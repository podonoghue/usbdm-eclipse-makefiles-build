/*
 * clock-MK22F512M12.c
 *
 *  Used for MK22FN512M12
 *
 * Based on K22P121M120SF7RM
 *   3 Oscillators (OSC0, RTC, IRC48M)
 *   1 FLL (OSC0, RTC, IRC48M), (FRDIV=/1-/128, /32-/1024, /1280, 1536)
 *   2 PLL (OSC0, RTC, IRC48M), (VCO PRDIV=/1-/24, VDIV=x24-x55)
 *
 * Used with:
 *   clock_private-MK64M12.h
 *
 *  Created on: 04/03/2012
 *      Author: podonoghue
 */
#include "string.h"
#include "derivative.h" /* include peripheral declarations */
#include "system.h"
#include "clock_configure.h"
#include "utilities.h"
#include "stdbool.h"
#include "pin_mapping.h"

using namespace USBDM;

// Some MCUs call OSC0 just OSC
#ifndef OSC0
#define OSC0 OSC
#endif

uint32_t SystemCoreClock = SYSTEM_CORE_CLOCK;   // Hz
uint32_t SystemBusClock  = SYSTEM_BUS_CLOCK; // Hz

/*!
 * Switch to/from high speed run mode
 * Changes the CPU clock frequency/1, and bus clock frequency /2
 * If the clock is set up for 120 MHz this will be the highest performance possible.
 *
 * This routine assumes that the clock preferences have been set up for the usual RUN mode and only
 * the Core clock divider needs to be changed.
 */
void hsRunMode(bool enable) {
   SMC->PMPROT = SMC_PMPROT_AHSRUN_MASK;

   if (enable) {
      SMC->PMCTRL = SMC_PMCTRL_RUNM(3);
      while ((SMC->PMSTAT & 0x80) == 0) {
         // Wait for mode change
         __asm__("nop");
      }
      // Set the SIM _CLKDIV dividers (CPU /1, Bus /2)
      SIM->CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(0)) | (SIM_CLKDIV1_OUTDIV2(1)) | SIM_CLKDIV1_OUTDIV3_M | SIM_CLKDIV1_OUTDIV4_M;
   }
   else {
      // Set the SIM _CLKDIV dividers (CPU normal)
      SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1_M | SIM_CLKDIV1_OUTDIV2_M | SIM_CLKDIV1_OUTDIV3_M | SIM_CLKDIV1_OUTDIV4_M;
      SMC->PMCTRL = SMC_PMCTRL_RUNM(0);
   }
   SystemCoreClockUpdate();
}

static void doClockGating() {

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

/** Current clock mode (FEI out of reset) */
McgInfo::ClockMode currentClockMode = McgInfo::ClockMode::ClockMode_FEI;

static constexpr uint8_t clockTransitionTable[8][8] = {
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
 * @param to CLock mode to transition to
 */
int clockTransition(McgInfo::ClockMode to) {
   constexpr volatile MCG_Type* mcg = (volatile MCG_Type*)McgInfo::basePtr;

   if (to == McgInfo::ClockMode_None) {
      return -1;
   }
   int transitionCount = 0;
   if (currentClockMode == McgInfo::ClockMode_None) {
      currentClockMode = McgInfo::ClockMode_FEI;
      mcg->C2 = McgInfo::MCG_C2;
   }
   do {
      McgInfo::ClockMode next = (McgInfo::ClockMode)clockTransitionTable[currentClockMode][to];
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
         mcg->C4 = (mcg->C4&~(MCG_C4_DMX32_MASK|MCG_C4_DRST_DRS_MASK))|McgInfo::MCG_C4;
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

         break;

      case McgInfo::ClockMode_FBI: // from BLPI, FEI, FEE, FBE
         mcg->C1 =
               MCG_C1_CLKS(1)           | // CLKS     = 1     -> Internal reference clock is selected
               MCG_C1_IREFS(1)          | // IREFS    = 1     -> Slow IRC for FLL source
               McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN

         mcg->C2 &= ~MCG_C2_LP_MASK;

         // Wait for S_CLKST to indicating that OUTCLK has switched to IRC
         do {
            __asm__("nop");
         } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(1));
         break;

      case McgInfo::ClockMode_FBE: // from FEI, FEE, FBI, PBE, BLPE
         mcg->C1 =
               MCG_C1_CLKS(2)           | // CLKS     = 2     -> External reference clock is selected
               MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
               McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN

         mcg->C2 &= ~MCG_C2_LP_MASK;
         // Select FLL as MCG clock source
         mcg->C6 &= ~MCG_C6_PLLS_M;
         break;

      case McgInfo::ClockMode_PBE: // from FBE, BLPE, PEE
         mcg->C1 =
               MCG_C1_CLKS(2)           | // CLKS     = 2     -> External reference clock is selected
               MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
               McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN
         mcg->C2 &= ~MCG_C2_LP_MASK;
         // Select PLL as MCG clock source
         mcg->C6 |= MCG_C6_PLLS_M;

         mcg->C5  = McgInfo::MCG_C5;
         mcg->C6  = McgInfo::MCG_C6;
         break;

      case McgInfo::ClockMode_PEE: // from PEE
         mcg->C1 =
               MCG_C1_CLKS(0)           | // CLKS     = 0     -> Output of PLLCS is selected
               MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
               McgInfo::MCG_C1;           // FRDIV, IRCLKEN, IREFSTEN
         break;

      case McgInfo::ClockMode_BLPI: // from FBI
         mcg->C2 |= MCG_C2_LP_MASK;
         break;

      case McgInfo::ClockMode_BLPE: // from FBE, PBE (registers differ depending on transition)
         mcg->C2 |= MCG_C2_LP_MASK;
         break;
      }
      currentClockMode = next;
      if (transitionCount++>5) {
         return -1;
      }
   } while (currentClockMode != to);
   return 0;
}

static void osc_initialise() {
#ifdef USBDM_OSC0_IS_DEFINED
   {
      constexpr volatile OSC_Type* osc = (volatile OSC_Type*)Osc0Info::basePtr;

      // XTAL/EXTAL Pins
      USBDM::Osc0Info::initPCRs();

      // Configure the Crystal Oscillator
      osc->CR  = USBDM::Osc0Info::OSC_CR;
#ifdef OSC_DIV_ERPS_MASK
      osc->DIV = USBDM::Osc0Info::OSC_DIV;
#endif
   }
#endif // USBDM_OSC0_IS_DEFINED
}

static void rtc_initialise() {
#ifdef USBDM_RTC_IS_DEFINED
   {
      constexpr volatile uint32_t* rtcClockReg = (volatile uint32_t*)RtcInfo::clockReg;
      constexpr volatile RTC_Type* rtc         = (volatile RTC_Type*)RtcInfo::basePtr;

      // XTAL32/EXTAL32 Pins
      USBDM::RtcInfo::initPCRs();

      // Configure the RTC Crystal Oscillator
      *rtcClockReg |= USBDM::RtcInfo::clockMask;
      rtc->CR       = USBDM::RtcInfo::RTC_CR;
   }
#endif // USBDM_RTC_IS_DEFINED
}

/*! @brief Sets up the clock out of RESET
 *
 */
void clock_initialise(void) {

   currentClockMode = McgInfo::ClockMode::ClockMode_None;

   osc_initialise();
   rtc_initialise();


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

   // Select OSCCLK Source
   MCG->C7 = McgInfo::MCG_C7; // OSCSEL = 0,1,2 -> XTAL/XTAL32/IRC48M

   // Fast Internal Clock divider
   MCG->SC = McgInfo::MCG_SC;

   clockTransition(McgInfo::clockMode);

   doClockGating();
   return;

#if 0

   // Out of reset MCG is in FEI mode
   // =============================================================

   // Set conservative SIM clock dividers BEFORE switching to ensure the clock speed remain within specification
   SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1(3) | SIM_CLKDIV1_OUTDIV2(7) | SIM_CLKDIV1_OUTDIV3(3) | SIM_CLKDIV1_OUTDIV4(7);

   clockTransition(McgInfo::ClockMode_FEI);

   doClockGating();
   SystemCoreClockUpdate();
   return;

   // Switch from FEI -> FEI/FBI/FEE/FBE
   // =============================================================

   // Set up crystal or external clock source for OSC0
   MCG->C2 =
         MCG_C2_LOCRE0_M     | // LOCRE0 = 0,1   -> Loss of clock reset enable
         MCG_C2_RANGE0_M     | // RANGE0 = 0,1,2 -> Oscillator low/high/very high clock range
         MCG_C2_HGO0_M       | // HGO0   = 0,1   -> Oscillator low power/high gain
         MCG_C2_EREFS0_M     | // EREFS0 = 0,1   -> Select external clock/crystal oscillator
         MCG_C2_IRCS_M;        // IRCS   = 0,1   -> Select slow/fast internal clock for internal reference

   // Set up RTC clock monitor
   MCG->C8 = MCG_C8_LOCRE1_M |    // LOCRE1 = 0,1 -> Loss of Lock Reset enable
         MCG_C8_CME1_M;       // CME1   = 0,1 -> Clock monitor enable

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
   MCG->C5 =   MCG_C5_PLLCLKEN0_M    |  // PLLCLKEN0  = 0,1 -> PLL -/enabled (irrespective of PLLS)
         MCG_C5_PLLSTEN0_M     |  // PLLSTEN0   = 0,1 -> disabled/enabled in normal stop mode
         MCG_C5_PRDIV0_M;         // PRDIV0     = N   -> PLL divider so PLL Ref. Freq. = 2-4 MHz

   // Transition via PBE
   // =============================================================
   MCG->C6 = MCG_C6_LOLIE0_M    |  // LOLIE0 = 0,1 -> Loss of Lock interrupt
         MCG_C6_PLLS_M      |  // PLLS   = 0,1 -> Enable PLL
         MCG_C6_CME0_M      |  // CME0   = 0,1 -> Disable/enable clock monitor
         MCG_C6_VDIV0_M;       // VDIV0  = N   -> PLL Multiplication factor

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
   SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1_M | SIM_CLKDIV1_OUTDIV2_M | SIM_CLKDIV1_OUTDIV3_M | SIM_CLKDIV1_OUTDIV4_M;

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
#endif
}

/*!
 * @brief Update SystemCoreClock variable
 *
 * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
 */
void SystemCoreClockUpdate(void) {
   uint32_t oscerclk = 0;
   switch((MCG->C7&MCG_C7_OSCSEL_MASK)) {
   case (0<<MCG_C7_OSCSEL_SHIFT) : oscerclk = OSCCLK_CLOCK; break;
   case (1<<MCG_C7_OSCSEL_SHIFT) : oscerclk = RTCCLK_CLOCK; break;
   case (2<<MCG_C7_OSCSEL_SHIFT) : oscerclk = IRC48M_CLOCK; break;
   }
   switch (MCG->S&MCG_S_CLKST_MASK) {
   case MCG_S_CLKST(0) : // FLL
               SystemCoreClock = (MCG->C4&MCG_C4_DMX32_MASK)?732:640;
   if ((MCG->C1&MCG_C1_IREFS_MASK) == 0) {
      SystemCoreClock *= oscerclk/(1<<((MCG->C1&MCG_C1_FRDIV_MASK)>>MCG_C1_FRDIV_SHIFT));
      if (((MCG->C2&MCG_C2_RANGE0_MASK) != 0) && ((MCG->C7&MCG_C7_OSCSEL_MASK) !=  1)) {
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
      SystemCoreClock *= SYSTEM_SLOW_IRC_CLOCK;
   }
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
               SystemCoreClock  = (oscerclk/10)*(((MCG->C6&MCG_C6_VDIV0_MASK)>>MCG_C6_VDIV0_SHIFT)+24);
   SystemCoreClock /= ((MCG->C5&MCG_C5_PRDIV0_MASK)>>MCG_C5_PRDIV0_SHIFT)+1;
   SystemCoreClock *= 10;
   break;
   }
   SystemBusClock    = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV2_MASK)>>SIM_CLKDIV1_OUTDIV2_SHIFT)+1);
   SystemCoreClock   = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV1_MASK)>>SIM_CLKDIV1_OUTDIV1_SHIFT)+1);
}
