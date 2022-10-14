/**
 ============================================================================
 * @file   pdb-example.cpp (180.ARM_Peripherals/Snippets/)
 * @brief  Basic C++ Programmable Delay Block (PDB) Example
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
static constexpr Seconds SEQ_LENGTH    = 100_ms;

// When to take ADC sample
static constexpr Seconds TRIGGER_TIME  =  9_ms;

static uint32_t result;
static bool     complete=false;

static void pdbCallback() {
   complete = true;
   Led::clear();
}

static void pdbErrorCallback() {
   complete = true;
   __BKPT();
}

static void configurePdb() {

#if 1
   Pdb0::Init pdbInit {

      PdbTrigger_Software ,      // Trigger Input Source Select - Software trigger is selected

      PdbLoadMode_Event ,        // Register Load Select - Registers loaded on event (software trigger)

      PdbPrescale_Auto_Select,   // Prescale selected automatically from modulo
      SEQ_LENGTH ,               // Counter modulo

      PdbAction_Interrupt ,      // Event action - Interrupt
      SEQ_LENGTH ,               // Interrupt delay
      pdbCallback,               // Interrupt handler

      PdbErrorAction_Interrupt , // Sequence Error Interrupt Enable - Interrupt on error
      pdbErrorCallback,          // Call-back to use

      PdbMode_Continuous ,       // PDB operation mode - Sequence runs continuously once triggered

      NvicPriority_Normal,       // IRQ level for this peripheral - Normal

      PdbChannel_0,              // Channel 0 set up
      PdbPretrigger0_Delayed ,   // Channel Pretrigger control (usually ADC0.SC1[0]) - Pretrigger delayed
      TRIGGER_TIME,              // Delay
   };

   Pdb0::configure(pdbInit);

#else

   Pdb::enable();

   // Software Trigger
   Pdb::setTriggerSource(PdbTrigger_Software);

   // Set call-backs
   Pdb::setErrorCallback(pdbErrorCallback);
   Pdb::setCallback(pdbCallback);

   // Interrupts during sequence or error
   Pdb::setActions(PdbAction_Interrupt, PdbErrorAction_Interrupt);

   // Set period of sequence
   Pdb::setPeriod(SEQ_LENGTH);

   // Generate interrupt at end of sequence
   Pdb::setInterruptDelay(SEQ_LENGTH);

   // Take single ADC sample at TRIGGER_TIME
   Pdb::configureAdcPretrigger(PdbChannel_0, PdbPretrigger0_Delayed, TRIGGER_TIME);

   // Update registers
   Pdb::configureRegisterLoad(PdbLoadMode_Immediate);
   while (!Pdb::isRegisterLoadComplete()) {
      __asm__("nop");
   }
   Pdb::enableNvicInterrupts(NvicPriority_Normal);
#endif
}

static void adcCallback(uint32_t value, int) {
   result = value;
   Led::set();
}

static void configureAdc() {

   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Pdb);

   MyAdc::enable();
   MyAdc::setResolution(AdcResolution_8bit_se);
   MyAdc::calibrate();
   MyAdc::setCallback(adcCallback);
   MyAdc::enableNvicInterrupts(NvicPriority_Normal);

   MyAdcChannel::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Enabled);
}

int main() {
   console.writeln("Starting");

   Led::setOutput();

   configureAdc();
   configurePdb();

   for(;;) {
      complete = false;
      Pdb::softwareTrigger();
      while (!complete) {
         __WFI();
      }
      console.write("ch1 = ").writeln(result);
   }
   for(;;) {
      __asm__("nop");
   }
}
