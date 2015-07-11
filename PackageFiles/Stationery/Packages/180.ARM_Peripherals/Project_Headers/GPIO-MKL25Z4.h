/**
 * @file      GPIO.h
 * @version   1.0.0
 * @brief     Pin declarations for MKL25Z4
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "derivative.h"
#include "PinMapping.h"
#include "GPIO_defs.h"

/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const DigitalIO digitalIO_PTA0;          //!< Digital I/O on PTA0
extern const DigitalIO digitalIO_PTA1;          //!< Digital I/O on PTA1
extern const DigitalIO digitalIO_PTA2;          //!< Digital I/O on PTA2
extern const DigitalIO digitalIO_PTA3;          //!< Digital I/O on PTA3
extern const DigitalIO digitalIO_PTA4;          //!< Digital I/O on PTA4
extern const DigitalIO digitalIO_PTA5;          //!< Digital I/O on PTA5
extern const DigitalIO digitalIO_PTA12;         //!< Digital I/O on PTA12
extern const DigitalIO digitalIO_PTA13;         //!< Digital I/O on PTA13
extern const DigitalIO digitalIO_PTA14;         //!< Digital I/O on PTA14
extern const DigitalIO digitalIO_PTA15;         //!< Digital I/O on PTA15
extern const DigitalIO digitalIO_PTA16;         //!< Digital I/O on PTA16
extern const DigitalIO digitalIO_PTA17;         //!< Digital I/O on PTA17
extern const DigitalIO digitalIO_PTA18;         //!< Digital I/O on PTA18
extern const DigitalIO digitalIO_PTA19;         //!< Digital I/O on PTA19
extern const DigitalIO digitalIO_PTA20;         //!< Digital I/O on PTA20
extern const DigitalIO digitalIO_PTB0;          //!< Digital I/O on PTB0
extern const DigitalIO digitalIO_PTB1;          //!< Digital I/O on PTB1
extern const DigitalIO digitalIO_PTB2;          //!< Digital I/O on PTB2
extern const DigitalIO digitalIO_PTB3;          //!< Digital I/O on PTB3
extern const DigitalIO digitalIO_PTB8;          //!< Digital I/O on PTB8
extern const DigitalIO digitalIO_PTB9;          //!< Digital I/O on PTB9
extern const DigitalIO digitalIO_PTB10;         //!< Digital I/O on PTB10
extern const DigitalIO digitalIO_PTB11;         //!< Digital I/O on PTB11
extern const DigitalIO digitalIO_PTB16;         //!< Digital I/O on PTB16
extern const DigitalIO digitalIO_PTB17;         //!< Digital I/O on PTB17
extern const DigitalIO digitalIO_PTB18;         //!< Digital I/O on PTB18
extern const DigitalIO digitalIO_PTB19;         //!< Digital I/O on PTB19
extern const DigitalIO digitalIO_PTC0;          //!< Digital I/O on PTC0
extern const DigitalIO digitalIO_PTC1;          //!< Digital I/O on PTC1
extern const DigitalIO digitalIO_PTC2;          //!< Digital I/O on PTC2
extern const DigitalIO digitalIO_PTC3;          //!< Digital I/O on PTC3
extern const DigitalIO digitalIO_PTC4;          //!< Digital I/O on PTC4
extern const DigitalIO digitalIO_PTC5;          //!< Digital I/O on PTC5
extern const DigitalIO digitalIO_PTC6;          //!< Digital I/O on PTC6
extern const DigitalIO digitalIO_PTC7;          //!< Digital I/O on PTC7
extern const DigitalIO digitalIO_PTC8;          //!< Digital I/O on PTC8
extern const DigitalIO digitalIO_PTC9;          //!< Digital I/O on PTC9
extern const DigitalIO digitalIO_PTC10;         //!< Digital I/O on PTC10
extern const DigitalIO digitalIO_PTC11;         //!< Digital I/O on PTC11
extern const DigitalIO digitalIO_PTC12;         //!< Digital I/O on PTC12
extern const DigitalIO digitalIO_PTC13;         //!< Digital I/O on PTC13
extern const DigitalIO digitalIO_PTC16;         //!< Digital I/O on PTC16
extern const DigitalIO digitalIO_PTC17;         //!< Digital I/O on PTC17
extern const DigitalIO digitalIO_PTD0;          //!< Digital I/O on PTD0
extern const DigitalIO digitalIO_PTD1;          //!< Digital I/O on PTD1
extern const DigitalIO digitalIO_PTD2;          //!< Digital I/O on PTD2
extern const DigitalIO digitalIO_PTD3;          //!< Digital I/O on PTD3
extern const DigitalIO digitalIO_PTD4;          //!< Digital I/O on PTD4
extern const DigitalIO digitalIO_PTD5;          //!< Digital I/O on PTD5
extern const DigitalIO digitalIO_PTD6;          //!< Digital I/O on PTD6
extern const DigitalIO digitalIO_PTD7;          //!< Digital I/O on PTD7
extern const DigitalIO digitalIO_PTE0;          //!< Digital I/O on PTE0
extern const DigitalIO digitalIO_PTE1;          //!< Digital I/O on PTE1
extern const DigitalIO digitalIO_PTE2;          //!< Digital I/O on PTE2
extern const DigitalIO digitalIO_PTE3;          //!< Digital I/O on PTE3
extern const DigitalIO digitalIO_PTE4;          //!< Digital I/O on PTE4
extern const DigitalIO digitalIO_PTE5;          //!< Digital I/O on PTE5
extern const DigitalIO digitalIO_PTE20;         //!< Digital I/O on PTE20
extern const DigitalIO digitalIO_PTE21;         //!< Digital I/O on PTE21
extern const DigitalIO digitalIO_PTE22;         //!< Digital I/O on PTE22
extern const DigitalIO digitalIO_PTE23;         //!< Digital I/O on PTE23
extern const DigitalIO digitalIO_PTE24;         //!< Digital I/O on PTE24
extern const DigitalIO digitalIO_PTE25;         //!< Digital I/O on PTE25
extern const DigitalIO digitalIO_PTE29;         //!< Digital I/O on PTE29
extern const DigitalIO digitalIO_PTE30;         //!< Digital I/O on PTE30
extern const DigitalIO digitalIO_PTE31;         //!< Digital I/O on PTE31
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const AnalogueIO analogueIO_PTB0;         //!< ADC0_8 on PTB0
extern const AnalogueIO analogueIO_PTB1;         //!< ADC0_9 on PTB1
extern const AnalogueIO analogueIO_PTB2;         //!< ADC0_12 on PTB2
extern const AnalogueIO analogueIO_PTB3;         //!< ADC0_13 on PTB3
extern const AnalogueIO analogueIO_PTC0;         //!< ADC0_14 on PTC0
extern const AnalogueIO analogueIO_PTC1;         //!< ADC0_15 on PTC1
extern const AnalogueIO analogueIO_PTC2;         //!< ADC0_11 on PTC2
extern const AnalogueIO analogueIO_PTD1;         //!< ADC0_5 on PTD1
extern const AnalogueIO analogueIO_PTD5;         //!< ADC0_6 on PTD5
extern const AnalogueIO analogueIO_PTD6;         //!< ADC0_7 on PTD6
extern const AnalogueIO analogueIO_PTE20;        //!< ADC0_0 on PTE20
extern const AnalogueIO analogueIO_PTE22;        //!< ADC0_3 on PTE22
extern const AnalogueIO analogueIO_PTE29;        //!< ADC0_4 on PTE29
extern const AnalogueIO analogueIO_PTE30;        //!< ADC0_23 on PTE30
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if TPM0_5_SEL == 1
extern const PwmIO  pwmIO_PTA0;              //!< TPM0_5 on PTA0
#endif
#if TPM2_0_SEL == 1
extern const PwmIO  pwmIO_PTA1;              //!< TPM2_0 on PTA1
#endif
#if TPM2_1_SEL == 1
extern const PwmIO  pwmIO_PTA2;              //!< TPM2_1 on PTA2
#endif
#if TPM0_0_SEL == 1
extern const PwmIO  pwmIO_PTA3;              //!< TPM0_0 on PTA3
#endif
#if TPM0_1_SEL == 1
extern const PwmIO  pwmIO_PTA4;              //!< TPM0_1 on PTA4
#endif
#if TPM0_2_SEL == 1
extern const PwmIO  pwmIO_PTA5;              //!< TPM0_2 on PTA5
#endif
#if TPM1_0_SEL == 1
extern const PwmIO  pwmIO_PTA12;             //!< TPM1_0 on PTA12
#endif
#if TPM1_1_SEL == 1
extern const PwmIO  pwmIO_PTA13;             //!< TPM1_1 on PTA13
#endif
#if TPM1_0_SEL == 2
extern const PwmIO  pwmIO_PTB0;              //!< TPM1_0 on PTB0
#endif
#if TPM1_1_SEL == 2
extern const PwmIO  pwmIO_PTB1;              //!< TPM1_1 on PTB1
#endif
#if TPM2_0_SEL == 2
extern const PwmIO  pwmIO_PTB2;              //!< TPM2_0 on PTB2
#endif
#if TPM2_1_SEL == 2
extern const PwmIO  pwmIO_PTB3;              //!< TPM2_1 on PTB3
#endif
#if TPM2_0_SEL == 3
extern const PwmIO  pwmIO_PTB18;             //!< TPM2_0 on PTB18
#endif
#if TPM2_1_SEL == 3
extern const PwmIO  pwmIO_PTB19;             //!< TPM2_1 on PTB19
#endif
#if TPM0_0_SEL == 2
extern const PwmIO  pwmIO_PTC1;              //!< TPM0_0 on PTC1
#endif
#if TPM0_1_SEL == 2
extern const PwmIO  pwmIO_PTC2;              //!< TPM0_1 on PTC2
#endif
#if TPM0_2_SEL == 2
extern const PwmIO  pwmIO_PTC3;              //!< TPM0_2 on PTC3
#endif
#if TPM0_3_SEL == 1
extern const PwmIO  pwmIO_PTC4;              //!< TPM0_3 on PTC4
#endif
#if TPM0_4_SEL == 1
extern const PwmIO  pwmIO_PTC8;              //!< TPM0_4 on PTC8
#endif
#if TPM0_5_SEL == 2
extern const PwmIO  pwmIO_PTC9;              //!< TPM0_5 on PTC9
#endif
#if TPM0_0_SEL == 3
extern const PwmIO  pwmIO_PTD0;              //!< TPM0_0 on PTD0
#endif
#if TPM0_1_SEL == 3
extern const PwmIO  pwmIO_PTD1;              //!< TPM0_1 on PTD1
#endif
#if TPM0_2_SEL == 3
extern const PwmIO  pwmIO_PTD2;              //!< TPM0_2 on PTD2
#endif
#if TPM0_3_SEL == 2
extern const PwmIO  pwmIO_PTD3;              //!< TPM0_3 on PTD3
#endif
#if TPM0_4_SEL == 2
extern const PwmIO  pwmIO_PTD4;              //!< TPM0_4 on PTD4
#endif
#if TPM0_5_SEL == 3
extern const PwmIO  pwmIO_PTD5;              //!< TPM0_5 on PTD5
#endif
#if TPM1_0_SEL == 3
extern const PwmIO  pwmIO_PTE20;             //!< TPM1_0 on PTE20
#endif
#if TPM1_1_SEL == 3
extern const PwmIO  pwmIO_PTE21;             //!< TPM1_1 on PTE21
#endif
#if TPM2_0_SEL == 4
extern const PwmIO  pwmIO_PTE22;             //!< TPM2_0 on PTE22
#endif
#if TPM2_1_SEL == 4
extern const PwmIO  pwmIO_PTE23;             //!< TPM2_1 on PTE23
#endif
#if TPM0_0_SEL == 4
extern const PwmIO  pwmIO_PTE24;             //!< TPM0_0 on PTE24
#endif
#if TPM0_1_SEL == 4
extern const PwmIO  pwmIO_PTE25;             //!< TPM0_1 on PTE25
#endif
#if TPM0_2_SEL == 4
extern const PwmIO  pwmIO_PTE29;             //!< TPM0_2 on PTE29
#endif
#if TPM0_3_SEL == 3
extern const PwmIO  pwmIO_PTE30;             //!< TPM0_3 on PTE30
#endif
#if TPM0_4_SEL == 3
extern const PwmIO  pwmIO_PTE31;             //!< TPM0_4 on PTE31
#endif
/**
 * @}
 */
/**
* @addtogroup alias_pin_mappings_GROUP Aliases for pins
* @brief Aliases for port pins for example Arduino based names
* @{
*/
#define digitalIO_A0         digitalIO_PTB0       //!< alias A0=>PTB0
#define digitalIO_A1         digitalIO_PTB1       //!< alias A1=>PTB1
#define digitalIO_A2         digitalIO_PTB2       //!< alias A2=>PTB2
#define digitalIO_A3         digitalIO_PTB3       //!< alias A3=>PTB3
#define digitalIO_A4         digitalIO_PTC2       //!< alias A4=>PTC2
#define digitalIO_A5         digitalIO_PTC1       //!< alias A5=>PTC1
#define digitalIO_A6         digitalIO_PTE30      //!< alias A6=>PTE30
#define digitalIO_A7         digitalIO_PTE29      //!< alias A7=>PTE29
#define digitalIO_A8         digitalIO_PTE23      //!< alias A8=>PTE23
#define digitalIO_A9         digitalIO_PTE22      //!< alias A9=>PTE22
#define digitalIO_A10        digitalIO_PTE21      //!< alias A10=>PTE21
#define digitalIO_A11        digitalIO_PTE20      //!< alias A11=>PTE20
#define digitalIO_A13        digitalIO_PTE5       //!< alias A13=>PTE5
#define digitalIO_A14        digitalIO_PTE4       //!< alias A14=>PTE4
#define digitalIO_A15        digitalIO_PTE3       //!< alias A15=>PTE3
#define digitalIO_A16        digitalIO_PTE2       //!< alias A16=>PTE2
#define digitalIO_A17        digitalIO_PTB11      //!< alias A17=>PTB11
#define digitalIO_A18        digitalIO_PTB10      //!< alias A18=>PTB10
#define digitalIO_A19        digitalIO_PTB9       //!< alias A19=>PTB9
#define digitalIO_A20        digitalIO_PTB8       //!< alias A20=>PTB8
#define digitalIO_D0         digitalIO_PTA1       //!< alias D0=>PTA1
#define digitalIO_D1         digitalIO_PTA2       //!< alias D1=>PTA2
#define digitalIO_D2         digitalIO_PTD4       //!< alias D2=>PTD4
#define digitalIO_D3         digitalIO_PTA12      //!< alias D3=>PTA12
#define digitalIO_D4         digitalIO_PTA4       //!< alias D4=>PTA4
#define digitalIO_D5         digitalIO_PTA5       //!< alias D5=>PTA5
#define digitalIO_D6         digitalIO_PTC8       //!< alias D6=>PTC8
#define digitalIO_D7         digitalIO_PTC9       //!< alias D7=>PTC9
#define digitalIO_D8         digitalIO_PTA13      //!< alias D8=>PTA13
#define digitalIO_D9         digitalIO_PTD5       //!< alias D9=>PTD5
#define digitalIO_D10        digitalIO_PTD0       //!< alias D10=>PTD0
#define digitalIO_D11        digitalIO_PTD2       //!< alias D11=>PTD2
#define digitalIO_D12        digitalIO_PTD3       //!< alias D12=>PTD3
#define digitalIO_D13        digitalIO_PTD1       //!< alias D13=>PTD1
#define digitalIO_D14        digitalIO_PTE1       //!< alias D14=>PTE1
#define digitalIO_D15        digitalIO_PTE0       //!< alias D15=>PTE0
#define digitalIO_D16        digitalIO_PTC7       //!< alias D16=>PTC7
#define digitalIO_D17        digitalIO_PTC0       //!< alias D17=>PTC0
#define digitalIO_D18        digitalIO_PTC3       //!< alias D18=>PTC3
#define digitalIO_D19        digitalIO_PTC4       //!< alias D19=>PTC4
#define digitalIO_D20        digitalIO_PTC5       //!< alias D20=>PTC5
#define digitalIO_D21        digitalIO_PTC6       //!< alias D21=>PTC6
#define digitalIO_D22        digitalIO_PTC10      //!< alias D22=>PTC10
#define digitalIO_D23        digitalIO_PTC11      //!< alias D23=>PTC11
#define digitalIO_D24        digitalIO_PTC12      //!< alias D24=>PTC12
#define digitalIO_D25        digitalIO_PTC13      //!< alias D25=>PTC13
#define digitalIO_D26        digitalIO_PTC16      //!< alias D26=>PTC16
#define digitalIO_D27        digitalIO_PTC17      //!< alias D27=>PTC17
#define digitalIO_D28        digitalIO_PTA16      //!< alias D28=>PTA16
#define digitalIO_D29        digitalIO_PTA17      //!< alias D29=>PTA17
#define digitalIO_D30        digitalIO_PTE31      //!< alias D30=>PTE31
#define digitalIO_D32        digitalIO_PTD6       //!< alias D32=>PTD6
#define digitalIO_D33        digitalIO_PTD7       //!< alias D33=>PTD7
#define analogueIO_A0        analogueIO_PTB0      //!< alias A0=>PTB0
#define analogueIO_A1        analogueIO_PTB1      //!< alias A1=>PTB1
#define analogueIO_A2        analogueIO_PTB2      //!< alias A2=>PTB2
#define analogueIO_A3        analogueIO_PTB3      //!< alias A3=>PTB3
#define analogueIO_A4        analogueIO_PTC2      //!< alias A4=>PTC2
#define analogueIO_A5        analogueIO_PTC1      //!< alias A5=>PTC1
#define analogueIO_A6        analogueIO_PTE30     //!< alias A6=>PTE30
#define analogueIO_A7        analogueIO_PTE29     //!< alias A7=>PTE29
#define analogueIO_A9        analogueIO_PTE22     //!< alias A9=>PTE22
#define analogueIO_A11       analogueIO_PTE20     //!< alias A11=>PTE20
#define analogueIO_D9        analogueIO_PTD5      //!< alias D9=>PTD5
#define analogueIO_D13       analogueIO_PTD1      //!< alias D13=>PTD1
#define analogueIO_D17       analogueIO_PTC0      //!< alias D17=>PTC0
#define analogueIO_D32       analogueIO_PTD6      //!< alias D32=>PTD6
#define pwmIO_A0             pwmIO_PTB0           //!< alias A0=>PTB0
#define pwmIO_A1             pwmIO_PTB1           //!< alias A1=>PTB1
#define pwmIO_A2             pwmIO_PTB2           //!< alias A2=>PTB2
#define pwmIO_A3             pwmIO_PTB3           //!< alias A3=>PTB3
#define pwmIO_A4             pwmIO_PTC2           //!< alias A4=>PTC2
#define pwmIO_A5             pwmIO_PTC1           //!< alias A5=>PTC1
#define pwmIO_A6             pwmIO_PTE30          //!< alias A6=>PTE30
#define pwmIO_A7             pwmIO_PTE29          //!< alias A7=>PTE29
#define pwmIO_A8             pwmIO_PTE23          //!< alias A8=>PTE23
#define pwmIO_A9             pwmIO_PTE22          //!< alias A9=>PTE22
#define pwmIO_A10            pwmIO_PTE21          //!< alias A10=>PTE21
#define pwmIO_A11            pwmIO_PTE20          //!< alias A11=>PTE20
#define pwmIO_D0             pwmIO_PTA1           //!< alias D0=>PTA1
#define pwmIO_D1             pwmIO_PTA2           //!< alias D1=>PTA2
#define pwmIO_D2             pwmIO_PTD4           //!< alias D2=>PTD4
#define pwmIO_D3             pwmIO_PTA12          //!< alias D3=>PTA12
#define pwmIO_D4             pwmIO_PTA4           //!< alias D4=>PTA4
#define pwmIO_D5             pwmIO_PTA5           //!< alias D5=>PTA5
#define pwmIO_D6             pwmIO_PTC8           //!< alias D6=>PTC8
#define pwmIO_D7             pwmIO_PTC9           //!< alias D7=>PTC9
#define pwmIO_D8             pwmIO_PTA13          //!< alias D8=>PTA13
#define pwmIO_D9             pwmIO_PTD5           //!< alias D9=>PTD5
#define pwmIO_D10            pwmIO_PTD0           //!< alias D10=>PTD0
#define pwmIO_D11            pwmIO_PTD2           //!< alias D11=>PTD2
#define pwmIO_D12            pwmIO_PTD3           //!< alias D12=>PTD3
#define pwmIO_D13            pwmIO_PTD1           //!< alias D13=>PTD1
#define pwmIO_D18            pwmIO_PTC3           //!< alias D18=>PTC3
#define pwmIO_D19            pwmIO_PTC4           //!< alias D19=>PTC4
#define pwmIO_D30            pwmIO_PTE31          //!< alias D30=>PTE31
/**
 * @}
 */
/*
ADC0_0=PTE20=[Disabled, PTE20]
ADC0_11=PTC2=[Disabled, PTC2]
ADC0_12=PTB2=[Disabled, PTB2]
ADC0_13=PTB3=[Disabled, PTB3]
ADC0_14=PTC0=[Disabled, PTC0]
ADC0_15=PTC1=[Disabled, PTC1]
ADC0_23=PTE30=[Disabled, PTE30]
ADC0_3=PTE22=[Disabled, PTE22]
ADC0_4=PTE29=[Disabled, PTE29]
ADC0_5=PTD1=[Disabled, PTD1]
ADC0_6=PTD5=[Disabled, PTD5]
ADC0_7=PTD6=[Disabled, PTD6]
ADC0_8=PTB0=[Disabled, PTB0]
ADC0_9=PTB1=[Disabled, PTB1]
I2C0_SCL=PTE24=[Disabled, PTB0, PTB2, PTC8, PTE24]
I2C0_SDA=PTE25=[Disabled, PTB1, PTB3, PTC9, PTE25]
I2C1_SCL=PTE1=[Disabled, PTA3, PTC1, PTC10, PTE1]
I2C1_SDA=PTE0=[Disabled, PTA4, PTC2, PTC11, PTE0]
SPI0_MISO=PTD3=[Disabled, PTA16, PTA17, PTC6, PTC7, PTD2, PTD3]
SPI0_MOSI=PTD2=[Disabled, PTA16, PTA17, PTC6, PTC7, PTD2, PTD3]
SPI0_PCS0=Disabled=[Disabled, PTA14, PTC4, PTD0]
SPI0_SCK=PTD1=[Disabled, PTA15, PTC5, PTD1]
SPI1_MISO=PTB16=[Disabled, PTB16, PTB17, PTD6, PTD7, PTE1, PTE3]
SPI1_MOSI=PTB17=[Disabled, PTB16, PTB17, PTD6, PTD7, PTE1, PTE3]
SPI1_PCS0=Disabled=[Disabled, PTB10, PTD4, PTE4]
SPI1_SCK=PTB11=[Disabled, PTB11, PTD5, PTE2]
TPM0_0=PTD0=[Disabled, PTA3, PTC1, PTD0, PTE24]
TPM0_1=PTD1=[Disabled, PTA4, PTC2, PTD1, PTE25]
TPM0_2=PTA5=[Disabled, PTA5, PTC3, PTD2, PTE29]
TPM0_3=PTC4=[Disabled, PTC4, PTD3, PTE30]
TPM0_4=PTC8=[Disabled, PTC8, PTD4, PTE31]
TPM0_5=PTC9=[Disabled, PTA0, PTC9, PTD5]
TPM1_0=PTA12=[Disabled, PTA12, PTB0, PTE20]
TPM1_1=PTA13=[Disabled, PTA13, PTB1, PTE21]
TPM2_0=PTA1=[Disabled, PTA1, PTB2, PTB18, PTE22]
TPM2_1=PTA2=[Disabled, PTA2, PTB3, PTB19, PTE23]

TPM0=SIM->SCGC6=SIM_SCGC6_TPM0_MASK
TPM1=SIM->SCGC6=SIM_SCGC6_TPM1_MASK
TPM2=SIM->SCGC6=SIM_SCGC6_TPM2_MASK
ADC0=SIM->SCGC6=SIM_SCGC6_ADC0_MASK
I2C0=SIM->SCGC4=SIM_SCGC4_I2C0_MASK
I2C1=SIM->SCGC4=SIM_SCGC4_I2C1_MASK
SPI0=SIM->SCGC4=SIM_SCGC4_SPI0_MASK
SPI1=SIM->SCGC4=SIM_SCGC4_SPI1_MASK
*/

#endif /* GPIO_H_ */
