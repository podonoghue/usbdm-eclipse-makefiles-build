/**
 * @file segment-lcd-example.cpp
 */
#include <stdio.h>
#include <stdbool.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "segment_lcd.h"

/**
 * Demonstration of Segment-LCD on FRDM-KL43 and and FRDM-KL46 boards
 *
 * Displays various numbers on LCD
 */

using namespace USBDM;

constexpr int DELAY_VALUE = 500;

int main(void) {

//   printf("Starting\n");

   SegmentLcd::enable();

   for(;;) {
      SegmentLcd::displayHex(0x1234);
      SegmentLcd::setDPs(0, true);
      waitMS(DELAY_VALUE);

      SegmentLcd::displayHex(0x5678);
      SegmentLcd::setDPs(1, true);
      waitMS(DELAY_VALUE);

      SegmentLcd::displayHex(0x9ABC);
      SegmentLcd::setDPs(2, true);
      waitMS(DELAY_VALUE);

      SegmentLcd::displayHex(0xDEF0);
      SegmentLcd::setDPs(3, true);
      waitMS(DELAY_VALUE);

      SegmentLcd::displayError(5);
      waitMS(DELAY_VALUE);

      SegmentLcd::displayDecimal(4321);
      SegmentLcd::setDPs(0, true);
      waitMS(DELAY_VALUE);

      SegmentLcd::displayDecimal(8765);
      SegmentLcd::setDPs(1, true);
      waitMS(DELAY_VALUE);
   }
   return 0;
}
