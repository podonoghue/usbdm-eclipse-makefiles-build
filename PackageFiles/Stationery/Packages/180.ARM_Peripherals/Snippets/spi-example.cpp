/*
 ============================================================================
 * @file    spi-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using SPI interface
 *
 *  Created on: 10/6/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "spi.h"

using namespace USBDM;

int main() {
   Spi1 spi{};

   // Configure SPI
   spi.setSpeed(1.0*MHz);
   spi.setMode(SpiMode_0);
   spi.setPeripheralSelect(SpiPeripheralSelect_0, ActiveLow, SpiSelectMode_Idle);
   spi.setFrameSize(8);

   // Save configuration
   SpiConfig configuration1 = spi.getConfig();

   // Configure SPI
   spi.setSpeed(10.0*MHz);
   spi.setMode(SpiMode_0);
   spi.setPeripheralSelect(SpiPeripheralSelect_1, ActiveLow, SpiSelectMode_Idle);
   spi.setFrameSize(12);

   // Save configuration
   SpiConfig configuration2 = spi.getConfig();

   for(;;) {
      {
         /*
          * Transmit with configuration 1
          * 8-bit transfers @ 1 MHz
          */
         static const uint8_t txData[] = { 0xA1,0xB2,0xC3,0xD4, };
         uint8_t rxData[4] = {};

         spi.startTransaction(configuration1);
         spi.txRx(sizeof(txData)/sizeof(txData[0]), txData, rxData);
         spi.txRx(sizeof(txData)/sizeof(txData[0]), txData, rxData);
         spi.txRx(0x12);
         spi.txRx(0x12);
         spi.endTransaction();
      }
      {
         /*
          * Transmit with configuration 1
          * 12-bit transfers @ 10 MHz
          */
         static const uint16_t txData[] = { 0xA01,0xB02,0xC03,0xD04, };
         uint16_t rxData[4] = {};
         spi.startTransaction(configuration2);
         spi.txRx(sizeof(txData)/sizeof(txData[0]), txData, rxData);
         spi.txRx(sizeof(txData)/sizeof(txData[0]), txData, rxData);
         spi.txRx(0x123);
         spi.txRx(0x123);
         spi.endTransaction();
      }
   }

}


