/*
 *  Vectors-mk.c
 *
 *  Generic vectors and security for Kinetis
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */
#include <stdint.h>
#include <string.h>
#include "derivative.h"

#define DEVICE_SUBFAMILY_CortexM4

#if !defined(OPEN_SDA_V1)
/*
 * OpenSDA doesn't use the security area
 */
/*
 * Security information
 */
typedef struct {
    uint8_t  backdoorKey[8];
    uint32_t fprot;
    uint8_t  fsec;
    uint8_t  fopt;
    uint8_t  feprot;
    uint8_t  fdprot;
} SecurityInfo;

__attribute__ ((section(".security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    /* fprot    */ 0xFFFFFFFF,
    /* fsec     */ FTFL_FSEC_KEYEN(3)|FTFL_FSEC_MEEN(3)|FTFL_FSEC_FSLACC(3)|FTFL_FSEC_SEC(2),
    /* fopt     */ 0xFF,
    /* feprot   */ 0xFF,
    /* fdprot   */ 0xFF,
};
#endif

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((__weak__, alias("Default_Handler")))

#ifndef SCB_ICSR
#define SCB_ICSR (*(volatile uint32_t*)(0xE000ED04))
#endif

/**
 * Default handler for interrupts
 *
 * Most of the vector table is initialised to point at this handler.
 *
 * If you end up here it probably means:
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
      __BKPT(0);
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
__attribute__((__naked__))
void _HardFault_Handler(volatile ExceptionFrame *exceptionFrame __attribute__((__unused__))) {
   while (1) {
      // Stop here for debugger
      __BKPT(0);
   }
}

void __HardReset(void) __attribute__((__interrupt__));
extern uint32_t __StackTop;

/*
 * Each vector is assigned an unique name.  This is then 'weakly' assigned to the
 * default handler.
 * To install a handler, create a function with the name shown and it will override
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
void DMA0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void DMA1_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void DMA2_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void DMA3_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void DMA_Error_IRQHandler(void)               WEAK_DEFAULT_HANDLER;
void FTFL_Command_IRQHandler(void)            WEAK_DEFAULT_HANDLER;
void FTFL_Collision_IRQHandler(void)          WEAK_DEFAULT_HANDLER;
void PMC_IRQHandler(void)                     WEAK_DEFAULT_HANDLER;
void LLWU_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void WDOG_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void I2C0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void SPI0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void I2S0_Tx_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void I2S0_Rx_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void UART0_LON_IRQHandler(void)               WEAK_DEFAULT_HANDLER;
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
void PIT_Ch0_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void PIT_Ch1_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void PIT_Ch2_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void PIT_Ch3_IRQHandler(void)                 WEAK_DEFAULT_HANDLER;
void PDB0_IRQHandler(void)                    WEAK_DEFAULT_HANDLER;
void USBOTG_IRQHandler(void)                  WEAK_DEFAULT_HANDLER;
void USBDCD_IRQHandler(void)                  WEAK_DEFAULT_HANDLER;
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
   intfunc  handlers[];
} VectorTable;

__attribute__ ((section(".interrupt_vectors")))
VectorTable const __vector_table = {
                                     /*  Exc# Irq# */
   &__StackTop,                      /*    0   -16  Initial stack pointer                                                            */
   {
      __HardReset,                   /*    1   -15  Reset Handler                                                                    */
      NMI_Handler,                   /*    2,  -14  Non maskable Interrupt, cannot be stopped or preempted                           */
      HardFault_Handler,             /*    3,  -13  Hard Fault, all classes of Fault                                                 */
      MemManage_Handler,             /*    4,  -12  Memory Management, MPU mismatch, including Access Violation and No Match         */
      BusFault_Handler,              /*    5,  -11  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
      UsageFault_Handler,            /*    6,  -10  Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
      0,                             /*    7,   -9  Reserved                                                                         */
      0,                             /*    8,   -8  Reserved                                                                         */
      0,                             /*    9,   -7  Reserved                                                                         */
      0,                             /*   10,   -6  Reserved                                                                         */
      SVC_Handler,                   /*   11,   -5  System Service Call via SVC instruction                                          */
      DebugMon_Handler,              /*   12,   -4  Debug Monitor                                                                    */
      0,                             /*   13,   -3  Reserved                                                                         */
      PendSV_Handler,                /*   14,   -2  Pendable request for system service                                              */
      SysTick_Handler,               /*   15,   -1  System Tick Timer                                                                */

                                     /* External Interrupts */
      DMA0_IRQHandler,               /*   16,    0  DMA channel 0 transfer complete interrupt                                        */
      DMA1_IRQHandler,               /*   17,    1  DMA channel 1 transfer complete interrupt                                        */
      DMA2_IRQHandler,               /*   18,    2  DMA channel 2 transfer complete interrupt                                        */
      DMA3_IRQHandler,               /*   19,    3  DMA channel 3 transfer complete interrupt                                        */
      DMA_Error_IRQHandler,          /*   20,    4  DMA error interrupt                                                              */
      Default_Handler,               /*   21,    5  Reserved                                                                         */
      FTFL_Command_IRQHandler,       /*   22,    6  FTFL interrupt                                                                   */
      FTFL_Collision_IRQHandler,     /*   23,    7  FTFL Read collision interrupt                                                    */
      PMC_IRQHandler,                /*   24,    8  PMC Low Voltage Detect, Low Voltage Warning                                      */
      LLWU_IRQHandler,               /*   25,    9  LLWU Low Leakage Wakeup                                                          */
      WDOG_IRQHandler,               /*   26,   10  WDOG interrupt                                                                   */
      I2C0_IRQHandler,               /*   27,   11  I2C0 interrupt                                                                   */
      SPI0_IRQHandler,               /*   28,   12  SPI0 interrupt                                                                   */
      I2S0_Tx_IRQHandler,            /*   29,   13  I2S0 transmit interrupt                                                          */
      I2S0_Rx_IRQHandler,            /*   30,   14  I2S0 receive interrupt                                                           */
      UART0_LON_IRQHandler,          /*   31,   15  UART0 LON interrupt                                                              */
      UART0_RxTx_IRQHandler,         /*   32,   16  UART0 receive/transmit interrupt                                                 */
      UART0_Error_IRQHandler,        /*   33,   17  UART0 error interrupt                                                            */
      UART1_RxTx_IRQHandler,         /*   34,   18  UART1 receive/transmit interrupt                                                 */
      UART1_Error_IRQHandler,        /*   35,   19  UART1 error interrupt                                                            */
      UART2_RxTx_IRQHandler,         /*   36,   20  UART2 receive/transmit interrupt                                                 */
      UART2_Error_IRQHandler,        /*   37,   21  UART0 error interrupt                                                            */
      ADC0_IRQHandler,               /*   38,   22  ADC0 interrupt                                                                   */
      CMP0_IRQHandler,               /*   39,   23  CMP0 interrupt                                                                   */
      CMP1_IRQHandler,               /*   40,   24  CMP1 interrupt                                                                   */
      FTM0_IRQHandler,               /*   41,   25  FTM0 fault, overflow and channels interrupt                                      */
      FTM1_IRQHandler,               /*   42,   26  FTM1 fault, overflow and channels interrupt                                      */
      CMT_IRQHandler,                /*   43,   27  CMT interrupt                                                                    */
      RTC_Alarm_IRQHandler,          /*   44,   28  RTC interrupt                                                                    */
      RTC_Seconds_IRQHandler,        /*   45,   29  RTC seconds interrupt                                                            */
      PIT_Ch0_IRQHandler,            /*   46,   30  PIT timer channel 0 interrupt                                                    */
      PIT_Ch1_IRQHandler,            /*   47,   31  PIT timer channel 1 interrupt                                                    */
      PIT_Ch2_IRQHandler,            /*   48,   32  PIT timer channel 2 interrupt                                                    */
      PIT_Ch3_IRQHandler,            /*   49,   33  PIT timer channel 3 interrupt                                                    */
      PDB0_IRQHandler,               /*   50,   34  PDB0 Programmable Delay Block interrupt                                          */
      USBOTG_IRQHandler,             /*   51,   35  USB0 OTG interrupt                                                               */
      USBDCD_IRQHandler,             /*   52,   36  USBDCD interrupt                                                                 */
      TSI0_IRQHandler,               /*   53,   37  TSI0 interrupt                                                                   */
      MCG_IRQHandler,                /*   54,   38  MCG interrupt                                                                    */
      LPTMR0_IRQHandler,             /*   55,   39  LPTMR Low Power Timer interrupt                                                  */
      PORTA_IRQHandler,              /*   56,   40  Port A interrupt                                                                 */
      PORTB_IRQHandler,              /*   57,   41  Port B interrupt                                                                 */
      PORTC_IRQHandler,              /*   58,   42  Port C interrupt                                                                 */
      PORTD_IRQHandler,              /*   59,   43  Port D interrupt                                                                 */
      PORTE_IRQHandler,              /*   60,   44  Port E interrupt                                                                 */
      SWI_IRQHandler,                /*   61,   45  Software interrupt                                                               */
      Default_Handler,               /*   62,   46  Reserved                                                                         */
      Default_Handler,               /*   63,   47  Reserved                                                                         */
      Default_Handler,               /*   64,   48  Reserved                                                                         */
      Default_Handler,               /*   65,   49  Reserved                                                                         */
      Default_Handler,               /*   66,   50  Reserved                                                                         */
      Default_Handler,               /*   67,   51  Reserved                                                                         */
      Default_Handler,               /*   68,   52  Reserved                                                                         */
      Default_Handler,               /*   69,   53  Reserved                                                                         */
      Default_Handler,               /*   70,   54  Reserved                                                                         */
      Default_Handler,               /*   71,   55  Reserved                                                                         */
      Default_Handler,               /*   72,   56  Reserved                                                                         */
      Default_Handler,               /*   73,   57  Reserved                                                                         */
      Default_Handler,               /*   74,   58  Reserved                                                                         */
      Default_Handler,               /*   75,   59  Reserved                                                                         */
      Default_Handler,               /*   76,   60  Reserved                                                                         */
      Default_Handler,               /*   77,   61  Reserved                                                                         */
      Default_Handler,               /*   78,   62  Reserved                                                                         */
      Default_Handler,               /*   79,   63  Reserved                                                                         */
      Default_Handler,               /*   80,   64  Reserved                                                                         */
      Default_Handler,               /*   81,   65  Reserved                                                                         */
      Default_Handler,               /*   82,   66  Reserved                                                                         */
      Default_Handler,               /*   83,   67  Reserved                                                                         */
      Default_Handler,               /*   84,   68  Reserved                                                                         */
      Default_Handler,               /*   85,   69  Reserved                                                                         */
      Default_Handler,               /*   86,   70  Reserved                                                                         */
      Default_Handler,               /*   87,   71  Reserved                                                                         */
      Default_Handler,               /*   88,   72  Reserved                                                                         */
      Default_Handler,               /*   89,   73  Reserved                                                                         */
      Default_Handler,               /*   90,   74  Reserved                                                                         */
      Default_Handler,               /*   91,   75  Reserved                                                                         */
      Default_Handler,               /*   92,   76  Reserved                                                                         */
      Default_Handler,               /*   93,   77  Reserved                                                                         */
      Default_Handler,               /*   94,   78  Reserved                                                                         */
      Default_Handler,               /*   95,   79  Reserved                                                                         */
      Default_Handler,               /*   96,   80  Reserved                                                                         */
      Default_Handler,               /*   97,   81  Reserved                                                                         */
      Default_Handler,               /*   98,   82  Reserved                                                                         */
      Default_Handler,               /*   99,   83  Reserved                                                                         */
      Default_Handler,               /*  100,   84  Reserved                                                                         */
      Default_Handler,               /*  101,   85  Reserved                                                                         */
      Default_Handler,               /*  102,   86  Reserved                                                                         */
      Default_Handler,               /*  103,   87  Reserved                                                                         */
      Default_Handler,               /*  104,   88  Reserved                                                                         */
      Default_Handler,               /*  105,   89  Reserved                                                                         */
      Default_Handler,               /*  106,   90  Reserved                                                                         */
      Default_Handler,               /*  107,   91  Reserved                                                                         */
      Default_Handler,               /*  108,   92  Reserved                                                                         */
      Default_Handler,               /*  109,   93  Reserved                                                                         */
      Default_Handler,               /*  110,   94  Reserved                                                                         */
      Default_Handler,               /*  111,   95  Reserved                                                                         */
      Default_Handler,               /*  112,   96  Reserved                                                                         */
      Default_Handler,               /*  113,   97  Reserved                                                                         */
      Default_Handler,               /*  114,   98  Reserved                                                                         */
      Default_Handler,               /*  115,   99  Reserved                                                                         */
      Default_Handler,               /*  116,  100  Reserved                                                                         */
      Default_Handler,               /*  117,  101  Reserved                                                                         */
      Default_Handler,               /*  118,  102  Reserved                                                                         */
      Default_Handler,               /*  119,  103  Reserved                                                                         */
      Default_Handler,               /*  120,  104  Reserved                                                                         */
      Default_Handler,               /*  121,  105  Reserved                                                                         */
      Default_Handler,               /*  122,  106  Reserved                                                                         */
      Default_Handler,               /*  123,  107  Reserved                                                                         */
      Default_Handler,               /*  124,  108  Reserved                                                                         */
      Default_Handler,               /*  125,  109  Reserved                                                                         */
      Default_Handler,               /*  126,  110  Reserved                                                                         */
      Default_Handler,               /*  127,  111  Reserved                                                                         */
      Default_Handler,               /*  128,  112  Reserved                                                                         */
      Default_Handler,               /*  129,  113  Reserved                                                                         */
      Default_Handler,               /*  130,  114  Reserved                                                                         */
      Default_Handler,               /*  131,  115  Reserved                                                                         */
      Default_Handler,               /*  132,  116  Reserved                                                                         */
      Default_Handler,               /*  133,  117  Reserved                                                                         */
      Default_Handler,               /*  134,  118  Reserved                                                                         */
      Default_Handler,               /*  135,  119  Reserved                                                                         */
      Default_Handler,               /*  136,  120  Reserved                                                                         */
      Default_Handler,               /*  137,  121  Reserved                                                                         */
      Default_Handler,               /*  138,  122  Reserved                                                                         */
      Default_Handler,               /*  139,  123  Reserved                                                                         */
      Default_Handler,               /*  140,  124  Reserved                                                                         */
      Default_Handler,               /*  141,  125  Reserved                                                                         */
      Default_Handler,               /*  142,  126  Reserved                                                                         */
      Default_Handler,               /*  143,  127  Reserved                                                                         */
      Default_Handler,               /*  144,  128  Reserved                                                                         */
      Default_Handler,               /*  145,  129  Reserved                                                                         */
      Default_Handler,               /*  146,  130  Reserved                                                                         */
      Default_Handler,               /*  147,  131  Reserved                                                                         */
      Default_Handler,               /*  148,  132  Reserved                                                                         */
      Default_Handler,               /*  149,  133  Reserved                                                                         */
      Default_Handler,               /*  150,  134  Reserved                                                                         */
      Default_Handler,               /*  151,  135  Reserved                                                                         */
      Default_Handler,               /*  152,  136  Reserved                                                                         */
      Default_Handler,               /*  153,  137  Reserved                                                                         */
      Default_Handler,               /*  154,  138  Reserved                                                                         */
      Default_Handler,               /*  155,  139  Reserved                                                                         */
      Default_Handler,               /*  156,  140  Reserved                                                                         */
      Default_Handler,               /*  157,  141  Reserved                                                                         */
      Default_Handler,               /*  158,  142  Reserved                                                                         */
      Default_Handler,               /*  159,  143  Reserved                                                                         */
      Default_Handler,               /*  160,  144  Reserved                                                                         */
      Default_Handler,               /*  161,  145  Reserved                                                                         */
      Default_Handler,               /*  162,  146  Reserved                                                                         */
      Default_Handler,               /*  163,  147  Reserved                                                                         */
      Default_Handler,               /*  164,  148  Reserved                                                                         */
      Default_Handler,               /*  165,  149  Reserved                                                                         */
      Default_Handler,               /*  166,  150  Reserved                                                                         */
      Default_Handler,               /*  167,  151  Reserved                                                                         */
      Default_Handler,               /*  168,  152  Reserved                                                                         */
      Default_Handler,               /*  169,  153  Reserved                                                                         */
      Default_Handler,               /*  170,  154  Reserved                                                                         */
      Default_Handler,               /*  171,  155  Reserved                                                                         */
      Default_Handler,               /*  172,  156  Reserved                                                                         */
      Default_Handler,               /*  173,  157  Reserved                                                                         */
      Default_Handler,               /*  174,  158  Reserved                                                                         */
      Default_Handler,               /*  175,  159  Reserved                                                                         */
      Default_Handler,               /*  176,  160  Reserved                                                                         */
      Default_Handler,               /*  177,  161  Reserved                                                                         */
      Default_Handler,               /*  178,  162  Reserved                                                                         */
      Default_Handler,               /*  179,  163  Reserved                                                                         */
      Default_Handler,               /*  180,  164  Reserved                                                                         */
      Default_Handler,               /*  181,  165  Reserved                                                                         */
      Default_Handler,               /*  182,  166  Reserved                                                                         */
      Default_Handler,               /*  183,  167  Reserved                                                                         */
      Default_Handler,               /*  184,  168  Reserved                                                                         */
      Default_Handler,               /*  185,  169  Reserved                                                                         */
      Default_Handler,               /*  186,  170  Reserved                                                                         */
      Default_Handler,               /*  187,  171  Reserved                                                                         */
      Default_Handler,               /*  188,  172  Reserved                                                                         */
      Default_Handler,               /*  189,  173  Reserved                                                                         */
      Default_Handler,               /*  190,  174  Reserved                                                                         */
      Default_Handler,               /*  191,  175  Reserved                                                                         */
      Default_Handler,               /*  192,  176  Reserved                                                                         */
      Default_Handler,               /*  193,  177  Reserved                                                                         */
      Default_Handler,               /*  194,  178  Reserved                                                                         */
      Default_Handler,               /*  195,  179  Reserved                                                                         */
      Default_Handler,               /*  196,  180  Reserved                                                                         */
      Default_Handler,               /*  197,  181  Reserved                                                                         */
      Default_Handler,               /*  198,  182  Reserved                                                                         */
      Default_Handler,               /*  199,  183  Reserved                                                                         */
      Default_Handler,               /*  200,  184  Reserved                                                                         */
      Default_Handler,               /*  201,  185  Reserved                                                                         */
      Default_Handler,               /*  202,  186  Reserved                                                                         */
      Default_Handler,               /*  203,  187  Reserved                                                                         */
      Default_Handler,               /*  204,  188  Reserved                                                                         */
      Default_Handler,               /*  205,  189  Reserved                                                                         */
      Default_Handler,               /*  206,  190  Reserved                                                                         */
      Default_Handler,               /*  207,  191  Reserved                                                                         */
      Default_Handler,               /*  208,  192  Reserved                                                                         */
      Default_Handler,               /*  209,  193  Reserved                                                                         */
      Default_Handler,               /*  210,  194  Reserved                                                                         */
      Default_Handler,               /*  211,  195  Reserved                                                                         */
      Default_Handler,               /*  212,  196  Reserved                                                                         */
      Default_Handler,               /*  213,  197  Reserved                                                                         */
      Default_Handler,               /*  214,  198  Reserved                                                                         */
      Default_Handler,               /*  215,  199  Reserved                                                                         */
      Default_Handler,               /*  216,  200  Reserved                                                                         */
      Default_Handler,               /*  217,  201  Reserved                                                                         */
      Default_Handler,               /*  218,  202  Reserved                                                                         */
      Default_Handler,               /*  219,  203  Reserved                                                                         */
      Default_Handler,               /*  220,  204  Reserved                                                                         */
      Default_Handler,               /*  221,  205  Reserved                                                                         */
      Default_Handler,               /*  222,  206  Reserved                                                                         */
      Default_Handler,               /*  223,  207  Reserved                                                                         */
      Default_Handler,               /*  224,  208  Reserved                                                                         */
      Default_Handler,               /*  225,  209  Reserved                                                                         */
      Default_Handler,               /*  226,  210  Reserved                                                                         */
      Default_Handler,               /*  227,  211  Reserved                                                                         */
      Default_Handler,               /*  228,  212  Reserved                                                                         */
      Default_Handler,               /*  229,  213  Reserved                                                                         */
      Default_Handler,               /*  230,  214  Reserved                                                                         */
      Default_Handler,               /*  231,  215  Reserved                                                                         */
      Default_Handler,               /*  232,  216  Reserved                                                                         */
      Default_Handler,               /*  233,  217  Reserved                                                                         */
      Default_Handler,               /*  234,  218  Reserved                                                                         */
      Default_Handler,               /*  235,  219  Reserved                                                                         */
      Default_Handler,               /*  236,  220  Reserved                                                                         */
      Default_Handler,               /*  237,  221  Reserved                                                                         */
      Default_Handler,               /*  238,  222  Reserved                                                                         */
      Default_Handler,               /*  239,  223  Reserved                                                                         */
      Default_Handler,               /*  240,  224  Reserved                                                                         */
      Default_Handler,               /*  241,  225  Reserved                                                                         */
      Default_Handler,               /*  242,  226  Reserved                                                                         */
      Default_Handler,               /*  243,  227  Reserved                                                                         */
      Default_Handler,               /*  244,  228  Reserved                                                                         */
      Default_Handler,               /*  245,  229  Reserved                                                                         */
      Default_Handler,               /*  246,  230  Reserved                                                                         */
      Default_Handler,               /*  247,  231  Reserved                                                                         */
      Default_Handler,               /*  248,  232  Reserved                                                                         */
      Default_Handler,               /*  249,  233  Reserved                                                                         */
      Default_Handler,               /*  250,  234  Reserved                                                                         */
      Default_Handler,               /*  251,  235  Reserved                                                                         */
      Default_Handler,               /*  252,  236  Reserved                                                                         */
      Default_Handler,               /*  253,  237  Reserved                                                                         */
      Default_Handler,               /*  254,  238  Reserved                                                                         */
      Default_Handler,               /*  255,  239  Reserved                                                                         */
   }
};



