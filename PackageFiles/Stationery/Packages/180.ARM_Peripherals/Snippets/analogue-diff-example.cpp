/**
 ============================================================================
 * @file analogue-diff-example.cpp
 * @brief Example showing use of a differential ADC channel
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"

using namespace USBDM;

/*
 * Demonstrates differential conversion on a channel
 */

// Connection mapping - change as required
using adcChannel = Adc0DiffChannel<0>;

int main(void) {
   // Enable ADC
   adcChannel::enable();

   // May change default resolution e.g.
//   adcChannel::setResolution(USBDM::AdcResolution_8bit_se);

   for(;;) {
      // Start next conversion
      uint32_t value = adcChannel::readAnalogue();
      printf("Value = %7ld\n", value);
   }
}
