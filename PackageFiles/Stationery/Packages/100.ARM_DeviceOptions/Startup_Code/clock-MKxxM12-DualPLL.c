/*
 * clock-MKxxM12-DualPLL.c
 *
 * Based on K60P144M150SF3RM
 *   3 Oscillators (OSC0, OSC1, OSC2=RTC)
 *   1 FLL (OSC0 or OSC2=RTC), (FRDIV=/1-/128, /32-/1024)
 *   2 PLLs (OSC0, OSC1), (VCO PRDIV=/1-/8, VDIV=x16-x47)
 *
 * Used with:
 *   clock_private-MKxxM12-DualPLL.h
 *
 *  Created on: 13/7/2012
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
   // XTAL0/EXTAL0 Pins
   // Shouldn't be needed as default
//   SIM->SCGC5  |= SIM_SCGC5_PORTA_MASK;
//   PORTA->PCR[18] = PORT_PCR_MUX(0);
//   PORTA->PCR[19] = PORT_PCR_MUX(0);

   // Configure the Crystal Oscillators
   OSC0->CR    = OSC0_CR_ERCLKEN_M|OSC0_CR_EREFSTEN_M|OSC0_CR_SCP_M;

   // XTAL/EXTAL Pins
   // Shouldn't be needed as default
//   SIM->SCGC5  |= SIM_SCGC5_PORTE_MASK;
//   PORTE_PCR24 = PORT_PCR_MUX(0);
//   PORTE_PCR25 = PORT_PCR_MUX(0);

   SIM->SCGC1 |= SIM_SCGC1_OSC1_MASK;
   OSC1->CR    = OSC1_CR_ERCLKEN_M|OSC1_CR_EREFSTEN_M|OSC1_CR_SCP_M;

#if (MCG_C7_OSCSEL_V != 0)
   SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;

   // Configure the RTC Crystal Oscillator
   RTC->CR = RTC_CR_SCP_M|RTC_CR_CLKO_M|RTC_CR_OSCE_M|RTC_CR_UM_M|RTC_CR_SUP_M|RTC_CR_WPE_M;
#endif

   // Select OSCCLK Source
   MCG->C7 = MCG_C7_OSCSEL_M; // OSCSEL = 0,1 -> XTAL/XTAL32

   // Fast Internal Clock divider
   MCG->SC = MCG_SC_FCRDIV_M;

   // Out of reset MCG is in FEI mode
   // =============================================================

   // Set conservative SIM clock dividers BEFORE switching to ensure the clock speed remain within specification
   SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1(3) | SIM_CLKDIV1_OUTDIV2(7) | SIM_CLKDIV1_OUTDIV3(3) | SIM_CLKDIV1_OUTDIV4(7);

   // Switch from FEI -> FEI/FBI/FEE/FBE
   // =============================================================

   // Set up crystal or external clock source for OSC0
   MCG->C2 = 
            MCG_C2_LOCRE0_M     | // LOCRE0 = 0,1   -> Loss of clock reset enable
            MCG_C2_RANGE0_M     | // RANGE0 = 0,1,2 -> Oscillator low/high/very high clock range
            MCG_C2_HGO0_M       | // HGO0   = 0,1   -> Oscillator low power/high gain
            MCG_C2_EREFS0_M     | // EREFS0 = 0,1   -> Select external clock/crystal oscillator
            MCG_C2_IRCS_M;        // IRCS   = 0,1   -> Select slow/fast internal clock for internal reference

   // Set up crystal or external clock source for OSC1
   MCG->C10 = MCG_C10_LOCRE2_M     | // LOCRE1 = 0,1   -> Loss of clock reset enable
              MCG_C10_RANGE1_M     | // RANGE1 = 0,1,2 -> Oscillator low/high/very high clock range
              MCG_C10_HGO1_M       | // HGO1   = 0,1   -> Oscillator low power/high gain
              MCG_C10_EREFS1_M;      // EREFS1 = 0,1   -> Select external clock/crystal oscillator

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

#if (MCG_C2_EREFS0_V != 0)
   // Wait for oscillator 0 stable (if used)
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_OSCINIT0_MASK) == 0);
#endif

#if (MCG_C10_EREFS1_V != 0)
   // Wait for oscillator 1 stable (if used)
   do {
      __asm__("nop");
   } while ((MCG->S2 & MCG_S2_OSCINIT1_MASK) == 0);
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

   // Configure PLL0 Reference Frequency
   // =============================================================
   MCG->C5 =   MCG_C5_PLLREFSEL0_M   |  // PLLREFSEL0 = 0,1 -> OSC0/OSC1 select
               MCG_C5_PLLCLKEN0_M    |  // PLLCLKEN0  = 0,1 -> PLL -/enabled (irrespective of PLLS)
               MCG_C5_PLLSTEN0_M     |  // PLLSTEN0   = 0,1 -> disabled/enabled in normal stop mode
               MCG_C5_PRDIV0_M;         // PRDIV0     = N   -> PLL divider so PLL Ref. Freq. = 8-16 MHz

   // Configure PLL1 Reference Frequency
   // =============================================================
   MCG->C11 =  MCG_C11_PLLREFSEL1_M   |  // PLLREFSEL1 = 0,1 -> OSC0/OSC1 select
               MCG_C11_PLLCLKEN1_M    |  // PLLCLKEN   = 0,1 -> PLL -/enabled (irrespective of PLLS)
               MCG_C11_PLLSTEN1_M     |  // PLLSTEN0   = 0,1 -> disabled/enabled in normal stop mode
               MCG_C11_PLLCS_M        |  // PLLCS      = 0,1 -> PLL0/PLL1 used as MCG source
               MCG_C11_PRDIV1_M;         // PRDIV0     = N   -> PLL divider so PLL Ref. Freq. = 8-16 MHz

   // Set up PLL0
   // =============================================================
   MCG->C6 = MCG_C6_LOLIE0_M    |  // LOLIE0 = 0,1 -> Loss of Lock interrupt
             MCG_C6_PLLS_M      |  // PLLS   = 0,1 -> Enable PLL
             MCG_C6_CME0_M      |  // CME0   = 0,1 -> Disable/enable clock monitor
             MCG_C6_VDIV0_M;       // VDIV0  = N   -> PLL Multiplication factor

   // Set up PLL1
   // =============================================================
   MCG->C12 = MCG_C12_LOLIE1_M    |  // LOLIE1 = 0,1 -> Loss of Lock interrupt
              MCG_C12_CME2_M      |  // CME2   = 0,1 -> Disable/enable clock monitor
              MCG_C12_VDIV1_M;       // VDIV1  = N   -> PLL Multiplication factor


#if ((CLOCK_MODE == CLOCK_MODE_PBE) || (CLOCK_MODE == CLOCK_MODE_PEE))
   // Transition via PBE
   // =============================================================

#if (MCG_C11_PLLCS_M == 0)
   // Wait for PLL0 to lock
   do {
      __asm__("nop");
   } while((MCG->S & MCG_S_LOCK0_MASK) == 0);
#else
   // Wait for PLL1 to lock
   do {
      __asm__("nop");
   } while((MCG->S2 & MCG_S2_LOCK1_MASK) == 0);
#endif
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
#endif // (CLOCK_MODE == CLOCK_MODE_NONE)


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

/*!
 * @brief Update SystemCoreClock variable
 *
 * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
 */
void SystemCoreClockUpdate(void) {
   uint32_t oscerclk = (MCG->C7&MCG_C7_OSCSEL_MASK)?RTCCLK_CLOCK:OSCCLK0_CLOCK;
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
         if ((MCG->C11&MCG_C11_PLLCS_MASK) == 0) {
            // PLL0
            if ((MCG->C11&MCG_C11_PLLREFSEL1_MASK)==0) {
               // OCS0
               oscerclk = OSCCLK0_CLOCK;
            }
            else {
               // OSC1
               oscerclk = OSCCLK1_CLOCK;
            }
            SystemCoreClock  = (oscerclk/10)*(((MCG->C6&MCG_C6_VDIV0_MASK)>>MCG_C6_VDIV0_SHIFT)+16);
            SystemCoreClock /= ((MCG->C5&MCG_C5_PRDIV0_MASK)>>MCG_C5_PRDIV0_SHIFT)+1;
         }
         else {
            // PLL1
            if ((MCG->C5&MCG_C5_PLLREFSEL0_MASK)==0) {
               // OCS0
               oscerclk = OSCCLK0_CLOCK;
            }
            else {
               // OSC1
               oscerclk = OSCCLK1_CLOCK;
            }
            SystemCoreClock  = (oscerclk/10)*(((MCG->C12&MCG_C12_VDIV1_MASK)>>MCG_C12_VDIV1_SHIFT)+16);
            SystemCoreClock /= ((MCG->C11&MCG_C11_PRDIV1_MASK)>>MCG_C11_PRDIV1_SHIFT)+1;
         }
         SystemCoreClock *= 10;
         break;
   }
   SystemBusClock    = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV2_MASK)>>SIM_CLKDIV1_OUTDIV2_SHIFT)+1);
   SystemCoreClock   = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV1_MASK)>>SIM_CLKDIV1_OUTDIV1_SHIFT)+1);
}

