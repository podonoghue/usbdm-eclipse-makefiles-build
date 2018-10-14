/**
 ============================================================================
 * @file  pit-example2.cpp (180.ARM_Peripherals/Snippets/pit-example2-MKL.cpp)
 * @brief Programmable Interrupt Timer (PIT) Example
 ============================================================================
 */
#include "hardware.h"
#include "pit.h"
#include "smc.h"

using namespace USBDM;

/**
 * Programmable Interrupt Timer (PIT) Example
 *
 * Demonstrates PIT call-back or static handler
 *
 * Toggles LEDs
 */
/**
 * This example uses PIT interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->PIT tab.
 * Select irqHandlerChannelX option (Class Method - Software ...)
 */

// Comment out the following line to use static interrupt handlers
#define SET_HANDLERS_PROGRAMMATICALLY

// Connection mapping - change as required
using Led1  = $(demo.cpp.red.led:USBDM::GpioB<18, ActiveLow>);
using Led2  = $(demo.cpp.green.led:USBDM::GpioB<19, ActiveLow>);

using Timer         = Pit;
using TimerChannelA = Timer::Channel<0>;
using TimerChannelB = Timer::Channel<1>;

#ifndef SET_HANDLERS_PROGRAMMATICALLY
/**
 * Example showing how to create custom IRQ handlers for PIT channels by
 * providing an explicit instantiation of the PIT template function for ISR
 */
namespace USBDM {

/*
 * If using a naked handler it must be named exactly as shown
 * MKL version - shared handler for all PIT channels
 *
 * This method avoids the overhead of the indirection through a call-back
 */
template<> void Timer::irqHandler() {

   if (pit().CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      pit().CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
      Led1::toggle();
   }
   if (pit().CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      pit().CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
      Led2::toggle();
   }
}

} // end namespace USBDM
#endif

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
   Led1::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   Led2::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   Timer::configure(PitDebugMode_Stop);

   Timer::enableNvicInterrupts(true, NvicPriority_Normal);

#ifdef SET_HANDLERS_PROGRAMMATICALLY
   // Set handler for channel programmatically
   TimerChannelA::setCallback(flashA);
   TimerChannelB::setCallback(flashB);
#endif

   // Flash 1st LED @ 2Hz
   TimerChannelA::configureInTicks(::SystemBusClock/2, PitChannelIrq_Enable);
   // or
//   TimerChannelA::configure(500*ms, PitChannelIrq_Enable);

   // Flash 2nd LED @ 1Hz
   TimerChannelB::configureInTicks(::SystemBusClock, PitChannelIrq_Enable);
   // or
//   TimerChannelB::configure(1*seconds, PitChannelIrq_Enable);

   // Check for errors so far
   checkError();

   for(;;) {
      // Sleep between interrupts
      Smc::enterWaitMode();
   }
}
