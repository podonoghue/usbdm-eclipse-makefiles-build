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

namespace USBDM {

/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
using gpioA_0              = const USBDM::GpioA<0>;
using gpio_D8              = const USBDM::GpioA<0>;
using gpioA_1              = const USBDM::GpioA<1>;
using gpio_D3              = const USBDM::GpioA<1>;
using gpioA_2              = const USBDM::GpioA<2>;
using gpio_D5              = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpioA_6              = const USBDM::GpioA<6>;
using gpioA_7              = const USBDM::GpioA<7>;
using gpioA_8              = const USBDM::GpioA<8>;
using gpioA_9              = const USBDM::GpioA<9>;
using gpioA_10             = const USBDM::GpioA<10>;
using gpioA_11             = const USBDM::GpioA<11>;
using gpioA_12             = const USBDM::GpioA<12>;
using gpioA_13             = const USBDM::GpioA<13>;
using gpioA_14             = const USBDM::GpioA<14>;
using gpioA_15             = const USBDM::GpioA<15>;
using gpioA_16             = const USBDM::GpioA<16>;
using gpioA_17             = const USBDM::GpioA<17>;
using gpioA_18             = const USBDM::GpioA<18>;
using gpioA_19             = const USBDM::GpioA<19>;
using gpioA_24             = const USBDM::GpioA<24>;
using gpioA_25             = const USBDM::GpioA<25>;
using gpioA_26             = const USBDM::GpioA<26>;
using gpioA_27             = const USBDM::GpioA<27>;
using gpioA_28             = const USBDM::GpioA<28>;
using gpioA_29             = const USBDM::GpioA<29>;
using gpioB_0              = const USBDM::GpioB<0>;
using gpioB_1              = const USBDM::GpioB<1>;
using gpioB_2              = const USBDM::GpioB<2>;
using gpio_A0              = const USBDM::GpioB<2>;
using gpioB_3              = const USBDM::GpioB<3>;
using gpio_A1              = const USBDM::GpioB<3>;
using gpioB_4              = const USBDM::GpioB<4>;
using gpioB_5              = const USBDM::GpioB<5>;
using gpioB_6              = const USBDM::GpioB<6>;
using gpioB_7              = const USBDM::GpioB<7>;
using gpioB_8              = const USBDM::GpioB<8>;
using gpioB_9              = const USBDM::GpioB<9>;
using gpio_D2              = const USBDM::GpioB<9>;
using gpioB_10             = const USBDM::GpioB<10>;
using gpio_A2              = const USBDM::GpioB<10>;
using gpioB_11             = const USBDM::GpioB<11>;
using gpio_A3              = const USBDM::GpioB<11>;
using gpioB_12             = const USBDM::GpioB<12>;
using gpioB_13             = const USBDM::GpioB<13>;
using gpioB_16             = const USBDM::GpioB<16>;
using gpioB_17             = const USBDM::GpioB<17>;
using gpioB_18             = const USBDM::GpioB<18>;
using gpioB_19             = const USBDM::GpioB<19>;
using gpioB_20             = const USBDM::GpioB<20>;
using gpioB_21             = const USBDM::GpioB<21>;
using gpio_LED_BLUE        = const USBDM::GpioB<21>;
using gpioB_22             = const USBDM::GpioB<22>;
using gpio_LED_RED         = const USBDM::GpioB<22>;
using gpioB_23             = const USBDM::GpioB<23>;
using gpio_D4              = const USBDM::GpioB<23>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpio_D6              = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpio_D7              = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpio_D9              = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
using gpioC_7              = const USBDM::GpioC<7>;
using gpioC_8              = const USBDM::GpioC<8>;
using gpioC_9              = const USBDM::GpioC<9>;
using gpioC_10             = const USBDM::GpioC<10>;
using gpio_A5              = const USBDM::GpioC<10>;
using gpioC_11             = const USBDM::GpioC<11>;
using gpio_A4              = const USBDM::GpioC<11>;
using gpioC_12             = const USBDM::GpioC<12>;
using gpioC_13             = const USBDM::GpioC<13>;
using gpioC_14             = const USBDM::GpioC<14>;
using gpioC_15             = const USBDM::GpioC<15>;
using gpioC_16             = const USBDM::GpioC<16>;
using gpio_D0              = const USBDM::GpioC<16>;
using gpioC_17             = const USBDM::GpioC<17>;
using gpio_D1              = const USBDM::GpioC<17>;
using gpioC_18             = const USBDM::GpioC<18>;
using gpioC_19             = const USBDM::GpioC<19>;
using gpioD_0              = const USBDM::GpioD<0>;
using gpio_D10             = const USBDM::GpioD<0>;
using gpioD_1              = const USBDM::GpioD<1>;
using gpio_D13             = const USBDM::GpioD<1>;
using gpioD_2              = const USBDM::GpioD<2>;
using gpio_D11             = const USBDM::GpioD<2>;
using gpioD_3              = const USBDM::GpioD<3>;
using gpio_D12             = const USBDM::GpioD<3>;
using gpioD_4              = const USBDM::GpioD<4>;
using gpio_nRF24L01_cs     = const USBDM::GpioD<4>;
using gpioD_5              = const USBDM::GpioD<5>;
using gpio_nRF24L01_sck    = const USBDM::GpioD<5>;
using gpioD_6              = const USBDM::GpioD<6>;
using gpio_nRF24L01_mosi   = const USBDM::GpioD<6>;
using gpioD_7              = const USBDM::GpioD<7>;
using gpio_nRF24L01_miso   = const USBDM::GpioD<7>;
using gpioD_8              = const USBDM::GpioD<8>;
using gpioD_9              = const USBDM::GpioD<9>;
using gpioD_10             = const USBDM::GpioD<10>;
using gpioD_11             = const USBDM::GpioD<11>;
using gpioD_12             = const USBDM::GpioD<12>;
using gpioD_13             = const USBDM::GpioD<13>;
using gpioD_14             = const USBDM::GpioD<14>;
using gpioD_15             = const USBDM::GpioD<15>;
using gpioE_0              = const USBDM::GpioE<0>;
using gpioE_1              = const USBDM::GpioE<1>;
using gpioE_2              = const USBDM::GpioE<2>;
using gpioE_3              = const USBDM::GpioE<3>;
using gpioE_4              = const USBDM::GpioE<4>;
using gpioE_5              = const USBDM::GpioE<5>;
using gpioE_6              = const USBDM::GpioE<6>;
using gpioE_7              = const USBDM::GpioE<7>;
using gpioE_8              = const USBDM::GpioE<8>;
using gpioE_9              = const USBDM::GpioE<9>;
using gpioE_10             = const USBDM::GpioE<10>;
using gpioE_11             = const USBDM::GpioE<11>;
using gpioE_12             = const USBDM::GpioE<12>;
using gpioE_24             = const USBDM::GpioE<24>;
using gpio_D15             = const USBDM::GpioE<24>;
using gpioE_25             = const USBDM::GpioE<25>;
using gpio_D14             = const USBDM::GpioE<25>;
using gpioE_26             = const USBDM::GpioE<26>;
using gpio_LED_GREEN       = const USBDM::GpioE<26>;
using gpioE_27             = const USBDM::GpioE<27>;
using gpioE_28             = const USBDM::GpioE<28>;
/**
 * @}
 */
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
   Analogue_T<getPortClockMask(adcChannel,Adc0Info), getPcrReg(adcChannel,Adc0Info), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
using adc0_se19            = const USBDM::Adc0<19>;
using adc0_se20            = const USBDM::Adc0<20>;
using adc0_se0             = const USBDM::Adc0<0>;
using adc0_se1             = const USBDM::Adc0<1>;
using adc0_se16            = const USBDM::Adc0<16>;
using adc0_se21            = const USBDM::Adc0<21>;
using adc0_se23            = const USBDM::Adc0<23>;
using adc0_se3             = const USBDM::Adc0<3>;
using adc0_se22            = const USBDM::Adc0<22>;
#if (PTA7_SIG_SEL == 0)
using adc0_se10            = const USBDM::Adc0<10>;
#endif
#if (PTA8_SIG_SEL == 0)
using adc0_se11            = const USBDM::Adc0<11>;
#endif
#if (PTB0_SIG_SEL == 0)
using adc0_se8             = const USBDM::Adc0<8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc0_se9             = const USBDM::Adc0<9>;
#endif
#if (PTB2_SIG_SEL == 0)
using adc0_se12            = const USBDM::Adc0<12>;
using adc_A0               = const USBDM::Adc0<12>;
#endif
#if (PTB3_SIG_SEL == 0)
using adc0_se13            = const USBDM::Adc0<13>;
using adc_A1               = const USBDM::Adc0<13>;
#endif
#if (PTC0_SIG_SEL == 0)
using adc0_se14            = const USBDM::Adc0<14>;
#endif
#if (PTC1_SIG_SEL == 0)
using adc0_se15            = const USBDM::Adc0<15>;
#endif
#if (PTC2_SIG_SEL == 0)
using adc0_se4b            = const USBDM::Adc0<4>;
using adc_D6               = const USBDM::Adc0<4>;
#endif
#if (PTD1_SIG_SEL == 0)
using adc0_se5b            = const USBDM::Adc0<5>;
using adc_D13              = const USBDM::Adc0<5>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc0_se6b            = const USBDM::Adc0<6>;
using adc_nRF24L01_sck     = const USBDM::Adc0<6>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc0_se7b            = const USBDM::Adc0<7>;
using adc_nRF24L01_mosi    = const USBDM::Adc0<7>;
#endif
#if (PTE2_SIG_SEL == 0)
using adc0_se2             = const USBDM::Adc0<2>;
#endif
#if (PTE24_SIG_SEL == 0)
using adc0_se17            = const USBDM::Adc0<17>;
using adc_D15              = const USBDM::Adc0<17>;
#endif
#if (PTE25_SIG_SEL == 0)
using adc0_se18            = const USBDM::Adc0<18>;
using adc_D14              = const USBDM::Adc0<18>;
#endif
/**
 * @}
 */
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
   Analogue_T<getPortClockMask(adcChannel,Adc1Info), getPcrReg(adcChannel,Adc1Info), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG), ADC1_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
using adc1_se19            = const USBDM::Adc1<19>;
using adc1_se20            = const USBDM::Adc1<20>;
using adc1_se0             = const USBDM::Adc1<0>;
using adc1_se1             = const USBDM::Adc1<1>;
using adc1_se16            = const USBDM::Adc1<16>;
using adc1_se18            = const USBDM::Adc1<18>;
using adc1_se23            = const USBDM::Adc1<23>;
#if (PTA17_SIG_SEL == 0)
using adc1_se17            = const USBDM::Adc1<17>;
#endif
#if (PTB0_SIG_SEL == 0)
using adc1_se8             = const USBDM::Adc1<8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc1_se9             = const USBDM::Adc1<9>;
#endif
#if (PTB4_SIG_SEL == 0)
using adc1_se10            = const USBDM::Adc1<10>;
#endif
#if (PTB5_SIG_SEL == 0)
using adc1_se11            = const USBDM::Adc1<11>;
#endif
#if (PTB6_SIG_SEL == 0)
using adc1_se12            = const USBDM::Adc1<12>;
#endif
#if (PTB7_SIG_SEL == 0)
using adc1_se13            = const USBDM::Adc1<13>;
#endif
#if (PTB10_SIG_SEL == 0)
using adc1_se14            = const USBDM::Adc1<14>;
using adc_A2               = const USBDM::Adc1<14>;
#endif
#if (PTB11_SIG_SEL == 0)
using adc1_se15            = const USBDM::Adc1<15>;
using adc_A3               = const USBDM::Adc1<15>;
#endif
#if (PTC8_SIG_SEL == 0)
using adc1_se4b            = const USBDM::Adc1<4>;
#endif
#if (PTC9_SIG_SEL == 0)
using adc1_se5b            = const USBDM::Adc1<5>;
#endif
#if (PTC10_SIG_SEL == 0)
using adc1_se6b            = const USBDM::Adc1<6>;
using adc_A5               = const USBDM::Adc1<6>;
#endif
#if (PTC11_SIG_SEL == 0)
using adc1_se7b            = const USBDM::Adc1<7>;
using adc_A4               = const USBDM::Adc1<7>;
#endif
/**
 * @}
 */
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
   Analogue_T<getPortClockMask(adcChannel,Adc1aInfo), getPcrReg(adcChannel,Adc1aInfo), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG), ADC1_CLOCK_MASK, adcChannel>;

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTE0_SIG_SEL == 0)
using adc1_se4a            = const USBDM::Adc1a<4>;
#endif
#if (PTE1_SIG_SEL == 0)
using adc1_se5a            = const USBDM::Adc1a<5>;
#endif
#if (PTE2_SIG_SEL == 0)
using adc1_se6a            = const USBDM::Adc1a<6>;
#endif
#if (PTE3_SIG_SEL == 0)
using adc1_se7a            = const USBDM::Adc1a<7>;
#endif
/**
 * @}
 */
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
   Ftm_T<getPortClockMask(ftmChannel,Ftm0Info), getPcrReg(ftmChannel,Ftm0Info), getPcrMux(ftmChannel,Ftm0Info), FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, FTM0_SC, ftmChannel>;

/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA0_SIG_SEL == 3)
using ftm0_ch5             = const USBDM::Ftm0<5>;
using ftm_D8               = const USBDM::Ftm0<5>;
#endif
#if (PTA1_SIG_SEL == 3)
using ftm0_ch6             = const USBDM::Ftm0<6>;
using ftm_D3               = const USBDM::Ftm0<6>;
#endif
#if (PTA2_SIG_SEL == 3)
using ftm0_ch7             = const USBDM::Ftm0<7>;
using ftm_D5               = const USBDM::Ftm0<7>;
#endif
#if (PTA3_SIG_SEL == 3)
using ftm0_ch0             = const USBDM::Ftm0<0>;
#endif
#if (PTA4_SIG_SEL == 3)
using ftm0_ch1             = const USBDM::Ftm0<1>;
#endif
#if (PTA5_SIG_SEL == 3)
using ftm0_ch2             = const USBDM::Ftm0<2>;
#endif
#if (PTA6_SIG_SEL == 3)
using ftm0_ch3             = const USBDM::Ftm0<3>;
#endif
#if (PTA7_SIG_SEL == 3)
using ftm0_ch4             = const USBDM::Ftm0<4>;
#endif
#if (PTB12_SIG_SEL == 4)
using ftm0_ch4             = const USBDM::Ftm0<4>;
#endif
#if (PTB13_SIG_SEL == 4)
using ftm0_ch5             = const USBDM::Ftm0<5>;
#endif
#if (PTC1_SIG_SEL == 4)
using ftm0_ch0             = const USBDM::Ftm0<0>;
#endif
#if (PTC2_SIG_SEL == 4)
using ftm0_ch1             = const USBDM::Ftm0<1>;
using ftm_D6               = const USBDM::Ftm0<1>;
#endif
#if (PTC3_SIG_SEL == 4)
using ftm0_ch2             = const USBDM::Ftm0<2>;
using ftm_D7               = const USBDM::Ftm0<2>;
#endif
#if (PTC4_SIG_SEL == 4)
using ftm0_ch3             = const USBDM::Ftm0<3>;
using ftm_D9               = const USBDM::Ftm0<3>;
#endif
#if (PTC5_SIG_SEL == 7)
using ftm0_ch2             = const USBDM::Ftm0<2>;
#endif
#if (PTD4_SIG_SEL == 4)
using ftm0_ch4             = const USBDM::Ftm0<4>;
using ftm_nRF24L01_cs      = const USBDM::Ftm0<4>;
#endif
#if (PTD5_SIG_SEL == 4)
using ftm0_ch5             = const USBDM::Ftm0<5>;
using ftm_nRF24L01_sck     = const USBDM::Ftm0<5>;
#endif
#if (PTD6_SIG_SEL == 4)
using ftm0_ch6             = const USBDM::Ftm0<6>;
using ftm_nRF24L01_mosi    = const USBDM::Ftm0<6>;
#endif
#if (PTD7_SIG_SEL == 4)
using ftm0_ch7             = const USBDM::Ftm0<7>;
using ftm_nRF24L01_miso    = const USBDM::Ftm0<7>;
#endif
/**
 * @}
 */
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
   Ftm_T<getPortClockMask(ftmChannel,Ftm1Info), getPcrReg(ftmChannel,Ftm1Info), getPcrMux(ftmChannel,Ftm1Info), FTM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM1_CLOCK_REG), FTM1_CLOCK_MASK, FTM1_SC, ftmChannel>;

/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA8_SIG_SEL == 3)
using ftm1_ch0             = const USBDM::Ftm1<0>;
#endif
#if (PTA9_SIG_SEL == 3)
using ftm1_ch1             = const USBDM::Ftm1<1>;
#endif
#if (PTA12_SIG_SEL == 3)
using ftm1_ch0             = const USBDM::Ftm1<0>;
#endif
#if (PTA13_SIG_SEL == 3)
using ftm1_ch1             = const USBDM::Ftm1<1>;
#endif
#if (PTB0_SIG_SEL == 3)
using ftm1_ch0             = const USBDM::Ftm1<0>;
#endif
#if (PTB1_SIG_SEL == 3)
using ftm1_ch1             = const USBDM::Ftm1<1>;
#endif
#if (PTB12_SIG_SEL == 3)
using ftm1_ch0             = const USBDM::Ftm1<0>;
#endif
#if (PTB13_SIG_SEL == 3)
using ftm1_ch1             = const USBDM::Ftm1<1>;
#endif
/**
 * @}
 */
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
template<uint8_t ftmChannel> using Ftm2 =
   Ftm_T<getPortClockMask(ftmChannel,Ftm2Info), getPcrReg(ftmChannel,Ftm2Info), getPcrMux(ftmChannel,Ftm2Info), FTM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM2_CLOCK_REG), FTM2_CLOCK_MASK, FTM2_SC, ftmChannel>;

/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA10_SIG_SEL == 3)
using ftm2_ch0             = const USBDM::Ftm2<0>;
#endif
#if (PTA11_SIG_SEL == 3)
using ftm2_ch1             = const USBDM::Ftm2<1>;
#endif
#if (PTB18_SIG_SEL == 3)
using ftm2_ch0             = const USBDM::Ftm2<0>;
#endif
#if (PTB19_SIG_SEL == 3)
using ftm2_ch1             = const USBDM::Ftm2<1>;
#endif
/**
 * @}
 */
/**
 * Convenience templated class representing an SPI pin
 *
 * Example
 * @code
 * using spi0_PCS0 = const USBDM::Spi0Pin<3>;
 * @endcode
 *
 * @tparam spiPinNum    SPI pin number (index into SpiInfo[])
 */
template<uint8_t spiPinNum> using Spi0Pin =
   Pcr_T<getPortClockMask(spiPinNum,Spi0Info), getPcrReg(spiPinNum,Spi0Info), PORT_PCR_MUX(getPcrMux(spiPinNum, Spi0Info))|DEFAULT_PCR>;

/**
* @addtogroup SpiIO_Group SPI, Serial Peripheral Interface
* @brief Pins used for SPI functions
* @{
*/
using spi0_PCS0            = const USBDM::Spi0Pin<3>;
using spi0_SCK             = const USBDM::Spi0Pin<0>;
using spi0_SOUT            = const USBDM::Spi0Pin<2>;
using spi0_SIN             = const USBDM::Spi0Pin<1>;
using spi0_PCS5            = const USBDM::Spi0Pin<8>;
using spi0_PCS4            = const USBDM::Spi0Pin<7>;
using spi0_PCS3            = const USBDM::Spi0Pin<6>;
using spi0_PCS2            = const USBDM::Spi0Pin<5>;
using spi0_PCS1            = const USBDM::Spi0Pin<4>;
/**
 * @}
 */
/**
 * Convenience templated class representing an SPI pin
 *
 * Example
 * @code
 * using spi0_PCS0 = const USBDM::Spi0Pin<3>;
 * @endcode
 *
 * @tparam spiPinNum    SPI pin number (index into SpiInfo[])
 */
template<uint8_t spiPinNum> using Spi1Pin =
   Pcr_T<getPortClockMask(spiPinNum,Spi1Info), getPcrReg(spiPinNum,Spi1Info), PORT_PCR_MUX(getPcrMux(spiPinNum, Spi1Info))|DEFAULT_PCR>;

/**
* @addtogroup SpiIO_Group SPI, Serial Peripheral Interface
* @brief Pins used for SPI functions
* @{
*/
using spi1_PCS1            = const USBDM::Spi1Pin<4>;
using spi1_PCS0            = const USBDM::Spi1Pin<3>;
using spi1_SCK             = const USBDM::Spi1Pin<0>;
using spi1_SOUT            = const USBDM::Spi1Pin<2>;
using spi1_SIN             = const USBDM::Spi1Pin<1>;
using spi1_PCS2            = const USBDM::Spi1Pin<5>;
using spi1_PCS3            = const USBDM::Spi1Pin<6>;
/**
 * @}
 */
/**
 * Convenience templated class representing an SPI pin
 *
 * Example
 * @code
 * using spi0_PCS0 = const USBDM::Spi0Pin<3>;
 * @endcode
 *
 * @tparam spiPinNum    SPI pin number (index into SpiInfo[])
 */
template<uint8_t spiPinNum> using Spi2Pin =
   Pcr_T<getPortClockMask(spiPinNum,Spi2Info), getPcrReg(spiPinNum,Spi2Info), PORT_PCR_MUX(getPcrMux(spiPinNum, Spi2Info))|DEFAULT_PCR>;

/**
* @addtogroup SpiIO_Group SPI, Serial Peripheral Interface
* @brief Pins used for SPI functions
* @{
*/
using spi2_PCS0            = const USBDM::Spi2Pin<3>;
using spi2_SCK             = const USBDM::Spi2Pin<0>;
using spi2_SOUT            = const USBDM::Spi2Pin<2>;
using spi2_SIN             = const USBDM::Spi2Pin<1>;
using spi2_PCS1            = const USBDM::Spi2Pin<4>;
/**
 * @}
 */
#if (DO_MAP_PINS_ON_RESET>0)
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
extern void usbdm_PinMapping();
#endif

} // End namespace USBDM

#endif /* GPIO_H_ */
