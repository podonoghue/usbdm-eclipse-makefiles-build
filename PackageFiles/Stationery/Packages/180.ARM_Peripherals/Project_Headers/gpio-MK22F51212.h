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

namespace USBDM {
/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
const USBDM::GpioA<0>     gpioA_0;
const USBDM::GpioA<1>     gpioA_1;
const USBDM::GpioA<1>     gpio_D9;
const USBDM::GpioA<1>     gpio_J2_4;
const USBDM::GpioA<1>     gpio_LED_RED;
const USBDM::GpioA<2>     gpioA_2;
const USBDM::GpioA<2>     gpio_D3;
const USBDM::GpioA<2>     gpio_J1_8;
const USBDM::GpioA<2>     gpio_LED_GREEN;
const USBDM::GpioA<3>     gpioA_3;
const USBDM::GpioA<4>     gpioA_4;
const USBDM::GpioA<4>     gpio_D4;
const USBDM::GpioA<4>     gpio_J1_10;
const USBDM::GpioA<5>     gpioA_5;
const USBDM::GpioA<5>     gpio_J1_1;
const USBDM::GpioA<12>    gpioA_12;
const USBDM::GpioA<12>    gpio_J1_5;
const USBDM::GpioA<13>    gpioA_13;
const USBDM::GpioA<13>    gpio_J1_3;
const USBDM::GpioA<14>    gpioA_14;
const USBDM::GpioA<15>    gpioA_15;
const USBDM::GpioA<16>    gpioA_16;
const USBDM::GpioA<17>    gpioA_17;
const USBDM::GpioA<18>    gpioA_18;
const USBDM::GpioA<19>    gpioA_19;
const USBDM::GpioB<0>     gpioB_0;
const USBDM::GpioB<0>     gpio_A0;
const USBDM::GpioB<0>     gpio_J24_2;
const USBDM::GpioB<1>     gpioB_1;
const USBDM::GpioB<1>     gpio_A1;
const USBDM::GpioB<1>     gpio_J24_4;
const USBDM::GpioB<2>     gpioB_2;
const USBDM::GpioB<2>     gpio_A5;
const USBDM::GpioB<2>     gpio_J24_12;
const USBDM::GpioB<2>     gpio_ONBOARD_SCL;
const USBDM::GpioB<3>     gpioB_3;
const USBDM::GpioB<3>     gpio_A4;
const USBDM::GpioB<3>     gpio_J24_10;
const USBDM::GpioB<3>     gpio_ONBOARD_SDA;
const USBDM::GpioB<6>     gpioB_6;
const USBDM::GpioB<7>     gpioB_7;
const USBDM::GpioB<8>     gpioB_8;
const USBDM::GpioB<9>     gpioB_9;
const USBDM::GpioB<10>    gpioB_10;
const USBDM::GpioB<11>    gpioB_11;
const USBDM::GpioB<16>    gpioB_16;
const USBDM::GpioB<16>    gpio_D2;
const USBDM::GpioB<16>    gpio_J1_6;
const USBDM::GpioB<17>    gpioB_17;
const USBDM::GpioB<18>    gpioB_18;
const USBDM::GpioB<18>    gpio_D5;
const USBDM::GpioB<18>    gpio_J1_12;
const USBDM::GpioB<19>    gpioB_19;
const USBDM::GpioB<19>    gpio_D8;
const USBDM::GpioB<19>    gpio_J2_2;
const USBDM::GpioB<20>    gpioB_20;
const USBDM::GpioB<21>    gpioB_21;
const USBDM::GpioB<22>    gpioB_22;
const USBDM::GpioB<23>    gpioB_23;
const USBDM::GpioC<0>     gpioC_0;
const USBDM::GpioC<1>     gpioC_1;
const USBDM::GpioC<1>     gpio_A2;
const USBDM::GpioC<1>     gpio_J24_6;
const USBDM::GpioC<2>     gpioC_2;
const USBDM::GpioC<2>     gpio_A3;
const USBDM::GpioC<2>     gpio_J24_8;
const USBDM::GpioC<3>     gpioC_3;
const USBDM::GpioC<3>     gpio_D6;
const USBDM::GpioC<3>     gpio_J1_14;
const USBDM::GpioC<4>     gpioC_4;
const USBDM::GpioC<4>     gpio_J24_9;
const USBDM::GpioC<5>     gpioC_5;
const USBDM::GpioC<5>     gpio_J1_15;
const USBDM::GpioC<6>     gpioC_6;
const USBDM::GpioC<6>     gpio_D7;
const USBDM::GpioC<6>     gpio_J1_16;
const USBDM::GpioC<7>     gpioC_7;
const USBDM::GpioC<7>     gpio_J1_11;
const USBDM::GpioC<8>     gpioC_8;
const USBDM::GpioC<8>     gpio_J1_7;
const USBDM::GpioC<9>     gpioC_9;
const USBDM::GpioC<9>     gpio_J1_9;
const USBDM::GpioC<10>    gpioC_10;
const USBDM::GpioC<10>    gpio_J1_13;
const USBDM::GpioC<11>    gpioC_11;
const USBDM::GpioC<12>    gpioC_12;
const USBDM::GpioC<13>    gpioC_13;
const USBDM::GpioC<14>    gpioC_14;
const USBDM::GpioC<15>    gpioC_15;
const USBDM::GpioC<16>    gpioC_16;
const USBDM::GpioC<17>    gpioC_17;
const USBDM::GpioC<18>    gpioC_18;
const USBDM::GpioC<19>    gpioC_19;
const USBDM::GpioD<0>     gpioD_0;
const USBDM::GpioD<1>     gpioD_1;
const USBDM::GpioD<2>     gpioD_2;
const USBDM::GpioD<2>     gpio_D0;
const USBDM::GpioD<2>     gpio_J1_2;
const USBDM::GpioD<3>     gpioD_3;
const USBDM::GpioD<3>     gpio_D1;
const USBDM::GpioD<3>     gpio_J1_4;
const USBDM::GpioD<4>     gpioD_4;
const USBDM::GpioD<4>     gpio_D10;
const USBDM::GpioD<4>     gpio_J2_6;
const USBDM::GpioD<5>     gpioD_5;
const USBDM::GpioD<5>     gpio_D13;
const USBDM::GpioD<5>     gpio_J2_12;
const USBDM::GpioD<5>     gpio_LED_BLUE;
const USBDM::GpioD<6>     gpioD_6;
const USBDM::GpioD<6>     gpio_D11;
const USBDM::GpioD<6>     gpio_J2_8;
const USBDM::GpioD<7>     gpioD_7;
const USBDM::GpioD<7>     gpio_D12;
const USBDM::GpioD<7>     gpio_J2_10;
const USBDM::GpioE<0>     gpioE_0;
const USBDM::GpioE<0>     gpio_D14;
const USBDM::GpioE<0>     gpio_J2_18;
const USBDM::GpioE<0>     gpio_ConTx;
const USBDM::GpioE<1>     gpioE_1;
const USBDM::GpioE<1>     gpio_D15;
const USBDM::GpioE<1>     gpio_J2_19;
const USBDM::GpioE<1>     gpio_ConRx;
const USBDM::GpioE<2>     gpioE_2;
const USBDM::GpioE<3>     gpioE_3;
const USBDM::GpioE<4>     gpioE_4;
const USBDM::GpioE<5>     gpioE_5;
const USBDM::GpioE<6>     gpioE_6;
const USBDM::GpioE<24>    gpioE_24;
const USBDM::GpioE<25>    gpioE_25;
const USBDM::GpioE<26>    gpioE_26;
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
const USBDM::Adc0<0,                0,                                         19> adc0_se19;
const USBDM::Adc0<0,                0,                                         19> adc_J24_3;
const USBDM::Adc0<0,                0,                                         20> adc0_se20;
const USBDM::Adc1<0,                0,                                         19> adc1_se19;
const USBDM::Adc1<0,                0,                                         19> adc_J24_7;
const USBDM::Adc0<0,                0,                                          0> adc0_se0;
const USBDM::Adc0<0,                0,                                          0> adc_J24_1;
const USBDM::Adc0<0,                0,                                          1> adc0_se1;
const USBDM::Adc1<0,                0,                                          0> adc1_se0;
const USBDM::Adc1<0,                0,                                          0> adc_J24_5;
const USBDM::Adc0<0,                0,                                          3> adc0_se3;
//const USBDM::Adc0<0,                0,                                          3> adc_J24_5;
const USBDM::Adc0<0,                0,                                         23> adc0_se23;
const USBDM::Adc0<0,                0,                                         23> adc_J24_11;
const USBDM::Adc1<0,                0,                                         20> adc1_se20;
const USBDM::Adc1<0,                0,                                          1> adc1_se1;
const USBDM::Adc0<0,                0,                                          2> adc0_se2;
const USBDM::Adc1<0,                0,                                         18> adc1_se18;
const USBDM::Adc1<0,                0,                                         23> adc1_se23;
#if (PTA17_SIG_SEL == 0)
const USBDM::Adc1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[17]), 17> adc1_se17;
#endif
#if (PTB0_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc0_se8;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc_A0;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc_J24_2;
#endif
#if (PTB0_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc1_se8;
//const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc_A0;
//const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc_J24_2;
#endif
#if (PTB1_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc0_se9;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc_A1;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc_J24_4;
#endif
#if (PTB1_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc1_se9;
//const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc_A1;
//const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc_J24_4;
#endif
#if (PTB2_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc0_se12;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc_A5;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc_J24_12;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc_ONBOARD_SCL;
#endif
#if (PTB3_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc0_se13;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc_A4;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc_J24_10;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc_ONBOARD_SDA;
#endif
#if (PTB6_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[6]),  12> adc1_se12;
#endif
#if (PTB7_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[7]),  13> adc1_se13;
#endif
#if (PTB10_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[10]), 14> adc1_se14;
#endif
#if (PTB11_SIG_SEL == 0)
const USBDM::Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[11]), 15> adc1_se15;
#endif
#if (PTC0_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc0_se14;
#endif
#if (PTC1_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc0_se15;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc_A2;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc_J24_6;
#endif
#if (PTC2_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4> adc0_se4;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4> adc_A3;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4> adc_J24_8;
#endif
#if (PTC8_SIG_SEL == 0)
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),   4> adc1_se4;
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),   4> adc_J1_7;
#endif
#if (PTC9_SIG_SEL == 0)
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),   5> adc1_se5;
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),   5> adc_J1_9;
#endif
#if (PTC10_SIG_SEL == 0)
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]),  6> adc1_se6;
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]),  6> adc_J1_13;
#endif
#if (PTC11_SIG_SEL == 0)
const USBDM::Adc1<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]),  7> adc1_se7;
#endif
#if (PTD1_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc0_se5;
#endif
#if (PTD5_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc0_se6;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc_D13;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc_J2_12;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc_LED_BLUE;
#endif
#if (PTD6_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc0_se7;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc_D11;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc_J2_8;
#endif
#if (PTE0_SIG_SEL == 0)
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),   4> adc1_se4;
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),   4> adc_D14;
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),   4> adc_J2_18;
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),   4> adc_ConTx;
#endif
#if (PTE1_SIG_SEL == 0)
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc1_se5;
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc_D15;
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc_J2_19;
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc_ConRx;
#endif
#if (PTE2_SIG_SEL == 0)
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[2]),   6> adc1_se6;
#endif
#if (PTE3_SIG_SEL == 0)
const USBDM::Adc1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[3]),   7> adc1_se7;
#endif
#if (PTE24_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), 17> adc0_se17;
#endif
#if (PTE25_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), 18> adc0_se18;
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
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  5>   ftm0_ch5;
#endif
#if (PTA1_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm0_ch6;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm_D9;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm_J2_4;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm_LED_RED;
#endif
#if (PTA2_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm0_ch7;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm_D3;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm_J1_8;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  7>   ftm_LED_GREEN;
#endif
#if (PTA3_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),   3,  0>   ftm0_ch0;
#endif
#if (PTA4_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   ftm0_ch1;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   ftm_D4;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   ftm_J1_10;
#endif
#if (PTA5_SIG_SEL == 3)
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   ftm0_ch2;
const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   ftm_J1_1;
#endif
#if (PTA12_SIG_SEL == 3)
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   ftm1_ch0;
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   ftm_J1_5;
#endif
#if (PTA13_SIG_SEL == 3)
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   ftm1_ch1;
const USBDM::Ftm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   ftm_J1_3;
#endif
#if (PTB0_SIG_SEL == 3)
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm1_ch0;
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm_A0;
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   ftm_J24_2;
#endif
#if (PTB1_SIG_SEL == 3)
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm1_ch1;
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm_A1;
const USBDM::Ftm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   ftm_J24_4;
#endif
#if (PTB18_SIG_SEL == 3)
const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]),  3,  0>   ftm2_ch0;
const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]),  3,  0>   ftm_D5;
const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]),  3,  0>   ftm_J1_12;
#endif
#if (PTB19_SIG_SEL == 3)
const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]),  3,  1>   ftm2_ch1;
const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]),  3,  1>   ftm_D8;
const USBDM::Ftm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]),  3,  1>   ftm_J2_2;
#endif
#if (PTC1_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   ftm0_ch0;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   ftm_A2;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   ftm_J24_6;
#endif
#if (PTC2_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   ftm0_ch1;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   ftm_A3;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   ftm_J24_8;
#endif
#if (PTC3_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm0_ch2;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm_D6;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   ftm_J1_14;
#endif
#if (PTC4_SIG_SEL == 4)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   ftm0_ch3;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   ftm_J24_9;
#endif
#if (PTC5_SIG_SEL == 7)
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),   7,  2>   ftm0_ch2;
const USBDM::Ftm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),   7,  2>   ftm_J1_15;
#endif
#if (PTD4_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm0_ch4;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm_D10;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   ftm_J2_6;
#endif
#if (PTD5_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm0_ch5;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm_D13;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm_J2_12;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   ftm_LED_BLUE;
#endif
#if (PTD6_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   4,  6>   ftm0_ch6;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   4,  6>   ftm_D11;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   4,  6>   ftm_J2_8;
#endif
#if (PTD7_SIG_SEL == 4)
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),   4,  7>   ftm0_ch7;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),   4,  7>   ftm_D12;
const USBDM::Ftm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),   4,  7>   ftm_J2_10;
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

} // End namespace USBDM

#endif /* GPIO_H_ */
