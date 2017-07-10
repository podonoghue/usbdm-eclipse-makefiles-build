/**
 * @file pit-example2.cpp (derived from pit-example2-MKL.cpp)
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
using RED_LED   = $(demo.cpp.red.led:USBDM::GpioB<18>);
using GREEN_LED = $(demo.cpp.green.led:USBDM::GpioB<19>);

#ifndef SET_HANDLERS_PROGRAMMATICALLY
/**
 * Example showing how to create custom IRQ handlers for PIT channels
 */
namespace USBDM {

/*
 * If using naked handler it must be named exactly as shown
 * MKL version - shared handler for all PIT channels
 */
template<> void Pit_T<PitInfo>::irqHandler() {
   if (PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
      RED_LED::toggle();
   }
   if (PIT->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
      GREEN_LED::toggle();
   }
}

} // end namespace USBDM
#endif

/*
 * These handlers are set programmatically
 */
void flashRed(void) {
   RED_LED::toggle();
}

void flashGreen(void) {
   GREEN_LED::toggle();
}

int main() {
   RED_LED::setOutput(PinDriveStrength_High);
   GREEN_LED::setOutput(PinDriveStrength_High);

   // Turn off LED initially
   RED_LED::set();
   GREEN_LED::set();

   Pit::configure();

#ifdef SET_HANDLERS_PROGRAMMATICALLY
   // Set handlers programmatically
   Pit::setCallback(0, flashRed);
   Pit::setCallback(1, flashGreen);
#endif

   // Flash RED @ 1Hz
   Pit::configureChannel(0, ::SystemBusClock/2);

   // Flash GREEN @ 0.5Hz
   Pit::configureChannel(1, ::SystemBusClock);

   // Check for errors so far
   checkError();

   for(;;) {
      __asm__("nop");
   }
}
