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

#if $(/ACMP/_BasicInfoGuard) // /ACMP/_BasicInfoGuard

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
};

$(/ACMP/staticDefinitions: )
$(/ACMP/declarations: )

$(/ACMP/InputMapping:   // /CMP/InputMapping None Found)
}; // namespace USBDM

#endif // /ACMP/_BasicInfoGuard

#endif /* PROJECT_HEADERS_ACMP_H_ */
