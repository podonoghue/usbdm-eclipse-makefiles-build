/*
 * pit.c
 *
 *  Created on: 12/11/2013
 *      Author: podonoghue
 */

#include <stddef.h>
#include "derivative.h"
#include "utilities.h"
#include "pit.h"

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

PITCallbackFunction PIT_::callback[sizeof(PIT->CHANNEL)/sizeof(PIT->CHANNEL[0])] = {0};

/*
 * If using naked handler it must be named exactly as shown
 * MKL version - shared handler for all PIT channels
 */
void PIT_IRQHandler(void) {
   for (unsigned channel=0; channel<(sizeof(PIT_::callback)/sizeof(PIT_::callback[0])); channel++) {
      if (PIT->CHANNEL[channel].TFLG & PIT_TFLG_TIF_MASK) {
         // Clear interrupt flag
         PIT->CHANNEL[channel].TFLG = PIT_TFLG_TIF_MASK;
         // Do call-back
         if (PIT_::callback[channel] != 0) {
            PIT_::callback[channel]();
         }
      }
   }
}
#endif

#ifdef LPTMR0
const PIT_ PIT_0;
#endif

#endif
