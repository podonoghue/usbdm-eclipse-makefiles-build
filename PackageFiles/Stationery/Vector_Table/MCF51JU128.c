/*
 *  Vectors.c
 *
 *  Generic vectors and security for Coldfire V1
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */
#include <stdint.h>

#define DEVICE_SUBFAMILY_CFV1Plus

/*
 * Security information
 */
#if defined(DEVICE_SUBFAMILY_CFV1Plus)
typedef struct {
    uint8_t   backdoorKey[8];
    uint8_t   fprot[4];
    uint8_t   fdprot;
    uint8_t   feprot;
    uint8_t   fopt;
    uint8_t   fsec;
} SecurityInfo;

__attribute__ ((section(".cs3.security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    /* fprot    */ {0xFF,0xFF,0xFF,0xFF,},
    /* fdprot   */ 0xFF,
    /* feprot   */ 0xFF,
    /* fopt     */ 0xFF,
    /* fsec     */ 0xFE,  /* KEYEN=3,MEEN=3,FSLACC=3,SEC=2 */
};
#elif defined(DEVICE_SUBFAMILY_CFV1)
typedef struct {
    uint8_t  backdoorKey[8];
    uint8_t  res1[5];
    uint8_t  nvprot;
    uint8_t  res2;
    uint8_t  nvopt;
} SecurityInfo;

__attribute__ ((section(".cs3.security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    /* res1     */ {0xFF,0xFF,0xFF,0xFF,0xFF,},
    /* nvprot   */ 0xFF,
    /* res2     */ 0xFF,
    /* nvopt    */ 0xFF,
};
#else
#error "Device family not set"
#endif

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((weak, alias("Default_Handler")))

 __attribute__((__interrupt__))
void Default_Handler(void) {
   while (1) {
      asm("halt");
   }
}

void __cs3_reset(void) __attribute__((__interrupt__));
extern uint32_t __cs3_stack;

void AccessError_Handler(void)            WEAK_DEFAULT_HANDLER;
void AddressError_Handler(void)      	  WEAK_DEFAULT_HANDLER;
void IllegalInstruction_Handler(void)     WEAK_DEFAULT_HANDLER;
void DivideBy0_Handler(void)       		  WEAK_DEFAULT_HANDLER;
void PrivilegeViolation_Handler(void)     WEAK_DEFAULT_HANDLER;
void Trace_Handler(void)       			  WEAK_DEFAULT_HANDLER;
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

void Int_UnsuppportedInstr_Handler(void)  WEAK_DEFAULT_HANDLER;
void Int_Irq_Handler(void)                WEAK_DEFAULT_HANDLER;
void Int_LVD_Handler(void)                WEAK_DEFAULT_HANDLER;
void Int_LLWU_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_LOL_Handler(void)                WEAK_DEFAULT_HANDLER;
void Int_Flash_Handler(void)              WEAK_DEFAULT_HANDLER;
void Int_DMA_Channel0_Handler(void)       WEAK_DEFAULT_HANDLER;
void Int_DMA_Channel1_Handler(void)       WEAK_DEFAULT_HANDLER;
void Int_DMA_Channel2_Handler(void)       WEAK_DEFAULT_HANDLER;
void Int_DMA_Channel3_Handler(void)       WEAK_DEFAULT_HANDLER;
void Int_USB0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_FTM1_Fault_Handler(void)         WEAK_DEFAULT_HANDLER;
void Int_FTM1_Ch0_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int_FTM1_Ch1_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int_FTM1_Ch2_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int_FTM1_Ch3_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int_FTM1_Ch4_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int_FTM1_Ch5_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int_CMP0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_FTM0_Fault_Handler(void)         WEAK_DEFAULT_HANDLER;
void Int_FTM0_Ch0_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int_FTM0_Ch1_Handler(void)           WEAK_DEFAULT_HANDLER;
void Int_SPI0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_SCI0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_SAI_Rx_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_SAI_Tx_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_I2C0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_I2C2_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_SPI1_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_SCI1_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_I2C1_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_I2C3_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_ADC0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_TSI0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_DAC0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_CMT_Handler(void)                WEAK_DEFAULT_HANDLER;
void Int_PDB0_Handler(void)               WEAK_DEFAULT_HANDLER;
void Int_LPTMR0_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_LPTMR1_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_L7_SWI_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_L6_SWI_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_L5_SWI_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_L4_SWI_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_L3_SWI_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_L2_SWI_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_L1_SWI_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_MTIM0_Handler(void)              WEAK_DEFAULT_HANDLER;
void Int_USBDCD_Handler(void)             WEAK_DEFAULT_HANDLER;
void Int_PORTA_B_Handler(void)            WEAK_DEFAULT_HANDLER;
void Int_PORTD_C_Handler(void)            WEAK_DEFAULT_HANDLER;
void Int_PORTF_E_Handler(void)            WEAK_DEFAULT_HANDLER;

__attribute__ ((section(".cs3.interrupt_vector")))
intfunc const __cs3_interrupt_vector_coldfire[] = {
    (intfunc)(&__cs3_stack),        /*   0 The stack pointer after relocation           */
    __cs3_reset,                    /*   1 Reset                                        */
    AccessError_Handler,            /*   2 Access Error                                 */
    AddressError_Handler,           /*   3 Address Error                                */
    IllegalInstruction_Handler,     /*   4 Illegal Instruction                          */
    DivideBy0_Handler,              /*   5 Divide by Zero                               */
    Default_Handler,                /*   6 Reserved                                     */
    Default_Handler,                /*   7 Reserved                                     */
    PrivilegeViolation_Handler,     /*   8 Privilege Violation                          */
    Trace_Handler,                  /*   9 Trace                                        */
    UnimplementedLineA_Handler,     /*  10 Unimplemented Line A                         */
    UnimplementedLineF_Handler,     /*  11 Unimplemented Line F                         */
    NonPCBreakpoint_Handler,        /*  12 Non-PC Breakpoint                            */
    PCBreakpoint_Handler,           /*  13 PC Breakpoint                                */
    FormatError_Handler,            /*  14 Format Error                                 */
    UninitializedInterrupt_Handler, /*  15 Uninitialized Interrupt                      */
    Default_Handler,                /*  16 Reserved                                     */
    Default_Handler,                /*  17 Reserved                                     */
    Default_Handler,                /*  18 Reserved                                     */
    Default_Handler,                /*  19 Reserved                                     */
    Default_Handler,                /*  20 Reserved                                     */
    Default_Handler,                /*  21 Reserved                                     */
    Default_Handler,                /*  22 Reserved                                     */
    Default_Handler,                /*  23 Reserved                                     */
    SpuriousInt_Handler,            /*  24 Spurious Interrupt                           */
    AutoVector1_Handler,            /*  25 AutoVector 1                                 */
    AutoVector2_Handler,            /*  26 AutoVector 2                                 */
    AutoVector3_Handler,            /*  27 AutoVector 3                                 */
    AutoVector4_Handler,            /*  28 AutoVector 4                                 */
    AutoVector5_Handler,            /*  29 AutoVector 5                                 */
    AutoVector6_Handler,            /*  30 AutoVector 6                                 */
    AutoVector7_Handler,            /*  31 AutoVector 7                                 */
    Trap0_Handler,                  /*  32 Trap 0                                       */
    Trap1_Handler,                  /*  33 Trap 1                                       */
    Trap2_Handler,                  /*  34 Trap 2                                       */
    Trap3_Handler,                  /*  35 Trap 3                                       */
    Trap4_Handler,                  /*  36 Trap 4                                       */
    Trap5_Handler,                  /*  37 Trap 5                                       */
    Trap6_Handler,                  /*  38 Trap 6                                       */
    Trap7_Handler,                  /*  39 Trap 7                                       */
    Trap8_Handler,                  /*  30 Trap 8                                       */
    Trap9_Handler,                  /*  41 Trap 9                                       */
    Trap10_Handler,                 /*  42 Trap 10                                      */
    Trap11_Handler,                 /*  43 Trap 11                                      */
    Trap12_Handler,                 /*  44 Trap 12                                      */
    Trap13_Handler,                 /*  45 Trap 13                                      */
    Trap14_Handler,                 /*  46 Trap 14                                      */
    Trap15_Handler,                 /*  47 Trap 15                                      */
    Default_Handler,                /*  48 Reserved                                     */
    Default_Handler,                /*  49 Reserved                                     */
    Default_Handler,                /*  50 Reserved                                     */
    Default_Handler,                /*  51 Reserved                                     */
    Default_Handler,                /*  52 Reserved                                     */
    Default_Handler,                /*  53 Reserved                                     */
    Default_Handler,                /*  54 Reserved                                     */
    Default_Handler,                /*  55 Reserved                                     */
    Default_Handler,                /*  56 Reserved                                     */
    Default_Handler,                /*  57 Reserved                                     */
    Default_Handler,                /*  58 Reserved                                     */
    Default_Handler,                /*  59 Reserved                                     */
    Default_Handler,                /*  60 Reserved                                     */
    Int_UnsuppportedInstr_Handler,  /*  61                                              */
    Default_Handler,                /*  62 Reserved                                     */
    Default_Handler,                /*  63 Reserved                                     */
    Int_Irq_Handler,                /*  64                                              */
    Int_LVD_Handler,                /*  65                                              */
    Int_LLWU_Handler,               /*  66                                              */
    Int_LOL_Handler,                /*  67                                              */
    Int_Flash_Handler,              /*  68                                              */
    Int_DMA_Channel0_Handler,       /*  69                                              */
    Int_DMA_Channel1_Handler,       /*  70                                              */
    Int_DMA_Channel2_Handler,       /*  71                                              */
    Int_DMA_Channel3_Handler,       /*  72                                              */
    Int_USB0_Handler,               /*  73                                              */
    Default_Handler,                /*  74 Reserved                                     */
    Int_FTM1_Fault_Handler,         /*  75                                              */
    Int_FTM1_Ch0_Handler,           /*  76                                              */
    Int_FTM1_Ch1_Handler,           /*  77                                              */
    Int_FTM1_Ch2_Handler,           /*  78                                              */
    Int_FTM1_Ch3_Handler,           /*  79                                              */
    Int_FTM1_Ch4_Handler,           /*  80                                              */
    Int_FTM1_Ch5_Handler,           /*  81                                              */
    Int_CMP0_Handler,               /*  82                                              */
    Int_FTM0_Fault_Handler,         /*  83                                              */
    Int_FTM0_Ch0_Handler,           /*  84                                              */
    Int_FTM0_Ch1_Handler,           /*  85                                              */
    Int_SPI0_Handler,               /*  86                                              */
    Int_SCI0_Handler,               /*  87                                              */
    Int_SAI_Rx_Handler,             /*  88                                              */
    Int_SAI_Tx_Handler,             /*  89                                              */
    Int_I2C0_Handler,               /*  90                                              */
    Int_I2C2_Handler,               /*  91                                              */
    Int_SPI1_Handler,               /*  92                                              */
    Int_SCI1_Handler,               /*  93                                              */
    Int_I2C1_Handler,               /*  94                                              */
    Int_I2C3_Handler,               /*  95                                              */
    Int_ADC0_Handler,               /*  96                                              */
    Int_TSI0_Handler,               /*  97                                              */
    Int_DAC0_Handler,               /*  98                                              */
    Int_CMT_Handler,                /*  99                                              */
    Int_PDB0_Handler,               /* 100                                              */
    Int_LPTMR0_Handler,             /* 101                                              */
    Int_LPTMR1_Handler,             /* 102                                              */
    Int_L7_SWI_Handler,             /* 103                                              */
    Int_L6_SWI_Handler,             /* 104                                              */
    Int_L5_SWI_Handler,             /* 105                                              */
    Int_L4_SWI_Handler,             /* 106                                              */
    Int_L3_SWI_Handler,             /* 107                                              */
    Int_L2_SWI_Handler,             /* 108                                              */
    Int_L1_SWI_Handler,             /* 109                                              */
    Int_MTIM0_Handler,              /* 110                                              */
    Int_USBDCD_Handler,             /* 111                                              */
    Int_PORTA_B_Handler,            /* 112                                              */
    Int_PORTD_C_Handler,            /* 113                                              */
    Int_PORTF_E_Handler,            /* 114                                              */
   };
