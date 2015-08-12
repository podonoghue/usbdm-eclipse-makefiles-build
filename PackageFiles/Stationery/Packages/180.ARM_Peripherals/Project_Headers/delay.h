/**
 * @file     delay.h
 * @brief    Simple delay routines using SysTick timer
 *
 * @version  V4.11.1.70
 * @date     18 June 2015
 */
#ifndef SOURCES_DELAY_H_
#define SOURCES_DELAY_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to busy-wait
 */
void waitMS(unsigned msToWait);

/**
 * Very approximate 10us delay routine
 */
void wait10us();

#ifndef __CMSIS_RTOS
/**
 * Get count of timer ticks
 *
 * @return ticks since arbitrary epoch
 */
unsigned getTicks();
#endif

#ifdef __cplusplus
}
#endif

#endif /* SOURCES_DELAY_H_ */
