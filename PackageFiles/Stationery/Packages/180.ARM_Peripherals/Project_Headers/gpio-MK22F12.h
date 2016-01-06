/**
 * @file      gpio.h (derived from gpio-MK22F12.h)
 * @version   1.1.0
 * @brief     Pin declarations for MK22F12
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
using gpioA_2              = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpioA_12             = const USBDM::GpioA<12>;
using gpioA_13             = const USBDM::GpioA<13>;
using gpioA_18             = const USBDM::GpioA<18>;
using gpioA_19             = const USBDM::GpioA<19>;
using gpioB_0              = const USBDM::GpioB<0>;
using gpioB_1              = const USBDM::GpioB<1>;
using gpioB_2              = const USBDM::GpioB<2>;
using gpioB_3              = const USBDM::GpioB<3>;
using gpioB_16             = const USBDM::GpioB<16>;
using gpioB_17             = const USBDM::GpioB<17>;
using gpioB_18             = const USBDM::GpioB<18>;
using gpioB_19             = const USBDM::GpioB<19>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
using gpioC_7              = const USBDM::GpioC<7>;
using gpioC_8              = const USBDM::GpioC<8>;
using gpioC_9              = const USBDM::GpioC<9>;
using gpioC_10             = const USBDM::GpioC<10>;
using gpioC_11             = const USBDM::GpioC<11>;
using gpioD_0              = const USBDM::GpioD<0>;
using gpioD_1              = const USBDM::GpioD<1>;
using gpioD_2              = const USBDM::GpioD<2>;
using gpioD_3              = const USBDM::GpioD<3>;
using gpioD_4              = const USBDM::GpioD<4>;
using gpioD_5              = const USBDM::GpioD<5>;
using gpioD_6              = const USBDM::GpioD<6>;
using gpioD_7              = const USBDM::GpioD<7>;
using gpioE_0              = const USBDM::GpioE<0>;
using gpioE_1              = const USBDM::GpioE<1>;
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

using adc0_se23            = const USBDM::Adc0<23>;
#if (PTB0_SIG_SEL == 0)
using adc0_se8             = const USBDM::Adc0<8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc0_se9             = const USBDM::Adc0<9>;
#endif
#if (PTB2_SIG_SEL == 0)
using adc0_se12            = const USBDM::Adc0<12>;
#endif
#if (PTB3_SIG_SEL == 0)
using adc0_se13            = const USBDM::Adc0<13>;
#endif
#if (PTC0_SIG_SEL == 0)
using adc0_se14            = const USBDM::Adc0<14>;
#endif
#if (PTC1_SIG_SEL == 0)
using adc0_se15            = const USBDM::Adc0<15>;
#endif
#if (PTC2_SIG_SEL == 0)
using adc0_se4b            = const USBDM::Adc0<4>;
#endif
#if (PTD1_SIG_SEL == 0)
using adc0_se5b            = const USBDM::Adc0<5>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc0_se6b            = const USBDM::Adc0<6>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc0_se7b            = const USBDM::Adc0<7>;
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
template<uint8_t adcChannel> using Adc1 =
   Adc_T<getPortClockMask(adcChannel,Adc1Info), getPcrReg(adcChannel,Adc1Info), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG), ADC1_CLOCK_MASK, adcChannel>;

using adc1_se18            = const USBDM::Adc1<18>;
#if (PTB0_SIG_SEL == 0)
using adc1_se8             = const USBDM::Adc1<8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc1_se9             = const USBDM::Adc1<9>;
#endif
#if (PTC8_SIG_SEL == 0)
using adc1_se4b            = const USBDM::Adc1<4>;
#endif
#if (PTC9_SIG_SEL == 0)
using adc1_se5b            = const USBDM::Adc1<5>;
#endif
#if (PTC10_SIG_SEL == 0)
using adc1_se6b            = const USBDM::Adc1<6>;
#endif
#if (PTC11_SIG_SEL == 0)
using adc1_se7b            = const USBDM::Adc1<7>;
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
template<uint8_t adcChannel> using Adc1a =
   Adc_T<getPortClockMask(adcChannel,Adc1aInfo), getPcrReg(adcChannel,Adc1aInfo), ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG), ADC1_CLOCK_MASK, adcChannel>;

#if (PTE0_SIG_SEL == 0)
using adc1_se4a            = const USBDM::Adc1a<4>;
#endif
#if (PTE1_SIG_SEL == 0)
using adc1_se5a            = const USBDM::Adc1a<5>;
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

#if (PTA0_SIG_SEL == 3)
using ftm0_ch5             = const USBDM::Ftm0<5>;
#endif
#if (PTA1_SIG_SEL == 3)
using ftm0_ch6             = const USBDM::Ftm0<6>;
#endif
#if (PTA2_SIG_SEL == 3)
using ftm0_ch7             = const USBDM::Ftm0<7>;
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
#if (PTC1_SIG_SEL == 4)
using ftm0_ch0             = const USBDM::Ftm0<0>;
#endif
#if (PTC2_SIG_SEL == 4)
using ftm0_ch1             = const USBDM::Ftm0<1>;
#endif
#if (PTC3_SIG_SEL == 4)
using ftm0_ch2             = const USBDM::Ftm0<2>;
#endif
#if (PTC4_SIG_SEL == 4)
using ftm0_ch3             = const USBDM::Ftm0<3>;
#endif
#if (PTC5_SIG_SEL == 7)
using ftm0_ch2             = const USBDM::Ftm0<2>;
#endif
#if (PTD4_SIG_SEL == 4)
using ftm0_ch4             = const USBDM::Ftm0<4>;
#endif
#if (PTD5_SIG_SEL == 4)
using ftm0_ch5             = const USBDM::Ftm0<5>;
#endif
#if (PTD6_SIG_SEL == 4)
using ftm0_ch6             = const USBDM::Ftm0<6>;
#endif
#if (PTD7_SIG_SEL == 4)
using ftm0_ch7             = const USBDM::Ftm0<7>;
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
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
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

using spi0_PCS4            = const USBDM::Spi0Pin<7>;
using spi0_PCS3            = const USBDM::Spi0Pin<6>;
using spi0_PCS2            = const USBDM::Spi0Pin<5>;
using spi0_PCS1            = const USBDM::Spi0Pin<4>;
using spi0_PCS0            = const USBDM::Spi0Pin<3>;
using spi0_SCK             = const USBDM::Spi0Pin<0>;
using spi0_SOUT            = const USBDM::Spi0Pin<2>;
using spi0_SIN             = const USBDM::Spi0Pin<1>;
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
template<uint8_t i2cPinIndex> using I2c2Pcr =
   Pcr_T<getPortClockMask(i2cPinIndex,I2c2Info), getPcrReg(i2cPinIndex,I2c2Info), PORT_PCR_MUX(getPcrMux(i2cPinIndex, I2c2Info))|I2C_DEFAULT_PCR>;

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
template<uint8_t i2cPinIndex> using I2c2Gpio =
   Gpio_T<getPortClockMask(i2cPinIndex,I2c2Info), getPcrReg(i2cPinIndex,I2c2Info), PORT_PCR_MUX(FIXED_GPIO_FN)|I2C_DEFAULT_PCR,
             getGpioAddress(i2cPinIndex,I2c2Info),   getGpioBit(i2cPinIndex,I2c2Info)>;
using i2c2_SCLPcr    = const USBDM::I2c2Pcr<0>;
using i2c2_SCLGpio   = const USBDM::I2c2Gpio<0>;
using i2c2_SDAPcr    = const USBDM::I2c2Pcr<1>;
using i2c2_SDAGpio   = const USBDM::I2c2Gpio<1>;
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
DMA0_SLOT_UART0_Receive              = 2,
DMA0_SLOT_UART0_Transmit             = 3,
DMA0_SLOT_UART1_Receive              = 4,
DMA0_SLOT_UART1_Transmit             = 5,
DMA0_SLOT_UART2_Receive              = 6,
DMA0_SLOT_UART2_Transmit             = 7,
DMA0_SLOT_I2S0_Receive               = 12,
DMA0_SLOT_I2S0_Transmit              = 13,
DMA0_SLOT_SPI0_Receive               = 14,
DMA0_SLOT_SPI0_Transmit              = 15,
DMA0_SLOT_SPI0_TransmitReceive       = 16,
DMA0_SLOT_I2C0                       = 18,
DMA0_SLOT_I2C1                       = 19,
DMA0_SLOT_FTM0_Ch_0                  = 20,
DMA0_SLOT_FTM0_Ch_1                  = 21,
DMA0_SLOT_FTM0_Ch_2                  = 22,
DMA0_SLOT_FTM0_Ch_3                  = 23,
DMA0_SLOT_FTM0_Ch_4                  = 24,
DMA0_SLOT_FTM0_Ch_5                  = 25,
DMA0_SLOT_FTM0_Ch_6                  = 26,
DMA0_SLOT_FTM0_Ch_7                  = 27,
DMA0_SLOT_FTM1_Ch_0                  = 28,
DMA0_SLOT_FTM1_Ch_1                  = 29,
DMA0_SLOT_FTM2_Ch_0                  = 30,
DMA0_SLOT_FTM2_Ch_1                  = 31,
DMA0_SLOT_FTM3_Ch_0                  = 32,
DMA0_SLOT_FTM3_Ch_1                  = 33,
DMA0_SLOT_FTM3_Ch_2                  = 34,
DMA0_SLOT_FTM3_Ch_3                  = 35,
DMA0_SLOT_FTM3_Ch_4                  = 36,
DMA0_SLOT_FTM3_Ch_5                  = 37,
DMA0_SLOT_FTM3_Ch_6                  = 38,
DMA0_SLOT_FTM3_Ch_7                  = 39,
DMA0_SLOT_ADC0                       = 40,
DMA0_SLOT_ADC1                       = 41,
DMA0_SLOT_CMP0                       = 42,
DMA0_SLOT_CMP1                       = 43,
DMA0_SLOT_DAC0                       = 45,
DMA0_SLOT_DAC1                       = 46,
DMA0_SLOT_PDB                        = 48,
DMA0_SLOT_PortA                      = 49,
DMA0_SLOT_PortB                      = 50,
DMA0_SLOT_PortC                      = 51,
DMA0_SLOT_PortD                      = 52,
DMA0_SLOT_PortE                      = 53,
DMA0_SLOT_LPUART_Receive             = 58,
DMA0_SLOT_LPUART_Transmit            = 59,
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
