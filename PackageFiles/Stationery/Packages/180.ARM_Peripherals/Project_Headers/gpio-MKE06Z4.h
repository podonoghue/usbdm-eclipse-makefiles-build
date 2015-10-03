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
extern const DigitalIO digitalIO_PTA0;          //!< DigitalIO on PTA0
extern const DigitalIO digitalIO_PTA1;          //!< DigitalIO on PTA1
extern const DigitalIO digitalIO_PTA2;          //!< DigitalIO on PTA2
extern const DigitalIO digitalIO_PTA3;          //!< DigitalIO on PTA3
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
extern const DigitalIO digitalIO_PTI4;          //!< DigitalIO on PTI4
extern const DigitalIO digitalIO_PTI5;          //!< DigitalIO on PTI5
extern const DigitalIO digitalIO_PTI6;          //!< DigitalIO on PTI6
/**
 * @}
 */
/*
ADC0_SE0,PTA0,[,Disabled, PTA0,]
ADC0_SE1,PTA1,[,Disabled, PTA1,]
ADC0_SE2,PTA6,[,Disabled, PTA6,]
ADC0_SE3,PTA7,[,Disabled, PTA7,]
ADC0_SE4,PTB0,[,Disabled, PTB0,]
ADC0_SE5,PTB1,[,Disabled, PTB1,]
ADC0_SE6,PTB2,[,Disabled, PTB2,]
ADC0_SE7,PTB3,[,Disabled, PTB3,]
ADC0_SE8,PTC0,[,Disabled, PTC0,]
ADC0_SE9,PTC1,[,Disabled, PTC1,]
ADC0_SE10,PTC2,[,Disabled, PTC2,]
ADC0_SE11,PTC3,[,Disabled, PTC3,]
ADC0_SE12,PTF4,[,Disabled, PTF4,]
ADC0_SE13,PTF5,[,Disabled, PTF5,]
ADC0_SE14,PTF6,[,Disabled, PTF6,]
ADC0_SE15,PTF7,[,Disabled, PTF7,]
FTM0_CH0,Disabled,[,Disabled, PTA0, PTB2,]
FTM0_CH1,Disabled,[,Disabled, PTA1, PTB3,]
FTM1_CH0,Disabled,[,Disabled, PTC4, PTH2,]
FTM1_CH1,Disabled,[,Disabled, PTC5, PTE7,]
FTM2_CH0,Disabled,[,Disabled, PTC0, PTF0, PTH0,]
FTM2_CH1,Disabled,[,Disabled, PTC1, PTF1, PTH1,]
FTM2_CH2,Disabled,[,Disabled, PTC2, PTD0, PTG4,]
FTM2_CH3,Disabled,[,Disabled, PTC3, PTD1, PTG5,]
FTM2_CH4,Disabled,[,Disabled, PTB4, PTG6,]
FTM2_CH5,Disabled,[,Disabled, PTB5, PTG7,]
I2C0_SCL,Disabled,[,Disabled, PTA3, PTB7,]
I2C0_4WSDAOUT,Disabled,[,Disabled, PTA1,]
I2C0_SDA,Disabled,[,Disabled, PTA2, PTB6,]
I2C0_4WSCLOUT,Disabled,[,Disabled, PTA0,]
I2C1_SDA,Disabled,[,Disabled, PTE0, PTH3,]
I2C1_SCL,Disabled,[,Disabled, PTE1, PTH4,]
SPI0_MISO,Disabled,[,Disabled, PTB4, PTE2,]
SPI0_MOSI,Disabled,[,Disabled, PTB3, PTE1,]
SPI0_PCS,Disabled,[,Disabled, PTB5, PTE3,]
SPI0_SCK,Disabled,[,Disabled, PTB2, PTE0,]
SPI1_MISO,Disabled,[,Disabled, PTD2, PTG6,]
SPI1_MOSI,Disabled,[,Disabled, PTD1, PTG5,]
SPI1_PCS,Disabled,[,Disabled, PTD3, PTG7,]
SPI1_SCK,Disabled,[,Disabled, PTD0, PTG4,]

ADC0,SIM->SCGC,SIM_SCGC_ADC0_MASK
I2C0,SIM->SCGC,SIM_SCGC_I2C0_MASK
I2C1,SIM->SCGC,SIM_SCGC_I2C1_MASK
SPI0,SIM->SCGC,SIM_SCGC_SPI0_MASK
SPI1,SIM->SCGC,SIM_SCGC_SPI1_MASK
FTM0,SIM->SCGC,SIM_SCGC_FTM0_MASK
FTM1,SIM->SCGC,SIM_SCGC_FTM1_MASK
FTM2,SIM->SCGC,SIM_SCGC_FTM2_MASK
*/

#endif /* GPIO_H_ */
