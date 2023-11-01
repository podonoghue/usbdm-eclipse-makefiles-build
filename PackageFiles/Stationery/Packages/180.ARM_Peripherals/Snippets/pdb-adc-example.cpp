/**
 ============================================================================
 * @file   pdb-example.cpp (180.ARM_Peripherals/Snippets/)
 * @brief  Basic C++ Programmable Delay Block (PDB) Example
 *
 * Sets up the PDB and 1/2 ADCs to to 2/4 conversions in a PDB cycle.
 * Results are captured by a PDB interrupt handler at the end of the cycle.
 *
 *  Created on: 10/7/2017
 *      Author: podonoghue
 ============================================================================
 */
/*
 * This example uses PDB software trigger to schedule an ADC conversion
 * Uses an LED for debug timing check.
 *
 * Note - Requires ADC and PDB interrupt handlers to be installed.
 */
#include "hardware.h"
#include "pdb.h"

using namespace USBDM;

// LED connection - change as required
using Led   = $(/HARDWARE/Led1:GpioB<0,ActiveLow>);

using Pdb           = Pdb0;

// ADC channel to use
using MyAdcChannel  = $(/HARDWARE/Analogue0:Adc0\:\:Channel<10>);

// Shared ADC to use
using MyAdc         = MyAdcChannel::OwningAdc;

// Length of PDB sequence
static constexpr Seconds SEQ_LENGTH    = 5_ms;

// When to take ADC samples within sequence
static constexpr Seconds TRIGGER_TIME1  =  1_ms;
static constexpr Seconds TRIGGER_TIME2  =  2_ms;
static constexpr Seconds TRIGGER_TIME3  =  3_ms;
static constexpr Seconds TRIGGER_TIME4  =  4_ms;

static volatile uint32_t result[4];
static volatile bool     complete=false;

static void pdbCallback() {
   result[0] = Adc0::getHardwareConversionResult(AdcPretrigger_0);
   result[1] = Adc0::getHardwareConversionResult(AdcPretrigger_1);
//   result[2] = Adc1::getHardwareConversionResult(AdcPretrigger_0);
//   result[3] = Adc1::getHardwareConversionResult(AdcPretrigger_1);
   complete = true;
   Led::toggle();
}

//static void pdbErrorCallback() {
//   __BKPT();
//}

static void configurePdb() {

#if 1
   // Configuration using Init structures in flash
   static const Pdb0::Init pdbInit {

      PdbTrigger_Software ,      // Trigger Input Source Select - Software trigger is selected

      PdbLoadMode_Event ,        // Register Load Select - Registers loaded on event (software trigger)

      PdbMode_Continuous,        // Sequence repeats

      PdbPrescale_Auto_Calculated,   // Prescale selected automatically from modulo
      SEQ_LENGTH ,               // Counter modulo

      PdbAction_Interrupt ,      // Event action - Interrupt
      SEQ_LENGTH ,               // Interrupt delay
      pdbCallback,               // Interrupt handler

      PdbErrorAction_Interrupt , // Sequence Error Interrupt Enable - Interrupt on error
//      pdbErrorCallback,          // Call-back to use

      NvicPriority_Normal,       // IRQ level for this peripheral - Normal

      PdbChannel_0,              // Channel 0 set up
      PdbPretrigger0_Delayed ,   // Channel Pretrigger control ADC0.SC1[0] - Pretrigger delayed
      TRIGGER_TIME1,             // Delay

      PdbChannel_0,              // Channel 0 set up
      PdbPretrigger1_Delayed ,   // Channel Pretrigger control ADC0.SC1[1] - Pretrigger delayed
      TRIGGER_TIME2,             // Delay

//      PdbChannel_1,              // Channel 1 set up
//      PdbPretrigger0_Delayed ,   // Channel Pretrigger control ADC1.SC1[0] - Pretrigger delayed
//      TRIGGER_TIME3,             // Delay
//
//      PdbChannel_1,              // Channel 1 set up
//      PdbPretrigger1_Delayed ,   // Channel Pretrigger control ADC1.SC1[1] - Pretrigger delayed
//      TRIGGER_TIME4,             // Delay
   };

   ErrorCode rc = Pdb0::configure(pdbInit);
   if (rc != E_NO_ERROR) {
      console.writeln("rc = ", getErrorMessage(rc));
      for(;;){}
   }

#else

   // Configuration using function calls
   Pdb::enable();

   // Software Trigger
   Pdb::setTriggerSource(PdbTrigger_Software);

   Pdb::setMode(PdbMode_Continuous);

   // Set period of sequence
   Pdb::setPeriod(SEQ_LENGTH);

   // Interrupts during sequence
   Pdb::setEventAction(PdbAction_Interrupt, SEQ_LENGTH);
   Pdb::setCallback(pdbCallback);

   // Interrupts on error
   Pdb::setErrorAction(PdbErrorAction_Interrupt);
   Pdb::setErrorCallback(pdbErrorCallback);

   // Take single ADC sample at TRIGGER_TIME1
   Pdb::configureAdcPretrigger(PdbChannel_0, PdbPretrigger0_Delayed, TRIGGER_TIME1);

   // Take single ADC sample at TRIGGER_TIME2
   Pdb::configureAdcPretrigger(PdbChannel_0, PdbPretrigger1_Delayed, TRIGGER_TIME2);

   // Take single ADC sample at TRIGGER_TIME3
   Pdb::configureAdcPretrigger(PdbChannel_1, PdbPretrigger0_Delayed, TRIGGER_TIME3);

   // Take single ADC sample at TRIGGER_TIME4
   Pdb::configureAdcPretrigger(PdbChannel_1, PdbPretrigger1_Delayed, TRIGGER_TIME4);

   Pdb::enableNvicInterrupts(NvicPriority_Normal);

   // Update registers on event
   Pdb::configureRegisterLoad(PdbLoadMode_Event);

#endif
}

static void configureAdc() {

#if 1
   // Configuration using Init structures in flash

   // Connect trigger sources
   static const SimInfo::AdcInit adcTriggerInit {
      SimAdc0TriggerMode_Pdb,
//      SimAdc1TriggerMode_Pdb,
   };
   SimInfo::configure(adcTriggerInit);

   static const Adc0::Init adc0Init {
      AdcClockSource_Asynch , // ADC Clock Source - Asynchronous clock (ADACK)
      AdcResolution_8bit_se , // ADC Resolution - 8-bit unsigned (single-ended mode)
      AdcMuxsel_B ,           // Selects between A/B multiplexor inputs on some ADC channels - The multiplexor selects B channels
      AdcTrigger_Hardware ,   // Conversion Trigger Select - Software trigger (write to SC1A)
      AdcAveraging_32 ,       // Hardware Average Select - 1 sample
   };
   Adc0::configure(adc0Init);

#ifdef ADC1
   static const Adc1::Init adc1Init {
      AdcClockSource_Asynch , // ADC Clock Source - Asynchronous clock (ADACK)
      AdcResolution_8bit_se , // ADC Resolution - 8-bit unsigned (single-ended mode)
      AdcMuxsel_B ,           // Selects between A/B multiplexor inputs on some ADC channels - The multiplexor selects B channels
      AdcTrigger_Hardware ,   // Conversion Trigger Select - Software trigger (write to SC1A)
      AdcAveraging_32 ,       // Hardware Average Select - 1 sample
   };
   Adc1::configure(adc1Init);
#endif

#else
   // Configuration using function calls

   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Pdb);
   SimInfo::setAdc1Triggers(SimAdc1TriggerMode_Pdb);

   Adc0::configure(AdcResolution_8bit_se, AdcClockSource_Asynch);
   Adc0::setAveraging(AdcAveraging_32);
   Adc0::calibrate();

#ifdef ADC1
   Adc1::configure(AdcResolution_8bit_se, AdcClockSource_Asynch);
   Adc1::setAveraging(AdcAveraging_32);
   Adc1::calibrate();
#endif

#endif

#ifdef MCU_MK22F51212
   // MK22F example - using same analogue input across 2 ADCs and 2 pretriggers
   typedef Adc0::Channel<3> LightSensor_ADC0; // A8/LightSensor
   typedef Adc1::Channel<0> LightSensor_ADC1; // A8/LightSensor

   LightSensor_ADC0::setInput();
   LightSensor_ADC0::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled);
   LightSensor_ADC0::enableHardwareConversion(AdcPretrigger_1, AdcInterrupt_Disabled);

   LightSensor_ADC1::setInput();
   LightSensor_ADC1::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled);
   LightSensor_ADC1::enableHardwareConversion(AdcPretrigger_1, AdcInterrupt_Disabled);
#else
   Adc0::Channel<8>::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled);
   Adc0::Channel<8>::setInput();
   Adc0::Channel<9>::enableHardwareConversion(AdcPretrigger_1, AdcInterrupt_Disabled);
   Adc0::Channel<9>::setInput();

#ifdef ADC1
   Adc1::Channel<8>::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled);
   Adc1::Channel<8>::setInput();
   Adc1::Channel<9>::enableHardwareConversion(AdcPretrigger_1, AdcInterrupt_Disabled);
   Adc1::Channel<9>::setInput();
#endif
#endif
}

int main() {
   console.writeln("Starting");

   Led::setOutput();

   configureAdc();
   configurePdb();

   complete = false;

   // Start repeating sequence
   Pdb::softwareTrigger();

   for(;;) {
      while (!complete) {
         __WFI();
      }
      complete = false;
      // Printing is done in the main-line and may miss values if the capture rate is high
      // This is not a safe approach - just for demonstration
      console.writeln("results = ", result[0], ", ", result[1], ", ", result[2], ", ", result[3]);
   }
   for(;;) {
      __asm__("nop");
   }
}
