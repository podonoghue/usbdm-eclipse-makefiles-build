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
   Lptmr0::clearEventFlag();
}

void pinCallback() {
   uint32_t pinStatusMask = Switch2_llwu::getPinEventFlags();
   (void)pinStatusMask;
   pinFlag = true;
   Switch2_llwu::clearPinEventFlag();
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

      console.writeln("LLWU DeviceFlag = ", llwuDeviceFlag);
      console.writeln("LLWU PinFlag    = ", llwuPinFlag);
      console.writeln("LLWU FilterFlag = ", llwuFilterFlag);
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

   /**
    * Configuration value for Lptmr0 in Time Interval Mode
    */
   static constexpr Lptmr0::TimeIntervalModeInit timerInitValue {
      NvicPriority_Normal,
      lptmrCallback,

      LptmrCounterActionOnEvent_Reset ,      // (lptmr_csr_tfc)            Counter Action on Compare Event - Counter is reset on event
      LptmrEventAction_Interrupt ,           // (lptmr_csr_tie)            Timer action on event - None
      LptmrClockSel_Lpoclk ,                 // (lptmr_psr_pcs)            Clock source for LPTMR - Low power oscillator (LPO - 1kHz)
      LptmrPrescale_Direct ,                 // (lptmr_psr_prescaler)      Prescaler Value - Prescaler = 1
      10_s,                                  // (lptmr_cmr_compare)        Timer Compare Value
   };

   Lptmr0::configure(timerInitValue);

   Smc::enableAllPowerModes();

   // Change to FEE to avoid further clock mode changes for LLS/VLLS
   console.flushOutput();
   Smc::enterRunMode(ClockConfig_RUN_FEE_80MHz);
   console.setBaudRate(defaultBaudRate);

   /*
    * Notes:
    * - LLWU will only be active in LLS/VLLS modes
    *   The LLWU interrupt will only be set for these modes
    * - The Switch input will wake-up the processor either through the usual interrupt mechanism or through the LLWU pin wake-up (reset).
    *   The PIN interrupt flag will be set for the former only as the PORTs are disabled in LLS/VLLS modes.
    * - The LPTMR input will wake-up the processor either through the usual interrupt mechanism or through the LLWU module wake-up.
    *   The LPTMR interrupt flag will be set in either case as the LPTMR is active in LLS/VLLS.
    *   LPO doesn't run on VLLS0 so LPTMR will be unavailable for wake-up.
    */
   for(;;) {
      wait(2_s);

      Lptmr0::clearEventFlag();
      Switch2_llwu::clearPinEventFlag();

      lptmrFlag   = false;
      pinFlag     = false;
      llwuFlag    = false;

      // LLWU is only of use in LLS/VLLS
      Llwu::configure(llwuInit);
      Llwu::enableNvicInterrupts(NvicPriority_Normal);

      console.writeln("Going to sleep...").flushOutput();

      ErrorCode rc = Smc::enterPowerMode(SmcPowerMode_VLLS1);

      Pmc::releaseIsolation();

      console.writeln("Awake!, rc = ", getErrorMessage(rc));

      // Note: This code will not run if wake-up via LLWU reset sequence

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


