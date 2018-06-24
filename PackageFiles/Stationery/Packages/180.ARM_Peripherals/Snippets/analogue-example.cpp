/**
 ============================================================================
 * @file analogue-example.cpp
 * @brief Example showing use of a single-ended ADC channel
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
//#include <type_traits> // std::is_same

using namespace USBDM;

/*
 * Demonstrates single-ended conversion on a channel
 */

// Connection mapping - change as required
// Note - many actions on the channel affect the entire ADC

// Shared ADC to use
using Adc        = Adc0;

// ADC channel to use
using AdcChannel = Adc0Channel<0>;

//static_assert(std::is_same<AdcChannel::Adc,Adc>::value, "ADC channel must belong to same ADC!");

int main(void) {
   // Enable and configure ADC
   Adc::configure(AdcResolution_12bit_se);

   // Calibrate before first use
   Adc::calibrate();

   // May change current resolution as needed e.g.
   Adc::setResolution(USBDM::AdcResolution_10bit_se);

//   // Configure ADC pins (if automatic mapping is not enabled in USBDM configuration)
//   if (!AdcChannel::AdcInfo::mapPinsOnEnable) {
//      AdcChannel::setInput();
//   }

   for(;;) {
      // Start next conversion
      uint32_t value = AdcChannel::readAnalogue();
      console.write("Value = ").write(value*3.3/(1<<10)).writeln(" volts");
   }
}
