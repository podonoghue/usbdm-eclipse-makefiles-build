/*
 ================================================================================
 * @file    spi-2-config-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   C++ demo using SPI interface
 *
 * This example sets up two hardware configurations and switches between them.
 * This has low overhead but is limited by the hardware.
 *   - Two configurations (assuming 2 SPI CTARs)
 *   - These configurations may be used with multiple devices (limited by PCSs)
 *
 *  Created on: 10/1/2023
 *      Author: podonoghue
 =================================================================================
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
 *  - SPI0_PCS1
 */
#include <string.h>
#include "hardware.h"
#include "spi.h"

using namespace USBDM;

static const Spi0::Init configuration {
   {  /* Shared settings            */
      SpiPeripheralSelectPolarity_All_ActiveHigh, // All PCSs active-high
   },
   //                              Speed      Mode        Bit Order           Frame Size
   /* Configuration 0 (CTAR0) */ { 1_MHz, SpiMode_0, SpiBitOrder_MsbFirst, SpiFrameSize_8_bits},
   /* Configuration 1 (CTAR1) */ {10_MHz, SpiMode_0, SpiBitOrder_MsbFirst, SpiFrameSize_12_bits},
};

int main() {
   // Create SPI with above configuration
   Spi0 spi(configuration);

   // Configure two configurations (CTARs) and the idle levels for PCSs
   // Can also change configurations loaded
   //   spi.configure(configuration);

   for(;;) {
      {
         /*
          * Odd transmission
          *
          * Transmit with configuration 0
          * 8-bit transfers @ 1 MHz using PCS0
          */
         static const uint8_t txDataA[] = { 0xA1,0xB2,0xC3,0xD4,0x55, };
         uint8_t rxData1[sizeof(txDataA)/sizeof(txDataA[0])] = {0};
         uint8_t rxData2[sizeof(txDataA)/sizeof(txDataA[0])] = {0};
         uint8_t rxData3 = 0;
         uint8_t rxData4 = 0;

         // Select configuration to use (CTAR & PCS options)
         spi.selectConfiguration(
               SpiCtarSelect_0,                       // Use CTAR0
               SpiPeripheralSelect_0,                 // PCS0 is asserted during transfer
               SpiPeripheralSelectMode_Transaction    // PCSx goes low between transactions
         );

         spi.startTransaction();
         spi.txRx(txDataA, rxData1);          // 5 x 8-bits tx-rx
         spi.txRx(txDataA, rxData2);          // 5 x 8-bits tx-rx
         rxData3 = spi.txRx(txDataA[0]);      // 8-bits tx-rx
         rxData4 = spi.txRxFinal(txDataA[1]); // 8-bits tx-rx + PCSx released
         spi.endTransaction();

         if ((memcmp(txDataA, rxData1, sizeof(txDataA)/sizeof(txDataA[0])) != 0) ||
             (memcmp(txDataA, rxData2, sizeof(txDataA)/sizeof(txDataA[0])) != 0) ||
             (rxData3 != txDataA[0]) ||
             (rxData4 != txDataA[1])) {
            console.writeln("Failed read-back");
            __asm__("bkpt");
         }
      }
      {
         /*
          * Even transmission
          *
          * Transmit with configuration 1
          * 12-bit transfers @ 10 MHz using PCS2
          */
         static const uint16_t txDataB[] = { 0xA01,0xB02,0xC03,0xD04,0x555, };
         uint16_t rxData1[sizeof(txDataB)/sizeof(txDataB[0])] = {0};
         uint16_t rxData2[sizeof(txDataB)/sizeof(txDataB[0])] = {0};
         uint16_t rxData3 = 0;;
         uint16_t rxData4 = 0;

         // Select configuration to use (CTAR & PCS options)
         spi.selectConfiguration(
               SpiCtarSelect_1,                       // Use CTAR1
               SpiPeripheralSelect_1,                 // PCS1 is asserted during transfer
               SpiPeripheralSelectMode_Transfer       // PCSx goes low between transfer
         );

         spi.startTransaction();
         spi.txRx(txDataB, rxData1);          // 5 x 12-bits tx-rx
         spi.txRx(txDataB, rxData2);          // 5 x 12-bits tx-rx
         rxData3 = spi.txRx(txDataB[0]);      // 12-bits tx-rx
         rxData4 = spi.txRxFinal(txDataB[1]); // 12-bits tx-rx + PCSx released
         spi.endTransaction();

         if ((memcmp(txDataB, rxData1, sizeof(txDataB)/sizeof(txDataB[0])) != 0) ||
             (memcmp(txDataB, rxData2, sizeof(txDataB)/sizeof(txDataB[0])) != 0) ||
             (rxData3 != txDataB[0]) ||
             (rxData4 != txDataB[1])) {
            console.writeln("Failed read-back");
            __asm__("bkpt");
         }
      }
      wait(10_ms);
   }

}
