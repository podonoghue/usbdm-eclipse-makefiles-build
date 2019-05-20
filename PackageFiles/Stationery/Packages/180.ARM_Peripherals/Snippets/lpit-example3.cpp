/**
 ============================================================================
 * @file  pit-example3.cpp (180.ARM_Peripherals/Snippets/pit-example3-MK.cpp)
 * @brief Programmable Interrupt Timer (PIT) Example
 * @author   podonoghue
============================================================================
 */
#include "hardware.h"
#include "lpit.h"
#include "smc.h"

using namespace USBDM;

/**
 * Programmable Interrupt Timer (LPIT) Example
 *
 * Demonstrates LPIT call-back
 *
 * Toggles LED
 */
/**
 * This example uses PIT interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->LPIT tab.
 * Select irqHandlerChannelX option (Class Method - Software ...)
 */

// Connection mapping - change as required
using Led = $(demo.cpp.blue.led:GpioA<2, ActiveLow>);

using Timer        = Lpit0;
using TimerChannel = Timer::Channel<0>;
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

   PccInfo::setLpit0ClockSource(PccDiv2Clock_Sirc);
   Timer::configure(LpitDozeMode_Run, LpitDebugMode_Stop);

   // Set handler programmatically
   TimerChannel::setCallback(flash);

   // Flash LED @ 1Hz
   TimerChannel::configure(0.5 * seconds, LpitChannelIrq_Enabled);

   TimerChannel::enableNvicInterrupts(NvicPriority_Normal);

   // Check for errors so far
   checkError();

   Smc::enablePowerModes(SmcVeryLowPower_Enabled, SmcHighSpeedRun_Enabled);
   for(;;) {
      // Sleep between interrupts
      Smc::enterStopMode(SmcStopMode_VeryLowPowerStop);
   }
}
