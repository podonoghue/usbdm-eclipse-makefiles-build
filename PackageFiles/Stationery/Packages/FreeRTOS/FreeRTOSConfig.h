/**
 * @file FreeRTOSConfig.h
 */
#ifndef _FREERTOS_CONFIG_H_
#define _FREERTOS_CONFIG_H_

/**
 * Most options have been moved to FreeRTOSConfig.cfg
 */
#include "FreeRTOSConfig.cfg"

#ifdef __cplusplus
extern "C" {
#endif
void           vApplicationMallocFailedHook( void );
void           vApplicationIdleHook( void );
void           vMainConfigureTimerForRunTimeStats(void);
unsigned long  ulMainGetRunTimeCounterValue(void);
void           vApplicationTickHook(void);
#ifdef __cplusplus
}
#endif

#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() vMainConfigureTimerForRunTimeStats()
#define portGET_RUN_TIME_COUNTER_VALUE()         ulMainGetRunTimeCounterValue()

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
    /* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
    #define configPRIO_BITS               __NVIC_PRIO_BITS
#else
    #define configPRIO_BITS               (4)        /* 15 priority levels */
#endif

/*
 * The lowest interrupt priority that can be used in a call to a "set priority" function.
 */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY ((1U << (configPRIO_BITS)) - 1)

/*
 * The highest interrupt priority that can be used by any interrupt service
 * routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
 * INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
 * PRIORITY THAN THIS! (higher priorities are lower numeric values.
 */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    (2)

/*
 * Interrupt priorities used by the kernel port layer itself.
 * These are generic to all Cortex-M ports, and do not rely on any particular library functions.
 */
#define configKERNEL_INTERRUPT_PRIORITY           (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

/*
 * !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
 * See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html.
 */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY     (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

/*
 * Normal assert() semantics without relying on the provision of an assert.h
 * header file.
 */
#define configASSERT(x) if((x) == 0) { taskDISABLE_INTERRUPTS(); for(;;); }

/*
 * Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
 * standard names.
 */
#define vPortSVCHandler     SVC_Handler
#define xPortPendSVHandler  PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* _FREERTOS_CONFIG_H_ */
