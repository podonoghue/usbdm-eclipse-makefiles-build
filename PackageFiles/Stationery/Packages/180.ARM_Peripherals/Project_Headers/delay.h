/**
 * @file delay.h
 * @brief Simple busy-waiting delay routines using DWT->CYCCNT counter
 *
 *  Created on: 5 Oct 2015
 *      Author: podonoghue
 */
#ifndef INCLUDE_USBDM_DELAY_H_
#define INCLUDE_USBDM_DELAY_H_

#include <stdint.h>

#ifdef __cplusplus
namespace USBDM {
#endif

/**
 * Simple delay routine
 *
 * @param usToWait How many microseconds to busy-wait
 */
void waitUS(uint32_t usToWait);

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to busy-wait
 */
void waitMS(uint32_t msToWait);

#ifdef __cplusplus
} // End namespace USBDM
#endif

#endif /* INCLUDE_USBDM_DELAY_H_ */
