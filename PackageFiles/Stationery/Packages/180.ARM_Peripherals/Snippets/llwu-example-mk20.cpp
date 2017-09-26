/*
 ============================================================================
 * @file    llwu-example-mk20.cpp (180.ARM_Peripherals/Snippets/)
 * @brief   Basic C++ demo
 *
 *  Created on: 25/09/2017
 *      Author: podonoghue
 ============================================================================
 */
/*
 * This examples assumes that appropriate clock configurations have been created:
 *  - ClockConfig_PEE_48MHz   For RUN mode (Core=80MHz, Bus=40MHz, Flash=27MHz)
 *  - ClockConfig_BLPE_4MHz   For VLPR (Core/Bus = 4MHz, Flash = 1MHz)
 *
 * Interrupts must be configured for GPIO pin used, LLWU, LPTMR
 * It will also be necessary to modify the linker memory map so that only
 * lowest 32K of SRAM_U (0x10000000..) is used if testing of LLS2 is intended.
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
using GreenLed  = GpioD<4,ActiveLow>;
using LedRed    = GpioC<3,ActiveLow>;

// Timer to use for timed wake-up
using WakeupTimer = Lptmr0;

// LLWU Pin Filter to use
static constexpr unsigned FILTER_NUM = 0;

// LLWU Pin to use for wake-up
static constexpr LlwuPin  WAKEUP_PIN = LlwuPin_ptc1;

// Pin IRQ for non-LLWU use
using WakeupPin = GpioC<1, ActiveLow>;

/**
 * Call-back for Timer
 */
void wakeupTimerCallback() {
   // We could also put code here that would execute on LPTMR event
   GreenLed::toggle();
   WakeupTimer::clearInterruptFlag();
   WakeupTimer::enableInterrupts(false);
   __asm__("nop");
}

/**
 * Call-back for direct pin interrupt
 *
 * @param[in] status 32-bit value from ISFR (each bit indicates a pin interrupt source)
 */
void pinCallback(uint32_t) {
   GreenLed::toggle();
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
      // Wake-up from pin
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
 * @param smcLowLeakageStopMode  VLLS mode to enter VLLS0,1,2,3 (for VLLS only)
 */
void testStopMode(
      SmcStopMode             smcStopMode,
      SmcLowLeakageStopMode   smcLowLeakageStopMode=SmcLowLeakageStopMode_VLLS3) {

   switch (smcStopMode) {
      case SmcStopMode_NormalStop:           console.write("Doing Normal Stop\n");         break;
      case SmcStopMode_VeryLowPowerStop:     console.write("Doing Very Low Power Stop\n");   break;
      case SmcStopMode_LowLeakageStop:       console.write("Doing Low Leakage Stop\n");     break;
      case SmcStopMode_VeryLowLeakageStop:   console.write("Doing Very Low Leakage Stop\n"); break;
   };

   if ((smcStopMode!=SmcStopMode_LowLeakageStop)&&(smcStopMode!=SmcStopMode_VeryLowLeakageStop)) {
      // Not using LLWU
      console.writeln("Disabling LLWU").flushOutput();
      Llwu::disableAllSources();
   }

   // Set STOP mode to enter
   Smc::setStopMode(smcStopMode);
   Smc::setStopOptions(smcLowLeakageStopMode);

   /*
    * Go to sleep - LPTMR or PIN wake-up
    */
   console.writeln("Deep Sleeping...").flushOutput();

   Smc::enterStopMode();

   Llwu::disableAllSources();

   /*
    * If back in RUN mode we need to restore clock as
    * MCG transitions PEE->PBE when in STOP modes
    */
   if (Smc::getStatus() == SmcStatus_run) {
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_PEE_48MHz]);
      console.setBaudRate(defaultBaudRate);
      console.writeln("Restored clock frequency").flushOutput();
   }
   console.writeln("Awake").flushOutput();
}

void testWaitMode(SmcRunMode smcRunMode) {
   /*
    * Go to sleep - LPTMR or PIN wake-up
    */
   switch (smcRunMode) {
      case SmcRunMode_Normal:           console.write("Doing Wait\n");                  break;
      case SmcRunMode_VeryLowPower:     console.write("Doing Very Low Power Wait\n");   break;
      default: break;
   };

   console.writeln("Sleeping...").flushOutput();
   Smc::enterWaitMode();
   console.writeln("Awake").flushOutput();
}

/** Names of tests */
static const char *TestNames[] = {
   "NONE ", "STOP ", "VLPS ", "WAIT ", "VLPW ", "LLS  ", "VLLS0", "VLLS1", "VLLS2", "VLLS3",
};

/** Possible tests - must be in this order */
enum Test {
   NONE, STOP, VLPS, WAIT, VLPW, LLS, VLLS0, VLLS1, VLLS2, VLLS3,
};

/**
 * Enable pin wake-up
 *
 * @param enable
 */
void enablePin(Test test, bool enable) {

   // Disable filtered pin
   Llwu::configurePinSource(
         WAKEUP_PIN,
         LlwuPinMode_Disabled);

   // Disable direct pin
   Llwu::configurePinSource(
         WAKEUP_PIN,
         LlwuPinMode_Disabled);

   // Disable wake-up pin via GPIO Interrupt
   WakeupPin::setInput(
         PinPull_Up,
         PinIrq_None,
         PinFilter_Passive);

   if (enable && (test>=LLS)) {
      // Use LLWU in Low-leakage modes
      Llwu::clearAllFlags();

      // Configure wake-up pin via LLWU
      Llwu::configureInputPin<WAKEUP_PIN>(
            PinPull_Up,
            PinIrq_None,
            PinFilter_Passive);

      if (test!=VLLS0) {
         // LLWU from filtered pin (PTC1=Arduino-A1)
         // Not available in VLLS0 as LPO not running
         console.writeln("Configuring filtered LLWU pin wake-up").flushOutput();
         Llwu::configureFilteredPinSource(
               FILTER_NUM,
               WAKEUP_PIN,
               LlwuFilterPinMode_FallingEdge);
      }
      else {
         // LLWU direct from pin (PTC1=Arduino-A1)
         console.writeln("Configuring direct LLWU pin wake-up").flushOutput();
         Llwu::configurePinSource(
               WAKEUP_PIN,
               LlwuPinMode_FallingEdge);
      }
      Llwu::setCallback(llwuCallback);
      Llwu::enableNvicInterrupts();
   }
   if (enable && (test<LLS)) {
      // Enable pin interrupt if not low-leakage mode
      console.writeln("Configuring pin interrupt for wake-up").flushOutput();

      // Configure wake-up pin via GPIO
      WakeupPin::setInput(
            PinPull_Up,
            PinIrq_Falling,
            PinFilter_Passive);

      WakeupPin::clearInterruptFlag();
      WakeupPin::setCallback(pinCallback);
      WakeupPin::enableNvicInterrupts();
   }
   else {
      WakeupPin::enableNvicInterrupts(false);
   }
}

/**
 * Enable LPTMR wake-up
 *
 * @param enable
 */
void enableTimer(Test test, bool enable) {

   if (enable) {
      // Set up wake-up timer (3 seconds)
      // Note - need a clock source that operates in LLSx e.g. ERCLK32

      console.writeln("Configuring timer").flushOutput();

      WakeupTimer::configureTimeCountingMode(
            LptmrResetOn_Compare,
            LptmrInterrupt_Enable,
            LptmrClockSel_erclk32);
      WakeupTimer::setPeriod(3*seconds);
      WakeupTimer::setCallback(wakeupTimerCallback);
      WakeupTimer::enableNvicInterrupts();

      if ((test>=LLS) && (test<=VLLS3)) {

         // Use LLWU with timer
         Llwu::clearAllFlags();

         console.writeln("Configuring timer LLWU wake-up").flushOutput();
         Llwu::configurePeripheralSource(LlwuPeripheral_Lptmr);
      }
   }
   else {
      WakeupTimer::enableNvicInterrupts(false);
   }
}

/**
 * Run test
 *
 * @param test          Test to run
 * @param enablePin     Enable pin wake-up
 * @param enableTimer   Enable timer wake-up
 */
void runTest(
      Test  test,
      bool  pinEnable,
      bool  timerEnable) {

   if (test == NONE) {
      // Not a test
      return;
   }

   console.write("\nRunning Test: ").writeln(TestNames[test]);

   enableTimer(test, timerEnable);
   enablePin(test, pinEnable);

   switch(test) {
      case WAIT:  testWaitMode(SmcRunMode_Normal);             break;
      case VLPW:  testWaitMode(SmcRunMode_VeryLowPower);       break;
      case STOP:  testStopMode(SmcStopMode_NormalStop);        break;
      case VLPS:  testStopMode(SmcStopMode_VeryLowPowerStop);  break;
      case LLS:   testStopMode(SmcStopMode_LowLeakageStop);    break;
      case VLLS0: testStopMode(SmcStopMode_VeryLowLeakageStop, SmcLowLeakageStopMode_VLLS0); break;
      case VLLS1: testStopMode(SmcStopMode_VeryLowLeakageStop, SmcLowLeakageStopMode_VLLS1); break;
      case VLLS2: testStopMode(SmcStopMode_VeryLowLeakageStop, SmcLowLeakageStopMode_VLLS2); break;
      case VLLS3: testStopMode(SmcStopMode_VeryLowLeakageStop, SmcLowLeakageStopMode_VLLS3); break;
      case NONE: break;
   }

   WakeupTimer::enableNvicInterrupts(false);
   WakeupPin::enableNvicInterrupts(false);
}

/**
 * Change run mode
 * VLPR<->RUN
 *
 * @param smcRunMode Current run mode
 *
 * @return Run mode entered
 */
SmcStatus changeRunMode() {
   SmcStatus smcStatus = Smc::getStatus();
   if (smcStatus == SmcStatus_run) {
      // RUN->VLPR
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_BLPE_4MHz]);
      Smc::enterRunMode(SmcRunMode_VeryLowPower);
      console.setBaudRate(defaultBaudRate);
      console.writeln("Changed to VLPR mode").flushOutput();
   }
   else if (smcStatus == SmcStatus_vlpr) {
      // VLPR->RUN mode
      Smc::enterRunMode(SmcRunMode_Normal);
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_PEE_48MHz]);
      console.setBaudRate(defaultBaudRate);
      console.writeln("Changed RUN mode").flushOutput();
   }
   return Smc::getStatus();
}

void help() {
   console.write(
      "\n\n"
      "WAIT  - Wait mode (enter from RUN only)\n"
      "VLPW  - Very low power wait (enter from VLPR only)\n"
      "STOP  - Stop mode (enter from RUN only)\n"
      "VLPS  - Very low power Stop\n"
      "LLS2  - Low Leakage Stop 2 - 32K SRAMU retained\n"
      "LLS3  - Low Leakage Stop 3 - All RAM retained\n"
      "VLLS0 - Very Low Leakage Stop 0 - Exit via LLWU reset\n"
      "VLLS1 - Very Low Leakage Stop 1 - Exit via LLWU reset\n"
      "VLLS2 - Very Low Leakage Stop 2 - Exit via LLWU reset\n"
      "VLLS3 - Very Low Leakage Stop 3 - Exit via LLWU reset\n"
   );
}

int main() {
   console.write("\nExecuting from RESET, SRS=").writeln(Rcm::getResetSourcesDescription());

   // Configure LEDs
   GreenLed::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);
   LedRed::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   // Enable all power modes
   Smc::enablePowerModes(
         SmcVeryLowPower_Enable,
         SmcLowLeakageStop_Enable,
         SmcVeryLowLeakageStop_Enable);

   //Errata e4481 STOP mode recovery unstable
   Pmc::setBandgapOperation(PmcBandgapMode_AlwaysOn);

   checkError();

   console.setEcho(EchoMode_Off);

   Test        test        = STOP;
   bool        refresh     = true;
   bool        enablePin   = true;
   bool        enableTimer = false;

   for(;;) {
      SmcStatus smcStatus = Smc::getStatus();
      if (refresh) {
         switch(smcStatus) {
            case SmcStatus_hsrun:
               console.write(
                     "\n\nTests\n"
                     "====================================\n"
                     "R - Select VLPR, RUN mode\n"
                     "T - Toggle LPTMR wake-up source\n"
                     "P - Toggle PIN wake-up source\n"
                     "H - Help\n"
               );
               break;
            default:
            case SmcStatus_run:
               console.write(
                     "\n\nTests\n"
                     "====================================\n"
                     "R - Select VLPR, RUN mode\n"
                     "S - Select STOP,VLPS test\n"
                     "W - Select WAIT test\n"
                     "L - Select LLS test\n"
                     "V - Select VLLS0, VLLS1, VLLS2, VLLS3 test\n"
                     "T - Toggle LPTMR wake-up source\n"
                     "P - Toggle PIN wake-up source\n"
                     "H - Help\n"
               );
               break;
            case SmcStatus_vlpr:
               console.write(
                     "\n\nTests\n"
                     "====================================\n"
                     "R - Select VLPR, RUN mode\n"
                     "S - Select VLPS test\n"
                     "W - Select VLPW test\n"
                     "L - Select LLS test\n"
                     "V - Select VLLS0, VLLS1, VLLS2, VLLS3 test\n"
                     "T - Toggle LPTMR wake-up source\n"
                     "P - Toggle PIN wake-up source\n"
                     "H - Help\n"
               );
               break;
         }
         refresh = false;
      }
      console.write("\rE - Execute test (");
      console.write(Smc::getSmcStatusName());
      console.write(", ");
      console.write(Mcg::getClockModeName());
      console.write("@");
      console.write(::SystemCoreClock);
      console.write(enablePin?", Pin":"     ");
      console.write(enableTimer?", Timer":"       ");
      console.write(", ");
      console.write(TestNames[test]);
      console.write(") :   ");
      console.flushOutput();
      int command = toupper(console.readChar());
      switch(command) {
         case 'S':
            if (smcStatus==SmcStatus_run) {
               test = (test==VLPS)?STOP:VLPS;
            }
            else if (smcStatus==SmcStatus_vlpr) {
               test = VLPS;
            }
            break;
         case 'W':
            if (smcStatus==SmcStatus_run) {
               test = WAIT;
            }
            else if (smcStatus==SmcStatus_vlpr) {
               test = VLPW;
            }
            break;
         case 'L':
            if (smcStatus!=SmcStatus_hsrun) {
               test = LLS;
            }
            break;
         case 'V':
            if (smcStatus!=SmcStatus_hsrun) {
               test = ((test != VLLS0)&&(test != VLLS1)&&(test != VLLS2))?VLLS0:(Test)(test+1);
            }
            break;
         case 'R':
            console.writeln().flushOutput();
            switch(changeRunMode()) {
               default:
                  break;
               case SmcStatus_vlpr:
                  if (test==WAIT) {
                     test=VLPW;
                  }
                  else if (test==STOP) {
                     test=VLPS;
                  }
                  break;
            }
            refresh = true;
            break;
         case 'P':
            enablePin = !enablePin;
            break;
         case 'T':
            enableTimer = !enableTimer;
            break;
         case 'H':
            help();
            refresh = true;
            break;
         case 'E':
            if (test != NONE) {
               console.writeln().flushOutput();
               runTest(test, enablePin, enableTimer);
               refresh = true;
            }
            break;
         default: break;
      }
   }
   return 0;
}
