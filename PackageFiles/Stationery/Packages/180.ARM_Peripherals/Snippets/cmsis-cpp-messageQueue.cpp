/**
 ============================================================================
 * @file cmsis-cpp-messageQueue.cpp
 * @brief RTX Message Queue example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface

/**
 * Message item
 */
struct MessageData {
   int a;
   int b;
};

/* Indicates the test is complete */
static bool messageQueueTestComplete = false;

/**
 * Message queue
 */
static CMSIS::MessageQueue<MessageData*, 10> messageQueue;

/**
 *  Thread for sending to the message queue
 */
static void messageQueueSender(const void *) {
   MessageData ar[30];
   for (unsigned i=0; i<(sizeof(ar)/sizeof(ar[0])); i++) {
      ar[i].a = i;
      ar[i].b = i*i;
      printf("%d: Sending %p (%d, %d)\n\r", i, &ar[i], ar[i].a, ar[i].b);
      osStatus rc = messageQueue.put(&ar[i], 0);
      osDelay(100);
      if (rc == osErrorResource) {
         break;
      }
   }
   printf("=== Sender complete ====\n\r");
}

/**
 *  Thread for receiving from the message queue
 */
static void messageQueueReceiver(const void *) {
   for(unsigned i=0; ; i++) {
      osEvent event = messageQueue.get(10000);
      if (event.status != osEventMessage) {
         break;
      }
      MessageData *data = (MessageData *)event.value.p;
      printf("%d: Received %p (%d, %d)\n\r", i, data, data->a, data->b);
   }
   messageQueueTestComplete = true;
   printf("=== Receiver complete ====\n\r");
}

/*
 * Message Queue example
 */
static void messageQueueExample() {
   printf(" message messageQueue.getId() = %p\n\r", messageQueue.getId());

   messageQueue.create();
   CMSIS::Thread sender(messageQueueSender);
   CMSIS::Thread receiver(messageQueueReceiver);

   receiver.run();
   sender.run();

   while(!messageQueueTestComplete) {
      __asm__("nop");
   }
}

int main() {
   messageQueueExample();

   for(;;) {
   }
   return 0;
}

