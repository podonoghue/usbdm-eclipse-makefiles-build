/*
 * clock-cfv1plus.c
 *
 *  Used for CFV1-Plus
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

// Some MCUs call OSC_CR0 just OSC_CR
#ifndef OSC0_CR
#define OSC0_CR OSC_CR
#endif

#ifdef ENABLE_CLKOUT
void showClocks(void) {

   // Put SYSTEM_MCGOUTCLK_CLOCK on PTA5
   SIM->SCGC6 |= SIM_SCGC6_PORTA_MASK;
   MXC->PTAPF2 = (MXC->PTAPF2&~MXC_PTAPF2_A5_MASK)|MXC_PTAPF2_A5(6);
   /*
    * 0 Disabled (reset value)
    * 1 OSC1ERCLK (from OSC1)
    * 2 OSC2ERCLK (from OSC2)
    * 3 MCGOUTCLK
    * 4 CPUCLK/SYSCLK
    * 5 BUSCLK
    * 6 LPO
    * 7 LPTMR0 prescaler clock output
    */
   SIM->CLKOUT = SIM_CLKOUT_CS(5)|SIM_CLKOUT_CLKOUTDIV(0);
}
#endif

uint32_t SystemCoreClock = SYSTEM_CORE_CLOCK;   // Hz
uint32_t SystemBusClock  = SYSTEM_BUS_CLOCK; // Hz

/*! Sets up the clock out of RESET
 *!
 */
void clock_initialise(void) {
#ifdef ENABLE_CLKOUT
   showClocks();
#endif

#if (CLOCK_MODE == CLOCK_MODE_RESET)
   // No clock setup
#else
   // XTAL/EXTAL Pins
   SIM->SCGC6 |= SIM_SCGC6_PORTB_MASK;
   MXC->PTBPF1 = (MXC->PTBPF1&~MXC_PTBPF1_B6_MASK)|MXC_PTBPF1_B6(0);
   MXC->PTBPF2 = (MXC->PTBPF2&~MXC_PTBPF2_B5_MASK)|MXC_PTBPF2_B5(0);

   // Configure OSC2 (XTAL1/EXTAL1
   OSC1->CR = OSC1_CR_ERCLKEN_M|OSC1_CR_EREFSTEN_M|OSC1_CR_SCP_M;

   // Configure OSC2 (XTAL2/EXTAL2
   OSC2->CR = OSC2_CR_ERCLKEN_M|OSC2_CR_EREFSTEN_M|OSC2_CR_SCP_M;

   // Configure OSC1 (XTAL1/EXTAL1)
   SIM->OSC1_CNTRL = SIM_OSC1_OSC1EN_M|SIM_OSC1_OSC1RANGE_M|SIM_OSC1_OSC1HGO_M|SIM_OSC1_OSC1EREFS_M;

   // Out of reset MCG is in FEI mode
   // =============================================================

   // Switch from FEI -> FEI/FBI/FEE/FBE
   // =============================================================

   // Set up crystal or external clock source
   MCG->C2 = MCG_C2_RANGE_M     | // RANGE = 0,1,2 -> Oscillator low/high/very high clock range
            MCG_C2_HGO_M       | // HGO   = 0,1   -> Oscillator low power/high gain
            MCG_C2_EREFS_M     | // EREFS = 0,1   -> Select external clock/crystal oscillator
            MCG_C2_IRCS_M;       // IRCS  = 0,1   -> Select slow/fast internal clock for internal reference

   SIM->CLKDIV0 = SIM_CLKDIV0_OUTDIV(3);

#if ((CLOCK_MODE == CLOCK_MODE_FEI) || (CLOCK_MODE == CLOCK_MODE_FBI) || (CLOCK_MODE == CLOCK_MODE_BLPI) )
   // Transition via FBI
   //=====================================
#define BYPASS (1) // CLKS value used while FLL locks
   MCG->C1 =  MCG_C1_CLKS(BYPASS)     | // CLKS     = 1     -> Internal reference source while PLL locks
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
   } while ((MCG->S & MCG_S_OSCINIT_MASK) == 0);
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
   MCG->C5 =  MCG_C5_PLLCLKEN_M    |  // PLLCLKEN = 0,1 -> PLL -/enabled (irrespective of PLLS)
             MCG_C5_PLLSTEN_M     |  // PLLSTEN0 = 0,1 -> disabled/enabled in normal stop mode
             MCG_C5_PRDIV_M;         // PRDIV0   = N   -> PLL divider so PLL Ref. Freq. = 2-4 MHz

   // Transition via PBE
   // =============================================================
   MCG->C6 = MCG_C6_LOLIE_M    |
            MCG_C6_PLLS_M     |  // PLLS  = 0,1 -> Enable PLL
            MCG_C6_CME_M      |  // CME0  = 0,1 -> Disable/enable clock monitor
            MCG_C6_VDIV_M;       // VDIV0 = N   -> PLL Multiplication factor

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

#if (CLOCK_MODE == CLOCK_MODE_BLPE) || (CLOCK_MODE == CLOCK_MODE_BLPI)
   // Select BLPE/BLPI clock mode
   MCG->C2 =
            MCG_C2_LOCRE_M      | // LOCRE0 = 0,1   -> Loss of clock reset
            MCG_C2_RANGE_M      | // RANGE0 = 0,1,2 -> Oscillator low/high/very high clock range
            MCG_C2_HGO_M        | // HGO0   = 0,1   -> Oscillator low power/high gain
            MCG_C2_EREFS_M      | // EREFS0 = 0,1   -> Select external clock/crystal oscillator
            MCG_C2_LP_M         | // LP     = 0,1   -> Select FLL enabled/disabled in bypass mode
            MCG_C2_IRCS_M;        // IRCS   = 0,1   -> Select slow/fast internal clock for internal reference

#endif // (CLOCK_MODE == CLOCK_MODE_BLPE) || (CLOCK_MODE == CLOCK_MODE_BLPI)
#endif // (CLOCK_MODE == CLOCK_MODE_RESET)

   // Basic clock multiplexing
#if defined(MCU_mcf51jf128) || defined(MCU_mcf51ju128) || defined(MCU_MCF51JF) || defined(MCU_MCF51JU)
//   SIM_SOPT2 = SIM_SOPT2_UART0SRC_M      | // UART0 clock - 0,1,2,3 -> Disabled, (MCGFLLCLK, MCGPLLCLK/2),  OSCERCLK, MCGIRCLK
//               SIM_SOPT2_TPMSRC_M ;        // TPM2 source
#else
   #error "CPU not set"
#endif

#ifdef SIM_CLKDIV1_USBFRAC_MASK
   SIM->CLKDIV1 = SIM_CLKDIV1_USBDIV_M | SIM_CLKDIV1_USBFRAC_M | SIM_CLKDIV1_USBSRC_M;
#endif

   SIM->CLKDIV0 = SIM_CLKDIV0_M;

   SystemCoreClockUpdate();
}

/**
 * Update SystemCoreClock variable
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from CPU registers.
 */
void SystemCoreClockUpdate(void) {
   uint32_t oscerclk = OSC2CLK_CLOCK;
   switch (MCG->S&MCG_S_CLKST_MASK) {
      case MCG_S_CLKST(0) : // FLL
         if ((MCG->C1&MCG_C1_IREFS_MASK) == 0) {
            SystemCoreClock = oscerclk/(1<<((MCG->C1&MCG_C1_FRDIV_MASK)>>MCG_C1_FRDIV_SHIFT));
            if ((MCG->C2&MCG_C2_RANGE_MASK) != 0) {
               if ((MCG->C1&MCG_C1_FRDIV_M) == MCG_C1_FRDIV(6)) {
                  SystemCoreClock /= 20;
               }
               else if ((MCG->C1&MCG_C1_FRDIV_M) == MCG_C1_FRDIV(7)) {
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
            SystemCoreClock = SYSTEM_FAST_IRC_CLOCK/2;
         }
         else {
            SystemCoreClock = SYSTEM_SLOW_IRC_CLOCK;
         }
         break;
      case MCG_S_CLKST(2) : // External Reference Clock
         SystemCoreClock = oscerclk;
         break;
      case MCG_S_CLKST(3) : // PLL
         SystemCoreClock  = (oscerclk/10)*(((MCG->C6&MCG_C6_VDIV_MASK)>>MCG_C6_VDIV_SHIFT)+24);
         SystemCoreClock /= ((MCG->C5&MCG_C5_PRDIV_MASK)>>MCG_C5_PRDIV_SHIFT)+1;
         SystemCoreClock *= 10;
         break;
   }
   SystemCoreClock   = SystemCoreClock/(((SIM->CLKDIV0&SIM_CLKDIV0_OUTDIV_MASK)>>SIM_CLKDIV0_OUTDIV_SHIFT)+1);
   SystemBusClock    = SystemCoreClock/2;
}

