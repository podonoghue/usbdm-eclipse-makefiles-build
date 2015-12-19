/*
 * @file delay.cpp (derived from delay-systick.cpp)
 *
 * @brief Delay routines using Systick Counter
 *
 *  Created on: 5 Nov 2015
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
static void waitTicks(int64_t delay) {

   // No interrupts
   NVIC_DisableIRQ(SysTick_IRQn);

   // Reload with maximum value 2^24
   SYST->RVR = -1;

   // Enable without interrupts
   SYST->CSR = SYST_CSR_CLKSOURCE_MASK| // Processor clock
               SYST_CSR_ENABLE_MASK;    // Enabled

   // Get current tick
   uint32_t last = SYST->CVR;

   while(delay > 0) {
      // Now
      uint32_t now = SYST->CVR;

      // Decrement time elapsed
      // Note: This relies on the loop executing in less than the roll-over time
      // of the counter i.e. (2^24)/SystemCoreClock
      delay -= ((1UL<<24)-1UL)&(uint32_t)(last-now);

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
 * @note Uses busy-waiting based on Systick timer
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
 * @note Uses busy-waiting based on Systick timer
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

