/**
 * @file pit-example2.cpp (derived from pit-example2-MK.cpp)
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
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

// Comment out the following line to use static interrupt handlers
#define SET_HANDLERS_PROGRAMMATICALLY

// Connection mapping - change as required
using LED1 = $(demo.cpp.red.led:USBDM::GpioA<2, USBDM::ActiveLow>);
using LED2 = $(demo.cpp.green.led:USBDM::GpioC<3, USBDM::ActiveLow>);

#ifndef SET_HANDLERS_PROGRAMMATICALLY
/**
 * Example showing how to create custom IRQ handlers for PIT channels
 */
namespace USBDM {

/*
 * If using naked handler it must be named exactly as shown
 * MK version - individual handler for each PIT channel
 */
template<> void Pit_T<PitInfo>::irq0Handler() {
   // Clear interrupt flag
   PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
   LED1::toggle();
}

template<> void Pit_T<PitInfo>::irq1Handler() {
   // Clear interrupt flag
   PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
   LED2::toggle();
}

} // end namespace USBDM
#endif

/*
 * These handlers are set programmatically
 */
void flashRed(void) {
   LED1::toggle();
}

void flashGreen(void) {
   LED2::toggle();
}

int main() {
   LED1::setOutput(PinDriveStrengthHigh);
   LED2::setOutput(PinDriveStrengthHigh);

   Pit::enable();

#ifdef SET_HANDLERS_PROGRAMMATICALLY
   // Set handlers programmatically
   Pit::setCallback(0, flashRed);
   Pit::setCallback(1, flashGreen);
#endif

   // Flash RED @ 1Hz
   Pit::configureChannel(0, ::SystemBusClock/2);

   // Flash GREEN @ 0.5Hz
   Pit::configureChannel(1, ::SystemBusClock);

   // Enable interrupts on the two channels
   Pit::enableInterrupts(0);
   Pit::enableInterrupts(1);

   // Check for errors so far
   checkError();

   for(;;) {
      __asm__("nop");
   }
}
