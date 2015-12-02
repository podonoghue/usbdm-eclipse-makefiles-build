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
using gpioA_0              = const USBDM::GpioA<0>;
using gpioA_1              = const USBDM::GpioA<1>;
using gpio_D9              = const USBDM::GpioA<1>;
using gpio_J2_4            = const USBDM::GpioA<1>;
using gpio_LED_RED         = const USBDM::GpioA<1>;
using gpioA_2              = const USBDM::GpioA<2>;
using gpio_D3              = const USBDM::GpioA<2>;
using gpio_J1_8            = const USBDM::GpioA<2>;
using gpio_LED_GREEN       = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpio_D4              = const USBDM::GpioA<4>;
using gpio_J1_10           = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpio_J1_1            = const USBDM::GpioA<5>;
using gpioA_12             = const USBDM::GpioA<12>;
using gpio_J1_5            = const USBDM::GpioA<12>;
using gpioA_13             = const USBDM::GpioA<13>;
using gpio_J1_3            = const USBDM::GpioA<13>;
using gpioA_14             = const USBDM::GpioA<14>;
using gpioA_15             = const USBDM::GpioA<15>;
using gpioA_16             = const USBDM::GpioA<16>;
using gpioA_17             = const USBDM::GpioA<17>;
using gpioA_18             = const USBDM::GpioA<18>;
using gpioA_19             = const USBDM::GpioA<19>;
using gpioB_0              = const USBDM::GpioB<0>;
using gpio_A0              = const USBDM::GpioB<0>;
using gpio_J24_2           = const USBDM::GpioB<0>;
using gpioB_1              = const USBDM::GpioB<1>;
using gpio_A1              = const USBDM::GpioB<1>;
using gpio_J24_4           = const USBDM::GpioB<1>;
using gpioB_2              = const USBDM::GpioB<2>;
using gpio_A5              = const USBDM::GpioB<2>;
using gpio_J24_12          = const USBDM::GpioB<2>;
using gpio_ONBOARD_SCL     = const USBDM::GpioB<2>;
using gpioB_3              = const USBDM::GpioB<3>;
using gpio_A4              = const USBDM::GpioB<3>;
using gpio_J24_10          = const USBDM::GpioB<3>;
using gpio_ONBOARD_SDA     = const USBDM::GpioB<3>;
using gpioB_6              = const USBDM::GpioB<6>;
using gpioB_7              = const USBDM::GpioB<7>;
using gpioB_8              = const USBDM::GpioB<8>;
using gpioB_9              = const USBDM::GpioB<9>;
using gpioB_10             = const USBDM::GpioB<10>;
using gpioB_11             = const USBDM::GpioB<11>;
using gpioB_16             = const USBDM::GpioB<16>;
using gpio_D2              = const USBDM::GpioB<16>;
using gpio_J1_6            = const USBDM::GpioB<16>;
using gpioB_17             = const USBDM::GpioB<17>;
using gpioB_18             = const USBDM::GpioB<18>;
using gpio_D5              = const USBDM::GpioB<18>;
using gpio_J1_12           = const USBDM::GpioB<18>;
using gpioB_19             = const USBDM::GpioB<19>;
using gpio_D8              = const USBDM::GpioB<19>;
using gpio_J2_2            = const USBDM::GpioB<19>;
using gpioB_20             = const USBDM::GpioB<20>;
using gpioB_21             = const USBDM::GpioB<21>;
using gpioB_22             = const USBDM::GpioB<22>;
using gpioB_23             = const USBDM::GpioB<23>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpio_A2              = const USBDM::GpioC<1>;
using gpio_J24_6           = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpio_A3              = const USBDM::GpioC<2>;
using gpio_J24_8           = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpio_D6              = const USBDM::GpioC<3>;
using gpio_J1_14           = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpio_J24_9           = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpio_J1_15           = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
using gpio_D7              = const USBDM::GpioC<6>;
using gpio_J1_16           = const USBDM::GpioC<6>;
using gpioC_7              = const USBDM::GpioC<7>;
using gpio_J1_11           = const USBDM::GpioC<7>;
using gpioC_8              = const USBDM::GpioC<8>;
using gpio_J1_7            = const USBDM::GpioC<8>;
using gpioC_9              = const USBDM::GpioC<9>;
using gpio_J1_9            = const USBDM::GpioC<9>;
using gpioC_10             = const USBDM::GpioC<10>;
using gpio_J1_13           = const USBDM::GpioC<10>;
using gpioC_11             = const USBDM::GpioC<11>;
using gpioC_12             = const USBDM::GpioC<12>;
using gpioC_13             = const USBDM::GpioC<13>;
using gpioC_14             = const USBDM::GpioC<14>;
using gpioC_15             = const USBDM::GpioC<15>;
using gpioC_16             = const USBDM::GpioC<16>;
using gpioC_17             = const USBDM::GpioC<17>;
using gpioC_18             = const USBDM::GpioC<18>;
using gpioC_19             = const USBDM::GpioC<19>;
using gpioD_0              = const USBDM::GpioD<0>;
using gpioD_1              = const USBDM::GpioD<1>;
using gpioD_2              = const USBDM::GpioD<2>;
using gpio_D0              = const USBDM::GpioD<2>;
using gpio_J1_2            = const USBDM::GpioD<2>;
using gpioD_3              = const USBDM::GpioD<3>;
using gpio_D1              = const USBDM::GpioD<3>;
using gpio_J1_4            = const USBDM::GpioD<3>;
using gpioD_4              = const USBDM::GpioD<4>;
using gpio_D10             = const USBDM::GpioD<4>;
using gpio_J2_6            = const USBDM::GpioD<4>;
using gpioD_5              = const USBDM::GpioD<5>;
using gpio_D13             = const USBDM::GpioD<5>;
using gpio_J2_12           = const USBDM::GpioD<5>;
using gpio_LED_BLUE        = const USBDM::GpioD<5>;
using gpioD_6              = const USBDM::GpioD<6>;
using gpio_D11             = const USBDM::GpioD<6>;
using gpio_J2_8            = const USBDM::GpioD<6>;
using gpioD_7              = const USBDM::GpioD<7>;
using gpio_D12             = const USBDM::GpioD<7>;
using gpio_J2_10           = const USBDM::GpioD<7>;
using gpioE_0              = const USBDM::GpioE<0>;
using gpio_D14             = const USBDM::GpioE<0>;
using gpio_J2_18           = const USBDM::GpioE<0>;
using gpio_ConTx           = const USBDM::GpioE<0>;
using gpioE_1              = const USBDM::GpioE<1>;
using gpio_D15             = const USBDM::GpioE<1>;
using gpio_J2_19           = const USBDM::GpioE<1>;
using gpio_ConRx           = const USBDM::GpioE<1>;
using gpioE_2              = const USBDM::GpioE<2>;
using gpioE_3              = const USBDM::GpioE<3>;
using gpioE_4              = const USBDM::GpioE<4>;
using gpioE_5              = const USBDM::GpioE<5>;
using gpioE_6              = const USBDM::GpioE<6>;
using gpioE_24             = const USBDM::GpioE<24>;
using gpioE_25             = const USBDM::GpioE<25>;
using gpioE_26             = const USBDM::GpioE<26>;
/**
 * @}
 */
constexpr PcrInfo Adc0Info[32] = {
 /*  0 */  { 0, 0,  0},
 /*  1 */  { 0, 0,  0},
 /*  2 */  { 0, 0,  0},
 /*  3 */  { 0, 0,  0},
#if (PTC2_SIG_SEL == 0)
 /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  0},
#else
 /*  4 */  { 0, 0, 0 },
#endif
#if (PTD1_SIG_SEL == 0)
 /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  0},
#else
 /*  5 */  { 0, 0, 0 },
#endif
#if (PTD5_SIG_SEL == 0)
 /*  6 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  0},
#else
 /*  6 */  { 0, 0, 0 },
#endif
#if (PTD6_SIG_SEL == 0)
 /*  7 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  0},
#else
 /*  7 */  { 0, 0, 0 },
#endif
#if (PTB0_SIG_SEL == 0)
 /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  0},
#else
 /*  8 */  { 0, 0, 0 },
#endif
#if (PTB1_SIG_SEL == 0)
 /*  9 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  0},
#else
 /*  9 */  { 0, 0, 0 },
#endif
 /* 10 */  { 0, 0, 0 },
 /* 11 */  { 0, 0, 0 },
#if (PTB2_SIG_SEL == 0)
 /* 12 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  0},
#else
 /* 12 */  { 0, 0, 0 },
#endif
#if (PTB3_SIG_SEL == 0)
 /* 13 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  0},
#else
 /* 13 */  { 0, 0, 0 },
#endif
#if (PTC0_SIG_SEL == 0)
 /* 14 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  0},
#else
 /* 14 */  { 0, 0, 0 },
#endif
#if (PTC1_SIG_SEL == 0)
 /* 15 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  0},
#else
 /* 15 */  { 0, 0, 0 },
#endif
 /* 16 */  { 0, 0, 0 },
#if (PTE24_SIG_SEL == 0)
 /* 17 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), 0},
#else
 /* 17 */  { 0, 0, 0 },
#endif
#if (PTE25_SIG_SEL == 0)
 /* 18 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), 0},
#else
 /* 18 */  { 0, 0, 0 },
#endif
 /* 19 */  { 0, 0,  0},
 /* 20 */  { 0, 0,  0},
 /* 21 */  { 0, 0, 0 },
 /* 22 */  { 0, 0, 0 },
 /* 23 */  { 0, 0,  0},
};

/**
 * Convenience templated class representing an ADC
 *
 * Example
 * @code
 *  // Instantiate ADC0 single-ended channel #8
 *  const adc0<8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC(USBDM::resolution_12bit_se);
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam adcChannel    ADC channel
 */
template<uint8_t adcChannel> using Adc0 =
   AnalogueIOT<getPortClockMask(adcChannel,Adc0Info), getPcrReg(adcChannel,Adc0Info), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
using adc0_se19            = const USBDM::Adc0<19>;
using adc_J24_3            = const USBDM::Adc0<19>;
using adc0_se20            = const USBDM::Adc0<20>;
using adc0_se0             = const USBDM::Adc0< 0>;
using adc_J24_1            = const USBDM::Adc0< 0>;
using adc0_se1             = const USBDM::Adc0< 1>;
using adc0_se3             = const USBDM::Adc0< 3>;
using adc_J24_5            = const USBDM::Adc0< 3>;
using adc0_se23            = const USBDM::Adc0<23>;
using adc_J24_11           = const USBDM::Adc0<23>;
using adc0_se2             = const USBDM::Adc0< 2>;
#if (PTB0_SIG_SEL == 0)
using adc0_se8             = const USBDM::Adc0< 8>;
using adc_A0               = const USBDM::Adc0< 8>;
using adc_J24_2            = const USBDM::Adc0< 8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc0_se9             = const USBDM::Adc0< 9>;
using adc_A1               = const USBDM::Adc0< 9>;
using adc_J24_4            = const USBDM::Adc0< 9>;
#endif
#if (PTB2_SIG_SEL == 0)
using adc0_se12            = const USBDM::Adc0<12>;
using adc_A5               = const USBDM::Adc0<12>;
using adc_J24_12           = const USBDM::Adc0<12>;
using adc_ONBOARD_SCL      = const USBDM::Adc0<12>;
#endif
#if (PTB3_SIG_SEL == 0)
using adc0_se13            = const USBDM::Adc0<13>;
using adc_A4               = const USBDM::Adc0<13>;
using adc_J24_10           = const USBDM::Adc0<13>;
using adc_ONBOARD_SDA      = const USBDM::Adc0<13>;
#endif
#if (PTC0_SIG_SEL == 0)
using adc0_se14            = const USBDM::Adc0<14>;
#endif
#if (PTC1_SIG_SEL == 0)
using adc0_se15            = const USBDM::Adc0<15>;
using adc_A2               = const USBDM::Adc0<15>;
using adc_J24_6            = const USBDM::Adc0<15>;
#endif
#if (PTC2_SIG_SEL == 0)
using adc0_se4b            = const USBDM::Adc0< 4>;
using adc_A3               = const USBDM::Adc0< 4>;
using adc_J24_8            = const USBDM::Adc0< 4>;
#endif
#if (PTD1_SIG_SEL == 0)
using adc0_se5b            = const USBDM::Adc0< 5>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc0_se6b            = const USBDM::Adc0< 6>;
using adc_D13              = const USBDM::Adc0< 6>;
using adc_J2_12            = const USBDM::Adc0< 6>;
using adc_LED_BLUE         = const USBDM::Adc0< 6>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc0_se7b            = const USBDM::Adc0< 7>;
using adc_D11              = const USBDM::Adc0< 7>;
using adc_J2_8             = const USBDM::Adc0< 7>;
#endif
#if (PTE24_SIG_SEL == 0)
using adc0_se17            = const USBDM::Adc0<17>;
#endif
#if (PTE25_SIG_SEL == 0)
using adc0_se18            = const USBDM::Adc0<18>;
#endif
/**
 * @}
 */
constexpr PcrInfo Adc1Info[32] = {
 /*  0 */  { 0, 0,  0},
 /*  1 */  { 0, 0,  0},
 /*  2 */  { 0, 0, 0 },
 /*  3 */  { 0, 0, 0 },
#if (PTC8_SIG_SEL == 0)
 /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  0},
#else
 /*  4 */  { 0, 0, 0 },
#endif
#if (PTC9_SIG_SEL == 0)
 /*  5 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  0},
#else
 /*  5 */  { 0, 0, 0 },
#endif
#if (PTC10_SIG_SEL == 0)
 /*  6 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]), 0},
#else
 /*  6 */  { 0, 0, 0 },
#endif
#if (PTC11_SIG_SEL == 0)
 /*  7 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]), 0},
#else
 /*  7 */  { 0, 0, 0 },
#endif
#if (PTB0_SIG_SEL == 0)
 /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  0},
#else
 /*  8 */  { 0, 0, 0 },
#endif
#if (PTB1_SIG_SEL == 0)
 /*  9 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  0},
#else
 /*  9 */  { 0, 0, 0 },
#endif
 /* 10 */  { 0, 0, 0 },
 /* 11 */  { 0, 0, 0 },
#if (PTB6_SIG_SEL == 0)
 /* 12 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[6]),  0},
#else
 /* 12 */  { 0, 0, 0 },
#endif
#if (PTB7_SIG_SEL == 0)
 /* 13 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[7]),  0},
#else
 /* 13 */  { 0, 0, 0 },
#endif
#if (PTB10_SIG_SEL == 0)
 /* 14 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[10]), 0},
#else
 /* 14 */  { 0, 0, 0 },
#endif
#if (PTB11_SIG_SEL == 0)
 /* 15 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[11]), 0},
#else
 /* 15 */  { 0, 0, 0 },
#endif
 /* 16 */  { 0, 0, 0 },
#if (PTA17_SIG_SEL == 0)
 /* 17 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[17]), 0},
#else
 /* 17 */  { 0, 0, 0 },
#endif
 /* 18 */  { 0, 0,  0},
 /* 19 */  { 0, 0,  0},
 /* 20 */  { 0, 0,  0},
 /* 21 */  { 0, 0, 0 },
 /* 22 */  { 0, 0, 0 },
 /* 23 */  { 0, 0,  0},
};

/**
 * Convenience templated class representing an ADC
 *
 * Example
 * @code
 *  // Instantiate ADC0 single-ended channel #8
 *  const adc0<8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC(USBDM::resolution_12bit_se);
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam adcChannel    ADC channel
 */
template<uint8_t adcChannel> using Adc1 =
   AnalogueIOT<getPortClockMask(adcChannel,Adc1Info), getPcrReg(adcChannel,Adc1Info), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG), ADC1_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
using adc1_se19            = const USBDM::Adc1<19>;
using adc_J24_7            = const USBDM::Adc1<19>;
using adc1_se0             = const USBDM::Adc1< 0>;
//using adc_J24_5            = const USBDM::Adc1< 0>;
using adc1_se20            = const USBDM::Adc1<20>;
using adc1_se1             = const USBDM::Adc1< 1>;
using adc1_se18            = const USBDM::Adc1<18>;
using adc1_se23            = const USBDM::Adc1<23>;
#if (PTA17_SIG_SEL == 0)
using adc1_se17            = const USBDM::Adc1<17>;
#endif
#if (PTB0_SIG_SEL == 0)
using adc1_se8             = const USBDM::Adc1< 8>;
//using adc_A0               = const USBDM::Adc1< 8>;
//using adc_J24_2            = const USBDM::Adc1< 8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc1_se9             = const USBDM::Adc1< 9>;
//using adc_A1               = const USBDM::Adc1< 9>;
//using adc_J24_4            = const USBDM::Adc1< 9>;
#endif
#if (PTB6_SIG_SEL == 0)
using adc1_se12            = const USBDM::Adc1<12>;
#endif
#if (PTB7_SIG_SEL == 0)
using adc1_se13            = const USBDM::Adc1<13>;
#endif
#if (PTB10_SIG_SEL == 0)
using adc1_se14            = const USBDM::Adc1<14>;
#endif
#if (PTB11_SIG_SEL == 0)
using adc1_se15            = const USBDM::Adc1<15>;
#endif
#if (PTC8_SIG_SEL == 0)
using adc1_se4b            = const USBDM::Adc1< 4>;
using adc_J1_7             = const USBDM::Adc1< 4>;
#endif
#if (PTC9_SIG_SEL == 0)
using adc1_se5b            = const USBDM::Adc1< 5>;
using adc_J1_9             = const USBDM::Adc1< 5>;
#endif
#if (PTC10_SIG_SEL == 0)
using adc1_se6b            = const USBDM::Adc1< 6>;
using adc_J1_13            = const USBDM::Adc1< 6>;
#endif
#if (PTC11_SIG_SEL == 0)
using adc1_se7b            = const USBDM::Adc1< 7>;
#endif
/**
 * @}
 */
constexpr PcrInfo Adc1aInfo[32] = {
 /*  0 */  { 0, 0, 0 },
 /*  1 */  { 0, 0, 0 },
 /*  2 */  { 0, 0, 0 },
 /*  3 */  { 0, 0, 0 },
#if (PTE0_SIG_SEL == 0)
 /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),  0},
#else
 /*  4 */  { 0, 0, 0 },
#endif
#if (PTE1_SIG_SEL == 0)
 /*  5 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),  0},
#else
 /*  5 */  { 0, 0, 0 },
#endif
#if (PTE2_SIG_SEL == 0)
 /*  6 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[2]),  0},
#else
 /*  6 */  { 0, 0, 0 },
#endif
#if (PTE3_SIG_SEL == 0)
 /*  7 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[3]),  0},
#else
 /*  7 */  { 0, 0, 0 },
#endif
};

/**
 * Convenience templated class representing an ADC
 *
 * Example
 * @code
 *  // Instantiate ADC0 single-ended channel #8
 *  const adc0<8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC(USBDM::resolution_12bit_se);
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam adcChannel    ADC channel
 */
template<uint8_t adcChannel> using Adc1a =
   AnalogueIOT<getPortClockMask(adcChannel,Adc1aInfo), getPcrReg(adcChannel,Adc1aInfo), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG), ADC1_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTE0_SIG_SEL == 0)
using adc1_se4a            = const USBDM::Adc1a< 4>;
using adc_D14              = const USBDM::Adc1a< 4>;
using adc_J2_18            = const USBDM::Adc1a< 4>;
using adc_ConTx            = const USBDM::Adc1a< 4>;
#endif
#if (PTE1_SIG_SEL == 0)
using adc1_se5a            = const USBDM::Adc1a< 5>;
using adc_D15              = const USBDM::Adc1a< 5>;
using adc_J2_19            = const USBDM::Adc1a< 5>;
using adc_ConRx            = const USBDM::Adc1a< 5>;
#endif
#if (PTE2_SIG_SEL == 0)
using adc1_se6a            = const USBDM::Adc1a< 6>;
#endif
#if (PTE3_SIG_SEL == 0)
using adc1_se7a            = const USBDM::Adc1a< 7>;
#endif
/**
 * @}
 */
constexpr PcrInfo Ftm0Info[32] = {
#if (PTA3_SIG_SEL == 3)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  3},
#elif (PTC1_SIG_SEL == 4)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  4},
#else
 /*  0 */  { 0, 0, 0 },
#endif
#if (PTA4_SIG_SEL == 3)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  3},
#elif (PTC2_SIG_SEL == 4)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  4},
#else
 /*  1 */  { 0, 0, 0 },
#endif
#if (PTA5_SIG_SEL == 3)
 /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),  3},
#elif (PTC3_SIG_SEL == 4)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  4},
#elif (PTC5_SIG_SEL == 7)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),  7},
#else
 /*  2 */  { 0, 0, 0 },
#endif
#if (PTC4_SIG_SEL == 4)
 /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  4},
#else
 /*  3 */  { 0, 0, 0 },
#endif
#if (PTD4_SIG_SEL == 4)
 /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  4},
#else
 /*  4 */  { 0, 0, 0 },
#endif
#if (PTA0_SIG_SEL == 3)
 /*  5 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),  3},
#elif (PTD5_SIG_SEL == 4)
 /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  4},
#else
 /*  5 */  { 0, 0, 0 },
#endif
#if (PTA1_SIG_SEL == 3)
 /*  6 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),  3},
#elif (PTD6_SIG_SEL == 4)
 /*  6 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  4},
#else
 /*  6 */  { 0, 0, 0 },
#endif
#if (PTA2_SIG_SEL == 3)
 /*  7 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),  3},
#elif (PTD7_SIG_SEL == 4)
 /*  7 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),  4},
#else
 /*  7 */  { 0, 0, 0 },
#endif
};

/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel (for FTM0 CH6)
 * const USBDM::Ftm0<6>   ftm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam ftmChannel    FTM channel
 */
template<uint8_t ftmChannel> using Ftm0 =
   PwmIOT<getPortClockMask(ftmChannel,Ftm0Info), getPcrReg(ftmChannel,Ftm0Info), getPcrMux(ftmChannel,Ftm0Info), FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, ftmChannel>;

/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA0_SIG_SEL == 3)
using ftm0_ch5             = const USBDM::Ftm0<5>;
#endif
#if (PTA1_SIG_SEL == 3)
using ftm0_ch6             = const USBDM::Ftm0<6>;
using ftm_D9               = const USBDM::Ftm0<6>;
using ftm_J2_4             = const USBDM::Ftm0<6>;
using ftm_LED_RED          = const USBDM::Ftm0<6>;
#endif
#if (PTA2_SIG_SEL == 3)
using ftm0_ch7             = const USBDM::Ftm0<7>;
using ftm_D3               = const USBDM::Ftm0<7>;
using ftm_J1_8             = const USBDM::Ftm0<7>;
using ftm_LED_GREEN        = const USBDM::Ftm0<7>;
#endif
#if (PTA3_SIG_SEL == 3)
using ftm0_ch0             = const USBDM::Ftm0<0>;
#endif
#if (PTA4_SIG_SEL == 3)
using ftm0_ch1             = const USBDM::Ftm0<1>;
using ftm_D4               = const USBDM::Ftm0<1>;
using ftm_J1_10            = const USBDM::Ftm0<1>;
#endif
#if (PTA5_SIG_SEL == 3)
using ftm0_ch2             = const USBDM::Ftm0<2>;
using ftm_J1_1             = const USBDM::Ftm0<2>;
#endif
#if (PTC1_SIG_SEL == 4)
using ftm0_ch0             = const USBDM::Ftm0<0>;
using ftm_A2               = const USBDM::Ftm0<0>;
using ftm_J24_6            = const USBDM::Ftm0<0>;
#endif
#if (PTC2_SIG_SEL == 4)
using ftm0_ch1             = const USBDM::Ftm0<1>;
using ftm_A3               = const USBDM::Ftm0<1>;
using ftm_J24_8            = const USBDM::Ftm0<1>;
#endif
#if (PTC3_SIG_SEL == 4)
using ftm0_ch2             = const USBDM::Ftm0<2>;
using ftm_D6               = const USBDM::Ftm0<2>;
using ftm_J1_14            = const USBDM::Ftm0<2>;
#endif
#if (PTC4_SIG_SEL == 4)
using ftm0_ch3             = const USBDM::Ftm0<3>;
using ftm_J24_9            = const USBDM::Ftm0<3>;
#endif
#if (PTC5_SIG_SEL == 7)
using ftm0_ch2             = const USBDM::Ftm0<2>;
using ftm_J1_15            = const USBDM::Ftm0<2>;
#endif
#if (PTD4_SIG_SEL == 4)
using ftm0_ch4             = const USBDM::Ftm0<4>;
using ftm_D10              = const USBDM::Ftm0<4>;
using ftm_J2_6             = const USBDM::Ftm0<4>;
#endif
#if (PTD5_SIG_SEL == 4)
using ftm0_ch5             = const USBDM::Ftm0<5>;
using ftm_D13              = const USBDM::Ftm0<5>;
using ftm_J2_12            = const USBDM::Ftm0<5>;
using ftm_LED_BLUE         = const USBDM::Ftm0<5>;
#endif
#if (PTD6_SIG_SEL == 4)
using ftm0_ch6             = const USBDM::Ftm0<6>;
using ftm_D11              = const USBDM::Ftm0<6>;
using ftm_J2_8             = const USBDM::Ftm0<6>;
#endif
#if (PTD7_SIG_SEL == 4)
using ftm0_ch7             = const USBDM::Ftm0<7>;
using ftm_D12              = const USBDM::Ftm0<7>;
using ftm_J2_10            = const USBDM::Ftm0<7>;
#endif
/**
 * @}
 */
constexpr PcrInfo Ftm1Info[32] = {
#if (PTA12_SIG_SEL == 3)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), 3},
#elif (PTB0_SIG_SEL == 3)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  3},
#else
 /*  0 */  { 0, 0, 0 },
#endif
#if (PTA13_SIG_SEL == 3)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), 3},
#elif (PTB1_SIG_SEL == 3)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  3},
#else
 /*  1 */  { 0, 0, 0 },
#endif
};

/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel (for FTM0 CH6)
 * const USBDM::Ftm0<6>   ftm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam ftmChannel    FTM channel
 */
template<uint8_t ftmChannel> using Ftm1 =
   PwmIOT<getPortClockMask(ftmChannel,Ftm1Info), getPcrReg(ftmChannel,Ftm1Info), getPcrMux(ftmChannel,Ftm1Info), FTM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM1_CLOCK_REG), FTM1_CLOCK_MASK, ftmChannel>;

/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA12_SIG_SEL == 3)
using ftm1_ch0             = const USBDM::Ftm1<0>;
using ftm_J1_5             = const USBDM::Ftm1<0>;
#endif
#if (PTA13_SIG_SEL == 3)
using ftm1_ch1             = const USBDM::Ftm1<1>;
using ftm_J1_3             = const USBDM::Ftm1<1>;
#endif
#if (PTB0_SIG_SEL == 3)
using ftm1_ch0             = const USBDM::Ftm1<0>;
using ftm_A0               = const USBDM::Ftm1<0>;
using ftm_J24_2            = const USBDM::Ftm1<0>;
#endif
#if (PTB1_SIG_SEL == 3)
using ftm1_ch1             = const USBDM::Ftm1<1>;
using ftm_A1               = const USBDM::Ftm1<1>;
using ftm_J24_4            = const USBDM::Ftm1<1>;
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
