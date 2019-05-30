/**
 * Simple producer-consumer example using a RTOS queue
 *
 * Assumes single producer & consumer so queue protection is not needed.
 */
#include "hardware.h"
#include "stringFormatter.h"
#include "console.h"

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/*
 * Task handles
 */
static TaskHandle_t  xTxTask;
static TaskHandle_t  xRxTask;

/*
 * The RTOS queue
 */
QueueHandle_t queuePC;

// Size of each buffer
constexpr unsigned BUFFER_SIZE = 64;

// Number of buffers
constexpr unsigned MAX_ITEMS   = 5;

/**
 * Produce a message to send
 *
 * @param buff Buffer for message
 */
void produce(void *buff) {
   static unsigned counter = 0;

   // Write message to buffer
   USBDM::StringFormatter sf(static_cast<char*>(buff), BUFFER_SIZE);
   sf.write("msg #").writeln(counter++);
}

/**
 * Consume a message
 *
 * @param buff Buffer for message
 */
void consume(void *buff) {
   char *buffer = static_cast<char*>(buff);
   USBDM::console.write(buffer);
}

/**
 * Transmit task
 *
 * @param pvParameters
 */
static void sendingTask( void *pvParameters ) {
   (void)pvParameters;

   // Local buffer - note FreeRTOS copies buffers in/out of the queue
   char buffer[BUFFER_SIZE];

   for( ;; ) {
      produce(buffer);
      xQueueSend( queuePC, buffer, portMAX_DELAY);
   }
}

/**
 * Receive task
 *
 * @param pvParameters Unused
 */
static void receivingTask( void *pvParameters ) {
   (void)pvParameters;

   // Local buffer - note FreeRTOS copies buffers in/out of the queue
   char buffer[BUFFER_SIZE];
   
   for( ;; ) {
      xQueueReceive( queuePC, buffer, portMAX_DELAY);
      consume(buffer);
   }
}

/**
 * Main line
 *
 * Creates tasks, timers and queues
 *
 * @return Doesn't
 */
int main( void ) {
   USBDM::console.writeln( "Hello from FreeRTOS example main" );

   /*
    * Create the RTOS queue
    */
   queuePC = xQueueCreate(MAX_ITEMS, BUFFER_SIZE);

   /*
    * Create the two tasks.
    */
   xTaskCreate(
         sendingTask,               // The function that implements the task.
         ( const char * ) "Tx",     // Text name for the task, provided to assist debugging only.
         configMINIMAL_STACK_SIZE,  // The size of stack allocated to the task in WORDs.
         NULL,                      // The task parameter (none).
         tskIDLE_PRIORITY+1,        // The task runs at the idle+1 priority.
         &xTxTask                   // Handle for created task
   );

   xTaskCreate(
         receivingTask,             // The function that implements the task.
         ( const char * ) "Rx",     // Text name for the task, provided to assist debugging only.
         configMINIMAL_STACK_SIZE,  // The size of stack allocated to the task in WORDs.
         NULL,                      // The task parameter (none).
         tskIDLE_PRIORITY+1,        // The task runs at the idle+1 priority.
         &xRxTask                   // Handle for created task
   );

   /* Start the tasks running. */
   vTaskStartScheduler();

   for( ;; ) {
      __asm__("bkpt");
   }
}

