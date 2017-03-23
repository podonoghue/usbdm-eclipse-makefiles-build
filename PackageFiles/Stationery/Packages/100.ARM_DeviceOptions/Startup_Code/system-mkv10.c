/*
 * sysinit-mkv10.c
 *
 * Generic system initialization for Kinetis MKMxx family
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */

#include <stdint.h>
#include "derivative.h"

/* This definition is overridden if Clock initialisation is provided */
__attribute__((__weak__))
void SystemCoreClockUpdate(void) {
}

/* This is overridden if actual clock code is provided */
__attribute__((__weak__))
uint32_t SystemBusClock = 8000000;
__attribute__((__weak__))
uint32_t SystemCoreClock = 4000000;

/* Actual Vector table */
extern int const __vector_table[];

#ifndef SCB
#define SCB_VTOR                 (*(uint32_t *)0xE000ED08)
#define SCB_CCR                  (*(uint32_t *)0xE000ED14)
#define SCB_CCR_DIV_0_TRP_MASK   (1<<4)
#define SCB_CCR_UNALIGN_TRP_MASK (1<<3)
#else
#define SCB_VTOR  (SCB->VTOR)
#define SCB_CCR   (SCB->CCR)
#endif

/* This definition is overridden if Clock initialisation is provided */
__attribute__((__weak__))
void clock_initialise() {
}

/* This definition is overridden if UART initialisation is provided */
__attribute__((__weak__))
void console_initialise() {
}

/* This definition is overridden if RTC initialisation is provided */
__attribute__((__weak__))
void rtc_initialise(void) {
}

// Dummy hook routine for when CMSIS is not used.
__attribute__((weak))
void software_init_hook (void) {
}

/* Unlocking Watchdog sequence words*/
#define WDOG_UNLOCK_SEQ_1   (0xC520)
#define WDOG_UNLOCK_SEQ_2   (0xD928)

#define WDOG_DISABLED_CTRL  (0xD2)

#ifdef __NO_STARTFILES__
#warning Due to limited RAM the C library standard initialisation is not called - BSS and DATA are still initialised
#endif

/*!
 *  @brief Low-level initialize the system
 *
 *  Low level setup of the microcontroller system. \n
 *  Called very early in the initialisation. \n
 *  May NOT use globals etc (as will be overwritten by BSS initialization)
 */
void SystemInitLowLevel(void) {
   /* This is generic initialization code */
   /* It may not be correct for a specific target */

#ifdef __VTOR_PRESENT
   /* Set the interrupt vector table position */
   SCB_VTOR = (uint32_t)__vector_table;
#endif

   /* Disable the Watchdog */
   WDOG->UNLOCK   = WDOG_UNLOCK_SEQ_1;
   WDOG->UNLOCK   = WDOG_UNLOCK_SEQ_2;
   WDOG->STCTRLH  = WDOG_DISABLED_CTRL;
}

/**
 * @brief Initialize the system
 *
 * Setup the microcontroller system.
 */
__attribute__ ((constructor))
void SystemInit(void) {
   /* This is generic initialization code */
   /* It may not be correct for a specific target */

   /* Use Clock initialisation - if present */
   clock_initialise();

   /* Use UART initialisation - if present */
   console_initialise();

   /* Use RTC initialisation - if present */
   rtc_initialise();

}

// Code below assumes interrupts start oiut enabled!

/** Nesting count for interrupt disable */
static int disableInterruptCount = 0;

/**
 * Disable interrupts
 *
 * This function keeps a count of the number of times interrupts is enabled/disabled so may be called in recursive routines
 */
void disableInterrupts() {
   __disable_irq();
   disableInterruptCount++;
}

/**
 * Enable interrupts
 *
 * This function keeps a count of the number of times interrupts is enabled/disabled so may be called in recursive routines
 *
 * @return true if interrupts are now enabled
 */
int enableInterrupts() {
   if (disableInterruptCount>0) {
      disableInterruptCount--;
   }
   if (disableInterruptCount == 0) {
      __enable_irq();
      return 1;
   }
   return 0;
}

