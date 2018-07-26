/**
 ============================================================================
 * @file    ftm-quadrature-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Demo using Ftm class to implement a Quadrature decoder
 *
 *  Created on: 28/5/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

/*
 * Note - Not all FTMs support quadrature decoder functions
 */

using namespace USBDM;

// Use FTM1 as the quadrature decoder
// Not all FTMs support this mode
using QuadDecoder = QuadDecoder1;

/**
 * Callback executed on timer overflow/underflow
 */
void callBack() {
   if (QuadDecoder::ftm().QDCTRL & FTM_QDCTRL_QUADIR_MASK) {
      // Indicates overflow while increasing
   }
   else {
      // Indicates overflow while decreasing
   }
}

int main() {
   // Configure decoder
   QuadDecoder::configure(FtmPrescale_1);

   // Set pin characteristics
   QuadDecoder::setInput(PinPull_Up);

   // Set pin filters
   QuadDecoder::enableFilter(15);

   // Reset position to zero
   // Movement will be +/- relative to this initial position
   QuadDecoder::resetPosition();

   // Set up callback for quadrature overflow or underflow
   QuadDecoder::setTimerOverflowCallback(callBack);
   QuadDecoder::enableTimerOverflowInterrupts();
   QuadDecoder::enableNvicInterrupts();

   // Check if configuration failed
   USBDM::checkError();

   for (;;) {
      // Report position
      console.write("Shaft position = ").writeln(QuadDecoder::getPosition());
   }

   return 0;
}
