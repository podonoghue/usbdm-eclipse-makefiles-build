/**
 * @file      kbi.h (180.ARM_Peripherals/Project_Headers/kbi-MKE.h)
 *
 * @brief    Abstraction layer for KBI interface
 *
 * @version  V4.12.
 * @date     13 July 2023
 */

#ifndef PROJECT_HEADERS_KBI_H_
#define PROJECT_HEADERS_KBI_H_

#include "pin_mapping.h"

#if $(/KBI/enablePeripheralSupport) // /KBI/enablePeripheralSupport

namespace USBDM {

template <class Info>
class KbiBase_T : public Info {

protected:
   /** Hardware instance */
   static constexpr HardwarePtr<KBI_Type> kbi = Info::baseAddress;

$(/KBI/protectedMethods: // No /KBI/protectedMethods found)
public:
$(/KBI/publicMethods: // No /KBI/publicMethods found)
$(/KBI/InitMethod: // No /KBI/InitMethod found)
};

$(/KBI/staticDefinitions: )
$(/KBI/declarations: )

}; // namespace USBDM

#endif // /KBI/enablePeripheralSupport

#endif /* PROJECT_HEADERS_KBI_H_ */
