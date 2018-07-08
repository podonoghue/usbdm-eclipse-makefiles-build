/*
 ============================================================================
 * @file    mcg-lite-test.cpp
 * @brief   Test Mcg Lite configuration
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "mcg.h"

/**
 * Test MCG Lite
 */

// LED connection - change as required
using Led   = $(demo.cpp.led:USBDM::GpioB<3>);

int main() {

   console.write(" SystemCoreClock = ".writeln(::SystemCoreClock);
   console.write(" SystemBusClock  = ".writeln(::SystemBusClock);

   // These clocks are updated when the clock configuration changes
   console.write(" USBDM::SystemCoreClock       = ".writeln(USBDM::SystemCoreClock);
   console.write(" USBDM::SystemBusClock        = ".writeln(USBDM::SystemBusClock);
   console.write(" USBDM::SystemLpoClock        = ".writeln(USBDM::SystemLpoClock);

   // These clocks are determined dynamically
   console.write(" USBDM::SystemMcgOutClock     = ".writeln(USBDM::McgInfo::getMcgOutClock());
   console.write(" USBDM::SystemMcgirClock      = ".writeln(USBDM::McgInfo::getMcgIrClock());
   console.write(" USBDM::SystemPeripheralClock = ".writeln(USBDM::SimInfo::getPeripheralClock());
   console.write(" USBDM::SystemOscerClock      = ".writeln(USBDM::Osc0Info::getOscerClock());
   console.write(" USBDM::SystemErclk32kClock   = ".writeln(USBDM::SimInfo::getErc32kClock());

   for(;;){

   }
}
