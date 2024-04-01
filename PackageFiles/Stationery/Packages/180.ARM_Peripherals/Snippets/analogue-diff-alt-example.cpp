/**
 ============================================================================
 * @file analogue-diff-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief Example showing use of a differential ADC channel
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "adc.h"

using namespace USBDM;

/*
 * Demonstrates differential conversion on a channel
 */

// Connection mapping - change as required
// Note - many actions on the channel affect the entire ADC

// Shared ADC to use
using MyAdc        = Adc0;

// ADC channel to use
using MyAdcChannel = MyAdc::DiffChannel<AdcChannelNum_Diff0>;

// Resolution to use for ADC
constexpr AdcResolution ADC_RESOLUTION = AdcResolution_9bit_diff;

int main(void) {

   // Connect ADC channel to pins
   MyAdcChannel::setInput();

   static constexpr MyAdc::Init adcInitValue = {
      AdcClockSource_Asynch ,             // (adc_cfg1_adiclk) ADC Clock Source
      ADC_RESOLUTION ,                    // (adc_cfg1_mode)   ADC Resolution
      AdcTrigger_Software ,               // (adc_sc2_adtrg)   Conversion Trigger Select
      AdcAveraging_4 ,                    // (adc_sc3_avg)     Hardware Average Select
      AdcSample_4cycles ,                 // (adc_sample)      Long Sample Time Select
   };
   // Enable and configure ADC
   MyAdc::configure(adcInitValue);

   for(;;) {
      // Do next conversion
      int32_t value = MyAdcChannel::readAnalogue();
      console.writeln("Difference  = ", value*3.3/MyAdc::getDifferentialMaximum(ADC_RESOLUTION), " volts");
   }
}
