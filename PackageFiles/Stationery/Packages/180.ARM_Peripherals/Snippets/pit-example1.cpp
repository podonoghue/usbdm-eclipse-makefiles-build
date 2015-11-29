#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "PIT.h"

using namespace USBDM;

/**
 * Programmable Interrupt Timer (PIT) Example
 *
 * Toggles LED use PIT for delay
 */

// LED connections
#define RED_LED   gpio_$(demo.cpp.red.led)

int main() {
   RED_LED.setDigitalOutput();

   // Turn off LED initially
   RED_LED.set();

   PIT_0.configure();

   for(;;) {
      RED_LED.toggle();
      PIT_0.delay(0, SystemBusClock*1);
   }
}
