/****************************************************************************************************//**
 * @file     MCF5225x.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MCF5225x.
 *           Equivalent: 
 *
 * @version  V0.0
 * @date     2018/07
 *
 *******************************************************************************************************/

#ifndef MCU_MCF5225X
#define MCU_MCF5225X

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
/* ----------------------   MCF5225x VectorTable                     ---------------------- */
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
  RNGA_IRQn                     = 104,   /**< 104 RNGA interrupt                                                                   */
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
  USB_IRQn                      = 117,   /**< 117 USB interrupt                                                                    */
  PIT0_IRQn                     = 119,   /**< 119 PIT 0 interrupt                                                                  */
  PIT1_IRQn                     = 120,   /**< 120 PIT 1 interrupt                                                                  */
  CFM_CBEIF_IRQn                = 122,   /**< 122 CFM SGFM buffer empty                                                            */
  CFM_CCIF_IRQn                 = 123,   /**< 123 CFM SGFM command complete                                                        */
  CFM_PVIF_IRQn                 = 124,   /**< 124 CFM Protection violation                                                         */
  CFM_AEIF_IRQn                 = 125,   /**< 125 CFM Access error                                                                 */
  I2C1_IRQn                     = 126,   /**< 126 I2C1 interrupt                                                                   */
  RTC_IRQn                      = 127,   /**< 127 RTC interrupt                                                                    */
  FLEXCAN_BUF0I_IRQn            = 136,   /**< 136 FLEXCAN Message Buffer 0 Interrupt                                               */
  FLEXCAN_BUF1I_IRQn            = 137,   /**< 137 FLEXCAN Message Buffer 1 Interrupt                                               */
  FLEXCAN_BUF2I_IRQn            = 138,   /**< 138 FLEXCAN Message Buffer 2 Interrupt                                               */
  FLEXCAN_BUF3I_IRQn            = 139,   /**< 139 FLEXCAN Message Buffer 3 Interrupt                                               */
  FLEXCAN_BUF4I_IRQn            = 140,   /**< 140 FLEXCAN Message Buffer 4 Interrupt                                               */
  FLEXCAN_BUF5I_IRQn            = 141,   /**< 141 FLEXCAN Message Buffer 5 Interrupt                                               */
  FLEXCAN_BUF6I_IRQn            = 142,   /**< 142 FLEXCAN Message Buffer 6 Interrupt                                               */
  FLEXCAN_BUF7I_IRQn            = 143,   /**< 143 FLEXCAN Message Buffer 7 Interrupt                                               */
  FLEXCAN_BUF8I_IRQn            = 144,   /**< 144 FLEXCAN Message Buffer 8 Interrupt                                               */
  FLEXCAN_BUF9I_IRQn            = 145,   /**< 145 FLEXCAN Message Buffer 9 Interrupt                                               */
  FLEXCAN_BUF10I_IRQn           = 146,   /**< 146 FLEXCAN Message Buffer 10 Interrupt                                              */
  FLEXCAN_BUF11I_IRQn           = 147,   /**< 147 FLEXCAN Message Buffer 11 Interrupt                                              */
  FLEXCAN_BUF12I_IRQn           = 148,   /**< 148 FLEXCAN Message Buffer 12 Interrupt                                              */
  FLEXCAN_BUF13I_IRQn           = 149,   /**< 149 FLEXCAN Message Buffer 13 Interrupt                                              */
  FLEXCAN_BUF14I_IRQn           = 150,   /**< 150 FLEXCAN Message Buffer 14 Interrupt                                              */
  FLEXCAN_BUF15I_IRQn           = 151,   /**< 151 FLEXCAN Message Buffer 15 Interrupt                                              */
  FLEXCAN_Error_IRQn            = 152,   /**< 152 FLEXCAN  Error Interrupt                                                         */
  FLEXCAN_BOFF_IRQn             = 153,   /**< 153 FLEXCAN  Bus-Off Interrupt                                                       */
} IRQn_Type;

/* -------------------------  Exception Handlers  ------------------------ */
extern void AccessError_Handler(void);               /**< Access Error                                                                     */
extern void AddressError_Handler(void);              /**< Address Error                                                                    */
extern void IllegalInstruction_Handler(void);        /**< Illegal Instruction                                                              */
extern void DivideBy0_Handler(void);                 /**< Divide by Zero                                                                   */
extern void PrivilegeViolation_Handler(void);        /**< Privilege Violation                                                              */
extern void Trace_Handler(void);                     /**< Trace                                                                            */
extern void UnimplementedLineA_Handler(void);        /**< Unimplemented Line A                                                             */
extern void UnimplementedLineF_Handler(void);        /**< Unimplemented Line F                                                             */
extern void Debug_Handler(void);                     /**< Debug                                                                            */
extern void FormatError_Handler(void);               /**< Format Error                                                                     */
extern void SpuriousInt_Handler(void);               /**< Spurious Interrupt                                                               */
extern void Trap0_Handler(void);                     /**< Trap # 0                                                                         */
extern void Trap1_Handler(void);                     /**< Trap # 1                                                                         */
extern void Trap2_Handler(void);                     /**< Trap # 2                                                                         */
extern void Trap3_Handler(void);                     /**< Trap # 3                                                                         */
extern void Trap4_Handler(void);                     /**< Trap # 4                                                                         */
extern void Trap5_Handler(void);                     /**< Trap # 5                                                                         */
extern void Trap6_Handler(void);                     /**< Trap # 6                                                                         */
extern void Trap7_Handler(void);                     /**< Trap # 7                                                                         */
extern void Trap8_Handler(void);                     /**< Trap # 8                                                                         */
extern void Trap9_Handler(void);                     /**< Trap # 9                                                                         */
extern void Trap10_Handler(void);                    /**< Trap # 10                                                                        */
extern void Trap11_Handler(void);                    /**< Trap # 11                                                                        */
extern void Trap12_Handler(void);                    /**< Trap # 12                                                                        */
extern void Trap13_Handler(void);                    /**< Trap # 13                                                                        */
extern void Trap14_Handler(void);                    /**< Trap # 14                                                                        */
extern void Trap15_Handler(void);                    /**< Trap # 15                                                                        */
extern void EPORT1_IRQHandler(void);                 /**< Edge port flag 1                                                                 */
extern void EPORT2_IRQHandler(void);                 /**< Edge port flag 2                                                                 */
extern void EPORT3_IRQHandler(void);                 /**< Edge port flag 3                                                                 */
extern void EPORT4_IRQHandler(void);                 /**< Edge port flag 4                                                                 */
extern void EPORT5_IRQHandler(void);                 /**< Edge port flag 5                                                                 */
extern void EPORT6_IRQHandler(void);                 /**< Edge port flag 6                                                                 */
extern void EPORT7_IRQHandler(void);                 /**< Edge port flag 7                                                                 */
extern void SCM_IRQHandler(void);                    /**< Software watchdog timeout                                                        */
extern void DMA_CH0_IRQHandler(void);                /**< DMA Channel 0 transfer complete                                                  */
extern void DMA_CH1_IRQHandler(void);                /**< DMA Channel 1 transfer complete                                                  */
extern void DMA_CH2_IRQHandler(void);                /**< DMA Channel 2 transfer complete                                                  */
extern void DMA_CH3_IRQHandler(void);                /**< DMA Channel 3 transfer complete                                                  */
extern void UART0_IRQHandler(void);                  /**< UART 0 interrupt                                                                 */
extern void UART1_IRQHandler(void);                  /**< UART 1 interrupt                                                                 */
extern void UART2_IRQHandler(void);                  /**< UART 2 interrupt                                                                 */
extern void I2C_IRQHandler(void);                    /**< I2C interrupt                                                                    */
extern void QSPI_IRQHandler(void);                   /**< QSPI interrupt                                                                   */
extern void DTIM0_IRQHandler(void);                  /**< DMA Timer 0 interrupt                                                            */
extern void DTIM1_IRQHandler(void);                  /**< DMA Timer 1 interrupt                                                            */
extern void DTIM2_IRQHandler(void);                  /**< DMA Timer 2 interrupt                                                            */
extern void DTIM3_IRQHandler(void);                  /**< DMA Timer 3 interrupt                                                            */
extern void FEC_TF_IRQHandler(void);                 /**< Transmit frame interrupt                                                         */
extern void FEC_TB_IRQHandler(void);                 /**< Transmit buffer interrupt                                                        */
extern void FEC_UN_IRQHandler(void);                 /**< Transmit FIFO underrun                                                           */
extern void FEC_RL_IRQHandler(void);                 /**< Collision retry limit                                                            */
extern void FEC_RF_IRQHandler(void);                 /**< Receive frame interrupt                                                          */
extern void FEC_RB_IRQHandler(void);                 /**< Receive buffer interrupt                                                         */
extern void FEC_MII_IRQHandler(void);                /**< MII interrupt                                                                    */
extern void FEC_LC_IRQHandler(void);                 /**< Late Collision                                                                   */
extern void FEC_HBERR_IRQHandler(void);              /**< Heart-beat error                                                                 */
extern void FEC_GRA_IRQHandler(void);                /**< Graceful stop complete                                                           */
extern void FEC_EBERR_IRQHandler(void);              /**< Ethernet bus error                                                               */
extern void FEC_BABT_IRQHandler(void);               /**< Babbling transmit error                                                          */
extern void FEC_BABR_IRQHandler(void);               /**< Babbling receive error                                                           */
extern void RNGA_IRQHandler(void);                   /**< RNGA interrupt                                                                   */
extern void GPT_TOF_IRQHandler(void);                /**< GPT Timer overflow                                                               */
extern void GPT_PAIF_IRQHandler(void);               /**< GPT Pulse accumulator input                                                      */
extern void GPT_PAOVF_IRQHandler(void);              /**< GPT Pulse accumulator overflow                                                   */
extern void GPT_C0F_IRQHandler(void);                /**< GPT Timer channel 0                                                              */
extern void GPT_C1F_IRQHandler(void);                /**< GPT Timer channel 1                                                              */
extern void GPT_C2F_IRQHandler(void);                /**< GPT Timer channel 2                                                              */
extern void GPT_C3F_IRQHandler(void);                /**< GPT Timer channel 3                                                              */
extern void PMM_IRQHandler(void);                    /**< LVD                                                                              */
extern void ADC_ADCA_IRQHandler(void);               /**< ADCA conversion complete                                                         */
extern void ADC_ADCB_IRQHandler(void);               /**< ADCB conversion complete                                                         */
extern void ADC_ADCINT_IRQHandler(void);             /**< ADC Interrupt                                                                    */
extern void PWM_IRQHandler(void);                    /**< PWM interrupt                                                                    */
extern void USB_IRQHandler(void);                    /**< USB interrupt                                                                    */
extern void PIT0_IRQHandler(void);                   /**< PIT 0 interrupt                                                                  */
extern void PIT1_IRQHandler(void);                   /**< PIT 1 interrupt                                                                  */
extern void CFM_CBEIF_IRQHandler(void);              /**< CFM SGFM buffer empty                                                            */
extern void CFM_CCIF_IRQHandler(void);               /**< CFM SGFM command complete                                                        */
extern void CFM_PVIF_IRQHandler(void);               /**< CFM Protection violation                                                         */
extern void CFM_AEIF_IRQHandler(void);               /**< CFM Access error                                                                 */
extern void I2C1_IRQHandler(void);                   /**< I2C1 interrupt                                                                   */
extern void RTC_IRQHandler(void);                    /**< RTC interrupt                                                                    */
extern void FLEXCAN_BUF0I_IRQHandler(void);          /**< FLEXCAN Message Buffer 0 Interrupt                                               */
extern void FLEXCAN_BUF1I_IRQHandler(void);          /**< FLEXCAN Message Buffer 1 Interrupt                                               */
extern void FLEXCAN_BUF2I_IRQHandler(void);          /**< FLEXCAN Message Buffer 2 Interrupt                                               */
extern void FLEXCAN_BUF3I_IRQHandler(void);          /**< FLEXCAN Message Buffer 3 Interrupt                                               */
extern void FLEXCAN_BUF4I_IRQHandler(void);          /**< FLEXCAN Message Buffer 4 Interrupt                                               */
extern void FLEXCAN_BUF5I_IRQHandler(void);          /**< FLEXCAN Message Buffer 5 Interrupt                                               */
extern void FLEXCAN_BUF6I_IRQHandler(void);          /**< FLEXCAN Message Buffer 6 Interrupt                                               */
extern void FLEXCAN_BUF7I_IRQHandler(void);          /**< FLEXCAN Message Buffer 7 Interrupt                                               */
extern void FLEXCAN_BUF8I_IRQHandler(void);          /**< FLEXCAN Message Buffer 8 Interrupt                                               */
extern void FLEXCAN_BUF9I_IRQHandler(void);          /**< FLEXCAN Message Buffer 9 Interrupt                                               */
extern void FLEXCAN_BUF10I_IRQHandler(void);         /**< FLEXCAN Message Buffer 10 Interrupt                                              */
extern void FLEXCAN_BUF11I_IRQHandler(void);         /**< FLEXCAN Message Buffer 11 Interrupt                                              */
extern void FLEXCAN_BUF12I_IRQHandler(void);         /**< FLEXCAN Message Buffer 12 Interrupt                                              */
extern void FLEXCAN_BUF13I_IRQHandler(void);         /**< FLEXCAN Message Buffer 13 Interrupt                                              */
extern void FLEXCAN_BUF14I_IRQHandler(void);         /**< FLEXCAN Message Buffer 14 Interrupt                                              */
extern void FLEXCAN_BUF15I_IRQHandler(void);         /**< FLEXCAN Message Buffer 15 Interrupt                                              */
extern void FLEXCAN_Error_IRQHandler(void);          /**< FLEXCAN  Error Interrupt                                                         */
extern void FLEXCAN_BOFF_IRQHandler(void);           /**< FLEXCAN  Bus-Off Interrupt                                                       */

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
typedef struct ADC_Type {
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
#define ADC_CTRL1_SMODE_MASK                     (0x7U)                                              /*!< ADC_CTRL1.SMODE Mask                    */
#define ADC_CTRL1_SMODE_SHIFT                    (0U)                                                /*!< ADC_CTRL1.SMODE Position                */
#define ADC_CTRL1_SMODE(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x7UL)           /*!< ADC_CTRL1.SMODE Field                   */
#define ADC_CTRL1_CHNCFG0_MASK                   (0x10U)                                             /*!< ADC_CTRL1.CHNCFG0 Mask                  */
#define ADC_CTRL1_CHNCFG0_SHIFT                  (4U)                                                /*!< ADC_CTRL1.CHNCFG0 Position              */
#define ADC_CTRL1_CHNCFG0(x)                     (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< ADC_CTRL1.CHNCFG0 Field                 */
#define ADC_CTRL1_CHNCFG1_MASK                   (0x20U)                                             /*!< ADC_CTRL1.CHNCFG1 Mask                  */
#define ADC_CTRL1_CHNCFG1_SHIFT                  (5U)                                                /*!< ADC_CTRL1.CHNCFG1 Position              */
#define ADC_CTRL1_CHNCFG1(x)                     (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ADC_CTRL1.CHNCFG1 Field                 */
#define ADC_CTRL1_CHNCFG2_MASK                   (0x40U)                                             /*!< ADC_CTRL1.CHNCFG2 Mask                  */
#define ADC_CTRL1_CHNCFG2_SHIFT                  (6U)                                                /*!< ADC_CTRL1.CHNCFG2 Position              */
#define ADC_CTRL1_CHNCFG2(x)                     (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ADC_CTRL1.CHNCFG2 Field                 */
#define ADC_CTRL1_CHNCFG3_MASK                   (0x80U)                                             /*!< ADC_CTRL1.CHNCFG3 Mask                  */
#define ADC_CTRL1_CHNCFG3_SHIFT                  (7U)                                                /*!< ADC_CTRL1.CHNCFG3 Position              */
#define ADC_CTRL1_CHNCFG3(x)                     (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< ADC_CTRL1.CHNCFG3 Field                 */
#define ADC_CTRL1_HLMTIE_MASK                    (0x100U)                                            /*!< ADC_CTRL1.HLMTIE Mask                   */
#define ADC_CTRL1_HLMTIE_SHIFT                   (8U)                                                /*!< ADC_CTRL1.HLMTIE Position               */
#define ADC_CTRL1_HLMTIE(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< ADC_CTRL1.HLMTIE Field                  */
#define ADC_CTRL1_LLMTIE_MASK                    (0x200U)                                            /*!< ADC_CTRL1.LLMTIE Mask                   */
#define ADC_CTRL1_LLMTIE_SHIFT                   (9U)                                                /*!< ADC_CTRL1.LLMTIE Position               */
#define ADC_CTRL1_LLMTIE(x)                      (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< ADC_CTRL1.LLMTIE Field                  */
#define ADC_CTRL1_ZCIE_MASK                      (0x400U)                                            /*!< ADC_CTRL1.ZCIE Mask                     */
#define ADC_CTRL1_ZCIE_SHIFT                     (10U)                                               /*!< ADC_CTRL1.ZCIE Position                 */
#define ADC_CTRL1_ZCIE(x)                        (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ADC_CTRL1.ZCIE Field                    */
#define ADC_CTRL1_EOSIE0_MASK                    (0x800U)                                            /*!< ADC_CTRL1.EOSIE0 Mask                   */
#define ADC_CTRL1_EOSIE0_SHIFT                   (11U)                                               /*!< ADC_CTRL1.EOSIE0 Position               */
#define ADC_CTRL1_EOSIE0(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC_CTRL1.EOSIE0 Field                  */
#define ADC_CTRL1_SYNC0_MASK                     (0x1000U)                                           /*!< ADC_CTRL1.SYNC0 Mask                    */
#define ADC_CTRL1_SYNC0_SHIFT                    (12U)                                               /*!< ADC_CTRL1.SYNC0 Position                */
#define ADC_CTRL1_SYNC0(x)                       (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC_CTRL1.SYNC0 Field                   */
#define ADC_CTRL1_START0_MASK                    (0x2000U)                                           /*!< ADC_CTRL1.START0 Mask                   */
#define ADC_CTRL1_START0_SHIFT                   (13U)                                               /*!< ADC_CTRL1.START0 Position               */
#define ADC_CTRL1_START0(x)                      (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< ADC_CTRL1.START0 Field                  */
#define ADC_CTRL1_STOP0_MASK                     (0x4000U)                                           /*!< ADC_CTRL1.STOP0 Mask                    */
#define ADC_CTRL1_STOP0_SHIFT                    (14U)                                               /*!< ADC_CTRL1.STOP0 Position                */
#define ADC_CTRL1_STOP0(x)                       (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC_CTRL1.STOP0 Field                   */
/* ------- CTRL2 Bit Fields                         ------ */
#define ADC_CTRL2_DIV_MASK                       (0x1FU)                                             /*!< ADC_CTRL2.DIV Mask                      */
#define ADC_CTRL2_DIV_SHIFT                      (0U)                                                /*!< ADC_CTRL2.DIV Position                  */
#define ADC_CTRL2_DIV(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< ADC_CTRL2.DIV Field                     */
#define ADC_CTRL2_SIMULT_MASK                    (0x20U)                                             /*!< ADC_CTRL2.SIMULT Mask                   */
#define ADC_CTRL2_SIMULT_SHIFT                   (5U)                                                /*!< ADC_CTRL2.SIMULT Position               */
#define ADC_CTRL2_SIMULT(x)                      (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ADC_CTRL2.SIMULT Field                  */
#define ADC_CTRL2_EOSIE1_MASK                    (0x800U)                                            /*!< ADC_CTRL2.EOSIE1 Mask                   */
#define ADC_CTRL2_EOSIE1_SHIFT                   (11U)                                               /*!< ADC_CTRL2.EOSIE1 Position               */
#define ADC_CTRL2_EOSIE1(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC_CTRL2.EOSIE1 Field                  */
#define ADC_CTRL2_SYNC1_MASK                     (0x1000U)                                           /*!< ADC_CTRL2.SYNC1 Mask                    */
#define ADC_CTRL2_SYNC1_SHIFT                    (12U)                                               /*!< ADC_CTRL2.SYNC1 Position                */
#define ADC_CTRL2_SYNC1(x)                       (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC_CTRL2.SYNC1 Field                   */
#define ADC_CTRL2_START1_MASK                    (0x2000U)                                           /*!< ADC_CTRL2.START1 Mask                   */
#define ADC_CTRL2_START1_SHIFT                   (13U)                                               /*!< ADC_CTRL2.START1 Position               */
#define ADC_CTRL2_START1(x)                      (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< ADC_CTRL2.START1 Field                  */
#define ADC_CTRL2_STOP1_MASK                     (0x4000U)                                           /*!< ADC_CTRL2.STOP1 Mask                    */
#define ADC_CTRL2_STOP1_SHIFT                    (14U)                                               /*!< ADC_CTRL2.STOP1 Position                */
#define ADC_CTRL2_STOP1(x)                       (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC_CTRL2.STOP1 Field                   */
/* ------- ADZCC Bit Fields                         ------ */
#define ADC_ADZCC_ZCE0_MASK                      (0x3U)                                              /*!< ADC_ADZCC.ZCE0 Mask                     */
#define ADC_ADZCC_ZCE0_SHIFT                     (0U)                                                /*!< ADC_ADZCC.ZCE0 Position                 */
#define ADC_ADZCC_ZCE0(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< ADC_ADZCC.ZCE0 Field                    */
#define ADC_ADZCC_ZCE1_MASK                      (0xCU)                                              /*!< ADC_ADZCC.ZCE1 Mask                     */
#define ADC_ADZCC_ZCE1_SHIFT                     (2U)                                                /*!< ADC_ADZCC.ZCE1 Position                 */
#define ADC_ADZCC_ZCE1(x)                        (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< ADC_ADZCC.ZCE1 Field                    */
#define ADC_ADZCC_ZCE2_MASK                      (0x30U)                                             /*!< ADC_ADZCC.ZCE2 Mask                     */
#define ADC_ADZCC_ZCE2_SHIFT                     (4U)                                                /*!< ADC_ADZCC.ZCE2 Position                 */
#define ADC_ADZCC_ZCE2(x)                        (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< ADC_ADZCC.ZCE2 Field                    */
#define ADC_ADZCC_ZCE3_MASK                      (0xC0U)                                             /*!< ADC_ADZCC.ZCE3 Mask                     */
#define ADC_ADZCC_ZCE3_SHIFT                     (6U)                                                /*!< ADC_ADZCC.ZCE3 Position                 */
#define ADC_ADZCC_ZCE3(x)                        (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< ADC_ADZCC.ZCE3 Field                    */
#define ADC_ADZCC_ZCE4_MASK                      (0x300U)                                            /*!< ADC_ADZCC.ZCE4 Mask                     */
#define ADC_ADZCC_ZCE4_SHIFT                     (8U)                                                /*!< ADC_ADZCC.ZCE4 Position                 */
#define ADC_ADZCC_ZCE4(x)                        (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< ADC_ADZCC.ZCE4 Field                    */
#define ADC_ADZCC_ZCE5_MASK                      (0xC00U)                                            /*!< ADC_ADZCC.ZCE5 Mask                     */
#define ADC_ADZCC_ZCE5_SHIFT                     (10U)                                               /*!< ADC_ADZCC.ZCE5 Position                 */
#define ADC_ADZCC_ZCE5(x)                        (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< ADC_ADZCC.ZCE5 Field                    */
#define ADC_ADZCC_ZCE6_MASK                      (0x3000U)                                           /*!< ADC_ADZCC.ZCE6 Mask                     */
#define ADC_ADZCC_ZCE6_SHIFT                     (12U)                                               /*!< ADC_ADZCC.ZCE6 Position                 */
#define ADC_ADZCC_ZCE6(x)                        (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< ADC_ADZCC.ZCE6 Field                    */
#define ADC_ADZCC_ZCE7_MASK                      (0xC000U)                                           /*!< ADC_ADZCC.ZCE7 Mask                     */
#define ADC_ADZCC_ZCE7_SHIFT                     (14U)                                               /*!< ADC_ADZCC.ZCE7 Position                 */
#define ADC_ADZCC_ZCE7(x)                        (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< ADC_ADZCC.ZCE7 Field                    */
/* ------- ADLST1 Bit Fields                        ------ */
#define ADC_ADLST1_SAMPLE0_MASK                  (0x7U)                                              /*!< ADC_ADLST1.SAMPLE0 Mask                 */
#define ADC_ADLST1_SAMPLE0_SHIFT                 (0U)                                                /*!< ADC_ADLST1.SAMPLE0 Position             */
#define ADC_ADLST1_SAMPLE0(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0x7UL)           /*!< ADC_ADLST1.SAMPLE0 Field                */
#define ADC_ADLST1_SAMPLE1_MASK                  (0x70U)                                             /*!< ADC_ADLST1.SAMPLE1 Mask                 */
#define ADC_ADLST1_SAMPLE1_SHIFT                 (4U)                                                /*!< ADC_ADLST1.SAMPLE1 Position             */
#define ADC_ADLST1_SAMPLE1(x)                    (((uint16_t)(((uint16_t)(x))<<4U))&0x70UL)          /*!< ADC_ADLST1.SAMPLE1 Field                */
#define ADC_ADLST1_SAMPLE2_MASK                  (0x700U)                                            /*!< ADC_ADLST1.SAMPLE2 Mask                 */
#define ADC_ADLST1_SAMPLE2_SHIFT                 (8U)                                                /*!< ADC_ADLST1.SAMPLE2 Position             */
#define ADC_ADLST1_SAMPLE2(x)                    (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< ADC_ADLST1.SAMPLE2 Field                */
#define ADC_ADLST1_SAMPLE3_MASK                  (0x7000U)                                           /*!< ADC_ADLST1.SAMPLE3 Mask                 */
#define ADC_ADLST1_SAMPLE3_SHIFT                 (12U)                                               /*!< ADC_ADLST1.SAMPLE3 Position             */
#define ADC_ADLST1_SAMPLE3(x)                    (((uint16_t)(((uint16_t)(x))<<12U))&0x7000UL)       /*!< ADC_ADLST1.SAMPLE3 Field                */
/* ------- ADLST2 Bit Fields                        ------ */
#define ADC_ADLST2_SAMPLE4_MASK                  (0x7U)                                              /*!< ADC_ADLST2.SAMPLE4 Mask                 */
#define ADC_ADLST2_SAMPLE4_SHIFT                 (0U)                                                /*!< ADC_ADLST2.SAMPLE4 Position             */
#define ADC_ADLST2_SAMPLE4(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0x7UL)           /*!< ADC_ADLST2.SAMPLE4 Field                */
#define ADC_ADLST2_SAMPLE5_MASK                  (0x70U)                                             /*!< ADC_ADLST2.SAMPLE5 Mask                 */
#define ADC_ADLST2_SAMPLE5_SHIFT                 (4U)                                                /*!< ADC_ADLST2.SAMPLE5 Position             */
#define ADC_ADLST2_SAMPLE5(x)                    (((uint16_t)(((uint16_t)(x))<<4U))&0x70UL)          /*!< ADC_ADLST2.SAMPLE5 Field                */
#define ADC_ADLST2_SAMPLE6_MASK                  (0x700U)                                            /*!< ADC_ADLST2.SAMPLE6 Mask                 */
#define ADC_ADLST2_SAMPLE6_SHIFT                 (8U)                                                /*!< ADC_ADLST2.SAMPLE6 Position             */
#define ADC_ADLST2_SAMPLE6(x)                    (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< ADC_ADLST2.SAMPLE6 Field                */
#define ADC_ADLST2_SAMPLE7_MASK                  (0x7000U)                                           /*!< ADC_ADLST2.SAMPLE7 Mask                 */
#define ADC_ADLST2_SAMPLE7_SHIFT                 (12U)                                               /*!< ADC_ADLST2.SAMPLE7 Position             */
#define ADC_ADLST2_SAMPLE7(x)                    (((uint16_t)(((uint16_t)(x))<<12U))&0x7000UL)       /*!< ADC_ADLST2.SAMPLE7 Field                */
/* ------- ADSDIS Bit Fields                        ------ */
#define ADC_ADSDIS_DS0_MASK                      (0x1U)                                              /*!< ADC_ADSDIS.DS0 Mask                     */
#define ADC_ADSDIS_DS0_SHIFT                     (0U)                                                /*!< ADC_ADSDIS.DS0 Position                 */
#define ADC_ADSDIS_DS0(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ADC_ADSDIS.DS0 Field                    */
#define ADC_ADSDIS_DS1_MASK                      (0x2U)                                              /*!< ADC_ADSDIS.DS1 Mask                     */
#define ADC_ADSDIS_DS1_SHIFT                     (1U)                                                /*!< ADC_ADSDIS.DS1 Position                 */
#define ADC_ADSDIS_DS1(x)                        (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ADC_ADSDIS.DS1 Field                    */
#define ADC_ADSDIS_DS2_MASK                      (0x4U)                                              /*!< ADC_ADSDIS.DS2 Mask                     */
#define ADC_ADSDIS_DS2_SHIFT                     (2U)                                                /*!< ADC_ADSDIS.DS2 Position                 */
#define ADC_ADSDIS_DS2(x)                        (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< ADC_ADSDIS.DS2 Field                    */
#define ADC_ADSDIS_DS3_MASK                      (0x8U)                                              /*!< ADC_ADSDIS.DS3 Mask                     */
#define ADC_ADSDIS_DS3_SHIFT                     (3U)                                                /*!< ADC_ADSDIS.DS3 Position                 */
#define ADC_ADSDIS_DS3(x)                        (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ADC_ADSDIS.DS3 Field                    */
#define ADC_ADSDIS_DS4_MASK                      (0x10U)                                             /*!< ADC_ADSDIS.DS4 Mask                     */
#define ADC_ADSDIS_DS4_SHIFT                     (4U)                                                /*!< ADC_ADSDIS.DS4 Position                 */
#define ADC_ADSDIS_DS4(x)                        (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< ADC_ADSDIS.DS4 Field                    */
#define ADC_ADSDIS_DS5_MASK                      (0x20U)                                             /*!< ADC_ADSDIS.DS5 Mask                     */
#define ADC_ADSDIS_DS5_SHIFT                     (5U)                                                /*!< ADC_ADSDIS.DS5 Position                 */
#define ADC_ADSDIS_DS5(x)                        (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ADC_ADSDIS.DS5 Field                    */
#define ADC_ADSDIS_DS6_MASK                      (0x40U)                                             /*!< ADC_ADSDIS.DS6 Mask                     */
#define ADC_ADSDIS_DS6_SHIFT                     (6U)                                                /*!< ADC_ADSDIS.DS6 Position                 */
#define ADC_ADSDIS_DS6(x)                        (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ADC_ADSDIS.DS6 Field                    */
#define ADC_ADSDIS_DS7_MASK                      (0x80U)                                             /*!< ADC_ADSDIS.DS7 Mask                     */
#define ADC_ADSDIS_DS7_SHIFT                     (7U)                                                /*!< ADC_ADSDIS.DS7 Position                 */
#define ADC_ADSDIS_DS7(x)                        (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< ADC_ADSDIS.DS7 Field                    */
/* ------- ADSTAT Bit Fields                        ------ */
#define ADC_ADSTAT_RDY0_MASK                     (0x1U)                                              /*!< ADC_ADSTAT.RDY0 Mask                    */
#define ADC_ADSTAT_RDY0_SHIFT                    (0U)                                                /*!< ADC_ADSTAT.RDY0 Position                */
#define ADC_ADSTAT_RDY0(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ADC_ADSTAT.RDY0 Field                   */
#define ADC_ADSTAT_RDY1_MASK                     (0x2U)                                              /*!< ADC_ADSTAT.RDY1 Mask                    */
#define ADC_ADSTAT_RDY1_SHIFT                    (1U)                                                /*!< ADC_ADSTAT.RDY1 Position                */
#define ADC_ADSTAT_RDY1(x)                       (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ADC_ADSTAT.RDY1 Field                   */
#define ADC_ADSTAT_RDY2_MASK                     (0x4U)                                              /*!< ADC_ADSTAT.RDY2 Mask                    */
#define ADC_ADSTAT_RDY2_SHIFT                    (2U)                                                /*!< ADC_ADSTAT.RDY2 Position                */
#define ADC_ADSTAT_RDY2(x)                       (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< ADC_ADSTAT.RDY2 Field                   */
#define ADC_ADSTAT_RDY3_MASK                     (0x8U)                                              /*!< ADC_ADSTAT.RDY3 Mask                    */
#define ADC_ADSTAT_RDY3_SHIFT                    (3U)                                                /*!< ADC_ADSTAT.RDY3 Position                */
#define ADC_ADSTAT_RDY3(x)                       (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ADC_ADSTAT.RDY3 Field                   */
#define ADC_ADSTAT_RDY4_MASK                     (0x10U)                                             /*!< ADC_ADSTAT.RDY4 Mask                    */
#define ADC_ADSTAT_RDY4_SHIFT                    (4U)                                                /*!< ADC_ADSTAT.RDY4 Position                */
#define ADC_ADSTAT_RDY4(x)                       (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< ADC_ADSTAT.RDY4 Field                   */
#define ADC_ADSTAT_RDY5_MASK                     (0x20U)                                             /*!< ADC_ADSTAT.RDY5 Mask                    */
#define ADC_ADSTAT_RDY5_SHIFT                    (5U)                                                /*!< ADC_ADSTAT.RDY5 Position                */
#define ADC_ADSTAT_RDY5(x)                       (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ADC_ADSTAT.RDY5 Field                   */
#define ADC_ADSTAT_RDY6_MASK                     (0x40U)                                             /*!< ADC_ADSTAT.RDY6 Mask                    */
#define ADC_ADSTAT_RDY6_SHIFT                    (6U)                                                /*!< ADC_ADSTAT.RDY6 Position                */
#define ADC_ADSTAT_RDY6(x)                       (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ADC_ADSTAT.RDY6 Field                   */
#define ADC_ADSTAT_RDY7_MASK                     (0x80U)                                             /*!< ADC_ADSTAT.RDY7 Mask                    */
#define ADC_ADSTAT_RDY7_SHIFT                    (7U)                                                /*!< ADC_ADSTAT.RDY7 Position                */
#define ADC_ADSTAT_RDY7(x)                       (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< ADC_ADSTAT.RDY7 Field                   */
#define ADC_ADSTAT_HLMTI_MASK                    (0x100U)                                            /*!< ADC_ADSTAT.HLMTI Mask                   */
#define ADC_ADSTAT_HLMTI_SHIFT                   (8U)                                                /*!< ADC_ADSTAT.HLMTI Position               */
#define ADC_ADSTAT_HLMTI(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< ADC_ADSTAT.HLMTI Field                  */
#define ADC_ADSTAT_LLMTI_MASK                    (0x200U)                                            /*!< ADC_ADSTAT.LLMTI Mask                   */
#define ADC_ADSTAT_LLMTI_SHIFT                   (9U)                                                /*!< ADC_ADSTAT.LLMTI Position               */
#define ADC_ADSTAT_LLMTI(x)                      (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< ADC_ADSTAT.LLMTI Field                  */
#define ADC_ADSTAT_ZCI_MASK                      (0x400U)                                            /*!< ADC_ADSTAT.ZCI Mask                     */
#define ADC_ADSTAT_ZCI_SHIFT                     (10U)                                               /*!< ADC_ADSTAT.ZCI Position                 */
#define ADC_ADSTAT_ZCI(x)                        (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ADC_ADSTAT.ZCI Field                    */
#define ADC_ADSTAT_EOSI0_MASK                    (0x800U)                                            /*!< ADC_ADSTAT.EOSI0 Mask                   */
#define ADC_ADSTAT_EOSI0_SHIFT                   (11U)                                               /*!< ADC_ADSTAT.EOSI0 Position               */
#define ADC_ADSTAT_EOSI0(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC_ADSTAT.EOSI0 Field                  */
#define ADC_ADSTAT_EOSI1_MASK                    (0x1000U)                                           /*!< ADC_ADSTAT.EOSI1 Mask                   */
#define ADC_ADSTAT_EOSI1_SHIFT                   (12U)                                               /*!< ADC_ADSTAT.EOSI1 Position               */
#define ADC_ADSTAT_EOSI1(x)                      (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC_ADSTAT.EOSI1 Field                  */
#define ADC_ADSTAT_CIP1_MASK                     (0x4000U)                                           /*!< ADC_ADSTAT.CIP1 Mask                    */
#define ADC_ADSTAT_CIP1_SHIFT                    (14U)                                               /*!< ADC_ADSTAT.CIP1 Position                */
#define ADC_ADSTAT_CIP1(x)                       (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC_ADSTAT.CIP1 Field                   */
#define ADC_ADSTAT_CIP0_MASK                     (0x8000U)                                           /*!< ADC_ADSTAT.CIP0 Mask                    */
#define ADC_ADSTAT_CIP0_SHIFT                    (15U)                                               /*!< ADC_ADSTAT.CIP0 Position                */
#define ADC_ADSTAT_CIP0(x)                       (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC_ADSTAT.CIP0 Field                   */
/* ------- ADLSTAT Bit Fields                       ------ */
#define ADC_ADLSTAT_LLS0_MASK                    (0x1U)                                              /*!< ADC_ADLSTAT.LLS0 Mask                   */
#define ADC_ADLSTAT_LLS0_SHIFT                   (0U)                                                /*!< ADC_ADLSTAT.LLS0 Position               */
#define ADC_ADLSTAT_LLS0(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ADC_ADLSTAT.LLS0 Field                  */
#define ADC_ADLSTAT_LLS1_MASK                    (0x2U)                                              /*!< ADC_ADLSTAT.LLS1 Mask                   */
#define ADC_ADLSTAT_LLS1_SHIFT                   (1U)                                                /*!< ADC_ADLSTAT.LLS1 Position               */
#define ADC_ADLSTAT_LLS1(x)                      (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ADC_ADLSTAT.LLS1 Field                  */
#define ADC_ADLSTAT_LLS2_MASK                    (0x4U)                                              /*!< ADC_ADLSTAT.LLS2 Mask                   */
#define ADC_ADLSTAT_LLS2_SHIFT                   (2U)                                                /*!< ADC_ADLSTAT.LLS2 Position               */
#define ADC_ADLSTAT_LLS2(x)                      (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< ADC_ADLSTAT.LLS2 Field                  */
#define ADC_ADLSTAT_LLS3_MASK                    (0x8U)                                              /*!< ADC_ADLSTAT.LLS3 Mask                   */
#define ADC_ADLSTAT_LLS3_SHIFT                   (3U)                                                /*!< ADC_ADLSTAT.LLS3 Position               */
#define ADC_ADLSTAT_LLS3(x)                      (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ADC_ADLSTAT.LLS3 Field                  */
#define ADC_ADLSTAT_LLS4_MASK                    (0x10U)                                             /*!< ADC_ADLSTAT.LLS4 Mask                   */
#define ADC_ADLSTAT_LLS4_SHIFT                   (4U)                                                /*!< ADC_ADLSTAT.LLS4 Position               */
#define ADC_ADLSTAT_LLS4(x)                      (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< ADC_ADLSTAT.LLS4 Field                  */
#define ADC_ADLSTAT_LLS5_MASK                    (0x20U)                                             /*!< ADC_ADLSTAT.LLS5 Mask                   */
#define ADC_ADLSTAT_LLS5_SHIFT                   (5U)                                                /*!< ADC_ADLSTAT.LLS5 Position               */
#define ADC_ADLSTAT_LLS5(x)                      (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ADC_ADLSTAT.LLS5 Field                  */
#define ADC_ADLSTAT_LLS6_MASK                    (0x40U)                                             /*!< ADC_ADLSTAT.LLS6 Mask                   */
#define ADC_ADLSTAT_LLS6_SHIFT                   (6U)                                                /*!< ADC_ADLSTAT.LLS6 Position               */
#define ADC_ADLSTAT_LLS6(x)                      (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ADC_ADLSTAT.LLS6 Field                  */
#define ADC_ADLSTAT_LLS7_MASK                    (0x80U)                                             /*!< ADC_ADLSTAT.LLS7 Mask                   */
#define ADC_ADLSTAT_LLS7_SHIFT                   (7U)                                                /*!< ADC_ADLSTAT.LLS7 Position               */
#define ADC_ADLSTAT_LLS7(x)                      (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< ADC_ADLSTAT.LLS7 Field                  */
#define ADC_ADLSTAT_HLS0_MASK                    (0x100U)                                            /*!< ADC_ADLSTAT.HLS0 Mask                   */
#define ADC_ADLSTAT_HLS0_SHIFT                   (8U)                                                /*!< ADC_ADLSTAT.HLS0 Position               */
#define ADC_ADLSTAT_HLS0(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< ADC_ADLSTAT.HLS0 Field                  */
#define ADC_ADLSTAT_HLS1_MASK                    (0x200U)                                            /*!< ADC_ADLSTAT.HLS1 Mask                   */
#define ADC_ADLSTAT_HLS1_SHIFT                   (9U)                                                /*!< ADC_ADLSTAT.HLS1 Position               */
#define ADC_ADLSTAT_HLS1(x)                      (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< ADC_ADLSTAT.HLS1 Field                  */
#define ADC_ADLSTAT_HLS2_MASK                    (0x400U)                                            /*!< ADC_ADLSTAT.HLS2 Mask                   */
#define ADC_ADLSTAT_HLS2_SHIFT                   (10U)                                               /*!< ADC_ADLSTAT.HLS2 Position               */
#define ADC_ADLSTAT_HLS2(x)                      (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ADC_ADLSTAT.HLS2 Field                  */
#define ADC_ADLSTAT_HLS3_MASK                    (0x800U)                                            /*!< ADC_ADLSTAT.HLS3 Mask                   */
#define ADC_ADLSTAT_HLS3_SHIFT                   (11U)                                               /*!< ADC_ADLSTAT.HLS3 Position               */
#define ADC_ADLSTAT_HLS3(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC_ADLSTAT.HLS3 Field                  */
#define ADC_ADLSTAT_HLS4_MASK                    (0x1000U)                                           /*!< ADC_ADLSTAT.HLS4 Mask                   */
#define ADC_ADLSTAT_HLS4_SHIFT                   (12U)                                               /*!< ADC_ADLSTAT.HLS4 Position               */
#define ADC_ADLSTAT_HLS4(x)                      (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC_ADLSTAT.HLS4 Field                  */
#define ADC_ADLSTAT_HLS5_MASK                    (0x2000U)                                           /*!< ADC_ADLSTAT.HLS5 Mask                   */
#define ADC_ADLSTAT_HLS5_SHIFT                   (13U)                                               /*!< ADC_ADLSTAT.HLS5 Position               */
#define ADC_ADLSTAT_HLS5(x)                      (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< ADC_ADLSTAT.HLS5 Field                  */
#define ADC_ADLSTAT_HLS6_MASK                    (0x4000U)                                           /*!< ADC_ADLSTAT.HLS6 Mask                   */
#define ADC_ADLSTAT_HLS6_SHIFT                   (14U)                                               /*!< ADC_ADLSTAT.HLS6 Position               */
#define ADC_ADLSTAT_HLS6(x)                      (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC_ADLSTAT.HLS6 Field                  */
#define ADC_ADLSTAT_HLS7_MASK                    (0x8000U)                                           /*!< ADC_ADLSTAT.HLS7 Mask                   */
#define ADC_ADLSTAT_HLS7_SHIFT                   (15U)                                               /*!< ADC_ADLSTAT.HLS7 Position               */
#define ADC_ADLSTAT_HLS7(x)                      (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC_ADLSTAT.HLS7 Field                  */
/* ------- ADZCSTAT Bit Fields                      ------ */
#define ADC_ADZCSTAT_ZCS0_MASK                   (0x1U)                                              /*!< ADC_ADZCSTAT.ZCS0 Mask                  */
#define ADC_ADZCSTAT_ZCS0_SHIFT                  (0U)                                                /*!< ADC_ADZCSTAT.ZCS0 Position              */
#define ADC_ADZCSTAT_ZCS0(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ADC_ADZCSTAT.ZCS0 Field                 */
#define ADC_ADZCSTAT_ZCS1_MASK                   (0x2U)                                              /*!< ADC_ADZCSTAT.ZCS1 Mask                  */
#define ADC_ADZCSTAT_ZCS1_SHIFT                  (1U)                                                /*!< ADC_ADZCSTAT.ZCS1 Position              */
#define ADC_ADZCSTAT_ZCS1(x)                     (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ADC_ADZCSTAT.ZCS1 Field                 */
#define ADC_ADZCSTAT_ZCS2_MASK                   (0x4U)                                              /*!< ADC_ADZCSTAT.ZCS2 Mask                  */
#define ADC_ADZCSTAT_ZCS2_SHIFT                  (2U)                                                /*!< ADC_ADZCSTAT.ZCS2 Position              */
#define ADC_ADZCSTAT_ZCS2(x)                     (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< ADC_ADZCSTAT.ZCS2 Field                 */
#define ADC_ADZCSTAT_ZCS3_MASK                   (0x8U)                                              /*!< ADC_ADZCSTAT.ZCS3 Mask                  */
#define ADC_ADZCSTAT_ZCS3_SHIFT                  (3U)                                                /*!< ADC_ADZCSTAT.ZCS3 Position              */
#define ADC_ADZCSTAT_ZCS3(x)                     (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ADC_ADZCSTAT.ZCS3 Field                 */
#define ADC_ADZCSTAT_ZCS4_MASK                   (0x10U)                                             /*!< ADC_ADZCSTAT.ZCS4 Mask                  */
#define ADC_ADZCSTAT_ZCS4_SHIFT                  (4U)                                                /*!< ADC_ADZCSTAT.ZCS4 Position              */
#define ADC_ADZCSTAT_ZCS4(x)                     (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< ADC_ADZCSTAT.ZCS4 Field                 */
#define ADC_ADZCSTAT_ZCS5_MASK                   (0x20U)                                             /*!< ADC_ADZCSTAT.ZCS5 Mask                  */
#define ADC_ADZCSTAT_ZCS5_SHIFT                  (5U)                                                /*!< ADC_ADZCSTAT.ZCS5 Position              */
#define ADC_ADZCSTAT_ZCS5(x)                     (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ADC_ADZCSTAT.ZCS5 Field                 */
#define ADC_ADZCSTAT_ZCS6_MASK                   (0x40U)                                             /*!< ADC_ADZCSTAT.ZCS6 Mask                  */
#define ADC_ADZCSTAT_ZCS6_SHIFT                  (6U)                                                /*!< ADC_ADZCSTAT.ZCS6 Position              */
#define ADC_ADZCSTAT_ZCS6(x)                     (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ADC_ADZCSTAT.ZCS6 Field                 */
#define ADC_ADZCSTAT_ZCS7_MASK                   (0x80U)                                             /*!< ADC_ADZCSTAT.ZCS7 Mask                  */
#define ADC_ADZCSTAT_ZCS7_SHIFT                  (7U)                                                /*!< ADC_ADZCSTAT.ZCS7 Position              */
#define ADC_ADZCSTAT_ZCS7(x)                     (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< ADC_ADZCSTAT.ZCS7 Field                 */
/* ------- ADRSLT Bit Fields                        ------ */
#define ADC_ADRSLT_RSLT_MASK                     (0x7FF8U)                                           /*!< ADC_ADRSLT.RSLT Mask                    */
#define ADC_ADRSLT_RSLT_SHIFT                    (3U)                                                /*!< ADC_ADRSLT.RSLT Position                */
#define ADC_ADRSLT_RSLT(x)                       (((uint16_t)(((uint16_t)(x))<<3U))&0x7FF8UL)        /*!< ADC_ADRSLT.RSLT Field                   */
#define ADC_ADRSLT_SEXT_MASK                     (0x8000U)                                           /*!< ADC_ADRSLT.SEXT Mask                    */
#define ADC_ADRSLT_SEXT_SHIFT                    (15U)                                               /*!< ADC_ADRSLT.SEXT Position                */
#define ADC_ADRSLT_SEXT(x)                       (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC_ADRSLT.SEXT Field                   */
/* ------- ADLLMT Bit Fields                        ------ */
#define ADC_ADLLMT_LLMT_MASK                     (0x7FF8U)                                           /*!< ADC_ADLLMT.LLMT Mask                    */
#define ADC_ADLLMT_LLMT_SHIFT                    (3U)                                                /*!< ADC_ADLLMT.LLMT Position                */
#define ADC_ADLLMT_LLMT(x)                       (((uint16_t)(((uint16_t)(x))<<3U))&0x7FF8UL)        /*!< ADC_ADLLMT.LLMT Field                   */
/* ------- ADHLMT Bit Fields                        ------ */
#define ADC_ADHLMT_HLMT_MASK                     (0x7FF8U)                                           /*!< ADC_ADHLMT.HLMT Mask                    */
#define ADC_ADHLMT_HLMT_SHIFT                    (3U)                                                /*!< ADC_ADHLMT.HLMT Position                */
#define ADC_ADHLMT_HLMT(x)                       (((uint16_t)(((uint16_t)(x))<<3U))&0x7FF8UL)        /*!< ADC_ADHLMT.HLMT Field                   */
/* ------- ADOFS Bit Fields                         ------ */
#define ADC_ADOFS_OFFSET_MASK                    (0x7FF8U)                                           /*!< ADC_ADOFS.OFFSET Mask                   */
#define ADC_ADOFS_OFFSET_SHIFT                   (3U)                                                /*!< ADC_ADOFS.OFFSET Position               */
#define ADC_ADOFS_OFFSET(x)                      (((uint16_t)(((uint16_t)(x))<<3U))&0x7FF8UL)        /*!< ADC_ADOFS.OFFSET Field                  */
/* ------- POWER Bit Fields                         ------ */
#define ADC_POWER_PD0_MASK                       (0x1U)                                              /*!< ADC_POWER.PD0 Mask                      */
#define ADC_POWER_PD0_SHIFT                      (0U)                                                /*!< ADC_POWER.PD0 Position                  */
#define ADC_POWER_PD0(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ADC_POWER.PD0 Field                     */
#define ADC_POWER_PD1_MASK                       (0x2U)                                              /*!< ADC_POWER.PD1 Mask                      */
#define ADC_POWER_PD1_SHIFT                      (1U)                                                /*!< ADC_POWER.PD1 Position                  */
#define ADC_POWER_PD1(x)                         (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ADC_POWER.PD1 Field                     */
#define ADC_POWER_PD2_MASK                       (0x4U)                                              /*!< ADC_POWER.PD2 Mask                      */
#define ADC_POWER_PD2_SHIFT                      (2U)                                                /*!< ADC_POWER.PD2 Position                  */
#define ADC_POWER_PD2(x)                         (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< ADC_POWER.PD2 Field                     */
#define ADC_POWER_APD_MASK                       (0x8U)                                              /*!< ADC_POWER.APD Mask                      */
#define ADC_POWER_APD_SHIFT                      (3U)                                                /*!< ADC_POWER.APD Position                  */
#define ADC_POWER_APD(x)                         (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ADC_POWER.APD Field                     */
#define ADC_POWER_PUDELAY_MASK                   (0x3F0U)                                            /*!< ADC_POWER.PUDELAY Mask                  */
#define ADC_POWER_PUDELAY_SHIFT                  (4U)                                                /*!< ADC_POWER.PUDELAY Position              */
#define ADC_POWER_PUDELAY(x)                     (((uint16_t)(((uint16_t)(x))<<4U))&0x3F0UL)         /*!< ADC_POWER.PUDELAY Field                 */
#define ADC_POWER_PSTS0_MASK                     (0x400U)                                            /*!< ADC_POWER.PSTS0 Mask                    */
#define ADC_POWER_PSTS0_SHIFT                    (10U)                                               /*!< ADC_POWER.PSTS0 Position                */
#define ADC_POWER_PSTS0(x)                       (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ADC_POWER.PSTS0 Field                   */
#define ADC_POWER_PSTS1_MASK                     (0x800U)                                            /*!< ADC_POWER.PSTS1 Mask                    */
#define ADC_POWER_PSTS1_SHIFT                    (11U)                                               /*!< ADC_POWER.PSTS1 Position                */
#define ADC_POWER_PSTS1(x)                       (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC_POWER.PSTS1 Field                   */
#define ADC_POWER_PSTS2_MASK                     (0x1000U)                                           /*!< ADC_POWER.PSTS2 Mask                    */
#define ADC_POWER_PSTS2_SHIFT                    (12U)                                               /*!< ADC_POWER.PSTS2 Position                */
#define ADC_POWER_PSTS2(x)                       (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC_POWER.PSTS2 Field                   */
#define ADC_POWER_ASB_MASK                       (0x8000U)                                           /*!< ADC_POWER.ASB Mask                      */
#define ADC_POWER_ASB_SHIFT                      (15U)                                               /*!< ADC_POWER.ASB Position                  */
#define ADC_POWER_ASB(x)                         (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC_POWER.ASB Field                     */
/* ------- CAL Bit Fields                           ------ */
#define ADC_CAL_SEL_VREFL_MASK                   (0x4000U)                                           /*!< ADC_CAL.SEL_VREFL Mask                  */
#define ADC_CAL_SEL_VREFL_SHIFT                  (14U)                                               /*!< ADC_CAL.SEL_VREFL Position              */
#define ADC_CAL_SEL_VREFL(x)                     (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC_CAL.SEL_VREFL Field                 */
#define ADC_CAL_SEL_VREFH_MASK                   (0x8000U)                                           /*!< ADC_CAL.SEL_VREFH Mask                  */
#define ADC_CAL_SEL_VREFH_SHIFT                  (15U)                                               /*!< ADC_CAL.SEL_VREFH Position              */
#define ADC_CAL_SEL_VREFH(x)                     (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC_CAL.SEL_VREFH Field                 */
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
* @addtogroup BWT_Peripheral_access_layer_GROUP BWT Peripheral Access Layer
* @brief C Struct for BWT
* @{
*/

/* ================================================================================ */
/* ================           BWT (file:MCF52259_BWT)              ================ */
/* ================================================================================ */

/**
 * @brief Backup Watchdog Timer Module
 */
/**
* @addtogroup BWT_structs_GROUP BWT struct
* @brief Struct for BWT
* @{
*/
typedef struct BWT_Type {
   __IO uint16_t  WCR;                          /**< 0000: Backup Watchdog Timer Control Register                       */
   __IO uint16_t  WMR;                          /**< 0002: Backup Watchdog Timer Modulus Register                       */
   __I  uint16_t  WCNTR;                        /**< 0004: Backup Watchdog Timer Count Register                         */
   __IO uint16_t  WSR;                          /**< 0006: Backup Watchdog Timer Service Register                       */
} BWT_Type;

/**
 * @} */ /* End group BWT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'BWT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup BWT_Register_Masks_GROUP BWT Register Masks
* @brief Register Masks for BWT
* @{
*/
/* ------- WCR Bit Fields                           ------ */
#define BWT_WCR_EN_MASK                          (0x1U)                                              /*!< BWT_WCR.EN Mask                         */
#define BWT_WCR_EN_SHIFT                         (0U)                                                /*!< BWT_WCR.EN Position                     */
#define BWT_WCR_EN(x)                            (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< BWT_WCR.EN Field                        */
#define BWT_WCR_DBG_MASK                         (0x2U)                                              /*!< BWT_WCR.DBG Mask                        */
#define BWT_WCR_DBG_SHIFT                        (1U)                                                /*!< BWT_WCR.DBG Position                    */
#define BWT_WCR_DBG(x)                           (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< BWT_WCR.DBG Field                       */
#define BWT_WCR_DOZE_MASK                        (0x4U)                                              /*!< BWT_WCR.DOZE Mask                       */
#define BWT_WCR_DOZE_SHIFT                       (2U)                                                /*!< BWT_WCR.DOZE Position                   */
#define BWT_WCR_DOZE(x)                          (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< BWT_WCR.DOZE Field                      */
#define BWT_WCR_WAIT_MASK                        (0x8U)                                              /*!< BWT_WCR.WAIT Mask                       */
#define BWT_WCR_WAIT_SHIFT                       (3U)                                                /*!< BWT_WCR.WAIT Position                   */
#define BWT_WCR_WAIT(x)                          (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< BWT_WCR.WAIT Field                      */
#define BWT_WCR_STOP_MASK                        (0x10U)                                             /*!< BWT_WCR.STOP Mask                       */
#define BWT_WCR_STOP_SHIFT                       (4U)                                                /*!< BWT_WCR.STOP Position                   */
#define BWT_WCR_STOP(x)                          (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< BWT_WCR.STOP Field                      */
/* ------- WMR Bit Fields                           ------ */
#define BWT_WMR_WM_MASK                          (0xFFFFU)                                           /*!< BWT_WMR.WM Mask                         */
#define BWT_WMR_WM_SHIFT                         (0U)                                                /*!< BWT_WMR.WM Position                     */
#define BWT_WMR_WM(x)                            (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< BWT_WMR.WM Field                        */
/* ------- WCNTR Bit Fields                         ------ */
#define BWT_WCNTR_WC_MASK                        (0xFFFFU)                                           /*!< BWT_WCNTR.WC Mask                       */
#define BWT_WCNTR_WC_SHIFT                       (0U)                                                /*!< BWT_WCNTR.WC Position                   */
#define BWT_WCNTR_WC(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< BWT_WCNTR.WC Field                      */
/* ------- WSR Bit Fields                           ------ */
#define BWT_WSR_WS_MASK                          (0xFFFFU)                                           /*!< BWT_WSR.WS Mask                         */
#define BWT_WSR_WS_SHIFT                         (0U)                                                /*!< BWT_WSR.WS Position                     */
#define BWT_WSR_WS(x)                            (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< BWT_WSR.WS Field                        */
/**
 * @} */ /* End group BWT_Register_Masks_GROUP 
 */

/* BWT - Peripheral instance base addresses */
#define BWT_BasePtr                    0x40140000UL //!< Peripheral base address
#define BWT                            ((BWT_Type *) BWT_BasePtr) //!< Freescale base pointer
#define BWT_BASE_PTR                   (BWT) //!< Freescale style base pointer
/**
 * @} */ /* End group BWT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CANMB_Peripheral_access_layer_GROUP CANMB Peripheral Access Layer
* @brief C Struct for CANMB
* @{
*/

/* ================================================================================ */
/* ================           CANMB (file:MCF52259_CANMB)          ================ */
/* ================================================================================ */

/**
 * @brief FlexCAN Module
 */
/**
* @addtogroup CANMB_structs_GROUP CANMB struct
* @brief Struct for CANMB
* @{
*/
typedef struct CANMB_Type {
   struct {
      __IO uint8_t   CODE;                      /**< 0000: Message buffer code                                          */
      __IO uint8_t   CTRL;                      /**< 0001: Control values                                               */
      __IO uint16_t  TIME;                      /**< 0002: Free-running counter time stamp                              */
      __IO uint32_t  ID;                        /**< 0004: Standard and Extended IDs                                    */
      __IO uint8_t   DATA[8];                   /**< 0008: Transmit/Receive data buffer                                 */
   } MB[16];                                    /**< 0000: (cluster: size=0x0100, 256)                                  */
} CANMB_Type;

/**
 * @} */ /* End group CANMB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CANMB' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CANMB_Register_Masks_GROUP CANMB Register Masks
* @brief Register Masks for CANMB
* @{
*/
/* ------- CODE Bit Fields                          ------ */
#define CANMB_CODE_CODE_MASK                     (0xFU)                                              /*!< CANMB_CODE.CODE Mask                    */
#define CANMB_CODE_CODE_SHIFT                    (0U)                                                /*!< CANMB_CODE.CODE Position                */
#define CANMB_CODE_CODE(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< CANMB_CODE.CODE Field                   */
/* ------- CTRL Bit Fields                          ------ */
#define CANMB_CTRL_LENGTH_MASK                   (0xFU)                                              /*!< CANMB_CTRL.LENGTH Mask                  */
#define CANMB_CTRL_LENGTH_SHIFT                  (0U)                                                /*!< CANMB_CTRL.LENGTH Position              */
#define CANMB_CTRL_LENGTH(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< CANMB_CTRL.LENGTH Field                 */
#define CANMB_CTRL_RTR_MASK                      (0x10U)                                             /*!< CANMB_CTRL.RTR Mask                     */
#define CANMB_CTRL_RTR_SHIFT                     (4U)                                                /*!< CANMB_CTRL.RTR Position                 */
#define CANMB_CTRL_RTR(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CANMB_CTRL.RTR Field                    */
#define CANMB_CTRL_IDE_MASK                      (0x20U)                                             /*!< CANMB_CTRL.IDE Mask                     */
#define CANMB_CTRL_IDE_SHIFT                     (5U)                                                /*!< CANMB_CTRL.IDE Position                 */
#define CANMB_CTRL_IDE(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< CANMB_CTRL.IDE Field                    */
#define CANMB_CTRL_SRR_MASK                      (0x40U)                                             /*!< CANMB_CTRL.SRR Mask                     */
#define CANMB_CTRL_SRR_SHIFT                     (6U)                                                /*!< CANMB_CTRL.SRR Position                 */
#define CANMB_CTRL_SRR(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CANMB_CTRL.SRR Field                    */
/* ------- TIME Bit Fields                          ------ */
#define CANMB_TIME_TIME_STAMP_MASK               (0xFFFFU)                                           /*!< CANMB_TIME.TIME_STAMP Mask              */
#define CANMB_TIME_TIME_STAMP_SHIFT              (0U)                                                /*!< CANMB_TIME.TIME_STAMP Position          */
#define CANMB_TIME_TIME_STAMP(x)                 (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CANMB_TIME.TIME_STAMP Field             */
/* ------- ID Bit Fields                            ------ */
#define CANMB_ID_EXT_MASK                        (0x3FFFFU)                                          /*!< CANMB_ID.EXT Mask                       */
#define CANMB_ID_EXT_SHIFT                       (0U)                                                /*!< CANMB_ID.EXT Position                   */
#define CANMB_ID_EXT(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFUL)       /*!< CANMB_ID.EXT Field                      */
#define CANMB_ID_STD_MASK                        (0x1FFC0000U)                                       /*!< CANMB_ID.STD Mask                       */
#define CANMB_ID_STD_SHIFT                       (18U)                                               /*!< CANMB_ID.STD Position                   */
#define CANMB_ID_STD(x)                          (((uint32_t)(((uint32_t)(x))<<18U))&0x1FFC0000UL)   /*!< CANMB_ID.STD Field                      */
/* ------- DATA Bit Fields                          ------ */
/**
 * @} */ /* End group CANMB_Register_Masks_GROUP 
 */

/* CANMB - Peripheral instance base addresses */
#define CANMB_BasePtr                  0x40170080UL //!< Peripheral base address
#define CANMB                          ((CANMB_Type *) CANMB_BasePtr) //!< Freescale base pointer
#define CANMB_BASE_PTR                 (CANMB) //!< Freescale style base pointer
/**
 * @} */ /* End group CANMB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CCM_Peripheral_access_layer_GROUP CCM Peripheral Access Layer
* @brief C Struct for CCM
* @{
*/

/* ================================================================================ */
/* ================           CCM (file:MCF52259_CCM)              ================ */
/* ================================================================================ */

/**
 * @brief Chip Configuration Module
 */
/**
* @addtogroup CCM_structs_GROUP CCM struct
* @brief Struct for CCM
* @{
*/
typedef struct CCM_Type {
   __IO uint16_t  CCR;                          /**< 0000: Chip Configuration Register                                  */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   LPCR;                         /**< 0003: Low-Power Control Register                                   */
   __I  uint16_t  RCON;                         /**< 0004: Reset Configuration Register                                 */
   __I  uint16_t  CIR;                          /**< 0006: Chip Identification Register                                 */
        uint8_t   RESERVED_1[4];               
   __IO uint16_t  CCE;                          /**< 000C: Chip Identification Extended Register                        */
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
#define CCM_CCR_MODE_MASK                        (0x700U)                                            /*!< CCM_CCR.MODE Mask                       */
#define CCM_CCR_MODE_SHIFT                       (8U)                                                /*!< CCM_CCR.MODE Position                   */
#define CCM_CCR_MODE(x)                          (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< CCM_CCR.MODE Field                      */
#define CCM_CCR_LOAD_MASK                        (0x8000U)                                           /*!< CCM_CCR.LOAD Mask                       */
#define CCM_CCR_LOAD_SHIFT                       (15U)                                               /*!< CCM_CCR.LOAD Position                   */
#define CCM_CCR_LOAD(x)                          (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< CCM_CCR.LOAD Field                      */
/* ------- LPCR Bit Fields                          ------ */
#define CCM_LPCR_LVDSE_MASK                      (0x2U)                                              /*!< CCM_LPCR.LVDSE Mask                     */
#define CCM_LPCR_LVDSE_SHIFT                     (1U)                                                /*!< CCM_LPCR.LVDSE Position                 */
#define CCM_LPCR_LVDSE(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CCM_LPCR.LVDSE Field                    */
#define CCM_LPCR_STPMD_MASK                      (0x18U)                                             /*!< CCM_LPCR.STPMD Mask                     */
#define CCM_LPCR_STPMD_SHIFT                     (3U)                                                /*!< CCM_LPCR.STPMD Position                 */
#define CCM_LPCR_STPMD(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x18UL)            /*!< CCM_LPCR.STPMD Field                    */
#define CCM_LPCR_LPMD_MASK                       (0x40U)                                             /*!< CCM_LPCR.LPMD Mask                      */
#define CCM_LPCR_LPMD_SHIFT                      (6U)                                                /*!< CCM_LPCR.LPMD Position                  */
#define CCM_LPCR_LPMD(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CCM_LPCR.LPMD Field                     */
/* ------- RCON Bit Fields                          ------ */
#define CCM_RCON_RLOAD_MASK                      (0x20U)                                             /*!< CCM_RCON.RLOAD Mask                     */
#define CCM_RCON_RLOAD_SHIFT                     (5U)                                                /*!< CCM_RCON.RLOAD Position                 */
#define CCM_RCON_RLOAD(x)                        (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< CCM_RCON.RLOAD Field                    */
/* ------- CIR Bit Fields                           ------ */
#define CCM_CIR_PRN_MASK                         (0x3FU)                                             /*!< CCM_CIR.PRN Mask                        */
#define CCM_CIR_PRN_SHIFT                        (0U)                                                /*!< CCM_CIR.PRN Position                    */
#define CCM_CIR_PRN(x)                           (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< CCM_CIR.PRN Field                       */
#define CCM_CIR_PIN_MASK                         (0xFFC0U)                                           /*!< CCM_CIR.PIN Mask                        */
#define CCM_CIR_PIN_SHIFT                        (6U)                                                /*!< CCM_CIR.PIN Position                    */
#define CCM_CIR_PIN(x)                           (((uint16_t)(((uint16_t)(x))<<6U))&0xFFC0UL)        /*!< CCM_CIR.PIN Field                       */
/* ------- CCE Bit Fields                           ------ */
#define CCM_CCE_USBEND_MASK                      (0x4000U)                                           /*!< CCM_CCE.USBEND Mask                     */
#define CCM_CCE_USBEND_SHIFT                     (14U)                                               /*!< CCM_CCE.USBEND Position                 */
#define CCM_CCE_USBEND(x)                        (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< CCM_CCE.USBEND Field                    */
#define CCM_CCE_MBMOD_MASK                       (0x8000U)                                           /*!< CCM_CCE.MBMOD Mask                      */
#define CCM_CCE_MBMOD_SHIFT                      (15U)                                               /*!< CCM_CCE.MBMOD Position                  */
#define CCM_CCE_MBMOD(x)                         (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< CCM_CCE.MBMOD Field                     */
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
typedef struct CFM_Type {
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
#define CFM_CFMMCR_KEYACC_MASK                   (0x20U)                                             /*!< CFM_CFMMCR.KEYACC Mask                  */
#define CFM_CFMMCR_KEYACC_SHIFT                  (5U)                                                /*!< CFM_CFMMCR.KEYACC Position              */
#define CFM_CFMMCR_KEYACC(x)                     (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< CFM_CFMMCR.KEYACC Field                 */
#define CFM_CFMMCR_CCIE_MASK                     (0x40U)                                             /*!< CFM_CFMMCR.CCIE Mask                    */
#define CFM_CFMMCR_CCIE_SHIFT                    (6U)                                                /*!< CFM_CFMMCR.CCIE Position                */
#define CFM_CFMMCR_CCIE(x)                       (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< CFM_CFMMCR.CCIE Field                   */
#define CFM_CFMMCR_CBEIE_MASK                    (0x80U)                                             /*!< CFM_CFMMCR.CBEIE Mask                   */
#define CFM_CFMMCR_CBEIE_SHIFT                   (7U)                                                /*!< CFM_CFMMCR.CBEIE Position               */
#define CFM_CFMMCR_CBEIE(x)                      (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< CFM_CFMMCR.CBEIE Field                  */
#define CFM_CFMMCR_AEIE_MASK                     (0x100U)                                            /*!< CFM_CFMMCR.AEIE Mask                    */
#define CFM_CFMMCR_AEIE_SHIFT                    (8U)                                                /*!< CFM_CFMMCR.AEIE Position                */
#define CFM_CFMMCR_AEIE(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< CFM_CFMMCR.AEIE Field                   */
#define CFM_CFMMCR_PVIE_MASK                     (0x200U)                                            /*!< CFM_CFMMCR.PVIE Mask                    */
#define CFM_CFMMCR_PVIE_SHIFT                    (9U)                                                /*!< CFM_CFMMCR.PVIE Position                */
#define CFM_CFMMCR_PVIE(x)                       (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< CFM_CFMMCR.PVIE Field                   */
#define CFM_CFMMCR_LOCK_MASK                     (0x400U)                                            /*!< CFM_CFMMCR.LOCK Mask                    */
#define CFM_CFMMCR_LOCK_SHIFT                    (10U)                                               /*!< CFM_CFMMCR.LOCK Position                */
#define CFM_CFMMCR_LOCK(x)                       (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< CFM_CFMMCR.LOCK Field                   */
/* ------- CFMCLKD Bit Fields                       ------ */
#define CFM_CFMCLKD_DIV_MASK                     (0x3FU)                                             /*!< CFM_CFMCLKD.DIV Mask                    */
#define CFM_CFMCLKD_DIV_SHIFT                    (0U)                                                /*!< CFM_CFMCLKD.DIV Position                */
#define CFM_CFMCLKD_DIV(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< CFM_CFMCLKD.DIV Field                   */
#define CFM_CFMCLKD_PRDIV8_MASK                  (0x40U)                                             /*!< CFM_CFMCLKD.PRDIV8 Mask                 */
#define CFM_CFMCLKD_PRDIV8_SHIFT                 (6U)                                                /*!< CFM_CFMCLKD.PRDIV8 Position             */
#define CFM_CFMCLKD_PRDIV8(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CFM_CFMCLKD.PRDIV8 Field                */
#define CFM_CFMCLKD_DIVLD_MASK                   (0x80U)                                             /*!< CFM_CFMCLKD.DIVLD Mask                  */
#define CFM_CFMCLKD_DIVLD_SHIFT                  (7U)                                                /*!< CFM_CFMCLKD.DIVLD Position              */
#define CFM_CFMCLKD_DIVLD(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CFM_CFMCLKD.DIVLD Field                 */
/* ------- CFMSEC Bit Fields                        ------ */
#define CFM_CFMSEC_SEC_MASK                      (0xFFFFU)                                           /*!< CFM_CFMSEC.SEC Mask                     */
#define CFM_CFMSEC_SEC_SHIFT                     (0U)                                                /*!< CFM_CFMSEC.SEC Position                 */
#define CFM_CFMSEC_SEC(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CFM_CFMSEC.SEC Field                    */
#define CFM_CFMSEC_SECSTAT_MASK                  (0x40000000U)                                       /*!< CFM_CFMSEC.SECSTAT Mask                 */
#define CFM_CFMSEC_SECSTAT_SHIFT                 (30U)                                               /*!< CFM_CFMSEC.SECSTAT Position             */
#define CFM_CFMSEC_SECSTAT(x)                    (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< CFM_CFMSEC.SECSTAT Field                */
#define CFM_CFMSEC_KEYEN_MASK                    (0x80000000U)                                       /*!< CFM_CFMSEC.KEYEN Mask                   */
#define CFM_CFMSEC_KEYEN_SHIFT                   (31U)                                               /*!< CFM_CFMSEC.KEYEN Position               */
#define CFM_CFMSEC_KEYEN(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< CFM_CFMSEC.KEYEN Field                  */
/* ------- CFMPROT Bit Fields                       ------ */
#define CFM_CFMPROT_PROTECT_MASK                 (0xFFFFFFFFU)                                       /*!< CFM_CFMPROT.PROTECT Mask                */
#define CFM_CFMPROT_PROTECT_SHIFT                (0U)                                                /*!< CFM_CFMPROT.PROTECT Position            */
#define CFM_CFMPROT_PROTECT(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CFM_CFMPROT.PROTECT Field               */
/* ------- CFMSACC Bit Fields                       ------ */
#define CFM_CFMSACC_SUPV_MASK                    (0xFFFFFFFFU)                                       /*!< CFM_CFMSACC.SUPV Mask                   */
#define CFM_CFMSACC_SUPV_SHIFT                   (0U)                                                /*!< CFM_CFMSACC.SUPV Position               */
#define CFM_CFMSACC_SUPV(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CFM_CFMSACC.SUPV Field                  */
/* ------- CFMDACC Bit Fields                       ------ */
#define CFM_CFMDACC_DACC_MASK                    (0xFFFFFFFFU)                                       /*!< CFM_CFMDACC.DACC Mask                   */
#define CFM_CFMDACC_DACC_SHIFT                   (0U)                                                /*!< CFM_CFMDACC.DACC Position               */
#define CFM_CFMDACC_DACC(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CFM_CFMDACC.DACC Field                  */
/* ------- CFMUSTAT Bit Fields                      ------ */
#define CFM_CFMUSTAT_BLANK_MASK                  (0x4U)                                              /*!< CFM_CFMUSTAT.BLANK Mask                 */
#define CFM_CFMUSTAT_BLANK_SHIFT                 (2U)                                                /*!< CFM_CFMUSTAT.BLANK Position             */
#define CFM_CFMUSTAT_BLANK(x)                    (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CFM_CFMUSTAT.BLANK Field                */
#define CFM_CFMUSTAT_ACCERR_MASK                 (0x10U)                                             /*!< CFM_CFMUSTAT.ACCERR Mask                */
#define CFM_CFMUSTAT_ACCERR_SHIFT                (4U)                                                /*!< CFM_CFMUSTAT.ACCERR Position            */
#define CFM_CFMUSTAT_ACCERR(x)                   (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CFM_CFMUSTAT.ACCERR Field               */
#define CFM_CFMUSTAT_PVIOL_MASK                  (0x20U)                                             /*!< CFM_CFMUSTAT.PVIOL Mask                 */
#define CFM_CFMUSTAT_PVIOL_SHIFT                 (5U)                                                /*!< CFM_CFMUSTAT.PVIOL Position             */
#define CFM_CFMUSTAT_PVIOL(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< CFM_CFMUSTAT.PVIOL Field                */
#define CFM_CFMUSTAT_CCIF_MASK                   (0x40U)                                             /*!< CFM_CFMUSTAT.CCIF Mask                  */
#define CFM_CFMUSTAT_CCIF_SHIFT                  (6U)                                                /*!< CFM_CFMUSTAT.CCIF Position              */
#define CFM_CFMUSTAT_CCIF(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CFM_CFMUSTAT.CCIF Field                 */
#define CFM_CFMUSTAT_CBEIF_MASK                  (0x80U)                                             /*!< CFM_CFMUSTAT.CBEIF Mask                 */
#define CFM_CFMUSTAT_CBEIF_SHIFT                 (7U)                                                /*!< CFM_CFMUSTAT.CBEIF Position             */
#define CFM_CFMUSTAT_CBEIF(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CFM_CFMUSTAT.CBEIF Field                */
/* ------- CFMCMD Bit Fields                        ------ */
#define CFM_CFMCMD_CMD_MASK                      (0x7FU)                                             /*!< CFM_CFMCMD.CMD Mask                     */
#define CFM_CFMCMD_CMD_SHIFT                     (0U)                                                /*!< CFM_CFMCMD.CMD Position                 */
#define CFM_CFMCMD_CMD(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x7FUL)            /*!< CFM_CFMCMD.CMD Field                    */
/* ------- CFMCLKSEL Bit Fields                     ------ */
#define CFM_CFMCLKSEL_CLKSEL_MASK                (0x3U)                                              /*!< CFM_CFMCLKSEL.CLKSEL Mask               */
#define CFM_CFMCLKSEL_CLKSEL_SHIFT               (0U)                                                /*!< CFM_CFMCLKSEL.CLKSEL Position           */
#define CFM_CFMCLKSEL_CLKSEL(x)                  (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< CFM_CFMCLKSEL.CLKSEL Field              */
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
/* ================           CLOCK (file:MCF52259_CLOCK)          ================ */
/* ================================================================================ */

/**
 * @brief Clock Module
 */
/**
* @addtogroup CLOCK_structs_GROUP CLOCK struct
* @brief Struct for CLOCK
* @{
*/
typedef struct CLOCK_Type {
   __IO uint16_t  SYNCR;                        /**< 0000: Synthesizer Control Register                                 */
   __I  uint8_t   SYNSR;                        /**< 0002: Synthesiser Status Register                                  */
        uint8_t   RESERVED_0;                  
   __I  uint16_t  ROCR;                         /**< 0004: Relaxation Oscillator Control Register                       */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   LPCR;                         /**< 0007: Low Power Control Register                                   */
   __IO uint8_t   CCHR;                         /**< 0008: Clock Control High Register                                  */
   __IO uint8_t   CCLR;                         /**< 0009: Clock Control Low Register                                   */
   __IO uint8_t   OCHR;                         /**< 000A: Oscillator Control High Register                             */
   __IO uint8_t   OCLR;                         /**< 000B: Oscillator Control Low Register                              */
        uint8_t   RESERVED_2[6];               
   __IO uint8_t   RTCCR;                        /**< 0012: Real Time Clock Control Register                             */
   __IO uint8_t   BWCR;                         /**< 0013: Backup Watchdog Timer Control Register                       */
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
#define CLOCK_SYNCR_PLLEN_MASK                   (0x1U)                                              /*!< CLOCK_SYNCR.PLLEN Mask                  */
#define CLOCK_SYNCR_PLLEN_SHIFT                  (0U)                                                /*!< CLOCK_SYNCR.PLLEN Position              */
#define CLOCK_SYNCR_PLLEN(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< CLOCK_SYNCR.PLLEN Field                 */
#define CLOCK_SYNCR_PLLMODE_MASK                 (0x2U)                                              /*!< CLOCK_SYNCR.PLLMODE Mask                */
#define CLOCK_SYNCR_PLLMODE_SHIFT                (1U)                                                /*!< CLOCK_SYNCR.PLLMODE Position            */
#define CLOCK_SYNCR_PLLMODE(x)                   (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< CLOCK_SYNCR.PLLMODE Field               */
#define CLOCK_SYNCR_CLKSRC_MASK                  (0x4U)                                              /*!< CLOCK_SYNCR.CLKSRC Mask                 */
#define CLOCK_SYNCR_CLKSRC_SHIFT                 (2U)                                                /*!< CLOCK_SYNCR.CLKSRC Position             */
#define CLOCK_SYNCR_CLKSRC(x)                    (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< CLOCK_SYNCR.CLKSRC Field                */
#define CLOCK_SYNCR_FWKUP_MASK                   (0x20U)                                             /*!< CLOCK_SYNCR.FWKUP Mask                  */
#define CLOCK_SYNCR_FWKUP_SHIFT                  (5U)                                                /*!< CLOCK_SYNCR.FWKUP Position              */
#define CLOCK_SYNCR_FWKUP(x)                     (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< CLOCK_SYNCR.FWKUP Field                 */
#define CLOCK_SYNCR_DISCLK_MASK                  (0x40U)                                             /*!< CLOCK_SYNCR.DISCLK Mask                 */
#define CLOCK_SYNCR_DISCLK_SHIFT                 (6U)                                                /*!< CLOCK_SYNCR.DISCLK Position             */
#define CLOCK_SYNCR_DISCLK(x)                    (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< CLOCK_SYNCR.DISCLK Field                */
#define CLOCK_SYNCR_LOCEN_MASK                   (0x80U)                                             /*!< CLOCK_SYNCR.LOCEN Mask                  */
#define CLOCK_SYNCR_LOCEN_SHIFT                  (7U)                                                /*!< CLOCK_SYNCR.LOCEN Position              */
#define CLOCK_SYNCR_LOCEN(x)                     (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< CLOCK_SYNCR.LOCEN Field                 */
#define CLOCK_SYNCR_RFD_MASK                     (0x700U)                                            /*!< CLOCK_SYNCR.RFD Mask                    */
#define CLOCK_SYNCR_RFD_SHIFT                    (8U)                                                /*!< CLOCK_SYNCR.RFD Position                */
#define CLOCK_SYNCR_RFD(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< CLOCK_SYNCR.RFD Field                   */
#define CLOCK_SYNCR_LOCRE_MASK                   (0x800U)                                            /*!< CLOCK_SYNCR.LOCRE Mask                  */
#define CLOCK_SYNCR_LOCRE_SHIFT                  (11U)                                               /*!< CLOCK_SYNCR.LOCRE Position              */
#define CLOCK_SYNCR_LOCRE(x)                     (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< CLOCK_SYNCR.LOCRE Field                 */
#define CLOCK_SYNCR_MFD_MASK                     (0x7000U)                                           /*!< CLOCK_SYNCR.MFD Mask                    */
#define CLOCK_SYNCR_MFD_SHIFT                    (12U)                                               /*!< CLOCK_SYNCR.MFD Position                */
#define CLOCK_SYNCR_MFD(x)                       (((uint16_t)(((uint16_t)(x))<<12U))&0x7000UL)       /*!< CLOCK_SYNCR.MFD Field                   */
#define CLOCK_SYNCR_LOLRE_MASK                   (0x8000U)                                           /*!< CLOCK_SYNCR.LOLRE Mask                  */
#define CLOCK_SYNCR_LOLRE_SHIFT                  (15U)                                               /*!< CLOCK_SYNCR.LOLRE Position              */
#define CLOCK_SYNCR_LOLRE(x)                     (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< CLOCK_SYNCR.LOLRE Field                 */
/* ------- SYNSR Bit Fields                         ------ */
#define CLOCK_SYNSR_LOCS_MASK                    (0x4U)                                              /*!< CLOCK_SYNSR.LOCS Mask                   */
#define CLOCK_SYNSR_LOCS_SHIFT                   (2U)                                                /*!< CLOCK_SYNSR.LOCS Position               */
#define CLOCK_SYNSR_LOCS(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CLOCK_SYNSR.LOCS Field                  */
#define CLOCK_SYNSR_LOCK_MASK                    (0x8U)                                              /*!< CLOCK_SYNSR.LOCK Mask                   */
#define CLOCK_SYNSR_LOCK_SHIFT                   (3U)                                                /*!< CLOCK_SYNSR.LOCK Position               */
#define CLOCK_SYNSR_LOCK(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< CLOCK_SYNSR.LOCK Field                  */
#define CLOCK_SYNSR_LOCKS_MASK                   (0x10U)                                             /*!< CLOCK_SYNSR.LOCKS Mask                  */
#define CLOCK_SYNSR_LOCKS_SHIFT                  (4U)                                                /*!< CLOCK_SYNSR.LOCKS Position              */
#define CLOCK_SYNSR_LOCKS(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CLOCK_SYNSR.LOCKS Field                 */
#define CLOCK_SYNSR_CRYOSC_MASK                  (0x20U)                                             /*!< CLOCK_SYNSR.CRYOSC Mask                 */
#define CLOCK_SYNSR_CRYOSC_SHIFT                 (5U)                                                /*!< CLOCK_SYNSR.CRYOSC Position             */
#define CLOCK_SYNSR_CRYOSC(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< CLOCK_SYNSR.CRYOSC Field                */
#define CLOCK_SYNSR_OCOSC_MASK                   (0x40U)                                             /*!< CLOCK_SYNSR.OCOSC Mask                  */
#define CLOCK_SYNSR_OCOSC_SHIFT                  (6U)                                                /*!< CLOCK_SYNSR.OCOSC Position              */
#define CLOCK_SYNSR_OCOSC(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CLOCK_SYNSR.OCOSC Field                 */
#define CLOCK_SYNSR_EXTOSC_MASK                  (0x80U)                                             /*!< CLOCK_SYNSR.EXTOSC Mask                 */
#define CLOCK_SYNSR_EXTOSC_SHIFT                 (7U)                                                /*!< CLOCK_SYNSR.EXTOSC Position             */
#define CLOCK_SYNSR_EXTOSC(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CLOCK_SYNSR.EXTOSC Field                */
/* ------- ROCR Bit Fields                          ------ */
#define CLOCK_ROCR_TRIM_MASK                     (0x3FFU)                                            /*!< CLOCK_ROCR.TRIM Mask                    */
#define CLOCK_ROCR_TRIM_SHIFT                    (0U)                                                /*!< CLOCK_ROCR.TRIM Position                */
#define CLOCK_ROCR_TRIM(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x3FFUL)         /*!< CLOCK_ROCR.TRIM Field                   */
/* ------- LPCR Bit Fields                          ------ */
#define CLOCK_LPCR_LPD_MASK                      (0xFU)                                              /*!< CLOCK_LPCR.LPD Mask                     */
#define CLOCK_LPCR_LPD_SHIFT                     (0U)                                                /*!< CLOCK_LPCR.LPD Position                 */
#define CLOCK_LPCR_LPD(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< CLOCK_LPCR.LPD Field                    */
/* ------- CCHR Bit Fields                          ------ */
#define CLOCK_CCHR_CCHR_MASK                     (0x7U)                                              /*!< CLOCK_CCHR.CCHR Mask                    */
#define CLOCK_CCHR_CCHR_SHIFT                    (0U)                                                /*!< CLOCK_CCHR.CCHR Position                */
#define CLOCK_CCHR_CCHR(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< CLOCK_CCHR.CCHR Field                   */
/* ------- CCLR Bit Fields                          ------ */
#define CLOCK_CCLR_OSCSEL0_MASK                  (0x3U)                                              /*!< CLOCK_CCLR.OSCSEL0 Mask                 */
#define CLOCK_CCLR_OSCSEL0_SHIFT                 (0U)                                                /*!< CLOCK_CCLR.OSCSEL0 Position             */
#define CLOCK_CCLR_OSCSEL0(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< CLOCK_CCLR.OSCSEL0 Field                */
/* ------- OCHR Bit Fields                          ------ */
#define CLOCK_OCHR_STBY_MASK                     (0x40U)                                             /*!< CLOCK_OCHR.STBY Mask                    */
#define CLOCK_OCHR_STBY_SHIFT                    (6U)                                                /*!< CLOCK_OCHR.STBY Position                */
#define CLOCK_OCHR_STBY(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CLOCK_OCHR.STBY Field                   */
#define CLOCK_OCHR_OCOEN_MASK                    (0x80U)                                             /*!< CLOCK_OCHR.OCOEN Mask                   */
#define CLOCK_OCHR_OCOEN_SHIFT                   (7U)                                                /*!< CLOCK_OCHR.OCOEN Position               */
#define CLOCK_OCHR_OCOEN(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CLOCK_OCHR.OCOEN Field                  */
/* ------- OCLR Bit Fields                          ------ */
#define CLOCK_OCLR_RANGE_MASK                    (0x10U)                                             /*!< CLOCK_OCLR.RANGE Mask                   */
#define CLOCK_OCLR_RANGE_SHIFT                   (4U)                                                /*!< CLOCK_OCLR.RANGE Position               */
#define CLOCK_OCLR_RANGE(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CLOCK_OCLR.RANGE Field                  */
#define CLOCK_OCLR_LPEN_MASK                     (0x20U)                                             /*!< CLOCK_OCLR.LPEN Mask                    */
#define CLOCK_OCLR_LPEN_SHIFT                    (5U)                                                /*!< CLOCK_OCLR.LPEN Position                */
#define CLOCK_OCLR_LPEN(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< CLOCK_OCLR.LPEN Field                   */
#define CLOCK_OCLR_REFS_MASK                     (0x40U)                                             /*!< CLOCK_OCLR.REFS Mask                    */
#define CLOCK_OCLR_REFS_SHIFT                    (6U)                                                /*!< CLOCK_OCLR.REFS Position                */
#define CLOCK_OCLR_REFS(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CLOCK_OCLR.REFS Field                   */
#define CLOCK_OCLR_OSCEN_MASK                    (0x80U)                                             /*!< CLOCK_OCLR.OSCEN Mask                   */
#define CLOCK_OCLR_OSCEN_SHIFT                   (7U)                                                /*!< CLOCK_OCLR.OSCEN Position               */
#define CLOCK_OCLR_OSCEN(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CLOCK_OCLR.OSCEN Field                  */
/* ------- RTCCR Bit Fields                         ------ */
#define CLOCK_RTCCR_RTCSEL_MASK                  (0x1U)                                              /*!< CLOCK_RTCCR.RTCSEL Mask                 */
#define CLOCK_RTCCR_RTCSEL_SHIFT                 (0U)                                                /*!< CLOCK_RTCCR.RTCSEL Position             */
#define CLOCK_RTCCR_RTCSEL(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< CLOCK_RTCCR.RTCSEL Field                */
#define CLOCK_RTCCR_LPEN_MASK                    (0x2U)                                              /*!< CLOCK_RTCCR.LPEN Mask                   */
#define CLOCK_RTCCR_LPEN_SHIFT                   (1U)                                                /*!< CLOCK_RTCCR.LPEN Position               */
#define CLOCK_RTCCR_LPEN(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CLOCK_RTCCR.LPEN Field                  */
#define CLOCK_RTCCR_REFS_MASK                    (0x4U)                                              /*!< CLOCK_RTCCR.REFS Mask                   */
#define CLOCK_RTCCR_REFS_SHIFT                   (2U)                                                /*!< CLOCK_RTCCR.REFS Position               */
#define CLOCK_RTCCR_REFS(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CLOCK_RTCCR.REFS Field                  */
#define CLOCK_RTCCR_KHZEN_MASK                   (0x8U)                                              /*!< CLOCK_RTCCR.KHZEN Mask                  */
#define CLOCK_RTCCR_KHZEN_SHIFT                  (3U)                                                /*!< CLOCK_RTCCR.KHZEN Position              */
#define CLOCK_RTCCR_KHZEN(x)                     (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< CLOCK_RTCCR.KHZEN Field                 */
#define CLOCK_RTCCR_OSCEN_MASK                   (0x10U)                                             /*!< CLOCK_RTCCR.OSCEN Mask                  */
#define CLOCK_RTCCR_OSCEN_SHIFT                  (4U)                                                /*!< CLOCK_RTCCR.OSCEN Position              */
#define CLOCK_RTCCR_OSCEN(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CLOCK_RTCCR.OSCEN Field                 */
#define CLOCK_RTCCR_EXTALEN_MASK                 (0x40U)                                             /*!< CLOCK_RTCCR.EXTALEN Mask                */
#define CLOCK_RTCCR_EXTALEN_SHIFT                (6U)                                                /*!< CLOCK_RTCCR.EXTALEN Position            */
#define CLOCK_RTCCR_EXTALEN(x)                   (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CLOCK_RTCCR.EXTALEN Field               */
/* ------- BWCR Bit Fields                          ------ */
#define CLOCK_BWCR_BWDSEL_MASK                   (0x1U)                                              /*!< CLOCK_BWCR.BWDSEL Mask                  */
#define CLOCK_BWCR_BWDSEL_SHIFT                  (0U)                                                /*!< CLOCK_BWCR.BWDSEL Position              */
#define CLOCK_BWCR_BWDSEL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< CLOCK_BWCR.BWDSEL Field                 */
#define CLOCK_BWCR_BWDSTOP_MASK                  (0x2U)                                              /*!< CLOCK_BWCR.BWDSTOP Mask                 */
#define CLOCK_BWCR_BWDSTOP_SHIFT                 (1U)                                                /*!< CLOCK_BWCR.BWDSTOP Position             */
#define CLOCK_BWCR_BWDSTOP(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CLOCK_BWCR.BWDSTOP Field                */
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
typedef struct DMA_Type {
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
#define DMA_SAR_SAR_MASK                         (0xFFFFFFFFU)                                       /*!< DMA_SAR.SAR Mask                        */
#define DMA_SAR_SAR_SHIFT                        (0U)                                                /*!< DMA_SAR.SAR Position                    */
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA_SAR.SAR Field                       */
/* ------- DAR Bit Fields                           ------ */
#define DMA_DAR_DAR_MASK                         (0xFFFFFFFFU)                                       /*!< DMA_DAR.DAR Mask                        */
#define DMA_DAR_DAR_SHIFT                        (0U)                                                /*!< DMA_DAR.DAR Position                    */
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA_DAR.DAR Field                       */
/* ------- BCR Bit Fields                           ------ */
#define DMA_BCR_BCR_MASK                         (0xFFFFFFU)                                         /*!< DMA_BCR.BCR Mask                        */
#define DMA_BCR_BCR_SHIFT                        (0U)                                                /*!< DMA_BCR.BCR Position                    */
#define DMA_BCR_BCR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< DMA_BCR.BCR Field                       */
#define DMA_BCR_DSR_MASK                         (0xFF000000U)                                       /*!< DMA_BCR.DSR Mask                        */
#define DMA_BCR_DSR_SHIFT                        (24U)                                               /*!< DMA_BCR.DSR Position                    */
#define DMA_BCR_DSR(x)                           (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< DMA_BCR.DSR Field                       */
/* ------- DSR Bit Fields                           ------ */
#define DMA_DSR_DONE_MASK                        (0x1U)                                              /*!< DMA_DSR.DONE Mask                       */
#define DMA_DSR_DONE_SHIFT                       (0U)                                                /*!< DMA_DSR.DONE Position                   */
#define DMA_DSR_DONE(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< DMA_DSR.DONE Field                      */
#define DMA_DSR_BSY_MASK                         (0x2U)                                              /*!< DMA_DSR.BSY Mask                        */
#define DMA_DSR_BSY_SHIFT                        (1U)                                                /*!< DMA_DSR.BSY Position                    */
#define DMA_DSR_BSY(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< DMA_DSR.BSY Field                       */
#define DMA_DSR_REQ_MASK                         (0x4U)                                              /*!< DMA_DSR.REQ Mask                        */
#define DMA_DSR_REQ_SHIFT                        (2U)                                                /*!< DMA_DSR.REQ Position                    */
#define DMA_DSR_REQ(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< DMA_DSR.REQ Field                       */
#define DMA_DSR_BED_MASK                         (0x10U)                                             /*!< DMA_DSR.BED Mask                        */
#define DMA_DSR_BED_SHIFT                        (4U)                                                /*!< DMA_DSR.BED Position                    */
#define DMA_DSR_BED(x)                           (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< DMA_DSR.BED Field                       */
#define DMA_DSR_BES_MASK                         (0x20U)                                             /*!< DMA_DSR.BES Mask                        */
#define DMA_DSR_BES_SHIFT                        (5U)                                                /*!< DMA_DSR.BES Position                    */
#define DMA_DSR_BES(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< DMA_DSR.BES Field                       */
#define DMA_DSR_CE_MASK                          (0x40U)                                             /*!< DMA_DSR.CE Mask                         */
#define DMA_DSR_CE_SHIFT                         (6U)                                                /*!< DMA_DSR.CE Position                     */
#define DMA_DSR_CE(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_DSR.CE Field                        */
/* ------- DCR Bit Fields                           ------ */
#define DMA_DCR_LCH2_MASK                        (0x3U)                                              /*!< DMA_DCR.LCH2 Mask                       */
#define DMA_DCR_LCH2_SHIFT                       (0U)                                                /*!< DMA_DCR.LCH2 Position                   */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< DMA_DCR.LCH2 Field                      */
#define DMA_DCR_LCH1_MASK                        (0xCU)                                              /*!< DMA_DCR.LCH1 Mask                       */
#define DMA_DCR_LCH1_SHIFT                       (2U)                                                /*!< DMA_DCR.LCH1 Position                   */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< DMA_DCR.LCH1 Field                      */
#define DMA_DCR_LINKCC_MASK                      (0x30U)                                             /*!< DMA_DCR.LINKCC Mask                     */
#define DMA_DCR_LINKCC_SHIFT                     (4U)                                                /*!< DMA_DCR.LINKCC Position                 */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< DMA_DCR.LINKCC Field                    */
#define DMA_DCR_D_REQ_MASK                       (0x80U)                                             /*!< DMA_DCR.D_REQ Mask                      */
#define DMA_DCR_D_REQ_SHIFT                      (7U)                                                /*!< DMA_DCR.D_REQ Position                  */
#define DMA_DCR_D_REQ(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_DCR.D_REQ Field                     */
#define DMA_DCR_DMOD_MASK                        (0xF00U)                                            /*!< DMA_DCR.DMOD Mask                       */
#define DMA_DCR_DMOD_SHIFT                       (8U)                                                /*!< DMA_DCR.DMOD Position                   */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< DMA_DCR.DMOD Field                      */
#define DMA_DCR_SMOD_MASK                        (0xF000U)                                           /*!< DMA_DCR.SMOD Mask                       */
#define DMA_DCR_SMOD_SHIFT                       (12U)                                               /*!< DMA_DCR.SMOD Position                   */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< DMA_DCR.SMOD Field                      */
#define DMA_DCR_START_MASK                       (0x10000U)                                          /*!< DMA_DCR.START Mask                      */
#define DMA_DCR_START_SHIFT                      (16U)                                               /*!< DMA_DCR.START Position                  */
#define DMA_DCR_START(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< DMA_DCR.START Field                     */
#define DMA_DCR_DSIZE_MASK                       (0x60000U)                                          /*!< DMA_DCR.DSIZE Mask                      */
#define DMA_DCR_DSIZE_SHIFT                      (17U)                                               /*!< DMA_DCR.DSIZE Position                  */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<17U))&0x60000UL)      /*!< DMA_DCR.DSIZE Field                     */
#define DMA_DCR_DINC_MASK                        (0x80000U)                                          /*!< DMA_DCR.DINC Mask                       */
#define DMA_DCR_DINC_SHIFT                       (19U)                                               /*!< DMA_DCR.DINC Position                   */
#define DMA_DCR_DINC(x)                          (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< DMA_DCR.DINC Field                      */
#define DMA_DCR_SSIZE_MASK                       (0x300000U)                                         /*!< DMA_DCR.SSIZE Mask                      */
#define DMA_DCR_SSIZE_SHIFT                      (20U)                                               /*!< DMA_DCR.SSIZE Position                  */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<20U))&0x300000UL)     /*!< DMA_DCR.SSIZE Field                     */
#define DMA_DCR_SINC_MASK                        (0x400000U)                                         /*!< DMA_DCR.SINC Mask                       */
#define DMA_DCR_SINC_SHIFT                       (22U)                                               /*!< DMA_DCR.SINC Position                   */
#define DMA_DCR_SINC(x)                          (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< DMA_DCR.SINC Field                      */
#define DMA_DCR_BWC_MASK                         (0xE000000U)                                        /*!< DMA_DCR.BWC Mask                        */
#define DMA_DCR_BWC_SHIFT                        (25U)                                               /*!< DMA_DCR.BWC Position                    */
#define DMA_DCR_BWC(x)                           (((uint32_t)(((uint32_t)(x))<<25U))&0xE000000UL)    /*!< DMA_DCR.BWC Field                       */
#define DMA_DCR_AA_MASK                          (0x10000000U)                                       /*!< DMA_DCR.AA Mask                         */
#define DMA_DCR_AA_SHIFT                         (28U)                                               /*!< DMA_DCR.AA Position                     */
#define DMA_DCR_AA(x)                            (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< DMA_DCR.AA Field                        */
#define DMA_DCR_CS_MASK                          (0x20000000U)                                       /*!< DMA_DCR.CS Mask                         */
#define DMA_DCR_CS_SHIFT                         (29U)                                               /*!< DMA_DCR.CS Position                     */
#define DMA_DCR_CS(x)                            (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< DMA_DCR.CS Field                        */
#define DMA_DCR_EEXT_MASK                        (0x40000000U)                                       /*!< DMA_DCR.EEXT Mask                       */
#define DMA_DCR_EEXT_SHIFT                       (30U)                                               /*!< DMA_DCR.EEXT Position                   */
#define DMA_DCR_EEXT(x)                          (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< DMA_DCR.EEXT Field                      */
#define DMA_DCR_INT_MASK                         (0x80000000U)                                       /*!< DMA_DCR.INT Mask                        */
#define DMA_DCR_INT_SHIFT                        (31U)                                               /*!< DMA_DCR.INT Position                    */
#define DMA_DCR_INT(x)                           (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< DMA_DCR.INT Field                       */
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
typedef struct DTIM_Type {
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
#define DTIM_DTMR_RST_MASK                       (0x1U)                                              /*!< DTIM_DTMR.RST Mask                      */
#define DTIM_DTMR_RST_SHIFT                      (0U)                                                /*!< DTIM_DTMR.RST Position                  */
#define DTIM_DTMR_RST(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< DTIM_DTMR.RST Field                     */
#define DTIM_DTMR_CLK_MASK                       (0x6U)                                              /*!< DTIM_DTMR.CLK Mask                      */
#define DTIM_DTMR_CLK_SHIFT                      (1U)                                                /*!< DTIM_DTMR.CLK Position                  */
#define DTIM_DTMR_CLK(x)                         (((uint16_t)(((uint16_t)(x))<<1U))&0x6UL)           /*!< DTIM_DTMR.CLK Field                     */
#define DTIM_DTMR_FRR_MASK                       (0x8U)                                              /*!< DTIM_DTMR.FRR Mask                      */
#define DTIM_DTMR_FRR_SHIFT                      (3U)                                                /*!< DTIM_DTMR.FRR Position                  */
#define DTIM_DTMR_FRR(x)                         (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< DTIM_DTMR.FRR Field                     */
#define DTIM_DTMR_ORRI_MASK                      (0x10U)                                             /*!< DTIM_DTMR.ORRI Mask                     */
#define DTIM_DTMR_ORRI_SHIFT                     (4U)                                                /*!< DTIM_DTMR.ORRI Position                 */
#define DTIM_DTMR_ORRI(x)                        (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< DTIM_DTMR.ORRI Field                    */
#define DTIM_DTMR_OM_MASK                        (0x20U)                                             /*!< DTIM_DTMR.OM Mask                       */
#define DTIM_DTMR_OM_SHIFT                       (5U)                                                /*!< DTIM_DTMR.OM Position                   */
#define DTIM_DTMR_OM(x)                          (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< DTIM_DTMR.OM Field                      */
#define DTIM_DTMR_CE_MASK                        (0xC0U)                                             /*!< DTIM_DTMR.CE Mask                       */
#define DTIM_DTMR_CE_SHIFT                       (6U)                                                /*!< DTIM_DTMR.CE Position                   */
#define DTIM_DTMR_CE(x)                          (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< DTIM_DTMR.CE Field                      */
#define DTIM_DTMR_PS_MASK                        (0xFF00U)                                           /*!< DTIM_DTMR.PS Mask                       */
#define DTIM_DTMR_PS_SHIFT                       (8U)                                                /*!< DTIM_DTMR.PS Position                   */
#define DTIM_DTMR_PS(x)                          (((uint16_t)(((uint16_t)(x))<<8U))&0xFF00UL)        /*!< DTIM_DTMR.PS Field                      */
/* ------- DTXMR Bit Fields                         ------ */
#define DTIM_DTXMR_MODE16_MASK                   (0x1U)                                              /*!< DTIM_DTXMR.MODE16 Mask                  */
#define DTIM_DTXMR_MODE16_SHIFT                  (0U)                                                /*!< DTIM_DTXMR.MODE16 Position              */
#define DTIM_DTXMR_MODE16(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< DTIM_DTXMR.MODE16 Field                 */
#define DTIM_DTXMR_HALTED_MASK                   (0x40U)                                             /*!< DTIM_DTXMR.HALTED Mask                  */
#define DTIM_DTXMR_HALTED_SHIFT                  (6U)                                                /*!< DTIM_DTXMR.HALTED Position              */
#define DTIM_DTXMR_HALTED(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DTIM_DTXMR.HALTED Field                 */
#define DTIM_DTXMR_DMAEN_MASK                    (0x80U)                                             /*!< DTIM_DTXMR.DMAEN Mask                   */
#define DTIM_DTXMR_DMAEN_SHIFT                   (7U)                                                /*!< DTIM_DTXMR.DMAEN Position               */
#define DTIM_DTXMR_DMAEN(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DTIM_DTXMR.DMAEN Field                  */
/* ------- DTER Bit Fields                          ------ */
#define DTIM_DTER_CAP_MASK                       (0x1U)                                              /*!< DTIM_DTER.CAP Mask                      */
#define DTIM_DTER_CAP_SHIFT                      (0U)                                                /*!< DTIM_DTER.CAP Position                  */
#define DTIM_DTER_CAP(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< DTIM_DTER.CAP Field                     */
#define DTIM_DTER_REF_MASK                       (0x2U)                                              /*!< DTIM_DTER.REF Mask                      */
#define DTIM_DTER_REF_SHIFT                      (1U)                                                /*!< DTIM_DTER.REF Position                  */
#define DTIM_DTER_REF(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< DTIM_DTER.REF Field                     */
/* ------- DTRR Bit Fields                          ------ */
#define DTIM_DTRR_REF_MASK                       (0xFFFFFFFFU)                                       /*!< DTIM_DTRR.REF Mask                      */
#define DTIM_DTRR_REF_SHIFT                      (0U)                                                /*!< DTIM_DTRR.REF Position                  */
#define DTIM_DTRR_REF(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DTIM_DTRR.REF Field                     */
/* ------- DTCR Bit Fields                          ------ */
#define DTIM_DTCR_CAP_MASK                       (0xFFFFFFFFU)                                       /*!< DTIM_DTCR.CAP Mask                      */
#define DTIM_DTCR_CAP_SHIFT                      (0U)                                                /*!< DTIM_DTCR.CAP Position                  */
#define DTIM_DTCR_CAP(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DTIM_DTCR.CAP Field                     */
/* ------- DTCN Bit Fields                          ------ */
#define DTIM_DTCN_CNT_MASK                       (0xFFFFFFFFU)                                       /*!< DTIM_DTCN.CNT Mask                      */
#define DTIM_DTCN_CNT_SHIFT                      (0U)                                                /*!< DTIM_DTCN.CNT Position                  */
#define DTIM_DTCN_CNT(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DTIM_DTCN.CNT Field                     */
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
typedef struct EPORT0_Type {
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
#define EPORT0_EPPAR_EPPA0_MASK                  (0x3U)                                              /*!< EPORT0_EPPAR.EPPA0 Mask                 */
#define EPORT0_EPPAR_EPPA0_SHIFT                 (0U)                                                /*!< EPORT0_EPPAR.EPPA0 Position             */
#define EPORT0_EPPAR_EPPA0(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< EPORT0_EPPAR.EPPA0 Field                */
#define EPORT0_EPPAR_EPPA1_MASK                  (0xCU)                                              /*!< EPORT0_EPPAR.EPPA1 Mask                 */
#define EPORT0_EPPAR_EPPA1_SHIFT                 (2U)                                                /*!< EPORT0_EPPAR.EPPA1 Position             */
#define EPORT0_EPPAR_EPPA1(x)                    (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< EPORT0_EPPAR.EPPA1 Field                */
#define EPORT0_EPPAR_EPPA2_MASK                  (0x30U)                                             /*!< EPORT0_EPPAR.EPPA2 Mask                 */
#define EPORT0_EPPAR_EPPA2_SHIFT                 (4U)                                                /*!< EPORT0_EPPAR.EPPA2 Position             */
#define EPORT0_EPPAR_EPPA2(x)                    (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< EPORT0_EPPAR.EPPA2 Field                */
#define EPORT0_EPPAR_EPPA3_MASK                  (0xC0U)                                             /*!< EPORT0_EPPAR.EPPA3 Mask                 */
#define EPORT0_EPPAR_EPPA3_SHIFT                 (6U)                                                /*!< EPORT0_EPPAR.EPPA3 Position             */
#define EPORT0_EPPAR_EPPA3(x)                    (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< EPORT0_EPPAR.EPPA3 Field                */
#define EPORT0_EPPAR_EPPA4_MASK                  (0x300U)                                            /*!< EPORT0_EPPAR.EPPA4 Mask                 */
#define EPORT0_EPPAR_EPPA4_SHIFT                 (8U)                                                /*!< EPORT0_EPPAR.EPPA4 Position             */
#define EPORT0_EPPAR_EPPA4(x)                    (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< EPORT0_EPPAR.EPPA4 Field                */
#define EPORT0_EPPAR_EPPA5_MASK                  (0xC00U)                                            /*!< EPORT0_EPPAR.EPPA5 Mask                 */
#define EPORT0_EPPAR_EPPA5_SHIFT                 (10U)                                               /*!< EPORT0_EPPAR.EPPA5 Position             */
#define EPORT0_EPPAR_EPPA5(x)                    (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< EPORT0_EPPAR.EPPA5 Field                */
#define EPORT0_EPPAR_EPPA6_MASK                  (0x3000U)                                           /*!< EPORT0_EPPAR.EPPA6 Mask                 */
#define EPORT0_EPPAR_EPPA6_SHIFT                 (12U)                                               /*!< EPORT0_EPPAR.EPPA6 Position             */
#define EPORT0_EPPAR_EPPA6(x)                    (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< EPORT0_EPPAR.EPPA6 Field                */
#define EPORT0_EPPAR_EPPA7_MASK                  (0xC000U)                                           /*!< EPORT0_EPPAR.EPPA7 Mask                 */
#define EPORT0_EPPAR_EPPA7_SHIFT                 (14U)                                               /*!< EPORT0_EPPAR.EPPA7 Position             */
#define EPORT0_EPPAR_EPPA7(x)                    (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< EPORT0_EPPAR.EPPA7 Field                */
/* ------- EPDDR Bit Fields                         ------ */
#define EPORT0_EPDDR_EPDD0_MASK                  (0x1U)                                              /*!< EPORT0_EPDDR.EPDD0 Mask                 */
#define EPORT0_EPDDR_EPDD0_SHIFT                 (0U)                                                /*!< EPORT0_EPDDR.EPDD0 Position             */
#define EPORT0_EPDDR_EPDD0(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< EPORT0_EPDDR.EPDD0 Field                */
#define EPORT0_EPDDR_EPDD1_MASK                  (0x2U)                                              /*!< EPORT0_EPDDR.EPDD1 Mask                 */
#define EPORT0_EPDDR_EPDD1_SHIFT                 (1U)                                                /*!< EPORT0_EPDDR.EPDD1 Position             */
#define EPORT0_EPDDR_EPDD1(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< EPORT0_EPDDR.EPDD1 Field                */
#define EPORT0_EPDDR_EPDD2_MASK                  (0x4U)                                              /*!< EPORT0_EPDDR.EPDD2 Mask                 */
#define EPORT0_EPDDR_EPDD2_SHIFT                 (2U)                                                /*!< EPORT0_EPDDR.EPDD2 Position             */
#define EPORT0_EPDDR_EPDD2(x)                    (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< EPORT0_EPDDR.EPDD2 Field                */
#define EPORT0_EPDDR_EPDD3_MASK                  (0x8U)                                              /*!< EPORT0_EPDDR.EPDD3 Mask                 */
#define EPORT0_EPDDR_EPDD3_SHIFT                 (3U)                                                /*!< EPORT0_EPDDR.EPDD3 Position             */
#define EPORT0_EPDDR_EPDD3(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< EPORT0_EPDDR.EPDD3 Field                */
#define EPORT0_EPDDR_EPDD4_MASK                  (0x10U)                                             /*!< EPORT0_EPDDR.EPDD4 Mask                 */
#define EPORT0_EPDDR_EPDD4_SHIFT                 (4U)                                                /*!< EPORT0_EPDDR.EPDD4 Position             */
#define EPORT0_EPDDR_EPDD4(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< EPORT0_EPDDR.EPDD4 Field                */
#define EPORT0_EPDDR_EPDD5_MASK                  (0x20U)                                             /*!< EPORT0_EPDDR.EPDD5 Mask                 */
#define EPORT0_EPDDR_EPDD5_SHIFT                 (5U)                                                /*!< EPORT0_EPDDR.EPDD5 Position             */
#define EPORT0_EPDDR_EPDD5(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< EPORT0_EPDDR.EPDD5 Field                */
#define EPORT0_EPDDR_EPDD6_MASK                  (0x40U)                                             /*!< EPORT0_EPDDR.EPDD6 Mask                 */
#define EPORT0_EPDDR_EPDD6_SHIFT                 (6U)                                                /*!< EPORT0_EPDDR.EPDD6 Position             */
#define EPORT0_EPDDR_EPDD6(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< EPORT0_EPDDR.EPDD6 Field                */
#define EPORT0_EPDDR_EPDD7_MASK                  (0x80U)                                             /*!< EPORT0_EPDDR.EPDD7 Mask                 */
#define EPORT0_EPDDR_EPDD7_SHIFT                 (7U)                                                /*!< EPORT0_EPDDR.EPDD7 Position             */
#define EPORT0_EPDDR_EPDD7(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< EPORT0_EPDDR.EPDD7 Field                */
/* ------- EPIER Bit Fields                         ------ */
#define EPORT0_EPIER_EPIE0_MASK                  (0x1U)                                              /*!< EPORT0_EPIER.EPIE0 Mask                 */
#define EPORT0_EPIER_EPIE0_SHIFT                 (0U)                                                /*!< EPORT0_EPIER.EPIE0 Position             */
#define EPORT0_EPIER_EPIE0(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< EPORT0_EPIER.EPIE0 Field                */
#define EPORT0_EPIER_EPIE1_MASK                  (0x2U)                                              /*!< EPORT0_EPIER.EPIE1 Mask                 */
#define EPORT0_EPIER_EPIE1_SHIFT                 (1U)                                                /*!< EPORT0_EPIER.EPIE1 Position             */
#define EPORT0_EPIER_EPIE1(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< EPORT0_EPIER.EPIE1 Field                */
#define EPORT0_EPIER_EPIE2_MASK                  (0x4U)                                              /*!< EPORT0_EPIER.EPIE2 Mask                 */
#define EPORT0_EPIER_EPIE2_SHIFT                 (2U)                                                /*!< EPORT0_EPIER.EPIE2 Position             */
#define EPORT0_EPIER_EPIE2(x)                    (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< EPORT0_EPIER.EPIE2 Field                */
#define EPORT0_EPIER_EPIE3_MASK                  (0x8U)                                              /*!< EPORT0_EPIER.EPIE3 Mask                 */
#define EPORT0_EPIER_EPIE3_SHIFT                 (3U)                                                /*!< EPORT0_EPIER.EPIE3 Position             */
#define EPORT0_EPIER_EPIE3(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< EPORT0_EPIER.EPIE3 Field                */
#define EPORT0_EPIER_EPIE4_MASK                  (0x10U)                                             /*!< EPORT0_EPIER.EPIE4 Mask                 */
#define EPORT0_EPIER_EPIE4_SHIFT                 (4U)                                                /*!< EPORT0_EPIER.EPIE4 Position             */
#define EPORT0_EPIER_EPIE4(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< EPORT0_EPIER.EPIE4 Field                */
#define EPORT0_EPIER_EPIE5_MASK                  (0x20U)                                             /*!< EPORT0_EPIER.EPIE5 Mask                 */
#define EPORT0_EPIER_EPIE5_SHIFT                 (5U)                                                /*!< EPORT0_EPIER.EPIE5 Position             */
#define EPORT0_EPIER_EPIE5(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< EPORT0_EPIER.EPIE5 Field                */
#define EPORT0_EPIER_EPIE6_MASK                  (0x40U)                                             /*!< EPORT0_EPIER.EPIE6 Mask                 */
#define EPORT0_EPIER_EPIE6_SHIFT                 (6U)                                                /*!< EPORT0_EPIER.EPIE6 Position             */
#define EPORT0_EPIER_EPIE6(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< EPORT0_EPIER.EPIE6 Field                */
#define EPORT0_EPIER_EPIE7_MASK                  (0x80U)                                             /*!< EPORT0_EPIER.EPIE7 Mask                 */
#define EPORT0_EPIER_EPIE7_SHIFT                 (7U)                                                /*!< EPORT0_EPIER.EPIE7 Position             */
#define EPORT0_EPIER_EPIE7(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< EPORT0_EPIER.EPIE7 Field                */
/* ------- EPDR Bit Fields                          ------ */
#define EPORT0_EPDR_EPD0_MASK                    (0x1U)                                              /*!< EPORT0_EPDR.EPD0 Mask                   */
#define EPORT0_EPDR_EPD0_SHIFT                   (0U)                                                /*!< EPORT0_EPDR.EPD0 Position               */
#define EPORT0_EPDR_EPD0(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< EPORT0_EPDR.EPD0 Field                  */
#define EPORT0_EPDR_EPD1_MASK                    (0x2U)                                              /*!< EPORT0_EPDR.EPD1 Mask                   */
#define EPORT0_EPDR_EPD1_SHIFT                   (1U)                                                /*!< EPORT0_EPDR.EPD1 Position               */
#define EPORT0_EPDR_EPD1(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< EPORT0_EPDR.EPD1 Field                  */
#define EPORT0_EPDR_EPD2_MASK                    (0x4U)                                              /*!< EPORT0_EPDR.EPD2 Mask                   */
#define EPORT0_EPDR_EPD2_SHIFT                   (2U)                                                /*!< EPORT0_EPDR.EPD2 Position               */
#define EPORT0_EPDR_EPD2(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< EPORT0_EPDR.EPD2 Field                  */
#define EPORT0_EPDR_EPD3_MASK                    (0x8U)                                              /*!< EPORT0_EPDR.EPD3 Mask                   */
#define EPORT0_EPDR_EPD3_SHIFT                   (3U)                                                /*!< EPORT0_EPDR.EPD3 Position               */
#define EPORT0_EPDR_EPD3(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< EPORT0_EPDR.EPD3 Field                  */
#define EPORT0_EPDR_EPD4_MASK                    (0x10U)                                             /*!< EPORT0_EPDR.EPD4 Mask                   */
#define EPORT0_EPDR_EPD4_SHIFT                   (4U)                                                /*!< EPORT0_EPDR.EPD4 Position               */
#define EPORT0_EPDR_EPD4(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< EPORT0_EPDR.EPD4 Field                  */
#define EPORT0_EPDR_EPD5_MASK                    (0x20U)                                             /*!< EPORT0_EPDR.EPD5 Mask                   */
#define EPORT0_EPDR_EPD5_SHIFT                   (5U)                                                /*!< EPORT0_EPDR.EPD5 Position               */
#define EPORT0_EPDR_EPD5(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< EPORT0_EPDR.EPD5 Field                  */
#define EPORT0_EPDR_EPD6_MASK                    (0x40U)                                             /*!< EPORT0_EPDR.EPD6 Mask                   */
#define EPORT0_EPDR_EPD6_SHIFT                   (6U)                                                /*!< EPORT0_EPDR.EPD6 Position               */
#define EPORT0_EPDR_EPD6(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< EPORT0_EPDR.EPD6 Field                  */
#define EPORT0_EPDR_EPD7_MASK                    (0x80U)                                             /*!< EPORT0_EPDR.EPD7 Mask                   */
#define EPORT0_EPDR_EPD7_SHIFT                   (7U)                                                /*!< EPORT0_EPDR.EPD7 Position               */
#define EPORT0_EPDR_EPD7(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< EPORT0_EPDR.EPD7 Field                  */
/* ------- EPPDR Bit Fields                         ------ */
#define EPORT0_EPPDR_EPPD0_MASK                  (0x1U)                                              /*!< EPORT0_EPPDR.EPPD0 Mask                 */
#define EPORT0_EPPDR_EPPD0_SHIFT                 (0U)                                                /*!< EPORT0_EPPDR.EPPD0 Position             */
#define EPORT0_EPPDR_EPPD0(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< EPORT0_EPPDR.EPPD0 Field                */
#define EPORT0_EPPDR_EPPD1_MASK                  (0x2U)                                              /*!< EPORT0_EPPDR.EPPD1 Mask                 */
#define EPORT0_EPPDR_EPPD1_SHIFT                 (1U)                                                /*!< EPORT0_EPPDR.EPPD1 Position             */
#define EPORT0_EPPDR_EPPD1(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< EPORT0_EPPDR.EPPD1 Field                */
#define EPORT0_EPPDR_EPPD2_MASK                  (0x4U)                                              /*!< EPORT0_EPPDR.EPPD2 Mask                 */
#define EPORT0_EPPDR_EPPD2_SHIFT                 (2U)                                                /*!< EPORT0_EPPDR.EPPD2 Position             */
#define EPORT0_EPPDR_EPPD2(x)                    (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< EPORT0_EPPDR.EPPD2 Field                */
#define EPORT0_EPPDR_EPPD3_MASK                  (0x8U)                                              /*!< EPORT0_EPPDR.EPPD3 Mask                 */
#define EPORT0_EPPDR_EPPD3_SHIFT                 (3U)                                                /*!< EPORT0_EPPDR.EPPD3 Position             */
#define EPORT0_EPPDR_EPPD3(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< EPORT0_EPPDR.EPPD3 Field                */
#define EPORT0_EPPDR_EPPD4_MASK                  (0x10U)                                             /*!< EPORT0_EPPDR.EPPD4 Mask                 */
#define EPORT0_EPPDR_EPPD4_SHIFT                 (4U)                                                /*!< EPORT0_EPPDR.EPPD4 Position             */
#define EPORT0_EPPDR_EPPD4(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< EPORT0_EPPDR.EPPD4 Field                */
#define EPORT0_EPPDR_EPPD5_MASK                  (0x20U)                                             /*!< EPORT0_EPPDR.EPPD5 Mask                 */
#define EPORT0_EPPDR_EPPD5_SHIFT                 (5U)                                                /*!< EPORT0_EPPDR.EPPD5 Position             */
#define EPORT0_EPPDR_EPPD5(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< EPORT0_EPPDR.EPPD5 Field                */
#define EPORT0_EPPDR_EPPD6_MASK                  (0x40U)                                             /*!< EPORT0_EPPDR.EPPD6 Mask                 */
#define EPORT0_EPPDR_EPPD6_SHIFT                 (6U)                                                /*!< EPORT0_EPPDR.EPPD6 Position             */
#define EPORT0_EPPDR_EPPD6(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< EPORT0_EPPDR.EPPD6 Field                */
#define EPORT0_EPPDR_EPPD7_MASK                  (0x80U)                                             /*!< EPORT0_EPPDR.EPPD7 Mask                 */
#define EPORT0_EPPDR_EPPD7_SHIFT                 (7U)                                                /*!< EPORT0_EPPDR.EPPD7 Position             */
#define EPORT0_EPPDR_EPPD7(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< EPORT0_EPPDR.EPPD7 Field                */
/* ------- EPFR Bit Fields                          ------ */
#define EPORT0_EPFR_EPF0_MASK                    (0x1U)                                              /*!< EPORT0_EPFR.EPF0 Mask                   */
#define EPORT0_EPFR_EPF0_SHIFT                   (0U)                                                /*!< EPORT0_EPFR.EPF0 Position               */
#define EPORT0_EPFR_EPF0(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< EPORT0_EPFR.EPF0 Field                  */
#define EPORT0_EPFR_EPF1_MASK                    (0x2U)                                              /*!< EPORT0_EPFR.EPF1 Mask                   */
#define EPORT0_EPFR_EPF1_SHIFT                   (1U)                                                /*!< EPORT0_EPFR.EPF1 Position               */
#define EPORT0_EPFR_EPF1(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< EPORT0_EPFR.EPF1 Field                  */
#define EPORT0_EPFR_EPF2_MASK                    (0x4U)                                              /*!< EPORT0_EPFR.EPF2 Mask                   */
#define EPORT0_EPFR_EPF2_SHIFT                   (2U)                                                /*!< EPORT0_EPFR.EPF2 Position               */
#define EPORT0_EPFR_EPF2(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< EPORT0_EPFR.EPF2 Field                  */
#define EPORT0_EPFR_EPF3_MASK                    (0x8U)                                              /*!< EPORT0_EPFR.EPF3 Mask                   */
#define EPORT0_EPFR_EPF3_SHIFT                   (3U)                                                /*!< EPORT0_EPFR.EPF3 Position               */
#define EPORT0_EPFR_EPF3(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< EPORT0_EPFR.EPF3 Field                  */
#define EPORT0_EPFR_EPF4_MASK                    (0x10U)                                             /*!< EPORT0_EPFR.EPF4 Mask                   */
#define EPORT0_EPFR_EPF4_SHIFT                   (4U)                                                /*!< EPORT0_EPFR.EPF4 Position               */
#define EPORT0_EPFR_EPF4(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< EPORT0_EPFR.EPF4 Field                  */
#define EPORT0_EPFR_EPF5_MASK                    (0x20U)                                             /*!< EPORT0_EPFR.EPF5 Mask                   */
#define EPORT0_EPFR_EPF5_SHIFT                   (5U)                                                /*!< EPORT0_EPFR.EPF5 Position               */
#define EPORT0_EPFR_EPF5(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< EPORT0_EPFR.EPF5 Field                  */
#define EPORT0_EPFR_EPF6_MASK                    (0x40U)                                             /*!< EPORT0_EPFR.EPF6 Mask                   */
#define EPORT0_EPFR_EPF6_SHIFT                   (6U)                                                /*!< EPORT0_EPFR.EPF6 Position               */
#define EPORT0_EPFR_EPF6(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< EPORT0_EPFR.EPF6 Field                  */
#define EPORT0_EPFR_EPF7_MASK                    (0x80U)                                             /*!< EPORT0_EPFR.EPF7 Mask                   */
#define EPORT0_EPFR_EPF7_SHIFT                   (7U)                                                /*!< EPORT0_EPFR.EPF7 Position               */
#define EPORT0_EPFR_EPF7(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< EPORT0_EPFR.EPF7 Field                  */
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
* @addtogroup FBCS_Peripheral_access_layer_GROUP FBCS Peripheral Access Layer
* @brief C Struct for FBCS
* @{
*/

/* ================================================================================ */
/* ================           FBCS (file:MCF52259_FBCS)            ================ */
/* ================================================================================ */

/**
 * @brief Mini-FlexBus Control
 */
/**
* @addtogroup FBCS_structs_GROUP FBCS struct
* @brief Struct for FBCS
* @{
*/
typedef struct FBCS_Type {
   struct {
      __IO uint32_t  CSAR;                      /**< 0000: Chip-Select Address Register                                 */
      __IO uint32_t  CSMR;                      /**< 0004: Chip-Select Mask Registers                                   */
      __IO uint32_t  CSCR;                      /**< 0008: Chip-Select Control Register                                 */
   } CH[2];                                     /**< 0000: (cluster: size=0x0018, 24)                                   */
} FBCS_Type;

/**
 * @} */ /* End group FBCS_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FBCS' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FBCS_Register_Masks_GROUP FBCS Register Masks
* @brief Register Masks for FBCS
* @{
*/
/* ------- CSAR Bit Fields                          ------ */
#define FBCS_CSAR_BA_MASK                        (0xFFFF0000U)                                       /*!< FBCS_CSAR.BA Mask                       */
#define FBCS_CSAR_BA_SHIFT                       (16U)                                               /*!< FBCS_CSAR.BA Position                   */
#define FBCS_CSAR_BA(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< FBCS_CSAR.BA Field                      */
/* ------- CSMR Bit Fields                          ------ */
#define FBCS_CSMR_V_MASK                         (0x1U)                                              /*!< FBCS_CSMR.V Mask                        */
#define FBCS_CSMR_V_SHIFT                        (0U)                                                /*!< FBCS_CSMR.V Position                    */
#define FBCS_CSMR_V(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FBCS_CSMR.V Field                       */
#define FBCS_CSMR_WP_MASK                        (0x100U)                                            /*!< FBCS_CSMR.WP Mask                       */
#define FBCS_CSMR_WP_SHIFT                       (8U)                                                /*!< FBCS_CSMR.WP Position                   */
#define FBCS_CSMR_WP(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FBCS_CSMR.WP Field                      */
#define FBCS_CSMR_BAM_MASK                       (0xFFFF0000U)                                       /*!< FBCS_CSMR.BAM Mask                      */
#define FBCS_CSMR_BAM_SHIFT                      (16U)                                               /*!< FBCS_CSMR.BAM Position                  */
#define FBCS_CSMR_BAM(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< FBCS_CSMR.BAM Field                     */
/* ------- CSCR Bit Fields                          ------ */
#define FBCS_CSCR_BSTW_MASK                      (0x8U)                                              /*!< FBCS_CSCR.BSTW Mask                     */
#define FBCS_CSCR_BSTW_SHIFT                     (3U)                                                /*!< FBCS_CSCR.BSTW Position                 */
#define FBCS_CSCR_BSTW(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FBCS_CSCR.BSTW Field                    */
#define FBCS_CSCR_BSTR_MASK                      (0x10U)                                             /*!< FBCS_CSCR.BSTR Mask                     */
#define FBCS_CSCR_BSTR_SHIFT                     (4U)                                                /*!< FBCS_CSCR.BSTR Position                 */
#define FBCS_CSCR_BSTR(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FBCS_CSCR.BSTR Field                    */
#define FBCS_CSCR_PS_MASK                        (0xC0U)                                             /*!< FBCS_CSCR.PS Mask                       */
#define FBCS_CSCR_PS_SHIFT                       (6U)                                                /*!< FBCS_CSCR.PS Position                   */
#define FBCS_CSCR_PS(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< FBCS_CSCR.PS Field                      */
#define FBCS_CSCR_AA_MASK                        (0x100U)                                            /*!< FBCS_CSCR.AA Mask                       */
#define FBCS_CSCR_AA_SHIFT                       (8U)                                                /*!< FBCS_CSCR.AA Position                   */
#define FBCS_CSCR_AA(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FBCS_CSCR.AA Field                      */
#define FBCS_CSCR_MUX_MASK                       (0x200U)                                            /*!< FBCS_CSCR.MUX Mask                      */
#define FBCS_CSCR_MUX_SHIFT                      (9U)                                                /*!< FBCS_CSCR.MUX Position                  */
#define FBCS_CSCR_MUX(x)                         (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FBCS_CSCR.MUX Field                     */
#define FBCS_CSCR_WS_MASK                        (0xFC00U)                                           /*!< FBCS_CSCR.WS Mask                       */
#define FBCS_CSCR_WS_SHIFT                       (10U)                                               /*!< FBCS_CSCR.WS Position                   */
#define FBCS_CSCR_WS(x)                          (((uint32_t)(((uint32_t)(x))<<10U))&0xFC00UL)       /*!< FBCS_CSCR.WS Field                      */
#define FBCS_CSCR_WRAH_MASK                      (0x30000U)                                          /*!< FBCS_CSCR.WRAH Mask                     */
#define FBCS_CSCR_WRAH_SHIFT                     (16U)                                               /*!< FBCS_CSCR.WRAH Position                 */
#define FBCS_CSCR_WRAH(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< FBCS_CSCR.WRAH Field                    */
#define FBCS_CSCR_RDAH_MASK                      (0xC0000U)                                          /*!< FBCS_CSCR.RDAH Mask                     */
#define FBCS_CSCR_RDAH_SHIFT                     (18U)                                               /*!< FBCS_CSCR.RDAH Position                 */
#define FBCS_CSCR_RDAH(x)                        (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< FBCS_CSCR.RDAH Field                    */
#define FBCS_CSCR_ASET_MASK                      (0x300000U)                                         /*!< FBCS_CSCR.ASET Mask                     */
#define FBCS_CSCR_ASET_SHIFT                     (20U)                                               /*!< FBCS_CSCR.ASET Position                 */
#define FBCS_CSCR_ASET(x)                        (((uint32_t)(((uint32_t)(x))<<20U))&0x300000UL)     /*!< FBCS_CSCR.ASET Field                    */
#define FBCS_CSCR_SWSEN_MASK                     (0x800000U)                                         /*!< FBCS_CSCR.SWSEN Mask                    */
#define FBCS_CSCR_SWSEN_SHIFT                    (23U)                                               /*!< FBCS_CSCR.SWSEN Position                */
#define FBCS_CSCR_SWSEN(x)                       (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< FBCS_CSCR.SWSEN Field                   */
#define FBCS_CSCR_SWS_MASK                       (0xFC000000U)                                       /*!< FBCS_CSCR.SWS Mask                      */
#define FBCS_CSCR_SWS_SHIFT                      (26U)                                               /*!< FBCS_CSCR.SWS Position                  */
#define FBCS_CSCR_SWS(x)                         (((uint32_t)(((uint32_t)(x))<<26U))&0xFC000000UL)   /*!< FBCS_CSCR.SWS Field                     */
/**
 * @} */ /* End group FBCS_Register_Masks_GROUP 
 */

/* FBCS - Peripheral instance base addresses */
#define FBCS_BasePtr                   0x40000080UL //!< Peripheral base address
#define FBCS                           ((FBCS_Type *) FBCS_BasePtr) //!< Freescale base pointer
#define FBCS_BASE_PTR                  (FBCS) //!< Freescale style base pointer
/**
 * @} */ /* End group FBCS_Peripheral_access_layer_GROUP 
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
typedef struct FEC_Type {
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
#define FEC_EIR_UN_MASK                          (0x80000U)                                          /*!< FEC_EIR.UN Mask                         */
#define FEC_EIR_UN_SHIFT                         (19U)                                               /*!< FEC_EIR.UN Position                     */
#define FEC_EIR_UN(x)                            (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< FEC_EIR.UN Field                        */
#define FEC_EIR_RL_MASK                          (0x100000U)                                         /*!< FEC_EIR.RL Mask                         */
#define FEC_EIR_RL_SHIFT                         (20U)                                               /*!< FEC_EIR.RL Position                     */
#define FEC_EIR_RL(x)                            (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< FEC_EIR.RL Field                        */
#define FEC_EIR_LC_MASK                          (0x200000U)                                         /*!< FEC_EIR.LC Mask                         */
#define FEC_EIR_LC_SHIFT                         (21U)                                               /*!< FEC_EIR.LC Position                     */
#define FEC_EIR_LC(x)                            (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< FEC_EIR.LC Field                        */
#define FEC_EIR_EBERR_MASK                       (0x400000U)                                         /*!< FEC_EIR.EBERR Mask                      */
#define FEC_EIR_EBERR_SHIFT                      (22U)                                               /*!< FEC_EIR.EBERR Position                  */
#define FEC_EIR_EBERR(x)                         (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< FEC_EIR.EBERR Field                     */
#define FEC_EIR_MII_MASK                         (0x800000U)                                         /*!< FEC_EIR.MII Mask                        */
#define FEC_EIR_MII_SHIFT                        (23U)                                               /*!< FEC_EIR.MII Position                    */
#define FEC_EIR_MII(x)                           (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< FEC_EIR.MII Field                       */
#define FEC_EIR_RXB_MASK                         (0x1000000U)                                        /*!< FEC_EIR.RXB Mask                        */
#define FEC_EIR_RXB_SHIFT                        (24U)                                               /*!< FEC_EIR.RXB Position                    */
#define FEC_EIR_RXB(x)                           (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< FEC_EIR.RXB Field                       */
#define FEC_EIR_RXF_MASK                         (0x2000000U)                                        /*!< FEC_EIR.RXF Mask                        */
#define FEC_EIR_RXF_SHIFT                        (25U)                                               /*!< FEC_EIR.RXF Position                    */
#define FEC_EIR_RXF(x)                           (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< FEC_EIR.RXF Field                       */
#define FEC_EIR_TXB_MASK                         (0x4000000U)                                        /*!< FEC_EIR.TXB Mask                        */
#define FEC_EIR_TXB_SHIFT                        (26U)                                               /*!< FEC_EIR.TXB Position                    */
#define FEC_EIR_TXB(x)                           (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< FEC_EIR.TXB Field                       */
#define FEC_EIR_TXF_MASK                         (0x8000000U)                                        /*!< FEC_EIR.TXF Mask                        */
#define FEC_EIR_TXF_SHIFT                        (27U)                                               /*!< FEC_EIR.TXF Position                    */
#define FEC_EIR_TXF(x)                           (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< FEC_EIR.TXF Field                       */
#define FEC_EIR_GRA_MASK                         (0x10000000U)                                       /*!< FEC_EIR.GRA Mask                        */
#define FEC_EIR_GRA_SHIFT                        (28U)                                               /*!< FEC_EIR.GRA Position                    */
#define FEC_EIR_GRA(x)                           (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< FEC_EIR.GRA Field                       */
#define FEC_EIR_BABT_MASK                        (0x20000000U)                                       /*!< FEC_EIR.BABT Mask                       */
#define FEC_EIR_BABT_SHIFT                       (29U)                                               /*!< FEC_EIR.BABT Position                   */
#define FEC_EIR_BABT(x)                          (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< FEC_EIR.BABT Field                      */
#define FEC_EIR_BABR_MASK                        (0x40000000U)                                       /*!< FEC_EIR.BABR Mask                       */
#define FEC_EIR_BABR_SHIFT                       (30U)                                               /*!< FEC_EIR.BABR Position                   */
#define FEC_EIR_BABR(x)                          (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< FEC_EIR.BABR Field                      */
#define FEC_EIR_HBERR_MASK                       (0x80000000U)                                       /*!< FEC_EIR.HBERR Mask                      */
#define FEC_EIR_HBERR_SHIFT                      (31U)                                               /*!< FEC_EIR.HBERR Position                  */
#define FEC_EIR_HBERR(x)                         (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< FEC_EIR.HBERR Field                     */
/* ------- EIMR Bit Fields                          ------ */
#define FEC_EIMR_UN_MASK                         (0x80000U)                                          /*!< FEC_EIMR.UN Mask                        */
#define FEC_EIMR_UN_SHIFT                        (19U)                                               /*!< FEC_EIMR.UN Position                    */
#define FEC_EIMR_UN(x)                           (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< FEC_EIMR.UN Field                       */
#define FEC_EIMR_RL_MASK                         (0x100000U)                                         /*!< FEC_EIMR.RL Mask                        */
#define FEC_EIMR_RL_SHIFT                        (20U)                                               /*!< FEC_EIMR.RL Position                    */
#define FEC_EIMR_RL(x)                           (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< FEC_EIMR.RL Field                       */
#define FEC_EIMR_LC_MASK                         (0x200000U)                                         /*!< FEC_EIMR.LC Mask                        */
#define FEC_EIMR_LC_SHIFT                        (21U)                                               /*!< FEC_EIMR.LC Position                    */
#define FEC_EIMR_LC(x)                           (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< FEC_EIMR.LC Field                       */
#define FEC_EIMR_EBERR_MASK                      (0x400000U)                                         /*!< FEC_EIMR.EBERR Mask                     */
#define FEC_EIMR_EBERR_SHIFT                     (22U)                                               /*!< FEC_EIMR.EBERR Position                 */
#define FEC_EIMR_EBERR(x)                        (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< FEC_EIMR.EBERR Field                    */
#define FEC_EIMR_MII_MASK                        (0x800000U)                                         /*!< FEC_EIMR.MII Mask                       */
#define FEC_EIMR_MII_SHIFT                       (23U)                                               /*!< FEC_EIMR.MII Position                   */
#define FEC_EIMR_MII(x)                          (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< FEC_EIMR.MII Field                      */
#define FEC_EIMR_RXB_MASK                        (0x1000000U)                                        /*!< FEC_EIMR.RXB Mask                       */
#define FEC_EIMR_RXB_SHIFT                       (24U)                                               /*!< FEC_EIMR.RXB Position                   */
#define FEC_EIMR_RXB(x)                          (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< FEC_EIMR.RXB Field                      */
#define FEC_EIMR_RXF_MASK                        (0x2000000U)                                        /*!< FEC_EIMR.RXF Mask                       */
#define FEC_EIMR_RXF_SHIFT                       (25U)                                               /*!< FEC_EIMR.RXF Position                   */
#define FEC_EIMR_RXF(x)                          (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< FEC_EIMR.RXF Field                      */
#define FEC_EIMR_TXB_MASK                        (0x4000000U)                                        /*!< FEC_EIMR.TXB Mask                       */
#define FEC_EIMR_TXB_SHIFT                       (26U)                                               /*!< FEC_EIMR.TXB Position                   */
#define FEC_EIMR_TXB(x)                          (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< FEC_EIMR.TXB Field                      */
#define FEC_EIMR_TXF_MASK                        (0x8000000U)                                        /*!< FEC_EIMR.TXF Mask                       */
#define FEC_EIMR_TXF_SHIFT                       (27U)                                               /*!< FEC_EIMR.TXF Position                   */
#define FEC_EIMR_TXF(x)                          (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< FEC_EIMR.TXF Field                      */
#define FEC_EIMR_GRA_MASK                        (0x10000000U)                                       /*!< FEC_EIMR.GRA Mask                       */
#define FEC_EIMR_GRA_SHIFT                       (28U)                                               /*!< FEC_EIMR.GRA Position                   */
#define FEC_EIMR_GRA(x)                          (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< FEC_EIMR.GRA Field                      */
#define FEC_EIMR_BABT_MASK                       (0x20000000U)                                       /*!< FEC_EIMR.BABT Mask                      */
#define FEC_EIMR_BABT_SHIFT                      (29U)                                               /*!< FEC_EIMR.BABT Position                  */
#define FEC_EIMR_BABT(x)                         (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< FEC_EIMR.BABT Field                     */
#define FEC_EIMR_BABR_MASK                       (0x40000000U)                                       /*!< FEC_EIMR.BABR Mask                      */
#define FEC_EIMR_BABR_SHIFT                      (30U)                                               /*!< FEC_EIMR.BABR Position                  */
#define FEC_EIMR_BABR(x)                         (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< FEC_EIMR.BABR Field                     */
#define FEC_EIMR_HBERR_MASK                      (0x80000000U)                                       /*!< FEC_EIMR.HBERR Mask                     */
#define FEC_EIMR_HBERR_SHIFT                     (31U)                                               /*!< FEC_EIMR.HBERR Position                 */
#define FEC_EIMR_HBERR(x)                        (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< FEC_EIMR.HBERR Field                    */
/* ------- RDAR Bit Fields                          ------ */
#define FEC_RDAR_R_DES_ACTIVE_MASK               (0x1000000U)                                        /*!< FEC_RDAR.R_DES_ACTIVE Mask              */
#define FEC_RDAR_R_DES_ACTIVE_SHIFT              (24U)                                               /*!< FEC_RDAR.R_DES_ACTIVE Position          */
#define FEC_RDAR_R_DES_ACTIVE(x)                 (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< FEC_RDAR.R_DES_ACTIVE Field             */
/* ------- TDAR Bit Fields                          ------ */
#define FEC_TDAR_X_DES_ACTIVE_MASK               (0x1000000U)                                        /*!< FEC_TDAR.X_DES_ACTIVE Mask              */
#define FEC_TDAR_X_DES_ACTIVE_SHIFT              (24U)                                               /*!< FEC_TDAR.X_DES_ACTIVE Position          */
#define FEC_TDAR_X_DES_ACTIVE(x)                 (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< FEC_TDAR.X_DES_ACTIVE Field             */
/* ------- ECR Bit Fields                           ------ */
#define FEC_ECR_RESET_MASK                       (0x1U)                                              /*!< FEC_ECR.RESET Mask                      */
#define FEC_ECR_RESET_SHIFT                      (0U)                                                /*!< FEC_ECR.RESET Position                  */
#define FEC_ECR_RESET(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FEC_ECR.RESET Field                     */
#define FEC_ECR_ETHER_EN_MASK                    (0x2U)                                              /*!< FEC_ECR.ETHER_EN Mask                   */
#define FEC_ECR_ETHER_EN_SHIFT                   (1U)                                                /*!< FEC_ECR.ETHER_EN Position               */
#define FEC_ECR_ETHER_EN(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FEC_ECR.ETHER_EN Field                  */
/* ------- MMFR Bit Fields                          ------ */
#define FEC_MMFR_DATA_MASK                       (0xFFFFU)                                           /*!< FEC_MMFR.DATA Mask                      */
#define FEC_MMFR_DATA_SHIFT                      (0U)                                                /*!< FEC_MMFR.DATA Position                  */
#define FEC_MMFR_DATA(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FEC_MMFR.DATA Field                     */
#define FEC_MMFR_TA_MASK                         (0x30000U)                                          /*!< FEC_MMFR.TA Mask                        */
#define FEC_MMFR_TA_SHIFT                        (16U)                                               /*!< FEC_MMFR.TA Position                    */
#define FEC_MMFR_TA(x)                           (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< FEC_MMFR.TA Field                       */
#define FEC_MMFR_RA_MASK                         (0x7C0000U)                                         /*!< FEC_MMFR.RA Mask                        */
#define FEC_MMFR_RA_SHIFT                        (18U)                                               /*!< FEC_MMFR.RA Position                    */
#define FEC_MMFR_RA(x)                           (((uint32_t)(((uint32_t)(x))<<18U))&0x7C0000UL)     /*!< FEC_MMFR.RA Field                       */
#define FEC_MMFR_PA_MASK                         (0xF800000U)                                        /*!< FEC_MMFR.PA Mask                        */
#define FEC_MMFR_PA_SHIFT                        (23U)                                               /*!< FEC_MMFR.PA Position                    */
#define FEC_MMFR_PA(x)                           (((uint32_t)(((uint32_t)(x))<<23U))&0xF800000UL)    /*!< FEC_MMFR.PA Field                       */
#define FEC_MMFR_OP_MASK                         (0x30000000U)                                       /*!< FEC_MMFR.OP Mask                        */
#define FEC_MMFR_OP_SHIFT                        (28U)                                               /*!< FEC_MMFR.OP Position                    */
#define FEC_MMFR_OP(x)                           (((uint32_t)(((uint32_t)(x))<<28U))&0x30000000UL)   /*!< FEC_MMFR.OP Field                       */
#define FEC_MMFR_ST_MASK                         (0xC0000000U)                                       /*!< FEC_MMFR.ST Mask                        */
#define FEC_MMFR_ST_SHIFT                        (30U)                                               /*!< FEC_MMFR.ST Position                    */
#define FEC_MMFR_ST(x)                           (((uint32_t)(((uint32_t)(x))<<30U))&0xC0000000UL)   /*!< FEC_MMFR.ST Field                       */
/* ------- MSCR Bit Fields                          ------ */
#define FEC_MSCR_MII_SPEED_MASK                  (0x7EU)                                             /*!< FEC_MSCR.MII_SPEED Mask                 */
#define FEC_MSCR_MII_SPEED_SHIFT                 (1U)                                                /*!< FEC_MSCR.MII_SPEED Position             */
#define FEC_MSCR_MII_SPEED(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x7EUL)          /*!< FEC_MSCR.MII_SPEED Field                */
#define FEC_MSCR_DIS_PREAMBLE_MASK               (0x80U)                                             /*!< FEC_MSCR.DIS_PREAMBLE Mask              */
#define FEC_MSCR_DIS_PREAMBLE_SHIFT              (7U)                                                /*!< FEC_MSCR.DIS_PREAMBLE Position          */
#define FEC_MSCR_DIS_PREAMBLE(x)                 (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FEC_MSCR.DIS_PREAMBLE Field             */
/* ------- MIBC Bit Fields                          ------ */
#define FEC_MIBC_MIB_IDLE_MASK                   (0x40000000U)                                       /*!< FEC_MIBC.MIB_IDLE Mask                  */
#define FEC_MIBC_MIB_IDLE_SHIFT                  (30U)                                               /*!< FEC_MIBC.MIB_IDLE Position              */
#define FEC_MIBC_MIB_IDLE(x)                     (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< FEC_MIBC.MIB_IDLE Field                 */
#define FEC_MIBC_MIB_DISABLE_MASK                (0x80000000U)                                       /*!< FEC_MIBC.MIB_DISABLE Mask               */
#define FEC_MIBC_MIB_DISABLE_SHIFT               (31U)                                               /*!< FEC_MIBC.MIB_DISABLE Position           */
#define FEC_MIBC_MIB_DISABLE(x)                  (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< FEC_MIBC.MIB_DISABLE Field              */
/* ------- RCR Bit Fields                           ------ */
#define FEC_RCR_LOOP_MASK                        (0x1U)                                              /*!< FEC_RCR.LOOP Mask                       */
#define FEC_RCR_LOOP_SHIFT                       (0U)                                                /*!< FEC_RCR.LOOP Position                   */
#define FEC_RCR_LOOP(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FEC_RCR.LOOP Field                      */
#define FEC_RCR_DRT_MASK                         (0x2U)                                              /*!< FEC_RCR.DRT Mask                        */
#define FEC_RCR_DRT_SHIFT                        (1U)                                                /*!< FEC_RCR.DRT Position                    */
#define FEC_RCR_DRT(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FEC_RCR.DRT Field                       */
#define FEC_RCR_MII_MODE_MASK                    (0x4U)                                              /*!< FEC_RCR.MII_MODE Mask                   */
#define FEC_RCR_MII_MODE_SHIFT                   (2U)                                                /*!< FEC_RCR.MII_MODE Position               */
#define FEC_RCR_MII_MODE(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FEC_RCR.MII_MODE Field                  */
#define FEC_RCR_PROM_MASK                        (0x8U)                                              /*!< FEC_RCR.PROM Mask                       */
#define FEC_RCR_PROM_SHIFT                       (3U)                                                /*!< FEC_RCR.PROM Position                   */
#define FEC_RCR_PROM(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FEC_RCR.PROM Field                      */
#define FEC_RCR_BC_REJ_MASK                      (0x10U)                                             /*!< FEC_RCR.BC_REJ Mask                     */
#define FEC_RCR_BC_REJ_SHIFT                     (4U)                                                /*!< FEC_RCR.BC_REJ Position                 */
#define FEC_RCR_BC_REJ(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FEC_RCR.BC_REJ Field                    */
#define FEC_RCR_FCE_MASK                         (0x20U)                                             /*!< FEC_RCR.FCE Mask                        */
#define FEC_RCR_FCE_SHIFT                        (5U)                                                /*!< FEC_RCR.FCE Position                    */
#define FEC_RCR_FCE(x)                           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FEC_RCR.FCE Field                       */
#define FEC_RCR_MAX_FL_MASK                      (0x7FF0000U)                                        /*!< FEC_RCR.MAX_FL Mask                     */
#define FEC_RCR_MAX_FL_SHIFT                     (16U)                                               /*!< FEC_RCR.MAX_FL Position                 */
#define FEC_RCR_MAX_FL(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0x7FF0000UL)    /*!< FEC_RCR.MAX_FL Field                    */
/* ------- TCR Bit Fields                           ------ */
#define FEC_TCR_GTS_MASK                         (0x1U)                                              /*!< FEC_TCR.GTS Mask                        */
#define FEC_TCR_GTS_SHIFT                        (0U)                                                /*!< FEC_TCR.GTS Position                    */
#define FEC_TCR_GTS(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FEC_TCR.GTS Field                       */
#define FEC_TCR_HBC_MASK                         (0x2U)                                              /*!< FEC_TCR.HBC Mask                        */
#define FEC_TCR_HBC_SHIFT                        (1U)                                                /*!< FEC_TCR.HBC Position                    */
#define FEC_TCR_HBC(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FEC_TCR.HBC Field                       */
#define FEC_TCR_FDEN_MASK                        (0x4U)                                              /*!< FEC_TCR.FDEN Mask                       */
#define FEC_TCR_FDEN_SHIFT                       (2U)                                                /*!< FEC_TCR.FDEN Position                   */
#define FEC_TCR_FDEN(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FEC_TCR.FDEN Field                      */
#define FEC_TCR_TFC_PAUSE_MASK                   (0x8U)                                              /*!< FEC_TCR.TFC_PAUSE Mask                  */
#define FEC_TCR_TFC_PAUSE_SHIFT                  (3U)                                                /*!< FEC_TCR.TFC_PAUSE Position              */
#define FEC_TCR_TFC_PAUSE(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FEC_TCR.TFC_PAUSE Field                 */
#define FEC_TCR_RFC_PAUSE_MASK                   (0x10U)                                             /*!< FEC_TCR.RFC_PAUSE Mask                  */
#define FEC_TCR_RFC_PAUSE_SHIFT                  (4U)                                                /*!< FEC_TCR.RFC_PAUSE Position              */
#define FEC_TCR_RFC_PAUSE(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FEC_TCR.RFC_PAUSE Field                 */
/* ------- PALR Bit Fields                          ------ */
#define FEC_PALR_PADDR1_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_PALR.PADDR1 Mask                    */
#define FEC_PALR_PADDR1_SHIFT                    (0U)                                                /*!< FEC_PALR.PADDR1 Position                */
#define FEC_PALR_PADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_PALR.PADDR1 Field                   */
/* ------- PAUR Bit Fields                          ------ */
#define FEC_PAUR_TYPE_MASK                       (0xFFFFU)                                           /*!< FEC_PAUR.TYPE Mask                      */
#define FEC_PAUR_TYPE_SHIFT                      (0U)                                                /*!< FEC_PAUR.TYPE Position                  */
#define FEC_PAUR_TYPE(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FEC_PAUR.TYPE Field                     */
#define FEC_PAUR_PADDR2_MASK                     (0xFFFF0000U)                                       /*!< FEC_PAUR.PADDR2 Mask                    */
#define FEC_PAUR_PADDR2_SHIFT                    (16U)                                               /*!< FEC_PAUR.PADDR2 Position                */
#define FEC_PAUR_PADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< FEC_PAUR.PADDR2 Field                   */
/* ------- OPD Bit Fields                           ------ */
#define FEC_OPD_PAUSE_DUR_MASK                   (0xFFFFU)                                           /*!< FEC_OPD.PAUSE_DUR Mask                  */
#define FEC_OPD_PAUSE_DUR_SHIFT                  (0U)                                                /*!< FEC_OPD.PAUSE_DUR Position              */
#define FEC_OPD_PAUSE_DUR(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FEC_OPD.PAUSE_DUR Field                 */
#define FEC_OPD_OPCODE_MASK                      (0xFFFF0000U)                                       /*!< FEC_OPD.OPCODE Mask                     */
#define FEC_OPD_OPCODE_SHIFT                     (16U)                                               /*!< FEC_OPD.OPCODE Position                 */
#define FEC_OPD_OPCODE(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< FEC_OPD.OPCODE Field                    */
/* ------- IAUR Bit Fields                          ------ */
#define FEC_IAUR_IADDR1_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_IAUR.IADDR1 Mask                    */
#define FEC_IAUR_IADDR1_SHIFT                    (0U)                                                /*!< FEC_IAUR.IADDR1 Position                */
#define FEC_IAUR_IADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IAUR.IADDR1 Field                   */
/* ------- IALR Bit Fields                          ------ */
#define FEC_IALR_IADDR2_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_IALR.IADDR2 Mask                    */
#define FEC_IALR_IADDR2_SHIFT                    (0U)                                                /*!< FEC_IALR.IADDR2 Position                */
#define FEC_IALR_IADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IALR.IADDR2 Field                   */
/* ------- GAUR Bit Fields                          ------ */
#define FEC_GAUR_GADDR1_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_GAUR.GADDR1 Mask                    */
#define FEC_GAUR_GADDR1_SHIFT                    (0U)                                                /*!< FEC_GAUR.GADDR1 Position                */
#define FEC_GAUR_GADDR1(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_GAUR.GADDR1 Field                   */
/* ------- GALR Bit Fields                          ------ */
#define FEC_GALR_GADDR2_MASK                     (0xFFFFFFFFU)                                       /*!< FEC_GALR.GADDR2 Mask                    */
#define FEC_GALR_GADDR2_SHIFT                    (0U)                                                /*!< FEC_GALR.GADDR2 Position                */
#define FEC_GALR_GADDR2(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_GALR.GADDR2 Field                   */
/* ------- TFWR Bit Fields                          ------ */
#define FEC_TFWR_X_WMRK_MASK                     (0x3U)                                              /*!< FEC_TFWR.X_WMRK Mask                    */
#define FEC_TFWR_X_WMRK_SHIFT                    (0U)                                                /*!< FEC_TFWR.X_WMRK Position                */
#define FEC_TFWR_X_WMRK(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< FEC_TFWR.X_WMRK Field                   */
/* ------- FRBR Bit Fields                          ------ */
#define FEC_FRBR_R_BOUND_MASK                    (0x3FCU)                                            /*!< FEC_FRBR.R_BOUND Mask                   */
#define FEC_FRBR_R_BOUND_SHIFT                   (2U)                                                /*!< FEC_FRBR.R_BOUND Position               */
#define FEC_FRBR_R_BOUND(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x3FCUL)         /*!< FEC_FRBR.R_BOUND Field                  */
/* ------- FRSR Bit Fields                          ------ */
#define FEC_FRSR_R_FSTART_MASK                   (0x3FCU)                                            /*!< FEC_FRSR.R_FSTART Mask                  */
#define FEC_FRSR_R_FSTART_SHIFT                  (2U)                                                /*!< FEC_FRSR.R_FSTART Position              */
#define FEC_FRSR_R_FSTART(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x3FCUL)         /*!< FEC_FRSR.R_FSTART Field                 */
/* ------- ERDSR Bit Fields                         ------ */
#define FEC_ERDSR_R_DES_START_MASK               (0xFFFFFFFCU)                                       /*!< FEC_ERDSR.R_DES_START Mask              */
#define FEC_ERDSR_R_DES_START_SHIFT              (2U)                                                /*!< FEC_ERDSR.R_DES_START Position          */
#define FEC_ERDSR_R_DES_START(x)                 (((uint32_t)(((uint32_t)(x))<<2U))&0xFFFFFFFCUL)    /*!< FEC_ERDSR.R_DES_START Field             */
/* ------- ETSDR Bit Fields                         ------ */
#define FEC_ETSDR_X_DES_START_MASK               (0xFFFFFFFCU)                                       /*!< FEC_ETSDR.X_DES_START Mask              */
#define FEC_ETSDR_X_DES_START_SHIFT              (2U)                                                /*!< FEC_ETSDR.X_DES_START Position          */
#define FEC_ETSDR_X_DES_START(x)                 (((uint32_t)(((uint32_t)(x))<<2U))&0xFFFFFFFCUL)    /*!< FEC_ETSDR.X_DES_START Field             */
/* ------- EMRBR Bit Fields                         ------ */
#define FEC_EMRBR_R_BUF_SIZE_MASK                (0x7F0U)                                            /*!< FEC_EMRBR.R_BUF_SIZE Mask               */
#define FEC_EMRBR_R_BUF_SIZE_SHIFT               (4U)                                                /*!< FEC_EMRBR.R_BUF_SIZE Position           */
#define FEC_EMRBR_R_BUF_SIZE(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x7F0UL)         /*!< FEC_EMRBR.R_BUF_SIZE Field              */
/* ------- RMON_T_DROP Bit Fields                   ------ */
#define FEC_RMON_T_DROP_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_DROP.Value Mask              */
#define FEC_RMON_T_DROP_Value_SHIFT              (0U)                                                /*!< FEC_RMON_T_DROP.Value Position          */
#define FEC_RMON_T_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_DROP.Value Field             */
/* ------- RMON_T_PACKETS Bit Fields                ------ */
#define FEC_RMON_T_PACKETS_Value_MASK            (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_PACKETS.Value Mask           */
#define FEC_RMON_T_PACKETS_Value_SHIFT           (0U)                                                /*!< FEC_RMON_T_PACKETS.Value Position       */
#define FEC_RMON_T_PACKETS_Value(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_PACKETS.Value Field          */
/* ------- RMON_T_BC_PKT Bit Fields                 ------ */
#define FEC_RMON_T_BC_PKT_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_BC_PKT.Value Mask            */
#define FEC_RMON_T_BC_PKT_Value_SHIFT            (0U)                                                /*!< FEC_RMON_T_BC_PKT.Value Position        */
#define FEC_RMON_T_BC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_BC_PKT.Value Field           */
/* ------- RMON_T_MC_PKT Bit Fields                 ------ */
#define FEC_RMON_T_MC_PKT_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_MC_PKT.Value Mask            */
#define FEC_RMON_T_MC_PKT_Value_SHIFT            (0U)                                                /*!< FEC_RMON_T_MC_PKT.Value Position        */
#define FEC_RMON_T_MC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_MC_PKT.Value Field           */
/* ------- RMON_T_CRC_ALIGN Bit Fields              ------ */
#define FEC_RMON_T_CRC_ALIGN_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_CRC_ALIGN.Value Mask         */
#define FEC_RMON_T_CRC_ALIGN_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_CRC_ALIGN.Value Position     */
#define FEC_RMON_T_CRC_ALIGN_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_CRC_ALIGN.Value Field        */
/* ------- RMON_T_UNDERSIZE Bit Fields              ------ */
#define FEC_RMON_T_UNDERSIZE_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_UNDERSIZE.Value Mask         */
#define FEC_RMON_T_UNDERSIZE_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_UNDERSIZE.Value Position     */
#define FEC_RMON_T_UNDERSIZE_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_UNDERSIZE.Value Field        */
/* ------- RMON_T_OVERSIZE Bit Fields               ------ */
#define FEC_RMON_T_OVERSIZE_Value_MASK           (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_OVERSIZE.Value Mask          */
#define FEC_RMON_T_OVERSIZE_Value_SHIFT          (0U)                                                /*!< FEC_RMON_T_OVERSIZE.Value Position      */
#define FEC_RMON_T_OVERSIZE_Value(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_OVERSIZE.Value Field         */
/* ------- RMON_T_FRAG Bit Fields                   ------ */
#define FEC_RMON_T_FRAG_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_FRAG.Value Mask              */
#define FEC_RMON_T_FRAG_Value_SHIFT              (0U)                                                /*!< FEC_RMON_T_FRAG.Value Position          */
#define FEC_RMON_T_FRAG_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_FRAG.Value Field             */
/* ------- RMON_T_JAB Bit Fields                    ------ */
#define FEC_RMON_T_JAB_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_JAB.Value Mask               */
#define FEC_RMON_T_JAB_Value_SHIFT               (0U)                                                /*!< FEC_RMON_T_JAB.Value Position           */
#define FEC_RMON_T_JAB_Value(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_JAB.Value Field              */
/* ------- RMON_T_COL Bit Fields                    ------ */
#define FEC_RMON_T_COL_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_COL.Value Mask               */
#define FEC_RMON_T_COL_Value_SHIFT               (0U)                                                /*!< FEC_RMON_T_COL.Value Position           */
#define FEC_RMON_T_COL_Value(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_COL.Value Field              */
/* ------- RMON_T_P6 Bit Fields                     ------ */
#define FEC_RMON_T_P6_Value_MASK                 (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P6.Value Mask                */
#define FEC_RMON_T_P6_Value_SHIFT                (0U)                                                /*!< FEC_RMON_T_P6.Value Position            */
#define FEC_RMON_T_P6_Value(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_P6.Value Field               */
/* ------- RMON_T_P128TO255 Bit Fields              ------ */
#define FEC_RMON_T_P128TO255_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P128TO255.Value Mask         */
#define FEC_RMON_T_P128TO255_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_P128TO255.Value Position     */
#define FEC_RMON_T_P128TO255_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_P128TO255.Value Field        */
/* ------- RMON_T_P256TO511 Bit Fields              ------ */
#define FEC_RMON_T_P256TO511_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P256TO511.Value Mask         */
#define FEC_RMON_T_P256TO511_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_P256TO511.Value Position     */
#define FEC_RMON_T_P256TO511_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_P256TO511.Value Field        */
/* ------- RMON_T_P512TO1023 Bit Fields             ------ */
#define FEC_RMON_T_P512TO1023_Value_MASK         (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P512TO1023.Value Mask        */
#define FEC_RMON_T_P512TO1023_Value_SHIFT        (0U)                                                /*!< FEC_RMON_T_P512TO1023.Value Position    */
#define FEC_RMON_T_P512TO1023_Value(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_P512TO1023.Value Field       */
/* ------- RMON_T_P1024TO2047 Bit Fields            ------ */
#define FEC_RMON_T_P1024TO2047_Value_MASK        (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P1024TO2047.Value Mask       */
#define FEC_RMON_T_P1024TO2047_Value_SHIFT       (0U)                                                /*!< FEC_RMON_T_P1024TO2047.Value Position   */
#define FEC_RMON_T_P1024TO2047_Value(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_P1024TO2047.Value Field      */
/* ------- RMON_T_P_GTE2048 Bit Fields              ------ */
#define FEC_RMON_T_P_GTE2048_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_P_GTE2048.Value Mask         */
#define FEC_RMON_T_P_GTE2048_Value_SHIFT         (0U)                                                /*!< FEC_RMON_T_P_GTE2048.Value Position     */
#define FEC_RMON_T_P_GTE2048_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_P_GTE2048.Value Field        */
/* ------- RMON_T_OCTETS Bit Fields                 ------ */
#define FEC_RMON_T_OCTETS_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_T_OCTETS.Value Mask            */
#define FEC_RMON_T_OCTETS_Value_SHIFT            (0U)                                                /*!< FEC_RMON_T_OCTETS.Value Position        */
#define FEC_RMON_T_OCTETS_Value(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_T_OCTETS.Value Field           */
/* ------- IEEE_T_DROP Bit Fields                   ------ */
#define FEC_IEEE_T_DROP_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_DROP.Value Mask              */
#define FEC_IEEE_T_DROP_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_T_DROP.Value Position          */
#define FEC_IEEE_T_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_DROP.Value Field             */
/* ------- IEEE_T_FRAME_OK Bit Fields               ------ */
#define FEC_IEEE_T_FRAME_OK_Value_MASK           (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_FRAME_OK.Value Mask          */
#define FEC_IEEE_T_FRAME_OK_Value_SHIFT          (0U)                                                /*!< FEC_IEEE_T_FRAME_OK.Value Position      */
#define FEC_IEEE_T_FRAME_OK_Value(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_FRAME_OK.Value Field         */
/* ------- IEEE_T_1COL Bit Fields                   ------ */
#define FEC_IEEE_T_1COL_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_1COL.Value Mask              */
#define FEC_IEEE_T_1COL_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_T_1COL.Value Position          */
#define FEC_IEEE_T_1COL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_1COL.Value Field             */
/* ------- IEEE_T_MCOL Bit Fields                   ------ */
#define FEC_IEEE_T_MCOL_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_MCOL.Value Mask              */
#define FEC_IEEE_T_MCOL_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_T_MCOL.Value Position          */
#define FEC_IEEE_T_MCOL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_MCOL.Value Field             */
/* ------- IEEE_T_DEF Bit Fields                    ------ */
#define FEC_IEEE_T_DEF_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_DEF.Value Mask               */
#define FEC_IEEE_T_DEF_Value_SHIFT               (0U)                                                /*!< FEC_IEEE_T_DEF.Value Position           */
#define FEC_IEEE_T_DEF_Value(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_DEF.Value Field              */
/* ------- IEEE_T_LCOL Bit Fields                   ------ */
#define FEC_IEEE_T_LCOL_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_LCOL.Value Mask              */
#define FEC_IEEE_T_LCOL_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_T_LCOL.Value Position          */
#define FEC_IEEE_T_LCOL_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_LCOL.Value Field             */
/* ------- IEEE_T_EXCOL Bit Fields                  ------ */
#define FEC_IEEE_T_EXCOL_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_EXCOL.Value Mask             */
#define FEC_IEEE_T_EXCOL_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_T_EXCOL.Value Position         */
#define FEC_IEEE_T_EXCOL_Value(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_EXCOL.Value Field            */
/* ------- IEEE_T_MACERR Bit Fields                 ------ */
#define FEC_IEEE_T_MACERR_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_MACERR.Value Mask            */
#define FEC_IEEE_T_MACERR_Value_SHIFT            (0U)                                                /*!< FEC_IEEE_T_MACERR.Value Position        */
#define FEC_IEEE_T_MACERR_Value(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_MACERR.Value Field           */
/* ------- IEEE_T_CSERR Bit Fields                  ------ */
#define FEC_IEEE_T_CSERR_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_CSERR.Value Mask             */
#define FEC_IEEE_T_CSERR_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_T_CSERR.Value Position         */
#define FEC_IEEE_T_CSERR_Value(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_CSERR.Value Field            */
/* ------- IEEE_T_SQE Bit Fields                    ------ */
#define FEC_IEEE_T_SQE_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_SQE.Value Mask               */
#define FEC_IEEE_T_SQE_Value_SHIFT               (0U)                                                /*!< FEC_IEEE_T_SQE.Value Position           */
#define FEC_IEEE_T_SQE_Value(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_SQE.Value Field              */
/* ------- IEEE_T_FDXFC Bit Fields                  ------ */
#define FEC_IEEE_T_FDXFC_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_FDXFC.Value Mask             */
#define FEC_IEEE_T_FDXFC_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_T_FDXFC.Value Position         */
#define FEC_IEEE_T_FDXFC_Value(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_FDXFC.Value Field            */
/* ------- IEEE_T_OCTETS_OK Bit Fields              ------ */
#define FEC_IEEE_T_OCTETS_OK_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_IEEE_T_OCTETS_OK.Value Mask         */
#define FEC_IEEE_T_OCTETS_OK_Value_SHIFT         (0U)                                                /*!< FEC_IEEE_T_OCTETS_OK.Value Position     */
#define FEC_IEEE_T_OCTETS_OK_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_T_OCTETS_OK.Value Field        */
/* ------- RMON_R_DROP Bit Fields                   ------ */
#define FEC_RMON_R_DROP_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_DROP.Value Mask              */
#define FEC_RMON_R_DROP_Value_SHIFT              (0U)                                                /*!< FEC_RMON_R_DROP.Value Position          */
#define FEC_RMON_R_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_DROP.Value Field             */
/* ------- RMON_R_PACKETS Bit Fields                ------ */
#define FEC_RMON_R_PACKETS_Value_MASK            (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_PACKETS.Value Mask           */
#define FEC_RMON_R_PACKETS_Value_SHIFT           (0U)                                                /*!< FEC_RMON_R_PACKETS.Value Position       */
#define FEC_RMON_R_PACKETS_Value(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_PACKETS.Value Field          */
/* ------- RMON_R_BC_PKT Bit Fields                 ------ */
#define FEC_RMON_R_BC_PKT_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_BC_PKT.Value Mask            */
#define FEC_RMON_R_BC_PKT_Value_SHIFT            (0U)                                                /*!< FEC_RMON_R_BC_PKT.Value Position        */
#define FEC_RMON_R_BC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_BC_PKT.Value Field           */
/* ------- RMON_R_MC_PKT Bit Fields                 ------ */
#define FEC_RMON_R_MC_PKT_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_MC_PKT.Value Mask            */
#define FEC_RMON_R_MC_PKT_Value_SHIFT            (0U)                                                /*!< FEC_RMON_R_MC_PKT.Value Position        */
#define FEC_RMON_R_MC_PKT_Value(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_MC_PKT.Value Field           */
/* ------- RMON_R_CRC_ALIGN Bit Fields              ------ */
#define FEC_RMON_R_CRC_ALIGN_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_CRC_ALIGN.Value Mask         */
#define FEC_RMON_R_CRC_ALIGN_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_CRC_ALIGN.Value Position     */
#define FEC_RMON_R_CRC_ALIGN_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_CRC_ALIGN.Value Field        */
/* ------- RMON_R_UNDERSIZE Bit Fields              ------ */
#define FEC_RMON_R_UNDERSIZE_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_UNDERSIZE.Value Mask         */
#define FEC_RMON_R_UNDERSIZE_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_UNDERSIZE.Value Position     */
#define FEC_RMON_R_UNDERSIZE_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_UNDERSIZE.Value Field        */
/* ------- RMON_R_OVERSIZE Bit Fields               ------ */
#define FEC_RMON_R_OVERSIZE_Value_MASK           (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_OVERSIZE.Value Mask          */
#define FEC_RMON_R_OVERSIZE_Value_SHIFT          (0U)                                                /*!< FEC_RMON_R_OVERSIZE.Value Position      */
#define FEC_RMON_R_OVERSIZE_Value(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_OVERSIZE.Value Field         */
/* ------- RMON_R_FRAG Bit Fields                   ------ */
#define FEC_RMON_R_FRAG_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_FRAG.Value Mask              */
#define FEC_RMON_R_FRAG_Value_SHIFT              (0U)                                                /*!< FEC_RMON_R_FRAG.Value Position          */
#define FEC_RMON_R_FRAG_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_FRAG.Value Field             */
/* ------- RMON_R_JAB Bit Fields                    ------ */
#define FEC_RMON_R_JAB_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_JAB.Value Mask               */
#define FEC_RMON_R_JAB_Value_SHIFT               (0U)                                                /*!< FEC_RMON_R_JAB.Value Position           */
#define FEC_RMON_R_JAB_Value(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_JAB.Value Field              */
/* ------- RMON_R_RESVD_0 Bit Fields                ------ */
#define FEC_RMON_R_RESVD_0_Value_MASK            (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_RESVD_0.Value Mask           */
#define FEC_RMON_R_RESVD_0_Value_SHIFT           (0U)                                                /*!< FEC_RMON_R_RESVD_0.Value Position       */
#define FEC_RMON_R_RESVD_0_Value(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_RESVD_0.Value Field          */
/* ------- RMON_R_P6 Bit Fields                     ------ */
#define FEC_RMON_R_P6_Value_MASK                 (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P6.Value Mask                */
#define FEC_RMON_R_P6_Value_SHIFT                (0U)                                                /*!< FEC_RMON_R_P6.Value Position            */
#define FEC_RMON_R_P6_Value(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_P6.Value Field               */
/* ------- RMON_R_P128TO255 Bit Fields              ------ */
#define FEC_RMON_R_P128TO255_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P128TO255.Value Mask         */
#define FEC_RMON_R_P128TO255_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_P128TO255.Value Position     */
#define FEC_RMON_R_P128TO255_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_P128TO255.Value Field        */
/* ------- RMON_R_P256TO511 Bit Fields              ------ */
#define FEC_RMON_R_P256TO511_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P256TO511.Value Mask         */
#define FEC_RMON_R_P256TO511_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_P256TO511.Value Position     */
#define FEC_RMON_R_P256TO511_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_P256TO511.Value Field        */
/* ------- RMON_R_P512TO1023 Bit Fields             ------ */
#define FEC_RMON_R_P512TO1023_Value_MASK         (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P512TO1023.Value Mask        */
#define FEC_RMON_R_P512TO1023_Value_SHIFT        (0U)                                                /*!< FEC_RMON_R_P512TO1023.Value Position    */
#define FEC_RMON_R_P512TO1023_Value(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_P512TO1023.Value Field       */
/* ------- RMON_R_P1024TO2047 Bit Fields            ------ */
#define FEC_RMON_R_P1024TO2047_Value_MASK        (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P1024TO2047.Value Mask       */
#define FEC_RMON_R_P1024TO2047_Value_SHIFT       (0U)                                                /*!< FEC_RMON_R_P1024TO2047.Value Position   */
#define FEC_RMON_R_P1024TO2047_Value(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_P1024TO2047.Value Field      */
/* ------- RMON_R_P_GTE2048 Bit Fields              ------ */
#define FEC_RMON_R_P_GTE2048_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_P_GTE2048.Value Mask         */
#define FEC_RMON_R_P_GTE2048_Value_SHIFT         (0U)                                                /*!< FEC_RMON_R_P_GTE2048.Value Position     */
#define FEC_RMON_R_P_GTE2048_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_P_GTE2048.Value Field        */
/* ------- RMON_R_OCTETS Bit Fields                 ------ */
#define FEC_RMON_R_OCTETS_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_RMON_R_OCTETS.Value Mask            */
#define FEC_RMON_R_OCTETS_Value_SHIFT            (0U)                                                /*!< FEC_RMON_R_OCTETS.Value Position        */
#define FEC_RMON_R_OCTETS_Value(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_RMON_R_OCTETS.Value Field           */
/* ------- IEEE_R_DROP Bit Fields                   ------ */
#define FEC_IEEE_R_DROP_Value_MASK               (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_DROP.Value Mask              */
#define FEC_IEEE_R_DROP_Value_SHIFT              (0U)                                                /*!< FEC_IEEE_R_DROP.Value Position          */
#define FEC_IEEE_R_DROP_Value(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_R_DROP.Value Field             */
/* ------- IEEE_R_FRAME_OK Bit Fields               ------ */
#define FEC_IEEE_R_FRAME_OK_Value_MASK           (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_FRAME_OK.Value Mask          */
#define FEC_IEEE_R_FRAME_OK_Value_SHIFT          (0U)                                                /*!< FEC_IEEE_R_FRAME_OK.Value Position      */
#define FEC_IEEE_R_FRAME_OK_Value(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_R_FRAME_OK.Value Field         */
/* ------- IEEE_R_CRC Bit Fields                    ------ */
#define FEC_IEEE_R_CRC_Value_MASK                (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_CRC.Value Mask               */
#define FEC_IEEE_R_CRC_Value_SHIFT               (0U)                                                /*!< FEC_IEEE_R_CRC.Value Position           */
#define FEC_IEEE_R_CRC_Value(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_R_CRC.Value Field              */
/* ------- IEEE_R_ALIGN Bit Fields                  ------ */
#define FEC_IEEE_R_ALIGN_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_ALIGN.Value Mask             */
#define FEC_IEEE_R_ALIGN_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_R_ALIGN.Value Position         */
#define FEC_IEEE_R_ALIGN_Value(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_R_ALIGN.Value Field            */
/* ------- IEEE_R_MACERR Bit Fields                 ------ */
#define FEC_IEEE_R_MACERR_Value_MASK             (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_MACERR.Value Mask            */
#define FEC_IEEE_R_MACERR_Value_SHIFT            (0U)                                                /*!< FEC_IEEE_R_MACERR.Value Position        */
#define FEC_IEEE_R_MACERR_Value(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_R_MACERR.Value Field           */
/* ------- IEEE_R_FDXFC Bit Fields                  ------ */
#define FEC_IEEE_R_FDXFC_Value_MASK              (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_FDXFC.Value Mask             */
#define FEC_IEEE_R_FDXFC_Value_SHIFT             (0U)                                                /*!< FEC_IEEE_R_FDXFC.Value Position         */
#define FEC_IEEE_R_FDXFC_Value(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_R_FDXFC.Value Field            */
/* ------- IEEE_R_OCTETS_OK Bit Fields              ------ */
#define FEC_IEEE_R_OCTETS_OK_Value_MASK          (0xFFFFFFFFU)                                       /*!< FEC_IEEE_R_OCTETS_OK.Value Mask         */
#define FEC_IEEE_R_OCTETS_OK_Value_SHIFT         (0U)                                                /*!< FEC_IEEE_R_OCTETS_OK.Value Position     */
#define FEC_IEEE_R_OCTETS_OK_Value(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FEC_IEEE_R_OCTETS_OK.Value Field        */
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
* @addtogroup FlexCAN_Peripheral_access_layer_GROUP FlexCAN Peripheral Access Layer
* @brief C Struct for FlexCAN
* @{
*/

/* ================================================================================ */
/* ================           FlexCAN (file:MCF52259_FlexCAN)       ================ */
/* ================================================================================ */

/**
 * @brief FlexCAN Module
 */
/**
* @addtogroup FlexCAN_structs_GROUP FlexCAN struct
* @brief Struct for FlexCAN
* @{
*/
typedef struct FlexCAN_Type {
   __IO uint32_t  CANMCR;                       /**< 0000: FlexCAN Configuration                                        */
   __IO uint32_t  CANCTRL;                      /**< 0004: FlexCAN Control                                              */
   __IO uint32_t  TIMER;                        /**< 0008: Free Running Timer                                           */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  RXGMASK;                      /**< 0010: Rx Global Mask                                               */
   __IO uint32_t  RX14MASK;                     /**< 0014: Rx Buffer 14 Mask                                            */
   __IO uint32_t  RX15MASK;                     /**< 0018: Rx Buffer 15 Mask                                            */
   __IO uint32_t  ERRCNT;                       /**< 001C: Error Counter                                                */
   __IO uint32_t  ERRSTAT;                      /**< 0020: Error and Status                                             */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  IMASK;                        /**< 0028: Interrupt Masks                                              */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  IFLAG;                        /**< 0030: Interrupt Flags                                              */
} FlexCAN_Type;

/**
 * @} */ /* End group FlexCAN_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FlexCAN' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FlexCAN_Register_Masks_GROUP FlexCAN Register Masks
* @brief Register Masks for FlexCAN
* @{
*/
/* ------- CANMCR Bit Fields                        ------ */
#define FlexCAN_CANMCR_MAXMB_MASK                (0xFU)                                              /*!< FlexCAN_CANMCR.MAXMB Mask               */
#define FlexCAN_CANMCR_MAXMB_SHIFT               (0U)                                                /*!< FlexCAN_CANMCR.MAXMB Position           */
#define FlexCAN_CANMCR_MAXMB(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< FlexCAN_CANMCR.MAXMB Field              */
#define FlexCAN_CANMCR_LPMACK_MASK               (0x100000U)                                         /*!< FlexCAN_CANMCR.LPMACK Mask              */
#define FlexCAN_CANMCR_LPMACK_SHIFT              (20U)                                               /*!< FlexCAN_CANMCR.LPMACK Position          */
#define FlexCAN_CANMCR_LPMACK(x)                 (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< FlexCAN_CANMCR.LPMACK Field             */
#define FlexCAN_CANMCR_SUPV_MASK                 (0x800000U)                                         /*!< FlexCAN_CANMCR.SUPV Mask                */
#define FlexCAN_CANMCR_SUPV_SHIFT                (23U)                                               /*!< FlexCAN_CANMCR.SUPV Position            */
#define FlexCAN_CANMCR_SUPV(x)                   (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< FlexCAN_CANMCR.SUPV Field               */
#define FlexCAN_CANMCR_FRZACK_MASK               (0x1000000U)                                        /*!< FlexCAN_CANMCR.FRZACK Mask              */
#define FlexCAN_CANMCR_FRZACK_SHIFT              (24U)                                               /*!< FlexCAN_CANMCR.FRZACK Position          */
#define FlexCAN_CANMCR_FRZACK(x)                 (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< FlexCAN_CANMCR.FRZACK Field             */
#define FlexCAN_CANMCR_SOFTRST_MASK              (0x2000000U)                                        /*!< FlexCAN_CANMCR.SOFTRST Mask             */
#define FlexCAN_CANMCR_SOFTRST_SHIFT             (25U)                                               /*!< FlexCAN_CANMCR.SOFTRST Position         */
#define FlexCAN_CANMCR_SOFTRST(x)                (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< FlexCAN_CANMCR.SOFTRST Field            */
#define FlexCAN_CANMCR_NOTRDY_MASK               (0x8000000U)                                        /*!< FlexCAN_CANMCR.NOTRDY Mask              */
#define FlexCAN_CANMCR_NOTRDY_SHIFT              (27U)                                               /*!< FlexCAN_CANMCR.NOTRDY Position          */
#define FlexCAN_CANMCR_NOTRDY(x)                 (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< FlexCAN_CANMCR.NOTRDY Field             */
#define FlexCAN_CANMCR_HALT_MASK                 (0x10000000U)                                       /*!< FlexCAN_CANMCR.HALT Mask                */
#define FlexCAN_CANMCR_HALT_SHIFT                (28U)                                               /*!< FlexCAN_CANMCR.HALT Position            */
#define FlexCAN_CANMCR_HALT(x)                   (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< FlexCAN_CANMCR.HALT Field               */
#define FlexCAN_CANMCR_FRZ_MASK                  (0x40000000U)                                       /*!< FlexCAN_CANMCR.FRZ Mask                 */
#define FlexCAN_CANMCR_FRZ_SHIFT                 (30U)                                               /*!< FlexCAN_CANMCR.FRZ Position             */
#define FlexCAN_CANMCR_FRZ(x)                    (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< FlexCAN_CANMCR.FRZ Field                */
#define FlexCAN_CANMCR_MDIS_MASK                 (0x80000000U)                                       /*!< FlexCAN_CANMCR.MDIS Mask                */
#define FlexCAN_CANMCR_MDIS_SHIFT                (31U)                                               /*!< FlexCAN_CANMCR.MDIS Position            */
#define FlexCAN_CANMCR_MDIS(x)                   (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< FlexCAN_CANMCR.MDIS Field               */
/* ------- CANCTRL Bit Fields                       ------ */
#define FlexCAN_CANCTRL_PROPSEG_MASK             (0x7U)                                              /*!< FlexCAN_CANCTRL.PROPSEG Mask            */
#define FlexCAN_CANCTRL_PROPSEG_SHIFT            (0U)                                                /*!< FlexCAN_CANCTRL.PROPSEG Position        */
#define FlexCAN_CANCTRL_PROPSEG(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< FlexCAN_CANCTRL.PROPSEG Field           */
#define FlexCAN_CANCTRL_LOM_MASK                 (0x8U)                                              /*!< FlexCAN_CANCTRL.LOM Mask                */
#define FlexCAN_CANCTRL_LOM_SHIFT                (3U)                                                /*!< FlexCAN_CANCTRL.LOM Position            */
#define FlexCAN_CANCTRL_LOM(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FlexCAN_CANCTRL.LOM Field               */
#define FlexCAN_CANCTRL_LBUF_MASK                (0x10U)                                             /*!< FlexCAN_CANCTRL.LBUF Mask               */
#define FlexCAN_CANCTRL_LBUF_SHIFT               (4U)                                                /*!< FlexCAN_CANCTRL.LBUF Position           */
#define FlexCAN_CANCTRL_LBUF(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FlexCAN_CANCTRL.LBUF Field              */
#define FlexCAN_CANCTRL_TSYNC_MASK               (0x20U)                                             /*!< FlexCAN_CANCTRL.TSYNC Mask              */
#define FlexCAN_CANCTRL_TSYNC_SHIFT              (5U)                                                /*!< FlexCAN_CANCTRL.TSYNC Position          */
#define FlexCAN_CANCTRL_TSYNC(x)                 (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FlexCAN_CANCTRL.TSYNC Field             */
#define FlexCAN_CANCTRL_BOFFREC_MASK             (0x40U)                                             /*!< FlexCAN_CANCTRL.BOFFREC Mask            */
#define FlexCAN_CANCTRL_BOFFREC_SHIFT            (6U)                                                /*!< FlexCAN_CANCTRL.BOFFREC Position        */
#define FlexCAN_CANCTRL_BOFFREC(x)               (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FlexCAN_CANCTRL.BOFFREC Field           */
#define FlexCAN_CANCTRL_SMP_MASK                 (0x80U)                                             /*!< FlexCAN_CANCTRL.SMP Mask                */
#define FlexCAN_CANCTRL_SMP_SHIFT                (7U)                                                /*!< FlexCAN_CANCTRL.SMP Position            */
#define FlexCAN_CANCTRL_SMP(x)                   (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FlexCAN_CANCTRL.SMP Field               */
#define FlexCAN_CANCTRL_LPB_MASK                 (0x1000U)                                           /*!< FlexCAN_CANCTRL.LPB Mask                */
#define FlexCAN_CANCTRL_LPB_SHIFT                (12U)                                               /*!< FlexCAN_CANCTRL.LPB Position            */
#define FlexCAN_CANCTRL_LPB(x)                   (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< FlexCAN_CANCTRL.LPB Field               */
#define FlexCAN_CANCTRL_CLK_SRC_MASK             (0x2000U)                                           /*!< FlexCAN_CANCTRL.CLK_SRC Mask            */
#define FlexCAN_CANCTRL_CLK_SRC_SHIFT            (13U)                                               /*!< FlexCAN_CANCTRL.CLK_SRC Position        */
#define FlexCAN_CANCTRL_CLK_SRC(x)               (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< FlexCAN_CANCTRL.CLK_SRC Field           */
#define FlexCAN_CANCTRL_ERRMSK_MASK              (0x4000U)                                           /*!< FlexCAN_CANCTRL.ERRMSK Mask             */
#define FlexCAN_CANCTRL_ERRMSK_SHIFT             (14U)                                               /*!< FlexCAN_CANCTRL.ERRMSK Position         */
#define FlexCAN_CANCTRL_ERRMSK(x)                (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< FlexCAN_CANCTRL.ERRMSK Field            */
#define FlexCAN_CANCTRL_BOFFMSK_MASK             (0x8000U)                                           /*!< FlexCAN_CANCTRL.BOFFMSK Mask            */
#define FlexCAN_CANCTRL_BOFFMSK_SHIFT            (15U)                                               /*!< FlexCAN_CANCTRL.BOFFMSK Position        */
#define FlexCAN_CANCTRL_BOFFMSK(x)               (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< FlexCAN_CANCTRL.BOFFMSK Field           */
#define FlexCAN_CANCTRL_PSEG2_MASK               (0x70000U)                                          /*!< FlexCAN_CANCTRL.PSEG2 Mask              */
#define FlexCAN_CANCTRL_PSEG2_SHIFT              (16U)                                               /*!< FlexCAN_CANCTRL.PSEG2 Position          */
#define FlexCAN_CANCTRL_PSEG2(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0x70000UL)      /*!< FlexCAN_CANCTRL.PSEG2 Field             */
#define FlexCAN_CANCTRL_PSEG1_MASK               (0x380000U)                                         /*!< FlexCAN_CANCTRL.PSEG1 Mask              */
#define FlexCAN_CANCTRL_PSEG1_SHIFT              (19U)                                               /*!< FlexCAN_CANCTRL.PSEG1 Position          */
#define FlexCAN_CANCTRL_PSEG1(x)                 (((uint32_t)(((uint32_t)(x))<<19U))&0x380000UL)     /*!< FlexCAN_CANCTRL.PSEG1 Field             */
#define FlexCAN_CANCTRL_RJW_MASK                 (0xC00000U)                                         /*!< FlexCAN_CANCTRL.RJW Mask                */
#define FlexCAN_CANCTRL_RJW_SHIFT                (22U)                                               /*!< FlexCAN_CANCTRL.RJW Position            */
#define FlexCAN_CANCTRL_RJW(x)                   (((uint32_t)(((uint32_t)(x))<<22U))&0xC00000UL)     /*!< FlexCAN_CANCTRL.RJW Field               */
#define FlexCAN_CANCTRL_PRESDIV_MASK             (0xFF000000U)                                       /*!< FlexCAN_CANCTRL.PRESDIV Mask            */
#define FlexCAN_CANCTRL_PRESDIV_SHIFT            (24U)                                               /*!< FlexCAN_CANCTRL.PRESDIV Position        */
#define FlexCAN_CANCTRL_PRESDIV(x)               (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< FlexCAN_CANCTRL.PRESDIV Field           */
/* ------- TIMER Bit Fields                         ------ */
#define FlexCAN_TIMER_TIMER_MASK                 (0xFFFFU)                                           /*!< FlexCAN_TIMER.TIMER Mask                */
#define FlexCAN_TIMER_TIMER_SHIFT                (0U)                                                /*!< FlexCAN_TIMER.TIMER Position            */
#define FlexCAN_TIMER_TIMER(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FlexCAN_TIMER.TIMER Field               */
/* ------- RXGMASK Bit Fields                       ------ */
#define FlexCAN_RXGMASK_MI_MASK                  (0x1FFFFFFFU)                                       /*!< FlexCAN_RXGMASK.MI Mask                 */
#define FlexCAN_RXGMASK_MI_SHIFT                 (0U)                                                /*!< FlexCAN_RXGMASK.MI Position             */
#define FlexCAN_RXGMASK_MI(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFFFFFUL)    /*!< FlexCAN_RXGMASK.MI Field                */
/* ------- RX14MASK Bit Fields                      ------ */
#define FlexCAN_RX14MASK_MI_MASK                 (0x1FFFFFFFU)                                       /*!< FlexCAN_RX14MASK.MI Mask                */
#define FlexCAN_RX14MASK_MI_SHIFT                (0U)                                                /*!< FlexCAN_RX14MASK.MI Position            */
#define FlexCAN_RX14MASK_MI(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFFFFFUL)    /*!< FlexCAN_RX14MASK.MI Field               */
/* ------- RX15MASK Bit Fields                      ------ */
#define FlexCAN_RX15MASK_MI_MASK                 (0x1FFFFFFFU)                                       /*!< FlexCAN_RX15MASK.MI Mask                */
#define FlexCAN_RX15MASK_MI_SHIFT                (0U)                                                /*!< FlexCAN_RX15MASK.MI Position            */
#define FlexCAN_RX15MASK_MI(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFFFFFUL)    /*!< FlexCAN_RX15MASK.MI Field               */
/* ------- ERRCNT Bit Fields                        ------ */
#define FlexCAN_ERRCNT_TXECTR_MASK               (0xFFU)                                             /*!< FlexCAN_ERRCNT.TXECTR Mask              */
#define FlexCAN_ERRCNT_TXECTR_SHIFT              (0U)                                                /*!< FlexCAN_ERRCNT.TXECTR Position          */
#define FlexCAN_ERRCNT_TXECTR(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FlexCAN_ERRCNT.TXECTR Field             */
#define FlexCAN_ERRCNT_RXECTR_MASK               (0xFF00U)                                           /*!< FlexCAN_ERRCNT.RXECTR Mask              */
#define FlexCAN_ERRCNT_RXECTR_SHIFT              (8U)                                                /*!< FlexCAN_ERRCNT.RXECTR Position          */
#define FlexCAN_ERRCNT_RXECTR(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< FlexCAN_ERRCNT.RXECTR Field             */
/* ------- ERRSTAT Bit Fields                       ------ */
#define FlexCAN_ERRSTAT_ERRINT_MASK              (0x2U)                                              /*!< FlexCAN_ERRSTAT.ERRINT Mask             */
#define FlexCAN_ERRSTAT_ERRINT_SHIFT             (1U)                                                /*!< FlexCAN_ERRSTAT.ERRINT Position         */
#define FlexCAN_ERRSTAT_ERRINT(x)                (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FlexCAN_ERRSTAT.ERRINT Field            */
#define FlexCAN_ERRSTAT_BOFFINT_MASK             (0x4U)                                              /*!< FlexCAN_ERRSTAT.BOFFINT Mask            */
#define FlexCAN_ERRSTAT_BOFFINT_SHIFT            (2U)                                                /*!< FlexCAN_ERRSTAT.BOFFINT Position        */
#define FlexCAN_ERRSTAT_BOFFINT(x)               (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FlexCAN_ERRSTAT.BOFFINT Field           */
#define FlexCAN_ERRSTAT_FLTCONF_MASK             (0x30U)                                             /*!< FlexCAN_ERRSTAT.FLTCONF Mask            */
#define FlexCAN_ERRSTAT_FLTCONF_SHIFT            (4U)                                                /*!< FlexCAN_ERRSTAT.FLTCONF Position        */
#define FlexCAN_ERRSTAT_FLTCONF(x)               (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< FlexCAN_ERRSTAT.FLTCONF Field           */
#define FlexCAN_ERRSTAT_TXRX_MASK                (0x40U)                                             /*!< FlexCAN_ERRSTAT.TXRX Mask               */
#define FlexCAN_ERRSTAT_TXRX_SHIFT               (6U)                                                /*!< FlexCAN_ERRSTAT.TXRX Position           */
#define FlexCAN_ERRSTAT_TXRX(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FlexCAN_ERRSTAT.TXRX Field              */
#define FlexCAN_ERRSTAT_IDLE_MASK                (0x80U)                                             /*!< FlexCAN_ERRSTAT.IDLE Mask               */
#define FlexCAN_ERRSTAT_IDLE_SHIFT               (7U)                                                /*!< FlexCAN_ERRSTAT.IDLE Position           */
#define FlexCAN_ERRSTAT_IDLE(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FlexCAN_ERRSTAT.IDLE Field              */
#define FlexCAN_ERRSTAT_RXWRN_MASK               (0x100U)                                            /*!< FlexCAN_ERRSTAT.RXWRN Mask              */
#define FlexCAN_ERRSTAT_RXWRN_SHIFT              (8U)                                                /*!< FlexCAN_ERRSTAT.RXWRN Position          */
#define FlexCAN_ERRSTAT_RXWRN(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FlexCAN_ERRSTAT.RXWRN Field             */
#define FlexCAN_ERRSTAT_TXWRN_MASK               (0x200U)                                            /*!< FlexCAN_ERRSTAT.TXWRN Mask              */
#define FlexCAN_ERRSTAT_TXWRN_SHIFT              (9U)                                                /*!< FlexCAN_ERRSTAT.TXWRN Position          */
#define FlexCAN_ERRSTAT_TXWRN(x)                 (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FlexCAN_ERRSTAT.TXWRN Field             */
#define FlexCAN_ERRSTAT_STFERR_MASK              (0x400U)                                            /*!< FlexCAN_ERRSTAT.STFERR Mask             */
#define FlexCAN_ERRSTAT_STFERR_SHIFT             (10U)                                               /*!< FlexCAN_ERRSTAT.STFERR Position         */
#define FlexCAN_ERRSTAT_STFERR(x)                (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< FlexCAN_ERRSTAT.STFERR Field            */
#define FlexCAN_ERRSTAT_FRMERR_MASK              (0x800U)                                            /*!< FlexCAN_ERRSTAT.FRMERR Mask             */
#define FlexCAN_ERRSTAT_FRMERR_SHIFT             (11U)                                               /*!< FlexCAN_ERRSTAT.FRMERR Position         */
#define FlexCAN_ERRSTAT_FRMERR(x)                (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< FlexCAN_ERRSTAT.FRMERR Field            */
#define FlexCAN_ERRSTAT_CRCERR_MASK              (0x1000U)                                           /*!< FlexCAN_ERRSTAT.CRCERR Mask             */
#define FlexCAN_ERRSTAT_CRCERR_SHIFT             (12U)                                               /*!< FlexCAN_ERRSTAT.CRCERR Position         */
#define FlexCAN_ERRSTAT_CRCERR(x)                (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< FlexCAN_ERRSTAT.CRCERR Field            */
#define FlexCAN_ERRSTAT_ACKERR_MASK              (0x2000U)                                           /*!< FlexCAN_ERRSTAT.ACKERR Mask             */
#define FlexCAN_ERRSTAT_ACKERR_SHIFT             (13U)                                               /*!< FlexCAN_ERRSTAT.ACKERR Position         */
#define FlexCAN_ERRSTAT_ACKERR(x)                (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< FlexCAN_ERRSTAT.ACKERR Field            */
#define FlexCAN_ERRSTAT_BIT0ERR_MASK             (0x4000U)                                           /*!< FlexCAN_ERRSTAT.BIT0ERR Mask            */
#define FlexCAN_ERRSTAT_BIT0ERR_SHIFT            (14U)                                               /*!< FlexCAN_ERRSTAT.BIT0ERR Position        */
#define FlexCAN_ERRSTAT_BIT0ERR(x)               (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< FlexCAN_ERRSTAT.BIT0ERR Field           */
#define FlexCAN_ERRSTAT_BIT1ERR_MASK             (0x8000U)                                           /*!< FlexCAN_ERRSTAT.BIT1ERR Mask            */
#define FlexCAN_ERRSTAT_BIT1ERR_SHIFT            (15U)                                               /*!< FlexCAN_ERRSTAT.BIT1ERR Position        */
#define FlexCAN_ERRSTAT_BIT1ERR(x)               (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< FlexCAN_ERRSTAT.BIT1ERR Field           */
/* ------- IMASK Bit Fields                         ------ */
#define FlexCAN_IMASK_BUF0M_MASK                 (0x1U)                                              /*!< FlexCAN_IMASK.BUF0M Mask                */
#define FlexCAN_IMASK_BUF0M_SHIFT                (0U)                                                /*!< FlexCAN_IMASK.BUF0M Position            */
#define FlexCAN_IMASK_BUF0M(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FlexCAN_IMASK.BUF0M Field               */
#define FlexCAN_IMASK_BUF1M_MASK                 (0x2U)                                              /*!< FlexCAN_IMASK.BUF1M Mask                */
#define FlexCAN_IMASK_BUF1M_SHIFT                (1U)                                                /*!< FlexCAN_IMASK.BUF1M Position            */
#define FlexCAN_IMASK_BUF1M(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FlexCAN_IMASK.BUF1M Field               */
#define FlexCAN_IMASK_BUF2M_MASK                 (0x4U)                                              /*!< FlexCAN_IMASK.BUF2M Mask                */
#define FlexCAN_IMASK_BUF2M_SHIFT                (2U)                                                /*!< FlexCAN_IMASK.BUF2M Position            */
#define FlexCAN_IMASK_BUF2M(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FlexCAN_IMASK.BUF2M Field               */
#define FlexCAN_IMASK_BUF3M_MASK                 (0x8U)                                              /*!< FlexCAN_IMASK.BUF3M Mask                */
#define FlexCAN_IMASK_BUF3M_SHIFT                (3U)                                                /*!< FlexCAN_IMASK.BUF3M Position            */
#define FlexCAN_IMASK_BUF3M(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FlexCAN_IMASK.BUF3M Field               */
#define FlexCAN_IMASK_BUF4M_MASK                 (0x10U)                                             /*!< FlexCAN_IMASK.BUF4M Mask                */
#define FlexCAN_IMASK_BUF4M_SHIFT                (4U)                                                /*!< FlexCAN_IMASK.BUF4M Position            */
#define FlexCAN_IMASK_BUF4M(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FlexCAN_IMASK.BUF4M Field               */
#define FlexCAN_IMASK_BUF5M_MASK                 (0x20U)                                             /*!< FlexCAN_IMASK.BUF5M Mask                */
#define FlexCAN_IMASK_BUF5M_SHIFT                (5U)                                                /*!< FlexCAN_IMASK.BUF5M Position            */
#define FlexCAN_IMASK_BUF5M(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FlexCAN_IMASK.BUF5M Field               */
#define FlexCAN_IMASK_BUF6M_MASK                 (0x40U)                                             /*!< FlexCAN_IMASK.BUF6M Mask                */
#define FlexCAN_IMASK_BUF6M_SHIFT                (6U)                                                /*!< FlexCAN_IMASK.BUF6M Position            */
#define FlexCAN_IMASK_BUF6M(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FlexCAN_IMASK.BUF6M Field               */
#define FlexCAN_IMASK_BUF7M_MASK                 (0x80U)                                             /*!< FlexCAN_IMASK.BUF7M Mask                */
#define FlexCAN_IMASK_BUF7M_SHIFT                (7U)                                                /*!< FlexCAN_IMASK.BUF7M Position            */
#define FlexCAN_IMASK_BUF7M(x)                   (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FlexCAN_IMASK.BUF7M Field               */
#define FlexCAN_IMASK_BUF8M_MASK                 (0x100U)                                            /*!< FlexCAN_IMASK.BUF8M Mask                */
#define FlexCAN_IMASK_BUF8M_SHIFT                (8U)                                                /*!< FlexCAN_IMASK.BUF8M Position            */
#define FlexCAN_IMASK_BUF8M(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FlexCAN_IMASK.BUF8M Field               */
#define FlexCAN_IMASK_BUF9M_MASK                 (0x200U)                                            /*!< FlexCAN_IMASK.BUF9M Mask                */
#define FlexCAN_IMASK_BUF9M_SHIFT                (9U)                                                /*!< FlexCAN_IMASK.BUF9M Position            */
#define FlexCAN_IMASK_BUF9M(x)                   (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FlexCAN_IMASK.BUF9M Field               */
#define FlexCAN_IMASK_BUF10M_MASK                (0x400U)                                            /*!< FlexCAN_IMASK.BUF10M Mask               */
#define FlexCAN_IMASK_BUF10M_SHIFT               (10U)                                               /*!< FlexCAN_IMASK.BUF10M Position           */
#define FlexCAN_IMASK_BUF10M(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< FlexCAN_IMASK.BUF10M Field              */
#define FlexCAN_IMASK_BUF11M_MASK                (0x800U)                                            /*!< FlexCAN_IMASK.BUF11M Mask               */
#define FlexCAN_IMASK_BUF11M_SHIFT               (11U)                                               /*!< FlexCAN_IMASK.BUF11M Position           */
#define FlexCAN_IMASK_BUF11M(x)                  (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< FlexCAN_IMASK.BUF11M Field              */
#define FlexCAN_IMASK_BUF12M_MASK                (0x1000U)                                           /*!< FlexCAN_IMASK.BUF12M Mask               */
#define FlexCAN_IMASK_BUF12M_SHIFT               (12U)                                               /*!< FlexCAN_IMASK.BUF12M Position           */
#define FlexCAN_IMASK_BUF12M(x)                  (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< FlexCAN_IMASK.BUF12M Field              */
#define FlexCAN_IMASK_BUF13M_MASK                (0x2000U)                                           /*!< FlexCAN_IMASK.BUF13M Mask               */
#define FlexCAN_IMASK_BUF13M_SHIFT               (13U)                                               /*!< FlexCAN_IMASK.BUF13M Position           */
#define FlexCAN_IMASK_BUF13M(x)                  (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< FlexCAN_IMASK.BUF13M Field              */
#define FlexCAN_IMASK_BUF14M_MASK                (0x4000U)                                           /*!< FlexCAN_IMASK.BUF14M Mask               */
#define FlexCAN_IMASK_BUF14M_SHIFT               (14U)                                               /*!< FlexCAN_IMASK.BUF14M Position           */
#define FlexCAN_IMASK_BUF14M(x)                  (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< FlexCAN_IMASK.BUF14M Field              */
#define FlexCAN_IMASK_BUF15M_MASK                (0x8000U)                                           /*!< FlexCAN_IMASK.BUF15M Mask               */
#define FlexCAN_IMASK_BUF15M_SHIFT               (15U)                                               /*!< FlexCAN_IMASK.BUF15M Position           */
#define FlexCAN_IMASK_BUF15M(x)                  (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< FlexCAN_IMASK.BUF15M Field              */
/* ------- IFLAG Bit Fields                         ------ */
#define FlexCAN_IFLAG_BUF0I_MASK                 (0x1U)                                              /*!< FlexCAN_IFLAG.BUF0I Mask                */
#define FlexCAN_IFLAG_BUF0I_SHIFT                (0U)                                                /*!< FlexCAN_IFLAG.BUF0I Position            */
#define FlexCAN_IFLAG_BUF0I(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FlexCAN_IFLAG.BUF0I Field               */
#define FlexCAN_IFLAG_BUF1I_MASK                 (0x2U)                                              /*!< FlexCAN_IFLAG.BUF1I Mask                */
#define FlexCAN_IFLAG_BUF1I_SHIFT                (1U)                                                /*!< FlexCAN_IFLAG.BUF1I Position            */
#define FlexCAN_IFLAG_BUF1I(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FlexCAN_IFLAG.BUF1I Field               */
#define FlexCAN_IFLAG_BUF2I_MASK                 (0x4U)                                              /*!< FlexCAN_IFLAG.BUF2I Mask                */
#define FlexCAN_IFLAG_BUF2I_SHIFT                (2U)                                                /*!< FlexCAN_IFLAG.BUF2I Position            */
#define FlexCAN_IFLAG_BUF2I(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FlexCAN_IFLAG.BUF2I Field               */
#define FlexCAN_IFLAG_BUF3I_MASK                 (0x8U)                                              /*!< FlexCAN_IFLAG.BUF3I Mask                */
#define FlexCAN_IFLAG_BUF3I_SHIFT                (3U)                                                /*!< FlexCAN_IFLAG.BUF3I Position            */
#define FlexCAN_IFLAG_BUF3I(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FlexCAN_IFLAG.BUF3I Field               */
#define FlexCAN_IFLAG_BUF4I_MASK                 (0x10U)                                             /*!< FlexCAN_IFLAG.BUF4I Mask                */
#define FlexCAN_IFLAG_BUF4I_SHIFT                (4U)                                                /*!< FlexCAN_IFLAG.BUF4I Position            */
#define FlexCAN_IFLAG_BUF4I(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FlexCAN_IFLAG.BUF4I Field               */
#define FlexCAN_IFLAG_BUF5I_MASK                 (0x20U)                                             /*!< FlexCAN_IFLAG.BUF5I Mask                */
#define FlexCAN_IFLAG_BUF5I_SHIFT                (5U)                                                /*!< FlexCAN_IFLAG.BUF5I Position            */
#define FlexCAN_IFLAG_BUF5I(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FlexCAN_IFLAG.BUF5I Field               */
#define FlexCAN_IFLAG_BUF6I_MASK                 (0x40U)                                             /*!< FlexCAN_IFLAG.BUF6I Mask                */
#define FlexCAN_IFLAG_BUF6I_SHIFT                (6U)                                                /*!< FlexCAN_IFLAG.BUF6I Position            */
#define FlexCAN_IFLAG_BUF6I(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FlexCAN_IFLAG.BUF6I Field               */
#define FlexCAN_IFLAG_BUF7I_MASK                 (0x80U)                                             /*!< FlexCAN_IFLAG.BUF7I Mask                */
#define FlexCAN_IFLAG_BUF7I_SHIFT                (7U)                                                /*!< FlexCAN_IFLAG.BUF7I Position            */
#define FlexCAN_IFLAG_BUF7I(x)                   (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FlexCAN_IFLAG.BUF7I Field               */
#define FlexCAN_IFLAG_BUF8I_MASK                 (0x100U)                                            /*!< FlexCAN_IFLAG.BUF8I Mask                */
#define FlexCAN_IFLAG_BUF8I_SHIFT                (8U)                                                /*!< FlexCAN_IFLAG.BUF8I Position            */
#define FlexCAN_IFLAG_BUF8I(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FlexCAN_IFLAG.BUF8I Field               */
#define FlexCAN_IFLAG_BUF9I_MASK                 (0x200U)                                            /*!< FlexCAN_IFLAG.BUF9I Mask                */
#define FlexCAN_IFLAG_BUF9I_SHIFT                (9U)                                                /*!< FlexCAN_IFLAG.BUF9I Position            */
#define FlexCAN_IFLAG_BUF9I(x)                   (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FlexCAN_IFLAG.BUF9I Field               */
#define FlexCAN_IFLAG_BUF10I_MASK                (0x400U)                                            /*!< FlexCAN_IFLAG.BUF10I Mask               */
#define FlexCAN_IFLAG_BUF10I_SHIFT               (10U)                                               /*!< FlexCAN_IFLAG.BUF10I Position           */
#define FlexCAN_IFLAG_BUF10I(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< FlexCAN_IFLAG.BUF10I Field              */
#define FlexCAN_IFLAG_BUF11I_MASK                (0x800U)                                            /*!< FlexCAN_IFLAG.BUF11I Mask               */
#define FlexCAN_IFLAG_BUF11I_SHIFT               (11U)                                               /*!< FlexCAN_IFLAG.BUF11I Position           */
#define FlexCAN_IFLAG_BUF11I(x)                  (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< FlexCAN_IFLAG.BUF11I Field              */
#define FlexCAN_IFLAG_BUF12I_MASK                (0x1000U)                                           /*!< FlexCAN_IFLAG.BUF12I Mask               */
#define FlexCAN_IFLAG_BUF12I_SHIFT               (12U)                                               /*!< FlexCAN_IFLAG.BUF12I Position           */
#define FlexCAN_IFLAG_BUF12I(x)                  (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< FlexCAN_IFLAG.BUF12I Field              */
#define FlexCAN_IFLAG_BUF13I_MASK                (0x2000U)                                           /*!< FlexCAN_IFLAG.BUF13I Mask               */
#define FlexCAN_IFLAG_BUF13I_SHIFT               (13U)                                               /*!< FlexCAN_IFLAG.BUF13I Position           */
#define FlexCAN_IFLAG_BUF13I(x)                  (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< FlexCAN_IFLAG.BUF13I Field              */
#define FlexCAN_IFLAG_BUF14I_MASK                (0x4000U)                                           /*!< FlexCAN_IFLAG.BUF14I Mask               */
#define FlexCAN_IFLAG_BUF14I_SHIFT               (14U)                                               /*!< FlexCAN_IFLAG.BUF14I Position           */
#define FlexCAN_IFLAG_BUF14I(x)                  (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< FlexCAN_IFLAG.BUF14I Field              */
#define FlexCAN_IFLAG_BUF15I_MASK                (0x8000U)                                           /*!< FlexCAN_IFLAG.BUF15I Mask               */
#define FlexCAN_IFLAG_BUF15I_SHIFT               (15U)                                               /*!< FlexCAN_IFLAG.BUF15I Position           */
#define FlexCAN_IFLAG_BUF15I(x)                  (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< FlexCAN_IFLAG.BUF15I Field              */
/**
 * @} */ /* End group FlexCAN_Register_Masks_GROUP 
 */

/* FlexCAN - Peripheral instance base addresses */
#define FlexCAN_BasePtr                0x40170000UL //!< Peripheral base address
#define FlexCAN                        ((FlexCAN_Type *) FlexCAN_BasePtr) //!< Freescale base pointer
#define FlexCAN_BASE_PTR               (FlexCAN) //!< Freescale style base pointer
/**
 * @} */ /* End group FlexCAN_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIO (file:MCF52259_GPIO)            ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O Port
 */
/**
* @addtogroup GPIO_structs_GROUP GPIO struct
* @brief Struct for GPIO
* @{
*/
typedef struct GPIO_Type {
   __IO uint8_t   PORTTE;                       /**< 0000: Data register                                                */
   __IO uint8_t   PORTTF;                       /**< 0001: Data register                                                */
   __IO uint8_t   PORTTG;                       /**< 0002: Data register                                                */
   __IO uint8_t   PORTTH;                       /**< 0003: Data register                                                */
   __IO uint8_t   PORTTI;                       /**< 0004: Data register                                                */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   PORTTJ;                       /**< 0006: Data register                                                */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   PORTNQ;                       /**< 0008: Data register                                                */
        uint8_t   RESERVED_2;                  
   __IO uint8_t   PORTAN;                       /**< 000A: Data register                                                */
   __IO uint8_t   PORTAS;                       /**< 000B: Data register                                                */
   __IO uint8_t   PORTQS;                       /**< 000C: Data register                                                */
        uint8_t   RESERVED_3;                  
   __IO uint8_t   PORTTA;                       /**< 000E: Data register                                                */
   __IO uint8_t   PORTTC;                       /**< 000F: Data register                                                */
        uint8_t   RESERVED_4;                  
   __IO uint8_t   PORTUA;                       /**< 0011: Data register                                                */
   __IO uint8_t   PORTUB;                       /**< 0012: Data register                                                */
   __IO uint8_t   PORTUC;                       /**< 0013: Data register                                                */
   __IO uint8_t   PORTDD;                       /**< 0014: Data register                                                */
        uint8_t   RESERVED_5[3];               
   __IO uint8_t   DDRTE;                        /**< 0018: Direction register                                           */
   __IO uint8_t   DDRTF;                        /**< 0019: Direction register                                           */
   __IO uint8_t   DDRTG;                        /**< 001A: Direction register                                           */
   __IO uint8_t   DDRTH;                        /**< 001B: Direction register                                           */
   __IO uint8_t   DDRTI;                        /**< 001C: Direction register                                           */
        uint8_t   RESERVED_6;                  
   __IO uint8_t   DDRTJ;                        /**< 001E: Direction register                                           */
        uint8_t   RESERVED_7;                  
   __IO uint8_t   DDRNQ;                        /**< 0020: Direction register                                           */
        uint8_t   RESERVED_8;                  
   __IO uint8_t   DDRAN;                        /**< 0022: Direction register                                           */
   __IO uint8_t   DDRAS;                        /**< 0023: Direction register                                           */
   __IO uint8_t   DDRQS;                        /**< 0024: Direction register                                           */
        uint8_t   RESERVED_9;                  
   __IO uint8_t   DDRTA;                        /**< 0026: Direction register                                           */
   __IO uint8_t   DDRTC;                        /**< 0027: Direction register                                           */
        uint8_t   RESERVED_10;                 
   __IO uint8_t   DDRUA;                        /**< 0029: Direction register                                           */
   __IO uint8_t   DDRUB;                        /**< 002A: Direction register                                           */
   __IO uint8_t   DDRUC;                        /**< 002B: Direction register                                           */
   __IO uint8_t   DDRDD;                        /**< 002C: Direction register                                           */
        uint8_t   RESERVED_11[3];              
   __IO uint8_t   SETTE;                        /**< 0030: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTF;                        /**< 0031: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTG;                        /**< 0032: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTH;                        /**< 0033: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTI;                        /**< 0034: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_12;                 
   __IO uint8_t   SETTJ;                        /**< 0036: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_13;                 
   __IO uint8_t   SETNQ;                        /**< 0038: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_14;                 
   __IO uint8_t   SETAN;                        /**< 003A: Pin Data/Set Registers                                       */
   __IO uint8_t   SETAS;                        /**< 003B: Pin Data/Set Registers                                       */
   __IO uint8_t   SETQS;                        /**< 003C: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_15;                 
   __IO uint8_t   SETTA;                        /**< 003E: Pin Data/Set Registers                                       */
   __IO uint8_t   SETTC;                        /**< 003F: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_16;                 
   __IO uint8_t   SETUA;                        /**< 0041: Pin Data/Set Registers                                       */
   __IO uint8_t   SETUB;                        /**< 0042: Pin Data/Set Registers                                       */
   __IO uint8_t   SETUC;                        /**< 0043: Pin Data/Set Registers                                       */
   __IO uint8_t   SETDD;                        /**< 0044: Pin Data/Set Registers                                       */
        uint8_t   RESERVED_17[3];              
   __O  uint8_t   CLRTE;                        /**< 0048: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTF;                        /**< 0049: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTG;                        /**< 004A: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTH;                        /**< 004B: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTI;                        /**< 004C: Port Clear Output Data Register                              */
        uint8_t   RESERVED_18;                 
   __O  uint8_t   CLRTJ;                        /**< 004E: Port Clear Output Data Register                              */
        uint8_t   RESERVED_19;                 
   __O  uint8_t   CLRNQ;                        /**< 0050: Port Clear Output Data Register                              */
        uint8_t   RESERVED_20;                 
   __O  uint8_t   CLRAN;                        /**< 0052: Port Clear Output Data Register                              */
   __O  uint8_t   CLRAS;                        /**< 0053: Port Clear Output Data Register                              */
   __O  uint8_t   CLRQS;                        /**< 0054: Port Clear Output Data Register                              */
        uint8_t   RESERVED_21;                 
   __O  uint8_t   CLRTA;                        /**< 0056: Port Clear Output Data Register                              */
   __O  uint8_t   CLRTC;                        /**< 0057: Port Clear Output Data Register                              */
        uint8_t   RESERVED_22;                 
   __O  uint8_t   CLRUA;                        /**< 0059: Port Clear Output Data Register                              */
   __O  uint8_t   CLRUB;                        /**< 005A: Port Clear Output Data Register                              */
   __O  uint8_t   CLRUC;                        /**< 005B: Port Clear Output Data Register                              */
   __O  uint8_t   CLRDD;                        /**< 005C: Port Clear Output Data Register                              */
        uint8_t   RESERVED_23[3];              
   __IO uint8_t   PARTE;                        /**< 0060: Pin Configuration                                            */
   __IO uint8_t   PARTF;                        /**< 0061: Pin Configuration                                            */
   __IO uint8_t   PARTG;                        /**< 0062: Pin Configuration                                            */
        uint8_t   RESERVED_24;                 
   __IO uint8_t   PARTI;                        /**< 0064: Pin Configuration                                            */
        uint8_t   RESERVED_25;                 
   __IO uint8_t   PARTJ;                        /**< 0066: Pin Configuration                                            */
        uint8_t   RESERVED_26;                 
   __IO uint16_t  QPARNQ;                       /**< 0068: Pin Configuration                                            */
   __IO uint8_t   PARAN;                        /**< 006A: Pin Configuration                                            */
   __IO uint8_t   QPARAS;                       /**< 006B: Pin Configuration                                            */
   __IO uint16_t  QPARQS;                       /**< 006C: Pin Configuration                                            */
   __IO uint8_t   QPARTA;                       /**< 006E: Pin Configuration                                            */
   __IO uint8_t   QPARTC;                       /**< 006F: Pin Configuration                                            */
        uint8_t   RESERVED_27;                 
   __IO uint8_t   QPARUA;                       /**< 0071: Pin Configuration                                            */
   __IO uint8_t   QPARUB;                       /**< 0072: Pin Configuration                                            */
   __IO uint8_t   QPARUC;                       /**< 0073: Pin Configuration                                            */
   __IO uint8_t   PARDD;                        /**< 0074: Pin Configuration                                            */
        uint8_t   RESERVED_28[27];             
   __IO uint16_t  QPARTH;                       /**< 0090: Pin Configuration                                            */
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
/* ------- PORTTE Bit Fields                        ------ */
#define GPIO_PORT_PORT0_MASK                     (0x1U)                                              /*!< GPIO_PORTTE.PORT0 Mask                  */
#define GPIO_PORT_PORT0_SHIFT                    (0U)                                                /*!< GPIO_PORTTE.PORT0 Position              */
#define GPIO_PORT_PORT0(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPIO_PORTTE.PORT0 Field                 */
#define GPIO_PORT_PORT1_MASK                     (0x2U)                                              /*!< GPIO_PORTTE.PORT1 Mask                  */
#define GPIO_PORT_PORT1_SHIFT                    (1U)                                                /*!< GPIO_PORTTE.PORT1 Position              */
#define GPIO_PORT_PORT1(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPIO_PORTTE.PORT1 Field                 */
#define GPIO_PORT_PORT2_MASK                     (0x4U)                                              /*!< GPIO_PORTTE.PORT2 Mask                  */
#define GPIO_PORT_PORT2_SHIFT                    (2U)                                                /*!< GPIO_PORTTE.PORT2 Position              */
#define GPIO_PORT_PORT2(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPIO_PORTTE.PORT2 Field                 */
#define GPIO_PORT_PORT3_MASK                     (0x8U)                                              /*!< GPIO_PORTTE.PORT3 Mask                  */
#define GPIO_PORT_PORT3_SHIFT                    (3U)                                                /*!< GPIO_PORTTE.PORT3 Position              */
#define GPIO_PORT_PORT3(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPIO_PORTTE.PORT3 Field                 */
#define GPIO_PORT_PORT4_MASK                     (0x10U)                                             /*!< GPIO_PORTTE.PORT4 Mask                  */
#define GPIO_PORT_PORT4_SHIFT                    (4U)                                                /*!< GPIO_PORTTE.PORT4 Position              */
#define GPIO_PORT_PORT4(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPIO_PORTTE.PORT4 Field                 */
#define GPIO_PORT_PORT5_MASK                     (0x20U)                                             /*!< GPIO_PORTTE.PORT5 Mask                  */
#define GPIO_PORT_PORT5_SHIFT                    (5U)                                                /*!< GPIO_PORTTE.PORT5 Position              */
#define GPIO_PORT_PORT5(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPIO_PORTTE.PORT5 Field                 */
#define GPIO_PORT_PORT6_MASK                     (0x40U)                                             /*!< GPIO_PORTTE.PORT6 Mask                  */
#define GPIO_PORT_PORT6_SHIFT                    (6U)                                                /*!< GPIO_PORTTE.PORT6 Position              */
#define GPIO_PORT_PORT6(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< GPIO_PORTTE.PORT6 Field                 */
#define GPIO_PORT_PORT7_MASK                     (0x80U)                                             /*!< GPIO_PORTTE.PORT7 Mask                  */
#define GPIO_PORT_PORT7_SHIFT                    (7U)                                                /*!< GPIO_PORTTE.PORT7 Position              */
#define GPIO_PORT_PORT7(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPIO_PORTTE.PORT7 Field                 */
/* ------- PORTTF Bit Fields                        ------ */
/* ------- PORTTG Bit Fields                        ------ */
/* ------- PORTTH Bit Fields                        ------ */
/* ------- PORTTI Bit Fields                        ------ */
/* ------- PORTTJ Bit Fields                        ------ */
/* ------- PORTNQ Bit Fields                        ------ */
/* ------- PORTAN Bit Fields                        ------ */
/* ------- PORTAS Bit Fields                        ------ */
/* ------- PORTQS Bit Fields                        ------ */
/* ------- PORTTA Bit Fields                        ------ */
/* ------- PORTTC Bit Fields                        ------ */
/* ------- PORTUA Bit Fields                        ------ */
/* ------- PORTUB Bit Fields                        ------ */
/* ------- PORTUC Bit Fields                        ------ */
/* ------- PORTDD Bit Fields                        ------ */
/* ------- DDRTE Bit Fields                         ------ */
#define GPIO_DDR_DDR0_MASK                       (0x1U)                                              /*!< GPIO_DDRTE.DDR0 Mask                    */
#define GPIO_DDR_DDR0_SHIFT                      (0U)                                                /*!< GPIO_DDRTE.DDR0 Position                */
#define GPIO_DDR_DDR0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPIO_DDRTE.DDR0 Field                   */
#define GPIO_DDR_DDR1_MASK                       (0x2U)                                              /*!< GPIO_DDRTE.DDR1 Mask                    */
#define GPIO_DDR_DDR1_SHIFT                      (1U)                                                /*!< GPIO_DDRTE.DDR1 Position                */
#define GPIO_DDR_DDR1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPIO_DDRTE.DDR1 Field                   */
#define GPIO_DDR_DDR2_MASK                       (0x4U)                                              /*!< GPIO_DDRTE.DDR2 Mask                    */
#define GPIO_DDR_DDR2_SHIFT                      (2U)                                                /*!< GPIO_DDRTE.DDR2 Position                */
#define GPIO_DDR_DDR2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPIO_DDRTE.DDR2 Field                   */
#define GPIO_DDR_DDR3_MASK                       (0x8U)                                              /*!< GPIO_DDRTE.DDR3 Mask                    */
#define GPIO_DDR_DDR3_SHIFT                      (3U)                                                /*!< GPIO_DDRTE.DDR3 Position                */
#define GPIO_DDR_DDR3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPIO_DDRTE.DDR3 Field                   */
#define GPIO_DDR_DDR4_MASK                       (0x10U)                                             /*!< GPIO_DDRTE.DDR4 Mask                    */
#define GPIO_DDR_DDR4_SHIFT                      (4U)                                                /*!< GPIO_DDRTE.DDR4 Position                */
#define GPIO_DDR_DDR4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPIO_DDRTE.DDR4 Field                   */
#define GPIO_DDR_DDR5_MASK                       (0x20U)                                             /*!< GPIO_DDRTE.DDR5 Mask                    */
#define GPIO_DDR_DDR5_SHIFT                      (5U)                                                /*!< GPIO_DDRTE.DDR5 Position                */
#define GPIO_DDR_DDR5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPIO_DDRTE.DDR5 Field                   */
#define GPIO_DDR_DDR6_MASK                       (0x40U)                                             /*!< GPIO_DDRTE.DDR6 Mask                    */
#define GPIO_DDR_DDR6_SHIFT                      (6U)                                                /*!< GPIO_DDRTE.DDR6 Position                */
#define GPIO_DDR_DDR6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< GPIO_DDRTE.DDR6 Field                   */
#define GPIO_DDR_DDR7_MASK                       (0x80U)                                             /*!< GPIO_DDRTE.DDR7 Mask                    */
#define GPIO_DDR_DDR7_SHIFT                      (7U)                                                /*!< GPIO_DDRTE.DDR7 Position                */
#define GPIO_DDR_DDR7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPIO_DDRTE.DDR7 Field                   */
/* ------- DDRTF Bit Fields                         ------ */
/* ------- DDRTG Bit Fields                         ------ */
/* ------- DDRTH Bit Fields                         ------ */
/* ------- DDRTI Bit Fields                         ------ */
/* ------- DDRTJ Bit Fields                         ------ */
/* ------- DDRNQ Bit Fields                         ------ */
/* ------- DDRAN Bit Fields                         ------ */
/* ------- DDRAS Bit Fields                         ------ */
/* ------- DDRQS Bit Fields                         ------ */
/* ------- DDRTA Bit Fields                         ------ */
/* ------- DDRTC Bit Fields                         ------ */
/* ------- DDRUA Bit Fields                         ------ */
/* ------- DDRUB Bit Fields                         ------ */
/* ------- DDRUC Bit Fields                         ------ */
/* ------- DDRDD Bit Fields                         ------ */
/* ------- SETTE Bit Fields                         ------ */
#define GPIO_SET_SET0_MASK                       (0x1U)                                              /*!< GPIO_SETTE.SET0 Mask                    */
#define GPIO_SET_SET0_SHIFT                      (0U)                                                /*!< GPIO_SETTE.SET0 Position                */
#define GPIO_SET_SET0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPIO_SETTE.SET0 Field                   */
#define GPIO_SET_SET1_MASK                       (0x2U)                                              /*!< GPIO_SETTE.SET1 Mask                    */
#define GPIO_SET_SET1_SHIFT                      (1U)                                                /*!< GPIO_SETTE.SET1 Position                */
#define GPIO_SET_SET1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPIO_SETTE.SET1 Field                   */
#define GPIO_SET_SET2_MASK                       (0x4U)                                              /*!< GPIO_SETTE.SET2 Mask                    */
#define GPIO_SET_SET2_SHIFT                      (2U)                                                /*!< GPIO_SETTE.SET2 Position                */
#define GPIO_SET_SET2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPIO_SETTE.SET2 Field                   */
#define GPIO_SET_SET3_MASK                       (0x8U)                                              /*!< GPIO_SETTE.SET3 Mask                    */
#define GPIO_SET_SET3_SHIFT                      (3U)                                                /*!< GPIO_SETTE.SET3 Position                */
#define GPIO_SET_SET3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPIO_SETTE.SET3 Field                   */
#define GPIO_SET_SET4_MASK                       (0x10U)                                             /*!< GPIO_SETTE.SET4 Mask                    */
#define GPIO_SET_SET4_SHIFT                      (4U)                                                /*!< GPIO_SETTE.SET4 Position                */
#define GPIO_SET_SET4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPIO_SETTE.SET4 Field                   */
#define GPIO_SET_SET5_MASK                       (0x20U)                                             /*!< GPIO_SETTE.SET5 Mask                    */
#define GPIO_SET_SET5_SHIFT                      (5U)                                                /*!< GPIO_SETTE.SET5 Position                */
#define GPIO_SET_SET5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPIO_SETTE.SET5 Field                   */
#define GPIO_SET_SET6_MASK                       (0x40U)                                             /*!< GPIO_SETTE.SET6 Mask                    */
#define GPIO_SET_SET6_SHIFT                      (6U)                                                /*!< GPIO_SETTE.SET6 Position                */
#define GPIO_SET_SET6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< GPIO_SETTE.SET6 Field                   */
#define GPIO_SET_SET7_MASK                       (0x80U)                                             /*!< GPIO_SETTE.SET7 Mask                    */
#define GPIO_SET_SET7_SHIFT                      (7U)                                                /*!< GPIO_SETTE.SET7 Position                */
#define GPIO_SET_SET7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPIO_SETTE.SET7 Field                   */
/* ------- SETTF Bit Fields                         ------ */
/* ------- SETTG Bit Fields                         ------ */
/* ------- SETTH Bit Fields                         ------ */
/* ------- SETTI Bit Fields                         ------ */
/* ------- SETTJ Bit Fields                         ------ */
/* ------- SETNQ Bit Fields                         ------ */
/* ------- SETAN Bit Fields                         ------ */
/* ------- SETAS Bit Fields                         ------ */
/* ------- SETQS Bit Fields                         ------ */
/* ------- SETTA Bit Fields                         ------ */
/* ------- SETTC Bit Fields                         ------ */
/* ------- SETUA Bit Fields                         ------ */
/* ------- SETUB Bit Fields                         ------ */
/* ------- SETUC Bit Fields                         ------ */
/* ------- SETDD Bit Fields                         ------ */
/* ------- CLRTE Bit Fields                         ------ */
#define GPIO_CLR_CLR0_MASK                       (0x1U)                                              /*!< GPIO_CLRTE.CLR0 Mask                    */
#define GPIO_CLR_CLR0_SHIFT                      (0U)                                                /*!< GPIO_CLRTE.CLR0 Position                */
#define GPIO_CLR_CLR0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPIO_CLRTE.CLR0 Field                   */
#define GPIO_CLR_CLR1_MASK                       (0x2U)                                              /*!< GPIO_CLRTE.CLR1 Mask                    */
#define GPIO_CLR_CLR1_SHIFT                      (1U)                                                /*!< GPIO_CLRTE.CLR1 Position                */
#define GPIO_CLR_CLR1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPIO_CLRTE.CLR1 Field                   */
#define GPIO_CLR_CLR2_MASK                       (0x4U)                                              /*!< GPIO_CLRTE.CLR2 Mask                    */
#define GPIO_CLR_CLR2_SHIFT                      (2U)                                                /*!< GPIO_CLRTE.CLR2 Position                */
#define GPIO_CLR_CLR2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPIO_CLRTE.CLR2 Field                   */
#define GPIO_CLR_CLR3_MASK                       (0x8U)                                              /*!< GPIO_CLRTE.CLR3 Mask                    */
#define GPIO_CLR_CLR3_SHIFT                      (3U)                                                /*!< GPIO_CLRTE.CLR3 Position                */
#define GPIO_CLR_CLR3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPIO_CLRTE.CLR3 Field                   */
#define GPIO_CLR_CLR4_MASK                       (0x10U)                                             /*!< GPIO_CLRTE.CLR4 Mask                    */
#define GPIO_CLR_CLR4_SHIFT                      (4U)                                                /*!< GPIO_CLRTE.CLR4 Position                */
#define GPIO_CLR_CLR4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPIO_CLRTE.CLR4 Field                   */
#define GPIO_CLR_CLR5_MASK                       (0x20U)                                             /*!< GPIO_CLRTE.CLR5 Mask                    */
#define GPIO_CLR_CLR5_SHIFT                      (5U)                                                /*!< GPIO_CLRTE.CLR5 Position                */
#define GPIO_CLR_CLR5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPIO_CLRTE.CLR5 Field                   */
#define GPIO_CLR_CLR6_MASK                       (0x40U)                                             /*!< GPIO_CLRTE.CLR6 Mask                    */
#define GPIO_CLR_CLR6_SHIFT                      (6U)                                                /*!< GPIO_CLRTE.CLR6 Position                */
#define GPIO_CLR_CLR6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< GPIO_CLRTE.CLR6 Field                   */
#define GPIO_CLR_CLR7_MASK                       (0x80U)                                             /*!< GPIO_CLRTE.CLR7 Mask                    */
#define GPIO_CLR_CLR7_SHIFT                      (7U)                                                /*!< GPIO_CLRTE.CLR7 Position                */
#define GPIO_CLR_CLR7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPIO_CLRTE.CLR7 Field                   */
/* ------- CLRTF Bit Fields                         ------ */
/* ------- CLRTG Bit Fields                         ------ */
/* ------- CLRTH Bit Fields                         ------ */
/* ------- CLRTI Bit Fields                         ------ */
/* ------- CLRTJ Bit Fields                         ------ */
/* ------- CLRNQ Bit Fields                         ------ */
/* ------- CLRAN Bit Fields                         ------ */
/* ------- CLRAS Bit Fields                         ------ */
/* ------- CLRQS Bit Fields                         ------ */
/* ------- CLRTA Bit Fields                         ------ */
/* ------- CLRTC Bit Fields                         ------ */
/* ------- CLRUA Bit Fields                         ------ */
/* ------- CLRUB Bit Fields                         ------ */
/* ------- CLRUC Bit Fields                         ------ */
/* ------- CLRDD Bit Fields                         ------ */
/* ------- PARTE Bit Fields                         ------ */
#define GPIO_PAR_PAR0_MASK                       (0x1U)                                              /*!< GPIO_PARTE.PAR0 Mask                    */
#define GPIO_PAR_PAR0_SHIFT                      (0U)                                                /*!< GPIO_PARTE.PAR0 Position                */
#define GPIO_PAR_PAR0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPIO_PARTE.PAR0 Field                   */
#define GPIO_PAR_PAR1_MASK                       (0x2U)                                              /*!< GPIO_PARTE.PAR1 Mask                    */
#define GPIO_PAR_PAR1_SHIFT                      (1U)                                                /*!< GPIO_PARTE.PAR1 Position                */
#define GPIO_PAR_PAR1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPIO_PARTE.PAR1 Field                   */
#define GPIO_PAR_PAR2_MASK                       (0x4U)                                              /*!< GPIO_PARTE.PAR2 Mask                    */
#define GPIO_PAR_PAR2_SHIFT                      (2U)                                                /*!< GPIO_PARTE.PAR2 Position                */
#define GPIO_PAR_PAR2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPIO_PARTE.PAR2 Field                   */
#define GPIO_PAR_PAR3_MASK                       (0x8U)                                              /*!< GPIO_PARTE.PAR3 Mask                    */
#define GPIO_PAR_PAR3_SHIFT                      (3U)                                                /*!< GPIO_PARTE.PAR3 Position                */
#define GPIO_PAR_PAR3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPIO_PARTE.PAR3 Field                   */
#define GPIO_PAR_PAR4_MASK                       (0x10U)                                             /*!< GPIO_PARTE.PAR4 Mask                    */
#define GPIO_PAR_PAR4_SHIFT                      (4U)                                                /*!< GPIO_PARTE.PAR4 Position                */
#define GPIO_PAR_PAR4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPIO_PARTE.PAR4 Field                   */
#define GPIO_PAR_PAR5_MASK                       (0x20U)                                             /*!< GPIO_PARTE.PAR5 Mask                    */
#define GPIO_PAR_PAR5_SHIFT                      (5U)                                                /*!< GPIO_PARTE.PAR5 Position                */
#define GPIO_PAR_PAR5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPIO_PARTE.PAR5 Field                   */
#define GPIO_PAR_PAR6_MASK                       (0x40U)                                             /*!< GPIO_PARTE.PAR6 Mask                    */
#define GPIO_PAR_PAR6_SHIFT                      (6U)                                                /*!< GPIO_PARTE.PAR6 Position                */
#define GPIO_PAR_PAR6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< GPIO_PARTE.PAR6 Field                   */
#define GPIO_PAR_PAR7_MASK                       (0x80U)                                             /*!< GPIO_PARTE.PAR7 Mask                    */
#define GPIO_PAR_PAR7_SHIFT                      (7U)                                                /*!< GPIO_PARTE.PAR7 Position                */
#define GPIO_PAR_PAR7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPIO_PARTE.PAR7 Field                   */
/* ------- PARTF Bit Fields                         ------ */
/* ------- PARTG Bit Fields                         ------ */
/* ------- PARTI Bit Fields                         ------ */
/* ------- PARTJ Bit Fields                         ------ */
/* ------- QPARNQ Bit Fields                        ------ */
#define GPIO_QPAR_QPAR0_MASK                     (0x3U)                                              /*!< GPIO_QPARNQ.QPAR0 Mask                  */
#define GPIO_QPAR_QPAR0_SHIFT                    (0U)                                                /*!< GPIO_QPARNQ.QPAR0 Position              */
#define GPIO_QPAR_QPAR0(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< GPIO_QPARNQ.QPAR0 Field                 */
#define GPIO_QPAR_QPAR1_MASK                     (0xCU)                                              /*!< GPIO_QPARNQ.QPAR1 Mask                  */
#define GPIO_QPAR_QPAR1_SHIFT                    (2U)                                                /*!< GPIO_QPARNQ.QPAR1 Position              */
#define GPIO_QPAR_QPAR1(x)                       (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< GPIO_QPARNQ.QPAR1 Field                 */
#define GPIO_QPAR_QPAR2_MASK                     (0x30U)                                             /*!< GPIO_QPARNQ.QPAR2 Mask                  */
#define GPIO_QPAR_QPAR2_SHIFT                    (4U)                                                /*!< GPIO_QPARNQ.QPAR2 Position              */
#define GPIO_QPAR_QPAR2(x)                       (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< GPIO_QPARNQ.QPAR2 Field                 */
#define GPIO_QPAR_QPAR3_MASK                     (0xC0U)                                             /*!< GPIO_QPARNQ.QPAR3 Mask                  */
#define GPIO_QPAR_QPAR3_SHIFT                    (6U)                                                /*!< GPIO_QPARNQ.QPAR3 Position              */
#define GPIO_QPAR_QPAR3(x)                       (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< GPIO_QPARNQ.QPAR3 Field                 */
#define GPIO_QPAR_QPAR4_MASK                     (0x300U)                                            /*!< GPIO_QPARNQ.QPAR4 Mask                  */
#define GPIO_QPAR_QPAR4_SHIFT                    (8U)                                                /*!< GPIO_QPARNQ.QPAR4 Position              */
#define GPIO_QPAR_QPAR4(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< GPIO_QPARNQ.QPAR4 Field                 */
#define GPIO_QPAR_QPAR5_MASK                     (0xC00U)                                            /*!< GPIO_QPARNQ.QPAR5 Mask                  */
#define GPIO_QPAR_QPAR5_SHIFT                    (10U)                                               /*!< GPIO_QPARNQ.QPAR5 Position              */
#define GPIO_QPAR_QPAR5(x)                       (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< GPIO_QPARNQ.QPAR5 Field                 */
#define GPIO_QPAR_QPAR6_MASK                     (0x3000U)                                           /*!< GPIO_QPARNQ.QPAR6 Mask                  */
#define GPIO_QPAR_QPAR6_SHIFT                    (12U)                                               /*!< GPIO_QPARNQ.QPAR6 Position              */
#define GPIO_QPAR_QPAR6(x)                       (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< GPIO_QPARNQ.QPAR6 Field                 */
#define GPIO_QPAR_QPAR7_MASK                     (0xC000U)                                           /*!< GPIO_QPARNQ.QPAR7 Mask                  */
#define GPIO_QPAR_QPAR7_SHIFT                    (14U)                                               /*!< GPIO_QPARNQ.QPAR7 Position              */
#define GPIO_QPAR_QPAR7(x)                       (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< GPIO_QPARNQ.QPAR7 Field                 */
/* ------- PARAN Bit Fields                         ------ */
/* ------- QPARAS Bit Fields                        ------ */
/* ------- QPARQS Bit Fields                        ------ */
/* ------- QPARTA Bit Fields                        ------ */
/* ------- QPARTC Bit Fields                        ------ */
/* ------- QPARUA Bit Fields                        ------ */
/* ------- QPARUB Bit Fields                        ------ */
/* ------- QPARUC Bit Fields                        ------ */
/* ------- PARDD Bit Fields                         ------ */
/* ------- QPARTH Bit Fields                        ------ */
/**
 * @} */ /* End group GPIO_Register_Masks_GROUP 
 */

/* GPIO - Peripheral instance base addresses */
#define GPIO_BasePtr                   0x40100000UL //!< Peripheral base address
#define GPIO                           ((GPIO_Type *) GPIO_BasePtr) //!< Freescale base pointer
#define GPIO_BASE_PTR                  (GPIO) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPT_Peripheral_access_layer_GROUP GPT Peripheral Access Layer
* @brief C Struct for GPT
* @{
*/

/* ================================================================================ */
/* ================           GPT (file:MCF52259_GPT)              ================ */
/* ================================================================================ */

/**
 * @brief None
 */
/**
* @addtogroup GPT_structs_GROUP GPT struct
* @brief Struct for GPT
* @{
*/
typedef struct GPT_Type {
   __IO uint8_t   GPTIOS;                       /**< 0000: None                                                         */
   __IO uint8_t   GPTCFORC;                     /**< 0001: None                                                         */
   __IO uint8_t   GPTOC3M;                      /**< 0002: None                                                         */
   __IO uint8_t   GPTOC3D;                      /**< 0003: None                                                         */
   __I  uint16_t  GPTCNT;                       /**< 0004: None                                                         */
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
} GPT_Type;

/**
 * @} */ /* End group GPT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPT_Register_Masks_GROUP GPT Register Masks
* @brief Register Masks for GPT
* @{
*/
/* ------- GPTIOS Bit Fields                        ------ */
#define GPT_GPTIOS_IOS_MASK                      (0xFU)                                              /*!< GPT_GPTIOS.IOS Mask                     */
#define GPT_GPTIOS_IOS_SHIFT                     (0U)                                                /*!< GPT_GPTIOS.IOS Position                 */
#define GPT_GPTIOS_IOS(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< GPT_GPTIOS.IOS Field                    */
/* ------- GPTCFORC Bit Fields                      ------ */
#define GPT_GPTCFORC_FOC0_MASK                   (0x1U)                                              /*!< GPT_GPTCFORC.FOC0 Mask                  */
#define GPT_GPTCFORC_FOC0_SHIFT                  (0U)                                                /*!< GPT_GPTCFORC.FOC0 Position              */
#define GPT_GPTCFORC_FOC0(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTCFORC.FOC0 Field                 */
#define GPT_GPTCFORC_FOC1_MASK                   (0x2U)                                              /*!< GPT_GPTCFORC.FOC1 Mask                  */
#define GPT_GPTCFORC_FOC1_SHIFT                  (1U)                                                /*!< GPT_GPTCFORC.FOC1 Position              */
#define GPT_GPTCFORC_FOC1(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTCFORC.FOC1 Field                 */
#define GPT_GPTCFORC_FOC2_MASK                   (0x4U)                                              /*!< GPT_GPTCFORC.FOC2 Mask                  */
#define GPT_GPTCFORC_FOC2_SHIFT                  (2U)                                                /*!< GPT_GPTCFORC.FOC2 Position              */
#define GPT_GPTCFORC_FOC2(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTCFORC.FOC2 Field                 */
#define GPT_GPTCFORC_FOC3_MASK                   (0x8U)                                              /*!< GPT_GPTCFORC.FOC3 Mask                  */
#define GPT_GPTCFORC_FOC3_SHIFT                  (3U)                                                /*!< GPT_GPTCFORC.FOC3 Position              */
#define GPT_GPTCFORC_FOC3(x)                     (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTCFORC.FOC3 Field                 */
/* ------- GPTOC3M Bit Fields                       ------ */
#define GPT_GPTOC3M_OC3M0_MASK                   (0x1U)                                              /*!< GPT_GPTOC3M.OC3M0 Mask                  */
#define GPT_GPTOC3M_OC3M0_SHIFT                  (0U)                                                /*!< GPT_GPTOC3M.OC3M0 Position              */
#define GPT_GPTOC3M_OC3M0(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTOC3M.OC3M0 Field                 */
#define GPT_GPTOC3M_OC3M1_MASK                   (0x2U)                                              /*!< GPT_GPTOC3M.OC3M1 Mask                  */
#define GPT_GPTOC3M_OC3M1_SHIFT                  (1U)                                                /*!< GPT_GPTOC3M.OC3M1 Position              */
#define GPT_GPTOC3M_OC3M1(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTOC3M.OC3M1 Field                 */
#define GPT_GPTOC3M_OC3M2_MASK                   (0x4U)                                              /*!< GPT_GPTOC3M.OC3M2 Mask                  */
#define GPT_GPTOC3M_OC3M2_SHIFT                  (2U)                                                /*!< GPT_GPTOC3M.OC3M2 Position              */
#define GPT_GPTOC3M_OC3M2(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTOC3M.OC3M2 Field                 */
#define GPT_GPTOC3M_OC3M3_MASK                   (0x8U)                                              /*!< GPT_GPTOC3M.OC3M3 Mask                  */
#define GPT_GPTOC3M_OC3M3_SHIFT                  (3U)                                                /*!< GPT_GPTOC3M.OC3M3 Position              */
#define GPT_GPTOC3M_OC3M3(x)                     (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTOC3M.OC3M3 Field                 */
/* ------- GPTOC3D Bit Fields                       ------ */
#define GPT_GPTOC3D_OC3D0_MASK                   (0x1U)                                              /*!< GPT_GPTOC3D.OC3D0 Mask                  */
#define GPT_GPTOC3D_OC3D0_SHIFT                  (0U)                                                /*!< GPT_GPTOC3D.OC3D0 Position              */
#define GPT_GPTOC3D_OC3D0(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTOC3D.OC3D0 Field                 */
#define GPT_GPTOC3D_OC3D1_MASK                   (0x2U)                                              /*!< GPT_GPTOC3D.OC3D1 Mask                  */
#define GPT_GPTOC3D_OC3D1_SHIFT                  (1U)                                                /*!< GPT_GPTOC3D.OC3D1 Position              */
#define GPT_GPTOC3D_OC3D1(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTOC3D.OC3D1 Field                 */
#define GPT_GPTOC3D_OC3D2_MASK                   (0x4U)                                              /*!< GPT_GPTOC3D.OC3D2 Mask                  */
#define GPT_GPTOC3D_OC3D2_SHIFT                  (2U)                                                /*!< GPT_GPTOC3D.OC3D2 Position              */
#define GPT_GPTOC3D_OC3D2(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTOC3D.OC3D2 Field                 */
#define GPT_GPTOC3D_OC3D3_MASK                   (0x8U)                                              /*!< GPT_GPTOC3D.OC3D3 Mask                  */
#define GPT_GPTOC3D_OC3D3_SHIFT                  (3U)                                                /*!< GPT_GPTOC3D.OC3D3 Position              */
#define GPT_GPTOC3D_OC3D3(x)                     (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTOC3D.OC3D3 Field                 */
/* ------- GPTCNT Bit Fields                        ------ */
#define GPT_GPTCNT_CNTR_MASK                     (0xFFFFU)                                           /*!< GPT_GPTCNT.CNTR Mask                    */
#define GPT_GPTCNT_CNTR_SHIFT                    (0U)                                                /*!< GPT_GPTCNT.CNTR Position                */
#define GPT_GPTCNT_CNTR(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< GPT_GPTCNT.CNTR Field                   */
/* ------- GPTSCR1 Bit Fields                       ------ */
#define GPT_GPTSCR1_TFFCA_MASK                   (0x10U)                                             /*!< GPT_GPTSCR1.TFFCA Mask                  */
#define GPT_GPTSCR1_TFFCA_SHIFT                  (4U)                                                /*!< GPT_GPTSCR1.TFFCA Position              */
#define GPT_GPTSCR1_TFFCA(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPT_GPTSCR1.TFFCA Field                 */
#define GPT_GPTSCR1_GPTEN_MASK                   (0x80U)                                             /*!< GPT_GPTSCR1.GPTEN Mask                  */
#define GPT_GPTSCR1_GPTEN_SHIFT                  (7U)                                                /*!< GPT_GPTSCR1.GPTEN Position              */
#define GPT_GPTSCR1_GPTEN(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPT_GPTSCR1.GPTEN Field                 */
/* ------- GPTTOV Bit Fields                        ------ */
#define GPT_GPTTOV_TOV0_MASK                     (0x1U)                                              /*!< GPT_GPTTOV.TOV0 Mask                    */
#define GPT_GPTTOV_TOV0_SHIFT                    (0U)                                                /*!< GPT_GPTTOV.TOV0 Position                */
#define GPT_GPTTOV_TOV0(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTTOV.TOV0 Field                   */
#define GPT_GPTTOV_TOV1_MASK                     (0x2U)                                              /*!< GPT_GPTTOV.TOV1 Mask                    */
#define GPT_GPTTOV_TOV1_SHIFT                    (1U)                                                /*!< GPT_GPTTOV.TOV1 Position                */
#define GPT_GPTTOV_TOV1(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTTOV.TOV1 Field                   */
#define GPT_GPTTOV_TOV2_MASK                     (0x4U)                                              /*!< GPT_GPTTOV.TOV2 Mask                    */
#define GPT_GPTTOV_TOV2_SHIFT                    (2U)                                                /*!< GPT_GPTTOV.TOV2 Position                */
#define GPT_GPTTOV_TOV2(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTTOV.TOV2 Field                   */
#define GPT_GPTTOV_TOV3_MASK                     (0x8U)                                              /*!< GPT_GPTTOV.TOV3 Mask                    */
#define GPT_GPTTOV_TOV3_SHIFT                    (3U)                                                /*!< GPT_GPTTOV.TOV3 Position                */
#define GPT_GPTTOV_TOV3(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTTOV.TOV3 Field                   */
/* ------- GPTCTL1 Bit Fields                       ------ */
#define GPT_GPTCTL1_OL0_MASK                     (0x1U)                                              /*!< GPT_GPTCTL1.OL0 Mask                    */
#define GPT_GPTCTL1_OL0_SHIFT                    (0U)                                                /*!< GPT_GPTCTL1.OL0 Position                */
#define GPT_GPTCTL1_OL0(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTCTL1.OL0 Field                   */
#define GPT_GPTCTL1_OM0_MASK                     (0x2U)                                              /*!< GPT_GPTCTL1.OM0 Mask                    */
#define GPT_GPTCTL1_OM0_SHIFT                    (1U)                                                /*!< GPT_GPTCTL1.OM0 Position                */
#define GPT_GPTCTL1_OM0(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTCTL1.OM0 Field                   */
#define GPT_GPTCTL1_OL1_MASK                     (0x4U)                                              /*!< GPT_GPTCTL1.OL1 Mask                    */
#define GPT_GPTCTL1_OL1_SHIFT                    (2U)                                                /*!< GPT_GPTCTL1.OL1 Position                */
#define GPT_GPTCTL1_OL1(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTCTL1.OL1 Field                   */
#define GPT_GPTCTL1_OM1_MASK                     (0x8U)                                              /*!< GPT_GPTCTL1.OM1 Mask                    */
#define GPT_GPTCTL1_OM1_SHIFT                    (3U)                                                /*!< GPT_GPTCTL1.OM1 Position                */
#define GPT_GPTCTL1_OM1(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTCTL1.OM1 Field                   */
#define GPT_GPTCTL1_OL2_MASK                     (0x10U)                                             /*!< GPT_GPTCTL1.OL2 Mask                    */
#define GPT_GPTCTL1_OL2_SHIFT                    (4U)                                                /*!< GPT_GPTCTL1.OL2 Position                */
#define GPT_GPTCTL1_OL2(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPT_GPTCTL1.OL2 Field                   */
#define GPT_GPTCTL1_OM2_MASK                     (0x20U)                                             /*!< GPT_GPTCTL1.OM2 Mask                    */
#define GPT_GPTCTL1_OM2_SHIFT                    (5U)                                                /*!< GPT_GPTCTL1.OM2 Position                */
#define GPT_GPTCTL1_OM2(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPT_GPTCTL1.OM2 Field                   */
#define GPT_GPTCTL1_OL3_MASK                     (0x40U)                                             /*!< GPT_GPTCTL1.OL3 Mask                    */
#define GPT_GPTCTL1_OL3_SHIFT                    (6U)                                                /*!< GPT_GPTCTL1.OL3 Position                */
#define GPT_GPTCTL1_OL3(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< GPT_GPTCTL1.OL3 Field                   */
#define GPT_GPTCTL1_OM3_MASK                     (0x80U)                                             /*!< GPT_GPTCTL1.OM3 Mask                    */
#define GPT_GPTCTL1_OM3_SHIFT                    (7U)                                                /*!< GPT_GPTCTL1.OM3 Position                */
#define GPT_GPTCTL1_OM3(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPT_GPTCTL1.OM3 Field                   */
/* ------- GPTCTL2 Bit Fields                       ------ */
#define GPT_GPTCTL2_EDG0A_MASK                   (0x1U)                                              /*!< GPT_GPTCTL2.EDG0A Mask                  */
#define GPT_GPTCTL2_EDG0A_SHIFT                  (0U)                                                /*!< GPT_GPTCTL2.EDG0A Position              */
#define GPT_GPTCTL2_EDG0A(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTCTL2.EDG0A Field                 */
#define GPT_GPTCTL2_EDG0B_MASK                   (0x2U)                                              /*!< GPT_GPTCTL2.EDG0B Mask                  */
#define GPT_GPTCTL2_EDG0B_SHIFT                  (1U)                                                /*!< GPT_GPTCTL2.EDG0B Position              */
#define GPT_GPTCTL2_EDG0B(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTCTL2.EDG0B Field                 */
#define GPT_GPTCTL2_EDG1A_MASK                   (0x4U)                                              /*!< GPT_GPTCTL2.EDG1A Mask                  */
#define GPT_GPTCTL2_EDG1A_SHIFT                  (2U)                                                /*!< GPT_GPTCTL2.EDG1A Position              */
#define GPT_GPTCTL2_EDG1A(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTCTL2.EDG1A Field                 */
#define GPT_GPTCTL2_EDG1B_MASK                   (0x8U)                                              /*!< GPT_GPTCTL2.EDG1B Mask                  */
#define GPT_GPTCTL2_EDG1B_SHIFT                  (3U)                                                /*!< GPT_GPTCTL2.EDG1B Position              */
#define GPT_GPTCTL2_EDG1B(x)                     (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTCTL2.EDG1B Field                 */
#define GPT_GPTCTL2_EDG2A_MASK                   (0x10U)                                             /*!< GPT_GPTCTL2.EDG2A Mask                  */
#define GPT_GPTCTL2_EDG2A_SHIFT                  (4U)                                                /*!< GPT_GPTCTL2.EDG2A Position              */
#define GPT_GPTCTL2_EDG2A(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPT_GPTCTL2.EDG2A Field                 */
#define GPT_GPTCTL2_EDG2B_MASK                   (0x20U)                                             /*!< GPT_GPTCTL2.EDG2B Mask                  */
#define GPT_GPTCTL2_EDG2B_SHIFT                  (5U)                                                /*!< GPT_GPTCTL2.EDG2B Position              */
#define GPT_GPTCTL2_EDG2B(x)                     (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPT_GPTCTL2.EDG2B Field                 */
#define GPT_GPTCTL2_EDG3A_MASK                   (0x40U)                                             /*!< GPT_GPTCTL2.EDG3A Mask                  */
#define GPT_GPTCTL2_EDG3A_SHIFT                  (6U)                                                /*!< GPT_GPTCTL2.EDG3A Position              */
#define GPT_GPTCTL2_EDG3A(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< GPT_GPTCTL2.EDG3A Field                 */
#define GPT_GPTCTL2_EDG3B_MASK                   (0x80U)                                             /*!< GPT_GPTCTL2.EDG3B Mask                  */
#define GPT_GPTCTL2_EDG3B_SHIFT                  (7U)                                                /*!< GPT_GPTCTL2.EDG3B Position              */
#define GPT_GPTCTL2_EDG3B(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPT_GPTCTL2.EDG3B Field                 */
/* ------- GPTIE Bit Fields                         ------ */
#define GPT_GPTIE_CI0_MASK                       (0x1U)                                              /*!< GPT_GPTIE.CI0 Mask                      */
#define GPT_GPTIE_CI0_SHIFT                      (0U)                                                /*!< GPT_GPTIE.CI0 Position                  */
#define GPT_GPTIE_CI0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTIE.CI0 Field                     */
#define GPT_GPTIE_CI1_MASK                       (0x2U)                                              /*!< GPT_GPTIE.CI1 Mask                      */
#define GPT_GPTIE_CI1_SHIFT                      (1U)                                                /*!< GPT_GPTIE.CI1 Position                  */
#define GPT_GPTIE_CI1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTIE.CI1 Field                     */
#define GPT_GPTIE_CI2_MASK                       (0x4U)                                              /*!< GPT_GPTIE.CI2 Mask                      */
#define GPT_GPTIE_CI2_SHIFT                      (2U)                                                /*!< GPT_GPTIE.CI2 Position                  */
#define GPT_GPTIE_CI2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTIE.CI2 Field                     */
#define GPT_GPTIE_CI3_MASK                       (0x8U)                                              /*!< GPT_GPTIE.CI3 Mask                      */
#define GPT_GPTIE_CI3_SHIFT                      (3U)                                                /*!< GPT_GPTIE.CI3 Position                  */
#define GPT_GPTIE_CI3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTIE.CI3 Field                     */
/* ------- GPTSCR2 Bit Fields                       ------ */
#define GPT_GPTSCR2_PR_MASK                      (0x7U)                                              /*!< GPT_GPTSCR2.PR Mask                     */
#define GPT_GPTSCR2_PR_SHIFT                     (0U)                                                /*!< GPT_GPTSCR2.PR Position                 */
#define GPT_GPTSCR2_PR(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< GPT_GPTSCR2.PR Field                    */
#define GPT_GPTSCR2_TCRE_MASK                    (0x8U)                                              /*!< GPT_GPTSCR2.TCRE Mask                   */
#define GPT_GPTSCR2_TCRE_SHIFT                   (3U)                                                /*!< GPT_GPTSCR2.TCRE Position               */
#define GPT_GPTSCR2_TCRE(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTSCR2.TCRE Field                  */
#define GPT_GPTSCR2_RDPT_MASK                    (0x10U)                                             /*!< GPT_GPTSCR2.RDPT Mask                   */
#define GPT_GPTSCR2_RDPT_SHIFT                   (4U)                                                /*!< GPT_GPTSCR2.RDPT Position               */
#define GPT_GPTSCR2_RDPT(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPT_GPTSCR2.RDPT Field                  */
#define GPT_GPTSCR2_PUPT_MASK                    (0x20U)                                             /*!< GPT_GPTSCR2.PUPT Mask                   */
#define GPT_GPTSCR2_PUPT_SHIFT                   (5U)                                                /*!< GPT_GPTSCR2.PUPT Position               */
#define GPT_GPTSCR2_PUPT(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPT_GPTSCR2.PUPT Field                  */
#define GPT_GPTSCR2_TOI_MASK                     (0x80U)                                             /*!< GPT_GPTSCR2.TOI Mask                    */
#define GPT_GPTSCR2_TOI_SHIFT                    (7U)                                                /*!< GPT_GPTSCR2.TOI Position                */
#define GPT_GPTSCR2_TOI(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPT_GPTSCR2.TOI Field                   */
/* ------- GPTFLG1 Bit Fields                       ------ */
#define GPT_GPTFLG1_CF0_MASK                     (0x1U)                                              /*!< GPT_GPTFLG1.CF0 Mask                    */
#define GPT_GPTFLG1_CF0_SHIFT                    (0U)                                                /*!< GPT_GPTFLG1.CF0 Position                */
#define GPT_GPTFLG1_CF0(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTFLG1.CF0 Field                   */
#define GPT_GPTFLG1_CF1_MASK                     (0x2U)                                              /*!< GPT_GPTFLG1.CF1 Mask                    */
#define GPT_GPTFLG1_CF1_SHIFT                    (1U)                                                /*!< GPT_GPTFLG1.CF1 Position                */
#define GPT_GPTFLG1_CF1(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTFLG1.CF1 Field                   */
#define GPT_GPTFLG1_CF2_MASK                     (0x4U)                                              /*!< GPT_GPTFLG1.CF2 Mask                    */
#define GPT_GPTFLG1_CF2_SHIFT                    (2U)                                                /*!< GPT_GPTFLG1.CF2 Position                */
#define GPT_GPTFLG1_CF2(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTFLG1.CF2 Field                   */
#define GPT_GPTFLG1_CF3_MASK                     (0x8U)                                              /*!< GPT_GPTFLG1.CF3 Mask                    */
#define GPT_GPTFLG1_CF3_SHIFT                    (3U)                                                /*!< GPT_GPTFLG1.CF3 Position                */
#define GPT_GPTFLG1_CF3(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTFLG1.CF3 Field                   */
/* ------- GPTFLG2 Bit Fields                       ------ */
#define GPT_GPTFLG2_TOF_MASK                     (0x80U)                                             /*!< GPT_GPTFLG2.TOF Mask                    */
#define GPT_GPTFLG2_TOF_SHIFT                    (7U)                                                /*!< GPT_GPTFLG2.TOF Position                */
#define GPT_GPTFLG2_TOF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< GPT_GPTFLG2.TOF Field                   */
/* ------- GPTC Bit Fields                          ------ */
#define GPT_GPTC_CCNT_MASK                       (0xFFFFU)                                           /*!< GPT_GPTC.CCNT Mask                      */
#define GPT_GPTC_CCNT_SHIFT                      (0U)                                                /*!< GPT_GPTC.CCNT Position                  */
#define GPT_GPTC_CCNT(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< GPT_GPTC.CCNT Field                     */
/* ------- GPTPACTL Bit Fields                      ------ */
#define GPT_GPTPACTL_PAI_MASK                    (0x1U)                                              /*!< GPT_GPTPACTL.PAI Mask                   */
#define GPT_GPTPACTL_PAI_SHIFT                   (0U)                                                /*!< GPT_GPTPACTL.PAI Position               */
#define GPT_GPTPACTL_PAI(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTPACTL.PAI Field                  */
#define GPT_GPTPACTL_PAOVI_MASK                  (0x2U)                                              /*!< GPT_GPTPACTL.PAOVI Mask                 */
#define GPT_GPTPACTL_PAOVI_SHIFT                 (1U)                                                /*!< GPT_GPTPACTL.PAOVI Position             */
#define GPT_GPTPACTL_PAOVI(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTPACTL.PAOVI Field                */
#define GPT_GPTPACTL_CLK_MASK                    (0xCU)                                              /*!< GPT_GPTPACTL.CLK Mask                   */
#define GPT_GPTPACTL_CLK_SHIFT                   (2U)                                                /*!< GPT_GPTPACTL.CLK Position               */
#define GPT_GPTPACTL_CLK(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< GPT_GPTPACTL.CLK Field                  */
#define GPT_GPTPACTL_PEDGE_MASK                  (0x10U)                                             /*!< GPT_GPTPACTL.PEDGE Mask                 */
#define GPT_GPTPACTL_PEDGE_SHIFT                 (4U)                                                /*!< GPT_GPTPACTL.PEDGE Position             */
#define GPT_GPTPACTL_PEDGE(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< GPT_GPTPACTL.PEDGE Field                */
#define GPT_GPTPACTL_PAMOD_MASK                  (0x20U)                                             /*!< GPT_GPTPACTL.PAMOD Mask                 */
#define GPT_GPTPACTL_PAMOD_SHIFT                 (5U)                                                /*!< GPT_GPTPACTL.PAMOD Position             */
#define GPT_GPTPACTL_PAMOD(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< GPT_GPTPACTL.PAMOD Field                */
#define GPT_GPTPACTL_PAE_MASK                    (0x40U)                                             /*!< GPT_GPTPACTL.PAE Mask                   */
#define GPT_GPTPACTL_PAE_SHIFT                   (6U)                                                /*!< GPT_GPTPACTL.PAE Position               */
#define GPT_GPTPACTL_PAE(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< GPT_GPTPACTL.PAE Field                  */
/* ------- GPTPAFLG Bit Fields                      ------ */
#define GPT_GPTPAFLG_PAIF_MASK                   (0x1U)                                              /*!< GPT_GPTPAFLG.PAIF Mask                  */
#define GPT_GPTPAFLG_PAIF_SHIFT                  (0U)                                                /*!< GPT_GPTPAFLG.PAIF Position              */
#define GPT_GPTPAFLG_PAIF(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTPAFLG.PAIF Field                 */
#define GPT_GPTPAFLG_PAOVF_MASK                  (0x2U)                                              /*!< GPT_GPTPAFLG.PAOVF Mask                 */
#define GPT_GPTPAFLG_PAOVF_SHIFT                 (1U)                                                /*!< GPT_GPTPAFLG.PAOVF Position             */
#define GPT_GPTPAFLG_PAOVF(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTPAFLG.PAOVF Field                */
/* ------- GPTPACNT Bit Fields                      ------ */
#define GPT_GPTPACNT_PACNT_MASK                  (0xFFFFU)                                           /*!< GPT_GPTPACNT.PACNT Mask                 */
#define GPT_GPTPACNT_PACNT_SHIFT                 (0U)                                                /*!< GPT_GPTPACNT.PACNT Position             */
#define GPT_GPTPACNT_PACNT(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< GPT_GPTPACNT.PACNT Field                */
/* ------- GPTPORT Bit Fields                       ------ */
#define GPT_GPTPORT_PORTT0_MASK                  (0x1U)                                              /*!< GPT_GPTPORT.PORTT0 Mask                 */
#define GPT_GPTPORT_PORTT0_SHIFT                 (0U)                                                /*!< GPT_GPTPORT.PORTT0 Position             */
#define GPT_GPTPORT_PORTT0(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTPORT.PORTT0 Field                */
#define GPT_GPTPORT_PORTT1_MASK                  (0x2U)                                              /*!< GPT_GPTPORT.PORTT1 Mask                 */
#define GPT_GPTPORT_PORTT1_SHIFT                 (1U)                                                /*!< GPT_GPTPORT.PORTT1 Position             */
#define GPT_GPTPORT_PORTT1(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTPORT.PORTT1 Field                */
#define GPT_GPTPORT_PORTT2_MASK                  (0x4U)                                              /*!< GPT_GPTPORT.PORTT2 Mask                 */
#define GPT_GPTPORT_PORTT2_SHIFT                 (2U)                                                /*!< GPT_GPTPORT.PORTT2 Position             */
#define GPT_GPTPORT_PORTT2(x)                    (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTPORT.PORTT2 Field                */
#define GPT_GPTPORT_PORTT3_MASK                  (0x8U)                                              /*!< GPT_GPTPORT.PORTT3 Mask                 */
#define GPT_GPTPORT_PORTT3_SHIFT                 (3U)                                                /*!< GPT_GPTPORT.PORTT3 Position             */
#define GPT_GPTPORT_PORTT3(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTPORT.PORTT3 Field                */
/* ------- GPTDDR Bit Fields                        ------ */
#define GPT_GPTDDR_DDRT0_MASK                    (0x1U)                                              /*!< GPT_GPTDDR.DDRT0 Mask                   */
#define GPT_GPTDDR_DDRT0_SHIFT                   (0U)                                                /*!< GPT_GPTDDR.DDRT0 Position               */
#define GPT_GPTDDR_DDRT0(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< GPT_GPTDDR.DDRT0 Field                  */
#define GPT_GPTDDR_DDRT1_MASK                    (0x2U)                                              /*!< GPT_GPTDDR.DDRT1 Mask                   */
#define GPT_GPTDDR_DDRT1_SHIFT                   (1U)                                                /*!< GPT_GPTDDR.DDRT1 Position               */
#define GPT_GPTDDR_DDRT1(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< GPT_GPTDDR.DDRT1 Field                  */
#define GPT_GPTDDR_DDRT2_MASK                    (0x4U)                                              /*!< GPT_GPTDDR.DDRT2 Mask                   */
#define GPT_GPTDDR_DDRT2_SHIFT                   (2U)                                                /*!< GPT_GPTDDR.DDRT2 Position               */
#define GPT_GPTDDR_DDRT2(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< GPT_GPTDDR.DDRT2 Field                  */
#define GPT_GPTDDR_DDRT3_MASK                    (0x8U)                                              /*!< GPT_GPTDDR.DDRT3 Mask                   */
#define GPT_GPTDDR_DDRT3_SHIFT                   (3U)                                                /*!< GPT_GPTDDR.DDRT3 Position               */
#define GPT_GPTDDR_DDRT3(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< GPT_GPTDDR.DDRT3 Field                  */
/**
 * @} */ /* End group GPT_Register_Masks_GROUP 
 */

/* GPT - Peripheral instance base addresses */
#define GPT_BasePtr                    0x401A0000UL //!< Peripheral base address
#define GPT                            ((GPT_Type *) GPT_BasePtr) //!< Freescale base pointer
#define GPT_BASE_PTR                   (GPT) //!< Freescale style base pointer
/**
 * @} */ /* End group GPT_Peripheral_access_layer_GROUP 
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
typedef struct I2C_Type {
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
#define I2C_I2ADR_ADR_MASK                       (0xFEU)                                             /*!< I2C0_I2ADR.ADR Mask                     */
#define I2C_I2ADR_ADR_SHIFT                      (1U)                                                /*!< I2C0_I2ADR.ADR Position                 */
#define I2C_I2ADR_ADR(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< I2C0_I2ADR.ADR Field                    */
/* ------- I2FDR Bit Fields                         ------ */
#define I2C_I2FDR_IC_MASK                        (0x3FU)                                             /*!< I2C0_I2FDR.IC Mask                      */
#define I2C_I2FDR_IC_SHIFT                       (0U)                                                /*!< I2C0_I2FDR.IC Position                  */
#define I2C_I2FDR_IC(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< I2C0_I2FDR.IC Field                     */
/* ------- I2CR Bit Fields                          ------ */
#define I2C_I2CR_RSTA_MASK                       (0x4U)                                              /*!< I2C0_I2CR.RSTA Mask                     */
#define I2C_I2CR_RSTA_SHIFT                      (2U)                                                /*!< I2C0_I2CR.RSTA Position                 */
#define I2C_I2CR_RSTA(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_I2CR.RSTA Field                    */
#define I2C_I2CR_TXAK_MASK                       (0x8U)                                              /*!< I2C0_I2CR.TXAK Mask                     */
#define I2C_I2CR_TXAK_SHIFT                      (3U)                                                /*!< I2C0_I2CR.TXAK Position                 */
#define I2C_I2CR_TXAK(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_I2CR.TXAK Field                    */
#define I2C_I2CR_MTX_MASK                        (0x10U)                                             /*!< I2C0_I2CR.MTX Mask                      */
#define I2C_I2CR_MTX_SHIFT                       (4U)                                                /*!< I2C0_I2CR.MTX Position                  */
#define I2C_I2CR_MTX(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_I2CR.MTX Field                     */
#define I2C_I2CR_MSTA_MASK                       (0x20U)                                             /*!< I2C0_I2CR.MSTA Mask                     */
#define I2C_I2CR_MSTA_SHIFT                      (5U)                                                /*!< I2C0_I2CR.MSTA Position                 */
#define I2C_I2CR_MSTA(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_I2CR.MSTA Field                    */
#define I2C_I2CR_IIEN_MASK                       (0x40U)                                             /*!< I2C0_I2CR.IIEN Mask                     */
#define I2C_I2CR_IIEN_SHIFT                      (6U)                                                /*!< I2C0_I2CR.IIEN Position                 */
#define I2C_I2CR_IIEN(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_I2CR.IIEN Field                    */
#define I2C_I2CR_IEN_MASK                        (0x80U)                                             /*!< I2C0_I2CR.IEN Mask                      */
#define I2C_I2CR_IEN_SHIFT                       (7U)                                                /*!< I2C0_I2CR.IEN Position                  */
#define I2C_I2CR_IEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_I2CR.IEN Field                     */
/* ------- I2SR Bit Fields                          ------ */
#define I2C_I2SR_RXAK_MASK                       (0x1U)                                              /*!< I2C0_I2SR.RXAK Mask                     */
#define I2C_I2SR_RXAK_SHIFT                      (0U)                                                /*!< I2C0_I2SR.RXAK Position                 */
#define I2C_I2SR_RXAK(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< I2C0_I2SR.RXAK Field                    */
#define I2C_I2SR_IIF_MASK                        (0x2U)                                              /*!< I2C0_I2SR.IIF Mask                      */
#define I2C_I2SR_IIF_SHIFT                       (1U)                                                /*!< I2C0_I2SR.IIF Position                  */
#define I2C_I2SR_IIF(x)                          (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< I2C0_I2SR.IIF Field                     */
#define I2C_I2SR_SRW_MASK                        (0x4U)                                              /*!< I2C0_I2SR.SRW Mask                      */
#define I2C_I2SR_SRW_SHIFT                       (2U)                                                /*!< I2C0_I2SR.SRW Position                  */
#define I2C_I2SR_SRW(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_I2SR.SRW Field                     */
#define I2C_I2SR_IAL_MASK                        (0x10U)                                             /*!< I2C0_I2SR.IAL Mask                      */
#define I2C_I2SR_IAL_SHIFT                       (4U)                                                /*!< I2C0_I2SR.IAL Position                  */
#define I2C_I2SR_IAL(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_I2SR.IAL Field                     */
#define I2C_I2SR_IBB_MASK                        (0x20U)                                             /*!< I2C0_I2SR.IBB Mask                      */
#define I2C_I2SR_IBB_SHIFT                       (5U)                                                /*!< I2C0_I2SR.IBB Position                  */
#define I2C_I2SR_IBB(x)                          (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_I2SR.IBB Field                     */
#define I2C_I2SR_IAAS_MASK                       (0x40U)                                             /*!< I2C0_I2SR.IAAS Mask                     */
#define I2C_I2SR_IAAS_SHIFT                      (6U)                                                /*!< I2C0_I2SR.IAAS Position                 */
#define I2C_I2SR_IAAS(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_I2SR.IAAS Field                    */
#define I2C_I2SR_ICF_MASK                        (0x80U)                                             /*!< I2C0_I2SR.ICF Mask                      */
#define I2C_I2SR_ICF_SHIFT                       (7U)                                                /*!< I2C0_I2SR.ICF Position                  */
#define I2C_I2SR_ICF(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_I2SR.ICF Field                     */
/* ------- I2DR Bit Fields                          ------ */
#define I2C_I2DR_DATA_MASK                       (0xFFU)                                             /*!< I2C0_I2DR.DATA Mask                     */
#define I2C_I2DR_DATA_SHIFT                      (0U)                                                /*!< I2C0_I2DR.DATA Position                 */
#define I2C_I2DR_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< I2C0_I2DR.DATA Field                    */
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
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C1 (derived from I2C0)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */

/* I2C1 - Peripheral instance base addresses */
#define I2C1_BasePtr                   0x40000380UL //!< Peripheral base address
#define I2C1                           ((I2C_Type *) I2C1_BasePtr) //!< Freescale base pointer
#define I2C1_BASE_PTR                  (I2C1) //!< Freescale style base pointer
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
typedef struct INTC_Type {
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
#define INTC_IPRH_INT32_MASK                     (0x1U)                                              /*!< INTC0_IPRH.INT32 Mask                   */
#define INTC_IPRH_INT32_SHIFT                    (0U)                                                /*!< INTC0_IPRH.INT32 Position               */
#define INTC_IPRH_INT32(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< INTC0_IPRH.INT32 Field                  */
#define INTC_IPRH_INT33_MASK                     (0x2U)                                              /*!< INTC0_IPRH.INT33 Mask                   */
#define INTC_IPRH_INT33_SHIFT                    (1U)                                                /*!< INTC0_IPRH.INT33 Position               */
#define INTC_IPRH_INT33(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< INTC0_IPRH.INT33 Field                  */
#define INTC_IPRH_INT34_MASK                     (0x4U)                                              /*!< INTC0_IPRH.INT34 Mask                   */
#define INTC_IPRH_INT34_SHIFT                    (2U)                                                /*!< INTC0_IPRH.INT34 Position               */
#define INTC_IPRH_INT34(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< INTC0_IPRH.INT34 Field                  */
#define INTC_IPRH_INT35_MASK                     (0x8U)                                              /*!< INTC0_IPRH.INT35 Mask                   */
#define INTC_IPRH_INT35_SHIFT                    (3U)                                                /*!< INTC0_IPRH.INT35 Position               */
#define INTC_IPRH_INT35(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< INTC0_IPRH.INT35 Field                  */
#define INTC_IPRH_INT36_MASK                     (0x10U)                                             /*!< INTC0_IPRH.INT36 Mask                   */
#define INTC_IPRH_INT36_SHIFT                    (4U)                                                /*!< INTC0_IPRH.INT36 Position               */
#define INTC_IPRH_INT36(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< INTC0_IPRH.INT36 Field                  */
#define INTC_IPRH_INT37_MASK                     (0x20U)                                             /*!< INTC0_IPRH.INT37 Mask                   */
#define INTC_IPRH_INT37_SHIFT                    (5U)                                                /*!< INTC0_IPRH.INT37 Position               */
#define INTC_IPRH_INT37(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< INTC0_IPRH.INT37 Field                  */
#define INTC_IPRH_INT38_MASK                     (0x40U)                                             /*!< INTC0_IPRH.INT38 Mask                   */
#define INTC_IPRH_INT38_SHIFT                    (6U)                                                /*!< INTC0_IPRH.INT38 Position               */
#define INTC_IPRH_INT38(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< INTC0_IPRH.INT38 Field                  */
#define INTC_IPRH_INT39_MASK                     (0x80U)                                             /*!< INTC0_IPRH.INT39 Mask                   */
#define INTC_IPRH_INT39_SHIFT                    (7U)                                                /*!< INTC0_IPRH.INT39 Position               */
#define INTC_IPRH_INT39(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< INTC0_IPRH.INT39 Field                  */
#define INTC_IPRH_INT40_MASK                     (0x100U)                                            /*!< INTC0_IPRH.INT40 Mask                   */
#define INTC_IPRH_INT40_SHIFT                    (8U)                                                /*!< INTC0_IPRH.INT40 Position               */
#define INTC_IPRH_INT40(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< INTC0_IPRH.INT40 Field                  */
#define INTC_IPRH_INT41_MASK                     (0x200U)                                            /*!< INTC0_IPRH.INT41 Mask                   */
#define INTC_IPRH_INT41_SHIFT                    (9U)                                                /*!< INTC0_IPRH.INT41 Position               */
#define INTC_IPRH_INT41(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< INTC0_IPRH.INT41 Field                  */
#define INTC_IPRH_INT42_MASK                     (0x400U)                                            /*!< INTC0_IPRH.INT42 Mask                   */
#define INTC_IPRH_INT42_SHIFT                    (10U)                                               /*!< INTC0_IPRH.INT42 Position               */
#define INTC_IPRH_INT42(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< INTC0_IPRH.INT42 Field                  */
#define INTC_IPRH_INT43_MASK                     (0x800U)                                            /*!< INTC0_IPRH.INT43 Mask                   */
#define INTC_IPRH_INT43_SHIFT                    (11U)                                               /*!< INTC0_IPRH.INT43 Position               */
#define INTC_IPRH_INT43(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< INTC0_IPRH.INT43 Field                  */
#define INTC_IPRH_INT44_MASK                     (0x1000U)                                           /*!< INTC0_IPRH.INT44 Mask                   */
#define INTC_IPRH_INT44_SHIFT                    (12U)                                               /*!< INTC0_IPRH.INT44 Position               */
#define INTC_IPRH_INT44(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< INTC0_IPRH.INT44 Field                  */
#define INTC_IPRH_INT45_MASK                     (0x2000U)                                           /*!< INTC0_IPRH.INT45 Mask                   */
#define INTC_IPRH_INT45_SHIFT                    (13U)                                               /*!< INTC0_IPRH.INT45 Position               */
#define INTC_IPRH_INT45(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< INTC0_IPRH.INT45 Field                  */
#define INTC_IPRH_INT46_MASK                     (0x4000U)                                           /*!< INTC0_IPRH.INT46 Mask                   */
#define INTC_IPRH_INT46_SHIFT                    (14U)                                               /*!< INTC0_IPRH.INT46 Position               */
#define INTC_IPRH_INT46(x)                       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< INTC0_IPRH.INT46 Field                  */
#define INTC_IPRH_INT47_MASK                     (0x8000U)                                           /*!< INTC0_IPRH.INT47 Mask                   */
#define INTC_IPRH_INT47_SHIFT                    (15U)                                               /*!< INTC0_IPRH.INT47 Position               */
#define INTC_IPRH_INT47(x)                       (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< INTC0_IPRH.INT47 Field                  */
#define INTC_IPRH_INT48_MASK                     (0x10000U)                                          /*!< INTC0_IPRH.INT48 Mask                   */
#define INTC_IPRH_INT48_SHIFT                    (16U)                                               /*!< INTC0_IPRH.INT48 Position               */
#define INTC_IPRH_INT48(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< INTC0_IPRH.INT48 Field                  */
#define INTC_IPRH_INT49_MASK                     (0x20000U)                                          /*!< INTC0_IPRH.INT49 Mask                   */
#define INTC_IPRH_INT49_SHIFT                    (17U)                                               /*!< INTC0_IPRH.INT49 Position               */
#define INTC_IPRH_INT49(x)                       (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< INTC0_IPRH.INT49 Field                  */
#define INTC_IPRH_INT50_MASK                     (0x40000U)                                          /*!< INTC0_IPRH.INT50 Mask                   */
#define INTC_IPRH_INT50_SHIFT                    (18U)                                               /*!< INTC0_IPRH.INT50 Position               */
#define INTC_IPRH_INT50(x)                       (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< INTC0_IPRH.INT50 Field                  */
#define INTC_IPRH_INT51_MASK                     (0x80000U)                                          /*!< INTC0_IPRH.INT51 Mask                   */
#define INTC_IPRH_INT51_SHIFT                    (19U)                                               /*!< INTC0_IPRH.INT51 Position               */
#define INTC_IPRH_INT51(x)                       (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< INTC0_IPRH.INT51 Field                  */
#define INTC_IPRH_INT52_MASK                     (0x100000U)                                         /*!< INTC0_IPRH.INT52 Mask                   */
#define INTC_IPRH_INT52_SHIFT                    (20U)                                               /*!< INTC0_IPRH.INT52 Position               */
#define INTC_IPRH_INT52(x)                       (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< INTC0_IPRH.INT52 Field                  */
#define INTC_IPRH_INT53_MASK                     (0x200000U)                                         /*!< INTC0_IPRH.INT53 Mask                   */
#define INTC_IPRH_INT53_SHIFT                    (21U)                                               /*!< INTC0_IPRH.INT53 Position               */
#define INTC_IPRH_INT53(x)                       (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< INTC0_IPRH.INT53 Field                  */
#define INTC_IPRH_INT54_MASK                     (0x400000U)                                         /*!< INTC0_IPRH.INT54 Mask                   */
#define INTC_IPRH_INT54_SHIFT                    (22U)                                               /*!< INTC0_IPRH.INT54 Position               */
#define INTC_IPRH_INT54(x)                       (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< INTC0_IPRH.INT54 Field                  */
#define INTC_IPRH_INT55_MASK                     (0x800000U)                                         /*!< INTC0_IPRH.INT55 Mask                   */
#define INTC_IPRH_INT55_SHIFT                    (23U)                                               /*!< INTC0_IPRH.INT55 Position               */
#define INTC_IPRH_INT55(x)                       (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< INTC0_IPRH.INT55 Field                  */
#define INTC_IPRH_INT56_MASK                     (0x1000000U)                                        /*!< INTC0_IPRH.INT56 Mask                   */
#define INTC_IPRH_INT56_SHIFT                    (24U)                                               /*!< INTC0_IPRH.INT56 Position               */
#define INTC_IPRH_INT56(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< INTC0_IPRH.INT56 Field                  */
#define INTC_IPRH_INT57_MASK                     (0x2000000U)                                        /*!< INTC0_IPRH.INT57 Mask                   */
#define INTC_IPRH_INT57_SHIFT                    (25U)                                               /*!< INTC0_IPRH.INT57 Position               */
#define INTC_IPRH_INT57(x)                       (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< INTC0_IPRH.INT57 Field                  */
#define INTC_IPRH_INT58_MASK                     (0x4000000U)                                        /*!< INTC0_IPRH.INT58 Mask                   */
#define INTC_IPRH_INT58_SHIFT                    (26U)                                               /*!< INTC0_IPRH.INT58 Position               */
#define INTC_IPRH_INT58(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< INTC0_IPRH.INT58 Field                  */
#define INTC_IPRH_INT59_MASK                     (0x8000000U)                                        /*!< INTC0_IPRH.INT59 Mask                   */
#define INTC_IPRH_INT59_SHIFT                    (27U)                                               /*!< INTC0_IPRH.INT59 Position               */
#define INTC_IPRH_INT59(x)                       (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< INTC0_IPRH.INT59 Field                  */
#define INTC_IPRH_INT60_MASK                     (0x10000000U)                                       /*!< INTC0_IPRH.INT60 Mask                   */
#define INTC_IPRH_INT60_SHIFT                    (28U)                                               /*!< INTC0_IPRH.INT60 Position               */
#define INTC_IPRH_INT60(x)                       (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< INTC0_IPRH.INT60 Field                  */
#define INTC_IPRH_INT61_MASK                     (0x20000000U)                                       /*!< INTC0_IPRH.INT61 Mask                   */
#define INTC_IPRH_INT61_SHIFT                    (29U)                                               /*!< INTC0_IPRH.INT61 Position               */
#define INTC_IPRH_INT61(x)                       (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< INTC0_IPRH.INT61 Field                  */
#define INTC_IPRH_INT62_MASK                     (0x40000000U)                                       /*!< INTC0_IPRH.INT62 Mask                   */
#define INTC_IPRH_INT62_SHIFT                    (30U)                                               /*!< INTC0_IPRH.INT62 Position               */
#define INTC_IPRH_INT62(x)                       (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< INTC0_IPRH.INT62 Field                  */
#define INTC_IPRH_INT63_MASK                     (0x80000000U)                                       /*!< INTC0_IPRH.INT63 Mask                   */
#define INTC_IPRH_INT63_SHIFT                    (31U)                                               /*!< INTC0_IPRH.INT63 Position               */
#define INTC_IPRH_INT63(x)                       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< INTC0_IPRH.INT63 Field                  */
/* ------- IPRL Bit Fields                          ------ */
#define INTC_IPRL_INT1_MASK                      (0x2U)                                              /*!< INTC0_IPRL.INT1 Mask                    */
#define INTC_IPRL_INT1_SHIFT                     (1U)                                                /*!< INTC0_IPRL.INT1 Position                */
#define INTC_IPRL_INT1(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< INTC0_IPRL.INT1 Field                   */
#define INTC_IPRL_INT2_MASK                      (0x4U)                                              /*!< INTC0_IPRL.INT2 Mask                    */
#define INTC_IPRL_INT2_SHIFT                     (2U)                                                /*!< INTC0_IPRL.INT2 Position                */
#define INTC_IPRL_INT2(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< INTC0_IPRL.INT2 Field                   */
#define INTC_IPRL_INT3_MASK                      (0x8U)                                              /*!< INTC0_IPRL.INT3 Mask                    */
#define INTC_IPRL_INT3_SHIFT                     (3U)                                                /*!< INTC0_IPRL.INT3 Position                */
#define INTC_IPRL_INT3(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< INTC0_IPRL.INT3 Field                   */
#define INTC_IPRL_INT4_MASK                      (0x10U)                                             /*!< INTC0_IPRL.INT4 Mask                    */
#define INTC_IPRL_INT4_SHIFT                     (4U)                                                /*!< INTC0_IPRL.INT4 Position                */
#define INTC_IPRL_INT4(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< INTC0_IPRL.INT4 Field                   */
#define INTC_IPRL_INT5_MASK                      (0x20U)                                             /*!< INTC0_IPRL.INT5 Mask                    */
#define INTC_IPRL_INT5_SHIFT                     (5U)                                                /*!< INTC0_IPRL.INT5 Position                */
#define INTC_IPRL_INT5(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< INTC0_IPRL.INT5 Field                   */
#define INTC_IPRL_INT6_MASK                      (0x40U)                                             /*!< INTC0_IPRL.INT6 Mask                    */
#define INTC_IPRL_INT6_SHIFT                     (6U)                                                /*!< INTC0_IPRL.INT6 Position                */
#define INTC_IPRL_INT6(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< INTC0_IPRL.INT6 Field                   */
#define INTC_IPRL_INT7_MASK                      (0x80U)                                             /*!< INTC0_IPRL.INT7 Mask                    */
#define INTC_IPRL_INT7_SHIFT                     (7U)                                                /*!< INTC0_IPRL.INT7 Position                */
#define INTC_IPRL_INT7(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< INTC0_IPRL.INT7 Field                   */
#define INTC_IPRL_INT8_MASK                      (0x100U)                                            /*!< INTC0_IPRL.INT8 Mask                    */
#define INTC_IPRL_INT8_SHIFT                     (8U)                                                /*!< INTC0_IPRL.INT8 Position                */
#define INTC_IPRL_INT8(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< INTC0_IPRL.INT8 Field                   */
#define INTC_IPRL_INT9_MASK                      (0x200U)                                            /*!< INTC0_IPRL.INT9 Mask                    */
#define INTC_IPRL_INT9_SHIFT                     (9U)                                                /*!< INTC0_IPRL.INT9 Position                */
#define INTC_IPRL_INT9(x)                        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< INTC0_IPRL.INT9 Field                   */
#define INTC_IPRL_INT10_MASK                     (0x400U)                                            /*!< INTC0_IPRL.INT10 Mask                   */
#define INTC_IPRL_INT10_SHIFT                    (10U)                                               /*!< INTC0_IPRL.INT10 Position               */
#define INTC_IPRL_INT10(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< INTC0_IPRL.INT10 Field                  */
#define INTC_IPRL_INT11_MASK                     (0x800U)                                            /*!< INTC0_IPRL.INT11 Mask                   */
#define INTC_IPRL_INT11_SHIFT                    (11U)                                               /*!< INTC0_IPRL.INT11 Position               */
#define INTC_IPRL_INT11(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< INTC0_IPRL.INT11 Field                  */
#define INTC_IPRL_INT12_MASK                     (0x1000U)                                           /*!< INTC0_IPRL.INT12 Mask                   */
#define INTC_IPRL_INT12_SHIFT                    (12U)                                               /*!< INTC0_IPRL.INT12 Position               */
#define INTC_IPRL_INT12(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< INTC0_IPRL.INT12 Field                  */
#define INTC_IPRL_INT13_MASK                     (0x2000U)                                           /*!< INTC0_IPRL.INT13 Mask                   */
#define INTC_IPRL_INT13_SHIFT                    (13U)                                               /*!< INTC0_IPRL.INT13 Position               */
#define INTC_IPRL_INT13(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< INTC0_IPRL.INT13 Field                  */
#define INTC_IPRL_INT14_MASK                     (0x4000U)                                           /*!< INTC0_IPRL.INT14 Mask                   */
#define INTC_IPRL_INT14_SHIFT                    (14U)                                               /*!< INTC0_IPRL.INT14 Position               */
#define INTC_IPRL_INT14(x)                       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< INTC0_IPRL.INT14 Field                  */
#define INTC_IPRL_INT15_MASK                     (0x8000U)                                           /*!< INTC0_IPRL.INT15 Mask                   */
#define INTC_IPRL_INT15_SHIFT                    (15U)                                               /*!< INTC0_IPRL.INT15 Position               */
#define INTC_IPRL_INT15(x)                       (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< INTC0_IPRL.INT15 Field                  */
#define INTC_IPRL_INT16_MASK                     (0x10000U)                                          /*!< INTC0_IPRL.INT16 Mask                   */
#define INTC_IPRL_INT16_SHIFT                    (16U)                                               /*!< INTC0_IPRL.INT16 Position               */
#define INTC_IPRL_INT16(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< INTC0_IPRL.INT16 Field                  */
#define INTC_IPRL_INT17_MASK                     (0x20000U)                                          /*!< INTC0_IPRL.INT17 Mask                   */
#define INTC_IPRL_INT17_SHIFT                    (17U)                                               /*!< INTC0_IPRL.INT17 Position               */
#define INTC_IPRL_INT17(x)                       (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< INTC0_IPRL.INT17 Field                  */
#define INTC_IPRL_INT18_MASK                     (0x40000U)                                          /*!< INTC0_IPRL.INT18 Mask                   */
#define INTC_IPRL_INT18_SHIFT                    (18U)                                               /*!< INTC0_IPRL.INT18 Position               */
#define INTC_IPRL_INT18(x)                       (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< INTC0_IPRL.INT18 Field                  */
#define INTC_IPRL_INT19_MASK                     (0x80000U)                                          /*!< INTC0_IPRL.INT19 Mask                   */
#define INTC_IPRL_INT19_SHIFT                    (19U)                                               /*!< INTC0_IPRL.INT19 Position               */
#define INTC_IPRL_INT19(x)                       (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< INTC0_IPRL.INT19 Field                  */
#define INTC_IPRL_INT20_MASK                     (0x100000U)                                         /*!< INTC0_IPRL.INT20 Mask                   */
#define INTC_IPRL_INT20_SHIFT                    (20U)                                               /*!< INTC0_IPRL.INT20 Position               */
#define INTC_IPRL_INT20(x)                       (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< INTC0_IPRL.INT20 Field                  */
#define INTC_IPRL_INT21_MASK                     (0x200000U)                                         /*!< INTC0_IPRL.INT21 Mask                   */
#define INTC_IPRL_INT21_SHIFT                    (21U)                                               /*!< INTC0_IPRL.INT21 Position               */
#define INTC_IPRL_INT21(x)                       (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< INTC0_IPRL.INT21 Field                  */
#define INTC_IPRL_INT22_MASK                     (0x400000U)                                         /*!< INTC0_IPRL.INT22 Mask                   */
#define INTC_IPRL_INT22_SHIFT                    (22U)                                               /*!< INTC0_IPRL.INT22 Position               */
#define INTC_IPRL_INT22(x)                       (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< INTC0_IPRL.INT22 Field                  */
#define INTC_IPRL_INT23_MASK                     (0x800000U)                                         /*!< INTC0_IPRL.INT23 Mask                   */
#define INTC_IPRL_INT23_SHIFT                    (23U)                                               /*!< INTC0_IPRL.INT23 Position               */
#define INTC_IPRL_INT23(x)                       (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< INTC0_IPRL.INT23 Field                  */
#define INTC_IPRL_INT24_MASK                     (0x1000000U)                                        /*!< INTC0_IPRL.INT24 Mask                   */
#define INTC_IPRL_INT24_SHIFT                    (24U)                                               /*!< INTC0_IPRL.INT24 Position               */
#define INTC_IPRL_INT24(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< INTC0_IPRL.INT24 Field                  */
#define INTC_IPRL_INT25_MASK                     (0x2000000U)                                        /*!< INTC0_IPRL.INT25 Mask                   */
#define INTC_IPRL_INT25_SHIFT                    (25U)                                               /*!< INTC0_IPRL.INT25 Position               */
#define INTC_IPRL_INT25(x)                       (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< INTC0_IPRL.INT25 Field                  */
#define INTC_IPRL_INT26_MASK                     (0x4000000U)                                        /*!< INTC0_IPRL.INT26 Mask                   */
#define INTC_IPRL_INT26_SHIFT                    (26U)                                               /*!< INTC0_IPRL.INT26 Position               */
#define INTC_IPRL_INT26(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< INTC0_IPRL.INT26 Field                  */
#define INTC_IPRL_INT27_MASK                     (0x8000000U)                                        /*!< INTC0_IPRL.INT27 Mask                   */
#define INTC_IPRL_INT27_SHIFT                    (27U)                                               /*!< INTC0_IPRL.INT27 Position               */
#define INTC_IPRL_INT27(x)                       (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< INTC0_IPRL.INT27 Field                  */
#define INTC_IPRL_INT28_MASK                     (0x10000000U)                                       /*!< INTC0_IPRL.INT28 Mask                   */
#define INTC_IPRL_INT28_SHIFT                    (28U)                                               /*!< INTC0_IPRL.INT28 Position               */
#define INTC_IPRL_INT28(x)                       (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< INTC0_IPRL.INT28 Field                  */
#define INTC_IPRL_INT29_MASK                     (0x20000000U)                                       /*!< INTC0_IPRL.INT29 Mask                   */
#define INTC_IPRL_INT29_SHIFT                    (29U)                                               /*!< INTC0_IPRL.INT29 Position               */
#define INTC_IPRL_INT29(x)                       (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< INTC0_IPRL.INT29 Field                  */
#define INTC_IPRL_INT30_MASK                     (0x40000000U)                                       /*!< INTC0_IPRL.INT30 Mask                   */
#define INTC_IPRL_INT30_SHIFT                    (30U)                                               /*!< INTC0_IPRL.INT30 Position               */
#define INTC_IPRL_INT30(x)                       (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< INTC0_IPRL.INT30 Field                  */
#define INTC_IPRL_INT31_MASK                     (0x80000000U)                                       /*!< INTC0_IPRL.INT31 Mask                   */
#define INTC_IPRL_INT31_SHIFT                    (31U)                                               /*!< INTC0_IPRL.INT31 Position               */
#define INTC_IPRL_INT31(x)                       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< INTC0_IPRL.INT31 Field                  */
/* ------- IMRH Bit Fields                          ------ */
#define INTC_IMRH_MASK32_MASK                    (0x1U)                                              /*!< INTC0_IMRH.MASK32 Mask                  */
#define INTC_IMRH_MASK32_SHIFT                   (0U)                                                /*!< INTC0_IMRH.MASK32 Position              */
#define INTC_IMRH_MASK32(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< INTC0_IMRH.MASK32 Field                 */
#define INTC_IMRH_MASK33_MASK                    (0x2U)                                              /*!< INTC0_IMRH.MASK33 Mask                  */
#define INTC_IMRH_MASK33_SHIFT                   (1U)                                                /*!< INTC0_IMRH.MASK33 Position              */
#define INTC_IMRH_MASK33(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< INTC0_IMRH.MASK33 Field                 */
#define INTC_IMRH_MASK34_MASK                    (0x4U)                                              /*!< INTC0_IMRH.MASK34 Mask                  */
#define INTC_IMRH_MASK34_SHIFT                   (2U)                                                /*!< INTC0_IMRH.MASK34 Position              */
#define INTC_IMRH_MASK34(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< INTC0_IMRH.MASK34 Field                 */
#define INTC_IMRH_MASK35_MASK                    (0x8U)                                              /*!< INTC0_IMRH.MASK35 Mask                  */
#define INTC_IMRH_MASK35_SHIFT                   (3U)                                                /*!< INTC0_IMRH.MASK35 Position              */
#define INTC_IMRH_MASK35(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< INTC0_IMRH.MASK35 Field                 */
#define INTC_IMRH_MASK36_MASK                    (0x10U)                                             /*!< INTC0_IMRH.MASK36 Mask                  */
#define INTC_IMRH_MASK36_SHIFT                   (4U)                                                /*!< INTC0_IMRH.MASK36 Position              */
#define INTC_IMRH_MASK36(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< INTC0_IMRH.MASK36 Field                 */
#define INTC_IMRH_MASK37_MASK                    (0x20U)                                             /*!< INTC0_IMRH.MASK37 Mask                  */
#define INTC_IMRH_MASK37_SHIFT                   (5U)                                                /*!< INTC0_IMRH.MASK37 Position              */
#define INTC_IMRH_MASK37(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< INTC0_IMRH.MASK37 Field                 */
#define INTC_IMRH_MASK38_MASK                    (0x40U)                                             /*!< INTC0_IMRH.MASK38 Mask                  */
#define INTC_IMRH_MASK38_SHIFT                   (6U)                                                /*!< INTC0_IMRH.MASK38 Position              */
#define INTC_IMRH_MASK38(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< INTC0_IMRH.MASK38 Field                 */
#define INTC_IMRH_MASK39_MASK                    (0x80U)                                             /*!< INTC0_IMRH.MASK39 Mask                  */
#define INTC_IMRH_MASK39_SHIFT                   (7U)                                                /*!< INTC0_IMRH.MASK39 Position              */
#define INTC_IMRH_MASK39(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< INTC0_IMRH.MASK39 Field                 */
#define INTC_IMRH_MASK40_MASK                    (0x100U)                                            /*!< INTC0_IMRH.MASK40 Mask                  */
#define INTC_IMRH_MASK40_SHIFT                   (8U)                                                /*!< INTC0_IMRH.MASK40 Position              */
#define INTC_IMRH_MASK40(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< INTC0_IMRH.MASK40 Field                 */
#define INTC_IMRH_MASK41_MASK                    (0x200U)                                            /*!< INTC0_IMRH.MASK41 Mask                  */
#define INTC_IMRH_MASK41_SHIFT                   (9U)                                                /*!< INTC0_IMRH.MASK41 Position              */
#define INTC_IMRH_MASK41(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< INTC0_IMRH.MASK41 Field                 */
#define INTC_IMRH_MASK42_MASK                    (0x400U)                                            /*!< INTC0_IMRH.MASK42 Mask                  */
#define INTC_IMRH_MASK42_SHIFT                   (10U)                                               /*!< INTC0_IMRH.MASK42 Position              */
#define INTC_IMRH_MASK42(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< INTC0_IMRH.MASK42 Field                 */
#define INTC_IMRH_MASK43_MASK                    (0x800U)                                            /*!< INTC0_IMRH.MASK43 Mask                  */
#define INTC_IMRH_MASK43_SHIFT                   (11U)                                               /*!< INTC0_IMRH.MASK43 Position              */
#define INTC_IMRH_MASK43(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< INTC0_IMRH.MASK43 Field                 */
#define INTC_IMRH_MASK44_MASK                    (0x1000U)                                           /*!< INTC0_IMRH.MASK44 Mask                  */
#define INTC_IMRH_MASK44_SHIFT                   (12U)                                               /*!< INTC0_IMRH.MASK44 Position              */
#define INTC_IMRH_MASK44(x)                      (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< INTC0_IMRH.MASK44 Field                 */
#define INTC_IMRH_MASK45_MASK                    (0x2000U)                                           /*!< INTC0_IMRH.MASK45 Mask                  */
#define INTC_IMRH_MASK45_SHIFT                   (13U)                                               /*!< INTC0_IMRH.MASK45 Position              */
#define INTC_IMRH_MASK45(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< INTC0_IMRH.MASK45 Field                 */
#define INTC_IMRH_MASK46_MASK                    (0x4000U)                                           /*!< INTC0_IMRH.MASK46 Mask                  */
#define INTC_IMRH_MASK46_SHIFT                   (14U)                                               /*!< INTC0_IMRH.MASK46 Position              */
#define INTC_IMRH_MASK46(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< INTC0_IMRH.MASK46 Field                 */
#define INTC_IMRH_MASK47_MASK                    (0x8000U)                                           /*!< INTC0_IMRH.MASK47 Mask                  */
#define INTC_IMRH_MASK47_SHIFT                   (15U)                                               /*!< INTC0_IMRH.MASK47 Position              */
#define INTC_IMRH_MASK47(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< INTC0_IMRH.MASK47 Field                 */
#define INTC_IMRH_MASK48_MASK                    (0x10000U)                                          /*!< INTC0_IMRH.MASK48 Mask                  */
#define INTC_IMRH_MASK48_SHIFT                   (16U)                                               /*!< INTC0_IMRH.MASK48 Position              */
#define INTC_IMRH_MASK48(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< INTC0_IMRH.MASK48 Field                 */
#define INTC_IMRH_MASK49_MASK                    (0x20000U)                                          /*!< INTC0_IMRH.MASK49 Mask                  */
#define INTC_IMRH_MASK49_SHIFT                   (17U)                                               /*!< INTC0_IMRH.MASK49 Position              */
#define INTC_IMRH_MASK49(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< INTC0_IMRH.MASK49 Field                 */
#define INTC_IMRH_MASK50_MASK                    (0x40000U)                                          /*!< INTC0_IMRH.MASK50 Mask                  */
#define INTC_IMRH_MASK50_SHIFT                   (18U)                                               /*!< INTC0_IMRH.MASK50 Position              */
#define INTC_IMRH_MASK50(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< INTC0_IMRH.MASK50 Field                 */
#define INTC_IMRH_MASK51_MASK                    (0x80000U)                                          /*!< INTC0_IMRH.MASK51 Mask                  */
#define INTC_IMRH_MASK51_SHIFT                   (19U)                                               /*!< INTC0_IMRH.MASK51 Position              */
#define INTC_IMRH_MASK51(x)                      (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< INTC0_IMRH.MASK51 Field                 */
#define INTC_IMRH_MASK52_MASK                    (0x100000U)                                         /*!< INTC0_IMRH.MASK52 Mask                  */
#define INTC_IMRH_MASK52_SHIFT                   (20U)                                               /*!< INTC0_IMRH.MASK52 Position              */
#define INTC_IMRH_MASK52(x)                      (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< INTC0_IMRH.MASK52 Field                 */
#define INTC_IMRH_MASK53_MASK                    (0x200000U)                                         /*!< INTC0_IMRH.MASK53 Mask                  */
#define INTC_IMRH_MASK53_SHIFT                   (21U)                                               /*!< INTC0_IMRH.MASK53 Position              */
#define INTC_IMRH_MASK53(x)                      (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< INTC0_IMRH.MASK53 Field                 */
#define INTC_IMRH_MASK54_MASK                    (0x400000U)                                         /*!< INTC0_IMRH.MASK54 Mask                  */
#define INTC_IMRH_MASK54_SHIFT                   (22U)                                               /*!< INTC0_IMRH.MASK54 Position              */
#define INTC_IMRH_MASK54(x)                      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< INTC0_IMRH.MASK54 Field                 */
#define INTC_IMRH_MASK55_MASK                    (0x800000U)                                         /*!< INTC0_IMRH.MASK55 Mask                  */
#define INTC_IMRH_MASK55_SHIFT                   (23U)                                               /*!< INTC0_IMRH.MASK55 Position              */
#define INTC_IMRH_MASK55(x)                      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< INTC0_IMRH.MASK55 Field                 */
#define INTC_IMRH_MASK56_MASK                    (0x1000000U)                                        /*!< INTC0_IMRH.MASK56 Mask                  */
#define INTC_IMRH_MASK56_SHIFT                   (24U)                                               /*!< INTC0_IMRH.MASK56 Position              */
#define INTC_IMRH_MASK56(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< INTC0_IMRH.MASK56 Field                 */
#define INTC_IMRH_MASK57_MASK                    (0x2000000U)                                        /*!< INTC0_IMRH.MASK57 Mask                  */
#define INTC_IMRH_MASK57_SHIFT                   (25U)                                               /*!< INTC0_IMRH.MASK57 Position              */
#define INTC_IMRH_MASK57(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< INTC0_IMRH.MASK57 Field                 */
#define INTC_IMRH_MASK58_MASK                    (0x4000000U)                                        /*!< INTC0_IMRH.MASK58 Mask                  */
#define INTC_IMRH_MASK58_SHIFT                   (26U)                                               /*!< INTC0_IMRH.MASK58 Position              */
#define INTC_IMRH_MASK58(x)                      (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< INTC0_IMRH.MASK58 Field                 */
#define INTC_IMRH_MASK59_MASK                    (0x8000000U)                                        /*!< INTC0_IMRH.MASK59 Mask                  */
#define INTC_IMRH_MASK59_SHIFT                   (27U)                                               /*!< INTC0_IMRH.MASK59 Position              */
#define INTC_IMRH_MASK59(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< INTC0_IMRH.MASK59 Field                 */
#define INTC_IMRH_MASK60_MASK                    (0x10000000U)                                       /*!< INTC0_IMRH.MASK60 Mask                  */
#define INTC_IMRH_MASK60_SHIFT                   (28U)                                               /*!< INTC0_IMRH.MASK60 Position              */
#define INTC_IMRH_MASK60(x)                      (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< INTC0_IMRH.MASK60 Field                 */
#define INTC_IMRH_MASK61_MASK                    (0x20000000U)                                       /*!< INTC0_IMRH.MASK61 Mask                  */
#define INTC_IMRH_MASK61_SHIFT                   (29U)                                               /*!< INTC0_IMRH.MASK61 Position              */
#define INTC_IMRH_MASK61(x)                      (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< INTC0_IMRH.MASK61 Field                 */
#define INTC_IMRH_MASK62_MASK                    (0x40000000U)                                       /*!< INTC0_IMRH.MASK62 Mask                  */
#define INTC_IMRH_MASK62_SHIFT                   (30U)                                               /*!< INTC0_IMRH.MASK62 Position              */
#define INTC_IMRH_MASK62(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< INTC0_IMRH.MASK62 Field                 */
#define INTC_IMRH_MASK63_MASK                    (0x80000000U)                                       /*!< INTC0_IMRH.MASK63 Mask                  */
#define INTC_IMRH_MASK63_SHIFT                   (31U)                                               /*!< INTC0_IMRH.MASK63 Position              */
#define INTC_IMRH_MASK63(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< INTC0_IMRH.MASK63 Field                 */
/* ------- IMRL Bit Fields                          ------ */
#define INTC_IMRL_MASKALL_MASK                   (0x1U)                                              /*!< INTC0_IMRL.MASKALL Mask                 */
#define INTC_IMRL_MASKALL_SHIFT                  (0U)                                                /*!< INTC0_IMRL.MASKALL Position             */
#define INTC_IMRL_MASKALL(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< INTC0_IMRL.MASKALL Field                */
#define INTC_IMRL_MASK1_MASK                     (0x2U)                                              /*!< INTC0_IMRL.MASK1 Mask                   */
#define INTC_IMRL_MASK1_SHIFT                    (1U)                                                /*!< INTC0_IMRL.MASK1 Position               */
#define INTC_IMRL_MASK1(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< INTC0_IMRL.MASK1 Field                  */
#define INTC_IMRL_MASK2_MASK                     (0x4U)                                              /*!< INTC0_IMRL.MASK2 Mask                   */
#define INTC_IMRL_MASK2_SHIFT                    (2U)                                                /*!< INTC0_IMRL.MASK2 Position               */
#define INTC_IMRL_MASK2(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< INTC0_IMRL.MASK2 Field                  */
#define INTC_IMRL_MASK3_MASK                     (0x8U)                                              /*!< INTC0_IMRL.MASK3 Mask                   */
#define INTC_IMRL_MASK3_SHIFT                    (3U)                                                /*!< INTC0_IMRL.MASK3 Position               */
#define INTC_IMRL_MASK3(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< INTC0_IMRL.MASK3 Field                  */
#define INTC_IMRL_MASK4_MASK                     (0x10U)                                             /*!< INTC0_IMRL.MASK4 Mask                   */
#define INTC_IMRL_MASK4_SHIFT                    (4U)                                                /*!< INTC0_IMRL.MASK4 Position               */
#define INTC_IMRL_MASK4(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< INTC0_IMRL.MASK4 Field                  */
#define INTC_IMRL_MASK5_MASK                     (0x20U)                                             /*!< INTC0_IMRL.MASK5 Mask                   */
#define INTC_IMRL_MASK5_SHIFT                    (5U)                                                /*!< INTC0_IMRL.MASK5 Position               */
#define INTC_IMRL_MASK5(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< INTC0_IMRL.MASK5 Field                  */
#define INTC_IMRL_MASK6_MASK                     (0x40U)                                             /*!< INTC0_IMRL.MASK6 Mask                   */
#define INTC_IMRL_MASK6_SHIFT                    (6U)                                                /*!< INTC0_IMRL.MASK6 Position               */
#define INTC_IMRL_MASK6(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< INTC0_IMRL.MASK6 Field                  */
#define INTC_IMRL_MASK7_MASK                     (0x80U)                                             /*!< INTC0_IMRL.MASK7 Mask                   */
#define INTC_IMRL_MASK7_SHIFT                    (7U)                                                /*!< INTC0_IMRL.MASK7 Position               */
#define INTC_IMRL_MASK7(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< INTC0_IMRL.MASK7 Field                  */
#define INTC_IMRL_MASK8_MASK                     (0x100U)                                            /*!< INTC0_IMRL.MASK8 Mask                   */
#define INTC_IMRL_MASK8_SHIFT                    (8U)                                                /*!< INTC0_IMRL.MASK8 Position               */
#define INTC_IMRL_MASK8(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< INTC0_IMRL.MASK8 Field                  */
#define INTC_IMRL_MASK9_MASK                     (0x200U)                                            /*!< INTC0_IMRL.MASK9 Mask                   */
#define INTC_IMRL_MASK9_SHIFT                    (9U)                                                /*!< INTC0_IMRL.MASK9 Position               */
#define INTC_IMRL_MASK9(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< INTC0_IMRL.MASK9 Field                  */
#define INTC_IMRL_MASK10_MASK                    (0x400U)                                            /*!< INTC0_IMRL.MASK10 Mask                  */
#define INTC_IMRL_MASK10_SHIFT                   (10U)                                               /*!< INTC0_IMRL.MASK10 Position              */
#define INTC_IMRL_MASK10(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< INTC0_IMRL.MASK10 Field                 */
#define INTC_IMRL_MASK11_MASK                    (0x800U)                                            /*!< INTC0_IMRL.MASK11 Mask                  */
#define INTC_IMRL_MASK11_SHIFT                   (11U)                                               /*!< INTC0_IMRL.MASK11 Position              */
#define INTC_IMRL_MASK11(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< INTC0_IMRL.MASK11 Field                 */
#define INTC_IMRL_MASK12_MASK                    (0x1000U)                                           /*!< INTC0_IMRL.MASK12 Mask                  */
#define INTC_IMRL_MASK12_SHIFT                   (12U)                                               /*!< INTC0_IMRL.MASK12 Position              */
#define INTC_IMRL_MASK12(x)                      (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< INTC0_IMRL.MASK12 Field                 */
#define INTC_IMRL_MASK13_MASK                    (0x2000U)                                           /*!< INTC0_IMRL.MASK13 Mask                  */
#define INTC_IMRL_MASK13_SHIFT                   (13U)                                               /*!< INTC0_IMRL.MASK13 Position              */
#define INTC_IMRL_MASK13(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< INTC0_IMRL.MASK13 Field                 */
#define INTC_IMRL_MASK14_MASK                    (0x4000U)                                           /*!< INTC0_IMRL.MASK14 Mask                  */
#define INTC_IMRL_MASK14_SHIFT                   (14U)                                               /*!< INTC0_IMRL.MASK14 Position              */
#define INTC_IMRL_MASK14(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< INTC0_IMRL.MASK14 Field                 */
#define INTC_IMRL_MASK15_MASK                    (0x8000U)                                           /*!< INTC0_IMRL.MASK15 Mask                  */
#define INTC_IMRL_MASK15_SHIFT                   (15U)                                               /*!< INTC0_IMRL.MASK15 Position              */
#define INTC_IMRL_MASK15(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< INTC0_IMRL.MASK15 Field                 */
#define INTC_IMRL_MASK16_MASK                    (0x10000U)                                          /*!< INTC0_IMRL.MASK16 Mask                  */
#define INTC_IMRL_MASK16_SHIFT                   (16U)                                               /*!< INTC0_IMRL.MASK16 Position              */
#define INTC_IMRL_MASK16(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< INTC0_IMRL.MASK16 Field                 */
#define INTC_IMRL_MASK17_MASK                    (0x20000U)                                          /*!< INTC0_IMRL.MASK17 Mask                  */
#define INTC_IMRL_MASK17_SHIFT                   (17U)                                               /*!< INTC0_IMRL.MASK17 Position              */
#define INTC_IMRL_MASK17(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< INTC0_IMRL.MASK17 Field                 */
#define INTC_IMRL_MASK18_MASK                    (0x40000U)                                          /*!< INTC0_IMRL.MASK18 Mask                  */
#define INTC_IMRL_MASK18_SHIFT                   (18U)                                               /*!< INTC0_IMRL.MASK18 Position              */
#define INTC_IMRL_MASK18(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< INTC0_IMRL.MASK18 Field                 */
#define INTC_IMRL_MASK19_MASK                    (0x80000U)                                          /*!< INTC0_IMRL.MASK19 Mask                  */
#define INTC_IMRL_MASK19_SHIFT                   (19U)                                               /*!< INTC0_IMRL.MASK19 Position              */
#define INTC_IMRL_MASK19(x)                      (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< INTC0_IMRL.MASK19 Field                 */
#define INTC_IMRL_MASK20_MASK                    (0x100000U)                                         /*!< INTC0_IMRL.MASK20 Mask                  */
#define INTC_IMRL_MASK20_SHIFT                   (20U)                                               /*!< INTC0_IMRL.MASK20 Position              */
#define INTC_IMRL_MASK20(x)                      (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< INTC0_IMRL.MASK20 Field                 */
#define INTC_IMRL_MASK21_MASK                    (0x200000U)                                         /*!< INTC0_IMRL.MASK21 Mask                  */
#define INTC_IMRL_MASK21_SHIFT                   (21U)                                               /*!< INTC0_IMRL.MASK21 Position              */
#define INTC_IMRL_MASK21(x)                      (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< INTC0_IMRL.MASK21 Field                 */
#define INTC_IMRL_MASK22_MASK                    (0x400000U)                                         /*!< INTC0_IMRL.MASK22 Mask                  */
#define INTC_IMRL_MASK22_SHIFT                   (22U)                                               /*!< INTC0_IMRL.MASK22 Position              */
#define INTC_IMRL_MASK22(x)                      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< INTC0_IMRL.MASK22 Field                 */
#define INTC_IMRL_MASK23_MASK                    (0x800000U)                                         /*!< INTC0_IMRL.MASK23 Mask                  */
#define INTC_IMRL_MASK23_SHIFT                   (23U)                                               /*!< INTC0_IMRL.MASK23 Position              */
#define INTC_IMRL_MASK23(x)                      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< INTC0_IMRL.MASK23 Field                 */
#define INTC_IMRL_MASK24_MASK                    (0x1000000U)                                        /*!< INTC0_IMRL.MASK24 Mask                  */
#define INTC_IMRL_MASK24_SHIFT                   (24U)                                               /*!< INTC0_IMRL.MASK24 Position              */
#define INTC_IMRL_MASK24(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< INTC0_IMRL.MASK24 Field                 */
#define INTC_IMRL_MASK25_MASK                    (0x2000000U)                                        /*!< INTC0_IMRL.MASK25 Mask                  */
#define INTC_IMRL_MASK25_SHIFT                   (25U)                                               /*!< INTC0_IMRL.MASK25 Position              */
#define INTC_IMRL_MASK25(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< INTC0_IMRL.MASK25 Field                 */
#define INTC_IMRL_MASK26_MASK                    (0x4000000U)                                        /*!< INTC0_IMRL.MASK26 Mask                  */
#define INTC_IMRL_MASK26_SHIFT                   (26U)                                               /*!< INTC0_IMRL.MASK26 Position              */
#define INTC_IMRL_MASK26(x)                      (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< INTC0_IMRL.MASK26 Field                 */
#define INTC_IMRL_MASK27_MASK                    (0x8000000U)                                        /*!< INTC0_IMRL.MASK27 Mask                  */
#define INTC_IMRL_MASK27_SHIFT                   (27U)                                               /*!< INTC0_IMRL.MASK27 Position              */
#define INTC_IMRL_MASK27(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< INTC0_IMRL.MASK27 Field                 */
#define INTC_IMRL_MASK28_MASK                    (0x10000000U)                                       /*!< INTC0_IMRL.MASK28 Mask                  */
#define INTC_IMRL_MASK28_SHIFT                   (28U)                                               /*!< INTC0_IMRL.MASK28 Position              */
#define INTC_IMRL_MASK28(x)                      (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< INTC0_IMRL.MASK28 Field                 */
#define INTC_IMRL_MASK29_MASK                    (0x20000000U)                                       /*!< INTC0_IMRL.MASK29 Mask                  */
#define INTC_IMRL_MASK29_SHIFT                   (29U)                                               /*!< INTC0_IMRL.MASK29 Position              */
#define INTC_IMRL_MASK29(x)                      (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< INTC0_IMRL.MASK29 Field                 */
#define INTC_IMRL_MASK30_MASK                    (0x40000000U)                                       /*!< INTC0_IMRL.MASK30 Mask                  */
#define INTC_IMRL_MASK30_SHIFT                   (30U)                                               /*!< INTC0_IMRL.MASK30 Position              */
#define INTC_IMRL_MASK30(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< INTC0_IMRL.MASK30 Field                 */
#define INTC_IMRL_MASK31_MASK                    (0x80000000U)                                       /*!< INTC0_IMRL.MASK31 Mask                  */
#define INTC_IMRL_MASK31_SHIFT                   (31U)                                               /*!< INTC0_IMRL.MASK31 Position              */
#define INTC_IMRL_MASK31(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< INTC0_IMRL.MASK31 Field                 */
/* ------- INTFRCH Bit Fields                       ------ */
#define INTC_INTFRCH_FRCH32_MASK                 (0x1U)                                              /*!< INTC0_INTFRCH.FRCH32 Mask               */
#define INTC_INTFRCH_FRCH32_SHIFT                (0U)                                                /*!< INTC0_INTFRCH.FRCH32 Position           */
#define INTC_INTFRCH_FRCH32(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< INTC0_INTFRCH.FRCH32 Field              */
#define INTC_INTFRCH_FRCH33_MASK                 (0x2U)                                              /*!< INTC0_INTFRCH.FRCH33 Mask               */
#define INTC_INTFRCH_FRCH33_SHIFT                (1U)                                                /*!< INTC0_INTFRCH.FRCH33 Position           */
#define INTC_INTFRCH_FRCH33(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< INTC0_INTFRCH.FRCH33 Field              */
#define INTC_INTFRCH_FRCH34_MASK                 (0x4U)                                              /*!< INTC0_INTFRCH.FRCH34 Mask               */
#define INTC_INTFRCH_FRCH34_SHIFT                (2U)                                                /*!< INTC0_INTFRCH.FRCH34 Position           */
#define INTC_INTFRCH_FRCH34(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< INTC0_INTFRCH.FRCH34 Field              */
#define INTC_INTFRCH_FRCH35_MASK                 (0x8U)                                              /*!< INTC0_INTFRCH.FRCH35 Mask               */
#define INTC_INTFRCH_FRCH35_SHIFT                (3U)                                                /*!< INTC0_INTFRCH.FRCH35 Position           */
#define INTC_INTFRCH_FRCH35(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< INTC0_INTFRCH.FRCH35 Field              */
#define INTC_INTFRCH_FRCH36_MASK                 (0x10U)                                             /*!< INTC0_INTFRCH.FRCH36 Mask               */
#define INTC_INTFRCH_FRCH36_SHIFT                (4U)                                                /*!< INTC0_INTFRCH.FRCH36 Position           */
#define INTC_INTFRCH_FRCH36(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< INTC0_INTFRCH.FRCH36 Field              */
#define INTC_INTFRCH_FRCH37_MASK                 (0x20U)                                             /*!< INTC0_INTFRCH.FRCH37 Mask               */
#define INTC_INTFRCH_FRCH37_SHIFT                (5U)                                                /*!< INTC0_INTFRCH.FRCH37 Position           */
#define INTC_INTFRCH_FRCH37(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< INTC0_INTFRCH.FRCH37 Field              */
#define INTC_INTFRCH_FRCH38_MASK                 (0x40U)                                             /*!< INTC0_INTFRCH.FRCH38 Mask               */
#define INTC_INTFRCH_FRCH38_SHIFT                (6U)                                                /*!< INTC0_INTFRCH.FRCH38 Position           */
#define INTC_INTFRCH_FRCH38(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< INTC0_INTFRCH.FRCH38 Field              */
#define INTC_INTFRCH_FRCH39_MASK                 (0x80U)                                             /*!< INTC0_INTFRCH.FRCH39 Mask               */
#define INTC_INTFRCH_FRCH39_SHIFT                (7U)                                                /*!< INTC0_INTFRCH.FRCH39 Position           */
#define INTC_INTFRCH_FRCH39(x)                   (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< INTC0_INTFRCH.FRCH39 Field              */
#define INTC_INTFRCH_FRCH40_MASK                 (0x100U)                                            /*!< INTC0_INTFRCH.FRCH40 Mask               */
#define INTC_INTFRCH_FRCH40_SHIFT                (8U)                                                /*!< INTC0_INTFRCH.FRCH40 Position           */
#define INTC_INTFRCH_FRCH40(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< INTC0_INTFRCH.FRCH40 Field              */
#define INTC_INTFRCH_FRCH41_MASK                 (0x200U)                                            /*!< INTC0_INTFRCH.FRCH41 Mask               */
#define INTC_INTFRCH_FRCH41_SHIFT                (9U)                                                /*!< INTC0_INTFRCH.FRCH41 Position           */
#define INTC_INTFRCH_FRCH41(x)                   (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< INTC0_INTFRCH.FRCH41 Field              */
#define INTC_INTFRCH_FRCH42_MASK                 (0x400U)                                            /*!< INTC0_INTFRCH.FRCH42 Mask               */
#define INTC_INTFRCH_FRCH42_SHIFT                (10U)                                               /*!< INTC0_INTFRCH.FRCH42 Position           */
#define INTC_INTFRCH_FRCH42(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< INTC0_INTFRCH.FRCH42 Field              */
#define INTC_INTFRCH_FRCH43_MASK                 (0x800U)                                            /*!< INTC0_INTFRCH.FRCH43 Mask               */
#define INTC_INTFRCH_FRCH43_SHIFT                (11U)                                               /*!< INTC0_INTFRCH.FRCH43 Position           */
#define INTC_INTFRCH_FRCH43(x)                   (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< INTC0_INTFRCH.FRCH43 Field              */
#define INTC_INTFRCH_FRCH44_MASK                 (0x1000U)                                           /*!< INTC0_INTFRCH.FRCH44 Mask               */
#define INTC_INTFRCH_FRCH44_SHIFT                (12U)                                               /*!< INTC0_INTFRCH.FRCH44 Position           */
#define INTC_INTFRCH_FRCH44(x)                   (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< INTC0_INTFRCH.FRCH44 Field              */
#define INTC_INTFRCH_FRCH45_MASK                 (0x2000U)                                           /*!< INTC0_INTFRCH.FRCH45 Mask               */
#define INTC_INTFRCH_FRCH45_SHIFT                (13U)                                               /*!< INTC0_INTFRCH.FRCH45 Position           */
#define INTC_INTFRCH_FRCH45(x)                   (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< INTC0_INTFRCH.FRCH45 Field              */
#define INTC_INTFRCH_FRCH46_MASK                 (0x4000U)                                           /*!< INTC0_INTFRCH.FRCH46 Mask               */
#define INTC_INTFRCH_FRCH46_SHIFT                (14U)                                               /*!< INTC0_INTFRCH.FRCH46 Position           */
#define INTC_INTFRCH_FRCH46(x)                   (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< INTC0_INTFRCH.FRCH46 Field              */
#define INTC_INTFRCH_FRCH47_MASK                 (0x8000U)                                           /*!< INTC0_INTFRCH.FRCH47 Mask               */
#define INTC_INTFRCH_FRCH47_SHIFT                (15U)                                               /*!< INTC0_INTFRCH.FRCH47 Position           */
#define INTC_INTFRCH_FRCH47(x)                   (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< INTC0_INTFRCH.FRCH47 Field              */
#define INTC_INTFRCH_FRCH48_MASK                 (0x10000U)                                          /*!< INTC0_INTFRCH.FRCH48 Mask               */
#define INTC_INTFRCH_FRCH48_SHIFT                (16U)                                               /*!< INTC0_INTFRCH.FRCH48 Position           */
#define INTC_INTFRCH_FRCH48(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< INTC0_INTFRCH.FRCH48 Field              */
#define INTC_INTFRCH_FRCH49_MASK                 (0x20000U)                                          /*!< INTC0_INTFRCH.FRCH49 Mask               */
#define INTC_INTFRCH_FRCH49_SHIFT                (17U)                                               /*!< INTC0_INTFRCH.FRCH49 Position           */
#define INTC_INTFRCH_FRCH49(x)                   (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< INTC0_INTFRCH.FRCH49 Field              */
#define INTC_INTFRCH_FRCH50_MASK                 (0x40000U)                                          /*!< INTC0_INTFRCH.FRCH50 Mask               */
#define INTC_INTFRCH_FRCH50_SHIFT                (18U)                                               /*!< INTC0_INTFRCH.FRCH50 Position           */
#define INTC_INTFRCH_FRCH50(x)                   (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< INTC0_INTFRCH.FRCH50 Field              */
#define INTC_INTFRCH_FRCH51_MASK                 (0x80000U)                                          /*!< INTC0_INTFRCH.FRCH51 Mask               */
#define INTC_INTFRCH_FRCH51_SHIFT                (19U)                                               /*!< INTC0_INTFRCH.FRCH51 Position           */
#define INTC_INTFRCH_FRCH51(x)                   (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< INTC0_INTFRCH.FRCH51 Field              */
#define INTC_INTFRCH_FRCH52_MASK                 (0x100000U)                                         /*!< INTC0_INTFRCH.FRCH52 Mask               */
#define INTC_INTFRCH_FRCH52_SHIFT                (20U)                                               /*!< INTC0_INTFRCH.FRCH52 Position           */
#define INTC_INTFRCH_FRCH52(x)                   (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< INTC0_INTFRCH.FRCH52 Field              */
#define INTC_INTFRCH_FRCH53_MASK                 (0x200000U)                                         /*!< INTC0_INTFRCH.FRCH53 Mask               */
#define INTC_INTFRCH_FRCH53_SHIFT                (21U)                                               /*!< INTC0_INTFRCH.FRCH53 Position           */
#define INTC_INTFRCH_FRCH53(x)                   (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< INTC0_INTFRCH.FRCH53 Field              */
#define INTC_INTFRCH_FRCH54_MASK                 (0x400000U)                                         /*!< INTC0_INTFRCH.FRCH54 Mask               */
#define INTC_INTFRCH_FRCH54_SHIFT                (22U)                                               /*!< INTC0_INTFRCH.FRCH54 Position           */
#define INTC_INTFRCH_FRCH54(x)                   (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< INTC0_INTFRCH.FRCH54 Field              */
#define INTC_INTFRCH_FRCH55_MASK                 (0x800000U)                                         /*!< INTC0_INTFRCH.FRCH55 Mask               */
#define INTC_INTFRCH_FRCH55_SHIFT                (23U)                                               /*!< INTC0_INTFRCH.FRCH55 Position           */
#define INTC_INTFRCH_FRCH55(x)                   (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< INTC0_INTFRCH.FRCH55 Field              */
#define INTC_INTFRCH_FRCH56_MASK                 (0x1000000U)                                        /*!< INTC0_INTFRCH.FRCH56 Mask               */
#define INTC_INTFRCH_FRCH56_SHIFT                (24U)                                               /*!< INTC0_INTFRCH.FRCH56 Position           */
#define INTC_INTFRCH_FRCH56(x)                   (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< INTC0_INTFRCH.FRCH56 Field              */
#define INTC_INTFRCH_FRCH57_MASK                 (0x2000000U)                                        /*!< INTC0_INTFRCH.FRCH57 Mask               */
#define INTC_INTFRCH_FRCH57_SHIFT                (25U)                                               /*!< INTC0_INTFRCH.FRCH57 Position           */
#define INTC_INTFRCH_FRCH57(x)                   (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< INTC0_INTFRCH.FRCH57 Field              */
#define INTC_INTFRCH_FRCH58_MASK                 (0x4000000U)                                        /*!< INTC0_INTFRCH.FRCH58 Mask               */
#define INTC_INTFRCH_FRCH58_SHIFT                (26U)                                               /*!< INTC0_INTFRCH.FRCH58 Position           */
#define INTC_INTFRCH_FRCH58(x)                   (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< INTC0_INTFRCH.FRCH58 Field              */
#define INTC_INTFRCH_FRCH59_MASK                 (0x8000000U)                                        /*!< INTC0_INTFRCH.FRCH59 Mask               */
#define INTC_INTFRCH_FRCH59_SHIFT                (27U)                                               /*!< INTC0_INTFRCH.FRCH59 Position           */
#define INTC_INTFRCH_FRCH59(x)                   (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< INTC0_INTFRCH.FRCH59 Field              */
#define INTC_INTFRCH_FRCH60_MASK                 (0x10000000U)                                       /*!< INTC0_INTFRCH.FRCH60 Mask               */
#define INTC_INTFRCH_FRCH60_SHIFT                (28U)                                               /*!< INTC0_INTFRCH.FRCH60 Position           */
#define INTC_INTFRCH_FRCH60(x)                   (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< INTC0_INTFRCH.FRCH60 Field              */
#define INTC_INTFRCH_FRCH61_MASK                 (0x20000000U)                                       /*!< INTC0_INTFRCH.FRCH61 Mask               */
#define INTC_INTFRCH_FRCH61_SHIFT                (29U)                                               /*!< INTC0_INTFRCH.FRCH61 Position           */
#define INTC_INTFRCH_FRCH61(x)                   (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< INTC0_INTFRCH.FRCH61 Field              */
#define INTC_INTFRCH_FRCH62_MASK                 (0x40000000U)                                       /*!< INTC0_INTFRCH.FRCH62 Mask               */
#define INTC_INTFRCH_FRCH62_SHIFT                (30U)                                               /*!< INTC0_INTFRCH.FRCH62 Position           */
#define INTC_INTFRCH_FRCH62(x)                   (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< INTC0_INTFRCH.FRCH62 Field              */
#define INTC_INTFRCH_FRCH63_MASK                 (0x80000000U)                                       /*!< INTC0_INTFRCH.FRCH63 Mask               */
#define INTC_INTFRCH_FRCH63_SHIFT                (31U)                                               /*!< INTC0_INTFRCH.FRCH63 Position           */
#define INTC_INTFRCH_FRCH63(x)                   (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< INTC0_INTFRCH.FRCH63 Field              */
/* ------- INTFRCL Bit Fields                       ------ */
#define INTC_INTFRCL_FRCH1_MASK                  (0x2U)                                              /*!< INTC0_INTFRCL.FRCH1 Mask                */
#define INTC_INTFRCL_FRCH1_SHIFT                 (1U)                                                /*!< INTC0_INTFRCL.FRCH1 Position            */
#define INTC_INTFRCL_FRCH1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< INTC0_INTFRCL.FRCH1 Field               */
#define INTC_INTFRCL_FRCH2_MASK                  (0x4U)                                              /*!< INTC0_INTFRCL.FRCH2 Mask                */
#define INTC_INTFRCL_FRCH2_SHIFT                 (2U)                                                /*!< INTC0_INTFRCL.FRCH2 Position            */
#define INTC_INTFRCL_FRCH2(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< INTC0_INTFRCL.FRCH2 Field               */
#define INTC_INTFRCL_FRCH3_MASK                  (0x8U)                                              /*!< INTC0_INTFRCL.FRCH3 Mask                */
#define INTC_INTFRCL_FRCH3_SHIFT                 (3U)                                                /*!< INTC0_INTFRCL.FRCH3 Position            */
#define INTC_INTFRCL_FRCH3(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< INTC0_INTFRCL.FRCH3 Field               */
#define INTC_INTFRCL_FRCH4_MASK                  (0x10U)                                             /*!< INTC0_INTFRCL.FRCH4 Mask                */
#define INTC_INTFRCL_FRCH4_SHIFT                 (4U)                                                /*!< INTC0_INTFRCL.FRCH4 Position            */
#define INTC_INTFRCL_FRCH4(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< INTC0_INTFRCL.FRCH4 Field               */
#define INTC_INTFRCL_FRCH5_MASK                  (0x20U)                                             /*!< INTC0_INTFRCL.FRCH5 Mask                */
#define INTC_INTFRCL_FRCH5_SHIFT                 (5U)                                                /*!< INTC0_INTFRCL.FRCH5 Position            */
#define INTC_INTFRCL_FRCH5(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< INTC0_INTFRCL.FRCH5 Field               */
#define INTC_INTFRCL_FRCH6_MASK                  (0x40U)                                             /*!< INTC0_INTFRCL.FRCH6 Mask                */
#define INTC_INTFRCL_FRCH6_SHIFT                 (6U)                                                /*!< INTC0_INTFRCL.FRCH6 Position            */
#define INTC_INTFRCL_FRCH6(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< INTC0_INTFRCL.FRCH6 Field               */
#define INTC_INTFRCL_FRCH7_MASK                  (0x80U)                                             /*!< INTC0_INTFRCL.FRCH7 Mask                */
#define INTC_INTFRCL_FRCH7_SHIFT                 (7U)                                                /*!< INTC0_INTFRCL.FRCH7 Position            */
#define INTC_INTFRCL_FRCH7(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< INTC0_INTFRCL.FRCH7 Field               */
#define INTC_INTFRCL_FRCH8_MASK                  (0x100U)                                            /*!< INTC0_INTFRCL.FRCH8 Mask                */
#define INTC_INTFRCL_FRCH8_SHIFT                 (8U)                                                /*!< INTC0_INTFRCL.FRCH8 Position            */
#define INTC_INTFRCL_FRCH8(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< INTC0_INTFRCL.FRCH8 Field               */
#define INTC_INTFRCL_FRCH9_MASK                  (0x200U)                                            /*!< INTC0_INTFRCL.FRCH9 Mask                */
#define INTC_INTFRCL_FRCH9_SHIFT                 (9U)                                                /*!< INTC0_INTFRCL.FRCH9 Position            */
#define INTC_INTFRCL_FRCH9(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< INTC0_INTFRCL.FRCH9 Field               */
#define INTC_INTFRCL_FRCH10_MASK                 (0x400U)                                            /*!< INTC0_INTFRCL.FRCH10 Mask               */
#define INTC_INTFRCL_FRCH10_SHIFT                (10U)                                               /*!< INTC0_INTFRCL.FRCH10 Position           */
#define INTC_INTFRCL_FRCH10(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< INTC0_INTFRCL.FRCH10 Field              */
#define INTC_INTFRCL_FRCH11_MASK                 (0x800U)                                            /*!< INTC0_INTFRCL.FRCH11 Mask               */
#define INTC_INTFRCL_FRCH11_SHIFT                (11U)                                               /*!< INTC0_INTFRCL.FRCH11 Position           */
#define INTC_INTFRCL_FRCH11(x)                   (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< INTC0_INTFRCL.FRCH11 Field              */
#define INTC_INTFRCL_FRCH12_MASK                 (0x1000U)                                           /*!< INTC0_INTFRCL.FRCH12 Mask               */
#define INTC_INTFRCL_FRCH12_SHIFT                (12U)                                               /*!< INTC0_INTFRCL.FRCH12 Position           */
#define INTC_INTFRCL_FRCH12(x)                   (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< INTC0_INTFRCL.FRCH12 Field              */
#define INTC_INTFRCL_FRCH13_MASK                 (0x2000U)                                           /*!< INTC0_INTFRCL.FRCH13 Mask               */
#define INTC_INTFRCL_FRCH13_SHIFT                (13U)                                               /*!< INTC0_INTFRCL.FRCH13 Position           */
#define INTC_INTFRCL_FRCH13(x)                   (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< INTC0_INTFRCL.FRCH13 Field              */
#define INTC_INTFRCL_FRCH14_MASK                 (0x4000U)                                           /*!< INTC0_INTFRCL.FRCH14 Mask               */
#define INTC_INTFRCL_FRCH14_SHIFT                (14U)                                               /*!< INTC0_INTFRCL.FRCH14 Position           */
#define INTC_INTFRCL_FRCH14(x)                   (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< INTC0_INTFRCL.FRCH14 Field              */
#define INTC_INTFRCL_FRCH15_MASK                 (0x8000U)                                           /*!< INTC0_INTFRCL.FRCH15 Mask               */
#define INTC_INTFRCL_FRCH15_SHIFT                (15U)                                               /*!< INTC0_INTFRCL.FRCH15 Position           */
#define INTC_INTFRCL_FRCH15(x)                   (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< INTC0_INTFRCL.FRCH15 Field              */
#define INTC_INTFRCL_FRCH16_MASK                 (0x10000U)                                          /*!< INTC0_INTFRCL.FRCH16 Mask               */
#define INTC_INTFRCL_FRCH16_SHIFT                (16U)                                               /*!< INTC0_INTFRCL.FRCH16 Position           */
#define INTC_INTFRCL_FRCH16(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< INTC0_INTFRCL.FRCH16 Field              */
#define INTC_INTFRCL_FRCH17_MASK                 (0x20000U)                                          /*!< INTC0_INTFRCL.FRCH17 Mask               */
#define INTC_INTFRCL_FRCH17_SHIFT                (17U)                                               /*!< INTC0_INTFRCL.FRCH17 Position           */
#define INTC_INTFRCL_FRCH17(x)                   (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< INTC0_INTFRCL.FRCH17 Field              */
#define INTC_INTFRCL_FRCH18_MASK                 (0x40000U)                                          /*!< INTC0_INTFRCL.FRCH18 Mask               */
#define INTC_INTFRCL_FRCH18_SHIFT                (18U)                                               /*!< INTC0_INTFRCL.FRCH18 Position           */
#define INTC_INTFRCL_FRCH18(x)                   (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< INTC0_INTFRCL.FRCH18 Field              */
#define INTC_INTFRCL_FRCH19_MASK                 (0x80000U)                                          /*!< INTC0_INTFRCL.FRCH19 Mask               */
#define INTC_INTFRCL_FRCH19_SHIFT                (19U)                                               /*!< INTC0_INTFRCL.FRCH19 Position           */
#define INTC_INTFRCL_FRCH19(x)                   (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< INTC0_INTFRCL.FRCH19 Field              */
#define INTC_INTFRCL_FRCH20_MASK                 (0x100000U)                                         /*!< INTC0_INTFRCL.FRCH20 Mask               */
#define INTC_INTFRCL_FRCH20_SHIFT                (20U)                                               /*!< INTC0_INTFRCL.FRCH20 Position           */
#define INTC_INTFRCL_FRCH20(x)                   (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< INTC0_INTFRCL.FRCH20 Field              */
#define INTC_INTFRCL_FRCH21_MASK                 (0x200000U)                                         /*!< INTC0_INTFRCL.FRCH21 Mask               */
#define INTC_INTFRCL_FRCH21_SHIFT                (21U)                                               /*!< INTC0_INTFRCL.FRCH21 Position           */
#define INTC_INTFRCL_FRCH21(x)                   (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< INTC0_INTFRCL.FRCH21 Field              */
#define INTC_INTFRCL_FRCH22_MASK                 (0x400000U)                                         /*!< INTC0_INTFRCL.FRCH22 Mask               */
#define INTC_INTFRCL_FRCH22_SHIFT                (22U)                                               /*!< INTC0_INTFRCL.FRCH22 Position           */
#define INTC_INTFRCL_FRCH22(x)                   (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< INTC0_INTFRCL.FRCH22 Field              */
#define INTC_INTFRCL_FRCH23_MASK                 (0x800000U)                                         /*!< INTC0_INTFRCL.FRCH23 Mask               */
#define INTC_INTFRCL_FRCH23_SHIFT                (23U)                                               /*!< INTC0_INTFRCL.FRCH23 Position           */
#define INTC_INTFRCL_FRCH23(x)                   (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< INTC0_INTFRCL.FRCH23 Field              */
#define INTC_INTFRCL_FRCH24_MASK                 (0x1000000U)                                        /*!< INTC0_INTFRCL.FRCH24 Mask               */
#define INTC_INTFRCL_FRCH24_SHIFT                (24U)                                               /*!< INTC0_INTFRCL.FRCH24 Position           */
#define INTC_INTFRCL_FRCH24(x)                   (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< INTC0_INTFRCL.FRCH24 Field              */
#define INTC_INTFRCL_FRCH25_MASK                 (0x2000000U)                                        /*!< INTC0_INTFRCL.FRCH25 Mask               */
#define INTC_INTFRCL_FRCH25_SHIFT                (25U)                                               /*!< INTC0_INTFRCL.FRCH25 Position           */
#define INTC_INTFRCL_FRCH25(x)                   (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< INTC0_INTFRCL.FRCH25 Field              */
#define INTC_INTFRCL_FRCH26_MASK                 (0x4000000U)                                        /*!< INTC0_INTFRCL.FRCH26 Mask               */
#define INTC_INTFRCL_FRCH26_SHIFT                (26U)                                               /*!< INTC0_INTFRCL.FRCH26 Position           */
#define INTC_INTFRCL_FRCH26(x)                   (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< INTC0_INTFRCL.FRCH26 Field              */
#define INTC_INTFRCL_FRCH27_MASK                 (0x8000000U)                                        /*!< INTC0_INTFRCL.FRCH27 Mask               */
#define INTC_INTFRCL_FRCH27_SHIFT                (27U)                                               /*!< INTC0_INTFRCL.FRCH27 Position           */
#define INTC_INTFRCL_FRCH27(x)                   (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< INTC0_INTFRCL.FRCH27 Field              */
#define INTC_INTFRCL_FRCH28_MASK                 (0x10000000U)                                       /*!< INTC0_INTFRCL.FRCH28 Mask               */
#define INTC_INTFRCL_FRCH28_SHIFT                (28U)                                               /*!< INTC0_INTFRCL.FRCH28 Position           */
#define INTC_INTFRCL_FRCH28(x)                   (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< INTC0_INTFRCL.FRCH28 Field              */
#define INTC_INTFRCL_FRCH29_MASK                 (0x20000000U)                                       /*!< INTC0_INTFRCL.FRCH29 Mask               */
#define INTC_INTFRCL_FRCH29_SHIFT                (29U)                                               /*!< INTC0_INTFRCL.FRCH29 Position           */
#define INTC_INTFRCL_FRCH29(x)                   (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< INTC0_INTFRCL.FRCH29 Field              */
#define INTC_INTFRCL_FRCH30_MASK                 (0x40000000U)                                       /*!< INTC0_INTFRCL.FRCH30 Mask               */
#define INTC_INTFRCL_FRCH30_SHIFT                (30U)                                               /*!< INTC0_INTFRCL.FRCH30 Position           */
#define INTC_INTFRCL_FRCH30(x)                   (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< INTC0_INTFRCL.FRCH30 Field              */
#define INTC_INTFRCL_FRCH31_MASK                 (0x80000000U)                                       /*!< INTC0_INTFRCL.FRCH31 Mask               */
#define INTC_INTFRCL_FRCH31_SHIFT                (31U)                                               /*!< INTC0_INTFRCL.FRCH31 Position           */
#define INTC_INTFRCL_FRCH31(x)                   (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< INTC0_INTFRCL.FRCH31 Field              */
/* ------- IRLR Bit Fields                          ------ */
#define INTC_IRLR_IRQ1_MASK                      (0x2U)                                              /*!< INTC0_IRLR.IRQ1 Mask                    */
#define INTC_IRLR_IRQ1_SHIFT                     (1U)                                                /*!< INTC0_IRLR.IRQ1 Position                */
#define INTC_IRLR_IRQ1(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< INTC0_IRLR.IRQ1 Field                   */
#define INTC_IRLR_IRQ2_MASK                      (0x4U)                                              /*!< INTC0_IRLR.IRQ2 Mask                    */
#define INTC_IRLR_IRQ2_SHIFT                     (2U)                                                /*!< INTC0_IRLR.IRQ2 Position                */
#define INTC_IRLR_IRQ2(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< INTC0_IRLR.IRQ2 Field                   */
#define INTC_IRLR_IRQ3_MASK                      (0x8U)                                              /*!< INTC0_IRLR.IRQ3 Mask                    */
#define INTC_IRLR_IRQ3_SHIFT                     (3U)                                                /*!< INTC0_IRLR.IRQ3 Position                */
#define INTC_IRLR_IRQ3(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< INTC0_IRLR.IRQ3 Field                   */
#define INTC_IRLR_IRQ4_MASK                      (0x10U)                                             /*!< INTC0_IRLR.IRQ4 Mask                    */
#define INTC_IRLR_IRQ4_SHIFT                     (4U)                                                /*!< INTC0_IRLR.IRQ4 Position                */
#define INTC_IRLR_IRQ4(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< INTC0_IRLR.IRQ4 Field                   */
#define INTC_IRLR_IRQ5_MASK                      (0x20U)                                             /*!< INTC0_IRLR.IRQ5 Mask                    */
#define INTC_IRLR_IRQ5_SHIFT                     (5U)                                                /*!< INTC0_IRLR.IRQ5 Position                */
#define INTC_IRLR_IRQ5(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< INTC0_IRLR.IRQ5 Field                   */
#define INTC_IRLR_IRQ6_MASK                      (0x40U)                                             /*!< INTC0_IRLR.IRQ6 Mask                    */
#define INTC_IRLR_IRQ6_SHIFT                     (6U)                                                /*!< INTC0_IRLR.IRQ6 Position                */
#define INTC_IRLR_IRQ6(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< INTC0_IRLR.IRQ6 Field                   */
#define INTC_IRLR_IRQ7_MASK                      (0x80U)                                             /*!< INTC0_IRLR.IRQ7 Mask                    */
#define INTC_IRLR_IRQ7_SHIFT                     (7U)                                                /*!< INTC0_IRLR.IRQ7 Position                */
#define INTC_IRLR_IRQ7(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< INTC0_IRLR.IRQ7 Field                   */
/* ------- IACKLPR Bit Fields                       ------ */
#define INTC_IACKLPR_PRI_MASK                    (0xFU)                                              /*!< INTC0_IACKLPR.PRI Mask                  */
#define INTC_IACKLPR_PRI_SHIFT                   (0U)                                                /*!< INTC0_IACKLPR.PRI Position              */
#define INTC_IACKLPR_PRI(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< INTC0_IACKLPR.PRI Field                 */
#define INTC_IACKLPR_LEVEL_MASK                  (0x70U)                                             /*!< INTC0_IACKLPR.LEVEL Mask                */
#define INTC_IACKLPR_LEVEL_SHIFT                 (4U)                                                /*!< INTC0_IACKLPR.LEVEL Position            */
#define INTC_IACKLPR_LEVEL(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x70UL)            /*!< INTC0_IACKLPR.LEVEL Field               */
/* ------- ICR Bit Fields                           ------ */
#define INTC_ICR_IP_MASK                         (0x7U)                                              /*!< INTC0_ICR.IP Mask                       */
#define INTC_ICR_IP_SHIFT                        (0U)                                                /*!< INTC0_ICR.IP Position                   */
#define INTC_ICR_IP(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< INTC0_ICR.IP Field                      */
#define INTC_ICR_IL_MASK                         (0x38U)                                             /*!< INTC0_ICR.IL Mask                       */
#define INTC_ICR_IL_SHIFT                        (3U)                                                /*!< INTC0_ICR.IL Position                   */
#define INTC_ICR_IL(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x38UL)            /*!< INTC0_ICR.IL Field                      */
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
/* ================           PAD (file:MCF52259_PAD)              ================ */
/* ================================================================================ */

/**
 * @brief Pin Configuration
 */
/**
* @addtogroup PAD_structs_GROUP PAD struct
* @brief Struct for PAD
* @{
*/
typedef struct PAD_Type {
   __IO uint32_t  PSRR0;                        /**< 0000: Pin Slew Rate Register 0                                     */
   __IO uint32_t  PDSR0;                        /**< 0004: Pin Drive Strength Register 0                                */
   __IO uint32_t  PSRR1;                        /**< 0008: Pin Slew Rate Register 1                                     */
        uint8_t   RESERVED_0[2];               
   __IO uint16_t  PSRR2;                        /**< 000E: Pin Slew Rate Register 2                                     */
   __IO uint32_t  PDSR1;                        /**< 0010: Pin Drive Strength Register 1                                */
        uint8_t   RESERVED_1[2];               
   __IO uint16_t  PDSR2;                        /**< 0016: Pin Drive Strength Register 2                                */
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
/* ------- PSRR0 Bit Fields                         ------ */
#define PAD_PSRR0_PSRR0_MASK                     (0x1U)                                              /*!< PAD_PSRR0.PSRR0 Mask                    */
#define PAD_PSRR0_PSRR0_SHIFT                    (0U)                                                /*!< PAD_PSRR0.PSRR0 Position                */
#define PAD_PSRR0_PSRR0(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PAD_PSRR0.PSRR0 Field                   */
#define PAD_PSRR0_PSRR1_MASK                     (0x2U)                                              /*!< PAD_PSRR0.PSRR1 Mask                    */
#define PAD_PSRR0_PSRR1_SHIFT                    (1U)                                                /*!< PAD_PSRR0.PSRR1 Position                */
#define PAD_PSRR0_PSRR1(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PAD_PSRR0.PSRR1 Field                   */
#define PAD_PSRR0_PSRR2_MASK                     (0x4U)                                              /*!< PAD_PSRR0.PSRR2 Mask                    */
#define PAD_PSRR0_PSRR2_SHIFT                    (2U)                                                /*!< PAD_PSRR0.PSRR2 Position                */
#define PAD_PSRR0_PSRR2(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< PAD_PSRR0.PSRR2 Field                   */
#define PAD_PSRR0_PSRR3_MASK                     (0x8U)                                              /*!< PAD_PSRR0.PSRR3 Mask                    */
#define PAD_PSRR0_PSRR3_SHIFT                    (3U)                                                /*!< PAD_PSRR0.PSRR3 Position                */
#define PAD_PSRR0_PSRR3(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< PAD_PSRR0.PSRR3 Field                   */
#define PAD_PSRR0_PSRR4_MASK                     (0x10U)                                             /*!< PAD_PSRR0.PSRR4 Mask                    */
#define PAD_PSRR0_PSRR4_SHIFT                    (4U)                                                /*!< PAD_PSRR0.PSRR4 Position                */
#define PAD_PSRR0_PSRR4(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< PAD_PSRR0.PSRR4 Field                   */
#define PAD_PSRR0_PSRR5_MASK                     (0x20U)                                             /*!< PAD_PSRR0.PSRR5 Mask                    */
#define PAD_PSRR0_PSRR5_SHIFT                    (5U)                                                /*!< PAD_PSRR0.PSRR5 Position                */
#define PAD_PSRR0_PSRR5(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< PAD_PSRR0.PSRR5 Field                   */
#define PAD_PSRR0_PSRR6_MASK                     (0x40U)                                             /*!< PAD_PSRR0.PSRR6 Mask                    */
#define PAD_PSRR0_PSRR6_SHIFT                    (6U)                                                /*!< PAD_PSRR0.PSRR6 Position                */
#define PAD_PSRR0_PSRR6(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< PAD_PSRR0.PSRR6 Field                   */
#define PAD_PSRR0_PSRR7_MASK                     (0x80U)                                             /*!< PAD_PSRR0.PSRR7 Mask                    */
#define PAD_PSRR0_PSRR7_SHIFT                    (7U)                                                /*!< PAD_PSRR0.PSRR7 Position                */
#define PAD_PSRR0_PSRR7(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< PAD_PSRR0.PSRR7 Field                   */
#define PAD_PSRR0_PSRR8_MASK                     (0x100U)                                            /*!< PAD_PSRR0.PSRR8 Mask                    */
#define PAD_PSRR0_PSRR8_SHIFT                    (8U)                                                /*!< PAD_PSRR0.PSRR8 Position                */
#define PAD_PSRR0_PSRR8(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< PAD_PSRR0.PSRR8 Field                   */
#define PAD_PSRR0_PSRR9_MASK                     (0x200U)                                            /*!< PAD_PSRR0.PSRR9 Mask                    */
#define PAD_PSRR0_PSRR9_SHIFT                    (9U)                                                /*!< PAD_PSRR0.PSRR9 Position                */
#define PAD_PSRR0_PSRR9(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< PAD_PSRR0.PSRR9 Field                   */
#define PAD_PSRR0_PSRR10_MASK                    (0x400U)                                            /*!< PAD_PSRR0.PSRR10 Mask                   */
#define PAD_PSRR0_PSRR10_SHIFT                   (10U)                                               /*!< PAD_PSRR0.PSRR10 Position               */
#define PAD_PSRR0_PSRR10(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< PAD_PSRR0.PSRR10 Field                  */
#define PAD_PSRR0_PSRR11_MASK                    (0x800U)                                            /*!< PAD_PSRR0.PSRR11 Mask                   */
#define PAD_PSRR0_PSRR11_SHIFT                   (11U)                                               /*!< PAD_PSRR0.PSRR11 Position               */
#define PAD_PSRR0_PSRR11(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< PAD_PSRR0.PSRR11 Field                  */
#define PAD_PSRR0_PSRR12_MASK                    (0x1000U)                                           /*!< PAD_PSRR0.PSRR12 Mask                   */
#define PAD_PSRR0_PSRR12_SHIFT                   (12U)                                               /*!< PAD_PSRR0.PSRR12 Position               */
#define PAD_PSRR0_PSRR12(x)                      (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< PAD_PSRR0.PSRR12 Field                  */
#define PAD_PSRR0_PSRR13_MASK                    (0x2000U)                                           /*!< PAD_PSRR0.PSRR13 Mask                   */
#define PAD_PSRR0_PSRR13_SHIFT                   (13U)                                               /*!< PAD_PSRR0.PSRR13 Position               */
#define PAD_PSRR0_PSRR13(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< PAD_PSRR0.PSRR13 Field                  */
#define PAD_PSRR0_PSRR14_MASK                    (0x4000U)                                           /*!< PAD_PSRR0.PSRR14 Mask                   */
#define PAD_PSRR0_PSRR14_SHIFT                   (14U)                                               /*!< PAD_PSRR0.PSRR14 Position               */
#define PAD_PSRR0_PSRR14(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< PAD_PSRR0.PSRR14 Field                  */
#define PAD_PSRR0_PSRR15_MASK                    (0x8000U)                                           /*!< PAD_PSRR0.PSRR15 Mask                   */
#define PAD_PSRR0_PSRR15_SHIFT                   (15U)                                               /*!< PAD_PSRR0.PSRR15 Position               */
#define PAD_PSRR0_PSRR15(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< PAD_PSRR0.PSRR15 Field                  */
#define PAD_PSRR0_PSRR16_MASK                    (0x10000U)                                          /*!< PAD_PSRR0.PSRR16 Mask                   */
#define PAD_PSRR0_PSRR16_SHIFT                   (16U)                                               /*!< PAD_PSRR0.PSRR16 Position               */
#define PAD_PSRR0_PSRR16(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< PAD_PSRR0.PSRR16 Field                  */
#define PAD_PSRR0_PSRR17_MASK                    (0x20000U)                                          /*!< PAD_PSRR0.PSRR17 Mask                   */
#define PAD_PSRR0_PSRR17_SHIFT                   (17U)                                               /*!< PAD_PSRR0.PSRR17 Position               */
#define PAD_PSRR0_PSRR17(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< PAD_PSRR0.PSRR17 Field                  */
#define PAD_PSRR0_PSRR18_MASK                    (0x40000U)                                          /*!< PAD_PSRR0.PSRR18 Mask                   */
#define PAD_PSRR0_PSRR18_SHIFT                   (18U)                                               /*!< PAD_PSRR0.PSRR18 Position               */
#define PAD_PSRR0_PSRR18(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< PAD_PSRR0.PSRR18 Field                  */
#define PAD_PSRR0_PSRR19_MASK                    (0x80000U)                                          /*!< PAD_PSRR0.PSRR19 Mask                   */
#define PAD_PSRR0_PSRR19_SHIFT                   (19U)                                               /*!< PAD_PSRR0.PSRR19 Position               */
#define PAD_PSRR0_PSRR19(x)                      (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< PAD_PSRR0.PSRR19 Field                  */
#define PAD_PSRR0_PSRR20_MASK                    (0x100000U)                                         /*!< PAD_PSRR0.PSRR20 Mask                   */
#define PAD_PSRR0_PSRR20_SHIFT                   (20U)                                               /*!< PAD_PSRR0.PSRR20 Position               */
#define PAD_PSRR0_PSRR20(x)                      (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< PAD_PSRR0.PSRR20 Field                  */
#define PAD_PSRR0_PSRR21_MASK                    (0x200000U)                                         /*!< PAD_PSRR0.PSRR21 Mask                   */
#define PAD_PSRR0_PSRR21_SHIFT                   (21U)                                               /*!< PAD_PSRR0.PSRR21 Position               */
#define PAD_PSRR0_PSRR21(x)                      (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< PAD_PSRR0.PSRR21 Field                  */
#define PAD_PSRR0_PSRR22_MASK                    (0x400000U)                                         /*!< PAD_PSRR0.PSRR22 Mask                   */
#define PAD_PSRR0_PSRR22_SHIFT                   (22U)                                               /*!< PAD_PSRR0.PSRR22 Position               */
#define PAD_PSRR0_PSRR22(x)                      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< PAD_PSRR0.PSRR22 Field                  */
#define PAD_PSRR0_PSRR23_MASK                    (0x800000U)                                         /*!< PAD_PSRR0.PSRR23 Mask                   */
#define PAD_PSRR0_PSRR23_SHIFT                   (23U)                                               /*!< PAD_PSRR0.PSRR23 Position               */
#define PAD_PSRR0_PSRR23(x)                      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< PAD_PSRR0.PSRR23 Field                  */
#define PAD_PSRR0_PSRR24_MASK                    (0x1000000U)                                        /*!< PAD_PSRR0.PSRR24 Mask                   */
#define PAD_PSRR0_PSRR24_SHIFT                   (24U)                                               /*!< PAD_PSRR0.PSRR24 Position               */
#define PAD_PSRR0_PSRR24(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< PAD_PSRR0.PSRR24 Field                  */
#define PAD_PSRR0_PSRR25_MASK                    (0x2000000U)                                        /*!< PAD_PSRR0.PSRR25 Mask                   */
#define PAD_PSRR0_PSRR25_SHIFT                   (25U)                                               /*!< PAD_PSRR0.PSRR25 Position               */
#define PAD_PSRR0_PSRR25(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< PAD_PSRR0.PSRR25 Field                  */
#define PAD_PSRR0_PSRR26_MASK                    (0x4000000U)                                        /*!< PAD_PSRR0.PSRR26 Mask                   */
#define PAD_PSRR0_PSRR26_SHIFT                   (26U)                                               /*!< PAD_PSRR0.PSRR26 Position               */
#define PAD_PSRR0_PSRR26(x)                      (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< PAD_PSRR0.PSRR26 Field                  */
#define PAD_PSRR0_PSRR27_MASK                    (0x8000000U)                                        /*!< PAD_PSRR0.PSRR27 Mask                   */
#define PAD_PSRR0_PSRR27_SHIFT                   (27U)                                               /*!< PAD_PSRR0.PSRR27 Position               */
#define PAD_PSRR0_PSRR27(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< PAD_PSRR0.PSRR27 Field                  */
#define PAD_PSRR0_PSRR28_MASK                    (0x10000000U)                                       /*!< PAD_PSRR0.PSRR28 Mask                   */
#define PAD_PSRR0_PSRR28_SHIFT                   (28U)                                               /*!< PAD_PSRR0.PSRR28 Position               */
#define PAD_PSRR0_PSRR28(x)                      (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< PAD_PSRR0.PSRR28 Field                  */
#define PAD_PSRR0_PSRR29_MASK                    (0x20000000U)                                       /*!< PAD_PSRR0.PSRR29 Mask                   */
#define PAD_PSRR0_PSRR29_SHIFT                   (29U)                                               /*!< PAD_PSRR0.PSRR29 Position               */
#define PAD_PSRR0_PSRR29(x)                      (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< PAD_PSRR0.PSRR29 Field                  */
#define PAD_PSRR0_PSRR30_MASK                    (0x40000000U)                                       /*!< PAD_PSRR0.PSRR30 Mask                   */
#define PAD_PSRR0_PSRR30_SHIFT                   (30U)                                               /*!< PAD_PSRR0.PSRR30 Position               */
#define PAD_PSRR0_PSRR30(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< PAD_PSRR0.PSRR30 Field                  */
#define PAD_PSRR0_PSRR31_MASK                    (0x80000000U)                                       /*!< PAD_PSRR0.PSRR31 Mask                   */
#define PAD_PSRR0_PSRR31_SHIFT                   (31U)                                               /*!< PAD_PSRR0.PSRR31 Position               */
#define PAD_PSRR0_PSRR31(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< PAD_PSRR0.PSRR31 Field                  */
/* ------- PDSR0 Bit Fields                         ------ */
#define PAD_PDSR0_PDSR0_MASK                     (0x1U)                                              /*!< PAD_PDSR0.PDSR0 Mask                    */
#define PAD_PDSR0_PDSR0_SHIFT                    (0U)                                                /*!< PAD_PDSR0.PDSR0 Position                */
#define PAD_PDSR0_PDSR0(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PAD_PDSR0.PDSR0 Field                   */
#define PAD_PDSR0_PDSR1_MASK                     (0x2U)                                              /*!< PAD_PDSR0.PDSR1 Mask                    */
#define PAD_PDSR0_PDSR1_SHIFT                    (1U)                                                /*!< PAD_PDSR0.PDSR1 Position                */
#define PAD_PDSR0_PDSR1(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PAD_PDSR0.PDSR1 Field                   */
#define PAD_PDSR0_PDSR2_MASK                     (0x4U)                                              /*!< PAD_PDSR0.PDSR2 Mask                    */
#define PAD_PDSR0_PDSR2_SHIFT                    (2U)                                                /*!< PAD_PDSR0.PDSR2 Position                */
#define PAD_PDSR0_PDSR2(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< PAD_PDSR0.PDSR2 Field                   */
#define PAD_PDSR0_PDSR3_MASK                     (0x8U)                                              /*!< PAD_PDSR0.PDSR3 Mask                    */
#define PAD_PDSR0_PDSR3_SHIFT                    (3U)                                                /*!< PAD_PDSR0.PDSR3 Position                */
#define PAD_PDSR0_PDSR3(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< PAD_PDSR0.PDSR3 Field                   */
#define PAD_PDSR0_PDSR4_MASK                     (0x10U)                                             /*!< PAD_PDSR0.PDSR4 Mask                    */
#define PAD_PDSR0_PDSR4_SHIFT                    (4U)                                                /*!< PAD_PDSR0.PDSR4 Position                */
#define PAD_PDSR0_PDSR4(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< PAD_PDSR0.PDSR4 Field                   */
#define PAD_PDSR0_PDSR5_MASK                     (0x20U)                                             /*!< PAD_PDSR0.PDSR5 Mask                    */
#define PAD_PDSR0_PDSR5_SHIFT                    (5U)                                                /*!< PAD_PDSR0.PDSR5 Position                */
#define PAD_PDSR0_PDSR5(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< PAD_PDSR0.PDSR5 Field                   */
#define PAD_PDSR0_PDSR6_MASK                     (0x40U)                                             /*!< PAD_PDSR0.PDSR6 Mask                    */
#define PAD_PDSR0_PDSR6_SHIFT                    (6U)                                                /*!< PAD_PDSR0.PDSR6 Position                */
#define PAD_PDSR0_PDSR6(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< PAD_PDSR0.PDSR6 Field                   */
#define PAD_PDSR0_PDSR7_MASK                     (0x80U)                                             /*!< PAD_PDSR0.PDSR7 Mask                    */
#define PAD_PDSR0_PDSR7_SHIFT                    (7U)                                                /*!< PAD_PDSR0.PDSR7 Position                */
#define PAD_PDSR0_PDSR7(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< PAD_PDSR0.PDSR7 Field                   */
#define PAD_PDSR0_PDSR8_MASK                     (0x100U)                                            /*!< PAD_PDSR0.PDSR8 Mask                    */
#define PAD_PDSR0_PDSR8_SHIFT                    (8U)                                                /*!< PAD_PDSR0.PDSR8 Position                */
#define PAD_PDSR0_PDSR8(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< PAD_PDSR0.PDSR8 Field                   */
#define PAD_PDSR0_PDSR9_MASK                     (0x200U)                                            /*!< PAD_PDSR0.PDSR9 Mask                    */
#define PAD_PDSR0_PDSR9_SHIFT                    (9U)                                                /*!< PAD_PDSR0.PDSR9 Position                */
#define PAD_PDSR0_PDSR9(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< PAD_PDSR0.PDSR9 Field                   */
#define PAD_PDSR0_PDSR10_MASK                    (0x400U)                                            /*!< PAD_PDSR0.PDSR10 Mask                   */
#define PAD_PDSR0_PDSR10_SHIFT                   (10U)                                               /*!< PAD_PDSR0.PDSR10 Position               */
#define PAD_PDSR0_PDSR10(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< PAD_PDSR0.PDSR10 Field                  */
#define PAD_PDSR0_PDSR11_MASK                    (0x800U)                                            /*!< PAD_PDSR0.PDSR11 Mask                   */
#define PAD_PDSR0_PDSR11_SHIFT                   (11U)                                               /*!< PAD_PDSR0.PDSR11 Position               */
#define PAD_PDSR0_PDSR11(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< PAD_PDSR0.PDSR11 Field                  */
#define PAD_PDSR0_PDSR12_MASK                    (0x1000U)                                           /*!< PAD_PDSR0.PDSR12 Mask                   */
#define PAD_PDSR0_PDSR12_SHIFT                   (12U)                                               /*!< PAD_PDSR0.PDSR12 Position               */
#define PAD_PDSR0_PDSR12(x)                      (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< PAD_PDSR0.PDSR12 Field                  */
#define PAD_PDSR0_PDSR13_MASK                    (0x2000U)                                           /*!< PAD_PDSR0.PDSR13 Mask                   */
#define PAD_PDSR0_PDSR13_SHIFT                   (13U)                                               /*!< PAD_PDSR0.PDSR13 Position               */
#define PAD_PDSR0_PDSR13(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< PAD_PDSR0.PDSR13 Field                  */
#define PAD_PDSR0_PDSR14_MASK                    (0x4000U)                                           /*!< PAD_PDSR0.PDSR14 Mask                   */
#define PAD_PDSR0_PDSR14_SHIFT                   (14U)                                               /*!< PAD_PDSR0.PDSR14 Position               */
#define PAD_PDSR0_PDSR14(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< PAD_PDSR0.PDSR14 Field                  */
#define PAD_PDSR0_PDSR15_MASK                    (0x8000U)                                           /*!< PAD_PDSR0.PDSR15 Mask                   */
#define PAD_PDSR0_PDSR15_SHIFT                   (15U)                                               /*!< PAD_PDSR0.PDSR15 Position               */
#define PAD_PDSR0_PDSR15(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< PAD_PDSR0.PDSR15 Field                  */
#define PAD_PDSR0_PDSR16_MASK                    (0x10000U)                                          /*!< PAD_PDSR0.PDSR16 Mask                   */
#define PAD_PDSR0_PDSR16_SHIFT                   (16U)                                               /*!< PAD_PDSR0.PDSR16 Position               */
#define PAD_PDSR0_PDSR16(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< PAD_PDSR0.PDSR16 Field                  */
#define PAD_PDSR0_PDSR17_MASK                    (0x20000U)                                          /*!< PAD_PDSR0.PDSR17 Mask                   */
#define PAD_PDSR0_PDSR17_SHIFT                   (17U)                                               /*!< PAD_PDSR0.PDSR17 Position               */
#define PAD_PDSR0_PDSR17(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< PAD_PDSR0.PDSR17 Field                  */
#define PAD_PDSR0_PDSR18_MASK                    (0x40000U)                                          /*!< PAD_PDSR0.PDSR18 Mask                   */
#define PAD_PDSR0_PDSR18_SHIFT                   (18U)                                               /*!< PAD_PDSR0.PDSR18 Position               */
#define PAD_PDSR0_PDSR18(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< PAD_PDSR0.PDSR18 Field                  */
#define PAD_PDSR0_PDSR19_MASK                    (0x80000U)                                          /*!< PAD_PDSR0.PDSR19 Mask                   */
#define PAD_PDSR0_PDSR19_SHIFT                   (19U)                                               /*!< PAD_PDSR0.PDSR19 Position               */
#define PAD_PDSR0_PDSR19(x)                      (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< PAD_PDSR0.PDSR19 Field                  */
#define PAD_PDSR0_PDSR20_MASK                    (0x100000U)                                         /*!< PAD_PDSR0.PDSR20 Mask                   */
#define PAD_PDSR0_PDSR20_SHIFT                   (20U)                                               /*!< PAD_PDSR0.PDSR20 Position               */
#define PAD_PDSR0_PDSR20(x)                      (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< PAD_PDSR0.PDSR20 Field                  */
#define PAD_PDSR0_PDSR21_MASK                    (0x200000U)                                         /*!< PAD_PDSR0.PDSR21 Mask                   */
#define PAD_PDSR0_PDSR21_SHIFT                   (21U)                                               /*!< PAD_PDSR0.PDSR21 Position               */
#define PAD_PDSR0_PDSR21(x)                      (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< PAD_PDSR0.PDSR21 Field                  */
#define PAD_PDSR0_PDSR22_MASK                    (0x400000U)                                         /*!< PAD_PDSR0.PDSR22 Mask                   */
#define PAD_PDSR0_PDSR22_SHIFT                   (22U)                                               /*!< PAD_PDSR0.PDSR22 Position               */
#define PAD_PDSR0_PDSR22(x)                      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< PAD_PDSR0.PDSR22 Field                  */
#define PAD_PDSR0_PDSR23_MASK                    (0x800000U)                                         /*!< PAD_PDSR0.PDSR23 Mask                   */
#define PAD_PDSR0_PDSR23_SHIFT                   (23U)                                               /*!< PAD_PDSR0.PDSR23 Position               */
#define PAD_PDSR0_PDSR23(x)                      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< PAD_PDSR0.PDSR23 Field                  */
#define PAD_PDSR0_PDSR24_MASK                    (0x1000000U)                                        /*!< PAD_PDSR0.PDSR24 Mask                   */
#define PAD_PDSR0_PDSR24_SHIFT                   (24U)                                               /*!< PAD_PDSR0.PDSR24 Position               */
#define PAD_PDSR0_PDSR24(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< PAD_PDSR0.PDSR24 Field                  */
#define PAD_PDSR0_PDSR25_MASK                    (0x2000000U)                                        /*!< PAD_PDSR0.PDSR25 Mask                   */
#define PAD_PDSR0_PDSR25_SHIFT                   (25U)                                               /*!< PAD_PDSR0.PDSR25 Position               */
#define PAD_PDSR0_PDSR25(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< PAD_PDSR0.PDSR25 Field                  */
#define PAD_PDSR0_PDSR26_MASK                    (0x4000000U)                                        /*!< PAD_PDSR0.PDSR26 Mask                   */
#define PAD_PDSR0_PDSR26_SHIFT                   (26U)                                               /*!< PAD_PDSR0.PDSR26 Position               */
#define PAD_PDSR0_PDSR26(x)                      (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< PAD_PDSR0.PDSR26 Field                  */
#define PAD_PDSR0_PDSR27_MASK                    (0x8000000U)                                        /*!< PAD_PDSR0.PDSR27 Mask                   */
#define PAD_PDSR0_PDSR27_SHIFT                   (27U)                                               /*!< PAD_PDSR0.PDSR27 Position               */
#define PAD_PDSR0_PDSR27(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< PAD_PDSR0.PDSR27 Field                  */
#define PAD_PDSR0_PDSR28_MASK                    (0x10000000U)                                       /*!< PAD_PDSR0.PDSR28 Mask                   */
#define PAD_PDSR0_PDSR28_SHIFT                   (28U)                                               /*!< PAD_PDSR0.PDSR28 Position               */
#define PAD_PDSR0_PDSR28(x)                      (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< PAD_PDSR0.PDSR28 Field                  */
#define PAD_PDSR0_PDSR29_MASK                    (0x20000000U)                                       /*!< PAD_PDSR0.PDSR29 Mask                   */
#define PAD_PDSR0_PDSR29_SHIFT                   (29U)                                               /*!< PAD_PDSR0.PDSR29 Position               */
#define PAD_PDSR0_PDSR29(x)                      (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< PAD_PDSR0.PDSR29 Field                  */
#define PAD_PDSR0_PDSR30_MASK                    (0x40000000U)                                       /*!< PAD_PDSR0.PDSR30 Mask                   */
#define PAD_PDSR0_PDSR30_SHIFT                   (30U)                                               /*!< PAD_PDSR0.PDSR30 Position               */
#define PAD_PDSR0_PDSR30(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< PAD_PDSR0.PDSR30 Field                  */
#define PAD_PDSR0_PDSR31_MASK                    (0x80000000U)                                       /*!< PAD_PDSR0.PDSR31 Mask                   */
#define PAD_PDSR0_PDSR31_SHIFT                   (31U)                                               /*!< PAD_PDSR0.PDSR31 Position               */
#define PAD_PDSR0_PDSR31(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< PAD_PDSR0.PDSR31 Field                  */
/* ------- PSRR1 Bit Fields                         ------ */
#define PAD_PSRR1_PSRR0_MASK                     (0x1U)                                              /*!< PAD_PSRR1.PSRR0 Mask                    */
#define PAD_PSRR1_PSRR0_SHIFT                    (0U)                                                /*!< PAD_PSRR1.PSRR0 Position                */
#define PAD_PSRR1_PSRR0(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PAD_PSRR1.PSRR0 Field                   */
#define PAD_PSRR1_PSRR1_MASK                     (0x2U)                                              /*!< PAD_PSRR1.PSRR1 Mask                    */
#define PAD_PSRR1_PSRR1_SHIFT                    (1U)                                                /*!< PAD_PSRR1.PSRR1 Position                */
#define PAD_PSRR1_PSRR1(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PAD_PSRR1.PSRR1 Field                   */
#define PAD_PSRR1_PSRR2_MASK                     (0x4U)                                              /*!< PAD_PSRR1.PSRR2 Mask                    */
#define PAD_PSRR1_PSRR2_SHIFT                    (2U)                                                /*!< PAD_PSRR1.PSRR2 Position                */
#define PAD_PSRR1_PSRR2(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< PAD_PSRR1.PSRR2 Field                   */
#define PAD_PSRR1_PSRR3_MASK                     (0x8U)                                              /*!< PAD_PSRR1.PSRR3 Mask                    */
#define PAD_PSRR1_PSRR3_SHIFT                    (3U)                                                /*!< PAD_PSRR1.PSRR3 Position                */
#define PAD_PSRR1_PSRR3(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< PAD_PSRR1.PSRR3 Field                   */
#define PAD_PSRR1_PSRR4_MASK                     (0x10U)                                             /*!< PAD_PSRR1.PSRR4 Mask                    */
#define PAD_PSRR1_PSRR4_SHIFT                    (4U)                                                /*!< PAD_PSRR1.PSRR4 Position                */
#define PAD_PSRR1_PSRR4(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< PAD_PSRR1.PSRR4 Field                   */
#define PAD_PSRR1_PSRR5_MASK                     (0x20U)                                             /*!< PAD_PSRR1.PSRR5 Mask                    */
#define PAD_PSRR1_PSRR5_SHIFT                    (5U)                                                /*!< PAD_PSRR1.PSRR5 Position                */
#define PAD_PSRR1_PSRR5(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< PAD_PSRR1.PSRR5 Field                   */
#define PAD_PSRR1_PSRR6_MASK                     (0x40U)                                             /*!< PAD_PSRR1.PSRR6 Mask                    */
#define PAD_PSRR1_PSRR6_SHIFT                    (6U)                                                /*!< PAD_PSRR1.PSRR6 Position                */
#define PAD_PSRR1_PSRR6(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< PAD_PSRR1.PSRR6 Field                   */
#define PAD_PSRR1_PSRR7_MASK                     (0x80U)                                             /*!< PAD_PSRR1.PSRR7 Mask                    */
#define PAD_PSRR1_PSRR7_SHIFT                    (7U)                                                /*!< PAD_PSRR1.PSRR7 Position                */
#define PAD_PSRR1_PSRR7(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< PAD_PSRR1.PSRR7 Field                   */
#define PAD_PSRR1_PSRR8_MASK                     (0x100U)                                            /*!< PAD_PSRR1.PSRR8 Mask                    */
#define PAD_PSRR1_PSRR8_SHIFT                    (8U)                                                /*!< PAD_PSRR1.PSRR8 Position                */
#define PAD_PSRR1_PSRR8(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< PAD_PSRR1.PSRR8 Field                   */
#define PAD_PSRR1_PSRR9_MASK                     (0x200U)                                            /*!< PAD_PSRR1.PSRR9 Mask                    */
#define PAD_PSRR1_PSRR9_SHIFT                    (9U)                                                /*!< PAD_PSRR1.PSRR9 Position                */
#define PAD_PSRR1_PSRR9(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< PAD_PSRR1.PSRR9 Field                   */
#define PAD_PSRR1_PSRR10_MASK                    (0x400U)                                            /*!< PAD_PSRR1.PSRR10 Mask                   */
#define PAD_PSRR1_PSRR10_SHIFT                   (10U)                                               /*!< PAD_PSRR1.PSRR10 Position               */
#define PAD_PSRR1_PSRR10(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< PAD_PSRR1.PSRR10 Field                  */
#define PAD_PSRR1_PSRR11_MASK                    (0x800U)                                            /*!< PAD_PSRR1.PSRR11 Mask                   */
#define PAD_PSRR1_PSRR11_SHIFT                   (11U)                                               /*!< PAD_PSRR1.PSRR11 Position               */
#define PAD_PSRR1_PSRR11(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< PAD_PSRR1.PSRR11 Field                  */
#define PAD_PSRR1_PSRR12_MASK                    (0x1000U)                                           /*!< PAD_PSRR1.PSRR12 Mask                   */
#define PAD_PSRR1_PSRR12_SHIFT                   (12U)                                               /*!< PAD_PSRR1.PSRR12 Position               */
#define PAD_PSRR1_PSRR12(x)                      (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< PAD_PSRR1.PSRR12 Field                  */
#define PAD_PSRR1_PSRR13_MASK                    (0x2000U)                                           /*!< PAD_PSRR1.PSRR13 Mask                   */
#define PAD_PSRR1_PSRR13_SHIFT                   (13U)                                               /*!< PAD_PSRR1.PSRR13 Position               */
#define PAD_PSRR1_PSRR13(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< PAD_PSRR1.PSRR13 Field                  */
#define PAD_PSRR1_PSRR14_MASK                    (0x4000U)                                           /*!< PAD_PSRR1.PSRR14 Mask                   */
#define PAD_PSRR1_PSRR14_SHIFT                   (14U)                                               /*!< PAD_PSRR1.PSRR14 Position               */
#define PAD_PSRR1_PSRR14(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< PAD_PSRR1.PSRR14 Field                  */
#define PAD_PSRR1_PSRR15_MASK                    (0x8000U)                                           /*!< PAD_PSRR1.PSRR15 Mask                   */
#define PAD_PSRR1_PSRR15_SHIFT                   (15U)                                               /*!< PAD_PSRR1.PSRR15 Position               */
#define PAD_PSRR1_PSRR15(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< PAD_PSRR1.PSRR15 Field                  */
#define PAD_PSRR1_PSRR16_MASK                    (0x10000U)                                          /*!< PAD_PSRR1.PSRR16 Mask                   */
#define PAD_PSRR1_PSRR16_SHIFT                   (16U)                                               /*!< PAD_PSRR1.PSRR16 Position               */
#define PAD_PSRR1_PSRR16(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< PAD_PSRR1.PSRR16 Field                  */
#define PAD_PSRR1_PSRR17_MASK                    (0x20000U)                                          /*!< PAD_PSRR1.PSRR17 Mask                   */
#define PAD_PSRR1_PSRR17_SHIFT                   (17U)                                               /*!< PAD_PSRR1.PSRR17 Position               */
#define PAD_PSRR1_PSRR17(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< PAD_PSRR1.PSRR17 Field                  */
#define PAD_PSRR1_PSRR18_MASK                    (0x40000U)                                          /*!< PAD_PSRR1.PSRR18 Mask                   */
#define PAD_PSRR1_PSRR18_SHIFT                   (18U)                                               /*!< PAD_PSRR1.PSRR18 Position               */
#define PAD_PSRR1_PSRR18(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< PAD_PSRR1.PSRR18 Field                  */
#define PAD_PSRR1_PSRR19_MASK                    (0x80000U)                                          /*!< PAD_PSRR1.PSRR19 Mask                   */
#define PAD_PSRR1_PSRR19_SHIFT                   (19U)                                               /*!< PAD_PSRR1.PSRR19 Position               */
#define PAD_PSRR1_PSRR19(x)                      (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< PAD_PSRR1.PSRR19 Field                  */
#define PAD_PSRR1_PSRR20_MASK                    (0x100000U)                                         /*!< PAD_PSRR1.PSRR20 Mask                   */
#define PAD_PSRR1_PSRR20_SHIFT                   (20U)                                               /*!< PAD_PSRR1.PSRR20 Position               */
#define PAD_PSRR1_PSRR20(x)                      (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< PAD_PSRR1.PSRR20 Field                  */
#define PAD_PSRR1_PSRR21_MASK                    (0x200000U)                                         /*!< PAD_PSRR1.PSRR21 Mask                   */
#define PAD_PSRR1_PSRR21_SHIFT                   (21U)                                               /*!< PAD_PSRR1.PSRR21 Position               */
#define PAD_PSRR1_PSRR21(x)                      (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< PAD_PSRR1.PSRR21 Field                  */
#define PAD_PSRR1_PSRR22_MASK                    (0x400000U)                                         /*!< PAD_PSRR1.PSRR22 Mask                   */
#define PAD_PSRR1_PSRR22_SHIFT                   (22U)                                               /*!< PAD_PSRR1.PSRR22 Position               */
#define PAD_PSRR1_PSRR22(x)                      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< PAD_PSRR1.PSRR22 Field                  */
#define PAD_PSRR1_PSRR23_MASK                    (0x800000U)                                         /*!< PAD_PSRR1.PSRR23 Mask                   */
#define PAD_PSRR1_PSRR23_SHIFT                   (23U)                                               /*!< PAD_PSRR1.PSRR23 Position               */
#define PAD_PSRR1_PSRR23(x)                      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< PAD_PSRR1.PSRR23 Field                  */
#define PAD_PSRR1_PSRR24_MASK                    (0x1000000U)                                        /*!< PAD_PSRR1.PSRR24 Mask                   */
#define PAD_PSRR1_PSRR24_SHIFT                   (24U)                                               /*!< PAD_PSRR1.PSRR24 Position               */
#define PAD_PSRR1_PSRR24(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< PAD_PSRR1.PSRR24 Field                  */
#define PAD_PSRR1_PSRR25_MASK                    (0x2000000U)                                        /*!< PAD_PSRR1.PSRR25 Mask                   */
#define PAD_PSRR1_PSRR25_SHIFT                   (25U)                                               /*!< PAD_PSRR1.PSRR25 Position               */
#define PAD_PSRR1_PSRR25(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< PAD_PSRR1.PSRR25 Field                  */
#define PAD_PSRR1_PSRR26_MASK                    (0x4000000U)                                        /*!< PAD_PSRR1.PSRR26 Mask                   */
#define PAD_PSRR1_PSRR26_SHIFT                   (26U)                                               /*!< PAD_PSRR1.PSRR26 Position               */
#define PAD_PSRR1_PSRR26(x)                      (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< PAD_PSRR1.PSRR26 Field                  */
#define PAD_PSRR1_PSRR27_MASK                    (0x8000000U)                                        /*!< PAD_PSRR1.PSRR27 Mask                   */
#define PAD_PSRR1_PSRR27_SHIFT                   (27U)                                               /*!< PAD_PSRR1.PSRR27 Position               */
#define PAD_PSRR1_PSRR27(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< PAD_PSRR1.PSRR27 Field                  */
#define PAD_PSRR1_PSRR28_MASK                    (0x10000000U)                                       /*!< PAD_PSRR1.PSRR28 Mask                   */
#define PAD_PSRR1_PSRR28_SHIFT                   (28U)                                               /*!< PAD_PSRR1.PSRR28 Position               */
#define PAD_PSRR1_PSRR28(x)                      (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< PAD_PSRR1.PSRR28 Field                  */
#define PAD_PSRR1_PSRR29_MASK                    (0x20000000U)                                       /*!< PAD_PSRR1.PSRR29 Mask                   */
#define PAD_PSRR1_PSRR29_SHIFT                   (29U)                                               /*!< PAD_PSRR1.PSRR29 Position               */
#define PAD_PSRR1_PSRR29(x)                      (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< PAD_PSRR1.PSRR29 Field                  */
#define PAD_PSRR1_PSRR30_MASK                    (0x40000000U)                                       /*!< PAD_PSRR1.PSRR30 Mask                   */
#define PAD_PSRR1_PSRR30_SHIFT                   (30U)                                               /*!< PAD_PSRR1.PSRR30 Position               */
#define PAD_PSRR1_PSRR30(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< PAD_PSRR1.PSRR30 Field                  */
#define PAD_PSRR1_PSRR31_MASK                    (0x80000000U)                                       /*!< PAD_PSRR1.PSRR31 Mask                   */
#define PAD_PSRR1_PSRR31_SHIFT                   (31U)                                               /*!< PAD_PSRR1.PSRR31 Position               */
#define PAD_PSRR1_PSRR31(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< PAD_PSRR1.PSRR31 Field                  */
/* ------- PSRR2 Bit Fields                         ------ */
#define PAD_PSRR2_PSRR0_MASK                     (0x1U)                                              /*!< PAD_PSRR2.PSRR0 Mask                    */
#define PAD_PSRR2_PSRR0_SHIFT                    (0U)                                                /*!< PAD_PSRR2.PSRR0 Position                */
#define PAD_PSRR2_PSRR0(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< PAD_PSRR2.PSRR0 Field                   */
#define PAD_PSRR2_PSRR1_MASK                     (0x2U)                                              /*!< PAD_PSRR2.PSRR1 Mask                    */
#define PAD_PSRR2_PSRR1_SHIFT                    (1U)                                                /*!< PAD_PSRR2.PSRR1 Position                */
#define PAD_PSRR2_PSRR1(x)                       (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< PAD_PSRR2.PSRR1 Field                   */
#define PAD_PSRR2_PSRR2_MASK                     (0x4U)                                              /*!< PAD_PSRR2.PSRR2 Mask                    */
#define PAD_PSRR2_PSRR2_SHIFT                    (2U)                                                /*!< PAD_PSRR2.PSRR2 Position                */
#define PAD_PSRR2_PSRR2(x)                       (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< PAD_PSRR2.PSRR2 Field                   */
#define PAD_PSRR2_PSRR3_MASK                     (0x8U)                                              /*!< PAD_PSRR2.PSRR3 Mask                    */
#define PAD_PSRR2_PSRR3_SHIFT                    (3U)                                                /*!< PAD_PSRR2.PSRR3 Position                */
#define PAD_PSRR2_PSRR3(x)                       (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< PAD_PSRR2.PSRR3 Field                   */
#define PAD_PSRR2_PSRR4_MASK                     (0x10U)                                             /*!< PAD_PSRR2.PSRR4 Mask                    */
#define PAD_PSRR2_PSRR4_SHIFT                    (4U)                                                /*!< PAD_PSRR2.PSRR4 Position                */
#define PAD_PSRR2_PSRR4(x)                       (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< PAD_PSRR2.PSRR4 Field                   */
#define PAD_PSRR2_PSRR5_MASK                     (0x20U)                                             /*!< PAD_PSRR2.PSRR5 Mask                    */
#define PAD_PSRR2_PSRR5_SHIFT                    (5U)                                                /*!< PAD_PSRR2.PSRR5 Position                */
#define PAD_PSRR2_PSRR5(x)                       (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< PAD_PSRR2.PSRR5 Field                   */
#define PAD_PSRR2_PSRR6_MASK                     (0x40U)                                             /*!< PAD_PSRR2.PSRR6 Mask                    */
#define PAD_PSRR2_PSRR6_SHIFT                    (6U)                                                /*!< PAD_PSRR2.PSRR6 Position                */
#define PAD_PSRR2_PSRR6(x)                       (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< PAD_PSRR2.PSRR6 Field                   */
#define PAD_PSRR2_PSRR7_MASK                     (0x80U)                                             /*!< PAD_PSRR2.PSRR7 Mask                    */
#define PAD_PSRR2_PSRR7_SHIFT                    (7U)                                                /*!< PAD_PSRR2.PSRR7 Position                */
#define PAD_PSRR2_PSRR7(x)                       (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< PAD_PSRR2.PSRR7 Field                   */
#define PAD_PSRR2_PSRR8_MASK                     (0x100U)                                            /*!< PAD_PSRR2.PSRR8 Mask                    */
#define PAD_PSRR2_PSRR8_SHIFT                    (8U)                                                /*!< PAD_PSRR2.PSRR8 Position                */
#define PAD_PSRR2_PSRR8(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< PAD_PSRR2.PSRR8 Field                   */
#define PAD_PSRR2_PSRR9_MASK                     (0x200U)                                            /*!< PAD_PSRR2.PSRR9 Mask                    */
#define PAD_PSRR2_PSRR9_SHIFT                    (9U)                                                /*!< PAD_PSRR2.PSRR9 Position                */
#define PAD_PSRR2_PSRR9(x)                       (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< PAD_PSRR2.PSRR9 Field                   */
#define PAD_PSRR2_PSRR10_MASK                    (0x400U)                                            /*!< PAD_PSRR2.PSRR10 Mask                   */
#define PAD_PSRR2_PSRR10_SHIFT                   (10U)                                               /*!< PAD_PSRR2.PSRR10 Position               */
#define PAD_PSRR2_PSRR10(x)                      (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< PAD_PSRR2.PSRR10 Field                  */
#define PAD_PSRR2_PSRR11_MASK                    (0x800U)                                            /*!< PAD_PSRR2.PSRR11 Mask                   */
#define PAD_PSRR2_PSRR11_SHIFT                   (11U)                                               /*!< PAD_PSRR2.PSRR11 Position               */
#define PAD_PSRR2_PSRR11(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< PAD_PSRR2.PSRR11 Field                  */
#define PAD_PSRR2_PSRR12_MASK                    (0x1000U)                                           /*!< PAD_PSRR2.PSRR12 Mask                   */
#define PAD_PSRR2_PSRR12_SHIFT                   (12U)                                               /*!< PAD_PSRR2.PSRR12 Position               */
#define PAD_PSRR2_PSRR12(x)                      (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< PAD_PSRR2.PSRR12 Field                  */
#define PAD_PSRR2_PSRR13_MASK                    (0x2000U)                                           /*!< PAD_PSRR2.PSRR13 Mask                   */
#define PAD_PSRR2_PSRR13_SHIFT                   (13U)                                               /*!< PAD_PSRR2.PSRR13 Position               */
#define PAD_PSRR2_PSRR13(x)                      (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< PAD_PSRR2.PSRR13 Field                  */
#define PAD_PSRR2_PSRR14_MASK                    (0x4000U)                                           /*!< PAD_PSRR2.PSRR14 Mask                   */
#define PAD_PSRR2_PSRR14_SHIFT                   (14U)                                               /*!< PAD_PSRR2.PSRR14 Position               */
#define PAD_PSRR2_PSRR14(x)                      (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< PAD_PSRR2.PSRR14 Field                  */
#define PAD_PSRR2_PSRR15_MASK                    (0x8000U)                                           /*!< PAD_PSRR2.PSRR15 Mask                   */
#define PAD_PSRR2_PSRR15_SHIFT                   (15U)                                               /*!< PAD_PSRR2.PSRR15 Position               */
#define PAD_PSRR2_PSRR15(x)                      (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< PAD_PSRR2.PSRR15 Field                  */
/* ------- PDSR1 Bit Fields                         ------ */
#define PAD_PDSR1_PDSR0_MASK                     (0x1U)                                              /*!< PAD_PDSR1.PDSR0 Mask                    */
#define PAD_PDSR1_PDSR0_SHIFT                    (0U)                                                /*!< PAD_PDSR1.PDSR0 Position                */
#define PAD_PDSR1_PDSR0(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PAD_PDSR1.PDSR0 Field                   */
#define PAD_PDSR1_PDSR1_MASK                     (0x2U)                                              /*!< PAD_PDSR1.PDSR1 Mask                    */
#define PAD_PDSR1_PDSR1_SHIFT                    (1U)                                                /*!< PAD_PDSR1.PDSR1 Position                */
#define PAD_PDSR1_PDSR1(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PAD_PDSR1.PDSR1 Field                   */
#define PAD_PDSR1_PDSR2_MASK                     (0x4U)                                              /*!< PAD_PDSR1.PDSR2 Mask                    */
#define PAD_PDSR1_PDSR2_SHIFT                    (2U)                                                /*!< PAD_PDSR1.PDSR2 Position                */
#define PAD_PDSR1_PDSR2(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< PAD_PDSR1.PDSR2 Field                   */
#define PAD_PDSR1_PDSR3_MASK                     (0x8U)                                              /*!< PAD_PDSR1.PDSR3 Mask                    */
#define PAD_PDSR1_PDSR3_SHIFT                    (3U)                                                /*!< PAD_PDSR1.PDSR3 Position                */
#define PAD_PDSR1_PDSR3(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< PAD_PDSR1.PDSR3 Field                   */
#define PAD_PDSR1_PDSR4_MASK                     (0x10U)                                             /*!< PAD_PDSR1.PDSR4 Mask                    */
#define PAD_PDSR1_PDSR4_SHIFT                    (4U)                                                /*!< PAD_PDSR1.PDSR4 Position                */
#define PAD_PDSR1_PDSR4(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< PAD_PDSR1.PDSR4 Field                   */
#define PAD_PDSR1_PDSR5_MASK                     (0x20U)                                             /*!< PAD_PDSR1.PDSR5 Mask                    */
#define PAD_PDSR1_PDSR5_SHIFT                    (5U)                                                /*!< PAD_PDSR1.PDSR5 Position                */
#define PAD_PDSR1_PDSR5(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< PAD_PDSR1.PDSR5 Field                   */
#define PAD_PDSR1_PDSR6_MASK                     (0x40U)                                             /*!< PAD_PDSR1.PDSR6 Mask                    */
#define PAD_PDSR1_PDSR6_SHIFT                    (6U)                                                /*!< PAD_PDSR1.PDSR6 Position                */
#define PAD_PDSR1_PDSR6(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< PAD_PDSR1.PDSR6 Field                   */
#define PAD_PDSR1_PDSR7_MASK                     (0x80U)                                             /*!< PAD_PDSR1.PDSR7 Mask                    */
#define PAD_PDSR1_PDSR7_SHIFT                    (7U)                                                /*!< PAD_PDSR1.PDSR7 Position                */
#define PAD_PDSR1_PDSR7(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< PAD_PDSR1.PDSR7 Field                   */
#define PAD_PDSR1_PDSR8_MASK                     (0x100U)                                            /*!< PAD_PDSR1.PDSR8 Mask                    */
#define PAD_PDSR1_PDSR8_SHIFT                    (8U)                                                /*!< PAD_PDSR1.PDSR8 Position                */
#define PAD_PDSR1_PDSR8(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< PAD_PDSR1.PDSR8 Field                   */
#define PAD_PDSR1_PDSR9_MASK                     (0x200U)                                            /*!< PAD_PDSR1.PDSR9 Mask                    */
#define PAD_PDSR1_PDSR9_SHIFT                    (9U)                                                /*!< PAD_PDSR1.PDSR9 Position                */
#define PAD_PDSR1_PDSR9(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< PAD_PDSR1.PDSR9 Field                   */
#define PAD_PDSR1_PDSR10_MASK                    (0x400U)                                            /*!< PAD_PDSR1.PDSR10 Mask                   */
#define PAD_PDSR1_PDSR10_SHIFT                   (10U)                                               /*!< PAD_PDSR1.PDSR10 Position               */
#define PAD_PDSR1_PDSR10(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< PAD_PDSR1.PDSR10 Field                  */
#define PAD_PDSR1_PDSR11_MASK                    (0x800U)                                            /*!< PAD_PDSR1.PDSR11 Mask                   */
#define PAD_PDSR1_PDSR11_SHIFT                   (11U)                                               /*!< PAD_PDSR1.PDSR11 Position               */
#define PAD_PDSR1_PDSR11(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< PAD_PDSR1.PDSR11 Field                  */
#define PAD_PDSR1_PDSR12_MASK                    (0x1000U)                                           /*!< PAD_PDSR1.PDSR12 Mask                   */
#define PAD_PDSR1_PDSR12_SHIFT                   (12U)                                               /*!< PAD_PDSR1.PDSR12 Position               */
#define PAD_PDSR1_PDSR12(x)                      (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< PAD_PDSR1.PDSR12 Field                  */
#define PAD_PDSR1_PDSR13_MASK                    (0x2000U)                                           /*!< PAD_PDSR1.PDSR13 Mask                   */
#define PAD_PDSR1_PDSR13_SHIFT                   (13U)                                               /*!< PAD_PDSR1.PDSR13 Position               */
#define PAD_PDSR1_PDSR13(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< PAD_PDSR1.PDSR13 Field                  */
#define PAD_PDSR1_PDSR14_MASK                    (0x4000U)                                           /*!< PAD_PDSR1.PDSR14 Mask                   */
#define PAD_PDSR1_PDSR14_SHIFT                   (14U)                                               /*!< PAD_PDSR1.PDSR14 Position               */
#define PAD_PDSR1_PDSR14(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< PAD_PDSR1.PDSR14 Field                  */
#define PAD_PDSR1_PDSR15_MASK                    (0x8000U)                                           /*!< PAD_PDSR1.PDSR15 Mask                   */
#define PAD_PDSR1_PDSR15_SHIFT                   (15U)                                               /*!< PAD_PDSR1.PDSR15 Position               */
#define PAD_PDSR1_PDSR15(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< PAD_PDSR1.PDSR15 Field                  */
#define PAD_PDSR1_PDSR16_MASK                    (0x10000U)                                          /*!< PAD_PDSR1.PDSR16 Mask                   */
#define PAD_PDSR1_PDSR16_SHIFT                   (16U)                                               /*!< PAD_PDSR1.PDSR16 Position               */
#define PAD_PDSR1_PDSR16(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< PAD_PDSR1.PDSR16 Field                  */
#define PAD_PDSR1_PDSR17_MASK                    (0x20000U)                                          /*!< PAD_PDSR1.PDSR17 Mask                   */
#define PAD_PDSR1_PDSR17_SHIFT                   (17U)                                               /*!< PAD_PDSR1.PDSR17 Position               */
#define PAD_PDSR1_PDSR17(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< PAD_PDSR1.PDSR17 Field                  */
#define PAD_PDSR1_PDSR18_MASK                    (0x40000U)                                          /*!< PAD_PDSR1.PDSR18 Mask                   */
#define PAD_PDSR1_PDSR18_SHIFT                   (18U)                                               /*!< PAD_PDSR1.PDSR18 Position               */
#define PAD_PDSR1_PDSR18(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< PAD_PDSR1.PDSR18 Field                  */
#define PAD_PDSR1_PDSR19_MASK                    (0x80000U)                                          /*!< PAD_PDSR1.PDSR19 Mask                   */
#define PAD_PDSR1_PDSR19_SHIFT                   (19U)                                               /*!< PAD_PDSR1.PDSR19 Position               */
#define PAD_PDSR1_PDSR19(x)                      (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< PAD_PDSR1.PDSR19 Field                  */
#define PAD_PDSR1_PDSR20_MASK                    (0x100000U)                                         /*!< PAD_PDSR1.PDSR20 Mask                   */
#define PAD_PDSR1_PDSR20_SHIFT                   (20U)                                               /*!< PAD_PDSR1.PDSR20 Position               */
#define PAD_PDSR1_PDSR20(x)                      (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< PAD_PDSR1.PDSR20 Field                  */
#define PAD_PDSR1_PDSR21_MASK                    (0x200000U)                                         /*!< PAD_PDSR1.PDSR21 Mask                   */
#define PAD_PDSR1_PDSR21_SHIFT                   (21U)                                               /*!< PAD_PDSR1.PDSR21 Position               */
#define PAD_PDSR1_PDSR21(x)                      (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< PAD_PDSR1.PDSR21 Field                  */
#define PAD_PDSR1_PDSR22_MASK                    (0x400000U)                                         /*!< PAD_PDSR1.PDSR22 Mask                   */
#define PAD_PDSR1_PDSR22_SHIFT                   (22U)                                               /*!< PAD_PDSR1.PDSR22 Position               */
#define PAD_PDSR1_PDSR22(x)                      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< PAD_PDSR1.PDSR22 Field                  */
#define PAD_PDSR1_PDSR23_MASK                    (0x800000U)                                         /*!< PAD_PDSR1.PDSR23 Mask                   */
#define PAD_PDSR1_PDSR23_SHIFT                   (23U)                                               /*!< PAD_PDSR1.PDSR23 Position               */
#define PAD_PDSR1_PDSR23(x)                      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< PAD_PDSR1.PDSR23 Field                  */
#define PAD_PDSR1_PDSR24_MASK                    (0x1000000U)                                        /*!< PAD_PDSR1.PDSR24 Mask                   */
#define PAD_PDSR1_PDSR24_SHIFT                   (24U)                                               /*!< PAD_PDSR1.PDSR24 Position               */
#define PAD_PDSR1_PDSR24(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< PAD_PDSR1.PDSR24 Field                  */
#define PAD_PDSR1_PDSR25_MASK                    (0x2000000U)                                        /*!< PAD_PDSR1.PDSR25 Mask                   */
#define PAD_PDSR1_PDSR25_SHIFT                   (25U)                                               /*!< PAD_PDSR1.PDSR25 Position               */
#define PAD_PDSR1_PDSR25(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< PAD_PDSR1.PDSR25 Field                  */
#define PAD_PDSR1_PDSR26_MASK                    (0x4000000U)                                        /*!< PAD_PDSR1.PDSR26 Mask                   */
#define PAD_PDSR1_PDSR26_SHIFT                   (26U)                                               /*!< PAD_PDSR1.PDSR26 Position               */
#define PAD_PDSR1_PDSR26(x)                      (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< PAD_PDSR1.PDSR26 Field                  */
#define PAD_PDSR1_PDSR27_MASK                    (0x8000000U)                                        /*!< PAD_PDSR1.PDSR27 Mask                   */
#define PAD_PDSR1_PDSR27_SHIFT                   (27U)                                               /*!< PAD_PDSR1.PDSR27 Position               */
#define PAD_PDSR1_PDSR27(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< PAD_PDSR1.PDSR27 Field                  */
#define PAD_PDSR1_PDSR28_MASK                    (0x10000000U)                                       /*!< PAD_PDSR1.PDSR28 Mask                   */
#define PAD_PDSR1_PDSR28_SHIFT                   (28U)                                               /*!< PAD_PDSR1.PDSR28 Position               */
#define PAD_PDSR1_PDSR28(x)                      (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< PAD_PDSR1.PDSR28 Field                  */
#define PAD_PDSR1_PDSR29_MASK                    (0x20000000U)                                       /*!< PAD_PDSR1.PDSR29 Mask                   */
#define PAD_PDSR1_PDSR29_SHIFT                   (29U)                                               /*!< PAD_PDSR1.PDSR29 Position               */
#define PAD_PDSR1_PDSR29(x)                      (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< PAD_PDSR1.PDSR29 Field                  */
#define PAD_PDSR1_PDSR30_MASK                    (0x40000000U)                                       /*!< PAD_PDSR1.PDSR30 Mask                   */
#define PAD_PDSR1_PDSR30_SHIFT                   (30U)                                               /*!< PAD_PDSR1.PDSR30 Position               */
#define PAD_PDSR1_PDSR30(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< PAD_PDSR1.PDSR30 Field                  */
#define PAD_PDSR1_PDSR31_MASK                    (0x80000000U)                                       /*!< PAD_PDSR1.PDSR31 Mask                   */
#define PAD_PDSR1_PDSR31_SHIFT                   (31U)                                               /*!< PAD_PDSR1.PDSR31 Position               */
#define PAD_PDSR1_PDSR31(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< PAD_PDSR1.PDSR31 Field                  */
/* ------- PDSR2 Bit Fields                         ------ */
#define PAD_PDSR2_PDSR0_MASK                     (0x1U)                                              /*!< PAD_PDSR2.PDSR0 Mask                    */
#define PAD_PDSR2_PDSR0_SHIFT                    (0U)                                                /*!< PAD_PDSR2.PDSR0 Position                */
#define PAD_PDSR2_PDSR0(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< PAD_PDSR2.PDSR0 Field                   */
#define PAD_PDSR2_PDSR1_MASK                     (0x2U)                                              /*!< PAD_PDSR2.PDSR1 Mask                    */
#define PAD_PDSR2_PDSR1_SHIFT                    (1U)                                                /*!< PAD_PDSR2.PDSR1 Position                */
#define PAD_PDSR2_PDSR1(x)                       (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< PAD_PDSR2.PDSR1 Field                   */
#define PAD_PDSR2_PDSR2_MASK                     (0x4U)                                              /*!< PAD_PDSR2.PDSR2 Mask                    */
#define PAD_PDSR2_PDSR2_SHIFT                    (2U)                                                /*!< PAD_PDSR2.PDSR2 Position                */
#define PAD_PDSR2_PDSR2(x)                       (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< PAD_PDSR2.PDSR2 Field                   */
#define PAD_PDSR2_PDSR3_MASK                     (0x8U)                                              /*!< PAD_PDSR2.PDSR3 Mask                    */
#define PAD_PDSR2_PDSR3_SHIFT                    (3U)                                                /*!< PAD_PDSR2.PDSR3 Position                */
#define PAD_PDSR2_PDSR3(x)                       (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< PAD_PDSR2.PDSR3 Field                   */
#define PAD_PDSR2_PDSR4_MASK                     (0x10U)                                             /*!< PAD_PDSR2.PDSR4 Mask                    */
#define PAD_PDSR2_PDSR4_SHIFT                    (4U)                                                /*!< PAD_PDSR2.PDSR4 Position                */
#define PAD_PDSR2_PDSR4(x)                       (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< PAD_PDSR2.PDSR4 Field                   */
#define PAD_PDSR2_PDSR5_MASK                     (0x20U)                                             /*!< PAD_PDSR2.PDSR5 Mask                    */
#define PAD_PDSR2_PDSR5_SHIFT                    (5U)                                                /*!< PAD_PDSR2.PDSR5 Position                */
#define PAD_PDSR2_PDSR5(x)                       (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< PAD_PDSR2.PDSR5 Field                   */
#define PAD_PDSR2_PDSR6_MASK                     (0x40U)                                             /*!< PAD_PDSR2.PDSR6 Mask                    */
#define PAD_PDSR2_PDSR6_SHIFT                    (6U)                                                /*!< PAD_PDSR2.PDSR6 Position                */
#define PAD_PDSR2_PDSR6(x)                       (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< PAD_PDSR2.PDSR6 Field                   */
#define PAD_PDSR2_PDSR7_MASK                     (0x80U)                                             /*!< PAD_PDSR2.PDSR7 Mask                    */
#define PAD_PDSR2_PDSR7_SHIFT                    (7U)                                                /*!< PAD_PDSR2.PDSR7 Position                */
#define PAD_PDSR2_PDSR7(x)                       (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< PAD_PDSR2.PDSR7 Field                   */
#define PAD_PDSR2_PDSR8_MASK                     (0x100U)                                            /*!< PAD_PDSR2.PDSR8 Mask                    */
#define PAD_PDSR2_PDSR8_SHIFT                    (8U)                                                /*!< PAD_PDSR2.PDSR8 Position                */
#define PAD_PDSR2_PDSR8(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< PAD_PDSR2.PDSR8 Field                   */
#define PAD_PDSR2_PDSR9_MASK                     (0x200U)                                            /*!< PAD_PDSR2.PDSR9 Mask                    */
#define PAD_PDSR2_PDSR9_SHIFT                    (9U)                                                /*!< PAD_PDSR2.PDSR9 Position                */
#define PAD_PDSR2_PDSR9(x)                       (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< PAD_PDSR2.PDSR9 Field                   */
#define PAD_PDSR2_PDSR10_MASK                    (0x400U)                                            /*!< PAD_PDSR2.PDSR10 Mask                   */
#define PAD_PDSR2_PDSR10_SHIFT                   (10U)                                               /*!< PAD_PDSR2.PDSR10 Position               */
#define PAD_PDSR2_PDSR10(x)                      (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< PAD_PDSR2.PDSR10 Field                  */
#define PAD_PDSR2_PDSR11_MASK                    (0x800U)                                            /*!< PAD_PDSR2.PDSR11 Mask                   */
#define PAD_PDSR2_PDSR11_SHIFT                   (11U)                                               /*!< PAD_PDSR2.PDSR11 Position               */
#define PAD_PDSR2_PDSR11(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< PAD_PDSR2.PDSR11 Field                  */
#define PAD_PDSR2_PDSR12_MASK                    (0x1000U)                                           /*!< PAD_PDSR2.PDSR12 Mask                   */
#define PAD_PDSR2_PDSR12_SHIFT                   (12U)                                               /*!< PAD_PDSR2.PDSR12 Position               */
#define PAD_PDSR2_PDSR12(x)                      (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< PAD_PDSR2.PDSR12 Field                  */
#define PAD_PDSR2_PDSR13_MASK                    (0x2000U)                                           /*!< PAD_PDSR2.PDSR13 Mask                   */
#define PAD_PDSR2_PDSR13_SHIFT                   (13U)                                               /*!< PAD_PDSR2.PDSR13 Position               */
#define PAD_PDSR2_PDSR13(x)                      (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< PAD_PDSR2.PDSR13 Field                  */
#define PAD_PDSR2_PDSR14_MASK                    (0x4000U)                                           /*!< PAD_PDSR2.PDSR14 Mask                   */
#define PAD_PDSR2_PDSR14_SHIFT                   (14U)                                               /*!< PAD_PDSR2.PDSR14 Position               */
#define PAD_PDSR2_PDSR14(x)                      (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< PAD_PDSR2.PDSR14 Field                  */
#define PAD_PDSR2_PDSR15_MASK                    (0x8000U)                                           /*!< PAD_PDSR2.PDSR15 Mask                   */
#define PAD_PDSR2_PDSR15_SHIFT                   (15U)                                               /*!< PAD_PDSR2.PDSR15 Position               */
#define PAD_PDSR2_PDSR15(x)                      (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< PAD_PDSR2.PDSR15 Field                  */
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
typedef struct PIT_Type {
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
#define PIT_PCSR_EN_MASK                         (0x1U)                                              /*!< PIT0_PCSR.EN Mask                       */
#define PIT_PCSR_EN_SHIFT                        (0U)                                                /*!< PIT0_PCSR.EN Position                   */
#define PIT_PCSR_EN(x)                           (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< PIT0_PCSR.EN Field                      */
#define PIT_PCSR_RLD_MASK                        (0x2U)                                              /*!< PIT0_PCSR.RLD Mask                      */
#define PIT_PCSR_RLD_SHIFT                       (1U)                                                /*!< PIT0_PCSR.RLD Position                  */
#define PIT_PCSR_RLD(x)                          (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< PIT0_PCSR.RLD Field                     */
#define PIT_PCSR_PIF_MASK                        (0x4U)                                              /*!< PIT0_PCSR.PIF Mask                      */
#define PIT_PCSR_PIF_SHIFT                       (2U)                                                /*!< PIT0_PCSR.PIF Position                  */
#define PIT_PCSR_PIF(x)                          (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< PIT0_PCSR.PIF Field                     */
#define PIT_PCSR_PIE_MASK                        (0x8U)                                              /*!< PIT0_PCSR.PIE Mask                      */
#define PIT_PCSR_PIE_SHIFT                       (3U)                                                /*!< PIT0_PCSR.PIE Position                  */
#define PIT_PCSR_PIE(x)                          (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< PIT0_PCSR.PIE Field                     */
#define PIT_PCSR_OVW_MASK                        (0x10U)                                             /*!< PIT0_PCSR.OVW Mask                      */
#define PIT_PCSR_OVW_SHIFT                       (4U)                                                /*!< PIT0_PCSR.OVW Position                  */
#define PIT_PCSR_OVW(x)                          (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< PIT0_PCSR.OVW Field                     */
#define PIT_PCSR_DBG_MASK                        (0x20U)                                             /*!< PIT0_PCSR.DBG Mask                      */
#define PIT_PCSR_DBG_SHIFT                       (5U)                                                /*!< PIT0_PCSR.DBG Position                  */
#define PIT_PCSR_DBG(x)                          (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< PIT0_PCSR.DBG Field                     */
#define PIT_PCSR_DOZE_MASK                       (0x40U)                                             /*!< PIT0_PCSR.DOZE Mask                     */
#define PIT_PCSR_DOZE_SHIFT                      (6U)                                                /*!< PIT0_PCSR.DOZE Position                 */
#define PIT_PCSR_DOZE(x)                         (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< PIT0_PCSR.DOZE Field                    */
#define PIT_PCSR_PRE_MASK                        (0xF00U)                                            /*!< PIT0_PCSR.PRE Mask                      */
#define PIT_PCSR_PRE_SHIFT                       (8U)                                                /*!< PIT0_PCSR.PRE Position                  */
#define PIT_PCSR_PRE(x)                          (((uint16_t)(((uint16_t)(x))<<8U))&0xF00UL)         /*!< PIT0_PCSR.PRE Field                     */
/* ------- PMR Bit Fields                           ------ */
#define PIT_PMR_PM_MASK                          (0xFFFFU)                                           /*!< PIT0_PMR.PM Mask                        */
#define PIT_PMR_PM_SHIFT                         (0U)                                                /*!< PIT0_PMR.PM Position                    */
#define PIT_PMR_PM(x)                            (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< PIT0_PMR.PM Field                       */
/* ------- PCNTR Bit Fields                         ------ */
#define PIT_PCNTR_PC_MASK                        (0xFFFFU)                                           /*!< PIT0_PCNTR.PC Mask                      */
#define PIT_PCNTR_PC_SHIFT                       (0U)                                                /*!< PIT0_PCNTR.PC Position                  */
#define PIT_PCNTR_PC(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< PIT0_PCNTR.PC Field                     */
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
typedef struct PMM_Type {
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
#define PMM_LPICR_XLPM_IPL_MASK                  (0x70U)                                             /*!< PMM_LPICR.XLPM_IPL Mask                 */
#define PMM_LPICR_XLPM_IPL_SHIFT                 (4U)                                                /*!< PMM_LPICR.XLPM_IPL Position             */
#define PMM_LPICR_XLPM_IPL(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x70UL)            /*!< PMM_LPICR.XLPM_IPL Field                */
#define PMM_LPICR_ENBSTOP_MASK                   (0x80U)                                             /*!< PMM_LPICR.ENBSTOP Mask                  */
#define PMM_LPICR_ENBSTOP_SHIFT                  (7U)                                                /*!< PMM_LPICR.ENBSTOP Position              */
#define PMM_LPICR_ENBSTOP(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PMM_LPICR.ENBSTOP Field                 */
/* ------- LPCR Bit Fields                          ------ */
#define PMM_LPCR_LVDSE_MASK                      (0x2U)                                              /*!< PMM_LPCR.LVDSE Mask                     */
#define PMM_LPCR_LVDSE_SHIFT                     (1U)                                                /*!< PMM_LPCR.LVDSE Position                 */
#define PMM_LPCR_LVDSE(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< PMM_LPCR.LVDSE Field                    */
#define PMM_LPCR_STPMD_MASK                      (0x18U)                                             /*!< PMM_LPCR.STPMD Mask                     */
#define PMM_LPCR_STPMD_SHIFT                     (3U)                                                /*!< PMM_LPCR.STPMD Position                 */
#define PMM_LPCR_STPMD(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x18UL)            /*!< PMM_LPCR.STPMD Field                    */
#define PMM_LPCR_LPMD_MASK                       (0xC0U)                                             /*!< PMM_LPCR.LPMD Mask                      */
#define PMM_LPCR_LPMD_SHIFT                      (6U)                                                /*!< PMM_LPCR.LPMD Position                  */
#define PMM_LPCR_LPMD(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< PMM_LPCR.LPMD Field                     */
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
typedef struct PWM_Type {
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
#define PWM_PWME_PWME0_MASK                      (0x1U)                                              /*!< PWM_PWME.PWME0 Mask                     */
#define PWM_PWME_PWME0_SHIFT                     (0U)                                                /*!< PWM_PWME.PWME0 Position                 */
#define PWM_PWME_PWME0(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< PWM_PWME.PWME0 Field                    */
#define PWM_PWME_PWME1_MASK                      (0x2U)                                              /*!< PWM_PWME.PWME1 Mask                     */
#define PWM_PWME_PWME1_SHIFT                     (1U)                                                /*!< PWM_PWME.PWME1 Position                 */
#define PWM_PWME_PWME1(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< PWM_PWME.PWME1 Field                    */
#define PWM_PWME_PWME2_MASK                      (0x4U)                                              /*!< PWM_PWME.PWME2 Mask                     */
#define PWM_PWME_PWME2_SHIFT                     (2U)                                                /*!< PWM_PWME.PWME2 Position                 */
#define PWM_PWME_PWME2(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< PWM_PWME.PWME2 Field                    */
#define PWM_PWME_PWME3_MASK                      (0x8U)                                              /*!< PWM_PWME.PWME3 Mask                     */
#define PWM_PWME_PWME3_SHIFT                     (3U)                                                /*!< PWM_PWME.PWME3 Position                 */
#define PWM_PWME_PWME3(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< PWM_PWME.PWME3 Field                    */
#define PWM_PWME_PWME4_MASK                      (0x10U)                                             /*!< PWM_PWME.PWME4 Mask                     */
#define PWM_PWME_PWME4_SHIFT                     (4U)                                                /*!< PWM_PWME.PWME4 Position                 */
#define PWM_PWME_PWME4(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PWM_PWME.PWME4 Field                    */
#define PWM_PWME_PWME5_MASK                      (0x20U)                                             /*!< PWM_PWME.PWME5 Mask                     */
#define PWM_PWME_PWME5_SHIFT                     (5U)                                                /*!< PWM_PWME.PWME5 Position                 */
#define PWM_PWME_PWME5(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PWM_PWME.PWME5 Field                    */
#define PWM_PWME_PWME6_MASK                      (0x40U)                                             /*!< PWM_PWME.PWME6 Mask                     */
#define PWM_PWME_PWME6_SHIFT                     (6U)                                                /*!< PWM_PWME.PWME6 Position                 */
#define PWM_PWME_PWME6(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PWM_PWME.PWME6 Field                    */
#define PWM_PWME_PWME7_MASK                      (0x80U)                                             /*!< PWM_PWME.PWME7 Mask                     */
#define PWM_PWME_PWME7_SHIFT                     (7U)                                                /*!< PWM_PWME.PWME7 Position                 */
#define PWM_PWME_PWME7(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PWM_PWME.PWME7 Field                    */
/* ------- PWMPOL Bit Fields                        ------ */
#define PWM_PWMPOL_PPOL0_MASK                    (0x1U)                                              /*!< PWM_PWMPOL.PPOL0 Mask                   */
#define PWM_PWMPOL_PPOL0_SHIFT                   (0U)                                                /*!< PWM_PWMPOL.PPOL0 Position               */
#define PWM_PWMPOL_PPOL0(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< PWM_PWMPOL.PPOL0 Field                  */
#define PWM_PWMPOL_PPOL1_MASK                    (0x2U)                                              /*!< PWM_PWMPOL.PPOL1 Mask                   */
#define PWM_PWMPOL_PPOL1_SHIFT                   (1U)                                                /*!< PWM_PWMPOL.PPOL1 Position               */
#define PWM_PWMPOL_PPOL1(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< PWM_PWMPOL.PPOL1 Field                  */
#define PWM_PWMPOL_PPOL2_MASK                    (0x4U)                                              /*!< PWM_PWMPOL.PPOL2 Mask                   */
#define PWM_PWMPOL_PPOL2_SHIFT                   (2U)                                                /*!< PWM_PWMPOL.PPOL2 Position               */
#define PWM_PWMPOL_PPOL2(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< PWM_PWMPOL.PPOL2 Field                  */
#define PWM_PWMPOL_PPOL3_MASK                    (0x8U)                                              /*!< PWM_PWMPOL.PPOL3 Mask                   */
#define PWM_PWMPOL_PPOL3_SHIFT                   (3U)                                                /*!< PWM_PWMPOL.PPOL3 Position               */
#define PWM_PWMPOL_PPOL3(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< PWM_PWMPOL.PPOL3 Field                  */
#define PWM_PWMPOL_PPOL4_MASK                    (0x10U)                                             /*!< PWM_PWMPOL.PPOL4 Mask                   */
#define PWM_PWMPOL_PPOL4_SHIFT                   (4U)                                                /*!< PWM_PWMPOL.PPOL4 Position               */
#define PWM_PWMPOL_PPOL4(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PWM_PWMPOL.PPOL4 Field                  */
#define PWM_PWMPOL_PPOL5_MASK                    (0x20U)                                             /*!< PWM_PWMPOL.PPOL5 Mask                   */
#define PWM_PWMPOL_PPOL5_SHIFT                   (5U)                                                /*!< PWM_PWMPOL.PPOL5 Position               */
#define PWM_PWMPOL_PPOL5(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PWM_PWMPOL.PPOL5 Field                  */
#define PWM_PWMPOL_PPOL6_MASK                    (0x40U)                                             /*!< PWM_PWMPOL.PPOL6 Mask                   */
#define PWM_PWMPOL_PPOL6_SHIFT                   (6U)                                                /*!< PWM_PWMPOL.PPOL6 Position               */
#define PWM_PWMPOL_PPOL6(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PWM_PWMPOL.PPOL6 Field                  */
#define PWM_PWMPOL_PPOL7_MASK                    (0x80U)                                             /*!< PWM_PWMPOL.PPOL7 Mask                   */
#define PWM_PWMPOL_PPOL7_SHIFT                   (7U)                                                /*!< PWM_PWMPOL.PPOL7 Position               */
#define PWM_PWMPOL_PPOL7(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PWM_PWMPOL.PPOL7 Field                  */
/* ------- PWMCLK Bit Fields                        ------ */
#define PWM_PWMCLK_PCLK0_MASK                    (0x1U)                                              /*!< PWM_PWMCLK.PCLK0 Mask                   */
#define PWM_PWMCLK_PCLK0_SHIFT                   (0U)                                                /*!< PWM_PWMCLK.PCLK0 Position               */
#define PWM_PWMCLK_PCLK0(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< PWM_PWMCLK.PCLK0 Field                  */
#define PWM_PWMCLK_PCLK1_MASK                    (0x2U)                                              /*!< PWM_PWMCLK.PCLK1 Mask                   */
#define PWM_PWMCLK_PCLK1_SHIFT                   (1U)                                                /*!< PWM_PWMCLK.PCLK1 Position               */
#define PWM_PWMCLK_PCLK1(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< PWM_PWMCLK.PCLK1 Field                  */
#define PWM_PWMCLK_PCLK2_MASK                    (0x4U)                                              /*!< PWM_PWMCLK.PCLK2 Mask                   */
#define PWM_PWMCLK_PCLK2_SHIFT                   (2U)                                                /*!< PWM_PWMCLK.PCLK2 Position               */
#define PWM_PWMCLK_PCLK2(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< PWM_PWMCLK.PCLK2 Field                  */
#define PWM_PWMCLK_PCLK3_MASK                    (0x8U)                                              /*!< PWM_PWMCLK.PCLK3 Mask                   */
#define PWM_PWMCLK_PCLK3_SHIFT                   (3U)                                                /*!< PWM_PWMCLK.PCLK3 Position               */
#define PWM_PWMCLK_PCLK3(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< PWM_PWMCLK.PCLK3 Field                  */
#define PWM_PWMCLK_PCLK4_MASK                    (0x10U)                                             /*!< PWM_PWMCLK.PCLK4 Mask                   */
#define PWM_PWMCLK_PCLK4_SHIFT                   (4U)                                                /*!< PWM_PWMCLK.PCLK4 Position               */
#define PWM_PWMCLK_PCLK4(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PWM_PWMCLK.PCLK4 Field                  */
#define PWM_PWMCLK_PCLK5_MASK                    (0x20U)                                             /*!< PWM_PWMCLK.PCLK5 Mask                   */
#define PWM_PWMCLK_PCLK5_SHIFT                   (5U)                                                /*!< PWM_PWMCLK.PCLK5 Position               */
#define PWM_PWMCLK_PCLK5(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PWM_PWMCLK.PCLK5 Field                  */
#define PWM_PWMCLK_PCLK6_MASK                    (0x40U)                                             /*!< PWM_PWMCLK.PCLK6 Mask                   */
#define PWM_PWMCLK_PCLK6_SHIFT                   (6U)                                                /*!< PWM_PWMCLK.PCLK6 Position               */
#define PWM_PWMCLK_PCLK6(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PWM_PWMCLK.PCLK6 Field                  */
#define PWM_PWMCLK_PCLK7_MASK                    (0x80U)                                             /*!< PWM_PWMCLK.PCLK7 Mask                   */
#define PWM_PWMCLK_PCLK7_SHIFT                   (7U)                                                /*!< PWM_PWMCLK.PCLK7 Position               */
#define PWM_PWMCLK_PCLK7(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PWM_PWMCLK.PCLK7 Field                  */
/* ------- PWMPRCLK Bit Fields                      ------ */
#define PWM_PWMPRCLK_PCKA_MASK                   (0x7U)                                              /*!< PWM_PWMPRCLK.PCKA Mask                  */
#define PWM_PWMPRCLK_PCKA_SHIFT                  (0U)                                                /*!< PWM_PWMPRCLK.PCKA Position              */
#define PWM_PWMPRCLK_PCKA(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< PWM_PWMPRCLK.PCKA Field                 */
#define PWM_PWMPRCLK_PCKB_MASK                   (0x70U)                                             /*!< PWM_PWMPRCLK.PCKB Mask                  */
#define PWM_PWMPRCLK_PCKB_SHIFT                  (4U)                                                /*!< PWM_PWMPRCLK.PCKB Position              */
#define PWM_PWMPRCLK_PCKB(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x70UL)            /*!< PWM_PWMPRCLK.PCKB Field                 */
/* ------- PWMCAE Bit Fields                        ------ */
#define PWM_PWMCAE_CAE0_MASK                     (0x1U)                                              /*!< PWM_PWMCAE.CAE0 Mask                    */
#define PWM_PWMCAE_CAE0_SHIFT                    (0U)                                                /*!< PWM_PWMCAE.CAE0 Position                */
#define PWM_PWMCAE_CAE0(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< PWM_PWMCAE.CAE0 Field                   */
#define PWM_PWMCAE_CAE1_MASK                     (0x2U)                                              /*!< PWM_PWMCAE.CAE1 Mask                    */
#define PWM_PWMCAE_CAE1_SHIFT                    (1U)                                                /*!< PWM_PWMCAE.CAE1 Position                */
#define PWM_PWMCAE_CAE1(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< PWM_PWMCAE.CAE1 Field                   */
#define PWM_PWMCAE_CAE2_MASK                     (0x4U)                                              /*!< PWM_PWMCAE.CAE2 Mask                    */
#define PWM_PWMCAE_CAE2_SHIFT                    (2U)                                                /*!< PWM_PWMCAE.CAE2 Position                */
#define PWM_PWMCAE_CAE2(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< PWM_PWMCAE.CAE2 Field                   */
#define PWM_PWMCAE_CAE3_MASK                     (0x8U)                                              /*!< PWM_PWMCAE.CAE3 Mask                    */
#define PWM_PWMCAE_CAE3_SHIFT                    (3U)                                                /*!< PWM_PWMCAE.CAE3 Position                */
#define PWM_PWMCAE_CAE3(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< PWM_PWMCAE.CAE3 Field                   */
#define PWM_PWMCAE_CAE4_MASK                     (0x10U)                                             /*!< PWM_PWMCAE.CAE4 Mask                    */
#define PWM_PWMCAE_CAE4_SHIFT                    (4U)                                                /*!< PWM_PWMCAE.CAE4 Position                */
#define PWM_PWMCAE_CAE4(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PWM_PWMCAE.CAE4 Field                   */
#define PWM_PWMCAE_CAE5_MASK                     (0x20U)                                             /*!< PWM_PWMCAE.CAE5 Mask                    */
#define PWM_PWMCAE_CAE5_SHIFT                    (5U)                                                /*!< PWM_PWMCAE.CAE5 Position                */
#define PWM_PWMCAE_CAE5(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PWM_PWMCAE.CAE5 Field                   */
#define PWM_PWMCAE_CAE6_MASK                     (0x40U)                                             /*!< PWM_PWMCAE.CAE6 Mask                    */
#define PWM_PWMCAE_CAE6_SHIFT                    (6U)                                                /*!< PWM_PWMCAE.CAE6 Position                */
#define PWM_PWMCAE_CAE6(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PWM_PWMCAE.CAE6 Field                   */
#define PWM_PWMCAE_CAE7_MASK                     (0x80U)                                             /*!< PWM_PWMCAE.CAE7 Mask                    */
#define PWM_PWMCAE_CAE7_SHIFT                    (7U)                                                /*!< PWM_PWMCAE.CAE7 Position                */
#define PWM_PWMCAE_CAE7(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PWM_PWMCAE.CAE7 Field                   */
/* ------- PWMCTL Bit Fields                        ------ */
#define PWM_PWMCTL_PFRZ_MASK                     (0x4U)                                              /*!< PWM_PWMCTL.PFRZ Mask                    */
#define PWM_PWMCTL_PFRZ_SHIFT                    (2U)                                                /*!< PWM_PWMCTL.PFRZ Position                */
#define PWM_PWMCTL_PFRZ(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< PWM_PWMCTL.PFRZ Field                   */
#define PWM_PWMCTL_PSWAI_MASK                    (0x8U)                                              /*!< PWM_PWMCTL.PSWAI Mask                   */
#define PWM_PWMCTL_PSWAI_SHIFT                   (3U)                                                /*!< PWM_PWMCTL.PSWAI Position               */
#define PWM_PWMCTL_PSWAI(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< PWM_PWMCTL.PSWAI Field                  */
#define PWM_PWMCTL_CON01_MASK                    (0x10U)                                             /*!< PWM_PWMCTL.CON01 Mask                   */
#define PWM_PWMCTL_CON01_SHIFT                   (4U)                                                /*!< PWM_PWMCTL.CON01 Position               */
#define PWM_PWMCTL_CON01(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PWM_PWMCTL.CON01 Field                  */
#define PWM_PWMCTL_CON23_MASK                    (0x20U)                                             /*!< PWM_PWMCTL.CON23 Mask                   */
#define PWM_PWMCTL_CON23_SHIFT                   (5U)                                                /*!< PWM_PWMCTL.CON23 Position               */
#define PWM_PWMCTL_CON23(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PWM_PWMCTL.CON23 Field                  */
#define PWM_PWMCTL_CON45_MASK                    (0x40U)                                             /*!< PWM_PWMCTL.CON45 Mask                   */
#define PWM_PWMCTL_CON45_SHIFT                   (6U)                                                /*!< PWM_PWMCTL.CON45 Position               */
#define PWM_PWMCTL_CON45(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PWM_PWMCTL.CON45 Field                  */
#define PWM_PWMCTL_CON67_MASK                    (0x80U)                                             /*!< PWM_PWMCTL.CON67 Mask                   */
#define PWM_PWMCTL_CON67_SHIFT                   (7U)                                                /*!< PWM_PWMCTL.CON67 Position               */
#define PWM_PWMCTL_CON67(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PWM_PWMCTL.CON67 Field                  */
/* ------- PWMSCLA Bit Fields                       ------ */
/* ------- PWMSCLB Bit Fields                       ------ */
/* ------- PWMCNT Bit Fields                        ------ */
/* ------- PWMPER Bit Fields                        ------ */
/* ------- PWMDTY Bit Fields                        ------ */
/* ------- PWMSDN Bit Fields                        ------ */
#define PWM_PWMSDN_SDNEN_MASK                    (0x1U)                                              /*!< PWM_PWMSDN.SDNEN Mask                   */
#define PWM_PWMSDN_SDNEN_SHIFT                   (0U)                                                /*!< PWM_PWMSDN.SDNEN Position               */
#define PWM_PWMSDN_SDNEN(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< PWM_PWMSDN.SDNEN Field                  */
#define PWM_PWMSDN_PWM7IL_MASK                   (0x2U)                                              /*!< PWM_PWMSDN.PWM7IL Mask                  */
#define PWM_PWMSDN_PWM7IL_SHIFT                  (1U)                                                /*!< PWM_PWMSDN.PWM7IL Position              */
#define PWM_PWMSDN_PWM7IL(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< PWM_PWMSDN.PWM7IL Field                 */
#define PWM_PWMSDN_PWM7IN_MASK                   (0x4U)                                              /*!< PWM_PWMSDN.PWM7IN Mask                  */
#define PWM_PWMSDN_PWM7IN_SHIFT                  (2U)                                                /*!< PWM_PWMSDN.PWM7IN Position              */
#define PWM_PWMSDN_PWM7IN(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< PWM_PWMSDN.PWM7IN Field                 */
#define PWM_PWMSDN_LVL_MASK                      (0x10U)                                             /*!< PWM_PWMSDN.LVL Mask                     */
#define PWM_PWMSDN_LVL_SHIFT                     (4U)                                                /*!< PWM_PWMSDN.LVL Position                 */
#define PWM_PWMSDN_LVL(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PWM_PWMSDN.LVL Field                    */
#define PWM_PWMSDN_RESTART_MASK                  (0x20U)                                             /*!< PWM_PWMSDN.RESTART Mask                 */
#define PWM_PWMSDN_RESTART_SHIFT                 (5U)                                                /*!< PWM_PWMSDN.RESTART Position             */
#define PWM_PWMSDN_RESTART(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PWM_PWMSDN.RESTART Field                */
#define PWM_PWMSDN_IE_MASK                       (0x40U)                                             /*!< PWM_PWMSDN.IE Mask                      */
#define PWM_PWMSDN_IE_SHIFT                      (6U)                                                /*!< PWM_PWMSDN.IE Position                  */
#define PWM_PWMSDN_IE(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PWM_PWMSDN.IE Field                     */
#define PWM_PWMSDN_IF_MASK                       (0x80U)                                             /*!< PWM_PWMSDN.IF Mask                      */
#define PWM_PWMSDN_IF_SHIFT                      (7U)                                                /*!< PWM_PWMSDN.IF Position                  */
#define PWM_PWMSDN_IF(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PWM_PWMSDN.IF Field                     */
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
typedef struct QSPI_Type {
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
#define QSPI_QMR_BAUD_MASK                       (0xFFU)                                             /*!< QSPI_QMR.BAUD Mask                      */
#define QSPI_QMR_BAUD_SHIFT                      (0U)                                                /*!< QSPI_QMR.BAUD Position                  */
#define QSPI_QMR_BAUD(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< QSPI_QMR.BAUD Field                     */
#define QSPI_QMR_CPHA_MASK                       (0x100U)                                            /*!< QSPI_QMR.CPHA Mask                      */
#define QSPI_QMR_CPHA_SHIFT                      (8U)                                                /*!< QSPI_QMR.CPHA Position                  */
#define QSPI_QMR_CPHA(x)                         (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< QSPI_QMR.CPHA Field                     */
#define QSPI_QMR_CPOL_MASK                       (0x200U)                                            /*!< QSPI_QMR.CPOL Mask                      */
#define QSPI_QMR_CPOL_SHIFT                      (9U)                                                /*!< QSPI_QMR.CPOL Position                  */
#define QSPI_QMR_CPOL(x)                         (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< QSPI_QMR.CPOL Field                     */
#define QSPI_QMR_BITS_MASK                       (0x3C00U)                                           /*!< QSPI_QMR.BITS Mask                      */
#define QSPI_QMR_BITS_SHIFT                      (10U)                                               /*!< QSPI_QMR.BITS Position                  */
#define QSPI_QMR_BITS(x)                         (((uint16_t)(((uint16_t)(x))<<10U))&0x3C00UL)       /*!< QSPI_QMR.BITS Field                     */
#define QSPI_QMR_DOHIE_MASK                      (0x4000U)                                           /*!< QSPI_QMR.DOHIE Mask                     */
#define QSPI_QMR_DOHIE_SHIFT                     (14U)                                               /*!< QSPI_QMR.DOHIE Position                 */
#define QSPI_QMR_DOHIE(x)                        (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< QSPI_QMR.DOHIE Field                    */
#define QSPI_QMR_MSTR_MASK                       (0x8000U)                                           /*!< QSPI_QMR.MSTR Mask                      */
#define QSPI_QMR_MSTR_SHIFT                      (15U)                                               /*!< QSPI_QMR.MSTR Position                  */
#define QSPI_QMR_MSTR(x)                         (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< QSPI_QMR.MSTR Field                     */
/* ------- QDLYR Bit Fields                         ------ */
#define QSPI_QDLYR_DTL_MASK                      (0xFFU)                                             /*!< QSPI_QDLYR.DTL Mask                     */
#define QSPI_QDLYR_DTL_SHIFT                     (0U)                                                /*!< QSPI_QDLYR.DTL Position                 */
#define QSPI_QDLYR_DTL(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< QSPI_QDLYR.DTL Field                    */
#define QSPI_QDLYR_QCD_MASK                      (0x7F00U)                                           /*!< QSPI_QDLYR.QCD Mask                     */
#define QSPI_QDLYR_QCD_SHIFT                     (8U)                                                /*!< QSPI_QDLYR.QCD Position                 */
#define QSPI_QDLYR_QCD(x)                        (((uint16_t)(((uint16_t)(x))<<8U))&0x7F00UL)        /*!< QSPI_QDLYR.QCD Field                    */
#define QSPI_QDLYR_SPE_MASK                      (0x8000U)                                           /*!< QSPI_QDLYR.SPE Mask                     */
#define QSPI_QDLYR_SPE_SHIFT                     (15U)                                               /*!< QSPI_QDLYR.SPE Position                 */
#define QSPI_QDLYR_SPE(x)                        (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< QSPI_QDLYR.SPE Field                    */
/* ------- QWR Bit Fields                           ------ */
#define QSPI_QWR_NEWQP_MASK                      (0xFU)                                              /*!< QSPI_QWR.NEWQP Mask                     */
#define QSPI_QWR_NEWQP_SHIFT                     (0U)                                                /*!< QSPI_QWR.NEWQP Position                 */
#define QSPI_QWR_NEWQP(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFUL)           /*!< QSPI_QWR.NEWQP Field                    */
#define QSPI_QWR_CPTQP_MASK                      (0xF0U)                                             /*!< QSPI_QWR.CPTQP Mask                     */
#define QSPI_QWR_CPTQP_SHIFT                     (4U)                                                /*!< QSPI_QWR.CPTQP Position                 */
#define QSPI_QWR_CPTQP(x)                        (((uint16_t)(((uint16_t)(x))<<4U))&0xF0UL)          /*!< QSPI_QWR.CPTQP Field                    */
#define QSPI_QWR_ENDQP_MASK                      (0xF00U)                                            /*!< QSPI_QWR.ENDQP Mask                     */
#define QSPI_QWR_ENDQP_SHIFT                     (8U)                                                /*!< QSPI_QWR.ENDQP Position                 */
#define QSPI_QWR_ENDQP(x)                        (((uint16_t)(((uint16_t)(x))<<8U))&0xF00UL)         /*!< QSPI_QWR.ENDQP Field                    */
#define QSPI_QWR_CSIV_MASK                       (0x1000U)                                           /*!< QSPI_QWR.CSIV Mask                      */
#define QSPI_QWR_CSIV_SHIFT                      (12U)                                               /*!< QSPI_QWR.CSIV Position                  */
#define QSPI_QWR_CSIV(x)                         (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< QSPI_QWR.CSIV Field                     */
#define QSPI_QWR_WRTO_MASK                       (0x2000U)                                           /*!< QSPI_QWR.WRTO Mask                      */
#define QSPI_QWR_WRTO_SHIFT                      (13U)                                               /*!< QSPI_QWR.WRTO Position                  */
#define QSPI_QWR_WRTO(x)                         (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< QSPI_QWR.WRTO Field                     */
#define QSPI_QWR_WREN_MASK                       (0x4000U)                                           /*!< QSPI_QWR.WREN Mask                      */
#define QSPI_QWR_WREN_SHIFT                      (14U)                                               /*!< QSPI_QWR.WREN Position                  */
#define QSPI_QWR_WREN(x)                         (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< QSPI_QWR.WREN Field                     */
#define QSPI_QWR_HALT_MASK                       (0x8000U)                                           /*!< QSPI_QWR.HALT Mask                      */
#define QSPI_QWR_HALT_SHIFT                      (15U)                                               /*!< QSPI_QWR.HALT Position                  */
#define QSPI_QWR_HALT(x)                         (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< QSPI_QWR.HALT Field                     */
/* ------- QIR Bit Fields                           ------ */
#define QSPI_QIR_SPIF_MASK                       (0x1U)                                              /*!< QSPI_QIR.SPIF Mask                      */
#define QSPI_QIR_SPIF_SHIFT                      (0U)                                                /*!< QSPI_QIR.SPIF Position                  */
#define QSPI_QIR_SPIF(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< QSPI_QIR.SPIF Field                     */
#define QSPI_QIR_ABRT_MASK                       (0x4U)                                              /*!< QSPI_QIR.ABRT Mask                      */
#define QSPI_QIR_ABRT_SHIFT                      (2U)                                                /*!< QSPI_QIR.ABRT Position                  */
#define QSPI_QIR_ABRT(x)                         (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< QSPI_QIR.ABRT Field                     */
#define QSPI_QIR_WCEF_MASK                       (0x8U)                                              /*!< QSPI_QIR.WCEF Mask                      */
#define QSPI_QIR_WCEF_SHIFT                      (3U)                                                /*!< QSPI_QIR.WCEF Position                  */
#define QSPI_QIR_WCEF(x)                         (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< QSPI_QIR.WCEF Field                     */
#define QSPI_QIR_SPIFE_MASK                      (0x100U)                                            /*!< QSPI_QIR.SPIFE Mask                     */
#define QSPI_QIR_SPIFE_SHIFT                     (8U)                                                /*!< QSPI_QIR.SPIFE Position                 */
#define QSPI_QIR_SPIFE(x)                        (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< QSPI_QIR.SPIFE Field                    */
#define QSPI_QIR_ABRTE_MASK                      (0x400U)                                            /*!< QSPI_QIR.ABRTE Mask                     */
#define QSPI_QIR_ABRTE_SHIFT                     (10U)                                               /*!< QSPI_QIR.ABRTE Position                 */
#define QSPI_QIR_ABRTE(x)                        (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< QSPI_QIR.ABRTE Field                    */
#define QSPI_QIR_WCEFE_MASK                      (0x800U)                                            /*!< QSPI_QIR.WCEFE Mask                     */
#define QSPI_QIR_WCEFE_SHIFT                     (11U)                                               /*!< QSPI_QIR.WCEFE Position                 */
#define QSPI_QIR_WCEFE(x)                        (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< QSPI_QIR.WCEFE Field                    */
#define QSPI_QIR_ABRTL_MASK                      (0x1000U)                                           /*!< QSPI_QIR.ABRTL Mask                     */
#define QSPI_QIR_ABRTL_SHIFT                     (12U)                                               /*!< QSPI_QIR.ABRTL Position                 */
#define QSPI_QIR_ABRTL(x)                        (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< QSPI_QIR.ABRTL Field                    */
#define QSPI_QIR_ABRTB_MASK                      (0x4000U)                                           /*!< QSPI_QIR.ABRTB Mask                     */
#define QSPI_QIR_ABRTB_SHIFT                     (14U)                                               /*!< QSPI_QIR.ABRTB Position                 */
#define QSPI_QIR_ABRTB(x)                        (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< QSPI_QIR.ABRTB Field                    */
#define QSPI_QIR_WCEFB_MASK                      (0x8000U)                                           /*!< QSPI_QIR.WCEFB Mask                     */
#define QSPI_QIR_WCEFB_SHIFT                     (15U)                                               /*!< QSPI_QIR.WCEFB Position                 */
#define QSPI_QIR_WCEFB(x)                        (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< QSPI_QIR.WCEFB Field                    */
/* ------- QAR Bit Fields                           ------ */
#define QSPI_QAR_ADDR_MASK                       (0x3FU)                                             /*!< QSPI_QAR.ADDR Mask                      */
#define QSPI_QAR_ADDR_SHIFT                      (0U)                                                /*!< QSPI_QAR.ADDR Position                  */
#define QSPI_QAR_ADDR(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< QSPI_QAR.ADDR Field                     */
/* ------- QDR Bit Fields                           ------ */
/* ------- QDR_COMMAND Bit Fields                   ------ */
#define QSPI_QDR_COMMAND_QSPI_CS0_MASK           (0x1U)                                              /*!< QSPI_QDR_COMMAND.QSPI_CS0 Mask          */
#define QSPI_QDR_COMMAND_QSPI_CS0_SHIFT          (0U)                                                /*!< QSPI_QDR_COMMAND.QSPI_CS0 Position      */
#define QSPI_QDR_COMMAND_QSPI_CS0(x)             (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< QSPI_QDR_COMMAND.QSPI_CS0 Field         */
#define QSPI_QDR_COMMAND_QSPI_CS1_MASK           (0x2U)                                              /*!< QSPI_QDR_COMMAND.QSPI_CS1 Mask          */
#define QSPI_QDR_COMMAND_QSPI_CS1_SHIFT          (1U)                                                /*!< QSPI_QDR_COMMAND.QSPI_CS1 Position      */
#define QSPI_QDR_COMMAND_QSPI_CS1(x)             (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< QSPI_QDR_COMMAND.QSPI_CS1 Field         */
#define QSPI_QDR_COMMAND_QSPI_CS2_MASK           (0x4U)                                              /*!< QSPI_QDR_COMMAND.QSPI_CS2 Mask          */
#define QSPI_QDR_COMMAND_QSPI_CS2_SHIFT          (2U)                                                /*!< QSPI_QDR_COMMAND.QSPI_CS2 Position      */
#define QSPI_QDR_COMMAND_QSPI_CS2(x)             (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< QSPI_QDR_COMMAND.QSPI_CS2 Field         */
#define QSPI_QDR_COMMAND_QSPI_CS3_MASK           (0x8U)                                              /*!< QSPI_QDR_COMMAND.QSPI_CS3 Mask          */
#define QSPI_QDR_COMMAND_QSPI_CS3_SHIFT          (3U)                                                /*!< QSPI_QDR_COMMAND.QSPI_CS3 Position      */
#define QSPI_QDR_COMMAND_QSPI_CS3(x)             (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< QSPI_QDR_COMMAND.QSPI_CS3 Field         */
#define QSPI_QDR_COMMAND_DSCK_MASK               (0x10U)                                             /*!< QSPI_QDR_COMMAND.DSCK Mask              */
#define QSPI_QDR_COMMAND_DSCK_SHIFT              (4U)                                                /*!< QSPI_QDR_COMMAND.DSCK Position          */
#define QSPI_QDR_COMMAND_DSCK(x)                 (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< QSPI_QDR_COMMAND.DSCK Field             */
#define QSPI_QDR_COMMAND_DT_MASK                 (0x20U)                                             /*!< QSPI_QDR_COMMAND.DT Mask                */
#define QSPI_QDR_COMMAND_DT_SHIFT                (5U)                                                /*!< QSPI_QDR_COMMAND.DT Position            */
#define QSPI_QDR_COMMAND_DT(x)                   (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< QSPI_QDR_COMMAND.DT Field               */
#define QSPI_QDR_COMMAND_BITSE_MASK              (0x40U)                                             /*!< QSPI_QDR_COMMAND.BITSE Mask             */
#define QSPI_QDR_COMMAND_BITSE_SHIFT             (6U)                                                /*!< QSPI_QDR_COMMAND.BITSE Position         */
#define QSPI_QDR_COMMAND_BITSE(x)                (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< QSPI_QDR_COMMAND.BITSE Field            */
#define QSPI_QDR_COMMAND_CONT_MASK               (0x80U)                                             /*!< QSPI_QDR_COMMAND.CONT Mask              */
#define QSPI_QDR_COMMAND_CONT_SHIFT              (7U)                                                /*!< QSPI_QDR_COMMAND.CONT Position          */
#define QSPI_QDR_COMMAND_CONT(x)                 (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< QSPI_QDR_COMMAND.CONT Field             */
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
/* ================           RCM (file:MCF52259_RCM)              ================ */
/* ================================================================================ */

/**
 * @brief Reset Controller Module
 */
/**
* @addtogroup RCM_structs_GROUP RCM struct
* @brief Struct for RCM
* @{
*/
typedef struct RCM_Type {
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
#define RCM_RCR_LVDE_MASK                        (0x1U)                                              /*!< RCM_RCR.LVDE Mask                       */
#define RCM_RCR_LVDE_SHIFT                       (0U)                                                /*!< RCM_RCR.LVDE Position                   */
#define RCM_RCR_LVDE(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< RCM_RCR.LVDE Field                      */
#define RCM_RCR_LVDRE_MASK                       (0x4U)                                              /*!< RCM_RCR.LVDRE Mask                      */
#define RCM_RCR_LVDRE_SHIFT                      (2U)                                                /*!< RCM_RCR.LVDRE Position                  */
#define RCM_RCR_LVDRE(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_RCR.LVDRE Field                     */
#define RCM_RCR_LVDIE_MASK                       (0x8U)                                              /*!< RCM_RCR.LVDIE Mask                      */
#define RCM_RCR_LVDIE_SHIFT                      (3U)                                                /*!< RCM_RCR.LVDIE Position                  */
#define RCM_RCR_LVDIE(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_RCR.LVDIE Field                     */
#define RCM_RCR_LVDF_MASK                        (0x10U)                                             /*!< RCM_RCR.LVDF Mask                       */
#define RCM_RCR_LVDF_SHIFT                       (4U)                                                /*!< RCM_RCR.LVDF Position                   */
#define RCM_RCR_LVDF(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< RCM_RCR.LVDF Field                      */
#define RCM_RCR_FRCRSTOUT_MASK                   (0x40U)                                             /*!< RCM_RCR.FRCRSTOUT Mask                  */
#define RCM_RCR_FRCRSTOUT_SHIFT                  (6U)                                                /*!< RCM_RCR.FRCRSTOUT Position              */
#define RCM_RCR_FRCRSTOUT(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< RCM_RCR.FRCRSTOUT Field                 */
#define RCM_RCR_SOFTRST_MASK                     (0x80U)                                             /*!< RCM_RCR.SOFTRST Mask                    */
#define RCM_RCR_SOFTRST_SHIFT                    (7U)                                                /*!< RCM_RCR.SOFTRST Position                */
#define RCM_RCR_SOFTRST(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< RCM_RCR.SOFTRST Field                   */
/* ------- RSR Bit Fields                           ------ */
#define RCM_RSR_LOL_MASK                         (0x1U)                                              /*!< RCM_RSR.LOL Mask                        */
#define RCM_RSR_LOL_SHIFT                        (0U)                                                /*!< RCM_RSR.LOL Position                    */
#define RCM_RSR_LOL(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< RCM_RSR.LOL Field                       */
#define RCM_RSR_LOC_MASK                         (0x2U)                                              /*!< RCM_RSR.LOC Mask                        */
#define RCM_RSR_LOC_SHIFT                        (1U)                                                /*!< RCM_RSR.LOC Position                    */
#define RCM_RSR_LOC(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_RSR.LOC Field                       */
#define RCM_RSR_EXT_MASK                         (0x4U)                                              /*!< RCM_RSR.EXT Mask                        */
#define RCM_RSR_EXT_SHIFT                        (2U)                                                /*!< RCM_RSR.EXT Position                    */
#define RCM_RSR_EXT(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_RSR.EXT Field                       */
#define RCM_RSR_POR_MASK                         (0x8U)                                              /*!< RCM_RSR.POR Mask                        */
#define RCM_RSR_POR_SHIFT                        (3U)                                                /*!< RCM_RSR.POR Position                    */
#define RCM_RSR_POR(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_RSR.POR Field                       */
#define RCM_RSR_WDR_MASK                         (0x10U)                                             /*!< RCM_RSR.WDR Mask                        */
#define RCM_RSR_WDR_SHIFT                        (4U)                                                /*!< RCM_RSR.WDR Position                    */
#define RCM_RSR_WDR(x)                           (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< RCM_RSR.WDR Field                       */
#define RCM_RSR_SOFT_MASK                        (0x20U)                                             /*!< RCM_RSR.SOFT Mask                       */
#define RCM_RSR_SOFT_SHIFT                       (5U)                                                /*!< RCM_RSR.SOFT Position                   */
#define RCM_RSR_SOFT(x)                          (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_RSR.SOFT Field                      */
#define RCM_RSR_LVD_MASK                         (0x40U)                                             /*!< RCM_RSR.LVD Mask                        */
#define RCM_RSR_LVD_SHIFT                        (6U)                                                /*!< RCM_RSR.LVD Position                    */
#define RCM_RSR_LVD(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< RCM_RSR.LVD Field                       */
#define RCM_RSR_BWT_MASK                         (0x80U)                                             /*!< RCM_RSR.BWT Mask                        */
#define RCM_RSR_BWT_SHIFT                        (7U)                                                /*!< RCM_RSR.BWT Position                    */
#define RCM_RSR_BWT(x)                           (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< RCM_RSR.BWT Field                       */
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
* @addtogroup RNGA_Peripheral_access_layer_GROUP RNGA Peripheral Access Layer
* @brief C Struct for RNGA
* @{
*/

/* ================================================================================ */
/* ================           RNGA (file:MCF52259_RNGA)            ================ */
/* ================================================================================ */

/**
 * @brief Random Number Generator
 */
/**
* @addtogroup RNGA_structs_GROUP RNGA struct
* @brief Struct for RNGA
* @{
*/
typedef struct RNGA_Type {
   __IO uint32_t  RNGCR;                        /**< 0000: Control Register                                             */
   __I  uint32_t  RNGSR;                        /**< 0004: Status Register                                              */
   __O  uint32_t  RNGER;                        /**< 0008: RNG Entropy Register                                         */
   __I  uint32_t  RNGOUT;                       /**< 000C: Output FIFO                                                  */
} RNGA_Type;

/**
 * @} */ /* End group RNGA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RNGA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RNGA_Register_Masks_GROUP RNGA Register Masks
* @brief Register Masks for RNGA
* @{
*/
/* ------- RNGCR Bit Fields                         ------ */
#define RNGA_RNGCR_GO_MASK                       (0x1U)                                              /*!< RNGA_RNGCR.GO Mask                      */
#define RNGA_RNGCR_GO_SHIFT                      (0U)                                                /*!< RNGA_RNGCR.GO Position                  */
#define RNGA_RNGCR_GO(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RNGA_RNGCR.GO Field                     */
#define RNGA_RNGCR_HA_MASK                       (0x2U)                                              /*!< RNGA_RNGCR.HA Mask                      */
#define RNGA_RNGCR_HA_SHIFT                      (1U)                                                /*!< RNGA_RNGCR.HA Position                  */
#define RNGA_RNGCR_HA(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RNGA_RNGCR.HA Field                     */
#define RNGA_RNGCR_IM_MASK                       (0x4U)                                              /*!< RNGA_RNGCR.IM Mask                      */
#define RNGA_RNGCR_IM_SHIFT                      (2U)                                                /*!< RNGA_RNGCR.IM Position                  */
#define RNGA_RNGCR_IM(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RNGA_RNGCR.IM Field                     */
#define RNGA_RNGCR_CI_MASK                       (0x8U)                                              /*!< RNGA_RNGCR.CI Mask                      */
#define RNGA_RNGCR_CI_SHIFT                      (3U)                                                /*!< RNGA_RNGCR.CI Position                  */
#define RNGA_RNGCR_CI(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< RNGA_RNGCR.CI Field                     */
#define RNGA_RNGCR_SLM_MASK                      (0x10U)                                             /*!< RNGA_RNGCR.SLM Mask                     */
#define RNGA_RNGCR_SLM_SHIFT                     (4U)                                                /*!< RNGA_RNGCR.SLM Position                 */
#define RNGA_RNGCR_SLM(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RNGA_RNGCR.SLM Field                    */
/* ------- RNGSR Bit Fields                         ------ */
#define RNGA_RNGSR_SV_MASK                       (0x1U)                                              /*!< RNGA_RNGSR.SV Mask                      */
#define RNGA_RNGSR_SV_SHIFT                      (0U)                                                /*!< RNGA_RNGSR.SV Position                  */
#define RNGA_RNGSR_SV(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RNGA_RNGSR.SV Field                     */
#define RNGA_RNGSR_LRS_MASK                      (0x2U)                                              /*!< RNGA_RNGSR.LRS Mask                     */
#define RNGA_RNGSR_LRS_SHIFT                     (1U)                                                /*!< RNGA_RNGSR.LRS Position                 */
#define RNGA_RNGSR_LRS(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RNGA_RNGSR.LRS Field                    */
#define RNGA_RNGSR_FUF_MASK                      (0x4U)                                              /*!< RNGA_RNGSR.FUF Mask                     */
#define RNGA_RNGSR_FUF_SHIFT                     (2U)                                                /*!< RNGA_RNGSR.FUF Position                 */
#define RNGA_RNGSR_FUF(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RNGA_RNGSR.FUF Field                    */
#define RNGA_RNGSR_EI_MASK                       (0x8U)                                              /*!< RNGA_RNGSR.EI Mask                      */
#define RNGA_RNGSR_EI_SHIFT                      (3U)                                                /*!< RNGA_RNGSR.EI Position                  */
#define RNGA_RNGSR_EI(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< RNGA_RNGSR.EI Field                     */
#define RNGA_RNGSR_SLP_MASK                      (0x10U)                                             /*!< RNGA_RNGSR.SLP Mask                     */
#define RNGA_RNGSR_SLP_SHIFT                     (4U)                                                /*!< RNGA_RNGSR.SLP Position                 */
#define RNGA_RNGSR_SLP(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RNGA_RNGSR.SLP Field                    */
#define RNGA_RNGSR_OFL_MASK                      (0xFF00U)                                           /*!< RNGA_RNGSR.OFL Mask                     */
#define RNGA_RNGSR_OFL_SHIFT                     (8U)                                                /*!< RNGA_RNGSR.OFL Position                 */
#define RNGA_RNGSR_OFL(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< RNGA_RNGSR.OFL Field                    */
#define RNGA_RNGSR_OFS_MASK                      (0xFF0000U)                                         /*!< RNGA_RNGSR.OFS Mask                     */
#define RNGA_RNGSR_OFS_SHIFT                     (16U)                                               /*!< RNGA_RNGSR.OFS Position                 */
#define RNGA_RNGSR_OFS(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< RNGA_RNGSR.OFS Field                    */
/* ------- RNGER Bit Fields                         ------ */
#define RNGA_RNGER_ENT_MASK                      (0xFFFFFFFFU)                                       /*!< RNGA_RNGER.ENT Mask                     */
#define RNGA_RNGER_ENT_SHIFT                     (0U)                                                /*!< RNGA_RNGER.ENT Position                 */
#define RNGA_RNGER_ENT(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< RNGA_RNGER.ENT Field                    */
/* ------- RNGOUT Bit Fields                        ------ */
#define RNGA_RNGOUT_RANDOM_OUTPUT_MASK           (0xFFFFFFFFU)                                       /*!< RNGA_RNGOUT.RANDOM_OUTPUT Mask          */
#define RNGA_RNGOUT_RANDOM_OUTPUT_SHIFT          (0U)                                                /*!< RNGA_RNGOUT.RANDOM_OUTPUT Position      */
#define RNGA_RNGOUT_RANDOM_OUTPUT(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< RNGA_RNGOUT.RANDOM_OUTPUT Field         */
/**
 * @} */ /* End group RNGA_Register_Masks_GROUP 
 */

/* RNGA - Peripheral instance base addresses */
#define RNGA_BasePtr                   0x401F0000UL //!< Peripheral base address
#define RNGA                           ((RNGA_Type *) RNGA_BasePtr) //!< Freescale base pointer
#define RNGA_BASE_PTR                  (RNGA) //!< Freescale style base pointer
/**
 * @} */ /* End group RNGA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer
* @brief C Struct for RTC
* @{
*/

/* ================================================================================ */
/* ================           RTC (file:MCF52259_RTC)              ================ */
/* ================================================================================ */

/**
 * @brief Real-Time Clock
 */
/**
* @addtogroup RTC_structs_GROUP RTC struct
* @brief Struct for RTC
* @{
*/
typedef struct RTC_Type {
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
        uint8_t   RESERVED_0[12];              
   __IO uint32_t  RTCGOCU;                      /**< 0034: General Oscillator Count Upper                               */
   __IO uint32_t  RTCGOCL;                      /**< 0038: General Oscillator Count Lower                               */
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
#define RTC_HOURMIN_MINUTES_MASK                 (0x3FU)                                             /*!< RTC_HOURMIN.MINUTES Mask                */
#define RTC_HOURMIN_MINUTES_SHIFT                (0U)                                                /*!< RTC_HOURMIN.MINUTES Position            */
#define RTC_HOURMIN_MINUTES(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< RTC_HOURMIN.MINUTES Field               */
#define RTC_HOURMIN_HOURS_MASK                   (0x1F00U)                                           /*!< RTC_HOURMIN.HOURS Mask                  */
#define RTC_HOURMIN_HOURS_SHIFT                  (8U)                                                /*!< RTC_HOURMIN.HOURS Position              */
#define RTC_HOURMIN_HOURS(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0x1F00UL)        /*!< RTC_HOURMIN.HOURS Field                 */
/* ------- SECONDS Bit Fields                       ------ */
#define RTC_SECONDS_SECONDS_MASK                 (0x3FU)                                             /*!< RTC_SECONDS.SECONDS Mask                */
#define RTC_SECONDS_SECONDS_SHIFT                (0U)                                                /*!< RTC_SECONDS.SECONDS Position            */
#define RTC_SECONDS_SECONDS(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< RTC_SECONDS.SECONDS Field               */
/* ------- ALRM_HM Bit Fields                       ------ */
#define RTC_ALRM_HM_MINUTES_MASK                 (0x3FU)                                             /*!< RTC_ALRM_HM.MINUTES Mask                */
#define RTC_ALRM_HM_MINUTES_SHIFT                (0U)                                                /*!< RTC_ALRM_HM.MINUTES Position            */
#define RTC_ALRM_HM_MINUTES(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< RTC_ALRM_HM.MINUTES Field               */
#define RTC_ALRM_HM_HOURS_MASK                   (0x1F00U)                                           /*!< RTC_ALRM_HM.HOURS Mask                  */
#define RTC_ALRM_HM_HOURS_SHIFT                  (8U)                                                /*!< RTC_ALRM_HM.HOURS Position              */
#define RTC_ALRM_HM_HOURS(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0x1F00UL)        /*!< RTC_ALRM_HM.HOURS Field                 */
/* ------- ALRM_SEC Bit Fields                      ------ */
#define RTC_ALRM_SEC_SECONDS_MASK                (0x3FU)                                             /*!< RTC_ALRM_SEC.SECONDS Mask               */
#define RTC_ALRM_SEC_SECONDS_SHIFT               (0U)                                                /*!< RTC_ALRM_SEC.SECONDS Position           */
#define RTC_ALRM_SEC_SECONDS(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< RTC_ALRM_SEC.SECONDS Field              */
/* ------- RTCCTL Bit Fields                        ------ */
#define RTC_RTCCTL_SWR_MASK                      (0x1U)                                              /*!< RTC_RTCCTL.SWR Mask                     */
#define RTC_RTCCTL_SWR_SHIFT                     (0U)                                                /*!< RTC_RTCCTL.SWR Position                 */
#define RTC_RTCCTL_SWR(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RTC_RTCCTL.SWR Field                    */
#define RTC_RTCCTL_EN_MASK                       (0x80U)                                             /*!< RTC_RTCCTL.EN Mask                      */
#define RTC_RTCCTL_EN_SHIFT                      (7U)                                                /*!< RTC_RTCCTL.EN Position                  */
#define RTC_RTCCTL_EN(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< RTC_RTCCTL.EN Field                     */
/* ------- RTCISR Bit Fields                        ------ */
#define RTC_RTCISR_SW_MASK                       (0x1U)                                              /*!< RTC_RTCISR.SW Mask                      */
#define RTC_RTCISR_SW_SHIFT                      (0U)                                                /*!< RTC_RTCISR.SW Position                  */
#define RTC_RTCISR_SW(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RTC_RTCISR.SW Field                     */
#define RTC_RTCISR_MIN_MASK                      (0x2U)                                              /*!< RTC_RTCISR.MIN Mask                     */
#define RTC_RTCISR_MIN_SHIFT                     (1U)                                                /*!< RTC_RTCISR.MIN Position                 */
#define RTC_RTCISR_MIN(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RTC_RTCISR.MIN Field                    */
#define RTC_RTCISR_ALM_MASK                      (0x4U)                                              /*!< RTC_RTCISR.ALM Mask                     */
#define RTC_RTCISR_ALM_SHIFT                     (2U)                                                /*!< RTC_RTCISR.ALM Position                 */
#define RTC_RTCISR_ALM(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RTC_RTCISR.ALM Field                    */
#define RTC_RTCISR_DAY_MASK                      (0x8U)                                              /*!< RTC_RTCISR.DAY Mask                     */
#define RTC_RTCISR_DAY_SHIFT                     (3U)                                                /*!< RTC_RTCISR.DAY Position                 */
#define RTC_RTCISR_DAY(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< RTC_RTCISR.DAY Field                    */
#define RTC_RTCISR_HZ1_MASK                      (0x10U)                                             /*!< RTC_RTCISR.HZ1 Mask                     */
#define RTC_RTCISR_HZ1_SHIFT                     (4U)                                                /*!< RTC_RTCISR.HZ1 Position                 */
#define RTC_RTCISR_HZ1(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RTC_RTCISR.HZ1 Field                    */
#define RTC_RTCISR_HR_MASK                       (0x20U)                                             /*!< RTC_RTCISR.HR Mask                      */
#define RTC_RTCISR_HR_SHIFT                      (5U)                                                /*!< RTC_RTCISR.HR Position                  */
#define RTC_RTCISR_HR(x)                         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< RTC_RTCISR.HR Field                     */
/* ------- RTCIENR Bit Fields                       ------ */
#define RTC_RTCIENR_SW_MASK                      (0x1U)                                              /*!< RTC_RTCIENR.SW Mask                     */
#define RTC_RTCIENR_SW_SHIFT                     (0U)                                                /*!< RTC_RTCIENR.SW Position                 */
#define RTC_RTCIENR_SW(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RTC_RTCIENR.SW Field                    */
#define RTC_RTCIENR_MIN_MASK                     (0x2U)                                              /*!< RTC_RTCIENR.MIN Mask                    */
#define RTC_RTCIENR_MIN_SHIFT                    (1U)                                                /*!< RTC_RTCIENR.MIN Position                */
#define RTC_RTCIENR_MIN(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RTC_RTCIENR.MIN Field                   */
#define RTC_RTCIENR_ALM_MASK                     (0x4U)                                              /*!< RTC_RTCIENR.ALM Mask                    */
#define RTC_RTCIENR_ALM_SHIFT                    (2U)                                                /*!< RTC_RTCIENR.ALM Position                */
#define RTC_RTCIENR_ALM(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RTC_RTCIENR.ALM Field                   */
#define RTC_RTCIENR_DAY_MASK                     (0x8U)                                              /*!< RTC_RTCIENR.DAY Mask                    */
#define RTC_RTCIENR_DAY_SHIFT                    (3U)                                                /*!< RTC_RTCIENR.DAY Position                */
#define RTC_RTCIENR_DAY(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< RTC_RTCIENR.DAY Field                   */
#define RTC_RTCIENR_HZ1_MASK                     (0x10U)                                             /*!< RTC_RTCIENR.HZ1 Mask                    */
#define RTC_RTCIENR_HZ1_SHIFT                    (4U)                                                /*!< RTC_RTCIENR.HZ1 Position                */
#define RTC_RTCIENR_HZ1(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RTC_RTCIENR.HZ1 Field                   */
#define RTC_RTCIENR_HR_MASK                      (0x20U)                                             /*!< RTC_RTCIENR.HR Mask                     */
#define RTC_RTCIENR_HR_SHIFT                     (5U)                                                /*!< RTC_RTCIENR.HR Position                 */
#define RTC_RTCIENR_HR(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< RTC_RTCIENR.HR Field                    */
/* ------- STPWCH Bit Fields                        ------ */
#define RTC_STPWCH_CNT_MASK                      (0x3FU)                                             /*!< RTC_STPWCH.CNT Mask                     */
#define RTC_STPWCH_CNT_SHIFT                     (0U)                                                /*!< RTC_STPWCH.CNT Position                 */
#define RTC_STPWCH_CNT(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< RTC_STPWCH.CNT Field                    */
/* ------- DAYS Bit Fields                          ------ */
#define RTC_DAYS_DAYS_MASK                       (0xFFFFU)                                           /*!< RTC_DAYS.DAYS Mask                      */
#define RTC_DAYS_DAYS_SHIFT                      (0U)                                                /*!< RTC_DAYS.DAYS Position                  */
#define RTC_DAYS_DAYS(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< RTC_DAYS.DAYS Field                     */
/* ------- ALRM_DAY Bit Fields                      ------ */
#define RTC_ALRM_DAY_DAYSAL_MASK                 (0xFFFFU)                                           /*!< RTC_ALRM_DAY.DAYSAL Mask                */
#define RTC_ALRM_DAY_DAYSAL_SHIFT                (0U)                                                /*!< RTC_ALRM_DAY.DAYSAL Position            */
#define RTC_ALRM_DAY_DAYSAL(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< RTC_ALRM_DAY.DAYSAL Field               */
/* ------- RTCGOCU Bit Fields                       ------ */
#define RTC_RTCGOCU_RTCGOCNT_MASK                (0xFFFFU)                                           /*!< RTC_RTCGOCU.RTCGOCNT Mask               */
#define RTC_RTCGOCU_RTCGOCNT_SHIFT               (0U)                                                /*!< RTC_RTCGOCU.RTCGOCNT Position           */
#define RTC_RTCGOCU_RTCGOCNT(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< RTC_RTCGOCU.RTCGOCNT Field              */
/* ------- RTCGOCL Bit Fields                       ------ */
#define RTC_RTCGOCL_RTCGOCNT_MASK                (0xFFFFU)                                           /*!< RTC_RTCGOCL.RTCGOCNT Mask               */
#define RTC_RTCGOCL_RTCGOCNT_SHIFT               (0U)                                                /*!< RTC_RTCGOCL.RTCGOCNT Position           */
#define RTC_RTCGOCL_RTCGOCNT(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< RTC_RTCGOCL.RTCGOCNT Field              */
/**
 * @} */ /* End group RTC_Register_Masks_GROUP 
 */

/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x40180000UL //!< Peripheral base address
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
/* ================           SCM (file:MCF52259_SCM)              ================ */
/* ================================================================================ */

/**
 * @brief System Control Module
 */
/**
* @addtogroup SCM_structs_GROUP SCM struct
* @brief Struct for SCM
* @{
*/
typedef struct SCM_Type {
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
   __IO uint8_t   PACR[11];                     /**< 0024: Peripheral Access Control Register                           */
        uint8_t   RESERVED_2;                  
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
#define SCM_IPSBAR_V_MASK                        (0x1U)                                              /*!< SCM_IPSBAR.V Mask                       */
#define SCM_IPSBAR_V_SHIFT                       (0U)                                                /*!< SCM_IPSBAR.V Position                   */
#define SCM_IPSBAR_V(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SCM_IPSBAR.V Field                      */
#define SCM_IPSBAR_BA_MASK                       (0xC0000000U)                                       /*!< SCM_IPSBAR.BA Mask                      */
#define SCM_IPSBAR_BA_SHIFT                      (30U)                                               /*!< SCM_IPSBAR.BA Position                  */
#define SCM_IPSBAR_BA(x)                         (((uint32_t)(((uint32_t)(x))<<30U))&0xC0000000UL)   /*!< SCM_IPSBAR.BA Field                     */
/* ------- RAMBAR Bit Fields                        ------ */
#define SCM_RAMBAR_BDE_MASK                      (0x200U)                                            /*!< SCM_RAMBAR.BDE Mask                     */
#define SCM_RAMBAR_BDE_SHIFT                     (9U)                                                /*!< SCM_RAMBAR.BDE Position                 */
#define SCM_RAMBAR_BDE(x)                        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SCM_RAMBAR.BDE Field                    */
#define SCM_RAMBAR_BA_MASK                       (0xFFFF0000U)                                       /*!< SCM_RAMBAR.BA Mask                      */
#define SCM_RAMBAR_BA_SHIFT                      (16U)                                               /*!< SCM_RAMBAR.BA Position                  */
#define SCM_RAMBAR_BA(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< SCM_RAMBAR.BA Field                     */
/* ------- PPMRH Bit Fields                         ------ */
#define SCM_PPMRH_CDGPIO_MASK                    (0x1U)                                              /*!< SCM_PPMRH.CDGPIO Mask                   */
#define SCM_PPMRH_CDGPIO_SHIFT                   (0U)                                                /*!< SCM_PPMRH.CDGPIO Position               */
#define SCM_PPMRH_CDGPIO(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SCM_PPMRH.CDGPIO Field                  */
#define SCM_PPMRH_CDEPORT_MASK                   (0x2U)                                              /*!< SCM_PPMRH.CDEPORT Mask                  */
#define SCM_PPMRH_CDEPORT_SHIFT                  (1U)                                                /*!< SCM_PPMRH.CDEPORT Position              */
#define SCM_PPMRH_CDEPORT(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SCM_PPMRH.CDEPORT Field                 */
#define SCM_PPMRH_CDPIT0_MASK                    (0x8U)                                              /*!< SCM_PPMRH.CDPIT0 Mask                   */
#define SCM_PPMRH_CDPIT0_SHIFT                   (3U)                                                /*!< SCM_PPMRH.CDPIT0 Position               */
#define SCM_PPMRH_CDPIT0(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SCM_PPMRH.CDPIT0 Field                  */
#define SCM_PPMRH_CDPIT1_MASK                    (0x10U)                                             /*!< SCM_PPMRH.CDPIT1 Mask                   */
#define SCM_PPMRH_CDPIT1_SHIFT                   (4U)                                                /*!< SCM_PPMRH.CDPIT1 Position               */
#define SCM_PPMRH_CDPIT1(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SCM_PPMRH.CDPIT1 Field                  */
#define SCM_PPMRH_CDADC_MASK                     (0x80U)                                             /*!< SCM_PPMRH.CDADC Mask                    */
#define SCM_PPMRH_CDADC_SHIFT                    (7U)                                                /*!< SCM_PPMRH.CDADC Position                */
#define SCM_PPMRH_CDADC(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SCM_PPMRH.CDADC Field                   */
#define SCM_PPMRH_CDGPT_MASK                     (0x100U)                                            /*!< SCM_PPMRH.CDGPT Mask                    */
#define SCM_PPMRH_CDGPT_SHIFT                    (8U)                                                /*!< SCM_PPMRH.CDGPT Position                */
#define SCM_PPMRH_CDGPT(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SCM_PPMRH.CDGPT Field                   */
#define SCM_PPMRH_CDPWM_MASK                     (0x200U)                                            /*!< SCM_PPMRH.CDPWM Mask                    */
#define SCM_PPMRH_CDPWM_SHIFT                    (9U)                                                /*!< SCM_PPMRH.CDPWM Position                */
#define SCM_PPMRH_CDPWM(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SCM_PPMRH.CDPWM Field                   */
#define SCM_PPMRH_CDCAN_MASK                     (0x400U)                                            /*!< SCM_PPMRH.CDCAN Mask                    */
#define SCM_PPMRH_CDCAN_SHIFT                    (10U)                                               /*!< SCM_PPMRH.CDCAN Position                */
#define SCM_PPMRH_CDCAN(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SCM_PPMRH.CDCAN Field                   */
#define SCM_PPMRH_CDCFM_MASK                     (0x800U)                                            /*!< SCM_PPMRH.CDCFM Mask                    */
#define SCM_PPMRH_CDCFM_SHIFT                    (11U)                                               /*!< SCM_PPMRH.CDCFM Position                */
#define SCM_PPMRH_CDCFM(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SCM_PPMRH.CDCFM Field                   */
/* ------- CRSR Bit Fields                          ------ */
#define SCM_CRSR_EXT_MASK                        (0x80U)                                             /*!< SCM_CRSR.EXT Mask                       */
#define SCM_CRSR_EXT_SHIFT                       (7U)                                                /*!< SCM_CRSR.EXT Position                   */
#define SCM_CRSR_EXT(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< SCM_CRSR.EXT Field                      */
/* ------- CWCR Bit Fields                          ------ */
#define SCM_CWCR_CWTIF_MASK                      (0x1U)                                              /*!< SCM_CWCR.CWTIF Mask                     */
#define SCM_CWCR_CWTIF_SHIFT                     (0U)                                                /*!< SCM_CWCR.CWTIF Position                 */
#define SCM_CWCR_CWTIF(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< SCM_CWCR.CWTIF Field                    */
#define SCM_CWCR_CWTAVAL_MASK                    (0x2U)                                              /*!< SCM_CWCR.CWTAVAL Mask                   */
#define SCM_CWCR_CWTAVAL_SHIFT                   (1U)                                                /*!< SCM_CWCR.CWTAVAL Position               */
#define SCM_CWCR_CWTAVAL(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< SCM_CWCR.CWTAVAL Field                  */
#define SCM_CWCR_CWTA_MASK                       (0x4U)                                              /*!< SCM_CWCR.CWTA Mask                      */
#define SCM_CWCR_CWTA_SHIFT                      (2U)                                                /*!< SCM_CWCR.CWTA Position                  */
#define SCM_CWCR_CWTA(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< SCM_CWCR.CWTA Field                     */
#define SCM_CWCR_CWT_MASK                        (0x38U)                                             /*!< SCM_CWCR.CWT Mask                       */
#define SCM_CWCR_CWT_SHIFT                       (3U)                                                /*!< SCM_CWCR.CWT Position                   */
#define SCM_CWCR_CWT(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x38UL)            /*!< SCM_CWCR.CWT Field                      */
#define SCM_CWCR_CWRI_MASK                       (0x40U)                                             /*!< SCM_CWCR.CWRI Mask                      */
#define SCM_CWCR_CWRI_SHIFT                      (6U)                                                /*!< SCM_CWCR.CWRI Position                  */
#define SCM_CWCR_CWRI(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< SCM_CWCR.CWRI Field                     */
#define SCM_CWCR_CWE_MASK                        (0x80U)                                             /*!< SCM_CWCR.CWE Mask                       */
#define SCM_CWCR_CWE_SHIFT                       (7U)                                                /*!< SCM_CWCR.CWE Position                   */
#define SCM_CWCR_CWE(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< SCM_CWCR.CWE Field                      */
/* ------- CWSR Bit Fields                          ------ */
/* ------- DMAREQC Bit Fields                       ------ */
#define SCM_DMAREQC_DMAC0_MASK                   (0xFU)                                              /*!< SCM_DMAREQC.DMAC0 Mask                  */
#define SCM_DMAREQC_DMAC0_SHIFT                  (0U)                                                /*!< SCM_DMAREQC.DMAC0 Position              */
#define SCM_DMAREQC_DMAC0(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SCM_DMAREQC.DMAC0 Field                 */
#define SCM_DMAREQC_DMAC1_MASK                   (0xF0U)                                             /*!< SCM_DMAREQC.DMAC1 Mask                  */
#define SCM_DMAREQC_DMAC1_SHIFT                  (4U)                                                /*!< SCM_DMAREQC.DMAC1 Position              */
#define SCM_DMAREQC_DMAC1(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< SCM_DMAREQC.DMAC1 Field                 */
#define SCM_DMAREQC_DMAC2_MASK                   (0xF00U)                                            /*!< SCM_DMAREQC.DMAC2 Mask                  */
#define SCM_DMAREQC_DMAC2_SHIFT                  (8U)                                                /*!< SCM_DMAREQC.DMAC2 Position              */
#define SCM_DMAREQC_DMAC2(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< SCM_DMAREQC.DMAC2 Field                 */
#define SCM_DMAREQC_DMAC3_MASK                   (0xF000U)                                           /*!< SCM_DMAREQC.DMAC3 Mask                  */
#define SCM_DMAREQC_DMAC3_SHIFT                  (12U)                                               /*!< SCM_DMAREQC.DMAC3 Position              */
#define SCM_DMAREQC_DMAC3(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SCM_DMAREQC.DMAC3 Field                 */
/* ------- PPMRL Bit Fields                         ------ */
#define SCM_PPMRL_CDG_MASK                       (0x2U)                                              /*!< SCM_PPMRL.CDG Mask                      */
#define SCM_PPMRL_CDG_SHIFT                      (1U)                                                /*!< SCM_PPMRL.CDG Position                  */
#define SCM_PPMRL_CDG(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SCM_PPMRL.CDG Field                     */
#define SCM_PPMRL_CDMINIBUS_MASK                 (0x8U)                                              /*!< SCM_PPMRL.CDMINIBUS Mask                */
#define SCM_PPMRL_CDMINIBUS_SHIFT                (3U)                                                /*!< SCM_PPMRL.CDMINIBUS Position            */
#define SCM_PPMRL_CDMINIBUS(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SCM_PPMRL.CDMINIBUS Field               */
#define SCM_PPMRL_CDDMA_MASK                     (0x10U)                                             /*!< SCM_PPMRL.CDDMA Mask                    */
#define SCM_PPMRL_CDDMA_SHIFT                    (4U)                                                /*!< SCM_PPMRL.CDDMA Position                */
#define SCM_PPMRL_CDDMA(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SCM_PPMRL.CDDMA Field                   */
#define SCM_PPMRL_CDUART0_MASK                   (0x20U)                                             /*!< SCM_PPMRL.CDUART0 Mask                  */
#define SCM_PPMRL_CDUART0_SHIFT                  (5U)                                                /*!< SCM_PPMRL.CDUART0 Position              */
#define SCM_PPMRL_CDUART0(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SCM_PPMRL.CDUART0 Field                 */
#define SCM_PPMRL_CDUART1_MASK                   (0x40U)                                             /*!< SCM_PPMRL.CDUART1 Mask                  */
#define SCM_PPMRL_CDUART1_SHIFT                  (6U)                                                /*!< SCM_PPMRL.CDUART1 Position              */
#define SCM_PPMRL_CDUART1(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SCM_PPMRL.CDUART1 Field                 */
#define SCM_PPMRL_CDUART2_MASK                   (0x80U)                                             /*!< SCM_PPMRL.CDUART2 Mask                  */
#define SCM_PPMRL_CDUART2_SHIFT                  (7U)                                                /*!< SCM_PPMRL.CDUART2 Position              */
#define SCM_PPMRL_CDUART2(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SCM_PPMRL.CDUART2 Field                 */
#define SCM_PPMRL_CDI2C0_MASK                    (0x200U)                                            /*!< SCM_PPMRL.CDI2C0 Mask                   */
#define SCM_PPMRL_CDI2C0_SHIFT                   (9U)                                                /*!< SCM_PPMRL.CDI2C0 Position               */
#define SCM_PPMRL_CDI2C0(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SCM_PPMRL.CDI2C0 Field                  */
#define SCM_PPMRL_CDQSPI_MASK                    (0x400U)                                            /*!< SCM_PPMRL.CDQSPI Mask                   */
#define SCM_PPMRL_CDQSPI_SHIFT                   (10U)                                               /*!< SCM_PPMRL.CDQSPI Position               */
#define SCM_PPMRL_CDQSPI(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SCM_PPMRL.CDQSPI Field                  */
#define SCM_PPMRL_CDI2C1_MASK                    (0x800U)                                            /*!< SCM_PPMRL.CDI2C1 Mask                   */
#define SCM_PPMRL_CDI2C1_SHIFT                   (11U)                                               /*!< SCM_PPMRL.CDI2C1 Position               */
#define SCM_PPMRL_CDI2C1(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SCM_PPMRL.CDI2C1 Field                  */
#define SCM_PPMRL_CDRTC_MASK                     (0x1000U)                                           /*!< SCM_PPMRL.CDRTC Mask                    */
#define SCM_PPMRL_CDRTC_SHIFT                    (12U)                                               /*!< SCM_PPMRL.CDRTC Position                */
#define SCM_PPMRL_CDRTC(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SCM_PPMRL.CDRTC Field                   */
#define SCM_PPMRL_CDDTIM0_MASK                   (0x2000U)                                           /*!< SCM_PPMRL.CDDTIM0 Mask                  */
#define SCM_PPMRL_CDDTIM0_SHIFT                  (13U)                                               /*!< SCM_PPMRL.CDDTIM0 Position              */
#define SCM_PPMRL_CDDTIM0(x)                     (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SCM_PPMRL.CDDTIM0 Field                 */
#define SCM_PPMRL_CDDTIM1_MASK                   (0x4000U)                                           /*!< SCM_PPMRL.CDDTIM1 Mask                  */
#define SCM_PPMRL_CDDTIM1_SHIFT                  (14U)                                               /*!< SCM_PPMRL.CDDTIM1 Position              */
#define SCM_PPMRL_CDDTIM1(x)                     (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< SCM_PPMRL.CDDTIM1 Field                 */
#define SCM_PPMRL_CDDTIM2_MASK                   (0x8000U)                                           /*!< SCM_PPMRL.CDDTIM2 Mask                  */
#define SCM_PPMRL_CDDTIM2_SHIFT                  (15U)                                               /*!< SCM_PPMRL.CDDTIM2 Position              */
#define SCM_PPMRL_CDDTIM2(x)                     (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< SCM_PPMRL.CDDTIM2 Field                 */
#define SCM_PPMRL_CDDTIM3_MASK                   (0x10000U)                                          /*!< SCM_PPMRL.CDDTIM3 Mask                  */
#define SCM_PPMRL_CDDTIM3_SHIFT                  (16U)                                               /*!< SCM_PPMRL.CDDTIM3 Position              */
#define SCM_PPMRL_CDDTIM3(x)                     (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SCM_PPMRL.CDDTIM3 Field                 */
#define SCM_PPMRL_CDINTC0_MASK                   (0x20000U)                                          /*!< SCM_PPMRL.CDINTC0 Mask                  */
#define SCM_PPMRL_CDINTC0_SHIFT                  (17U)                                               /*!< SCM_PPMRL.CDINTC0 Position              */
#define SCM_PPMRL_CDINTC0(x)                     (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SCM_PPMRL.CDINTC0 Field                 */
#define SCM_PPMRL_CDINTC1_MASK                   (0x40000U)                                          /*!< SCM_PPMRL.CDINTC1 Mask                  */
#define SCM_PPMRL_CDINTC1_SHIFT                  (18U)                                               /*!< SCM_PPMRL.CDINTC1 Position              */
#define SCM_PPMRL_CDINTC1(x)                     (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< SCM_PPMRL.CDINTC1 Field                 */
#define SCM_PPMRL_CDFEC_MASK                     (0x200000U)                                         /*!< SCM_PPMRL.CDFEC Mask                    */
#define SCM_PPMRL_CDFEC_SHIFT                    (21U)                                               /*!< SCM_PPMRL.CDFEC Position                */
#define SCM_PPMRL_CDFEC(x)                       (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< SCM_PPMRL.CDFEC Field                   */
/* ------- MPARK Bit Fields                         ------ */
#define SCM_MPARK_LCKOUT_TIME_MASK               (0xF00U)                                            /*!< SCM_MPARK.LCKOUT_TIME Mask              */
#define SCM_MPARK_LCKOUT_TIME_SHIFT              (8U)                                                /*!< SCM_MPARK.LCKOUT_TIME Position          */
#define SCM_MPARK_LCKOUT_TIME(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< SCM_MPARK.LCKOUT_TIME Field             */
#define SCM_MPARK_PRKLAST_MASK                   (0x1000U)                                           /*!< SCM_MPARK.PRKLAST Mask                  */
#define SCM_MPARK_PRKLAST_SHIFT                  (12U)                                               /*!< SCM_MPARK.PRKLAST Position              */
#define SCM_MPARK_PRKLAST(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SCM_MPARK.PRKLAST Field                 */
#define SCM_MPARK_TIMEOUT_MASK                   (0x2000U)                                           /*!< SCM_MPARK.TIMEOUT Mask                  */
#define SCM_MPARK_TIMEOUT_SHIFT                  (13U)                                               /*!< SCM_MPARK.TIMEOUT Position              */
#define SCM_MPARK_TIMEOUT(x)                     (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SCM_MPARK.TIMEOUT Field                 */
#define SCM_MPARK_FIXED_MASK                     (0x4000U)                                           /*!< SCM_MPARK.FIXED Mask                    */
#define SCM_MPARK_FIXED_SHIFT                    (14U)                                               /*!< SCM_MPARK.FIXED Position                */
#define SCM_MPARK_FIXED(x)                       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< SCM_MPARK.FIXED Field                   */
#define SCM_MPARK_M1_PRTY_MASK                   (0x30000U)                                          /*!< SCM_MPARK.M1_PRTY Mask                  */
#define SCM_MPARK_M1_PRTY_SHIFT                  (16U)                                               /*!< SCM_MPARK.M1_PRTY Position              */
#define SCM_MPARK_M1_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< SCM_MPARK.M1_PRTY Field                 */
#define SCM_MPARK_M0_PRTY_MASK                   (0xC0000U)                                          /*!< SCM_MPARK.M0_PRTY Mask                  */
#define SCM_MPARK_M0_PRTY_SHIFT                  (18U)                                               /*!< SCM_MPARK.M0_PRTY Position              */
#define SCM_MPARK_M0_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< SCM_MPARK.M0_PRTY Field                 */
#define SCM_MPARK_M2_PRTY_MASK                   (0x300000U)                                         /*!< SCM_MPARK.M2_PRTY Mask                  */
#define SCM_MPARK_M2_PRTY_SHIFT                  (20U)                                               /*!< SCM_MPARK.M2_PRTY Position              */
#define SCM_MPARK_M2_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<20U))&0x300000UL)     /*!< SCM_MPARK.M2_PRTY Field                 */
#define SCM_MPARK_M3_PRTY_MASK                   (0xC00000U)                                         /*!< SCM_MPARK.M3_PRTY Mask                  */
#define SCM_MPARK_M3_PRTY_SHIFT                  (22U)                                               /*!< SCM_MPARK.M3_PRTY Position              */
#define SCM_MPARK_M3_PRTY(x)                     (((uint32_t)(((uint32_t)(x))<<22U))&0xC00000UL)     /*!< SCM_MPARK.M3_PRTY Field                 */
#define SCM_MPARK_BCR24BIT_MASK                  (0x1000000U)                                        /*!< SCM_MPARK.BCR24BIT Mask                 */
#define SCM_MPARK_BCR24BIT_SHIFT                 (24U)                                               /*!< SCM_MPARK.BCR24BIT Position             */
#define SCM_MPARK_BCR24BIT(x)                    (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SCM_MPARK.BCR24BIT Field                */
#define SCM_MPARK_M2_P_EN_MASK                   (0x2000000U)                                        /*!< SCM_MPARK.M2_P_EN Mask                  */
#define SCM_MPARK_M2_P_EN_SHIFT                  (25U)                                               /*!< SCM_MPARK.M2_P_EN Position              */
#define SCM_MPARK_M2_P_EN(x)                     (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SCM_MPARK.M2_P_EN Field                 */
/* ------- MPR Bit Fields                           ------ */
#define SCM_MPR_MPR0_MASK                        (0x1U)                                              /*!< SCM_MPR.MPR0 Mask                       */
#define SCM_MPR_MPR0_SHIFT                       (0U)                                                /*!< SCM_MPR.MPR0 Position                   */
#define SCM_MPR_MPR0(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< SCM_MPR.MPR0 Field                      */
#define SCM_MPR_MPR1_MASK                        (0x2U)                                              /*!< SCM_MPR.MPR1 Mask                       */
#define SCM_MPR_MPR1_SHIFT                       (1U)                                                /*!< SCM_MPR.MPR1 Position                   */
#define SCM_MPR_MPR1(x)                          (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< SCM_MPR.MPR1 Field                      */
#define SCM_MPR_MPR2_MASK                        (0x4U)                                              /*!< SCM_MPR.MPR2 Mask                       */
#define SCM_MPR_MPR2_SHIFT                       (2U)                                                /*!< SCM_MPR.MPR2 Position                   */
#define SCM_MPR_MPR2(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< SCM_MPR.MPR2 Field                      */
#define SCM_MPR_MPR3_MASK                        (0x8U)                                              /*!< SCM_MPR.MPR3 Mask                       */
#define SCM_MPR_MPR3_SHIFT                       (3U)                                                /*!< SCM_MPR.MPR3 Position                   */
#define SCM_MPR_MPR3(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< SCM_MPR.MPR3 Field                      */
/* ------- PPMRS Bit Fields                         ------ */
#define SCM_PPMRS_SMCD_MASK                      (0x1FU)                                             /*!< SCM_PPMRS.SMCD Mask                     */
#define SCM_PPMRS_SMCD_SHIFT                     (0U)                                                /*!< SCM_PPMRS.SMCD Position                 */
#define SCM_PPMRS_SMCD(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< SCM_PPMRS.SMCD Field                    */
#define SCM_PPMRS_SAMCD_MASK                     (0x40U)                                             /*!< SCM_PPMRS.SAMCD Mask                    */
#define SCM_PPMRS_SAMCD_SHIFT                    (6U)                                                /*!< SCM_PPMRS.SAMCD Position                */
#define SCM_PPMRS_SAMCD(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< SCM_PPMRS.SAMCD Field                   */
/* ------- PPMRC Bit Fields                         ------ */
#define SCM_PPMRC_SMCD_MASK                      (0x1FU)                                             /*!< SCM_PPMRC.SMCD Mask                     */
#define SCM_PPMRC_SMCD_SHIFT                     (0U)                                                /*!< SCM_PPMRC.SMCD Position                 */
#define SCM_PPMRC_SMCD(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< SCM_PPMRC.SMCD Field                    */
#define SCM_PPMRC_SAMCD_MASK                     (0x40U)                                             /*!< SCM_PPMRC.SAMCD Mask                    */
#define SCM_PPMRC_SAMCD_SHIFT                    (6U)                                                /*!< SCM_PPMRC.SAMCD Position                */
#define SCM_PPMRC_SAMCD(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< SCM_PPMRC.SAMCD Field                   */
/* ------- IPSBMT Bit Fields                        ------ */
#define SCM_IPSBMT_BMT_MASK                      (0x7U)                                              /*!< SCM_IPSBMT.BMT Mask                     */
#define SCM_IPSBMT_BMT_SHIFT                     (0U)                                                /*!< SCM_IPSBMT.BMT Position                 */
#define SCM_IPSBMT_BMT(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< SCM_IPSBMT.BMT Field                    */
#define SCM_IPSBMT_BME_MASK                      (0x10U)                                             /*!< SCM_IPSBMT.BME Mask                     */
#define SCM_IPSBMT_BME_SHIFT                     (4U)                                                /*!< SCM_IPSBMT.BME Position                 */
#define SCM_IPSBMT_BME(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< SCM_IPSBMT.BME Field                    */
/* ------- PACR Bit Fields                          ------ */
#define SCM_PACR_ACCESS_CTRL0_MASK               (0x7U)                                              /*!< SCM_PACR.ACCESS_CTRL0 Mask              */
#define SCM_PACR_ACCESS_CTRL0_SHIFT              (0U)                                                /*!< SCM_PACR.ACCESS_CTRL0 Position          */
#define SCM_PACR_ACCESS_CTRL0(x)                 (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< SCM_PACR.ACCESS_CTRL0 Field             */
#define SCM_PACR_LOCK0_MASK                      (0x8U)                                              /*!< SCM_PACR.LOCK0 Mask                     */
#define SCM_PACR_LOCK0_SHIFT                     (3U)                                                /*!< SCM_PACR.LOCK0 Position                 */
#define SCM_PACR_LOCK0(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< SCM_PACR.LOCK0 Field                    */
#define SCM_PACR_ACCESS_CTRL1_MASK               (0x70U)                                             /*!< SCM_PACR.ACCESS_CTRL1 Mask              */
#define SCM_PACR_ACCESS_CTRL1_SHIFT              (4U)                                                /*!< SCM_PACR.ACCESS_CTRL1 Position          */
#define SCM_PACR_ACCESS_CTRL1(x)                 (((uint8_t)(((uint8_t)(x))<<4U))&0x70UL)            /*!< SCM_PACR.ACCESS_CTRL1 Field             */
#define SCM_PACR_LOCK1_MASK                      (0x80U)                                             /*!< SCM_PACR.LOCK1 Mask                     */
#define SCM_PACR_LOCK1_SHIFT                     (7U)                                                /*!< SCM_PACR.LOCK1 Position                 */
#define SCM_PACR_LOCK1(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< SCM_PACR.LOCK1 Field                    */
/* ------- GPACR Bit Fields                         ------ */
#define SCM_GPACR_ACCESS_CTRL_MASK               (0xFU)                                              /*!< SCM_GPACR.ACCESS_CTRL Mask              */
#define SCM_GPACR_ACCESS_CTRL_SHIFT              (0U)                                                /*!< SCM_GPACR.ACCESS_CTRL Position          */
#define SCM_GPACR_ACCESS_CTRL(x)                 (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< SCM_GPACR.ACCESS_CTRL Field             */
#define SCM_GPACR_LOCK_MASK                      (0x80U)                                             /*!< SCM_GPACR.LOCK Mask                     */
#define SCM_GPACR_LOCK_SHIFT                     (7U)                                                /*!< SCM_GPACR.LOCK Position                 */
#define SCM_GPACR_LOCK(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< SCM_GPACR.LOCK Field                    */
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
typedef struct UART_Type {
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
#define UART_UMR1_BC_MASK                        (0x3U)                                              /*!< UART0_UMR1.BC Mask                      */
#define UART_UMR1_BC_SHIFT                       (0U)                                                /*!< UART0_UMR1.BC Position                  */
#define UART_UMR1_BC(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< UART0_UMR1.BC Field                     */
#define UART_UMR1_PT_MASK                        (0x4U)                                              /*!< UART0_UMR1.PT Mask                      */
#define UART_UMR1_PT_SHIFT                       (2U)                                                /*!< UART0_UMR1.PT Position                  */
#define UART_UMR1_PT(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_UMR1.PT Field                     */
#define UART_UMR1_PM_MASK                        (0x18U)                                             /*!< UART0_UMR1.PM Mask                      */
#define UART_UMR1_PM_SHIFT                       (3U)                                                /*!< UART0_UMR1.PM Position                  */
#define UART_UMR1_PM(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x18UL)            /*!< UART0_UMR1.PM Field                     */
#define UART_UMR1_ERR_MASK                       (0x20U)                                             /*!< UART0_UMR1.ERR Mask                     */
#define UART_UMR1_ERR_SHIFT                      (5U)                                                /*!< UART0_UMR1.ERR Position                 */
#define UART_UMR1_ERR(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_UMR1.ERR Field                    */
#define UART_UMR1_RXIRQ_MASK                     (0x40U)                                             /*!< UART0_UMR1.RXIRQ Mask                   */
#define UART_UMR1_RXIRQ_SHIFT                    (6U)                                                /*!< UART0_UMR1.RXIRQ Position               */
#define UART_UMR1_RXIRQ(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_UMR1.RXIRQ Field                  */
#define UART_UMR1_RXRTS_MASK                     (0x80U)                                             /*!< UART0_UMR1.RXRTS Mask                   */
#define UART_UMR1_RXRTS_SHIFT                    (7U)                                                /*!< UART0_UMR1.RXRTS Position               */
#define UART_UMR1_RXRTS(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_UMR1.RXRTS Field                  */
/* ------- UMR2 Bit Fields                          ------ */
#define UART_UMR2_SB_MASK                        (0xFU)                                              /*!< UART0_UMR2.SB Mask                      */
#define UART_UMR2_SB_SHIFT                       (0U)                                                /*!< UART0_UMR2.SB Position                  */
#define UART_UMR2_SB(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< UART0_UMR2.SB Field                     */
#define UART_UMR2_TXCTS_MASK                     (0x10U)                                             /*!< UART0_UMR2.TXCTS Mask                   */
#define UART_UMR2_TXCTS_SHIFT                    (4U)                                                /*!< UART0_UMR2.TXCTS Position               */
#define UART_UMR2_TXCTS(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< UART0_UMR2.TXCTS Field                  */
#define UART_UMR2_TXRTS_MASK                     (0x20U)                                             /*!< UART0_UMR2.TXRTS Mask                   */
#define UART_UMR2_TXRTS_SHIFT                    (5U)                                                /*!< UART0_UMR2.TXRTS Position               */
#define UART_UMR2_TXRTS(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_UMR2.TXRTS Field                  */
#define UART_UMR2_CM_MASK                        (0xC0U)                                             /*!< UART0_UMR2.CM Mask                      */
#define UART_UMR2_CM_SHIFT                       (6U)                                                /*!< UART0_UMR2.CM Position                  */
#define UART_UMR2_CM(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< UART0_UMR2.CM Field                     */
/* ------- UCSR Bit Fields                          ------ */
#define UART_UCSR_TCS_MASK                       (0xFU)                                              /*!< UART0_UCSR.TCS Mask                     */
#define UART_UCSR_TCS_SHIFT                      (0U)                                                /*!< UART0_UCSR.TCS Position                 */
#define UART_UCSR_TCS(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< UART0_UCSR.TCS Field                    */
#define UART_UCSR_RCS_MASK                       (0xF0U)                                             /*!< UART0_UCSR.RCS Mask                     */
#define UART_UCSR_RCS_SHIFT                      (4U)                                                /*!< UART0_UCSR.RCS Position                 */
#define UART_UCSR_RCS(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0xF0UL)            /*!< UART0_UCSR.RCS Field                    */
/* ------- USR Bit Fields                           ------ */
#define UART_USR_RXRDY_MASK                      (0x1U)                                              /*!< UART0_USR.RXRDY Mask                    */
#define UART_USR_RXRDY_SHIFT                     (0U)                                                /*!< UART0_USR.RXRDY Position                */
#define UART_USR_RXRDY(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_USR.RXRDY Field                   */
#define UART_USR_FFULL_MASK                      (0x2U)                                              /*!< UART0_USR.FFULL Mask                    */
#define UART_USR_FFULL_SHIFT                     (1U)                                                /*!< UART0_USR.FFULL Position                */
#define UART_USR_FFULL(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_USR.FFULL Field                   */
#define UART_USR_TXRDY_MASK                      (0x4U)                                              /*!< UART0_USR.TXRDY Mask                    */
#define UART_USR_TXRDY_SHIFT                     (2U)                                                /*!< UART0_USR.TXRDY Position                */
#define UART_USR_TXRDY(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_USR.TXRDY Field                   */
#define UART_USR_TXEMP_MASK                      (0x8U)                                              /*!< UART0_USR.TXEMP Mask                    */
#define UART_USR_TXEMP_SHIFT                     (3U)                                                /*!< UART0_USR.TXEMP Position                */
#define UART_USR_TXEMP(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_USR.TXEMP Field                   */
#define UART_USR_OE_MASK                         (0x10U)                                             /*!< UART0_USR.OE Mask                       */
#define UART_USR_OE_SHIFT                        (4U)                                                /*!< UART0_USR.OE Position                   */
#define UART_USR_OE(x)                           (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< UART0_USR.OE Field                      */
#define UART_USR_PE_MASK                         (0x20U)                                             /*!< UART0_USR.PE Mask                       */
#define UART_USR_PE_SHIFT                        (5U)                                                /*!< UART0_USR.PE Position                   */
#define UART_USR_PE(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_USR.PE Field                      */
#define UART_USR_FE_MASK                         (0x40U)                                             /*!< UART0_USR.FE Mask                       */
#define UART_USR_FE_SHIFT                        (6U)                                                /*!< UART0_USR.FE Position                   */
#define UART_USR_FE(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_USR.FE Field                      */
#define UART_USR_RB_MASK                         (0x80U)                                             /*!< UART0_USR.RB Mask                       */
#define UART_USR_RB_SHIFT                        (7U)                                                /*!< UART0_USR.RB Position                   */
#define UART_USR_RB(x)                           (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_USR.RB Field                      */
/* ------- UCR Bit Fields                           ------ */
#define UART_UCR_RC_MASK                         (0x3U)                                              /*!< UART0_UCR.RC Mask                       */
#define UART_UCR_RC_SHIFT                        (0U)                                                /*!< UART0_UCR.RC Position                   */
#define UART_UCR_RC(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< UART0_UCR.RC Field                      */
#define UART_UCR_TC_MASK                         (0xCU)                                              /*!< UART0_UCR.TC Mask                       */
#define UART_UCR_TC_SHIFT                        (2U)                                                /*!< UART0_UCR.TC Position                   */
#define UART_UCR_TC(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< UART0_UCR.TC Field                      */
#define UART_UCR_MISC_MASK                       (0x70U)                                             /*!< UART0_UCR.MISC Mask                     */
#define UART_UCR_MISC_SHIFT                      (4U)                                                /*!< UART0_UCR.MISC Position                 */
#define UART_UCR_MISC(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x70UL)            /*!< UART0_UCR.MISC Field                    */
/* ------- URB Bit Fields                           ------ */
#define UART_URB_RB_MASK                         (0xFFU)                                             /*!< UART0_URB.RB Mask                       */
#define UART_URB_RB_SHIFT                        (0U)                                                /*!< UART0_URB.RB Position                   */
#define UART_URB_RB(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_URB.RB Field                      */
/* ------- UTB Bit Fields                           ------ */
#define UART_UTB_TB_MASK                         (0xFFU)                                             /*!< UART0_UTB.TB Mask                       */
#define UART_UTB_TB_SHIFT                        (0U)                                                /*!< UART0_UTB.TB Position                   */
#define UART_UTB_TB(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_UTB.TB Field                      */
/* ------- UACR Bit Fields                          ------ */
#define UART_UACR_IEC_MASK                       (0x1U)                                              /*!< UART0_UACR.IEC Mask                     */
#define UART_UACR_IEC_SHIFT                      (0U)                                                /*!< UART0_UACR.IEC Position                 */
#define UART_UACR_IEC(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_UACR.IEC Field                    */
/* ------- UIPCR Bit Fields                         ------ */
#define UART_UIPCR_CTS_MASK                      (0x1U)                                              /*!< UART0_UIPCR.CTS Mask                    */
#define UART_UIPCR_CTS_SHIFT                     (0U)                                                /*!< UART0_UIPCR.CTS Position                */
#define UART_UIPCR_CTS(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_UIPCR.CTS Field                   */
#define UART_UIPCR_COS_MASK                      (0x10U)                                             /*!< UART0_UIPCR.COS Mask                    */
#define UART_UIPCR_COS_SHIFT                     (4U)                                                /*!< UART0_UIPCR.COS Position                */
#define UART_UIPCR_COS(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< UART0_UIPCR.COS Field                   */
/* ------- UIMR Bit Fields                          ------ */
#define UART_UIMR_TXRDY_MASK                     (0x1U)                                              /*!< UART0_UIMR.TXRDY Mask                   */
#define UART_UIMR_TXRDY_SHIFT                    (0U)                                                /*!< UART0_UIMR.TXRDY Position               */
#define UART_UIMR_TXRDY(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_UIMR.TXRDY Field                  */
#define UART_UIMR_FFULL_RXRDY_MASK               (0x2U)                                              /*!< UART0_UIMR.FFULL_RXRDY Mask             */
#define UART_UIMR_FFULL_RXRDY_SHIFT              (1U)                                                /*!< UART0_UIMR.FFULL_RXRDY Position         */
#define UART_UIMR_FFULL_RXRDY(x)                 (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_UIMR.FFULL_RXRDY Field            */
#define UART_UIMR_DB_MASK                        (0x4U)                                              /*!< UART0_UIMR.DB Mask                      */
#define UART_UIMR_DB_SHIFT                       (2U)                                                /*!< UART0_UIMR.DB Position                  */
#define UART_UIMR_DB(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_UIMR.DB Field                     */
#define UART_UIMR_COS_MASK                       (0x80U)                                             /*!< UART0_UIMR.COS Mask                     */
#define UART_UIMR_COS_SHIFT                      (7U)                                                /*!< UART0_UIMR.COS Position                 */
#define UART_UIMR_COS(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_UIMR.COS Field                    */
/* ------- UISR Bit Fields                          ------ */
#define UART_UISR_TXRDY_MASK                     (0x1U)                                              /*!< UART0_UISR.TXRDY Mask                   */
#define UART_UISR_TXRDY_SHIFT                    (0U)                                                /*!< UART0_UISR.TXRDY Position               */
#define UART_UISR_TXRDY(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_UISR.TXRDY Field                  */
#define UART_UISR_FFULL_RXRDY_MASK               (0x2U)                                              /*!< UART0_UISR.FFULL_RXRDY Mask             */
#define UART_UISR_FFULL_RXRDY_SHIFT              (1U)                                                /*!< UART0_UISR.FFULL_RXRDY Position         */
#define UART_UISR_FFULL_RXRDY(x)                 (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_UISR.FFULL_RXRDY Field            */
#define UART_UISR_DB_MASK                        (0x4U)                                              /*!< UART0_UISR.DB Mask                      */
#define UART_UISR_DB_SHIFT                       (2U)                                                /*!< UART0_UISR.DB Position                  */
#define UART_UISR_DB(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_UISR.DB Field                     */
#define UART_UISR_COS_MASK                       (0x80U)                                             /*!< UART0_UISR.COS Mask                     */
#define UART_UISR_COS_SHIFT                      (7U)                                                /*!< UART0_UISR.COS Position                 */
#define UART_UISR_COS(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_UISR.COS Field                    */
/* ------- UBG1 Bit Fields                          ------ */
#define UART_UBG1_Divider_MSB_MASK               (0xFFU)                                             /*!< UART0_UBG1.Divider_MSB Mask             */
#define UART_UBG1_Divider_MSB_SHIFT              (0U)                                                /*!< UART0_UBG1.Divider_MSB Position         */
#define UART_UBG1_Divider_MSB(x)                 (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_UBG1.Divider_MSB Field            */
/* ------- UBG2 Bit Fields                          ------ */
#define UART_UBG2_Divider_LSB_MASK               (0xFFU)                                             /*!< UART0_UBG2.Divider_LSB Mask             */
#define UART_UBG2_Divider_LSB_SHIFT              (0U)                                                /*!< UART0_UBG2.Divider_LSB Position         */
#define UART_UBG2_Divider_LSB(x)                 (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_UBG2.Divider_LSB Field            */
/* ------- UIP Bit Fields                           ------ */
#define UART_UIP_CTS_MASK                        (0x1U)                                              /*!< UART0_UIP.CTS Mask                      */
#define UART_UIP_CTS_SHIFT                       (0U)                                                /*!< UART0_UIP.CTS Position                  */
#define UART_UIP_CTS(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_UIP.CTS Field                     */
/* ------- UOP1 Bit Fields                          ------ */
#define UART_UOP1_RTS_MASK                       (0x1U)                                              /*!< UART0_UOP1.RTS Mask                     */
#define UART_UOP1_RTS_SHIFT                      (0U)                                                /*!< UART0_UOP1.RTS Position                 */
#define UART_UOP1_RTS(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_UOP1.RTS Field                    */
/* ------- UOP0 Bit Fields                          ------ */
#define UART_UOP0_RTS_MASK                       (0x1U)                                              /*!< UART0_UOP0.RTS Mask                     */
#define UART_UOP0_RTS_SHIFT                      (0U)                                                /*!< UART0_UOP0.RTS Position                 */
#define UART_UOP0_RTS(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_UOP0.RTS Field                    */
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
/**
* @addtogroup USB_Peripheral_access_layer_GROUP USB Peripheral Access Layer
* @brief C Struct for USB
* @{
*/

/* ================================================================================ */
/* ================           USB0 (file:MCF52259_USB_OTG)         ================ */
/* ================================================================================ */

/**
 * @brief Universal Serial Bus, OTG Capable Controller
 */
/**
* @addtogroup USB_structs_GROUP USB struct
* @brief Struct for USB
* @{
*/
typedef struct USB_Type {
   __I  uint8_t   PERID;                        /**< 0000: Peripheral ID Register                                       */
        uint8_t   RESERVED_0[3];               
   __I  uint8_t   IDCOMP;                       /**< 0004: Peripheral ID Complement Register                            */
        uint8_t   RESERVED_1[3];               
   __I  uint8_t   REV;                          /**< 0008: Peripheral Revision Register                                 */
        uint8_t   RESERVED_2[3];               
   __I  uint8_t   ADDINFO;                      /**< 000C: Peripheral Additional Info Register                          */
        uint8_t   RESERVED_3[3];               
   __IO uint8_t   OTGISTAT;                     /**< 0010: OTG Interrupt Status Register                                */
        uint8_t   RESERVED_4[3];               
   __IO uint8_t   OTGICR;                       /**< 0014: OTG Interrupt Control Register                               */
        uint8_t   RESERVED_5[3];               
   __IO uint8_t   OTGSTAT;                      /**< 0018: OTG Status Register                                          */
        uint8_t   RESERVED_6[3];               
   __IO uint8_t   OTGCTL;                       /**< 001C: OTG Control Register                                         */
        uint8_t   RESERVED_7[99];              
   __IO uint8_t   ISTAT;                        /**< 0080: Interrupt Status Register                                    */
        uint8_t   RESERVED_8[3];               
   __IO uint8_t   INTEN;                        /**< 0084: Interrupt Enable Register                                    */
        uint8_t   RESERVED_9[3];               
   __IO uint8_t   ERRSTAT;                      /**< 0088: Error Interrupt Status Register                              */
        uint8_t   RESERVED_10[3];              
   __IO uint8_t   ERREN;                        /**< 008C: Error Interrupt Enable Register                              */
        uint8_t   RESERVED_11[3];              
   __I  uint8_t   STAT;                         /**< 0090: Status Register                                              */
        uint8_t   RESERVED_12[3];              
   __IO uint8_t   CTL;                          /**< 0094: Control register                                             */
        uint8_t   RESERVED_13[3];              
   __IO uint8_t   ADDR;                         /**< 0098: Address Register                                             */
        uint8_t   RESERVED_14[3];              
   __IO uint8_t   BDTPAGE1;                     /**< 009C: BDT Page Register 1                                          */
        uint8_t   RESERVED_15[3];              
   __IO uint8_t   FRMNUML;                      /**< 00A0: Frame Number Register Low                                    */
        uint8_t   RESERVED_16[3];              
   __IO uint8_t   FRMNUMH;                      /**< 00A4: Frame Number Register High                                   */
        uint8_t   RESERVED_17[3];              
   __IO uint8_t   TOKEN;                        /**< 00A8: Token Register                                               */
        uint8_t   RESERVED_18[3];              
   __IO uint8_t   SOFTHLD;                      /**< 00AC: SOF Threshold Register                                       */
        uint8_t   RESERVED_19[3];              
   __IO uint8_t   BDTPAGE2;                     /**< 00B0: BDT Page Register 2                                          */
        uint8_t   RESERVED_20[3];              
   __IO uint8_t   BDTPAGE3;                     /**< 00B4: BDT Page Register 3                                          */
        uint8_t   RESERVED_21[11];             
   struct {
      __IO uint8_t   ENDPT;                     /**< 00C0: Endpoint Control Register                                    */
           uint8_t   RESERVED_22[3];           
   } ENDPOINT[16];                              /**< 00C0: (cluster: size=0x0040, 64)                                   */
   __IO uint8_t   USBCTRL;                      /**< 0100: USB Control Register                                         */
        uint8_t   RESERVED_23[3];              
   __I  uint8_t   OBSERVE;                      /**< 0104: USB OTG Observe Register                                     */
        uint8_t   RESERVED_24[3];              
   __IO uint8_t   CONTROL;                      /**< 0108: USB OTG Control Register                                     */
} USB_Type;

/**
 * @} */ /* End group USB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'USB0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup USB_Register_Masks_GROUP USB Register Masks
* @brief Register Masks for USB
* @{
*/
/* ------- PERID Bit Fields                         ------ */
#define USB_PERID_ID_MASK                        (0x3FU)                                             /*!< USB0_PERID.ID Mask                      */
#define USB_PERID_ID_SHIFT                       (0U)                                                /*!< USB0_PERID.ID Position                  */
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< USB0_PERID.ID Field                     */
/* ------- IDCOMP Bit Fields                        ------ */
#define USB_IDCOMP_NID_MASK                      (0x3FU)                                             /*!< USB0_IDCOMP.NID Mask                    */
#define USB_IDCOMP_NID_SHIFT                     (0U)                                                /*!< USB0_IDCOMP.NID Position                */
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< USB0_IDCOMP.NID Field                   */
/* ------- REV Bit Fields                           ------ */
#define USB_REV_REV_MASK                         (0xFFU)                                             /*!< USB0_REV.REV Mask                       */
#define USB_REV_REV_SHIFT                        (0U)                                                /*!< USB0_REV.REV Position                   */
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_REV.REV Field                      */
/* ------- ADDINFO Bit Fields                       ------ */
#define USB_ADDINFO_IEHOST_MASK                  (0x1U)                                              /*!< USB0_ADDINFO.IEHOST Mask                */
#define USB_ADDINFO_IEHOST_SHIFT                 (0U)                                                /*!< USB0_ADDINFO.IEHOST Position            */
#define USB_ADDINFO_IEHOST(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ADDINFO.IEHOST Field               */
#define USB_ADDINFO_IRQNUM_MASK                  (0xF8U)                                             /*!< USB0_ADDINFO.IRQNUM Mask                */
#define USB_ADDINFO_IRQNUM_SHIFT                 (3U)                                                /*!< USB0_ADDINFO.IRQNUM Position            */
#define USB_ADDINFO_IRQNUM(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0xF8UL)            /*!< USB0_ADDINFO.IRQNUM Field               */
/* ------- OTGISTAT Bit Fields                      ------ */
#define USB_OTGISTAT_AVBUSCHG_MASK               (0x1U)                                              /*!< USB0_OTGISTAT.AVBUSCHG Mask             */
#define USB_OTGISTAT_AVBUSCHG_SHIFT              (0U)                                                /*!< USB0_OTGISTAT.AVBUSCHG Position         */
#define USB_OTGISTAT_AVBUSCHG(x)                 (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_OTGISTAT.AVBUSCHG Field            */
#define USB_OTGISTAT_B_SESS_CHG_MASK             (0x4U)                                              /*!< USB0_OTGISTAT.B_SESS_CHG Mask           */
#define USB_OTGISTAT_B_SESS_CHG_SHIFT            (2U)                                                /*!< USB0_OTGISTAT.B_SESS_CHG Position       */
#define USB_OTGISTAT_B_SESS_CHG(x)               (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_OTGISTAT.B_SESS_CHG Field          */
#define USB_OTGISTAT_SESSVLDCHG_MASK             (0x8U)                                              /*!< USB0_OTGISTAT.SESSVLDCHG Mask           */
#define USB_OTGISTAT_SESSVLDCHG_SHIFT            (3U)                                                /*!< USB0_OTGISTAT.SESSVLDCHG Position       */
#define USB_OTGISTAT_SESSVLDCHG(x)               (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_OTGISTAT.SESSVLDCHG Field          */
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         (0x20U)                                             /*!< USB0_OTGISTAT.LINE_STATE_CHG Mask       */
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        (5U)                                                /*!< USB0_OTGISTAT.LINE_STATE_CHG Position   */
#define USB_OTGISTAT_LINE_STATE_CHG(x)           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_OTGISTAT.LINE_STATE_CHG Field      */
#define USB_OTGISTAT_ONEMSEC_MASK                (0x40U)                                             /*!< USB0_OTGISTAT.ONEMSEC Mask              */
#define USB_OTGISTAT_ONEMSEC_SHIFT               (6U)                                                /*!< USB0_OTGISTAT.ONEMSEC Position          */
#define USB_OTGISTAT_ONEMSEC(x)                  (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_OTGISTAT.ONEMSEC Field             */
#define USB_OTGISTAT_IDCHG_MASK                  (0x80U)                                             /*!< USB0_OTGISTAT.IDCHG Mask                */
#define USB_OTGISTAT_IDCHG_SHIFT                 (7U)                                                /*!< USB0_OTGISTAT.IDCHG Position            */
#define USB_OTGISTAT_IDCHG(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_OTGISTAT.IDCHG Field               */
/* ------- OTGICR Bit Fields                        ------ */
#define USB_OTGICR_AVBUSEN_MASK                  (0x1U)                                              /*!< USB0_OTGICR.AVBUSEN Mask                */
#define USB_OTGICR_AVBUSEN_SHIFT                 (0U)                                                /*!< USB0_OTGICR.AVBUSEN Position            */
#define USB_OTGICR_AVBUSEN(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_OTGICR.AVBUSEN Field               */
#define USB_OTGICR_BSESSEN_MASK                  (0x4U)                                              /*!< USB0_OTGICR.BSESSEN Mask                */
#define USB_OTGICR_BSESSEN_SHIFT                 (2U)                                                /*!< USB0_OTGICR.BSESSEN Position            */
#define USB_OTGICR_BSESSEN(x)                    (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_OTGICR.BSESSEN Field               */
#define USB_OTGICR_SESSVLDEN_MASK                (0x8U)                                              /*!< USB0_OTGICR.SESSVLDEN Mask              */
#define USB_OTGICR_SESSVLDEN_SHIFT               (3U)                                                /*!< USB0_OTGICR.SESSVLDEN Position          */
#define USB_OTGICR_SESSVLDEN(x)                  (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_OTGICR.SESSVLDEN Field             */
#define USB_OTGICR_LINESTATEEN_MASK              (0x20U)                                             /*!< USB0_OTGICR.LINESTATEEN Mask            */
#define USB_OTGICR_LINESTATEEN_SHIFT             (5U)                                                /*!< USB0_OTGICR.LINESTATEEN Position        */
#define USB_OTGICR_LINESTATEEN(x)                (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_OTGICR.LINESTATEEN Field           */
#define USB_OTGICR_ONEMSECEN_MASK                (0x40U)                                             /*!< USB0_OTGICR.ONEMSECEN Mask              */
#define USB_OTGICR_ONEMSECEN_SHIFT               (6U)                                                /*!< USB0_OTGICR.ONEMSECEN Position          */
#define USB_OTGICR_ONEMSECEN(x)                  (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_OTGICR.ONEMSECEN Field             */
#define USB_OTGICR_IDEN_MASK                     (0x80U)                                             /*!< USB0_OTGICR.IDEN Mask                   */
#define USB_OTGICR_IDEN_SHIFT                    (7U)                                                /*!< USB0_OTGICR.IDEN Position               */
#define USB_OTGICR_IDEN(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_OTGICR.IDEN Field                  */
/* ------- OTGSTAT Bit Fields                       ------ */
#define USB_OTGSTAT_AVBUSVLD_MASK                (0x1U)                                              /*!< USB0_OTGSTAT.AVBUSVLD Mask              */
#define USB_OTGSTAT_AVBUSVLD_SHIFT               (0U)                                                /*!< USB0_OTGSTAT.AVBUSVLD Position          */
#define USB_OTGSTAT_AVBUSVLD(x)                  (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_OTGSTAT.AVBUSVLD Field             */
#define USB_OTGSTAT_BSESSEND_MASK                (0x4U)                                              /*!< USB0_OTGSTAT.BSESSEND Mask              */
#define USB_OTGSTAT_BSESSEND_SHIFT               (2U)                                                /*!< USB0_OTGSTAT.BSESSEND Position          */
#define USB_OTGSTAT_BSESSEND(x)                  (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_OTGSTAT.BSESSEND Field             */
#define USB_OTGSTAT_SESS_VLD_MASK                (0x8U)                                              /*!< USB0_OTGSTAT.SESS_VLD Mask              */
#define USB_OTGSTAT_SESS_VLD_SHIFT               (3U)                                                /*!< USB0_OTGSTAT.SESS_VLD Position          */
#define USB_OTGSTAT_SESS_VLD(x)                  (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_OTGSTAT.SESS_VLD Field             */
#define USB_OTGSTAT_LINESTATESTABLE_MASK         (0x20U)                                             /*!< USB0_OTGSTAT.LINESTATESTABLE Mask       */
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        (5U)                                                /*!< USB0_OTGSTAT.LINESTATESTABLE Position   */
#define USB_OTGSTAT_LINESTATESTABLE(x)           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_OTGSTAT.LINESTATESTABLE Field      */
#define USB_OTGSTAT_ONEMSECEN_MASK               (0x40U)                                             /*!< USB0_OTGSTAT.ONEMSECEN Mask             */
#define USB_OTGSTAT_ONEMSECEN_SHIFT              (6U)                                                /*!< USB0_OTGSTAT.ONEMSECEN Position         */
#define USB_OTGSTAT_ONEMSECEN(x)                 (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_OTGSTAT.ONEMSECEN Field            */
#define USB_OTGSTAT_ID_MASK                      (0x80U)                                             /*!< USB0_OTGSTAT.ID Mask                    */
#define USB_OTGSTAT_ID_SHIFT                     (7U)                                                /*!< USB0_OTGSTAT.ID Position                */
#define USB_OTGSTAT_ID(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_OTGSTAT.ID Field                   */
/* ------- OTGCTL Bit Fields                        ------ */
#define USB_OTGCTL_OTGEN_MASK                    (0x4U)                                              /*!< USB0_OTGCTL.OTGEN Mask                  */
#define USB_OTGCTL_OTGEN_SHIFT                   (2U)                                                /*!< USB0_OTGCTL.OTGEN Position              */
#define USB_OTGCTL_OTGEN(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_OTGCTL.OTGEN Field                 */
#define USB_OTGCTL_DMLOW_MASK                    (0x10U)                                             /*!< USB0_OTGCTL.DMLOW Mask                  */
#define USB_OTGCTL_DMLOW_SHIFT                   (4U)                                                /*!< USB0_OTGCTL.DMLOW Position              */
#define USB_OTGCTL_DMLOW(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_OTGCTL.DMLOW Field                 */
#define USB_OTGCTL_DPLOW_MASK                    (0x20U)                                             /*!< USB0_OTGCTL.DPLOW Mask                  */
#define USB_OTGCTL_DPLOW_SHIFT                   (5U)                                                /*!< USB0_OTGCTL.DPLOW Position              */
#define USB_OTGCTL_DPLOW(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_OTGCTL.DPLOW Field                 */
#define USB_OTGCTL_DPHIGH_MASK                   (0x80U)                                             /*!< USB0_OTGCTL.DPHIGH Mask                 */
#define USB_OTGCTL_DPHIGH_SHIFT                  (7U)                                                /*!< USB0_OTGCTL.DPHIGH Position             */
#define USB_OTGCTL_DPHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_OTGCTL.DPHIGH Field                */
/* ------- ISTAT Bit Fields                         ------ */
#define USB_ISTAT_USBRST_MASK                    (0x1U)                                              /*!< USB0_ISTAT.USBRST Mask                  */
#define USB_ISTAT_USBRST_SHIFT                   (0U)                                                /*!< USB0_ISTAT.USBRST Position              */
#define USB_ISTAT_USBRST(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ISTAT.USBRST Field                 */
#define USB_ISTAT_ERROR_MASK                     (0x2U)                                              /*!< USB0_ISTAT.ERROR Mask                   */
#define USB_ISTAT_ERROR_SHIFT                    (1U)                                                /*!< USB0_ISTAT.ERROR Position               */
#define USB_ISTAT_ERROR(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_ISTAT.ERROR Field                  */
#define USB_ISTAT_SOFTOK_MASK                    (0x4U)                                              /*!< USB0_ISTAT.SOFTOK Mask                  */
#define USB_ISTAT_SOFTOK_SHIFT                   (2U)                                                /*!< USB0_ISTAT.SOFTOK Position              */
#define USB_ISTAT_SOFTOK(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_ISTAT.SOFTOK Field                 */
#define USB_ISTAT_TOKDNE_MASK                    (0x8U)                                              /*!< USB0_ISTAT.TOKDNE Mask                  */
#define USB_ISTAT_TOKDNE_SHIFT                   (3U)                                                /*!< USB0_ISTAT.TOKDNE Position              */
#define USB_ISTAT_TOKDNE(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_ISTAT.TOKDNE Field                 */
#define USB_ISTAT_SLEEP_MASK                     (0x10U)                                             /*!< USB0_ISTAT.SLEEP Mask                   */
#define USB_ISTAT_SLEEP_SHIFT                    (4U)                                                /*!< USB0_ISTAT.SLEEP Position               */
#define USB_ISTAT_SLEEP(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_ISTAT.SLEEP Field                  */
#define USB_ISTAT_RESUME_MASK                    (0x20U)                                             /*!< USB0_ISTAT.RESUME Mask                  */
#define USB_ISTAT_RESUME_SHIFT                   (5U)                                                /*!< USB0_ISTAT.RESUME Position              */
#define USB_ISTAT_RESUME(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_ISTAT.RESUME Field                 */
#define USB_ISTAT_ATTACH_MASK                    (0x40U)                                             /*!< USB0_ISTAT.ATTACH Mask                  */
#define USB_ISTAT_ATTACH_SHIFT                   (6U)                                                /*!< USB0_ISTAT.ATTACH Position              */
#define USB_ISTAT_ATTACH(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_ISTAT.ATTACH Field                 */
#define USB_ISTAT_STALL_MASK                     (0x80U)                                             /*!< USB0_ISTAT.STALL Mask                   */
#define USB_ISTAT_STALL_SHIFT                    (7U)                                                /*!< USB0_ISTAT.STALL Position               */
#define USB_ISTAT_STALL(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ISTAT.STALL Field                  */
/* ------- INTEN Bit Fields                         ------ */
#define USB_INTEN_USBRSTEN_MASK                  (0x1U)                                              /*!< USB0_INTEN.USBRSTEN Mask                */
#define USB_INTEN_USBRSTEN_SHIFT                 (0U)                                                /*!< USB0_INTEN.USBRSTEN Position            */
#define USB_INTEN_USBRSTEN(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_INTEN.USBRSTEN Field               */
#define USB_INTEN_ERROREN_MASK                   (0x2U)                                              /*!< USB0_INTEN.ERROREN Mask                 */
#define USB_INTEN_ERROREN_SHIFT                  (1U)                                                /*!< USB0_INTEN.ERROREN Position             */
#define USB_INTEN_ERROREN(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_INTEN.ERROREN Field                */
#define USB_INTEN_SOFTOKEN_MASK                  (0x4U)                                              /*!< USB0_INTEN.SOFTOKEN Mask                */
#define USB_INTEN_SOFTOKEN_SHIFT                 (2U)                                                /*!< USB0_INTEN.SOFTOKEN Position            */
#define USB_INTEN_SOFTOKEN(x)                    (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_INTEN.SOFTOKEN Field               */
#define USB_INTEN_TOKDNEEN_MASK                  (0x8U)                                              /*!< USB0_INTEN.TOKDNEEN Mask                */
#define USB_INTEN_TOKDNEEN_SHIFT                 (3U)                                                /*!< USB0_INTEN.TOKDNEEN Position            */
#define USB_INTEN_TOKDNEEN(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_INTEN.TOKDNEEN Field               */
#define USB_INTEN_SLEEPEN_MASK                   (0x10U)                                             /*!< USB0_INTEN.SLEEPEN Mask                 */
#define USB_INTEN_SLEEPEN_SHIFT                  (4U)                                                /*!< USB0_INTEN.SLEEPEN Position             */
#define USB_INTEN_SLEEPEN(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_INTEN.SLEEPEN Field                */
#define USB_INTEN_RESUMEEN_MASK                  (0x20U)                                             /*!< USB0_INTEN.RESUMEEN Mask                */
#define USB_INTEN_RESUMEEN_SHIFT                 (5U)                                                /*!< USB0_INTEN.RESUMEEN Position            */
#define USB_INTEN_RESUMEEN(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_INTEN.RESUMEEN Field               */
#define USB_INTEN_ATTACHEN_MASK                  (0x40U)                                             /*!< USB0_INTEN.ATTACHEN Mask                */
#define USB_INTEN_ATTACHEN_SHIFT                 (6U)                                                /*!< USB0_INTEN.ATTACHEN Position            */
#define USB_INTEN_ATTACHEN(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_INTEN.ATTACHEN Field               */
#define USB_INTEN_STALLEN_MASK                   (0x80U)                                             /*!< USB0_INTEN.STALLEN Mask                 */
#define USB_INTEN_STALLEN_SHIFT                  (7U)                                                /*!< USB0_INTEN.STALLEN Position             */
#define USB_INTEN_STALLEN(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_INTEN.STALLEN Field                */
/* ------- ERRSTAT Bit Fields                       ------ */
#define USB_ERRSTAT_PIDERR_MASK                  (0x1U)                                              /*!< USB0_ERRSTAT.PIDERR Mask                */
#define USB_ERRSTAT_PIDERR_SHIFT                 (0U)                                                /*!< USB0_ERRSTAT.PIDERR Position            */
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ERRSTAT.PIDERR Field               */
#define USB_ERRSTAT_CRC5EOF_MASK                 (0x2U)                                              /*!< USB0_ERRSTAT.CRC5EOF Mask               */
#define USB_ERRSTAT_CRC5EOF_SHIFT                (1U)                                                /*!< USB0_ERRSTAT.CRC5EOF Position           */
#define USB_ERRSTAT_CRC5EOF(x)                   (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_ERRSTAT.CRC5EOF Field              */
#define USB_ERRSTAT_CRC16_MASK                   (0x4U)                                              /*!< USB0_ERRSTAT.CRC16 Mask                 */
#define USB_ERRSTAT_CRC16_SHIFT                  (2U)                                                /*!< USB0_ERRSTAT.CRC16 Position             */
#define USB_ERRSTAT_CRC16(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_ERRSTAT.CRC16 Field                */
#define USB_ERRSTAT_DFN8_MASK                    (0x8U)                                              /*!< USB0_ERRSTAT.DFN8 Mask                  */
#define USB_ERRSTAT_DFN8_SHIFT                   (3U)                                                /*!< USB0_ERRSTAT.DFN8 Position              */
#define USB_ERRSTAT_DFN8(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_ERRSTAT.DFN8 Field                 */
#define USB_ERRSTAT_BTOERR_MASK                  (0x10U)                                             /*!< USB0_ERRSTAT.BTOERR Mask                */
#define USB_ERRSTAT_BTOERR_SHIFT                 (4U)                                                /*!< USB0_ERRSTAT.BTOERR Position            */
#define USB_ERRSTAT_BTOERR(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_ERRSTAT.BTOERR Field               */
#define USB_ERRSTAT_DMAERR_MASK                  (0x20U)                                             /*!< USB0_ERRSTAT.DMAERR Mask                */
#define USB_ERRSTAT_DMAERR_SHIFT                 (5U)                                                /*!< USB0_ERRSTAT.DMAERR Position            */
#define USB_ERRSTAT_DMAERR(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_ERRSTAT.DMAERR Field               */
#define USB_ERRSTAT_BTSERR_MASK                  (0x80U)                                             /*!< USB0_ERRSTAT.BTSERR Mask                */
#define USB_ERRSTAT_BTSERR_SHIFT                 (7U)                                                /*!< USB0_ERRSTAT.BTSERR Position            */
#define USB_ERRSTAT_BTSERR(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ERRSTAT.BTSERR Field               */
/* ------- ERREN Bit Fields                         ------ */
#define USB_ERREN_PIDERREN_MASK                  (0x1U)                                              /*!< USB0_ERREN.PIDERREN Mask                */
#define USB_ERREN_PIDERREN_SHIFT                 (0U)                                                /*!< USB0_ERREN.PIDERREN Position            */
#define USB_ERREN_PIDERREN(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ERREN.PIDERREN Field               */
#define USB_ERREN_CRC5EOFEN_MASK                 (0x2U)                                              /*!< USB0_ERREN.CRC5EOFEN Mask               */
#define USB_ERREN_CRC5EOFEN_SHIFT                (1U)                                                /*!< USB0_ERREN.CRC5EOFEN Position           */
#define USB_ERREN_CRC5EOFEN(x)                   (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_ERREN.CRC5EOFEN Field              */
#define USB_ERREN_CRC16EN_MASK                   (0x4U)                                              /*!< USB0_ERREN.CRC16EN Mask                 */
#define USB_ERREN_CRC16EN_SHIFT                  (2U)                                                /*!< USB0_ERREN.CRC16EN Position             */
#define USB_ERREN_CRC16EN(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_ERREN.CRC16EN Field                */
#define USB_ERREN_DFN8EN_MASK                    (0x8U)                                              /*!< USB0_ERREN.DFN8EN Mask                  */
#define USB_ERREN_DFN8EN_SHIFT                   (3U)                                                /*!< USB0_ERREN.DFN8EN Position              */
#define USB_ERREN_DFN8EN(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_ERREN.DFN8EN Field                 */
#define USB_ERREN_BTOERREN_MASK                  (0x10U)                                             /*!< USB0_ERREN.BTOERREN Mask                */
#define USB_ERREN_BTOERREN_SHIFT                 (4U)                                                /*!< USB0_ERREN.BTOERREN Position            */
#define USB_ERREN_BTOERREN(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_ERREN.BTOERREN Field               */
#define USB_ERREN_DMAERREN_MASK                  (0x20U)                                             /*!< USB0_ERREN.DMAERREN Mask                */
#define USB_ERREN_DMAERREN_SHIFT                 (5U)                                                /*!< USB0_ERREN.DMAERREN Position            */
#define USB_ERREN_DMAERREN(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_ERREN.DMAERREN Field               */
#define USB_ERREN_BTSERREN_MASK                  (0x80U)                                             /*!< USB0_ERREN.BTSERREN Mask                */
#define USB_ERREN_BTSERREN_SHIFT                 (7U)                                                /*!< USB0_ERREN.BTSERREN Position            */
#define USB_ERREN_BTSERREN(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ERREN.BTSERREN Field               */
/* ------- STAT Bit Fields                          ------ */
#define USB_STAT_ODD_MASK                        (0x4U)                                              /*!< USB0_STAT.ODD Mask                      */
#define USB_STAT_ODD_SHIFT                       (2U)                                                /*!< USB0_STAT.ODD Position                  */
#define USB_STAT_ODD(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_STAT.ODD Field                     */
#define USB_STAT_TX_MASK                         (0x8U)                                              /*!< USB0_STAT.TX Mask                       */
#define USB_STAT_TX_SHIFT                        (3U)                                                /*!< USB0_STAT.TX Position                   */
#define USB_STAT_TX(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_STAT.TX Field                      */
#define USB_STAT_ENDP_MASK                       (0xF0U)                                             /*!< USB0_STAT.ENDP Mask                     */
#define USB_STAT_ENDP_SHIFT                      (4U)                                                /*!< USB0_STAT.ENDP Position                 */
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0xF0UL)            /*!< USB0_STAT.ENDP Field                    */
/* ------- CTL Bit Fields                           ------ */
#define USB_CTL_USBENSOFEN_MASK                  (0x1U)                                              /*!< USB0_CTL.USBENSOFEN Mask                */
#define USB_CTL_USBENSOFEN_SHIFT                 (0U)                                                /*!< USB0_CTL.USBENSOFEN Position            */
#define USB_CTL_USBENSOFEN(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_CTL.USBENSOFEN Field               */
#define USB_CTL_ODDRST_MASK                      (0x2U)                                              /*!< USB0_CTL.ODDRST Mask                    */
#define USB_CTL_ODDRST_SHIFT                     (1U)                                                /*!< USB0_CTL.ODDRST Position                */
#define USB_CTL_ODDRST(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_CTL.ODDRST Field                   */
#define USB_CTL_RESUME_MASK                      (0x4U)                                              /*!< USB0_CTL.RESUME Mask                    */
#define USB_CTL_RESUME_SHIFT                     (2U)                                                /*!< USB0_CTL.RESUME Position                */
#define USB_CTL_RESUME(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_CTL.RESUME Field                   */
#define USB_CTL_HOSTMODEEN_MASK                  (0x8U)                                              /*!< USB0_CTL.HOSTMODEEN Mask                */
#define USB_CTL_HOSTMODEEN_SHIFT                 (3U)                                                /*!< USB0_CTL.HOSTMODEEN Position            */
#define USB_CTL_HOSTMODEEN(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_CTL.HOSTMODEEN Field               */
#define USB_CTL_RESET_MASK                       (0x10U)                                             /*!< USB0_CTL.RESET Mask                     */
#define USB_CTL_RESET_SHIFT                      (4U)                                                /*!< USB0_CTL.RESET Position                 */
#define USB_CTL_RESET(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_CTL.RESET Field                    */
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          (0x20U)                                             /*!< USB0_CTL.TXSUSPENDTOKENBUSY Mask        */
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         (5U)                                                /*!< USB0_CTL.TXSUSPENDTOKENBUSY Position    */
#define USB_CTL_TXSUSPENDTOKENBUSY(x)            (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_CTL.TXSUSPENDTOKENBUSY Field       */
#define USB_CTL_SE0_MASK                         (0x40U)                                             /*!< USB0_CTL.SE0 Mask                       */
#define USB_CTL_SE0_SHIFT                        (6U)                                                /*!< USB0_CTL.SE0 Position                   */
#define USB_CTL_SE0(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_CTL.SE0 Field                      */
#define USB_CTL_JSTATE_MASK                      (0x80U)                                             /*!< USB0_CTL.JSTATE Mask                    */
#define USB_CTL_JSTATE_SHIFT                     (7U)                                                /*!< USB0_CTL.JSTATE Position                */
#define USB_CTL_JSTATE(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_CTL.JSTATE Field                   */
/* ------- ADDR Bit Fields                          ------ */
#define USB_ADDR_ADDR_MASK                       (0x7FU)                                             /*!< USB0_ADDR.ADDR Mask                     */
#define USB_ADDR_ADDR_SHIFT                      (0U)                                                /*!< USB0_ADDR.ADDR Position                 */
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7FUL)            /*!< USB0_ADDR.ADDR Field                    */
#define USB_ADDR_LSEN_MASK                       (0x80U)                                             /*!< USB0_ADDR.LSEN Mask                     */
#define USB_ADDR_LSEN_SHIFT                      (7U)                                                /*!< USB0_ADDR.LSEN Position                 */
#define USB_ADDR_LSEN(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ADDR.LSEN Field                    */
/* ------- BDTPAGE1 Bit Fields                      ------ */
#define USB_BDTPAGE1_BDTBA_MASK                  (0xFEU)                                             /*!< USB0_BDTPAGE1.BDTBA Mask                */
#define USB_BDTPAGE1_BDTBA_SHIFT                 (1U)                                                /*!< USB0_BDTPAGE1.BDTBA Position            */
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< USB0_BDTPAGE1.BDTBA Field               */
/* ------- FRMNUML Bit Fields                       ------ */
#define USB_FRMNUML_FRM_MASK                     (0xFFU)                                             /*!< USB0_FRMNUML.FRM Mask                   */
#define USB_FRMNUML_FRM_SHIFT                    (0U)                                                /*!< USB0_FRMNUML.FRM Position               */
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_FRMNUML.FRM Field                  */
/* ------- FRMNUMH Bit Fields                       ------ */
#define USB_FRMNUMH_FRM_MASK                     (0x7U)                                              /*!< USB0_FRMNUMH.FRM Mask                   */
#define USB_FRMNUMH_FRM_SHIFT                    (0U)                                                /*!< USB0_FRMNUMH.FRM Position               */
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< USB0_FRMNUMH.FRM Field                  */
/* ------- TOKEN Bit Fields                         ------ */
#define USB_TOKEN_TOKENENDPT_MASK                (0xFU)                                              /*!< USB0_TOKEN.TOKENENDPT Mask              */
#define USB_TOKEN_TOKENENDPT_SHIFT               (0U)                                                /*!< USB0_TOKEN.TOKENENDPT Position          */
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< USB0_TOKEN.TOKENENDPT Field             */
#define USB_TOKEN_TOKENPID_MASK                  (0xF0U)                                             /*!< USB0_TOKEN.TOKENPID Mask                */
#define USB_TOKEN_TOKENPID_SHIFT                 (4U)                                                /*!< USB0_TOKEN.TOKENPID Position            */
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0xF0UL)            /*!< USB0_TOKEN.TOKENPID Field               */
/* ------- SOFTHLD Bit Fields                       ------ */
#define USB_SOFTHLD_CNT_MASK                     (0xFFU)                                             /*!< USB0_SOFTHLD.CNT Mask                   */
#define USB_SOFTHLD_CNT_SHIFT                    (0U)                                                /*!< USB0_SOFTHLD.CNT Position               */
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_SOFTHLD.CNT Field                  */
/* ------- BDTPAGE2 Bit Fields                      ------ */
#define USB_BDTPAGE2_BDTBA_MASK                  (0xFFU)                                             /*!< USB0_BDTPAGE2.BDTBA Mask                */
#define USB_BDTPAGE2_BDTBA_SHIFT                 (0U)                                                /*!< USB0_BDTPAGE2.BDTBA Position            */
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_BDTPAGE2.BDTBA Field               */
/* ------- BDTPAGE3 Bit Fields                      ------ */
#define USB_BDTPAGE3_BDTBA_MASK                  (0xFFU)                                             /*!< USB0_BDTPAGE3.BDTBA Mask                */
#define USB_BDTPAGE3_BDTBA_SHIFT                 (0U)                                                /*!< USB0_BDTPAGE3.BDTBA Position            */
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_BDTPAGE3.BDTBA Field               */
/* ------- ENDPT Bit Fields                         ------ */
#define USB_ENDPT_EPHSHK_MASK                    (0x1U)                                              /*!< USB0_ENDPT.EPHSHK Mask                  */
#define USB_ENDPT_EPHSHK_SHIFT                   (0U)                                                /*!< USB0_ENDPT.EPHSHK Position              */
#define USB_ENDPT_EPHSHK(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ENDPT.EPHSHK Field                 */
#define USB_ENDPT_EPSTALL_MASK                   (0x2U)                                              /*!< USB0_ENDPT.EPSTALL Mask                 */
#define USB_ENDPT_EPSTALL_SHIFT                  (1U)                                                /*!< USB0_ENDPT.EPSTALL Position             */
#define USB_ENDPT_EPSTALL(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_ENDPT.EPSTALL Field                */
#define USB_ENDPT_EPTXEN_MASK                    (0x4U)                                              /*!< USB0_ENDPT.EPTXEN Mask                  */
#define USB_ENDPT_EPTXEN_SHIFT                   (2U)                                                /*!< USB0_ENDPT.EPTXEN Position              */
#define USB_ENDPT_EPTXEN(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_ENDPT.EPTXEN Field                 */
#define USB_ENDPT_EPRXEN_MASK                    (0x8U)                                              /*!< USB0_ENDPT.EPRXEN Mask                  */
#define USB_ENDPT_EPRXEN_SHIFT                   (3U)                                                /*!< USB0_ENDPT.EPRXEN Position              */
#define USB_ENDPT_EPRXEN(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_ENDPT.EPRXEN Field                 */
#define USB_ENDPT_EPCTLDIS_MASK                  (0x10U)                                             /*!< USB0_ENDPT.EPCTLDIS Mask                */
#define USB_ENDPT_EPCTLDIS_SHIFT                 (4U)                                                /*!< USB0_ENDPT.EPCTLDIS Position            */
#define USB_ENDPT_EPCTLDIS(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_ENDPT.EPCTLDIS Field               */
#define USB_ENDPT_RETRYDIS_MASK                  (0x40U)                                             /*!< USB0_ENDPT.RETRYDIS Mask                */
#define USB_ENDPT_RETRYDIS_SHIFT                 (6U)                                                /*!< USB0_ENDPT.RETRYDIS Position            */
#define USB_ENDPT_RETRYDIS(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_ENDPT.RETRYDIS Field               */
#define USB_ENDPT_HOSTWOHUB_MASK                 (0x80U)                                             /*!< USB0_ENDPT.HOSTWOHUB Mask               */
#define USB_ENDPT_HOSTWOHUB_SHIFT                (7U)                                                /*!< USB0_ENDPT.HOSTWOHUB Position           */
#define USB_ENDPT_HOSTWOHUB(x)                   (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ENDPT.HOSTWOHUB Field              */
/* ------- USBCTRL Bit Fields                       ------ */
#define USB_USBCTRL_CLK_SRC_MASK                 (0x3U)                                              /*!< USB0_USBCTRL.CLK_SRC Mask               */
#define USB_USBCTRL_CLK_SRC_SHIFT                (0U)                                                /*!< USB0_USBCTRL.CLK_SRC Position           */
#define USB_USBCTRL_CLK_SRC(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< USB0_USBCTRL.CLK_SRC Field              */
#define USB_USBCTRL_PDE_MASK                     (0x40U)                                             /*!< USB0_USBCTRL.PDE Mask                   */
#define USB_USBCTRL_PDE_SHIFT                    (6U)                                                /*!< USB0_USBCTRL.PDE Position               */
#define USB_USBCTRL_PDE(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_USBCTRL.PDE Field                  */
#define USB_USBCTRL_SUSP_MASK                    (0x80U)                                             /*!< USB0_USBCTRL.SUSP Mask                  */
#define USB_USBCTRL_SUSP_SHIFT                   (7U)                                                /*!< USB0_USBCTRL.SUSP Position              */
#define USB_USBCTRL_SUSP(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_USBCTRL.SUSP Field                 */
/* ------- OBSERVE Bit Fields                       ------ */
#define USB_OBSERVE_DMPD_MASK                    (0x10U)                                             /*!< USB0_OBSERVE.DMPD Mask                  */
#define USB_OBSERVE_DMPD_SHIFT                   (4U)                                                /*!< USB0_OBSERVE.DMPD Position              */
#define USB_OBSERVE_DMPD(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_OBSERVE.DMPD Field                 */
#define USB_OBSERVE_DPPD_MASK                    (0x40U)                                             /*!< USB0_OBSERVE.DPPD Mask                  */
#define USB_OBSERVE_DPPD_SHIFT                   (6U)                                                /*!< USB0_OBSERVE.DPPD Position              */
#define USB_OBSERVE_DPPD(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_OBSERVE.DPPD Field                 */
#define USB_OBSERVE_DPPU_MASK                    (0x80U)                                             /*!< USB0_OBSERVE.DPPU Mask                  */
#define USB_OBSERVE_DPPU_SHIFT                   (7U)                                                /*!< USB0_OBSERVE.DPPU Position              */
#define USB_OBSERVE_DPPU(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_OBSERVE.DPPU Field                 */
/* ------- CONTROL Bit Fields                       ------ */
#define USB_CONTROL_SESSEND_MASK                 (0x1U)                                              /*!< USB0_CONTROL.SESSEND Mask               */
#define USB_CONTROL_SESSEND_SHIFT                (0U)                                                /*!< USB0_CONTROL.SESSEND Position           */
#define USB_CONTROL_SESSEND(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_CONTROL.SESSEND Field              */
#define USB_CONTROL_SESSVLD_MASK                 (0x2U)                                              /*!< USB0_CONTROL.SESSVLD Mask               */
#define USB_CONTROL_SESSVLD_SHIFT                (1U)                                                /*!< USB0_CONTROL.SESSVLD Position           */
#define USB_CONTROL_SESSVLD(x)                   (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_CONTROL.SESSVLD Field              */
#define USB_CONTROL_VBUSVLD_MASK                 (0x4U)                                              /*!< USB0_CONTROL.VBUSVLD Mask               */
#define USB_CONTROL_VBUSVLD_SHIFT                (2U)                                                /*!< USB0_CONTROL.VBUSVLD Position           */
#define USB_CONTROL_VBUSVLD(x)                   (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_CONTROL.VBUSVLD Field              */
#define USB_CONTROL_ID_MASK                      (0x8U)                                              /*!< USB0_CONTROL.ID Mask                    */
#define USB_CONTROL_ID_SHIFT                     (3U)                                                /*!< USB0_CONTROL.ID Position                */
#define USB_CONTROL_ID(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_CONTROL.ID Field                   */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          (0x10U)                                             /*!< USB0_CONTROL.DPPULLUPNONOTG Mask        */
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         (4U)                                                /*!< USB0_CONTROL.DPPULLUPNONOTG Position    */
#define USB_CONTROL_DPPULLUPNONOTG(x)            (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_CONTROL.DPPULLUPNONOTG Field       */
/**
 * @} */ /* End group USB_Register_Masks_GROUP 
 */

/* USB0 - Peripheral instance base addresses */
#define USB0_BasePtr                   0x401C0000UL //!< Peripheral base address
#define USB0                           ((USB_Type *) USB0_BasePtr) //!< Freescale base pointer
#define USB0_BASE_PTR                  (USB0) //!< Freescale style base pointer
/**
 * @} */ /* End group USB_Peripheral_access_layer_GROUP 
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


#endif  /* MCU_MCF5225X */

