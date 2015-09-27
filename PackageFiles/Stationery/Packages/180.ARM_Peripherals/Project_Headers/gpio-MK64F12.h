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
extern const DigitalIO digitalIO_PTA0;          //!< DigitalIO on PTA0
extern const DigitalIO digitalIO_PTA1;          //!< DigitalIO on PTA1
extern const DigitalIO digitalIO_PTA2;          //!< DigitalIO on PTA2
extern const DigitalIO digitalIO_PTA3;          //!< DigitalIO on PTA3
extern const DigitalIO digitalIO_PTA4;          //!< DigitalIO on PTA4
extern const DigitalIO digitalIO_PTA5;          //!< DigitalIO on PTA5
extern const DigitalIO digitalIO_PTA6;          //!< DigitalIO on PTA6
extern const DigitalIO digitalIO_PTA7;          //!< DigitalIO on PTA7
extern const DigitalIO digitalIO_PTA8;          //!< DigitalIO on PTA8
extern const DigitalIO digitalIO_PTA9;          //!< DigitalIO on PTA9
extern const DigitalIO digitalIO_PTA10;         //!< DigitalIO on PTA10
extern const DigitalIO digitalIO_PTA11;         //!< DigitalIO on PTA11
extern const DigitalIO digitalIO_PTA12;         //!< DigitalIO on PTA12
extern const DigitalIO digitalIO_PTA13;         //!< DigitalIO on PTA13
extern const DigitalIO digitalIO_PTA14;         //!< DigitalIO on PTA14
extern const DigitalIO digitalIO_PTA15;         //!< DigitalIO on PTA15
extern const DigitalIO digitalIO_PTA16;         //!< DigitalIO on PTA16
extern const DigitalIO digitalIO_PTA17;         //!< DigitalIO on PTA17
extern const DigitalIO digitalIO_PTA18;         //!< DigitalIO on PTA18
extern const DigitalIO digitalIO_PTA19;         //!< DigitalIO on PTA19
extern const DigitalIO digitalIO_PTA24;         //!< DigitalIO on PTA24
extern const DigitalIO digitalIO_PTA25;         //!< DigitalIO on PTA25
extern const DigitalIO digitalIO_PTA26;         //!< DigitalIO on PTA26
extern const DigitalIO digitalIO_PTA27;         //!< DigitalIO on PTA27
extern const DigitalIO digitalIO_PTA28;         //!< DigitalIO on PTA28
extern const DigitalIO digitalIO_PTA29;         //!< DigitalIO on PTA29
extern const DigitalIO digitalIO_PTB0;          //!< DigitalIO on PTB0
extern const DigitalIO digitalIO_PTB1;          //!< DigitalIO on PTB1
extern const DigitalIO digitalIO_PTB2;          //!< DigitalIO on PTB2
extern const DigitalIO digitalIO_PTB3;          //!< DigitalIO on PTB3
extern const DigitalIO digitalIO_PTB4;          //!< DigitalIO on PTB4
extern const DigitalIO digitalIO_PTB5;          //!< DigitalIO on PTB5
extern const DigitalIO digitalIO_PTB6;          //!< DigitalIO on PTB6
extern const DigitalIO digitalIO_PTB7;          //!< DigitalIO on PTB7
extern const DigitalIO digitalIO_PTB8;          //!< DigitalIO on PTB8
extern const DigitalIO digitalIO_PTB9;          //!< DigitalIO on PTB9
extern const DigitalIO digitalIO_PTB10;         //!< DigitalIO on PTB10
extern const DigitalIO digitalIO_PTB11;         //!< DigitalIO on PTB11
extern const DigitalIO digitalIO_PTB12;         //!< DigitalIO on PTB12
extern const DigitalIO digitalIO_PTB13;         //!< DigitalIO on PTB13
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
extern const DigitalIO digitalIO_PTC14;         //!< DigitalIO on PTC14
extern const DigitalIO digitalIO_PTC15;         //!< DigitalIO on PTC15
extern const DigitalIO digitalIO_PTC16;         //!< DigitalIO on PTC16
extern const DigitalIO digitalIO_PTC17;         //!< DigitalIO on PTC17
extern const DigitalIO digitalIO_PTC18;         //!< DigitalIO on PTC18
extern const DigitalIO digitalIO_PTC19;         //!< DigitalIO on PTC19
extern const DigitalIO digitalIO_PTD0;          //!< DigitalIO on PTD0
extern const DigitalIO digitalIO_PTD1;          //!< DigitalIO on PTD1
extern const DigitalIO digitalIO_PTD2;          //!< DigitalIO on PTD2
extern const DigitalIO digitalIO_PTD3;          //!< DigitalIO on PTD3
extern const DigitalIO digitalIO_PTD4;          //!< DigitalIO on PTD4
extern const DigitalIO digitalIO_PTD5;          //!< DigitalIO on PTD5
extern const DigitalIO digitalIO_PTD6;          //!< DigitalIO on PTD6
extern const DigitalIO digitalIO_PTD7;          //!< DigitalIO on PTD7
extern const DigitalIO digitalIO_PTD8;          //!< DigitalIO on PTD8
extern const DigitalIO digitalIO_PTD9;          //!< DigitalIO on PTD9
extern const DigitalIO digitalIO_PTD10;         //!< DigitalIO on PTD10
extern const DigitalIO digitalIO_PTD11;         //!< DigitalIO on PTD11
extern const DigitalIO digitalIO_PTD12;         //!< DigitalIO on PTD12
extern const DigitalIO digitalIO_PTD13;         //!< DigitalIO on PTD13
extern const DigitalIO digitalIO_PTD14;         //!< DigitalIO on PTD14
extern const DigitalIO digitalIO_PTD15;         //!< DigitalIO on PTD15
extern const DigitalIO digitalIO_PTE0;          //!< DigitalIO on PTE0
extern const DigitalIO digitalIO_PTE1;          //!< DigitalIO on PTE1
extern const DigitalIO digitalIO_PTE2;          //!< DigitalIO on PTE2
extern const DigitalIO digitalIO_PTE3;          //!< DigitalIO on PTE3
extern const DigitalIO digitalIO_PTE4;          //!< DigitalIO on PTE4
extern const DigitalIO digitalIO_PTE5;          //!< DigitalIO on PTE5
extern const DigitalIO digitalIO_PTE6;          //!< DigitalIO on PTE6
extern const DigitalIO digitalIO_PTE7;          //!< DigitalIO on PTE7
extern const DigitalIO digitalIO_PTE8;          //!< DigitalIO on PTE8
extern const DigitalIO digitalIO_PTE9;          //!< DigitalIO on PTE9
extern const DigitalIO digitalIO_PTE10;         //!< DigitalIO on PTE10
extern const DigitalIO digitalIO_PTE11;         //!< DigitalIO on PTE11
extern const DigitalIO digitalIO_PTE12;         //!< DigitalIO on PTE12
extern const DigitalIO digitalIO_PTE24;         //!< DigitalIO on PTE24
extern const DigitalIO digitalIO_PTE25;         //!< DigitalIO on PTE25
extern const DigitalIO digitalIO_PTE26;         //!< DigitalIO on PTE26
extern const DigitalIO digitalIO_PTE27;         //!< DigitalIO on PTE27
extern const DigitalIO digitalIO_PTE28;         //!< DigitalIO on PTE28
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if ADC0_21_SEL == 1
extern const AnalogueIO analogueIO_ADC0_SE16;    //!< AnalogueIO on ADC0_SE16
#endif
#if ADC0_23_SEL == 1
extern const AnalogueIO analogueIO_ADC0_SE23;    //!< AnalogueIO on ADC0_SE23
#endif
#if ADC0_22_SEL == 1
extern const AnalogueIO analogueIO_ADC1_SE16;    //!< AnalogueIO on ADC1_SE16
#endif
#if ADC1_18_SEL == 1
extern const AnalogueIO analogueIO_ADC1_SE18;    //!< AnalogueIO on ADC1_SE18
#endif
#if ADC1_23_SEL == 1
extern const AnalogueIO analogueIO_ADC1_SE23;    //!< AnalogueIO on ADC1_SE23
#endif
#if ADC0_10_SEL == 1
extern const AnalogueIO analogueIO_PTA7;         //!< AnalogueIO on PTA7
#endif
#if ADC0_11_SEL == 1
extern const AnalogueIO analogueIO_PTA8;         //!< AnalogueIO on PTA8
#endif
#if ADC1_17_SEL == 1
extern const AnalogueIO analogueIO_PTA17;        //!< AnalogueIO on PTA17
#endif
#if ADC1_8_SEL == 1
extern const AnalogueIO analogueIO_PTB0;         //!< AnalogueIO on PTB0
#endif
#if ADC1_9_SEL == 1
extern const AnalogueIO analogueIO_PTB1;         //!< AnalogueIO on PTB1
#endif
#if ADC0_12_SEL == 1
extern const AnalogueIO analogueIO_PTB2;         //!< AnalogueIO on PTB2
#endif
#if ADC0_13_SEL == 1
extern const AnalogueIO analogueIO_PTB3;         //!< AnalogueIO on PTB3
#endif
#if ADC1_10_SEL == 1
extern const AnalogueIO analogueIO_PTB4;         //!< AnalogueIO on PTB4
#endif
#if ADC1_11_SEL == 1
extern const AnalogueIO analogueIO_PTB5;         //!< AnalogueIO on PTB5
#endif
#if ADC1_12_SEL == 1
extern const AnalogueIO analogueIO_PTB6;         //!< AnalogueIO on PTB6
#endif
#if ADC1_13_SEL == 1
extern const AnalogueIO analogueIO_PTB7;         //!< AnalogueIO on PTB7
#endif
#if ADC1_14_SEL == 1
extern const AnalogueIO analogueIO_PTB10;        //!< AnalogueIO on PTB10
#endif
#if ADC1_15_SEL == 1
extern const AnalogueIO analogueIO_PTB11;        //!< AnalogueIO on PTB11
#endif
#if ADC0_14_SEL == 1
extern const AnalogueIO analogueIO_PTC0;         //!< AnalogueIO on PTC0
#endif
#if ADC0_15_SEL == 1
extern const AnalogueIO analogueIO_PTC1;         //!< AnalogueIO on PTC1
#endif
#if ADC0_4_SEL == 1
extern const AnalogueIO analogueIO_PTC2;         //!< AnalogueIO on PTC2
#endif
#if ADC1_4_SEL == 1
extern const AnalogueIO analogueIO_PTC8;         //!< AnalogueIO on PTC8
#endif
#if ADC1_5_SEL == 1
extern const AnalogueIO analogueIO_PTC9;         //!< AnalogueIO on PTC9
#endif
#if ADC1_6_SEL == 1
extern const AnalogueIO analogueIO_PTC10;        //!< AnalogueIO on PTC10
#endif
#if ADC1_7_SEL == 1
extern const AnalogueIO analogueIO_PTC11;        //!< AnalogueIO on PTC11
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
#if ADC0_17_SEL == 1
extern const AnalogueIO analogueIO_PTE24;        //!< AnalogueIO on PTE24
#endif
#if ADC0_18_SEL == 1
extern const AnalogueIO analogueIO_PTE25;        //!< AnalogueIO on PTE25
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if FTM0_5_SEL == 1
extern const PwmIO  pwmIO_PTA0;              //!< PwmIO on PTA0
#endif
#if FTM0_6_SEL == 1
extern const PwmIO  pwmIO_PTA1;              //!< PwmIO on PTA1
#endif
#if FTM0_7_SEL == 1
extern const PwmIO  pwmIO_PTA2;              //!< PwmIO on PTA2
#endif
#if FTM0_0_SEL == 1
extern const PwmIO  pwmIO_PTA3;              //!< PwmIO on PTA3
#endif
#if FTM0_1_SEL == 1
extern const PwmIO  pwmIO_PTA4;              //!< PwmIO on PTA4
#endif
#if FTM0_2_SEL == 1
extern const PwmIO  pwmIO_PTA5;              //!< PwmIO on PTA5
#endif
#if FTM0_3_SEL == 1
extern const PwmIO  pwmIO_PTA6;              //!< PwmIO on PTA6
#endif
#if FTM0_4_SEL == 1
extern const PwmIO  pwmIO_PTA7;              //!< PwmIO on PTA7
#endif
#if FTM1_0_SEL == 1
extern const PwmIO  pwmIO_PTA8;              //!< PwmIO on PTA8
#endif
#if FTM1_1_SEL == 1
extern const PwmIO  pwmIO_PTA9;              //!< PwmIO on PTA9
#endif
#if FTM2_0_SEL == 1
extern const PwmIO  pwmIO_PTA10;             //!< PwmIO on PTA10
#endif
#if FTM2_1_SEL == 1
extern const PwmIO  pwmIO_PTA11;             //!< PwmIO on PTA11
#endif
#if FTM1_0_SEL == 2
extern const PwmIO  pwmIO_PTA12;             //!< PwmIO on PTA12
#endif
#if FTM1_1_SEL == 2
extern const PwmIO  pwmIO_PTA13;             //!< PwmIO on PTA13
#endif
#if FTM1_0_SEL == 3
extern const PwmIO  pwmIO_PTB0;              //!< PwmIO on PTB0
#endif
#if FTM1_1_SEL == 3
extern const PwmIO  pwmIO_PTB1;              //!< PwmIO on PTB1
#endif
#if FTM1_0_SEL == 4
extern const PwmIO  pwmIO_PTB12;             //!< PwmIO on PTB12
#endif
#if FTM0_4_SEL == 2
extern const PwmIO  pwmIO_PTB12;             //!< PwmIO on PTB12
#endif
#if FTM1_1_SEL == 4
extern const PwmIO  pwmIO_PTB13;             //!< PwmIO on PTB13
#endif
#if FTM0_5_SEL == 2
extern const PwmIO  pwmIO_PTB13;             //!< PwmIO on PTB13
#endif
#if FTM2_0_SEL == 2
extern const PwmIO  pwmIO_PTB18;             //!< PwmIO on PTB18
#endif
#if FTM2_1_SEL == 2
extern const PwmIO  pwmIO_PTB19;             //!< PwmIO on PTB19
#endif
#if FTM0_0_SEL == 2
extern const PwmIO  pwmIO_PTC1;              //!< PwmIO on PTC1
#endif
#if FTM0_1_SEL == 2
extern const PwmIO  pwmIO_PTC2;              //!< PwmIO on PTC2
#endif
#if FTM0_2_SEL == 2
extern const PwmIO  pwmIO_PTC3;              //!< PwmIO on PTC3
#endif
#if FTM0_3_SEL == 2
extern const PwmIO  pwmIO_PTC4;              //!< PwmIO on PTC4
#endif
#if FTM0_2_SEL == 3
extern const PwmIO  pwmIO_PTC5;              //!< PwmIO on PTC5
#endif
#if FTM3_4_SEL == 1
extern const PwmIO  pwmIO_PTC8;              //!< PwmIO on PTC8
#endif
#if FTM3_5_SEL == 1
extern const PwmIO  pwmIO_PTC9;              //!< PwmIO on PTC9
#endif
#if FTM3_6_SEL == 1
extern const PwmIO  pwmIO_PTC10;             //!< PwmIO on PTC10
#endif
#if FTM3_7_SEL == 1
extern const PwmIO  pwmIO_PTC11;             //!< PwmIO on PTC11
#endif
#if FTM3_0_SEL == 1
extern const PwmIO  pwmIO_PTD0;              //!< PwmIO on PTD0
#endif
#if FTM3_1_SEL == 1
extern const PwmIO  pwmIO_PTD1;              //!< PwmIO on PTD1
#endif
#if FTM3_2_SEL == 1
extern const PwmIO  pwmIO_PTD2;              //!< PwmIO on PTD2
#endif
#if FTM3_3_SEL == 1
extern const PwmIO  pwmIO_PTD3;              //!< PwmIO on PTD3
#endif
#if FTM0_4_SEL == 3
extern const PwmIO  pwmIO_PTD4;              //!< PwmIO on PTD4
#endif
#if FTM0_5_SEL == 3
extern const PwmIO  pwmIO_PTD5;              //!< PwmIO on PTD5
#endif
#if FTM0_6_SEL == 2
extern const PwmIO  pwmIO_PTD6;              //!< PwmIO on PTD6
#endif
#if FTM0_7_SEL == 2
extern const PwmIO  pwmIO_PTD7;              //!< PwmIO on PTD7
#endif
#if FTM3_0_SEL == 2
extern const PwmIO  pwmIO_PTE5;              //!< PwmIO on PTE5
#endif
#if FTM3_1_SEL == 2
extern const PwmIO  pwmIO_PTE6;              //!< PwmIO on PTE6
#endif
#if FTM3_2_SEL == 2
extern const PwmIO  pwmIO_PTE7;              //!< PwmIO on PTE7
#endif
#if FTM3_3_SEL == 2
extern const PwmIO  pwmIO_PTE8;              //!< PwmIO on PTE8
#endif
#if FTM3_4_SEL == 2
extern const PwmIO  pwmIO_PTE9;              //!< PwmIO on PTE9
#endif
#if FTM3_5_SEL == 2
extern const PwmIO  pwmIO_PTE10;             //!< PwmIO on PTE10
#endif
#if FTM3_6_SEL == 2
extern const PwmIO  pwmIO_PTE11;             //!< PwmIO on PTE11
#endif
#if FTM3_7_SEL == 2
extern const PwmIO  pwmIO_PTE12;             //!< PwmIO on PTE12
#endif
/**
 * @}
 */
/**
* @addtogroup alias_pin_mappings_GROUP Aliases for pins
* @brief Aliases for port pins for example Arduino based names
* @{
*/
#define digitalIO_A0              digitalIO_PTB2       //!< alias A0=>PTB2
#define digitalIO_A1              digitalIO_PTB3       //!< alias A1=>PTB3
#define digitalIO_A2              digitalIO_PTB10      //!< alias A2=>PTB10
#define digitalIO_A3              digitalIO_PTB11      //!< alias A3=>PTB11
#define digitalIO_A4              digitalIO_PTC11      //!< alias A4=>PTC11
#define digitalIO_A5              digitalIO_PTC10      //!< alias A5=>PTC10
#define digitalIO_D0              digitalIO_PTC16      //!< alias D0=>PTC16
#define digitalIO_D1              digitalIO_PTC17      //!< alias D1=>PTC17
#define digitalIO_D2              digitalIO_PTB9       //!< alias D2=>PTB9
#define digitalIO_D3              digitalIO_PTA1       //!< alias D3=>PTA1
#define digitalIO_D4              digitalIO_PTB23      //!< alias D4=>PTB23
#define digitalIO_D5              digitalIO_PTA2       //!< alias D5=>PTA2
#define digitalIO_D6              digitalIO_PTC2       //!< alias D6=>PTC2
#define digitalIO_D7              digitalIO_PTC3       //!< alias D7=>PTC3
#define digitalIO_D8              digitalIO_PTA0       //!< alias D8=>PTA0
#define digitalIO_D9              digitalIO_PTC4       //!< alias D9=>PTC4
#define digitalIO_D10             digitalIO_PTD0       //!< alias D10=>PTD0
#define digitalIO_D11             digitalIO_PTD2       //!< alias D11=>PTD2
#define digitalIO_D12             digitalIO_PTD3       //!< alias D12=>PTD3
#define digitalIO_D13             digitalIO_PTD1       //!< alias D13=>PTD1
#define digitalIO_D14             digitalIO_PTE25      //!< alias D14=>PTE25
#define digitalIO_D15             digitalIO_PTE24      //!< alias D15=>PTE24
#define digitalIO_nRF24L01_miso   digitalIO_PTD7       //!< alias nRF24L01_miso=>PTD7
#define digitalIO_nRF24L01_mosi   digitalIO_PTD6       //!< alias nRF24L01_mosi=>PTD6
#define digitalIO_nRF24L01_sck    digitalIO_PTD5       //!< alias nRF24L01_sck=>PTD5
#define digitalIO_nRF24L01_cs     digitalIO_PTD4       //!< alias nRF24L01_cs=>PTD4
#define analogueIO_A0             analogueIO_PTB2      //!< alias A0=>PTB2
#define analogueIO_A1             analogueIO_PTB3      //!< alias A1=>PTB3
#define analogueIO_A2             analogueIO_PTB10     //!< alias A2=>PTB10
#define analogueIO_A3             analogueIO_PTB11     //!< alias A3=>PTB11
#define analogueIO_A4             analogueIO_PTC11     //!< alias A4=>PTC11
#define analogueIO_A5             analogueIO_PTC10     //!< alias A5=>PTC10
#define analogueIO_D6             analogueIO_PTC2      //!< alias D6=>PTC2
#define analogueIO_D13            analogueIO_PTD1      //!< alias D13=>PTD1
#define analogueIO_D14            analogueIO_PTE25     //!< alias D14=>PTE25
#define analogueIO_D15            analogueIO_PTE24     //!< alias D15=>PTE24
#define analogueIO_nRF24L01_mosi  analogueIO_PTD6      //!< alias nRF24L01_mosi=>PTD6
#define analogueIO_nRF24L01_sck   analogueIO_PTD5      //!< alias nRF24L01_sck=>PTD5
#define pwmIO_A4                  pwmIO_PTC11          //!< alias A4=>PTC11
#define pwmIO_A5                  pwmIO_PTC10          //!< alias A5=>PTC10
#define pwmIO_D3                  pwmIO_PTA1           //!< alias D3=>PTA1
#define pwmIO_D5                  pwmIO_PTA2           //!< alias D5=>PTA2
#define pwmIO_D6                  pwmIO_PTC2           //!< alias D6=>PTC2
#define pwmIO_D7                  pwmIO_PTC3           //!< alias D7=>PTC3
#define pwmIO_D8                  pwmIO_PTA0           //!< alias D8=>PTA0
#define pwmIO_D9                  pwmIO_PTC4           //!< alias D9=>PTC4
#define pwmIO_D10                 pwmIO_PTD0           //!< alias D10=>PTD0
#define pwmIO_D11                 pwmIO_PTD2           //!< alias D11=>PTD2
#define pwmIO_D12                 pwmIO_PTD3           //!< alias D12=>PTD3
#define pwmIO_D13                 pwmIO_PTD1           //!< alias D13=>PTD1
#define pwmIO_nRF24L01_miso       pwmIO_PTD7           //!< alias nRF24L01_miso=>PTD7
#define pwmIO_nRF24L01_mosi       pwmIO_PTD6           //!< alias nRF24L01_mosi=>PTD6
#define pwmIO_nRF24L01_sck        pwmIO_PTD5           //!< alias nRF24L01_sck=>PTD5
#define pwmIO_nRF24L01_cs         pwmIO_PTD4           //!< alias nRF24L01_cs=>PTD4
/**
 * @}
 */
/*
ADC0_4=PTC2=[Disabled, PTC2]
ADC0_5=PTD1=[Disabled, PTD1]
ADC0_6=PTD5=[Disabled, PTD5]
ADC0_7=PTD6=[Disabled, PTD6]
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
ADC1_4=PTC8=[Disabled, PTC8]
ADC1_5=PTC9=[Disabled, PTC9]
ADC1_6=PTC10=[Disabled, PTC10]
ADC1_7=PTC11=[Disabled, PTC11]
ADC1_8=PTB0=[Disabled, PTB0]
ADC1_9=PTB1=[Disabled, PTB1]
ADC1_10=PTB4=[Disabled, PTB4]
ADC1_11=PTB5=[Disabled, PTB5]
ADC1_12=PTB6=[Disabled, PTB6]
ADC1_13=PTB7=[Disabled, PTB7]
ADC1_14=PTB10=[Disabled, PTB10]
ADC1_15=PTB11=[Disabled, PTB11]
ADC1_17=PTA17=[Disabled, PTA17]
ADC1_18=ADC1_SE18=[Disabled, ADC1_SE18]
ADC1_23=ADC1_SE23=[Disabled, ADC1_SE23]
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
I2C1_SDA=PTC11=[Disabled, PTC11, PTE0]
I2C1_SCL=PTC10=[Disabled, PTC10, PTE1]
I2C2_SDA=PTA11=[Disabled, PTA11, PTA13]
I2C2_SCL=PTA12=[Disabled, PTA12, PTA14]
LPTMR0_1=Disabled=[Disabled, PTA19]
LPTMR0_2=Disabled=[Disabled, PTC5]
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
LPTMR0=SIM->SCGC5=SIM_SCGC5_LPTMR_MASK
SDHC0=SIM->SCGC3=SIM_SCGC3_SDHC0_MASK
I2C0=SIM->SCGC4=SIM_SCGC4_I2C0_MASK
I2C1=SIM->SCGC4=SIM_SCGC4_I2C1_MASK
I2C2=SIM->SCGC1=SIM_SCGC1_I2C2_MASK
SPI0=SIM->SCGC6=SIM_SCGC6_SPI0_MASK
SPI1=SIM->SCGC6=SIM_SCGC6_SPI1_MASK
SPI2=SIM->SCGC3=SIM_SCGC3_SPI2_MASK
FTM0=SIM->SCGC6=SIM_SCGC6_FTM0_MASK
FTM1=SIM->SCGC6=SIM_SCGC6_FTM1_MASK
FTM2=SIM->SCGC6=SIM_SCGC6_FTM2_MASK
FTM3=SIM->SCGC3=SIM_SCGC3_FTM3_MASK
*/

#endif /* GPIO_H_ */
