/*
 ============================================================================
 * main-MKL.c
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "utilities.h"
#include "gpio.h"
#include "examples.h"

// Simple delay - not for real programs!
void delay(void) {
   for(int i=0; i<400000; i++) {
      __asm__("nop");
   }
}

void shortDelay(void) {
   for(int i=0; i<400; i++) {
      __asm__("nop");
   }
}

#if EXAMPLE == 0
// LED connections
#define RED_LED   digitalIO_$(demo.cpp.red.led)
#define GREEN_LED digitalIO_$(demo.cpp.green.led)
#define BLUE_LED  digitalIO_$(demo.cpp.blue.led)

int main() {
   RED_LED.setDigitalOutput();
   GREEN_LED.setDigitalOutput();
   BLUE_LED.setDigitalOutput();
   RED_LED.set();
   GREEN_LED.set();
   BLUE_LED.set();
   for(;;) {
      RED_LED.toggle();
      delay();
      RED_LED.toggle();
      delay();
      GREEN_LED.toggle();
      delay();
      GREEN_LED.toggle();
      delay();
      BLUE_LED.toggle();
      delay();
      BLUE_LED.toggle();
      delay();
   }
}
#endif

#if EXAMPLE == 1
/*
 * This example if not supported on all targets as PWM feature may not be available
 * on the pins connected to the LEDs (e.g. K64F).
 *
 * The mapping of pins in pin_mapping.h may need to be changed to map PWM to LEDs as
 * preference was given to mapping to external pins on board (e.g. KL25Z).
 *
 */
 // LED connections
#define RED_LED   pwmIO_$(demo.cpp.red.led)
#define GREEN_LED pwmIO_$(demo.cpp.green.led)
#define BLUE_LED  pwmIO_$(demo.cpp.blue.led)

#ifdef MCU_MK64F12
#error "PWM is not available on LEDs"
#endif

int main() {
   RED_LED.setPwmOutput(2000,   PwmIO::ftm_leftAlign);
   GREEN_LED.setPwmOutput(2000, PwmIO::ftm_leftAlign);
   BLUE_LED.setPwmOutput(2000,  PwmIO::ftm_leftAlign);
   for(;;) {
      for (int i=0; i<=100; i++) {
         RED_LED.setDutyCycle(i);
         delay();
      }
      for (int i=0; i<=100; i++) {
         GREEN_LED.setDutyCycle(i);
         delay();
      }
      for (int i=0; i<=100; i++) {
         BLUE_LED.setDutyCycle(i);
         delay();
      }
   }
}
#endif

#if EXAMPLE == 2
// Joystick
// 2 x Analogue input
// 1 x Digital input

// Connection mapping
#define JOYSTICK_X   analogueIO_$(demo.cpp.joystick.x)
#define JOYSTICK_Y   analogueIO_$(demo.cpp.joystick.y)
#define JOYSTICK_K   digitalIO_$(demo.cpp.joystick.z)

int main(void) {
   JOYSTICK_X.setAnalogueInput();
   JOYSTICK_Y.setAnalogueInput();
   JOYSTICK_K.setDigitalInput();

   for(;;) {
      int  x = JOYSTICK_X.readAnalogue();
      int  y = JOYSTICK_Y.readAnalogue();
      bool k = JOYSTICK_K.read();
      printf("Joystick (X,Y,Z) = (%7d, %7d, %s)\n", x, y, k?"HIGH":"LOW");
      delay();
   }
}
#endif

#if EXAMPLE == 3
// SWITCH + LED
// 1 x Digital input
// 1 x Digital output

// Connection mapping
#define SWITCH    digitalIO_$(demo.cpp.external.switch)
#define LED       digitalIO_$(demo.cpp.external.led)

int main(void) {
   LED.setDigitalOutput();
   SWITCH.setDigitalInput();

   for(;;) {
      LED.write(!SWITCH.read());
   }
}
#endif

#if EXAMPLE == 4
#include "lptmr.h"

// LED connections
#define RED_LED   digitalIO_$(demo.cpp.red.led)
#define GREEN_LED digitalIO_$(demo.cpp.green.led)
#define BLUE_LED  digitalIO_$(demo.cpp.blue.led)

#if LPTMR_USES_NAKED_HANDLER == 1
/*
 * If using naked handler it must be named exactly as shown
 */
void LPTMR0_IRQHandler(void) {
   // Clear interrupt flag
   LPTMR0->CSR |= LPTMR_CSR_TCF_MASK;
   RED_LED.toggle();
}
#else
/*
 * This handler is set programmatically
 */
void flash(void) {
   RED_LED.toggle();
}
#endif

int main() {
   RED_LED.setDigitalOutput();

   // May need to change prescaler to get useful delays
   LPTMR_0.configure(1000, LPTMR_CSR_DEFAULT_VALUE|LPTMR_CSR_TIE_MASK);
   
#if LPTMR_USES_NAKED_HANDLER == 0
   // This handler is set programmatically
   LPTMR_0.setCallback(flash);
#endif

   for(;;) {
      // This is required so that the CNR visibly updates in debugger
      LPTMR0->CNR = 0;
      __asm__("nop");
   }
}
#endif

#if EXAMPLE == 5
#include "pit.h"

// LED connections
#define RED_LED   digitalIO_$(demo.cpp.red.led)
#define GREEN_LED digitalIO_$(demo.cpp.green.led)
#define BLUE_LED  digitalIO_$(demo.cpp.blue.led)

#if PIT_USES_NAKED_HANDLER == 1
/*
 * If using naked handler it must be named exactly as shown
 * MKL version - shared handler for all PIT channels
 */
void PIT_IRQHandler(void) {
   if (PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
      RED_LED.toggle();
   }
   if (PIT->CHANNEL[1].TFLG & PIT_TFLG_TIF_MASK) {
      // Clear interrupt flag
      PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
      GREEN_LED.toggle();
   }
}
#else
/*
 * These handlers are set programmatically
 */
void flashRed(void) {
   RED_LED.toggle();
}
void flashGreen(void) {
   GREEN_LED.toggle();
}
void flashBlue(void) {
   BLUE_LED.toggle();
}
#endif

int main() {
   RED_LED.setDigitalOutput();
   GREEN_LED.setDigitalOutput();
   BLUE_LED.setDigitalOutput();

   // Turn off LED initially
   RED_LED.set();
   GREEN_LED.set();
   BLUE_LED.set();

   PIT_0.configure();

#if PIT_USES_NAKED_HANDLER == 0
   // These handlers are set programmatically
   PIT_0.setCallback(0, flashRed);
   PIT_0.setCallback(1, flashGreen);
#endif

   // Flash RED @ 1Hz
   PIT_0.configureChannel(0, SystemBusClock/2);

   // Flash GREEN @ 0.5Hz
   PIT_0.configureChannel(1, SystemBusClock);

   for(;;) {
      __asm__("nop");
   }
}
#endif

#if EXAMPLE == 6
#include "pit.h"

// LED connections
#define RED_LED   digitalIO_$(demo.cpp.red.led)
#define GREEN_LED digitalIO_$(demo.cpp.green.led)
#define BLUE_LED  digitalIO_$(demo.cpp.blue.led)

int main() {
   RED_LED.setDigitalOutput();
   GREEN_LED.setDigitalOutput();
   BLUE_LED.setDigitalOutput();

   // Turn off LED initially
   RED_LED.set();
   GREEN_LED.set();
   BLUE_LED.set();

   PIT_0.configure();

   for(;;) {
      RED_LED.toggle();
      PIT_0.delay(0, SystemBusClock*1);
   }
}
#endif

