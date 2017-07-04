/**
 ============================================================================
 * @file    ftm-pwm-example.cpp
 * @brief   Demo using Ftm class to implement a basic PWM output
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"

using namespace USBDM;

/**
 * Demonstrates use of the PWM outputs
 *
 * Uses PWM to change the brightness of an LED
 */

// Simple delay - not for real programs!
static void delay(void) {
   for(int i=0; i<400000; i++) {
      __asm__("nop");
   }
}

/*
 * This example is not supported on all targets as PWM feature may not be available
 * on the pins connected to the LEDs (e.g. K64F).
 *
 * The mapping of pins may need to be changed to map PWM to LEDs as
 * preference was given to mapping to external pins on board (e.g. KL25Z).
 *
 */
// Connection mapping - change as required
using LED1 = $(demo.cpp.pwm.led1:Ftm0Channel<7>);

#ifdef MCU_MK64F12
#error "PWM is not available on LEDs"
#endif

#if 0
/**
 * Example showing how to install a custom IRQ handler for a FTM
 */
namespace USBDM {

template<> void FtmIrq_T<Ftm0Info>::irqHandler() {
   // Your code
   __asm__("nop");
}

}
#endif

int main() {
   LED1::enable();
   LED1::setDriveStrength(PinDriveStrengthHigh);

   /*
    * Change PWM period
    * Note - Setting the period of LED1 affects all channels on the same FTM
    */
   LED1::setPeriod(5*us);

   // Check for error so far
   checkError();

   for(;;) {
      for (int i=1; i<=99; i++) {
         LED1::setDutyCycle(i);
         delay();
      }
      for (int i=99; i>0; i--) {
         LED1::setDutyCycle(i);
         delay();
      }
   }
}
