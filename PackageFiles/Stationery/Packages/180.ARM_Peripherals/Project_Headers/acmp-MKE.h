/**
 * @file      acmp.h (180.ARM_Peripherals/Project_Headers/acmp-MKE.h)
 *
 * @brief    Abstraction layer for ACMP interface
 *
 * @version  V4.12.
 * @date     13 July 2023
 */

#ifndef PROJECT_HEADERS_ACMP_H_
#define PROJECT_HEADERS_ACMP_H_

#include "pin_mapping.h"

#if $(/ACMP/enablePeripheralSupport) // /ACMP/enablePeripheralSupport

namespace USBDM {

template <class Info>
class AcmpBase_T : public Info {

protected:
   /** Hardware instance */
   static constexpr HardwarePtr<ACMP_Type> acmp = Info::baseAddress;

$(/ACMP/protectedMethods: // No /ACMP/protectedMethods found)
public:
$(/ACMP/publicMethods: // No /ACMP/publicMethods found)
$(/ACMP/InitMethod: // No /ACMP/InitMethod found)
   /**
    * Enable interrupts in NVIC
    */
   static void enableNvicInterrupts() {
      NVIC_EnableIRQ(Info::irqNums[0]);
   }

   /**
    * Enable and set priority of interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    *
    * @param[in]  nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(NvicPriority nvicPriority) {
      enableNvicInterrupt(Info::irqNums[0], nvicPriority);
   }

   /**
    * Disable interrupts in NVIC
    */
   static void disableNvicInterrupts() {
      NVIC_DisableIRQ(Info::irqNums[0]);
   }

};

$(/ACMP/staticDefinitions: )
$(/ACMP/declarations: )

}; // namespace USBDM

#endif // /ACMP/enablePeripheralSupport

#endif /* PROJECT_HEADERS_ACMP_H_ */
