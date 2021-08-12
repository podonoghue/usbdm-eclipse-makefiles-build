/*
 * stub.cpp
 *
 *  Created on: 9 Dec 2019
 *      Author: podonoghue
 */
#include "hardware.h"

__attribute__ ((section(".stub")))
void stub() {
//   USBDM::console.writeln("Stub...");
}

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((__weak__, alias("Default_Handler")))

/**
 * Default handler for interrupts
 */
extern "C" {

void Reset_Handler(void) __attribute__((__interrupt__));
extern uint32_t __StackTop;
}

/*
 * Each vector is assigned an unique name.  This is then 'weakly' assigned to the
 * default handler.
 * To install a handler, create a C linkage function with the name shown and it will override
 * the weak default.
 */
/*********** $start(cVectorTable) *** Do not edit after this comment ****************/
#ifdef __cplusplus
extern "C" {
#endif
// Reset handler must have C linkage
void Reset_Handler(void);
#ifdef __cplusplus
}
#endif

typedef struct {
   uint32_t *initialSP;
   intfunc  handlers[15];
} VectorTable;

extern VectorTable const __vector_table_stub;

__attribute__ ((section(".stub_interrupts")))
VectorTable const __vector_table_stub = {
                                               /*  Exc# Irq# */
   &__StackTop,                                /*    0   -16  Initial stack pointer                                                            */
   {
      stub,                                    /*    1,  -15  Reset Vector, invoked on Power up and warm reset                                 */
      NMI_Handler,                             /*    2,  -14  Non maskable Interrupt, cannot be stopped or preempted                           */
      HardFault_Handler,                       /*    3,  -13  Hard Fault, all classes of Fault                                                 */
      MemManage_Handler,                       /*    4,  -12  Memory Management, MPU mismatch, including Access Violation and No Match         */
      BusFault_Handler,                        /*    5,  -11  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
      UsageFault_Handler,                      /*    6,  -10  Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
      0,                                       /*    7,   -9                                                                                   */
      0,                                       /*    8,   -8                                                                                   */
      0,                                       /*    9,   -7                                                                                   */
      0,                                       /*   10,   -6                                                                                   */
      SVC_Handler,                             /*   11,   -5  System Service Call via SVC instruction                                          */
      DebugMon_Handler,                        /*   12,   -4  Debug Monitor                                                                    */
      0,                                       /*   13,   -3                                                                                   */
      PendSV_Handler,                          /*   14,   -2  Pendable request for system service                                              */
      SysTick_Handler,                         /*   15,   -1  System Tick Timer                                                                */
   }
};
