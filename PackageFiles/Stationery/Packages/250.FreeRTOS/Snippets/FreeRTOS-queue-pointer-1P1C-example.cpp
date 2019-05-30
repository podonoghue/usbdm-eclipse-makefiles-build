/**
 * Simple producer-consumer example using a RTOS queue
 *
 * Assumes single producer & consumer so queue protection is not needed.
 */
#include <memory.h>
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

template<class T, unsigned maxItems>
class MemoryPool {
   static_assert(maxItems<32, "Only up to 32 items supported");

   T       *pool;
   uint32_t allocatedItems;

public:
   MemoryPool() : pool(nullptr), allocatedItems(-1) {
      unsigned size = maxItems*sizeof(T);
      pool = static_cast<T *>(malloc(size));
   }

   T *getBuffer() {
      USBDM::CriticalSection cs;
      // Allocate buffer
      unsigned bufferNum = __builtin_ffs(allocatedItems);
      if ((bufferNum == 0)||(--bufferNum>=maxItems)) {
         return nullptr;
      }
      allocatedItems &= ~(1<<bufferNum);
      return pool+bufferNum;
   }

   void freeBuffer(T *buffer) {
      const unsigned bufferNum  = buffer-pool;
      const uint32_t bufferMask = (1<<bufferNum);

      usbdm_assert(bufferNum<maxItems,                 "Illegal buffer");
      usbdm_assert((allocatedItems & bufferMask) == 0, "Freeing unallocated buffer");

      USBDM::CriticalSection cs;
      // Free buffer
      allocatedItems |= bufferMask;
   }
};

// Size of each buffer
constexpr unsigned BUFFER_SIZE = 64;

// Number of buffers
constexpr unsigned MAX_ITEMS   = 5;

// Type for buffer
using Buffer = char[BUFFER_SIZE];

// Message Pool (Two more than size of queue to allow for 2 in-process items)
MemoryPool<Buffer, MAX_ITEMS+2> pool;

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

   // Note FreeRTOS copies buffers in/out of the queue

   for( ;; ) {
      Buffer *buffer = pool.getBuffer();
      usbdm_assert(buffer != nullptr, "No buffer available!");
      produce(buffer);
//      USBDM::console.write("Sending buff@").write(buffer).write(" ").writeln((const char*)buffer);
      xQueueSend( queuePC, &buffer, portMAX_DELAY);
   }
}

/**
 * Receive task
 *
 * @param pvParameters Unused
 */
static void receivingTask( void *pvParameters ) {
   (void)pvParameters;

   for( ;; ) {
      Buffer *buffer = nullptr;
      xQueueReceive(queuePC, &buffer, portMAX_DELAY);
      consume(buffer);
      pool.freeBuffer(buffer);
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
    * This is a queue of pointers
    */
   queuePC = xQueueCreate(MAX_ITEMS, sizeof(Buffer *));

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

