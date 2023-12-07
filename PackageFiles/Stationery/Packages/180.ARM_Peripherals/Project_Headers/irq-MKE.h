/**
 * @file      irq.h (180.ARM_Peripherals/Project_Headers/irq-MKE.h)
 *
 * @brief    Abstraction layer for IRQ interface
 *
 * @version  V4.12.
 * @date     13 July 2023
 */

#ifndef PROJECT_HEADERS_IRQ_H_
#define PROJECT_HEADERS_IRQ_H_

#include "pin_mapping.h"

namespace USBDM {

template <class Info>
class IrqBase_T : public IrqInfo {

protected:
   /** Hardware instance */
   static constexpr HardwarePtr<IRQ_Type> irq = baseAddress;

$(/IRQ/protectedMethods: // No /IRQ/protectedMethods found)
public:
$(/IRQ/publicMethods: // No /IRQ/publicMethods found)
$(/IRQ/InitMethod: // No /IRQ/InitMethod found)
};

$(/IRQ/staticDefinitions: )
$(/IRQ/declarations: )

}; // namespace USBDM

#endif /* PROJECT_HEADERS_IRQ_H_ */
