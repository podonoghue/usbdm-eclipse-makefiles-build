/*
 * clock-cfv1.c
 *
 *  Used for CFV1
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

   // Out of reset MCG is in FEI mode
   // =============================================================

   // Switch from FEI -> FEI/FBI/FEE/FBE
   // =============================================================

   // Set up crystal or external clock source
   MCGC2 = MCGC2_BDIV_M      | // BDIV  =
           MCGC2_RANGE_M     | // RANGE = 0,1,2 -> Oscillator low/high/very high clock range
           MCGC2_HGO_M       | // HGO   = 0,1   -> Oscillator low power/high gain
           MCGC2_EREFS_M     | // EREFS = 0,1   -> Select external clock/crystal oscillator
           MCGC2_ERCLKEN_M   | //
           MCGC2_EREFSTEN_M;   //

#if ((CLOCK_MODE == CLOCK_MODE_FEI) || (CLOCK_MODE == CLOCK_MODE_FBI) || (CLOCK_MODE == CLOCK_MODE_BLPI) )
   // Transition via FBI
   //=====================================
#define BYPASS (1) // CLKS value used while FLL locks
   MCGC1 =  (BYPASS<<MCGC1_CLKS_BITNUM)     | // CLKS     = 1     -> Internal reference source while PLL locks
            MCGC1_RDIV_M                    | // FRDIV    = N     -> XTAL/2^n ~ 31.25 kHz
            MCGC1_IREFS_M                   | // IREFS    = 0,1   -> External/Slow IRC for FLL source
            MCGC1_IRCLKEN_M                 | // IRCLKEN  = 0,1   -> IRCLK disable/enable
            MCGC1_IREFSTEN_M;                 // IREFSTEN = 0,1   -> Internal reference enabled in STOP mode

   // Wait for S_IREFST to indicate FLL Reference has switched
   do {
      __asm__("nop");
   } while ((MCGSC & MCGSC_IREFST_MASK) != (MCGC1_IREFS_V?MCGSC_IREFST_MASK:0));

   // Wait for S_CLKST to indicating that OUTCLK has switched to bypass PLL/FLL
   do {
      __asm__("nop");
   } while ((MCGSC & MCGSC_CLKST_MASK) != (BYPASS<<MCGSC_CLKST_BITNUM));

   // Set FLL Parameters
   MCGC4 = (MCGC4&~(MCGC4_DMX32_MASK|MCGC4_DRST_DRS_MASK))|MCGC4_DMX32_M|MCGC4_DRS_M;
#endif

#if ((CLOCK_MODE == CLOCK_MODE_FBE) || (CLOCK_MODE == CLOCK_MODE_FEE) || (CLOCK_MODE == CLOCK_MODE_PLBE) || (CLOCK_MODE == CLOCK_MODE_PBE) || (CLOCK_MODE == CLOCK_MODE_PEE))

   // Transition via FBE
   //=====================================
#define BYPASS (2) // CLKS value used while PLL locks
   MCGC1 =  (BYPASS<<MCGC1_CLKS_BITNUM)     | // CLKS     = 2     -> External reference source while PLL locks
             MCGC1_RDIV_M                   | // FRDIV    = N     -> XTAL/2^n ~ 31.25 kHz
             MCGC1_IREFS_M                  | // IREFS    = 0,1   -> External/Slow IRC for FLL source
             MCGC1_IRCLKEN_M                | // IRCLKEN  = 0,1   -> IRCLK disable/enable
             MCGC1_IREFSTEN_M;                // IREFSTEN = 0,1   -> Internal reference enabled in STOP mode

#if (MCGC2_EREFS_V != 0)
   // Wait for oscillator stable (if used)
   do {
      __asm__("nop");
   } while ((MCGSC & MCGSC_OSCINIT_MASK) == 0);
#endif

   // Wait for S_IREFST to indicate FLL Reference has switched
   do {
      __asm__("nop");
   } while ((MCGSC & MCGSC_IREFST_MASK) != (MCGC1_IREFS_V?MCGSC_IREFST_MASK:0));

   // Wait for S_CLKST to indicating that OUTCLK has switched to bypass PLL/FLL
   do {
      __asm__("nop");
   } while ((MCGSC & MCGSC_CLKST_MASK) != (BYPASS<<MCGSC_CLKST_BITNUM));

   // Set FLL Parameters
   MCGC4 = (MCGC4&~(MCGC4_DMX32_MASK|MCGC4_DRST_DRS_MASK))|MCGC4_DMX32_M|MCGC4_DRS_M;
#endif

#if ((CLOCK_MODE == CLOCK_MODE_PBE) || (CLOCK_MODE == CLOCK_MODE_PEE))

   // Transition via PBE
   // =============================================================
   MCGC3 = MCGC3_LOLIE_M    |
            MCGC3_PLLS_M    |  // PLLS  = 0,1 -> Enable PLL
            MCGC3_CME_M     |  // CME0  = 0,1 -> Disable/enable clock monitor
            MCGC3_VDIV_M;      // VDIV0 = N   -> PLL Multiplication factor

   // Wait for PLL to lock
   do {
      __asm__("nop");
   } while((MCGSC & MCGSC_LOCK_MASK) == 0);

   // Wait until PLLS clock source changes to the PLL clock out
   do {
      __asm__("nop");
   } while((MCGSC & MCGSC_PLLST_MASK) == 0);

#endif

#if ((CLOCK_MODE == CLOCK_MODE_FEI) || (CLOCK_MODE == CLOCK_MODE_FEE))
   // Wait for FLL to lock
   do {
      __asm__("nop");
   } while ((MCGC4&MCGC4_DRST_DRS_MASK) != MCGC4_DRS_M);
#endif


   // Select FEI/FBI/FEE/FBE/PBE/PEE clock mode
   MCGC1 =  MCGC1_CLKS_M        | // CLKS     = 0,1,2 -> Select FLL/IRCSCLK/ERCLK
            MCGC1_RDIV_M       | // RDIV    = N     -> XTAL/2^n ~ 31.25 kHz
            MCGC1_IREFS_M      | // IREFS    = 0,1   -> External/Slow IRC for FLL source
            MCGC1_IRCLKEN_M    | // IRCLKEN  = 0,1   -> IRCLK disable/enable
            MCGC1_IREFSTEN_M;    // IREFSTEN = 0,1   -> Internal reference enabled in STOP mode

   // Wait for mode change
   do {
      __asm__("nop");
   } while ((MCGSC & MCGSC_IREFST_MASK) != (MCGC1_IREFS_V?MCGSC_IREFST_MASK:0));

#if defined (MCGC3_PLLS_V) && (MCGC1_CLKS_V == 0) // FLL or PLL
#define MCGSC_CLKST_M ((MCGC3_PLLS_V?3:0)<<MCGSC_CLKST_BITNUM)
#else
   #define MCGSC_CLKST_M (MCGC1_CLKS_V<<MCGSC_CLKST_BITNUM)
#endif

   // Wait for S_CLKST to indicating that OUTCLK has switched
   do {
      __asm__("nop");
   } while ((MCGSC & MCGSC_CLKST_MASK) != MCGSC_CLKST_M);

#if (CLOCK_MODE == CLOCK_MODE_BLPE) || (CLOCK_MODE == CLOCK_MODE_BLPI)
   // Select BLPE/BLPI clock mode
   MCGC2 =
            MCGC2_LOCRE_M      | // LOCRE0 = 0,1   -> Loss of clock reset
            MCGC2_RANGE_M      | // RANGE0 = 0,1,2 -> Oscillator low/high/very high clock range
            MCGC2_HGO_M        | // HGO0   = 0,1   -> Oscillator low power/high gain
            MCGC2_EREFS_M      | // EREFS0 = 0,1   -> Select external clock/crystal oscillator
            MCGC2_LP_M         | // LP     = 0,1   -> Select FLL enabled/disabled in bypass mode
            MCGC2_IRCS_M;        // IRCS   = 0,1   -> Select slow/fast internal clock for internal reference

#endif // (CLOCK_MODE == CLOCK_MODE_BLPE) || (CLOCK_MODE == CLOCK_MODE_BLPI)
#endif // (CLOCK_MODE == CLOCK_MODE_RESET)

   // Basic clock multiplexing
#if defined(MCU_mcf51jm128)
//   SIM_SOPT2 = SIM_SOPT2_UART0SRC_M      | // UART0 clock - 0,1,2,3 -> Disabled, (MCGFLLCLK, MCGPLLCLK/2),  OSCERCLK, MCGIRCLK
//               SIM_SOPT2_TPMSRC_M ;        // TPM2 source
#else
   #error "Modify as required"
#endif

#ifdef SIM_CLKDIV1_USBFRAC_MASK
   SIM->CLKDIV1 = SIM_CLKDIV1_USBDIV_M | SIM_CLKDIV1_USBFRAC_M | SIM_CLKDIV1_USBSRC_M;
#endif

#ifdef SIM->CLKDIV0
   SIM->CLKDIV0 = SIM_CLKDIV0_M;
#endif

   SystemCoreClockUpdate();
}

/**
 * Update SystemCoreClock variable
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from CPU registers.
 */
void SystemCoreClockUpdate(void) {
   uint32_t oscerclk = OSCCLK_CLOCK;
   switch (MCGSC&MCGSC_CLKST_MASK) {
      case 0<<MCGSC_CLKST_BITNUM : // FLL
         if ((MCGC1&MCGC1_IREFS_MASK) == 0) {
            SystemCoreClock = oscerclk/(1<<((MCGC1&MCGC1_RDIV_MASK)>>MCGC1_RDIV_BITNUM));
            if ((MCGC2&MCGC2_RANGE_MASK) != 0) {
               // Assume RDIV not 6 or 7
               SystemCoreClock /= 32;
            }
         }
         else {
            SystemCoreClock = SYSTEM_SLOW_IRC_CLOCK;
         }
         SystemCoreClock *= (MCGC4&MCGC4_DMX32_MASK)?608:512;
         SystemCoreClock *= ((MCGC4&MCGC4_DRST_DRS_MASK)>>MCGC4_DRST_DRS_BITNUM)+1;
      break;
      case 1<<MCGSC_CLKST_BITNUM : // Internal Reference Clock
         SystemCoreClock = SYSTEM_SLOW_IRC_CLOCK;
         break;
      case 2<<MCGSC_CLKST_BITNUM : // External Reference Clock
         SystemCoreClock = oscerclk;
         break;
      case 3<<MCGSC_CLKST_BITNUM : // PLL
         SystemCoreClock  = (oscerclk/10)*(4*((MCGC3&MCGC3_VDIV_MASK)>>MCGC3_VDIV_BITNUM));
         SystemCoreClock /= (1<<((MCGC1&MCGC1_RDIV_MASK)>>MCGC1_RDIV_BITNUM));
         SystemCoreClock *= 10;
         break;
   }
   SystemCoreClock   = SystemCoreClock/(1<<((MCGC2&MCGC2_BDIV0_MASK)>>MCGC2_BDIV_BITNUM));
   SystemBusClock    = SystemCoreClock/2;
}

