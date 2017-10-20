/*
 *  @file vectors.c
 *
 *  Generic vectors and security for Kinetis
 *
 *  Created on: 22/05/2017
 *      Author: podonoghue
 */
#include <stdint.h>
#include <string.h>
#include "derivative.h"

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((__weak__, alias("Default_Handler")))

#ifndef SCB_ICSR
#define SCB_ICSR (*(volatile uint32_t*)(0xE000ED04))
#define SCB_ICSR_VECTACTIVE_Pos   0U
#define SCB_ICSR_VECTACTIVE_Msk   (0x1FFUL)
#endif

/**
 * Default handler for interrupts
 *
 * Most of the vector table is initialised to point at this handler.
 *
 * If you end up here it probably means:
 *   - Failed to enable the interrupt handler in the USBDM device configuration
 *   - You have accidently enabled an interrupt source in a peripheral
 *   - Enabled the wrong interrupt source
 *   - Failed to install or create a handler for an interrupt you intended using e.g. mis-spelled the name.
 *     Compare your handler (C function) name to that used in the vector table.
 *
 * You can check 'vectorNum' below to determine the interrupt source.  Look this up in the vector table below.
 */
__attribute__((__interrupt__))
void Default_Handler(void) {

   __attribute__((unused))
   volatile uint32_t vectorNum = (SCB_ICSR&SCB_ICSR_VECTACTIVE_Msk)>>SCB_ICSR_VECTACTIVE_Pos;

   while (1) {
      __asm__("bkpt");
   }
}

typedef struct {
   unsigned int r0;
   unsigned int r1;
   unsigned int r2;
   unsigned int r3;
   unsigned int r12;
   void       (*lr)();
   void       (*pc)();
   unsigned int psr;
} ExceptionFrame;

#ifdef DEVICE_SUBFAMILY_CortexM0
/*  Low-level exception handler
 *
 *  Interface from asm to C.
 *  Passes address of exception handler to C-level handler
 *
 *  See http://www.freertos.org/Debugging-Hard-Faults-On-Cortex-M-Microcontrollers.html
 */
__attribute__((__naked__, __weak__, __interrupt__))
void HardFault_Handler(void) {
   /*
    * Determines the active stack pointer and loads it into r0
    * This is used as the 1st argument to _HardFault_Handler(volatile ExceptionFrame *exceptionFrame)
    * and allows access to the saved processor state.
    * Other registers are unchanged and available in the usual register view
    */
   __asm__ volatile ("       mov r0,lr                                     \n"); // Check mode
   __asm__ volatile ("       mov r1,#4                                     \n");
   __asm__ volatile ("       and r0,r1                                     \n");
   __asm__ volatile ("       bne skip1                                     \n");
   __asm__ volatile ("       mrs r0,msp                                    \n"); // Get active SP in r0
   __asm__ volatile ("       b   skip2                                     \n");
   __asm__ volatile ("skip1:                                               \n");
   __asm__ volatile ("       mrs r0,psp                                    \n");
   __asm__ volatile ("skip2:                                               \n");
   __asm__ volatile ("       nop                                           \n");
   __asm__ volatile ("       ldr r2, handler_addr_const                    \n"); // Go to C handler
   __asm__ volatile ("       bx r2                                         \n");
   __asm__ volatile ("       handler_addr_const: .word _HardFault_Handler  \n");
}
#endif
#if defined(DEVICE_SUBFAMILY_CortexM3) || defined(DEVICE_SUBFAMILY_CortexM3F) || \
    defined(DEVICE_SUBFAMILY_CortexM4) || defined(DEVICE_SUBFAMILY_CortexM4F)

/*  Low-level exception handler
 *
 *  Interface from asm to C.
 *  Passes address of exception handler to C-level handler
 *
 *  See http://www.freertos.org/Debugging-Hard-Faults-On-Cortex-M-Microcontrollers.html
 */
__attribute__((__naked__, __weak__, __interrupt__))
void HardFault_Handler(void) {
   /*
    * Determines the active stack pointer and loads it into r0
    * This is used as the 1st argument to _HardFault_Handler(volatile ExceptionFrame *exceptionFrame)
    * and allows access to the saved processor state.
    * Other registers are unchanged and available in the usual register view
    */
     __asm__ volatile ( "  tst   lr, #4              \n");  // Check mode
     __asm__ volatile ( "  ite   eq                  \n");  // Get active SP in r0
     __asm__ volatile ( "  mrseq r0, msp             \n");
     __asm__ volatile ( "  mrsne r0, psp             \n");
     __asm__ volatile ( "  b     _HardFault_Handler  \n");  // Go to C handler
}
#endif

/******************************************************************************/
/* Hard fault handler in C with stack frame location as input parameter
 *
 * Assumed exception frame without floating-point storage
 *
 * @param exceptionFrame address of exception frame
 *
 * If you end up here you have probably done one of the following:
 *   - Accessed illegal/unimplemented memory e.g. gone off the end of an array
 *   - Accessed a disabled peripheral - Check you have enabled the clock
 *   - Accessed unaligned memory - unlikely I guess
 *
 */
__attribute__((__naked__))
void _HardFault_Handler(volatile ExceptionFrame *exceptionFrame __attribute__((__unused__))) {
   while (1) {
      // Stop here for debugger
      __asm__("bkpt");
   }
}

void Reset_Handler(void) __attribute__((__interrupt__));

extern uint32_t __StackTop;

/*
 * Each vector is assigned an unique name.  This is then 'weakly' assigned to the
 * default handler.
 * To install a handler, create a C linkage function with the name shown and it will override
 * the weak default.
 */
void NMI_Handler(void)                        WEAK_DEFAULT_HANDLER;
void MemManage_Handler(void)                  WEAK_DEFAULT_HANDLER;
void BusFault_Handler(void)                   WEAK_DEFAULT_HANDLER;
void UsageFault_Handler(void)                 WEAK_DEFAULT_HANDLER;
void SVC_Handler(void)                        WEAK_DEFAULT_HANDLER;
void DebugMon_Handler(void)                   WEAK_DEFAULT_HANDLER;
void PendSV_Handler(void)                     WEAK_DEFAULT_HANDLER;
void SysTick_Handler(void)                    WEAK_DEFAULT_HANDLER;

void Int0_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int1_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int2_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int3_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int4_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int5_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int6_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int7_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int8_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int9_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int10_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int11_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int12_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int13_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int14_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int15_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int16_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int17_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int18_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int19_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int20_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int21_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int22_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int23_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int24_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int25_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int26_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int27_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int28_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int29_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int30_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int31_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int32_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int33_Handler(void)          WEAK_DEFAULT_HANDLER;
void Int34_Handler(void)          WEAK_DEFAULT_HANDLER;

typedef struct {
   uint32_t *initialSP;
   intfunc  handlers[];
} VectorTable;

__attribute__ ((section(".interrupt_vectors")))
VectorTable const __vector_table = {
                                     /*  Exc# Irq# */
   &__StackTop,                      /*    0   -16  Initial stack pointer                                                            */
   {
      Reset_Handler,                 /*    1   -15  Reset Handler                                                                    */
      NMI_Handler,                   /*    2,  -14  Non maskable Interrupt, cannot be stopped or preempted                           */
      HardFault_Handler,             /*    3,  -13  Hard Fault, all classes of Fault                                                 */
      MemManage_Handler,             /*    4,  -12  Memory Management, MPU mismatch, including Access Violation and No Match         */
      BusFault_Handler,              /*    5,  -11  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
      UsageFault_Handler,            /*    6,  -10  Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
      0,                             /*    7,  -9   Reserved                                                                         */
      0,                             /*    8,  -8   Reserved                                                                         */
      0,                             /*    9,  -7   Reserved                                                                         */
      0,                             /*   10,  -6   Reserved                                                                         */
      SVC_Handler,                   /*   11,  -5   System Service Call via SVC instruction                                          */
      DebugMon_Handler,              /*   12,  -4   Debug Monitor                                                                    */
      0,                             /*   13,  -3   Reserved                                                                         */
      PendSV_Handler,                /*   14,  -2   Pendable request for system service                                              */
      SysTick_Handler,               /*   15,  -1   System Tick Timer                                                                */

                                    /* External Interrupts */
          Int0_Handler,             /* Int #0  */
          Int1_Handler,             /* Int #1  */
          Int2_Handler,             /* Int #2  */
          Int3_Handler,             /* Int #3  */
          Int4_Handler,             /* Int #4  */
          Int5_Handler,             /* Int #5  */
          Int6_Handler,             /* Int #6  */
          Int7_Handler,             /* Int #7  */
          Int8_Handler,             /* Int #8  */
          Int9_Handler,             /* Int #9  */
          Int10_Handler,            /* Int #10 */
          Int11_Handler,            /* Int #11 */
          Int12_Handler,            /* Int #12 */
          Int13_Handler,            /* Int #13 */
          Int14_Handler,            /* Int #14 */
          Int15_Handler,            /* Int #15 */
          Int16_Handler,            /* Int #16 */
          Int17_Handler,            /* Int #17 */
          Int18_Handler,            /* Int #18 */
          Int19_Handler,            /* Int #19 */
          Int20_Handler,            /* Int #20 */
          Int21_Handler,            /* Int #21 */
          Int22_Handler,            /* Int #22 */
          Int23_Handler,            /* Int #23 */
          Int24_Handler,            /* Int #24 */
          Int25_Handler,            /* Int #25 */
          Int26_Handler,            /* Int #26 */
          Int27_Handler,            /* Int #27 */
          Int28_Handler,            /* Int #28 */
          Int29_Handler,            /* Int #29 */
          Int30_Handler,            /* Int #30 */
          Int31_Handler,            /* Int #31 */
          Int32_Handler,            /* Int #32 */
          Int33_Handler,            /* Int #33 */
          Int34_Handler,            /* Int #34 */
   }
};

