/**
 * @file      gpio.h (derived from gpio-MKE06Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKE06Z4
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "derivative.h"
#include "pin_mapping.h"
#include "gpio_defs.h"

/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const DigitalIO digitalIO_PTA0;          //!< DigitalIO on pin PTA0
extern const DigitalIO digitalIO_PTA1;          //!< DigitalIO on pin PTA1
extern const DigitalIO digitalIO_PTA2;          //!< DigitalIO on pin PTA2
extern const DigitalIO digitalIO_PTA3;          //!< DigitalIO on pin PTA3
extern const DigitalIO digitalIO_PTA4;          //!< DigitalIO on pin PTA4
extern const DigitalIO digitalIO_PTA5;          //!< DigitalIO on pin PTA5
extern const DigitalIO digitalIO_PTA6;          //!< DigitalIO on pin PTA6
extern const DigitalIO digitalIO_PTA7;          //!< DigitalIO on pin PTA7
extern const DigitalIO digitalIO_PTB0;          //!< DigitalIO on pin PTB0
extern const DigitalIO digitalIO_PTB1;          //!< DigitalIO on pin PTB1
extern const DigitalIO digitalIO_PTB2;          //!< DigitalIO on pin PTB2
extern const DigitalIO digitalIO_PTB3;          //!< DigitalIO on pin PTB3
extern const DigitalIO digitalIO_PTB4;          //!< DigitalIO on pin PTB4
extern const DigitalIO digitalIO_PTB5;          //!< DigitalIO on pin PTB5
extern const DigitalIO digitalIO_PTB6;          //!< DigitalIO on pin PTB6
extern const DigitalIO digitalIO_PTB7;          //!< DigitalIO on pin PTB7
extern const DigitalIO digitalIO_PTC0;          //!< DigitalIO on pin PTC0
extern const DigitalIO digitalIO_PTC1;          //!< DigitalIO on pin PTC1
extern const DigitalIO digitalIO_PTC2;          //!< DigitalIO on pin PTC2
extern const DigitalIO digitalIO_PTC3;          //!< DigitalIO on pin PTC3
extern const DigitalIO digitalIO_PTC4;          //!< DigitalIO on pin PTC4
extern const DigitalIO digitalIO_PTC5;          //!< DigitalIO on pin PTC5
extern const DigitalIO digitalIO_PTC6;          //!< DigitalIO on pin PTC6
extern const DigitalIO digitalIO_PTC7;          //!< DigitalIO on pin PTC7
extern const DigitalIO digitalIO_PTD0;          //!< DigitalIO on pin PTD0
extern const DigitalIO digitalIO_PTD1;          //!< DigitalIO on pin PTD1
extern const DigitalIO digitalIO_PTD2;          //!< DigitalIO on pin PTD2
extern const DigitalIO digitalIO_PTD3;          //!< DigitalIO on pin PTD3
extern const DigitalIO digitalIO_PTD4;          //!< DigitalIO on pin PTD4
extern const DigitalIO digitalIO_PTD5;          //!< DigitalIO on pin PTD5
extern const DigitalIO digitalIO_PTD6;          //!< DigitalIO on pin PTD6
extern const DigitalIO digitalIO_PTD7;          //!< DigitalIO on pin PTD7
extern const DigitalIO digitalIO_PTE0;          //!< DigitalIO on pin PTE0
extern const DigitalIO digitalIO_PTE1;          //!< DigitalIO on pin PTE1
extern const DigitalIO digitalIO_PTE2;          //!< DigitalIO on pin PTE2
extern const DigitalIO digitalIO_PTE3;          //!< DigitalIO on pin PTE3
extern const DigitalIO digitalIO_PTE4;          //!< DigitalIO on pin PTE4
extern const DigitalIO digitalIO_PTE5;          //!< DigitalIO on pin PTE5
extern const DigitalIO digitalIO_PTE6;          //!< DigitalIO on pin PTE6
extern const DigitalIO digitalIO_PTE7;          //!< DigitalIO on pin PTE7
extern const DigitalIO digitalIO_PTF0;          //!< DigitalIO on pin PTF0
extern const DigitalIO digitalIO_PTF1;          //!< DigitalIO on pin PTF1
extern const DigitalIO digitalIO_PTF2;          //!< DigitalIO on pin PTF2
extern const DigitalIO digitalIO_PTF3;          //!< DigitalIO on pin PTF3
extern const DigitalIO digitalIO_PTF4;          //!< DigitalIO on pin PTF4
extern const DigitalIO digitalIO_PTF5;          //!< DigitalIO on pin PTF5
extern const DigitalIO digitalIO_PTF6;          //!< DigitalIO on pin PTF6
extern const DigitalIO digitalIO_PTF7;          //!< DigitalIO on pin PTF7
extern const DigitalIO digitalIO_PTG0;          //!< DigitalIO on pin PTG0
extern const DigitalIO digitalIO_PTG1;          //!< DigitalIO on pin PTG1
extern const DigitalIO digitalIO_PTG2;          //!< DigitalIO on pin PTG2
extern const DigitalIO digitalIO_PTG3;          //!< DigitalIO on pin PTG3
extern const DigitalIO digitalIO_PTG4;          //!< DigitalIO on pin PTG4
extern const DigitalIO digitalIO_PTG5;          //!< DigitalIO on pin PTG5
#define digitalIO_LED_RED    digitalIO_PTG5
extern const DigitalIO digitalIO_PTG6;          //!< DigitalIO on pin PTG6
#define digitalIO_LED_GREEN  digitalIO_PTG6
extern const DigitalIO digitalIO_PTG7;          //!< DigitalIO on pin PTG7
#define digitalIO_LED_BLUE   digitalIO_PTG7
extern const DigitalIO digitalIO_PTH0;          //!< DigitalIO on pin PTH0
extern const DigitalIO digitalIO_PTH1;          //!< DigitalIO on pin PTH1
extern const DigitalIO digitalIO_PTH2;          //!< DigitalIO on pin PTH2
extern const DigitalIO digitalIO_PTH3;          //!< DigitalIO on pin PTH3
extern const DigitalIO digitalIO_PTH4;          //!< DigitalIO on pin PTH4
extern const DigitalIO digitalIO_PTH5;          //!< DigitalIO on pin PTH5
extern const DigitalIO digitalIO_PTH6;          //!< DigitalIO on pin PTH6
extern const DigitalIO digitalIO_PTH7;          //!< DigitalIO on pin PTH7
extern const DigitalIO digitalIO_PTI0;          //!< DigitalIO on pin PTI0
extern const DigitalIO digitalIO_PTI1;          //!< DigitalIO on pin PTI1
extern const DigitalIO digitalIO_PTI2;          //!< DigitalIO on pin PTI2
extern const DigitalIO digitalIO_PTI3;          //!< DigitalIO on pin PTI3
extern const DigitalIO digitalIO_PTI4;          //!< DigitalIO on pin PTI4
extern const DigitalIO digitalIO_PTI5;          //!< DigitalIO on pin PTI5
extern const DigitalIO digitalIO_PTI6;          //!< DigitalIO on pin PTI6
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
ACMP0      SIM->SCGC    SIM_SCGC_ACMP0_MASK
ACMP1      SIM->SCGC    SIM_SCGC_ACMP1_MASK
ADC0       SIM->SCGC    SIM_SCGC_ADC0_MASK
CRC        SIM->SCGC    SIM_SCGC_CRC_MASK
FTM0       SIM->SCGC    SIM_SCGC_FTM0_MASK
FTM1       SIM->SCGC    SIM_SCGC_FTM1_MASK
FTM2       SIM->SCGC    SIM_SCGC_FTM2_MASK
I2C0       SIM->SCGC    SIM_SCGC_I2C0_MASK
I2C1       SIM->SCGC    SIM_SCGC_I2C1_MASK
IRQ        SIM->SCGC    SIM_SCGC_IRQ_MASK
KBI0       SIM->SCGC    SIM_SCGC_KBI0_MASK
KBI1       SIM->SCGC    SIM_SCGC_KBI1_MASK
MSCAN      SIM->SCGC    SIM_SCGC_MSCAN_MASK
PIT        SIM->SCGC    SIM_SCGC_PIT_MASK
PWT        SIM->SCGC    SIM_SCGC_PWT_MASK
RTC        SIM->SCGC    SIM_SCGC_RTC_MASK
SPI0       SIM->SCGC    SIM_SCGC_SPI0_MASK
SPI1       SIM->SCGC    SIM_SCGC_SPI1_MASK
SWD        SIM->SCGC    SIM_SCGC_SWD_MASK
UART0      SIM->SCGC    SIM_SCGC_UART0_MASK
UART1      SIM->SCGC    SIM_SCGC_UART1_MASK
UART2      SIM->SCGC    SIM_SCGC_UART2_MASK
*/


#endif /* GPIO_H_ */
