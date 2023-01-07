/*
 ============================================================================
 * @file    mcg-test.c
 * @brief   Test Mcg configuration
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "mcg.h"

/**
 * Test MCG
 */

using namespace USBDM;

int main() {

   // These clocks are updated when the clock configuration changes
   console.write(" SystemCoreClock       = ").writeln(SystemCoreClock);
   console.write(" SystemBusClock        = ").writeln(SystemBusClock);
   console.write(" SystemMcgFFClock      = ").writeln(SystemMcgFFClock);
   console.write(" SystemMcgFllClock     = ").writeln(SystemMcgFllClock);
   console.write(" SystemMcgPllClock     = ").writeln(SystemMcgPllClock);
   console.write(" SystemMcgOutClock     = ").writeln(SystemMcgOutClock);
//   console.write(" SystemLpoClock        = ").writeln(SystemLpoClock);

   // These clocks are determined dynamically
   console.write(" McgirClock      = ").writeln(McgInfo::getMcgIrClock());
   console.write(" PeripheralClock = ").writeln(SimInfo::getPeripheralClock());
   console.write(" OscerClock      = ").writeln(Osc0Info::getOscerClock());
   console.write(" Erclk32kClock   = ").writeln(SimInfo::getErc32kClock());
   console.write(" LpoClock        = ").writeln(PmcInfo::getLpoClock());

   for(;;){

   }
}
