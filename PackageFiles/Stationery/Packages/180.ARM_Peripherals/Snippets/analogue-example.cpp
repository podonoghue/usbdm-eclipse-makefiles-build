/**
 ============================================================================
 * @file analogue-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief Example showing use of a single-ended ADC channel
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

using namespace USBDM;

/*
 * Demonstrates single-ended conversion on a channel
 */

// Connection mapping - change as required
// Note - many actions on the channel affect the entire ADC

// Shared ADC to use
using Adc        = Adc0;

// ADC channel to use
using AdcChannel = Adc::Channel<0>;

// Resolution to use for ADC
constexpr AdcResolution adcResolution = AdcResolution_10bit_se;

int main(void) {
   // Enable and configure ADC
   Adc::configure(AdcResolution_12bit_se);

   // Calibrate before first use
   Adc::calibrate();

   // May change current resolution as needed e.g.
   Adc::setResolution(adcResolution);

   // Connect ADC channel to pin
   AdcChannel::setInput();

   for(;;) {
      // Do next conversion
      uint32_t value = AdcChannel::readAnalogue();
      console.write("Value = ").write(value*3.3/Adc::getSinglendeddMaximum(adcResolution)).writeln(" volts");
   }
}
