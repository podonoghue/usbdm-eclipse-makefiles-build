/**
 ============================================================================
 * @file    spi-flash-example (180.ARM_Peripherals/Snippets/spi-flash-example)
 * @brief   Demo for SPI flash
 *
 *  Created on: 15/8/2022
 *      Author: podonoghue
 ============================================================================
 */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <memory.h>

#include "at45db041e.h"
#include "hardware.h"

using namespace USBDM;

int main() {

   // SPI interface to use
   SpiFlash spiFlash;

   // Flash interface
   FlashInterface flashInterface{spiFlash, Spi0::Pcs_FlashCS};

   while(!flashInterface.initialise()) {
      console.writeln("Failed initialise()");
   }

   uint8_t data[256];

   /**
    * Flash RAM buffer write-read test
    */
   // Fill buffer with random number sequence
   const auto seed1 = time(NULL);
   srand(seed1);
   for (size_t index=0; index<sizeofArray(data); index++) {
      data[index] = (uint8_t)rand();
   }
   console.writeln("Test Buffer for RAM write");
   console.writeArray(data, sizeof(data), 0);

   // Write to RAM buffer
   flashInterface.writeDataBuffer(data);

   // Read-back and verify against same random number sequence
   memset(data, 0, sizeof(data));
   flashInterface.readDataBuffer(data);

   console.writeln("Test Buffer from RAM read");
   console.writeArray(data, sizeof(data), 0);

   bool failed = false;
   srand(seed1);
   for (size_t index=0; index<sizeofArray(data); index++) {
      uint8_t probe     = data[index];
      uint8_t reference = rand();
      if (reference != probe) {
         failed = true;
         console.write(index).write(": Read = 0x").write(probe, Radix_16).write(", Ref = 0x").write(reference, Radix_16).writeln("Failed");
      }
   }
   if (!failed) {
      console.writeln("RAM write-read test passed\n");
   }

   // So seed1 != seed2
   wait(1_s);

   /**
    * Flash buffer write-read test
    */
   // Fill buffer with random number sequence
   const auto seed2 = time(NULL);
   srand(seed2);
   for (size_t index=0; index<sizeofArray(data); index++) {
      data[index] = (uint8_t)rand();
   }
   console.writeln("Test Buffer for Flash write");
   console.writeArray(data, sizeof(data), 0);

   // Choose a ~random block address
   const uint32_t flashAddress = ((data[0]<<16)|(data[1]<<8)|data[2])&((1<<19)-1)&~0xFF;

   // Write to Flash
   flashInterface.writePage(data, flashAddress);

   // Read-back and verify against same random number sequence
   memset(data, 0, sizeof(data));
   flashInterface.readPage(data, flashAddress);

   console.writeln("Test Buffer from Flash read");
   console.writeArray(data, sizeof(data), 0);

   failed = false;
   srand(seed2);
   for (size_t index=0; index<sizeofArray(data); index++) {
      uint8_t probe     = data[index];
      uint8_t reference = rand();
      if (reference != probe) {
         failed = true;
         console.write(index).write(": Read = 0x").write(probe, Radix_16).write(", Ref = 0x").write(reference, Radix_16).writeln(" - Failed");
      }
   }
   if (!failed) {
      console.writeln("Flash write-read passed\n");
   }

   /*
    * Erase check
    */
   console.writeln("Chip erase result = ", flashInterface.eraseChip()?"OK\n":"Failed\n");

   // Read back page programmed earlier
   flashInterface.readPage(data, flashAddress);

   console.writeln("Test Buffer from Flash read after erase");
   console.writeArray(data, sizeof(data), 0);

   for (size_t index=0; index<sizeofArray(data); index++) {
      uint8_t probe     = data[index];
      uint8_t reference = 0xFF;
      if (reference != probe) {
         failed = true;
         console.write(index).write(": Read = 0x").write(probe, Radix_16).write(", Ref = 0x").write(reference, Radix_16).writeln(" - Failed");
      }
   }
   if (!failed) {
      console.writeln("Page blank check passed");
   }

   for(;;) {
      __asm__("nop");
   }

   return 0;
}
