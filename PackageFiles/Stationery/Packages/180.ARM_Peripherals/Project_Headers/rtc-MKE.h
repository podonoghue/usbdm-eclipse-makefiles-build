/**
 * @file      irq.h (180.ARM_Peripherals/Project_Headers/irq-MKE.h)
 *
 * @brief    Abstraction layer for RTC interface
 *
 * @version  V4.12.
 * @date     13 July 2023
 */

#ifndef PROJECT_HEADERS_RTC_H_
#define PROJECT_HEADERS_RTC_H_

#include "pin_mapping.h"

namespace USBDM {

template <class Info>
class RtcBase_T : public RtcInfo {

protected:
   /** Hardware instance */
   static constexpr HardwarePtr<RTC_Type> rtc = baseAddress;

$(/RTC/protectedMethods: // No /RTC/protectedMethods found)
public:
$(/RTC/publicMethods: // No /RTC/publicMethods found)
$(/RTC/InitMethod: // No /RTC/InitMethod found)
   /**
    * Enable interrupts in NVIC
    */
   static void enableNvicInterrupts() {
      NVIC_EnableRTC(Info::irqNums[0]);
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
      NVIC_DisableRTC(Info::irqNums[0]);
   }

};

$(/RTC/staticDefinitions: )
$(/RTC/declarations: )

}; // namespace USBDM

#endif /* PROJECT_HEADERS_RTC_H_ */
