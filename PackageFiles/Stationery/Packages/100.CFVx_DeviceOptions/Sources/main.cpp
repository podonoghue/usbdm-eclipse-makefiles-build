/*
 ============================================================================
 Description : Basic CPP Main
 ============================================================================
 */
#include "derivative.h"
#include "utilities.h"

volatile int count = 0;

/*
 * Example use of interrupt handler
 *
 * See vectors.c for interrupt names
 */
extern "C" __attribute__((__interrupt__))
void AccessError_Handler(void) {
   for(;;) {
      __breakpoint();
   }
}

int main(void) {

   for(count =0; count < 100; count++) {
      __asm__("nop");
   }
   // Generate Access error (interrupt handler demonstration)
   // (*(unsigned int *) 101) = 100;

   // Real programs never die!
   for(;;) {
      __asm__("nop");
   }
}
