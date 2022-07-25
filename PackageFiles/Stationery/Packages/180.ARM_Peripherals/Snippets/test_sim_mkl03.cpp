/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

/**
 * See more examples in Snippets directory
 */

// LED connection - change as required
using Led   = GpioB<6,ActiveLow>;

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock = ").writeln(SystemCoreClock);
   console.write("SystemBusClock  = ").writeln(SystemBusClock);

   //************ SOPT1 **************/
   SimInfo::setErc32kClkoutPin(SimErc32kClkoutPinSelect_None);
   SimInfo::setErc32kClkoutPin(SimErc32kClkoutPinSelect_PTB13);
   SimInfo::getErc32kClock();

   SimInfo::setErc32kClock(SimOsc32kSel_Osc32kClk);
   SimInfo::setErc32kClock(SimOsc32kSel_LpoClk);
   SimInfo::setErc32kClock(SimOsc32kSel_RtcClkin);

   //************ SOPT2 **************/
   SimInfo::getPeripheralClock();

   SimInfo::setClkout(SimClkoutSel_Bus);
   SimInfo::setClkout(SimClkoutSel_Irc48MHz);
   SimInfo::setClkout(SimClkoutSel_Lpo);
   SimInfo::setClkout(SimClkoutSel_McgLirClk);
   SimInfo::setClkout(SimClkoutSel_OscerClk0);

   SimInfo::setRtcClockout(RtcClkoutSel_1Hz);
   SimInfo::setRtcClockout(RtcClkoutSel_32kHz);

   SimInfo::setTpmClock(SimTpmClockSource_Disabled);
   SimInfo::setTpmClock(SimTpmClockSource_McgIrClk);
   SimInfo::setTpmClock(SimTpmClockSource_OscerClk);
   SimInfo::setTpmClock(SimTpmClockSource_McgPClk);
   SimInfo::getTpmClock();

   SimInfo::setLpuart0Clock(SimLpuart0ClockSource_Disabled);
   SimInfo::setLpuart0Clock(SimLpuart0ClockSource_McgIrClk);
   SimInfo::setLpuart0Clock(SimLpuart0ClockSource_OscerClk);
   SimInfo::setLpuart0Clock(SimLpuart0ClockSource_McgPClk);
   SimInfo::getLpuart0Clock();

   //************ SOPT4 **************/
   TpmClkin0::setInput();

   SimInfo::setTpm0ExternalClockInput(SimTpm0ExternalClockInput_0);
   SimInfo::setTpm0ExternalClockInput(SimTpm0ExternalClockInput_1);

   SimInfo::setTpm1ExternalClockInput(SimTpm1ExternalClockInput_0);
   SimInfo::setTpm1ExternalClockInput(SimTpm1ExternalClockInput_1);

   SimInfo::setTpm1Ch0InputCaptureSource(SimTpm1Ch0InputCaptureSource_IcPin);
   SimInfo::setTpm1Ch0InputCaptureSource(SimTpm1Ch0InputCaptureSource_Cmp0);

   //************ SOPT5 **************/
   SimInfo::setLpuart0TxSrc(SimLpuart0TxSrc_Direct);
   SimInfo::setLpuart0TxSrc(SimLpuart0TxSrc_ModulatedByTpm1Ch0);

   SimInfo::setLpuart0RxSrc(SimLpuart0RxSrc_Lpuart0Rx);
   SimInfo::setLpuart0RxSrc(SimLpuart0RxSrc_Cmp0);

   SimInfo::setLpuart0Drive(SimLpuart0Drive_OpenDrain);
   SimInfo::setLpuart0Drive(SimLpuart0Drive_PushPull);

   //************ SOPT7 **************/
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0Trigger_Cmp0);
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0Trigger_Lptmr);
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_1, SimAdc0Trigger_RtcAlarm);
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_1, SimAdc0Trigger_RtcSeconds);

   //************ EXTERNAL **************/
   SimInfo::getAdcClock(AdcClockSource_Asynch);
   SimInfo::getAdcClock(AdcClockSource_Bus);
   SimInfo::getAdcClock(AdcClockSource_Busdiv2);
   SimInfo::getAdcClock(AdcClockSource_OscerClk);
   SimInfo::getAdcClock(AdcClockSource_Default);

   Led::setOutput();

   for(int count = 0;;count++) {
      Led::toggle();
      waitMS(100);
      SimInfo::feedCop();
      console.write(count).writeln(": Tick...");
   }
   return 0;
}
