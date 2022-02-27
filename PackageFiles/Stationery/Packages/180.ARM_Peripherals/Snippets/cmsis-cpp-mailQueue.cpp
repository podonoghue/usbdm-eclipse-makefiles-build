/**
 ============================================================================
 * @file cmsis-cpp-mailQueue.cpp (180.ARM_Peripherals/Snippets)
 * @brief RTX Mail Queue example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"                   // Hardware interface
#include "cmsis.h"                      // CMSIS RTX

using namespace USBDM;

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
      MailData *data = mailQueue.alloc(2000);
      if (data == nullptr) {
         console.writeln("Error: Sender failed to allocate mail buffer!");
         break;
      }
      console.writeln(i, ": Allocated ", data);
      data->a = i;
      data->b = i*i;
      console.writeln(i, ": Sending   ", data, ", (", data->a, ", ", data->a, ")");
      mailQueue.put(data);
      osDelay(100);
   }
   console.writeln("=== Sender complete ====");
   while(!mailQueueTestComplete) {
      __asm__("nop");
   }
}

/**
 *  Thread for receiving from the mail queue
 */
static void mailQueueReceiver(const void *) {
   // Wait a while for sender to produce items (more interesting result)
   osDelay(1000);
   for(unsigned i=0; ; i++) {
      osEvent event = mailQueue.get(5000);
      if (event.status != osEventMail) {
         console.writeln("Error: Receiver failed to get mail!");
         break;
      }
      MailData *data = mailQueue.getValueFromEvent(event);
      console.writeln(i, ": Received  ", data, "(", data->a, ",", data->b, ")");
      console.writeln(i, ": Freeing ", data);
      mailQueue.free(data);
   }
   mailQueueTestComplete = true;
   console.writeln("=== Receiver complete ====\n\r");
}

/**
 *  Mail queue example
 */
void mailQueueExample() {

   console.writeln(" mail mailQueue.getId() = ", mailQueue.getId());

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

