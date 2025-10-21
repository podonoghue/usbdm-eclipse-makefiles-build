/******************************************************************************
 * @file   tft-example-ILI9163.cpp (180.ARM_Peripherals/Snippets)
 * @brief  Example for ILI9163 based TFT display
 * @author podonoghue
 *
 *  Created on: 5/10/2025
 *
 *  Requires declarations for the following in Configure.usbdmProject
 *
 *  TftCs       TFT CS as SPI Peripheral select e.g. PCS0 (D7)
 *  TftDc       TFT DC as SPI Peripheral select e.g. PCS2 (A3)
 *  TftResetPin TFT Reset pin as GPIO e.g. GpioB.1 (A4)
 *
 *  Fixed SPI specific connections
 *  SDA         SOUT (D11)
 *  ---         SIN  (D12)
 *  SCL         SCK  (D13)
 *
 *  Power
 *  GND
 *  VCC
 ******************************************************************************/
#include "hardware.h"
#include "tft_ILI9163.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

int main() {

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

   // TFT interface
   TFT_ILI9163<Orientation_Normal, DisplaySize_128x160> tft(spi);

   for(;;) {
      tft.setBackgroundColour(RED);
      tft.clear();

      tft.setColour(BLACK);
      tft.drawOpenRect(tft.WIDTH/4-5, tft.HEIGHT/4-5, 3*tft.WIDTH/4+5, 3*tft.HEIGHT/4+5);
      tft.drawCircle(tft.WIDTH/2, tft.HEIGHT/2, tft.WIDTH/4);

      tft.setColour(WHITE);
      tft.drawLine(0, 0,            tft.WIDTH, tft.HEIGHT);
      tft.drawLine(0, tft.HEIGHT,   tft.WIDTH, 0);
      tft.drawLine( tft.WIDTH/2,    0,         tft.WIDTH/2, tft.HEIGHT);
      tft.drawLine(0, tft.HEIGHT/2, tft.WIDTH, tft.HEIGHT/2);
      tft.drawOpenRect(0, 0, tft.WIDTH-1, tft.HEIGHT-1);
      tft.drawOpenCircle(tft.WIDTH/2, tft.HEIGHT/2, tft.WIDTH/4);

//      tft.drawOpenRect(1, 1, tft.WIDTH, tft.HEIGHT);
//      tft.drawOpenRect(2, 2, tft.WIDTH+1, tft.HEIGHT+1);
//      tft.drawOpenRect(3, 3, tft.WIDTH+2, tft.HEIGHT+2);
      waitMS(2000);

      tft.clear();
      tft.setBackgroundColour(RED);
      tft.setColour(WHITE);
      tft.setFont(font16x32).moveXYRelative(2, 2).writeln("Hello!");
      tft.setFont(font16x24).moveXYRelative(2, 0).writeln("Hello!");
      tft.setFont(font14x20).moveXYRelative(2, 0).writeln("Hello!");
      tft.setFont(font11x16).moveXYRelative(2, 0).writeln("Hello!");
      tft.setFont(font7x12).moveXYRelative(2, 0).writeln("Hello!");
      tft.setFont(font6x8).moveXYRelative(2, 0).writeln("Hello!");
      tft.drawOpenRect(0, 0, tft.WIDTH-1, tft.HEIGHT-1);
      waitMS(2000);

      tft.clear();
      tft.setBackgroundColour(RED);
      tft.setColour(WHITE);
      tft.setFont(font7x12);
      tft.write(
            "Lorem ipsum dolor \n"
            "sit amet, consecte\n"
            "tur adipiscing eli\n"
            "t, sed do eiusmod \n"
            "tempor incididunt \n"
            "ut labore et dolor\n"
            "e magna aliqua. Ut\n"
            " enim ad minim ven\n"
            "iam, quis nostrud \n"
            "exercitation ullam\n"
            "co laboris nisi ut");
      waitMS(2000);

   }
   return 0;
}
