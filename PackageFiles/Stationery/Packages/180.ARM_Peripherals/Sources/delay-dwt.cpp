/*
 * @file delay.cpp (derived from delay-dwt.cpp)
 * @brief Delay routines using DWT->CYCCNT counter
 *
 *  Created on: 5 Oct 2015
 *      Author: podonoghue
 */
#include "derivative.h"
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

   CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

#ifdef DEBUG_BUILD
   if ((DWT->CTRL&DWT_CTRL_NOCYCCNT_Msk) != 0) {
      // No CYCCNT
      __asm__("bkpt");
   }
#endif

   // Enable counter
   DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

   // Get current tick
   uint32_t last = DWT->CYCCNT;

   while(delayct > 0) {
      // Now
      uint32_t now = DWT->CYCCNT;
      // Decrement time elapsed
      // Note: This relies on the loop executing in less than the roll-over time
      // of the counter i.e. (2^32)/SystemCoreClock
      delayct -= (uint32_t)(now-last);
      // Save for next increment
      last = now;
   }
}

/**
 * Simple delay routine
 *
 * @param usToWait How many microseconds to busy-wait
 *
 * @note Limited to 2^32 us (4,294 s)
 * @note Uses busy-waiting
 */
void waitUS(uint32_t usToWait) {
   // Convert duration to DWT ticks
   waitTicks(((uint64_t)usToWait * SystemCoreClock) / 1000000);
}

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to busy-wait
 *
 * @note Limited to 2^32 ms (71,582 minutes)
 * @note Uses busy-waiting
 */
void waitMS(uint32_t msToWait) {
   // Convert duration to DWT ticks
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

