/**
 ================================================================================
 * @file    qspi-example.cpp (180.ARM_Peripherals/Snippets/qspi-example.cpp)
 * @brief   QSPI Controller example for MK28_FRDM
 *
 *  Created on: 20/11/2021
 *      Author: podonoghue
 ================================================================================
 */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "hardware.h"

using namespace USBDM;

#ifdef MCU_MK82F25615
#include "mx25u3235fzni.h"

// Declare flash on Qspi0 - FRDM_K82F
using flash = Mx25u3235fzni;
#endif

#ifdef MCU_MK28F15
#include "mt25qu256aba.h"

// Declare flash on Qspi0 - FRDM_K28F
using flash = Mt25qu256aba;
#endif

void testQspi() {

   // How much of the flash to test
   static constexpr unsigned FLASH_SIZE_TO_TEST = flash::FLASH_SIZE; //flash::FLASH_SIZE; // 10*flash::FLASH_SECTOR_SIZE;

   // Start address for flash test
   static constexpr unsigned FLASH_TEST_START = 0;

   // End address for flash test
   static constexpr unsigned FLASH_TEST_END   = FLASH_TEST_START + FLASH_SIZE_TO_TEST-1;

   console.setWidth(6).setPadding(Padding_LeadingZeroes);
   console.write("Testing Flash[0x").write(FLASH_TEST_START, Radix_16).
         write("..0x").write(FLASH_TEST_END, Radix_16).writeln("]");
   console.resetFormat();

   // rand() is expected to generate the same pseudo-random sequence from the same seed
   const auto seed = time(NULL);
   srand(seed);

   uint32_t flashAddress = FLASH_TEST_START;

   // What size to access the Flash at
   using AccessType = uint32_t;

   // For each sector
   for (unsigned sector = 0; sector<(FLASH_SIZE_TO_TEST/flash::FLASH_SECTOR_SIZE); sector++) {

      console.write("\rProgramming Sector ");
      console.setWidth(6).setPadding(Padding_LeadingZeroes);
      console.write("0x").write(flashAddress, Radix_16);

      // Erase the sector
      flash::eraseSector(flashAddress);

      // For each page in sector
      for (unsigned page = 0; page<(flash::FLASH_SECTOR_SIZE/flash::FLASH_PAGE_SIZE); page++) {

         // Fill Flash page data with random number sequence
         AccessType buffer[flash::FLASH_PAGE_SIZE/sizeof(AccessType)];
         for (size_t index=0; index<(sizeof(buffer)/sizeof(AccessType)); index++) {
            buffer[index] = rand();
         }

         // Program page
         flash::programPage(flashAddress, (uint32_t*)buffer);

         flashAddress += flash::FLASH_PAGE_SIZE;
      }
   }

   // Start again with same seed
   srand(seed);

   console.writeln("\nVerifying");

   // Access flash as memory array
   flash::FlashArrayType<AccessType> flashReadArray;

   unsigned failCount = 0;
   for (unsigned address = FLASH_TEST_START; (address < FLASH_TEST_END/sizeof(AccessType)); address++) {
      AccessType probe     = flashReadArray[address];
      AccessType reference = rand();
      if (reference != probe) {
         failCount++;
         if (failCount>10) {
            console.writeln("Too many error - giving up");
            break;
         }
         console.setPadding(Padding_LeadingZeroes).
               setWidth(7).write("0x").write(address, Radix_16).
               setWidth(7).write("(PA 0x").write(flash::FLASH_START+(sizeof(AccessType)*address), Radix_16).
               setWidth(2*sizeof(AccessType)).
               write("): Read = 0x").write(probe, Radix_16).
               write(", Ref = 0x").write(reference, Radix_16).writeln(" - Failed");
      }
   }
   if (failCount>0) {
      console.writeln("Failed test");
   }
   else {
      console.writeln("Passed test");
   }
}

int main() {
   console.writeln("Configuring QSPI Controller\n");
   flash::initialise();

   console.writeln("\nStarting QSPI testing\n");
   testQspi();

   for(;;) {
      __BKPT();
   }

   return 0;
}
