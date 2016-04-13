/*
 * @file pit.cpp (derived from pit-MK.cpp)
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
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

#if defined(PIT) && (PIT_USES_NAKED_HANDLER == 0)

template<class Info>
PITCallbackFunction Pit_T<Info>::callback[Info::irqCount];

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
