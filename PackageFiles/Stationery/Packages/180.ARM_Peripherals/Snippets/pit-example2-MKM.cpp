/**
 ============================================================================
 * @file  pit-example2.cpp (180.ARM_Peripherals/Snippets/pit-example2-MKM.cpp)
 * @brief Programmable Interrupt Timer (PIT) Example
 *
 * Demonstrates PIT call-back or static handler
 *
 * @author   podonoghue
============================================================================
 */
#include "hardware.h"
#include "pit.h"

using namespace USBDM;

/**
 * This example uses PIT interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->PIT tab.
 * Select irqHandlingMethod option (Software (Use setCallback() or override class method)
 */

// Comment out the following line to use static interrupt handlers
#define SET_HANDLERS_PROGRAMMATICALLY

// Connection mapping - change as required
using Led1 = $(/HARDWARE/Led1:GpioB<0, ActiveLow>);
using Led2 = $(/HARDWARE/Led2:GpioB<1, ActiveLow>);

#ifndef SET_HANDLERS_PROGRAMMATICALLY
/**
 * Example showing how to create custom IRQ handlers for PIT channels by
 * providing an explicit instantiation of the PIT template function for ISR
 */
namespace USBDM {

/*
 * If using naked handler it must be named exactly as shown
 * MKM version - shared handler for all PITs and PIT channels
 */
template<> void Pit_T<PitInfo>::irqHandler() {
   if (PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      PIT0->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
      Led1::toggle();
   }
   if (PIT0->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      PIT0->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
      Led2::toggle();
   }
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
   Led1::setOutput();
   Led2::setOutput();

   // Turn off LED initially
   Led1::set();
   Led2::set();

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
