/*
 *  Vectors.c
 *
 *  Generic vectors and security for Coldfire Vx
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */
#include <stdint.h>

/*
 * Security information
 */
typedef struct {
    uint8_t   backdoorKey[8];
    uint32_t  cfmprot;
    uint32_t  cfmsacc;
    uint32_t  cfmdacc;
    uint32_t  cfmsec;
} SecurityInfo;

__attribute__ ((section(".security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    /* cfmprot  */ 0x00000000,
    /* cfmsacc  */ 0x00000000,
    /* cfmdacc  */ 0x00000000,
    /* cfmsec   */ 0x00000000,  /* KEYEN=0,SEC=0x0000 (SEC=0x4AC8 protects device) */
};

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((weak, alias("Default_Handler")))

 __attribute__((__interrupt__))
void Default_Handler(void) {
   while (1) {
      __asm__("halt");
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
void AccessError_Handler(void)            WEAK_DEFAULT_HANDLER;
void AddressError_Handler(void)           WEAK_DEFAULT_HANDLER;
void IllegalInstruction_Handler(void)     WEAK_DEFAULT_HANDLER;
void DivideBy0_Handler(void)              WEAK_DEFAULT_HANDLER;
void PrivilegeViolation_Handler(void)     WEAK_DEFAULT_HANDLER;
void Trace_Handler(void)                  WEAK_DEFAULT_HANDLER;
void UnimplementedLineA_Handler(void)     WEAK_DEFAULT_HANDLER;
void UnimplementedLineF_Handler(void)     WEAK_DEFAULT_HANDLER;
void NonPCBreakpoint_Handler(void)        WEAK_DEFAULT_HANDLER;
void PCBreakpoint_Handler(void)           WEAK_DEFAULT_HANDLER;
void FormatError_Handler(void)            WEAK_DEFAULT_HANDLER;
void UninitializedInterrupt_Handler(void) WEAK_DEFAULT_HANDLER;
void SpuriousInt_Handler(void)            WEAK_DEFAULT_HANDLER;
void AutoVector1_Handler(void)            WEAK_DEFAULT_HANDLER;
void AutoVector2_Handler(void)            WEAK_DEFAULT_HANDLER;
void AutoVector3_Handler(void)            WEAK_DEFAULT_HANDLER;
void AutoVector4_Handler(void)            WEAK_DEFAULT_HANDLER;
void AutoVector5_Handler(void)            WEAK_DEFAULT_HANDLER;
void AutoVector6_Handler(void)            WEAK_DEFAULT_HANDLER;
void AutoVector7_Handler(void)            WEAK_DEFAULT_HANDLER;
void Trap0_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap1_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap2_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap3_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap4_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap5_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap6_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap7_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap8_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap9_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Trap10_Handler(void)                 WEAK_DEFAULT_HANDLER;
void Trap11_Handler(void)                 WEAK_DEFAULT_HANDLER;
void Trap12_Handler(void)                 WEAK_DEFAULT_HANDLER;
void Trap13_Handler(void)                 WEAK_DEFAULT_HANDLER;
void Trap14_Handler(void)                 WEAK_DEFAULT_HANDLER;
void Trap15_Handler(void)                 WEAK_DEFAULT_HANDLER;

void Int48_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int49_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int50_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int51_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int52_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int53_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int54_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int55_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int56_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int57_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int58_Handler(void)                  WEAK_DEFAULT_HANDLER;
void Int59_Handler(void)                  WEAK_DEFAULT_HANDLER;

__attribute__ ((section(".interrupt_vectors")))
intfunc const vectors[256] = {
    (intfunc)(&__StackTop),            /*  0 The stack pointer       */
    __HardReset,                    /*  1 Reset                   */
    AccessError_Handler,            /*  2 Access Error            */
    AddressError_Handler,           /*  3 Address Error           */
    IllegalInstruction_Handler,     /*  4 Illegal Instruction     */
    DivideBy0_Handler,              /*  5 Divide by Zero          */
    Default_Handler,                /*  6 Reserved                */
    Default_Handler,                /*  7 Reserved                */
    PrivilegeViolation_Handler,     /*  8 Privilege Violation     */
    Trace_Handler,                  /*  9 Trace                   */
    UnimplementedLineA_Handler,     /* 10 Unimplemented Line A    */
    UnimplementedLineF_Handler,     /* 11 Unimplemented Line F    */
    NonPCBreakpoint_Handler,        /* 12 Non-PC Breakpoint       */
    PCBreakpoint_Handler,           /* 13 PC Breakpoint           */
    FormatError_Handler,            /* 14 Format Error            */
    UninitializedInterrupt_Handler, /* 15 Uninitialized Interrupt */
    Default_Handler,                /* 16 Reserved                */
    Default_Handler,                /* 17 Reserved                */
    Default_Handler,                /* 18 Reserved                */
    Default_Handler,                /* 19 Reserved                */
    Default_Handler,                /* 20 Reserved                */
    Default_Handler,                /* 21 Reserved                */
    Default_Handler,                /* 22 Reserved                */
    Default_Handler,                /* 23 Reserved                */
    SpuriousInt_Handler,            /* 24 Spurious Interrupt      */
    AutoVector1_Handler,            /* 25 AutoVector 1            */
    AutoVector2_Handler,            /* 26 AutoVector 2            */
    AutoVector3_Handler,            /* 27 AutoVector 3            */
    AutoVector4_Handler,            /* 28 AutoVector 4            */
    AutoVector5_Handler,            /* 29 AutoVector 5            */
    AutoVector6_Handler,            /* 30 AutoVector 6            */
    AutoVector7_Handler,            /* 31 AutoVector 7            */
    Trap0_Handler,                  /* 32 Trap 0                  */
    Trap1_Handler,                  /* 33 Trap 1                  */
    Trap2_Handler,                  /* 34 Trap 2                  */
    Trap3_Handler,                  /* 35 Trap 3                  */
    Trap4_Handler,                  /* 36 Trap 4                  */
    Trap5_Handler,                  /* 37 Trap 5                  */
    Trap6_Handler,                  /* 38 Trap 6                  */
    Trap7_Handler,                  /* 39 Trap 7                  */
    Trap8_Handler,                  /* 40 Trap 8                  */
    Trap9_Handler,                  /* 41 Trap 9                  */
    Trap10_Handler,                 /* 42 Trap 10                 */
    Trap11_Handler,                 /* 43 Trap 11                 */
    Trap12_Handler,                 /* 44 Trap 12                 */
    Trap13_Handler,                 /* 45 Trap 13                 */
    Trap14_Handler,                 /* 46 Trap 14                 */
    Trap15_Handler,                 /* 47 Trap 15                 */
    Int48_Handler,
    Int49_Handler,
    Int50_Handler,
    Int51_Handler,
    Int52_Handler,
    Int53_Handler,
    Int54_Handler,
    Int55_Handler,
    Int56_Handler,
    Int57_Handler,
    Int58_Handler,
    Int59_Handler,
};
