/*
 ============================================================================
 * main-MKL.c
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "Segment_LCD.h"


// Simple delay - not for real programs!
void delay(void) {
   for(int i=0; i<400000; i++) {
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

      SegLCD_DisplayDecimal(4321);
      SegLCD_SetDPs(0, true);
      delay();

      SegLCD_DisplayDecimal(8765);
      SegLCD_SetDPs(1, true);
      delay();
   }
   return 0;
}
