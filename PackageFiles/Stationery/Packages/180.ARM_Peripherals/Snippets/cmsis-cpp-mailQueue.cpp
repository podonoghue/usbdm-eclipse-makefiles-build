/**
 ============================================================================
 * @file cmsis-cpp-mailQueue.cpp
 * @brief RTX Mail Queue example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface
#include "console.h"

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
      console.write(i).write(": Allocated ").writeln(data);
      data->a = i;
      data->b = i*i;
      console.write(i).write(": Sending   ").write(data).write(", (").write(data->a).write(", ").write(data->a).writeln(")");
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
      console.
         write(i).write(": Received  ").write(data).
         write("(").write(data->a).write(",").write(data->b).writeln(")");
      console.write(i).write(": Freeing ").writeln(data);
      mailQueue.free(data);
   }
   mailQueueTestComplete = true;
   console.writeln("=== Receiver complete ====\n\r");
}

/**
 *  Mail queue example
 */
void mailQueueExample() {

   console.write(" mail mailQueue.getId() = ").writeln(mailQueue.getId());

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

