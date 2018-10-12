/**
 ============================================================================
 * @file analogue-interrupt-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief Example showing use of a interrupts with an ADC channel
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

using namespace USBDM;

/*
 * Demonstrates conversion on a single channel with interrupts
 */

// Connection mapping - change as required
// (ADC Ch(19) = light sensor on FRDM-K20
using Adc        = Adc0;
using AdcChannel = Adc::Channel<19>;

/**
 * NOTE:  This is not a sensible approach
 *        Using serial I/O in a ISR is very silly!!!!
 */
void handler(uint32_t value, int) {
   // Start next conversion
   AdcChannel::startConversion();
   value = value/10;
   for (uint i=0; i<75; i++) {
      if (i<value) {
         console.write('X');
      }
   }
   console.writeln();
}

int main(void) {
   console.writeln("Starting");

   // Enable and configure ADC
   Adc::configure(AdcResolution_8bit_se);

   // Calibrate before use
   Adc::calibrate();

   // Note: Setting callback affects all channels on that ADC
   Adc::setCallback(handler);

   // Check for error so far
   checkError();

   // Start a conversion
   AdcChannel::startConversion();

   for(;;) {
   }
}
