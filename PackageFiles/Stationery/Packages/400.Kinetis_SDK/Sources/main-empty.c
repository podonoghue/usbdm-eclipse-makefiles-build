#include <string.h>
#include <stdio.h>
#include "board.h"
#include "fsl_device_registers.h"

/*!
 * @brief Main demo function - no defined hardware
 */
int main(void)
{
   // Initialise the hardware board
   hardware_init();

   printf("\r\n...main...\r\n");

    for(;;) {
       printf("...Tick...\r\n");
       __asm__("nop");
    }
}
