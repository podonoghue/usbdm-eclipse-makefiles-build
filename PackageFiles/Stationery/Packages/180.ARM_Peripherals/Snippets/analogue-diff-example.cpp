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

using namespace USBDM;

/*
 * Demonstrates differential conversion on a channel
 */

// Connection mapping - change as required
// Note - many actions on the channel affect the entire ADC

// Shared ADC to use
using Adc        = Adc0;

// ADC channel to use
using AdcChannel = Adc0DiffChannel<0>;

int main(void) {

   // Enable and configure ADC
   Adc::configure(AdcResolution_11bit_diff);

   // Calibrate before first use
   Adc::calibrate();

   // May change default resolution as needed e.g.
   Adc::setResolution(USBDM::AdcResolution_9bit_diff);

//   // Configure ADC pins (if automatic mapping is not enabled in USBDM configuration)
//   if (!AdcChannel::AdcInfo::mapPinsOnEnable) {
//      AdcChannel::setInput();
//   }

   for(;;) {
      // Start next conversion
      int32_t value = AdcChannel::readAnalogue();
      console.write("Difference  = ").write(value*3.3/(1<<8)-1).writeln(" volts");
   }
}
