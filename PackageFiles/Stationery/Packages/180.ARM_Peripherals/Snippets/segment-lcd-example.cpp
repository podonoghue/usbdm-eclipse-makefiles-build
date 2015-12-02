/**
 * @file segment-lcd-example.cpp
 */
#include <stdio.h>
#include <stdbool.h>
#include "system.h"
#include "derivative.h"
#include "segment_lcd.h"

using namespace USBDM;

/**
 * Demonstration of Segment-LCD on FRDM-KL43 and and FRDM-KL46 boards
 *
 * Displays various numbers on LCD
 */

// Simple delay - not for real programs!
void delay(void) {
   for(int i=0; i<4000000; i++) {
      __asm__("nop");
   }
}

int main(void) {

   SegLCD_Init();

   for(;;) {
      SegLCD_DisplayHex(0x1234);
      SegLCD_SetDPs(0, true);
      delay();

      SegLCD_DisplayHex(0x5678);
      SegLCD_SetDPs(1, true);
      delay();

      SegLCD_DisplayHex(0x9ABC);
      SegLCD_SetDPs(2, true);
      delay();

      SegLCD_DisplayHex(0xDEF0);
      SegLCD_SetDPs(3, true);
      delay();

      SegLCD_DisplayError(5);
      delay();

      SegLCD_DisplayDecimal(4321);
      SegLCD_SetDPs(0, true);
      delay();

      SegLCD_DisplayDecimal(8765);
      SegLCD_SetDPs(1, true);
      delay();
   }
   return 0;
}
