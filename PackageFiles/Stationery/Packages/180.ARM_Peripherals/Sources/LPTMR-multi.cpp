/*
 * lptrm.c
 *
 *  Created on: 12/11/2013
 *      Author: podonoghue
 */

#include <stddef.h>
#include "derivative.h"
#include "utilities.h"
#include "LPTMR.h"

/*!=========================================================================
 *
 *   Low Power Timer (LPTMR) routines
 *
 *=========================================================================*/

#ifdef LPTMR0
#if !defined(SIM_SCGC5_LPTMR0_MASK)
#define SIM_SCGC5_LPTMR0_MASK SIM_SCGC5_LPTMR_MASK
#endif

#if LPTMR_USES_NAKED_HANDLER == 0

static LPTMRCallbackFunction LPTMR_0_Handler = 0;
const LPTMR LPTMR_0 = {LPTMR0, &LPTMR0_CLOCK_REG, LPTMR0_CLOCK_MASK, LPTMR0_IRQn, LPTMR_IRQ_LEVEL_V, &LPTMR_0_Handler};

/*!
 *   LPTRM interrupt handler
 *
 *   Calls LPTMR callback
 */
void LPTMR0_IRQHandler(void) {
   // Clear interrupt flag
   LPTMR0->CSR |= LPTMR_CSR_TCF_MASK;

   if (LPTMR_0_Handler != 0) {
      LPTMR_0_Handler();
   }
}

#else

const LPTMR LPTMR_0 = {LPTMR0, &LPTMR0_CLOCK_REG, LPTMR0_CLOCK_MASK, LPTMR0_IRQn, LPTMR_IRQ_LEVEL_V};

#endif


#endif
