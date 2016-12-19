/****************************************************************************************************//**
 * @file     MCF5223x.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MCF5223x.
 *           Equivalent: 
 *
 * @version  V0.0
 * @date     2016/12
 *
 *******************************************************************************************************/

#ifndef MCU_MCF5223X
#define MCU_MCF5223X

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------  Interrupt Number Definition  ------------------------ */

/**
 * Interrupt vector numbers
 */
typedef enum {
/* ------------------------  Processor Exceptions Numbers  ------------------------- */
  Reset_IRQn                    =   1,   /**<   1 Initial PC                                                                       */
  AccessError_IRQn              =   2,   /**<   2 Access Error                                                                     */
  AddressError_IRQn             =   3,   /**<   3 Address Error                                                                    */
  IllegalInstruction_IRQn       =   4,   /**<   4 Illegal Instruction                                                              */
  DivideBy0_IRQn                =   5,   /**<   5 Divide by Zero                                                                   */
  PrivilegeViolation_IRQn       =   8,   /**<   8 Privilege Violation                                                              */
  Trace_IRQn                    =   9,   /**<   9 Trace                                                                            */
  UnimplementedLineA_IRQn       =  10,   /**<  10 Unimplemented Line A                                                             */
  UnimplementedLineF_IRQn       =  11,   /**<  11 Unimplemented Line F                                                             */
  Debug_IRQn                    =  12,   /**<  12 Debug                                                                            */
  FormatError_IRQn              =  14,   /**<  14 Format Error                                                                     */
  SpuriousInt_IRQn              =  24,   /**<  24 Spurious Interrupt                                                               */
  Trap0_IRQn                    =  32,   /**<  32 Trap # 0                                                                         */
  Trap1_IRQn                    =  33,   /**<  33 Trap # 1                                                                         */
  Trap2_IRQn                    =  34,   /**<  34 Trap # 2                                                                         */
  Trap3_IRQn                    =  35,   /**<  35 Trap # 3                                                                         */
  Trap4_IRQn                    =  36,   /**<  36 Trap # 4                                                                         */
  Trap5_IRQn                    =  37,   /**<  37 Trap # 5                                                                         */
  Trap6_IRQn                    =  38,   /**<  38 Trap # 6                                                                         */
  Trap7_IRQn                    =  39,   /**<  39 Trap # 7                                                                         */
  Trap8_IRQn                    =  40,   /**<  40 Trap # 8                                                                         */
  Trap9_IRQn                    =  41,   /**<  41 Trap # 9                                                                         */
  Trap10_IRQn                   =  42,   /**<  42 Trap # 10                                                                        */
  Trap11_IRQn                   =  43,   /**<  43 Trap # 11                                                                        */
  Trap12_IRQn                   =  44,   /**<  44 Trap # 12                                                                        */
  Trap13_IRQn                   =  45,   /**<  45 Trap # 13                                                                        */
  Trap14_IRQn                   =  46,   /**<  46 Trap # 14                                                                        */
  Trap15_IRQn                   =  47,   /**<  47 Trap # 15                                                                        */
/* ----------------------   MCF5223x VectorTable                     ---------------------- */
  EPORT1_IRQn                   =  65,   /**<  65 Edge port flag 1                                                                 */
  EPORT2_IRQn                   =  66,   /**<  66 Edge port flag 2                                                                 */
  EPORT3_IRQn                   =  67,   /**<  67 Edge port flag 3                                                                 */
  EPORT4_IRQn                   =  68,   /**<  68 Edge port flag 4                                                                 */
  EPORT5_IRQn                   =  69,   /**<  69 Edge port flag 5                                                                 */
  EPORT6_IRQn                   =  70,   /**<  70 Edge port flag 6                                                                 */
  EPORT7_IRQn                   =  71,   /**<  71 Edge port flag 7                                                                 */
  SCM_IRQn                      =  72,   /**<  72 Software watchdog timeout                                                        */
  DMA_CH0_IRQn                  =  73,   /**<  73 DMA Channel 0 transfer complete                                                  */
  DMA_CH1_IRQn                  =  74,   /**<  74 DMA Channel 1 transfer complete                                                  */
  DMA_CH2_IRQn                  =  75,   /**<  75 DMA Channel 2 transfer complete                                                  */
  DMA_CH3_IRQn                  =  76,   /**<  76 DMA Channel 3 transfer complete                                                  */
  UART0_IRQn                    =  77,   /**<  77 UART 0 interrupt                                                                 */
  UART1_IRQn                    =  78,   /**<  78 UART 1 interrupt                                                                 */
  UART2_IRQn                    =  79,   /**<  79 UART 2 interrupt                                                                 */
  I2C_IRQn                      =  81,   /**<  81 I2C interrupt                                                                    */
  QSPI_IRQn                     =  82,   /**<  82 QSPI interrupt                                                                   */
  DTIM0_IRQn                    =  83,   /**<  83 DMA Timer 0 interrupt                                                            */
  DTIM1_IRQn                    =  84,   /**<  84 DMA Timer 1 interrupt                                                            */
  DTIM2_IRQn                    =  85,   /**<  85 DMA Timer 2 interrupt                                                            */
  DTIM3_IRQn                    =  86,   /**<  86 DMA Timer 3 interrupt                                                            */
  FEC_TF_IRQn                   =  87,   /**<  87 Transmit frame interrupt                                                         */
  FEC_TB_IRQn                   =  88,   /**<  88 Transmit buffer interrupt                                                        */
  FEC_UN_IRQn                   =  89,   /**<  89 Transmit FIFO underrun                                                           */
  FEC_RL_IRQn                   =  90,   /**<  90 Collision retry limit                                                            */
  FEC_RF_IRQn                   =  91,   /**<  91 Receive frame interrupt                                                          */
  FEC_RB_IRQn                   =  92,   /**<  92 Receive buffer interrupt                                                         */
  FEC_MII_IRQn                  =  93,   /**<  93 MII interrupt                                                                    */
  FEC_LC_IRQn                   =  94,   /**<  94 Late Collision                                                                   */
  FEC_HBERR_IRQn                =  95,   /**<  95 Heart-beat error                                                                 */
  FEC_GRA_IRQn                  =  96,   /**<  96 Graceful stop complete                                                           */
  FEC_EBERR_IRQn                =  97,   /**<  97 Ethernet bus error                                                               */
  FEC_BABT_IRQn                 =  98,   /**<  98 Babbling transmit error                                                          */
  FEC_BABR_IRQn                 =  99,   /**<  99 Babbling receive error                                                           */
  EPHY_IRQn                     = 100,   /**< 100 EPHY interrupt                                                                   */
  GPT_TOF_IRQn                  = 105,   /**< 105 GPT Timer overflow                                                               */
  GPT_PAIF_IRQn                 = 106,   /**< 106 GPT Pulse accumulator input                                                      */
  GPT_PAOVF_IRQn                = 107,   /**< 107 GPT Pulse accumulator overflow                                                   */
  GPT_C0F_IRQn                  = 108,   /**< 108 GPT Timer channel 0                                                              */
  GPT_C1F_IRQn                  = 109,   /**< 109 GPT Timer channel 1                                                              */
  GPT_C2F_IRQn                  = 110,   /**< 110 GPT Timer channel 2                                                              */
  GPT_C3F_IRQn                  = 111,   /**< 111 GPT Timer channel 3                                                              */
  PMM_IRQn                      = 112,   /**< 112 LVD                                                                              */
  ADC_ADCA_IRQn                 = 113,   /**< 113 ADCA conversion complete                                                         */
  ADC_ADCB_IRQn                 = 114,   /**< 114 ADCB conversion complete                                                         */
  ADC_ADCINT_IRQn               = 115,   /**< 115 ADC Interrupt                                                                    */
  PWM_IRQn                      = 116,   /**< 116 PWM interrupt                                                                    */
  RNGA_IRQn                     = 117,   /**< 117 RNGA interrupt                                                                   */
  PIT0_IRQn                     = 119,   /**< 119 PIT 0 interrupt                                                                  */
  PIT1_IRQn                     = 120,   /**< 120 PIT 1 interrupt                                                                  */
  CFM_CBEIF_IRQn                = 122,   /**< 122 CFM SGFM buffer empty                                                            */
  CFM_CCIF_IRQn                 = 123,   /**< 123 CFM SGFM command complete                                                        */
  CFM_PVIF_IRQn                 = 124,   /**< 124 CFM Protection violation                                                         */
  RTC_IRQn                      = 127,   /**< 127 RTC interrupt                                                                    */
} IRQn_Type;

/* -------------------------  Exception Handlers  ------------------------ */
extern void AccessError_Handler(void);         /**< Access Error                                                                     */
extern void AddressError_Handler(void);        /**< Address Error                                                                    */
extern void IllegalInstruction_Handler(void);   /**< Illegal Instruction                                                              */
extern void DivideBy0_Handler(void);           /**< Divide by Zero                                                                   */
extern void PrivilegeViolation_Handler(void);   /**< Privilege Violation                                                              */
extern void Trace_Handler(void);               /**< Trace                                                                            */
extern void UnimplementedLineA_Handler(void);   /**< Unimplemented Line A                                                             */
extern void UnimplementedLineF_Handler(void);   /**< Unimplemented Line F                                                             */
extern void Debug_Handler(void);               /**< Debug                                                                            */
extern void FormatError_Handler(void);         /**< Format Error                                                                     */
extern void SpuriousInt_Handler(void);         /**< Spurious Interrupt                                                               */
extern void Trap0_Handler(void);               /**< Trap # 0                                                                         */
extern void Trap1_Handler(void);               /**< Trap # 1                                                                         */
extern void Trap2_Handler(void);               /**< Trap # 2                                                                         */
extern void Trap3_Handler(void);               /**< Trap # 3                                                                         */
extern void Trap4_Handler(void);               /**< Trap # 4                                                                         */
extern void Trap5_Handler(void);               /**< Trap # 5                                                                         */
extern void Trap6_Handler(void);               /**< Trap # 6                                                                         */
extern void Trap7_Handler(void);               /**< Trap # 7                                                                         */
extern void Trap8_Handler(void);               /**< Trap # 8                                                                         */
extern void Trap9_Handler(void);               /**< Trap # 9                                                                         */
extern void Trap10_Handler(void);              /**< Trap # 10                                                                        */
extern void Trap11_Handler(void);              /**< Trap # 11                                                                        */
extern void Trap12_Handler(void);              /**< Trap # 12                                                                        */
extern void Trap13_Handler(void);              /**< Trap # 13                                                                        */
extern void Trap14_Handler(void);              /**< Trap # 14                                                                        */
extern void Trap15_Handler(void);              /**< Trap # 15                                                                        */
extern void EPORT1_IRQHandler(void);           /**< Edge port flag 1                                                                 */
extern void EPORT2_IRQHandler(void);           /**< Edge port flag 2                                                                 */
extern void EPORT3_IRQHandler(void);           /**< Edge port flag 3                                                                 */
extern void EPORT4_IRQHandler(void);           /**< Edge port flag 4                                                                 */
extern void EPORT5_IRQHandler(void);           /**< Edge port flag 5                                                                 */
extern void EPORT6_IRQHandler(void);           /**< Edge port flag 6                                                                 */
extern void EPORT7_IRQHandler(void);           /**< Edge port flag 7                                                                 */
extern void SCM_IRQHandler(void);              /**< Software watchdog timeout                                                        */
extern void DMA_CH0_IRQHandler(void);          /**< DMA Channel 0 transfer complete                                                  */
extern void DMA_CH1_IRQHandler(void);          /**< DMA Channel 1 transfer complete                                                  */
extern void DMA_CH2_IRQHandler(void);          /**< DMA Channel 2 transfer complete                                                  */
extern void DMA_CH3_IRQHandler(void);          /**< DMA Channel 3 transfer complete                                                  */
extern void UART0_IRQHandler(void);            /**< UART 0 interrupt                                                                 */
extern void UART1_IRQHandler(void);            /**< UART 1 interrupt                                                                 */
extern void UART2_IRQHandler(void);            /**< UART 2 interrupt                                                                 */
extern void I2C_IRQHandler(void);              /**< I2C interrupt                                                                    */
extern void QSPI_IRQHandler(void);             /**< QSPI interrupt                                                                   */
extern void DTIM0_IRQHandler(void);            /**< DMA Timer 0 interrupt                                                            */
extern void DTIM1_IRQHandler(void);            /**< DMA Timer 1 interrupt                                                            */
extern void DTIM2_IRQHandler(void);            /**< DMA Timer 2 interrupt                                                            */
extern void DTIM3_IRQHandler(void);            /**< DMA Timer 3 interrupt                                                            */
extern void FEC_TF_IRQHandler(void);           /**< Transmit frame interrupt                                                         */
extern void FEC_TB_IRQHandler(void);           /**< Transmit buffer interrupt                                                        */
extern void FEC_UN_IRQHandler(void);           /**< Transmit FIFO underrun                                                           */
extern void FEC_RL_IRQHandler(void);           /**< Collision retry limit                                                            */
extern void FEC_RF_IRQHandler(void);           /**< Receive frame interrupt                                                          */
extern void FEC_RB_IRQHandler(void);           /**< Receive buffer interrupt                                                         */
extern void FEC_MII_IRQHandler(void);          /**< MII interrupt                                                                    */
extern void FEC_LC_IRQHandler(void);           /**< Late Collision                                                                   */
extern void FEC_HBERR_IRQHandler(void);        /**< Heart-beat error                                                                 */
extern void FEC_GRA_IRQHandler(void);          /**< Graceful stop complete                                                           */
extern void FEC_EBERR_IRQHandler(void);        /**< Ethernet bus error                                                               */
extern void FEC_BABT_IRQHandler(void);         /**< Babbling transmit error                                                          */
extern void FEC_BABR_IRQHandler(void);         /**< Babbling receive error                                                           */
extern void EPHY_IRQHandler(void);             /**< EPHY interrupt                                                                   */
extern void GPT_TOF_IRQHandler(void);          /**< GPT Timer overflow                                                               */
extern void GPT_PAIF_IRQHandler(void);         /**< GPT Pulse accumulator input                                                      */
extern void GPT_PAOVF_IRQHandler(void);        /**< GPT Pulse accumulator overflow                                                   */
extern void GPT_C0F_IRQHandler(void);          /**< GPT Timer channel 0                                                              */
extern void GPT_C1F_IRQHandler(void);          /**< GPT Timer channel 1                                                              */
extern void GPT_C2F_IRQHandler(void);          /**< GPT Timer channel 2                                                              */
extern void GPT_C3F_IRQHandler(void);          /**< GPT Timer channel 3                                                              */
extern void PMM_IRQHandler(void);              /**< LVD                                                                              */
extern void ADC_ADCA_IRQHandler(void);         /**< ADCA conversion complete                                                         */
extern void ADC_ADCB_IRQHandler(void);         /**< ADCB conversion complete                                                         */
extern void ADC_ADCINT_IRQHandler(void);       /**< ADC Interrupt                                                                    */
extern void PWM_IRQHandler(void);              /**< PWM interrupt                                                                    */
extern void RNGA_IRQHandler(void);             /**< RNGA interrupt                                                                   */
extern void PIT0_IRQHandler(void);             /**< PIT 0 interrupt                                                                  */
extern void PIT1_IRQHandler(void);             /**< PIT 1 interrupt                                                                  */
extern void CFM_CBEIF_IRQHandler(void);        /**< CFM SGFM buffer empty                                                            */
extern void CFM_CCIF_IRQHandler(void);         /**< CFM SGFM command complete                                                        */
extern void CFM_PVIF_IRQHandler(void);         /**< CFM Protection violation                                                         */
extern void RTC_IRQHandler(void);              /**< RTC interrupt                                                                    */

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/**
* @addtogroup Cortex_Core_Configuration_GROUP Cortex Core Configuration
* @brief Configuration of the cm4 Processor and Core Peripherals
* @{
*/
#define __CM3_REV                 0x0100     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          0          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             0          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
#include "core_cfv2.h"          /* Processor and core peripherals     */
#include "system.h"             /* Device specific configuration file */

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
/**
* @addtogroup Peripheral_access_layer_GROUP Device Peripheral Access Layer
* @brief C structs allowing access to peripheral registers
* @{
*/
/**
* @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer
* @brief C Struct for ADC
* @{
*/

/* ================================================================================ */
/* ================           ADC (file:MCF522xx_ADC)              ================ */
/* ================================================================================ */

/**
 * @brief Analogue-to-Digital Converter
The analog-to-digital converter (ADC) consists of two separate and complete ADCs, each with their own
sample and hold circuits. The converters share a common voltage reference and common digital control
module
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC Structure                                                */
   __IO uint16_t  CTRL1;                        /**< 0000: Control Register 1                                           */
   __IO uint16_t  CTRL2;                        /**< 0002: Control Register 2                                           */
   __IO uint16_t  ADZCC;                        /**< 0004: Zero Crossing Control Register                               */
   __IO uint16_t  ADLST1;                       /**< 0006: Channel List Register 1                                      */
   __IO uint16_t  ADLST2;                       /**< 0008: Channel List Register 2                                      */
   __IO uint16_t  ADSDIS;                       /**< 000A: Sample Disable Register                                      */
   __IO uint16_t  ADSTAT;                       /**< 000C: Status Register                                              */
   __IO uint16_t  ADLSTAT;                      /**< 000E: Limit Status Register                                        */
   __IO uint16_t  ADZCSTAT;                     /**< 0010: Zero Crossing Status Register                                */
   __IO uint16_t  ADRSLT[8];                    /**< 0012: Result Registers                                             */
   __IO uint16_t  ADLLMT[8];                    /**< 0022: Low Limit Register                                           */
   __IO uint16_t  ADHLMT[8];                    /**< 0032: High Limit Register                                          */
   __IO uint16_t  ADOFS[8];                     /**< 0042: Offset Register                                              */
   __IO uint16_t  POWER;                        /**< 0052: Power Control Register                                       */
   __IO uint16_t  CAL;                          /**< 0054: Voltage Reference Register                                   */
} ADC_Type;

/**
 * @} */ /* End group ADC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ADC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ADC_Register_Masks_GROUP ADC Register Masks
* @brief Register Masks for ADC
* @{
*/
/* ------- CTRL1 Bit Fields                         ------ */
#define ADC_CTRL1_SMODE_MASK                     (0x7U)                                              /*!< ADC_CTRL1: SMODE Mask                   */
#define ADC_CTRL1_SMODE_SHIFT                    (0U)                                                /*!< ADC_CTRL1: SMODE Position               */
#define ADC_CTRL1_SMODE(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_SMODE_SHIFT))&ADC_CTRL1_SMODE_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_CHNCFG0_MASK                   (0x10U)                                             /*!< ADC_CTRL1: CHNCFG0 Mask                 */
#define ADC_CTRL1_CHNCFG0_SHIFT                  (4U)                                                /*!< ADC_CTRL1: CHNCFG0 Position             */
#define ADC_CTRL1_CHNCFG0(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_CHNCFG0_SHIFT))&ADC_CTRL1_CHNCFG0_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_CHNCFG1_MASK                   (0x20U)                                             /*!< ADC_CTRL1: CHNCFG1 Mask                 */
#define ADC_CTRL1_CHNCFG1_SHIFT                  (5U)                                                /*!< ADC_CTRL1: CHNCFG1 Position             */
#define ADC_CTRL1_CHNCFG1(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_CHNCFG1_SHIFT))&ADC_CTRL1_CHNCFG1_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_CHNCFG2_MASK                   (0x40U)                                             /*!< ADC_CTRL1: CHNCFG2 Mask                 */
#define ADC_CTRL1_CHNCFG2_SHIFT                  (6U)                                                /*!< ADC_CTRL1: CHNCFG2 Position             */
#define ADC_CTRL1_CHNCFG2(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_CHNCFG2_SHIFT))&ADC_CTRL1_CHNCFG2_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_CHNCFG3_MASK                   (0x80U)                                             /*!< ADC_CTRL1: CHNCFG3 Mask                 */
#define ADC_CTRL1_CHNCFG3_SHIFT                  (7U)                                                /*!< ADC_CTRL1: CHNCFG3 Position             */
#define ADC_CTRL1_CHNCFG3(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_CHNCFG3_SHIFT))&ADC_CTRL1_CHNCFG3_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_HLMTIE_MASK                    (0x100U)                                            /*!< ADC_CTRL1: HLMTIE Mask                  */
#define ADC_CTRL1_HLMTIE_SHIFT                   (8U)                                                /*!< ADC_CTRL1: HLMTIE Position              */
#define ADC_CTRL1_HLMTIE(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_HLMTIE_SHIFT))&ADC_CTRL1_HLMTIE_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_LLMTIE_MASK                    (0x200U)                                            /*!< ADC_CTRL1: LLMTIE Mask                  */
#define ADC_CTRL1_LLMTIE_SHIFT                   (9U)                                                /*!< ADC_CTRL1: LLMTIE Position              */
#define ADC_CTRL1_LLMTIE(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_LLMTIE_SHIFT))&ADC_CTRL1_LLMTIE_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_ZCIE_MASK                      (0x400U)                                            /*!< ADC_CTRL1: ZCIE Mask                    */
#define ADC_CTRL1_ZCIE_SHIFT                     (10U)                                               /*!< ADC_CTRL1: ZCIE Position                */
#define ADC_CTRL1_ZCIE(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_ZCIE_SHIFT))&ADC_CTRL1_ZCIE_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_EOSIE0_MASK                    (0x800U)                                            /*!< ADC_CTRL1: EOSIE0 Mask                  */
#define ADC_CTRL1_EOSIE0_SHIFT                   (11U)                                               /*!< ADC_CTRL1: EOSIE0 Position              */
#define ADC_CTRL1_EOSIE0(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_EOSIE0_SHIFT))&ADC_CTRL1_EOSIE0_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_SYNC0_MASK                     (0x1000U)                                           /*!< ADC_CTRL1: SYNC0 Mask                   */
#define ADC_CTRL1_SYNC0_SHIFT                    (12U)                                               /*!< ADC_CTRL1: SYNC0 Position               */
#define ADC_CTRL1_SYNC0(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_SYNC0_SHIFT))&ADC_CTRL1_SYNC0_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_START0_MASK                    (0x2000U)                                           /*!< ADC_CTRL1: START0 Mask                  */
#define ADC_CTRL1_START0_SHIFT                   (13U)                                               /*!< ADC_CTRL1: START0 Position              */
#define ADC_CTRL1_START0(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_START0_SHIFT))&ADC_CTRL1_START0_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_STOP0_MASK                     (0x4000U)                                           /*!< ADC_CTRL1: STOP0 Mask                   */
#define ADC_CTRL1_STOP0_SHIFT                    (14U)                                               /*!< ADC_CTRL1: STOP0 Position               */
#define ADC_CTRL1_STOP0(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_STOP0_SHIFT))&ADC_CTRL1_STOP0_MASK) /*!< ADC_CTRL1                               */
/* ------- CTRL2 Bit Fields                         ------ */
#define ADC_CTRL2_DIV_MASK                       (0x1FU)                                             /*!< ADC_CTRL2: DIV Mask                     */
#define ADC_CTRL2_DIV_SHIFT                      (0U)                                                /*!< ADC_CTRL2: DIV Position                 */
#define ADC_CTRL2_DIV(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_DIV_SHIFT))&ADC_CTRL2_DIV_MASK) /*!< ADC_CTRL2                               */
#define ADC_CTRL2_SIMULT_MASK                    (0x20U)                                             /*!< ADC_CTRL2: SIMULT Mask                  */
#define ADC_CTRL2_SIMULT_SHIFT                   (5U)                                                /*!< ADC_CTRL2: SIMULT Position              */
#define ADC_CTRL2_SIMULT(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_SIMULT_SHIFT))&ADC_CTRL2_SIMULT_MASK) /*!< ADC_CTRL2                               */
#define ADC_CTRL2_EOSIE1_MASK                    (0x800U)                                            /*!< ADC_CTRL2: EOSIE1 Mask                  */
#define ADC_CTRL2_EOSIE1_SHIFT                   (11U)                                               /*!< ADC_CTRL2: EOSIE1 Position              */
#define ADC_CTRL2_EOSIE1(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_EOSIE1_SHIFT))&ADC_CTRL2_EOSIE1_MASK) /*!< ADC_CTRL2                               */
#define ADC_CTRL2_SYNC1_MASK                     (0x1000U)                                           /*!< ADC_CTRL2: SYNC1 Mask                   */
#define ADC_CTRL2_SYNC1_SHIFT                    (12U)                                               /*!< ADC_CTRL2: SYNC1 Position               */
#define ADC_CTRL2_SYNC1(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_SYNC1_SHIFT))&ADC_CTRL2_SYNC1_MASK) /*!< ADC_CTRL2                               */
#define ADC_CTRL2_START1_MASK                    (0x2000U)                                           /*!< ADC_CTRL2: START1 Mask                  */
#define ADC_CTRL2_START1_SHIFT                   (13U)                                               /*!< ADC_CTRL2: START1 Position              */
#define ADC_CTRL2_START1(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_START1_SHIFT))&ADC_CTRL2_START1_MASK) /*!< ADC_CTRL2                               */
#define ADC_CTRL2_STOP1_MASK                     (0x4000U)                                           /*!< ADC_CTRL2: STOP1 Mask                   */
#define ADC_CTRL2_STOP1_SHIFT                    (14U)                                               /*!< ADC_CTRL2: STOP1 Position               */
#define ADC_CTRL2_STOP1(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_STOP1_SHIFT))&ADC_CTRL2_STOP1_MASK) /*!< ADC_CTRL2                               */
/* ------- ADZCC Bit Fields                         ------ */
#define ADC_ADZCC_ZCE0_MASK                      (0x3U)                                              /*!< ADC_ADZCC: ZCE0 Mask                    */
#define ADC_ADZCC_ZCE0_SHIFT                     (0U)                                                /*!< ADC_ADZCC: ZCE0 Position                */
#define ADC_ADZCC_ZCE0(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE0_SHIFT))&ADC_ADZCC_ZCE0_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE1_MASK                      (0xCU)                                              /*!< ADC_ADZCC: ZCE1 Mask                    */
#define ADC_ADZCC_ZCE1_SHIFT                     (2U)                                                /*!< ADC_ADZCC: ZCE1 Position                */
#define ADC_ADZCC_ZCE1(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE1_SHIFT))&ADC_ADZCC_ZCE1_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE2_MASK                      (0x30U)                                             /*!< ADC_ADZCC: ZCE2 Mask                    */
#define ADC_ADZCC_ZCE2_SHIFT                     (4U)                                                /*!< ADC_ADZCC: ZCE2 Position                */
#define ADC_ADZCC_ZCE2(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE2_SHIFT))&ADC_ADZCC_ZCE2_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE3_MASK                      (0xC0U)                                             /*!< ADC_ADZCC: ZCE3 Mask                    */
#define ADC_ADZCC_ZCE3_SHIFT                     (6U)                                                /*!< ADC_ADZCC: ZCE3 Position                */
#define ADC_ADZCC_ZCE3(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE3_SHIFT))&ADC_ADZCC_ZCE3_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE4_MASK                      (0x300U)                                            /*!< ADC_ADZCC: ZCE4 Mask                    */
#define ADC_ADZCC_ZCE4_SHIFT                     (8U)                                                /*!< ADC_ADZCC: ZCE4 Position                */
#define ADC_ADZCC_ZCE4(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE4_SHIFT))&ADC_ADZCC_ZCE4_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE5_MASK                      (0xC00U)                                            /*!< ADC_ADZCC: ZCE5 Mask                    */
#define ADC_ADZCC_ZCE5_SHIFT                     (10U)                                               /*!< ADC_ADZCC: ZCE5 Position                */
#define ADC_ADZCC_ZCE5(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE5_SHIFT))&ADC_ADZCC_ZCE5_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE6_MASK                      (0x3000U)                                           /*!< ADC_ADZCC: ZCE6 Mask                    */
#define ADC_ADZCC_ZCE6_SHIFT                     (12U)                                               /*!< ADC_ADZCC: ZCE6 Position                */
#define ADC_ADZCC_ZCE6(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE6_SHIFT))&ADC_ADZCC_ZCE6_MASK) /*!< ADC_ADZCC                               */
#define ADC_ADZCC_ZCE7_MASK                      (0xC000U)                                           /*!< ADC_ADZCC: ZCE7 Mask                    */
#define ADC_ADZCC_ZCE7_SHIFT                     (14U)                                               /*!< ADC_ADZCC: ZCE7 Position                */
#define ADC_ADZCC_ZCE7(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADZCC_ZCE7_SHIFT))&ADC_ADZCC_ZCE7_MASK) /*!< ADC_ADZCC                               */
/* ------- ADLST1 Bit Fields                        ------ */
#define ADC_ADLST1_SAMPLE0_MASK                  (0x7U)                                              /*!< ADC_ADLST1: SAMPLE0 Mask                */
#define ADC_ADLST1_SAMPLE0_SHIFT                 (0U)                                                /*!< ADC_ADLST1: SAMPLE0 Position            */
#define ADC_ADLST1_SAMPLE0(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST1_SAMPLE0_SHIFT))&ADC_ADLST1_SAMPLE0_MASK) /*!< ADC_ADLST1                              */
#define ADC_ADLST1_SAMPLE1_MASK                  (0x70U)                                             /*!< ADC_ADLST1: SAMPLE1 Mask                */
#define ADC_ADLST1_SAMPLE1_SHIFT                 (4U)                                                /*!< ADC_ADLST1: SAMPLE1 Position            */
#define ADC_ADLST1_SAMPLE1(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST1_SAMPLE1_SHIFT))&ADC_ADLST1_SAMPLE1_MASK) /*!< ADC_ADLST1                              */
#define ADC_ADLST1_SAMPLE2_MASK                  (0x700U)                                            /*!< ADC_ADLST1: SAMPLE2 Mask                */
#define ADC_ADLST1_SAMPLE2_SHIFT                 (8U)                                                /*!< ADC_ADLST1: SAMPLE2 Position            */
#define ADC_ADLST1_SAMPLE2(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST1_SAMPLE2_SHIFT))&ADC_ADLST1_SAMPLE2_MASK) /*!< ADC_ADLST1                              */
#define ADC_ADLST1_SAMPLE3_MASK                  (0x7000U)                                           /*!< ADC_ADLST1: SAMPLE3 Mask                */
#define ADC_ADLST1_SAMPLE3_SHIFT                 (12U)                                               /*!< ADC_ADLST1: SAMPLE3 Position            */
#define ADC_ADLST1_SAMPLE3(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST1_SAMPLE3_SHIFT))&ADC_ADLST1_SAMPLE3_MASK) /*!< ADC_ADLST1                              */
/* ------- ADLST2 Bit Fields                        ------ */
#define ADC_ADLST2_SAMPLE4_MASK                  (0x7U)                                              /*!< ADC_ADLST2: SAMPLE4 Mask                */
#define ADC_ADLST2_SAMPLE4_SHIFT                 (0U)                                                /*!< ADC_ADLST2: SAMPLE4 Position            */
#define ADC_ADLST2_SAMPLE4(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST2_SAMPLE4_SHIFT))&ADC_ADLST2_SAMPLE4_MASK) /*!< ADC_ADLST2                              */
#define ADC_ADLST2_SAMPLE5_MASK                  (0x70U)                                             /*!< ADC_ADLST2: SAMPLE5 Mask                */
#define ADC_ADLST2_SAMPLE5_SHIFT                 (4U)                                                /*!< ADC_ADLST2: SAMPLE5 Position            */
#define ADC_ADLST2_SAMPLE5(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST2_SAMPLE5_SHIFT))&ADC_ADLST2_SAMPLE5_MASK) /*!< ADC_ADLST2                              */
#define ADC_ADLST2_SAMPLE6_MASK                  (0x700U)                                            /*!< ADC_ADLST2: SAMPLE6 Mask                */
#define ADC_ADLST2_SAMPLE6_SHIFT                 (8U)                                                /*!< ADC_ADLST2: SAMPLE6 Position            */
#define ADC_ADLST2_SAMPLE6(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST2_SAMPLE6_SHIFT))&ADC_ADLST2_SAMPLE6_MASK) /*!< ADC_ADLST2                              */
#define ADC_ADLST2_SAMPLE7_MASK                  (0x7000U)                                           /*!< ADC_ADLST2: SAMPLE7 Mask                */
#define ADC_ADLST2_SAMPLE7_SHIFT                 (12U)                                               /*!< ADC_ADLST2: SAMPLE7 Position            */
#define ADC_ADLST2_SAMPLE7(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_ADLST2_SAMPLE7_SHIFT))&ADC_ADLST2_SAMPLE7_MASK) /*!< ADC_ADLST2                              */
/* ------- ADSDIS Bit Fields                        ------ */
#define ADC_ADSDIS_DS0_MASK                      (0x1U)                                              /*!< ADC_ADSDIS: DS0 Mask                    */
#define ADC_ADSDIS_DS0_SHIFT                     (0U)                                                /*!< ADC_ADSDIS: DS0 Position                */
#define ADC_ADSDIS_DS0(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSDIS_DS0_SHIFT))&ADC_ADSDIS_DS0_MASK) /*!< ADC_ADSDIS                              */
#define ADC_ADSDIS_DS1_MASK                      (0x2U)                                              /*!< ADC_ADSDIS: DS1 Mask                    */
#define ADC_ADSDIS_DS1_SHIFT                     (1U)                                                /*!< ADC_ADSDIS: DS1 Position                */
#define ADC_ADSDIS_DS1(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSDIS_DS1_SHIFT))&ADC_ADSDIS_DS1_MASK) /*!< ADC_ADSDIS                              */
#define ADC_ADSDIS_DS2_MASK                      (0x4U)                                              /*!< ADC_ADSDIS: DS2 Mask                    */
#define ADC_ADSDIS_DS2_SHIFT                     (2U)                                                /*!< ADC_ADSDIS: DS2 Position                */
#define ADC_ADSDIS_DS2(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSDIS_DS2_SHIFT))&ADC_ADSDIS_DS2_MASK) /*!< ADC_ADSDIS                              */
#define ADC_ADSDIS_DS3_MASK                      (0x8U)                                              /*!< ADC_ADSDIS: DS3 Mask                    */
#define ADC_ADSDIS_DS3_SHIFT                     (3U)                                                /*!< ADC_ADSDIS: DS3 Position                */
#define ADC_ADSDIS_DS3(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSDIS_DS3_SHIFT))&ADC_ADSDIS_DS3_MASK) /*!< ADC_ADSDIS                              */
#define ADC_ADSDIS_DS4_MASK                      (0x10U)                                             /*!< ADC_ADSDIS: DS4 Mask                    */
#define ADC_ADSDIS_DS4_SHIFT                     (4U)                                                /*!< ADC_ADSDIS: DS4 Position                */
#define ADC_ADSDIS_DS4(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSDIS_DS4_SHIFT))&ADC_ADSDIS_DS4_MASK) /*!< ADC_ADSDIS                              */
#define ADC_ADSDIS_DS5_MASK                      (0x20U)                                             /*!< ADC_ADSDIS: DS5 Mask                    */
#define ADC_ADSDIS_DS5_SHIFT                     (5U)                                                /*!< ADC_ADSDIS: DS5 Position                */
#define ADC_ADSDIS_DS5(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSDIS_DS5_SHIFT))&ADC_ADSDIS_DS5_MASK) /*!< ADC_ADSDIS                              */
#define ADC_ADSDIS_DS6_MASK                      (0x40U)                                             /*!< ADC_ADSDIS: DS6 Mask                    */
#define ADC_ADSDIS_DS6_SHIFT                     (6U)                                                /*!< ADC_ADSDIS: DS6 Position                */
#define ADC_ADSDIS_DS6(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSDIS_DS6_SHIFT))&ADC_ADSDIS_DS6_MASK) /*!< ADC_ADSDIS                              */
#define ADC_ADSDIS_DS7_MASK                      (0x80U)                                             /*!< ADC_ADSDIS: DS7 Mask                    */
#define ADC_ADSDIS_DS7_SHIFT                     (7U)                                                /*!< ADC_ADSDIS: DS7 Position                */
#define ADC_ADSDIS_DS7(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSDIS_DS7_SHIFT))&ADC_ADSDIS_DS7_MASK) /*!< ADC_ADSDIS                              */
/* ------- ADSTAT Bit Fields                        ------ */
#define ADC_ADSTAT_RDY0_MASK                     (0x1U)                                              /*!< ADC_ADSTAT: RDY0 Mask                   */
#define ADC_ADSTAT_RDY0_SHIFT                    (0U)                                                /*!< ADC_ADSTAT: RDY0 Position               */
#define ADC_ADSTAT_RDY0(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_RDY0_SHIFT))&ADC_ADSTAT_RDY0_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_RDY1_MASK                     (0x2U)                                              /*!< ADC_ADSTAT: RDY1 Mask                   */
#define ADC_ADSTAT_RDY1_SHIFT                    (1U)                                                /*!< ADC_ADSTAT: RDY1 Position               */
#define ADC_ADSTAT_RDY1(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_RDY1_SHIFT))&ADC_ADSTAT_RDY1_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_RDY2_MASK                     (0x4U)                                              /*!< ADC_ADSTAT: RDY2 Mask                   */
#define ADC_ADSTAT_RDY2_SHIFT                    (2U)                                                /*!< ADC_ADSTAT: RDY2 Position               */
#define ADC_ADSTAT_RDY2(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_RDY2_SHIFT))&ADC_ADSTAT_RDY2_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_RDY3_MASK                     (0x8U)                                              /*!< ADC_ADSTAT: RDY3 Mask                   */
#define ADC_ADSTAT_RDY3_SHIFT                    (3U)                                                /*!< ADC_ADSTAT: RDY3 Position               */
#define ADC_ADSTAT_RDY3(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_RDY3_SHIFT))&ADC_ADSTAT_RDY3_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_RDY4_MASK                     (0x10U)                                             /*!< ADC_ADSTAT: RDY4 Mask                   */
#define ADC_ADSTAT_RDY4_SHIFT                    (4U)                                                /*!< ADC_ADSTAT: RDY4 Position               */
#define ADC_ADSTAT_RDY4(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_RDY4_SHIFT))&ADC_ADSTAT_RDY4_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_RDY5_MASK                     (0x20U)                                             /*!< ADC_ADSTAT: RDY5 Mask                   */
#define ADC_ADSTAT_RDY5_SHIFT                    (5U)                                                /*!< ADC_ADSTAT: RDY5 Position               */
#define ADC_ADSTAT_RDY5(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_RDY5_SHIFT))&ADC_ADSTAT_RDY5_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_RDY6_MASK                     (0x40U)                                             /*!< ADC_ADSTAT: RDY6 Mask                   */
#define ADC_ADSTAT_RDY6_SHIFT                    (6U)                                                /*!< ADC_ADSTAT: RDY6 Position               */
#define ADC_ADSTAT_RDY6(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_RDY6_SHIFT))&ADC_ADSTAT_RDY6_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_RDY7_MASK                     (0x80U)                                             /*!< ADC_ADSTAT: RDY7 Mask                   */
#define ADC_ADSTAT_RDY7_SHIFT                    (7U)                                                /*!< ADC_ADSTAT: RDY7 Position               */
#define ADC_ADSTAT_RDY7(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_RDY7_SHIFT))&ADC_ADSTAT_RDY7_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_HLMTI_MASK                    (0x100U)                                            /*!< ADC_ADSTAT: HLMTI Mask                  */
#define ADC_ADSTAT_HLMTI_SHIFT                   (8U)                                                /*!< ADC_ADSTAT: HLMTI Position              */
#define ADC_ADSTAT_HLMTI(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_HLMTI_SHIFT))&ADC_ADSTAT_HLMTI_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_LLMTI_MASK                    (0x200U)                                            /*!< ADC_ADSTAT: LLMTI Mask                  */
#define ADC_ADSTAT_LLMTI_SHIFT                   (9U)                                                /*!< ADC_ADSTAT: LLMTI Position              */
#define ADC_ADSTAT_LLMTI(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_LLMTI_SHIFT))&ADC_ADSTAT_LLMTI_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_ZCI_MASK                      (0x400U)                                            /*!< ADC_ADSTAT: ZCI Mask                    */
#define ADC_ADSTAT_ZCI_SHIFT                     (10U)                                               /*!< ADC_ADSTAT: ZCI Position                */
#define ADC_ADSTAT_ZCI(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_ZCI_SHIFT))&ADC_ADSTAT_ZCI_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_EOSI0_MASK                    (0x800U)                                            /*!< ADC_ADSTAT: EOSI0 Mask                  */
#define ADC_ADSTAT_EOSI0_SHIFT                   (11U)                                               /*!< ADC_ADSTAT: EOSI0 Position              */
#define ADC_ADSTAT_EOSI0(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_EOSI0_SHIFT))&ADC_ADSTAT_EOSI0_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_EOSI1_MASK                    (0x1000U)                                           /*!< ADC_ADSTAT: EOSI1 Mask                  */
#define ADC_ADSTAT_EOSI1_SHIFT                   (12U)                                               /*!< ADC_ADSTAT: EOSI1 Position              */
#define ADC_ADSTAT_EOSI1(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_EOSI1_SHIFT))&ADC_ADSTAT_EOSI1_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_CIP1_MASK                     (0x4000U)                                           /*!< ADC_ADSTAT: CIP1 Mask                   */
#define ADC_ADSTAT_CIP1_SHIFT                    (14U)                                               /*!< ADC_ADSTAT: CIP1 Position               */
#define ADC_ADSTAT_CIP1(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_CIP1_SHIFT))&ADC_ADSTAT_CIP1_MASK) /*!< ADC_ADSTAT                              */
#define ADC_ADSTAT_CIP0_MASK                     (0x8000U)                                           /*!< ADC_ADSTAT: CIP0 Mask                   */
#define ADC_ADSTAT_CIP0_SHIFT                    (15U)                                               /*!< ADC_ADSTAT: CIP0 Position               */
#define ADC_ADSTAT_CIP0(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADSTAT_CIP0_SHIFT))&ADC_ADSTAT_CIP0_MASK) /*!< ADC_ADSTAT                              */
/* ------- ADLSTAT Bit Fields                       ------ */
#define ADC_ADLSTAT_LLS0_MASK                    (0x1U)                                              /*!< ADC_ADLSTAT: LLS0 Mask                  */
#define ADC_ADLSTAT_LLS0_SHIFT                   (0U)                                                /*!< ADC_ADLSTAT: LLS0 Position              */
#define ADC_ADLSTAT_LLS0(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_LLS0_SHIFT))&ADC_ADLSTAT_LLS0_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_LLS1_MASK                    (0x2U)                                              /*!< ADC_ADLSTAT: LLS1 Mask                  */
#define ADC_ADLSTAT_LLS1_SHIFT                   (1U)                                                /*!< ADC_ADLSTAT: LLS1 Position              */
#define ADC_ADLSTAT_LLS1(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_LLS1_SHIFT))&ADC_ADLSTAT_LLS1_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_LLS2_MASK                    (0x4U)                                              /*!< ADC_ADLSTAT: LLS2 Mask                  */
#define ADC_ADLSTAT_LLS2_SHIFT                   (2U)                                                /*!< ADC_ADLSTAT: LLS2 Position              */
#define ADC_ADLSTAT_LLS2(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_LLS2_SHIFT))&ADC_ADLSTAT_LLS2_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_LLS3_MASK                    (0x8U)                                              /*!< ADC_ADLSTAT: LLS3 Mask                  */
#define ADC_ADLSTAT_LLS3_SHIFT                   (3U)                                                /*!< ADC_ADLSTAT: LLS3 Position              */
#define ADC_ADLSTAT_LLS3(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_LLS3_SHIFT))&ADC_ADLSTAT_LLS3_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_LLS4_MASK                    (0x10U)                                             /*!< ADC_ADLSTAT: LLS4 Mask                  */
#define ADC_ADLSTAT_LLS4_SHIFT                   (4U)                                                /*!< ADC_ADLSTAT: LLS4 Position              */
#define ADC_ADLSTAT_LLS4(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_LLS4_SHIFT))&ADC_ADLSTAT_LLS4_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_LLS5_MASK                    (0x20U)                                             /*!< ADC_ADLSTAT: LLS5 Mask                  */
#define ADC_ADLSTAT_LLS5_SHIFT                   (5U)                                                /*!< ADC_ADLSTAT: LLS5 Position              */
#define ADC_ADLSTAT_LLS5(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_LLS5_SHIFT))&ADC_ADLSTAT_LLS5_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_LLS6_MASK                    (0x40U)                                             /*!< ADC_ADLSTAT: LLS6 Mask                  */
#define ADC_ADLSTAT_LLS6_SHIFT                   (6U)                                                /*!< ADC_ADLSTAT: LLS6 Position              */
#define ADC_ADLSTAT_LLS6(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_LLS6_SHIFT))&ADC_ADLSTAT_LLS6_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_LLS7_MASK                    (0x80U)                                             /*!< ADC_ADLSTAT: LLS7 Mask                  */
#define ADC_ADLSTAT_LLS7_SHIFT                   (7U)                                                /*!< ADC_ADLSTAT: LLS7 Position              */
#define ADC_ADLSTAT_LLS7(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_LLS7_SHIFT))&ADC_ADLSTAT_LLS7_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_HLS0_MASK                    (0x100U)                                            /*!< ADC_ADLSTAT: HLS0 Mask                  */
#define ADC_ADLSTAT_HLS0_SHIFT                   (8U)                                                /*!< ADC_ADLSTAT: HLS0 Position              */
#define ADC_ADLSTAT_HLS0(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_HLS0_SHIFT))&ADC_ADLSTAT_HLS0_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_HLS1_MASK                    (0x200U)                                            /*!< ADC_ADLSTAT: HLS1 Mask                  */
#define ADC_ADLSTAT_HLS1_SHIFT                   (9U)                                                /*!< ADC_ADLSTAT: HLS1 Position              */
#define ADC_ADLSTAT_HLS1(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_HLS1_SHIFT))&ADC_ADLSTAT_HLS1_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_HLS2_MASK                    (0x400U)                                            /*!< ADC_ADLSTAT: HLS2 Mask                  */
#define ADC_ADLSTAT_HLS2_SHIFT                   (10U)                                               /*!< ADC_ADLSTAT: HLS2 Position              */
#define ADC_ADLSTAT_HLS2(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_HLS2_SHIFT))&ADC_ADLSTAT_HLS2_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_HLS3_MASK                    (0x800U)                                            /*!< ADC_ADLSTAT: HLS3 Mask                  */
#define ADC_ADLSTAT_HLS3_SHIFT                   (11U)                                               /*!< ADC_ADLSTAT: HLS3 Position              */
#define ADC_ADLSTAT_HLS3(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_HLS3_SHIFT))&ADC_ADLSTAT_HLS3_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_HLS4_MASK                    (0x1000U)                                           /*!< ADC_ADLSTAT: HLS4 Mask                  */
#define ADC_ADLSTAT_HLS4_SHIFT                   (12U)                                               /*!< ADC_ADLSTAT: HLS4 Position              */
#define ADC_ADLSTAT_HLS4(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_HLS4_SHIFT))&ADC_ADLSTAT_HLS4_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_HLS5_MASK                    (0x2000U)                                           /*!< ADC_ADLSTAT: HLS5 Mask                  */
#define ADC_ADLSTAT_HLS5_SHIFT                   (13U)                                               /*!< ADC_ADLSTAT: HLS5 Position              */
#define ADC_ADLSTAT_HLS5(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_HLS5_SHIFT))&ADC_ADLSTAT_HLS5_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_HLS6_MASK                    (0x4000U)                                           /*!< ADC_ADLSTAT: HLS6 Mask                  */
#define ADC_ADLSTAT_HLS6_SHIFT                   (14U)                                               /*!< ADC_ADLSTAT: HLS6 Position              */
#define ADC_ADLSTAT_HLS6(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_HLS6_SHIFT))&ADC_ADLSTAT_HLS6_MASK) /*!< ADC_ADLSTAT                             */
#define ADC_ADLSTAT_HLS7_MASK                    (0x8000U)                                           /*!< ADC_ADLSTAT: HLS7 Mask                  */
#define ADC_ADLSTAT_HLS7_SHIFT                   (15U)                                               /*!< ADC_ADLSTAT: HLS7 Position              */
#define ADC_ADLSTAT_HLS7(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADLSTAT_HLS7_SHIFT))&ADC_ADLSTAT_HLS7_MASK) /*!< ADC_ADLSTAT                             */
/* ------- ADZCSTAT Bit Fields                      ------ */
#define ADC_ADZCSTAT_ZCS0_MASK                   (0x1U)                                              /*!< ADC_ADZCSTAT: ZCS0 Mask                 */
#define ADC_ADZCSTAT_ZCS0_SHIFT                  (0U)                                                /*!< ADC_ADZCSTAT: ZCS0 Position             */
#define ADC_ADZCSTAT_ZCS0(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ADZCSTAT_ZCS0_SHIFT))&ADC_ADZCSTAT_ZCS0_MASK) /*!< ADC_ADZCSTAT                            */
#define ADC_ADZCSTAT_ZCS1_MASK                   (0x2U)                                              /*!< ADC_ADZCSTAT: ZCS1 Mask                 */
#define ADC_ADZCSTAT_ZCS1_SHIFT                  (1U)                                                /*!< ADC_ADZCSTAT: ZCS1 Position             */
#define ADC_ADZCSTAT_ZCS1(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ADZCSTAT_ZCS1_SHIFT))&ADC_ADZCSTAT_ZCS1_MASK) /*!< ADC_ADZCSTAT                            */
#define ADC_ADZCSTAT_ZCS2_MASK                   (0x4U)                                              /*!< ADC_ADZCSTAT: ZCS2 Mask                 */
#define ADC_ADZCSTAT_ZCS2_SHIFT                  (2U)                                                /*!< ADC_ADZCSTAT: ZCS2 Position             */
#define ADC_ADZCSTAT_ZCS2(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ADZCSTAT_ZCS2_SHIFT))&ADC_ADZCSTAT_ZCS2_MASK) /*!< ADC_ADZCSTAT                            */
#define ADC_ADZCSTAT_ZCS3_MASK                   (0x8U)                                              /*!< ADC_ADZCSTAT: ZCS3 Mask                 */
#define ADC_ADZCSTAT_ZCS3_SHIFT                  (3U)                                                /*!< ADC_ADZCSTAT: ZCS3 Position             */
#define ADC_ADZCSTAT_ZCS3(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ADZCSTAT_ZCS3_SHIFT))&ADC_ADZCSTAT_ZCS3_MASK) /*!< ADC_ADZCSTAT                            */
#define ADC_ADZCSTAT_ZCS4_MASK                   (0x10U)                                             /*!< ADC_ADZCSTAT: ZCS4 Mask                 */
#define ADC_ADZCSTAT_ZCS4_SHIFT                  (4U)                                                /*!< ADC_ADZCSTAT: ZCS4 Position             */
#define ADC_ADZCSTAT_ZCS4(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ADZCSTAT_ZCS4_SHIFT))&ADC_ADZCSTAT_ZCS4_MASK) /*!< ADC_ADZCSTAT                            */
#define ADC_ADZCSTAT_ZCS5_MASK                   (0x20U)                                             /*!< ADC_ADZCSTAT: ZCS5 Mask                 */
#define ADC_ADZCSTAT_ZCS5_SHIFT                  (5U)                                                /*!< ADC_ADZCSTAT: ZCS5 Position             */
#define ADC_ADZCSTAT_ZCS5(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ADZCSTAT_ZCS5_SHIFT))&ADC_ADZCSTAT_ZCS5_MASK) /*!< ADC_ADZCSTAT                            */
#define ADC_ADZCSTAT_ZCS6_MASK                   (0x40U)                                             /*!< ADC_ADZCSTAT: ZCS6 Mask                 */
#define ADC_ADZCSTAT_ZCS6_SHIFT                  (6U)                                                /*!< ADC_ADZCSTAT: ZCS6 Position             */
#define ADC_ADZCSTAT_ZCS6(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ADZCSTAT_ZCS6_SHIFT))&ADC_ADZCSTAT_ZCS6_MASK) /*!< ADC_ADZCSTAT                            */
#define ADC_ADZCSTAT_ZCS7_MASK                   (0x80U)                                             /*!< ADC_ADZCSTAT: ZCS7 Mask                 */
#define ADC_ADZCSTAT_ZCS7_SHIFT                  (7U)                                                /*!< ADC_ADZCSTAT: ZCS7 Position             */
#define ADC_ADZCSTAT_ZCS7(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ADZCSTAT_ZCS7_SHIFT))&ADC_ADZCSTAT_ZCS7_MASK) /*!< ADC_ADZCSTAT                            */
/* ------- ADRSLT Bit Fields                        ------ */
#define ADC_ADRSLT_RSLT_MASK                     (0x7FF8U)                                           /*!< ADC_ADRSLT: RSLT Mask                   */
#define ADC_ADRSLT_RSLT_SHIFT                    (3U)                                                /*!< ADC_ADRSLT: RSLT Position               */
#define ADC_ADRSLT_RSLT(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADRSLT_RSLT_SHIFT))&ADC_ADRSLT_RSLT_MASK) /*!< ADC_ADRSLT                              */
#define ADC_ADRSLT_SEXT_MASK                     (0x8000U)                                           /*!< ADC_ADRSLT: SEXT Mask                   */
#define ADC_ADRSLT_SEXT_SHIFT                    (15U)                                               /*!< ADC_ADRSLT: SEXT Position               */
#define ADC_ADRSLT_SEXT(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADRSLT_SEXT_SHIFT))&ADC_ADRSLT_SEXT_MASK) /*!< ADC_ADRSLT                              */
/* ------- ADLLMT Bit Fields                        ------ */
#define ADC_ADLLMT_LLMT_MASK                     (0x7FF8U)                                           /*!< ADC_ADLLMT: LLMT Mask                   */
#define ADC_ADLLMT_LLMT_SHIFT                    (3U)                                                /*!< ADC_ADLLMT: LLMT Position               */
#define ADC_ADLLMT_LLMT(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADLLMT_LLMT_SHIFT))&ADC_ADLLMT_LLMT_MASK) /*!< ADC_ADLLMT                              */
/* ------- ADHLMT Bit Fields                        ------ */
#define ADC_ADHLMT_HLMT_MASK                     (0x7FF8U)                                           /*!< ADC_ADHLMT: HLMT Mask                   */
#define ADC_ADHLMT_HLMT_SHIFT                    (3U)                                                /*!< ADC_ADHLMT: HLMT Position               */
#define ADC_ADHLMT_HLMT(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_ADHLMT_HLMT_SHIFT))&ADC_ADHLMT_HLMT_MASK) /*!< ADC_ADHLMT                              */
/* ------- ADOFS Bit Fields                         ------ */
#define ADC_ADOFS_OFFSET_MASK                    (0x7FF8U)                                           /*!< ADC_ADOFS: OFFSET Mask                  */
#define ADC_ADOFS_OFFSET_SHIFT                   (3U)                                                /*!< ADC_ADOFS: OFFSET Position              */
#define ADC_ADOFS_OFFSET(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ADOFS_OFFSET_SHIFT))&ADC_ADOFS_OFFSET_MASK) /*!< ADC_ADOFS                               */
/* ------- POWER Bit Fields                         ------ */
#define ADC_POWER_PD0_MASK                       (0x1U)                                              /*!< ADC_POWER: PD0 Mask                     */
#define ADC_POWER_PD0_SHIFT                      (0U)                                                /*!< ADC_POWER: PD0 Position                 */
#define ADC_POWER_PD0(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_POWER_PD0_SHIFT))&ADC_POWER_PD0_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_PD1_MASK                       (0x2U)                                              /*!< ADC_POWER: PD1 Mask                     */
#define ADC_POWER_PD1_SHIFT                      (1U)                                                /*!< ADC_POWER: PD1 Position                 */
#define ADC_POWER_PD1(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_POWER_PD1_SHIFT))&ADC_POWER_PD1_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_PD2_MASK                       (0x4U)                                              /*!< ADC_POWER: PD2 Mask                     */
#define ADC_POWER_PD2_SHIFT                      (2U)                                                /*!< ADC_POWER: PD2 Position                 */
#define ADC_POWER_PD2(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_POWER_PD2_SHIFT))&ADC_POWER_PD2_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_APD_MASK                       (0x8U)                                              /*!< ADC_POWER: APD Mask                     */
#define ADC_POWER_APD_SHIFT                      (3U)                                                /*!< ADC_POWER: APD Position                 */
#define ADC_POWER_APD(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_POWER_APD_SHIFT))&ADC_POWER_APD_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_PUDELAY_MASK                   (0x3F0U)                                            /*!< ADC_POWER: PUDELAY Mask                 */
#define ADC_POWER_PUDELAY_SHIFT                  (4U)                                                /*!< ADC_POWER: PUDELAY Position             */
#define ADC_POWER_PUDELAY(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_POWER_PUDELAY_SHIFT))&ADC_POWER_PUDELAY_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_PSTS0_MASK                     (0x400U)                                            /*!< ADC_POWER: PSTS0 Mask                   */
#define ADC_POWER_PSTS0_SHIFT                    (10U)                                               /*!< ADC_POWER: PSTS0 Position               */
#define ADC_POWER_PSTS0(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_POWER_PSTS0_SHIFT))&ADC_POWER_PSTS0_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_PSTS1_MASK                     (0x800U)                                            /*!< ADC_POWER: PSTS1 Mask                   */
#define ADC_POWER_PSTS1_SHIFT                    (11U)                                               /*!< ADC_POWER: PSTS1 Position               */
#define ADC_POWER_PSTS1(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_POWER_PSTS1_SHIFT))&ADC_POWER_PSTS1_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_PSTS2_MASK                     (0x1000U)                                           /*!< ADC_POWER: PSTS2 Mask                   */
#define ADC_POWER_PSTS2_SHIFT                    (12U)                                               /*!< ADC_POWER: PSTS2 Position               */
#define ADC_POWER_PSTS2(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_POWER_PSTS2_SHIFT))&ADC_POWER_PSTS2_MASK) /*!< ADC_POWER                               */
#define ADC_POWER_ASB_MASK                       (0x8000U)                                           /*!< ADC_POWER: ASB Mask                     */
#define ADC_POWER_ASB_SHIFT                      (15U)                                               /*!< ADC_POWER: ASB Position                 */
#define ADC_POWER_ASB(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_POWER_ASB_SHIFT))&ADC_POWER_ASB_MASK) /*!< ADC_POWER                               */
/* ------- CAL Bit Fields                           ------ */
#define ADC_CAL_SEL_VREFL_MASK                   (0x4000U)                                           /*!< ADC_CAL: SEL_VREFL Mask                 */
#define ADC_CAL_SEL_VREFL_SHIFT                  (14U)                                               /*!< ADC_CAL: SEL_VREFL Position             */
#define ADC_CAL_SEL_VREFL(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_CAL_SEL_VREFL_SHIFT))&ADC_CAL_SEL_VREFL_MASK) /*!< ADC_CAL                                 */
#define ADC_CAL_SEL_VREFH_MASK                   (0x8000U)                                           /*!< ADC_CAL: SEL_VREFH Mask                 */
#define ADC_CAL_SEL_VREFH_SHIFT                  (15U)                                               /*!< ADC_CAL: SEL_VREFH Position             */
#define ADC_CAL_SEL_VREFH(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_CAL_SEL_VREFH_SHIFT))&ADC_CAL_SEL_VREFH_MASK) /*!< ADC_CAL                                 */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC - Peripheral instance base addresses */
#define ADC_BasePtr                    0x40190000UL //!< Peripheral base address
#define ADC                            ((ADC_Type *) ADC_BasePtr) //!< Freescale base pointer
#define ADC_BASE_PTR                   (ADC) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CCM_Peripheral_access_layer_GROUP CCM Peripheral Access Layer
* @brief C Struct for CCM
* @{
*/

/* ================================================================================ */
/* ================           CCM (file:MCF52233_CCM)              ================ */
/* ================================================================================ */

/**
 * @brief Chip Configuration Module
 */
/**
* @addtogroup CCM_structs_GROUP CCM struct
* @brief Struct for CCM
* @{
*/
typedef struct {                                /*       CCM Structure                                                */
   __I  uint16_t  CCR;                          /**< 0000: Chip Configuration Register                                  */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   LPCR;                         /**< 0003: Low-Power Control Register                                   */
   __I  uint16_t  RCON;                         /**< 0004: Reset Configuration Register                                 */
   __I  uint16_t  CIR;                          /**< 0006: Chip Identification Register                                 */
} CCM_Type;

/**
 * @} */ /* End group CCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CCM_Register_Masks_GROUP CCM Register Masks
* @brief Register Masks for CCM
* @{
*/
/* ------- CCR Bit Fields                           ------ */
#define CCM_CCR_BMT_MASK                         (0x7U)                                              /*!< CCM_CCR: BMT Mask                       */
#define CCM_CCR_BMT_SHIFT                        (0U)                                                /*!< CCM_CCR: BMT Position                   */
#define CCM_CCR_BMT(x)                           (((uint16_t)(((uint16_t)(x))<<CCM_CCR_BMT_SHIFT))&CCM_CCR_BMT_MASK) /*!< CCM_CCR                                 */
#define CCM_CCR_BME_MASK                         (0x8U)                                              /*!< CCM_CCR: BME Mask                       */
#define CCM_CCR_BME_SHIFT                        (3U)                                                /*!< CCM_CCR: BME Position                   */
#define CCM_CCR_BME(x)                           (((uint16_t)(((uint16_t)(x))<<CCM_CCR_BME_SHIFT))&CCM_CCR_BME_MASK) /*!< CCM_CCR                                 */
#define CCM_CCR_PSTEN_MASK                       (0x20U)                                             /*!< CCM_CCR: PSTEN Mask                     */
#define CCM_CCR_PSTEN_SHIFT                      (5U)                                                /*!< CCM_CCR: PSTEN Position                 */
#define CCM_CCR_PSTEN(x)                         (((uint16_t)(((uint16_t)(x))<<CCM_CCR_PSTEN_SHIFT))&CCM_CCR_PSTEN_MASK) /*!< CCM_CCR                                 */
#define CCM_CCR_SZEN_MASK                        (0x40U)                                             /*!< CCM_CCR: SZEN Mask                      */
#define CCM_CCR_SZEN_SHIFT                       (6U)                                                /*!< CCM_CCR: SZEN Position                  */
#define CCM_CCR_SZEN(x)                          (((uint16_t)(((uint16_t)(x))<<CCM_CCR_SZEN_SHIFT))&CCM_CCR_SZEN_MASK) /*!< CCM_CCR                                 */
/* ------- LPCR Bit Fields                          ------ */
#define CCM_LPCR_LVDSE_MASK                      (0x2U)                                              /*!< CCM_LPCR: LVDSE Mask                    */
#define CCM_LPCR_LVDSE_SHIFT                     (1U)                                                /*!< CCM_LPCR: LVDSE Position                */
#define CCM_LPCR_LVDSE(x)                        (((uint8_t)(((uint8_t)(x))<<CCM_LPCR_LVDSE_SHIFT))&CCM_LPCR_LVDSE_MASK) /*!< CCM_LPCR                                */
#define CCM_LPCR_STPMD_MASK                      (0x18U)                                             /*!< CCM_LPCR: STPMD Mask                    */
#define CCM_LPCR_STPMD_SHIFT                     (3U)                                                /*!< CCM_LPCR: STPMD Position                */
#define CCM_LPCR_STPMD(x)                        (((uint8_t)(((uint8_t)(x))<<CCM_LPCR_STPMD_SHIFT))&CCM_LPCR_STPMD_MASK) /*!< CCM_LPCR                                */
#define CCM_LPCR_LPMD_MASK                       (0x40U)                                             /*!< CCM_LPCR: LPMD Mask                     */
#define CCM_LPCR_LPMD_SHIFT                      (6U)                                                /*!< CCM_LPCR: LPMD Position                 */
#define CCM_LPCR_LPMD(x)                         (((uint8_t)(((uint8_t)(x))<<CCM_LPCR_LPMD_SHIFT))&CCM_LPCR_LPMD_MASK) /*!< CCM_LPCR                                */
/* ------- RCON Bit Fields                          ------ */
#define CCM_RCON_MODE_MASK                       (0x1U)                                              /*!< CCM_RCON: MODE Mask                     */
#define CCM_RCON_MODE_SHIFT                      (0U)                                                /*!< CCM_RCON: MODE Position                 */
#define CCM_RCON_MODE(x)                         (((uint16_t)(((uint16_t)(x))<<CCM_RCON_MODE_SHIFT))&CCM_RCON_MODE_MASK) /*!< CCM_RCON                                */
#define CCM_RCON_RLOAD_MASK                      (0x20U)                                             /*!< CCM_RCON: RLOAD Mask                    */
#define CCM_RCON_RLOAD_SHIFT                     (5U)                                                /*!< CCM_RCON: RLOAD Position                */
#define CCM_RCON_RLOAD(x)                        (((uint16_t)(((uint16_t)(x))<<CCM_RCON_RLOAD_SHIFT))&CCM_RCON_RLOAD_MASK) /*!< CCM_RCON                                */
/* ------- CIR Bit Fields                           ------ */
#define CCM_CIR_PRN_MASK                         (0x3FU)                                             /*!< CCM_CIR: PRN Mask                       */
#define CCM_CIR_PRN_SHIFT                        (0U)                                                /*!< CCM_CIR: PRN Position                   */
#define CCM_CIR_PRN(x)                           (((uint16_t)(((uint16_t)(x))<<CCM_CIR_PRN_SHIFT))&CCM_CIR_PRN_MASK) /*!< CCM_CIR                                 */
#define CCM_CIR_PIN_MASK                         (0xFFC0U)                                           /*!< CCM_CIR: PIN Mask                       */
#define CCM_CIR_PIN_SHIFT                        (6U)                                                /*!< CCM_CIR: PIN Position                   */
#define CCM_CIR_PIN(x)                           (((uint16_t)(((uint16_t)(x))<<CCM_CIR_PIN_SHIFT))&CCM_CIR_PIN_MASK) /*!< CCM_CIR                                 */
/**
 * @} */ /* End group CCM_Register_Masks_GROUP 
 */

/* CCM - Peripheral instance base addresses */
#define CCM_BasePtr                    0x40110004UL //!< Peripheral base address
#define CCM                            ((CCM_Type *) CCM_BasePtr) //!< Freescale base pointer
#define CCM_BASE_PTR                   (CCM) //!< Freescale style base pointer
/**
 * @} */ /* End group CCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CFM_Peripheral_access_layer_GROUP CFM Peripheral Access Layer
* @brief C Struct for CFM
* @{
*/

/* ================================================================================ */
/* ================           CFM (file:MCF522xx_CFM)              ================ */
/* ================================================================================ */

/**
 * @brief ColdFire Flash Module
 */
/**
* @addtogroup CFM_structs_GROUP CFM struct
* @brief Struct for CFM
* @{
*/
typedef struct {                                /*       CFM Structure                                                */
   __IO uint16_t  CFMMCR;                       /**< 0000: Module Configuration Register                                */
   __IO uint8_t   CFMCLKD;                      /**< 0002: Clock Divider Register                                       */
        uint8_t   RESERVED_0[5];               
   __I  uint32_t  CFMSEC;                       /**< 0008: Security Register                                            */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  CFMPROT;                      /**< 0010: Protection Register                                          */
   __IO uint32_t  CFMSACC;                      /**< 0014: Supervisor Access Register                                   */
   __IO uint32_t  CFMDACC;                      /**< 0018: Data Access Register                                         */
        uint8_t   RESERVED_2[4];               
   __IO uint8_t   CFMUSTAT;                     /**< 0020: User Status Register                                         */
        uint8_t   RESERVED_3[3];               
   __IO uint8_t   CFMCMD;                       /**< 0024: Command Register                                             */
        uint8_t   RESERVED_4[37];              
   __I  uint16_t  CFMCLKSEL;                    /**< 004A: Clock Select Register                                        */
} CFM_Type;

/**
 * @} */ /* End group CFM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CFM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CFM_Register_Masks_GROUP CFM Register Masks
* @brief Register Masks for CFM
* @{
*/
/* ------- CFMMCR Bit Fields                        ------ */
#define CFM_CFMMCR_KEYACC_MASK                   (0x20U)                                             /*!< CFM_CFMMCR: KEYACC Mask                 */
#define CFM_CFMMCR_KEYACC_SHIFT                  (5U)                                                /*!< CFM_CFMMCR: KEYACC Position             */
#define CFM_CFMMCR_KEYACC(x)                     (((uint16_t)(((uint16_t)(x))<<CFM_CFMMCR_KEYACC_SHIFT))&CFM_CFMMCR_KEYACC_MASK) /*!< CFM_CFMMCR                              */
#define CFM_CFMMCR_CCIE_MASK                     (0x40U)                                             /*!< CFM_CFMMCR: CCIE Mask                   */
#define CFM_CFMMCR_CCIE_SHIFT                    (6U)                                                /*!< CFM_CFMMCR: CCIE Position               */
#define CFM_CFMMCR_CCIE(x)                       (((uint16_t)(((uint16_t)(x))<<CFM_CFMMCR_CCIE_SHIFT))&CFM_CFMMCR_CCIE_MASK) /*!< CFM_CFMMCR                              */
#define CFM_CFMMCR_CBEIE_MASK                    (0x80U)                                             /*!< CFM_CFMMCR: CBEIE Mask                  */
#define CFM_CFMMCR_CBEIE_SHIFT                   (7U)                                                /*!< CFM_CFMMCR: CBEIE Position              */
#define CFM_CFMMCR_CBEIE(x)                      (((uint16_t)(((uint16_t)(x))<<CFM_CFMMCR_CBEIE_SHIFT))&CFM_CFMMCR_CBEIE_MASK) /*!< CFM_CFMMCR                              */
#define CFM_CFMMCR_AEIE_MASK                     (0x100U)                                            /*!< CFM_CFMMCR: AEIE Mask                   */
#define CFM_CFMMCR_AEIE_SHIFT                    (8U)                                                /*!< CFM_CFMMCR: AEIE Position               */
#define CFM_CFMMCR_AEIE(x)                       (((uint16_t)(((uint16_t)(x))<<CFM_CFMMCR_AEIE_SHIFT))&CFM_CFMMCR_AEIE_MASK) /*!< CFM_CFMMCR                              */
#define CFM_CFMMCR_PVIE_MASK                     (0x200U)                                            /*!< CFM_CFMMCR: PVIE Mask                   */
#define CFM_CFMMCR_PVIE_SHIFT                    (9U)                                                /*!< CFM_CFMMCR: PVIE Position               */
#define CFM_CFMMCR_PVIE(x)                       (((uint16_t)(((uint16_t)(x))<<CFM_CFMMCR_PVIE_SHIFT))&CFM_CFMMCR_PVIE_MASK) /*!< CFM_CFMMCR                              */
#define CFM_CFMMCR_LOCK_MASK                     (0x400U)                                            /*!< CFM_CFMMCR: LOCK Mask                   */
#define CFM_CFMMCR_LOCK_SHIFT                    (10U)                                               /*!< CFM_CFMMCR: LOCK Position               */
#define CFM_CFMMCR_LOCK(x)                       (((uint16_t)(((uint16_t)(x))<<CFM_CFMMCR_LOCK_SHIFT))&CFM_CFMMCR_LOCK_MASK) /*!< CFM_CFMMCR                              */
/* ------- CFMCLKD Bit Fields                       ------ */
#define CFM_CFMCLKD_DIV_MASK                     (0x3FU)                                             /*!< CFM_CFMCLKD: DIV Mask                   */
#define CFM_CFMCLKD_DIV_SHIFT                    (0U)                                                /*!< CFM_CFMCLKD: DIV Position               */
#define CFM_CFMCLKD_DIV(x)                       (((uint8_t)(((uint8_t)(x))<<CFM_CFMCLKD_DIV_SHIFT))&CFM_CFMCLKD_DIV_MASK) /*!< CFM_CFMCLKD                             */
#define CFM_CFMCLKD_PRDIV8_MASK                  (0x40U)                                             /*!< CFM_CFMCLKD: PRDIV8 Mask                */
#define CFM_CFMCLKD_PRDIV8_SHIFT                 (6U)                                                /*!< CFM_CFMCLKD: PRDIV8 Position            */
#define CFM_CFMCLKD_PRDIV8(x)                    (((uint8_t)(((uint8_t)(x))<<CFM_CFMCLKD_PRDIV8_SHIFT))&CFM_CFMCLKD_PRDIV8_MASK) /*!< CFM_CFMCLKD                             */
#define CFM_CFMCLKD_DIVLD_MASK                   (0x80U)                                             /*!< CFM_CFMCLKD: DIVLD Mask                 */
#define CFM_CFMCLKD_DIVLD_SHIFT                  (7U)                                                /*!< CFM_CFMCLKD: DIVLD Position             */
#define CFM_CFMCLKD_DIVLD(x)                     (((uint8_t)(((uint8_t)(x))<<CFM_CFMCLKD_DIVLD_SHIFT))&CFM_CFMCLKD_DIVLD_MASK) /*!< CFM_CFMCLKD                             */
/* ------- CFMSEC Bit Fields                        ------ */
#define CFM_CFMSEC_SEC_MASK                      (0xFFFFU)                                           /*!< CFM_CFMSEC: SEC Mask                    */
#define CFM_CFMSEC_SEC_SHIFT                     (0U)                                                /*!< CFM_CFMSEC: SEC Position                */
#define CFM_CFMSEC_SEC(x)                        (((uint32_t)(((uint32_t)(x))<<CFM_CFMSEC_SEC_SHIFT))&CFM_CFMSEC_SEC_MASK) /*!< CFM_CFMSEC                              */
#define CFM_CFMSEC_SECSTAT_MASK                  (0x40000000U)                                       /*!< CFM_CFMSEC: SECSTAT Mask                */
#define CFM_CFMSEC_SECSTAT_SHIFT                 (30U)                                               /*!< CFM_CFMSEC: SECSTAT Position            */
#define CFM_CFMSEC_SECSTAT(x)                    (((uint32_t)(((uint32_t)(x))<<CFM_CFMSEC_SECSTAT_SHIFT))&CFM_CFMSEC_SECSTAT_MASK) /*!< CFM_CFMSEC                              */
#define CFM_CFMSEC_KEYEN_MASK                    (0x80000000U)                                       /*!< CFM_CFMSEC: KEYEN Mask                  */
#define CFM_CFMSEC_KEYEN_SHIFT                   (31U)                                               /*!< CFM_CFMSEC: KEYEN Position              */
#define CFM_CFMSEC_KEYEN(x)                      (((uint32_t)(((uint32_t)(x))<<CFM_CFMSEC_KEYEN_SHIFT))&CFM_CFMSEC_KEYEN_MASK) /*!< CFM_CFMSEC                              */
/* ------- CFMPROT Bit Fields                       ------ */
#define CFM_CFMPROT_PROTECT_MASK                 (0xFFFFFFFFU)                                       /*!< CFM_CFMPROT: PROTECT Mask               */
#define CFM_CFMPROT_PROTECT_SHIFT                (0U)                                                /*!< CFM_CFMPROT: PROTECT Position           */
#define CFM_CFMPROT_PROTECT(x)                   (((uint32_t)(((uint32_t)(x))<<CFM_CFMPROT_PROTECT_SHIFT))&CFM_CFMPROT_PROTECT_MASK) /*!< CFM_CFMPROT                             */
/* ------- CFMSACC Bit Fields                       ------ */
#define CFM_CFMSACC_SUPV_MASK                    (0xFFFFFFFFU)                                       /*!< CFM_CFMSACC: SUPV Mask                  */
#define CFM_CFMSACC_SUPV_SHIFT                   (0U)                                                /*!< CFM_CFMSACC: SUPV Position              */
#define CFM_CFMSACC_SUPV(x)                      (((uint32_t)(((uint32_t)(x))<<CFM_CFMSACC_SUPV_SHIFT))&CFM_CFMSACC_SUPV_MASK) /*!< CFM_CFMSACC                             */
/* ------- CFMDACC Bit Fields                       ------ */
#define CFM_CFMDACC_DACC_MASK                    (0xFFFFFFFFU)                                       /*!< CFM_CFMDACC: DACC Mask                  */
#define CFM_CFMDACC_DACC_SHIFT                   (0U)                                                /*!< CFM_CFMDACC: DACC Position              */
#define CFM_CFMDACC_DACC(x)                      (((uint32_t)(((uint32_t)(x))<<CFM_CFMDACC_DACC_SHIFT))&CFM_CFMDACC_DACC_MASK) /*!< CFM_CFMDACC                             */
/* ------- CFMUSTAT Bit Fields                      ------ */
#define CFM_CFMUSTAT_BLANK_MASK                  (0x4U)                                              /*!< CFM_CFMUSTAT: BLANK Mask                */
#define CFM_CFMUSTAT_BLANK_SHIFT                 (2U)                                                /*!< CFM_CFMUSTAT: BLANK Position            */
#define CFM_CFMUSTAT_BLANK(x)                    (((uint8_t)(((uint8_t)(x))<<CFM_CFMUSTAT_BLANK_SHIFT))&CFM_CFMUSTAT_BLANK_MASK) /*!< CFM_CFMUSTAT                            */
#define CFM_CFMUSTAT_ACCERR_MASK                 (0x10U)                                             /*!< CFM_CFMUSTAT: ACCERR Mask               */
#define CFM_CFMUSTAT_ACCERR_SHIFT                (4U)                                                /*!< CFM_CFMUSTAT: ACCERR Position           */
#define CFM_CFMUSTAT_ACCERR(x)                   (((uint8_t)(((uint8_t)(x))<<CFM_CFMUSTAT_ACCERR_SHIFT))&CFM_CFMUSTAT_ACCERR_MASK) /*!< CFM_CFMUSTAT                            */
#define CFM_CFMUSTAT_PVIOL_MASK                  (0x20U)                                             /*!< CFM_CFMUSTAT: PVIOL Mask                */
#define CFM_CFMUSTAT_PVIOL_SHIFT                 (5U)                                                /*!< CFM_CFMUSTAT: PVIOL Position            */
#define CFM_CFMUSTAT_PVIOL(x)                    (((uint8_t)(((uint8_t)(x))<<CFM_CFMUSTAT_PVIOL_SHIFT))&CFM_CFMUSTAT_PVIOL_MASK) /*!< CFM_CFMUSTAT                            */
#define CFM_CFMUSTAT_CCIF_MASK                   (0x40U)                                             /*!< CFM_CFMUSTAT: CCIF Mask                 */
#define CFM_CFMUSTAT_CCIF_SHIFT                  (6U)                                                /*!< CFM_CFMUSTAT: CCIF Position             */
#define CFM_CFMUSTAT_CCIF(x)                     (((uint8_t)(((uint8_t)(x))<<CFM_CFMUSTAT_CCIF_SHIFT))&CFM_CFMUSTAT_CCIF_MASK) /*!< CFM_CFMUSTAT                            */
#define CFM_CFMUSTAT_CBEIF_MASK                  (0x80U)                                             /*!< CFM_CFMUSTAT: CBEIF Mask                */
#define CFM_CFMUSTAT_CBEIF_SHIFT                 (7U)                                                /*!< CFM_CFMUSTAT: CBEIF Position            */
#define CFM_CFMUSTAT_CBEIF(x)                    (((uint8_t)(((uint8_t)(x))<<CFM_CFMUSTAT_CBEIF_SHIFT))&CFM_CFMUSTAT_CBEIF_MASK) /*!< CFM_CFMUSTAT                            */
/* ------- CFMCMD Bit Fields                        ------ */
#define CFM_CFMCMD_CMD_MASK                      (0x7FU)                                             /*!< CFM_CFMCMD: CMD Mask                    */
#define CFM_CFMCMD_CMD_SHIFT                     (0U)                                                /*!< CFM_CFMCMD: CMD Position                */
#define CFM_CFMCMD_CMD(x)                        (((uint8_t)(((uint8_t)(x))<<CFM_CFMCMD_CMD_SHIFT))&CFM_CFMCMD_CMD_MASK) /*!< CFM_CFMCMD                              */
/* ------- CFMCLKSEL Bit Fields                     ------ */
#define CFM_CFMCLKSEL_CLKSEL_MASK                (0x3U)                                              /*!< CFM_CFMCLKSEL: CLKSEL Mask              */
#define CFM_CFMCLKSEL_CLKSEL_SHIFT               (0U)                                                /*!< CFM_CFMCLKSEL: CLKSEL Position          */
#define CFM_CFMCLKSEL_CLKSEL(x)                  (((uint16_t)(((uint16_t)(x))<<CFM_CFMCLKSEL_CLKSEL_SHIFT))&CFM_CFMCLKSEL_CLKSEL_MASK) /*!< CFM_CFMCLKSEL                           */
/**
 * @} */ /* End group CFM_Register_Masks_GROUP 
 */

/* CFM - Peripheral instance base addresses */
#define CFM_BasePtr                    0x401D0000UL //!< Peripheral base address
#define CFM                            ((CFM_Type *) CFM_BasePtr) //!< Freescale base pointer
#define CFM_BASE_PTR                   (CFM) //!< Freescale style base pointer
/**
 * @} */ /* End group CFM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CLOCK_Peripheral_access_layer_GROUP CLOCK Peripheral Access Layer
* @brief C Struct for CLOCK
* @{
*/

/* ================================================================================ */
/* ================           CLOCK (file:MCF52233_CLOCK)          ================ */
/* ================================================================================ */

/**
 * @brief Clock Module
 */
/**
* @addtogroup CLOCK_structs_GROUP CLOCK struct
* @brief Struct for CLOCK
* @{
*/
typedef struct {                                /*       CLOCK Structure                                              */
   __IO uint16_t  SYNCR;                        /**< 0000: Synthesizer Control Register                                 */
   __I  uint8_t   SYNSR;                        /**< 0002: Synthesiser Status Register                                  */
        uint8_t   RESERVED_0[4];               
   __IO uint8_t   LPCR;                         /**< 0007: Low Power Control Register                                   */
   __IO uint8_t   CCHR;                         /**< 0008: Clock Control High Register                                  */
        uint8_t   RESERVED_1[3];               
   __IO uint32_t  RTCDR;                        /**< 000C: Real Time Clock Divide Register                              */
} CLOCK_Type;

/**
 * @} */ /* End group CLOCK_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CLOCK' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CLOCK_Register_Masks_GROUP CLOCK Register Masks
* @brief Register Masks for CLOCK
* @{
*/
/* ------- SYNCR Bit Fields                         ------ */
#define CLOCK_SYNCR_PLLEN_MASK                   (0x1U)                                              /*!< CLOCK_SYNCR: PLLEN Mask                 */
#define CLOCK_SYNCR_PLLEN_SHIFT                  (0U)                                                /*!< CLOCK_SYNCR: PLLEN Position             */
#define CLOCK_SYNCR_PLLEN(x)                     (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_PLLEN_SHIFT))&CLOCK_SYNCR_PLLEN_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_PLLMODE_MASK                 (0x2U)                                              /*!< CLOCK_SYNCR: PLLMODE Mask               */
#define CLOCK_SYNCR_PLLMODE_SHIFT                (1U)                                                /*!< CLOCK_SYNCR: PLLMODE Position           */
#define CLOCK_SYNCR_PLLMODE(x)                   (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_PLLMODE_SHIFT))&CLOCK_SYNCR_PLLMODE_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_CLKSRC_MASK                  (0x4U)                                              /*!< CLOCK_SYNCR: CLKSRC Mask                */
#define CLOCK_SYNCR_CLKSRC_SHIFT                 (2U)                                                /*!< CLOCK_SYNCR: CLKSRC Position            */
#define CLOCK_SYNCR_CLKSRC(x)                    (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_CLKSRC_SHIFT))&CLOCK_SYNCR_CLKSRC_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_FWKUP_MASK                   (0x20U)                                             /*!< CLOCK_SYNCR: FWKUP Mask                 */
#define CLOCK_SYNCR_FWKUP_SHIFT                  (5U)                                                /*!< CLOCK_SYNCR: FWKUP Position             */
#define CLOCK_SYNCR_FWKUP(x)                     (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_FWKUP_SHIFT))&CLOCK_SYNCR_FWKUP_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_DISCLK_MASK                  (0x40U)                                             /*!< CLOCK_SYNCR: DISCLK Mask                */
#define CLOCK_SYNCR_DISCLK_SHIFT                 (6U)                                                /*!< CLOCK_SYNCR: DISCLK Position            */
#define CLOCK_SYNCR_DISCLK(x)                    (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_DISCLK_SHIFT))&CLOCK_SYNCR_DISCLK_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_LOCEN_MASK                   (0x80U)                                             /*!< CLOCK_SYNCR: LOCEN Mask                 */
#define CLOCK_SYNCR_LOCEN_SHIFT                  (7U)                                                /*!< CLOCK_SYNCR: LOCEN Position             */
#define CLOCK_SYNCR_LOCEN(x)                     (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_LOCEN_SHIFT))&CLOCK_SYNCR_LOCEN_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_RFD_MASK                     (0x700U)                                            /*!< CLOCK_SYNCR: RFD Mask                   */
#define CLOCK_SYNCR_RFD_SHIFT                    (8U)                                                /*!< CLOCK_SYNCR: RFD Position               */
#define CLOCK_SYNCR_RFD(x)                       (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_RFD_SHIFT))&CLOCK_SYNCR_RFD_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_LOCRE_MASK                   (0x800U)                                            /*!< CLOCK_SYNCR: LOCRE Mask                 */
#define CLOCK_SYNCR_LOCRE_SHIFT                  (11U)                                               /*!< CLOCK_SYNCR: LOCRE Position             */
#define CLOCK_SYNCR_LOCRE(x)                     (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_LOCRE_SHIFT))&CLOCK_SYNCR_LOCRE_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_MFD_MASK                     (0x7000U)                                           /*!< CLOCK_SYNCR: MFD Mask                   */
#define CLOCK_SYNCR_MFD_SHIFT                    (12U)                                               /*!< CLOCK_SYNCR: MFD Position               */
#define CLOCK_SYNCR_MFD(x)                       (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_MFD_SHIFT))&CLOCK_SYNCR_MFD_MASK) /*!< CLOCK_SYNCR                             */
#define CLOCK_SYNCR_LOLRE_MASK                   (0x8000U)                                           /*!< CLOCK_SYNCR: LOLRE Mask                 */
#define CLOCK_SYNCR_LOLRE_SHIFT                  (15U)                                               /*!< CLOCK_SYNCR: LOLRE Position             */
#define CLOCK_SYNCR_LOLRE(x)                     (((uint16_t)(((uint16_t)(x))<<CLOCK_SYNCR_LOLRE_SHIFT))&CLOCK_SYNCR_LOLRE_MASK) /*!< CLOCK_SYNCR                             */
/* ------- SYNSR Bit Fields                         ------ */
#define CLOCK_SYNSR_LOCS_MASK                    (0x4U)                                              /*!< CLOCK_SYNSR: LOCS Mask                  */
#define CLOCK_SYNSR_LOCS_SHIFT                   (2U)                                                /*!< CLOCK_SYNSR: LOCS Position              */
#define CLOCK_SYNSR_LOCS(x)                      (((uint8_t)(((uint8_t)(x))<<CLOCK_SYNSR_LOCS_SHIFT))&CLOCK_SYNSR_LOCS_MASK) /*!< CLOCK_SYNSR                             */
#define CLOCK_SYNSR_LOCK_MASK                    (0x8U)                                              /*!< CLOCK_SYNSR: LOCK Mask                  */
#define CLOCK_SYNSR_LOCK_SHIFT                   (3U)                                                /*!< CLOCK_SYNSR: LOCK Position              */
#define CLOCK_SYNSR_LOCK(x)                      (((uint8_t)(((uint8_t)(x))<<CLOCK_SYNSR_LOCK_SHIFT))&CLOCK_SYNSR_LOCK_MASK) /*!< CLOCK_SYNSR                             */
#define CLOCK_SYNSR_LOCKS_MASK                   (0x10U)                                             /*!< CLOCK_SYNSR: LOCKS Mask                 */
#define CLOCK_SYNSR_LOCKS_SHIFT                  (4U)                                                /*!< CLOCK_SYNSR: LOCKS Position             */
#define CLOCK_SYNSR_LOCKS(x)                     (((uint8_t)(((uint8_t)(x))<<CLOCK_SYNSR_LOCKS_SHIFT))&CLOCK_SYNSR_LOCKS_MASK) /*!< CLOCK_SYNSR                             */
#define CLOCK_SYNSR_EXTOSC_MASK                  (0x80U)                                             /*!< CLOCK_SYNSR: EXTOSC Mask                */
#define CLOCK_SYNSR_EXTOSC_SHIFT                 (7U)                                                /*!< CLOCK_SYNSR: EXTOSC Position            */
#define CLOCK_SYNSR_EXTOSC(x)                    (((uint8_t)(((uint8_t)(x))<<CLOCK_SYNSR_EXTOSC_SHIFT))&CLOCK_SYNSR_EXTOSC_MASK) /*!< CLOCK_SYNSR                             */
/* ------- LPCR Bit Fields                          ------ */
#define CLOCK_LPCR_LPD_MASK                      (0xFU)                                              /*!< CLOCK_LPCR: LPD Mask                    */
#define CLOCK_LPCR_LPD_SHIFT                     (0U)                                                /*!< CLOCK_LPCR: LPD Position                */
#define CLOCK_LPCR_LPD(x)                        (((uint8_t)(((uint8_t)(x))<<CLOCK_LPCR_LPD_SHIFT))&CLOCK_LPCR_LPD_MASK) /*!< CLOCK_LPCR                              */
/* ------- CCHR Bit Fields                          ------ */
#define CLOCK_CCHR_CCHR_MASK                     (0x7U)                                              /*!< CLOCK_CCHR: CCHR Mask                   */
#define CLOCK_CCHR_CCHR_SHIFT                    (0U)                                                /*!< CLOCK_CCHR: CCHR Position               */
#define CLOCK_CCHR_CCHR(x)                       (((uint8_t)(((uint8_t)(x))<<CLOCK_CCHR_CCHR_SHIFT))&CLOCK_CCHR_CCHR_MASK) /*!< CLOCK_CCHR                              */
/* ------- RTCDR Bit Fields                         ------ */
#define CLOCK_RTCDR_RTCDF_MASK                   (0xFFFFFFFFU)                                       /*!< CLOCK_RTCDR: RTCDF Mask                 */
#define CLOCK_RTCDR_RTCDF_SHIFT                  (0U)                                                /*!< CLOCK_RTCDR: RTCDF Position             */
#define CLOCK_RTCDR_RTCDF(x)                     (((uint32_t)(((uint32_t)(x))<<CLOCK_RTCDR_RTCDF_SHIFT))&CLOCK_RTCDR_RTCDF_MASK) /*!< CLOCK_RTCDR                             */
/**
 * @} */ /* End group CLOCK_Register_Masks_GROUP 
 */

/* CLOCK - Peripheral instance base addresses */
#define CLOCK_BasePtr                  0x40120000UL //!< Peripheral base address
#define CLOCK                          ((CLOCK_Type *) CLOCK_BasePtr) //!< Freescale base pointer
#define CLOCK_BASE_PTR                 (CLOCK) //!< Freescale style base pointer
/**
 * @} */ /* End group CLOCK_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA_Peripheral_access_layer_GROUP DMA Peripheral Access Layer
* @brief C Struct for DMA
* @{
*/

/* ================================================================================ */
/* ================           DMA (file:MCF522xx_DMA)              ================ */
/* ================================================================================ */

/**
 * @brief DMA Controller Module
 */
/**
* @addtogroup DMA_structs_GROUP DMA struct
* @brief Struct for DMA
* @{
*/
typedef struct {                                /*       DMA Structure                                                */
   struct {
      __IO uint32_t  SAR;                       /**< 0000: Source Address Register                                      */
      __IO uint32_t  DAR;                       /**< 0004: Destination Address Register                                 */
      union {                                   /**< 0000: (size=0004)                                                  */
         __IO uint32_t  BCR;                    /**< 0008: Byte Count and Status Register                               */
         __IO uint8_t   DSR;                    /**< 0008: Status Register                                              */
      };
      __IO uint32_t  DCR;                       /**< 000C: Control Register                                             */
   } CH[4];                                     /**< 0000: (cluster: size=0x0040, 64)                                   */
} DMA_Type;

/**
 * @} */ /* End group DMA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA_Register_Masks_GROUP DMA Register Masks
* @brief Register Masks for DMA
* @{
*/
/* ------- SAR Bit Fields                           ------ */
#define DMA_SAR_SAR_MASK                         (0xFFFFFFFFU)                                       /*!< DMA_SAR: SAR Mask                       */
#define DMA_SAR_SAR_SHIFT                        (0U)                                                /*!< DMA_SAR: SAR Position                   */
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_SAR_SAR_SHIFT))&DMA_SAR_SAR_MASK) /*!< DMA_SAR                                 */
/* ------- DAR Bit Fields                           ------ */
#define DMA_DAR_DAR_MASK                         (0xFFFFFFFFU)                                       /*!< DMA_DAR: DAR Mask                       */
#define DMA_DAR_DAR_SHIFT                        (0U)                                                /*!< DMA_DAR: DAR Position                   */
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DAR_DAR_SHIFT))&DMA_DAR_DAR_MASK) /*!< DMA_DAR                                 */
/* ------- BCR Bit Fields                           ------ */
#define DMA_BCR_BCR_MASK                         (0xFFFFFFU)                                         /*!< DMA_BCR: BCR Mask                       */
#define DMA_BCR_BCR_SHIFT                        (0U)                                                /*!< DMA_BCR: BCR Position                   */
#define DMA_BCR_BCR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_BCR_BCR_SHIFT))&DMA_BCR_BCR_MASK) /*!< DMA_BCR                                 */
#define DMA_BCR_DSR_MASK                         (0xFF000000U)                                       /*!< DMA_BCR: DSR Mask                       */
#define DMA_BCR_DSR_SHIFT                        (24U)                                               /*!< DMA_BCR: DSR Position                   */
#define DMA_BCR_DSR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_BCR_DSR_SHIFT))&DMA_BCR_DSR_MASK) /*!< DMA_BCR                                 */
/* ------- DSR Bit Fields                           ------ */
#define DMA_DSR_DONE_MASK                        (0x1U)                                              /*!< DMA_DSR: DONE Mask                      */
#define DMA_DSR_DONE_SHIFT                       (0U)                                                /*!< DMA_DSR: DONE Position                  */
#define DMA_DSR_DONE(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_DSR_DONE_SHIFT))&DMA_DSR_DONE_MASK) /*!< DMA_DSR                                 */
#define DMA_DSR_BSY_MASK                         (0x2U)                                              /*!< DMA_DSR: BSY Mask                       */
#define DMA_DSR_BSY_SHIFT                        (1U)                                                /*!< DMA_DSR: BSY Position                   */
#define DMA_DSR_BSY(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BSY_SHIFT))&DMA_DSR_BSY_MASK) /*!< DMA_DSR                                 */
#define DMA_DSR_REQ_MASK                         (0x4U)                                              /*!< DMA_DSR: REQ Mask                       */
#define DMA_DSR_REQ_SHIFT                        (2U)                                                /*!< DMA_DSR: REQ Position                   */
#define DMA_DSR_REQ(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_REQ_SHIFT))&DMA_DSR_REQ_MASK) /*!< DMA_DSR                                 */
#define DMA_DSR_BED_MASK                         (0x10U)                                             /*!< DMA_DSR: BED Mask                       */
#define DMA_DSR_BED_SHIFT                        (4U)                                                /*!< DMA_DSR: BED Position                   */
#define DMA_DSR_BED(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BED_SHIFT))&DMA_DSR_BED_MASK) /*!< DMA_DSR                                 */
#define DMA_DSR_BES_MASK                         (0x20U)                                             /*!< DMA_DSR: BES Mask                       */
#define DMA_DSR_BES_SHIFT                        (5U)                                                /*!< DMA_DSR: BES Position                   */
#define DMA_DSR_BES(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BES_SHIFT))&DMA_DSR_BES_MASK) /*!< DMA_DSR                                 */
#define DMA_DSR_CE_MASK                          (0x40U)                                             /*!< DMA_DSR: CE Mask                        */
#define DMA_DSR_CE_SHIFT                         (6U)                                                /*!< DMA_DSR: CE Position                    */
#define DMA_DSR_CE(x)                            (((uint8_t)(((uint8_t)(x))<<DMA_DSR_CE_SHIFT))&DMA_DSR_CE_MASK) /*!< DMA_DSR                                 */
/* ------- DCR Bit Fields                           ------ */
#define DMA_DCR_LCH2_MASK                        (0x3U)                                              /*!< DMA_DCR: LCH2 Mask                      */
#define DMA_DCR_LCH2_SHIFT                       (0U)                                                /*!< DMA_DCR: LCH2 Position                  */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH2_SHIFT))&DMA_DCR_LCH2_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_LCH1_MASK                        (0xCU)                                              /*!< DMA_DCR: LCH1 Mask                      */
#define DMA_DCR_LCH1_SHIFT                       (2U)                                                /*!< DMA_DCR: LCH1 Position                  */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH1_SHIFT))&DMA_DCR_LCH1_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_LINKCC_MASK                      (0x30U)                                             /*!< DMA_DCR: LINKCC Mask                    */
#define DMA_DCR_LINKCC_SHIFT                     (4U)                                                /*!< DMA_DCR: LINKCC Position                */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LINKCC_SHIFT))&DMA_DCR_LINKCC_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_D_REQ_MASK                       (0x80U)                                             /*!< DMA_DCR: D_REQ Mask                     */
#define DMA_DCR_D_REQ_SHIFT                      (7U)                                                /*!< DMA_DCR: D_REQ Position                 */
#define DMA_DCR_D_REQ(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_D_REQ_SHIFT))&DMA_DCR_D_REQ_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_DMOD_MASK                        (0xF00U)                                            /*!< DMA_DCR: DMOD Mask                      */
#define DMA_DCR_DMOD_SHIFT                       (8U)                                                /*!< DMA_DCR: DMOD Position                  */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DMOD_SHIFT))&DMA_DCR_DMOD_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_SMOD_MASK                        (0xF000U)                                           /*!< DMA_DCR: SMOD Mask                      */
#define DMA_DCR_SMOD_SHIFT                       (12U)                                               /*!< DMA_DCR: SMOD Position                  */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SMOD_SHIFT))&DMA_DCR_SMOD_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_START_MASK                       (0x10000U)                                          /*!< DMA_DCR: START Mask                     */
#define DMA_DCR_START_SHIFT                      (16U)                                               /*!< DMA_DCR: START Position                 */
#define DMA_DCR_START(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_START_SHIFT))&DMA_DCR_START_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_DSIZE_MASK                       (0x60000U)                                          /*!< DMA_DCR: DSIZE Mask                     */
#define DMA_DCR_DSIZE_SHIFT                      (17U)                                               /*!< DMA_DCR: DSIZE Position                 */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DSIZE_SHIFT))&DMA_DCR_DSIZE_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_DINC_MASK                        (0x80000U)                                          /*!< DMA_DCR: DINC Mask                      */
#define DMA_DCR_DINC_SHIFT                       (19U)                                               /*!< DMA_DCR: DINC Position                  */
#define DMA_DCR_DINC(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DINC_SHIFT))&DMA_DCR_DINC_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_SSIZE_MASK                       (0x300000U)                                         /*!< DMA_DCR: SSIZE Mask                     */
#define DMA_DCR_SSIZE_SHIFT                      (20U)                                               /*!< DMA_DCR: SSIZE Position                 */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SSIZE_SHIFT))&DMA_DCR_SSIZE_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_SINC_MASK                        (0x400000U)                                         /*!< DMA_DCR: SINC Mask                      */
#define DMA_DCR_SINC_SHIFT                       (22U)                                               /*!< DMA_DCR: SINC Position                  */
#define DMA_DCR_SINC(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SINC_SHIFT))&DMA_DCR_SINC_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_BWC_MASK                         (0xE000000U)                                        /*!< DMA_DCR: BWC Mask                       */
#define DMA_DCR_BWC_SHIFT                        (25U)                                               /*!< DMA_DCR: BWC Position                   */
#define DMA_DCR_BWC(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DCR_BWC_SHIFT))&DMA_DCR_BWC_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_AA_MASK                          (0x10000000U)                                       /*!< DMA_DCR: AA Mask                        */
#define DMA_DCR_AA_SHIFT                         (28U)                                               /*!< DMA_DCR: AA Position                    */
#define DMA_DCR_AA(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_DCR_AA_SHIFT))&DMA_DCR_AA_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_CS_MASK                          (0x20000000U)                                       /*!< DMA_DCR: CS Mask                        */
#define DMA_DCR_CS_SHIFT                         (29U)                                               /*!< DMA_DCR: CS Position                    */
#define DMA_DCR_CS(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_DCR_CS_SHIFT))&DMA_DCR_CS_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_EEXT_MASK                        (0x40000000U)                                       /*!< DMA_DCR: EEXT Mask                      */
#define DMA_DCR_EEXT_SHIFT                       (30U)                                               /*!< DMA_DCR: EEXT Position                  */
#define DMA_DCR_EEXT(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_EEXT_SHIFT))&DMA_DCR_EEXT_MASK) /*!< DMA_DCR                                 */
#define DMA_DCR_INT_MASK                         (0x80000000U)                                       /*!< DMA_DCR: INT Mask                       */
#define DMA_DCR_INT_SHIFT                        (31U)                                               /*!< DMA_DCR: INT Position                   */
#define DMA_DCR_INT(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DCR_INT_SHIFT))&DMA_DCR_INT_MASK) /*!< DMA_DCR                                 */
/**
 * @} */ /* End group DMA_Register_Masks_GROUP 
 */

/* DMA - Peripheral instance base addresses */
#define DMA_BasePtr                    0x40000100UL //!< Peripheral base address
#define DMA                            ((DMA_Type *) DMA_BasePtr) //!< Freescale base pointer
#define DMA_BASE_PTR                   (DMA) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DTIM_Peripheral_access_layer_GROUP DTIM Peripheral Access Layer
* @brief C Struct for DTIM
* @{
*/

/* ================================================================================ */
/* ================           DTIM (file:MCF522xx_DTIM)            ================ */
/* ================================================================================ */

/**
 * @brief DMA Timers
 */
/**
* @addtogroup DTIM_structs_GROUP DTIM struct
* @brief Struct for DTIM
* @{
*/
typedef struct {                                /*       DTIM Structure                                               */
   struct {
      __IO uint16_t  DTMR;                      /**< 0000: Timer Mode Register                                          */
      __IO uint8_t   DTXMR;                     /**< 0002: Timer Extended Mode                                          */
      __IO uint8_t   DTER;                      /**< 0003: Timer Event                                                  */
      __IO uint32_t  DTRR;                      /**< 0004: Timer Reference Register                                     */
      __I  uint32_t  DTCR;                      /**< 0008: Timer Capture Registers                                      */
      __IO uint32_t  DTCN;                      /**< 000C: Timer Counter                                                */
           uint8_t   RESERVED_0[48];           
   } CH[4];                                     /**< 0000: (cluster: size=0x0100, 256)                                  */
} DTIM_Type;

/**
 * @} */ /* End group DTIM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DTIM' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DTIM_Register_Masks_GROUP DTIM Register Masks
* @brief Register Masks for DTIM
* @{
*/
/* ------- DTMR Bit Fields                          ------ */
#define DTIM_DTMR_RST_MASK                       (0x1U)                                              /*!< DTIM_DTMR: RST Mask                     */
#define DTIM_DTMR_RST_SHIFT                      (0U)                                                /*!< DTIM_DTMR: RST Position                 */
#define DTIM_DTMR_RST(x)                         (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_RST_SHIFT))&DTIM_DTMR_RST_MASK) /*!< DTIM_DTMR                               */
#define DTIM_DTMR_CLK_MASK                       (0x6U)                                              /*!< DTIM_DTMR: CLK Mask                     */
#define DTIM_DTMR_CLK_SHIFT                      (1U)                                                /*!< DTIM_DTMR: CLK Position                 */
#define DTIM_DTMR_CLK(x)                         (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_CLK_SHIFT))&DTIM_DTMR_CLK_MASK) /*!< DTIM_DTMR                               */
#define DTIM_DTMR_FRR_MASK                       (0x8U)                                              /*!< DTIM_DTMR: FRR Mask                     */
#define DTIM_DTMR_FRR_SHIFT                      (3U)                                                /*!< DTIM_DTMR: FRR Position                 */
#define DTIM_DTMR_FRR(x)                         (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_FRR_SHIFT))&DTIM_DTMR_FRR_MASK) /*!< DTIM_DTMR                               */
#define DTIM_DTMR_ORRI_MASK                      (0x10U)                                             /*!< DTIM_DTMR: ORRI Mask                    */
#define DTIM_DTMR_ORRI_SHIFT                     (4U)                                                /*!< DTIM_DTMR: ORRI Position                */
#define DTIM_DTMR_ORRI(x)                        (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_ORRI_SHIFT))&DTIM_DTMR_ORRI_MASK) /*!< DTIM_DTMR                               */
#define DTIM_DTMR_OM_MASK                        (0x20U)                                             /*!< DTIM_DTMR: OM Mask                      */
#define DTIM_DTMR_OM_SHIFT                       (5U)                                                /*!< DTIM_DTMR: OM Position                  */
#define DTIM_DTMR_OM(x)                          (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_OM_SHIFT))&DTIM_DTMR_OM_MASK) /*!< DTIM_DTMR                               */
#define DTIM_DTMR_CE_MASK                        (0xC0U)                                             /*!< DTIM_DTMR: CE Mask                      */
#define DTIM_DTMR_CE_SHIFT                       (6U)                                                /*!< DTIM_DTMR: CE Position                  */
#define DTIM_DTMR_CE(x)                          (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_CE_SHIFT))&DTIM_DTMR_CE_MASK) /*!< DTIM_DTMR                               */
#define DTIM_DTMR_PS_MASK                        (0xFF00U)                                           /*!< DTIM_DTMR: PS Mask                      */
#define DTIM_DTMR_PS_SHIFT                       (8U)                                                /*!< DTIM_DTMR: PS Position                  */
#define DTIM_DTMR_PS(x)                          (((uint16_t)(((uint16_t)(x))<<DTIM_DTMR_PS_SHIFT))&DTIM_DTMR_PS_MASK) /*!< DTIM_DTMR                               */
/* ------- DTXMR Bit Fields                         ------ */
#define DTIM_DTXMR_MODE16_MASK                   (0x1U)                                              /*!< DTIM_DTXMR: MODE16 Mask                 */
#define DTIM_DTXMR_MODE16_SHIFT                  (0U)                                                /*!< DTIM_DTXMR: MODE16 Position             */
#define DTIM_DTXMR_MODE16(x)                     (((uint8_t)(((uint8_t)(x))<<DTIM_DTXMR_MODE16_SHIFT))&DTIM_DTXMR_MODE16_MASK) /*!< DTIM_DTXMR                              */
#define DTIM_DTXMR_HALTED_MASK                   (0x40U)                                             /*!< DTIM_DTXMR: HALTED Mask                 */
#define DTIM_DTXMR_HALTED_SHIFT                  (6U)                                                /*!< DTIM_DTXMR: HALTED Position             */
#define DTIM_DTXMR_HALTED(x)                     (((uint8_t)(((uint8_t)(x))<<DTIM_DTXMR_HALTED_SHIFT))&DTIM_DTXMR_HALTED_MASK) /*!< DTIM_DTXMR                              */
#define DTIM_DTXMR_DMAEN_MASK                    (0x80U)                                             /*!< DTIM_DTXMR: DMAEN Mask                  */
#define DTIM_DTXMR_DMAEN_SHIFT                   (7U)                                                /*!< DTIM_DTXMR: DMAEN Position              */
#define DTIM_DTXMR_DMAEN(x)                      (((uint8_t)(((uint8_t)(x))<<DTIM_DTXMR_DMAEN_SHIFT))&DTIM_DTXMR_DMAEN_MASK) /*!< DTIM_DTXMR                              */
/* ------- DTER Bit Fields                          ------ */
#define DTIM_DTER_CAP_MASK                       (0x1U)                                              /*!< DTIM_DTER: CAP Mask                     */
#define DTIM_DTER_CAP_SHIFT                      (0U)                                                /*!< DTIM_DTER: CAP Position                 */
#define DTIM_DTER_CAP(x)                         (((uint8_t)(((uint8_t)(x))<<DTIM_DTER_CAP_SHIFT))&DTIM_DTER_CAP_MASK) /*!< DTIM_DTER                               */
#define DTIM_DTER_REF_MASK                       (0x2U)                                              /*!< DTIM_DTER: REF Mask                     */
#define DTIM_DTER_REF_SHIFT                      (1U)                                                /*!< DTIM_DTER: REF Position                 */
#define DTIM_DTER_REF(x)                         (((uint8_t)(((uint8_t)(x))<<DTIM_DTER_REF_SHIFT))&DTIM_DTER_REF_MASK) /*!< DTIM_DTER                               */
/* ------- DTRR Bit Fields                          ------ */
#define DTIM_DTRR_REF_MASK                       (0xFFFFFFFFU)                                       /*!< DTIM_DTRR: REF Mask                     */
#define DTIM_DTRR_REF_SHIFT                      (0U)                                                /*!< DTIM_DTRR: REF Position                 */
#define DTIM_DTRR_REF(x)                         (((uint32_t)(((uint32_t)(x))<<DTIM_DTRR_REF_SHIFT))&DTIM_DTRR_REF_MASK) /*!< DTIM_DTRR                               */
/* ------- DTCR Bit Fields                          ------ */
#define DTIM_DTCR_CAP_MASK                       (0xFFFFFFFFU)                                       /*!< DTIM_DTCR: CAP Mask                     */
#define DTIM_DTCR_CAP_SHIFT                      (0U)                                                /*!< DTIM_DTCR: CAP Position                 */
#define DTIM_DTCR_CAP(x)                         (((uint32_t)(((uint32_t)(x))<<DTIM_DTCR_CAP_SHIFT))&DTIM_DTCR_CAP_MASK) /*!< DTIM_DTCR                               */
/* ------- DTCN Bit Fields                          ------ */
#define DTIM_DTCN_CNT_MASK                       (0xFFFFFFFFU)                                       /*!< DTIM_DTCN: CNT Mask                     */
#define DTIM_DTCN_CNT_SHIFT                      (0U)                                                /*!< DTIM_DTCN: CNT Position                 */
#define DTIM_DTCN_CNT(x)                         (((uint32_t)(((uint32_t)(x))<<DTIM_DTCN_CNT_SHIFT))&DTIM_DTCN_CNT_MASK) /*!< DTIM_DTCN                               */
/**
 * @} */ /* End group DTIM_Register_Masks_GROUP 
 */

/* DTIM - Peripheral instance base addresses */
#define DTIM_BasePtr                   0x40000400UL //!< Peripheral base address
#define DTIM                           ((DTIM_Type *) DTIM_BasePtr) //!< Freescale base pointer
#define DTIM_BASE_PTR                  (DTIM) //!< Freescale style base pointer
/**
 * @} */ /* End group DTIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EPHY_Peripheral_access_layer_GROUP EPHY Peripheral Access Layer
* @brief C Struct for EPHY
* @{
*/

/* ================================================================================ */
/* ================           EPHY (file:MCF52233_EPHY)            ================ */
/* ================================================================================ */

/**
 * @brief None
 */
/**
* @addtogroup EPHY_structs_GROUP EPHY struct
* @brief Struct for EPHY
* @{
*/
typedef struct {                                /*       EPHY Structure                                               */
   __IO uint8_t   EPHYCTL0;                     /**< 0000: None                                                         */
   __IO uint8_t   EPHYCTL1;                     /**< 0001: None                                                         */
   __IO uint8_t   EPHYSR;                       /**< 0002: None                                                         */
} EPHY_Type;

/**
 * @} */ /* End group EPHY_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'EPHY' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup EPHY_Register_Masks_GROUP EPHY Register Masks
* @brief Register Masks for EPHY
* @{
*/
/* ------- EPHYCTL0 Bit Fields                      ------ */
#define EPHY_EPHYCTL0_EPHYIEN_MASK               (0x1U)                                              /*!< EPHY_EPHYCTL0: EPHYIEN Mask             */
#define EPHY_EPHYCTL0_EPHYIEN_SHIFT              (0U)                                                /*!< EPHY_EPHYCTL0: EPHYIEN Position         */
#define EPHY_EPHYCTL0_EPHYIEN(x)                 (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL0_EPHYIEN_SHIFT))&EPHY_EPHYCTL0_EPHYIEN_MASK) /*!< EPHY_EPHYCTL0                           */
#define EPHY_EPHYCTL0_EPHYWAI_MASK               (0x4U)                                              /*!< EPHY_EPHYCTL0: EPHYWAI Mask             */
#define EPHY_EPHYCTL0_EPHYWAI_SHIFT              (2U)                                                /*!< EPHY_EPHYCTL0: EPHYWAI Position         */
#define EPHY_EPHYCTL0_EPHYWAI(x)                 (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL0_EPHYWAI_SHIFT))&EPHY_EPHYCTL0_EPHYWAI_MASK) /*!< EPHY_EPHYCTL0                           */
#define EPHY_EPHYCTL0_LEDEN_MASK                 (0x8U)                                              /*!< EPHY_EPHYCTL0: LEDEN Mask               */
#define EPHY_EPHYCTL0_LEDEN_SHIFT                (3U)                                                /*!< EPHY_EPHYCTL0: LEDEN Position           */
#define EPHY_EPHYCTL0_LEDEN(x)                   (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL0_LEDEN_SHIFT))&EPHY_EPHYCTL0_LEDEN_MASK) /*!< EPHY_EPHYCTL0                           */
#define EPHY_EPHYCTL0_DIS10_MASK                 (0x10U)                                             /*!< EPHY_EPHYCTL0: DIS10 Mask               */
#define EPHY_EPHYCTL0_DIS10_SHIFT                (4U)                                                /*!< EPHY_EPHYCTL0: DIS10 Position           */
#define EPHY_EPHYCTL0_DIS10(x)                   (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL0_DIS10_SHIFT))&EPHY_EPHYCTL0_DIS10_MASK) /*!< EPHY_EPHYCTL0                           */
#define EPHY_EPHYCTL0_DIS100_MASK                (0x20U)                                             /*!< EPHY_EPHYCTL0: DIS100 Mask              */
#define EPHY_EPHYCTL0_DIS100_SHIFT               (5U)                                                /*!< EPHY_EPHYCTL0: DIS100 Position          */
#define EPHY_EPHYCTL0_DIS100(x)                  (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL0_DIS100_SHIFT))&EPHY_EPHYCTL0_DIS100_MASK) /*!< EPHY_EPHYCTL0                           */
#define EPHY_EPHYCTL0_ANDIS_MASK                 (0x40U)                                             /*!< EPHY_EPHYCTL0: ANDIS Mask               */
#define EPHY_EPHYCTL0_ANDIS_SHIFT                (6U)                                                /*!< EPHY_EPHYCTL0: ANDIS Position           */
#define EPHY_EPHYCTL0_ANDIS(x)                   (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL0_ANDIS_SHIFT))&EPHY_EPHYCTL0_ANDIS_MASK) /*!< EPHY_EPHYCTL0                           */
#define EPHY_EPHYCTL0_EPHYEN_MASK                (0x80U)                                             /*!< EPHY_EPHYCTL0: EPHYEN Mask              */
#define EPHY_EPHYCTL0_EPHYEN_SHIFT               (7U)                                                /*!< EPHY_EPHYCTL0: EPHYEN Position          */
#define EPHY_EPHYCTL0_EPHYEN(x)                  (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL0_EPHYEN_SHIFT))&EPHY_EPHYCTL0_EPHYEN_MASK) /*!< EPHY_EPHYCTL0                           */
/* ------- EPHYCTL1 Bit Fields                      ------ */
#define EPHY_EPHYCTL1_PHYADD_MASK                (0x1FU)                                             /*!< EPHY_EPHYCTL1: PHYADD Mask              */
#define EPHY_EPHYCTL1_PHYADD_SHIFT               (0U)                                                /*!< EPHY_EPHYCTL1: PHYADD Position          */
#define EPHY_EPHYCTL1_PHYADD(x)                  (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYCTL1_PHYADD_SHIFT))&EPHY_EPHYCTL1_PHYADD_MASK) /*!< EPHY_EPHYCTL1                           */
/* ------- EPHYSR Bit Fields                        ------ */
#define EPHY_EPHYSR_EPHYIF_MASK                  (0x1U)                                              /*!< EPHY_EPHYSR: EPHYIF Mask                */
#define EPHY_EPHYSR_EPHYIF_SHIFT                 (0U)                                                /*!< EPHY_EPHYSR: EPHYIF Position            */
#define EPHY_EPHYSR_EPHYIF(x)                    (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYSR_EPHYIF_SHIFT))&EPHY_EPHYSR_EPHYIF_MASK) /*!< EPHY_EPHYSR                             */
#define EPHY_EPHYSR_DIS10_MASK                   (0x10U)                                             /*!< EPHY_EPHYSR: DIS10 Mask                 */
#define EPHY_EPHYSR_DIS10_SHIFT                  (4U)                                                /*!< EPHY_EPHYSR: DIS10 Position             */
#define EPHY_EPHYSR_DIS10(x)                     (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYSR_DIS10_SHIFT))&EPHY_EPHYSR_DIS10_MASK) /*!< EPHY_EPHYSR                             */
#define EPHY_EPHYSR_DIS100_MASK                  (0x20U)                                             /*!< EPHY_EPHYSR: DIS100 Mask                */
#define EPHY_EPHYSR_DIS100_SHIFT                 (5U)                                                /*!< EPHY_EPHYSR: DIS100 Position            */
#define EPHY_EPHYSR_DIS100(x)                    (((uint8_t)(((uint8_t)(x))<<EPHY_EPHYSR_DIS100_SHIFT))&EPHY_EPHYSR_DIS100_MASK) /*!< EPHY_EPHYSR                             */
/**
 * @} */ /* End group EPHY_Register_Masks_GROUP 
 */

/* EPHY - Peripheral instance base addresses */
#define EPHY_BasePtr                   0x401E0000UL //!< Peripheral base address
#define EPHY                           ((EPHY_Type *) EPHY_BasePtr) //!< Freescale base pointer
#define EPHY_BASE_PTR                  (EPHY) //!< Freescale style base pointer
/**
 * @} */ /* End group EPHY_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EPORT_Peripheral_access_layer_GROUP EPORT Peripheral Access Layer
* @brief C Struct for EPORT
* @{
*/

/* ================================================================================ */
/* ================           EPORT0 (file:MCF522xx_EPORT0)        ================ */
/* ================================================================================ */

/**
 * @brief Edge Port Module
 */
/**
* @addtogroup EPORT_structs_GROUP EPORT struct
* @brief Struct for EPORT
* @{
*/
typedef struct {                                /*       EPORT0 Structure                                             */
   __IO uint16_t  EPPAR;                        /**< 0000: Pin Assignment Register                                      */
   __IO uint8_t   EPDDR;                        /**< 0002: Data Direction Register                                      */
   __IO uint8_t   EPIER;                        /**< 0003: Interrupt Enable Register                                    */
   __IO uint8_t   EPDR;                         /**< 0004: Data Register                                                */
   __I  uint8_t   EPPDR;                        /**< 0005: Pin Data Register                                            */
   __IO uint8_t   EPFR;                         /**< 0006: Edge Flag Register                                           */
} EPORT0_Type;

/**
 * @} */ /* End group EPORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'EPORT0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup EPORT_Register_Masks_GROUP EPORT Register Masks
* @brief Register Masks for EPORT
* @{
*/
/* ------- EPPAR Bit Fields                         ------ */
#define EPORT0_EPPAR_EPPA0_MASK                  (0x3U)                                              /*!< EPORT0_EPPAR: EPPA0 Mask                */
#define EPORT0_EPPAR_EPPA0_SHIFT                 (0U)                                                /*!< EPORT0_EPPAR: EPPA0 Position            */
#define EPORT0_EPPAR_EPPA0(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA0_SHIFT))&EPORT0_EPPAR_EPPA0_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA1_MASK                  (0xCU)                                              /*!< EPORT0_EPPAR: EPPA1 Mask                */
#define EPORT0_EPPAR_EPPA1_SHIFT                 (2U)                                                /*!< EPORT0_EPPAR: EPPA1 Position            */
#define EPORT0_EPPAR_EPPA1(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA1_SHIFT))&EPORT0_EPPAR_EPPA1_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA2_MASK                  (0x30U)                                             /*!< EPORT0_EPPAR: EPPA2 Mask                */
#define EPORT0_EPPAR_EPPA2_SHIFT                 (4U)                                                /*!< EPORT0_EPPAR: EPPA2 Position            */
#define EPORT0_EPPAR_EPPA2(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA2_SHIFT))&EPORT0_EPPAR_EPPA2_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA3_MASK                  (0xC0U)                                             /*!< EPORT0_EPPAR: EPPA3 Mask                */
#define EPORT0_EPPAR_EPPA3_SHIFT                 (6U)                                                /*!< EPORT0_EPPAR: EPPA3 Position            */
#define EPORT0_EPPAR_EPPA3(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA3_SHIFT))&EPORT0_EPPAR_EPPA3_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA4_MASK                  (0x300U)                                            /*!< EPORT0_EPPAR: EPPA4 Mask                */
#define EPORT0_EPPAR_EPPA4_SHIFT                 (8U)                                                /*!< EPORT0_EPPAR: EPPA4 Position            */
#define EPORT0_EPPAR_EPPA4(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA4_SHIFT))&EPORT0_EPPAR_EPPA4_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA5_MASK                  (0xC00U)                                            /*!< EPORT0_EPPAR: EPPA5 Mask                */
#define EPORT0_EPPAR_EPPA5_SHIFT                 (10U)                                               /*!< EPORT0_EPPAR: EPPA5 Position            */
#define EPORT0_EPPAR_EPPA5(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA5_SHIFT))&EPORT0_EPPAR_EPPA5_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA6_MASK                  (0x3000U)                                           /*!< EPORT0_EPPAR: EPPA6 Mask                */
#define EPORT0_EPPAR_EPPA6_SHIFT                 (12U)                                               /*!< EPORT0_EPPAR: EPPA6 Position            */
#define EPORT0_EPPAR_EPPA6(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA6_SHIFT))&EPORT0_EPPAR_EPPA6_MASK) /*!< EPORT0_EPPAR                            */
#define EPORT0_EPPAR_EPPA7_MASK                  (0xC000U)                                           /*!< EPORT0_EPPAR: EPPA7 Mask                */
#define EPORT0_EPPAR_EPPA7_SHIFT                 (14U)                                               /*!< EPORT0_EPPAR: EPPA7 Position            */
#define EPORT0_EPPAR_EPPA7(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT0_EPPAR_EPPA7_SHIFT))&EPORT0_EPPAR_EPPA7_MASK) /*!< EPORT0_EPPAR                            */
/* ------- EPDDR Bit Fields                         ------ */
#define EPORT0_EPDDR_EPDD0_MASK                  (0x1U)                                              /*!< EPORT0_EPDDR: EPDD0 Mask                */
#define EPORT0_EPDDR_EPDD0_SHIFT                 (0U)                                                /*!< EPORT0_EPDDR: EPDD0 Position            */
#define EPORT0_EPDDR_EPDD0(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDDR_EPDD0_SHIFT))&EPORT0_EPDDR_EPDD0_MASK) /*!< EPORT0_EPDDR                            */
#define EPORT0_EPDDR_EPDD1_MASK                  (0x2U)                                              /*!< EPORT0_EPDDR: EPDD1 Mask                */
#define EPORT0_EPDDR_EPDD1_SHIFT                 (1U)                                                /*!< EPORT0_EPDDR: EPDD1 Position            */
#define EPORT0_EPDDR_EPDD1(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDDR_EPDD1_SHIFT))&EPORT0_EPDDR_EPDD1_MASK) /*!< EPORT0_EPDDR                            */
#define EPORT0_EPDDR_EPDD2_MASK                  (0x4U)                                              /*!< EPORT0_EPDDR: EPDD2 Mask                */
#define EPORT0_EPDDR_EPDD2_SHIFT                 (2U)                                                /*!< EPORT0_EPDDR: EPDD2 Position            */
#define EPORT0_EPDDR_EPDD2(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDDR_EPDD2_SHIFT))&EPORT0_EPDDR_EPDD2_MASK) /*!< EPORT0_EPDDR                            */
#define EPORT0_EPDDR_EPDD3_MASK                  (0x8U)                                              /*!< EPORT0_EPDDR: EPDD3 Mask                */
#define EPORT0_EPDDR_EPDD3_SHIFT                 (3U)                                                /*!< EPORT0_EPDDR: EPDD3 Position            */
#define EPORT0_EPDDR_EPDD3(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDDR_EPDD3_SHIFT))&EPORT0_EPDDR_EPDD3_MASK) /*!< EPORT0_EPDDR                            */
#define EPORT0_EPDDR_EPDD4_MASK                  (0x10U)                                             /*!< EPORT0_EPDDR: EPDD4 Mask                */
#define EPORT0_EPDDR_EPDD4_SHIFT                 (4U)                                                /*!< EPORT0_EPDDR: EPDD4 Position            */
#define EPORT0_EPDDR_EPDD4(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDDR_EPDD4_SHIFT))&EPORT0_EPDDR_EPDD4_MASK) /*!< EPORT0_EPDDR                            */
#define EPORT0_EPDDR_EPDD5_MASK                  (0x20U)                                             /*!< EPORT0_EPDDR: EPDD5 Mask                */
#define EPORT0_EPDDR_EPDD5_SHIFT                 (5U)                                                /*!< EPORT0_EPDDR: EPDD5 Position            */
#define EPORT0_EPDDR_EPDD5(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDDR_EPDD5_SHIFT))&EPORT0_EPDDR_EPDD5_MASK) /*!< EPORT0_EPDDR                            */
#define EPORT0_EPDDR_EPDD6_MASK                  (0x40U)                                             /*!< EPORT0_EPDDR: EPDD6 Mask                */
#define EPORT0_EPDDR_EPDD6_SHIFT                 (6U)                                                /*!< EPORT0_EPDDR: EPDD6 Position            */
#define EPORT0_EPDDR_EPDD6(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDDR_EPDD6_SHIFT))&EPORT0_EPDDR_EPDD6_MASK) /*!< EPORT0_EPDDR                            */
#define EPORT0_EPDDR_EPDD7_MASK                  (0x80U)                                             /*!< EPORT0_EPDDR: EPDD7 Mask                */
#define EPORT0_EPDDR_EPDD7_SHIFT                 (7U)                                                /*!< EPORT0_EPDDR: EPDD7 Position            */
#define EPORT0_EPDDR_EPDD7(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDDR_EPDD7_SHIFT))&EPORT0_EPDDR_EPDD7_MASK) /*!< EPORT0_EPDDR                            */
/* ------- EPIER Bit Fields                         ------ */
#define EPORT0_EPIER_EPIE0_MASK                  (0x1U)                                              /*!< EPORT0_EPIER: EPIE0 Mask                */
#define EPORT0_EPIER_EPIE0_SHIFT                 (0U)                                                /*!< EPORT0_EPIER: EPIE0 Position            */
#define EPORT0_EPIER_EPIE0(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPIER_EPIE0_SHIFT))&EPORT0_EPIER_EPIE0_MASK) /*!< EPORT0_EPIER                            */
#define EPORT0_EPIER_EPIE1_MASK                  (0x2U)                                              /*!< EPORT0_EPIER: EPIE1 Mask                */
#define EPORT0_EPIER_EPIE1_SHIFT                 (1U)                                                /*!< EPORT0_EPIER: EPIE1 Position            */
#define EPORT0_EPIER_EPIE1(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPIER_EPIE1_SHIFT))&EPORT0_EPIER_EPIE1_MASK) /*!< EPORT0_EPIER                            */
#define EPORT0_EPIER_EPIE2_MASK                  (0x4U)                                              /*!< EPORT0_EPIER: EPIE2 Mask                */
#define EPORT0_EPIER_EPIE2_SHIFT                 (2U)                                                /*!< EPORT0_EPIER: EPIE2 Position            */
#define EPORT0_EPIER_EPIE2(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPIER_EPIE2_SHIFT))&EPORT0_EPIER_EPIE2_MASK) /*!< EPORT0_EPIER                            */
#define EPORT0_EPIER_EPIE3_MASK                  (0x8U)                                              /*!< EPORT0_EPIER: EPIE3 Mask                */
#define EPORT0_EPIER_EPIE3_SHIFT                 (3U)                                                /*!< EPORT0_EPIER: EPIE3 Position            */
#define EPORT0_EPIER_EPIE3(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPIER_EPIE3_SHIFT))&EPORT0_EPIER_EPIE3_MASK) /*!< EPORT0_EPIER                            */
#define EPORT0_EPIER_EPIE4_MASK                  (0x10U)                                             /*!< EPORT0_EPIER: EPIE4 Mask                */
#define EPORT0_EPIER_EPIE4_SHIFT                 (4U)                                                /*!< EPORT0_EPIER: EPIE4 Position            */
#define EPORT0_EPIER_EPIE4(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPIER_EPIE4_SHIFT))&EPORT0_EPIER_EPIE4_MASK) /*!< EPORT0_EPIER                            */
#define EPORT0_EPIER_EPIE5_MASK                  (0x20U)                                             /*!< EPORT0_EPIER: EPIE5 Mask                */
#define EPORT0_EPIER_EPIE5_SHIFT                 (5U)                                                /*!< EPORT0_EPIER: EPIE5 Position            */
#define EPORT0_EPIER_EPIE5(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPIER_EPIE5_SHIFT))&EPORT0_EPIER_EPIE5_MASK) /*!< EPORT0_EPIER                            */
#define EPORT0_EPIER_EPIE6_MASK                  (0x40U)                                             /*!< EPORT0_EPIER: EPIE6 Mask                */
#define EPORT0_EPIER_EPIE6_SHIFT                 (6U)                                                /*!< EPORT0_EPIER: EPIE6 Position            */
#define EPORT0_EPIER_EPIE6(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPIER_EPIE6_SHIFT))&EPORT0_EPIER_EPIE6_MASK) /*!< EPORT0_EPIER                            */
#define EPORT0_EPIER_EPIE7_MASK                  (0x80U)                                             /*!< EPORT0_EPIER: EPIE7 Mask                */
#define EPORT0_EPIER_EPIE7_SHIFT                 (7U)                                                /*!< EPORT0_EPIER: EPIE7 Position            */
#define EPORT0_EPIER_EPIE7(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPIER_EPIE7_SHIFT))&EPORT0_EPIER_EPIE7_MASK) /*!< EPORT0_EPIER                            */
/* ------- EPDR Bit Fields                          ------ */
#define EPORT0_EPDR_EPD0_MASK                    (0x1U)                                              /*!< EPORT0_EPDR: EPD0 Mask                  */
#define EPORT0_EPDR_EPD0_SHIFT                   (0U)                                                /*!< EPORT0_EPDR: EPD0 Position              */
#define EPORT0_EPDR_EPD0(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDR_EPD0_SHIFT))&EPORT0_EPDR_EPD0_MASK) /*!< EPORT0_EPDR                             */
#define EPORT0_EPDR_EPD1_MASK                    (0x2U)                                              /*!< EPORT0_EPDR: EPD1 Mask                  */
#define EPORT0_EPDR_EPD1_SHIFT                   (1U)                                                /*!< EPORT0_EPDR: EPD1 Position              */
#define EPORT0_EPDR_EPD1(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDR_EPD1_SHIFT))&EPORT0_EPDR_EPD1_MASK) /*!< EPORT0_EPDR                             */
#define EPORT0_EPDR_EPD2_MASK                    (0x4U)                                              /*!< EPORT0_EPDR: EPD2 Mask                  */
#define EPORT0_EPDR_EPD2_SHIFT                   (2U)                                                /*!< EPORT0_EPDR: EPD2 Position              */
#define EPORT0_EPDR_EPD2(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDR_EPD2_SHIFT))&EPORT0_EPDR_EPD2_MASK) /*!< EPORT0_EPDR                             */
#define EPORT0_EPDR_EPD3_MASK                    (0x8U)                                              /*!< EPORT0_EPDR: EPD3 Mask                  */
#define EPORT0_EPDR_EPD3_SHIFT                   (3U)                                                /*!< EPORT0_EPDR: EPD3 Position              */
#define EPORT0_EPDR_EPD3(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDR_EPD3_SHIFT))&EPORT0_EPDR_EPD3_MASK) /*!< EPORT0_EPDR                             */
#define EPORT0_EPDR_EPD4_MASK                    (0x10U)                                             /*!< EPORT0_EPDR: EPD4 Mask                  */
#define EPORT0_EPDR_EPD4_SHIFT                   (4U)                                                /*!< EPORT0_EPDR: EPD4 Position              */
#define EPORT0_EPDR_EPD4(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDR_EPD4_SHIFT))&EPORT0_EPDR_EPD4_MASK) /*!< EPORT0_EPDR                             */
#define EPORT0_EPDR_EPD5_MASK                    (0x20U)                                             /*!< EPORT0_EPDR: EPD5 Mask                  */
#define EPORT0_EPDR_EPD5_SHIFT                   (5U)                                                /*!< EPORT0_EPDR: EPD5 Position              */
#define EPORT0_EPDR_EPD5(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDR_EPD5_SHIFT))&EPORT0_EPDR_EPD5_MASK) /*!< EPORT0_EPDR                             */
#define EPORT0_EPDR_EPD6_MASK                    (0x40U)                                             /*!< EPORT0_EPDR: EPD6 Mask                  */
#define EPORT0_EPDR_EPD6_SHIFT                   (6U)                                                /*!< EPORT0_EPDR: EPD6 Position              */
#define EPORT0_EPDR_EPD6(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDR_EPD6_SHIFT))&EPORT0_EPDR_EPD6_MASK) /*!< EPORT0_EPDR                             */
#define EPORT0_EPDR_EPD7_MASK                    (0x80U)                                             /*!< EPORT0_EPDR: EPD7 Mask                  */
#define EPORT0_EPDR_EPD7_SHIFT                   (7U)                                                /*!< EPORT0_EPDR: EPD7 Position              */
#define EPORT0_EPDR_EPD7(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPDR_EPD7_SHIFT))&EPORT0_EPDR_EPD7_MASK) /*!< EPORT0_EPDR                             */
/* ------- EPPDR Bit Fields                         ------ */
#define EPORT0_EPPDR_EPPD0_MASK                  (0x1U)                                              /*!< EPORT0_EPPDR: EPPD0 Mask                */
#define EPORT0_EPPDR_EPPD0_SHIFT                 (0U)                                                /*!< EPORT0_EPPDR: EPPD0 Position            */
#define EPORT0_EPPDR_EPPD0(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPPDR_EPPD0_SHIFT))&EPORT0_EPPDR_EPPD0_MASK) /*!< EPORT0_EPPDR                            */
#define EPORT0_EPPDR_EPPD1_MASK                  (0x2U)                                              /*!< EPORT0_EPPDR: EPPD1 Mask                */
#define EPORT0_EPPDR_EPPD1_SHIFT                 (1U)                                                /*!< EPORT0_EPPDR: EPPD1 Position            */
#define EPORT0_EPPDR_EPPD1(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPPDR_EPPD1_SHIFT))&EPORT0_EPPDR_EPPD1_MASK) /*!< EPORT0_EPPDR                            */
#define EPORT0_EPPDR_EPPD2_MASK                  (0x4U)                                              /*!< EPORT0_EPPDR: EPPD2 Mask                */
#define EPORT0_EPPDR_EPPD2_SHIFT                 (2U)                                                /*!< EPORT0_EPPDR: EPPD2 Position            */
#define EPORT0_EPPDR_EPPD2(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPPDR_EPPD2_SHIFT))&EPORT0_EPPDR_EPPD2_MASK) /*!< EPORT0_EPPDR                            */
#define EPORT0_EPPDR_EPPD3_MASK                  (0x8U)                                              /*!< EPORT0_EPPDR: EPPD3 Mask                */
#define EPORT0_EPPDR_EPPD3_SHIFT                 (3U)                                                /*!< EPORT0_EPPDR: EPPD3 Position            */
#define EPORT0_EPPDR_EPPD3(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPPDR_EPPD3_SHIFT))&EPORT0_EPPDR_EPPD3_MASK) /*!< EPORT0_EPPDR                            */
#define EPORT0_EPPDR_EPPD4_MASK                  (0x10U)                                             /*!< EPORT0_EPPDR: EPPD4 Mask                */
#define EPORT0_EPPDR_EPPD4_SHIFT                 (4U)                                                /*!< EPORT0_EPPDR: EPPD4 Position            */
#define EPORT0_EPPDR_EPPD4(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPPDR_EPPD4_SHIFT))&EPORT0_EPPDR_EPPD4_MASK) /*!< EPORT0_EPPDR                            */
#define EPORT0_EPPDR_EPPD5_MASK                  (0x20U)                                             /*!< EPORT0_EPPDR: EPPD5 Mask                */
#define EPORT0_EPPDR_EPPD5_SHIFT                 (5U)                                                /*!< EPORT0_EPPDR: EPPD5 Position            */
#define EPORT0_EPPDR_EPPD5(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPPDR_EPPD5_SHIFT))&EPORT0_EPPDR_EPPD5_MASK) /*!< EPORT0_EPPDR                            */
#define EPORT0_EPPDR_EPPD6_MASK                  (0x40U)                                             /*!< EPORT0_EPPDR: EPPD6 Mask                */
#define EPORT0_EPPDR_EPPD6_SHIFT                 (6U)                                                /*!< EPORT0_EPPDR: EPPD6 Position            */
#define EPORT0_EPPDR_EPPD6(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPPDR_EPPD6_SHIFT))&EPORT0_EPPDR_EPPD6_MASK) /*!< EPORT0_EPPDR                            */
#define EPORT0_EPPDR_EPPD7_MASK                  (0x80U)                                             /*!< EPORT0_EPPDR: EPPD7 Mask                */
#define EPORT0_EPPDR_EPPD7_SHIFT                 (7U)                                                /*!< EPORT0_EPPDR: EPPD7 Position            */
#define EPORT0_EPPDR_EPPD7(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT0_EPPDR_EPPD7_SHIFT))&EPORT0_EPPDR_EPPD7_MASK) /*!< EPORT0_EPPDR                            */
/* ------- EPFR Bit Fields                          ------ */
#define EPORT0_EPFR_EPF0_MASK                    (0x1U)                                              /*!< EPORT0_EPFR: EPF0 Mask                  */
#define EPORT0_EPFR_EPF0_SHIFT                   (0U)                                                /*!< EPORT0_EPFR: EPF0 Position              */
#define EPORT0_EPFR_EPF0(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPFR_EPF0_SHIFT))&EPORT0_EPFR_EPF0_MASK) /*!< EPORT0_EPFR                             */
#define EPORT0_EPFR_EPF1_MASK                    (0x2U)                                              /*!< EPORT0_EPFR: EPF1 Mask                  */
#define EPORT0_EPFR_EPF1_SHIFT                   (1U)                                                /*!< EPORT0_EPFR: EPF1 Position              */
#define EPORT0_EPFR_EPF1(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPFR_EPF1_SHIFT))&EPORT0_EPFR_EPF1_MASK) /*!< EPORT0_EPFR                             */
#define EPORT0_EPFR_EPF2_MASK                    (0x4U)                                              /*!< EPORT0_EPFR: EPF2 Mask                  */
#define EPORT0_EPFR_EPF2_SHIFT                   (2U)                                                /*!< EPORT0_EPFR: EPF2 Position              */
#define EPORT0_EPFR_EPF2(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPFR_EPF2_SHIFT))&EPORT0_EPFR_EPF2_MASK) /*!< EPORT0_EPFR                             */
#define EPORT0_EPFR_EPF3_MASK                    (0x8U)                                              /*!< EPORT0_EPFR: EPF3 Mask                  */
#define EPORT0_EPFR_EPF3_SHIFT                   (3U)                                                /*!< EPORT0_EPFR: EPF3 Position              */
#define EPORT0_EPFR_EPF3(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPFR_EPF3_SHIFT))&EPORT0_EPFR_EPF3_MASK) /*!< EPORT0_EPFR                             */
#define EPORT0_EPFR_EPF4_MASK                    (0x10U)                                             /*!< EPORT0_EPFR: EPF4 Mask                  */
#define EPORT0_EPFR_EPF4_SHIFT                   (4U)                                                /*!< EPORT0_EPFR: EPF4 Position              */
#define EPORT0_EPFR_EPF4(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPFR_EPF4_SHIFT))&EPORT0_EPFR_EPF4_MASK) /*!< EPORT0_EPFR                             */
#define EPORT0_EPFR_EPF5_MASK                    (0x20U)                                             /*!< EPORT0_EPFR: EPF5 Mask                  */
#define EPORT0_EPFR_EPF5_SHIFT                   (5U)                                                /*!< EPORT0_EPFR: EPF5 Position              */
#define EPORT0_EPFR_EPF5(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPFR_EPF5_SHIFT))&EPORT0_EPFR_EPF5_MASK) /*!< EPORT0_EPFR                             */
#define EPORT0_EPFR_EPF6_MASK                    (0x40U)                                             /*!< EPORT0_EPFR: EPF6 Mask                  */
#define EPORT0_EPFR_EPF6_SHIFT                   (6U)                                                /*!< EPORT0_EPFR: EPF6 Position              */
#define EPORT0_EPFR_EPF6(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPFR_EPF6_SHIFT))&EPORT0_EPFR_EPF6_MASK) /*!< EPORT0_EPFR                             */
#define EPORT0_EPFR_EPF7_MASK                    (0x80U)                                             /*!< EPORT0_EPFR: EPF7 Mask                  */
#define EPORT0_EPFR_EPF7_SHIFT                   (7U)                                                /*!< EPORT0_EPFR: EPF7 Position              */
#define EPORT0_EPFR_EPF7(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT0_EPFR_EPF7_SHIFT))&EPORT0_EPFR_EPF7_MASK) /*!< EPORT0_EPFR                             */
/**
 * @} */ /* End group EPORT_Register_Masks_GROUP 
 */

/* EPORT0 - Peripheral instance base addresses */
#define EPORT0_BasePtr                 0x40130000UL //!< Peripheral base address
#define EPORT0                         ((EPORT0_Type *) EPORT0_BasePtr) //!< Freescale base pointer
#define EPORT0_BASE_PTR                (EPORT0) //!< Freescale style base pointer
/**
 * @} */ /* End group EPORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EPORT_Peripheral_access_layer_GROUP EPORT Peripheral Access Layer
* @brief C Struct for EPORT
* @{
*/

/* ================================================================================ */
/* ================           EPORT1 (file:MCF522xx_EPORT1)        ================ */
/* ================================================================================ */

/**
 * @brief Edge Port Module
 */
/**
* @addtogroup EPORT_structs_GROUP EPORT struct
* @brief Struct for EPORT
* @{
*/
typedef struct {                                /*       EPORT1 Structure                                             */
   __IO uint16_t  EPPAR;                        /**< 0000: Pin Assignment Register                                      */
   __IO uint8_t   EPDDR;                        /**< 0002: Data Direction Register                                      */
   __IO uint8_t   EPIER;                        /**< 0003: Interrupt Enable Register                                    */
   __IO uint8_t   EPDR;                         /**< 0004: Data Register                                                */
   __I  uint8_t   EPPDR;                        /**< 0005: Pin Data Register                                            */
   __IO uint8_t   EPFR;                         /**< 0006: Edge Flag Register                                           */
} EPORT1_Type;

/**
 * @} */ /* End group EPORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'EPORT1' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup EPORT_Register_Masks_GROUP EPORT Register Masks
* @brief Register Masks for EPORT
* @{
*/
/* ------- EPPAR Bit Fields                         ------ */
#define EPORT1_EPPAR_EPPA8_MASK                  (0x3U)                                              /*!< EPORT1_EPPAR: EPPA8 Mask                */
#define EPORT1_EPPAR_EPPA8_SHIFT                 (0U)                                                /*!< EPORT1_EPPAR: EPPA8 Position            */
#define EPORT1_EPPAR_EPPA8(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA8_SHIFT))&EPORT1_EPPAR_EPPA8_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA9_MASK                  (0xCU)                                              /*!< EPORT1_EPPAR: EPPA9 Mask                */
#define EPORT1_EPPAR_EPPA9_SHIFT                 (2U)                                                /*!< EPORT1_EPPAR: EPPA9 Position            */
#define EPORT1_EPPAR_EPPA9(x)                    (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA9_SHIFT))&EPORT1_EPPAR_EPPA9_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA10_MASK                 (0x30U)                                             /*!< EPORT1_EPPAR: EPPA10 Mask               */
#define EPORT1_EPPAR_EPPA10_SHIFT                (4U)                                                /*!< EPORT1_EPPAR: EPPA10 Position           */
#define EPORT1_EPPAR_EPPA10(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA10_SHIFT))&EPORT1_EPPAR_EPPA10_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA11_MASK                 (0xC0U)                                             /*!< EPORT1_EPPAR: EPPA11 Mask               */
#define EPORT1_EPPAR_EPPA11_SHIFT                (6U)                                                /*!< EPORT1_EPPAR: EPPA11 Position           */
#define EPORT1_EPPAR_EPPA11(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA11_SHIFT))&EPORT1_EPPAR_EPPA11_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA12_MASK                 (0x300U)                                            /*!< EPORT1_EPPAR: EPPA12 Mask               */
#define EPORT1_EPPAR_EPPA12_SHIFT                (8U)                                                /*!< EPORT1_EPPAR: EPPA12 Position           */
#define EPORT1_EPPAR_EPPA12(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA12_SHIFT))&EPORT1_EPPAR_EPPA12_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA13_MASK                 (0xC00U)                                            /*!< EPORT1_EPPAR: EPPA13 Mask               */
#define EPORT1_EPPAR_EPPA13_SHIFT                (10U)                                               /*!< EPORT1_EPPAR: EPPA13 Position           */
#define EPORT1_EPPAR_EPPA13(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA13_SHIFT))&EPORT1_EPPAR_EPPA13_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA14_MASK                 (0x3000U)                                           /*!< EPORT1_EPPAR: EPPA14 Mask               */
#define EPORT1_EPPAR_EPPA14_SHIFT                (12U)                                               /*!< EPORT1_EPPAR: EPPA14 Position           */
#define EPORT1_EPPAR_EPPA14(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA14_SHIFT))&EPORT1_EPPAR_EPPA14_MASK) /*!< EPORT1_EPPAR                            */
#define EPORT1_EPPAR_EPPA15_MASK                 (0xC000U)                                           /*!< EPORT1_EPPAR: EPPA15 Mask               */
#define EPORT1_EPPAR_EPPA15_SHIFT                (14U)                                               /*!< EPORT1_EPPAR: EPPA15 Position           */
#define EPORT1_EPPAR_EPPA15(x)                   (((uint16_t)(((uint16_t)(x))<<EPORT1_EPPAR_EPPA15_SHIFT))&EPORT1_EPPAR_EPPA15_MASK) /*!< EPORT1_EPPAR                            */
/* ------- EPDDR Bit Fields                         ------ */
#define EPORT1_EPDDR_EPDD8_MASK                  (0x1U)                                              /*!< EPORT1_EPDDR: EPDD8 Mask                */
#define EPORT1_EPDDR_EPDD8_SHIFT                 (0U)                                                /*!< EPORT1_EPDDR: EPDD8 Position            */
#define EPORT1_EPDDR_EPDD8(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDDR_EPDD8_SHIFT))&EPORT1_EPDDR_EPDD8_MASK) /*!< EPORT1_EPDDR                            */
#define EPORT1_EPDDR_EPDD9_MASK                  (0x2U)                                              /*!< EPORT1_EPDDR: EPDD9 Mask                */
#define EPORT1_EPDDR_EPDD9_SHIFT                 (1U)                                                /*!< EPORT1_EPDDR: EPDD9 Position            */
#define EPORT1_EPDDR_EPDD9(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDDR_EPDD9_SHIFT))&EPORT1_EPDDR_EPDD9_MASK) /*!< EPORT1_EPDDR                            */
#define EPORT1_EPDDR_EPDD10_MASK                 (0x4U)                                              /*!< EPORT1_EPDDR: EPDD10 Mask               */
#define EPORT1_EPDDR_EPDD10_SHIFT                (2U)                                                /*!< EPORT1_EPDDR: EPDD10 Position           */
#define EPORT1_EPDDR_EPDD10(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDDR_EPDD10_SHIFT))&EPORT1_EPDDR_EPDD10_MASK) /*!< EPORT1_EPDDR                            */
#define EPORT1_EPDDR_EPDD11_MASK                 (0x8U)                                              /*!< EPORT1_EPDDR: EPDD11 Mask               */
#define EPORT1_EPDDR_EPDD11_SHIFT                (3U)                                                /*!< EPORT1_EPDDR: EPDD11 Position           */
#define EPORT1_EPDDR_EPDD11(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDDR_EPDD11_SHIFT))&EPORT1_EPDDR_EPDD11_MASK) /*!< EPORT1_EPDDR                            */
#define EPORT1_EPDDR_EPDD12_MASK                 (0x10U)                                             /*!< EPORT1_EPDDR: EPDD12 Mask               */
#define EPORT1_EPDDR_EPDD12_SHIFT                (4U)                                                /*!< EPORT1_EPDDR: EPDD12 Position           */
#define EPORT1_EPDDR_EPDD12(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDDR_EPDD12_SHIFT))&EPORT1_EPDDR_EPDD12_MASK) /*!< EPORT1_EPDDR                            */
#define EPORT1_EPDDR_EPDD13_MASK                 (0x20U)                                             /*!< EPORT1_EPDDR: EPDD13 Mask               */
#define EPORT1_EPDDR_EPDD13_SHIFT                (5U)                                                /*!< EPORT1_EPDDR: EPDD13 Position           */
#define EPORT1_EPDDR_EPDD13(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDDR_EPDD13_SHIFT))&EPORT1_EPDDR_EPDD13_MASK) /*!< EPORT1_EPDDR                            */
#define EPORT1_EPDDR_EPDD14_MASK                 (0x40U)                                             /*!< EPORT1_EPDDR: EPDD14 Mask               */
#define EPORT1_EPDDR_EPDD14_SHIFT                (6U)                                                /*!< EPORT1_EPDDR: EPDD14 Position           */
#define EPORT1_EPDDR_EPDD14(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDDR_EPDD14_SHIFT))&EPORT1_EPDDR_EPDD14_MASK) /*!< EPORT1_EPDDR                            */
#define EPORT1_EPDDR_EPDD15_MASK                 (0x80U)                                             /*!< EPORT1_EPDDR: EPDD15 Mask               */
#define EPORT1_EPDDR_EPDD15_SHIFT                (7U)                                                /*!< EPORT1_EPDDR: EPDD15 Position           */
#define EPORT1_EPDDR_EPDD15(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDDR_EPDD15_SHIFT))&EPORT1_EPDDR_EPDD15_MASK) /*!< EPORT1_EPDDR                            */
/* ------- EPIER Bit Fields                         ------ */
#define EPORT1_EPIER_EPIE8_MASK                  (0x1U)                                              /*!< EPORT1_EPIER: EPIE8 Mask                */
#define EPORT1_EPIER_EPIE8_SHIFT                 (0U)                                                /*!< EPORT1_EPIER: EPIE8 Position            */
#define EPORT1_EPIER_EPIE8(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT1_EPIER_EPIE8_SHIFT))&EPORT1_EPIER_EPIE8_MASK) /*!< EPORT1_EPIER                            */
#define EPORT1_EPIER_EPIE9_MASK                  (0x2U)                                              /*!< EPORT1_EPIER: EPIE9 Mask                */
#define EPORT1_EPIER_EPIE9_SHIFT                 (1U)                                                /*!< EPORT1_EPIER: EPIE9 Position            */
#define EPORT1_EPIER_EPIE9(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT1_EPIER_EPIE9_SHIFT))&EPORT1_EPIER_EPIE9_MASK) /*!< EPORT1_EPIER                            */
#define EPORT1_EPIER_EPIE10_MASK                 (0x4U)                                              /*!< EPORT1_EPIER: EPIE10 Mask               */
#define EPORT1_EPIER_EPIE10_SHIFT                (2U)                                                /*!< EPORT1_EPIER: EPIE10 Position           */
#define EPORT1_EPIER_EPIE10(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPIER_EPIE10_SHIFT))&EPORT1_EPIER_EPIE10_MASK) /*!< EPORT1_EPIER                            */
#define EPORT1_EPIER_EPIE11_MASK                 (0x8U)                                              /*!< EPORT1_EPIER: EPIE11 Mask               */
#define EPORT1_EPIER_EPIE11_SHIFT                (3U)                                                /*!< EPORT1_EPIER: EPIE11 Position           */
#define EPORT1_EPIER_EPIE11(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPIER_EPIE11_SHIFT))&EPORT1_EPIER_EPIE11_MASK) /*!< EPORT1_EPIER                            */
#define EPORT1_EPIER_EPIE12_MASK                 (0x10U)                                             /*!< EPORT1_EPIER: EPIE12 Mask               */
#define EPORT1_EPIER_EPIE12_SHIFT                (4U)                                                /*!< EPORT1_EPIER: EPIE12 Position           */
#define EPORT1_EPIER_EPIE12(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPIER_EPIE12_SHIFT))&EPORT1_EPIER_EPIE12_MASK) /*!< EPORT1_EPIER                            */
#define EPORT1_EPIER_EPIE13_MASK                 (0x20U)                                             /*!< EPORT1_EPIER: EPIE13 Mask               */
#define EPORT1_EPIER_EPIE13_SHIFT                (5U)                                                /*!< EPORT1_EPIER: EPIE13 Position           */
#define EPORT1_EPIER_EPIE13(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPIER_EPIE13_SHIFT))&EPORT1_EPIER_EPIE13_MASK) /*!< EPORT1_EPIER                            */
#define EPORT1_EPIER_EPIE14_MASK                 (0x40U)                                             /*!< EPORT1_EPIER: EPIE14 Mask               */
#define EPORT1_EPIER_EPIE14_SHIFT                (6U)                                                /*!< EPORT1_EPIER: EPIE14 Position           */
#define EPORT1_EPIER_EPIE14(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPIER_EPIE14_SHIFT))&EPORT1_EPIER_EPIE14_MASK) /*!< EPORT1_EPIER                            */
#define EPORT1_EPIER_EPIE15_MASK                 (0x80U)                                             /*!< EPORT1_EPIER: EPIE15 Mask               */
#define EPORT1_EPIER_EPIE15_SHIFT                (7U)                                                /*!< EPORT1_EPIER: EPIE15 Position           */
#define EPORT1_EPIER_EPIE15(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPIER_EPIE15_SHIFT))&EPORT1_EPIER_EPIE15_MASK) /*!< EPORT1_EPIER                            */
/* ------- EPDR Bit Fields                          ------ */
#define EPORT1_EPDR_EPD8_MASK                    (0x1U)                                              /*!< EPORT1_EPDR: EPD8 Mask                  */
#define EPORT1_EPDR_EPD8_SHIFT                   (0U)                                                /*!< EPORT1_EPDR: EPD8 Position              */
#define EPORT1_EPDR_EPD8(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDR_EPD8_SHIFT))&EPORT1_EPDR_EPD8_MASK) /*!< EPORT1_EPDR                             */
#define EPORT1_EPDR_EPD9_MASK                    (0x2U)                                              /*!< EPORT1_EPDR: EPD9 Mask                  */
#define EPORT1_EPDR_EPD9_SHIFT                   (1U)                                                /*!< EPORT1_EPDR: EPD9 Position              */
#define EPORT1_EPDR_EPD9(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDR_EPD9_SHIFT))&EPORT1_EPDR_EPD9_MASK) /*!< EPORT1_EPDR                             */
#define EPORT1_EPDR_EPD10_MASK                   (0x4U)                                              /*!< EPORT1_EPDR: EPD10 Mask                 */
#define EPORT1_EPDR_EPD10_SHIFT                  (2U)                                                /*!< EPORT1_EPDR: EPD10 Position             */
#define EPORT1_EPDR_EPD10(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDR_EPD10_SHIFT))&EPORT1_EPDR_EPD10_MASK) /*!< EPORT1_EPDR                             */
#define EPORT1_EPDR_EPD11_MASK                   (0x8U)                                              /*!< EPORT1_EPDR: EPD11 Mask                 */
#define EPORT1_EPDR_EPD11_SHIFT                  (3U)                                                /*!< EPORT1_EPDR: EPD11 Position             */
#define EPORT1_EPDR_EPD11(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDR_EPD11_SHIFT))&EPORT1_EPDR_EPD11_MASK) /*!< EPORT1_EPDR                             */
#define EPORT1_EPDR_EPD12_MASK                   (0x10U)                                             /*!< EPORT1_EPDR: EPD12 Mask                 */
#define EPORT1_EPDR_EPD12_SHIFT                  (4U)                                                /*!< EPORT1_EPDR: EPD12 Position             */
#define EPORT1_EPDR_EPD12(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDR_EPD12_SHIFT))&EPORT1_EPDR_EPD12_MASK) /*!< EPORT1_EPDR                             */
#define EPORT1_EPDR_EPD13_MASK                   (0x20U)                                             /*!< EPORT1_EPDR: EPD13 Mask                 */
#define EPORT1_EPDR_EPD13_SHIFT                  (5U)                                                /*!< EPORT1_EPDR: EPD13 Position             */
#define EPORT1_EPDR_EPD13(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDR_EPD13_SHIFT))&EPORT1_EPDR_EPD13_MASK) /*!< EPORT1_EPDR                             */
#define EPORT1_EPDR_EPD14_MASK                   (0x40U)                                             /*!< EPORT1_EPDR: EPD14 Mask                 */
#define EPORT1_EPDR_EPD14_SHIFT                  (6U)                                                /*!< EPORT1_EPDR: EPD14 Position             */
#define EPORT1_EPDR_EPD14(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDR_EPD14_SHIFT))&EPORT1_EPDR_EPD14_MASK) /*!< EPORT1_EPDR                             */
#define EPORT1_EPDR_EPD15_MASK                   (0x80U)                                             /*!< EPORT1_EPDR: EPD15 Mask                 */
#define EPORT1_EPDR_EPD15_SHIFT                  (7U)                                                /*!< EPORT1_EPDR: EPD15 Position             */
#define EPORT1_EPDR_EPD15(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPDR_EPD15_SHIFT))&EPORT1_EPDR_EPD15_MASK) /*!< EPORT1_EPDR                             */
/* ------- EPPDR Bit Fields                         ------ */
#define EPORT1_EPPDR_EPPD8_MASK                  (0x1U)                                              /*!< EPORT1_EPPDR: EPPD8 Mask                */
#define EPORT1_EPPDR_EPPD8_SHIFT                 (0U)                                                /*!< EPORT1_EPPDR: EPPD8 Position            */
#define EPORT1_EPPDR_EPPD8(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT1_EPPDR_EPPD8_SHIFT))&EPORT1_EPPDR_EPPD8_MASK) /*!< EPORT1_EPPDR                            */
#define EPORT1_EPPDR_EPPD9_MASK                  (0x2U)                                              /*!< EPORT1_EPPDR: EPPD9 Mask                */
#define EPORT1_EPPDR_EPPD9_SHIFT                 (1U)                                                /*!< EPORT1_EPPDR: EPPD9 Position            */
#define EPORT1_EPPDR_EPPD9(x)                    (((uint8_t)(((uint8_t)(x))<<EPORT1_EPPDR_EPPD9_SHIFT))&EPORT1_EPPDR_EPPD9_MASK) /*!< EPORT1_EPPDR                            */
#define EPORT1_EPPDR_EPPD10_MASK                 (0x4U)                                              /*!< EPORT1_EPPDR: EPPD10 Mask               */
#define EPORT1_EPPDR_EPPD10_SHIFT                (2U)                                                /*!< EPORT1_EPPDR: EPPD10 Position           */
#define EPORT1_EPPDR_EPPD10(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPPDR_EPPD10_SHIFT))&EPORT1_EPPDR_EPPD10_MASK) /*!< EPORT1_EPPDR                            */
#define EPORT1_EPPDR_EPPD11_MASK                 (0x8U)                                              /*!< EPORT1_EPPDR: EPPD11 Mask               */
#define EPORT1_EPPDR_EPPD11_SHIFT                (3U)                                                /*!< EPORT1_EPPDR: EPPD11 Position           */
#define EPORT1_EPPDR_EPPD11(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPPDR_EPPD11_SHIFT))&EPORT1_EPPDR_EPPD11_MASK) /*!< EPORT1_EPPDR                            */
#define EPORT1_EPPDR_EPPD12_MASK                 (0x10U)                                             /*!< EPORT1_EPPDR: EPPD12 Mask               */
#define EPORT1_EPPDR_EPPD12_SHIFT                (4U)                                                /*!< EPORT1_EPPDR: EPPD12 Position           */
#define EPORT1_EPPDR_EPPD12(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPPDR_EPPD12_SHIFT))&EPORT1_EPPDR_EPPD12_MASK) /*!< EPORT1_EPPDR                            */
#define EPORT1_EPPDR_EPPD13_MASK                 (0x20U)                                             /*!< EPORT1_EPPDR: EPPD13 Mask               */
#define EPORT1_EPPDR_EPPD13_SHIFT                (5U)                                                /*!< EPORT1_EPPDR: EPPD13 Position           */
#define EPORT1_EPPDR_EPPD13(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPPDR_EPPD13_SHIFT))&EPORT1_EPPDR_EPPD13_MASK) /*!< EPORT1_EPPDR                            */
#define EPORT1_EPPDR_EPPD14_MASK                 (0x40U)                                             /*!< EPORT1_EPPDR: EPPD14 Mask               */
#define EPORT1_EPPDR_EPPD14_SHIFT                (6U)                                                /*!< EPORT1_EPPDR: EPPD14 Position           */
#define EPORT1_EPPDR_EPPD14(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPPDR_EPPD14_SHIFT))&EPORT1_EPPDR_EPPD14_MASK) /*!< EPORT1_EPPDR                            */
#define EPORT1_EPPDR_EPPD15_MASK                 (0x80U)                                             /*!< EPORT1_EPPDR: EPPD15 Mask               */
#define EPORT1_EPPDR_EPPD15_SHIFT                (7U)                                                /*!< EPORT1_EPPDR: EPPD15 Position           */
#define EPORT1_EPPDR_EPPD15(x)                   (((uint8_t)(((uint8_t)(x))<<EPORT1_EPPDR_EPPD15_SHIFT))&EPORT1_EPPDR_EPPD15_MASK) /*!< EPORT1_EPPDR                            */
/* ------- EPFR Bit Fields                          ------ */
#define EPORT1_EPFR_EPF8_MASK                    (0x1U)                                              /*!< EPORT1_EPFR: EPF8 Mask                  */
#define EPORT1_EPFR_EPF8_SHIFT                   (0U)                                                /*!< EPORT1_EPFR: EPF8 Position              */
#define EPORT1_EPFR_EPF8(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT1_EPFR_EPF8_SHIFT))&EPORT1_EPFR_EPF8_MASK) /*!< EPORT1_EPFR                             */
#define EPORT1_EPFR_EPF9_MASK                    (0x2U)                                              /*!< EPORT1_EPFR: EPF9 Mask                  */
#define EPORT1_EPFR_EPF9_SHIFT                   (1U)                                                /*!< EPORT1_EPFR: EPF9 Position              */
#define EPORT1_EPFR_EPF9(x)                      (((uint8_t)(((uint8_t)(x))<<EPORT1_EPFR_EPF9_SHIFT))&EPORT1_EPFR_EPF9_MASK) /*!< EPORT1_EPFR                             */
#define EPORT1_EPFR_EPF10_MASK                   (0x4U)                                              /*!< EPORT1_EPFR: EPF10 Mask                 */
#define EPORT1_EPFR_EPF10_SHIFT                  (2U)                                                /*!< EPORT1_EPFR: EPF10 Position             */
#define EPORT1_EPFR_EPF10(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPFR_EPF10_SHIFT))&EPORT1_EPFR_EPF10_MASK) /*!< EPORT1_EPFR                             */
#define EPORT1_EPFR_EPF11_MASK                   (0x8U)                                              /*!< EPORT1_EPFR: EPF11 Mask                 */
#define EPORT1_EPFR_EPF11_SHIFT                  (3U)                                                /*!< EPORT1_EPFR: EPF11 Position             */
#define EPORT1_EPFR_EPF11(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPFR_EPF11_SHIFT))&EPORT1_EPFR_EPF11_MASK) /*!< EPORT1_EPFR                             */
#define EPORT1_EPFR_EPF12_MASK                   (0x10U)                                             /*!< EPORT1_EPFR: EPF12 Mask                 */
#define EPORT1_EPFR_EPF12_SHIFT                  (4U)                                                /*!< EPORT1_EPFR: EPF12 Position             */
#define EPORT1_EPFR_EPF12(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPFR_EPF12_SHIFT))&EPORT1_EPFR_EPF12_MASK) /*!< EPORT1_EPFR                             */
#define EPORT1_EPFR_EPF13_MASK                   (0x20U)                                             /*!< EPORT1_EPFR: EPF13 Mask                 */
#define EPORT1_EPFR_EPF13_SHIFT                  (5U)                                                /*!< EPORT1_EPFR: EPF13 Position             */
#define EPORT1_EPFR_EPF13(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPFR_EPF13_SHIFT))&EPORT1_EPFR_EPF13_MASK) /*!< EPORT1_EPFR                             */
#define EPORT1_EPFR_EPF14_MASK                   (0x40U)                                             /*!< EPORT1_EPFR: EPF14 Mask                 */
#define EPORT1_EPFR_EPF14_SHIFT                  (6U)                                                /*!< EPORT1_EPFR: EPF14 Position             */
#define EPORT1_EPFR_EPF14(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPFR_EPF14_SHIFT))&EPORT1_EPFR_EPF14_MASK) /*!< EPORT1_EPFR                             */
#define EPORT1_EPFR_EPF15_MASK                   (0x80U)                                             /*!< EPORT1_EPFR: EPF15 Mask                 */
#define EPORT1_EPFR_EPF15_SHIFT                  (7U)                                                /*!< EPORT1_EPFR: EPF15 Position             */
#define EPORT1_EPFR_EPF15(x)                     (((uint8_t)(((uint8_t)(x))<<EPORT1_EPFR_EPF15_SHIFT))&EPORT1_EPFR_EPF15_MASK) /*!< EPORT1_EPFR                             */
/**
 * @} */ /* End group EPORT_Register_Masks_GROUP 
 */

/* EPORT1 - Peripheral instance base addresses */
#define EPORT1_BasePtr                 0x40140000UL //!< Peripheral base address
#define EPORT1                         ((EPORT1_Type *) EPORT1_BasePtr) //!< Freescale base pointer
#define EPORT1_BASE_PTR                (EPORT1) //!< Freescale style base pointer
/**
 * @} */ /* End group EPORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FEC_Peripheral_access_layer_GROUP FEC Peripheral Access Layer
* @brief C Struct for FEC
* @{
*/

/* ================================================================================ */
/* ================           FEC (file:MCF522xx_FEC)              ================ */
/* ================================================================================ */

/**
 * @brief None
 */
/**
* @addtogroup FEC_structs_GROUP FEC struct
* @brief Struct for FEC
* @{
*/
typedef struct {                                /*       FEC Structure                                                */
   __IO uint32_t  EIR;                          /**< 0000: None                                                         */
   __IO uint32_t  EIMR;                         /**< 0004: None                                                         */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  RDAR;                         /**< 000C: None                                                         */
   __IO uint32_t  TDAR;                         /**< 0010: None                                                         */
        uint8_t   RESERVED_1[12];              
   __IO uint32_t  ECR;                          /**< 0020: None                                                         */
        uint8_t   RESERVED_2[24];              
   __IO uint32_t  MMFR;                         /**< 003C: None                                                         */
   __IO uint32_t  MSCR;                         /**< 0040: None                                                         */
        uint8_t   RESERVED_3[28];              
   __IO uint32_t  MIBC;                         /**< 0060: None                                                         */
        uint8_t   RESERVED_4[28];              
   __IO uint32_t  RCR;                          /**< 0080: None                                                         */
        uint8_t   RESERVED_5[60];              
   __IO uint32_t  TCR;                          /**< 00C0: None                                                         */
        uint8_t   RESERVED_6[28];              
   __IO uint32_t  PALR;                         /**< 00E0: None                                                         */
   __IO uint32_t  PAUR;                         /**< 00E4: None                                                         */
   __IO uint32_t  OPD;                          /**< 00E8: None                                                         */
        uint8_t   RESERVED_7[40];              
   __IO uint32_t  IAUR;                         /**< 0114: None                                                         */
   __IO uint32_t  IALR;                         /**< 0118: None                                                         */
   __IO uint32_t  GAUR;                         /**< 011C: None                                                         */
   __IO uint32_t  GALR;                         /**< 0120: None                                                         */
        uint8_t   RESERVED_8[28];              
   __IO uint32_t  TFWR;                         /**< 0140: None                                                         */
        uint8_t   RESERVED_9[4];               
   __IO uint32_t  FRBR;                         /**< 0148: None                                                         */
   __IO uint32_t  FRSR;                         /**< 014C: None                                                         */
        uint8_t   RESERVED_10[44];             
   __IO uint32_t  ERDSR;                        /**< 017C: None                                                         */
   __IO uint32_t  ETSDR;                        /**< 0180: None                                                         */
   __IO uint32_t  EMRBR;                        /**< 0184: None                                                         */
        uint8_t   RESERVED_11[116];            
   __IO uint32_t  RMON_T_DROP;                  /**< 01FC: None                                                         */
   __IO uint32_t  RMON_T_PACKETS;               /**< 0200: None                                                         */
   __IO uint32_t  RMON_T_BC_PKT;                /**< 0204: None                                                         */
   __IO uint32_t  RMON_T_MC_PKT;                /**< 0208: None                                                         */
   __IO uint32_t  RMON_T_CRC_ALIGN;             /**< 020C: None                                                         */
   __IO uint32_t  RMON_T_UNDERSIZE;             /**< 0210: None                                                         */
   __IO uint32_t  RMON_T_OVERSIZE;              /**< 0214: None                                                         */
   __IO uint32_t  RMON_T_FRAG;                  /**< 0218: None                                                         */
   __IO uint32_t  RMON_T_JAB;                   /**< 021C: None                                                         */
   __IO uint32_t  RMON_T_COL;                   /**< 0220: None                                                         */
   __IO uint32_t  RMON_T_P64;                   /**< 0224: None                                                         */
   __IO uint32_t  RMON_T_P65TO127;              /**< 0228: None                                                         */
   __IO uint32_t  RMON_T_P128TO255;             /**< 022C: None                                                         */
   __IO uint32_t  RMON_T_P256TO511;             /**< 0230: None                                                         */
   __IO uint32_t  RMON_T_P512TO1023;            /**< 0234: None                                                         */
   __IO uint32_t  RMON_T_P1024TO2047;           /**< 0238: None                                                         */
   __IO uint32_t  RMON_T_P_GTE2048;             /**< 023C: None                                                         */
   __IO uint32_t  RMON_T_OCTETS;                /**< 0240: None                                                         */
   __IO uint32_t  IEEE_T_DROP;                  /**< 0244: None                                                         */
   __IO uint32_t  IEEE_T_FRAME_OK;              /**< 0248: None                                                         */
   __IO uint32_t  IEEE_T_1COL;                  /**< 024C: None                                                         */
   __IO uint32_t  IEEE_T_MCOL;                  /**< 0250: None                                                         */
   __IO uint32_t  IEEE_T_DEF;                   /**< 0254: None                                                         */
   __IO uint32_t  IEEE_T_LCOL;                  /**< 0258: None                                                         */
   __IO uint32_t  IEEE_T_EXCOL;                 /**< 025C: None                                                         */
   __IO uint32_t  IEEE_T_MACERR;                /**< 0260: None                                                         */
   __IO uint32_t  IEEE_T_CSERR;                 /**< 0264: None                                                         */
   __IO uint32_t  IEEE_T_SQE;                   /**< 0268: None                                                         */
   __IO uint32_t  IEEE_T_FDXFC;                 /**< 026C: None                                                         */
   __IO uint32_t  IEEE_T_OCTETS_OK;             /**< 0270: None                                                         */
        uint8_t   RESERVED_12[8];              
   __IO uint32_t  RMON_R_DROP;                  /**< 027C: None                                                         */
   __IO uint32_t  RMON_R_PACKETS;               /**< 0280: None                                                         */
   __IO uint32_t  RMON_R_BC_PKT;                /**< 0284: None                                                         */
   __IO uint32_t  RMON_R_MC_PKT;                /**< 0288: None                                                         */
   __IO uint32_t  RMON_R_CRC_ALIGN;             /**< 028C: None                                                         */
   __IO uint32_t  RMON_R_UNDERSIZE;             /**< 0290: None                                                         */
   __IO uint32_t  RMON_R_OVERSIZE;              /**< 0294: None                                                         */
   __IO uint32_t  RMON_R_FRAG;                  /**< 0298: None                                                         */
   __IO uint32_t  RMON_R_JAB;                   /**< 029C: None                                                         */
   __IO uint32_t  RMON_R_RESVD_0;               /**< 02A0: None                                                         */
   __IO uint32_t  RMON_R_P64;                   /**< 02A4: None                                                         */
   __IO uint32_t  RMON_R_P65TO127;              /**< 02A8: None                                                         */
   __IO uint32_t  RMON_R_P128TO255;             /**< 02AC: None                                                         */
   __IO uint32_t  RMON_R_P256TO511;             /**< 02B0: None                                                         */
   __IO uint32_t  RMON_R_P512TO1023;            /**< 02B4: None                                                         */
   __IO uint32_t  RMON_R_P1024TO2047;           /**< 02B8: None                                                         */
   __IO uint32_t  RMON_R_P_GTE2048;             /**< 02BC: None                                                         */
   __IO uint32_t  RMON_R_OCTETS;                /**< 02C0: None                                                         */
   __IO uint32_t  IEEE_R_DROP;                  /**< 02C4: None                                                         */
   __IO uint32_t  IEEE_R_FRAME_OK;              /**< 02C8: None                                                         */
   __IO uint32_t  IEEE_R_CRC;                   /**< 02CC: None                                                         */
   __IO uint32_t  IEEE_R_ALIGN;                 /**< 02D0: None                                                         */
   __IO uint32_t  IEEE_R_MACERR;                /**< 02D4: None                                                         */
   __IO uint32_t  IEEE_R_FDXFC;                 /**< 02D8: None                                                         */
   __IO uint32_t  IEEE_R_OCTETS_OK;             /**< 02DC: None                                                         */
} FEC_Type;

/**
 * @} */ /* End group FEC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FEC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FEC_Register_Masks_GROUP FEC Register Masks
* @brief Register Masks for FEC
* @{
*/
/* ------- EIR Bit Fields                           ------ */
#define FEC_EIR_UN_MASK                          (0x80000U)                                          /*!< FEC_EIR: UN Mask                        */
#define FEC_EIR_UN_SHIFT                         (19U)                                               /*!< FEC_EIR: UN Position                    */
#define FEC_EIR_UN(x)                            (((uint32_t)(((uint32_t)(x))<<FEC_EIR_UN_SHIFT))&FEC_EIR_UN_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_RL_MASK                          (0x100000U)                                         /*!< FEC_EIR: RL Mask                        */
#define FEC_EIR_RL_SHIFT                         (20U)                                               /*!< FEC_EIR: RL Position                    */
#define FEC_EIR_RL(x)                            (((uint32_t)(((uint32_t)(x))<<FEC_EIR_RL_SHIFT))&FEC_EIR_RL_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_LC_MASK                          (0x200000U)                                         /*!< FEC_EIR: LC Mask                        */
#define FEC_EIR_LC_SHIFT                         (21U)                                               /*!< FEC_EIR: LC Position                    */
#define FEC_EIR_LC(x)                            (((uint32_t)(((uint32_t)(x))<<FEC_EIR_LC_SHIFT))&FEC_EIR_LC_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_EBERR_MASK                       (0x400000U)                                         /*!< FEC_EIR: EBERR Mask                     */
#define FEC_EIR_EBERR_SHIFT                      (22U)                                               /*!< FEC_EIR: EBERR Position                 */
#define FEC_EIR_EBERR(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_EIR_EBERR_SHIFT))&FEC_EIR_EBERR_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_MII_MASK                         (0x800000U)                                         /*!< FEC_EIR: MII Mask                       */
#define FEC_EIR_MII_SHIFT                        (23U)                                               /*!< FEC_EIR: MII Position                   */
#define FEC_EIR_MII(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_MII_SHIFT))&FEC_EIR_MII_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_RXB_MASK                         (0x1000000U)                                        /*!< FEC_EIR: RXB Mask                       */
#define FEC_EIR_RXB_SHIFT                        (24U)                                               /*!< FEC_EIR: RXB Position                   */
#define FEC_EIR_RXB(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_RXB_SHIFT))&FEC_EIR_RXB_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_RXF_MASK                         (0x2000000U)                                        /*!< FEC_EIR: RXF Mask                       */
#define FEC_EIR_RXF_SHIFT                        (25U)                                               /*!< FEC_EIR: RXF Position                   */
#define FEC_EIR_RXF(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_RXF_SHIFT))&FEC_EIR_RXF_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_TXB_MASK                         (0x4000000U)                                        /*!< FEC_EIR: TXB Mask                       */
#define FEC_EIR_TXB_SHIFT                        (26U)                                               /*!< FEC_EIR: TXB Position                   */
#define FEC_EIR_TXB(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_TXB_SHIFT))&FEC_EIR_TXB_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_TXF_MASK                         (0x8000000U)                                        /*!< FEC_EIR: TXF Mask                       */
#define FEC_EIR_TXF_SHIFT                        (27U)                                               /*!< FEC_EIR: TXF Position                   */
#define FEC_EIR_TXF(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_TXF_SHIFT))&FEC_EIR_TXF_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_GRA_MASK                         (0x10000000U)                                       /*!< FEC_EIR: GRA Mask                       */
#define FEC_EIR_GRA_SHIFT                        (28U)                                               /*!< FEC_EIR: GRA Position                   */
#define FEC_EIR_GRA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIR_GRA_SHIFT))&FEC_EIR_GRA_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_BABT_MASK                        (0x20000000U)                                       /*!< FEC_EIR: BABT Mask                      */
#define FEC_EIR_BABT_SHIFT                       (29U)                                               /*!< FEC_EIR: BABT Position                  */
#define FEC_EIR_BABT(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIR_BABT_SHIFT))&FEC_EIR_BABT_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_BABR_MASK                        (0x40000000U)                                       /*!< FEC_EIR: BABR Mask                      */
#define FEC_EIR_BABR_SHIFT                       (30U)                                               /*!< FEC_EIR: BABR Position                  */
#define FEC_EIR_BABR(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIR_BABR_SHIFT))&FEC_EIR_BABR_MASK) /*!< FEC_EIR                                 */
#define FEC_EIR_HBERR_MASK                       (0x80000000U)                                       /*!< FEC_EIR: HBERR Mask                     */
#define FEC_EIR_HBERR_SHIFT                      (31U)                                               /*!< FEC_EIR: HBERR Position                 */
#define FEC_EIR_HBERR(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_EIR_HBERR_SHIFT))&FEC_EIR_HBERR_MASK) /*!< FEC_EIR                                 */
/* ------- EIMR Bit Fields                          ------ */
#define FEC_EIMR_UN_MASK                         (0x80000U)                                          /*!< FEC_EIMR: UN Mask                       */
#define FEC_EIMR_UN_SHIFT                        (19U)                                               /*!< FEC_EIMR: UN Position                   */
#define FEC_EIMR_UN(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_UN_SHIFT))&FEC_EIMR_UN_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_RL_MASK                         (0x100000U)                                         /*!< FEC_EIMR: RL Mask                       */
#define FEC_EIMR_RL_SHIFT                        (20U)                                               /*!< FEC_EIMR: RL Position                   */
#define FEC_EIMR_RL(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_RL_SHIFT))&FEC_EIMR_RL_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_LC_MASK                         (0x200000U)                                         /*!< FEC_EIMR: LC Mask                       */
#define FEC_EIMR_LC_SHIFT                        (21U)                                               /*!< FEC_EIMR: LC Position                   */
#define FEC_EIMR_LC(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_LC_SHIFT))&FEC_EIMR_LC_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_EBERR_MASK                      (0x400000U)                                         /*!< FEC_EIMR: EBERR Mask                    */
#define FEC_EIMR_EBERR_SHIFT                     (22U)                                               /*!< FEC_EIMR: EBERR Position                */
#define FEC_EIMR_EBERR(x)                        (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_EBERR_SHIFT))&FEC_EIMR_EBERR_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_MII_MASK                        (0x800000U)                                         /*!< FEC_EIMR: MII Mask                      */
#define FEC_EIMR_MII_SHIFT                       (23U)                                               /*!< FEC_EIMR: MII Position                  */
#define FEC_EIMR_MII(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_MII_SHIFT))&FEC_EIMR_MII_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_RXB_MASK                        (0x1000000U)                                        /*!< FEC_EIMR: RXB Mask                      */
#define FEC_EIMR_RXB_SHIFT                       (24U)                                               /*!< FEC_EIMR: RXB Position                  */
#define FEC_EIMR_RXB(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_RXB_SHIFT))&FEC_EIMR_RXB_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_RXF_MASK                        (0x2000000U)                                        /*!< FEC_EIMR: RXF Mask                      */
#define FEC_EIMR_RXF_SHIFT                       (25U)                                               /*!< FEC_EIMR: RXF Position                  */
#define FEC_EIMR_RXF(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_RXF_SHIFT))&FEC_EIMR_RXF_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_TXB_MASK                        (0x4000000U)                                        /*!< FEC_EIMR: TXB Mask                      */
#define FEC_EIMR_TXB_SHIFT                       (26U)                                               /*!< FEC_EIMR: TXB Position                  */
#define FEC_EIMR_TXB(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_TXB_SHIFT))&FEC_EIMR_TXB_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_TXF_MASK                        (0x8000000U)                                        /*!< FEC_EIMR: TXF Mask                      */
#define FEC_EIMR_TXF_SHIFT                       (27U)                                               /*!< FEC_EIMR: TXF Position                  */
#define FEC_EIMR_TXF(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_TXF_SHIFT))&FEC_EIMR_TXF_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_GRA_MASK                        (0x10000000U)                                       /*!< FEC_EIMR: GRA Mask                      */
#define FEC_EIMR_GRA_SHIFT                       (28U)                                               /*!< FEC_EIMR: GRA Position                  */
#define FEC_EIMR_GRA(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_GRA_SHIFT))&FEC_EIMR_GRA_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_BABT_MASK                       (0x20000000U)                                       /*!< FEC_EIMR: BABT Mask                     */
#define FEC_EIMR_BABT_SHIFT                      (29U)                                               /*!< FEC_EIMR: BABT Position                 */
#define FEC_EIMR_BABT(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_BABT_SHIFT))&FEC_EIMR_BABT_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_BABR_MASK                       (0x40000000U)                                       /*!< FEC_EIMR: BABR Mask                     */
#define FEC_EIMR_BABR_SHIFT                      (30U)                                               /*!< FEC_EIMR: BABR Position                 */
#define FEC_EIMR_BABR(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_BABR_SHIFT))&FEC_EIMR_BABR_MASK) /*!< FEC_EIMR                                */
#define FEC_EIMR_HBERR_MASK                      (0x80000000U)                                       /*!< FEC_EIMR: HBERR Mask                    */
#define FEC_EIMR_HBERR_SHIFT                     (31U)                                               /*!< FEC_EIMR: HBERR Position                */
#define FEC_EIMR_HBERR(x)                        (((uint32_t)(((uint32_t)(x))<<FEC_EIMR_HBERR_SHIFT))&FEC_EIMR_HBERR_MASK) /*!< FEC_EIMR                                */
/* ------- RDAR Bit Fields                          ------ */
#define FEC_RDAR_R_DES_ACTIVE_MASK               (0x1000000U)                                        /*!< FEC_RDAR: R_DES_ACTIVE Mask             */
#define FEC_RDAR_R_DES_ACTIVE_SHIFT              (24U)                                               /*!< FEC_RDAR: R_DES_ACTIVE Position         */
#define FEC_RDAR_R_DES_ACTIVE(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RDAR_R_DES_ACTIVE_SHIFT))&FEC_RDAR_R_DES_ACTIVE_MASK) /*!< FEC_RDAR                                */
/* ------- TDAR Bit Fields                          ------ */
#define FEC_TDAR_X_DES_ACTIVE_MASK               (0x1000000U)                                        /*!< FEC_TDAR: X_DES_ACTIVE Mask             */
#define FEC_TDAR_X_DES_ACTIVE_SHIFT              (24U)                                               /*!< FEC_TDAR: X_DES_ACTIVE Position         */
#define FEC_TDAR_X_DES_ACTIVE(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_TDAR_X_DES_ACTIVE_SHIFT))&FEC_TDAR_X_DES_ACTIVE_MASK) /*!< FEC_TDAR                                */
/* ------- ECR Bit Fields                           ------ */
#define FEC_ECR_RESET_MASK                       (0x1U)                                              /*!< FEC_ECR: RESET Mask                     */
#define FEC_ECR_RESET_SHIFT                      (0U)                                                /*!< FEC_ECR: RESET Position                 */
#define FEC_ECR_RESET(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_ECR_RESET_SHIFT))&FEC_ECR_RESET_MASK) /*!< FEC_ECR                                 */
#define FEC_ECR_ETHER_EN_MASK                    (0x2U)                                              /*!< FEC_ECR: ETHER_EN Mask                  */
#define FEC_ECR_ETHER_EN_SHIFT                   (1U)                                                /*!< FEC_ECR: ETHER_EN Position              */
#define FEC_ECR_ETHER_EN(x)                      (((uint32_t)(((uint32_t)(x))<<FEC_ECR_ETHER_EN_SHIFT))&FEC_ECR_ETHER_EN_MASK) /*!< FEC_ECR                                 */
/* ------- MMFR Bit Fields                          ------ */
#define FEC_MMFR_DATA_MASK                       (0xFFFFU)                                           /*!< FEC_MMFR: DATA Mask                     */
#define FEC_MMFR_DATA_SHIFT                      (0U)                                                /*!< FEC_MMFR: DATA Position                 */
#define FEC_MMFR_DATA(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_DATA_SHIFT))&FEC_MMFR_DATA_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_TA_MASK                         (0x30000U)                                          /*!< FEC_MMFR: TA Mask                       */
#define FEC_MMFR_TA_SHIFT                        (16U)                                               /*!< FEC_MMFR: TA Position                   */
#define FEC_MMFR_TA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_TA_SHIFT))&FEC_MMFR_TA_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_RA_MASK                         (0x7C0000U)                                         /*!< FEC_MMFR: RA Mask                       */
#define FEC_MMFR_RA_SHIFT                        (18U)                                               /*!< FEC_MMFR: RA Position                   */
#define FEC_MMFR_RA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_RA_SHIFT))&FEC_MMFR_RA_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_PA_MASK                         (0xF800000U)                                        /*!< FEC_MMFR: PA Mask                       */
#define FEC_MMFR_PA_SHIFT                        (23U)                                               /*!< FEC_MMFR: PA Position                   */
#define FEC_MMFR_PA(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_PA_SHIFT))&FEC_MMFR_PA_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_OP_MASK                         (0x30000000U)                                       /*!< FEC_MMFR: OP Mask                       */
#define FEC_MMFR_OP_SHIFT                        (28U)                                               /*!< FEC_MMFR: OP Position                   */
#define FEC_MMFR_OP(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_OP_SHIFT))&FEC_MMFR_OP_MASK) /*!< FEC_MMFR                                */
#define FEC_MMFR_ST_MASK                         (0xC0000000U)                                       /*!< FEC_MMFR: ST Mask                       */
#define FEC_MMFR_ST_SHIFT                        (30U)                                               /*!< FEC_MMFR: ST Position                   */
#define FEC_MMFR_ST(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_MMFR_ST_SHIFT))&FEC_MMFR_ST_MASK) /*!< FEC_MMFR                                */
/* ------- MSCR Bit Fields                          ------ */
#define FEC_MSCR_MII_SPEED_MASK                  (0x7EU)                                             /*!< FEC_MSCR: MII_SPEED Mask                */
#define FEC_MSCR_MII_SPEED_SHIFT                 (1U)                                                /*!< FEC_MSCR: MII_SPEED Position            */
#define FEC_MSCR_MII_SPEED(x)                    (((uint32_t)(((uint32_t)(x))<<FEC_MSCR_MII_SPEED_SHIFT))&FEC_MSCR_MII_SPEED_MASK) /*!< FEC_MSCR                                */
#define FEC_MSCR_DIS_PREAMBLE_MASK               (0x80U)                                             /*!< FEC_MSCR: DIS_PREAMBLE Mask             */
#define FEC_MSCR_DIS_PREAMBLE_SHIFT              (7U)                                                /*!< FEC_MSCR: DIS_PREAMBLE Position         */
#define FEC_MSCR_DIS_PREAMBLE(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_MSCR_DIS_PREAMBLE_SHIFT))&FEC_MSCR_DIS_PREAMBLE_MASK) /*!< FEC_MSCR                                */
/* ------- MIBC Bit Fields                          ------ */
#define FEC_MIBC_MIB_IDLE_MASK                   (0x40000000U)                                       /*!< FEC_MIBC: MIB_IDLE Mask                 */
#define FEC_MIBC_MIB_IDLE_SHIFT                  (30U)                                               /*!< FEC_MIBC: MIB_IDLE Position             */
#define FEC_MIBC_MIB_IDLE(x)                     (((uint32_t)(((uint32_t)(x))<<FEC_MIBC_MIB_IDLE_SHIFT))&FEC_MIBC_MIB_IDLE_MASK) /*!< FEC_MIBC                                */
#define FEC_MIBC_MIB_DISABLE_MASK                (0x80000000U)                                       /*!< FEC_MIBC: MIB_DISABLE Mask              */
#define FEC_MIBC_MIB_DISABLE_SHIFT               (31U)                                               /*!< FEC_MIBC: MIB_DISABLE Position          */
#define FEC_MIBC_MIB_DISABLE(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_MIBC_MIB_DISABLE_SHIFT))&FEC_MIBC_MIB_DISABLE_MASK) /*!< FEC_MIBC                                */
/* ------- RCR Bit Fields                           ------ */
#define FEC_RCR_LOOP_MASK                        (0x1U)                                              /*!< FEC_RCR: LOOP Mask                      */
#define FEC_RCR_LOOP_SHIFT                       (0U)                                                /*!< FEC_RCR: LOOP Position                  */
#define FEC_RCR_LOOP(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_RCR_LOOP_SHIFT))&FEC_RCR_LOOP_MASK) /*!< FEC_RCR                                 */
#define FEC_RCR_DRT_MASK                         (0x2U)                                              /*!< FEC_RCR: DRT Mask                       */
#define FEC_RCR_DRT_SHIFT                        (1U)                                                /*!< FEC_RCR: DRT Position                   */
#define FEC_RCR_DRT(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_RCR_DRT_SHIFT))&FEC_RCR_DRT_MASK) /*!< FEC_RCR                                 */
#define FEC_RCR_MII_MODE_MASK                    (0x4U)                                              /*!< FEC_RCR: MII_MODE Mask                  */
#define FEC_RCR_MII_MODE_SHIFT                   (2U)                                                /*!< FEC_RCR: MII_MODE Position              */
#define FEC_RCR_MII_MODE(x)                      (((uint32_t)(((uint32_t)(x))<<FEC_RCR_MII_MODE_SHIFT))&FEC_RCR_MII_MODE_MASK) /*!< FEC_RCR                                 */
#define FEC_RCR_PROM_MASK                        (0x8U)                                              /*!< FEC_RCR: PROM Mask                      */
#define FEC_RCR_PROM_SHIFT                       (3U)                                                /*!< FEC_RCR: PROM Position                  */
#define FEC_RCR_PROM(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_RCR_PROM_SHIFT))&FEC_RCR_PROM_MASK) /*!< FEC_RCR                                 */
#define FEC_RCR_BC_REJ_MASK                      (0x10U)                                             /*!< FEC_RCR: BC_REJ Mask                    */
#define FEC_RCR_BC_REJ_SHIFT                     (4U)                                                /*!< FEC_RCR: BC_REJ Position                */
#define FEC_RCR_BC_REJ(x)                        (((uint32_t)(((uint32_t)(x))<<FEC_RCR_BC_REJ_SHIFT))&FEC_RCR_BC_REJ_MASK) /*!< FEC_RCR                                 */
#define FEC_RCR_FCE_MASK                         (0x20U)                                             /*!< FEC_RCR: FCE Mask                       */
#define FEC_RCR_FCE_SHIFT                        (5U)                                                /*!< FEC_RCR: FCE Position                   */
#define FEC_RCR_FCE(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_RCR_FCE_SHIFT))&FEC_RCR_FCE_MASK) /*!< FEC_RCR                                 */
#define FEC_RCR_MAX_FL_MASK                      (0x7FF0000U)                                        /*!< FEC_RCR: MAX_FL Mask                    */
#define FEC_RCR_MAX_FL_SHIFT                     (16U)                                               /*!< FEC_RCR: MAX_FL Position                */
#define FEC_RCR_MAX_FL(x)                        (((uint32_t)(((uint32_t)(x))<<FEC_RCR_MAX_FL_SHIFT))&FEC_RCR_MAX_FL_MASK) /*!< FEC_RCR                                 */
/* ------- TCR Bit Fields                           ------ */
#define FEC_TCR_GTS_MASK                         (0x1U)                                              /*!< FEC_TCR: GTS Mask                       */
#define FEC_TCR_GTS_SHIFT                        (0U)                                                /*!< FEC_TCR: GTS Position                   */
#define FEC_TCR_GTS(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_TCR_GTS_SHIFT))&FEC_TCR_GTS_MASK) /*!< FEC_TCR                                 */
#define FEC_TCR_HBC_MASK                         (0x2U)                                              /*!< FEC_TCR: HBC Mask                       */
#define FEC_TCR_HBC_SHIFT                        (1U)                                                /*!< FEC_TCR: HBC Position                   */
#define FEC_TCR_HBC(x)                           (((uint32_t)(((uint32_t)(x))<<FEC_TCR_HBC_SHIFT))&FEC_TCR_HBC_MASK) /*!< FEC_TCR                                 */
#define FEC_TCR_FDEN_MASK                        (0x4U)                                              /*!< FEC_TCR: FDEN Mask                      */
#define FEC_TCR_FDEN_SHIFT                       (2U)                                                /*!< FEC_TCR: FDEN Position                  */
#define FEC_TCR_FDEN(x)                          (((uint32_t)(((uint32_t)(x))<<FEC_TCR_FDEN_SHIFT))&FEC_TCR_FDEN_MASK) /*!< FEC_TCR                                 */
#define FEC_TCR_TFC_PAUSE_MASK                   (0x8U)                                              /*!< FEC_TCR: TFC_PAUSE Mask                 */
#define FEC_TCR_TFC_PAUSE_SHIFT                  (3U)                                                /*!< FEC_TCR: TFC_PAUSE Position             */
#define FEC_TCR_TFC_PAUSE(x)                     (((uint32_t)(((uint32_t)(x))<<FEC_TCR_TFC_PAUSE_SHIFT))&FEC_TCR_TFC_PAUSE_MASK) /*!< FEC_TCR                                 */
#define FEC_TCR_RFC_PAUSE_MASK                   (0x10U)                                             /*!< FEC_TCR: RFC_PAUSE Mask                 */
#define FEC_TCR_RFC_PAUSE_SHIFT                  (4U)                                                /*!< FEC_TCR: RFC_PAUSE Position             */
#define FEC_TCR_RFC_PAUSE(x)                     (((uint32_t)(((uint32_t)(x))<<FEC_TCR_RFC_PAUSE_SHIFT))&FEC_TCR_RFC_PAUSE_MASK) /*!< FEC_TCR                                 */
/* ------- PALR Bit Fields                          ------ */
#define FEC_PALR_PADDR1_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_PALR: PADDR1 Mask                   */
#define FEC_PALR_PADDR1_SHIFT                    (0U)                                                /*!< FEC_PALR: PADDR1 Position               */
#define FEC_PALR_PADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_PALR_PADDR1_SHIFT))&FEC_PALR_PADDR1_MASK) /*!< FEC_PALR                                */
/* ------- PAUR Bit Fields                          ------ */
#define FEC_PAUR_TYPE_MASK                       (0xFFFFU)                                           /*!< FEC_PAUR: TYPE Mask                     */
#define FEC_PAUR_TYPE_SHIFT                      (0U)                                                /*!< FEC_PAUR: TYPE Position                 */
#define FEC_PAUR_TYPE(x)                         (((uint32_t)(((uint32_t)(x))<<FEC_PAUR_TYPE_SHIFT))&FEC_PAUR_TYPE_MASK) /*!< FEC_PAUR                                */
#define FEC_PAUR_PADDR2_MASK                     (0xFFFF0000U)                                       /*!< FEC_PAUR: PADDR2 Mask                   */
#define FEC_PAUR_PADDR2_SHIFT                    (16U)                                               /*!< FEC_PAUR: PADDR2 Position               */
#define FEC_PAUR_PADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_PAUR_PADDR2_SHIFT))&FEC_PAUR_PADDR2_MASK) /*!< FEC_PAUR                                */
/* ------- OPD Bit Fields                           ------ */
#define FEC_OPD_PAUSE_DUR_MASK                   (0xFFFFU)                                           /*!< FEC_OPD: PAUSE_DUR Mask                 */
#define FEC_OPD_PAUSE_DUR_SHIFT                  (0U)                                                /*!< FEC_OPD: PAUSE_DUR Position             */
#define FEC_OPD_PAUSE_DUR(x)                     (((uint32_t)(((uint32_t)(x))<<FEC_OPD_PAUSE_DUR_SHIFT))&FEC_OPD_PAUSE_DUR_MASK) /*!< FEC_OPD                                 */
#define FEC_OPD_OPCODE_MASK                      (0xFFFF0000U)                                       /*!< FEC_OPD: OPCODE Mask                    */
#define FEC_OPD_OPCODE_SHIFT                     (16U)                                               /*!< FEC_OPD: OPCODE Position                */
#define FEC_OPD_OPCODE(x)                        (((uint32_t)(((uint32_t)(x))<<FEC_OPD_OPCODE_SHIFT))&FEC_OPD_OPCODE_MASK) /*!< FEC_OPD                                 */
/* ------- IAUR Bit Fields                          ------ */
#define FEC_IAUR_IADDR1_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_IAUR: IADDR1 Mask                   */
#define FEC_IAUR_IADDR1_SHIFT                    (0U)                                                /*!< FEC_IAUR: IADDR1 Position               */
#define FEC_IAUR_IADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_IAUR_IADDR1_SHIFT))&FEC_IAUR_IADDR1_MASK) /*!< FEC_IAUR                                */
/* ------- IALR Bit Fields                          ------ */
#define FEC_IALR_IADDR2_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_IALR: IADDR2 Mask                   */
#define FEC_IALR_IADDR2_SHIFT                    (0U)                                                /*!< FEC_IALR: IADDR2 Position               */
#define FEC_IALR_IADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_IALR_IADDR2_SHIFT))&FEC_IALR_IADDR2_MASK) /*!< FEC_IALR                                */
/* ------- GAUR Bit Fields                          ------ */
#define FEC_GAUR_GADDR1_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_GAUR: GADDR1 Mask                   */
#define FEC_GAUR_GADDR1_SHIFT                    (0U)                                                /*!< FEC_GAUR: GADDR1 Position               */
#define FEC_GAUR_GADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_GAUR_GADDR1_SHIFT))&FEC_GAUR_GADDR1_MASK) /*!< FEC_GAUR                                */
/* ------- GALR Bit Fields                          ------ */
#define FEC_GALR_GADDR2_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_GALR: GADDR2 Mask                   */
#define FEC_GALR_GADDR2_SHIFT                    (0U)                                                /*!< FEC_GALR: GADDR2 Position               */
#define FEC_GALR_GADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_GALR_GADDR2_SHIFT))&FEC_GALR_GADDR2_MASK) /*!< FEC_GALR                                */
/* ------- TFWR Bit Fields                          ------ */
#define FEC_TFWR_X_WMRK_MASK                     (0x3U)                                              /*!< FEC_TFWR: X_WMRK Mask                   */
#define FEC_TFWR_X_WMRK_SHIFT                    (0U)                                                /*!< FEC_TFWR: X_WMRK Position               */
#define FEC_TFWR_X_WMRK(x)                       (((uint32_t)(((uint32_t)(x))<<FEC_TFWR_X_WMRK_SHIFT))&FEC_TFWR_X_WMRK_MASK) /*!< FEC_TFWR                                */
/* ------- FRBR Bit Fields                          ------ */
#define FEC_FRBR_R_BOUND_MASK                    (0x3FCU)                                            /*!< FEC_FRBR: R_BOUND Mask                  */
#define FEC_FRBR_R_BOUND_SHIFT                   (2U)                                                /*!< FEC_FRBR: R_BOUND Position              */
#define FEC_FRBR_R_BOUND(x)                      (((uint32_t)(((uint32_t)(x))<<FEC_FRBR_R_BOUND_SHIFT))&FEC_FRBR_R_BOUND_MASK) /*!< FEC_FRBR                                */
/* ------- FRSR Bit Fields                          ------ */
#define FEC_FRSR_R_FSTART_MASK                   (0x3FCU)                                            /*!< FEC_FRSR: R_FSTART Mask                 */
#define FEC_FRSR_R_FSTART_SHIFT                  (2U)                                                /*!< FEC_FRSR: R_FSTART Position             */
#define FEC_FRSR_R_FSTART(x)                     (((uint32_t)(((uint32_t)(x))<<FEC_FRSR_R_FSTART_SHIFT))&FEC_FRSR_R_FSTART_MASK) /*!< FEC_FRSR                                */
/* ------- ERDSR Bit Fields                         ------ */
#define FEC_ERDSR_R_DES_START_MASK               (0xFFFFFFFCU)                                       /*!< FEC_ERDSR: R_DES_START Mask             */
#define FEC_ERDSR_R_DES_START_SHIFT              (2U)                                                /*!< FEC_ERDSR: R_DES_START Position         */
#define FEC_ERDSR_R_DES_START(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_ERDSR_R_DES_START_SHIFT))&FEC_ERDSR_R_DES_START_MASK) /*!< FEC_ERDSR                               */
/* ------- ETSDR Bit Fields                         ------ */
#define FEC_ETSDR_X_DES_START_MASK               (0xFFFFFFFCU)                                       /*!< FEC_ETSDR: X_DES_START Mask             */
#define FEC_ETSDR_X_DES_START_SHIFT              (2U)                                                /*!< FEC_ETSDR: X_DES_START Position         */
#define FEC_ETSDR_X_DES_START(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_ETSDR_X_DES_START_SHIFT))&FEC_ETSDR_X_DES_START_MASK) /*!< FEC_ETSDR                               */
/* ------- EMRBR Bit Fields                         ------ */
#define FEC_EMRBR_R_BUF_SIZE_MASK                (0x7F0U)                                            /*!< FEC_EMRBR: R_BUF_SIZE Mask              */
#define FEC_EMRBR_R_BUF_SIZE_SHIFT               (4U)                                                /*!< FEC_EMRBR: R_BUF_SIZE Position          */
#define FEC_EMRBR_R_BUF_SIZE(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_EMRBR_R_BUF_SIZE_SHIFT))&FEC_EMRBR_R_BUF_SIZE_MASK) /*!< FEC_EMRBR                               */
/* ------- RMON_T_DROP Bit Fields                   ------ */
#define FEC_RMON_T_DROP_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_DROP: Value Mask             */
#define FEC_RMON_T_DROP_Value_SHIFT              (0U)                                                /*!< FEC_RMON_T_DROP: Value Position         */
#define FEC_RMON_T_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_DROP_Value_SHIFT))&FEC_RMON_T_DROP_Value_MASK) /*!< FEC_RMON_T_DROP                         */
/* ------- RMON_T_PACKETS Bit Fields                ------ */
#define FEC_RMON_T_PACKETS_Value_MASK            (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_PACKETS: Value Mask          */
#define FEC_RMON_T_PACKETS_Value_SHIFT           (0U)                                                /*!< FEC_RMON_T_PACKETS: Value Position      */
#define FEC_RMON_T_PACKETS_Value(x)              (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_PACKETS_Value_SHIFT))&FEC_RMON_T_PACKETS_Value_MASK) /*!< FEC_RMON_T_PACKETS                      */
/* ------- RMON_T_BC_PKT Bit Fields                 ------ */
#define FEC_RMON_T_BC_PKT_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_BC_PKT: Value Mask           */
#define FEC_RMON_T_BC_PKT_Value_SHIFT            (0U)                                                /*!< FEC_RMON_T_BC_PKT: Value Position       */
#define FEC_RMON_T_BC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_BC_PKT_Value_SHIFT))&FEC_RMON_T_BC_PKT_Value_MASK) /*!< FEC_RMON_T_BC_PKT                       */
/* ------- RMON_T_MC_PKT Bit Fields                 ------ */
#define FEC_RMON_T_MC_PKT_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_MC_PKT: Value Mask           */
#define FEC_RMON_T_MC_PKT_Value_SHIFT            (0U)                                                /*!< FEC_RMON_T_MC_PKT: Value Position       */
#define FEC_RMON_T_MC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_MC_PKT_Value_SHIFT))&FEC_RMON_T_MC_PKT_Value_MASK) /*!< FEC_RMON_T_MC_PKT                       */
/* ------- RMON_T_CRC_ALIGN Bit Fields              ------ */
#define FEC_RMON_T_CRC_ALIGN_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_CRC_ALIGN: Value Mask        */
#define FEC_RMON_T_CRC_ALIGN_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_CRC_ALIGN: Value Position    */
#define FEC_RMON_T_CRC_ALIGN_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_CRC_ALIGN_Value_SHIFT))&FEC_RMON_T_CRC_ALIGN_Value_MASK) /*!< FEC_RMON_T_CRC_ALIGN                    */
/* ------- RMON_T_UNDERSIZE Bit Fields              ------ */
#define FEC_RMON_T_UNDERSIZE_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_UNDERSIZE: Value Mask        */
#define FEC_RMON_T_UNDERSIZE_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_UNDERSIZE: Value Position    */
#define FEC_RMON_T_UNDERSIZE_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_UNDERSIZE_Value_SHIFT))&FEC_RMON_T_UNDERSIZE_Value_MASK) /*!< FEC_RMON_T_UNDERSIZE                    */
/* ------- RMON_T_OVERSIZE Bit Fields               ------ */
#define FEC_RMON_T_OVERSIZE_Value_MASK           (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_OVERSIZE: Value Mask         */
#define FEC_RMON_T_OVERSIZE_Value_SHIFT          (0U)                                                /*!< FEC_RMON_T_OVERSIZE: Value Position     */
#define FEC_RMON_T_OVERSIZE_Value(x)             (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_OVERSIZE_Value_SHIFT))&FEC_RMON_T_OVERSIZE_Value_MASK) /*!< FEC_RMON_T_OVERSIZE                     */
/* ------- RMON_T_FRAG Bit Fields                   ------ */
#define FEC_RMON_T_FRAG_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_FRAG: Value Mask             */
#define FEC_RMON_T_FRAG_Value_SHIFT              (0U)                                                /*!< FEC_RMON_T_FRAG: Value Position         */
#define FEC_RMON_T_FRAG_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_FRAG_Value_SHIFT))&FEC_RMON_T_FRAG_Value_MASK) /*!< FEC_RMON_T_FRAG                         */
/* ------- RMON_T_JAB Bit Fields                    ------ */
#define FEC_RMON_T_JAB_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_JAB: Value Mask              */
#define FEC_RMON_T_JAB_Value_SHIFT               (0U)                                                /*!< FEC_RMON_T_JAB: Value Position          */
#define FEC_RMON_T_JAB_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_JAB_Value_SHIFT))&FEC_RMON_T_JAB_Value_MASK) /*!< FEC_RMON_T_JAB                          */
/* ------- RMON_T_COL Bit Fields                    ------ */
#define FEC_RMON_T_COL_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_COL: Value Mask              */
#define FEC_RMON_T_COL_Value_SHIFT               (0U)                                                /*!< FEC_RMON_T_COL: Value Position          */
#define FEC_RMON_T_COL_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_COL_Value_SHIFT))&FEC_RMON_T_COL_Value_MASK) /*!< FEC_RMON_T_COL                          */
/* ------- RMON_T_P6 Bit Fields                     ------ */
#define FEC_RMON_T_P6_Value_MASK                 (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P6: Value Mask               */
#define FEC_RMON_T_P6_Value_SHIFT                (0U)                                                /*!< FEC_RMON_T_P6: Value Position           */
#define FEC_RMON_T_P6_Value(x)                   (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P6_Value_SHIFT))&FEC_RMON_T_P6_Value_MASK) /*!< FEC_RMON_T_P6                           */
/* ------- RMON_T_P128TO255 Bit Fields              ------ */
#define FEC_RMON_T_P128TO255_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P128TO255: Value Mask        */
#define FEC_RMON_T_P128TO255_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_P128TO255: Value Position    */
#define FEC_RMON_T_P128TO255_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P128TO255_Value_SHIFT))&FEC_RMON_T_P128TO255_Value_MASK) /*!< FEC_RMON_T_P128TO255                    */
/* ------- RMON_T_P256TO511 Bit Fields              ------ */
#define FEC_RMON_T_P256TO511_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P256TO511: Value Mask        */
#define FEC_RMON_T_P256TO511_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_P256TO511: Value Position    */
#define FEC_RMON_T_P256TO511_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P256TO511_Value_SHIFT))&FEC_RMON_T_P256TO511_Value_MASK) /*!< FEC_RMON_T_P256TO511                    */
/* ------- RMON_T_P512TO1023 Bit Fields             ------ */
#define FEC_RMON_T_P512TO1023_Value_MASK         (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P512TO1023: Value Mask       */
#define FEC_RMON_T_P512TO1023_Value_SHIFT        (0U)                                                /*!< FEC_RMON_T_P512TO1023: Value Position   */
#define FEC_RMON_T_P512TO1023_Value(x)           (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P512TO1023_Value_SHIFT))&FEC_RMON_T_P512TO1023_Value_MASK) /*!< FEC_RMON_T_P512TO1023                   */
/* ------- RMON_T_P1024TO2047 Bit Fields            ------ */
#define FEC_RMON_T_P1024TO2047_Value_MASK        (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P1024TO2047: Value Mask      */
#define FEC_RMON_T_P1024TO2047_Value_SHIFT       (0U)                                                /*!< FEC_RMON_T_P1024TO2047: Value Position  */
#define FEC_RMON_T_P1024TO2047_Value(x)          (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P1024TO2047_Value_SHIFT))&FEC_RMON_T_P1024TO2047_Value_MASK) /*!< FEC_RMON_T_P1024TO2047                  */
/* ------- RMON_T_P_GTE2048 Bit Fields              ------ */
#define FEC_RMON_T_P_GTE2048_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P_GTE2048: Value Mask        */
#define FEC_RMON_T_P_GTE2048_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_P_GTE2048: Value Position    */
#define FEC_RMON_T_P_GTE2048_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_P_GTE2048_Value_SHIFT))&FEC_RMON_T_P_GTE2048_Value_MASK) /*!< FEC_RMON_T_P_GTE2048                    */
/* ------- RMON_T_OCTETS Bit Fields                 ------ */
#define FEC_RMON_T_OCTETS_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_OCTETS: Value Mask           */
#define FEC_RMON_T_OCTETS_Value_SHIFT            (0U)                                                /*!< FEC_RMON_T_OCTETS: Value Position       */
#define FEC_RMON_T_OCTETS_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_T_OCTETS_Value_SHIFT))&FEC_RMON_T_OCTETS_Value_MASK) /*!< FEC_RMON_T_OCTETS                       */
/* ------- IEEE_T_DROP Bit Fields                   ------ */
#define FEC_IEEE_T_DROP_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_DROP: Value Mask             */
#define FEC_IEEE_T_DROP_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_T_DROP: Value Position         */
#define FEC_IEEE_T_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_DROP_Value_SHIFT))&FEC_IEEE_T_DROP_Value_MASK) /*!< FEC_IEEE_T_DROP                         */
/* ------- IEEE_T_FRAME_OK Bit Fields               ------ */
#define FEC_IEEE_T_FRAME_OK_Value_MASK           (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_FRAME_OK: Value Mask         */
#define FEC_IEEE_T_FRAME_OK_Value_SHIFT          (0U)                                                /*!< FEC_IEEE_T_FRAME_OK: Value Position     */
#define FEC_IEEE_T_FRAME_OK_Value(x)             (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_FRAME_OK_Value_SHIFT))&FEC_IEEE_T_FRAME_OK_Value_MASK) /*!< FEC_IEEE_T_FRAME_OK                     */
/* ------- IEEE_T_1COL Bit Fields                   ------ */
#define FEC_IEEE_T_1COL_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_1COL: Value Mask             */
#define FEC_IEEE_T_1COL_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_T_1COL: Value Position         */
#define FEC_IEEE_T_1COL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_1COL_Value_SHIFT))&FEC_IEEE_T_1COL_Value_MASK) /*!< FEC_IEEE_T_1COL                         */
/* ------- IEEE_T_MCOL Bit Fields                   ------ */
#define FEC_IEEE_T_MCOL_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_MCOL: Value Mask             */
#define FEC_IEEE_T_MCOL_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_T_MCOL: Value Position         */
#define FEC_IEEE_T_MCOL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_MCOL_Value_SHIFT))&FEC_IEEE_T_MCOL_Value_MASK) /*!< FEC_IEEE_T_MCOL                         */
/* ------- IEEE_T_DEF Bit Fields                    ------ */
#define FEC_IEEE_T_DEF_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_DEF: Value Mask              */
#define FEC_IEEE_T_DEF_Value_SHIFT               (0U)                                                /*!< FEC_IEEE_T_DEF: Value Position          */
#define FEC_IEEE_T_DEF_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_DEF_Value_SHIFT))&FEC_IEEE_T_DEF_Value_MASK) /*!< FEC_IEEE_T_DEF                          */
/* ------- IEEE_T_LCOL Bit Fields                   ------ */
#define FEC_IEEE_T_LCOL_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_LCOL: Value Mask             */
#define FEC_IEEE_T_LCOL_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_T_LCOL: Value Position         */
#define FEC_IEEE_T_LCOL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_LCOL_Value_SHIFT))&FEC_IEEE_T_LCOL_Value_MASK) /*!< FEC_IEEE_T_LCOL                         */
/* ------- IEEE_T_EXCOL Bit Fields                  ------ */
#define FEC_IEEE_T_EXCOL_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_EXCOL: Value Mask            */
#define FEC_IEEE_T_EXCOL_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_T_EXCOL: Value Position        */
#define FEC_IEEE_T_EXCOL_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_EXCOL_Value_SHIFT))&FEC_IEEE_T_EXCOL_Value_MASK) /*!< FEC_IEEE_T_EXCOL                        */
/* ------- IEEE_T_MACERR Bit Fields                 ------ */
#define FEC_IEEE_T_MACERR_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_MACERR: Value Mask           */
#define FEC_IEEE_T_MACERR_Value_SHIFT            (0U)                                                /*!< FEC_IEEE_T_MACERR: Value Position       */
#define FEC_IEEE_T_MACERR_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_MACERR_Value_SHIFT))&FEC_IEEE_T_MACERR_Value_MASK) /*!< FEC_IEEE_T_MACERR                       */
/* ------- IEEE_T_CSERR Bit Fields                  ------ */
#define FEC_IEEE_T_CSERR_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_CSERR: Value Mask            */
#define FEC_IEEE_T_CSERR_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_T_CSERR: Value Position        */
#define FEC_IEEE_T_CSERR_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_CSERR_Value_SHIFT))&FEC_IEEE_T_CSERR_Value_MASK) /*!< FEC_IEEE_T_CSERR                        */
/* ------- IEEE_T_SQE Bit Fields                    ------ */
#define FEC_IEEE_T_SQE_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_SQE: Value Mask              */
#define FEC_IEEE_T_SQE_Value_SHIFT               (0U)                                                /*!< FEC_IEEE_T_SQE: Value Position          */
#define FEC_IEEE_T_SQE_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_SQE_Value_SHIFT))&FEC_IEEE_T_SQE_Value_MASK) /*!< FEC_IEEE_T_SQE                          */
/* ------- IEEE_T_FDXFC Bit Fields                  ------ */
#define FEC_IEEE_T_FDXFC_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_FDXFC: Value Mask            */
#define FEC_IEEE_T_FDXFC_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_T_FDXFC: Value Position        */
#define FEC_IEEE_T_FDXFC_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_FDXFC_Value_SHIFT))&FEC_IEEE_T_FDXFC_Value_MASK) /*!< FEC_IEEE_T_FDXFC                        */
/* ------- IEEE_T_OCTETS_OK Bit Fields              ------ */
#define FEC_IEEE_T_OCTETS_OK_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_OCTETS_OK: Value Mask        */
#define FEC_IEEE_T_OCTETS_OK_Value_SHIFT         (0U)                                                /*!< FEC_IEEE_T_OCTETS_OK: Value Position    */
#define FEC_IEEE_T_OCTETS_OK_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_T_OCTETS_OK_Value_SHIFT))&FEC_IEEE_T_OCTETS_OK_Value_MASK) /*!< FEC_IEEE_T_OCTETS_OK                    */
/* ------- RMON_R_DROP Bit Fields                   ------ */
#define FEC_RMON_R_DROP_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_DROP: Value Mask             */
#define FEC_RMON_R_DROP_Value_SHIFT              (0U)                                                /*!< FEC_RMON_R_DROP: Value Position         */
#define FEC_RMON_R_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_DROP_Value_SHIFT))&FEC_RMON_R_DROP_Value_MASK) /*!< FEC_RMON_R_DROP                         */
/* ------- RMON_R_PACKETS Bit Fields                ------ */
#define FEC_RMON_R_PACKETS_Value_MASK            (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_PACKETS: Value Mask          */
#define FEC_RMON_R_PACKETS_Value_SHIFT           (0U)                                                /*!< FEC_RMON_R_PACKETS: Value Position      */
#define FEC_RMON_R_PACKETS_Value(x)              (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_PACKETS_Value_SHIFT))&FEC_RMON_R_PACKETS_Value_MASK) /*!< FEC_RMON_R_PACKETS                      */
/* ------- RMON_R_BC_PKT Bit Fields                 ------ */
#define FEC_RMON_R_BC_PKT_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_BC_PKT: Value Mask           */
#define FEC_RMON_R_BC_PKT_Value_SHIFT            (0U)                                                /*!< FEC_RMON_R_BC_PKT: Value Position       */
#define FEC_RMON_R_BC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_BC_PKT_Value_SHIFT))&FEC_RMON_R_BC_PKT_Value_MASK) /*!< FEC_RMON_R_BC_PKT                       */
/* ------- RMON_R_MC_PKT Bit Fields                 ------ */
#define FEC_RMON_R_MC_PKT_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_MC_PKT: Value Mask           */
#define FEC_RMON_R_MC_PKT_Value_SHIFT            (0U)                                                /*!< FEC_RMON_R_MC_PKT: Value Position       */
#define FEC_RMON_R_MC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_MC_PKT_Value_SHIFT))&FEC_RMON_R_MC_PKT_Value_MASK) /*!< FEC_RMON_R_MC_PKT                       */
/* ------- RMON_R_CRC_ALIGN Bit Fields              ------ */
#define FEC_RMON_R_CRC_ALIGN_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_CRC_ALIGN: Value Mask        */
#define FEC_RMON_R_CRC_ALIGN_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_CRC_ALIGN: Value Position    */
#define FEC_RMON_R_CRC_ALIGN_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_CRC_ALIGN_Value_SHIFT))&FEC_RMON_R_CRC_ALIGN_Value_MASK) /*!< FEC_RMON_R_CRC_ALIGN                    */
/* ------- RMON_R_UNDERSIZE Bit Fields              ------ */
#define FEC_RMON_R_UNDERSIZE_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_UNDERSIZE: Value Mask        */
#define FEC_RMON_R_UNDERSIZE_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_UNDERSIZE: Value Position    */
#define FEC_RMON_R_UNDERSIZE_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_UNDERSIZE_Value_SHIFT))&FEC_RMON_R_UNDERSIZE_Value_MASK) /*!< FEC_RMON_R_UNDERSIZE                    */
/* ------- RMON_R_OVERSIZE Bit Fields               ------ */
#define FEC_RMON_R_OVERSIZE_Value_MASK           (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_OVERSIZE: Value Mask         */
#define FEC_RMON_R_OVERSIZE_Value_SHIFT          (0U)                                                /*!< FEC_RMON_R_OVERSIZE: Value Position     */
#define FEC_RMON_R_OVERSIZE_Value(x)             (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_OVERSIZE_Value_SHIFT))&FEC_RMON_R_OVERSIZE_Value_MASK) /*!< FEC_RMON_R_OVERSIZE                     */
/* ------- RMON_R_FRAG Bit Fields                   ------ */
#define FEC_RMON_R_FRAG_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_FRAG: Value Mask             */
#define FEC_RMON_R_FRAG_Value_SHIFT              (0U)                                                /*!< FEC_RMON_R_FRAG: Value Position         */
#define FEC_RMON_R_FRAG_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_FRAG_Value_SHIFT))&FEC_RMON_R_FRAG_Value_MASK) /*!< FEC_RMON_R_FRAG                         */
/* ------- RMON_R_JAB Bit Fields                    ------ */
#define FEC_RMON_R_JAB_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_JAB: Value Mask              */
#define FEC_RMON_R_JAB_Value_SHIFT               (0U)                                                /*!< FEC_RMON_R_JAB: Value Position          */
#define FEC_RMON_R_JAB_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_JAB_Value_SHIFT))&FEC_RMON_R_JAB_Value_MASK) /*!< FEC_RMON_R_JAB                          */
/* ------- RMON_R_RESVD_0 Bit Fields                ------ */
#define FEC_RMON_R_RESVD_0_Value_MASK            (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_RESVD_0: Value Mask          */
#define FEC_RMON_R_RESVD_0_Value_SHIFT           (0U)                                                /*!< FEC_RMON_R_RESVD_0: Value Position      */
#define FEC_RMON_R_RESVD_0_Value(x)              (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_RESVD_0_Value_SHIFT))&FEC_RMON_R_RESVD_0_Value_MASK) /*!< FEC_RMON_R_RESVD_0                      */
/* ------- RMON_R_P6 Bit Fields                     ------ */
#define FEC_RMON_R_P6_Value_MASK                 (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P6: Value Mask               */
#define FEC_RMON_R_P6_Value_SHIFT                (0U)                                                /*!< FEC_RMON_R_P6: Value Position           */
#define FEC_RMON_R_P6_Value(x)                   (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P6_Value_SHIFT))&FEC_RMON_R_P6_Value_MASK) /*!< FEC_RMON_R_P6                           */
/* ------- RMON_R_P128TO255 Bit Fields              ------ */
#define FEC_RMON_R_P128TO255_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P128TO255: Value Mask        */
#define FEC_RMON_R_P128TO255_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_P128TO255: Value Position    */
#define FEC_RMON_R_P128TO255_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P128TO255_Value_SHIFT))&FEC_RMON_R_P128TO255_Value_MASK) /*!< FEC_RMON_R_P128TO255                    */
/* ------- RMON_R_P256TO511 Bit Fields              ------ */
#define FEC_RMON_R_P256TO511_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P256TO511: Value Mask        */
#define FEC_RMON_R_P256TO511_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_P256TO511: Value Position    */
#define FEC_RMON_R_P256TO511_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P256TO511_Value_SHIFT))&FEC_RMON_R_P256TO511_Value_MASK) /*!< FEC_RMON_R_P256TO511                    */
/* ------- RMON_R_P512TO1023 Bit Fields             ------ */
#define FEC_RMON_R_P512TO1023_Value_MASK         (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P512TO1023: Value Mask       */
#define FEC_RMON_R_P512TO1023_Value_SHIFT        (0U)                                                /*!< FEC_RMON_R_P512TO1023: Value Position   */
#define FEC_RMON_R_P512TO1023_Value(x)           (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P512TO1023_Value_SHIFT))&FEC_RMON_R_P512TO1023_Value_MASK) /*!< FEC_RMON_R_P512TO1023                   */
/* ------- RMON_R_P1024TO2047 Bit Fields            ------ */
#define FEC_RMON_R_P1024TO2047_Value_MASK        (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P1024TO2047: Value Mask      */
#define FEC_RMON_R_P1024TO2047_Value_SHIFT       (0U)                                                /*!< FEC_RMON_R_P1024TO2047: Value Position  */
#define FEC_RMON_R_P1024TO2047_Value(x)          (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P1024TO2047_Value_SHIFT))&FEC_RMON_R_P1024TO2047_Value_MASK) /*!< FEC_RMON_R_P1024TO2047                  */
/* ------- RMON_R_P_GTE2048 Bit Fields              ------ */
#define FEC_RMON_R_P_GTE2048_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P_GTE2048: Value Mask        */
#define FEC_RMON_R_P_GTE2048_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_P_GTE2048: Value Position    */
#define FEC_RMON_R_P_GTE2048_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_P_GTE2048_Value_SHIFT))&FEC_RMON_R_P_GTE2048_Value_MASK) /*!< FEC_RMON_R_P_GTE2048                    */
/* ------- RMON_R_OCTETS Bit Fields                 ------ */
#define FEC_RMON_R_OCTETS_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_OCTETS: Value Mask           */
#define FEC_RMON_R_OCTETS_Value_SHIFT            (0U)                                                /*!< FEC_RMON_R_OCTETS: Value Position       */
#define FEC_RMON_R_OCTETS_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_RMON_R_OCTETS_Value_SHIFT))&FEC_RMON_R_OCTETS_Value_MASK) /*!< FEC_RMON_R_OCTETS                       */
/* ------- IEEE_R_DROP Bit Fields                   ------ */
#define FEC_IEEE_R_DROP_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_DROP: Value Mask             */
#define FEC_IEEE_R_DROP_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_R_DROP: Value Position         */
#define FEC_IEEE_R_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_DROP_Value_SHIFT))&FEC_IEEE_R_DROP_Value_MASK) /*!< FEC_IEEE_R_DROP                         */
/* ------- IEEE_R_FRAME_OK Bit Fields               ------ */
#define FEC_IEEE_R_FRAME_OK_Value_MASK           (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_FRAME_OK: Value Mask         */
#define FEC_IEEE_R_FRAME_OK_Value_SHIFT          (0U)                                                /*!< FEC_IEEE_R_FRAME_OK: Value Position     */
#define FEC_IEEE_R_FRAME_OK_Value(x)             (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_FRAME_OK_Value_SHIFT))&FEC_IEEE_R_FRAME_OK_Value_MASK) /*!< FEC_IEEE_R_FRAME_OK                     */
/* ------- IEEE_R_CRC Bit Fields                    ------ */
#define FEC_IEEE_R_CRC_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_CRC: Value Mask              */
#define FEC_IEEE_R_CRC_Value_SHIFT               (0U)                                                /*!< FEC_IEEE_R_CRC: Value Position          */
#define FEC_IEEE_R_CRC_Value(x)                  (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_CRC_Value_SHIFT))&FEC_IEEE_R_CRC_Value_MASK) /*!< FEC_IEEE_R_CRC                          */
/* ------- IEEE_R_ALIGN Bit Fields                  ------ */
#define FEC_IEEE_R_ALIGN_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_ALIGN: Value Mask            */
#define FEC_IEEE_R_ALIGN_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_R_ALIGN: Value Position        */
#define FEC_IEEE_R_ALIGN_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_ALIGN_Value_SHIFT))&FEC_IEEE_R_ALIGN_Value_MASK) /*!< FEC_IEEE_R_ALIGN                        */
/* ------- IEEE_R_MACERR Bit Fields                 ------ */
#define FEC_IEEE_R_MACERR_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_MACERR: Value Mask           */
#define FEC_IEEE_R_MACERR_Value_SHIFT            (0U)                                                /*!< FEC_IEEE_R_MACERR: Value Position       */
#define FEC_IEEE_R_MACERR_Value(x)               (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_MACERR_Value_SHIFT))&FEC_IEEE_R_MACERR_Value_MASK) /*!< FEC_IEEE_R_MACERR                       */
/* ------- IEEE_R_FDXFC Bit Fields                  ------ */
#define FEC_IEEE_R_FDXFC_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_FDXFC: Value Mask            */
#define FEC_IEEE_R_FDXFC_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_R_FDXFC: Value Position        */
#define FEC_IEEE_R_FDXFC_Value(x)                (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_FDXFC_Value_SHIFT))&FEC_IEEE_R_FDXFC_Value_MASK) /*!< FEC_IEEE_R_FDXFC                        */
/* ------- IEEE_R_OCTETS_OK Bit Fields              ------ */
#define FEC_IEEE_R_OCTETS_OK_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_OCTETS_OK: Value Mask        */
#define FEC_IEEE_R_OCTETS_OK_Value_SHIFT         (0U)                                                /*!< FEC_IEEE_R_OCTETS_OK: Value Position    */
#define FEC_IEEE_R_OCTETS_OK_Value(x)            (((uint32_t)(((uint32_t)(x))<<FEC_IEEE_R_OCTETS_OK_Value_SHIFT))&FEC_IEEE_R_OCTETS_OK_Value_MASK) /*!< FEC_IEEE_R_OCTETS_OK                    */
/**
 * @} */ /* End group FEC_Register_Masks_GROUP 
 */

/* FEC - Peripheral instance base addresses */
#define FEC_BasePtr                    0x40001004UL //!< Peripheral base address
#define FEC                            ((FEC_Type *) FEC_BasePtr) //!< Freescale base pointer
#define FEC_BASE_PTR                   (FEC) //!< Freescale style base pointer
/**
 * @} */ /* End group FEC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIO (file:MCF52233_GPIO)            ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O Port
 */
/**
* @addtogroup GPIO_structs_GROUP GPIO struct
* @brief Struct for GPIO
* @{
*/
typedef struct {                                /*       GPIO Structure                                               */
   __IO uint8_t   PORTNQ;                       /**< 0000: Data register                                                */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   PORTAN;                       /**< 0002: Data register                                                */
   __IO uint8_t   PORTAS;                       /**< 0003: Data register                                                */
   __IO uint8_t   PORTQS;                       /**< 0004: Data register                                                */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   PORTTA;                       /**< 0006: Data register                                                */
   __IO uint8_t   PORTTC;                       /**< 0007: Data register                                                */
   __IO uint8_t   PORTTD;                       /**< 0008: Data register                                                */
   __IO uint8_t   PORTUA;                       /**< 0009: Data register                                                */
   __IO uint8_t   PORTUB;                       /**< 000A: Data register                                                */
   __IO uint8_t   PORTUC;                       /**< 000B: Data register                                                */
   __IO uint8_t   PORTDD;                       /**< 000C: Data register                                                */
   __IO uint8_t   PORTLD;                       /**< 000D: Data register                                                */
   __IO uint8_t   PORTGP;                       /**< 000E: Data register                                                */
        uint8_t   RESERVED_2[9];               
   __IO uint8_t   DDRNQ;                        /**< 0018: Direction register                                           */
        uint8_t   RESERVED_3;                  
   __IO uint8_t   DDRAN;                        /**< 001A: Direction register                                           */
   __IO uint8_t   DDRAS;                        /**< 001B: Direction register                                           */
   __IO uint8_t   DDRQS;                        /**< 001C: Direction register                                           */
        uint8_t   RESERVED_4;                  
   __IO uint8_t   DDRTA;                        /**< 001E: Direction register                                           */
   __IO uint8_t   DDRTC;                        /**< 001F: Direction register                                           */
   __IO uint8_t   DDRTD;                        /**< 0020: Direction register                                           */
   __IO uint8_t   DDRUA;                        /**< 0021: Direction register                                           */
   __IO uint8_t   DDRUB;                        /**< 0022: Direction register                                           */
   __IO uint8_t   DDRUC;                        /**< 0023: Direction register                                           */
   __IO uint8_t   DDRDD;                        /**< 0024: Direction register                                           */
   __IO uint8_t   DDRLD;                        /**< 0025: Direction register                                           */
   __IO uint8_t   DDRGP;                        /**< 0026: Direction register                                           */
        uint8_t   RESERVED_5[9];               
   __IO uint8_t   SETNQ;                        /**< 0030: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_6;                  
   __IO uint8_t   SETAN;                        /**< 0032: Pin Data/Set Registers                                       */
   __IO uint8_t   SETAS;                        /**< 0033: Pin Data/Set Registers                                       */
   __IO uint8_t   SETQS;                        /**< 0034: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_7;                  
   __IO uint8_t   SETTA;                        /**< 0036: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTC;                        /**< 0037: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTD;                        /**< 0038: Pin Data/Set Registers                                       */
   __IO uint8_t   SETUA;                        /**< 0039: Pin Data/Set Registers                                       */
   __IO uint8_t   SETUB;                        /**< 003A: Pin Data/Set Registers                                       */
   __IO uint8_t   SETUC;                        /**< 003B: Pin Data/Set Registers                                       */
   __IO uint8_t   SETDD;                        /**< 003C: Pin Data/Set Registers                                       */
   __IO uint8_t   SETLD;                        /**< 003D: Pin Data/Set Registers                                       */
   __IO uint8_t   SETGP;                        /**< 003E: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_8[9];               
   __O  uint8_t   CLRNQ;                        /**< 0048: Port Clear Output Data Register                              */
        uint8_t   RESERVED_9;                  
   __O  uint8_t   CLRAN;                        /**< 004A: Port Clear Output Data Register                              */
   __O  uint8_t   CLRAS;                        /**< 004B: Port Clear Output Data Register                              */
   __O  uint8_t   CLRQS;                        /**< 004C: Port Clear Output Data Register                              */
        uint8_t   RESERVED_10;                 
   __O  uint8_t   CLRTA;                        /**< 004E: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTC;                        /**< 004F: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTD;                        /**< 0050: Port Clear Output Data Register                              */
   __O  uint8_t   CLRUA;                        /**< 0051: Port Clear Output Data Register                              */
   __O  uint8_t   CLRUB;                        /**< 0052: Port Clear Output Data Register                              */
   __O  uint8_t   CLRUC;                        /**< 0053: Port Clear Output Data Register                              */
   __O  uint8_t   CLRDD;                        /**< 0054: Port Clear Output Data Register                              */
   __O  uint8_t   CLRLD;                        /**< 0055: Port Clear Output Data Register                              */
   __O  uint8_t   CLRGP;                        /**< 0056: Port Clear Output Data Register                              */
        uint8_t   RESERVED_11[9];              
   __IO uint16_t  QPARNQ;                       /**< 0060: Pin Configuration                                            */
   __IO uint8_t   PARAN;                        /**< 0062: Pin Configuration                                            */
   __IO uint8_t   QPARAS;                       /**< 0063: Pin Configuration                                            */
   __IO uint16_t  QPARQS;                       /**< 0064: Pin Configuration                                            */
   __IO uint8_t   QPARTA;                       /**< 0066: Pin Configuration                                            */
   __IO uint8_t   QPARTC;                       /**< 0067: Pin Configuration                                            */
   __IO uint8_t   PARTD;                        /**< 0068: Pin Configuration                                            */
   __IO uint8_t   QPARUA;                       /**< 0069: Pin Configuration                                            */
   __IO uint8_t   QPARUB;                       /**< 006A: Pin Configuration                                            */
   __IO uint8_t   PARUC;                        /**< 006B: Pin Configuration                                            */
   __IO uint8_t   PARDD;                        /**< 006C: Pin Configuration                                            */
   __IO uint8_t   PARLD;                        /**< 006D: Pin Configuration                                            */
   __IO uint8_t   PARGP;                        /**< 006E: Pin Configuration                                            */
} GPIO_Type;

/**
 * @} */ /* End group GPIO_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIO' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_Register_Masks_GROUP GPIO Register Masks
* @brief Register Masks for GPIO
* @{
*/
/* ------- PORTNQ Bit Fields                        ------ */
#define GPIO_PORT_PORT0_MASK                     (0x1U)                                              /*!< GPIO_PORTNQ: PORT0 Mask                 */
#define GPIO_PORT_PORT0_SHIFT                    (0U)                                                /*!< GPIO_PORTNQ: PORT0 Position             */
#define GPIO_PORT_PORT0(x)                       (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_PORT0_SHIFT))&GPIO_PORT_PORT0_MASK) /*!< GPIO_PORTNQ                             */
#define GPIO_PORT_PORT1_MASK                     (0x2U)                                              /*!< GPIO_PORTNQ: PORT1 Mask                 */
#define GPIO_PORT_PORT1_SHIFT                    (1U)                                                /*!< GPIO_PORTNQ: PORT1 Position             */
#define GPIO_PORT_PORT1(x)                       (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_PORT1_SHIFT))&GPIO_PORT_PORT1_MASK) /*!< GPIO_PORTNQ                             */
#define GPIO_PORT_PORT2_MASK                     (0x4U)                                              /*!< GPIO_PORTNQ: PORT2 Mask                 */
#define GPIO_PORT_PORT2_SHIFT                    (2U)                                                /*!< GPIO_PORTNQ: PORT2 Position             */
#define GPIO_PORT_PORT2(x)                       (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_PORT2_SHIFT))&GPIO_PORT_PORT2_MASK) /*!< GPIO_PORTNQ                             */
#define GPIO_PORT_PORT3_MASK                     (0x8U)                                              /*!< GPIO_PORTNQ: PORT3 Mask                 */
#define GPIO_PORT_PORT3_SHIFT                    (3U)                                                /*!< GPIO_PORTNQ: PORT3 Position             */
#define GPIO_PORT_PORT3(x)                       (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_PORT3_SHIFT))&GPIO_PORT_PORT3_MASK) /*!< GPIO_PORTNQ                             */
#define GPIO_PORT_PORT4_MASK                     (0x10U)                                             /*!< GPIO_PORTNQ: PORT4 Mask                 */
#define GPIO_PORT_PORT4_SHIFT                    (4U)                                                /*!< GPIO_PORTNQ: PORT4 Position             */
#define GPIO_PORT_PORT4(x)                       (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_PORT4_SHIFT))&GPIO_PORT_PORT4_MASK) /*!< GPIO_PORTNQ                             */
#define GPIO_PORT_PORT5_MASK                     (0x20U)                                             /*!< GPIO_PORTNQ: PORT5 Mask                 */
#define GPIO_PORT_PORT5_SHIFT                    (5U)                                                /*!< GPIO_PORTNQ: PORT5 Position             */
#define GPIO_PORT_PORT5(x)                       (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_PORT5_SHIFT))&GPIO_PORT_PORT5_MASK) /*!< GPIO_PORTNQ                             */
#define GPIO_PORT_PORT6_MASK                     (0x40U)                                             /*!< GPIO_PORTNQ: PORT6 Mask                 */
#define GPIO_PORT_PORT6_SHIFT                    (6U)                                                /*!< GPIO_PORTNQ: PORT6 Position             */
#define GPIO_PORT_PORT6(x)                       (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_PORT6_SHIFT))&GPIO_PORT_PORT6_MASK) /*!< GPIO_PORTNQ                             */
#define GPIO_PORT_PORT7_MASK                     (0x80U)                                             /*!< GPIO_PORTNQ: PORT7 Mask                 */
#define GPIO_PORT_PORT7_SHIFT                    (7U)                                                /*!< GPIO_PORTNQ: PORT7 Position             */
#define GPIO_PORT_PORT7(x)                       (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_PORT7_SHIFT))&GPIO_PORT_PORT7_MASK) /*!< GPIO_PORTNQ                             */
/* ------- DDRNQ Bit Fields                         ------ */
#define GPIO_DDR_DDR0_MASK                       (0x1U)                                              /*!< GPIO_DDRNQ: DDR0 Mask                   */
#define GPIO_DDR_DDR0_SHIFT                      (0U)                                                /*!< GPIO_DDRNQ: DDR0 Position               */
#define GPIO_DDR_DDR0(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_DDR_DDR0_SHIFT))&GPIO_DDR_DDR0_MASK) /*!< GPIO_DDRNQ                              */
#define GPIO_DDR_DDR1_MASK                       (0x2U)                                              /*!< GPIO_DDRNQ: DDR1 Mask                   */
#define GPIO_DDR_DDR1_SHIFT                      (1U)                                                /*!< GPIO_DDRNQ: DDR1 Position               */
#define GPIO_DDR_DDR1(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_DDR_DDR1_SHIFT))&GPIO_DDR_DDR1_MASK) /*!< GPIO_DDRNQ                              */
#define GPIO_DDR_DDR2_MASK                       (0x4U)                                              /*!< GPIO_DDRNQ: DDR2 Mask                   */
#define GPIO_DDR_DDR2_SHIFT                      (2U)                                                /*!< GPIO_DDRNQ: DDR2 Position               */
#define GPIO_DDR_DDR2(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_DDR_DDR2_SHIFT))&GPIO_DDR_DDR2_MASK) /*!< GPIO_DDRNQ                              */
#define GPIO_DDR_DDR3_MASK                       (0x8U)                                              /*!< GPIO_DDRNQ: DDR3 Mask                   */
#define GPIO_DDR_DDR3_SHIFT                      (3U)                                                /*!< GPIO_DDRNQ: DDR3 Position               */
#define GPIO_DDR_DDR3(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_DDR_DDR3_SHIFT))&GPIO_DDR_DDR3_MASK) /*!< GPIO_DDRNQ                              */
#define GPIO_DDR_DDR4_MASK                       (0x10U)                                             /*!< GPIO_DDRNQ: DDR4 Mask                   */
#define GPIO_DDR_DDR4_SHIFT                      (4U)                                                /*!< GPIO_DDRNQ: DDR4 Position               */
#define GPIO_DDR_DDR4(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_DDR_DDR4_SHIFT))&GPIO_DDR_DDR4_MASK) /*!< GPIO_DDRNQ                              */
#define GPIO_DDR_DDR5_MASK                       (0x20U)                                             /*!< GPIO_DDRNQ: DDR5 Mask                   */
#define GPIO_DDR_DDR5_SHIFT                      (5U)                                                /*!< GPIO_DDRNQ: DDR5 Position               */
#define GPIO_DDR_DDR5(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_DDR_DDR5_SHIFT))&GPIO_DDR_DDR5_MASK) /*!< GPIO_DDRNQ                              */
#define GPIO_DDR_DDR6_MASK                       (0x40U)                                             /*!< GPIO_DDRNQ: DDR6 Mask                   */
#define GPIO_DDR_DDR6_SHIFT                      (6U)                                                /*!< GPIO_DDRNQ: DDR6 Position               */
#define GPIO_DDR_DDR6(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_DDR_DDR6_SHIFT))&GPIO_DDR_DDR6_MASK) /*!< GPIO_DDRNQ                              */
#define GPIO_DDR_DDR7_MASK                       (0x80U)                                             /*!< GPIO_DDRNQ: DDR7 Mask                   */
#define GPIO_DDR_DDR7_SHIFT                      (7U)                                                /*!< GPIO_DDRNQ: DDR7 Position               */
#define GPIO_DDR_DDR7(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_DDR_DDR7_SHIFT))&GPIO_DDR_DDR7_MASK) /*!< GPIO_DDRNQ                              */
/* ------- SETNQ Bit Fields                         ------ */
#define GPIO_SET_SET0_MASK                       (0x1U)                                              /*!< GPIO_SETNQ: SET0 Mask                   */
#define GPIO_SET_SET0_SHIFT                      (0U)                                                /*!< GPIO_SETNQ: SET0 Position               */
#define GPIO_SET_SET0(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_SET_SET0_SHIFT))&GPIO_SET_SET0_MASK) /*!< GPIO_SETNQ                              */
#define GPIO_SET_SET1_MASK                       (0x2U)                                              /*!< GPIO_SETNQ: SET1 Mask                   */
#define GPIO_SET_SET1_SHIFT                      (1U)                                                /*!< GPIO_SETNQ: SET1 Position               */
#define GPIO_SET_SET1(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_SET_SET1_SHIFT))&GPIO_SET_SET1_MASK) /*!< GPIO_SETNQ                              */
#define GPIO_SET_SET2_MASK                       (0x4U)                                              /*!< GPIO_SETNQ: SET2 Mask                   */
#define GPIO_SET_SET2_SHIFT                      (2U)                                                /*!< GPIO_SETNQ: SET2 Position               */
#define GPIO_SET_SET2(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_SET_SET2_SHIFT))&GPIO_SET_SET2_MASK) /*!< GPIO_SETNQ                              */
#define GPIO_SET_SET3_MASK                       (0x8U)                                              /*!< GPIO_SETNQ: SET3 Mask                   */
#define GPIO_SET_SET3_SHIFT                      (3U)                                                /*!< GPIO_SETNQ: SET3 Position               */
#define GPIO_SET_SET3(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_SET_SET3_SHIFT))&GPIO_SET_SET3_MASK) /*!< GPIO_SETNQ                              */
#define GPIO_SET_SET4_MASK                       (0x10U)                                             /*!< GPIO_SETNQ: SET4 Mask                   */
#define GPIO_SET_SET4_SHIFT                      (4U)                                                /*!< GPIO_SETNQ: SET4 Position               */
#define GPIO_SET_SET4(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_SET_SET4_SHIFT))&GPIO_SET_SET4_MASK) /*!< GPIO_SETNQ                              */
#define GPIO_SET_SET5_MASK                       (0x20U)                                             /*!< GPIO_SETNQ: SET5 Mask                   */
#define GPIO_SET_SET5_SHIFT                      (5U)                                                /*!< GPIO_SETNQ: SET5 Position               */
#define GPIO_SET_SET5(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_SET_SET5_SHIFT))&GPIO_SET_SET5_MASK) /*!< GPIO_SETNQ                              */
#define GPIO_SET_SET6_MASK                       (0x40U)                                             /*!< GPIO_SETNQ: SET6 Mask                   */
#define GPIO_SET_SET6_SHIFT                      (6U)                                                /*!< GPIO_SETNQ: SET6 Position               */
#define GPIO_SET_SET6(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_SET_SET6_SHIFT))&GPIO_SET_SET6_MASK) /*!< GPIO_SETNQ                              */
#define GPIO_SET_SET7_MASK                       (0x80U)                                             /*!< GPIO_SETNQ: SET7 Mask                   */
#define GPIO_SET_SET7_SHIFT                      (7U)                                                /*!< GPIO_SETNQ: SET7 Position               */
#define GPIO_SET_SET7(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_SET_SET7_SHIFT))&GPIO_SET_SET7_MASK) /*!< GPIO_SETNQ                              */
/* ------- CLRNQ Bit Fields                         ------ */
#define GPIO_CLR_CLR0_MASK                       (0x1U)                                              /*!< GPIO_CLRNQ: CLR0 Mask                   */
#define GPIO_CLR_CLR0_SHIFT                      (0U)                                                /*!< GPIO_CLRNQ: CLR0 Position               */
#define GPIO_CLR_CLR0(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_CLR_CLR0_SHIFT))&GPIO_CLR_CLR0_MASK) /*!< GPIO_CLRNQ                              */
#define GPIO_CLR_CLR1_MASK                       (0x2U)                                              /*!< GPIO_CLRNQ: CLR1 Mask                   */
#define GPIO_CLR_CLR1_SHIFT                      (1U)                                                /*!< GPIO_CLRNQ: CLR1 Position               */
#define GPIO_CLR_CLR1(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_CLR_CLR1_SHIFT))&GPIO_CLR_CLR1_MASK) /*!< GPIO_CLRNQ                              */
#define GPIO_CLR_CLR2_MASK                       (0x4U)                                              /*!< GPIO_CLRNQ: CLR2 Mask                   */
#define GPIO_CLR_CLR2_SHIFT                      (2U)                                                /*!< GPIO_CLRNQ: CLR2 Position               */
#define GPIO_CLR_CLR2(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_CLR_CLR2_SHIFT))&GPIO_CLR_CLR2_MASK) /*!< GPIO_CLRNQ                              */
#define GPIO_CLR_CLR3_MASK                       (0x8U)                                              /*!< GPIO_CLRNQ: CLR3 Mask                   */
#define GPIO_CLR_CLR3_SHIFT                      (3U)                                                /*!< GPIO_CLRNQ: CLR3 Position               */
#define GPIO_CLR_CLR3(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_CLR_CLR3_SHIFT))&GPIO_CLR_CLR3_MASK) /*!< GPIO_CLRNQ                              */
#define GPIO_CLR_CLR4_MASK                       (0x10U)                                             /*!< GPIO_CLRNQ: CLR4 Mask                   */
#define GPIO_CLR_CLR4_SHIFT                      (4U)                                                /*!< GPIO_CLRNQ: CLR4 Position               */
#define GPIO_CLR_CLR4(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_CLR_CLR4_SHIFT))&GPIO_CLR_CLR4_MASK) /*!< GPIO_CLRNQ                              */
#define GPIO_CLR_CLR5_MASK                       (0x20U)                                             /*!< GPIO_CLRNQ: CLR5 Mask                   */
#define GPIO_CLR_CLR5_SHIFT                      (5U)                                                /*!< GPIO_CLRNQ: CLR5 Position               */
#define GPIO_CLR_CLR5(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_CLR_CLR5_SHIFT))&GPIO_CLR_CLR5_MASK) /*!< GPIO_CLRNQ                              */
#define GPIO_CLR_CLR6_MASK                       (0x40U)                                             /*!< GPIO_CLRNQ: CLR6 Mask                   */
#define GPIO_CLR_CLR6_SHIFT                      (6U)                                                /*!< GPIO_CLRNQ: CLR6 Position               */
#define GPIO_CLR_CLR6(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_CLR_CLR6_SHIFT))&GPIO_CLR_CLR6_MASK) /*!< GPIO_CLRNQ                              */
#define GPIO_CLR_CLR7_MASK                       (0x80U)                                             /*!< GPIO_CLRNQ: CLR7 Mask                   */
#define GPIO_CLR_CLR7_SHIFT                      (7U)                                                /*!< GPIO_CLRNQ: CLR7 Position               */
#define GPIO_CLR_CLR7(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_CLR_CLR7_SHIFT))&GPIO_CLR_CLR7_MASK) /*!< GPIO_CLRNQ                              */
/* ------- QPARNQ Bit Fields                        ------ */
#define GPIO_QPAR_QPAR0_MASK                     (0x3U)                                              /*!< GPIO_QPARNQ: QPAR0 Mask                 */
#define GPIO_QPAR_QPAR0_SHIFT                    (0U)                                                /*!< GPIO_QPARNQ: QPAR0 Position             */
#define GPIO_QPAR_QPAR0(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR0_SHIFT))&GPIO_QPAR_QPAR0_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR1_MASK                     (0xCU)                                              /*!< GPIO_QPARNQ: QPAR1 Mask                 */
#define GPIO_QPAR_QPAR1_SHIFT                    (2U)                                                /*!< GPIO_QPARNQ: QPAR1 Position             */
#define GPIO_QPAR_QPAR1(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR1_SHIFT))&GPIO_QPAR_QPAR1_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR2_MASK                     (0x30U)                                             /*!< GPIO_QPARNQ: QPAR2 Mask                 */
#define GPIO_QPAR_QPAR2_SHIFT                    (4U)                                                /*!< GPIO_QPARNQ: QPAR2 Position             */
#define GPIO_QPAR_QPAR2(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR2_SHIFT))&GPIO_QPAR_QPAR2_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR3_MASK                     (0xC0U)                                             /*!< GPIO_QPARNQ: QPAR3 Mask                 */
#define GPIO_QPAR_QPAR3_SHIFT                    (6U)                                                /*!< GPIO_QPARNQ: QPAR3 Position             */
#define GPIO_QPAR_QPAR3(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR3_SHIFT))&GPIO_QPAR_QPAR3_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR4_MASK                     (0x300U)                                            /*!< GPIO_QPARNQ: QPAR4 Mask                 */
#define GPIO_QPAR_QPAR4_SHIFT                    (8U)                                                /*!< GPIO_QPARNQ: QPAR4 Position             */
#define GPIO_QPAR_QPAR4(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR4_SHIFT))&GPIO_QPAR_QPAR4_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR5_MASK                     (0xC00U)                                            /*!< GPIO_QPARNQ: QPAR5 Mask                 */
#define GPIO_QPAR_QPAR5_SHIFT                    (10U)                                               /*!< GPIO_QPARNQ: QPAR5 Position             */
#define GPIO_QPAR_QPAR5(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR5_SHIFT))&GPIO_QPAR_QPAR5_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR6_MASK                     (0x3000U)                                           /*!< GPIO_QPARNQ: QPAR6 Mask                 */
#define GPIO_QPAR_QPAR6_SHIFT                    (12U)                                               /*!< GPIO_QPARNQ: QPAR6 Position             */
#define GPIO_QPAR_QPAR6(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR6_SHIFT))&GPIO_QPAR_QPAR6_MASK) /*!< GPIO_QPARNQ                             */
#define GPIO_QPAR_QPAR7_MASK                     (0xC000U)                                           /*!< GPIO_QPARNQ: QPAR7 Mask                 */
#define GPIO_QPAR_QPAR7_SHIFT                    (14U)                                               /*!< GPIO_QPARNQ: QPAR7 Position             */
#define GPIO_QPAR_QPAR7(x)                       (((uint16_t)(((uint16_t)(x))<<GPIO_QPAR_QPAR7_SHIFT))&GPIO_QPAR_QPAR7_MASK) /*!< GPIO_QPARNQ                             */
/* ------- PARAN Bit Fields                         ------ */
#define GPIO_PAR_PAR0_MASK                       (0x1U)                                              /*!< GPIO_PARAN: PAR0 Mask                   */
#define GPIO_PAR_PAR0_SHIFT                      (0U)                                                /*!< GPIO_PARAN: PAR0 Position               */
#define GPIO_PAR_PAR0(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PAR_PAR0_SHIFT))&GPIO_PAR_PAR0_MASK) /*!< GPIO_PARAN                              */
#define GPIO_PAR_PAR1_MASK                       (0x2U)                                              /*!< GPIO_PARAN: PAR1 Mask                   */
#define GPIO_PAR_PAR1_SHIFT                      (1U)                                                /*!< GPIO_PARAN: PAR1 Position               */
#define GPIO_PAR_PAR1(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PAR_PAR1_SHIFT))&GPIO_PAR_PAR1_MASK) /*!< GPIO_PARAN                              */
#define GPIO_PAR_PAR2_MASK                       (0x4U)                                              /*!< GPIO_PARAN: PAR2 Mask                   */
#define GPIO_PAR_PAR2_SHIFT                      (2U)                                                /*!< GPIO_PARAN: PAR2 Position               */
#define GPIO_PAR_PAR2(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PAR_PAR2_SHIFT))&GPIO_PAR_PAR2_MASK) /*!< GPIO_PARAN                              */
#define GPIO_PAR_PAR3_MASK                       (0x8U)                                              /*!< GPIO_PARAN: PAR3 Mask                   */
#define GPIO_PAR_PAR3_SHIFT                      (3U)                                                /*!< GPIO_PARAN: PAR3 Position               */
#define GPIO_PAR_PAR3(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PAR_PAR3_SHIFT))&GPIO_PAR_PAR3_MASK) /*!< GPIO_PARAN                              */
#define GPIO_PAR_PAR4_MASK                       (0x10U)                                             /*!< GPIO_PARAN: PAR4 Mask                   */
#define GPIO_PAR_PAR4_SHIFT                      (4U)                                                /*!< GPIO_PARAN: PAR4 Position               */
#define GPIO_PAR_PAR4(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PAR_PAR4_SHIFT))&GPIO_PAR_PAR4_MASK) /*!< GPIO_PARAN                              */
#define GPIO_PAR_PAR5_MASK                       (0x20U)                                             /*!< GPIO_PARAN: PAR5 Mask                   */
#define GPIO_PAR_PAR5_SHIFT                      (5U)                                                /*!< GPIO_PARAN: PAR5 Position               */
#define GPIO_PAR_PAR5(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PAR_PAR5_SHIFT))&GPIO_PAR_PAR5_MASK) /*!< GPIO_PARAN                              */
#define GPIO_PAR_PAR6_MASK                       (0x40U)                                             /*!< GPIO_PARAN: PAR6 Mask                   */
#define GPIO_PAR_PAR6_SHIFT                      (6U)                                                /*!< GPIO_PARAN: PAR6 Position               */
#define GPIO_PAR_PAR6(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PAR_PAR6_SHIFT))&GPIO_PAR_PAR6_MASK) /*!< GPIO_PARAN                              */
#define GPIO_PAR_PAR7_MASK                       (0x80U)                                             /*!< GPIO_PARAN: PAR7 Mask                   */
#define GPIO_PAR_PAR7_SHIFT                      (7U)                                                /*!< GPIO_PARAN: PAR7 Position               */
#define GPIO_PAR_PAR7(x)                         (((uint8_t)(((uint8_t)(x))<<GPIO_PAR_PAR7_SHIFT))&GPIO_PAR_PAR7_MASK) /*!< GPIO_PARAN                              */
/* ------- QPARAS Bit Fields                        ------ */
/**
 * @} */ /* End group GPIO_Register_Masks_GROUP 
 */

/* GPIO - Peripheral instance base addresses */
#define GPIO_BasePtr                   0x40100008UL //!< Peripheral base address
#define GPIO                           ((GPIO_Type *) GPIO_BasePtr) //!< Freescale base pointer
#define GPIO_BASE_PTR                  (GPIO) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPTA_Peripheral_access_layer_GROUP GPTA Peripheral Access Layer
* @brief C Struct for GPTA
* @{
*/

/* ================================================================================ */
/* ================           GPTA (file:MCF52233_GPTA)            ================ */
/* ================================================================================ */

/**
 * @brief None
 */
/**
* @addtogroup GPTA_structs_GROUP GPTA struct
* @brief Struct for GPTA
* @{
*/
typedef struct {                                /*       GPTA Structure                                               */
   __IO uint8_t   GPTIOS;                       /**< 0000: None                                                         */
   __IO uint8_t   GPTCFORC;                     /**< 0001: None                                                         */
   __IO uint8_t   GPTOC3M;                      /**< 0002: None                                                         */
   __IO uint8_t   GPTOC3D;                      /**< 0003: None                                                         */
   __IO uint16_t  GPTCNT;                       /**< 0004: None                                                         */
   __IO uint8_t   GPTSCR1;                      /**< 0006: None                                                         */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   GPTTOV;                       /**< 0008: None                                                         */
   __IO uint8_t   GPTCTL1;                      /**< 0009: None                                                         */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   GPTCTL2;                      /**< 000B: None                                                         */
   __IO uint8_t   GPTIE;                        /**< 000C: None                                                         */
   __IO uint8_t   GPTSCR2;                      /**< 000D: None                                                         */
   __IO uint8_t   GPTFLG1;                      /**< 000E: None                                                         */
   __IO uint8_t   GPTFLG2;                      /**< 000F: None                                                         */
   __IO uint16_t  GPTC[4];                      /**< 0010: None                                                         */
   __IO uint8_t   GPTPACTL;                     /**< 0018: None                                                         */
   __IO uint8_t   GPTPAFLG;                     /**< 0019: None                                                         */
   __IO uint16_t  GPTPACNT;                     /**< 001A: None                                                         */
        uint8_t   RESERVED_2;                  
   __IO uint8_t   GPTPORT;                      /**< 001D: None                                                         */
   __IO uint8_t   GPTDDR;                       /**< 001E: None                                                         */
} GPTA_Type;

/**
 * @} */ /* End group GPTA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPTA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPTA_Register_Masks_GROUP GPTA Register Masks
* @brief Register Masks for GPTA
* @{
*/
/* ------- GPTIOS Bit Fields                        ------ */
#define GPTA_GPTIOS_IOS0_MASK                    (0x1U)                                              /*!< GPTA_GPTIOS: IOS0 Mask                  */
#define GPTA_GPTIOS_IOS0_SHIFT                   (0U)                                                /*!< GPTA_GPTIOS: IOS0 Position              */
#define GPTA_GPTIOS_IOS0(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTIOS_IOS0_SHIFT))&GPTA_GPTIOS_IOS0_MASK) /*!< GPTA_GPTIOS                             */
#define GPTA_GPTIOS_IOS1_MASK                    (0x2U)                                              /*!< GPTA_GPTIOS: IOS1 Mask                  */
#define GPTA_GPTIOS_IOS1_SHIFT                   (1U)                                                /*!< GPTA_GPTIOS: IOS1 Position              */
#define GPTA_GPTIOS_IOS1(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTIOS_IOS1_SHIFT))&GPTA_GPTIOS_IOS1_MASK) /*!< GPTA_GPTIOS                             */
#define GPTA_GPTIOS_IOS2_MASK                    (0x4U)                                              /*!< GPTA_GPTIOS: IOS2 Mask                  */
#define GPTA_GPTIOS_IOS2_SHIFT                   (2U)                                                /*!< GPTA_GPTIOS: IOS2 Position              */
#define GPTA_GPTIOS_IOS2(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTIOS_IOS2_SHIFT))&GPTA_GPTIOS_IOS2_MASK) /*!< GPTA_GPTIOS                             */
#define GPTA_GPTIOS_IOS3_MASK                    (0x8U)                                              /*!< GPTA_GPTIOS: IOS3 Mask                  */
#define GPTA_GPTIOS_IOS3_SHIFT                   (3U)                                                /*!< GPTA_GPTIOS: IOS3 Position              */
#define GPTA_GPTIOS_IOS3(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTIOS_IOS3_SHIFT))&GPTA_GPTIOS_IOS3_MASK) /*!< GPTA_GPTIOS                             */
/* ------- GPTCFORC Bit Fields                      ------ */
#define GPTA_GPTCFORC_FOC0_MASK                  (0x1U)                                              /*!< GPTA_GPTCFORC: FOC0 Mask                */
#define GPTA_GPTCFORC_FOC0_SHIFT                 (0U)                                                /*!< GPTA_GPTCFORC: FOC0 Position            */
#define GPTA_GPTCFORC_FOC0(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCFORC_FOC0_SHIFT))&GPTA_GPTCFORC_FOC0_MASK) /*!< GPTA_GPTCFORC                           */
#define GPTA_GPTCFORC_FOC1_MASK                  (0x2U)                                              /*!< GPTA_GPTCFORC: FOC1 Mask                */
#define GPTA_GPTCFORC_FOC1_SHIFT                 (1U)                                                /*!< GPTA_GPTCFORC: FOC1 Position            */
#define GPTA_GPTCFORC_FOC1(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCFORC_FOC1_SHIFT))&GPTA_GPTCFORC_FOC1_MASK) /*!< GPTA_GPTCFORC                           */
#define GPTA_GPTCFORC_FOC2_MASK                  (0x4U)                                              /*!< GPTA_GPTCFORC: FOC2 Mask                */
#define GPTA_GPTCFORC_FOC2_SHIFT                 (2U)                                                /*!< GPTA_GPTCFORC: FOC2 Position            */
#define GPTA_GPTCFORC_FOC2(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCFORC_FOC2_SHIFT))&GPTA_GPTCFORC_FOC2_MASK) /*!< GPTA_GPTCFORC                           */
#define GPTA_GPTCFORC_FOC3_MASK                  (0x8U)                                              /*!< GPTA_GPTCFORC: FOC3 Mask                */
#define GPTA_GPTCFORC_FOC3_SHIFT                 (3U)                                                /*!< GPTA_GPTCFORC: FOC3 Position            */
#define GPTA_GPTCFORC_FOC3(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCFORC_FOC3_SHIFT))&GPTA_GPTCFORC_FOC3_MASK) /*!< GPTA_GPTCFORC                           */
/* ------- GPTOC3M Bit Fields                       ------ */
#define GPTA_GPTOC3M_OC3M0_MASK                  (0x1U)                                              /*!< GPTA_GPTOC3M: OC3M0 Mask                */
#define GPTA_GPTOC3M_OC3M0_SHIFT                 (0U)                                                /*!< GPTA_GPTOC3M: OC3M0 Position            */
#define GPTA_GPTOC3M_OC3M0(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTOC3M_OC3M0_SHIFT))&GPTA_GPTOC3M_OC3M0_MASK) /*!< GPTA_GPTOC3M                            */
#define GPTA_GPTOC3M_OC3M1_MASK                  (0x2U)                                              /*!< GPTA_GPTOC3M: OC3M1 Mask                */
#define GPTA_GPTOC3M_OC3M1_SHIFT                 (1U)                                                /*!< GPTA_GPTOC3M: OC3M1 Position            */
#define GPTA_GPTOC3M_OC3M1(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTOC3M_OC3M1_SHIFT))&GPTA_GPTOC3M_OC3M1_MASK) /*!< GPTA_GPTOC3M                            */
#define GPTA_GPTOC3M_OC3M2_MASK                  (0x4U)                                              /*!< GPTA_GPTOC3M: OC3M2 Mask                */
#define GPTA_GPTOC3M_OC3M2_SHIFT                 (2U)                                                /*!< GPTA_GPTOC3M: OC3M2 Position            */
#define GPTA_GPTOC3M_OC3M2(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTOC3M_OC3M2_SHIFT))&GPTA_GPTOC3M_OC3M2_MASK) /*!< GPTA_GPTOC3M                            */
#define GPTA_GPTOC3M_OC3M3_MASK                  (0x8U)                                              /*!< GPTA_GPTOC3M: OC3M3 Mask                */
#define GPTA_GPTOC3M_OC3M3_SHIFT                 (3U)                                                /*!< GPTA_GPTOC3M: OC3M3 Position            */
#define GPTA_GPTOC3M_OC3M3(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTOC3M_OC3M3_SHIFT))&GPTA_GPTOC3M_OC3M3_MASK) /*!< GPTA_GPTOC3M                            */
/* ------- GPTOC3D Bit Fields                       ------ */
#define GPTA_GPTOC3D_OC3D0_MASK                  (0x1U)                                              /*!< GPTA_GPTOC3D: OC3D0 Mask                */
#define GPTA_GPTOC3D_OC3D0_SHIFT                 (0U)                                                /*!< GPTA_GPTOC3D: OC3D0 Position            */
#define GPTA_GPTOC3D_OC3D0(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTOC3D_OC3D0_SHIFT))&GPTA_GPTOC3D_OC3D0_MASK) /*!< GPTA_GPTOC3D                            */
#define GPTA_GPTOC3D_OC3D1_MASK                  (0x2U)                                              /*!< GPTA_GPTOC3D: OC3D1 Mask                */
#define GPTA_GPTOC3D_OC3D1_SHIFT                 (1U)                                                /*!< GPTA_GPTOC3D: OC3D1 Position            */
#define GPTA_GPTOC3D_OC3D1(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTOC3D_OC3D1_SHIFT))&GPTA_GPTOC3D_OC3D1_MASK) /*!< GPTA_GPTOC3D                            */
#define GPTA_GPTOC3D_OC3D2_MASK                  (0x4U)                                              /*!< GPTA_GPTOC3D: OC3D2 Mask                */
#define GPTA_GPTOC3D_OC3D2_SHIFT                 (2U)                                                /*!< GPTA_GPTOC3D: OC3D2 Position            */
#define GPTA_GPTOC3D_OC3D2(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTOC3D_OC3D2_SHIFT))&GPTA_GPTOC3D_OC3D2_MASK) /*!< GPTA_GPTOC3D                            */
#define GPTA_GPTOC3D_OC3D3_MASK                  (0x8U)                                              /*!< GPTA_GPTOC3D: OC3D3 Mask                */
#define GPTA_GPTOC3D_OC3D3_SHIFT                 (3U)                                                /*!< GPTA_GPTOC3D: OC3D3 Position            */
#define GPTA_GPTOC3D_OC3D3(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTOC3D_OC3D3_SHIFT))&GPTA_GPTOC3D_OC3D3_MASK) /*!< GPTA_GPTOC3D                            */
/* ------- GPTCNT Bit Fields                        ------ */
#define GPTA_GPTCNT_CNTR_MASK                    (0xFFFFU)                                           /*!< GPTA_GPTCNT: CNTR Mask                  */
#define GPTA_GPTCNT_CNTR_SHIFT                   (0U)                                                /*!< GPTA_GPTCNT: CNTR Position              */
#define GPTA_GPTCNT_CNTR(x)                      (((uint16_t)(((uint16_t)(x))<<GPTA_GPTCNT_CNTR_SHIFT))&GPTA_GPTCNT_CNTR_MASK) /*!< GPTA_GPTCNT                             */
/* ------- GPTSCR1 Bit Fields                       ------ */
#define GPTA_GPTSCR1_TFFCA_MASK                  (0x10U)                                             /*!< GPTA_GPTSCR1: TFFCA Mask                */
#define GPTA_GPTSCR1_TFFCA_SHIFT                 (4U)                                                /*!< GPTA_GPTSCR1: TFFCA Position            */
#define GPTA_GPTSCR1_TFFCA(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTSCR1_TFFCA_SHIFT))&GPTA_GPTSCR1_TFFCA_MASK) /*!< GPTA_GPTSCR1                            */
#define GPTA_GPTSCR1_GPTEN_MASK                  (0x80U)                                             /*!< GPTA_GPTSCR1: GPTEN Mask                */
#define GPTA_GPTSCR1_GPTEN_SHIFT                 (7U)                                                /*!< GPTA_GPTSCR1: GPTEN Position            */
#define GPTA_GPTSCR1_GPTEN(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTSCR1_GPTEN_SHIFT))&GPTA_GPTSCR1_GPTEN_MASK) /*!< GPTA_GPTSCR1                            */
/* ------- GPTTOV Bit Fields                        ------ */
#define GPTA_GPTTOV_TOV0_MASK                    (0x1U)                                              /*!< GPTA_GPTTOV: TOV0 Mask                  */
#define GPTA_GPTTOV_TOV0_SHIFT                   (0U)                                                /*!< GPTA_GPTTOV: TOV0 Position              */
#define GPTA_GPTTOV_TOV0(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTTOV_TOV0_SHIFT))&GPTA_GPTTOV_TOV0_MASK) /*!< GPTA_GPTTOV                             */
#define GPTA_GPTTOV_TOV1_MASK                    (0x2U)                                              /*!< GPTA_GPTTOV: TOV1 Mask                  */
#define GPTA_GPTTOV_TOV1_SHIFT                   (1U)                                                /*!< GPTA_GPTTOV: TOV1 Position              */
#define GPTA_GPTTOV_TOV1(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTTOV_TOV1_SHIFT))&GPTA_GPTTOV_TOV1_MASK) /*!< GPTA_GPTTOV                             */
#define GPTA_GPTTOV_TOV2_MASK                    (0x4U)                                              /*!< GPTA_GPTTOV: TOV2 Mask                  */
#define GPTA_GPTTOV_TOV2_SHIFT                   (2U)                                                /*!< GPTA_GPTTOV: TOV2 Position              */
#define GPTA_GPTTOV_TOV2(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTTOV_TOV2_SHIFT))&GPTA_GPTTOV_TOV2_MASK) /*!< GPTA_GPTTOV                             */
#define GPTA_GPTTOV_TOV3_MASK                    (0x8U)                                              /*!< GPTA_GPTTOV: TOV3 Mask                  */
#define GPTA_GPTTOV_TOV3_SHIFT                   (3U)                                                /*!< GPTA_GPTTOV: TOV3 Position              */
#define GPTA_GPTTOV_TOV3(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTTOV_TOV3_SHIFT))&GPTA_GPTTOV_TOV3_MASK) /*!< GPTA_GPTTOV                             */
/* ------- GPTCTL1 Bit Fields                       ------ */
#define GPTA_GPTCTL1_OL0_MASK                    (0x1U)                                              /*!< GPTA_GPTCTL1: OL0 Mask                  */
#define GPTA_GPTCTL1_OL0_SHIFT                   (0U)                                                /*!< GPTA_GPTCTL1: OL0 Position              */
#define GPTA_GPTCTL1_OL0(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL1_OL0_SHIFT))&GPTA_GPTCTL1_OL0_MASK) /*!< GPTA_GPTCTL1                            */
#define GPTA_GPTCTL1_OM0_MASK                    (0x2U)                                              /*!< GPTA_GPTCTL1: OM0 Mask                  */
#define GPTA_GPTCTL1_OM0_SHIFT                   (1U)                                                /*!< GPTA_GPTCTL1: OM0 Position              */
#define GPTA_GPTCTL1_OM0(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL1_OM0_SHIFT))&GPTA_GPTCTL1_OM0_MASK) /*!< GPTA_GPTCTL1                            */
#define GPTA_GPTCTL1_OL1_MASK                    (0x4U)                                              /*!< GPTA_GPTCTL1: OL1 Mask                  */
#define GPTA_GPTCTL1_OL1_SHIFT                   (2U)                                                /*!< GPTA_GPTCTL1: OL1 Position              */
#define GPTA_GPTCTL1_OL1(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL1_OL1_SHIFT))&GPTA_GPTCTL1_OL1_MASK) /*!< GPTA_GPTCTL1                            */
#define GPTA_GPTCTL1_OM1_MASK                    (0x8U)                                              /*!< GPTA_GPTCTL1: OM1 Mask                  */
#define GPTA_GPTCTL1_OM1_SHIFT                   (3U)                                                /*!< GPTA_GPTCTL1: OM1 Position              */
#define GPTA_GPTCTL1_OM1(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL1_OM1_SHIFT))&GPTA_GPTCTL1_OM1_MASK) /*!< GPTA_GPTCTL1                            */
#define GPTA_GPTCTL1_OL2_MASK                    (0x10U)                                             /*!< GPTA_GPTCTL1: OL2 Mask                  */
#define GPTA_GPTCTL1_OL2_SHIFT                   (4U)                                                /*!< GPTA_GPTCTL1: OL2 Position              */
#define GPTA_GPTCTL1_OL2(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL1_OL2_SHIFT))&GPTA_GPTCTL1_OL2_MASK) /*!< GPTA_GPTCTL1                            */
#define GPTA_GPTCTL1_OM2_MASK                    (0x20U)                                             /*!< GPTA_GPTCTL1: OM2 Mask                  */
#define GPTA_GPTCTL1_OM2_SHIFT                   (5U)                                                /*!< GPTA_GPTCTL1: OM2 Position              */
#define GPTA_GPTCTL1_OM2(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL1_OM2_SHIFT))&GPTA_GPTCTL1_OM2_MASK) /*!< GPTA_GPTCTL1                            */
#define GPTA_GPTCTL1_OL3_MASK                    (0x40U)                                             /*!< GPTA_GPTCTL1: OL3 Mask                  */
#define GPTA_GPTCTL1_OL3_SHIFT                   (6U)                                                /*!< GPTA_GPTCTL1: OL3 Position              */
#define GPTA_GPTCTL1_OL3(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL1_OL3_SHIFT))&GPTA_GPTCTL1_OL3_MASK) /*!< GPTA_GPTCTL1                            */
#define GPTA_GPTCTL1_OM3_MASK                    (0x80U)                                             /*!< GPTA_GPTCTL1: OM3 Mask                  */
#define GPTA_GPTCTL1_OM3_SHIFT                   (7U)                                                /*!< GPTA_GPTCTL1: OM3 Position              */
#define GPTA_GPTCTL1_OM3(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL1_OM3_SHIFT))&GPTA_GPTCTL1_OM3_MASK) /*!< GPTA_GPTCTL1                            */
/* ------- GPTCTL2 Bit Fields                       ------ */
#define GPTA_GPTCTL2_EDG0A_MASK                  (0x1U)                                              /*!< GPTA_GPTCTL2: EDG0A Mask                */
#define GPTA_GPTCTL2_EDG0A_SHIFT                 (0U)                                                /*!< GPTA_GPTCTL2: EDG0A Position            */
#define GPTA_GPTCTL2_EDG0A(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL2_EDG0A_SHIFT))&GPTA_GPTCTL2_EDG0A_MASK) /*!< GPTA_GPTCTL2                            */
#define GPTA_GPTCTL2_EDG0B_MASK                  (0x2U)                                              /*!< GPTA_GPTCTL2: EDG0B Mask                */
#define GPTA_GPTCTL2_EDG0B_SHIFT                 (1U)                                                /*!< GPTA_GPTCTL2: EDG0B Position            */
#define GPTA_GPTCTL2_EDG0B(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL2_EDG0B_SHIFT))&GPTA_GPTCTL2_EDG0B_MASK) /*!< GPTA_GPTCTL2                            */
#define GPTA_GPTCTL2_EDG1A_MASK                  (0x4U)                                              /*!< GPTA_GPTCTL2: EDG1A Mask                */
#define GPTA_GPTCTL2_EDG1A_SHIFT                 (2U)                                                /*!< GPTA_GPTCTL2: EDG1A Position            */
#define GPTA_GPTCTL2_EDG1A(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL2_EDG1A_SHIFT))&GPTA_GPTCTL2_EDG1A_MASK) /*!< GPTA_GPTCTL2                            */
#define GPTA_GPTCTL2_EDG1B_MASK                  (0x8U)                                              /*!< GPTA_GPTCTL2: EDG1B Mask                */
#define GPTA_GPTCTL2_EDG1B_SHIFT                 (3U)                                                /*!< GPTA_GPTCTL2: EDG1B Position            */
#define GPTA_GPTCTL2_EDG1B(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL2_EDG1B_SHIFT))&GPTA_GPTCTL2_EDG1B_MASK) /*!< GPTA_GPTCTL2                            */
#define GPTA_GPTCTL2_EDG2A_MASK                  (0x10U)                                             /*!< GPTA_GPTCTL2: EDG2A Mask                */
#define GPTA_GPTCTL2_EDG2A_SHIFT                 (4U)                                                /*!< GPTA_GPTCTL2: EDG2A Position            */
#define GPTA_GPTCTL2_EDG2A(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL2_EDG2A_SHIFT))&GPTA_GPTCTL2_EDG2A_MASK) /*!< GPTA_GPTCTL2                            */
#define GPTA_GPTCTL2_EDG2B_MASK                  (0x20U)                                             /*!< GPTA_GPTCTL2: EDG2B Mask                */
#define GPTA_GPTCTL2_EDG2B_SHIFT                 (5U)                                                /*!< GPTA_GPTCTL2: EDG2B Position            */
#define GPTA_GPTCTL2_EDG2B(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL2_EDG2B_SHIFT))&GPTA_GPTCTL2_EDG2B_MASK) /*!< GPTA_GPTCTL2                            */
#define GPTA_GPTCTL2_EDG3A_MASK                  (0x40U)                                             /*!< GPTA_GPTCTL2: EDG3A Mask                */
#define GPTA_GPTCTL2_EDG3A_SHIFT                 (6U)                                                /*!< GPTA_GPTCTL2: EDG3A Position            */
#define GPTA_GPTCTL2_EDG3A(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL2_EDG3A_SHIFT))&GPTA_GPTCTL2_EDG3A_MASK) /*!< GPTA_GPTCTL2                            */
#define GPTA_GPTCTL2_EDG3B_MASK                  (0x80U)                                             /*!< GPTA_GPTCTL2: EDG3B Mask                */
#define GPTA_GPTCTL2_EDG3B_SHIFT                 (7U)                                                /*!< GPTA_GPTCTL2: EDG3B Position            */
#define GPTA_GPTCTL2_EDG3B(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTCTL2_EDG3B_SHIFT))&GPTA_GPTCTL2_EDG3B_MASK) /*!< GPTA_GPTCTL2                            */
/* ------- GPTIE Bit Fields                         ------ */
#define GPTA_GPTIE_CI0_MASK                      (0x1U)                                              /*!< GPTA_GPTIE: CI0 Mask                    */
#define GPTA_GPTIE_CI0_SHIFT                     (0U)                                                /*!< GPTA_GPTIE: CI0 Position                */
#define GPTA_GPTIE_CI0(x)                        (((uint8_t)(((uint8_t)(x))<<GPTA_GPTIE_CI0_SHIFT))&GPTA_GPTIE_CI0_MASK) /*!< GPTA_GPTIE                              */
#define GPTA_GPTIE_CI1_MASK                      (0x2U)                                              /*!< GPTA_GPTIE: CI1 Mask                    */
#define GPTA_GPTIE_CI1_SHIFT                     (1U)                                                /*!< GPTA_GPTIE: CI1 Position                */
#define GPTA_GPTIE_CI1(x)                        (((uint8_t)(((uint8_t)(x))<<GPTA_GPTIE_CI1_SHIFT))&GPTA_GPTIE_CI1_MASK) /*!< GPTA_GPTIE                              */
#define GPTA_GPTIE_CI2_MASK                      (0x4U)                                              /*!< GPTA_GPTIE: CI2 Mask                    */
#define GPTA_GPTIE_CI2_SHIFT                     (2U)                                                /*!< GPTA_GPTIE: CI2 Position                */
#define GPTA_GPTIE_CI2(x)                        (((uint8_t)(((uint8_t)(x))<<GPTA_GPTIE_CI2_SHIFT))&GPTA_GPTIE_CI2_MASK) /*!< GPTA_GPTIE                              */
#define GPTA_GPTIE_CI3_MASK                      (0x8U)                                              /*!< GPTA_GPTIE: CI3 Mask                    */
#define GPTA_GPTIE_CI3_SHIFT                     (3U)                                                /*!< GPTA_GPTIE: CI3 Position                */
#define GPTA_GPTIE_CI3(x)                        (((uint8_t)(((uint8_t)(x))<<GPTA_GPTIE_CI3_SHIFT))&GPTA_GPTIE_CI3_MASK) /*!< GPTA_GPTIE                              */
/* ------- GPTSCR2 Bit Fields                       ------ */
#define GPTA_GPTSCR2_PR_MASK                     (0x7U)                                              /*!< GPTA_GPTSCR2: PR Mask                   */
#define GPTA_GPTSCR2_PR_SHIFT                    (0U)                                                /*!< GPTA_GPTSCR2: PR Position               */
#define GPTA_GPTSCR2_PR(x)                       (((uint8_t)(((uint8_t)(x))<<GPTA_GPTSCR2_PR_SHIFT))&GPTA_GPTSCR2_PR_MASK) /*!< GPTA_GPTSCR2                            */
#define GPTA_GPTSCR2_TCRE_MASK                   (0x8U)                                              /*!< GPTA_GPTSCR2: TCRE Mask                 */
#define GPTA_GPTSCR2_TCRE_SHIFT                  (3U)                                                /*!< GPTA_GPTSCR2: TCRE Position             */
#define GPTA_GPTSCR2_TCRE(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTSCR2_TCRE_SHIFT))&GPTA_GPTSCR2_TCRE_MASK) /*!< GPTA_GPTSCR2                            */
#define GPTA_GPTSCR2_RDPT_MASK                   (0x10U)                                             /*!< GPTA_GPTSCR2: RDPT Mask                 */
#define GPTA_GPTSCR2_RDPT_SHIFT                  (4U)                                                /*!< GPTA_GPTSCR2: RDPT Position             */
#define GPTA_GPTSCR2_RDPT(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTSCR2_RDPT_SHIFT))&GPTA_GPTSCR2_RDPT_MASK) /*!< GPTA_GPTSCR2                            */
#define GPTA_GPTSCR2_PUPT_MASK                   (0x20U)                                             /*!< GPTA_GPTSCR2: PUPT Mask                 */
#define GPTA_GPTSCR2_PUPT_SHIFT                  (5U)                                                /*!< GPTA_GPTSCR2: PUPT Position             */
#define GPTA_GPTSCR2_PUPT(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTSCR2_PUPT_SHIFT))&GPTA_GPTSCR2_PUPT_MASK) /*!< GPTA_GPTSCR2                            */
#define GPTA_GPTSCR2_TOI_MASK                    (0x80U)                                             /*!< GPTA_GPTSCR2: TOI Mask                  */
#define GPTA_GPTSCR2_TOI_SHIFT                   (7U)                                                /*!< GPTA_GPTSCR2: TOI Position              */
#define GPTA_GPTSCR2_TOI(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTSCR2_TOI_SHIFT))&GPTA_GPTSCR2_TOI_MASK) /*!< GPTA_GPTSCR2                            */
/* ------- GPTFLG1 Bit Fields                       ------ */
#define GPTA_GPTFLG1_CF0_MASK                    (0x1U)                                              /*!< GPTA_GPTFLG1: CF0 Mask                  */
#define GPTA_GPTFLG1_CF0_SHIFT                   (0U)                                                /*!< GPTA_GPTFLG1: CF0 Position              */
#define GPTA_GPTFLG1_CF0(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTFLG1_CF0_SHIFT))&GPTA_GPTFLG1_CF0_MASK) /*!< GPTA_GPTFLG1                            */
#define GPTA_GPTFLG1_CF1_MASK                    (0x2U)                                              /*!< GPTA_GPTFLG1: CF1 Mask                  */
#define GPTA_GPTFLG1_CF1_SHIFT                   (1U)                                                /*!< GPTA_GPTFLG1: CF1 Position              */
#define GPTA_GPTFLG1_CF1(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTFLG1_CF1_SHIFT))&GPTA_GPTFLG1_CF1_MASK) /*!< GPTA_GPTFLG1                            */
#define GPTA_GPTFLG1_CF2_MASK                    (0x4U)                                              /*!< GPTA_GPTFLG1: CF2 Mask                  */
#define GPTA_GPTFLG1_CF2_SHIFT                   (2U)                                                /*!< GPTA_GPTFLG1: CF2 Position              */
#define GPTA_GPTFLG1_CF2(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTFLG1_CF2_SHIFT))&GPTA_GPTFLG1_CF2_MASK) /*!< GPTA_GPTFLG1                            */
#define GPTA_GPTFLG1_CF3_MASK                    (0x8U)                                              /*!< GPTA_GPTFLG1: CF3 Mask                  */
#define GPTA_GPTFLG1_CF3_SHIFT                   (3U)                                                /*!< GPTA_GPTFLG1: CF3 Position              */
#define GPTA_GPTFLG1_CF3(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTFLG1_CF3_SHIFT))&GPTA_GPTFLG1_CF3_MASK) /*!< GPTA_GPTFLG1                            */
/* ------- GPTFLG2 Bit Fields                       ------ */
#define GPTA_GPTFLG2_TOF_MASK                    (0x80U)                                             /*!< GPTA_GPTFLG2: TOF Mask                  */
#define GPTA_GPTFLG2_TOF_SHIFT                   (7U)                                                /*!< GPTA_GPTFLG2: TOF Position              */
#define GPTA_GPTFLG2_TOF(x)                      (((uint8_t)(((uint8_t)(x))<<GPTA_GPTFLG2_TOF_SHIFT))&GPTA_GPTFLG2_TOF_MASK) /*!< GPTA_GPTFLG2                            */
/* ------- GPTC Bit Fields                          ------ */
#define GPTA_GPTC_CCNT_MASK                      (0xFFFFU)                                           /*!< GPTA_GPTC: CCNT Mask                    */
#define GPTA_GPTC_CCNT_SHIFT                     (0U)                                                /*!< GPTA_GPTC: CCNT Position                */
#define GPTA_GPTC_CCNT(x)                        (((uint16_t)(((uint16_t)(x))<<GPTA_GPTC_CCNT_SHIFT))&GPTA_GPTC_CCNT_MASK) /*!< GPTA_GPTC                               */
/* ------- GPTPACTL Bit Fields                      ------ */
#define GPTA_GPTPACTL_PAI_MASK                   (0x1U)                                              /*!< GPTA_GPTPACTL: PAI Mask                 */
#define GPTA_GPTPACTL_PAI_SHIFT                  (0U)                                                /*!< GPTA_GPTPACTL: PAI Position             */
#define GPTA_GPTPACTL_PAI(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPACTL_PAI_SHIFT))&GPTA_GPTPACTL_PAI_MASK) /*!< GPTA_GPTPACTL                           */
#define GPTA_GPTPACTL_PAOVI_MASK                 (0x2U)                                              /*!< GPTA_GPTPACTL: PAOVI Mask               */
#define GPTA_GPTPACTL_PAOVI_SHIFT                (1U)                                                /*!< GPTA_GPTPACTL: PAOVI Position           */
#define GPTA_GPTPACTL_PAOVI(x)                   (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPACTL_PAOVI_SHIFT))&GPTA_GPTPACTL_PAOVI_MASK) /*!< GPTA_GPTPACTL                           */
#define GPTA_GPTPACTL_CLK_MASK                   (0xCU)                                              /*!< GPTA_GPTPACTL: CLK Mask                 */
#define GPTA_GPTPACTL_CLK_SHIFT                  (2U)                                                /*!< GPTA_GPTPACTL: CLK Position             */
#define GPTA_GPTPACTL_CLK(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPACTL_CLK_SHIFT))&GPTA_GPTPACTL_CLK_MASK) /*!< GPTA_GPTPACTL                           */
#define GPTA_GPTPACTL_PEDGE_MASK                 (0x10U)                                             /*!< GPTA_GPTPACTL: PEDGE Mask               */
#define GPTA_GPTPACTL_PEDGE_SHIFT                (4U)                                                /*!< GPTA_GPTPACTL: PEDGE Position           */
#define GPTA_GPTPACTL_PEDGE(x)                   (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPACTL_PEDGE_SHIFT))&GPTA_GPTPACTL_PEDGE_MASK) /*!< GPTA_GPTPACTL                           */
#define GPTA_GPTPACTL_PAMOD_MASK                 (0x20U)                                             /*!< GPTA_GPTPACTL: PAMOD Mask               */
#define GPTA_GPTPACTL_PAMOD_SHIFT                (5U)                                                /*!< GPTA_GPTPACTL: PAMOD Position           */
#define GPTA_GPTPACTL_PAMOD(x)                   (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPACTL_PAMOD_SHIFT))&GPTA_GPTPACTL_PAMOD_MASK) /*!< GPTA_GPTPACTL                           */
#define GPTA_GPTPACTL_PAE_MASK                   (0x40U)                                             /*!< GPTA_GPTPACTL: PAE Mask                 */
#define GPTA_GPTPACTL_PAE_SHIFT                  (6U)                                                /*!< GPTA_GPTPACTL: PAE Position             */
#define GPTA_GPTPACTL_PAE(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPACTL_PAE_SHIFT))&GPTA_GPTPACTL_PAE_MASK) /*!< GPTA_GPTPACTL                           */
/* ------- GPTPAFLG Bit Fields                      ------ */
#define GPTA_GPTPAFLG_PAIF_MASK                  (0x1U)                                              /*!< GPTA_GPTPAFLG: PAIF Mask                */
#define GPTA_GPTPAFLG_PAIF_SHIFT                 (0U)                                                /*!< GPTA_GPTPAFLG: PAIF Position            */
#define GPTA_GPTPAFLG_PAIF(x)                    (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPAFLG_PAIF_SHIFT))&GPTA_GPTPAFLG_PAIF_MASK) /*!< GPTA_GPTPAFLG                           */
#define GPTA_GPTPAFLG_PAOVF_MASK                 (0x2U)                                              /*!< GPTA_GPTPAFLG: PAOVF Mask               */
#define GPTA_GPTPAFLG_PAOVF_SHIFT                (1U)                                                /*!< GPTA_GPTPAFLG: PAOVF Position           */
#define GPTA_GPTPAFLG_PAOVF(x)                   (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPAFLG_PAOVF_SHIFT))&GPTA_GPTPAFLG_PAOVF_MASK) /*!< GPTA_GPTPAFLG                           */
/* ------- GPTPACNT Bit Fields                      ------ */
#define GPTA_GPTPACNT_PACNT_MASK                 (0xFFFFU)                                           /*!< GPTA_GPTPACNT: PACNT Mask               */
#define GPTA_GPTPACNT_PACNT_SHIFT                (0U)                                                /*!< GPTA_GPTPACNT: PACNT Position           */
#define GPTA_GPTPACNT_PACNT(x)                   (((uint16_t)(((uint16_t)(x))<<GPTA_GPTPACNT_PACNT_SHIFT))&GPTA_GPTPACNT_PACNT_MASK) /*!< GPTA_GPTPACNT                           */
/* ------- GPTPORT Bit Fields                       ------ */
#define GPTA_GPTPORT_PORTT0_MASK                 (0x1U)                                              /*!< GPTA_GPTPORT: PORTT0 Mask               */
#define GPTA_GPTPORT_PORTT0_SHIFT                (0U)                                                /*!< GPTA_GPTPORT: PORTT0 Position           */
#define GPTA_GPTPORT_PORTT0(x)                   (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPORT_PORTT0_SHIFT))&GPTA_GPTPORT_PORTT0_MASK) /*!< GPTA_GPTPORT                            */
#define GPTA_GPTPORT_PORTT1_MASK                 (0x2U)                                              /*!< GPTA_GPTPORT: PORTT1 Mask               */
#define GPTA_GPTPORT_PORTT1_SHIFT                (1U)                                                /*!< GPTA_GPTPORT: PORTT1 Position           */
#define GPTA_GPTPORT_PORTT1(x)                   (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPORT_PORTT1_SHIFT))&GPTA_GPTPORT_PORTT1_MASK) /*!< GPTA_GPTPORT                            */
#define GPTA_GPTPORT_PORTT2_MASK                 (0x4U)                                              /*!< GPTA_GPTPORT: PORTT2 Mask               */
#define GPTA_GPTPORT_PORTT2_SHIFT                (2U)                                                /*!< GPTA_GPTPORT: PORTT2 Position           */
#define GPTA_GPTPORT_PORTT2(x)                   (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPORT_PORTT2_SHIFT))&GPTA_GPTPORT_PORTT2_MASK) /*!< GPTA_GPTPORT                            */
#define GPTA_GPTPORT_PORTT3_MASK                 (0x8U)                                              /*!< GPTA_GPTPORT: PORTT3 Mask               */
#define GPTA_GPTPORT_PORTT3_SHIFT                (3U)                                                /*!< GPTA_GPTPORT: PORTT3 Position           */
#define GPTA_GPTPORT_PORTT3(x)                   (((uint8_t)(((uint8_t)(x))<<GPTA_GPTPORT_PORTT3_SHIFT))&GPTA_GPTPORT_PORTT3_MASK) /*!< GPTA_GPTPORT                            */
/* ------- GPTDDR Bit Fields                        ------ */
#define GPTA_GPTDDR_DDRT0_MASK                   (0x1U)                                              /*!< GPTA_GPTDDR: DDRT0 Mask                 */
#define GPTA_GPTDDR_DDRT0_SHIFT                  (0U)                                                /*!< GPTA_GPTDDR: DDRT0 Position             */
#define GPTA_GPTDDR_DDRT0(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTDDR_DDRT0_SHIFT))&GPTA_GPTDDR_DDRT0_MASK) /*!< GPTA_GPTDDR                             */
#define GPTA_GPTDDR_DDRT1_MASK                   (0x2U)                                              /*!< GPTA_GPTDDR: DDRT1 Mask                 */
#define GPTA_GPTDDR_DDRT1_SHIFT                  (1U)                                                /*!< GPTA_GPTDDR: DDRT1 Position             */
#define GPTA_GPTDDR_DDRT1(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTDDR_DDRT1_SHIFT))&GPTA_GPTDDR_DDRT1_MASK) /*!< GPTA_GPTDDR                             */
#define GPTA_GPTDDR_DDRT2_MASK                   (0x4U)                                              /*!< GPTA_GPTDDR: DDRT2 Mask                 */
#define GPTA_GPTDDR_DDRT2_SHIFT                  (2U)                                                /*!< GPTA_GPTDDR: DDRT2 Position             */
#define GPTA_GPTDDR_DDRT2(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTDDR_DDRT2_SHIFT))&GPTA_GPTDDR_DDRT2_MASK) /*!< GPTA_GPTDDR                             */
#define GPTA_GPTDDR_DDRT3_MASK                   (0x8U)                                              /*!< GPTA_GPTDDR: DDRT3 Mask                 */
#define GPTA_GPTDDR_DDRT3_SHIFT                  (3U)                                                /*!< GPTA_GPTDDR: DDRT3 Position             */
#define GPTA_GPTDDR_DDRT3(x)                     (((uint8_t)(((uint8_t)(x))<<GPTA_GPTDDR_DDRT3_SHIFT))&GPTA_GPTDDR_DDRT3_MASK) /*!< GPTA_GPTDDR                             */
/**
 * @} */ /* End group GPTA_Register_Masks_GROUP 
 */

/* GPTA - Peripheral instance base addresses */
#define GPTA_BasePtr                   0x401A0000UL //!< Peripheral base address
#define GPTA                           ((GPTA_Type *) GPTA_BasePtr) //!< Freescale base pointer
#define GPTA_BASE_PTR                  (GPTA) //!< Freescale style base pointer
/**
 * @} */ /* End group GPTA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:MCF522xx_I2C0)            ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */
/**
* @addtogroup I2C_structs_GROUP I2C struct
* @brief Struct for I2C
* @{
*/
typedef struct {                                /*       I2C0 Structure                                               */
   __IO uint8_t   I2ADR;                        /**< 0000: Address Register                                             */
        uint8_t   RESERVED_0[3];               
   __IO uint8_t   I2FDR;                        /**< 0004: Frequency Divider Register                                   */
        uint8_t   RESERVED_1[3];               
   __IO uint8_t   I2CR;                         /**< 0008: Control Register                                             */
        uint8_t   RESERVED_2[3];               
   __IO uint8_t   I2SR;                         /**< 000C: Status Register                                              */
        uint8_t   RESERVED_3[3];               
   __IO uint8_t   I2DR;                         /**< 0010: Data I/O Register                                            */
} I2C_Type;

/**
 * @} */ /* End group I2C_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2C_Register_Masks_GROUP I2C Register Masks
* @brief Register Masks for I2C
* @{
*/
/* ------- I2ADR Bit Fields                         ------ */
#define I2C_I2ADR_ADR_MASK                       (0xFEU)                                             /*!< I2C0_I2ADR: ADR Mask                    */
#define I2C_I2ADR_ADR_SHIFT                      (1U)                                                /*!< I2C0_I2ADR: ADR Position                */
#define I2C_I2ADR_ADR(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2ADR_ADR_SHIFT))&I2C_I2ADR_ADR_MASK) /*!< I2C0_I2ADR                              */
/* ------- I2FDR Bit Fields                         ------ */
#define I2C_I2FDR_IC_MASK                        (0x3FU)                                             /*!< I2C0_I2FDR: IC Mask                     */
#define I2C_I2FDR_IC_SHIFT                       (0U)                                                /*!< I2C0_I2FDR: IC Position                 */
#define I2C_I2FDR_IC(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2FDR_IC_SHIFT))&I2C_I2FDR_IC_MASK) /*!< I2C0_I2FDR                              */
/* ------- I2CR Bit Fields                          ------ */
#define I2C_I2CR_RSTA_MASK                       (0x4U)                                              /*!< I2C0_I2CR: RSTA Mask                    */
#define I2C_I2CR_RSTA_SHIFT                      (2U)                                                /*!< I2C0_I2CR: RSTA Position                */
#define I2C_I2CR_RSTA(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2CR_RSTA_SHIFT))&I2C_I2CR_RSTA_MASK) /*!< I2C0_I2CR                               */
#define I2C_I2CR_TXAK_MASK                       (0x8U)                                              /*!< I2C0_I2CR: TXAK Mask                    */
#define I2C_I2CR_TXAK_SHIFT                      (3U)                                                /*!< I2C0_I2CR: TXAK Position                */
#define I2C_I2CR_TXAK(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2CR_TXAK_SHIFT))&I2C_I2CR_TXAK_MASK) /*!< I2C0_I2CR                               */
#define I2C_I2CR_MTX_MASK                        (0x10U)                                             /*!< I2C0_I2CR: MTX Mask                     */
#define I2C_I2CR_MTX_SHIFT                       (4U)                                                /*!< I2C0_I2CR: MTX Position                 */
#define I2C_I2CR_MTX(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2CR_MTX_SHIFT))&I2C_I2CR_MTX_MASK) /*!< I2C0_I2CR                               */
#define I2C_I2CR_MSTA_MASK                       (0x20U)                                             /*!< I2C0_I2CR: MSTA Mask                    */
#define I2C_I2CR_MSTA_SHIFT                      (5U)                                                /*!< I2C0_I2CR: MSTA Position                */
#define I2C_I2CR_MSTA(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2CR_MSTA_SHIFT))&I2C_I2CR_MSTA_MASK) /*!< I2C0_I2CR                               */
#define I2C_I2CR_IIEN_MASK                       (0x40U)                                             /*!< I2C0_I2CR: IIEN Mask                    */
#define I2C_I2CR_IIEN_SHIFT                      (6U)                                                /*!< I2C0_I2CR: IIEN Position                */
#define I2C_I2CR_IIEN(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2CR_IIEN_SHIFT))&I2C_I2CR_IIEN_MASK) /*!< I2C0_I2CR                               */
#define I2C_I2CR_IEN_MASK                        (0x80U)                                             /*!< I2C0_I2CR: IEN Mask                     */
#define I2C_I2CR_IEN_SHIFT                       (7U)                                                /*!< I2C0_I2CR: IEN Position                 */
#define I2C_I2CR_IEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2CR_IEN_SHIFT))&I2C_I2CR_IEN_MASK) /*!< I2C0_I2CR                               */
/* ------- I2SR Bit Fields                          ------ */
#define I2C_I2SR_RXAK_MASK                       (0x1U)                                              /*!< I2C0_I2SR: RXAK Mask                    */
#define I2C_I2SR_RXAK_SHIFT                      (0U)                                                /*!< I2C0_I2SR: RXAK Position                */
#define I2C_I2SR_RXAK(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2SR_RXAK_SHIFT))&I2C_I2SR_RXAK_MASK) /*!< I2C0_I2SR                               */
#define I2C_I2SR_IIF_MASK                        (0x2U)                                              /*!< I2C0_I2SR: IIF Mask                     */
#define I2C_I2SR_IIF_SHIFT                       (1U)                                                /*!< I2C0_I2SR: IIF Position                 */
#define I2C_I2SR_IIF(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2SR_IIF_SHIFT))&I2C_I2SR_IIF_MASK) /*!< I2C0_I2SR                               */
#define I2C_I2SR_SRW_MASK                        (0x4U)                                              /*!< I2C0_I2SR: SRW Mask                     */
#define I2C_I2SR_SRW_SHIFT                       (2U)                                                /*!< I2C0_I2SR: SRW Position                 */
#define I2C_I2SR_SRW(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2SR_SRW_SHIFT))&I2C_I2SR_SRW_MASK) /*!< I2C0_I2SR                               */
#define I2C_I2SR_IAL_MASK                        (0x10U)                                             /*!< I2C0_I2SR: IAL Mask                     */
#define I2C_I2SR_IAL_SHIFT                       (4U)                                                /*!< I2C0_I2SR: IAL Position                 */
#define I2C_I2SR_IAL(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2SR_IAL_SHIFT))&I2C_I2SR_IAL_MASK) /*!< I2C0_I2SR                               */
#define I2C_I2SR_IBB_MASK                        (0x20U)                                             /*!< I2C0_I2SR: IBB Mask                     */
#define I2C_I2SR_IBB_SHIFT                       (5U)                                                /*!< I2C0_I2SR: IBB Position                 */
#define I2C_I2SR_IBB(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2SR_IBB_SHIFT))&I2C_I2SR_IBB_MASK) /*!< I2C0_I2SR                               */
#define I2C_I2SR_IAAS_MASK                       (0x40U)                                             /*!< I2C0_I2SR: IAAS Mask                    */
#define I2C_I2SR_IAAS_SHIFT                      (6U)                                                /*!< I2C0_I2SR: IAAS Position                */
#define I2C_I2SR_IAAS(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2SR_IAAS_SHIFT))&I2C_I2SR_IAAS_MASK) /*!< I2C0_I2SR                               */
#define I2C_I2SR_ICF_MASK                        (0x80U)                                             /*!< I2C0_I2SR: ICF Mask                     */
#define I2C_I2SR_ICF_SHIFT                       (7U)                                                /*!< I2C0_I2SR: ICF Position                 */
#define I2C_I2SR_ICF(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_I2SR_ICF_SHIFT))&I2C_I2SR_ICF_MASK) /*!< I2C0_I2SR                               */
/* ------- I2DR Bit Fields                          ------ */
#define I2C_I2DR_DATA_MASK                       (0xFFU)                                             /*!< I2C0_I2DR: DATA Mask                    */
#define I2C_I2DR_DATA_SHIFT                      (0U)                                                /*!< I2C0_I2DR: DATA Position                */
#define I2C_I2DR_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_I2DR_DATA_SHIFT))&I2C_I2DR_DATA_MASK) /*!< I2C0_I2DR                               */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40000300UL //!< Peripheral base address
#define I2C0                           ((I2C_Type *) I2C0_BasePtr) //!< Freescale base pointer
#define I2C0_BASE_PTR                  (I2C0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup INTC_Peripheral_access_layer_GROUP INTC Peripheral Access Layer
* @brief C Struct for INTC
* @{
*/

/* ================================================================================ */
/* ================           INTC0 (file:MCF522xx_INTC0)          ================ */
/* ================================================================================ */

/**
 * @brief Interrupt Controller Module
 */
/**
* @addtogroup INTC_structs_GROUP INTC struct
* @brief Struct for INTC
* @{
*/
typedef struct {                                /*       INTC0 Structure                                              */
   __I  uint32_t  IPRH;                         /**< 0000: Interrupt Pending Register High                              */
   __I  uint32_t  IPRL;                         /**< 0004: Interrupt Pending Register Low                               */
   __IO uint32_t  IMRH;                         /**< 0008: Interrupt Mask Register High                                 */
   __IO uint32_t  IMRL;                         /**< 000C: Interrupt Mask Register Low                                  */
   __IO uint32_t  INTFRCH;                      /**< 0010: Interrupt Force Register High                                */
   __IO uint32_t  INTFRCL;                      /**< 0014: Interrupt Force Register Low                                 */
   __I  uint8_t   IRLR;                         /**< 0018: Interrupt Request Level Register                             */
   __I  uint8_t   IACKLPR;                      /**< 0019: Interrupt Acknowledge Level and Priority Register            */
        uint8_t   RESERVED_0[39];              
   __I  uint8_t   ICR1;                         /**< 0041: Interrupt Control Register 1                                 */
   __I  uint8_t   ICR2;                         /**< 0042: Interrupt Control Register 2                                 */
   __I  uint8_t   ICR3;                         /**< 0043: Interrupt Control Register 3                                 */
   __I  uint8_t   ICR4;                         /**< 0044: Interrupt Control Register 4                                 */
   __I  uint8_t   ICR5;                         /**< 0045: Interrupt Control Register 5                                 */
   __I  uint8_t   ICR6;                         /**< 0046: Interrupt Control Register 6                                 */
   __I  uint8_t   ICR7;                         /**< 0047: Interrupt Control Register 7                                 */
   __IO uint8_t   ICR8;                         /**< 0048: Interrupt Control Register 8                                 */
   __IO uint8_t   ICR9;                         /**< 0049: Interrupt Control Register 9                                 */
   __IO uint8_t   ICR10;                        /**< 004A: Interrupt Control Register 10                                */
   __IO uint8_t   ICR11;                        /**< 004B: Interrupt Control Register 11                                */
   __IO uint8_t   ICR12;                        /**< 004C: Interrupt Control Register 12                                */
   __IO uint8_t   ICR13;                        /**< 004D: Interrupt Control Register 13                                */
   __IO uint8_t   ICR14;                        /**< 004E: Interrupt Control Register 14                                */
   __IO uint8_t   ICR15;                        /**< 004F: Interrupt Control Register 15                                */
   __IO uint8_t   ICR16;                        /**< 0050: Interrupt Control Register 16                                */
   __IO uint8_t   ICR17;                        /**< 0051: Interrupt Control Register 17                                */
   __IO uint8_t   ICR18;                        /**< 0052: Interrupt Control Register 18                                */
   __IO uint8_t   ICR19;                        /**< 0053: Interrupt Control Register 19                                */
   __IO uint8_t   ICR20;                        /**< 0054: Interrupt Control Register 20                                */
   __IO uint8_t   ICR21;                        /**< 0055: Interrupt Control Register 21                                */
   __IO uint8_t   ICR22;                        /**< 0056: Interrupt Control Register 22                                */
   __IO uint8_t   ICR23;                        /**< 0057: Interrupt Control Register 23                                */
   __IO uint8_t   ICR24;                        /**< 0058: Interrupt Control Register 24                                */
   __IO uint8_t   ICR25;                        /**< 0059: Interrupt Control Register 25                                */
   __IO uint8_t   ICR26;                        /**< 005A: Interrupt Control Register 26                                */
   __IO uint8_t   ICR27;                        /**< 005B: Interrupt Control Register 27                                */
   __IO uint8_t   ICR28;                        /**< 005C: Interrupt Control Register 28                                */
   __IO uint8_t   ICR29;                        /**< 005D: Interrupt Control Register 29                                */
   __IO uint8_t   ICR30;                        /**< 005E: Interrupt Control Register 30                                */
   __IO uint8_t   ICR31;                        /**< 005F: Interrupt Control Register 31                                */
   __IO uint8_t   ICR32;                        /**< 0060: Interrupt Control Register 32                                */
   __IO uint8_t   ICR33;                        /**< 0061: Interrupt Control Register 33                                */
   __IO uint8_t   ICR34;                        /**< 0062: Interrupt Control Register 34                                */
   __IO uint8_t   ICR35;                        /**< 0063: Interrupt Control Register 35                                */
   __IO uint8_t   ICR36;                        /**< 0064: Interrupt Control Register 36                                */
   __IO uint8_t   ICR37;                        /**< 0065: Interrupt Control Register 37                                */
   __IO uint8_t   ICR38;                        /**< 0066: Interrupt Control Register 38                                */
   __IO uint8_t   ICR39;                        /**< 0067: Interrupt Control Register 39                                */
   __IO uint8_t   ICR40;                        /**< 0068: Interrupt Control Register 40                                */
   __IO uint8_t   ICR41;                        /**< 0069: Interrupt Control Register 41                                */
   __IO uint8_t   ICR42;                        /**< 006A: Interrupt Control Register 42                                */
   __IO uint8_t   ICR43;                        /**< 006B: Interrupt Control Register 43                                */
   __IO uint8_t   ICR44;                        /**< 006C: Interrupt Control Register 44                                */
   __IO uint8_t   ICR45;                        /**< 006D: Interrupt Control Register 45                                */
   __IO uint8_t   ICR46;                        /**< 006E: Interrupt Control Register 46                                */
   __IO uint8_t   ICR47;                        /**< 006F: Interrupt Control Register 47                                */
   __IO uint8_t   ICR48;                        /**< 0070: Interrupt Control Register 48                                */
   __IO uint8_t   ICR49;                        /**< 0071: Interrupt Control Register 49                                */
   __IO uint8_t   ICR50;                        /**< 0072: Interrupt Control Register 50                                */
   __IO uint8_t   ICR51;                        /**< 0073: Interrupt Control Register 51                                */
   __IO uint8_t   ICR52;                        /**< 0074: Interrupt Control Register 52                                */
   __IO uint8_t   ICR53;                        /**< 0075: Interrupt Control Register 53                                */
   __IO uint8_t   ICR54;                        /**< 0076: Interrupt Control Register 54                                */
   __IO uint8_t   ICR55;                        /**< 0077: Interrupt Control Register 55                                */
   __IO uint8_t   ICR56;                        /**< 0078: Interrupt Control Register 56                                */
   __IO uint8_t   ICR57;                        /**< 0079: Interrupt Control Register 57                                */
   __IO uint8_t   ICR58;                        /**< 007A: Interrupt Control Register 58                                */
   __IO uint8_t   ICR59;                        /**< 007B: Interrupt Control Register 59                                */
   __IO uint8_t   ICR60;                        /**< 007C: Interrupt Control Register 60                                */
   __IO uint8_t   ICR61;                        /**< 007D: Interrupt Control Register 61                                */
   __IO uint8_t   ICR62;                        /**< 007E: Interrupt Control Register 62                                */
   __IO uint8_t   ICR63;                        /**< 007F: Interrupt Control Register 63                                */
        uint8_t   RESERVED_1[96];              
   __I  uint8_t   SWIACK;                       /**< 00E0: Software IACK Register                                       */
        uint8_t   RESERVED_2[3];               
   __I  uint8_t   L1IACK;                       /**< 00E4: Level 1 IACK Register                                        */
        uint8_t   RESERVED_3[3];               
   __I  uint8_t   L2IACK;                       /**< 00E8: Level 2 IACK Register                                        */
        uint8_t   RESERVED_4[3];               
   __I  uint8_t   L3IACK;                       /**< 00EC: Level 3 IACK Register                                        */
        uint8_t   RESERVED_5[3];               
   __I  uint8_t   L4IACK;                       /**< 00F0: Level 4 IACK Register                                        */
        uint8_t   RESERVED_6[3];               
   __I  uint8_t   L5IACK;                       /**< 00F4: Level 5 IACK Register                                        */
        uint8_t   RESERVED_7[3];               
   __I  uint8_t   L6IACK;                       /**< 00F8: Level 6 IACK Register                                        */
        uint8_t   RESERVED_8[3];               
   __I  uint8_t   L7IACK;                       /**< 00FC: Level 7 IACK Register                                        */
        uint8_t   RESERVED_9[3];               
} INTC_Type;

/**
 * @} */ /* End group INTC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'INTC0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup INTC_Register_Masks_GROUP INTC Register Masks
* @brief Register Masks for INTC
* @{
*/
/* ------- IPRH Bit Fields                          ------ */
#define INTC_IPRH_INT32_MASK                     (0x1U)                                              /*!< INTC0_IPRH: INT32 Mask                  */
#define INTC_IPRH_INT32_SHIFT                    (0U)                                                /*!< INTC0_IPRH: INT32 Position              */
#define INTC_IPRH_INT32(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT32_SHIFT))&INTC_IPRH_INT32_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT33_MASK                     (0x2U)                                              /*!< INTC0_IPRH: INT33 Mask                  */
#define INTC_IPRH_INT33_SHIFT                    (1U)                                                /*!< INTC0_IPRH: INT33 Position              */
#define INTC_IPRH_INT33(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT33_SHIFT))&INTC_IPRH_INT33_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT34_MASK                     (0x4U)                                              /*!< INTC0_IPRH: INT34 Mask                  */
#define INTC_IPRH_INT34_SHIFT                    (2U)                                                /*!< INTC0_IPRH: INT34 Position              */
#define INTC_IPRH_INT34(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT34_SHIFT))&INTC_IPRH_INT34_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT35_MASK                     (0x8U)                                              /*!< INTC0_IPRH: INT35 Mask                  */
#define INTC_IPRH_INT35_SHIFT                    (3U)                                                /*!< INTC0_IPRH: INT35 Position              */
#define INTC_IPRH_INT35(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT35_SHIFT))&INTC_IPRH_INT35_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT36_MASK                     (0x10U)                                             /*!< INTC0_IPRH: INT36 Mask                  */
#define INTC_IPRH_INT36_SHIFT                    (4U)                                                /*!< INTC0_IPRH: INT36 Position              */
#define INTC_IPRH_INT36(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT36_SHIFT))&INTC_IPRH_INT36_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT37_MASK                     (0x20U)                                             /*!< INTC0_IPRH: INT37 Mask                  */
#define INTC_IPRH_INT37_SHIFT                    (5U)                                                /*!< INTC0_IPRH: INT37 Position              */
#define INTC_IPRH_INT37(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT37_SHIFT))&INTC_IPRH_INT37_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT38_MASK                     (0x40U)                                             /*!< INTC0_IPRH: INT38 Mask                  */
#define INTC_IPRH_INT38_SHIFT                    (6U)                                                /*!< INTC0_IPRH: INT38 Position              */
#define INTC_IPRH_INT38(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT38_SHIFT))&INTC_IPRH_INT38_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT39_MASK                     (0x80U)                                             /*!< INTC0_IPRH: INT39 Mask                  */
#define INTC_IPRH_INT39_SHIFT                    (7U)                                                /*!< INTC0_IPRH: INT39 Position              */
#define INTC_IPRH_INT39(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT39_SHIFT))&INTC_IPRH_INT39_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT40_MASK                     (0x100U)                                            /*!< INTC0_IPRH: INT40 Mask                  */
#define INTC_IPRH_INT40_SHIFT                    (8U)                                                /*!< INTC0_IPRH: INT40 Position              */
#define INTC_IPRH_INT40(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT40_SHIFT))&INTC_IPRH_INT40_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT41_MASK                     (0x200U)                                            /*!< INTC0_IPRH: INT41 Mask                  */
#define INTC_IPRH_INT41_SHIFT                    (9U)                                                /*!< INTC0_IPRH: INT41 Position              */
#define INTC_IPRH_INT41(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT41_SHIFT))&INTC_IPRH_INT41_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT42_MASK                     (0x400U)                                            /*!< INTC0_IPRH: INT42 Mask                  */
#define INTC_IPRH_INT42_SHIFT                    (10U)                                               /*!< INTC0_IPRH: INT42 Position              */
#define INTC_IPRH_INT42(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT42_SHIFT))&INTC_IPRH_INT42_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT43_MASK                     (0x800U)                                            /*!< INTC0_IPRH: INT43 Mask                  */
#define INTC_IPRH_INT43_SHIFT                    (11U)                                               /*!< INTC0_IPRH: INT43 Position              */
#define INTC_IPRH_INT43(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT43_SHIFT))&INTC_IPRH_INT43_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT44_MASK                     (0x1000U)                                           /*!< INTC0_IPRH: INT44 Mask                  */
#define INTC_IPRH_INT44_SHIFT                    (12U)                                               /*!< INTC0_IPRH: INT44 Position              */
#define INTC_IPRH_INT44(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT44_SHIFT))&INTC_IPRH_INT44_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT45_MASK                     (0x2000U)                                           /*!< INTC0_IPRH: INT45 Mask                  */
#define INTC_IPRH_INT45_SHIFT                    (13U)                                               /*!< INTC0_IPRH: INT45 Position              */
#define INTC_IPRH_INT45(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT45_SHIFT))&INTC_IPRH_INT45_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT46_MASK                     (0x4000U)                                           /*!< INTC0_IPRH: INT46 Mask                  */
#define INTC_IPRH_INT46_SHIFT                    (14U)                                               /*!< INTC0_IPRH: INT46 Position              */
#define INTC_IPRH_INT46(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT46_SHIFT))&INTC_IPRH_INT46_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT47_MASK                     (0x8000U)                                           /*!< INTC0_IPRH: INT47 Mask                  */
#define INTC_IPRH_INT47_SHIFT                    (15U)                                               /*!< INTC0_IPRH: INT47 Position              */
#define INTC_IPRH_INT47(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT47_SHIFT))&INTC_IPRH_INT47_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT48_MASK                     (0x10000U)                                          /*!< INTC0_IPRH: INT48 Mask                  */
#define INTC_IPRH_INT48_SHIFT                    (16U)                                               /*!< INTC0_IPRH: INT48 Position              */
#define INTC_IPRH_INT48(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT48_SHIFT))&INTC_IPRH_INT48_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT49_MASK                     (0x20000U)                                          /*!< INTC0_IPRH: INT49 Mask                  */
#define INTC_IPRH_INT49_SHIFT                    (17U)                                               /*!< INTC0_IPRH: INT49 Position              */
#define INTC_IPRH_INT49(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT49_SHIFT))&INTC_IPRH_INT49_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT50_MASK                     (0x40000U)                                          /*!< INTC0_IPRH: INT50 Mask                  */
#define INTC_IPRH_INT50_SHIFT                    (18U)                                               /*!< INTC0_IPRH: INT50 Position              */
#define INTC_IPRH_INT50(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT50_SHIFT))&INTC_IPRH_INT50_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT51_MASK                     (0x80000U)                                          /*!< INTC0_IPRH: INT51 Mask                  */
#define INTC_IPRH_INT51_SHIFT                    (19U)                                               /*!< INTC0_IPRH: INT51 Position              */
#define INTC_IPRH_INT51(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT51_SHIFT))&INTC_IPRH_INT51_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT52_MASK                     (0x100000U)                                         /*!< INTC0_IPRH: INT52 Mask                  */
#define INTC_IPRH_INT52_SHIFT                    (20U)                                               /*!< INTC0_IPRH: INT52 Position              */
#define INTC_IPRH_INT52(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT52_SHIFT))&INTC_IPRH_INT52_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT53_MASK                     (0x200000U)                                         /*!< INTC0_IPRH: INT53 Mask                  */
#define INTC_IPRH_INT53_SHIFT                    (21U)                                               /*!< INTC0_IPRH: INT53 Position              */
#define INTC_IPRH_INT53(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT53_SHIFT))&INTC_IPRH_INT53_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT54_MASK                     (0x400000U)                                         /*!< INTC0_IPRH: INT54 Mask                  */
#define INTC_IPRH_INT54_SHIFT                    (22U)                                               /*!< INTC0_IPRH: INT54 Position              */
#define INTC_IPRH_INT54(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT54_SHIFT))&INTC_IPRH_INT54_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT55_MASK                     (0x800000U)                                         /*!< INTC0_IPRH: INT55 Mask                  */
#define INTC_IPRH_INT55_SHIFT                    (23U)                                               /*!< INTC0_IPRH: INT55 Position              */
#define INTC_IPRH_INT55(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT55_SHIFT))&INTC_IPRH_INT55_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT56_MASK                     (0x1000000U)                                        /*!< INTC0_IPRH: INT56 Mask                  */
#define INTC_IPRH_INT56_SHIFT                    (24U)                                               /*!< INTC0_IPRH: INT56 Position              */
#define INTC_IPRH_INT56(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT56_SHIFT))&INTC_IPRH_INT56_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT57_MASK                     (0x2000000U)                                        /*!< INTC0_IPRH: INT57 Mask                  */
#define INTC_IPRH_INT57_SHIFT                    (25U)                                               /*!< INTC0_IPRH: INT57 Position              */
#define INTC_IPRH_INT57(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT57_SHIFT))&INTC_IPRH_INT57_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT58_MASK                     (0x4000000U)                                        /*!< INTC0_IPRH: INT58 Mask                  */
#define INTC_IPRH_INT58_SHIFT                    (26U)                                               /*!< INTC0_IPRH: INT58 Position              */
#define INTC_IPRH_INT58(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT58_SHIFT))&INTC_IPRH_INT58_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT59_MASK                     (0x8000000U)                                        /*!< INTC0_IPRH: INT59 Mask                  */
#define INTC_IPRH_INT59_SHIFT                    (27U)                                               /*!< INTC0_IPRH: INT59 Position              */
#define INTC_IPRH_INT59(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT59_SHIFT))&INTC_IPRH_INT59_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT60_MASK                     (0x10000000U)                                       /*!< INTC0_IPRH: INT60 Mask                  */
#define INTC_IPRH_INT60_SHIFT                    (28U)                                               /*!< INTC0_IPRH: INT60 Position              */
#define INTC_IPRH_INT60(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT60_SHIFT))&INTC_IPRH_INT60_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT61_MASK                     (0x20000000U)                                       /*!< INTC0_IPRH: INT61 Mask                  */
#define INTC_IPRH_INT61_SHIFT                    (29U)                                               /*!< INTC0_IPRH: INT61 Position              */
#define INTC_IPRH_INT61(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT61_SHIFT))&INTC_IPRH_INT61_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT62_MASK                     (0x40000000U)                                       /*!< INTC0_IPRH: INT62 Mask                  */
#define INTC_IPRH_INT62_SHIFT                    (30U)                                               /*!< INTC0_IPRH: INT62 Position              */
#define INTC_IPRH_INT62(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT62_SHIFT))&INTC_IPRH_INT62_MASK) /*!< INTC0_IPRH                              */
#define INTC_IPRH_INT63_MASK                     (0x80000000U)                                       /*!< INTC0_IPRH: INT63 Mask                  */
#define INTC_IPRH_INT63_SHIFT                    (31U)                                               /*!< INTC0_IPRH: INT63 Position              */
#define INTC_IPRH_INT63(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRH_INT63_SHIFT))&INTC_IPRH_INT63_MASK) /*!< INTC0_IPRH                              */
/* ------- IPRL Bit Fields                          ------ */
#define INTC_IPRL_INT1_MASK                      (0x2U)                                              /*!< INTC0_IPRL: INT1 Mask                   */
#define INTC_IPRL_INT1_SHIFT                     (1U)                                                /*!< INTC0_IPRL: INT1 Position               */
#define INTC_IPRL_INT1(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT1_SHIFT))&INTC_IPRL_INT1_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT2_MASK                      (0x4U)                                              /*!< INTC0_IPRL: INT2 Mask                   */
#define INTC_IPRL_INT2_SHIFT                     (2U)                                                /*!< INTC0_IPRL: INT2 Position               */
#define INTC_IPRL_INT2(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT2_SHIFT))&INTC_IPRL_INT2_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT3_MASK                      (0x8U)                                              /*!< INTC0_IPRL: INT3 Mask                   */
#define INTC_IPRL_INT3_SHIFT                     (3U)                                                /*!< INTC0_IPRL: INT3 Position               */
#define INTC_IPRL_INT3(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT3_SHIFT))&INTC_IPRL_INT3_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT4_MASK                      (0x10U)                                             /*!< INTC0_IPRL: INT4 Mask                   */
#define INTC_IPRL_INT4_SHIFT                     (4U)                                                /*!< INTC0_IPRL: INT4 Position               */
#define INTC_IPRL_INT4(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT4_SHIFT))&INTC_IPRL_INT4_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT5_MASK                      (0x20U)                                             /*!< INTC0_IPRL: INT5 Mask                   */
#define INTC_IPRL_INT5_SHIFT                     (5U)                                                /*!< INTC0_IPRL: INT5 Position               */
#define INTC_IPRL_INT5(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT5_SHIFT))&INTC_IPRL_INT5_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT6_MASK                      (0x40U)                                             /*!< INTC0_IPRL: INT6 Mask                   */
#define INTC_IPRL_INT6_SHIFT                     (6U)                                                /*!< INTC0_IPRL: INT6 Position               */
#define INTC_IPRL_INT6(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT6_SHIFT))&INTC_IPRL_INT6_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT7_MASK                      (0x80U)                                             /*!< INTC0_IPRL: INT7 Mask                   */
#define INTC_IPRL_INT7_SHIFT                     (7U)                                                /*!< INTC0_IPRL: INT7 Position               */
#define INTC_IPRL_INT7(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT7_SHIFT))&INTC_IPRL_INT7_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT8_MASK                      (0x100U)                                            /*!< INTC0_IPRL: INT8 Mask                   */
#define INTC_IPRL_INT8_SHIFT                     (8U)                                                /*!< INTC0_IPRL: INT8 Position               */
#define INTC_IPRL_INT8(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT8_SHIFT))&INTC_IPRL_INT8_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT9_MASK                      (0x200U)                                            /*!< INTC0_IPRL: INT9 Mask                   */
#define INTC_IPRL_INT9_SHIFT                     (9U)                                                /*!< INTC0_IPRL: INT9 Position               */
#define INTC_IPRL_INT9(x)                        (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT9_SHIFT))&INTC_IPRL_INT9_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT10_MASK                     (0x400U)                                            /*!< INTC0_IPRL: INT10 Mask                  */
#define INTC_IPRL_INT10_SHIFT                    (10U)                                               /*!< INTC0_IPRL: INT10 Position              */
#define INTC_IPRL_INT10(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT10_SHIFT))&INTC_IPRL_INT10_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT11_MASK                     (0x800U)                                            /*!< INTC0_IPRL: INT11 Mask                  */
#define INTC_IPRL_INT11_SHIFT                    (11U)                                               /*!< INTC0_IPRL: INT11 Position              */
#define INTC_IPRL_INT11(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT11_SHIFT))&INTC_IPRL_INT11_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT12_MASK                     (0x1000U)                                           /*!< INTC0_IPRL: INT12 Mask                  */
#define INTC_IPRL_INT12_SHIFT                    (12U)                                               /*!< INTC0_IPRL: INT12 Position              */
#define INTC_IPRL_INT12(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT12_SHIFT))&INTC_IPRL_INT12_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT13_MASK                     (0x2000U)                                           /*!< INTC0_IPRL: INT13 Mask                  */
#define INTC_IPRL_INT13_SHIFT                    (13U)                                               /*!< INTC0_IPRL: INT13 Position              */
#define INTC_IPRL_INT13(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT13_SHIFT))&INTC_IPRL_INT13_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT14_MASK                     (0x4000U)                                           /*!< INTC0_IPRL: INT14 Mask                  */
#define INTC_IPRL_INT14_SHIFT                    (14U)                                               /*!< INTC0_IPRL: INT14 Position              */
#define INTC_IPRL_INT14(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT14_SHIFT))&INTC_IPRL_INT14_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT15_MASK                     (0x8000U)                                           /*!< INTC0_IPRL: INT15 Mask                  */
#define INTC_IPRL_INT15_SHIFT                    (15U)                                               /*!< INTC0_IPRL: INT15 Position              */
#define INTC_IPRL_INT15(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT15_SHIFT))&INTC_IPRL_INT15_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT16_MASK                     (0x10000U)                                          /*!< INTC0_IPRL: INT16 Mask                  */
#define INTC_IPRL_INT16_SHIFT                    (16U)                                               /*!< INTC0_IPRL: INT16 Position              */
#define INTC_IPRL_INT16(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT16_SHIFT))&INTC_IPRL_INT16_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT17_MASK                     (0x20000U)                                          /*!< INTC0_IPRL: INT17 Mask                  */
#define INTC_IPRL_INT17_SHIFT                    (17U)                                               /*!< INTC0_IPRL: INT17 Position              */
#define INTC_IPRL_INT17(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT17_SHIFT))&INTC_IPRL_INT17_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT18_MASK                     (0x40000U)                                          /*!< INTC0_IPRL: INT18 Mask                  */
#define INTC_IPRL_INT18_SHIFT                    (18U)                                               /*!< INTC0_IPRL: INT18 Position              */
#define INTC_IPRL_INT18(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT18_SHIFT))&INTC_IPRL_INT18_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT19_MASK                     (0x80000U)                                          /*!< INTC0_IPRL: INT19 Mask                  */
#define INTC_IPRL_INT19_SHIFT                    (19U)                                               /*!< INTC0_IPRL: INT19 Position              */
#define INTC_IPRL_INT19(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT19_SHIFT))&INTC_IPRL_INT19_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT20_MASK                     (0x100000U)                                         /*!< INTC0_IPRL: INT20 Mask                  */
#define INTC_IPRL_INT20_SHIFT                    (20U)                                               /*!< INTC0_IPRL: INT20 Position              */
#define INTC_IPRL_INT20(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT20_SHIFT))&INTC_IPRL_INT20_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT21_MASK                     (0x200000U)                                         /*!< INTC0_IPRL: INT21 Mask                  */
#define INTC_IPRL_INT21_SHIFT                    (21U)                                               /*!< INTC0_IPRL: INT21 Position              */
#define INTC_IPRL_INT21(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT21_SHIFT))&INTC_IPRL_INT21_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT22_MASK                     (0x400000U)                                         /*!< INTC0_IPRL: INT22 Mask                  */
#define INTC_IPRL_INT22_SHIFT                    (22U)                                               /*!< INTC0_IPRL: INT22 Position              */
#define INTC_IPRL_INT22(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT22_SHIFT))&INTC_IPRL_INT22_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT23_MASK                     (0x800000U)                                         /*!< INTC0_IPRL: INT23 Mask                  */
#define INTC_IPRL_INT23_SHIFT                    (23U)                                               /*!< INTC0_IPRL: INT23 Position              */
#define INTC_IPRL_INT23(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT23_SHIFT))&INTC_IPRL_INT23_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT24_MASK                     (0x1000000U)                                        /*!< INTC0_IPRL: INT24 Mask                  */
#define INTC_IPRL_INT24_SHIFT                    (24U)                                               /*!< INTC0_IPRL: INT24 Position              */
#define INTC_IPRL_INT24(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT24_SHIFT))&INTC_IPRL_INT24_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT25_MASK                     (0x2000000U)                                        /*!< INTC0_IPRL: INT25 Mask                  */
#define INTC_IPRL_INT25_SHIFT                    (25U)                                               /*!< INTC0_IPRL: INT25 Position              */
#define INTC_IPRL_INT25(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT25_SHIFT))&INTC_IPRL_INT25_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT26_MASK                     (0x4000000U)                                        /*!< INTC0_IPRL: INT26 Mask                  */
#define INTC_IPRL_INT26_SHIFT                    (26U)                                               /*!< INTC0_IPRL: INT26 Position              */
#define INTC_IPRL_INT26(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT26_SHIFT))&INTC_IPRL_INT26_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT27_MASK                     (0x8000000U)                                        /*!< INTC0_IPRL: INT27 Mask                  */
#define INTC_IPRL_INT27_SHIFT                    (27U)                                               /*!< INTC0_IPRL: INT27 Position              */
#define INTC_IPRL_INT27(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT27_SHIFT))&INTC_IPRL_INT27_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT28_MASK                     (0x10000000U)                                       /*!< INTC0_IPRL: INT28 Mask                  */
#define INTC_IPRL_INT28_SHIFT                    (28U)                                               /*!< INTC0_IPRL: INT28 Position              */
#define INTC_IPRL_INT28(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT28_SHIFT))&INTC_IPRL_INT28_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT29_MASK                     (0x20000000U)                                       /*!< INTC0_IPRL: INT29 Mask                  */
#define INTC_IPRL_INT29_SHIFT                    (29U)                                               /*!< INTC0_IPRL: INT29 Position              */
#define INTC_IPRL_INT29(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT29_SHIFT))&INTC_IPRL_INT29_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT30_MASK                     (0x40000000U)                                       /*!< INTC0_IPRL: INT30 Mask                  */
#define INTC_IPRL_INT30_SHIFT                    (30U)                                               /*!< INTC0_IPRL: INT30 Position              */
#define INTC_IPRL_INT30(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT30_SHIFT))&INTC_IPRL_INT30_MASK) /*!< INTC0_IPRL                              */
#define INTC_IPRL_INT31_MASK                     (0x80000000U)                                       /*!< INTC0_IPRL: INT31 Mask                  */
#define INTC_IPRL_INT31_SHIFT                    (31U)                                               /*!< INTC0_IPRL: INT31 Position              */
#define INTC_IPRL_INT31(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IPRL_INT31_SHIFT))&INTC_IPRL_INT31_MASK) /*!< INTC0_IPRL                              */
/* ------- IMRH Bit Fields                          ------ */
#define INTC_IMRH_MASK32_MASK                    (0x1U)                                              /*!< INTC0_IMRH: MASK32 Mask                 */
#define INTC_IMRH_MASK32_SHIFT                   (0U)                                                /*!< INTC0_IMRH: MASK32 Position             */
#define INTC_IMRH_MASK32(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK32_SHIFT))&INTC_IMRH_MASK32_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK33_MASK                    (0x2U)                                              /*!< INTC0_IMRH: MASK33 Mask                 */
#define INTC_IMRH_MASK33_SHIFT                   (1U)                                                /*!< INTC0_IMRH: MASK33 Position             */
#define INTC_IMRH_MASK33(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK33_SHIFT))&INTC_IMRH_MASK33_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK34_MASK                    (0x4U)                                              /*!< INTC0_IMRH: MASK34 Mask                 */
#define INTC_IMRH_MASK34_SHIFT                   (2U)                                                /*!< INTC0_IMRH: MASK34 Position             */
#define INTC_IMRH_MASK34(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK34_SHIFT))&INTC_IMRH_MASK34_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK35_MASK                    (0x8U)                                              /*!< INTC0_IMRH: MASK35 Mask                 */
#define INTC_IMRH_MASK35_SHIFT                   (3U)                                                /*!< INTC0_IMRH: MASK35 Position             */
#define INTC_IMRH_MASK35(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK35_SHIFT))&INTC_IMRH_MASK35_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK36_MASK                    (0x10U)                                             /*!< INTC0_IMRH: MASK36 Mask                 */
#define INTC_IMRH_MASK36_SHIFT                   (4U)                                                /*!< INTC0_IMRH: MASK36 Position             */
#define INTC_IMRH_MASK36(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK36_SHIFT))&INTC_IMRH_MASK36_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK37_MASK                    (0x20U)                                             /*!< INTC0_IMRH: MASK37 Mask                 */
#define INTC_IMRH_MASK37_SHIFT                   (5U)                                                /*!< INTC0_IMRH: MASK37 Position             */
#define INTC_IMRH_MASK37(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK37_SHIFT))&INTC_IMRH_MASK37_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK38_MASK                    (0x40U)                                             /*!< INTC0_IMRH: MASK38 Mask                 */
#define INTC_IMRH_MASK38_SHIFT                   (6U)                                                /*!< INTC0_IMRH: MASK38 Position             */
#define INTC_IMRH_MASK38(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK38_SHIFT))&INTC_IMRH_MASK38_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK39_MASK                    (0x80U)                                             /*!< INTC0_IMRH: MASK39 Mask                 */
#define INTC_IMRH_MASK39_SHIFT                   (7U)                                                /*!< INTC0_IMRH: MASK39 Position             */
#define INTC_IMRH_MASK39(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK39_SHIFT))&INTC_IMRH_MASK39_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK40_MASK                    (0x100U)                                            /*!< INTC0_IMRH: MASK40 Mask                 */
#define INTC_IMRH_MASK40_SHIFT                   (8U)                                                /*!< INTC0_IMRH: MASK40 Position             */
#define INTC_IMRH_MASK40(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK40_SHIFT))&INTC_IMRH_MASK40_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK41_MASK                    (0x200U)                                            /*!< INTC0_IMRH: MASK41 Mask                 */
#define INTC_IMRH_MASK41_SHIFT                   (9U)                                                /*!< INTC0_IMRH: MASK41 Position             */
#define INTC_IMRH_MASK41(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK41_SHIFT))&INTC_IMRH_MASK41_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK42_MASK                    (0x400U)                                            /*!< INTC0_IMRH: MASK42 Mask                 */
#define INTC_IMRH_MASK42_SHIFT                   (10U)                                               /*!< INTC0_IMRH: MASK42 Position             */
#define INTC_IMRH_MASK42(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK42_SHIFT))&INTC_IMRH_MASK42_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK43_MASK                    (0x800U)                                            /*!< INTC0_IMRH: MASK43 Mask                 */
#define INTC_IMRH_MASK43_SHIFT                   (11U)                                               /*!< INTC0_IMRH: MASK43 Position             */
#define INTC_IMRH_MASK43(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK43_SHIFT))&INTC_IMRH_MASK43_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK44_MASK                    (0x1000U)                                           /*!< INTC0_IMRH: MASK44 Mask                 */
#define INTC_IMRH_MASK44_SHIFT                   (12U)                                               /*!< INTC0_IMRH: MASK44 Position             */
#define INTC_IMRH_MASK44(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK44_SHIFT))&INTC_IMRH_MASK44_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK45_MASK                    (0x2000U)                                           /*!< INTC0_IMRH: MASK45 Mask                 */
#define INTC_IMRH_MASK45_SHIFT                   (13U)                                               /*!< INTC0_IMRH: MASK45 Position             */
#define INTC_IMRH_MASK45(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK45_SHIFT))&INTC_IMRH_MASK45_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK46_MASK                    (0x4000U)                                           /*!< INTC0_IMRH: MASK46 Mask                 */
#define INTC_IMRH_MASK46_SHIFT                   (14U)                                               /*!< INTC0_IMRH: MASK46 Position             */
#define INTC_IMRH_MASK46(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK46_SHIFT))&INTC_IMRH_MASK46_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK47_MASK                    (0x8000U)                                           /*!< INTC0_IMRH: MASK47 Mask                 */
#define INTC_IMRH_MASK47_SHIFT                   (15U)                                               /*!< INTC0_IMRH: MASK47 Position             */
#define INTC_IMRH_MASK47(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK47_SHIFT))&INTC_IMRH_MASK47_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK48_MASK                    (0x10000U)                                          /*!< INTC0_IMRH: MASK48 Mask                 */
#define INTC_IMRH_MASK48_SHIFT                   (16U)                                               /*!< INTC0_IMRH: MASK48 Position             */
#define INTC_IMRH_MASK48(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK48_SHIFT))&INTC_IMRH_MASK48_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK49_MASK                    (0x20000U)                                          /*!< INTC0_IMRH: MASK49 Mask                 */
#define INTC_IMRH_MASK49_SHIFT                   (17U)                                               /*!< INTC0_IMRH: MASK49 Position             */
#define INTC_IMRH_MASK49(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK49_SHIFT))&INTC_IMRH_MASK49_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK50_MASK                    (0x40000U)                                          /*!< INTC0_IMRH: MASK50 Mask                 */
#define INTC_IMRH_MASK50_SHIFT                   (18U)                                               /*!< INTC0_IMRH: MASK50 Position             */
#define INTC_IMRH_MASK50(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK50_SHIFT))&INTC_IMRH_MASK50_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK51_MASK                    (0x80000U)                                          /*!< INTC0_IMRH: MASK51 Mask                 */
#define INTC_IMRH_MASK51_SHIFT                   (19U)                                               /*!< INTC0_IMRH: MASK51 Position             */
#define INTC_IMRH_MASK51(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK51_SHIFT))&INTC_IMRH_MASK51_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK52_MASK                    (0x100000U)                                         /*!< INTC0_IMRH: MASK52 Mask                 */
#define INTC_IMRH_MASK52_SHIFT                   (20U)                                               /*!< INTC0_IMRH: MASK52 Position             */
#define INTC_IMRH_MASK52(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK52_SHIFT))&INTC_IMRH_MASK52_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK53_MASK                    (0x200000U)                                         /*!< INTC0_IMRH: MASK53 Mask                 */
#define INTC_IMRH_MASK53_SHIFT                   (21U)                                               /*!< INTC0_IMRH: MASK53 Position             */
#define INTC_IMRH_MASK53(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK53_SHIFT))&INTC_IMRH_MASK53_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK54_MASK                    (0x400000U)                                         /*!< INTC0_IMRH: MASK54 Mask                 */
#define INTC_IMRH_MASK54_SHIFT                   (22U)                                               /*!< INTC0_IMRH: MASK54 Position             */
#define INTC_IMRH_MASK54(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK54_SHIFT))&INTC_IMRH_MASK54_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK55_MASK                    (0x800000U)                                         /*!< INTC0_IMRH: MASK55 Mask                 */
#define INTC_IMRH_MASK55_SHIFT                   (23U)                                               /*!< INTC0_IMRH: MASK55 Position             */
#define INTC_IMRH_MASK55(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK55_SHIFT))&INTC_IMRH_MASK55_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK56_MASK                    (0x1000000U)                                        /*!< INTC0_IMRH: MASK56 Mask                 */
#define INTC_IMRH_MASK56_SHIFT                   (24U)                                               /*!< INTC0_IMRH: MASK56 Position             */
#define INTC_IMRH_MASK56(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK56_SHIFT))&INTC_IMRH_MASK56_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK57_MASK                    (0x2000000U)                                        /*!< INTC0_IMRH: MASK57 Mask                 */
#define INTC_IMRH_MASK57_SHIFT                   (25U)                                               /*!< INTC0_IMRH: MASK57 Position             */
#define INTC_IMRH_MASK57(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK57_SHIFT))&INTC_IMRH_MASK57_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK58_MASK                    (0x4000000U)                                        /*!< INTC0_IMRH: MASK58 Mask                 */
#define INTC_IMRH_MASK58_SHIFT                   (26U)                                               /*!< INTC0_IMRH: MASK58 Position             */
#define INTC_IMRH_MASK58(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK58_SHIFT))&INTC_IMRH_MASK58_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK59_MASK                    (0x8000000U)                                        /*!< INTC0_IMRH: MASK59 Mask                 */
#define INTC_IMRH_MASK59_SHIFT                   (27U)                                               /*!< INTC0_IMRH: MASK59 Position             */
#define INTC_IMRH_MASK59(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK59_SHIFT))&INTC_IMRH_MASK59_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK60_MASK                    (0x10000000U)                                       /*!< INTC0_IMRH: MASK60 Mask                 */
#define INTC_IMRH_MASK60_SHIFT                   (28U)                                               /*!< INTC0_IMRH: MASK60 Position             */
#define INTC_IMRH_MASK60(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK60_SHIFT))&INTC_IMRH_MASK60_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK61_MASK                    (0x20000000U)                                       /*!< INTC0_IMRH: MASK61 Mask                 */
#define INTC_IMRH_MASK61_SHIFT                   (29U)                                               /*!< INTC0_IMRH: MASK61 Position             */
#define INTC_IMRH_MASK61(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK61_SHIFT))&INTC_IMRH_MASK61_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK62_MASK                    (0x40000000U)                                       /*!< INTC0_IMRH: MASK62 Mask                 */
#define INTC_IMRH_MASK62_SHIFT                   (30U)                                               /*!< INTC0_IMRH: MASK62 Position             */
#define INTC_IMRH_MASK62(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK62_SHIFT))&INTC_IMRH_MASK62_MASK) /*!< INTC0_IMRH                              */
#define INTC_IMRH_MASK63_MASK                    (0x80000000U)                                       /*!< INTC0_IMRH: MASK63 Mask                 */
#define INTC_IMRH_MASK63_SHIFT                   (31U)                                               /*!< INTC0_IMRH: MASK63 Position             */
#define INTC_IMRH_MASK63(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRH_MASK63_SHIFT))&INTC_IMRH_MASK63_MASK) /*!< INTC0_IMRH                              */
/* ------- IMRL Bit Fields                          ------ */
#define INTC_IMRL_MASKALL_MASK                   (0x1U)                                              /*!< INTC0_IMRL: MASKALL Mask                */
#define INTC_IMRL_MASKALL_SHIFT                  (0U)                                                /*!< INTC0_IMRL: MASKALL Position            */
#define INTC_IMRL_MASKALL(x)                     (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASKALL_SHIFT))&INTC_IMRL_MASKALL_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK1_MASK                     (0x2U)                                              /*!< INTC0_IMRL: MASK1 Mask                  */
#define INTC_IMRL_MASK1_SHIFT                    (1U)                                                /*!< INTC0_IMRL: MASK1 Position              */
#define INTC_IMRL_MASK1(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK1_SHIFT))&INTC_IMRL_MASK1_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK2_MASK                     (0x4U)                                              /*!< INTC0_IMRL: MASK2 Mask                  */
#define INTC_IMRL_MASK2_SHIFT                    (2U)                                                /*!< INTC0_IMRL: MASK2 Position              */
#define INTC_IMRL_MASK2(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK2_SHIFT))&INTC_IMRL_MASK2_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK3_MASK                     (0x8U)                                              /*!< INTC0_IMRL: MASK3 Mask                  */
#define INTC_IMRL_MASK3_SHIFT                    (3U)                                                /*!< INTC0_IMRL: MASK3 Position              */
#define INTC_IMRL_MASK3(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK3_SHIFT))&INTC_IMRL_MASK3_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK4_MASK                     (0x10U)                                             /*!< INTC0_IMRL: MASK4 Mask                  */
#define INTC_IMRL_MASK4_SHIFT                    (4U)                                                /*!< INTC0_IMRL: MASK4 Position              */
#define INTC_IMRL_MASK4(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK4_SHIFT))&INTC_IMRL_MASK4_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK5_MASK                     (0x20U)                                             /*!< INTC0_IMRL: MASK5 Mask                  */
#define INTC_IMRL_MASK5_SHIFT                    (5U)                                                /*!< INTC0_IMRL: MASK5 Position              */
#define INTC_IMRL_MASK5(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK5_SHIFT))&INTC_IMRL_MASK5_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK6_MASK                     (0x40U)                                             /*!< INTC0_IMRL: MASK6 Mask                  */
#define INTC_IMRL_MASK6_SHIFT                    (6U)                                                /*!< INTC0_IMRL: MASK6 Position              */
#define INTC_IMRL_MASK6(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK6_SHIFT))&INTC_IMRL_MASK6_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK7_MASK                     (0x80U)                                             /*!< INTC0_IMRL: MASK7 Mask                  */
#define INTC_IMRL_MASK7_SHIFT                    (7U)                                                /*!< INTC0_IMRL: MASK7 Position              */
#define INTC_IMRL_MASK7(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK7_SHIFT))&INTC_IMRL_MASK7_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK8_MASK                     (0x100U)                                            /*!< INTC0_IMRL: MASK8 Mask                  */
#define INTC_IMRL_MASK8_SHIFT                    (8U)                                                /*!< INTC0_IMRL: MASK8 Position              */
#define INTC_IMRL_MASK8(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK8_SHIFT))&INTC_IMRL_MASK8_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK9_MASK                     (0x200U)                                            /*!< INTC0_IMRL: MASK9 Mask                  */
#define INTC_IMRL_MASK9_SHIFT                    (9U)                                                /*!< INTC0_IMRL: MASK9 Position              */
#define INTC_IMRL_MASK9(x)                       (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK9_SHIFT))&INTC_IMRL_MASK9_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK10_MASK                    (0x400U)                                            /*!< INTC0_IMRL: MASK10 Mask                 */
#define INTC_IMRL_MASK10_SHIFT                   (10U)                                               /*!< INTC0_IMRL: MASK10 Position             */
#define INTC_IMRL_MASK10(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK10_SHIFT))&INTC_IMRL_MASK10_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK11_MASK                    (0x800U)                                            /*!< INTC0_IMRL: MASK11 Mask                 */
#define INTC_IMRL_MASK11_SHIFT                   (11U)                                               /*!< INTC0_IMRL: MASK11 Position             */
#define INTC_IMRL_MASK11(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK11_SHIFT))&INTC_IMRL_MASK11_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK12_MASK                    (0x1000U)                                           /*!< INTC0_IMRL: MASK12 Mask                 */
#define INTC_IMRL_MASK12_SHIFT                   (12U)                                               /*!< INTC0_IMRL: MASK12 Position             */
#define INTC_IMRL_MASK12(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK12_SHIFT))&INTC_IMRL_MASK12_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK13_MASK                    (0x2000U)                                           /*!< INTC0_IMRL: MASK13 Mask                 */
#define INTC_IMRL_MASK13_SHIFT                   (13U)                                               /*!< INTC0_IMRL: MASK13 Position             */
#define INTC_IMRL_MASK13(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK13_SHIFT))&INTC_IMRL_MASK13_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK14_MASK                    (0x4000U)                                           /*!< INTC0_IMRL: MASK14 Mask                 */
#define INTC_IMRL_MASK14_SHIFT                   (14U)                                               /*!< INTC0_IMRL: MASK14 Position             */
#define INTC_IMRL_MASK14(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK14_SHIFT))&INTC_IMRL_MASK14_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK15_MASK                    (0x8000U)                                           /*!< INTC0_IMRL: MASK15 Mask                 */
#define INTC_IMRL_MASK15_SHIFT                   (15U)                                               /*!< INTC0_IMRL: MASK15 Position             */
#define INTC_IMRL_MASK15(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK15_SHIFT))&INTC_IMRL_MASK15_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK16_MASK                    (0x10000U)                                          /*!< INTC0_IMRL: MASK16 Mask                 */
#define INTC_IMRL_MASK16_SHIFT                   (16U)                                               /*!< INTC0_IMRL: MASK16 Position             */
#define INTC_IMRL_MASK16(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK16_SHIFT))&INTC_IMRL_MASK16_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK17_MASK                    (0x20000U)                                          /*!< INTC0_IMRL: MASK17 Mask                 */
#define INTC_IMRL_MASK17_SHIFT                   (17U)                                               /*!< INTC0_IMRL: MASK17 Position             */
#define INTC_IMRL_MASK17(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK17_SHIFT))&INTC_IMRL_MASK17_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK18_MASK                    (0x40000U)                                          /*!< INTC0_IMRL: MASK18 Mask                 */
#define INTC_IMRL_MASK18_SHIFT                   (18U)                                               /*!< INTC0_IMRL: MASK18 Position             */
#define INTC_IMRL_MASK18(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK18_SHIFT))&INTC_IMRL_MASK18_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK19_MASK                    (0x80000U)                                          /*!< INTC0_IMRL: MASK19 Mask                 */
#define INTC_IMRL_MASK19_SHIFT                   (19U)                                               /*!< INTC0_IMRL: MASK19 Position             */
#define INTC_IMRL_MASK19(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK19_SHIFT))&INTC_IMRL_MASK19_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK20_MASK                    (0x100000U)                                         /*!< INTC0_IMRL: MASK20 Mask                 */
#define INTC_IMRL_MASK20_SHIFT                   (20U)                                               /*!< INTC0_IMRL: MASK20 Position             */
#define INTC_IMRL_MASK20(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK20_SHIFT))&INTC_IMRL_MASK20_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK21_MASK                    (0x200000U)                                         /*!< INTC0_IMRL: MASK21 Mask                 */
#define INTC_IMRL_MASK21_SHIFT                   (21U)                                               /*!< INTC0_IMRL: MASK21 Position             */
#define INTC_IMRL_MASK21(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK21_SHIFT))&INTC_IMRL_MASK21_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK22_MASK                    (0x400000U)                                         /*!< INTC0_IMRL: MASK22 Mask                 */
#define INTC_IMRL_MASK22_SHIFT                   (22U)                                               /*!< INTC0_IMRL: MASK22 Position             */
#define INTC_IMRL_MASK22(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK22_SHIFT))&INTC_IMRL_MASK22_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK23_MASK                    (0x800000U)                                         /*!< INTC0_IMRL: MASK23 Mask                 */
#define INTC_IMRL_MASK23_SHIFT                   (23U)                                               /*!< INTC0_IMRL: MASK23 Position             */
#define INTC_IMRL_MASK23(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK23_SHIFT))&INTC_IMRL_MASK23_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK24_MASK                    (0x1000000U)                                        /*!< INTC0_IMRL: MASK24 Mask                 */
#define INTC_IMRL_MASK24_SHIFT                   (24U)                                               /*!< INTC0_IMRL: MASK24 Position             */
#define INTC_IMRL_MASK24(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK24_SHIFT))&INTC_IMRL_MASK24_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK25_MASK                    (0x2000000U)                                        /*!< INTC0_IMRL: MASK25 Mask                 */
#define INTC_IMRL_MASK25_SHIFT                   (25U)                                               /*!< INTC0_IMRL: MASK25 Position             */
#define INTC_IMRL_MASK25(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK25_SHIFT))&INTC_IMRL_MASK25_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK26_MASK                    (0x4000000U)                                        /*!< INTC0_IMRL: MASK26 Mask                 */
#define INTC_IMRL_MASK26_SHIFT                   (26U)                                               /*!< INTC0_IMRL: MASK26 Position             */
#define INTC_IMRL_MASK26(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK26_SHIFT))&INTC_IMRL_MASK26_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK27_MASK                    (0x8000000U)                                        /*!< INTC0_IMRL: MASK27 Mask                 */
#define INTC_IMRL_MASK27_SHIFT                   (27U)                                               /*!< INTC0_IMRL: MASK27 Position             */
#define INTC_IMRL_MASK27(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK27_SHIFT))&INTC_IMRL_MASK27_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK28_MASK                    (0x10000000U)                                       /*!< INTC0_IMRL: MASK28 Mask                 */
#define INTC_IMRL_MASK28_SHIFT                   (28U)                                               /*!< INTC0_IMRL: MASK28 Position             */
#define INTC_IMRL_MASK28(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK28_SHIFT))&INTC_IMRL_MASK28_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK29_MASK                    (0x20000000U)                                       /*!< INTC0_IMRL: MASK29 Mask                 */
#define INTC_IMRL_MASK29_SHIFT                   (29U)                                               /*!< INTC0_IMRL: MASK29 Position             */
#define INTC_IMRL_MASK29(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK29_SHIFT))&INTC_IMRL_MASK29_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK30_MASK                    (0x40000000U)                                       /*!< INTC0_IMRL: MASK30 Mask                 */
#define INTC_IMRL_MASK30_SHIFT                   (30U)                                               /*!< INTC0_IMRL: MASK30 Position             */
#define INTC_IMRL_MASK30(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK30_SHIFT))&INTC_IMRL_MASK30_MASK) /*!< INTC0_IMRL                              */
#define INTC_IMRL_MASK31_MASK                    (0x80000000U)                                       /*!< INTC0_IMRL: MASK31 Mask                 */
#define INTC_IMRL_MASK31_SHIFT                   (31U)                                               /*!< INTC0_IMRL: MASK31 Position             */
#define INTC_IMRL_MASK31(x)                      (((uint32_t)(((uint32_t)(x))<<INTC_IMRL_MASK31_SHIFT))&INTC_IMRL_MASK31_MASK) /*!< INTC0_IMRL                              */
/* ------- INTFRCH Bit Fields                       ------ */
#define INTC_INTFRCH_FRCH32_MASK                 (0x1U)                                              /*!< INTC0_INTFRCH: FRCH32 Mask              */
#define INTC_INTFRCH_FRCH32_SHIFT                (0U)                                                /*!< INTC0_INTFRCH: FRCH32 Position          */
#define INTC_INTFRCH_FRCH32(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH32_SHIFT))&INTC_INTFRCH_FRCH32_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH33_MASK                 (0x2U)                                              /*!< INTC0_INTFRCH: FRCH33 Mask              */
#define INTC_INTFRCH_FRCH33_SHIFT                (1U)                                                /*!< INTC0_INTFRCH: FRCH33 Position          */
#define INTC_INTFRCH_FRCH33(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH33_SHIFT))&INTC_INTFRCH_FRCH33_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH34_MASK                 (0x4U)                                              /*!< INTC0_INTFRCH: FRCH34 Mask              */
#define INTC_INTFRCH_FRCH34_SHIFT                (2U)                                                /*!< INTC0_INTFRCH: FRCH34 Position          */
#define INTC_INTFRCH_FRCH34(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH34_SHIFT))&INTC_INTFRCH_FRCH34_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH35_MASK                 (0x8U)                                              /*!< INTC0_INTFRCH: FRCH35 Mask              */
#define INTC_INTFRCH_FRCH35_SHIFT                (3U)                                                /*!< INTC0_INTFRCH: FRCH35 Position          */
#define INTC_INTFRCH_FRCH35(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH35_SHIFT))&INTC_INTFRCH_FRCH35_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH36_MASK                 (0x10U)                                             /*!< INTC0_INTFRCH: FRCH36 Mask              */
#define INTC_INTFRCH_FRCH36_SHIFT                (4U)                                                /*!< INTC0_INTFRCH: FRCH36 Position          */
#define INTC_INTFRCH_FRCH36(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH36_SHIFT))&INTC_INTFRCH_FRCH36_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH37_MASK                 (0x20U)                                             /*!< INTC0_INTFRCH: FRCH37 Mask              */
#define INTC_INTFRCH_FRCH37_SHIFT                (5U)                                                /*!< INTC0_INTFRCH: FRCH37 Position          */
#define INTC_INTFRCH_FRCH37(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH37_SHIFT))&INTC_INTFRCH_FRCH37_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH38_MASK                 (0x40U)                                             /*!< INTC0_INTFRCH: FRCH38 Mask              */
#define INTC_INTFRCH_FRCH38_SHIFT                (6U)                                                /*!< INTC0_INTFRCH: FRCH38 Position          */
#define INTC_INTFRCH_FRCH38(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH38_SHIFT))&INTC_INTFRCH_FRCH38_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH39_MASK                 (0x80U)                                             /*!< INTC0_INTFRCH: FRCH39 Mask              */
#define INTC_INTFRCH_FRCH39_SHIFT                (7U)                                                /*!< INTC0_INTFRCH: FRCH39 Position          */
#define INTC_INTFRCH_FRCH39(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH39_SHIFT))&INTC_INTFRCH_FRCH39_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH40_MASK                 (0x100U)                                            /*!< INTC0_INTFRCH: FRCH40 Mask              */
#define INTC_INTFRCH_FRCH40_SHIFT                (8U)                                                /*!< INTC0_INTFRCH: FRCH40 Position          */
#define INTC_INTFRCH_FRCH40(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH40_SHIFT))&INTC_INTFRCH_FRCH40_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH41_MASK                 (0x200U)                                            /*!< INTC0_INTFRCH: FRCH41 Mask              */
#define INTC_INTFRCH_FRCH41_SHIFT                (9U)                                                /*!< INTC0_INTFRCH: FRCH41 Position          */
#define INTC_INTFRCH_FRCH41(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH41_SHIFT))&INTC_INTFRCH_FRCH41_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH42_MASK                 (0x400U)                                            /*!< INTC0_INTFRCH: FRCH42 Mask              */
#define INTC_INTFRCH_FRCH42_SHIFT                (10U)                                               /*!< INTC0_INTFRCH: FRCH42 Position          */
#define INTC_INTFRCH_FRCH42(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH42_SHIFT))&INTC_INTFRCH_FRCH42_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH43_MASK                 (0x800U)                                            /*!< INTC0_INTFRCH: FRCH43 Mask              */
#define INTC_INTFRCH_FRCH43_SHIFT                (11U)                                               /*!< INTC0_INTFRCH: FRCH43 Position          */
#define INTC_INTFRCH_FRCH43(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH43_SHIFT))&INTC_INTFRCH_FRCH43_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH44_MASK                 (0x1000U)                                           /*!< INTC0_INTFRCH: FRCH44 Mask              */
#define INTC_INTFRCH_FRCH44_SHIFT                (12U)                                               /*!< INTC0_INTFRCH: FRCH44 Position          */
#define INTC_INTFRCH_FRCH44(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH44_SHIFT))&INTC_INTFRCH_FRCH44_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH45_MASK                 (0x2000U)                                           /*!< INTC0_INTFRCH: FRCH45 Mask              */
#define INTC_INTFRCH_FRCH45_SHIFT                (13U)                                               /*!< INTC0_INTFRCH: FRCH45 Position          */
#define INTC_INTFRCH_FRCH45(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH45_SHIFT))&INTC_INTFRCH_FRCH45_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH46_MASK                 (0x4000U)                                           /*!< INTC0_INTFRCH: FRCH46 Mask              */
#define INTC_INTFRCH_FRCH46_SHIFT                (14U)                                               /*!< INTC0_INTFRCH: FRCH46 Position          */
#define INTC_INTFRCH_FRCH46(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH46_SHIFT))&INTC_INTFRCH_FRCH46_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH47_MASK                 (0x8000U)                                           /*!< INTC0_INTFRCH: FRCH47 Mask              */
#define INTC_INTFRCH_FRCH47_SHIFT                (15U)                                               /*!< INTC0_INTFRCH: FRCH47 Position          */
#define INTC_INTFRCH_FRCH47(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH47_SHIFT))&INTC_INTFRCH_FRCH47_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH48_MASK                 (0x10000U)                                          /*!< INTC0_INTFRCH: FRCH48 Mask              */
#define INTC_INTFRCH_FRCH48_SHIFT                (16U)                                               /*!< INTC0_INTFRCH: FRCH48 Position          */
#define INTC_INTFRCH_FRCH48(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH48_SHIFT))&INTC_INTFRCH_FRCH48_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH49_MASK                 (0x20000U)                                          /*!< INTC0_INTFRCH: FRCH49 Mask              */
#define INTC_INTFRCH_FRCH49_SHIFT                (17U)                                               /*!< INTC0_INTFRCH: FRCH49 Position          */
#define INTC_INTFRCH_FRCH49(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH49_SHIFT))&INTC_INTFRCH_FRCH49_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH50_MASK                 (0x40000U)                                          /*!< INTC0_INTFRCH: FRCH50 Mask              */
#define INTC_INTFRCH_FRCH50_SHIFT                (18U)                                               /*!< INTC0_INTFRCH: FRCH50 Position          */
#define INTC_INTFRCH_FRCH50(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH50_SHIFT))&INTC_INTFRCH_FRCH50_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH51_MASK                 (0x80000U)                                          /*!< INTC0_INTFRCH: FRCH51 Mask              */
#define INTC_INTFRCH_FRCH51_SHIFT                (19U)                                               /*!< INTC0_INTFRCH: FRCH51 Position          */
#define INTC_INTFRCH_FRCH51(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH51_SHIFT))&INTC_INTFRCH_FRCH51_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH52_MASK                 (0x100000U)                                         /*!< INTC0_INTFRCH: FRCH52 Mask              */
#define INTC_INTFRCH_FRCH52_SHIFT                (20U)                                               /*!< INTC0_INTFRCH: FRCH52 Position          */
#define INTC_INTFRCH_FRCH52(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH52_SHIFT))&INTC_INTFRCH_FRCH52_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH53_MASK                 (0x200000U)                                         /*!< INTC0_INTFRCH: FRCH53 Mask              */
#define INTC_INTFRCH_FRCH53_SHIFT                (21U)                                               /*!< INTC0_INTFRCH: FRCH53 Position          */
#define INTC_INTFRCH_FRCH53(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH53_SHIFT))&INTC_INTFRCH_FRCH53_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH54_MASK                 (0x400000U)                                         /*!< INTC0_INTFRCH: FRCH54 Mask              */
#define INTC_INTFRCH_FRCH54_SHIFT                (22U)                                               /*!< INTC0_INTFRCH: FRCH54 Position          */
#define INTC_INTFRCH_FRCH54(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH54_SHIFT))&INTC_INTFRCH_FRCH54_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH55_MASK                 (0x800000U)                                         /*!< INTC0_INTFRCH: FRCH55 Mask              */
#define INTC_INTFRCH_FRCH55_SHIFT                (23U)                                               /*!< INTC0_INTFRCH: FRCH55 Position          */
#define INTC_INTFRCH_FRCH55(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH55_SHIFT))&INTC_INTFRCH_FRCH55_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH56_MASK                 (0x1000000U)                                        /*!< INTC0_INTFRCH: FRCH56 Mask              */
#define INTC_INTFRCH_FRCH56_SHIFT                (24U)                                               /*!< INTC0_INTFRCH: FRCH56 Position          */
#define INTC_INTFRCH_FRCH56(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH56_SHIFT))&INTC_INTFRCH_FRCH56_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH57_MASK                 (0x2000000U)                                        /*!< INTC0_INTFRCH: FRCH57 Mask              */
#define INTC_INTFRCH_FRCH57_SHIFT                (25U)                                               /*!< INTC0_INTFRCH: FRCH57 Position          */
#define INTC_INTFRCH_FRCH57(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH57_SHIFT))&INTC_INTFRCH_FRCH57_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH58_MASK                 (0x4000000U)                                        /*!< INTC0_INTFRCH: FRCH58 Mask              */
#define INTC_INTFRCH_FRCH58_SHIFT                (26U)                                               /*!< INTC0_INTFRCH: FRCH58 Position          */
#define INTC_INTFRCH_FRCH58(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH58_SHIFT))&INTC_INTFRCH_FRCH58_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH59_MASK                 (0x8000000U)                                        /*!< INTC0_INTFRCH: FRCH59 Mask              */
#define INTC_INTFRCH_FRCH59_SHIFT                (27U)                                               /*!< INTC0_INTFRCH: FRCH59 Position          */
#define INTC_INTFRCH_FRCH59(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH59_SHIFT))&INTC_INTFRCH_FRCH59_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH60_MASK                 (0x10000000U)                                       /*!< INTC0_INTFRCH: FRCH60 Mask              */
#define INTC_INTFRCH_FRCH60_SHIFT                (28U)                                               /*!< INTC0_INTFRCH: FRCH60 Position          */
#define INTC_INTFRCH_FRCH60(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH60_SHIFT))&INTC_INTFRCH_FRCH60_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH61_MASK                 (0x20000000U)                                       /*!< INTC0_INTFRCH: FRCH61 Mask              */
#define INTC_INTFRCH_FRCH61_SHIFT                (29U)                                               /*!< INTC0_INTFRCH: FRCH61 Position          */
#define INTC_INTFRCH_FRCH61(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH61_SHIFT))&INTC_INTFRCH_FRCH61_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH62_MASK                 (0x40000000U)                                       /*!< INTC0_INTFRCH: FRCH62 Mask              */
#define INTC_INTFRCH_FRCH62_SHIFT                (30U)                                               /*!< INTC0_INTFRCH: FRCH62 Position          */
#define INTC_INTFRCH_FRCH62(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH62_SHIFT))&INTC_INTFRCH_FRCH62_MASK) /*!< INTC0_INTFRCH                           */
#define INTC_INTFRCH_FRCH63_MASK                 (0x80000000U)                                       /*!< INTC0_INTFRCH: FRCH63 Mask              */
#define INTC_INTFRCH_FRCH63_SHIFT                (31U)                                               /*!< INTC0_INTFRCH: FRCH63 Position          */
#define INTC_INTFRCH_FRCH63(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCH_FRCH63_SHIFT))&INTC_INTFRCH_FRCH63_MASK) /*!< INTC0_INTFRCH                           */
/* ------- INTFRCL Bit Fields                       ------ */
#define INTC_INTFRCL_FRCH1_MASK                  (0x2U)                                              /*!< INTC0_INTFRCL: FRCH1 Mask               */
#define INTC_INTFRCL_FRCH1_SHIFT                 (1U)                                                /*!< INTC0_INTFRCL: FRCH1 Position           */
#define INTC_INTFRCL_FRCH1(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH1_SHIFT))&INTC_INTFRCL_FRCH1_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH2_MASK                  (0x4U)                                              /*!< INTC0_INTFRCL: FRCH2 Mask               */
#define INTC_INTFRCL_FRCH2_SHIFT                 (2U)                                                /*!< INTC0_INTFRCL: FRCH2 Position           */
#define INTC_INTFRCL_FRCH2(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH2_SHIFT))&INTC_INTFRCL_FRCH2_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH3_MASK                  (0x8U)                                              /*!< INTC0_INTFRCL: FRCH3 Mask               */
#define INTC_INTFRCL_FRCH3_SHIFT                 (3U)                                                /*!< INTC0_INTFRCL: FRCH3 Position           */
#define INTC_INTFRCL_FRCH3(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH3_SHIFT))&INTC_INTFRCL_FRCH3_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH4_MASK                  (0x10U)                                             /*!< INTC0_INTFRCL: FRCH4 Mask               */
#define INTC_INTFRCL_FRCH4_SHIFT                 (4U)                                                /*!< INTC0_INTFRCL: FRCH4 Position           */
#define INTC_INTFRCL_FRCH4(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH4_SHIFT))&INTC_INTFRCL_FRCH4_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH5_MASK                  (0x20U)                                             /*!< INTC0_INTFRCL: FRCH5 Mask               */
#define INTC_INTFRCL_FRCH5_SHIFT                 (5U)                                                /*!< INTC0_INTFRCL: FRCH5 Position           */
#define INTC_INTFRCL_FRCH5(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH5_SHIFT))&INTC_INTFRCL_FRCH5_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH6_MASK                  (0x40U)                                             /*!< INTC0_INTFRCL: FRCH6 Mask               */
#define INTC_INTFRCL_FRCH6_SHIFT                 (6U)                                                /*!< INTC0_INTFRCL: FRCH6 Position           */
#define INTC_INTFRCL_FRCH6(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH6_SHIFT))&INTC_INTFRCL_FRCH6_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH7_MASK                  (0x80U)                                             /*!< INTC0_INTFRCL: FRCH7 Mask               */
#define INTC_INTFRCL_FRCH7_SHIFT                 (7U)                                                /*!< INTC0_INTFRCL: FRCH7 Position           */
#define INTC_INTFRCL_FRCH7(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH7_SHIFT))&INTC_INTFRCL_FRCH7_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH8_MASK                  (0x100U)                                            /*!< INTC0_INTFRCL: FRCH8 Mask               */
#define INTC_INTFRCL_FRCH8_SHIFT                 (8U)                                                /*!< INTC0_INTFRCL: FRCH8 Position           */
#define INTC_INTFRCL_FRCH8(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH8_SHIFT))&INTC_INTFRCL_FRCH8_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH9_MASK                  (0x200U)                                            /*!< INTC0_INTFRCL: FRCH9 Mask               */
#define INTC_INTFRCL_FRCH9_SHIFT                 (9U)                                                /*!< INTC0_INTFRCL: FRCH9 Position           */
#define INTC_INTFRCL_FRCH9(x)                    (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH9_SHIFT))&INTC_INTFRCL_FRCH9_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH10_MASK                 (0x400U)                                            /*!< INTC0_INTFRCL: FRCH10 Mask              */
#define INTC_INTFRCL_FRCH10_SHIFT                (10U)                                               /*!< INTC0_INTFRCL: FRCH10 Position          */
#define INTC_INTFRCL_FRCH10(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH10_SHIFT))&INTC_INTFRCL_FRCH10_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH11_MASK                 (0x800U)                                            /*!< INTC0_INTFRCL: FRCH11 Mask              */
#define INTC_INTFRCL_FRCH11_SHIFT                (11U)                                               /*!< INTC0_INTFRCL: FRCH11 Position          */
#define INTC_INTFRCL_FRCH11(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH11_SHIFT))&INTC_INTFRCL_FRCH11_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH12_MASK                 (0x1000U)                                           /*!< INTC0_INTFRCL: FRCH12 Mask              */
#define INTC_INTFRCL_FRCH12_SHIFT                (12U)                                               /*!< INTC0_INTFRCL: FRCH12 Position          */
#define INTC_INTFRCL_FRCH12(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH12_SHIFT))&INTC_INTFRCL_FRCH12_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH13_MASK                 (0x2000U)                                           /*!< INTC0_INTFRCL: FRCH13 Mask              */
#define INTC_INTFRCL_FRCH13_SHIFT                (13U)                                               /*!< INTC0_INTFRCL: FRCH13 Position          */
#define INTC_INTFRCL_FRCH13(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH13_SHIFT))&INTC_INTFRCL_FRCH13_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH14_MASK                 (0x4000U)                                           /*!< INTC0_INTFRCL: FRCH14 Mask              */
#define INTC_INTFRCL_FRCH14_SHIFT                (14U)                                               /*!< INTC0_INTFRCL: FRCH14 Position          */
#define INTC_INTFRCL_FRCH14(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH14_SHIFT))&INTC_INTFRCL_FRCH14_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH15_MASK                 (0x8000U)                                           /*!< INTC0_INTFRCL: FRCH15 Mask              */
#define INTC_INTFRCL_FRCH15_SHIFT                (15U)                                               /*!< INTC0_INTFRCL: FRCH15 Position          */
#define INTC_INTFRCL_FRCH15(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH15_SHIFT))&INTC_INTFRCL_FRCH15_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH16_MASK                 (0x10000U)                                          /*!< INTC0_INTFRCL: FRCH16 Mask              */
#define INTC_INTFRCL_FRCH16_SHIFT                (16U)                                               /*!< INTC0_INTFRCL: FRCH16 Position          */
#define INTC_INTFRCL_FRCH16(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH16_SHIFT))&INTC_INTFRCL_FRCH16_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH17_MASK                 (0x20000U)                                          /*!< INTC0_INTFRCL: FRCH17 Mask              */
#define INTC_INTFRCL_FRCH17_SHIFT                (17U)                                               /*!< INTC0_INTFRCL: FRCH17 Position          */
#define INTC_INTFRCL_FRCH17(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH17_SHIFT))&INTC_INTFRCL_FRCH17_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH18_MASK                 (0x40000U)                                          /*!< INTC0_INTFRCL: FRCH18 Mask              */
#define INTC_INTFRCL_FRCH18_SHIFT                (18U)                                               /*!< INTC0_INTFRCL: FRCH18 Position          */
#define INTC_INTFRCL_FRCH18(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH18_SHIFT))&INTC_INTFRCL_FRCH18_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH19_MASK                 (0x80000U)                                          /*!< INTC0_INTFRCL: FRCH19 Mask              */
#define INTC_INTFRCL_FRCH19_SHIFT                (19U)                                               /*!< INTC0_INTFRCL: FRCH19 Position          */
#define INTC_INTFRCL_FRCH19(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH19_SHIFT))&INTC_INTFRCL_FRCH19_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH20_MASK                 (0x100000U)                                         /*!< INTC0_INTFRCL: FRCH20 Mask              */
#define INTC_INTFRCL_FRCH20_SHIFT                (20U)                                               /*!< INTC0_INTFRCL: FRCH20 Position          */
#define INTC_INTFRCL_FRCH20(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH20_SHIFT))&INTC_INTFRCL_FRCH20_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH21_MASK                 (0x200000U)                                         /*!< INTC0_INTFRCL: FRCH21 Mask              */
#define INTC_INTFRCL_FRCH21_SHIFT                (21U)                                               /*!< INTC0_INTFRCL: FRCH21 Position          */
#define INTC_INTFRCL_FRCH21(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH21_SHIFT))&INTC_INTFRCL_FRCH21_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH22_MASK                 (0x400000U)                                         /*!< INTC0_INTFRCL: FRCH22 Mask              */
#define INTC_INTFRCL_FRCH22_SHIFT                (22U)                                               /*!< INTC0_INTFRCL: FRCH22 Position          */
#define INTC_INTFRCL_FRCH22(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH22_SHIFT))&INTC_INTFRCL_FRCH22_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH23_MASK                 (0x800000U)                                         /*!< INTC0_INTFRCL: FRCH23 Mask              */
#define INTC_INTFRCL_FRCH23_SHIFT                (23U)                                               /*!< INTC0_INTFRCL: FRCH23 Position          */
#define INTC_INTFRCL_FRCH23(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH23_SHIFT))&INTC_INTFRCL_FRCH23_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH24_MASK                 (0x1000000U)                                        /*!< INTC0_INTFRCL: FRCH24 Mask              */
#define INTC_INTFRCL_FRCH24_SHIFT                (24U)                                               /*!< INTC0_INTFRCL: FRCH24 Position          */
#define INTC_INTFRCL_FRCH24(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH24_SHIFT))&INTC_INTFRCL_FRCH24_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH25_MASK                 (0x2000000U)                                        /*!< INTC0_INTFRCL: FRCH25 Mask              */
#define INTC_INTFRCL_FRCH25_SHIFT                (25U)                                               /*!< INTC0_INTFRCL: FRCH25 Position          */
#define INTC_INTFRCL_FRCH25(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH25_SHIFT))&INTC_INTFRCL_FRCH25_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH26_MASK                 (0x4000000U)                                        /*!< INTC0_INTFRCL: FRCH26 Mask              */
#define INTC_INTFRCL_FRCH26_SHIFT                (26U)                                               /*!< INTC0_INTFRCL: FRCH26 Position          */
#define INTC_INTFRCL_FRCH26(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH26_SHIFT))&INTC_INTFRCL_FRCH26_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH27_MASK                 (0x8000000U)                                        /*!< INTC0_INTFRCL: FRCH27 Mask              */
#define INTC_INTFRCL_FRCH27_SHIFT                (27U)                                               /*!< INTC0_INTFRCL: FRCH27 Position          */
#define INTC_INTFRCL_FRCH27(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH27_SHIFT))&INTC_INTFRCL_FRCH27_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH28_MASK                 (0x10000000U)                                       /*!< INTC0_INTFRCL: FRCH28 Mask              */
#define INTC_INTFRCL_FRCH28_SHIFT                (28U)                                               /*!< INTC0_INTFRCL: FRCH28 Position          */
#define INTC_INTFRCL_FRCH28(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH28_SHIFT))&INTC_INTFRCL_FRCH28_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH29_MASK                 (0x20000000U)                                       /*!< INTC0_INTFRCL: FRCH29 Mask              */
#define INTC_INTFRCL_FRCH29_SHIFT                (29U)                                               /*!< INTC0_INTFRCL: FRCH29 Position          */
#define INTC_INTFRCL_FRCH29(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH29_SHIFT))&INTC_INTFRCL_FRCH29_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH30_MASK                 (0x40000000U)                                       /*!< INTC0_INTFRCL: FRCH30 Mask              */
#define INTC_INTFRCL_FRCH30_SHIFT                (30U)                                               /*!< INTC0_INTFRCL: FRCH30 Position          */
#define INTC_INTFRCL_FRCH30(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH30_SHIFT))&INTC_INTFRCL_FRCH30_MASK) /*!< INTC0_INTFRCL                           */
#define INTC_INTFRCL_FRCH31_MASK                 (0x80000000U)                                       /*!< INTC0_INTFRCL: FRCH31 Mask              */
#define INTC_INTFRCL_FRCH31_SHIFT                (31U)                                               /*!< INTC0_INTFRCL: FRCH31 Position          */
#define INTC_INTFRCL_FRCH31(x)                   (((uint32_t)(((uint32_t)(x))<<INTC_INTFRCL_FRCH31_SHIFT))&INTC_INTFRCL_FRCH31_MASK) /*!< INTC0_INTFRCL                           */
/* ------- IRLR Bit Fields                          ------ */
#define INTC_IRLR_IRQ1_MASK                      (0x2U)                                              /*!< INTC0_IRLR: IRQ1 Mask                   */
#define INTC_IRLR_IRQ1_SHIFT                     (1U)                                                /*!< INTC0_IRLR: IRQ1 Position               */
#define INTC_IRLR_IRQ1(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_IRLR_IRQ1_SHIFT))&INTC_IRLR_IRQ1_MASK) /*!< INTC0_IRLR                              */
#define INTC_IRLR_IRQ2_MASK                      (0x4U)                                              /*!< INTC0_IRLR: IRQ2 Mask                   */
#define INTC_IRLR_IRQ2_SHIFT                     (2U)                                                /*!< INTC0_IRLR: IRQ2 Position               */
#define INTC_IRLR_IRQ2(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_IRLR_IRQ2_SHIFT))&INTC_IRLR_IRQ2_MASK) /*!< INTC0_IRLR                              */
#define INTC_IRLR_IRQ3_MASK                      (0x8U)                                              /*!< INTC0_IRLR: IRQ3 Mask                   */
#define INTC_IRLR_IRQ3_SHIFT                     (3U)                                                /*!< INTC0_IRLR: IRQ3 Position               */
#define INTC_IRLR_IRQ3(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_IRLR_IRQ3_SHIFT))&INTC_IRLR_IRQ3_MASK) /*!< INTC0_IRLR                              */
#define INTC_IRLR_IRQ4_MASK                      (0x10U)                                             /*!< INTC0_IRLR: IRQ4 Mask                   */
#define INTC_IRLR_IRQ4_SHIFT                     (4U)                                                /*!< INTC0_IRLR: IRQ4 Position               */
#define INTC_IRLR_IRQ4(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_IRLR_IRQ4_SHIFT))&INTC_IRLR_IRQ4_MASK) /*!< INTC0_IRLR                              */
#define INTC_IRLR_IRQ5_MASK                      (0x20U)                                             /*!< INTC0_IRLR: IRQ5 Mask                   */
#define INTC_IRLR_IRQ5_SHIFT                     (5U)                                                /*!< INTC0_IRLR: IRQ5 Position               */
#define INTC_IRLR_IRQ5(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_IRLR_IRQ5_SHIFT))&INTC_IRLR_IRQ5_MASK) /*!< INTC0_IRLR                              */
#define INTC_IRLR_IRQ6_MASK                      (0x40U)                                             /*!< INTC0_IRLR: IRQ6 Mask                   */
#define INTC_IRLR_IRQ6_SHIFT                     (6U)                                                /*!< INTC0_IRLR: IRQ6 Position               */
#define INTC_IRLR_IRQ6(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_IRLR_IRQ6_SHIFT))&INTC_IRLR_IRQ6_MASK) /*!< INTC0_IRLR                              */
#define INTC_IRLR_IRQ7_MASK                      (0x80U)                                             /*!< INTC0_IRLR: IRQ7 Mask                   */
#define INTC_IRLR_IRQ7_SHIFT                     (7U)                                                /*!< INTC0_IRLR: IRQ7 Position               */
#define INTC_IRLR_IRQ7(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_IRLR_IRQ7_SHIFT))&INTC_IRLR_IRQ7_MASK) /*!< INTC0_IRLR                              */
/* ------- IACKLPR Bit Fields                       ------ */
#define INTC_IACKLPR_PRI_MASK                    (0xFU)                                              /*!< INTC0_IACKLPR: PRI Mask                 */
#define INTC_IACKLPR_PRI_SHIFT                   (0U)                                                /*!< INTC0_IACKLPR: PRI Position             */
#define INTC_IACKLPR_PRI(x)                      (((uint8_t)(((uint8_t)(x))<<INTC_IACKLPR_PRI_SHIFT))&INTC_IACKLPR_PRI_MASK) /*!< INTC0_IACKLPR                           */
#define INTC_IACKLPR_LEVEL_MASK                  (0x70U)                                             /*!< INTC0_IACKLPR: LEVEL Mask               */
#define INTC_IACKLPR_LEVEL_SHIFT                 (4U)                                                /*!< INTC0_IACKLPR: LEVEL Position           */
#define INTC_IACKLPR_LEVEL(x)                    (((uint8_t)(((uint8_t)(x))<<INTC_IACKLPR_LEVEL_SHIFT))&INTC_IACKLPR_LEVEL_MASK) /*!< INTC0_IACKLPR                           */
/* ------- ICR Bit Fields                           ------ */
#define INTC_ICR_IP_MASK                         (0x7U)                                              /*!< INTC0_ICR: IP Mask                      */
#define INTC_ICR_IP_SHIFT                        (0U)                                                /*!< INTC0_ICR: IP Position                  */
#define INTC_ICR_IP(x)                           (((uint8_t)(((uint8_t)(x))<<INTC_ICR_IP_SHIFT))&INTC_ICR_IP_MASK) /*!< INTC0_ICR                               */
#define INTC_ICR_IL_MASK                         (0x38U)                                             /*!< INTC0_ICR: IL Mask                      */
#define INTC_ICR_IL_SHIFT                        (3U)                                                /*!< INTC0_ICR: IL Position                  */
#define INTC_ICR_IL(x)                           (((uint8_t)(((uint8_t)(x))<<INTC_ICR_IL_SHIFT))&INTC_ICR_IL_MASK) /*!< INTC0_ICR                               */
/* ------- ICR Bit Fields                           ------ */
/* ------- SWIACK Bit Fields                        ------ */
/* ------- LIACK Bit Fields                         ------ */
/**
 * @} */ /* End group INTC_Register_Masks_GROUP 
 */

/* INTC0 - Peripheral instance base addresses */
#define INTC0_BasePtr                  0x40000C00UL //!< Peripheral base address
#define INTC0                          ((INTC_Type *) INTC0_BasePtr) //!< Freescale base pointer
#define INTC0_BASE_PTR                 (INTC0) //!< Freescale style base pointer
/**
 * @} */ /* End group INTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup INTC_Peripheral_access_layer_GROUP INTC Peripheral Access Layer
* @brief C Struct for INTC
* @{
*/

/* ================================================================================ */
/* ================           INTC1 (derived from INTC0)           ================ */
/* ================================================================================ */

/**
 * @brief Interrupt Controller Module
 */

/* INTC1 - Peripheral instance base addresses */
#define INTC1_BasePtr                  0x40000D00UL //!< Peripheral base address
#define INTC1                          ((INTC_Type *) INTC1_BasePtr) //!< Freescale base pointer
#define INTC1_BASE_PTR                 (INTC1) //!< Freescale style base pointer
/**
 * @} */ /* End group INTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PAD_Peripheral_access_layer_GROUP PAD Peripheral Access Layer
* @brief C Struct for PAD
* @{
*/

/* ================================================================================ */
/* ================           PAD (file:MCF52233_PAD)              ================ */
/* ================================================================================ */

/**
 * @brief Pin Configuration
 */
/**
* @addtogroup PAD_structs_GROUP PAD struct
* @brief Struct for PAD
* @{
*/
typedef struct {                                /*       PAD Structure                                                */
   __IO uint16_t  PWOR;                         /**< 0000: Pin Wired OR Register                                        */
   __IO uint16_t  PDSR1;                        /**< 0002: Pin Drive Strength Register 1                                */
   __IO uint32_t  PDSR0;                        /**< 0004: Pin Drive Strength Register 0                                */
} PAD_Type;

/**
 * @} */ /* End group PAD_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PAD' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PAD_Register_Masks_GROUP PAD Register Masks
* @brief Register Masks for PAD
* @{
*/
/* ------- PWOR Bit Fields                          ------ */
#define PAD_PWOR_PWOR0_MASK                      (0xFFFFU)                                           /*!< PAD_PWOR: PWOR0 Mask                    */
#define PAD_PWOR_PWOR0_SHIFT                     (0U)                                                /*!< PAD_PWOR: PWOR0 Position                */
#define PAD_PWOR_PWOR0(x)                        (((uint16_t)(((uint16_t)(x))<<PAD_PWOR_PWOR0_SHIFT))&PAD_PWOR_PWOR0_MASK) /*!< PAD_PWOR                                */
/* ------- PDSR1 Bit Fields                         ------ */
#define PAD_PDSR1_PDSRx_MASK                     (0xFFFFU)                                           /*!< PAD_PDSR1: PDSRx Mask                   */
#define PAD_PDSR1_PDSRx_SHIFT                    (0U)                                                /*!< PAD_PDSR1: PDSRx Position               */
#define PAD_PDSR1_PDSRx(x)                       (((uint16_t)(((uint16_t)(x))<<PAD_PDSR1_PDSRx_SHIFT))&PAD_PDSR1_PDSRx_MASK) /*!< PAD_PDSR1                               */
/* ------- PDSR0 Bit Fields                         ------ */
#define PAD_PDSR0_PDSR0_MASK                     (0xFFFFFFFFU)                                       /*!< PAD_PDSR0: PDSR0 Mask                   */
#define PAD_PDSR0_PDSR0_SHIFT                    (0U)                                                /*!< PAD_PDSR0: PDSR0 Position               */
#define PAD_PDSR0_PDSR0(x)                       (((uint32_t)(((uint32_t)(x))<<PAD_PDSR0_PDSR0_SHIFT))&PAD_PDSR0_PDSR0_MASK) /*!< PAD_PDSR0                               */
/**
 * @} */ /* End group PAD_Register_Masks_GROUP 
 */

/* PAD - Peripheral instance base addresses */
#define PAD_BasePtr                    0x40100078UL //!< Peripheral base address
#define PAD                            ((PAD_Type *) PAD_BasePtr) //!< Freescale base pointer
#define PAD_BASE_PTR                   (PAD) //!< Freescale style base pointer
/**
 * @} */ /* End group PAD_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT0 (file:MCF522xx_PIT0)            ================ */
/* ================================================================================ */

/**
 * @brief Programmable Interrupt Timer
The PIT is a 16-bit timer that provides precise interrupts at regular intervals with minimal processor intervention. 
The timer can count down from the value written in the modulus register or it can be a free-running down-counter
 */
/**
* @addtogroup PIT_structs_GROUP PIT struct
* @brief Struct for PIT
* @{
*/
typedef struct {                                /*       PIT0 Structure                                               */
   __IO uint16_t  PCSR;                         /**< 0000: Control and Status Register                                  */
   __IO uint16_t  PMR;                          /**< 0002: Modulus Register                                             */
   __I  uint16_t  PCNTR;                        /**< 0004: Count Register                                               */
} PIT_Type;

/**
 * @} */ /* End group PIT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PIT0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PIT_Register_Masks_GROUP PIT Register Masks
* @brief Register Masks for PIT
* @{
*/
/* ------- PCSR Bit Fields                          ------ */
#define PIT_PCSR_EN_MASK                         (0x1U)                                              /*!< PIT0_PCSR: EN Mask                      */
#define PIT_PCSR_EN_SHIFT                        (0U)                                                /*!< PIT0_PCSR: EN Position                  */
#define PIT_PCSR_EN(x)                           (((uint16_t)(((uint16_t)(x))<<PIT_PCSR_EN_SHIFT))&PIT_PCSR_EN_MASK) /*!< PIT0_PCSR                               */
#define PIT_PCSR_RLD_MASK                        (0x2U)                                              /*!< PIT0_PCSR: RLD Mask                     */
#define PIT_PCSR_RLD_SHIFT                       (1U)                                                /*!< PIT0_PCSR: RLD Position                 */
#define PIT_PCSR_RLD(x)                          (((uint16_t)(((uint16_t)(x))<<PIT_PCSR_RLD_SHIFT))&PIT_PCSR_RLD_MASK) /*!< PIT0_PCSR                               */
#define PIT_PCSR_PIF_MASK                        (0x4U)                                              /*!< PIT0_PCSR: PIF Mask                     */
#define PIT_PCSR_PIF_SHIFT                       (2U)                                                /*!< PIT0_PCSR: PIF Position                 */
#define PIT_PCSR_PIF(x)                          (((uint16_t)(((uint16_t)(x))<<PIT_PCSR_PIF_SHIFT))&PIT_PCSR_PIF_MASK) /*!< PIT0_PCSR                               */
#define PIT_PCSR_PIE_MASK                        (0x8U)                                              /*!< PIT0_PCSR: PIE Mask                     */
#define PIT_PCSR_PIE_SHIFT                       (3U)                                                /*!< PIT0_PCSR: PIE Position                 */
#define PIT_PCSR_PIE(x)                          (((uint16_t)(((uint16_t)(x))<<PIT_PCSR_PIE_SHIFT))&PIT_PCSR_PIE_MASK) /*!< PIT0_PCSR                               */
#define PIT_PCSR_OVW_MASK                        (0x10U)                                             /*!< PIT0_PCSR: OVW Mask                     */
#define PIT_PCSR_OVW_SHIFT                       (4U)                                                /*!< PIT0_PCSR: OVW Position                 */
#define PIT_PCSR_OVW(x)                          (((uint16_t)(((uint16_t)(x))<<PIT_PCSR_OVW_SHIFT))&PIT_PCSR_OVW_MASK) /*!< PIT0_PCSR                               */
#define PIT_PCSR_DBG_MASK                        (0x20U)                                             /*!< PIT0_PCSR: DBG Mask                     */
#define PIT_PCSR_DBG_SHIFT                       (5U)                                                /*!< PIT0_PCSR: DBG Position                 */
#define PIT_PCSR_DBG(x)                          (((uint16_t)(((uint16_t)(x))<<PIT_PCSR_DBG_SHIFT))&PIT_PCSR_DBG_MASK) /*!< PIT0_PCSR                               */
#define PIT_PCSR_DOZE_MASK                       (0x40U)                                             /*!< PIT0_PCSR: DOZE Mask                    */
#define PIT_PCSR_DOZE_SHIFT                      (6U)                                                /*!< PIT0_PCSR: DOZE Position                */
#define PIT_PCSR_DOZE(x)                         (((uint16_t)(((uint16_t)(x))<<PIT_PCSR_DOZE_SHIFT))&PIT_PCSR_DOZE_MASK) /*!< PIT0_PCSR                               */
#define PIT_PCSR_PRE_MASK                        (0xF00U)                                            /*!< PIT0_PCSR: PRE Mask                     */
#define PIT_PCSR_PRE_SHIFT                       (8U)                                                /*!< PIT0_PCSR: PRE Position                 */
#define PIT_PCSR_PRE(x)                          (((uint16_t)(((uint16_t)(x))<<PIT_PCSR_PRE_SHIFT))&PIT_PCSR_PRE_MASK) /*!< PIT0_PCSR                               */
/* ------- PMR Bit Fields                           ------ */
#define PIT_PMR_PM_MASK                          (0xFFFFU)                                           /*!< PIT0_PMR: PM Mask                       */
#define PIT_PMR_PM_SHIFT                         (0U)                                                /*!< PIT0_PMR: PM Position                   */
#define PIT_PMR_PM(x)                            (((uint16_t)(((uint16_t)(x))<<PIT_PMR_PM_SHIFT))&PIT_PMR_PM_MASK) /*!< PIT0_PMR                                */
/* ------- PCNTR Bit Fields                         ------ */
#define PIT_PCNTR_PC_MASK                        (0xFFFFU)                                           /*!< PIT0_PCNTR: PC Mask                     */
#define PIT_PCNTR_PC_SHIFT                       (0U)                                                /*!< PIT0_PCNTR: PC Position                 */
#define PIT_PCNTR_PC(x)                          (((uint16_t)(((uint16_t)(x))<<PIT_PCNTR_PC_SHIFT))&PIT_PCNTR_PC_MASK) /*!< PIT0_PCNTR                              */
/**
 * @} */ /* End group PIT_Register_Masks_GROUP 
 */

/* PIT0 - Peripheral instance base addresses */
#define PIT0_BasePtr                   0x40150000UL //!< Peripheral base address
#define PIT0                           ((PIT_Type *) PIT0_BasePtr) //!< Freescale base pointer
#define PIT0_BASE_PTR                  (PIT0) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT1 (derived from PIT0)             ================ */
/* ================================================================================ */

/**
 * @brief Programmable Interrupt Timer
The PIT is a 16-bit timer that provides precise interrupts at regular intervals with minimal processor intervention. 
The timer can count down from the value written in the modulus register or it can be a free-running down-counter
 */

/* PIT1 - Peripheral instance base addresses */
#define PIT1_BasePtr                   0x40160000UL //!< Peripheral base address
#define PIT1                           ((PIT_Type *) PIT1_BasePtr) //!< Freescale base pointer
#define PIT1_BASE_PTR                  (PIT1) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMM_Peripheral_access_layer_GROUP PMM Peripheral Access Layer
* @brief C Struct for PMM
* @{
*/

/* ================================================================================ */
/* ================           PMM (file:MCF522xx_PMM)              ================ */
/* ================================================================================ */

/**
 * @brief Power Management
 */
/**
* @addtogroup PMM_structs_GROUP PMM struct
* @brief Struct for PMM
* @{
*/
typedef struct {                                /*       PMM Structure                                                */
   __IO uint8_t   LPICR;                        /**< 0000: Low-Power Interrupt Control Register                         */
        uint8_t   RESERVED_0[1114100];         
   __IO uint8_t   LPCR;                         /**< 10FFF5: Low-Power Control Register                                   */
} PMM_Type;

/**
 * @} */ /* End group PMM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PMM_Register_Masks_GROUP PMM Register Masks
* @brief Register Masks for PMM
* @{
*/
/* ------- LPICR Bit Fields                         ------ */
#define PMM_LPICR_XLPM_IPL_MASK                  (0x70U)                                             /*!< PMM_LPICR: XLPM_IPL Mask                */
#define PMM_LPICR_XLPM_IPL_SHIFT                 (4U)                                                /*!< PMM_LPICR: XLPM_IPL Position            */
#define PMM_LPICR_XLPM_IPL(x)                    (((uint8_t)(((uint8_t)(x))<<PMM_LPICR_XLPM_IPL_SHIFT))&PMM_LPICR_XLPM_IPL_MASK) /*!< PMM_LPICR                               */
#define PMM_LPICR_ENBSTOP_MASK                   (0x80U)                                             /*!< PMM_LPICR: ENBSTOP Mask                 */
#define PMM_LPICR_ENBSTOP_SHIFT                  (7U)                                                /*!< PMM_LPICR: ENBSTOP Position             */
#define PMM_LPICR_ENBSTOP(x)                     (((uint8_t)(((uint8_t)(x))<<PMM_LPICR_ENBSTOP_SHIFT))&PMM_LPICR_ENBSTOP_MASK) /*!< PMM_LPICR                               */
/* ------- LPCR Bit Fields                          ------ */
#define PMM_LPCR_LVDSE_MASK                      (0x2U)                                              /*!< PMM_LPCR: LVDSE Mask                    */
#define PMM_LPCR_LVDSE_SHIFT                     (1U)                                                /*!< PMM_LPCR: LVDSE Position                */
#define PMM_LPCR_LVDSE(x)                        (((uint8_t)(((uint8_t)(x))<<PMM_LPCR_LVDSE_SHIFT))&PMM_LPCR_LVDSE_MASK) /*!< PMM_LPCR                                */
#define PMM_LPCR_STPMD_MASK                      (0x18U)                                             /*!< PMM_LPCR: STPMD Mask                    */
#define PMM_LPCR_STPMD_SHIFT                     (3U)                                                /*!< PMM_LPCR: STPMD Position                */
#define PMM_LPCR_STPMD(x)                        (((uint8_t)(((uint8_t)(x))<<PMM_LPCR_STPMD_SHIFT))&PMM_LPCR_STPMD_MASK) /*!< PMM_LPCR                                */
#define PMM_LPCR_LPMD_MASK                       (0xC0U)                                             /*!< PMM_LPCR: LPMD Mask                     */
#define PMM_LPCR_LPMD_SHIFT                      (6U)                                                /*!< PMM_LPCR: LPMD Position                 */
#define PMM_LPCR_LPMD(x)                         (((uint8_t)(((uint8_t)(x))<<PMM_LPCR_LPMD_SHIFT))&PMM_LPCR_LPMD_MASK) /*!< PMM_LPCR                                */
/**
 * @} */ /* End group PMM_Register_Masks_GROUP 
 */

/* PMM - Peripheral instance base addresses */
#define PMM_BasePtr                    0x40000012UL //!< Peripheral base address
#define PMM                            ((PMM_Type *) PMM_BasePtr) //!< Freescale base pointer
#define PMM_BASE_PTR                   (PMM) //!< Freescale style base pointer
/**
 * @} */ /* End group PMM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PWM_Peripheral_access_layer_GROUP PWM Peripheral Access Layer
* @brief C Struct for PWM
* @{
*/

/* ================================================================================ */
/* ================           PWM (file:MCF522xx_PWM)              ================ */
/* ================================================================================ */

/**
 * @brief Pulse-Width Modulation Module
 */
/**
* @addtogroup PWM_structs_GROUP PWM struct
* @brief Struct for PWM
* @{
*/
typedef struct {                                /*       PWM Structure                                                */
   __IO uint8_t   PWME;                         /**< 0000: Enable Register                                              */
   __IO uint8_t   PWMPOL;                       /**< 0001: Polarity Register                                            */
   __IO uint8_t   PWMCLK;                       /**< 0002: Clock Select Register                                        */
   __IO uint8_t   PWMPRCLK;                     /**< 0003: Prescale Clock Select Register                               */
   __IO uint8_t   PWMCAE;                       /**< 0004: Centre Align Enable Register                                 */
   __IO uint8_t   PWMCTL;                       /**< 0005: Control Register                                             */
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   PWMSCLA;                      /**< 0008: Scale Register A                                             */
   __IO uint8_t   PWMSCLB;                      /**< 0009: Scale Register B                                             */
        uint8_t   RESERVED_1[2];               
   __IO uint8_t   PWMCNT[8];                    /**< 000C: Channel  Counter Register                                    */
   __IO uint8_t   PWMPER[8];                    /**< 0014: Channel  Period Register                                     */
   __IO uint8_t   PWMDTY[8];                    /**< 001C: Channel  Duty Register                                       */
   __IO uint8_t   PWMSDN;                       /**< 0024: Shutdown Register                                            */
} PWM_Type;

/**
 * @} */ /* End group PWM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PWM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PWM_Register_Masks_GROUP PWM Register Masks
* @brief Register Masks for PWM
* @{
*/
/* ------- PWME Bit Fields                          ------ */
#define PWM_PWME_PWME0_MASK                      (0x1U)                                              /*!< PWM_PWME: PWME0 Mask                    */
#define PWM_PWME_PWME0_SHIFT                     (0U)                                                /*!< PWM_PWME: PWME0 Position                */
#define PWM_PWME_PWME0(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWME_PWME0_SHIFT))&PWM_PWME_PWME0_MASK) /*!< PWM_PWME                                */
#define PWM_PWME_PWME1_MASK                      (0x2U)                                              /*!< PWM_PWME: PWME1 Mask                    */
#define PWM_PWME_PWME1_SHIFT                     (1U)                                                /*!< PWM_PWME: PWME1 Position                */
#define PWM_PWME_PWME1(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWME_PWME1_SHIFT))&PWM_PWME_PWME1_MASK) /*!< PWM_PWME                                */
#define PWM_PWME_PWME2_MASK                      (0x4U)                                              /*!< PWM_PWME: PWME2 Mask                    */
#define PWM_PWME_PWME2_SHIFT                     (2U)                                                /*!< PWM_PWME: PWME2 Position                */
#define PWM_PWME_PWME2(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWME_PWME2_SHIFT))&PWM_PWME_PWME2_MASK) /*!< PWM_PWME                                */
#define PWM_PWME_PWME3_MASK                      (0x8U)                                              /*!< PWM_PWME: PWME3 Mask                    */
#define PWM_PWME_PWME3_SHIFT                     (3U)                                                /*!< PWM_PWME: PWME3 Position                */
#define PWM_PWME_PWME3(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWME_PWME3_SHIFT))&PWM_PWME_PWME3_MASK) /*!< PWM_PWME                                */
#define PWM_PWME_PWME4_MASK                      (0x10U)                                             /*!< PWM_PWME: PWME4 Mask                    */
#define PWM_PWME_PWME4_SHIFT                     (4U)                                                /*!< PWM_PWME: PWME4 Position                */
#define PWM_PWME_PWME4(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWME_PWME4_SHIFT))&PWM_PWME_PWME4_MASK) /*!< PWM_PWME                                */
#define PWM_PWME_PWME5_MASK                      (0x20U)                                             /*!< PWM_PWME: PWME5 Mask                    */
#define PWM_PWME_PWME5_SHIFT                     (5U)                                                /*!< PWM_PWME: PWME5 Position                */
#define PWM_PWME_PWME5(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWME_PWME5_SHIFT))&PWM_PWME_PWME5_MASK) /*!< PWM_PWME                                */
#define PWM_PWME_PWME6_MASK                      (0x40U)                                             /*!< PWM_PWME: PWME6 Mask                    */
#define PWM_PWME_PWME6_SHIFT                     (6U)                                                /*!< PWM_PWME: PWME6 Position                */
#define PWM_PWME_PWME6(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWME_PWME6_SHIFT))&PWM_PWME_PWME6_MASK) /*!< PWM_PWME                                */
#define PWM_PWME_PWME7_MASK                      (0x80U)                                             /*!< PWM_PWME: PWME7 Mask                    */
#define PWM_PWME_PWME7_SHIFT                     (7U)                                                /*!< PWM_PWME: PWME7 Position                */
#define PWM_PWME_PWME7(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWME_PWME7_SHIFT))&PWM_PWME_PWME7_MASK) /*!< PWM_PWME                                */
/* ------- PWMPOL Bit Fields                        ------ */
#define PWM_PWMPOL_PPOL0_MASK                    (0x1U)                                              /*!< PWM_PWMPOL: PPOL0 Mask                  */
#define PWM_PWMPOL_PPOL0_SHIFT                   (0U)                                                /*!< PWM_PWMPOL: PPOL0 Position              */
#define PWM_PWMPOL_PPOL0(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMPOL_PPOL0_SHIFT))&PWM_PWMPOL_PPOL0_MASK) /*!< PWM_PWMPOL                              */
#define PWM_PWMPOL_PPOL1_MASK                    (0x2U)                                              /*!< PWM_PWMPOL: PPOL1 Mask                  */
#define PWM_PWMPOL_PPOL1_SHIFT                   (1U)                                                /*!< PWM_PWMPOL: PPOL1 Position              */
#define PWM_PWMPOL_PPOL1(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMPOL_PPOL1_SHIFT))&PWM_PWMPOL_PPOL1_MASK) /*!< PWM_PWMPOL                              */
#define PWM_PWMPOL_PPOL2_MASK                    (0x4U)                                              /*!< PWM_PWMPOL: PPOL2 Mask                  */
#define PWM_PWMPOL_PPOL2_SHIFT                   (2U)                                                /*!< PWM_PWMPOL: PPOL2 Position              */
#define PWM_PWMPOL_PPOL2(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMPOL_PPOL2_SHIFT))&PWM_PWMPOL_PPOL2_MASK) /*!< PWM_PWMPOL                              */
#define PWM_PWMPOL_PPOL3_MASK                    (0x8U)                                              /*!< PWM_PWMPOL: PPOL3 Mask                  */
#define PWM_PWMPOL_PPOL3_SHIFT                   (3U)                                                /*!< PWM_PWMPOL: PPOL3 Position              */
#define PWM_PWMPOL_PPOL3(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMPOL_PPOL3_SHIFT))&PWM_PWMPOL_PPOL3_MASK) /*!< PWM_PWMPOL                              */
#define PWM_PWMPOL_PPOL4_MASK                    (0x10U)                                             /*!< PWM_PWMPOL: PPOL4 Mask                  */
#define PWM_PWMPOL_PPOL4_SHIFT                   (4U)                                                /*!< PWM_PWMPOL: PPOL4 Position              */
#define PWM_PWMPOL_PPOL4(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMPOL_PPOL4_SHIFT))&PWM_PWMPOL_PPOL4_MASK) /*!< PWM_PWMPOL                              */
#define PWM_PWMPOL_PPOL5_MASK                    (0x20U)                                             /*!< PWM_PWMPOL: PPOL5 Mask                  */
#define PWM_PWMPOL_PPOL5_SHIFT                   (5U)                                                /*!< PWM_PWMPOL: PPOL5 Position              */
#define PWM_PWMPOL_PPOL5(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMPOL_PPOL5_SHIFT))&PWM_PWMPOL_PPOL5_MASK) /*!< PWM_PWMPOL                              */
#define PWM_PWMPOL_PPOL6_MASK                    (0x40U)                                             /*!< PWM_PWMPOL: PPOL6 Mask                  */
#define PWM_PWMPOL_PPOL6_SHIFT                   (6U)                                                /*!< PWM_PWMPOL: PPOL6 Position              */
#define PWM_PWMPOL_PPOL6(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMPOL_PPOL6_SHIFT))&PWM_PWMPOL_PPOL6_MASK) /*!< PWM_PWMPOL                              */
#define PWM_PWMPOL_PPOL7_MASK                    (0x80U)                                             /*!< PWM_PWMPOL: PPOL7 Mask                  */
#define PWM_PWMPOL_PPOL7_SHIFT                   (7U)                                                /*!< PWM_PWMPOL: PPOL7 Position              */
#define PWM_PWMPOL_PPOL7(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMPOL_PPOL7_SHIFT))&PWM_PWMPOL_PPOL7_MASK) /*!< PWM_PWMPOL                              */
/* ------- PWMCLK Bit Fields                        ------ */
#define PWM_PWMCLK_PCLK0_MASK                    (0x1U)                                              /*!< PWM_PWMCLK: PCLK0 Mask                  */
#define PWM_PWMCLK_PCLK0_SHIFT                   (0U)                                                /*!< PWM_PWMCLK: PCLK0 Position              */
#define PWM_PWMCLK_PCLK0(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCLK_PCLK0_SHIFT))&PWM_PWMCLK_PCLK0_MASK) /*!< PWM_PWMCLK                              */
#define PWM_PWMCLK_PCLK1_MASK                    (0x2U)                                              /*!< PWM_PWMCLK: PCLK1 Mask                  */
#define PWM_PWMCLK_PCLK1_SHIFT                   (1U)                                                /*!< PWM_PWMCLK: PCLK1 Position              */
#define PWM_PWMCLK_PCLK1(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCLK_PCLK1_SHIFT))&PWM_PWMCLK_PCLK1_MASK) /*!< PWM_PWMCLK                              */
#define PWM_PWMCLK_PCLK2_MASK                    (0x4U)                                              /*!< PWM_PWMCLK: PCLK2 Mask                  */
#define PWM_PWMCLK_PCLK2_SHIFT                   (2U)                                                /*!< PWM_PWMCLK: PCLK2 Position              */
#define PWM_PWMCLK_PCLK2(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCLK_PCLK2_SHIFT))&PWM_PWMCLK_PCLK2_MASK) /*!< PWM_PWMCLK                              */
#define PWM_PWMCLK_PCLK3_MASK                    (0x8U)                                              /*!< PWM_PWMCLK: PCLK3 Mask                  */
#define PWM_PWMCLK_PCLK3_SHIFT                   (3U)                                                /*!< PWM_PWMCLK: PCLK3 Position              */
#define PWM_PWMCLK_PCLK3(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCLK_PCLK3_SHIFT))&PWM_PWMCLK_PCLK3_MASK) /*!< PWM_PWMCLK                              */
#define PWM_PWMCLK_PCLK4_MASK                    (0x10U)                                             /*!< PWM_PWMCLK: PCLK4 Mask                  */
#define PWM_PWMCLK_PCLK4_SHIFT                   (4U)                                                /*!< PWM_PWMCLK: PCLK4 Position              */
#define PWM_PWMCLK_PCLK4(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCLK_PCLK4_SHIFT))&PWM_PWMCLK_PCLK4_MASK) /*!< PWM_PWMCLK                              */
#define PWM_PWMCLK_PCLK5_MASK                    (0x20U)                                             /*!< PWM_PWMCLK: PCLK5 Mask                  */
#define PWM_PWMCLK_PCLK5_SHIFT                   (5U)                                                /*!< PWM_PWMCLK: PCLK5 Position              */
#define PWM_PWMCLK_PCLK5(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCLK_PCLK5_SHIFT))&PWM_PWMCLK_PCLK5_MASK) /*!< PWM_PWMCLK                              */
#define PWM_PWMCLK_PCLK6_MASK                    (0x40U)                                             /*!< PWM_PWMCLK: PCLK6 Mask                  */
#define PWM_PWMCLK_PCLK6_SHIFT                   (6U)                                                /*!< PWM_PWMCLK: PCLK6 Position              */
#define PWM_PWMCLK_PCLK6(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCLK_PCLK6_SHIFT))&PWM_PWMCLK_PCLK6_MASK) /*!< PWM_PWMCLK                              */
#define PWM_PWMCLK_PCLK7_MASK                    (0x80U)                                             /*!< PWM_PWMCLK: PCLK7 Mask                  */
#define PWM_PWMCLK_PCLK7_SHIFT                   (7U)                                                /*!< PWM_PWMCLK: PCLK7 Position              */
#define PWM_PWMCLK_PCLK7(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCLK_PCLK7_SHIFT))&PWM_PWMCLK_PCLK7_MASK) /*!< PWM_PWMCLK                              */
/* ------- PWMPRCLK Bit Fields                      ------ */
#define PWM_PWMPRCLK_PCKA_MASK                   (0x7U)                                              /*!< PWM_PWMPRCLK: PCKA Mask                 */
#define PWM_PWMPRCLK_PCKA_SHIFT                  (0U)                                                /*!< PWM_PWMPRCLK: PCKA Position             */
#define PWM_PWMPRCLK_PCKA(x)                     (((uint8_t)(((uint8_t)(x))<<PWM_PWMPRCLK_PCKA_SHIFT))&PWM_PWMPRCLK_PCKA_MASK) /*!< PWM_PWMPRCLK                            */
#define PWM_PWMPRCLK_PCKB_MASK                   (0x70U)                                             /*!< PWM_PWMPRCLK: PCKB Mask                 */
#define PWM_PWMPRCLK_PCKB_SHIFT                  (4U)                                                /*!< PWM_PWMPRCLK: PCKB Position             */
#define PWM_PWMPRCLK_PCKB(x)                     (((uint8_t)(((uint8_t)(x))<<PWM_PWMPRCLK_PCKB_SHIFT))&PWM_PWMPRCLK_PCKB_MASK) /*!< PWM_PWMPRCLK                            */
/* ------- PWMCAE Bit Fields                        ------ */
#define PWM_PWMCAE_CAE0_MASK                     (0x1U)                                              /*!< PWM_PWMCAE: CAE0 Mask                   */
#define PWM_PWMCAE_CAE0_SHIFT                    (0U)                                                /*!< PWM_PWMCAE: CAE0 Position               */
#define PWM_PWMCAE_CAE0(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCAE_CAE0_SHIFT))&PWM_PWMCAE_CAE0_MASK) /*!< PWM_PWMCAE                              */
#define PWM_PWMCAE_CAE1_MASK                     (0x2U)                                              /*!< PWM_PWMCAE: CAE1 Mask                   */
#define PWM_PWMCAE_CAE1_SHIFT                    (1U)                                                /*!< PWM_PWMCAE: CAE1 Position               */
#define PWM_PWMCAE_CAE1(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCAE_CAE1_SHIFT))&PWM_PWMCAE_CAE1_MASK) /*!< PWM_PWMCAE                              */
#define PWM_PWMCAE_CAE2_MASK                     (0x4U)                                              /*!< PWM_PWMCAE: CAE2 Mask                   */
#define PWM_PWMCAE_CAE2_SHIFT                    (2U)                                                /*!< PWM_PWMCAE: CAE2 Position               */
#define PWM_PWMCAE_CAE2(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCAE_CAE2_SHIFT))&PWM_PWMCAE_CAE2_MASK) /*!< PWM_PWMCAE                              */
#define PWM_PWMCAE_CAE3_MASK                     (0x8U)                                              /*!< PWM_PWMCAE: CAE3 Mask                   */
#define PWM_PWMCAE_CAE3_SHIFT                    (3U)                                                /*!< PWM_PWMCAE: CAE3 Position               */
#define PWM_PWMCAE_CAE3(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCAE_CAE3_SHIFT))&PWM_PWMCAE_CAE3_MASK) /*!< PWM_PWMCAE                              */
#define PWM_PWMCAE_CAE4_MASK                     (0x10U)                                             /*!< PWM_PWMCAE: CAE4 Mask                   */
#define PWM_PWMCAE_CAE4_SHIFT                    (4U)                                                /*!< PWM_PWMCAE: CAE4 Position               */
#define PWM_PWMCAE_CAE4(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCAE_CAE4_SHIFT))&PWM_PWMCAE_CAE4_MASK) /*!< PWM_PWMCAE                              */
#define PWM_PWMCAE_CAE5_MASK                     (0x20U)                                             /*!< PWM_PWMCAE: CAE5 Mask                   */
#define PWM_PWMCAE_CAE5_SHIFT                    (5U)                                                /*!< PWM_PWMCAE: CAE5 Position               */
#define PWM_PWMCAE_CAE5(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCAE_CAE5_SHIFT))&PWM_PWMCAE_CAE5_MASK) /*!< PWM_PWMCAE                              */
#define PWM_PWMCAE_CAE6_MASK                     (0x40U)                                             /*!< PWM_PWMCAE: CAE6 Mask                   */
#define PWM_PWMCAE_CAE6_SHIFT                    (6U)                                                /*!< PWM_PWMCAE: CAE6 Position               */
#define PWM_PWMCAE_CAE6(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCAE_CAE6_SHIFT))&PWM_PWMCAE_CAE6_MASK) /*!< PWM_PWMCAE                              */
#define PWM_PWMCAE_CAE7_MASK                     (0x80U)                                             /*!< PWM_PWMCAE: CAE7 Mask                   */
#define PWM_PWMCAE_CAE7_SHIFT                    (7U)                                                /*!< PWM_PWMCAE: CAE7 Position               */
#define PWM_PWMCAE_CAE7(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCAE_CAE7_SHIFT))&PWM_PWMCAE_CAE7_MASK) /*!< PWM_PWMCAE                              */
/* ------- PWMCTL Bit Fields                        ------ */
#define PWM_PWMCTL_PFRZ_MASK                     (0x4U)                                              /*!< PWM_PWMCTL: PFRZ Mask                   */
#define PWM_PWMCTL_PFRZ_SHIFT                    (2U)                                                /*!< PWM_PWMCTL: PFRZ Position               */
#define PWM_PWMCTL_PFRZ(x)                       (((uint8_t)(((uint8_t)(x))<<PWM_PWMCTL_PFRZ_SHIFT))&PWM_PWMCTL_PFRZ_MASK) /*!< PWM_PWMCTL                              */
#define PWM_PWMCTL_PSWAI_MASK                    (0x8U)                                              /*!< PWM_PWMCTL: PSWAI Mask                  */
#define PWM_PWMCTL_PSWAI_SHIFT                   (3U)                                                /*!< PWM_PWMCTL: PSWAI Position              */
#define PWM_PWMCTL_PSWAI(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCTL_PSWAI_SHIFT))&PWM_PWMCTL_PSWAI_MASK) /*!< PWM_PWMCTL                              */
#define PWM_PWMCTL_CON01_MASK                    (0x10U)                                             /*!< PWM_PWMCTL: CON01 Mask                  */
#define PWM_PWMCTL_CON01_SHIFT                   (4U)                                                /*!< PWM_PWMCTL: CON01 Position              */
#define PWM_PWMCTL_CON01(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCTL_CON01_SHIFT))&PWM_PWMCTL_CON01_MASK) /*!< PWM_PWMCTL                              */
#define PWM_PWMCTL_CON23_MASK                    (0x20U)                                             /*!< PWM_PWMCTL: CON23 Mask                  */
#define PWM_PWMCTL_CON23_SHIFT                   (5U)                                                /*!< PWM_PWMCTL: CON23 Position              */
#define PWM_PWMCTL_CON23(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCTL_CON23_SHIFT))&PWM_PWMCTL_CON23_MASK) /*!< PWM_PWMCTL                              */
#define PWM_PWMCTL_CON45_MASK                    (0x40U)                                             /*!< PWM_PWMCTL: CON45 Mask                  */
#define PWM_PWMCTL_CON45_SHIFT                   (6U)                                                /*!< PWM_PWMCTL: CON45 Position              */
#define PWM_PWMCTL_CON45(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCTL_CON45_SHIFT))&PWM_PWMCTL_CON45_MASK) /*!< PWM_PWMCTL                              */
#define PWM_PWMCTL_CON67_MASK                    (0x80U)                                             /*!< PWM_PWMCTL: CON67 Mask                  */
#define PWM_PWMCTL_CON67_SHIFT                   (7U)                                                /*!< PWM_PWMCTL: CON67 Position              */
#define PWM_PWMCTL_CON67(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMCTL_CON67_SHIFT))&PWM_PWMCTL_CON67_MASK) /*!< PWM_PWMCTL                              */
/* ------- PWMSCLA Bit Fields                       ------ */
/* ------- PWMSCLB Bit Fields                       ------ */
/* ------- PWMCNT Bit Fields                        ------ */
/* ------- PWMPER Bit Fields                        ------ */
/* ------- PWMDTY Bit Fields                        ------ */
/* ------- PWMSDN Bit Fields                        ------ */
#define PWM_PWMSDN_SDNEN_MASK                    (0x1U)                                              /*!< PWM_PWMSDN: SDNEN Mask                  */
#define PWM_PWMSDN_SDNEN_SHIFT                   (0U)                                                /*!< PWM_PWMSDN: SDNEN Position              */
#define PWM_PWMSDN_SDNEN(x)                      (((uint8_t)(((uint8_t)(x))<<PWM_PWMSDN_SDNEN_SHIFT))&PWM_PWMSDN_SDNEN_MASK) /*!< PWM_PWMSDN                              */
#define PWM_PWMSDN_PWM7IL_MASK                   (0x2U)                                              /*!< PWM_PWMSDN: PWM7IL Mask                 */
#define PWM_PWMSDN_PWM7IL_SHIFT                  (1U)                                                /*!< PWM_PWMSDN: PWM7IL Position             */
#define PWM_PWMSDN_PWM7IL(x)                     (((uint8_t)(((uint8_t)(x))<<PWM_PWMSDN_PWM7IL_SHIFT))&PWM_PWMSDN_PWM7IL_MASK) /*!< PWM_PWMSDN                              */
#define PWM_PWMSDN_PWM7IN_MASK                   (0x4U)                                              /*!< PWM_PWMSDN: PWM7IN Mask                 */
#define PWM_PWMSDN_PWM7IN_SHIFT                  (2U)                                                /*!< PWM_PWMSDN: PWM7IN Position             */
#define PWM_PWMSDN_PWM7IN(x)                     (((uint8_t)(((uint8_t)(x))<<PWM_PWMSDN_PWM7IN_SHIFT))&PWM_PWMSDN_PWM7IN_MASK) /*!< PWM_PWMSDN                              */
#define PWM_PWMSDN_LVL_MASK                      (0x10U)                                             /*!< PWM_PWMSDN: LVL Mask                    */
#define PWM_PWMSDN_LVL_SHIFT                     (4U)                                                /*!< PWM_PWMSDN: LVL Position                */
#define PWM_PWMSDN_LVL(x)                        (((uint8_t)(((uint8_t)(x))<<PWM_PWMSDN_LVL_SHIFT))&PWM_PWMSDN_LVL_MASK) /*!< PWM_PWMSDN                              */
#define PWM_PWMSDN_RESTART_MASK                  (0x20U)                                             /*!< PWM_PWMSDN: RESTART Mask                */
#define PWM_PWMSDN_RESTART_SHIFT                 (5U)                                                /*!< PWM_PWMSDN: RESTART Position            */
#define PWM_PWMSDN_RESTART(x)                    (((uint8_t)(((uint8_t)(x))<<PWM_PWMSDN_RESTART_SHIFT))&PWM_PWMSDN_RESTART_MASK) /*!< PWM_PWMSDN                              */
#define PWM_PWMSDN_IE_MASK                       (0x40U)                                             /*!< PWM_PWMSDN: IE Mask                     */
#define PWM_PWMSDN_IE_SHIFT                      (6U)                                                /*!< PWM_PWMSDN: IE Position                 */
#define PWM_PWMSDN_IE(x)                         (((uint8_t)(((uint8_t)(x))<<PWM_PWMSDN_IE_SHIFT))&PWM_PWMSDN_IE_MASK) /*!< PWM_PWMSDN                              */
#define PWM_PWMSDN_IF_MASK                       (0x80U)                                             /*!< PWM_PWMSDN: IF Mask                     */
#define PWM_PWMSDN_IF_SHIFT                      (7U)                                                /*!< PWM_PWMSDN: IF Position                 */
#define PWM_PWMSDN_IF(x)                         (((uint8_t)(((uint8_t)(x))<<PWM_PWMSDN_IF_SHIFT))&PWM_PWMSDN_IF_MASK) /*!< PWM_PWMSDN                              */
/**
 * @} */ /* End group PWM_Register_Masks_GROUP 
 */

/* PWM - Peripheral instance base addresses */
#define PWM_BasePtr                    0x401B0000UL //!< Peripheral base address
#define PWM                            ((PWM_Type *) PWM_BasePtr) //!< Freescale base pointer
#define PWM_BASE_PTR                   (PWM) //!< Freescale style base pointer
/**
 * @} */ /* End group PWM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup QSPI_Peripheral_access_layer_GROUP QSPI Peripheral Access Layer
* @brief C Struct for QSPI
* @{
*/

/* ================================================================================ */
/* ================           QSPI (file:MCF522xx_QSPI)            ================ */
/* ================================================================================ */

/**
 * @brief Queued Serial Peripheral Interface
 */
/**
* @addtogroup QSPI_structs_GROUP QSPI struct
* @brief Struct for QSPI
* @{
*/
typedef struct {                                /*       QSPI Structure                                               */
   __IO uint16_t  QMR;                          /**< 0000: Mode Register                                                */
        uint8_t   RESERVED_0[2];               
   __IO uint16_t  QDLYR;                        /**< 0004: Delay Register                                               */
        uint8_t   RESERVED_1[2];               
   __IO uint16_t  QWR;                          /**< 0008: Wrap Register                                                */
        uint8_t   RESERVED_2[2];               
   __IO uint16_t  QIR;                          /**< 000C: Interrupt Register                                           */
        uint8_t   RESERVED_3[2];               
   __IO uint16_t  QAR;                          /**< 0010: Address Register                                             */
        uint8_t   RESERVED_4[2];               
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  QDR;                       /**< 0014: Data Register                                                */
      __O  uint8_t   QDR_COMMAND;               /**< 0014: Command Register                                             */
   };
} QSPI_Type;

/**
 * @} */ /* End group QSPI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'QSPI' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup QSPI_Register_Masks_GROUP QSPI Register Masks
* @brief Register Masks for QSPI
* @{
*/
/* ------- QMR Bit Fields                           ------ */
#define QSPI_QMR_BAUD_MASK                       (0xFFU)                                             /*!< QSPI_QMR: BAUD Mask                     */
#define QSPI_QMR_BAUD_SHIFT                      (0U)                                                /*!< QSPI_QMR: BAUD Position                 */
#define QSPI_QMR_BAUD(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QMR_BAUD_SHIFT))&QSPI_QMR_BAUD_MASK) /*!< QSPI_QMR                                */
#define QSPI_QMR_CPHA_MASK                       (0x100U)                                            /*!< QSPI_QMR: CPHA Mask                     */
#define QSPI_QMR_CPHA_SHIFT                      (8U)                                                /*!< QSPI_QMR: CPHA Position                 */
#define QSPI_QMR_CPHA(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QMR_CPHA_SHIFT))&QSPI_QMR_CPHA_MASK) /*!< QSPI_QMR                                */
#define QSPI_QMR_CPOL_MASK                       (0x200U)                                            /*!< QSPI_QMR: CPOL Mask                     */
#define QSPI_QMR_CPOL_SHIFT                      (9U)                                                /*!< QSPI_QMR: CPOL Position                 */
#define QSPI_QMR_CPOL(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QMR_CPOL_SHIFT))&QSPI_QMR_CPOL_MASK) /*!< QSPI_QMR                                */
#define QSPI_QMR_BITS_MASK                       (0x3C00U)                                           /*!< QSPI_QMR: BITS Mask                     */
#define QSPI_QMR_BITS_SHIFT                      (10U)                                               /*!< QSPI_QMR: BITS Position                 */
#define QSPI_QMR_BITS(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QMR_BITS_SHIFT))&QSPI_QMR_BITS_MASK) /*!< QSPI_QMR                                */
#define QSPI_QMR_DOHIE_MASK                      (0x4000U)                                           /*!< QSPI_QMR: DOHIE Mask                    */
#define QSPI_QMR_DOHIE_SHIFT                     (14U)                                               /*!< QSPI_QMR: DOHIE Position                */
#define QSPI_QMR_DOHIE(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QMR_DOHIE_SHIFT))&QSPI_QMR_DOHIE_MASK) /*!< QSPI_QMR                                */
#define QSPI_QMR_MSTR_MASK                       (0x8000U)                                           /*!< QSPI_QMR: MSTR Mask                     */
#define QSPI_QMR_MSTR_SHIFT                      (15U)                                               /*!< QSPI_QMR: MSTR Position                 */
#define QSPI_QMR_MSTR(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QMR_MSTR_SHIFT))&QSPI_QMR_MSTR_MASK) /*!< QSPI_QMR                                */
/* ------- QDLYR Bit Fields                         ------ */
#define QSPI_QDLYR_DTL_MASK                      (0xFFU)                                             /*!< QSPI_QDLYR: DTL Mask                    */
#define QSPI_QDLYR_DTL_SHIFT                     (0U)                                                /*!< QSPI_QDLYR: DTL Position                */
#define QSPI_QDLYR_DTL(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QDLYR_DTL_SHIFT))&QSPI_QDLYR_DTL_MASK) /*!< QSPI_QDLYR                              */
#define QSPI_QDLYR_QCD_MASK                      (0x7F00U)                                           /*!< QSPI_QDLYR: QCD Mask                    */
#define QSPI_QDLYR_QCD_SHIFT                     (8U)                                                /*!< QSPI_QDLYR: QCD Position                */
#define QSPI_QDLYR_QCD(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QDLYR_QCD_SHIFT))&QSPI_QDLYR_QCD_MASK) /*!< QSPI_QDLYR                              */
#define QSPI_QDLYR_SPE_MASK                      (0x8000U)                                           /*!< QSPI_QDLYR: SPE Mask                    */
#define QSPI_QDLYR_SPE_SHIFT                     (15U)                                               /*!< QSPI_QDLYR: SPE Position                */
#define QSPI_QDLYR_SPE(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QDLYR_SPE_SHIFT))&QSPI_QDLYR_SPE_MASK) /*!< QSPI_QDLYR                              */
/* ------- QWR Bit Fields                           ------ */
#define QSPI_QWR_NEWQP_MASK                      (0xFU)                                              /*!< QSPI_QWR: NEWQP Mask                    */
#define QSPI_QWR_NEWQP_SHIFT                     (0U)                                                /*!< QSPI_QWR: NEWQP Position                */
#define QSPI_QWR_NEWQP(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_NEWQP_SHIFT))&QSPI_QWR_NEWQP_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_CPTQP_MASK                      (0xF0U)                                             /*!< QSPI_QWR: CPTQP Mask                    */
#define QSPI_QWR_CPTQP_SHIFT                     (4U)                                                /*!< QSPI_QWR: CPTQP Position                */
#define QSPI_QWR_CPTQP(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_CPTQP_SHIFT))&QSPI_QWR_CPTQP_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_ENDQP_MASK                      (0xF00U)                                            /*!< QSPI_QWR: ENDQP Mask                    */
#define QSPI_QWR_ENDQP_SHIFT                     (8U)                                                /*!< QSPI_QWR: ENDQP Position                */
#define QSPI_QWR_ENDQP(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_ENDQP_SHIFT))&QSPI_QWR_ENDQP_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_CSIV_MASK                       (0x1000U)                                           /*!< QSPI_QWR: CSIV Mask                     */
#define QSPI_QWR_CSIV_SHIFT                      (12U)                                               /*!< QSPI_QWR: CSIV Position                 */
#define QSPI_QWR_CSIV(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_CSIV_SHIFT))&QSPI_QWR_CSIV_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_WRTO_MASK                       (0x2000U)                                           /*!< QSPI_QWR: WRTO Mask                     */
#define QSPI_QWR_WRTO_SHIFT                      (13U)                                               /*!< QSPI_QWR: WRTO Position                 */
#define QSPI_QWR_WRTO(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_WRTO_SHIFT))&QSPI_QWR_WRTO_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_WREN_MASK                       (0x4000U)                                           /*!< QSPI_QWR: WREN Mask                     */
#define QSPI_QWR_WREN_SHIFT                      (14U)                                               /*!< QSPI_QWR: WREN Position                 */
#define QSPI_QWR_WREN(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_WREN_SHIFT))&QSPI_QWR_WREN_MASK) /*!< QSPI_QWR                                */
#define QSPI_QWR_HALT_MASK                       (0x8000U)                                           /*!< QSPI_QWR: HALT Mask                     */
#define QSPI_QWR_HALT_SHIFT                      (15U)                                               /*!< QSPI_QWR: HALT Position                 */
#define QSPI_QWR_HALT(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QWR_HALT_SHIFT))&QSPI_QWR_HALT_MASK) /*!< QSPI_QWR                                */
/* ------- QIR Bit Fields                           ------ */
#define QSPI_QIR_SPIF_MASK                       (0x1U)                                              /*!< QSPI_QIR: SPIF Mask                     */
#define QSPI_QIR_SPIF_SHIFT                      (0U)                                                /*!< QSPI_QIR: SPIF Position                 */
#define QSPI_QIR_SPIF(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_SPIF_SHIFT))&QSPI_QIR_SPIF_MASK) /*!< QSPI_QIR                                */
#define QSPI_QIR_ABRT_MASK                       (0x4U)                                              /*!< QSPI_QIR: ABRT Mask                     */
#define QSPI_QIR_ABRT_SHIFT                      (2U)                                                /*!< QSPI_QIR: ABRT Position                 */
#define QSPI_QIR_ABRT(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_ABRT_SHIFT))&QSPI_QIR_ABRT_MASK) /*!< QSPI_QIR                                */
#define QSPI_QIR_WCEF_MASK                       (0x8U)                                              /*!< QSPI_QIR: WCEF Mask                     */
#define QSPI_QIR_WCEF_SHIFT                      (3U)                                                /*!< QSPI_QIR: WCEF Position                 */
#define QSPI_QIR_WCEF(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_WCEF_SHIFT))&QSPI_QIR_WCEF_MASK) /*!< QSPI_QIR                                */
#define QSPI_QIR_SPIFE_MASK                      (0x100U)                                            /*!< QSPI_QIR: SPIFE Mask                    */
#define QSPI_QIR_SPIFE_SHIFT                     (8U)                                                /*!< QSPI_QIR: SPIFE Position                */
#define QSPI_QIR_SPIFE(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_SPIFE_SHIFT))&QSPI_QIR_SPIFE_MASK) /*!< QSPI_QIR                                */
#define QSPI_QIR_ABRTE_MASK                      (0x400U)                                            /*!< QSPI_QIR: ABRTE Mask                    */
#define QSPI_QIR_ABRTE_SHIFT                     (10U)                                               /*!< QSPI_QIR: ABRTE Position                */
#define QSPI_QIR_ABRTE(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_ABRTE_SHIFT))&QSPI_QIR_ABRTE_MASK) /*!< QSPI_QIR                                */
#define QSPI_QIR_WCEFE_MASK                      (0x800U)                                            /*!< QSPI_QIR: WCEFE Mask                    */
#define QSPI_QIR_WCEFE_SHIFT                     (11U)                                               /*!< QSPI_QIR: WCEFE Position                */
#define QSPI_QIR_WCEFE(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_WCEFE_SHIFT))&QSPI_QIR_WCEFE_MASK) /*!< QSPI_QIR                                */
#define QSPI_QIR_ABRTL_MASK                      (0x1000U)                                           /*!< QSPI_QIR: ABRTL Mask                    */
#define QSPI_QIR_ABRTL_SHIFT                     (12U)                                               /*!< QSPI_QIR: ABRTL Position                */
#define QSPI_QIR_ABRTL(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_ABRTL_SHIFT))&QSPI_QIR_ABRTL_MASK) /*!< QSPI_QIR                                */
#define QSPI_QIR_ABRTB_MASK                      (0x4000U)                                           /*!< QSPI_QIR: ABRTB Mask                    */
#define QSPI_QIR_ABRTB_SHIFT                     (14U)                                               /*!< QSPI_QIR: ABRTB Position                */
#define QSPI_QIR_ABRTB(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_ABRTB_SHIFT))&QSPI_QIR_ABRTB_MASK) /*!< QSPI_QIR                                */
#define QSPI_QIR_WCEFB_MASK                      (0x8000U)                                           /*!< QSPI_QIR: WCEFB Mask                    */
#define QSPI_QIR_WCEFB_SHIFT                     (15U)                                               /*!< QSPI_QIR: WCEFB Position                */
#define QSPI_QIR_WCEFB(x)                        (((uint16_t)(((uint16_t)(x))<<QSPI_QIR_WCEFB_SHIFT))&QSPI_QIR_WCEFB_MASK) /*!< QSPI_QIR                                */
/* ------- QAR Bit Fields                           ------ */
#define QSPI_QAR_ADDR_MASK                       (0x3FU)                                             /*!< QSPI_QAR: ADDR Mask                     */
#define QSPI_QAR_ADDR_SHIFT                      (0U)                                                /*!< QSPI_QAR: ADDR Position                 */
#define QSPI_QAR_ADDR(x)                         (((uint16_t)(((uint16_t)(x))<<QSPI_QAR_ADDR_SHIFT))&QSPI_QAR_ADDR_MASK) /*!< QSPI_QAR                                */
/* ------- QDR Bit Fields                           ------ */
/* ------- QDR_COMMAND Bit Fields                   ------ */
#define QSPI_QDR_COMMAND_QSPI_CS0_MASK           (0x1U)                                              /*!< QSPI_QDR_COMMAND: QSPI_CS0 Mask         */
#define QSPI_QDR_COMMAND_QSPI_CS0_SHIFT          (0U)                                                /*!< QSPI_QDR_COMMAND: QSPI_CS0 Position     */
#define QSPI_QDR_COMMAND_QSPI_CS0(x)             (((uint8_t)(((uint8_t)(x))<<QSPI_QDR_COMMAND_QSPI_CS0_SHIFT))&QSPI_QDR_COMMAND_QSPI_CS0_MASK) /*!< QSPI_QDR_COMMAND                        */
#define QSPI_QDR_COMMAND_QSPI_CS1_MASK           (0x2U)                                              /*!< QSPI_QDR_COMMAND: QSPI_CS1 Mask         */
#define QSPI_QDR_COMMAND_QSPI_CS1_SHIFT          (1U)                                                /*!< QSPI_QDR_COMMAND: QSPI_CS1 Position     */
#define QSPI_QDR_COMMAND_QSPI_CS1(x)             (((uint8_t)(((uint8_t)(x))<<QSPI_QDR_COMMAND_QSPI_CS1_SHIFT))&QSPI_QDR_COMMAND_QSPI_CS1_MASK) /*!< QSPI_QDR_COMMAND                        */
#define QSPI_QDR_COMMAND_QSPI_CS2_MASK           (0x4U)                                              /*!< QSPI_QDR_COMMAND: QSPI_CS2 Mask         */
#define QSPI_QDR_COMMAND_QSPI_CS2_SHIFT          (2U)                                                /*!< QSPI_QDR_COMMAND: QSPI_CS2 Position     */
#define QSPI_QDR_COMMAND_QSPI_CS2(x)             (((uint8_t)(((uint8_t)(x))<<QSPI_QDR_COMMAND_QSPI_CS2_SHIFT))&QSPI_QDR_COMMAND_QSPI_CS2_MASK) /*!< QSPI_QDR_COMMAND                        */
#define QSPI_QDR_COMMAND_QSPI_CS3_MASK           (0x8U)                                              /*!< QSPI_QDR_COMMAND: QSPI_CS3 Mask         */
#define QSPI_QDR_COMMAND_QSPI_CS3_SHIFT          (3U)                                                /*!< QSPI_QDR_COMMAND: QSPI_CS3 Position     */
#define QSPI_QDR_COMMAND_QSPI_CS3(x)             (((uint8_t)(((uint8_t)(x))<<QSPI_QDR_COMMAND_QSPI_CS3_SHIFT))&QSPI_QDR_COMMAND_QSPI_CS3_MASK) /*!< QSPI_QDR_COMMAND                        */
#define QSPI_QDR_COMMAND_DSCK_MASK               (0x10U)                                             /*!< QSPI_QDR_COMMAND: DSCK Mask             */
#define QSPI_QDR_COMMAND_DSCK_SHIFT              (4U)                                                /*!< QSPI_QDR_COMMAND: DSCK Position         */
#define QSPI_QDR_COMMAND_DSCK(x)                 (((uint8_t)(((uint8_t)(x))<<QSPI_QDR_COMMAND_DSCK_SHIFT))&QSPI_QDR_COMMAND_DSCK_MASK) /*!< QSPI_QDR_COMMAND                        */
#define QSPI_QDR_COMMAND_DT_MASK                 (0x20U)                                             /*!< QSPI_QDR_COMMAND: DT Mask               */
#define QSPI_QDR_COMMAND_DT_SHIFT                (5U)                                                /*!< QSPI_QDR_COMMAND: DT Position           */
#define QSPI_QDR_COMMAND_DT(x)                   (((uint8_t)(((uint8_t)(x))<<QSPI_QDR_COMMAND_DT_SHIFT))&QSPI_QDR_COMMAND_DT_MASK) /*!< QSPI_QDR_COMMAND                        */
#define QSPI_QDR_COMMAND_BITSE_MASK              (0x40U)                                             /*!< QSPI_QDR_COMMAND: BITSE Mask            */
#define QSPI_QDR_COMMAND_BITSE_SHIFT             (6U)                                                /*!< QSPI_QDR_COMMAND: BITSE Position        */
#define QSPI_QDR_COMMAND_BITSE(x)                (((uint8_t)(((uint8_t)(x))<<QSPI_QDR_COMMAND_BITSE_SHIFT))&QSPI_QDR_COMMAND_BITSE_MASK) /*!< QSPI_QDR_COMMAND                        */
#define QSPI_QDR_COMMAND_CONT_MASK               (0x80U)                                             /*!< QSPI_QDR_COMMAND: CONT Mask             */
#define QSPI_QDR_COMMAND_CONT_SHIFT              (7U)                                                /*!< QSPI_QDR_COMMAND: CONT Position         */
#define QSPI_QDR_COMMAND_CONT(x)                 (((uint8_t)(((uint8_t)(x))<<QSPI_QDR_COMMAND_CONT_SHIFT))&QSPI_QDR_COMMAND_CONT_MASK) /*!< QSPI_QDR_COMMAND                        */
/**
 * @} */ /* End group QSPI_Register_Masks_GROUP 
 */

/* QSPI - Peripheral instance base addresses */
#define QSPI_BasePtr                   0x40000340UL //!< Peripheral base address
#define QSPI                           ((QSPI_Type *) QSPI_BasePtr) //!< Freescale base pointer
#define QSPI_BASE_PTR                  (QSPI) //!< Freescale style base pointer
/**
 * @} */ /* End group QSPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:MCF52233_RCM)              ================ */
/* ================================================================================ */

/**
 * @brief Reset Controller Module
 */
/**
* @addtogroup RCM_structs_GROUP RCM struct
* @brief Struct for RCM
* @{
*/
typedef struct {                                /*       RCM Structure                                                */
   __IO uint8_t   RCR;                          /**< 0000: Reset Control Register                                       */
   __I  uint8_t   RSR;                          /**< 0001: Reset Status Register                                        */
} RCM_Type;

/**
 * @} */ /* End group RCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RCM_Register_Masks_GROUP RCM Register Masks
* @brief Register Masks for RCM
* @{
*/
/* ------- RCR Bit Fields                           ------ */
#define RCM_RCR_LVDE_MASK                        (0x1U)                                              /*!< RCM_RCR: LVDE Mask                      */
#define RCM_RCR_LVDE_SHIFT                       (0U)                                                /*!< RCM_RCR: LVDE Position                  */
#define RCM_RCR_LVDE(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_RCR_LVDE_SHIFT))&RCM_RCR_LVDE_MASK) /*!< RCM_RCR                                 */
#define RCM_RCR_LVDRE_MASK                       (0x4U)                                              /*!< RCM_RCR: LVDRE Mask                     */
#define RCM_RCR_LVDRE_SHIFT                      (2U)                                                /*!< RCM_RCR: LVDRE Position                 */
#define RCM_RCR_LVDRE(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_RCR_LVDRE_SHIFT))&RCM_RCR_LVDRE_MASK) /*!< RCM_RCR                                 */
#define RCM_RCR_LVDIE_MASK                       (0x8U)                                              /*!< RCM_RCR: LVDIE Mask                     */
#define RCM_RCR_LVDIE_SHIFT                      (3U)                                                /*!< RCM_RCR: LVDIE Position                 */
#define RCM_RCR_LVDIE(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_RCR_LVDIE_SHIFT))&RCM_RCR_LVDIE_MASK) /*!< RCM_RCR                                 */
#define RCM_RCR_LVDF_MASK                        (0x10U)                                             /*!< RCM_RCR: LVDF Mask                      */
#define RCM_RCR_LVDF_SHIFT                       (4U)                                                /*!< RCM_RCR: LVDF Position                  */
#define RCM_RCR_LVDF(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_RCR_LVDF_SHIFT))&RCM_RCR_LVDF_MASK) /*!< RCM_RCR                                 */
#define RCM_RCR_FRCRSTOUT_MASK                   (0x40U)                                             /*!< RCM_RCR: FRCRSTOUT Mask                 */
#define RCM_RCR_FRCRSTOUT_SHIFT                  (6U)                                                /*!< RCM_RCR: FRCRSTOUT Position             */
#define RCM_RCR_FRCRSTOUT(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_RCR_FRCRSTOUT_SHIFT))&RCM_RCR_FRCRSTOUT_MASK) /*!< RCM_RCR                                 */
#define RCM_RCR_SOFTRST_MASK                     (0x80U)                                             /*!< RCM_RCR: SOFTRST Mask                   */
#define RCM_RCR_SOFTRST_SHIFT                    (7U)                                                /*!< RCM_RCR: SOFTRST Position               */
#define RCM_RCR_SOFTRST(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_RCR_SOFTRST_SHIFT))&RCM_RCR_SOFTRST_MASK) /*!< RCM_RCR                                 */
/* ------- RSR Bit Fields                           ------ */
#define RCM_RSR_LOL_MASK                         (0x1U)                                              /*!< RCM_RSR: LOL Mask                       */
#define RCM_RSR_LOL_SHIFT                        (0U)                                                /*!< RCM_RSR: LOL Position                   */
#define RCM_RSR_LOL(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_RSR_LOL_SHIFT))&RCM_RSR_LOL_MASK) /*!< RCM_RSR                                 */
#define RCM_RSR_LOC_MASK                         (0x2U)                                              /*!< RCM_RSR: LOC Mask                       */
#define RCM_RSR_LOC_SHIFT                        (1U)                                                /*!< RCM_RSR: LOC Position                   */
#define RCM_RSR_LOC(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_RSR_LOC_SHIFT))&RCM_RSR_LOC_MASK) /*!< RCM_RSR                                 */
#define RCM_RSR_EXT_MASK                         (0x4U)                                              /*!< RCM_RSR: EXT Mask                       */
#define RCM_RSR_EXT_SHIFT                        (2U)                                                /*!< RCM_RSR: EXT Position                   */
#define RCM_RSR_EXT(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_RSR_EXT_SHIFT))&RCM_RSR_EXT_MASK) /*!< RCM_RSR                                 */
#define RCM_RSR_POR_MASK                         (0x8U)                                              /*!< RCM_RSR: POR Mask                       */
#define RCM_RSR_POR_SHIFT                        (3U)                                                /*!< RCM_RSR: POR Position                   */
#define RCM_RSR_POR(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_RSR_POR_SHIFT))&RCM_RSR_POR_MASK) /*!< RCM_RSR                                 */
#define RCM_RSR_SOFT_MASK                        (0x20U)                                             /*!< RCM_RSR: SOFT Mask                      */
#define RCM_RSR_SOFT_SHIFT                       (5U)                                                /*!< RCM_RSR: SOFT Position                  */
#define RCM_RSR_SOFT(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_RSR_SOFT_SHIFT))&RCM_RSR_SOFT_MASK) /*!< RCM_RSR                                 */
#define RCM_RSR_LVD_MASK                         (0x40U)                                             /*!< RCM_RSR: LVD Mask                       */
#define RCM_RSR_LVD_SHIFT                        (6U)                                                /*!< RCM_RSR: LVD Position                   */
#define RCM_RSR_LVD(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_RSR_LVD_SHIFT))&RCM_RSR_LVD_MASK) /*!< RCM_RSR                                 */
/**
 * @} */ /* End group RCM_Register_Masks_GROUP 
 */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x40110000UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer
/**
 * @} */ /* End group RCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer
* @brief C Struct for RTC
* @{
*/

/* ================================================================================ */
/* ================           RTC (file:MCF52233_RTC)              ================ */
/* ================================================================================ */

/**
 * @brief Real-Time Clock
 */
/**
* @addtogroup RTC_structs_GROUP RTC struct
* @brief Struct for RTC
* @{
*/
typedef struct {                                /*       RTC Structure                                                */
   __IO uint32_t  HOURMIN;                      /**< 0000: Hours and Minutes Counter                                    */
   __IO uint32_t  SECONDS;                      /**< 0004: Seconds Counter                                              */
   __IO uint32_t  ALRM_HM;                      /**< 0008: Hours and Minutes Alarm                                      */
   __IO uint32_t  ALRM_SEC;                     /**< 000C: Seconds Alarm                                                */
   __IO uint32_t  RTCCTL;                       /**< 0010: Control                                                      */
   __IO uint32_t  RTCISR;                       /**< 0014: Interrupt Status                                             */
   __IO uint32_t  RTCIENR;                      /**< 0018: Interrupt Enable                                             */
   __IO uint32_t  STPWCH;                       /**< 001C: Stop-watch Minutes                                           */
   __IO uint32_t  DAYS;                         /**< 0020: Days Counter                                                 */
   __IO uint32_t  ALRM_DAY;                     /**< 0024: Day Alarm                                                    */
} RTC_Type;

/**
 * @} */ /* End group RTC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RTC_Register_Masks_GROUP RTC Register Masks
* @brief Register Masks for RTC
* @{
*/
/* ------- HOURMIN Bit Fields                       ------ */
#define RTC_HOURMIN_MINUTES_MASK                 (0x3FU)                                             /*!< RTC_HOURMIN: MINUTES Mask               */
#define RTC_HOURMIN_MINUTES_SHIFT                (0U)                                                /*!< RTC_HOURMIN: MINUTES Position           */
#define RTC_HOURMIN_MINUTES(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_HOURMIN_MINUTES_SHIFT))&RTC_HOURMIN_MINUTES_MASK) /*!< RTC_HOURMIN                             */
#define RTC_HOURMIN_HOURS_MASK                   (0x1F00U)                                           /*!< RTC_HOURMIN: HOURS Mask                 */
#define RTC_HOURMIN_HOURS_SHIFT                  (8U)                                                /*!< RTC_HOURMIN: HOURS Position             */
#define RTC_HOURMIN_HOURS(x)                     (((uint32_t)(((uint32_t)(x))<<RTC_HOURMIN_HOURS_SHIFT))&RTC_HOURMIN_HOURS_MASK) /*!< RTC_HOURMIN                             */
/* ------- SECONDS Bit Fields                       ------ */
#define RTC_SECONDS_SECONDS_MASK                 (0x3FU)                                             /*!< RTC_SECONDS: SECONDS Mask               */
#define RTC_SECONDS_SECONDS_SHIFT                (0U)                                                /*!< RTC_SECONDS: SECONDS Position           */
#define RTC_SECONDS_SECONDS(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_SECONDS_SECONDS_SHIFT))&RTC_SECONDS_SECONDS_MASK) /*!< RTC_SECONDS                             */
/* ------- ALRM_HM Bit Fields                       ------ */
#define RTC_ALRM_HM_MINUTES_MASK                 (0x3FU)                                             /*!< RTC_ALRM_HM: MINUTES Mask               */
#define RTC_ALRM_HM_MINUTES_SHIFT                (0U)                                                /*!< RTC_ALRM_HM: MINUTES Position           */
#define RTC_ALRM_HM_MINUTES(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_ALRM_HM_MINUTES_SHIFT))&RTC_ALRM_HM_MINUTES_MASK) /*!< RTC_ALRM_HM                             */
#define RTC_ALRM_HM_HOURS_MASK                   (0x1F00U)                                           /*!< RTC_ALRM_HM: HOURS Mask                 */
#define RTC_ALRM_HM_HOURS_SHIFT                  (8U)                                                /*!< RTC_ALRM_HM: HOURS Position             */
#define RTC_ALRM_HM_HOURS(x)                     (((uint32_t)(((uint32_t)(x))<<RTC_ALRM_HM_HOURS_SHIFT))&RTC_ALRM_HM_HOURS_MASK) /*!< RTC_ALRM_HM                             */
/* ------- ALRM_SEC Bit Fields                      ------ */
#define RTC_ALRM_SEC_SECONDS_MASK                (0x3FU)                                             /*!< RTC_ALRM_SEC: SECONDS Mask              */
#define RTC_ALRM_SEC_SECONDS_SHIFT               (0U)                                                /*!< RTC_ALRM_SEC: SECONDS Position          */
#define RTC_ALRM_SEC_SECONDS(x)                  (((uint32_t)(((uint32_t)(x))<<RTC_ALRM_SEC_SECONDS_SHIFT))&RTC_ALRM_SEC_SECONDS_MASK) /*!< RTC_ALRM_SEC                            */
/* ------- RTCCTL Bit Fields                        ------ */
#define RTC_RTCCTL_SWR_MASK                      (0x1U)                                              /*!< RTC_RTCCTL: SWR Mask                    */
#define RTC_RTCCTL_SWR_SHIFT                     (0U)                                                /*!< RTC_RTCCTL: SWR Position                */
#define RTC_RTCCTL_SWR(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_RTCCTL_SWR_SHIFT))&RTC_RTCCTL_SWR_MASK) /*!< RTC_RTCCTL                              */
#define RTC_RTCCTL_EN_MASK                       (0x80U)                                             /*!< RTC_RTCCTL: EN Mask                     */
#define RTC_RTCCTL_EN_SHIFT                      (7U)                                                /*!< RTC_RTCCTL: EN Position                 */
#define RTC_RTCCTL_EN(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_RTCCTL_EN_SHIFT))&RTC_RTCCTL_EN_MASK) /*!< RTC_RTCCTL                              */
/* ------- RTCISR Bit Fields                        ------ */
#define RTC_RTCISR_SW_MASK                       (0x1U)                                              /*!< RTC_RTCISR: SW Mask                     */
#define RTC_RTCISR_SW_SHIFT                      (0U)                                                /*!< RTC_RTCISR: SW Position                 */
#define RTC_RTCISR_SW(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_RTCISR_SW_SHIFT))&RTC_RTCISR_SW_MASK) /*!< RTC_RTCISR                              */
#define RTC_RTCISR_MIN_MASK                      (0x2U)                                              /*!< RTC_RTCISR: MIN Mask                    */
#define RTC_RTCISR_MIN_SHIFT                     (1U)                                                /*!< RTC_RTCISR: MIN Position                */
#define RTC_RTCISR_MIN(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_RTCISR_MIN_SHIFT))&RTC_RTCISR_MIN_MASK) /*!< RTC_RTCISR                              */
#define RTC_RTCISR_ALM_MASK                      (0x4U)                                              /*!< RTC_RTCISR: ALM Mask                    */
#define RTC_RTCISR_ALM_SHIFT                     (2U)                                                /*!< RTC_RTCISR: ALM Position                */
#define RTC_RTCISR_ALM(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_RTCISR_ALM_SHIFT))&RTC_RTCISR_ALM_MASK) /*!< RTC_RTCISR                              */
#define RTC_RTCISR_DAY_MASK                      (0x8U)                                              /*!< RTC_RTCISR: DAY Mask                    */
#define RTC_RTCISR_DAY_SHIFT                     (3U)                                                /*!< RTC_RTCISR: DAY Position                */
#define RTC_RTCISR_DAY(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_RTCISR_DAY_SHIFT))&RTC_RTCISR_DAY_MASK) /*!< RTC_RTCISR                              */
#define RTC_RTCISR_HZ1_MASK                      (0x10U)                                             /*!< RTC_RTCISR: HZ1 Mask                    */
#define RTC_RTCISR_HZ1_SHIFT                     (4U)                                                /*!< RTC_RTCISR: HZ1 Position                */
#define RTC_RTCISR_HZ1(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_RTCISR_HZ1_SHIFT))&RTC_RTCISR_HZ1_MASK) /*!< RTC_RTCISR                              */
#define RTC_RTCISR_HR_MASK                       (0x20U)                                             /*!< RTC_RTCISR: HR Mask                     */
#define RTC_RTCISR_HR_SHIFT                      (5U)                                                /*!< RTC_RTCISR: HR Position                 */
#define RTC_RTCISR_HR(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_RTCISR_HR_SHIFT))&RTC_RTCISR_HR_MASK) /*!< RTC_RTCISR                              */
/* ------- RTCIENR Bit Fields                       ------ */
#define RTC_RTCIENR_SW_MASK                      (0x1U)                                              /*!< RTC_RTCIENR: SW Mask                    */
#define RTC_RTCIENR_SW_SHIFT                     (0U)                                                /*!< RTC_RTCIENR: SW Position                */
#define RTC_RTCIENR_SW(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_RTCIENR_SW_SHIFT))&RTC_RTCIENR_SW_MASK) /*!< RTC_RTCIENR                             */
#define RTC_RTCIENR_MIN_MASK                     (0x2U)                                              /*!< RTC_RTCIENR: MIN Mask                   */
#define RTC_RTCIENR_MIN_SHIFT                    (1U)                                                /*!< RTC_RTCIENR: MIN Position               */
#define RTC_RTCIENR_MIN(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_RTCIENR_MIN_SHIFT))&RTC_RTCIENR_MIN_MASK) /*!< RTC_RTCIENR                             */
#define RTC_RTCIENR_ALM_MASK                     (0x4U)                                              /*!< RTC_RTCIENR: ALM Mask                   */
#define RTC_RTCIENR_ALM_SHIFT                    (2U)                                                /*!< RTC_RTCIENR: ALM Position               */
#define RTC_RTCIENR_ALM(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_RTCIENR_ALM_SHIFT))&RTC_RTCIENR_ALM_MASK) /*!< RTC_RTCIENR                             */
#define RTC_RTCIENR_DAY_MASK                     (0x8U)                                              /*!< RTC_RTCIENR: DAY Mask                   */
#define RTC_RTCIENR_DAY_SHIFT                    (3U)                                                /*!< RTC_RTCIENR: DAY Position               */
#define RTC_RTCIENR_DAY(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_RTCIENR_DAY_SHIFT))&RTC_RTCIENR_DAY_MASK) /*!< RTC_RTCIENR                             */
#define RTC_RTCIENR_HZ1_MASK                     (0x10U)                                             /*!< RTC_RTCIENR: HZ1 Mask                   */
#define RTC_RTCIENR_HZ1_SHIFT                    (4U)                                                /*!< RTC_RTCIENR: HZ1 Position               */
#define RTC_RTCIENR_HZ1(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_RTCIENR_HZ1_SHIFT))&RTC_RTCIENR_HZ1_MASK) /*!< RTC_RTCIENR                             */
#define RTC_RTCIENR_HR_MASK                      (0x20U)                                             /*!< RTC_RTCIENR: HR Mask                    */
#define RTC_RTCIENR_HR_SHIFT                     (5U)                                                /*!< RTC_RTCIENR: HR Position                */
#define RTC_RTCIENR_HR(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_RTCIENR_HR_SHIFT))&RTC_RTCIENR_HR_MASK) /*!< RTC_RTCIENR                             */
/* ------- STPWCH Bit Fields                        ------ */
#define RTC_STPWCH_CNT_MASK                      (0x3FU)                                             /*!< RTC_STPWCH: CNT Mask                    */
#define RTC_STPWCH_CNT_SHIFT                     (0U)                                                /*!< RTC_STPWCH: CNT Position                */
#define RTC_STPWCH_CNT(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_STPWCH_CNT_SHIFT))&RTC_STPWCH_CNT_MASK) /*!< RTC_STPWCH                              */
/* ------- DAYS Bit Fields                          ------ */
#define RTC_DAYS_DAYS_MASK                       (0xFFFFU)                                           /*!< RTC_DAYS: DAYS Mask                     */
#define RTC_DAYS_DAYS_SHIFT                      (0U)                                                /*!< RTC_DAYS: DAYS Position                 */
#define RTC_DAYS_DAYS(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_DAYS_DAYS_SHIFT))&RTC_DAYS_DAYS_MASK) /*!< RTC_DAYS                                */
/* ------- ALRM_DAY Bit Fields                      ------ */
#define RTC_ALRM_DAY_DAYSAL_MASK                 (0xFFFFU)                                           /*!< RTC_ALRM_DAY: DAYSAL Mask               */
#define RTC_ALRM_DAY_DAYSAL_SHIFT                (0U)                                                /*!< RTC_ALRM_DAY: DAYSAL Position           */
#define RTC_ALRM_DAY_DAYSAL(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_ALRM_DAY_DAYSAL_SHIFT))&RTC_ALRM_DAY_DAYSAL_MASK) /*!< RTC_ALRM_DAY                            */
/**
 * @} */ /* End group RTC_Register_Masks_GROUP 
 */

/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x400003C0UL //!< Peripheral base address
#define RTC                            ((RTC_Type *) RTC_BasePtr) //!< Freescale base pointer
#define RTC_BASE_PTR                   (RTC) //!< Freescale style base pointer
/**
 * @} */ /* End group RTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SCM_Peripheral_access_layer_GROUP SCM Peripheral Access Layer
* @brief C Struct for SCM
* @{
*/

/* ================================================================================ */
/* ================           SCM (file:MCF52233_SCM)              ================ */
/* ================================================================================ */

/**
 * @brief System Control Module
 */
/**
* @addtogroup SCM_structs_GROUP SCM struct
* @brief Struct for SCM
* @{
*/
typedef struct {                                /*       SCM Structure                                                */
   __IO uint32_t  IPSBAR;                       /**< 0000: Peripheral System Base Address Register                      */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  RAMBAR;                       /**< 0008: Memory Base Address Register                                 */
   __IO uint32_t  PPMRH;                        /**< 000C: Peripheral Power Management                                  */
   __IO uint8_t   CRSR;                         /**< 0010: Core Reset Status Register                                   */
   __IO uint8_t   CWCR;                         /**< 0011: Core Watchdog Control Register                               */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   CWSR;                         /**< 0013: Watchdog Service Register                                    */
   __IO uint32_t  DMAREQC;                      /**< 0014: DMA Request Control                                          */
   __IO uint32_t  PPMRL;                        /**< 0018: Peripheral Power Management                                  */
   __IO uint32_t  MPARK;                        /**< 001C: Bus Master Park Register                                     */
   __IO uint8_t   MPR;                          /**< 0020: Controls the bus master privilege level                      */
   __IO uint8_t   PPMRS;                        /**< 0021: Peripheral Power Management Set Register                     */
   __IO uint8_t   PPMRC;                        /**< 0022: Peripheral Power Management Clear Register                   */
   __IO uint8_t   IPSBMT;                       /**< 0023: IPS Bus Timeout Monitor                                      */
   __IO uint8_t   PACR[9];                      /**< 0024: Peripheral Access Control Register                           */
        uint8_t   RESERVED_2[3];               
   __IO uint8_t   GPACR[2];                     /**< 0030: Grouped Peripheral Access Control                            */
} SCM_Type;

/**
 * @} */ /* End group SCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SCM_Register_Masks_GROUP SCM Register Masks
* @brief Register Masks for SCM
* @{
*/
/* ------- IPSBAR Bit Fields                        ------ */
#define SCM_IPSBAR_V_MASK                        (0x1U)                                              /*!< SCM_IPSBAR: V Mask                      */
#define SCM_IPSBAR_V_SHIFT                       (0U)                                                /*!< SCM_IPSBAR: V Position                  */
#define SCM_IPSBAR_V(x)                          (((uint32_t)(((uint32_t)(x))<<SCM_IPSBAR_V_SHIFT))&SCM_IPSBAR_V_MASK) /*!< SCM_IPSBAR                              */
#define SCM_IPSBAR_BA_MASK                       (0xC0000000U)                                       /*!< SCM_IPSBAR: BA Mask                     */
#define SCM_IPSBAR_BA_SHIFT                      (30U)                                               /*!< SCM_IPSBAR: BA Position                 */
#define SCM_IPSBAR_BA(x)                         (((uint32_t)(((uint32_t)(x))<<SCM_IPSBAR_BA_SHIFT))&SCM_IPSBAR_BA_MASK) /*!< SCM_IPSBAR                              */
/* ------- RAMBAR Bit Fields                        ------ */
#define SCM_RAMBAR_BDE_MASK                      (0x200U)                                            /*!< SCM_RAMBAR: BDE Mask                    */
#define SCM_RAMBAR_BDE_SHIFT                     (9U)                                                /*!< SCM_RAMBAR: BDE Position                */
#define SCM_RAMBAR_BDE(x)                        (((uint32_t)(((uint32_t)(x))<<SCM_RAMBAR_BDE_SHIFT))&SCM_RAMBAR_BDE_MASK) /*!< SCM_RAMBAR                              */
#define SCM_RAMBAR_BA_MASK                       (0xFFFF0000U)                                       /*!< SCM_RAMBAR: BA Mask                     */
#define SCM_RAMBAR_BA_SHIFT                      (16U)                                               /*!< SCM_RAMBAR: BA Position                 */
#define SCM_RAMBAR_BA(x)                         (((uint32_t)(((uint32_t)(x))<<SCM_RAMBAR_BA_SHIFT))&SCM_RAMBAR_BA_MASK) /*!< SCM_RAMBAR                              */
/* ------- PPMRH Bit Fields                         ------ */
#define SCM_PPMRH_CDGPIO_MASK                    (0x1U)                                              /*!< SCM_PPMRH: CDGPIO Mask                  */
#define SCM_PPMRH_CDGPIO_SHIFT                   (0U)                                                /*!< SCM_PPMRH: CDGPIO Position              */
#define SCM_PPMRH_CDGPIO(x)                      (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDGPIO_SHIFT))&SCM_PPMRH_CDGPIO_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDEPORT_MASK                   (0x2U)                                              /*!< SCM_PPMRH: CDEPORT Mask                 */
#define SCM_PPMRH_CDEPORT_SHIFT                  (1U)                                                /*!< SCM_PPMRH: CDEPORT Position             */
#define SCM_PPMRH_CDEPORT(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDEPORT_SHIFT))&SCM_PPMRH_CDEPORT_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDPIT0_MASK                    (0x8U)                                              /*!< SCM_PPMRH: CDPIT0 Mask                  */
#define SCM_PPMRH_CDPIT0_SHIFT                   (3U)                                                /*!< SCM_PPMRH: CDPIT0 Position              */
#define SCM_PPMRH_CDPIT0(x)                      (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDPIT0_SHIFT))&SCM_PPMRH_CDPIT0_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDPIT1_MASK                    (0x10U)                                             /*!< SCM_PPMRH: CDPIT1 Mask                  */
#define SCM_PPMRH_CDPIT1_SHIFT                   (4U)                                                /*!< SCM_PPMRH: CDPIT1 Position              */
#define SCM_PPMRH_CDPIT1(x)                      (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDPIT1_SHIFT))&SCM_PPMRH_CDPIT1_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDADC_MASK                     (0x80U)                                             /*!< SCM_PPMRH: CDADC Mask                   */
#define SCM_PPMRH_CDADC_SHIFT                    (7U)                                                /*!< SCM_PPMRH: CDADC Position               */
#define SCM_PPMRH_CDADC(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDADC_SHIFT))&SCM_PPMRH_CDADC_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDGPT_MASK                     (0x100U)                                            /*!< SCM_PPMRH: CDGPT Mask                   */
#define SCM_PPMRH_CDGPT_SHIFT                    (8U)                                                /*!< SCM_PPMRH: CDGPT Position               */
#define SCM_PPMRH_CDGPT(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDGPT_SHIFT))&SCM_PPMRH_CDGPT_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDPWM_MASK                     (0x200U)                                            /*!< SCM_PPMRH: CDPWM Mask                   */
#define SCM_PPMRH_CDPWM_SHIFT                    (9U)                                                /*!< SCM_PPMRH: CDPWM Position               */
#define SCM_PPMRH_CDPWM(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDPWM_SHIFT))&SCM_PPMRH_CDPWM_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDCAN_MASK                     (0x400U)                                            /*!< SCM_PPMRH: CDCAN Mask                   */
#define SCM_PPMRH_CDCAN_SHIFT                    (10U)                                               /*!< SCM_PPMRH: CDCAN Position               */
#define SCM_PPMRH_CDCAN(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDCAN_SHIFT))&SCM_PPMRH_CDCAN_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDCFM_MASK                     (0x800U)                                            /*!< SCM_PPMRH: CDCFM Mask                   */
#define SCM_PPMRH_CDCFM_SHIFT                    (11U)                                               /*!< SCM_PPMRH: CDCFM Position               */
#define SCM_PPMRH_CDCFM(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDCFM_SHIFT))&SCM_PPMRH_CDCFM_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDEPHY_MASK                    (0x1000U)                                           /*!< SCM_PPMRH: CDEPHY Mask                  */
#define SCM_PPMRH_CDEPHY_SHIFT                   (12U)                                               /*!< SCM_PPMRH: CDEPHY Position              */
#define SCM_PPMRH_CDEPHY(x)                      (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDEPHY_SHIFT))&SCM_PPMRH_CDEPHY_MASK) /*!< SCM_PPMRH                               */
#define SCM_PPMRH_CDRNGA_MASK                    (0x2000U)                                           /*!< SCM_PPMRH: CDRNGA Mask                  */
#define SCM_PPMRH_CDRNGA_SHIFT                   (13U)                                               /*!< SCM_PPMRH: CDRNGA Position              */
#define SCM_PPMRH_CDRNGA(x)                      (((uint32_t)(((uint32_t)(x))<<SCM_PPMRH_CDRNGA_SHIFT))&SCM_PPMRH_CDRNGA_MASK) /*!< SCM_PPMRH                               */
/* ------- CRSR Bit Fields                          ------ */
#define SCM_CRSR_EXT_MASK                        (0x80U)                                             /*!< SCM_CRSR: EXT Mask                      */
#define SCM_CRSR_EXT_SHIFT                       (7U)                                                /*!< SCM_CRSR: EXT Position                  */
#define SCM_CRSR_EXT(x)                          (((uint8_t)(((uint8_t)(x))<<SCM_CRSR_EXT_SHIFT))&SCM_CRSR_EXT_MASK) /*!< SCM_CRSR                                */
/* ------- CWCR Bit Fields                          ------ */
#define SCM_CWCR_CWTIF_MASK                      (0x1U)                                              /*!< SCM_CWCR: CWTIF Mask                    */
#define SCM_CWCR_CWTIF_SHIFT                     (0U)                                                /*!< SCM_CWCR: CWTIF Position                */
#define SCM_CWCR_CWTIF(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_CWCR_CWTIF_SHIFT))&SCM_CWCR_CWTIF_MASK) /*!< SCM_CWCR                                */
#define SCM_CWCR_CWTAVAL_MASK                    (0x2U)                                              /*!< SCM_CWCR: CWTAVAL Mask                  */
#define SCM_CWCR_CWTAVAL_SHIFT                   (1U)                                                /*!< SCM_CWCR: CWTAVAL Position              */
#define SCM_CWCR_CWTAVAL(x)                      (((uint8_t)(((uint8_t)(x))<<SCM_CWCR_CWTAVAL_SHIFT))&SCM_CWCR_CWTAVAL_MASK) /*!< SCM_CWCR                                */
#define SCM_CWCR_CWTA_MASK                       (0x4U)                                              /*!< SCM_CWCR: CWTA Mask                     */
#define SCM_CWCR_CWTA_SHIFT                      (2U)                                                /*!< SCM_CWCR: CWTA Position                 */
#define SCM_CWCR_CWTA(x)                         (((uint8_t)(((uint8_t)(x))<<SCM_CWCR_CWTA_SHIFT))&SCM_CWCR_CWTA_MASK) /*!< SCM_CWCR                                */
#define SCM_CWCR_CWT_MASK                        (0x38U)                                             /*!< SCM_CWCR: CWT Mask                      */
#define SCM_CWCR_CWT_SHIFT                       (3U)                                                /*!< SCM_CWCR: CWT Position                  */
#define SCM_CWCR_CWT(x)                          (((uint8_t)(((uint8_t)(x))<<SCM_CWCR_CWT_SHIFT))&SCM_CWCR_CWT_MASK) /*!< SCM_CWCR                                */
#define SCM_CWCR_CWRI_MASK                       (0x40U)                                             /*!< SCM_CWCR: CWRI Mask                     */
#define SCM_CWCR_CWRI_SHIFT                      (6U)                                                /*!< SCM_CWCR: CWRI Position                 */
#define SCM_CWCR_CWRI(x)                         (((uint8_t)(((uint8_t)(x))<<SCM_CWCR_CWRI_SHIFT))&SCM_CWCR_CWRI_MASK) /*!< SCM_CWCR                                */
#define SCM_CWCR_CWE_MASK                        (0x80U)                                             /*!< SCM_CWCR: CWE Mask                      */
#define SCM_CWCR_CWE_SHIFT                       (7U)                                                /*!< SCM_CWCR: CWE Position                  */
#define SCM_CWCR_CWE(x)                          (((uint8_t)(((uint8_t)(x))<<SCM_CWCR_CWE_SHIFT))&SCM_CWCR_CWE_MASK) /*!< SCM_CWCR                                */
/* ------- CWSR Bit Fields                          ------ */
/* ------- DMAREQC Bit Fields                       ------ */
#define SCM_DMAREQC_DMAC0_MASK                   (0xFU)                                              /*!< SCM_DMAREQC: DMAC0 Mask                 */
#define SCM_DMAREQC_DMAC0_SHIFT                  (0U)                                                /*!< SCM_DMAREQC: DMAC0 Position             */
#define SCM_DMAREQC_DMAC0(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_DMAREQC_DMAC0_SHIFT))&SCM_DMAREQC_DMAC0_MASK) /*!< SCM_DMAREQC                             */
#define SCM_DMAREQC_DMAC1_MASK                   (0xF0U)                                             /*!< SCM_DMAREQC: DMAC1 Mask                 */
#define SCM_DMAREQC_DMAC1_SHIFT                  (4U)                                                /*!< SCM_DMAREQC: DMAC1 Position             */
#define SCM_DMAREQC_DMAC1(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_DMAREQC_DMAC1_SHIFT))&SCM_DMAREQC_DMAC1_MASK) /*!< SCM_DMAREQC                             */
#define SCM_DMAREQC_DMAC2_MASK                   (0xF00U)                                            /*!< SCM_DMAREQC: DMAC2 Mask                 */
#define SCM_DMAREQC_DMAC2_SHIFT                  (8U)                                                /*!< SCM_DMAREQC: DMAC2 Position             */
#define SCM_DMAREQC_DMAC2(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_DMAREQC_DMAC2_SHIFT))&SCM_DMAREQC_DMAC2_MASK) /*!< SCM_DMAREQC                             */
#define SCM_DMAREQC_DMAC3_MASK                   (0xF000U)                                           /*!< SCM_DMAREQC: DMAC3 Mask                 */
#define SCM_DMAREQC_DMAC3_SHIFT                  (12U)                                               /*!< SCM_DMAREQC: DMAC3 Position             */
#define SCM_DMAREQC_DMAC3(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_DMAREQC_DMAC3_SHIFT))&SCM_DMAREQC_DMAC3_MASK) /*!< SCM_DMAREQC                             */
/* ------- PPMRL Bit Fields                         ------ */
#define SCM_PPMRL_CDG_MASK                       (0x2U)                                              /*!< SCM_PPMRL: CDG Mask                     */
#define SCM_PPMRL_CDG_SHIFT                      (1U)                                                /*!< SCM_PPMRL: CDG Position                 */
#define SCM_PPMRL_CDG(x)                         (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDG_SHIFT))&SCM_PPMRL_CDG_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDDMA_MASK                     (0x10U)                                             /*!< SCM_PPMRL: CDDMA Mask                   */
#define SCM_PPMRL_CDDMA_SHIFT                    (4U)                                                /*!< SCM_PPMRL: CDDMA Position               */
#define SCM_PPMRL_CDDMA(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDDMA_SHIFT))&SCM_PPMRL_CDDMA_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDUART0_MASK                   (0x20U)                                             /*!< SCM_PPMRL: CDUART0 Mask                 */
#define SCM_PPMRL_CDUART0_SHIFT                  (5U)                                                /*!< SCM_PPMRL: CDUART0 Position             */
#define SCM_PPMRL_CDUART0(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDUART0_SHIFT))&SCM_PPMRL_CDUART0_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDUART1_MASK                   (0x40U)                                             /*!< SCM_PPMRL: CDUART1 Mask                 */
#define SCM_PPMRL_CDUART1_SHIFT                  (6U)                                                /*!< SCM_PPMRL: CDUART1 Position             */
#define SCM_PPMRL_CDUART1(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDUART1_SHIFT))&SCM_PPMRL_CDUART1_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDUART2_MASK                   (0x80U)                                             /*!< SCM_PPMRL: CDUART2 Mask                 */
#define SCM_PPMRL_CDUART2_SHIFT                  (7U)                                                /*!< SCM_PPMRL: CDUART2 Position             */
#define SCM_PPMRL_CDUART2(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDUART2_SHIFT))&SCM_PPMRL_CDUART2_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDI2C0_MASK                    (0x200U)                                            /*!< SCM_PPMRL: CDI2C0 Mask                  */
#define SCM_PPMRL_CDI2C0_SHIFT                   (9U)                                                /*!< SCM_PPMRL: CDI2C0 Position              */
#define SCM_PPMRL_CDI2C0(x)                      (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDI2C0_SHIFT))&SCM_PPMRL_CDI2C0_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDQSPI_MASK                    (0x400U)                                            /*!< SCM_PPMRL: CDQSPI Mask                  */
#define SCM_PPMRL_CDQSPI_SHIFT                   (10U)                                               /*!< SCM_PPMRL: CDQSPI Position              */
#define SCM_PPMRL_CDQSPI(x)                      (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDQSPI_SHIFT))&SCM_PPMRL_CDQSPI_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDRTC_MASK                     (0x1000U)                                           /*!< SCM_PPMRL: CDRTC Mask                   */
#define SCM_PPMRL_CDRTC_SHIFT                    (12U)                                               /*!< SCM_PPMRL: CDRTC Position               */
#define SCM_PPMRL_CDRTC(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDRTC_SHIFT))&SCM_PPMRL_CDRTC_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDDTIM0_MASK                   (0x2000U)                                           /*!< SCM_PPMRL: CDDTIM0 Mask                 */
#define SCM_PPMRL_CDDTIM0_SHIFT                  (13U)                                               /*!< SCM_PPMRL: CDDTIM0 Position             */
#define SCM_PPMRL_CDDTIM0(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDDTIM0_SHIFT))&SCM_PPMRL_CDDTIM0_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDDTIM1_MASK                   (0x4000U)                                           /*!< SCM_PPMRL: CDDTIM1 Mask                 */
#define SCM_PPMRL_CDDTIM1_SHIFT                  (14U)                                               /*!< SCM_PPMRL: CDDTIM1 Position             */
#define SCM_PPMRL_CDDTIM1(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDDTIM1_SHIFT))&SCM_PPMRL_CDDTIM1_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDDTIM2_MASK                   (0x8000U)                                           /*!< SCM_PPMRL: CDDTIM2 Mask                 */
#define SCM_PPMRL_CDDTIM2_SHIFT                  (15U)                                               /*!< SCM_PPMRL: CDDTIM2 Position             */
#define SCM_PPMRL_CDDTIM2(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDDTIM2_SHIFT))&SCM_PPMRL_CDDTIM2_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDDTIM3_MASK                   (0x10000U)                                          /*!< SCM_PPMRL: CDDTIM3 Mask                 */
#define SCM_PPMRL_CDDTIM3_SHIFT                  (16U)                                               /*!< SCM_PPMRL: CDDTIM3 Position             */
#define SCM_PPMRL_CDDTIM3(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDDTIM3_SHIFT))&SCM_PPMRL_CDDTIM3_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDINTC0_MASK                   (0x20000U)                                          /*!< SCM_PPMRL: CDINTC0 Mask                 */
#define SCM_PPMRL_CDINTC0_SHIFT                  (17U)                                               /*!< SCM_PPMRL: CDINTC0 Position             */
#define SCM_PPMRL_CDINTC0(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDINTC0_SHIFT))&SCM_PPMRL_CDINTC0_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDINTC1_MASK                   (0x40000U)                                          /*!< SCM_PPMRL: CDINTC1 Mask                 */
#define SCM_PPMRL_CDINTC1_SHIFT                  (18U)                                               /*!< SCM_PPMRL: CDINTC1 Position             */
#define SCM_PPMRL_CDINTC1(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDINTC1_SHIFT))&SCM_PPMRL_CDINTC1_MASK) /*!< SCM_PPMRL                               */
#define SCM_PPMRL_CDFEC_MASK                     (0x200000U)                                         /*!< SCM_PPMRL: CDFEC Mask                   */
#define SCM_PPMRL_CDFEC_SHIFT                    (21U)                                               /*!< SCM_PPMRL: CDFEC Position               */
#define SCM_PPMRL_CDFEC(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_PPMRL_CDFEC_SHIFT))&SCM_PPMRL_CDFEC_MASK) /*!< SCM_PPMRL                               */
/* ------- MPARK Bit Fields                         ------ */
#define SCM_MPARK_LCKOUT_TIME_MASK               (0xF00U)                                            /*!< SCM_MPARK: LCKOUT_TIME Mask             */
#define SCM_MPARK_LCKOUT_TIME_SHIFT              (8U)                                                /*!< SCM_MPARK: LCKOUT_TIME Position         */
#define SCM_MPARK_LCKOUT_TIME(x)                 (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_LCKOUT_TIME_SHIFT))&SCM_MPARK_LCKOUT_TIME_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_PRKLAST_MASK                   (0x1000U)                                           /*!< SCM_MPARK: PRKLAST Mask                 */
#define SCM_MPARK_PRKLAST_SHIFT                  (12U)                                               /*!< SCM_MPARK: PRKLAST Position             */
#define SCM_MPARK_PRKLAST(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_PRKLAST_SHIFT))&SCM_MPARK_PRKLAST_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_TIMEOUT_MASK                   (0x2000U)                                           /*!< SCM_MPARK: TIMEOUT Mask                 */
#define SCM_MPARK_TIMEOUT_SHIFT                  (13U)                                               /*!< SCM_MPARK: TIMEOUT Position             */
#define SCM_MPARK_TIMEOUT(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_TIMEOUT_SHIFT))&SCM_MPARK_TIMEOUT_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_FIXED_MASK                     (0x4000U)                                           /*!< SCM_MPARK: FIXED Mask                   */
#define SCM_MPARK_FIXED_SHIFT                    (14U)                                               /*!< SCM_MPARK: FIXED Position               */
#define SCM_MPARK_FIXED(x)                       (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_FIXED_SHIFT))&SCM_MPARK_FIXED_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_M1_PRTY_MASK                   (0x30000U)                                          /*!< SCM_MPARK: M1_PRTY Mask                 */
#define SCM_MPARK_M1_PRTY_SHIFT                  (16U)                                               /*!< SCM_MPARK: M1_PRTY Position             */
#define SCM_MPARK_M1_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_M1_PRTY_SHIFT))&SCM_MPARK_M1_PRTY_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_M0_PRTY_MASK                   (0xC0000U)                                          /*!< SCM_MPARK: M0_PRTY Mask                 */
#define SCM_MPARK_M0_PRTY_SHIFT                  (18U)                                               /*!< SCM_MPARK: M0_PRTY Position             */
#define SCM_MPARK_M0_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_M0_PRTY_SHIFT))&SCM_MPARK_M0_PRTY_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_M2_PRTY_MASK                   (0x300000U)                                         /*!< SCM_MPARK: M2_PRTY Mask                 */
#define SCM_MPARK_M2_PRTY_SHIFT                  (20U)                                               /*!< SCM_MPARK: M2_PRTY Position             */
#define SCM_MPARK_M2_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_M2_PRTY_SHIFT))&SCM_MPARK_M2_PRTY_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_BCR24BIT_MASK                  (0x1000000U)                                        /*!< SCM_MPARK: BCR24BIT Mask                */
#define SCM_MPARK_BCR24BIT_SHIFT                 (24U)                                               /*!< SCM_MPARK: BCR24BIT Position            */
#define SCM_MPARK_BCR24BIT(x)                    (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_BCR24BIT_SHIFT))&SCM_MPARK_BCR24BIT_MASK) /*!< SCM_MPARK                               */
#define SCM_MPARK_M2_P_EN_MASK                   (0x2000000U)                                        /*!< SCM_MPARK: M2_P_EN Mask                 */
#define SCM_MPARK_M2_P_EN_SHIFT                  (25U)                                               /*!< SCM_MPARK: M2_P_EN Position             */
#define SCM_MPARK_M2_P_EN(x)                     (((uint32_t)(((uint32_t)(x))<<SCM_MPARK_M2_P_EN_SHIFT))&SCM_MPARK_M2_P_EN_MASK) /*!< SCM_MPARK                               */
/* ------- MPR Bit Fields                           ------ */
#define SCM_MPR_MPR0_MASK                        (0x1U)                                              /*!< SCM_MPR: MPR0 Mask                      */
#define SCM_MPR_MPR0_SHIFT                       (0U)                                                /*!< SCM_MPR: MPR0 Position                  */
#define SCM_MPR_MPR0(x)                          (((uint8_t)(((uint8_t)(x))<<SCM_MPR_MPR0_SHIFT))&SCM_MPR_MPR0_MASK) /*!< SCM_MPR                                 */
#define SCM_MPR_MPR1_MASK                        (0x2U)                                              /*!< SCM_MPR: MPR1 Mask                      */
#define SCM_MPR_MPR1_SHIFT                       (1U)                                                /*!< SCM_MPR: MPR1 Position                  */
#define SCM_MPR_MPR1(x)                          (((uint8_t)(((uint8_t)(x))<<SCM_MPR_MPR1_SHIFT))&SCM_MPR_MPR1_MASK) /*!< SCM_MPR                                 */
#define SCM_MPR_MPR2_MASK                        (0x4U)                                              /*!< SCM_MPR: MPR2 Mask                      */
#define SCM_MPR_MPR2_SHIFT                       (2U)                                                /*!< SCM_MPR: MPR2 Position                  */
#define SCM_MPR_MPR2(x)                          (((uint8_t)(((uint8_t)(x))<<SCM_MPR_MPR2_SHIFT))&SCM_MPR_MPR2_MASK) /*!< SCM_MPR                                 */
#define SCM_MPR_MPR3_MASK                        (0x8U)                                              /*!< SCM_MPR: MPR3 Mask                      */
#define SCM_MPR_MPR3_SHIFT                       (3U)                                                /*!< SCM_MPR: MPR3 Position                  */
#define SCM_MPR_MPR3(x)                          (((uint8_t)(((uint8_t)(x))<<SCM_MPR_MPR3_SHIFT))&SCM_MPR_MPR3_MASK) /*!< SCM_MPR                                 */
/* ------- PPMRS Bit Fields                         ------ */
#define SCM_PPMRS_SMCD_MASK                      (0x1FU)                                             /*!< SCM_PPMRS: SMCD Mask                    */
#define SCM_PPMRS_SMCD_SHIFT                     (0U)                                                /*!< SCM_PPMRS: SMCD Position                */
#define SCM_PPMRS_SMCD(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_PPMRS_SMCD_SHIFT))&SCM_PPMRS_SMCD_MASK) /*!< SCM_PPMRS                               */
#define SCM_PPMRS_SAMCD_MASK                     (0x40U)                                             /*!< SCM_PPMRS: SAMCD Mask                   */
#define SCM_PPMRS_SAMCD_SHIFT                    (6U)                                                /*!< SCM_PPMRS: SAMCD Position               */
#define SCM_PPMRS_SAMCD(x)                       (((uint8_t)(((uint8_t)(x))<<SCM_PPMRS_SAMCD_SHIFT))&SCM_PPMRS_SAMCD_MASK) /*!< SCM_PPMRS                               */
/* ------- PPMRC Bit Fields                         ------ */
#define SCM_PPMRC_SMCD_MASK                      (0x1FU)                                             /*!< SCM_PPMRC: SMCD Mask                    */
#define SCM_PPMRC_SMCD_SHIFT                     (0U)                                                /*!< SCM_PPMRC: SMCD Position                */
#define SCM_PPMRC_SMCD(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_PPMRC_SMCD_SHIFT))&SCM_PPMRC_SMCD_MASK) /*!< SCM_PPMRC                               */
#define SCM_PPMRC_SAMCD_MASK                     (0x40U)                                             /*!< SCM_PPMRC: SAMCD Mask                   */
#define SCM_PPMRC_SAMCD_SHIFT                    (6U)                                                /*!< SCM_PPMRC: SAMCD Position               */
#define SCM_PPMRC_SAMCD(x)                       (((uint8_t)(((uint8_t)(x))<<SCM_PPMRC_SAMCD_SHIFT))&SCM_PPMRC_SAMCD_MASK) /*!< SCM_PPMRC                               */
/* ------- IPSBMT Bit Fields                        ------ */
#define SCM_IPSBMT_BMT_MASK                      (0x7U)                                              /*!< SCM_IPSBMT: BMT Mask                    */
#define SCM_IPSBMT_BMT_SHIFT                     (0U)                                                /*!< SCM_IPSBMT: BMT Position                */
#define SCM_IPSBMT_BMT(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_IPSBMT_BMT_SHIFT))&SCM_IPSBMT_BMT_MASK) /*!< SCM_IPSBMT                              */
#define SCM_IPSBMT_BME_MASK                      (0x10U)                                             /*!< SCM_IPSBMT: BME Mask                    */
#define SCM_IPSBMT_BME_SHIFT                     (4U)                                                /*!< SCM_IPSBMT: BME Position                */
#define SCM_IPSBMT_BME(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_IPSBMT_BME_SHIFT))&SCM_IPSBMT_BME_MASK) /*!< SCM_IPSBMT                              */
/* ------- PACR Bit Fields                          ------ */
#define SCM_PACR_ACCESS_CTRL0_MASK               (0x7U)                                              /*!< SCM_PACR: ACCESS_CTRL0 Mask             */
#define SCM_PACR_ACCESS_CTRL0_SHIFT              (0U)                                                /*!< SCM_PACR: ACCESS_CTRL0 Position         */
#define SCM_PACR_ACCESS_CTRL0(x)                 (((uint8_t)(((uint8_t)(x))<<SCM_PACR_ACCESS_CTRL0_SHIFT))&SCM_PACR_ACCESS_CTRL0_MASK) /*!< SCM_PACR                                */
#define SCM_PACR_LOCK0_MASK                      (0x8U)                                              /*!< SCM_PACR: LOCK0 Mask                    */
#define SCM_PACR_LOCK0_SHIFT                     (3U)                                                /*!< SCM_PACR: LOCK0 Position                */
#define SCM_PACR_LOCK0(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_PACR_LOCK0_SHIFT))&SCM_PACR_LOCK0_MASK) /*!< SCM_PACR                                */
#define SCM_PACR_ACCESS_CTRL1_MASK               (0x70U)                                             /*!< SCM_PACR: ACCESS_CTRL1 Mask             */
#define SCM_PACR_ACCESS_CTRL1_SHIFT              (4U)                                                /*!< SCM_PACR: ACCESS_CTRL1 Position         */
#define SCM_PACR_ACCESS_CTRL1(x)                 (((uint8_t)(((uint8_t)(x))<<SCM_PACR_ACCESS_CTRL1_SHIFT))&SCM_PACR_ACCESS_CTRL1_MASK) /*!< SCM_PACR                                */
#define SCM_PACR_LOCK1_MASK                      (0x80U)                                             /*!< SCM_PACR: LOCK1 Mask                    */
#define SCM_PACR_LOCK1_SHIFT                     (7U)                                                /*!< SCM_PACR: LOCK1 Position                */
#define SCM_PACR_LOCK1(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_PACR_LOCK1_SHIFT))&SCM_PACR_LOCK1_MASK) /*!< SCM_PACR                                */
/* ------- GPACR Bit Fields                         ------ */
#define SCM_GPACR_ACCESS_CTRL_MASK               (0xFU)                                              /*!< SCM_GPACR: ACCESS_CTRL Mask             */
#define SCM_GPACR_ACCESS_CTRL_SHIFT              (0U)                                                /*!< SCM_GPACR: ACCESS_CTRL Position         */
#define SCM_GPACR_ACCESS_CTRL(x)                 (((uint8_t)(((uint8_t)(x))<<SCM_GPACR_ACCESS_CTRL_SHIFT))&SCM_GPACR_ACCESS_CTRL_MASK) /*!< SCM_GPACR                               */
#define SCM_GPACR_LOCK_MASK                      (0x80U)                                             /*!< SCM_GPACR: LOCK Mask                    */
#define SCM_GPACR_LOCK_SHIFT                     (7U)                                                /*!< SCM_GPACR: LOCK Position                */
#define SCM_GPACR_LOCK(x)                        (((uint8_t)(((uint8_t)(x))<<SCM_GPACR_LOCK_SHIFT))&SCM_GPACR_LOCK_MASK) /*!< SCM_GPACR                               */
/**
 * @} */ /* End group SCM_Register_Masks_GROUP 
 */

/* SCM - Peripheral instance base addresses */
#define SCM_BasePtr                    0x40000000UL //!< Peripheral base address
#define SCM                            ((SCM_Type *) SCM_BasePtr) //!< Freescale base pointer
#define SCM_BASE_PTR                   (SCM) //!< Freescale style base pointer
/**
 * @} */ /* End group SCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART0 (file:MCF522xx_UART0)          ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Rx/Tx
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART0 Structure                                              */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   UMR1;                      /**< 0000: Mode Registers 1                                             */
      __IO uint8_t   UMR2;                      /**< 0000: Mode Registers 2                                             */
   };
        uint8_t   RESERVED_0[3];               
   union {                                      /**< 0000: (size=0001)                                                  */
      __O  uint8_t   UCSR;                      /**< 0004: Clock Select Register                                        */
      __I  uint8_t   USR;                       /**< 0004: Status Register                                              */
   };
        uint8_t   RESERVED_1[3];               
   __O  uint8_t   UCR;                          /**< 0008: Command                                                      */
        uint8_t   RESERVED_2[3];               
   union {                                      /**< 0000: (size=0001)                                                  */
      __I  uint8_t   URB;                       /**< 000C: Receive Buffers                                              */
      __O  uint8_t   UTB;                       /**< 000C: Transmit Buffers                                             */
   };
        uint8_t   RESERVED_3[3];               
   union {                                      /**< 0000: (size=0001)                                                  */
      __O  uint8_t   UACR;                      /**< 0010: Auxiliary Control Register                                   */
      __I  uint8_t   UIPCR;                     /**< 0010: Input Port Change Register                                   */
   };
        uint8_t   RESERVED_4[3];               
   union {                                      /**< 0000: (size=0001)                                                  */
      __O  uint8_t   UIMR;                      /**< 0014: Interrupt Mask Register                                      */
      __I  uint8_t   UISR;                      /**< 0014: Interrupt Status Register                                    */
   };
        uint8_t   RESERVED_5[3];               
   __O  uint8_t   UBG1;                         /**< 0018: Baud Rate Generator Register 1                               */
        uint8_t   RESERVED_6[3];               
   __O  uint8_t   UBG2;                         /**< 001C: Baud Rate Generator Register 2                               */
        uint8_t   RESERVED_7[23];              
   __I  uint8_t   UIP;                          /**< 0034: Input Port Register                                          */
        uint8_t   RESERVED_8[3];               
   __O  uint8_t   UOP1;                         /**< 0038: Port Bit Set Command Register                                */
        uint8_t   RESERVED_9[3];               
   __O  uint8_t   UOP0;                         /**< 003C: Port Bit Reset Command Register                              */
} UART_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- UMR1 Bit Fields                          ------ */
#define UART_UMR1_BC_MASK                        (0x3U)                                              /*!< UART0_UMR1: BC Mask                     */
#define UART_UMR1_BC_SHIFT                       (0U)                                                /*!< UART0_UMR1: BC Position                 */
#define UART_UMR1_BC(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR1_BC_SHIFT))&UART_UMR1_BC_MASK) /*!< UART0_UMR1                              */
#define UART_UMR1_PT_MASK                        (0x4U)                                              /*!< UART0_UMR1: PT Mask                     */
#define UART_UMR1_PT_SHIFT                       (2U)                                                /*!< UART0_UMR1: PT Position                 */
#define UART_UMR1_PT(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR1_PT_SHIFT))&UART_UMR1_PT_MASK) /*!< UART0_UMR1                              */
#define UART_UMR1_PM_MASK                        (0x18U)                                             /*!< UART0_UMR1: PM Mask                     */
#define UART_UMR1_PM_SHIFT                       (3U)                                                /*!< UART0_UMR1: PM Position                 */
#define UART_UMR1_PM(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR1_PM_SHIFT))&UART_UMR1_PM_MASK) /*!< UART0_UMR1                              */
#define UART_UMR1_ERR_MASK                       (0x20U)                                             /*!< UART0_UMR1: ERR Mask                    */
#define UART_UMR1_ERR_SHIFT                      (5U)                                                /*!< UART0_UMR1: ERR Position                */
#define UART_UMR1_ERR(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UMR1_ERR_SHIFT))&UART_UMR1_ERR_MASK) /*!< UART0_UMR1                              */
#define UART_UMR1_RXIRQ_MASK                     (0x40U)                                             /*!< UART0_UMR1: RXIRQ Mask                  */
#define UART_UMR1_RXIRQ_SHIFT                    (6U)                                                /*!< UART0_UMR1: RXIRQ Position              */
#define UART_UMR1_RXIRQ(x)                       (((uint8_t)(((uint8_t)(x))<<UART_UMR1_RXIRQ_SHIFT))&UART_UMR1_RXIRQ_MASK) /*!< UART0_UMR1                              */
#define UART_UMR1_RXRTS_MASK                     (0x80U)                                             /*!< UART0_UMR1: RXRTS Mask                  */
#define UART_UMR1_RXRTS_SHIFT                    (7U)                                                /*!< UART0_UMR1: RXRTS Position              */
#define UART_UMR1_RXRTS(x)                       (((uint8_t)(((uint8_t)(x))<<UART_UMR1_RXRTS_SHIFT))&UART_UMR1_RXRTS_MASK) /*!< UART0_UMR1                              */
/* ------- UMR2 Bit Fields                          ------ */
#define UART_UMR2_SB_MASK                        (0xFU)                                              /*!< UART0_UMR2: SB Mask                     */
#define UART_UMR2_SB_SHIFT                       (0U)                                                /*!< UART0_UMR2: SB Position                 */
#define UART_UMR2_SB(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR2_SB_SHIFT))&UART_UMR2_SB_MASK) /*!< UART0_UMR2                              */
#define UART_UMR2_TXCTS_MASK                     (0x10U)                                             /*!< UART0_UMR2: TXCTS Mask                  */
#define UART_UMR2_TXCTS_SHIFT                    (4U)                                                /*!< UART0_UMR2: TXCTS Position              */
#define UART_UMR2_TXCTS(x)                       (((uint8_t)(((uint8_t)(x))<<UART_UMR2_TXCTS_SHIFT))&UART_UMR2_TXCTS_MASK) /*!< UART0_UMR2                              */
#define UART_UMR2_TXRTS_MASK                     (0x20U)                                             /*!< UART0_UMR2: TXRTS Mask                  */
#define UART_UMR2_TXRTS_SHIFT                    (5U)                                                /*!< UART0_UMR2: TXRTS Position              */
#define UART_UMR2_TXRTS(x)                       (((uint8_t)(((uint8_t)(x))<<UART_UMR2_TXRTS_SHIFT))&UART_UMR2_TXRTS_MASK) /*!< UART0_UMR2                              */
#define UART_UMR2_CM_MASK                        (0xC0U)                                             /*!< UART0_UMR2: CM Mask                     */
#define UART_UMR2_CM_SHIFT                       (6U)                                                /*!< UART0_UMR2: CM Position                 */
#define UART_UMR2_CM(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UMR2_CM_SHIFT))&UART_UMR2_CM_MASK) /*!< UART0_UMR2                              */
/* ------- UCSR Bit Fields                          ------ */
#define UART_UCSR_TCS_MASK                       (0xFU)                                              /*!< UART0_UCSR: TCS Mask                    */
#define UART_UCSR_TCS_SHIFT                      (0U)                                                /*!< UART0_UCSR: TCS Position                */
#define UART_UCSR_TCS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UCSR_TCS_SHIFT))&UART_UCSR_TCS_MASK) /*!< UART0_UCSR                              */
#define UART_UCSR_RCS_MASK                       (0xF0U)                                             /*!< UART0_UCSR: RCS Mask                    */
#define UART_UCSR_RCS_SHIFT                      (4U)                                                /*!< UART0_UCSR: RCS Position                */
#define UART_UCSR_RCS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UCSR_RCS_SHIFT))&UART_UCSR_RCS_MASK) /*!< UART0_UCSR                              */
/* ------- USR Bit Fields                           ------ */
#define UART_USR_RXRDY_MASK                      (0x1U)                                              /*!< UART0_USR: RXRDY Mask                   */
#define UART_USR_RXRDY_SHIFT                     (0U)                                                /*!< UART0_USR: RXRDY Position               */
#define UART_USR_RXRDY(x)                        (((uint8_t)(((uint8_t)(x))<<UART_USR_RXRDY_SHIFT))&UART_USR_RXRDY_MASK) /*!< UART0_USR                               */
#define UART_USR_FFULL_MASK                      (0x2U)                                              /*!< UART0_USR: FFULL Mask                   */
#define UART_USR_FFULL_SHIFT                     (1U)                                                /*!< UART0_USR: FFULL Position               */
#define UART_USR_FFULL(x)                        (((uint8_t)(((uint8_t)(x))<<UART_USR_FFULL_SHIFT))&UART_USR_FFULL_MASK) /*!< UART0_USR                               */
#define UART_USR_TXRDY_MASK                      (0x4U)                                              /*!< UART0_USR: TXRDY Mask                   */
#define UART_USR_TXRDY_SHIFT                     (2U)                                                /*!< UART0_USR: TXRDY Position               */
#define UART_USR_TXRDY(x)                        (((uint8_t)(((uint8_t)(x))<<UART_USR_TXRDY_SHIFT))&UART_USR_TXRDY_MASK) /*!< UART0_USR                               */
#define UART_USR_TXEMP_MASK                      (0x8U)                                              /*!< UART0_USR: TXEMP Mask                   */
#define UART_USR_TXEMP_SHIFT                     (3U)                                                /*!< UART0_USR: TXEMP Position               */
#define UART_USR_TXEMP(x)                        (((uint8_t)(((uint8_t)(x))<<UART_USR_TXEMP_SHIFT))&UART_USR_TXEMP_MASK) /*!< UART0_USR                               */
#define UART_USR_OE_MASK                         (0x10U)                                             /*!< UART0_USR: OE Mask                      */
#define UART_USR_OE_SHIFT                        (4U)                                                /*!< UART0_USR: OE Position                  */
#define UART_USR_OE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_USR_OE_SHIFT))&UART_USR_OE_MASK) /*!< UART0_USR                               */
#define UART_USR_PE_MASK                         (0x20U)                                             /*!< UART0_USR: PE Mask                      */
#define UART_USR_PE_SHIFT                        (5U)                                                /*!< UART0_USR: PE Position                  */
#define UART_USR_PE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_USR_PE_SHIFT))&UART_USR_PE_MASK) /*!< UART0_USR                               */
#define UART_USR_FE_MASK                         (0x40U)                                             /*!< UART0_USR: FE Mask                      */
#define UART_USR_FE_SHIFT                        (6U)                                                /*!< UART0_USR: FE Position                  */
#define UART_USR_FE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_USR_FE_SHIFT))&UART_USR_FE_MASK) /*!< UART0_USR                               */
#define UART_USR_RB_MASK                         (0x80U)                                             /*!< UART0_USR: RB Mask                      */
#define UART_USR_RB_SHIFT                        (7U)                                                /*!< UART0_USR: RB Position                  */
#define UART_USR_RB(x)                           (((uint8_t)(((uint8_t)(x))<<UART_USR_RB_SHIFT))&UART_USR_RB_MASK) /*!< UART0_USR                               */
/* ------- UCR Bit Fields                           ------ */
#define UART_UCR_RC_MASK                         (0x3U)                                              /*!< UART0_UCR: RC Mask                      */
#define UART_UCR_RC_SHIFT                        (0U)                                                /*!< UART0_UCR: RC Position                  */
#define UART_UCR_RC(x)                           (((uint8_t)(((uint8_t)(x))<<UART_UCR_RC_SHIFT))&UART_UCR_RC_MASK) /*!< UART0_UCR                               */
#define UART_UCR_TC_MASK                         (0xCU)                                              /*!< UART0_UCR: TC Mask                      */
#define UART_UCR_TC_SHIFT                        (2U)                                                /*!< UART0_UCR: TC Position                  */
#define UART_UCR_TC(x)                           (((uint8_t)(((uint8_t)(x))<<UART_UCR_TC_SHIFT))&UART_UCR_TC_MASK) /*!< UART0_UCR                               */
#define UART_UCR_MISC_MASK                       (0x70U)                                             /*!< UART0_UCR: MISC Mask                    */
#define UART_UCR_MISC_SHIFT                      (4U)                                                /*!< UART0_UCR: MISC Position                */
#define UART_UCR_MISC(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UCR_MISC_SHIFT))&UART_UCR_MISC_MASK) /*!< UART0_UCR                               */
/* ------- URB Bit Fields                           ------ */
#define UART_URB_RB_MASK                         (0xFFU)                                             /*!< UART0_URB: RB Mask                      */
#define UART_URB_RB_SHIFT                        (0U)                                                /*!< UART0_URB: RB Position                  */
#define UART_URB_RB(x)                           (((uint8_t)(((uint8_t)(x))<<UART_URB_RB_SHIFT))&UART_URB_RB_MASK) /*!< UART0_URB                               */
/* ------- UTB Bit Fields                           ------ */
#define UART_UTB_TB_MASK                         (0xFFU)                                             /*!< UART0_UTB: TB Mask                      */
#define UART_UTB_TB_SHIFT                        (0U)                                                /*!< UART0_UTB: TB Position                  */
#define UART_UTB_TB(x)                           (((uint8_t)(((uint8_t)(x))<<UART_UTB_TB_SHIFT))&UART_UTB_TB_MASK) /*!< UART0_UTB                               */
/* ------- UACR Bit Fields                          ------ */
#define UART_UACR_IEC_MASK                       (0x1U)                                              /*!< UART0_UACR: IEC Mask                    */
#define UART_UACR_IEC_SHIFT                      (0U)                                                /*!< UART0_UACR: IEC Position                */
#define UART_UACR_IEC(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UACR_IEC_SHIFT))&UART_UACR_IEC_MASK) /*!< UART0_UACR                              */
/* ------- UIPCR Bit Fields                         ------ */
#define UART_UIPCR_CTS_MASK                      (0x1U)                                              /*!< UART0_UIPCR: CTS Mask                   */
#define UART_UIPCR_CTS_SHIFT                     (0U)                                                /*!< UART0_UIPCR: CTS Position               */
#define UART_UIPCR_CTS(x)                        (((uint8_t)(((uint8_t)(x))<<UART_UIPCR_CTS_SHIFT))&UART_UIPCR_CTS_MASK) /*!< UART0_UIPCR                             */
#define UART_UIPCR_COS_MASK                      (0x10U)                                             /*!< UART0_UIPCR: COS Mask                   */
#define UART_UIPCR_COS_SHIFT                     (4U)                                                /*!< UART0_UIPCR: COS Position               */
#define UART_UIPCR_COS(x)                        (((uint8_t)(((uint8_t)(x))<<UART_UIPCR_COS_SHIFT))&UART_UIPCR_COS_MASK) /*!< UART0_UIPCR                             */
/* ------- UIMR Bit Fields                          ------ */
#define UART_UIMR_TXRDY_MASK                     (0x1U)                                              /*!< UART0_UIMR: TXRDY Mask                  */
#define UART_UIMR_TXRDY_SHIFT                    (0U)                                                /*!< UART0_UIMR: TXRDY Position              */
#define UART_UIMR_TXRDY(x)                       (((uint8_t)(((uint8_t)(x))<<UART_UIMR_TXRDY_SHIFT))&UART_UIMR_TXRDY_MASK) /*!< UART0_UIMR                              */
#define UART_UIMR_FFULL_RXRDY_MASK               (0x2U)                                              /*!< UART0_UIMR: FFULL_RXRDY Mask            */
#define UART_UIMR_FFULL_RXRDY_SHIFT              (1U)                                                /*!< UART0_UIMR: FFULL_RXRDY Position        */
#define UART_UIMR_FFULL_RXRDY(x)                 (((uint8_t)(((uint8_t)(x))<<UART_UIMR_FFULL_RXRDY_SHIFT))&UART_UIMR_FFULL_RXRDY_MASK) /*!< UART0_UIMR                              */
#define UART_UIMR_DB_MASK                        (0x4U)                                              /*!< UART0_UIMR: DB Mask                     */
#define UART_UIMR_DB_SHIFT                       (2U)                                                /*!< UART0_UIMR: DB Position                 */
#define UART_UIMR_DB(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UIMR_DB_SHIFT))&UART_UIMR_DB_MASK) /*!< UART0_UIMR                              */
#define UART_UIMR_COS_MASK                       (0x80U)                                             /*!< UART0_UIMR: COS Mask                    */
#define UART_UIMR_COS_SHIFT                      (7U)                                                /*!< UART0_UIMR: COS Position                */
#define UART_UIMR_COS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UIMR_COS_SHIFT))&UART_UIMR_COS_MASK) /*!< UART0_UIMR                              */
/* ------- UISR Bit Fields                          ------ */
#define UART_UISR_TXRDY_MASK                     (0x1U)                                              /*!< UART0_UISR: TXRDY Mask                  */
#define UART_UISR_TXRDY_SHIFT                    (0U)                                                /*!< UART0_UISR: TXRDY Position              */
#define UART_UISR_TXRDY(x)                       (((uint8_t)(((uint8_t)(x))<<UART_UISR_TXRDY_SHIFT))&UART_UISR_TXRDY_MASK) /*!< UART0_UISR                              */
#define UART_UISR_FFULL_RXRDY_MASK               (0x2U)                                              /*!< UART0_UISR: FFULL_RXRDY Mask            */
#define UART_UISR_FFULL_RXRDY_SHIFT              (1U)                                                /*!< UART0_UISR: FFULL_RXRDY Position        */
#define UART_UISR_FFULL_RXRDY(x)                 (((uint8_t)(((uint8_t)(x))<<UART_UISR_FFULL_RXRDY_SHIFT))&UART_UISR_FFULL_RXRDY_MASK) /*!< UART0_UISR                              */
#define UART_UISR_DB_MASK                        (0x4U)                                              /*!< UART0_UISR: DB Mask                     */
#define UART_UISR_DB_SHIFT                       (2U)                                                /*!< UART0_UISR: DB Position                 */
#define UART_UISR_DB(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UISR_DB_SHIFT))&UART_UISR_DB_MASK) /*!< UART0_UISR                              */
#define UART_UISR_COS_MASK                       (0x80U)                                             /*!< UART0_UISR: COS Mask                    */
#define UART_UISR_COS_SHIFT                      (7U)                                                /*!< UART0_UISR: COS Position                */
#define UART_UISR_COS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UISR_COS_SHIFT))&UART_UISR_COS_MASK) /*!< UART0_UISR                              */
/* ------- UBG1 Bit Fields                          ------ */
#define UART_UBG1_Divider_MSB_MASK               (0xFFU)                                             /*!< UART0_UBG1: Divider_MSB Mask            */
#define UART_UBG1_Divider_MSB_SHIFT              (0U)                                                /*!< UART0_UBG1: Divider_MSB Position        */
#define UART_UBG1_Divider_MSB(x)                 (((uint8_t)(((uint8_t)(x))<<UART_UBG1_Divider_MSB_SHIFT))&UART_UBG1_Divider_MSB_MASK) /*!< UART0_UBG1                              */
/* ------- UBG2 Bit Fields                          ------ */
#define UART_UBG2_Divider_LSB_MASK               (0xFFU)                                             /*!< UART0_UBG2: Divider_LSB Mask            */
#define UART_UBG2_Divider_LSB_SHIFT              (0U)                                                /*!< UART0_UBG2: Divider_LSB Position        */
#define UART_UBG2_Divider_LSB(x)                 (((uint8_t)(((uint8_t)(x))<<UART_UBG2_Divider_LSB_SHIFT))&UART_UBG2_Divider_LSB_MASK) /*!< UART0_UBG2                              */
/* ------- UIP Bit Fields                           ------ */
#define UART_UIP_CTS_MASK                        (0x1U)                                              /*!< UART0_UIP: CTS Mask                     */
#define UART_UIP_CTS_SHIFT                       (0U)                                                /*!< UART0_UIP: CTS Position                 */
#define UART_UIP_CTS(x)                          (((uint8_t)(((uint8_t)(x))<<UART_UIP_CTS_SHIFT))&UART_UIP_CTS_MASK) /*!< UART0_UIP                               */
/* ------- UOP1 Bit Fields                          ------ */
#define UART_UOP1_RTS_MASK                       (0x1U)                                              /*!< UART0_UOP1: RTS Mask                    */
#define UART_UOP1_RTS_SHIFT                      (0U)                                                /*!< UART0_UOP1: RTS Position                */
#define UART_UOP1_RTS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UOP1_RTS_SHIFT))&UART_UOP1_RTS_MASK) /*!< UART0_UOP1                              */
/* ------- UOP0 Bit Fields                          ------ */
#define UART_UOP0_RTS_MASK                       (0x1U)                                              /*!< UART0_UOP0: RTS Mask                    */
#define UART_UOP0_RTS_SHIFT                      (0U)                                                /*!< UART0_UOP0: RTS Position                */
#define UART_UOP0_RTS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_UOP0_RTS_SHIFT))&UART_UOP0_RTS_MASK) /*!< UART0_UOP0                              */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x40000200UL //!< Peripheral base address
#define UART0                          ((UART_Type *) UART0_BasePtr) //!< Freescale base pointer
#define UART0_BASE_PTR                 (UART0) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART1 (derived from UART0)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Rx/Tx
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x40000240UL //!< Peripheral base address
#define UART1                          ((UART_Type *) UART1_BasePtr) //!< Freescale base pointer
#define UART1_BASE_PTR                 (UART1) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART2 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Rx/Tx
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x40000280UL //!< Peripheral base address
#define UART2                          ((UART_Type *) UART2_BasePtr) //!< Freescale base pointer
#define UART2_BASE_PTR                 (UART2) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
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
/**
 * @} */ /* End group Peripheral_access_layer_GROUP 
 */

#ifdef __cplusplus
}
#endif


#endif  /* MCU_MCF5223X */

