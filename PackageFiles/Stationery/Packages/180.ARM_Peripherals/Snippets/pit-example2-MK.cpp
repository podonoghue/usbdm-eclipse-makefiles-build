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
 * Demonstrates PIT call-back or handler
 *
 * Toggles LEDs
 */

// Connection mapping - change as required
using RED_LED   = $(demo.cpp.red.led:USBDM::GpioB<0>);
using GREEN_LED = $(demo.cpp.green.led:USBDM::GpioB<1>);

#if PIT_USES_NAKED_HANDLER == 1
/*
 * If using naked handler it must be named exactly as shown
 */
void PIT0_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
   RED_LED::toggle();
}
/*
 * If using naked handler it must be named exactly as shown
 */
void PIT1_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
   GREEN_LED::toggle();
}

/*
 * If using naked handler it must be named exactly as shown
 * MKL version - shared handler for all PIT channels
 */
void PIT_IRQHandler(void) {
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
#else
/*
 * These handlers are set programmatically
 */
void flashRed(void) {
   RED_LED::toggle();
}
void flashGreen(void) {
   GREEN_LED::toggle();
}
#endif

int main() {
   RED_LED::setOutput();
   GREEN_LED::setOutput();

   // Turn off LED initially
   RED_LED::set();
   GREEN_LED::set();

   Pit::configure();

#if PIT_USES_NAKED_HANDLER == 0
   // These handlers are set programmatically
   Pit::setCallback(0, flashRed);
   Pit::setCallback(1, flashGreen);
#endif

   // Flash RED @ 1Hz
   Pit::configureChannel(0, SystemBusClock/2);

   // Flash GREEN @ 0.5Hz
   Pit::configureChannel(1, SystemBusClock);

   for(;;) {
      __asm__("nop");
   }
}
