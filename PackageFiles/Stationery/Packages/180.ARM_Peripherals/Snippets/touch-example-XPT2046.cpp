/******************************************************************************
 * @file   touch-example-XPT2046.cpp (180.ARM_Peripherals/Snippets)
 * @brief  Example for XPT2046 resistive touch interface
 * @author podonoghue
 *
 *  Created on: 5/10/2025
 *
 *  Requires declarations for the following in Configure.usbdmProject
 *
 *  TouchCs     XPT2046 CS as SPI Peripheral select e.g. PCS0 (D7)
 *  TouchIrq    XPT2046 IRQ as GPIO
 *
 *  Fixed SPI specific connections
 *  XPT2046 SIN     MOSI/SOUT - D11
 *  XPT2046 SOUT    MISO/SIN  - D12
 *  XPT2046 SCK     SCK       - D13
 *
 *  Power
 *  GND
 *  VCC
 ******************************************************************************/
#include "hardware.h"
#include "touch_XPT2046.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

static const Spi0::Init spiConfig {
   {
      // Common setting that are seldom changed
      SpiModifiedTiming_Normal ,                   // Modified Timing Format - Normal Timing
      SpiDoze_Enabled ,                            // Enables Doze mode (when processor is waiting?) - Suspend in doze
      SpiFreeze_Enabled ,                          // Controls SPI operation while in debug mode - Suspend in debug
      SpiRxOverflowHandling_Overwrite ,            // Handling of Rx Overflow Data - Overwrite existing
      SpiContinuousClock_Disable,                  // Continuous SCK Enable - Clock during transfers only
      SpiPcsActiveLow_None,                        // Polarity for PCS signals
      SpiPeripheralSelectMode_Transaction          // Negate PCS between Transactions
   },
   { /* CTARs default */ }
};

// Shared SPI to use
Spi0 spi(spiConfig);

int main() {
   static constexpr IntegerFormat decimalFormat(Padding_LeadingSpaces, Width_4, Radix_10);

   console.writeln("\nStarting");

   TouchInterface ti(spi);
   for(;;) {
      unsigned x,y;
      if (ti.checkTouch(x, y)) {
         console.setFormat(decimalFormat);
         console.writeln("X = ", x, ", Y = ", y);
      }
   }
   return 0;
}
