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
 * Uses PWM to change the brightness of 2 LEDs
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
using LED1 = $(demo.cpp.pwm.led1:Ftm0Channel<0>);
using LED2 = $(demo.cpp.pwm.led2:Ftm0Channel<1>);

#ifdef MCU_MK64F12
#error "PWM is not available on LEDs"
#endif

#if 0
/**
 * Example showing how to install a custom IRQ handler for a TPM
 */
namespace USBDM {

template<> void TpmIrq_T<Tpm1Info>::irqHandler() {
   // Your code
}

}
#endif

int main() {
   LED1::enable();
   LED2::enable();

   // Change PWM period
//   LED1::configure(1000);
//   LED2::configure(1000);

   for(;;) {
      for (int i=0; i<=100; i++) {
         LED1::setDutyCycle(i);
         delay();
      }
      for (int i=0; i<=100; i++) {
         LED2::setDutyCycle(i);
         delay();
      }
   }
}
