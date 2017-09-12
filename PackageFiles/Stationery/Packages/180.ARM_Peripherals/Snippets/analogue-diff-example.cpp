/**
 ============================================================================
 * @file analogue-diff-example.cpp
 * @brief Example showing use of a differential ADC channel
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

using namespace USBDM;

/*
 * Demonstrates differential conversion on a channel
 */

// Connection mapping - change as required
// Note - many actions on the channel affect the entire ADC
using Adc        = Adc0;
using AdcChannel = Adc0DiffChannel<0>;

int main(void) {

   // Enable and configure ADC
   Adc::configure(AdcResolution_11bit_diff);

   // Calibrate before use
   Adc::calibrate();

   // May change default resolution e.g.
   Adc::setResolution(USBDM::AdcResolution_9bit_diff);

   AdcChannel::enable();

   for(;;) {
      // Start next conversion
      uint32_t value = AdcChannel::readAnalogue();
      console.write("Value = ").writeln(value);
   }
}
