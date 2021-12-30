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
#include "ftm.h"

using namespace USBDM;

/**
 * Demonstrates use of the PWM outputs
 *
 * Uses PWM to change the brightness of an LED
 */

// Connection mapping - change as required
using Timer  = Ftm0;
using PwmLed = Timer::Channel<0>;

int main() {

   // Configure base FTM for left-aligned PWM
   Timer::configure(
         FtmMode_LeftAlign,
         FtmClockSource_System);

   /*
    * Change PWM period
    * Note - Setting the period affects all channels of the FTM
    */
   Timer::setPeriod(5_us);

   // Configure channel as PWM high-pulses
   PwmLed::configure(FtmChMode_PwmHighTruePulses);

   // Configure pin associated with channel
   PwmLed::setOutput(PinDriveStrength_High, PinDriveMode_PushPull);

   // Check if configuration failed
   checkError();

   for(;;) {
      // Using percentage duty-cycle
      for (unsigned i=1; i<=99; i++) {
         PwmLed::setDutyCycle((int)i);
         waitMS(10);
         console.write("Duty = ").write(i).writeln(" %");
      }
      // Using high-time
      for (int i=99; i>0; i--) {
         PwmLed::setHighTime(i*(5_us/100.0));
         waitMS(10);
         console.write("High time = ").write(5*i).writeln(" us");
      }
   }
}
