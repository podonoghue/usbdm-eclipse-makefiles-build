/*
 * cmsis.h
 *
 *  Created on: 20Feb.,2017
 *      Author: podonoghue
 */
#ifndef PROJECT_HEADERS_CMSIS_H_
#define PROJECT_HEADERS_CMSIS_H_

#include "cmsis_os.h"
#include "hardware.h"

namespace CMSIS {

/**
 * Wrapper for CMSIS Timer
 */
class Timer {

private:
   uint32_t           os_timer_cb[6] = { 0 };
   const osTimerDef_t os_timer_def;
   osTimerId          timer_id;

public:
   /**
    * Create timer
    *
    * @param callback Timer callback function
    * @param type     Type of timer i.e. osTimerOnce, osTimerPeriodic
    * @param argument Pointer to data to pass to callback
    */
   Timer(
         void           (*callback)(const void *),
         os_timer_type  type,
         void           *argument=nullptr) :
            os_timer_def { callback, os_timer_cb }
   {
      timer_id            = osTimerCreate(&os_timer_def, type, argument);
      USBDM::setAndCheckCmsisErrorCode((timer_id != nullptr)?osOK:osErrorOS);
   }
   /**
    * Delete timer
    */
   ~Timer() {
      osTimerDelete(timer_id);
   }
   /**
    * Stop the timer
    */
   void stop() {
      osTimerStop(timer_id);
   }
   /**
    * Start or restart timer
    *
    * @param millisec Interval in milliseconds
    */
   void start(int millisec) {
      USBDM::setAndCheckCmsisErrorCode(osTimerStart(timer_id, millisec));
   }
   /**
    * Start or restart timer
    *
    * @param interval Interval in seconds
    */
   void start(double interval) {
      start((int)round(interval*1000.0));
   }
};

/**
 * Wrapper for CMSIS Mutex
 */
class Mutex {

private:
   uint32_t             os_mutex_cb[4] = { 0 };
   const osMutexDef_t   os_mutex_def   = { os_mutex_cb };
   osMutexId            mutex_id;

public:
   /**
    * Create mutex
    */
   Mutex() {
      mutex_id = osMutexCreate(&os_mutex_def);
      USBDM::setAndCheckCmsisErrorCode((mutex_id != nullptr)?osOK:osErrorOS);
   }
   /**
    * Delete mutex
    */
   ~Mutex() {
      osMutexDelete(mutex_id);
   }
   /**
    * Obtain mutex
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    */
   void wait(uint32_t millisec=osWaitForever) {
      osMutexWait(mutex_id, millisec);
   }
   /**
    * Release mutex
    */
   void release() {
      osMutexRelease(mutex_id);
   }
};
/**
 * Wrapper for CMSIS Semaphore
 */
class Semaphore {

private:
   uint32_t           os_semaphore_cb[2] = { 0 };
   osSemaphoreDef_t   os_semaphore_def = { os_semaphore_cb };
   osSemaphoreId      semaphore_id;

public:
   /**
    * Create semaphore
    */
   Semaphore(int32_t count) {
      semaphore_id = osSemaphoreCreate(&os_semaphore_def, count);
      USBDM::setAndCheckCmsisErrorCode((semaphore_id != nullptr)?osOK:osErrorOS);
   }
   /**
    * Delete semaphore
    */
   ~Semaphore() {
      osSemaphoreDelete(semaphore_id);
   }
   /**
    * Obtain semaphore
    *
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    */
   void wait(uint32_t millisec=osWaitForever) {
      osSemaphoreWait(semaphore_id, millisec);
   }
   /**
    * Release semaphore
    */
   void release() {
      osSemaphoreRelease(semaphore_id);
   }
};
/**
 * Wrapper for CMSIS Thread
 */
class Thread {

private:

   const osThreadDef_t thread_def;
   osThreadId thread_id;

public:
   /**
    * Create thread
    *
    * @param argument   Argument passed to thread function
    * @param priority   Priority of thread e.g. osPriorityNormal
    * @param instances  Number of times this thread will be instantiated
    * @param stackSize  Stack size for thread or 0 to indicate default
    */
   Thread(
         void (*threadFunction)(const void *),
         void       *argument=nullptr,
         osPriority  priority=osPriorityNormal,
         uint32_t    instances=1,
         uint32_t    stackSize=0) :
            thread_def {threadFunction, priority, instances, stackSize }
   {
      thread_id = osThreadCreate(&thread_def, argument);
      USBDM::setAndCheckCmsisErrorCode((thread_id != nullptr)?osOK:osErrorOS);
   };
   /**
    * Delete thread
    */
   ~Thread() {
      osThreadTerminate(thread_id);
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
    * @return priority of thread
    */
   osPriority getPriority() {
      return osThreadGetPriority(thread_id);
   }
   /**
    * Set thread Priority
    *
    * @param priority Priority to set for thread
    */
   osStatus setPriority(osPriority priority) {
      return osThreadSetPriority(thread_id, priority);
   }
   /**
    * Set thread Priority
    *
    * @param priority Priority to set for thread
    */
   osStatus yield() {
      return osThreadYield();
   }
   /**
    * Set the specified Signal Flags
    *
    * @param flags    Flags to set
    */
   int32_t signalSet(int32_t flags) {
      return osSignalSet(thread_id, flags);
   }
   /**
    * Clear the specified Signal Flags
    *
    * @param flags    Flags to clear
    */
   int32_t signalClear(int32_t flags) {
      return osSignalClear(thread_id, flags);
   }
   /**
    * Wait for one or more Signal Flags to become signaled for the current thread.
    *
    * @param flags    Flags to wait on
    * @param millisec How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return Structure describing event occurring
    */
   static osEvent signalWait(int32_t flags, uint32_t millisec=osWaitForever) {
      return osSignalWait(flags, millisec);
   }

};

}; // end namespace CMSIS

#endif /* PROJECT_HEADERS_CMSIS_H_ */
