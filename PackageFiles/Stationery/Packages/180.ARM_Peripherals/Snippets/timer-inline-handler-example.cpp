/**
 ============================================================================
 * @file    timer-inline-handler-example.cpp (180.ARM_Peripherals/snippets
 * @brief   Demo of how to use inline handlers for PIT and LPTMR
 *
 *  Created on: 5/6/2022
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "pit.h"
#include "lptmr.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// LED connection - change as required
using LED   = $(/HARDWARE/Led1:GpioA<2, ActiveLow>);

// Handler for PIT channel 0
PIT_CHANNEL0_HANDLER() {
   console.writeln("PIT Handler");
   // Clear interrupt flag
   pit->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
}

// Handler for LPTMR0
LPTMR0_HANDLER() {
   console.writeln("LPTMR0 Handler");
   // Clear interrupt flag
   lptmr->CSR = lptmr->CSR | LPTMR_CSR_TCF_MASK;
}

int main() {
   console.writeln("\nStarting");

   Pit::Channel<0>::Owner::configure(PitDebugMode_Stop);
   Pit::Channel<0>::configure(1_s, PitChannelIrq_Enabled);
   Pit::Channel<0>::enableNvicInterrupts(NvicPriority_High);

   Lptmr0::configureTimeCountingMode(LptmrResetOn_Compare, LptmrInterrupt_Enabled);
   Lptmr0::setPeriod(5_s);
   Lptmr0::enableNvicInterrupts(NvicPriority_High);

   Led::setOutput();

   checkError();

   for(int count = 0;;count++) {
      Led::toggle();
      waitMS(100);
      console.writeln(count, ": Tick...");
   }
   return 0;
}
