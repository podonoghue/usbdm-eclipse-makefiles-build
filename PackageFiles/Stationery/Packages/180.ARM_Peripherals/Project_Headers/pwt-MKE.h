/**
 * @file      pwt.h (180.ARM_Peripherals/Project_Headers/pwt-MKE.h)
 *
 * @brief    Abstraction layer for PWT interface
 *
 * @version  V4.12.
 * @date     13 July 2023
 */

#ifndef PROJECT_HEADERS_PWT_H_
#define PROJECT_HEADERS_PWT_H_

#include "pin_mapping.h"

namespace USBDM {

template <class Info>
class PwtBase_T : public PwtInfo {

protected:
   /** Hardware instance */
   static constexpr HardwarePtr<PWT_Type> pwt = baseAddress;

$(/PWT/protectedMethods: // No /PWT/protectedMethods found)
public:
$(/PWT/publicMethods: // No /PWT/publicMethods found)
$(/PWT/InitMethod: // No /PWT/InitMethod found)
   /**
    * Enable interrupts in NVIC
    */
   static void enableNvicInterrupts() {
      NVIC_EnablePWT(Info::irqNums[0]);
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
      NVIC_DisablePWT(Info::irqNums[0]);
   }

};

$(/PWT/staticDefinitions: )
$(/PWT/declarations: )

}; // namespace USBDM

#endif /* PROJECT_HEADERS_PWT_H_ */
