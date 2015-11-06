#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "PIT.h"

/**
 * Programmable Interrupt Timer (PIT) Example
 *
 * Demonstrates PIT call-back or handler
 *
 * Toggles LEDs
 */

// LED connections
#define RED_LED   digitalIO_$(demo.cpp.red.led)
#define GREEN_LED digitalIO_$(demo.cpp.green.led)

#if PIT_USES_NAKED_HANDLER == 1
/*
 * If using naked handler it must be named exactly as shown
 * MKM version - shared handler for all PITs and PIT channels
 */
void PIT0_1_IRQHandler(void) {
   if (PIT0->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      PIT0->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
      RED_LED.toggle();
   }
   if (PIT0->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      PIT0->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
      GREEN_LED.toggle();
   }
}
#else
/*
 * These handlers are set programmatically
 */
void flashRed(void) {
   RED_LED.toggle();
}
void flashGreen(void) {
   GREEN_LED.toggle();
}
#endif

int main() {
   RED_LED.setDigitalOutput();
   GREEN_LED.setDigitalOutput();

   // Turn off LED initially
   RED_LED.set();
   GREEN_LED.set();

   PIT_0.configure();

#if PIT_USES_NAKED_HANDLER == 0
   PIT_0.setCallback(0, flashGreen);
   PIT_0.setCallback(1, flashRed);
#endif

   // Flash RED @ 1Hz
   PIT_0.configureChannel(0, SystemBusClock/2);

   // Flash GREEN @ 0.5Hz
   PIT_0.configureChannel(1, SystemBusClock);

   for(;;) {
      __asm__("nop");
   }
}
