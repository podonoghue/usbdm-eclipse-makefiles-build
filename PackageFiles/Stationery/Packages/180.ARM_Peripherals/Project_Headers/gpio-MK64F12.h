/**
 * @file      gpio.h (derived from gpio-MK64F12.h)
 * @version   1.1.0
 * @brief     Pin declarations for MK64F12
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
extern const USBDM::GpioA<0>     gpioA_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D8             gpioA_0              //!< Alias for @ref USBDM::gpioA_0
extern const USBDM::GpioA<1>     gpioA_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D3             gpioA_1              //!< Alias for @ref USBDM::gpioA_1
extern const USBDM::GpioA<2>     gpioA_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D5             gpioA_2              //!< Alias for @ref USBDM::gpioA_2
extern const USBDM::GpioA<3>     gpioA_3;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<4>     gpioA_4;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<5>     gpioA_5;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<6>     gpioA_6;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<7>     gpioA_7;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<8>     gpioA_8;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<9>     gpioA_9;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<10>    gpioA_10;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<11>    gpioA_11;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<12>    gpioA_12;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<13>    gpioA_13;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<14>    gpioA_14;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<15>    gpioA_15;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<16>    gpioA_16;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<17>    gpioA_17;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<18>    gpioA_18;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<19>    gpioA_19;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<24>    gpioA_24;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<25>    gpioA_25;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<26>    gpioA_26;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<27>    gpioA_27;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<28>    gpioA_28;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioA<29>    gpioA_29;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<0>     gpioB_0;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<1>     gpioB_1;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<2>     gpioB_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A0             gpioB_2              //!< Alias for @ref USBDM::gpioB_2
extern const USBDM::GpioB<3>     gpioB_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_A1             gpioB_3              //!< Alias for @ref USBDM::gpioB_3
extern const USBDM::GpioB<4>     gpioB_4;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<5>     gpioB_5;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<6>     gpioB_6;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<7>     gpioB_7;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<8>     gpioB_8;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<9>     gpioB_9;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D2             gpioB_9              //!< Alias for @ref USBDM::gpioB_9
extern const USBDM::GpioB<10>    gpioB_10;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A2             gpioB_10             //!< Alias for @ref USBDM::gpioB_10
extern const USBDM::GpioB<11>    gpioB_11;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A3             gpioB_11             //!< Alias for @ref USBDM::gpioB_11
extern const USBDM::GpioB<12>    gpioB_12;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<13>    gpioB_13;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<16>    gpioB_16;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<17>    gpioB_17;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<18>    gpioB_18;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<19>    gpioB_19;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<20>    gpioB_20;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioB<21>    gpioB_21;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_LED_BLUE       gpioB_21             //!< Alias for @ref USBDM::gpioB_21
extern const USBDM::GpioB<22>    gpioB_22;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_LED_RED        gpioB_22             //!< Alias for @ref USBDM::gpioB_22
extern const USBDM::GpioB<23>    gpioB_23;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D4             gpioB_23             //!< Alias for @ref USBDM::gpioB_23
extern const USBDM::GpioC<0>     gpioC_0;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<1>     gpioC_1;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<2>     gpioC_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D6             gpioC_2              //!< Alias for @ref USBDM::gpioC_2
extern const USBDM::GpioC<3>     gpioC_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D7             gpioC_3              //!< Alias for @ref USBDM::gpioC_3
extern const USBDM::GpioC<4>     gpioC_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D9             gpioC_4              //!< Alias for @ref USBDM::gpioC_4
extern const USBDM::GpioC<5>     gpioC_5;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<6>     gpioC_6;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<7>     gpioC_7;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<8>     gpioC_8;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<9>     gpioC_9;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<10>    gpioC_10;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A5             gpioC_10             //!< Alias for @ref USBDM::gpioC_10
extern const USBDM::GpioC<11>    gpioC_11;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_A4             gpioC_11             //!< Alias for @ref USBDM::gpioC_11
extern const USBDM::GpioC<12>    gpioC_12;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<13>    gpioC_13;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<14>    gpioC_14;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<15>    gpioC_15;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<16>    gpioC_16;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D0             gpioC_16             //!< Alias for @ref USBDM::gpioC_16
extern const USBDM::GpioC<17>    gpioC_17;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D1             gpioC_17             //!< Alias for @ref USBDM::gpioC_17
extern const USBDM::GpioC<18>    gpioC_18;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioC<19>    gpioC_19;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioD<0>     gpioD_0;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D10            gpioD_0              //!< Alias for @ref USBDM::gpioD_0
extern const USBDM::GpioD<1>     gpioD_1;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D13            gpioD_1              //!< Alias for @ref USBDM::gpioD_1
extern const USBDM::GpioD<2>     gpioD_2;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D11            gpioD_2              //!< Alias for @ref USBDM::gpioD_2
extern const USBDM::GpioD<3>     gpioD_3;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_D12            gpioD_3              //!< Alias for @ref USBDM::gpioD_3
extern const USBDM::GpioD<4>     gpioD_4;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_nRF24L01_cs    gpioD_4              //!< Alias for @ref USBDM::gpioD_4
extern const USBDM::GpioD<5>     gpioD_5;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_nRF24L01_sck   gpioD_5              //!< Alias for @ref USBDM::gpioD_5
extern const USBDM::GpioD<6>     gpioD_6;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_nRF24L01_mosi  gpioD_6              //!< Alias for @ref USBDM::gpioD_6
extern const USBDM::GpioD<7>     gpioD_7;             //!< See @ref USBDM::DigitalIOT
#define digitalIO_nRF24L01_miso  gpioD_7              //!< Alias for @ref USBDM::gpioD_7
extern const USBDM::GpioD<8>     gpioD_8;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioD<9>     gpioD_9;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioD<10>    gpioD_10;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioD<11>    gpioD_11;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioD<12>    gpioD_12;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioD<13>    gpioD_13;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioD<14>    gpioD_14;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioD<15>    gpioD_15;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<0>     gpioE_0;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<1>     gpioE_1;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<2>     gpioE_2;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<3>     gpioE_3;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<4>     gpioE_4;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<5>     gpioE_5;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<6>     gpioE_6;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<7>     gpioE_7;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<8>     gpioE_8;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<9>     gpioE_9;             //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<10>    gpioE_10;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<11>    gpioE_11;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<12>    gpioE_12;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<24>    gpioE_24;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D15            gpioE_24             //!< Alias for @ref USBDM::gpioE_24
extern const USBDM::GpioE<25>    gpioE_25;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_D14            gpioE_25             //!< Alias for @ref USBDM::gpioE_25
extern const USBDM::GpioE<26>    gpioE_26;            //!< See @ref USBDM::DigitalIOT
#define digitalIO_LED_GREEN      gpioE_26             //!< Alias for @ref USBDM::gpioE_26
extern const USBDM::GpioE<27>    gpioE_27;            //!< See @ref USBDM::DigitalIOT
extern const USBDM::GpioE<28>    gpioE_28;            //!< See @ref USBDM::DigitalIOT
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const USBDM::Adc0<0,                0,                                         19> adc0_se19;
extern const USBDM::Adc0<0,                0,                                         20> adc0_se20;
extern const USBDM::Adc0<0,                0,                                          0> adc0_se0;
extern const USBDM::Adc0<0,                0,                                          1> adc0_se1;
extern const USBDM::Adc0<0,                0,                                         16> adc0_se16;
extern const USBDM::Adc0<0,                0,                                         21> adc0_se21;
extern const USBDM::Adc0<0,                0,                                         23> adc0_se23;
extern const USBDM::Adc1<0,                0,                                         19> adc1_se19;
extern const USBDM::Adc1<0,                0,                                         20> adc1_se20;
extern const USBDM::Adc1<0,                0,                                          0> adc1_se0;
extern const USBDM::Adc0<0,                0,                                          3> adc0_se3;
extern const USBDM::Adc1<0,                0,                                          1> adc1_se1;
extern const USBDM::Adc1<0,                0,                                         16> adc1_se16;
extern const USBDM::Adc0<0,                0,                                         22> adc0_se22;
extern const USBDM::Adc1<0,                0,                                         18> adc1_se18;
extern const USBDM::Adc1<0,                0,                                         23> adc1_se23;
#if (PTA7_SIG_SEL == 0)
extern const USBDM::Adc0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[7]),  10> adc0_se10;
#endif
#if (PTA8_SIG_SEL == 0)
extern const USBDM::Adc0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[8]),  11> adc0_se11;
#endif
#if (PTA17_SIG_SEL == 0)
extern const USBDM::Adc1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[17]), 17> adc1_se17;
#endif
#if (PTB0_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc0_se8;
#endif
#if (PTB0_SIG_SEL == 0)
extern const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc1_se8;
#endif
#if (PTB1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc0_se9;
#endif
#if (PTB1_SIG_SEL == 0)
extern const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc1_se9;
#endif
#if (PTB2_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc0_se12;
#define analogueIO_A0            adc0_se12            //!< Alias for @ref USBDM::adc0_se12
#endif
#if (PTB3_SIG_SEL == 0)
extern const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc0_se13;
#define analogueIO_A1            adc0_se13            //!< Alias for @ref USBDM::adc0_se13
#endif
#if (PTB4_SIG_SEL == 0)
extern const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[4]),  10> adc1_se10;
#endif
#if (PTB5_SIG_SEL == 0)
extern const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[5]),  11> adc1_se11;
#endif
#if (PTB6_SIG_SEL == 0)
extern const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[6]),  12> adc1_se12;
#endif
#if (PTB7_SIG_SEL == 0)
extern const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[7]),  13> adc1_se13;
#endif
#if (PTB10_SIG_SEL == 0)
extern const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[10]), 14> adc1_se14;
#define analogueIO_A2            adc1_se14            //!< Alias for @ref USBDM::adc1_se14
#endif
#if (PTB11_SIG_SEL == 0)
extern const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[11]), 15> adc1_se15;
#define analogueIO_A3            adc1_se15            //!< Alias for @ref USBDM::adc1_se15
#endif
#if (PTC0_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc0_se14;
#endif
#if (PTC1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc0_se15;
#endif
#if (PTC2_SIG_SEL == 0)
extern const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4> adc0_se4;
#define analogueIO_D6            adc0_se4             //!< Alias for @ref USBDM::adc0_se4
#endif
#if (PTC8_SIG_SEL == 0)
extern const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),   4> adc1_se4;
#endif
#if (PTC9_SIG_SEL == 0)
extern const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),   5> adc1_se5;
#endif
#if (PTC10_SIG_SEL == 0)
extern const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]),  6> adc1_se6;
#define analogueIO_A5            adc1_se6             //!< Alias for @ref USBDM::adc1_se6
#endif
#if (PTC11_SIG_SEL == 0)
extern const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]),  7> adc1_se7;
#define analogueIO_A4            adc1_se7             //!< Alias for @ref USBDM::adc1_se7
#endif
#if (PTD1_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc0_se5;
#define analogueIO_D13           adc0_se5             //!< Alias for @ref USBDM::adc0_se5
#endif
#if (PTD5_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc0_se6;
#define analogueIO_nRF24L01_sck  adc0_se6             //!< Alias for @ref USBDM::adc0_se6
#endif
#if (PTD6_SIG_SEL == 0)
extern const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc0_se7;
#define analogueIO_nRF24L01_mosi adc0_se7             //!< Alias for @ref USBDM::adc0_se7
#endif
#if (PTE0_SIG_SEL == 0)
extern const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),   4> adc1_se4;
#endif
#if (PTE1_SIG_SEL == 0)
extern const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc1_se5;
#endif
#if (PTE2_SIG_SEL == 0)
extern const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[2]),   6> adc1_se6;
#endif
#if (PTE2_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[2]),   2> adc0_se2;
#endif
#if (PTE3_SIG_SEL == 0)
extern const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[3]),   7> adc1_se7;
#endif
#if (PTE24_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), 17> adc0_se17;
#define analogueIO_D15           adc0_se17            //!< Alias for @ref USBDM::adc0_se17
#endif
#if (PTE25_SIG_SEL == 0)
extern const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), 18> adc0_se18;
#define analogueIO_D14           adc0_se18            //!< Alias for @ref USBDM::adc0_se18
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
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  5>   ftm0_ch5;
#define pwmIO_D8                 ftm0_ch5             //!< Alias for @ref USBDM::ftm0_ch5
#endif
#if (PTA1_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm0_ch6;
#define pwmIO_D3                 ftm0_ch6             //!< Alias for @ref USBDM::ftm0_ch6
#endif
#if (PTA2_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm0_ch7;
#define pwmIO_D5                 ftm0_ch7             //!< Alias for @ref USBDM::ftm0_ch7
#endif
#if (PTA3_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),   3,  0>   ftm0_ch0;
#endif
#if (PTA4_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   ftm0_ch1;
#endif
#if (PTA5_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   ftm0_ch2;
#endif
#if (PTA6_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[6]),   3,  3>   ftm0_ch3;
#endif
#if (PTA7_SIG_SEL == 3)
extern const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[7]),   3,  4>   ftm0_ch4;
#endif
#if (PTA8_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[8]),   3,  0>   ftm1_ch0;
#endif
#if (PTA9_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[9]),   3,  1>   ftm1_ch1;
#endif
#if (PTA10_SIG_SEL == 3)
extern const USBDM::Ftm2<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[10]),  3,  0>   ftm2_ch0;
#endif
#if (PTA11_SIG_SEL == 3)
extern const USBDM::Ftm2<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[11]),  3,  1>   ftm2_ch1;
#endif
#if (PTA12_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   ftm1_ch0;
#endif
#if (PTA13_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   ftm1_ch1;
#endif
#if (PTB0_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm1_ch0;
#endif
#if (PTB1_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm1_ch1;
#endif
#if (PTB12_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   ftm1_ch0;
#endif
#if (PTB12_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[12]),  4,  4>   ftm0_ch4;
#endif
#if (PTB13_SIG_SEL == 3)
extern const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   ftm1_ch1;
#endif
#if (PTB13_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[13]),  4,  5>   ftm0_ch5;
#endif
#if (PTB18_SIG_SEL == 3)
extern const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]),  3,  0>   ftm2_ch0;
#endif
#if (PTB19_SIG_SEL == 3)
extern const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]),  3,  1>   ftm2_ch1;
#endif
#if (PTC1_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   ftm0_ch0;
#endif
#if (PTC2_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   ftm0_ch1;
#define pwmIO_D6                 ftm0_ch1             //!< Alias for @ref USBDM::ftm0_ch1
#endif
#if (PTC3_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm0_ch2;
#define pwmIO_D7                 ftm0_ch2             //!< Alias for @ref USBDM::ftm0_ch2
#endif
#if (PTC4_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   ftm0_ch3;
#define pwmIO_D9                 ftm0_ch3             //!< Alias for @ref USBDM::ftm0_ch3
#endif
#if (PTC5_SIG_SEL == 7)
extern const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),   7,  2>   ftm0_ch2;
#endif
#if (PTC8_SIG_SEL == 3)
extern const USBDM::Ftm3<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),   3,  4>   ftm3_ch4;
#endif
#if (PTC9_SIG_SEL == 3)
extern const USBDM::Ftm3<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),   3,  5>   ftm3_ch5;
#endif
#if (PTC10_SIG_SEL == 3)
extern const USBDM::Ftm3<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]),  3,  6>   ftm3_ch6;
#define pwmIO_A5                 ftm3_ch6             //!< Alias for @ref USBDM::ftm3_ch6
#endif
#if (PTC11_SIG_SEL == 3)
extern const USBDM::Ftm3<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]),  3,  7>   ftm3_ch7;
#define pwmIO_A4                 ftm3_ch7             //!< Alias for @ref USBDM::ftm3_ch7
#endif
#if (PTD0_SIG_SEL == 4)
extern const USBDM::Ftm3<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),   4,  0>   ftm3_ch0;
#define pwmIO_D10                ftm3_ch0             //!< Alias for @ref USBDM::ftm3_ch0
#endif
#if (PTD1_SIG_SEL == 4)
extern const USBDM::Ftm3<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  1>   ftm3_ch1;
#define pwmIO_D13                ftm3_ch1             //!< Alias for @ref USBDM::ftm3_ch1
#endif
#if (PTD2_SIG_SEL == 4)
extern const USBDM::Ftm3<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  2>   ftm3_ch2;
#define pwmIO_D11                ftm3_ch2             //!< Alias for @ref USBDM::ftm3_ch2
#endif
#if (PTD3_SIG_SEL == 4)
extern const USBDM::Ftm3<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  3>   ftm3_ch3;
#define pwmIO_D12                ftm3_ch3             //!< Alias for @ref USBDM::ftm3_ch3
#endif
#if (PTD4_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm0_ch4;
#define pwmIO_nRF24L01_cs        ftm0_ch4             //!< Alias for @ref USBDM::ftm0_ch4
#endif
#if (PTD5_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm0_ch5;
#define pwmIO_nRF24L01_sck       ftm0_ch5             //!< Alias for @ref USBDM::ftm0_ch5
#endif
#if (PTD6_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   4,  6>   ftm0_ch6;
#define pwmIO_nRF24L01_mosi      ftm0_ch6             //!< Alias for @ref USBDM::ftm0_ch6
#endif
#if (PTD7_SIG_SEL == 4)
extern const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),   4,  7>   ftm0_ch7;
#define pwmIO_nRF24L01_miso      ftm0_ch7             //!< Alias for @ref USBDM::ftm0_ch7
#endif
#if (PTE5_SIG_SEL == 6)
extern const USBDM::Ftm3<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[5]),   6,  0>   ftm3_ch0;
#endif
#if (PTE6_SIG_SEL == 6)
extern const USBDM::Ftm3<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[6]),   6,  1>   ftm3_ch1;
#endif
#if (PTE7_SIG_SEL == 6)
extern const USBDM::Ftm3<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[7]),   6,  2>   ftm3_ch2;
#endif
#if (PTE8_SIG_SEL == 6)
extern const USBDM::Ftm3<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[8]),   6,  3>   ftm3_ch3;
#endif
#if (PTE9_SIG_SEL == 6)
extern const USBDM::Ftm3<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[9]),   6,  4>   ftm3_ch4;
#endif
#if (PTE10_SIG_SEL == 6)
extern const USBDM::Ftm3<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[10]),  6,  5>   ftm3_ch5;
#endif
#if (PTE11_SIG_SEL == 6)
extern const USBDM::Ftm3<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[11]),  6,  6>   ftm3_ch6;
#endif
#if (PTE12_SIG_SEL == 6)
extern const USBDM::Ftm3<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[12]),  6,  7>   ftm3_ch7;
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
ADC1       SCGC3        SIM_SCGC3_ADC1_MASK
CMP        SCGC4        SIM_SCGC4_CMP_MASK
CMT        SCGC4        SIM_SCGC4_CMT_MASK
DAC0       SCGC6        SIM_SCGC6_DAC0_MASK
DAC1       SCGC2        SIM_SCGC2_DAC1_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX     SCGC6        SIM_SCGC6_DMAMUX_MASK
ENET       SCGC2        SIM_SCGC2_ENET_MASK
EWM        SCGC4        SIM_SCGC4_EWM_MASK
FLEXBUS    SCGC7        SIM_SCGC7_FLEXBUS_MASK
FLEXCAN    SCGC6        SIM_SCGC6_FLEXCAN_MASK
FTM0       SCGC6        SIM_SCGC6_FTM0_MASK
FTM1       SCGC6        SIM_SCGC6_FTM1_MASK
FTM2       SCGC6        SIM_SCGC6_FTM2_MASK
FTM3       SCGC3        SIM_SCGC3_FTM3_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2C1       SCGC4        SIM_SCGC4_I2C1_MASK
I2C2       SCGC1        SIM_SCGC1_I2C2_MASK
I2S0       SCGC6        SIM_SCGC6_I2S0_MASK
LPTMR0     SCGC5        SIM_SCGC5_LPTMR_MASK
MPU        SCGC7        SIM_SCGC7_MPU_MASK
PDB0       SCGC6        SIM_SCGC6_PDB0_MASK
PIT        SCGC6        SIM_SCGC6_PIT_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
RNGA       SCGC6        SIM_SCGC6_RNGA_MASK
RTC        SCGC6        SIM_SCGC6_RTC_MASK
SDHC0      SCGC3        SIM_SCGC3_SDHC0_MASK
SPI0       SCGC6        SIM_SCGC6_SPI0_MASK
SPI1       SCGC6        SIM_SCGC6_SPI1_MASK
SPI2       SCGC3        SIM_SCGC3_SPI2_MASK
UART0      SCGC4        SIM_SCGC4_UART0_MASK
UART1      SCGC4        SIM_SCGC4_UART1_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
UART3      SCGC4        SIM_SCGC4_UART3_MASK
UART4      SCGC1        SIM_SCGC1_UART4_MASK
UART5      SCGC1        SIM_SCGC1_UART5_MASK
USBDCD     SCGC6        SIM_SCGC6_USBDCD_MASK
USBOTG     SCGC4        SIM_SCGC4_USBOTG_MASK
VREF       SCGC4        SIM_SCGC4_VREF_MASK
*/

#if USBDM_USE_NAMESPACES
} // End namespace USBDM
#endif

#endif /* GPIO_H_ */
