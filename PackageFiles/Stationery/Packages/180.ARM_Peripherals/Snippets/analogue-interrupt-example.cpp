/**
 ============================================================================
 * @file analogue-interrupt-example.cpp
 * @brief Example showing use of a interrupts with an ADC channel
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
 * Demonstrates conversion on a single channel with interrupts
 */

// Connection mapping - change as required
// (ch(19) = light sensor on FRDM-K20
using adc        = Adc0;
using adcChannel = Adc0Channel<19>;

/**
 * NOTE:  This is not a sensible approach
 *        Using puts() in a ISR is very silly!!!!
 */
void handler(uint32_t value, int) {
   // Start next conversion
   adcChannel::startConversion();
   value = value/10;
   for (uint i=0; i<75; i++) {
      if (i<value) {
         putchar('X');
      }
//      else {
//         putchar(' ');
//      }
   }
   putchar('\n');
//   printf("Value = %7ld\r", value);
}

int main(void) {
   // Do not delete this banner - otherwise putchar() macro breaks.
   printf("Starting\n");

   // Enable ADC
   adc::configure();

   // Note: Setting callback affects all channels on that ADC
   adc::setCallback(handler);

   // May change resolution e.g.
   adcChannel::setResolution(USBDM::AdcResolution_8bit_se);

   adcChannel::startConversion();

   // Check for error so far
   checkError();

   for(;;) {
   }
}
