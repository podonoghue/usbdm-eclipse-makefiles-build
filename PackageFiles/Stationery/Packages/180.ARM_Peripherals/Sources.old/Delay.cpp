/*
 * @file Delay.cpp
 * @brief Very simple delay routine using SysTick timer
 *
 *  Created on: 5 Jul 2015
 *      Author: podonoghue
 */
#include "derivative.h"
#include "Delay.h"

#ifndef __CMSIS_RTOS
volatile static unsigned timer;
volatile static unsigned ticks;

/**
 * SysTick handler
 *
 * This routine is called approximately every millisecond
 */
void SysTick_Handler(void) {
   ticks++;
   if (timer>0) {
      timer--;
   }
}

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to busy-wait
 * @note Uses interrupts
 */
void waitMS(unsigned msToWait) {
   // 1 ms tick
   SysTick_Config(SystemBusClock/1000);

   timer = msToWait;
   while (timer>0) {
      __WFI();
   }
}

/**
 * Get count of timer ticks
 *
 * @return ticks since arbitrary epoch
 */
unsigned getTicks() {
   return ticks;
}
#else
#include "cmsis_os.h"

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to busy-wait
 */
void waitMS(unsigned msToWait) {
   osDelay(msToWait);
}
#endif

/**
 * Very <b>approximate</b> 10us delay routine
 * This is only provided for LCD interface etc where
 * some pulses have a minimum duration
 */
//void wait10us() {
//   int i = SystemBusClock/1000000;
//   while (i-->0) {
//      __asm__("nop");
//      __asm__("nop");
//      __asm__("nop");
//      __asm__("nop");
//      __asm__("nop");
//      __asm__("nop");
//      __asm__("nop");
//   }
//}

