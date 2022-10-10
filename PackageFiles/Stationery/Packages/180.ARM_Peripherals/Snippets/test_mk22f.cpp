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
#include "llwu.h"
#include "lptmr.h"
#include "smc.h"
#include "adc.h"
#include "wdog.h"
#include "pit.h"
#include "mcm.h"
#include "fmc.h"
#include "wdog.h"
#include "sim.h"
#include "ftm.h"
#include "mcg.h"
#include "vref.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// LED connection - change as required
using Led   = RGB_Blue;

void flash() {
   Led::setOutput();
   for(int count = 0;;count++) {

      Wdog::refresh(WdogRefresh_1, WdogRefresh_2);

      Led::toggle();
      waitMS(100);
      console.writeln(count, ": Tick...");
   }
}

void doStuff(const PitChannel &pitChannel) {
   pitChannel.configure(2_s);
}

void callback() {
   console.writeln("Floating point exception");
}

void pitCallback() {
//   console.writeln("pit IRQ");
   Digital_D0::toggle();
}

void pinCallback(uint32_t ) {
   console.writeln("pin IRQ");
}

void lptmrCallback() {
   console.writeln("lptmr IRQ");
}

void ftmCallback() {
//   console.writeln("ftm IRQ");
   Digital_D0::toggle();
}

void report() {
   checkError();
   console_setBaudRate(defaultBaudRate);
   console.writeln(
         "Run mode = ", Smc::getSmcStatusName(),
         ", Clock = ", Mcg::getClockModeName(),
         "@", SystemCoreClock, " Hz").flushOutput();
}

static constexpr AdcResolution ADC_RESOLUTION = AdcResolution_10bit_se;

void adcCallback(uint32_t result, int channel) {
   console.writeln("ADC result ch(", channel, ") = ",
            (result*3.3)/Adc0::getSingleEndedMaximum(ADC_RESOLUTION), " volts");
}
void testADC() {

   using Test = Analogue_A0;

   Test::setInput();

//   Adc0::defaultConfigure();

   static const Adc0::Init adcInit {
        AdcClockSource_Asynch ,  // ADC Clock Source
        AdcClockDivider_1 ,      // Clock Divide Select
        ADC_RESOLUTION ,         // ADC Resolution
        AdcPower_Normal ,        // Low-Power Configuration
        AdcClockRange_Normal ,   // High-Speed Configuration
        AdcAsyncClock_Disabled , // Asynchronous Clock Output Enable
        AdcRefSel_VrefHL ,       // Voltage Reference Selection
        AdcDma_Disabled ,        // DMA Enable
        AdcMuxsel_B ,            // Selects between A/B multiplexor inputs on some ADC channels
        AdcDma_Disabled ,        // DMA Enable
        AdcTrigger_Software ,    // Conversion Trigger Select
        AdcAveraging_32 ,        // Hardware Average Select
        AdcContinuous_Enabled ,  // Selects between single and continuous conversion
        NvicPriority_Normal ,    // IRQ level for this peripheral
        adcCallback,             // Call-back to execute on completion
        // These 2/3 parameters must appear in this order
        AdcCompare_Disabled ,    // Compare function
        0 ,                      // ADC CV low value
        0,                       // ADC CV high value (May be omitted)
        Adc0::DefaultInitValue,
   };
   Adc0::configure(adcInit);
   Test::startConversion(AdcInterrupt_Enabled);
   for(;;) {
      __asm__("nop");
   }
   Test::OwningAdc::configure(AdcResolution_10bit_se);
   Test::OwningAdc::configure(AdcResolution_11bit_diff, AdcClockSource_Irc48mClk);
   Test::OwningAdc::configure(AdcResolution_10bit_se, AdcClockSource_Bus);

   Test::setInput();
   console.writeln("ADC = ", Test::readAnalogue());

   console.writeln("ADC  8b_se res   = ", Test::OwningAdc::getSingleEndedMaximum(AdcResolution_8bit_se));
   console.writeln("ADC 10b_se res   = ", Test::OwningAdc::getSingleEndedMaximum(AdcResolution_10bit_se));
   console.writeln("ADC 12b_se res   = ", Test::OwningAdc::getSingleEndedMaximum(AdcResolution_12bit_se));
   console.writeln("ADC 16b_se res   = ", Test::OwningAdc::getSingleEndedMaximum(AdcResolution_16bit_se));

   console.writeln("ADC  9b_diff res = ", Test::OwningAdc::getDifferentialMaximum(AdcResolution_9bit_diff));
   console.writeln("ADC 11b_diff res = ", Test::OwningAdc::getDifferentialMaximum(AdcResolution_11bit_diff));
   console.writeln("ADC 13b_diff res = ", Test::OwningAdc::getDifferentialMaximum(AdcResolution_13bit_diff));
   console.writeln("ADC 16b_diff res = ", Test::OwningAdc::getDifferentialMaximum(AdcResolution_16bit_diff));

   console.writeln("getAdcClock(AdcClockSource_Asynch)   = ", Adc0Info::getAdcClock(AdcClockSource_Asynch));
   console.writeln("getAdcClock(AdcClockSource_Bus)      = ", Adc0Info::getAdcClock(AdcClockSource_Bus));
   console.writeln("getAdcClock(AdcClockSource_Busdiv2)  = ", Adc0Info::getAdcClock(AdcClockSource_Irc48mClk));
   console.writeln("getAdcClock(AdcClockSource_OscerClk) = ", Adc0Info::getAdcClock(AdcClockSource_OscerClk));

   LightSensor::OwningAdc::configure(AdcResolution_8bit_se);
   LightSensor::setInput();
}

void timerCallback(uint8_t mask) {
   (void) mask;
   Led::toggle();
}

void testFTMInstances(FtmBase &test, FtmChannel &channel) {

   test.selectClock(FtmClockSource_FixedFrequencyClock,  FtmPrescale_DivBy1);
   test.setClockSource(FtmClockSource_FixedFrequencyClock);
   test.setPrescaler(FtmPrescale_DivBy32);
   test.stopCounter();
   test.setMode(FtmMode_LeftAligned);
   test.setCounterStartValue(100_ticks);
   test.setCounterMaximumValue(10000_ticks);
   test.setPolarity(ActiveHigh, 0b001100);
   test.setHighTime(100_us, 3);
   test.setDeltaEventTime(100, 3);
   channel.setDeltaEventTime(100);
   Ticks t;
   t = test.getCounterStartValue();
   t = test.getCounterMaximumValue();
   console.writeln("t = ", t);
}

void testFTM() {
   Led::setOutput();

   using Test = RGB_Red_Pwm;
   Test::setOutput();

   Digital_D0::setOutput();

   Ftm0::setChannelCallback(timerCallback);

   RGB_Red_Pwm::setOutput();
   static const Test::OwningFtm::ChannelInit channelInit0 {
      FtmChannelNum_0,
      FtmChannelMode_CombinePositivePulse , // Channel Mode - Disabled
      FtmChannelAction_None , // Action on Channel Event - No action
      FtmChannelReset_Disabled , // Reset counter on channel IC event - Disabled
      1000_ticks,  // Output Compare Event time
   };
   static const Test::OwningFtm::Channel<1>::ChannelInit channelInit1 {
      FtmChannelNum_1,
      FtmChannelMode_Disabled , // Channel Mode - Disabled
      FtmChannelAction_None , // Action on Channel Event - No action
      FtmChannelReset_Disabled , // Reset counter on channel IC event - Disabled
      2000_ticks,  // Output Compare Event time
   };
   console.writeln("configure(channelInit1), rc => ", getErrorMessage(Test::OwningFtm::configureChannel(channelInit0)));
   console.writeln("configure(channelInit2), rc => ", getErrorMessage(Test::OwningFtm::configureChannel(channelInit1)));

   Ftm0::Channel<0>::configure(channelInit0);
   Ftm0::Channel<1>::configure(channelInit1);

   static const Test::OwningFtm::Init ftmInit {
      FtmMode_LeftAligned,
      FtmOverflowAction_Interrupt,
      Digital_D0::toggle,
      NvicPriority_VeryHigh,
      FtmClockSource_SystemClock,
      FtmMode_CentreAligned,
      400_us,
      Test::OwningFtm::DefaultInitValue,
   };
   console.writeln("configure(init), rc => ", getErrorMessage(Test::OwningFtm::configure(ftmInit)));

   for(;;) {
      __asm__("nop");
   }

   Test::OwningFtm::configureChannel(Test::OwningFtm::DefaultChannelInitValues[FtmChannelNum_3]);

   static const FtmQuadDecoder1::QuadInit quadInit {
      FtmQuadratureMode_Phase_AB_Mode , // Quadrature decoding mode - Phase-AB Mode
      FtmPhaseAPolarity_ActiveHigh , // Polarity of Phase A input - Active High
      FtmPhaseBPolarity_ActiveHigh , // Polarity of Phase B input - Active High
      FtmPhaseAFilter_Disabled , // Filtering on Phase A input - No Filter
      FtmPhaseBFilter_Disabled , // Filtering on Phase B input - No Filter
      FtmOverflowAction_Interrupt , // Overflow Interrupt - Interrupt Enabled
      NvicPriority_Normal , // IRQ level for this peripheral - Normal
      FtmPrescale_DivBy32,  // Clock prescaler - Divide by 32
      ftmCallback,
      FtmQuadDecoder1::DefaultInitValue,
   };

   FtmQuadDecoder1::configure(quadInit);

   FtmQuadDecoder1::configure(FtmPrescale_DivBy1, FtmQuadratureMode_Phase_AB_Mode);

//
//   Test::OwningFtm::setCallback(Digital_D0::toggle);
//   Test::OwningFtm::configure(Test::OwningFtm::DefaultInitValue);
//
//   for(;;) {
//      __asm__("nop");
//   }

   for(;;) {
      __asm__("nop");
   }

   Test::OwningFtm::defaultConfigure();
   Test::OwningFtm::enableNvicInterrupts();

   Test::OwningFtm::configure(Test::OwningFtm::DefaultInitValue);

   console.writeln("25 ms = ", Test::OwningFtm::convertSecondsToTicks(25_ms));

   static const Test::OwningFtm::Init init2 {
      FtmMode_CentreAligned,
      FtmOverflowAction_Interrupt,
      Digital_D0::toggle,
      NvicPriority_VeryHigh,
      FtmClockSource_SystemClock,
      FtmPrescale_DivBy32, 100_ticks, 1000_ticks,
   };
   console.writeln("configure(init2), rc => ", getErrorMessage(Test::OwningFtm::configure(init2)));

   //************ FTM **************/
   Test::OwningFtm::configure(FtmMode_LeftAligned, FtmClockSource_SystemClock, FtmPrescale_DivBy16);

   Test::OwningFtm::selectClock(FtmClockSource_FixedFrequencyClock,  FtmPrescale_DivBy1);
   Test::OwningFtm::setClockSource(FtmClockSource_FixedFrequencyClock);
   Test::OwningFtm::setPrescaler(FtmPrescale_DivBy32);
   Test::OwningFtm::stopCounter();
   Test::OwningFtm::setCounterStartValue(100_ticks);
   Test::OwningFtm::setCounterMaximumValue(10000_ticks);
   Ticks t;
   t = Test::OwningFtm::getCounterStartValue();
   t = Test::OwningFtm::getCounterMaximumValue();
   console.writeln("t = ", t);

   Test::OwningFtm::setPeriod(20_ms);
   Test::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);
   Test::configure(FtmChannelMode_PwmHighTruePulses);
   Test::setHighTime(5_ms);
   Test::setDutyCycle(25);

   static const Ftm1Info::Init ftmInit1 {
      FtmMode_CentreAligned,
      FtmOverflowAction_Interrupt,
      FtmClockSource_SystemClock,
      100_us
   };
   Ftm1::configure(ftmInit1);

   Ftm0 ftm0;
   Ftm0::Channel<1> ftmChannel;
   ftm0.configure(FtmMode_LeftAligned, FtmClockSource_SystemClock, FtmPrescale_DivBy16);
   testFTMInstances(ftm0,ftmChannel);
   Ftm0::configure(FtmMode_LeftAligned, FtmClockSource_SystemClock, FtmPrescale_DivBy1);
   Ftm0::Channel<0>::configure(FtmChannelMode_OutputCompareToggle, FtmChannelAction_None);
   Ftm0::setMaximumInterval(100_ms);
   Ftm0::setPeriod(100_ms);
   Ftm0::getTime();

   Ftm0::convertTicksToSeconds(100_ticks);

   console.writeln("Ticks = ", 100_ticks);

   Ticks a(10U), b;
   b = a;
   console.writeln("b = ", b);
}

void testFMC() {

   //************ FMC **************/
   __asm__("nop");
   Fmc::setFlashBank0Cache(FmcFlashCache_Disabled);
   Fmc::setFlashBank0Cache(FmcFlashCache_DataOnly);
   Fmc::setFlashBank0Cache(FmcFlashCache_InstructionsOnly);
   Fmc::setFlashBank0Cache(FmcFlashCache_InstructionsAndData);

   Fmc::setFlashBank0Speculation(FmcFlashSpeculation_Disabled);
   Fmc::setFlashBank0Speculation(FmcFlashSpeculation_DataOnly);
   Fmc::setFlashBank0Speculation(FmcFlashSpeculation_InstructionsOnly);
   Fmc::setFlashBank0Speculation(FmcFlashSpeculation_InstructionsAndData);

   static constexpr Fmc::FlashBank0Init flashBank0Init {
      FmcFlashCache_InstructionsOnly,
      FmcFlashSpeculation_InstructionsOnly,
   };
   flashBank0Init.configure();
   Fmc::DefaultFlashBank0InitValue.configure();

   Fmc::FlashBank0Init currentFlashBank0Settings;
   currentFlashBank0Settings.readConfig();
   currentFlashBank0Settings.configure();

   Fmc::setFlashBank1Cache(FmcFlashCache_Disabled);
   Fmc::setFlashBank1Cache(FmcFlashCache_DataOnly);
   Fmc::setFlashBank1Cache(FmcFlashCache_InstructionsOnly);
   Fmc::setFlashBank1Cache(FmcFlashCache_InstructionsAndData);

   Fmc::setFlashBank1Speculation(FmcFlashSpeculation_Disabled);
   Fmc::setFlashBank1Speculation(FmcFlashSpeculation_DataOnly);
   Fmc::setFlashBank1Speculation(FmcFlashSpeculation_InstructionsOnly);
   Fmc::setFlashBank1Speculation(FmcFlashSpeculation_InstructionsAndData);

   static constexpr Fmc::FlashBank1Init flashBank1Init {
      FmcFlashCache_InstructionsOnly,
      FmcFlashSpeculation_InstructionsOnly,
   };
   flashBank1Init.configure();
   Fmc::DefaultFlashBank1InitValue.configure();

   Fmc::FlashBank1Init currentFlashBank1Settings;
   currentFlashBank1Settings.readConfig();
   currentFlashBank1Settings.configure();
}

void testGPIO() {

   using Led    = RGB_Blue;
   using Switch = Switch3;

   //************ GPIO **************/

   static const PcrInit pcrInit {
      PinPull_Up, PinAction_None, PinFilter_None,
      PinDriveStrength_High, PinDriveMode_OpenDrain, PinSlewRate_Slow,
   };
   Led::setOutput(pcrInit);
   Switch::setInput(pcrInit);

   Led::setOutput(PinDriveStrength_High, PinDriveMode_OpenDrain, PinSlewRate_Slow);

   Led::setOutput(pcrInit);
   Led::setPCR(pcrInit);

   Led::setOutput();
   Led::setOutput(PinDriveStrength_High, PinDriveMode_OpenDrain, PinSlewRate_Slow);
   Led::setOutput(pcrInit);

   Led::setInput();
   Led::setInput(PinPull_Up, PinAction_None, PinFilter_None);
   Led::setInput(pcrInit);

   Led::setInOut();
   Led::setInOut(PinPull_Down, PinDriveStrength_High, PinDriveMode_PushPull, PinAction_None, PinFilter_Digital, PinSlewRate_Slow);
   Led::setInOut(pcrInit);

   Led::setInput(PinDriveMode_OpenDrain|PinPull_Down|PinDriveStrength_High|PinAction_IrqFalling|PinFilter_Passive|PinSlewRate_Fast);

   Led::setInOut(PinPull_Down, PinDriveStrength_High, PinDriveMode_OpenDrain, PinAction_None, PinFilter_None, PinSlewRate_Fast);

   Switch::setInput(PinPull_Up, PinAction_IrqFalling, PinFilter_Passive);
   Switch::setPinCallback(pinCallback);
   Switch::enablePinNvicInterrupts(NvicPriority_Normal);
}

void reportLlwu(const Llwu::Init &llwuInit) {
   (void)llwuInit;
//   console.writeln(
//         "me=",llwuInit.me, Radix_2, "\n",
//         "pe=",llwuInit.pe[0], Radix_2, ", ",llwuInit.pe[1], Radix_2, ", ",llwuInit.pe[2], Radix_2, ", ",llwuInit.pe[3], Radix_2, "\n",
//         "filt=",llwuInit.filt[0], Radix_2, ", ",llwuInit.filt[1], Radix_2);
}

void testLLWU() {

   //************ LLWU **************/
   static constexpr Llwu::Init llwuInit {
      // Pins
      LlwuPin_Pta4,  LlwuPinMode_FallingEdge,
      LlwuPin_Pta13, LlwuPinMode_EitherEdge,
      LlwuPin_Ptd4,  LlwuPinMode_RisingEdge,

      // Filtered Pins
      LlwuFilterNum_1, LlwuPin_Switch2_llwu, LlwuFilterPinMode_EitherEdge,
      LlwuFilterNum_2, LlwuPin_Ptc3, LlwuFilterPinMode_RisingEdge,

      // Peripherals
      LlwuPeripheral_RtcAlarm,
      LlwuPeripheral_Lptmr0,
   };
   reportLlwu(llwuInit);
   llwuInit.configure();
   reportLlwu(Llwu::DefaultInitValue);
   Llwu::DefaultInitValue.configure();

   Llwu::configureFilteredPinSource(LlwuFilterNum_1, LlwuPin_Switch2_llwu, LlwuFilterPinMode_EitherEdge);

   Llwu::DefaultInitValue.configure();
   Llwu::defaultConfigure();
}

void testLPTMR() {

   Lptmr0::setCallback(lptmrCallback);
   Lptmr0::defaultConfigure();

   for(;;) {
      __asm__("nop");
   }
   LptmrInput2::setInput(PinPull_Up, PinAction_None, PinFilter_Passive);

   Digital_D0::setOutput();

   Lptmr0::setCallback(Digital_D0::toggle);
   Lptmr0::configure(Lptmr0::DefaultTimeIntervalModeInitValue);
   Lptmr0::defaultConfigure();

   for(;;) {
      __asm__("nop");
   }

   static constexpr Lptmr0::TimeIntervalModeInit lptrmTimeIntervalMode {
      LptmrResetOnCompare_Enabled,
      LptmrInterrupt_Enabled,
      LptmrClockSel_Oscerclk,
      Digital_D0::toggle,
      NvicPriority_Normal,
      100_ms,
   };
   console.writeln("Init() Result = ", getErrorMessage(Lptmr0::configure(lptrmTimeIntervalMode)));

   for(;;) {
      __asm__("nop");
   }

   static constexpr Lptmr0::PulseCountingModeInit lptrmPulseCountingMode {
      LptmrPinSel_AltPin2,
      LptmrResetOnCompare_Disabled,
      LptmrPulseEdge_Rising,
      LptmrInterrupt_Enabled,
      LptmrClockSel_Oscerclk,
      LptmrGlitchFilter_128_clocks,
      Digital_D0::toggle,
      NvicPriority_High,
      100_ticks,
   };
   Lptmr0::configure(lptrmPulseCountingMode);

   Lptmr0::setCompareThreshold(100_ticks);
   Lptmr0::setClock(LptmrClockSel_Lpoclk, LptmrPrescale_DivBy_1024);
   Lptmr0::setClock(LptmrClockSel_Lpoclk, LptmrGlitchFilter_128_clocks);
   Lptmr0::setInputClockSource(LptmrClockSel_Mcgirclk);
   Lptmr0::setFilterInterval(500_ms);
   Lptmr0::setPeriod(10_s);

   Lptmr0::configure(lptrmPulseCountingMode);
   Lptmr0::setPeriod(10_s);

   Lptmr0::defaultConfigure();


   Lptmr0::configureTimeIntervalMode(LptmrResetOnCompare_Enabled, LptmrInterrupt_Enabled, LptmrClockSel_Lpoclk);
   Lptmr0::setPeriod(2_s);
   Lptmr0::setCallback(lptmrCallback);
   Lptmr0::enableNvicInterrupts(NvicPriority_Normal);

   Lptmr0::setClock(LptmrClockSel_Lpoclk, LptmrPrescale_DivBy_16384);
   Lptmr0::setInputClockSource(LptmrClockSel_Mcgirclk);
   (void)Lptmr0::getInputClockFrequency();
   (void)Lptmr0::getClockFrequency();
   (void)Lptmr0::getClockFrequencyF();
   Lptmr0::enableInterrupts(LptmrInterrupt_Disabled);
   Lptmr0::clearInterruptFlag();
   Lptmr0::setFilterInterval(5_s);

   static const Lptmr0::PulseCountingModeInit lptrmGlitchInit {
      LptmrPinSel_Cmp0,
      LptmrPulseEdge_Rising,
      LptmrClockSel_Mcgirclk,
      LptmrGlitchFilter_128_clocks,
      LptmrInterrupt_Enabled,
      LptmrResetOnCompare_Enabled,
      100_ticks,
   };
   Lptmr0::configure(lptrmGlitchInit);

   static const Lptmr0::TimeIntervalModeInit lptrmTimeInit {
      LptmrResetOnCompare_Enabled,
      LptmrInterrupt_Enabled,
      LptmrClockSel_Lpoclk,
      LptmrPrescale_DivBy_16,
      100_ms,
   };
   Lptmr0::configure(lptrmTimeInit);

   Lptmr0::configurePulseCountingMode(LptmrPinSel_AltPin1, LptmrPulseEdge_Falling, LptmrClockSel_Lpoclk, LptmrGlitchFilter_128_clocks, LptmrResetOnCompare_Enabled, LptmrInterrupt_Enabled);
   Lptmr0::configureTimeIntervalMode(LptmrResetOnCompare_Enabled, LptmrInterrupt_Enabled, LptmrClockSel_Mcgirclk, LptmrPrescale_DivBy_16);
   Lptmr0::configure(Lptmr0::DefaultPulseCountingModeInitValue);
   Lptmr0::configure(Lptmr0::DefaultTimeIntervalModeInitValue);

   Lptmr0::defaultConfigure();

}

class MyClockChangeCallback : public ClockChangeCallback {
public:
   virtual void beforeClockChange() override {
      console.writeln("Before clock change");
      console.flushOutput();
   }
   virtual void afterClockChange() override {
      console.setBaudRate(defaultBaudRate);
      console.writeln("After clock change");
   }
};

MyClockChangeCallback cb;

void testMCG() {

   //************ MCG **************/
//   McgInfo::enableMcgIrClock(McgIrClkEn_Enabled);
//   McgInfo::enableMcgIrClock(McgIrClkEn_Disabled);
//   McgInfo::setInternalReferenceClock(McgIrClkSrc_Fast);
//   McgInfo::setInternalReferenceClock(McgIrClkSrc_Slow);

   Mcg::addClockChangeCallback(cb);
   Smc::enableAllPowerModes();
   Smc::enterRunMode(ClockConfig_VLPR_BLPE_4MHz);
   waitMS(1000);
   Smc::enterRunMode(ClockConfig_RUN_PEE_80MHz);
   waitMS(1000);
   Smc::enterRunMode(ClockConfig_HSRUN_PEE_120MHz);
   waitMS(1000);
   Smc::enterRunMode(ClockConfig_RUN_PEE_80MHz);
   waitMS(1000);
}

void testMCM(){

   //************ MCM **************/
   Mcm::setCrossbarArbitration(McmArbitration_FixedPriority);

   Mcm::defaultConfigure();
   Mcm::enable();

   Mcm::enterComputeMode(McmComputeOnlyMode_Enable);
   Mcm::enterComputeMode(McmComputeOnlyMode_EnableWithWakeOnInterrupt);
   Mcm::exitComputeMode();

   Mcm::enableNvicInterrupts(NvicPriority_High);
   Mcm::setCallback(callback);

   static const Mcm::FloatingPointIrqInit floatingPointIrqs(
         McmFpuDenormalIrq_Select,
         McmFpuInvalidOperationIrq_Select,
         McmFpuDivideByZeroIrq_Select,
         Mcm::DefaultFloatingPointIrqInitValue);
   floatingPointIrqs.configure();
   floatingPointIrqs.enableInterrupts();
   floatingPointIrqs.disableInterrupts();

   Mcm::FloatingPointIrqInit{
      McmFpuDenormalIrq_Select,
      McmFpuUnderflowIrq_Select}.disableInterrupts();

   Mcm::DefaultFloatingPointIrqInitValue.configure();
   Mcm::disableMcmFpuDenormalIrq();

   Mcm::FloatingPointIrqInit{
      // List of interrupts to modify
      McmFpuDenormalIrq_Select,          // This interrupt is enabled
      McmFpuDivideByZeroIrq_Unselect,    // This interrupt is disabled
      Mcm::DefaultFloatingPointIrqInitValue  // Other interrupts are determined by this value (determined by configure.usbdmProject)
   }.configure();

   // The above is equivalent to:
   Mcm::DefaultFloatingPointIrqInitValue.configure();
   Mcm::FloatingPointIrqInit {McmFpuDenormalIrq_Select}.enableInterrupts();
   Mcm::FloatingPointIrqInit {McmFpuDivideByZeroIrq_Select}.disableInterrupts();

   Mcm::FloatingPointIrqInit currentFloatingPointIrqSettings;
   currentFloatingPointIrqSettings.readConfig();
   currentFloatingPointIrqSettings.enableInterrupts();
}

void testOSC() {

   //************ OSC **************/
   Osc0Info::setErcDivider(OscErClkDiv_By1);
   Osc0Info::setErcDivider(OscErClkDiv_By2);
   Osc0Info::setErcDivider(OscErClkDiv_By4);
   Osc0Info::setErcDivider(OscErClkDiv_By8);

   Osc0Info::enableExternalReference(OscErClkEn_Disabled);
   Osc0Info::enableExternalReference(OscErClkEn_Enabled);
}

void testPIT() {

   Digital_D0::setOutput();
// const PitInfo::Init PitInfo::DefaultChannel1InitValue
//   Pit::configure(Pit::DefaultChannel0InitValue);
//   Pit::configure(Pit::DefaultChannel1InitValue);
//
//   static const Pit::Init init1 {
//      PitChannelNum_0,
//      PitChannelEnable_Enabled,
//      PitChannelChain_Disabled,
//      PitChannelIrq_Enabled,
//      Digital_D0::toggle,
//      NvicPriority_Normal,
//      100_ticks,
//   };
//   Pit::configure(init1);

   Pit::configure(Pit::DefaultChannelInitValues[1]);

   static const Pit::Init init2 {
      PitChannelNum_1,
      PitChannelEnable_Enabled,
      PitChannelChain_Disabled,
      PitChannelIrq_Enabled,
      Digital_D0::toggle,
      NvicPriority_VeryHigh,
      200_ms,
   };
   Pit::configure(init2);

   for(;;) {
      __asm__("nop");
   }
   Pit::configure(PitDebugMode_Stop);
//   Pit::setCallback(PitChannelNum_0, pitCallback);
   Pit::configureChannel(PitChannelNum_0, 1_s, PitChannelIrq_Enabled);
//   Pit::enableNvicInterrupts(PitChannelNum_0);

   using PitChannel = Pit::Channel<0>;

   PitChannel::Owner::configure(PitDebugMode_Stop);
//   PitChannel::setCallback(pitCallback);
   PitChannel::configure(1_s, PitChannelIrq_Enabled);
   PitChannel::enableNvicInterrupts(NvicPriority_Normal);
}

void testSIM() {

   static const Sim::Init simInit {
      SimErc32kClkoutPinSelect_None , // ERCLK32K Clock Output
      SimErc32kSel_LpoClk , // ERCLK32K clock source
      SimUsbPower_EnabledInAll,  // USB voltage regulator power control
      SimLpuartClockSource_PeripheralClk,  // LPUART Clock select
      SimUsbFullSpeedClockSource_PeripheralClk,  // USB Clock
      SimTraceClockoutSel_McgOutClk,  // Debug trace clock select
      SimRtcClkoutSel_32kHz,  // RTC clock out source
      SimClkoutSel_OscerClk0,  // CLKOUT pin clock
      SimPeripheralClockSource_Irc48mClk,  // Peripheral Clock
      SimFlexbusSecurity_None,  // FlexBus off-chip access security level
      SimFtm0Flt0_Ftm0Fault0,  // FTM0 Fault 0 Select
      SimFtm0Trg0Src_Cmp0,  // FTM0 Hardware Trigger 0 Source
      SimFtm0Flt1_Ftm0Fault1,  // FTM0 Fault 1 Select
      SimFtm0Trg1Src_PdbTrigger1,  // FTM0 Hardware Trigger 1 Source
      SimFtm0ClkSel_FtmClkin0,  // FTM0 External Clock Pin
      SimFtm1Flt0_Ftm1Fault0,  // FTM1 Fault 0 Select
      SimFtm1Ch0Src_IcPin,  // FTM 1 channel 0 input capture source
      SimFtm1ClkSel_FtmClkin0,  // FTM1 External Clock Pin
      SimFtm2Flt0_Ftm2Fault0,  // FTM2 Fault 0 Select
      SimFtm2Ch0Src_IcPin,  // FTM2 channel 0 input capture source
      SimFtm2Ch1Src_IcPin,  // FTM2 channel 1 input capture source
      SimFtm2ClkSel_FtmClkin0,  // FTM2 External Clock Pin
      SimFtm3Flt0_Ftm3Fault0,  // FTM3 Fault 0 Select
      SimFtm3Trg0Src_Ftm1,  // FTM3 Hardware Trigger 0 Source
      SimFtm3Trg1Src_Ftm2,  // FTM3 Hardware Trigger 1 Source
      SimFtm3ClkSel_FtmClkin0,  // FTM3 External Clock Pin
      SimUart0RxSrc_RxPin,  // UART 0 receive data source
      SimUart0TxSrc_Direct,  // UART 0 transmit data source
      SimLpuart0RxSrc_RxPin,  // LPUART 0 receive data source
      SimUart1RxSrc_RxPin,  // UART 1 receive data source
      SimUart1TxSrc_Direct,  // UART 1 transmit data source
      SimAdc0TriggerMode_Pdb , // ADC0 trigger mode
      SimAdc0TriggerSrc_External,  // ADC0 trigger
      SimAdc1TriggerMode_Pdb , // ADC1 trigger mode
      SimAdc1TriggerSrc_External,  // ADC1 trigger
      SimFtm0Ch0OutputSrc_Direct,  // FTM0 channel 0 output source
      SimFtm3Ch0OutputSrc_Direct,  // FTM3 channel 0 output source
      SimFtm0Ch1OutputSrc_Direct,  // FTM0 channel 1 output source
      SimFtm3Ch1OutputSrc_Direct,  // FTM3 channel 1 output source
      SimFtm0Ch2OutputSrc_Direct,  // FTM0 channel 2 output source
      SimFtm3Ch2OutputSrc_Direct,  // FTM3 channel 2 output source
      SimFtm0Ch3OutputSrc_Direct,  // FTM0 channel 3 output source
      SimFtm3Ch3OutputSrc_Direct,  // FTM3 channel 3 output source
      SimFtm0Ch4OutputSrc_Direct,  // FTM0 channel 4 output source
      SimFtm3Ch4OutputSrc_Direct,  // FTM3 channel 4 output source
      SimFtm0Ch5OutputSrc_Direct,  // FTM0 channel 5 output source
      SimFtm3Ch5OutputSrc_Direct,  // FTM3 channel 5 output source
      SimFtm0Ch6OutputSrc_Direct,  // FTM0 channel 6 output source
      SimFtm3Ch6OutputSrc_Direct,  // FTM3 channel 6 output source
      SimFtm0Ch7OutputSrc_Direct,  // FTM0 channel 7 output source
      SimFtm3Ch7OutputSrc_Direct,  // FTM3 channel 7 output source
   };
   simInit.configure();

   Sim::DefaultInitValue.configure();


   //************ SOPT1 **************/
   console.writeln("ramSize() = 0x", Sim::getRamSize(), Radix_16);

   Sim::setErc32kClock(SimErc32kSel_Osc32kClk);
   Sim::setErc32kClock(SimErc32kSel_LpoClk);
   Sim::setErc32kClock(SimErc32kSel_Rtc32kClk);
   console.writeln("getErc32kClock() = ", Sim::getErc32kClock());

   Sim::setErc32kClkoutPin(SimErc32kClkoutPinSelect_None);
   Sim::setErc32kClkoutPin(SimErc32kClkoutPinSelect_PTE0);
   Sim::setErc32kClkoutPin(SimErc32kClkoutPinSelect_PTE26);

   Sim::setUsbPowerModes(SimUsbPower_Disabled);
   Sim::setUsbPowerModes(SimUsbPower_EnabledInAll);
   Sim::setUsbPowerModes(SimUsbPower_EnabledInRun);
   Sim::setUsbPowerModes(SimUsbPower_EnabledInRun_LowPower);
   Sim::setUsbPowerModes(SimUsbPower_EnabledInRun_Stop);

   //************ SOPT2 **************/

   Sim::setPeripheralClock(SimPeripheralClockSource_McgFllClk);
   console.writeln("getPeripheralClock() = ", Sim::getPeripheralClock());
   Sim::setPeripheralClock(SimPeripheralClockSource_McgPllClk);
   console.writeln("getPeripheralClock() = ", Sim::getPeripheralClock());
   Sim::setPeripheralClock(SimPeripheralClockSource_Irc48mClk);
   console.writeln("getPeripheralClock() = ", Sim::getPeripheralClock());
//   Sim::setPeripheralClock(SimPeripheralClockSource_Usb1PfdClk);
//   console.writeln("getPeripheralClock() = ", Sim::getPeripheralClock());

   Sim::setRtcClockout(SimRtcClkoutSel_1Hz);
   Sim::setRtcClockout(SimRtcClkoutSel_32kHz);

   Sim::setClkout(SimClkoutSel_FlashClk);
   Sim::setClkout(SimClkoutSel_LpoClk);
   Sim::setClkout(SimClkoutSel_McgIrClk);
   Sim::setClkout(SimClkoutSel_OscerClk0);
   Sim::setClkout(SimClkoutSel_RtcClk);

   Sim::setUsbFullSpeedClock(SimUsbFullSpeedClockSource_External);
   Sim::setUsbFullSpeedClock(SimUsbFullSpeedClockSource_PeripheralClk);

   Sim::setTraceClockout(SimTraceClockoutSel_CoreClk);
   Sim::setTraceClockout(SimTraceClockoutSel_McgOutClk);

   console.writeln("getUart0Clock() = ", Sim::getUart0Clock());

   console.writeln("getUart1Clock() = ", Sim::getUart1Clock());

   console.writeln("getUart2Clock() = ", Sim::getUart2Clock());

   Sim::setFlexbusSecurity(SimFlexbusSecurity_All);
   Sim::setFlexbusSecurity(SimFlexbusSecurity_DataOnly);
   Sim::setFlexbusSecurity(SimFlexbusSecurity_None);
   console.writeln("getFlexbusSecurity() = ", Sim::getFlexbusSecurity(), Radix_16);

   Sim::setLpuartClock(SimLpuartClockSource_Disabled);
   console.writeln("getLpuartClock() = ", Sim::getLpuartClock());
   Sim::setLpuartClock(SimLpuartClockSource_McgIrClk);
   console.writeln("getLpuartClock() = ", Sim::getLpuartClock());
   Sim::setLpuartClock(SimLpuartClockSource_OscerClk);
   console.writeln("getLpuartClock() = ", Sim::getLpuartClock());
   Sim::setLpuartClock(SimLpuartClockSource_PeripheralClk);
   console.writeln("getLpuartClock() = ", Sim::getLpuartClock());

   Sim::ClockInit clockInit {
      SimLpuartClockSource_Disabled,
      Sim::DefaultSopt2Values[0],
   };
   clockInit.configure();

   //************ SOPT4 **************/
//   FtmClkin0::setInput();

   Sim::setFtm0Flt0(SimFtm0Flt0_Cmp0);
   Sim::setFtm0Flt0(SimFtm0Flt0_Ftm0Fault0);

   Sim::setFtm0Flt1(SimFtm0Flt1_Cmp1);
   Sim::setFtm0Flt1(SimFtm0Flt1_Ftm0Fault1);

   Sim::setFtm1Flt0(SimFtm1Flt0_Cmp0);
   Sim::setFtm1Flt0(SimFtm1Flt0_Ftm1Fault0);

   Sim::setFtm2Flt0(SimFtm2Flt0_Cmp0);
   Sim::setFtm2Flt0(SimFtm2Flt0_Ftm2Fault0);

   Sim::setFtm3Flt0(SimFtm3Flt0_Cmp0);
   Sim::setFtm3Flt0(SimFtm3Flt0_Ftm3Fault0);

   Sim::setFtm1Ch0Src(SimFtm1Ch0Src_IcPin);
   Sim::setFtm1Ch0Src(SimFtm1Ch0Src_Cmp0);
   Sim::setFtm1Ch0Src(SimFtm1Ch0Src_Cmp1);
   Sim::setFtm1Ch0Src(SimFtm1Ch0Src_UsbSof);

   Sim::setFtm2Ch0Src(SimFtm2Ch0Src_IcPin);
   Sim::setFtm2Ch0Src(SimFtm2Ch0Src_Cmp0);
   Sim::setFtm2Ch0Src(SimFtm2Ch0Src_Cmp1);

   Sim::setFtm2Ch1Src(SimFtm2Ch1Src_IcPin);
   Sim::setFtm2Ch1Src(SimFtm2Ch1Src_Ftm2Ch1_Ftm2Ch2_Ftm1Ch1);

   Sim::setFtm0ClkSel(SimFtm0ClkSel_FtmClkin0);
   Sim::setFtm0ClkSel(SimFtm0ClkSel_FtmClkin1);

   Sim::setFtm1ClkSel(SimFtm1ClkSel_FtmClkin0);
   Sim::setFtm1ClkSel(SimFtm1ClkSel_FtmClkin1);

   Sim::setFtm2ClkSel(SimFtm2ClkSel_FtmClkin0);
   Sim::setFtm2ClkSel(SimFtm2ClkSel_FtmClkin1);

   Sim::setFtm3ClkSel(SimFtm3ClkSel_FtmClkin0);
   Sim::setFtm3ClkSel(SimFtm3ClkSel_FtmClkin1);

   Sim::setFtm0Trg0Src(SimFtm0Trg0Src_Cmp0);
   Sim::setFtm0Trg0Src(SimFtm0Trg0Src_Ftm1);

   Sim::setFtm0Trg1Src(SimFtm0Trg1Src_Ftm2);
   Sim::setFtm0Trg1Src(SimFtm0Trg1Src_PdbTrigger1);

   Sim::setFtm3Trg0Src(SimFtm3Trg0Src_Ftm1);

   Sim::setFtm3Trg1Src(SimFtm3Trg1Src_Ftm2);

   //************ SOPT5 **************/
   Sim::setUart0TxSrc(SimUart0TxSrc_ModulatedByFtm1Ch0);
   Sim::setUart0TxSrc(SimUart0TxSrc_ModulatedByFtm2Ch0);
   Sim::setUart0TxSrc(SimUart0TxSrc_Direct);

   Sim::setUart0RxSrc(SimUart0RxSrc_Cmp0);
   Sim::setUart0RxSrc(SimUart0RxSrc_Cmp1);
   Sim::setUart0RxSrc(SimUart0RxSrc_RxPin);

   Sim::setUart1TxSrc(SimUart1TxSrc_ModulatedByFtm1Ch0);
   Sim::setUart1TxSrc(SimUart1TxSrc_ModulatedByFtm2Ch0);
   Sim::setUart1TxSrc(SimUart1TxSrc_Direct);

   Sim::setUart1RxSrc(SimUart1RxSrc_Cmp0);
   Sim::setUart1RxSrc(SimUart1RxSrc_Cmp1);
   Sim::setUart1RxSrc(SimUart1RxSrc_RxPin);

   Sim::setLpuart0RxSrc(SimLpuart0RxSrc_Cmp0);
   Sim::setLpuart0RxSrc(SimLpuart0RxSrc_Cmp0);
   Sim::setLpuart0RxSrc(SimLpuart0RxSrc_Cmp1);
   Sim::setLpuart0RxSrc(SimLpuart0RxSrc_RxPin);

   static const Sim::Lpuart0Init lpuart0Init {
      SimLpuart0RxSrc_Cmp0,
   };
   lpuart0Init.configure();

   static const Sim::Uart0Init uart0Init {
      SimUart0TxSrc_Direct, SimUart0RxSrc_Cmp0,
   };
   uart0Init.configure();

   static const Sim::Uart1Init uart1Init {
      SimUart1TxSrc_Direct, SimUart1RxSrc_Cmp0,
   };
   uart1Init.configure();

   //************ SOPT7 **************/
   Sim::setAdc0Triggers(SimAdc0TriggerMode_Pdb);
   Sim::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0TriggerSrc_Cmp0);
   Sim::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0TriggerSrc_Lptmr);
   Sim::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_1, SimAdc0TriggerSrc_RtcAlarm);
   Sim::setAdc0Triggers(SimAdc0TriggerMode_Alt_PreTrigger_1, SimAdc0TriggerSrc_RtcSeconds);

   Sim::setAdc1Triggers(SimAdc1TriggerMode_Pdb);
   Sim::setAdc1Triggers(SimAdc1TriggerMode_Alt_PreTrigger_0, SimAdc1TriggerSrc_Cmp0);
   Sim::setAdc1Triggers(SimAdc1TriggerMode_Alt_PreTrigger_0, SimAdc1TriggerSrc_Lptmr);
   Sim::setAdc1Triggers(SimAdc1TriggerMode_Alt_PreTrigger_1, SimAdc1TriggerSrc_RtcAlarm);
   Sim::setAdc1Triggers(SimAdc1TriggerMode_Alt_PreTrigger_1, SimAdc1TriggerSrc_RtcSeconds);

   Sim::Adc0Init adc0Init {
      SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0TriggerSrc_Cmp0,
   };
   adc0Init.configure();

   //************ SOPT8 **************/
   Sim::setFtm0Ch0OutputSrc(SimFtm0Ch0OutputSrc_Direct);
   Sim::setFtm0Ch0OutputSrc(SimFtm0Ch0OutputSrc_ModulatedByFtm1Ch1);

   Sim::setFtm0Ch1OutputSrc(SimFtm0Ch1OutputSrc_Direct);
   Sim::setFtm0Ch1OutputSrc(SimFtm0Ch1OutputSrc_ModulatedByFtm1Ch1);

   Sim::setFtm0Ch2OutputSrc(SimFtm0Ch2OutputSrc_Direct);
   Sim::setFtm0Ch2OutputSrc(SimFtm0Ch2OutputSrc_ModulatedByFtm1Ch1);

   Sim::setFtm0Ch3OutputSrc(SimFtm0Ch3OutputSrc_Direct);
   Sim::setFtm0Ch3OutputSrc(SimFtm0Ch3OutputSrc_ModulatedByFtm1Ch1);

   Sim::setFtm0Ch4OutputSrc(SimFtm0Ch4OutputSrc_Direct);
   Sim::setFtm0Ch4OutputSrc(SimFtm0Ch4OutputSrc_ModulatedByFtm1Ch1);

   Sim::setFtm0Ch5OutputSrc(SimFtm0Ch5OutputSrc_Direct);
   Sim::setFtm0Ch5OutputSrc(SimFtm0Ch5OutputSrc_ModulatedByFtm1Ch1);

   Sim::setFtm0Ch6OutputSrc(SimFtm0Ch6OutputSrc_Direct);
   Sim::setFtm0Ch6OutputSrc(SimFtm0Ch6OutputSrc_ModulatedByFtm1Ch1);

   Sim::setFtm0Ch7OutputSrc(SimFtm0Ch7OutputSrc_Direct);
   Sim::setFtm0Ch7OutputSrc(SimFtm0Ch7OutputSrc_ModulatedByFtm1Ch1);

   Sim::setFtm3Ch0OutputSrc(SimFtm3Ch0OutputSrc_Direct);
   Sim::setFtm3Ch0OutputSrc(SimFtm3Ch0OutputSrc_ModulatedByFtm2Ch1);

   Sim::setFtm3Ch1OutputSrc(SimFtm3Ch1OutputSrc_Direct);
   Sim::setFtm3Ch1OutputSrc(SimFtm3Ch1OutputSrc_ModulatedByFtm2Ch1);

   Sim::setFtm3Ch2OutputSrc(SimFtm3Ch2OutputSrc_Direct);
   Sim::setFtm3Ch2OutputSrc(SimFtm3Ch2OutputSrc_ModulatedByFtm2Ch1);

   Sim::setFtm3Ch3OutputSrc(SimFtm3Ch3OutputSrc_Direct);
   Sim::setFtm3Ch3OutputSrc(SimFtm3Ch3OutputSrc_ModulatedByFtm2Ch1);

   Sim::setFtm3Ch4OutputSrc(SimFtm3Ch4OutputSrc_Direct);
   Sim::setFtm3Ch4OutputSrc(SimFtm3Ch4OutputSrc_ModulatedByFtm2Ch1);

   Sim::setFtm3Ch5OutputSrc(SimFtm3Ch5OutputSrc_Direct);
   Sim::setFtm3Ch5OutputSrc(SimFtm3Ch5OutputSrc_ModulatedByFtm2Ch1);

   Sim::setFtm3Ch6OutputSrc(SimFtm3Ch6OutputSrc_Direct);
   Sim::setFtm3Ch6OutputSrc(SimFtm3Ch6OutputSrc_ModulatedByFtm2Ch1);

   Sim::setFtm3Ch7OutputSrc(SimFtm3Ch7OutputSrc_Direct);
   Sim::setFtm3Ch7OutputSrc(SimFtm3Ch7OutputSrc_ModulatedByFtm2Ch1);

   Sim::setFtmSyncBits(SimFtmSync_Ftm0|SimFtmSync_Ftm1|SimFtmSync_Ftm2);
   Sim::clearFtmSyncBits(SimFtmSync_Ftm0);
   Sim::clearAllFtmSyncBits();


}

void testSMC() {

   Smc::defaultConfigure();

   //************ SMC **************/
   static constexpr Smc::Init smcInit1 {
      // Allow all power modes
      SmcAllowVeryLowPower_Enabled, SmcAllowLowLeakageStop_Enabled, SmcAllowVeryLowLeakageStop_Enabled,
      // Partial Stop mode to use
      SmcPartialStopMode_Partial2,
      // (Very) Low leakage stop mode to use
      SmcLowLeakageStopMode_VLLS3,
      // Allow brown-out detection in VLLS0
      SmcPowerOnResetInVlls0_Enabled,
      // Stop mode to enter on Deep-sleep
      SmcStopMode_NormalStop,
      // Value to build upon - must be last in parameter list
      Smc::DefaultInitValue,
   };

   static constexpr Smc::Init smcInit {
      // Partial Stop mode to use
      SmcPartialStopMode_Partial1,
      smcInit1
   };

   console.writeln("DefaultValue.pmprot = ", Smc::DefaultInitValue.pmprot, Radix_2, ", pmctrl = ", Smc::DefaultInitValue.pmctrl, Radix_2, ", stopctrl = ", Smc::DefaultInitValue.stopctrl, Radix_2 );
   console.writeln("smcInit.pmprot      = ", smcInit.pmprot, Radix_2, ", pmctrl = ", smcInit.pmctrl, Radix_2, ", stopctrl = ", smcInit.stopctrl, Radix_2 );
   console.writeln("smcInit1.pmprot     = ", smcInit1.pmprot, Radix_2, ", pmctrl = ", smcInit1.pmctrl, Radix_2, ", stopctrl = ", smcInit1.stopctrl, Radix_2 );

   Smc::DefaultInitValue.initialise();

   Smc::Init currentSmcSettings;
   currentSmcSettings.readConfig();
   currentSmcSettings.setOptions();

   Smc::Init{
      // Stop mode to enter on Deep-sleep
      SmcStopMode_NormalStop,
      // The value below is generated from Configure.usbdmProject
      Smc::DefaultInitValue}.setOptions();

   report();
   Smc::enterRunMode(ClockConfig_VLPR_BLPE_4MHz);
   report();
   Smc::enterRunMode(ClockConfig_RUN_PEE_80MHz);
   report();
   Smc::enterRunMode(ClockConfig_HSRUN_PEE_120MHz);
   report();
   Smc::enterRunMode(ClockConfig_RUN_PEE_80MHz);
   report();

   smcInit.initialise();
   smcInit.setOptions();

   Smc::enterStopMode(smcInit);

   Smc::enterPowerMode(SmcPowerMode_PartialSTOP1);
//   Smc::enterStopMode(SmcStopMode_LowLeakageStop);

   Smc::setSleepOnExit(SmcSleepOnExit_Enabled);
   Smc::setSleepOnExit(SmcSleepOnExit_Disabled);

   Smc::enableAllPowerModes();
   Smc::enablePowerModes(SmcAllowHighSpeedRun_Enabled, SmcAllowVeryLowPower_Enabled, SmcAllowLowLeakageStop_Enabled, SmcAllowVeryLowLeakageStop_Enabled);

   Smc::setStopMode(SmcStopMode_LowLeakageStop);
   Smc::setStopMode(SmcStopMode_NormalStop);
   Smc::setStopMode(SmcStopMode_VeryLowLeakageStop);
   Smc::setStopMode(SmcStopMode_VeryLowPowerStop);

   Smc::setStopOptions(SmcPartialStopMode_Partial1, SmcLowLeakageStopMode_VLLS2, SmcPowerOnResetInVlls0_Enabled);
   Smc::setPartialStopMode(SmcPartialStopMode_Normal);
   Smc::setPartialStopMode(SmcPartialStopMode_Partial1);
   Smc::setPartialStopMode(SmcPartialStopMode_Partial2);
   Smc::setLowLeakageStopMode(SmcLowLeakageStopMode_VLLS0);
   Smc::setLowLeakageStopMode(SmcLowLeakageStopMode_VLLS1);
   Smc::setLowLeakageStopMode(SmcLowLeakageStopMode_VLLS2);
   Smc::setLowLeakageStopMode(SmcLowLeakageStopMode_VLLS3);
   Smc::setPowerOnResetInVLLS0(SmcPowerOnResetInVlls0_Enabled);
   Smc::setPowerOnResetInVLLS0(SmcPowerOnResetInVlls0_Disabled);
//   Smc::setRam2PoweredInLLS2_VLLS2(SmcLowLeakageRam2_Enabled);
//   Smc::setRam2PoweredInLLS2_VLLS2(SmcLowLeakageRam2_Disabled);
//   Smc::setLpoPoweredInLLS_VLLS(SmcLpoInLowLeakage_Enabled);
//   Smc::setLpoPoweredInLLS_VLLS(SmcLpoInLowLeakage_Disabled);
//   Smc::setExitVeryLowPowerOnInterrupt(smcExitVeryLowPowerOnInt);

   console.writeln("Smc::getStatus() = ", Smc::getSmcStatusName(Smc::getStatus()));
   console.writeln("Smc::getStatus() = ", Smc::getSmcStatusName());

}

void testUSB() {

   //************ USB0 **************/
   Usb0Info::enableClock();

   Usb0Info::enableIrc48m(UsbIrc48mClockEnable_Disabled);
   Usb0Info::enableIrc48m(UsbIrc48mClockEnable_Peripheral);
   Usb0Info::enableIrc48m(UsbIrc48mClockEnable_PeripheralAndUsb);

   Usb0Info::setIrc48mTracking(UsbIrc48mClockTrackingMode_NotTracking);
   Usb0Info::setIrc48mTracking(UsbIrc48mClockTrackingMode_AlwaysFineTracking, UsbIrc48mClockResetTrim_Keep);
   Usb0Info::setIrc48mTracking(UsbIrc48mClockTrackingMode_RoughAndFineTracking, UsbIrc48mClockResetTrim_Restart);

   Sim::setPeripheralClock(SimPeripheralClockSource_Irc48mClk);
   Sim::setUsbFullSpeedClock(SimUsbFullSpeedClockSource_PeripheralClk);

   //************ USBPHY **************/
//   Usbphy1::initialise();
}

void testVREF() {
   Vref::configure(VrefBuffer_HighPower, VrefReg_Enabled, VrefIcomp_Enabled, VrefChop_Enabled);
   Vref::configure(Vref::DefaultInitValue);

   Vref::defaultConfigure();

   static const Vref::Init vrefInit{
      VrefEnable_Enabled ,    // Internal Voltage Reference enable
      VrefChop_Disabled ,     // Chop oscillator enable
      VrefReg_Enabled ,       // Regulator enable
      VrefIcomp_Enabled ,     // Second order curvature compensation enable
      VrefBuffer_HighPower,   // Buffer Mode selection
   };

   Vref::configure(vrefInit);

   static const Vref::Init vrefInit2{
      VrefEnable_Enabled ,    // Internal Voltage Reference enable
      VrefChop_Disabled ,     // Chop oscillator enable
//      VrefReg_Enabled ,      // Regulator enable
      VrefIcomp_Enabled ,    // Second order curvature compensation enable
      VrefBuffer_HighPower,  // Buffer Mode selection
   };

   Vref::configure(vrefInit2);
}


void wdogCallback() {
   __asm__("nop");
}

void testWDOG() {

   console.writeln("Size of Wdog::Init = ", sizeof(Wdog::Init), " bytes");

   Wdog::defaultConfigure();
   Wdog::configure(Wdog::DefaultInitValue);

   static const Wdog::Init wdogInit {
      WdogEnable_Enabled,          // Enabled
      WdogTestMode_Disabled ,       // Test mode disable
      WdogEnableInWait_Disabled ,   // Enable watchdog in WAIT mode
      WdogEnableInStop_Disabled ,   // Enable watchdog in STOP mode
      WdogEnableInDebug_Disabled ,  // Enable watchdog in DEBUG mode
      WdogAllowUpdate_Enabled ,     // Allow watchdog update
      WdogWindow_Disabled ,         // Enable watchdog windowing mode
      WdogIntBeforeReset_Enabled ,  // Enable interrupt before reset
      WdogClock_LpoClk ,            // Watchdog clock source
      WdogEnable_Disabled ,         // Watchdog enable
      NvicPriority_Normal,          // IRQ level for this peripheral
//      wdogCallback,                 // Call-back
      // Using ticks
      WdogPrescale_Direct,
      1000_ticks, 0_ticks,
      // Using seconds
//      1_s , 0_s ,                   // Watchdog Timeout and Window values
      Wdog::DefaultInitValue,
   };

   console.writeln("Wdog::configure(wdogInit), rc = ", getErrorMessage(Wdog::configure(wdogInit)));


   for(;;) {
      wait(5_ms);
      Wdog::refresh(WdogRefresh_1, WdogRefresh_2);
   }
}

void runTests() {

   testADC();
   testFMC();
   testFTM();
   testGPIO();
   testLLWU();
   testLPTMR();
   testMCG();
   testMCM();
   testOSC();
   testPIT();
   testSIM();
   testSMC();
   testUSB();
   testWDOG();
}

/**
 *
 * @return
 */
int main() {
   console.writeln("SystemBusClock - ", SystemBusClock);
   runTests();

//   testADC();
//   testVREF();
//   for(;;) {
//      Wdog::refresh(WdogRefresh_1, WdogRefresh_2);
//      __asm__("nop");
//   }
//   testWDOG();

//   testPIT();
//   testLPTMR();
   testFTM();

//   testMCG();

//   testLPTMR();

   flash();
   return 0;
}
