/*
 ========================================================================================
 * @file    vlpr-run-hsrun-example.cpp (180.ARM_Peripherals/snippets)
 * @brief   Basic C++ demo using Smc and Mcg classes
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ========================================================================================
 */
/*
 * This examples assumes that appropriate clock configurations have been created:
 *  - ClockConfig_PEE_120MHz  For HSRUN mode (Core=120MHz, Bus=60MHz, Flash=24MHz)
 *  - ClockConfig_PEE_80MHz   For RUN mode (Core=80MHz, Bus=40MHz, Flash=27MHz)
 *  - ClockConfig_BLPE_4MHz   For VLPR (Core/Bus = 4MHz, Flash = 1MHz)
 */
#include "hardware.h"
#include "mcg.h"
#include "smc.h"

using namespace USBDM;

// Map clock settings for each mode to available settings
static constexpr unsigned ClockConfig_HSRUN = ClockConfig_PEE_120MHz;
static constexpr unsigned ClockConfig_RUN   = ClockConfig_PEE_80MHz;
static constexpr unsigned ClockConfig_VLPR  = ClockConfig_BLPE_4MHz;

//static constexpr unsigned ClockConfig_RUN   = ClockConfig_PEE_48MHz;

// LED connection - change as required
using Led   = GpioC<3>;

using namespace USBDM;

void report() {
   console.write("Run mode=");
   console.write(Smc::getSmcStatusName());
   console.write(", Clock =");
   console.write(Mcg::getClockModeName());
   console.write("@");
   console.write(::SystemCoreClock);
   console.writeln(" Hz").flushOutput();
}

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock = ").writeln(::SystemCoreClock);
   console.write("SystemBusClock  = ").writeln(::SystemBusClock);
   
   report();

   Smc::enablePowerModes(
         SmcVeryLowPower_Enable,
         SmcLowLeakageStop_Enable,
         SmcVeryLowLeakageStop_Enable,
         SmcHighSpeedRun_Enable);

   Led::setOutput();

   for (;;) {
      Led::toggle();
      /*
       * RUN -> VLPR
       * Change clock down then run mode
       */
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_VLPR]);
      console_setBaudRate(defaultBaudRate);
      Smc::enterRunMode(SmcRunMode_VeryLowPower);
      report();
      waitMS(1000);

      /*
       * VLPR -> RUN
       * Change mode then clock up
       */
      Smc::enterRunMode(SmcRunMode_Normal);
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_RUN]);
      console_setBaudRate(defaultBaudRate);
      report();
      waitMS(1000);

#ifdef SMC_PMPROT_AHSRUN
      /*
       * RUN -> HSRUN
       * Change mode then clock up
       */
      Smc::enterRunMode(SmcRunMode_HighSpeed);
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_HSRUN]);
      console_setBaudRate(defaultBaudRate);
      report();
      waitMS(1000);

      /*
       * HSRUN -> RUN
       * Change clock down then run mode
       */
      Mcg::clockTransition(McgInfo::clockInfo[ClockConfig_RUN]);
      Smc::enterRunMode(SmcRunMode_Normal);
      console_setBaudRate(defaultBaudRate);
      report();
      waitMS(1000);
#endif
   }
   return 0;
}
