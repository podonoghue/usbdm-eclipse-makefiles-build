/*
 * delme.cpp
 *
 *  Created on: 30 Sep. 2021
 *      Author: peter
 */
#include "hardware.h"
using namespace USBDM;

void doStuff(const Gpio &led, const GpioField &leds) {
   volatile uint32_t temp;

   led.off();
   led.setActive();
   led.setInactive();
   led.toggle();
   temp = led.read();
   temp = led.readState();
   led.write(false);
   led.write(true);

   leds.write(0b00);
   leds.bitToggle(0b11);
   temp = leds.read();
   temp = leds.readState();
   leds.write(0b10);

   (void) temp;
}
