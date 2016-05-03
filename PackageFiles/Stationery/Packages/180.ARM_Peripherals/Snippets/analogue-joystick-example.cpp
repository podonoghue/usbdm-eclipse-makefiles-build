/**
 * @file analogue-example.cpp
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
using JOYSTICK_X = $(demo.cpp.joystick.x:USBDM::Adc0<0>);
using JOYSTICK_Y = $(demo.cpp.joystick.y:USBDM::Adc0<1>);
using JOYSTICK_K = $(demo.cpp.joystick.k:USBDM::GpioB<0>);

int main(void) {
   JOYSTICK_X::enable();
   JOYSTICK_Y::enable();
   JOYSTICK_K::setInput();

   // May change default resolution e.g.
//   JOYSTICK_X::setMode(USBDM::resolution_8bit_se);
//   JOYSTICK_Y::setMode(USBDM::resolution_8bit_se);

   for(;;) {
      int  x = JOYSTICK_X::readAnalogue();
      int  y = JOYSTICK_Y::readAnalogue();
      bool k = JOYSTICK_K::read();
      printf("Joystick (X,Y,Z) = (%7d, %7d, %s)\n", x, y, k?"HIGH":"LOW");
   }
}
