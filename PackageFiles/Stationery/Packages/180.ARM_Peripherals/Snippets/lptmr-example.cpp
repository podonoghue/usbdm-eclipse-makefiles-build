/**
 * @file lptmr-example.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "lptmr.h"

using namespace USBDM;

/*
 * Low power timer (LPTMR) example
 *
 * Demonstrates use of timer call-back
 */

// Comment out the following line to use static interrupt handlers
#define SET_HANDLERS_PROGRAMMATICALLY

// Connection mapping - change as required
using RED_LED   = $(demo.cpp.red.led:USBDM::GpioB<0>);

/*
 * This handler is set programmatically
 */
void flash(void) {
   RED_LED::toggle();
}

#ifndef SET_HANDLERS_PROGRAMMATICALLY
/**
 * Example showing how to install a custom IRQ handler for a LPTMR
 */
namespace USBDM {

template<> void Lptmr_T<Lptmr0Info>::irqHandler() {
   // Clear interrupt flag
   lptmr->CSR |= LPTMR_CSR_TCF_MASK;
   RED_LED::toggle();
}

}
#endif

int main() {
   RED_LED::setOutput();

   // May need to change prescaler to get useful delays
   Lptmr0::enable();
   
//   Lptmr0::configure(Lptmr0::convertMicrosecondsToTicks(1000));
   Lptmr0::configure(Lptmr0::convertSecondsToTicks(.001));

#ifdef SET_HANDLERS_PROGRAMMATICALLY
   // This handler is set programmatically
   Lptmr0::setCallback(flash);
#endif

   for(;;) {
      // This is required so that the CNR visibly updates in debugger
      LPTMR0->CNR = 0;
      __asm__("nop");
   }
}
