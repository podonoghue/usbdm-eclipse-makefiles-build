/**
 ============================================================================
 * @file  lpit-example2.cpp (180.ARM_Peripherals/Snippets/lpit-example2.cpp)
 * @brief Low Power Interrupt Timer (LPIT) Example
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
 * Demonstrates LPIT call-back or static handler
 *
 * Toggles LEDs
 */
/**
 * This example uses LPIT interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->LPIT tab.
 * Select irqHandlerChannelX option (Class Method - Software ...)
 */

// Comment out the following line to use static interrupt handlers
#define SET_HANDLERS_PROGRAMMATICALLY

// Connection mapping - change as required
using Led1 = $(demo.cpp.blue.led:GpioA<2, ActiveLow>);
using Led2 = $(demo.cpp.red.led:GpioC<3, ActiveLow>);

using Timer         = Lpit0;
using TimerChannelA = Timer::Channel<0>;
using TimerChannelB = Timer::Channel<1>;

#ifndef SET_HANDLERS_PROGRAMMATICALLY
/**
 * Example showing how to create custom IRQ handlers for LPIT channels by
 * providing an explicit instantiation of the LPIT template function for ISR
 */
namespace USBDM {

/*
 * If using a naked handler it must be named exactly as shown
 * S32 version - individual handler for each LPIT channel
 *
 * This method avoids the overhead of the indirection through a call-back
 */
template<> template<> void TimerChannelA::irqHandler() {
   // Clear interrupt flag
   lpit().MSR = CHANNEL_MASK;
   Led1::toggle();
}

template<> template<> void TimerChannelB::irqHandler() {
   // Clear interrupt flag
   lpit().MSR = CHANNEL_MASK;
   Led2::toggle();
}

} // end namespace USBDM

#else
/*
 * These callbacks are set programmatically
 */
static void flashA(void) {
   Led1::toggle();
}

static void flashB(void) {
   Led2::toggle();
}
#endif

int main() {
   Led1::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   Led2::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   PccInfo::setLpit0ClockSource(PccDiv2Clock_Sirc);
   Timer::configure(LpitDozeMode_Run, LpitDebugMode_Stop);

#ifdef SET_HANDLERS_PROGRAMMATICALLY
   // Set handler for channel programmatically
   TimerChannelA::setCallback(flashA);
   TimerChannelB::setCallback(flashB);
#endif

   // Flash 1st LED @ 2Hz
   TimerChannelA::configure(500*ms, LpitChannelIrq_Enabled);

   // Flash 2nd LED @ 1Hz
   TimerChannelB::configure(1*seconds, LpitChannelIrq_Enabled);

   TimerChannelA::enableNvicInterrupts(NvicPriority_Normal);
   TimerChannelB::enableNvicInterrupts(NvicPriority_Normal);

   // Check for errors so far
   checkError();

   Smc::enablePowerModes(SmcVeryLowPower_Enabled, SmcHighSpeedRun_Enabled);
   for(;;) {
      // Sleep between interrupts
      Smc::enterStopMode(SmcStopMode_VeryLowPowerStop);
   }
}
