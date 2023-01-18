/*
 ================================================================================
 * @file    spi-N-config-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   C++ demo using SPI interface
 *
 *  This example re-uses configuration 0 with different calculated configurations
 *  This approach is useful if more configuration are needed that the number
 *  supported by the hardware (usually 2 CTARs).
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

// Configurations to use
// These are converted to calculated configurations to reduce overhead
static const Spi0::SerialInit configuration1{ 1_MHz,  SpiMode_0, SpiBitOrder_MsbFirst, SpiFrameSize_8_bits};
static const Spi0::SerialInit configuration2{ 10_MHz, SpiMode_0, SpiBitOrder_MsbFirst, SpiFrameSize_12_bits};

int main() {
   Spi0 spi{};

   // Configure SPI parameters for odd transmissions

   // This method is time consuming as it calculates several derived parameters
   spi.setConfiguration(configuration1);

   // Peripheral settings to use with above configuration
   spi.selectConfiguration(SpiCtarSelect_0, SpiPeripheralSelect_0, SpiPeripheralSelectMode_Transaction);

   // Save the derived configuration
   SpiCalculatedConfiguration configurationOdd = spi.getConfiguration();

   // Configure SPI parameters for even transmissions

   // This method is time consuming as it calculates several derived parameters
   spi.setConfiguration(configuration2);

   // Peripheral settings to use with above configuration
   spi.selectConfiguration(SpiCtarSelect_0, SpiPeripheralSelect_1, SpiPeripheralSelectMode_Transfer);

   // Save the derived configuration
   SpiCalculatedConfiguration configurationEven = spi.getConfiguration();

   for(;;) {
      {
         /*
          * Odd transmission
          *
          * Transmit with Odd configuration
          * 8-bit transfers @ 1 MHz using PCS0
          */
         static const uint8_t txDataA[] = { 0xA1,0xB2,0xC3,0xD4,0x55, };
         uint8_t rxData1[sizeof(txDataA)/sizeof(txDataA[0])] = {0};
         uint8_t rxData2[sizeof(txDataA)/sizeof(txDataA[0])] = {0};
         uint8_t rxData3 = 0;
         uint8_t rxData4 = 0;

         spi.startTransaction(configurationOdd);
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
          * Transmit with Even configuration
          * 12-bit transfers @ 10 MHz using PCS2
          */
         static const uint16_t txDataB[] = { 0xA01,0xB02,0xC03,0xD04,0x555, };
         uint16_t rxData1[sizeof(txDataB)/sizeof(txDataB[0])] = {0};
         uint16_t rxData2[sizeof(txDataB)/sizeof(txDataB[0])] = {0};
         uint16_t rxData3 = 0;;
         uint16_t rxData4 = 0;

         spi.startTransaction(configurationEven);
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
