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
   // Configure base FTM for left-aligned PWM
   LED1::Ftm::configure(FtmMode_LeftAlign);
   // Configure channel as high-pulses
   LED1::configure(FtmChMode_PwmHighTruePulses);
   // Set high-drive on pin
   LED1::setDriveStrength(PinDriveStrength_High);

   /*
    * Change PWM period
    * Note - Setting the period of LED1 affects all channels on the same FTM
    */
   LED1::setPeriod(5*us);

   // Check if configuration failed
   USBDM::checkError();

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
