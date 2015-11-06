#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"

/*
 * Simple example flashing LEDs on digital outputs
 */

// Simple delay - not for real programs!
void delay(void) {
   for(int i=0; i<400000; i++) {
      __asm__("nop");
   }
}

// LED connections
#define RED_LED   digitalIO_$(demo.cpp.red.led)
#define GREEN_LED digitalIO_$(demo.cpp.green.led)

int main() {
   RED_LED.setDigitalOutput();
   GREEN_LED.setDigitalOutput();
   RED_LED.set();
   GREEN_LED.set();
   for(;;) {
      RED_LED.toggle();
      delay();
      RED_LED.toggle();
      delay();
      GREEN_LED.toggle();
      delay();
      GREEN_LED.toggle();
      delay();
   }
}
