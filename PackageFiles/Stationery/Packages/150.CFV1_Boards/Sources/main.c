/*
 ============================================================================
 * main.c
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "utilities.h"
#include "leds.h"

// Simple delay - not for real programs!
void delay(void) {
   volatile unsigned long i;
   for (i=400000; i>0; i--) {
      __asm__("nop");
   }
}

/* Example use of interrupt handler
 *
 * See vectors.c for interrupt names
 */
__attribute__((__interrupt__))
void AccessError_Handler(void) {
   for(;;) {
      __breakpoint();
   }
}

int main(void) {

   volatile int count = 0;

   // Generate Access error (interrupt handler demonstration)
   // (*(unsigned int *) 101) = 100;
   
   led_initialise();

//   printf("SystemBusClock  = %ld\n", SystemBusClock);
//   printf("SystemCoreClock = %ld\n", SystemCoreClock);

   // Real programs never die!
   for(;;) {
      count++;
      greenLedToggle();
      delay();
   }
   return 0;
}
