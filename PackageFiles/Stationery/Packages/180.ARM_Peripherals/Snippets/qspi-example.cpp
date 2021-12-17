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
#include "mt25qu256aba.h"

using namespace USBDM;

// Declare flash on Qspi0
using flash = Mt25qu256aba;

void testQspi() {

   // How much of the flash to test
   static constexpr unsigned FLASH_SIZE_TO_TEST = flash::FLASH_SIZE;

   // Offset into flash to start test
   static constexpr unsigned FLASH_START_OFFSET = 0;

   // Start address for flash test
   static constexpr unsigned FLASH_TEST_START = flash::FLASH_START + FLASH_START_OFFSET;

   // End address for flash test
   static constexpr unsigned FLASH_TEST_END   = FLASH_TEST_START + FLASH_SIZE_TO_TEST-1;

   console.setWidth(8).setPadding(Padding_LeadingZeroes);
   console.write("Testing Flash[0x").write(FLASH_TEST_START, Radix_16).
         write("..0x").write(FLASH_TEST_END, Radix_16).writeln("]");
   console.resetFormat();

   // rand() is expected to generate the same pseudo-random sequence from the same seed
   const auto seed = time(NULL);
   srand(seed);

   uint32_t flashAddress = FLASH_TEST_START;

   console.writeln("Programming Location");

   // For each sector
   for (unsigned sector = 0; sector<(FLASH_SIZE_TO_TEST/flash::FLASH_SECTOR_SIZE); sector++) {

      console.write("0x").write(flashAddress, Radix_16).write('\r');

      // Erase the sector
      flash::eraseSector(flashAddress);

      // For each page in sector
      for (unsigned page = 0; page<(flash::FLASH_SECTOR_SIZE/flash::FLASH_PAGE_SIZE); page++) {

         // Fill Flash page data with random number sequence
         uint32_t buffer[flash::FLASH_PAGE_SIZE/sizeof(uint32_t)];
         for (size_t index=0; index<(sizeof(buffer)/sizeof(buffer[0])); index++) {
            buffer[index] = rand();
         }

         // Program page
         flash::programPage(flashAddress, buffer);

         flashAddress += flash::FLASH_PAGE_SIZE;
      }
   }

   // Start again
   srand(seed);

   console.writeln("\nVerifying");

   // What size to access the Flash at when testing
   using AccessType = uint32_t;

   bool failed = false;
   for (AccessType *ptr = (AccessType *) FLASH_TEST_START ;
        ptr<((AccessType *)FLASH_TEST_END);
        ptr++) {
      AccessType probe     = *ptr;
      AccessType reference = rand();
      if (reference != probe) {
         failed = true;
         console.write(ptr).write(": Read = 0x").write(probe, Radix_16).write(", Ref = ").write(reference, Radix_16).writeln(" - Failed");
      }
   }
   if (failed) {
      console.writeln("Failed test");
   }
   else {
      console.writeln("Passed test");
   }
}

int main() {
   console.writeln("Configuring QSPI Controller\n");
   flash::qspiInit();

   console.writeln("\nStarting QSPI testing\n");
   testQspi();

   for(;;) {
      __BKPT();
   }

   return 0;
}
