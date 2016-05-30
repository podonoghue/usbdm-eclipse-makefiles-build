/*
 * @file mcg.cpp (derived from mcg_mk_ics48m.cpp)
 *
 * Based on K22P121M120SF7RM
 *   3 Oscillators (OSC0, RTC, IRC48M)
 *   1 FLL (OSC0, RTC, IRC48M), (FRDIV=/1-/128, /32-/1024, /1280, 1536)
 *   2 PLL (OSC0, RTC, IRC48M), (VCO PRDIV=/1-/24, VDIV=x24-x55)
 *
 *  Created on: 04/03/2012
 *      Author: podonoghue
 */
#include "string.h"
#include "derivative.h" /* include peripheral declarations */
#include "system.h"
#include "utilities.h"
#include "stdbool.h"
#include "pin_mapping.h"
#include "rtc.h"
#include "mcg.h"
#include "osc.h"

extern "C" uint32_t SystemCoreClock;
extern "C" uint32_t SystemBusClock;

namespace USBDM {

/** Callback for programmatically set handler */
MCGCallbackFunction Mcg::callback = {0};

/** Current clock mode (FEI out of reset) */
McgInfo::ClockMode Mcg::currentClockMode = McgInfo::ClockMode::ClockMode_FEI;

/**
 * Switch to/from high speed run mode
 * Changes the CPU clock frequency/1, and bus clock frequency /2
 * If the clock is set up for 120 MHz this will be the highest performance possible.
 *
 * This routine assumes that the clock preferences have been set up for the usual RUN mode and only
 * the Core clock divider needs to be changed.
 */
void Mcg::hsRunMode(bool enable) {
   SMC->PMPROT = SMC_PMPROT_AHSRUN_MASK;

   if (enable) {
      SMC->PMCTRL = SMC_PMCTRL_RUNM(3);
      while ((SMC->PMSTAT & 0x80) == 0) {
         // Wait for mode change
         __asm__("nop");
      }
      // Set the SIM _CLKDIV dividers (CPU /1, Bus /2)
      SIM->CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(0))|(SIM_CLKDIV1_OUTDIV2(1))|(McgInfo::SIM_CLKDIV1 & (SIM_CLKDIV1_OUTDIV3_MASK|SIM_CLKDIV1_OUTDIV4_MASK));
   }
   else {
      // Set the SIM _CLKDIV dividers (CPU normal)
      SIM->CLKDIV1 = McgInfo::SIM_CLKDIV1;
      SMC->PMCTRL = SMC_PMCTRL_RUNM(0);
   }
   SystemCoreClockUpdate();
}

/**
 * Do default clock gating
 */
void Mcg::doClockGating() {

   /*!
    * SOPT1 Clock multiplexing
    */
#if defined(SIM_SOPT1_OSC32KSEL_MASK) && defined(SIM_SOPT1_OSC32KSEL_M) // ERCLK32K source
   SIM->SOPT1 = (SIM->SOPT1&~SIM_SOPT1_OSC32KSEL_MASK)|SIM_SOPT1_OSC32KSEL_M;
#endif

   /*!
    * SOPT2 Clock multiplexing
    */
#if defined(SIM_SOPT2_SDHCSRC_MASK) && defined(SIM_SOPT2_SDHCSRC_M) // SDHC clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_SDHCSRC_MASK)|SIM_SOPT2_SDHCSRC_M;
#endif

#if defined(SIM_SOPT2_TIMESRC_MASK) && defined(SIM_SOPT2_TIMESRC_M) // Ethernet time-stamp clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_TIMESRC_MASK)|SIM_SOPT2_TIMESRC_M;
#endif

#if defined(SIM_SOPT2_RMIISRC_MASK) && defined(SIM_SOPT2_RMIISRC_M) // RMII clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_RMIISRC_MASK)|SIM_SOPT2_RMIISRC_M;
#endif

#ifdef SIM_SCGC4_USBOTG_MASK
   // !! WARNING !! The USB interface must be disabled for clock changes to have effect !! WARNING !!
   SIM->SCGC4 &= ~SIM_SCGC4_USBOTG_MASK;
#endif

#if defined(SIM_SOPT2_USBSRC_MASK) && defined(SIM_SOPT2_USBSRC_M) // USB clock (48MHz req.)
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_USBSRC_MASK)|SIM_SOPT2_USBSRC_M;
#endif

#if defined(SIM_SOPT2_USBFSRC_MASK) && defined(SIM_SOPT2_USBFSRC_M) // USB clock (48MHz req.)
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_USBFSRC_MASK)|SIM_SOPT2_USBFSRC_M;
#endif

#if defined(SIM_SOPT2_PLLFLLSEL_MASK) && defined(SIM_SOPT2_PLLFLLSEL_M) // Peripheral clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_PLLFLLSEL_MASK)|SIM_SOPT2_PLLFLLSEL_M;
#endif

#if defined(SIM_SOPT2_UART0SRC_MASK) && defined(SIM_SOPT2_UART0SRC_M) // UART0 clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_UART0SRC_MASK)|SIM_SOPT2_UART0SRC_M;
#endif

#if defined(SIM_SOPT2_TPMSRC_MASK) && defined(SIM_SOPT2_TPMSRC_M) // TPM clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_TPMSRC_MASK)|SIM_SOPT2_TPMSRC_M;
#endif

#if defined(SIM_SOPT2_CLKOUTSEL_MASK) && defined(SIM_SOPT2_CLKOUTSEL_M)
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_CLKOUTSEL_MASK)|SIM_SOPT2_CLKOUTSEL_M;
#endif

#if defined(SIM_SOPT2_RTCCLKOUTSEL_MASK) && defined(SIM_SOPT2_RTCCLKOUTSEL_M)
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_RTCCLKOUTSEL_MASK)|SIM_SOPT2_RTCCLKOUTSEL_M;
#endif

#if defined(SIM_CLKDIV2_USBDIV_MASK) && defined(SIM_CLKDIV2_USBFRAC_MASK) && defined(SIM_CLKDIV2_USB_M)
   SIM->CLKDIV2 = (SIM->CLKDIV2&~(SIM_CLKDIV2_USBDIV_MASK|SIM_CLKDIV2_USBFRAC_MASK)) | SIM_CLKDIV2_USB_M;
#endif

   SystemCoreClockUpdate();
}

constexpr uint8_t clockTransitionTable[8][8] = {
         /*  from                 to =>   ClockMode_FEI,           ClockMode_FEE,           ClockMode_FBI,           ClockMode_BLPI,          ClockMode_FBE,           ClockMode_BLPE,          ClockMode_PBE,           ClockMode_PEE */
         /* ClockMode_FEI,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_FEE,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_FBI,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_BLPI, McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_BLPI, */ { McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI, },
         /* ClockMode_FBE,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_BLPE, McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE, },
         /* ClockMode_BLPE, */ { McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_BLPE, McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE, },
         /* ClockMode_PBE,  */ { McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_BLPE, McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PEE, },
         /* ClockMode_PEE,  */ { McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PEE, },
   };

/**
 * Transition from current clock mode to mode given
 *
 * @param to Clock mode to transition to
 */
int Mcg::clockTransition(McgInfo::ClockMode to) {
   constexpr volatile MCG_Type* mcg = (volatile MCG_Type*)McgInfo::basePtr;

   // Set conservative clock dividers
   SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV4(5)|SIM_CLKDIV1_OUTDIV3(5)|SIM_CLKDIV1_OUTDIV2(5)|SIM_CLKDIV1_OUTDIV1(5);

   if (to != McgInfo::ClockMode_None) {
      int transitionCount = 0;
      do {
         // Used to indicate that clock stabilization wait is needed
         bool externalClockInUse = false;

         McgInfo::ClockMode next;
         if (currentClockMode == McgInfo::ClockMode_None) {
            next = McgInfo::ClockMode_FEI;
         }
         else {
            next = (McgInfo::ClockMode)clockTransitionTable[currentClockMode][to];
         }
         switch (next) {

         case McgInfo::ClockMode_None:
         case McgInfo::ClockMode_FEI: // From FEE, FBI, FBE or reset(FEI)

            mcg->C2 = McgInfo::MCG_C2;

            mcg->C1 =
                  MCG_C1_CLKS(0)           | // CLKS     = 0     -> Output of FLL is selected
                  MCG_C1_IREFS(1)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN

            // Wait for S_IREFST to indicate FLL Reference has switched to IRC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_IREFST_MASK) != (MCG_S_IREFST(1)));

            // Wait for S_CLKST to indicating that OUTCLK has switched to FLL
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(0));

            // Set FLL Parameters
            mcg->C4 = (mcg->C4&(MCG_C4_FCTRIM_MASK|MCG_C4_SCFTRIM_MASK))|McgInfo::MCG_C4;
            break;

         case McgInfo::ClockMode_FEE: // from FEI, FBI or FBE
            mcg->C1 =
                  MCG_C1_CLKS(0)           | // CLKS     = 0     -> Output of FLL is selected
                  MCG_C1_IREFS(0)          | // IREFS    = 0     -> External reference clock is FLL source
                  McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN

            // Wait for S_IREFST to indicate FLL Reference has switched to ERC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_IREFST_MASK) != (MCG_S_IREFST(0)));

            // Wait for S_CLKST to indicating that OUTCLK has switched to FLL
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(0));
            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_FBI: // from BLPI, FEI, FEE, FBE
            mcg->C1 =
                  MCG_C1_CLKS(1)           | // CLKS     = 1     -> Internal reference clock is selected
                  MCG_C1_IREFS(1)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN

            // Clear LP
            mcg->C2 = McgInfo::MCG_C2;

            // Wait for S_CLKST to indicating that OUTCLK has switched to IRC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(1));
            break;

         case McgInfo::ClockMode_FBE: // from FEI, FEE, FBI, PBE, BLPE
            // Clear LP
            mcg->C2 = McgInfo::MCG_C2;

            mcg->C1 =
                  MCG_C1_CLKS(2)           | // CLKS     = 2     -> External reference clock is selected
                  MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN

            // Select FLL as MCG clock source
            mcg->C6  = McgInfo::MCG_C6;

            // Wait for S_IREFST to indicate FLL Reference has switched to ERC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_IREFST_MASK) != (MCG_S_IREFST(0)));

            // Wait for S_CLKST to indicating that OUTCLK has switched to IRC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(2));

            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_PBE: // from FBE, BLPE, PEE
            // Clear LP
            mcg->C2 = McgInfo::MCG_C2;

            mcg->C1 =
                  MCG_C1_CLKS(2)           | // CLKS     = 2     -> External reference clock is selected
                  MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN

            // Select PLL as MCG clock source
            mcg->C6  = McgInfo::MCG_C6|MCG_C6_PLLS_MASK;
            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_PEE: // from PBE
            mcg->C1 =
                  MCG_C1_CLKS(0)           | // CLKS     = 0     -> Output of PLLCS is selected
                  MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN
            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_BLPE: // from FBE, PBE (registers differ depending on transition)
            externalClockInUse = true;
         case McgInfo::ClockMode_BLPI: // from FBI
            // Set LP
            mcg->C2 = McgInfo::MCG_C2|MCG_C2_LP_MASK;
            break;
         }
         // Wait for oscillator stable (if used)
         if (externalClockInUse && (McgInfo::MCG_C2&MCG_C2_EREFS0_MASK)) {
            do {
               __asm__("nop");
            } while ((MCG->S & MCG_S_OSCINIT0_MASK) == 0);
         }
         currentClockMode = next;
         if (transitionCount++>5) {
            return -1;
         }
      } while (currentClockMode != to);

      SIM->CLKDIV1 = McgInfo::SIM_CLKDIV1;
   }

   SystemCoreClockUpdate();
   return 0;
}

/**
 * Update SystemCoreClock variable
 *
 * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
 */
void Mcg::SystemCoreClockUpdate(void) {
   uint32_t oscerclk = 0;
   switch((MCG->C7&MCG_C7_OSCSEL_MASK)) {
      case (0<<MCG_C7_OSCSEL_SHIFT) : oscerclk = Osc0Info::oscclk_clock; break;
      case (1<<MCG_C7_OSCSEL_SHIFT) : oscerclk = RtcInfo::rtcclk_clock; break;
      case (2<<MCG_C7_OSCSEL_SHIFT) : oscerclk = McgInfo::irc48m_clock; break;
   }
   switch (MCG->S&MCG_S_CLKST_MASK) {
      case MCG_S_CLKST(0) : // FLL
         if ((MCG->C1&MCG_C1_IREFS_MASK) == 0) {
            // External reference clock is selected
            SystemCoreClock = oscerclk/(1<<((MCG->C1&MCG_C1_FRDIV_MASK)>>MCG_C1_FRDIV_SHIFT));
            if (((MCG->C2&MCG_C2_RANGE0_MASK) != 0) && ((MCG->C7&MCG_C7_OSCSEL_MASK) !=  1)) {
			   // High divisors
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
            // Slow internal reference clock is selected
            SystemCoreClock = McgInfo::system_slow_irc_clock;
         }
         SystemCoreClock *= (MCG->C4&MCG_C4_DMX32_MASK)?732:640;
         SystemCoreClock *= ((MCG->C4&MCG_C4_DRST_DRS_MASK)>>MCG_C4_DRST_DRS_SHIFT)+1;
         break;
      case MCG_S_CLKST(1) : // Internal Reference Clock
         if ((MCG->C2&MCG_C2_IRCS_MASK) != 0) {
            SystemCoreClock = McgInfo::system_fast_irc_clock/(1<<((MCG->SC&MCG_SC_FCRDIV_MASK)>>MCG_SC_FCRDIV_SHIFT));
         }
         else {
            SystemCoreClock = McgInfo::system_slow_irc_clock;
         }
         break;
      case MCG_S_CLKST(2) : // External Reference Clock
         SystemCoreClock = oscerclk;
         break;
      case MCG_S_CLKST(3) : // PLL
         SystemCoreClock  = (oscerclk/10)*(((MCG->C6&MCG_C6_VDIV0_MASK)>>MCG_C6_VDIV0_SHIFT)+24);
         SystemCoreClock /= ((MCG->C5&MCG_C5_PRDIV0_MASK)>>MCG_C5_PRDIV0_SHIFT)+1;
         SystemCoreClock *= 10;
         break;
   }
   SystemBusClock    = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV2_MASK)>>SIM_CLKDIV1_OUTDIV2_SHIFT)+1);
   SystemCoreClock   = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV1_MASK)>>SIM_CLKDIV1_OUTDIV1_SHIFT)+1);
}

/**
 * Sets up the clock out of RESET
 */
void Mcg::initialise(void) {

   currentClockMode = McgInfo::ClockMode::ClockMode_None;

   if (McgInfo::clockMode == McgInfo::ClockMode::ClockMode_None) {
      // No clock setup
      doClockGating();
      return;
   }

   if (McgInfo::MCG_C7&&MCG_C7_OSCSEL_MASK) {
      // Note IRC48M Internal Oscillator automatically enable if MCG_C7_OSCSEL = 2
      SIM->SCGC4 |= SIM_SCGC4_USBOTG_MASK;
      USB0->CLK_RECOVER_IRC_EN = USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK|USB_CLK_RECOVER_IRC_EN_REG_EN_MASK;
   }

   // Set PLL PRDIV0 etc
   MCG->C5  = McgInfo::MCG_C5;

   // Select OSCCLK Source
   MCG->C7 = McgInfo::MCG_C7; // OSCSEL = 0,1,2 -> XTAL/XTAL32/IRC48M

   // Set Fast Internal Clock divider
   MCG->SC = McgInfo::MCG_SC;

   // Transition to desired clock mode
   clockTransition(McgInfo::clockMode);

   doClockGating();
}

} // end namespace USBDM

/**
 * Sets up the clock out of RESET
 */
extern "C"
void clock_initialise(void) {

#ifdef USBDM_OSC0_IS_DEFINED
   USBDM::Osc0::initialise();
#endif

#ifdef USBDM_RTC_IS_DEFINED
   USBDM::Rtc::initialise();
#endif

#ifdef USBDM_MCG_IS_DEFINED
   USBDM::Mcg::initialise();
#endif

}

