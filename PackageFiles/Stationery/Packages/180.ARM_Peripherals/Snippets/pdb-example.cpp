/**
 * @file pdb-example1.cpp
 *
 * Programmable Delay Block (PDB) Example
 *
 * This example uses PDB software trigger to schedule an ADC conversion
 * Uses an LED for debug timing check.
*/
#include "hardware.h"
#include "pdb.h"

using namespace USBDM;

// LED connection - change as required
using Led         = GpioA<2, ActiveLow>;
using Pdb         = Pdb0;
using Adc         = Adc0;
using AdcChannel  = Adc0Channel<19>;

// Length of PDB sequence
static constexpr float SEQ_LENGTH    = 10*ms;

// When to take ADC sample
static constexpr float TRIGGER_TIME  =  9*ms;

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

   // Note: Can work in timer ticks and avoid floating point if desired
   //   Pdb::setClock(PdbPrescale_128, PdbMultiplier_10);
   //   Pdb::setModulo(1000);
   //   Pdb::setInterruptDelayInTicks(900);
   //   Pdb::setPretriggersInTicks(0, PdbPretrigger0_Delayed, 800);

   Pdb::enable();
   // Software Trigger
   Pdb::setTriggerSource(PdbTrigger_Software, PdbMode_OneShot);
   // Set call-backs
   Pdb::setErrorCallback(pdbErrorCallback);
   Pdb::setCallback(pdbCallback);
   // Interrupts during sequence or error
   Pdb::setInterrupts(PdbInterrupt_Enable, PdbErrorInterrupt_Enable);

   // Set period of sequence
   Pdb::setPeriod(SEQ_LENGTH);
   // Generate interrupt at end of sequence
   Pdb::setInterruptDelay(SEQ_LENGTH);
   // Take single ADC sample at TRIGGER_TIME
   Pdb::setPretriggers(0, PdbPretrigger0_Delay, TRIGGER_TIME);
   // Update registers
   Pdb::triggerRegisterLoad(PdbLoadMode_Immediate);
   while (!Pdb::isRegisterLoadComplete()) {
      __asm__("nop");
   }
   Pdb::enableNvicInterrupts();
}

static void adcCallback(uint32_t value, int) {
   result = value;
   Led::set();
}

static void configureAdc() {

   SimInfo::setAdc0Triggers(SimInfo::SimAdc0AltTrigger_Pdb);

   Adc::enable();
   Adc::setResolution(AdcResolution_8bit_se);
   Adc::calibrate();
   Adc::setCallback(adcCallback);
   Adc::enableNvicInterrupts();

   AdcChannel::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_enable);
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
