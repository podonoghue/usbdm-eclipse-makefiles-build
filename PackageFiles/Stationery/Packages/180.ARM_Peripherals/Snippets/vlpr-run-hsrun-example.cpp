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
 *  - ClockConfig_BLPE_4MHz   For VLPR (Core/Bus = 4MHz, Flash = 800KHz)
 *
 *  It is also necessary to configure the CLKOUT Pin
 */
#include "hardware.h"
#include "mcg.h"
#include "smc.h"
#include "rcm.h"

using namespace USBDM;

// Map clock settings for each mode to available settings
#if defined(SMC_PMPROT_AHSRUN_MASK)
static constexpr ClockConfig ClockConfig_HSRUN = ClockConfig_PEE_120MHz;
#endif
static constexpr ClockConfig ClockConfig_RUN   = ClockConfig_PEE_80MHz;
static constexpr ClockConfig ClockConfig_VLPR  = ClockConfig_BLPE_4MHz;


void report() {
   checkError();
   console_setBaudRate(defaultBaudRate);
   console.writeln(
         "Run mode = ", Smc::getSmcStatusName(),
         ", Clock = ", Mcg::getClockModeName(),
         "@", SystemCoreClock, " Hz").flushOutput();
}

int main() {

   // Change clock so console (LPUART) will continue working
   SimInfo::setLpuartClock(SimLpuartClockSource_OscerClk);
   console.setBaudRate(defaultBaudRate);

   console.writeln("Starting\n");
   console.writeln("SystemCoreClock = ", SystemCoreClock);
   console.writeln("SystemBusClock  = ", SystemBusClock);

   console.writeln("Reset Source = ", Rcm::getResetSourceDescription()).flushOutput();

   // Monitor clock changes on CLKOUT pin
   ControlInfo::CLKOUT_pin::setOutput();
   SimInfo::setClkout(SimClkoutSel_FlexBusClk);

   report();

   Smc::enableAllPowerModes();

   for (;;) {
      /*
       * RUN -> VLPR
       */
      Smc::enterRunMode(ClockConfig_VLPR);
      report();
      wait(5_s);

      /*
       * VLPR -> RUN
       */
      Smc::enterRunMode(ClockConfig_RUN);
      report();
      wait(5_s);

#if defined(SMC_PMPROT_AHSRUN_MASK)
      /*
       * RUN -> HSRUN
       */
      Smc::enterRunMode(ClockConfig_HSRUN);
      report();
      wait(5_s);

      /*
       * HSRUN -> RUN
       */
      Smc::enterRunMode(ClockConfig_RUN);
      report();
      wait(5_s);
#endif
   }
   return 0;
}
