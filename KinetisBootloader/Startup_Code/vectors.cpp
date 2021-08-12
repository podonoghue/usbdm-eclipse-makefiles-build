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
#include "usb.h"
#include "pit.h"
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
#ifdef __cplusplus
extern "C" {
#endif
// Reset handler must have C linkage
void Reset_Handler(void);
#ifdef __cplusplus
}
#endif
void NMI_Handler(void)                        WEAK_DEFAULT_HANDLER;
void MemManage_Handler(void)                  WEAK_DEFAULT_HANDLER;
void BusFault_Handler(void)                   WEAK_DEFAULT_HANDLER;
void UsageFault_Handler(void)                 WEAK_DEFAULT_HANDLER;
void SVC_Handler(void)                        WEAK_DEFAULT_HANDLER;
void DebugMon_Handler(void)                   WEAK_DEFAULT_HANDLER;
void PendSV_Handler(void)                     WEAK_DEFAULT_HANDLER;
void SysTick_Handler(void)                    WEAK_DEFAULT_HANDLER;
void DMA0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void DMA1_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void DMA2_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void DMA3_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void DMA_Error_IRQHandler(void)               WEAK_DEFAULT_HANDLER;
void FTF_Command_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void FTF_ReadCollision_IRQHandler(void)       WEAK_DEFAULT_HANDLER;
void PMC_IRQHandler(void)                     WEAK_DEFAULT_HANDLER;
void LLWU_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void WDOG_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void I2C0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void SPI0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void I2S0_Tx_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void I2S0_Rx_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void UART0_Lon_IRQHandler(void)               WEAK_DEFAULT_HANDLER;
void UART0_RxTx_IRQHandler(void)              WEAK_DEFAULT_HANDLER;
void UART0_Error_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void UART1_RxTx_IRQHandler(void)              WEAK_DEFAULT_HANDLER;
void UART1_Error_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void UART2_RxTx_IRQHandler(void)              WEAK_DEFAULT_HANDLER;
void UART2_Error_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void ADC0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void CMP0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void CMP1_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void FTM0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void FTM1_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void CMT_IRQHandler(void)                     WEAK_DEFAULT_HANDLER;
void RTC_Alarm_IRQHandler(void)               WEAK_DEFAULT_HANDLER;
void RTC_Seconds_IRQHandler(void)             WEAK_DEFAULT_HANDLER;
void PDB0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void USBDCD0_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void TSI0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void MCG_IRQHandler(void)                     WEAK_DEFAULT_HANDLER;
void LPTMR0_IRQHandler(void)                  WEAK_DEFAULT_HANDLER;
void PORTA_IRQHandler(void)                   WEAK_DEFAULT_HANDLER;
void PORTB_IRQHandler(void)                   WEAK_DEFAULT_HANDLER;
void PORTC_IRQHandler(void)                   WEAK_DEFAULT_HANDLER;
void PORTD_IRQHandler(void)                   WEAK_DEFAULT_HANDLER;
void PORTE_IRQHandler(void)                   WEAK_DEFAULT_HANDLER;
void SWI_IRQHandler(void)                     WEAK_DEFAULT_HANDLER;

typedef struct {
   uint32_t *initialSP;
   intfunc  handlers[61];
} VectorTable;

extern VectorTable const __vector_table;

__attribute__ ((section(".interrupt_vectors")))
VectorTable const __vector_table = {
                                               /*  Exc# Irq# */
   &__StackTop,                                /*    0   -16  Initial stack pointer                                                            */
   {
      Reset_Handler,                           /*    1,  -15  Reset Vector, invoked on Power up and warm reset                                 */
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

                                               /* External Interrupts */
      DMA0_IRQHandler,                         /*   16,    0  Direct memory access controller                                                  */
      DMA1_IRQHandler,                         /*   17,    1  Direct memory access controller                                                  */
      DMA2_IRQHandler,                         /*   18,    2  Direct memory access controller                                                  */
      DMA3_IRQHandler,                         /*   19,    3  Direct memory access controller                                                  */
      DMA_Error_IRQHandler,                    /*   20,    4  DMA error interrupt                                                              */
      Default_Handler,                         /*   21,    5                                                                                   */
      FTF_Command_IRQHandler,                  /*   22,    6  Flash Memory Interface                                                           */
      FTF_ReadCollision_IRQHandler,            /*   23,    7  Flash Memory Interface                                                           */
      PMC_IRQHandler,                          /*   24,    8  Power Management Controller                                                      */
      LLWU_IRQHandler,                         /*   25,    9  Low Leakage Wakeup                                                               */
      WDOG_IRQHandler,                         /*   26,   10  External Watchdog Monitor                                                        */
      I2C0_IRQHandler,                         /*   27,   11  Inter-Integrated Circuit                                                         */
      SPI0_IRQHandler,                         /*   28,   12  Serial Peripheral Interface                                                      */
      I2S0_Tx_IRQHandler,                      /*   29,   13  Synchronous Serial Interface                                                     */
      I2S0_Rx_IRQHandler,                      /*   30,   14  Synchronous Serial Interface                                                     */
      UART0_Lon_IRQHandler,                    /*   31,   15  Serial Communication Interface                                                   */
      UART0_RxTx_IRQHandler,                   /*   32,   16  Serial Communication Interface                                                   */
      UART0_Error_IRQHandler,                  /*   33,   17  Serial Communication Interface                                                   */
      UART1_RxTx_IRQHandler,                   /*   34,   18  Serial Communication Interface                                                   */
      UART1_Error_IRQHandler,                  /*   35,   19  Serial Communication Interface                                                   */
      UART2_RxTx_IRQHandler,                   /*   36,   20  Serial Communication Interface                                                   */
      UART2_Error_IRQHandler,                  /*   37,   21  Serial Communication Interface                                                   */
      ADC0_IRQHandler,                         /*   38,   22  Analogue to Digital Converter                                                    */
      CMP0_IRQHandler,                         /*   39,   23  High-Speed Comparator                                                            */
      CMP1_IRQHandler,                         /*   40,   24  High-Speed Comparator                                                            */
      FTM0_IRQHandler,                         /*   41,   25  FlexTimer Module                                                                 */
      FTM1_IRQHandler,                         /*   42,   26  FlexTimer Module                                                                 */
      CMT_IRQHandler,                          /*   43,   27  Carrier Modulator Transmitter                                                    */
      RTC_Alarm_IRQHandler,                    /*   44,   28  Real Time Clock                                                                  */
      RTC_Seconds_IRQHandler,                  /*   45,   29  Real Time Clock                                                                  */
      USBDM::Pit::Channel<0>::irqHandler,      /*   46,   30  Periodic Interrupt Timer                                                         */
      USBDM::Pit::Channel<1>::irqHandler,      /*   47,   31  Periodic Interrupt Timer                                                         */
      USBDM::Pit::Channel<2>::irqHandler,      /*   48,   32  Periodic Interrupt Timer                                                         */
      USBDM::Pit::Channel<3>::irqHandler,      /*   49,   33  Periodic Interrupt Timer                                                         */
      PDB0_IRQHandler,                         /*   50,   34  Programmable Delay Block                                                         */
      USBDM::Usb0::irqHandler,                 /*   51,   35  Universal Serial Bus                                                             */
      USBDCD0_IRQHandler,                      /*   52,   36  USB Device Charger Detection                                                     */
      TSI0_IRQHandler,                         /*   53,   37  Touch Sense Interface                                                            */
      MCG_IRQHandler,                          /*   54,   38  Multipurpose Clock Generator                                                     */
      LPTMR0_IRQHandler,                       /*   55,   39  Low Power Timer                                                                  */
      PORTA_IRQHandler,                        /*   56,   40  General Purpose Input/Output                                                     */
      PORTB_IRQHandler,                        /*   57,   41  General Purpose Input/Output                                                     */
      PORTC_IRQHandler,                        /*   58,   42  General Purpose Input/Output                                                     */
      PORTD_IRQHandler,                        /*   59,   43  General Purpose Input/Output                                                     */
      PORTE_IRQHandler,                        /*   60,   44  General Purpose Input/Output                                                     */
      SWI_IRQHandler,                          /*   61,   45  Software interrupt                                                               */
   }
};

/*********** $end(cVectorTable)   *** Do not edit above this comment ***************/


