/*
 * main.cpp
 *
 *  Created on: 1May,2017
 *      Author: podonoghue
 */

#include "FreeRTOS_CPP.h"
#include "hardware.h"

using namespace FREERTOS_CPP; // Open namespace for CMSIS wrapper functions
using namespace USBDM; // Open namespace for CMSIS wrapper functions

//! Number of messages in pool to send
static constexpr int NUM_MESSAGES = 5;

//! Queue used to communicate between processes
static Queue<const char *> *queue;

static Mutex mutex(nullptr);

/**
 * Task producing messages which are added to the queue
 */
class Producer : public TaskClass {

private:
   // Name of the task
   const char * const     name;
   // Iteration counter
   int                    count = 0;
   // Messages pool to send
   const char            *messages[NUM_MESSAGES];
   // Delay between message transmission
   static constexpr long  DELAY_TIME = 400;

public:
   /**
    * Constructor for Task
    *
    * @param name  Name of task
    *
    * Other task parameters are defaulted.
    */
   Producer(char const *name) :
      TaskClass(name, TaskPrio_Low, configMINIMAL_STACK_SIZE), name(name) {
      messages[0] = "Message 0";
      messages[1] = "Message 1";
      messages[2] = "Message 2";
      messages[3] = "Message 3";
      messages[4] = "Message 4";
   }

   /**
    * Task function
    *
    * Sends messages in endless loop
    */
   void task() override {
      int messageIndex = 0;
      for(;;) {
         queue->add(messages[messageIndex%NUM_MESSAGES]);
         mutex.take();
         console
            .write("Producer sent ")
            .write(messageIndex)
            .write(", ")
            .writeln(messages[messageIndex%NUM_MESSAGES]);
         mutex.give();
         messageIndex++;
         delay(rand()%DELAY_TIME);
      }
   }
};

/**
 * Task consuming messages from the queue
 */
class Consumer : public TaskClass {

private:
   // Name of the task
   const char * const    name;
   // Delay between message reception
   static constexpr long DELAY_TIME = 400;

public:
   /**
    * Constructor for Task
    *
    * @param name  Name of task
    *
    * Other task parameters are defaulted.
    */
   Consumer(char const *name) :
      TaskClass(name, TaskPrio_Idle, configMINIMAL_STACK_SIZE), name(name) {
   }

   /**
    * Task function
    *
    * Receive messages in endless loop
    */
   void task() override {
      for(;;) {
         const char *message;
         queue->pop(message);
         mutex.take();
         console
            .write("                              Consumer: ")
            .writeln(message);
         mutex.give();
         delay(rand()%DELAY_TIME);
      }
   }
};

// Create two static threads with default priority and stack sizes
static Producer *task1;
static Consumer *task2;

int main() {
   console.writeln("Starting");

   // Queue used to communicate between processes
   queue = new Queue<const char *>(NUM_MESSAGES, "The main queue");

   // Create two threads
   task1 = new Producer("Producer 1");
   task2 = new Consumer("Consumer 1");

   /*
    * Start the tasks running.
    */
   vTaskStartScheduler();

   /*
    * Shouldn't get here
    */
   console.writeln("Opps!!!!");
   for( ;; ) {
   }

}

