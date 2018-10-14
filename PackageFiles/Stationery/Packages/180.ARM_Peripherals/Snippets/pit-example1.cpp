/**
 ============================================================================
 * @file  pit-example1.cpp (180.ARM_Peripherals/Snippets/)
 * @brief Programmable Interrupt Timer (PIT) Example
 * @author   podonoghue
 * Toggles LED use PIT for delay.
 * This example uses busy-waiting so it not a practical solution
============================================================================
 */
#include "hardware.h"
#include "pit.h"

using namespace USBDM;

// Connection mapping - change as required
// Led is assumed active-low
using LED   = $(demo.cpp.red.led:GpioA<2, ActiveLow>);

using TimerChannel = Pit::Channel<0>;

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
//      TimerChannel::delayInTicks(::SystemBusClock/10);
      TimerChannel::delay(100*ms);
   }
}
