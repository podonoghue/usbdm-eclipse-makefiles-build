/*
 ============================================================================
 * @file    test-mcg.c
 * @brief   Test Mcg configuration
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
 * Test MCG
 */

// LED connection - change as required
using Led   = USBDM::GpioC<3>;

int main() {

   printf(" SystemCoreClock = %ld\n", ::SystemCoreClock);
   printf(" SystemBusClock  = %ld\n", ::SystemBusClock);

   // These clocks are updated when the clock configuration changes
   printf(" USBDM::SystemCoreClock       = %ld\n", USBDM::SystemCoreClock);
   printf(" USBDM::SystemBusClock        = %ld\n", USBDM::SystemBusClock);
   printf(" USBDM::SystemMcgffClock      = %ld\n", USBDM::SystemMcgffClock);
   printf(" USBDM::SystemMcgFllClock     = %ld\n", USBDM::SystemMcgFllClock);
   printf(" USBDM::SystemMcgPllClock     = %ld\n", USBDM::SystemMcgPllClock);
   printf(" USBDM::SystemMcgOutClock     = %ld\n", USBDM::SystemMcgOutClock);
   printf(" USBDM::SystemLpoClock        = %ld\n", USBDM::SystemLpoClock);

   // These clocks are determined dynamically
   printf(" USBDM::SystemMcgirClock      = %ld\n", USBDM::McgInfo::getMcgIrClock());
   printf(" USBDM::SystemPeripheralClock = %ld\n", USBDM::SimInfo::getPeripheralClock());
   printf(" USBDM::SystemOscerClock      = %ld\n", USBDM::Osc0Info::getOscerClock());
   printf(" USBDM::SystemErclk32kClock   = %ld\n", USBDM::SimInfo::getErc32kClock());

   for(;;){

   }
}
