/**
 ============================================================================
 * @file    ftm-quadrature-example.cpp
 * @brief   Demo using Ftm class to implement a Quadrature encoder
 *
 *  Created on: 28/5/2017
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "hardware.h"

/*
 * Note - Not all FTMs support quadrature encoder functions
 */

/**
 * Callback executed on timer overflow/underflow
 *
 * @param tmr Pointer to hardware
 */
void callBack(volatile FTM_Type *tmr) {
   if (tmr->QDCTRL & FTM_QDCTRL_QUADIR_MASK) {
      // Indicates overflow while increasing
   }
   else {
      // Indicates overflow while decreasing
   }
}

int main() {
   using namespace USBDM;

   // Use FTM1 as the quadrature encoder
   // Not all FTMs support this mode
   using QuadEncoder = QuadEncoder1;

   // Enable encoder
   QuadEncoder::enable();

   // Set pin filters
   QuadEncoder::enableFilter(15);

   // Reset position to zero
   // Movement will be relative to this value
   QuadEncoder::resetPosition();

   // Set up callback for quadrature overflow or underflow
   QuadEncoder::setTimerOverflowCallback(callBack);
   QuadEncoder::enableTimerOverflowInterrupts();
   QuadEncoder::enableNvicInterrupts();

   for (;;) {
      // Report position
      printf("Shaft position = %d\n\r", QuadEncoder::getPosition());
   }

   return 0;
}
