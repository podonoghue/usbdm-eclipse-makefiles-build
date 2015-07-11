/**
 * @file      GPIO.h
 * @version   1.0.0
 * @brief     Pin declarations for MK20D5
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
extern const DigitalIO digitalIO_PTA18;         //!< Digital I/O on PTA18
extern const DigitalIO digitalIO_PTA19;         //!< Digital I/O on PTA19
extern const DigitalIO digitalIO_PTB0;          //!< Digital I/O on PTB0
extern const DigitalIO digitalIO_PTB1;          //!< Digital I/O on PTB1
extern const DigitalIO digitalIO_PTB2;          //!< Digital I/O on PTB2
extern const DigitalIO digitalIO_PTB3;          //!< Digital I/O on PTB3
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
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const AnalogueIO analogueIO_ADC0_SE23;    //!< ADC0_23 on ADC0_SE23
extern const AnalogueIO analogueIO_PTB0;         //!< ADC0_8 on PTB0
extern const AnalogueIO analogueIO_PTB1;         //!< ADC0_9 on PTB1
extern const AnalogueIO analogueIO_PTB2;         //!< ADC0_12 on PTB2
extern const AnalogueIO analogueIO_PTB3;         //!< ADC0_13 on PTB3
extern const AnalogueIO analogueIO_PTC0;         //!< ADC0_14 on PTC0
extern const AnalogueIO analogueIO_PTC1;         //!< ADC0_15 on PTC1
extern const AnalogueIO analogueIO_PTC2;         //!< ADC0_4 on PTC2
extern const AnalogueIO analogueIO_PTD1;         //!< ADC0_5 on PTD1
extern const AnalogueIO analogueIO_PTD5;         //!< ADC0_6 on PTD5
extern const AnalogueIO analogueIO_PTD6;         //!< ADC0_7 on PTD6
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if FTM0_5_SEL == 1
extern const PwmIO  pwmIO_PTA0;              //!< FTM0_5 on PTA0
#endif
#if FTM0_6_SEL == 1
extern const PwmIO  pwmIO_PTA1;              //!< FTM0_6 on PTA1
#endif
#if FTM0_7_SEL == 1
extern const PwmIO  pwmIO_PTA2;              //!< FTM0_7 on PTA2
#endif
#if FTM0_0_SEL == 1
extern const PwmIO  pwmIO_PTA3;              //!< FTM0_0 on PTA3
#endif
#if FTM0_1_SEL == 1
extern const PwmIO  pwmIO_PTA4;              //!< FTM0_1 on PTA4
#endif
#if FTM0_2_SEL == 1
extern const PwmIO  pwmIO_PTA5;              //!< FTM0_2 on PTA5
#endif
#if FTM1_0_SEL == 1
extern const PwmIO  pwmIO_PTA12;             //!< FTM1_0 on PTA12
#endif
#if FTM1_1_SEL == 1
extern const PwmIO  pwmIO_PTA13;             //!< FTM1_1 on PTA13
#endif
#if FTM1_0_SEL == 2
extern const PwmIO  pwmIO_PTB0;              //!< FTM1_0 on PTB0
#endif
#if FTM1_1_SEL == 2
extern const PwmIO  pwmIO_PTB1;              //!< FTM1_1 on PTB1
#endif
#if FTM0_0_SEL == 2
extern const PwmIO  pwmIO_PTC1;              //!< FTM0_0 on PTC1
#endif
#if FTM0_1_SEL == 2
extern const PwmIO  pwmIO_PTC2;              //!< FTM0_1 on PTC2
#endif
#if FTM0_2_SEL == 2
extern const PwmIO  pwmIO_PTC3;              //!< FTM0_2 on PTC3
#endif
#if FTM0_3_SEL == 1
extern const PwmIO  pwmIO_PTC4;              //!< FTM0_3 on PTC4
#endif
#if FTM0_4_SEL == 1
extern const PwmIO  pwmIO_PTD4;              //!< FTM0_4 on PTD4
#endif
#if FTM0_5_SEL == 2
extern const PwmIO  pwmIO_PTD5;              //!< FTM0_5 on PTD5
#endif
#if FTM0_6_SEL == 2
extern const PwmIO  pwmIO_PTD6;              //!< FTM0_6 on PTD6
#endif
#if FTM0_7_SEL == 2
extern const PwmIO  pwmIO_PTD7;              //!< FTM0_7 on PTD7
#endif
/**
 * @}
 */
/**
* @addtogroup alias_pin_mappings_GROUP Aliases for pins
* @brief Aliases for port pins for example Arduino based names
* @{
*/
#define digitalIO_A0         digitalIO_PTC0       //!< alias A0=>PTC0
#define digitalIO_A1         digitalIO_PTC1       //!< alias A1=>PTC1
#define digitalIO_A2         digitalIO_PTD6       //!< alias A2=>PTD6
#define digitalIO_A3         digitalIO_PTD5       //!< alias A3=>PTD5
#define digitalIO_A4         digitalIO_PTB1       //!< alias A4=>PTB1
#define digitalIO_A5         digitalIO_PTB0       //!< alias A5=>PTB0
#define digitalIO_D0         digitalIO_PTE1       //!< alias D0=>PTE1
#define digitalIO_D1         digitalIO_PTE0       //!< alias D1=>PTE0
#define digitalIO_D2         digitalIO_PTA5       //!< alias D2=>PTA5
#define digitalIO_D3         digitalIO_PTD4       //!< alias D3=>PTD4
#define digitalIO_D4         digitalIO_PTC8       //!< alias D4=>PTC8
#define digitalIO_D5         digitalIO_PTA1       //!< alias D5=>PTA1
#define digitalIO_D6         digitalIO_PTC3       //!< alias D6=>PTC3
#define digitalIO_D7         digitalIO_PTC4       //!< alias D7=>PTC4
#define digitalIO_D8         digitalIO_PTA12      //!< alias D8=>PTA12
#define digitalIO_D9         digitalIO_PTA2       //!< alias D9=>PTA2
#define digitalIO_D10        digitalIO_PTC2       //!< alias D10=>PTC2
#define digitalIO_D11        digitalIO_PTD2       //!< alias D11=>PTD2
#define digitalIO_D12        digitalIO_PTD3       //!< alias D12=>PTD3
#define digitalIO_D13        digitalIO_PTD1       //!< alias D13=>PTD1
#define digitalIO_D14        digitalIO_PTB3       //!< alias D14=>PTB3
#define digitalIO_D15        digitalIO_PTB2       //!< alias D15=>PTB2
#define digitalIO_D16        digitalIO_PTD0       //!< alias D16=>PTD0
#define digitalIO_D17        digitalIO_PTC11      //!< alias D17=>PTC11
#define digitalIO_D18        digitalIO_PTC5       //!< alias D18=>PTC5
#define digitalIO_D19        digitalIO_PTC6       //!< alias D19=>PTC6
#define digitalIO_D20        digitalIO_PTC7       //!< alias D20=>PTC7
#define digitalIO_D21        digitalIO_PTA4       //!< alias D21=>PTA4
#define digitalIO_D22        digitalIO_PTD7       //!< alias D22=>PTD7
#define digitalIO_D23        digitalIO_PTC9       //!< alias D23=>PTC9
#define digitalIO_D24        digitalIO_PTA13      //!< alias D24=>PTA13
#define digitalIO_D25        digitalIO_PTC10      //!< alias D25=>PTC10
#define analogueIO_A0        analogueIO_PTC0      //!< alias A0=>PTC0
#define analogueIO_A1        analogueIO_PTC1      //!< alias A1=>PTC1
#define analogueIO_A2        analogueIO_PTD6      //!< alias A2=>PTD6
#define analogueIO_A3        analogueIO_PTD5      //!< alias A3=>PTD5
#define analogueIO_A4        analogueIO_PTB1      //!< alias A4=>PTB1
#define analogueIO_A5        analogueIO_PTB0      //!< alias A5=>PTB0
#define analogueIO_D10       analogueIO_PTC2      //!< alias D10=>PTC2
#define analogueIO_D13       analogueIO_PTD1      //!< alias D13=>PTD1
#define analogueIO_D14       analogueIO_PTB3      //!< alias D14=>PTB3
#define analogueIO_D15       analogueIO_PTB2      //!< alias D15=>PTB2
#define pwmIO_A1             pwmIO_PTC1           //!< alias A1=>PTC1
#define pwmIO_A2             pwmIO_PTD6           //!< alias A2=>PTD6
#define pwmIO_A3             pwmIO_PTD5           //!< alias A3=>PTD5
#define pwmIO_A4             pwmIO_PTB1           //!< alias A4=>PTB1
#define pwmIO_A5             pwmIO_PTB0           //!< alias A5=>PTB0
#define pwmIO_D2             pwmIO_PTA5           //!< alias D2=>PTA5
#define pwmIO_D3             pwmIO_PTD4           //!< alias D3=>PTD4
#define pwmIO_D5             pwmIO_PTA1           //!< alias D5=>PTA1
#define pwmIO_D6             pwmIO_PTC3           //!< alias D6=>PTC3
#define pwmIO_D7             pwmIO_PTC4           //!< alias D7=>PTC4
#define pwmIO_D8             pwmIO_PTA12          //!< alias D8=>PTA12
#define pwmIO_D9             pwmIO_PTA2           //!< alias D9=>PTA2
#define pwmIO_D10            pwmIO_PTC2           //!< alias D10=>PTC2
#define pwmIO_D21            pwmIO_PTA4           //!< alias D21=>PTA4
#define pwmIO_D22            pwmIO_PTD7           //!< alias D22=>PTD7
#define pwmIO_D24            pwmIO_PTA13          //!< alias D24=>PTA13
/**
 * @}
 */
/*
ADC0_12=PTB2=[Disabled, PTB2]
ADC0_13=PTB3=[Disabled, PTB3]
ADC0_14=PTC0=[Disabled, PTC0]
ADC0_15=PTC1=[Disabled, PTC1]
ADC0_23=ADC0_SE23=[Disabled, ADC0_SE23]
ADC0_4=PTC2=[Disabled, PTC2]
ADC0_5=PTD1=[Disabled, PTD1]
ADC0_6=PTD5=[Disabled, PTD5]
ADC0_7=PTD6=[Disabled, PTD6]
ADC0_8=PTB0=[Disabled, PTB0]
ADC0_9=PTB1=[Disabled, PTB1]
FTM0_0=PTC1=[Disabled, PTA3, PTC1]
FTM0_1=PTC2=[Disabled, PTA4, PTC2]
FTM0_2=PTC3=[Disabled, PTA5, PTC3]
FTM0_3=PTC4=[Disabled, PTC4]
FTM0_4=PTD4=[Disabled, PTD4]
FTM0_5=PTD5=[Disabled, PTA0, PTD5]
FTM0_6=PTA1=[Disabled, PTA1, PTD6]
FTM0_7=PTA2=[Disabled, PTA2, PTD7]
FTM1_0=PTA12=[Disabled, PTA12, PTB0]
FTM1_1=PTA13=[Disabled, PTA13, PTB1]
I2C0_SCL=PTB0=[Disabled, PTB0, PTB2]
I2C0_SDA=PTB1=[Disabled, PTB1, PTB3]
SPI0_PCS0=Disabled=[Disabled, PTC4, PTD0]
SPI0_PCS1=Disabled=[Disabled, PTC3, PTD4]
SPI0_PCS2=Disabled=[Disabled, PTC2, PTD5]
SPI0_PCS3=Disabled=[Disabled, PTC1, PTD6]
SPI0_PCS4=Disabled=[Disabled, PTC0]
SPI0_SCK=PTD1=[Disabled, PTC5, PTD1]
SPI0_SIN=PTD3=[Disabled, PTC7, PTD3]
SPI0_SOUT=PTD2=[Disabled, PTC6, PTD2]

ADC0=SIM->SCGC6=SIM_SCGC6_ADC0_MASK
I2C0=SIM->SCGC4=SIM_SCGC4_I2C0_MASK
SPI0=SIM->SCGC6=SIM_SCGC6_SPI0_MASK
FTM0=SIM->SCGC6=SIM_SCGC6_FTM0_MASK
FTM1=SIM->SCGC6=SIM_SCGC6_FTM1_MASK
*/

#endif /* GPIO_H_ */
