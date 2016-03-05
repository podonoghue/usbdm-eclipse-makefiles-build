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

/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
extern "C"
void PIT0_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;

   if (Pit::callback[0] != 0) {
      Pit::callback[0]();
   }
}
/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
extern "C"
void PIT1_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;

   if (Pit::callback[1] != 0) {
      Pit::callback[1]();
   }
}
/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
extern "C"
void PIT2_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[2].TFLG = PIT_TFLG_TIF_MASK;

   if (Pit::callback[2] != 0) {
      Pit::callback[2]();
   }
}
/**
 *   PIT interrupt handler
 *
 *   Calls PIT callback
 */
extern "C"
void PIT3_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[3].TFLG = PIT_TFLG_TIF_MASK;

   if (Pit::callback[3] != 0) {
      Pit::callback[3]();
   }
}
#endif

#endif
