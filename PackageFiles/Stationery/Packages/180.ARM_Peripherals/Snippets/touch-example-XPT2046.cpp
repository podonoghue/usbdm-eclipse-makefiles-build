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
 *  --------------------------------
 *  XPT2046 CS      PCS0      - D7   (example)
 *  XPT2046 SIN     MOSI/SOUT - D11
 *  XPT2046 SOUT    MISO/SIN  - D12
 *  XPT2046 SCK     SCK       - D13
 *  XPT2046 IRQ     GPIO      - A5   (example)
 *  Power
 *  ------
 *  GND
 *  VCC
 ******************************************************************************/
#include "hardware.h"
#include "touch_XPT2046.h"
#include "smc.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

using TouchInterface = Touch_XPT2046<320, 480>;

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
TouchInterface ti(spi);

void testTouch() {
   static constexpr IntegerFormat decimalFormat(Padding_LeadingSpaces, Width_4, Radix_10);
   for(;;) {
      unsigned x,y;
      if (ti.checkTouch(x, y)) {
         console.setFormat(decimalFormat);
         console.writeln("X = ", x, ", Y = ", y);
      }
   }
}

static volatile bool wakeUp = false;

void touchHandler() {
   console.writeln("Touch Irq");
   ti.disableTouchInterrupt();
   wakeUp = true;
}

void testTouchWakeup() {

   DebugLed::setOutput();
   ti.setInterruptHandler(touchHandler);
   static constexpr IntegerFormat decimalFormat(Padding_LeadingSpaces, Width_4, Radix_10);

   for(;;) {
      DebugLed::off();
      ti.enableTouchInterrupt();
      console.writeln("Entering low power mode...");
      Smc::enterWaitMode();
      if (!wakeUp) {
         console.writeln("False Alarm");
         continue;
      }
      DebugLed::on();
      console.writeln("Awake!...");
      waitMS(200);
   }
}

int main() {

   console.writeln("\nStarting");
//   testTouch();
   testTouchWakeup();

   return 0;
}
