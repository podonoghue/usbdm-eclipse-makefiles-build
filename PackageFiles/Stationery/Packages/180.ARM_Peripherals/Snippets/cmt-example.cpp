/**
 ============================================================================
 * @file    cmt-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo using Cmt class
 *
 * It will be necessary to configure the CMT in the USBDM configuration
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "cmt.h"

using namespace USBDM;

// LED connection - change as required
using Led   = GpioA<2,ActiveLow>;

constexpr uint8_t  PrimaryCarrierHalfTime   = ((8000000UL/40000)/2); // 40kHz
constexpr uint8_t  SecondaryCarrierHalfTime = ((8000000UL/80000)/2); // 80kHz

constexpr uint16_t OneMarkTime  = 100;
constexpr uint16_t OneSpaceTime = 100;

constexpr uint16_t ZeroMarkTime  = 200;
constexpr uint16_t ZeroSpaceTime = 100;

constexpr uint16_t data = 0xF0A5;
volatile int bitNum = 15;

void cmtCallback() {

   if (Cmt::getStatus()) {
      Led::toggle();
      // LSB
      if (data&(1<<bitNum)) {
         Cmt::setMarkSpaceTiming(OneMarkTime, OneSpaceTime);
      }
      else {
         Cmt::setMarkSpaceTiming(ZeroMarkTime, ZeroSpaceTime);
      }
      if (bitNum == 15) {
         Cmt::setExtendedSpace(CmtExtendedSpace_Enabled);
      }
      if (bitNum--==0) {
         Cmt::setExtendedSpace(CmtExtendedSpace_Disabled);
      }
   }
}

void configureCmtFrequencyShiftKeying() {
   Cmt::configure(CmtMode_Direct);
   Cmt::setPrimaryTiming(PrimaryCarrierHalfTime,PrimaryCarrierHalfTime);
   Cmt::setSecondaryTiming(SecondaryCarrierHalfTime,SecondaryCarrierHalfTime);
   Cmt::setMarkSpaceTiming(ZeroMarkTime, ZeroSpaceTime);
   Cmt::outputControl(CmtOutput_Enabled);
   Cmt::setOutput(PinDriveMode_PushPull);

   Cmt::setCallback(cmtCallback);
   Cmt::enableInterruptDma(CmtInterruptDma_Irq);
   Cmt::enableNvicInterrupts(NvicPriority_Normal);
   Cmt::setMode(CmtMode_FreqShiftKeying);
}

void configureCmtTime() {
   Cmt::configure(CmtMode_Direct);
   Cmt::setPrimaryTiming(PrimaryCarrierHalfTime,PrimaryCarrierHalfTime);
   Cmt::setMarkSpaceTiming(ZeroMarkTime, ZeroSpaceTime);
   Cmt::outputControl(CmtOutput_Enabled);
   Cmt::setOutput(PinDriveMode_PushPull);

   Cmt::setCallback(cmtCallback);
   Cmt::enableInterruptDma(CmtInterruptDma_Irq);
   Cmt::enableNvicInterrupts(NvicPriority_Normal);
   Cmt::setMode(CmtMode_Time);
}

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock = ").writeln(::SystemCoreClock);
   console.write("SystemBusClock  = ").writeln(::SystemBusClock);

//   configureCmtFrequencyShiftKeying();
   configureCmtTime();

   Led::setOutput();

   // Configure CMT output and connect to pin
   Cmt::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   for(int count = 0;;count++) {
      waitMS(500);
      bitNum = 15;
      console.write(count).writeln(": Tick...");
   }
   return 0;
}
