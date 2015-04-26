/*
 ============================================================================
 Name        : RTX_Main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : Basic C Main
 ============================================================================
 */
#include <stdio.h>

#include "derivative.h"
#include "utilities.h"
#include "cmsis_os.h"
//#include "leds.h"

// Forward references
void threadFunction(void const *argument);    // prototype for thread function

//! Thread IDs
osThreadId mainFunctionId;
osThreadId threadFunctionId;

//! Thread definition
osThreadDef(threadFunction, osPriorityNormal, 1, 0);

#define SIGNAL_MASK (1<<2) // Arbitrary signal mask used for communication

/*!
 * Function representing a different thread of execution
 *
 * @param argument pointer to arbitrary object passed from thread creation
 *
 */
void threadFunction(void const *argument) {
   (void) argument;
   for (;;) {

   // Signal to main thread
   osSignalSet(mainFunctionId, SIGNAL_MASK);

   // Pause for 1 s
   osDelay(1000);
   }
}

/*!
 * Main function - forms main thread
 *
 */
int main(void) {

   // Get main thread ID
   mainFunctionId = osThreadGetId();

   // Create thread
   threadFunctionId = osThreadCreate(osThread(threadFunction), NULL);
   if (threadFunctionId == NULL) {
      __asm__("bkpt");
   }

// Need suitable features for the stdio & leds
//   printf("Main thread ID = %d\n", (int)mainFunctionId);
//   printf("Thread ID      = %d\n", (int)threadFunctionId);

//   led_initialise();

   for (;;) {
      // Wait for signal from thread
      osSignalWait(SIGNAL_MASK, osWaitForever);

//      printf("Thread signaled\n");
//      greenLedToggle();
   }

}
