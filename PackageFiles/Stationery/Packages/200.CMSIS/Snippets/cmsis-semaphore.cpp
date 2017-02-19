/*----------------------------------------------------------------------------
 * RTX example program - Semaphores
 *
 * Based on examples at https://developer.mbed.org/handbook/CMSIS-RTOS
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

#include "cmsis_os.h"                   // CMSIS RTX
#include "hardware.h"                   // Hardware interface

// Directly access USBDM routines
using namespace USBDM;

osSemaphoreId two_slots;
osSemaphoreDef(two_slots);

void test_thread(void const *name) {
    while (true) {
        osSemaphoreWait(two_slots, osWaitForever);
        printf("%s\n\r", (const char*)name);
        osDelay(1000);
        osSemaphoreRelease(two_slots);
    }
}

void t2(void const *) {
   test_thread("Th 2");
}
osThreadDef(t2, osPriorityNormal, 1, 0);

void t3(void const *) {
   test_thread("Th 3");
}
osThreadDef(t3, osPriorityNormal, 1, 0);

int main (void) {
    two_slots = osSemaphoreCreate(osSemaphore(two_slots), 2);

    osThreadCreate(osThread(t2), NULL);
    osThreadCreate(osThread(t3), NULL);

    test_thread((void *)"Th 1");
}
