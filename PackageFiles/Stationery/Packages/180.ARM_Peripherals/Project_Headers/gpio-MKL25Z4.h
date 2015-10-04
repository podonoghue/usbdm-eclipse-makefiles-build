/**
 * @file      gpio.h (derived from gpio-MKL25Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKL25Z4
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
extern const DigitalIO digitalIO_PTA0;                    //!< DigitalIO on PTA0
extern const DigitalIO digitalIO_PTA1;                    //!< DigitalIO on PTA1
#define digitalIO_D0 digitalIO_PTA1
extern const DigitalIO digitalIO_PTA2;                    //!< DigitalIO on PTA2
#define digitalIO_D1 digitalIO_PTA2
extern const DigitalIO digitalIO_PTA3;                    //!< DigitalIO on PTA3
extern const DigitalIO digitalIO_PTA4;                    //!< DigitalIO on PTA4
#define digitalIO_D4 digitalIO_PTA4
extern const DigitalIO digitalIO_PTA5;                    //!< DigitalIO on PTA5
#define digitalIO_D5 digitalIO_PTA5
extern const DigitalIO digitalIO_PTA12;                   //!< DigitalIO on PTA12
#define digitalIO_D3 digitalIO_PTA12
extern const DigitalIO digitalIO_PTA13;                   //!< DigitalIO on PTA13
#define digitalIO_D8 digitalIO_PTA13
extern const DigitalIO digitalIO_PTA14;                   //!< DigitalIO on PTA14
extern const DigitalIO digitalIO_PTA15;                   //!< DigitalIO on PTA15
extern const DigitalIO digitalIO_PTA16;                   //!< DigitalIO on PTA16
#define digitalIO_D28 digitalIO_PTA16
extern const DigitalIO digitalIO_PTA17;                   //!< DigitalIO on PTA17
#define digitalIO_D29 digitalIO_PTA17
extern const DigitalIO digitalIO_PTA18;                   //!< DigitalIO on PTA18
extern const DigitalIO digitalIO_PTA19;                   //!< DigitalIO on PTA19
extern const DigitalIO digitalIO_PTA20;                   //!< DigitalIO on PTA20
extern const DigitalIO digitalIO_PTB0;                    //!< DigitalIO on PTB0
#define digitalIO_A0 digitalIO_PTB0
extern const DigitalIO digitalIO_PTB1;                    //!< DigitalIO on PTB1
#define digitalIO_A1 digitalIO_PTB1
extern const DigitalIO digitalIO_PTB2;                    //!< DigitalIO on PTB2
#define digitalIO_A2 digitalIO_PTB2
extern const DigitalIO digitalIO_PTB3;                    //!< DigitalIO on PTB3
#define digitalIO_A3 digitalIO_PTB3
extern const DigitalIO digitalIO_PTB8;                    //!< DigitalIO on PTB8
#define digitalIO_A20 digitalIO_PTB8
extern const DigitalIO digitalIO_PTB9;                    //!< DigitalIO on PTB9
#define digitalIO_A19 digitalIO_PTB9
extern const DigitalIO digitalIO_PTB10;                   //!< DigitalIO on PTB10
#define digitalIO_A18 digitalIO_PTB10
extern const DigitalIO digitalIO_PTB11;                   //!< DigitalIO on PTB11
#define digitalIO_A17 digitalIO_PTB11
extern const DigitalIO digitalIO_PTB16;                   //!< DigitalIO on PTB16
extern const DigitalIO digitalIO_PTB17;                   //!< DigitalIO on PTB17
extern const DigitalIO digitalIO_PTB18;                   //!< DigitalIO on PTB18
extern const DigitalIO digitalIO_PTB19;                   //!< DigitalIO on PTB19
extern const DigitalIO digitalIO_PTC0;                    //!< DigitalIO on PTC0
#define digitalIO_D17 digitalIO_PTC0
extern const DigitalIO digitalIO_PTC1;                    //!< DigitalIO on PTC1
#define digitalIO_A5 digitalIO_PTC1
extern const DigitalIO digitalIO_PTC2;                    //!< DigitalIO on PTC2
#define digitalIO_A4 digitalIO_PTC2
extern const DigitalIO digitalIO_PTC3;                    //!< DigitalIO on PTC3
#define digitalIO_D18 digitalIO_PTC3
extern const DigitalIO digitalIO_PTC4;                    //!< DigitalIO on PTC4
#define digitalIO_D19 digitalIO_PTC4
extern const DigitalIO digitalIO_PTC5;                    //!< DigitalIO on PTC5
#define digitalIO_D20 digitalIO_PTC5
extern const DigitalIO digitalIO_PTC6;                    //!< DigitalIO on PTC6
#define digitalIO_D21 digitalIO_PTC6
extern const DigitalIO digitalIO_PTC7;                    //!< DigitalIO on PTC7
#define digitalIO_D16 digitalIO_PTC7
extern const DigitalIO digitalIO_PTC8;                    //!< DigitalIO on PTC8
#define digitalIO_D6 digitalIO_PTC8
extern const DigitalIO digitalIO_PTC9;                    //!< DigitalIO on PTC9
#define digitalIO_D7 digitalIO_PTC9
extern const DigitalIO digitalIO_PTC10;                   //!< DigitalIO on PTC10
#define digitalIO_D22 digitalIO_PTC10
extern const DigitalIO digitalIO_PTC11;                   //!< DigitalIO on PTC11
#define digitalIO_D23 digitalIO_PTC11
extern const DigitalIO digitalIO_PTC12;                   //!< DigitalIO on PTC12
#define digitalIO_D24 digitalIO_PTC12
extern const DigitalIO digitalIO_PTC13;                   //!< DigitalIO on PTC13
#define digitalIO_D25 digitalIO_PTC13
extern const DigitalIO digitalIO_PTC16;                   //!< DigitalIO on PTC16
#define digitalIO_D26 digitalIO_PTC16
extern const DigitalIO digitalIO_PTC17;                   //!< DigitalIO on PTC17
#define digitalIO_D27 digitalIO_PTC17
extern const DigitalIO digitalIO_PTD0;                    //!< DigitalIO on PTD0
#define digitalIO_D10 digitalIO_PTD0
extern const DigitalIO digitalIO_PTD1;                    //!< DigitalIO on PTD1
#define digitalIO_D13 digitalIO_PTD1
extern const DigitalIO digitalIO_PTD2;                    //!< DigitalIO on PTD2
#define digitalIO_D11 digitalIO_PTD2
extern const DigitalIO digitalIO_PTD3;                    //!< DigitalIO on PTD3
#define digitalIO_D12 digitalIO_PTD3
extern const DigitalIO digitalIO_PTD4;                    //!< DigitalIO on PTD4
#define digitalIO_D2 digitalIO_PTD4
extern const DigitalIO digitalIO_PTD5;                    //!< DigitalIO on PTD5
#define digitalIO_D9 digitalIO_PTD5
extern const DigitalIO digitalIO_PTD6;                    //!< DigitalIO on PTD6
#define digitalIO_D32 digitalIO_PTD6
extern const DigitalIO digitalIO_PTD7;                    //!< DigitalIO on PTD7
#define digitalIO_D33 digitalIO_PTD7
extern const DigitalIO digitalIO_PTE0;                    //!< DigitalIO on PTE0
#define digitalIO_D15 digitalIO_PTE0
extern const DigitalIO digitalIO_PTE1;                    //!< DigitalIO on PTE1
#define digitalIO_D14 digitalIO_PTE1
extern const DigitalIO digitalIO_PTE2;                    //!< DigitalIO on PTE2
#define digitalIO_A16 digitalIO_PTE2
extern const DigitalIO digitalIO_PTE3;                    //!< DigitalIO on PTE3
#define digitalIO_A15 digitalIO_PTE3
extern const DigitalIO digitalIO_PTE4;                    //!< DigitalIO on PTE4
#define digitalIO_A14 digitalIO_PTE4
extern const DigitalIO digitalIO_PTE5;                    //!< DigitalIO on PTE5
#define digitalIO_A13 digitalIO_PTE5
extern const DigitalIO digitalIO_PTE20;                   //!< DigitalIO on PTE20
#define digitalIO_A11 digitalIO_PTE20
extern const DigitalIO digitalIO_PTE21;                   //!< DigitalIO on PTE21
#define digitalIO_A10 digitalIO_PTE21
extern const DigitalIO digitalIO_PTE22;                   //!< DigitalIO on PTE22
#define digitalIO_A9 digitalIO_PTE22
extern const DigitalIO digitalIO_PTE23;                   //!< DigitalIO on PTE23
#define digitalIO_A8 digitalIO_PTE23
extern const DigitalIO digitalIO_PTE24;                   //!< DigitalIO on PTE24
extern const DigitalIO digitalIO_PTE25;                   //!< DigitalIO on PTE25
extern const DigitalIO digitalIO_PTE29;                   //!< DigitalIO on PTE29
#define digitalIO_A7 digitalIO_PTE29
extern const DigitalIO digitalIO_PTE30;                   //!< DigitalIO on PTE30
#define digitalIO_A6 digitalIO_PTE30
extern const DigitalIO digitalIO_PTE31;                   //!< DigitalIO on PTE31
#define digitalIO_D30 digitalIO_PTE31
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const AnalogueIO analogueIO_PTB0;                    //!< AnalogueIO on PTB0
#define analogueIO_A0 analogueIO_PTB0
extern const AnalogueIO analogueIO_PTB1;                    //!< AnalogueIO on PTB1
#define analogueIO_A1 analogueIO_PTB1
extern const AnalogueIO analogueIO_PTB2;                    //!< AnalogueIO on PTB2
#define analogueIO_A2 analogueIO_PTB2
extern const AnalogueIO analogueIO_PTB3;                    //!< AnalogueIO on PTB3
#define analogueIO_A3 analogueIO_PTB3
extern const AnalogueIO analogueIO_PTC0;                    //!< AnalogueIO on PTC0
#define analogueIO_D17 analogueIO_PTC0
extern const AnalogueIO analogueIO_PTC1;                    //!< AnalogueIO on PTC1
#define analogueIO_A5 analogueIO_PTC1
extern const AnalogueIO analogueIO_PTC2;                    //!< AnalogueIO on PTC2
#define analogueIO_A4 analogueIO_PTC2
extern const AnalogueIO analogueIO_PTD1;                    //!< AnalogueIO on PTD1
#define analogueIO_D13 analogueIO_PTD1
extern const AnalogueIO analogueIO_PTD5;                    //!< AnalogueIO on PTD5
#define analogueIO_D9 analogueIO_PTD5
extern const AnalogueIO analogueIO_PTD6;                    //!< AnalogueIO on PTD6
#define analogueIO_D32 analogueIO_PTD6
extern const AnalogueIO analogueIO_PTE20;                   //!< AnalogueIO on PTE20
#define analogueIO_A11 analogueIO_PTE20
extern const AnalogueIO analogueIO_PTE20_1;                 //!< AnalogueIO on PTE20
#define analogueIO_A11 analogueIO_PTE20
extern const AnalogueIO analogueIO_PTE21;                   //!< AnalogueIO on PTE21
#define analogueIO_A10 analogueIO_PTE21
extern const AnalogueIO analogueIO_PTE21_1;                 //!< AnalogueIO on PTE21
#define analogueIO_A10 analogueIO_PTE21
extern const AnalogueIO analogueIO_PTE22;                   //!< AnalogueIO on PTE22
#define analogueIO_A9 analogueIO_PTE22
extern const AnalogueIO analogueIO_PTE22_1;                 //!< AnalogueIO on PTE22
#define analogueIO_A9 analogueIO_PTE22
extern const AnalogueIO analogueIO_PTE23;                   //!< AnalogueIO on PTE23
#define analogueIO_A8 analogueIO_PTE23
extern const AnalogueIO analogueIO_PTE23_1;                 //!< AnalogueIO on PTE23
#define analogueIO_A8 analogueIO_PTE23
extern const AnalogueIO analogueIO_PTE29;                   //!< AnalogueIO on PTE29
#define analogueIO_A7 analogueIO_PTE29
extern const AnalogueIO analogueIO_PTE30;                   //!< AnalogueIO on PTE30
#define analogueIO_A6 analogueIO_PTE30
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
extern const PwmIO  pwmIO_PTA0;                    //!< PwmIO on PTA0
extern const PwmIO  pwmIO_PTA1;                    //!< PwmIO on PTA1
#define pwmIO_D0 pwmIO_PTA1
extern const PwmIO  pwmIO_PTA2;                    //!< PwmIO on PTA2
#define pwmIO_D1 pwmIO_PTA2
extern const PwmIO  pwmIO_PTA3;                    //!< PwmIO on PTA3
extern const PwmIO  pwmIO_PTA4;                    //!< PwmIO on PTA4
#define pwmIO_D4 pwmIO_PTA4
extern const PwmIO  pwmIO_PTA5;                    //!< PwmIO on PTA5
#define pwmIO_D5 pwmIO_PTA5
extern const PwmIO  pwmIO_PTA12;                   //!< PwmIO on PTA12
#define pwmIO_D3 pwmIO_PTA12
extern const PwmIO  pwmIO_PTA13;                   //!< PwmIO on PTA13
#define pwmIO_D8 pwmIO_PTA13
extern const PwmIO  pwmIO_PTB0;                    //!< PwmIO on PTB0
#define pwmIO_A0 pwmIO_PTB0
extern const PwmIO  pwmIO_PTB1;                    //!< PwmIO on PTB1
#define pwmIO_A1 pwmIO_PTB1
extern const PwmIO  pwmIO_PTB2;                    //!< PwmIO on PTB2
#define pwmIO_A2 pwmIO_PTB2
extern const PwmIO  pwmIO_PTB3;                    //!< PwmIO on PTB3
#define pwmIO_A3 pwmIO_PTB3
extern const PwmIO  pwmIO_PTB18;                   //!< PwmIO on PTB18
extern const PwmIO  pwmIO_PTB19;                   //!< PwmIO on PTB19
extern const PwmIO  pwmIO_PTC1;                    //!< PwmIO on PTC1
#define pwmIO_A5 pwmIO_PTC1
extern const PwmIO  pwmIO_PTC2;                    //!< PwmIO on PTC2
#define pwmIO_A4 pwmIO_PTC2
extern const PwmIO  pwmIO_PTC3;                    //!< PwmIO on PTC3
#define pwmIO_D18 pwmIO_PTC3
extern const PwmIO  pwmIO_PTC4;                    //!< PwmIO on PTC4
#define pwmIO_D19 pwmIO_PTC4
extern const PwmIO  pwmIO_PTC8;                    //!< PwmIO on PTC8
#define pwmIO_D6 pwmIO_PTC8
extern const PwmIO  pwmIO_PTC9;                    //!< PwmIO on PTC9
#define pwmIO_D7 pwmIO_PTC9
extern const PwmIO  pwmIO_PTD0;                    //!< PwmIO on PTD0
#define pwmIO_D10 pwmIO_PTD0
extern const PwmIO  pwmIO_PTD1;                    //!< PwmIO on PTD1
#define pwmIO_D13 pwmIO_PTD1
extern const PwmIO  pwmIO_PTD2;                    //!< PwmIO on PTD2
#define pwmIO_D11 pwmIO_PTD2
extern const PwmIO  pwmIO_PTD3;                    //!< PwmIO on PTD3
#define pwmIO_D12 pwmIO_PTD3
extern const PwmIO  pwmIO_PTD4;                    //!< PwmIO on PTD4
#define pwmIO_D2 pwmIO_PTD4
extern const PwmIO  pwmIO_PTD5;                    //!< PwmIO on PTD5
#define pwmIO_D9 pwmIO_PTD5
extern const PwmIO  pwmIO_PTE20;                   //!< PwmIO on PTE20
#define pwmIO_A11 pwmIO_PTE20
extern const PwmIO  pwmIO_PTE21;                   //!< PwmIO on PTE21
#define pwmIO_A10 pwmIO_PTE21
extern const PwmIO  pwmIO_PTE22;                   //!< PwmIO on PTE22
#define pwmIO_A9 pwmIO_PTE22
extern const PwmIO  pwmIO_PTE23;                   //!< PwmIO on PTE23
#define pwmIO_A8 pwmIO_PTE23
extern const PwmIO  pwmIO_PTE24;                   //!< PwmIO on PTE24
extern const PwmIO  pwmIO_PTE25;                   //!< PwmIO on PTE25
extern const PwmIO  pwmIO_PTE29;                   //!< PwmIO on PTE29
#define pwmIO_A7 pwmIO_PTE29
extern const PwmIO  pwmIO_PTE30;                   //!< PwmIO on PTE30
#define pwmIO_A6 pwmIO_PTE30
extern const PwmIO  pwmIO_PTE31;                   //!< PwmIO on PTE31
#define pwmIO_D30 pwmIO_PTE31
/**
 * @}
 */
/*
Clock Information 
ADC0       SIM->SCGC6   SIM_SCGC6_ADC0_MASK
CMP        SIM->SCGC4   SIM_SCGC4_CMP_MASK
DAC0       SIM->SCGC6   SIM_SCGC6_DAC0_MASK
DMA        SIM->SCGC7   SIM_SCGC7_DMA_MASK
DMAMUX     SIM->SCGC6   SIM_SCGC6_DMAMUX_MASK
I2C0       SIM->SCGC4   SIM_SCGC4_I2C0_MASK
I2C1       SIM->SCGC4   SIM_SCGC4_I2C1_MASK
LPTMR0     SIM->SCGC5   SIM_SCGC5_LPTMR_MASK
PIT        SIM->SCGC6   SIM_SCGC6_PIT_MASK
PORTA      SIM->SCGC5   SIM_SCGC5_PORTA_MASK
PORTB      SIM->SCGC5   SIM_SCGC5_PORTB_MASK
PORTC      SIM->SCGC5   SIM_SCGC5_PORTC_MASK
PORTD      SIM->SCGC5   SIM_SCGC5_PORTD_MASK
PORTE      SIM->SCGC5   SIM_SCGC5_PORTE_MASK
RTC        SIM->SCGC6   SIM_SCGC6_RTC_MASK
SPI0       SIM->SCGC4   SIM_SCGC4_SPI0_MASK
SPI1       SIM->SCGC4   SIM_SCGC4_SPI1_MASK
TPM0       SIM->SCGC6   SIM_SCGC6_TPM0_MASK
TPM1       SIM->SCGC6   SIM_SCGC6_TPM1_MASK
TPM2       SIM->SCGC6   SIM_SCGC6_TPM2_MASK
TSI        SIM->SCGC5   SIM_SCGC5_TSI_MASK
UART0      SIM->SCGC4   SIM_SCGC4_UART0_MASK
UART1      SIM->SCGC4   SIM_SCGC4_UART1_MASK
UART2      SIM->SCGC4   SIM_SCGC4_UART2_MASK
USBOTG     SIM->SCGC4   SIM_SCGC4_USBOTG_MASK
*/


#endif /* GPIO_H_ */
