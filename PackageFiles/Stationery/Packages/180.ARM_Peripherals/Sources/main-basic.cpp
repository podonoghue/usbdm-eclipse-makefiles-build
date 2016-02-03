/*
 ============================================================================
 * @file    main.c (derived from main-basic.cpp)
 * @brief   Basic C++ demo using GHPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "delay.h"

/**
 * See examples in Snippets directory
 */

// LED connection - change as required
using Led = USBDM::GpioB<3>;

int main() {
   Led::setOutput();
   Led::set();
   for(;;) {
      Led::toggle();
      USBDM::waitMS(100);
   }
   return 0;
}
