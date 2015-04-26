/*
 * lptmr_private-MK64M12.h
 *
 *  Created on: Nov 6, 2012
 *      Author: podonoghue
 */

#ifndef LPTMR_PRIVATE_H_
#define LPTMR_PRIVATE_H_

#include <stdint.h>
#include "derivative.h"
#include "clock.h"

#ifdef __cplusplus
extern "C" {
#endif

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

//===================================
//
// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

// LPTMR0_CLKSRC ==============================
//
//   <o> LPTMR0 Clock Source
//   <i> Low Power Timer clock source - [LPTMR0_PSR_PCS]
//     <0=> MCG Internal Reference Clock (MCGIRCLK)
//     <1=> Low power oscillator (LPO - 1kHz)
//     <2=> 32kHz Clock Source (ERCLK32)
//     <3=> Oscillator External Reference Clock (OSCERCLK)
#define LPTMR_PSR_PCS_V 0
#define LPTMR_PSR_PCS_M (LPTMR_PSR_PCS_V<<LPTMR0_PSR_PCS_SHIFT)

#if (LPTMR_PSR_PCS_M == LPTMR0_PSR_PCS(0))
#define SYSTEM_LPTMR0_CLOCK SYSTEM_MCGIR_CLOCK
#elif (LPTMR_PSR_PCS_M == LPTMR0_PSR_PCS(1))
#define SYSTEM_LPTMR0_CLOCK SYSTEM_LOW_POWER_CLOCK
#elif (LPTMR_PSR_PCS_M == LPTMR0_PSR_PCS(2))
#define SYSTEM_LPTMR0_CLOCK SYSTEM_ERCLK32_CLOCK
#elif (LPTMR_PSR_PCS_M == LPTMR0_PSR_PCS(3))
#define SYSTEM_LPTMR0_CLOCK SYSTEM_OSCER_CLOCK
#endif

#ifdef __cplusplus
}
#endif

#endif /* LPTMR_PRIVATE_H_ */
