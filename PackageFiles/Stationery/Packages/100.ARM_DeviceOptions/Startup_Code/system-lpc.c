/*
 * system.c
 *
 * Derived from system-lpc.c
 *
 * Generic system initialization for LPC
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

/* Actual Vector table */
//extern int const __vector_table[];

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
   }
   return disableInterruptCount>0;
}

