/*
 ============================================================================
 * @file    cmp.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using CMP class
 *
 * It will be necessary to configure the CMP in the configuration
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

#include "cmp.h"

// Connections - change as required
using Cmp   = USBDM::Cmp0;

// Led to control
using Led   = USBDM::gpio_LED_RED;

/**
 * Comparator callback
 *
 * @param status Status from cmp.SCR (only CFR, CFF flags)
 */
void callback(int status) {
   if (status & CMP_SCR_CFR_MASK) {
      // Rising edge
      Led::low();
   }
   else if (status & CMP_SCR_CFF_MASK) {
      // Falling edge
      Led::high();
   }
#ifdef DEBUG_BUILD
   else {
      // Unexpected
      __BKPT();
   }
#endif
}

int main() {
//   printf("Starting\n");

//   printf("SystemBusClock  = %ld\n", SystemBusClock);
//   printf("SystemCoreClock = %ld\n", SystemCoreClock);

   // LED initially off (active low)
   Led::setOutput();
   Led::high();

   // Enable comparator before use
   Cmp::enable();

   // Internal DAC used for one input - set level
   Cmp::setDacLevel(20);

   // Set callback to execute on event
   Cmp::setCallback(callback);

   // Set Comparator inputs (CMP_IN0, DAC)
   Cmp::selectInputs(0, 7);

   // Enable interrupts on Rising and Falling edges
   Cmp::enableFallingEdgeInterrupts(true);
   Cmp::enableRisingEdgeInterrupts(true);

   for(;;) {
//      Led::toggle();
      USBDM::waitMS(100);
//      printf("Tick\n");
   }
   return 0;
}
