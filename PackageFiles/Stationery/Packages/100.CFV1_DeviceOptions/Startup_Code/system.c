/*
 * sysinit.c
 *
 * Generic system initialization for Coldfire V1
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */

#include <stdint.h>
#include "derivative.h"

#define $(targetDeviceSubFamily)

$(cDeviceParameters)
#ifndef SIM_COPC
#define SIM_COPC (*(uint8_t*) (0xFF80C0+0x0A))
#endif


#ifndef SIM_COPC
#define SIM_COPC (*(uint8_t*) (0xFF80C0+0x0A))
#endif


#ifdef MCU_MCF51AG128
// MCF51AG128 has a different Watchdog
#if !defined(WDOG_UNLOCK)
   /* Defaults for MK devices */

   /* Watchdog unlock register */
   #define WDOG_BASE_ADDR (0xFF9880)
   #define WDOG_STCTRLH  (*(uint16_t *)(WDOG_BASE_ADDR+0x00))
   #define WDOG_UNLOCK   (*(uint16_t *)(WDOG_BASE_ADDR+0x0E))
#endif

   /* Unlocking Watchdog sequence words */
   #define WDOG_UNLOCK_SEQ_1   0xC520
   #define WDOG_UNLOCK_SEQ_2   0xD928

   /* Word to disable the Watchdog */
   #define KINETIS_WDOG_DISABLED_CTRL  (0xD2)
#else

// Usual watchdog
#ifndef SOPT1
#define SOPT1 (*(uint8_t*) 0xFF9880)
#endif

#endif

/* This definition is overridden if Clock initialisation is provided */
__attribute__((__weak__))
void clock_initialise(void) {
}

/* This definition is overridden if UART initialisation is provided */
__attribute__((__weak__))
void uart_initialise(int baudRate) {
   (void)baudRate;
}

void SystemInit(void) {
   // This is generic initialization code
   // It may not be correct for a specific target

#ifdef SIM_COPC
   // Disable watch-dog
   SIM_COPC = 0x00;
#elif defined(WDOG_UNLOCK)
   // Disable watch-dog
   WDOG_UNLOCK  = WDOG_UNLOCK_SEQ_1;
   WDOG_UNLOCK  = WDOG_UNLOCK_SEQ_2;
   WDOG_STCTRLH = KINETIS_WDOG_DISABLED_CTRL;
#elif defined(SOPT1)
   // Disable watch-dog
   SOPT1 = 0x00;
#endif

   /* Use Clock initialisation - if present */
   clock_initialise();

   /* Use UART initialisation - if present */
   uart_initialise(19200);
}

void hardware_init_hook() {

}
void software_init_hook() {

}

