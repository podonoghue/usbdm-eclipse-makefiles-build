/*! \file
   \brief Utility Routines for loading Freescale S-Record Files

   FlashImageImp.cpp

   \verbatim
   Copyright (C) 2008  Peter O'Donoghue

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\endverbatim

\verbatim
 Change History
+========================================================================================
| 29 May 15 | Added saveFile()                                          V4.11.1.40  - pgo
| 10 Feb 15 | Now discards S5 & S6 SRECs                                V4.10.6.260 - pgo
| 20 Jan 15 | Added DSC ELF file support for newer targets              V4.10.6.250 - pgo
| 21 Jul 14 | Added S12X ELF file support                               V4.10.6.170 - pgo
| 20 Oct 12 | Added DSC ELF file support                                V4.10.3     - pgo
|  7 Sep 12 | Added HCS12 support & device type check                   V4.10.0     - pgo
|  1 Jun 12 | Changed to template format                                V4.9.5      - pgo
| 31 May 12 | Changed back to flat format                               V4.9.5      - pgo
| 17 Apr 12 | Added ELF format loading                                  V4.9.5      - pgo
| 14 Feb 11 | Changed to dynamic memory allocation for buffer           V4.5        - pgo
| 30 Jan 10 | 2.0.0 Changed to C++                                                  - pgo
|           |       Added paged memory support                                      - pgo
|  8 Dec 09 | Started changes for paged files - incomplete                          - pgo
|  ??    09 | Created                                                               - pgo
+========================================================================================
\endverbatim
 */

#include <string.h>
#include <map>

#include "FlashImage.h"

#include "MyException.h"
#include "Elf.h"
#include "Utils.h"

#include "FlashImageImp.h"
#include "PluginHelper.h"

using namespace std;

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(void *pp) {
   return TcreatePluginInstance<FlashImageImp>(pp);
}

const char* FlashImageImp::get_pFlagsName(unsigned int flags) {
   static char buff[20];
   buff[0] = '\0';
   if (flags&PF_X) {
      strcat(buff,"PF_X|");
   }
   if (flags&PF_W) {
      strcat(buff,"PF_W|");
   }
   if (flags&PF_R) {
      strcat(buff,"PF_R|");
   }
   return buff;
}

const char* FlashImageImp::get_ptTypeName(unsigned int type) {
   const char *names[] = {
         "PT_NULL"    ,
         "PT_LOAD"    ,
         "PT_DYNAMIC" ,
         "PT_INTERP"  ,
         "PT_NOTE"    ,
         "PT_SHLIB"   ,
         "PT_PHDR"    ,
   };
   if (type > sizeof(names)/sizeof(names[0])) {
      return "Unknown";
   }
   return names[type];
}

/*
 * ======================================================================
 */

class MemoryPage {
/* Represents a memory 'page'.
 * Note: A page does not correspond to a flash page or sector!
 */

public:
   uint8_t data[FlashImageImp::PageSize];           //!< Page of memory
   uint8_t validBits[FlashImageImp::PageSize/8];    //!< Indicates valid bytes in data

public:
   MemoryPage();

   bool     isValid(unsigned index) const;
   void     setValue(unsigned index, uint8_t value);
   void     remove(unsigned index);
   uint8_t  getValue(unsigned index);
};

/*!
 * Constructor
 */
MemoryPage::MemoryPage() {
   memset(data, 0xFF, sizeof(data));
   memset(validBits, 0, sizeof(validBits));
}

/*!
 * Indicates if a page[index] has been written to
 */
bool MemoryPage::isValid(unsigned index) const {
   if (index >= FlashImageImp::PageSize) {
      throw MyException("Page index out of range");
   }
   return (validBits[index/8] & (1<<(index&0x7)))?true:false;
}

/*!
 * Sets page[index] to value & marks as valid
 */
void MemoryPage::setValue(unsigned index, uint8_t value) {
   if (index >= FlashImageImp::PageSize) {
      throw runtime_error("Page index out of range");
   }
   data[index]         = value;
   validBits[index/8] |= (1<<(index&0x7));
}

/*!
 *  Sets page[index] to 0xFF & marks as invalid
 */
void MemoryPage::remove(unsigned index) {
   if (index >= FlashImageImp::PageSize) {
      throw runtime_error("Page index out of range");
   }
   data[index]         = (uint8_t)-1;
   validBits[index/8] &= ~(1<<(index&0x7));
}

/*!
 *  Returns contents of page[index] if valid or (uint8_t)-1 otherwise
 */
uint8_t MemoryPage::getValue(unsigned index) {
   if (!isValid(index)) {
      return  (uint8_t)-1;
   }
   return data[index];
}

/*
 * ======================================================================
 */

/*!
 *    Class to enumerate the occupied locations within the memory image
 *    @note may be invalidated by changes to the referenced image
 */
class EnumeratorImp : public FlashImage::Enumerator {
protected:
   FlashImageImp  &memoryImage;    //! Associated flash image
   uint32_t        address;        //! Current location in image

public:
   EnumeratorImp(FlashImageImp &memoryImage, uint32_t address = 0);
   virtual ~EnumeratorImp() {};

   virtual uint32_t   getAddress() const;
   virtual bool       isValid() const;
   virtual bool       setAddress(uint32_t addr);
   virtual bool       nextValid();
   virtual void       lastValid();
};

/*! Construct an enumerator positioned at a given starting address
 *  Note: if address is unallocated then the Enumerator is advanced to next allocated address
 */
EnumeratorImp::EnumeratorImp(FlashImageImp &memoryImage, uint32_t address) : memoryImage(memoryImage), address(address) {
   LOGGING_Q;

   if (!isValid()) {
      // Address is not valid - advance to next valid address
      if (nextValid()) {
         log.print("Advanced to next valid address: 0x%08X\n", this->address);
      }
      else {
         log.print("No allocated address found");
      }
   }
}

/*! Get the current location as a flat address
 */
uint32_t EnumeratorImp::getAddress() const {
   return address;
}

/*! Indicates if the current memory location is valid (occupied)
 *
 * @return \n
 *         true  => current location is occupied
 *        false => current location is unoccupied/unallocated
 */
bool EnumeratorImp::isValid() const {
//   UsbdmSystem::Log::print("addr = 0x%06X\n", address);
   return memoryImage.isValid(address);
}

/*!
 * Sets the iterator to the given address
 *
 *  @return \n
 *         true  => current location is occupied
 *         false => current location is unoccupied/unallocated
 */
bool EnumeratorImp::setAddress(uint32_t addr) {
//   log.print("addr = 0x%06X\n", address);
   address = addr;
   if (!memoryImage.isValid(address)) {
      return nextValid();
   }
   return true;
}

/*!
 * Advance to next occupied flash location
 *
 * @return \n
 *        true  => advanced to next occupied location
 *        false => no occupied locations remain, enumerator is left at last \e unoccupied location
 */
bool EnumeratorImp::nextValid() {
   MemoryPagePtr memoryPage;
   uint16_t pageNum, offset;
   //   log.print("start=0x%06X\n", address);
   address++;
   do {
      FlashImageImp::addressToPageOffset(address, pageNum, offset);
//      log.print("Checking 0x%06X)\n", address);

      // At start of page or haven't checked this page yet
      if ((offset == 0) || (memoryPage == NULL)) {
         typename map<uint32_t, MemoryPagePtr>::iterator iter = memoryImage.memoryPages.find(pageNum);
         if (iter == memoryImage.memoryPages.end()) {
            memoryPage.reset();
         }
         else {
            memoryPage = iter->second;
         }
      }
      if (memoryPage == NULL) {
         // Unallocated page - move to start of next page
         //         log.print("enumerator::nextValid(a=0x%06X) - skipping unallocated page #0x%X\n", address, pageNum);
         address += FlashImageImp::PageSize;
         address &= ~FlashImageImp::PageMask;
         if (address > memoryImage.lastAllocatedAddress) {
//            address = memoryImage.lastAllocatedAddress;
//            log.print("end = 0x%06X, no remaining valid addresses\n", address);
            return false;
         }
         continue;
      }
      // Check if valid byte in page
      if (memoryPage->isValid(offset)) {
         //         log.print("end = 0x%06X\n", address);
         return true;
      }
      address++;
   } while (1);
   return false;
}

/*!
 *  Advance location to just before the next unoccupied flash location or page boundary
 *  Assumes current location is occupied.
 */
void EnumeratorImp::lastValid() {
   uint16_t pageNum, offset;
   LOGGING_Q;
//   log.print("start=0x%06X\n", address);

   FlashImageImp::addressToPageOffset(address, pageNum, offset);
   typename map<uint32_t, MemoryPagePtr>::iterator iter = memoryImage.memoryPages.find(pageNum);
   if (iter == memoryImage.memoryPages.end()) {
//      log.print("end=0x%06), start address not allocated\n", address);
      return;
   }
   MemoryPagePtr memoryPage = iter->second;
   do {
//      log.print("Checking 0x%06X)\n", address);
      if (address == memoryImage.lastAllocatedAddress) {
//         log.print("end=0x%06X, end of memory\n", address);
         return;
      }
      FlashImageImp::addressToPageOffset(address, pageNum, offset);
      // Check if at page boundary or probing one ahead fails
      if ((offset == FlashImageImp::PageSize-1) || !memoryPage->isValid(++offset)) {
//         log.print("end=0x%06X\n", address);
         return;
      }
      address++;
   } while (1);
}

/*
 * ======================================================================
 */

/*!
 *   Constructor - creates an empty Flash image
 */
FlashImageImp::FlashImageImp() :
      targetType(T_NONE),
      wordAddresses(false),
      firstAllocatedAddress((unsigned )(-1)),
      lastAllocatedAddress(0),
      lastPageNumAccessed((uint16_t )(-1)),
      elementCount(0),
      littleEndian(false),
      allowOverwrite(false),
      fp(0),
      discardFF(true) {
}

/*!
 *   Set target type of image
 *
 *   @param targetType - Target type to set
 */
void FlashImageImp::setTargetType(TargetType_t targetType) {
   this->targetType = targetType;
   if (targetType == T_MC56F80xx) {
      wordAddresses = true;
   }
   clear();
}

/*!
 *  ~Constructor
 */
FlashImageImp::~FlashImageImp() {
   clear();
}

/*!
 * Get string describing the error code
 *
 * @param rc - Error code
 *
 * @return String describing the error
 */
const char *FlashImageImp::getErrorString(USBDM_ErrorCode rc) {
   return USBDM_GetErrorString(rc);
}

/*!
 *  Initialises the memory to empty
 */
void FlashImageImp::clear(void) {

   // Initialise flash image to unused value
   typename std::map<uint32_t,MemoryPagePtr>::iterator it = memoryPages.begin();
   while(it != memoryPages.end()){
      it->second.reset();
      it++;
   }
   memoryPages.clear();
   firstAllocatedAddress  = (unsigned )(-1);
   lastAllocatedAddress   = 0;
   lastPageNumAccessed    = (uint16_t )(-1);
   lastMemoryPageAccessed.reset();
   elementCount           = 0;
   littleEndian           = false;
}

/*!
 *  Checks if the memory location is valid (has been written to)
 *
 *  @param address - 32-bit memory address
 *
 *  @return\n
 *          true   => location has been previously written to \n
 *          false  => location is invalid
 */
bool FlashImageImp::isValid(uint32_t address) {
   uint16_t pageNum;
   uint16_t offset;
   addressToPageOffset(address, pageNum, offset);
   MemoryPagePtr memoryPage = getmemoryPage(pageNum);
   return (memoryPage != NULL) && (memoryPage->isValid(offset));
}

/*!
 *   Gets an enumerator for the memory
 */
FlashImage::EnumeratorPtr FlashImageImp::getEnumerator(uint32_t address) {
   return EnumeratorPtr(new EnumeratorImp(*this, address));
}

/*!
 * Check if image is entirely empty (never written to)
 *
 * @return true=>image is entirely empty,\n
 *               image is not empty
 */
bool FlashImageImp::isEmpty() const {
   return elementCount==0;
}

/*!
 *  Prints a summary of the Flash memory allocated/used.
 */
void FlashImageImp::printMemoryMap() {
   EnumeratorPtr enumerator(getEnumerator());
   UsbdmSystem::Log::print("FlashImageImp::MemorySpace::printMemoryMap()\n");
   while (enumerator->isValid()) {
      // Start address of block
      uint32_t startBlock = enumerator->getAddress();
      // Find end of block
      enumerator->lastValid();
      uint32_t endBlock = enumerator->getAddress();
      UsbdmSystem::Log::print("Memory Block[0x%06X...0x%06X]\n", startBlock, endBlock);
      // Move to start of next occupied range
      enumerator->nextValid();
   }
}

/*!
 *  Returns an approximate count of occupied bytes
 */
unsigned FlashImageImp::getByteCount() const {
   return elementCount*sizeof(uint8_t);
}

/*
 *  Get pathname of last file loaded
 */
const string & FlashImageImp::getSourcePathname() const {
   return sourcePath;
}

/*!
 * Locate Page from page number
 *
 * @param   pageNum
 *
 * @return  memory page or NULL if not found
 */
MemoryPagePtr FlashImageImp::getmemoryPage(uint32_t pageNum) {
   MemoryPagePtr memoryPage;
   if ((pageNum == lastPageNumAccessed) && (lastMemoryPageAccessed != NULL)) {
      // Used cached copy
      memoryPage = lastMemoryPageAccessed;
   }
   else {
      typename std::map<uint32_t, MemoryPagePtr>::iterator iter = memoryPages.find(pageNum);
      if (iter == memoryPages.end()) {
         memoryPage.reset();
      }
      else {
         memoryPage = iter->second;
      }
      // Cache access
      lastMemoryPageAccessed  = memoryPage;
   }
   return memoryPage;
}

/*!
 *   Allocate page
 *
 *   @param pageNum
 */
MemoryPagePtr FlashImageImp::allocatePage(uint32_t pageNum) {
   LOGGING_Q;
   MemoryPagePtr memoryPage;

   memoryPage = getmemoryPage(pageNum);
   if (memoryPage == NULL) {
      log.print( "Allocating page #%2.2X [0x%06X-0x%06X]\n", pageNum, pageOffsetToAddress(pageNum, 0), pageOffsetToAddress(pageNum, PageSize-1));
      memoryPage.reset(new MemoryPage);
      memoryPages.insert(pair<const uint32_t, MemoryPagePtr>(pageNum, memoryPage));
      // Update cache
      lastMemoryPageAccessed = memoryPage;
   }
   return memoryPage;
}

/*!
 *    Load a S19 or ELF file into the buffer. \n
 *
 *  @param filePath      : Path of file to load
 *  @param clearBuffer   : Clear buffer before loading
 *
 *  @return error code see \ref USBDM_ErrorCode
 */
USBDM_ErrorCode  FlashImageImp::loadFile(const string &filePath, bool clearBuffer) {
   LOGGING_Q;

   sourceFilename = "";
   sourcePath     = "";
   allowOverwrite = !clearBuffer;
   if (clearBuffer) {
      clear();
   }
   log.print("FlashImageImp::MemorySpace::loadFile(\"%s\")\n", filePath.c_str());

   // Try ELF Format
   USBDM_ErrorCode rc = loadElfFile(filePath);
   if (rc == SFILE_RC_UNKNOWN_FILE_FORMAT) {
      // Try SREC Format if not recognized as ELF
      rc = loadS1S9File(filePath);
   }
//   log.print("FlashImageImp::loadFile()\n"
//         "Lowest used Address \t = 0x%4.4X\n"
//         "Highest used Address\t = 0x%4.4X\n",
//         FlashImageImpDescription->firstAddr,  // first non-0xFF address
//         FlashImageImpDescription->lastAddr    // last non-0xFF address
//         );
//
   if (rc == SFILE_RC_OK) {
      sourcePath      = filePath;
      sourceFilename  = filePath; //!Todo Fix
   }
   return rc;
}

/*!
 *    Save image buffer as a S19 file. \n
 *
 *  @param filePath      : Path of file to load
 *  @param discardFF     : Discard sizable blocks of consecutive 0xFF values (assumed blank)
 *
 *  @return error code see \ref USBDM_ErrorCode
 */
USBDM_ErrorCode FlashImageImp::saveFile(const std::string &filePath, bool discardFF) {
   LOGGING;
   this->discardFF = discardFF;
   fp = fopen(filePath.c_str(), "wt");
   if (fp == 0) {
      return SFILE_RC_FILE_OPEN_FAILED;
   }
   FlashImage::EnumeratorPtr e = getEnumerator(0);
   while (e->isValid()) {
      uint32_t start = e->getAddress();
      e->lastValid();
      uint32_t end = e->getAddress();
      log.print("[0x%06X..0x%06X]\n", start, end);
      e->nextValid();
      uint8_t data[end-start+1];
      uint8_t *dataPtr = data;
      for (uint32_t address=start; address<=end; address++) {
         *dataPtr++ = getValue(address);
      }
      writeData(data, start, end-start+1);
   }
   fclose(fp);
   return BDM_RC_OK;
}

//! Dump a single S-record to stdout
//!
//! @param file     file handle for writes
//! @param buffer   location of data to dump
//! @param address  base address of data
//! @param size     number of bytes to dump
//!
//! @note size must be less than or equal to \ref maxSrecSize
//! @note S-records filled with 0xFF are discarded
//!
void FlashImageImp::writeSrec(uint8_t *buffer, uint32_t address, unsigned size) {
   LOGGING;
   log.print("[0x%06X..0x%06X]\n", address, address+size-1);

   // Discard 0xFF filled records (blank Flash)
   bool allFF = discardFF;
   if (discardFF) {
      for(unsigned sub=0; sub<size; sub++) {
         if (buffer[sub] != 0xFF ) {
            allFF = false;
            break;
         }
      }
   }
   if ((size == 0) || allFF) {
      return;
   }
   uint8_t *ptr = buffer;
   uint8_t checkSum;
   if ((address) < 0x10000U) {
      fprintf(fp, "S1%02X%04X", size+3, address);
      checkSum = size+3;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   else if (address < 0x1000000U) {
      fprintf(fp, "S2%02X%06X", size+4, address);
      checkSum = size+4;
      checkSum += (address>>16)&0xFF;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   else {
      fprintf(fp, "S3%02X%08X", size+5, address);
      checkSum = size+5;
      checkSum += (address>>24)&0xFF;
      checkSum += (address>>16)&0xFF;
      checkSum += (address>>8)&0xFF;
      checkSum += (address)&0xFF;
   }
   while (size-->0) {
      checkSum += *ptr;
      fprintf(fp, "%02X", *ptr++);
   }
   checkSum = checkSum^0xFF;
   fprintf(fp, "%02X\n", checkSum);
}

//! Dump data as S-records to stdout
//!
//! @param file     file handle for writes
//! @param buffer   location of data to dump
//! @param address  base address of data
//! @param size     number of bytes to dump
//!
//! @note Regions filled with 0xFF are discarded
//!
void FlashImageImp::writeData(uint8_t *buffer, uint32_t address, unsigned size) {
   LOGGING;
   log.print("[0x%06X..0x%06X]\n", address, address+size-1);
   while (size>0) {
      uint8_t oddBytes = address & (maxSrecSize-1);
      uint8_t srecSize = maxSrecSize - oddBytes;
      if (srecSize > size) {
         srecSize = (uint8_t) size;
      }
      writeSrec(buffer, address, srecSize);
      address += srecSize;
      buffer  += srecSize;
      size    -= srecSize;
   }
}

/*!
 *  Obtain the value of a Flash memory location
 *
 *  @param address - 32-bit memory address
 *
 *  @return - uint8_t value (dummy value of 0xFF.. is unallocated address)
 */
uint8_t FlashImageImp::getValue(uint32_t address) {
   uint16_t         offset;
   uint16_t         pageNum;
   MemoryPagePtr    memoryPage;
   addressToPageOffset(address, pageNum, offset);
   memoryPage = getmemoryPage(pageNum);
   if (memoryPage == NULL)
      return (uint8_t)-1;
   else
      return memoryPage->getValue(offset);
}

/*!
 *   Set a Flash memory location
 *
 *   @param address - 32-bit memory address
 *   @param value   - uint8_t value to write to image
 *
 *   @note Allocates a memory location if necessary
 */
void FlashImageImp::setValue(uint32_t address, uint8_t value) {
   uint16_t offset;
   uint16_t pageNum;

   addressToPageOffset(address, pageNum, offset);
   MemoryPagePtr memoryPage = allocatePage(pageNum);
   if (!memoryPage->isValid(offset)) {
      // new location
      elementCount++;
   }
   memoryPage->setValue(offset, value);
   if (firstAllocatedAddress > address) {
      firstAllocatedAddress = address;
   }
   if (lastAllocatedAddress < address) {
      lastAllocatedAddress = address;
   }
}

/*
 * Remove a Flash memory location (set to unprogrammed)
 *
 * @param address - 32-bit memory address
 */
void FlashImageImp::remove(uint32_t address) {
   uint16_t offset;
   uint16_t pageNum;

   addressToPageOffset(address, pageNum, offset);
   MemoryPagePtr memoryPage = getmemoryPage(pageNum);
   if ((memoryPage == NULL) || !memoryPage->isValid(offset)) {
      // Doesn't exist
      return;
   }
   elementCount--;
   memoryPage->remove(offset);
}

/*!
 *  Dump the contents of a range of memory to log file
 *
 * @param startAddress - start of range
 * @param endAddress   - end of range
 *
 */
void FlashImageImp::dumpRange(uint32_t startAddress, uint32_t endAddress) {
   LOGGING_Q;
   uint32_t addr;
   uint32_t rangeEnd;

   log.print("Dump of [0x%06X-0x%06X]\n", startAddress, endAddress);
   EnumeratorImp iter(*this, startAddress);
   if (!iter.isValid()) {
      iter.nextValid();
   }
   do {
      if (sizeof(uint8_t) == 1) {
         addr = iter.getAddress() & ~0xF;
         iter.lastValid();
         rangeEnd = iter.getAddress();
         log.print("        : 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n"
               "==========================================================\n");
         while (addr <= rangeEnd) {
            if (((addr & 0x000F) == 0) || (addr == startAddress))
               log.print("%8.8X:", addr);
            if (isValid(addr))
               log.print("%02X ", getValue(addr));
            else
               log.print("   ");
            if (((addr & 0x000F) == 0xF) || (addr == rangeEnd))
               log.print("\n");
            addr++;
         }
      }
      else {
         addr = iter.getAddress() & ~0xF;
         iter.lastValid();
         rangeEnd = iter.getAddress();
         log.print("        : 0    1    2    3    4    5    6    7\n"
               "==================================================\n");
         while (addr <= rangeEnd) {
            if (((addr & 0x0007) == 0) || (addr == startAddress))
               log.print("%8.8X:", addr);
            if (isValid(addr))
               log.print("%04X ", getValue(addr));
            else
               log.print("     ");
            if (((addr & 0x0007) == 0x7) || (addr == rangeEnd))
               log.print("\n");
            addr++;
         }
      }
   } while (iter.nextValid());
   log.print("\n\n");
}

/*!
 * Load data into Flash image
 *
 * @param bufferSize    - size of data to load (in uint8_t)
 * @param address       - address to load at
 * @param data          - data to load
 * @param dontOverwrite - produce error if overwriting existing data
 */
USBDM_ErrorCode FlashImageImp::loadData(uint32_t       bufferSize,
      uint32_t       address,
      const uint8_t data[],
      bool           dontOverwrite) {
   uint32_t bufferAddress;

   //   log.print("FlashImageImp::loadData(0x%04X...0x%04X)\n", address, address+bufferSize-1);
   bufferAddress = 0;
   while (bufferAddress < bufferSize){
      //      if (!allocatePage(address)) {
      //         log.print("loadData() - Address is too large = 0x%08X > 0x%08lX\n",
      //               address, MAX_SFILE_ADDRESS);
      //
      //         return SFILE_RC_ADDRESS_TOO_LARGE;
      //      }
      if (!this->isValid(address) || !dontOverwrite) {
         this->setValue(address, data[bufferAddress]);
      }
      address++;
      bufferAddress++;
   }
   //   printMemoryMap();
   return SFILE_RC_OK;
}

/*!
 * Load data into Flash image from byte array
 *
 * @param bufferSize    - size of data to load (in bytes)
 * @param address       - address to load at (byte/word address)
 * @param data          - data to load
 * @param dontOverwrite - true to prevent overwriting data
 *
 * @note This is only of use if uint8_t is not a byte
 */
USBDM_ErrorCode FlashImageImp::loadDataBytes(uint32_t        bufferSize,
      uint32_t        address,
      const uint8_t   data[],
      bool            dontOverwrite) {
   LOGGING_Q;
   //    log.print("FlashImageImp::loadData(0x%04X...0x%04X)\n", address, address+bufferSize-1);
   if (sizeof(uint8_t) == 1) {
      // Copy directly to buffer
      uint32_t bufferAddress = 0;
      while (bufferAddress < bufferSize) {
         unsigned value;
         value = data[bufferAddress++];
         if (!this->isValid(address) || !dontOverwrite) {
            this->setValue(address, value);
         }
         //         log.print("FlashImageImp::loadDataBytes() - image[0x%06X] <= 0x%04X\n", address, value);
         address++;
      }
   }
   else {
      if ((bufferSize&0x01) != 0) {
         log.print("FlashImageImp::loadDataBytes() - Error: Odd buffer size\n");
         return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
      }
      // Convert to little-endian native & copy to buffer
      uint32_t bufferAddress = 0;
      while (bufferAddress < bufferSize) {
         unsigned value;
         value = data[bufferAddress++];
         value = (data[bufferAddress++]<<8)+value;
         //         log.print("FlashImageImp::loadDataBytes() - image[0x%06X] <= 0x%04X\n", address, value);
         if (!this->isValid(address) || !dontOverwrite) {
            this->setValue(address, value);
         }
         //         log.print("FlashImageImp::loadDataBytes() - image[0x%06X] <= 0x%04X\n", address, value);
         address++;
      }
   }
   return BDM_RC_OK;
}

/*! Maps Address to PageNum:offset
 *
 * @param address - 32-bit address
 * @param pageNum - page number portion of address
 * @param offset  - offset within page
 *
 * @note - These values do NOT refer to the paging structure used by the target!
 */
void FlashImageImp::addressToPageOffset(uint32_t address, uint16_t &pageNum, uint16_t &offset) {
   offset  = address & PageMask;
   pageNum = address >> PageBitOffset;
   //      printf("%8.8X=>%2.2X:%4.4X\n", address, pageNum, offset);
}

/*! Maps PageNum:offset to Address
 *
 * @param pageNum - page number portion of address
 * @param offset  - offset within page
 *
 * @return 32-bit address
 *
 * @note - These values do NOT refer to the paging structure used by the target!
 */
uint32_t FlashImageImp::pageOffsetToAddress(uint16_t pageNum, uint16_t offset) {
   if (offset>=PageSize)
      throw runtime_error("Page offset too large\n");
   return (pageNum << PageBitOffset) + offset;
}

/*! Convert a 32-bit unsigned number between Target and Native format
 *
 * @param value - value to convert
 *
 * @return - converted value
 */

uint32_t FlashImageImp::targetToNative(uint32_t &value) {
   if (littleEndian) {
      return value;
   }
   return ((value<<24)&0xFF000000) + ((value<<8)&0x00FF0000) +
         ((value>>8) &0x0000FF00) + ((value>>24)&0x000000FF);
}

/*! Convert a 16-bit unsigned number between Target and Native format
 *
 * @param value - value to convert
 *
 * @return - converted value
 */

uint16_t FlashImageImp::targetToNative(uint16_t &value) {
   if (littleEndian) {
      return value;
   }
   return ((value<<8)&0xFF00) + ((value>>8)&0x00FF);
}

/*! Convert a 32-bit signed number between Target and Native format
 *
 * @param value - value to convert
 *
 * @return - converted value
 */

int32_t FlashImageImp::targetToNative(int32_t &value) {
   if (littleEndian) {
      return value;
   }
   return ((value<<24)&0xFF000000) + ((value<<8)&0x00FF0000) +
         ((value>>8) &0x0000FF00) + ((value>>24)&0x000000FF);
}

/*! Convert a 16-bit signed number between Target and Native format
 *
 * @param value - value to convert
 *
 * @return - converted value
 */

int16_t FlashImageImp::targetToNative(int16_t &value) {
   if (littleEndian) {
      return value;
   }
   return ((value<<8)&0xFF00) + ((value>>8)&0x00FF);
}

/*
 *   Load a Freescale S-record file into the buffer. \n
 *
 *   The buffer is cleared to 0xFFFF before loading.  Modified locations will
 *   have a non-0xFF upper byte so used locations can be differentiated. \n
 *
 * @param fileName         : Path of file to load
 *
 * @return error code see \ref USBDM_ErrorCode
 */
USBDM_ErrorCode FlashImageImp::loadS1S9File(const string &fileName) {
   LOGGING_Q;
   char        *ptr;
   char         buffer[1024];
   uint32_t     addr;
   uint32_t     srecSize;
   uint8_t      checkSum;
   bool         fileRecognized = false;

   FILE *fp = fopen(fileName.c_str(), "rt");

   if (fp == NULL) {
      log.print("FlashImageImp::MemorySpace::loadS1S9File(\"%s\") - Failed to open input file\n", fileName.c_str());
      return SFILE_RC_FILE_OPEN_FAILED;
   }
   log.print("filename = \"%s\"\n", fileName.c_str());

   unsigned int lineNum  = 0;
   while (fgets(buffer, sizeof(buffer)-1, fp) != NULL) {
      lineNum++;
//      log.print("Input: %s",buffer);
      ptr = buffer;
      // Find first non-blank
      while ((*ptr == ' ') || (*ptr == '\t') || (*ptr == '\n') || (*ptr == '\r'))
         ptr++;
      // Check if S-record
      if ((*ptr != 'S') && (*ptr != 's')) {
         log.print("- illegal line #%5d-%s", lineNum, buffer);
         fclose(fp);
         if (fileRecognized) {
            return SFILE_RC_ILLEGAL_LINE;
         }
         else {
            return SFILE_RC_UNKNOWN_FILE_FORMAT;
         }
      }
      switch (*(ptr+1)) {
      case '0': // Information header
      case '7': // 32-bit start address
      case '8': // 24-bit start address
      case '9': // 16-bit start address
      case '5': // 16-bit record length
      case '6': // 24-bit record length
         // Discard S0, S5, S6, S7, S8 & S9 records
         continue;
      case '1':
         // S1 = 16-bit address, data record
         ptr +=2; // Skip 'S1'
         srecSize = hex2ToDecimal( &ptr );
         addr = hex4ToDecimal( &ptr );
         checkSum = (uint8_t)srecSize + (uint8_t)(addr>>8) + (uint8_t)addr;
         srecSize -= 3; // subtract 3 from byte count (srecSize + 2 addr bytes)
//         log.print("(%2.2X)%4.4lX:\n",srecSize,addr);
         break;
      case '2':
         // S2 = 24-bit address, data record
         ptr +=2; // Skip 'S2'
         srecSize = hex2ToDecimal( &ptr );
         addr = hex6ToDecimal( &ptr );
         checkSum = (uint8_t)srecSize + (uint8_t)(addr>>16) + (uint8_t)(addr>>8) + (uint8_t)addr;
         srecSize -= 4; // subtract 4 from byte count (srecSize + 3 addr bytes)
//         log.print("srecSize=0x%02X, addr=0x%06X\n",srecSize,addr);
         break;
      case '3':
         // S3 32-bit address, data record
         ptr +=2; // Skip 'S3'
         srecSize = hex2ToDecimal( &ptr );
         addr = hex8ToDecimal( &ptr );
         checkSum = (uint8_t)srecSize + (uint8_t)(addr>>24) + (uint8_t)(addr>>16) + (uint8_t)(addr>>8) + (uint8_t)addr;
         srecSize -= 5; // subtract 5 from byte count (srecSize + 4 addr bytes)
//         log.print("S3: srecSize=0x%02X, addr=0x%08X, initial chk=0x%02X\n", srecSize, addr, checkSum);
         break;
      default:
         log.print("- illegal line #%5d-%s", lineNum, buffer);
         fclose(fp);
         if (fileRecognized) {
            return SFILE_RC_ILLEGAL_LINE;
         }
         else {
            return SFILE_RC_UNKNOWN_FILE_FORMAT;
         }
      }
      if (wordAddresses) {
         addr *= 2;
      }
      if (sizeof(uint8_t) == 1) {
         while (srecSize>0) {
            uint8_t data;
            data = hex2ToDecimal( &ptr );
            checkSum += (uint8_t)data;
            if (this->isValid(addr) && !allowOverwrite) {
               // Occupied address
               log.print("Memory image overlaps @0x%X\n", addr);
            }
            this->setValue(addr++, (uint8_t)data);
            srecSize--;
//         log.print("%02X",data);
         }
      }
      // Get checksum from record
      uint8_t data = hex2ToDecimal( &ptr );
      if ((uint8_t)~checkSum != data) {
         log.print("- illegal line #%5d:\n%s", lineNum, buffer);
         log.print("- checksum error, Checksum=0x%02X, "
               "Calculated Checksum=0x%02X\n",
               data, (uint8_t)~checkSum);
         fclose(fp);
         return SFILE_RC_CHECKSUM;
      }
      fileRecognized = true; // Read at least 1 record - assume it's a SREC file
//      log.print("\n");
   }
   fclose(fp);
//   log.print("FlashImageImp::MemorySpace::loadS1S9File()\n");
//   printMemoryMap();
   return SFILE_RC_OK;
}

/*
 *   Load a ELF block into the buffer. \n
 *
 *   The buffer is cleared to 0xFFFF before loading.  Modified locations will
 *   have a non-0xFF upper byte so used locations can be differentiated. \n
 *
 * @param fp            : Open file pointer
 * @param fOffset       : Offset to block in file
 * @param size          : Size of block in bytes
 * @param addr          : Bytes address to load block
 */
USBDM_ErrorCode FlashImageImp::loadElfBlock(FILE *fp,
      long        fOffset,
      Elf32_Word  size,
      Elf32_Addr  addr) {

   LOGGING_Q;
#if defined(TARGET) && (TARGET == MC56F80xx)
   // DSC image uses word addresses
   addr /= 2;
#endif
   if (size == 0) {
      log.print("[empty]\n");
   }
   else {
#if defined(TARGET) && (TARGET == MC56F80xx)
      log.print("[0x%08X..0x%08X]\n", addr, addr+size/2-1);
#else
      log.print("[0x%08X..0x%08X]\n", addr, addr+size-1);
#endif
   }
   fseek(fp, fOffset, SEEK_SET);
   while (size>0) {
      uint8_t buff[1000];
      Elf32_Word blockSize = size;
      if (blockSize > sizeof(buff)) {
         blockSize = sizeof(buff);
      }
      size_t sz;
      if ((sz=fread(buff, 1, blockSize, fp)) != blockSize) {
         log.print("- Failed - Undersize read of Block (Expected %lu, read %lu)\n", (unsigned long)blockSize, (unsigned long)sz);
         return SFILE_RC_ELF_FORMAT_ERROR;
      }
//      #if defined(TARGET) && (TARGET == MC56F80xx)
//            printDump(buff, blockSize, addr, WORD_ADDRESS|WORD_DISPLAY);
//      #else
//            printDump(buff, blockSize, addr, BYTE_ADDRESS);
//      #endif
      for (unsigned index=0; index<blockSize; ) {
         uint16_t value;
#if defined(TARGET) && (TARGET == MC56F80xx)
         value  = buff[index++];
         value += buff[index++]<<8;
#else
         value = buff[index++];
#endif
         this->setValue(addr++, value);
      }
      size -= blockSize;
   }
   return SFILE_RC_OK;
}

/*
 * Print ELF Header
 *
 * @param elfHeader -  ELF header to print
 */
void FlashImageImp::printElfHeader(Elf32_Ehdr *elfHeader) {
   UsbdmSystem::Log::print("e_type      = 0x%04X\n"
         "e_machine   = 0x%04X\n"
         "e_version   = 0x%08X\n"
         "e_entry     = 0x%08X\n"
         "e_phoff     = 0x%08X\n"
         "e_shoff     = 0x%08X\n"
         "e_flags     = 0x%08X\n"
         "e_ehsize    = 0x%04X\n"
         "e_phentsize = 0x%04X\n"
         "e_phnum     = 0x%04X\n"
         "e_shentsize = 0x%04X\n"
         "e_shnum     = 0x%04X\n"
         "e_shstrndx  = 0x%04X\n",
         elfHeader->e_type,
         elfHeader->e_machine,
         elfHeader->e_version,
         elfHeader->e_entry,
         elfHeader->e_phoff,
         elfHeader->e_shoff,
         elfHeader->e_flags,
         elfHeader->e_ehsize,
         elfHeader->e_phentsize,
         elfHeader->e_phnum,
         elfHeader->e_shentsize,
         elfHeader->e_shnum,
         elfHeader->e_shstrndx );
}

/*
 * Convert fields in ELF header to native format
 *
 * @param elfHeader -  ELF header to convert
 */
void FlashImageImp::fixElfHeaderSex(Elf32_Ehdr *elfHeader) {
   // Convert to native format
   elfHeader->e_type      = targetToNative(elfHeader->e_type     );
   elfHeader->e_machine   = targetToNative(elfHeader->e_machine  );
   elfHeader->e_version   = targetToNative(elfHeader->e_version  );
   elfHeader->e_entry     = targetToNative(elfHeader->e_entry    );
   elfHeader->e_phoff     = targetToNative(elfHeader->e_phoff    );
   elfHeader->e_shoff     = targetToNative(elfHeader->e_shoff    );
   elfHeader->e_flags     = targetToNative(elfHeader->e_flags    );
   elfHeader->e_ehsize    = targetToNative(elfHeader->e_ehsize   );
   elfHeader->e_phentsize = targetToNative(elfHeader->e_phentsize);
   elfHeader->e_phnum     = targetToNative(elfHeader->e_phnum    );
   elfHeader->e_shentsize = targetToNative(elfHeader->e_shentsize);
   elfHeader->e_shnum     = targetToNative(elfHeader->e_shnum    );
   elfHeader->e_shstrndx  = targetToNative(elfHeader->e_shstrndx );
}

/*
 * Print ELF Program Header
 *
 * @param programHeader -  ELF Program header to print
 */
void FlashImageImp::printElfProgramHeader(Elf32_Phdr *programHeader) {
   UsbdmSystem::Log::print("===================\n"
         "p_type                  p_offset   p_vaddr    p_paddr    p_filesz   p_memsz    p_align    p_flags\n"
         "0x%08X (%-10s) 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X (%-20s)\n",
         programHeader->p_type  , get_ptTypeName(programHeader->p_type),
         programHeader->p_offset,
         programHeader->p_vaddr ,
         programHeader->p_paddr ,
         programHeader->p_filesz,
         programHeader->p_memsz ,
         programHeader->p_align ,
         programHeader->p_flags , get_pFlagsName(programHeader->p_flags)
   );
}

/*
 * Convert fields to native format
 *
 * @param elfHeader -  ELF Program header to convert
 */
void FlashImageImp::fixElfProgramHeaderSex(Elf32_Phdr *elfHeader) {
   elfHeader->p_type    = targetToNative(elfHeader->p_type  );
   elfHeader->p_offset  = targetToNative(elfHeader->p_offset);
   elfHeader->p_vaddr   = targetToNative(elfHeader->p_vaddr );
   elfHeader->p_paddr   = targetToNative(elfHeader->p_paddr );
   elfHeader->p_filesz  = targetToNative(elfHeader->p_filesz);
   elfHeader->p_memsz   = targetToNative(elfHeader->p_memsz );
   elfHeader->p_flags   = targetToNative(elfHeader->p_flags );
   elfHeader->p_align   = targetToNative(elfHeader->p_align );
}

/*
 *   Load a ELF file into the buffer. \n
 *
 * @param filePath         : Path of file to load
 *
 * @return error code see \ref USBDM_ErrorCode
 */
USBDM_ErrorCode FlashImageImp::loadElfFile(const string &filePath) {
   LOGGING_Q;
   fp = fopen(filePath.c_str(), "rb");
   if (fp == NULL) {
      log.error("Failed to open input file \'%s\'\n", filePath.c_str());
      return SFILE_RC_FILE_OPEN_FAILED;
   }
//   log.print("Input file - \'%s\'\n", filePath.c_str());

   Elf32_Ehdr elfHeader;
   if (fread(&elfHeader, 1, sizeof(elfHeader), fp) != sizeof(elfHeader)) {
      return SFILE_RC_ELF_FORMAT_ERROR;
   }
   //   log.print("FlashImageImp::MemorySpace::loadElfFile() - \n");
   //   printElfHeader(&elfHeader);

   if ((elfHeader.e_ident[EI_MAG0] != ELFMAG0V) ||(elfHeader.e_ident[EI_MAG1] != ELFMAG1V) ||
         (elfHeader.e_ident[EI_MAG2] != ELFMAG2V) ||(elfHeader.e_ident[EI_MAG3] != ELFMAG3V) ||
         (elfHeader.e_ident[EI_CLASS] != ELFCLASS32)) {
      log.error("Invalid  format\n");
      fclose(fp);
      return SFILE_RC_UNKNOWN_FILE_FORMAT;
   }
   littleEndian = elfHeader.e_ident[EI_DATA] == ELFDATA2LSB;
   fixElfHeaderSex(&elfHeader);

   //   log.print("FlashImageImp::MemorySpace::loadElfFile() - elfHeader.e_machine = 0x%X(%d) \n", elfHeader.e_machine, elfHeader.e_machine);
   //   printElfHeader(&elfHeader);

   if ((elfHeader.e_type != ET_EXEC) || (elfHeader.e_phoff == 0) || (elfHeader.e_phentsize == 0) || (elfHeader.e_phnum == 0)) {
      log.error("Invalid format\n");
      fclose(fp);
      return SFILE_RC_ELF_FORMAT_ERROR;
   }
   fseek(fp, elfHeader.e_phoff, SEEK_SET);
   for(Elf32_Half entry=0; entry<elfHeader.e_phnum; entry++) {
      Elf32_Phdr programHeader;
      fseek(fp, elfHeader.e_phoff+entry*elfHeader.e_phentsize, SEEK_SET);
      size_t sz;
      if ((sz=fread(&programHeader, 1, sizeof(programHeader), fp)) != sizeof(programHeader)) {
         log.error("Undersize read of Header (Expected %lu, read %lu)\n", (unsigned long)sizeof(programHeader), (unsigned long)sz);
         return SFILE_RC_ELF_FORMAT_ERROR;
      }
      fixElfProgramHeaderSex(&programHeader);
      if ((programHeader.p_type == PT_LOAD) && (programHeader.p_filesz > 0)) {
         loadElfBlock(&programHeader);
      }
   }
   fclose(fp);
   printMemoryMap();
   return SFILE_RC_OK;
}


USBDM_ErrorCode FlashImageImp::loadElfBlock(Elf32_Phdr *programHeader) {

//   printElfProgramHeader(programHeader);

   Elf32_Addr loadAddress;

   if ((targetType == T_RS08) || (targetType == T_HCS08) || (targetType == T_HCS12) || (targetType == T_S12Z) || (targetType == T_MC56F80xx)) {
      // These targets use the virtual address as the load address
      loadAddress = programHeader->p_vaddr;
#if defined(TARGET) && (TARGET == MC56F80xx)
      if ((programHeader->p_flags&PF_X) == 0) {
         // Indicates X:ROM/X:RAM (not executable)
         loadAddress += (DataOffset<<1);
      }
#endif
   }
   else {
      // Other targets load at the physical address (VADDR is RAM copy destination)
      loadAddress = programHeader->p_paddr;
   }
   return loadElfBlock(fp, programHeader->p_offset, programHeader->p_filesz, loadAddress);
}


USBDM_ErrorCode FlashImageImp::checkTargetType(Elf32_Half e_machine, TargetType_t targetType) {
   static const Elf32_Half e_machine_types[] = {
         /* T_HCS12     */ EM_68HC12,
         /* T_HCS08     */ EM_68HC08,
         /* T_RS08      */ 0,
         /* T_CFV1      */ EM_68K,
         /* T_CFVx      */ EM_68K,
         /* T_JTAG      */ 0,
         /* T_EZFLASH   */ 0,
         /* T_MC56F80xx */ EM_56K,
         /* T_ARM_JTAG  */ EM_ARM,
         /* T_ARM_SWD   */ EM_ARM,
         /* T_ARM       */ EM_ARM,
         /* T_S12Z      */ EM_S12X,
   };

   if ((targetType<0) || (targetType >= (sizeof(e_machine_types)/sizeof(e_machine_types[0])))) {
      UsbdmSystem::Log::error("Invalid e_machine = %X\n", e_machine);
      return BDM_RC_UNKNOWN_TARGET;
   }
   // Special case for MC56K as it used two IDs
   if ((targetType = T_MC56F80xx) && ((e_machine != EM_56K) && (e_machine != EM_56K_2))) {
      UsbdmSystem::Log::error("Invalid e_machine = %X\n", e_machine);
      return SFILE_RC_ELF_WRONG_TARGET;
   }
   if (e_machine != e_machine_types[targetType]) {
      UsbdmSystem::Log::error("Invalid e_machine = %X\n", e_machine);
      return SFILE_RC_ELF_WRONG_TARGET;
   }
   return BDM_RC_OK;
}
