/**
 * @file     adc.h
 * @brief    ADC routines
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_ADC_H
#define HEADER_ADC_H

#include <stddef.h>
#include <assert.h>
#include "derivative.h"

/*
 * Default port information
 */
#ifndef FIXED_PORT_CLOCK_REG
#define FIXED_PORT_CLOCK_REG SCGC5
#endif

#ifndef FIXED_ADC_FN
#define FIXED_ADC_FN    (0)
#endif

#ifndef ADC0_CLOCK_MASK
#ifdef SIM_SCGC6_ADC0_MASK
#define ADC0_CLOCK_MASK SIM_SCGC6_ADC0_MASK
#define ADC0_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC3_ADC1_MASK
#define ADC1_CLOCK_MASK SIM_SCGC3_ADC1_MASK
#define ADC1_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC6_ADC1_MASK
#define ADC1_CLOCK_MASK SIM_SCGC6_ADC1_MASK
#define ADC1_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_ADC2_MASK
#define ADC2_CLOCK_MASK SIM_SCGC6_ADC2_MASK
#define ADC2_CLOCK_REG  SCGC6
#endif
#endif

namespace USBDM {

/**
 * @addtogroup AnalogueIO_Group Analogue Input
 * @{
 */

/**
 * PCR multiplexor value for analogue function
 */
static constexpr uint32_t    ADC_PORT_FN = PORT_PCR_MUX(FIXED_ADC_FN);
/**
 * Default PCR value for pins used as GPIO (including multiplexor value)
 */
static constexpr uint32_t    ADC_DEFAULT_PCR = ADC_PORT_FN;

/**
 * ADC Resolutions for use with AnalogueIO::setMode()
 */
enum Adc_Resolution {
   resolution_8bit_se    = ADC_CFG1_MODE(0),
   resolution_10bit_se   = ADC_CFG1_MODE(2),
   resolution_12bit_se   = ADC_CFG1_MODE(1),
   resolution_16bit_se   = ADC_CFG1_MODE(3),
   resolution_9bit_diff  = ADC_CFG1_MODE(0),
   resolution_11bit_diff = ADC_CFG1_MODE(2),
   resolution_12bit_diff = ADC_CFG1_MODE(1),
   resolution_16bit_diff = ADC_CFG1_MODE(3),
};

/**
 * Template class representing a pin with Analogue Input capability\n
 * Uses a information structure to describe the ADC
 *
 * Example
 * @code
 *  // Instantiate ADC channel adc0_se8
 *  const Adc_T<adc0Info, 8> adc0_se8;
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
 * @tparam info            Table of information describing ADC
 * @tparam adcChannel      ADC channel
 */
template<class Info, uint8_t adcChannel>
class Adc_T {

#ifdef DEBUG_BUILD
   static_assert((adcChannel<Info::NUM_SIGNALS), "Adc_T: Non-existent ADC channel - Modify Configure.usbdm");
   static_assert((adcChannel>=Info::NUM_SIGNALS)||(Info::info[adcChannel].gpioBit != UNMAPPED_PCR), "Adc_T: ADC channel is not mapped to a pin - Modify Configure.usbdm");
   static_assert((adcChannel>=Info::NUM_SIGNALS)||(Info::info[adcChannel].gpioBit != INVALID_PCR),  "Adc_T: ADC channel doesn't exist in this device/package");
   static_assert((adcChannel>=Info::NUM_SIGNALS)||((Info::info[adcChannel].gpioBit == UNMAPPED_PCR)||(Info::info[adcChannel].gpioBit == INVALID_PCR)||(Info::info[adcChannel].gpioBit >= 0)), "Adc_T: Illegal ADC channel");
#endif

private:
   static constexpr volatile ADC_Type *adc      = reinterpret_cast<volatile ADC_Type *>(Info::basePtr);
   static constexpr volatile uint32_t *clockReg = reinterpret_cast<volatile uint32_t *>(Info::clockReg);

public:
   using Pcr = PcrTable_T<Info, adcChannel>;

   /**
    * Set port pin as analogue input
    *
    * @param mode Mode for converter (currently only resolution)
    *
    * @note This initialises the ADC
    */
   static void setMode(uint32_t mode = resolution_16bit_se) {
      // Enable clock to ADC
      *clockReg  |= Info::clockMask;

      // Set up ADC pin
      Pcr::setPCR(ADC_PORT_FN);

      // Configure ADC for software triggered conversion
      adc->CFG1 = ADC_CFG1_ADIV(1)|mode|ADC_CFG1_ADLSMP_MASK|ADC_CFG1_ADICLK(0);
      adc->SC2  = 0;
      adc->CFG2 = ADC_CFG2_ADLSTS(0)|ADC_CFG2_MUXSEL_MASK; // Choose 'b' channels
   }
   /**
    * Initiates a conversion and waits for it to complete
    *
    * @return - the result of the conversion
    */
   static int readAnalogue() {
      // Trigger conversion
      adc->SC1[0] = ADC_SC1_ADCH(adcChannel);

      while ((adc->SC1[0]&ADC_SC1_COCO_MASK) == 0) {
         __asm__("nop");
      }
      return (int)adc->R[0];
   };
};

/**
 * @}
 */
 
} // End namespace USBDM

#endif /* HEADER_ADC_H */

