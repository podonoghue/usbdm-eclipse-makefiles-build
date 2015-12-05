/**
 * @file      gpio.h (derived from gpio-MKM33Z5.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKM33Z5
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
using gpio_LED_RED         = const USBDM::GpioA<0>;
using gpioA_1              = const USBDM::GpioA<1>;
using gpio_LED_GREEN       = const USBDM::GpioA<1>;
using gpioA_2              = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpioA_6              = const USBDM::GpioA<6>;
using gpioA_7              = const USBDM::GpioA<7>;
using gpioB_0              = const USBDM::GpioB<0>;
using gpioB_1              = const USBDM::GpioB<1>;
using gpioB_2              = const USBDM::GpioB<2>;
using gpioB_3              = const USBDM::GpioB<3>;
using gpioB_4              = const USBDM::GpioB<4>;
using gpioB_5              = const USBDM::GpioB<5>;
using gpioB_6              = const USBDM::GpioB<6>;
using gpioB_7              = const USBDM::GpioB<7>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
using gpioC_7              = const USBDM::GpioC<7>;
using gpioD_0              = const USBDM::GpioD<0>;
using gpioD_1              = const USBDM::GpioD<1>;
using gpio_LED_BLUE        = const USBDM::GpioD<1>;
using gpioD_2              = const USBDM::GpioD<2>;
using gpioD_3              = const USBDM::GpioD<3>;
using gpioD_4              = const USBDM::GpioD<4>;
using gpioD_5              = const USBDM::GpioD<5>;
using gpioD_6              = const USBDM::GpioD<6>;
using gpioD_7              = const USBDM::GpioD<7>;
using gpioE_0              = const USBDM::GpioE<0>;
using gpioE_1              = const USBDM::GpioE<1>;
using gpioE_2              = const USBDM::GpioE<2>;
using gpioE_3              = const USBDM::GpioE<3>;
using gpioE_4              = const USBDM::GpioE<4>;
using gpioE_5              = const USBDM::GpioE<5>;
using gpioE_6              = const USBDM::GpioE<6>;
using gpioE_7              = const USBDM::GpioE<7>;
using gpioF_0              = const USBDM::GpioF<0>;
using gpioF_1              = const USBDM::GpioF<1>;
using gpioF_2              = const USBDM::GpioF<2>;
using gpioF_3              = const USBDM::GpioF<3>;
using gpioF_4              = const USBDM::GpioF<4>;
using gpioF_5              = const USBDM::GpioF<5>;
using gpioF_6              = const USBDM::GpioF<6>;
using gpioF_7              = const USBDM::GpioF<7>;
using gpioG_0              = const USBDM::GpioG<0>;
using gpioG_1              = const USBDM::GpioG<1>;
using gpioG_2              = const USBDM::GpioG<2>;
using gpioG_3              = const USBDM::GpioG<3>;
using gpioG_4              = const USBDM::GpioG<4>;
using gpioG_5              = const USBDM::GpioG<5>;
using gpioG_6              = const USBDM::GpioG<6>;
using gpioG_7              = const USBDM::GpioG<7>;
using gpioH_0              = const USBDM::GpioH<0>;
using gpioH_1              = const USBDM::GpioH<1>;
using gpioH_2              = const USBDM::GpioH<2>;
using gpioH_3              = const USBDM::GpioH<3>;
using gpioH_4              = const USBDM::GpioH<4>;
using gpioH_5              = const USBDM::GpioH<5>;
using gpioH_6              = const USBDM::GpioH<6>;
using gpioH_7              = const USBDM::GpioH<7>;
using gpioI_0              = const USBDM::GpioI<0>;
using gpioI_1              = const USBDM::GpioI<1>;
using gpioI_2              = const USBDM::GpioI<2>;
using gpioI_3              = const USBDM::GpioI<3>;
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
   Analogue_T<getPortClockMask(adcChannel,Adc0Info), getPcrReg(adcChannel,Adc0Info), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

#if (PTC5_SIG_SEL == 0)
using adc0_se0             = const USBDM::Adc0<0>;
#endif
#if (PTC6_SIG_SEL == 0)
using adc0_se1             = const USBDM::Adc0<1>;
#endif
#if (PTC7_SIG_SEL == 0)
using adc0_se2             = const USBDM::Adc0<2>;
#endif
#if (PTD4_SIG_SEL == 0)
using adc0_se3             = const USBDM::Adc0<3>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc0_se4             = const USBDM::Adc0<4>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc0_se5             = const USBDM::Adc0<5>;
#endif
#if (PTE7_SIG_SEL == 0)
using adc0_se6             = const USBDM::Adc0<6>;
#endif
#if (PTF0_SIG_SEL == 0)
using adc0_se7             = const USBDM::Adc0<7>;
#endif
#if (PTF1_SIG_SEL == 0)
using adc0_se8             = const USBDM::Adc0<8>;
#endif
#if (PTF2_SIG_SEL == 0)
using adc0_se9             = const USBDM::Adc0<9>;
#endif
#if (PTG1_SIG_SEL == 0)
using adc0_se10            = const USBDM::Adc0<10>;
#endif
#if (PTG2_SIG_SEL == 0)
using adc0_se11            = const USBDM::Adc0<11>;
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
   Digital_T<getPortClockMask(i2cPinIndex,I2c0Info), getPcrReg(i2cPinIndex,I2c0Info), PORT_PCR_MUX(FIXED_GPIO_FN)|I2C_DEFAULT_PCR,
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
   Digital_T<getPortClockMask(i2cPinIndex,I2c1Info), getPcrReg(i2cPinIndex,I2c1Info), PORT_PCR_MUX(FIXED_GPIO_FN)|I2C_DEFAULT_PCR,
             getGpioAddress(i2cPinIndex,I2c1Info),   getGpioBit(i2cPinIndex,I2c1Info)>;
using i2c1_SDAPcr    = const USBDM::I2c1Pcr<1>;
using i2c1_SDAGpio   = const USBDM::I2c1Gpio<1>;
using i2c1_SCLPcr    = const USBDM::I2c1Pcr<0>;
using i2c1_SCLGpio   = const USBDM::I2c1Gpio<0>;
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
