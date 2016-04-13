/**
 * @file     gpio.h (from gpio_defs-MK.h)
 * @brief    GPIO Pin routines
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_VREF_H
#define HEADER_VREF_H

#include <stddef.h>
#include <assert.h>
#include "derivative.h"
#include "bitband.h"

#ifdef VREF_Type
/**
 * @addtogroup VREF_Group Voltage reference
 * @{
 */
/**
 * Template class representing a Voltage Reference
 *
 * @tparam info      Information class for VREF
 *
 * @code
 * using vref = Vref_T<VrefInfo>;
 *
 *  vref::initialise();
 *
 * @endcode
 */
template<class info>
class Vref_T {

private:
   using OutPcr  = PcrTable_T<info, 0>;
   static constexpr volatile VREF_Type *vref = reinterpret_cast<VREF_Type *>(info::basePtr);

public:
   /**
    * Enable the voltage reference
    *
    * @param scValue Value for SC register e.g. VREF_SC_VREFEN_MASK|VREF_SC_REGEN_MASK|VREF_SC_ICOMPEN_MASK|VREF_SC_MODE_LV(2)
    */
   static void enable(uint32_t scValue=VREF_SC_VREFEN_MASK|VREF_SC_REGEN_MASK|VREF_SC_ICOMPEN_MASK|VREF_SC_MODE_LV(2)) {
      // Configure pin (if necessary)
      OutPcr::setPCR();

      // Enable clock to I2C interface
      *reinterpret_cast<uint32_t *>(info::clockReg) |= info::clockMask;

      // Initialise hardware
      vref->TRM |= VREF_TRM_CHOPEN_MASK;
      vref->SC   = scValue;
      while ((vref->SC & VREF_SC_VREFST_MASK) == 0) {
         // Wait until stable
      }
   }
   static void disable() {
      vref->SC = 0;
      *reinterpret_cast<uint32_t *>(info::clockReg) &= ~info::clockMask;
   }
};
/**
 * @}
 */
#endif
} // End namespace USBDM

#endif /* HEADER_VREF_H */

