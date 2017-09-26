/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
/*
 * This examples assumes that two appropriate clock configurations have been created:
 *  - ClockConfig_PEE_48MHz   For RUN mode (Core=48MHz, Bus=48MHz, Flash = 24MHz)
 *  - ClockConfig_BLPI_4MHz   For VLPR mode (Core=4MHz, Bus=4MHz, Flash = 800kHz)
 */
#include "hardware.h"
#include "mcg.h"
#include "smc.h"
#include "lptmr.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// LED connection - change as required
using Led   = USBDM::GpioA<2>;

using WakeupTimer = Lptmr0;

void wakeupCallback() {
   __asm__("nop");
   Led::toggle();
}

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock = ").writeln(::SystemCoreClock);
   console.write("SystemBusClock  = ").writeln(::SystemBusClock);
   waitMS(200);

   // Enable all power modes
   Smc::enablePowerModes(
         SmcVeryLowPower_Enable,
         SmcLowLeakageStop_Enable,
         SmcVeryLowLeakageStop_Enable
         );

   Led::setOutput();

   WakeupTimer::configureTimeCountingMode(LptmrResetOn_Compare, LptmrInterrupt_Enable);
   WakeupTimer::setPeriod(3*seconds);
   WakeupTimer::setCallback(wakeupCallback);
   WakeupTimer::enableNvicInterrupts();

   for(;;) {
      /*
       * RUN -> VLPR
       * Change clock down then run mode
       */
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_BLPI_4MHz]);
      console.setBaudRate(defaultBaudRate);
      console<<Smc::getSmcStatusName()<<":"<<Mcg::getClockModeName()<<"@"<<::SystemCoreClock<<" Hz\n";
      Smc::enterRunMode(SmcRunMode_VeryLowPower);
      console<<Smc::getSmcStatusName()<<":"<<Mcg::getClockModeName()<<"@"<<::SystemCoreClock<<" Hz\n";
      waitMS(200);
      /*
       * VLPR -> RUN
       * Change mode then clock up
       */
      Smc::enterRunMode(SmcRunMode_Normal);
      console<<Smc::getSmcStatusName()<<":"<<Mcg::getClockModeName()<<"@"<<::SystemCoreClock<<" Hz\n"<<Flush;
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_PEE_48MHz]);
      console.setBaudRate(defaultBaudRate);
      console<<Smc::getSmcStatusName()<<":"<<Mcg::getClockModeName()<<"@"<<::SystemCoreClock<<" Hz\n";
      waitMS(200);
   }
   return 0;
}
