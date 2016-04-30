/*
 ============================================================================
 * main-MK.c
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "pin_mapping.h"

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

// Simple delay - not for real programs!
static void delay(void) {
   for(int i=0; i<400000; i++) {
      __asm__("nop");
   }
}

// LED connections
#define RED_LED   USBDM::gpio_$(demo.cpp.red.led)
#define GREEN_LED USBDM::gpio_$(demo.cpp.green.led)

int main() {
   RED_LED::setOutput();
   GREEN_LED::setOutput();
   RED_LED::set();
   GREEN_LED::set();
   for(;;) {
      RED_LED::toggle();
      delay();
      RED_LED::toggle();
      delay();
      GREEN_LED::toggle();
      delay();
      GREEN_LED::toggle();
      delay();
   }
   return 0;
}
