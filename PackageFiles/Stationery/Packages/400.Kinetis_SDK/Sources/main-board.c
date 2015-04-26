#include <string.h>
#include <stdio.h>
#include <board.h>

/**
 * Simple delay function
 */
void delay() {
   for (int i=0; i<10000; i++) {
      __asm__("nop");
   }
}

/*!
 * @brief Main demo function for a bare board
 */
int main(void)
{
   // Initialise the hardware board
   hardware_init();

   // Initialise the debug UART
   dbg_uart_init();

   printf("\r\n...main...\r\n");

   LED1_EN;
   for(;;) {
      printf("...Tick...\r\n");
      LED1_ON;
      delay();
      LED1_OFF;
      delay();
   }
}
