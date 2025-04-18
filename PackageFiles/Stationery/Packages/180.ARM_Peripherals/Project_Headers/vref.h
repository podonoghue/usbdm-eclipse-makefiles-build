/**
 * @file     vref.h (180.ARM_Peripherals/Project_Headers/vref.h)
 * @brief    Voltage Reference
 */

#ifndef HEADER_VREF_H
#define HEADER_VREF_H
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "derivative.h"
#include "pin_mapping.h"

$(/VREF/prototypes:// $/VREF/prototypes not found)

namespace USBDM {

/**
 * @addtogroup VREF_Group VREF, Voltage Reference
 * @brief C++ Class allowing access to Voltage Reference
 * @{
 */
$(/VREF/peripheral_h_definition:// $/VREF/peripheral_h_definition not found)
/**
 * Template class representing a Voltage Reference
 *
 * @tparam info      Information class for VREF
 *
 * @code
 * using vref = VrefBase_T<VrefInfo>;
 *
 *  vref::initialise();
 *
 * @endcode
 */
template<class Info>
class VrefBase_T : public Info {

   CreatePeripheralPinChecker("VREF");

private:
   /**
    * This class is not intended to be instantiated
    */
   VrefBase_T(const VrefBase_T&) = delete;
   VrefBase_T(VrefBase_T&&) = delete;

public:
   /** Hardware instance pointer */
   static constexpr HardwarePtr<VREF_Type> vref = Info::baseAddress;

   VrefBase_T() {
   };

public:
$(/VREF/InitMethod: // /VREF/InitMethod not found)
   $(/VREF/classInfo: // No class Info found)
   /**
    * Enable Vref output pin as Vref output.
    * Configures all Pin Control Register (PCR) values
    */
   static void setOutput() {
      CheckPinExistsAndIsMapped<Info,Info::outputPin>::check();

      using Pcr = PcrTable_T<Info, Info::outputPin>;

      // Enable and map pin to Vref_out is needed
      Pcr::setPCR();
   }
};

$(/VREF/declarations: // No declarations found)
/**
 * End VREF_Group
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_VREF_H */
