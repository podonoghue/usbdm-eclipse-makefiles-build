/*
 ============================================================================
 * @file    spi-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using SPI interface
 *
 * This example uses a single configuration.
 *
 *  Created on: 10/6/2017
 *      Author: podonoghue
 ============================================================================
 */
/*
 * This example requires a loop-back between SPI_MOSI and SPI_MISO.
 * It may be necessary to adjust the peripheral selection to an available pin.
 *
 * The SPI signals used must be mapped to pins in Configure.usbdmProject
 *  - SPI0_SCK
 *  - SPI0_SIN
 *  - SPI0_SOUT
 *  - SPI0_PCS0
 */
#include <string.h>
#include "hardware.h"
#include "spi.h"

using namespace USBDM;

// Single configuration
static const SpiConfigurations configurations {
   //                              Speed      Mode        Bit Order           Frame Size
   /* Configuration 0 (CTAR0) */ { 1'000'000, SpiMode_0, SpiOrder_MsbFirst, SpiFrameSize_8},
   /* PCS idle levels         */ 0b000000, // All PCSs idle low
};

int main() {
   Spi0 spi{};

   // Configure SPI
   spi.setConfigurations(configurations);

   // Set configuration to use
   spi.setActiveConfiguration(SpiPeripheralSelect_0, SpiCtarSelect_0);

   for(;;) {
      {
         /*
          * Transmission
          *
          * Transmit with configuration 0
          * 8-bit transfers @ 1 MHz using PCS0
          */
         static const uint8_t txDataA[] = { 0xA1,0xB2,0xC3,0xD4,0x55, };
         uint8_t rxData1[sizeof(txDataA)/sizeof(txDataA[0])] = {0};
         uint8_t rxData2[sizeof(txDataA)/sizeof(txDataA[0])] = {0};
         uint8_t rxData3 = 0;
         uint8_t rxData4 = 0;

         spi.startTransaction();
         spi.txRx(txDataA, rxData1); // 5 bytes tx-rx
         spi.txRx(txDataA, rxData2); // 5 bytes tx-rx
         rxData3 = spi.txRx(txDataA[0]); // 1 byte tx-rx
         rxData4 = spi.txRx(txDataA[1]); // 1 byte tx-rx
         spi.endTransaction();

         if ((memcmp(txDataA, rxData1, sizeof(txDataA)/sizeof(txDataA[0])) != 0) ||
             (memcmp(txDataA, rxData2, sizeof(txDataA)/sizeof(txDataA[0])) != 0) ||
             (rxData3 != txDataA[0]) ||
             (rxData4 != txDataA[1])) {
            console.writeln("Failed read-back");
            __asm__("bkpt");
         }
      }
      wait(10*ms);
   }

}
