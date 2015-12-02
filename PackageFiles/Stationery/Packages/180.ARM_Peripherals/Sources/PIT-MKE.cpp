/*
 * @file pit.cpp (derived from pit-MKE.cpp)
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

PITCallbackFunction PIT_::callback[PIT_NUMBER_OF_CHANNELS] = {0};

/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
void PIT0_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;

   if (PIT_::callback[0] != 0) {
      PIT_::callback[0]();
   }
}
/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
void PIT1_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;

   if (PIT_::callback[1] != 0) {
      PIT_::callback[1]();
   }
}
/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
void PIT2_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[2].TFLG = PIT_TFLG_TIF_MASK;

   if (PIT_::callback[2] != 0) {
      PIT_::callback[2]();
   }
}
/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
void PIT3_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[3].TFLG = PIT_TFLG_TIF_MASK;

   if (PIT_::callback[3] != 0) {
      PIT_::callback[3]();
   }
}
#endif

#ifdef LPTMR0
const PIT_ PIT_0;
#endif

#endif
