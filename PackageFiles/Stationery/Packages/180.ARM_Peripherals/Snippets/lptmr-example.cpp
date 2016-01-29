/**
 * @file lptmr-example.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "lptmr.h"

using namespace USBDM;

/*
 * Low power timer (LPTMR) example
 *
 * Demonstrates use of timer call-back
 */

// Connection mapping - change as required
using RED_LED   = $(demo.cpp.red.led:USBDM::GpioB<0>);

#if LPTMR_USES_NAKED_HANDLER == 1
/*
 * If using naked handler it must be named exactly as shown
 */
void LPTMR0_IRQHandler(void) {
   // Clear interrupt flag
   LPTMR0->CSR |= LPTMR_CSR_TCF_MASK;
   RED_LED::toggle();
}
#else
/*
 * This handler is set programmatically
 */
void flash(void) {
   RED_LED::toggle();
}
#endif

int main() {
   RED_LED::setOutput();

   // May need to change prescaler to get useful delays
   LPTMR_0.configure(1000, LPTMR_CSR_DEFAULT_VALUE|LPTMR_CSR_TIE_MASK);
   
#if LPTMR_USES_NAKED_HANDLER == 0
   // This handler is set programmatically
   LPTMR_0.setCallback(flash);
#endif

   for(;;) {
      // This is required so that the CNR visibly updates in debugger
      LPTMR0->CNR = 0;
      __asm__("nop");
   }
}
