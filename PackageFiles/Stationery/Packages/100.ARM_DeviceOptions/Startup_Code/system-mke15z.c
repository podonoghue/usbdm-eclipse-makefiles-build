/*
 * sysinit-mke15z.c
 *
 * Generic system initialization for Kinetis MKExx family
 *
 *  Created on: 18/08/2013
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

#if !defined(WDOG)

/* WDOG timer register */
typedef struct {
   volatile uint8_t  CS1;
   volatile uint8_t  CS2;
   volatile uint16_t CNT;
   volatile uint16_t TOVAL;
   volatile uint16_t WIN;
} WatchDog;

#define WDOG (*(volatile WatchDog*) 0x40052000)

#define WDOG_CS1_EN_MASK       (1<<7)
#define WDOG_CS1_INT_MASK      (1<<6)
#define WDOG_CS1_UPDATE_MASK   (1<<5)
#define WDOG_CS1_DBG_MASK      (1<<2)
#define WDOG_CS1_WAIT_MASK     (1<<1)
#define WDOG_CS1_STOP_MASK     (1<<0)

#define WDOG_CS2_CLK(x)  ((x)<<0)

#define WDOG_CS1     WDOG.CS1
#define WDOG_CS2     WDOG.CS2
#define WDOG_CNT     WDOG.CNT
#define WDOG_TOVAL   WDOG.TOVAL

#endif

#define WDOG_UPDATE_KEY                          (0xD928C520U)
#define WDOG_REFRESH_KEY                         (0xB480A602U)

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

#ifdef __VTOR_PRESENT
   /* Set the interrupt vector table position */
   SCB_VTOR = (uint32_t)__vector_table;
#endif

   // Clear Boot ROM flag (future boots from Flash)
   RCM->MR = RCM_MR_BOOTROM(3);

   // Disable watch-dog
   WDOG->CNT    = WDOG_UPDATE_KEY; // Write the unlock word
   WDOG->TOVAL  = -1;              // Setting time-out value
   WDOG->CS     =
         WDOG_CS_CLK(1) |        // Setting 1-kHz clock source
         WDOG_CS_UPDATE(1);      // Allow future update
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

// Code below assumes interrupts start out enabled!

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
