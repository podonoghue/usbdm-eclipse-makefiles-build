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
 *  - RUN_CLOCK_CONFIG   = ClockConfig_PEE_48MHz   For RUN mode (Core=48MHz, Bus=24MHz, Flash=27MHz)
 *  - VLPR_CLOCK_CONFIG  = ClockConfig_BLPE_4MHz   For VLPR (Core/Bus = 4MHz, Flash = 1MHz)
 *
 * Interrupts must be configured for GPIO pin used, LLWU, LPTMR
 * It will also be necessary to modify the linker memory map so that only
 * lowest 32K of SRAM_U (0x10000000..) is used if testing of LLS2 is intended.
 *
 * Note: The STOP mode doesn't seem to work from RUN mode while using the
 * debugger.  INVSTATE occurs occasionally. Stand-alone it's OK.
 *
 * MK20D5 Power transition notes
 * LLS -> RUN mode on wake-up irrespective of whether it is entered from RUN or VLPR
 * VLPS -> RUN mode on wake-up if entered from RUN or LPWUI is set
 * VLPS -> VLPR only if entered from VLPR and LPWUI is not set
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

// Define clock modes to use
static ClockConfig RUN_CLOCK_CONFIG    = ClockConfig_PEE_48MHz;
static ClockConfig VLPR_CLOCK_CONFIG   = ClockConfig_BLPE_4MHz;

// May need reduced baud rate for slow clocks
static constexpr int BAUD_RATE = 115200;

// Using LEDs rather defeats VLLSx mode!
using RedLed    = GpioC<3,ActiveLow>;
using GreenLed  = GpioD<4,ActiveLow>;

// Timer to use for timed wake-up
using WakeupTimer = Lptmr0;

// LLWU Pin Filter to use
static constexpr unsigned FILTER_NUM = 0;

// LLWU Pin to use for wake-up
static constexpr LlwuPin  WAKEUP_PIN = LlwuPin_ptc1;

// LLWU pin configuration
using WakeupPin = PcrTable_T<LlwuInfo, WAKEUP_PIN>;

//! Flag to indicate Pin handler ran
bool pinHandlerRan;

//! Flag to indicate Timer handler ran
bool timerHandlerRan;

//! Flag to indicate LLWU handler ran
bool llwuHandlerRan;

/**
 * Call-back for Timer
 */
void wakeupTimerCallback() {
   // We could also put code here that would execute on LPTMR event
   timerHandlerRan = true;
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
void pinCallback(uint32_t status __attribute__((unused))) {
   pinHandlerRan = true;
   GreenLed::toggle();
}

/**
 * Call-back for LLWU events
 */
void llwuCallback() {
   llwuHandlerRan = true;
   if (Llwu::isPeripheralWakeupSource(LlwuPeripheral_Lptmr)) {
      // Wake-up from LPTMR
      RedLed::toggle();
      WakeupTimer::clearInterruptFlag();
      WakeupTimer::enableInterrupts(false);
   }
   if (Llwu::isPinWakeupSource(WAKEUP_PIN)) {
      // Wake-up from pin
      RedLed::toggle();
      Llwu::clearPinWakeupFlag(WAKEUP_PIN);
   }
   if (Llwu::isFilteredPinWakeupSource(FILTER_NUM)) {
      // Wake-up from filtered pin
      RedLed::toggle();
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
      case SmcStopMode_NormalStop:           console.write("Doing Normal Stop\n");           break;
      case SmcStopMode_VeryLowPowerStop:     console.write("Doing Very Low Power Stop\n");   break;
      case SmcStopMode_LowLeakageStop:       console.write("Doing Low Leakage Stop\n");      break;
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

   // Make sure handlers have run
   waitMS(10);

#ifdef MCG_C6_PLLS_MASK
   /*
    * If back in RUN mode we need to restore clock as
    * MCG transitions PEE->PBE when in STOP modes.
    * This assumes run mode is PEE
    */
   if (Smc::getStatus() == SmcStatus_run) {
      Mcg::clockTransition(McgInfo::clockInfo[RUN_CLOCK_CONFIG]);
      console.setBaudRate(BAUD_RATE);
      console.writeln("Awake!").flushOutput();
      console.writeln("Restored clock frequency").flushOutput();
   }
   else
#endif
   {
      console.writeln("Awake!").flushOutput();
   }
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
   console.writeln("Awake!").flushOutput();
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
 * @param test    Test being run
 * @param enable  Whether to enable pin wake-up or interrupt
 */
void enablePin(Test test, bool enable) {

   // Disable filtered pin
   Llwu::configureFilteredPinSource(
         FILTER_NUM,
         WAKEUP_PIN,
         LlwuFilterPinMode_Disabled);

   // Disable direct pin
   Llwu::configurePinSource(
         WAKEUP_PIN,
         LlwuPinMode_Disabled);

   // Disable wake-up pin
   Llwu::setInput<WAKEUP_PIN>(
         PinPull_Up,
         PinIrq_None,
         PinFilter_Passive);

   if (enable && (test>=LLS)) {

      // Configure wake-up pin as LLWU input
      Llwu::setInput<WAKEUP_PIN>(
            PinPull_Up,
            PinIrq_None,
            PinFilter_Passive);

      // Use LLWU in most Low-leakage modes
      Llwu::clearAllFlags();

      if (test!=VLLS0) {
         // LLWU from filtered pin
         // Not available in VLLS0 as LPO not running
         console.writeln("Configuring filtered LLWU pin wake-up").flushOutput();
         Llwu::configureFilteredPinSource(
               FILTER_NUM,
               WAKEUP_PIN,
               LlwuFilterPinMode_FallingEdge);
      }
      else {
         // LLWU direct from pin
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

      // Configure wake-up via GPIO interrupt
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
 * @param test    Test being run
 * @param enable  Whether to enable timer wake-up or interrupt
 */
void enableTimer(Test test, bool enable) {

   if (enable) {
      // Set up wake-up timer
      // Note - need a clock source that operates in LLSx e.g. ERCLK32

      console.writeln("Configuring timer interrupt").flushOutput();

      WakeupTimer::configureTimeCountingMode(
            LptmrResetOn_Compare,
            LptmrInterrupt_Enable,
            LptmrClockSel_lpoclk);
      WakeupTimer::setPeriod(5*seconds);
      WakeupTimer::setCallback(wakeupTimerCallback);
      WakeupTimer::enableNvicInterrupts();

      if (test>=LLS) {

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
 * @param pinEnable     Enable pin wake-up
 * @param timerEnable   Enable timer wake-up
 */
void runTest(
      Test  test,
      bool  pinEnable,
      bool  timerEnable) {

   // Timer can't be used with VLLS0
   timerEnable = timerEnable&&(test!=VLLS0);

   console.writeln("\n**************************************").flushOutput();
   console.write("Running Test: ").writeln(TestNames[test]);

   if (test == NONE) {
      // Not a test
      return;
   }

   if (!pinEnable && !timerEnable) {
      console.writeln("Can't do test without Pin or Timer wake-up method\n");
      return;
   }

   // Clear call-back flags
   pinHandlerRan   = false;
   llwuHandlerRan  = false;
   timerHandlerRan = false;

   enableTimer(test, timerEnable);
   enablePin(test, pinEnable);

   console.write("Wake-up using ").write(pinEnable?"Pin, ":"").writeln(timerEnable?"Timer":"");

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
   Llwu::enableNvicInterrupts(false);
   WakeupTimer::enableNvicInterrupts(false);
   WakeupPin::enableNvicInterrupts(false);

   console.write("Timer callback() ").writeln(timerHandlerRan?"Ran":"Didn't run");
   console.write("Pin callback()   ").writeln(pinHandlerRan?"Ran":"Didn't run");
   console.write("LLWU callback()  ").writeln(llwuHandlerRan?"Ran":"Didn't run");
   console.writeln("**************************************").flushOutput();
}

/**
 * Change run mode
 * VLPR<->RUN
 *
 * @return Run mode entered
 */
SmcStatus changeRunMode() {
   SmcStatus smcStatus = Smc::getStatus();
   if (smcStatus == SmcStatus_run) {
      // RUN->VLPR
      Mcg::clockTransition(McgInfo::clockInfo[VLPR_CLOCK_CONFIG]);
      Smc::enterRunMode(SmcRunMode_VeryLowPower);
      console.setBaudRate(BAUD_RATE);
      console.writeln("Changed to VLPR mode").flushOutput();
   }
   else if (smcStatus == SmcStatus_vlpr) {
      // VLPR->RUN mode
      Smc::enterRunMode(SmcRunMode_Normal);
      Mcg::clockTransition(McgInfo::clockInfo[RUN_CLOCK_CONFIG]);
      console.setBaudRate(BAUD_RATE);
      console.writeln("Changed to RUN mode").flushOutput();
   }
   return Smc::getStatus();
}

void help() {
   console.write(
         "\n\n"
         "***************************************************************\n"
#ifdef SMC_PMCTRL_LPWUI_MASK
         "LPWUI - Whether to exit VLPR,VLPW,VLPS to RUN mode on interrupt\n"
#endif
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
         "LPTMR - Uses LPO clock so not available in VLLS0\n"
         "Pin   - Port Pin used for interrupt or wake-up source\n"
         "***************************************************************\n"
   );
}

int main() {
   // Set UART (console) clock to clock source available in VLPR mode
   //SimInfo::setUart0Clock(SimUartClockSource_OscerClk);
   console.setBaudRate(BAUD_RATE);

   console.writeln("\n**************************************");
   console.write("Executing from RESET, SRS=").writeln(Rcm::getResetSourceDescription());
   // Configure LEDs
   GreenLed::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);
   RedLed::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   // Enable all power modes
   Smc::enablePowerModes(
         SmcVeryLowPower_Enable,
         SmcLowLeakageStop_Enable,
         SmcVeryLowLeakageStop_Enable);

   //Errata e4481 STOP mode recovery unstable
   Pmc::setBandgapOperation(PmcBandgapBuffer_Off, PmcBandgapLowPowerEnable_On);

   checkError();

   console.setEcho(EchoMode_Off);

   Test  test        = STOP;
   bool  refresh     = true;
   bool  enablePin   = true;
   bool  enableTimer = true;

#ifdef SMC_PMCTRL_LPWUI_MASK
   bool lpwui = false;
#endif

   for(;;) {
      SmcStatus smcStatus = Smc::getStatus();
      if (refresh) {
         console.write("SystemCoreClock  = ").writeln(::SystemCoreClock);
         console.write("SystemBusClock   = ").writeln(::SystemBusClock);

         switch(smcStatus) {
            default:
            case SmcStatus_run:
               console.write(
                     "\n\nTests\n"
                     "====================================\n"
                     "R - Change run mode - VLPR, RUN\n"
                     "S - Select STOP,VLPS test\n"
                     "W - Select WAIT test\n"
                     "L - Select LLS test\n"
                     "V - Select VLLS0, VLLS1, VLLS2, VLLS3 test\n"
#ifdef SMC_PMCTRL_LPWUI_MASK
                     "I - Toggle LPWUI\n"
#endif
                     "T - Toggle LPTMR wake-up (not available in VLLS0)\n"
                     "P - Toggle PIN wake-up source\n"
                     "H - Help\n"
               );
               break;
            case SmcStatus_vlpr:
               console.write(
                     "\n\nTests\n"
                     "====================================\n"
                     "R - Change run mode - VLPR, RUN\n"
                     "S - Select VLPS test\n"
                     "W - Select VLPW test\n"
                     "L - Select LLS test\n"
                     "V - Select VLLS0, VLLS1, VLLS2, VLLS3 test\n"
                     "T - Toggle LPTMR wake-up (not available in VLLS0)\n"
                     "P - Toggle PIN wake-up\n"
                     "H - Help\n"
               );
               break;
         }
         refresh = false;
      }
      console.write("\rE - Execute test (");
      console.write(Smc::getSmcStatusName());
      console.write(":");
      console.write(Mcg::getClockModeName());
      console.write("@");
      console.write(::SystemCoreClock);
#ifdef SMC_PMCTRL_LPWUI_MASK
      console.write(lpwui?", LPWUI":"       ");
#endif
      console.write(enablePin?", Pin":"     ");
      console.write((enableTimer&&(test!=VLLS0))?", Timer":"       ");
      console.write(", Test=");
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
               test = LLS;
            break;
         case 'V':
               test = ((test != VLLS0)&&(test != VLLS1)&&(test != VLLS2))?VLLS0:(Test)(test+1);
            break;
         case 'R':
            console.writeln("\n").flushOutput();
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
#ifdef SMC_PMCTRL_LPWUI_MASK
         case 'I':
            if (smcStatus==SmcStatus_run) {
               lpwui = !lpwui;
               Smc::setExitVeryLowPowerOnInterrupt(lpwui?SmcExitVeryLowPowerOnInt_Enable:SmcExitVeryLowPowerOnInt_Disable);
            }
            break;
#endif
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
