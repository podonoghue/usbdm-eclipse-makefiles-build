/**
 * @file     pmc.h (180.ARM_Peripherals/Project_Headers/pmc.h)
 * @brief    Power Management Controller
 *
 * @version  V4.12.1.210
 * @date     30 September 2017
 */

#ifndef HEADER_PMC_H
#define HEADER_PMC_H
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "pin_mapping.h"

$(/PMC/prototypes:// $/PMC/prototypes not found)

namespace USBDM {
/**
 * @addtogroup PMC_Group PMC, Power Management Controller
 * @brief Peripheral information for Power Management Controller
 * @{
 */

$(/PMC/peripheral_h_definition:// $/PMC/peripheral_h_definition not found)

/**
 * Template class providing interface to Power Management Controller
 *
 * @code
 * using pmc = PmcBase;
 *
 *  pmc::defaultConfigure();
 *
 * @endcode
 */
class PmcBase : public PmcInfo {

protected:
$(/PMC/protectedMethods: // No protected methods found)

protected:
   /** Hardware instance */
   static constexpr HardwarePtr<PMC_Type> pmc = baseAddress;

public:
   /**
    * Enable clock to the PMC
    */
   static void  __attribute__((always_inline)) enable() {
   }

#ifdef PMC_REGSC_BIASEN
   /**
    * Enables source and well biasing for the core logic in low power mode.
    *
    * In full performance mode this option has no effect.
    * This is useful to further reduce MCU power consumption in low power mode.
    * This bit must be enabled when using VLP* modes.
    *
    * Biasing enabled => Core logic is slower and there are restrictions in allowed system clock speed
    */
   static void enableCoreBias() {
      pmc->REGSC |= PMC_REGSC_BIASEN_MASK;
   }

   /**
    * Disables source and well biasing for the core logic in low power mode.
    *
    * Biasing disabled => Core logic can run in full performance
    */
   static void disableCoreBias() {
      pmc->REGSC &= ~PMC_REGSC_BIASEN_MASK;
   }
#endif

#ifdef PMC_REGSC_CLKBIASDIS
   /**
    * Enables the bias currents and reference voltages for some clock modules.
    *
    * Disabling clock bias reduces power consumption in VLPS mode.
    *
    * Enabled  - No effect
    */
   static void enableClockBias() {
      pmc->REGSC &= ~PMC_REGSC_CLKBIASDIS_MASK;
   }

   /**
    * Disables the bias currents and reference voltages for some clock modules.
    *
    * Disabling clock bias further reduce power consumption in VLPS mode.
    * While using this option, it must be ensured that respective clock modules are
    * disabled in VLPS mode otherwise severe malfunction of clock modules will occur.
    *
    * Disabled - In VLPS mode, the bias currents and reference voltages for the
    *            following clock modules are disabled: SIRC, FIRC, PLL.
    */
   static void disableClockBias() {
      pmc->REGSC |= PMC_REGSC_CLKBIASDIS_MASK;
   }
#endif

#ifdef PMC_REGSC_LPODIS
   /**
    * Enable low power oscillator (LPO)
    *
    * Controls operation of the low power oscillator.
    *
    * @note After disabling the LPO a time of 2 LPO clock cycles is required before
    *       it is allowed to enable it again. Violating this waiting time of 2 cycles
    *       can result in malfunction of the LPO.
    */
   static void enableLowPowerOscillator() {
      pmc->REGSC &= ~PMC_REGSC_LPODIS_MASK;
   }

   /**
    * Disable low power oscillator (LPO)
    *
    * Controls operation of the low power oscillator.
    *
    * @note After disabling the LPO a time of 2 LPO clock cycles is required before
    *       it is allowed to enable it again. Violating this waiting time of 2 cycles
    *       can result in malfunction of the LPO.
    */
   static void disableLowPowerOscillator() {
      pmc->REGSC |= PMC_REGSC_LPODIS_MASK;
   }
#endif

#ifdef PMC_REGSC_LPOSTAT
   /**
    * Get Low Power Oscillator (LPO) state
    *
    * @return true  => LPO is currently in high state
    * @return false => LPO is currently in low state
    */
   static bool getLowpowerOscillatorStatus() {
      return (pmc->REGSC & PMC_REGSC_LPOSTAT_MASK)?true:false;
   }
#endif

#ifdef PMC_LPOTRIM_LPOTRIM
   static void setLowpowerOscillatorTrim(int trimValue) {
      pmc->LPOTRIM = PMC_LPOTRIM_LPOTRIM(trimValue);
   }
   static int getLowpowerOscillatorTrim() {
      int trim = pmc->LPOTRIM&PMC_LPOTRIM_LPOTRIM_MASK;
      if (((unsigned)trim)>(PMC_LPOTRIM_LPOTRIM_MASK>>1)) {
         // Sign extend -ve values
         trim -= PMC_LPOTRIM_LPOTRIM_MASK+1;
      }
      return trim;
   }
#endif

};

$(/PMC/declarations: // No declarations found)

/**
 * End PMC_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_PMC_H */
