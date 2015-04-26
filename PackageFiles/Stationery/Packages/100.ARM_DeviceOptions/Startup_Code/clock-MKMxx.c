/*
 * clock-MKMxx.c
 *
 * Based on MKMxxZxxCxx5RM
 *    2 Oscillators (OSC0, RTC)
 *    1 FLL (OSC0,RTC), (FRDIV=/1-/128, /32-/1024, /1280, /1536)
 *    1 PLL (OSC0,RTC), (VCO x375)
 *
 * Used with:
 *    clock_private-MKMxx.h
 *
 *  Created on: 29/09/2014
 *      Author: podonoghue
 */
#include "string.h"
#include "derivative.h" /* include peripheral declarations */
#include "system.h"
#include "clock_configure.h"
#include "utilities.h"
#include "stdbool.h"

// Some MCUs call OSC_CR0 just OSC->CR
#ifndef OSC0
#define OSC0 OSC
#endif

uint32_t SystemCoreClock = SYSTEM_CORE_CLOCK;   // Hz
uint32_t SystemBusClock  = SYSTEM_BUS_CLOCK; // Hz

/*! @brief Sets up the clock out of RESET
 *
 */
void clock_initialise(void) {

#if (CLOCK_MODE == CLOCK_MODE_NONE)
   // No clock setup
#else
   // XTAL/EXTAL Pins
   SIM->SCGC5   |= SIM_SCGC5_PORTE_MASK;
   PORTE->PCR[2] = PORT_PCR_MUX(0);
   PORTE->PCR[3] = PORT_PCR_MUX(0);

   // Configure the Crystal Oscillator
   OSC0->CR = OSC_CR_ERCLKEN_M|OSC_CR_EREFSTEN_M|OSC_CR_SCP_M;

#if defined(RTC->OSC) && defined(RTC_OSC_OSC_DISABLE_M)
   SIM->SCGC5 |= SIM_SCGC5_IRTC_MASK|SIM_SCGC5_IRTCREGFILE_MASK;
#define RTC_OSC_VALUE (RTC_OSC_OSC_DISABLE_M|RTC_OSC_SCP_M|RTC_OSC_BOOT_MODE_M)
#if (RTC_OSC_VALUE!=0)
   // Unlock RTC
   RTC->STATUS_B = RTC_STATUS_WE(0);
   RTC->STATUS_B = RTC_STATUS_WE(1);
   RTC->STATUS_B = RTC_STATUS_WE(3);
   RTC->STATUS_B = RTC_STATUS_WE(2);
   RTC->OSC = RTC_OSC_VALUE;
   // Lock RTC
   RTC->STATUS_B = RTC_STATUS_WE(1);
#endif
#endif

#if defined(MCG->C7) && defined(MCG_C7_PLL32KREFSEL_M)
   MCG->C7 = MCG_C7_PLL32KREFSEL_M | MCG_C7_OSCSEL_M;
#endif

#if defined(MCG->C8) && defined(MCG_C8_LOCRE1_M)
   MCG->C8 = MCG_C8_LOCRE1_M | MCG_C8_LOLRE_M | MCG_C8_CME1_M | MCG_C8_COARSE_LOLIE_M;
#endif

   // Fast Internal Clock divider
   MCG->SC = MCG_SC_FCRDIV_M;

   // Out of reset MCG is in FEI mode
   // =============================================================

   // Set conservative clock divider
   SIM->CLKDIV1 = SIM_CLKDIV1_SYSDIV(5);

   // Switch from FEI -> FEI/FBI/FEE/FBE
   // =============================================================

   // Set up crystal or external clock source
   MCG->C2 =
            MCG_C2_LOCRE0_M     | // LOCRE0 = 0,1   -> Loss of clock reset enable
            MCG_C2_RANGE0_M     | // RANGE0 = 0,1,2 -> Oscillator low/high/very high clock range
            MCG_C2_HGO0_M       | // HGO0   = 0,1   -> Oscillator low power/high gain
            MCG_C2_EREFS0_M     | // EREFS0 = 0,1   -> Select external clock/crystal oscillator
            MCG_C2_IRCS_M;        // IRCS   = 0,1   -> Select slow/fast internal clock for internal reference

#if ((CLOCK_MODE == CLOCK_MODE_FEI) || (CLOCK_MODE == CLOCK_MODE_FBI) || (CLOCK_MODE == CLOCK_MODE_BLPI) )
   // Transition via FBI
   //=====================================
#define BYPASS (1) // CLKS value used while FLL locks
   MCG->C1 =  MCG_C1_CLKS(BYPASS)     | // CLKS     = X     -> External reference source while PLL locks
              MCG_C1_FRDIV_M          | // FRDIV    = N     -> XTAL/2^n ~ 31.25 kHz
              MCG_C1_IREFS_M          | // IREFS    = 0,1   -> External/Slow IRC for FLL source
              MCG_C1_IRCLKEN_M        | // IRCLKEN  = 0,1   -> IRCLK disable/enable
              MCG_C1_IREFSTEN_M;        // IREFSTEN = 0,1   -> Internal reference enabled in STOP mode

   // Wait for S_IREFST to indicate FLL Reference has switched
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_IREFST_MASK) != (MCG_C1_IREFS_V<<MCG_S_IREFST_SHIFT));

   // Wait for S_CLKST to indicating that OUTCLK has switched to bypass PLL/FLL
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(BYPASS));

   // Set FLL Parameters
   MCG->C4 = (MCG->C4&~(MCG_C4_DMX32_MASK|MCG_C4_DRST_DRS_MASK))|MCG_C4_DMX32_M|MCG_C4_DRST_DRS_M;
#endif

#if ((CLOCK_MODE == CLOCK_MODE_FBE) || (CLOCK_MODE == CLOCK_MODE_FEE) || (CLOCK_MODE == CLOCK_MODE_PLBE) || (CLOCK_MODE == CLOCK_MODE_PBE) || (CLOCK_MODE == CLOCK_MODE_PEE))

   // Transition via FBE
   //=====================================
#define BYPASS (2) // CLKS value used while PLL locks
   MCG->C1 =  MCG_C1_CLKS(BYPASS)     | // CLKS     = 2     -> External reference source while PLL locks
              MCG_C1_FRDIV_M          | // FRDIV    = N     -> XTAL/2^n ~ 31.25 kHz
              MCG_C1_IREFS_M          | // IREFS    = 0,1   -> External/Slow IRC for FLL source
              MCG_C1_IRCLKEN_M        | // IRCLKEN  = 0,1   -> IRCLK disable/enable
              MCG_C1_IREFSTEN_M;        // IREFSTEN = 0,1   -> Internal reference enabled in STOP mode

#if (MCG_C2_EREFS_V != 0)
   // Wait for oscillator stable (if used)
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_OSCINIT0_MASK) == 0);
#endif

   // Wait for S_IREFST to indicate FLL Reference has switched
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_IREFST_MASK) != (MCG_C1_IREFS_V<<MCG_S_IREFST_SHIFT));

   // Wait for S_CLKST to indicating that OUTCLK has switched to bypass PLL/FLL
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(BYPASS));

   // Set FLL Parameters
   MCG->C4 = (MCG->C4&~(MCG_C4_DMX32_MASK|MCG_C4_DRST_DRS_MASK))|MCG_C4_DMX32_M|MCG_C4_DRST_DRS_M;
#endif

#if ((CLOCK_MODE == CLOCK_MODE_PBE) || (CLOCK_MODE == CLOCK_MODE_PEE))

   // Configure PLL Reference Frequency
   // =============================================================
   MCG->C5 =  MCG_C5_PLLCLKEN0_M    |  // PLLCLKEN = 0,1 -> PLL -/enabled (irrespective of PLLS)
              MCG_C5_PLLSTEN0_M;       // PLLSTEN0 = 0,1 -> disabled/enabled in normal stop mode

   // Transition via PBE
   // =============================================================
   MCG->C6 = MCG_C6_LOLIE0_M    |
            MCG_C6_PLLS_M      |  // PLLS  = 0,1 -> Enable PLL
            MCG_C6_CME0_M;        // CME0  = 0,1 -> Disable/enable clock monitor

   // Wait for PLL to lock
   do {
      __asm__("nop");
   } while((MCG->S & MCG_S_LOCK0_MASK) == 0);

   // Wait until PLLS clock source changes to the PLL clock out
   do {
      __asm__("nop");
   } while((MCG->S & MCG_S_PLLST_MASK) == 0);
#endif

#if ((CLOCK_MODE == CLOCK_MODE_FEI) || (CLOCK_MODE == CLOCK_MODE_FEE))
   // Wait for FLL to lock
   do {
      __asm__("nop");
   } while ((MCG->C4&MCG_C4_DRST_DRS_MASK) != MCG_C4_DRST_DRS_M);
#endif

   // Select FEI/FBI/FEE/FBE/PBE/PEE clock mode
   MCG->C1 =  MCG_C1_CLKS_M       | // CLKS     = 0,1,2 -> Select FLL/IRCSCLK/ERCLK
              MCG_C1_FRDIV_M      | // FRDIV    = N     -> XTAL/2^n ~ 31.25 kHz
              MCG_C1_IREFS_M      | // IREFS    = 0,1   -> External/Slow IRC for FLL source
              MCG_C1_IRCLKEN_M    | // IRCLKEN  = 0,1   -> IRCLK disable/enable
              MCG_C1_IREFSTEN_M;    // IREFSTEN = 0,1   -> Internal reference enabled in STOP mode

   // Wait for mode change
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_IREFST_MASK) != (MCG_C1_IREFS_V<<MCG_S_IREFST_SHIFT));

#if defined (MCG_C6_PLLS_V) && (MCG_C1_CLKS_V == 0) // FLL or PLL
#define MCG_S_CLKST_M MCG_S_CLKST(MCG_C6_PLLS_V?3:0)
#else
   #define MCG_S_CLKST_M MCG_S_CLKST(MCG_C1_CLKS_V)
#endif

   // Wait for S_CLKST to indicating that OUTCLK has switched
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST_M);

   // Set the SIM _CLKDIV dividers
   SIM->CLKDIV1 = SIM_CLKDIV1_SYSDIV_M | SIM_CLKDIV1_SYSCLKMODE_M;

#if (CLOCK_MODE == CLOCK_MODE_BLPE) || (CLOCK_MODE == CLOCK_MODE_BLPI)
   // Select BLPE/BLPI clock mode
   MCG->C2 =
            MCG_C2_LOCRE0_M      | // LOCRE0 = 0,1   -> Loss of clock reset
            MCG_C2_RANGE0_M      | // RANGE0 = 0,1,2 -> Oscillator low/high/very high clock range
            MCG_C2_HGO0_M        | // HGO0   = 0,1   -> Oscillator low power/high gain
            MCG_C2_EREFS0_M      | // EREFS0 = 0,1   -> Select external clock/crystal oscillator
            MCG_C2_LP_M          | // LP     = 0,1   -> Select FLL enabled/disabled in bypass mode
            MCG_C2_IRCS_M;         // IRCS   = 0,1   -> Select slow/fast internal clock for internal reference

#endif // (CLOCK_MODE == CLOCK_MODE_BLPE) || (CLOCK_MODE == CLOCK_MODE_BLPI)
#endif // (CLOCK_MODE == CLOCK_MODE_NONE)


   /*!
    * SOPT1 Clock multiplexing
    */
#if defined(SIM_SOPT1_OSC32KSEL_MASK) && defined(SIM_SOPT1_OSC32KSEL_M) // ERCLK32K source
   SIM->SOPT1 = (SIM->SOPT1&~SIM_SOPT1_OSC32KSEL_MASK)|SIM_SOPT1_OSC32KSEL_M;
#endif

   /*!
    * SIM->CTRL_REG Clock multiplexing
    */
#if defined(SIM_CTRL_REG_CLKOUTSEL_MASK)
   SIM->CTRL_REG = (SIM->CTRL_REG&~SIM_CTRL_REG_CLKOUTSEL_MASK)|SIM_CTRL_REG_CLKOUTSEL_M;
#endif

#if defined(SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK)
   SIM->CTRL_REG = (SIM->CTRL_REG&~SIM_CTRL_REG_SAR_TRG_CLK_SEL_MASK)|SIM_CTRL_REG_SAR_TRG_CLK_SEL_M;
#endif

   SystemCoreClockUpdate();
}

/*!
 * @brief Update SystemCoreClock variable
 *
 * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
 */
void SystemCoreClockUpdate(void) {
   uint32_t oscerclk = (MCG->C7&MCG_C7_OSCSEL_MASK)?SYSTEM_OSC32K_CLOCK:OSCCLK_CLOCK;
   switch (MCG->S&MCG_S_CLKST_MASK) {
      case MCG_S_CLKST(0) : // FLL
         if ((MCG->C1&MCG_C1_IREFS_MASK) == 0) {
            SystemCoreClock = oscerclk/(1<<((MCG->C1&MCG_C1_FRDIV_MASK)>>MCG_C1_FRDIV_SHIFT));
            if ((MCG->C2&MCG_C2_RANGE0_MASK) != 0) {
               if ((MCG->C1&MCG_C1_FRDIV_MASK) == MCG_C1_FRDIV(6)) {
                  SystemCoreClock /= 20;
               }
               else if ((MCG->C1&MCG_C1_FRDIV_MASK) == MCG_C1_FRDIV(7)) {
                  SystemCoreClock /= 12;
               }
               else {
                  SystemCoreClock /= 32;
               }
            }
         }
         else {
            SystemCoreClock = SYSTEM_SLOW_IRC_CLOCK;
         }
         SystemCoreClock *= (MCG->C4&MCG_C4_DMX32_MASK)?732:640;
         SystemCoreClock *= ((MCG->C4&MCG_C4_DRST_DRS_MASK)>>MCG_C4_DRST_DRS_SHIFT)+1;
      break;
      case MCG_S_CLKST(1) : // Internal Reference Clock
         if ((MCG->C2&MCG_C2_IRCS_MASK) != 0) {
            SystemCoreClock = SYSTEM_FAST_IRC_CLOCK/(1<<((MCG->SC&MCG_SC_FCRDIV_MASK)>>MCG_SC_FCRDIV_SHIFT));
         }
         else {
            SystemCoreClock = SYSTEM_SLOW_IRC_CLOCK;
         }
         break;
      case MCG_S_CLKST(2) : // External Reference Clock
         SystemCoreClock = oscerclk;
         break;
      case MCG_S_CLKST(3) : // PLL
         SystemCoreClock  = oscerclk*375;
         break;
   }
   SystemCoreClock   = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_SYSDIV_MASK)>>SIM_CLKDIV1_SYSDIV_SHIFT)+1);
   if ((SIM->CLKDIV1&SIM_CLKDIV1_SYSCLKMODE_MASK) != 0) {
      SystemBusClock = SystemCoreClock/2;
   }
   else {
      SystemBusClock = SystemCoreClock;
   }
}

