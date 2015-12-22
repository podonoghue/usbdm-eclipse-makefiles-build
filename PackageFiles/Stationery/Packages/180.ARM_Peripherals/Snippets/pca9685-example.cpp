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
#include "gpio.h"
#include "pca9685.h"
/**
 * See examples in Snippets directory
 */

// LED connections
#define RED_LED   USBDM::gpio_LED_RED
#define GREEN_LED USBDM::gpio_LED_GREEN

int main() {

   USBDM::I2c     *i2c     = new USBDM::I2c0();
   USBDM::PCA9685 *pca9685 = new USBDM::PCA9685(i2c);

   pca9685->set_pin_high(3);
   pca9685->set_pin_pwm(3, 50);

   bool odd=true;
   for (;;) {
      odd = !odd;
      for (int i=0; i<15; i++) {
         if (odd) {
            pca9685->set_pin_high(i);
         }
         else {
            pca9685->set_pin_low(i);
         }
      }
   }
//   RED_LED::setOutput();
//   GREEN_LED::setOutput();
//   RED_LED::set();
//   GREEN_LED::set();
//   for(;;) {
//      RED_LED::toggle();
//      delay();
//      RED_LED::toggle();
//      delay();
//      GREEN_LED::toggle();
//      delay();
//      GREEN_LED::toggle();
//      delay();
//   }
}
