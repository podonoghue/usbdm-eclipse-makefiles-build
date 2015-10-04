/**
 * @file      gpio.h (derived from gpio-MK64F12.h)
 * @version   1.0.0
 * @brief     Pin declarations for MK64F12
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
#define digitalIO_D8 digitalIO_PTA0
extern const DigitalIO digitalIO_PTA1;                    //!< DigitalIO on PTA1
#define digitalIO_D3 digitalIO_PTA1
extern const DigitalIO digitalIO_PTA2;                    //!< DigitalIO on PTA2
#define digitalIO_D5 digitalIO_PTA2
extern const DigitalIO digitalIO_PTA3;                    //!< DigitalIO on PTA3
extern const DigitalIO digitalIO_PTA4;                    //!< DigitalIO on PTA4
extern const DigitalIO digitalIO_PTA5;                    //!< DigitalIO on PTA5
extern const DigitalIO digitalIO_PTA6;                    //!< DigitalIO on PTA6
extern const DigitalIO digitalIO_PTA7;                    //!< DigitalIO on PTA7
extern const DigitalIO digitalIO_PTA8;                    //!< DigitalIO on PTA8
extern const DigitalIO digitalIO_PTA9;                    //!< DigitalIO on PTA9
extern const DigitalIO digitalIO_PTA10;                   //!< DigitalIO on PTA10
extern const DigitalIO digitalIO_PTA11;                   //!< DigitalIO on PTA11
extern const DigitalIO digitalIO_PTA12;                   //!< DigitalIO on PTA12
extern const DigitalIO digitalIO_PTA13;                   //!< DigitalIO on PTA13
extern const DigitalIO digitalIO_PTA14;                   //!< DigitalIO on PTA14
extern const DigitalIO digitalIO_PTA15;                   //!< DigitalIO on PTA15
extern const DigitalIO digitalIO_PTA16;                   //!< DigitalIO on PTA16
extern const DigitalIO digitalIO_PTA17;                   //!< DigitalIO on PTA17
extern const DigitalIO digitalIO_PTA18;                   //!< DigitalIO on PTA18
extern const DigitalIO digitalIO_PTA19;                   //!< DigitalIO on PTA19
extern const DigitalIO digitalIO_PTA24;                   //!< DigitalIO on PTA24
extern const DigitalIO digitalIO_PTA25;                   //!< DigitalIO on PTA25
extern const DigitalIO digitalIO_PTA26;                   //!< DigitalIO on PTA26
extern const DigitalIO digitalIO_PTA27;                   //!< DigitalIO on PTA27
extern const DigitalIO digitalIO_PTA28;                   //!< DigitalIO on PTA28
extern const DigitalIO digitalIO_PTA29;                   //!< DigitalIO on PTA29
extern const DigitalIO digitalIO_PTB0;                    //!< DigitalIO on PTB0
extern const DigitalIO digitalIO_PTB1;                    //!< DigitalIO on PTB1
extern const DigitalIO digitalIO_PTB2;                    //!< DigitalIO on PTB2
#define digitalIO_A0 digitalIO_PTB2
extern const DigitalIO digitalIO_PTB3;                    //!< DigitalIO on PTB3
#define digitalIO_A1 digitalIO_PTB3
extern const DigitalIO digitalIO_PTB4;                    //!< DigitalIO on PTB4
extern const DigitalIO digitalIO_PTB5;                    //!< DigitalIO on PTB5
extern const DigitalIO digitalIO_PTB6;                    //!< DigitalIO on PTB6
extern const DigitalIO digitalIO_PTB7;                    //!< DigitalIO on PTB7
extern const DigitalIO digitalIO_PTB8;                    //!< DigitalIO on PTB8
extern const DigitalIO digitalIO_PTB9;                    //!< DigitalIO on PTB9
#define digitalIO_D2 digitalIO_PTB9
extern const DigitalIO digitalIO_PTB10;                   //!< DigitalIO on PTB10
#define digitalIO_A2 digitalIO_PTB10
extern const DigitalIO digitalIO_PTB11;                   //!< DigitalIO on PTB11
#define digitalIO_A3 digitalIO_PTB11
extern const DigitalIO digitalIO_PTB12;                   //!< DigitalIO on PTB12
extern const DigitalIO digitalIO_PTB13;                   //!< DigitalIO on PTB13
extern const DigitalIO digitalIO_PTB16;                   //!< DigitalIO on PTB16
extern const DigitalIO digitalIO_PTB17;                   //!< DigitalIO on PTB17
extern const DigitalIO digitalIO_PTB18;                   //!< DigitalIO on PTB18
extern const DigitalIO digitalIO_PTB19;                   //!< DigitalIO on PTB19
extern const DigitalIO digitalIO_PTB20;                   //!< DigitalIO on PTB20
extern const DigitalIO digitalIO_PTB21;                   //!< DigitalIO on PTB21
extern const DigitalIO digitalIO_PTB22;                   //!< DigitalIO on PTB22
extern const DigitalIO digitalIO_PTB23;                   //!< DigitalIO on PTB23
#define digitalIO_D4 digitalIO_PTB23
extern const DigitalIO digitalIO_PTC0;                    //!< DigitalIO on PTC0
extern const DigitalIO digitalIO_PTC1;                    //!< DigitalIO on PTC1
extern const DigitalIO digitalIO_PTC2;                    //!< DigitalIO on PTC2
#define digitalIO_D6 digitalIO_PTC2
extern const DigitalIO digitalIO_PTC3;                    //!< DigitalIO on PTC3
#define digitalIO_D7 digitalIO_PTC3
extern const DigitalIO digitalIO_PTC4;                    //!< DigitalIO on PTC4
#define digitalIO_D9 digitalIO_PTC4
extern const DigitalIO digitalIO_PTC5;                    //!< DigitalIO on PTC5
extern const DigitalIO digitalIO_PTC6;                    //!< DigitalIO on PTC6
extern const DigitalIO digitalIO_PTC7;                    //!< DigitalIO on PTC7
extern const DigitalIO digitalIO_PTC8;                    //!< DigitalIO on PTC8
extern const DigitalIO digitalIO_PTC9;                    //!< DigitalIO on PTC9
extern const DigitalIO digitalIO_PTC10;                   //!< DigitalIO on PTC10
#define digitalIO_A5 digitalIO_PTC10
extern const DigitalIO digitalIO_PTC11;                   //!< DigitalIO on PTC11
#define digitalIO_A4 digitalIO_PTC11
extern const DigitalIO digitalIO_PTC12;                   //!< DigitalIO on PTC12
extern const DigitalIO digitalIO_PTC13;                   //!< DigitalIO on PTC13
extern const DigitalIO digitalIO_PTC14;                   //!< DigitalIO on PTC14
extern const DigitalIO digitalIO_PTC15;                   //!< DigitalIO on PTC15
extern const DigitalIO digitalIO_PTC16;                   //!< DigitalIO on PTC16
#define digitalIO_D0 digitalIO_PTC16
extern const DigitalIO digitalIO_PTC17;                   //!< DigitalIO on PTC17
#define digitalIO_D1 digitalIO_PTC17
extern const DigitalIO digitalIO_PTC18;                   //!< DigitalIO on PTC18
extern const DigitalIO digitalIO_PTC19;                   //!< DigitalIO on PTC19
extern const DigitalIO digitalIO_PTD0;                    //!< DigitalIO on PTD0
#define digitalIO_D10 digitalIO_PTD0
extern const DigitalIO digitalIO_PTD1;                    //!< DigitalIO on PTD1
#define digitalIO_D13 digitalIO_PTD1
extern const DigitalIO digitalIO_PTD2;                    //!< DigitalIO on PTD2
#define digitalIO_D11 digitalIO_PTD2
extern const DigitalIO digitalIO_PTD3;                    //!< DigitalIO on PTD3
#define digitalIO_D12 digitalIO_PTD3
extern const DigitalIO digitalIO_PTD4;                    //!< DigitalIO on PTD4
#define digitalIO_nRF24L01_cs digitalIO_PTD4
extern const DigitalIO digitalIO_PTD5;                    //!< DigitalIO on PTD5
#define digitalIO_nRF24L01_sck digitalIO_PTD5
extern const DigitalIO digitalIO_PTD6;                    //!< DigitalIO on PTD6
#define digitalIO_nRF24L01_mosi digitalIO_PTD6
extern const DigitalIO digitalIO_PTD7;                    //!< DigitalIO on PTD7
#define digitalIO_nRF24L01_miso digitalIO_PTD7
extern const DigitalIO digitalIO_PTD8;                    //!< DigitalIO on PTD8
extern const DigitalIO digitalIO_PTD9;                    //!< DigitalIO on PTD9
extern const DigitalIO digitalIO_PTD10;                   //!< DigitalIO on PTD10
extern const DigitalIO digitalIO_PTD11;                   //!< DigitalIO on PTD11
extern const DigitalIO digitalIO_PTD12;                   //!< DigitalIO on PTD12
extern const DigitalIO digitalIO_PTD13;                   //!< DigitalIO on PTD13
extern const DigitalIO digitalIO_PTD14;                   //!< DigitalIO on PTD14
extern const DigitalIO digitalIO_PTD15;                   //!< DigitalIO on PTD15
extern const DigitalIO digitalIO_PTE0;                    //!< DigitalIO on PTE0
extern const DigitalIO digitalIO_PTE1;                    //!< DigitalIO on PTE1
extern const DigitalIO digitalIO_PTE2;                    //!< DigitalIO on PTE2
extern const DigitalIO digitalIO_PTE3;                    //!< DigitalIO on PTE3
extern const DigitalIO digitalIO_PTE4;                    //!< DigitalIO on PTE4
extern const DigitalIO digitalIO_PTE5;                    //!< DigitalIO on PTE5
extern const DigitalIO digitalIO_PTE6;                    //!< DigitalIO on PTE6
extern const DigitalIO digitalIO_PTE7;                    //!< DigitalIO on PTE7
extern const DigitalIO digitalIO_PTE8;                    //!< DigitalIO on PTE8
extern const DigitalIO digitalIO_PTE9;                    //!< DigitalIO on PTE9
extern const DigitalIO digitalIO_PTE10;                   //!< DigitalIO on PTE10
extern const DigitalIO digitalIO_PTE11;                   //!< DigitalIO on PTE11
extern const DigitalIO digitalIO_PTE12;                   //!< DigitalIO on PTE12
extern const DigitalIO digitalIO_PTE24;                   //!< DigitalIO on PTE24
#define digitalIO_D15 digitalIO_PTE24
extern const DigitalIO digitalIO_PTE25;                   //!< DigitalIO on PTE25
#define digitalIO_D14 digitalIO_PTE25
extern const DigitalIO digitalIO_PTE26;                   //!< DigitalIO on PTE26
extern const DigitalIO digitalIO_PTE27;                   //!< DigitalIO on PTE27
extern const DigitalIO digitalIO_PTE28;                   //!< DigitalIO on PTE28
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
extern const AnalogueIO analogueIO_ADC0_SE16;               //!< AnalogueIO on ADC0_SE16
extern const AnalogueIO analogueIO_ADC0_SE16_1;             //!< AnalogueIO on ADC0_SE16
extern const AnalogueIO analogueIO_ADC0_SE23;               //!< AnalogueIO on ADC0_SE23
extern const AnalogueIO analogueIO_ADC1_DM0;                //!< AnalogueIO on ADC1_DM0
extern const AnalogueIO analogueIO_ADC1_DM0_1;              //!< AnalogueIO on ADC1_DM0
extern const AnalogueIO analogueIO_ADC1_DM1;                //!< AnalogueIO on ADC1_DM1
extern const AnalogueIO analogueIO_ADC1_DP0;                //!< AnalogueIO on ADC1_DP0
extern const AnalogueIO analogueIO_ADC1_DP0_1;              //!< AnalogueIO on ADC1_DP0
extern const AnalogueIO analogueIO_ADC1_DP1;                //!< AnalogueIO on ADC1_DP1
extern const AnalogueIO analogueIO_ADC1_SE16;               //!< AnalogueIO on ADC1_SE16
extern const AnalogueIO analogueIO_ADC1_SE16_1;             //!< AnalogueIO on ADC1_SE16
extern const AnalogueIO analogueIO_ADC1_SE18;               //!< AnalogueIO on ADC1_SE18
extern const AnalogueIO analogueIO_ADC1_SE23;               //!< AnalogueIO on ADC1_SE23
extern const AnalogueIO analogueIO_PTA7;                    //!< AnalogueIO on PTA7
extern const AnalogueIO analogueIO_PTA8;                    //!< AnalogueIO on PTA8
extern const AnalogueIO analogueIO_PTA17;                   //!< AnalogueIO on PTA17
extern const AnalogueIO analogueIO_PTB0;                    //!< AnalogueIO on PTB0
extern const AnalogueIO analogueIO_PTB0_1;                  //!< AnalogueIO on PTB0
extern const AnalogueIO analogueIO_PTB1;                    //!< AnalogueIO on PTB1
extern const AnalogueIO analogueIO_PTB1_1;                  //!< AnalogueIO on PTB1
extern const AnalogueIO analogueIO_PTB2;                    //!< AnalogueIO on PTB2
#define analogueIO_A0 analogueIO_PTB2
extern const AnalogueIO analogueIO_PTB3;                    //!< AnalogueIO on PTB3
#define analogueIO_A1 analogueIO_PTB3
extern const AnalogueIO analogueIO_PTB4;                    //!< AnalogueIO on PTB4
extern const AnalogueIO analogueIO_PTB5;                    //!< AnalogueIO on PTB5
extern const AnalogueIO analogueIO_PTB6;                    //!< AnalogueIO on PTB6
extern const AnalogueIO analogueIO_PTB7;                    //!< AnalogueIO on PTB7
extern const AnalogueIO analogueIO_PTB10;                   //!< AnalogueIO on PTB10
#define analogueIO_A2 analogueIO_PTB10
extern const AnalogueIO analogueIO_PTB11;                   //!< AnalogueIO on PTB11
#define analogueIO_A3 analogueIO_PTB11
extern const AnalogueIO analogueIO_PTC0;                    //!< AnalogueIO on PTC0
extern const AnalogueIO analogueIO_PTC1;                    //!< AnalogueIO on PTC1
extern const AnalogueIO analogueIO_PTC2;                    //!< AnalogueIO on PTC2
#define analogueIO_D6 analogueIO_PTC2
extern const AnalogueIO analogueIO_PTC8;                    //!< AnalogueIO on PTC8
extern const AnalogueIO analogueIO_PTC9;                    //!< AnalogueIO on PTC9
extern const AnalogueIO analogueIO_PTC10;                   //!< AnalogueIO on PTC10
#define analogueIO_A5 analogueIO_PTC10
extern const AnalogueIO analogueIO_PTC11;                   //!< AnalogueIO on PTC11
#define analogueIO_A4 analogueIO_PTC11
extern const AnalogueIO analogueIO_PTD1;                    //!< AnalogueIO on PTD1
#define analogueIO_D13 analogueIO_PTD1
extern const AnalogueIO analogueIO_PTD5;                    //!< AnalogueIO on PTD5
#define analogueIO_nRF24L01_sck analogueIO_PTD5
extern const AnalogueIO analogueIO_PTD6;                    //!< AnalogueIO on PTD6
#define analogueIO_nRF24L01_mosi analogueIO_PTD6
extern const AnalogueIO analogueIO_PTE0;                    //!< AnalogueIO on PTE0
extern const AnalogueIO analogueIO_PTE1;                    //!< AnalogueIO on PTE1
extern const AnalogueIO analogueIO_PTE2;                    //!< AnalogueIO on PTE2
extern const AnalogueIO analogueIO_PTE2_1;                  //!< AnalogueIO on PTE2
extern const AnalogueIO analogueIO_PTE3;                    //!< AnalogueIO on PTE3
extern const AnalogueIO analogueIO_PTE3_1;                  //!< AnalogueIO on PTE3
extern const AnalogueIO analogueIO_PTE24;                   //!< AnalogueIO on PTE24
#define analogueIO_D15 analogueIO_PTE24
extern const AnalogueIO analogueIO_PTE25;                   //!< AnalogueIO on PTE25
#define analogueIO_D14 analogueIO_PTE25
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
extern const PwmIO  pwmIO_PTA0;                    //!< PwmIO on PTA0
#define pwmIO_D8 pwmIO_PTA0
extern const PwmIO  pwmIO_PTA1;                    //!< PwmIO on PTA1
#define pwmIO_D3 pwmIO_PTA1
extern const PwmIO  pwmIO_PTA2;                    //!< PwmIO on PTA2
#define pwmIO_D5 pwmIO_PTA2
extern const PwmIO  pwmIO_PTA3;                    //!< PwmIO on PTA3
extern const PwmIO  pwmIO_PTA4;                    //!< PwmIO on PTA4
extern const PwmIO  pwmIO_PTA5;                    //!< PwmIO on PTA5
extern const PwmIO  pwmIO_PTA6;                    //!< PwmIO on PTA6
extern const PwmIO  pwmIO_PTA7;                    //!< PwmIO on PTA7
extern const PwmIO  pwmIO_PTA8;                    //!< PwmIO on PTA8
extern const PwmIO  pwmIO_PTA9;                    //!< PwmIO on PTA9
extern const PwmIO  pwmIO_PTA10;                   //!< PwmIO on PTA10
extern const PwmIO  pwmIO_PTA11;                   //!< PwmIO on PTA11
extern const PwmIO  pwmIO_PTA12;                   //!< PwmIO on PTA12
extern const PwmIO  pwmIO_PTA13;                   //!< PwmIO on PTA13
extern const PwmIO  pwmIO_PTB0;                    //!< PwmIO on PTB0
extern const PwmIO  pwmIO_PTB1;                    //!< PwmIO on PTB1
extern const PwmIO  pwmIO_PTB12;                   //!< PwmIO on PTB12
extern const PwmIO  pwmIO_PTB12_1;                 //!< PwmIO on PTB12
extern const PwmIO  pwmIO_PTB13;                   //!< PwmIO on PTB13
extern const PwmIO  pwmIO_PTB13_1;                 //!< PwmIO on PTB13
extern const PwmIO  pwmIO_PTB18;                   //!< PwmIO on PTB18
extern const PwmIO  pwmIO_PTB19;                   //!< PwmIO on PTB19
extern const PwmIO  pwmIO_PTC1;                    //!< PwmIO on PTC1
extern const PwmIO  pwmIO_PTC2;                    //!< PwmIO on PTC2
#define pwmIO_D6 pwmIO_PTC2
extern const PwmIO  pwmIO_PTC3;                    //!< PwmIO on PTC3
#define pwmIO_D7 pwmIO_PTC3
extern const PwmIO  pwmIO_PTC4;                    //!< PwmIO on PTC4
#define pwmIO_D9 pwmIO_PTC4
extern const PwmIO  pwmIO_PTC5;                    //!< PwmIO on PTC5
extern const PwmIO  pwmIO_PTC8;                    //!< PwmIO on PTC8
extern const PwmIO  pwmIO_PTC9;                    //!< PwmIO on PTC9
extern const PwmIO  pwmIO_PTC10;                   //!< PwmIO on PTC10
#define pwmIO_A5 pwmIO_PTC10
extern const PwmIO  pwmIO_PTC11;                   //!< PwmIO on PTC11
#define pwmIO_A4 pwmIO_PTC11
extern const PwmIO  pwmIO_PTD0;                    //!< PwmIO on PTD0
#define pwmIO_D10 pwmIO_PTD0
extern const PwmIO  pwmIO_PTD1;                    //!< PwmIO on PTD1
#define pwmIO_D13 pwmIO_PTD1
extern const PwmIO  pwmIO_PTD2;                    //!< PwmIO on PTD2
#define pwmIO_D11 pwmIO_PTD2
extern const PwmIO  pwmIO_PTD3;                    //!< PwmIO on PTD3
#define pwmIO_D12 pwmIO_PTD3
extern const PwmIO  pwmIO_PTD4;                    //!< PwmIO on PTD4
#define pwmIO_nRF24L01_cs pwmIO_PTD4
extern const PwmIO  pwmIO_PTD5;                    //!< PwmIO on PTD5
#define pwmIO_nRF24L01_sck pwmIO_PTD5
extern const PwmIO  pwmIO_PTD6;                    //!< PwmIO on PTD6
#define pwmIO_nRF24L01_mosi pwmIO_PTD6
extern const PwmIO  pwmIO_PTD7;                    //!< PwmIO on PTD7
#define pwmIO_nRF24L01_miso pwmIO_PTD7
extern const PwmIO  pwmIO_PTE5;                    //!< PwmIO on PTE5
extern const PwmIO  pwmIO_PTE6;                    //!< PwmIO on PTE6
extern const PwmIO  pwmIO_PTE7;                    //!< PwmIO on PTE7
extern const PwmIO  pwmIO_PTE8;                    //!< PwmIO on PTE8
extern const PwmIO  pwmIO_PTE9;                    //!< PwmIO on PTE9
extern const PwmIO  pwmIO_PTE10;                   //!< PwmIO on PTE10
extern const PwmIO  pwmIO_PTE11;                   //!< PwmIO on PTE11
extern const PwmIO  pwmIO_PTE12;                   //!< PwmIO on PTE12
/**
 * @}
 */
/*
Clock Information 
ADC0       SIM->SCGC6   SIM_SCGC6_ADC0_MASK
ADC1       SIM->SCGC3   SIM_SCGC3_ADC1_MASK
CMP        SIM->SCGC4   SIM_SCGC4_CMP_MASK
CMT        SIM->SCGC4   SIM_SCGC4_CMT_MASK
DAC0       SIM->SCGC6   SIM_SCGC6_DAC0_MASK
DAC1       SIM->SCGC2   SIM_SCGC2_DAC1_MASK
DMA        SIM->SCGC7   SIM_SCGC7_DMA_MASK
DMAMUX     SIM->SCGC6   SIM_SCGC6_DMAMUX_MASK
ENET       SIM->SCGC2   SIM_SCGC2_ENET_MASK
EWM        SIM->SCGC4   SIM_SCGC4_EWM_MASK
FLEXBUS    SIM->SCGC7   SIM_SCGC7_FLEXBUS_MASK
FLEXCAN    SIM->SCGC6   SIM_SCGC6_FLEXCAN_MASK
FTM0       SIM->SCGC6   SIM_SCGC6_FTM0_MASK
FTM1       SIM->SCGC6   SIM_SCGC6_FTM1_MASK
FTM2       SIM->SCGC6   SIM_SCGC6_FTM2_MASK
FTM3       SIM->SCGC3   SIM_SCGC3_FTM3_MASK
I2C0       SIM->SCGC4   SIM_SCGC4_I2C0_MASK
I2C1       SIM->SCGC4   SIM_SCGC4_I2C1_MASK
I2C2       SIM->SCGC1   SIM_SCGC1_I2C2_MASK
I2S0       SIM->SCGC6   SIM_SCGC6_I2S0_MASK
LPTMR0     SIM->SCGC5   SIM_SCGC5_LPTMR_MASK
MPU        SIM->SCGC7   SIM_SCGC7_MPU_MASK
PDB0       SIM->SCGC6   SIM_SCGC6_PDB0_MASK
PIT        SIM->SCGC6   SIM_SCGC6_PIT_MASK
PORTA      SIM->SCGC5   SIM_SCGC5_PORTA_MASK
PORTB      SIM->SCGC5   SIM_SCGC5_PORTB_MASK
PORTC      SIM->SCGC5   SIM_SCGC5_PORTC_MASK
PORTD      SIM->SCGC5   SIM_SCGC5_PORTD_MASK
PORTE      SIM->SCGC5   SIM_SCGC5_PORTE_MASK
RNGA       SIM->SCGC6   SIM_SCGC6_RNGA_MASK
RTC        SIM->SCGC6   SIM_SCGC6_RTC_MASK
SDHC0      SIM->SCGC3   SIM_SCGC3_SDHC0_MASK
SPI0       SIM->SCGC6   SIM_SCGC6_SPI0_MASK
SPI1       SIM->SCGC6   SIM_SCGC6_SPI1_MASK
SPI2       SIM->SCGC3   SIM_SCGC3_SPI2_MASK
UART0      SIM->SCGC4   SIM_SCGC4_UART0_MASK
UART1      SIM->SCGC4   SIM_SCGC4_UART1_MASK
UART2      SIM->SCGC4   SIM_SCGC4_UART2_MASK
UART3      SIM->SCGC4   SIM_SCGC4_UART3_MASK
UART4      SIM->SCGC1   SIM_SCGC1_UART4_MASK
UART5      SIM->SCGC1   SIM_SCGC1_UART5_MASK
USBDCD     SIM->SCGC6   SIM_SCGC6_USBDCD_MASK
USBOTG     SIM->SCGC4   SIM_SCGC4_USBOTG_MASK
VREF       SIM->SCGC4   SIM_SCGC4_VREF_MASK
*/


#endif /* GPIO_H_ */
