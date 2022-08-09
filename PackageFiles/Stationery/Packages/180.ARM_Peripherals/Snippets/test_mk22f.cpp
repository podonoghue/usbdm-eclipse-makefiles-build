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
#include "smc.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// LED connection - change as required
using Led   = GreenLed;

int main() {
   console.writeln("Starting\n");
   console.writeln("SystemCoreClock = ", SystemCoreClock);
   console.writeln("SystemBusClock  = ", SystemBusClock);

   //************ SOPT1 **************/
   console.writeln("ramSize() = 0x", SimInfo::getRamSize(), Radix_16);

   SimInfo::setErc32kClock(SimOsc32kSel_Osc32kClk);
   SimInfo::setErc32kClock(SimOsc32kSel_LpoClk);
   SimInfo::setErc32kClock(SimOsc32kSel_Rtc32kClk);
   console.writeln("getErc32kClock() = ", SimInfo::getErc32kClock());

   SimInfo::setErc32kClkoutPin(SimErc32kClkoutPinSelect_None);
   SimInfo::setErc32kClkoutPin(SimErc32kClkoutPinSelect_PTE0);
   SimInfo::setErc32kClkoutPin(SimErc32kClkoutPinSelect_PTE26);

   SimInfo::setUsbPowerModes(SimUsbPower_Disabled);
   SimInfo::setUsbPowerModes(SimUsbPower_EnabledInAll);
   SimInfo::setUsbPowerModes(SimUsbPower_EnabledInRun);
   SimInfo::setUsbPowerModes(SimUsbPower_EnabledInRun_LowPower);
   SimInfo::setUsbPowerModes(SimUsbPower_EnabledInRun_Stop);

   //************ SOPT2 **************/

   SimInfo::setPeripheralClock(SimPeripheralClockSource_McgFllClk);
   console.writeln("getPeripheralClock() = ", SimInfo::getPeripheralClock());
   SimInfo::setPeripheralClock(SimPeripheralClockSource_McgPllClk);
   console.writeln("getPeripheralClock() = ", SimInfo::getPeripheralClock());
   SimInfo::setPeripheralClock(SimPeripheralClockSource_Irc48mClk);
   console.writeln("getPeripheralClock() = ", SimInfo::getPeripheralClock());

   SimInfo::setRtcClockout(SimRtcClkoutSel_1Hz);
   SimInfo::setRtcClockout(SimRtcClkoutSel_32kHz);

   SimInfo::setClkout(SimClkoutSel_FlashClk);
   SimInfo::setClkout(SimClkoutSel_LpoClk);
   SimInfo::setClkout(SimClkoutSel_McgIrClk);
   SimInfo::setClkout(SimClkoutSel_OscerClk0);
   SimInfo::setClkout(SimClkoutSel_RtcClk);

   SimInfo::setUsbFullSpeedClock(SimUsbFullSpeedClockSource_External);
   SimInfo::setUsbFullSpeedClock(SimUsbFullSpeedClockSource_PeripheralClk);

   SimInfo::setTraceClockout(SimTraceClockoutSel_CoreClk);
   SimInfo::setTraceClockout(SimTraceClockoutSel_McgOutClk);

   console.writeln("getUart0Clock() = ", SimInfo::getUart0Clock());

   console.writeln("getUart1Clock() = ", SimInfo::getUart1Clock());

   console.writeln("getUart2Clock() = ", SimInfo::getUart2Clock());

   SimInfo::setFlexbusSecurity(SimFlexbusSecurity_All);
   SimInfo::setFlexbusSecurity(SimFlexbusSecurity_DataOnly);
   SimInfo::setFlexbusSecurity(SimFlexbusSecurity_None);
   console.writeln("getFlexbusSecurity() = ", SimInfo::getFlexbusSecurity(), Radix_16);

   SimInfo::setLpuartClock(SimLpuartClockSource_Disabled);
   console.writeln("getLpuartClock() = ", SimInfo::getLpuartClock());
   SimInfo::setLpuartClock(SimLpuartClockSource_McgIrClk);
   console.writeln("getLpuartClock() = ", SimInfo::getLpuartClock());
   SimInfo::setLpuartClock(SimLpuartClockSource_OscerClk);
   console.writeln("getLpuartClock() = ", SimInfo::getLpuartClock());
   SimInfo::setLpuartClock(SimLpuartClockSource_PeripheralClk);
   console.writeln("getLpuartClock() = ", SimInfo::getLpuartClock());

   //************ SOPT4 **************/
//   FtmClkin0::setInput();

   SimInfo::setFtm0Flt0(SimFtm0Flt0_Cmp0);
   SimInfo::setFtm0Flt0(SimFtm0Flt0_Ftm0Fault0);

   SimInfo::setFtm0Flt1(SimFtm0Flt1_Cmp1);
   SimInfo::setFtm0Flt1(SimFtm0Flt1_Ftm0Fault1);

   SimInfo::setFtm1Flt0(SimFtm1Flt0_Cmp0);
   SimInfo::setFtm1Flt0(SimFtm1Flt0_Ftm1Fault0);

   SimInfo::setFtm2Flt0(SimFtm2Flt0_Cmp0);
   SimInfo::setFtm2Flt0(SimFtm2Flt0_Ftm2Fault0);

   SimInfo::setFtm3Flt0(SimFtm3Flt0_Cmp0);
   SimInfo::setFtm3Flt0(SimFtm3Flt0_Ftm3Fault0);

   SimInfo::setFtm1Ch0Src(SimFtm1Ch0Src_IcPin);
   SimInfo::setFtm1Ch0Src(SimFtm1Ch0Src_Cmp0);
   SimInfo::setFtm1Ch0Src(SimFtm1Ch0Src_Cmp1);
   SimInfo::setFtm1Ch0Src(SimFtm1Ch0Src_UsbSof);

   SimInfo::setFtm2Ch0Src(SimFtm2Ch0Src_IcPin);
   SimInfo::setFtm2Ch0Src(SimFtm2Ch0Src_Cmp0);
   SimInfo::setFtm2Ch0Src(SimFtm2Ch0Src_Cmp1);

   SimInfo::setFtm2Ch1Src(SimFtm2Ch1Src_IcPin);
   SimInfo::setFtm2Ch1Src(SimFtm2Ch1Src_Ftm2Ch1_Ftm2Ch2_Ftm1Ch1);

   SimInfo::setFtm0ClkSel(SimFtm0ClkSel_0);
   SimInfo::setFtm0ClkSel(SimFtm0ClkSel_1);

   SimInfo::setFtm1ClkSel(SimFtm1ClkSel_0);
   SimInfo::setFtm1ClkSel(SimFtm1ClkSel_1);

   SimInfo::setFtm2ClkSel(SimFtm2ClkSel_0);
   SimInfo::setFtm2ClkSel(SimFtm2ClkSel_1);

   SimInfo::setFtm3ClkSel(SimFtm3ClkSel_0);
   SimInfo::setFtm3ClkSel(SimFtm3ClkSel_1);

   SimInfo::setFtm0Trg0Src(SimFtm0Trg0Src_Cmp0);
   SimInfo::setFtm0Trg0Src(SimFtm0Trg0Src_Ftm1);

   SimInfo::setFtm0Trg1Src(SimFtm0Trg1Src_Ftm2);
   SimInfo::setFtm0Trg1Src(SimFtm0Trg1Src_PdbTrigger1);

   SimInfo::setFtm3Trg0Src(SimFtm3Trg0Src_Ftm1);

   SimInfo::setFtm3Trg1Src(SimFtm3Trg1Src_Ftm2);

   //************ SOPT5 **************/
   SimInfo::setUart0TxSrc(SimUart0TxSrc_ModulatedByFtm1Ch0);
   SimInfo::setUart0TxSrc(SimUart0TxSrc_ModulatedByFtm2Ch0);
   SimInfo::setUart0TxSrc(SimUart0TxSrc_Direct);

   SimInfo::setUart0RxSrc(SimUart0RxSrc_Cmp0);
   SimInfo::setUart0RxSrc(SimUart0RxSrc_Cmp1);
   SimInfo::setUart0RxSrc(SimUart0RxSrc_RxPin);

   SimInfo::setUart1TxSrc(SimUart1TxSrc_ModulatedByFtm1Ch0);
   SimInfo::setUart1TxSrc(SimUart1TxSrc_ModulatedByFtm2Ch0);
   SimInfo::setUart1TxSrc(SimUart1TxSrc_Direct);

   SimInfo::setUart1RxSrc(SimUart1RxSrc_Cmp0);
   SimInfo::setUart1RxSrc(SimUart1RxSrc_Cmp1);
   SimInfo::setUart1RxSrc(SimUart1RxSrc_RxPin);

   SimInfo::setLpuart0RxSrc(SimLpuart0RxSrc_Cmp0);
   SimInfo::setLpuart0RxSrc(SimLpuart0RxSrc_Cmp0);
   SimInfo::setLpuart0RxSrc(SimLpuart0RxSrc_Cmp1);
   SimInfo::setLpuart0RxSrc(SimLpuart0RxSrc_RxPin);

   //************ SOPT7 **************/
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Pdb);
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0Trigger_Cmp0);
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0Trigger_Lptmr);
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_1, SimAdc0Trigger_RtcAlarm);
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_1, SimAdc0Trigger_RtcSeconds);

   SimInfo::setAdc1Triggers(SimAdc1TriggerMode_Pdb);
   SimInfo::setAdc1Triggers(SimAdc1TriggerMode_Alt_PreTrigger_0, SimAdc1Trigger_Cmp0);
   SimInfo::setAdc1Triggers(SimAdc1TriggerMode_Alt_PreTrigger_0, SimAdc1Trigger_Lptmr);
   SimInfo::setAdc1Triggers(SimAdc1TriggerMode_Alt_PreTrigger_1, SimAdc1Trigger_RtcAlarm);
   SimInfo::setAdc1Triggers(SimAdc1TriggerMode_Alt_PreTrigger_1, SimAdc1Trigger_RtcSeconds);

   //************ SOPT8 **************/
   SimInfo::setFtm0Ch0OutputSrc(SimFtm0Ch0OutputSrc_Direct);
   SimInfo::setFtm0Ch0OutputSrc(SimFtm0Ch0OutputSrc_ModulatedByFtm1Ch1);

   SimInfo::setFtm0Ch1OutputSrc(SimFtm0Ch1OutputSrc_Direct);
   SimInfo::setFtm0Ch1OutputSrc(SimFtm0Ch1OutputSrc_ModulatedByFtm1Ch1);

   SimInfo::setFtm0Ch2OutputSrc(SimFtm0Ch2OutputSrc_Direct);
   SimInfo::setFtm0Ch2OutputSrc(SimFtm0Ch2OutputSrc_ModulatedByFtm1Ch1);

   SimInfo::setFtm0Ch3OutputSrc(SimFtm0Ch3OutputSrc_Direct);
   SimInfo::setFtm0Ch3OutputSrc(SimFtm0Ch3OutputSrc_ModulatedByFtm1Ch1);

   SimInfo::setFtm0Ch4OutputSrc(SimFtm0Ch4OutputSrc_Direct);
   SimInfo::setFtm0Ch4OutputSrc(SimFtm0Ch4OutputSrc_ModulatedByFtm1Ch1);

   SimInfo::setFtm0Ch5OutputSrc(SimFtm0Ch5OutputSrc_Direct);
   SimInfo::setFtm0Ch5OutputSrc(SimFtm0Ch5OutputSrc_ModulatedByFtm1Ch1);

   SimInfo::setFtm0Ch6OutputSrc(SimFtm0Ch6OutputSrc_Direct);
   SimInfo::setFtm0Ch6OutputSrc(SimFtm0Ch6OutputSrc_ModulatedByFtm1Ch1);

   SimInfo::setFtm0Ch7OutputSrc(SimFtm0Ch7OutputSrc_Direct);
   SimInfo::setFtm0Ch7OutputSrc(SimFtm0Ch7OutputSrc_ModulatedByFtm1Ch1);

   SimInfo::setFtm3Ch0OutputSrc(SimFtm3Ch0OutputSrc_Direct);
   SimInfo::setFtm3Ch0OutputSrc(SimFtm3Ch0OutputSrc_ModulatedByFtm2Ch1);

   SimInfo::setFtm3Ch1OutputSrc(SimFtm3Ch1OutputSrc_Direct);
   SimInfo::setFtm3Ch1OutputSrc(SimFtm3Ch1OutputSrc_ModulatedByFtm2Ch1);

   SimInfo::setFtm3Ch2OutputSrc(SimFtm3Ch2OutputSrc_Direct);
   SimInfo::setFtm3Ch2OutputSrc(SimFtm3Ch2OutputSrc_ModulatedByFtm2Ch1);

   SimInfo::setFtm3Ch3OutputSrc(SimFtm3Ch3OutputSrc_Direct);
   SimInfo::setFtm3Ch3OutputSrc(SimFtm3Ch3OutputSrc_ModulatedByFtm2Ch1);

   SimInfo::setFtm3Ch4OutputSrc(SimFtm3Ch4OutputSrc_Direct);
   SimInfo::setFtm3Ch4OutputSrc(SimFtm3Ch4OutputSrc_ModulatedByFtm2Ch1);

   SimInfo::setFtm3Ch5OutputSrc(SimFtm3Ch5OutputSrc_Direct);
   SimInfo::setFtm3Ch5OutputSrc(SimFtm3Ch5OutputSrc_ModulatedByFtm2Ch1);

   SimInfo::setFtm3Ch6OutputSrc(SimFtm3Ch6OutputSrc_Direct);
   SimInfo::setFtm3Ch6OutputSrc(SimFtm3Ch6OutputSrc_ModulatedByFtm2Ch1);

   SimInfo::setFtm3Ch7OutputSrc(SimFtm3Ch7OutputSrc_Direct);
   SimInfo::setFtm3Ch7OutputSrc(SimFtm3Ch7OutputSrc_ModulatedByFtm2Ch1);

   SimInfo::setFtmSyncBits(FtmSync_Ftm0|FtmSync_Ftm1|FtmSync_Ftm2);
   SimInfo::clearFtmSyncBits(FtmSync_Ftm0);
   SimInfo::clearAllFtmSyncBits();

   //************ EXTERNAL **************/
   Adc0::configure(AdcResolution_12bit_se, AdcClockSource_Irc48mClk);

   //************ USB0 **************/
   Usb0Info::enableClock();

   Usb0Info::enableIrc48m(UsbIrc48mClockEnable_Disabled);
   Usb0Info::enableIrc48m(UsbIrc48mClockEnable_Peripheral);
   Usb0Info::enableIrc48m(UsbIrc48mClockEnable_PeripheralAndUsb);

   Usb0Info::setIrc48mTracking(UsbIrc48mClockTrackingMode_NotTracking);
   Usb0Info::setIrc48mTracking(UsbIrc48mClockTrackingMode_AlwaysFineTracking, UsbIrc48mClockResetTrim_Keep);
   Usb0Info::setIrc48mTracking(UsbIrc48mClockTrackingMode_RoughAndFineTracking, UsbIrc48mClockResetTrim_Restart);

   SimInfo::setPeripheralClock(SimPeripheralClockSource_Irc48mClk);
   SimInfo::setUsbFullSpeedClock(SimUsbFullSpeedClockSource_PeripheralClk);

   //************ SMC **************/

   Smc::setSleepOnExit(SmcSleepOnExit_Enabled);
   Smc::setSleepOnExit(SmcSleepOnExit_Disabled);

   Smc::enableAllPowerModes();
   Smc::enablePowerModes(SmcHighSpeedRun_Enabled, SmcVeryLowPower_Enabled, SmcLowLeakageStop_Enabled, SmcVeryLowLeakageStop_Enabled);

   Smc::setStopMode(SmcStopMode_LowLeakageStop);
   Smc::setStopMode(SmcStopMode_NormalStop);
   Smc::setStopMode(SmcStopMode_VeryLowLeakageStop);
   Smc::setStopMode(SmcStopMode_VeryLowPowerStop);

   Smc::setStopOptions(SmcPartialStopMode_Normal, SmcLowLeakageStopMode_LLS3, SmcPowerOnReset_Enabled);
   Smc::setPartialStopMode(SmcPartialStopMode_Normal);
   Smc::setPartialStopMode(SmcPartialStopMode_Partial1);
   Smc::setPartialStopMode(SmcPartialStopMode_Partial2);
   Smc::setLowLeakageStopMode(SmcLowLeakageStopMode_VLLS0);
   Smc::setLowLeakageStopMode(SmcLowLeakageStopMode_VLLS1);
   Smc::setLowLeakageStopMode(SmcLowLeakageStopMode_VLLS2);
   Smc::setLowLeakageStopMode(SmcLowLeakageStopMode_VLLS3);
   Smc::setPowerOnResetInVLLS0(SmcPowerOnReset_Enabled);
   Smc::setPowerOnResetInVLLS0(SmcPowerOnReset_Disabled);

   console.writeln("Smc::getStatus() = ", Smc::getSmcStatusName(Smc::getStatus()));

   Smc::enterRunMode(SmcRunMode_HighSpeed, ClockConfig_PEE_120MHz);
   console.setBaudRate(defaultBaudRate);
   console.writeln("SystemCoreClock = ", SystemCoreClock);
   console.writeln("SystemBusClock  = ", SystemBusClock);
   console.writeln("Smc::getStatus() = ", Smc::getSmcStatusName());

//   Smc::enterPowerMode(SmcPowerMode_LLS3);
//   Smc::enterPowerMode(SmcPowerMode_VLLS3);

   Led::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);
   Led::setOutput(PinDriveStrength_High|PinDriveMode_PushPull|PinSlewRate_Slow);

   for(int count = 0;;count++) {
      Led::toggle();
      waitMS(100);
      console.writeln(count, ": Tick...");
   }
   return 0;
}
