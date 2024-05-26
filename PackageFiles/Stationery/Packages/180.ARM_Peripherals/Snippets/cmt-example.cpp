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
using Led   = TestLed;

// Assumes prescaler set to obtain 8MHz clock
constexpr Ticks  PrimaryCarrierHalfTime   = Ticks((8000000UL/40000)/2); // 40kHz
constexpr Ticks  SecondaryCarrierHalfTime = Ticks((8000000UL/80000)/2); // 80kHz

constexpr Ticks OneMarkTime  = 100_ticks;
constexpr Ticks OneSpaceTime = 0_ticks;

constexpr Ticks ZeroMarkTime  = 200_ticks;
constexpr Ticks ZeroSpaceTime = 0_ticks;

constexpr uint16_t data = 0xF0A5;
volatile int bitNum = 15;

void cmtCallback() {

   if (Cmt::getEndOfCycleFlag()) {
      // LSB
      if (data&(1<<bitNum)) {
         Cmt::setMarkSpacePeriods(OneMarkTime, OneSpaceTime);
      }
      else {
         Cmt::setMarkSpacePeriods(ZeroMarkTime, ZeroSpaceTime);
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
   // Configure CMT output and connect to pin
   Cmt::OutputPin::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   static constexpr Cmt::Init cmtInit {
      NvicPriority_Normal,
      cmtCallback,

      CmtMode_FreqShiftKeying ,                              // Mode of operation
      CmtClockPrescaler_Auto ,                               // Primary Prescaler Divider
      CmtIntermediatePrescaler_DivBy1 ,                      // Intermediate frequency Prescaler
      CmtOutput_ActiveHigh ,                                 // Output Control
      CmtEndOfCycleAction_Interrupt ,                        // End of Cycle Action
      CmtPrimaryCarrierHighTime(PrimaryCarrierHalfTime) ,    // Primary Carrier High Time
      CmtPrimaryCarrierLowTime(PrimaryCarrierHalfTime) ,     // Primary Carrier Low Time
      CmtSecondaryCarrierHighTime(SecondaryCarrierHalfTime), // Secondary Carrier High Time
      CmtSecondaryCarrierLowTime(SecondaryCarrierHalfTime),  // Secondary Carrier Low Time
      CmtMarkPeriod(ZeroMarkTime) ,                          // Mark period
      CmtSpacePeriod(ZeroSpaceTime),                         // Space period
   };
   Cmt::configure(cmtInit);
}

void configureCmtTime() {
   // Configure CMT output and connect to pin
   Cmt::OutputPin::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   static constexpr Cmt::Init cmtInit {
      NvicPriority_Normal,
      cmtCallback,

      CmtMode_Time ,                                       // Mode of operation
      CmtClockPrescaler_Auto ,                             // Primary Prescaler Divider
      CmtIntermediatePrescaler_DivBy1 ,                    // Intermediate frequency Prescaler
      CmtOutput_ActiveHigh ,                               // Output Control
      CmtEndOfCycleAction_Interrupt ,                      // End of Cycle Action
      CmtPrimaryCarrierHighTime(PrimaryCarrierHalfTime) ,  // Primary Carrier High Time
      CmtPrimaryCarrierLowTime(PrimaryCarrierHalfTime) ,   // Primary Carrier Low Time
      CmtMarkPeriod(ZeroMarkTime) ,                        // Mark period
      CmtSpacePeriod(ZeroSpaceTime),                       // Space period
   };
   Cmt::configure(cmtInit);
}

int main() {
   console.writeln("Starting\n");
   console.writeln("SystemCoreClock = ", SystemCoreClock);
   console.writeln("SystemBusClock  = ", SystemBusClock);

   configureCmtFrequencyShiftKeying();
//   configureCmtTime();

   Led::setOutput();

   for(int count = 0;;count++) {
      waitMS(500);
      bitNum = 15;
      console.writeln(count, ": Tick...");
      Led::toggle();
   }
   return 0;
}
