/**
 * @file pit-example1.cpp
 *
 * Programmable Interrupt Timer (PIT) Example
 *
 * Toggles LED use PIT for delay.
 * This example uses busy-waiting so it not a practical solution
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "pit.h"

using namespace USBDM;

// Connection mapping - change as required
// Led is assumed active-low
using LED   = $(demo.cpp.red.led:GpioB<0>);

int main() {

   LED::setOutput(PinDriveStrengthHigh);

   // Enable PIT
   Pit::enable();

   // Check for errors so far
   checkError();

   for(;;) {
      LED::toggle();

      // Delay in ticks using channel 0
      // This is a busy-waiting loop!
//      Pit::delay(0, ::SystemBusClock/10);
      Pit::delay(0, 1000*ms);
   }
}
