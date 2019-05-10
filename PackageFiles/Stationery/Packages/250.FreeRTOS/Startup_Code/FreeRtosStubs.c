#include "FreeRTOS.h"
#include "task.h"

/**
 * Called if a call to pvPortMalloc() fails because there is insufficient
 * free memory available in the FreeRTOS heap.  pvPortMalloc() is called
 * internally by FreeRTOS API functions that create tasks, queues, software
 * timers, and semaphores.  The size of the FreeRTOS heap is set by the
 * configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h.
 */
void __attribute__ ((__weak__)) vApplicationMallocFailedHook( void ) {
   taskDISABLE_INTERRUPTS();
   for( ;; ) {
      __asm__("bkpt");
   }
}

/**
 * Run time stack overflow checking is performed if
 * configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
 * function is called if a stack overflow is detected.
 */
void __attribute__ ((__weak__)) vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName ) {
   ( void ) pcTaskName;
   ( void ) pxTask;

   taskDISABLE_INTERRUPTS();
   for( ;; ) {
      __asm__("bkpt");
   }
}

/**
 * This function is called on each cycle of the idle task.  In this case it
 * does nothing useful, other than report the amount of FreeRTOS heap that
 * remains unallocated.
 */
void __attribute__ ((__weak__)) vApplicationIdleHook( void ) {
//   volatile size_t xFreeHeapSpace;

//   xFreeHeapSpace = xPortGetFreeHeapSize();

//   if( xFreeHeapSpace > 100 ) {
      /* By now, the kernel has allocated everything it is going to, so
  if there is a lot of heap remaining unallocated then
  the value of configTOTAL_HEAP_SIZE in FreeRTOSConfig.h can be
  reduced accordingly. */
//   }
}

/**
 * This function must be provided to initialize whichever peripheral
 * is used to generate the time base. The time base used by the run time stats
 * must have a higher resolution than the tick interrupt,
 * otherwise the gathered statistics may be too inaccurate to be truly useful.
 * It is recommended to make the time base between 10 and 20 times faster
 * than the tick interrupt.
 */
void __attribute__ ((__weak__)) vMainConfigureTimerForRunTimeStats() {
}

/**
 * This function must be provided to return the current time base value which
 * is the total time that the application has been running in the chosen time base units.
 * It must be defined return the current time base value.
 */
unsigned long __attribute__ ((__weak__)) ulMainGetRunTimeCounterValue() {
   return 0UL;
}

/**
 * The tick hook function is a hook (or callback) function that,
 * if defined and configured, will be called during each tick interrupt.
 */
void __attribute__ ((__weak__)) vApplicationTickHook() {
}
