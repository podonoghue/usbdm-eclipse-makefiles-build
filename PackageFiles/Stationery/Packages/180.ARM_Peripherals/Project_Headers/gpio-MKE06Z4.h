/**
 * @file      gpio.h (derived from gpio-MKE06Z4.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKE06Z4
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stddef.h>
#include "derivative.h"
#include "pin_mapping.h"
#include "gpio_defs.h"

namespace USBDM {

/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
using gpioA_0              = const USBDM::GpioA<0>;
using gpioA_1              = const USBDM::GpioA<1>;
using gpioA_2              = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpioA_6              = const USBDM::GpioA<6>;
using gpioA_7              = const USBDM::GpioA<7>;
using gpioA_8              = const USBDM::GpioA<8>;
using gpioA_9              = const USBDM::GpioA<9>;
using gpioA_10             = const USBDM::GpioA<10>;
using gpioA_11             = const USBDM::GpioA<11>;
using gpioA_12             = const USBDM::GpioA<12>;
using gpioA_13             = const USBDM::GpioA<13>;
using gpioA_14             = const USBDM::GpioA<14>;
using gpioA_15             = const USBDM::GpioA<15>;
using gpioA_16             = const USBDM::GpioA<16>;
using gpioA_17             = const USBDM::GpioA<17>;
using gpioA_18             = const USBDM::GpioA<18>;
using gpioA_19             = const USBDM::GpioA<19>;
using gpioA_20             = const USBDM::GpioA<20>;
using gpioA_21             = const USBDM::GpioA<21>;
using gpioA_22             = const USBDM::GpioA<22>;
using gpioA_23             = const USBDM::GpioA<23>;
using gpioA_24             = const USBDM::GpioA<24>;
using gpioA_25             = const USBDM::GpioA<25>;
using gpioA_26             = const USBDM::GpioA<26>;
using gpioA_27             = const USBDM::GpioA<27>;
using gpioA_28             = const USBDM::GpioA<28>;
using gpioA_29             = const USBDM::GpioA<29>;
using gpioA_30             = const USBDM::GpioA<30>;
using gpioA_31             = const USBDM::GpioA<31>;
using gpioB_0              = const USBDM::GpioB<0>;
using gpioB_1              = const USBDM::GpioB<1>;
using gpioB_2              = const USBDM::GpioB<2>;
using gpioB_3              = const USBDM::GpioB<3>;
using gpioB_4              = const USBDM::GpioB<4>;
using gpioB_5              = const USBDM::GpioB<5>;
using gpioB_6              = const USBDM::GpioB<6>;
using gpioB_7              = const USBDM::GpioB<7>;
using gpioB_8              = const USBDM::GpioB<8>;
using gpioB_9              = const USBDM::GpioB<9>;
using gpioB_10             = const USBDM::GpioB<10>;
using gpioB_11             = const USBDM::GpioB<11>;
using gpioB_12             = const USBDM::GpioB<12>;
using gpioB_13             = const USBDM::GpioB<13>;
using gpioB_14             = const USBDM::GpioB<14>;
using gpioB_15             = const USBDM::GpioB<15>;
using gpioB_16             = const USBDM::GpioB<16>;
using gpioB_17             = const USBDM::GpioB<17>;
using gpioB_18             = const USBDM::GpioB<18>;
using gpioB_19             = const USBDM::GpioB<19>;
using gpioB_20             = const USBDM::GpioB<20>;
using gpioB_21             = const USBDM::GpioB<21>;
using gpio_LED_RED         = const USBDM::GpioB<21>;
using gpioB_22             = const USBDM::GpioB<22>;
using gpio_LED_GREEN       = const USBDM::GpioB<22>;
using gpioB_23             = const USBDM::GpioB<23>;
using gpio_LED_BLUE        = const USBDM::GpioB<23>;
using gpioB_24             = const USBDM::GpioB<24>;
using gpioB_25             = const USBDM::GpioB<25>;
using gpioB_26             = const USBDM::GpioB<26>;
using gpioB_27             = const USBDM::GpioB<27>;
using gpioB_28             = const USBDM::GpioB<28>;
using gpioB_29             = const USBDM::GpioB<29>;
using gpioB_30             = const USBDM::GpioB<30>;
using gpioB_31             = const USBDM::GpioB<31>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
/**
 * @}
 */
#if (DO_MAP_PINS_ON_RESET>0)
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
extern void usbdm_PinMapping();
#endif

} // End namespace USBDM

#endif /* GPIO_H_ */
