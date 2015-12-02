/**
 * @file digital-example2.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"

using namespace USBDM;

/*
 * Simple Digital I/O example
 *
 * Echos an external switch to an external LED
 * Uses arduino aliases
 *
 *  SWITCH + LED
 *  1 x Digital input
 *  1 x Digital output
 *
 */

// Connection mapping
#define SWITCH    gpio_D12
#define LED       gpio_D13

int main(void) {
   LED::setOutput();
   SWITCH::setInput();

   for(;;) {
      LED::write(!SWITCH::read());
   }
}
