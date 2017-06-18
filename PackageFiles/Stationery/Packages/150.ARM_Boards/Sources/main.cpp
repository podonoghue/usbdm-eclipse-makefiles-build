/*
 ============================================================================
 * @file main.cpp (150.ARM_Boards/Sources/main.cpp)
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */

#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "utilities.h"
#include "leds.h"
#include "delay.h"

int main(void) {

   volatile int count = 0;

   led_initialise();

//   printf("SystemBusClock  = %ld\n", SystemBusClock);
//   printf("SystemCoreClock = %ld\n", SystemCoreClock);

   // Real programs never die!
   for(;;) {
      count++;
      greenLedToggle();
//      printf("Count = %d\n", count);
      USBDM::waitMS(100);
   }
   return 0;
}
