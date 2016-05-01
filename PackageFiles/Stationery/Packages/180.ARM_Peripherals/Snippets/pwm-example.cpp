/**
 * @file pwm-example.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"

using namespace USBDM;

/**
 * Demonstrates use of the PWM outputs
 *
 * Uses PWM to change the brightness of 3 LEDs
 *
 */

// Simple delay - not for real programs!
static void delay(void) {
   for(int i=0; i<400000; i++) {
      __asm__("nop");
   }
}

/*
 * This example is not supported on all targets as PWM feature may not be available
 * on the pins connected to the LEDs (e.g. K64F).
 *
 * The mapping of pins in pin_mapping.h may need to be changed to map PWM to LEDs as
 * preference was given to mapping to external pins on board (e.g. KL25Z).
 *
 */
// Connection mapping - change as required
using RED_LED   = $(demo.cpp.pwm.red.led:Ftm0<0>);
using GREEN_LED = $(demo.cpp.pwm.green.led:Ftm0<1>);

#ifdef MCU_MK64F12
#error "PWM is not available on LEDs"
#endif

#if 0
/**
 * Example showing how to install a custom IRQ handler for a FTM
 */
namespace USBDM {

template<> void FtmIrq_T<Ftm0Info>::irqHandler() {
   // Your code
}

}
#endif

int main() {
   RED_LED::enable();
   GREEN_LED::enable();

   // Change PWM period
//   RED_LED::configure(1000);
//   GREEN_LED::configure(1000);

   for(;;) {
      for (int i=0; i<=100; i++) {
         RED_LED::setDutyCycle(i);
         delay();
      }
      for (int i=0; i<=100; i++) {
         GREEN_LED::setDutyCycle(i);
         delay();
      }
   }
}
