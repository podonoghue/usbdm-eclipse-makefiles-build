/*----------------------------------------------------------------------------
 * RTX example program - Threads with MUTEX
 *
 * Based on examples at https://developer.mbed.org/handbook/CMSIS-RTOS
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

#include "cmsis_os.h"                   // CMSIS RTX
#include "hardware.h"                   // Hardware interface

// Directly access USBDM routines
using namespace USBDM;

osMutexId stdio_mutex;
osMutexDef(stdio_mutex);

void notify(const char* name, int state) {
   osMutexWait(stdio_mutex, osWaitForever);
   printf("%s: %d\n\r", name, state);
   osMutexRelease(stdio_mutex);
}

void test_thread(void const *args) {
   while (true) {
      notify((const char*)args, 0); osDelay(1000);
      notify((const char*)args, 1); osDelay(1000);
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

int main() {
   printf("Starting\n");
   stdio_mutex = osMutexCreate(osMutex(stdio_mutex));

   osThreadCreate(osThread(t2), NULL);
   osThreadCreate(osThread(t3), NULL);

   test_thread("Th 1");
}
