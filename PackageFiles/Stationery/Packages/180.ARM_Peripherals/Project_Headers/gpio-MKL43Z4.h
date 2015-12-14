/**
 * @file      gpio.h (derived from gpio-MKL43Z4.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKL43Z4
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
using gpioA_2              = const USBDM::GpioA<2>;
using gpio_D1              = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpio_D4              = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpio_D5              = const USBDM::GpioA<5>;
using gpioA_12             = const USBDM::GpioA<12>;
using gpio_D3              = const USBDM::GpioA<12>;
using gpioA_13             = const USBDM::GpioA<13>;
using gpio_D8              = const USBDM::GpioA<13>;
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
using gpioB_16             = const USBDM::GpioB<16>;
using gpioB_17             = const USBDM::GpioB<17>;
using gpioB_18             = const USBDM::GpioB<18>;
using gpioB_19             = const USBDM::GpioB<19>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpio_A5              = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpio_A4              = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpio_ACCEL_INT1      = const USBDM::GpioC<5>;
using gpio_MAG_INT         = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
using gpioC_7              = const USBDM::GpioC<7>;
using gpioD_0              = const USBDM::GpioD<0>;
using gpioD_1              = const USBDM::GpioD<1>;
using gpio_ACCEL_INT2      = const USBDM::GpioD<1>;
using gpioD_2              = const USBDM::GpioD<2>;
using gpio_D9              = const USBDM::GpioD<2>;
using gpioD_3              = const USBDM::GpioD<3>;
using gpio_D2              = const USBDM::GpioD<3>;
using gpioD_4              = const USBDM::GpioD<4>;
using gpio_D10             = const USBDM::GpioD<4>;
using gpioD_5              = const USBDM::GpioD<5>;
using gpio_D13             = const USBDM::GpioD<5>;
using gpio_LED_GREEN       = const USBDM::GpioD<5>;
using gpioD_6              = const USBDM::GpioD<6>;
using gpio_D11             = const USBDM::GpioD<6>;
using gpioD_7              = const USBDM::GpioD<7>;
using gpioE_0              = const USBDM::GpioE<0>;
using gpio_D14             = const USBDM::GpioE<0>;
using gpioE_1              = const USBDM::GpioE<1>;
using gpio_D15             = const USBDM::GpioE<1>;
using gpioE_20             = const USBDM::GpioE<20>;
using gpioE_21             = const USBDM::GpioE<21>;
using gpioE_22             = const USBDM::GpioE<22>;
using gpio_LIGHT_SENS      = const USBDM::GpioE<22>;
using gpioE_23             = const USBDM::GpioE<23>;
using gpioE_24             = const USBDM::GpioE<24>;
using gpio_ONBOARD_SCL     = const USBDM::GpioE<24>;
using gpioE_25             = const USBDM::GpioE<25>;
using gpio_ONBOARD_SDA     = const USBDM::GpioE<25>;
using gpioE_29             = const USBDM::GpioE<29>;
using gpio_D6              = const USBDM::GpioE<29>;
using gpioE_30             = const USBDM::GpioE<30>;
using gpio_D7              = const USBDM::GpioE<30>;
using gpioE_31             = const USBDM::GpioE<31>;
using gpio_LED_RED         = const USBDM::GpioE<31>;
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
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
   Adc_T<getPortClockMask(adcChannel,Adc0Info), getPcrReg(adcChannel,Adc0Info), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

#if (PTB0_SIG_SEL == 0)
using adc0_se8             = const USBDM::Adc0<8>;
using adc_A0               = const USBDM::Adc0<8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc0_se9             = const USBDM::Adc0<9>;
using adc_A1               = const USBDM::Adc0<9>;
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
using adc0_se5b            = const USBDM::Adc0<5>;
using adc_ACCEL_INT2       = const USBDM::Adc0<5>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc0_se6b            = const USBDM::Adc0<6>;
using adc_D13              = const USBDM::Adc0<6>;
using adc_LED_GREEN        = const USBDM::Adc0<6>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc0_se7b            = const USBDM::Adc0<7>;
using adc_D11              = const USBDM::Adc0<7>;
#endif
#if (PTE20_SIG_SEL == 0)
using adc0_se0             = const USBDM::Adc0<0>;
#endif
#if (PTE22_SIG_SEL == 0)
using adc0_se3             = const USBDM::Adc0<3>;
using adc_LIGHT_SENS       = const USBDM::Adc0<3>;
#endif
#if (PTE29_SIG_SEL == 0)
using adc0_se4b            = const USBDM::Adc0<4>;
using adc_D6               = const USBDM::Adc0<4>;
#endif
#if (PTE30_SIG_SEL == 0)
using adc0_se23            = const USBDM::Adc0<23>;
using adc_D7               = const USBDM::Adc0<23>;
#endif
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
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
template<uint8_t adcChannel> using Adc0a =
   Adc_T<getPortClockMask(adcChannel,Adc0aInfo), getPcrReg(adcChannel,Adc0aInfo), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

#if (PTE21_SIG_SEL == 0)
using adc0_se4a            = const USBDM::Adc0a<4>;
#endif
#if (PTE23_SIG_SEL == 0)
using adc0_se7a            = const USBDM::Adc0a<7>;
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
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
   Tpm_T<getPortClockMask(tpmChannel,Tpm0Info), getPcrReg(tpmChannel,Tpm0Info), getPcrMux(tpmChannel,Tpm0Info), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, TPM0_SC, tpmChannel>;

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
#endif
#if (PTC4_SIG_SEL == 4)
using tpm0_ch3             = const USBDM::Tpm0<3>;
#endif
#if (PTD0_SIG_SEL == 4)
using tpm0_ch0             = const USBDM::Tpm0<0>;
#endif
#if (PTD1_SIG_SEL == 4)
using tpm0_ch1             = const USBDM::Tpm0<1>;
using tpm_ACCEL_INT2       = const USBDM::Tpm0<1>;
#endif
#if (PTD2_SIG_SEL == 4)
using tpm0_ch2             = const USBDM::Tpm0<2>;
using tpm_D9               = const USBDM::Tpm0<2>;
#endif
#if (PTD3_SIG_SEL == 4)
using tpm0_ch3             = const USBDM::Tpm0<3>;
using tpm_D2               = const USBDM::Tpm0<3>;
#endif
#if (PTD4_SIG_SEL == 4)
using tpm0_ch4             = const USBDM::Tpm0<4>;
using tpm_D10              = const USBDM::Tpm0<4>;
#endif
#if (PTD5_SIG_SEL == 4)
using tpm0_ch5             = const USBDM::Tpm0<5>;
using tpm_D13              = const USBDM::Tpm0<5>;
using tpm_LED_GREEN        = const USBDM::Tpm0<5>;
#endif
#if (PTE24_SIG_SEL == 3)
using tpm0_ch0             = const USBDM::Tpm0<0>;
using tpm_ONBOARD_SCL      = const USBDM::Tpm0<0>;
#endif
#if (PTE25_SIG_SEL == 3)
using tpm0_ch1             = const USBDM::Tpm0<1>;
using tpm_ONBOARD_SDA      = const USBDM::Tpm0<1>;
#endif
#if (PTE29_SIG_SEL == 3)
using tpm0_ch2             = const USBDM::Tpm0<2>;
using tpm_D6               = const USBDM::Tpm0<2>;
#endif
#if (PTE30_SIG_SEL == 3)
using tpm0_ch3             = const USBDM::Tpm0<3>;
using tpm_D7               = const USBDM::Tpm0<3>;
#endif
#if (PTE31_SIG_SEL == 3)
using tpm0_ch4             = const USBDM::Tpm0<4>;
using tpm_LED_RED          = const USBDM::Tpm0<4>;
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
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
   Tpm_T<getPortClockMask(tpmChannel,Tpm1Info), getPcrReg(tpmChannel,Tpm1Info), getPcrMux(tpmChannel,Tpm1Info), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, TPM0_SC, tpmChannel>;

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
#endif
#if (PTE21_SIG_SEL == 3)
using tpm1_ch1             = const USBDM::Tpm1<1>;
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
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
template<uint8_t tpmChannel> using Tpm2 =
   Tpm_T<getPortClockMask(tpmChannel,Tpm2Info), getPcrReg(tpmChannel,Tpm2Info), getPcrMux(tpmChannel,Tpm2Info), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, TPM0_SC, tpmChannel>;

#if (PTA1_SIG_SEL == 3)
using tpm2_ch0             = const USBDM::Tpm2<0>;
using tpm_D0               = const USBDM::Tpm2<0>;
#endif
#if (PTA2_SIG_SEL == 3)
using tpm2_ch1             = const USBDM::Tpm2<1>;
using tpm_D1               = const USBDM::Tpm2<1>;
#endif
#if (PTB2_SIG_SEL == 3)
using tpm2_ch0             = const USBDM::Tpm2<0>;
using tpm_A2               = const USBDM::Tpm2<0>;
#endif
#if (PTB3_SIG_SEL == 3)
using tpm2_ch1             = const USBDM::Tpm2<1>;
using tpm_A3               = const USBDM::Tpm2<1>;
#endif
#if (PTB18_SIG_SEL == 3)
using tpm2_ch0             = const USBDM::Tpm2<0>;
#endif
#if (PTB19_SIG_SEL == 3)
using tpm2_ch1             = const USBDM::Tpm2<1>;
#endif
#if (PTE22_SIG_SEL == 3)
using tpm2_ch0             = const USBDM::Tpm2<0>;
using tpm_LIGHT_SENS       = const USBDM::Tpm2<0>;
#endif
#if (PTE23_SIG_SEL == 3)
using tpm2_ch1             = const USBDM::Tpm2<1>;
#endif
/**
 * @}
 */
/**
* @addtogroup SpiIO_Group SPI, Serial Peripheral Interface
* @brief Pins used for SPI functions
* @{
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

using spi0_SCK             = const USBDM::Spi0Pin<0>;
using spi0_MOSI            = const USBDM::Spi0Pin<2>;
using spi0_MISO            = const USBDM::Spi0Pin<1>;
/**
 * @}
 */
/**
* @addtogroup SpiIO_Group SPI, Serial Peripheral Interface
* @brief Pins used for SPI functions
* @{
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

using spi1_MOSI            = const USBDM::Spi1Pin<2>;
using spi1_MISO            = const USBDM::Spi1Pin<1>;
using spi1_SCK             = const USBDM::Spi1Pin<0>;
/**
 * @}
 */
/**
* @addtogroup I2CIO_Group I2C, Inter-Integrated-Circuit Interface
* @brief Pins used for I2C functions
* @{
*/
/**
 * Convenience templated class representing PCR associated with a I2C pin
 *
 * Example
 * @code
 * using i2c0_SCLPin = const USBDM::I2c0Pin<3>;
 * @endcode
 *
 * @tparam i2cPinIndex    I2C pin number (index into I2cInfo[])
 */
template<uint8_t i2cPinIndex> using I2c0Pcr =
   Pcr_T<getPortClockMask(i2cPinIndex,I2c0Info), getPcrReg(i2cPinIndex,I2c0Info), PORT_PCR_MUX(getPcrMux(i2cPinIndex, I2c0Info))|I2C_DEFAULT_PCR>;

/**
 * Convenience templated class representing a GPIO used as I2C pin
 *
 * Example
 * @code
 * using i2c0_SCLGpio = const USBDM::I2c0Gpio<3>;
 * @endcode
 *
 * @tparam i2cPinIndex    I2C pin number (index into I2cInfo[])
 */
template<uint8_t i2cPinIndex> using I2c0Gpio =
   Gpio_T<getPortClockMask(i2cPinIndex,I2c0Info), getPcrReg(i2cPinIndex,I2c0Info), PORT_PCR_MUX(FIXED_GPIO_FN)|I2C_DEFAULT_PCR,
             getGpioAddress(i2cPinIndex,I2c0Info),   getGpioBit(i2cPinIndex,I2c0Info)>;
using i2c0_SCLPcr    = const USBDM::I2c0Pcr<0>;
using i2c0_SCLGpio   = const USBDM::I2c0Gpio<0>;
using i2c0_SDAPcr    = const USBDM::I2c0Pcr<1>;
using i2c0_SDAGpio   = const USBDM::I2c0Gpio<1>;
/**
 * @}
 */
/**
* @addtogroup I2CIO_Group I2C, Inter-Integrated-Circuit Interface
* @brief Pins used for I2C functions
* @{
*/
/**
 * Convenience templated class representing PCR associated with a I2C pin
 *
 * Example
 * @code
 * using i2c0_SCLPin = const USBDM::I2c0Pin<3>;
 * @endcode
 *
 * @tparam i2cPinIndex    I2C pin number (index into I2cInfo[])
 */
template<uint8_t i2cPinIndex> using I2c1Pcr =
   Pcr_T<getPortClockMask(i2cPinIndex,I2c1Info), getPcrReg(i2cPinIndex,I2c1Info), PORT_PCR_MUX(getPcrMux(i2cPinIndex, I2c1Info))|I2C_DEFAULT_PCR>;

/**
 * Convenience templated class representing a GPIO used as I2C pin
 *
 * Example
 * @code
 * using i2c0_SCLGpio = const USBDM::I2c0Gpio<3>;
 * @endcode
 *
 * @tparam i2cPinIndex    I2C pin number (index into I2cInfo[])
 */
template<uint8_t i2cPinIndex> using I2c1Gpio =
   Gpio_T<getPortClockMask(i2cPinIndex,I2c1Info), getPcrReg(i2cPinIndex,I2c1Info), PORT_PCR_MUX(FIXED_GPIO_FN)|I2C_DEFAULT_PCR,
             getGpioAddress(i2cPinIndex,I2c1Info),   getGpioBit(i2cPinIndex,I2c1Info)>;
using i2c1_SCLPcr    = const USBDM::I2c1Pcr<0>;
using i2c1_SCLGpio   = const USBDM::I2c1Gpio<0>;
using i2c1_SDAPcr    = const USBDM::I2c1Pcr<1>;
using i2c1_SDAGpio   = const USBDM::I2c1Gpio<1>;
/**
 * @}
 */
/**
* @addtogroup DMA_Group Direct Memory Access (DMA)
* @brief Support for DMA operations
* @{
*/
enum {
DMA0_SLOT_Disabled                   = 0,
DMA0_SLOT_LPUART0_Receive            = 2,
DMA0_SLOT_LPUART0_Transmit           = 3,
DMA0_SLOT_LPUART1_Receive            = 4,
DMA0_SLOT_LPUART1_Transmit           = 5,
DMA0_SLOT_UART2_Receive              = 6,
DMA0_SLOT_UART2_Transmit             = 7,
DMA0_SLOT_FlexIO_Ch0                 = 10,
DMA0_SLOT_FlexIO_Ch1                 = 11,
DMA0_SLOT_FlexIO_Ch2                 = 12,
DMA0_SLOT_FlexIO_Ch3                 = 13,
DMA0_SLOT_I2S0_Receive               = 14,
DMA0_SLOT_I2S0_Transmit              = 15,
DMA0_SLOT_SPI0_Receive               = 16,
DMA0_SLOT_SPI0_Transmit              = 17,
DMA0_SLOT_SPI1_Receive               = 18,
DMA0_SLOT_SPI1_Transmit              = 19,
DMA0_SLOT_I2C0                       = 22,
DMA0_SLOT_I2C1                       = 23,
DMA0_SLOT_TPM0_Ch_0                  = 24,
DMA0_SLOT_TPM0_Ch_1                  = 25,
DMA0_SLOT_TPM0_Ch_2                  = 26,
DMA0_SLOT_TPM0_Ch_3                  = 27,
DMA0_SLOT_TPM0_Ch_4                  = 28,
DMA0_SLOT_TPM0_Ch_5                  = 29,
DMA0_SLOT_TPM1_Ch_0                  = 32,
DMA0_SLOT_TPM1_Ch_1                  = 33,
DMA0_SLOT_TPM2_Ch_0                  = 34,
DMA0_SLOT_TPM2_Ch_1                  = 35,
DMA0_SLOT_ADC0                       = 40,
DMA0_SLOT_CMP0                       = 42,
DMA0_SLOT_DAC0                       = 45,
DMA0_SLOT_PortA                      = 49,
DMA0_SLOT_PortC                      = 51,
DMA0_SLOT_PortD                      = 52,
DMA0_SLOT_TPM0_Overflow              = 54,
DMA0_SLOT_TPM1_Overflow              = 55,
DMA0_SLOT_TPM2_Overflow              = 56,
DMA0_SLOT_AlwaysEnabled0             = 60,
DMA0_SLOT_AlwaysEnabled1             = 61,
DMA0_SLOT_AlwaysEnabled2             = 62,
DMA0_SLOT_AlwaysEnabled3             = 63,
};
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
