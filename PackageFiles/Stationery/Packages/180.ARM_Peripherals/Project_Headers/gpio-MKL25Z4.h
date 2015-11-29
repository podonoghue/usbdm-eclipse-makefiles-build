/**
 * @file      gpio.h (derived from gpio-MKL25Z4.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKL25Z4
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
const USBDM::GpioA<1>     gpio_D0;
const USBDM::GpioA<2>     gpioA_2;
const USBDM::GpioA<2>     gpio_D1;
const USBDM::GpioA<3>     gpioA_3;
const USBDM::GpioA<4>     gpioA_4;
const USBDM::GpioA<4>     gpio_D4;
const USBDM::GpioA<5>     gpioA_5;
const USBDM::GpioA<5>     gpio_D5;
const USBDM::GpioA<12>    gpioA_12;
const USBDM::GpioA<12>    gpio_D3;
const USBDM::GpioA<13>    gpioA_13;
const USBDM::GpioA<13>    gpio_D8;
const USBDM::GpioA<14>    gpioA_14;
const USBDM::GpioA<15>    gpioA_15;
const USBDM::GpioA<16>    gpioA_16;
const USBDM::GpioA<16>    gpio_D28;
const USBDM::GpioA<17>    gpioA_17;
const USBDM::GpioA<17>    gpio_D29;
const USBDM::GpioA<18>    gpioA_18;
const USBDM::GpioA<19>    gpioA_19;
const USBDM::GpioA<20>    gpioA_20;
const USBDM::GpioB<0>     gpioB_0;
const USBDM::GpioB<0>     gpio_A0;
const USBDM::GpioB<1>     gpioB_1;
const USBDM::GpioB<1>     gpio_A1;
const USBDM::GpioB<2>     gpioB_2;
const USBDM::GpioB<2>     gpio_A2;
const USBDM::GpioB<3>     gpioB_3;
const USBDM::GpioB<3>     gpio_A3;
const USBDM::GpioB<8>     gpioB_8;
const USBDM::GpioB<8>     gpio_A20;
const USBDM::GpioB<9>     gpioB_9;
const USBDM::GpioB<9>     gpio_A19;
const USBDM::GpioB<10>    gpioB_10;
const USBDM::GpioB<10>    gpio_A18;
const USBDM::GpioB<11>    gpioB_11;
const USBDM::GpioB<11>    gpio_A17;
const USBDM::GpioB<16>    gpioB_16;
const USBDM::GpioB<17>    gpioB_17;
const USBDM::GpioB<18>    gpioB_18;
const USBDM::GpioB<18>    gpio_LED_RED;
const USBDM::GpioB<19>    gpioB_19;
const USBDM::GpioB<19>    gpio_LED_GREEN;
const USBDM::GpioC<0>     gpioC_0;
const USBDM::GpioC<0>     gpio_D17;
const USBDM::GpioC<1>     gpioC_1;
const USBDM::GpioC<1>     gpio_A5;
const USBDM::GpioC<2>     gpioC_2;
const USBDM::GpioC<2>     gpio_A4;
const USBDM::GpioC<3>     gpioC_3;
const USBDM::GpioC<3>     gpio_D18;
const USBDM::GpioC<4>     gpioC_4;
const USBDM::GpioC<4>     gpio_D19;
const USBDM::GpioC<5>     gpioC_5;
const USBDM::GpioC<5>     gpio_D20;
const USBDM::GpioC<6>     gpioC_6;
const USBDM::GpioC<6>     gpio_D21;
const USBDM::GpioC<7>     gpioC_7;
const USBDM::GpioC<7>     gpio_D16;
const USBDM::GpioC<8>     gpioC_8;
const USBDM::GpioC<8>     gpio_D6;
const USBDM::GpioC<9>     gpioC_9;
const USBDM::GpioC<9>     gpio_D7;
const USBDM::GpioC<10>    gpioC_10;
const USBDM::GpioC<10>    gpio_D22;
const USBDM::GpioC<11>    gpioC_11;
const USBDM::GpioC<11>    gpio_D23;
const USBDM::GpioC<12>    gpioC_12;
const USBDM::GpioC<12>    gpio_D24;
const USBDM::GpioC<13>    gpioC_13;
const USBDM::GpioC<13>    gpio_D25;
const USBDM::GpioC<16>    gpioC_16;
const USBDM::GpioC<16>    gpio_D26;
const USBDM::GpioC<17>    gpioC_17;
const USBDM::GpioC<17>    gpio_D27;
const USBDM::GpioD<0>     gpioD_0;
const USBDM::GpioD<0>     gpio_D10;
const USBDM::GpioD<1>     gpioD_1;
const USBDM::GpioD<1>     gpio_D13;
const USBDM::GpioD<1>     gpio_LED_BLUE;
const USBDM::GpioD<2>     gpioD_2;
const USBDM::GpioD<2>     gpio_D11;
const USBDM::GpioD<3>     gpioD_3;
const USBDM::GpioD<3>     gpio_D12;
const USBDM::GpioD<4>     gpioD_4;
const USBDM::GpioD<4>     gpio_D2;
const USBDM::GpioD<5>     gpioD_5;
const USBDM::GpioD<5>     gpio_D9;
const USBDM::GpioD<6>     gpioD_6;
const USBDM::GpioD<6>     gpio_D32;
const USBDM::GpioD<7>     gpioD_7;
const USBDM::GpioD<7>     gpio_D33;
const USBDM::GpioE<0>     gpioE_0;
const USBDM::GpioE<0>     gpio_D15;
const USBDM::GpioE<1>     gpioE_1;
const USBDM::GpioE<1>     gpio_D14;
const USBDM::GpioE<2>     gpioE_2;
const USBDM::GpioE<2>     gpio_A16;
const USBDM::GpioE<3>     gpioE_3;
const USBDM::GpioE<3>     gpio_A15;
const USBDM::GpioE<4>     gpioE_4;
const USBDM::GpioE<4>     gpio_A14;
const USBDM::GpioE<5>     gpioE_5;
const USBDM::GpioE<5>     gpio_A13;
const USBDM::GpioE<20>    gpioE_20;
const USBDM::GpioE<20>    gpio_A11;
const USBDM::GpioE<21>    gpioE_21;
const USBDM::GpioE<21>    gpio_A10;
const USBDM::GpioE<22>    gpioE_22;
const USBDM::GpioE<22>    gpio_A9;
const USBDM::GpioE<23>    gpioE_23;
const USBDM::GpioE<23>    gpio_A8;
const USBDM::GpioE<24>    gpioE_24;
const USBDM::GpioE<24>    gpio_ACCEL_SCL;
const USBDM::GpioE<25>    gpioE_25;
const USBDM::GpioE<25>    gpio_ACCEL_SDA;
const USBDM::GpioE<29>    gpioE_29;
const USBDM::GpioE<29>    gpio_A7;
const USBDM::GpioE<30>    gpioE_30;
const USBDM::GpioE<30>    gpio_A6;
const USBDM::GpioE<31>    gpioE_31;
const USBDM::GpioE<31>    gpio_D30;
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTB0_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc0_se8;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   8> adc_A0;
#endif
#if (PTB1_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc0_se9;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   9> adc_A1;
#endif
#if (PTB2_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc0_se12;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  12> adc_A2;
#endif
#if (PTB3_SIG_SEL == 0)
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc0_se13;
const USBDM::Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  13> adc_A3;
#endif
#if (PTC0_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc0_se14;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  14> adc_D17;
#endif
#if (PTC1_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc0_se15;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  15> adc_A5;
#endif
#if (PTC2_SIG_SEL == 0)
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  11> adc0_se11;
const USBDM::Adc0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  11> adc_A4;
#endif
#if (PTD1_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc0_se5;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc_D13;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   5> adc_LED_BLUE;
#endif
#if (PTD5_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc0_se6;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   6> adc_D9;
#endif
#if (PTD6_SIG_SEL == 0)
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc0_se7;
const USBDM::Adc0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),   7> adc_D32;
#endif
#if (PTE20_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]),  0> adc0_se0;
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]),  0> adc_A11;
#endif
#if (PTE21_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]),  4> adc0_se4;
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]),  4> adc_A10;
#endif
#if (PTE22_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]),  3> adc0_se3;
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]),  3> adc_A9;
#endif
#if (PTE23_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]),  7> adc0_se7;
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]),  7> adc_A8;
#endif
#if (PTE29_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]),  4> adc0_se4;
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]),  4> adc_A7;
#endif
#if (PTE30_SIG_SEL == 0)
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), 23> adc0_se23;
const USBDM::Adc0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), 23> adc_A6;
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
const USBDM::Tpm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  5>   tpm0_ch5;
#endif
#if (PTA1_SIG_SEL == 3)
const USBDM::Tpm2<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  0>   tpm2_ch0;
const USBDM::Tpm2<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  0>   tpm_D0;
#endif
#if (PTA2_SIG_SEL == 3)
const USBDM::Tpm2<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  1>   tpm2_ch1;
const USBDM::Tpm2<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  1>   tpm_D1;
#endif
#if (PTA3_SIG_SEL == 3)
const USBDM::Tpm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),   3,  0>   tpm0_ch0;
#endif
#if (PTA4_SIG_SEL == 3)
const USBDM::Tpm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   tpm0_ch1;
const USBDM::Tpm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),   3,  1>   tpm_D4;
#endif
#if (PTA5_SIG_SEL == 3)
const USBDM::Tpm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   tpm0_ch2;
const USBDM::Tpm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),   3,  2>   tpm_D5;
#endif
#if (PTA12_SIG_SEL == 3)
const USBDM::Tpm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   tpm1_ch0;
const USBDM::Tpm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]),  3,  0>   tpm_D3;
#endif
#if (PTA13_SIG_SEL == 3)
const USBDM::Tpm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   tpm1_ch1;
const USBDM::Tpm1<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]),  3,  1>   tpm_D8;
#endif
#if (PTB0_SIG_SEL == 3)
const USBDM::Tpm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   tpm1_ch0;
const USBDM::Tpm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),   3,  0>   tpm_A0;
#endif
#if (PTB1_SIG_SEL == 3)
const USBDM::Tpm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   tpm1_ch1;
const USBDM::Tpm1<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  1>   tpm_A1;
#endif
#if (PTB2_SIG_SEL == 3)
const USBDM::Tpm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  0>   tpm2_ch0;
const USBDM::Tpm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),   3,  0>   tpm_A2;
#endif
#if (PTB3_SIG_SEL == 3)
const USBDM::Tpm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),   3,  1>   tpm2_ch1;
const USBDM::Tpm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),   3,  1>   tpm_A3;
#endif
#if (PTB18_SIG_SEL == 3)
const USBDM::Tpm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]),  3,  0>   tpm2_ch0;
const USBDM::Tpm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]),  3,  0>   tpm_LED_RED;
#endif
#if (PTB19_SIG_SEL == 3)
const USBDM::Tpm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]),  3,  1>   tpm2_ch1;
const USBDM::Tpm2<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]),  3,  1>   tpm_LED_GREEN;
#endif
#if (PTC1_SIG_SEL == 4)
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   tpm0_ch0;
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  0>   tpm_A5;
#endif
#if (PTC2_SIG_SEL == 4)
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   tpm0_ch1;
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  1>   tpm_A4;
#endif
#if (PTC3_SIG_SEL == 4)
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   tpm0_ch2;
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  2>   tpm_D18;
#endif
#if (PTC4_SIG_SEL == 4)
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   tpm0_ch3;
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  3>   tpm_D19;
#endif
#if (PTC8_SIG_SEL == 3)
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),   3,  4>   tpm0_ch4;
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),   3,  4>   tpm_D6;
#endif
#if (PTC9_SIG_SEL == 3)
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),   3,  5>   tpm0_ch5;
const USBDM::Tpm0<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),   3,  5>   tpm_D7;
#endif
#if (PTD0_SIG_SEL == 4)
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),   4,  0>   tpm0_ch0;
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),   4,  0>   tpm_D10;
#endif
#if (PTD1_SIG_SEL == 4)
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  1>   tpm0_ch1;
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  1>   tpm_D13;
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),   4,  1>   tpm_LED_BLUE;
#endif
#if (PTD2_SIG_SEL == 4)
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  2>   tpm0_ch2;
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),   4,  2>   tpm_D11;
#endif
#if (PTD3_SIG_SEL == 4)
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  3>   tpm0_ch3;
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),   4,  3>   tpm_D12;
#endif
#if (PTD4_SIG_SEL == 4)
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   tpm0_ch4;
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),   4,  4>   tpm_D2;
#endif
#if (PTD5_SIG_SEL == 4)
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   tpm0_ch5;
const USBDM::Tpm0<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),   4,  5>   tpm_D9;
#endif
#if (PTE20_SIG_SEL == 3)
const USBDM::Tpm1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]),  3,  0>   tpm1_ch0;
const USBDM::Tpm1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]),  3,  0>   tpm_A11;
#endif
#if (PTE21_SIG_SEL == 3)
const USBDM::Tpm1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]),  3,  1>   tpm1_ch1;
const USBDM::Tpm1<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]),  3,  1>   tpm_A10;
#endif
#if (PTE22_SIG_SEL == 3)
const USBDM::Tpm2<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]),  3,  0>   tpm2_ch0;
const USBDM::Tpm2<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]),  3,  0>   tpm_A9;
#endif
#if (PTE23_SIG_SEL == 3)
const USBDM::Tpm2<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]),  3,  1>   tpm2_ch1;
const USBDM::Tpm2<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]),  3,  1>   tpm_A8;
#endif
#if (PTE24_SIG_SEL == 3)
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]),  3,  0>   tpm0_ch0;
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]),  3,  0>   tpm_ACCEL_SCL;
#endif
#if (PTE25_SIG_SEL == 3)
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]),  3,  1>   tpm0_ch1;
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]),  3,  1>   tpm_ACCEL_SDA;
#endif
#if (PTE29_SIG_SEL == 3)
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]),  3,  2>   tpm0_ch2;
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]),  3,  2>   tpm_A7;
#endif
#if (PTE30_SIG_SEL == 3)
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]),  3,  3>   tpm0_ch3;
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]),  3,  3>   tpm_A6;
#endif
#if (PTE31_SIG_SEL == 3)
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[31]),  3,  4>   tpm0_ch4;
const USBDM::Tpm0<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[31]),  3,  4>   tpm_D30;
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
CMP        SCGC4        SIM_SCGC4_CMP_MASK
DAC0       SCGC6        SIM_SCGC6_DAC0_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX     SCGC6        SIM_SCGC6_DMAMUX_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2C1       SCGC4        SIM_SCGC4_I2C1_MASK
LPTMR0     SCGC5        SIM_SCGC5_LPTMR_MASK
PIT        SCGC6        SIM_SCGC6_PIT_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
RTC        SCGC6        SIM_SCGC6_RTC_MASK
SPI0       SCGC4        SIM_SCGC4_SPI0_MASK
SPI1       SCGC4        SIM_SCGC4_SPI1_MASK
TPM0       SCGC6        SIM_SCGC6_TPM0_MASK
TPM1       SCGC6        SIM_SCGC6_TPM1_MASK
TPM2       SCGC6        SIM_SCGC6_TPM2_MASK
TSI        SCGC5        SIM_SCGC5_TSI_MASK
UART0      SCGC4        SIM_SCGC4_UART0_MASK
UART1      SCGC4        SIM_SCGC4_UART1_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
USBOTG     SCGC4        SIM_SCGC4_USBOTG_MASK
*/

} // End namespace USBDM

#endif /* GPIO_H_ */
