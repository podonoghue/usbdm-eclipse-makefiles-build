 /**
 ============================================================================
 * @file    flash_programming_example.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo of Flash programming interface
 *
 * This example erases and then programs a range of flash memory located in the data flash area.
 *
 * @note Alignment requirements
 * - The minimum erase element for the flash is a sector (usually 1, 2 or 4 K bytes).\n
 *   This requires erasing to be done on a sector boundary and be a multiple of the sector size.
 * - The minimum program element size is a phrase (usually 4 or 8 bytes).\n
 *   This requires programming to be done on a phrase boundary and be a multiple of the phrase size.
 *
 *  Created on: 17/4/2017
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "flash.h"

using namespace USBDM;

/** Data to be programmed to flash */
static uint8_t data[USBDM::Flash::programFlashSectorSize] = {};

/** Array located in data flash that will be programmed */
__attribute__ ((section(".flexNVM"), aligned(USBDM::Flash::programFlashSectorSize)))
static uint8_t copy[sizeof(data)];

/**
 * Print a range of memory as a hex table
 *
 * @param address Address to start at
 * @param size    Number bytes to print
 */
void printDump(uint8_t *address, uint32_t size) {
   printf("          0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n\r");
   bool needNewline = true;
   for (uint index=0; index<size; index++) {
      if (needNewline) {
         printf("%08X ", (int)address+index);
      }
      printf("%02X ", address[index]);
      needNewline = ((index%16)==15);
      if (needNewline) {
         printf("\n\r");
      }
   }
   printf("\n\r");
}

/**
 * Flash programming example
 */
int main(void) {
   printf("Starting\n\r");
   static_assert(((sizeof(copy)&(Flash::dataFlashSectorSize-1)) == 0), "Data must be correct size");
   assert((((unsigned)copy&(Flash::dataFlashSectorSize-1)) == 0));

   // Report original flash contents
   printf("Flash before programming\n\r");
   printDump(copy, sizeof(copy));

   // Erase array located in flash
   FlashDriverError_t rc = Flash::eraseRange(copy, sizeof(copy));
   if (rc != USBDM::FLASH_ERR_OK) {
      printf("Flash erasing failed\n\r");
      __BKPT();
   }

   // Report programmed flash contents
   printf("Flash after erasing\n\r");
   printDump(copy, sizeof(copy));

   // Verify programmed data
   for (uint index=0; index<sizeof(copy); index++) {
      if (copy[index] != 0xFF) {
         printf("Flash failed erase @%p: (data[%3d],0x%02X) != 0xFF\n\r",
               &copy[index], index, copy[index]);
         printf("Verify of flash erasing failed\n\r");
         __BKPT();
      }
   }

   // Fill source with random data
   for (uint index=0; index<sizeof(data); index++) {
      data[index] = rand()%256;
   }

   // Program data to array located in flash
   rc = Flash::programRange(data, copy, sizeof(data));
   if (rc != USBDM::FLASH_ERR_OK) {
      printf("Flash programming failed\n\r");
      __BKPT();
   }

   // Report programmed flash contents
   printf("Flash after programming\n\r");
   printDump(copy, sizeof(copy));

   // Verify programmed data
   for (uint index=0; index<sizeof(data); index++) {
      if (data[index] != copy[index]) {
         printf("Flash failed verify @%p: (data[%3d],0x%02X) != (copy[%3d],0x%02X)\n\r",
               &copy[index], index, data[index], index, copy[index]);
         printf("Verify of flash programming failed\n\r");
         __BKPT();
      }
   }

   for(;;) {

   }
}
