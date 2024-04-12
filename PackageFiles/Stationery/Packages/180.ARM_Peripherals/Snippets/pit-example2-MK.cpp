/**
 ============================================================================
 * @file  pit-example2.cpp (180.ARM_Peripherals/Snippets/pit-example2-MK.cpp)
 * @brief Programmable Interrupt Timer (PIT) Example
 *
 * Demonstrates PIT call-back or static handler
 *
 * @author   podonoghue
============================================================================
 */
#include "hardware.h"
#include "pit.h"
#include "smc.h"

using namespace USBDM;

/**
 * This example uses PIT interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->PIT tab.
 * Select irqHandlingMethod option (Software (Use setCallback() or override class method)
 */

// Comment out the following line to use static interrupt handlers
#define SET_HANDLERS_PROGRAMMATICALLY

// Connection mapping - change as required
using Led1 = RGB_Blue;
using Led2 = RGB_Green;

using Timer         = Pit;
using TimerChannelA = Timer::Channel<0>;
using TimerChannelB = Timer::Channel<1>;

/*
 * These callbacks are set programmatically
 */
void flashA(void) {
   Led1::toggle();
}

void flashB(void) {
   Led2::toggle();
}

int main() {
   static constexpr PcrInit ledSettings {
      PinDriveStrength_High,
      PinDriveMode_PushPull,
      PinSlewRate_Slow
   };
   Led1::setOutput(ledSettings);
   Led2::setOutput(ledSettings);

   Timer::defaultConfigure();

   // Set handler for channel programmatically
   TimerChannelA::setCallback(flashA);
   TimerChannelB::setCallback(flashB);

   // Number of PIT ticks per second
   const Ticks ticksPerSecond = Pit::convertSecondsToTicks(1_s);

   // Flash 1st LED @ 2Hz
   TimerChannelA::configure(Ticks(ticksPerSecond/2U), PitChannelAction_Interrupt); // Configured in 'ticks'
   // or
//   TimerChannelA::configure(500_ms, PitChannelAction_Interrupt); // Configured in 'seconds'

   // Flash 2nd LED @ 1Hz
   TimerChannelB::configure(ticksPerSecond, PitChannelAction_Interrupt); // Configured in 'ticks'
   // or
//   TimerChannelB::configure(1_s, PitChannelAction_Interrupt); // Configured in 'seconds'

   TimerChannelA::enableNvicInterrupts(NvicPriority_Normal);
   TimerChannelB::enableNvicInterrupts(NvicPriority_Normal);

   // Check for errors so far
   checkError();

   for(;;) {
      // Sleep between interrupts
      Smc::enterWaitMode();
   }
}
