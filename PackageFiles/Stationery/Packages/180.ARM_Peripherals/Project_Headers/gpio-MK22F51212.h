/**
 * @file      gpio.h (derived from gpio-MK22F51212.h)
 * @version   1.0.0
 * @brief     Pin declarations for MK22F51212
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
#define digitalIO_D9 digitalIO_PTA1
extern const DigitalIO digitalIO_PTA2;                    //!< DigitalIO on PTA2
#define digitalIO_D3 digitalIO_PTA2
extern const DigitalIO digitalIO_PTA3;                    //!< DigitalIO on PTA3
extern const DigitalIO digitalIO_PTA4;                    //!< DigitalIO on PTA4
#define digitalIO_D4 digitalIO_PTA4
extern const DigitalIO digitalIO_PTA5;                    //!< DigitalIO on PTA5
extern const DigitalIO digitalIO_PTA12;                   //!< DigitalIO on PTA12
extern const DigitalIO digitalIO_PTA13;                   //!< DigitalIO on PTA13
extern const DigitalIO digitalIO_PTA14;                   //!< DigitalIO on PTA14
extern const DigitalIO digitalIO_PTA15;                   //!< DigitalIO on PTA15
extern const DigitalIO digitalIO_PTA16;                   //!< DigitalIO on PTA16
extern const DigitalIO digitalIO_PTA17;                   //!< DigitalIO on PTA17
extern const DigitalIO digitalIO_PTA18;                   //!< DigitalIO on PTA18
extern const DigitalIO digitalIO_PTA19;                   //!< DigitalIO on PTA19
extern const DigitalIO digitalIO_PTB0;                    //!< DigitalIO on PTB0
#define digitalIO_A0 digitalIO_PTB0
extern const DigitalIO digitalIO_PTB1;                    //!< DigitalIO on PTB1
#define digitalIO_A1 digitalIO_PTB1
extern const DigitalIO digitalIO_PTB2;                    //!< DigitalIO on PTB2
#define digitalIO_A5 digitalIO_PTB2
extern const DigitalIO digitalIO_PTB3;                    //!< DigitalIO on PTB3
#define digitalIO_A4 digitalIO_PTB3
extern const DigitalIO digitalIO_PTB6;                    //!< DigitalIO on PTB6
extern const DigitalIO digitalIO_PTB7;                    //!< DigitalIO on PTB7
extern const DigitalIO digitalIO_PTB8;                    //!< DigitalIO on PTB8
extern const DigitalIO digitalIO_PTB9;                    //!< DigitalIO on PTB9
extern const DigitalIO digitalIO_PTB10;                   //!< DigitalIO on PTB10
extern const DigitalIO digitalIO_PTB11;                   //!< DigitalIO on PTB11
extern const DigitalIO digitalIO_PTB16;                   //!< DigitalIO on PTB16
#define digitalIO_D2 digitalIO_PTB16
extern const DigitalIO digitalIO_PTB17;                   //!< DigitalIO on PTB17
extern const DigitalIO digitalIO_PTB18;                   //!< DigitalIO on PTB18
#define digitalIO_D5 digitalIO_PTB18
extern const DigitalIO digitalIO_PTB19;                   //!< DigitalIO on PTB19
#define digitalIO_D8 digitalIO_PTB19
extern const DigitalIO digitalIO_PTB20;                   //!< DigitalIO on PTB20
extern const DigitalIO digitalIO_PTB21;                   //!< DigitalIO on PTB21
extern const DigitalIO digitalIO_PTB22;                   //!< DigitalIO on PTB22
extern const DigitalIO digitalIO_PTB23;                   //!< DigitalIO on PTB23
extern const DigitalIO digitalIO_PTC0;                    //!< DigitalIO on PTC0
extern const DigitalIO digitalIO_PTC1;                    //!< DigitalIO on PTC1
#define digitalIO_A2 digitalIO_PTC1
extern const DigitalIO digitalIO_PTC2;                    //!< DigitalIO on PTC2
#define digitalIO_A3 digitalIO_PTC2
extern const DigitalIO digitalIO_PTC3;                    //!< DigitalIO on PTC3
#define digitalIO_D6 digitalIO_PTC3
extern const DigitalIO digitalIO_PTC4;                    //!< DigitalIO on PTC4
extern const DigitalIO digitalIO_PTC5;                    //!< DigitalIO on PTC5
extern const DigitalIO digitalIO_PTC6;                    //!< DigitalIO on PTC6
#define digitalIO_D7 digitalIO_PTC6
extern const DigitalIO digitalIO_PTC7;                    //!< DigitalIO on PTC7
extern const DigitalIO digitalIO_PTC8;                    //!< DigitalIO on PTC8
extern const DigitalIO digitalIO_PTC9;                    //!< DigitalIO on PTC9
extern const DigitalIO digitalIO_PTC10;                   //!< DigitalIO on PTC10
extern const DigitalIO digitalIO_PTC11;                   //!< DigitalIO on PTC11
extern const DigitalIO digitalIO_PTC12;                   //!< DigitalIO on PTC12
extern const DigitalIO digitalIO_PTC13;                   //!< DigitalIO on PTC13
extern const DigitalIO digitalIO_PTC14;                   //!< DigitalIO on PTC14
extern const DigitalIO digitalIO_PTC15;                   //!< DigitalIO on PTC15
extern const DigitalIO digitalIO_PTC16;                   //!< DigitalIO on PTC16
extern const DigitalIO digitalIO_PTC17;                   //!< DigitalIO on PTC17
extern const DigitalIO digitalIO_PTC18;                   //!< DigitalIO on PTC18
extern const DigitalIO digitalIO_PTC19;                   //!< DigitalIO on PTC19
extern const DigitalIO digitalIO_PTD0;                    //!< DigitalIO on PTD0
extern const DigitalIO digitalIO_PTD1;                    //!< DigitalIO on PTD1
extern const DigitalIO digitalIO_PTD2;                    //!< DigitalIO on PTD2
#define digitalIO_D0 digitalIO_PTD2
extern const DigitalIO digitalIO_PTD3;                    //!< DigitalIO on PTD3
#define digitalIO_D1 digitalIO_PTD3
extern const DigitalIO digitalIO_PTD4;                    //!< DigitalIO on PTD4
#define digitalIO_D10 digitalIO_PTD4
extern const DigitalIO digitalIO_PTD5;                    //!< DigitalIO on PTD5
#define digitalIO_D13 digitalIO_PTD5
extern const DigitalIO digitalIO_PTD6;                    //!< DigitalIO on PTD6
#define digitalIO_D11 digitalIO_PTD6
extern const DigitalIO digitalIO_PTD7;                    //!< DigitalIO on PTD7
#define digitalIO_D12 digitalIO_PTD7
extern const DigitalIO digitalIO_PTE0;                    //!< DigitalIO on PTE0
#define digitalIO_D14 digitalIO_PTE0
extern const DigitalIO digitalIO_PTE1;                    //!< DigitalIO on PTE1
#define digitalIO_D15 digitalIO_PTE1
extern const DigitalIO digitalIO_PTE2;                    //!< DigitalIO on PTE2
extern const DigitalIO digitalIO_PTE3;                    //!< DigitalIO on PTE3
extern const DigitalIO digitalIO_PTE4;                    //!< DigitalIO on PTE4
extern const DigitalIO digitalIO_PTE5;                    //!< DigitalIO on PTE5
extern const DigitalIO digitalIO_PTE6;                    //!< DigitalIO on PTE6
extern const DigitalIO digitalIO_PTE24;                   //!< DigitalIO on PTE24
extern const DigitalIO digitalIO_PTE25;                   //!< DigitalIO on PTE25
extern const DigitalIO digitalIO_PTE26;                   //!< DigitalIO on PTE26
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const AnalogueIO analogueIO_ADC0_DM0;                //!< AnalogueIO on ADC0_DM0
extern const AnalogueIO analogueIO_ADC0_DM0_1;              //!< AnalogueIO on ADC0_DM0
extern const AnalogueIO analogueIO_ADC0_DM1;                //!< AnalogueIO on ADC0_DM1
extern const AnalogueIO analogueIO_ADC0_DP0;                //!< AnalogueIO on ADC0_DP0
extern const AnalogueIO analogueIO_ADC0_DP0_1;              //!< AnalogueIO on ADC0_DP0
extern const AnalogueIO analogueIO_ADC0_DP1;                //!< AnalogueIO on ADC0_DP1
extern const AnalogueIO analogueIO_ADC0_SE23;               //!< AnalogueIO on ADC0_SE23
extern const AnalogueIO analogueIO_ADC1_DM0;                //!< AnalogueIO on ADC1_DM0
extern const AnalogueIO analogueIO_ADC1_DM0_1;              //!< AnalogueIO on ADC1_DM0
extern const AnalogueIO analogueIO_ADC1_DM1;                //!< AnalogueIO on ADC1_DM1
extern const AnalogueIO analogueIO_ADC1_DM1_1;              //!< AnalogueIO on ADC1_DM1
extern const AnalogueIO analogueIO_ADC1_DP0;                //!< AnalogueIO on ADC1_DP0
extern const AnalogueIO analogueIO_ADC1_DP0_1;              //!< AnalogueIO on ADC1_DP0
extern const AnalogueIO analogueIO_ADC1_DP1;                //!< AnalogueIO on ADC1_DP1
extern const AnalogueIO analogueIO_ADC1_DP1_1;              //!< AnalogueIO on ADC1_DP1
extern const AnalogueIO analogueIO_ADC1_SE18;               //!< AnalogueIO on ADC1_SE18
extern const AnalogueIO analogueIO_ADC1_SE23;               //!< AnalogueIO on ADC1_SE23
extern const AnalogueIO analogueIO_PTA17;                   //!< AnalogueIO on PTA17
extern const AnalogueIO analogueIO_PTB0;                    //!< AnalogueIO on PTB0
#define analogueIO_A0 analogueIO_PTB0
extern const AnalogueIO analogueIO_PTB0_1;                  //!< AnalogueIO on PTB0
#define analogueIO_A0 analogueIO_PTB0
extern const AnalogueIO analogueIO_PTB1;                    //!< AnalogueIO on PTB1
#define analogueIO_A1 analogueIO_PTB1
extern const AnalogueIO analogueIO_PTB1_1;                  //!< AnalogueIO on PTB1
#define analogueIO_A1 analogueIO_PTB1
extern const AnalogueIO analogueIO_PTB2;                    //!< AnalogueIO on PTB2
#define analogueIO_A5 analogueIO_PTB2
extern const AnalogueIO analogueIO_PTB3;                    //!< AnalogueIO on PTB3
#define analogueIO_A4 analogueIO_PTB3
extern const AnalogueIO analogueIO_PTB6;                    //!< AnalogueIO on PTB6
extern const AnalogueIO analogueIO_PTB7;                    //!< AnalogueIO on PTB7
extern const AnalogueIO analogueIO_PTB10;                   //!< AnalogueIO on PTB10
extern const AnalogueIO analogueIO_PTB11;                   //!< AnalogueIO on PTB11
extern const AnalogueIO analogueIO_PTC0;                    //!< AnalogueIO on PTC0
extern const AnalogueIO analogueIO_PTC1;                    //!< AnalogueIO on PTC1
#define analogueIO_A2 analogueIO_PTC1
extern const AnalogueIO analogueIO_PTC2;                    //!< AnalogueIO on PTC2
#define analogueIO_A3 analogueIO_PTC2
extern const AnalogueIO analogueIO_PTC8;                    //!< AnalogueIO on PTC8
extern const AnalogueIO analogueIO_PTC9;                    //!< AnalogueIO on PTC9
extern const AnalogueIO analogueIO_PTC10;                   //!< AnalogueIO on PTC10
extern const AnalogueIO analogueIO_PTC11;                   //!< AnalogueIO on PTC11
extern const AnalogueIO analogueIO_PTD1;                    //!< AnalogueIO on PTD1
extern const AnalogueIO analogueIO_PTD5;                    //!< AnalogueIO on PTD5
#define analogueIO_D13 analogueIO_PTD5
extern const AnalogueIO analogueIO_PTD6;                    //!< AnalogueIO on PTD6
#define analogueIO_D11 analogueIO_PTD6
extern const AnalogueIO analogueIO_PTE0;                    //!< AnalogueIO on PTE0
#define analogueIO_D14 analogueIO_PTE0
extern const AnalogueIO analogueIO_PTE1;                    //!< AnalogueIO on PTE1
#define analogueIO_D15 analogueIO_PTE1
extern const AnalogueIO analogueIO_PTE2;                    //!< AnalogueIO on PTE2
extern const AnalogueIO analogueIO_PTE3;                    //!< AnalogueIO on PTE3
extern const AnalogueIO analogueIO_PTE24;                   //!< AnalogueIO on PTE24
extern const AnalogueIO analogueIO_PTE25;                   //!< AnalogueIO on PTE25
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
#define pwmIO_D9 pwmIO_PTA1
extern const PwmIO  pwmIO_PTA2;                    //!< PwmIO on PTA2
#define pwmIO_D3 pwmIO_PTA2
extern const PwmIO  pwmIO_PTA3;                    //!< PwmIO on PTA3
extern const PwmIO  pwmIO_PTA4;                    //!< PwmIO on PTA4
#define pwmIO_D4 pwmIO_PTA4
extern const PwmIO  pwmIO_PTA5;                    //!< PwmIO on PTA5
extern const PwmIO  pwmIO_PTA12;                   //!< PwmIO on PTA12
extern const PwmIO  pwmIO_PTA13;                   //!< PwmIO on PTA13
extern const PwmIO  pwmIO_PTB0;                    //!< PwmIO on PTB0
#define pwmIO_A0 pwmIO_PTB0
extern const PwmIO  pwmIO_PTB1;                    //!< PwmIO on PTB1
#define pwmIO_A1 pwmIO_PTB1
extern const PwmIO  pwmIO_PTB18;                   //!< PwmIO on PTB18
#define pwmIO_D5 pwmIO_PTB18
extern const PwmIO  pwmIO_PTB19;                   //!< PwmIO on PTB19
#define pwmIO_D8 pwmIO_PTB19
extern const PwmIO  pwmIO_PTC1;                    //!< PwmIO on PTC1
#define pwmIO_A2 pwmIO_PTC1
extern const PwmIO  pwmIO_PTC2;                    //!< PwmIO on PTC2
#define pwmIO_A3 pwmIO_PTC2
extern const PwmIO  pwmIO_PTC3;                    //!< PwmIO on PTC3
#define pwmIO_D6 pwmIO_PTC3
extern const PwmIO  pwmIO_PTC4;                    //!< PwmIO on PTC4
extern const PwmIO  pwmIO_PTC5;                    //!< PwmIO on PTC5
extern const PwmIO  pwmIO_PTD4;                    //!< PwmIO on PTD4
#define pwmIO_D10 pwmIO_PTD4
extern const PwmIO  pwmIO_PTD5;                    //!< PwmIO on PTD5
#define pwmIO_D13 pwmIO_PTD5
extern const PwmIO  pwmIO_PTD6;                    //!< PwmIO on PTD6
#define pwmIO_D11 pwmIO_PTD6
extern const PwmIO  pwmIO_PTD7;                    //!< PwmIO on PTD7
#define pwmIO_D12 pwmIO_PTD7
/**
 * @}
 */
/*
Clock Information 
ADC0       SIM->SCGC6   SIM_SCGC6_ADC0_MASK
ADC1       SIM->SCGC6   SIM_SCGC6_ADC1_MASK
CMP        SIM->SCGC4   SIM_SCGC4_CMP_MASK
DAC0       SIM->SCGC6   SIM_SCGC6_DAC0_MASK
DMA        SIM->SCGC7   SIM_SCGC7_DMA_MASK
DMAMUX     SIM->SCGC6   SIM_SCGC6_DMAMUX_MASK
EWM        SIM->SCGC4   SIM_SCGC4_EWM_MASK
FTM0       SIM->SCGC6   SIM_SCGC6_FTM0_MASK
FTM1       SIM->SCGC6   SIM_SCGC6_FTM1_MASK
FTM2       SIM->SCGC6   SIM_SCGC6_FTM2_MASK
I2C0       SIM->SCGC4   SIM_SCGC4_I2C0_MASK
I2C1       SIM->SCGC4   SIM_SCGC4_I2C1_MASK
I2S0       SIM->SCGC6   SIM_SCGC6_I2S0_MASK
LPTMR0     SIM->SCGC5   SIM_SCGC5_LPTMR_MASK
LPUART0    SIM->SCGC6   SIM_SCGC6_LPUART0_MASK
PDB0       SIM->SCGC6   SIM_SCGC6_PDB0_MASK
PIT        SIM->SCGC6   SIM_SCGC6_PIT_MASK
PORTA      SIM->SCGC5   SIM_SCGC5_PORTA_MASK
PORTB      SIM->SCGC5   SIM_SCGC5_PORTB_MASK
PORTC      SIM->SCGC5   SIM_SCGC5_PORTC_MASK
PORTD      SIM->SCGC5   SIM_SCGC5_PORTD_MASK
PORTE      SIM->SCGC5   SIM_SCGC5_PORTE_MASK
RNGA       SIM->SCGC6   SIM_SCGC6_RNGA_MASK
RTC        SIM->SCGC6   SIM_SCGC6_RTC_MASK
SPI0       SIM->SCGC6   SIM_SCGC6_SPI0_MASK
SPI1       SIM->SCGC6   SIM_SCGC6_SPI1_MASK
UART0      SIM->SCGC4   SIM_SCGC4_UART0_MASK
UART1      SIM->SCGC4   SIM_SCGC4_UART1_MASK
UART2      SIM->SCGC4   SIM_SCGC4_UART2_MASK
USBOTG     SIM->SCGC4   SIM_SCGC4_USBOTG_MASK
VREF       SIM->SCGC4   SIM_SCGC4_VREF_MASK
*/


#endif /* GPIO_H_ */
