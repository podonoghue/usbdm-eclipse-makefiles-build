/**
 ============================================================================
 * @file    analogue-comparison-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using ADC comparison hardware with interrupts
 *
 *  Created on: 10/6/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "adc.h"
#include "smc.h"

using namespace USBDM;

/*
 * Demonstrates ADC comparison hardware with interrupts
 */

// Connection - change as required
using Led         = $(/HARDWARE/Led1:GpioB<0,ActiveLow>);

// ADC channel to use
using MyAdcChannel  = Adc0::Channel<Adc0ChannelNum_Analogue_A0>;

// Shared ADC to use
using MyAdc         = MyAdcChannel::Owner;

// Resolution to use for ADC
constexpr AdcResolution ADC_RESOLUTION = AdcResolution_10bit_se;

// Lower window threshold for comparison 20%
constexpr int LOWER_THRESHOLD = MyAdc::getSingleEndedMaximum(ADC_RESOLUTION)*0.2;

// Upper window threshold for comparison 60%
constexpr int UPPER_THRESHOLD = MyAdc::getSingleEndedMaximum(ADC_RESOLUTION)*0.6;

/**
 * ADC callback
 *
 * Will toggle LED while comparison is true
 */
void adcComparisonCallback(uint32_t result, AdcChannelNum channel) {
   (void)result;
   (void)channel;
   Led::toggle();
}

int main() {

   // Enable LED
   Led::setOutput();

   // Connect ADC channel to pin
   MyAdcChannel::setInput();

   static constexpr MyAdc::Init adcInitValue = {
      NvicPriority_Normal ,               // (irqLevel) IRQ priority level
      adcComparisonCallback,              // Call-back

      AdcClockSource_Asynch ,             // (adc_cfg1_adiclk) ADC Clock Source
      ADC_RESOLUTION ,                    // (adc_cfg1_mode) ADC Resolution
      AdcTrigger_Software ,               // (adc_sc2_adtrg) Conversion Trigger Select
      AdcAveraging_4 ,                    // (adc_sc3_avg) Hardware Average Select
      AdcOperation_Continuous ,           // (adc_sc3_adco) Single or continuous conversion
      AdcSample_4cycles ,                 // (adc_sample) Long Sample Time Select
      AdcCompare_OutsideRangeExclusive ,  // (adc_sc2_compare) Compare function
      LOWER_THRESHOLD ,                   // (adc_cv1) ADC CV low value
      UPPER_THRESHOLD ,                   // (adc_cv2) ADC CV high value
      // Software triggered (Pre-trigger0 = SC1A), (adc_sc1_adch) Channel to use and (adc_sc1_aien) IRQ when complete
      AdcPretrigger_0, MyAdcChannel::CHANNEL, AdcAction_Interrupt,
   };
   MyAdc::configure(adcInitValue);

   for(;;) {
      Smc::enterWaitMode();
   }
}
