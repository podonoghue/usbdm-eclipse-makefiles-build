/*! \file
   \brief Utility Routines for loading Freescale S-Record Files

   FlashImage.cpp

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
+==============================================================================
| 14 Feb 11 | Changed to dynamic memory allocation for buffer     V4.5    - pgo
+------------------------------------------------------------------------------
| 30 Jan 10 | 2.0.0 Changed to C++                                        - pgo
|           |       Added paged memory support                            - pgo
+-----------+------------------------------------------------------------------
|  8 Dec 09 | Started changes for paged files - incomplete                - pgo
+------------------------------------------------------------------------------
|  ??    09 | Created                                                     - pgo
+==============================================================================
\endverbatim
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "UsbdmSystem.h"
#include "Common.h"
#include "FlashImage.h"
#include "ApplicationFiles.h"

//! Error code returned by the various routines
static const char *errorMessages[] = {
   ("No error"),
   ("S-record checksum error"),
   ("S-file unrecognized/unsupported line"),
   ("Hex file failed to open"),
   ("S-record address too large"),
   ("Illegal operand"),
};

//! Obtain Error message string from error number
//!
//! @param errorNum - error number to look up
//!
//! @return ptr to static string describing the error
//!
const char *FlashImage::getErrorMessage(FlashImage::ErrorCode errorNum) {
   static const char unknownErrorMsg[] = "Unknown";

   if ((unsigned)errorNum < (sizeof(errorMessages)/sizeof(errorMessages[0])))
      return errorMessages[errorNum];

   return unknownErrorMsg;
}

/*! Convert a single HEX character ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 15
 */
static unsigned int hex1ToDecimal(char **ptr) {
   uint8_t data = *(*ptr)++;
   if ((data >= '0') && (data <= '9'))
      return data - '0';
   if ((data >= 'a') && (data <= 'f'))
      return data - 'a' + 10;
   if ((data >= 'A') && (data <= 'F'))
      return data - 'A' + 10;
   return 0;
}

/*! Convert two HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 255
 */
static unsigned int hex2ToDecimal( char **ptr) {
   int data  =             hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}

/*! Convert four HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 65535
 */
static uint16_t hex4ToDecimal( char **ptr) {
   int data  =             hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}

/*! Convert six HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 0xFFFFFFU
 */
static uint32_t hex6ToDecimal( char **ptr) {
   int data  =             hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}

/*! Convert six HEX characters ('0'-'9', 'a'-'f' or 'A'-'F') into a number
 *
 * @param ptr  -  Ptr to the ptr to the character to convert. *ptr is advanced
 *
 * @return - a value in the range 0 to 0xFFFFFFU
 */
static uint32_t hex8ToDecimal( char **ptr) {
   int data  =             hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   data      = data * 16 + hex1ToDecimal(ptr);
   return data;
}

void FlashImage::MemorySpace::dumpRange(unsigned int startAddress, unsigned int endAddress) {
   uint32_t addr;
   uint32_t rangeEnd;

   UsbdmSystem::Log::print("Dump of [0x%06X-0x%06X]\n", startAddress, endAddress);
   Enumerator iter(*this, startAddress);
   if (!iter.isValid())
      iter.nextValid();
   do {
      addr = iter.getAddress() & ~0xF;
      iter.lastValid();
      rangeEnd = iter.getAddress();
      UsbdmSystem::Log::print("        : 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n"
            "========================================================\n");
      while (addr <= rangeEnd) {
         if (((addr & 0x000F) == 0) || (addr == startAddress))
            UsbdmSystem::Log::print("%8.8X:", addr);
               if (isValid(addr))
                  UsbdmSystem::Log::print("%02X ", getValue(addr));
               else
                  UsbdmSystem::Log::print("   ");
         if (((addr & 0x000F) == 0xF) || (addr == rangeEnd))
            UsbdmSystem::Log::print("\n");
         addr++;
      }
   } while (iter.nextValid());
   UsbdmSystem::Log::print("\n\n");
}

//!   Load a Freescale S-record file into the buffer. \n
//!
//!   The buffer is cleared to 0xFFFF before loading.  Modified locations will
//!   have a non-0xFF upper byte so used locations can be differentiated. \n
//!
//! @param fileName         : Path of file to load
//! @param clearBuffer      : Clear the buffer before loading
//!
//! @return error code see \ref FlashImage::ErrorCode
//!
FlashImage::ErrorCode FlashImage::MemorySpace::loadS1S9File(const string   &fileName,
                                                            bool           clearBuffer,
                                                            bool           wordAddresses) {
   LOGGING_Q;
   char *ptr;
   unsigned int  data;
   char buffer[1024];
   uint32_t  addr;
   uint32_t  size;
   FILE *fp;
   uint8_t checkSum;
//   uint8_t paged;
   int lineNum;

   if (clearBuffer) {
      initData();
   }
   log.print("Filepath = %s\n", fileName.c_str()); fflush(stderr);

   fp = openApplicationFile(fileName.c_str(), "rb");

   if (fp == NULL) {
      log.print("Failed to open input file \"%s\"\n", fileName.c_str());

      return SFILE_RC_FILE_OPEN_FAILED;
   }
   log.print("Loading input file \"%s\"\n", fileName.c_str()); fflush(stderr);

   lineNum  = 0;
//   paged    = false; // Assume
   while (fgets(buffer, sizeof(buffer)-1, fp) != NULL) {
      lineNum++;
      //log.print("Input: %s",buffer);
      ptr = buffer;
      // Find first non-blank
      while ((*ptr == ' ') || (*ptr == '\t') || (*ptr == '\n') || (*ptr == '\r'))
         ptr++;
      // Check if S-record
      if ((*ptr != 'S') && (*ptr != 's')) {
         log.print("loadS1S9File() - illegal line #%5d-%s", lineNum, buffer);
         fclose(fp);
         return SFILE_RC_ILLEGAL_LINE;
      }
      switch (*(ptr+1)) {
         case '0': // Information header
         case '7': // 32-bit start address
         case '8': // 24-bit start address
         case '9': // 16-bit start address
            // Discard S0, S7, S8 & S9 records
            continue;
         case '1':
            // S1 = 16-bit address, data record
            ptr +=2; // Skip 'S1'
            size = hex2ToDecimal( &ptr );
            addr = hex4ToDecimal( &ptr );
            checkSum = (uint8_t)size + (uint8_t)(addr>>8) + (uint8_t)addr;
            size -= 3; // subtract 3 from byte count (size + 2 addr bytes)
            //log.print("(%2.2X)%4.4lX:\n",size,addr);
            break;
         case '2':
            // S2 = 24-bit address, data record
            ptr +=2; // Skip 'S2'
            size = hex2ToDecimal( &ptr );
            addr = hex6ToDecimal( &ptr );
            checkSum = (uint8_t)size + (uint8_t)(addr>>16) + (uint8_t)(addr>>8) + (uint8_t)addr;
            size -= 4; // subtract 4 from byte count (size + 3 addr bytes)
            //log.print("size=0x%02X, addr=0x%06X\n",size,addr);
            break;
         case '3':
            // S3 32-bit address, data record
            ptr +=2; // Skip 'S3'
            size = hex2ToDecimal( &ptr );
            addr = hex8ToDecimal( &ptr );
            checkSum = (uint8_t)size + (uint8_t)(addr>>24) + (uint8_t)(addr>>16) + (uint8_t)(addr>>8) + (uint8_t)addr;
            size -= 5; // subtract 5 from byte count (size + 4 addr bytes)
//            log.print("S3: size=0x%02X, addr=0x%08X, initial chk=0x%02X\n", size, addr, checkSum);
            break;
         default:
            log.print("loadS1S9File() - illegal line #%5d-%s", lineNum, buffer);
            fclose(fp);
            return SFILE_RC_ILLEGAL_LINE;
      }
      if (wordAddresses) {
         addr *= 2;
      }
      while (size-->0) {
         data = hex2ToDecimal( &ptr );
//         if (!allocatePage(addr)) {
//            log.print("loadS1S9File() - illegal line #%5d-%s", lineNum, buffer);
//            log.print("loadS1S9File() Address is too large = 0x%06X > 0x%08lX\n",
//                  addr, MAX_SFILE_ADDRESS);
//
//            fclose(fp);
//            return SFILE_RC_ADDRESS_TOO_LARGE;
//         }
         if (addr > 0xFFFF)
            largeModel = true;
         this->setValue(addr++, (uint8_t)data);
//         log.print("%02X",data);
         checkSum += (uint8_t)data;
      }
      // Get checksum from record
      data = hex2ToDecimal( &ptr );
      if ((uint8_t)~checkSum != data) {
         log.print("loadS1S9File() - illegal line #%5d:\n%s", lineNum, buffer);
         log.print("loadS1S9File() checksum error, Checksum=0x%02X, "
               "Calculated Checksum=0x%02X\n",
               data, (uint8_t)~checkSum);
         fclose(fp);
         return SFILE_RC_CHECKSUM;
      }
      //log.print("\n");
   }
//   fprintf( stderr,
//            "Lowest used Address \t = 0x%4.4X\n"
//            "Highest used Address\t = 0x%4.4X\n",
//            flashImageDescription->firstAddr,  // first non-0xFF address
//            flashImageDescription->lastAddr    // last non-0xFF address
//            );
//

   fclose(fp);

//   dumpFile(&flashImageDescription);
//   printMemoryMap();

//   dumpRange(firstAllocatedAddress, lastAllocatedAddress);
   return SFILE_RC_OK;
}

//=====================================================================
//! Load data into Flash image
//!
//! @param bufferSize - size of data to load (in bytes)
//! @param address    - address to load at
//! @param data       - data to load

FlashImage::ErrorCode FlashImage::MemorySpace::loadData(uint32_t      bufferSize,
                                                        uint32_t      address,
                                                        const uint8_t data[],
                                                        bool          dontOverwrite) {
   unsigned int bufferAddress;

   //   log.print("FlashImage::loadData(0x%04X...0x%04X)\n", address, address+bufferSize-1);
   bufferAddress = 0;
   while (bufferAddress < bufferSize){
//      if (!allocatePage(address)) {
//         log.print("loadData() - Address is too large = 0x%08X > 0x%08lX\n",
//               address, MAX_SFILE_ADDRESS);
//
//         return SFILE_RC_ADDRESS_TOO_LARGE;
//      }
      if (address > 0xFFFFU)
         largeModel = true;
      if (!this->isValid(address) || !dontOverwrite) {
         this->setValue(address, data[bufferAddress]);
      }
      address++;
      bufferAddress++;
   }
//   printMemoryMap();
   return SFILE_RC_OK;
}

//=====================================================================
//! Prints a summary of the Flash memory allocated/used.
//!
void FlashImage::printMemoryMap(void) const {
//   uint16_t offset;
//   uint16_t pageNum;
//   uint16_t first;
//   uint16_t last;

   //    dumpRange(0x000000U, 0x000FFF);
   //   for (pageNum = 0; pageNum < sizeof(memoryPages)/sizeof(memoryPages[0]); pageNum++) {
   //      if (memoryPages[pageNum] != NULL) {
   //         last  = 0x0000;
   //         first = PAGE_SIZE-1;
   //         for (offset =0; offset < PAGE_SIZE; offset++) {
   //            if ((memoryPages[pageNum][offset] & 0xFF00) != 0xFF00) {
   //               if (offset < first)
   //                  first = offset;
   //               if (offset > last)
   //                  last = offset;
   //            }
   //         }
   //         log.print("Page #%4X allocated", pageNum);
   //         if (first <= last)
   //            log.print(", [%8.8X-%8.8X] => [%8.8X-%8.8X] occupied", first, last,
   //                   pageOffsetToAddress(pageNum,first), pageOffsetToAddress(pageNum,last));
   //         log.print("\n");
   ////         dumpRange(first, last);
   //
   //      }
   //   }
#if 0
   uint32_t address;
   last  = 0x0000;
   first = sizeof(memoryImage)/sizeof(memoryImage[0])-1;
   for (address = 0; address < sizeof(memoryImage)/sizeof(memoryImage[0]); address++) {
      if (memoryImage[address] != 0xFFFF) {
         printf("mem[%X] => %2.2X\n", address, memoryImage[address]);
      }
   }
#endif
}

//! Advance to next occupied flash location
//!
//! @return \n
//!        true  => advanced to next occupied location
//!        false => no occupied locations remain, enumerator is left at last \e unoccupied location
//!
bool FlashImage::Enumerator::nextValid() {
   const MemoryPage *memoryPage = NULL;
   uint16_t pageNum, offset;
//   log.print("enumerator::nextValid(start=0x%06X)\n", address);
   address++;
   do {
      addressToPageOffset(address, pageNum, offset);
//      log.print("enumerator::nextValid() checking 0x%06X)\n", address);

      // At start of page or haven't checked this page yet
      if ((offset == 0) || (memoryPage == NULL)) {
         map<uint32_t, MemoryPage *>::iterator iter = memoryImage.memoryPages.find(pageNum);
         if (iter == memoryImage.memoryPages.end())
            memoryPage = NULL;
         else
            memoryPage = iter->second;
      }
      if (memoryPage == NULL) {
         // Unallocated page - move to start of next page
//         log.print("enumerator::nextValid(a=0x%06X) - skipping unallocated page #0x%X\n", address, pageNum);
         address += PAGE_SIZE;
         address &= ~PAGE_MASK;
         if (address > memoryImage.lastAllocatedAddress) {
//            address = memoryImage.lastAllocatedAddress;
//            log.print("enumerator::nextValid(end  =0x%06X), no remaining valid addresses\n", address);
            return false;
         }
         continue;
      }
      // Check if valid byte in page
      if (memoryPage->isValid(offset)) {
//         log.print("enumerator::nextValid(end  =0x%06X)\n", address);
         return true;
      }
      address++;
   } while (1);
   return false;
}

//! Advance location to just before the next unoccupied flash location or page boundary
//! Assumes current location is occupied.
//!
//! @return \n
//!        true  => advanced to last occupied location or just before a page boundary
//!        false => no unoccupied locations remain, enumerator is advanced to last occupied location
//!
void FlashImage::Enumerator::lastValid() {
   uint16_t pageNum, offset;
//   log.print("enumerator::lastValid(start=0x%06X)\n", address);
   addressToPageOffset(address, pageNum, offset);
   map<uint32_t, MemoryPage *>::iterator iter = memoryImage.memoryPages.find(pageNum);
   if (iter == memoryImage.memoryPages.end()) {
//      log.print("enumerator::lastValid(end=0x%06X), start address not allocated\n", address);
      return;
   }
   MemoryPage *memoryPage = iter->second;
   do {
//      log.print("enumerator::lastValid() checking 0x%06X)\n", address);
      if (address == memoryImage.lastAllocatedAddress) {
//         log.print("enumerator::lastValid(end=0x%06X), end of memory\n", address);
         return;
      }

      addressToPageOffset(address, pageNum, offset);

      // Check if at page boundary or probing one ahead fails
      if ((offset == PAGE_SIZE-1) || !memoryPage->isValid(++offset)) {
//         log.print("enumerator::lastValid(end=0x%06X)\n", address);
         return;
      }
     address++;
   } while (1);
}

//! Allocate a memory location in Flash image
//!
//! @param pageNum - 16-bit page address
//!
//! @return\n
//!         true   => success \n
//!         false  => failure
//!
FlashImage::MemoryPage *FlashImage::MemorySpace::allocatePage(uint32_t pageNum) {
   LOGGING_Q;
   MemoryPage *memoryPage;

   memoryPage = getmemoryPage(pageNum);
   if (memoryPage == NULL) {
      log.print( "Allocating page #%2.2X [0x%06X-0x%06X]\n", pageNum, pageOffsetToAddress(pageNum, 0), pageOffsetToAddress(pageNum, PAGE_SIZE-1));
      memoryPage = new MemoryPage;
      memoryPages.insert(pair<const uint32_t, MemoryPage*>(pageNum, memoryPage));
      // Update cache
      lastMemoryPageAccessed = memoryPage;
   }
   return memoryPage;
}

//! Obtain the value of a Flash memory location
//!
//! @param address - 32-bit memory address
//!
//! @return - 8-bit value (dummy value of 0xFF is unallocated address)
//!
uint8_t FlashImage::MemorySpace::getValue(uint32_t address) {
   uint16_t         offset;
   uint16_t         pageNum;
   MemoryPage *memoryPage;
   addressToPageOffset(address, pageNum, offset);
   memoryPage = getmemoryPage(pageNum);
   if (memoryPage == NULL)
      return 0xFF;
   else
      return memoryPage->getValue(offset);
}

//! Set a Flash memory location
//!
//! @param address - 32-bit memory address
//! @param value   - 8-bit value to write to image
//!
//! @note Allocates a memory location if necessary
//!
void FlashImage::MemorySpace::setValue(uint32_t address, uint8_t value) {
   uint16_t offset;
   uint16_t pageNum;

   empty = false;
   addressToPageOffset(address, pageNum, offset);
   MemoryPage *memoryPage = allocatePage(pageNum);
   if (!memoryPage->isValid(offset)) {
      // new location
      byteCount++;
   }
   memoryPage->setValue(offset, value);
   if (firstAllocatedAddress > address)
      firstAllocatedAddress = address;
   if (lastAllocatedAddress < address)
      lastAllocatedAddress = address;
}
