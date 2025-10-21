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
using Led   = RGB_Blue;

// Assumes prescaler set to obtain 8MHz clock
constexpr Ticks  PrimaryCarrierHalfTime   = Ticks((8000000UL/40000)/2); // 40kHz
constexpr Ticks  SecondaryCarrierHalfTime = Ticks((8000000UL/80000)/2); // 80kHz

constexpr Ticks OneMarkTime  = 100_ticks;
constexpr Ticks OneSpaceTime = 50_ticks;

constexpr Ticks ZeroMarkTime  = 200_ticks;
constexpr Ticks ZeroSpaceTime = 100_ticks;

volatile  uint16_t data = 0xF0A5;
volatile int bitNum = 15;

void cmtCallback() {

   if (Cmt::getEndOfCycleFlag()) {
      if (bitNum == -1) {
         // Done last bit - disable Tx
         Cmt::stop();
         Cmt::clearEndOfCycleFlag();
         return;
      }
      // Set up next bit
      if (data&(1<<bitNum)) {
         Cmt::setMarkSpacePeriods(OneMarkTime, OneSpaceTime);
      }
      else {
         Cmt::setMarkSpacePeriods(ZeroMarkTime, ZeroSpaceTime);
      }
      bitNum--;
   }
}

void configureCmt() {
   // Configure CMT output and connect to pin
   Cmt::OutputPin::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   static constexpr Cmt::Init cmtInit {
      NvicPriority_Normal,                                     // (irqLevel)        IRQ priority level - Normal
      cmtCallback,                                             // (handlerName)     User declared event handler

      CmtMode_Direct ,                                         // (cmt_msc_mode)    Mode of operation - Direct=Disabled
      CmtClockPrescaler_Auto ,                                 // (cmt_pps_ppsdiv)  Primary Prescaler Divider - Bus clock / 6
      CmtIntermediatePrescaler_DivBy1 ,                        // (cmt_msc_cmtdiv)  Intermediate frequency Prescaler - Intermediate frequency /1
      CmtOutput_ActiveHigh ,                                   // (cmt_oc_output)   Output Control - Active-high
      CmtEndOfCycleAction_Interrupt ,                          // (cmt_dma_irq)     End of Cycle Event handling - Interrupt Request
      CmtPrimaryCarrierHighTime(PrimaryCarrierHalfTime) ,      // (cmt_cgh1_ph)     Primary Carrier High Time Data Value
      CmtPrimaryCarrierLowTime(PrimaryCarrierHalfTime) ,       // (cmt_cgl1_pl)     Primary Carrier Low Time Data Value
      CmtSecondaryCarrierHighTime(SecondaryCarrierHalfTime),   // (cmt_cgh2_sh)     Secondary Carrier High Time Data Value
      CmtSecondaryCarrierLowTime(SecondaryCarrierHalfTime),    // (cmt_cgl2_sl)     Secondary Carrier Low Time Data Value
      CmtMarkPeriod(ZeroMarkTime) ,                            // (cmt_mark)        Mark period
      CmtSpacePeriod(ZeroSpaceTime),                           // (cmt_space)       Space period
   };
   Cmt::configure(cmtInit);
}

/**
 * Transmit the given value
 *
 * @param value Value to transmit
 */
void transmitValueFsk(uint16_t value) {
   data   = value;
   bitNum = 15;
   configureCmt();
}

bool isBusy() {
   return Cmt::isEnabled();
}


int main() {
   console.writeln("Starting\n");
   console.writeln("SystemCoreClock = ", SystemCoreClock);
   console.writeln("SystemBusClock  = ", SystemBusClock);

//   configureCmtFrequencyShiftKeying();
   Led::setOutput();

   for(int count = 0;;count++) {
      waitMS(500);
      while (isBusy()) {
         __asm__("nop");
      }
      transmitValueFsk(0xA0F0);
      console.writeln(count, ": Tick...");
      Led::toggle();
   }
   return 0;
}
