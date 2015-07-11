/*
 ============================================================================
 * main.c
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "utilities.h"
#include "GPIO.h"

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

#define EXAMPLE 0

#if EXAMPLE == 0

#ifdef MCU_MKL25Z4
#define RED_LED   digitalIO_PTB18
#define GREEN_LED digitalIO_PTB19
#define BLUE_LED  digitalIO_PTD1
#endif
#ifdef MCU_MK20D5
#define RED_LED   digitalIO_PTC3
#define GREEN_LED digitalIO_PTD4
#define BLUE_LED  digitalIO_PTA2
#endif
#ifdef MCU_MK22F51212
#define RED_LED   digitalIO_PTA1
#define GREEN_LED digitalIO_PTA2
#define BLUE_LED  digitalIO_PTD5
#endif
#ifdef MCU_MK64F12
#define RED_LED   digitalIO_PTB22
#define GREEN_LED digitalIO_PTE26
#define BLUE_LED  digitalIO_PTB21
#endif

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

#ifdef MCU_MKL25Z4
// Requires pin mapping to be changed - See PinMapping.h
#define RED_LED   pwmIO_PTB18
#define GREEN_LED pwmIO_PTB19
#define BLUE_LED  pwmIO_PTD1
#endif
#ifdef MCU_MK20D5
#define RED_LED   pwmIO_PTC3
#define GREEN_LED pwmIO_PTD4
#define BLUE_LED  pwmIO_PTA2
#endif
#ifdef MCU_MK22F51212
#define BLUE_LED  pwmIO_PTA1
#define RED_LED   pwmIO_PTA2
#define GREEN_LED pwmIO_PTD5
#endif
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
#define JOYSTICK_X   analogueIO_A2
#define JOYSTICK_Y   analogueIO_A1
#define JOYSTICK_K   digitalIO_A0

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
#define SWITCH    digitalIO_D12
#define LED       digitalIO_D13

int main(void) {
   LED.setDigitalOutput();
   SWITCH.setDigitalInput();

   for(;;) {
      LED.write(!SWITCH.read());
   }
}
#endif
