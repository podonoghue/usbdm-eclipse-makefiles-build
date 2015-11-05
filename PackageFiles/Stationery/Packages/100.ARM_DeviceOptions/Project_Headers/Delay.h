/*
 * @file delay.h
 * @brief Simple busy-waiting delay routines using DWT->CYCCNT counter
 *
 *  Created on: 5 Oct 2015
 *      Author: podonoghue
 */
#ifndef SOURCES_DELAY_H_
#define SOURCES_DELAY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

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
}
#endif

#endif /* SOURCES_DELAY_H_ */
