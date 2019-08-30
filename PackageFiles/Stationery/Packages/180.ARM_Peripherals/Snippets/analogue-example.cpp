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
   Adc::configure(adcResolution);

   // Calibrate before first use
   Adc::calibrate();

   // Connect ADC channel to pin
   AdcChannel::setInput();

   for(;;) {
      // Do next conversion
      uint32_t value = AdcChannel::readAnalogue();

      // Scale value for input voltage range (Assumes Vrh=3.3V, Vrl=0.0V)
      float voltage = value*3.3/Adc::getSingleEndedMaximum(adcResolution);

      // Report
      console.write("Value = ").write(voltage).writeln(" volts");
   }
}
