/**
 * @file pit-example2.cpp (derived from pit-example2-MK.cpp)
 */
#include "hardware.h"
#include "pit.h"

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
using LED1 = $(demo.cpp.red.led:USBDM::GpioA<2, USBDM::ActiveLow>);
using LED2 = $(demo.cpp.green.led:USBDM::GpioC<3, USBDM::ActiveLow>);

using Timer         = Pit;
using TimerChannelA = PitChannel<0>;
using TimerChannelB = PitChannel<1>;

#ifndef SET_HANDLERS_PROGRAMMATICALLY
/**
 * Example showing how to create custom IRQ handlers for PIT channels by
 * providing an explicit instantiation of the PIT template function for ISR
 */
namespace USBDM {

/*
 * If using a naked handler it must be named exactly as shown
 * MK version - individual handler for each PIT channel
 *
 * This method avoids the overhead of the indirection through a call-back
 */
template<> void PitBase_T<PitInfo>::irq0Handler() {
   // Clear interrupt flag
   pit->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
   Led1::toggle();
}

template<> void PitBase_T<PitInfo>::irq1Handler() {
   // Clear interrupt flag
   pit->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
   Led2::toggle();
}

} // end namespace USBDM
#endif

/*
 * These handlers are set programmatically
 */
void flashRed(void) {
   Led1::toggle();
}

void flashGreen(void) {
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

   Timer::configure();

#ifdef SET_HANDLERS_PROGRAMMATICALLY
   // Set handlers programmatically
   Timer::setCallback(0, flashRed);
   Timer::setCallback(1, flashGreen);
#endif

   // Flash 1st LED @ 2Hz
   TimerChannelA::configureChannelInTicks(0, ::SystemBusClock/2);
   // or TimerChannelA::configureChannel(0, 500*ms);

   // Flash 2nd LED @ 1Hz
   TimerChannelB::configureChannelInTicks(1, ::SystemBusClock);
   // or TimerChannelB::configureChannel(1, 1*seconds);

   // Enable interrupts on the two channels
   TimerChannelA::enableInterrupts();
   TimerChannelB::enableInterrupts();

   // Check for errors so far
   checkError();

   for(;;) {
      __asm__("nop");
   }
}
