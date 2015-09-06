/**
 * @file      gpio.h (derived from gpio-MKL46Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKL46Z4
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
extern const DigitalIO digitalIO_PTA12;         //!< DigitalIO on PTA12
extern const DigitalIO digitalIO_PTA13;         //!< DigitalIO on PTA13
extern const DigitalIO digitalIO_PTA14;         //!< DigitalIO on PTA14
extern const DigitalIO digitalIO_PTA15;         //!< DigitalIO on PTA15
extern const DigitalIO digitalIO_PTA16;         //!< DigitalIO on PTA16
extern const DigitalIO digitalIO_PTA17;         //!< DigitalIO on PTA17
extern const DigitalIO digitalIO_PTA18;         //!< DigitalIO on PTA18
extern const DigitalIO digitalIO_PTA19;         //!< DigitalIO on PTA19
extern const DigitalIO digitalIO_PTA20;         //!< DigitalIO on PTA20
extern const DigitalIO digitalIO_PTB0;          //!< DigitalIO on PTB0
extern const DigitalIO digitalIO_PTB1;          //!< DigitalIO on PTB1
extern const DigitalIO digitalIO_PTB2;          //!< DigitalIO on PTB2
extern const DigitalIO digitalIO_PTB3;          //!< DigitalIO on PTB3
extern const DigitalIO digitalIO_PTB7;          //!< DigitalIO on PTB7
extern const DigitalIO digitalIO_PTB8;          //!< DigitalIO on PTB8
extern const DigitalIO digitalIO_PTB9;          //!< DigitalIO on PTB9
extern const DigitalIO digitalIO_PTB10;         //!< DigitalIO on PTB10
extern const DigitalIO digitalIO_PTB11;         //!< DigitalIO on PTB11
extern const DigitalIO digitalIO_PTB16;         //!< DigitalIO on PTB16
extern const DigitalIO digitalIO_PTB17;         //!< DigitalIO on PTB17
extern const DigitalIO digitalIO_PTB18;         //!< DigitalIO on PTB18
extern const DigitalIO digitalIO_PTB19;         //!< DigitalIO on PTB19
extern const DigitalIO digitalIO_PTB20;         //!< DigitalIO on PTB20
extern const DigitalIO digitalIO_PTB21;         //!< DigitalIO on PTB21
extern const DigitalIO digitalIO_PTB22;         //!< DigitalIO on PTB22
extern const DigitalIO digitalIO_PTB23;         //!< DigitalIO on PTB23
extern const DigitalIO digitalIO_PTC0;          //!< DigitalIO on PTC0
extern const DigitalIO digitalIO_PTC1;          //!< DigitalIO on PTC1
extern const DigitalIO digitalIO_PTC2;          //!< DigitalIO on PTC2
extern const DigitalIO digitalIO_PTC3;          //!< DigitalIO on PTC3
extern const DigitalIO digitalIO_PTC4;          //!< DigitalIO on PTC4
extern const DigitalIO digitalIO_PTC5;          //!< DigitalIO on PTC5
extern const DigitalIO digitalIO_PTC6;          //!< DigitalIO on PTC6
extern const DigitalIO digitalIO_PTC7;          //!< DigitalIO on PTC7
extern const DigitalIO digitalIO_PTC8;          //!< DigitalIO on PTC8
extern const DigitalIO digitalIO_PTC9;          //!< DigitalIO on PTC9
extern const DigitalIO digitalIO_PTC10;         //!< DigitalIO on PTC10
extern const DigitalIO digitalIO_PTC11;         //!< DigitalIO on PTC11
extern const DigitalIO digitalIO_PTC12;         //!< DigitalIO on PTC12
extern const DigitalIO digitalIO_PTC13;         //!< DigitalIO on PTC13
extern const DigitalIO digitalIO_PTC16;         //!< DigitalIO on PTC16
extern const DigitalIO digitalIO_PTC17;         //!< DigitalIO on PTC17
extern const DigitalIO digitalIO_PTC18;         //!< DigitalIO on PTC18
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
extern const DigitalIO digitalIO_PTE16;         //!< DigitalIO on PTE16
extern const DigitalIO digitalIO_PTE17;         //!< DigitalIO on PTE17
extern const DigitalIO digitalIO_PTE18;         //!< DigitalIO on PTE18
extern const DigitalIO digitalIO_PTE19;         //!< DigitalIO on PTE19
extern const DigitalIO digitalIO_PTE20;         //!< DigitalIO on PTE20
extern const DigitalIO digitalIO_PTE21;         //!< DigitalIO on PTE21
extern const DigitalIO digitalIO_PTE22;         //!< DigitalIO on PTE22
extern const DigitalIO digitalIO_PTE23;         //!< DigitalIO on PTE23
extern const DigitalIO digitalIO_PTE24;         //!< DigitalIO on PTE24
extern const DigitalIO digitalIO_PTE25;         //!< DigitalIO on PTE25
extern const DigitalIO digitalIO_PTE26;         //!< DigitalIO on PTE26
extern const DigitalIO digitalIO_PTE29;         //!< DigitalIO on PTE29
extern const DigitalIO digitalIO_PTE30;         //!< DigitalIO on PTE30
extern const DigitalIO digitalIO_PTE31;         //!< DigitalIO on PTE31
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if ADC0_8_SEL == 1
extern const AnalogueIO analogueIO_PTB0;         //!< AnalogueIO on PTB0
#endif
#if ADC0_9_SEL == 1
extern const AnalogueIO analogueIO_PTB1;         //!< AnalogueIO on PTB1
#endif
#if ADC0_12_SEL == 1
extern const AnalogueIO analogueIO_PTB2;         //!< AnalogueIO on PTB2
#endif
#if ADC0_13_SEL == 1
extern const AnalogueIO analogueIO_PTB3;         //!< AnalogueIO on PTB3
#endif
#if ADC0_14_SEL == 1
extern const AnalogueIO analogueIO_PTC0;         //!< AnalogueIO on PTC0
#endif
#if ADC0_15_SEL == 1
extern const AnalogueIO analogueIO_PTC1;         //!< AnalogueIO on PTC1
#endif
#if ADC0_11_SEL == 1
extern const AnalogueIO analogueIO_PTC2;         //!< AnalogueIO on PTC2
#endif
#if ADC0_5_SEL == 1
extern const AnalogueIO analogueIO_PTD1;         //!< AnalogueIO on PTD1
#endif
#if ADC0_6_SEL == 1
extern const AnalogueIO analogueIO_PTD5;         //!< AnalogueIO on PTD5
#endif
#if ADC0_7_SEL == 1
extern const AnalogueIO analogueIO_PTD6;         //!< AnalogueIO on PTD6
#endif
#if ADC0_1_SEL == 1
extern const AnalogueIO analogueIO_PTE16;        //!< AnalogueIO on PTE16
#endif
#if ADC0_2_SEL == 1
extern const AnalogueIO analogueIO_PTE18;        //!< AnalogueIO on PTE18
#endif
#if ADC0_0_SEL == 1
extern const AnalogueIO analogueIO_PTE20;        //!< AnalogueIO on PTE20
#endif
#if ADC0_3_SEL == 1
extern const AnalogueIO analogueIO_PTE22;        //!< AnalogueIO on PTE22
#endif
#if ADC0_4_SEL == 1
extern const AnalogueIO analogueIO_PTE29;        //!< AnalogueIO on PTE29
#endif
#if ADC0_23_SEL == 1
extern const AnalogueIO analogueIO_PTE30;        //!< AnalogueIO on PTE30
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if TPM0_5_SEL == 1
extern const PwmIO  pwmIO_PTA0;              //!< PwmIO on PTA0
#endif
#if TPM2_0_SEL == 1
extern const PwmIO  pwmIO_PTA1;              //!< PwmIO on PTA1
#endif
#if TPM2_1_SEL == 1
extern const PwmIO  pwmIO_PTA2;              //!< PwmIO on PTA2
#endif
#if TPM0_0_SEL == 1
extern const PwmIO  pwmIO_PTA3;              //!< PwmIO on PTA3
#endif
#if TPM0_1_SEL == 1
extern const PwmIO  pwmIO_PTA4;              //!< PwmIO on PTA4
#endif
#if TPM0_2_SEL == 1
extern const PwmIO  pwmIO_PTA5;              //!< PwmIO on PTA5
#endif
#if TPM0_3_SEL == 1
extern const PwmIO  pwmIO_PTA6;              //!< PwmIO on PTA6
#endif
#if TPM0_4_SEL == 1
extern const PwmIO  pwmIO_PTA7;              //!< PwmIO on PTA7
#endif
#if TPM1_0_SEL == 1
extern const PwmIO  pwmIO_PTA12;             //!< PwmIO on PTA12
#endif
#if TPM1_1_SEL == 1
extern const PwmIO  pwmIO_PTA13;             //!< PwmIO on PTA13
#endif
#if TPM1_0_SEL == 2
extern const PwmIO  pwmIO_PTB0;              //!< PwmIO on PTB0
#endif
#if TPM1_1_SEL == 2
extern const PwmIO  pwmIO_PTB1;              //!< PwmIO on PTB1
#endif
#if TPM2_0_SEL == 2
extern const PwmIO  pwmIO_PTB2;              //!< PwmIO on PTB2
#endif
#if TPM2_1_SEL == 2
extern const PwmIO  pwmIO_PTB3;              //!< PwmIO on PTB3
#endif
#if TPM2_0_SEL == 3
extern const PwmIO  pwmIO_PTB18;             //!< PwmIO on PTB18
#endif
#if TPM2_1_SEL == 3
extern const PwmIO  pwmIO_PTB19;             //!< PwmIO on PTB19
#endif
#if TPM0_0_SEL == 2
extern const PwmIO  pwmIO_PTC1;              //!< PwmIO on PTC1
#endif
#if TPM0_1_SEL == 2
extern const PwmIO  pwmIO_PTC2;              //!< PwmIO on PTC2
#endif
#if TPM0_2_SEL == 2
extern const PwmIO  pwmIO_PTC3;              //!< PwmIO on PTC3
#endif
#if TPM0_3_SEL == 2
extern const PwmIO  pwmIO_PTC4;              //!< PwmIO on PTC4
#endif
#if TPM0_4_SEL == 2
extern const PwmIO  pwmIO_PTC8;              //!< PwmIO on PTC8
#endif
#if TPM0_5_SEL == 2
extern const PwmIO  pwmIO_PTC9;              //!< PwmIO on PTC9
#endif
#if TPM0_0_SEL == 3
extern const PwmIO  pwmIO_PTD0;              //!< PwmIO on PTD0
#endif
#if TPM0_1_SEL == 3
extern const PwmIO  pwmIO_PTD1;              //!< PwmIO on PTD1
#endif
#if TPM0_2_SEL == 3
extern const PwmIO  pwmIO_PTD2;              //!< PwmIO on PTD2
#endif
#if TPM0_3_SEL == 3
extern const PwmIO  pwmIO_PTD3;              //!< PwmIO on PTD3
#endif
#if TPM0_4_SEL == 3
extern const PwmIO  pwmIO_PTD4;              //!< PwmIO on PTD4
#endif
#if TPM0_5_SEL == 3
extern const PwmIO  pwmIO_PTD5;              //!< PwmIO on PTD5
#endif
#if TPM1_0_SEL == 3
extern const PwmIO  pwmIO_PTE20;             //!< PwmIO on PTE20
#endif
#if TPM1_1_SEL == 3
extern const PwmIO  pwmIO_PTE21;             //!< PwmIO on PTE21
#endif
#if TPM2_0_SEL == 4
extern const PwmIO  pwmIO_PTE22;             //!< PwmIO on PTE22
#endif
#if TPM2_1_SEL == 4
extern const PwmIO  pwmIO_PTE23;             //!< PwmIO on PTE23
#endif
#if TPM0_0_SEL == 4
extern const PwmIO  pwmIO_PTE24;             //!< PwmIO on PTE24
#endif
#if TPM0_1_SEL == 4
extern const PwmIO  pwmIO_PTE25;             //!< PwmIO on PTE25
#endif
#if TPM0_5_SEL == 4
extern const PwmIO  pwmIO_PTE26;             //!< PwmIO on PTE26
#endif
#if TPM0_2_SEL == 4
extern const PwmIO  pwmIO_PTE29;             //!< PwmIO on PTE29
#endif
#if TPM0_3_SEL == 4
extern const PwmIO  pwmIO_PTE30;             //!< PwmIO on PTE30
#endif
#if TPM0_4_SEL == 4
extern const PwmIO  pwmIO_PTE31;             //!< PwmIO on PTE31
#endif
/**
 * @}
 */
/**
* @addtogroup alias_pin_mappings_GROUP Aliases for pins
* @brief Aliases for port pins for example Arduino based names
* @{
*/
#define digitalIO_A0              digitalIO_PTB0       //!< alias A0=>PTB0
#define digitalIO_A1              digitalIO_PTB1       //!< alias A1=>PTB1
#define digitalIO_A2              digitalIO_PTB2       //!< alias A2=>PTB2
#define digitalIO_A3              digitalIO_PTB3       //!< alias A3=>PTB3
#define digitalIO_A4              digitalIO_PTC2       //!< alias A4=>PTC2
#define digitalIO_A5              digitalIO_PTC1       //!< alias A5=>PTC1
#define digitalIO_ACC_INT1        digitalIO_PTC5       //!< alias ACC_INT1=>PTC5
#define digitalIO_ACC_INT2        digitalIO_PTD1       //!< alias ACC_INT2=>PTD1
#define digitalIO_ACC_SCL         digitalIO_PTE24      //!< alias ACC_SCL=>PTE24
#define digitalIO_ACC_SDA         digitalIO_PTE25      //!< alias ACC_SDA=>PTE25
#define digitalIO_D0              digitalIO_PTA1       //!< alias D0=>PTA1
#define digitalIO_D1              digitalIO_PTA2       //!< alias D1=>PTA2
#define digitalIO_D2              digitalIO_PTD3       //!< alias D2=>PTD3
#define digitalIO_D3              digitalIO_PTA12      //!< alias D3=>PTA12
#define digitalIO_D4              digitalIO_PTA4       //!< alias D4=>PTA4
#define digitalIO_D5              digitalIO_PTA5       //!< alias D5=>PTA5
#define digitalIO_D6              digitalIO_PTC8       //!< alias D6=>PTC8
#define digitalIO_D7              digitalIO_PTC9       //!< alias D7=>PTC9
#define digitalIO_D8              digitalIO_PTA13      //!< alias D8=>PTA13
#define digitalIO_D9              digitalIO_PTD2       //!< alias D9=>PTD2
#define digitalIO_D10             digitalIO_PTD4       //!< alias D10=>PTD4
#define digitalIO_D11             digitalIO_PTD6       //!< alias D11=>PTD6
#define digitalIO_D12             digitalIO_PTD7       //!< alias D12=>PTD7
#define digitalIO_D13             digitalIO_PTD5       //!< alias D13=>PTD5
#define digitalIO_D14             digitalIO_PTE0       //!< alias D14=>PTE0
#define digitalIO_D15             digitalIO_PTE1       //!< alias D15=>PTE1
#define digitalIO_GRN_LED         digitalIO_PTE29      //!< alias GRN_LED=>PTE29
#define digitalIO_LIGHT_SENS      digitalIO_PTE22      //!< alias LIGHT_SENS=>PTE22
#define digitalIO_MAG_INT         digitalIO_PTD1       //!< alias MAG_INT=>PTD1
#define digitalIO_MAG_SCL         digitalIO_PTE24      //!< alias MAG_SCL=>PTE24
#define digitalIO_MAG_SDA         digitalIO_PTE25      //!< alias MAG_SDA=>PTE25
#define digitalIO_RED_LED         digitalIO_PTD5       //!< alias RED_LED=>PTD5
#define analogueIO_A0             analogueIO_PTB0      //!< alias A0=>PTB0
#define analogueIO_A1             analogueIO_PTB1      //!< alias A1=>PTB1
#define analogueIO_A2             analogueIO_PTB2      //!< alias A2=>PTB2
#define analogueIO_A3             analogueIO_PTB3      //!< alias A3=>PTB3
#define analogueIO_A4             analogueIO_PTC2      //!< alias A4=>PTC2
#define analogueIO_A5             analogueIO_PTC1      //!< alias A5=>PTC1
#define analogueIO_ACC_INT2       analogueIO_PTD1      //!< alias ACC_INT2=>PTD1
#define analogueIO_D11            analogueIO_PTD6      //!< alias D11=>PTD6
#define analogueIO_D13            analogueIO_PTD5      //!< alias D13=>PTD5
#define analogueIO_GRN_LED        analogueIO_PTE29     //!< alias GRN_LED=>PTE29
#define analogueIO_LIGHT_SENS     analogueIO_PTE22     //!< alias LIGHT_SENS=>PTE22
#define analogueIO_MAG_INT        analogueIO_PTD1      //!< alias MAG_INT=>PTD1
#define analogueIO_RED_LED        analogueIO_PTD5      //!< alias RED_LED=>PTD5
#define pwmIO_A0                  pwmIO_PTB0           //!< alias A0=>PTB0
#define pwmIO_A1                  pwmIO_PTB1           //!< alias A1=>PTB1
#define pwmIO_A2                  pwmIO_PTB2           //!< alias A2=>PTB2
#define pwmIO_A3                  pwmIO_PTB3           //!< alias A3=>PTB3
#define pwmIO_A4                  pwmIO_PTC2           //!< alias A4=>PTC2
#define pwmIO_A5                  pwmIO_PTC1           //!< alias A5=>PTC1
#define pwmIO_ACC_INT2            pwmIO_PTD1           //!< alias ACC_INT2=>PTD1
#define pwmIO_ACC_SCL             pwmIO_PTE24          //!< alias ACC_SCL=>PTE24
#define pwmIO_ACC_SDA             pwmIO_PTE25          //!< alias ACC_SDA=>PTE25
#define pwmIO_D0                  pwmIO_PTA1           //!< alias D0=>PTA1
#define pwmIO_D1                  pwmIO_PTA2           //!< alias D1=>PTA2
#define pwmIO_D2                  pwmIO_PTD3           //!< alias D2=>PTD3
#define pwmIO_D3                  pwmIO_PTA12          //!< alias D3=>PTA12
#define pwmIO_D4                  pwmIO_PTA4           //!< alias D4=>PTA4
#define pwmIO_D5                  pwmIO_PTA5           //!< alias D5=>PTA5
#define pwmIO_D6                  pwmIO_PTC8           //!< alias D6=>PTC8
#define pwmIO_D7                  pwmIO_PTC9           //!< alias D7=>PTC9
#define pwmIO_D8                  pwmIO_PTA13          //!< alias D8=>PTA13
#define pwmIO_D9                  pwmIO_PTD2           //!< alias D9=>PTD2
#define pwmIO_D10                 pwmIO_PTD4           //!< alias D10=>PTD4
#define pwmIO_D13                 pwmIO_PTD5           //!< alias D13=>PTD5
#define pwmIO_GRN_LED             pwmIO_PTE29          //!< alias GRN_LED=>PTE29
#define pwmIO_LIGHT_SENS          pwmIO_PTE22          //!< alias LIGHT_SENS=>PTE22
#define pwmIO_MAG_INT             pwmIO_PTD1           //!< alias MAG_INT=>PTD1
#define pwmIO_MAG_SCL             pwmIO_PTE24          //!< alias MAG_SCL=>PTE24
#define pwmIO_MAG_SDA             pwmIO_PTE25          //!< alias MAG_SDA=>PTE25
#define pwmIO_RED_LED             pwmIO_PTD5           //!< alias RED_LED=>PTD5
/**
 * @}
 */
/*
ADC0_0=PTE20=[Disabled, PTE20]
ADC0_1=PTE16=[Disabled, PTE16]
ADC0_2=PTE18=[Disabled, PTE18]
ADC0_3=PTE22=[Disabled, PTE22]
ADC0_4=PTE29=[Disabled, PTE29]
ADC0_5=PTD1=[Disabled, PTD1]
ADC0_6=PTD5=[Disabled, PTD5]
ADC0_7=PTD6=[Disabled, PTD6]
ADC0_8=PTB0=[Disabled, PTB0]
ADC0_9=PTB1=[Disabled, PTB1]
ADC0_11=PTC2=[Disabled, PTC2]
ADC0_12=PTB2=[Disabled, PTB2]
ADC0_13=PTB3=[Disabled, PTB3]
ADC0_14=PTC0=[Disabled, PTC0]
ADC0_15=PTC1=[Disabled, PTC1]
ADC0_23=PTE30=[Disabled, PTE30]
I2C0_SCL=PTE24=[Disabled, PTB0, PTB2, PTC8, PTE19, PTE24]
I2C0_SDA=PTE25=[Disabled, PTB1, PTB3, PTC9, PTE18, PTE25]
I2C1_SDA=PTE0=[Disabled, PTA4, PTC2, PTC11, PTE0]
I2C1_SCL=PTE1=[Disabled, PTA3, PTC1, PTC10, PTE1]
LPTMR0_1=Disabled=[Disabled, PTA19]
LPTMR0_2=Disabled=[Disabled, PTC5]
LPTMR0_3=Disabled=[Disabled, PTE17]
SPI0_MISO=Disabled=[Disabled, PTA16, PTA17, PTC6, PTC7, PTD2, PTD3, PTE18, PTE19]
SPI0_MOSI=Disabled=[Disabled, PTA16, PTA17, PTC6, PTC7, PTD2, PTD3, PTE18, PTE19]
SPI0_PCS0=Disabled=[Disabled, PTA14, PTC4, PTD0, PTE16]
SPI0_SCK=Disabled=[Disabled, PTA15, PTC5, PTD1, PTE17]
SPI1_MISO=PTD7=[Disabled, PTB16, PTB17, PTD6, PTD7, PTE0, PTE1, PTE3]
SPI1_MOSI=PTD6=[Disabled, PTB16, PTB17, PTD6, PTD7, PTE1, PTE3]
SPI1_PCS0=PTD4=[Disabled, PTB8, PTB10, PTD4, PTE4]
SPI1_SCK=PTD5=[Disabled, PTB9, PTB11, PTD5, PTE2]
TPM0_0=PTC1=[Disabled, PTA3, PTC1, PTD0, PTE24]
TPM0_1=PTC2=[Disabled, PTA4, PTC2, PTD1, PTE25]
TPM0_2=PTD2=[Disabled, PTA5, PTC3, PTD2, PTE29]
TPM0_3=PTC4=[Disabled, PTA6, PTC4, PTD3, PTE30]
TPM0_4=PTD4=[Disabled, PTA7, PTC8, PTD4, PTE31]
TPM0_5=PTC9=[Disabled, PTA0, PTC9, PTD5, PTE26]
TPM1_0=PTA12=[Disabled, PTA12, PTB0, PTE20]
TPM1_1=PTA13=[Disabled, PTA13, PTB1, PTE21]
TPM2_0=PTB2=[Disabled, PTA1, PTB2, PTB18, PTE22]
TPM2_1=PTB3=[Disabled, PTA2, PTB3, PTB19, PTE23]

SPI1=SIM->SCGC4=SIM_SCGC4_SPI1_MASK
SPI0=SIM->SCGC4=SIM_SCGC4_SPI0_MASK
LPTMR0=SIM->SCGC5=SIM_SCGC5_LPTMR_MASK
TPM2=SIM->SCGC6=SIM_SCGC6_TPM2_MASK
TPM1=SIM->SCGC6=SIM_SCGC6_TPM1_MASK
TPM0=SIM->SCGC6=SIM_SCGC6_TPM0_MASK
ADC0=SIM->SCGC6=SIM_SCGC6_ADC0_MASK
I2C1=SIM->SCGC4=SIM_SCGC4_I2C1_MASK
I2C0=SIM->SCGC4=SIM_SCGC4_I2C0_MASK
*/

#endif /* GPIO_H_ */
