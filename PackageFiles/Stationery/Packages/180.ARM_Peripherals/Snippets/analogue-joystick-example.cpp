/**
 ============================================================================
 * @file analogue-joystick-example.cpp
 * @brief Example showing use of a use of 2 ADC channels with a 2-pot joystick
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

/*
 * External Joy-stick
 * 2 x Analogue input
 * 1 x Digital input
 *
 */

// Connection mapping - change as required
using adc = USBDM::Adc0;
using JOYSTICK_X = $(demo.cpp.joystick.x:USBDM::Adc0Channel<0>);
using JOYSTICK_Y = $(demo.cpp.joystick.y:USBDM::Adc0Channel<3>);
using JOYSTICK_K = $(demo.cpp.joystick.k:USBDM::GpioC<3>);

int main(void) {

   // Enable and configure ADC
   adc::configure(AdcResolution_8bit_se);

   // Calibrate before use
   adc::calibrate();

   JOYSTICK_K::setInput();

   for(;;) {
      int  x = JOYSTICK_X::readAnalogue();
      int  y = JOYSTICK_Y::readAnalogue();
      bool k = JOYSTICK_K::read();
      printf("Joystick (X,Y,Z) = (%7d, %7d, %s)\n", x, y, k?"HIGH":"LOW");
   }
}
