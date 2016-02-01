/**
 * @file      gpio.h (derived from gpio-Generic.h)
 * @version   1.1.0
 * @brief     Pin declarations for generic device
 */

#ifndef PROJECT_HEADERS_GPIO_H_
#define PROJECT_HEADERS_GPIO_H_

#include "gpio_defs.h"
#include "pin_mapping.h"

namespace USBDM {

/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#ifdef ADC0_CLOCK_REG
/**
 * Template class representing a ADC0 channel
 *
 * Example
 * @code
 *  // Instantiate ADC channel (Assumes adc0_se8 is mapped to PORTB.2)
 *  const Adc0<PORTB_CLOCK_MASK, PORTB_BasePtr, 2, 8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC();
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam portClockMask Mask for clock register for PORT associated with this ADC
 * @tparam pcrReg        PCR for the PORT pin associated with this ADC
 * @tparam adcChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t port, uint32_t bitNum, uint8_t adcChannel> using Adc0 =
      Adc_T<portClockMask, port, bitNum, ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;
#endif // ADC0_CLOCK_REG

#ifdef ADC1_CLOCK_REG
/**
 * Template class representing a ADC1 channel
 *
 * Example
 * @code
 *  // Instantiate ADC channel (Assumes adc1_se8 is mapped to PORTB.2)
 *  const Adc1<PORTB_CLOCK_MASK, PORTB_BasePtr, 2, 8> adc1_se8;
 *
 *  // Initialise ADC
 *  adc1_se8.initialiseADC();
 *
 *  // Set as analogue input
 *  adc1_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc1_se8.readAnalogue();
 *  @endcode
 *
 * @tparam portClockMask Mask for clock register for PORT associated with this ADC
 * @tparam pcrReg        PCR for the PORT pin associated with this ADC
 * @tparam adcChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t port, uint32_t bitNum, uint8_t adcChannel> using Adc1 =
      Adc_T<portClockMask, port, bitNum, ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG), ADC1_CLOCK_MASK, adcChannel>;
#endif // ADC1_CLOCK_REG
/**
 * @}
 */

/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#ifdef FTM0_CLOCK_REG
/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel 6 (for FTM0 CH6, assuming on PortB.2(Fn3))
 *
 * USBDM::Tmr0<PORTB_CLOCK_MASK, PORTB_BasePtr, 2, 3, 8> tmr0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tmr0_ch6.setMode(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tmr0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tmr0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel    FTM channel
 */
template<uint32_t portClockMask, uint32_t port, uint32_t bitNum, uint32_t ftmMuxFn, uint8_t channel> using Tmr0 =
      TmrBase_T<portClockMask, port, bitNum, ftmMuxFn, FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, FTM0_SC, channel>;
#endif // FTM0_CLOCK_REG

#ifdef FTM1_CLOCK_REG
/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel 6 (for FTM1 CH6, assuming on PortB.2(Fn3))
 *
 * USBDM::Tmr1<PORTB_CLOCK_MASK, PORTB_BasePtr, 2, 3, 8> tmr1_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tmr1_ch6.setMode(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tmr1_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tmr1_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel    FTM channel
 */
template<uint32_t portClockMask, uint32_t port, uint32_t bitNum, uint32_t ftmMuxFn, uint8_t channel> using Tmr1 =
      TmrBase_T<portClockMask, port, bitNum, ftmMuxFn, FTM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM1_CLOCK_REG), FTM1_CLOCK_MASK, FTM1_SC, channel>;
#endif // FTM1_CLOCK_REG

#ifdef FTM2_CLOCK_REG
/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel 6 (for FTM2 CH6, assuming on PortB.2(Fn3))
 *
 * USBDM::Tmr1<PORTB_CLOCK_MASK, PORTB_BasePtr, 2, 3, 8> tmr2_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tmr2_ch6.setMode(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tmr2_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tmr2_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel    FTM channel
 */
template<uint32_t portClockMask, uint32_t port, uint32_t bitNum, uint32_t ftmMuxFn, uint8_t channel> using Tmr1 =
      TmrBase_T<portClockMask, port, bitNum, ftmMuxFn, FTM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM2_CLOCK_REG), FTM2_CLOCK_MASK, FTM2_SC, channel>;
#endif // FTM2_CLOCK_REG

#ifdef FTM3_CLOCK_REG
/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel 6 (for FTM3 CH6, assuming on PortB.2(Fn3))
 *
 * USBDM::Tmr1<PORTB_CLOCK_MASK, PORTB_BasePtr, 2, 3, 8> tmr3_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tmr3_ch6.setMode(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tmr3_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tmr3_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel    FTM channel
 */
template<uint32_t portClockMask, uint32_t port, uint32_t bitNum, uint32_t ftmMuxFn, uint8_t channel> using Tmr1 =
      TmrBase_T<portClockMask, port, bitNum, ftmMuxFn, FTM3_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM3_CLOCK_REG), FTM3_CLOCK_MASK, FTM3_SC, channel>;
#endif // FTM3_CLOCK_REG

/**
 * @}
 */

} // End namespace USBDM

#endif /* PROJECT_HEADERS_GPIO_H_ */
