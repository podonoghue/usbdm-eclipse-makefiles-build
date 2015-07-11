/**
 * @file      GPIO.h
 * @version   1.0.0
 * @brief     Pin declarations for MK64F12
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
extern const DigitalIO digitalIO_PTA6;          //!< Digital I/O on PTA6
extern const DigitalIO digitalIO_PTA7;          //!< Digital I/O on PTA7
extern const DigitalIO digitalIO_PTA8;          //!< Digital I/O on PTA8
extern const DigitalIO digitalIO_PTA9;          //!< Digital I/O on PTA9
extern const DigitalIO digitalIO_PTA10;         //!< Digital I/O on PTA10
extern const DigitalIO digitalIO_PTA11;         //!< Digital I/O on PTA11
extern const DigitalIO digitalIO_PTA12;         //!< Digital I/O on PTA12
extern const DigitalIO digitalIO_PTA13;         //!< Digital I/O on PTA13
extern const DigitalIO digitalIO_PTA14;         //!< Digital I/O on PTA14
extern const DigitalIO digitalIO_PTA15;         //!< Digital I/O on PTA15
extern const DigitalIO digitalIO_PTA16;         //!< Digital I/O on PTA16
extern const DigitalIO digitalIO_PTA17;         //!< Digital I/O on PTA17
extern const DigitalIO digitalIO_PTA18;         //!< Digital I/O on PTA18
extern const DigitalIO digitalIO_PTA19;         //!< Digital I/O on PTA19
extern const DigitalIO digitalIO_PTA24;         //!< Digital I/O on PTA24
extern const DigitalIO digitalIO_PTA25;         //!< Digital I/O on PTA25
extern const DigitalIO digitalIO_PTA26;         //!< Digital I/O on PTA26
extern const DigitalIO digitalIO_PTA27;         //!< Digital I/O on PTA27
extern const DigitalIO digitalIO_PTA28;         //!< Digital I/O on PTA28
extern const DigitalIO digitalIO_PTA29;         //!< Digital I/O on PTA29
extern const DigitalIO digitalIO_PTB0;          //!< Digital I/O on PTB0
extern const DigitalIO digitalIO_PTB1;          //!< Digital I/O on PTB1
extern const DigitalIO digitalIO_PTB2;          //!< Digital I/O on PTB2
extern const DigitalIO digitalIO_PTB3;          //!< Digital I/O on PTB3
extern const DigitalIO digitalIO_PTB4;          //!< Digital I/O on PTB4
extern const DigitalIO digitalIO_PTB5;          //!< Digital I/O on PTB5
extern const DigitalIO digitalIO_PTB6;          //!< Digital I/O on PTB6
extern const DigitalIO digitalIO_PTB7;          //!< Digital I/O on PTB7
extern const DigitalIO digitalIO_PTB8;          //!< Digital I/O on PTB8
extern const DigitalIO digitalIO_PTB9;          //!< Digital I/O on PTB9
extern const DigitalIO digitalIO_PTB10;         //!< Digital I/O on PTB10
extern const DigitalIO digitalIO_PTB11;         //!< Digital I/O on PTB11
extern const DigitalIO digitalIO_PTB12;         //!< Digital I/O on PTB12
extern const DigitalIO digitalIO_PTB13;         //!< Digital I/O on PTB13
extern const DigitalIO digitalIO_PTB16;         //!< Digital I/O on PTB16
extern const DigitalIO digitalIO_PTB17;         //!< Digital I/O on PTB17
extern const DigitalIO digitalIO_PTB18;         //!< Digital I/O on PTB18
extern const DigitalIO digitalIO_PTB19;         //!< Digital I/O on PTB19
extern const DigitalIO digitalIO_PTB20;         //!< Digital I/O on PTB20
extern const DigitalIO digitalIO_PTB21;         //!< Digital I/O on PTB21
extern const DigitalIO digitalIO_PTB22;         //!< Digital I/O on PTB22
extern const DigitalIO digitalIO_PTB23;         //!< Digital I/O on PTB23
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
extern const DigitalIO digitalIO_PTC14;         //!< Digital I/O on PTC14
extern const DigitalIO digitalIO_PTC15;         //!< Digital I/O on PTC15
extern const DigitalIO digitalIO_PTC16;         //!< Digital I/O on PTC16
extern const DigitalIO digitalIO_PTC17;         //!< Digital I/O on PTC17
extern const DigitalIO digitalIO_PTC18;         //!< Digital I/O on PTC18
extern const DigitalIO digitalIO_PTC19;         //!< Digital I/O on PTC19
extern const DigitalIO digitalIO_PTD0;          //!< Digital I/O on PTD0
extern const DigitalIO digitalIO_PTD1;          //!< Digital I/O on PTD1
extern const DigitalIO digitalIO_PTD2;          //!< Digital I/O on PTD2
extern const DigitalIO digitalIO_PTD3;          //!< Digital I/O on PTD3
extern const DigitalIO digitalIO_PTD4;          //!< Digital I/O on PTD4
extern const DigitalIO digitalIO_PTD5;          //!< Digital I/O on PTD5
extern const DigitalIO digitalIO_PTD6;          //!< Digital I/O on PTD6
extern const DigitalIO digitalIO_PTD7;          //!< Digital I/O on PTD7
extern const DigitalIO digitalIO_PTD8;          //!< Digital I/O on PTD8
extern const DigitalIO digitalIO_PTD9;          //!< Digital I/O on PTD9
extern const DigitalIO digitalIO_PTD10;         //!< Digital I/O on PTD10
extern const DigitalIO digitalIO_PTD11;         //!< Digital I/O on PTD11
extern const DigitalIO digitalIO_PTD12;         //!< Digital I/O on PTD12
extern const DigitalIO digitalIO_PTD13;         //!< Digital I/O on PTD13
extern const DigitalIO digitalIO_PTD14;         //!< Digital I/O on PTD14
extern const DigitalIO digitalIO_PTD15;         //!< Digital I/O on PTD15
extern const DigitalIO digitalIO_PTE0;          //!< Digital I/O on PTE0
extern const DigitalIO digitalIO_PTE1;          //!< Digital I/O on PTE1
extern const DigitalIO digitalIO_PTE2;          //!< Digital I/O on PTE2
extern const DigitalIO digitalIO_PTE3;          //!< Digital I/O on PTE3
extern const DigitalIO digitalIO_PTE4;          //!< Digital I/O on PTE4
extern const DigitalIO digitalIO_PTE5;          //!< Digital I/O on PTE5
extern const DigitalIO digitalIO_PTE6;          //!< Digital I/O on PTE6
extern const DigitalIO digitalIO_PTE7;          //!< Digital I/O on PTE7
extern const DigitalIO digitalIO_PTE8;          //!< Digital I/O on PTE8
extern const DigitalIO digitalIO_PTE9;          //!< Digital I/O on PTE9
extern const DigitalIO digitalIO_PTE10;         //!< Digital I/O on PTE10
extern const DigitalIO digitalIO_PTE11;         //!< Digital I/O on PTE11
extern const DigitalIO digitalIO_PTE12;         //!< Digital I/O on PTE12
extern const DigitalIO digitalIO_PTE24;         //!< Digital I/O on PTE24
extern const DigitalIO digitalIO_PTE25;         //!< Digital I/O on PTE25
extern const DigitalIO digitalIO_PTE26;         //!< Digital I/O on PTE26
extern const DigitalIO digitalIO_PTE27;         //!< Digital I/O on PTE27
extern const DigitalIO digitalIO_PTE28;         //!< Digital I/O on PTE28
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const AnalogueIO analogueIO_ADC0_SE16;    //!< ADC0_21 on ADC0_SE16
extern const AnalogueIO analogueIO_ADC0_SE23;    //!< ADC0_23 on ADC0_SE23
extern const AnalogueIO analogueIO_ADC1_SE16;    //!< ADC0_22 on ADC1_SE16
extern const AnalogueIO analogueIO_ADC1_SE18;    //!< ADC1_18 on ADC1_SE18
extern const AnalogueIO analogueIO_ADC1_SE23;    //!< ADC1_23 on ADC1_SE23
extern const AnalogueIO analogueIO_PTA7;         //!< ADC0_10 on PTA7
extern const AnalogueIO analogueIO_PTA8;         //!< ADC0_11 on PTA8
extern const AnalogueIO analogueIO_PTA17;        //!< ADC1_17 on PTA17
extern const AnalogueIO analogueIO_PTB0;         //!< ADC1_8 on PTB0
extern const AnalogueIO analogueIO_PTB1;         //!< ADC1_9 on PTB1
extern const AnalogueIO analogueIO_PTB2;         //!< ADC0_12 on PTB2
extern const AnalogueIO analogueIO_PTB3;         //!< ADC0_13 on PTB3
extern const AnalogueIO analogueIO_PTB4;         //!< ADC1_10 on PTB4
extern const AnalogueIO analogueIO_PTB5;         //!< ADC1_11 on PTB5
extern const AnalogueIO analogueIO_PTB6;         //!< ADC1_12 on PTB6
extern const AnalogueIO analogueIO_PTB7;         //!< ADC1_13 on PTB7
extern const AnalogueIO analogueIO_PTB10;        //!< ADC1_14 on PTB10
extern const AnalogueIO analogueIO_PTB11;        //!< ADC1_15 on PTB11
extern const AnalogueIO analogueIO_PTC0;         //!< ADC0_14 on PTC0
extern const AnalogueIO analogueIO_PTC1;         //!< ADC0_15 on PTC1
extern const AnalogueIO analogueIO_PTC2;         //!< ADC0_4 on PTC2
extern const AnalogueIO analogueIO_PTC8;         //!< ADC1_4 on PTC8
extern const AnalogueIO analogueIO_PTC9;         //!< ADC1_5 on PTC9
extern const AnalogueIO analogueIO_PTC10;        //!< ADC1_6 on PTC10
extern const AnalogueIO analogueIO_PTC11;        //!< ADC1_7 on PTC11
extern const AnalogueIO analogueIO_PTD1;         //!< ADC0_5 on PTD1
extern const AnalogueIO analogueIO_PTD5;         //!< ADC0_6 on PTD5
extern const AnalogueIO analogueIO_PTD6;         //!< ADC0_7 on PTD6
extern const AnalogueIO analogueIO_PTE24;        //!< ADC0_17 on PTE24
extern const AnalogueIO analogueIO_PTE25;        //!< ADC0_18 on PTE25
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
#if FTM0_3_SEL == 1
extern const PwmIO  pwmIO_PTA6;              //!< FTM0_3 on PTA6
#endif
#if FTM0_4_SEL == 1
extern const PwmIO  pwmIO_PTA7;              //!< FTM0_4 on PTA7
#endif
#if FTM1_0_SEL == 1
extern const PwmIO  pwmIO_PTA8;              //!< FTM1_0 on PTA8
#endif
#if FTM1_1_SEL == 1
extern const PwmIO  pwmIO_PTA9;              //!< FTM1_1 on PTA9
#endif
#if FTM2_0_SEL == 1
extern const PwmIO  pwmIO_PTA10;             //!< FTM2_0 on PTA10
#endif
#if FTM2_1_SEL == 1
extern const PwmIO  pwmIO_PTA11;             //!< FTM2_1 on PTA11
#endif
#if FTM1_0_SEL == 2
extern const PwmIO  pwmIO_PTA12;             //!< FTM1_0 on PTA12
#endif
#if FTM1_1_SEL == 2
extern const PwmIO  pwmIO_PTA13;             //!< FTM1_1 on PTA13
#endif
#if FTM1_0_SEL == 3
extern const PwmIO  pwmIO_PTB0;              //!< FTM1_0 on PTB0
#endif
#if FTM1_1_SEL == 3
extern const PwmIO  pwmIO_PTB1;              //!< FTM1_1 on PTB1
#endif
#if FTM1_0_SEL == 4
extern const PwmIO  pwmIO_PTB12;             //!< FTM1_0 on PTB12
#endif
#if FTM0_4_SEL == 2
extern const PwmIO  pwmIO_PTB12;             //!< FTM0_4 on PTB12
#endif
#if FTM1_1_SEL == 4
extern const PwmIO  pwmIO_PTB13;             //!< FTM1_1 on PTB13
#endif
#if FTM0_5_SEL == 2
extern const PwmIO  pwmIO_PTB13;             //!< FTM0_5 on PTB13
#endif
#if FTM2_0_SEL == 2
extern const PwmIO  pwmIO_PTB18;             //!< FTM2_0 on PTB18
#endif
#if FTM2_1_SEL == 2
extern const PwmIO  pwmIO_PTB19;             //!< FTM2_1 on PTB19
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
#if FTM0_3_SEL == 2
extern const PwmIO  pwmIO_PTC4;              //!< FTM0_3 on PTC4
#endif
#if FTM0_2_SEL == 3
extern const PwmIO  pwmIO_PTC5;              //!< FTM0_2 on PTC5
#endif
#if FTM3_4_SEL == 1
extern const PwmIO  pwmIO_PTC8;              //!< FTM3_4 on PTC8
#endif
#if FTM3_5_SEL == 1
extern const PwmIO  pwmIO_PTC9;              //!< FTM3_5 on PTC9
#endif
#if FTM3_6_SEL == 1
extern const PwmIO  pwmIO_PTC10;             //!< FTM3_6 on PTC10
#endif
#if FTM3_7_SEL == 1
extern const PwmIO  pwmIO_PTC11;             //!< FTM3_7 on PTC11
#endif
#if FTM3_0_SEL == 1
extern const PwmIO  pwmIO_PTD0;              //!< FTM3_0 on PTD0
#endif
#if FTM3_1_SEL == 1
extern const PwmIO  pwmIO_PTD1;              //!< FTM3_1 on PTD1
#endif
#if FTM3_2_SEL == 1
extern const PwmIO  pwmIO_PTD2;              //!< FTM3_2 on PTD2
#endif
#if FTM3_3_SEL == 1
extern const PwmIO  pwmIO_PTD3;              //!< FTM3_3 on PTD3
#endif
#if FTM0_4_SEL == 3
extern const PwmIO  pwmIO_PTD4;              //!< FTM0_4 on PTD4
#endif
#if FTM0_5_SEL == 3
extern const PwmIO  pwmIO_PTD5;              //!< FTM0_5 on PTD5
#endif
#if FTM0_6_SEL == 2
extern const PwmIO  pwmIO_PTD6;              //!< FTM0_6 on PTD6
#endif
#if FTM0_7_SEL == 2
extern const PwmIO  pwmIO_PTD7;              //!< FTM0_7 on PTD7
#endif
#if FTM3_0_SEL == 2
extern const PwmIO  pwmIO_PTE5;              //!< FTM3_0 on PTE5
#endif
#if FTM3_1_SEL == 2
extern const PwmIO  pwmIO_PTE6;              //!< FTM3_1 on PTE6
#endif
#if FTM3_2_SEL == 2
extern const PwmIO  pwmIO_PTE7;              //!< FTM3_2 on PTE7
#endif
#if FTM3_3_SEL == 2
extern const PwmIO  pwmIO_PTE8;              //!< FTM3_3 on PTE8
#endif
#if FTM3_4_SEL == 2
extern const PwmIO  pwmIO_PTE9;              //!< FTM3_4 on PTE9
#endif
#if FTM3_5_SEL == 2
extern const PwmIO  pwmIO_PTE10;             //!< FTM3_5 on PTE10
#endif
#if FTM3_6_SEL == 2
extern const PwmIO  pwmIO_PTE11;             //!< FTM3_6 on PTE11
#endif
#if FTM3_7_SEL == 2
extern const PwmIO  pwmIO_PTE12;             //!< FTM3_7 on PTE12
#endif
/**
 * @}
 */
/**
* @addtogroup alias_pin_mappings_GROUP Aliases for pins
* @brief Aliases for port pins for example Arduino based names
* @{
*/
#define digitalIO_A0         digitalIO_PTB2       //!< alias A0=>PTB2
#define digitalIO_A1         digitalIO_PTB3       //!< alias A1=>PTB3
#define digitalIO_A2         digitalIO_PTB10      //!< alias A2=>PTB10
#define digitalIO_A3         digitalIO_PTB11      //!< alias A3=>PTB11
#define digitalIO_A4         digitalIO_PTC11      //!< alias A4=>PTC11
#define digitalIO_A5         digitalIO_PTC10      //!< alias A5=>PTC10
#define digitalIO_D0         digitalIO_PTC16      //!< alias D0=>PTC16
#define digitalIO_D1         digitalIO_PTC17      //!< alias D1=>PTC17
#define digitalIO_D2         digitalIO_PTB9       //!< alias D2=>PTB9
#define digitalIO_D3         digitalIO_PTA1       //!< alias D3=>PTA1
#define digitalIO_D4         digitalIO_PTB23      //!< alias D4=>PTB23
#define digitalIO_D5         digitalIO_PTA2       //!< alias D5=>PTA2
#define digitalIO_D6         digitalIO_PTC2       //!< alias D6=>PTC2
#define digitalIO_D7         digitalIO_PTC3       //!< alias D7=>PTC3
#define digitalIO_D8         digitalIO_PTA0       //!< alias D8=>PTA0
#define digitalIO_D9         digitalIO_PTC4       //!< alias D9=>PTC4
#define digitalIO_D10        digitalIO_PTD0       //!< alias D10=>PTD0
#define digitalIO_D11        digitalIO_PTD2       //!< alias D11=>PTD2
#define digitalIO_D12        digitalIO_PTD3       //!< alias D12=>PTD3
#define digitalIO_D13        digitalIO_PTD1       //!< alias D13=>PTD1
#define digitalIO_D14        digitalIO_PTE25      //!< alias D14=>PTE25
#define digitalIO_D15        digitalIO_PTE24      //!< alias D15=>PTE24
#define digitalIO_nRF24L01_cs digitalIO_PTD4       //!< alias nRF24L01_cs=>PTD4
#define digitalIO_nRF24L01_miso digitalIO_PTD7       //!< alias nRF24L01_miso=>PTD7
#define digitalIO_nRF24L01_mosi digitalIO_PTD6       //!< alias nRF24L01_mosi=>PTD6
#define digitalIO_nRF24L01_sck digitalIO_PTD5       //!< alias nRF24L01_sck=>PTD5
#define analogueIO_A0        analogueIO_PTB2      //!< alias A0=>PTB2
#define analogueIO_A1        analogueIO_PTB3      //!< alias A1=>PTB3
#define analogueIO_A2        analogueIO_PTB10     //!< alias A2=>PTB10
#define analogueIO_A3        analogueIO_PTB11     //!< alias A3=>PTB11
#define analogueIO_A4        analogueIO_PTC11     //!< alias A4=>PTC11
#define analogueIO_A5        analogueIO_PTC10     //!< alias A5=>PTC10
#define analogueIO_D6        analogueIO_PTC2      //!< alias D6=>PTC2
#define analogueIO_D13       analogueIO_PTD1      //!< alias D13=>PTD1
#define analogueIO_D14       analogueIO_PTE25     //!< alias D14=>PTE25
#define analogueIO_D15       analogueIO_PTE24     //!< alias D15=>PTE24
#define analogueIO_nRF24L01_mosi analogueIO_PTD6      //!< alias nRF24L01_mosi=>PTD6
#define analogueIO_nRF24L01_sck analogueIO_PTD5      //!< alias nRF24L01_sck=>PTD5
#define pwmIO_A4             pwmIO_PTC11          //!< alias A4=>PTC11
#define pwmIO_A5             pwmIO_PTC10          //!< alias A5=>PTC10
#define pwmIO_D3             pwmIO_PTA1           //!< alias D3=>PTA1
#define pwmIO_D5             pwmIO_PTA2           //!< alias D5=>PTA2
#define pwmIO_D6             pwmIO_PTC2           //!< alias D6=>PTC2
#define pwmIO_D7             pwmIO_PTC3           //!< alias D7=>PTC3
#define pwmIO_D8             pwmIO_PTA0           //!< alias D8=>PTA0
#define pwmIO_D9             pwmIO_PTC4           //!< alias D9=>PTC4
#define pwmIO_D10            pwmIO_PTD0           //!< alias D10=>PTD0
#define pwmIO_D11            pwmIO_PTD2           //!< alias D11=>PTD2
#define pwmIO_D12            pwmIO_PTD3           //!< alias D12=>PTD3
#define pwmIO_D13            pwmIO_PTD1           //!< alias D13=>PTD1
#define pwmIO_nRF24L01_cs    pwmIO_PTD4           //!< alias nRF24L01_cs=>PTD4
#define pwmIO_nRF24L01_miso  pwmIO_PTD7           //!< alias nRF24L01_miso=>PTD7
#define pwmIO_nRF24L01_mosi  pwmIO_PTD6           //!< alias nRF24L01_mosi=>PTD6
#define pwmIO_nRF24L01_sck   pwmIO_PTD5           //!< alias nRF24L01_sck=>PTD5
/**
 * @}
 */
/*
ADC0_10=PTA7=[Disabled, PTA7]
ADC0_11=PTA8=[Disabled, PTA8]
ADC0_12=PTB2=[Disabled, PTB2]
ADC0_13=PTB3=[Disabled, PTB3]
ADC0_14=PTC0=[Disabled, PTC0]
ADC0_15=PTC1=[Disabled, PTC1]
ADC0_17=PTE24=[Disabled, PTE24]
ADC0_18=PTE25=[Disabled, PTE25]
ADC0_21=ADC0_SE16=[Disabled, ADC0_SE16]
ADC0_22=ADC1_SE16=[Disabled, ADC1_SE16]
ADC0_23=ADC0_SE23=[Disabled, ADC0_SE23]
ADC0_4=PTC2=[Disabled, PTC2]
ADC0_5=PTD1=[Disabled, PTD1]
ADC0_6=PTD5=[Disabled, PTD5]
ADC0_7=PTD6=[Disabled, PTD6]
ADC1_10=PTB4=[Disabled, PTB4]
ADC1_11=PTB5=[Disabled, PTB5]
ADC1_12=PTB6=[Disabled, PTB6]
ADC1_13=PTB7=[Disabled, PTB7]
ADC1_14=PTB10=[Disabled, PTB10]
ADC1_15=PTB11=[Disabled, PTB11]
ADC1_17=PTA17=[Disabled, PTA17]
ADC1_18=ADC1_SE18=[Disabled, ADC1_SE18]
ADC1_23=ADC1_SE23=[Disabled, ADC1_SE23]
ADC1_4=PTC8=[Disabled, PTC8]
ADC1_5=PTC9=[Disabled, PTC9]
ADC1_6=PTC10=[Disabled, PTC10]
ADC1_7=PTC11=[Disabled, PTC11]
ADC1_8=PTB0=[Disabled, PTB0]
ADC1_9=PTB1=[Disabled, PTB1]
FTM0_0=PTC1=[Disabled, PTA3, PTC1]
FTM0_1=PTC2=[Disabled, PTA4, PTC2]
FTM0_2=PTC3=[Disabled, PTA5, PTC3, PTC5]
FTM0_3=PTC4=[Disabled, PTA6, PTC4]
FTM0_4=PTA7=[Disabled, PTA7, PTB12, PTD4]
FTM0_5=PTA0=[Disabled, PTA0, PTB13, PTD5]
FTM0_6=PTA1=[Disabled, PTA1, PTD6]
FTM0_7=PTA2=[Disabled, PTA2, PTD7]
FTM1_0=PTA8=[Disabled, PTA8, PTA12, PTB0, PTB12]
FTM1_1=PTA9=[Disabled, PTA9, PTA13, PTB1, PTB13]
FTM2_0=PTA10=[Disabled, PTA10, PTB18]
FTM2_1=PTA11=[Disabled, PTA11, PTB19]
FTM3_0=PTD0=[Disabled, PTD0, PTE5]
FTM3_1=PTD1=[Disabled, PTD1, PTE6]
FTM3_2=PTD2=[Disabled, PTD2, PTE7]
FTM3_3=PTD3=[Disabled, PTD3, PTE8]
FTM3_4=PTC8=[Disabled, PTC8, PTE9]
FTM3_5=PTC9=[Disabled, PTC9, PTE10]
FTM3_6=PTC10=[Disabled, PTC10, PTE11]
FTM3_7=PTC11=[Disabled, PTC11, PTE12]
I2C0_SCL=PTE24=[Disabled, PTB0, PTB2, PTD2, PTD8, PTE24]
I2C0_SDA=PTE25=[Disabled, PTB1, PTB3, PTD3, PTD9, PTE25]
I2C1_SCL=PTC10=[Disabled, PTC10, PTE1]
I2C1_SDA=PTC11=[Disabled, PTC11, PTE0]
I2C2_SCL=PTA12=[Disabled, PTA12, PTA14]
I2C2_SDA=PTA11=[Disabled, PTA11, PTA13]
SPI0_PCS0=Disabled=[Disabled, PTA14, PTC4, PTD0]
SPI0_PCS1=Disabled=[Disabled, PTC3, PTD4]
SPI0_PCS2=Disabled=[Disabled, PTC2, PTD5]
SPI0_PCS3=Disabled=[Disabled, PTC1, PTD6]
SPI0_PCS4=Disabled=[Disabled, PTC0]
SPI0_PCS5=Disabled=[Disabled, PTB23]
SPI0_SCK=PTD1=[Disabled, PTA15, PTC5, PTD1]
SPI0_SIN=PTD3=[Disabled, PTA17, PTC7, PTD3]
SPI0_SOUT=PTD2=[Disabled, PTA16, PTC6, PTD2]
SPI1_PCS0=PTD4=[Disabled, PTB10, PTD4, PTE4]
SPI1_PCS1=Disabled=[Disabled, PTB9, PTE0]
SPI1_PCS2=Disabled=[Disabled, PTE5]
SPI1_PCS3=Disabled=[Disabled, PTE6]
SPI1_SCK=PTD5=[Disabled, PTB11, PTD5, PTE2]
SPI1_SIN=PTD7=[Disabled, PTB17, PTD7, PTE1, PTE3]
SPI1_SOUT=PTD6=[Disabled, PTB16, PTD6, PTE1, PTE3]
SPI2_PCS0=Disabled=[Disabled, PTB20, PTD11]
SPI2_PCS1=Disabled=[Disabled, PTD15]
SPI2_SCK=PTB21=[Disabled, PTB21, PTD12]
SPI2_SIN=PTB23=[Disabled, PTB23, PTD14]
SPI2_SOUT=PTB22=[Disabled, PTB22, PTD13]

ADC0=SIM->SCGC6=SIM_SCGC6_ADC0_MASK
ADC1=SIM->SCGC3=SIM_SCGC3_ADC1_MASK
SDHC0=SIM->SCGC3=SIM_SCGC3_SDHC0_MASK
I2C0=SIM->SCGC4=SIM_SCGC4_I2C0_MASK
I2C1=SIM->SCGC4=SIM_SCGC4_I2C1_MASK
I2C2=SIM->SCGC1=SIM_SCGC1_I2C2_MASK
SPI0=SIM->SCGC6=SIM_SCGC6_SPI0_MASK
SPI1=SIM->SCGC6=SIM_SCGC6_SPI1_MASK
SPI2=SIM->SCGC3=SIM_SCGC3_SPI2_MASK
FTM0=SIM->SCGC6=SIM_SCGC6_FTM0_MASK
FTM1=SIM->SCGC6=SIM_SCGC6_FTM1_MASK
FTM2=SIM->SCGC3=SIM_SCGC3_FTM2_MASK
FTM3=SIM->SCGC3=SIM_SCGC3_FTM3_MASK
*/

#endif /* GPIO_H_ */
