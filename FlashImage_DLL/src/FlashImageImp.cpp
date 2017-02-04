/** \file
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
| 29 Dec 16 | Revised loading ELF files                                 V4.12.1.150 - pgo
|  4 Mar 16 | Improved format of dumpRange()                            V4.12.1.80  - pgo
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
#include <malloc.h>

#include "FlashImage.h"
#include "MyException.h"
#include "Elf.h"
#include "Utils.h"
#include "FlashImageImp.h"
#include "PluginHelper.h"

using namespace std;

/*
 * Create the plug-in instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(void *pp) {

   return TcreatePluginInstance<FlashImageImp>(pp);
}

/*
 * ======================================================================
 */

/**
 *  Represents a memory 'page'.
 *  Note: A page does not correspond to a flash page or sector!
 */
class MemoryPage {

public:
   /** Page of memory */
   uint8_t data[FlashImageImp::PAGE_SIZE];

   /** Indicates valid bytes in data */
   uint8_t validBits[FlashImageImp::PAGE_SIZE/8];

public:
   MemoryPage();

   bool     isValid(unsigned index) const;
   void     setValue(unsigned index, uint8_t value);
   void     remove(unsigned index);
   uint8_t  getValue(unsigned index);
};

/**
 * Constructor
 */
MemoryPage::MemoryPage() {
   memset(data, 0xFF, sizeof(data));
   memset(validBits, 0, sizeof(validBits));
}

/**
 * Indicates if a page[index] has been written to
 */
bool MemoryPage::isValid(unsigned index) const {
   if (index >= FlashImageImp::PAGE_SIZE) {
      throw MyException("Page index out of range");
   }
   return (validBits[index/8] & (1<<(index&0x7)))?true:false;
}

/**
 * Sets page[index] to value & marks as valid
 */
void MemoryPage::setValue(unsigned index, uint8_t value) {
   if (index >= FlashImageImp::PAGE_SIZE) {
      throw runtime_error("Page index out of range");
   }
   data[index]         = value;
   validBits[index/8] |= (1<<(index&0x7));
}

/**
 *  Sets page[index] to 0xFF & marks as invalid
 */
void MemoryPage::remove(unsigned index) {
   if (index >= FlashImageImp::PAGE_SIZE) {
      throw runtime_error("Page index out of range");
   }
   data[index]         = (uint8_t)-1;
   validBits[index/8] &= ~(1<<(index&0x7));
}

/**
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

/**
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

/**
 *  Construct an enumerator positioned at a given starting address
 *  Note: if address is unallocated then the Enumerator is advanced to next allocated address
 */
EnumeratorImp::EnumeratorImp(FlashImageImp &memoryImage, uint32_t address) : memoryImage(memoryImage), address(address) {
   LOGGING_Q;

   if (!isValid()) {
      // Address is not valid - advance to next valid address
      if (nextValid()) {
         log.print("Advanced to 1st valid address: 0x%08X\n", this->address);
      }
      else {
         log.print("No allocated address found\n");
      }
   }
}

/**
 *  Get the current location as a flat address
 */
uint32_t EnumeratorImp::getAddress() const {
   return address;
}

/**
 *  Indicates if the current memory location is valid (occupied)
 *
 *  @return true  => current location is occupied
 *  @return false => current location is unoccupied/unallocated
 */
bool EnumeratorImp::isValid() const {
//   UsbdmSystem::Log::print("addr = 0x%06X\n", address);
   return memoryImage.isValid(address);
}

/**
 *  Sets the iterator to the given address
 *
 *  @return true  => current location is occupied
 *  @return false => current location is unoccupied/unallocated
 */
bool EnumeratorImp::setAddress(uint32_t addr) {
//   log.print("addr = 0x%06X\n", address);
   address = addr;
   if (!memoryImage.isValid(address)) {
      return nextValid();
   }
   return true;
}

/**
 *  Advance to next occupied flash location
 *
 *  @return true  => Advanced to next occupied location
 *  @return false => No occupied locations remain, enumerator is left at last \e unoccupied location
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
         address += FlashImageImp::PAGE_SIZE;
         address &= ~FlashImageImp::PAGE_MASK;
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

/**
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
      if ((offset == FlashImageImp::PAGE_SIZE-1) || !memoryPage->isValid(++offset)) {
//         log.print("end=0x%06X\n", address);
         return;
      }
      address++;
   } while (1);
}

/*
 * ======================================================================
 */

/**
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
      discardFF(true),
      printHeader(true),
      programHeaders(0),
      symTable(0) {
}

/**
 *  Set target type of image
 *
 *  @param targetType - Target type to set
 */
void FlashImageImp::setTargetType(TargetType_t targetType) {
   this->targetType = targetType;
   if (targetType == T_MC56F80xx) {
      wordAddresses = true;
   }
   clear();
}

/**
 *  ~Constructor
 */
FlashImageImp::~FlashImageImp() {
   clear();
}

/**
 *  Get string describing the error code
 *
 *  @param rc - Error code
 *
 *  @return String describing the error
 */
const char *FlashImageImp::getErrorString(USBDM_ErrorCode rc) {
   return USBDM_GetErrorString(rc);
}

/**
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

/**
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

/**
 *  Gets an enumerator for the memory
 */
FlashImage::EnumeratorPtr FlashImageImp::getEnumerator(uint32_t address) {
   return EnumeratorPtr(new EnumeratorImp(*this, address));
}

/**
 *  Check if image is entirely empty (never written to)
 *
 *  @return true  => image is entirely empty
 *  @return false => image is not empty
 */
bool FlashImageImp::isEmpty() const {
   return elementCount==0;
}

/**
 *  Prints a summary of the Flash memory allocated/used.
 */
void FlashImageImp::printMemoryMap() {
   EnumeratorPtr enumerator(getEnumerator());
   UsbdmSystem::Log::print("Memory Map ===========>\n");
   while (enumerator->isValid()) {
      // Start address of block
      uint32_t startBlock = enumerator->getAddress();
      // Find end of block
      enumerator->lastValid();
      uint32_t endBlock = enumerator->getAddress();
      UsbdmSystem::Log::print("Memory Block[0x%08X...0x%08X]\n", startBlock, endBlock);
      // Move to start of next occupied range
      enumerator->nextValid();
   }
   UsbdmSystem::Log::print("======================>\n");
}

/**
 *  Returns an approximate count of occupied bytes
 */
unsigned FlashImageImp::getByteCount() const {
   return elementCount*sizeof(uint8_t);
}

/**
 *  Get pathname of last file loaded
 */
const string & FlashImageImp::getSourcePathname() const {
   return sourcePath;
}

/**
 *  Locate Page from page number
 *
 *  @param   pageNum
 *
 *  @return  memory page or NULL if not found
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

/**
 *  Allocate page
 *
 *  @param pageNum
 */
MemoryPagePtr FlashImageImp::allocatePage(uint32_t pageNum) {
   LOGGING_Q;
   MemoryPagePtr memoryPage;

   memoryPage = getmemoryPage(pageNum);
   if (memoryPage == NULL) {
// log.print( "Allocating page #%2.2X [0x%06X-0x%06X]\n", pageNum, pageOffsetToAddress(pageNum, 0), pageOffsetToAddress(pageNum, PAGE_SIZE-1));
      memoryPage.reset(new MemoryPage);
      memoryPages.insert(pair<const uint32_t, MemoryPagePtr>(pageNum, memoryPage));
      // Update cache
      lastMemoryPageAccessed = memoryPage;
   }
   return memoryPage;
}

/**
 *    Load a S19 or ELF file into the buffer. \n
 *
 *  @param filePath     Path of file to load
 *  @param clearBuffer  Clear buffer before loading
 *
 *  @return Error code
 */
USBDM_ErrorCode  FlashImageImp::loadFile(const string &filePath, bool clearBuffer) {
   LOGGING_Q;

   sourceFilename = "";
   sourcePath     = "";
   allowOverwrite = !clearBuffer;
   if (clearBuffer) {
      clear();
   }
   log.print("File: \"%s\"\n", filePath.c_str());

   // Try ELF Format
   USBDM_ErrorCode rc = loadElfFile(filePath);
   if (rc == SFILE_RC_UNKNOWN_FILE_FORMAT) {
      // Try SREC Format if not recognized as ELF
      rc = loadS1S9File(filePath);
   }

   if (rc == SFILE_RC_OK) {

      log.print(" Spans [0x%4.4X..0x%4.4X]\n",
            firstAllocatedAddress,  // first non-0xFF address
            lastAllocatedAddress    // last non-0xFF address
      );
//      printMemoryMap();

      sourcePath      = filePath;
      sourceFilename  = filePath;
   }
   return rc;
}

/**
 *  Save image buffer as a S19 file. \n
 *
 *  @param filePath    Path of file to load
 *  @param discardFF   Discard sizable blocks of consecutive 0xFF values (assumed blank)
 *
 *  @return Error code
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

/**
 *  Dump a single S-record to stdout
 *
 *  @param file     File handle for writes
 *  @param buffer   Location of data to dump
 *  @param address  Base address of data
 *  @param size     Number of bytes to dump
 *
 *  @note size must be less than or equal to \ref maxSrecSize
 *  @note S-records filled with 0xFF are discarded
 */
void FlashImageImp::writeSrec(uint8_t *buffer, uint32_t address, unsigned size) {
   LOGGING_Q;
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

/**
 *  Dump data as S-records to stdout
 *
 *  @param file     File handle for writes
 *  @param buffer   Location of data to dump
 *  @param address  Base address of data
 *  @param size     Number of bytes to dump
 *
 *  @note Regions filled with 0xFF are discarded
 */
void FlashImageImp::writeData(uint8_t *buffer, uint32_t address, unsigned size) {
   LOGGING;
   log.print("[0x%06X..0x%06X]\n", address, address+size-1);
   while (size>0) {
      uint8_t oddBytes = address & (MAX_SREC_SIZE-1);
      uint8_t srecSize = MAX_SREC_SIZE - oddBytes;
      if (srecSize > size) {
         srecSize = (uint8_t) size;
      }
      writeSrec(buffer, address, srecSize);
      address += srecSize;
      buffer  += srecSize;
      size    -= srecSize;
   }
}

/**
 *  Obtain the value of a Flash memory location
 *
 *  @param address Memory address
 *
 *  @return Value (dummy value of 0xFF.. is unallocated address)
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

/**
 *  Set a Flash memory location
 *
 *  @param address Memory address
 *  @param value   Value to write to image
 *
 *  @note Allocates a memory location if necessary
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
 *  Remove a Flash memory location (set to unprogrammed)
 *
 *  @param address - Memory address
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

/**
 *  Dump the contents of a range of memory to log file
 *
 *  @param startAddress Start of range
 *  @param endAddress   End of range
 *
 */
void FlashImageImp::dumpRange(uint32_t startAddress, uint32_t endAddress) {
   uint32_t addr;
   uint32_t rangeEnd;

   UsbdmSystem::Log::print("\n");
   UsbdmSystem::Log::print("Dump of [0x%06X-0x%06X]\n", startAddress, endAddress);
   EnumeratorImp iter(*this, startAddress);
   if (!iter.isValid()) {
      iter.nextValid();
   }
   bool endOfLine = true;
   do {
      if (sizeof(uint8_t) == 1) {
         addr = iter.getAddress() & ~0xF;
         if (addr > endAddress) {
            break;
         }
         iter.lastValid();
         rangeEnd = iter.getAddress();
         UsbdmSystem::Log::print("        : 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F  \n");
         UsbdmSystem::Log::print("==========================================================\n");
         endOfLine = true;
         while ((addr <= rangeEnd) && (addr <= endAddress)) {
            if (endOfLine) {
               UsbdmSystem::Log::print("%8.8X: ", addr);
            }
            if ((addr >= startAddress) && isValid(addr)) {
               UsbdmSystem::Log::printq("%02X ", getValue(addr));
            }
            else {
               UsbdmSystem::Log::printq("   ");
            }
            endOfLine = (((addr & 0x000F) == 0xF) || (addr == rangeEnd));
            if (endOfLine) {
               UsbdmSystem::Log::printq("\n");
            }
            addr++;
         }
      }
      else {
         addr = iter.getAddress() & ~0xF;
         if (addr > endAddress) {
            break;
         }
         iter.lastValid();
         rangeEnd = iter.getAddress();
         UsbdmSystem::Log::print("        : 0    1    2    3    4    5    6    7    \n");
         UsbdmSystem::Log::print("==================================================\n");
         endOfLine = true;
         while ((addr <= rangeEnd) && (addr <= endAddress)) {
            if (endOfLine) {
               UsbdmSystem::Log::print("%8.8X: ", addr);
            }
            if ((addr >= startAddress) && isValid(addr)) {
               UsbdmSystem::Log::printq("%04X ", getValue(addr));
            }
            else {
               UsbdmSystem::Log::printq("     ");
            }
            endOfLine = (((addr & 0x0007) == 0x7) || (addr == rangeEnd));
            if (endOfLine) {
               UsbdmSystem::Log::printq("\n");
            }
            addr++;
         }
      }
   } while (iter.nextValid());
   if (!endOfLine) {
      UsbdmSystem::Log::printq("\n");
   }
   UsbdmSystem::Log::print("\n");
}

/**
 *  Load data into Flash image
 *
 *  @param bufferSize    Size of data to load (in uint8_t)
 *  @param address       Address to load at
 *  @param data          Data to load
 *  @param dontOverwrite Produce error if overwriting existing data
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

/**
 *  Load data into Flash image from byte array
 *
 *  @param bufferSize     Size of data to load (in bytes)
 *  @param address        Address to load at (byte/word address)
 *  @param data           Data to load
 *  @param dontOverwrite  True to prevent overwriting data
 *
 *  @note This is only of use if uint8_t is not a byte
 */
USBDM_ErrorCode FlashImageImp::loadDataBytes(uint32_t        bufferSize,
                                             uint32_t        address,
                                             const uint8_t   data[],
                                             bool            dontOverwrite) {
   LOGGING_Q;
   log.print("load[0x%04X...0x%04X]\n", address, address+bufferSize-1);
   uint32_t bufferAddress = 0;
   while (bufferAddress < bufferSize) {
//      log.print("image[0x%08X] <= 0x%04X\n", address, data[bufferAddress]);
      if (!this->isValid(address) || !dontOverwrite) {
         this->setValue(address, data[bufferAddress]);
      }
      address++;
      bufferAddress++;
   }
   return BDM_RC_OK;
}

void FlashImageImp::fill(uint32_t size, uint32_t address, uint8_t fillValue) {
   while (size-->0) {
      setValue(address++, fillValue);
   }
}

void FlashImageImp::fillUnused(uint32_t size, uint32_t address, uint8_t fillValue) {
   while (size-->0) {
      if (isValid(address)) {
         // Already allocated address
         continue;
      }
      setValue(address++, fillValue);
   }
}

/**
 *  Maps Address to PageNum:offset
 *
 *  @param address  Address
 *  @param pageNum  Page number portion of address
 *  @param offset   Offset within page
 *
 *  @note - These values do NOT refer to the paging structure used by the target!
 */
void FlashImageImp::addressToPageOffset(uint32_t address, uint16_t &pageNum, uint16_t &offset) {
   offset  = address & PAGE_MASK;
   pageNum = address >> PAGE_BIT_OFFSET;
   //      printf("%8.8X=>%2.2X:%4.4X\n", address, pageNum, offset);
}

/**
 *  Maps PageNum:offset to Address
 *
 *  @param pageNum  Page number portion of address
 *  @param offset   Offset within page
 *
 *  @return Address
 *
 *  @note - These values do NOT refer to the paging structure used by the target!
 */
uint32_t FlashImageImp::pageOffsetToAddress(uint16_t pageNum, uint16_t offset) {
   if (offset>=PAGE_SIZE)
      throw runtime_error("Page offset too large\n");
   return (pageNum << PAGE_BIT_OFFSET) + offset;
}

/**
 *  Convert a 32-bit unsigned number between Target and Native format
 *
 *  @param value Value to convert
 *
 *  @return Converted value
 */

uint32_t FlashImageImp::targetToNative(uint32_t &value) {
   if (littleEndian) {
      return value;
   }
   uint32_t relocAddress = ((value<<24)&0xFF000000) + ((value<<8)&0x00FF0000) +
         ((value>>8) &0x0000FF00) + ((value>>24)&0x000000FF);
//   UsbdmSystem::Log::print("0x%08X => 0x%08X\n", value, relocAddress);
//   value = relocAddress;
   return relocAddress;
}

/**
 *  Convert a 16-bit unsigned number between Target and Native format
 *
 *  @param value Value to convert
 *
 *  @return Converted value
 */

uint16_t FlashImageImp::targetToNative(uint16_t &value) {
   if (littleEndian) {
      return value;
   }
   return ((value<<8)&0xFF00) + ((value>>8)&0x00FF);
}

/**
 *  Convert a 32-bit signed number between Target and Native format
 *
 *  @param value Value to convert
 *
 *  @return Converted value
 */
int32_t FlashImageImp::targetToNative(int32_t &value) {
   if (littleEndian) {
      return value;
   }
   return ((value<<24)&0xFF000000) + ((value<<8)&0x00FF0000) +
         ((value>>8) &0x0000FF00) + ((value>>24)&0x000000FF);
}

/**
 *  Convert a 16-bit signed number between Target and Native format
 *
 *  @param value Value to convert
 *
 *  @return Converted value
 */
int16_t FlashImageImp::targetToNative(int16_t &value) {
   if (littleEndian) {
      return value;
   }
   return ((value<<8)&0xFF00) + ((value>>8)&0x00FF);
}

/*
 *  Load a Freescale S-record file into the buffer. \n
 *
 *  The buffer is cleared to 0xFFFF before loading.  Modified locations will
 *  have a non-0xFF upper byte so used locations can be differentiated. \n
 *
 *  @param fileName Path of file to load
 *
 *  @return Error code
 */
USBDM_ErrorCode FlashImageImp::loadS1S9File(const string &fileName) {
   LOGGING_Q;
   char        *ptr;
   char         buffer[1024];
   uint32_t     addr;
   uint32_t     srecSize;
   uint8_t      checkSum;
   bool         fileRecognized = false;

   Openfile file(fileName.c_str(), "rt");
   fp = file.getfp();

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
         return SFILE_RC_CHECKSUM;
      }
      fileRecognized = true; // Read at least 1 record - assume it's a SREC file
//      log.print("\n");
   }
//   log.print("FlashImageImp::MemorySpace::loadS1S9File()\n");
//   printMemoryMap();
   return SFILE_RC_OK;
}

/*=============================================================================
 * ELF Files
 *===========================================================================*/

/**
 *  Get string describing pFlags
 *
 *  @param  flags
 *
 *  @return Pointer to static string
 */
static const char* get_pFlagsName(unsigned int flags) {
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

/**
 *  Get string describing pTypeName
 *
 *  @param  type
 *
 *  @return Pointer to static string
 */
static const char* get_pTypeName(unsigned int type) {
   switch (type) {
   case PT_NULL:      return "PT_NULL";
   case PT_LOAD:      return "PT_LOAD";
   case PT_DYNAMIC:   return "PT_DYNAMIC";
   case PT_INTERP:    return "PT_INTERP";
   case PT_NOTE:      return "PT_NOTE";
   case PT_SHLIB:     return "PT_SHLIB";
   case PT_PHDR:      return "PT_PHDR";
   case PT_ARM_EXIDX: return "PT_ARM_EXIDX";
   default :          return "????";
   }
}

/**
 *  Get string describing shtype
 *
 *  @param  type
 *
 *  @return Pointer to static string
 */
static const char *getshTypeName(Elf32_Word shtype) {
   static char buff[30] = {0};
   buff[0] = '\0';
   strcat(buff, "(");
   switch (shtype) {
   case SHT_ARM_EXIDX           : strcat(buff, "ARM_EXIDX ");          break;
   case SHT_ARM_PREEMPTMAP      : strcat(buff, "ARM_PREEMPTMAP ");     break;
   case SHT_ARM_ATTRIBUTES      : strcat(buff, "ARM_ATTRIBUTES ");     break;
   case SHT_ARM_DEBUGOVERLAY    : strcat(buff, "ARM_DEBUGOVERLAY ");   break;
   case SHT_ARM_OVERLAYSECTION  : strcat(buff, "ARM_OVERLAYSECTION "); break;

   case SHT_NULL                : strcat(buff, "NULL ");               break;
   case SHT_PROGBITS            : strcat(buff, "PROGBITS");            break;
   case SHT_SYMTAB              : strcat(buff, "SYMTAB ");             break;
   case SHT_STRTAB              : strcat(buff, "STRTAB ");             break;
   case SHT_RELA                : strcat(buff, "RELA ");               break;
   case SHT_HASH                : strcat(buff, "HASH ");               break;
   case SHT_DYNAMIC             : strcat(buff, "DYNAMIC ");            break;
   case SHT_NOTE                : strcat(buff, "NOTE ");               break;
   case SHT_NOBITS              : strcat(buff, "NOBITS ");             break;
   case SHT_REL                 : strcat(buff, "REL ");                break;
   case SHT_SHLIB               : strcat(buff, "SHLIB ");              break;
   case SHT_DYNSYM              : strcat(buff, "DYNSYM ");             break;
   case SHT_INIT_ARRAY          : strcat(buff, "INIT_ARRAY ");         break;
   case SHT_FINI_ARRAY          : strcat(buff, "FINI_ARRAY ");         break;
   case SHT_PREINIT_ARRAY       : strcat(buff, "PREINIT_ARRAY ");      break;
   }
   strcat(buff, ")");
   return buff;
   //#define SHT_LOPROC      0x70000000
   //#define SHT_HIPROC      0x7fffffff
   //#define SHT_LOUSER      0x80000000
   //#define SHT_HIUSER      0xffffffff
}

/**
 *  Get string describing shflags
 *
 *  @param  type
 *
 *  @return Pointer to static string
 */
static const char *getshFlagName(Elf32_Word shflags) {
   static char buff[100];
   buff[0] = '\0';
   strcat(buff, "(");
   if (shflags&SHF_ALLOC) {
      strcat(buff, "ALLOC ");
   }
   if ((shflags&SHF_WRITE) == 0) {
      strcat(buff, "READONLY ");
   }
   if (shflags&SHF_EXECINSTR) {
      strcat(buff, "CODE ");
   }
   else {

   }
   strcat(buff, ")");
   return buff;
}

/**
 *  Check if ELF machine ID agrees with target
 *
 *  @param e_machine  ID from ELF file
 *  @param targetType Target type to check against
 *
 *  @return Error code on mismatch
 */
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

/**
 *  Load a ELF block into the buffer.
 *
 *  The buffer is cleared to 0xFFFF before loading.  Modified locations will
 *  have a non-0xFF upper byte so used locations can be differentiated. \n
 *
 *  @param fp       Open file pointer
 *  @param fOffset  Offset to block in file
 *  @param size     Size of block in bytes
 *  @param addr     Bytes address to load block
 */
USBDM_ErrorCode FlashImageImp::loadElfBlock(
      FILE       *fp,
      long        fOffset,
      Elf32_Word  size,
      Elf32_Addr  addr) {

   LOGGING_Q;
#if defined(TARGET) && (TARGET == MC56F80xx)
   // DSC image uses word addresses
   addr /= 2;
#endif
   if (size == 0) {
      //      log.print("[empty]\n");
      return BDM_RC_OK;
   }
#if defined(TARGET) && (TARGET == MC56F80xx)
      log.print("[0x%08X..0x%08X]\n", addr, addr+size/2-1);
#else
      log.print("[0x%08X..0x%08X]\n", addr, addr+size-1);
#endif
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

/**
 *  Print ELF Header
 *
 *  @param elfHeader ELF header to print
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

/**
 *  Convert fields in ELF header to native format
 *
 *  @param elfHeader ELF header to convert
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

/**
 *  Print ELF Program Header
 *
 *  @param programHeader ELF Program header to print
 */
void FlashImageImp::printElfProgramHeader(Elf32_Phdr *programHeader) {
   if (printHeader) {
      UsbdmSystem::Log::printq("=== Program Header Table (Segments) ===\n"
            "p_type                       p_offset   p_vaddr    p_paddr    p_filesz   p_memsz    p_align    p_flags\n");
      printHeader = false;
   }
   UsbdmSystem::Log::printq(
         "0x%08X (%-15s) 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X (%-20s)\n",
         programHeader->p_type  , get_pTypeName(programHeader->p_type),
         programHeader->p_offset,
         programHeader->p_vaddr ,
         programHeader->p_paddr ,
         programHeader->p_filesz,
         programHeader->p_memsz ,
         programHeader->p_align ,
         programHeader->p_flags , get_pFlagsName(programHeader->p_flags)
   );
}

/**
 *  Print ELF Program Header
 *
 *  @param programHeader -  ELF Program header to print
 */
void FlashImageImp::printElfSectionHeader(Elf32_Shdr *elfsHeader) {
   if (elfsHeader->sh_type == SHT_NULL) {
      return;
   }
   if (printHeader) {
      printHeader = false;
      UsbdmSystem::Log::printq("=== Section Header Table (Sections) ===\n"
            "shtype                            shflags                             shaddr,    shoffset   shsize     shlink     shinfo     shaddralign shentsize\n");
   }
   UsbdmSystem::Log::printq(
         "%-20s (0x%08X) %-22s (0x%08X) 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X %s\n",
         getshTypeName(elfsHeader->sh_type), elfsHeader->sh_type,
         getshFlagName(elfsHeader->sh_flags), elfsHeader->sh_flags,
         elfsHeader->sh_addr      ,
         elfsHeader->sh_offset    ,
         elfsHeader->sh_size      ,
         elfsHeader->sh_link      ,
         elfsHeader->sh_info      ,
         elfsHeader->sh_addralign ,
         elfsHeader->sh_entsize   ,
         getElfString(elfsHeader->sh_name)
   );
}

/**
 *  Convert fields to native format
 *
 *  @param elfHeader -  ELF Program header to convert
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

/**
 *  Convert fields to native format
 *
 *  @param elfHeader -  ELF Program header to convert
 */
void FlashImageImp::fixElfSectionHeaderSex(Elf32_Shdr *elfsHeader) {
   elfsHeader->sh_name      = targetToNative(elfsHeader->sh_name      );
   elfsHeader->sh_type      = targetToNative(elfsHeader->sh_type      );
   elfsHeader->sh_flags     = targetToNative(elfsHeader->sh_flags     );
   elfsHeader->sh_addr      = targetToNative(elfsHeader->sh_addr      );
   elfsHeader->sh_offset    = targetToNative(elfsHeader->sh_offset    );
   elfsHeader->sh_size      = targetToNative(elfsHeader->sh_size      );
   elfsHeader->sh_link      = targetToNative(elfsHeader->sh_link      );
   elfsHeader->sh_info      = targetToNative(elfsHeader->sh_info      );
   elfsHeader->sh_addralign = targetToNative(elfsHeader->sh_addralign );
   elfsHeader->sh_entsize   = targetToNative(elfsHeader->sh_entsize   );
}

/**
 *  Get string from ELF file string area
 *
 *  @param index ELF string index
 *
 *  @return Pointer to static string
 *
 *  @note Will trigger loading of entire symbol table
 */
const char * FlashImageImp::getElfString(unsigned index) {
   static const char *empty = "-";
   static bool noSymTable = false;

   if (index ==0) {
      return empty;
   }
   if (noSymTable) {
      return empty;
   }
   if (symTable == 0) {
      noSymTable = true;
      if (elfHeader.e_shstrndx == 0) {
         return empty;
      }
      // Load string table section header
      fseek(fp, elfHeader.e_shoff+elfHeader.e_shstrndx*elfHeader.e_shentsize, SEEK_SET);
      size_t sz;
      if ((sz=fread(&stringSectionHeader, 1, sizeof(stringSectionHeader), fp)) != sizeof(stringSectionHeader)) {
         UsbdmSystem::Log::error("Undersize read of String Section Header (Expected %lu, read %lu)\n",
               (unsigned long)sizeof(stringSectionHeader), (unsigned long)sz);
         return empty;
      }
      if (stringSectionHeader.sh_type == SHN_UNDEF) {
         return empty;
      }
      symTable = (char*)malloc(stringSectionHeader.sh_size);
      if (symTable == 0) {
         UsbdmSystem::Log::error("Malloc failed\n");
         return empty;
      }
      fseek(fp, stringSectionHeader.sh_offset, SEEK_SET);
      if (fread(symTable, 1, stringSectionHeader.sh_size, fp) != stringSectionHeader.sh_size) {
         return empty;
      }
      noSymTable = false;
   }
   if (index >= stringSectionHeader.sh_size) {
      return "Illegal";
   }
   return symTable+index;
}

#define USE_SECTIONS

/**
 *  Load a ELF file into the buffer. \n
 *
 *  @param filePath Path of file to load
 *
 *  @return Error code
 */
USBDM_ErrorCode FlashImageImp::loadElfFile(const string &filePath) {
   LOGGING_Q;
   Openfile file(filePath.c_str(), "rb");
   MallocWrapper<Elf32_Phdr> phWrapper(programHeaders);
   MallocWrapper<char>       stWrapper(symTable);

   fp = file.getfp();
   if (fp == NULL) {
      log.error("Failed to open input file \'%s\'\n", filePath.c_str());
      return SFILE_RC_FILE_OPEN_FAILED;
   }
   //   log.print("Input file - \'%s\'\n", filePath.c_str());

   if (fread(&elfHeader, 1, sizeof(elfHeader), fp) != sizeof(elfHeader)) {
      return SFILE_RC_UNKNOWN_FILE_FORMAT;
   }
   //   log.print("FlashImageImp::MemorySpace::loadElfFile() - \n");
   //   printElfHeader(&elfHeader);

   if ((elfHeader.e_ident[EI_MAG0]  != ELFMAG0V) || (elfHeader.e_ident[EI_MAG1] != ELFMAG1V) ||
       (elfHeader.e_ident[EI_MAG2]  != ELFMAG2V) || (elfHeader.e_ident[EI_MAG3] != ELFMAG3V) ||
       (elfHeader.e_ident[EI_CLASS] != ELFCLASS32)) {
      log.error("Unsupported ELF format\n");
      return SFILE_RC_UNKNOWN_FILE_FORMAT;
   }
   littleEndian = elfHeader.e_ident[EI_DATA] == ELFDATA2LSB;
   fixElfHeaderSex(&elfHeader);

   //   log.print("FlashImageImp::MemorySpace::loadElfFile() - elfHeader.e_machine = 0x%X(%d) \n", elfHeader.e_machine, elfHeader.e_machine);
   //   printElfHeader(&elfHeader);

   /*
    * If we get this far we assume we have an ELF file so any error will be ELF format errors
    */
   if ((elfHeader.e_type != ET_EXEC) || (elfHeader.e_phoff == 0) || (elfHeader.e_phentsize == 0) || (elfHeader.e_phnum == 0)) {
      log.error("Invalid format\n");
      return SFILE_RC_ELF_FORMAT_ERROR;
   }

   /*
    * Read program headers
    */
   if (elfHeader.e_phnum <= 0) {
      // No program image to load
      return SFILE_RC_ELF_FORMAT_ERROR;
   }
   const size_t totalProgramHeaderSize = elfHeader.e_phnum*sizeof(Elf32_Phdr);

   phWrapper.alloc(totalProgramHeaderSize);
   if (programHeaders == 0) {
      return SFILE_RC_ELF_FORMAT_ERROR;
   }
   fseek(fp, elfHeader.e_phoff, SEEK_SET);
   size_t sz;
   if ((sz=fread(programHeaders, 1, totalProgramHeaderSize, fp)) != totalProgramHeaderSize) {
      log.error("Undersize read of Header (Expected %lu, read %lu)\n",
            (unsigned long)totalProgramHeaderSize, (unsigned long)sz);
      return SFILE_RC_ELF_FORMAT_ERROR;
   }

   // Convert program headers to native format (and print)
   printHeader = true;
   for(Elf32_Phdr *programHeader=programHeaders;
         programHeader<(programHeaders+elfHeader.e_phnum);
         programHeader++) {
      fixElfProgramHeaderSex(programHeader);
#ifdef LOG
      if (programHeader->p_filesz != 0) {
         printElfProgramHeader(programHeader);
      }
#endif
   }

#ifdef LOG
   printHeader = true;
   for(Elf32_Half sectionIndex=0; sectionIndex<elfHeader.e_shnum; sectionIndex++) {
      Elf32_Shdr sectionHeader;
      fseek(fp, elfHeader.e_shoff+sectionIndex*elfHeader.e_shentsize, SEEK_SET);
      size_t sz;
      if ((sz=fread(&sectionHeader, 1, sizeof(sectionHeader), fp)) != sizeof(sectionHeader)) {
         log.error("Undersize read of Section Header (Expected %lu, read %lu)\n", (unsigned long)sizeof(sectionHeader), (unsigned long)sz);
         return SFILE_RC_ELF_FORMAT_ERROR;
      }
      fixElfSectionHeaderSex(&sectionHeader);
      if (sectionHeader.sh_type&SHT_PROGBITS) {
         printElfSectionHeader(&sectionHeader);
      }
   }
#endif

#ifdef USE_SECTIONS
   log.print("Loading by Section Headers\n");
   if (elfHeader.e_shoff == 0) {
      log.print("No section headers present\n");
      return SFILE_RC_ELF_FORMAT_ERROR;
   }
   // Load image based on suitable sections
   for(Elf32_Half sectionIndex=0; sectionIndex<elfHeader.e_shnum; sectionIndex++) {
      Elf32_Shdr sectionHeader;
      fseek(fp, elfHeader.e_shoff+sectionIndex*elfHeader.e_shentsize, SEEK_SET);
      size_t sz;
      if ((sz=fread(&sectionHeader, 1, sizeof(sectionHeader), fp)) != sizeof(sectionHeader)) {
         log.error("Undersize read of Section Header (Expected %lu, read %lu)\n", (unsigned long)sizeof(sectionHeader), (unsigned long)sz);
         return SFILE_RC_ELF_FORMAT_ERROR;
      }
      fixElfSectionHeaderSex(&sectionHeader);
      loadElfBlockBySectionHeader(&sectionHeader);
   }
#else
   // Load image based on suitable segments
   log.print("Loading by Program Headers\n");
   for(Elf32_Phdr *programHeader=programHeaders;
         programHeader<(programHeaders+elfHeader.e_phnum);
         programHeader++) {
      if (programHeader->p_filesz>0) {
         printElfProgramHeader(programHeader);
      }
      USBDM_ErrorCode rc = loadElfBlockByProgramHeader(programHeader);
      if (rc != BDM_RC_OK) {
         return rc;
      }
   }
#endif
   return SFILE_RC_OK;
}

#ifdef USE_SECTIONS
/**
 *  Gets load address (physical address)
 *  Most needed for .data
 *
 *  @param  sectionHeader  Section Header to determine load address for
 *
 *  @return Corresponding load address (may be the same)
 */
Elf32_Addr FlashImageImp::getLoadAddress(Elf32_Shdr *sectionHeader) {
   for(Elf32_Phdr *programHeader=programHeaders;
         programHeader<(programHeaders+elfHeader.e_phnum);
         programHeader++) {
      if ((programHeader->p_offset<=sectionHeader->sh_offset) &&
          ((programHeader->p_offset+programHeader->p_filesz)>=(sectionHeader->sh_offset+sectionHeader->sh_size))) {
         Elf32_Addr lAddress = sectionHeader->sh_addr;
         Elf32_Addr pAddress = sectionHeader->sh_offset - programHeader->p_offset + programHeader->p_paddr;
         UsbdmSystem::Log::print("L:0x%08X ==> P:0x%08X\n", lAddress, pAddress);
         return pAddress;
      }
   }
   throw new MyException(SFILE_RC_ELF_FORMAT_ERROR);
}

/**
 *  Load ELF block based on section header
 *
 *  @param sectionHeader Section header describing section to load into image
 *
 *  @return Error code
 */
USBDM_ErrorCode FlashImageImp::loadElfBlockBySectionHeader(Elf32_Shdr *sectionHeader) {
   LOGGING_Q;

   if ((sectionHeader->sh_flags&SHF_ALLOC) == 0) {
      return BDM_RC_OK;
   }
   if (sectionHeader->sh_type == SHT_NOBITS) {
      return BDM_RC_OK;
   }
   Elf32_Addr loadAddress = sectionHeader->sh_addr; //getLoadAddress(sectionHeader);
   Elf32_Word size        = sectionHeader->sh_size;

#if defined(TARGET) && (TARGET == MC56F80xx)
   // DSC image uses word addresses
   addr /= 2;
#endif
   if (size == 0) {
//      log.print("[empty]\n");
      return BDM_RC_OK;
   }
#if defined(TARGET) && (TARGET == MC56F80xx)
      log.print("loading [0x%08X..0x%08X] @0x%08X\n", sectionHeader->sh_addr, sectionHeader->sh_addr+size/2-1 loadAddress);
#else
      log.print("loading [0x%08X..0x%08X] @0x%08X\n", sectionHeader->sh_addr, sectionHeader->sh_addr+size-1, loadAddress);
#endif
   fseek(fp, sectionHeader->sh_offset, SEEK_SET);
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
//      log.printDump(buff, blockSize, loadAddress);
      for (unsigned index=0; index<blockSize; ) {
         uint16_t value;
#if defined(TARGET) && (TARGET == MC56F80xx)
         value  = buff[index++];
         value += buff[index++]<<8;
#else
         value = buff[index++];
#endif
         this->setValue(loadAddress++, value);
      }
      size -= blockSize;
   }
   return SFILE_RC_OK;
}
#else
/**
 *  Load ELF block based on program header
 *
 *  @param sectionHeader Program header describing program segment to load into image
 *
 *  @return Error code
 */
USBDM_ErrorCode FlashImageImp::loadElfBlockByProgramHeader(Elf32_Phdr *programHeader) {
   LOGGING_Q;

//   printElfProgramHeader(programHeader);

   Elf32_Addr loadAddress;
   if ((programHeader->p_type&PT_LOAD) == 0) {
      return BDM_RC_OK;
   }
   if (programHeader->p_filesz == 0) {
      return BDM_RC_OK;
   }
   if ((targetType == T_RS08) || (targetType == T_HCS08) || (targetType == T_HCS12) || (targetType == T_S12Z) || (targetType == T_MC56F80xx)) {
      // These targets use the virtual address as the load address
      loadAddress = programHeader->p_vaddr;
      log.print("Using p_vaddr = 0x%08X\n", loadAddress);
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
      log.print("Using p_paddr = 0x%08X\n", loadAddress);
   }
   return loadElfBlock(fp, programHeader->p_offset, programHeader->p_filesz, loadAddress);
}
#endif // USE_SECTIONS

