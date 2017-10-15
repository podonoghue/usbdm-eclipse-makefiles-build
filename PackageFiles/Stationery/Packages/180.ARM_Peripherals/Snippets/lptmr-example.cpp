/**
 * @file lptmr-example.cpp
 */
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
using RED_LED   = USBDM::GpioC<3>;

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

   // Enable LPTMR in time counting mode
   Lptmr0::configureTimeCountingMode(
         LptmrResetOn_Compare,
         LptmrInterrupt_Enable,
         LptmrClockSel_mcgirclk);

   // Set clock source
   Lptmr0::setClock(LptmrClockSel_erclk32);
   // Set period of timer event
   Lptmr0::setPeriod(200*ms);

#ifdef SET_HANDLERS_PROGRAMMATICALLY
   // This handler is set programmatically
   Lptmr0::setCallback(flash);
#endif

   Lptmr0::enableNvicInterrupts();

   // Check for errors so far
   checkError();

   for(;;) {
      // This is required so that the CNR visibly updates in debugger
      LPTMR0->CNR = 0;
      __asm__("nop");
   }
}
