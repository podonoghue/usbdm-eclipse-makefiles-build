/**
 ============================================================================
 * @file cmsis-cpp-messageQueue.cpp (180.ARM_Peripherals/Snippets)
 * @brief RTX Message Queue example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"                   // Hardware interface
#include "cmsis.h"                      // CMSIS RTX

using namespace USBDM;

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
      console.
         writeln(i, ": Sending ", &ar[i]).write(", (", ar[i].a, ",", ar[i].b, ")");
      osStatus rc = messageQueue.put(&ar[i], 0);
      osDelay(100);
      if (rc == osErrorResource) {
         break;
      }
   }
   console.writeln("=== Sender complete ====\n\r");
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
      MessageData *data = messageQueue.getValueFromEvent(event);
      console.
         writeln(i, ": Received ", data).write(", (", data->a, ",", data->b, ")");
   }
   messageQueueTestComplete = true;
   console.writeln("=== Receiver complete ====");
}

/*
 * Message Queue example
 */
static void messageQueueExample() {
   console.writeln(" message messageQueue.getId() = ", messageQueue.getId());

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

