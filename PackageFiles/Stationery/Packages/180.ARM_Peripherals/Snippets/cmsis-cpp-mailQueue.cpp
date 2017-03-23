/*----------------------------------------------------------------------------
 * @file cmsis-cpp-mailQueue.cpp
 *
 * RTX example program
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface

struct MailData {
   int a;
   int b;
};

static bool mailQueueTestComplete = false;

static CMSIS::MailQueue<MailData, 10> mailQueue;

void mailQueueSender(const void *) {
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

void mailQueueReceiver(const void *) {
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

//
// Mail queue example
//
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

