/*
 ============================================================================
 Description : Basic C Main
 ============================================================================
 */
#include "derivative.h"
#include "utilities.h"
#include "leds.h"

volatile int count = 0;

/*
 * Example use of interrupt handler
 *
 * See vectors.c for interrupt names
 */
__attribute__((__interrupt__))
void AccessError_Handler(void) {
   for(;;) {
      __breakpoint();
   }
}

void delay(void) {
   for(int i=0; i<50000; i++) {
      __asm__("nop");
   }
}

int main(void) {

   led_initialise();
   // Real programs never die!
   for(;;) {
      greenLedToggle();
      greenLed2Toggle();
      redLedToggle();
      yellowLedToggle();
      delay();
   }
}
