/*
 * clock-SCG_MKE1xZ7.c
 *
 *  Used for KE1xZ
 * 
 *  Created on: 04/03/2012
 *      Author: podonoghue
 */
#include "derivative.h"
#include "stdbool.h"

enum {
   scgMode_SystemOSC   = (1),
   scgMode_SlowIRC     = (2),
   scgMode_FastIRC     = (3),
   scgMode_SystemLPFLL = (5),
   scgMode_SystemPLL   = (6),
};

/*
 * Clock frequencies
 */
#define CPU_XTAL_CLK_HZ        (8000000)   /**< 8 MHz crystal */

#if CPU_XTAL_CLK_HZ <= 40000
#define XTAL_RANGE 1
#define LPFLL_FREQ 32768
#elif CPU_XTAL_CLK_HZ <= 8000000
#define XTAL_RANGE 2
#define LPFLL_FREQ 2000000
#else
#define XTAL_RANGE 3
#define LPFLL_FREQ 2000000
#endif

#define SCG_SIRC_LOW_HZ        (2000000)   /**< SIRC low frequency */
#define SCG_SIRC_HIGH_HZ       (8000000)   /**< SIRC high frequency */

#define SCG_FIRC_LOW_HZ       (48000000)   /**< FIRC low frequency */
#define SCG_FIRC_MID_LOW_HZ   (52000000)   /**< FIRC mid-low frequency */
#define SCG_FIRC_MID_HIGH_HZ  (56000000)   /**< FIRC mid-high frequency */
#define SCG_FIRC_HIGH_HZ      (60000000)   /**< FIRC high frequency */

#ifdef SCG_LPFLLCSR_LPFLLEN_MASK
#define SCG_LPFLL_LOW_HZ      (48000000)   /**< LPFLL low frequency */
#define SCG_LPFLL_MID_LOW_HZ  (72000000)   /**< LPFLL mid-low frequency */
#define SCG_LPFLL_MID_HIGH_HZ        (0)   /**< LPFLL mid-high frequency */
#define SCG_LPFLL_HIGH_HZ            (0)   /**< LPFLL high frequency */
#endif

/*!
 * @brief Sets up the clock out of RESET
 *
 * Assumes 8 MHz external crystal
 */
void clock_initialise(void) {

   // System oscillator
   PCC->PCC_PORTB = PCC_PCC_PORTB_CGC(1);
   PORTB->PCR[6]  = PORT_PCR_MUX(0);
   PORTB->PCR[7]  = PORT_PCR_MUX(0);

   SCG->SOSCCSR =
         SCG_SOSCCSR_SOSCERR(1)|       // Clear error
         SCG_SOSCCSR_SOSCEN(0);        // Disable

   SCG->SOSCDIV =
         SCG_SOSCDIV_SOSCDIV1(1)|   // /1
         SCG_SOSCDIV_SOSCDIV2(1);   // /1

   SCG->SOSCCFG =
         SCG_SOSCCFG_EREFS(1)|            // Crystal
         SCG_SOSCCFG_HGO(XTAL_RANGE>1)|   // High/low gain
         SCG_SOSCCFG_RANGE(XTAL_RANGE);   // Range (1:32 kHz - 40 kHz, 2:1 MHz - 8 MHz, 3:8 MHz - 32 MHz)

   SCG->SOSCCSR =
#ifdef SCG_SOSCCSR_SOSCSTEN
         SCG_SOSCCSR_SOSCSTEN(1)|      // Enable in stop mode
         SCG_SOSCCSR_SOSCERCLKEN(1)|   // Enable in stop mode
         SCG_SOSCCSR_SOSCLPEN(1)|      // Enable in VLPS
#endif
         SCG_SOSCCSR_SOSCERR(1)|       // Clear error
         SCG_SOSCCSR_SOSCEN(1);        // Enable

   while ((SCG->SOSCCSR&SCG_SOSCCSR_SOSCVLD_MASK) == 0) {
      __asm__("nop");
   }

   // Slow IRC
   SCG->SIRCCSR =
         SCG_SIRCCSR_SIRCEN(0);     // Disable

   SCG->SIRCCFG =
         SCG_SIRCCFG_RANGE(1);      // High speed (8 MHz)

   SCG->SIRCDIV =
         SCG_SIRCDIV_SIRCDIV1(1)|   // /1
         SCG_SIRCDIV_SIRCDIV2(1);   // /1

   SCG->SIRCCSR =
         SCG_SIRCCSR_SIRCEN(1)|     // Enable
         SCG_SIRCCSR_SIRCSTEN(1)|   // Enable in Stop
         SCG_SIRCCSR_SIRCLPEN(1);   // Enable in VLP

   while ((SCG->SIRCCSR&SCG_SIRCCSR_SIRCVLD_MASK) == 0) {
      __asm__("nop");
   }

   // Fast IRC
   SCG->FIRCCSR =
         SCG_FIRCCSR_FIRCERR(1)|    // Clear error
         SCG_FIRCCSR_FIRCEN(0);     // Disable

   SCG->FIRCCFG =
         SCG_FIRCCFG_RANGE(0);      // High speed (48 MHz)

   SCG->FIRCDIV =
         SCG_FIRCDIV_FIRCDIV1(1)|   // /1
         SCG_FIRCDIV_FIRCDIV2(1);   // /1

   SCG->FIRCCSR =
#ifdef SCG_FIRCCSR_FIRCSTEN
         SCG_FIRCCSR_FIRCSTEN(1)|   // Enable in Stop
         SCG_FIRCCSR_FIRCLPEN(1)|   // Enable in VLP
#endif
         SCG_FIRCCSR_FIRCREGOFF(0)| // Enable Regulator
         SCG_FIRCCSR_FIRCERR(1)|    // Clear error flag
         SCG_FIRCCSR_FIRCEN(1);     // Enable

   while ((SCG->FIRCCSR&SCG_FIRCCSR_FIRCVLD_MASK) == 0) {
      __asm__("nop");
   }

#ifdef SCG_LPFLLCSR_LPFLLEN_MASK
   // Low power FLL
   SCG->LPFLLCSR =
         SCG_LPFLLCSR_LPFLLERR(1)|  // Clear error
         SCG_LPFLLCSR_LPFLLEN(0);   // Disable

   SCG->LPFLLDIV =
         SCG_LPFLLDIV_LPFLLDIV1(1)| // /1
         SCG_LPFLLDIV_LPFLLDIV2(1); // /1

   SCG->LPFLLCFG =
         SCG_LPFLLCFG_FSEL(0);   // Trim to 48 MHz

   SCG->LPFLLTCFG =
         SCG_LPFLLTCFG_TRIMSRC(2)|                               // System oscillator (8 MHz)
         SCG_LPFLLTCFG_TRIMDIV((CPU_XTAL_CLK_HZ/LPFLL_FREQ)-1)|  // e.g. 3 = /4 => (8 MHz / 4 = 2 MHz)
         SCG_LPFLLTCFG_LOCKW2LSB(1);                             // 2 LSB ~0.8%

   SCG->LPFLLCSR =
         SCG_LPFLLCSR_LPFLLERR(1)|  // Clear error
         SCG_LPFLLCSR_LPFLLEN(1);   // Enable

   while ((SCG->LPFLLCSR&SCG_LPFLLCSR_LPFLLVLD_MASK) == 0) {
      __asm__("nop");
   }
#endif

#ifdef SCG_SPLLCSR_SPLLEN_MASK
   // System PLL
   SCG->SPLLCSR =
         SCG_SPLLCSR_SPLLERR(1)|  // Clear error
         SCG_SPLLCSR_SPLLEN(0);   // Disable

   SCG->SPLLDIV =
         SCG_SPLLDIV_SPLLDIV1(1)| // /1
         SCG_SPLLDIV_SPLLDIV2(1); // /1

   SCG->SPLLCFG =
         SCG_SPLLCFG_PREDIV(1-1)|   // /1 8 MHz in,                Divider 0-7 => /1-/8 (must result in 8 MHz - 16 MHz input)
         SCG_SPLLCFG_MULT(40-16);   // x40 (40x8/1)/2 160 MHz out, Multiplier 0-39 => x16-x47 (with post-divider of /2) (must be 180 MHz - 320 MHz)

   SCG->SPLLCSR =
         SCG_SPLLCSR_SPLLERR(1)|  // Clear error
         SCG_SPLLCSR_SPLLEN(1);   // Enable

   while ((SCG->SPLLCSR&SCG_SPLLCSR_SPLLVLD_MASK) == 0) {
      __asm__("nop");
   }
#endif

   // RUN mode configure
   SCG->RCCR =
         SCG_RCCR_SCS(scgMode_SystemLPFLL)| // Clock source = LPFLL = 48 MHz
         SCG_RCCR_DIVCORE(1-1)|               // Core Clock FLL/1 = 48 MHz
         SCG_RCCR_DIVSLOW(2-1);               // Slow Clock Core/2 = 24 MHz

   // VLPR mode configure
   SCG->VCCR =
         SCG_VCCR_SCS(scgMode_SlowIRC)|     // Clock source = SIRC ~ 2 MHz
         SCG_VCCR_DIVCORE(1-1)|     // Core Clock SIRC/1  => 2 MHz
         SCG_VCCR_DIVSLOW(2-1);     // Slow Clock Core/2  => 1 MHz

   // Clock output
   SCG->CLKOUTCNFG =
         SCG_CLKOUTCNFG_CLKOUTSEL(3); // Fast IRC

   SystemCoreClockUpdate();
}

/*!
 * @brief Update SystemCoreClock variable
 *
 * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
 */
void SystemCoreClockUpdate(void) {
   uint32_t frequency = 0U;      /* SCG output clock frequency */
   uint32_t regValue;

   static const uint32_t fircFreq[] = {
         SCG_FIRC_LOW_HZ,
         SCG_FIRC_MID_LOW_HZ,
         SCG_FIRC_MID_HIGH_HZ,
         SCG_FIRC_HIGH_HZ,
   };

#ifdef SCG_LPFLLCSR_LPFLLEN_MASK
   static const uint32_t lpfllFreq[] = {
         SCG_LPFLL_LOW_HZ,
         SCG_LPFLL_MID_LOW_HZ,
         SCG_LPFLL_MID_HIGH_HZ,
         SCG_LPFLL_HIGH_HZ,
   };
#endif

   switch (SCG->CSR & SCG_CSR_SCS_MASK) {
      case SCG_CSR_SCS(scgMode_SystemOSC): // System OSC (SOSC_CLK)
         frequency = CPU_XTAL_CLK_HZ;
         break;

      case SCG_CSR_SCS(scgMode_SlowIRC): // Slow IRC (SIRC_CLK)
         regValue = (SCG->SIRCCFG & SCG_SIRCCFG_RANGE_MASK);
         frequency = (regValue != 0U) ? SCG_SIRC_HIGH_HZ : SCG_SIRC_LOW_HZ;
         break;

      case SCG_CSR_SCS(scgMode_FastIRC): // Fast IRC (FIRC_CLK)
         regValue = (SCG->FIRCCFG & SCG_FIRCCFG_RANGE_MASK) >> SCG_FIRCCFG_RANGE_SHIFT;
         frequency= fircFreq[regValue];
         break;

#ifdef SCG_LPFLLCSR_LPFLLEN_MASK
      case SCG_CSR_SCS(scgMode_SystemLPFLL): // Low Power FLL (LPFLL_CLK)
         regValue = (SCG->LPFLLCFG & SCG_LPFLLCFG_FSEL_MASK) >> SCG_LPFLLCFG_FSEL_SHIFT;
         frequency= lpfllFreq[regValue];
         break;
#endif

#ifdef SCG_SPLLCSR_SPLLEN_MASK
      case SCG_CSR_SCS(scgMode_SystemPLL): // System PLL (SPLL_CLK)
	     {
         uint32_t prediv, multi;
         frequency = CPU_XTAL_CLK_HZ;
         prediv = ((SCG->SPLLCFG & SCG_SPLLCFG_PREDIV_MASK) >> SCG_SPLLCFG_PREDIV_SHIFT) + 1U;
         multi = ((SCG->SPLLCFG & SCG_SPLLCFG_MULT_MASK) >> SCG_SPLLCFG_MULT_SHIFT) + 16U;
         frequency = frequency * multi / (prediv * 2U);
		 }
      break;
#endif

      default:
         break;
   }
   if (frequency == 0) {
      // Invalid clock
      __asm__("nop");
   }
   SystemCoreClock = (frequency / (((SCG->CSR & SCG_CSR_DIVCORE_MASK) >> SCG_CSR_DIVCORE_SHIFT) + 1U));
   SystemBusClock  = (SystemCoreClock / (((SCG->CSR & SCG_CSR_DIVSLOW_MASK) >> SCG_CSR_DIVSLOW_SHIFT) + 1U));
}
