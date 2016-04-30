/*
 ============================================================================
 * @file    main.c (derived from main-basic.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"

/**
 * See more examples in Snippets directory
 *
 * Using a timer channel
 *   using ftmChannel = USBDM::Ftm0Channel<0>;
 *   ftmChannel::setMode(1000, USBDM::tmr_leftAlign);
 *   ftmChannel::setDutyCycle(25);
 *
 * Using a ADC channel
 *   using adcChannel = USBDM::Adc0Channel<4>;
 *   adcChannel::setMode(USBDM::resolution_16bit_se);
 *   int value = adcChannel::readAnalogue();
 */

// LED connection - change as required
using Led   = $(demo.cpp.led:USBDM::GpioB<3>);

int main() {
   Led::setOutput();
   for(;;) {
      Led::toggle();
      USBDM::waitMS(100);
   }
   return 0;
}
