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
using gpioA_0              = const USBDM::GpioA<0>;
using gpioA_1              = const USBDM::GpioA<1>;
using gpio_D0              = const USBDM::GpioA<1>;
using gpio_ConRx           = const USBDM::GpioA<1>;
using gpioA_2              = const USBDM::GpioA<2>;
using gpio_D1              = const USBDM::GpioA<2>;
using gpio_ConTx           = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpio_D4              = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpio_D5              = const USBDM::GpioA<5>;
using gpioA_12             = const USBDM::GpioA<12>;
using gpio_D3              = const USBDM::GpioA<12>;
using gpioA_13             = const USBDM::GpioA<13>;
using gpio_D8              = const USBDM::GpioA<13>;
using gpioA_14             = const USBDM::GpioA<14>;
using gpioA_15             = const USBDM::GpioA<15>;
using gpioA_16             = const USBDM::GpioA<16>;
using gpio_D28             = const USBDM::GpioA<16>;
using gpioA_17             = const USBDM::GpioA<17>;
using gpio_D29             = const USBDM::GpioA<17>;
using gpioA_18             = const USBDM::GpioA<18>;
using gpioA_19             = const USBDM::GpioA<19>;
using gpioA_20             = const USBDM::GpioA<20>;
using gpioB_0              = const USBDM::GpioB<0>;
using gpio_A0              = const USBDM::GpioB<0>;
using gpioB_1              = const USBDM::GpioB<1>;
using gpio_A1              = const USBDM::GpioB<1>;
using gpioB_2              = const USBDM::GpioB<2>;
using gpio_A2              = const USBDM::GpioB<2>;
using gpioB_3              = const USBDM::GpioB<3>;
using gpio_A3              = const USBDM::GpioB<3>;
using gpioB_8              = const USBDM::GpioB<8>;
using gpio_A20             = const USBDM::GpioB<8>;
using gpioB_9              = const USBDM::GpioB<9>;
using gpio_A19             = const USBDM::GpioB<9>;
using gpioB_10             = const USBDM::GpioB<10>;
using gpio_A18             = const USBDM::GpioB<10>;
using gpioB_11             = const USBDM::GpioB<11>;
using gpio_A17             = const USBDM::GpioB<11>;
using gpioB_16             = const USBDM::GpioB<16>;
using gpioB_17             = const USBDM::GpioB<17>;
using gpioB_18             = const USBDM::GpioB<18>;
using gpio_LED_RED         = const USBDM::GpioB<18>;
using gpioB_19             = const USBDM::GpioB<19>;
using gpio_LED_GREEN       = const USBDM::GpioB<19>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpio_D17             = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpio_A5              = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpio_A4              = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpio_D18             = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpio_D19             = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpio_D20             = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
using gpio_D21             = const USBDM::GpioC<6>;
using gpioC_7              = const USBDM::GpioC<7>;
using gpio_D16             = const USBDM::GpioC<7>;
using gpioC_8              = const USBDM::GpioC<8>;
using gpio_D6              = const USBDM::GpioC<8>;
using gpioC_9              = const USBDM::GpioC<9>;
using gpio_D7              = const USBDM::GpioC<9>;
using gpioC_10             = const USBDM::GpioC<10>;
using gpio_D22             = const USBDM::GpioC<10>;
using gpioC_11             = const USBDM::GpioC<11>;
using gpio_D23             = const USBDM::GpioC<11>;
using gpioC_12             = const USBDM::GpioC<12>;
using gpio_D24             = const USBDM::GpioC<12>;
using gpioC_13             = const USBDM::GpioC<13>;
using gpio_D25             = const USBDM::GpioC<13>;
using gpioC_16             = const USBDM::GpioC<16>;
using gpio_D26             = const USBDM::GpioC<16>;
using gpioC_17             = const USBDM::GpioC<17>;
using gpio_D27             = const USBDM::GpioC<17>;
using gpioD_0              = const USBDM::GpioD<0>;
using gpio_D10             = const USBDM::GpioD<0>;
using gpioD_1              = const USBDM::GpioD<1>;
using gpio_D13             = const USBDM::GpioD<1>;
using gpio_LED_BLUE        = const USBDM::GpioD<1>;
using gpioD_2              = const USBDM::GpioD<2>;
using gpio_D11             = const USBDM::GpioD<2>;
using gpioD_3              = const USBDM::GpioD<3>;
using gpio_D12             = const USBDM::GpioD<3>;
using gpioD_4              = const USBDM::GpioD<4>;
using gpio_D2              = const USBDM::GpioD<4>;
using gpioD_5              = const USBDM::GpioD<5>;
using gpio_D9              = const USBDM::GpioD<5>;
using gpioD_6              = const USBDM::GpioD<6>;
using gpio_D32             = const USBDM::GpioD<6>;
using gpioD_7              = const USBDM::GpioD<7>;
using gpio_D33             = const USBDM::GpioD<7>;
using gpioE_0              = const USBDM::GpioE<0>;
using gpio_D15             = const USBDM::GpioE<0>;
using gpioE_1              = const USBDM::GpioE<1>;
using gpio_D14             = const USBDM::GpioE<1>;
using gpioE_2              = const USBDM::GpioE<2>;
using gpio_A16             = const USBDM::GpioE<2>;
using gpioE_3              = const USBDM::GpioE<3>;
using gpio_A15             = const USBDM::GpioE<3>;
using gpioE_4              = const USBDM::GpioE<4>;
using gpio_A14             = const USBDM::GpioE<4>;
using gpioE_5              = const USBDM::GpioE<5>;
using gpio_A13             = const USBDM::GpioE<5>;
using gpioE_20             = const USBDM::GpioE<20>;
using gpio_A11             = const USBDM::GpioE<20>;
using gpioE_21             = const USBDM::GpioE<21>;
using gpio_A10             = const USBDM::GpioE<21>;
using gpioE_22             = const USBDM::GpioE<22>;
using gpio_A9              = const USBDM::GpioE<22>;
using gpioE_23             = const USBDM::GpioE<23>;
using gpio_A8              = const USBDM::GpioE<23>;
using gpioE_24             = const USBDM::GpioE<24>;
using gpio_ACCEL_SCL       = const USBDM::GpioE<24>;
using gpioE_25             = const USBDM::GpioE<25>;
using gpio_ACCEL_SDA       = const USBDM::GpioE<25>;
using gpioE_29             = const USBDM::GpioE<29>;
using gpio_A7              = const USBDM::GpioE<29>;
using gpioE_30             = const USBDM::GpioE<30>;
using gpio_A6              = const USBDM::GpioE<30>;
using gpioE_31             = const USBDM::GpioE<31>;
using gpio_D30             = const USBDM::GpioE<31>;
/**
 * @}
 */
constexpr PcrInfo Adc0Info[32] = {
#if (PTE20_SIG_SEL == 0)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), 0},
#else
 /*  0 */  { 0, 0, 0 },
#endif
 /*  1 */  { 0, 0, 0 },
 /*  2 */  { 0, 0, 0 },
#if (PTE22_SIG_SEL == 0)
 /*  3 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]), 0},
#else
 /*  3 */  { 0, 0, 0 },
#endif
#if (PTE29_SIG_SEL == 0)
 /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), 0},
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
#if (PTC2_SIG_SEL == 0)
 /* 11 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  0},
#else
 /* 11 */  { 0, 0, 0 },
#endif
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
 /* 17 */  { 0, 0, 0 },
 /* 18 */  { 0, 0, 0 },
 /* 19 */  { 0, 0, 0 },
 /* 20 */  { 0, 0, 0 },
 /* 21 */  { 0, 0, 0 },
 /* 22 */  { 0, 0, 0 },
#if (PTE30_SIG_SEL == 0)
 /* 23 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), 0},
#else
 /* 23 */  { 0, 0, 0 },
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
template<uint8_t adcChannel> using Adc0 =
   AnalogueIOT<getPortClockMask(adcChannel,Adc0Info), getPcrReg(adcChannel,Adc0Info), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTB0_SIG_SEL == 0)
using adc0_se8             = const USBDM::Adc0< 8>;
using adc_A0               = const USBDM::Adc0< 8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc0_se9             = const USBDM::Adc0< 9>;
using adc_A1               = const USBDM::Adc0< 9>;
#endif
#if (PTB2_SIG_SEL == 0)
using adc0_se12            = const USBDM::Adc0<12>;
using adc_A2               = const USBDM::Adc0<12>;
#endif
#if (PTB3_SIG_SEL == 0)
using adc0_se13            = const USBDM::Adc0<13>;
using adc_A3               = const USBDM::Adc0<13>;
#endif
#if (PTC0_SIG_SEL == 0)
using adc0_se14            = const USBDM::Adc0<14>;
using adc_D17              = const USBDM::Adc0<14>;
#endif
#if (PTC1_SIG_SEL == 0)
using adc0_se15            = const USBDM::Adc0<15>;
using adc_A5               = const USBDM::Adc0<15>;
#endif
#if (PTC2_SIG_SEL == 0)
using adc0_se11            = const USBDM::Adc0<11>;
using adc_A4               = const USBDM::Adc0<11>;
#endif
#if (PTD1_SIG_SEL == 0)
using adc0_se5b            = const USBDM::Adc0< 5>;
using adc_D13              = const USBDM::Adc0< 5>;
using adc_LED_BLUE         = const USBDM::Adc0< 5>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc0_se6b            = const USBDM::Adc0< 6>;
using adc_D9               = const USBDM::Adc0< 6>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc0_se7b            = const USBDM::Adc0< 7>;
using adc_D32              = const USBDM::Adc0< 7>;
#endif
#if (PTE20_SIG_SEL == 0)
using adc0_se0             = const USBDM::Adc0< 0>;
using adc_A11              = const USBDM::Adc0< 0>;
#endif
#if (PTE22_SIG_SEL == 0)
using adc0_se3             = const USBDM::Adc0< 3>;
using adc_A9               = const USBDM::Adc0< 3>;
#endif
#if (PTE29_SIG_SEL == 0)
using adc0_se4b            = const USBDM::Adc0< 4>;
using adc_A7               = const USBDM::Adc0< 4>;
#endif
#if (PTE30_SIG_SEL == 0)
using adc0_se23            = const USBDM::Adc0<23>;
using adc_A6               = const USBDM::Adc0<23>;
#endif
/**
 * @}
 */
constexpr PcrInfo Adc0aInfo[32] = {
 /*  0 */  { 0, 0, 0 },
 /*  1 */  { 0, 0, 0 },
 /*  2 */  { 0, 0, 0 },
 /*  3 */  { 0, 0, 0 },
#if (PTE21_SIG_SEL == 0)
 /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), 0},
#else
 /*  4 */  { 0, 0, 0 },
#endif
 /*  5 */  { 0, 0, 0 },
 /*  6 */  { 0, 0, 0 },
#if (PTE23_SIG_SEL == 0)
 /*  7 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]), 0},
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
template<uint8_t adcChannel> using Adc0a =
   AnalogueIOT<getPortClockMask(adcChannel,Adc0aInfo), getPcrReg(adcChannel,Adc0aInfo), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTE21_SIG_SEL == 0)
using adc0_se4a            = const USBDM::Adc0a< 4>;
using adc_A10              = const USBDM::Adc0a< 4>;
#endif
#if (PTE23_SIG_SEL == 0)
using adc0_se7a            = const USBDM::Adc0a< 7>;
using adc_A8               = const USBDM::Adc0a< 7>;
#endif
/**
 * @}
 */
constexpr PcrInfo Tpm0Info[32] = {
#if (PTA3_SIG_SEL == 3)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  3},
#elif (PTC1_SIG_SEL == 4)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  4},
#elif (PTD0_SIG_SEL == 4)
 /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),  4},
#elif (PTE24_SIG_SEL == 3)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), 3},
#else
 /*  0 */  { 0, 0, 0 },
#endif
#if (PTA4_SIG_SEL == 3)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  3},
#elif (PTC2_SIG_SEL == 4)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  4},
#elif (PTD1_SIG_SEL == 4)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  4},
#elif (PTE25_SIG_SEL == 3)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), 3},
#else
 /*  1 */  { 0, 0, 0 },
#endif
#if (PTA5_SIG_SEL == 3)
 /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),  3},
#elif (PTC3_SIG_SEL == 4)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  4},
#elif (PTD2_SIG_SEL == 4)
 /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  4},
#elif (PTE29_SIG_SEL == 3)
 /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), 3},
#else
 /*  2 */  { 0, 0, 0 },
#endif
#if (PTC4_SIG_SEL == 4)
 /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  4},
#elif (PTD3_SIG_SEL == 4)
 /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  4},
#elif (PTE30_SIG_SEL == 3)
 /*  3 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), 3},
#else
 /*  3 */  { 0, 0, 0 },
#endif
#if (PTC8_SIG_SEL == 3)
 /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  3},
#elif (PTD4_SIG_SEL == 4)
 /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  4},
#elif (PTE31_SIG_SEL == 3)
 /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[31]), 3},
#else
 /*  4 */  { 0, 0, 0 },
#endif
#if (PTA0_SIG_SEL == 3)
 /*  5 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),  3},
#elif (PTC9_SIG_SEL == 3)
 /*  5 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  3},
#elif (PTD5_SIG_SEL == 4)
 /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  4},
#else
 /*  5 */  { 0, 0, 0 },
#endif
};

/**
 * Convenience templated class representing a TPM
 *
 * Example
 * @code
 * // Instantiate the tpm channel (for TPM0 CH6)
 * const USBDM::Tpm0<6>   tpm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tpm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tpm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tpm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam tpmChannel    TPM channel
 */
template<uint8_t tpmChannel> using Tpm0 =
   PwmIOT<getPortClockMask(tpmChannel,Tpm0Info), getPcrReg(tpmChannel,Tpm0Info), getPcrMux(tpmChannel,Tpm0Info), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, tpmChannel>;

/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA0_SIG_SEL == 3)
using tpm0_ch5             = const USBDM::Tpm0<5>;
#endif
#if (PTA3_SIG_SEL == 3)
using tpm0_ch0             = const USBDM::Tpm0<0>;
#endif
#if (PTA4_SIG_SEL == 3)
using tpm0_ch1             = const USBDM::Tpm0<1>;
using tpm_D4               = const USBDM::Tpm0<1>;
#endif
#if (PTA5_SIG_SEL == 3)
using tpm0_ch2             = const USBDM::Tpm0<2>;
using tpm_D5               = const USBDM::Tpm0<2>;
#endif
#if (PTC1_SIG_SEL == 4)
using tpm0_ch0             = const USBDM::Tpm0<0>;
using tpm_A5               = const USBDM::Tpm0<0>;
#endif
#if (PTC2_SIG_SEL == 4)
using tpm0_ch1             = const USBDM::Tpm0<1>;
using tpm_A4               = const USBDM::Tpm0<1>;
#endif
#if (PTC3_SIG_SEL == 4)
using tpm0_ch2             = const USBDM::Tpm0<2>;
using tpm_D18              = const USBDM::Tpm0<2>;
#endif
#if (PTC4_SIG_SEL == 4)
using tpm0_ch3             = const USBDM::Tpm0<3>;
using tpm_D19              = const USBDM::Tpm0<3>;
#endif
#if (PTC8_SIG_SEL == 3)
using tpm0_ch4             = const USBDM::Tpm0<4>;
using tpm_D6               = const USBDM::Tpm0<4>;
#endif
#if (PTC9_SIG_SEL == 3)
using tpm0_ch5             = const USBDM::Tpm0<5>;
using tpm_D7               = const USBDM::Tpm0<5>;
#endif
#if (PTD0_SIG_SEL == 4)
using tpm0_ch0             = const USBDM::Tpm0<0>;
using tpm_D10              = const USBDM::Tpm0<0>;
#endif
#if (PTD1_SIG_SEL == 4)
using tpm0_ch1             = const USBDM::Tpm0<1>;
using tpm_D13              = const USBDM::Tpm0<1>;
using tpm_LED_BLUE         = const USBDM::Tpm0<1>;
#endif
#if (PTD2_SIG_SEL == 4)
using tpm0_ch2             = const USBDM::Tpm0<2>;
using tpm_D11              = const USBDM::Tpm0<2>;
#endif
#if (PTD3_SIG_SEL == 4)
using tpm0_ch3             = const USBDM::Tpm0<3>;
using tpm_D12              = const USBDM::Tpm0<3>;
#endif
#if (PTD4_SIG_SEL == 4)
using tpm0_ch4             = const USBDM::Tpm0<4>;
using tpm_D2               = const USBDM::Tpm0<4>;
#endif
#if (PTD5_SIG_SEL == 4)
using tpm0_ch5             = const USBDM::Tpm0<5>;
using tpm_D9               = const USBDM::Tpm0<5>;
#endif
#if (PTE24_SIG_SEL == 3)
using tpm0_ch0             = const USBDM::Tpm0<0>;
using tpm_ACCEL_SCL        = const USBDM::Tpm0<0>;
#endif
#if (PTE25_SIG_SEL == 3)
using tpm0_ch1             = const USBDM::Tpm0<1>;
using tpm_ACCEL_SDA        = const USBDM::Tpm0<1>;
#endif
#if (PTE29_SIG_SEL == 3)
using tpm0_ch2             = const USBDM::Tpm0<2>;
using tpm_A7               = const USBDM::Tpm0<2>;
#endif
#if (PTE30_SIG_SEL == 3)
using tpm0_ch3             = const USBDM::Tpm0<3>;
using tpm_A6               = const USBDM::Tpm0<3>;
#endif
#if (PTE31_SIG_SEL == 3)
using tpm0_ch4             = const USBDM::Tpm0<4>;
using tpm_D30              = const USBDM::Tpm0<4>;
#endif
/**
 * @}
 */
constexpr PcrInfo Tpm1Info[32] = {
#if (PTA12_SIG_SEL == 3)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), 3},
#elif (PTB0_SIG_SEL == 3)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  3},
#elif (PTE20_SIG_SEL == 3)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), 3},
#else
 /*  0 */  { 0, 0, 0 },
#endif
#if (PTA13_SIG_SEL == 3)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), 3},
#elif (PTB1_SIG_SEL == 3)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  3},
#elif (PTE21_SIG_SEL == 3)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), 3},
#else
 /*  1 */  { 0, 0, 0 },
#endif
};

/**
 * Convenience templated class representing a TPM
 *
 * Example
 * @code
 * // Instantiate the tpm channel (for TPM0 CH6)
 * const USBDM::Tpm0<6>   tpm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tpm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tpm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tpm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam tpmChannel    TPM channel
 */
template<uint8_t tpmChannel> using Tpm1 =
   PwmIOT<getPortClockMask(tpmChannel,Tpm1Info), getPcrReg(tpmChannel,Tpm1Info), getPcrMux(tpmChannel,Tpm1Info), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, tpmChannel>;

/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA12_SIG_SEL == 3)
using tpm1_ch0             = const USBDM::Tpm1<0>;
using tpm_D3               = const USBDM::Tpm1<0>;
#endif
#if (PTA13_SIG_SEL == 3)
using tpm1_ch1             = const USBDM::Tpm1<1>;
using tpm_D8               = const USBDM::Tpm1<1>;
#endif
#if (PTB0_SIG_SEL == 3)
using tpm1_ch0             = const USBDM::Tpm1<0>;
using tpm_A0               = const USBDM::Tpm1<0>;
#endif
#if (PTB1_SIG_SEL == 3)
using tpm1_ch1             = const USBDM::Tpm1<1>;
using tpm_A1               = const USBDM::Tpm1<1>;
#endif
#if (PTE20_SIG_SEL == 3)
using tpm1_ch0             = const USBDM::Tpm1<0>;
using tpm_A11              = const USBDM::Tpm1<0>;
#endif
#if (PTE21_SIG_SEL == 3)
using tpm1_ch1             = const USBDM::Tpm1<1>;
using tpm_A10              = const USBDM::Tpm1<1>;
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
