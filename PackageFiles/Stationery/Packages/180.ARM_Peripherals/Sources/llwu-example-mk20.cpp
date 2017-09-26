/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
/*
 * This examples assumes that an appropriate clock configuration has been created:
 *  - ClockConfig_PEE_48MHz   For RUN mode (Core=48MHz, Bus=48MHz, Flash = 24MHz)
 */
#include "hardware.h"
#include "mcg.h"
#include "smc.h"
#include "lptmr.h"
#include "llwu.h"
#include "pmc.h"
#include "rcm.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// LED connection - change as required
// Using LEDs rather defeats VLLSx mode!
using LedBlue   = USBDM::GpioA<2,ActiveLow>;
using LedRed    = USBDM::GpioC<3,ActiveLow>;

// Timer to use for timed wake-up
using WakeupTimer = Lptmr0;

// LLWU Pin Filter to use
static constexpr unsigned FILTER_NUM = 0;

// LLWU Pin to use for wake-up
static constexpr LlwuPin  WAKEUP_PIN = LlwuPin_ptc1;

/**
 * Call-back for Timer
 */
void wakeupTimerCallback() {
   // We could also put code here that would execute on LPTMR event
   LedBlue::toggle();
   __asm__("nop");
}

/**
 * Call-back for LLWU events
 */
void llwuCallback() {
   if (Llwu::isPeripheralWakeupSource(LlwuPeripheral_Lptmr)) {
      // Wake-up from LPTMR
      LedRed::toggle();
      WakeupTimer::clearInterruptFlag();
      WakeupTimer::enableInterrupts(false);
   }
   if (Llwu::isPinWakeupSource(WAKEUP_PIN)) {
      // Wake-up from filtered pin
      LedRed::toggle();
      Llwu::clearPinWakeupFlag(WAKEUP_PIN);
   }
   if (Llwu::isFilteredPinWakeupSource(FILTER_NUM)) {
      // Wake-up from filtered pin
      LedRed::toggle();
      Llwu::clearFilteredPinWakeupFlag(FILTER_NUM);
   }
   __asm__("nop");
}

/**
 *
 * @param smcStopMode            STOP mode to enter - STOP,VLPS,LLS,VLLS
 * @param smcLowLeakageStopMode  VLLS mode to enter (if applicable) VLLS0,1,2,3 (in VLLS modes)
 */
void testStopMode(
      SmcStopMode             smcStopMode,
      SmcLowLeakageStopMode   smcLowLeakageStopMode) {

   switch (smcStopMode) {
      case SmcStopMode_NormalStop:           console.write("Doing NormalStop\n");         break;
      case SmcStopMode_VeryLowPowerStop:     console.write("Doing VeryLowPowerStop\n");   break;
      case SmcStopMode_LowLeakageStop:       console.write("Doing LowLeakageStop\n");     break;
      case SmcStopMode_VeryLowLeakageStop:   console.write("Doing VeryLowLeakageStop\n"); break;
   };

   // Set up wake-up timer (3 seconds)
   // Note - need a clock source that operates in LLSx e.g. ERCLK32
   WakeupTimer::configureTimeCountingMode(
         LptmrResetOn_Compare,
         LptmrInterrupt_Enable,
         LptmrClockSel_erclk32);
   WakeupTimer::setPeriod(3*seconds);
   WakeupTimer::setCallback(wakeupTimerCallback);
   WakeupTimer::enableNvicInterrupts();

   if ((smcStopMode==SmcStopMode_LowLeakageStop)||(smcStopMode==SmcStopMode_VeryLowLeakageStop)) {

      Llwu::clearAllFlags();

      // LLWU from timer
      console.writeln("Configuring timer LLWU wake-up");
      Llwu::configurePeripheralSource(LlwuPeripheral_Lptmr);

      if ((smcStopMode!=SmcStopMode_VeryLowLeakageStop)||(smcLowLeakageStopMode!=SmcLowLeakageStopMode_VLLS0)) {
         // LLWU from filtered pin (PTC1=Arduino-A1)
         // Not available in VLLS0 as LPO not running
         console.writeln("Configuring filtered LLWU pin wake-up");
         Llwu::configureFilteredPinSource(
               FILTER_NUM,
               WAKEUP_PIN,
               LlwuFilterPinMode_FallingEdge);
      }
      else {
         // LLWU from pin (PTC1=Arduino-A1)
         console.writeln("Configuring direct LLWU pin wake-up");
         Llwu::configurePinSource(
               WAKEUP_PIN,
               LlwuPinMode_FallingEdge);
      }
      Llwu::setCallback(llwuCallback);
      Llwu::enableNvicInterrupts();
   }
   else {
      // Not using LLWU
      console.writeln("Disabling LLWU");
      Llwu::disableAllSources();
   }

   // Set STOP mode to enter
   Smc::setStopMode(smcStopMode);
   Smc::setStopOptions(smcLowLeakageStopMode);

   /*
    * Go to deep sleep - LPTMR or PIN wake-up
    */
   console<<"Sleeping...\n"<<Flush;

   Smc::enterStopMode();

   Llwu::disableAllSources();

   /*
    * Restore default clock mode as MCG will transition PEE->PBE when in STOP mode
    */
   Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_default]);
   console<<"Awake\n"<<Flush;
}

int main() {
   console.write("\nExecuting from RESET, SRS=").writeln(Rcm::getResetSourcesDescription());

   // Configure LEDs
   LedBlue::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);
   LedRed::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   Llwu::configureInputPin<WAKEUP_PIN>(
         PinPull_Up,
         PinIrq_None,
         PinFilter_None);

   // Enable all power modes
   Smc::enablePowerModes(
         SmcVeryLowPower_Enable,
         SmcLowLeakageStop_Enable,
         SmcVeryLowLeakageStop_Enable
   );

   //Errata e4481 STOP mode recovery unstable
   Pmc::setBandgapOperation(PmcBandgapMode_AlwaysOn);

   checkError();

   SmcStopMode             smcStopMode           = SmcStopMode_NormalStop;
   SmcLowLeakageStopMode   smcLowLeakageStopMode = SmcLowLeakageStopMode_VLLS3;
   console.setEcho(EchoMode_Off);
   int   command = 'N';
   const char *test    = "STOP";

   for(;;) {
      console.write(
            "\nTests\n"
            "====================================\n"
            "N - Normal stop\n"
            "V - VLPS\n"
            "L - LLS\n"
            "0 - VLLS0\n"
            "1 - VLLS1\n"
            "2 - VLLS2\n"
            "3 - VLLS3\n"
            "T - Run test (current=").
                  write(test).
                  write(") :");
      command = toupper(console.readChar());
      console.writeln();
      switch(command) {
         case 'N': test="STOP";  smcStopMode = SmcStopMode_NormalStop;         break;
         case 'V': test="VLPS";  smcStopMode = SmcStopMode_VeryLowPowerStop;   break;
         case 'L': test="LLS";   smcStopMode = SmcStopMode_LowLeakageStop;     break;
         case '0': test="VLLS0"; smcStopMode = SmcStopMode_VeryLowLeakageStop; smcLowLeakageStopMode = SmcLowLeakageStopMode_VLLS0; break;
         case '1': test="VLLS1"; smcStopMode = SmcStopMode_VeryLowLeakageStop; smcLowLeakageStopMode = SmcLowLeakageStopMode_VLLS1; break;
         case '2': test="VLLS2"; smcStopMode = SmcStopMode_VeryLowLeakageStop; smcLowLeakageStopMode = SmcLowLeakageStopMode_VLLS2; break;
         case '3': test="VLLS3"; smcStopMode = SmcStopMode_VeryLowLeakageStop; smcLowLeakageStopMode = SmcLowLeakageStopMode_VLLS3; break;

         case 't': case 'T': testStopMode(smcStopMode, smcLowLeakageStopMode); break;

         default: break;
      }
   }
   return 0;
}
