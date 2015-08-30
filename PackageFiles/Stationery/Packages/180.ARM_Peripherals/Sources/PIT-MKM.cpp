/*
 * @file PIT.cpp (from PIT-MKM.cpp)
 *
 *  Created on: 12/11/2013
 *      Author: podonoghue
 */

#include <stddef.h>
#include "derivative.h"
#include "utilities.h"
#include "PIT.h"

/*!=========================================================================
 *
 *   Programmable Interrupt Timer (PIT) routines
 *
 *=========================================================================*/

#ifdef PIT0
#if !defined(SIM_SCGC5_PIT0_MASK)
#define SIM_SCGC5_PIT0_MASK SIM_SCGC5_PIT_MASK
#endif

#if PIT_USES_NAKED_HANDLER == 0

PITCallbackFunction PIT_::callback[PIT0_NUMBER_OF_CHANNELS+PIT1_NUMBER_OF_CHANNELS] = {0};

/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
void PIT0_1_IRQHandler(void) {
   unsigned channel;
   for (channel=0; channel<PIT0_NUMBER_OF_CHANNELS; channel++) {
      if ((PIT_::callback[channel] != 0) && (PIT0->CHANNEL[channel].TFLG & PIT_TFLG_TIF_MASK)) {
         // Clear interrupt flag
         PIT0->CHANNEL[channel].TFLG = PIT_TFLG_TIF_MASK;
         // Do call-back
         PIT_::callback[channel]();
      }
   }
   for (;channel<(PIT0_NUMBER_OF_CHANNELS+PIT1_NUMBER_OF_CHANNELS); channel++) {
      if ((PIT_::callback[channel] != 0) && (PIT1->CHANNEL[channel].TFLG & PIT_TFLG_TIF_MASK)) {
         // Clear interrupt flag
         PIT1->CHANNEL[channel].TFLG = PIT_TFLG_TIF_MASK;
         // Do call-back
         PIT_::callback[channel]();
      }
   }
}
#endif

#ifdef PIT0
const PIT_ PIT_0 = {&PIT0_CLOCK_REG, PIT0_CLOCK_MASK, PIT0};
#endif

#ifdef PIT1
const PIT_ PIT_1 = {&PIT1_CLOCK_REG, PIT1_CLOCK_MASK, PIT1};
#endif

#endif
