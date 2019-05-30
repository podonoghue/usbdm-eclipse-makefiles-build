/**
 * Simple producer-consumer example using semaphores and a non-RTOS queue
 *
 * Assumes single producer & consumer so queue protection is not needed.
 */
#include "hardware.h"
#include "stringFormatter.h"
#include "console.h"

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/*
 * Task handles
 */
static TaskHandle_t  xTxTask;
static TaskHandle_t  xRxTask;

/*
 * Semaphores
 */
SemaphoreHandle_t semFull;
SemaphoreHandle_t semEmpty;

// Size of each buffer
constexpr unsigned BUFFER_SIZE = 100;

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

// Used to implement queue
char buffer[MAX_ITEMS][BUFFER_SIZE];

/**
 * Transmit task
 *
 * @param pvParameters
 */
static void sendingTask( void *pvParameters ) {
   (void)pvParameters;

   unsigned tailIndex = 0;
   for( ;; ) {
      xSemaphoreTake(semEmpty, portMAX_DELAY);
      produce(buffer[tailIndex]);
      xSemaphoreGive(semFull);
      tailIndex++;
      if (tailIndex>=MAX_ITEMS) {
         tailIndex = 0;
      }
   }
}

/**
 * Receive task
 *
 * @param pvParameters Unused
 */
static void receivingTask( void *pvParameters ) {
   (void)pvParameters;

   unsigned headIndex = 0;
   for( ;; ) {
      xSemaphoreTake(semFull, portMAX_DELAY);
      consume(buffer[headIndex]);
      xSemaphoreGive(semEmpty);
      headIndex++;
      if (headIndex>=MAX_ITEMS) {
         headIndex = 0;
      }
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
    * Create the semaphores
    */
   semEmpty = xSemaphoreCreateCounting(100, MAX_ITEMS);
   semFull  = xSemaphoreCreateCounting(100, 0);

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

