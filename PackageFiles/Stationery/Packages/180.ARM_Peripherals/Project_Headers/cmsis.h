/**
 * @file cmsis.h
 *
 *  Created on: 20Feb.,2017
 *      Author: podonoghue
 */
#ifndef PROJECT_HEADERS_CMSIS_H_
#define PROJECT_HEADERS_CMSIS_H_

#include "cmsis_os.h"
#include "hardware.h"

/**
 * Namespace enclosing wrapper classes for CMSIS-RTX
 */
namespace CMSIS {

/**
 * Based on os_timer_cb in rt_CMSIS.c
 * Timer Control Block
 */
struct osTimerControlBlock_t {
   struct os_timer_cb_ *next;   // Pointer to next active Timer
   uint8_t             state;   // Timer State
   uint8_t              type;   // Timer Type (Periodic/One-shot)
   uint16_t         reserved;   // Reserved
   uint32_t             tcnt;   // Timer Delay Count
   uint32_t             icnt;   // Timer Initial Count
   void                 *arg;   // Timer Function Argument
   const osTimerDef_t *timer;   // Pointer to Timer definition
};

/**
 * Wrapper for CMSIS Timer
 *
 * @tparam callback Timer callback function
 * @tparam timerType Type of timer e.g. osTimerPeriodic, osTimerOnce
 *
 * Example:
 * @code
 * //
 * // Timer example
 * //
 * void timerExample() {
 *    static auto cb1 = [] (const void *) {
 *       RED_LED::toggle();
 *    };
 *    static auto cb2 = [] (const void *) {
 *       GREEN_LED::toggle();
 *    };
 *    static CMSIS::Timer<osTimerPeriodic> myTimer1(cb1);
 *    static CMSIS::Timer<osTimerPeriodic> myTimer2(cb2);
 *
 *    RED_LED::setOutput();
 *    GREEN_LED::setOutput();
 * 
 *    myTimer2.start(500);
 *    myTimer1.start(1000);
 *
 *    printf(" myTimer1::getId() = %p\n\r", myTimer1.getId());
 *    printf(" myTimer2::getId() = %p\n\r", myTimer2.getId());
 * }
 * @endcode
 */
template<os_timer_type timerType=osTimerPeriodic>
class Timer {

private:
   osTimerControlBlock_t  os_timer_cb  = {0,0,0,0,0,0,0,0};
   const osTimerDef_t     os_timer_def;

public:
   Timer(void (*callback)(const void *)) :
      os_timer_def{callback, (void*)&os_timer_cb}
   {
   }
   ~Timer() {
      if (os_timer_cb.state != 0) {
         destroy();
      }
   }
   /**
    * Create timer
    *
    * @param type     Type of timer i.e. osTimerOnce, osTimerPeriodic
    * @param argument Pointer to data to pass to callback
    *
    * @note Not usually required as done on first use
    */
   void create(void *argument=nullptr, os_timer_type type=timerType) {
      osTimerId timer_id __attribute__((unused)) = osTimerCreate(&os_timer_def, type, argument);
      assert((void*)timer_id == (void*)&os_timer_cb);
   }
   /**
    * Destroy timer
    *
    * @return error code:
    * @return - osOK:              The timer has been deleted.
    * @return - osErrorISR:        Cannot be called from interrupt service routines.
    * @return - osErrorParameter:  Parameter is incorrect
    */
   osStatus destroy() {
      return osTimerDelete((osTimerId)&os_timer_cb);
   }
   /**
    * Stop the timer
    */
   void stop() {
      osTimerStop((osTimerId)&os_timer_cb);
   }
   /**
    * Start or restart timer
    *
    * @param millisec Interval in milliseconds
    */
   void start(int millisec) {
      if (os_timer_cb.state == 0) {
         // Lazy initialisation
         create();
      }
      USBDM::setAndCheckCmsisErrorCode(osTimerStart((osTimerId)&os_timer_cb, millisec));
   }
   /**
    * Start or restart timer
    *
    * @param interval Interval in seconds
    */
   void start(double interval) {
      start((int)round(interval*1000.0));
   }
   /**
    * Get timer ID
    *
    * @return CMSIS Timer ID
    */
   inline osTimerId getId() {
      return (osTimerId)&os_timer_cb;
   }
};

/**
 * Wrapper for CMSIS Mutex
 */
class Mutex {

private:
   uint32_t           os_mutex_cb[4] = { 0 };
   const osMutexDef_t os_mutex_def   = {os_mutex_cb};

public:
   /**
    * Create mutex
    */
   Mutex() {
      osMutexId mutex_id __attribute__((unused)) = osMutexCreate(&os_mutex_def);
      assert((void*)mutex_id == (void*)os_mutex_cb);
   }
   /**
    * Delete mutex
    */
   ~Mutex() {
      osMutexDelete((osMutexId) os_mutex_cb);
   }
   /**
    * Obtain mutex
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   osStatus wait(uint32_t millisec=osWaitForever) {
      return osMutexWait((osMutexId) os_mutex_cb, millisec);
   }
   /**
    * Release mutex
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   osStatus release() {
      return osMutexRelease((osMutexId) os_mutex_cb);
   }
   /**
    * Get mutex ID
    *
    * @return CMSIS Mutex ID
    *
    * @return osOK: The mutex has been correctly released.
    * @return osErrorResource: The mutex was not obtained before.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   osMutexId getID() {
      return (osMutexId) os_mutex_cb;
   }
};
/**
 * Wrapper for CMSIS Semaphore
 */
class Semaphore {

private:
   uint32_t               os_semaphore_cb[2] = { 0 };
   const osSemaphoreDef_t os_semaphore_def   = { os_semaphore_cb };

public:
   /**
    * Create semaphore
    *
    * @param count Number of available resources.
    */
   Semaphore(int32_t count) {
      osSemaphoreId semaphore_id __attribute__((unused)) = osSemaphoreCreate(&os_semaphore_def, count);
      assert((void*)semaphore_id == (void*)os_semaphore_cb);
   }
   /**
    * Delete semaphore
    */
   ~Semaphore() {
      osSemaphoreDelete((osSemaphoreId)os_semaphore_cb);
   }
   /**
    * Obtain semaphore
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return Number of available tokens, or -1 in case of incorrect parameters.
    */
   int32_t wait(uint32_t millisec=osWaitForever) {
      int32_t rc = osSemaphoreWait((osSemaphoreId)os_semaphore_cb, millisec);
      assert(rc >= 0);
      return rc;
   }
   /**
    * Release semaphore
    */
   void release() {
      osStatus status __attribute__((unused)) = osSemaphoreRelease((osSemaphoreId)os_semaphore_cb);
      assert(status == osOK);
   }
   /**
    * Get semaphore ID
    *
    * @return CMSIS semaphore ID
    */
   osSemaphoreId getID() {
      return (osSemaphoreId)os_semaphore_cb;
   }
};

/**
 * Wrapper for CMSIS Memory Allocation Pool
 *
 * @tparam T      Type of items in pool
 * @tparam size   Size of pool in items
 *
 * Example:
 * @code
 * //
 * // Memory pools example
 * //
 * void memoryPoolExample() {
 *    struct Data {
 *       int a;
 *       int b;
 *    };
 *
 *    Pool<Data, 10> pool;
 *
 *    printf(" memory pool::getId() = %p\n\r", pool.getId());
 *
 *    Data *ar[30] = {0};
 *    for (unsigned i=0; i<(sizeof(ar)/sizeof(ar[0])); i++) {
 *       ar[i] = pool.alloc();
 *       if (ar[i] == nullptr) {
 *          break;
 *       }
 *       else {
 *          printf("%d: Allocated %p\n\r", i, ar[i]);
 *       }
 *       ar[i]->a = i;
 *       ar[i]->b = i*i;
 *    }
 *    for (unsigned i=0; i<(sizeof(ar)/sizeof(ar[0])); i++) {
 *       if (ar[i] != nullptr) {
 *          printf("%d: free %p (%d, %d)\n\r", i, ar[i], ar[i]->a, ar[i]->b);
 *          pool.free(ar[i]);
 *       }
 *    }
 * }
 * @endcode
 */
template <typename T, size_t size>
class Pool {

private:
         uint32_t pool[3+((sizeof(T)+3)/4)*size] = {0};
   const osPoolDef_t os_pool_def                 = { size, sizeof(T), pool };

public:
   Pool() {
   }
   ~Pool() {
   }

   /**
    * Create pool
    */
   void create() {
      osPoolId pool_id = osPoolCreate(&os_pool_def);
      assert((void*)pool_id == (void*)pool);
   }
   /**
    * Allocate a memory block from the memory pool.
    *
    * @return Address of the allocated memory block or nullptr in case of no memory available.
    */
   T *alloc() {
      if ((pool[0] == 0)&&(pool[1] == 0)) {
         // Lazy creation
         create();
      }
      return (T*)osPoolAlloc((osPoolId)pool);
   }
   /**
    * Allocate a memory block from the memory pool and initialise to all zeroes.
    *
    * @return Address of the allocated memory block or nullptr in case of no memory available.
    */
   T *calloc() {
      if (pool[0] == 0) {
         // Lazy creation
         create();
      }
      return (T*)osPoolCAlloc((osPoolId)pool);
   }
   /**
    * Return a memory block to a memory pool.
    *
    * @param buffer Address of buffer to return to pool
    *
    * @return osOK:             The memory block is released.
    * @return osErrorValue:     Block does not belong to the memory pool.
    * @return osErrorParameter: A parameter is invalid or outside of a permitted range.
    */
   void free(T *buffer) {
      osStatus status = osPoolFree((osPoolId)pool, buffer);
      assert(status == osOK);
   }
   /**
    * Get pool ID
    *
    * @return CMSIS pool ID
    */
   osPoolId getId() {
      return (osPoolId)pool;
   }
};
//template <class T, size_t size> uint32_t Pool<T,size>::pool[] = {0};
//template <class T, size_t size> const osPoolDef_t Pool<T,size>::os_pool_def = { size, sizeof(T), pool };

/**
 * Wrapper for CMSIS Thread
 *
 * @code
 * //
 * // Thread example
 * //
 * void threadExample() {
 *    static auto threadFn = [] (const void *) {
 *       for(;;) {
 *          BLUE_LED::toggle();
 *          osDelay(2000);
 *       }
 *    };
 *    static Thread thread(threadFn);
 *
 *    BLUE_LED::setOutput();
 *
 *    thread.run();
 *    printf(" thread::getId() = %p\n\r", thread.getId());
 * }
 * @endcode
 */
class Thread {

private:

   const osThreadDef_t thread_def;
   osThreadId thread_id = 0;

public:
   /**
    * Create thread
    *
    * @param threadFunction   Function to execute as the thread
    * @param priority         Priority of thread e.g. osPriorityNormal
    * @param stackSize        Stack size for thread or 0 to indicate default
    */
   Thread(
         void (*threadFunction)(const void *),
         osPriority  priority=osPriorityNormal,
         uint32_t    stackSize=0) :
            thread_def {threadFunction, priority, 1, stackSize }
   {
   };
   /**
    * Delete thread
    */
   ~Thread() {
      osThreadTerminate(thread_id);
   }
   /**
    * Run thread
    *
    * @param argument Argument to thread function
    */
   void run(void *argument=nullptr) {
      thread_id = osThreadCreate(&thread_def, argument);
      USBDM::setAndCheckCmsisErrorCode((thread_id != nullptr)?osOK:osErrorOS);
   }
   /**
    * Get thread ID
    *
    * @return ID of thread
    */
   osThreadId getId() {
      return thread_id;
   }
   /**
    * Get thread ID of current process
    *
    * @return ID of thread
    */
   static osThreadId getMyId() {
      return osThreadGetId();
   }
   /**
    * Get thread Priority
    *
    * @return Priority of thread
    */
   osPriority getPriority() {
      return osThreadGetPriority(thread_id);
   }
   /**
    * Set thread Priority
    *
    * @param priority Priority to set for thread
    *
    * @return osOK:              The priority of the thread has been successfully changed.
    * @return osErrorValue:      Incorrect priority value.
    * @return osErrorResource:   Thread that is not an active thread.
    * @return osErrorISR:        Cannot be called from interrupt service routines.
    */
   osStatus setPriority(osPriority priority) {
      return osThreadSetPriority(thread_id, priority);
   }
   /**
    * Pass control to the next thread that is in state READY.
    * If there is no other thread in the state READY, the current
    * thread continues execution and no thread switching occurs.
    *
    * @return osOK:       The function has been correctly executed.
    * @return osErrorISR: Cannot be called from interrupt service routines.
    *
    */
   osStatus yield() {
      return osThreadYield();
   }
   /**
    * Set the specified Signal Flags
    *
    * @param signals Specifies the signal flags of the thread that should be set.
    *
    * @return Previous signal flags of the specified thread or 0x80000000 in case of incorrect parameters or call from ISR.
    *
    */
   int32_t signalSet(int32_t signals) {
      return osSignalSet(thread_id, signals);
   }
   /**
    * Clear the specified Signal Flags
    *
    * @param signals Specifies the signal flags of the thread that shall be cleared.
    *
    * @return Previous signal flags of the specified thread or 0x80000000 in case of incorrect parameters or call from ISR.
    */
   int32_t signalClear(int32_t signals) {
      return osSignalClear(thread_id, signals);
   }
   /**
    * Wait for one or more Signal Flags to become signaled for the current thread.
    *
    * @param signals  Wait until all specified signal flags set or 0 for any single signal flag.
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return Structure describing event occurring with status:
    * @return - osOK: no signal received when the timeout value millisec was 0.
    * @return - osEventTimeout: signal not occurred within timeout
    * @return - osEventSignal: signal occurred, value.signals contains the signal flags; these signal flags are cleared.
    * @return - osErrorValue: the value signals is outside of the permitted range.
    * @return - osErrorISR: osSignalWait cannot be called from interrupt service routines.
    *
    */
   static osEvent signalWait(int32_t signals, uint32_t millisec=osWaitForever) {
      return osSignalWait(signals, millisec);
   }
   /**
    * Terminate the thread.
    *
    * @return - osOK: the specified thread has been successfully terminated.
    * @return - osErrorParameter: thread_id is incorrect.
    * @return - osErrorResource: thread_id refers to a thread that is not an active thread.
    * @return - osErrorISR: osThreadTerminate cannot be called from interrupt service routines.
    */
   osStatus terminate() {
      return osThreadTerminate(thread_id);
   }
};

/**
 * Wrapper for CMSIS Message Queue
 *
 *
 * @tparam T      Type of items in message queue
 * @tparam size   Size of message queue in items
 *
 * Example:
 * @code
 * struct MessageData {
 *    int a;
 *    int b;
 * };
 *
 * static bool messageQueueTestComplete = false;
 *
 * static CMSIS::MessageQueue<MessageData*, 10> messageQueue;
 *
 * void messageQueueSender(const void *) {
 *    MessageData ar[30];
 *    for (unsigned i=0; i<(sizeof(ar)/sizeof(ar[0])); i++) {
 *       ar[i].a = i;
 *       ar[i].b = i*i;
 *       printf("%d: Sending %p (%d, %d)\n\r", i, &ar[i], ar[i].a, ar[i].b);
 *       osStatus rc = messageQueue.put(&ar[i], 0);
 *       osDelay(100);
 *       if (rc == osErrorResource) {
 *          break;
 *       }
 *    }
 *    printf("=== Sender complete ====\n\r");
 * }
 *
 * void messageQueueReceiver(const void *) {
 *    for(unsigned i=0; ; i++) {
 *       osEvent event = messageQueue.get(10000);
 *       if (event.status != osEventMessage) {
 *          break;
 *       }
 *       MessageData *data = (MessageData *)event.value.p;
 *       printf("%d: Received %p (%d, %d)\n\r", i, data, data->a, data->b);
 *    }
 *    messageQueueTestComplete = true;
 *    printf("=== Receiver complete ====\n\r");
 * }
 *
 * //
 * // Message Queue example
 * //
 * void messageQueueExample() {
 *    printf(" message messageQueue.getId() = %p\n\r", messageQueue.getId());
 *
 *    messageQueue.create();
 *    Thread sender(messageQueueSender);
 *    Thread receiver(messageQueueReceiver);
 *
 *    receiver.run();
 *    sender.run();
 *
 *    while(!messageQueueTestComplete) {
 *       __asm__("nop");
 *    }
 * }
 * @endcode
 */
template <typename T, size_t size, Thread *thread=nullptr>
class MessageQueue {

   static_assert(sizeof(T)<=sizeof(int), "Object is too large to pass as message");

private:
         uint32_t        queue[4+size] = {0};
   const osMessageQDef_t os_pool_def   = { size, queue };

//   static void *operator new     (size_t) = delete;
//   static void *operator new[]   (size_t) = delete;
//   static void  operator delete  (void*)  = delete;
//   static void  operator delete[](void*)  = delete;

public:
   MessageQueue() {
   }

   ~MessageQueue() {
   }
   /**
    * Create message queue
    *
    * @return osMessageQId or NULL if failed.
    */
   osMessageQId create() {
      osThreadId threadId = 0;
      if (thread != 0) {
         threadId = thread->getId();
      }
      osMessageQId message_id = osMessageCreate(&os_pool_def, threadId);
      assert((void*)message_id == (void*)queue);
      return message_id;
   }
   /**
    * Put message to queue.
    * Waits indefinitely.
    *
    * @param info     Message to send
    *
    * @return osOK: the message is put into the queue.
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   void put(T info) {
      if ((queue[0]==0) && (queue[1]==0)) {
         create();
      }
      osStatus status = osMessagePut((osMessageQId)queue, (uint32_t)info, osWaitForever);
      assert(status == osOK);
   }
   /**
    * Put message to queue.
    * Returns immediately (for use in ISRs)
    *
    * @param info     Message to send
    *
    * @return osOK: the message is put into the queue.
    * @return osErrorResource: no memory in the queue was available.
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   osStatus putISR(T info) {
      return osMessagePut((osMessageQId)queue, (uint32_t)info, 0);
   }
   /**
    * Put message to queue with timeout
    *
    * @param info     Message to enter
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: the message is put into the queue.
    * @return osErrorResource: no memory in the queue was available.
    * @return osErrorTimeoutResource: no memory in the queue was available during the given time limit.
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   osStatus put(T info, uint32_t millisec) {
      if ((queue[0]==0) && (queue[1]==0)) {
         create();
      }
      return osMessagePut((osMessageQId)queue, (uint32_t)info, millisec);
   }
   /**
    * Get message from queue.
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return Status and Error Codes
    * @return osOK: no message is available in the queue and no timeout was specified.
    * @return osEventTimeout: no message has arrived during the given timeout period.
    * @return osEventMessage: message received, value.p contains the pointer to message.
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   osEvent get(uint32_t millisec=osWaitForever) {
      if ((queue[0]==0) && (queue[1]==0)) {
         create();
      }
      return osMessageGet((osMessageQId)queue, millisec);
   }
   /**
    * Get message from queue.
    * Returns immediately (for use in ISRs)
    *
    * @return Status and Error Codes
    * @return osOK: no message is available in the queue.
    * @return osEventMessage: message received, value.p contains the pointer to message.
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   osEvent getISR() {
      osEvent event = osMessageGet((osMessageQId)queue, 0);
      assert (event.status != osErrorParameter);
      return event;
   }
   /**
    * Get pool ID
    *
    * @return CMSIS pool ID
    */
   osMessageQId getId() {
      return (osMessageQId)queue;
   }
};

//template <class T, size_t size, Thread *thread>
//uint32_t MessageQueue<T,size,thread>::queue[] = {0};
//
//template <class T, size_t size, Thread *thread>
//const osMessageQDef_t MessageQueue<T,size,thread>:: os_pool_def = { size, queue };

/**
 * Wrapper for CMSIS Message Queue
 *
 *
 * @tparam T      Type of items in message queue
 * @tparam size   Size of message queue in items
 *
 * Example:
 * @code
 * struct MailData {
 *    int a;
 *    int b;
 * };
 *
 * static bool mailQueueTestComplete = false;
 *
 * static MailQueue<MailData, 10> mailQueue;
 *
 * void mailQueueSender(const void *) {
 *    for (unsigned i=0; i<20; i++) {
 *       MailData *data = mailQueue.alloc(0);
 *       if (data == nullptr) {
 *          break;
 *       }
 *       printf("%d: Allocated %p\n\r", i, data);
 *       data->a = i;
 *       data->b = i*i;
 *       printf("%d: Sending   %p (%d, %d)\n\r", i, &data, data->a, data->b);
 *       mailQueue.put(data);
 *       osDelay(100);
 *    }
 *    printf("=== Sender complete ====\n\r");
 *    while(!mailQueueTestComplete) {
 *       __asm__("nop");
 *    }
 * }
 *
 * void mailQueueReceiver(const void *) {
 *    for(unsigned i=0; ; i++) {
 *       osEvent event = mailQueue.get(5000);
 *       if (event.status != osEventMail) {
 *          break;
 *       }
 *       MailData *data = (MailData *)event.value.p;
 *       printf("%d: Received  %p (%d, %d)\n\r", i, data, data->a, data->b);
 *       mailQueue.free(data);
 *    }
 *    mailQueueTestComplete = true;
 *    printf("=== Receiver complete ====\n\r");
 * }
 *
 * //
 * // Mail queue example
 * //
 * void mailQueueExample() {
 *
 *    printf(" mail mailQueue.getId() = %p\n\r", mailQueue.getId());
 *
 *    mailQueue.create();
 *
 *    Thread sender(mailQueueSender);
 *    Thread receiver(mailQueueReceiver);
 *
 *    receiver.run();
 *    sender.run();
 *
 *    while(!mailQueueTestComplete) {
 *       __asm__("nop");
 *    }
 * }
 * @endcode
 */
template <typename T, size_t size, Thread *thread=nullptr>
class MailQueue {

private:
          uint32_t     queue[4+size];
          uint32_t     messages[3+((sizeof(T)+3)/4)*size];
   const  void         *pool[2]       = {queue, messages};
   const  os_mailQ_def os_mail_def    = {size, sizeof(T), pool};

//   static void *operator new     (size_t) = delete;
//   static void *operator new[]   (size_t) = delete;
//   static void  operator delete  (void*)  = delete;
//   static void  operator delete[](void*)  = delete;

public:
   /**
    * Create mail queue
    */
   void create() {
      osThreadId threadId = 0;
      if (thread != 0) {
         threadId = thread->getId();
      }
      osMailQId queue_id __attribute__((unused)) = osMailCreate(&os_mail_def, threadId);
      assert(queue_id == (osMailQId)pool);
   }
   /**
    * Allocate a memory block from the mail queue
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait.
    *
    * @return Pointer to allocated block or nullptr on failure.
    */
   T *alloc(uint32_t millisec=osWaitForever) {
      if ((messages[0]==0) && (messages[1]==0)) {
         create();
      }
      return (T *) osMailAlloc((os_mailQ_cb *)&pool, millisec);
   }

   /**
    * Allocate a memory block from the mail queue\n
    * For use in ISRs.
    *
    * @return Pointer to allocated block or nullptr on failure.

    * @return osOK: the block has been allocated
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   T *allocISR() {
      return (T *)osMailAlloc((os_mailQ_cb *)&pool, 0);
   }

   /**
    * Allocate a memory block from the mail queue and initialise to all zeroes.
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait.
    *
    * @return Pointer to allocated block or nullptr on failure.
    */
   T *calloc(uint32_t millisec=osWaitForever) {
      if ((messages[0]==0) && (messages[0]==0)) {
         create();
      }
      return (T *)osMailCAlloc((os_mailQ_cb *)&pool, millisec);
   }

   /**
    * Allocate a memory block from the mail queue and initialise to all zeroes.\n
    * For use in ISRs.
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return Pointer to allocated block or nullptr on failure.
    */
   T *callocISR(uint32_t millisec) {
      return (T *)osMailCAlloc((osMailQId)&pool, 0);
   }

   /**
    * Free a memory block from the mail queue.
    *
    * @param mail Mail block to free (previously allocated with alloc or calloc)
    *
    * @return osOK: the mail block is released.
    * @return osErrorValue: mail block does not belong to the mail queue pool.
    * @return osErrorParameter: the value to the parameter queue_id is incorrect.
    */
   osStatus free(T *mail) {
      return osMailFree((osMailQId)&pool, mail);
   }

   /**
    * Get a mail item from the mail queue.
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait.
    *
    * @return Status with:
    * @return osOK: no mail is available in the queue and no timeout was specified
    * @return osEventTimeout: no mail has arrived during the given timeout period.
    * @return osEventMail: mail received, value.p contains the pointer to mail content.
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   osEvent get(uint32_t millisec=osWaitForever) {
      return osMailGet((os_mailQ_cb *)&pool, millisec);
   }

   /**
    * Get a mail item from the mail queue.\n
    * Fir use in ISRs
    *
    * @return osOK: no mail is available in the queue
    * @return osEventMail: mail received, value.p contains the pointer to mail content.
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   osEvent getISR() {
      return osMailGet((os_mailQ_cb *)&pool, 0);
   }

   /**
    * Put a mail item into the mail queue.
    *
    * @param mail A mail block previously allocated by alloc() or calloc().
    *
    * @return osOK: no mail is available in the queue and no timeout was specified
    * @return osErrorValue: mail was previously not allocated as memory slot.
    * @return osErrorParameter: a parameter is invalid or outside of a permitted range.
    */
   osStatus put(T *mail) {
      return osMailPut((os_mailQ_cb *)&pool, mail);
   }
   /**
    * Get mail queue ID
    *
    * @return CMSIS mail queue ID
    */
   osMailQId getId() {
      return (osMailQId)queue;
   }
};
//template <class T, size_t size, Thread *thread>
//uint32_t MailQueue<T,size,thread>::queue[4+size];
//
//template <class T, size_t size, Thread *thread>
//uint32_t MailQueue<T,size,thread>::messages[3+((sizeof(T)+3)/4)*size];
//
//template <class T, size_t size, Thread *thread>
//const void *MailQueue<T,size,thread>::pool[2] = {queue, messages};
//
//template <class T, size_t size, Thread *thread>
//const os_mailQ_def MailQueue<T,size,thread>::os_mail_def = {size, sizeof(T), pool};

}; // end namespace CMSIS
#endif /* PROJECT_HEADERS_CMSIS_H_ */
