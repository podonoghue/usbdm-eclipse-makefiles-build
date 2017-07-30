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
using LED   = $(demo.cpp.red.led:GpioA<2, ActiveLow>);

int main() {

   LED::setOutput(PinDriveStrength_High);

   // Enable PIT
   Pit::configure();

   // Check for errors so far
   checkError();

   for(;;) {
      LED::toggle();

      // Delay in ticks using channel 0
      // This is a busy-waiting loop!
//      Pit::delayInTicks(0, ::SystemBusClock/10);
      Pit::delay(0, 100*ms);
   }
}
