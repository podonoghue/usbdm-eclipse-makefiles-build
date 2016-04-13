/*
 * @file lptmr.cpp
 *
 *  Created on: 12/11/2013
 *      Author: podonoghue
 */

#include <stddef.h>
#include "derivative.h"
#include "utilities.h"
#include "lptmr.h"

using namespace USBDM;

/*!=========================================================================
 *
 *   Low Power Timer (Lptrm) routines
 *
 *=========================================================================*/

#if defined(LPTMR0) && (LPTMR_USES_NAKED_HANDLER == 0)

template<> LPTMRCallbackFunction Lptmr_T<Lptmr0Info>::callback = 0;

/*!
 *   LPTRM interrupt handler
 *
 *   Calls LPTMR callback
 */
void LPTMR0_IRQHandler(void) {
   // Clear interrupt flag
   Lptmr_T<Lptmr0Info>::lptmr->CSR |= LPTMR_CSR_TCF_MASK;

   if (Lptmr_T<Lptmr0Info>::callback != 0) {
      (*Lptmr_T<Lptmr0Info>::callback)();
   }
}
#endif
