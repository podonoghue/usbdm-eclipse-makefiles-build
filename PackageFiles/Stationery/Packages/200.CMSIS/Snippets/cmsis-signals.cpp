/*----------------------------------------------------------------------------
 * RTX example program - Signals
 *
 * Based on examples at https://developer.mbed.org/handbook/CMSIS-RTOS
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

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
 * Flag used to communicate between main() and led_thread()
 */
static constexpr int SIGNAL_FLAG = 1<<0;

void led_thread(void const *) {
   Led1::setOutput();
   while (true) {
      // Signal flags that are reported as event are automatically cleared.
      osSignalWait(SIGNAL_FLAG, osWaitForever);
      Led1::toggle();
   }
}
osThreadDef(led_thread, osPriorityNormal, 1, 0);

int main (void) {
   osThreadId tid = osThreadCreate(osThread(led_thread), NULL);

   while (true) {
      osDelay(1000);
      osSignalSet(tid, SIGNAL_FLAG);
   }
}
