/**
 ============================================================================
 * @file  pit-example2.cpp (180.ARM_Peripherals/Snippets/pit-example3-MK.cpp)
 * @brief Programmable Interrupt Timer (PIT) Example
 * @author   podonoghue
============================================================================
 */
#include "hardware.h"
#include "pit.h"

using namespace USBDM;

/**
 * Programmable Interrupt Timer (PIT) Example
 *
 * Demonstrates PIT call-back
 *
 * Toggles LED
 */
/**
 * This example uses PIT interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->PIT tab.
 * Select irqHandlers option (Class Method - Software ...)
 */

// Connection mapping - change as required
using Led = $(demo.cpp.blue.led:GpioA<2, USBDM::ActiveLow>);

using Timer        = Pit;
using TimerChannel = PitChannel<0>;
/*
 * This callback is set programmatically
 */
void flash(void) {
   Led::toggle();
}

int main() {
   Led::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   Timer::configure(PitDebugMode_Stop);

   // Set handler programmatically
   TimerChannel::setCallback(flash);

   // Flash LED @ 1Hz
//   TimerChannel::configureInTicks(::SystemBusClock/2, PitChannelIrq_Enable);
   TimerChannel::configure(0.5 * seconds, PitChannelIrq_Enable);

   TimerChannel::enableNvicInterrupts(true, NvicPriority_Normal);

   // Check for errors so far
   checkError();

   for(;;) {
      // Sleep between interrupts
      __asm__("wfi");
   }
}
