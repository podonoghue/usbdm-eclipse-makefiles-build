/**
 * @file      gpio.h (derived from gpio-MK22F51212.h)
 * @version   1.1.0
 * @brief     Pin declarations for MK22F51212
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stddef.h>
#include "derivative.h"
#include "pin_mapping.h"
#include "gpio_defs.h"

#if USBDM_USE_NAMESPACES
namespace USBDM {
#endif
/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const USBDM::PortA_T<0>   digitalIO_PTA0;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<1>   digitalIO_PTA1;      //!< See @ref DigitalIO
#define digitalIO_D9             digitalIO_PTA1       //!< Alias for @ref USBDM::digitalIO_PTA1
#define digitalIO_J2_4           digitalIO_PTA1       //!< Alias for @ref USBDM::digitalIO_PTA1
#define digitalIO_LED_RED        digitalIO_PTA1       //!< Alias for @ref USBDM::digitalIO_PTA1
extern const USBDM::PortA_T<2>   digitalIO_PTA2;      //!< See @ref DigitalIO
#define digitalIO_D3             digitalIO_PTA2       //!< Alias for @ref USBDM::digitalIO_PTA2
#define digitalIO_J1_8           digitalIO_PTA2       //!< Alias for @ref USBDM::digitalIO_PTA2
#define digitalIO_LED_GREEN      digitalIO_PTA2       //!< Alias for @ref USBDM::digitalIO_PTA2
extern const USBDM::PortA_T<3>   digitalIO_PTA3;      //!< See @ref DigitalIO
extern const USBDM::PortA_T<4>   digitalIO_PTA4;      //!< See @ref DigitalIO
#define digitalIO_D4             digitalIO_PTA4       //!< Alias for @ref USBDM::digitalIO_PTA4
#define digitalIO_J1_10          digitalIO_PTA4       //!< Alias for @ref USBDM::digitalIO_PTA4
extern const USBDM::PortA_T<5>   digitalIO_PTA5;      //!< See @ref DigitalIO
#define digitalIO_J1_1           digitalIO_PTA5       //!< Alias for @ref USBDM::digitalIO_PTA5
extern const USBDM::PortA_T<12>  digitalIO_PTA12;     //!< See @ref DigitalIO
#define digitalIO_J1_5           digitalIO_PTA12      //!< Alias for @ref USBDM::digitalIO_PTA12
extern const USBDM::PortA_T<13>  digitalIO_PTA13;     //!< See @ref DigitalIO
#define digitalIO_J1_3           digitalIO_PTA13      //!< Alias for @ref USBDM::digitalIO_PTA13
extern const USBDM::PortA_T<14>  digitalIO_PTA14;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<15>  digitalIO_PTA15;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<16>  digitalIO_PTA16;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<17>  digitalIO_PTA17;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<18>  digitalIO_PTA18;     //!< See @ref DigitalIO
extern const USBDM::PortA_T<19>  digitalIO_PTA19;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<0>   digitalIO_PTB0;      //!< See @ref DigitalIO
#define digitalIO_A0             digitalIO_PTB0       //!< Alias for @ref USBDM::digitalIO_PTB0
#define digitalIO_J24_2          digitalIO_PTB0       //!< Alias for @ref USBDM::digitalIO_PTB0
extern const USBDM::PortB_T<1>   digitalIO_PTB1;      //!< See @ref DigitalIO
#define digitalIO_A1             digitalIO_PTB1       //!< Alias for @ref USBDM::digitalIO_PTB1
#define digitalIO_J24_4          digitalIO_PTB1       //!< Alias for @ref USBDM::digitalIO_PTB1
extern const USBDM::PortB_T<2>   digitalIO_PTB2;      //!< See @ref DigitalIO
#define digitalIO_A5             digitalIO_PTB2       //!< Alias for @ref USBDM::digitalIO_PTB2
#define digitalIO_J24_12         digitalIO_PTB2       //!< Alias for @ref USBDM::digitalIO_PTB2
#define digitalIO_ONBOARD_SCL    digitalIO_PTB2       //!< Alias for @ref USBDM::digitalIO_PTB2
extern const USBDM::PortB_T<3>   digitalIO_PTB3;      //!< See @ref DigitalIO
#define digitalIO_A4             digitalIO_PTB3       //!< Alias for @ref USBDM::digitalIO_PTB3
#define digitalIO_J24_10         digitalIO_PTB3       //!< Alias for @ref USBDM::digitalIO_PTB3
#define digitalIO_ONBOARD_SDA    digitalIO_PTB3       //!< Alias for @ref USBDM::digitalIO_PTB3
extern const USBDM::PortB_T<6>   digitalIO_PTB6;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<7>   digitalIO_PTB7;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<8>   digitalIO_PTB8;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<9>   digitalIO_PTB9;      //!< See @ref DigitalIO
extern const USBDM::PortB_T<10>  digitalIO_PTB10;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<11>  digitalIO_PTB11;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<16>  digitalIO_PTB16;     //!< See @ref DigitalIO
#define digitalIO_D2             digitalIO_PTB16      //!< Alias for @ref USBDM::digitalIO_PTB16
#define digitalIO_J1_6           digitalIO_PTB16      //!< Alias for @ref USBDM::digitalIO_PTB16
extern const USBDM::PortB_T<17>  digitalIO_PTB17;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<18>  digitalIO_PTB18;     //!< See @ref DigitalIO
#define digitalIO_D5             digitalIO_PTB18      //!< Alias for @ref USBDM::digitalIO_PTB18
#define digitalIO_J1_12          digitalIO_PTB18      //!< Alias for @ref USBDM::digitalIO_PTB18
extern const USBDM::PortB_T<19>  digitalIO_PTB19;     //!< See @ref DigitalIO
#define digitalIO_D8             digitalIO_PTB19      //!< Alias for @ref USBDM::digitalIO_PTB19
#define digitalIO_J2_2           digitalIO_PTB19      //!< Alias for @ref USBDM::digitalIO_PTB19
extern const USBDM::PortB_T<20>  digitalIO_PTB20;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<21>  digitalIO_PTB21;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<22>  digitalIO_PTB22;     //!< See @ref DigitalIO
extern const USBDM::PortB_T<23>  digitalIO_PTB23;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<0>   digitalIO_PTC0;      //!< See @ref DigitalIO
extern const USBDM::PortC_T<1>   digitalIO_PTC1;      //!< See @ref DigitalIO
#define digitalIO_A2             digitalIO_PTC1       //!< Alias for @ref USBDM::digitalIO_PTC1
#define digitalIO_J24_6          digitalIO_PTC1       //!< Alias for @ref USBDM::digitalIO_PTC1
extern const USBDM::PortC_T<2>   digitalIO_PTC2;      //!< See @ref DigitalIO
#define digitalIO_A3             digitalIO_PTC2       //!< Alias for @ref USBDM::digitalIO_PTC2
#define digitalIO_J24_8          digitalIO_PTC2       //!< Alias for @ref USBDM::digitalIO_PTC2
extern const USBDM::PortC_T<3>   digitalIO_PTC3;      //!< See @ref DigitalIO
#define digitalIO_D6             digitalIO_PTC3       //!< Alias for @ref USBDM::digitalIO_PTC3
#define digitalIO_J1_14          digitalIO_PTC3       //!< Alias for @ref USBDM::digitalIO_PTC3
extern const USBDM::PortC_T<4>   digitalIO_PTC4;      //!< See @ref DigitalIO
#define digitalIO_J24_9          digitalIO_PTC4       //!< Alias for @ref USBDM::digitalIO_PTC4
extern const USBDM::PortC_T<5>   digitalIO_PTC5;      //!< See @ref DigitalIO
#define digitalIO_J1_15          digitalIO_PTC5       //!< Alias for @ref USBDM::digitalIO_PTC5
extern const USBDM::PortC_T<6>   digitalIO_PTC6;      //!< See @ref DigitalIO
#define digitalIO_D7             digitalIO_PTC6       //!< Alias for @ref USBDM::digitalIO_PTC6
#define digitalIO_J1_16          digitalIO_PTC6       //!< Alias for @ref USBDM::digitalIO_PTC6
extern const USBDM::PortC_T<7>   digitalIO_PTC7;      //!< See @ref DigitalIO
#define digitalIO_J1_11          digitalIO_PTC7       //!< Alias for @ref USBDM::digitalIO_PTC7
extern const USBDM::PortC_T<8>   digitalIO_PTC8;      //!< See @ref DigitalIO
#define digitalIO_J1_7           digitalIO_PTC8       //!< Alias for @ref USBDM::digitalIO_PTC8
extern const USBDM::PortC_T<9>   digitalIO_PTC9;      //!< See @ref DigitalIO
#define digitalIO_J1_9           digitalIO_PTC9       //!< Alias for @ref USBDM::digitalIO_PTC9
extern const USBDM::PortC_T<10>  digitalIO_PTC10;     //!< See @ref DigitalIO
#define digitalIO_J1_13          digitalIO_PTC10      //!< Alias for @ref USBDM::digitalIO_PTC10
extern const USBDM::PortC_T<11>  digitalIO_PTC11;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<12>  digitalIO_PTC12;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<13>  digitalIO_PTC13;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<14>  digitalIO_PTC14;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<15>  digitalIO_PTC15;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<16>  digitalIO_PTC16;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<17>  digitalIO_PTC17;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<18>  digitalIO_PTC18;     //!< See @ref DigitalIO
extern const USBDM::PortC_T<19>  digitalIO_PTC19;     //!< See @ref DigitalIO
extern const USBDM::PortD_T<0>   digitalIO_PTD0;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<1>   digitalIO_PTD1;      //!< See @ref DigitalIO
extern const USBDM::PortD_T<2>   digitalIO_PTD2;      //!< See @ref DigitalIO
#define digitalIO_D0             digitalIO_PTD2       //!< Alias for @ref USBDM::digitalIO_PTD2
#define digitalIO_J1_2           digitalIO_PTD2       //!< Alias for @ref USBDM::digitalIO_PTD2
extern const USBDM::PortD_T<3>   digitalIO_PTD3;      //!< See @ref DigitalIO
#define digitalIO_D1             digitalIO_PTD3       //!< Alias for @ref USBDM::digitalIO_PTD3
#define digitalIO_J1_4           digitalIO_PTD3       //!< Alias for @ref USBDM::digitalIO_PTD3
extern const USBDM::PortD_T<4>   digitalIO_PTD4;      //!< See @ref DigitalIO
#define digitalIO_D10            digitalIO_PTD4       //!< Alias for @ref USBDM::digitalIO_PTD4
#define digitalIO_J2_6           digitalIO_PTD4       //!< Alias for @ref USBDM::digitalIO_PTD4
extern const USBDM::PortD_T<5>   digitalIO_PTD5;      //!< See @ref DigitalIO
#define digitalIO_D13            digitalIO_PTD5       //!< Alias for @ref USBDM::digitalIO_PTD5
#define digitalIO_J2_12          digitalIO_PTD5       //!< Alias for @ref USBDM::digitalIO_PTD5
#define digitalIO_LED_BLUE       digitalIO_PTD5       //!< Alias for @ref USBDM::digitalIO_PTD5
extern const USBDM::PortD_T<6>   digitalIO_PTD6;      //!< See @ref DigitalIO
#define digitalIO_D11            digitalIO_PTD6       //!< Alias for @ref USBDM::digitalIO_PTD6
#define digitalIO_J2_8           digitalIO_PTD6       //!< Alias for @ref USBDM::digitalIO_PTD6
extern const USBDM::PortD_T<7>   digitalIO_PTD7;      //!< See @ref DigitalIO
#define digitalIO_D12            digitalIO_PTD7       //!< Alias for @ref USBDM::digitalIO_PTD7
#define digitalIO_J2_10          digitalIO_PTD7       //!< Alias for @ref USBDM::digitalIO_PTD7
extern const USBDM::PortE_T<0>   digitalIO_PTE0;      //!< See @ref DigitalIO
#define digitalIO_D14            digitalIO_PTE0       //!< Alias for @ref USBDM::digitalIO_PTE0
#define digitalIO_J2_18          digitalIO_PTE0       //!< Alias for @ref USBDM::digitalIO_PTE0
extern const USBDM::PortE_T<1>   digitalIO_PTE1;      //!< See @ref DigitalIO
#define digitalIO_D15            digitalIO_PTE1       //!< Alias for @ref USBDM::digitalIO_PTE1
#define digitalIO_J2_19          digitalIO_PTE1       //!< Alias for @ref USBDM::digitalIO_PTE1
extern const USBDM::PortE_T<2>   digitalIO_PTE2;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<3>   digitalIO_PTE3;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<4>   digitalIO_PTE4;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<5>   digitalIO_PTE5;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<6>   digitalIO_PTE6;      //!< See @ref DigitalIO
extern const USBDM::PortE_T<24>  digitalIO_PTE24;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<25>  digitalIO_PTE25;     //!< See @ref DigitalIO
extern const USBDM::PortE_T<26>  digitalIO_PTE26;     //!< See @ref DigitalIO
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const USBDM::AnalogueIOT<0,                0,                                         ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,19> analogueIO_ADC0_SE19;
#define analogueIO_J24_3         analogueIO_ADC0_SE19 //!< Alias for @ref USBDM::analogueIO_ADC0_SE19
extern const USBDM::AnalogueIOT<0,                0,                                         ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,20> analogueIO_ADC0_SE20;
extern const USBDM::AnalogueIOT<0,                0,                                         ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,19> analogueIO_ADC1_SE19;
#define analogueIO_J24_7         analogueIO_ADC1_SE19 //!< Alias for @ref USBDM::analogueIO_ADC1_SE19
extern const USBDM::AnalogueIOT<0,                0,                                         ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 0> analogueIO_ADC0_SE0;
#define analogueIO_J24_1         analogueIO_ADC0_SE0  //!< Alias for @ref USBDM::analogueIO_ADC0_SE0
extern const USBDM::AnalogueIOT<0,                0,                                         ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 1> analogueIO_ADC0_SE1;
extern const USBDM::AnalogueIOT<0,                0,                                         ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 0> analogueIO_ADC1_SE0;
#define analogueIO_J24_5         analogueIO_ADC1_SE0  //!< Alias for @ref USBDM::analogueIO_ADC1_SE0
extern const USBDM::AnalogueIOT<0,                0,                                         ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 3> analogueIO_ADC0_SE3;
//#define analogueIO_J24_5         analogueIO_ADC0_SE3  //!< Alias for @ref USBDM::analogueIO_ADC0_SE3
extern const USBDM::AnalogueIOT<0,                0,                                         ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,23> analogueIO_ADC0_SE23;
#define analogueIO_J24_11        analogueIO_ADC0_SE23 //!< Alias for @ref USBDM::analogueIO_ADC0_SE23
extern const USBDM::AnalogueIOT<0,                0,                                         ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,20> analogueIO_ADC1_SE20;
extern const USBDM::AnalogueIOT<0,                0,                                         ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 1> analogueIO_ADC1_SE1;
extern const USBDM::AnalogueIOT<0,                0,                                         ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 2> analogueIO_ADC0_SE2;
extern const USBDM::AnalogueIOT<0,                0,                                         ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,18> analogueIO_ADC1_SE18;
extern const USBDM::AnalogueIOT<0,                0,                                         ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,23> analogueIO_ADC1_SE23;
#if (PTA17_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[17]), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,17> analogueIO_ADC1_SE17;
#endif
#if (PTB0_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 8> analogueIO_ADC0_SE8;
#define analogueIO_A0            analogueIO_ADC0_SE8  //!< Alias for @ref USBDM::analogueIO_ADC0_SE8
#define analogueIO_J24_2         analogueIO_ADC0_SE8  //!< Alias for @ref USBDM::analogueIO_ADC0_SE8
#endif
#if (PTB0_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 8> analogueIO_ADC1_SE8;
//#define analogueIO_A0            analogueIO_ADC1_SE8  //!< Alias for @ref USBDM::analogueIO_ADC1_SE8
//#define analogueIO_J24_2         analogueIO_ADC1_SE8  //!< Alias for @ref USBDM::analogueIO_ADC1_SE8
#endif
#if (PTB1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 9> analogueIO_ADC0_SE9;
#define analogueIO_A1            analogueIO_ADC0_SE9  //!< Alias for @ref USBDM::analogueIO_ADC0_SE9
#define analogueIO_J24_4         analogueIO_ADC0_SE9  //!< Alias for @ref USBDM::analogueIO_ADC0_SE9
#endif
#if (PTB1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 9> analogueIO_ADC1_SE9;
//#define analogueIO_A1            analogueIO_ADC1_SE9  //!< Alias for @ref USBDM::analogueIO_ADC1_SE9
//#define analogueIO_J24_4         analogueIO_ADC1_SE9  //!< Alias for @ref USBDM::analogueIO_ADC1_SE9
#endif
#if (PTB2_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,12> analogueIO_ADC0_SE12;
#define analogueIO_A5            analogueIO_ADC0_SE12 //!< Alias for @ref USBDM::analogueIO_ADC0_SE12
#define analogueIO_J24_12        analogueIO_ADC0_SE12 //!< Alias for @ref USBDM::analogueIO_ADC0_SE12
#define analogueIO_ONBOARD_SCL   analogueIO_ADC0_SE12 //!< Alias for @ref USBDM::analogueIO_ADC0_SE12
#endif
#if (PTB3_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,13> analogueIO_ADC0_SE13;
#define analogueIO_A4            analogueIO_ADC0_SE13 //!< Alias for @ref USBDM::analogueIO_ADC0_SE13
#define analogueIO_J24_10        analogueIO_ADC0_SE13 //!< Alias for @ref USBDM::analogueIO_ADC0_SE13
#define analogueIO_ONBOARD_SDA   analogueIO_ADC0_SE13 //!< Alias for @ref USBDM::analogueIO_ADC0_SE13
#endif
#if (PTB6_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[6]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,12> analogueIO_ADC1_SE12;
#endif
#if (PTB7_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[7]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,13> analogueIO_ADC1_SE13;
#endif
#if (PTB10_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[10]), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,14> analogueIO_ADC1_SE14;
#endif
#if (PTB11_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[11]), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK,15> analogueIO_ADC1_SE15;
#endif
#if (PTC0_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,14> analogueIO_ADC0_SE14;
#endif
#if (PTC1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,15> analogueIO_ADC0_SE15;
#define analogueIO_A2            analogueIO_ADC0_SE15 //!< Alias for @ref USBDM::analogueIO_ADC0_SE15
#define analogueIO_J24_6         analogueIO_ADC0_SE15 //!< Alias for @ref USBDM::analogueIO_ADC0_SE15
#endif
#if (PTC2_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 4> analogueIO_ADC0_SE4b;
#define analogueIO_A3            analogueIO_ADC0_SE4b //!< Alias for @ref USBDM::analogueIO_ADC0_SE4b
#define analogueIO_J24_8         analogueIO_ADC0_SE4b //!< Alias for @ref USBDM::analogueIO_ADC0_SE4b
#endif
#if (PTC8_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 4> analogueIO_ADC1_SE4b;
#define analogueIO_J1_7          analogueIO_ADC1_SE4b //!< Alias for @ref USBDM::analogueIO_ADC1_SE4b
#endif
#if (PTC9_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 5> analogueIO_ADC1_SE5b;
#define analogueIO_J1_9          analogueIO_ADC1_SE5b //!< Alias for @ref USBDM::analogueIO_ADC1_SE5b
#endif
#if (PTC10_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 6> analogueIO_ADC1_SE6b;
#define analogueIO_J1_13         analogueIO_ADC1_SE6b //!< Alias for @ref USBDM::analogueIO_ADC1_SE6b
#endif
#if (PTC11_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 7> analogueIO_ADC1_SE7b;
#endif
#if (PTD1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 5> analogueIO_ADC0_SE5b;
#endif
#if (PTD5_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 6> analogueIO_ADC0_SE6b;
#define analogueIO_D13           analogueIO_ADC0_SE6b //!< Alias for @ref USBDM::analogueIO_ADC0_SE6b
#define analogueIO_J2_12         analogueIO_ADC0_SE6b //!< Alias for @ref USBDM::analogueIO_ADC0_SE6b
#define analogueIO_LED_BLUE      analogueIO_ADC0_SE6b //!< Alias for @ref USBDM::analogueIO_ADC0_SE6b
#endif
#if (PTD6_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK, 7> analogueIO_ADC0_SE7b;
#define analogueIO_D11           analogueIO_ADC0_SE7b //!< Alias for @ref USBDM::analogueIO_ADC0_SE7b
#define analogueIO_J2_8          analogueIO_ADC0_SE7b //!< Alias for @ref USBDM::analogueIO_ADC0_SE7b
#endif
#if (PTE0_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 4> analogueIO_ADC1_SE4a;
#define analogueIO_D14           analogueIO_ADC1_SE4a //!< Alias for @ref USBDM::analogueIO_ADC1_SE4a
#define analogueIO_J2_18         analogueIO_ADC1_SE4a //!< Alias for @ref USBDM::analogueIO_ADC1_SE4a
#endif
#if (PTE1_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 5> analogueIO_ADC1_SE5a;
#define analogueIO_D15           analogueIO_ADC1_SE5a //!< Alias for @ref USBDM::analogueIO_ADC1_SE5a
#define analogueIO_J2_19         analogueIO_ADC1_SE5a //!< Alias for @ref USBDM::analogueIO_ADC1_SE5a
#endif
#if (PTE2_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[2]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 6> analogueIO_ADC1_SE6a;
#endif
#if (PTE3_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[3]),  ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG),ADC1_CLOCK_MASK, 7> analogueIO_ADC1_SE7a;
#endif
#if (PTE24_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,17> analogueIO_ADC0_SE17;
#endif
#if (PTE25_SIG_SEL == 0)
extern const USBDM::AnalogueIOT<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),ADC0_CLOCK_MASK,18> analogueIO_ADC0_SE18;
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA0_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 5,  3> pwmIO_FTM0_CH5;
#endif
#if (PTA1_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 6,  3> pwmIO_FTM0_CH6;
#define pwmIO_D9                 pwmIO_FTM0_CH6       //!< Alias for @ref USBDM::pwmIO_FTM0_CH6
#define pwmIO_J2_4               pwmIO_FTM0_CH6       //!< Alias for @ref USBDM::pwmIO_FTM0_CH6
#define pwmIO_LED_RED            pwmIO_FTM0_CH6       //!< Alias for @ref USBDM::pwmIO_FTM0_CH6
#endif
#if (PTA2_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 7,  3> pwmIO_FTM0_CH7;
#define pwmIO_D3                 pwmIO_FTM0_CH7       //!< Alias for @ref USBDM::pwmIO_FTM0_CH7
#define pwmIO_J1_8               pwmIO_FTM0_CH7       //!< Alias for @ref USBDM::pwmIO_FTM0_CH7
#define pwmIO_LED_GREEN          pwmIO_FTM0_CH7       //!< Alias for @ref USBDM::pwmIO_FTM0_CH7
#endif
#if (PTA3_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 0,  3> pwmIO_FTM0_CH0;
#endif
#if (PTA4_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 1,  3> pwmIO_FTM0_CH1;
#define pwmIO_D4                 pwmIO_FTM0_CH1       //!< Alias for @ref USBDM::pwmIO_FTM0_CH1
#define pwmIO_J1_10              pwmIO_FTM0_CH1       //!< Alias for @ref USBDM::pwmIO_FTM0_CH1
#endif
#if (PTA5_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 2,  3> pwmIO_FTM0_CH2;
#define pwmIO_J1_1               pwmIO_FTM0_CH2       //!< Alias for @ref USBDM::pwmIO_FTM0_CH2
#endif
#if (PTA12_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), FTM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM1_CLOCK_REG), FTM1_CLOCK_MASK, 0,  3> pwmIO_FTM1_CH0;
#define pwmIO_J1_5               pwmIO_FTM1_CH0       //!< Alias for @ref USBDM::pwmIO_FTM1_CH0
#endif
#if (PTA13_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), FTM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM1_CLOCK_REG), FTM1_CLOCK_MASK, 1,  3> pwmIO_FTM1_CH1;
#define pwmIO_J1_3               pwmIO_FTM1_CH1       //!< Alias for @ref USBDM::pwmIO_FTM1_CH1
#endif
#if (PTB0_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  FTM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM1_CLOCK_REG), FTM1_CLOCK_MASK, 0,  3> pwmIO_FTM1_CH0;
#define pwmIO_A0                 pwmIO_FTM1_CH0       //!< Alias for @ref USBDM::pwmIO_FTM1_CH0
#define pwmIO_J24_2              pwmIO_FTM1_CH0       //!< Alias for @ref USBDM::pwmIO_FTM1_CH0
#endif
#if (PTB1_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  FTM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM1_CLOCK_REG), FTM1_CLOCK_MASK, 1,  3> pwmIO_FTM1_CH1;
#define pwmIO_A1                 pwmIO_FTM1_CH1       //!< Alias for @ref USBDM::pwmIO_FTM1_CH1
#define pwmIO_J24_4              pwmIO_FTM1_CH1       //!< Alias for @ref USBDM::pwmIO_FTM1_CH1
#endif
#if (PTB18_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]), FTM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM2_CLOCK_REG), FTM2_CLOCK_MASK, 0,  3> pwmIO_FTM2_CH0;
#define pwmIO_D5                 pwmIO_FTM2_CH0       //!< Alias for @ref USBDM::pwmIO_FTM2_CH0
#define pwmIO_J1_12              pwmIO_FTM2_CH0       //!< Alias for @ref USBDM::pwmIO_FTM2_CH0
#endif
#if (PTB19_SIG_SEL == 3)
extern const USBDM::PwmIOT<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]), FTM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM2_CLOCK_REG), FTM2_CLOCK_MASK, 1,  3> pwmIO_FTM2_CH1;
#define pwmIO_D8                 pwmIO_FTM2_CH1       //!< Alias for @ref USBDM::pwmIO_FTM2_CH1
#define pwmIO_J2_2               pwmIO_FTM2_CH1       //!< Alias for @ref USBDM::pwmIO_FTM2_CH1
#endif
#if (PTC1_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 0,  4> pwmIO_FTM0_CH0;
#define pwmIO_A2                 pwmIO_FTM0_CH0       //!< Alias for @ref USBDM::pwmIO_FTM0_CH0
#define pwmIO_J24_6              pwmIO_FTM0_CH0       //!< Alias for @ref USBDM::pwmIO_FTM0_CH0
#endif
#if (PTC2_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 1,  4> pwmIO_FTM0_CH1;
#define pwmIO_A3                 pwmIO_FTM0_CH1       //!< Alias for @ref USBDM::pwmIO_FTM0_CH1
#define pwmIO_J24_8              pwmIO_FTM0_CH1       //!< Alias for @ref USBDM::pwmIO_FTM0_CH1
#endif
#if (PTC3_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 2,  4> pwmIO_FTM0_CH2;
#define pwmIO_D6                 pwmIO_FTM0_CH2       //!< Alias for @ref USBDM::pwmIO_FTM0_CH2
#define pwmIO_J1_14              pwmIO_FTM0_CH2       //!< Alias for @ref USBDM::pwmIO_FTM0_CH2
#endif
#if (PTC4_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 3,  4> pwmIO_FTM0_CH3;
#define pwmIO_J24_9              pwmIO_FTM0_CH3       //!< Alias for @ref USBDM::pwmIO_FTM0_CH3
#endif
#if (PTC5_SIG_SEL == 7)
extern const USBDM::PwmIOT<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 2,  7> pwmIO_FTM0_CH2;
#define pwmIO_J1_15              pwmIO_FTM0_CH2       //!< Alias for @ref USBDM::pwmIO_FTM0_CH2
#endif
#if (PTD4_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 4,  4> pwmIO_FTM0_CH4;
#define pwmIO_D10                pwmIO_FTM0_CH4       //!< Alias for @ref USBDM::pwmIO_FTM0_CH4
#define pwmIO_J2_6               pwmIO_FTM0_CH4       //!< Alias for @ref USBDM::pwmIO_FTM0_CH4
#endif
#if (PTD5_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 5,  4> pwmIO_FTM0_CH5;
#define pwmIO_D13                pwmIO_FTM0_CH5       //!< Alias for @ref USBDM::pwmIO_FTM0_CH5
#define pwmIO_J2_12              pwmIO_FTM0_CH5       //!< Alias for @ref USBDM::pwmIO_FTM0_CH5
#define pwmIO_LED_BLUE           pwmIO_FTM0_CH5       //!< Alias for @ref USBDM::pwmIO_FTM0_CH5
#endif
#if (PTD6_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 6,  4> pwmIO_FTM0_CH6;
#define pwmIO_D11                pwmIO_FTM0_CH6       //!< Alias for @ref USBDM::pwmIO_FTM0_CH6
#define pwmIO_J2_8               pwmIO_FTM0_CH6       //!< Alias for @ref USBDM::pwmIO_FTM0_CH6
#endif
#if (PTD7_SIG_SEL == 4)
extern const USBDM::PwmIOT<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),  FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, 7,  4> pwmIO_FTM0_CH7;
#define pwmIO_D12                pwmIO_FTM0_CH7       //!< Alias for @ref USBDM::pwmIO_FTM0_CH7
#define pwmIO_J2_10              pwmIO_FTM0_CH7       //!< Alias for @ref USBDM::pwmIO_FTM0_CH7
#endif
/**
 * @}
 */
#if defined(DO_MAP_PINS_ON_RESET) && (DO_MAP_PINS_ON_RESET>0)
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
extern void usbdm_PinMapping();
#endif

/*
Clock Information 
ADC0       SCGC6        SIM_SCGC6_ADC0_MASK
ADC1       SCGC6        SIM_SCGC6_ADC1_MASK
CMP        SCGC4        SIM_SCGC4_CMP_MASK
DAC0       SCGC6        SIM_SCGC6_DAC0_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX     SCGC6        SIM_SCGC6_DMAMUX_MASK
EWM        SCGC4        SIM_SCGC4_EWM_MASK
FTM0       SCGC6        SIM_SCGC6_FTM0_MASK
FTM1       SCGC6        SIM_SCGC6_FTM1_MASK
FTM2       SCGC6        SIM_SCGC6_FTM2_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2C1       SCGC4        SIM_SCGC4_I2C1_MASK
I2S0       SCGC6        SIM_SCGC6_I2S0_MASK
LPTMR0     SCGC5        SIM_SCGC5_LPTMR_MASK
LPUART0    SCGC6        SIM_SCGC6_LPUART0_MASK
PDB0       SCGC6        SIM_SCGC6_PDB0_MASK
PIT        SCGC6        SIM_SCGC6_PIT_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
RNGA       SCGC6        SIM_SCGC6_RNGA_MASK
RTC        SCGC6        SIM_SCGC6_RTC_MASK
SPI0       SCGC6        SIM_SCGC6_SPI0_MASK
SPI1       SCGC6        SIM_SCGC6_SPI1_MASK
UART0      SCGC4        SIM_SCGC4_UART0_MASK
UART1      SCGC4        SIM_SCGC4_UART1_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
USBOTG     SCGC4        SIM_SCGC4_USBOTG_MASK
VREF       SCGC4        SIM_SCGC4_VREF_MASK
*/

#if USBDM_USE_NAMESPACES
} // End namespace USBDM
#endif

#endif /* GPIO_H_ */
