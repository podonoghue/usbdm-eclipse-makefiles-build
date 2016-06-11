/**
 * @file pit-example1.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "pit.h"

using namespace USBDM;

/**
 * Programmable Interrupt Timer (PIT) Example
 *
 * Toggles LED use PIT for delay
 */

// Connection mapping - change as required
using RED_LED   = $(demo.cpp.red.led:USBDM::GpioB<0>);

int main() {
   RED_LED::setOutput();

   // Turn off LED initially
   RED_LED::set();

   Pit::configure();

   for(;;) {
      RED_LED::toggle();
      Pit::delay(0, ::SystemBusClock*1);
   }
}
