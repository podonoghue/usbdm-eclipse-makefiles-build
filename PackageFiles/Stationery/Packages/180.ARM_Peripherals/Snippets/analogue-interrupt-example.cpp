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

   // Enable and configure ADC
   adc::configure(AdcResolution_8bit_se);

   // Calibrate before use
   adc::calibrate();

   // Note: Setting callback affects all channels on that ADC
   adc::setCallback(handler);

   // Check for error so far
   checkError();

   // Start a conversion
   adcChannel::startConversion();

   for(;;) {
   }
}
