/*
 * clockMCF5225x.c
 *
 *  Used for MCF52252, MCF52254, MCF52255, MCF52256, MCF52258, MCF52259
 *
 *  Based on MCF52259RM
 *
 *  Created on: 04/03/2012
 *      Author: podonoghue
 */
#include "string.h"
#include "derivative.h" /* include peripheral declarations */
#include "system.h"
#include "utilities.h"
#include "stdbool.h"

#include "clock_configure.h"

uint32_t SystemCoreClock  = 2*SYSTEM_BUS_CLOCK; // Hz
uint32_t SystemBusClock   = SYSTEM_BUS_CLOCK;   // Hz

/*! Sets up the clock out of RESET
 *!
 */
void clock_initialise(void) {
//   CLOCK_SYNCR = CLOCK_SYNCR_MFD(1)|CLOCK_SYNCR_RFD(0)|CLOCK_SYNCR_PLLMODE;
   SystemCoreClockUpdate();
}

/**
 * Update SystemCoreClock variable
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from CPU registers.
 */
void SystemCoreClockUpdate(void) {
   uint32_t refClk = OSCCLK_CLOCK;

#ifdef CLOCK_SYNSR_OCOSC_MASK
   switch(CLOCK_SYNSR & (CLOCK_SYNSR_EXTOSC_MASK|CLOCK_SYNSR_OCOSC_MASK|CLOCK_SYNSR_CRYOSC_MASK)) {
      case (CLOCK_SYNSR_EXTOSC_MASK):
      case (CLOCK_SYNSR_CRYOSC_MASK):
         refClk = OSCCLK_CLOCK;
         break;

      case (CLOCK_SYNSR_OCOSC_MASK):
         refClk = SYSTEM_IRC_CLOCK;
         break;
   }
#endif

   uint32_t cchr = 1 + ((CLOCK_CCHR & CLOCK_CCHR_CCHR_MASK)>>CLOCK_CCHR_CCHR_SHIFT);
   refClk /= cchr;

   if ((CLOCK_SYNCR&(CLOCK_SYNCR_PLLEN_MASK|CLOCK_SYNCR_CLKSRC_MASK)) == (CLOCK_SYNCR_PLLEN_MASK|CLOCK_SYNCR_CLKSRC_MASK)) {
      // PLL output clock drives the system clock
      uint32_t mfd  = 2*((CLOCK_SYNCR&CLOCK_SYNCR_MFD(0xFFFF))>>CLOCK_SYNCR_MFD_SHIFT)+4;
      uint32_t rfd  = 1<<((CLOCK_SYNCR&CLOCK_SYNCR_RFD(0xFFFF))>>CLOCK_SYNCR_RFD_SHIFT);
      SystemCoreClock = (refClk*mfd)/rfd;
   }
   else {
      // PLL reference clock (input clock) drives the system clock.
      SystemCoreClock = refClk;
   }
   SystemCoreClock >>= ((CLOCK_LPCR & CLOCK_LPCR_LPD_MASK)>>CLOCK_LPCR_LPD_SHIFT);
}

