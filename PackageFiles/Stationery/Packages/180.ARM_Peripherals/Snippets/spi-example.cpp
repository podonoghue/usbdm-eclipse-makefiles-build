/*
 ============================================================================
 * @file    spi-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using SPI interface
 *
 *  Created on: 10/6/2017
 *      Author: podonoghue
 ============================================================================
 */
/*
 * This example requires a loop-back between SPI_MOSI and SPI_MISO.
 * It may be necessary to adjust the peripheral selection to an available pin.
 */
#include <string.h>
#include "spi.h"

using namespace USBDM;

int main() {
   Spi0 spi{};


   spi.startTransaction();

   // Configure SPI
   spi.setSpeed(10*MHz);
   spi.setMode(SpiMode_0);
   spi.setPeripheralSelect(SpiPeripheralSelect_0, ActiveLow, SpiSelectMode_Idle);
   spi.setFrameSize(8);

   // Save configuration
   SpiConfig configuration1 = spi.getConfiguration();

   // Configure SPI
   spi.setSpeed(24.0*MHz);
   spi.setMode(SpiMode_0);
   spi.setPeripheralSelect(SpiPeripheralSelect_2, ActiveLow, SpiSelectMode_Idle);
   spi.setFrameSize(12);

   // Save configuration
   SpiConfig configuration2 = spi.getConfiguration();

   spi.endTransaction();

   for(;;) {
      {
         /*
          * Transmit with configuration 1
          * 8-bit transfers @ 10 MHz
          */
         static const uint8_t txDataA[] = { 0xA1,0xB2,0xC3,0xD4,0xE5, };
         uint8_t rxData1[sizeof(txDataA)/sizeof(txDataA[0])] = {0};
         uint8_t rxData2[sizeof(txDataA)/sizeof(txDataA[0])] = {0};
         uint8_t rxData3;
         uint8_t rxData4;

         spi.startTransaction(configuration1);
         spi.txRx(sizeof(txDataA)/sizeof(txDataA[0]), txDataA, rxData1);
         spi.txRx(sizeof(txDataA)/sizeof(txDataA[0]), txDataA, rxData2);
         rxData3 = spi.txRx(txDataA[0]);
         rxData4 = spi.txRx(txDataA[1]);
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
          * Transmit with configuration 1
          * 12-bit transfers @ 24 MHz
          */
         static const uint16_t txDataB[] = { 0xA01,0xB02,0xC03,0xD04,0xE05, };
         uint16_t rxData1[sizeof(txDataB)/sizeof(txDataB[0])] = {0};
         uint16_t rxData2[sizeof(txDataB)/sizeof(txDataB[0])] = {0};
         uint16_t rxData3;
         uint16_t rxData4;

         spi.startTransaction(configuration2);
         spi.txRx(sizeof(txDataB)/sizeof(txDataB[0]), txDataB, rxData1);
         spi.txRx(sizeof(txDataB)/sizeof(txDataB[0]), txDataB, rxData2);
         rxData3 = spi.txRx(txDataB[0]);
         rxData4 = spi.txRx(txDataB[1]);
         spi.endTransaction();

         if ((memcmp(txDataB, rxData1, sizeof(txDataB)/sizeof(txDataB[0])) != 0) ||
             (memcmp(txDataB, rxData2, sizeof(txDataB)/sizeof(txDataB[0])) != 0) ||
             (rxData3 != txDataB[0]) ||
             (rxData4 != txDataB[1])) {
            console.writeln("Failed read-back");
            __asm__("bkpt");
         }
      }
      wait(10*ms);
   }

}


