/**
 * @file      gpio.h (derived from gpio-MKM33Z5.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKM33Z5
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
#define digitalIO_LED_RED    digitalIO_PTA0
extern const DigitalIO digitalIO_PTA1;          //!< DigitalIO on pin PTA1
#define digitalIO_LED_GREEN  digitalIO_PTA1
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
#define digitalIO_LED_BLUE   digitalIO_PTD1
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
extern const DigitalIO digitalIO_PTG6;          //!< DigitalIO on pin PTG6
extern const DigitalIO digitalIO_PTG7;          //!< DigitalIO on pin PTG7
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
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTC5_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE0;     //!< AnalogueIO on pin PTC5
#endif
#if (PTC6_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE1;     //!< AnalogueIO on pin PTC6
#endif
#if (PTC7_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE2;     //!< AnalogueIO on pin PTC7
#endif
#if (PTD4_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE3;     //!< AnalogueIO on pin PTD4
#endif
#if (PTD5_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE4;     //!< AnalogueIO on pin PTD5
#endif
#if (PTD6_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE5;     //!< AnalogueIO on pin PTD6
#endif
#if (PTE7_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE6;     //!< AnalogueIO on pin PTE7
#endif
#if (PTF0_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE7;     //!< AnalogueIO on pin PTF0
#endif
#if (PTF1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE8;     //!< AnalogueIO on pin PTF1
#endif
#if (PTF2_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE9;     //!< AnalogueIO on pin PTF2
#endif
#if (PTG1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE10;    //!< AnalogueIO on pin PTG1
#endif
#if (PTG2_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE11;    //!< AnalogueIO on pin PTG2
#endif
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
ADC0       SIM->SCGC6   SIM_SCGC6_ADC_MASK
AFE        SIM->SCGC6   SIM_SCGC6_AFE_MASK
CMP0       SIM->SCGC4   SIM_SCGC4_CMP0_MASK
CMP1       SIM->SCGC4   SIM_SCGC4_CMP1_MASK
CRC        SIM->SCGC6   SIM_SCGC6_CRC_MASK
DMA        SIM->SCGC7   SIM_SCGC7_DMA_MASK
DMAMUX0    SIM->SCGC6   SIM_SCGC6_DMAMUX0_MASK
DMAMUX1    SIM->SCGC6   SIM_SCGC6_DMAMUX1_MASK
DMAMUX2    SIM->SCGC6   SIM_SCGC6_DMAMUX2_MASK
DMAMUX3    SIM->SCGC6   SIM_SCGC6_DMAMUX3_MASK
EWM        SIM->SCGC4   SIM_SCGC4_EWM_MASK
I2C0       SIM->SCGC4   SIM_SCGC4_I2C0_MASK
I2C1       SIM->SCGC4   SIM_SCGC4_I2C1_MASK
IRTC       SIM->SCGC5   SIM_SCGC5_IRTC_MASK
IRTCREGFILE SIM->SCGC5   SIM_SCGC5_IRTCREGFILE_MASK
LPTMR0     SIM->SCGC6   SIM_SCGC6_LPTMR_MASK
MCG        SIM->SCGC4   SIM_SCGC4_MCG_MASK
MPU        SIM->SCGC7   SIM_SCGC7_MPU_MASK
OSC        SIM->SCGC4   SIM_SCGC4_OSC_MASK
PIT0       SIM->SCGC6   SIM_SCGC6_PIT0_MASK
PIT1       SIM->SCGC6   SIM_SCGC6_PIT1_MASK
PORTA      SIM->SCGC5   SIM_SCGC5_PORTA_MASK
PORTB      SIM->SCGC5   SIM_SCGC5_PORTB_MASK
PORTC      SIM->SCGC5   SIM_SCGC5_PORTC_MASK
PORTD      SIM->SCGC5   SIM_SCGC5_PORTD_MASK
PORTE      SIM->SCGC5   SIM_SCGC5_PORTE_MASK
PORTF      SIM->SCGC5   SIM_SCGC5_PORTF_MASK
PORTG      SIM->SCGC5   SIM_SCGC5_PORTG_MASK
PORTH      SIM->SCGC5   SIM_SCGC5_PORTH_MASK
PORTI      SIM->SCGC5   SIM_SCGC5_PORTI_MASK
RNGA       SIM->SCGC6   SIM_SCGC6_RNGA_MASK
SIM_HP     SIM->SCGC6   SIM_SCGC6_SIM_HP_MASK
SIM_LP     SIM->SCGC6   SIM_SCGC6_SIM_LP_MASK
SLCD       SIM->SCGC5   SIM_SCGC5_SLCD_MASK
SPI0       SIM->SCGC4   SIM_SCGC4_SPI0_MASK
SPI1       SIM->SCGC4   SIM_SCGC4_SPI1_MASK
TMR0       SIM->SCGC5   SIM_SCGC5_TMR0_MASK
TMR1       SIM->SCGC5   SIM_SCGC5_TMR1_MASK
TMR2       SIM->SCGC5   SIM_SCGC5_TMR2_MASK
TMR3       SIM->SCGC5   SIM_SCGC5_TMR3_MASK
UART0      SIM->SCGC4   SIM_SCGC4_UART0_MASK
UART1      SIM->SCGC4   SIM_SCGC4_UART1_MASK
UART2      SIM->SCGC4   SIM_SCGC4_UART2_MASK
UART3      SIM->SCGC4   SIM_SCGC4_UART3_MASK
VREF       SIM->SCGC4   SIM_SCGC4_VREF_MASK
WDOG       SIM->SCGC5   SIM_SCGC5_WDOG_MASK
XBAR       SIM->SCGC5   SIM_SCGC5_XBAR_MASK
*/


#endif /* GPIO_H_ */
