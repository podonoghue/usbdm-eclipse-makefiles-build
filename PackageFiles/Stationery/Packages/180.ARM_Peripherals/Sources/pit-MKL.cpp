/*
 * @file pit.cpp (derived from pit-MKL.cpp)
 *
 *  Created on: 12/11/2013
 *      Author: podonoghue
 */

#include <stddef.h>
#include "derivative.h"
#include "utilities.h"
#include "pit.h"

using namespace USBDM;

/*!=========================================================================
 *
 *   Programmable Interrupt Timer (PIT) routines
 *
 *=========================================================================*/

#ifdef PIT
#if !defined(SIM_SCGC5_PIT0_MASK)
#define SIM_SCGC5_PIT0_MASK SIM_SCGC5_PIT_MASK
#endif

#if PIT_USES_NAKED_HANDLER == 0

/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
extern "C"
void PIT_IRQHandler(void) {
   for (unsigned channel=0; channel<PIT_NUMBER_OF_CHANNELS; channel++) {
      if (PIT->CHANNEL[channel].TFLG & PIT_TFLG_TIF_MASK) {
         // Clear interrupt flag
         PIT->CHANNEL[channel].TFLG = PIT_TFLG_TIF_MASK;
         // Do call-back
         if (Pit::callback[channel] != 0) {
            Pit::callback[channel]();
         }
      }
   }
}
#endif
#endif
