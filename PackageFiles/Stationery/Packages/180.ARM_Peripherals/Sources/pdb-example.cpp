/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "pit.h"
#include "pdb.h"
#include "lptmr.h"

using namespace USBDM;

// LED connection - change as required
using Led   = GpioC<3>;

using Lptmr       = Lptmr0;
using Pdb         = Pdb0;
using Ftm         = Ftm0;
using FtmChannel  = Ftm0Channel<7>;

void lptmrCallback() {
   Led::clear();
//   Led::set();
//   Led::clear();
}

void pdbCallback() {
   Led::toggle();
}

static uint16_t lowTime;
static uint16_t highTime;

void ftmCallback(uint8_t) {
   // True when a high cycle is under way i.e. a low cycle needs to be scheduled
   static bool highCycleInProgress = true;
   if (highCycleInProgress) {
      FtmChannel::setDeltaEventTime(highTime);
      FtmChannel::enable(FtmOutputCompareClear);
   }
   else {
      FtmChannel::setDeltaEventTime(lowTime);
      FtmChannel::enable(FtmOutputCompareSet);
   }
}

int main() {
   printf("Starting\n");

   printf("SystemBusClock  = %ld\n", ::SystemBusClock);
   printf("SystemCoreClock = %ld\n", ::SystemCoreClock);
   printf("PeripheralClock = %ld\n", SimInfo::getPeripheralClock());

   constexpr float PERIOD    = 100*ms;
   constexpr float HIGH_TIME =  25*ms;
   constexpr float LOW_TIME  = PERIOD-HIGH_TIME;

   Led::setOutput();

#if 0
#if 0
   Pdb::configure();
#else
   Pdb::enable();
   Pdb::setTriggerSource(PdbTrigger_Lptrm);
   Pdb::enableSequenceInterrupts();
   Pdb::setClock(PdbPrescale_128, PdbMultiplier_10);
//   Pdb::setModulo(1000);
//   Pdb::setInterruptDelayInTicks(500);
//   Pdb::setPretriggersInTicks(0, PdbPretrigger0_Delayed, 100, PdbPretrigger1_Delayed, 200);
   Pdb::setPeriod(PERIOD+10*ms);
   Pdb::setInterruptDelay(PERIOD-10*ms);
   Pdb::setPretriggers(0, PdbPretrigger0_Delayed, 50*ms, PdbPretrigger1_Delayed, 150*ms);
   Pdb::triggerRegisterLoad(PdbLoadMode_immediate);
//   Pdb::softwareTrigger();

   while (!Pdb::isRegisterLoadComplete()) {
      __asm__("nop");
   }
#endif

   Pdb::setCallback(pdbCallback);
   Pdb::enableNvicInterrupts();

#if 1
   Lptmr::configure();
#else
   // Enable LPTMR in time counting mode
   Lptmr::setTimeCountingMode(LptmrResetOn_Compare);
   // Set clock source
   Lptmr::setClock(LptmrClockSel_erclk32, LptmrPrescale_1024);
   // Set period of timer event
   Lptmr::setPeriod(PERIOD);
#endif
   // Set callback
   Lptmr::setCallback(lptmrCallback);
   Lptmr::enableInterrupts();

   printf("PitInfo::getClockFrequency         = %ld\n", PitInfo::getClockFrequency());
   printf("Pdb0Info::getInputClockFrequency() = %ld\n", Pdb0Info::getInputClockFrequency());
//   printf("Lptmr0Info::getClockFrequency()    = %ld\n", Lptmr0Info::getClockFrequency());

#endif

   Ftm::enable();
   Ftm::setClockSource(FtmClockSource_System);
   Ftm::setMode(FtmMode_LeftAlign);
   Ftm::setPeriod(PERIOD);
   Ftm::enableExternalTrigger(FtmExternalTrigger_init);

   FtmChannel::enable(FtmPwmHighTruePulses);
   FtmChannel::setHighTime(HIGH_TIME);
   FtmChannel::setDriveStrength(PinDriveStrength_High);

   // Check if configuration failed
   USBDM::checkError();

//   Ftm::setChannelCallback(ftmCallback);
//
//
//   // Calculate intervals
//   lowTime  = Ftm::convertSecondsToTicks(LOW_TIME);
//   highTime = Ftm::convertSecondsToTicks(HIGH_TIME);
//
//   // Set up for initial high cycle starting in 100 ticks
//   FtmChannel::enable(FtmOutputCompareSet);
//   FtmChannel::setRelativeEventTime(100);

   for(;;) {
//      Led::toggle();
      waitMS(100);
//      printf("Tick\n");
   }
   return 0;
}
