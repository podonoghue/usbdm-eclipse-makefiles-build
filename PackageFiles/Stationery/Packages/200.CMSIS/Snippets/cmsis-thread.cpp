/*----------------------------------------------------------------------------
 * RTX example program - Threads
 *
 * Based on examples at https://developer.mbed.org/handbook/CMSIS-RTOS
 *----------------------------------------------------------------------------
 */
#include "cmsis_os.h"                   // CMSIS RTX
#include "hardware.h"                   // Hardware interface


// Directly access USBDM routines
using namespace USBDM;

/*
 * LEDs to use
 */
using Led1 = $(demo.cpp.red.led:USBDM::GpioB<0>);
using Led2 = $(demo.cpp.green.led:USBDM::GpioB<1>);

/*
 * This thread toggles one LED at 1s rate
 */
void led2_thread(void const *) {
   while (true) {
      Led2::toggle();
      osDelay(1000);
   }
}
osThreadDef(led2_thread, osPriorityNormal, 1, 0);

/*
 * Main:
 * - Initialises LEDs
 * - Creates led2_thread() thread
 * - Main thread toggles one LED at 0.5s rate
 */
int main() {

   Led1::setOutput();
   Led2::setOutput();

   osThreadCreate(osThread(led2_thread), NULL);

   while (true) {
      Led1::toggle();
      osDelay(500);
   }
}
