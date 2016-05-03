/**
 * @file analogue-example.cpp
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
//   adcChannel::setMode(USBDM::resolution_8bit_se);

   for(;;) {
      // Start next conversion
      uint32_t value = adcChannel::readAnalogue();
      printf("Value = %7ld\n", value);
   }
}
