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
// Requires pin mapping to be changed - See pin_mapping.h
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

#if EXAMPLE == 4
#include "lptmr.h"

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

#if PIT_USES_NAKED_HANDLER == 1
/*
 * If using naked handler it must be named exactly as shown
 */
void PIT0_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
   RED_LED.toggle();
}
/*
 * If using naked handler it must be named exactly as shown
 */
void PIT1_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
   GREEN_LED.toggle();
}
/*
 * If using naked handler it must be named exactly as shown
 */
void PIT2_IRQHandler(void) {
   // Clear interrupt flag
   PIT->CHANNEL[2].TFLG = PIT_TFLG_TIF_MASK;
   BLUE_LED.toggle();
}
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
   if ((sizeof(PIT->CHANNEL)/sizeof(PIT->CHANNEL[0])) > 2) {
      if (PIT->CHANNEL[2].TFLG & PIT_TFLG_TIF_MASK) {
         // Clear interrupt flag
         PIT->CHANNEL[2].TFLG = PIT_TFLG_TIF_MASK;
         BLUE_LED.toggle();
      }
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

   // May need to change prescaler to get useful delays
   PIT_0.configure(1000);

#if PIT_USES_NAKED_HANDLER == 0
   // These handlers are set programmatically
   PIT_0.setCallback(0, flashRed);
   PIT_0.setCallback(1, flashGreen);
   if ((sizeof(PIT->CHANNEL)/sizeof(PIT->CHANNEL[0])) > 2) {
      PIT_0.setCallback(2, flashBlue);
   }
#endif

   // Flash RED @ 1Hz
   PIT_0.configureChannel(0, SystemBusClock/2);

   // Flash GREEN @ 0.5Hz
   PIT_0.configureChannel(1, SystemBusClock);

   if ((sizeof(PIT->CHANNEL)/sizeof(PIT->CHANNEL[0])) > 2) {
      // Flash BLUE @ 0.25Hz
      PIT_0.configureChannel(2, SystemBusClock*2);
   }
   else {
      BLUE_LED.set();
   }

   for(;;) {
      __asm__("nop");
   }
}
#endif
