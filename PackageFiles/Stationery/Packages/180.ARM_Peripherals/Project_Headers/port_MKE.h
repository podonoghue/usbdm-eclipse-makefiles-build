/**
 * @file     port.h (180.ARM_Peripherals/Project_Headers/port_MKE.h)
 * @brief    PORT routines
 *
 * @version  V4.12.1.270
 * @date     10 July 2023
 */

#ifndef PROJECT_HEADERS_PORT_H_
#define PROJECT_HEADERS_PORT_H_

#include "pin_mapping.h"

namespace USBDM {

enum PullDirection : uint32_t {
   PullDirection_none = 0,
   PullDirection_up   = 0xFFFFFFFFU,
};

enum HighDrive : uint32_t {
   HighDrive_off = 0,
   HighDrive_on  = 0xFFFFFFFFU,
};

/**
 * Class holding shared code for the PORT
 */
class Port : public PortInfo {

   using Info = PortInfo;

public:
$(/PORT/InitMethod: // /PORT/InitMethod not found)
};

/**
 * Class representing a PORT pin
 *
 * @tparam pinIndex  Index into tables describing individual PORT pins e.g. PTA = 0..7, PTB = 8..25 etc
 */
template<PinIndex pinIndex>
class Port_T : public PortInfo {

protected:
   using Info = PortInfo;
$(/PORT/protectedMethods: // /PORT/protectedMethods not found)
public:
$(/PORT/publicMethods: // /PORT/publicMethods not found)

};

/**
 * Class representing a field of PORT pins
 *
 * @tparam pinIndexLeft  Index identifying left-most PORT pins e.g. PTA = 0..7, PTB = 8..25 etc
 * @tparam pinIndexRight Index identifying left-most PORT pins e.g. PTA = 0..7, PTB = 8..25 etc
 */
template<PinIndex pinIndexLeft, PinIndex pinIndexRight>
class PortField_T : private Port_T<pinIndexLeft> {

   // Restrict to same Port i.e. 8 bits wide
   // In practice it could extend across Ports A-B-C-D or E-F-G-H as they are accessed through the same GPIO register
   static_assert((pinIndexLeft<PinIndex::MAX_PIN_INDEX), "Illegal bit number for left in PortField");
   static_assert(((unsigned(pinIndexLeft)&~0b111)==(unsigned(pinIndexRight)&~0b111)) && (pinIndexLeft>=pinIndexRight),
      "Illegal bit number for left or right in PortField");

private:
   /**
    * This class is not intended to be instantiated
    */
   PortField_T(const PortField_T&) = delete;
   PortField_T(PortField_T&&) = delete;

   /// Left bit within used GPIO registers
   static constexpr PinNum Left  = unsigned(pinIndexLeft)%32;

   /// Right bit within used GPIO registers
   static constexpr PinNum Right = unsigned(pinIndexRight)%32;


protected:

   using Info = PortInfo;

public:
$(/PORT/publicFieldMethods: // /PORT/publicMethods not found)
};

$(/PORT/declarations: // /PORT/declarations not found) 
} // namespace USBDM


#endif /* PROJECT_HEADERS_PORT_H_ */
