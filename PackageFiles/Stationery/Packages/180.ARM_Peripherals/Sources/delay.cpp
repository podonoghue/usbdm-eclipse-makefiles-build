/*
 * @file delay.cpp
 *
 * @brief Delay routines using Systick Counter
 *
 *  Created on: 5 Nov 2015
 *      Author: podonoghue
 */
#include "delay.h"

#ifdef __cplusplus
namespace USBDM {
#endif

#ifndef __CMSIS_RTOS

/**
 * Simple delay routine
 *
 * @param delayct How many ticks to busy-wait
 *
 */
static void waitTicks(int64_t delayct) {

   // Enable counter
   enableTimer();

   // Get current tick
   uint32_t last = getTicks();

   while(delayct > 0) {
      // Decrement time elapsed
      // Note: This relies on the loop executing in less than the roll-over time
      // of the counter i.e. (TIMER_MASK+1)/SystemCoreClock
      uint32_t now = getTicks();
      delayct -= (uint32_t)(TIMER_MASK&(last-now));
      last = now;
   }
}

/**
 * Simple delay routine
 *
 * @param usToWait How many microseconds to busy-wait
 *
 * @note Limited to 2^32 us (4,294 s)
 * @note Uses busy-waiting based on Systick timer
 */
void waitUS(uint32_t usToWait) {
   // Convert duration to ticks
   waitTicks(((uint64_t)usToWait * SystemCoreClock) / 1000000);
}

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to busy-wait
 *
 * @note Limited to 2^32 ms (71,582 minutes)
 * @note Uses busy-waiting based on Systick timer
 */
void waitMS(uint32_t msToWait) {
   // Convert duration to ticks
   waitTicks(((uint64_t)msToWait * SystemCoreClock) / 1000);
}

#else
#include "cmsis_os.h"

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to wait
 */
void waitMS(uint32_t msToWait) {
   osDelay(msToWait);
}
#endif

#ifdef __cplusplus
} // End namespace USBDM
#endif

