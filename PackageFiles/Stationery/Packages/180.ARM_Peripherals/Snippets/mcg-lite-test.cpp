/*
 ============================================================================
 * @file    test-mcglite.c
 * @brief   Test Mcg Lite configuration
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
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

   printf(" SystemCoreClock = %ld\n", ::SystemCoreClock);
   printf(" SystemBusClock  = %ld\n", ::SystemBusClock);

   // These clocks are updated when the clock configuration changes
   printf(" USBDM::SystemCoreClock       = %ld\n", USBDM::SystemCoreClock);
   printf(" USBDM::SystemBusClock        = %ld\n", USBDM::SystemBusClock);
   printf(" USBDM::SystemLpoClock        = %ld\n", USBDM::SystemLpoClock);

   // These clocks are determined dynamically
   printf(" USBDM::SystemMcgOutClock     = %ld\n", USBDM::McgInfo::getMcgOutClock());
   printf(" USBDM::SystemMcgirClock      = %ld\n", USBDM::McgInfo::getMcgIrClock());
   printf(" USBDM::SystemPeripheralClock = %ld\n", USBDM::SimInfo::getPeripheralClock());
   printf(" USBDM::SystemOscerClock      = %ld\n", USBDM::Osc0Info::getOscerClock());
   printf(" USBDM::SystemErclk32kClock   = %ld\n", USBDM::SimInfo::getErc32kClock());

   for(;;){

   }
}
