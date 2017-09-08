/**
 ============================================================================
 * @file    ftm-quadrature-example.cpp
 * @brief   Demo using Ftm class to implement a Quadrature encoder
 *
 *  Created on: 28/5/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

/*
 * Note - Not all FTMs support quadrature encoder functions
 */

using namespace USBDM;

// Use FTM1 as the quadrature encoder
// Not all FTMs support this mode
using QuadEncoder = QuadEncoder1;

/**
 * Callback executed on timer overflow/underflow
 */
void callBack() {
   if (QuadEncoder::ftm->QDCTRL & FTM_QDCTRL_QUADIR_MASK) {
      // Indicates overflow while increasing
   }
   else {
      // Indicates overflow while decreasing
   }
}

int main() {
   // Enable encoder
   QuadEncoder::enable();

   // Set pin filters
   QuadEncoder::enableFilter(15);

   // Reset position to zero
   // Movement will be +/- relative to this initial position
   QuadEncoder::resetPosition();

   // Set up callback for quadrature overflow or underflow
   QuadEncoder::setTimerOverflowCallback(callBack);
   QuadEncoder::enableTimerOverflowInterrupts();
   QuadEncoder::enableNvicInterrupts();

   // Check if configuration failed
   USBDM::checkError();

   for (;;) {
      // Report position
      console.write("Shaft position = ").writeln(QuadEncoder::getPosition());
   }

   return 0;
}
