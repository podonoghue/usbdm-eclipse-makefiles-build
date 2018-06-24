/*----------------------------------------------------------------------------
 * RTX example program - Interrupt Service Routine
 *
 * Based on examples at https://developer.mbed.org/handbook/CMSIS-RTOS
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

#include "cmsis_os.h"                   // CMSIS RTX
#include "hardware.h"                   // Hardware interface

#include "lptmr.h"

// Directly access USBDM routines
using namespace USBDM;

/*
 * LEDs to use
 */
using Led1 = $(demo.cpp.green.led:USBDM::GpioB<1>);

osMessageQDef(queue, 5, message_t);
osMessageQId  queue;

void queue_isr() {
   osMessagePut(queue, (uint32_t)"queue_isr", 0);
   Led1::toggle();
}

void queue_thread(void const *) {
   while (true) {
      osMessagePut(queue, (uint32_t)"queue_thread", 0);
      osDelay(1000);
   }
}

osThreadDef(queue_thread, osPriorityNormal, 1, 0);

using Timer =  USBDM::Lptmr0;

int main (void) {
   Led1::setOutput();

   queue = osMessageCreate(osMessageQ(queue), NULL);

   osThreadCreate(osThread(queue_thread), NULL);

   /*
    * Note: LPTMR interrupt handling must be enabled on Configure.usbdmProject
    */
   Timer::enable();
   Timer::setCallback(queue_isr);
   Timer::setPeriod(1.0);
   Timer::enableNvicInterrupts();

   while (true) {
      osEvent evt = osMessageGet(queue, osWaitForever);
      if (evt.status != osEventMessage) {
         console.write("queue->get() returned ").writeln(evt.status, Radix_16);
      } else {
         console.write("queue->get() returned \'").write((const char *)evt.value.v).writeln("\'");
      }
   }
}
