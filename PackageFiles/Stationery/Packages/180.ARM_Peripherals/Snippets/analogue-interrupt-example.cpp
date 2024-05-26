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
#include "adc.h"

using namespace USBDM;

/*
 * Demonstrates conversion on a single channel with interrupts
 */

// Connection mapping - change as required
// (ADC Ch(19) = light sensor on FRDM-K20
using MyAdcChannel = Adc0::Channel<Adc0ChannelNum_Analogue_A0>;
using MyAdc        = MyAdcChannel::Owner;

/**
 * NOTE:  This is not a sensible approach
 *        Using serial I/O in a ISR is very silly!!!!
 */
void handler(uint32_t result, AdcChannelNum) {
   result = result/10;
   for (unsigned i=0; i<result; i++) {
      console.write('X');
   }
   console.writeln();
}

int main(void) {
   console.writeln("Starting");

   // Connect ADC channel to pins
   MyAdcChannel::setInput();

   static constexpr MyAdc::Init adcInitValue = {
         NvicPriority_Normal,                // NVIC configuration
         handler,                            // ADC call-back

      AdcClockSource_Asynch ,             // (adc_cfg1_adiclk) ADC Clock Source
      AdcResolution_8bit_se ,             // (adc_cfg1_mode)   ADC Resolution
      AdcTrigger_Software ,               // (adc_sc2_adtrg)   Conversion Trigger Select
      AdcAveraging_4 ,                    // (adc_sc3_avg)     Hardware Average Select
      AdcSample_4cycles ,                 // (adc_sample)      Long Sample Time Select
      AdcContinuous_Enabled ,             // (adc_sc3_adco)    Continuous conversions

      // Software configuration - Trigger conversions on channel with interrupts
      AdcPretrigger_0, MyAdcChannel::CHANNEL, AdcAction_Interrupt,
   };
   // Enable and configure ADC
   MyAdc::configure(adcInitValue);

   // Check for error so far
   checkError();

   for(;;) {
      waitMS(100);
   }
}
