/*
 ===============================================================================
 * @file    spi-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using SPI interface
 *
 * This example uses a single configuration set up when the SPI is instantiated.
 *
 *  Created on: 10/1/2023
 *      Author: podonoghue
 ===============================================================================
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
#include <stdlib.h>
#include <time.h>

#include "hardware.h"
#include "spi.h"

using namespace USBDM;

#define USE_RANDOM_DATA

#ifdef USE_RANDOM_DATA
// 4-bit to 16bit transfers with random data
using DataSize = uint16_t;
static DataSize txDataA[10] = {};
static constexpr SpiFrameSize frameSize = SpiFrameSize_16_bits; // 4-16 (adjust DataSize as needed)
#else
#if 0
// 9-bit to 16-bit transfers with recognisable pattern
using DataSize = uint16_t;
static const DataSize txDataA[] = { 0x1AA1,0x2BB2,0x3CC3,0x4DD4,0xAA55, };
static constexpr SpiFrameSize frameSize = SpiFrameSize_16_bits; // 9-12
#else
// 4-bit to 8bit transfers with recognisable pattern
using DataSize = uint8_t;
static const DataSize txDataA[] = { 0xA1,0xB2,0xC3,0xD4,0x55, };
static constexpr SpiFrameSize frameSize = SpiFrameSize_8_bits; // 4-8
#endif
#endif

// SPI base configuration
static const Spi0::Init baseConfiguration {
   // Shared configuration - not usually modified after initial configuration
   SpiPcsActiveLow_Pcs0,                 // PCS0 active-low, others active-high
   SpiFreeze_Enabled,                    // Freeze in debug
   SpiDoze_Enabled,                      // Doze in sleep

   // These are initial transfer settings.
   // Can be changed using selectConfiguration(...) or startTransaction(...)
   SpiCtarSelect_0,                       // Use CTAR0
   SpiPeripheralSelect_Pcs0,              // PCS1 is asserted during transfer
   SpiPeripheralSelectMode_Transaction,   // PCSx negated between transactions
};

// SPI communication configuration
static const Spi::SerialInit serialInit {
   1_MHz ,                 // Speed of interface
   SpiMode_0 ,             // Mode - Mode 0: CPOL=0, CPHA=0
   frameSize ,             // SPI Frame sizes - 8 bits/transfer
   SpiBitOrder_LsbFirst,   // Transmission order - LSB sent first
};

int main() {

   // Create SPI with above baseConfiguration
   Spi0 spi(baseConfiguration);

   // Set polarity of User PCS
   // Done above
//   spi.setPcsPolarityActiveLow(SpiPeripheralSelect_UserPcs);

   // Calculate communication baseConfiguration
   auto communicationConfiguration = spi.calculateConfiguration(serialInit,
         SpiPeripheralSelect_UserPcs, SpiPeripheralSelectMode_Transaction, SpiCtarSelect_0);

   for(int count=0;;count++) {
      /*
       * Transmission
       *
       * Transmit with configuration
       * Transfers @ 1 MHz using PCS0
       */
      DataSize rxData1[sizeofArray(txDataA)] = {0};
      DataSize rxData2[sizeofArray(txDataA)] = {0};
      DataSize rxData3 = 0;
      DataSize rxData4 = 0;

#ifdef USE_RANDOM_DATA
      unsigned seed = time(nullptr);

      /* Initialise random number generator */
      srand(seed+count);

      for (unsigned index=0; index<sizeofArray(txDataA); index++) {
         // Fill with random data
         txDataA[index] = rand();
      }
#endif

      spi.startTransaction(communicationConfiguration);
      spi.txRx(txDataA, rxData1, false);   // N items tx-rx
      spi.txRx(txDataA, rxData2);          // N items tx-rx
      rxData3 = spi.txRx(txDataA[0]);      // 1 item tx-rx
      rxData4 = spi.txRxFinal(txDataA[1]); // 1 item tx-rx
      spi.endTransaction();

      if ((memcmp(txDataA, rxData1, sizeof(txDataA)/sizeof(txDataA[0])) != 0) ||
            (memcmp(txDataA, rxData2, sizeof(txDataA)/sizeof(txDataA[0])) != 0) ||
            (rxData3 != txDataA[0]) ||
            (rxData4 != txDataA[1])) {
         console.writeln("Failed read-back");
         __asm__("bkpt");
      }
      wait(10_ms);
   }

}
