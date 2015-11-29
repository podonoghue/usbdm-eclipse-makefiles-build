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

// Connection mapping
#define JOYSTICK_X   adc_A2
#define JOYSTICK_Y   adc_A1
#define JOYSTICK_K   adc_A0

int main(void) {
   JOYSTICK_X.setAnalogueInput();
   JOYSTICK_Y.setAnalogueInput();
   JOYSTICK_K.setDigitalInput();

   for(;;) {
      int  x = JOYSTICK_X.readAnalogue();
      int  y = JOYSTICK_Y.readAnalogue();
      bool k = JOYSTICK_K.read();
      printf("Joystick (X,Y,Z) = (%7d, %7d, %s)\n", x, y, k?"HIGH":"LOW");
   }
}
