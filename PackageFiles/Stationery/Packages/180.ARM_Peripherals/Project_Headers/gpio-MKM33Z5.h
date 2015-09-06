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
extern const DigitalIO digitalIO_PTA0;          //!< DigitalIO on PTA0
extern const DigitalIO digitalIO_PTA1;          //!< DigitalIO on PTA1
extern const DigitalIO digitalIO_PTA2;          //!< DigitalIO on PTA2
extern const DigitalIO digitalIO_PTA3;          //!< DigitalIO on PTA3
extern const DigitalIO digitalIO_PTA4;          //!< DigitalIO on PTA4
extern const DigitalIO digitalIO_PTA5;          //!< DigitalIO on PTA5
extern const DigitalIO digitalIO_PTA6;          //!< DigitalIO on PTA6
extern const DigitalIO digitalIO_PTA7;          //!< DigitalIO on PTA7
extern const DigitalIO digitalIO_PTB0;          //!< DigitalIO on PTB0
extern const DigitalIO digitalIO_PTB1;          //!< DigitalIO on PTB1
extern const DigitalIO digitalIO_PTB2;          //!< DigitalIO on PTB2
extern const DigitalIO digitalIO_PTB3;          //!< DigitalIO on PTB3
extern const DigitalIO digitalIO_PTB4;          //!< DigitalIO on PTB4
extern const DigitalIO digitalIO_PTB5;          //!< DigitalIO on PTB5
extern const DigitalIO digitalIO_PTB6;          //!< DigitalIO on PTB6
extern const DigitalIO digitalIO_PTB7;          //!< DigitalIO on PTB7
extern const DigitalIO digitalIO_PTC0;          //!< DigitalIO on PTC0
extern const DigitalIO digitalIO_PTC1;          //!< DigitalIO on PTC1
extern const DigitalIO digitalIO_PTC2;          //!< DigitalIO on PTC2
extern const DigitalIO digitalIO_PTC3;          //!< DigitalIO on PTC3
extern const DigitalIO digitalIO_PTC4;          //!< DigitalIO on PTC4
extern const DigitalIO digitalIO_PTC5;          //!< DigitalIO on PTC5
extern const DigitalIO digitalIO_PTC6;          //!< DigitalIO on PTC6
extern const DigitalIO digitalIO_PTC7;          //!< DigitalIO on PTC7
extern const DigitalIO digitalIO_PTD0;          //!< DigitalIO on PTD0
extern const DigitalIO digitalIO_PTD1;          //!< DigitalIO on PTD1
extern const DigitalIO digitalIO_PTD2;          //!< DigitalIO on PTD2
extern const DigitalIO digitalIO_PTD3;          //!< DigitalIO on PTD3
extern const DigitalIO digitalIO_PTD4;          //!< DigitalIO on PTD4
extern const DigitalIO digitalIO_PTD5;          //!< DigitalIO on PTD5
extern const DigitalIO digitalIO_PTD6;          //!< DigitalIO on PTD6
extern const DigitalIO digitalIO_PTD7;          //!< DigitalIO on PTD7
extern const DigitalIO digitalIO_PTE0;          //!< DigitalIO on PTE0
extern const DigitalIO digitalIO_PTE1;          //!< DigitalIO on PTE1
extern const DigitalIO digitalIO_PTE2;          //!< DigitalIO on PTE2
extern const DigitalIO digitalIO_PTE3;          //!< DigitalIO on PTE3
extern const DigitalIO digitalIO_PTE4;          //!< DigitalIO on PTE4
extern const DigitalIO digitalIO_PTE5;          //!< DigitalIO on PTE5
extern const DigitalIO digitalIO_PTE6;          //!< DigitalIO on PTE6
extern const DigitalIO digitalIO_PTE7;          //!< DigitalIO on PTE7
extern const DigitalIO digitalIO_PTF0;          //!< DigitalIO on PTF0
extern const DigitalIO digitalIO_PTF1;          //!< DigitalIO on PTF1
extern const DigitalIO digitalIO_PTF2;          //!< DigitalIO on PTF2
extern const DigitalIO digitalIO_PTF3;          //!< DigitalIO on PTF3
extern const DigitalIO digitalIO_PTF4;          //!< DigitalIO on PTF4
extern const DigitalIO digitalIO_PTF5;          //!< DigitalIO on PTF5
extern const DigitalIO digitalIO_PTF6;          //!< DigitalIO on PTF6
extern const DigitalIO digitalIO_PTF7;          //!< DigitalIO on PTF7
extern const DigitalIO digitalIO_PTG0;          //!< DigitalIO on PTG0
extern const DigitalIO digitalIO_PTG1;          //!< DigitalIO on PTG1
extern const DigitalIO digitalIO_PTG2;          //!< DigitalIO on PTG2
extern const DigitalIO digitalIO_PTG3;          //!< DigitalIO on PTG3
extern const DigitalIO digitalIO_PTG4;          //!< DigitalIO on PTG4
extern const DigitalIO digitalIO_PTG5;          //!< DigitalIO on PTG5
extern const DigitalIO digitalIO_PTG6;          //!< DigitalIO on PTG6
extern const DigitalIO digitalIO_PTG7;          //!< DigitalIO on PTG7
extern const DigitalIO digitalIO_PTH0;          //!< DigitalIO on PTH0
extern const DigitalIO digitalIO_PTH1;          //!< DigitalIO on PTH1
extern const DigitalIO digitalIO_PTH2;          //!< DigitalIO on PTH2
extern const DigitalIO digitalIO_PTH3;          //!< DigitalIO on PTH3
extern const DigitalIO digitalIO_PTH4;          //!< DigitalIO on PTH4
extern const DigitalIO digitalIO_PTH5;          //!< DigitalIO on PTH5
extern const DigitalIO digitalIO_PTH6;          //!< DigitalIO on PTH6
extern const DigitalIO digitalIO_PTH7;          //!< DigitalIO on PTH7
extern const DigitalIO digitalIO_PTI0;          //!< DigitalIO on PTI0
extern const DigitalIO digitalIO_PTI1;          //!< DigitalIO on PTI1
extern const DigitalIO digitalIO_PTI2;          //!< DigitalIO on PTI2
extern const DigitalIO digitalIO_PTI3;          //!< DigitalIO on PTI3
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if ADC0_0_SEL == 1
extern const AnalogueIO analogueIO_PTC5;         //!< AnalogueIO on PTC5
#endif
#if ADC0_1_SEL == 1
extern const AnalogueIO analogueIO_PTC6;         //!< AnalogueIO on PTC6
#endif
#if ADC0_2_SEL == 1
extern const AnalogueIO analogueIO_PTC7;         //!< AnalogueIO on PTC7
#endif
#if ADC0_3_SEL == 1
extern const AnalogueIO analogueIO_PTD4;         //!< AnalogueIO on PTD4
#endif
#if ADC0_4_SEL == 1
extern const AnalogueIO analogueIO_PTD5;         //!< AnalogueIO on PTD5
#endif
#if ADC0_5_SEL == 1
extern const AnalogueIO analogueIO_PTD6;         //!< AnalogueIO on PTD6
#endif
#if ADC0_6_SEL == 1
extern const AnalogueIO analogueIO_PTE7;         //!< AnalogueIO on PTE7
#endif
#if ADC0_7_SEL == 1
extern const AnalogueIO analogueIO_PTF0;         //!< AnalogueIO on PTF0
#endif
#if ADC0_8_SEL == 1
extern const AnalogueIO analogueIO_PTF1;         //!< AnalogueIO on PTF1
#endif
#if ADC0_9_SEL == 1
extern const AnalogueIO analogueIO_PTF2;         //!< AnalogueIO on PTF2
#endif
#if ADC0_10_SEL == 1
extern const AnalogueIO analogueIO_PTG1;         //!< AnalogueIO on PTG1
#endif
#if ADC0_11_SEL == 1
extern const AnalogueIO analogueIO_PTG2;         //!< AnalogueIO on PTG2
#endif
/**
 * @}
 */
/**
* @addtogroup alias_pin_mappings_GROUP Aliases for pins
* @brief Aliases for port pins for example Arduino based names
* @{
*/
/**
 * @}
 */
/*
ADC0_0=PTC5=[Disabled, PTC5]
ADC0_1=PTC6=[Disabled, PTC6]
ADC0_2=PTC7=[Disabled, PTC7]
ADC0_3=PTD4=[Disabled, PTD4]
ADC0_4=PTD5=[Disabled, PTD5]
ADC0_5=PTD6=[Disabled, PTD6]
ADC0_6=PTE7=[Disabled, PTE7]
ADC0_7=PTF0=[Disabled, PTF0]
ADC0_8=PTF1=[Disabled, PTF1]
ADC0_9=PTF2=[Disabled, PTF2]
ADC0_10=PTG1=[Disabled, PTG1]
ADC0_11=PTG2=[Disabled, PTG2]
I2C0_SCL=Disabled=[Disabled, PTD7, PTE6, PTG3]
I2C0_SDA=Disabled=[Disabled, PTE0, PTE7, PTG4]
I2C1_SDA=Disabled=[Disabled, PTE2, PTF6]
I2C1_SCL=Disabled=[Disabled, PTE3, PTF5]
SPI0_MISO=Disabled=[Disabled, PTD4, PTG5]
SPI0_MOSI=Disabled=[Disabled, PTD3, PTG4]
SPI0_SCK=Disabled=[Disabled, PTD2, PTG3]
SPI1_MISO=Disabled=[Disabled, PTF5, PTI0, PTI1]
SPI1_MOSI=Disabled=[Disabled, PTF6, PTI0, PTI1]
SPI1_SCK=Disabled=[Disabled, PTF4, PTH7]

SPI1=SIM->SCGC4=SIM_SCGC4_SPI1_MASK
SPI0=SIM->SCGC4=SIM_SCGC4_SPI0_MASK
ADC0=SIM->SCGC6=SIM_SCGC6_ADC_MASK
I2C1=SIM->SCGC4=SIM_SCGC4_I2C1_MASK
I2C0=SIM->SCGC4=SIM_SCGC4_I2C0_MASK
*/

#endif /* GPIO_H_ */
