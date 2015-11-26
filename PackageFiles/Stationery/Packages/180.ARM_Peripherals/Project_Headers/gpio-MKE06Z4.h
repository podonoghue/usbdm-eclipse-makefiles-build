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

#if USBDM_USE_NAMESPACES
namespace USBDM {
#endif
/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const USBDM::GpioA<0>     gpioA_0;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<1>     gpioA_1;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<2>     gpioA_2;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<3>     gpioA_3;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<4>     gpioA_4;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<5>     gpioA_5;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<6>     gpioA_6;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<7>     gpioA_7;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<8>     gpioA_8;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<9>     gpioA_9;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<10>    gpioA_10;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<11>    gpioA_11;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<12>    gpioA_12;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<13>    gpioA_13;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<14>    gpioA_14;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<15>    gpioA_15;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<16>    gpioA_16;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<17>    gpioA_17;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<18>    gpioA_18;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<19>    gpioA_19;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<20>    gpioA_20;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<21>    gpioA_21;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<22>    gpioA_22;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<23>    gpioA_23;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<24>    gpioA_24;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<25>    gpioA_25;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<26>    gpioA_26;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<27>    gpioA_27;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<28>    gpioA_28;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<29>    gpioA_29;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<30>    gpioA_30;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<31>    gpioA_31;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<0>     gpioB_0;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<1>     gpioB_1;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<2>     gpioB_2;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<3>     gpioB_3;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<4>     gpioB_4;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<5>     gpioB_5;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<6>     gpioB_6;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<7>     gpioB_7;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<8>     gpioB_8;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<9>     gpioB_9;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<10>    gpioB_10;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<11>    gpioB_11;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<12>    gpioB_12;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<13>    gpioB_13;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<14>    gpioB_14;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<15>    gpioB_15;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<16>    gpioB_16;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<17>    gpioB_17;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<18>    gpioB_18;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<19>    gpioB_19;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<20>    gpioB_20;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<21>    gpioB_21;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_LED_RED        gpioB_21             //!< Alias for @ref USBDM::gpioB_21
extern const USBDM::GpioB<22>    gpioB_22;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_LED_GREEN      gpioB_22             //!< Alias for @ref USBDM::gpioB_22
extern const USBDM::GpioB<23>    gpioB_23;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_LED_BLUE       gpioB_23             //!< Alias for @ref USBDM::gpioB_23
extern const USBDM::GpioB<24>    gpioB_24;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<25>    gpioB_25;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<26>    gpioB_26;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<27>    gpioB_27;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<28>    gpioB_28;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<29>    gpioB_29;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<30>    gpioB_30;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<31>    gpioB_31;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<0>     gpioC_0;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<1>     gpioC_1;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<2>     gpioC_2;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<3>     gpioC_3;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<4>     gpioC_4;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<5>     gpioC_5;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<6>     gpioC_6;             //!< See @ref USBDM::DigitalIOT
/**
 * @}
 */
#if defined(DO_MAP_PINS_ON_RESET) && (DO_MAP_PINS_ON_RESET>0)
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
extern void usbdm_PinMapping();
#endif

/*
Clock Information 
ACMP0      SCGC         SIM_SCGC_ACMP0_MASK
ACMP1      SCGC         SIM_SCGC_ACMP1_MASK
ADC0       SCGC         SIM_SCGC_ADC0_MASK
CRC        SCGC         SIM_SCGC_CRC_MASK
FTM0       SCGC         SIM_SCGC_FTM0_MASK
FTM1       SCGC         SIM_SCGC_FTM1_MASK
FTM2       SCGC         SIM_SCGC_FTM2_MASK
I2C0       SCGC         SIM_SCGC_I2C0_MASK
I2C1       SCGC         SIM_SCGC_I2C1_MASK
IRQ        SCGC         SIM_SCGC_IRQ_MASK
KBI0       SCGC         SIM_SCGC_KBI0_MASK
KBI1       SCGC         SIM_SCGC_KBI1_MASK
MSCAN      SCGC         SIM_SCGC_MSCAN_MASK
PIT        SCGC         SIM_SCGC_PIT_MASK
PWT        SCGC         SIM_SCGC_PWT_MASK
RTC        SCGC         SIM_SCGC_RTC_MASK
SPI0       SCGC         SIM_SCGC_SPI0_MASK
SPI1       SCGC         SIM_SCGC_SPI1_MASK
SWD        SCGC         SIM_SCGC_SWD_MASK
UART0      SCGC         SIM_SCGC_UART0_MASK
UART1      SCGC         SIM_SCGC_UART1_MASK
UART2      SCGC         SIM_SCGC_UART2_MASK
*/

#if USBDM_USE_NAMESPACES
} // End namespace USBDM
#endif

#endif /* GPIO_H_ */
