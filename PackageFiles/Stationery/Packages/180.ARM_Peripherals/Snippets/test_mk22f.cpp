/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <time.h>

#include "hardware.h"
#include "adc.h"
#include "cmp.h"
//#include "cmt.h"
#include "crc.h"
#include "dac.h"
#include "dma.h"
#include "ewm.h"
#include "ftm.h"
#include "fmc.h"
#include "llwu.h"
#include "lptmr.h"
#include "mcg.h"
#include "mcm.h"
#include "osc.h"
#include "pit.h"
#include "pdb.h"
#include "pmc.h"
#include "rcm.h"
#include "rnga.h"
#include "sim.h"
#include "smc.h"
#include "spi.h"
#include "vref.h"
#include "wdog.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

#ifdef USBDM_ADC1_AVAILABLE
static constexpr AdcResolution ADC_RESOLUTION = AdcResolution_10bit_se;

void adcCallback(uint32_t result, int channel) {
   TestLed::toggle();
   console.writeln("ADC result ch(", channel, ") = ",
            (result*3.3)/AdcTest::getSingleEndedMaximum(ADC_RESOLUTION), " volts");
}

void testAdc() {

   TestLed::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);

   AdcTestChannel::setInput();

   static const AdcTestChannel::OwningAdc::Init adcInit {
        AdcClockSource_Bus ,     // ADC Clock Source
        ADC_RESOLUTION ,         // ADC Resolution
        AdcPower_Normal ,        // Low-Power Configuration
        AdcClockRange_Normal ,   // High-Speed Configuration
        AdcAsyncClock_Disabled , // Asynchronous Clock Output Enable
        AdcRefSel_VrefHL ,       // Voltage Reference Selection
        AdcDma_Disabled ,        // DMA Enable
        AdcMuxsel_B ,            // Selects between A/B multiplexor inputs on some ADC channels
        AdcTrigger_Software ,    // Conversion Trigger Select
        AdcAveraging_32 ,        // Hardware Average Select
        AdcContinuous_Disabled , // Selects between single and continuous conversion
        NvicPriority_Normal ,    // IRQ level for this peripheral
        adcCallback,             // Call-back to execute on completion
        // These 2/3 parameters must appear in this order
        AdcCompare_Disabled ,    // Compare function
        0 ,                      // ADC CV low value
        0,                       // ADC CV high value (May be omitted)
        AdcPretrigger_0, AdcChannelNum_11,    AdcAction_Disabled,   // Settings for ADC hardware trigger #0
        AdcPretrigger_1, AdcChannelNum_Diff0, AdcAction_Enabled,    // Settings for ADC hardware trigger #1
        Adc1::DefaultInitValue,
   };
   AdcTestChannel::OwningAdc::configure(adcInit);

   for(;;) {
      TestLed::toggle();
      console.writeln("ADC = ", AdcTestChannel::readAnalogue());
   }

   AdcTest::configure(adcInit);
   AdcTest::defaultConfigure();
   AdcTest::configure(AdcTest::DefaultInitValue);
   AdcTest::calibrate();

   AdcTestChannel::startConversion(AdcAction_Disabled);
   for(;;) {
      __asm__("nop");
   }

   AdcTestChannel::setInput();
   console.writeln("ADC = ", AdcTestChannel::readAnalogue());

   console.writeln("ADC  8b_se res   = ", AdcTestChannel::OwningAdc::getSingleEndedMaximum(AdcResolution_8bit_se));
   console.writeln("ADC 10b_se res   = ", AdcTestChannel::OwningAdc::getSingleEndedMaximum(AdcResolution_10bit_se));
   console.writeln("ADC 12b_se res   = ", AdcTestChannel::OwningAdc::getSingleEndedMaximum(AdcResolution_12bit_se));
   console.writeln("ADC 16b_se res   = ", AdcTestChannel::OwningAdc::getSingleEndedMaximum(AdcResolution_16bit_se));

   console.writeln("ADC  9b_diff res = ", AdcTestChannel::OwningAdc::getDifferentialMaximum(AdcResolution_9bit_diff));
   console.writeln("ADC 11b_diff res = ", AdcTestChannel::OwningAdc::getDifferentialMaximum(AdcResolution_11bit_diff));
   console.writeln("ADC 13b_diff res = ", AdcTestChannel::OwningAdc::getDifferentialMaximum(AdcResolution_13bit_diff));
   console.writeln("ADC 16b_diff res = ", AdcTestChannel::OwningAdc::getDifferentialMaximum(AdcResolution_16bit_diff));

   console.writeln("getAdcClock(AdcClockSource_Asynch)   = ", AdcTest::getAdcClock(AdcClockSource_Asynch));
   console.writeln("getAdcClock(AdcClockSource_Bus)      = ", AdcTest::getAdcClock(AdcClockSource_Bus));
   console.writeln("getAdcClock(AdcClockSource_Busdiv2)  = ", AdcTest::getAdcClock(AdcClockSource_Irc48mClk));
   console.writeln("getAdcClock(AdcClockSource_OscerClk) = ", AdcTest::getAdcClock(AdcClockSource_OscerClk));

   LightSensor_ADC1::OwningAdc::configure(AdcResolution_8bit_se);
   LightSensor_ADC1::setInput();

   //************ EXTERNAL **************/
   AdcTest::enableComparison(AdcCompare_InsideRangeExclusive, 100, 200);

}

#endif

#ifdef USBDM_CMP0_AVAILABLE
void cmpCallback(const CmpStatus &status) {
   switch (status.event) {
      default:
      case CmpEventId_None:
         console.writeln("-");
         break;
      case CmpEventId_RisingEdge:
         console.writeln("Rising");
         break;
      case CmpEventId_FallingEdge:
         console.writeln("Falling");
         break;
      case CmpEventId_BothEdges:
         console.writeln("Both");
         break;
   }
   console.writeln("CMP out = ", status.state);
}

void testCmp() {

   Cmp0::setOutput();

   Cmp0::configure(Cmp0::DefaultInitValue);

   static constexpr Cmp0::Init cmpInit1 {
      CmpEnable_Enabled ,          // Comparator Enable - Comparator is enabled
      CmpMode_Direct ,             // Operating mode - Direct
      CmpTrigger_Enabled ,         // Trigger Mode Enable - Trigger mode is enabled
      CmpPower_HighSpeed ,         // Power Mode Select - High-Speed Comparison mode
      CmpPolarity_Inverted ,       // Comparator Invert - Inverted
      CmpOutput_Direct ,           // Comparator output pin source - Direct (unfiltered)
      CmpHysteresis_Level_2 ,      // Comparator hard block hysteresis control - Level 2
      CmpDma_Disabled ,            // DMA Enable Control - Disabled
      CmpEvent_OnFalling ,         // Action on transition - Falling edge
      cmpCallback,                 // Call-back to execute on event

      // Filter settings - must be in this order
      CmpFilterSamples_4 ,         // Filter Sample Count - 4 sample must agree
      5_us ,                       // Filter Sample Period in seconds

      // DAC Settings - must be in this order
      CmpDacEnable_Enabled ,       // DAC Enable - Enabled
      CmpDacrefSel_Vdd ,           // DAC Reference Voltage Select - Vin2 (Vdd)
      31 ,                         // DAC level

      // Inputs
      cmp0Input_D7.plusPin ,     // Plus Input Mux Control
      Cmp0Input_D21::minusPin,   // Minus Input Mux Control
   };
   Cmp0::configure(cmpInit1);

   Cmp0::defaultConfigure();
   Cmp0::configure(Cmp0::DefaultInitValue);

   static constexpr Cmp0::Init cmpInit2 {
      CmpEnable_Enabled ,          // Comparator Enable - Comparator is enabled
      CmpMode_Direct ,             // Operating mode - Direct
      CmpTrigger_Enabled ,         // Trigger Mode Enable - Trigger mode is enabled
      CmpPower_HighSpeed ,         // Power Mode Select - High-Speed Comparison mode
      CmpPolarity_Inverted ,       // Comparator Invert - Inverted
      CmpOutput_Direct ,           // Comparator output pin source - Direct (unfiltered)
      CmpHysteresis_Level_2 ,      // Comparator hard block hysteresis control - Level 2
      CmpDma_Disabled ,            // DMA Enable Control - Disabled
      CmpEvent_OnFalling ,         // Action on transition - Falling edge
      cmpCallback,                 // Call-back to execute on event

      // Filter settings - must be in this order
      CmpFilterSamples_4 ,         // Filter Sample Count - 4 sample must agree
      100_ticks ,                  // Filter Sample Period in ticks

      // DAC Settings - must be in this order
      CmpDacEnable_Enabled ,       // DAC Enable - Enabled
      CmpDacrefSel_Vdd ,           // DAC Reference Voltage Select - Vin2 (Vdd)
      31 ,                         // DAC level

      // Inputs
      cmp0Input_D7.plusPin ,     // Plus Input Mux Control
      Cmp0Input_D21::minusPin,   // Minus Input Mux Control
   };
   Cmp0::configure(cmpInit2);

   Cmp0::selectInputs(Cmp0InputPlus_Ptc6, Cmp0InputMinus_CmpDac);

   Cmp0::Pin<Cmp0InputMinus_CmpDac> xx;

   xx.setInput();

   Cmp0::selectInputs(xx, xx);

   using yy = Cmp0::Pin<Cmp0InputMinus_CmpDac>;

   yy::setInput();

   Cmp0::selectInputs(yy::plusPin, yy::minusPin);

   cmp0Input_D7.setInput();
   Cmp0Input_D21::setInput();
   Cmp0::selectInputs(cmp0Input_D7, Cmp0Input_D21::minusPin);
   Cmp0::selectInputs(Cmp0Input_D21::plusPin, cmp0Input_D7);
}
#endif // USBDM_CMP0_AVAILABLE

#ifdef USBDM_CMT_AVAILABLE

void cmtCallback() {

}

void testCmt() {
   static constexpr Cmt::Init cmtInit = {
      CmtMode_FreqShiftKeying ,           // Mode of operation - FreqShiftKeying
      CmtClockPrescaler_BusClockDivBy6 ,  // Primary Prescaler Divider - Bus clock / 6
      CmtIntermediatePrescaler_DivBy2 ,   // Intermediate frequency Prescaler - Intermediate frequency /2
      CmtOutput_ActiveHigh ,              // Output Control - Active-high
      CmtEndOfCycleAction_None ,          // End of Cycle Event handling - No Action
      CmtPrimaryCarrierHighTime(100) ,    // Primary Carrier High Time Data Value
      CmtPrimaryCarrierLowTime(200) ,     // Primary Carrier Low Time Data Value
      CmtSecondaryCarrierHighTime(300) ,  // Secondary Carrier High Time Data Value
      CmtSecondaryCarrierLowTime(400) ,   // Secondary Carrier Low Time Data Value
      CmtMarkPeriod(50) ,                 // Mark period
      CmtSpacePeriod(75),                 // Space period

      NvicPriority_VeryHigh,              // Interrupt priority level
      cmtCallback,                        // Event callback
   };
   Cmt::configure(cmtInit);
   Cmt::configure(Cmt::DefaultInitValue);
   Cmt::defaultConfigure();
}
#endif //  USBDM_CMT_AVAILABLE

#ifdef USBDM_CRC0_AVAILABLE

void testCrc() {

   static const uint8_t data[] = {1,2,3,4,5,6,7,8};
   static constexpr Crc0::Init InitValue = {
      CrcPolynomial(0x1234) , // CRC Polynomial
      CrcSeed(0xFFFF) , // CRC Seed
      CrcWriteTranspose_NoTransposition , // Type of Transpose For Writes - No transposition
      CrcReadTranspose_NoTransposition , // Type of Transpose For Read - No transposition
      CrcReadComplement_Normal , // Complement Read Of CRC Data Register - No inversion
      CrcWidth_16BitCrc,  // Width of CRC protocol - 16-bit CRC
   };
   Crc0::configure(InitValue);
   Crc0::calculateCrc(data);

   Crc0::defaultConfigure();
   Crc0::configure(Crc0::DefaultInitValue);

   Crc0::configure_Crc32();
   Crc0::writeData16(0x1234);
   Crc0::calculateCrc(data);
}
#endif // USBDM_CRC0_AVAILABLE

#ifdef USBDM_DAC0_AVAILABLE
void dacCallback(const uint8_t status) {
   if (status & DacReadPtrTopFlag_Reached) {

   }
}

void testDAC() {

   static const Dac0::Init dacInit {
      DacReferenceSelect_Vdda ,       // DAC Reference Select - VddA
      DacTriggerSelect_Software ,     // DAC Trigger Select - Software trigger
      DacPower_High ,                 // DAC Low Power Control - High-Power mode
      DacWatermarkAction_None,        // DAC Buffer Watermark Interrupt Enable - Interrupt is disabled
      DacReadPtrTopAction_None ,      // DAC Buffer Read Pointer Top Flag Interrupt Enable - Interrupt is disabled
      DacReadPtrBottomAction_None ,   // DAC Buffer Read Pointer Bottom Flag Interrupt Enable - Interrupt is disabled
      DacDma_Enabled ,                // DMA Enable Select - DMA is disabled
      DacWaterMark_Normal_1 ,         // Buffer Watermark Select - Normal mode: 1 free entry
      DacBufferMode_Normal ,          // Buffer operation mode - Normal
      DacBufferUpperLimit_Max,        // DAC Buffer Upper Limit - max entries
      dacCallback,                    // Interrupt call-back
   };
   Dac0::configure(dacInit);
   Dac0::defaultConfigure();
   Dac0::configure(Dac0::DefaultInitValue);
}
#endif //  USBDM_DAC0_AVAILABLE

#if defined(USBDM_DMAMUX0_AVAILABLE)
void testDma() {
   Dmamux0::Init dmamuxInit[] {
      {
      DmaChannelNum_0,

      DmamuxMode_Continuous , // DMA Channel Mode - continuous
      DmamuxSlot_Disabled,  // Mapping of DMA slot to DMA channel - Disabled
      },
   };
   Dmamux0::configure(dmamuxInit);
}
#endif

#ifdef USBDM_DMA0_AVAILABLE

#endif //  USBDM_DMA0_AVAILABLE

#ifdef USBDM_EWM_AVAILABLE
void ewmCallback() {

}

void testEwm() {
   static const Ewm::Init ewmInit {
      EwmInterrupt_Enabled ,  // Interrupt Enable - Interrupt enabled
      EwmInputPin_Disabled ,  // Input pin control - Input disabled
      EwmMode_Enabled ,       // EWM enable - Disabled
#ifdef EWM_CLKPRESCALER_CLK_DIV
      EwmClockPrescaler(10) , // LPO Clock prescaler
#endif
      100_ticks ,             // Minimum service time
      254_ticks,              // Maximum service time

      ewmCallback,
      NvicPriority_Normal,
   };

   Ewm::configure(ewmInit);
   Ewm::configure(ewmInit2);

   Ewm::configure(Ewm::DefaultInitValue);
   Ewm::writeKeys(EwmService_First, EwmService_Second);
   Ewm::setInput(PinPull_Down, PinAction_None, PinFilter_None);
   Ewm::setInputPin(EwmInputPin_ActiveHigh);


}
#endif

#ifdef USBDM_FMC_AVAILABLE

void testFMC() {

   //************ FMC **************/
   __asm__("nop");

   // Shared settings
   Fmc::setPrefetch(1, FmcPrefetch_Disabled);
   Fmc::setProtection(2, FmcAccessProtection_ReadAndWriteAccesses);
   Fmc::setCacheWayLock(0, FmcCacheWayLock_CacheWayIsUnlocked);
   Fmc::cacheWayInvalidate(FmcWayInvalidate_AllWays);
   Fmc::speculationBufferInvalidate();
   Fmc::setReplacementPolicy(FmcReplacementPolicy_LruAllWays);

   // Bank0 specific
   Fmc::setFlashBank0Cache(FmcFlashCache_Disabled);
   Fmc::setFlashBank0Cache(FmcFlashCache_DataOnly);
   Fmc::setFlashBank0Cache(FmcFlashCache_InstructionsOnly);
   Fmc::setFlashBank0Cache(FmcFlashCache_InstructionsAndData);

   Fmc::setFlashBank0Speculation(FmcFlashSpeculation_Disabled);
   Fmc::setFlashBank0Speculation(FmcFlashSpeculation_DataOnly);
   Fmc::setFlashBank0Speculation(FmcFlashSpeculation_InstructionsOnly);
   Fmc::setFlashBank0Speculation(FmcFlashSpeculation_InstructionsAndData);

   Fmc::setFlashBank0PageBuffer(FmcPageBuffer_Disabled);
   Fmc::setFlashBank0PageBuffer(FmcPageBuffer_Enabled);

   static constexpr Fmc::FlashBank0Init flashBank0Init {
      FmcFlashCache_InstructionsOnly,
      FmcFlashSpeculation_InstructionsOnly,
      FmcPageBuffer_Enabled,
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
#endif // USBDM_FMC_AVAILABLE

#ifdef USBDM_FTM0_AVAILABLE
void timerChannelCallback(uint8_t mask) {
   (void) mask;
   TestLed::toggle();
}

void timerCallback() {
   TestLed::toggle();
}

void testFTMInstances(FtmBase &test, FtmChannel &channel) {

   test.selectClock(FtmClockSource_FixedFrequencyClock,  FtmPrescale_DivBy1);
   test.setClockSource(FtmClockSource_FixedFrequencyClock);
   test.setPrescaler(FtmPrescale_DivBy32);
   test.stopCounter();
   test.setCountMode(FtmCountMode_LeftAligned);
   test.setCounterMaximumValue(10000_ticks);
   test.setHighTime(100_us, 3);
   test.setDeltaEventTime(100_ticks, 3);
   channel.setDeltaEventTime(100_ticks);
//   test.setPolarity(ActiveHigh, 0b001100);
   Ticks t;
   t = test.getCounterMaximumValue();
   console.writeln("t = ", t);
}

void testFtm() {

   TestLed::setOutput();

   SharedTimerChannel::setOutput();

   Digital_D0::setOutput();

   SharedTimerChannel::setChannelCallback(timerChannelCallback);
   SharedTimerChannel::setCallback(timerCallback);

   SharedTimerChannel::setOutput();
   static const SharedTimerChannel::OwningFtm::ChannelInit channelInit0 {
      FtmChannelNum_0,
      FtmCombinedChannelMode_CombinePositivePulse , // Channel Mode - Disabled
      FtmChannelAction_None , // Action on Channel Event - No action
      FtmChannelReset_Disabled , // Reset counter on channel IC event - Disabled
      1000_ticks,  // Output Compare Event time
   };
   static const SharedTimerChannel::OwningFtm::Channel<1>::ChannelInit channelInit1 {
      FtmChannelNum_1,
      FtmChannelMode_Disabled , // Channel Mode - Disabled
      FtmChannelAction_None , // Action on Channel Event - No action
      FtmChannelReset_Disabled , // Reset counter on channel IC event - Disabled
      2000_ticks,  // Output Compare Event time
   };
   console.writeln("configure(channelInit1), rc => ", getErrorMessage(SharedTimerChannel::OwningFtm::configure(channelInit0)));
   console.writeln("configure(channelInit2), rc => ", getErrorMessage(SharedTimerChannel::OwningFtm::configure(channelInit1)));

   SharedChannelTimer::Channel<0>::configure(channelInit0);
   SharedChannelTimer::Channel<1>::configure(channelInit1);

   static const SharedTimerChannel::OwningFtm::Init ftmInit {
      FtmCountMode_LeftAligned,
      FtmOverflowAction_Interrupt,
      timerCallback,
      Digital_D0::toggle,
      NvicPriority_VeryHigh,
      FtmClockSource_SystemClock,
      400_us,
      SharedTimerChannel::OwningFtm::DefaultInitValue,
   };
   console.writeln("configure(init), rc => ", getErrorMessage(SharedTimerChannel::OwningFtm::configure(ftmInit)));

   for(;;) {
      __asm__("nop");
   }

   SharedTimerChannel::OwningFtm::configure(SharedTimerChannel::OwningFtm::DefaultChannelInitValues[FtmChannelNum_3]);

   static const FtmQuadDecoder2::QuadInit quadInit {
      FtmQuadratureMode_Phase_AB_Mode , // Quadrature decoding mode - Phase-AB Mode
      FtmPhaseAPolarity_ActiveHigh ,    // Polarity of Phase A input - Active High
      FtmPhaseBPolarity_ActiveHigh ,    // Polarity of Phase B input - Active High
      FtmPhaseAFilter_10_Clocks ,        // Filtering on Phase A input - No Filter
      FtmPhaseBFilter_10_Clocks ,        // Filtering on Phase B input - No Filter
      FtmOverflowAction_Interrupt ,     // Overflow Interrupt - Interrupt Enabled
      NvicPriority_Normal ,             // IRQ level for this peripheral - Normal
      FtmPrescale_DivBy32,              // Clock prescaler - Divide by 32
      timerCallback,
      FtmQuadDecoder2::DefaultQuadInitValue,
   };

   FtmQuadDecoder2::configure(quadInit);

   FtmQuadDecoder2::configure(FtmPrescale_DivBy1, FtmQuadratureMode_Phase_AB_Mode);

   for(;;) {
      __asm__("nop");
   }

   SharedTimerChannel::OwningFtm::defaultConfigure();
   SharedTimerChannel::OwningFtm::enableNvicInterrupts();

   SharedTimerChannel::OwningFtm::configure(SharedTimerChannel::OwningFtm::DefaultInitValue);

   console.writeln("25 ms = ", SharedTimerChannel::OwningFtm::convertSecondsToTicks(25_ms));

   static const SharedTimerChannel::OwningFtm::Init init2 {
      FtmCountMode_CentreAligned,
      FtmOverflowAction_Interrupt,
      Digital_D0::toggle,
      NvicPriority_VeryHigh,
      FtmClockSource_SystemClock,
      FtmPrescale_DivBy32, 1000_ticks,
   };
   console.writeln("configure(init2), rc => ", getErrorMessage(SharedTimerChannel::OwningFtm::configure(init2)));

   //************ FTM **************/
   SharedTimerChannel::OwningFtm::configure(FtmCountMode_LeftAligned, FtmClockSource_SystemClock, FtmPrescale_DivBy16);

   SharedTimerChannel::OwningFtm::selectClock(FtmClockSource_FixedFrequencyClock,  FtmPrescale_DivBy1);
   SharedTimerChannel::OwningFtm::setClockSource(FtmClockSource_FixedFrequencyClock);
   SharedTimerChannel::OwningFtm::setPrescaler(FtmPrescale_DivBy32);
   SharedTimerChannel::OwningFtm::stopCounter();
   SharedTimerChannel::OwningFtm::setCounterMaximumValue(10000_ticks);
   Ticks t;
   t = SharedTimerChannel::OwningFtm::getCounterMaximumValue();
   console.writeln("t = ", t);

   SharedTimerChannel::OwningFtm::setPeriod(20_ms);
   SharedTimerChannel::setOutput(PinDriveStrength_High, PinDriveMode_PushPull, PinSlewRate_Slow);
   SharedTimerChannel::configure(FtmChannelMode_PwmHighTruePulses);
   SharedTimerChannel::setHighTime(5_ms);
   SharedTimerChannel::setDutyCycle(25);

   static const SharedTimerChannel::ChannelInit channelInit {
      FtmChannelNum_0,

      FtmChannelMode_Disabled , // Channel Mode - Disabled
      FtmChannelAction_None , // Action on Channel Event - No action
      0_ticks,  // Output Compare Event time in ticks
   };
   SharedTimerChannel::OwningFtm::configure(channelInit);
   SharedTimerChannel::configure(channelInit);

   SharedTimerChannel::defaultConfigure();
   SharedTimerChannel::configure(SharedTimerChannel::OwningFtm::DefaultChannelInitValues[0]);

   SharedTimerChannel::configure(FtmChannelMode_OutputCompareToggle, FtmChannelAction_Interrupt);

   static const Ftm1Info::Init ftmInit1 {
      FtmCountMode_CentreAligned,
      FtmOverflowAction_Interrupt,
      FtmClockSource_SystemClock,
      100_us
   };
   IndividualChannelTimer::configure(ftmInit1);

   SharedChannelTimer ftm0;
   SharedChannelTimer::Channel<1> ftmChannel;
   ftm0.configure(FtmCountMode_LeftAligned, FtmClockSource_SystemClock, FtmPrescale_DivBy16);
   testFTMInstances(ftm0,ftmChannel);
   SharedChannelTimer::configure(FtmCountMode_LeftAligned, FtmClockSource_SystemClock, FtmPrescale_DivBy1);
   SharedChannelTimer::Channel<0>::configure(FtmChannelMode_OutputCompareToggle, FtmChannelAction_None);
   SharedChannelTimer::setMaximumInterval(100_ms);
   SharedChannelTimer::setPeriod(100_ms);
   SharedChannelTimer::getTime();

   SharedChannelTimer::convertTicksToSeconds(100_ticks);

   console.writeln("Ticks = ", 100_ticks);

   Ticks a(10U), b;
   b = a;
   console.writeln("b = ", b);

   IndividualChannelTimer::setCallback(timerCallback);
   IndividualTimerChannel::setChannelCallback(timerChannelCallback);

   static const IndividualTimerChannel::OwningFtm::Init init3 {
      FtmCountMode_CentreAligned,
      FtmOverflowAction_Interrupt,
      timerCallback,
      NvicPriority_VeryHigh,
      FtmClockSource_SystemClock,
      FtmPrescale_DivBy32, 1000_ticks,
   };

   IndividualChannelTimer::configure(init3);

   static const IndividualTimerChannel::ChannelInit chInit3 {
      FtmChannelNum_0,

      FtmChannelMode_OutputCompare , // Channel Mode - Disabled
      FtmChannelAction_Interrupt ,   // Action on Channel Event - No action

      0_ticks,  // Output Compare Event time in ticks
   };

   IndividualChannelTimer::configure(chInit3);
}
#endif // USBDM_FTM0_AVAILABLE

#ifdef USBDM_GPIOA_AVAILABLE

void pinCallback(uint32_t status) {
   (void) status;
}

void testGpio() {

   //************ GPIO **************/

   static constexpr PcrInit pcrInit {
      PinPull_Up, PinAction_None, PinFilter_None,
      PinDriveStrength_High, PinDriveMode_OpenDrain, PinSlewRate_Slow,
   };
   TestLed::setOutput(pcrInit);
   TestSwitch::setInput(pcrInit);

   TestLed::setOutput(PinDriveStrength_High, PinDriveMode_OpenDrain, PinSlewRate_Slow);

   TestLed::setOutput(pcrInit);
   TestLed::setPCR(pcrInit);

   TestLed::setOutput();
   TestLed::setOutput(PinDriveStrength_High, PinDriveMode_OpenDrain, PinSlewRate_Slow);
   TestLed::setOutput(pcrInit);

   TestLed::setInput();
   TestLed::setInput(PinPull_Up, PinAction_None, PinFilter_None);
   TestLed::setInput(pcrInit);

   TestLed::setInOut();
   TestLed::setInOut(PinPull_Down, PinDriveStrength_High, PinDriveMode_PushPull, PinAction_None, PinFilter_Digital, PinSlewRate_Slow);
   TestLed::setInOut(pcrInit);

   TestLed::setInput(PinDriveMode_OpenDrain|PinPull_Down|PinDriveStrength_High|PinAction_IrqFalling|PinFilter_Passive|PinSlewRate_Fast);

   TestLed::setInOut(PinPull_Down, PinDriveStrength_High, PinDriveMode_OpenDrain, PinAction_None, PinFilter_None, PinSlewRate_Fast);

   TestSwitch::setInput(PinPull_Up, PinAction_IrqFalling, PinFilter_Passive);
   TestSwitch::setPinCallback(pinCallback);
   TestSwitch::enableNvicPinInterrupts(NvicPriority_Normal);

   TestLed::on();
   TestLed::off();
   TestLed::toggle();
   TestLed::write(false);
   TestLed::set();
   TestLed::clear();
   TestLed::writeBit(false);

   TestSwitch::setInput();

   TestField::write(0b110);
   TestField::bitRead();
   TestField::bitClear(0b001);
   TestField::bitSet(0b001);
   TestField::bitToggle(0b001);
   TestField::read();
}
#endif // USBDM_GPIOA_AVAILABLE

#ifdef USBDM_I2C0_AVAILABLE
void i2cCallback(ErrorCode errorCode) {
   console.writeln("Error = ", getErrorMessage(errorCode));
}

void testI2c() {

   static constexpr TestI2c::Init i2c0Init = {
         I2cAddressLength_7Bit, 0x70 ,      // Address Extension - 7-bit address, Slave Address
         400_kHz,                           // Bit rate in Hz
                                            // OR
   //      I2cFMult_Mul1, 100 ,               // Baud rate prescaler - mul = 1, Baud rate divider
         I2cBusRole_Controller ,            // Bus Role Select - Controller mode
         I2cWakeup_Disabled ,               // Wake-up Enable - Disabled
         I2cCallAddress_Disabled ,          // General Call Address Enable - Disabled
         I2cClockStretching_Disabled ,      // Slave Baud Rate Control - Slave rate follows master
         I2cAddressRange_Disabled, 0x74 ,   // Range Address Matching Enable - Range mode enabled, Range Slave Address
         I2cStopHoldOff_Disabled ,          // Stop Hold Enable - Stop hold-off is disabled
         I2cStartStopInterrupt_Disabled ,   // Bus Stop or Start Interrupt Enable - Interrupt disabled
         I2cFilter_3_ClockCycles ,          // Programmable Filter Factor - 3 cycles

         // SMB
//         I2cSmbFastAck_Disabled ,           // Fast NACK/ACK Enable - ACK/NAK on data byte
//         I2cSmbAlert_Disabled ,             // SMBus Alert Response Address Enable - SMBus alert matching is disabled
//         I2cSmbTimwoutClock_BusClockDiv64 , // Timeout Counter Clock Select - Bus clock / 64
//         I2cSmbTimoutInterrupt_Disabled ,   // SHTF2 Interrupt Enable - Interrupt disabled
//         I2cSmbAddress_Disabled , 0x23,     // Second I2C Address (SMB) Enable - Address 2 (SMB) disabled, SMBus Address
//         3000_ticks,                        // SCL low timeout value

         NvicPriority_Normal,
         i2cCallback,
      };

      TestI2c i2c0{};

      i2c0.defaultConfigure();
      i2c0.configure(I2c0Info::DefaultInitValue);
      i2c0.configure(i2c0Init);

}
#endif

#ifdef USBDM_LLWU_AVAILABLE

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

      // Reset
//      LlwuResetWakeup_Enabled, LlwuResetFilter_Enabled
   };
   reportLlwu(llwuInit);
   Llwu::configure(llwuInit);

   LlwuTest::setInput(PinPull_Up);

   Llwu::configureFilteredPinSource(LlwuFilterNum_1, LlwuPin_Switch2_llwu, LlwuFilterPinMode_EitherEdge);

//   Llwu::configureResetFilter(LlwuResetFilter_Enabled, LlwuResetWakeup_Enabled);
   Llwu::configure(Llwu::DefaultInitValue);
   Llwu::defaultConfigure();
}
#endif // LLWU

#ifdef USBDM_LPTMR0_AVAILABLE

void lptmrCallback() {

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
   Lptmr0::configureTimeIntervalMode(LptmrResetOnCompare_Enabled, LptmrInterrupt_Enabled, LptmrClockSel_Mcgirclk, 10_ticks, LptmrPrescale_DivBy_16);
   Lptmr0::configureTimeIntervalMode(LptmrResetOnCompare_Enabled, LptmrInterrupt_Enabled, 100_s, LptmrClockSel_Lpoclk);
   Lptmr0::configure(Lptmr0::DefaultPulseCountingModeInitValue);
   Lptmr0::configure(Lptmr0::DefaultTimeIntervalModeInitValue);

   Lptmr0::defaultConfigure();

}
#endif

#if defined(USBDM_MCG_AVAILABLE) && defined(USBDM_SMC_AVAILABLE)
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

void testMcg() {

   //************ MCG **************/
//   McgInfo::enableMcgIrClock(McgIrClkEn_Enabled);
//   McgInfo::enableMcgIrClock(McgIrClkEn_Disabled);
//   McgInfo::setInternalReferenceClock(McgIrClkSrc_Fast);
//   McgInfo::setInternalReferenceClock(McgIrClkSrc_Slow);

   Mcg::addClockChangeCallback(cb);
   Smc::enableAllPowerModes();
   Smc::enterRunMode(ClockConfig_VLPR_BLPI_4MHz);
   waitMS(1000);
   Smc::enterRunMode(ClockConfig_RUN_PEE_80MHz);
   waitMS(1000);
   Smc::enterRunMode(ClockConfig_HSRUN_PEE_120MHz);
   waitMS(1000);
   Smc::enterRunMode(ClockConfig_RUN_PEE_80MHz);
   waitMS(1000);
}
#endif

#ifdef USBDM_MCM_AVAILABLE

void mcmCallback() {

}
void testMCM(){

   //************ MCM **************/
   Mcm::setCrossbarArbitration(McmArbitration_FixedPriority);

   Mcm::enable();

#ifdef MCM_CPO_CPOACK_MASK
   // Compute mode
   Mcm::enterComputeMode(McmComputeOnlyMode_Enable);
   Mcm::enterComputeMode(McmComputeOnlyMode_EnableWithWakeOnInterrupt);
   Mcm::exitComputeMode();
#endif

//   Mcm::defaultConfigure();
//   Mcm::enableNvicInterrupts(NvicPriority_High);
//   Mcm::setCallback(callback);

#ifdef MCM_ISCR_FUFC_SHIFT
   // Floating point
   static constexpr Mcm::FloatingPointIrqInit floatingPointIrqs {
      McmFpuDenormalIrq_Select,
      McmFpuInvalidOperationIrq_Select,
      McmFpuDivideByZeroIrq_Select,
      Mcm::DefaultFloatingPointIrqInitValue
   };

   floatingPointIrqs.configure();
   floatingPointIrqs.enableInterrupts();
   floatingPointIrqs.disableInterrupts();

   Mcm::FloatingPointIrqInit {
      McmFpuDenormalIrq_Select,
      McmFpuUnderflowIrq_Select}.disableInterrupts();

   Mcm::DefaultFloatingPointIrqInitValue.configure();
   Mcm::disableMcmFpuDenormalIrq();

   Mcm::FloatingPointIrqInit {
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

   Mcm::setCallback(mcmCallback);

#endif
}
#endif // USBDM_MCM_AVAILABLE

#ifdef USBDM_OSC0_AVAILABLE
void testOSC() {

   //************ OSC **************/
   Osc0::setErcDivider(OscErClkDiv_By1);
   Osc0::setErcDivider(OscErClkDiv_By2);
   Osc0::setErcDivider(OscErClkDiv_By4);
   Osc0::setErcDivider(OscErClkDiv_By8);

   Osc0::setExternalReference(OscErClkEn_Disabled);
   Osc0::setExternalReference(OscErClkEn_Enabled);
}
#endif

#ifdef USBDM_PDB0_AVAILABLE
void pdbCallback(void) {

}

void testPDB() {

   Seconds period{200_ms};
   uint32_t scValue = 0;
   uint16_t modValue = 0;

   const Seconds test[] = {
         5_s, 1_s, 500_ms, 200_ms, 10_ms, 5_ms, 1_ms, 500_ns, 200_ns, 100_ns, 10_ns,
   };
   for (unsigned index=0; index<sizeofArray(test); index++) {
      period = test[index];
      if (Pdb0::calculateCounterParameters(period, scValue, modValue) != E_NO_ERROR) {
         console.writeln((float)period, " -> Failed" );
      }
      else {
         console.writeln((float)period, " -> ", (unsigned)Pdb0::convertTicksToSeconds(modValue, scValue));
      }
   }

   Seconds_Ticks st1, st2;

   st1.fromSeconds(10_s);
   st2.fromTicks(100_ticks);

   console.writeln("10_s      = ", (float)st1.toSeconds());
   console.writeln("100_ticks = ", st2.toTicks());

   Pdb0::configure(Pdb0::DefaultInitValue);
   Pdb0::softwareTrigger();
   while(!Pdb0::isRegisterLoadComplete()) {
      __asm__("nop");
   }
   static constexpr Pdb0::Init init1 {

      PdbTrigger_Software ,      // Trigger Input Source Select - Software trigger is selected
      PdbMode_OneShot ,          // PDB operation mode - Sequence runs once only
      PdbLoadMode_Immediate ,    // Register Load Select - Register loaded immediately

      PdbPrescale_DivBy_4 ,      // Clock Prescaler Divider Select - Divide by 4
      0x1000_ticks ,             // Counter modulus

      NvicPriority_VeryHigh,     // IRQ level for this peripheral - VeryHigh

      PdbErrorAction_Interrupt , // Sequence Error Interrupt Enable - Interrupt on error

      PdbAction_Interrupt ,      // Action done on event - No action on event
      0x900_ticks ,              // Interrupt delay
      pdbCallback,               // Action call-back


      // ADC Pretriggers
      PdbChannel_0, PdbPretrigger0_Delayed, 0x111_ticks, // Channel 0 Pretrigger 0
      PdbChannel_0, PdbPretrigger1_Disabled,             // Channel 0 Pretrigger 1
      PdbChannel_1, PdbPretrigger0_Delayed, 0x222_ticks, // Channel 1 Pretrigger 0
      PdbChannel_1, PdbPretrigger1_Bypassed,             // Channel 1 Pretrigger 1

      // DAC triggers
      PdbDac0TriggerMode_Periodic, 0x333_ticks, // DAC0 Trigger
      PdbDac1TriggerMode_External,              // DAC1 Trigger

      // Pulse outputs
      PdbPulseOutput0_Enabled, 0x444_ticks, 0x555_ticks,  // Pulse output 0 (CMP0)
      PdbPulseOutput1_Enabled, 0x666_ticks, 0x777_ticks,  // Pulse output 0 (CMP1)

      Pdb0::DefaultInitValue,
   };
   Pdb0::configure(init1);
   while(!Pdb0::isRegisterLoadComplete()) {
      __asm__("nop");
   }

   static constexpr Pdb0::Init init2 {

      PdbTrigger_Software ,      // Trigger Input Source Select - Software trigger is selected
      PdbMode_OneShot ,          // PDB operation mode - Sequence runs once only
      PdbLoadMode_Immediate ,    // Register Load Select - Register loaded immediately

      PdbPrescale_Auto_Calculated ,  // Clock Prescaler Auto calculated from PDB period
      200_ms ,                   // Counter period

      NvicPriority_VeryHigh,     // IRQ level for this peripheral - VeryHigh

      PdbAction_Interrupt ,      // Action done on event - Interrupt on event
      190_ms ,                   // Interrupt delay
      pdbCallback,               // Action call-back

      PdbErrorAction_None ,      // Sequence Error Interrupt Enable - No interrupt on error
//      pdbCallback,               // Error action call-back

      // ADC Pretriggers
      PdbChannel_0, PdbPretrigger0_Delayed, 100_ms, // Channel 0 Pretrigger 0 @ 100 ms
      PdbChannel_0, PdbPretrigger1_Disabled,        // Channel 0 Pretrigger 1 disabled
      PdbChannel_1, PdbPretrigger0_Delayed, 150_ms, // Channel 1 Pretrigger 0 @ 150 ms
      PdbChannel_1, PdbPretrigger1_Bypassed,        // Channel 1 Pretrigger 1 disabled

      // DAC triggers
      PdbDac0TriggerMode_Periodic, 50_ms, // DAC0 Trigger @ 50 ms
      PdbDac1TriggerMode_External,        // DAC1 Trigger directly triggered by external input

      // Pulse outputs
      PdbPulseOutput0_Enabled, 120_ms, 130_ms,  // Pulse output 0 (CMP0 window) @ 120-130 ms
      PdbPulseOutput1_Enabled, 220_ms, 230_ms,  // Pulse output 0 (CMP1 window) @ 220-230 ms
   };
   Pdb0::configure(init2);

   while(!Pdb0::isRegisterLoadComplete()) {
      __asm__("nop");
   }
}
#endif // USBDM_PDB_AVAILABLE

#ifdef USBDM_PIT_AVAILABLE

void pitCallback() {
   TestLed::toggle();
}

void testPitInstance(Pit const &pit, const PitChannel &pitChannel0, const PitChannel &pitChannel1) {
   static constexpr Pit::Init commonInit {
      PitDebugMode_StopInDebug,
      PitOperation_Enabled,
   };
   pit.defaultConfigure();
   pit.configure(commonInit);

   pitChannel0.configure(100_ticks, PitChannelIrq_Enabled);
   pitChannel0.configure(1_s, PitChannelIrq_Enabled);
   pitChannel0.setPeriod(1_s);
   pitChannel0.setPeriod(100_ticks);
   pitChannel0.setPeriodInMicroseconds(100);
   pitChannel0.defaultConfigureIfNeeded();
   pitChannel0.enable();
   pitChannel0.disable();
   pitChannel0.delay(100_ticks);
   pitChannel0.delay(1_s);
   pitChannel0.enableInterrupts(false);
   pitChannel0.enableNvicInterrupts();
   pitChannel0.enableNvicInterrupts(NvicPriority_High);
   pitChannel0.disableNvicInterrupts();
   pitChannel0.setCallback(TestLed::toggle);
   pitChannel0.oneShot(TestLed::toggle, 100_ticks);
   pitChannel0.oneShot(TestLed::toggle, 1_s);
   pitChannel0.oneShotInMicroseconds(TestLed::toggle, 1);
   pitChannel0.oneShotInMilliseconds(TestLed::toggle, 100);

   pitChannel1.configure(100_ticks, PitChannelIrq_Enabled);
   pitChannel1.configure(1_s, PitChannelIrq_Enabled);
   pitChannel1.setPeriod(1_s);
   pitChannel1.setPeriod(100_ticks);
   pitChannel1.setPeriodInMicroseconds(100);
   pitChannel1.defaultConfigureIfNeeded();
   pitChannel1.enable();
   pitChannel1.disable();
   pitChannel1.delay(100_ticks);
   pitChannel1.delay(1_s);
   pitChannel1.enableInterrupts(false);
   pitChannel1.enableNvicInterrupts();
   pitChannel1.enableNvicInterrupts(NvicPriority_High);
   pitChannel1.disableNvicInterrupts();
   pitChannel1.setCallback(TestLed::toggle);
   pitChannel1.oneShot(TestLed::toggle, 100_ticks);
   pitChannel1.oneShot(TestLed::toggle, 1_s);
   pitChannel1.oneShotInMicroseconds(TestLed::toggle, 1);
   pitChannel1.oneShotInMilliseconds(TestLed::toggle, 100);
}

void testPit() {
   const Pit pit{};
   const Pit::Channel<PitChannelNum_1> pitChannel0;
   const Pit::PitChannel pitChannel1(PitChannelNum_1);

   pitChannel0.configure(100_ticks, PitChannelIrq_Enabled);
   pitChannel0.configure(1_s, PitChannelIrq_Enabled);
   pitChannel0.setPeriod(1_s);
   pitChannel0.setPeriod(100_ticks);
   pitChannel0.setPeriodInMicroseconds(100);
   pitChannel0.defaultConfigureIfNeeded();
   pitChannel0.enable();
   pitChannel0.disable();
   pitChannel0.delay(100_ticks);
   pitChannel0.delay(1_s);
   pitChannel0.enableInterrupts(false);
   pitChannel0.enableNvicInterrupts();
   pitChannel0.enableNvicInterrupts(NvicPriority_High);
   pitChannel0.disableNvicInterrupts();
   pitChannel0.setCallback(TestLed::toggle);
   pitChannel0.oneShot(TestLed::toggle, 100_ticks);
   pitChannel0.oneShot(TestLed::toggle, 1_s);
   pitChannel0.oneShotInMicroseconds(TestLed::toggle, 1);
   pitChannel0.oneShotInMilliseconds(TestLed::toggle, 100);

   pitChannel1.configure(100_ticks, PitChannelIrq_Enabled);
   pitChannel1.configure(1_s, PitChannelIrq_Enabled);
   pitChannel1.setPeriod(1_s);
   pitChannel1.setPeriod(100_ticks);
   pitChannel1.setPeriodInMicroseconds(100);
   pitChannel1.defaultConfigureIfNeeded();
   pitChannel1.enable();
   pitChannel1.disable();
   pitChannel1.delay(100_ticks);
   pitChannel1.delay(1_s);
   pitChannel1.enableInterrupts(false);
   pitChannel1.enableNvicInterrupts();
   pitChannel1.enableNvicInterrupts(NvicPriority_High);
   pitChannel1.disableNvicInterrupts();
   pitChannel1.setCallback(TestLed::toggle);
   pitChannel1.oneShot(TestLed::toggle, 100_ticks);
   pitChannel1.oneShot(TestLed::toggle, 1_s);
   pitChannel1.oneShotInMicroseconds(TestLed::toggle, 1);
   pitChannel1.oneShotInMilliseconds(TestLed::toggle, 100);

   testPitInstance(pit, pitChannel0, pitChannel1);

   pitChannel1.oneShot(TestLed::toggle, 1_s);

   TestLed::setOutput();

   Pit::defaultConfigure();
   Pit::configure(Pit::DefaultInitValue);
   Pit::configure(Pit::DefaultChannelInitValues);

   static constexpr Pit::Init commonInit {
      PitDebugMode_StopInDebug,
      PitOperation_Enabled,
   };
   Pit::configure(commonInit);

   static constexpr Pit::ChannelInit channelInit {
      PitChannelNum_1,
      PitChannelEnable_Enabled,
      PitChannelIrq_Enabled,
      TestLed::toggle,
      NvicPriority_VeryHigh,
      200_ms,
   };
   Pit::configure(channelInit);
   Pit::configure(PitChannelNum_1, channelInit);

   static constexpr Pit::ChannelInit channelInits[] {
      {
      PitChannelNum_0,

      PitChannelEnable_Enabled , // Timer Channel Enable - Channel enabled
      PitChannelIrq_Enabled ,    // Timer Interrupt Enable - Interrupts are enabled
      200_ticks,                 // Reload value channel 0
      },
      {
      PitChannelNum_1,

      PitChannelEnable_Enabled , // Timer Channel Enable - Channel enabled
//      PitChannelChain_Disabled , // Chain with previous channel - Timers are not chained
      PitChannelIrq_Enabled ,    // Timer Interrupt Enable - Interrupts are enabled
      100_ticks,                 // Reload value channel 1
      },
   };
   Pit::configure(channelInits);

   PitTestChannelA::delay(2_s);
   PitTestChannelA::oneShot(TestLed::toggle, 2_s);

   PitTestChannelB::configure(channelInit);

   for(;;) {
      __asm__("nop");
   }
   Pit::setCallback(PitChannelNum_0, pitCallback);
   Pit::configureChannel(PitChannelNum_0, 1_s, PitChannelIrq_Enabled);
   Pit::enableNvicInterrupts(PitChannelNum_0);
   Pit::defaultConfigure();
   Pit::defaultConfigureIfNeeded();

   using PitChannel = Pit::Channel<0>;

   PitChannel::Owner::configure(commonInit);
   PitChannel::setCallback(pitCallback);
   PitChannel::configure(1_s, PitChannelIrq_Enabled);
   PitChannel::enableNvicInterrupts(NvicPriority_Normal);
}
#endif // USBDM_PIT_AVAILABLE

#ifdef USBDM_PMC_AVAILABLE
void pmcCallback(PmcInterruptReason) {
}

void testPmc() {
   static constexpr Pmc::Init pmcInitValue {
      PmcLowVoltageAction_None ,                // Low-voltage detect action - None
      PmcLowVoltageDetectLevel_Low ,            // Low-Voltage Detect level select - Low trip point selected
      PmcLowVoltageWarningAction_None ,         // Low-Voltage Warning Interrupt Enable - No action
      PmcLowVoltageWarningLevel_Low ,           // Low-Voltage Warning Voltage Select - Low trip point selected
      PmcBandgapOperationInLowPower_Disabled ,  // Bandgap Enable In VLPx Operation - Disabled
      PmcBandgapBuffer_Disabled,                // Bandgap Buffer Enable - Disabled
      NvicPriority_VeryLow,                     // IRQ level for this peripheral - VeryLow
      pmcCallback,                              // Call-back function
   };
   Pmc::configure(pmcInitValue);
   Pmc::defaultConfigure();
   Pmc::configure(Pmc::DefaultInitValue);
   Pmc::setCallback(pmcCallback);
}
#endif

#ifdef USBDM_RCM_AVAILABLE
void testRcm() {
   static constexpr Rcm::Init rcmInit {
      RcmResetPinStopFilter_LowPowerOscillator ,     // Reset pin filter select in low power modes
      RcmResetPinRunWaitFilter_LowPowerOscillator ,  // Reset pin filter select in run and wait modes
      RcmResetFilter_10Cycles,                       // Reset pin filter bus clock select
   };
   Rcm::configure(rcmInit);
   Rcm::configure(Rcm::DefaultInitValue);
   Rcm::defaultConfigure();
}
#endif // USBDM_RCM_AVAILABLE

#ifdef USBDM_RNGA_AVAILABLE
void rngaCallback() {
}

void testRnga() {
   static constexpr Rnga::Init rngaInit = {
      RngaMode_Normal ,                 // Operating Mode  - RNGA is not in Sleep mode
      RngaAction_Interrupt ,            // Action on event - Interrupt
      RngaSecurityViolations_Notified , // High Assurance - Security violations are notified
      RngaGo_GenerateData ,             // Generation of random data - Start generation
      uint32_t(0x1234),                 // External Entropy value
   };
   Rnga::configure(rngaInit);
   Rnga::configure(Rnga::DefaultInitValue);
   Rnga::defaultConfigure();

   Rnga::waitForRandomValue();
   Rnga::getRandomValue();
   Rnga::isValueAvailable();

   Rnga::setCallback(rngaCallback);
}
#endif

#if defined USBDM_SIM_AVAILABLE
void testSIM() {

   static const Sim::Init simInit {
      SimErc32kClkoutPinSelect_None ,            // ERCLK32K Clock Output
      SimErc32kSel_LpoClk ,                      // ERCLK32K clock source
      SimUsbPower_EnabledInAll,                  // USB voltage regulator power control
      SimLpuartClockSource_PeripheralClk,        // LPUART Clock select
      SimUsbFullSpeedClockSource_PeripheralClk,  // USB Clock
      SimTraceClockoutSel_McgOutClk,             // Debug trace clock select
      SimRtcClkoutSel_32kHz,                     // RTC clock out source
      SimClkoutSel_OscerClk0,                    // CLKOUT pin clock
      SimPeripheralClockSource_Irc48mClk,        // Peripheral Clock
      SimFlexbusSecurity_None,                   // FlexBus off-chip access security level
      SimFtm0Flt0_Ftm0Fault0,                    // FTM0 Fault 0 Select
      SimFtm0Trg0Src_Cmp0,                       // FTM0 Hardware Trigger 0 Source
      SimFtm0Flt1_Ftm0Fault1,                    // FTM0 Fault 1 Select
      SimFtm0Trg1Src_PdbTrigger1,                // FTM0 Hardware Trigger 1 Source
      SimFtm0ClkSel_FtmClkin0,                   // FTM0 External Clock Pin
      SimFtm1Flt0_Ftm1Fault0,                    // FTM1 Fault 0 Select
      SimFtm1Ch0Src_IcPin,                       // FTM 1 channel 0 input capture source
      SimFtm1ClkSel_FtmClkin0,                   // FTM1 External Clock Pin
      SimFtm2Flt0_Ftm2Fault0,                    // FTM2 Fault 0 Select
      SimFtm2Ch0Src_IcPin,                       // FTM2 channel 0 input capture source
      SimFtm2Ch1Src_IcPin,                       // FTM2 channel 1 input capture source
      SimFtm2ClkSel_FtmClkin0,                   // FTM2 External Clock Pin
      SimFtm3Flt0_Ftm3Fault0,                    // FTM3 Fault 0 Select
      SimFtm3Trg0Src_Ftm1Match,                  // FTM3 Hardware Trigger 0 Source
      SimFtm3Trg1Src_Ftm2Match,                  // FTM3 Hardware Trigger 1 Source
      SimFtm3ClkSel_FtmClkin0,                   // FTM3 External Clock Pin
      SimUart0RxSrc_RxPin,                       // UART 0 receive data source
      SimUart0TxSrc_Direct,                      // UART 0 transmit data source
      SimLpuart0RxSrc_RxPin,                     // LPUART 0 receive data source
      SimUart1RxSrc_RxPin,                       // UART 1 receive data source
      SimUart1TxSrc_Direct,                      // UART 1 transmit data source
      SimAdc0TriggerMode_Pdb ,                   // ADC0 trigger mode
      SimAdc0TriggerSrc_External,                // ADC0 trigger
      SimAdc1TriggerMode_Pdb ,                   // ADC1 trigger mode
      SimAdc1TriggerSrc_External,                // ADC1 trigger
      SimFtm0Ch0OutputSrc_Direct,                // FTM0 channel 0 output source
      SimFtm3Ch0OutputSrc_Direct,                // FTM3 channel 0 output source
      SimFtm0Ch1OutputSrc_Direct,                // FTM0 channel 1 output source
      SimFtm3Ch1OutputSrc_Direct,                // FTM3 channel 1 output source
      SimFtm0Ch2OutputSrc_Direct,                // FTM0 channel 2 output source
      SimFtm3Ch2OutputSrc_Direct,                // FTM3 channel 2 output source
      SimFtm0Ch3OutputSrc_Direct,                // FTM0 channel 3 output source
      SimFtm3Ch3OutputSrc_Direct,                // FTM3 channel 3 output source
      SimFtm0Ch4OutputSrc_Direct,                // FTM0 channel 4 output source
      SimFtm3Ch4OutputSrc_Direct,                // FTM3 channel 4 output source
      SimFtm0Ch5OutputSrc_Direct,                // FTM0 channel 5 output source
      SimFtm3Ch5OutputSrc_Direct,                // FTM3 channel 5 output source
      SimFtm0Ch6OutputSrc_Direct,                // FTM0 channel 6 output source
      SimFtm3Ch6OutputSrc_Direct,                // FTM3 channel 6 output source
      SimFtm0Ch7OutputSrc_Direct,                // FTM0 channel 7 output source
      SimFtm3Ch7OutputSrc_Direct,                // FTM3 channel 7 output source
   };
   Sim::configure(simInit);

   Sim::configure(Sim::DefaultInitValue);

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

   Sim::ClockSourceInit clockSourceInit {
      SimPeripheralClockSource_McgPllClk,
      SimLpuartClockSource_Disabled,
      Sim::DefaultSopt2Values[0],
   };
   Sim::configure(clockSourceInit);

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
   Sim::setFtm0Trg0Src(SimFtm0Trg0Src_Ftm1Match);

   Sim::setFtm0Trg1Src(SimFtm0Trg1Src_Ftm2Match);
   Sim::setFtm0Trg1Src(SimFtm0Trg1Src_PdbTrigger1);

   Sim::setFtm3Trg0Src(SimFtm3Trg0Src_Ftm1Match);

   Sim::setFtm3Trg1Src(SimFtm3Trg1Src_Ftm2Match);

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
   Sim::configure(lpuart0Init);

   static const Sim::Uart0Init uart0Init {
      SimUart0TxSrc_Direct, SimUart0RxSrc_Cmp0,
   };
   Sim::configure(uart0Init);

   static const Sim::Uart1Init uart1Init {
      SimUart1TxSrc_Direct, SimUart1RxSrc_Cmp0,
   };
   Sim::configure(uart1Init);

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
   Sim::configure(adc0Init);

   Sim::Adc1Init adc1Init {
      SimAdc1TriggerMode_Alt_PreTrigger_0, SimAdc1TriggerSrc_Cmp0,
   };
   Sim::configure(adc1Init);

   Sim::AdcInit adcInit {
      SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0TriggerSrc_Cmp0,
      SimAdc1TriggerMode_Alt_PreTrigger_0, SimAdc1TriggerSrc_Cmp0,
   };
   Sim::configure(adcInit);

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

   //************ SCGCx **************/
   SimInfo::ClockEnables clockInit {
      SimAdc0Clock_Enabled,  // Adc0 Clock Gate Control - Adc0 Clock enabled
      SimAdc1Clock_Disabled,  // Adc1 Clock Gate Control - Adc1 Clock disabled
      SimCmpClock_Disabled,  // Cmp Clock Gate Control - Cmp Clock disabled
      SimCrc0Clock_Disabled,  // Crc0 Clock Gate Control - Crc0 Clock disabled
      SimDac0Clock_Disabled,  // Dac0 Clock Gate Control - Dac0 Clock disabled
      SimDac1Clock_Disabled,  // Dac1 Clock Gate Control - Dac1 Clock disabled
      SimDma0Clock_Disabled,  // Dma0 Clock Gate Control - Dma0 Clock disabled
      SimDmamux0Clock_Disabled,  // Dmamux0 Clock Gate Control - Dmamux0 Clock disabled
      SimEwmClock_Disabled,  // Ewm Clock Gate Control - Ewm Clock disabled
      SimFtfClock_Enabled,  // Ftf Clock Gate Control - Ftf Clock enabled
      SimFtm0Clock_Disabled,  // Ftm0 Clock Gate Control - Ftm0 Clock disabled
      SimFtm1Clock_Disabled,  // Ftm1 Clock Gate Control - Ftm1 Clock disabled
      SimFtm2Clock_Disabled,  // Ftm2 Clock Gate Control - Ftm2 Clock disabled
      SimFtm3Clock_Disabled,  // Ftm3 Clock Gate Control - Ftm3 Clock disabled
      SimI2c0Clock_Disabled,  // I2c0 Clock Gate Control - I2c0 Clock disabled
      SimI2c1Clock_Disabled,  // I2c1 Clock Gate Control - I2c1 Clock disabled
      SimI2s0Clock_Disabled,  // I2s0 Clock Gate Control - I2s0 Clock disabled
      SimLptmr0Clock_Disabled,  // Lptmr0 Clock Gate Control - Lptmr0 Clock disabled
      SimLpuart0Clock_Disabled,  // Lpuart0 Clock Gate Control - Lpuart0 Clock disabled
      SimPdb0Clock_Disabled,  // Pdb0 Clock Gate Control - Pdb0 Clock disabled
      SimPitClock_Disabled,  // Pit Clock Gate Control - Pit Clock disabled
      SimPortaClock_Disabled,  // Porta Clock Gate Control - Porta Clock disabled
      SimPortbClock_Disabled,  // Portb Clock Gate Control - Portb Clock disabled
      SimPortcClock_Disabled,  // Portc Clock Gate Control - Portc Clock disabled
      SimPortdClock_Disabled,  // Portd Clock Gate Control - Portd Clock disabled
      SimPorteClock_Disabled,  // Porte Clock Gate Control - Porte Clock disabled
      SimRngaClock_Disabled,  // Rnga Clock Gate Control - Rnga Clock disabled
      SimRtcClock_Disabled,  // Rtc Clock Gate Control - Rtc Clock disabled
      SimSpi0Clock_Disabled,  // Spi0 Clock Gate Control - Spi0 Clock disabled
      SimSpi1Clock_Disabled,  // Spi1 Clock Gate Control - Spi1 Clock disabled
      SimUart0Clock_Disabled,  // Uart0 Clock Gate Control - Uart0 Clock disabled
      SimUart1Clock_Disabled,  // Uart1 Clock Gate Control - Uart1 Clock disabled
      SimUart2Clock_Disabled,  // Uart2 Clock Gate Control - Uart2 Clock disabled
      SimUsb0Clock_Disabled,  // Usb0 Clock Gate Control - Usb0 Clock disabled
      SimVrefClock_Disabled,  // Vref Clock Gate Control - Vref Clock disabled
   };
   SimInfo::configureClocks(clockInit);
   SimInfo::configureClocks(SimInfo::DefaultClockEnables);
   SimInfo::enableClocks(clockInit);
   SimInfo::disableClocks(clockInit);
}
#endif // USBDM_SIM_AVAILABLE

#ifdef USBDM_SMC_AVAILABLE

void report() {
   checkError();
   console_setBaudRate(defaultBaudRate);
   console.writeln(
         "Run mode = ", Smc::getSmcStatusName(),
         ", Clock = ", Mcg::getClockModeName(),
         "@", SystemCoreClock, " Hz").flushOutput();
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
      Smc::enterRunMode(ClockConfig_VLPR_BLPI_4MHz);
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
#endif // USBDM_SMC_AVAILABLE

#ifdef USBDM_SPI0_AVAILABLE

void testSpi() {
#if 1
   static constexpr TestSPI::SerialInit SpiSerialInitA {

      // CTAR initialisation
      SpiCtarSelect_0,        // CTAR0

      10_MHz ,                // Speed of interface
      SpiMode_0 ,             // Mode - Mode 0: CPOL=0, CPHA=0
      SpiFrameSize_8_bits ,   // SPI Frame sizes - 8 bits/transfer
      SpiBitOrder_MsbFirst,   // Transmission order - MSB sent first

      TestSPI::DefaultSerialInitValue[0],
   };

   static constexpr TestSPI::Config SpiSharedConfigA {

      // Shared configuration - not usually modified after initial configuration
      SpiDoze_Enabled ,                         // Enables Doze mode (when processor is waiting?) - Suspend in Doze
      SpiFreeze_Enabled ,                       // Controls SPI operation while in debug mode - Suspend in debug
      SpiPcsMode_PCS5,
      SpiModifiedTiming_Normal ,                // Modified Timing Format - Normal Timing
      SpiRxOverflowHandling_Ignore ,            // Handling of Rx Overflow Data - ignore new data
      SpiContinuousClock_Disable,               // Continuous SCK Enable - Not continuous clock
      SpiPcsPolarity_TestSPI_TestPcs_ActiveLow, // This PCS is Active-low (others are active-high)

      // These are initial transfer settings. Can be changed using selectConfiguration().
      SpiCtarSelect_0,                          // Use CTAR0
      SpiPeripheralSelect_TestSPI_TestPcs,      // PCS to assert during transfer
      SpiPeripheralSelectMode_Transaction,      // Assert PCS for entire transaction
   };

   static constexpr TestSPI::Init SpiConfigurationA {
      SpiSharedConfigA,
      SpiSerialInitA,
      SpiSerialInitA,
   };

   TestSPI spi1A(SpiConfigurationA);
   spi1A.configure(SpiConfigurationA);
#endif

   static constexpr TestSPI::Init spiConfiguration {
      {
         // Shared configuration - not usually modified after initial configuration
         SpiDoze_Enabled ,                         // Enables Doze mode (when processor is waiting?) - Suspend in Doze
         SpiFreeze_Enabled ,                       // Controls SPI operation while in debug mode - Suspend in debug
         SpiPcsMode_PCS5,
         SpiModifiedTiming_Normal ,                // Modified Timing Format - Normal Timing
         SpiRxOverflowHandling_Overwrite ,         // Handling of Rx Overflow Data - Overwrite existing
         SpiContinuousClock_Disable,               // Continuous SCK Enable - Not continuous clock
         SpiPcsPolarity_TestSPI_TestPcs_ActiveLow, // This PCS is active-low (others are active-high)

         // These are initial transfer settings. Can be changed using selectConfiguration().
         SpiCtarSelect_0,                          // Use CTAR0
         SpiPeripheralSelect_TestSPI_TestPcs,      // PCS to assert during transfer
         SpiPeripheralSelectMode_Transaction,      // Assert PCS for entire transaction
      },
      {
         // CTAR 0 initialisation (SerialInit)
         10_MHz ,                // Speed of interface
         SpiMode_0 ,             // Mode - Mode 0: CPOL=0, CPHA=0
         SpiFrameSize_8_bits ,   // SPI Frame sizes - 8 bits/transfer
         SpiBitOrder_MsbFirst,   // Transmission order - MSB sent first
      },
      {
         // CTAR 1 initialisation (SerialInit)
         1_MHz ,                 // Speed of interface
         SpiMode_0 ,             // Mode - Mode 0: CPOL=0, CPHA=0
         SpiFrameSize_8_bits ,   // SPI Frame sizes - 8 bits/transfer
         SpiBitOrder_MsbFirst,   // Transmission order - MSB sent first
      },
   };

   TestSPI spi(spiConfiguration);

   // Set configuration to use (Not needed as same as default set by SpiConfiguration above)
//   spi.selectConfiguration(SpiCtarSelect_0, SpiPeripheralSelect_TestSPI_TestPcs, SpiPeripheralSelectMode_Transaction);

   const uint8_t dataOut1[4]                      = {'1', '2', '3', '4', };
   const uint8_t dataOut2[4]                      = {'5', '6', '7', '8', };
   uint8_t dataIn1[USBDM::sizeofArray(dataOut1)]  = "";
   uint8_t dataIn2[USBDM::sizeofArray(dataOut2)]  = "";

   for(;;) {
      spi.startTransaction();
      spi.txRx(dataOut1, dataIn1);
      spi.txRx(dataOut2, dataIn2);
      spi.endTransaction();
      wait(200_ms);
   }
}

#endif

#ifdef USBDM_TSI0_AVAILABLE
void testTsi() {

   Tsi0::Init tsiInit {
      TsiScanMode_Periodic ,              // Select scan mode - Disabled
      TsiStopMode_Disabled ,              // TSI STOP Enable - Disabled in low power
      TsiEventSource_EndOfScan ,          // TSI event source - End Of Scan
      TsiErrorInterrupt_Enabled ,         // Error Interrupt Enable - Interrupt enabled
      TsiElectrodePrescaler_DivBy2 ,      // Electrode Oscillator Prescaler - Divide by 8
      TsiConsecutiveScan(8),
      TsiLowPowerScanInterval_1ms ,       // Low-Power Mode Scan Interval - 1 ms interval
      TsiLowPowerClockSource_LpoClk ,     // Low-Power Mode Clock Source - LPOCLK
      TsiClockSource_LpoClk ,             // Active Mode Clock Source - LPOSCCLK
      TsiScanPeriod(8) ,                  // Scan Period Modulus
      TsiReferenceChargeCurrent(16) ,     // Reference Oscillator Charge Current select
      TsiExternalChargeCurrent(16) ,      // External Oscillator Charge Current select
      TsiElectrodeA::TSI_INPUT ,          // Channels enabled as TSI inputs
      TsiElectrodeB::TSI_INPUT ,          //
      TsiElectrodeA::TSI_LOWPOWER_INPUT , // Low-Power Scan Pin
      TsiLowThreshold(0) ,                // Low Power Channel Low Threshold value
      TsiHighThreshold(0),                // Low Power Channel High Threshold value
   };
   Tsi0::configure(tsiInit);
   Tsi0::configure(Tsi0::DefaultInitValue);
   Tsi0::defaultConfigure();
}
#endif

#ifdef USBDM_USB_AVAILABLE
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
#endif

#ifdef USBDM_VREF_AVAILABLE
void testVREF() {
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
#endif

#ifdef USBDM_WDOG_AVAILABLE
void wdogCallback() {
   __asm__("nop");
}

void testWDOG() {

   console.writeln("Size of Wdog::Init = ", sizeof(Wdog::Init), " bytes");

   Wdog::defaultConfigure();
   Wdog::configure(Wdog::DefaultInitValue);

   //   static const Wdog::Init wdogInit {
   //      WdogEnable_Enabled,          // Enabled
   //      WdogTestMode_Disabled ,       // Test mode disable
   //      WdogEnableInWait_Disabled ,   // Enable watchdog in WAIT mode
   //      WdogEnableInStop_Disabled ,   // Enable watchdog in STOP mode
   //      WdogEnableInDebug_Disabled ,  // Enable watchdog in DEBUG mode
   //      WdogAllowUpdate_Enabled ,     // Allow watchdog update
   //      WdogWindow_Disabled ,         // Enable watchdog windowing mode
   //      WdogIntBeforeReset_Enabled ,  // Enable interrupt before reset
   //      WdogClock_LpoClk ,            // Watchdog clock source
   //      WdogEnable_Disabled ,         // Watchdog enable
   //      NvicPriority_Normal,          // IRQ level for this peripheral
   //      wdogCallback,                 // Call-back
   //      // Using ticks
   //      WdogPrescale_Direct,
   //      1000_ticks, 0_ticks,
   //      // Using seconds
   //      1_s , 0_s ,                   // Watchdog Timeout and Window values
   //      Wdog::DefaultInitValue,
   //   };

   static constexpr Wdog::Init wdogInit {
      WdogEnable_Enabled,          // Enabled
      WdogTestMode_Disabled ,       // Test mode disable
      WdogEnableInWait_Disabled ,   // Enable watchdog in WAIT mode
      WdogEnableInStop_Disabled ,   // Enable watchdog in STOP mode
      WdogEnableInDebug_Disabled ,  // Enable watchdog in DEBUG mode
      WdogAllowUpdate_Enabled ,     // Allow watchdog update
      WdogWindow_Disabled ,         // Enable watchdog windowing mode
      WdogAction_ImmediateReset ,   // Controls interrupt before reset - Immediate Reset
      WdogClock_LpoClk ,            // Watchdog clock source
      WdogEnable_Disabled ,         // Watchdog enable
      NvicPriority_Normal,          // IRQ level for this peripheral
//      wdogCallback,                 // Call-back
      // Using ticks
//      WdogPrescale_Direct,
//      1000_ticks, 0_ticks,
      // Using seconds
      2_s , 1_s ,                   // Watchdog Timeout and Window values
      Wdog::DefaultInitValue,
   };

   console.writeln("Wdog::configure(wdogInit), rc = ", getErrorMessage(Wdog::configure(wdogInit)));


   for(;;) {
      wait(5_ms);
      Wdog::refresh(WdogRefresh_1, WdogRefresh_2);
   }
}
#endif

void runTests() {
   console.writeln("SystemBusClock - ", SystemBusClock);

#ifdef USBDM_ADC0_AVAILABLE
   testAdc();
#endif
#ifdef USBDM_CMP0_AVAILABLE
   testCmp();
#endif
#ifdef USBDM_CMT_AVAILABLE
   testCmt();
#endif
#ifdef USBDM_CRC0_AVAILABLE
   testCrc();
#endif
#ifdef USBDM_EWM_AVAILABLE
   testEwm();
#endif
#ifdef USBDM_FMC_AVAILABLE
   testFMC();
#endif
#ifdef USBDM_FTM0_AVAILABLE
   testFtm();
#endif
#ifdef USBDM_GPIOA_AVAILABLE
   testGpio();
#endif
#ifdef USBDM_I2C0_AVAILABLE
   testI2c();
#endif
#ifdef USBDM_LLWU_AVAILABLE
   testLLWU();
#endif
#ifdef USBDM_LPTMR0_AVAILABLE
   testLPTMR();
#endif
#if defined(USBDM_MCG_AVAILABLE) && defined(USBDM_SMC_AVAILABLE)
   testMcg();
#endif
#ifdef USBDM_MCM_AVAILABLE
   testMCM();
#endif
#ifdef USBDM_OSC0_AVAILABLE
   testOSC();
#endif
#ifdef USBDM_PDB0_AVAILABLE
   testPDB();
#endif
#ifdef USBDM_PIT_AVAILABLE
   testPit();
#endif
#ifdef USBDM_PMC_AVAILABLE
   testPmc();
#endif
#ifdef USBDM_RCM_AVAILABLE
   testRcm();
#endif
#ifdef USBDM_SIM_AVAILABLE
   testSIM();
#endif
#ifdef USBDM_SPI0_AVAILABLE
   testSpi();
#endif
#ifdef USBDM_TSI0_AVAILABLE
   testTsi();
#endif
#ifdef USBDM_VREF_AVAILABLE
   testVREF();
#endif
}

void doTest() {
//   testEwm();
//   testI2c();
   testSpi();
}

/**
 *
 * @return
 */
int main() {
   console.writeln("SystemBusClock - ", SystemBusClock);

   doTest();

   runTests();
}
