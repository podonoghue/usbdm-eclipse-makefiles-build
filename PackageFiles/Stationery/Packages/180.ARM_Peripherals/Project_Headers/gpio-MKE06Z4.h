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
const USBDM::GpioA<0>     gpioA_0;
const USBDM::GpioA<1>     gpioA_1;
const USBDM::GpioA<2>     gpioA_2;
const USBDM::GpioA<3>     gpioA_3;
const USBDM::GpioA<4>     gpioA_4;
const USBDM::GpioA<5>     gpioA_5;
const USBDM::GpioA<6>     gpioA_6;
const USBDM::GpioA<7>     gpioA_7;
const USBDM::GpioA<8>     gpioA_8;
const USBDM::GpioA<9>     gpioA_9;
const USBDM::GpioA<10>    gpioA_10;
const USBDM::GpioA<11>    gpioA_11;
const USBDM::GpioA<12>    gpioA_12;
const USBDM::GpioA<13>    gpioA_13;
const USBDM::GpioA<14>    gpioA_14;
const USBDM::GpioA<15>    gpioA_15;
const USBDM::GpioA<16>    gpioA_16;
const USBDM::GpioA<17>    gpioA_17;
const USBDM::GpioA<18>    gpioA_18;
const USBDM::GpioA<19>    gpioA_19;
const USBDM::GpioA<20>    gpioA_20;
const USBDM::GpioA<21>    gpioA_21;
const USBDM::GpioA<22>    gpioA_22;
const USBDM::GpioA<23>    gpioA_23;
const USBDM::GpioA<24>    gpioA_24;
const USBDM::GpioA<25>    gpioA_25;
const USBDM::GpioA<26>    gpioA_26;
const USBDM::GpioA<27>    gpioA_27;
const USBDM::GpioA<28>    gpioA_28;
const USBDM::GpioA<29>    gpioA_29;
const USBDM::GpioA<30>    gpioA_30;
const USBDM::GpioA<31>    gpioA_31;
const USBDM::GpioB<0>     gpioB_0;
const USBDM::GpioB<1>     gpioB_1;
const USBDM::GpioB<2>     gpioB_2;
const USBDM::GpioB<3>     gpioB_3;
const USBDM::GpioB<4>     gpioB_4;
const USBDM::GpioB<5>     gpioB_5;
const USBDM::GpioB<6>     gpioB_6;
const USBDM::GpioB<7>     gpioB_7;
const USBDM::GpioB<8>     gpioB_8;
const USBDM::GpioB<9>     gpioB_9;
const USBDM::GpioB<10>    gpioB_10;
const USBDM::GpioB<11>    gpioB_11;
const USBDM::GpioB<12>    gpioB_12;
const USBDM::GpioB<13>    gpioB_13;
const USBDM::GpioB<14>    gpioB_14;
const USBDM::GpioB<15>    gpioB_15;
const USBDM::GpioB<16>    gpioB_16;
const USBDM::GpioB<17>    gpioB_17;
const USBDM::GpioB<18>    gpioB_18;
const USBDM::GpioB<19>    gpioB_19;
const USBDM::GpioB<20>    gpioB_20;
const USBDM::GpioB<21>    gpioB_21;
const USBDM::GpioB<21>    gpio_LED_RED;
const USBDM::GpioB<22>    gpioB_22;
const USBDM::GpioB<22>    gpio_LED_GREEN;
const USBDM::GpioB<23>    gpioB_23;
const USBDM::GpioB<23>    gpio_LED_BLUE;
const USBDM::GpioB<24>    gpioB_24;
const USBDM::GpioB<25>    gpioB_25;
const USBDM::GpioB<26>    gpioB_26;
const USBDM::GpioB<27>    gpioB_27;
const USBDM::GpioB<28>    gpioB_28;
const USBDM::GpioB<29>    gpioB_29;
const USBDM::GpioB<30>    gpioB_30;
const USBDM::GpioB<31>    gpioB_31;
const USBDM::GpioC<0>     gpioC_0;
const USBDM::GpioC<1>     gpioC_1;
const USBDM::GpioC<2>     gpioC_2;
const USBDM::GpioC<3>     gpioC_3;
const USBDM::GpioC<4>     gpioC_4;
const USBDM::GpioC<5>     gpioC_5;
const USBDM::GpioC<6>     gpioC_6;
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

} // End namespace USBDM

#endif /* GPIO_H_ */
