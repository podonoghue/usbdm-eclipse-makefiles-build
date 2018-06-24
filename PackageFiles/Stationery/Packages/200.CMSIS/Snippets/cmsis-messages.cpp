/*----------------------------------------------------------------------------
 * RTX example program - Messages & Memory Pools
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

typedef struct {
   float    voltage;   /* AD result of measured voltage */
   float    current;   /* AD result of measured current */
   uint32_t counter;   /* Counter value               */
} message_t;

osPoolDef(mpool, 16, message_t);
osPoolId  mpool;

osMessageQDef(queue, 16, message_t);
osMessageQId  queue;

void send_thread (void const *) {
   uint32_t i = 0;
   while (true) {
      i++; // fake data update
      message_t *message = (message_t*)osPoolAlloc(mpool);
      message->voltage = (i * 0.1) * 33;
      message->current = (i * 0.1) * 11;
      message->counter = i;
      osMessagePut(queue, (uint32_t)message, osWaitForever);
      osDelay(1000);
   }
}

osThreadDef(send_thread, osPriorityNormal, 1,0 );

int main (void) {
   mpool = osPoolCreate(osPool(mpool));
   queue = osMessageCreate(osMessageQ(queue), NULL);

   osThreadCreate(osThread(send_thread), NULL);

   while (true) {
      osEvent evt = osMessageGet(queue, osWaitForever);
      if (evt.status == osEventMessage) {
         message_t *message = (message_t*)evt.value.p;
         console.write("\nVoltage: ").write(message->voltage).writeln(" V");
         console.write("Current: ").write(message->current).writeln(" A");
         console.write("Number of cycles: ").writeln(message->counter);

         osPoolFree(mpool, message);
      }
   }
}
