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
 * @tparam bitNum  Index into tables describing individual PORT pins e.g. PTA = 0..7, PTB = 8..25 etc
 */
template<unsigned bitNum>
class Port_T : public PortInfo {

protected:
   using Info = PortInfo;
$(/PORT/protectedMethods: // /PORT/protectedMethods not found)
public:
$(/PORT/publicMethods: // /PORT/publicMethods not found)

};

$(/PORT/declarations: // /PORT/declarations not found) 
} // namespace USBDM


#endif /* PROJECT_HEADERS_PORT_H_ */
