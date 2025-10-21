/*
 ================================================================================
 * @file    spi-N-config-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   C++ demo using SPI interface
 *
 *  This example re-uses a configuration with different device selection.
 *  The devices share the same configuration e.g. speed etc but use different
 *  select signals (PCSx).
 *
 *  Created on: 22/9/2025
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

static const Spi0::Init spiConfig{
   {
   // Common setting that are seldom changed
   SpiModifiedTiming_Normal ,                   // Modified Timing Format - Normal Timing
   SpiDoze_Enabled ,                            // Enables Doze mode (when processor is waiting?) - Suspend in doze
   SpiFreeze_Enabled ,                          // Controls SPI operation while in debug mode - Suspend in debug
   SpiRxOverflowHandling_Overwrite ,            // Handling of Rx Overflow Data - Overwrite existing
   SpiContinuousClock_Disable,                  // Continuous SCK Enable - Clock during transfers only
   SpiPcsActiveLow_Pcs1,                        // Polarity for PCS signals (similar lines may be repeated)
   },
   {
      // Common device settings (Configuration SpiCtarSelect_0 only used)
      10_MHz,  SpiMode_0, SpiBitOrder_MsbFirst, SpiFrameSize_8_bits,
   }
};

int main() {

   // Create SPI with above configuration
   Spi0 spi{spiConfig};

   for(;;) {
      {
         /*
          * Odd transmission
          *
          * Transmit with Odd configuration
          * 8-bit transfers @ 10 MHz using PCS1 (active-high) to select device
          */
         static const uint8_t txData[] = { 0xA1,0xB2,0xC3,0xD4,0xE5, };
         uint8_t rxData[sizeof(txData)/sizeof(txData[0])] = {0};
         uint8_t txData1 = 0xF6;

         // Device is selected by active-low PCS1
         spi.selectConfiguration(SpiCtarSelect_0, SpiPeripheralSelect_Pcs1, SpiPeripheralSelectMode_Transaction);
         spi.startTransaction();
         spi.txRx(txData, rxData, false);  // 5 x 8-bits tx-rx, not last transfer in transaction
         spi.txRxFinal(txData1);           // 8-bits tx, final transfer in transaction
         spi.endTransaction();
      }
      {
         /*
          * Even transmission
          *
          * 8-bit transfers @ 10 MHz using PCS0 (active-low) to select device
          */
         uint8_t txData1 = 0x90;
         static const uint8_t txData[] = { 0xA1,0xB2,0xC3,0xD4,0xE5, 0xF6};
         uint8_t rxData[sizeof(txData)/sizeof(txData[0])] = {0};

         // Device is selected by active-high PCS0
         spi.selectConfiguration(SpiCtarSelect_0, SpiPeripheralSelect_Pcs0, SpiPeripheralSelectMode_Transaction);
         spi.startTransaction();
         spi.txRx(txData1);        // 8-bits tx
         spi.txRx(txData, rxData); // 6 x 8-bits tx-rx
         spi.endTransaction();
      }
      wait(1_ms);
   }

}
