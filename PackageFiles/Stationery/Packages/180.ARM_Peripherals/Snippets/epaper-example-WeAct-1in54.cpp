/**
 =========================================================================================================
 * @file    epaper-example-WeAct-1in54.cpp (180.ARM_Peripherals/Snippets/epaper-example-WeAct-1in54.cpp)
 * @brief   EPaper example for 1.54" WeAct Studio Epaper display
 * @author podonoghue
 *  Created on: 5/10/2025
 *
 *  Requires declarations for the following in Configure.usbdmProject
 *
 *  EpdCs       [BLUE]    EPD CS as SPI Peripheral select e.g. PCS0 (D7)
 *  EpdDc       [WHITE]   EPD DC as SPI Peripheral select e.g. PCS2 (A3)
 *  EpdResetPin [ORANGE]  EPD Reset pin as GPIO e.g. GpioB.1 (A4)
 *  EpdBusyPin  [VIOLET]  EPD Busy pin as GPIO e.g. GpioB.0 (A5)
 *
 *  Fixed SPI specific connections
 *  SDA         [YELLOW]  SOUT (D11)
 *  ---         ---       SIN  (D12)
 *  SCL         [GREEN]   SCK  (D13)
 *
 *  Power
 *  GND         [BLACK]
 *  VCC         [RED]
 =========================================================================================================
 */
#include "hardware.h"
#include "EPD_1in54_GDEM0154I61.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

int main() {

   console.writeln("\nStarting");

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

   // EPD interface
   EPD_1in54_GDEM0154I61 epd(spi);


   epd.clearDisplay();

   epd.setFont(font16x32);
   epd.clear(WHITE);
   epd.setColour(BLACK);
   epd.writeln("Hello There");
   epd.writeln("Bye Bye");
   epd.firstPage(Refresh_full);
   waitMS(2000);

   epd.clearDisplay();

   epd.clear(WHITE);
   epd.setColour(BLACK);
   epd.drawRect(0, 0,   199,  50);
   epd.drawRect(0, 150, 199, 199);
   epd.setColour(WHITE);
   epd.setFont(font16x32);
   epd.moveXY(10, 15);
   epd.writeln("Unchanged");
   epd.moveXY(10, 165);
   epd.writeln("Unchanged");

   epd.setColour(BLACK);
   epd.setFont(font16x32);
   epd.moveXY(10, 60);
   epd.writeln("Test #0");
   epd.firstPage(Refresh_partial);
   waitMS(5000);

   for (unsigned test=1; test<20; test++) {
      epd.drawRect(10, 60, 6*font16x32.WIDTH, font16x32.height);
      epd.moveXY(10, 60);
      epd.writeln("Test #", test);
      epd.nextPage();
      waitMS(5000);
   }

   for(;;) {
      __asm__("nop");
   }

   return 0;
}
