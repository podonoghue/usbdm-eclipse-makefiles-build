/**
 * @file digital-example1.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"

using namespace USBDM;

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
#define RED_LED   gpio_$(demo.cpp.red.led)
#define GREEN_LED gpio_$(demo.cpp.green.led)

int main() {
   RED_LED::setOutput();
   GREEN_LED::setOutput();
   RED_LED::set();
   GREEN_LED::set();
   for(;;) {
      RED_LED::toggle();
      delay();
      RED_LED::toggle();
      delay();
      GREEN_LED::toggle();
      delay();
      GREEN_LED::toggle();
      delay();
   }
}
