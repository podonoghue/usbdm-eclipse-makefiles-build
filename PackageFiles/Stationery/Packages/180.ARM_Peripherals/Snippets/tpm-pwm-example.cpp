/**
 ============================================================================
 * @file    tpm-pwm-example.cpp
 * @brief   Demo using Ftm class to implement a basic PWM output
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

using namespace USBDM;

/**
 * Demonstrates use of the PWM outputs
 *
 * Uses PWM to change the brightness of an LED
 */

// Connection mapping - change as required
using Timer = $(demo.cpp.tpm:Tpm2);
using Led   = $(demo.cpp.pwm.led1:Tpm2Channel<0>);

int main() {

   // Configure base TPM for left-aligned PWM
   Timer::configure(
         TpmMode_LeftAlign,
         TpmClockSource_Internal);

   /*
    * Change PWM period
    * Note - Setting the period affects all channels of the Timer
    */
   Timer::setPeriod(5*us);

   // Configure channel as high-pulses
   Led::configure(TpmChMode_PwmHighTruePulses);

   // Configure pin associated with channel
   Led::setDriveStrength(PinDriveStrength_High);
   Led::setDriveMode(PinDriveMode_PushPull);

   // Check if configuration failed
   checkError();

   for(;;) {
      // Using percentage duty-cycle
      for (int i=1; i<=99; i++) {
         Led::setDutyCycle(i);
         waitMS(10);
      }
      // Using high-time
      for (int i=99; i>0; i--) {
         Led::setHighTime((i*5*us)/100.0);
         waitMS(10);
      }
   }
}
