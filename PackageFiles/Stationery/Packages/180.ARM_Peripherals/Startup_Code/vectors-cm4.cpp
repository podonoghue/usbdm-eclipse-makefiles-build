/*
 *  @file vectors.cpp  (180.ARM_Peripherals/Startup_Code/vectors-cm4.cpp)
 *
 *  Generated from  vectors-cm4.cpp
 *
 *  Generic vectors Kinetis Cortex-M4 devices
 *
 *  Based on Keil Application Note 209
 *
 *  Created on: 22/05/2017
 *      Author: podonoghue
 */
#include <stdint.h>
#include <string.h>
#include "derivative.h"
#include "hardware.h"

/*********** $start(VectorsIncludeFiles) *** Do not edit after this comment ****************/
/*********** $end(VectorsIncludeFiles)   *** Do not edit above this comment ***************/

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((__nothrow__, __weak__, alias("Default_Handler")))
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
extern "C" {
__attribute__((__interrupt__))
void Default_Handler(void) {

#ifdef SCB
   __attribute__((unused))
   volatile uint32_t vectorNum = (SCB->ICSR&SCB_ICSR_VECTACTIVE_Msk)>>SCB_ICSR_VECTACTIVE_Pos;
#endif

   while (1) {
      __asm__("bkpt");
   }
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
     __asm__ volatile ( "  mov   r1, lr              \n");  // Get LR=EXC_RETURN in r1
     __asm__ volatile ( "  b     _HardFault_Handler  \n");  // Go to C handler
}

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
extern "C" {
__attribute__((__naked__))
void _HardFault_Handler(
      volatile ExceptionFrame *exceptionFrame __attribute__((__unused__)),
      uint32_t execReturn                     __attribute__((__unused__)) ) {

#if defined(DEBUG_BUILD) && USE_CONSOLE
   using namespace USBDM;

   console.setPadding(Padding_LeadingZeroes);
   console.setWidth(8);
   console.write("\n[Hardfault]\n - Stack frame:\n");
   console.write("R0  = 0x").writeln(exceptionFrame->r0,  Radix_16);
   console.write("R1  = 0x").writeln(exceptionFrame->r1,  Radix_16);
   console.write("R2  = 0x").writeln(exceptionFrame->r2,  Radix_16);
   console.write("R3  = 0x").writeln(exceptionFrame->r3,  Radix_16);
   console.write("R12 = 0x").writeln(exceptionFrame->r12, Radix_16);
   console.write("LR  = 0x").writeln((void*)(exceptionFrame->lr),  Radix_16);
   console.write("PC  = 0x").writeln((void*)(exceptionFrame->pc),  Radix_16);
   console.write("PSR = 0x").writeln(exceptionFrame->psr, Radix_16);
   console.write ("- FSR/FAR:\n");
   uint32_t cfsr = SCB->CFSR;
   console.write("CFSR = 0x").writeln(cfsr);
   console.write("HFSR = 0x").writeln(SCB->HFSR, Radix_16);
   console.write("DFSR = 0x").writeln(SCB->DFSR, Radix_16);
   console.write("AFSR = 0x").writeln(SCB->AFSR, Radix_16);
   if (cfsr & 0x0080) console.write("MMFAR = 0").writeln(SCB->MMFAR, Radix_16);
   if (cfsr & 0x8000) console.write("BFAR = 0x").writeln(SCB->BFAR,  Radix_16);
   console.writeln("- Misc");
   console.write("LR/EXC_RETURN= 0x").writeln(execReturn,  Radix_16);
#endif

   while (1) {
      // Stop here for debugger
      __asm__("bkpt");
   }
}

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
/*********** $end(cVectorTable)   *** Do not edit above this comment ***************/


