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
static constexpr Seconds SEQ_LENGTH    = 10_ms;

// When to take ADC sample
static constexpr Seconds TRIGGER_TIME  =  9_ms;

static uint32_t result;
static bool     complete=false;

static void pdbCallback() {
   if ((Pdb0::getChannelFlags(0) & PDB_S_ERR_MASK) != 0) {
      Pdb0::clearChannelFlags(0);
      // Channel sequence error
      console.writeln("Sequence Error!!");
   }
   Pdb0::clearEventFlag();

   complete = true;
   Led::clear();
}

//static void pdbErrorCallback() {
//   complete = true;
//   __BKPT();
//}

static void configurePdb() {

   static constexpr Pdb0::Init pdbInit = {

         PdbTrigger_Software ,   // Trigger Input Source Select
         PdbMode_OneShot ,       // PDB operation mode - Sequence runs once only
         PdbLoadMode_Immediate , // Register Load Select - Registers loaded immediately on LDOK=1
         NvicPriority_Normal ,   // IRQ level for this peripheral

         // Period
         PdbPrescale_Auto_Calculated,  // Clock Prescaler and modulo calculated
         SEQ_LENGTH,

         // Error IRQ
         PdbErrorAction_Interrupt,  // Sequence Error Interrupt Enable - Interrupt on error

         // Event IRQ
         PdbAction_Interrupt ,      // Timer event action
         SEQ_LENGTH  ,              // Interrupt delay
         pdbCallback,

         // Pre-trigger 0 configuration
         PdbChannel_0,
         PdbPretrigger0_Delayed , // Channel Pretrigger ADC0.SC1[0] - Pretrigger disabled
         TRIGGER_TIME,            // Delay

//         // Pre-trigger 1 configuration
//         PdbChannel_0,
//         PdbPretrigger1_Disabled , // Channel Pretrigger ADC0.SC1[1] - Pretrigger disabled
//         0_ticks,  // Delay

//         // Pulse output 0 (CMP0) configuration
//         PdbPulseOutput0_Disabled , // Pulse output trigger enable - Pulse output disabled
//         0_ticks , // Pulse-Output Delay 1 - rising edge
//         0_ticks,  // Pulse-Output Delay 2 - falling edge
//
//         // Pulse output 1 (CMP1) configuration
//         PdbPulseOutput1_Disabled , // Pulse output trigger enable - Pulse output disabled
//         0_ticks , // Pulse-Output Delay 1 - rising edge
//         0_ticks,  // Pulse-Output Delay 2 - falling edge
//
      };

   Pdb0::configure(pdbInit);

   // Wait for register load to complete
   while (!Pdb::isRegisterLoadComplete()) {
      __asm__("nop");
   }

#if 0
   // Note: Can work in timer ticks and avoid floating point if desired
   //   Pdb::setClock(PdbPrescale_128, PdbMultiplier_10);
   //   Pdb::setModulo(1000);
   //   Pdb::setInterruptDelayInTicks(900_ticks);
   //   Pdb::setPretriggersInTicks(0, PdbPretrigger0_Delayed, 800_ticks);

   Pdb::enable();

   // Software Trigger
   Pdb::setTriggerSource(PdbTrigger_Software);

   // Set call-backs
//   Pdb::setErrorCallback(pdbErrorCallback);
   Pdb::setCallback(pdbCallback);

   // Set period of sequence - must be done before setting times
   Pdb::setPeriod(SEQ_LENGTH);

   // Interrupts during sequence or error
   Pdb::setEventAction(PdbAction_Interrupt, SEQ_LENGTH);
   Pdb::setErrorAction(PdbErrorAction_Interrupt);

   // Take single ADC (SC0) sample at TRIGGER_TIME
   Pdb::configureAdcPretrigger(PdbChannel_0, PdbPretrigger0_Delayed, TRIGGER_TIME);

   // Update registers
   Pdb::configureRegisterLoad(PdbLoadMode_Immediate);

   // Wait for register load to complete
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
