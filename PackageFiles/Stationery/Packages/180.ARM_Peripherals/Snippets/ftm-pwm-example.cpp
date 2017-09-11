/**
 ============================================================================
 * @file    ftm-pwm-example.cpp
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
using Timer = Ftm0;
using Led   = Ftm0Channel<7>;

int main() {
   // Configure base FTM for left-aligned PWM
   Timer::configure(
         FtmMode_LeftAlign,
         FtmClockSource_System,
         FtmPrescale_1
   );

   /*
    * Change PWM period
    * Note - Setting the period of Led affects all channels on the same FTM
    */
   Timer::setPeriod(5*us);

   // Configure channel as high-pulses
   Led::configure(FtmChMode_PwmHighTruePulses);

   // Configure pin associated with channel
   Led::setDriveStrength(PinDriveStrength_High);
   Led::setDriveMode(PinDriveMode_PushPull);

   // Check if configuration failed
   USBDM::checkError();

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
