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
#include "adc.h"
#include "pmc.h"

using namespace USBDM;

/*
 * Demonstrates single-ended conversion on a channel
 */

// Connection mapping - change as required
// Note - many actions on the channel affect the entire ADC

// Shared ADC to use
using MyAdc        = Adc0;

// ADC channel to use
using BandgapAdcChannel  = Adc0::Channel<Adc0ChannelNum_Analogue_A0>;  // Internal bandgap
using MyAdcChannel       = Adc0::Channel<Adc0ChannelNum_Analogue_A1>;  // Internal chip temperature

// Resolution to use for ADC
constexpr AdcResolution adcResolution = AdcResolution_16bit_se;

void reportChipTemperature() {
   using TemperatureChannel    = Adc0::Channel<Adc0ChannelNum_TEMP_SENSOR>;  // Internal temp sensor
   constexpr float VREF_H      = 3.3;                                        // External Vref voltage ~ Vcc

   unsigned tMeasure        = TemperatureChannel::readAnalogue();
   float    tVoltage        = tMeasure*(VREF_H/Adc0::getSingleEndedMaximum(adcResolution));
   // Formula from data sheets
   float    chipTemperature = 25 - (tVoltage-0.719)/.001715;

   static constexpr FloatFormat format {
      Precision_2,
      Padding_LeadingSpaces,
      Width_auto,
   };
   console.setFormat(format);
   console.writeln("Temp = ", chipTemperature, " degrees");
   console.resetFloatFormat();
}

int main(void) {

   MyAdc::Init adcInit {
      adcResolution,
      AdcAveraging_32,
   };

   // Enable and configure ADC
   MyAdc::configure(adcInit);

   // Connect ADC channel to pin
   MyAdcChannel::setInput();

   // Enable band-gap voltage reference buffer in PMC
   static constexpr Pmc::Init pmcInit {
      PmcBandgapOperationInLowPower_Enabled , // (pmc_regsc_bgen) Bandgap Enable In VLPx Operation - Disabled
      PmcBandgapBuffer_Enabled,  // (pmc_regsc_bgbe) Bandgap Buffer Enable - Disabled
   };
   Pmc::configure(pmcInit);

   static constexpr FloatFormat format {
      Precision_3,
      Padding_LeadingSpaces,
      Width_6,
   };

   for(;;) {
//      reportChipTemperature();

      // Do next conversion
      uint32_t value = BandgapAdcChannel::readAnalogue();

      // Scale value for input voltage range (Assumes Vrh=3.3V, Vrl=0.0V)
      float voltage = value*3.3/MyAdc::getSingleEndedMaximum(adcResolution);

      // Report
      console.setFormat(format);
      console.writeln("Value = ", voltage, " volts");
      waitMS(200);
   }
}
