/****************************************************************************************************//**
 * @file     MCF5223x.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MCF5223x.
 *           Equivalent: MCF52231, MCF52230, MCF52233, MCF52232, MCF52235, MCF52234, MCF52236
 *
 * @version  V0.0
 * @date     2015/04
 *
 *******************************************************************************************************/

#ifndef MCU_MCF5223X
#define MCU_MCF5223X

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* ------------------------  Processor Exceptions Numbers  ------------------------- */
  Reset_IRQn                    =   1,   /*!<   1 Initial PC                                                                       */
  AccessError_IRQn              =   2,   /*!<   2 Access Error                                                                     */
  AddressError_IRQn             =   3,   /*!<   3 Address Error                                                                    */
  IllegalInstruction_IRQn       =   4,   /*!<   4 Illegal Instruction                                                              */
  DivideBy0_IRQn                =   5,   /*!<   5 Divide by Zero                                                                   */
  PrivilegeViolation_IRQn       =   8,   /*!<   8 Privilege Violation                                                              */
  Trace_IRQn                    =   9,   /*!<   9 Trace                                                                            */
  UnimplementedLineA_IRQn       =  10,   /*!<  10 Unimplemented Line A                                                             */
  UnimplementedLineF_IRQn       =  11,   /*!<  11 Unimplemented Line F                                                             */
  Debug_IRQn                    =  12,   /*!<  12 Debug                                                                            */
  FormatError_IRQn              =  14,   /*!<  14 Format Error                                                                     */
  SpuriousInt_IRQn              =  24,   /*!<  24 Spurious Interrupt                                                               */
  Trap0_IRQn                    =  32,   /*!<  32 Trap # 0                                                                         */
  Trap1_IRQn                    =  33,   /*!<  33 Trap # 1                                                                         */
  Trap2_IRQn                    =  34,   /*!<  34 Trap # 2                                                                         */
  Trap3_IRQn                    =  35,   /*!<  35 Trap # 3                                                                         */
  Trap4_IRQn                    =  36,   /*!<  36 Trap # 4                                                                         */
  Trap5_IRQn                    =  37,   /*!<  37 Trap # 5                                                                         */
  Trap6_IRQn                    =  38,   /*!<  38 Trap # 6                                                                         */
  Trap7_IRQn                    =  39,   /*!<  39 Trap # 7                                                                         */
  Trap8_IRQn                    =  40,   /*!<  40 Trap # 8                                                                         */
  Trap9_IRQn                    =  41,   /*!<  41 Trap # 9                                                                         */
  Trap10_IRQn                   =  42,   /*!<  42 Trap # 10                                                                        */
  Trap11_IRQn                   =  43,   /*!<  43 Trap # 11                                                                        */
  Trap12_IRQn                   =  44,   /*!<  44 Trap # 12                                                                        */
  Trap13_IRQn                   =  45,   /*!<  45 Trap # 13                                                                        */
  Trap14_IRQn                   =  46,   /*!<  46 Trap # 14                                                                        */
  Trap15_IRQn                   =  47,   /*!<  47 Trap # 15                                                                        */
/* ----------------------   MCF5223x VectorTable                     ---------------------- */
  EPORT1_IRQn                   =  65,   /*!<  65 Edge port flag 1                                                                 */
  EPORT2_IRQn                   =  66,   /*!<  66 Edge port flag 2                                                                 */
  EPORT3_IRQn                   =  67,   /*!<  67 Edge port flag 3                                                                 */
  EPORT4_IRQn                   =  68,   /*!<  68 Edge port flag 4                                                                 */
  EPORT5_IRQn                   =  69,   /*!<  69 Edge port flag 5                                                                 */
  EPORT6_IRQn                   =  70,   /*!<  70 Edge port flag 6                                                                 */
  EPORT7_IRQn                   =  71,   /*!<  71 Edge port flag 7                                                                 */
  SCM_IRQn                      =  72,   /*!<  72 Software watchdog timeout                                                        */
  DMA_CH0_IRQn                  =  73,   /*!<  73 DMA Channel 0 transfer complete                                                  */
  DMA_CH1_IRQn                  =  74,   /*!<  74 DMA Channel 1 transfer complete                                                  */
  DMA_CH2_IRQn                  =  75,   /*!<  75 DMA Channel 2 transfer complete                                                  */
  DMA_CH3_IRQn                  =  76,   /*!<  76 DMA Channel 3 transfer complete                                                  */
  UART0_IRQn                    =  77,   /*!<  77 UART 0 interrupt                                                                 */
  UART1_IRQn                    =  78,   /*!<  78 UART 1 interrupt                                                                 */
  UART2_IRQn                    =  79,   /*!<  79 UART 2 interrupt                                                                 */
  I2C_IRQn                      =  81,   /*!<  81 I2C interrupt                                                                    */
  QSPI_IRQn                     =  82,   /*!<  82 QSPI interrupt                                                                   */
  DTIM0_IRQn                    =  83,   /*!<  83 DMA Timer 0 interrupt                                                            */
  DTIM1_IRQn                    =  84,   /*!<  84 DMA Timer 1 interrupt                                                            */
  DTIM2_IRQn                    =  85,   /*!<  85 DMA Timer 2 interrupt                                                            */
  DTIM3_IRQn                    =  86,   /*!<  86 DMA Timer 3 interrupt                                                            */
  FEC_TF_IRQn                   =  87,   /*!<  87 Transmit frame interrupt                                                         */
  FEC_TB_IRQn                   =  88,   /*!<  88 Transmit buffer interrupt                                                        */
  FEC_UN_IRQn                   =  89,   /*!<  89 Transmit FIFO underrun                                                           */
  FEC_RL_IRQn                   =  90,   /*!<  90 Collision retry limit                                                            */
  FEC_RF_IRQn                   =  91,   /*!<  91 Receive frame interrupt                                                          */
  FEC_RB_IRQn                   =  92,   /*!<  92 Receive buffer interrupt                                                         */
  FEC_MII_IRQn                  =  93,   /*!<  93 MII interrupt                                                                    */
  FEC_LC_IRQn                   =  94,   /*!<  94 Late Collision                                                                   */
  FEC_HBERR_IRQn                =  95,   /*!<  95 Heart-beat error                                                                 */
  FEC_GRA_IRQn                  =  96,   /*!<  96 Graceful stop complete                                                           */
  FEC_EBERR_IRQn                =  97,   /*!<  97 Ethernet bus error                                                               */
  FEC_BABT_IRQn                 =  98,   /*!<  98 Babbling transmit error                                                          */
  FEC_BABR_IRQn                 =  99,   /*!<  99 Babbling receive error                                                           */
  EPHY_IRQn                     = 100,   /*!< 100 EPHY interrupt                                                                   */
  GPT_TOF_IRQn                  = 105,   /*!< 105 GPT Timer overflow                                                               */
  GPT_PAIF_IRQn                 = 106,   /*!< 106 GPT Pulse accumulator input                                                      */
  GPT_PAOVF_IRQn                = 107,   /*!< 107 GPT Pulse accumulator overflow                                                   */
  GPT_C0F_IRQn                  = 108,   /*!< 108 GPT Timer channel 0                                                              */
  GPT_C1F_IRQn                  = 109,   /*!< 109 GPT Timer channel 1                                                              */
  GPT_C2F_IRQn                  = 110,   /*!< 110 GPT Timer channel 2                                                              */
  GPT_C3F_IRQn                  = 111,   /*!< 111 GPT Timer channel 3                                                              */
  PMM_IRQn                      = 112,   /*!< 112 LVD                                                                              */
  ADC_ADCA_IRQn                 = 113,   /*!< 113 ADCA conversion complete                                                         */
  ADC_ADCB_IRQn                 = 114,   /*!< 114 ADCB conversion complete                                                         */
  ADC_ADCINT_IRQn               = 115,   /*!< 115 ADC Interrupt                                                                    */
  PWM_IRQn                      = 116,   /*!< 116 PWM interrupt                                                                    */
  RNGA_IRQn                     = 117,   /*!< 117 RNGA interrupt                                                                   */
  PIT0_IRQn                     = 119,   /*!< 119 PIT 0 interrupt                                                                  */
  PIT1_IRQn                     = 120,   /*!< 120 PIT 1 interrupt                                                                  */
  CFM_CBEIF_IRQn                = 122,   /*!< 122 CFM SGFM buffer empty                                                            */
  CFM_CCIF_IRQn                 = 123,   /*!< 123 CFM SGFM command complete                                                        */
  CFM_PVIF_IRQn                 = 124,   /*!< 124 CFM Protection violation                                                         */
  RTC_IRQn                      = 127,   /*!< 127 RTC interrupt                                                                    */
} IRQn_Type;

/* -------------------------  Exception Handlers  ------------------------ */
extern void AccessError_Handler(void);
extern void AddressError_Handler(void);
extern void IllegalInstruction_Handler(void);
extern void DivideBy0_Handler(void);
extern void PrivilegeViolation_Handler(void);
extern void Trace_Handler(void);
extern void UnimplementedLineA_Handler(void);
extern void UnimplementedLineF_Handler(void);
extern void Debug_Handler(void);
extern void FormatError_Handler(void);
extern void SpuriousInt_Handler(void);
extern void Trap0_Handler(void);
extern void Trap1_Handler(void);
extern void Trap2_Handler(void);
extern void Trap3_Handler(void);
extern void Trap4_Handler(void);
extern void Trap5_Handler(void);
extern void Trap6_Handler(void);
extern void Trap7_Handler(void);
extern void Trap8_Handler(void);
extern void Trap9_Handler(void);
extern void Trap10_Handler(void);
extern void Trap11_Handler(void);
extern void Trap12_Handler(void);
extern void Trap13_Handler(void);
extern void Trap14_Handler(void);
extern void Trap15_Handler(void);
extern void EPORT1_IRQHandler(void);
extern void EPORT2_IRQHandler(void);
extern void EPORT3_IRQHandler(void);
extern void EPORT4_IRQHandler(void);
extern void EPORT5_IRQHandler(void);
extern void EPORT6_IRQHandler(void);
extern void EPORT7_IRQHandler(void);
extern void SCM_IRQHandler(void);
extern void DMA_CH0_IRQHandler(void);
extern void DMA_CH1_IRQHandler(void);
extern void DMA_CH2_IRQHandler(void);
extern void DMA_CH3_IRQHandler(void);
extern void UART0_IRQHandler(void);
extern void UART1_IRQHandler(void);
extern void UART2_IRQHandler(void);
extern void I2C_IRQHandler(void);
extern void QSPI_IRQHandler(void);
extern void DTIM0_IRQHandler(void);
extern void DTIM1_IRQHandler(void);
extern void DTIM2_IRQHandler(void);
extern void DTIM3_IRQHandler(void);
extern void FEC_TF_IRQHandler(void);
extern void FEC_TB_IRQHandler(void);
extern void FEC_UN_IRQHandler(void);
extern void FEC_RL_IRQHandler(void);
extern void FEC_RF_IRQHandler(void);
extern void FEC_RB_IRQHandler(void);
extern void FEC_MII_IRQHandler(void);
extern void FEC_LC_IRQHandler(void);
extern void FEC_HBERR_IRQHandler(void);
extern void FEC_GRA_IRQHandler(void);
extern void FEC_EBERR_IRQHandler(void);
extern void FEC_BABT_IRQHandler(void);
extern void FEC_BABR_IRQHandler(void);
extern void EPHY_IRQHandler(void);
extern void GPT_TOF_IRQHandler(void);
extern void GPT_PAIF_IRQHandler(void);
extern void GPT_PAOVF_IRQHandler(void);
extern void GPT_C0F_IRQHandler(void);
extern void GPT_C1F_IRQHandler(void);
extern void GPT_C2F_IRQHandler(void);
extern void GPT_C3F_IRQHandler(void);
extern void PMM_IRQHandler(void);
extern void ADC_ADCA_IRQHandler(void);
extern void ADC_ADCB_IRQHandler(void);
extern void ADC_ADCINT_IRQHandler(void);
extern void PWM_IRQHandler(void);
extern void RNGA_IRQHandler(void);
extern void PIT0_IRQHandler(void);
extern void PIT1_IRQHandler(void);
extern void CFM_CBEIF_IRQHandler(void);
extern void CFM_CCIF_IRQHandler(void);
extern void CFM_PVIF_IRQHandler(void);
extern void RTC_IRQHandler(void);

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the cm4 Processor and Core Peripherals---------------- */
#define __CM3_REV                0x0100
#define __MPU_PRESENT            0
#define __NVIC_PRIO_BITS         0
#define __Vendor_SysTickConfig   0
#define __FPU_PRESENT            0

#include "core_cfv2.h"          /*!< Processor and core peripherals */
#include "system.h"             /*!< Device specific configuration file */

#ifndef __IO
#define __IO volatile 
#endif

#ifndef __I
#define __I volatile const
#endif

#ifndef __O
#define __O volatile
#endif


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */



/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================           ADC (file:MCF522xx_ADC)              ================ */
/* ================================================================================ */

/**
 * @brief Analogue-to-Digital Converter
The analog-to-digital converter (ADC) consists of two separate and complete ADCs, each with their own
sample and hold circuits. The converters share a common voltage reference and common digital control
module
 */
typedef struct {                                /*!<       ADC Structure                                                */
   __IO uint16_t  CTRL1;                        /*!< 0000: Control Register 1                                           */
   __IO uint16_t  CTRL2;                        /*!< 0002: Control Register 2                                           */
   __IO uint16_t  ADZCC;                        /*!< 0004: Zero Crossing Control Register                               */
   __IO uint16_t  ADLST1;                       /*!< 0006: Channel List Register 1                                      */
   __IO uint16_t  ADLST2;                       /*!< 0008: Channel List Register 2                                      */
   __IO uint16_t  ADSDIS;                       /*!< 000A: Sample Disable Register                                      */
   __IO uint16_t  ADSTAT;                       /*!< 000C: Status Register                                              */
   __IO uint16_t  ADLSTAT;                      /*!< 000E: Limit Status Register                                        */
   __IO uint16_t  ADZCSTAT;                     /*!< 0010: Zero Crossing Status Register                                */
   __IO uint16_t  ADRSLT[8];                    /*!< 0012: Result Registers                                             */
   __IO uint16_t  ADLLMT[8];                    /*!< 0022: Low Limit Register                                           */
   __IO uint16_t  ADHLMT[8];                    /*!< 0032: High Limit Register                                          */
   __IO uint16_t  ADOFS[8];                     /*!< 0042: Offset Register                                              */
   __IO uint16_t  POWER;                        /*!< 0052: Power Control Register                                       */
   __IO uint16_t  CAL;                          /*!< 0054: Voltage Reference Register                                   */
} ADC_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'ADC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- CTRL1 Bit Fields                         ------ */
#define ADC_CTRL1_SMODE_MASK                     (0x07UL << ADC_CTRL1_SMODE_SHIFT)                   /*!< ADC_CTRL1: SMODE Mask                   */
#define ADC_CTRL1_SMODE_SHIFT                    0                                                   /*!< ADC_CTRL1: SMODE Position               */
#define ADC_CTRL1_SMODE(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_SMODE_SHIFT))&ADC_CTRL1_SMODE_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_CHNCFG0_MASK                   (0x01UL << ADC_CTRL1_CHNCFG0_SHIFT)                 /*!< ADC_CTRL1: CHNCFG0 Mask                 */
#define ADC_CTRL1_CHNCFG0_SHIFT                  4                                                   /*!< ADC_CTRL1: CHNCFG0 Position             */
#define ADC_CTRL1_CHNCFG1_MASK                   (0x01UL << ADC_CTRL1_CHNCFG1_SHIFT)                 /*!< ADC_CTRL1: CHNCFG1 Mask                 */
#define ADC_CTRL1_CHNCFG1_SHIFT                  5                                                   /*!< ADC_CTRL1: CHNCFG1 Position             */
#define ADC_CTRL1_CHNCFG2_MASK                   (0x01UL << ADC_CTRL1_CHNCFG2_SHIFT)                 /*!< ADC_CTRL1: CHNCFG2 Mask                 */
#define ADC_CTRL1_CHNCFG2_SHIFT                  6                                                   /*!< ADC_CTRL1: CHNCFG2 Position             */
#define ADC_CTRL1_CHNCFG3_MASK                   (0x01UL << ADC_CTRL1_CHNCFG3_SHIFT)                 /*!< ADC_CTRL1: CHNCFG3 Mask                 */
#define ADC_CTRL1_CHNCFG3_SHIFT                  7                                                   /*!< ADC_CTRL1: CHNCFG3 Position             */
#define ADC_CTRL1_HLMTIE_MASK                    (0x01UL << ADC_CTRL1_HLMTIE_SHIFT)                  /*!< ADC_CTRL1: HLMTIE Mask                  */
#define ADC_CTRL1_HLMTIE_SHIFT                   8                                                   /*!< ADC_CTRL1: HLMTIE Position              */
#define ADC_CTRL1_LLMTIE_MASK                    (0x01UL << ADC_CTRL1_LLMTIE_SHIFT)                  /*!< ADC_CTRL1: LLMTIE Mask                  */
#define ADC_CTRL1_LLMTIE_SHIFT                   9                                                   /*!< ADC_CTRL1: LLMTIE Position              */
#define ADC_CTRL1_ZCIE_MASK                      (0x01UL << ADC_CTRL1_ZCIE_SHIFT)                    /*!< ADC_CTRL1: ZCIE Mask                    */
#define ADC_CTRL1_ZCIE_SHIFT                     10                                                  /*!< ADC_CTRL1: ZCIE Position                */
#define ADC_CTRL1_EOSIE0_MASK                    (0x01UL << ADC_CTRL1_EOSIE0_SHIFT)                  /*!< ADC_CTRL1: EOSIE0 Mask                  */
#define ADC_CTRL1_EOSIE0_SHIFT                   11                                                  /*!< ADC_CTRL1: EOSIE0 Position              */
#define ADC_CTRL1_SYNC0_MASK                     (0x01UL << ADC_CTRL1_SYNC0_SHIFT)                   /*!< ADC_CTRL1: SYNC0 Mask                   */
#define ADC_CTRL1_SYNC0_SHIFT                    12                                                  /*!< ADC_CTRL1: SYNC0 Position               */
#define ADC_CTRL1_START0_MASK                    (0x01UL << ADC_CTRL1_START0_SHIFT)                  /*!< ADC_CTRL1: START0 Mask                  */
#define ADC_CTRL1_START0_SHIFT                   13                                                  /*!< ADC_CTRL1: START0 Position              */
#define ADC_CTRL1_STOP0_MASK                     (0x01UL << ADC_CTRL1_STOP0_SHIFT)                   /*!< ADC_CTRL1: STOP0 Mask                   */
#define ADC_CTRL1_STOP0_SHIFT                    14                                                  /*!< ADC_CTRL1: STOP0 Position               */
/* ------- CTRL2 Bit Fields                         ------ */
#define ADC_CTRL2_DIV_MASK                       (0x1FUL << ADC_CTRL2_DIV_SHIFT)                     /*!< ADC_CTRL2: DIV Mask                     */
#define ADC_CTRL2_DIV_SHIFT                      0                                                   /*!< ADC_CTRL2: DIV Position                 */
#define ADC_CTRL2_DIV(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_DIV_SHIFT))&ADC_CTRL2_DIV_MASK) /*!< ADC_CTRL2                               */
#define ADC_CTRL2_SIMULT_MASK                    (0x01UL << ADC_CTRL2_SIMULT_SHIFT)                  /*!< ADC_CTRL2: SIMULT Mask                  */
#define ADC_CTRL2_SIMULT_SHIFT                   5                                                   /*!< ADC_CTRL2: SIMULT Position              */
#define ADC_CTRL2_EOSIE1_MASK                    (0x01UL << ADC_CTRL2_EOSIE1_SHIFT)                  /*!< ADC_CTRL2: EOSIE1 Mask                  */
#define ADC_CTRL2_EOSIE1_SHIFT                   11                                                  /*!< ADC_CTRL2: EOSIE1 Position              */
#define ADC_CTRL2_SYNC1_MASK                     (0x01UL << ADC_CTRL2_SYNC1_SHIFT)                   /*!< ADC_CTRL2: SYNC1 Mask                   */
#define ADC_CTRL2_SYNC1_SHIFT                    12                                                  /*!< ADC_CTRL2: SYNC1 Position               */
#define ADC_CTRL2_START1_MASK                    (0x01UL << ADC_CTRL2_START1_SHIFT)                  /*!< ADC_CTRL2: START1 Mask                  */
#define ADC_CTRL2_START1_SHIFT                   13                                                  /*!< ADC_CTRL2: START1 Position              */
#define ADC_CTRL2_STOP1_MASK                     (0x01UL << ADC_CTRL2_STOP1_SHIFT)                   /*!< ADC_CTRL2: STOP1 Mask                   */
#define ADC_CTRL2_STOP1_SHIFT                    14                                                  /*!< ADC_CTRL2: STOP1 Position               */
/* ------- ADZCC Bit Fields                         ------ */
#define ADC_ADZCC_ZCE0_MASK                      (0x03UL << ADC_ADZCC_ZCE0_SHIFT)                    /*!< ADC_ADZCC: ZCE0 Mask                    */
#define ADC_ADZCC_ZCE0_SHIFT                     0                                                   /*!< ADC_ADZCC: ZCE0 Position                */
#define ADC_ADZCC_ZCE0(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE0_SHIFT))&ADC_ADZCC_ZCE0_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE1_MASK                      (0x03UL << ADC_ADZCC_ZCE1_SHIFT)                    /*!< ADC_ADZCC: ZCE1 Mask                    */
#define ADC_ADZCC_ZCE1_SHIFT                     2                                                   /*!< ADC_ADZCC: ZCE1 Position                */
#define ADC_ADZCC_ZCE1(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE1_SHIFT))&ADC_ADZCC_ZCE1_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE2_MASK                      (0x03UL << ADC_ADZCC_ZCE2_SHIFT)                    /*!< ADC_ADZCC: ZCE2 Mask                    */
#define ADC_ADZCC_ZCE2_SHIFT                     4                                                   /*!< ADC_ADZCC: ZCE2 Position                */
#define ADC_ADZCC_ZCE2(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE2_SHIFT))&ADC_ADZCC_ZCE2_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE3_MASK                      (0x03UL << ADC_ADZCC_ZCE3_SHIFT)                    /*!< ADC_ADZCC: ZCE3 Mask                    */
#define ADC_ADZCC_ZCE3_SHIFT                     6                                                   /*!< ADC_ADZCC: ZCE3 Position                */
#define ADC_ADZCC_ZCE3(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE3_SHIFT))&ADC_ADZCC_ZCE3_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE4_MASK                      (0x03UL << ADC_ADZCC_ZCE4_SHIFT)                    /*!< ADC_ADZCC: ZCE4 Mask                    */
#define ADC_ADZCC_ZCE4_SHIFT                     8                                                   /*!< ADC_ADZCC: ZCE4 Position                */
#define ADC_ADZCC_ZCE4(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE4_SHIFT))&ADC_ADZCC_ZCE4_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE5_MASK                      (0x03UL << ADC_ADZCC_ZCE5_SHIFT)                    /*!< ADC_ADZCC: ZCE5 Mask                    */
#define ADC_ADZCC_ZCE5_SHIFT                     10                                                  /*!< ADC_ADZCC: ZCE5 Position                */
#define ADC_ADZCC_ZCE5(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE5_SHIFT))&ADC_ADZCC_ZCE5_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE6_MASK                      (0x03UL << ADC_ADZCC_ZCE6_SHIFT)                    /*!< ADC_ADZCC: ZCE6 Mask                    */
#define ADC_ADZCC_ZCE6_SHIFT                     12                                                  /*!< ADC_ADZCC: ZCE6 Position                */
#define ADC_ADZCC_ZCE6(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE6_SHIFT))&ADC_ADZCC_ZCE6_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE7_MASK                      (0x03UL << ADC_ADZCC_ZCE7_SHIFT)                    /*!< ADC_ADZCC: ZCE7 Mask                    */
#define ADC_ADZCC_ZCE7_SHIFT                     14                                                  /*!< ADC_ADZCC: ZCE7 Position                */
#define ADC_ADZCC_ZCE7(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE7_SHIFT))&ADC_ADZCC_ZCE7_MASK) /*!< ADC_ADZCC                               */
/* ------- ADLST1 Bit Fields                        ------ */
#define ADC_ADLST1_SAMPLE0_MASK                  (0x07UL << ADC_ADLST1_SAMPLE0_SHIFT)                /*!< ADC_ADLST1: SAMPLE0 Mask                */
#define ADC_ADLST1_SAMPLE0_SHIFT                 0                                                   /*!< ADC_ADLST1: SAMPLE0 Position            */
#define ADC_ADLST1_SAMPLE0(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST1_SAMPLE0_SHIFT))&ADC_ADLST1_SAMPLE0_MASK) /*!< ADC_ADLST1                              */
#define ADC_ADLST1_SAMPLE1_MASK                  (0x07UL << ADC_ADLST1_SAMPLE1_SHIFT)                /*!< ADC_ADLST1: SAMPLE1 Mask                */
#define ADC_ADLST1_SAMPLE1_SHIFT                 4                                                   /*!< ADC_ADLST1: SAMPLE1 Position            */
#define ADC_ADLST1_SAMPLE1(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST1_SAMPLE1_SHIFT))&ADC_ADLST1_SAMPLE1_MASK) /*!< ADC_ADLST1                              */
#define ADC_ADLST1_SAMPLE2_MASK                  (0x07UL << ADC_ADLST1_SAMPLE2_SHIFT)                /*!< ADC_ADLST1: SAMPLE2 Mask                */
#define ADC_ADLST1_SAMPLE2_SHIFT                 8                                                   /*!< ADC_ADLST1: SAMPLE2 Position            */
#define ADC_ADLST1_SAMPLE2(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST1_SAMPLE2_SHIFT))&ADC_ADLST1_SAMPLE2_MASK) /*!< ADC_ADLST1                              */
#define ADC_ADLST1_SAMPLE3_MASK                  (0x07UL << ADC_ADLST1_SAMPLE3_SHIFT)                /*!< ADC_ADLST1: SAMPLE3 Mask                */
#define ADC_ADLST1_SAMPLE3_SHIFT                 12                                                  /*!< ADC_ADLST1: SAMPLE3 Position            */
#define ADC_ADLST1_SAMPLE3(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST1_SAMPLE3_SHIFT))&ADC_ADLST1_SAMPLE3_MASK) /*!< ADC_ADLST1                              */
/* ------- ADLST2 Bit Fields                        ------ */
#define ADC_ADLST2_SAMPLE4_MASK                  (0x07UL << ADC_ADLST2_SAMPLE4_SHIFT)                /*!< ADC_ADLST2: SAMPLE4 Mask                */
#define ADC_ADLST2_SAMPLE4_SHIFT                 0                                                   /*!< ADC_ADLST2: SAMPLE4 Position            */
#define ADC_ADLST2_SAMPLE4(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST2_SAMPLE4_SHIFT))&ADC_ADLST2_SAMPLE4_MASK) /*!< ADC_ADLST2                              */
#define ADC_ADLST2_SAMPLE5_MASK                  (0x07UL << ADC_ADLST2_SAMPLE5_SHIFT)                /*!< ADC_ADLST2: SAMPLE5 Mask                */
#define ADC_ADLST2_SAMPLE5_SHIFT                 4                                                   /*!< ADC_ADLST2: SAMPLE5 Position            */
#define ADC_ADLST2_SAMPLE5(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST2_SAMPLE5_SHIFT))&ADC_ADLST2_SAMPLE5_MASK) /*!< ADC_ADLST2                              */
#define ADC_ADLST2_SAMPLE6_MASK                  (0x07UL << ADC_ADLST2_SAMPLE6_SHIFT)                /*!< ADC_ADLST2: SAMPLE6 Mask                */
#define ADC_ADLST2_SAMPLE6_SHIFT                 8                                                   /*!< ADC_ADLST2: SAMPLE6 Position            */
#define ADC_ADLST2_SAMPLE6(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST2_SAMPLE6_SHIFT))&ADC_ADLST2_SAMPLE6_MASK) /*!< ADC_ADLST2                              */
#define ADC_ADLST2_SAMPLE7_MASK                  (0x07UL << ADC_ADLST2_SAMPLE7_SHIFT)                /*!< ADC_ADLST2: SAMPLE7 Mask                */
#define ADC_ADLST2_SAMPLE7_SHIFT                 12                                                  /*!< ADC_ADLST2: SAMPLE7 Position            */
#define ADC_ADLST2_SAMPLE7(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST2_SAMPLE7_SHIFT))&ADC_ADLST2_SAMPLE7_MASK) /*!< ADC_ADLST2                              */
/* ------- ADSDIS Bit Fields                        ------ */
#define ADC_ADSDIS_DS0_MASK                      (0x01UL << ADC_ADSDIS_DS0_SHIFT)                    /*!< ADC_ADSDIS: DS0 Mask                    */
#define ADC_ADSDIS_DS0_SHIFT                     0                                                   /*!< ADC_ADSDIS: DS0 Position                */
#define ADC_ADSDIS_DS1_MASK                      (0x01UL << ADC_ADSDIS_DS1_SHIFT)                    /*!< ADC_ADSDIS: DS1 Mask                    */
#define ADC_ADSDIS_DS1_SHIFT                     1                                                   /*!< ADC_ADSDIS: DS1 Position                */
#define ADC_ADSDIS_DS2_MASK                      (0x01UL << ADC_ADSDIS_DS2_SHIFT)                    /*!< ADC_ADSDIS: DS2 Mask                    */
#define ADC_ADSDIS_DS2_SHIFT                     2                                                   /*!< ADC_ADSDIS: DS2 Position                */
#define ADC_ADSDIS_DS3_MASK                      (0x01UL << ADC_ADSDIS_DS3_SHIFT)                    /*!< ADC_ADSDIS: DS3 Mask                    */
#define ADC_ADSDIS_DS3_SHIFT                     3                                                   /*!< ADC_ADSDIS: DS3 Position                */
#define ADC_ADSDIS_DS4_MASK                      (0x01UL << ADC_ADSDIS_DS4_SHIFT)                    /*!< ADC_ADSDIS: DS4 Mask                    */
#define ADC_ADSDIS_DS4_SHIFT                     4                                                   /*!< ADC_ADSDIS: DS4 Position                */
#define ADC_ADSDIS_DS5_MASK                      (0x01UL << ADC_ADSDIS_DS5_SHIFT)                    /*!< ADC_ADSDIS: DS5 Mask                    */
#define ADC_ADSDIS_DS5_SHIFT                     5                                                   /*!< ADC_ADSDIS: DS5 Position                */
#define ADC_ADSDIS_DS6_MASK                      (0x01UL << ADC_ADSDIS_DS6_SHIFT)                    /*!< ADC_ADSDIS: DS6 Mask                    */
#define ADC_ADSDIS_DS6_SHIFT                     6                                                   /*!< ADC_ADSDIS: DS6 Position                */
#define ADC_ADSDIS_DS7_MASK                      (0x01UL << ADC_ADSDIS_DS7_SHIFT)                    /*!< ADC_ADSDIS: DS7 Mask                    */
#define ADC_ADSDIS_DS7_SHIFT                     7                                                   /*!< ADC_ADSDIS: DS7 Position                */
/* ------- ADSTAT Bit Fields                        ------ */
#define ADC_ADSTAT_RDY0_MASK                     (0x01UL << ADC_ADSTAT_RDY0_SHIFT)                   /*!< ADC_ADSTAT: RDY0 Mask                   */
#define ADC_ADSTAT_RDY0_SHIFT                    0                                                   /*!< ADC_ADSTAT: RDY0 Position               */
#define ADC_ADSTAT_RDY1_MASK                     (0x01UL << ADC_ADSTAT_RDY1_SHIFT)                   /*!< ADC_ADSTAT: RDY1 Mask                   */
#define ADC_ADSTAT_RDY1_SHIFT                    1                                                   /*!< ADC_ADSTAT: RDY1 Position               */
#define ADC_ADSTAT_RDY2_MASK                     (0x01UL << ADC_ADSTAT_RDY2_SHIFT)                   /*!< ADC_ADSTAT: RDY2 Mask                   */
#define ADC_ADSTAT_RDY2_SHIFT                    2                                                   /*!< ADC_ADSTAT: RDY2 Position               */
#define ADC_ADSTAT_RDY3_MASK                     (0x01UL << ADC_ADSTAT_RDY3_SHIFT)                   /*!< ADC_ADSTAT: RDY3 Mask                   */
#define ADC_ADSTAT_RDY3_SHIFT                    3                                                   /*!< ADC_ADSTAT: RDY3 Position               */
#define ADC_ADSTAT_RDY4_MASK                     (0x01UL << ADC_ADSTAT_RDY4_SHIFT)                   /*!< ADC_ADSTAT: RDY4 Mask                   */
#define ADC_ADSTAT_RDY4_SHIFT                    4                                                   /*!< ADC_ADSTAT: RDY4 Position               */
#define ADC_ADSTAT_RDY5_MASK                     (0x01UL << ADC_ADSTAT_RDY5_SHIFT)                   /*!< ADC_ADSTAT: RDY5 Mask                   */
#define ADC_ADSTAT_RDY5_SHIFT                    5                                                   /*!< ADC_ADSTAT: RDY5 Position               */
#define ADC_ADSTAT_RDY6_MASK                     (0x01UL << ADC_ADSTAT_RDY6_SHIFT)                   /*!< ADC_ADSTAT: RDY6 Mask                   */
#define ADC_ADSTAT_RDY6_SHIFT                    6                                                   /*!< ADC_ADSTAT: RDY6 Position               */
#define ADC_ADSTAT_RDY7_MASK                     (0x01UL << ADC_ADSTAT_RDY7_SHIFT)                   /*!< ADC_ADSTAT: RDY7 Mask                   */
#define ADC_ADSTAT_RDY7_SHIFT                    7                                                   /*!< ADC_ADSTAT: RDY7 Position               */
#define ADC_ADSTAT_HLMTI_MASK                    (0x01UL << ADC_ADSTAT_HLMTI_SHIFT)                  /*!< ADC_ADSTAT: HLMTI Mask                  */
#define ADC_ADSTAT_HLMTI_SHIFT                   8                                                   /*!< ADC_ADSTAT: HLMTI Position              */
#define ADC_ADSTAT_LLMTI_MASK                    (0x01UL << ADC_ADSTAT_LLMTI_SHIFT)                  /*!< ADC_ADSTAT: LLMTI Mask                  */
#define ADC_ADSTAT_LLMTI_SHIFT                   9                                                   /*!< ADC_ADSTAT: LLMTI Position              */
#define ADC_ADSTAT_ZCI_MASK                      (0x01UL << ADC_ADSTAT_ZCI_SHIFT)                    /*!< ADC_ADSTAT: ZCI Mask                    */
#define ADC_ADSTAT_ZCI_SHIFT                     10                                                  /*!< ADC_ADSTAT: ZCI Position                */
#define ADC_ADSTAT_EOSI0_MASK                    (0x01UL << ADC_ADSTAT_EOSI0_SHIFT)                  /*!< ADC_ADSTAT: EOSI0 Mask                  */
#define ADC_ADSTAT_EOSI0_SHIFT                   11                                                  /*!< ADC_ADSTAT: EOSI0 Position              */
#define ADC_ADSTAT_EOSI1_MASK                    (0x01UL << ADC_ADSTAT_EOSI1_SHIFT)                  /*!< ADC_ADSTAT: EOSI1 Mask                  */
#define ADC_ADSTAT_EOSI1_SHIFT                   12                                                  /*!< ADC_ADSTAT: EOSI1 Position              */
#define ADC_ADSTAT_CIP1_MASK                     (0x01UL << ADC_ADSTAT_CIP1_SHIFT)                   /*!< ADC_ADSTAT: CIP1 Mask                   */
#define ADC_ADSTAT_CIP1_SHIFT                    14                                                  /*!< ADC_ADSTAT: CIP1 Position               */
#define ADC_ADSTAT_CIP0_MASK                     (0x01UL << ADC_ADSTAT_CIP0_SHIFT)                   /*!< ADC_ADSTAT: CIP0 Mask                   */
#define ADC_ADSTAT_CIP0_SHIFT                    15                                                  /*!< ADC_ADSTAT: CIP0 Position               */
/* ------- ADLSTAT Bit Fields                       ------ */
#define ADC_ADLSTAT_LLS0_MASK                    (0x01UL << ADC_ADLSTAT_LLS0_SHIFT)                  /*!< ADC_ADLSTAT: LLS0 Mask                  */
#define ADC_ADLSTAT_LLS0_SHIFT                   0                                                   /*!< ADC_ADLSTAT: LLS0 Position              */
#define ADC_ADLSTAT_LLS1_MASK                    (0x01UL << ADC_ADLSTAT_LLS1_SHIFT)                  /*!< ADC_ADLSTAT: LLS1 Mask                  */
#define ADC_ADLSTAT_LLS1_SHIFT                   1                                                   /*!< ADC_ADLSTAT: LLS1 Position              */
#define ADC_ADLSTAT_LLS2_MASK                    (0x01UL << ADC_ADLSTAT_LLS2_SHIFT)                  /*!< ADC_ADLSTAT: LLS2 Mask                  */
#define ADC_ADLSTAT_LLS2_SHIFT                   2                                                   /*!< ADC_ADLSTAT: LLS2 Position              */
#define ADC_ADLSTAT_LLS3_MASK                    (0x01UL << ADC_ADLSTAT_LLS3_SHIFT)                  /*!< ADC_ADLSTAT: LLS3 Mask                  */
#define ADC_ADLSTAT_LLS3_SHIFT                   3                                                   /*!< ADC_ADLSTAT: LLS3 Position              */
#define ADC_ADLSTAT_LLS4_MASK                    (0x01UL << ADC_ADLSTAT_LLS4_SHIFT)                  /*!< ADC_ADLSTAT: LLS4 Mask                  */
#define ADC_ADLSTAT_LLS4_SHIFT                   4                                                   /*!< ADC_ADLSTAT: LLS4 Position              */
#define ADC_ADLSTAT_LLS5_MASK                    (0x01UL << ADC_ADLSTAT_LLS5_SHIFT)                  /*!< ADC_ADLSTAT: LLS5 Mask                  */
#define ADC_ADLSTAT_LLS5_SHIFT                   5                                                   /*!< ADC_ADLSTAT: LLS5 Position              */
#define ADC_ADLSTAT_LLS6_MASK                    (0x01UL << ADC_ADLSTAT_LLS6_SHIFT)                  /*!< ADC_ADLSTAT: LLS6 Mask                  */
#define ADC_ADLSTAT_LLS6_SHIFT                   6                                                   /*!< ADC_ADLSTAT: LLS6 Position              */
#define ADC_ADLSTAT_LLS7_MASK                    (0x01UL << ADC_ADLSTAT_LLS7_SHIFT)                  /*!< ADC_ADLSTAT: LLS7 Mask                  */
#define ADC_ADLSTAT_LLS7_SHIFT                   7                                                   /*!< ADC_ADLSTAT: LLS7 Position              */
#define ADC_ADLSTAT_HLS0_MASK                    (0x01UL << ADC_ADLSTAT_HLS0_SHIFT)                  /*!< ADC_ADLSTAT: HLS0 Mask                  */
#define ADC_ADLSTAT_HLS0_SHIFT                   8                                                   /*!< ADC_ADLSTAT: HLS0 Position              */
#define ADC_ADLSTAT_HLS1_MASK                    (0x01UL << ADC_ADLSTAT_HLS1_SHIFT)                  /*!< ADC_ADLSTAT: HLS1 Mask                  */
#define ADC_ADLSTAT_HLS1_SHIFT                   9                                                   /*!< ADC_ADLSTAT: HLS1 Position              */
#define ADC_ADLSTAT_HLS2_MASK                    (0x01UL << ADC_ADLSTAT_HLS2_SHIFT)                  /*!< ADC_ADLSTAT: HLS2 Mask                  */
#define ADC_ADLSTAT_HLS2_SHIFT                   10                                                  /*!< ADC_ADLSTAT: HLS2 Position              */
#define ADC_ADLSTAT_HLS3_MASK                    (0x01UL << ADC_ADLSTAT_HLS3_SHIFT)                  /*!< ADC_ADLSTAT: HLS3 Mask                  */
#define ADC_ADLSTAT_HLS3_SHIFT                   11                                                  /*!< ADC_ADLSTAT: HLS3 Position              */
#define ADC_ADLSTAT_HLS4_MASK                    (0x01UL << ADC_ADLSTAT_HLS4_SHIFT)                  /*!< ADC_ADLSTAT: HLS4 Mask                  */
#define ADC_ADLSTAT_HLS4_SHIFT                   12                                                  /*!< ADC_ADLSTAT: HLS4 Position              */
#define ADC_ADLSTAT_HLS5_MASK                    (0x01UL << ADC_ADLSTAT_HLS5_SHIFT)                  /*!< ADC_ADLSTAT: HLS5 Mask                  */
#define ADC_ADLSTAT_HLS5_SHIFT                   13                                                  /*!< ADC_ADLSTAT: HLS5 Position              */
#define ADC_ADLSTAT_HLS6_MASK                    (0x01UL << ADC_ADLSTAT_HLS6_SHIFT)                  /*!< ADC_ADLSTAT: HLS6 Mask                  */
#define ADC_ADLSTAT_HLS6_SHIFT                   14                                                  /*!< ADC_ADLSTAT: HLS6 Position              */
#define ADC_ADLSTAT_HLS7_MASK                    (0x01UL << ADC_ADLSTAT_HLS7_SHIFT)                  /*!< ADC_ADLSTAT: HLS7 Mask                  */
#define ADC_ADLSTAT_HLS7_SHIFT                   15                                                  /*!< ADC_ADLSTAT: HLS7 Position              */
/* ------- ADZCSTAT Bit Fields                      ------ */
#define ADC_ADZCSTAT_ZCS0_MASK                   (0x01UL << ADC_ADZCSTAT_ZCS0_SHIFT)                 /*!< ADC_ADZCSTAT: ZCS0 Mask                 */
#define ADC_ADZCSTAT_ZCS0_SHIFT                  0                                                   /*!< ADC_ADZCSTAT: ZCS0 Position             */
#define ADC_ADZCSTAT_ZCS1_MASK                   (0x01UL << ADC_ADZCSTAT_ZCS1_SHIFT)                 /*!< ADC_ADZCSTAT: ZCS1 Mask                 */
#define ADC_ADZCSTAT_ZCS1_SHIFT                  1                                                   /*!< ADC_ADZCSTAT: ZCS1 Position             */
#define ADC_ADZCSTAT_ZCS2_MASK                   (0x01UL << ADC_ADZCSTAT_ZCS2_SHIFT)                 /*!< ADC_ADZCSTAT: ZCS2 Mask                 */
#define ADC_ADZCSTAT_ZCS2_SHIFT                  2                                                   /*!< ADC_ADZCSTAT: ZCS2 Position             */
#define ADC_ADZCSTAT_ZCS3_MASK                   (0x01UL << ADC_ADZCSTAT_ZCS3_SHIFT)                 /*!< ADC_ADZCSTAT: ZCS3 Mask                 */
#define ADC_ADZCSTAT_ZCS3_SHIFT                  3                                                   /*!< ADC_ADZCSTAT: ZCS3 Position             */
#define ADC_ADZCSTAT_ZCS4_MASK                   (0x01UL << ADC_ADZCSTAT_ZCS4_SHIFT)                 /*!< ADC_ADZCSTAT: ZCS4 Mask                 */
#define ADC_ADZCSTAT_ZCS4_SHIFT                  4                                                   /*!< ADC_ADZCSTAT: ZCS4 Position             */
#define ADC_ADZCSTAT_ZCS5_MASK                   (0x01UL << ADC_ADZCSTAT_ZCS5_SHIFT)                 /*!< ADC_ADZCSTAT: ZCS5 Mask                 */
#define ADC_ADZCSTAT_ZCS5_SHIFT                  5                                                   /*!< ADC_ADZCSTAT: ZCS5 Position             */
#define ADC_ADZCSTAT_ZCS6_MASK                   (0x01UL << ADC_ADZCSTAT_ZCS6_SHIFT)                 /*!< ADC_ADZCSTAT: ZCS6 Mask                 */
#define ADC_ADZCSTAT_ZCS6_SHIFT                  6                                                   /*!< ADC_ADZCSTAT: ZCS6 Position             */
#define ADC_ADZCSTAT_ZCS7_MASK                   (0x01UL << ADC_ADZCSTAT_ZCS7_SHIFT)                 /*!< ADC_ADZCSTAT: ZCS7 Mask                 */
#define ADC_ADZCSTAT_ZCS7_SHIFT                  7                                                   /*!< ADC_ADZCSTAT: ZCS7 Position             */
/* ------- ADRSLT Bit Fields                        ------ */
#define ADC_ADRSLT_RSLT_MASK                     (0xFFFUL << ADC_ADRSLT_RSLT_SHIFT)                  /*!< ADC_ADRSLT: RSLT Mask                   */
#define ADC_ADRSLT_RSLT_SHIFT                    3                                                   /*!< ADC_ADRSLT: RSLT Position               */
#define ADC_ADRSLT_RSLT(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADRSLT_RSLT_SHIFT))&ADC_ADRSLT_RSLT_MASK) /*!< ADC_ADRSLT                              */
#define ADC_ADRSLT_SEXT_MASK                     (0x01UL << ADC_ADRSLT_SEXT_SHIFT)                   /*!< ADC_ADRSLT: SEXT Mask                   */
#define ADC_ADRSLT_SEXT_SHIFT                    15                                                  /*!< ADC_ADRSLT: SEXT Position               */
/* ------- ADLLMT Bit Fields                        ------ */
#define ADC_ADLLMT_LLMT_MASK                     (0xFFFUL << ADC_ADLLMT_LLMT_SHIFT)                  /*!< ADC_ADLLMT: LLMT Mask                   */
#define ADC_ADLLMT_LLMT_SHIFT                    3                                                   /*!< ADC_ADLLMT: LLMT Position               */
#define ADC_ADLLMT_LLMT(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADLLMT_LLMT_SHIFT))&ADC_ADLLMT_LLMT_MASK) /*!< ADC_ADLLMT                              */
/* ------- ADHLMT Bit Fields                        ------ */
#define ADC_ADHLMT_HLMT_MASK                     (0xFFFUL << ADC_ADHLMT_HLMT_SHIFT)                  /*!< ADC_ADHLMT: HLMT Mask                   */
#define ADC_ADHLMT_HLMT_SHIFT                    3                                                   /*!< ADC_ADHLMT: HLMT Position               */
#define ADC_ADHLMT_HLMT(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADHLMT_HLMT_SHIFT))&ADC_ADHLMT_HLMT_MASK) /*!< ADC_ADHLMT                              */
/* ------- ADOFS Bit Fields                         ------ */
#define ADC_ADOFS_OFFSET_MASK                    (0xFFFUL << ADC_ADOFS_OFFSET_SHIFT)                 /*!< ADC_ADOFS: OFFSET Mask                  */
#define ADC_ADOFS_OFFSET_SHIFT                   3                                                   /*!< ADC_ADOFS: OFFSET Position              */
#define ADC_ADOFS_OFFSET(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADOFS_OFFSET_SHIFT))&ADC_ADOFS_OFFSET_MASK) /*!< ADC_ADOFS                               */
/* ------- POWER Bit Fields                         ------ */
#define ADC_POWER_PD0_MASK                       (0x01UL << ADC_POWER_PD0_SHIFT)                     /*!< ADC_POWER: PD0 Mask                     */
#define ADC_POWER_PD0_SHIFT                      0                                                   /*!< ADC_POWER: PD0 Position                 */
#define ADC_POWER_PD1_MASK                       (0x01UL << ADC_POWER_PD1_SHIFT)                     /*!< ADC_POWER: PD1 Mask                     */
#define ADC_POWER_PD1_SHIFT                      1                                                   /*!< ADC_POWER: PD1 Position                 */
#define ADC_POWER_PD2_MASK                       (0x01UL << ADC_POWER_PD2_SHIFT)                     /*!< ADC_POWER: PD2 Mask                     */
#define ADC_POWER_PD2_SHIFT                      2                                                   /*!< ADC_POWER: PD2 Position                 */
#define ADC_POWER_APD_MASK                       (0x01UL << ADC_POWER_APD_SHIFT)                     /*!< ADC_POWER: APD Mask                     */
#define ADC_POWER_APD_SHIFT                      3                                                   /*!< ADC_POWER: APD Position                 */
#define ADC_POWER_PUDELAY_MASK                   (0x3FUL << ADC_POWER_PUDELAY_SHIFT)                 /*!< ADC_POWER: PUDELAY Mask                 */
#define ADC_POWER_PUDELAY_SHIFT                  4                                                   /*!< ADC_POWER: PUDELAY Position             */
#define ADC_POWER_PUDELAY(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_POWER_PUDELAY_SHIFT))&ADC_POWER_PUDELAY_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_PSTS0_MASK                     (0x01UL << ADC_POWER_PSTS0_SHIFT)                   /*!< ADC_POWER: PSTS0 Mask                   */
#define ADC_POWER_PSTS0_SHIFT                    10                                                  /*!< ADC_POWER: PSTS0 Position               */
#define ADC_POWER_PSTS1_MASK                     (0x01UL << ADC_POWER_PSTS1_SHIFT)                   /*!< ADC_POWER: PSTS1 Mask                   */
#define ADC_POWER_PSTS1_SHIFT                    11                                                  /*!< ADC_POWER: PSTS1 Position               */
#define ADC_POWER_PSTS2_MASK                     (0x01UL << ADC_POWER_PSTS2_SHIFT)                   /*!< ADC_POWER: PSTS2 Mask                   */
#define ADC_POWER_PSTS2_SHIFT                    12                                                  /*!< ADC_POWER: PSTS2 Position               */
#define ADC_POWER_ASB_MASK                       (0x01UL << ADC_POWER_ASB_SHIFT)                     /*!< ADC_POWER: ASB Mask                     */
#define ADC_POWER_ASB_SHIFT                      15                                                  /*!< ADC_POWER: ASB Position                 */
/* ------- CAL Bit Fields                           ------ */
#define ADC_CAL_SEL_VREFL_MASK                   (0x01UL << ADC_CAL_SEL_VREFL_SHIFT)                 /*!< ADC_CAL: SEL_VREFL Mask                 */
#define ADC_CAL_SEL_VREFL_SHIFT                  14                                                  /*!< ADC_CAL: SEL_VREFL Position             */
#define ADC_CAL_SEL_VREFH_MASK                   (0x01UL << ADC_CAL_SEL_VREFH_SHIFT)                 /*!< ADC_CAL: SEL_VREFH Mask                 */
#define ADC_CAL_SEL_VREFH_SHIFT                  15                                                  /*!< ADC_CAL: SEL_VREFH Position             */

/* ADC - Peripheral instance base addresses */
#define ADC_BasePtr                    0x40190000UL
#define ADC                            ((ADC_Type *) ADC_BasePtr)
#define ADC_BASE_PTR                   (ADC)

/* ================================================================================ */
/* ================           CCM (file:MCF52233_CCM)              ================ */
/* ================================================================================ */

/**
 * @brief Chip Configuration Module
 */
typedef struct {                                /*!<       CCM Structure                                                */
   __I  uint16_t  CCR;                          /*!< 0000: Chip Configuration Register                                  */
   __I  uint8_t   RESERVED0;                    /*!< 0002:                                                              */
   __IO uint8_t   LPCR;                         /*!< 0003: Low-Power Control Register                                   */
   __I  uint16_t  RCON;                         /*!< 0004: Reset Configuration Register                                 */
   __I  uint16_t  CIR;                          /*!< 0006: Chip Identification Register                                 */
} CCM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'CCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- CCR Bit Fields                           ------ */
#define CCM_CCR_BMT_MASK                         (0x07UL << CCM_CCR_BMT_SHIFT)                       /*!< CCM_CCR: BMT Mask                       */
#define CCM_CCR_BMT_SHIFT                        0                                                   /*!< CCM_CCR: BMT Position                   */
#define CCM_CCR_BMT(x)                           (((uint16_t)(((uint16_t)(x))<<CCM_CCR_BMT_SHIFT))&CCM_CCR_BMT_MASK) /*!< CCM_CCR                                 */
#define CCM_CCR_BME_MASK                         (0x01UL << CCM_CCR_BME_SHIFT)                       /*!< CCM_CCR: BME Mask                       */
#define CCM_CCR_BME_SHIFT                        3                                                   /*!< CCM_CCR: BME Position                   */
#define CCM_CCR_PSTEN_MASK                       (0x01UL << CCM_CCR_PSTEN_SHIFT)                     /*!< CCM_CCR: PSTEN Mask                     */
#define CCM_CCR_PSTEN_SHIFT                      5                                                   /*!< CCM_CCR: PSTEN Position                 */
#define CCM_CCR_SZEN_MASK                        (0x01UL << CCM_CCR_SZEN_SHIFT)                      /*!< CCM_CCR: SZEN Mask                      */
#define CCM_CCR_SZEN_SHIFT                       6                                                   /*!< CCM_CCR: SZEN Position                  */
/* ------- LPCR Bit Fields                          ------ */
#define CCM_LPCR_LVDSE_MASK                      (0x01UL << CCM_LPCR_LVDSE_SHIFT)                    /*!< CCM_LPCR: LVDSE Mask                    */
#define CCM_LPCR_LVDSE_SHIFT                     1                                                   /*!< CCM_LPCR: LVDSE Position                */
#define CCM_LPCR_STPMD_MASK                      (0x03UL << CCM_LPCR_STPMD_SHIFT)                    /*!< CCM_LPCR: STPMD Mask                    */
#define CCM_LPCR_STPMD_SHIFT                     3                                                   /*!< CCM_LPCR: STPMD Position                */
#define CCM_LPCR_STPMD(x)                        (((uint8_t)(((uint8_t)(x))<<CCM_LPCR_STPMD_SHIFT))&CCM_LPCR_STPMD_MASK) /*!< CCM_LPCR                                */
#define CCM_LPCR_LPMD_MASK                       (0x01UL << CCM_LPCR_LPMD_SHIFT)                     /*!< CCM_LPCR: LPMD Mask                     */
#define CCM_LPCR_LPMD_SHIFT                      6                                                   /*!< CCM_LPCR: LPMD Position                 */
/* ------- RCON Bit Fields                          ------ */
#define CCM_RCON_MODE_MASK                       (0x01UL << CCM_RCON_MODE_SHIFT)                     /*!< CCM_RCON: MODE Mask                     */
#define CCM_RCON_MODE_SHIFT                      0                                                   /*!< CCM_RCON: MODE Position                 */
#define CCM_RCON_RLOAD_MASK                      (0x01UL << CCM_RCON_RLOAD_SHIFT)                    /*!< CCM_RCON: RLOAD Mask                    */
#define CCM_RCON_RLOAD_SHIFT                     5                                                   /*!< CCM_RCON: RLOAD Position                */
/* ------- CIR Bit Fields                           ------ */
#define CCM_CIR_PRN_MASK                         (0x3FUL << CCM_CIR_PRN_SHIFT)                       /*!< CCM_CIR: PRN Mask                       */
#define CCM_CIR_PRN_SHIFT                        0                                                   /*!< CCM_CIR: PRN Position                   */
#define CCM_CIR_PRN(x)                           (((uint16_t)(((uint16_t)(x))<<CCM_CIR_PRN_SHIFT))&CCM_CIR_PRN_MASK) /*!< CCM_CIR                                 */
#define CCM_CIR_PIN_MASK                         (0x3FFUL << CCM_CIR_PIN_SHIFT)                      /*!< CCM_CIR: PIN Mask                       */
#define CCM_CIR_PIN_SHIFT                        6                                                   /*!< CCM_CIR: PIN Position                   */
#define CCM_CIR_PIN(x)                           (((uint16_t)(((uint16_t)(x))<<CCM_CIR_PIN_SHIFT))&CCM_CIR_PIN_MASK) /*!< CCM_CIR                                 */

/* CCM - Peripheral instance base addresses */
#define CCM_BasePtr                    0x40110004UL
#define CCM                            ((CCM_Type *) CCM_BasePtr)
#define CCM_BASE_PTR                   (CCM)

/* ================================================================================ */
/* ================           CFM (file:MCF522xx_CFM)              ================ */
/* ================================================================================ */

/**
 * @brief ColdFire Flash Module
 */
typedef struct {                                /*!<       CFM Structure                                                */
   __IO uint16_t  CFMMCR;                       /*!< 0000: Module Configuration Register                                */
   __IO uint8_t   CFMCLKD;                      /*!< 0002: Clock Divider Register                                       */
   __I  uint8_t   RESERVED0[5];                 /*!< 0003:                                                              */
   __I  uint32_t  CFMSEC;                       /*!< 0008: Security Register                                            */
   __I  uint32_t  RESERVED1;                    /*!< 000C:                                                              */
   __IO uint32_t  CFMPROT;                      /*!< 0010: Protection Register                                          */
   __IO uint32_t  CFMSACC;                      /*!< 0014: Supervisor Access Register                                   */
   __IO uint32_t  CFMDACC;                      /*!< 0018: Data Access Register                                         */
   __I  uint32_t  RESERVED2;                    /*!< 001C:                                                              */
   __IO uint8_t   CFMUSTAT;                     /*!< 0020: User Status Register                                         */
   __I  uint8_t   RESERVED3[3];                 /*!< 0021:                                                              */
   __IO uint8_t   CFMCMD;                       /*!< 0024: Command Register                                             */
   __I  uint8_t   RESERVED4[37];                /*!< 0025:                                                              */
   __I  uint16_t  CFMCLKSEL;                    /*!< 004A: Clock Select Register                                        */
} CFM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'CFM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- CFMMCR Bit Fields                        ------ */
#define CFM_CFMMCR_KEYACC_MASK                   (0x01UL << CFM_CFMMCR_KEYACC_SHIFT)                 /*!< CFM_CFMMCR: KEYACC Mask                 */
#define CFM_CFMMCR_KEYACC_SHIFT                  5                                                   /*!< CFM_CFMMCR: KEYACC Position             */
#define CFM_CFMMCR_CCIE_MASK                     (0x01UL << CFM_CFMMCR_CCIE_SHIFT)                   /*!< CFM_CFMMCR: CCIE Mask                   */
#define CFM_CFMMCR_CCIE_SHIFT                    6                                                   /*!< CFM_CFMMCR: CCIE Position               */
#define CFM_CFMMCR_CBEIE_MASK                    (0x01UL << CFM_CFMMCR_CBEIE_SHIFT)                  /*!< CFM_CFMMCR: CBEIE Mask                  */
#define CFM_CFMMCR_CBEIE_SHIFT                   7                                                   /*!< CFM_CFMMCR: CBEIE Position              */
#define CFM_CFMMCR_AEIE_MASK                     (0x01UL << CFM_CFMMCR_AEIE_SHIFT)                   /*!< CFM_CFMMCR: AEIE Mask                   */
#define CFM_CFMMCR_AEIE_SHIFT                    8                                                   /*!< CFM_CFMMCR: AEIE Position               */
#define CFM_CFMMCR_PVIE_MASK                     (0x01UL << CFM_CFMMCR_PVIE_SHIFT)                   /*!< CFM_CFMMCR: PVIE Mask                   */
#define CFM_CFMMCR_PVIE_SHIFT                    9                                                   /*!< CFM_CFMMCR: PVIE Position               */
#define CFM_CFMMCR_LOCK_MASK                     (0x01UL << CFM_CFMMCR_LOCK_SHIFT)                   /*!< CFM_CFMMCR: LOCK Mask                   */
#define CFM_CFMMCR_LOCK_SHIFT                    10                                                  /*!< CFM_CFMMCR: LOCK Position               */
/* ------- CFMCLKD Bit Fields                       ------ */
#define CFM_CFMCLKD_DIV_MASK                     (0x3FUL << CFM_CFMCLKD_DIV_SHIFT)                   /*!< CFM_CFMCLKD: DIV Mask                   */
#define CFM_CFMCLKD_DIV_SHIFT                    0                                                   /*!< CFM_CFMCLKD: DIV Position               */
#define CFM_CFMCLKD_DIV(x)                       (((uint8_t)(((uint8_t)(x))<<CFM_CFMCLKD_DIV_SHIFT))&CFM_CFMCLKD_DIV_MASK) /*!< CFM_CFMCLKD                             */
#define CFM_CFMCLKD_PRDIV8_MASK                  (0x01UL << CFM_CFMCLKD_PRDIV8_SHIFT)                /*!< CFM_CFMCLKD: PRDIV8 Mask                */
#define CFM_CFMCLKD_PRDIV8_SHIFT                 6                                                   /*!< CFM_CFMCLKD: PRDIV8 Position            */
#define CFM_CFMCLKD_DIVLD_MASK                   (0x01UL << CFM_CFMCLKD_DIVLD_SHIFT)                 /*!< CFM_CFMCLKD: DIVLD Mask                 */
#define CFM_CFMCLKD_DIVLD_SHIFT                  7                                                   /*!< CFM_CFMCLKD: DIVLD Position             */
/* ------- CFMSEC Bit Fields                        ------ */
#define CFM_CFMSEC_SEC_MASK                      (0xFFFFUL << CFM_CFMSEC_SEC_SHIFT)                  /*!< CFM_CFMSEC: SEC Mask                    */
#define CFM_CFMSEC_SEC_SHIFT                     0                                                   /*!< CFM_CFMSEC: SEC Position                */
#define CFM_CFMSEC_SEC(x)                        (((uint32_t)(((uint32_t)(x))<<CFM_CFMSEC_SEC_SHIFT))&CFM_CFMSEC_SEC_MASK) /*!< CFM_CFMSEC                              */
#define CFM_CFMSEC_SECSTAT_MASK                  (0x01UL << CFM_CFMSEC_SECSTAT_SHIFT)                /*!< CFM_CFMSEC: SECSTAT Mask                */
#define CFM_CFMSEC_SECSTAT_SHIFT                 30                                                  /*!< CFM_CFMSEC: SECSTAT Position            */
#define CFM_CFMSEC_KEYEN_MASK                    (0x01UL << CFM_CFMSEC_KEYEN_SHIFT)                  /*!< CFM_CFMSEC: KEYEN Mask                  */
#define CFM_CFMSEC_KEYEN_SHIFT                   31                                                  /*!< CFM_CFMSEC: KEYEN Position              */
/* ------- CFMPROT Bit Fields                       ------ */
#define CFM_CFMPROT_PROTECT_MASK                 (0xFFFFFFFFUL << CFM_CFMPROT_PROTECT_SHIFT)         /*!< CFM_CFMPROT: PROTECT Mask               */
#define CFM_CFMPROT_PROTECT_SHIFT                0                                                   /*!< CFM_CFMPROT: PROTECT Position           */
#define CFM_CFMPROT_PROTECT(x)                   (((uint32_t)(((uint32_t)(x))<<CFM_CFMPROT_PROTECT_SHIFT))&CFM_CFMPROT_PROTECT_MASK) /*!< CFM_CFMPROT                             */
/* ------- CFMSACC Bit Fields                       ------ */
#define CFM_CFMSACC_SUPV_MASK                    (0xFFFFFFFFUL << CFM_CFMSACC_SUPV_SHIFT)            /*!< CFM_CFMSACC: SUPV Mask                  */
#define CFM_CFMSACC_SUPV_SHIFT                   0                                                   /*!< CFM_CFMSACC: SUPV Position              */
#define CFM_CFMSACC_SUPV(x)                      (((uint32_t)(((uint32_t)(x))<<CFM_CFMSACC_SUPV_SHIFT))&CFM_CFMSACC_SUPV_MASK) /*!< CFM_CFMSACC                             */
/* ------- CFMDACC Bit Fields                       ------ */
#define CFM_CFMDACC_DACC_MASK                    (0xFFFFFFFFUL << CFM_CFMDACC_DACC_SHIFT)            /*!< CFM_CFMDACC: DACC Mask                  */
#define CFM_CFMDACC_DACC_SHIFT                   0                                                   /*!< CFM_CFMDACC: DACC Position              */
#define CFM_CFMDACC_DACC(x)                      (((uint32_t)(((uint32_t)(x))<<CFM_CFMDACC_DACC_SHIFT))&CFM_CFMDACC_DACC_MASK) /*!< CFM_CFMDACC                             */
/* ------- CFMUSTAT Bit Fields                      ------ */
#define CFM_CFMUSTAT_BLANK_MASK                  (0x01UL << CFM_CFMUSTAT_BLANK_SHIFT)                /*!< CFM_CFMUSTAT: BLANK Mask                */
#define CFM_CFMUSTAT_BLANK_SHIFT                 2                                                   /*!< CFM_CFMUSTAT: BLANK Position            */
#define CFM_CFMUSTAT_ACCERR_MASK                 (0x01UL << CFM_CFMUSTAT_ACCERR_SHIFT)               /*!< CFM_CFMUSTAT: ACCERR Mask               */
#define CFM_CFMUSTAT_ACCERR_SHIFT                4                                                   /*!< CFM_CFMUSTAT: ACCERR Position           */
#define CFM_CFMUSTAT_PVIOL_MASK                  (0x01UL << CFM_CFMUSTAT_PVIOL_SHIFT)                /*!< CFM_CFMUSTAT: PVIOL Mask                */
#define CFM_CFMUSTAT_PVIOL_SHIFT                 5                                                   /*!< CFM_CFMUSTAT: PVIOL Position            */
#define CFM_CFMUSTAT_CCIF_MASK                   (0x01UL << CFM_CFMUSTAT_CCIF_SHIFT)                 /*!< CFM_CFMUSTAT: CCIF Mask                 */
#define CFM_CFMUSTAT_CCIF_SHIFT                  6                                                   /*!< CFM_CFMUSTAT: CCIF Position             */
#define CFM_CFMUSTAT_CBEIF_MASK                  (0x01UL << CFM_CFMUSTAT_CBEIF_SHIFT)                /*!< CFM_CFMUSTAT: CBEIF Mask                */
#define CFM_CFMUSTAT_CBEIF_SHIFT                 7                                                   /*!< CFM_CFMUSTAT: CBEIF Position            */
/* ------- CFMCMD Bit Fields                        ------ */
#define CFM_CFMCMD_CMD_MASK                      (0x7FUL << CFM_CFMCMD_CMD_SHIFT)                    /*!< CFM_CFMCMD: CMD Mask                    */
#define CFM_CFMCMD_CMD_SHIFT                     0                                                   /*!< CFM_CFMCMD: CMD Position                */
#define CFM_CFMCMD_CMD(x)                        (((uint8_t)(((uint8_t)(x))<<CFM_CFMCMD_CMD_SHIFT))&CFM_CFMCMD_CMD_MASK) /*!< CFM_CFMCMD                              */
/* ------- CFMCLKSEL Bit Fields                     ------ */
#define CFM_CFMCLKSEL_CLKSEL_MASK                (0x03UL << CFM_CFMCLKSEL_CLKSEL_SHIFT)              /*!< CFM_CFMCLKSEL: CLKSEL Mask              */
#define CFM_CFMCLKSEL_CLKSEL_SHIFT               0                                                   /*!< CFM_CFMCLKSEL: CLKSEL Position          */
#define CFM_CFMCLKSEL_CLKSEL(x)                  (((uint16_t)(((uint16_t)(x))<<CFM_CFMCLKSEL_CLKSEL_SHIFT))&CFM_CFMCLKSEL_CLKSEL_MASK) /*!< CFM_CFMCLKSEL                           */

/* CFM - Peripheral instance base addresses */
#define CFM_BasePtr                    0x401D0000UL
#define CFM                            ((CFM_Type *) CFM_BasePtr)
#define CFM_BASE_PTR                   (CFM)

/* ================================================================================ */
/* ================           CLOCK (file:MCF52233_CLOCK)          ================ */
/* ================================================================================ */

/**
 * @brief Clock Module
 */
typedef struct {                                /*!<       CLOCK Structure                                              */
   __IO uint16_t  SYNCR;                        /*!< 0000: Synthesizer Control Register                                 */
   __I  uint8_t   SYNSR;                        /*!< 0002: Synthesiser Status Register                                  */
   __I  uint8_t   RESERVED0[4];                 /*!< 0003:                                                              */
   __IO uint8_t   LPCR;                         /*!< 0007: Low Power Control Register                                   */
   __IO uint8_t   CCHR;                         /*!< 0008: Clock Control High Register                                  */
   __I  uint8_t   RESERVED1[3];                 /*!< 0009:                                                              */
   __IO uint32_t  RTCDR;                        /*!< 000C: Real Time Clock Divide Register                              */
} CLOCK_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'CLOCK' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- SYNCR Bit Fields                         ------ */
#define CLOCK_SYNCR_PLLEN_MASK                   (0x01UL << CLOCK_SYNCR_PLLEN_SHIFT)                 /*!< CLOCK_SYNCR: PLLEN Mask                 */
#define CLOCK_SYNCR_PLLEN_SHIFT                  0                                                   /*!< CLOCK_SYNCR: PLLEN Position             */
#define CLOCK_SYNCR_PLLMODE_MASK                 (0x01UL << CLOCK_SYNCR_PLLMODE_SHIFT)               /*!< CLOCK_SYNCR: PLLMODE Mask               */
#define CLOCK_SYNCR_PLLMODE_SHIFT                1                                                   /*!< CLOCK_SYNCR: PLLMODE Position           */
#define CLOCK_SYNCR_CLKSRC_MASK                  (0x01UL << CLOCK_SYNCR_CLKSRC_SHIFT)                /*!< CLOCK_SYNCR: CLKSRC Mask                */
#define CLOCK_SYNCR_CLKSRC_SHIFT                 2                                                   /*!< CLOCK_SYNCR: CLKSRC Position            */
#define CLOCK_SYNCR_FWKUP_MASK                   (0x01UL << CLOCK_SYNCR_FWKUP_SHIFT)                 /*!< CLOCK_SYNCR: FWKUP Mask                 */
#define CLOCK_SYNCR_FWKUP_SHIFT                  5                                                   /*!< CLOCK_SYNCR: FWKUP Position             */
#define CLOCK_SYNCR_DISCLK_MASK                  (0x01UL << CLOCK_SYNCR_DISCLK_SHIFT)                /*!< CLOCK_SYNCR: DISCLK Mask                */
#define CLOCK_SYNCR_DISCLK_SHIFT                 6                                                   /*!< CLOCK_SYNCR: DISCLK Position            */
#define CLOCK_SYNCR_LOCEN_MASK                   (0x01UL << CLOCK_SYNCR_LOCEN_SHIFT)                 /*!< CLOCK_SYNCR: LOCEN Mask                 */
#define CLOCK_SYNCR_LOCEN_SHIFT                  7                                                   /*!< CLOCK_SYNCR: LOCEN Position             */
#define CLOCK_SYNCR_RFD_MASK                     (0x07UL << CLOCK_SYNCR_RFD_SHIFT)                   /*!< CLOCK_SYNCR: RFD Mask                   */
#define CLOCK_SYNCR_RFD_SHIFT                    8                                                   /*!< CLOCK_SYNCR: RFD Position               */
#define CLOCK_SYNCR_RFD(x)                       (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_RFD_SHIFT))&CLOCK_SYNCR_RFD_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_LOCRE_MASK                   (0x01UL << CLOCK_SYNCR_LOCRE_SHIFT)                 /*!< CLOCK_SYNCR: LOCRE Mask                 */
#define CLOCK_SYNCR_LOCRE_SHIFT                  11                                                  /*!< CLOCK_SYNCR: LOCRE Position             */
#define CLOCK_SYNCR_MFD_MASK                     (0x07UL << CLOCK_SYNCR_MFD_SHIFT)                   /*!< CLOCK_SYNCR: MFD Mask                   */
#define CLOCK_SYNCR_MFD_SHIFT                    12                                                  /*!< CLOCK_SYNCR: MFD Position               */
#define CLOCK_SYNCR_MFD(x)                       (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_MFD_SHIFT))&CLOCK_SYNCR_MFD_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_LOLRE_MASK                   (0x01UL << CLOCK_SYNCR_LOLRE_SHIFT)                 /*!< CLOCK_SYNCR: LOLRE Mask                 */
#define CLOCK_SYNCR_LOLRE_SHIFT                  15                                                  /*!< CLOCK_SYNCR: LOLRE Position             */
/* ------- SYNSR Bit Fields                         ------ */
#define CLOCK_SYNSR_LOCS_MASK                    (0x01UL << CLOCK_SYNSR_LOCS_SHIFT)                  /*!< CLOCK_SYNSR: LOCS Mask                  */
#define CLOCK_SYNSR_LOCS_SHIFT                   2                                                   /*!< CLOCK_SYNSR: LOCS Position              */
#define CLOCK_SYNSR_LOCK_MASK                    (0x01UL << CLOCK_SYNSR_LOCK_SHIFT)                  /*!< CLOCK_SYNSR: LOCK Mask                  */
#define CLOCK_SYNSR_LOCK_SHIFT                   3                                                   /*!< CLOCK_SYNSR: LOCK Position              */
#define CLOCK_SYNSR_LOCKS_MASK                   (0x01UL << CLOCK_SYNSR_LOCKS_SHIFT)                 /*!< CLOCK_SYNSR: LOCKS Mask                 */
#define CLOCK_SYNSR_LOCKS_SHIFT                  4                                                   /*!< CLOCK_SYNSR: LOCKS Position             */
#define CLOCK_SYNSR_EXTOSC_MASK                  (0x01UL << CLOCK_SYNSR_EXTOSC_SHIFT)                /*!< CLOCK_SYNSR: EXTOSC Mask                */
#define CLOCK_SYNSR_EXTOSC_SHIFT                 7                                                   /*!< CLOCK_SYNSR: EXTOSC Position            */
/* ------- LPCR Bit Fields                          ------ */
#define CLOCK_LPCR_LPD_MASK                      (0x0FUL << CLOCK_LPCR_LPD_SHIFT)                    /*!< CLOCK_LPCR: LPD Mask                    */
#define CLOCK_LPCR_LPD_SHIFT                     0                                                   /*!< CLOCK_LPCR: LPD Position                */
#define CLOCK_LPCR_LPD(x)                        (((uint8_t)(((uint8_t)(x))<<CLOCK_LPCR_LPD_SHIFT))&CLOCK_LPCR_LPD_MASK) /*!< CLOCK_LPCR                              */
/* ------- CCHR Bit Fields                          ------ */
#define CLOCK_CCHR_CCHR_MASK                     (0x07UL << CLOCK_CCHR_CCHR_SHIFT)                   /*!< CLOCK_CCHR: CCHR Mask                   */
#define CLOCK_CCHR_CCHR_SHIFT                    0                                                   /*!< CLOCK_CCHR: CCHR Position               */
#define CLOCK_CCHR_CCHR(x)                       (((uint8_t)(((uint8_t)(x))<<CLOCK_CCHR_CCHR_SHIFT))&CLOCK_CCHR_CCHR_MASK) /*!< CLOCK_CCHR                              */
/* ------- RTCDR Bit Fields                         ------ */
#define CLOCK_RTCDR_RTCDF_MASK                   (0xFFFFFFFFUL << CLOCK_RTCDR_RTCDF_SHIFT)           /*!< CLOCK_RTCDR: RTCDF Mask                 */
#define CLOCK_RTCDR_RTCDF_SHIFT                  0                                                   /*!< CLOCK_RTCDR: RTCDF Position             */
#define CLOCK_RTCDR_RTCDF(x)                     (((uint32_t)(((uint32_t)(x))<<CLOCK_RTCDR_RTCDF_SHIFT))&CLOCK_RTCDR_RTCDF_MASK) /*!< CLOCK_RTCDR                             */

/* CLOCK - Peripheral instance base addresses */
#define CLOCK_BasePtr                  0x40120000UL
#define CLOCK                          ((CLOCK_Type *) CLOCK_BasePtr)
#define CLOCK_BASE_PTR                 (CLOCK)

/* ================================================================================ */
/* ================           DMA (file:MCF522xx_DMA)              ================ */
/* ================================================================================ */

/**
 * @brief DMA Controller Module
 */
typedef struct {                                /*!<       DMA Structure                                                */
   struct { /* (cluster) */                     /*!< 0000: (size=0x0040, 64)                                            */
      __IO uint32_t  SAR;                       /*!< 0000: Source Address Register                                      */
      __IO uint32_t  DAR;                       /*!< 0004: Destination Address Register                                 */
      union {                                   /*!< 0000: (size=0004)                                                  */
         __IO uint32_t  BCR;                    /*!< 0008: Byte Count and Status Register                               */
         __IO uint8_t   DSR;                    /*!< 0008: Status Register                                              */
      };
      __IO uint32_t  DCR;                       /*!< 000C: Control Register                                             */
   } CH[4];
} DMA_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'DMA' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- SAR Bit Fields                           ------ */
#define DMA_SAR_SAR_MASK                         (0xFFFFFFFFUL << DMA_SAR_SAR_SHIFT)                 /*!< DMA_SAR: SAR Mask                       */
#define DMA_SAR_SAR_SHIFT                        0                                                   /*!< DMA_SAR: SAR Position                   */
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_SAR_SAR_SHIFT))&DMA_SAR_SAR_MASK) /*!< DMA_SAR                                 */
/* ------- DAR Bit Fields                           ------ */
#define DMA_DAR_DAR_MASK                         (0xFFFFFFFFUL << DMA_DAR_DAR_SHIFT)                 /*!< DMA_DAR: DAR Mask                       */
#define DMA_DAR_DAR_SHIFT                        0                                                   /*!< DMA_DAR: DAR Position                   */
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DAR_DAR_SHIFT))&DMA_DAR_DAR_MASK) /*!< DMA_DAR                                 */
/* ------- BCR Bit Fields                           ------ */
#define DMA_BCR_BCR_MASK                         (0xFFFFFFUL << DMA_BCR_BCR_SHIFT)                   /*!< DMA_BCR: BCR Mask                       */
#define DMA_BCR_BCR_SHIFT                        0                                                   /*!< DMA_BCR: BCR Position                   */
#define DMA_BCR_BCR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_BCR_BCR_SHIFT))&DMA_BCR_BCR_MASK) /*!< DMA_BCR                                 */
#define DMA_BCR_DSR_MASK                         (0xFFUL << DMA_BCR_DSR_SHIFT)                       /*!< DMA_BCR: DSR Mask                       */
#define DMA_BCR_DSR_SHIFT                        24                                                  /*!< DMA_BCR: DSR Position                   */
#define DMA_BCR_DSR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_BCR_DSR_SHIFT))&DMA_BCR_DSR_MASK) /*!< DMA_BCR                                 */
/* ------- DSR Bit Fields                           ------ */
#define DMA_DSR_DONE_MASK                        (0x01UL << DMA_DSR_DONE_SHIFT)                      /*!< DMA_DSR: DONE Mask                      */
#define DMA_DSR_DONE_SHIFT                       0                                                   /*!< DMA_DSR: DONE Position                  */
#define DMA_DSR_BSY_MASK                         (0x01UL << DMA_DSR_BSY_SHIFT)                       /*!< DMA_DSR: BSY Mask                       */
#define DMA_DSR_BSY_SHIFT                        1                                                   /*!< DMA_DSR: BSY Position                   */
#define DMA_DSR_REQ_MASK                         (0x01UL << DMA_DSR_REQ_SHIFT)                       /*!< DMA_DSR: REQ Mask                       */
#define DMA_DSR_REQ_SHIFT                        2                                                   /*!< DMA_DSR: REQ Position                   */
#define DMA_DSR_BED_MASK                         (0x01UL << DMA_DSR_BED_SHIFT)                       /*!< DMA_DSR: BED Mask                       */
#define DMA_DSR_BED_SHIFT                        4                                                   /*!< DMA_DSR: BED Position                   */
#define DMA_DSR_BES_MASK                         (0x01UL << DMA_DSR_BES_SHIFT)                       /*!< DMA_DSR: BES Mask                       */
#define DMA_DSR_BES_SHIFT                        5                                                   /*!< DMA_DSR: BES Position                   */
#define DMA_DSR_CE_MASK                          (0x01UL << DMA_DSR_CE_SHIFT)                        /*!< DMA_DSR: CE Mask                        */
#define DMA_DSR_CE_SHIFT                         6                                                   /*!< DMA_DSR: CE Position                    */
/* ------- DCR Bit Fields                           ------ */
#define DMA_DCR_LCH2_MASK                        (0x03UL << DMA_DCR_LCH2_SHIFT)                      /*!< DMA_DCR: LCH2 Mask                      */
#define DMA_DCR_LCH2_SHIFT                       0                                                   /*!< DMA_DCR: LCH2 Position                  */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH2_SHIFT))&DMA_DCR_LCH2_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_LCH1_MASK                        (0x03UL << DMA_DCR_LCH1_SHIFT)                      /*!< DMA_DCR: LCH1 Mask                      */
#define DMA_DCR_LCH1_SHIFT                       2                                                   /*!< DMA_DCR: LCH1 Position                  */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH1_SHIFT))&DMA_DCR_LCH1_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_LINKCC_MASK                      (0x03UL << DMA_DCR_LINKCC_SHIFT)                    /*!< DMA_DCR: LINKCC Mask                    */
#define DMA_DCR_LINKCC_SHIFT                     4                                                   /*!< DMA_DCR: LINKCC Position                */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LINKCC_SHIFT))&DMA_DCR_LINKCC_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_D_REQ_MASK                       (0x01UL << DMA_DCR_D_REQ_SHIFT)                     /*!< DMA_DCR: D_REQ Mask                     */
#define DMA_DCR_D_REQ_SHIFT                      7                                                   /*!< DMA_DCR: D_REQ Position                 */
#define DMA_DCR_DMOD_MASK                        (0x0FUL << DMA_DCR_DMOD_SHIFT)                      /*!< DMA_DCR: DMOD Mask                      */
#define DMA_DCR_DMOD_SHIFT                       8                                                   /*!< DMA_DCR: DMOD Position                  */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DMOD_SHIFT))&DMA_DCR_DMOD_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_SMOD_MASK                        (0x0FUL << DMA_DCR_SMOD_SHIFT)                      /*!< DMA_DCR: SMOD Mask                      */
#define DMA_DCR_SMOD_SHIFT                       12                                                  /*!< DMA_DCR: SMOD Position                  */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SMOD_SHIFT))&DMA_DCR_SMOD_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_START_MASK                       (0x01UL << DMA_DCR_START_SHIFT)                     /*!< DMA_DCR: START Mask                     */
#define DMA_DCR_START_SHIFT                      16                                                  /*!< DMA_DCR: START Position                 */
#define DMA_DCR_DSIZE_MASK                       (0x03UL << DMA_DCR_DSIZE_SHIFT)                     /*!< DMA_DCR: DSIZE Mask                     */
#define DMA_DCR_DSIZE_SHIFT                      17                                                  /*!< DMA_DCR: DSIZE Position                 */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DSIZE_SHIFT))&DMA_DCR_DSIZE_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_DINC_MASK                        (0x01UL << DMA_DCR_DINC_SHIFT)                      /*!< DMA_DCR: DINC Mask                      */
#define DMA_DCR_DINC_SHIFT                       19                                                  /*!< DMA_DCR: DINC Position                  */
#define DMA_DCR_SSIZE_MASK                       (0x03UL << DMA_DCR_SSIZE_SHIFT)                     /*!< DMA_DCR: SSIZE Mask                     */
#define DMA_DCR_SSIZE_SHIFT                      20                                                  /*!< DMA_DCR: SSIZE Position                 */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SSIZE_SHIFT))&DMA_DCR_SSIZE_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_SINC_MASK                        (0x01UL << DMA_DCR_SINC_SHIFT)                      /*!< DMA_DCR: SINC Mask                      */
#define DMA_DCR_SINC_SHIFT                       22                                                  /*!< DMA_DCR: SINC Position                  */
#define DMA_DCR_BWC_MASK                         (0x07UL << DMA_DCR_BWC_SHIFT)                       /*!< DMA_DCR: BWC Mask                       */
#define DMA_DCR_BWC_SHIFT                        25                                                  /*!< DMA_DCR: BWC Position                   */
#define DMA_DCR_BWC(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DCR_BWC_SHIFT))&DMA_DCR_BWC_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_AA_MASK                          (0x01UL << DMA_DCR_AA_SHIFT)                        /*!< DMA_DCR: AA Mask                        */
#define DMA_DCR_AA_SHIFT                         28                                                  /*!< DMA_DCR: AA Position                    */
#define DMA_DCR_CS_MASK                          (0x01UL << DMA_DCR_CS_SHIFT)                        /*!< DMA_DCR: CS Mask                        */
#define DMA_DCR_CS_SHIFT                         29                                                  /*!< DMA_DCR: CS Position                    */
#define DMA_DCR_EEXT_MASK                        (0x01UL << DMA_DCR_EEXT_SHIFT)                      /*!< DMA_DCR: EEXT Mask                      */
#define DMA_DCR_EEXT_SHIFT                       30                                                  /*!< DMA_DCR: EEXT Position                  */
#define DMA_DCR_INT_MASK                         (0x01UL << DMA_DCR_INT_SHIFT)                       /*!< DMA_DCR: INT Mask                       */
#define DMA_DCR_INT_SHIFT                        31                                                  /*!< DMA_DCR: INT Position                   */

/* DMA - Peripheral instance base addresses */
#define DMA_BasePtr                    0x40000100UL
#define DMA                            ((DMA_Type *) DMA_BasePtr)
#define DMA_BASE_PTR                   (DMA)

/* ================================================================================ */
/* ================           DTIM (file:MCF522xx_DTIM)            ================ */
/* ================================================================================ */

/**
 * @brief DMA Timers
 */
typedef struct {                                /*!<       DTIM Structure                                               */
   struct { /* (cluster) */                     /*!< 0000: (size=0x0100, 256)                                           */
      __IO uint16_t  DTMR;                      /*!< 0000: Timer Mode Register                                          */
      __IO uint8_t   DTXMR;                     /*!< 0002: Timer Extended Mode                                          */
      __IO uint8_t   DTER;                      /*!< 0003: Timer Event                                                  */
      __IO uint32_t  DTRR;                      /*!< 0004: Timer Reference Register                                     */
      __I  uint32_t  DTCR;                      /*!< 0008: Timer Capture Registers                                      */
      __IO uint32_t  DTCN;                      /*!< 000C: Timer Counter                                                */
      __I  uint32_t  RESERVED0[12];             /*!< 0010:                                                              */
   } CH[4];
} DTIM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'DTIM' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- DTMR Bit Fields                          ------ */
#define DTIM_DTMR_RST_MASK                       (0x01UL << DTIM_DTMR_RST_SHIFT)                     /*!< DTIM_DTMR: RST Mask                     */
#define DTIM_DTMR_RST_SHIFT                      0                                                   /*!< DTIM_DTMR: RST Position                 */
#define DTIM_DTMR_CLK_MASK                       (0x03UL << DTIM_DTMR_CLK_SHIFT)                     /*!< DTIM_DTMR: CLK Mask                     */
#define DTIM_DTMR_CLK_SHIFT                      1                                                   /*!< DTIM_DTMR: CLK Position                 */
#define DTIM_DTMR_CLK(x)                         (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_CLK_SHIFT))&DTIM_DTMR_CLK_MASK) /*!< DTIM_DTMR                               */
#define DTIM_DTMR_FRR_MASK                       (0x01UL << DTIM_DTMR_FRR_SHIFT)                     /*!< DTIM_DTMR: FRR Mask                     */
#define DTIM_DTMR_FRR_SHIFT                      3                                                   /*!< DTIM_DTMR: FRR Position                 */
#define DTIM_DTMR_ORRI_MASK                      (0x01UL << DTIM_DTMR_ORRI_SHIFT)                    /*!< DTIM_DTMR: ORRI Mask                    */
#define DTIM_DTMR_ORRI_SHIFT                     4                                                   /*!< DTIM_DTMR: ORRI Position                */
#define DTIM_DTMR_OM_MASK                        (0x01UL << DTIM_DTMR_OM_SHIFT)                      /*!< DTIM_DTMR: OM Mask                      */
#define DTIM_DTMR_OM_SHIFT                       5                                                   /*!< DTIM_DTMR: OM Position                  */
#define DTIM_DTMR_CE_MASK                        (0x03UL << DTIM_DTMR_CE_SHIFT)                      /*!< DTIM_DTMR: CE Mask                      */
#define DTIM_DTMR_CE_SHIFT                       6                                                   /*!< DTIM_DTMR: CE Position                  */
#define DTIM_DTMR_CE(x)                          (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_CE_SHIFT))&DTIM_DTMR_CE_MASK) /*!< DTIM_DTMR                               */
#define DTIM_DTMR_PS_MASK                        (0xFFUL << DTIM_DTMR_PS_SHIFT)                      /*!< DTIM_DTMR: PS Mask                      */
#define DTIM_DTMR_PS_SHIFT                       8                                                   /*!< DTIM_DTMR: PS Position                  */
#define DTIM_DTMR_PS(x)                          (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_PS_SHIFT))&DTIM_DTMR_PS_MASK) /*!< DTIM_DTMR                               */
/* ------- DTXMR Bit Fields                         ------ */
#define DTIM_DTXMR_MODE16_MASK                   (0x01UL << DTIM_DTXMR_MODE16_SHIFT)                 /*!< DTIM_DTXMR: MODE16 Mask                 */
#define DTIM_DTXMR_MODE16_SHIFT                  0                                                   /*!< DTIM_DTXMR: MODE16 Position             */
#define DTIM_DTXMR_HALTED_MASK                   (0x01UL << DTIM_DTXMR_HALTED_SHIFT)                 /*!< DTIM_DTXMR: HALTED Mask                 */
#define DTIM_DTXMR_HALTED_SHIFT                  6                                                   /*!< DTIM_DTXMR: HALTED Position             */
#define DTIM_DTXMR_DMAEN_MASK                    (0x01UL << DTIM_DTXMR_DMAEN_SHIFT)                  /*!< DTIM_DTXMR: DMAEN Mask                  */
#define DTIM_DTXMR_DMAEN_SHIFT                   7                                                   /*!< DTIM_DTXMR: DMAEN Position              */
/* ------- DTER Bit Fields                          ------ */
#define DTIM_DTER_CAP_MASK                       (0x01UL << DTIM_DTER_CAP_SHIFT)                     /*!< DTIM_DTER: CAP Mask                     */
#define DTIM_DTER_CAP_SHIFT                      0                                                   /*!< DTIM_DTER: CAP Position                 */
#define DTIM_DTER_REF_MASK                       (0x01UL << DTIM_DTER_REF_SHIFT)                     /*!< DTIM_DTER: REF Mask                     */
#define DTIM_DTER_REF_SHIFT                      1                                                   /*!< DTIM_DTER: REF Position                 */
/* ------- DTRR Bit Fields                          ------ */
#define DTIM_DTRR_REF_MASK                       (0xFFFFFFFFUL << DTIM_DTRR_REF_SHIFT)               /*!< DTIM_DTRR: REF Mask                     */
#define DTIM_DTRR_REF_SHIFT                      0                                                   /*!< DTIM_DTRR: REF Position                 */
#define DTIM_DTRR_REF(x)                         (((uint32_t)(((uint32_t)(x))<<DTIM_DTRR_REF_SHIFT))&DTIM_DTRR_REF_MASK) /*!< DTIM_DTRR                               */
/* ------- DTCR Bit Fields                          ------ */
#define DTIM_DTCR_CAP_MASK                       (0xFFFFFFFFUL << DTIM_DTCR_CAP_SHIFT)               /*!< DTIM_DTCR: CAP Mask                     */
#define DTIM_DTCR_CAP_SHIFT                      0                                                   /*!< DTIM_DTCR: CAP Position                 */
#define DTIM_DTCR_CAP(x)                         (((uint32_t)(((uint32_t)(x))<<DTIM_DTCR_CAP_SHIFT))&DTIM_DTCR_CAP_MASK) /*!< DTIM_DTCR                               */
/* ------- DTCN Bit Fields                          ------ */
#define DTIM_DTCN_CNT_MASK                       (0xFFFFFFFFUL << DTIM_DTCN_CNT_SHIFT)               /*!< DTIM_DTCN: CNT Mask                     */
#define DTIM_DTCN_CNT_SHIFT                      0                                                   /*!< DTIM_DTCN: CNT Position                 */
#define DTIM_DTCN_CNT(x)                         (((uint32_t)(((uint32_t)(x))<<DTIM_DTCN_CNT_SHIFT))&DTIM_DTCN_CNT_MASK) /*!< DTIM_DTCN                               */

/* DTIM - Peripheral instance base addresses */
#define DTIM_BasePtr                   0x40000400UL
#define DTIM                           ((DTIM_Type *) DTIM_BasePtr)
#define DTIM_BASE_PTR                  (DTIM)

/* ================================================================================ */
/* ================           EPHY (file:MCF52233_EPHY)            ================ */
/* ================================================================================ */

/**
 * @brief None
 */
typedef struct {                                /*!<       EPHY Structure                                               */
   __IO uint8_t   EPHYCTL0;                     /*!< 0000: None                                                         */
   __IO uint8_t   EPHYCTL1;                     /*!< 0001: None                                                         */
   __IO uint8_t   EPHYSR;                       /*!< 0002: None                                                         */
} EPHY_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'EPHY' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- EPHYCTL0 Bit Fields                      ------ */
#define EPHY_EPHYCTL0_EPHYIEN_MASK               (0x01UL << EPHY_EPHYCTL0_EPHYIEN_SHIFT)             /*!< EPHY_EPHYCTL0: EPHYIEN Mask             */
#define EPHY_EPHYCTL0_EPHYIEN_SHIFT              0                                                   /*!< EPHY_EPHYCTL0: EPHYIEN Position         */
#define EPHY_EPHYCTL0_EPHYWAI_MASK               (0x01UL << EPHY_EPHYCTL0_EPHYWAI_SHIFT)             /*!< EPHY_EPHYCTL0: EPHYWAI Mask             */
#define EPHY_EPHYCTL0_EPHYWAI_SHIFT              2                                                   /*!< EPHY_EPHYCTL0: EPHYWAI Position         */
#define EPHY_EPHYCTL0_LEDEN_MASK                 (0x01UL << EPHY_EPHYCTL0_LEDEN_SHIFT)               /*!< EPHY_EPHYCTL0: LEDEN Mask               */
#define EPHY_EPHYCTL0_LEDEN_SHIFT                3                                                   /*!< EPHY_EPHYCTL0: LEDEN Position           */
#define EPHY_EPHYCTL0_DIS10_MASK                 (0x01UL << EPHY_EPHYCTL0_DIS10_SHIFT)               /*!< EPHY_EPHYCTL0: DIS10 Mask               */
#define EPHY_EPHYCTL0_DIS10_SHIFT                4                                                   /*!< EPHY_EPHYCTL0: DIS10 Position           */
#define EPHY_EPHYCTL0_DIS100_MASK                (0x01UL << EPHY_EPHYCTL0_DIS100_SHIFT)              /*!< EPHY_EPHYCTL0: DIS100 Mask              */
#define EPHY_EPHYCTL0_DIS100_SHIFT               5                                                   /*!< EPHY_EPHYCTL0: DIS100 Position          */
#define EPHY_EPHYCTL0_ANDIS_MASK                 (0x01UL << EPHY_EPHYCTL0_ANDIS_SHIFT)               /*!< EPHY_EPHYCTL0: ANDIS Mask               */
#define EPHY_EPHYCTL0_ANDIS_SHIFT                6                                                   /*!< EPHY_EPHYCTL0: ANDIS Position           */
#define EPHY_EPHYCTL0_EPHYEN_MASK                (0x01UL << EPHY_EPHYCTL0_EPHYEN_SHIFT)              /*!< EPHY_EPHYCTL0: EPHYEN Mask              */
#define EPHY_EPHYCTL0_EPHYEN_SHIFT               7                                                   /*!< EPHY_EPHYCTL0: EPHYEN Position          */
/* ------- EPHYCTL1 Bit Fields                      ------ */
#define EPHY_EPHYCTL1_PHYADD_MASK                (0x1FUL << EPHY_EPHYCTL1_PHYADD_SHIFT)              /*!< EPHY_EPHYCTL1: PHYADD Mask              */
#define EPHY_EPHYCTL1_PHYADD_SHIFT               0                                                   /*!< EPHY_EPHYCTL1: PHYADD Position          */
#define EPHY_EPHYCTL1_PHYADD(x)                  (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL1_PHYADD_SHIFT))&EPHY_EPHYCTL1_PHYADD_MASK) /*!< EPHY_EPHYCTL1                           */
/* ------- EPHYSR Bit Fields                        ------ */
#define EPHY_EPHYSR_EPHYIF_MASK                  (0x01UL << EPHY_EPHYSR_EPHYIF_SHIFT)                /*!< EPHY_EPHYSR: EPHYIF Mask                */
#define EPHY_EPHYSR_EPHYIF_SHIFT                 0                                                   /*!< EPHY_EPHYSR: EPHYIF Position            */
#define EPHY_EPHYSR_DIS10_MASK                   (0x01UL << EPHY_EPHYSR_DIS10_SHIFT)                 /*!< EPHY_EPHYSR: DIS10 Mask                 */
#define EPHY_EPHYSR_DIS10_SHIFT                  4                                                   /*!< EPHY_EPHYSR: DIS10 Position             */
#define EPHY_EPHYSR_DIS100_MASK                  (0x01UL << EPHY_EPHYSR_DIS100_SHIFT)                /*!< EPHY_EPHYSR: DIS100 Mask                */
#define EPHY_EPHYSR_DIS100_SHIFT                 5                                                   /*!< EPHY_EPHYSR: DIS100 Position            */

/* EPHY - Peripheral instance base addresses */
#define EPHY_BasePtr                   0x401E0000UL
#define EPHY                           ((EPHY_Type *) EPHY_BasePtr)
#define EPHY_BASE_PTR                  (EPHY)

/* ================================================================================ */
/* ================           EPORT0 (file:MCF522xx_EPORT0)        ================ */
/* ================================================================================ */

/**
 * @brief Edge Port Module
 */
typedef struct {                                /*!<       EPORT0 Structure                                             */
   __IO uint16_t  EPPAR;                        /*!< 0000: Pin Assignment Register                                      */
   __IO uint8_t   EPDDR;                        /*!< 0002: Data Direction Register                                      */
   __IO uint8_t   EPIER;                        /*!< 0003: Interrupt Enable Register                                    */
   __IO uint8_t   EPDR;                         /*!< 0004: Data Register                                                */
   __I  uint8_t   EPPDR;                        /*!< 0005: Pin Data Register                                            */
   __IO uint8_t   EPFR;                         /*!< 0006: Edge Flag Register                                           */
} EPORT0_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'EPORT0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- EPPAR Bit Fields                         ------ */
#define EPORT0_EPPAR_EPPA0_MASK                  (0x03UL << EPORT0_EPPAR_EPPA0_SHIFT)                /*!< EPORT0_EPPAR: EPPA0 Mask                */
#define EPORT0_EPPAR_EPPA0_SHIFT                 0                                                   /*!< EPORT0_EPPAR: EPPA0 Position            */
#define EPORT0_EPPAR_EPPA0(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA0_SHIFT))&EPORT0_EPPAR_EPPA0_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA1_MASK                  (0x03UL << EPORT0_EPPAR_EPPA1_SHIFT)                /*!< EPORT0_EPPAR: EPPA1 Mask                */
#define EPORT0_EPPAR_EPPA1_SHIFT                 2                                                   /*!< EPORT0_EPPAR: EPPA1 Position            */
#define EPORT0_EPPAR_EPPA1(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA1_SHIFT))&EPORT0_EPPAR_EPPA1_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA2_MASK                  (0x03UL << EPORT0_EPPAR_EPPA2_SHIFT)                /*!< EPORT0_EPPAR: EPPA2 Mask                */
#define EPORT0_EPPAR_EPPA2_SHIFT                 4                                                   /*!< EPORT0_EPPAR: EPPA2 Position            */
#define EPORT0_EPPAR_EPPA2(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA2_SHIFT))&EPORT0_EPPAR_EPPA2_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA3_MASK                  (0x03UL << EPORT0_EPPAR_EPPA3_SHIFT)                /*!< EPORT0_EPPAR: EPPA3 Mask                */
#define EPORT0_EPPAR_EPPA3_SHIFT                 6                                                   /*!< EPORT0_EPPAR: EPPA3 Position            */
#define EPORT0_EPPAR_EPPA3(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA3_SHIFT))&EPORT0_EPPAR_EPPA3_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA4_MASK                  (0x03UL << EPORT0_EPPAR_EPPA4_SHIFT)                /*!< EPORT0_EPPAR: EPPA4 Mask                */
#define EPORT0_EPPAR_EPPA4_SHIFT                 8                                                   /*!< EPORT0_EPPAR: EPPA4 Position            */
#define EPORT0_EPPAR_EPPA4(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA4_SHIFT))&EPORT0_EPPAR_EPPA4_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA5_MASK                  (0x03UL << EPORT0_EPPAR_EPPA5_SHIFT)                /*!< EPORT0_EPPAR: EPPA5 Mask                */
#define EPORT0_EPPAR_EPPA5_SHIFT                 10                                                  /*!< EPORT0_EPPAR: EPPA5 Position            */
#define EPORT0_EPPAR_EPPA5(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA5_SHIFT))&EPORT0_EPPAR_EPPA5_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA6_MASK                  (0x03UL << EPORT0_EPPAR_EPPA6_SHIFT)                /*!< EPORT0_EPPAR: EPPA6 Mask                */
#define EPORT0_EPPAR_EPPA6_SHIFT                 12                                                  /*!< EPORT0_EPPAR: EPPA6 Position            */
#define EPORT0_EPPAR_EPPA6(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA6_SHIFT))&EPORT0_EPPAR_EPPA6_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA7_MASK                  (0x03UL << EPORT0_EPPAR_EPPA7_SHIFT)                /*!< EPORT0_EPPAR: EPPA7 Mask                */
#define EPORT0_EPPAR_EPPA7_SHIFT                 14                                                  /*!< EPORT0_EPPAR: EPPA7 Position            */
#define EPORT0_EPPAR_EPPA7(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA7_SHIFT))&EPORT0_EPPAR_EPPA7_MASK) /*!< EPORT0_EPPAR                            */
/* ------- EPDDR Bit Fields                         ------ */
#define EPORT0_EPDDR_EPDD0_MASK                  (0x01UL << EPORT0_EPDDR_EPDD0_SHIFT)                /*!< EPORT0_EPDDR: EPDD0 Mask                */
#define EPORT0_EPDDR_EPDD0_SHIFT                 0                                                   /*!< EPORT0_EPDDR: EPDD0 Position            */
#define EPORT0_EPDDR_EPDD1_MASK                  (0x01UL << EPORT0_EPDDR_EPDD1_SHIFT)                /*!< EPORT0_EPDDR: EPDD1 Mask                */
#define EPORT0_EPDDR_EPDD1_SHIFT                 1                                                   /*!< EPORT0_EPDDR: EPDD1 Position            */
#define EPORT0_EPDDR_EPDD2_MASK                  (0x01UL << EPORT0_EPDDR_EPDD2_SHIFT)                /*!< EPORT0_EPDDR: EPDD2 Mask                */
#define EPORT0_EPDDR_EPDD2_SHIFT                 2                                                   /*!< EPORT0_EPDDR: EPDD2 Position            */
#define EPORT0_EPDDR_EPDD3_MASK                  (0x01UL << EPORT0_EPDDR_EPDD3_SHIFT)                /*!< EPORT0_EPDDR: EPDD3 Mask                */
#define EPORT0_EPDDR_EPDD3_SHIFT                 3                                                   /*!< EPORT0_EPDDR: EPDD3 Position            */
#define EPORT0_EPDDR_EPDD4_MASK                  (0x01UL << EPORT0_EPDDR_EPDD4_SHIFT)                /*!< EPORT0_EPDDR: EPDD4 Mask                */
#define EPORT0_EPDDR_EPDD4_SHIFT                 4                                                   /*!< EPORT0_EPDDR: EPDD4 Position            */
#define EPORT0_EPDDR_EPDD5_MASK                  (0x01UL << EPORT0_EPDDR_EPDD5_SHIFT)                /*!< EPORT0_EPDDR: EPDD5 Mask                */
#define EPORT0_EPDDR_EPDD5_SHIFT                 5                                                   /*!< EPORT0_EPDDR: EPDD5 Position            */
#define EPORT0_EPDDR_EPDD6_MASK                  (0x01UL << EPORT0_EPDDR_EPDD6_SHIFT)                /*!< EPORT0_EPDDR: EPDD6 Mask                */
#define EPORT0_EPDDR_EPDD6_SHIFT                 6                                                   /*!< EPORT0_EPDDR: EPDD6 Position            */
#define EPORT0_EPDDR_EPDD7_MASK                  (0x01UL << EPORT0_EPDDR_EPDD7_SHIFT)                /*!< EPORT0_EPDDR: EPDD7 Mask                */
#define EPORT0_EPDDR_EPDD7_SHIFT                 7                                                   /*!< EPORT0_EPDDR: EPDD7 Position            */
/* ------- EPIER Bit Fields                         ------ */
#define EPORT0_EPIER_EPIE0_MASK                  (0x01UL << EPORT0_EPIER_EPIE0_SHIFT)                /*!< EPORT0_EPIER: EPIE0 Mask                */
#define EPORT0_EPIER_EPIE0_SHIFT                 0                                                   /*!< EPORT0_EPIER: EPIE0 Position            */
#define EPORT0_EPIER_EPIE1_MASK                  (0x01UL << EPORT0_EPIER_EPIE1_SHIFT)                /*!< EPORT0_EPIER: EPIE1 Mask                */
#define EPORT0_EPIER_EPIE1_SHIFT                 1                                                   /*!< EPORT0_EPIER: EPIE1 Position            */
#define EPORT0_EPIER_EPIE2_MASK                  (0x01UL << EPORT0_EPIER_EPIE2_SHIFT)                /*!< EPORT0_EPIER: EPIE2 Mask                */
#define EPORT0_EPIER_EPIE2_SHIFT                 2                                                   /*!< EPORT0_EPIER: EPIE2 Position            */
#define EPORT0_EPIER_EPIE3_MASK                  (0x01UL << EPORT0_EPIER_EPIE3_SHIFT)                /*!< EPORT0_EPIER: EPIE3 Mask                */
#define EPORT0_EPIER_EPIE3_SHIFT                 3                                                   /*!< EPORT0_EPIER: EPIE3 Position            */
#define EPORT0_EPIER_EPIE4_MASK                  (0x01UL << EPORT0_EPIER_EPIE4_SHIFT)                /*!< EPORT0_EPIER: EPIE4 Mask                */
#define EPORT0_EPIER_EPIE4_SHIFT                 4                                                   /*!< EPORT0_EPIER: EPIE4 Position            */
#define EPORT0_EPIER_EPIE5_MASK                  (0x01UL << EPORT0_EPIER_EPIE5_SHIFT)                /*!< EPORT0_EPIER: EPIE5 Mask                */
#define EPORT0_EPIER_EPIE5_SHIFT                 5                                                   /*!< EPORT0_EPIER: EPIE5 Position            */
#define EPORT0_EPIER_EPIE6_MASK                  (0x01UL << EPORT0_EPIER_EPIE6_SHIFT)                /*!< EPORT0_EPIER: EPIE6 Mask                */
#define EPORT0_EPIER_EPIE6_SHIFT                 6                                                   /*!< EPORT0_EPIER: EPIE6 Position            */
#define EPORT0_EPIER_EPIE7_MASK                  (0x01UL << EPORT0_EPIER_EPIE7_SHIFT)                /*!< EPORT0_EPIER: EPIE7 Mask                */
#define EPORT0_EPIER_EPIE7_SHIFT                 7                                                   /*!< EPORT0_EPIER: EPIE7 Position            */
/* ------- EPDR Bit Fields                          ------ */
#define EPORT0_EPDR_EPD0_MASK                    (0x01UL << EPORT0_EPDR_EPD0_SHIFT)                  /*!< EPORT0_EPDR: EPD0 Mask                  */
#define EPORT0_EPDR_EPD0_SHIFT                   0                                                   /*!< EPORT0_EPDR: EPD0 Position              */
#define EPORT0_EPDR_EPD1_MASK                    (0x01UL << EPORT0_EPDR_EPD1_SHIFT)                  /*!< EPORT0_EPDR: EPD1 Mask                  */
#define EPORT0_EPDR_EPD1_SHIFT                   1                                                   /*!< EPORT0_EPDR: EPD1 Position              */
#define EPORT0_EPDR_EPD2_MASK                    (0x01UL << EPORT0_EPDR_EPD2_SHIFT)                  /*!< EPORT0_EPDR: EPD2 Mask                  */
#define EPORT0_EPDR_EPD2_SHIFT                   2                                                   /*!< EPORT0_EPDR: EPD2 Position              */
#define EPORT0_EPDR_EPD3_MASK                    (0x01UL << EPORT0_EPDR_EPD3_SHIFT)                  /*!< EPORT0_EPDR: EPD3 Mask                  */
#define EPORT0_EPDR_EPD3_SHIFT                   3                                                   /*!< EPORT0_EPDR: EPD3 Position              */
#define EPORT0_EPDR_EPD4_MASK                    (0x01UL << EPORT0_EPDR_EPD4_SHIFT)                  /*!< EPORT0_EPDR: EPD4 Mask                  */
#define EPORT0_EPDR_EPD4_SHIFT                   4                                                   /*!< EPORT0_EPDR: EPD4 Position              */
#define EPORT0_EPDR_EPD5_MASK                    (0x01UL << EPORT0_EPDR_EPD5_SHIFT)                  /*!< EPORT0_EPDR: EPD5 Mask                  */
#define EPORT0_EPDR_EPD5_SHIFT                   5                                                   /*!< EPORT0_EPDR: EPD5 Position              */
#define EPORT0_EPDR_EPD6_MASK                    (0x01UL << EPORT0_EPDR_EPD6_SHIFT)                  /*!< EPORT0_EPDR: EPD6 Mask                  */
#define EPORT0_EPDR_EPD6_SHIFT                   6                                                   /*!< EPORT0_EPDR: EPD6 Position              */
#define EPORT0_EPDR_EPD7_MASK                    (0x01UL << EPORT0_EPDR_EPD7_SHIFT)                  /*!< EPORT0_EPDR: EPD7 Mask                  */
#define EPORT0_EPDR_EPD7_SHIFT                   7                                                   /*!< EPORT0_EPDR: EPD7 Position              */
/* ------- EPPDR Bit Fields                         ------ */
#define EPORT0_EPPDR_EPPD0_MASK                  (0x01UL << EPORT0_EPPDR_EPPD0_SHIFT)                /*!< EPORT0_EPPDR: EPPD0 Mask                */
#define EPORT0_EPPDR_EPPD0_SHIFT                 0                                                   /*!< EPORT0_EPPDR: EPPD0 Position            */
#define EPORT0_EPPDR_EPPD1_MASK                  (0x01UL << EPORT0_EPPDR_EPPD1_SHIFT)                /*!< EPORT0_EPPDR: EPPD1 Mask                */
#define EPORT0_EPPDR_EPPD1_SHIFT                 1                                                   /*!< EPORT0_EPPDR: EPPD1 Position            */
#define EPORT0_EPPDR_EPPD2_MASK                  (0x01UL << EPORT0_EPPDR_EPPD2_SHIFT)                /*!< EPORT0_EPPDR: EPPD2 Mask                */
#define EPORT0_EPPDR_EPPD2_SHIFT                 2                                                   /*!< EPORT0_EPPDR: EPPD2 Position            */
#define EPORT0_EPPDR_EPPD3_MASK                  (0x01UL << EPORT0_EPPDR_EPPD3_SHIFT)                /*!< EPORT0_EPPDR: EPPD3 Mask                */
#define EPORT0_EPPDR_EPPD3_SHIFT                 3                                                   /*!< EPORT0_EPPDR: EPPD3 Position            */
#define EPORT0_EPPDR_EPPD4_MASK                  (0x01UL << EPORT0_EPPDR_EPPD4_SHIFT)                /*!< EPORT0_EPPDR: EPPD4 Mask                */
#define EPORT0_EPPDR_EPPD4_SHIFT                 4                                                   /*!< EPORT0_EPPDR: EPPD4 Position            */
#define EPORT0_EPPDR_EPPD5_MASK                  (0x01UL << EPORT0_EPPDR_EPPD5_SHIFT)                /*!< EPORT0_EPPDR: EPPD5 Mask                */
#define EPORT0_EPPDR_EPPD5_SHIFT                 5                                                   /*!< EPORT0_EPPDR: EPPD5 Position            */
#define EPORT0_EPPDR_EPPD6_MASK                  (0x01UL << EPORT0_EPPDR_EPPD6_SHIFT)                /*!< EPORT0_EPPDR: EPPD6 Mask                */
#define EPORT0_EPPDR_EPPD6_SHIFT                 6                                                   /*!< EPORT0_EPPDR: EPPD6 Position            */
#define EPORT0_EPPDR_EPPD7_MASK                  (0x01UL << EPORT0_EPPDR_EPPD7_SHIFT)                /*!< EPORT0_EPPDR: EPPD7 Mask                */
#define EPORT0_EPPDR_EPPD7_SHIFT                 7                                                   /*!< EPORT0_EPPDR: EPPD7 Position            */
/* ------- EPFR Bit Fields                          ------ */
#define EPORT0_EPFR_EPF0_MASK                    (0x01UL << EPORT0_EPFR_EPF0_SHIFT)                  /*!< EPORT0_EPFR: EPF0 Mask                  */
#define EPORT0_EPFR_EPF0_SHIFT                   0                                                   /*!< EPORT0_EPFR: EPF0 Position              */
#define EPORT0_EPFR_EPF1_MASK                    (0x01UL << EPORT0_EPFR_EPF1_SHIFT)                  /*!< EPORT0_EPFR: EPF1 Mask                  */
#define EPORT0_EPFR_EPF1_SHIFT                   1                                                   /*!< EPORT0_EPFR: EPF1 Position              */
#define EPORT0_EPFR_EPF2_MASK                    (0x01UL << EPORT0_EPFR_EPF2_SHIFT)                  /*!< EPORT0_EPFR: EPF2 Mask                  */
#define EPORT0_EPFR_EPF2_SHIFT                   2                                                   /*!< EPORT0_EPFR: EPF2 Position              */
#define EPORT0_EPFR_EPF3_MASK                    (0x01UL << EPORT0_EPFR_EPF3_SHIFT)                  /*!< EPORT0_EPFR: EPF3 Mask                  */
#define EPORT0_EPFR_EPF3_SHIFT                   3                                                   /*!< EPORT0_EPFR: EPF3 Position              */
#define EPORT0_EPFR_EPF4_MASK                    (0x01UL << EPORT0_EPFR_EPF4_SHIFT)                  /*!< EPORT0_EPFR: EPF4 Mask                  */
#define EPORT0_EPFR_EPF4_SHIFT                   4                                                   /*!< EPORT0_EPFR: EPF4 Position              */
#define EPORT0_EPFR_EPF5_MASK                    (0x01UL << EPORT0_EPFR_EPF5_SHIFT)                  /*!< EPORT0_EPFR: EPF5 Mask                  */
#define EPORT0_EPFR_EPF5_SHIFT                   5                                                   /*!< EPORT0_EPFR: EPF5 Position              */
#define EPORT0_EPFR_EPF6_MASK                    (0x01UL << EPORT0_EPFR_EPF6_SHIFT)                  /*!< EPORT0_EPFR: EPF6 Mask                  */
#define EPORT0_EPFR_EPF6_SHIFT                   6                                                   /*!< EPORT0_EPFR: EPF6 Position              */
#define EPORT0_EPFR_EPF7_MASK                    (0x01UL << EPORT0_EPFR_EPF7_SHIFT)                  /*!< EPORT0_EPFR: EPF7 Mask                  */
#define EPORT0_EPFR_EPF7_SHIFT                   7                                                   /*!< EPORT0_EPFR: EPF7 Position              */

/* EPORT0 - Peripheral instance base addresses */
#define EPORT0_BasePtr                 0x40130000UL
#define EPORT0                         ((EPORT0_Type *) EPORT0_BasePtr)
#define EPORT0_BASE_PTR                (EPORT0)

/* ================================================================================ */
/* ================           EPORT1 (file:MCF522xx_EPORT1)        ================ */
/* ================================================================================ */

/**
 * @brief Edge Port Module
 */
typedef struct {                                /*!<       EPORT1 Structure                                             */
   __IO uint16_t  EPPAR;                        /*!< 0000: Pin Assignment Register                                      */
   __IO uint8_t   EPDDR;                        /*!< 0002: Data Direction Register                                      */
   __IO uint8_t   EPIER;                        /*!< 0003: Interrupt Enable Register                                    */
   __IO uint8_t   EPDR;                         /*!< 0004: Data Register                                                */
   __I  uint8_t   EPPDR;                        /*!< 0005: Pin Data Register                                            */
   __IO uint8_t   EPFR;                         /*!< 0006: Edge Flag Register                                           */
} EPORT1_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'EPORT1' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- EPPAR Bit Fields                         ------ */
#define EPORT1_EPPAR_EPPA8_MASK                  (0x03UL << EPORT1_EPPAR_EPPA8_SHIFT)                /*!< EPORT1_EPPAR: EPPA8 Mask                */
#define EPORT1_EPPAR_EPPA8_SHIFT                 0                                                   /*!< EPORT1_EPPAR: EPPA8 Position            */
#define EPORT1_EPPAR_EPPA8(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA8_SHIFT))&EPORT1_EPPAR_EPPA8_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA9_MASK                  (0x03UL << EPORT1_EPPAR_EPPA9_SHIFT)                /*!< EPORT1_EPPAR: EPPA9 Mask                */
#define EPORT1_EPPAR_EPPA9_SHIFT                 2                                                   /*!< EPORT1_EPPAR: EPPA9 Position            */
#define EPORT1_EPPAR_EPPA9(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA9_SHIFT))&EPORT1_EPPAR_EPPA9_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA10_MASK                 (0x03UL << EPORT1_EPPAR_EPPA10_SHIFT)               /*!< EPORT1_EPPAR: EPPA10 Mask               */
#define EPORT1_EPPAR_EPPA10_SHIFT                4                                                   /*!< EPORT1_EPPAR: EPPA10 Position           */
#define EPORT1_EPPAR_EPPA10(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA10_SHIFT))&EPORT1_EPPAR_EPPA10_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA11_MASK                 (0x03UL << EPORT1_EPPAR_EPPA11_SHIFT)               /*!< EPORT1_EPPAR: EPPA11 Mask               */
#define EPORT1_EPPAR_EPPA11_SHIFT                6                                                   /*!< EPORT1_EPPAR: EPPA11 Position           */
#define EPORT1_EPPAR_EPPA11(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA11_SHIFT))&EPORT1_EPPAR_EPPA11_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA12_MASK                 (0x03UL << EPORT1_EPPAR_EPPA12_SHIFT)               /*!< EPORT1_EPPAR: EPPA12 Mask               */
#define EPORT1_EPPAR_EPPA12_SHIFT                8                                                   /*!< EPORT1_EPPAR: EPPA12 Position           */
#define EPORT1_EPPAR_EPPA12(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA12_SHIFT))&EPORT1_EPPAR_EPPA12_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA13_MASK                 (0x03UL << EPORT1_EPPAR_EPPA13_SHIFT)               /*!< EPORT1_EPPAR: EPPA13 Mask               */
#define EPORT1_EPPAR_EPPA13_SHIFT                10                                                  /*!< EPORT1_EPPAR: EPPA13 Position           */
#define EPORT1_EPPAR_EPPA13(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA13_SHIFT))&EPORT1_EPPAR_EPPA13_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA14_MASK                 (0x03UL << EPORT1_EPPAR_EPPA14_SHIFT)               /*!< EPORT1_EPPAR: EPPA14 Mask               */
#define EPORT1_EPPAR_EPPA14_SHIFT                12                                                  /*!< EPORT1_EPPAR: EPPA14 Position           */
#define EPORT1_EPPAR_EPPA14(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA14_SHIFT))&EPORT1_EPPAR_EPPA14_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA15_MASK                 (0x03UL << EPORT1_EPPAR_EPPA15_SHIFT)               /*!< EPORT1_EPPAR: EPPA15 Mask               */
#define EPORT1_EPPAR_EPPA15_SHIFT                14                                                  /*!< EPORT1_EPPAR: EPPA15 Position           */
#define EPORT1_EPPAR_EPPA15(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA15_SHIFT))&EPORT1_EPPAR_EPPA15_MASK) /*!< EPORT1_EPPAR                            */
/* ------- EPDDR Bit Fields                         ------ */
#define EPORT1_EPDDR_EPDD8_MASK                  (0x01UL << EPORT1_EPDDR_EPDD8_SHIFT)                /*!< EPORT1_EPDDR: EPDD8 Mask                */
#define EPORT1_EPDDR_EPDD8_SHIFT                 0                                                   /*!< EPORT1_EPDDR: EPDD8 Position            */
#define EPORT1_EPDDR_EPDD9_MASK                  (0x01UL << EPORT1_EPDDR_EPDD9_SHIFT)                /*!< EPORT1_EPDDR: EPDD9 Mask                */
#define EPORT1_EPDDR_EPDD9_SHIFT                 1                                                   /*!< EPORT1_EPDDR: EPDD9 Position            */
#define EPORT1_EPDDR_EPDD10_MASK                 (0x01UL << EPORT1_EPDDR_EPDD10_SHIFT)               /*!< EPORT1_EPDDR: EPDD10 Mask               */
#define EPORT1_EPDDR_EPDD10_SHIFT                2                                                   /*!< EPORT1_EPDDR: EPDD10 Position           */
#define EPORT1_EPDDR_EPDD11_MASK                 (0x01UL << EPORT1_EPDDR_EPDD11_SHIFT)               /*!< EPORT1_EPDDR: EPDD11 Mask               */
#define EPORT1_EPDDR_EPDD11_SHIFT                3                                                   /*!< EPORT1_EPDDR: EPDD11 Position           */
#define EPORT1_EPDDR_EPDD12_MASK                 (0x01UL << EPORT1_EPDDR_EPDD12_SHIFT)               /*!< EPORT1_EPDDR: EPDD12 Mask               */
#define EPORT1_EPDDR_EPDD12_SHIFT                4                                                   /*!< EPORT1_EPDDR: EPDD12 Position           */
#define EPORT1_EPDDR_EPDD13_MASK                 (0x01UL << EPORT1_EPDDR_EPDD13_SHIFT)               /*!< EPORT1_EPDDR: EPDD13 Mask               */
#define EPORT1_EPDDR_EPDD13_SHIFT                5                                                   /*!< EPORT1_EPDDR: EPDD13 Position           */
#define EPORT1_EPDDR_EPDD14_MASK                 (0x01UL << EPORT1_EPDDR_EPDD14_SHIFT)               /*!< EPORT1_EPDDR: EPDD14 Mask               */
#define EPORT1_EPDDR_EPDD14_SHIFT                6                                                   /*!< EPORT1_EPDDR: EPDD14 Position           */
#define EPORT1_EPDDR_EPDD15_MASK                 (0x01UL << EPORT1_EPDDR_EPDD15_SHIFT)               /*!< EPORT1_EPDDR: EPDD15 Mask               */
#define EPORT1_EPDDR_EPDD15_SHIFT                7                                                   /*!< EPORT1_EPDDR: EPDD15 Position           */
/* ------- EPIER Bit Fields                         ------ */
#define EPORT1_EPIER_EPIE8_MASK                  (0x01UL << EPORT1_EPIER_EPIE8_SHIFT)                /*!< EPORT1_EPIER: EPIE8 Mask                */
#define EPORT1_EPIER_EPIE8_SHIFT                 0                                                   /*!< EPORT1_EPIER: EPIE8 Position            */
#define EPORT1_EPIER_EPIE9_MASK                  (0x01UL << EPORT1_EPIER_EPIE9_SHIFT)                /*!< EPORT1_EPIER: EPIE9 Mask                */
#define EPORT1_EPIER_EPIE9_SHIFT                 1                                                   /*!< EPORT1_EPIER: EPIE9 Position            */
#define EPORT1_EPIER_EPIE10_MASK                 (0x01UL << EPORT1_EPIER_EPIE10_SHIFT)               /*!< EPORT1_EPIER: EPIE10 Mask               */
#define EPORT1_EPIER_EPIE10_SHIFT                2                                                   /*!< EPORT1_EPIER: EPIE10 Position           */
#define EPORT1_EPIER_EPIE11_MASK                 (0x01UL << EPORT1_EPIER_EPIE11_SHIFT)               /*!< EPORT1_EPIER: EPIE11 Mask               */
#define EPORT1_EPIER_EPIE11_SHIFT                3                                                   /*!< EPORT1_EPIER: EPIE11 Position           */
#define EPORT1_EPIER_EPIE12_MASK                 (0x01UL << EPORT1_EPIER_EPIE12_SHIFT)               /*!< EPORT1_EPIER: EPIE12 Mask               */
#define EPORT1_EPIER_EPIE12_SHIFT                4                                                   /*!< EPORT1_EPIER: EPIE12 Position           */
#define EPORT1_EPIER_EPIE13_MASK                 (0x01UL << EPORT1_EPIER_EPIE13_SHIFT)               /*!< EPORT1_EPIER: EPIE13 Mask               */
#define EPORT1_EPIER_EPIE13_SHIFT                5                                                   /*!< EPORT1_EPIER: EPIE13 Position           */
#define EPORT1_EPIER_EPIE14_MASK                 (0x01UL << EPORT1_EPIER_EPIE14_SHIFT)               /*!< EPORT1_EPIER: EPIE14 Mask               */
#define EPORT1_EPIER_EPIE14_SHIFT                6                                                   /*!< EPORT1_EPIER: EPIE14 Position           */
#define EPORT1_EPIER_EPIE15_MASK                 (0x01UL << EPORT1_EPIER_EPIE15_SHIFT)               /*!< EPORT1_EPIER: EPIE15 Mask               */
#define EPORT1_EPIER_EPIE15_SHIFT                7                                                   /*!< EPORT1_EPIER: EPIE15 Position           */
/* ------- EPDR Bit Fields                          ------ */
#define EPORT1_EPDR_EPD8_MASK                    (0x01UL << EPORT1_EPDR_EPD8_SHIFT)                  /*!< EPORT1_EPDR: EPD8 Mask                  */
#define EPORT1_EPDR_EPD8_SHIFT                   0                                                   /*!< EPORT1_EPDR: EPD8 Position              */
#define EPORT1_EPDR_EPD9_MASK                    (0x01UL << EPORT1_EPDR_EPD9_SHIFT)                  /*!< EPORT1_EPDR: EPD9 Mask                  */
#define EPORT1_EPDR_EPD9_SHIFT                   1                                                   /*!< EPORT1_EPDR: EPD9 Position              */
#define EPORT1_EPDR_EPD10_MASK                   (0x01UL << EPORT1_EPDR_EPD10_SHIFT)                 /*!< EPORT1_EPDR: EPD10 Mask                 */
#define EPORT1_EPDR_EPD10_SHIFT                  2                                                   /*!< EPORT1_EPDR: EPD10 Position             */
#define EPORT1_EPDR_EPD11_MASK                   (0x01UL << EPORT1_EPDR_EPD11_SHIFT)                 /*!< EPORT1_EPDR: EPD11 Mask                 */
#define EPORT1_EPDR_EPD11_SHIFT                  3                                                   /*!< EPORT1_EPDR: EPD11 Position             */
#define EPORT1_EPDR_EPD12_MASK                   (0x01UL << EPORT1_EPDR_EPD12_SHIFT)                 /*!< EPORT1_EPDR: EPD12 Mask                 */
#define EPORT1_EPDR_EPD12_SHIFT                  4                                                   /*!< EPORT1_EPDR: EPD12 Position             */
#define EPORT1_EPDR_EPD13_MASK                   (0x01UL << EPORT1_EPDR_EPD13_SHIFT)                 /*!< EPORT1_EPDR: EPD13 Mask                 */
#define EPORT1_EPDR_EPD13_SHIFT                  5                                                   /*!< EPORT1_EPDR: EPD13 Position             */
#define EPORT1_EPDR_EPD14_MASK                   (0x01UL << EPORT1_EPDR_EPD14_SHIFT)                 /*!< EPORT1_EPDR: EPD14 Mask                 */
#define EPORT1_EPDR_EPD14_SHIFT                  6                                                   /*!< EPORT1_EPDR: EPD14 Position             */
#define EPORT1_EPDR_EPD15_MASK                   (0x01UL << EPORT1_EPDR_EPD15_SHIFT)                 /*!< EPORT1_EPDR: EPD15 Mask                 */
#define EPORT1_EPDR_EPD15_SHIFT                  7                                                   /*!< EPORT1_EPDR: EPD15 Position             */
/* ------- EPPDR Bit Fields                         ------ */
#define EPORT1_EPPDR_EPPD8_MASK                  (0x01UL << EPORT1_EPPDR_EPPD8_SHIFT)                /*!< EPORT1_EPPDR: EPPD8 Mask                */
#define EPORT1_EPPDR_EPPD8_SHIFT                 0                                                   /*!< EPORT1_EPPDR: EPPD8 Position            */
#define EPORT1_EPPDR_EPPD9_MASK                  (0x01UL << EPORT1_EPPDR_EPPD9_SHIFT)                /*!< EPORT1_EPPDR: EPPD9 Mask                */
#define EPORT1_EPPDR_EPPD9_SHIFT                 1                                                   /*!< EPORT1_EPPDR: EPPD9 Position            */
#define EPORT1_EPPDR_EPPD10_MASK                 (0x01UL << EPORT1_EPPDR_EPPD10_SHIFT)               /*!< EPORT1_EPPDR: EPPD10 Mask               */
#define EPORT1_EPPDR_EPPD10_SHIFT                2                                                   /*!< EPORT1_EPPDR: EPPD10 Position           */
#define EPORT1_EPPDR_EPPD11_MASK                 (0x01UL << EPORT1_EPPDR_EPPD11_SHIFT)               /*!< EPORT1_EPPDR: EPPD11 Mask               */
#define EPORT1_EPPDR_EPPD11_SHIFT                3                                                   /*!< EPORT1_EPPDR: EPPD11 Position           */
#define EPORT1_EPPDR_EPPD12_MASK                 (0x01UL << EPORT1_EPPDR_EPPD12_SHIFT)               /*!< EPORT1_EPPDR: EPPD12 Mask               */
#define EPORT1_EPPDR_EPPD12_SHIFT                4                                                   /*!< EPORT1_EPPDR: EPPD12 Position           */
#define EPORT1_EPPDR_EPPD13_MASK                 (0x01UL << EPORT1_EPPDR_EPPD13_SHIFT)               /*!< EPORT1_EPPDR: EPPD13 Mask               */
#define EPORT1_EPPDR_EPPD13_SHIFT                5                                                   /*!< EPORT1_EPPDR: EPPD13 Position           */
#define EPORT1_EPPDR_EPPD14_MASK                 (0x01UL << EPORT1_EPPDR_EPPD14_SHIFT)               /*!< EPORT1_EPPDR: EPPD14 Mask               */
#define EPORT1_EPPDR_EPPD14_SHIFT                6                                                   /*!< EPORT1_EPPDR: EPPD14 Position           */
#define EPORT1_EPPDR_EPPD15_MASK                 (0x01UL << EPORT1_EPPDR_EPPD15_SHIFT)               /*!< EPORT1_EPPDR: EPPD15 Mask               */
#define EPORT1_EPPDR_EPPD15_SHIFT                7                                                   /*!< EPORT1_EPPDR: EPPD15 Position           */
/* ------- EPFR Bit Fields                          ------ */
#define EPORT1_EPFR_EPF8_MASK                    (0x01UL << EPORT1_EPFR_EPF8_SHIFT)                  /*!< EPORT1_EPFR: EPF8 Mask                  */
#define EPORT1_EPFR_EPF8_SHIFT                   0                                                   /*!< EPORT1_EPFR: EPF8 Position              */
#define EPORT1_EPFR_EPF9_MASK                    (0x01UL << EPORT1_EPFR_EPF9_SHIFT)                  /*!< EPORT1_EPFR: EPF9 Mask                  */
#define EPORT1_EPFR_EPF9_SHIFT                   1                                                   /*!< EPORT1_EPFR: EPF9 Position              */
#define EPORT1_EPFR_EPF10_MASK                   (0x01UL << EPORT1_EPFR_EPF10_SHIFT)                 /*!< EPORT1_EPFR: EPF10 Mask                 */
#define EPORT1_EPFR_EPF10_SHIFT                  2                                                   /*!< EPORT1_EPFR: EPF10 Position             */
#define EPORT1_EPFR_EPF11_MASK                   (0x01UL << EPORT1_EPFR_EPF11_SHIFT)                 /*!< EPORT1_EPFR: EPF11 Mask                 */
#define EPORT1_EPFR_EPF11_SHIFT                  3                                                   /*!< EPORT1_EPFR: EPF11 Position             */
#define EPORT1_EPFR_EPF12_MASK                   (0x01UL << EPORT1_EPFR_EPF12_SHIFT)                 /*!< EPORT1_EPFR: EPF12 Mask                 */
#define EPORT1_EPFR_EPF12_SHIFT                  4                                                   /*!< EPORT1_EPFR: EPF12 Position             */
#define EPORT1_EPFR_EPF13_MASK                   (0x01UL << EPORT1_EPFR_EPF13_SHIFT)                 /*!< EPORT1_EPFR: EPF13 Mask                 */
#define EPORT1_EPFR_EPF13_SHIFT                  5                                                   /*!< EPORT1_EPFR: EPF13 Position             */
#define EPORT1_EPFR_EPF14_MASK                   (0x01UL << EPORT1_EPFR_EPF14_SHIFT)                 /*!< EPORT1_EPFR: EPF14 Mask                 */
#define EPORT1_EPFR_EPF14_SHIFT                  6                                                   /*!< EPORT1_EPFR: EPF14 Position             */
#define EPORT1_EPFR_EPF15_MASK                   (0x01UL << EPORT1_EPFR_EPF15_SHIFT)                 /*!< EPORT1_EPFR: EPF15 Mask                 */
#define EPORT1_EPFR_EPF15_SHIFT                  7                                                   /*!< EPORT1_EPFR: EPF15 Position             */

/* EPORT1 - Peripheral instance base addresses */
#define EPORT1_BasePtr                 0x40140000UL
#define EPORT1                         ((EPORT1_Type *) EPORT1_BasePtr)
#define EPORT1_BASE_PTR                (EPORT1)

/* ================================================================================ */
/* ================           FEC (file:MCF522xx_FEC)              ================ */
/* ================================================================================ */

/**
 * @brief None
 */
typedef struct {                                /*!<       FEC Structure                                                */
   __IO uint32_t  EIR;                          /*!< 0000: None                                                         */
   __IO uint32_t  EIMR;                         /*!< 0004: None                                                         */
   __I  uint32_t  RESERVED0;                    /*!< 0008:                                                              */
   __IO uint32_t  RDAR;                         /*!< 000C: None                                                         */
   __IO uint32_t  TDAR;                         /*!< 0010: None                                                         */
   __I  uint32_t  RESERVED1[3];                 /*!< 0014:                                                              */
   __IO uint32_t  ECR;                          /*!< 0020: None                                                         */
   __I  uint32_t  RESERVED2[6];                 /*!< 0024:                                                              */
   __IO uint32_t  MMFR;                         /*!< 003C: None                                                         */
   __IO uint32_t  MSCR;                         /*!< 0040: None                                                         */
   __I  uint32_t  RESERVED3[7];                 /*!< 0044:                                                              */
   __IO uint32_t  MIBC;                         /*!< 0060: None                                                         */
   __I  uint32_t  RESERVED4[7];                 /*!< 0064:                                                              */
   __IO uint32_t  RCR;                          /*!< 0080: None                                                         */
   __I  uint32_t  RESERVED5[15];                /*!< 0084:                                                              */
   __IO uint32_t  TCR;                          /*!< 00C0: None                                                         */
   __I  uint32_t  RESERVED6[7];                 /*!< 00C4:                                                              */
   __IO uint32_t  PALR;                         /*!< 00E0: None                                                         */
   __IO uint32_t  PAUR;                         /*!< 00E4: None                                                         */
   __IO uint32_t  OPD;                          /*!< 00E8: None                                                         */
   __I  uint32_t  RESERVED7[10];                /*!< 00EC:                                                              */
   __IO uint32_t  IAUR;                         /*!< 0114: None                                                         */
   __IO uint32_t  IALR;                         /*!< 0118: None                                                         */
   __IO uint32_t  GAUR;                         /*!< 011C: None                                                         */
   __IO uint32_t  GALR;                         /*!< 0120: None                                                         */
   __I  uint32_t  RESERVED8[7];                 /*!< 0124:                                                              */
   __IO uint32_t  TFWR;                         /*!< 0140: None                                                         */
   __I  uint32_t  RESERVED9;                    /*!< 0144:                                                              */
   __IO uint32_t  FRBR;                         /*!< 0148: None                                                         */
   __IO uint32_t  FRSR;                         /*!< 014C: None                                                         */
   __I  uint32_t  RESERVED10[11];               /*!< 0150:                                                              */
   __IO uint32_t  ERDSR;                        /*!< 017C: None                                                         */
   __IO uint32_t  ETSDR;                        /*!< 0180: None                                                         */
   __IO uint32_t  EMRBR;                        /*!< 0184: None                                                         */
   __I  uint32_t  RESERVED11[29];               /*!< 0188:                                                              */
   __IO uint32_t  RMON_T_DROP;                  /*!< 01FC: None                                                         */
   __IO uint32_t  RMON_T_PACKETS;               /*!< 0200: None                                                         */
   __IO uint32_t  RMON_T_BC_PKT;                /*!< 0204: None                                                         */
   __IO uint32_t  RMON_T_MC_PKT;                /*!< 0208: None                                                         */
   __IO uint32_t  RMON_T_CRC_ALIGN;             /*!< 020C: None                                                         */
   __IO uint32_t  RMON_T_UNDERSIZE;             /*!< 0210: None                                                         */
   __IO uint32_t  RMON_T_OVERSIZE;              /*!< 0214: None                                                         */
   __IO uint32_t  RMON_T_FRAG;                  /*!< 0218: None                                                         */
   __IO uint32_t  RMON_T_JAB;                   /*!< 021C: None                                                         */
   __IO uint32_t  RMON_T_COL;                   /*!< 0220: None                                                         */
   __IO uint32_t  RMON_T_P64;                   /*!< 0224: None                                                         */
   __IO uint32_t  RMON_T_P65TO127;              /*!< 0228: None                                                         */
   __IO uint32_t  RMON_T_P128TO255;             /*!< 022C: None                                                         */
   __IO uint32_t  RMON_T_P256TO511;             /*!< 0230: None                                                         */
   __IO uint32_t  RMON_T_P512TO1023;            /*!< 0234: None                                                         */
   __IO uint32_t  RMON_T_P1024TO2047;           /*!< 0238: None                                                         */
   __IO uint32_t  RMON_T_P_GTE2048;             /*!< 023C: None                                                         */
   __IO uint32_t  RMON_T_OCTETS;                /*!< 0240: None                                                         */
   __IO uint32_t  IEEE_T_DROP;                  /*!< 0244: None                                                         */
   __IO uint32_t  IEEE_T_FRAME_OK;              /*!< 0248: None                                                         */
   __IO uint32_t  IEEE_T_1COL;                  /*!< 024C: None                                                         */
   __IO uint32_t  IEEE_T_MCOL;                  /*!< 0250: None                                                         */
   __IO uint32_t  IEEE_T_DEF;                   /*!< 0254: None                                                         */
   __IO uint32_t  IEEE_T_LCOL;                  /*!< 0258: None                                                         */
   __IO uint32_t  IEEE_T_EXCOL;                 /*!< 025C: None                                                         */
   __IO uint32_t  IEEE_T_MACERR;                /*!< 0260: None                                                         */
   __IO uint32_t  IEEE_T_CSERR;                 /*!< 0264: None                                                         */
   __IO uint32_t  IEEE_T_SQE;                   /*!< 0268: None                                                         */
   __IO uint32_t  IEEE_T_FDXFC;                 /*!< 026C: None                                                         */
   __IO uint32_t  IEEE_T_OCTETS_OK;             /*!< 0270: None                                                         */
   __I  uint32_t  RESERVED12[2];                /*!< 0274:                                                              */
   __IO uint32_t  RMON_R_DROP;                  /*!< 027C: None                                                         */
   __IO uint32_t  RMON_R_PACKETS;               /*!< 0280: None                                                         */
   __IO uint32_t  RMON_R_BC_PKT;                /*!< 0284: None                                                         */
   __IO uint32_t  RMON_R_MC_PKT;                /*!< 0288: None                                                         */
   __IO uint32_t  RMON_R_CRC_ALIGN;             /*!< 028C: None                                                         */
   __IO uint32_t  RMON_R_UNDERSIZE;             /*!< 0290: None                                                         */
   __IO uint32_t  RMON_R_OVERSIZE;              /*!< 0294: None                                                         */
   __IO uint32_t  RMON_R_FRAG;                  /*!< 0298: None                                                         */
   __IO uint32_t  RMON_R_JAB;                   /*!< 029C: None                                                         */
   __IO uint32_t  RMON_R_RESVD_0;               /*!< 02A0: None                                                         */
   __IO uint32_t  RMON_R_P64;                   /*!< 02A4: None                                                         */
   __IO uint32_t  RMON_R_P65TO127;              /*!< 02A8: None                                                         */
   __IO uint32_t  RMON_R_P128TO255;             /*!< 02AC: None                                                         */
   __IO uint32_t  RMON_R_P256TO511;             /*!< 02B0: None                                                         */
   __IO uint32_t  RMON_R_P512TO1023;            /*!< 02B4: None                                                         */
   __IO uint32_t  RMON_R_P1024TO2047;           /*!< 02B8: None                                                         */
   __IO uint32_t  RMON_R_P_GTE2048;             /*!< 02BC: None                                                         */
   __IO uint32_t  RMON_R_OCTETS;                /*!< 02C0: None                                                         */
   __IO uint32_t  IEEE_R_DROP;                  /*!< 02C4: None                                                         */
   __IO uint32_t  IEEE_R_FRAME_OK;              /*!< 02C8: None                                                         */
   __IO uint32_t  IEEE_R_CRC;                   /*!< 02CC: None                                                         */
   __IO uint32_t  IEEE_R_ALIGN;                 /*!< 02D0: None                                                         */
   __IO uint32_t  IEEE_R_MACERR;                /*!< 02D4: None                                                         */
   __IO uint32_t  IEEE_R_FDXFC;                 /*!< 02D8: None                                                         */
   __IO uint32_t  IEEE_R_OCTETS_OK;             /*!< 02DC: None                                                         */
} FEC_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'FEC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- EIR Bit Fields                           ------ */
#define FEC_EIR_UN_MASK                          (0x01UL << FEC_EIR_UN_SHIFT)                        /*!< FEC_EIR: UN Mask                        */
#define FEC_EIR_UN_SHIFT                         19                                                  /*!< FEC_EIR: UN Position                    */
#define FEC_EIR_RL_MASK                          (0x01UL << FEC_EIR_RL_SHIFT)                        /*!< FEC_EIR: RL Mask                        */
#define FEC_EIR_RL_SHIFT                         20                                                  /*!< FEC_EIR: RL Position                    */
#define FEC_EIR_LC_MASK                          (0x01UL << FEC_EIR_LC_SHIFT)                        /*!< FEC_EIR: LC Mask                        */
#define FEC_EIR_LC_SHIFT                         21                                                  /*!< FEC_EIR: LC Position                    */
#define FEC_EIR_EBERR_MASK                       (0x01UL << FEC_EIR_EBERR_SHIFT)                     /*!< FEC_EIR: EBERR Mask                     */
#define FEC_EIR_EBERR_SHIFT                      22                                                  /*!< FEC_EIR: EBERR Position                 */
#define FEC_EIR_MII_MASK                         (0x01UL << FEC_EIR_MII_SHIFT)                       /*!< FEC_EIR: MII Mask                       */
#define FEC_EIR_MII_SHIFT                        23                                                  /*!< FEC_EIR: MII Position                   */
#define FEC_EIR_RXB_MASK                         (0x01UL << FEC_EIR_RXB_SHIFT)                       /*!< FEC_EIR: RXB Mask                       */
#define FEC_EIR_RXB_SHIFT                        24                                                  /*!< FEC_EIR: RXB Position                   */
#define FEC_EIR_RXF_MASK                         (0x01UL << FEC_EIR_RXF_SHIFT)                       /*!< FEC_EIR: RXF Mask                       */
#define FEC_EIR_RXF_SHIFT                        25                                                  /*!< FEC_EIR: RXF Position                   */
#define FEC_EIR_TXB_MASK                         (0x01UL << FEC_EIR_TXB_SHIFT)                       /*!< FEC_EIR: TXB Mask                       */
#define FEC_EIR_TXB_SHIFT                        26                                                  /*!< FEC_EIR: TXB Position                   */
#define FEC_EIR_TXF_MASK                         (0x01UL << FEC_EIR_TXF_SHIFT)                       /*!< FEC_EIR: TXF Mask                       */
#define FEC_EIR_TXF_SHIFT                        27                                                  /*!< FEC_EIR: TXF Position                   */
#define FEC_EIR_GRA_MASK                         (0x01UL << FEC_EIR_GRA_SHIFT)                       /*!< FEC_EIR: GRA Mask                       */
#define FEC_EIR_GRA_SHIFT                        28                                                  /*!< FEC_EIR: GRA Position                   */
#define FEC_EIR_BABT_MASK                        (0x01UL << FEC_EIR_BABT_SHIFT)                      /*!< FEC_EIR: BABT Mask                      */
#define FEC_EIR_BABT_SHIFT                       29                                                  /*!< FEC_EIR: BABT Position                  */
#define FEC_EIR_BABR_MASK                        (0x01UL << FEC_EIR_BABR_SHIFT)                      /*!< FEC_EIR: BABR Mask                      */
#define FEC_EIR_BABR_SHIFT                       30                                                  /*!< FEC_EIR: BABR Position                  */
#define FEC_EIR_HBERR_MASK                       (0x01UL << FEC_EIR_HBERR_SHIFT)                     /*!< FEC_EIR: HBERR Mask                     */
#define FEC_EIR_HBERR_SHIFT                      31                                                  /*!< FEC_EIR: HBERR Position                 */
/* ------- EIMR Bit Fields                          ------ */
#define FEC_EIMR_UN_MASK                         (0x01UL << FEC_EIMR_UN_SHIFT)                       /*!< FEC_EIMR: UN Mask                       */
#define FEC_EIMR_UN_SHIFT                        19                                                  /*!< FEC_EIMR: UN Position                   */
#define FEC_EIMR_RL_MASK                         (0x01UL << FEC_EIMR_RL_SHIFT)                       /*!< FEC_EIMR: RL Mask                       */
#define FEC_EIMR_RL_SHIFT                        20                                                  /*!< FEC_EIMR: RL Position                   */
#define FEC_EIMR_LC_MASK                         (0x01UL << FEC_EIMR_LC_SHIFT)                       /*!< FEC_EIMR: LC Mask                       */
#define FEC_EIMR_LC_SHIFT                        21                                                  /*!< FEC_EIMR: LC Position                   */
#define FEC_EIMR_EBERR_MASK                      (0x01UL << FEC_EIMR_EBERR_SHIFT)                    /*!< FEC_EIMR: EBERR Mask                    */
#define FEC_EIMR_EBERR_SHIFT                     22                                                  /*!< FEC_EIMR: EBERR Position                */
#define FEC_EIMR_MII_MASK                        (0x01UL << FEC_EIMR_MII_SHIFT)                      /*!< FEC_EIMR: MII Mask                      */
#define FEC_EIMR_MII_SHIFT                       23                                                  /*!< FEC_EIMR: MII Position                  */
#define FEC_EIMR_RXB_MASK                        (0x01UL << FEC_EIMR_RXB_SHIFT)                      /*!< FEC_EIMR: RXB Mask                      */
#define FEC_EIMR_RXB_SHIFT                       24                                                  /*!< FEC_EIMR: RXB Position                  */
#define FEC_EIMR_RXF_MASK                        (0x01UL << FEC_EIMR_RXF_SHIFT)                      /*!< FEC_EIMR: RXF Mask                      */
#define FEC_EIMR_RXF_SHIFT                       25                                                  /*!< FEC_EIMR: RXF Position                  */
#define FEC_EIMR_TXB_MASK                        (0x01UL << FEC_EIMR_TXB_SHIFT)                      /*!< FEC_EIMR: TXB Mask                      */
#define FEC_EIMR_TXB_SHIFT                       26                                                  /*!< FEC_EIMR: TXB Position                  */
#define FEC_EIMR_TXF_MASK                        (0x01UL << FEC_EIMR_TXF_SHIFT)                      /*!< FEC_EIMR: TXF Mask                      */
#define FEC_EIMR_TXF_SHIFT                       27                                                  /*!< FEC_EIMR: TXF Position                  */
#define FEC_EIMR_GRA_MASK                        (0x01UL << FEC_EIMR_GRA_SHIFT)                      /*!< FEC_EIMR: GRA Mask                      */
#define FEC_EIMR_GRA_SHIFT                       28                                                  /*!< FEC_EIMR: GRA Position                  */
#define FEC_EIMR_BABT_MASK                       (0x01UL << FEC_EIMR_BABT_SHIFT)                     /*!< FEC_EIMR: BABT Mask                     */
#define FEC_EIMR_BABT_SHIFT                      29                                                  /*!< FEC_EIMR: BABT Position                 */
#define FEC_EIMR_BABR_MASK                       (0x01UL << FEC_EIMR_BABR_SHIFT)                     /*!< FEC_EIMR: BABR Mask                     */
#define FEC_EIMR_BABR_SHIFT                      30                                                  /*!< FEC_EIMR: BABR Position                 */
#define FEC_EIMR_HBERR_MASK                      (0x01UL << FEC_EIMR_HBERR_SHIFT)                    /*!< FEC_EIMR: HBERR Mask                    */
#define FEC_EIMR_HBERR_SHIFT                     31                                                  /*!< FEC_EIMR: HBERR Position                */
/* ------- RDAR Bit Fields                          ------ */
#define FEC_RDAR_R_DES_ACTIVE_MASK               (0x01UL << FEC_RDAR_R_DES_ACTIVE_SHIFT)             /*!< FEC_RDAR: R_DES_ACTIVE Mask             */
#define FEC_RDAR_R_DES_ACTIVE_SHIFT              24                                                  /*!< FEC_RDAR: R_DES_ACTIVE Position         */
/* ------- TDAR Bit Fields                          ------ */
#define FEC_TDAR_X_DES_ACTIVE_MASK               (0x01UL << FEC_TDAR_X_DES_ACTIVE_SHIFT)             /*!< FEC_TDAR: X_DES_ACTIVE Mask             */
#define FEC_TDAR_X_DES_ACTIVE_SHIFT              24                                                  /*!< FEC_TDAR: X_DES_ACTIVE Position         */
/* ------- ECR Bit Fields                           ------ */
#define FEC_ECR_RESET_MASK                       (0x01UL << FEC_ECR_RESET_SHIFT)                     /*!< FEC_ECR: RESET Mask                     */
#define FEC_ECR_RESET_SHIFT                      0                                                   /*!< FEC_ECR: RESET Position                 */
#define FEC_ECR_ETHER_EN_MASK                    (0x01UL << FEC_ECR_ETHER_EN_SHIFT)                  /*!< FEC_ECR: ETHER_EN Mask                  */
#define FEC_ECR_ETHER_EN_SHIFT                   1                                                   /*!< FEC_ECR: ETHER_EN Position              */
/* ------- MMFR Bit Fields                          ------ */
#define FEC_MMFR_DATA_MASK                       (0xFFFFUL << FEC_MMFR_DATA_SHIFT)                   /*!< FEC_MMFR: DATA Mask                     */
#define FEC_MMFR_DATA_SHIFT                      0                                                   /*!< FEC_MMFR: DATA Position                 */
#define FEC_MMFR_DATA(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_DATA_SHIFT))&FEC_MMFR_DATA_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_TA_MASK                         (0x03UL << FEC_MMFR_TA_SHIFT)                       /*!< FEC_MMFR: TA Mask                       */
#define FEC_MMFR_TA_SHIFT                        16                                                  /*!< FEC_MMFR: TA Position                   */
#define FEC_MMFR_TA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_TA_SHIFT))&FEC_MMFR_TA_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_RA_MASK                         (0x1FUL << FEC_MMFR_RA_SHIFT)                       /*!< FEC_MMFR: RA Mask                       */
#define FEC_MMFR_RA_SHIFT                        18                                                  /*!< FEC_MMFR: RA Position                   */
#define FEC_MMFR_RA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_RA_SHIFT))&FEC_MMFR_RA_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_PA_MASK                         (0x1FUL << FEC_MMFR_PA_SHIFT)                       /*!< FEC_MMFR: PA Mask                       */
#define FEC_MMFR_PA_SHIFT                        23                                                  /*!< FEC_MMFR: PA Position                   */
#define FEC_MMFR_PA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_PA_SHIFT))&FEC_MMFR_PA_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_OP_MASK                         (0x03UL << FEC_MMFR_OP_SHIFT)                       /*!< FEC_MMFR: OP Mask                       */
#define FEC_MMFR_OP_SHIFT                        28                                                  /*!< FEC_MMFR: OP Position                   */
#define FEC_MMFR_OP(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_OP_SHIFT))&FEC_MMFR_OP_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_ST_MASK                         (0x03UL << FEC_MMFR_ST_SHIFT)                       /*!< FEC_MMFR: ST Mask                       */
#define FEC_MMFR_ST_SHIFT                        30                                                  /*!< FEC_MMFR: ST Position                   */
#define FEC_MMFR_ST(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_ST_SHIFT))&FEC_MMFR_ST_MASK) /*!< FEC_MMFR                                */
/* ------- MSCR Bit Fields                          ------ */
#define FEC_MSCR_MII_SPEED_MASK                  (0x3FUL << FEC_MSCR_MII_SPEED_SHIFT)                /*!< FEC_MSCR: MII_SPEED Mask                */
#define FEC_MSCR_MII_SPEED_SHIFT                 1                                                   /*!< FEC_MSCR: MII_SPEED Position            */
#define FEC_MSCR_MII_SPEED(x)                    (((uint32_t)(((uint32_t)(x))<<FEC_MSCR_MII_SPEED_SHIFT))&FEC_MSCR_MII_SPEED_MASK) /*!< FEC_MSCR                                */
#define FEC_MSCR_DIS_PREAMBLE_MASK               (0x01UL << FEC_MSCR_DIS_PREAMBLE_SHIFT)             /*!< FEC_MSCR: DIS_PREAMBLE Mask             */
#define FEC_MSCR_DIS_PREAMBLE_SHIFT              7                                                   /*!< FEC_MSCR: DIS_PREAMBLE Position         */
/* ------- MIBC Bit Fields                          ------ */
#define FEC_MIBC_MIB_IDLE_MASK                   (0x01UL << FEC_MIBC_MIB_IDLE_SHIFT)                 /*!< FEC_MIBC: MIB_IDLE Mask                 */
#define FEC_MIBC_MIB_IDLE_SHIFT                  30                                                  /*!< FEC_MIBC: MIB_IDLE Position             */
#define FEC_MIBC_MIB_DISABLE_MASK                (0x01UL << FEC_MIBC_MIB_DISABLE_SHIFT)              /*!< FEC_MIBC: MIB_DISABLE Mask              */
#define FEC_MIBC_MIB_DISABLE_SHIFT               31                                                  /*!< FEC_MIBC: MIB_DISABLE Position          */
/* ------- RCR Bit Fields                           ------ */
#define FEC_RCR_LOOP_MASK                        (0x01UL << FEC_RCR_LOOP_SHIFT)                      /*!< FEC_RCR: LOOP Mask                      */
#define FEC_RCR_LOOP_SHIFT                       0                                                   /*!< FEC_RCR: LOOP Position                  */
#define FEC_RCR_DRT_MASK                         (0x01UL << FEC_RCR_DRT_SHIFT)                       /*!< FEC_RCR: DRT Mask                       */
#define FEC_RCR_DRT_SHIFT                        1                                                   /*!< FEC_RCR: DRT Position                   */
#define FEC_RCR_MII_MODE_MASK                    (0x01UL << FEC_RCR_MII_MODE_SHIFT)                  /*!< FEC_RCR: MII_MODE Mask                  */
#define FEC_RCR_MII_MODE_SHIFT                   2                                                   /*!< FEC_RCR: MII_MODE Position              */
#define FEC_RCR_PROM_MASK                        (0x01UL << FEC_RCR_PROM_SHIFT)                      /*!< FEC_RCR: PROM Mask                      */
#define FEC_RCR_PROM_SHIFT                       3                                                   /*!< FEC_RCR: PROM Position                  */
#define FEC_RCR_BC_REJ_MASK                      (0x01UL << FEC_RCR_BC_REJ_SHIFT)                    /*!< FEC_RCR: BC_REJ Mask                    */
#define FEC_RCR_BC_REJ_SHIFT                     4                                                   /*!< FEC_RCR: BC_REJ Position                */
#define FEC_RCR_FCE_MASK                         (0x01UL << FEC_RCR_FCE_SHIFT)                       /*!< FEC_RCR: FCE Mask                       */
#define FEC_RCR_FCE_SHIFT                        5                                                   /*!< FEC_RCR: FCE Position                   */
#define FEC_RCR_MAX_FL_MASK                      (0x7FFUL << FEC_RCR_MAX_FL_SHIFT)                   /*!< FEC_RCR: MAX_FL Mask                    */
#define FEC_RCR_MAX_FL_SHIFT                     16                                                  /*!< FEC_RCR: MAX_FL Position                */
#define FEC_RCR_MAX_FL(x)                        (((uint32_t)(((uint32_t)(x))<<FEC_RCR_MAX_FL_SHIFT))&FEC_RCR_MAX_FL_MASK) /*!< FEC_RCR                                 */
/* ------- TCR Bit Fields                           ------ */
#define FEC_TCR_GTS_MASK                         (0x01UL << FEC_TCR_GTS_SHIFT)                       /*!< FEC_TCR: GTS Mask                       */
#define FEC_TCR_GTS_SHIFT                        0                                                   /*!< FEC_TCR: GTS Position                   */
#define FEC_TCR_HBC_MASK                         (0x01UL << FEC_TCR_HBC_SHIFT)                       /*!< FEC_TCR: HBC Mask                       */
#define FEC_TCR_HBC_SHIFT                        1                                                   /*!< FEC_TCR: HBC Position                   */
#define FEC_TCR_FDEN_MASK                        (0x01UL << FEC_TCR_FDEN_SHIFT)                      /*!< FEC_TCR: FDEN Mask                      */
#define FEC_TCR_FDEN_SHIFT                       2                                                   /*!< FEC_TCR: FDEN Position                  */
#define FEC_TCR_TFC_PAUSE_MASK                   (0x01UL << FEC_TCR_TFC_PAUSE_SHIFT)                 /*!< FEC_TCR: TFC_PAUSE Mask                 */
#define FEC_TCR_TFC_PAUSE_SHIFT                  3                                                   /*!< FEC_TCR: TFC_PAUSE Position             */
#define FEC_TCR_RFC_PAUSE_MASK                   (0x01UL << FEC_TCR_RFC_PAUSE_SHIFT)                 /*!< FEC_TCR: RFC_PAUSE Mask                 */
#define FEC_TCR_RFC_PAUSE_SHIFT                  4                                                   /*!< FEC_TCR: RFC_PAUSE Position             */
/* ------- PALR Bit Fields                          ------ */
#define FEC_PALR_PADDR1_MASK                     (0xFFFFFFFFUL << FEC_PALR_PADDR1_SHIFT)             /*!< FEC_PALR: PADDR1 Mask                   */
#define FEC_PALR_PADDR1_SHIFT                    0                                                   /*!< FEC_PALR: PADDR1 Position               */
#define FEC_PALR_PADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_PALR_PADDR1_SHIFT))&FEC_PALR_PADDR1_MASK) /*!< FEC_PALR                                */
/* ------- PAUR Bit Fields                          ------ */
#define FEC_PAUR_TYPE_MASK                       (0xFFFFUL << FEC_PAUR_TYPE_SHIFT)                   /*!< FEC_PAUR: TYPE Mask                     */
#define FEC_PAUR_TYPE_SHIFT                      0                                                   /*!< FEC_PAUR: TYPE Position                 */
#define FEC_PAUR_TYPE(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_PAUR_TYPE_SHIFT))&FEC_PAUR_TYPE_MASK) /*!< FEC_PAUR                                */
#define FEC_PAUR_PADDR2_MASK                     (0xFFFFUL << FEC_PAUR_PADDR2_SHIFT)                 /*!< FEC_PAUR: PADDR2 Mask                   */
#define FEC_PAUR_PADDR2_SHIFT                    16                                                  /*!< FEC_PAUR: PADDR2 Position               */
#define FEC_PAUR_PADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_PAUR_PADDR2_SHIFT))&FEC_PAUR_PADDR2_MASK) /*!< FEC_PAUR                                */
/* ------- OPD Bit Fields                           ------ */
#define FEC_OPD_PAUSE_DUR_MASK                   (0xFFFFUL << FEC_OPD_PAUSE_DUR_SHIFT)               /*!< FEC_OPD: PAUSE_DUR Mask                 */
#define FEC_OPD_PAUSE_DUR_SHIFT                  0                                                   /*!< FEC_OPD: PAUSE_DUR Position             */
#define FEC_OPD_PAUSE_DUR(x)                     (((uint32_t)(((uint32_t)(x))<<FEC_OPD_PAUSE_DUR_SHIFT))&FEC_OPD_PAUSE_DUR_MASK) /*!< FEC_OPD                                 */
#define FEC_OPD_OPCODE_MASK                      (0xFFFFUL << FEC_OPD_OPCODE_SHIFT)                  /*!< FEC_OPD: OPCODE Mask                    */
#define FEC_OPD_OPCODE_SHIFT                     16                                                  /*!< FEC_OPD: OPCODE Position                */
#define FEC_OPD_OPCODE(x)                        (((uint32_t)(((uint32_t)(x))<<FEC_OPD_OPCODE_SHIFT))&FEC_OPD_OPCODE_MASK) /*!< FEC_OPD                                 */
/* ------- IAUR Bit Fields                          ------ */
#define FEC_IAUR_IADDR1_MASK                     (0xFFFFFFFFUL << FEC_IAUR_IADDR1_SHIFT)             /*!< FEC_IAUR: IADDR1 Mask                   */
#define FEC_IAUR_IADDR1_SHIFT                    0                                                   /*!< FEC_IAUR: IADDR1 Position               */
#define FEC_IAUR_IADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_IAUR_IADDR1_SHIFT))&FEC_IAUR_IADDR1_MASK) /*!< FEC_IAUR                                */
/* ------- IALR Bit Fields                          ------ */
#define FEC_IALR_IADDR2_MASK                     (0xFFFFFFFFUL << FEC_IALR_IADDR2_SHIFT)             /*!< FEC_IALR: IADDR2 Mask                   */
#define FEC_IALR_IADDR2_SHIFT                    0                                                   /*!< FEC_IALR: IADDR2 Position               */
#define FEC_IALR_IADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_IALR_IADDR2_SHIFT))&FEC_IALR_IADDR2_MASK) /*!< FEC_IALR                                */
/* ------- GAUR Bit Fields                          ------ */
#define FEC_GAUR_GADDR1_MASK                     (0xFFFFFFFFUL << FEC_GAUR_GADDR1_SHIFT)             /*!< FEC_GAUR: GADDR1 Mask                   */
#define FEC_GAUR_GADDR1_SHIFT                    0                                                   /*!< FEC_GAUR: GADDR1 Position               */
#define FEC_GAUR_GADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_GAUR_GADDR1_SHIFT))&FEC_GAUR_GADDR1_MASK) /*!< FEC_GAUR                                */
/* ------- GALR Bit Fields                          ------ */
#define FEC_GALR_GADDR2_MASK                     (0xFFFFFFFFUL << FEC_GALR_GADDR2_SHIFT)             /*!< FEC_GALR: GADDR2 Mask                   */
#define FEC_GALR_GADDR2_SHIFT                    0                                                   /*!< FEC_GALR: GADDR2 Position               */
#define FEC_GALR_GADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_GALR_GADDR2_SHIFT))&FEC_GALR_GADDR2_MASK) /*!< FEC_GALR                                */
/* ------- TFWR Bit Fields                          ------ */
#define FEC_TFWR_X_WMRK_MASK                     (0x03UL << FEC_TFWR_X_WMRK_SHIFT)                   /*!< FEC_TFWR: X_WMRK Mask                   */
#define FEC_TFWR_X_WMRK_SHIFT                    0                                                   /*!< FEC_TFWR: X_WMRK Position               */
#define FEC_TFWR_X_WMRK(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_TFWR_X_WMRK_SHIFT))&FEC_TFWR_X_WMRK_MASK) /*!< FEC_TFWR                                */
/* ------- FRBR Bit Fields                          ------ */
#define FEC_FRBR_R_BOUND_MASK                    (0xFFUL << FEC_FRBR_R_BOUND_SHIFT)                  /*!< FEC_FRBR: R_BOUND Mask                  */
#define FEC_FRBR_R_BOUND_SHIFT                   2                                                   /*!< FEC_FRBR: R_BOUND Position              */
#define FEC_FRBR_R_BOUND(x)                      (((uint32_t)(((uint32_t)(x))<<FEC_FRBR_R_BOUND_SHIFT))&FEC_FRBR_R_BOUND_MASK) /*!< FEC_FRBR                                */
/* ------- FRSR Bit Fields                          ------ */
#define FEC_FRSR_R_FSTART_MASK                   (0xFFUL << FEC_FRSR_R_FSTART_SHIFT)                 /*!< FEC_FRSR: R_FSTART Mask                 */
#define FEC_FRSR_R_FSTART_SHIFT                  2                                                   /*!< FEC_FRSR: R_FSTART Position             */
#define FEC_FRSR_R_FSTART(x)                     (((uint32_t)(((uint32_t)(x))<<FEC_FRSR_R_FSTART_SHIFT))&FEC_FRSR_R_FSTART_MASK) /*!< FEC_FRSR                                */
/* ------- ERDSR Bit Fields                         ------ */
#define FEC_ERDSR_R_DES_START_MASK               (0x3FFFFFFFUL << FEC_ERDSR_R_DES_START_SHIFT)       /*!< FEC_ERDSR: R_DES_START Mask             */
#define FEC_ERDSR_R_DES_START_SHIFT              2                                                   /*!< FEC_ERDSR: R_DES_START Position         */
#define FEC_ERDSR_R_DES_START(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_ERDSR_R_DES_START_SHIFT))&FEC_ERDSR_R_DES_START_MASK) /*!< FEC_ERDSR                               */
/* ------- ETSDR Bit Fields                         ------ */
#define FEC_ETSDR_X_DES_START_MASK               (0x3FFFFFFFUL << FEC_ETSDR_X_DES_START_SHIFT)       /*!< FEC_ETSDR: X_DES_START Mask             */
#define FEC_ETSDR_X_DES_START_SHIFT              2                                                   /*!< FEC_ETSDR: X_DES_START Position         */
#define FEC_ETSDR_X_DES_START(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_ETSDR_X_DES_START_SHIFT))&FEC_ETSDR_X_DES_START_MASK) /*!< FEC_ETSDR                               */
/* ------- EMRBR Bit Fields                         ------ */
#define FEC_EMRBR_R_BUF_SIZE_MASK                (0x7FUL << FEC_EMRBR_R_BUF_SIZE_SHIFT)              /*!< FEC_EMRBR: R_BUF_SIZE Mask              */
#define FEC_EMRBR_R_BUF_SIZE_SHIFT               4                                                   /*!< FEC_EMRBR: R_BUF_SIZE Position          */
#define FEC_EMRBR_R_BUF_SIZE(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_EMRBR_R_BUF_SIZE_SHIFT))&FEC_EMRBR_R_BUF_SIZE_MASK) /*!< FEC_EMRBR                               */
/* ------- RMON_T_DROP Bit Fields                   ------ */
#define FEC_RMON_T_DROP_Value_MASK               (0xFFFFFFFFUL << FEC_RMON_T_DROP_Value_SHIFT)       /*!< FEC_RMON_T_DROP: Value Mask             */
#define FEC_RMON_T_DROP_Value_SHIFT              0                                                   /*!< FEC_RMON_T_DROP: Value Position         */
#define FEC_RMON_T_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_DROP_Value_SHIFT))&FEC_RMON_T_DROP_Value_MASK) /*!< FEC_RMON_T_DROP                         */
/* ------- RMON_T_PACKETS Bit Fields                ------ */
#define FEC_RMON_T_PACKETS_Value_MASK            (0xFFFFFFFFUL << FEC_RMON_T_PACKETS_Value_SHIFT)    /*!< FEC_RMON_T_PACKETS: Value Mask          */
#define FEC_RMON_T_PACKETS_Value_SHIFT           0                                                   /*!< FEC_RMON_T_PACKETS: Value Position      */
#define FEC_RMON_T_PACKETS_Value(x)              (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_PACKETS_Value_SHIFT))&FEC_RMON_T_PACKETS_Value_MASK) /*!< FEC_RMON_T_PACKETS                      */
/* ------- RMON_T_BC_PKT Bit Fields                 ------ */
#define FEC_RMON_T_BC_PKT_Value_MASK             (0xFFFFFFFFUL << FEC_RMON_T_BC_PKT_Value_SHIFT)     /*!< FEC_RMON_T_BC_PKT: Value Mask           */
#define FEC_RMON_T_BC_PKT_Value_SHIFT            0                                                   /*!< FEC_RMON_T_BC_PKT: Value Position       */
#define FEC_RMON_T_BC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_BC_PKT_Value_SHIFT))&FEC_RMON_T_BC_PKT_Value_MASK) /*!< FEC_RMON_T_BC_PKT                       */
/* ------- RMON_T_MC_PKT Bit Fields                 ------ */
#define FEC_RMON_T_MC_PKT_Value_MASK             (0xFFFFFFFFUL << FEC_RMON_T_MC_PKT_Value_SHIFT)     /*!< FEC_RMON_T_MC_PKT: Value Mask           */
#define FEC_RMON_T_MC_PKT_Value_SHIFT            0                                                   /*!< FEC_RMON_T_MC_PKT: Value Position       */
#define FEC_RMON_T_MC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_MC_PKT_Value_SHIFT))&FEC_RMON_T_MC_PKT_Value_MASK) /*!< FEC_RMON_T_MC_PKT                       */
/* ------- RMON_T_CRC_ALIGN Bit Fields              ------ */
#define FEC_RMON_T_CRC_ALIGN_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_T_CRC_ALIGN_Value_SHIFT)  /*!< FEC_RMON_T_CRC_ALIGN: Value Mask        */
#define FEC_RMON_T_CRC_ALIGN_Value_SHIFT         0                                                   /*!< FEC_RMON_T_CRC_ALIGN: Value Position    */
#define FEC_RMON_T_CRC_ALIGN_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_CRC_ALIGN_Value_SHIFT))&FEC_RMON_T_CRC_ALIGN_Value_MASK) /*!< FEC_RMON_T_CRC_ALIGN                    */
/* ------- RMON_T_UNDERSIZE Bit Fields              ------ */
#define FEC_RMON_T_UNDERSIZE_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_T_UNDERSIZE_Value_SHIFT)  /*!< FEC_RMON_T_UNDERSIZE: Value Mask        */
#define FEC_RMON_T_UNDERSIZE_Value_SHIFT         0                                                   /*!< FEC_RMON_T_UNDERSIZE: Value Position    */
#define FEC_RMON_T_UNDERSIZE_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_UNDERSIZE_Value_SHIFT))&FEC_RMON_T_UNDERSIZE_Value_MASK) /*!< FEC_RMON_T_UNDERSIZE                    */
/* ------- RMON_T_OVERSIZE Bit Fields               ------ */
#define FEC_RMON_T_OVERSIZE_Value_MASK           (0xFFFFFFFFUL << FEC_RMON_T_OVERSIZE_Value_SHIFT)   /*!< FEC_RMON_T_OVERSIZE: Value Mask         */
#define FEC_RMON_T_OVERSIZE_Value_SHIFT          0                                                   /*!< FEC_RMON_T_OVERSIZE: Value Position     */
#define FEC_RMON_T_OVERSIZE_Value(x)             (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_OVERSIZE_Value_SHIFT))&FEC_RMON_T_OVERSIZE_Value_MASK) /*!< FEC_RMON_T_OVERSIZE                     */
/* ------- RMON_T_FRAG Bit Fields                   ------ */
#define FEC_RMON_T_FRAG_Value_MASK               (0xFFFFFFFFUL << FEC_RMON_T_FRAG_Value_SHIFT)       /*!< FEC_RMON_T_FRAG: Value Mask             */
#define FEC_RMON_T_FRAG_Value_SHIFT              0                                                   /*!< FEC_RMON_T_FRAG: Value Position         */
#define FEC_RMON_T_FRAG_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_FRAG_Value_SHIFT))&FEC_RMON_T_FRAG_Value_MASK) /*!< FEC_RMON_T_FRAG                         */
/* ------- RMON_T_JAB Bit Fields                    ------ */
#define FEC_RMON_T_JAB_Value_MASK                (0xFFFFFFFFUL << FEC_RMON_T_JAB_Value_SHIFT)        /*!< FEC_RMON_T_JAB: Value Mask              */
#define FEC_RMON_T_JAB_Value_SHIFT               0                                                   /*!< FEC_RMON_T_JAB: Value Position          */
#define FEC_RMON_T_JAB_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_JAB_Value_SHIFT))&FEC_RMON_T_JAB_Value_MASK) /*!< FEC_RMON_T_JAB                          */
/* ------- RMON_T_COL Bit Fields                    ------ */
#define FEC_RMON_T_COL_Value_MASK                (0xFFFFFFFFUL << FEC_RMON_T_COL_Value_SHIFT)        /*!< FEC_RMON_T_COL: Value Mask              */
#define FEC_RMON_T_COL_Value_SHIFT               0                                                   /*!< FEC_RMON_T_COL: Value Position          */
#define FEC_RMON_T_COL_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_COL_Value_SHIFT))&FEC_RMON_T_COL_Value_MASK) /*!< FEC_RMON_T_COL                          */
/* ------- RMON_T_P6 Bit Fields                     ------ */
#define FEC_RMON_T_P6_Value_MASK                 (0xFFFFFFFFUL << FEC_RMON_T_P6_Value_SHIFT)         /*!< FEC_RMON_T_P6: Value Mask               */
#define FEC_RMON_T_P6_Value_SHIFT                0                                                   /*!< FEC_RMON_T_P6: Value Position           */
#define FEC_RMON_T_P6_Value(x)                   (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P6_Value_SHIFT))&FEC_RMON_T_P6_Value_MASK) /*!< FEC_RMON_T_P6                           */
/* ------- RMON_T_P128TO255 Bit Fields              ------ */
#define FEC_RMON_T_P128TO255_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_T_P128TO255_Value_SHIFT)  /*!< FEC_RMON_T_P128TO255: Value Mask        */
#define FEC_RMON_T_P128TO255_Value_SHIFT         0                                                   /*!< FEC_RMON_T_P128TO255: Value Position    */
#define FEC_RMON_T_P128TO255_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P128TO255_Value_SHIFT))&FEC_RMON_T_P128TO255_Value_MASK) /*!< FEC_RMON_T_P128TO255                    */
/* ------- RMON_T_P256TO511 Bit Fields              ------ */
#define FEC_RMON_T_P256TO511_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_T_P256TO511_Value_SHIFT)  /*!< FEC_RMON_T_P256TO511: Value Mask        */
#define FEC_RMON_T_P256TO511_Value_SHIFT         0                                                   /*!< FEC_RMON_T_P256TO511: Value Position    */
#define FEC_RMON_T_P256TO511_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P256TO511_Value_SHIFT))&FEC_RMON_T_P256TO511_Value_MASK) /*!< FEC_RMON_T_P256TO511                    */
/* ------- RMON_T_P512TO1023 Bit Fields             ------ */
#define FEC_RMON_T_P512TO1023_Value_MASK         (0xFFFFFFFFUL << FEC_RMON_T_P512TO1023_Value_SHIFT) /*!< FEC_RMON_T_P512TO1023: Value Mask       */
#define FEC_RMON_T_P512TO1023_Value_SHIFT        0                                                   /*!< FEC_RMON_T_P512TO1023: Value Position   */
#define FEC_RMON_T_P512TO1023_Value(x)           (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P512TO1023_Value_SHIFT))&FEC_RMON_T_P512TO1023_Value_MASK) /*!< FEC_RMON_T_P512TO1023                   */
/* ------- RMON_T_P1024TO2047 Bit Fields            ------ */
#define FEC_RMON_T_P1024TO2047_Value_MASK        (0xFFFFFFFFUL << FEC_RMON_T_P1024TO2047_Value_SHIFT) /*!< FEC_RMON_T_P1024TO2047: Value Mask      */
#define FEC_RMON_T_P1024TO2047_Value_SHIFT       0                                                   /*!< FEC_RMON_T_P1024TO2047: Value Position  */
#define FEC_RMON_T_P1024TO2047_Value(x)          (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P1024TO2047_Value_SHIFT))&FEC_RMON_T_P1024TO2047_Value_MASK) /*!< FEC_RMON_T_P1024TO2047                  */
/* ------- RMON_T_P_GTE2048 Bit Fields              ------ */
#define FEC_RMON_T_P_GTE2048_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_T_P_GTE2048_Value_SHIFT)  /*!< FEC_RMON_T_P_GTE2048: Value Mask        */
#define FEC_RMON_T_P_GTE2048_Value_SHIFT         0                                                   /*!< FEC_RMON_T_P_GTE2048: Value Position    */
#define FEC_RMON_T_P_GTE2048_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P_GTE2048_Value_SHIFT))&FEC_RMON_T_P_GTE2048_Value_MASK) /*!< FEC_RMON_T_P_GTE2048                    */
/* ------- RMON_T_OCTETS Bit Fields                 ------ */
#define FEC_RMON_T_OCTETS_Value_MASK             (0xFFFFFFFFUL << FEC_RMON_T_OCTETS_Value_SHIFT)     /*!< FEC_RMON_T_OCTETS: Value Mask           */
#define FEC_RMON_T_OCTETS_Value_SHIFT            0                                                   /*!< FEC_RMON_T_OCTETS: Value Position       */
#define FEC_RMON_T_OCTETS_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_OCTETS_Value_SHIFT))&FEC_RMON_T_OCTETS_Value_MASK) /*!< FEC_RMON_T_OCTETS                       */
/* ------- IEEE_T_DROP Bit Fields                   ------ */
#define FEC_IEEE_T_DROP_Value_MASK               (0xFFFFFFFFUL << FEC_IEEE_T_DROP_Value_SHIFT)       /*!< FEC_IEEE_T_DROP: Value Mask             */
#define FEC_IEEE_T_DROP_Value_SHIFT              0                                                   /*!< FEC_IEEE_T_DROP: Value Position         */
#define FEC_IEEE_T_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_DROP_Value_SHIFT))&FEC_IEEE_T_DROP_Value_MASK) /*!< FEC_IEEE_T_DROP                         */
/* ------- IEEE_T_FRAME_OK Bit Fields               ------ */
#define FEC_IEEE_T_FRAME_OK_Value_MASK           (0xFFFFFFFFUL << FEC_IEEE_T_FRAME_OK_Value_SHIFT)   /*!< FEC_IEEE_T_FRAME_OK: Value Mask         */
#define FEC_IEEE_T_FRAME_OK_Value_SHIFT          0                                                   /*!< FEC_IEEE_T_FRAME_OK: Value Position     */
#define FEC_IEEE_T_FRAME_OK_Value(x)             (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_FRAME_OK_Value_SHIFT))&FEC_IEEE_T_FRAME_OK_Value_MASK) /*!< FEC_IEEE_T_FRAME_OK                     */
/* ------- IEEE_T_1COL Bit Fields                   ------ */
#define FEC_IEEE_T_1COL_Value_MASK               (0xFFFFFFFFUL << FEC_IEEE_T_1COL_Value_SHIFT)       /*!< FEC_IEEE_T_1COL: Value Mask             */
#define FEC_IEEE_T_1COL_Value_SHIFT              0                                                   /*!< FEC_IEEE_T_1COL: Value Position         */
#define FEC_IEEE_T_1COL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_1COL_Value_SHIFT))&FEC_IEEE_T_1COL_Value_MASK) /*!< FEC_IEEE_T_1COL                         */
/* ------- IEEE_T_MCOL Bit Fields                   ------ */
#define FEC_IEEE_T_MCOL_Value_MASK               (0xFFFFFFFFUL << FEC_IEEE_T_MCOL_Value_SHIFT)       /*!< FEC_IEEE_T_MCOL: Value Mask             */
#define FEC_IEEE_T_MCOL_Value_SHIFT              0                                                   /*!< FEC_IEEE_T_MCOL: Value Position         */
#define FEC_IEEE_T_MCOL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_MCOL_Value_SHIFT))&FEC_IEEE_T_MCOL_Value_MASK) /*!< FEC_IEEE_T_MCOL                         */
/* ------- IEEE_T_DEF Bit Fields                    ------ */
#define FEC_IEEE_T_DEF_Value_MASK                (0xFFFFFFFFUL << FEC_IEEE_T_DEF_Value_SHIFT)        /*!< FEC_IEEE_T_DEF: Value Mask              */
#define FEC_IEEE_T_DEF_Value_SHIFT               0                                                   /*!< FEC_IEEE_T_DEF: Value Position          */
#define FEC_IEEE_T_DEF_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_DEF_Value_SHIFT))&FEC_IEEE_T_DEF_Value_MASK) /*!< FEC_IEEE_T_DEF                          */
/* ------- IEEE_T_LCOL Bit Fields                   ------ */
#define FEC_IEEE_T_LCOL_Value_MASK               (0xFFFFFFFFUL << FEC_IEEE_T_LCOL_Value_SHIFT)       /*!< FEC_IEEE_T_LCOL: Value Mask             */
#define FEC_IEEE_T_LCOL_Value_SHIFT              0                                                   /*!< FEC_IEEE_T_LCOL: Value Position         */
#define FEC_IEEE_T_LCOL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_LCOL_Value_SHIFT))&FEC_IEEE_T_LCOL_Value_MASK) /*!< FEC_IEEE_T_LCOL                         */
/* ------- IEEE_T_EXCOL Bit Fields                  ------ */
#define FEC_IEEE_T_EXCOL_Value_MASK              (0xFFFFFFFFUL << FEC_IEEE_T_EXCOL_Value_SHIFT)      /*!< FEC_IEEE_T_EXCOL: Value Mask            */
#define FEC_IEEE_T_EXCOL_Value_SHIFT             0                                                   /*!< FEC_IEEE_T_EXCOL: Value Position        */
#define FEC_IEEE_T_EXCOL_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_EXCOL_Value_SHIFT))&FEC_IEEE_T_EXCOL_Value_MASK) /*!< FEC_IEEE_T_EXCOL                        */
/* ------- IEEE_T_MACERR Bit Fields                 ------ */
#define FEC_IEEE_T_MACERR_Value_MASK             (0xFFFFFFFFUL << FEC_IEEE_T_MACERR_Value_SHIFT)     /*!< FEC_IEEE_T_MACERR: Value Mask           */
#define FEC_IEEE_T_MACERR_Value_SHIFT            0                                                   /*!< FEC_IEEE_T_MACERR: Value Position       */
#define FEC_IEEE_T_MACERR_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_MACERR_Value_SHIFT))&FEC_IEEE_T_MACERR_Value_MASK) /*!< FEC_IEEE_T_MACERR                       */
/* ------- IEEE_T_CSERR Bit Fields                  ------ */
#define FEC_IEEE_T_CSERR_Value_MASK              (0xFFFFFFFFUL << FEC_IEEE_T_CSERR_Value_SHIFT)      /*!< FEC_IEEE_T_CSERR: Value Mask            */
#define FEC_IEEE_T_CSERR_Value_SHIFT             0                                                   /*!< FEC_IEEE_T_CSERR: Value Position        */
#define FEC_IEEE_T_CSERR_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_CSERR_Value_SHIFT))&FEC_IEEE_T_CSERR_Value_MASK) /*!< FEC_IEEE_T_CSERR                        */
/* ------- IEEE_T_SQE Bit Fields                    ------ */
#define FEC_IEEE_T_SQE_Value_MASK                (0xFFFFFFFFUL << FEC_IEEE_T_SQE_Value_SHIFT)        /*!< FEC_IEEE_T_SQE: Value Mask              */
#define FEC_IEEE_T_SQE_Value_SHIFT               0                                                   /*!< FEC_IEEE_T_SQE: Value Position          */
#define FEC_IEEE_T_SQE_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_SQE_Value_SHIFT))&FEC_IEEE_T_SQE_Value_MASK) /*!< FEC_IEEE_T_SQE                          */
/* ------- IEEE_T_FDXFC Bit Fields                  ------ */
#define FEC_IEEE_T_FDXFC_Value_MASK              (0xFFFFFFFFUL << FEC_IEEE_T_FDXFC_Value_SHIFT)      /*!< FEC_IEEE_T_FDXFC: Value Mask            */
#define FEC_IEEE_T_FDXFC_Value_SHIFT             0                                                   /*!< FEC_IEEE_T_FDXFC: Value Position        */
#define FEC_IEEE_T_FDXFC_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_FDXFC_Value_SHIFT))&FEC_IEEE_T_FDXFC_Value_MASK) /*!< FEC_IEEE_T_FDXFC                        */
/* ------- IEEE_T_OCTETS_OK Bit Fields              ------ */
#define FEC_IEEE_T_OCTETS_OK_Value_MASK          (0xFFFFFFFFUL << FEC_IEEE_T_OCTETS_OK_Value_SHIFT)  /*!< FEC_IEEE_T_OCTETS_OK: Value Mask        */
#define FEC_IEEE_T_OCTETS_OK_Value_SHIFT         0                                                   /*!< FEC_IEEE_T_OCTETS_OK: Value Position    */
#define FEC_IEEE_T_OCTETS_OK_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_OCTETS_OK_Value_SHIFT))&FEC_IEEE_T_OCTETS_OK_Value_MASK) /*!< FEC_IEEE_T_OCTETS_OK                    */
/* ------- RMON_R_DROP Bit Fields                   ------ */
#define FEC_RMON_R_DROP_Value_MASK               (0xFFFFFFFFUL << FEC_RMON_R_DROP_Value_SHIFT)       /*!< FEC_RMON_R_DROP: Value Mask             */
#define FEC_RMON_R_DROP_Value_SHIFT              0                                                   /*!< FEC_RMON_R_DROP: Value Position         */
#define FEC_RMON_R_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_DROP_Value_SHIFT))&FEC_RMON_R_DROP_Value_MASK) /*!< FEC_RMON_R_DROP                         */
/* ------- RMON_R_PACKETS Bit Fields                ------ */
#define FEC_RMON_R_PACKETS_Value_MASK            (0xFFFFFFFFUL << FEC_RMON_R_PACKETS_Value_SHIFT)    /*!< FEC_RMON_R_PACKETS: Value Mask          */
#define FEC_RMON_R_PACKETS_Value_SHIFT           0                                                   /*!< FEC_RMON_R_PACKETS: Value Position      */
#define FEC_RMON_R_PACKETS_Value(x)              (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_PACKETS_Value_SHIFT))&FEC_RMON_R_PACKETS_Value_MASK) /*!< FEC_RMON_R_PACKETS                      */
/* ------- RMON_R_BC_PKT Bit Fields                 ------ */
#define FEC_RMON_R_BC_PKT_Value_MASK             (0xFFFFFFFFUL << FEC_RMON_R_BC_PKT_Value_SHIFT)     /*!< FEC_RMON_R_BC_PKT: Value Mask           */
#define FEC_RMON_R_BC_PKT_Value_SHIFT            0                                                   /*!< FEC_RMON_R_BC_PKT: Value Position       */
#define FEC_RMON_R_BC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_BC_PKT_Value_SHIFT))&FEC_RMON_R_BC_PKT_Value_MASK) /*!< FEC_RMON_R_BC_PKT                       */
/* ------- RMON_R_MC_PKT Bit Fields                 ------ */
#define FEC_RMON_R_MC_PKT_Value_MASK             (0xFFFFFFFFUL << FEC_RMON_R_MC_PKT_Value_SHIFT)     /*!< FEC_RMON_R_MC_PKT: Value Mask           */
#define FEC_RMON_R_MC_PKT_Value_SHIFT            0                                                   /*!< FEC_RMON_R_MC_PKT: Value Position       */
#define FEC_RMON_R_MC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_MC_PKT_Value_SHIFT))&FEC_RMON_R_MC_PKT_Value_MASK) /*!< FEC_RMON_R_MC_PKT                       */
/* ------- RMON_R_CRC_ALIGN Bit Fields              ------ */
#define FEC_RMON_R_CRC_ALIGN_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_R_CRC_ALIGN_Value_SHIFT)  /*!< FEC_RMON_R_CRC_ALIGN: Value Mask        */
#define FEC_RMON_R_CRC_ALIGN_Value_SHIFT         0                                                   /*!< FEC_RMON_R_CRC_ALIGN: Value Position    */
#define FEC_RMON_R_CRC_ALIGN_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_CRC_ALIGN_Value_SHIFT))&FEC_RMON_R_CRC_ALIGN_Value_MASK) /*!< FEC_RMON_R_CRC_ALIGN                    */
/* ------- RMON_R_UNDERSIZE Bit Fields              ------ */
#define FEC_RMON_R_UNDERSIZE_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_R_UNDERSIZE_Value_SHIFT)  /*!< FEC_RMON_R_UNDERSIZE: Value Mask        */
#define FEC_RMON_R_UNDERSIZE_Value_SHIFT         0                                                   /*!< FEC_RMON_R_UNDERSIZE: Value Position    */
#define FEC_RMON_R_UNDERSIZE_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_UNDERSIZE_Value_SHIFT))&FEC_RMON_R_UNDERSIZE_Value_MASK) /*!< FEC_RMON_R_UNDERSIZE                    */
/* ------- RMON_R_OVERSIZE Bit Fields               ------ */
#define FEC_RMON_R_OVERSIZE_Value_MASK           (0xFFFFFFFFUL << FEC_RMON_R_OVERSIZE_Value_SHIFT)   /*!< FEC_RMON_R_OVERSIZE: Value Mask         */
#define FEC_RMON_R_OVERSIZE_Value_SHIFT          0                                                   /*!< FEC_RMON_R_OVERSIZE: Value Position     */
#define FEC_RMON_R_OVERSIZE_Value(x)             (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_OVERSIZE_Value_SHIFT))&FEC_RMON_R_OVERSIZE_Value_MASK) /*!< FEC_RMON_R_OVERSIZE                     */
/* ------- RMON_R_FRAG Bit Fields                   ------ */
#define FEC_RMON_R_FRAG_Value_MASK               (0xFFFFFFFFUL << FEC_RMON_R_FRAG_Value_SHIFT)       /*!< FEC_RMON_R_FRAG: Value Mask             */
#define FEC_RMON_R_FRAG_Value_SHIFT              0                                                   /*!< FEC_RMON_R_FRAG: Value Position         */
#define FEC_RMON_R_FRAG_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_FRAG_Value_SHIFT))&FEC_RMON_R_FRAG_Value_MASK) /*!< FEC_RMON_R_FRAG                         */
/* ------- RMON_R_JAB Bit Fields                    ------ */
#define FEC_RMON_R_JAB_Value_MASK                (0xFFFFFFFFUL << FEC_RMON_R_JAB_Value_SHIFT)        /*!< FEC_RMON_R_JAB: Value Mask              */
#define FEC_RMON_R_JAB_Value_SHIFT               0                                                   /*!< FEC_RMON_R_JAB: Value Position          */
#define FEC_RMON_R_JAB_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_JAB_Value_SHIFT))&FEC_RMON_R_JAB_Value_MASK) /*!< FEC_RMON_R_JAB                          */
/* ------- RMON_R_RESVD_0 Bit Fields                ------ */
#define FEC_RMON_R_RESVD_0_Value_MASK            (0xFFFFFFFFUL << FEC_RMON_R_RESVD_0_Value_SHIFT)    /*!< FEC_RMON_R_RESVD_0: Value Mask          */
#define FEC_RMON_R_RESVD_0_Value_SHIFT           0                                                   /*!< FEC_RMON_R_RESVD_0: Value Position      */
#define FEC_RMON_R_RESVD_0_Value(x)              (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_RESVD_0_Value_SHIFT))&FEC_RMON_R_RESVD_0_Value_MASK) /*!< FEC_RMON_R_RESVD_0                      */
/* ------- RMON_R_P6 Bit Fields                     ------ */
#define FEC_RMON_R_P6_Value_MASK                 (0xFFFFFFFFUL << FEC_RMON_R_P6_Value_SHIFT)         /*!< FEC_RMON_R_P6: Value Mask               */
#define FEC_RMON_R_P6_Value_SHIFT                0                                                   /*!< FEC_RMON_R_P6: Value Position           */
#define FEC_RMON_R_P6_Value(x)                   (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P6_Value_SHIFT))&FEC_RMON_R_P6_Value_MASK) /*!< FEC_RMON_R_P6                           */
/* ------- RMON_R_P128TO255 Bit Fields              ------ */
#define FEC_RMON_R_P128TO255_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_R_P128TO255_Value_SHIFT)  /*!< FEC_RMON_R_P128TO255: Value Mask        */
#define FEC_RMON_R_P128TO255_Value_SHIFT         0                                                   /*!< FEC_RMON_R_P128TO255: Value Position    */
#define FEC_RMON_R_P128TO255_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P128TO255_Value_SHIFT))&FEC_RMON_R_P128TO255_Value_MASK) /*!< FEC_RMON_R_P128TO255                    */
/* ------- RMON_R_P256TO511 Bit Fields              ------ */
#define FEC_RMON_R_P256TO511_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_R_P256TO511_Value_SHIFT)  /*!< FEC_RMON_R_P256TO511: Value Mask        */
#define FEC_RMON_R_P256TO511_Value_SHIFT         0                                                   /*!< FEC_RMON_R_P256TO511: Value Position    */
#define FEC_RMON_R_P256TO511_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P256TO511_Value_SHIFT))&FEC_RMON_R_P256TO511_Value_MASK) /*!< FEC_RMON_R_P256TO511                    */
/* ------- RMON_R_P512TO1023 Bit Fields             ------ */
#define FEC_RMON_R_P512TO1023_Value_MASK         (0xFFFFFFFFUL << FEC_RMON_R_P512TO1023_Value_SHIFT) /*!< FEC_RMON_R_P512TO1023: Value Mask       */
#define FEC_RMON_R_P512TO1023_Value_SHIFT        0                                                   /*!< FEC_RMON_R_P512TO1023: Value Position   */
#define FEC_RMON_R_P512TO1023_Value(x)           (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P512TO1023_Value_SHIFT))&FEC_RMON_R_P512TO1023_Value_MASK) /*!< FEC_RMON_R_P512TO1023                   */
/* ------- RMON_R_P1024TO2047 Bit Fields            ------ */
#define FEC_RMON_R_P1024TO2047_Value_MASK        (0xFFFFFFFFUL << FEC_RMON_R_P1024TO2047_Value_SHIFT) /*!< FEC_RMON_R_P1024TO2047: Value Mask      */
#define FEC_RMON_R_P1024TO2047_Value_SHIFT       0                                                   /*!< FEC_RMON_R_P1024TO2047: Value Position  */
#define FEC_RMON_R_P1024TO2047_Value(x)          (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P1024TO2047_Value_SHIFT))&FEC_RMON_R_P1024TO2047_Value_MASK) /*!< FEC_RMON_R_P1024TO2047                  */
/* ------- RMON_R_P_GTE2048 Bit Fields              ------ */
#define FEC_RMON_R_P_GTE2048_Value_MASK          (0xFFFFFFFFUL << FEC_RMON_R_P_GTE2048_Value_SHIFT)  /*!< FEC_RMON_R_P_GTE2048: Value Mask        */
#define FEC_RMON_R_P_GTE2048_Value_SHIFT         0                                                   /*!< FEC_RMON_R_P_GTE2048: Value Position    */
#define FEC_RMON_R_P_GTE2048_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P_GTE2048_Value_SHIFT))&FEC_RMON_R_P_GTE2048_Value_MASK) /*!< FEC_RMON_R_P_GTE2048                    */
/* ------- RMON_R_OCTETS Bit Fields                 ------ */
#define FEC_RMON_R_OCTETS_Value_MASK             (0xFFFFFFFFUL << FEC_RMON_R_OCTETS_Value_SHIFT)     /*!< FEC_RMON_R_OCTETS: Value Mask           */
#define FEC_RMON_R_OCTETS_Value_SHIFT            0                                                   /*!< FEC_RMON_R_OCTETS: Value Position       */
#define FEC_RMON_R_OCTETS_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_OCTETS_Value_SHIFT))&FEC_RMON_R_OCTETS_Value_MASK) /*!< FEC_RMON_R_OCTETS                       */
/* ------- IEEE_R_DROP Bit Fields                   ------ */
#define FEC_IEEE_R_DROP_Value_MASK               (0xFFFFFFFFUL << FEC_IEEE_R_DROP_Value_SHIFT)       /*!< FEC_IEEE_R_DROP: Value Mask             */
#define FEC_IEEE_R_DROP_Value_SHIFT              0                                                   /*!< FEC_IEEE_R_DROP: Value Position         */
#define FEC_IEEE_R_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_DROP_Value_SHIFT))&FEC_IEEE_R_DROP_Value_MASK) /*!< FEC_IEEE_R_DROP                         */
/* ------- IEEE_R_FRAME_OK Bit Fields               ------ */
#define FEC_IEEE_R_FRAME_OK_Value_MASK           (0xFFFFFFFFUL << FEC_IEEE_R_FRAME_OK_Value_SHIFT)   /*!< FEC_IEEE_R_FRAME_OK: Value Mask         */
#define FEC_IEEE_R_FRAME_OK_Value_SHIFT          0                                                   /*!< FEC_IEEE_R_FRAME_OK: Value Position     */
#define FEC_IEEE_R_FRAME_OK_Value(x)             (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_FRAME_OK_Value_SHIFT))&FEC_IEEE_R_FRAME_OK_Value_MASK) /*!< FEC_IEEE_R_FRAME_OK                     */
/* ------- IEEE_R_CRC Bit Fields                    ------ */
#define FEC_IEEE_R_CRC_Value_MASK                (0xFFFFFFFFUL << FEC_IEEE_R_CRC_Value_SHIFT)        /*!< FEC_IEEE_R_CRC: Value Mask              */
#define FEC_IEEE_R_CRC_Value_SHIFT               0                                                   /*!< FEC_IEEE_R_CRC: Value Position          */
#define FEC_IEEE_R_CRC_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_CRC_Value_SHIFT))&FEC_IEEE_R_CRC_Value_MASK) /*!< FEC_IEEE_R_CRC                          */
/* ------- IEEE_R_ALIGN Bit Fields                  ------ */
#define FEC_IEEE_R_ALIGN_Value_MASK              (0xFFFFFFFFUL << FEC_IEEE_R_ALIGN_Value_SHIFT)      /*!< FEC_IEEE_R_ALIGN: Value Mask            */
#define FEC_IEEE_R_ALIGN_Value_SHIFT             0                                                   /*!< FEC_IEEE_R_ALIGN: Value Position        */
#define FEC_IEEE_R_ALIGN_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_ALIGN_Value_SHIFT))&FEC_IEEE_R_ALIGN_Value_MASK) /*!< FEC_IEEE_R_ALIGN                        */
/* ------- IEEE_R_MACERR Bit Fields                 ------ */
#define FEC_IEEE_R_MACERR_Value_MASK             (0xFFFFFFFFUL << FEC_IEEE_R_MACERR_Value_SHIFT)     /*!< FEC_IEEE_R_MACERR: Value Mask           */
#define FEC_IEEE_R_MACERR_Value_SHIFT            0                                                   /*!< FEC_IEEE_R_MACERR: Value Position       */
#define FEC_IEEE_R_MACERR_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_MACERR_Value_SHIFT))&FEC_IEEE_R_MACERR_Value_MASK) /*!< FEC_IEEE_R_MACERR                       */
/* ------- IEEE_R_FDXFC Bit Fields                  ------ */
#define FEC_IEEE_R_FDXFC_Value_MASK              (0xFFFFFFFFUL << FEC_IEEE_R_FDXFC_Value_SHIFT)      /*!< FEC_IEEE_R_FDXFC: Value Mask            */
#define FEC_IEEE_R_FDXFC_Value_SHIFT             0                                                   /*!< FEC_IEEE_R_FDXFC: Value Position        */
#define FEC_IEEE_R_FDXFC_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_FDXFC_Value_SHIFT))&FEC_IEEE_R_FDXFC_Value_MASK) /*!< FEC_IEEE_R_FDXFC                        */
/* ------- IEEE_R_OCTETS_OK Bit Fields              ------ */
#define FEC_IEEE_R_OCTETS_OK_Value_MASK          (0xFFFFFFFFUL << FEC_IEEE_R_OCTETS_OK_Value_SHIFT)  /*!< FEC_IEEE_R_OCTETS_OK: Value Mask        */
#define FEC_IEEE_R_OCTETS_OK_Value_SHIFT         0                                                   /*!< FEC_IEEE_R_OCTETS_OK: Value Position    */
#define FEC_IEEE_R_OCTETS_OK_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_OCTETS_OK_Value_SHIFT))&FEC_IEEE_R_OCTETS_OK_Value_MASK) /*!< FEC_IEEE_R_OCTETS_OK                    */

/* FEC - Peripheral instance base addresses */
#define FEC_BasePtr                    0x40001004UL
#define FEC                            ((FEC_Type *) FEC_BasePtr)
#define FEC_BASE_PTR                   (FEC)

/* ================================================================================ */
/* ================           GPIO (file:MCF52233_GPIO)            ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O Port
 */
typedef struct {                                /*!<       GPIO Structure                                               */
   __IO uint8_t   PORTNQ;                       /*!< 0000: Data register                                                */
   __I  uint8_t   RESERVED0;                    /*!< 0001:                                                              */
   __IO uint8_t   PORTAN;                       /*!< 0002: Data register                                                */
   __IO uint8_t   PORTAS;                       /*!< 0003: Data register                                                */
   __IO uint8_t   PORTQS;                       /*!< 0004: Data register                                                */
   __I  uint8_t   RESERVED1;                    /*!< 0005:                                                              */
   __IO uint8_t   PORTTA;                       /*!< 0006: Data register                                                */
   __IO uint8_t   PORTTC;                       /*!< 0007: Data register                                                */
   __IO uint8_t   PORTTD;                       /*!< 0008: Data register                                                */
   __IO uint8_t   PORTUA;                       /*!< 0009: Data register                                                */
   __IO uint8_t   PORTUB;                       /*!< 000A: Data register                                                */
   __IO uint8_t   PORTUC;                       /*!< 000B: Data register                                                */
   __IO uint8_t   PORTDD;                       /*!< 000C: Data register                                                */
   __IO uint8_t   PORTLD;                       /*!< 000D: Data register                                                */
   __IO uint8_t   PORTGP;                       /*!< 000E: Data register                                                */
   __I  uint8_t   RESERVED2[9];                 /*!< 000F:                                                              */
   __IO uint8_t   DDRNQ;                        /*!< 0018: Direction register                                           */
   __I  uint8_t   RESERVED3;                    /*!< 0019:                                                              */
   __IO uint8_t   DDRAN;                        /*!< 001A: Direction register                                           */
   __IO uint8_t   DDRAS;                        /*!< 001B: Direction register                                           */
   __IO uint8_t   DDRQS;                        /*!< 001C: Direction register                                           */
   __I  uint8_t   RESERVED4;                    /*!< 001D:                                                              */
   __IO uint8_t   DDRTA;                        /*!< 001E: Direction register                                           */
   __IO uint8_t   DDRTC;                        /*!< 001F: Direction register                                           */
   __IO uint8_t   DDRTD;                        /*!< 0020: Direction register                                           */
   __IO uint8_t   DDRUA;                        /*!< 0021: Direction register                                           */
   __IO uint8_t   DDRUB;                        /*!< 0022: Direction register                                           */
   __IO uint8_t   DDRUC;                        /*!< 0023: Direction register                                           */
   __IO uint8_t   DDRDD;                        /*!< 0024: Direction register                                           */
   __IO uint8_t   DDRLD;                        /*!< 0025: Direction register                                           */
   __IO uint8_t   DDRGP;                        /*!< 0026: Direction register                                           */
   __I  uint8_t   RESERVED5[9];                 /*!< 0027:                                                              */
   __IO uint8_t   SETNQ;                        /*!< 0030: Pin Data/Set Registers                                       */
   __I  uint8_t   RESERVED6;                    /*!< 0031:                                                              */
   __IO uint8_t   SETAN;                        /*!< 0032: Pin Data/Set Registers                                       */
   __IO uint8_t   SETAS;                        /*!< 0033: Pin Data/Set Registers                                       */
   __IO uint8_t   SETQS;                        /*!< 0034: Pin Data/Set Registers                                       */
   __I  uint8_t   RESERVED7;                    /*!< 0035:                                                              */
   __IO uint8_t   SETTA;                        /*!< 0036: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTC;                        /*!< 0037: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTD;                        /*!< 0038: Pin Data/Set Registers                                       */
   __IO uint8_t   SETUA;                        /*!< 0039: Pin Data/Set Registers                                       */
   __IO uint8_t   SETUB;                        /*!< 003A: Pin Data/Set Registers                                       */
   __IO uint8_t   SETUC;                        /*!< 003B: Pin Data/Set Registers                                       */
   __IO uint8_t   SETDD;                        /*!< 003C: Pin Data/Set Registers                                       */
   __IO uint8_t   SETLD;                        /*!< 003D: Pin Data/Set Registers                                       */
   __IO uint8_t   SETGP;                        /*!< 003E: Pin Data/Set Registers                                       */
   __I  uint8_t   RESERVED8[9];                 /*!< 003F:                                                              */
   __O  uint8_t   CLRNQ;                        /*!< 0048: Port Clear Output Data Register                              */
   __I  uint8_t   RESERVED9;                    /*!< 0049:                                                              */
   __O  uint8_t   CLRAN;                        /*!< 004A: Port Clear Output Data Register                              */
   __O  uint8_t   CLRAS;                        /*!< 004B: Port Clear Output Data Register                              */
   __O  uint8_t   CLRQS;                        /*!< 004C: Port Clear Output Data Register                              */
   __I  uint8_t   RESERVED10;                   /*!< 004D:                                                              */
   __O  uint8_t   CLRTA;                        /*!< 004E: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTC;                        /*!< 004F: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTD;                        /*!< 0050: Port Clear Output Data Register                              */
   __O  uint8_t   CLRUA;                        /*!< 0051: Port Clear Output Data Register                              */
   __O  uint8_t   CLRUB;                        /*!< 0052: Port Clear Output Data Register                              */
   __O  uint8_t   CLRUC;                        /*!< 0053: Port Clear Output Data Register                              */
   __O  uint8_t   CLRDD;                        /*!< 0054: Port Clear Output Data Register                              */
   __O  uint8_t   CLRLD;                        /*!< 0055: Port Clear Output Data Register                              */
   __O  uint8_t   CLRGP;                        /*!< 0056: Port Clear Output Data Register                              */
   __I  uint8_t   RESERVED11[9];                /*!< 0057:                                                              */
   __IO uint16_t  QPARNQ;                       /*!< 0060: Pin Configuration                                            */
   __IO uint8_t   PARAN;                        /*!< 0062: Pin Configuration                                            */
   __IO uint8_t   QPARAS;                       /*!< 0063: Pin Configuration                                            */
   __IO uint16_t  QPARQS;                       /*!< 0064: Pin Configuration                                            */
   __IO uint8_t   QPARTA;                       /*!< 0066: Pin Configuration                                            */
   __IO uint8_t   QPARTC;                       /*!< 0067: Pin Configuration                                            */
   __IO uint8_t   PARTD;                        /*!< 0068: Pin Configuration                                            */
   __IO uint8_t   QPARUA;                       /*!< 0069: Pin Configuration                                            */
   __IO uint8_t   QPARUB;                       /*!< 006A: Pin Configuration                                            */
   __IO uint8_t   PARUC;                        /*!< 006B: Pin Configuration                                            */
   __IO uint8_t   PARDD;                        /*!< 006C: Pin Configuration                                            */
   __IO uint8_t   PARLD;                        /*!< 006D: Pin Configuration                                            */
   __IO uint8_t   PARGP;                        /*!< 006E: Pin Configuration                                            */
} GPIO_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'GPIO' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- PORTNQ Bit Fields                        ------ */
#define GPIO_PORT_PORT0_MASK                     (0x01UL << GPIO_PORT_PORT0_SHIFT)                   /*!< GPIO_PORTNQ: PORT0 Mask                 */
#define GPIO_PORT_PORT0_SHIFT                    0                                                   /*!< GPIO_PORTNQ: PORT0 Position             */
#define GPIO_PORT_PORT1_MASK                     (0x01UL << GPIO_PORT_PORT1_SHIFT)                   /*!< GPIO_PORTNQ: PORT1 Mask                 */
#define GPIO_PORT_PORT1_SHIFT                    1                                                   /*!< GPIO_PORTNQ: PORT1 Position             */
#define GPIO_PORT_PORT2_MASK                     (0x01UL << GPIO_PORT_PORT2_SHIFT)                   /*!< GPIO_PORTNQ: PORT2 Mask                 */
#define GPIO_PORT_PORT2_SHIFT                    2                                                   /*!< GPIO_PORTNQ: PORT2 Position             */
#define GPIO_PORT_PORT3_MASK                     (0x01UL << GPIO_PORT_PORT3_SHIFT)                   /*!< GPIO_PORTNQ: PORT3 Mask                 */
#define GPIO_PORT_PORT3_SHIFT                    3                                                   /*!< GPIO_PORTNQ: PORT3 Position             */
#define GPIO_PORT_PORT4_MASK                     (0x01UL << GPIO_PORT_PORT4_SHIFT)                   /*!< GPIO_PORTNQ: PORT4 Mask                 */
#define GPIO_PORT_PORT4_SHIFT                    4                                                   /*!< GPIO_PORTNQ: PORT4 Position             */
#define GPIO_PORT_PORT5_MASK                     (0x01UL << GPIO_PORT_PORT5_SHIFT)                   /*!< GPIO_PORTNQ: PORT5 Mask                 */
#define GPIO_PORT_PORT5_SHIFT                    5                                                   /*!< GPIO_PORTNQ: PORT5 Position             */
#define GPIO_PORT_PORT6_MASK                     (0x01UL << GPIO_PORT_PORT6_SHIFT)                   /*!< GPIO_PORTNQ: PORT6 Mask                 */
#define GPIO_PORT_PORT6_SHIFT                    6                                                   /*!< GPIO_PORTNQ: PORT6 Position             */
#define GPIO_PORT_PORT7_MASK                     (0x01UL << GPIO_PORT_PORT7_SHIFT)                   /*!< GPIO_PORTNQ: PORT7 Mask                 */
#define GPIO_PORT_PORT7_SHIFT                    7                                                   /*!< GPIO_PORTNQ: PORT7 Position             */
/* ------- DDRNQ Bit Fields                         ------ */
#define GPIO_DDR_DDR0_MASK                       (0x01UL << GPIO_DDR_DDR0_SHIFT)                     /*!< GPIO_DDRNQ: DDR0 Mask                   */
#define GPIO_DDR_DDR0_SHIFT                      0                                                   /*!< GPIO_DDRNQ: DDR0 Position               */
#define GPIO_DDR_DDR1_MASK                       (0x01UL << GPIO_DDR_DDR1_SHIFT)                     /*!< GPIO_DDRNQ: DDR1 Mask                   */
#define GPIO_DDR_DDR1_SHIFT                      1                                                   /*!< GPIO_DDRNQ: DDR1 Position               */
#define GPIO_DDR_DDR2_MASK                       (0x01UL << GPIO_DDR_DDR2_SHIFT)                     /*!< GPIO_DDRNQ: DDR2 Mask                   */
#define GPIO_DDR_DDR2_SHIFT                      2                                                   /*!< GPIO_DDRNQ: DDR2 Position               */
#define GPIO_DDR_DDR3_MASK                       (0x01UL << GPIO_DDR_DDR3_SHIFT)                     /*!< GPIO_DDRNQ: DDR3 Mask                   */
#define GPIO_DDR_DDR3_SHIFT                      3                                                   /*!< GPIO_DDRNQ: DDR3 Position               */
#define GPIO_DDR_DDR4_MASK                       (0x01UL << GPIO_DDR_DDR4_SHIFT)                     /*!< GPIO_DDRNQ: DDR4 Mask                   */
#define GPIO_DDR_DDR4_SHIFT                      4                                                   /*!< GPIO_DDRNQ: DDR4 Position               */
#define GPIO_DDR_DDR5_MASK                       (0x01UL << GPIO_DDR_DDR5_SHIFT)                     /*!< GPIO_DDRNQ: DDR5 Mask                   */
#define GPIO_DDR_DDR5_SHIFT                      5                                                   /*!< GPIO_DDRNQ: DDR5 Position               */
#define GPIO_DDR_DDR6_MASK                       (0x01UL << GPIO_DDR_DDR6_SHIFT)                     /*!< GPIO_DDRNQ: DDR6 Mask                   */
#define GPIO_DDR_DDR6_SHIFT                      6                                                   /*!< GPIO_DDRNQ: DDR6 Position               */
#define GPIO_DDR_DDR7_MASK                       (0x01UL << GPIO_DDR_DDR7_SHIFT)                     /*!< GPIO_DDRNQ: DDR7 Mask                   */
#define GPIO_DDR_DDR7_SHIFT                      7                                                   /*!< GPIO_DDRNQ: DDR7 Position               */
/* ------- SETNQ Bit Fields                         ------ */
#define GPIO_SET_SET0_MASK                       (0x01UL << GPIO_SET_SET0_SHIFT)                     /*!< GPIO_SETNQ: SET0 Mask                   */
#define GPIO_SET_SET0_SHIFT                      0                                                   /*!< GPIO_SETNQ: SET0 Position               */
#define GPIO_SET_SET1_MASK                       (0x01UL << GPIO_SET_SET1_SHIFT)                     /*!< GPIO_SETNQ: SET1 Mask                   */
#define GPIO_SET_SET1_SHIFT                      1                                                   /*!< GPIO_SETNQ: SET1 Position               */
#define GPIO_SET_SET2_MASK                       (0x01UL << GPIO_SET_SET2_SHIFT)                     /*!< GPIO_SETNQ: SET2 Mask                   */
#define GPIO_SET_SET2_SHIFT                      2                                                   /*!< GPIO_SETNQ: SET2 Position               */
#define GPIO_SET_SET3_MASK                       (0x01UL << GPIO_SET_SET3_SHIFT)                     /*!< GPIO_SETNQ: SET3 Mask                   */
#define GPIO_SET_SET3_SHIFT                      3                                                   /*!< GPIO_SETNQ: SET3 Position               */
#define GPIO_SET_SET4_MASK                       (0x01UL << GPIO_SET_SET4_SHIFT)                     /*!< GPIO_SETNQ: SET4 Mask                   */
#define GPIO_SET_SET4_SHIFT                      4                                                   /*!< GPIO_SETNQ: SET4 Position               */
#define GPIO_SET_SET5_MASK                       (0x01UL << GPIO_SET_SET5_SHIFT)                     /*!< GPIO_SETNQ: SET5 Mask                   */
#define GPIO_SET_SET5_SHIFT                      5                                                   /*!< GPIO_SETNQ: SET5 Position               */
#define GPIO_SET_SET6_MASK                       (0x01UL << GPIO_SET_SET6_SHIFT)                     /*!< GPIO_SETNQ: SET6 Mask                   */
#define GPIO_SET_SET6_SHIFT                      6                                                   /*!< GPIO_SETNQ: SET6 Position               */
#define GPIO_SET_SET7_MASK                       (0x01UL << GPIO_SET_SET7_SHIFT)                     /*!< GPIO_SETNQ: SET7 Mask                   */
#define GPIO_SET_SET7_SHIFT                      7                                                   /*!< GPIO_SETNQ: SET7 Position               */
/* ------- CLRNQ Bit Fields                         ------ */
#define GPIO_CLR_CLR0_MASK                       (0x01UL << GPIO_CLR_CLR0_SHIFT)                     /*!< GPIO_CLRNQ: CLR0 Mask                   */
#define GPIO_CLR_CLR0_SHIFT                      0                                                   /*!< GPIO_CLRNQ: CLR0 Position               */
#define GPIO_CLR_CLR1_MASK                       (0x01UL << GPIO_CLR_CLR1_SHIFT)                     /*!< GPIO_CLRNQ: CLR1 Mask                   */
#define GPIO_CLR_CLR1_SHIFT                      1                                                   /*!< GPIO_CLRNQ: CLR1 Position               */
#define GPIO_CLR_CLR2_MASK                       (0x01UL << GPIO_CLR_CLR2_SHIFT)                     /*!< GPIO_CLRNQ: CLR2 Mask                   */
#define GPIO_CLR_CLR2_SHIFT                      2                                                   /*!< GPIO_CLRNQ: CLR2 Position               */
#define GPIO_CLR_CLR3_MASK                       (0x01UL << GPIO_CLR_CLR3_SHIFT)                     /*!< GPIO_CLRNQ: CLR3 Mask                   */
#define GPIO_CLR_CLR3_SHIFT                      3                                                   /*!< GPIO_CLRNQ: CLR3 Position               */
#define GPIO_CLR_CLR4_MASK                       (0x01UL << GPIO_CLR_CLR4_SHIFT)                     /*!< GPIO_CLRNQ: CLR4 Mask                   */
#define GPIO_CLR_CLR4_SHIFT                      4                                                   /*!< GPIO_CLRNQ: CLR4 Position               */
#define GPIO_CLR_CLR5_MASK                       (0x01UL << GPIO_CLR_CLR5_SHIFT)                     /*!< GPIO_CLRNQ: CLR5 Mask                   */
#define GPIO_CLR_CLR5_SHIFT                      5                                                   /*!< GPIO_CLRNQ: CLR5 Position               */
#define GPIO_CLR_CLR6_MASK                       (0x01UL << GPIO_CLR_CLR6_SHIFT)                     /*!< GPIO_CLRNQ: CLR6 Mask                   */
#define GPIO_CLR_CLR6_SHIFT                      6                                                   /*!< GPIO_CLRNQ: CLR6 Position               */
#define GPIO_CLR_CLR7_MASK                       (0x01UL << GPIO_CLR_CLR7_SHIFT)                     /*!< GPIO_CLRNQ: CLR7 Mask                   */
#define GPIO_CLR_CLR7_SHIFT                      7                                                   /*!< GPIO_CLRNQ: CLR7 Position               */
/* ------- QPARNQ Bit Fields                        ------ */
#define GPIO_QPAR_QPAR0_MASK                     (0x03UL << GPIO_QPAR_QPAR0_SHIFT)                   /*!< GPIO_QPARNQ: QPAR0 Mask                 */
#define GPIO_QPAR_QPAR0_SHIFT                    0                                                   /*!< GPIO_QPARNQ: QPAR0 Position             */
#define GPIO_QPAR_QPAR0(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR0_SHIFT))&GPIO_QPAR_QPAR0_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR1_MASK                     (0x03UL << GPIO_QPAR_QPAR1_SHIFT)                   /*!< GPIO_QPARNQ: QPAR1 Mask                 */
#define GPIO_QPAR_QPAR1_SHIFT                    2                                                   /*!< GPIO_QPARNQ: QPAR1 Position             */
#define GPIO_QPAR_QPAR1(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR1_SHIFT))&GPIO_QPAR_QPAR1_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR2_MASK                     (0x03UL << GPIO_QPAR_QPAR2_SHIFT)                   /*!< GPIO_QPARNQ: QPAR2 Mask                 */
#define GPIO_QPAR_QPAR2_SHIFT                    4                                                   /*!< GPIO_QPARNQ: QPAR2 Position             */
#define GPIO_QPAR_QPAR2(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR2_SHIFT))&GPIO_QPAR_QPAR2_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR3_MASK                     (0x03UL << GPIO_QPAR_QPAR3_SHIFT)                   /*!< GPIO_QPARNQ: QPAR3 Mask                 */
#define GPIO_QPAR_QPAR3_SHIFT                    6                                                   /*!< GPIO_QPARNQ: QPAR3 Position             */
#define GPIO_QPAR_QPAR3(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR3_SHIFT))&GPIO_QPAR_QPAR3_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR4_MASK                     (0x03UL << GPIO_QPAR_QPAR4_SHIFT)                   /*!< GPIO_QPARNQ: QPAR4 Mask                 */
#define GPIO_QPAR_QPAR4_SHIFT                    8                                                   /*!< GPIO_QPARNQ: QPAR4 Position             */
#define GPIO_QPAR_QPAR4(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR4_SHIFT))&GPIO_QPAR_QPAR4_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR5_MASK                     (0x03UL << GPIO_QPAR_QPAR5_SHIFT)                   /*!< GPIO_QPARNQ: QPAR5 Mask                 */
#define GPIO_QPAR_QPAR5_SHIFT                    10                                                  /*!< GPIO_QPARNQ: QPAR5 Position             */
#define GPIO_QPAR_QPAR5(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR5_SHIFT))&GPIO_QPAR_QPAR5_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR6_MASK                     (0x03UL << GPIO_QPAR_QPAR6_SHIFT)                   /*!< GPIO_QPARNQ: QPAR6 Mask                 */
#define GPIO_QPAR_QPAR6_SHIFT                    12                                                  /*!< GPIO_QPARNQ: QPAR6 Position             */
#define GPIO_QPAR_QPAR6(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR6_SHIFT))&GPIO_QPAR_QPAR6_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR7_MASK                     (0x03UL << GPIO_QPAR_QPAR7_SHIFT)                   /*!< GPIO_QPARNQ: QPAR7 Mask                 */
#define GPIO_QPAR_QPAR7_SHIFT                    14                                                  /*!< GPIO_QPARNQ: QPAR7 Position             */
#define GPIO_QPAR_QPAR7(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR7_SHIFT))&GPIO_QPAR_QPAR7_MASK) /*!< GPIO_QPARNQ                             */
/* ------- PARAN Bit Fields                         ------ */
#define GPIO_PAR_PAR0_MASK                       (0x01UL << GPIO_PAR_PAR0_SHIFT)                     /*!< GPIO_PARAN: PAR0 Mask                   */
#define GPIO_PAR_PAR0_SHIFT                      0                                                   /*!< GPIO_PARAN: PAR0 Position               */
#define GPIO_PAR_PAR1_MASK                       (0x01UL << GPIO_PAR_PAR1_SHIFT)                     /*!< GPIO_PARAN: PAR1 Mask                   */
#define GPIO_PAR_PAR1_SHIFT                      1                                                   /*!< GPIO_PARAN: PAR1 Position               */
#define GPIO_PAR_PAR2_MASK                       (0x01UL << GPIO_PAR_PAR2_SHIFT)                     /*!< GPIO_PARAN: PAR2 Mask                   */
#define GPIO_PAR_PAR2_SHIFT                      2                                                   /*!< GPIO_PARAN: PAR2 Position               */
#define GPIO_PAR_PAR3_MASK                       (0x01UL << GPIO_PAR_PAR3_SHIFT)                     /*!< GPIO_PARAN: PAR3 Mask                   */
#define GPIO_PAR_PAR3_SHIFT                      3                                                   /*!< GPIO_PARAN: PAR3 Position               */
#define GPIO_PAR_PAR4_MASK                       (0x01UL << GPIO_PAR_PAR4_SHIFT)                     /*!< GPIO_PARAN: PAR4 Mask                   */
#define GPIO_PAR_PAR4_SHIFT                      4                                                   /*!< GPIO_PARAN: PAR4 Position               */
#define GPIO_PAR_PAR5_MASK                       (0x01UL << GPIO_PAR_PAR5_SHIFT)                     /*!< GPIO_PARAN: PAR5 Mask                   */
#define GPIO_PAR_PAR5_SHIFT                      5                                                   /*!< GPIO_PARAN: PAR5 Position               */
#define GPIO_PAR_PAR6_MASK                       (0x01UL << GPIO_PAR_PAR6_SHIFT)                     /*!< GPIO_PARAN: PAR6 Mask                   */
#define GPIO_PAR_PAR6_SHIFT                      6                                                   /*!< GPIO_PARAN: PAR6 Position               */
#define GPIO_PAR_PAR7_MASK                       (0x01UL << GPIO_PAR_PAR7_SHIFT)                     /*!< GPIO_PARAN: PAR7 Mask                   */
#define GPIO_PAR_PAR7_SHIFT                      7                                                   /*!< GPIO_PARAN: PAR7 Position               */
/* ------- QPARAS Bit Fields                        ------ */

/* GPIO - Peripheral instance base addresses */
#define GPIO_BasePtr                   0x40100008UL
#define GPIO                           ((GPIO_Type *) GPIO_BasePtr)
#define GPIO_BASE_PTR                  (GPIO)

/* ================================================================================ */
/* ================           GPTA (file:MCF52233_GPTA)            ================ */
/* ================================================================================ */

/**
 * @brief None
 */
typedef struct {                                /*!<       GPTA Structure                                               */
   __IO uint8_t   GPTIOS;                       /*!< 0000: None                                                         */
   __IO uint8_t   GPTCFORC;                     /*!< 0001: None                                                         */
   __IO uint8_t   GPTOC3M;                      /*!< 0002: None                                                         */
   __IO uint8_t   GPTOC3D;                      /*!< 0003: None                                                         */
   __IO uint16_t  GPTCNT;                       /*!< 0004: None                                                         */
   __IO uint8_t   GPTSCR1;                      /*!< 0006: None                                                         */
   __I  uint8_t   RESERVED0;                    /*!< 0007:                                                              */
   __IO uint8_t   GPTTOV;                       /*!< 0008: None                                                         */
   __IO uint8_t   GPTCTL1;                      /*!< 0009: None                                                         */
   __I  uint8_t   RESERVED1;                    /*!< 000A:                                                              */
   __IO uint8_t   GPTCTL2;                      /*!< 000B: None                                                         */
   __IO uint8_t   GPTIE;                        /*!< 000C: None                                                         */
   __IO uint8_t   GPTSCR2;                      /*!< 000D: None                                                         */
   __IO uint8_t   GPTFLG1;                      /*!< 000E: None                                                         */
   __IO uint8_t   GPTFLG2;                      /*!< 000F: None                                                         */
   __IO uint16_t  GPTC[4];                      /*!< 0010: None                                                         */
   __IO uint8_t   GPTPACTL;                     /*!< 0018: None                                                         */
   __IO uint8_t   GPTPAFLG;                     /*!< 0019: None                                                         */
   __IO uint16_t  GPTPACNT;                     /*!< 001A: None                                                         */
   __I  uint8_t   RESERVED2;                    /*!< 001C:                                                              */
   __IO uint8_t   GPTPORT;                      /*!< 001D: None                                                         */
   __IO uint8_t   GPTDDR;                       /*!< 001E: None                                                         */
} GPTA_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'GPTA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- GPTIOS Bit Fields                        ------ */
#define GPTA_GPTIOS_IOS0_MASK                    (0x01UL << GPTA_GPTIOS_IOS0_SHIFT)                  /*!< GPTA_GPTIOS: IOS0 Mask                  */
#define GPTA_GPTIOS_IOS0_SHIFT                   0                                                   /*!< GPTA_GPTIOS: IOS0 Position              */
#define GPTA_GPTIOS_IOS1_MASK                    (0x01UL << GPTA_GPTIOS_IOS1_SHIFT)                  /*!< GPTA_GPTIOS: IOS1 Mask                  */
#define GPTA_GPTIOS_IOS1_SHIFT                   1                                                   /*!< GPTA_GPTIOS: IOS1 Position              */
#define GPTA_GPTIOS_IOS2_MASK                    (0x01UL << GPTA_GPTIOS_IOS2_SHIFT)                  /*!< GPTA_GPTIOS: IOS2 Mask                  */
#define GPTA_GPTIOS_IOS2_SHIFT                   2                                                   /*!< GPTA_GPTIOS: IOS2 Position              */
#define GPTA_GPTIOS_IOS3_MASK                    (0x01UL << GPTA_GPTIOS_IOS3_SHIFT)                  /*!< GPTA_GPTIOS: IOS3 Mask                  */
#define GPTA_GPTIOS_IOS3_SHIFT                   3                                                   /*!< GPTA_GPTIOS: IOS3 Position              */
/* ------- GPTCFORC Bit Fields                      ------ */
#define GPTA_GPTCFORC_FOC0_MASK                  (0x01UL << GPTA_GPTCFORC_FOC0_SHIFT)                /*!< GPTA_GPTCFORC: FOC0 Mask                */
#define GPTA_GPTCFORC_FOC0_SHIFT                 0                                                   /*!< GPTA_GPTCFORC: FOC0 Position            */
#define GPTA_GPTCFORC_FOC1_MASK                  (0x01UL << GPTA_GPTCFORC_FOC1_SHIFT)                /*!< GPTA_GPTCFORC: FOC1 Mask                */
#define GPTA_GPTCFORC_FOC1_SHIFT                 1                                                   /*!< GPTA_GPTCFORC: FOC1 Position            */
#define GPTA_GPTCFORC_FOC2_MASK                  (0x01UL << GPTA_GPTCFORC_FOC2_SHIFT)                /*!< GPTA_GPTCFORC: FOC2 Mask                */
#define GPTA_GPTCFORC_FOC2_SHIFT                 2                                                   /*!< GPTA_GPTCFORC: FOC2 Position            */
#define GPTA_GPTCFORC_FOC3_MASK                  (0x01UL << GPTA_GPTCFORC_FOC3_SHIFT)                /*!< GPTA_GPTCFORC: FOC3 Mask                */
#define GPTA_GPTCFORC_FOC3_SHIFT                 3                                                   /*!< GPTA_GPTCFORC: FOC3 Position            */
/* ------- GPTOC3M Bit Fields                       ------ */
#define GPTA_GPTOC3M_OC3M0_MASK                  (0x01UL << GPTA_GPTOC3M_OC3M0_SHIFT)                /*!< GPTA_GPTOC3M: OC3M0 Mask                */
#define GPTA_GPTOC3M_OC3M0_SHIFT                 0                                                   /*!< GPTA_GPTOC3M: OC3M0 Position            */
#define GPTA_GPTOC3M_OC3M1_MASK                  (0x01UL << GPTA_GPTOC3M_OC3M1_SHIFT)                /*!< GPTA_GPTOC3M: OC3M1 Mask                */
#define GPTA_GPTOC3M_OC3M1_SHIFT                 1                                                   /*!< GPTA_GPTOC3M: OC3M1 Position            */
#define GPTA_GPTOC3M_OC3M2_MASK                  (0x01UL << GPTA_GPTOC3M_OC3M2_SHIFT)                /*!< GPTA_GPTOC3M: OC3M2 Mask                */
#define GPTA_GPTOC3M_OC3M2_SHIFT                 2                                                   /*!< GPTA_GPTOC3M: OC3M2 Position            */
#define GPTA_GPTOC3M_OC3M3_MASK                  (0x01UL << GPTA_GPTOC3M_OC3M3_SHIFT)                /*!< GPTA_GPTOC3M: OC3M3 Mask                */
#define GPTA_GPTOC3M_OC3M3_SHIFT                 3                                                   /*!< GPTA_GPTOC3M: OC3M3 Position            */
/* ------- GPTOC3D Bit Fields                       ------ */
#define GPTA_GPTOC3D_OC3D0_MASK                  (0x01UL << GPTA_GPTOC3D_OC3D0_SHIFT)                /*!< GPTA_GPTOC3D: OC3D0 Mask                */
#define GPTA_GPTOC3D_OC3D0_SHIFT                 0                                                   /*!< GPTA_GPTOC3D: OC3D0 Position            */
#define GPTA_GPTOC3D_OC3D1_MASK                  (0x01UL << GPTA_GPTOC3D_OC3D1_SHIFT)                /*!< GPTA_GPTOC3D: OC3D1 Mask                */
#define GPTA_GPTOC3D_OC3D1_SHIFT                 1                                                   /*!< GPTA_GPTOC3D: OC3D1 Position            */
#define GPTA_GPTOC3D_OC3D2_MASK                  (0x01UL << GPTA_GPTOC3D_OC3D2_SHIFT)                /*!< GPTA_GPTOC3D: OC3D2 Mask                */
#define GPTA_GPTOC3D_OC3D2_SHIFT                 2                                                   /*!< GPTA_GPTOC3D: OC3D2 Position            */
#define GPTA_GPTOC3D_OC3D3_MASK                  (0x01UL << GPTA_GPTOC3D_OC3D3_SHIFT)                /*!< GPTA_GPTOC3D: OC3D3 Mask                */
#define GPTA_GPTOC3D_OC3D3_SHIFT                 3                                                   /*!< GPTA_GPTOC3D: OC3D3 Position            */
/* ------- GPTCNT Bit Fields                        ------ */
#define GPTA_GPTCNT_CNTR_MASK                    (0xFFFFUL << GPTA_GPTCNT_CNTR_SHIFT)                /*!< GPTA_GPTCNT: CNTR Mask                  */
#define GPTA_GPTCNT_CNTR_SHIFT                   0                                                   /*!< GPTA_GPTCNT: CNTR Position              */
#define GPTA_GPTCNT_CNTR(x)                      (((uint16_t)(((uint16_t)(x))<<GPTA_GPTCNT_CNTR_SHIFT))&GPTA_GPTCNT_CNTR_MASK) /*!< GPTA_GPTCNT                             */
/* ------- GPTSCR1 Bit Fields                       ------ */
#define GPTA_GPTSCR1_TFFCA_MASK                  (0x01UL << GPTA_GPTSCR1_TFFCA_SHIFT)                /*!< GPTA_GPTSCR1: TFFCA Mask                */
#define GPTA_GPTSCR1_TFFCA_SHIFT                 4                                                   /*!< GPTA_GPTSCR1: TFFCA Position            */
#define GPTA_GPTSCR1_GPTEN_MASK                  (0x01UL << GPTA_GPTSCR1_GPTEN_SHIFT)                /*!< GPTA_GPTSCR1: GPTEN Mask                */
#define GPTA_GPTSCR1_GPTEN_SHIFT                 7                                                   /*!< GPTA_GPTSCR1: GPTEN Position            */
/* ------- GPTTOV Bit Fields                        ------ */
#define GPTA_GPTTOV_TOV0_MASK                    (0x01UL << GPTA_GPTTOV_TOV0_SHIFT)                  /*!< GPTA_GPTTOV: TOV0 Mask                  */
#define GPTA_GPTTOV_TOV0_SHIFT                   0                                                   /*!< GPTA_GPTTOV: TOV0 Position              */
#define GPTA_GPTTOV_TOV1_MASK                    (0x01UL << GPTA_GPTTOV_TOV1_SHIFT)                  /*!< GPTA_GPTTOV: TOV1 Mask                  */
#define GPTA_GPTTOV_TOV1_SHIFT                   1                                                   /*!< GPTA_GPTTOV: TOV1 Position              */
#define GPTA_GPTTOV_TOV2_MASK                    (0x01UL << GPTA_GPTTOV_TOV2_SHIFT)                  /*!< GPTA_GPTTOV: TOV2 Mask                  */
#define GPTA_GPTTOV_TOV2_SHIFT                   2                                                   /*!< GPTA_GPTTOV: TOV2 Position              */
#define GPTA_GPTTOV_TOV3_MASK                    (0x01UL << GPTA_GPTTOV_TOV3_SHIFT)                  /*!< GPTA_GPTTOV: TOV3 Mask                  */
#define GPTA_GPTTOV_TOV3_SHIFT                   3                                                   /*!< GPTA_GPTTOV: TOV3 Position              */
/* ------- GPTCTL1 Bit Fields                       ------ */
#define GPTA_GPTCTL1_OL0_MASK                    (0x01UL << GPTA_GPTCTL1_OL0_SHIFT)                  /*!< GPTA_GPTCTL1: OL0 Mask                  */
#define GPTA_GPTCTL1_OL0_SHIFT                   0                                                   /*!< GPTA_GPTCTL1: OL0 Position              */
#define GPTA_GPTCTL1_OM0_MASK                    (0x01UL << GPTA_GPTCTL1_OM0_SHIFT)                  /*!< GPTA_GPTCTL1: OM0 Mask                  */
#define GPTA_GPTCTL1_OM0_SHIFT                   1                                                   /*!< GPTA_GPTCTL1: OM0 Position              */
#define GPTA_GPTCTL1_OL1_MASK                    (0x01UL << GPTA_GPTCTL1_OL1_SHIFT)                  /*!< GPTA_GPTCTL1: OL1 Mask                  */
#define GPTA_GPTCTL1_OL1_SHIFT                   2                                                   /*!< GPTA_GPTCTL1: OL1 Position              */
#define GPTA_GPTCTL1_OM1_MASK                    (0x01UL << GPTA_GPTCTL1_OM1_SHIFT)                  /*!< GPTA_GPTCTL1: OM1 Mask                  */
#define GPTA_GPTCTL1_OM1_SHIFT                   3                                                   /*!< GPTA_GPTCTL1: OM1 Position              */
#define GPTA_GPTCTL1_OL2_MASK                    (0x01UL << GPTA_GPTCTL1_OL2_SHIFT)                  /*!< GPTA_GPTCTL1: OL2 Mask                  */
#define GPTA_GPTCTL1_OL2_SHIFT                   4                                                   /*!< GPTA_GPTCTL1: OL2 Position              */
#define GPTA_GPTCTL1_OM2_MASK                    (0x01UL << GPTA_GPTCTL1_OM2_SHIFT)                  /*!< GPTA_GPTCTL1: OM2 Mask                  */
#define GPTA_GPTCTL1_OM2_SHIFT                   5                                                   /*!< GPTA_GPTCTL1: OM2 Position              */
#define GPTA_GPTCTL1_OL3_MASK                    (0x01UL << GPTA_GPTCTL1_OL3_SHIFT)                  /*!< GPTA_GPTCTL1: OL3 Mask                  */
#define GPTA_GPTCTL1_OL3_SHIFT                   6                                                   /*!< GPTA_GPTCTL1: OL3 Position              */
#define GPTA_GPTCTL1_OM3_MASK                    (0x01UL << GPTA_GPTCTL1_OM3_SHIFT)                  /*!< GPTA_GPTCTL1: OM3 Mask                  */
#define GPTA_GPTCTL1_OM3_SHIFT                   7                                                   /*!< GPTA_GPTCTL1: OM3 Position              */
/* ------- GPTCTL2 Bit Fields                       ------ */
#define GPTA_GPTCTL2_EDG0A_MASK                  (0x01UL << GPTA_GPTCTL2_EDG0A_SHIFT)                /*!< GPTA_GPTCTL2: EDG0A Mask                */
#define GPTA_GPTCTL2_EDG0A_SHIFT                 0                                                   /*!< GPTA_GPTCTL2: EDG0A Position            */
#define GPTA_GPTCTL2_EDG0B_MASK                  (0x01UL << GPTA_GPTCTL2_EDG0B_SHIFT)                /*!< GPTA_GPTCTL2: EDG0B Mask                */
#define GPTA_GPTCTL2_EDG0B_SHIFT                 1                                                   /*!< GPTA_GPTCTL2: EDG0B Position            */
#define GPTA_GPTCTL2_EDG1A_MASK                  (0x01UL << GPTA_GPTCTL2_EDG1A_SHIFT)                /*!< GPTA_GPTCTL2: EDG1A Mask                */
#define GPTA_GPTCTL2_EDG1A_SHIFT                 2                                                   /*!< GPTA_GPTCTL2: EDG1A Position            */
#define GPTA_GPTCTL2_EDG1B_MASK                  (0x01UL << GPTA_GPTCTL2_EDG1B_SHIFT)                /*!< GPTA_GPTCTL2: EDG1B Mask                */
#define GPTA_GPTCTL2_EDG1B_SHIFT                 3                                                   /*!< GPTA_GPTCTL2: EDG1B Position            */
#define GPTA_GPTCTL2_EDG2A_MASK                  (0x01UL << GPTA_GPTCTL2_EDG2A_SHIFT)                /*!< GPTA_GPTCTL2: EDG2A Mask                */
#define GPTA_GPTCTL2_EDG2A_SHIFT                 4                                                   /*!< GPTA_GPTCTL2: EDG2A Position            */
#define GPTA_GPTCTL2_EDG2B_MASK                  (0x01UL << GPTA_GPTCTL2_EDG2B_SHIFT)                /*!< GPTA_GPTCTL2: EDG2B Mask                */
#define GPTA_GPTCTL2_EDG2B_SHIFT                 5                                                   /*!< GPTA_GPTCTL2: EDG2B Position            */
#define GPTA_GPTCTL2_EDG3A_MASK                  (0x01UL << GPTA_GPTCTL2_EDG3A_SHIFT)                /*!< GPTA_GPTCTL2: EDG3A Mask                */
#define GPTA_GPTCTL2_EDG3A_SHIFT                 6                                                   /*!< GPTA_GPTCTL2: EDG3A Position            */
#define GPTA_GPTCTL2_EDG3B_MASK                  (0x01UL << GPTA_GPTCTL2_EDG3B_SHIFT)                /*!< GPTA_GPTCTL2: EDG3B Mask                */
#define GPTA_GPTCTL2_EDG3B_SHIFT                 7                                                   /*!< GPTA_GPTCTL2: EDG3B Position            */
/* ------- GPTIE Bit Fields                         ------ */
#define GPTA_GPTIE_CI0_MASK                      (0x01UL << GPTA_GPTIE_CI0_SHIFT)                    /*!< GPTA_GPTIE: CI0 Mask                    */
#define GPTA_GPTIE_CI0_SHIFT                     0                                                   /*!< GPTA_GPTIE: CI0 Position                */
#define GPTA_GPTIE_CI1_MASK                      (0x01UL << GPTA_GPTIE_CI1_SHIFT)                    /*!< GPTA_GPTIE: CI1 Mask                    */
#define GPTA_GPTIE_CI1_SHIFT                     1                                                   /*!< GPTA_GPTIE: CI1 Position                */
#define GPTA_GPTIE_CI2_MASK                      (0x01UL << GPTA_GPTIE_CI2_SHIFT)                    /*!< GPTA_GPTIE: CI2 Mask                    */
#define GPTA_GPTIE_CI2_SHIFT                     2                                                   /*!< GPTA_GPTIE: CI2 Position                */
#define GPTA_GPTIE_CI3_MASK                      (0x01UL << GPTA_GPTIE_CI3_SHIFT)                    /*!< GPTA_GPTIE: CI3 Mask                    */
#define GPTA_GPTIE_CI3_SHIFT                     3                                                   /*!< GPTA_GPTIE: CI3 Position                */
/* ------- GPTSCR2 Bit Fields                       ------ */
#define GPTA_GPTSCR2_PR_MASK                     (0x07UL << GPTA_GPTSCR2_PR_SHIFT)                   /*!< GPTA_GPTSCR2: PR Mask                   */
#define GPTA_GPTSCR2_PR_SHIFT                    0                                                   /*!< GPTA_GPTSCR2: PR Position               */
#define GPTA_GPTSCR2_PR(x)                       (((uint8_t)(((uint8_t)(x))<<GPTA_GPTSCR2_PR_SHIFT))&GPTA_GPTSCR2_PR_MASK) /*!< GPTA_GPTSCR2                            */
#define GPTA_GPTSCR2_TCRE_MASK                   (0x01UL << GPTA_GPTSCR2_TCRE_SHIFT)                 /*!< GPTA_GPTSCR2: TCRE Mask                 */
#define GPTA_GPTSCR2_TCRE_SHIFT                  3                                                   /*!< GPTA_GPTSCR2: TCRE Position             */
#define GPTA_GPTSCR2_RDPT_MASK                   (0x01UL << GPTA_GPTSCR2_RDPT_SHIFT)                 /*!< GPTA_GPTSCR2: RDPT Mask                 */
#define GPTA_GPTSCR2_RDPT_SHIFT                  4                                                   /*!< GPTA_GPTSCR2: RDPT Position             */
#define GPTA_GPTSCR2_PUPT_MASK                   (0x01UL << GPTA_GPTSCR2_PUPT_SHIFT)                 /*!< GPTA_GPTSCR2: PUPT Mask                 */
#define GPTA_GPTSCR2_PUPT_SHIFT                  5                                                   /*!< GPTA_GPTSCR2: PUPT Position             */
#define GPTA_GPTSCR2_TOI_MASK                    (0x01UL << GPTA_GPTSCR2_TOI_SHIFT)                  /*!< GPTA_GPTSCR2: TOI Mask                  */
#define GPTA_GPTSCR2_TOI_SHIFT                   7                                                   /*!< GPTA_GPTSCR2: TOI Position              */
/* ------- GPTFLG1 Bit Fields                       ------ */
#define GPTA_GPTFLG1_CF0_MASK                    (0x01UL << GPTA_GPTFLG1_CF0_SHIFT)                  /*!< GPTA_GPTFLG1: CF0 Mask                  */
#define GPTA_GPTFLG1_CF0_SHIFT                   0                                                   /*!< GPTA_GPTFLG1: CF0 Position              */
#define GPTA_GPTFLG1_CF1_MASK                    (0x01UL << GPTA_GPTFLG1_CF1_SHIFT)                  /*!< GPTA_GPTFLG1: CF1 Mask                  */
#define GPTA_GPTFLG1_CF1_SHIFT                   1                                                   /*!< GPTA_GPTFLG1: CF1 Position              */
#define GPTA_GPTFLG1_CF2_MASK                    (0x01UL << GPTA_GPTFLG1_CF2_SHIFT)                  /*!< GPTA_GPTFLG1: CF2 Mask                  */
#define GPTA_GPTFLG1_CF2_SHIFT                   2                                                   /*!< GPTA_GPTFLG1: CF2 Position              */
#define GPTA_GPTFLG1_CF3_MASK                    (0x01UL << GPTA_GPTFLG1_CF3_SHIFT)                  /*!< GPTA_GPTFLG1: CF3 Mask                  */
#define GPTA_GPTFLG1_CF3_SHIFT                   3                                                   /*!< GPTA_GPTFLG1: CF3 Position              */
/* ------- GPTFLG2 Bit Fields                       ------ */
#define GPTA_GPTFLG2_TOF_MASK                    (0x01UL << GPTA_GPTFLG2_TOF_SHIFT)                  /*!< GPTA_GPTFLG2: TOF Mask                  */
#define GPTA_GPTFLG2_TOF_SHIFT                   7                                                   /*!< GPTA_GPTFLG2: TOF Position              */
/* ------- GPTC Bit Fields                          ------ */
#define GPTA_GPTC_CCNT_MASK                      (0xFFFFUL << GPTA_GPTC_CCNT_SHIFT)                  /*!< GPTA_GPTC: CCNT Mask                    */
#define GPTA_GPTC_CCNT_SHIFT                     0                                                   /*!< GPTA_GPTC: CCNT Position                */
#define GPTA_GPTC_CCNT(x)                        (((uint16_t)(((uint16_t)(x))<<GPTA_GPTC_CCNT_SHIFT))&GPTA_GPTC_CCNT_MASK) /*!< GPTA_GPTC                               */
/* ------- GPTPACTL Bit Fields                      ------ */
#define GPTA_GPTPACTL_PAI_MASK                   (0x01UL << GPTA_GPTPACTL_PAI_SHIFT)                 /*!< GPTA_GPTPACTL: PAI Mask                 */
#define GPTA_GPTPACTL_PAI_SHIFT                  0                                                   /*!< GPTA_GPTPACTL: PAI Position             */
#define GPTA_GPTPACTL_PAOVI_MASK                 (0x01UL << GPTA_GPTPACTL_PAOVI_SHIFT)               /*!< GPTA_GPTPACTL: PAOVI Mask               */
#define GPTA_GPTPACTL_PAOVI_SHIFT                1                                                   /*!< GPTA_GPTPACTL: PAOVI Position           */
#define GPTA_GPTPACTL_CLK_MASK                   (0x03UL << GPTA_GPTPACTL_CLK_SHIFT)                 /*!< GPTA_GPTPACTL: CLK Mask                 */
#define GPTA_GPTPACTL_CLK_SHIFT                  2                                                   /*!< GPTA_GPTPACTL: CLK Position             */
#define GPTA_GPTPACTL_CLK(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPACTL_CLK_SHIFT))&GPTA_GPTPACTL_CLK_MASK) /*!< GPTA_GPTPACTL                           */
#define GPTA_GPTPACTL_PEDGE_MASK                 (0x01UL << GPTA_GPTPACTL_PEDGE_SHIFT)               /*!< GPTA_GPTPACTL: PEDGE Mask               */
#define GPTA_GPTPACTL_PEDGE_SHIFT                4                                                   /*!< GPTA_GPTPACTL: PEDGE Position           */
#define GPTA_GPTPACTL_PAMOD_MASK                 (0x01UL << GPTA_GPTPACTL_PAMOD_SHIFT)               /*!< GPTA_GPTPACTL: PAMOD Mask               */
#define GPTA_GPTPACTL_PAMOD_SHIFT                5                                                   /*!< GPTA_GPTPACTL: PAMOD Position           */
#define GPTA_GPTPACTL_PAE_MASK                   (0x01UL << GPTA_GPTPACTL_PAE_SHIFT)                 /*!< GPTA_GPTPACTL: PAE Mask                 */
#define GPTA_GPTPACTL_PAE_SHIFT                  6                                                   /*!< GPTA_GPTPACTL: PAE Position             */
/* ------- GPTPAFLG Bit Fields                      ------ */
#define GPTA_GPTPAFLG_PAIF_MASK                  (0x01UL << GPTA_GPTPAFLG_PAIF_SHIFT)                /*!< GPTA_GPTPAFLG: PAIF Mask                */
#define GPTA_GPTPAFLG_PAIF_SHIFT                 0                                                   /*!< GPTA_GPTPAFLG: PAIF Position            */
#define GPTA_GPTPAFLG_PAOVF_MASK                 (0x01UL << GPTA_GPTPAFLG_PAOVF_SHIFT)               /*!< GPTA_GPTPAFLG: PAOVF Mask               */
#define GPTA_GPTPAFLG_PAOVF_SHIFT                1                                                   /*!< GPTA_GPTPAFLG: PAOVF Position           */
/* ------- GPTPACNT Bit Fields                      ------ */
#define GPTA_GPTPACNT_PACNT_MASK                 (0xFFFFUL << GPTA_GPTPACNT_PACNT_SHIFT)             /*!< GPTA_GPTPACNT: PACNT Mask               */
#define GPTA_GPTPACNT_PACNT_SHIFT                0                                                   /*!< GPTA_GPTPACNT: PACNT Position           */
#define GPTA_GPTPACNT_PACNT(x)                   (((uint16_t)(((uint16_t)(x))<<GPTA_GPTPACNT_PACNT_SHIFT))&GPTA_GPTPACNT_PACNT_MASK) /*!< GPTA_GPTPACNT                           */
/* ------- GPTPORT Bit Fields                       ------ */
#define GPTA_GPTPORT_PORTT0_MASK                 (0x01UL << GPTA_GPTPORT_PORTT0_SHIFT)               /*!< GPTA_GPTPORT: PORTT0 Mask               */
#define GPTA_GPTPORT_PORTT0_SHIFT                0                                                   /*!< GPTA_GPTPORT: PORTT0 Position           */
#define GPTA_GPTPORT_PORTT1_MASK                 (0x01UL << GPTA_GPTPORT_PORTT1_SHIFT)               /*!< GPTA_GPTPORT: PORTT1 Mask               */
#define GPTA_GPTPORT_PORTT1_SHIFT                1                                                   /*!< GPTA_GPTPORT: PORTT1 Position           */
#define GPTA_GPTPORT_PORTT2_MASK                 (0x01UL << GPTA_GPTPORT_PORTT2_SHIFT)               /*!< GPTA_GPTPORT: PORTT2 Mask               */
#define GPTA_GPTPORT_PORTT2_SHIFT                2                                                   /*!< GPTA_GPTPORT: PORTT2 Position           */
#define GPTA_GPTPORT_PORTT3_MASK                 (0x01UL << GPTA_GPTPORT_PORTT3_SHIFT)               /*!< GPTA_GPTPORT: PORTT3 Mask               */
#define GPTA_GPTPORT_PORTT3_SHIFT                3                                                   /*!< GPTA_GPTPORT: PORTT3 Position           */
/* ------- GPTDDR Bit Fields                        ------ */
#define GPTA_GPTDDR_DDRT0_MASK                   (0x01UL << GPTA_GPTDDR_DDRT0_SHIFT)                 /*!< GPTA_GPTDDR: DDRT0 Mask                 */
#define GPTA_GPTDDR_DDRT0_SHIFT                  0                                                   /*!< GPTA_GPTDDR: DDRT0 Position             */
#define GPTA_GPTDDR_DDRT1_MASK                   (0x01UL << GPTA_GPTDDR_DDRT1_SHIFT)                 /*!< GPTA_GPTDDR: DDRT1 Mask                 */
#define GPTA_GPTDDR_DDRT1_SHIFT                  1                                                   /*!< GPTA_GPTDDR: DDRT1 Position             */
#define GPTA_GPTDDR_DDRT2_MASK                   (0x01UL << GPTA_GPTDDR_DDRT2_SHIFT)                 /*!< GPTA_GPTDDR: DDRT2 Mask                 */
#define GPTA_GPTDDR_DDRT2_SHIFT                  2                                                   /*!< GPTA_GPTDDR: DDRT2 Position             */
#define GPTA_GPTDDR_DDRT3_MASK                   (0x01UL << GPTA_GPTDDR_DDRT3_SHIFT)                 /*!< GPTA_GPTDDR: DDRT3 Mask                 */
#define GPTA_GPTDDR_DDRT3_SHIFT                  3                                                   /*!< GPTA_GPTDDR: DDRT3 Position             */

/* GPTA - Peripheral instance base addresses */
#define GPTA_BasePtr                   0x401A0000UL
#define GPTA                           ((GPTA_Type *) GPTA_BasePtr)
#define GPTA_BASE_PTR                  (GPTA)

/* ================================================================================ */
/* ================           I2C0 (file:MCF522xx_I2C0)            ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */
typedef struct {                                /*!<       I2C0 Structure                                               */
   __IO uint8_t   I2ADR;                        /*!< 0000: Address Register                                             */
   __I  uint8_t   RESERVED0[3];                 /*!< 0001:                                                              */
   __IO uint8_t   I2FDR;                        /*!< 0004: Frequency Divider Register                                   */
   __I  uint8_t   RESERVED1[3];                 /*!< 0005:                                                              */
   __IO uint8_t   I2CR;                         /*!< 0008: Control Register                                             */
   __I  uint8_t   RESERVED2[3];                 /*!< 0009:                                                              */
   __IO uint8_t   I2SR;                         /*!< 000C: Status Register                                              */
   __I  uint8_t   RESERVED3[3];                 /*!< 000D:                                                              */
   __IO uint8_t   I2DR;                         /*!< 0010: Data I/O Register                                            */
} I2C_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- I2ADR Bit Fields                         ------ */
#define I2C_I2ADR_ADR_MASK                       (0x7FUL << I2C_I2ADR_ADR_SHIFT)                     /*!< I2C0_I2ADR: ADR Mask                    */
#define I2C_I2ADR_ADR_SHIFT                      1                                                   /*!< I2C0_I2ADR: ADR Position                */
#define I2C_I2ADR_ADR(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2ADR_ADR_SHIFT))&I2C_I2ADR_ADR_MASK) /*!< I2C0_I2ADR                              */
/* ------- I2FDR Bit Fields                         ------ */
#define I2C_I2FDR_IC_MASK                        (0x3FUL << I2C_I2FDR_IC_SHIFT)                      /*!< I2C0_I2FDR: IC Mask                     */
#define I2C_I2FDR_IC_SHIFT                       0                                                   /*!< I2C0_I2FDR: IC Position                 */
#define I2C_I2FDR_IC(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2FDR_IC_SHIFT))&I2C_I2FDR_IC_MASK) /*!< I2C0_I2FDR                              */
/* ------- I2CR Bit Fields                          ------ */
#define I2C_I2CR_RSTA_MASK                       (0x01UL << I2C_I2CR_RSTA_SHIFT)                     /*!< I2C0_I2CR: RSTA Mask                    */
#define I2C_I2CR_RSTA_SHIFT                      2                                                   /*!< I2C0_I2CR: RSTA Position                */
#define I2C_I2CR_TXAK_MASK                       (0x01UL << I2C_I2CR_TXAK_SHIFT)                     /*!< I2C0_I2CR: TXAK Mask                    */
#define I2C_I2CR_TXAK_SHIFT                      3                                                   /*!< I2C0_I2CR: TXAK Position                */
#define I2C_I2CR_MTX_MASK                        (0x01UL << I2C_I2CR_MTX_SHIFT)                      /*!< I2C0_I2CR: MTX Mask                     */
#define I2C_I2CR_MTX_SHIFT                       4                                                   /*!< I2C0_I2CR: MTX Position                 */
#define I2C_I2CR_MSTA_MASK                       (0x01UL << I2C_I2CR_MSTA_SHIFT)                     /*!< I2C0_I2CR: MSTA Mask                    */
#define I2C_I2CR_MSTA_SHIFT                      5                                                   /*!< I2C0_I2CR: MSTA Position                */
#define I2C_I2CR_IIEN_MASK                       (0x01UL << I2C_I2CR_IIEN_SHIFT)                     /*!< I2C0_I2CR: IIEN Mask                    */
#define I2C_I2CR_IIEN_SHIFT                      6                                                   /*!< I2C0_I2CR: IIEN Position                */
#define I2C_I2CR_IEN_MASK                        (0x01UL << I2C_I2CR_IEN_SHIFT)                      /*!< I2C0_I2CR: IEN Mask                     */
#define I2C_I2CR_IEN_SHIFT                       7                                                   /*!< I2C0_I2CR: IEN Position                 */
/* ------- I2SR Bit Fields                          ------ */
#define I2C_I2SR_RXAK_MASK                       (0x01UL << I2C_I2SR_RXAK_SHIFT)                     /*!< I2C0_I2SR: RXAK Mask                    */
#define I2C_I2SR_RXAK_SHIFT                      0                                                   /*!< I2C0_I2SR: RXAK Position                */
#define I2C_I2SR_IIF_MASK                        (0x01UL << I2C_I2SR_IIF_SHIFT)                      /*!< I2C0_I2SR: IIF Mask                     */
#define I2C_I2SR_IIF_SHIFT                       1                                                   /*!< I2C0_I2SR: IIF Position                 */
#define I2C_I2SR_SRW_MASK                        (0x01UL << I2C_I2SR_SRW_SHIFT)                      /*!< I2C0_I2SR: SRW Mask                     */
#define I2C_I2SR_SRW_SHIFT                       2                                                   /*!< I2C0_I2SR: SRW Position                 */
#define I2C_I2SR_IAL_MASK                        (0x01UL << I2C_I2SR_IAL_SHIFT)                      /*!< I2C0_I2SR: IAL Mask                     */
#define I2C_I2SR_IAL_SHIFT                       4                                                   /*!< I2C0_I2SR: IAL Position                 */
#define I2C_I2SR_IBB_MASK                        (0x01UL << I2C_I2SR_IBB_SHIFT)                      /*!< I2C0_I2SR: IBB Mask                     */
#define I2C_I2SR_IBB_SHIFT                       5                                                   /*!< I2C0_I2SR: IBB Position                 */
#define I2C_I2SR_IAAS_MASK                       (0x01UL << I2C_I2SR_IAAS_SHIFT)                     /*!< I2C0_I2SR: IAAS Mask                    */
#define I2C_I2SR_IAAS_SHIFT                      6                                                   /*!< I2C0_I2SR: IAAS Position                */
#define I2C_I2SR_ICF_MASK                        (0x01UL << I2C_I2SR_ICF_SHIFT)                      /*!< I2C0_I2SR: ICF Mask                     */
#define I2C_I2SR_ICF_SHIFT                       7                                                   /*!< I2C0_I2SR: ICF Position                 */
/* ------- I2DR Bit Fields                          ------ */
#define I2C_I2DR_DATA_MASK                       (0xFFUL << I2C_I2DR_DATA_SHIFT)                     /*!< I2C0_I2DR: DATA Mask                    */
#define I2C_I2DR_DATA_SHIFT                      0                                                   /*!< I2C0_I2DR: DATA Position                */
#define I2C_I2DR_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2DR_DATA_SHIFT))&I2C_I2DR_DATA_MASK) /*!< I2C0_I2DR                               */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40000300UL
#define I2C0                           ((I2C_Type *) I2C0_BasePtr)
#define I2C0_BASE_PTR                  (I2C0)

/* ================================================================================ */
/* ================           INTC0 (file:MCF522xx_INTC0)          ================ */
/* ================================================================================ */

/**
 * @brief Interrupt Controller Module
 */
typedef struct {                                /*!<       INTC0 Structure                                              */
   __I  uint32_t  IPRH;                         /*!< 0000: Interrupt Pending Register High                              */
   __I  uint32_t  IPRL;                         /*!< 0004: Interrupt Pending Register Low                               */
   __IO uint32_t  IMRH;                         /*!< 0008: Interrupt Mask Register High                                 */
   __IO uint32_t  IMRL;                         /*!< 000C: Interrupt Mask Register Low                                  */
   __IO uint32_t  INTFRCH;                      /*!< 0010: Interrupt Force Register High                                */
   __IO uint32_t  INTFRCL;                      /*!< 0014: Interrupt Force Register Low                                 */
   __I  uint8_t   IRLR;                         /*!< 0018: Interrupt Request Level Register                             */
   __I  uint8_t   IACKLPR;                      /*!< 0019: Interrupt Acknowledge Level and Priority Register            */
   __I  uint8_t   RESERVED0[39];                /*!< 001A:                                                              */
   __I  uint8_t   ICR1;                         /*!< 0041: Interrupt Control Register 1                                 */
   __I  uint8_t   ICR2;                         /*!< 0042: Interrupt Control Register 2                                 */
   __I  uint8_t   ICR3;                         /*!< 0043: Interrupt Control Register 3                                 */
   __I  uint8_t   ICR4;                         /*!< 0044: Interrupt Control Register 4                                 */
   __I  uint8_t   ICR5;                         /*!< 0045: Interrupt Control Register 5                                 */
   __I  uint8_t   ICR6;                         /*!< 0046: Interrupt Control Register 6                                 */
   __I  uint8_t   ICR7;                         /*!< 0047: Interrupt Control Register 7                                 */
   __IO uint8_t   ICR8;                         /*!< 0048: Interrupt Control Register 8                                 */
   __IO uint8_t   ICR9;                         /*!< 0049: Interrupt Control Register 9                                 */
   __IO uint8_t   ICR10;                        /*!< 004A: Interrupt Control Register 10                                */
   __IO uint8_t   ICR11;                        /*!< 004B: Interrupt Control Register 11                                */
   __IO uint8_t   ICR12;                        /*!< 004C: Interrupt Control Register 12                                */
   __IO uint8_t   ICR13;                        /*!< 004D: Interrupt Control Register 13                                */
   __IO uint8_t   ICR14;                        /*!< 004E: Interrupt Control Register 14                                */
   __IO uint8_t   ICR15;                        /*!< 004F: Interrupt Control Register 15                                */
   __IO uint8_t   ICR16;                        /*!< 0050: Interrupt Control Register 16                                */
   __IO uint8_t   ICR17;                        /*!< 0051: Interrupt Control Register 17                                */
   __IO uint8_t   ICR18;                        /*!< 0052: Interrupt Control Register 18                                */
   __IO uint8_t   ICR19;                        /*!< 0053: Interrupt Control Register 19                                */
   __IO uint8_t   ICR20;                        /*!< 0054: Interrupt Control Register 20                                */
   __IO uint8_t   ICR21;                        /*!< 0055: Interrupt Control Register 21                                */
   __IO uint8_t   ICR22;                        /*!< 0056: Interrupt Control Register 22                                */
   __IO uint8_t   ICR23;                        /*!< 0057: Interrupt Control Register 23                                */
   __IO uint8_t   ICR24;                        /*!< 0058: Interrupt Control Register 24                                */
   __IO uint8_t   ICR25;                        /*!< 0059: Interrupt Control Register 25                                */
   __IO uint8_t   ICR26;                        /*!< 005A: Interrupt Control Register 26                                */
   __IO uint8_t   ICR27;                        /*!< 005B: Interrupt Control Register 27                                */
   __IO uint8_t   ICR28;                        /*!< 005C: Interrupt Control Register 28                                */
   __IO uint8_t   ICR29;                        /*!< 005D: Interrupt Control Register 29                                */
   __IO uint8_t   ICR30;                        /*!< 005E: Interrupt Control Register 30                                */
   __IO uint8_t   ICR31;                        /*!< 005F: Interrupt Control Register 31                                */
   __IO uint8_t   ICR32;                        /*!< 0060: Interrupt Control Register 32                                */
   __IO uint8_t   ICR33;                        /*!< 0061: Interrupt Control Register 33                                */
   __IO uint8_t   ICR34;                        /*!< 0062: Interrupt Control Register 34                                */
   __IO uint8_t   ICR35;                        /*!< 0063: Interrupt Control Register 35                                */
   __IO uint8_t   ICR36;                        /*!< 0064: Interrupt Control Register 36                                */
   __IO uint8_t   ICR37;                        /*!< 0065: Interrupt Control Register 37                                */
   __IO uint8_t   ICR38;                        /*!< 0066: Interrupt Control Register 38                                */
   __IO uint8_t   ICR39;                        /*!< 0067: Interrupt Control Register 39                                */
   __IO uint8_t   ICR40;                        /*!< 0068: Interrupt Control Register 40                                */
   __IO uint8_t   ICR41;                        /*!< 0069: Interrupt Control Register 41                                */
   __IO uint8_t   ICR42;                        /*!< 006A: Interrupt Control Register 42                                */
   __IO uint8_t   ICR43;                        /*!< 006B: Interrupt Control Register 43                                */
   __IO uint8_t   ICR44;                        /*!< 006C: Interrupt Control Register 44                                */
   __IO uint8_t   ICR45;                        /*!< 006D: Interrupt Control Register 45                                */
   __IO uint8_t   ICR46;                        /*!< 006E: Interrupt Control Register 46                                */
   __IO uint8_t   ICR47;                        /*!< 006F: Interrupt Control Register 47                                */
   __IO uint8_t   ICR48;                        /*!< 0070: Interrupt Control Register 48                                */
   __IO uint8_t   ICR49;                        /*!< 0071: Interrupt Control Register 49                                */
   __IO uint8_t   ICR50;                        /*!< 0072: Interrupt Control Register 50                                */
   __IO uint8_t   ICR51;                        /*!< 0073: Interrupt Control Register 51                                */
   __IO uint8_t   ICR52;                        /*!< 0074: Interrupt Control Register 52                                */
   __IO uint8_t   ICR53;                        /*!< 0075: Interrupt Control Register 53                                */
   __IO uint8_t   ICR54;                        /*!< 0076: Interrupt Control Register 54                                */
   __IO uint8_t   ICR55;                        /*!< 0077: Interrupt Control Register 55                                */
   __IO uint8_t   ICR56;                        /*!< 0078: Interrupt Control Register 56                                */
   __IO uint8_t   ICR57;                        /*!< 0079: Interrupt Control Register 57                                */
   __IO uint8_t   ICR58;                        /*!< 007A: Interrupt Control Register 58                                */
   __IO uint8_t   ICR59;                        /*!< 007B: Interrupt Control Register 59                                */
   __IO uint8_t   ICR60;                        /*!< 007C: Interrupt Control Register 60                                */
   __IO uint8_t   ICR61;                        /*!< 007D: Interrupt Control Register 61                                */
   __IO uint8_t   ICR62;                        /*!< 007E: Interrupt Control Register 62                                */
   __IO uint8_t   ICR63;                        /*!< 007F: Interrupt Control Register 63                                */
   __I  uint32_t  RESERVED1[24];                /*!< 0080:                                                              */
   __I  uint8_t   SWIACK;                       /*!< 00E0: Software IACK Register                                       */
   __I  uint8_t   RESERVED2[3];                 /*!< 00E1:                                                              */
   __I  uint8_t   L1IACK;                       /*!< 00E4: Level 1 IACK Register                                        */
   __I  uint8_t   RESERVED3[3];                 /*!< 00E4:                                                              */
   __I  uint8_t   L2IACK;                       /*!< 00E8: Level 2 IACK Register                                        */
   __I  uint8_t   RESERVED4[3];                 /*!< 00E7:                                                              */
   __I  uint8_t   L3IACK;                       /*!< 00EC: Level 3 IACK Register                                        */
   __I  uint8_t   RESERVED5[3];                 /*!< 00EB:                                                              */
   __I  uint8_t   L4IACK;                       /*!< 00F0: Level 4 IACK Register                                        */
   __I  uint8_t   RESERVED6[3];                 /*!< 00EF:                                                              */
   __I  uint8_t   L5IACK;                       /*!< 00F4: Level 5 IACK Register                                        */
   __I  uint8_t   RESERVED7[3];                 /*!< 00F3:                                                              */
   __I  uint8_t   L6IACK;                       /*!< 00F8: Level 6 IACK Register                                        */
   __I  uint8_t   RESERVED8[3];                 /*!< 00F7:                                                              */
   __I  uint8_t   L7IACK;                       /*!< 00FC: Level 7 IACK Register                                        */
   __I  uint8_t   RESERVED9[3];                 /*!< 00FB:                                                              */
} INTC_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'INTC0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- IPRH Bit Fields                          ------ */
#define INTC_IPRH_INT32_MASK                     (0x01UL << INTC_IPRH_INT32_SHIFT)                   /*!< INTC0_IPRH: INT32 Mask                  */
#define INTC_IPRH_INT32_SHIFT                    0                                                   /*!< INTC0_IPRH: INT32 Position              */
#define INTC_IPRH_INT33_MASK                     (0x01UL << INTC_IPRH_INT33_SHIFT)                   /*!< INTC0_IPRH: INT33 Mask                  */
#define INTC_IPRH_INT33_SHIFT                    1                                                   /*!< INTC0_IPRH: INT33 Position              */
#define INTC_IPRH_INT34_MASK                     (0x01UL << INTC_IPRH_INT34_SHIFT)                   /*!< INTC0_IPRH: INT34 Mask                  */
#define INTC_IPRH_INT34_SHIFT                    2                                                   /*!< INTC0_IPRH: INT34 Position              */
#define INTC_IPRH_INT35_MASK                     (0x01UL << INTC_IPRH_INT35_SHIFT)                   /*!< INTC0_IPRH: INT35 Mask                  */
#define INTC_IPRH_INT35_SHIFT                    3                                                   /*!< INTC0_IPRH: INT35 Position              */
#define INTC_IPRH_INT36_MASK                     (0x01UL << INTC_IPRH_INT36_SHIFT)                   /*!< INTC0_IPRH: INT36 Mask                  */
#define INTC_IPRH_INT36_SHIFT                    4                                                   /*!< INTC0_IPRH: INT36 Position              */
#define INTC_IPRH_INT37_MASK                     (0x01UL << INTC_IPRH_INT37_SHIFT)                   /*!< INTC0_IPRH: INT37 Mask                  */
#define INTC_IPRH_INT37_SHIFT                    5                                                   /*!< INTC0_IPRH: INT37 Position              */
#define INTC_IPRH_INT38_MASK                     (0x01UL << INTC_IPRH_INT38_SHIFT)                   /*!< INTC0_IPRH: INT38 Mask                  */
#define INTC_IPRH_INT38_SHIFT                    6                                                   /*!< INTC0_IPRH: INT38 Position              */
#define INTC_IPRH_INT39_MASK                     (0x01UL << INTC_IPRH_INT39_SHIFT)                   /*!< INTC0_IPRH: INT39 Mask                  */
#define INTC_IPRH_INT39_SHIFT                    7                                                   /*!< INTC0_IPRH: INT39 Position              */
#define INTC_IPRH_INT40_MASK                     (0x01UL << INTC_IPRH_INT40_SHIFT)                   /*!< INTC0_IPRH: INT40 Mask                  */
#define INTC_IPRH_INT40_SHIFT                    8                                                   /*!< INTC0_IPRH: INT40 Position              */
#define INTC_IPRH_INT41_MASK                     (0x01UL << INTC_IPRH_INT41_SHIFT)                   /*!< INTC0_IPRH: INT41 Mask                  */
#define INTC_IPRH_INT41_SHIFT                    9                                                   /*!< INTC0_IPRH: INT41 Position              */
#define INTC_IPRH_INT42_MASK                     (0x01UL << INTC_IPRH_INT42_SHIFT)                   /*!< INTC0_IPRH: INT42 Mask                  */
#define INTC_IPRH_INT42_SHIFT                    10                                                  /*!< INTC0_IPRH: INT42 Position              */
#define INTC_IPRH_INT43_MASK                     (0x01UL << INTC_IPRH_INT43_SHIFT)                   /*!< INTC0_IPRH: INT43 Mask                  */
#define INTC_IPRH_INT43_SHIFT                    11                                                  /*!< INTC0_IPRH: INT43 Position              */
#define INTC_IPRH_INT44_MASK                     (0x01UL << INTC_IPRH_INT44_SHIFT)                   /*!< INTC0_IPRH: INT44 Mask                  */
#define INTC_IPRH_INT44_SHIFT                    12                                                  /*!< INTC0_IPRH: INT44 Position              */
#define INTC_IPRH_INT45_MASK                     (0x01UL << INTC_IPRH_INT45_SHIFT)                   /*!< INTC0_IPRH: INT45 Mask                  */
#define INTC_IPRH_INT45_SHIFT                    13                                                  /*!< INTC0_IPRH: INT45 Position              */
#define INTC_IPRH_INT46_MASK                     (0x01UL << INTC_IPRH_INT46_SHIFT)                   /*!< INTC0_IPRH: INT46 Mask                  */
#define INTC_IPRH_INT46_SHIFT                    14                                                  /*!< INTC0_IPRH: INT46 Position              */
#define INTC_IPRH_INT47_MASK                     (0x01UL << INTC_IPRH_INT47_SHIFT)                   /*!< INTC0_IPRH: INT47 Mask                  */
#define INTC_IPRH_INT47_SHIFT                    15                                                  /*!< INTC0_IPRH: INT47 Position              */
#define INTC_IPRH_INT48_MASK                     (0x01UL << INTC_IPRH_INT48_SHIFT)                   /*!< INTC0_IPRH: INT48 Mask                  */
#define INTC_IPRH_INT48_SHIFT                    16                                                  /*!< INTC0_IPRH: INT48 Position              */
#define INTC_IPRH_INT49_MASK                     (0x01UL << INTC_IPRH_INT49_SHIFT)                   /*!< INTC0_IPRH: INT49 Mask                  */
#define INTC_IPRH_INT49_SHIFT                    17                                                  /*!< INTC0_IPRH: INT49 Position              */
#define INTC_IPRH_INT50_MASK                     (0x01UL << INTC_IPRH_INT50_SHIFT)                   /*!< INTC0_IPRH: INT50 Mask                  */
#define INTC_IPRH_INT50_SHIFT                    18                                                  /*!< INTC0_IPRH: INT50 Position              */
#define INTC_IPRH_INT51_MASK                     (0x01UL << INTC_IPRH_INT51_SHIFT)                   /*!< INTC0_IPRH: INT51 Mask                  */
#define INTC_IPRH_INT51_SHIFT                    19                                                  /*!< INTC0_IPRH: INT51 Position              */
#define INTC_IPRH_INT52_MASK                     (0x01UL << INTC_IPRH_INT52_SHIFT)                   /*!< INTC0_IPRH: INT52 Mask                  */
#define INTC_IPRH_INT52_SHIFT                    20                                                  /*!< INTC0_IPRH: INT52 Position              */
#define INTC_IPRH_INT53_MASK                     (0x01UL << INTC_IPRH_INT53_SHIFT)                   /*!< INTC0_IPRH: INT53 Mask                  */
#define INTC_IPRH_INT53_SHIFT                    21                                                  /*!< INTC0_IPRH: INT53 Position              */
#define INTC_IPRH_INT54_MASK                     (0x01UL << INTC_IPRH_INT54_SHIFT)                   /*!< INTC0_IPRH: INT54 Mask                  */
#define INTC_IPRH_INT54_SHIFT                    22                                                  /*!< INTC0_IPRH: INT54 Position              */
#define INTC_IPRH_INT55_MASK                     (0x01UL << INTC_IPRH_INT55_SHIFT)                   /*!< INTC0_IPRH: INT55 Mask                  */
#define INTC_IPRH_INT55_SHIFT                    23                                                  /*!< INTC0_IPRH: INT55 Position              */
#define INTC_IPRH_INT56_MASK                     (0x01UL << INTC_IPRH_INT56_SHIFT)                   /*!< INTC0_IPRH: INT56 Mask                  */
#define INTC_IPRH_INT56_SHIFT                    24                                                  /*!< INTC0_IPRH: INT56 Position              */
#define INTC_IPRH_INT57_MASK                     (0x01UL << INTC_IPRH_INT57_SHIFT)                   /*!< INTC0_IPRH: INT57 Mask                  */
#define INTC_IPRH_INT57_SHIFT                    25                                                  /*!< INTC0_IPRH: INT57 Position              */
#define INTC_IPRH_INT58_MASK                     (0x01UL << INTC_IPRH_INT58_SHIFT)                   /*!< INTC0_IPRH: INT58 Mask                  */
#define INTC_IPRH_INT58_SHIFT                    26                                                  /*!< INTC0_IPRH: INT58 Position              */
#define INTC_IPRH_INT59_MASK                     (0x01UL << INTC_IPRH_INT59_SHIFT)                   /*!< INTC0_IPRH: INT59 Mask                  */
#define INTC_IPRH_INT59_SHIFT                    27                                                  /*!< INTC0_IPRH: INT59 Position              */
#define INTC_IPRH_INT60_MASK                     (0x01UL << INTC_IPRH_INT60_SHIFT)                   /*!< INTC0_IPRH: INT60 Mask                  */
#define INTC_IPRH_INT60_SHIFT                    28                                                  /*!< INTC0_IPRH: INT60 Position              */
#define INTC_IPRH_INT61_MASK                     (0x01UL << INTC_IPRH_INT61_SHIFT)                   /*!< INTC0_IPRH: INT61 Mask                  */
#define INTC_IPRH_INT61_SHIFT                    29                                                  /*!< INTC0_IPRH: INT61 Position              */
#define INTC_IPRH_INT62_MASK                     (0x01UL << INTC_IPRH_INT62_SHIFT)                   /*!< INTC0_IPRH: INT62 Mask                  */
#define INTC_IPRH_INT62_SHIFT                    30                                                  /*!< INTC0_IPRH: INT62 Position              */
#define INTC_IPRH_INT63_MASK                     (0x01UL << INTC_IPRH_INT63_SHIFT)                   /*!< INTC0_IPRH: INT63 Mask                  */
#define INTC_IPRH_INT63_SHIFT                    31                                                  /*!< INTC0_IPRH: INT63 Position              */
/* ------- IPRL Bit Fields                          ------ */
#define INTC_IPRL_INT1_MASK                      (0x01UL << INTC_IPRL_INT1_SHIFT)                    /*!< INTC0_IPRL: INT1 Mask                   */
#define INTC_IPRL_INT1_SHIFT                     1                                                   /*!< INTC0_IPRL: INT1 Position               */
#define INTC_IPRL_INT2_MASK                      (0x01UL << INTC_IPRL_INT2_SHIFT)                    /*!< INTC0_IPRL: INT2 Mask                   */
#define INTC_IPRL_INT2_SHIFT                     2                                                   /*!< INTC0_IPRL: INT2 Position               */
#define INTC_IPRL_INT3_MASK                      (0x01UL << INTC_IPRL_INT3_SHIFT)                    /*!< INTC0_IPRL: INT3 Mask                   */
#define INTC_IPRL_INT3_SHIFT                     3                                                   /*!< INTC0_IPRL: INT3 Position               */
#define INTC_IPRL_INT4_MASK                      (0x01UL << INTC_IPRL_INT4_SHIFT)                    /*!< INTC0_IPRL: INT4 Mask                   */
#define INTC_IPRL_INT4_SHIFT                     4                                                   /*!< INTC0_IPRL: INT4 Position               */
#define INTC_IPRL_INT5_MASK                      (0x01UL << INTC_IPRL_INT5_SHIFT)                    /*!< INTC0_IPRL: INT5 Mask                   */
#define INTC_IPRL_INT5_SHIFT                     5                                                   /*!< INTC0_IPRL: INT5 Position               */
#define INTC_IPRL_INT6_MASK                      (0x01UL << INTC_IPRL_INT6_SHIFT)                    /*!< INTC0_IPRL: INT6 Mask                   */
#define INTC_IPRL_INT6_SHIFT                     6                                                   /*!< INTC0_IPRL: INT6 Position               */
#define INTC_IPRL_INT7_MASK                      (0x01UL << INTC_IPRL_INT7_SHIFT)                    /*!< INTC0_IPRL: INT7 Mask                   */
#define INTC_IPRL_INT7_SHIFT                     7                                                   /*!< INTC0_IPRL: INT7 Position               */
#define INTC_IPRL_INT8_MASK                      (0x01UL << INTC_IPRL_INT8_SHIFT)                    /*!< INTC0_IPRL: INT8 Mask                   */
#define INTC_IPRL_INT8_SHIFT                     8                                                   /*!< INTC0_IPRL: INT8 Position               */
#define INTC_IPRL_INT9_MASK                      (0x01UL << INTC_IPRL_INT9_SHIFT)                    /*!< INTC0_IPRL: INT9 Mask                   */
#define INTC_IPRL_INT9_SHIFT                     9                                                   /*!< INTC0_IPRL: INT9 Position               */
#define INTC_IPRL_INT10_MASK                     (0x01UL << INTC_IPRL_INT10_SHIFT)                   /*!< INTC0_IPRL: INT10 Mask                  */
#define INTC_IPRL_INT10_SHIFT                    10                                                  /*!< INTC0_IPRL: INT10 Position              */
#define INTC_IPRL_INT11_MASK                     (0x01UL << INTC_IPRL_INT11_SHIFT)                   /*!< INTC0_IPRL: INT11 Mask                  */
#define INTC_IPRL_INT11_SHIFT                    11                                                  /*!< INTC0_IPRL: INT11 Position              */
#define INTC_IPRL_INT12_MASK                     (0x01UL << INTC_IPRL_INT12_SHIFT)                   /*!< INTC0_IPRL: INT12 Mask                  */
#define INTC_IPRL_INT12_SHIFT                    12                                                  /*!< INTC0_IPRL: INT12 Position              */
#define INTC_IPRL_INT13_MASK                     (0x01UL << INTC_IPRL_INT13_SHIFT)                   /*!< INTC0_IPRL: INT13 Mask                  */
#define INTC_IPRL_INT13_SHIFT                    13                                                  /*!< INTC0_IPRL: INT13 Position              */
#define INTC_IPRL_INT14_MASK                     (0x01UL << INTC_IPRL_INT14_SHIFT)                   /*!< INTC0_IPRL: INT14 Mask                  */
#define INTC_IPRL_INT14_SHIFT                    14                                                  /*!< INTC0_IPRL: INT14 Position              */
#define INTC_IPRL_INT15_MASK                     (0x01UL << INTC_IPRL_INT15_SHIFT)                   /*!< INTC0_IPRL: INT15 Mask                  */
#define INTC_IPRL_INT15_SHIFT                    15                                                  /*!< INTC0_IPRL: INT15 Position              */
#define INTC_IPRL_INT16_MASK                     (0x01UL << INTC_IPRL_INT16_SHIFT)                   /*!< INTC0_IPRL: INT16 Mask                  */
#define INTC_IPRL_INT16_SHIFT                    16                                                  /*!< INTC0_IPRL: INT16 Position              */
#define INTC_IPRL_INT17_MASK                     (0x01UL << INTC_IPRL_INT17_SHIFT)                   /*!< INTC0_IPRL: INT17 Mask                  */
#define INTC_IPRL_INT17_SHIFT                    17                                                  /*!< INTC0_IPRL: INT17 Position              */
#define INTC_IPRL_INT18_MASK                     (0x01UL << INTC_IPRL_INT18_SHIFT)                   /*!< INTC0_IPRL: INT18 Mask                  */
#define INTC_IPRL_INT18_SHIFT                    18                                                  /*!< INTC0_IPRL: INT18 Position              */
#define INTC_IPRL_INT19_MASK                     (0x01UL << INTC_IPRL_INT19_SHIFT)                   /*!< INTC0_IPRL: INT19 Mask                  */
#define INTC_IPRL_INT19_SHIFT                    19                                                  /*!< INTC0_IPRL: INT19 Position              */
#define INTC_IPRL_INT20_MASK                     (0x01UL << INTC_IPRL_INT20_SHIFT)                   /*!< INTC0_IPRL: INT20 Mask                  */
#define INTC_IPRL_INT20_SHIFT                    20                                                  /*!< INTC0_IPRL: INT20 Position              */
#define INTC_IPRL_INT21_MASK                     (0x01UL << INTC_IPRL_INT21_SHIFT)                   /*!< INTC0_IPRL: INT21 Mask                  */
#define INTC_IPRL_INT21_SHIFT                    21                                                  /*!< INTC0_IPRL: INT21 Position              */
#define INTC_IPRL_INT22_MASK                     (0x01UL << INTC_IPRL_INT22_SHIFT)                   /*!< INTC0_IPRL: INT22 Mask                  */
#define INTC_IPRL_INT22_SHIFT                    22                                                  /*!< INTC0_IPRL: INT22 Position              */
#define INTC_IPRL_INT23_MASK                     (0x01UL << INTC_IPRL_INT23_SHIFT)                   /*!< INTC0_IPRL: INT23 Mask                  */
#define INTC_IPRL_INT23_SHIFT                    23                                                  /*!< INTC0_IPRL: INT23 Position              */
#define INTC_IPRL_INT24_MASK                     (0x01UL << INTC_IPRL_INT24_SHIFT)                   /*!< INTC0_IPRL: INT24 Mask                  */
#define INTC_IPRL_INT24_SHIFT                    24                                                  /*!< INTC0_IPRL: INT24 Position              */
#define INTC_IPRL_INT25_MASK                     (0x01UL << INTC_IPRL_INT25_SHIFT)                   /*!< INTC0_IPRL: INT25 Mask                  */
#define INTC_IPRL_INT25_SHIFT                    25                                                  /*!< INTC0_IPRL: INT25 Position              */
#define INTC_IPRL_INT26_MASK                     (0x01UL << INTC_IPRL_INT26_SHIFT)                   /*!< INTC0_IPRL: INT26 Mask                  */
#define INTC_IPRL_INT26_SHIFT                    26                                                  /*!< INTC0_IPRL: INT26 Position              */
#define INTC_IPRL_INT27_MASK                     (0x01UL << INTC_IPRL_INT27_SHIFT)                   /*!< INTC0_IPRL: INT27 Mask                  */
#define INTC_IPRL_INT27_SHIFT                    27                                                  /*!< INTC0_IPRL: INT27 Position              */
#define INTC_IPRL_INT28_MASK                     (0x01UL << INTC_IPRL_INT28_SHIFT)                   /*!< INTC0_IPRL: INT28 Mask                  */
#define INTC_IPRL_INT28_SHIFT                    28                                                  /*!< INTC0_IPRL: INT28 Position              */
#define INTC_IPRL_INT29_MASK                     (0x01UL << INTC_IPRL_INT29_SHIFT)                   /*!< INTC0_IPRL: INT29 Mask                  */
#define INTC_IPRL_INT29_SHIFT                    29                                                  /*!< INTC0_IPRL: INT29 Position              */
#define INTC_IPRL_INT30_MASK                     (0x01UL << INTC_IPRL_INT30_SHIFT)                   /*!< INTC0_IPRL: INT30 Mask                  */
#define INTC_IPRL_INT30_SHIFT                    30                                                  /*!< INTC0_IPRL: INT30 Position              */
#define INTC_IPRL_INT31_MASK                     (0x01UL << INTC_IPRL_INT31_SHIFT)                   /*!< INTC0_IPRL: INT31 Mask                  */
#define INTC_IPRL_INT31_SHIFT                    31                                                  /*!< INTC0_IPRL: INT31 Position              */
/* ------- IMRH Bit Fields                          ------ */
#define INTC_IMRH_MASK32_MASK                    (0x01UL << INTC_IMRH_MASK32_SHIFT)                  /*!< INTC0_IMRH: MASK32 Mask                 */
#define INTC_IMRH_MASK32_SHIFT                   0                                                   /*!< INTC0_IMRH: MASK32 Position             */
#define INTC_IMRH_MASK33_MASK                    (0x01UL << INTC_IMRH_MASK33_SHIFT)                  /*!< INTC0_IMRH: MASK33 Mask                 */
#define INTC_IMRH_MASK33_SHIFT                   1                                                   /*!< INTC0_IMRH: MASK33 Position             */
#define INTC_IMRH_MASK34_MASK                    (0x01UL << INTC_IMRH_MASK34_SHIFT)                  /*!< INTC0_IMRH: MASK34 Mask                 */
#define INTC_IMRH_MASK34_SHIFT                   2                                                   /*!< INTC0_IMRH: MASK34 Position             */
#define INTC_IMRH_MASK35_MASK                    (0x01UL << INTC_IMRH_MASK35_SHIFT)                  /*!< INTC0_IMRH: MASK35 Mask                 */
#define INTC_IMRH_MASK35_SHIFT                   3                                                   /*!< INTC0_IMRH: MASK35 Position             */
#define INTC_IMRH_MASK36_MASK                    (0x01UL << INTC_IMRH_MASK36_SHIFT)                  /*!< INTC0_IMRH: MASK36 Mask                 */
#define INTC_IMRH_MASK36_SHIFT                   4                                                   /*!< INTC0_IMRH: MASK36 Position             */
#define INTC_IMRH_MASK37_MASK                    (0x01UL << INTC_IMRH_MASK37_SHIFT)                  /*!< INTC0_IMRH: MASK37 Mask                 */
#define INTC_IMRH_MASK37_SHIFT                   5                                                   /*!< INTC0_IMRH: MASK37 Position             */
#define INTC_IMRH_MASK38_MASK                    (0x01UL << INTC_IMRH_MASK38_SHIFT)                  /*!< INTC0_IMRH: MASK38 Mask                 */
#define INTC_IMRH_MASK38_SHIFT                   6                                                   /*!< INTC0_IMRH: MASK38 Position             */
#define INTC_IMRH_MASK39_MASK                    (0x01UL << INTC_IMRH_MASK39_SHIFT)                  /*!< INTC0_IMRH: MASK39 Mask                 */
#define INTC_IMRH_MASK39_SHIFT                   7                                                   /*!< INTC0_IMRH: MASK39 Position             */
#define INTC_IMRH_MASK40_MASK                    (0x01UL << INTC_IMRH_MASK40_SHIFT)                  /*!< INTC0_IMRH: MASK40 Mask                 */
#define INTC_IMRH_MASK40_SHIFT                   8                                                   /*!< INTC0_IMRH: MASK40 Position             */
#define INTC_IMRH_MASK41_MASK                    (0x01UL << INTC_IMRH_MASK41_SHIFT)                  /*!< INTC0_IMRH: MASK41 Mask                 */
#define INTC_IMRH_MASK41_SHIFT                   9                                                   /*!< INTC0_IMRH: MASK41 Position             */
#define INTC_IMRH_MASK42_MASK                    (0x01UL << INTC_IMRH_MASK42_SHIFT)                  /*!< INTC0_IMRH: MASK42 Mask                 */
#define INTC_IMRH_MASK42_SHIFT                   10                                                  /*!< INTC0_IMRH: MASK42 Position             */
#define INTC_IMRH_MASK43_MASK                    (0x01UL << INTC_IMRH_MASK43_SHIFT)                  /*!< INTC0_IMRH: MASK43 Mask                 */
#define INTC_IMRH_MASK43_SHIFT                   11                                                  /*!< INTC0_IMRH: MASK43 Position             */
#define INTC_IMRH_MASK44_MASK                    (0x01UL << INTC_IMRH_MASK44_SHIFT)                  /*!< INTC0_IMRH: MASK44 Mask                 */
#define INTC_IMRH_MASK44_SHIFT                   12                                                  /*!< INTC0_IMRH: MASK44 Position             */
#define INTC_IMRH_MASK45_MASK                    (0x01UL << INTC_IMRH_MASK45_SHIFT)                  /*!< INTC0_IMRH: MASK45 Mask                 */
#define INTC_IMRH_MASK45_SHIFT                   13                                                  /*!< INTC0_IMRH: MASK45 Position             */
#define INTC_IMRH_MASK46_MASK                    (0x01UL << INTC_IMRH_MASK46_SHIFT)                  /*!< INTC0_IMRH: MASK46 Mask                 */
#define INTC_IMRH_MASK46_SHIFT                   14                                                  /*!< INTC0_IMRH: MASK46 Position             */
#define INTC_IMRH_MASK47_MASK                    (0x01UL << INTC_IMRH_MASK47_SHIFT)                  /*!< INTC0_IMRH: MASK47 Mask                 */
#define INTC_IMRH_MASK47_SHIFT                   15                                                  /*!< INTC0_IMRH: MASK47 Position             */
#define INTC_IMRH_MASK48_MASK                    (0x01UL << INTC_IMRH_MASK48_SHIFT)                  /*!< INTC0_IMRH: MASK48 Mask                 */
#define INTC_IMRH_MASK48_SHIFT                   16                                                  /*!< INTC0_IMRH: MASK48 Position             */
#define INTC_IMRH_MASK49_MASK                    (0x01UL << INTC_IMRH_MASK49_SHIFT)                  /*!< INTC0_IMRH: MASK49 Mask                 */
#define INTC_IMRH_MASK49_SHIFT                   17                                                  /*!< INTC0_IMRH: MASK49 Position             */
#define INTC_IMRH_MASK50_MASK                    (0x01UL << INTC_IMRH_MASK50_SHIFT)                  /*!< INTC0_IMRH: MASK50 Mask                 */
#define INTC_IMRH_MASK50_SHIFT                   18                                                  /*!< INTC0_IMRH: MASK50 Position             */
#define INTC_IMRH_MASK51_MASK                    (0x01UL << INTC_IMRH_MASK51_SHIFT)                  /*!< INTC0_IMRH: MASK51 Mask                 */
#define INTC_IMRH_MASK51_SHIFT                   19                                                  /*!< INTC0_IMRH: MASK51 Position             */
#define INTC_IMRH_MASK52_MASK                    (0x01UL << INTC_IMRH_MASK52_SHIFT)                  /*!< INTC0_IMRH: MASK52 Mask                 */
#define INTC_IMRH_MASK52_SHIFT                   20                                                  /*!< INTC0_IMRH: MASK52 Position             */
#define INTC_IMRH_MASK53_MASK                    (0x01UL << INTC_IMRH_MASK53_SHIFT)                  /*!< INTC0_IMRH: MASK53 Mask                 */
#define INTC_IMRH_MASK53_SHIFT                   21                                                  /*!< INTC0_IMRH: MASK53 Position             */
#define INTC_IMRH_MASK54_MASK                    (0x01UL << INTC_IMRH_MASK54_SHIFT)                  /*!< INTC0_IMRH: MASK54 Mask                 */
#define INTC_IMRH_MASK54_SHIFT                   22                                                  /*!< INTC0_IMRH: MASK54 Position             */
#define INTC_IMRH_MASK55_MASK                    (0x01UL << INTC_IMRH_MASK55_SHIFT)                  /*!< INTC0_IMRH: MASK55 Mask                 */
#define INTC_IMRH_MASK55_SHIFT                   23                                                  /*!< INTC0_IMRH: MASK55 Position             */
#define INTC_IMRH_MASK56_MASK                    (0x01UL << INTC_IMRH_MASK56_SHIFT)                  /*!< INTC0_IMRH: MASK56 Mask                 */
#define INTC_IMRH_MASK56_SHIFT                   24                                                  /*!< INTC0_IMRH: MASK56 Position             */
#define INTC_IMRH_MASK57_MASK                    (0x01UL << INTC_IMRH_MASK57_SHIFT)                  /*!< INTC0_IMRH: MASK57 Mask                 */
#define INTC_IMRH_MASK57_SHIFT                   25                                                  /*!< INTC0_IMRH: MASK57 Position             */
#define INTC_IMRH_MASK58_MASK                    (0x01UL << INTC_IMRH_MASK58_SHIFT)                  /*!< INTC0_IMRH: MASK58 Mask                 */
#define INTC_IMRH_MASK58_SHIFT                   26                                                  /*!< INTC0_IMRH: MASK58 Position             */
#define INTC_IMRH_MASK59_MASK                    (0x01UL << INTC_IMRH_MASK59_SHIFT)                  /*!< INTC0_IMRH: MASK59 Mask                 */
#define INTC_IMRH_MASK59_SHIFT                   27                                                  /*!< INTC0_IMRH: MASK59 Position             */
#define INTC_IMRH_MASK60_MASK                    (0x01UL << INTC_IMRH_MASK60_SHIFT)                  /*!< INTC0_IMRH: MASK60 Mask                 */
#define INTC_IMRH_MASK60_SHIFT                   28                                                  /*!< INTC0_IMRH: MASK60 Position             */
#define INTC_IMRH_MASK61_MASK                    (0x01UL << INTC_IMRH_MASK61_SHIFT)                  /*!< INTC0_IMRH: MASK61 Mask                 */
#define INTC_IMRH_MASK61_SHIFT                   29                                                  /*!< INTC0_IMRH: MASK61 Position             */
#define INTC_IMRH_MASK62_MASK                    (0x01UL << INTC_IMRH_MASK62_SHIFT)                  /*!< INTC0_IMRH: MASK62 Mask                 */
#define INTC_IMRH_MASK62_SHIFT                   30                                                  /*!< INTC0_IMRH: MASK62 Position             */
#define INTC_IMRH_MASK63_MASK                    (0x01UL << INTC_IMRH_MASK63_SHIFT)                  /*!< INTC0_IMRH: MASK63 Mask                 */
#define INTC_IMRH_MASK63_SHIFT                   31                                                  /*!< INTC0_IMRH: MASK63 Position             */
/* ------- IMRL Bit Fields                          ------ */
#define INTC_IMRL_MASKALL_MASK                   (0x01UL << INTC_IMRL_MASKALL_SHIFT)                 /*!< INTC0_IMRL: MASKALL Mask                */
#define INTC_IMRL_MASKALL_SHIFT                  0                                                   /*!< INTC0_IMRL: MASKALL Position            */
#define INTC_IMRL_MASK1_MASK                     (0x01UL << INTC_IMRL_MASK1_SHIFT)                   /*!< INTC0_IMRL: MASK1 Mask                  */
#define INTC_IMRL_MASK1_SHIFT                    1                                                   /*!< INTC0_IMRL: MASK1 Position              */
#define INTC_IMRL_MASK2_MASK                     (0x01UL << INTC_IMRL_MASK2_SHIFT)                   /*!< INTC0_IMRL: MASK2 Mask                  */
#define INTC_IMRL_MASK2_SHIFT                    2                                                   /*!< INTC0_IMRL: MASK2 Position              */
#define INTC_IMRL_MASK3_MASK                     (0x01UL << INTC_IMRL_MASK3_SHIFT)                   /*!< INTC0_IMRL: MASK3 Mask                  */
#define INTC_IMRL_MASK3_SHIFT                    3                                                   /*!< INTC0_IMRL: MASK3 Position              */
#define INTC_IMRL_MASK4_MASK                     (0x01UL << INTC_IMRL_MASK4_SHIFT)                   /*!< INTC0_IMRL: MASK4 Mask                  */
#define INTC_IMRL_MASK4_SHIFT                    4                                                   /*!< INTC0_IMRL: MASK4 Position              */
#define INTC_IMRL_MASK5_MASK                     (0x01UL << INTC_IMRL_MASK5_SHIFT)                   /*!< INTC0_IMRL: MASK5 Mask                  */
#define INTC_IMRL_MASK5_SHIFT                    5                                                   /*!< INTC0_IMRL: MASK5 Position              */
#define INTC_IMRL_MASK6_MASK                     (0x01UL << INTC_IMRL_MASK6_SHIFT)                   /*!< INTC0_IMRL: MASK6 Mask                  */
#define INTC_IMRL_MASK6_SHIFT                    6                                                   /*!< INTC0_IMRL: MASK6 Position              */
#define INTC_IMRL_MASK7_MASK                     (0x01UL << INTC_IMRL_MASK7_SHIFT)                   /*!< INTC0_IMRL: MASK7 Mask                  */
#define INTC_IMRL_MASK7_SHIFT                    7                                                   /*!< INTC0_IMRL: MASK7 Position              */
#define INTC_IMRL_MASK8_MASK                     (0x01UL << INTC_IMRL_MASK8_SHIFT)                   /*!< INTC0_IMRL: MASK8 Mask                  */
#define INTC_IMRL_MASK8_SHIFT                    8                                                   /*!< INTC0_IMRL: MASK8 Position              */
#define INTC_IMRL_MASK9_MASK                     (0x01UL << INTC_IMRL_MASK9_SHIFT)                   /*!< INTC0_IMRL: MASK9 Mask                  */
#define INTC_IMRL_MASK9_SHIFT                    9                                                   /*!< INTC0_IMRL: MASK9 Position              */
#define INTC_IMRL_MASK10_MASK                    (0x01UL << INTC_IMRL_MASK10_SHIFT)                  /*!< INTC0_IMRL: MASK10 Mask                 */
#define INTC_IMRL_MASK10_SHIFT                   10                                                  /*!< INTC0_IMRL: MASK10 Position             */
#define INTC_IMRL_MASK11_MASK                    (0x01UL << INTC_IMRL_MASK11_SHIFT)                  /*!< INTC0_IMRL: MASK11 Mask                 */
#define INTC_IMRL_MASK11_SHIFT                   11                                                  /*!< INTC0_IMRL: MASK11 Position             */
#define INTC_IMRL_MASK12_MASK                    (0x01UL << INTC_IMRL_MASK12_SHIFT)                  /*!< INTC0_IMRL: MASK12 Mask                 */
#define INTC_IMRL_MASK12_SHIFT                   12                                                  /*!< INTC0_IMRL: MASK12 Position             */
#define INTC_IMRL_MASK13_MASK                    (0x01UL << INTC_IMRL_MASK13_SHIFT)                  /*!< INTC0_IMRL: MASK13 Mask                 */
#define INTC_IMRL_MASK13_SHIFT                   13                                                  /*!< INTC0_IMRL: MASK13 Position             */
#define INTC_IMRL_MASK14_MASK                    (0x01UL << INTC_IMRL_MASK14_SHIFT)                  /*!< INTC0_IMRL: MASK14 Mask                 */
#define INTC_IMRL_MASK14_SHIFT                   14                                                  /*!< INTC0_IMRL: MASK14 Position             */
#define INTC_IMRL_MASK15_MASK                    (0x01UL << INTC_IMRL_MASK15_SHIFT)                  /*!< INTC0_IMRL: MASK15 Mask                 */
#define INTC_IMRL_MASK15_SHIFT                   15                                                  /*!< INTC0_IMRL: MASK15 Position             */
#define INTC_IMRL_MASK16_MASK                    (0x01UL << INTC_IMRL_MASK16_SHIFT)                  /*!< INTC0_IMRL: MASK16 Mask                 */
#define INTC_IMRL_MASK16_SHIFT                   16                                                  /*!< INTC0_IMRL: MASK16 Position             */
#define INTC_IMRL_MASK17_MASK                    (0x01UL << INTC_IMRL_MASK17_SHIFT)                  /*!< INTC0_IMRL: MASK17 Mask                 */
#define INTC_IMRL_MASK17_SHIFT                   17                                                  /*!< INTC0_IMRL: MASK17 Position             */
#define INTC_IMRL_MASK18_MASK                    (0x01UL << INTC_IMRL_MASK18_SHIFT)                  /*!< INTC0_IMRL: MASK18 Mask                 */
#define INTC_IMRL_MASK18_SHIFT                   18                                                  /*!< INTC0_IMRL: MASK18 Position             */
#define INTC_IMRL_MASK19_MASK                    (0x01UL << INTC_IMRL_MASK19_SHIFT)                  /*!< INTC0_IMRL: MASK19 Mask                 */
#define INTC_IMRL_MASK19_SHIFT                   19                                                  /*!< INTC0_IMRL: MASK19 Position             */
#define INTC_IMRL_MASK20_MASK                    (0x01UL << INTC_IMRL_MASK20_SHIFT)                  /*!< INTC0_IMRL: MASK20 Mask                 */
#define INTC_IMRL_MASK20_SHIFT                   20                                                  /*!< INTC0_IMRL: MASK20 Position             */
#define INTC_IMRL_MASK21_MASK                    (0x01UL << INTC_IMRL_MASK21_SHIFT)                  /*!< INTC0_IMRL: MASK21 Mask                 */
#define INTC_IMRL_MASK21_SHIFT                   21                                                  /*!< INTC0_IMRL: MASK21 Position             */
#define INTC_IMRL_MASK22_MASK                    (0x01UL << INTC_IMRL_MASK22_SHIFT)                  /*!< INTC0_IMRL: MASK22 Mask                 */
#define INTC_IMRL_MASK22_SHIFT                   22                                                  /*!< INTC0_IMRL: MASK22 Position             */
#define INTC_IMRL_MASK23_MASK                    (0x01UL << INTC_IMRL_MASK23_SHIFT)                  /*!< INTC0_IMRL: MASK23 Mask                 */
#define INTC_IMRL_MASK23_SHIFT                   23                                                  /*!< INTC0_IMRL: MASK23 Position             */
#define INTC_IMRL_MASK24_MASK                    (0x01UL << INTC_IMRL_MASK24_SHIFT)                  /*!< INTC0_IMRL: MASK24 Mask                 */
#define INTC_IMRL_MASK24_SHIFT                   24                                                  /*!< INTC0_IMRL: MASK24 Position             */
#define INTC_IMRL_MASK25_MASK                    (0x01UL << INTC_IMRL_MASK25_SHIFT)                  /*!< INTC0_IMRL: MASK25 Mask                 */
#define INTC_IMRL_MASK25_SHIFT                   25                                                  /*!< INTC0_IMRL: MASK25 Position             */
#define INTC_IMRL_MASK26_MASK                    (0x01UL << INTC_IMRL_MASK26_SHIFT)                  /*!< INTC0_IMRL: MASK26 Mask                 */
#define INTC_IMRL_MASK26_SHIFT                   26                                                  /*!< INTC0_IMRL: MASK26 Position             */
#define INTC_IMRL_MASK27_MASK                    (0x01UL << INTC_IMRL_MASK27_SHIFT)                  /*!< INTC0_IMRL: MASK27 Mask                 */
#define INTC_IMRL_MASK27_SHIFT                   27                                                  /*!< INTC0_IMRL: MASK27 Position             */
#define INTC_IMRL_MASK28_MASK                    (0x01UL << INTC_IMRL_MASK28_SHIFT)                  /*!< INTC0_IMRL: MASK28 Mask                 */
#define INTC_IMRL_MASK28_SHIFT                   28                                                  /*!< INTC0_IMRL: MASK28 Position             */
#define INTC_IMRL_MASK29_MASK                    (0x01UL << INTC_IMRL_MASK29_SHIFT)                  /*!< INTC0_IMRL: MASK29 Mask                 */
#define INTC_IMRL_MASK29_SHIFT                   29                                                  /*!< INTC0_IMRL: MASK29 Position             */
#define INTC_IMRL_MASK30_MASK                    (0x01UL << INTC_IMRL_MASK30_SHIFT)                  /*!< INTC0_IMRL: MASK30 Mask                 */
#define INTC_IMRL_MASK30_SHIFT                   30                                                  /*!< INTC0_IMRL: MASK30 Position             */
#define INTC_IMRL_MASK31_MASK                    (0x01UL << INTC_IMRL_MASK31_SHIFT)                  /*!< INTC0_IMRL: MASK31 Mask                 */
#define INTC_IMRL_MASK31_SHIFT                   31                                                  /*!< INTC0_IMRL: MASK31 Position             */
/* ------- INTFRCH Bit Fields                       ------ */
#define INTC_INTFRCH_FRCH32_MASK                 (0x01UL << INTC_INTFRCH_FRCH32_SHIFT)               /*!< INTC0_INTFRCH: FRCH32 Mask              */
#define INTC_INTFRCH_FRCH32_SHIFT                0                                                   /*!< INTC0_INTFRCH: FRCH32 Position          */
#define INTC_INTFRCH_FRCH33_MASK                 (0x01UL << INTC_INTFRCH_FRCH33_SHIFT)               /*!< INTC0_INTFRCH: FRCH33 Mask              */
#define INTC_INTFRCH_FRCH33_SHIFT                1                                                   /*!< INTC0_INTFRCH: FRCH33 Position          */
#define INTC_INTFRCH_FRCH34_MASK                 (0x01UL << INTC_INTFRCH_FRCH34_SHIFT)               /*!< INTC0_INTFRCH: FRCH34 Mask              */
#define INTC_INTFRCH_FRCH34_SHIFT                2                                                   /*!< INTC0_INTFRCH: FRCH34 Position          */
#define INTC_INTFRCH_FRCH35_MASK                 (0x01UL << INTC_INTFRCH_FRCH35_SHIFT)               /*!< INTC0_INTFRCH: FRCH35 Mask              */
#define INTC_INTFRCH_FRCH35_SHIFT                3                                                   /*!< INTC0_INTFRCH: FRCH35 Position          */
#define INTC_INTFRCH_FRCH36_MASK                 (0x01UL << INTC_INTFRCH_FRCH36_SHIFT)               /*!< INTC0_INTFRCH: FRCH36 Mask              */
#define INTC_INTFRCH_FRCH36_SHIFT                4                                                   /*!< INTC0_INTFRCH: FRCH36 Position          */
#define INTC_INTFRCH_FRCH37_MASK                 (0x01UL << INTC_INTFRCH_FRCH37_SHIFT)               /*!< INTC0_INTFRCH: FRCH37 Mask              */
#define INTC_INTFRCH_FRCH37_SHIFT                5                                                   /*!< INTC0_INTFRCH: FRCH37 Position          */
#define INTC_INTFRCH_FRCH38_MASK                 (0x01UL << INTC_INTFRCH_FRCH38_SHIFT)               /*!< INTC0_INTFRCH: FRCH38 Mask              */
#define INTC_INTFRCH_FRCH38_SHIFT                6                                                   /*!< INTC0_INTFRCH: FRCH38 Position          */
#define INTC_INTFRCH_FRCH39_MASK                 (0x01UL << INTC_INTFRCH_FRCH39_SHIFT)               /*!< INTC0_INTFRCH: FRCH39 Mask              */
#define INTC_INTFRCH_FRCH39_SHIFT                7                                                   /*!< INTC0_INTFRCH: FRCH39 Position          */
#define INTC_INTFRCH_FRCH40_MASK                 (0x01UL << INTC_INTFRCH_FRCH40_SHIFT)               /*!< INTC0_INTFRCH: FRCH40 Mask              */
#define INTC_INTFRCH_FRCH40_SHIFT                8                                                   /*!< INTC0_INTFRCH: FRCH40 Position          */
#define INTC_INTFRCH_FRCH41_MASK                 (0x01UL << INTC_INTFRCH_FRCH41_SHIFT)               /*!< INTC0_INTFRCH: FRCH41 Mask              */
#define INTC_INTFRCH_FRCH41_SHIFT                9                                                   /*!< INTC0_INTFRCH: FRCH41 Position          */
#define INTC_INTFRCH_FRCH42_MASK                 (0x01UL << INTC_INTFRCH_FRCH42_SHIFT)               /*!< INTC0_INTFRCH: FRCH42 Mask              */
#define INTC_INTFRCH_FRCH42_SHIFT                10                                                  /*!< INTC0_INTFRCH: FRCH42 Position          */
#define INTC_INTFRCH_FRCH43_MASK                 (0x01UL << INTC_INTFRCH_FRCH43_SHIFT)               /*!< INTC0_INTFRCH: FRCH43 Mask              */
#define INTC_INTFRCH_FRCH43_SHIFT                11                                                  /*!< INTC0_INTFRCH: FRCH43 Position          */
#define INTC_INTFRCH_FRCH44_MASK                 (0x01UL << INTC_INTFRCH_FRCH44_SHIFT)               /*!< INTC0_INTFRCH: FRCH44 Mask              */
#define INTC_INTFRCH_FRCH44_SHIFT                12                                                  /*!< INTC0_INTFRCH: FRCH44 Position          */
#define INTC_INTFRCH_FRCH45_MASK                 (0x01UL << INTC_INTFRCH_FRCH45_SHIFT)               /*!< INTC0_INTFRCH: FRCH45 Mask              */
#define INTC_INTFRCH_FRCH45_SHIFT                13                                                  /*!< INTC0_INTFRCH: FRCH45 Position          */
#define INTC_INTFRCH_FRCH46_MASK                 (0x01UL << INTC_INTFRCH_FRCH46_SHIFT)               /*!< INTC0_INTFRCH: FRCH46 Mask              */
#define INTC_INTFRCH_FRCH46_SHIFT                14                                                  /*!< INTC0_INTFRCH: FRCH46 Position          */
#define INTC_INTFRCH_FRCH47_MASK                 (0x01UL << INTC_INTFRCH_FRCH47_SHIFT)               /*!< INTC0_INTFRCH: FRCH47 Mask              */
#define INTC_INTFRCH_FRCH47_SHIFT                15                                                  /*!< INTC0_INTFRCH: FRCH47 Position          */
#define INTC_INTFRCH_FRCH48_MASK                 (0x01UL << INTC_INTFRCH_FRCH48_SHIFT)               /*!< INTC0_INTFRCH: FRCH48 Mask              */
#define INTC_INTFRCH_FRCH48_SHIFT                16                                                  /*!< INTC0_INTFRCH: FRCH48 Position          */
#define INTC_INTFRCH_FRCH49_MASK                 (0x01UL << INTC_INTFRCH_FRCH49_SHIFT)               /*!< INTC0_INTFRCH: FRCH49 Mask              */
#define INTC_INTFRCH_FRCH49_SHIFT                17                                                  /*!< INTC0_INTFRCH: FRCH49 Position          */
#define INTC_INTFRCH_FRCH50_MASK                 (0x01UL << INTC_INTFRCH_FRCH50_SHIFT)               /*!< INTC0_INTFRCH: FRCH50 Mask              */
#define INTC_INTFRCH_FRCH50_SHIFT                18                                                  /*!< INTC0_INTFRCH: FRCH50 Position          */
#define INTC_INTFRCH_FRCH51_MASK                 (0x01UL << INTC_INTFRCH_FRCH51_SHIFT)               /*!< INTC0_INTFRCH: FRCH51 Mask              */
#define INTC_INTFRCH_FRCH51_SHIFT                19                                                  /*!< INTC0_INTFRCH: FRCH51 Position          */
#define INTC_INTFRCH_FRCH52_MASK                 (0x01UL << INTC_INTFRCH_FRCH52_SHIFT)               /*!< INTC0_INTFRCH: FRCH52 Mask              */
#define INTC_INTFRCH_FRCH52_SHIFT                20                                                  /*!< INTC0_INTFRCH: FRCH52 Position          */
#define INTC_INTFRCH_FRCH53_MASK                 (0x01UL << INTC_INTFRCH_FRCH53_SHIFT)               /*!< INTC0_INTFRCH: FRCH53 Mask              */
#define INTC_INTFRCH_FRCH53_SHIFT                21                                                  /*!< INTC0_INTFRCH: FRCH53 Position          */
#define INTC_INTFRCH_FRCH54_MASK                 (0x01UL << INTC_INTFRCH_FRCH54_SHIFT)               /*!< INTC0_INTFRCH: FRCH54 Mask              */
#define INTC_INTFRCH_FRCH54_SHIFT                22                                                  /*!< INTC0_INTFRCH: FRCH54 Position          */
#define INTC_INTFRCH_FRCH55_MASK                 (0x01UL << INTC_INTFRCH_FRCH55_SHIFT)               /*!< INTC0_INTFRCH: FRCH55 Mask              */
#define INTC_INTFRCH_FRCH55_SHIFT                23                                                  /*!< INTC0_INTFRCH: FRCH55 Position          */
#define INTC_INTFRCH_FRCH56_MASK                 (0x01UL << INTC_INTFRCH_FRCH56_SHIFT)               /*!< INTC0_INTFRCH: FRCH56 Mask              */
#define INTC_INTFRCH_FRCH56_SHIFT                24                                                  /*!< INTC0_INTFRCH: FRCH56 Position          */
#define INTC_INTFRCH_FRCH57_MASK                 (0x01UL << INTC_INTFRCH_FRCH57_SHIFT)               /*!< INTC0_INTFRCH: FRCH57 Mask              */
#define INTC_INTFRCH_FRCH57_SHIFT                25                                                  /*!< INTC0_INTFRCH: FRCH57 Position          */
#define INTC_INTFRCH_FRCH58_MASK                 (0x01UL << INTC_INTFRCH_FRCH58_SHIFT)               /*!< INTC0_INTFRCH: FRCH58 Mask              */
#define INTC_INTFRCH_FRCH58_SHIFT                26                                                  /*!< INTC0_INTFRCH: FRCH58 Position          */
#define INTC_INTFRCH_FRCH59_MASK                 (0x01UL << INTC_INTFRCH_FRCH59_SHIFT)               /*!< INTC0_INTFRCH: FRCH59 Mask              */
#define INTC_INTFRCH_FRCH59_SHIFT                27                                                  /*!< INTC0_INTFRCH: FRCH59 Position          */
#define INTC_INTFRCH_FRCH60_MASK                 (0x01UL << INTC_INTFRCH_FRCH60_SHIFT)               /*!< INTC0_INTFRCH: FRCH60 Mask              */
#define INTC_INTFRCH_FRCH60_SHIFT                28                                                  /*!< INTC0_INTFRCH: FRCH60 Position          */
#define INTC_INTFRCH_FRCH61_MASK                 (0x01UL << INTC_INTFRCH_FRCH61_SHIFT)               /*!< INTC0_INTFRCH: FRCH61 Mask              */
#define INTC_INTFRCH_FRCH61_SHIFT                29                                                  /*!< INTC0_INTFRCH: FRCH61 Position          */
#define INTC_INTFRCH_FRCH62_MASK                 (0x01UL << INTC_INTFRCH_FRCH62_SHIFT)               /*!< INTC0_INTFRCH: FRCH62 Mask              */
#define INTC_INTFRCH_FRCH62_SHIFT                30                                                  /*!< INTC0_INTFRCH: FRCH62 Position          */
#define INTC_INTFRCH_FRCH63_MASK                 (0x01UL << INTC_INTFRCH_FRCH63_SHIFT)               /*!< INTC0_INTFRCH: FRCH63 Mask              */
#define INTC_INTFRCH_FRCH63_SHIFT                31                                                  /*!< INTC0_INTFRCH: FRCH63 Position          */
/* ------- INTFRCL Bit Fields                       ------ */
#define INTC_INTFRCL_FRCH1_MASK                  (0x01UL << INTC_INTFRCL_FRCH1_SHIFT)                /*!< INTC0_INTFRCL: FRCH1 Mask               */
#define INTC_INTFRCL_FRCH1_SHIFT                 1                                                   /*!< INTC0_INTFRCL: FRCH1 Position           */
#define INTC_INTFRCL_FRCH2_MASK                  (0x01UL << INTC_INTFRCL_FRCH2_SHIFT)                /*!< INTC0_INTFRCL: FRCH2 Mask               */
#define INTC_INTFRCL_FRCH2_SHIFT                 2                                                   /*!< INTC0_INTFRCL: FRCH2 Position           */
#define INTC_INTFRCL_FRCH3_MASK                  (0x01UL << INTC_INTFRCL_FRCH3_SHIFT)                /*!< INTC0_INTFRCL: FRCH3 Mask               */
#define INTC_INTFRCL_FRCH3_SHIFT                 3                                                   /*!< INTC0_INTFRCL: FRCH3 Position           */
#define INTC_INTFRCL_FRCH4_MASK                  (0x01UL << INTC_INTFRCL_FRCH4_SHIFT)                /*!< INTC0_INTFRCL: FRCH4 Mask               */
#define INTC_INTFRCL_FRCH4_SHIFT                 4                                                   /*!< INTC0_INTFRCL: FRCH4 Position           */
#define INTC_INTFRCL_FRCH5_MASK                  (0x01UL << INTC_INTFRCL_FRCH5_SHIFT)                /*!< INTC0_INTFRCL: FRCH5 Mask               */
#define INTC_INTFRCL_FRCH5_SHIFT                 5                                                   /*!< INTC0_INTFRCL: FRCH5 Position           */
#define INTC_INTFRCL_FRCH6_MASK                  (0x01UL << INTC_INTFRCL_FRCH6_SHIFT)                /*!< INTC0_INTFRCL: FRCH6 Mask               */
#define INTC_INTFRCL_FRCH6_SHIFT                 6                                                   /*!< INTC0_INTFRCL: FRCH6 Position           */
#define INTC_INTFRCL_FRCH7_MASK                  (0x01UL << INTC_INTFRCL_FRCH7_SHIFT)                /*!< INTC0_INTFRCL: FRCH7 Mask               */
#define INTC_INTFRCL_FRCH7_SHIFT                 7                                                   /*!< INTC0_INTFRCL: FRCH7 Position           */
#define INTC_INTFRCL_FRCH8_MASK                  (0x01UL << INTC_INTFRCL_FRCH8_SHIFT)                /*!< INTC0_INTFRCL: FRCH8 Mask               */
#define INTC_INTFRCL_FRCH8_SHIFT                 8                                                   /*!< INTC0_INTFRCL: FRCH8 Position           */
#define INTC_INTFRCL_FRCH9_MASK                  (0x01UL << INTC_INTFRCL_FRCH9_SHIFT)                /*!< INTC0_INTFRCL: FRCH9 Mask               */
#define INTC_INTFRCL_FRCH9_SHIFT                 9                                                   /*!< INTC0_INTFRCL: FRCH9 Position           */
#define INTC_INTFRCL_FRCH10_MASK                 (0x01UL << INTC_INTFRCL_FRCH10_SHIFT)               /*!< INTC0_INTFRCL: FRCH10 Mask              */
#define INTC_INTFRCL_FRCH10_SHIFT                10                                                  /*!< INTC0_INTFRCL: FRCH10 Position          */
#define INTC_INTFRCL_FRCH11_MASK                 (0x01UL << INTC_INTFRCL_FRCH11_SHIFT)               /*!< INTC0_INTFRCL: FRCH11 Mask              */
#define INTC_INTFRCL_FRCH11_SHIFT                11                                                  /*!< INTC0_INTFRCL: FRCH11 Position          */
#define INTC_INTFRCL_FRCH12_MASK                 (0x01UL << INTC_INTFRCL_FRCH12_SHIFT)               /*!< INTC0_INTFRCL: FRCH12 Mask              */
#define INTC_INTFRCL_FRCH12_SHIFT                12                                                  /*!< INTC0_INTFRCL: FRCH12 Position          */
#define INTC_INTFRCL_FRCH13_MASK                 (0x01UL << INTC_INTFRCL_FRCH13_SHIFT)               /*!< INTC0_INTFRCL: FRCH13 Mask              */
#define INTC_INTFRCL_FRCH13_SHIFT                13                                                  /*!< INTC0_INTFRCL: FRCH13 Position          */
#define INTC_INTFRCL_FRCH14_MASK                 (0x01UL << INTC_INTFRCL_FRCH14_SHIFT)               /*!< INTC0_INTFRCL: FRCH14 Mask              */
#define INTC_INTFRCL_FRCH14_SHIFT                14                                                  /*!< INTC0_INTFRCL: FRCH14 Position          */
#define INTC_INTFRCL_FRCH15_MASK                 (0x01UL << INTC_INTFRCL_FRCH15_SHIFT)               /*!< INTC0_INTFRCL: FRCH15 Mask              */
#define INTC_INTFRCL_FRCH15_SHIFT                15                                                  /*!< INTC0_INTFRCL: FRCH15 Position          */
#define INTC_INTFRCL_FRCH16_MASK                 (0x01UL << INTC_INTFRCL_FRCH16_SHIFT)               /*!< INTC0_INTFRCL: FRCH16 Mask              */
#define INTC_INTFRCL_FRCH16_SHIFT                16                                                  /*!< INTC0_INTFRCL: FRCH16 Position          */
#define INTC_INTFRCL_FRCH17_MASK                 (0x01UL << INTC_INTFRCL_FRCH17_SHIFT)               /*!< INTC0_INTFRCL: FRCH17 Mask              */
#define INTC_INTFRCL_FRCH17_SHIFT                17                                                  /*!< INTC0_INTFRCL: FRCH17 Position          */
#define INTC_INTFRCL_FRCH18_MASK                 (0x01UL << INTC_INTFRCL_FRCH18_SHIFT)               /*!< INTC0_INTFRCL: FRCH18 Mask              */
#define INTC_INTFRCL_FRCH18_SHIFT                18                                                  /*!< INTC0_INTFRCL: FRCH18 Position          */
#define INTC_INTFRCL_FRCH19_MASK                 (0x01UL << INTC_INTFRCL_FRCH19_SHIFT)               /*!< INTC0_INTFRCL: FRCH19 Mask              */
#define INTC_INTFRCL_FRCH19_SHIFT                19                                                  /*!< INTC0_INTFRCL: FRCH19 Position          */
#define INTC_INTFRCL_FRCH20_MASK                 (0x01UL << INTC_INTFRCL_FRCH20_SHIFT)               /*!< INTC0_INTFRCL: FRCH20 Mask              */
#define INTC_INTFRCL_FRCH20_SHIFT                20                                                  /*!< INTC0_INTFRCL: FRCH20 Position          */
#define INTC_INTFRCL_FRCH21_MASK                 (0x01UL << INTC_INTFRCL_FRCH21_SHIFT)               /*!< INTC0_INTFRCL: FRCH21 Mask              */
#define INTC_INTFRCL_FRCH21_SHIFT                21                                                  /*!< INTC0_INTFRCL: FRCH21 Position          */
#define INTC_INTFRCL_FRCH22_MASK                 (0x01UL << INTC_INTFRCL_FRCH22_SHIFT)               /*!< INTC0_INTFRCL: FRCH22 Mask              */
#define INTC_INTFRCL_FRCH22_SHIFT                22                                                  /*!< INTC0_INTFRCL: FRCH22 Position          */
#define INTC_INTFRCL_FRCH23_MASK                 (0x01UL << INTC_INTFRCL_FRCH23_SHIFT)               /*!< INTC0_INTFRCL: FRCH23 Mask              */
#define INTC_INTFRCL_FRCH23_SHIFT                23                                                  /*!< INTC0_INTFRCL: FRCH23 Position          */
#define INTC_INTFRCL_FRCH24_MASK                 (0x01UL << INTC_INTFRCL_FRCH24_SHIFT)               /*!< INTC0_INTFRCL: FRCH24 Mask              */
#define INTC_INTFRCL_FRCH24_SHIFT                24                                                  /*!< INTC0_INTFRCL: FRCH24 Position          */
#define INTC_INTFRCL_FRCH25_MASK                 (0x01UL << INTC_INTFRCL_FRCH25_SHIFT)               /*!< INTC0_INTFRCL: FRCH25 Mask              */
#define INTC_INTFRCL_FRCH25_SHIFT                25                                                  /*!< INTC0_INTFRCL: FRCH25 Position          */
#define INTC_INTFRCL_FRCH26_MASK                 (0x01UL << INTC_INTFRCL_FRCH26_SHIFT)               /*!< INTC0_INTFRCL: FRCH26 Mask              */
#define INTC_INTFRCL_FRCH26_SHIFT                26                                                  /*!< INTC0_INTFRCL: FRCH26 Position          */
#define INTC_INTFRCL_FRCH27_MASK                 (0x01UL << INTC_INTFRCL_FRCH27_SHIFT)               /*!< INTC0_INTFRCL: FRCH27 Mask              */
#define INTC_INTFRCL_FRCH27_SHIFT                27                                                  /*!< INTC0_INTFRCL: FRCH27 Position          */
#define INTC_INTFRCL_FRCH28_MASK                 (0x01UL << INTC_INTFRCL_FRCH28_SHIFT)               /*!< INTC0_INTFRCL: FRCH28 Mask              */
#define INTC_INTFRCL_FRCH28_SHIFT                28                                                  /*!< INTC0_INTFRCL: FRCH28 Position          */
#define INTC_INTFRCL_FRCH29_MASK                 (0x01UL << INTC_INTFRCL_FRCH29_SHIFT)               /*!< INTC0_INTFRCL: FRCH29 Mask              */
#define INTC_INTFRCL_FRCH29_SHIFT                29                                                  /*!< INTC0_INTFRCL: FRCH29 Position          */
#define INTC_INTFRCL_FRCH30_MASK                 (0x01UL << INTC_INTFRCL_FRCH30_SHIFT)               /*!< INTC0_INTFRCL: FRCH30 Mask              */
#define INTC_INTFRCL_FRCH30_SHIFT                30                                                  /*!< INTC0_INTFRCL: FRCH30 Position          */
#define INTC_INTFRCL_FRCH31_MASK                 (0x01UL << INTC_INTFRCL_FRCH31_SHIFT)               /*!< INTC0_INTFRCL: FRCH31 Mask              */
#define INTC_INTFRCL_FRCH31_SHIFT                31                                                  /*!< INTC0_INTFRCL: FRCH31 Position          */
/* ------- IRLR Bit Fields                          ------ */
#define INTC_IRLR_IRQ1_MASK                      (0x01UL << INTC_IRLR_IRQ1_SHIFT)                    /*!< INTC0_IRLR: IRQ1 Mask                   */
#define INTC_IRLR_IRQ1_SHIFT                     1                                                   /*!< INTC0_IRLR: IRQ1 Position               */
#define INTC_IRLR_IRQ2_MASK                      (0x01UL << INTC_IRLR_IRQ2_SHIFT)                    /*!< INTC0_IRLR: IRQ2 Mask                   */
#define INTC_IRLR_IRQ2_SHIFT                     2                                                   /*!< INTC0_IRLR: IRQ2 Position               */
#define INTC_IRLR_IRQ3_MASK                      (0x01UL << INTC_IRLR_IRQ3_SHIFT)                    /*!< INTC0_IRLR: IRQ3 Mask                   */
#define INTC_IRLR_IRQ3_SHIFT                     3                                                   /*!< INTC0_IRLR: IRQ3 Position               */
#define INTC_IRLR_IRQ4_MASK                      (0x01UL << INTC_IRLR_IRQ4_SHIFT)                    /*!< INTC0_IRLR: IRQ4 Mask                   */
#define INTC_IRLR_IRQ4_SHIFT                     4                                                   /*!< INTC0_IRLR: IRQ4 Position               */
#define INTC_IRLR_IRQ5_MASK                      (0x01UL << INTC_IRLR_IRQ5_SHIFT)                    /*!< INTC0_IRLR: IRQ5 Mask                   */
#define INTC_IRLR_IRQ5_SHIFT                     5                                                   /*!< INTC0_IRLR: IRQ5 Position               */
#define INTC_IRLR_IRQ6_MASK                      (0x01UL << INTC_IRLR_IRQ6_SHIFT)                    /*!< INTC0_IRLR: IRQ6 Mask                   */
#define INTC_IRLR_IRQ6_SHIFT                     6                                                   /*!< INTC0_IRLR: IRQ6 Position               */
#define INTC_IRLR_IRQ7_MASK                      (0x01UL << INTC_IRLR_IRQ7_SHIFT)                    /*!< INTC0_IRLR: IRQ7 Mask                   */
#define INTC_IRLR_IRQ7_SHIFT                     7                                                   /*!< INTC0_IRLR: IRQ7 Position               */
/* ------- IACKLPR Bit Fields                       ------ */
#define INTC_IACKLPR_PRI_MASK                    (0x0FUL << INTC_IACKLPR_PRI_SHIFT)                  /*!< INTC0_IACKLPR: PRI Mask                 */
#define INTC_IACKLPR_PRI_SHIFT                   0                                                   /*!< INTC0_IACKLPR: PRI Position             */
#define INTC_IACKLPR_PRI(x)                      (((uint8_t)(((uint8_t)(x))<<INTC_IACKLPR_PRI_SHIFT))&INTC_IACKLPR_PRI_MASK) /*!< INTC0_IACKLPR                           */
#define INTC_IACKLPR_LEVEL_MASK                  (0x07UL << INTC_IACKLPR_LEVEL_SHIFT)                /*!< INTC0_IACKLPR: LEVEL Mask               */
#define INTC_IACKLPR_LEVEL_SHIFT                 4                                                   /*!< INTC0_IACKLPR: LEVEL Position           */
#define INTC_IACKLPR_LEVEL(x)                    (((uint8_t)(((uint8_t)(x))<<INTC_IACKLPR_LEVEL_SHIFT))&INTC_IACKLPR_LEVEL_MASK) /*!< INTC0_IACKLPR                           */
/* ------- ICR Bit Fields                           ------ */
#define INTC_ICR_IP_MASK                         (0x07UL << INTC_ICR_IP_SHIFT)                       /*!< INTC0_ICR: IP Mask                      */
#define INTC_ICR_IP_SHIFT                        0                                                   /*!< INTC0_ICR: IP Position                  */
#define INTC_ICR_IP(x)                           (((uint8_t)(((uint8_t)(x))<<INTC_ICR_IP_SHIFT))&INTC_ICR_IP_MASK) /*!< INTC0_ICR                               */
#define INTC_ICR_IL_MASK                         (0x07UL << INTC_ICR_IL_SHIFT)                       /*!< INTC0_ICR: IL Mask                      */
#define INTC_ICR_IL_SHIFT                        3                                                   /*!< INTC0_ICR: IL Position                  */
#define INTC_ICR_IL(x)                           (((uint8_t)(((uint8_t)(x))<<INTC_ICR_IL_SHIFT))&INTC_ICR_IL_MASK) /*!< INTC0_ICR                               */
/* ------- ICR Bit Fields                           ------ */
/* ------- SWIACK Bit Fields                        ------ */
/* ------- LIACK Bit Fields                         ------ */

/* INTC0 - Peripheral instance base addresses */
#define INTC0_BasePtr                  0x40000C00UL
#define INTC0                          ((INTC_Type *) INTC0_BasePtr)
#define INTC0_BASE_PTR                 (INTC0)

/* ================================================================================ */
/* ================           INTC1 (derived from INTC0)           ================ */
/* ================================================================================ */

/**
 * @brief Interrupt Controller Module
 */

/* INTC1 - Peripheral instance base addresses */
#define INTC1_BasePtr                  0x40000D00UL
#define INTC1                          ((INTC_Type *) INTC1_BasePtr)
#define INTC1_BASE_PTR                 (INTC1)

/* ================================================================================ */
/* ================           PAD (file:MCF52233_PAD)              ================ */
/* ================================================================================ */

/**
 * @brief Pin Configuration
 */
typedef struct {                                /*!<       PAD Structure                                                */
   __IO uint16_t  PWOR;                         /*!< 0000: Pin Wired OR Register                                        */
   __IO uint16_t  PDSR1;                        /*!< 0002: Pin Drive Strength Register 1                                */
   __IO uint32_t  PDSR0;                        /*!< 0004: Pin Drive Strength Register 0                                */
} PAD_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'PAD' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- PWOR Bit Fields                          ------ */
#define PAD_PWOR_PWOR0_MASK                      (0xFFFFUL << PAD_PWOR_PWOR0_SHIFT)                  /*!< PAD_PWOR: PWOR0 Mask                    */
#define PAD_PWOR_PWOR0_SHIFT                     0                                                   /*!< PAD_PWOR: PWOR0 Position                */
#define PAD_PWOR_PWOR0(x)                        (((uint16_t)(((uint16_t)(x))<<PAD_PWOR_PWOR0_SHIFT))&PAD_PWOR_PWOR0_MASK) /*!< PAD_PWOR                                */
/* ------- PDSR1 Bit Fields                         ------ */
#define PAD_PDSR1_PDSRx_MASK                     (0xFFFFUL << PAD_PDSR1_PDSRx_SHIFT)                 /*!< PAD_PDSR1: PDSRx Mask                   */
#define PAD_PDSR1_PDSRx_SHIFT                    0                                                   /*!< PAD_PDSR1: PDSRx Position               */
#define PAD_PDSR1_PDSRx(x)                       (((uint16_t)(((uint16_t)(x))<<PAD_PDSR1_PDSRx_SHIFT))&PAD_PDSR1_PDSRx_MASK) /*!< PAD_PDSR1                               */
/* ------- PDSR0 Bit Fields                         ------ */
#define PAD_PDSR0_PDSR0_MASK                     (0xFFFFFFFFUL << PAD_PDSR0_PDSR0_SHIFT)             /*!< PAD_PDSR0: PDSR0 Mask                   */
#define PAD_PDSR0_PDSR0_SHIFT                    0                                                   /*!< PAD_PDSR0: PDSR0 Position               */
#define PAD_PDSR0_PDSR0(x)                       (((uint32_t)(((uint32_t)(x))<<PAD_PDSR0_PDSR0_SHIFT))&PAD_PDSR0_PDSR0_MASK) /*!< PAD_PDSR0                               */

/* PAD - Peripheral instance base addresses */
#define PAD_BasePtr                    0x40100078UL
#define PAD                            ((PAD_Type *) PAD_BasePtr)
#define PAD_BASE_PTR                   (PAD)

/* ================================================================================ */
/* ================           PIT0 (file:MCF522xx_PIT0)            ================ */
/* ================================================================================ */

/**
 * @brief Programmable Interrupt Timer
The PIT is a 16-bit timer that provides precise interrupts at regular intervals with minimal processor intervention. 
The timer can count down from the value written in the modulus register or it can be a free-running down-counter
 */
typedef struct {                                /*!<       PIT0 Structure                                               */
   __IO uint16_t  PCSR;                         /*!< 0000: Control and Status Register                                  */
   __IO uint16_t  PMR;                          /*!< 0002: Modulus Register                                             */
   __I  uint16_t  PCNTR;                        /*!< 0004: Count Register                                               */
} PIT_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'PIT0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- PCSR Bit Fields                          ------ */
#define PIT0_PCSR_EN_MASK                        (0x01UL << PIT0_PCSR_EN_SHIFT)                      /*!< PIT0_PCSR: EN Mask                      */
#define PIT0_PCSR_EN_SHIFT                       0                                                   /*!< PIT0_PCSR: EN Position                  */
#define PIT0_PCSR_RLD_MASK                       (0x01UL << PIT0_PCSR_RLD_SHIFT)                     /*!< PIT0_PCSR: RLD Mask                     */
#define PIT0_PCSR_RLD_SHIFT                      1                                                   /*!< PIT0_PCSR: RLD Position                 */
#define PIT0_PCSR_PIF_MASK                       (0x01UL << PIT0_PCSR_PIF_SHIFT)                     /*!< PIT0_PCSR: PIF Mask                     */
#define PIT0_PCSR_PIF_SHIFT                      2                                                   /*!< PIT0_PCSR: PIF Position                 */
#define PIT0_PCSR_PIE_MASK                       (0x01UL << PIT0_PCSR_PIE_SHIFT)                     /*!< PIT0_PCSR: PIE Mask                     */
#define PIT0_PCSR_PIE_SHIFT                      3                                                   /*!< PIT0_PCSR: PIE Position                 */
#define PIT0_PCSR_OVW_MASK                       (0x01UL << PIT0_PCSR_OVW_SHIFT)                     /*!< PIT0_PCSR: OVW Mask                     */
#define PIT0_PCSR_OVW_SHIFT                      4                                                   /*!< PIT0_PCSR: OVW Position                 */
#define PIT0_PCSR_DBG_MASK                       (0x01UL << PIT0_PCSR_DBG_SHIFT)                     /*!< PIT0_PCSR: DBG Mask                     */
#define PIT0_PCSR_DBG_SHIFT                      5                                                   /*!< PIT0_PCSR: DBG Position                 */
#define PIT0_PCSR_DOZE_MASK                      (0x01UL << PIT0_PCSR_DOZE_SHIFT)                    /*!< PIT0_PCSR: DOZE Mask                    */
#define PIT0_PCSR_DOZE_SHIFT                     6                                                   /*!< PIT0_PCSR: DOZE Position                */
#define PIT0_PCSR_PRE_MASK                       (0x0FUL << PIT0_PCSR_PRE_SHIFT)                     /*!< PIT0_PCSR: PRE Mask                     */
#define PIT0_PCSR_PRE_SHIFT                      8                                                   /*!< PIT0_PCSR: PRE Position                 */
#define PIT0_PCSR_PRE(x)                         (((uint16_t)(((uint16_t)(x))<<PIT0_PCSR_PRE_SHIFT))&PIT0_PCSR_PRE_MASK) /*!< PIT0_PCSR                               */
/* ------- PMR Bit Fields                           ------ */
#define PIT0_PMR_PM_MASK                         (0xFFFFUL << PIT0_PMR_PM_SHIFT)                     /*!< PIT0_PMR: PM Mask                       */
#define PIT0_PMR_PM_SHIFT                        0                                                   /*!< PIT0_PMR: PM Position                   */
#define PIT0_PMR_PM(x)                           (((uint16_t)(((uint16_t)(x))<<PIT0_PMR_PM_SHIFT))&PIT0_PMR_PM_MASK) /*!< PIT0_PMR                                */
/* ------- PCNTR Bit Fields                         ------ */
#define PIT0_PCNTR_PC_MASK                       (0xFFFFUL << PIT0_PCNTR_PC_SHIFT)                   /*!< PIT0_PCNTR: PC Mask                     */
#define PIT0_PCNTR_PC_SHIFT                      0                                                   /*!< PIT0_PCNTR: PC Position                 */
#define PIT0_PCNTR_PC(x)                         (((uint16_t)(((uint16_t)(x))<<PIT0_PCNTR_PC_SHIFT))&PIT0_PCNTR_PC_MASK) /*!< PIT0_PCNTR                              */

/* PIT0 - Peripheral instance base addresses */
#define PIT0_BasePtr                   0x40150000UL
#define PIT0                           ((PIT_Type *) PIT0_BasePtr)
#define PIT0_BASE_PTR                  (PIT0)

/* ================================================================================ */
/* ================           PIT1 (derived from PIT0)             ================ */
/* ================================================================================ */

/**
 * @brief Programmable Interrupt Timer
The PIT is a 16-bit timer that provides precise interrupts at regular intervals with minimal processor intervention. 
The timer can count down from the value written in the modulus register or it can be a free-running down-counter
 */

/* PIT1 - Peripheral instance base addresses */
#define PIT1_BasePtr                   0x40160000UL
#define PIT1                           ((PIT_Type *) PIT1_BasePtr)
#define PIT1_BASE_PTR                  (PIT1)

/* ================================================================================ */
/* ================           PMM (file:MCF522xx_PMM)              ================ */
/* ================================================================================ */

/**
 * @brief Power Management
 */
typedef struct {                                /*!<       PMM Structure                                                */
   __IO uint8_t   LPICR;                        /*!< 0000: Low-Power Interrupt Control Register                         */
   __I  uint8_t   RESERVED0[1114100];           /*!< 0001:                                                              */
   __IO uint8_t   LPCR;                         /*!< 10FFF5: Low-Power Control Register                                   */
} PMM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'PMM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- LPICR Bit Fields                         ------ */
#define PMM_LPICR_XLPM_IPL_MASK                  (0x07UL << PMM_LPICR_XLPM_IPL_SHIFT)                /*!< PMM_LPICR: XLPM_IPL Mask                */
#define PMM_LPICR_XLPM_IPL_SHIFT                 4                                                   /*!< PMM_LPICR: XLPM_IPL Position            */
#define PMM_LPICR_XLPM_IPL(x)                    (((uint8_t)(((uint8_t)(x))<<PMM_LPICR_XLPM_IPL_SHIFT))&PMM_LPICR_XLPM_IPL_MASK) /*!< PMM_LPICR                               */
#define PMM_LPICR_ENBSTOP_MASK                   (0x01UL << PMM_LPICR_ENBSTOP_SHIFT)                 /*!< PMM_LPICR: ENBSTOP Mask                 */
#define PMM_LPICR_ENBSTOP_SHIFT                  7                                                   /*!< PMM_LPICR: ENBSTOP Position             */
/* ------- LPCR Bit Fields                          ------ */
#define PMM_LPCR_LVDSE_MASK                      (0x01UL << PMM_LPCR_LVDSE_SHIFT)                    /*!< PMM_LPCR: LVDSE Mask                    */
#define PMM_LPCR_LVDSE_SHIFT                     1                                                   /*!< PMM_LPCR: LVDSE Position                */
#define PMM_LPCR_STPMD_MASK                      (0x03UL << PMM_LPCR_STPMD_SHIFT)                    /*!< PMM_LPCR: STPMD Mask                    */
#define PMM_LPCR_STPMD_SHIFT                     3                                                   /*!< PMM_LPCR: STPMD Position                */
#define PMM_LPCR_STPMD(x)                        (((uint8_t)(((uint8_t)(x))<<PMM_LPCR_STPMD_SHIFT))&PMM_LPCR_STPMD_MASK) /*!< PMM_LPCR                                */
#define PMM_LPCR_LPMD_MASK                       (0x03UL << PMM_LPCR_LPMD_SHIFT)                     /*!< PMM_LPCR: LPMD Mask                     */
#define PMM_LPCR_LPMD_SHIFT                      6                                                   /*!< PMM_LPCR: LPMD Position                 */
#define PMM_LPCR_LPMD(x)                         (((uint8_t)(((uint8_t)(x))<<PMM_LPCR_LPMD_SHIFT))&PMM_LPCR_LPMD_MASK) /*!< PMM_LPCR                                */

/* PMM - Peripheral instance base addresses */
#define PMM_BasePtr                    0x40000012UL
#define PMM                            ((PMM_Type *) PMM_BasePtr)
#define PMM_BASE_PTR                   (PMM)

/* ================================================================================ */
/* ================           PWM (file:MCF522xx_PWM)              ================ */
/* ================================================================================ */

/**
 * @brief Pulse-Width Modulation Module
 */
typedef struct {                                /*!<       PWM Structure                                                */
   __IO uint8_t   PWME;                         /*!< 0000: Enable Register                                              */
   __IO uint8_t   PWMPOL;                       /*!< 0001: Polarity Register                                            */
   __IO uint8_t   PWMCLK;                       /*!< 0002: Clock Select Register                                        */
   __IO uint8_t   PWMPRCLK;                     /*!< 0003: Prescale Clock Select Register                               */
   __IO uint8_t   PWMCAE;                       /*!< 0004: Centre Align Enable Register                                 */
   __IO uint8_t   PWMCTL;                       /*!< 0005: Control Register                                             */
   __I  uint16_t  RESERVED0;                    /*!< 0006:                                                              */
   __IO uint8_t   PWMSCLA;                      /*!< 0008: Scale Register A                                             */
   __IO uint8_t   PWMSCLB;                      /*!< 0009: Scale Register B                                             */
   __I  uint16_t  RESERVED1;                    /*!< 000A:                                                              */
   __IO uint8_t   PWMCNT[8];                    /*!< 000C: Channel  Counter Register                                    */
   __IO uint8_t   PWMPER[8];                    /*!< 0014: Channel  Period Register                                     */
   __IO uint8_t   PWMDTY[8];                    /*!< 001C: Channel  Duty Register                                       */
   __IO uint8_t   PWMSDN;                       /*!< 0024: Shutdown Register                                            */
} PWM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'PWM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- PWME Bit Fields                          ------ */
#define PWM_PWME_PWME0_MASK                      (0x01UL << PWM_PWME_PWME0_SHIFT)                    /*!< PWM_PWME: PWME0 Mask                    */
#define PWM_PWME_PWME0_SHIFT                     0                                                   /*!< PWM_PWME: PWME0 Position                */
#define PWM_PWME_PWME1_MASK                      (0x01UL << PWM_PWME_PWME1_SHIFT)                    /*!< PWM_PWME: PWME1 Mask                    */
#define PWM_PWME_PWME1_SHIFT                     1                                                   /*!< PWM_PWME: PWME1 Position                */
#define PWM_PWME_PWME2_MASK                      (0x01UL << PWM_PWME_PWME2_SHIFT)                    /*!< PWM_PWME: PWME2 Mask                    */
#define PWM_PWME_PWME2_SHIFT                     2                                                   /*!< PWM_PWME: PWME2 Position                */
#define PWM_PWME_PWME3_MASK                      (0x01UL << PWM_PWME_PWME3_SHIFT)                    /*!< PWM_PWME: PWME3 Mask                    */
#define PWM_PWME_PWME3_SHIFT                     3                                                   /*!< PWM_PWME: PWME3 Position                */
#define PWM_PWME_PWME4_MASK                      (0x01UL << PWM_PWME_PWME4_SHIFT)                    /*!< PWM_PWME: PWME4 Mask                    */
#define PWM_PWME_PWME4_SHIFT                     4                                                   /*!< PWM_PWME: PWME4 Position                */
#define PWM_PWME_PWME5_MASK                      (0x01UL << PWM_PWME_PWME5_SHIFT)                    /*!< PWM_PWME: PWME5 Mask                    */
#define PWM_PWME_PWME5_SHIFT                     5                                                   /*!< PWM_PWME: PWME5 Position                */
#define PWM_PWME_PWME6_MASK                      (0x01UL << PWM_PWME_PWME6_SHIFT)                    /*!< PWM_PWME: PWME6 Mask                    */
#define PWM_PWME_PWME6_SHIFT                     6                                                   /*!< PWM_PWME: PWME6 Position                */
#define PWM_PWME_PWME7_MASK                      (0x01UL << PWM_PWME_PWME7_SHIFT)                    /*!< PWM_PWME: PWME7 Mask                    */
#define PWM_PWME_PWME7_SHIFT                     7                                                   /*!< PWM_PWME: PWME7 Position                */
/* ------- PWMPOL Bit Fields                        ------ */
#define PWM_PWMPOL_PPOL0_MASK                    (0x01UL << PWM_PWMPOL_PPOL0_SHIFT)                  /*!< PWM_PWMPOL: PPOL0 Mask                  */
#define PWM_PWMPOL_PPOL0_SHIFT                   0                                                   /*!< PWM_PWMPOL: PPOL0 Position              */
#define PWM_PWMPOL_PPOL1_MASK                    (0x01UL << PWM_PWMPOL_PPOL1_SHIFT)                  /*!< PWM_PWMPOL: PPOL1 Mask                  */
#define PWM_PWMPOL_PPOL1_SHIFT                   1                                                   /*!< PWM_PWMPOL: PPOL1 Position              */
#define PWM_PWMPOL_PPOL2_MASK                    (0x01UL << PWM_PWMPOL_PPOL2_SHIFT)                  /*!< PWM_PWMPOL: PPOL2 Mask                  */
#define PWM_PWMPOL_PPOL2_SHIFT                   2                                                   /*!< PWM_PWMPOL: PPOL2 Position              */
#define PWM_PWMPOL_PPOL3_MASK                    (0x01UL << PWM_PWMPOL_PPOL3_SHIFT)                  /*!< PWM_PWMPOL: PPOL3 Mask                  */
#define PWM_PWMPOL_PPOL3_SHIFT                   3                                                   /*!< PWM_PWMPOL: PPOL3 Position              */
#define PWM_PWMPOL_PPOL4_MASK                    (0x01UL << PWM_PWMPOL_PPOL4_SHIFT)                  /*!< PWM_PWMPOL: PPOL4 Mask                  */
#define PWM_PWMPOL_PPOL4_SHIFT                   4                                                   /*!< PWM_PWMPOL: PPOL4 Position              */
#define PWM_PWMPOL_PPOL5_MASK                    (0x01UL << PWM_PWMPOL_PPOL5_SHIFT)                  /*!< PWM_PWMPOL: PPOL5 Mask                  */
#define PWM_PWMPOL_PPOL5_SHIFT                   5                                                   /*!< PWM_PWMPOL: PPOL5 Position              */
#define PWM_PWMPOL_PPOL6_MASK                    (0x01UL << PWM_PWMPOL_PPOL6_SHIFT)                  /*!< PWM_PWMPOL: PPOL6 Mask                  */
#define PWM_PWMPOL_PPOL6_SHIFT                   6                                                   /*!< PWM_PWMPOL: PPOL6 Position              */
#define PWM_PWMPOL_PPOL7_MASK                    (0x01UL << PWM_PWMPOL_PPOL7_SHIFT)                  /*!< PWM_PWMPOL: PPOL7 Mask                  */
#define PWM_PWMPOL_PPOL7_SHIFT                   7                                                   /*!< PWM_PWMPOL: PPOL7 Position              */
/* ------- PWMCLK Bit Fields                        ------ */
#define PWM_PWMCLK_PCLK0_MASK                    (0x01UL << PWM_PWMCLK_PCLK0_SHIFT)                  /*!< PWM_PWMCLK: PCLK0 Mask                  */
#define PWM_PWMCLK_PCLK0_SHIFT                   0                                                   /*!< PWM_PWMCLK: PCLK0 Position              */
#define PWM_PWMCLK_PCLK1_MASK                    (0x01UL << PWM_PWMCLK_PCLK1_SHIFT)                  /*!< PWM_PWMCLK: PCLK1 Mask                  */
#define PWM_PWMCLK_PCLK1_SHIFT                   1                                                   /*!< PWM_PWMCLK: PCLK1 Position              */
#define PWM_PWMCLK_PCLK2_MASK                    (0x01UL << PWM_PWMCLK_PCLK2_SHIFT)                  /*!< PWM_PWMCLK: PCLK2 Mask                  */
#define PWM_PWMCLK_PCLK2_SHIFT                   2                                                   /*!< PWM_PWMCLK: PCLK2 Position              */
#define PWM_PWMCLK_PCLK3_MASK                    (0x01UL << PWM_PWMCLK_PCLK3_SHIFT)                  /*!< PWM_PWMCLK: PCLK3 Mask                  */
#define PWM_PWMCLK_PCLK3_SHIFT                   3                                                   /*!< PWM_PWMCLK: PCLK3 Position              */
#define PWM_PWMCLK_PCLK4_MASK                    (0x01UL << PWM_PWMCLK_PCLK4_SHIFT)                  /*!< PWM_PWMCLK: PCLK4 Mask                  */
#define PWM_PWMCLK_PCLK4_SHIFT                   4                                                   /*!< PWM_PWMCLK: PCLK4 Position              */
#define PWM_PWMCLK_PCLK5_MASK                    (0x01UL << PWM_PWMCLK_PCLK5_SHIFT)                  /*!< PWM_PWMCLK: PCLK5 Mask                  */
#define PWM_PWMCLK_PCLK5_SHIFT                   5                                                   /*!< PWM_PWMCLK: PCLK5 Position              */
#define PWM_PWMCLK_PCLK6_MASK                    (0x01UL << PWM_PWMCLK_PCLK6_SHIFT)                  /*!< PWM_PWMCLK: PCLK6 Mask                  */
#define PWM_PWMCLK_PCLK6_SHIFT                   6                                                   /*!< PWM_PWMCLK: PCLK6 Position              */
#define PWM_PWMCLK_PCLK7_MASK                    (0x01UL << PWM_PWMCLK_PCLK7_SHIFT)                  /*!< PWM_PWMCLK: PCLK7 Mask                  */
#define PWM_PWMCLK_PCLK7_SHIFT                   7                                                   /*!< PWM_PWMCLK: PCLK7 Position              */
/* ------- PWMPRCLK Bit Fields                      ------ */
#define PWM_PWMPRCLK_PCKA_MASK                   (0x07UL << PWM_PWMPRCLK_PCKA_SHIFT)                 /*!< PWM_PWMPRCLK: PCKA Mask                 */
#define PWM_PWMPRCLK_PCKA_SHIFT                  0                                                   /*!< PWM_PWMPRCLK: PCKA Position             */
#define PWM_PWMPRCLK_PCKA(x)                     (((uint8_t)(((uint8_t)(x))<<PWM_PWMPRCLK_PCKA_SHIFT))&PWM_PWMPRCLK_PCKA_MASK) /*!< PWM_PWMPRCLK                            */
#define PWM_PWMPRCLK_PCKB_MASK                   (0x07UL << PWM_PWMPRCLK_PCKB_SHIFT)                 /*!< PWM_PWMPRCLK: PCKB Mask                 */
#define PWM_PWMPRCLK_PCKB_SHIFT                  4                                                   /*!< PWM_PWMPRCLK: PCKB Position             */
#define PWM_PWMPRCLK_PCKB(x)                     (((uint8_t)(((uint8_t)(x))<<PWM_PWMPRCLK_PCKB_SHIFT))&PWM_PWMPRCLK_PCKB_MASK) /*!< PWM_PWMPRCLK                            */
/* ------- PWMCAE Bit Fields                        ------ */
#define PWM_PWMCAE_CAE0_MASK                     (0x01UL << PWM_PWMCAE_CAE0_SHIFT)                   /*!< PWM_PWMCAE: CAE0 Mask                   */
#define PWM_PWMCAE_CAE0_SHIFT                    0                                                   /*!< PWM_PWMCAE: CAE0 Position               */
#define PWM_PWMCAE_CAE1_MASK                     (0x01UL << PWM_PWMCAE_CAE1_SHIFT)                   /*!< PWM_PWMCAE: CAE1 Mask                   */
#define PWM_PWMCAE_CAE1_SHIFT                    1                                                   /*!< PWM_PWMCAE: CAE1 Position               */
#define PWM_PWMCAE_CAE2_MASK                     (0x01UL << PWM_PWMCAE_CAE2_SHIFT)                   /*!< PWM_PWMCAE: CAE2 Mask                   */
#define PWM_PWMCAE_CAE2_SHIFT                    2                                                   /*!< PWM_PWMCAE: CAE2 Position               */
#define PWM_PWMCAE_CAE3_MASK                     (0x01UL << PWM_PWMCAE_CAE3_SHIFT)                   /*!< PWM_PWMCAE: CAE3 Mask                   */
#define PWM_PWMCAE_CAE3_SHIFT                    3                                                   /*!< PWM_PWMCAE: CAE3 Position               */
#define PWM_PWMCAE_CAE4_MASK                     (0x01UL << PWM_PWMCAE_CAE4_SHIFT)                   /*!< PWM_PWMCAE: CAE4 Mask                   */
#define PWM_PWMCAE_CAE4_SHIFT                    4                                                   /*!< PWM_PWMCAE: CAE4 Position               */
#define PWM_PWMCAE_CAE5_MASK                     (0x01UL << PWM_PWMCAE_CAE5_SHIFT)                   /*!< PWM_PWMCAE: CAE5 Mask                   */
#define PWM_PWMCAE_CAE5_SHIFT                    5                                                   /*!< PWM_PWMCAE: CAE5 Position               */
#define PWM_PWMCAE_CAE6_MASK                     (0x01UL << PWM_PWMCAE_CAE6_SHIFT)                   /*!< PWM_PWMCAE: CAE6 Mask                   */
#define PWM_PWMCAE_CAE6_SHIFT                    6                                                   /*!< PWM_PWMCAE: CAE6 Position               */
#define PWM_PWMCAE_CAE7_MASK                     (0x01UL << PWM_PWMCAE_CAE7_SHIFT)                   /*!< PWM_PWMCAE: CAE7 Mask                   */
#define PWM_PWMCAE_CAE7_SHIFT                    7                                                   /*!< PWM_PWMCAE: CAE7 Position               */
/* ------- PWMCTL Bit Fields                        ------ */
#define PWM_PWMCTL_PFRZ_MASK                     (0x01UL << PWM_PWMCTL_PFRZ_SHIFT)                   /*!< PWM_PWMCTL: PFRZ Mask                   */
#define PWM_PWMCTL_PFRZ_SHIFT                    2                                                   /*!< PWM_PWMCTL: PFRZ Position               */
#define PWM_PWMCTL_PSWAI_MASK                    (0x01UL << PWM_PWMCTL_PSWAI_SHIFT)                  /*!< PWM_PWMCTL: PSWAI Mask                  */
#define PWM_PWMCTL_PSWAI_SHIFT                   3                                                   /*!< PWM_PWMCTL: PSWAI Position              */
#define PWM_PWMCTL_CON01_MASK                    (0x01UL << PWM_PWMCTL_CON01_SHIFT)                  /*!< PWM_PWMCTL: CON01 Mask                  */
#define PWM_PWMCTL_CON01_SHIFT                   4                                                   /*!< PWM_PWMCTL: CON01 Position              */
#define PWM_PWMCTL_CON23_MASK                    (0x01UL << PWM_PWMCTL_CON23_SHIFT)                  /*!< PWM_PWMCTL: CON23 Mask                  */
#define PWM_PWMCTL_CON23_SHIFT                   5                                                   /*!< PWM_PWMCTL: CON23 Position              */
#define PWM_PWMCTL_CON45_MASK                    (0x01UL << PWM_PWMCTL_CON45_SHIFT)                  /*!< PWM_PWMCTL: CON45 Mask                  */
#define PWM_PWMCTL_CON45_SHIFT                   6                                                   /*!< PWM_PWMCTL: CON45 Position              */
#define PWM_PWMCTL_CON67_MASK                    (0x01UL << PWM_PWMCTL_CON67_SHIFT)                  /*!< PWM_PWMCTL: CON67 Mask                  */
#define PWM_PWMCTL_CON67_SHIFT                   7                                                   /*!< PWM_PWMCTL: CON67 Position              */
/* ------- PWMSCLA Bit Fields                       ------ */
/* ------- PWMSCLB Bit Fields                       ------ */
/* ------- PWMCNT Bit Fields                        ------ */
/* ------- PWMPER Bit Fields                        ------ */
/* ------- PWMDTY Bit Fields                        ------ */
/* ------- PWMSDN Bit Fields                        ------ */
#define PWM_PWMSDN_SDNEN_MASK                    (0x01UL << PWM_PWMSDN_SDNEN_SHIFT)                  /*!< PWM_PWMSDN: SDNEN Mask                  */
#define PWM_PWMSDN_SDNEN_SHIFT                   0                                                   /*!< PWM_PWMSDN: SDNEN Position              */
#define PWM_PWMSDN_PWM7IL_MASK                   (0x01UL << PWM_PWMSDN_PWM7IL_SHIFT)                 /*!< PWM_PWMSDN: PWM7IL Mask                 */
#define PWM_PWMSDN_PWM7IL_SHIFT                  1                                                   /*!< PWM_PWMSDN: PWM7IL Position             */
#define PWM_PWMSDN_PWM7IN_MASK                   (0x01UL << PWM_PWMSDN_PWM7IN_SHIFT)                 /*!< PWM_PWMSDN: PWM7IN Mask                 */
#define PWM_PWMSDN_PWM7IN_SHIFT                  2                                                   /*!< PWM_PWMSDN: PWM7IN Position             */
#define PWM_PWMSDN_LVL_MASK                      (0x01UL << PWM_PWMSDN_LVL_SHIFT)                    /*!< PWM_PWMSDN: LVL Mask                    */
#define PWM_PWMSDN_LVL_SHIFT                     4                                                   /*!< PWM_PWMSDN: LVL Position                */
#define PWM_PWMSDN_RESTART_MASK                  (0x01UL << PWM_PWMSDN_RESTART_SHIFT)                /*!< PWM_PWMSDN: RESTART Mask                */
#define PWM_PWMSDN_RESTART_SHIFT                 5                                                   /*!< PWM_PWMSDN: RESTART Position            */
#define PWM_PWMSDN_IE_MASK                       (0x01UL << PWM_PWMSDN_IE_SHIFT)                     /*!< PWM_PWMSDN: IE Mask                     */
#define PWM_PWMSDN_IE_SHIFT                      6                                                   /*!< PWM_PWMSDN: IE Position                 */
#define PWM_PWMSDN_IF_MASK                       (0x01UL << PWM_PWMSDN_IF_SHIFT)                     /*!< PWM_PWMSDN: IF Mask                     */
#define PWM_PWMSDN_IF_SHIFT                      7                                                   /*!< PWM_PWMSDN: IF Position                 */

/* PWM - Peripheral instance base addresses */
#define PWM_BasePtr                    0x401B0000UL
#define PWM                            ((PWM_Type *) PWM_BasePtr)
#define PWM_BASE_PTR                   (PWM)

/* ================================================================================ */
/* ================           QSPI (file:MCF522xx_QSPI)            ================ */
/* ================================================================================ */

/**
 * @brief Queued Serial Peripheral Interface
 */
typedef struct {                                /*!<       QSPI Structure                                               */
   __IO uint16_t  QMR;                          /*!< 0000: Mode Register                                                */
   __I  uint16_t  RESERVED0;                    /*!< 0002:                                                              */
   __IO uint16_t  QDLYR;                        /*!< 0004: Delay Register                                               */
   __I  uint16_t  RESERVED1;                    /*!< 0006:                                                              */
   __IO uint16_t  QWR;                          /*!< 0008: Wrap Register                                                */
   __I  uint16_t  RESERVED2;                    /*!< 000A:                                                              */
   __IO uint16_t  QIR;                          /*!< 000C: Interrupt Register                                           */
   __I  uint16_t  RESERVED3;                    /*!< 000E:                                                              */
   __IO uint16_t  QAR;                          /*!< 0010: Address Register                                             */
   __I  uint16_t  RESERVED4;                    /*!< 0012:                                                              */
   union {                                      /*!< 0000: (size=0002)                                                  */
      __IO uint16_t  QDR;                       /*!< 0014: Data Register                                                */
      __O  uint8_t   QDR_COMMAND;               /*!< 0014: Command Register                                             */
   };
} QSPI_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'QSPI' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- QMR Bit Fields                           ------ */
#define QSPI_QMR_BAUD_MASK                       (0xFFUL << QSPI_QMR_BAUD_SHIFT)                     /*!< QSPI_QMR: BAUD Mask                     */
#define QSPI_QMR_BAUD_SHIFT                      0                                                   /*!< QSPI_QMR: BAUD Position                 */
#define QSPI_QMR_BAUD(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QMR_BAUD_SHIFT))&QSPI_QMR_BAUD_MASK) /*!< QSPI_QMR                                */
#define QSPI_QMR_CPHA_MASK                       (0x01UL << QSPI_QMR_CPHA_SHIFT)                     /*!< QSPI_QMR: CPHA Mask                     */
#define QSPI_QMR_CPHA_SHIFT                      8                                                   /*!< QSPI_QMR: CPHA Position                 */
#define QSPI_QMR_CPOL_MASK                       (0x01UL << QSPI_QMR_CPOL_SHIFT)                     /*!< QSPI_QMR: CPOL Mask                     */
#define QSPI_QMR_CPOL_SHIFT                      9                                                   /*!< QSPI_QMR: CPOL Position                 */
#define QSPI_QMR_BITS_MASK                       (0x0FUL << QSPI_QMR_BITS_SHIFT)                     /*!< QSPI_QMR: BITS Mask                     */
#define QSPI_QMR_BITS_SHIFT                      10                                                  /*!< QSPI_QMR: BITS Position                 */
#define QSPI_QMR_BITS(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QMR_BITS_SHIFT))&QSPI_QMR_BITS_MASK) /*!< QSPI_QMR                                */
#define QSPI_QMR_DOHIE_MASK                      (0x01UL << QSPI_QMR_DOHIE_SHIFT)                    /*!< QSPI_QMR: DOHIE Mask                    */
#define QSPI_QMR_DOHIE_SHIFT                     14                                                  /*!< QSPI_QMR: DOHIE Position                */
#define QSPI_QMR_MSTR_MASK                       (0x01UL << QSPI_QMR_MSTR_SHIFT)                     /*!< QSPI_QMR: MSTR Mask                     */
#define QSPI_QMR_MSTR_SHIFT                      15                                                  /*!< QSPI_QMR: MSTR Position                 */
/* ------- QDLYR Bit Fields                         ------ */
#define QSPI_QDLYR_DTL_MASK                      (0xFFUL << QSPI_QDLYR_DTL_SHIFT)                    /*!< QSPI_QDLYR: DTL Mask                    */
#define QSPI_QDLYR_DTL_SHIFT                     0                                                   /*!< QSPI_QDLYR: DTL Position                */
#define QSPI_QDLYR_DTL(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QDLYR_DTL_SHIFT))&QSPI_QDLYR_DTL_MASK) /*!< QSPI_QDLYR                              */
#define QSPI_QDLYR_QCD_MASK                      (0x7FUL << QSPI_QDLYR_QCD_SHIFT)                    /*!< QSPI_QDLYR: QCD Mask                    */
#define QSPI_QDLYR_QCD_SHIFT                     8                                                   /*!< QSPI_QDLYR: QCD Position                */
#define QSPI_QDLYR_QCD(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QDLYR_QCD_SHIFT))&QSPI_QDLYR_QCD_MASK) /*!< QSPI_QDLYR                              */
#define QSPI_QDLYR_SPE_MASK                      (0x01UL << QSPI_QDLYR_SPE_SHIFT)                    /*!< QSPI_QDLYR: SPE Mask                    */
#define QSPI_QDLYR_SPE_SHIFT                     15                                                  /*!< QSPI_QDLYR: SPE Position                */
/* ------- QWR Bit Fields                           ------ */
#define QSPI_QWR_NEWQP_MASK                      (0x0FUL << QSPI_QWR_NEWQP_SHIFT)                    /*!< QSPI_QWR: NEWQP Mask                    */
#define QSPI_QWR_NEWQP_SHIFT                     0                                                   /*!< QSPI_QWR: NEWQP Position                */
#define QSPI_QWR_NEWQP(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_NEWQP_SHIFT))&QSPI_QWR_NEWQP_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_CPTQP_MASK                      (0x0FUL << QSPI_QWR_CPTQP_SHIFT)                    /*!< QSPI_QWR: CPTQP Mask                    */
#define QSPI_QWR_CPTQP_SHIFT                     4                                                   /*!< QSPI_QWR: CPTQP Position                */
#define QSPI_QWR_CPTQP(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_CPTQP_SHIFT))&QSPI_QWR_CPTQP_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_ENDQP_MASK                      (0x0FUL << QSPI_QWR_ENDQP_SHIFT)                    /*!< QSPI_QWR: ENDQP Mask                    */
#define QSPI_QWR_ENDQP_SHIFT                     8                                                   /*!< QSPI_QWR: ENDQP Position                */
#define QSPI_QWR_ENDQP(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_ENDQP_SHIFT))&QSPI_QWR_ENDQP_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_CSIV_MASK                       (0x01UL << QSPI_QWR_CSIV_SHIFT)                     /*!< QSPI_QWR: CSIV Mask                     */
#define QSPI_QWR_CSIV_SHIFT                      12                                                  /*!< QSPI_QWR: CSIV Position                 */
#define QSPI_QWR_WRTO_MASK                       (0x01UL << QSPI_QWR_WRTO_SHIFT)                     /*!< QSPI_QWR: WRTO Mask                     */
#define QSPI_QWR_WRTO_SHIFT                      13                                                  /*!< QSPI_QWR: WRTO Position                 */
#define QSPI_QWR_WREN_MASK                       (0x01UL << QSPI_QWR_WREN_SHIFT)                     /*!< QSPI_QWR: WREN Mask                     */
#define QSPI_QWR_WREN_SHIFT                      14                                                  /*!< QSPI_QWR: WREN Position                 */
#define QSPI_QWR_HALT_MASK                       (0x01UL << QSPI_QWR_HALT_SHIFT)                     /*!< QSPI_QWR: HALT Mask                     */
#define QSPI_QWR_HALT_SHIFT                      15                                                  /*!< QSPI_QWR: HALT Position                 */
/* ------- QIR Bit Fields                           ------ */
#define QSPI_QIR_SPIF_MASK                       (0x01UL << QSPI_QIR_SPIF_SHIFT)                     /*!< QSPI_QIR: SPIF Mask                     */
#define QSPI_QIR_SPIF_SHIFT                      0                                                   /*!< QSPI_QIR: SPIF Position                 */
#define QSPI_QIR_ABRT_MASK                       (0x01UL << QSPI_QIR_ABRT_SHIFT)                     /*!< QSPI_QIR: ABRT Mask                     */
#define QSPI_QIR_ABRT_SHIFT                      2                                                   /*!< QSPI_QIR: ABRT Position                 */
#define QSPI_QIR_WCEF_MASK                       (0x01UL << QSPI_QIR_WCEF_SHIFT)                     /*!< QSPI_QIR: WCEF Mask                     */
#define QSPI_QIR_WCEF_SHIFT                      3                                                   /*!< QSPI_QIR: WCEF Position                 */
#define QSPI_QIR_SPIFE_MASK                      (0x01UL << QSPI_QIR_SPIFE_SHIFT)                    /*!< QSPI_QIR: SPIFE Mask                    */
#define QSPI_QIR_SPIFE_SHIFT                     8                                                   /*!< QSPI_QIR: SPIFE Position                */
#define QSPI_QIR_ABRTE_MASK                      (0x01UL << QSPI_QIR_ABRTE_SHIFT)                    /*!< QSPI_QIR: ABRTE Mask                    */
#define QSPI_QIR_ABRTE_SHIFT                     10                                                  /*!< QSPI_QIR: ABRTE Position                */
#define QSPI_QIR_WCEFE_MASK                      (0x01UL << QSPI_QIR_WCEFE_SHIFT)                    /*!< QSPI_QIR: WCEFE Mask                    */
#define QSPI_QIR_WCEFE_SHIFT                     11                                                  /*!< QSPI_QIR: WCEFE Position                */
#define QSPI_QIR_ABRTL_MASK                      (0x01UL << QSPI_QIR_ABRTL_SHIFT)                    /*!< QSPI_QIR: ABRTL Mask                    */
#define QSPI_QIR_ABRTL_SHIFT                     12                                                  /*!< QSPI_QIR: ABRTL Position                */
#define QSPI_QIR_ABRTB_MASK                      (0x01UL << QSPI_QIR_ABRTB_SHIFT)                    /*!< QSPI_QIR: ABRTB Mask                    */
#define QSPI_QIR_ABRTB_SHIFT                     14                                                  /*!< QSPI_QIR: ABRTB Position                */
#define QSPI_QIR_WCEFB_MASK                      (0x01UL << QSPI_QIR_WCEFB_SHIFT)                    /*!< QSPI_QIR: WCEFB Mask                    */
#define QSPI_QIR_WCEFB_SHIFT                     15                                                  /*!< QSPI_QIR: WCEFB Position                */
/* ------- QAR Bit Fields                           ------ */
#define QSPI_QAR_ADDR_MASK                       (0x3FUL << QSPI_QAR_ADDR_SHIFT)                     /*!< QSPI_QAR: ADDR Mask                     */
#define QSPI_QAR_ADDR_SHIFT                      0                                                   /*!< QSPI_QAR: ADDR Position                 */
#define QSPI_QAR_ADDR(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QAR_ADDR_SHIFT))&QSPI_QAR_ADDR_MASK) /*!< QSPI_QAR                                */
/* ------- QDR Bit Fields                           ------ */
/* ------- QDR_COMMAND Bit Fields                   ------ */
#define QSPI_QDR_COMMAND_QSPI_CS0_MASK           (0x01UL << QSPI_QDR_COMMAND_QSPI_CS0_SHIFT)         /*!< QSPI_QDR_COMMAND: QSPI_CS0 Mask         */
#define QSPI_QDR_COMMAND_QSPI_CS0_SHIFT          0                                                   /*!< QSPI_QDR_COMMAND: QSPI_CS0 Position     */
#define QSPI_QDR_COMMAND_QSPI_CS1_MASK           (0x01UL << QSPI_QDR_COMMAND_QSPI_CS1_SHIFT)         /*!< QSPI_QDR_COMMAND: QSPI_CS1 Mask         */
#define QSPI_QDR_COMMAND_QSPI_CS1_SHIFT          1                                                   /*!< QSPI_QDR_COMMAND: QSPI_CS1 Position     */
#define QSPI_QDR_COMMAND_QSPI_CS2_MASK           (0x01UL << QSPI_QDR_COMMAND_QSPI_CS2_SHIFT)         /*!< QSPI_QDR_COMMAND: QSPI_CS2 Mask         */
#define QSPI_QDR_COMMAND_QSPI_CS2_SHIFT          2                                                   /*!< QSPI_QDR_COMMAND: QSPI_CS2 Position     */
#define QSPI_QDR_COMMAND_QSPI_CS3_MASK           (0x01UL << QSPI_QDR_COMMAND_QSPI_CS3_SHIFT)         /*!< QSPI_QDR_COMMAND: QSPI_CS3 Mask         */
#define QSPI_QDR_COMMAND_QSPI_CS3_SHIFT          3                                                   /*!< QSPI_QDR_COMMAND: QSPI_CS3 Position     */
#define QSPI_QDR_COMMAND_DSCK_MASK               (0x01UL << QSPI_QDR_COMMAND_DSCK_SHIFT)             /*!< QSPI_QDR_COMMAND: DSCK Mask             */
#define QSPI_QDR_COMMAND_DSCK_SHIFT              4                                                   /*!< QSPI_QDR_COMMAND: DSCK Position         */
#define QSPI_QDR_COMMAND_DT_MASK                 (0x01UL << QSPI_QDR_COMMAND_DT_SHIFT)               /*!< QSPI_QDR_COMMAND: DT Mask               */
#define QSPI_QDR_COMMAND_DT_SHIFT                5                                                   /*!< QSPI_QDR_COMMAND: DT Position           */
#define QSPI_QDR_COMMAND_BITSE_MASK              (0x01UL << QSPI_QDR_COMMAND_BITSE_SHIFT)            /*!< QSPI_QDR_COMMAND: BITSE Mask            */
#define QSPI_QDR_COMMAND_BITSE_SHIFT             6                                                   /*!< QSPI_QDR_COMMAND: BITSE Position        */
#define QSPI_QDR_COMMAND_CONT_MASK               (0x01UL << QSPI_QDR_COMMAND_CONT_SHIFT)             /*!< QSPI_QDR_COMMAND: CONT Mask             */
#define QSPI_QDR_COMMAND_CONT_SHIFT              7                                                   /*!< QSPI_QDR_COMMAND: CONT Position         */

/* QSPI - Peripheral instance base addresses */
#define QSPI_BasePtr                   0x40000340UL
#define QSPI                           ((QSPI_Type *) QSPI_BasePtr)
#define QSPI_BASE_PTR                  (QSPI)

/* ================================================================================ */
/* ================           RCM (file:MCF52233_RCM)              ================ */
/* ================================================================================ */

/**
 * @brief Reset Controller Module
 */
typedef struct {                                /*!<       RCM Structure                                                */
   __IO uint8_t   RCR;                          /*!< 0000: Reset Control Register                                       */
   __I  uint8_t   RSR;                          /*!< 0001: Reset Status Register                                        */
} RCM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- RCR Bit Fields                           ------ */
#define RCM_RCR_LVDE_MASK                        (0x01UL << RCM_RCR_LVDE_SHIFT)                      /*!< RCM_RCR: LVDE Mask                      */
#define RCM_RCR_LVDE_SHIFT                       0                                                   /*!< RCM_RCR: LVDE Position                  */
#define RCM_RCR_LVDRE_MASK                       (0x01UL << RCM_RCR_LVDRE_SHIFT)                     /*!< RCM_RCR: LVDRE Mask                     */
#define RCM_RCR_LVDRE_SHIFT                      2                                                   /*!< RCM_RCR: LVDRE Position                 */
#define RCM_RCR_LVDIE_MASK                       (0x01UL << RCM_RCR_LVDIE_SHIFT)                     /*!< RCM_RCR: LVDIE Mask                     */
#define RCM_RCR_LVDIE_SHIFT                      3                                                   /*!< RCM_RCR: LVDIE Position                 */
#define RCM_RCR_LVDF_MASK                        (0x01UL << RCM_RCR_LVDF_SHIFT)                      /*!< RCM_RCR: LVDF Mask                      */
#define RCM_RCR_LVDF_SHIFT                       4                                                   /*!< RCM_RCR: LVDF Position                  */
#define RCM_RCR_FRCRSTOUT_MASK                   (0x01UL << RCM_RCR_FRCRSTOUT_SHIFT)                 /*!< RCM_RCR: FRCRSTOUT Mask                 */
#define RCM_RCR_FRCRSTOUT_SHIFT                  6                                                   /*!< RCM_RCR: FRCRSTOUT Position             */
#define RCM_RCR_SOFTRST_MASK                     (0x01UL << RCM_RCR_SOFTRST_SHIFT)                   /*!< RCM_RCR: SOFTRST Mask                   */
#define RCM_RCR_SOFTRST_SHIFT                    7                                                   /*!< RCM_RCR: SOFTRST Position               */
/* ------- RSR Bit Fields                           ------ */
#define RCM_RSR_LOL_MASK                         (0x01UL << RCM_RSR_LOL_SHIFT)                       /*!< RCM_RSR: LOL Mask                       */
#define RCM_RSR_LOL_SHIFT                        0                                                   /*!< RCM_RSR: LOL Position                   */
#define RCM_RSR_LOC_MASK                         (0x01UL << RCM_RSR_LOC_SHIFT)                       /*!< RCM_RSR: LOC Mask                       */
#define RCM_RSR_LOC_SHIFT                        1                                                   /*!< RCM_RSR: LOC Position                   */
#define RCM_RSR_EXT_MASK                         (0x01UL << RCM_RSR_EXT_SHIFT)                       /*!< RCM_RSR: EXT Mask                       */
#define RCM_RSR_EXT_SHIFT                        2                                                   /*!< RCM_RSR: EXT Position                   */
#define RCM_RSR_POR_MASK                         (0x01UL << RCM_RSR_POR_SHIFT)                       /*!< RCM_RSR: POR Mask                       */
#define RCM_RSR_POR_SHIFT                        3                                                   /*!< RCM_RSR: POR Position                   */
#define RCM_RSR_SOFT_MASK                        (0x01UL << RCM_RSR_SOFT_SHIFT)                      /*!< RCM_RSR: SOFT Mask                      */
#define RCM_RSR_SOFT_SHIFT                       5                                                   /*!< RCM_RSR: SOFT Position                  */
#define RCM_RSR_LVD_MASK                         (0x01UL << RCM_RSR_LVD_SHIFT)                       /*!< RCM_RSR: LVD Mask                       */
#define RCM_RSR_LVD_SHIFT                        6                                                   /*!< RCM_RSR: LVD Position                   */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x40110000UL
#define RCM                            ((RCM_Type *) RCM_BasePtr)
#define RCM_BASE_PTR                   (RCM)

/* ================================================================================ */
/* ================           RTC (file:MCF52233_RTC)              ================ */
/* ================================================================================ */

/**
 * @brief Real-Time Clock
 */
typedef struct {                                /*!<       RTC Structure                                                */
   __IO uint32_t  HOURMIN;                      /*!< 0000: Hours and Minutes Counter                                    */
   __IO uint32_t  SECONDS;                      /*!< 0004: Seconds Counter                                              */
   __IO uint32_t  ALRM_HM;                      /*!< 0008: Hours and Minutes Alarm                                      */
   __IO uint32_t  ALRM_SEC;                     /*!< 000C: Seconds Alarm                                                */
   __IO uint32_t  RTCCTL;                       /*!< 0010: Control                                                      */
   __IO uint32_t  RTCISR;                       /*!< 0014: Interrupt Status                                             */
   __IO uint32_t  RTCIENR;                      /*!< 0018: Interrupt Enable                                             */
   __IO uint32_t  STPWCH;                       /*!< 001C: Stop-watch Minutes                                           */
   __IO uint32_t  DAYS;                         /*!< 0020: Days Counter                                                 */
   __IO uint32_t  ALRM_DAY;                     /*!< 0024: Day Alarm                                                    */
} RTC_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- HOURMIN Bit Fields                       ------ */
#define RTC_HOURMIN_MINUTES_MASK                 (0x3FUL << RTC_HOURMIN_MINUTES_SHIFT)               /*!< RTC_HOURMIN: MINUTES Mask               */
#define RTC_HOURMIN_MINUTES_SHIFT                0                                                   /*!< RTC_HOURMIN: MINUTES Position           */
#define RTC_HOURMIN_MINUTES(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_HOURMIN_MINUTES_SHIFT))&RTC_HOURMIN_MINUTES_MASK) /*!< RTC_HOURMIN                             */
#define RTC_HOURMIN_HOURS_MASK                   (0x1FUL << RTC_HOURMIN_HOURS_SHIFT)                 /*!< RTC_HOURMIN: HOURS Mask                 */
#define RTC_HOURMIN_HOURS_SHIFT                  8                                                   /*!< RTC_HOURMIN: HOURS Position             */
#define RTC_HOURMIN_HOURS(x)                     (((uint32_t)(((uint32_t)(x))<<RTC_HOURMIN_HOURS_SHIFT))&RTC_HOURMIN_HOURS_MASK) /*!< RTC_HOURMIN                             */
/* ------- SECONDS Bit Fields                       ------ */
#define RTC_SECONDS_SECONDS_MASK                 (0x3FUL << RTC_SECONDS_SECONDS_SHIFT)               /*!< RTC_SECONDS: SECONDS Mask               */
#define RTC_SECONDS_SECONDS_SHIFT                0                                                   /*!< RTC_SECONDS: SECONDS Position           */
#define RTC_SECONDS_SECONDS(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_SECONDS_SECONDS_SHIFT))&RTC_SECONDS_SECONDS_MASK) /*!< RTC_SECONDS                             */
/* ------- ALRM_HM Bit Fields                       ------ */
#define RTC_ALRM_HM_MINUTES_MASK                 (0x3FUL << RTC_ALRM_HM_MINUTES_SHIFT)               /*!< RTC_ALRM_HM: MINUTES Mask               */
#define RTC_ALRM_HM_MINUTES_SHIFT                0                                                   /*!< RTC_ALRM_HM: MINUTES Position           */
#define RTC_ALRM_HM_MINUTES(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_ALRM_HM_MINUTES_SHIFT))&RTC_ALRM_HM_MINUTES_MASK) /*!< RTC_ALRM_HM                             */
#define RTC_ALRM_HM_HOURS_MASK                   (0x1FUL << RTC_ALRM_HM_HOURS_SHIFT)                 /*!< RTC_ALRM_HM: HOURS Mask                 */
#define RTC_ALRM_HM_HOURS_SHIFT                  8                                                   /*!< RTC_ALRM_HM: HOURS Position             */
#define RTC_ALRM_HM_HOURS(x)                     (((uint32_t)(((uint32_t)(x))<<RTC_ALRM_HM_HOURS_SHIFT))&RTC_ALRM_HM_HOURS_MASK) /*!< RTC_ALRM_HM                             */
/* ------- ALRM_SEC Bit Fields                      ------ */
#define RTC_ALRM_SEC_SECONDS_MASK                (0x3FUL << RTC_ALRM_SEC_SECONDS_SHIFT)              /*!< RTC_ALRM_SEC: SECONDS Mask              */
#define RTC_ALRM_SEC_SECONDS_SHIFT               0                                                   /*!< RTC_ALRM_SEC: SECONDS Position          */
#define RTC_ALRM_SEC_SECONDS(x)                  (((uint32_t)(((uint32_t)(x))<<RTC_ALRM_SEC_SECONDS_SHIFT))&RTC_ALRM_SEC_SECONDS_MASK) /*!< RTC_ALRM_SEC                            */
/* ------- RTCCTL Bit Fields                        ------ */
#define RTC_RTCCTL_SWR_MASK                      (0x01UL << RTC_RTCCTL_SWR_SHIFT)                    /*!< RTC_RTCCTL: SWR Mask                    */
#define RTC_RTCCTL_SWR_SHIFT                     0                                                   /*!< RTC_RTCCTL: SWR Position                */
#define RTC_RTCCTL_EN_MASK                       (0x01UL << RTC_RTCCTL_EN_SHIFT)                     /*!< RTC_RTCCTL: EN Mask                     */
#define RTC_RTCCTL_EN_SHIFT                      7                                                   /*!< RTC_RTCCTL: EN Position                 */
/* ------- RTCISR Bit Fields                        ------ */
#define RTC_RTCISR_SW_MASK                       (0x01UL << RTC_RTCISR_SW_SHIFT)                     /*!< RTC_RTCISR: SW Mask                     */
#define RTC_RTCISR_SW_SHIFT                      0                                                   /*!< RTC_RTCISR: SW Position                 */
#define RTC_RTCISR_MIN_MASK                      (0x01UL << RTC_RTCISR_MIN_SHIFT)                    /*!< RTC_RTCISR: MIN Mask                    */
#define RTC_RTCISR_MIN_SHIFT                     1                                                   /*!< RTC_RTCISR: MIN Position                */
#define RTC_RTCISR_ALM_MASK                      (0x01UL << RTC_RTCISR_ALM_SHIFT)                    /*!< RTC_RTCISR: ALM Mask                    */
#define RTC_RTCISR_ALM_SHIFT                     2                                                   /*!< RTC_RTCISR: ALM Position                */
#define RTC_RTCISR_DAY_MASK                      (0x01UL << RTC_RTCISR_DAY_SHIFT)                    /*!< RTC_RTCISR: DAY Mask                    */
#define RTC_RTCISR_DAY_SHIFT                     3                                                   /*!< RTC_RTCISR: DAY Position                */
#define RTC_RTCISR_HZ1_MASK                      (0x01UL << RTC_RTCISR_HZ1_SHIFT)                    /*!< RTC_RTCISR: HZ1 Mask                    */
#define RTC_RTCISR_HZ1_SHIFT                     4                                                   /*!< RTC_RTCISR: HZ1 Position                */
#define RTC_RTCISR_HR_MASK                       (0x01UL << RTC_RTCISR_HR_SHIFT)                     /*!< RTC_RTCISR: HR Mask                     */
#define RTC_RTCISR_HR_SHIFT                      5                                                   /*!< RTC_RTCISR: HR Position                 */
/* ------- RTCIENR Bit Fields                       ------ */
#define RTC_RTCIENR_SW_MASK                      (0x01UL << RTC_RTCIENR_SW_SHIFT)                    /*!< RTC_RTCIENR: SW Mask                    */
#define RTC_RTCIENR_SW_SHIFT                     0                                                   /*!< RTC_RTCIENR: SW Position                */
#define RTC_RTCIENR_MIN_MASK                     (0x01UL << RTC_RTCIENR_MIN_SHIFT)                   /*!< RTC_RTCIENR: MIN Mask                   */
#define RTC_RTCIENR_MIN_SHIFT                    1                                                   /*!< RTC_RTCIENR: MIN Position               */
#define RTC_RTCIENR_ALM_MASK                     (0x01UL << RTC_RTCIENR_ALM_SHIFT)                   /*!< RTC_RTCIENR: ALM Mask                   */
#define RTC_RTCIENR_ALM_SHIFT                    2                                                   /*!< RTC_RTCIENR: ALM Position               */
#define RTC_RTCIENR_DAY_MASK                     (0x01UL << RTC_RTCIENR_DAY_SHIFT)                   /*!< RTC_RTCIENR: DAY Mask                   */
#define RTC_RTCIENR_DAY_SHIFT                    3                                                   /*!< RTC_RTCIENR: DAY Position               */
#define RTC_RTCIENR_HZ1_MASK                     (0x01UL << RTC_RTCIENR_HZ1_SHIFT)                   /*!< RTC_RTCIENR: HZ1 Mask                   */
#define RTC_RTCIENR_HZ1_SHIFT                    4                                                   /*!< RTC_RTCIENR: HZ1 Position               */
#define RTC_RTCIENR_HR_MASK                      (0x01UL << RTC_RTCIENR_HR_SHIFT)                    /*!< RTC_RTCIENR: HR Mask                    */
#define RTC_RTCIENR_HR_SHIFT                     5                                                   /*!< RTC_RTCIENR: HR Position                */
/* ------- STPWCH Bit Fields                        ------ */
#define RTC_STPWCH_CNT_MASK                      (0x3FUL << RTC_STPWCH_CNT_SHIFT)                    /*!< RTC_STPWCH: CNT Mask                    */
#define RTC_STPWCH_CNT_SHIFT                     0                                                   /*!< RTC_STPWCH: CNT Position                */
#define RTC_STPWCH_CNT(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_STPWCH_CNT_SHIFT))&RTC_STPWCH_CNT_MASK) /*!< RTC_STPWCH                              */
/* ------- DAYS Bit Fields                          ------ */
#define RTC_DAYS_DAYS_MASK                       (0xFFFFUL << RTC_DAYS_DAYS_SHIFT)                   /*!< RTC_DAYS: DAYS Mask                     */
#define RTC_DAYS_DAYS_SHIFT                      0                                                   /*!< RTC_DAYS: DAYS Position                 */
#define RTC_DAYS_DAYS(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_DAYS_DAYS_SHIFT))&RTC_DAYS_DAYS_MASK) /*!< RTC_DAYS                                */
/* ------- ALRM_DAY Bit Fields                      ------ */
#define RTC_ALRM_DAY_DAYSAL_MASK                 (0xFFFFUL << RTC_ALRM_DAY_DAYSAL_SHIFT)             /*!< RTC_ALRM_DAY: DAYSAL Mask               */
#define RTC_ALRM_DAY_DAYSAL_SHIFT                0                                                   /*!< RTC_ALRM_DAY: DAYSAL Position           */
#define RTC_ALRM_DAY_DAYSAL(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_ALRM_DAY_DAYSAL_SHIFT))&RTC_ALRM_DAY_DAYSAL_MASK) /*!< RTC_ALRM_DAY                            */

/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x400003C0UL
#define RTC                            ((RTC_Type *) RTC_BasePtr)
#define RTC_BASE_PTR                   (RTC)

/* ================================================================================ */
/* ================           SCM (file:MCF52233_SCM)              ================ */
/* ================================================================================ */

/**
 * @brief System Control Module
 */
typedef struct {                                /*!<       SCM Structure                                                */
   __IO uint32_t  IPSBAR;                       /*!< 0000: Peripheral System Base Address Register                      */
   __I  uint32_t  RESERVED0;                    /*!< 0004:                                                              */
   __IO uint32_t  RAMBAR;                       /*!< 0008: Memory Base Address Register                                 */
   __IO uint32_t  PPMRH;                        /*!< 000C: Peripheral Power Management                                  */
   __IO uint8_t   CRSR;                         /*!< 0010: Core Reset Status Register                                   */
   __IO uint8_t   CWCR;                         /*!< 0011: Core Watchdog Control Register                               */
   __I  uint8_t   RESERVED1;                    /*!< 0012:                                                              */
   __IO uint8_t   CWSR;                         /*!< 0013: Watchdog Service Register                                    */
   __IO uint32_t  DMAREQC;                      /*!< 0014: DMA Request Control                                          */
   __IO uint32_t  PPMRL;                        /*!< 0018: Peripheral Power Management                                  */
   __IO uint32_t  MPARK;                        /*!< 001C: Bus Master Park Register                                     */
   __IO uint8_t   MPR;                          /*!< 0020: Controls the bus master privilege level                      */
   __IO uint8_t   PPMRS;                        /*!< 0021: Peripheral Power Management Set Register                     */
   __IO uint8_t   PPMRC;                        /*!< 0022: Peripheral Power Management Clear Register                   */
   __IO uint8_t   IPSBMT;                       /*!< 0023: IPS Bus Timeout Monitor                                      */
   __IO uint8_t   PACR[9];                      /*!< 0024: Peripheral Access Control Register                           */
   __I  uint8_t   RESERVED2[3];                 /*!< 002D:                                                              */
   __IO uint8_t   GPACR[2];                     /*!< 0030: Grouped Peripheral Access Control                            */
} SCM_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'SCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- IPSBAR Bit Fields                        ------ */
#define SCM_IPSBAR_V_MASK                        (0x01UL << SCM_IPSBAR_V_SHIFT)                      /*!< SCM_IPSBAR: V Mask                      */
#define SCM_IPSBAR_V_SHIFT                       0                                                   /*!< SCM_IPSBAR: V Position                  */
#define SCM_IPSBAR_BA_MASK                       (0x03UL << SCM_IPSBAR_BA_SHIFT)                     /*!< SCM_IPSBAR: BA Mask                     */
#define SCM_IPSBAR_BA_SHIFT                      30                                                  /*!< SCM_IPSBAR: BA Position                 */
#define SCM_IPSBAR_BA(x)                         (((uint32_t)(((uint32_t)(x))<<SCM_IPSBAR_BA_SHIFT))&SCM_IPSBAR_BA_MASK) /*!< SCM_IPSBAR                              */
/* ------- RAMBAR Bit Fields                        ------ */
#define SCM_RAMBAR_BDE_MASK                      (0x01UL << SCM_RAMBAR_BDE_SHIFT)                    /*!< SCM_RAMBAR: BDE Mask                    */
#define SCM_RAMBAR_BDE_SHIFT                     9                                                   /*!< SCM_RAMBAR: BDE Position                */
#define SCM_RAMBAR_BA_MASK                       (0xFFFFUL << SCM_RAMBAR_BA_SHIFT)                   /*!< SCM_RAMBAR: BA Mask                     */
#define SCM_RAMBAR_BA_SHIFT                      16                                                  /*!< SCM_RAMBAR: BA Position                 */
#define SCM_RAMBAR_BA(x)                         (((uint32_t)(((uint32_t)(x))<<SCM_RAMBAR_BA_SHIFT))&SCM_RAMBAR_BA_MASK) /*!< SCM_RAMBAR                              */
/* ------- PPMRH Bit Fields                         ------ */
#define SCM_PPMRH_CDGPIO_MASK                    (0x01UL << SCM_PPMRH_CDGPIO_SHIFT)                  /*!< SCM_PPMRH: CDGPIO Mask                  */
#define SCM_PPMRH_CDGPIO_SHIFT                   0                                                   /*!< SCM_PPMRH: CDGPIO Position              */
#define SCM_PPMRH_CDEPORT_MASK                   (0x01UL << SCM_PPMRH_CDEPORT_SHIFT)                 /*!< SCM_PPMRH: CDEPORT Mask                 */
#define SCM_PPMRH_CDEPORT_SHIFT                  1                                                   /*!< SCM_PPMRH: CDEPORT Position             */
#define SCM_PPMRH_CDPIT0_MASK                    (0x01UL << SCM_PPMRH_CDPIT0_SHIFT)                  /*!< SCM_PPMRH: CDPIT0 Mask                  */
#define SCM_PPMRH_CDPIT0_SHIFT                   3                                                   /*!< SCM_PPMRH: CDPIT0 Position              */
#define SCM_PPMRH_CDPIT1_MASK                    (0x01UL << SCM_PPMRH_CDPIT1_SHIFT)                  /*!< SCM_PPMRH: CDPIT1 Mask                  */
#define SCM_PPMRH_CDPIT1_SHIFT                   4                                                   /*!< SCM_PPMRH: CDPIT1 Position              */
#define SCM_PPMRH_CDADC_MASK                     (0x01UL << SCM_PPMRH_CDADC_SHIFT)                   /*!< SCM_PPMRH: CDADC Mask                   */
#define SCM_PPMRH_CDADC_SHIFT                    7                                                   /*!< SCM_PPMRH: CDADC Position               */
#define SCM_PPMRH_CDGPT_MASK                     (0x01UL << SCM_PPMRH_CDGPT_SHIFT)                   /*!< SCM_PPMRH: CDGPT Mask                   */
#define SCM_PPMRH_CDGPT_SHIFT                    8                                                   /*!< SCM_PPMRH: CDGPT Position               */
#define SCM_PPMRH_CDPWM_MASK                     (0x01UL << SCM_PPMRH_CDPWM_SHIFT)                   /*!< SCM_PPMRH: CDPWM Mask                   */
#define SCM_PPMRH_CDPWM_SHIFT                    9                                                   /*!< SCM_PPMRH: CDPWM Position               */
#define SCM_PPMRH_CDCAN_MASK                     (0x01UL << SCM_PPMRH_CDCAN_SHIFT)                   /*!< SCM_PPMRH: CDCAN Mask                   */
#define SCM_PPMRH_CDCAN_SHIFT                    10                                                  /*!< SCM_PPMRH: CDCAN Position               */
#define SCM_PPMRH_CDCFM_MASK                     (0x01UL << SCM_PPMRH_CDCFM_SHIFT)                   /*!< SCM_PPMRH: CDCFM Mask                   */
#define SCM_PPMRH_CDCFM_SHIFT                    11                                                  /*!< SCM_PPMRH: CDCFM Position               */
#define SCM_PPMRH_CDEPHY_MASK                    (0x01UL << SCM_PPMRH_CDEPHY_SHIFT)                  /*!< SCM_PPMRH: CDEPHY Mask                  */
#define SCM_PPMRH_CDEPHY_SHIFT                   12                                                  /*!< SCM_PPMRH: CDEPHY Position              */
#define SCM_PPMRH_CDRNGA_MASK                    (0x01UL << SCM_PPMRH_CDRNGA_SHIFT)                  /*!< SCM_PPMRH: CDRNGA Mask                  */
#define SCM_PPMRH_CDRNGA_SHIFT                   13                                                  /*!< SCM_PPMRH: CDRNGA Position              */
/* ------- CRSR Bit Fields                          ------ */
#define SCM_CRSR_EXT_MASK                        (0x01UL << SCM_CRSR_EXT_SHIFT)                      /*!< SCM_CRSR: EXT Mask                      */
#define SCM_CRSR_EXT_SHIFT                       7                                                   /*!< SCM_CRSR: EXT Position                  */
/* ------- CWCR Bit Fields                          ------ */
#define SCM_CWCR_CWTIF_MASK                      (0x01UL << SCM_CWCR_CWTIF_SHIFT)                    /*!< SCM_CWCR: CWTIF Mask                    */
#define SCM_CWCR_CWTIF_SHIFT                     0                                                   /*!< SCM_CWCR: CWTIF Position                */
#define SCM_CWCR_CWTAVAL_MASK                    (0x01UL << SCM_CWCR_CWTAVAL_SHIFT)                  /*!< SCM_CWCR: CWTAVAL Mask                  */
#define SCM_CWCR_CWTAVAL_SHIFT                   1                                                   /*!< SCM_CWCR: CWTAVAL Position              */
#define SCM_CWCR_CWTA_MASK                       (0x01UL << SCM_CWCR_CWTA_SHIFT)                     /*!< SCM_CWCR: CWTA Mask                     */
#define SCM_CWCR_CWTA_SHIFT                      2                                                   /*!< SCM_CWCR: CWTA Position                 */
#define SCM_CWCR_CWT_MASK                        (0x07UL << SCM_CWCR_CWT_SHIFT)                      /*!< SCM_CWCR: CWT Mask                      */
#define SCM_CWCR_CWT_SHIFT                       3                                                   /*!< SCM_CWCR: CWT Position                  */
#define SCM_CWCR_CWT(x)                          (((uint8_t)(((uint8_t)(x))<<SCM_CWCR_CWT_SHIFT))&SCM_CWCR_CWT_MASK) /*!< SCM_CWCR                                */
#define SCM_CWCR_CWRI_MASK                       (0x01UL << SCM_CWCR_CWRI_SHIFT)                     /*!< SCM_CWCR: CWRI Mask                     */
#define SCM_CWCR_CWRI_SHIFT                      6                                                   /*!< SCM_CWCR: CWRI Position                 */
#define SCM_CWCR_CWE_MASK                        (0x01UL << SCM_CWCR_CWE_SHIFT)                      /*!< SCM_CWCR: CWE Mask                      */
#define SCM_CWCR_CWE_SHIFT                       7                                                   /*!< SCM_CWCR: CWE Position                  */
/* ------- CWSR Bit Fields                          ------ */
/* ------- DMAREQC Bit Fields                       ------ */
#define SCM_DMAREQC_DMAC0_MASK                   (0x0FUL << SCM_DMAREQC_DMAC0_SHIFT)                 /*!< SCM_DMAREQC: DMAC0 Mask                 */
#define SCM_DMAREQC_DMAC0_SHIFT                  0                                                   /*!< SCM_DMAREQC: DMAC0 Position             */
#define SCM_DMAREQC_DMAC0(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_DMAREQC_DMAC0_SHIFT))&SCM_DMAREQC_DMAC0_MASK) /*!< SCM_DMAREQC                             */
#define SCM_DMAREQC_DMAC1_MASK                   (0x0FUL << SCM_DMAREQC_DMAC1_SHIFT)                 /*!< SCM_DMAREQC: DMAC1 Mask                 */
#define SCM_DMAREQC_DMAC1_SHIFT                  4                                                   /*!< SCM_DMAREQC: DMAC1 Position             */
#define SCM_DMAREQC_DMAC1(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_DMAREQC_DMAC1_SHIFT))&SCM_DMAREQC_DMAC1_MASK) /*!< SCM_DMAREQC                             */
#define SCM_DMAREQC_DMAC2_MASK                   (0x0FUL << SCM_DMAREQC_DMAC2_SHIFT)                 /*!< SCM_DMAREQC: DMAC2 Mask                 */
#define SCM_DMAREQC_DMAC2_SHIFT                  8                                                   /*!< SCM_DMAREQC: DMAC2 Position             */
#define SCM_DMAREQC_DMAC2(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_DMAREQC_DMAC2_SHIFT))&SCM_DMAREQC_DMAC2_MASK) /*!< SCM_DMAREQC                             */
#define SCM_DMAREQC_DMAC3_MASK                   (0x0FUL << SCM_DMAREQC_DMAC3_SHIFT)                 /*!< SCM_DMAREQC: DMAC3 Mask                 */
#define SCM_DMAREQC_DMAC3_SHIFT                  12                                                  /*!< SCM_DMAREQC: DMAC3 Position             */
#define SCM_DMAREQC_DMAC3(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_DMAREQC_DMAC3_SHIFT))&SCM_DMAREQC_DMAC3_MASK) /*!< SCM_DMAREQC                             */
/* ------- PPMRL Bit Fields                         ------ */
#define SCM_PPMRL_CDG_MASK                       (0x01UL << SCM_PPMRL_CDG_SHIFT)                     /*!< SCM_PPMRL: CDG Mask                     */
#define SCM_PPMRL_CDG_SHIFT                      1                                                   /*!< SCM_PPMRL: CDG Position                 */
#define SCM_PPMRL_CDDMA_MASK                     (0x01UL << SCM_PPMRL_CDDMA_SHIFT)                   /*!< SCM_PPMRL: CDDMA Mask                   */
#define SCM_PPMRL_CDDMA_SHIFT                    4                                                   /*!< SCM_PPMRL: CDDMA Position               */
#define SCM_PPMRL_CDUART0_MASK                   (0x01UL << SCM_PPMRL_CDUART0_SHIFT)                 /*!< SCM_PPMRL: CDUART0 Mask                 */
#define SCM_PPMRL_CDUART0_SHIFT                  5                                                   /*!< SCM_PPMRL: CDUART0 Position             */
#define SCM_PPMRL_CDUART1_MASK                   (0x01UL << SCM_PPMRL_CDUART1_SHIFT)                 /*!< SCM_PPMRL: CDUART1 Mask                 */
#define SCM_PPMRL_CDUART1_SHIFT                  6                                                   /*!< SCM_PPMRL: CDUART1 Position             */
#define SCM_PPMRL_CDUART2_MASK                   (0x01UL << SCM_PPMRL_CDUART2_SHIFT)                 /*!< SCM_PPMRL: CDUART2 Mask                 */
#define SCM_PPMRL_CDUART2_SHIFT                  7                                                   /*!< SCM_PPMRL: CDUART2 Position             */
#define SCM_PPMRL_CDI2C0_MASK                    (0x01UL << SCM_PPMRL_CDI2C0_SHIFT)                  /*!< SCM_PPMRL: CDI2C0 Mask                  */
#define SCM_PPMRL_CDI2C0_SHIFT                   9                                                   /*!< SCM_PPMRL: CDI2C0 Position              */
#define SCM_PPMRL_CDQSPI_MASK                    (0x01UL << SCM_PPMRL_CDQSPI_SHIFT)                  /*!< SCM_PPMRL: CDQSPI Mask                  */
#define SCM_PPMRL_CDQSPI_SHIFT                   10                                                  /*!< SCM_PPMRL: CDQSPI Position              */
#define SCM_PPMRL_CDRTC_MASK                     (0x01UL << SCM_PPMRL_CDRTC_SHIFT)                   /*!< SCM_PPMRL: CDRTC Mask                   */
#define SCM_PPMRL_CDRTC_SHIFT                    12                                                  /*!< SCM_PPMRL: CDRTC Position               */
#define SCM_PPMRL_CDDTIM0_MASK                   (0x01UL << SCM_PPMRL_CDDTIM0_SHIFT)                 /*!< SCM_PPMRL: CDDTIM0 Mask                 */
#define SCM_PPMRL_CDDTIM0_SHIFT                  13                                                  /*!< SCM_PPMRL: CDDTIM0 Position             */
#define SCM_PPMRL_CDDTIM1_MASK                   (0x01UL << SCM_PPMRL_CDDTIM1_SHIFT)                 /*!< SCM_PPMRL: CDDTIM1 Mask                 */
#define SCM_PPMRL_CDDTIM1_SHIFT                  14                                                  /*!< SCM_PPMRL: CDDTIM1 Position             */
#define SCM_PPMRL_CDDTIM2_MASK                   (0x01UL << SCM_PPMRL_CDDTIM2_SHIFT)                 /*!< SCM_PPMRL: CDDTIM2 Mask                 */
#define SCM_PPMRL_CDDTIM2_SHIFT                  15                                                  /*!< SCM_PPMRL: CDDTIM2 Position             */
#define SCM_PPMRL_CDDTIM3_MASK                   (0x01UL << SCM_PPMRL_CDDTIM3_SHIFT)                 /*!< SCM_PPMRL: CDDTIM3 Mask                 */
#define SCM_PPMRL_CDDTIM3_SHIFT                  16                                                  /*!< SCM_PPMRL: CDDTIM3 Position             */
#define SCM_PPMRL_CDINTC0_MASK                   (0x01UL << SCM_PPMRL_CDINTC0_SHIFT)                 /*!< SCM_PPMRL: CDINTC0 Mask                 */
#define SCM_PPMRL_CDINTC0_SHIFT                  17                                                  /*!< SCM_PPMRL: CDINTC0 Position             */
#define SCM_PPMRL_CDINTC1_MASK                   (0x01UL << SCM_PPMRL_CDINTC1_SHIFT)                 /*!< SCM_PPMRL: CDINTC1 Mask                 */
#define SCM_PPMRL_CDINTC1_SHIFT                  18                                                  /*!< SCM_PPMRL: CDINTC1 Position             */
#define SCM_PPMRL_CDFEC_MASK                     (0x01UL << SCM_PPMRL_CDFEC_SHIFT)                   /*!< SCM_PPMRL: CDFEC Mask                   */
#define SCM_PPMRL_CDFEC_SHIFT                    21                                                  /*!< SCM_PPMRL: CDFEC Position               */
/* ------- MPARK Bit Fields                         ------ */
#define SCM_MPARK_LCKOUT_TIME_MASK               (0x0FUL << SCM_MPARK_LCKOUT_TIME_SHIFT)             /*!< SCM_MPARK: LCKOUT_TIME Mask             */
#define SCM_MPARK_LCKOUT_TIME_SHIFT              8                                                   /*!< SCM_MPARK: LCKOUT_TIME Position         */
#define SCM_MPARK_LCKOUT_TIME(x)                 (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_LCKOUT_TIME_SHIFT))&SCM_MPARK_LCKOUT_TIME_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_PRKLAST_MASK                   (0x01UL << SCM_MPARK_PRKLAST_SHIFT)                 /*!< SCM_MPARK: PRKLAST Mask                 */
#define SCM_MPARK_PRKLAST_SHIFT                  12                                                  /*!< SCM_MPARK: PRKLAST Position             */
#define SCM_MPARK_TIMEOUT_MASK                   (0x01UL << SCM_MPARK_TIMEOUT_SHIFT)                 /*!< SCM_MPARK: TIMEOUT Mask                 */
#define SCM_MPARK_TIMEOUT_SHIFT                  13                                                  /*!< SCM_MPARK: TIMEOUT Position             */
#define SCM_MPARK_FIXED_MASK                     (0x01UL << SCM_MPARK_FIXED_SHIFT)                   /*!< SCM_MPARK: FIXED Mask                   */
#define SCM_MPARK_FIXED_SHIFT                    14                                                  /*!< SCM_MPARK: FIXED Position               */
#define SCM_MPARK_M1_PRTY_MASK                   (0x03UL << SCM_MPARK_M1_PRTY_SHIFT)                 /*!< SCM_MPARK: M1_PRTY Mask                 */
#define SCM_MPARK_M1_PRTY_SHIFT                  16                                                  /*!< SCM_MPARK: M1_PRTY Position             */
#define SCM_MPARK_M1_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_M1_PRTY_SHIFT))&SCM_MPARK_M1_PRTY_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_M0_PRTY_MASK                   (0x03UL << SCM_MPARK_M0_PRTY_SHIFT)                 /*!< SCM_MPARK: M0_PRTY Mask                 */
#define SCM_MPARK_M0_PRTY_SHIFT                  18                                                  /*!< SCM_MPARK: M0_PRTY Position             */
#define SCM_MPARK_M0_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_M0_PRTY_SHIFT))&SCM_MPARK_M0_PRTY_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_M2_PRTY_MASK                   (0x03UL << SCM_MPARK_M2_PRTY_SHIFT)                 /*!< SCM_MPARK: M2_PRTY Mask                 */
#define SCM_MPARK_M2_PRTY_SHIFT                  20                                                  /*!< SCM_MPARK: M2_PRTY Position             */
#define SCM_MPARK_M2_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_M2_PRTY_SHIFT))&SCM_MPARK_M2_PRTY_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_BCR24BIT_MASK                  (0x01UL << SCM_MPARK_BCR24BIT_SHIFT)                /*!< SCM_MPARK: BCR24BIT Mask                */
#define SCM_MPARK_BCR24BIT_SHIFT                 24                                                  /*!< SCM_MPARK: BCR24BIT Position            */
#define SCM_MPARK_M2_P_EN_MASK                   (0x01UL << SCM_MPARK_M2_P_EN_SHIFT)                 /*!< SCM_MPARK: M2_P_EN Mask                 */
#define SCM_MPARK_M2_P_EN_SHIFT                  25                                                  /*!< SCM_MPARK: M2_P_EN Position             */
/* ------- MPR Bit Fields                           ------ */
#define SCM_MPR_MPR0_MASK                        (0x01UL << SCM_MPR_MPR0_SHIFT)                      /*!< SCM_MPR: MPR0 Mask                      */
#define SCM_MPR_MPR0_SHIFT                       0                                                   /*!< SCM_MPR: MPR0 Position                  */
#define SCM_MPR_MPR1_MASK                        (0x01UL << SCM_MPR_MPR1_SHIFT)                      /*!< SCM_MPR: MPR1 Mask                      */
#define SCM_MPR_MPR1_SHIFT                       1                                                   /*!< SCM_MPR: MPR1 Position                  */
#define SCM_MPR_MPR2_MASK                        (0x01UL << SCM_MPR_MPR2_SHIFT)                      /*!< SCM_MPR: MPR2 Mask                      */
#define SCM_MPR_MPR2_SHIFT                       2                                                   /*!< SCM_MPR: MPR2 Position                  */
#define SCM_MPR_MPR3_MASK                        (0x01UL << SCM_MPR_MPR3_SHIFT)                      /*!< SCM_MPR: MPR3 Mask                      */
#define SCM_MPR_MPR3_SHIFT                       3                                                   /*!< SCM_MPR: MPR3 Position                  */
/* ------- PPMRS Bit Fields                         ------ */
#define SCM_PPMRS_SMCD_MASK                      (0x1FUL << SCM_PPMRS_SMCD_SHIFT)                    /*!< SCM_PPMRS: SMCD Mask                    */
#define SCM_PPMRS_SMCD_SHIFT                     0                                                   /*!< SCM_PPMRS: SMCD Position                */
#define SCM_PPMRS_SMCD(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_PPMRS_SMCD_SHIFT))&SCM_PPMRS_SMCD_MASK) /*!< SCM_PPMRS                               */
#define SCM_PPMRS_SAMCD_MASK                     (0x01UL << SCM_PPMRS_SAMCD_SHIFT)                   /*!< SCM_PPMRS: SAMCD Mask                   */
#define SCM_PPMRS_SAMCD_SHIFT                    6                                                   /*!< SCM_PPMRS: SAMCD Position               */
/* ------- PPMRC Bit Fields                         ------ */
#define SCM_PPMRC_SMCD_MASK                      (0x1FUL << SCM_PPMRC_SMCD_SHIFT)                    /*!< SCM_PPMRC: SMCD Mask                    */
#define SCM_PPMRC_SMCD_SHIFT                     0                                                   /*!< SCM_PPMRC: SMCD Position                */
#define SCM_PPMRC_SMCD(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_PPMRC_SMCD_SHIFT))&SCM_PPMRC_SMCD_MASK) /*!< SCM_PPMRC                               */
#define SCM_PPMRC_SAMCD_MASK                     (0x01UL << SCM_PPMRC_SAMCD_SHIFT)                   /*!< SCM_PPMRC: SAMCD Mask                   */
#define SCM_PPMRC_SAMCD_SHIFT                    6                                                   /*!< SCM_PPMRC: SAMCD Position               */
/* ------- IPSBMT Bit Fields                        ------ */
#define SCM_IPSBMT_BMT_MASK                      (0x07UL << SCM_IPSBMT_BMT_SHIFT)                    /*!< SCM_IPSBMT: BMT Mask                    */
#define SCM_IPSBMT_BMT_SHIFT                     0                                                   /*!< SCM_IPSBMT: BMT Position                */
#define SCM_IPSBMT_BMT(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_IPSBMT_BMT_SHIFT))&SCM_IPSBMT_BMT_MASK) /*!< SCM_IPSBMT                              */
#define SCM_IPSBMT_BME_MASK                      (0x01UL << SCM_IPSBMT_BME_SHIFT)                    /*!< SCM_IPSBMT: BME Mask                    */
#define SCM_IPSBMT_BME_SHIFT                     4                                                   /*!< SCM_IPSBMT: BME Position                */
/* ------- PACR Bit Fields                          ------ */
#define SCM_PACR_ACCESS_CTRL0_MASK               (0x07UL << SCM_PACR_ACCESS_CTRL0_SHIFT)             /*!< SCM_PACR: ACCESS_CTRL0 Mask             */
#define SCM_PACR_ACCESS_CTRL0_SHIFT              0                                                   /*!< SCM_PACR: ACCESS_CTRL0 Position         */
#define SCM_PACR_ACCESS_CTRL0(x)                 (((uint8_t)(((uint8_t)(x))<<SCM_PACR_ACCESS_CTRL0_SHIFT))&SCM_PACR_ACCESS_CTRL0_MASK) /*!< SCM_PACR                                */
#define SCM_PACR_LOCK0_MASK                      (0x01UL << SCM_PACR_LOCK0_SHIFT)                    /*!< SCM_PACR: LOCK0 Mask                    */
#define SCM_PACR_LOCK0_SHIFT                     3                                                   /*!< SCM_PACR: LOCK0 Position                */
#define SCM_PACR_ACCESS_CTRL1_MASK               (0x07UL << SCM_PACR_ACCESS_CTRL1_SHIFT)             /*!< SCM_PACR: ACCESS_CTRL1 Mask             */
#define SCM_PACR_ACCESS_CTRL1_SHIFT              4                                                   /*!< SCM_PACR: ACCESS_CTRL1 Position         */
#define SCM_PACR_ACCESS_CTRL1(x)                 (((uint8_t)(((uint8_t)(x))<<SCM_PACR_ACCESS_CTRL1_SHIFT))&SCM_PACR_ACCESS_CTRL1_MASK) /*!< SCM_PACR                                */
#define SCM_PACR_LOCK1_MASK                      (0x01UL << SCM_PACR_LOCK1_SHIFT)                    /*!< SCM_PACR: LOCK1 Mask                    */
#define SCM_PACR_LOCK1_SHIFT                     7                                                   /*!< SCM_PACR: LOCK1 Position                */
/* ------- GPACR Bit Fields                         ------ */
#define SCM_GPACR_ACCESS_CTRL_MASK               (0x0FUL << SCM_GPACR_ACCESS_CTRL_SHIFT)             /*!< SCM_GPACR: ACCESS_CTRL Mask             */
#define SCM_GPACR_ACCESS_CTRL_SHIFT              0                                                   /*!< SCM_GPACR: ACCESS_CTRL Position         */
#define SCM_GPACR_ACCESS_CTRL(x)                 (((uint8_t)(((uint8_t)(x))<<SCM_GPACR_ACCESS_CTRL_SHIFT))&SCM_GPACR_ACCESS_CTRL_MASK) /*!< SCM_GPACR                               */
#define SCM_GPACR_LOCK_MASK                      (0x01UL << SCM_GPACR_LOCK_SHIFT)                    /*!< SCM_GPACR: LOCK Mask                    */
#define SCM_GPACR_LOCK_SHIFT                     7                                                   /*!< SCM_GPACR: LOCK Position                */

/* SCM - Peripheral instance base addresses */
#define SCM_BasePtr                    0x40000000UL
#define SCM                            ((SCM_Type *) SCM_BasePtr)
#define SCM_BASE_PTR                   (SCM)

/* ================================================================================ */
/* ================           UART0 (file:MCF522xx_UART0)          ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Rx/Tx
 */
typedef struct {                                /*!<       UART0 Structure                                              */
   union {                                      /*!< 0000: (size=0001)                                                  */
      __IO uint8_t   UMR1;                      /*!< 0000: Mode Registers 1                                             */
      __IO uint8_t   UMR2;                      /*!< 0000: Mode Registers 2                                             */
   };
   __I  uint8_t   RESERVED0[3];                 /*!< 0001:                                                              */
   union {                                      /*!< 0000: (size=0001)                                                  */
      __O  uint8_t   UCSR;                      /*!< 0004: Clock Select Register                                        */
      __I  uint8_t   USR;                       /*!< 0004: Status Register                                              */
   };
   __I  uint8_t   RESERVED1[3];                 /*!< 0005:                                                              */
   __O  uint8_t   UCR;                          /*!< 0008: Command                                                      */
   __I  uint8_t   RESERVED2[3];                 /*!< 0009:                                                              */
   union {                                      /*!< 0000: (size=0001)                                                  */
      __I  uint8_t   URB;                       /*!< 000C: Receive Buffers                                              */
      __O  uint8_t   UTB;                       /*!< 000C: Transmit Buffers                                             */
   };
   __I  uint8_t   RESERVED3[3];                 /*!< 000D:                                                              */
   union {                                      /*!< 0000: (size=0001)                                                  */
      __O  uint8_t   UACR;                      /*!< 0010: Auxiliary Control Register                                   */
      __I  uint8_t   UIPCR;                     /*!< 0010: Input Port Change Register                                   */
   };
   __I  uint8_t   RESERVED4[3];                 /*!< 0011:                                                              */
   union {                                      /*!< 0000: (size=0001)                                                  */
      __O  uint8_t   UIMR;                      /*!< 0014: Interrupt Mask Register                                      */
      __I  uint8_t   UISR;                      /*!< 0014: Interrupt Status Register                                    */
   };
   __I  uint8_t   RESERVED5[3];                 /*!< 0015:                                                              */
   __O  uint8_t   UBG1;                         /*!< 0018: Baud Rate Generator Register 1                               */
   __I  uint8_t   RESERVED6[3];                 /*!< 0019:                                                              */
   __O  uint8_t   UBG2;                         /*!< 001C: Baud Rate Generator Register 2                               */
   __I  uint8_t   RESERVED7[23];                /*!< 001D:                                                              */
   __I  uint8_t   UIP;                          /*!< 0034: Input Port Register                                          */
   __I  uint8_t   RESERVED8[3];                 /*!< 0035:                                                              */
   __O  uint8_t   UOP1;                         /*!< 0038: Port Bit Set Command Register                                */
   __I  uint8_t   RESERVED9[3];                 /*!< 0039:                                                              */
   __O  uint8_t   UOP0;                         /*!< 003C: Port Bit Reset Command Register                              */
} UART_Type;


/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/* ------- UMR1 Bit Fields                          ------ */
#define UART_UMR1_BC_MASK                        (0x03UL << UART_UMR1_BC_SHIFT)                      /*!< UART0_UMR1: BC Mask                     */
#define UART_UMR1_BC_SHIFT                       0                                                   /*!< UART0_UMR1: BC Position                 */
#define UART_UMR1_BC(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR1_BC_SHIFT))&UART_UMR1_BC_MASK) /*!< UART0_UMR1                              */
#define UART_UMR1_PT_MASK                        (0x01UL << UART_UMR1_PT_SHIFT)                      /*!< UART0_UMR1: PT Mask                     */
#define UART_UMR1_PT_SHIFT                       2                                                   /*!< UART0_UMR1: PT Position                 */
#define UART_UMR1_PM_MASK                        (0x03UL << UART_UMR1_PM_SHIFT)                      /*!< UART0_UMR1: PM Mask                     */
#define UART_UMR1_PM_SHIFT                       3                                                   /*!< UART0_UMR1: PM Position                 */
#define UART_UMR1_PM(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR1_PM_SHIFT))&UART_UMR1_PM_MASK) /*!< UART0_UMR1                              */
#define UART_UMR1_ERR_MASK                       (0x01UL << UART_UMR1_ERR_SHIFT)                     /*!< UART0_UMR1: ERR Mask                    */
#define UART_UMR1_ERR_SHIFT                      5                                                   /*!< UART0_UMR1: ERR Position                */
#define UART_UMR1_RXIRQ_MASK                     (0x01UL << UART_UMR1_RXIRQ_SHIFT)                   /*!< UART0_UMR1: RXIRQ Mask                  */
#define UART_UMR1_RXIRQ_SHIFT                    6                                                   /*!< UART0_UMR1: RXIRQ Position              */
#define UART_UMR1_RXRTS_MASK                     (0x01UL << UART_UMR1_RXRTS_SHIFT)                   /*!< UART0_UMR1: RXRTS Mask                  */
#define UART_UMR1_RXRTS_SHIFT                    7                                                   /*!< UART0_UMR1: RXRTS Position              */
/* ------- UMR2 Bit Fields                          ------ */
#define UART_UMR2_SB_MASK                        (0x0FUL << UART_UMR2_SB_SHIFT)                      /*!< UART0_UMR2: SB Mask                     */
#define UART_UMR2_SB_SHIFT                       0                                                   /*!< UART0_UMR2: SB Position                 */
#define UART_UMR2_SB(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR2_SB_SHIFT))&UART_UMR2_SB_MASK) /*!< UART0_UMR2                              */
#define UART_UMR2_TXCTS_MASK                     (0x01UL << UART_UMR2_TXCTS_SHIFT)                   /*!< UART0_UMR2: TXCTS Mask                  */
#define UART_UMR2_TXCTS_SHIFT                    4                                                   /*!< UART0_UMR2: TXCTS Position              */
#define UART_UMR2_TXRTS_MASK                     (0x01UL << UART_UMR2_TXRTS_SHIFT)                   /*!< UART0_UMR2: TXRTS Mask                  */
#define UART_UMR2_TXRTS_SHIFT                    5                                                   /*!< UART0_UMR2: TXRTS Position              */
#define UART_UMR2_CM_MASK                        (0x03UL << UART_UMR2_CM_SHIFT)                      /*!< UART0_UMR2: CM Mask                     */
#define UART_UMR2_CM_SHIFT                       6                                                   /*!< UART0_UMR2: CM Position                 */
#define UART_UMR2_CM(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR2_CM_SHIFT))&UART_UMR2_CM_MASK) /*!< UART0_UMR2                              */
/* ------- UCSR Bit Fields                          ------ */
#define UART_UCSR_TCS_MASK                       (0x0FUL << UART_UCSR_TCS_SHIFT)                     /*!< UART0_UCSR: TCS Mask                    */
#define UART_UCSR_TCS_SHIFT                      0                                                   /*!< UART0_UCSR: TCS Position                */
#define UART_UCSR_TCS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UCSR_TCS_SHIFT))&UART_UCSR_TCS_MASK) /*!< UART0_UCSR                              */
#define UART_UCSR_RCS_MASK                       (0x0FUL << UART_UCSR_RCS_SHIFT)                     /*!< UART0_UCSR: RCS Mask                    */
#define UART_UCSR_RCS_SHIFT                      4                                                   /*!< UART0_UCSR: RCS Position                */
#define UART_UCSR_RCS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UCSR_RCS_SHIFT))&UART_UCSR_RCS_MASK) /*!< UART0_UCSR                              */
/* ------- USR Bit Fields                           ------ */
#define UART_USR_RXRDY_MASK                      (0x01UL << UART_USR_RXRDY_SHIFT)                    /*!< UART0_USR: RXRDY Mask                   */
#define UART_USR_RXRDY_SHIFT                     0                                                   /*!< UART0_USR: RXRDY Position               */
#define UART_USR_FFULL_MASK                      (0x01UL << UART_USR_FFULL_SHIFT)                    /*!< UART0_USR: FFULL Mask                   */
#define UART_USR_FFULL_SHIFT                     1                                                   /*!< UART0_USR: FFULL Position               */
#define UART_USR_TXRDY_MASK                      (0x01UL << UART_USR_TXRDY_SHIFT)                    /*!< UART0_USR: TXRDY Mask                   */
#define UART_USR_TXRDY_SHIFT                     2                                                   /*!< UART0_USR: TXRDY Position               */
#define UART_USR_TXEMP_MASK                      (0x01UL << UART_USR_TXEMP_SHIFT)                    /*!< UART0_USR: TXEMP Mask                   */
#define UART_USR_TXEMP_SHIFT                     3                                                   /*!< UART0_USR: TXEMP Position               */
#define UART_USR_OE_MASK                         (0x01UL << UART_USR_OE_SHIFT)                       /*!< UART0_USR: OE Mask                      */
#define UART_USR_OE_SHIFT                        4                                                   /*!< UART0_USR: OE Position                  */
#define UART_USR_PE_MASK                         (0x01UL << UART_USR_PE_SHIFT)                       /*!< UART0_USR: PE Mask                      */
#define UART_USR_PE_SHIFT                        5                                                   /*!< UART0_USR: PE Position                  */
#define UART_USR_FE_MASK                         (0x01UL << UART_USR_FE_SHIFT)                       /*!< UART0_USR: FE Mask                      */
#define UART_USR_FE_SHIFT                        6                                                   /*!< UART0_USR: FE Position                  */
#define UART_USR_RB_MASK                         (0x01UL << UART_USR_RB_SHIFT)                       /*!< UART0_USR: RB Mask                      */
#define UART_USR_RB_SHIFT                        7                                                   /*!< UART0_USR: RB Position                  */
/* ------- UCR Bit Fields                           ------ */
#define UART_UCR_RC_MASK                         (0x03UL << UART_UCR_RC_SHIFT)                       /*!< UART0_UCR: RC Mask                      */
#define UART_UCR_RC_SHIFT                        0                                                   /*!< UART0_UCR: RC Position                  */
#define UART_UCR_RC(x)                           (((uint8_t)(((uint8_t)(x))<<UART_UCR_RC_SHIFT))&UART_UCR_RC_MASK) /*!< UART0_UCR                               */
#define UART_UCR_TC_MASK                         (0x03UL << UART_UCR_TC_SHIFT)                       /*!< UART0_UCR: TC Mask                      */
#define UART_UCR_TC_SHIFT                        2                                                   /*!< UART0_UCR: TC Position                  */
#define UART_UCR_TC(x)                           (((uint8_t)(((uint8_t)(x))<<UART_UCR_TC_SHIFT))&UART_UCR_TC_MASK) /*!< UART0_UCR                               */
#define UART_UCR_MISC_MASK                       (0x07UL << UART_UCR_MISC_SHIFT)                     /*!< UART0_UCR: MISC Mask                    */
#define UART_UCR_MISC_SHIFT                      4                                                   /*!< UART0_UCR: MISC Position                */
#define UART_UCR_MISC(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UCR_MISC_SHIFT))&UART_UCR_MISC_MASK) /*!< UART0_UCR                               */
/* ------- URB Bit Fields                           ------ */
#define UART_URB_RB_MASK                         (0xFFUL << UART_URB_RB_SHIFT)                       /*!< UART0_URB: RB Mask                      */
#define UART_URB_RB_SHIFT                        0                                                   /*!< UART0_URB: RB Position                  */
#define UART_URB_RB(x)                           (((uint8_t)(((uint8_t)(x))<<UART_URB_RB_SHIFT))&UART_URB_RB_MASK) /*!< UART0_URB                               */
/* ------- UTB Bit Fields                           ------ */
#define UART_UTB_TB_MASK                         (0xFFUL << UART_UTB_TB_SHIFT)                       /*!< UART0_UTB: TB Mask                      */
#define UART_UTB_TB_SHIFT                        0                                                   /*!< UART0_UTB: TB Position                  */
#define UART_UTB_TB(x)                           (((uint8_t)(((uint8_t)(x))<<UART_UTB_TB_SHIFT))&UART_UTB_TB_MASK) /*!< UART0_UTB                               */
/* ------- UACR Bit Fields                          ------ */
#define UART_UACR_IEC_MASK                       (0x01UL << UART_UACR_IEC_SHIFT)                     /*!< UART0_UACR: IEC Mask                    */
#define UART_UACR_IEC_SHIFT                      0                                                   /*!< UART0_UACR: IEC Position                */
/* ------- UIPCR Bit Fields                         ------ */
#define UART_UIPCR_CTS_MASK                      (0x01UL << UART_UIPCR_CTS_SHIFT)                    /*!< UART0_UIPCR: CTS Mask                   */
#define UART_UIPCR_CTS_SHIFT                     0                                                   /*!< UART0_UIPCR: CTS Position               */
#define UART_UIPCR_COS_MASK                      (0x01UL << UART_UIPCR_COS_SHIFT)                    /*!< UART0_UIPCR: COS Mask                   */
#define UART_UIPCR_COS_SHIFT                     4                                                   /*!< UART0_UIPCR: COS Position               */
/* ------- UIMR Bit Fields                          ------ */
#define UART_UIMR_TXRDY_MASK                     (0x01UL << UART_UIMR_TXRDY_SHIFT)                   /*!< UART0_UIMR: TXRDY Mask                  */
#define UART_UIMR_TXRDY_SHIFT                    0                                                   /*!< UART0_UIMR: TXRDY Position              */
#define UART_UIMR_FFULL_RXRDY_MASK               (0x01UL << UART_UIMR_FFULL_RXRDY_SHIFT)             /*!< UART0_UIMR: FFULL_RXRDY Mask            */
#define UART_UIMR_FFULL_RXRDY_SHIFT              1                                                   /*!< UART0_UIMR: FFULL_RXRDY Position        */
#define UART_UIMR_DB_MASK                        (0x01UL << UART_UIMR_DB_SHIFT)                      /*!< UART0_UIMR: DB Mask                     */
#define UART_UIMR_DB_SHIFT                       2                                                   /*!< UART0_UIMR: DB Position                 */
#define UART_UIMR_COS_MASK                       (0x01UL << UART_UIMR_COS_SHIFT)                     /*!< UART0_UIMR: COS Mask                    */
#define UART_UIMR_COS_SHIFT                      7                                                   /*!< UART0_UIMR: COS Position                */
/* ------- UISR Bit Fields                          ------ */
#define UART_UISR_TXRDY_MASK                     (0x01UL << UART_UISR_TXRDY_SHIFT)                   /*!< UART0_UISR: TXRDY Mask                  */
#define UART_UISR_TXRDY_SHIFT                    0                                                   /*!< UART0_UISR: TXRDY Position              */
#define UART_UISR_FFULL_RXRDY_MASK               (0x01UL << UART_UISR_FFULL_RXRDY_SHIFT)             /*!< UART0_UISR: FFULL_RXRDY Mask            */
#define UART_UISR_FFULL_RXRDY_SHIFT              1                                                   /*!< UART0_UISR: FFULL_RXRDY Position        */
#define UART_UISR_DB_MASK                        (0x01UL << UART_UISR_DB_SHIFT)                      /*!< UART0_UISR: DB Mask                     */
#define UART_UISR_DB_SHIFT                       2                                                   /*!< UART0_UISR: DB Position                 */
#define UART_UISR_COS_MASK                       (0x01UL << UART_UISR_COS_SHIFT)                     /*!< UART0_UISR: COS Mask                    */
#define UART_UISR_COS_SHIFT                      7                                                   /*!< UART0_UISR: COS Position                */
/* ------- UBG1 Bit Fields                          ------ */
#define UART_UBG1_Divider_MSB_MASK               (0xFFUL << UART_UBG1_Divider_MSB_SHIFT)             /*!< UART0_UBG1: Divider_MSB Mask            */
#define UART_UBG1_Divider_MSB_SHIFT              0                                                   /*!< UART0_UBG1: Divider_MSB Position        */
#define UART_UBG1_Divider_MSB(x)                 (((uint8_t)(((uint8_t)(x))<<UART_UBG1_Divider_MSB_SHIFT))&UART_UBG1_Divider_MSB_MASK) /*!< UART0_UBG1                              */
/* ------- UBG2 Bit Fields                          ------ */
#define UART_UBG2_Divider_LSB_MASK               (0xFFUL << UART_UBG2_Divider_LSB_SHIFT)             /*!< UART0_UBG2: Divider_LSB Mask            */
#define UART_UBG2_Divider_LSB_SHIFT              0                                                   /*!< UART0_UBG2: Divider_LSB Position        */
#define UART_UBG2_Divider_LSB(x)                 (((uint8_t)(((uint8_t)(x))<<UART_UBG2_Divider_LSB_SHIFT))&UART_UBG2_Divider_LSB_MASK) /*!< UART0_UBG2                              */
/* ------- UIP Bit Fields                           ------ */
#define UART_UIP_CTS_MASK                        (0x01UL << UART_UIP_CTS_SHIFT)                      /*!< UART0_UIP: CTS Mask                     */
#define UART_UIP_CTS_SHIFT                       0                                                   /*!< UART0_UIP: CTS Position                 */
/* ------- UOP1 Bit Fields                          ------ */
#define UART_UOP1_RTS_MASK                       (0x01UL << UART_UOP1_RTS_SHIFT)                     /*!< UART0_UOP1: RTS Mask                    */
#define UART_UOP1_RTS_SHIFT                      0                                                   /*!< UART0_UOP1: RTS Position                */
/* ------- UOP0 Bit Fields                          ------ */
#define UART_UOP0_RTS_MASK                       (0x01UL << UART_UOP0_RTS_SHIFT)                     /*!< UART0_UOP0: RTS Mask                    */
#define UART_UOP0_RTS_SHIFT                      0                                                   /*!< UART0_UOP0: RTS Position                */

/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x40000200UL
#define UART0                          ((UART_Type *) UART0_BasePtr)
#define UART0_BASE_PTR                 (UART0)

/* ================================================================================ */
/* ================           UART1 (derived from UART0)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Rx/Tx
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x40000240UL
#define UART1                          ((UART_Type *) UART1_BasePtr)
#define UART1_BASE_PTR                 (UART1)

/* ================================================================================ */
/* ================           UART2 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Rx/Tx
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x40000280UL
#define UART2                          ((UART_Type *) UART2_BasePtr)
#define UART2_BASE_PTR                 (UART2)
/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif

#ifdef __cplusplus
}
#endif


#endif  /* MCU_MCF5223X */

