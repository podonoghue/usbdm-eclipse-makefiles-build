#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"

using namespace USBDM;

/**
 * Demonstrates use of the PWM outputs
 *
 * Uses PWM to change the brightness of 3 LEDs
 *
 */

// Simple delay - not for real programs!
void delay(void) {
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
 // LED connections
#define RED_LED   ftm_$(demo.cpp.red.led)
#define GREEN_LED ftm_$(demo.cpp.green.led)

#ifdef MCU_MK64F12
#error "PWM is not available on LEDs"
#endif

int main() {
   RED_LED.setPwmOutput(2000,   ftm_leftAlign);
   GREEN_LED.setPwmOutput(2000, ftm_leftAlign);
   for(;;) {
      for (int i=0; i<=100; i++) {
         RED_LED.setDutyCycle(i);
         delay();
      }
      for (int i=0; i<=100; i++) {
         GREEN_LED.setDutyCycle(i);
         delay();
      }
   }
}
