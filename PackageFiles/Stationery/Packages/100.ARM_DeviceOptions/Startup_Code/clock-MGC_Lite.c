/*
 *  clock-MCG_Lite.c
 *
 *  Used for MKL03, MKL27, MKL43
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

// Some MCUs call OSC0 just OSC
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
   SIM->SCGC5  |= SIM_SCGC5_PORTA_MASK;
   PORTA->PCR[18] = PORT_PCR_MUX(0);
   PORTA->PCR[19] = PORT_PCR_MUX(0);

   // Configure the Crystal Oscillator
   OSC0->CR = OSC_CR_ERCLKEN_M|OSC_CR_EREFSTEN_M|OSC_CR_SCP_M;

#if defined(RTC_CR_OSCE_M) && defined(RTC_CR_OSCE_V)
   SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;
   RTC->CR = RTC_CR_SCP_M|RTC_CR_CLKO_M|RTC_CR_OSCE_M|RTC_CR_SCP_M|RTC_CR_WPS_M|RTC_CR_UM_M|RTC_CR_SUP_M|RTC_CR_WPE_M;
#endif

#if !defined(MCG_MC_HIRCEN_M)
#define MCG_MC_HIRCEN_M (0)
#endif

#if defined(MCG_MC_HIRCEN_M)
   MCG->MC = MCG_MC_HIRCEN_M|MCG_MC_HIRCEN_M|MCG_MC_LIRC_DIV2_M;
#endif

   // Fast Internal Clock divider
   MCG->SC = MCG_SC_FCRDIV_M;

   // Out of reset MCG is in LIRC mode
   // =============================================================

   // Set conservative SIM clock dividers BEFORE switching to ensure the clock speed remain within specification
   SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1(3) | SIM_CLKDIV1_OUTDIV2(7) | SIM_CLKDIV1_OUTDIV3(3) | SIM_CLKDIV1_OUTDIV4(7);

   // Switch from LIRC -> LIRC/HIRC/EXT
   // =============================================================

   // Transition via HIRC
   //=====================================
#define HIRC_BYPASS (0) // HIRC mode used while LIRC mode changed
   MCG->C1 =  MCG_C1_CLKS(HIRC_BYPASS) | // CLKS     = X     -> HIRC source while PLL locks
              MCG_C1_IRCLKEN_M         | // IRCLKEN  = 0,1   -> IRCLK disable/enable
              MCG_C1_IREFSTEN_M;         // IREFSTEN = 0,1   -> Internal reference enabled in STOP mode

   // Wait for S_CLKST to indicating that OUTCLK has switched to bypass HIRC
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(HIRC_BYPASS));

   // Set up crystal or external clock source & select final IRC mode
   MCG->C2 =
#ifdef MCG_C2_RANGE0_M
            MCG_C2_RANGE0_M     | // RANGE0 = 0,1,2 -> Oscillator low/high/very high clock range
            MCG_C2_HGO0_M       | // HGO0   = 0,1   -> Oscillator low power/high gain
#endif
            MCG_C2_EREFS0_M     | // EREFS0 = 0,1   -> Select external clock/crystal oscillator
            MCG_C2_IRCS_M;        // IRCS   = 0,1   -> Select 8/4 MHz internal clock for internal reference

#if (RTC_CR_OSCE_V != 0) || (MCG_C2_EREFS0_V != 0)
   // Wait for oscillator stable (if used)
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_OSCINIT0_MASK) == 0);
#endif

   // Transition to final LIRC/HIRC/EXT/LIRC clock mode
   //=====================================
   MCG->C1 =  MCG_C1_CLKS_M        | // CLKS     = 0,1,2 -> Select FLL/IRCSCLK/ERCLK
              MCG_C1_IRCLKEN_M     | // IRCLKEN  = 0,1   -> IRCLK disable/enable
              MCG_C1_IREFSTEN_M;     // IREFSTEN = 0,1   -> Internal reference enabled in STOP mode

   // Wait for S_CLKST to indicating that OUTCLK has switched to final mode
   do {
      __asm__("nop");
   } while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(MCG_C1_CLKS_V));

   // Set the SIM _CLKDIV dividers
   SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1_M | SIM_CLKDIV1_OUTDIV2_M | SIM_CLKDIV1_OUTDIV3_M | SIM_CLKDIV1_OUTDIV4_M;

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

#if defined(SIM_SOPT2_LPUART0SRC_MASK) && defined(SIM_SOPT2_LPUART0SRC_M) // LPUART0 clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_LPUART0SRC_MASK)| SIM_SOPT2_LPUART0SRC_M;
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
   uint32_t oscerclk = OSCCLK_CLOCK;
   switch (MCG->S&MCG_S_CLKST_MASK) {
      case MCG_S_CLKST(0) : // HIRC
         SystemCoreClock = IRC48M_CLOCK;
         break;
      case MCG_S_CLKST(1) : // LIRC
         if ((MCG->C2&MCG_C2_IRCS_MASK) != 0) {
            SystemCoreClock = IRC8M_CLOCK;
         }
         else {
            SystemCoreClock = IRC2M_CLOCK;
         }
         break;
      case MCG_S_CLKST(2) : // External Reference Clock
         SystemCoreClock = oscerclk;
         break;
   }
   SystemCoreClock   = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV1_MASK)>>SIM_CLKDIV1_OUTDIV1_SHIFT)+1);
   SystemBusClock    = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV4_MASK)>>SIM_CLKDIV1_OUTDIV4_SHIFT)+1);
}

