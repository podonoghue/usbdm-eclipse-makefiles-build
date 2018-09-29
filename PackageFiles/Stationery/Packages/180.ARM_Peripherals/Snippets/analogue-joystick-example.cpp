/**
 ============================================================================
 * @file analogue-joystick-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief Example showing use of a use of 2 ADC channels with a 2-pot joystick
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

using namespace USBDM;

/*
 * External Joy-stick
 * 2 x Analogue input
 * 1 x Digital input
 *
 */

// Connection mapping - change as required
using Adc = USBDM::Adc0;

using JOYSTICK_X = $(demo.cpp.joystick.x:Adc::Channel<0>);
using JOYSTICK_Y = $(demo.cpp.joystick.y:Adc::Channel<3>);
using JOYSTICK_K = $(demo.cpp.joystick.k:GpioC<3,ActiveLow>);

int main(void) {

   // Enable and configure ADC
   Adc::configure(AdcResolution_8bit_se);

   // Calibrate before use
   Adc::calibrate();

   JOYSTICK_K::setInput();

   for(;;) {
      int  x = JOYSTICK_X::readAnalogue();
      int  y = JOYSTICK_Y::readAnalogue();
      bool k = JOYSTICK_K::isPressed();
      console.write("Joystick (X,Y,K) = ").write(x).write(", ").write(y).write(", ").writeln(k?"Pressed":"Released");
   }
}
