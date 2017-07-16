/*
 ============================================================================
 * @file    adc-comparison-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo of using ADC comparison hardware with interrupts
 *
 *  Created on: 10/6/2017
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "adc.h"

using namespace USBDM;

/*
 * Demonstrates ADC comparison hardware with interrupts
 */

// Connection - change as required
using Led         = GpioA<2, ActiveLow>;  // = PTA2 = D9 = Blue LED
using Adc         = Adc0;
using AdcChannel  = Adc0Channel<0>;

/**
 * ADC callback
 *
 * Will toggle LED while comparison is true
 */
void adcComparisonCallback(uint32_t, int) {
   Led::toggle();
}

int main() {
   // Enable LED
   Led::setOutput();

   // Enable and configure ADC
   Adc::configure(AdcResolution_16bit_se);

   // Calibrate before use
   Adc::calibrate();

   // Set up comparison range
   Adc::enableComparison(AdcCompare_OutsideRangeExclusive, 80, 160);

   /**
    * Set callback
    * The callback is executed each time the Conversion Complete (COCO) flag sets.
    * In comparison mode this only occurs when the converted value matches the comparison set.
    */
   Adc::setCallback(adcComparisonCallback);
   Adc::enableNvicInterrupts();

   /**
    * Start continuous conversions with interrupts on comparison true.
    * A bit wasteful of power - should throttle.
    */
   AdcChannel::startConversion(AdcInterrupt_enable, AdcContinuous_Enabled);

   for(;;) {
      __asm__("nop");
   }
}
