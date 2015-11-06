#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"

/*
 * Simple Digital I/O example
 *
 * Echos an external switch to an external LED
 *
 *  SWITCH + LED
 *  1 x Digital input
 *  1 x Digital output
 *
 */

// Simple delay - not for real programs!
void delay(void) {
   for(int i=0; i<400000; i++) {
      __asm__("nop");
   }
}

// Connection mapping
#define SWITCH    digitalIO_D12
#define LED       digitalIO_D13

int main(void) {
   LED.setDigitalOutput();
   SWITCH.setDigitalInput();

   for(;;) {
      LED.write(!SWITCH.read());
   }
}
