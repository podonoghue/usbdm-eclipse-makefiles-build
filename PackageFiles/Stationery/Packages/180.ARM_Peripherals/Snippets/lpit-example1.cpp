/**
 ============================================================================
 * @file  lpit-example1.cpp (180.ARM_Peripherals/Snippets/)
 * @brief Low Power Interrupt Timer (LPIT) Example
 * @author   podonoghue
 * Toggles LED using PIT for delay.
 * This example uses busy-waiting so it not a practical solution
============================================================================
 */
#include "hardware.h"
#include "lpit.h"

using namespace USBDM;

// Connection mapping - change as required
// Led is assumed active-low
using Led   = $(demo.cpp.red.led:GpioD<15,ActiveLow>);

using Timer         = Lpit0;
using TimerChannel  = Timer::Channel<0>;

int main() {

   Led::setOutput(PinDriveStrength_High);

   // Enable PIT
   PccInfo::setLpit0ClockSource(PccDiv2Clock_Firc);
   Timer::configure();

   // Check for errors so far
   checkError();

   for(;;) {
      // Delay in ticks using channel 0
      // This is a busy-waiting loop!
      TimerChannel::delay(100*ms);
      //console.writeln("Tick");
      Led::toggle();
   }
}
