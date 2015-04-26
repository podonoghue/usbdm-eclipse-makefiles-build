#include <string.h>
#include <stdio.h>
#include "device/fsl_device_registers.h"

/*!
 * @brief Main demo function - no defined hardware
 */
int main(void)
{
   printf("\r\n...main...\r\n");

    for(;;) {
       printf("...Tick...\r\n");
       __asm__("nop");
    }
}
