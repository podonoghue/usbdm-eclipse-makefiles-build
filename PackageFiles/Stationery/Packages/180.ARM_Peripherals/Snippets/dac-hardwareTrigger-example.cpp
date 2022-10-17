/**
 ============================================================================
 * @file    dac-hardwareTrigger-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   DAC example using buffer and hardware trigger
 *
 *  Created on: 20/10/2018
 *      Author: podonoghue
 ============================================================================
 */
/**
 * This example is only useful if the DAC has a reasonable size
 * buffer e.g. 16 entries.
 */
#include "hardware.h"
#include "dac.h"
#include "pdb.h"
#include "smc.h"

using namespace USBDM;

using Dac   = Dac0;

/**
 * Configure PDB to trigger DAC
 */
static void configurePdb() {

#if 0
   // PDB configuration using structure in Flash (Ticks)
   static constexpr Pdb0::Init pdbInitValue = {

      PdbTrigger_Software ,   // Trigger Input Source Select - Software trigger is selected
      PdbPrescale_DivBy_40 ,  // Clock Prescaler Divider Select - Divide by 1 (obtained from Configure.usbdmProject)
      9999_ticks ,            // Counter modulus (obtained from Configure.usbdmProject)
      PdbMode_Continuous ,    // PDB operation mode - Sequence runs continuously once triggered
      PdbLoadMode_Event ,     // Register Load Select - Registers loaded on trigger input event

      PdbDac0TriggerMode_Periodic , // DAC trigger control - DAC trigger delayed by DAC interval counter
      99_ticks,                     // DAC interval (obtained from Configure.usbdmProject)
   };
   Pdb0::configure(pdbInitValue);

   // Start timer and load values
   Pdb0::softwareTrigger();

#elif 1
   // PDB configuration using structure in Flash (Seconds)
   static constexpr Pdb0::Init pdbInitValue = {

      PdbTrigger_Software ,         // Trigger Input Source Select - Software trigger is selected
      PdbPrescale_Auto_Select ,     // Clock Prescaler Divider Select - Auto select divider according to period
      10_ms ,                       // Counter modulus
      PdbMode_Continuous ,          // PDB operation mode - Sequence runs continuously once triggered
      PdbLoadMode_Event ,           // Register Load Select - Registers loaded on trigger input event

      PdbDac0TriggerMode_Periodic ,  // DAC trigger control - DAC trigger delayed by DAC interval counter
      100_us,                        // DAC interval
   };
   Pdb0::configure(pdbInitValue);

   // Start timer and load values
   Pdb0::softwareTrigger();

#else
   // PDB configuration using method calls
   Pdb0::configure(
         PdbMode_Continuous,
         PdbTrigger_Software);

   Pdb0::setPeriod(1_ms);
   Pdb0::configureDacTrigger(0, PdbDac0TriggerMode_Periodic, 20_us);

   // Any phase will do (<PDB_PERIOD)
   Pdb0::setInterruptDelay(0_ticks);

   // Registers load on next event
   Pdb0::configureRegisterLoad(PdbLoadMode_Event);

   // Start timer and load values
   Pdb0::softwareTrigger();
#endif
}

/**
 * Configure DAC and initialise DAC buffer
 */
static void configureDac() {

   // Basic configuration - Hardware trigger
   Dac::configure(
         DacReferenceSelect_Vdda,
         DacPower_High,
         DacTriggerSelect_Hardware);

   // Normal buffer
   Dac::configureBuffer(
         DacBufferMode_Normal);

   // Connect output to pin (if necessary)
   Dac::setOutput();

   // Fill DAC buffer with values for ramp waveform
   Dac::setBufferLimit(Dac::getBufferSize()-1);
   for (unsigned index=0; index<Dac::getBufferSize(); index++) {
      uint16_t value = round(index*Dac::getRange())/(Dac::getBufferSize()-1);
      Dac::writeValue(index, value);
      console.writeln("Value[", index, "] = ", value);
   }
}

int main() {
   console.writeln("Starting");

   configureDac();
   configurePdb();

   // PDB loops through DAC values using hardware trigger
   for(;;) {
      Smc::enterWaitMode();
   }

   return 0;
}
