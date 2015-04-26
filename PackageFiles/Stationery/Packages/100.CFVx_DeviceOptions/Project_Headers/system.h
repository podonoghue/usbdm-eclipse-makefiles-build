/*
 * system.h
 *
 *  Created on: Nov 6, 2012
 *      Author: podonoghue
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t SystemCoreClock; // Hz
extern uint32_t SystemBusClock;  // Hz

void clock_initialise(void);
void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H_ */
