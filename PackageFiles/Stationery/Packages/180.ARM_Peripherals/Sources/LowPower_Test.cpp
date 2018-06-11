/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "smc.h"
#include "llwu.h"
#include "lptmr.h"
#include "mcg.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

using Switch = USBDM::GpioC<0, ActiveLow>;
using Led    = USBDM::GpioA<2, ActiveLow>;

// LLWU Wake-up pin to use
static constexpr LlwuPin llwuPin = LlwuPin_ptc1;


const McgInfo::ClockInfo clockInfo = {
   //! Clock Mode
   McgInfo::ClockMode_PEE,

   //! Mode flags
   0,

   //! Control Register 1
   MCG_C1_FRDIV(3)   | // FRDIV    FLL External Reference Divider
   MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
   MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

   //! Control Register 2
   MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
   MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
   MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
   MCG_C2_EREFS0(1) | // EREFS   External Reference Select
   MCG_C2_IRCS(1),    // IRCS    Internal Reference Clock Select

   //! Control Register 4
   MCG_C4_DMX32(0)     | // DMX32    DCO lock range
   MCG_C4_DRST_DRS(0),   // DRST_DRS DCO Range Select

   //! Control Register 5
   MCG_C5_PLLCLKEN0(0)  | // PLLCLKEN0 PLL Clock Enable
   MCG_C5_PLLSTEN0(0)   | // PLLSTEN0  PLL Stop Enable
   MCG_C5_PRDIV0(1),     // PRDIV0    PLL External Reference Divider

   //! Control Register 6
   MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
   MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
   MCG_C6_VDIV0(0),   // VDIV0  PLL VCO Divider

   //! Status and Control Register
   MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

   //! Control Register 7
   MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

   //! Control Register 8
   MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
   MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
   MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
};

static void wakeupCallback() {
   volatile uint32_t flags = Llwu::getPinWakeupSources();
   Llwu::clearWakeupPinFlags();

   if (Llwu::isPinWakeupSource(llwuPin)) {
      Llwu::clearWakeupPinFlag(llwuPin);
   }

   Led::toggle();

   flags = Llwu::getPeripheralWakeupSources();

   (void)flags;

   if (Llwu::isPeripheralWakeupSource(LlwuPeripheral_Lptmr)) {
      __asm__("nop");
   }
   __asm__("nop");
}

int main() {

   Switch::setInput(PinPull_Up);
   Led::setOutput(PinDriveStrength_High);

   Smc::enablePowerModes(
         SmcVeryLowPower_Enable,
         SmcLowLeakageStop_Enable,
         SmcVeryLowLeakageStop_Enable);

   Smc::setStopMode(SmcStopMode_NormalStop);
   Smc::setExitVeryLowPowerOnInterrupt(SmcExitVeryLowPowerOnInt_Disable);

   Smc::setStopOptions(SmcLowLeakageStopMode_LLS2, SmcPowerOnReset_Disable, SmcPartialStopMode_Normal);

   Llwu::enable();
   Llwu::configurePin(llwuPin, LlwuPinMode_EitherEdge);

   Llwu::setCallback(wakeupCallback);
   Llwu::enableNvicInterrupts();

   checkError();

   for (;;) {
      // Wait a while so that debugger can report.
      USBDM::waitMS(120);
      Smc::enterStopMode(SmcStopMode_LowLeakageStop);
   }
//   Smc::enterRunMode(SmcRunMode_VeryLowPower);
//   Smc::enterWaitMode();
//
//   Smc::sleep();
//   Smc::deepSleep();
//
//   Smc::enterRunMode(SmcRunMode_Normal);
//
//   Llwu::enable();
//   Llwu::configurePin(llwuPin, LlwuPinMode_EitherEdge);
//
//   Llwu::setCallback(wakeupCallback);
//   Llwu::enableNvicInterrupts();
//
//   checkError();
//
//   for(;;) {
//      __asm__("nop");
//      __WFI();
//   }

#if 0
//   Llwu::configurePin(LlwuPin_ptc1, LlwuPinMode_EitherEdge);
//   Llwu::configurePin(LlwuPin_pte1, LlwuPinMode_RisingEdge);
//   Llwu::configurePin(LlwuPin_ptc6, LlwuPinMode_FallingEdge);
//   Llwu::configurePin(LlwuPin_ptd6, LlwuPinMode_EitherEdge);

//   Llwu::configurePeripheral(LlwuPeripheral_Cmp0,  LlwuPeripheralMode_Enabled);
   //   Llwu::configurePeripheral(LlwuPeripheral_Cmp0,  LlwuPeripheralMode_Disabled);
   Llwu::configurePeripheral(LlwuPeripheral_Lptmr, LlwuPeripheralMode_Enabled);

//   Llwu::configureFilteredInput(0, LlwuPin_pta4, LlwuFilterPinMode_EitherEdge);
//   Llwu::configureFilteredInput(1, LlwuPin_ptd0, LlwuFilterPinMode_RisingEdge);

//   Llwu::isPinWakeupSource(llwuPin);
//   Llwu::isPeripheralWakeupSource(LlwuPeripheral_RtcAlarm);

   Llwu::clearWakeupPinFlag(llwuPin);
   Llwu::clearWakeupPinFlags();

//   Llwu::getPeripheralWakeupSources();
//   Llwu::getPinWakeupSources();

//   Lptmr0::setTimeCountingMode(LptmrResetOn_Compare);
//   Lptmr0::setClock(LptmrClockSel_lpoclk);
//   Lptmr0::setPeriod(10*seconds);

   // Enable LPTMR in time counting mode
   Lptmr0::setTimeCountingMode(LptmrResetOn_Compare);
   // Set clock source
   Lptmr0::setClock(LptmrClockSel_lpoclk);
   // Set period of timer event
   Lptmr0::setPeriod(10000*ms);

   // This handler is set programmatically
//   Lptmr0::setCallback(wakeupCallback);

//   Lptmr0::enableInterrupts();

   checkError();

   for(;;) {
      __asm__("nop");
      __WFI();
   }
#endif
}
