/*
 * lptmr.c
 *
 *  Created on: 14/07/2014
 *      Author: podonoghue
 */

#include "lptmr_private.h"

void lptmr_initialise(void) {
#if defined(LPTMR0_PSR_PCS_MASK) && defined(LPTMR_PSR_PCS_M) // Low Power Timer clock
   LPTMR0->PSR = (LPTMR0->PSR&~LPTMR0_PSR_PCS_MASK)|LPTMR_PSR_PCS_M;
#endif
}



