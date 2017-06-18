/**
 ============================================================================
 * @file cmsis-cpp-mailQueue.cpp
 * @brief RTX Mail Queue example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface

/**
 * Mail item
 */
struct MailData {
   int a;
   int b;
};

/* Indicates the test is complete */
static bool mailQueueTestComplete = false;

/**
 * Mail queue
 */
static CMSIS::MailQueue<MailData, 10> mailQueue;

/**
 *  Thread for sending to the mail queue
 */
static void mailQueueSender(const void *) {
   for (unsigned i=0; i<20; i++) {
      MailData *data = mailQueue.alloc(0);
      if (data == nullptr) {
         break;
      }
      printf("%d: Allocated %p\n\r", i, data);
      data->a = i;
      data->b = i*i;
      printf("%d: Sending   %p (%d, %d)\n\r", i, &data, data->a, data->b);
      mailQueue.put(data);
      osDelay(100);
   }
   printf("=== Sender complete ====\n\r");
   while(!mailQueueTestComplete) {
      __asm__("nop");
   }
}

/**
 *  Thread for receiving from the mail queue
 */
static void mailQueueReceiver(const void *) {
   for(unsigned i=0; ; i++) {
      osEvent event = mailQueue.get(5000);
      if (event.status != osEventMail) {
         break;
      }
      MailData *data = (MailData *)event.value.p;
      printf("%d: Received  %p (%d, %d)\n\r", i, data, data->a, data->b);
      mailQueue.free(data);
   }
   mailQueueTestComplete = true;
   printf("=== Receiver complete ====\n\r");
}

/**
 *  Mail queue example
 */
void mailQueueExample() {

   printf(" mail mailQueue.getId() = %p\n\r", mailQueue.getId());

   mailQueue.create();

   CMSIS::Thread sender(mailQueueSender);
   CMSIS::Thread receiver(mailQueueReceiver);

   receiver.run();
   sender.run();

   while(!mailQueueTestComplete) {
      __asm__("nop");
   }
}

int main() {
   mailQueueExample();

   for(;;) {
   }
   return 0;
}

