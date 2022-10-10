/*
 * llwu-simple-example.cpp
 *
 *  Created on: 27 Aug. 2022
 *      Author: peter
 */

#include "hardware.h"
#include "llwu.h"
#include "lptmr.h"
#include "smc.h"
#include "rcm.h"
#include "pmc.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

bool lptmrFlag;
bool pinFlag;
bool llwuFlag;

void lptmrCallback() {
   lptmrFlag = true;
}

void pinCallback(uint32_t pinStatusMask) {
   (void)pinStatusMask;
   pinFlag = true;
}

void llwuCallback() {
   Llwu::disableNvicInterrupts();
   llwuFlag = true;
}

int main(void) {
   console.setBaudRate(defaultBaudRate);
   console.writeln("\n**************************************");
   console.writeln("Executing from RESET, SRS=", Rcm::getResetSourceDescription());

   if ((Rcm::getResetSource() & RcmSource_Wakeup) != 0) {
      console.writeln("========================================");
      console.writeln("Reset due to LLWU");

      bool llwuDeviceFlag  = Llwu::getPeripheralWakeupSources()&LlwuPeripheral_Lptmr0;
      bool llwuPinFlag     = Llwu::isPinWakeupSource(Switch2_llwu::pin);
      bool llwuFilterFlag  = Llwu::isFilteredPinWakeupSource(LlwuFilterNum_1);

      console.write("LLWU DeviceFlag = ").writeln(llwuDeviceFlag);
      console.write("LLWU PinFlag    = ").writeln(llwuPinFlag);
      console.write("LLWU FilterFlag = ").writeln(llwuFilterFlag);
   }

   // LLWU sources
   static constexpr Llwu::Init llwuInit {
      LlwuPeripheral_Lptmr0,
      // Only enable one of the following lines:
//      LlwuPin_Switch2_llwu, LlwuPinMode_FallingEdge,
      LlwuFilterNum_1, LlwuPin_Switch2_llwu, LlwuFilterPinMode_FallingEdge
   };

   // Configure switch as LLWU input with pin interrupt
   Switch2_llwu::setInput(PinPull_Up, PinAction_IrqFalling, PinFilter_Passive);

   // The following are not necessary if using LLWU
   Switch2_llwu::setPinCallback(pinCallback);
   Switch2_llwu::enableNvicPinInterrupts(NvicPriority_Normal);

   Llwu::setCallback(llwuCallback);

   Lptmr0::setCallback(lptmrCallback);
   Lptmr0::configureTimeIntervalMode(LptmrResetOnCompare_Enabled, LptmrInterrupt_Enabled, 10_s, LptmrClockSel_Lpoclk);
   Lptmr0::enableNvicInterrupts(NvicPriority_Normal);

   Smc::enableAllPowerModes();

   // Change to FEE to avoid further clock mode changes for LLS/VLLS
   console.flushOutput();
   Smc::enterRunMode(ClockConfig_RUN_FEE_80MHz);
   console.setBaudRate(defaultBaudRate);

   /*
    * Notes:
    * - LLWU will only be active in LLS/VLLS modes
    *   The LLWU interrupt will only be set for these modes
    * - The Switch input will wake-up the processor either through the usual interrupt mechanism or through the LLWU pin wake-up.
    *   The PIN interrupt flag will be set for the former only as the PORTs are disabled in LLS/VLLS modes.
    * - The LPTMR input will wake-up the processor either through the usual interrupt mechanism or through the LLWU module wake-up.
    *   The LPTMR interrupt flag will be set in either case as the LPTMR is active in LLS/VLLS.
    */
   for(;;) {
      wait(1_s);

      Lptmr0::clearInterruptFlag();
      Switch2_llwu::clearPinInterruptFlag();

      lptmrFlag   = false;
      pinFlag     = false;
      llwuFlag    = false;

      // LLWU is only of use in LLS/VLLS
      llwuInit.configure();
      Llwu::enableNvicInterrupts(NvicPriority_Normal);

      console.writeln("Going to sleep...").flushOutput();

      ErrorCode rc = Smc::enterPowerMode(SmcPowerMode_VLLS0);

      Pmc::releasePins();

      console.writeln("Awake!, rc = ", getErrorMessage(rc));

      if (lptmrFlag) {
         // Will indicate LPTMR timed out
         console.writeln("LPTMR call-back ran");
      }
      if (pinFlag) {
         // Will NOT be set on LLS/VLLS wake-up
         console.writeln("Pin call-back ran");
      }
      if (llwuFlag) {
         console.writeln("LLWU call-back ran");
      }
   }

   return 0;
}


