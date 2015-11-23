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
extern const USBDM::PortA_T<0>   digitalIO_PTA0;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<1>   digitalIO_PTA1;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<2>   digitalIO_PTA2;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<3>   digitalIO_PTA3;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<4>   digitalIO_PTA4;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<5>   digitalIO_PTA5;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<6>   digitalIO_PTA6;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<7>   digitalIO_PTA7;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<8>   digitalIO_PTA8;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<9>   digitalIO_PTA9;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<10>  digitalIO_PTA10;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<11>  digitalIO_PTA11;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<12>  digitalIO_PTA12;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<13>  digitalIO_PTA13;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<14>  digitalIO_PTA14;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<15>  digitalIO_PTA15;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<16>  digitalIO_PTA16;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<17>  digitalIO_PTA17;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<18>  digitalIO_PTA18;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<19>  digitalIO_PTA19;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<20>  digitalIO_PTA20;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<21>  digitalIO_PTA21;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<22>  digitalIO_PTA22;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<23>  digitalIO_PTA23;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<24>  digitalIO_PTA24;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<25>  digitalIO_PTA25;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<26>  digitalIO_PTA26;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<27>  digitalIO_PTA27;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<28>  digitalIO_PTA28;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<29>  digitalIO_PTA29;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<30>  digitalIO_PTA30;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<31>  digitalIO_PTA31;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<0>   digitalIO_PTB0;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<1>   digitalIO_PTB1;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<2>   digitalIO_PTB2;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<3>   digitalIO_PTB3;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<4>   digitalIO_PTB4;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<5>   digitalIO_PTB5;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<6>   digitalIO_PTB6;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<7>   digitalIO_PTB7;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<8>   digitalIO_PTB8;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<9>   digitalIO_PTB9;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<10>  digitalIO_PTB10;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<11>  digitalIO_PTB11;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<12>  digitalIO_PTB12;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<13>  digitalIO_PTB13;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<14>  digitalIO_PTB14;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<15>  digitalIO_PTB15;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<16>  digitalIO_PTB16;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<17>  digitalIO_PTB17;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<18>  digitalIO_PTB18;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<19>  digitalIO_PTB19;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<20>  digitalIO_PTB20;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<21>  digitalIO_PTB21;     //!< See @ref DigitalIO
#define digitalIO_LED_RED        digitalIO_PTG5       //!< Alias for @ref USBDM::digitalIO_PTG5
extern const USBDM::PortB_T<22>  digitalIO_PTB22;     //!< See @ref DigitalIO
#define digitalIO_LED_GREEN      digitalIO_PTG6       //!< Alias for @ref USBDM::digitalIO_PTG6
extern const USBDM::PortB_T<23>  digitalIO_PTB23;     //!< See @ref DigitalIO
#define digitalIO_LED_BLUE       digitalIO_PTG7       //!< Alias for @ref USBDM::digitalIO_PTG7
extern const USBDM::PortB_T<24>  digitalIO_PTB24;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<25>  digitalIO_PTB25;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<26>  digitalIO_PTB26;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<27>  digitalIO_PTB27;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<28>  digitalIO_PTB28;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<29>  digitalIO_PTB29;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<30>  digitalIO_PTB30;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<31>  digitalIO_PTB31;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<0>   digitalIO_PTC0;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<1>   digitalIO_PTC1;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<2>   digitalIO_PTC2;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<3>   digitalIO_PTC3;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<4>   digitalIO_PTC4;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<5>   digitalIO_PTC5;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<6>   digitalIO_PTC6;      //!< See @ref DigitalIO
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
