/**
 * @file analogue-example.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"

using namespace USBDM;

/*
 * External Joy-stick
 * 2 x Analogue input
 * 1 x Digital input
 *
 */

// Connection mapping - change as required
using JOYSTICK_X = $(demo.cpp.joystick.x:USBDM::Adc0<0>);
using JOYSTICK_Y = $(demo.cpp.joystick.y:USBDM::Adc0<1>);
using JOYSTICK_K = $(demo.cpp.joystick.k:USBDM::GpioB<0>);

int main(void) {
   JOYSTICK_X::setMode();
   JOYSTICK_Y::setMode();
   JOYSTICK_K::setInput();

   for(;;) {
      int  x = JOYSTICK_X::readAnalogue();
      int  y = JOYSTICK_Y::readAnalogue();
      bool k = JOYSTICK_K::read();
      printf("Joystick (X,Y,Z) = (%7d, %7d, %s)\n", x, y, k?"HIGH":"LOW");
   }
}
