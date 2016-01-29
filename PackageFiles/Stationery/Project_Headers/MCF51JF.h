/****************************************************************************************************//**
 * @file     $(targetDevice).h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MCF51JF.
 *           Equivalent: 
 *
 * @version  V0.0
 * @date     2016/01
 *
 *******************************************************************************************************/

#ifndef MCU_MCF51JF
#define MCU_MCF51JF

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
  NonPCBreakpoint_IRQn          =  12,   /**<  12 Non PC Breakpoint                                                                */
  PCBreakpoint_IRQn             =  13,   /**<  13 PC Breakpoint                                                                    */
  FormatError_IRQn              =  14,   /**<  14 Format Error                                                                     */
  Uninitialized_IRQn            =  15,   /**<  15 Uninitialised Interrupt                                                          */
  SpuriousInt_IRQn              =  24,   /**<  24 Spurious Interrupt                                                               */
  AutoVector1_IRQn              =  25,   /**<  25 Auto vector # 1                                                                  */
  AutoVector2_IRQn              =  26,   /**<  26 Auto vector # 2                                                                  */
  AutoVector3_IRQn              =  27,   /**<  27 Auto vector # 3                                                                  */
  AutoVector4_IRQn              =  28,   /**<  28 Auto vector # 4                                                                  */
  AutoVector5_IRQn              =  29,   /**<  29 Auto vector # 5                                                                  */
  AutoVector6_IRQn              =  30,   /**<  30 Auto vector # 6                                                                  */
  AutoVector7_IRQn              =  31,   /**<  31 Auto vector # 7                                                                  */
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
/* ----------------------   MCF51JFxxx VectorTable                   ---------------------- */
  IRQ_IRQn                      =  64,   /**<  64 IRQ                                                                              */
  LVD_IRQn                      =  65,   /**<  65 Low Voltage Detect, Low Voltage Warning interrupt                                */
  LLWU_IRQn                     =  66,   /**<  66 Low Leakage Wakeup                                                               */
  LOL_IRQn                      =  67,   /**<  67 MCG Loss of Clock                                                                */
  FLASH_IRQn                    =  68,   /**<  68 Flash                                                                            */
  DMA_CH0_IRQn                  =  69,   /**<  69 DMA Channel 0                                                                    */
  DMA_CH1_IRQn                  =  70,   /**<  70 DMA Channel 1                                                                    */
  DMA_CH2_IRQn                  =  71,   /**<  71 DMA Channel 2                                                                    */
  DMA_CH3_IRQn                  =  72,   /**<  72 DMA Channel 3                                                                    */
  USB0_IRQn                     =  73,   /**<  73 USB0 Status                                                                      */
  RNGB_IRQn                     =  74,   /**<  74 RNGB                                                                             */
  FTM1FAULT_OVF_IRQn            =  75,   /**<  75 FTM1 Fault & Overflow                                                            */
  FTM1_CH0_IRQn                 =  76,   /**<  76 FTM1 Channel 0                                                                   */
  FTM1_CH1_IRQn                 =  77,   /**<  77 FTM1 Channel 1                                                                   */
  FTM1_CH2_IRQn                 =  78,   /**<  78 FTM1 Channel 2                                                                   */
  FTM1_CH3_IRQn                 =  79,   /**<  79 FTM1 Channel 3                                                                   */
  FTM1_CH4_IRQn                 =  80,   /**<  80 FTM1 Channel 4                                                                   */
  FTM1_CH5_IRQn                 =  81,   /**<  81 FTM1 Channel 5                                                                   */
  CMP0_IRQn                     =  82,   /**<  82 CMP0                                                                             */
  FTM0_FAULT_OVF_IRQn           =  83,   /**<  83 FTM0 Fault & Overflow                                                            */
  FTM0_CH0_IRQn                 =  84,   /**<  84 FTM0 Channel 0                                                                   */
  FTM0_CH1_IRQn                 =  85,   /**<  85 FTM0 Channel 1                                                                   */
  SPI0_IRQn                     =  86,   /**<  86 SPI0                                                                             */
  SCI0_IRQn                     =  87,   /**<  87 UART0                                                                            */
  SAI_RX_IRQn                   =  88,   /**<  88 I2S Receive                                                                      */
  SAI_TX_IRQn                   =  89,   /**<  89 I2S Transmit                                                                     */
  IIC0_IRQn                     =  90,   /**<  90 I2C0                                                                             */
  IIC2_IRQn                     =  91,   /**<  91 I2C2                                                                             */
  SPI1_IRQn                     =  92,   /**<  92 SPI1                                                                             */
  SCI1_IRQn                     =  93,   /**<  93 UART1                                                                            */
  IIC1_IRQn                     =  94,   /**<  94 I2C1                                                                             */
  IIC3_IRQn                     =  95,   /**<  95 I2C3                                                                             */
  ADC0_IRQn                     =  96,   /**<  96 ADC0                                                                             */
  TSI0_IRQn                     =  97,   /**<  97 TSI0                                                                             */
  DAC0_IRQn                     =  98,   /**<  98 DAC0                                                                             */
  CMT_IRQn                      =  99,   /**<  99 CMT                                                                              */
  PDB0_IRQn                     = 100,   /**< 100 PDB0                                                                             */
  LPTMR0_IRQn                   = 101,   /**< 101 LPTMR0                                                                           */
  LPTMR1_IRQn                   = 102,   /**< 102 LPTMR1                                                                           */
  L7_SWI_IRQn                   = 103,   /**< 103 Level 7 Software Interrupt                                                       */
  L6_SWI_IRQn                   = 104,   /**< 104 Level 6 Software Interrupt                                                       */
  L5_SWI_IRQn                   = 105,   /**< 105 Level 5 Software Interrupt                                                       */
  L4_SWI_IRQn                   = 106,   /**< 106 Level 4 Software Interrupt                                                       */
  L3_SWI_IRQn                   = 107,   /**< 107 Level 3 Software Interrupt                                                       */
  L2_SWI_IRQn                   = 108,   /**< 108 Level 2 Software Interrupt                                                       */
  L1_SWI_IRQn                   = 109,   /**< 109 Level 1 Software Interrupt                                                       */
  MTIM0_IRQn                    = 110,   /**< 110 MTIM0                                                                            */
  USBDCD_IRQn                   = 111,   /**< 111 USBDCD                                                                           */
  PORT_AB_IRQn                  = 112,   /**< 112 EGPIO Port A & EGPIO Port B                                                      */
  PORT_CD_IRQn                  = 113,   /**< 113 EGPIO Port C & EGPIO Port D                                                      */
  PORT_EF_IRQn                  = 114,   /**< 114 EGPIO Port E & EGPIO Port F                                                      */
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
extern void NonPCBreakpoint_Handler(void);     /**< Non PC Breakpoint                                                                */
extern void PCBreakpoint_Handler(void);        /**< PC Breakpoint                                                                    */
extern void FormatError_Handler(void);         /**< Format Error                                                                     */
extern void Uninitialized_Handler(void);       /**< Uninitialised Interrupt                                                          */
extern void SpuriousInt_Handler(void);         /**< Spurious Interrupt                                                               */
extern void AutoVector1_Handler(void);         /**< Auto vector # 1                                                                  */
extern void AutoVector2_Handler(void);         /**< Auto vector # 2                                                                  */
extern void AutoVector3_Handler(void);         /**< Auto vector # 3                                                                  */
extern void AutoVector4_Handler(void);         /**< Auto vector # 4                                                                  */
extern void AutoVector5_Handler(void);         /**< Auto vector # 5                                                                  */
extern void AutoVector6_Handler(void);         /**< Auto vector # 6                                                                  */
extern void AutoVector7_Handler(void);         /**< Auto vector # 7                                                                  */
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
extern void IRQ_IRQHandler(void);              /**< IRQ                                                                              */
extern void LVD_IRQHandler(void);              /**< Low Voltage Detect, Low Voltage Warning interrupt                                */
extern void LLWU_IRQHandler(void);             /**< Low Leakage Wakeup                                                               */
extern void LOL_IRQHandler(void);              /**< MCG Loss of Clock                                                                */
extern void FLASH_IRQHandler(void);            /**< Flash                                                                            */
extern void DMA_CH0_IRQHandler(void);          /**< DMA Channel 0                                                                    */
extern void DMA_CH1_IRQHandler(void);          /**< DMA Channel 1                                                                    */
extern void DMA_CH2_IRQHandler(void);          /**< DMA Channel 2                                                                    */
extern void DMA_CH3_IRQHandler(void);          /**< DMA Channel 3                                                                    */
extern void USB0_IRQHandler(void);             /**< USB0 Status                                                                      */
extern void RNGB_IRQHandler(void);             /**< RNGB                                                                             */
extern void FTM1FAULT_OVF_IRQHandler(void);    /**< FTM1 Fault & Overflow                                                            */
extern void FTM1_CH0_IRQHandler(void);         /**< FTM1 Channel 0                                                                   */
extern void FTM1_CH1_IRQHandler(void);         /**< FTM1 Channel 1                                                                   */
extern void FTM1_CH2_IRQHandler(void);         /**< FTM1 Channel 2                                                                   */
extern void FTM1_CH3_IRQHandler(void);         /**< FTM1 Channel 3                                                                   */
extern void FTM1_CH4_IRQHandler(void);         /**< FTM1 Channel 4                                                                   */
extern void FTM1_CH5_IRQHandler(void);         /**< FTM1 Channel 5                                                                   */
extern void CMP0_IRQHandler(void);             /**< CMP0                                                                             */
extern void FTM0_FAULT_OVF_IRQHandler(void);   /**< FTM0 Fault & Overflow                                                            */
extern void FTM0_CH0_IRQHandler(void);         /**< FTM0 Channel 0                                                                   */
extern void FTM0_CH1_IRQHandler(void);         /**< FTM0 Channel 1                                                                   */
extern void SPI0_IRQHandler(void);             /**< SPI0                                                                             */
extern void SCI0_IRQHandler(void);             /**< UART0                                                                            */
extern void SAI_RX_IRQHandler(void);           /**< I2S Receive                                                                      */
extern void SAI_TX_IRQHandler(void);           /**< I2S Transmit                                                                     */
extern void IIC0_IRQHandler(void);             /**< I2C0                                                                             */
extern void IIC2_IRQHandler(void);             /**< I2C2                                                                             */
extern void SPI1_IRQHandler(void);             /**< SPI1                                                                             */
extern void SCI1_IRQHandler(void);             /**< UART1                                                                            */
extern void IIC1_IRQHandler(void);             /**< I2C1                                                                             */
extern void IIC3_IRQHandler(void);             /**< I2C3                                                                             */
extern void ADC0_IRQHandler(void);             /**< ADC0                                                                             */
extern void TSI0_IRQHandler(void);             /**< TSI0                                                                             */
extern void DAC0_IRQHandler(void);             /**< DAC0                                                                             */
extern void CMT_IRQHandler(void);              /**< CMT                                                                              */
extern void PDB0_IRQHandler(void);             /**< PDB0                                                                             */
extern void LPTMR0_IRQHandler(void);           /**< LPTMR0                                                                           */
extern void LPTMR1_IRQHandler(void);           /**< LPTMR1                                                                           */
extern void L7_SWI_IRQHandler(void);           /**< Level 7 Software Interrupt                                                       */
extern void L6_SWI_IRQHandler(void);           /**< Level 6 Software Interrupt                                                       */
extern void L5_SWI_IRQHandler(void);           /**< Level 5 Software Interrupt                                                       */
extern void L4_SWI_IRQHandler(void);           /**< Level 4 Software Interrupt                                                       */
extern void L3_SWI_IRQHandler(void);           /**< Level 3 Software Interrupt                                                       */
extern void L2_SWI_IRQHandler(void);           /**< Level 2 Software Interrupt                                                       */
extern void L1_SWI_IRQHandler(void);           /**< Level 1 Software Interrupt                                                       */
extern void MTIM0_IRQHandler(void);            /**< MTIM0                                                                            */
extern void USBDCD_IRQHandler(void);           /**< USBDCD                                                                           */
extern void PORT_AB_IRQHandler(void);          /**< EGPIO Port A & EGPIO Port B                                                      */
extern void PORT_CD_IRQHandler(void);          /**< EGPIO Port C & EGPIO Port D                                                      */
extern void PORT_EF_IRQHandler(void);          /**< EGPIO Port E & EGPIO Port F                                                      */

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
#include "core_cfv1.h"          /* Processor and core peripherals     */
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
/* ================           ADC0 (file:ADC0_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC0 Structure                                               */
   __IO uint32_t  SC1A;                         /**< 0000: Status and Control Register 1                                */
   __IO uint32_t  SC1B;                         /**< 0004: Status and Control Register 1                                */
   __IO uint32_t  CFG1;                         /**< 0008: Configuration Register 1                                     */
   __IO uint32_t  CFG2;                         /**< 000C: Configuration Register 2                                     */
   __I  uint32_t  RA;                           /**< 0010: Data Result Register                                         */
   __I  uint32_t  RB;                           /**< 0014: Data Result Register                                         */
   __IO uint32_t  CV1;                          /**< 0018: Compare Value                                                */
   __IO uint32_t  CV2;                          /**< 001C: Compare Value                                                */
   __IO uint32_t  SC2;                          /**< 0020: Status and Control Register 2                                */
   __IO uint32_t  SC3;                          /**< 0024: Status and Control Register 3                                */
   __IO uint32_t  OFS;                          /**< 0028: Offset Correction Register                                   */
   __IO uint32_t  PG;                           /**< 002C: Plus-Side Gain Register                                      */
   __I  uint32_t  RESERVED0;                   
   __IO uint32_t  CLPD;                         /**< 0034: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLPS;                         /**< 0038: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP4;                         /**< 003C: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP3;                         /**< 0040: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP2;                         /**< 0044: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP1;                         /**< 0048: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP0;                         /**< 004C: Plus-Side General Calibration Value                          */
} ADC_Type;

/**
 * @} */ /* End group ADC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ADC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ADC_Register_Masks_GROUP ADC Register Masks
* @brief Register Masks for ADC
* @{
*/
/* ------- SC1 Bit Fields                           ------ */
#define ADC_SC1_ADCH_MASK                        (0x1FUL << ADC_SC1_ADCH_SHIFT)                      /*!< ADC0_SC1: ADCH Mask                     */
#define ADC_SC1_ADCH_SHIFT                       0                                                   /*!< ADC0_SC1: ADCH Position                 */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_AIEN_MASK                        (0x01UL << ADC_SC1_AIEN_SHIFT)                      /*!< ADC0_SC1: AIEN Mask                     */
#define ADC_SC1_AIEN_SHIFT                       6                                                   /*!< ADC0_SC1: AIEN Position                 */
#define ADC_SC1_COCO_MASK                        (0x01UL << ADC_SC1_COCO_SHIFT)                      /*!< ADC0_SC1: COCO Mask                     */
#define ADC_SC1_COCO_SHIFT                       7                                                   /*!< ADC0_SC1: COCO Position                 */
/* ------- CFG1 Bit Fields                          ------ */
#define ADC_CFG1_ADICLK_MASK                     (0x03UL << ADC_CFG1_ADICLK_SHIFT)                   /*!< ADC0_CFG1: ADICLK Mask                  */
#define ADC_CFG1_ADICLK_SHIFT                    0                                                   /*!< ADC0_CFG1: ADICLK Position              */
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_MODE_MASK                       (0x03UL << ADC_CFG1_MODE_SHIFT)                     /*!< ADC0_CFG1: MODE Mask                    */
#define ADC_CFG1_MODE_SHIFT                      2                                                   /*!< ADC0_CFG1: MODE Position                */
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLSMP_MASK                     (0x01UL << ADC_CFG1_ADLSMP_SHIFT)                   /*!< ADC0_CFG1: ADLSMP Mask                  */
#define ADC_CFG1_ADLSMP_SHIFT                    4                                                   /*!< ADC0_CFG1: ADLSMP Position              */
#define ADC_CFG1_ADIV_MASK                       (0x03UL << ADC_CFG1_ADIV_SHIFT)                     /*!< ADC0_CFG1: ADIV Mask                    */
#define ADC_CFG1_ADIV_SHIFT                      5                                                   /*!< ADC0_CFG1: ADIV Position                */
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLPC_MASK                      (0x01UL << ADC_CFG1_ADLPC_SHIFT)                    /*!< ADC0_CFG1: ADLPC Mask                   */
#define ADC_CFG1_ADLPC_SHIFT                     7                                                   /*!< ADC0_CFG1: ADLPC Position               */
/* ------- CFG2 Bit Fields                          ------ */
#define ADC_CFG2_ADLSTS_MASK                     (0x03UL << ADC_CFG2_ADLSTS_SHIFT)                   /*!< ADC0_CFG2: ADLSTS Mask                  */
#define ADC_CFG2_ADLSTS_SHIFT                    0                                                   /*!< ADC0_CFG2: ADLSTS Position              */
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_ADHSC_MASK                      (0x01UL << ADC_CFG2_ADHSC_SHIFT)                    /*!< ADC0_CFG2: ADHSC Mask                   */
#define ADC_CFG2_ADHSC_SHIFT                     2                                                   /*!< ADC0_CFG2: ADHSC Position               */
#define ADC_CFG2_ADACKEN_MASK                    (0x01UL << ADC_CFG2_ADACKEN_SHIFT)                  /*!< ADC0_CFG2: ADACKEN Mask                 */
#define ADC_CFG2_ADACKEN_SHIFT                   3                                                   /*!< ADC0_CFG2: ADACKEN Position             */
/* ------- R Bit Fields                             ------ */
#define ADC_R_D_MASK                             (0xFFFFUL << ADC_R_D_SHIFT)                         /*!< ADC0_R: D Mask                          */
#define ADC_R_D_SHIFT                            0                                                   /*!< ADC0_R: D Position                      */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK) /*!< ADC0_R                                  */
/* ------- CV Bit Fields                            ------ */
#define ADC_CV_CV_MASK                           (0xFFFFUL << ADC_CV_CV_SHIFT)                       /*!< ADC0_CV: CV Mask                        */
#define ADC_CV_CV_SHIFT                          0                                                   /*!< ADC0_CV: CV Position                    */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK) /*!< ADC0_CV                                 */
/* ------- SC2 Bit Fields                           ------ */
#define ADC_SC2_REFSEL_MASK                      (0x03UL << ADC_SC2_REFSEL_SHIFT)                    /*!< ADC0_SC2: REFSEL Mask                   */
#define ADC_SC2_REFSEL_SHIFT                     0                                                   /*!< ADC0_SC2: REFSEL Position               */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_DMAEN_MASK                       (0x01UL << ADC_SC2_DMAEN_SHIFT)                     /*!< ADC0_SC2: DMAEN Mask                    */
#define ADC_SC2_DMAEN_SHIFT                      2                                                   /*!< ADC0_SC2: DMAEN Position                */
#define ADC_SC2_ACREN_MASK                       (0x01UL << ADC_SC2_ACREN_SHIFT)                     /*!< ADC0_SC2: ACREN Mask                    */
#define ADC_SC2_ACREN_SHIFT                      3                                                   /*!< ADC0_SC2: ACREN Position                */
#define ADC_SC2_ACFGT_MASK                       (0x01UL << ADC_SC2_ACFGT_SHIFT)                     /*!< ADC0_SC2: ACFGT Mask                    */
#define ADC_SC2_ACFGT_SHIFT                      4                                                   /*!< ADC0_SC2: ACFGT Position                */
#define ADC_SC2_ACFE_MASK                        (0x01UL << ADC_SC2_ACFE_SHIFT)                      /*!< ADC0_SC2: ACFE Mask                     */
#define ADC_SC2_ACFE_SHIFT                       5                                                   /*!< ADC0_SC2: ACFE Position                 */
#define ADC_SC2_ADTRG_MASK                       (0x01UL << ADC_SC2_ADTRG_SHIFT)                     /*!< ADC0_SC2: ADTRG Mask                    */
#define ADC_SC2_ADTRG_SHIFT                      6                                                   /*!< ADC0_SC2: ADTRG Position                */
#define ADC_SC2_ADACT_MASK                       (0x01UL << ADC_SC2_ADACT_SHIFT)                     /*!< ADC0_SC2: ADACT Mask                    */
#define ADC_SC2_ADACT_SHIFT                      7                                                   /*!< ADC0_SC2: ADACT Position                */
/* ------- SC3 Bit Fields                           ------ */
#define ADC_SC3_AVGS_MASK                        (0x03UL << ADC_SC3_AVGS_SHIFT)                      /*!< ADC0_SC3: AVGS Mask                     */
#define ADC_SC3_AVGS_SHIFT                       0                                                   /*!< ADC0_SC3: AVGS Position                 */
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_AVGE_MASK                        (0x01UL << ADC_SC3_AVGE_SHIFT)                      /*!< ADC0_SC3: AVGE Mask                     */
#define ADC_SC3_AVGE_SHIFT                       2                                                   /*!< ADC0_SC3: AVGE Position                 */
#define ADC_SC3_ADCO_MASK                        (0x01UL << ADC_SC3_ADCO_SHIFT)                      /*!< ADC0_SC3: ADCO Mask                     */
#define ADC_SC3_ADCO_SHIFT                       3                                                   /*!< ADC0_SC3: ADCO Position                 */
#define ADC_SC3_CALF_MASK                        (0x01UL << ADC_SC3_CALF_SHIFT)                      /*!< ADC0_SC3: CALF Mask                     */
#define ADC_SC3_CALF_SHIFT                       6                                                   /*!< ADC0_SC3: CALF Position                 */
#define ADC_SC3_CAL_MASK                         (0x01UL << ADC_SC3_CAL_SHIFT)                       /*!< ADC0_SC3: CAL Mask                      */
#define ADC_SC3_CAL_SHIFT                        7                                                   /*!< ADC0_SC3: CAL Position                  */
/* ------- OFS Bit Fields                           ------ */
#define ADC_OFS_OFS_MASK                         (0xFFFFUL << ADC_OFS_OFS_SHIFT)                     /*!< ADC0_OFS: OFS Mask                      */
#define ADC_OFS_OFS_SHIFT                        0                                                   /*!< ADC0_OFS: OFS Position                  */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK) /*!< ADC0_OFS                                */
/* ------- PG Bit Fields                            ------ */
#define ADC_PG_PG_MASK                           (0xFFFFUL << ADC_PG_PG_SHIFT)                       /*!< ADC0_PG: PG Mask                        */
#define ADC_PG_PG_SHIFT                          0                                                   /*!< ADC0_PG: PG Position                    */
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK) /*!< ADC0_PG                                 */
/* ------- CLPD Bit Fields                          ------ */
#define ADC_CLPD_CLPD_MASK                       (0x3FUL << ADC_CLPD_CLPD_SHIFT)                     /*!< ADC0_CLPD: CLPD Mask                    */
#define ADC_CLPD_CLPD_SHIFT                      0                                                   /*!< ADC0_CLPD: CLPD Position                */
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK) /*!< ADC0_CLPD                               */
/* ------- CLPS Bit Fields                          ------ */
#define ADC_CLPS_CLPS_MASK                       (0x3FUL << ADC_CLPS_CLPS_SHIFT)                     /*!< ADC0_CLPS: CLPS Mask                    */
#define ADC_CLPS_CLPS_SHIFT                      0                                                   /*!< ADC0_CLPS: CLPS Position                */
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK) /*!< ADC0_CLPS                               */
/* ------- CLP4 Bit Fields                          ------ */
#define ADC_CLP4_CLP4_MASK                       (0x3FFUL << ADC_CLP4_CLP4_SHIFT)                    /*!< ADC0_CLP4: CLP4 Mask                    */
#define ADC_CLP4_CLP4_SHIFT                      0                                                   /*!< ADC0_CLP4: CLP4 Position                */
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK) /*!< ADC0_CLP4                               */
/* ------- CLP3 Bit Fields                          ------ */
#define ADC_CLP3_CLP3_MASK                       (0x1FFUL << ADC_CLP3_CLP3_SHIFT)                    /*!< ADC0_CLP3: CLP3 Mask                    */
#define ADC_CLP3_CLP3_SHIFT                      0                                                   /*!< ADC0_CLP3: CLP3 Position                */
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK) /*!< ADC0_CLP3                               */
/* ------- CLP2 Bit Fields                          ------ */
#define ADC_CLP2_CLP2_MASK                       (0xFFUL << ADC_CLP2_CLP2_SHIFT)                     /*!< ADC0_CLP2: CLP2 Mask                    */
#define ADC_CLP2_CLP2_SHIFT                      0                                                   /*!< ADC0_CLP2: CLP2 Position                */
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK) /*!< ADC0_CLP2                               */
/* ------- CLP1 Bit Fields                          ------ */
#define ADC_CLP1_CLP1_MASK                       (0x7FUL << ADC_CLP1_CLP1_SHIFT)                     /*!< ADC0_CLP1: CLP1 Mask                    */
#define ADC_CLP1_CLP1_SHIFT                      0                                                   /*!< ADC0_CLP1: CLP1 Position                */
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK) /*!< ADC0_CLP1                               */
/* ------- CLP0 Bit Fields                          ------ */
#define ADC_CLP0_CLP0_MASK                       (0x3FUL << ADC_CLP0_CLP0_SHIFT)                     /*!< ADC0_CLP0: CLP0 Mask                    */
#define ADC_CLP0_CLP0_SHIFT                      0                                                   /*!< ADC0_CLP0: CLP0 Position                */
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK) /*!< ADC0_CLP0                               */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC0 - Peripheral instance base addresses */
#define ADC0_BasePtr                   0xFFFF8600UL //!< Peripheral base address
#define ADC0                           ((ADC_Type *) ADC0_BasePtr) //!< Freescale base pointer
#define ADC0_BASE_PTR                  (ADC0) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP0 (file:CMP0_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */
/**
* @addtogroup CMP_structs_GROUP CMP struct
* @brief Struct for CMP
* @{
*/
typedef struct {                                /*       CMP0 Structure                                               */
   __IO uint8_t   CR0;                          /**< 0000: CMP Control Register 0                                       */
   __IO uint8_t   CR1;                          /**< 0001: CMP Control Register 1                                       */
   __IO uint8_t   FPR;                          /**< 0002: CMP Filter Period Register                                   */
   __IO uint8_t   SCR;                          /**< 0003: CMP Status and Control Register                              */
   __IO uint8_t   DACCR;                        /**< 0004: DAC Control Register                                         */
   __IO uint8_t   MUXCR;                        /**< 0005: MUX Control Register                                         */
} CMP_Type;

/**
 * @} */ /* End group CMP_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMP0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMP_Register_Masks_GROUP CMP Register Masks
* @brief Register Masks for CMP
* @{
*/
/* ------- CR0 Bit Fields                           ------ */
#define CMP_CR0_HYSTCTR_MASK                     (0x03UL << CMP_CR0_HYSTCTR_SHIFT)                   /*!< CMP0_CR0: HYSTCTR Mask                  */
#define CMP_CR0_HYSTCTR_SHIFT                    0                                                   /*!< CMP0_CR0: HYSTCTR Position              */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK) /*!< CMP0_CR0                                */
#define CMP_CR0_FILTER_CNT_MASK                  (0x07UL << CMP_CR0_FILTER_CNT_SHIFT)                /*!< CMP0_CR0: FILTER_CNT Mask               */
#define CMP_CR0_FILTER_CNT_SHIFT                 4                                                   /*!< CMP0_CR0: FILTER_CNT Position           */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK) /*!< CMP0_CR0                                */
/* ------- CR1 Bit Fields                           ------ */
#define CMP_CR1_EN_MASK                          (0x01UL << CMP_CR1_EN_SHIFT)                        /*!< CMP0_CR1: EN Mask                       */
#define CMP_CR1_EN_SHIFT                         0                                                   /*!< CMP0_CR1: EN Position                   */
#define CMP_CR1_OPE_MASK                         (0x01UL << CMP_CR1_OPE_SHIFT)                       /*!< CMP0_CR1: OPE Mask                      */
#define CMP_CR1_OPE_SHIFT                        1                                                   /*!< CMP0_CR1: OPE Position                  */
#define CMP_CR1_COS_MASK                         (0x01UL << CMP_CR1_COS_SHIFT)                       /*!< CMP0_CR1: COS Mask                      */
#define CMP_CR1_COS_SHIFT                        2                                                   /*!< CMP0_CR1: COS Position                  */
#define CMP_CR1_INV_MASK                         (0x01UL << CMP_CR1_INV_SHIFT)                       /*!< CMP0_CR1: INV Mask                      */
#define CMP_CR1_INV_SHIFT                        3                                                   /*!< CMP0_CR1: INV Position                  */
#define CMP_CR1_PMODE_MASK                       (0x01UL << CMP_CR1_PMODE_SHIFT)                     /*!< CMP0_CR1: PMODE Mask                    */
#define CMP_CR1_PMODE_SHIFT                      4                                                   /*!< CMP0_CR1: PMODE Position                */
#define CMP_CR1_WE_MASK                          (0x01UL << CMP_CR1_WE_SHIFT)                        /*!< CMP0_CR1: WE Mask                       */
#define CMP_CR1_WE_SHIFT                         6                                                   /*!< CMP0_CR1: WE Position                   */
#define CMP_CR1_SE_MASK                          (0x01UL << CMP_CR1_SE_SHIFT)                        /*!< CMP0_CR1: SE Mask                       */
#define CMP_CR1_SE_SHIFT                         7                                                   /*!< CMP0_CR1: SE Position                   */
/* ------- FPR Bit Fields                           ------ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFUL << CMP_FPR_FILT_PER_SHIFT)                  /*!< CMP0_FPR: FILT_PER Mask                 */
#define CMP_FPR_FILT_PER_SHIFT                   0                                                   /*!< CMP0_FPR: FILT_PER Position             */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK) /*!< CMP0_FPR                                */
/* ------- SCR Bit Fields                           ------ */
#define CMP_SCR_COUT_MASK                        (0x01UL << CMP_SCR_COUT_SHIFT)                      /*!< CMP0_SCR: COUT Mask                     */
#define CMP_SCR_COUT_SHIFT                       0                                                   /*!< CMP0_SCR: COUT Position                 */
#define CMP_SCR_CFF_MASK                         (0x01UL << CMP_SCR_CFF_SHIFT)                       /*!< CMP0_SCR: CFF Mask                      */
#define CMP_SCR_CFF_SHIFT                        1                                                   /*!< CMP0_SCR: CFF Position                  */
#define CMP_SCR_CFR_MASK                         (0x01UL << CMP_SCR_CFR_SHIFT)                       /*!< CMP0_SCR: CFR Mask                      */
#define CMP_SCR_CFR_SHIFT                        2                                                   /*!< CMP0_SCR: CFR Position                  */
#define CMP_SCR_IEF_MASK                         (0x01UL << CMP_SCR_IEF_SHIFT)                       /*!< CMP0_SCR: IEF Mask                      */
#define CMP_SCR_IEF_SHIFT                        3                                                   /*!< CMP0_SCR: IEF Position                  */
#define CMP_SCR_IER_MASK                         (0x01UL << CMP_SCR_IER_SHIFT)                       /*!< CMP0_SCR: IER Mask                      */
#define CMP_SCR_IER_SHIFT                        4                                                   /*!< CMP0_SCR: IER Position                  */
#define CMP_SCR_DMAEN_MASK                       (0x01UL << CMP_SCR_DMAEN_SHIFT)                     /*!< CMP0_SCR: DMAEN Mask                    */
#define CMP_SCR_DMAEN_SHIFT                      6                                                   /*!< CMP0_SCR: DMAEN Position                */
/* ------- DACCR Bit Fields                         ------ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FUL << CMP_DACCR_VOSEL_SHIFT)                   /*!< CMP0_DACCR: VOSEL Mask                  */
#define CMP_DACCR_VOSEL_SHIFT                    0                                                   /*!< CMP0_DACCR: VOSEL Position              */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_VRSEL_MASK                     (0x01UL << CMP_DACCR_VRSEL_SHIFT)                   /*!< CMP0_DACCR: VRSEL Mask                  */
#define CMP_DACCR_VRSEL_SHIFT                    6                                                   /*!< CMP0_DACCR: VRSEL Position              */
#define CMP_DACCR_DACEN_MASK                     (0x01UL << CMP_DACCR_DACEN_SHIFT)                   /*!< CMP0_DACCR: DACEN Mask                  */
#define CMP_DACCR_DACEN_SHIFT                    7                                                   /*!< CMP0_DACCR: DACEN Position              */
/* ------- MUXCR Bit Fields                         ------ */
#define CMP_MUXCR_MSEL_MASK                      (0x07UL << CMP_MUXCR_MSEL_SHIFT)                    /*!< CMP0_MUXCR: MSEL Mask                   */
#define CMP_MUXCR_MSEL_SHIFT                     0                                                   /*!< CMP0_MUXCR: MSEL Position               */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_PSEL_MASK                      (0x07UL << CMP_MUXCR_PSEL_SHIFT)                    /*!< CMP0_MUXCR: PSEL Mask                   */
#define CMP_MUXCR_PSEL_SHIFT                     3                                                   /*!< CMP0_MUXCR: PSEL Position               */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_MEN_MASK                       (0x01UL << CMP_MUXCR_MEN_SHIFT)                     /*!< CMP0_MUXCR: MEN Mask                    */
#define CMP_MUXCR_MEN_SHIFT                      6                                                   /*!< CMP0_MUXCR: MEN Position                */
#define CMP_MUXCR_PEN_MASK                       (0x01UL << CMP_MUXCR_PEN_SHIFT)                     /*!< CMP0_MUXCR: PEN Mask                    */
#define CMP_MUXCR_PEN_SHIFT                      7                                                   /*!< CMP0_MUXCR: PEN Position                */
/**
 * @} */ /* End group CMP_Register_Masks_GROUP 
 */

/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0xFFFF8530UL //!< Peripheral base address
#define CMP0                           ((CMP_Type *) CMP0_BasePtr) //!< Freescale base pointer
#define CMP0_BASE_PTR                  (CMP0) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMT_Peripheral_access_layer_GROUP CMT Peripheral Access Layer
* @brief C Struct for CMT
* @{
*/

/* ================================================================================ */
/* ================           CMT (file:CMT_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief Carrier Modulator Transmitter
 */
/**
* @addtogroup CMT_structs_GROUP CMT struct
* @brief Struct for CMT
* @{
*/
typedef struct {                                /*       CMT Structure                                                */
   __IO uint8_t   CGH1;                         /**< 0000: Carrier Generator High Data Register 1                       */
   __IO uint8_t   CGL1;                         /**< 0001: Carrier Generator Low Data Register 1                        */
   __IO uint8_t   CGH2;                         /**< 0002: Carrier Generator High Data Register 2                       */
   __IO uint8_t   CGL2;                         /**< 0003: Carrier Generator Low Data Register 2                        */
   __IO uint8_t   OC;                           /**< 0004: Output Control Register                                      */
   __IO uint8_t   MSC;                          /**< 0005: Modulator Status and Control Register                        */
   __IO uint8_t   CMD1;                         /**< 0006: Modulator Data Register Mark High                            */
   __IO uint8_t   CMD2;                         /**< 0007: Modulator Data Register Mark Low                             */
   __IO uint8_t   CMD3;                         /**< 0008: Modulator Data Register Space High                           */
   __IO uint8_t   CMD4;                         /**< 0009: Modulator Data Register Space Low                            */
   __IO uint8_t   PPS;                          /**< 000A: Primary Prescaler Register                                   */
   __IO uint8_t   DMA;                          /**< 000B: Direct Memory Access Register                                */
} CMT_Type;

/**
 * @} */ /* End group CMT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMT_Register_Masks_GROUP CMT Register Masks
* @brief Register Masks for CMT
* @{
*/
/* ------- CGH1 Bit Fields                          ------ */
#define CMT_CGH1_PH_MASK                         (0xFFUL << CMT_CGH1_PH_SHIFT)                       /*!< CMT_CGH1: PH Mask                       */
#define CMT_CGH1_PH_SHIFT                        0                                                   /*!< CMT_CGH1: PH Position                   */
#define CMT_CGH1_PH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH1_PH_SHIFT))&CMT_CGH1_PH_MASK) /*!< CMT_CGH1                                */
/* ------- CGL1 Bit Fields                          ------ */
#define CMT_CGL1_PL_MASK                         (0xFFUL << CMT_CGL1_PL_SHIFT)                       /*!< CMT_CGL1: PL Mask                       */
#define CMT_CGL1_PL_SHIFT                        0                                                   /*!< CMT_CGL1: PL Position                   */
#define CMT_CGL1_PL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL1_PL_SHIFT))&CMT_CGL1_PL_MASK) /*!< CMT_CGL1                                */
/* ------- CGH2 Bit Fields                          ------ */
#define CMT_CGH2_SH_MASK                         (0xFFUL << CMT_CGH2_SH_SHIFT)                       /*!< CMT_CGH2: SH Mask                       */
#define CMT_CGH2_SH_SHIFT                        0                                                   /*!< CMT_CGH2: SH Position                   */
#define CMT_CGH2_SH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH2_SH_SHIFT))&CMT_CGH2_SH_MASK) /*!< CMT_CGH2                                */
/* ------- CGL2 Bit Fields                          ------ */
#define CMT_CGL2_SL_MASK                         (0xFFUL << CMT_CGL2_SL_SHIFT)                       /*!< CMT_CGL2: SL Mask                       */
#define CMT_CGL2_SL_SHIFT                        0                                                   /*!< CMT_CGL2: SL Position                   */
#define CMT_CGL2_SL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL2_SL_SHIFT))&CMT_CGL2_SL_MASK) /*!< CMT_CGL2                                */
/* ------- OC Bit Fields                            ------ */
#define CMT_OC_IROPEN_MASK                       (0x01UL << CMT_OC_IROPEN_SHIFT)                     /*!< CMT_OC: IROPEN Mask                     */
#define CMT_OC_IROPEN_SHIFT                      5                                                   /*!< CMT_OC: IROPEN Position                 */
#define CMT_OC_CMTPOL_MASK                       (0x01UL << CMT_OC_CMTPOL_SHIFT)                     /*!< CMT_OC: CMTPOL Mask                     */
#define CMT_OC_CMTPOL_SHIFT                      6                                                   /*!< CMT_OC: CMTPOL Position                 */
#define CMT_OC_IROL_MASK                         (0x01UL << CMT_OC_IROL_SHIFT)                       /*!< CMT_OC: IROL Mask                       */
#define CMT_OC_IROL_SHIFT                        7                                                   /*!< CMT_OC: IROL Position                   */
/* ------- MSC Bit Fields                           ------ */
#define CMT_MSC_MCGEN_MASK                       (0x01UL << CMT_MSC_MCGEN_SHIFT)                     /*!< CMT_MSC: MCGEN Mask                     */
#define CMT_MSC_MCGEN_SHIFT                      0                                                   /*!< CMT_MSC: MCGEN Position                 */
#define CMT_MSC_EOCIE_MASK                       (0x01UL << CMT_MSC_EOCIE_SHIFT)                     /*!< CMT_MSC: EOCIE Mask                     */
#define CMT_MSC_EOCIE_SHIFT                      1                                                   /*!< CMT_MSC: EOCIE Position                 */
#define CMT_MSC_FSK_MASK                         (0x01UL << CMT_MSC_FSK_SHIFT)                       /*!< CMT_MSC: FSK Mask                       */
#define CMT_MSC_FSK_SHIFT                        2                                                   /*!< CMT_MSC: FSK Position                   */
#define CMT_MSC_BASE_MASK                        (0x01UL << CMT_MSC_BASE_SHIFT)                      /*!< CMT_MSC: BASE Mask                      */
#define CMT_MSC_BASE_SHIFT                       3                                                   /*!< CMT_MSC: BASE Position                  */
#define CMT_MSC_EXSPC_MASK                       (0x01UL << CMT_MSC_EXSPC_SHIFT)                     /*!< CMT_MSC: EXSPC Mask                     */
#define CMT_MSC_EXSPC_SHIFT                      4                                                   /*!< CMT_MSC: EXSPC Position                 */
#define CMT_MSC_CMTDIV_MASK                      (0x03UL << CMT_MSC_CMTDIV_SHIFT)                    /*!< CMT_MSC: CMTDIV Mask                    */
#define CMT_MSC_CMTDIV_SHIFT                     5                                                   /*!< CMT_MSC: CMTDIV Position                */
#define CMT_MSC_CMTDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_MSC_CMTDIV_SHIFT))&CMT_MSC_CMTDIV_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EOCF_MASK                        (0x01UL << CMT_MSC_EOCF_SHIFT)                      /*!< CMT_MSC: EOCF Mask                      */
#define CMT_MSC_EOCF_SHIFT                       7                                                   /*!< CMT_MSC: EOCF Position                  */
/* ------- CMD1 Bit Fields                          ------ */
#define CMT_CMD1_MB_MASK                         (0xFFUL << CMT_CMD1_MB_SHIFT)                       /*!< CMT_CMD1: MB Mask                       */
#define CMT_CMD1_MB_SHIFT                        0                                                   /*!< CMT_CMD1: MB Position                   */
#define CMT_CMD1_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD1_MB_SHIFT))&CMT_CMD1_MB_MASK) /*!< CMT_CMD1                                */
/* ------- CMD2 Bit Fields                          ------ */
#define CMT_CMD2_MB_MASK                         (0xFFUL << CMT_CMD2_MB_SHIFT)                       /*!< CMT_CMD2: MB Mask                       */
#define CMT_CMD2_MB_SHIFT                        0                                                   /*!< CMT_CMD2: MB Position                   */
#define CMT_CMD2_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD2_MB_SHIFT))&CMT_CMD2_MB_MASK) /*!< CMT_CMD2                                */
/* ------- CMD3 Bit Fields                          ------ */
#define CMT_CMD3_SB_MASK                         (0xFFUL << CMT_CMD3_SB_SHIFT)                       /*!< CMT_CMD3: SB Mask                       */
#define CMT_CMD3_SB_SHIFT                        0                                                   /*!< CMT_CMD3: SB Position                   */
#define CMT_CMD3_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD3_SB_SHIFT))&CMT_CMD3_SB_MASK) /*!< CMT_CMD3                                */
/* ------- CMD4 Bit Fields                          ------ */
#define CMT_CMD4_SB_MASK                         (0xFFUL << CMT_CMD4_SB_SHIFT)                       /*!< CMT_CMD4: SB Mask                       */
#define CMT_CMD4_SB_SHIFT                        0                                                   /*!< CMT_CMD4: SB Position                   */
#define CMT_CMD4_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD4_SB_SHIFT))&CMT_CMD4_SB_MASK) /*!< CMT_CMD4                                */
/* ------- PPS Bit Fields                           ------ */
#define CMT_PPS_PPSDIV_MASK                      (0x0FUL << CMT_PPS_PPSDIV_SHIFT)                    /*!< CMT_PPS: PPSDIV Mask                    */
#define CMT_PPS_PPSDIV_SHIFT                     0                                                   /*!< CMT_PPS: PPSDIV Position                */
#define CMT_PPS_PPSDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_PPS_PPSDIV_SHIFT))&CMT_PPS_PPSDIV_MASK) /*!< CMT_PPS                                 */
/* ------- DMA Bit Fields                           ------ */
#define CMT_DMA_DMA_MASK                         (0x01UL << CMT_DMA_DMA_SHIFT)                       /*!< CMT_DMA: DMA Mask                       */
#define CMT_DMA_DMA_SHIFT                        0                                                   /*!< CMT_DMA: DMA Position                   */
/**
 * @} */ /* End group CMT_Register_Masks_GROUP 
 */

/* CMT - Peripheral instance base addresses */
#define CMT_BasePtr                    0xFFFF8420UL //!< Peripheral base address
#define CMT                            ((CMT_Type *) CMT_BasePtr) //!< Freescale base pointer
#define CMT_BASE_PTR                   (CMT) //!< Freescale style base pointer
/**
 * @} */ /* End group CMT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer
* @brief C Struct for CRC
* @{
*/

/* ================================================================================ */
/* ================           CRC (file:CRC_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check
 */
/**
* @addtogroup CRC_structs_GROUP CRC struct
* @brief Struct for CRC
* @{
*/
typedef struct {                                /*       CRC Structure                                                */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CRC;                       /**< 0000: Data register                                                */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  CRCH;                /**< 0000: CRCH register                                                */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   CRCHU;            /**< 0000: CRCHU register                                               */
               __IO uint8_t   CRCHL;            /**< 0001: CRCHL register                                               */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  CRCL;                /**< 0002: CRCL register                                                */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   CRCLU;            /**< 0002: CRCLU register                                               */
               __IO uint8_t   CRCLL;            /**< 0003: CRCLL register                                               */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  GPOLY;                     /**< 0004: Polynomial register                                          */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYH;              /**< 0004: GPOLYH register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYHU;          /**< 0004: GPOLYHU register                                             */
               __IO uint8_t   GPOLYHL;          /**< 0005: GPOLYHL register                                             */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYL;              /**< 0006: GPOLYL register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYLU;          /**< 0006: GPOLYLU register                                             */
               __IO uint8_t   GPOLYLL;          /**< 0007: GPOLYLL register                                             */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  CTRL;                      /**< 0008: Control register                                             */
      __IO uint8_t   CTRLH;                     /**< 0008: Control register (byte access)                               */
   };
} CRC_Type;

/**
 * @} */ /* End group CRC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CRC_Register_Masks_GROUP CRC Register Masks
* @brief Register Masks for CRC
* @{
*/
/* ------- CRC Bit Fields                           ------ */
#define CRC_CRC_LL_MASK                          (0xFFUL << CRC_CRC_LL_SHIFT)                        /*!< CRC_CRC: LL Mask                        */
#define CRC_CRC_LL_SHIFT                         0                                                   /*!< CRC_CRC: LL Position                    */
#define CRC_CRC_LL(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_LL_SHIFT))&CRC_CRC_LL_MASK) /*!< CRC_CRC                                 */
#define CRC_CRC_LU_MASK                          (0xFFUL << CRC_CRC_LU_SHIFT)                        /*!< CRC_CRC: LU Mask                        */
#define CRC_CRC_LU_SHIFT                         8                                                   /*!< CRC_CRC: LU Position                    */
#define CRC_CRC_LU(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_LU_SHIFT))&CRC_CRC_LU_MASK) /*!< CRC_CRC                                 */
#define CRC_CRC_HL_MASK                          (0xFFUL << CRC_CRC_HL_SHIFT)                        /*!< CRC_CRC: HL Mask                        */
#define CRC_CRC_HL_SHIFT                         16                                                  /*!< CRC_CRC: HL Position                    */
#define CRC_CRC_HL(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HL_SHIFT))&CRC_CRC_HL_MASK) /*!< CRC_CRC                                 */
#define CRC_CRC_HU_MASK                          (0xFFUL << CRC_CRC_HU_SHIFT)                        /*!< CRC_CRC: HU Mask                        */
#define CRC_CRC_HU_SHIFT                         24                                                  /*!< CRC_CRC: HU Position                    */
#define CRC_CRC_HU(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HU_SHIFT))&CRC_CRC_HU_MASK) /*!< CRC_CRC                                 */
/* ------- CRCH Bit Fields                          ------ */
#define CRC_CRCH_CRCH_MASK                       (0xFFFFUL << CRC_CRCH_CRCH_SHIFT)                   /*!< CRC_CRCH: CRCH Mask                     */
#define CRC_CRCH_CRCH_SHIFT                      0                                                   /*!< CRC_CRCH: CRCH Position                 */
#define CRC_CRCH_CRCH(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CRCH_CRCH_SHIFT))&CRC_CRCH_CRCH_MASK) /*!< CRC_CRCH                                */
/* ------- CRCHU Bit Fields                         ------ */
#define CRC_CRCHU_CRCHU_MASK                     (0xFFUL << CRC_CRCHU_CRCHU_SHIFT)                   /*!< CRC_CRCHU: CRCHU Mask                   */
#define CRC_CRCHU_CRCHU_SHIFT                    0                                                   /*!< CRC_CRCHU: CRCHU Position               */
#define CRC_CRCHU_CRCHU(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCHU_CRCHU_SHIFT))&CRC_CRCHU_CRCHU_MASK) /*!< CRC_CRCHU                               */
/* ------- CRCHL Bit Fields                         ------ */
#define CRC_CRCHL_CRCHL_MASK                     (0xFFUL << CRC_CRCHL_CRCHL_SHIFT)                   /*!< CRC_CRCHL: CRCHL Mask                   */
#define CRC_CRCHL_CRCHL_SHIFT                    0                                                   /*!< CRC_CRCHL: CRCHL Position               */
#define CRC_CRCHL_CRCHL(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCHL_CRCHL_SHIFT))&CRC_CRCHL_CRCHL_MASK) /*!< CRC_CRCHL                               */
/* ------- CRCL Bit Fields                          ------ */
#define CRC_CRCL_CRCL_MASK                       (0xFFFFUL << CRC_CRCL_CRCL_SHIFT)                   /*!< CRC_CRCL: CRCL Mask                     */
#define CRC_CRCL_CRCL_SHIFT                      0                                                   /*!< CRC_CRCL: CRCL Position                 */
#define CRC_CRCL_CRCL(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CRCL_CRCL_SHIFT))&CRC_CRCL_CRCL_MASK) /*!< CRC_CRCL                                */
/* ------- CRCLU Bit Fields                         ------ */
#define CRC_CRCLU_CRCLU_MASK                     (0xFFUL << CRC_CRCLU_CRCLU_SHIFT)                   /*!< CRC_CRCLU: CRCLU Mask                   */
#define CRC_CRCLU_CRCLU_SHIFT                    0                                                   /*!< CRC_CRCLU: CRCLU Position               */
#define CRC_CRCLU_CRCLU(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCLU_CRCLU_SHIFT))&CRC_CRCLU_CRCLU_MASK) /*!< CRC_CRCLU                               */
/* ------- CRCLL Bit Fields                         ------ */
#define CRC_CRCLL_CRCLL_MASK                     (0xFFUL << CRC_CRCLL_CRCLL_SHIFT)                   /*!< CRC_CRCLL: CRCLL Mask                   */
#define CRC_CRCLL_CRCLL_SHIFT                    0                                                   /*!< CRC_CRCLL: CRCLL Position               */
#define CRC_CRCLL_CRCLL(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCLL_CRCLL_SHIFT))&CRC_CRCLL_CRCLL_MASK) /*!< CRC_CRCLL                               */
/* ------- GPOLY Bit Fields                         ------ */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFUL << CRC_GPOLY_LOW_SHIFT)                   /*!< CRC_GPOLY: LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      0                                                   /*!< CRC_GPOLY: LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK) /*!< CRC_GPOLY                               */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFFUL << CRC_GPOLY_HIGH_SHIFT)                  /*!< CRC_GPOLY: HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     16                                                  /*!< CRC_GPOLY: HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK) /*!< CRC_GPOLY                               */
/* ------- GPOLYH Bit Fields                        ------ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFUL << CRC_GPOLYH_GPOLYH_SHIFT)               /*!< CRC_GPOLYH: GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  0                                                   /*!< CRC_GPOLYH: GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK) /*!< CRC_GPOLYH                              */
/* ------- GPOLYHU Bit Fields                       ------ */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFUL << CRC_GPOLYHU_GPOLYHU_SHIFT)               /*!< CRC_GPOLYHU: GPOLYHU Mask               */
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0                                                   /*!< CRC_GPOLYHU: GPOLYHU Position           */
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK) /*!< CRC_GPOLYHU                             */
/* ------- GPOLYHL Bit Fields                       ------ */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFUL << CRC_GPOLYHL_GPOLYHL_SHIFT)               /*!< CRC_GPOLYHL: GPOLYHL Mask               */
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0                                                   /*!< CRC_GPOLYHL: GPOLYHL Position           */
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK) /*!< CRC_GPOLYHL                             */
/* ------- GPOLYL Bit Fields                        ------ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFUL << CRC_GPOLYL_GPOLYL_SHIFT)               /*!< CRC_GPOLYL: GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  0                                                   /*!< CRC_GPOLYL: GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK) /*!< CRC_GPOLYL                              */
/* ------- GPOLYLU Bit Fields                       ------ */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFUL << CRC_GPOLYLU_GPOLYLU_SHIFT)               /*!< CRC_GPOLYLU: GPOLYLU Mask               */
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0                                                   /*!< CRC_GPOLYLU: GPOLYLU Position           */
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK) /*!< CRC_GPOLYLU                             */
/* ------- GPOLYLL Bit Fields                       ------ */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFUL << CRC_GPOLYLL_GPOLYLL_SHIFT)               /*!< CRC_GPOLYLL: GPOLYLL Mask               */
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0                                                   /*!< CRC_GPOLYLL: GPOLYLL Position           */
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK) /*!< CRC_GPOLYLL                             */
/* ------- CTRL Bit Fields                          ------ */
#define CRC_CTRL_TCRC_MASK                       (0x01UL << CRC_CTRL_TCRC_SHIFT)                     /*!< CRC_CTRL: TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      8                                                   /*!< CRC_CTRL: TCRC Position                 */
#define CRC_CTRL_WAS_MASK                        (0x01UL << CRC_CTRL_WAS_SHIFT)                      /*!< CRC_CTRL: WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       9                                                   /*!< CRC_CTRL: WAS Position                  */
#define CRC_CTRL_FXOR_MASK                       (0x01UL << CRC_CTRL_FXOR_SHIFT)                     /*!< CRC_CTRL: FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      10                                                  /*!< CRC_CTRL: FXOR Position                 */
#define CRC_CTRL_TOTR_MASK                       (0x03UL << CRC_CTRL_TOTR_SHIFT)                     /*!< CRC_CTRL: TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      12                                                  /*!< CRC_CTRL: TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_TOT_MASK                        (0x03UL << CRC_CTRL_TOT_SHIFT)                      /*!< CRC_CTRL: TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       14                                                  /*!< CRC_CTRL: TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((uint16_t)(((uint16_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK) /*!< CRC_CTRL                                */
/* ------- CTRLH Bit Fields                         ------ */
#define CRC_CTRLH_TCRC_MASK                      (0x01UL << CRC_CTRLH_TCRC_SHIFT)                    /*!< CRC_CTRLH: TCRC Mask                    */
#define CRC_CTRLH_TCRC_SHIFT                     0                                                   /*!< CRC_CTRLH: TCRC Position                */
#define CRC_CTRLH_WAS_MASK                       (0x01UL << CRC_CTRLH_WAS_SHIFT)                     /*!< CRC_CTRLH: WAS Mask                     */
#define CRC_CTRLH_WAS_SHIFT                      1                                                   /*!< CRC_CTRLH: WAS Position                 */
#define CRC_CTRLH_FXOR_MASK                      (0x01UL << CRC_CTRLH_FXOR_SHIFT)                    /*!< CRC_CTRLH: FXOR Mask                    */
#define CRC_CTRLH_FXOR_SHIFT                     2                                                   /*!< CRC_CTRLH: FXOR Position                */
#define CRC_CTRLH_TOTR_MASK                      (0x03UL << CRC_CTRLH_TOTR_SHIFT)                    /*!< CRC_CTRLH: TOTR Mask                    */
#define CRC_CTRLH_TOTR_SHIFT                     4                                                   /*!< CRC_CTRLH: TOTR Position                */
#define CRC_CTRLH_TOTR(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLH_TOTR_SHIFT))&CRC_CTRLH_TOTR_MASK) /*!< CRC_CTRLH                               */
#define CRC_CTRLH_TOT_MASK                       (0x03UL << CRC_CTRLH_TOT_SHIFT)                     /*!< CRC_CTRLH: TOT Mask                     */
#define CRC_CTRLH_TOT_SHIFT                      6                                                   /*!< CRC_CTRLH: TOT Position                 */
#define CRC_CTRLH_TOT(x)                         (((uint8_t)(((uint8_t)(x))<<CRC_CTRLH_TOT_SHIFT))&CRC_CTRLH_TOT_MASK) /*!< CRC_CTRLH                               */
/**
 * @} */ /* End group CRC_Register_Masks_GROUP 
 */

/* CRC - Peripheral instance base addresses */
#define CRC_BasePtr                    0xFFFF8570UL //!< Peripheral base address
#define CRC                            ((CRC_Type *) CRC_BasePtr) //!< Freescale base pointer
#define CRC_BASE_PTR                   (CRC) //!< Freescale style base pointer
/**
 * @} */ /* End group CRC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DAC_Peripheral_access_layer_GROUP DAC Peripheral Access Layer
* @brief C Struct for DAC
* @{
*/

/* ================================================================================ */
/* ================           DAC0 (file:DAC0_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief 12-Bit Digital-to-Analog Converter
 */
/**
* @addtogroup DAC_structs_GROUP DAC struct
* @brief Struct for DAC
* @{
*/
typedef struct {                                /*       DAC0 Structure                                               */
   union {                                      /**< 0000: (size=0020)                                                  */
      struct {
         __IO uint8_t   DATH;                   /**< 0000: Data High Register                                           */
         __IO uint8_t   DATL;                   /**< 0001: Data Low Register                                            */
      } DAT[16];                                /**< 0000: (cluster: size=0x0020, 32)                                   */
      __IO uint16_t  DATA[16];                  /**< 0000: Data Register                                                */
   };
   __IO uint8_t   SR;                           /**< 0020: Status Register                                              */
   __IO uint8_t   C0;                           /**< 0021: Control Register 0                                           */
   __IO uint8_t   C1;                           /**< 0022: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0023: Control Register 2                                           */
} DAC_Type;

/**
 * @} */ /* End group DAC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DAC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DAC_Register_Masks_GROUP DAC Register Masks
* @brief Register Masks for DAC
* @{
*/
/* ------- DATH Bit Fields                          ------ */
#define DAC_DATH_DATA_MASK                       (0x0FUL << DAC_DATH_DATA_SHIFT)                     /*!< DAC0_DATH: DATA Mask                    */
#define DAC_DATH_DATA_SHIFT                      0                                                   /*!< DAC0_DATH: DATA Position                */
#define DAC_DATH_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA_SHIFT))&DAC_DATH_DATA_MASK) /*!< DAC0_DATH                               */
/* ------- DATL Bit Fields                          ------ */
#define DAC_DATL_DATA_MASK                       (0xFFUL << DAC_DATL_DATA_SHIFT)                     /*!< DAC0_DATL: DATA Mask                    */
#define DAC_DATL_DATA_SHIFT                      0                                                   /*!< DAC0_DATL: DATA Position                */
#define DAC_DATL_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA_SHIFT))&DAC_DATL_DATA_MASK) /*!< DAC0_DATL                               */
/* ------- DATA Bit Fields                          ------ */
#define DAC_DATA_DATA_MASK                       (0xFFFUL << DAC_DATA_DATA_SHIFT)                    /*!< DAC0_DATA: DATA Mask                    */
#define DAC_DATA_DATA_SHIFT                      0                                                   /*!< DAC0_DATA: DATA Position                */
#define DAC_DATA_DATA(x)                         (((uint16_t)(((uint16_t)(x))<<DAC_DATA_DATA_SHIFT))&DAC_DATA_DATA_MASK) /*!< DAC0_DATA                               */
/* ------- SR Bit Fields                            ------ */
#define DAC_SR_DACBFRPBF_MASK                    (0x01UL << DAC_SR_DACBFRPBF_SHIFT)                  /*!< DAC0_SR: DACBFRPBF Mask                 */
#define DAC_SR_DACBFRPBF_SHIFT                   0                                                   /*!< DAC0_SR: DACBFRPBF Position             */
#define DAC_SR_DACBFRPTF_MASK                    (0x01UL << DAC_SR_DACBFRPTF_SHIFT)                  /*!< DAC0_SR: DACBFRPTF Mask                 */
#define DAC_SR_DACBFRPTF_SHIFT                   1                                                   /*!< DAC0_SR: DACBFRPTF Position             */
#define DAC_SR_DACBFWMF_MASK                     (0x01UL << DAC_SR_DACBFWMF_SHIFT)                   /*!< DAC0_SR: DACBFWMF Mask                  */
#define DAC_SR_DACBFWMF_SHIFT                    2                                                   /*!< DAC0_SR: DACBFWMF Position              */
/* ------- C0 Bit Fields                            ------ */
#define DAC_C0_DACBBIEN_MASK                     (0x01UL << DAC_C0_DACBBIEN_SHIFT)                   /*!< DAC0_C0: DACBBIEN Mask                  */
#define DAC_C0_DACBBIEN_SHIFT                    0                                                   /*!< DAC0_C0: DACBBIEN Position              */
#define DAC_C0_DACBTIEN_MASK                     (0x01UL << DAC_C0_DACBTIEN_SHIFT)                   /*!< DAC0_C0: DACBTIEN Mask                  */
#define DAC_C0_DACBTIEN_SHIFT                    1                                                   /*!< DAC0_C0: DACBTIEN Position              */
#define DAC_C0_DACBWIEN_MASK                     (0x01UL << DAC_C0_DACBWIEN_SHIFT)                   /*!< DAC0_C0: DACBWIEN Mask                  */
#define DAC_C0_DACBWIEN_SHIFT                    2                                                   /*!< DAC0_C0: DACBWIEN Position              */
#define DAC_C0_LPEN_MASK                         (0x01UL << DAC_C0_LPEN_SHIFT)                       /*!< DAC0_C0: LPEN Mask                      */
#define DAC_C0_LPEN_SHIFT                        3                                                   /*!< DAC0_C0: LPEN Position                  */
#define DAC_C0_DACSWTRG_MASK                     (0x01UL << DAC_C0_DACSWTRG_SHIFT)                   /*!< DAC0_C0: DACSWTRG Mask                  */
#define DAC_C0_DACSWTRG_SHIFT                    4                                                   /*!< DAC0_C0: DACSWTRG Position              */
#define DAC_C0_DACTRGSEL_MASK                    (0x01UL << DAC_C0_DACTRGSEL_SHIFT)                  /*!< DAC0_C0: DACTRGSEL Mask                 */
#define DAC_C0_DACTRGSEL_SHIFT                   5                                                   /*!< DAC0_C0: DACTRGSEL Position             */
#define DAC_C0_DACRFS_MASK                       (0x01UL << DAC_C0_DACRFS_SHIFT)                     /*!< DAC0_C0: DACRFS Mask                    */
#define DAC_C0_DACRFS_SHIFT                      6                                                   /*!< DAC0_C0: DACRFS Position                */
#define DAC_C0_DACEN_MASK                        (0x01UL << DAC_C0_DACEN_SHIFT)                      /*!< DAC0_C0: DACEN Mask                     */
#define DAC_C0_DACEN_SHIFT                       7                                                   /*!< DAC0_C0: DACEN Position                 */
/* ------- C1 Bit Fields                            ------ */
#define DAC_C1_DACBFEN_MASK                      (0x01UL << DAC_C1_DACBFEN_SHIFT)                    /*!< DAC0_C1: DACBFEN Mask                   */
#define DAC_C1_DACBFEN_SHIFT                     0                                                   /*!< DAC0_C1: DACBFEN Position               */
#define DAC_C1_DACBFMD_MASK                      (0x03UL << DAC_C1_DACBFMD_SHIFT)                    /*!< DAC0_C1: DACBFMD Mask                   */
#define DAC_C1_DACBFMD_SHIFT                     1                                                   /*!< DAC0_C1: DACBFMD Position               */
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DACBFWM_MASK                      (0x03UL << DAC_C1_DACBFWM_SHIFT)                    /*!< DAC0_C1: DACBFWM Mask                   */
#define DAC_C1_DACBFWM_SHIFT                     3                                                   /*!< DAC0_C1: DACBFWM Position               */
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFWM_SHIFT))&DAC_C1_DACBFWM_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DMAEN_MASK                        (0x01UL << DAC_C1_DMAEN_SHIFT)                      /*!< DAC0_C1: DMAEN Mask                     */
#define DAC_C1_DMAEN_SHIFT                       7                                                   /*!< DAC0_C1: DMAEN Position                 */
/* ------- C2 Bit Fields                            ------ */
#define DAC_C2_DACBFUP_MASK                      (0x0FUL << DAC_C2_DACBFUP_SHIFT)                    /*!< DAC0_C2: DACBFUP Mask                   */
#define DAC_C2_DACBFUP_SHIFT                     0                                                   /*!< DAC0_C2: DACBFUP Position               */
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK) /*!< DAC0_C2                                 */
#define DAC_C2_DACBFRP_MASK                      (0x0FUL << DAC_C2_DACBFRP_SHIFT)                    /*!< DAC0_C2: DACBFRP Mask                   */
#define DAC_C2_DACBFRP_SHIFT                     4                                                   /*!< DAC0_C2: DACBFRP Position               */
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK) /*!< DAC0_C2                                 */
/**
 * @} */ /* End group DAC_Register_Masks_GROUP 
 */

/* DAC0 - Peripheral instance base addresses */
#define DAC0_BasePtr                   0xFFFF8500UL //!< Peripheral base address
#define DAC0                           ((DAC_Type *) DAC0_BasePtr) //!< Freescale base pointer
#define DAC0_BASE_PTR                  (DAC0) //!< Freescale style base pointer
/**
 * @} */ /* End group DAC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA_Peripheral_access_layer_GROUP DMA Peripheral Access Layer
* @brief C Struct for DMA
* @{
*/

/* ================================================================================ */
/* ================           DMA0 (file:DMA0_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief DMA Controller Module
 */
/**
* @addtogroup DMA_structs_GROUP DMA struct
* @brief Struct for DMA
* @{
*/
typedef struct {                                /*       DMA0 Structure                                               */
   __IO uint32_t  REQC;                         /**< 0000: Request Control Register                                     */
   __I  uint32_t  RESERVED0[63];               
   struct {
      __IO uint32_t  SAR;                       /**< 0100: Source Address Register                                      */
      __IO uint32_t  DAR;                       /**< 0104: Destination Address Register                                 */
      union {                                   /**< 0100: (size=0004)                                                  */
         __IO uint32_t  DSR_BCR;                /**< 0108: Byte Count and Status Register                               */
         __IO uint8_t   DSR;                    /**< 0108: Status Register                                              */
      };
      __IO uint32_t  DCR;                       /**< 010C: Control Register                                             */
   } CH[4];                                     /**< 0100: (cluster: size=0x0040, 64)                                   */
} DMA_Type;

/**
 * @} */ /* End group DMA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA_Register_Masks_GROUP DMA Register Masks
* @brief Register Masks for DMA
* @{
*/
/* ------- REQC Bit Fields                          ------ */
#define DMA_REQC_DMAC3_MASK                      (0x0FUL << DMA_REQC_DMAC3_SHIFT)                    /*!< DMA0_REQC: DMAC3 Mask                   */
#define DMA_REQC_DMAC3_SHIFT                     0                                                   /*!< DMA0_REQC: DMAC3 Position               */
#define DMA_REQC_DMAC3(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_REQC_DMAC3_SHIFT))&DMA_REQC_DMAC3_MASK) /*!< DMA0_REQC                               */
#define DMA_REQC_CFSM3_MASK                      (0x01UL << DMA_REQC_CFSM3_SHIFT)                    /*!< DMA0_REQC: CFSM3 Mask                   */
#define DMA_REQC_CFSM3_SHIFT                     7                                                   /*!< DMA0_REQC: CFSM3 Position               */
#define DMA_REQC_DMAC2_MASK                      (0x0FUL << DMA_REQC_DMAC2_SHIFT)                    /*!< DMA0_REQC: DMAC2 Mask                   */
#define DMA_REQC_DMAC2_SHIFT                     8                                                   /*!< DMA0_REQC: DMAC2 Position               */
#define DMA_REQC_DMAC2(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_REQC_DMAC2_SHIFT))&DMA_REQC_DMAC2_MASK) /*!< DMA0_REQC                               */
#define DMA_REQC_CFSM2_MASK                      (0x01UL << DMA_REQC_CFSM2_SHIFT)                    /*!< DMA0_REQC: CFSM2 Mask                   */
#define DMA_REQC_CFSM2_SHIFT                     15                                                  /*!< DMA0_REQC: CFSM2 Position               */
#define DMA_REQC_DMAC1_MASK                      (0x0FUL << DMA_REQC_DMAC1_SHIFT)                    /*!< DMA0_REQC: DMAC1 Mask                   */
#define DMA_REQC_DMAC1_SHIFT                     16                                                  /*!< DMA0_REQC: DMAC1 Position               */
#define DMA_REQC_DMAC1(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_REQC_DMAC1_SHIFT))&DMA_REQC_DMAC1_MASK) /*!< DMA0_REQC                               */
#define DMA_REQC_CFSM1_MASK                      (0x01UL << DMA_REQC_CFSM1_SHIFT)                    /*!< DMA0_REQC: CFSM1 Mask                   */
#define DMA_REQC_CFSM1_SHIFT                     23                                                  /*!< DMA0_REQC: CFSM1 Position               */
#define DMA_REQC_DMAC0_MASK                      (0x0FUL << DMA_REQC_DMAC0_SHIFT)                    /*!< DMA0_REQC: DMAC0 Mask                   */
#define DMA_REQC_DMAC0_SHIFT                     24                                                  /*!< DMA0_REQC: DMAC0 Position               */
#define DMA_REQC_DMAC0(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_REQC_DMAC0_SHIFT))&DMA_REQC_DMAC0_MASK) /*!< DMA0_REQC                               */
#define DMA_REQC_CFSM0_MASK                      (0x01UL << DMA_REQC_CFSM0_SHIFT)                    /*!< DMA0_REQC: CFSM0 Mask                   */
#define DMA_REQC_CFSM0_SHIFT                     31                                                  /*!< DMA0_REQC: CFSM0 Position               */
/* ------- SAR Bit Fields                           ------ */
#define DMA_SAR_SAR_MASK                         (0xFFFFFFFFUL << DMA_SAR_SAR_SHIFT)                 /*!< DMA0_SAR: SAR Mask                      */
#define DMA_SAR_SAR_SHIFT                        0                                                   /*!< DMA0_SAR: SAR Position                  */
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_SAR_SAR_SHIFT))&DMA_SAR_SAR_MASK) /*!< DMA0_SAR                                */
/* ------- DAR Bit Fields                           ------ */
#define DMA_DAR_DAR_MASK                         (0xFFFFFFFFUL << DMA_DAR_DAR_SHIFT)                 /*!< DMA0_DAR: DAR Mask                      */
#define DMA_DAR_DAR_SHIFT                        0                                                   /*!< DMA0_DAR: DAR Position                  */
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DAR_DAR_SHIFT))&DMA_DAR_DAR_MASK) /*!< DMA0_DAR                                */
/* ------- DSR_BCR Bit Fields                       ------ */
#define DMA_DSR_BCR_BCR_MASK                     (0xFFFFFFUL << DMA_DSR_BCR_BCR_SHIFT)               /*!< DMA0_DSR_BCR: BCR Mask                  */
#define DMA_DSR_BCR_BCR_SHIFT                    0                                                   /*!< DMA0_DSR_BCR: BCR Position              */
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BCR_SHIFT))&DMA_DSR_BCR_BCR_MASK) /*!< DMA0_DSR_BCR                            */
#define DMA_DSR_BCR_DSR_MASK                     (0xFFUL << DMA_DSR_BCR_DSR_SHIFT)                   /*!< DMA0_DSR_BCR: DSR Mask                  */
#define DMA_DSR_BCR_DSR_SHIFT                    24                                                  /*!< DMA0_DSR_BCR: DSR Position              */
#define DMA_DSR_BCR_DSR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_DSR_SHIFT))&DMA_DSR_BCR_DSR_MASK) /*!< DMA0_DSR_BCR                            */
/* ------- DSR Bit Fields                           ------ */
#define DMA_DSR_DONE_MASK                        (0x01UL << DMA_DSR_DONE_SHIFT)                      /*!< DMA0_DSR: DONE Mask                     */
#define DMA_DSR_DONE_SHIFT                       0                                                   /*!< DMA0_DSR: DONE Position                 */
#define DMA_DSR_BSY_MASK                         (0x01UL << DMA_DSR_BSY_SHIFT)                       /*!< DMA0_DSR: BSY Mask                      */
#define DMA_DSR_BSY_SHIFT                        1                                                   /*!< DMA0_DSR: BSY Position                  */
#define DMA_DSR_REQ_MASK                         (0x01UL << DMA_DSR_REQ_SHIFT)                       /*!< DMA0_DSR: REQ Mask                      */
#define DMA_DSR_REQ_SHIFT                        2                                                   /*!< DMA0_DSR: REQ Position                  */
#define DMA_DSR_BED_MASK                         (0x01UL << DMA_DSR_BED_SHIFT)                       /*!< DMA0_DSR: BED Mask                      */
#define DMA_DSR_BED_SHIFT                        4                                                   /*!< DMA0_DSR: BED Position                  */
#define DMA_DSR_BES_MASK                         (0x01UL << DMA_DSR_BES_SHIFT)                       /*!< DMA0_DSR: BES Mask                      */
#define DMA_DSR_BES_SHIFT                        5                                                   /*!< DMA0_DSR: BES Position                  */
#define DMA_DSR_CE_MASK                          (0x01UL << DMA_DSR_CE_SHIFT)                        /*!< DMA0_DSR: CE Mask                       */
#define DMA_DSR_CE_SHIFT                         6                                                   /*!< DMA0_DSR: CE Position                   */
/* ------- DCR Bit Fields                           ------ */
#define DMA_DCR_LCH2_MASK                        (0x03UL << DMA_DCR_LCH2_SHIFT)                      /*!< DMA0_DCR: LCH2 Mask                     */
#define DMA_DCR_LCH2_SHIFT                       0                                                   /*!< DMA0_DCR: LCH2 Position                 */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH2_SHIFT))&DMA_DCR_LCH2_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_LCH1_MASK                        (0x03UL << DMA_DCR_LCH1_SHIFT)                      /*!< DMA0_DCR: LCH1 Mask                     */
#define DMA_DCR_LCH1_SHIFT                       2                                                   /*!< DMA0_DCR: LCH1 Position                 */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH1_SHIFT))&DMA_DCR_LCH1_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_LINKCC_MASK                      (0x03UL << DMA_DCR_LINKCC_SHIFT)                    /*!< DMA0_DCR: LINKCC Mask                   */
#define DMA_DCR_LINKCC_SHIFT                     4                                                   /*!< DMA0_DCR: LINKCC Position               */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LINKCC_SHIFT))&DMA_DCR_LINKCC_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_D_REQ_MASK                       (0x01UL << DMA_DCR_D_REQ_SHIFT)                     /*!< DMA0_DCR: D_REQ Mask                    */
#define DMA_DCR_D_REQ_SHIFT                      7                                                   /*!< DMA0_DCR: D_REQ Position                */
#define DMA_DCR_DMOD_MASK                        (0x0FUL << DMA_DCR_DMOD_SHIFT)                      /*!< DMA0_DCR: DMOD Mask                     */
#define DMA_DCR_DMOD_SHIFT                       8                                                   /*!< DMA0_DCR: DMOD Position                 */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DMOD_SHIFT))&DMA_DCR_DMOD_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_SMOD_MASK                        (0x0FUL << DMA_DCR_SMOD_SHIFT)                      /*!< DMA0_DCR: SMOD Mask                     */
#define DMA_DCR_SMOD_SHIFT                       12                                                  /*!< DMA0_DCR: SMOD Position                 */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SMOD_SHIFT))&DMA_DCR_SMOD_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_START_MASK                       (0x01UL << DMA_DCR_START_SHIFT)                     /*!< DMA0_DCR: START Mask                    */
#define DMA_DCR_START_SHIFT                      16                                                  /*!< DMA0_DCR: START Position                */
#define DMA_DCR_DSIZE_MASK                       (0x03UL << DMA_DCR_DSIZE_SHIFT)                     /*!< DMA0_DCR: DSIZE Mask                    */
#define DMA_DCR_DSIZE_SHIFT                      17                                                  /*!< DMA0_DCR: DSIZE Position                */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DSIZE_SHIFT))&DMA_DCR_DSIZE_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_DINC_MASK                        (0x01UL << DMA_DCR_DINC_SHIFT)                      /*!< DMA0_DCR: DINC Mask                     */
#define DMA_DCR_DINC_SHIFT                       19                                                  /*!< DMA0_DCR: DINC Position                 */
#define DMA_DCR_SSIZE_MASK                       (0x03UL << DMA_DCR_SSIZE_SHIFT)                     /*!< DMA0_DCR: SSIZE Mask                    */
#define DMA_DCR_SSIZE_SHIFT                      20                                                  /*!< DMA0_DCR: SSIZE Position                */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SSIZE_SHIFT))&DMA_DCR_SSIZE_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_SINC_MASK                        (0x01UL << DMA_DCR_SINC_SHIFT)                      /*!< DMA0_DCR: SINC Mask                     */
#define DMA_DCR_SINC_SHIFT                       22                                                  /*!< DMA0_DCR: SINC Position                 */
#define DMA_DCR_BWC_MASK                         (0x07UL << DMA_DCR_BWC_SHIFT)                       /*!< DMA0_DCR: BWC Mask                      */
#define DMA_DCR_BWC_SHIFT                        25                                                  /*!< DMA0_DCR: BWC Position                  */
#define DMA_DCR_BWC(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DCR_BWC_SHIFT))&DMA_DCR_BWC_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_AA_MASK                          (0x01UL << DMA_DCR_AA_SHIFT)                        /*!< DMA0_DCR: AA Mask                       */
#define DMA_DCR_AA_SHIFT                         28                                                  /*!< DMA0_DCR: AA Position                   */
#define DMA_DCR_CS_MASK                          (0x01UL << DMA_DCR_CS_SHIFT)                        /*!< DMA0_DCR: CS Mask                       */
#define DMA_DCR_CS_SHIFT                         29                                                  /*!< DMA0_DCR: CS Position                   */
#define DMA_DCR_EEXT_MASK                        (0x01UL << DMA_DCR_EEXT_SHIFT)                      /*!< DMA0_DCR: EEXT Mask                     */
#define DMA_DCR_EEXT_SHIFT                       30                                                  /*!< DMA0_DCR: EEXT Position                 */
#define DMA_DCR_INT_MASK                         (0x01UL << DMA_DCR_INT_SHIFT)                       /*!< DMA0_DCR: INT Mask                      */
#define DMA_DCR_INT_SHIFT                        31                                                  /*!< DMA0_DCR: INT Position                  */
/**
 * @} */ /* End group DMA_Register_Masks_GROUP 
 */

/* DMA0 - Peripheral instance base addresses */
#define DMA0_BasePtr                   0xFFFFE400UL //!< Peripheral base address
#define DMA0                           ((DMA_Type *) DMA0_BasePtr) //!< Freescale base pointer
#define DMA0_BASE_PTR                  (DMA0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FB_Peripheral_access_layer_GROUP FB Peripheral Access Layer
* @brief C Struct for FB
* @{
*/

/* ================================================================================ */
/* ================           FB (file:FB_MCF51)                   ================ */
/* ================================================================================ */

/**
 * @brief FlexBus external bus interface
 */
/**
* @addtogroup FB_structs_GROUP FB struct
* @brief Struct for FB
* @{
*/
typedef struct {                                /*       FB Structure                                                 */
   struct {
      __IO uint32_t  CSAR;                      /**< 0000: Chip Select Address Register                                 */
      __IO uint32_t  CSMR;                      /**< 0004: Chip Select Mask Register                                    */
      __IO uint32_t  CSCR;                      /**< 0008: Chip Select Control Register                                 */
   } CS[2];                                     /**< 0000: (cluster: size=0x0018, 24)                                   */
} FB_Type;

/**
 * @} */ /* End group FB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FB' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FB_Register_Masks_GROUP FB Register Masks
* @brief Register Masks for FB
* @{
*/
/* ------- CSAR Bit Fields                          ------ */
#define FB_CSAR_BA_MASK                          (0xFFFFUL << FB_CSAR_BA_SHIFT)                      /*!< FB_CSAR: BA Mask                        */
#define FB_CSAR_BA_SHIFT                         16                                                  /*!< FB_CSAR: BA Position                    */
#define FB_CSAR_BA(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSAR_BA_SHIFT))&FB_CSAR_BA_MASK) /*!< FB_CSAR                                 */
/* ------- CSMR Bit Fields                          ------ */
#define FB_CSMR_V_MASK                           (0x01UL << FB_CSMR_V_SHIFT)                         /*!< FB_CSMR: V Mask                         */
#define FB_CSMR_V_SHIFT                          0                                                   /*!< FB_CSMR: V Position                     */
#define FB_CSMR_WP_MASK                          (0x01UL << FB_CSMR_WP_SHIFT)                        /*!< FB_CSMR: WP Mask                        */
#define FB_CSMR_WP_SHIFT                         8                                                   /*!< FB_CSMR: WP Position                    */
#define FB_CSMR_BAM_MASK                         (0xFFFFUL << FB_CSMR_BAM_SHIFT)                     /*!< FB_CSMR: BAM Mask                       */
#define FB_CSMR_BAM_SHIFT                        16                                                  /*!< FB_CSMR: BAM Position                   */
#define FB_CSMR_BAM(x)                           (((uint32_t)(((uint32_t)(x))<<FB_CSMR_BAM_SHIFT))&FB_CSMR_BAM_MASK) /*!< FB_CSMR                                 */
/* ------- CSCR Bit Fields                          ------ */
#define FB_CSCR_PS_MASK                          (0x03UL << FB_CSCR_PS_SHIFT)                        /*!< FB_CSCR: PS Mask                        */
#define FB_CSCR_PS_SHIFT                         6                                                   /*!< FB_CSCR: PS Position                    */
#define FB_CSCR_PS(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_PS_SHIFT))&FB_CSCR_PS_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_AA_MASK                          (0x01UL << FB_CSCR_AA_SHIFT)                        /*!< FB_CSCR: AA Mask                        */
#define FB_CSCR_AA_SHIFT                         8                                                   /*!< FB_CSCR: AA Position                    */
#define FB_CSCR_MUX_MASK                         (0x01UL << FB_CSCR_MUX_SHIFT)                       /*!< FB_CSCR: MUX Mask                       */
#define FB_CSCR_MUX_SHIFT                        9                                                   /*!< FB_CSCR: MUX Position                   */
#define FB_CSCR_WS_MASK                          (0x3FUL << FB_CSCR_WS_SHIFT)                        /*!< FB_CSCR: WS Mask                        */
#define FB_CSCR_WS_SHIFT                         10                                                  /*!< FB_CSCR: WS Position                    */
#define FB_CSCR_WS(x)                            (((uint32_t)(((uint32_t)(x))<<FB_CSCR_WS_SHIFT))&FB_CSCR_WS_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_WRAH_MASK                        (0x03UL << FB_CSCR_WRAH_SHIFT)                      /*!< FB_CSCR: WRAH Mask                      */
#define FB_CSCR_WRAH_SHIFT                       16                                                  /*!< FB_CSCR: WRAH Position                  */
#define FB_CSCR_WRAH(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_WRAH_SHIFT))&FB_CSCR_WRAH_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_RDAH_MASK                        (0x03UL << FB_CSCR_RDAH_SHIFT)                      /*!< FB_CSCR: RDAH Mask                      */
#define FB_CSCR_RDAH_SHIFT                       18                                                  /*!< FB_CSCR: RDAH Position                  */
#define FB_CSCR_RDAH(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_RDAH_SHIFT))&FB_CSCR_RDAH_MASK) /*!< FB_CSCR                                 */
#define FB_CSCR_ASET_MASK                        (0x03UL << FB_CSCR_ASET_SHIFT)                      /*!< FB_CSCR: ASET Mask                      */
#define FB_CSCR_ASET_SHIFT                       20                                                  /*!< FB_CSCR: ASET Position                  */
#define FB_CSCR_ASET(x)                          (((uint32_t)(((uint32_t)(x))<<FB_CSCR_ASET_SHIFT))&FB_CSCR_ASET_MASK) /*!< FB_CSCR                                 */
/**
 * @} */ /* End group FB_Register_Masks_GROUP 
 */

/* FB - Peripheral instance base addresses */
#define FB_BasePtr                     0xFFFFE800UL //!< Peripheral base address
#define FB                             ((FB_Type *) FB_BasePtr) //!< Freescale base pointer
#define FB_BASE_PTR                    (FB) //!< Freescale style base pointer
/**
 * @} */ /* End group FB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTFL_Peripheral_access_layer_GROUP FTFL Peripheral Access Layer
* @brief C Struct for FTFL
* @{
*/

/* ================================================================================ */
/* ================           FTFL (file:FTFL_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
* @addtogroup FTFL_structs_GROUP FTFL struct
* @brief Struct for FTFL
* @{
*/
typedef struct {                                /*       FTFL Structure                                               */
   __I  uint8_t   FOPT;                         /**< 0000: Flash Option Register                                        */
   __I  uint8_t   FSEC;                         /**< 0001: Flash Security Register                                      */
   __IO uint8_t   FCNFG;                        /**< 0002: Flash Configuration Register                                 */
   __IO uint8_t   FSTAT;                        /**< 0003: Flash Status Register                                        */
   __IO uint8_t   FCCOB0;                       /**< 0004: FCCOB 0 - Usually FCMD (Flash command)                       */
   __IO uint8_t   FCCOB1;                       /**< 0005: FCCOB 1 - Usually Flash address [23..16]                     */
   __IO uint8_t   FCCOB2;                       /**< 0006: FCCOB 2 - Usually Flash address [15..8]                      */
   __IO uint8_t   FCCOB3;                       /**< 0007: FCCOB 3 - Usually Flash address [7..0]                       */
   __IO uint8_t   FCCOB4;                       /**< 0008: FCCOB 4 - Usually Data Byte 0                                */
   __IO uint8_t   FCCOB5;                       /**< 0009: FCCOB 5 - Usually Data Byte 1                                */
   __IO uint8_t   FCCOB6;                       /**< 000A: FCCOB 6 - Usually Data Byte 2                                */
   __IO uint8_t   FCCOB7;                       /**< 000B: FCCOB 7 - Usually Data Byte 3                                */
   __IO uint8_t   FCCOB8;                       /**< 000C: FCCOB 8 - Usually Data Byte 4                                */
   __IO uint8_t   FCCOB9;                       /**< 000D: FCCOB 9 - Usually Data Byte 5                                */
   __IO uint8_t   FCCOBA;                       /**< 000E: FCCOB A - Usually Data Byte 6                                */
   __IO uint8_t   FCCOBB;                       /**< 000F: FCCOB B - Usually Data Byte 7                                */
   __IO uint8_t   FPROT0;                       /**< 0010: Program Flash Protection                                     */
   __IO uint8_t   FPROT1;                       /**< 0011: Program Flash Protection                                     */
   __IO uint8_t   FPROT2;                       /**< 0012: Program Flash Protection                                     */
   __IO uint8_t   FPROT3;                       /**< 0013: Program Flash Protection                                     */
   __IO uint8_t   FDPROT;                       /**< 0014: Data Flash Protection Register                               */
   __IO uint8_t   FEPROT;                       /**< 0015: EEPROM Protection Register                                   */
} FTFL_Type;

/**
 * @} */ /* End group FTFL_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFL' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTFL_Register_Masks_GROUP FTFL Register Masks
* @brief Register Masks for FTFL
* @{
*/
/* ------- FOPT Bit Fields                          ------ */
#define FTFL_FOPT_OPT_MASK                       (0xFFUL << FTFL_FOPT_OPT_SHIFT)                     /*!< FTFL_FOPT: OPT Mask                     */
#define FTFL_FOPT_OPT_SHIFT                      0                                                   /*!< FTFL_FOPT: OPT Position                 */
#define FTFL_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FOPT_OPT_SHIFT))&FTFL_FOPT_OPT_MASK) /*!< FTFL_FOPT                               */
/* ------- FSEC Bit Fields                          ------ */
#define FTFL_FSEC_SEC_MASK                       (0x03UL << FTFL_FSEC_SEC_SHIFT)                     /*!< FTFL_FSEC: SEC Mask                     */
#define FTFL_FSEC_SEC_SHIFT                      0                                                   /*!< FTFL_FSEC: SEC Position                 */
#define FTFL_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_SEC_SHIFT))&FTFL_FSEC_SEC_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_FSLACC_MASK                    (0x03UL << FTFL_FSEC_FSLACC_SHIFT)                  /*!< FTFL_FSEC: FSLACC Mask                  */
#define FTFL_FSEC_FSLACC_SHIFT                   2                                                   /*!< FTFL_FSEC: FSLACC Position              */
#define FTFL_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_FSLACC_SHIFT))&FTFL_FSEC_FSLACC_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_MEEN_MASK                      (0x03UL << FTFL_FSEC_MEEN_SHIFT)                    /*!< FTFL_FSEC: MEEN Mask                    */
#define FTFL_FSEC_MEEN_SHIFT                     4                                                   /*!< FTFL_FSEC: MEEN Position                */
#define FTFL_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_MEEN_SHIFT))&FTFL_FSEC_MEEN_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_KEYEN_MASK                     (0x03UL << FTFL_FSEC_KEYEN_SHIFT)                   /*!< FTFL_FSEC: KEYEN Mask                   */
#define FTFL_FSEC_KEYEN_SHIFT                    6                                                   /*!< FTFL_FSEC: KEYEN Position               */
#define FTFL_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_KEYEN_SHIFT))&FTFL_FSEC_KEYEN_MASK) /*!< FTFL_FSEC                               */
/* ------- FCNFG Bit Fields                         ------ */
#define FTFL_FCNFG_EEERDY_MASK                   (0x01UL << FTFL_FCNFG_EEERDY_SHIFT)                 /*!< FTFL_FCNFG: EEERDY Mask                 */
#define FTFL_FCNFG_EEERDY_SHIFT                  0                                                   /*!< FTFL_FCNFG: EEERDY Position             */
#define FTFL_FCNFG_RAMRDY_MASK                   (0x01UL << FTFL_FCNFG_RAMRDY_SHIFT)                 /*!< FTFL_FCNFG: RAMRDY Mask                 */
#define FTFL_FCNFG_RAMRDY_SHIFT                  1                                                   /*!< FTFL_FCNFG: RAMRDY Position             */
#define FTFL_FCNFG_PFLSH_MASK                    (0x01UL << FTFL_FCNFG_PFLSH_SHIFT)                  /*!< FTFL_FCNFG: PFLSH Mask                  */
#define FTFL_FCNFG_PFLSH_SHIFT                   2                                                   /*!< FTFL_FCNFG: PFLSH Position              */
#define FTFL_FCNFG_SWAP_MASK                     (0x01UL << FTFL_FCNFG_SWAP_SHIFT)                   /*!< FTFL_FCNFG: SWAP Mask                   */
#define FTFL_FCNFG_SWAP_SHIFT                    3                                                   /*!< FTFL_FCNFG: SWAP Position               */
#define FTFL_FCNFG_ERSSUSP_MASK                  (0x01UL << FTFL_FCNFG_ERSSUSP_SHIFT)                /*!< FTFL_FCNFG: ERSSUSP Mask                */
#define FTFL_FCNFG_ERSSUSP_SHIFT                 4                                                   /*!< FTFL_FCNFG: ERSSUSP Position            */
#define FTFL_FCNFG_ERSAREQ_MASK                  (0x01UL << FTFL_FCNFG_ERSAREQ_SHIFT)                /*!< FTFL_FCNFG: ERSAREQ Mask                */
#define FTFL_FCNFG_ERSAREQ_SHIFT                 5                                                   /*!< FTFL_FCNFG: ERSAREQ Position            */
#define FTFL_FCNFG_RDCOLLIE_MASK                 (0x01UL << FTFL_FCNFG_RDCOLLIE_SHIFT)               /*!< FTFL_FCNFG: RDCOLLIE Mask               */
#define FTFL_FCNFG_RDCOLLIE_SHIFT                6                                                   /*!< FTFL_FCNFG: RDCOLLIE Position           */
#define FTFL_FCNFG_CCIE_MASK                     (0x01UL << FTFL_FCNFG_CCIE_SHIFT)                   /*!< FTFL_FCNFG: CCIE Mask                   */
#define FTFL_FCNFG_CCIE_SHIFT                    7                                                   /*!< FTFL_FCNFG: CCIE Position               */
/* ------- FSTAT Bit Fields                         ------ */
#define FTFL_FSTAT_MGSTAT0_MASK                  (0x01UL << FTFL_FSTAT_MGSTAT0_SHIFT)                /*!< FTFL_FSTAT: MGSTAT0 Mask                */
#define FTFL_FSTAT_MGSTAT0_SHIFT                 0                                                   /*!< FTFL_FSTAT: MGSTAT0 Position            */
#define FTFL_FSTAT_FPVIOL_MASK                   (0x01UL << FTFL_FSTAT_FPVIOL_SHIFT)                 /*!< FTFL_FSTAT: FPVIOL Mask                 */
#define FTFL_FSTAT_FPVIOL_SHIFT                  4                                                   /*!< FTFL_FSTAT: FPVIOL Position             */
#define FTFL_FSTAT_ACCERR_MASK                   (0x01UL << FTFL_FSTAT_ACCERR_SHIFT)                 /*!< FTFL_FSTAT: ACCERR Mask                 */
#define FTFL_FSTAT_ACCERR_SHIFT                  5                                                   /*!< FTFL_FSTAT: ACCERR Position             */
#define FTFL_FSTAT_RDCOLERR_MASK                 (0x01UL << FTFL_FSTAT_RDCOLERR_SHIFT)               /*!< FTFL_FSTAT: RDCOLERR Mask               */
#define FTFL_FSTAT_RDCOLERR_SHIFT                6                                                   /*!< FTFL_FSTAT: RDCOLERR Position           */
#define FTFL_FSTAT_CCIF_MASK                     (0x01UL << FTFL_FSTAT_CCIF_SHIFT)                   /*!< FTFL_FSTAT: CCIF Mask                   */
#define FTFL_FSTAT_CCIF_SHIFT                    7                                                   /*!< FTFL_FSTAT: CCIF Position               */
/* ------- FCCOB Bit Fields                         ------ */
#define FTFL_FCCOB_CCOBn_MASK                    (0xFFUL << FTFL_FCCOB_CCOBn_SHIFT)                  /*!< FTFL_FCCOB: CCOBn Mask                  */
#define FTFL_FCCOB_CCOBn_SHIFT                   0                                                   /*!< FTFL_FCCOB: CCOBn Position              */
#define FTFL_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB_CCOBn_SHIFT))&FTFL_FCCOB_CCOBn_MASK) /*!< FTFL_FCCOB                              */
/* ------- FPROT Bit Fields                         ------ */
#define FTFL_FPROT_PROT_MASK                     (0xFFUL << FTFL_FPROT_PROT_SHIFT)                   /*!< FTFL_FPROT: PROT Mask                   */
#define FTFL_FPROT_PROT_SHIFT                    0                                                   /*!< FTFL_FPROT: PROT Position               */
#define FTFL_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT_PROT_SHIFT))&FTFL_FPROT_PROT_MASK) /*!< FTFL_FPROT                              */
/* ------- FDPROT Bit Fields                        ------ */
#define FTFL_FDPROT_DPROT_MASK                   (0xFFUL << FTFL_FDPROT_DPROT_SHIFT)                 /*!< FTFL_FDPROT: DPROT Mask                 */
#define FTFL_FDPROT_DPROT_SHIFT                  0                                                   /*!< FTFL_FDPROT: DPROT Position             */
#define FTFL_FDPROT_DPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FDPROT_DPROT_SHIFT))&FTFL_FDPROT_DPROT_MASK) /*!< FTFL_FDPROT                             */
/* ------- FEPROT Bit Fields                        ------ */
#define FTFL_FEPROT_EPROT_MASK                   (0xFFUL << FTFL_FEPROT_EPROT_SHIFT)                 /*!< FTFL_FEPROT: EPROT Mask                 */
#define FTFL_FEPROT_EPROT_SHIFT                  0                                                   /*!< FTFL_FEPROT: EPROT Position             */
#define FTFL_FEPROT_EPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FEPROT_EPROT_SHIFT))&FTFL_FEPROT_EPROT_MASK) /*!< FTFL_FEPROT                             */
/**
 * @} */ /* End group FTFL_Register_Masks_GROUP 
 */

/* FTFL - Peripheral instance base addresses */
#define FTFL_BasePtr                   0xFFFF84E0UL //!< Peripheral base address
#define FTFL                           ((FTFL_Type *) FTFL_BasePtr) //!< Freescale base pointer
#define FTFL_BASE_PTR                  (FTFL) //!< Freescale style base pointer
/**
 * @} */ /* End group FTFL_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM0 (file:FTM0_2CH_MCF51)           ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM0 Structure                                               */
   __IO uint8_t   SC;                           /**< 0000: Status and Control                                           */
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  CNT;                       /**< 0001: Counter                                                      */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   CNTH;                   /**< 0001: Counter High                                                 */
         __IO uint8_t   CNTL;                   /**< 0002: Counter Low                                                  */
      };
   };
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  MOD;                       /**< 0003: Modulo High                                                  */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   MODH;                   /**< 0003: Modulo High                                                  */
         __IO uint8_t   MODL;                   /**< 0004: Modulo Low                                                   */
      };
   };
   struct {
      __IO uint8_t   CnSC;                      /**< 0005: Channel  Status and Control                                  */
      union {                                   /**< 0005: (size=0002)                                                  */
         __IO uint16_t  CnV;                    /**< 0006: Channel  Value                                               */
         struct {                               /**< 0005: (size=0002)                                                  */
            __IO uint8_t   CnVH;                /**< 0006: Channel  Value High                                          */
            __IO uint8_t   CnVL;                /**< 0007: Channel  Value Low                                           */
         };
      };
   } CONTROLS[2];                               /**< 0005: (cluster: size=0x0006, 6)                                    */
   __I  uint8_t   RESERVED0[21];               
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  CNTIN;                     /**< 0020: Counter Initial Value                                        */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   CNTINH;                 /**< 0020: Counter Initial Value High                                   */
         __IO uint8_t   CNTINL;                 /**< 0021: Counter Initial Value Low                                    */
      };
   };
   __IO uint8_t   STATUS;                       /**< 0022: Capture and Compare Status                                   */
   __IO uint8_t   MODE;                         /**< 0023: Features Mode Selection                                      */
   __IO uint8_t   SYNC;                         /**< 0024: Synchronization                                              */
   __IO uint8_t   OUTINIT;                      /**< 0025: Initial State for Channels Output                            */
   __IO uint8_t   OUTMASK;                      /**< 0026: Output Mask                                                  */
   __IO uint8_t   COMBINE[1];                   /**< 0027: Function for Linked Channels                                 */
   __I  uint8_t   RESERVED1[3];                
   __IO uint8_t   DEADTIME;                     /**< 002B: Deadtime Insertion Control                                   */
   __IO uint8_t   EXTTRIG;                      /**< 002C: FTM External Trigger                                         */
   __IO uint8_t   POL;                          /**< 002D: Channels Polarity                                            */
   __IO uint8_t   FMS;                          /**< 002E: Fault Mode Status                                            */
   __IO uint8_t   FILTER0;                      /**< 002F: Input Capture Filter Control                                 */
   __IO uint8_t   FILTER1;                      /**< 0030: Input Capture Filter Control                                 */
   __IO uint8_t   FLTFILTER;                    /**< 0031: Fault Input Filter Control                                   */
   __IO uint8_t   FLTCTRL;                      /**< 0032: Fault Control                                                */
   __IO uint8_t   QDCTRL;                       /**< 0033: Quadrature Decoder Control and Status                        */
} FTM_2CH_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define FTM_SC_PS_MASK                           (0x07UL << FTM_SC_PS_SHIFT)                         /*!< FTM0_SC: PS Mask                        */
#define FTM_SC_PS_SHIFT                          0                                                   /*!< FTM0_SC: PS Position                    */
#define FTM_SC_PS(x)                             (((uint8_t)(((uint8_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_CLKS_MASK                         (0x03UL << FTM_SC_CLKS_SHIFT)                       /*!< FTM0_SC: CLKS Mask                      */
#define FTM_SC_CLKS_SHIFT                        3                                                   /*!< FTM0_SC: CLKS Position                  */
#define FTM_SC_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_CPWMS_MASK                        (0x01UL << FTM_SC_CPWMS_SHIFT)                      /*!< FTM0_SC: CPWMS Mask                     */
#define FTM_SC_CPWMS_SHIFT                       5                                                   /*!< FTM0_SC: CPWMS Position                 */
#define FTM_SC_TOIE_MASK                         (0x01UL << FTM_SC_TOIE_SHIFT)                       /*!< FTM0_SC: TOIE Mask                      */
#define FTM_SC_TOIE_SHIFT                        6                                                   /*!< FTM0_SC: TOIE Position                  */
#define FTM_SC_TOF_MASK                          (0x01UL << FTM_SC_TOF_SHIFT)                        /*!< FTM0_SC: TOF Mask                       */
#define FTM_SC_TOF_SHIFT                         7                                                   /*!< FTM0_SC: TOF Position                   */
/* ------- CNT Bit Fields                           ------ */
#define FTM_CNT_COUNT_MASK                       (0xFFFFUL << FTM_CNT_COUNT_SHIFT)                   /*!< FTM0_CNT: COUNT Mask                    */
#define FTM_CNT_COUNT_SHIFT                      0                                                   /*!< FTM0_CNT: COUNT Position                */
#define FTM_CNT_COUNT(x)                         (((uint16_t)(((uint16_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK) /*!< FTM0_CNT                                */
/* ------- CNTH Bit Fields                          ------ */
#define FTM_CNTH_COUNT_MASK                      (0xFFUL << FTM_CNTH_COUNT_SHIFT)                    /*!< FTM0_CNTH: COUNT Mask                   */
#define FTM_CNTH_COUNT_SHIFT                     0                                                   /*!< FTM0_CNTH: COUNT Position               */
#define FTM_CNTH_COUNT(x)                        (((uint8_t)(((uint8_t)(x))<<FTM_CNTH_COUNT_SHIFT))&FTM_CNTH_COUNT_MASK) /*!< FTM0_CNTH                               */
/* ------- CNTL Bit Fields                          ------ */
#define FTM_CNTL_COUNT_MASK                      (0xFFUL << FTM_CNTL_COUNT_SHIFT)                    /*!< FTM0_CNTL: COUNT Mask                   */
#define FTM_CNTL_COUNT_SHIFT                     0                                                   /*!< FTM0_CNTL: COUNT Position               */
#define FTM_CNTL_COUNT(x)                        (((uint8_t)(((uint8_t)(x))<<FTM_CNTL_COUNT_SHIFT))&FTM_CNTL_COUNT_MASK) /*!< FTM0_CNTL                               */
/* ------- MOD Bit Fields                           ------ */
#define FTM_MOD_MOD_MASK                         (0xFFFFUL << FTM_MOD_MOD_SHIFT)                     /*!< FTM0_MOD: MOD Mask                      */
#define FTM_MOD_MOD_SHIFT                        0                                                   /*!< FTM0_MOD: MOD Position                  */
#define FTM_MOD_MOD(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK) /*!< FTM0_MOD                                */
/* ------- MODH Bit Fields                          ------ */
#define FTM_MODH_MOD_MASK                        (0xFFUL << FTM_MODH_MOD_SHIFT)                      /*!< FTM0_MODH: MOD Mask                     */
#define FTM_MODH_MOD_SHIFT                       0                                                   /*!< FTM0_MODH: MOD Position                 */
#define FTM_MODH_MOD(x)                          (((uint8_t)(((uint8_t)(x))<<FTM_MODH_MOD_SHIFT))&FTM_MODH_MOD_MASK) /*!< FTM0_MODH                               */
/* ------- MODL Bit Fields                          ------ */
#define FTM_MODL_MOD_MASK                        (0xFFUL << FTM_MODL_MOD_SHIFT)                      /*!< FTM0_MODL: MOD Mask                     */
#define FTM_MODL_MOD_SHIFT                       0                                                   /*!< FTM0_MODL: MOD Position                 */
#define FTM_MODL_MOD(x)                          (((uint8_t)(((uint8_t)(x))<<FTM_MODL_MOD_SHIFT))&FTM_MODL_MOD_MASK) /*!< FTM0_MODL                               */
/* ------- CnSC Bit Fields                          ------ */
#define FTM_CnSC_DMA_MASK                        (0x01UL << FTM_CnSC_DMA_SHIFT)                      /*!< FTM0_CnSC: DMA Mask                     */
#define FTM_CnSC_DMA_SHIFT                       0                                                   /*!< FTM0_CnSC: DMA Position                 */
#define FTM_CnSC_ELS_MASK                        (0x03UL << FTM_CnSC_ELS_SHIFT)                      /*!< FTM0_CnSC: ELS Mask                     */
#define FTM_CnSC_ELS_SHIFT                       2                                                   /*!< FTM0_CnSC: ELS Position                 */
#define FTM_CnSC_ELS(x)                          (((uint8_t)(((uint8_t)(x))<<FTM_CnSC_ELS_SHIFT))&FTM_CnSC_ELS_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELSA_MASK                       (0x01UL << FTM_CnSC_ELSA_SHIFT)                     /*!< FTM0_CnSC: ELSA Mask                    */
#define FTM_CnSC_ELSA_SHIFT                      2                                                   /*!< FTM0_CnSC: ELSA Position                */
#define FTM_CnSC_ELSB_MASK                       (0x01UL << FTM_CnSC_ELSB_SHIFT)                     /*!< FTM0_CnSC: ELSB Mask                    */
#define FTM_CnSC_ELSB_SHIFT                      3                                                   /*!< FTM0_CnSC: ELSB Position                */
#define FTM_CnSC_MS_MASK                         (0x03UL << FTM_CnSC_MS_SHIFT)                       /*!< FTM0_CnSC: MS Mask                      */
#define FTM_CnSC_MS_SHIFT                        4                                                   /*!< FTM0_CnSC: MS Position                  */
#define FTM_CnSC_MS(x)                           (((uint8_t)(((uint8_t)(x))<<FTM_CnSC_MS_SHIFT))&FTM_CnSC_MS_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MSA_MASK                        (0x01UL << FTM_CnSC_MSA_SHIFT)                      /*!< FTM0_CnSC: MSA Mask                     */
#define FTM_CnSC_MSA_SHIFT                       4                                                   /*!< FTM0_CnSC: MSA Position                 */
#define FTM_CnSC_MSB_MASK                        (0x01UL << FTM_CnSC_MSB_SHIFT)                      /*!< FTM0_CnSC: MSB Mask                     */
#define FTM_CnSC_MSB_SHIFT                       5                                                   /*!< FTM0_CnSC: MSB Position                 */
#define FTM_CnSC_CHIE_MASK                       (0x01UL << FTM_CnSC_CHIE_SHIFT)                     /*!< FTM0_CnSC: CHIE Mask                    */
#define FTM_CnSC_CHIE_SHIFT                      6                                                   /*!< FTM0_CnSC: CHIE Position                */
#define FTM_CnSC_CHF_MASK                        (0x01UL << FTM_CnSC_CHF_SHIFT)                      /*!< FTM0_CnSC: CHF Mask                     */
#define FTM_CnSC_CHF_SHIFT                       7                                                   /*!< FTM0_CnSC: CHF Position                 */
/* ------- CnV Bit Fields                           ------ */
#define FTM_CnV_VAL_MASK                         (0xFFFFUL << FTM_CnV_VAL_SHIFT)                     /*!< FTM0_CnV: VAL Mask                      */
#define FTM_CnV_VAL_SHIFT                        0                                                   /*!< FTM0_CnV: VAL Position                  */
#define FTM_CnV_VAL(x)                           (((uint16_t)(((uint16_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK) /*!< FTM0_CnV                                */
/* ------- CnVH Bit Fields                          ------ */
#define FTM_CnVH_VAL_MASK                        (0xFFUL << FTM_CnVH_VAL_SHIFT)                      /*!< FTM0_CnVH: VAL Mask                     */
#define FTM_CnVH_VAL_SHIFT                       0                                                   /*!< FTM0_CnVH: VAL Position                 */
#define FTM_CnVH_VAL(x)                          (((uint8_t)(((uint8_t)(x))<<FTM_CnVH_VAL_SHIFT))&FTM_CnVH_VAL_MASK) /*!< FTM0_CnVH                               */
/* ------- CnVL Bit Fields                          ------ */
#define FTM_CnVL_VAL_MASK                        (0xFFUL << FTM_CnVL_VAL_SHIFT)                      /*!< FTM0_CnVL: VAL Mask                     */
#define FTM_CnVL_VAL_SHIFT                       0                                                   /*!< FTM0_CnVL: VAL Position                 */
#define FTM_CnVL_VAL(x)                          (((uint8_t)(((uint8_t)(x))<<FTM_CnVL_VAL_SHIFT))&FTM_CnVL_VAL_MASK) /*!< FTM0_CnVL                               */
/* ------- CNTIN Bit Fields                         ------ */
#define FTM_CNTIN_INIT_MASK                      (0xFFFFUL << FTM_CNTIN_INIT_SHIFT)                  /*!< FTM0_CNTIN: INIT Mask                   */
#define FTM_CNTIN_INIT_SHIFT                     0                                                   /*!< FTM0_CNTIN: INIT Position               */
#define FTM_CNTIN_INIT(x)                        (((uint16_t)(((uint16_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK) /*!< FTM0_CNTIN                              */
/* ------- CNTINH Bit Fields                        ------ */
#define FTM_CNTINH_INIT_MASK                     (0xFFUL << FTM_CNTINH_INIT_SHIFT)                   /*!< FTM0_CNTINH: INIT Mask                  */
#define FTM_CNTINH_INIT_SHIFT                    0                                                   /*!< FTM0_CNTINH: INIT Position              */
#define FTM_CNTINH_INIT(x)                       (((uint8_t)(((uint8_t)(x))<<FTM_CNTINH_INIT_SHIFT))&FTM_CNTINH_INIT_MASK) /*!< FTM0_CNTINH                             */
/* ------- CNTINL Bit Fields                        ------ */
#define FTM_CNTINL_INIT_MASK                     (0xFFUL << FTM_CNTINL_INIT_SHIFT)                   /*!< FTM0_CNTINL: INIT Mask                  */
#define FTM_CNTINL_INIT_SHIFT                    0                                                   /*!< FTM0_CNTINL: INIT Position              */
#define FTM_CNTINL_INIT(x)                       (((uint8_t)(((uint8_t)(x))<<FTM_CNTINL_INIT_SHIFT))&FTM_CNTINL_INIT_MASK) /*!< FTM0_CNTINL                             */
/* ------- STATUS Bit Fields                        ------ */
#define FTM_STATUS_CH0F_MASK                     (0x01UL << FTM_STATUS_CH0F_SHIFT)                   /*!< FTM0_STATUS: CH0F Mask                  */
#define FTM_STATUS_CH0F_SHIFT                    0                                                   /*!< FTM0_STATUS: CH0F Position              */
#define FTM_STATUS_CH1F_MASK                     (0x01UL << FTM_STATUS_CH1F_SHIFT)                   /*!< FTM0_STATUS: CH1F Mask                  */
#define FTM_STATUS_CH1F_SHIFT                    1                                                   /*!< FTM0_STATUS: CH1F Position              */
#define FTM_STATUS_CH2F_MASK                     (0x01UL << FTM_STATUS_CH2F_SHIFT)                   /*!< FTM0_STATUS: CH2F Mask                  */
#define FTM_STATUS_CH2F_SHIFT                    2                                                   /*!< FTM0_STATUS: CH2F Position              */
#define FTM_STATUS_CH3F_MASK                     (0x01UL << FTM_STATUS_CH3F_SHIFT)                   /*!< FTM0_STATUS: CH3F Mask                  */
#define FTM_STATUS_CH3F_SHIFT                    3                                                   /*!< FTM0_STATUS: CH3F Position              */
#define FTM_STATUS_CH4F_MASK                     (0x01UL << FTM_STATUS_CH4F_SHIFT)                   /*!< FTM0_STATUS: CH4F Mask                  */
#define FTM_STATUS_CH4F_SHIFT                    4                                                   /*!< FTM0_STATUS: CH4F Position              */
#define FTM_STATUS_CH5F_MASK                     (0x01UL << FTM_STATUS_CH5F_SHIFT)                   /*!< FTM0_STATUS: CH5F Mask                  */
#define FTM_STATUS_CH5F_SHIFT                    5                                                   /*!< FTM0_STATUS: CH5F Position              */
#define FTM_STATUS_CH6F_MASK                     (0x01UL << FTM_STATUS_CH6F_SHIFT)                   /*!< FTM0_STATUS: CH6F Mask                  */
#define FTM_STATUS_CH6F_SHIFT                    6                                                   /*!< FTM0_STATUS: CH6F Position              */
#define FTM_STATUS_CH7F_MASK                     (0x01UL << FTM_STATUS_CH7F_SHIFT)                   /*!< FTM0_STATUS: CH7F Mask                  */
#define FTM_STATUS_CH7F_SHIFT                    7                                                   /*!< FTM0_STATUS: CH7F Position              */
/* ------- MODE Bit Fields                          ------ */
#define FTM_MODE_FTMEN_MASK                      (0x01UL << FTM_MODE_FTMEN_SHIFT)                    /*!< FTM0_MODE: FTMEN Mask                   */
#define FTM_MODE_FTMEN_SHIFT                     0                                                   /*!< FTM0_MODE: FTMEN Position               */
#define FTM_MODE_INIT_MASK                       (0x01UL << FTM_MODE_INIT_SHIFT)                     /*!< FTM0_MODE: INIT Mask                    */
#define FTM_MODE_INIT_SHIFT                      1                                                   /*!< FTM0_MODE: INIT Position                */
#define FTM_MODE_WPDIS_MASK                      (0x01UL << FTM_MODE_WPDIS_SHIFT)                    /*!< FTM0_MODE: WPDIS Mask                   */
#define FTM_MODE_WPDIS_SHIFT                     2                                                   /*!< FTM0_MODE: WPDIS Position               */
#define FTM_MODE_PWMSYNC_MASK                    (0x01UL << FTM_MODE_PWMSYNC_SHIFT)                  /*!< FTM0_MODE: PWMSYNC Mask                 */
#define FTM_MODE_PWMSYNC_SHIFT                   3                                                   /*!< FTM0_MODE: PWMSYNC Position             */
#define FTM_MODE_CAPTEST_MASK                    (0x01UL << FTM_MODE_CAPTEST_SHIFT)                  /*!< FTM0_MODE: CAPTEST Mask                 */
#define FTM_MODE_CAPTEST_SHIFT                   4                                                   /*!< FTM0_MODE: CAPTEST Position             */
#define FTM_MODE_FAULTM_MASK                     (0x03UL << FTM_MODE_FAULTM_SHIFT)                   /*!< FTM0_MODE: FAULTM Mask                  */
#define FTM_MODE_FAULTM_SHIFT                    5                                                   /*!< FTM0_MODE: FAULTM Position              */
#define FTM_MODE_FAULTM(x)                       (((uint8_t)(((uint8_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_FAULTIE_MASK                    (0x01UL << FTM_MODE_FAULTIE_SHIFT)                  /*!< FTM0_MODE: FAULTIE Mask                 */
#define FTM_MODE_FAULTIE_SHIFT                   7                                                   /*!< FTM0_MODE: FAULTIE Position             */
/* ------- SYNC Bit Fields                          ------ */
#define FTM_SYNC_CNTMIN_MASK                     (0x01UL << FTM_SYNC_CNTMIN_SHIFT)                   /*!< FTM0_SYNC: CNTMIN Mask                  */
#define FTM_SYNC_CNTMIN_SHIFT                    0                                                   /*!< FTM0_SYNC: CNTMIN Position              */
#define FTM_SYNC_CNTMAX_MASK                     (0x01UL << FTM_SYNC_CNTMAX_SHIFT)                   /*!< FTM0_SYNC: CNTMAX Mask                  */
#define FTM_SYNC_CNTMAX_SHIFT                    1                                                   /*!< FTM0_SYNC: CNTMAX Position              */
#define FTM_SYNC_REINIT_MASK                     (0x01UL << FTM_SYNC_REINIT_SHIFT)                   /*!< FTM0_SYNC: REINIT Mask                  */
#define FTM_SYNC_REINIT_SHIFT                    2                                                   /*!< FTM0_SYNC: REINIT Position              */
#define FTM_SYNC_SYNCHOM_MASK                    (0x01UL << FTM_SYNC_SYNCHOM_SHIFT)                  /*!< FTM0_SYNC: SYNCHOM Mask                 */
#define FTM_SYNC_SYNCHOM_SHIFT                   3                                                   /*!< FTM0_SYNC: SYNCHOM Position             */
#define FTM_SYNC_TRIG0_MASK                      (0x01UL << FTM_SYNC_TRIG0_SHIFT)                    /*!< FTM0_SYNC: TRIG0 Mask                   */
#define FTM_SYNC_TRIG0_SHIFT                     4                                                   /*!< FTM0_SYNC: TRIG0 Position               */
#define FTM_SYNC_TRIG1_MASK                      (0x01UL << FTM_SYNC_TRIG1_SHIFT)                    /*!< FTM0_SYNC: TRIG1 Mask                   */
#define FTM_SYNC_TRIG1_SHIFT                     5                                                   /*!< FTM0_SYNC: TRIG1 Position               */
#define FTM_SYNC_TRIG2_MASK                      (0x01UL << FTM_SYNC_TRIG2_SHIFT)                    /*!< FTM0_SYNC: TRIG2 Mask                   */
#define FTM_SYNC_TRIG2_SHIFT                     6                                                   /*!< FTM0_SYNC: TRIG2 Position               */
#define FTM_SYNC_SWSYNC_MASK                     (0x01UL << FTM_SYNC_SWSYNC_SHIFT)                   /*!< FTM0_SYNC: SWSYNC Mask                  */
#define FTM_SYNC_SWSYNC_SHIFT                    7                                                   /*!< FTM0_SYNC: SWSYNC Position              */
/* ------- OUTINIT Bit Fields                       ------ */
#define FTM_OUTINIT_CH0OI_MASK                   (0x01UL << FTM_OUTINIT_CH0OI_SHIFT)                 /*!< FTM0_OUTINIT: CH0OI Mask                */
#define FTM_OUTINIT_CH0OI_SHIFT                  0                                                   /*!< FTM0_OUTINIT: CH0OI Position            */
#define FTM_OUTINIT_CH1OI_MASK                   (0x01UL << FTM_OUTINIT_CH1OI_SHIFT)                 /*!< FTM0_OUTINIT: CH1OI Mask                */
#define FTM_OUTINIT_CH1OI_SHIFT                  1                                                   /*!< FTM0_OUTINIT: CH1OI Position            */
#define FTM_OUTINIT_CH2OI_MASK                   (0x01UL << FTM_OUTINIT_CH2OI_SHIFT)                 /*!< FTM0_OUTINIT: CH2OI Mask                */
#define FTM_OUTINIT_CH2OI_SHIFT                  2                                                   /*!< FTM0_OUTINIT: CH2OI Position            */
#define FTM_OUTINIT_CH3OI_MASK                   (0x01UL << FTM_OUTINIT_CH3OI_SHIFT)                 /*!< FTM0_OUTINIT: CH3OI Mask                */
#define FTM_OUTINIT_CH3OI_SHIFT                  3                                                   /*!< FTM0_OUTINIT: CH3OI Position            */
#define FTM_OUTINIT_CH4OI_MASK                   (0x01UL << FTM_OUTINIT_CH4OI_SHIFT)                 /*!< FTM0_OUTINIT: CH4OI Mask                */
#define FTM_OUTINIT_CH4OI_SHIFT                  4                                                   /*!< FTM0_OUTINIT: CH4OI Position            */
#define FTM_OUTINIT_CH5OI_MASK                   (0x01UL << FTM_OUTINIT_CH5OI_SHIFT)                 /*!< FTM0_OUTINIT: CH5OI Mask                */
#define FTM_OUTINIT_CH5OI_SHIFT                  5                                                   /*!< FTM0_OUTINIT: CH5OI Position            */
#define FTM_OUTINIT_CH6OI_MASK                   (0x01UL << FTM_OUTINIT_CH6OI_SHIFT)                 /*!< FTM0_OUTINIT: CH6OI Mask                */
#define FTM_OUTINIT_CH6OI_SHIFT                  6                                                   /*!< FTM0_OUTINIT: CH6OI Position            */
#define FTM_OUTINIT_CH7OI_MASK                   (0x01UL << FTM_OUTINIT_CH7OI_SHIFT)                 /*!< FTM0_OUTINIT: CH7OI Mask                */
#define FTM_OUTINIT_CH7OI_SHIFT                  7                                                   /*!< FTM0_OUTINIT: CH7OI Position            */
/* ------- OUTMASK Bit Fields                       ------ */
#define FTM_OUTMASK_CH0OM_MASK                   (0x01UL << FTM_OUTMASK_CH0OM_SHIFT)                 /*!< FTM0_OUTMASK: CH0OM Mask                */
#define FTM_OUTMASK_CH0OM_SHIFT                  0                                                   /*!< FTM0_OUTMASK: CH0OM Position            */
#define FTM_OUTMASK_CH1OM_MASK                   (0x01UL << FTM_OUTMASK_CH1OM_SHIFT)                 /*!< FTM0_OUTMASK: CH1OM Mask                */
#define FTM_OUTMASK_CH1OM_SHIFT                  1                                                   /*!< FTM0_OUTMASK: CH1OM Position            */
#define FTM_OUTMASK_CH2OM_MASK                   (0x01UL << FTM_OUTMASK_CH2OM_SHIFT)                 /*!< FTM0_OUTMASK: CH2OM Mask                */
#define FTM_OUTMASK_CH2OM_SHIFT                  2                                                   /*!< FTM0_OUTMASK: CH2OM Position            */
#define FTM_OUTMASK_CH3OM_MASK                   (0x01UL << FTM_OUTMASK_CH3OM_SHIFT)                 /*!< FTM0_OUTMASK: CH3OM Mask                */
#define FTM_OUTMASK_CH3OM_SHIFT                  3                                                   /*!< FTM0_OUTMASK: CH3OM Position            */
#define FTM_OUTMASK_CH4OM_MASK                   (0x01UL << FTM_OUTMASK_CH4OM_SHIFT)                 /*!< FTM0_OUTMASK: CH4OM Mask                */
#define FTM_OUTMASK_CH4OM_SHIFT                  4                                                   /*!< FTM0_OUTMASK: CH4OM Position            */
#define FTM_OUTMASK_CH5OM_MASK                   (0x01UL << FTM_OUTMASK_CH5OM_SHIFT)                 /*!< FTM0_OUTMASK: CH5OM Mask                */
#define FTM_OUTMASK_CH5OM_SHIFT                  5                                                   /*!< FTM0_OUTMASK: CH5OM Position            */
#define FTM_OUTMASK_CH6OM_MASK                   (0x01UL << FTM_OUTMASK_CH6OM_SHIFT)                 /*!< FTM0_OUTMASK: CH6OM Mask                */
#define FTM_OUTMASK_CH6OM_SHIFT                  6                                                   /*!< FTM0_OUTMASK: CH6OM Position            */
#define FTM_OUTMASK_CH7OM_MASK                   (0x01UL << FTM_OUTMASK_CH7OM_SHIFT)                 /*!< FTM0_OUTMASK: CH7OM Mask                */
#define FTM_OUTMASK_CH7OM_SHIFT                  7                                                   /*!< FTM0_OUTMASK: CH7OM Position            */
/* ------- COMBINE Bit Fields                       ------ */
#define FTM_COMBINE_COMBINE_MASK                 (0x01UL << FTM_COMBINE_COMBINE_SHIFT)               /*!< FTM0_COMBINE: COMBINE Mask              */
#define FTM_COMBINE_COMBINE_SHIFT                0                                                   /*!< FTM0_COMBINE: COMBINE Position          */
#define FTM_COMBINE_COMP_MASK                    (0x01UL << FTM_COMBINE_COMP_SHIFT)                  /*!< FTM0_COMBINE: COMP Mask                 */
#define FTM_COMBINE_COMP_SHIFT                   1                                                   /*!< FTM0_COMBINE: COMP Position             */
#define FTM_COMBINE_DECAPEN_MASK                 (0x01UL << FTM_COMBINE_DECAPEN_SHIFT)               /*!< FTM0_COMBINE: DECAPEN Mask              */
#define FTM_COMBINE_DECAPEN_SHIFT                2                                                   /*!< FTM0_COMBINE: DECAPEN Position          */
#define FTM_COMBINE_DECAP_MASK                   (0x01UL << FTM_COMBINE_DECAP_SHIFT)                 /*!< FTM0_COMBINE: DECAP Mask                */
#define FTM_COMBINE_DECAP_SHIFT                  3                                                   /*!< FTM0_COMBINE: DECAP Position            */
#define FTM_COMBINE_DTEN_MASK                    (0x01UL << FTM_COMBINE_DTEN_SHIFT)                  /*!< FTM0_COMBINE: DTEN Mask                 */
#define FTM_COMBINE_DTEN_SHIFT                   4                                                   /*!< FTM0_COMBINE: DTEN Position             */
#define FTM_COMBINE_SYNCEN_MASK                  (0x01UL << FTM_COMBINE_SYNCEN_SHIFT)                /*!< FTM0_COMBINE: SYNCEN Mask               */
#define FTM_COMBINE_SYNCEN_SHIFT                 5                                                   /*!< FTM0_COMBINE: SYNCEN Position           */
#define FTM_COMBINE_FAULTEN_MASK                 (0x01UL << FTM_COMBINE_FAULTEN_SHIFT)               /*!< FTM0_COMBINE: FAULTEN Mask              */
#define FTM_COMBINE_FAULTEN_SHIFT                6                                                   /*!< FTM0_COMBINE: FAULTEN Position          */
/* ------- DEADTIME Bit Fields                      ------ */
#define FTM_DEADTIME_DTVAL_MASK                  (0x3FUL << FTM_DEADTIME_DTVAL_SHIFT)                /*!< FTM0_DEADTIME: DTVAL Mask               */
#define FTM_DEADTIME_DTVAL_SHIFT                 0                                                   /*!< FTM0_DEADTIME: DTVAL Position           */
#define FTM_DEADTIME_DTVAL(x)                    (((uint8_t)(((uint8_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK) /*!< FTM0_DEADTIME                           */
#define FTM_DEADTIME_DTPS_MASK                   (0x03UL << FTM_DEADTIME_DTPS_SHIFT)                 /*!< FTM0_DEADTIME: DTPS Mask                */
#define FTM_DEADTIME_DTPS_SHIFT                  6                                                   /*!< FTM0_DEADTIME: DTPS Position            */
#define FTM_DEADTIME_DTPS(x)                     (((uint8_t)(((uint8_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK) /*!< FTM0_DEADTIME                           */
/* ------- EXTTRIG Bit Fields                       ------ */
#define FTM_EXTTRIG_CH2TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH2TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH2TRIG Mask              */
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0                                                   /*!< FTM0_EXTTRIG: CH2TRIG Position          */
#define FTM_EXTTRIG_CH3TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH3TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH3TRIG Mask              */
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1                                                   /*!< FTM0_EXTTRIG: CH3TRIG Position          */
#define FTM_EXTTRIG_CH4TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH4TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH4TRIG Mask              */
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2                                                   /*!< FTM0_EXTTRIG: CH4TRIG Position          */
#define FTM_EXTTRIG_CH5TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH5TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH5TRIG Mask              */
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3                                                   /*!< FTM0_EXTTRIG: CH5TRIG Position          */
#define FTM_EXTTRIG_CH0TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH0TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH0TRIG Mask              */
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4                                                   /*!< FTM0_EXTTRIG: CH0TRIG Position          */
#define FTM_EXTTRIG_CH1TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH1TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH1TRIG Mask              */
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5                                                   /*!< FTM0_EXTTRIG: CH1TRIG Position          */
#define FTM_EXTTRIG_INITTRIGEN_MASK              (0x01UL << FTM_EXTTRIG_INITTRIGEN_SHIFT)            /*!< FTM0_EXTTRIG: INITTRIGEN Mask           */
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6                                                   /*!< FTM0_EXTTRIG: INITTRIGEN Position       */
#define FTM_EXTTRIG_TRIGF_MASK                   (0x01UL << FTM_EXTTRIG_TRIGF_SHIFT)                 /*!< FTM0_EXTTRIG: TRIGF Mask                */
#define FTM_EXTTRIG_TRIGF_SHIFT                  7                                                   /*!< FTM0_EXTTRIG: TRIGF Position            */
/* ------- POL Bit Fields                           ------ */
#define FTM_POL_POL0_MASK                        (0x01UL << FTM_POL_POL0_SHIFT)                      /*!< FTM0_POL: POL0 Mask                     */
#define FTM_POL_POL0_SHIFT                       0                                                   /*!< FTM0_POL: POL0 Position                 */
#define FTM_POL_POL1_MASK                        (0x01UL << FTM_POL_POL1_SHIFT)                      /*!< FTM0_POL: POL1 Mask                     */
#define FTM_POL_POL1_SHIFT                       1                                                   /*!< FTM0_POL: POL1 Position                 */
#define FTM_POL_POL2_MASK                        (0x01UL << FTM_POL_POL2_SHIFT)                      /*!< FTM0_POL: POL2 Mask                     */
#define FTM_POL_POL2_SHIFT                       2                                                   /*!< FTM0_POL: POL2 Position                 */
#define FTM_POL_POL3_MASK                        (0x01UL << FTM_POL_POL3_SHIFT)                      /*!< FTM0_POL: POL3 Mask                     */
#define FTM_POL_POL3_SHIFT                       3                                                   /*!< FTM0_POL: POL3 Position                 */
#define FTM_POL_POL4_MASK                        (0x01UL << FTM_POL_POL4_SHIFT)                      /*!< FTM0_POL: POL4 Mask                     */
#define FTM_POL_POL4_SHIFT                       4                                                   /*!< FTM0_POL: POL4 Position                 */
#define FTM_POL_POL5_MASK                        (0x01UL << FTM_POL_POL5_SHIFT)                      /*!< FTM0_POL: POL5 Mask                     */
#define FTM_POL_POL5_SHIFT                       5                                                   /*!< FTM0_POL: POL5 Position                 */
#define FTM_POL_POL6_MASK                        (0x01UL << FTM_POL_POL6_SHIFT)                      /*!< FTM0_POL: POL6 Mask                     */
#define FTM_POL_POL6_SHIFT                       6                                                   /*!< FTM0_POL: POL6 Position                 */
#define FTM_POL_POL7_MASK                        (0x01UL << FTM_POL_POL7_SHIFT)                      /*!< FTM0_POL: POL7 Mask                     */
#define FTM_POL_POL7_SHIFT                       7                                                   /*!< FTM0_POL: POL7 Position                 */
/* ------- FMS Bit Fields                           ------ */
#define FTM_FMS_FAULTF0_MASK                     (0x01UL << FTM_FMS_FAULTF0_SHIFT)                   /*!< FTM0_FMS: FAULTF0 Mask                  */
#define FTM_FMS_FAULTF0_SHIFT                    0                                                   /*!< FTM0_FMS: FAULTF0 Position              */
#define FTM_FMS_FAULTF1_MASK                     (0x01UL << FTM_FMS_FAULTF1_SHIFT)                   /*!< FTM0_FMS: FAULTF1 Mask                  */
#define FTM_FMS_FAULTF1_SHIFT                    1                                                   /*!< FTM0_FMS: FAULTF1 Position              */
#define FTM_FMS_FAULTF2_MASK                     (0x01UL << FTM_FMS_FAULTF2_SHIFT)                   /*!< FTM0_FMS: FAULTF2 Mask                  */
#define FTM_FMS_FAULTF2_SHIFT                    2                                                   /*!< FTM0_FMS: FAULTF2 Position              */
#define FTM_FMS_FAULTF3_MASK                     (0x01UL << FTM_FMS_FAULTF3_SHIFT)                   /*!< FTM0_FMS: FAULTF3 Mask                  */
#define FTM_FMS_FAULTF3_SHIFT                    3                                                   /*!< FTM0_FMS: FAULTF3 Position              */
#define FTM_FMS_FAULTIN_MASK                     (0x01UL << FTM_FMS_FAULTIN_SHIFT)                   /*!< FTM0_FMS: FAULTIN Mask                  */
#define FTM_FMS_FAULTIN_SHIFT                    5                                                   /*!< FTM0_FMS: FAULTIN Position              */
#define FTM_FMS_WPEN_MASK                        (0x01UL << FTM_FMS_WPEN_SHIFT)                      /*!< FTM0_FMS: WPEN Mask                     */
#define FTM_FMS_WPEN_SHIFT                       6                                                   /*!< FTM0_FMS: WPEN Position                 */
#define FTM_FMS_FAULTF_MASK                      (0x01UL << FTM_FMS_FAULTF_SHIFT)                    /*!< FTM0_FMS: FAULTF Mask                   */
#define FTM_FMS_FAULTF_SHIFT                     7                                                   /*!< FTM0_FMS: FAULTF Position               */
/* ------- FILTER0 Bit Fields                       ------ */
#define FTM_FILTER0_CH0FVAL_MASK                 (0x0FUL << FTM_FILTER0_CH0FVAL_SHIFT)               /*!< FTM0_FILTER0: CH0FVAL Mask              */
#define FTM_FILTER0_CH0FVAL_SHIFT                0                                                   /*!< FTM0_FILTER0: CH0FVAL Position          */
#define FTM_FILTER0_CH0FVAL(x)                   (((uint8_t)(((uint8_t)(x))<<FTM_FILTER0_CH0FVAL_SHIFT))&FTM_FILTER0_CH0FVAL_MASK) /*!< FTM0_FILTER0                            */
#define FTM_FILTER0_CH1FVAL_MASK                 (0x0FUL << FTM_FILTER0_CH1FVAL_SHIFT)               /*!< FTM0_FILTER0: CH1FVAL Mask              */
#define FTM_FILTER0_CH1FVAL_SHIFT                4                                                   /*!< FTM0_FILTER0: CH1FVAL Position          */
#define FTM_FILTER0_CH1FVAL(x)                   (((uint8_t)(((uint8_t)(x))<<FTM_FILTER0_CH1FVAL_SHIFT))&FTM_FILTER0_CH1FVAL_MASK) /*!< FTM0_FILTER0                            */
/* ------- FILTER1 Bit Fields                       ------ */
#define FTM_FILTER1_CH2FVAL_MASK                 (0x0FUL << FTM_FILTER1_CH2FVAL_SHIFT)               /*!< FTM0_FILTER1: CH2FVAL Mask              */
#define FTM_FILTER1_CH2FVAL_SHIFT                0                                                   /*!< FTM0_FILTER1: CH2FVAL Position          */
#define FTM_FILTER1_CH2FVAL(x)                   (((uint8_t)(((uint8_t)(x))<<FTM_FILTER1_CH2FVAL_SHIFT))&FTM_FILTER1_CH2FVAL_MASK) /*!< FTM0_FILTER1                            */
#define FTM_FILTER1_CH3FVAL_MASK                 (0x0FUL << FTM_FILTER1_CH3FVAL_SHIFT)               /*!< FTM0_FILTER1: CH3FVAL Mask              */
#define FTM_FILTER1_CH3FVAL_SHIFT                4                                                   /*!< FTM0_FILTER1: CH3FVAL Position          */
#define FTM_FILTER1_CH3FVAL(x)                   (((uint8_t)(((uint8_t)(x))<<FTM_FILTER1_CH3FVAL_SHIFT))&FTM_FILTER1_CH3FVAL_MASK) /*!< FTM0_FILTER1                            */
/* ------- FLTFILTER Bit Fields                     ------ */
#define FTM_FLTFILTER_FFVAL_MASK                 (0x0FUL << FTM_FLTFILTER_FFVAL_SHIFT)               /*!< FTM0_FLTFILTER: FFVAL Mask              */
#define FTM_FLTFILTER_FFVAL_SHIFT                0                                                   /*!< FTM0_FLTFILTER: FFVAL Position          */
#define FTM_FLTFILTER_FFVAL(x)                   (((uint8_t)(((uint8_t)(x))<<FTM_FLTFILTER_FFVAL_SHIFT))&FTM_FLTFILTER_FFVAL_MASK) /*!< FTM0_FLTFILTER                          */
/* ------- FLTCTRL Bit Fields                       ------ */
#define FTM_FLTCTRL_FAULT0EN_MASK                (0x01UL << FTM_FLTCTRL_FAULT0EN_SHIFT)              /*!< FTM0_FLTCTRL: FAULT0EN Mask             */
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0                                                   /*!< FTM0_FLTCTRL: FAULT0EN Position         */
#define FTM_FLTCTRL_FAULT1EN_MASK                (0x01UL << FTM_FLTCTRL_FAULT1EN_SHIFT)              /*!< FTM0_FLTCTRL: FAULT1EN Mask             */
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1                                                   /*!< FTM0_FLTCTRL: FAULT1EN Position         */
#define FTM_FLTCTRL_FAULT2EN_MASK                (0x01UL << FTM_FLTCTRL_FAULT2EN_SHIFT)              /*!< FTM0_FLTCTRL: FAULT2EN Mask             */
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2                                                   /*!< FTM0_FLTCTRL: FAULT2EN Position         */
#define FTM_FLTCTRL_FAULT3EN_MASK                (0x01UL << FTM_FLTCTRL_FAULT3EN_SHIFT)              /*!< FTM0_FLTCTRL: FAULT3EN Mask             */
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3                                                   /*!< FTM0_FLTCTRL: FAULT3EN Position         */
#define FTM_FLTCTRL_FFLTR0EN_MASK                (0x01UL << FTM_FLTCTRL_FFLTR0EN_SHIFT)              /*!< FTM0_FLTCTRL: FFLTR0EN Mask             */
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4                                                   /*!< FTM0_FLTCTRL: FFLTR0EN Position         */
#define FTM_FLTCTRL_FFLTR1EN_MASK                (0x01UL << FTM_FLTCTRL_FFLTR1EN_SHIFT)              /*!< FTM0_FLTCTRL: FFLTR1EN Mask             */
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5                                                   /*!< FTM0_FLTCTRL: FFLTR1EN Position         */
#define FTM_FLTCTRL_FFLTR2EN_MASK                (0x01UL << FTM_FLTCTRL_FFLTR2EN_SHIFT)              /*!< FTM0_FLTCTRL: FFLTR2EN Mask             */
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6                                                   /*!< FTM0_FLTCTRL: FFLTR2EN Position         */
#define FTM_FLTCTRL_FFLTR3EN_MASK                (0x01UL << FTM_FLTCTRL_FFLTR3EN_SHIFT)              /*!< FTM0_FLTCTRL: FFLTR3EN Mask             */
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7                                                   /*!< FTM0_FLTCTRL: FFLTR3EN Position         */
/* ------- QDCTRL Bit Fields                        ------ */
#define FTM_QDCTRL_QUADEN_MASK                   (0x01UL << FTM_QDCTRL_QUADEN_SHIFT)                 /*!< FTM0_QDCTRL: QUADEN Mask                */
#define FTM_QDCTRL_QUADEN_SHIFT                  0                                                   /*!< FTM0_QDCTRL: QUADEN Position            */
#define FTM_QDCTRL_TOFDIR_MASK                   (0x01UL << FTM_QDCTRL_TOFDIR_SHIFT)                 /*!< FTM0_QDCTRL: TOFDIR Mask                */
#define FTM_QDCTRL_TOFDIR_SHIFT                  1                                                   /*!< FTM0_QDCTRL: TOFDIR Position            */
#define FTM_QDCTRL_QUADIR_MASK                   (0x01UL << FTM_QDCTRL_QUADIR_SHIFT)                 /*!< FTM0_QDCTRL: QUADIR Mask                */
#define FTM_QDCTRL_QUADIR_SHIFT                  2                                                   /*!< FTM0_QDCTRL: QUADIR Position            */
#define FTM_QDCTRL_QUADMODE_MASK                 (0x01UL << FTM_QDCTRL_QUADMODE_SHIFT)               /*!< FTM0_QDCTRL: QUADMODE Mask              */
#define FTM_QDCTRL_QUADMODE_SHIFT                3                                                   /*!< FTM0_QDCTRL: QUADMODE Position          */
#define FTM_QDCTRL_PHBPOL_MASK                   (0x01UL << FTM_QDCTRL_PHBPOL_SHIFT)                 /*!< FTM0_QDCTRL: PHBPOL Mask                */
#define FTM_QDCTRL_PHBPOL_SHIFT                  4                                                   /*!< FTM0_QDCTRL: PHBPOL Position            */
#define FTM_QDCTRL_PHAPOL_MASK                   (0x01UL << FTM_QDCTRL_PHAPOL_SHIFT)                 /*!< FTM0_QDCTRL: PHAPOL Mask                */
#define FTM_QDCTRL_PHAPOL_SHIFT                  5                                                   /*!< FTM0_QDCTRL: PHAPOL Position            */
#define FTM_QDCTRL_PHBFLTREN_MASK                (0x01UL << FTM_QDCTRL_PHBFLTREN_SHIFT)              /*!< FTM0_QDCTRL: PHBFLTREN Mask             */
#define FTM_QDCTRL_PHBFLTREN_SHIFT               6                                                   /*!< FTM0_QDCTRL: PHBFLTREN Position         */
#define FTM_QDCTRL_PHAFLTREN_MASK                (0x01UL << FTM_QDCTRL_PHAFLTREN_SHIFT)              /*!< FTM0_QDCTRL: PHAFLTREN Mask             */
#define FTM_QDCTRL_PHAFLTREN_SHIFT               7                                                   /*!< FTM0_QDCTRL: PHAFLTREN Position         */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM0 - Peripheral instance base addresses */
#define FTM0_BasePtr                   0xFFFF8440UL //!< Peripheral base address
#define FTM0                           ((FTM_2CH_Type *) FTM0_BasePtr) //!< Freescale base pointer
#define FTM0_BASE_PTR                  (FTM0) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM1 (file:FTM1_6CH_MCF51)           ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (6 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM1 Structure                                               */
   __IO uint8_t   SC;                           /**< 0000: Status and Control                                           */
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  CNT;                       /**< 0001: Counter                                                      */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   CNTH;                   /**< 0001: Counter High                                                 */
         __IO uint8_t   CNTL;                   /**< 0002: Counter Low                                                  */
      };
   };
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  MOD;                       /**< 0003: Modulo High                                                  */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   MODH;                   /**< 0003: Modulo High                                                  */
         __IO uint8_t   MODL;                   /**< 0004: Modulo Low                                                   */
      };
   };
   struct {
      __IO uint8_t   CnSC;                      /**< 0005: Channel  Status and Control                                  */
      union {                                   /**< 0005: (size=0002)                                                  */
         __IO uint16_t  CnV;                    /**< 0006: Channel  Value                                               */
         struct {                               /**< 0005: (size=0002)                                                  */
            __IO uint8_t   CnVH;                /**< 0006: Channel  Value High                                          */
            __IO uint8_t   CnVL;                /**< 0007: Channel  Value Low                                           */
         };
      };
   } CONTROLS[6];                               /**< 0005: (cluster: size=0x0012, 18)                                   */
   __I  uint8_t   RESERVED0[9];                
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  CNTIN;                     /**< 0020: Counter Initial Value                                        */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   CNTINH;                 /**< 0020: Counter Initial Value High                                   */
         __IO uint8_t   CNTINL;                 /**< 0021: Counter Initial Value Low                                    */
      };
   };
   __IO uint8_t   STATUS;                       /**< 0022: Capture and Compare Status                                   */
   __IO uint8_t   MODE;                         /**< 0023: Features Mode Selection                                      */
   __IO uint8_t   SYNC;                         /**< 0024: Synchronization                                              */
   __IO uint8_t   OUTINIT;                      /**< 0025: Initial State for Channels Output                            */
   __IO uint8_t   OUTMASK;                      /**< 0026: Output Mask                                                  */
   __IO uint8_t   COMBINE[3];                   /**< 0027: Function for Linked Channels                                 */
   __I  uint8_t   RESERVED1;                   
   __IO uint8_t   DEADTIME;                     /**< 002B: Deadtime Insertion Control                                   */
   __IO uint8_t   EXTTRIG;                      /**< 002C: FTM External Trigger                                         */
   __IO uint8_t   POL;                          /**< 002D: Channels Polarity                                            */
   __IO uint8_t   FMS;                          /**< 002E: Fault Mode Status                                            */
   __IO uint8_t   FILTER0;                      /**< 002F: Input Capture Filter Control                                 */
   __IO uint8_t   FILTER1;                      /**< 0030: Input Capture Filter Control                                 */
   __IO uint8_t   FLTFILTER;                    /**< 0031: Fault Input Filter Control                                   */
   __IO uint8_t   FLTCTRL;                      /**< 0032: Fault Control                                                */
   __IO uint8_t   QDCTRL;                       /**< 0033: Quadrature Decoder Control and Status                        */
} FTM_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
/* ------- CNT Bit Fields                           ------ */
/* ------- CNTH Bit Fields                          ------ */
/* ------- CNTL Bit Fields                          ------ */
/* ------- MOD Bit Fields                           ------ */
/* ------- MODH Bit Fields                          ------ */
/* ------- MODL Bit Fields                          ------ */
/* ------- CnSC Bit Fields                          ------ */
/* ------- CnV Bit Fields                           ------ */
/* ------- CnVH Bit Fields                          ------ */
/* ------- CnVL Bit Fields                          ------ */
/* ------- CNTIN Bit Fields                         ------ */
/* ------- CNTINH Bit Fields                        ------ */
/* ------- CNTINL Bit Fields                        ------ */
/* ------- STATUS Bit Fields                        ------ */
/* ------- MODE Bit Fields                          ------ */
/* ------- SYNC Bit Fields                          ------ */
/* ------- OUTINIT Bit Fields                       ------ */
/* ------- OUTMASK Bit Fields                       ------ */
/* ------- COMBINE Bit Fields                       ------ */
/* ------- DEADTIME Bit Fields                      ------ */
/* ------- EXTTRIG Bit Fields                       ------ */
/* ------- POL Bit Fields                           ------ */
/* ------- FMS Bit Fields                           ------ */
/* ------- FILTER0 Bit Fields                       ------ */
/* ------- FILTER1 Bit Fields                       ------ */
/* ------- FLTFILTER Bit Fields                     ------ */
/* ------- FLTCTRL Bit Fields                       ------ */
/* ------- QDCTRL Bit Fields                        ------ */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM1 - Peripheral instance base addresses */
#define FTM1_BasePtr                   0xFFFF8480UL //!< Peripheral base address
#define FTM1                           ((FTM_Type *) FTM1_BasePtr) //!< Freescale base pointer
#define FTM1_BASE_PTR                  (FTM1) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PTA_Peripheral_access_layer_GROUP PTA Peripheral Access Layer
* @brief C Struct for PTA
* @{
*/

/* ================================================================================ */
/* ================           GPIOA (file:PTA_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief GPIO Port
 */
/**
* @addtogroup PTA_structs_GROUP PTA struct
* @brief Struct for PTA
* @{
*/
typedef struct {                                /*       GPIOA Structure                                              */
   __IO uint8_t   D;                            /**< 0000: Port Data Register                                           */
   __IO uint8_t   DD;                           /**< 0001: Port Data Direction Register                                 */
   __I  uint8_t   PV;                           /**< 0002: Port Pin Value Register                                      */
} PT_Type;

/**
 * @} */ /* End group PTA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PTA_Register_Masks_GROUP PTA Register Masks
* @brief Register Masks for PTA
* @{
*/
/* ------- D Bit Fields                             ------ */
/* ------- DD Bit Fields                            ------ */
/* ------- PV Bit Fields                            ------ */
/**
 * @} */ /* End group PTA_Register_Masks_GROUP 
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0xFFFF8000UL //!< Peripheral base address
#define GPIOA                          ((PT_Type *) GPIOA_BasePtr) //!< Freescale base pointer
#define GPIOA_BASE_PTR                 (GPIOA) //!< Freescale style base pointer
/**
 * @} */ /* End group PTA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PTA_Peripheral_access_layer_GROUP PTA Peripheral Access Layer
* @brief C Struct for PTA
* @{
*/

/* ================================================================================ */
/* ================           GPIOB (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief GPIO Port
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0xFFFF8010UL //!< Peripheral base address
#define GPIOB                          ((PT_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer
/**
 * @} */ /* End group PTA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PTA_Peripheral_access_layer_GROUP PTA Peripheral Access Layer
* @brief C Struct for PTA
* @{
*/

/* ================================================================================ */
/* ================           GPIOC (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief GPIO Port
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0xFFFF8020UL //!< Peripheral base address
#define GPIOC                          ((PT_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer
/**
 * @} */ /* End group PTA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PTA_Peripheral_access_layer_GROUP PTA Peripheral Access Layer
* @brief C Struct for PTA
* @{
*/

/* ================================================================================ */
/* ================           GPIOD (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief GPIO Port
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0xFFFF8030UL //!< Peripheral base address
#define GPIOD                          ((PT_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer
/**
 * @} */ /* End group PTA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PTA_Peripheral_access_layer_GROUP PTA Peripheral Access Layer
* @brief C Struct for PTA
* @{
*/

/* ================================================================================ */
/* ================           GPIOE (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief GPIO Port
 */

/* GPIOE - Peripheral instance base addresses */
#define GPIOE_BasePtr                  0xFFFF8040UL //!< Peripheral base address
#define GPIOE                          ((PT_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group PTA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PTA_Peripheral_access_layer_GROUP PTA Peripheral Access Layer
* @brief C Struct for PTA
* @{
*/

/* ================================================================================ */
/* ================           GPIOF (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief GPIO Port
 */

/* GPIOF - Peripheral instance base addresses */
#define GPIOF_BasePtr                  0xFFFF8050UL //!< Peripheral base address
#define GPIOF                          ((PT_Type *) GPIOF_BasePtr) //!< Freescale base pointer
#define GPIOF_BASE_PTR                 (GPIOF) //!< Freescale style base pointer
/**
 * @} */ /* End group PTA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MCF51)               ================ */
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
   __IO uint8_t   A1;                           /**< 0000: Address Register 1                                           */
   __IO uint8_t   F;                            /**< 0001: Frequency Divider register                                   */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   S;                            /**< 0003: Status Register                                              */
   __IO uint8_t   D;                            /**< 0004: Data I/O register                                            */
   __IO uint8_t   C2;                           /**< 0005: Control Register 2                                           */
   __IO uint8_t   FLT;                          /**< 0006: Programmable Input Glitch Filter register                    */
   __IO uint8_t   RA;                           /**< 0007: Range Address register                                       */
   __IO uint8_t   SMB;                          /**< 0008: SMBus Control and Status register                            */
   __IO uint8_t   A2;                           /**< 0009: Address Register 2                                           */
   __IO uint8_t   SLTH;                         /**< 000A: SCL Low Timeout Register High                                */
   __IO uint8_t   SLTL;                         /**< 000B: SCL Low Timeout Register Low                                 */
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
/* ------- A1 Bit Fields                            ------ */
#define I2C_A1_AD_MASK                           (0x7FUL << I2C_A1_AD_SHIFT)                         /*!< I2C0_A1: AD Mask                        */
#define I2C_A1_AD_SHIFT                          1                                                   /*!< I2C0_A1: AD Position                    */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK) /*!< I2C0_A1                                 */
/* ------- F Bit Fields                             ------ */
#define I2C_F_ICR_MASK                           (0x3FUL << I2C_F_ICR_SHIFT)                         /*!< I2C0_F: ICR Mask                        */
#define I2C_F_ICR_SHIFT                          0                                                   /*!< I2C0_F: ICR Position                    */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK) /*!< I2C0_F                                  */
#define I2C_F_MULT_MASK                          (0x03UL << I2C_F_MULT_SHIFT)                        /*!< I2C0_F: MULT Mask                       */
#define I2C_F_MULT_SHIFT                         6                                                   /*!< I2C0_F: MULT Position                   */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK) /*!< I2C0_F                                  */
/* ------- C1 Bit Fields                            ------ */
#define I2C_C1_DMAEN_MASK                        (0x01UL << I2C_C1_DMAEN_SHIFT)                      /*!< I2C0_C1: DMAEN Mask                     */
#define I2C_C1_DMAEN_SHIFT                       0                                                   /*!< I2C0_C1: DMAEN Position                 */
#define I2C_C1_WUEN_MASK                         (0x01UL << I2C_C1_WUEN_SHIFT)                       /*!< I2C0_C1: WUEN Mask                      */
#define I2C_C1_WUEN_SHIFT                        1                                                   /*!< I2C0_C1: WUEN Position                  */
#define I2C_C1_RSTA_MASK                         (0x01UL << I2C_C1_RSTA_SHIFT)                       /*!< I2C0_C1: RSTA Mask                      */
#define I2C_C1_RSTA_SHIFT                        2                                                   /*!< I2C0_C1: RSTA Position                  */
#define I2C_C1_TXAK_MASK                         (0x01UL << I2C_C1_TXAK_SHIFT)                       /*!< I2C0_C1: TXAK Mask                      */
#define I2C_C1_TXAK_SHIFT                        3                                                   /*!< I2C0_C1: TXAK Position                  */
#define I2C_C1_TX_MASK                           (0x01UL << I2C_C1_TX_SHIFT)                         /*!< I2C0_C1: TX Mask                        */
#define I2C_C1_TX_SHIFT                          4                                                   /*!< I2C0_C1: TX Position                    */
#define I2C_C1_MST_MASK                          (0x01UL << I2C_C1_MST_SHIFT)                        /*!< I2C0_C1: MST Mask                       */
#define I2C_C1_MST_SHIFT                         5                                                   /*!< I2C0_C1: MST Position                   */
#define I2C_C1_IICIE_MASK                        (0x01UL << I2C_C1_IICIE_SHIFT)                      /*!< I2C0_C1: IICIE Mask                     */
#define I2C_C1_IICIE_SHIFT                       6                                                   /*!< I2C0_C1: IICIE Position                 */
#define I2C_C1_IICEN_MASK                        (0x01UL << I2C_C1_IICEN_SHIFT)                      /*!< I2C0_C1: IICEN Mask                     */
#define I2C_C1_IICEN_SHIFT                       7                                                   /*!< I2C0_C1: IICEN Position                 */
/* ------- S Bit Fields                             ------ */
#define I2C_S_RXAK_MASK                          (0x01UL << I2C_S_RXAK_SHIFT)                        /*!< I2C0_S: RXAK Mask                       */
#define I2C_S_RXAK_SHIFT                         0                                                   /*!< I2C0_S: RXAK Position                   */
#define I2C_S_IICIF_MASK                         (0x01UL << I2C_S_IICIF_SHIFT)                       /*!< I2C0_S: IICIF Mask                      */
#define I2C_S_IICIF_SHIFT                        1                                                   /*!< I2C0_S: IICIF Position                  */
#define I2C_S_SRW_MASK                           (0x01UL << I2C_S_SRW_SHIFT)                         /*!< I2C0_S: SRW Mask                        */
#define I2C_S_SRW_SHIFT                          2                                                   /*!< I2C0_S: SRW Position                    */
#define I2C_S_RAM_MASK                           (0x01UL << I2C_S_RAM_SHIFT)                         /*!< I2C0_S: RAM Mask                        */
#define I2C_S_RAM_SHIFT                          3                                                   /*!< I2C0_S: RAM Position                    */
#define I2C_S_ARBL_MASK                          (0x01UL << I2C_S_ARBL_SHIFT)                        /*!< I2C0_S: ARBL Mask                       */
#define I2C_S_ARBL_SHIFT                         4                                                   /*!< I2C0_S: ARBL Position                   */
#define I2C_S_BUSY_MASK                          (0x01UL << I2C_S_BUSY_SHIFT)                        /*!< I2C0_S: BUSY Mask                       */
#define I2C_S_BUSY_SHIFT                         5                                                   /*!< I2C0_S: BUSY Position                   */
#define I2C_S_IAAS_MASK                          (0x01UL << I2C_S_IAAS_SHIFT)                        /*!< I2C0_S: IAAS Mask                       */
#define I2C_S_IAAS_SHIFT                         6                                                   /*!< I2C0_S: IAAS Position                   */
#define I2C_S_TCF_MASK                           (0x01UL << I2C_S_TCF_SHIFT)                         /*!< I2C0_S: TCF Mask                        */
#define I2C_S_TCF_SHIFT                          7                                                   /*!< I2C0_S: TCF Position                    */
/* ------- D Bit Fields                             ------ */
#define I2C_D_DATA_MASK                          (0xFFUL << I2C_D_DATA_SHIFT)                        /*!< I2C0_D: DATA Mask                       */
#define I2C_D_DATA_SHIFT                         0                                                   /*!< I2C0_D: DATA Position                   */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK) /*!< I2C0_D                                  */
/* ------- C2 Bit Fields                            ------ */
#define I2C_C2_AD_MASK                           (0x07UL << I2C_C2_AD_SHIFT)                         /*!< I2C0_C2: AD Mask                        */
#define I2C_C2_AD_SHIFT                          0                                                   /*!< I2C0_C2: AD Position                    */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_RMEN_MASK                         (0x01UL << I2C_C2_RMEN_SHIFT)                       /*!< I2C0_C2: RMEN Mask                      */
#define I2C_C2_RMEN_SHIFT                        3                                                   /*!< I2C0_C2: RMEN Position                  */
#define I2C_C2_SBRC_MASK                         (0x01UL << I2C_C2_SBRC_SHIFT)                       /*!< I2C0_C2: SBRC Mask                      */
#define I2C_C2_SBRC_SHIFT                        4                                                   /*!< I2C0_C2: SBRC Position                  */
#define I2C_C2_HDRS_MASK                         (0x01UL << I2C_C2_HDRS_SHIFT)                       /*!< I2C0_C2: HDRS Mask                      */
#define I2C_C2_HDRS_SHIFT                        5                                                   /*!< I2C0_C2: HDRS Position                  */
#define I2C_C2_ADEXT_MASK                        (0x01UL << I2C_C2_ADEXT_SHIFT)                      /*!< I2C0_C2: ADEXT Mask                     */
#define I2C_C2_ADEXT_SHIFT                       6                                                   /*!< I2C0_C2: ADEXT Position                 */
#define I2C_C2_GCAEN_MASK                        (0x01UL << I2C_C2_GCAEN_SHIFT)                      /*!< I2C0_C2: GCAEN Mask                     */
#define I2C_C2_GCAEN_SHIFT                       7                                                   /*!< I2C0_C2: GCAEN Position                 */
/* ------- FLT Bit Fields                           ------ */
#define I2C_FLT_FLT_MASK                         (0x1FUL << I2C_FLT_FLT_SHIFT)                       /*!< I2C0_FLT: FLT Mask                      */
#define I2C_FLT_FLT_SHIFT                        0                                                   /*!< I2C0_FLT: FLT Position                  */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK) /*!< I2C0_FLT                                */
/* ------- RA Bit Fields                            ------ */
#define I2C_RA_RAD_MASK                          (0x7FUL << I2C_RA_RAD_SHIFT)                        /*!< I2C0_RA: RAD Mask                       */
#define I2C_RA_RAD_SHIFT                         1                                                   /*!< I2C0_RA: RAD Position                   */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK) /*!< I2C0_RA                                 */
/* ------- SMB Bit Fields                           ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x01UL << I2C_SMB_SHTF2IE_SHIFT)                   /*!< I2C0_SMB: SHTF2IE Mask                  */
#define I2C_SMB_SHTF2IE_SHIFT                    0                                                   /*!< I2C0_SMB: SHTF2IE Position              */
#define I2C_SMB_SHTF2_MASK                       (0x01UL << I2C_SMB_SHTF2_SHIFT)                     /*!< I2C0_SMB: SHTF2 Mask                    */
#define I2C_SMB_SHTF2_SHIFT                      1                                                   /*!< I2C0_SMB: SHTF2 Position                */
#define I2C_SMB_SHTF1_MASK                       (0x01UL << I2C_SMB_SHTF1_SHIFT)                     /*!< I2C0_SMB: SHTF1 Mask                    */
#define I2C_SMB_SHTF1_SHIFT                      2                                                   /*!< I2C0_SMB: SHTF1 Position                */
#define I2C_SMB_SLTF_MASK                        (0x01UL << I2C_SMB_SLTF_SHIFT)                      /*!< I2C0_SMB: SLTF Mask                     */
#define I2C_SMB_SLTF_SHIFT                       3                                                   /*!< I2C0_SMB: SLTF Position                 */
#define I2C_SMB_TCKSEL_MASK                      (0x01UL << I2C_SMB_TCKSEL_SHIFT)                    /*!< I2C0_SMB: TCKSEL Mask                   */
#define I2C_SMB_TCKSEL_SHIFT                     4                                                   /*!< I2C0_SMB: TCKSEL Position               */
#define I2C_SMB_SIICAEN_MASK                     (0x01UL << I2C_SMB_SIICAEN_SHIFT)                   /*!< I2C0_SMB: SIICAEN Mask                  */
#define I2C_SMB_SIICAEN_SHIFT                    5                                                   /*!< I2C0_SMB: SIICAEN Position              */
#define I2C_SMB_ALERTEN_MASK                     (0x01UL << I2C_SMB_ALERTEN_SHIFT)                   /*!< I2C0_SMB: ALERTEN Mask                  */
#define I2C_SMB_ALERTEN_SHIFT                    6                                                   /*!< I2C0_SMB: ALERTEN Position              */
#define I2C_SMB_FACK_MASK                        (0x01UL << I2C_SMB_FACK_SHIFT)                      /*!< I2C0_SMB: FACK Mask                     */
#define I2C_SMB_FACK_SHIFT                       7                                                   /*!< I2C0_SMB: FACK Position                 */
/* ------- A2 Bit Fields                            ------ */
#define I2C_A2_SAD_MASK                          (0x7FUL << I2C_A2_SAD_SHIFT)                        /*!< I2C0_A2: SAD Mask                       */
#define I2C_A2_SAD_SHIFT                         1                                                   /*!< I2C0_A2: SAD Position                   */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK) /*!< I2C0_A2                                 */
/* ------- SLTH Bit Fields                          ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFUL << I2C_SLTH_SSLT_SHIFT)                     /*!< I2C0_SLTH: SSLT Mask                    */
#define I2C_SLTH_SSLT_SHIFT                      0                                                   /*!< I2C0_SLTH: SSLT Position                */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK) /*!< I2C0_SLTH                               */
/* ------- SLTL Bit Fields                          ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFUL << I2C_SLTL_SSLT_SHIFT)                     /*!< I2C0_SLTL: SSLT Mask                    */
#define I2C_SLTL_SSLT_SHIFT                      0                                                   /*!< I2C0_SLTL: SSLT Position                */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK) /*!< I2C0_SLTL                               */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0xFFFF81C0UL //!< Peripheral base address
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
#define I2C1_BasePtr                   0xFFFF81D0UL //!< Peripheral base address
#define I2C1                           ((I2C_Type *) I2C1_BasePtr) //!< Freescale base pointer
#define I2C1_BASE_PTR                  (I2C1) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C2 (derived from I2C0)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */

/* I2C2 - Peripheral instance base addresses */
#define I2C2_BasePtr                   0xFFFF81E0UL //!< Peripheral base address
#define I2C2                           ((I2C_Type *) I2C2_BasePtr) //!< Freescale base pointer
#define I2C2_BASE_PTR                  (I2C2) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C3 (derived from I2C0)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */

/* I2C3 - Peripheral instance base addresses */
#define I2C3_BasePtr                   0xFFFF81F0UL //!< Peripheral base address
#define I2C3                           ((I2C_Type *) I2C3_BasePtr) //!< Freescale base pointer
#define I2C3_BASE_PTR                  (I2C3) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2S_Peripheral_access_layer_GROUP I2S Peripheral Access Layer
* @brief C Struct for I2S
* @{
*/

/* ================================================================================ */
/* ================           I2S0 (file:I2S0_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief Inter-IC Sound / Synchronous Audio Interface
 */
/**
* @addtogroup I2S_structs_GROUP I2S struct
* @brief Struct for I2S
* @{
*/
typedef struct {                                /*       I2S0 Structure                                               */
   __IO uint32_t  TCSR;                         /**< 0000: Transmit Control Register                                    */
   __IO uint32_t  TCR1;                         /**< 0004: Transmit Configuration 1 Register                            */
   __IO uint32_t  TCR2;                         /**< 0008: Transmit Configuration 2 Register                            */
   __IO uint32_t  TCR3;                         /**< 000C: Transmit Configuration 3 Register                            */
   __IO uint32_t  TCR4;                         /**< 0010: Transmit Configuration 4 Register                            */
   __IO uint32_t  TCR5;                         /**< 0014: Transmit Configuration 5 Register                            */
   __I  uint32_t  RESERVED0[2];                
   __IO uint32_t  TDR[1];                       /**< 0020: Transmit Data Register                                       */
   __I  uint32_t  RESERVED1[7];                
   __I  uint32_t  TFR[1];                       /**< 0040: Transmit FIFO Register                                       */
   __I  uint32_t  RESERVED2[7];                
   __IO uint32_t  TMR;                          /**< 0060: Transmit Mask Register                                       */
   __I  uint32_t  RESERVED3[7];                
   __IO uint32_t  RCSR;                         /**< 0080: Receive Control Register                                     */
   __IO uint32_t  RCR1;                         /**< 0084: Receive Configuration 1 Register                             */
   __IO uint32_t  RCR2;                         /**< 0088: Receive Configuration 2 Register                             */
   __IO uint32_t  RCR3;                         /**< 008C: Receive Configuration 3 Register                             */
   __IO uint32_t  RCR4;                         /**< 0090: Receive Configuration 4 Register                             */
   __IO uint32_t  RCR5;                         /**< 0094: Receive Configuration 5 Register                             */
   __I  uint32_t  RESERVED4[2];                
   __I  uint32_t  RDR[1];                       /**< 00A0: Receive Data Register                                        */
   __I  uint32_t  RESERVED5[7];                
   __I  uint32_t  RFR[1];                       /**< 00C0: Receive FIFO Register                                        */
   __I  uint32_t  RESERVED6[7];                
   __IO uint32_t  RMR;                          /**< 00E0: Receive Mask Register                                        */
   __I  uint32_t  RESERVED7[7];                
   __IO uint32_t  MCR;                          /**< 0100: MCLK Control Register                                        */
   __IO uint32_t  MDR;                          /**< 0104: MCLK Divide Register                                         */
} I2S_Type;

/**
 * @} */ /* End group I2S_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2S0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2S_Register_Masks_GROUP I2S Register Masks
* @brief Register Masks for I2S
* @{
*/
/* ------- TCSR Bit Fields                          ------ */
#define I2S_TCSR_FRDE_MASK                       (0x01UL << I2S_TCSR_FRDE_SHIFT)                     /*!< I2S0_TCSR: FRDE Mask                    */
#define I2S_TCSR_FRDE_SHIFT                      0                                                   /*!< I2S0_TCSR: FRDE Position                */
#define I2S_TCSR_FWDE_MASK                       (0x01UL << I2S_TCSR_FWDE_SHIFT)                     /*!< I2S0_TCSR: FWDE Mask                    */
#define I2S_TCSR_FWDE_SHIFT                      1                                                   /*!< I2S0_TCSR: FWDE Position                */
#define I2S_TCSR_FRIE_MASK                       (0x01UL << I2S_TCSR_FRIE_SHIFT)                     /*!< I2S0_TCSR: FRIE Mask                    */
#define I2S_TCSR_FRIE_SHIFT                      8                                                   /*!< I2S0_TCSR: FRIE Position                */
#define I2S_TCSR_FWIE_MASK                       (0x01UL << I2S_TCSR_FWIE_SHIFT)                     /*!< I2S0_TCSR: FWIE Mask                    */
#define I2S_TCSR_FWIE_SHIFT                      9                                                   /*!< I2S0_TCSR: FWIE Position                */
#define I2S_TCSR_FEIE_MASK                       (0x01UL << I2S_TCSR_FEIE_SHIFT)                     /*!< I2S0_TCSR: FEIE Mask                    */
#define I2S_TCSR_FEIE_SHIFT                      10                                                  /*!< I2S0_TCSR: FEIE Position                */
#define I2S_TCSR_SEIE_MASK                       (0x01UL << I2S_TCSR_SEIE_SHIFT)                     /*!< I2S0_TCSR: SEIE Mask                    */
#define I2S_TCSR_SEIE_SHIFT                      11                                                  /*!< I2S0_TCSR: SEIE Position                */
#define I2S_TCSR_WSIE_MASK                       (0x01UL << I2S_TCSR_WSIE_SHIFT)                     /*!< I2S0_TCSR: WSIE Mask                    */
#define I2S_TCSR_WSIE_SHIFT                      12                                                  /*!< I2S0_TCSR: WSIE Position                */
#define I2S_TCSR_FRF_MASK                        (0x01UL << I2S_TCSR_FRF_SHIFT)                      /*!< I2S0_TCSR: FRF Mask                     */
#define I2S_TCSR_FRF_SHIFT                       16                                                  /*!< I2S0_TCSR: FRF Position                 */
#define I2S_TCSR_FWF_MASK                        (0x01UL << I2S_TCSR_FWF_SHIFT)                      /*!< I2S0_TCSR: FWF Mask                     */
#define I2S_TCSR_FWF_SHIFT                       17                                                  /*!< I2S0_TCSR: FWF Position                 */
#define I2S_TCSR_FEF_MASK                        (0x01UL << I2S_TCSR_FEF_SHIFT)                      /*!< I2S0_TCSR: FEF Mask                     */
#define I2S_TCSR_FEF_SHIFT                       18                                                  /*!< I2S0_TCSR: FEF Position                 */
#define I2S_TCSR_SEF_MASK                        (0x01UL << I2S_TCSR_SEF_SHIFT)                      /*!< I2S0_TCSR: SEF Mask                     */
#define I2S_TCSR_SEF_SHIFT                       19                                                  /*!< I2S0_TCSR: SEF Position                 */
#define I2S_TCSR_WSF_MASK                        (0x01UL << I2S_TCSR_WSF_SHIFT)                      /*!< I2S0_TCSR: WSF Mask                     */
#define I2S_TCSR_WSF_SHIFT                       20                                                  /*!< I2S0_TCSR: WSF Position                 */
#define I2S_TCSR_SR_MASK                         (0x01UL << I2S_TCSR_SR_SHIFT)                       /*!< I2S0_TCSR: SR Mask                      */
#define I2S_TCSR_SR_SHIFT                        24                                                  /*!< I2S0_TCSR: SR Position                  */
#define I2S_TCSR_FR_MASK                         (0x01UL << I2S_TCSR_FR_SHIFT)                       /*!< I2S0_TCSR: FR Mask                      */
#define I2S_TCSR_FR_SHIFT                        25                                                  /*!< I2S0_TCSR: FR Position                  */
#define I2S_TCSR_BCE_MASK                        (0x01UL << I2S_TCSR_BCE_SHIFT)                      /*!< I2S0_TCSR: BCE Mask                     */
#define I2S_TCSR_BCE_SHIFT                       28                                                  /*!< I2S0_TCSR: BCE Position                 */
#define I2S_TCSR_DBGE_MASK                       (0x01UL << I2S_TCSR_DBGE_SHIFT)                     /*!< I2S0_TCSR: DBGE Mask                    */
#define I2S_TCSR_DBGE_SHIFT                      29                                                  /*!< I2S0_TCSR: DBGE Position                */
#define I2S_TCSR_STOPE_MASK                      (0x01UL << I2S_TCSR_STOPE_SHIFT)                    /*!< I2S0_TCSR: STOPE Mask                   */
#define I2S_TCSR_STOPE_SHIFT                     30                                                  /*!< I2S0_TCSR: STOPE Position               */
#define I2S_TCSR_TE_MASK                         (0x01UL << I2S_TCSR_TE_SHIFT)                       /*!< I2S0_TCSR: TE Mask                      */
#define I2S_TCSR_TE_SHIFT                        31                                                  /*!< I2S0_TCSR: TE Position                  */
/* ------- TCR1 Bit Fields                          ------ */
#define I2S_TCR1_TFW_MASK                        (0x03UL << I2S_TCR1_TFW_SHIFT)                      /*!< I2S0_TCR1: TFW Mask                     */
#define I2S_TCR1_TFW_SHIFT                       0                                                   /*!< I2S0_TCR1: TFW Position                 */
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR1_TFW_SHIFT))&I2S_TCR1_TFW_MASK) /*!< I2S0_TCR1                               */
/* ------- TCR2 Bit Fields                          ------ */
#define I2S_TCR2_DIV_MASK                        (0xFFUL << I2S_TCR2_DIV_SHIFT)                      /*!< I2S0_TCR2: DIV Mask                     */
#define I2S_TCR2_DIV_SHIFT                       0                                                   /*!< I2S0_TCR2: DIV Position                 */
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_DIV_SHIFT))&I2S_TCR2_DIV_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCD_MASK                        (0x01UL << I2S_TCR2_BCD_SHIFT)                      /*!< I2S0_TCR2: BCD Mask                     */
#define I2S_TCR2_BCD_SHIFT                       24                                                  /*!< I2S0_TCR2: BCD Position                 */
#define I2S_TCR2_BCP_MASK                        (0x01UL << I2S_TCR2_BCP_SHIFT)                      /*!< I2S0_TCR2: BCP Mask                     */
#define I2S_TCR2_BCP_SHIFT                       25                                                  /*!< I2S0_TCR2: BCP Position                 */
#define I2S_TCR2_MSEL_MASK                       (0x03UL << I2S_TCR2_MSEL_SHIFT)                     /*!< I2S0_TCR2: MSEL Mask                    */
#define I2S_TCR2_MSEL_SHIFT                      26                                                  /*!< I2S0_TCR2: MSEL Position                */
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_MSEL_SHIFT))&I2S_TCR2_MSEL_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCI_MASK                        (0x01UL << I2S_TCR2_BCI_SHIFT)                      /*!< I2S0_TCR2: BCI Mask                     */
#define I2S_TCR2_BCI_SHIFT                       28                                                  /*!< I2S0_TCR2: BCI Position                 */
#define I2S_TCR2_BCS_MASK                        (0x01UL << I2S_TCR2_BCS_SHIFT)                      /*!< I2S0_TCR2: BCS Mask                     */
#define I2S_TCR2_BCS_SHIFT                       29                                                  /*!< I2S0_TCR2: BCS Position                 */
#define I2S_TCR2_SYNC_MASK                       (0x03UL << I2S_TCR2_SYNC_SHIFT)                     /*!< I2S0_TCR2: SYNC Mask                    */
#define I2S_TCR2_SYNC_SHIFT                      30                                                  /*!< I2S0_TCR2: SYNC Position                */
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_SYNC_SHIFT))&I2S_TCR2_SYNC_MASK) /*!< I2S0_TCR2                               */
/* ------- TCR3 Bit Fields                          ------ */
#define I2S_TCR3_WDFL_MASK                       (0x1FUL << I2S_TCR3_WDFL_SHIFT)                     /*!< I2S0_TCR3: WDFL Mask                    */
#define I2S_TCR3_WDFL_SHIFT                      0                                                   /*!< I2S0_TCR3: WDFL Position                */
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_WDFL_SHIFT))&I2S_TCR3_WDFL_MASK) /*!< I2S0_TCR3                               */
#define I2S_TCR3_TCE_MASK                        (0x01UL << I2S_TCR3_TCE_SHIFT)                      /*!< I2S0_TCR3: TCE Mask                     */
#define I2S_TCR3_TCE_SHIFT                       16                                                  /*!< I2S0_TCR3: TCE Position                 */
/* ------- TCR4 Bit Fields                          ------ */
#define I2S_TCR4_FSD_MASK                        (0x01UL << I2S_TCR4_FSD_SHIFT)                      /*!< I2S0_TCR4: FSD Mask                     */
#define I2S_TCR4_FSD_SHIFT                       0                                                   /*!< I2S0_TCR4: FSD Position                 */
#define I2S_TCR4_FSP_MASK                        (0x01UL << I2S_TCR4_FSP_SHIFT)                      /*!< I2S0_TCR4: FSP Mask                     */
#define I2S_TCR4_FSP_SHIFT                       1                                                   /*!< I2S0_TCR4: FSP Position                 */
#define I2S_TCR4_FSE_MASK                        (0x01UL << I2S_TCR4_FSE_SHIFT)                      /*!< I2S0_TCR4: FSE Mask                     */
#define I2S_TCR4_FSE_SHIFT                       3                                                   /*!< I2S0_TCR4: FSE Position                 */
#define I2S_TCR4_MF_MASK                         (0x01UL << I2S_TCR4_MF_SHIFT)                       /*!< I2S0_TCR4: MF Mask                      */
#define I2S_TCR4_MF_SHIFT                        4                                                   /*!< I2S0_TCR4: MF Position                  */
#define I2S_TCR4_SYWD_MASK                       (0x1FUL << I2S_TCR4_SYWD_SHIFT)                     /*!< I2S0_TCR4: SYWD Mask                    */
#define I2S_TCR4_SYWD_SHIFT                      8                                                   /*!< I2S0_TCR4: SYWD Position                */
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_SYWD_SHIFT))&I2S_TCR4_SYWD_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FRSZ_MASK                       (0x1FUL << I2S_TCR4_FRSZ_SHIFT)                     /*!< I2S0_TCR4: FRSZ Mask                    */
#define I2S_TCR4_FRSZ_SHIFT                      16                                                  /*!< I2S0_TCR4: FRSZ Position                */
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FRSZ_SHIFT))&I2S_TCR4_FRSZ_MASK) /*!< I2S0_TCR4                               */
/* ------- TCR5 Bit Fields                          ------ */
#define I2S_TCR5_FBT_MASK                        (0x1FUL << I2S_TCR5_FBT_SHIFT)                      /*!< I2S0_TCR5: FBT Mask                     */
#define I2S_TCR5_FBT_SHIFT                       8                                                   /*!< I2S0_TCR5: FBT Position                 */
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_FBT_SHIFT))&I2S_TCR5_FBT_MASK) /*!< I2S0_TCR5                               */
#define I2S_TCR5_W0W_MASK                        (0x1FUL << I2S_TCR5_W0W_SHIFT)                      /*!< I2S0_TCR5: W0W Mask                     */
#define I2S_TCR5_W0W_SHIFT                       16                                                  /*!< I2S0_TCR5: W0W Position                 */
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_W0W_SHIFT))&I2S_TCR5_W0W_MASK) /*!< I2S0_TCR5                               */
#define I2S_TCR5_WNW_MASK                        (0x1FUL << I2S_TCR5_WNW_SHIFT)                      /*!< I2S0_TCR5: WNW Mask                     */
#define I2S_TCR5_WNW_SHIFT                       24                                                  /*!< I2S0_TCR5: WNW Position                 */
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_WNW_SHIFT))&I2S_TCR5_WNW_MASK) /*!< I2S0_TCR5                               */
/* ------- TDR Bit Fields                           ------ */
#define I2S_TDR_TDR_MASK                         (0xFFFFFFFFUL << I2S_TDR_TDR_SHIFT)                 /*!< I2S0_TDR: TDR Mask                      */
#define I2S_TDR_TDR_SHIFT                        0                                                   /*!< I2S0_TDR: TDR Position                  */
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TDR_TDR_SHIFT))&I2S_TDR_TDR_MASK) /*!< I2S0_TDR                                */
/* ------- TFR Bit Fields                           ------ */
#define I2S_TFR_RFP_MASK                         (0x07UL << I2S_TFR_RFP_SHIFT)                       /*!< I2S0_TFR: RFP Mask                      */
#define I2S_TFR_RFP_SHIFT                        0                                                   /*!< I2S0_TFR: RFP Position                  */
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_RFP_SHIFT))&I2S_TFR_RFP_MASK) /*!< I2S0_TFR                                */
#define I2S_TFR_WFP_MASK                         (0x07UL << I2S_TFR_WFP_SHIFT)                       /*!< I2S0_TFR: WFP Mask                      */
#define I2S_TFR_WFP_SHIFT                        16                                                  /*!< I2S0_TFR: WFP Position                  */
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_WFP_SHIFT))&I2S_TFR_WFP_MASK) /*!< I2S0_TFR                                */
/* ------- TMR Bit Fields                           ------ */
#define I2S_TMR_TWM_MASK                         (0xFFFFFFFFUL << I2S_TMR_TWM_SHIFT)                 /*!< I2S0_TMR: TWM Mask                      */
#define I2S_TMR_TWM_SHIFT                        0                                                   /*!< I2S0_TMR: TWM Position                  */
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TMR_TWM_SHIFT))&I2S_TMR_TWM_MASK) /*!< I2S0_TMR                                */
/* ------- RCSR Bit Fields                          ------ */
#define I2S_RCSR_FRDE_MASK                       (0x01UL << I2S_RCSR_FRDE_SHIFT)                     /*!< I2S0_RCSR: FRDE Mask                    */
#define I2S_RCSR_FRDE_SHIFT                      0                                                   /*!< I2S0_RCSR: FRDE Position                */
#define I2S_RCSR_FWDE_MASK                       (0x01UL << I2S_RCSR_FWDE_SHIFT)                     /*!< I2S0_RCSR: FWDE Mask                    */
#define I2S_RCSR_FWDE_SHIFT                      1                                                   /*!< I2S0_RCSR: FWDE Position                */
#define I2S_RCSR_FRIE_MASK                       (0x01UL << I2S_RCSR_FRIE_SHIFT)                     /*!< I2S0_RCSR: FRIE Mask                    */
#define I2S_RCSR_FRIE_SHIFT                      8                                                   /*!< I2S0_RCSR: FRIE Position                */
#define I2S_RCSR_FWIE_MASK                       (0x01UL << I2S_RCSR_FWIE_SHIFT)                     /*!< I2S0_RCSR: FWIE Mask                    */
#define I2S_RCSR_FWIE_SHIFT                      9                                                   /*!< I2S0_RCSR: FWIE Position                */
#define I2S_RCSR_FEIE_MASK                       (0x01UL << I2S_RCSR_FEIE_SHIFT)                     /*!< I2S0_RCSR: FEIE Mask                    */
#define I2S_RCSR_FEIE_SHIFT                      10                                                  /*!< I2S0_RCSR: FEIE Position                */
#define I2S_RCSR_SEIE_MASK                       (0x01UL << I2S_RCSR_SEIE_SHIFT)                     /*!< I2S0_RCSR: SEIE Mask                    */
#define I2S_RCSR_SEIE_SHIFT                      11                                                  /*!< I2S0_RCSR: SEIE Position                */
#define I2S_RCSR_WSIE_MASK                       (0x01UL << I2S_RCSR_WSIE_SHIFT)                     /*!< I2S0_RCSR: WSIE Mask                    */
#define I2S_RCSR_WSIE_SHIFT                      12                                                  /*!< I2S0_RCSR: WSIE Position                */
#define I2S_RCSR_FRF_MASK                        (0x01UL << I2S_RCSR_FRF_SHIFT)                      /*!< I2S0_RCSR: FRF Mask                     */
#define I2S_RCSR_FRF_SHIFT                       16                                                  /*!< I2S0_RCSR: FRF Position                 */
#define I2S_RCSR_FWF_MASK                        (0x01UL << I2S_RCSR_FWF_SHIFT)                      /*!< I2S0_RCSR: FWF Mask                     */
#define I2S_RCSR_FWF_SHIFT                       17                                                  /*!< I2S0_RCSR: FWF Position                 */
#define I2S_RCSR_FEF_MASK                        (0x01UL << I2S_RCSR_FEF_SHIFT)                      /*!< I2S0_RCSR: FEF Mask                     */
#define I2S_RCSR_FEF_SHIFT                       18                                                  /*!< I2S0_RCSR: FEF Position                 */
#define I2S_RCSR_SEF_MASK                        (0x01UL << I2S_RCSR_SEF_SHIFT)                      /*!< I2S0_RCSR: SEF Mask                     */
#define I2S_RCSR_SEF_SHIFT                       19                                                  /*!< I2S0_RCSR: SEF Position                 */
#define I2S_RCSR_WSF_MASK                        (0x01UL << I2S_RCSR_WSF_SHIFT)                      /*!< I2S0_RCSR: WSF Mask                     */
#define I2S_RCSR_WSF_SHIFT                       20                                                  /*!< I2S0_RCSR: WSF Position                 */
#define I2S_RCSR_SR_MASK                         (0x01UL << I2S_RCSR_SR_SHIFT)                       /*!< I2S0_RCSR: SR Mask                      */
#define I2S_RCSR_SR_SHIFT                        24                                                  /*!< I2S0_RCSR: SR Position                  */
#define I2S_RCSR_FR_MASK                         (0x01UL << I2S_RCSR_FR_SHIFT)                       /*!< I2S0_RCSR: FR Mask                      */
#define I2S_RCSR_FR_SHIFT                        25                                                  /*!< I2S0_RCSR: FR Position                  */
#define I2S_RCSR_BCE_MASK                        (0x01UL << I2S_RCSR_BCE_SHIFT)                      /*!< I2S0_RCSR: BCE Mask                     */
#define I2S_RCSR_BCE_SHIFT                       28                                                  /*!< I2S0_RCSR: BCE Position                 */
#define I2S_RCSR_DBGE_MASK                       (0x01UL << I2S_RCSR_DBGE_SHIFT)                     /*!< I2S0_RCSR: DBGE Mask                    */
#define I2S_RCSR_DBGE_SHIFT                      29                                                  /*!< I2S0_RCSR: DBGE Position                */
#define I2S_RCSR_STOPE_MASK                      (0x01UL << I2S_RCSR_STOPE_SHIFT)                    /*!< I2S0_RCSR: STOPE Mask                   */
#define I2S_RCSR_STOPE_SHIFT                     30                                                  /*!< I2S0_RCSR: STOPE Position               */
#define I2S_RCSR_RE_MASK                         (0x01UL << I2S_RCSR_RE_SHIFT)                       /*!< I2S0_RCSR: RE Mask                      */
#define I2S_RCSR_RE_SHIFT                        31                                                  /*!< I2S0_RCSR: RE Position                  */
/* ------- RCR1 Bit Fields                          ------ */
#define I2S_RCR1_RFW_MASK                        (0x03UL << I2S_RCR1_RFW_SHIFT)                      /*!< I2S0_RCR1: RFW Mask                     */
#define I2S_RCR1_RFW_SHIFT                       0                                                   /*!< I2S0_RCR1: RFW Position                 */
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR1_RFW_SHIFT))&I2S_RCR1_RFW_MASK) /*!< I2S0_RCR1                               */
/* ------- RCR2 Bit Fields                          ------ */
#define I2S_RCR2_DIV_MASK                        (0xFFUL << I2S_RCR2_DIV_SHIFT)                      /*!< I2S0_RCR2: DIV Mask                     */
#define I2S_RCR2_DIV_SHIFT                       0                                                   /*!< I2S0_RCR2: DIV Position                 */
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_DIV_SHIFT))&I2S_RCR2_DIV_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCD_MASK                        (0x01UL << I2S_RCR2_BCD_SHIFT)                      /*!< I2S0_RCR2: BCD Mask                     */
#define I2S_RCR2_BCD_SHIFT                       24                                                  /*!< I2S0_RCR2: BCD Position                 */
#define I2S_RCR2_BCP_MASK                        (0x01UL << I2S_RCR2_BCP_SHIFT)                      /*!< I2S0_RCR2: BCP Mask                     */
#define I2S_RCR2_BCP_SHIFT                       25                                                  /*!< I2S0_RCR2: BCP Position                 */
#define I2S_RCR2_MSEL_MASK                       (0x03UL << I2S_RCR2_MSEL_SHIFT)                     /*!< I2S0_RCR2: MSEL Mask                    */
#define I2S_RCR2_MSEL_SHIFT                      26                                                  /*!< I2S0_RCR2: MSEL Position                */
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_MSEL_SHIFT))&I2S_RCR2_MSEL_MASK) /*!< I2S0_RCR2                               */
/* ------- RCR3 Bit Fields                          ------ */
#define I2S_RCR3_WDFL_MASK                       (0x0FUL << I2S_RCR3_WDFL_SHIFT)                     /*!< I2S0_RCR3: WDFL Mask                    */
#define I2S_RCR3_WDFL_SHIFT                      0                                                   /*!< I2S0_RCR3: WDFL Position                */
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_WDFL_SHIFT))&I2S_RCR3_WDFL_MASK) /*!< I2S0_RCR3                               */
#define I2S_RCR3_RCE_MASK                        (0x01UL << I2S_RCR3_RCE_SHIFT)                      /*!< I2S0_RCR3: RCE Mask                     */
#define I2S_RCR3_RCE_SHIFT                       16                                                  /*!< I2S0_RCR3: RCE Position                 */
/* ------- RCR4 Bit Fields                          ------ */
#define I2S_RCR4_FSD_MASK                        (0x01UL << I2S_RCR4_FSD_SHIFT)                      /*!< I2S0_RCR4: FSD Mask                     */
#define I2S_RCR4_FSD_SHIFT                       0                                                   /*!< I2S0_RCR4: FSD Position                 */
#define I2S_RCR4_FSP_MASK                        (0x01UL << I2S_RCR4_FSP_SHIFT)                      /*!< I2S0_RCR4: FSP Mask                     */
#define I2S_RCR4_FSP_SHIFT                       1                                                   /*!< I2S0_RCR4: FSP Position                 */
#define I2S_RCR4_FSE_MASK                        (0x01UL << I2S_RCR4_FSE_SHIFT)                      /*!< I2S0_RCR4: FSE Mask                     */
#define I2S_RCR4_FSE_SHIFT                       3                                                   /*!< I2S0_RCR4: FSE Position                 */
#define I2S_RCR4_MF_MASK                         (0x01UL << I2S_RCR4_MF_SHIFT)                       /*!< I2S0_RCR4: MF Mask                      */
#define I2S_RCR4_MF_SHIFT                        4                                                   /*!< I2S0_RCR4: MF Position                  */
#define I2S_RCR4_SYWD_MASK                       (0x1FUL << I2S_RCR4_SYWD_SHIFT)                     /*!< I2S0_RCR4: SYWD Mask                    */
#define I2S_RCR4_SYWD_SHIFT                      8                                                   /*!< I2S0_RCR4: SYWD Position                */
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_SYWD_SHIFT))&I2S_RCR4_SYWD_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FRSZ_MASK                       (0x1FUL << I2S_RCR4_FRSZ_SHIFT)                     /*!< I2S0_RCR4: FRSZ Mask                    */
#define I2S_RCR4_FRSZ_SHIFT                      16                                                  /*!< I2S0_RCR4: FRSZ Position                */
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FRSZ_SHIFT))&I2S_RCR4_FRSZ_MASK) /*!< I2S0_RCR4                               */
/* ------- RCR5 Bit Fields                          ------ */
#define I2S_RCR5_FBT_MASK                        (0x1FUL << I2S_RCR5_FBT_SHIFT)                      /*!< I2S0_RCR5: FBT Mask                     */
#define I2S_RCR5_FBT_SHIFT                       8                                                   /*!< I2S0_RCR5: FBT Position                 */
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_FBT_SHIFT))&I2S_RCR5_FBT_MASK) /*!< I2S0_RCR5                               */
#define I2S_RCR5_W0W_MASK                        (0x1FUL << I2S_RCR5_W0W_SHIFT)                      /*!< I2S0_RCR5: W0W Mask                     */
#define I2S_RCR5_W0W_SHIFT                       16                                                  /*!< I2S0_RCR5: W0W Position                 */
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_W0W_SHIFT))&I2S_RCR5_W0W_MASK) /*!< I2S0_RCR5                               */
#define I2S_RCR5_WNW_MASK                        (0x1FUL << I2S_RCR5_WNW_SHIFT)                      /*!< I2S0_RCR5: WNW Mask                     */
#define I2S_RCR5_WNW_SHIFT                       24                                                  /*!< I2S0_RCR5: WNW Position                 */
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_WNW_SHIFT))&I2S_RCR5_WNW_MASK) /*!< I2S0_RCR5                               */
/* ------- RDR Bit Fields                           ------ */
#define I2S_RDR_RDR_MASK                         (0xFFFFFFFFUL << I2S_RDR_RDR_SHIFT)                 /*!< I2S0_RDR: RDR Mask                      */
#define I2S_RDR_RDR_SHIFT                        0                                                   /*!< I2S0_RDR: RDR Position                  */
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RDR_RDR_SHIFT))&I2S_RDR_RDR_MASK) /*!< I2S0_RDR                                */
/* ------- RFR Bit Fields                           ------ */
#define I2S_RFR_RFP_MASK                         (0x07UL << I2S_RFR_RFP_SHIFT)                       /*!< I2S0_RFR: RFP Mask                      */
#define I2S_RFR_RFP_SHIFT                        0                                                   /*!< I2S0_RFR: RFP Position                  */
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_RFP_SHIFT))&I2S_RFR_RFP_MASK) /*!< I2S0_RFR                                */
#define I2S_RFR_WFP_MASK                         (0x07UL << I2S_RFR_WFP_SHIFT)                       /*!< I2S0_RFR: WFP Mask                      */
#define I2S_RFR_WFP_SHIFT                        16                                                  /*!< I2S0_RFR: WFP Position                  */
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_WFP_SHIFT))&I2S_RFR_WFP_MASK) /*!< I2S0_RFR                                */
/* ------- RMR Bit Fields                           ------ */
#define I2S_RMR_RWM_MASK                         (0xFFFFFFFFUL << I2S_RMR_RWM_SHIFT)                 /*!< I2S0_RMR: RWM Mask                      */
#define I2S_RMR_RWM_SHIFT                        0                                                   /*!< I2S0_RMR: RWM Position                  */
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RMR_RWM_SHIFT))&I2S_RMR_RWM_MASK) /*!< I2S0_RMR                                */
/* ------- MCR Bit Fields                           ------ */
#define I2S_MCR_MICS_MASK                        (0x03UL << I2S_MCR_MICS_SHIFT)                      /*!< I2S0_MCR: MICS Mask                     */
#define I2S_MCR_MICS_SHIFT                       24                                                  /*!< I2S0_MCR: MICS Position                 */
#define I2S_MCR_MICS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MICS_SHIFT))&I2S_MCR_MICS_MASK) /*!< I2S0_MCR                                */
#define I2S_MCR_MOE_MASK                         (0x01UL << I2S_MCR_MOE_SHIFT)                       /*!< I2S0_MCR: MOE Mask                      */
#define I2S_MCR_MOE_SHIFT                        30                                                  /*!< I2S0_MCR: MOE Position                  */
#define I2S_MCR_DUF_MASK                         (0x01UL << I2S_MCR_DUF_SHIFT)                       /*!< I2S0_MCR: DUF Mask                      */
#define I2S_MCR_DUF_SHIFT                        31                                                  /*!< I2S0_MCR: DUF Position                  */
/* ------- MDR Bit Fields                           ------ */
#define I2S_MDR_DIVIDE_MASK                      (0xFFFUL << I2S_MDR_DIVIDE_SHIFT)                   /*!< I2S0_MDR: DIVIDE Mask                   */
#define I2S_MDR_DIVIDE_SHIFT                     0                                                   /*!< I2S0_MDR: DIVIDE Position               */
#define I2S_MDR_DIVIDE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_MDR_DIVIDE_SHIFT))&I2S_MDR_DIVIDE_MASK) /*!< I2S0_MDR                                */
#define I2S_MDR_FRACT_MASK                       (0xFFUL << I2S_MDR_FRACT_SHIFT)                     /*!< I2S0_MDR: FRACT Mask                    */
#define I2S_MDR_FRACT_SHIFT                      12                                                  /*!< I2S0_MDR: FRACT Position                */
#define I2S_MDR_FRACT(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_MDR_FRACT_SHIFT))&I2S_MDR_FRACT_MASK) /*!< I2S0_MDR                                */
/**
 * @} */ /* End group I2S_Register_Masks_GROUP 
 */

/* I2S0 - Peripheral instance base addresses */
#define I2S0_BasePtr                   0xFFFF8200UL //!< Peripheral base address
#define I2S0                           ((I2S_Type *) I2S0_BasePtr) //!< Freescale base pointer
#define I2S0_BASE_PTR                  (I2S0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2S_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup INTC_Peripheral_access_layer_GROUP INTC Peripheral Access Layer
* @brief C Struct for INTC
* @{
*/

/* ================================================================================ */
/* ================           INTC0 (file:INTC0_MCF51)             ================ */
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
   __I  uint32_t  RESERVED0[2];                
   __IO uint32_t  IMRH;                         /**< 0008: Interrupt Mask Register High                                 */
   __IO uint32_t  IMRL;                         /**< 000C: Interrupt Mask Register Low                                  */
   __IO uint8_t   FRC;                          /**< 0010: Force Interrupt Register                                     */
   __I  uint8_t   RESERVED1[7];                
   __IO uint8_t   PL6P7;                        /**< 0018: Programmable Level 6 Priority 7 Register                     */
   __IO uint8_t   PL6P6;                        /**< 0019: Programmable Level 6 Priority 6 Register                     */
   __I  uint8_t   RESERVED2;                   
   __IO uint8_t   WCR;                          /**< 001B: Wakeup Control Register                                      */
   __IO uint8_t   SIMR;                         /**< 001C: Set Interrupt Mask Register                                  */
   __IO uint8_t   CIMR;                         /**< 001D: Clear Interrupt Mask Register                                */
   __IO uint8_t   SFRC;                         /**< 001E: Set Interrupt Force Register                                 */
   __IO uint8_t   CFRC;                         /**< 001F: Clear Interrupt Force Register                               */
   __I  uint8_t   SWIACK;                       /**< 0020: Software IACK Register                                       */
   __I  uint8_t   RESERVED3[3];                
   __I  uint8_t   LVL1IACK;                     /**< 0024: Level 1 IACK Register                                        */
   __I  uint8_t   RESERVED4[3];                
   __I  uint8_t   LVL2IACK;                     /**< 0028: Level 2 IACK Register                                        */
   __I  uint8_t   RESERVED5[3];                
   __I  uint8_t   LVL3IACK;                     /**< 002C: Level 3 IACK Register                                        */
   __I  uint8_t   RESERVED6[3];                
   __I  uint8_t   LVL4IACK;                     /**< 0030: Level 4 IACK Register                                        */
   __I  uint8_t   RESERVED7[3];                
   __I  uint8_t   LVL5IACK;                     /**< 0034: Level 5 IACK Register                                        */
   __I  uint8_t   RESERVED8[3];                
   __I  uint8_t   LVL6IACK;                     /**< 0038: Level 6 IACK Register                                        */
   __I  uint8_t   RESERVED9[3];                
   __I  uint8_t   LVL7IACK;                     /**< 003C: Level 7 IACK Register                                        */
   __I  uint8_t   RESERVED10[3];               
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
/* ------- IMRH Bit Fields                          ------ */
#define INTC_IMRH_IMR32_MASK                     (0x01UL << INTC_IMRH_IMR32_SHIFT)                   /*!< INTC0_IMRH: IMR32 Mask                  */
#define INTC_IMRH_IMR32_SHIFT                    0                                                   /*!< INTC0_IMRH: IMR32 Position              */
#define INTC_IMRH_IMR33_MASK                     (0x01UL << INTC_IMRH_IMR33_SHIFT)                   /*!< INTC0_IMRH: IMR33 Mask                  */
#define INTC_IMRH_IMR33_SHIFT                    1                                                   /*!< INTC0_IMRH: IMR33 Position              */
#define INTC_IMRH_IMR34_MASK                     (0x01UL << INTC_IMRH_IMR34_SHIFT)                   /*!< INTC0_IMRH: IMR34 Mask                  */
#define INTC_IMRH_IMR34_SHIFT                    2                                                   /*!< INTC0_IMRH: IMR34 Position              */
#define INTC_IMRH_IMR35_MASK                     (0x01UL << INTC_IMRH_IMR35_SHIFT)                   /*!< INTC0_IMRH: IMR35 Mask                  */
#define INTC_IMRH_IMR35_SHIFT                    3                                                   /*!< INTC0_IMRH: IMR35 Position              */
#define INTC_IMRH_IMR36_MASK                     (0x01UL << INTC_IMRH_IMR36_SHIFT)                   /*!< INTC0_IMRH: IMR36 Mask                  */
#define INTC_IMRH_IMR36_SHIFT                    4                                                   /*!< INTC0_IMRH: IMR36 Position              */
#define INTC_IMRH_IMR37_MASK                     (0x01UL << INTC_IMRH_IMR37_SHIFT)                   /*!< INTC0_IMRH: IMR37 Mask                  */
#define INTC_IMRH_IMR37_SHIFT                    5                                                   /*!< INTC0_IMRH: IMR37 Position              */
#define INTC_IMRH_IMR38_MASK                     (0x01UL << INTC_IMRH_IMR38_SHIFT)                   /*!< INTC0_IMRH: IMR38 Mask                  */
#define INTC_IMRH_IMR38_SHIFT                    6                                                   /*!< INTC0_IMRH: IMR38 Position              */
#define INTC_IMRH_IMR39_MASK                     (0x01UL << INTC_IMRH_IMR39_SHIFT)                   /*!< INTC0_IMRH: IMR39 Mask                  */
#define INTC_IMRH_IMR39_SHIFT                    7                                                   /*!< INTC0_IMRH: IMR39 Position              */
#define INTC_IMRH_IMR40_MASK                     (0x01UL << INTC_IMRH_IMR40_SHIFT)                   /*!< INTC0_IMRH: IMR40 Mask                  */
#define INTC_IMRH_IMR40_SHIFT                    8                                                   /*!< INTC0_IMRH: IMR40 Position              */
#define INTC_IMRH_IMR41_MASK                     (0x01UL << INTC_IMRH_IMR41_SHIFT)                   /*!< INTC0_IMRH: IMR41 Mask                  */
#define INTC_IMRH_IMR41_SHIFT                    9                                                   /*!< INTC0_IMRH: IMR41 Position              */
#define INTC_IMRH_IMR42_MASK                     (0x01UL << INTC_IMRH_IMR42_SHIFT)                   /*!< INTC0_IMRH: IMR42 Mask                  */
#define INTC_IMRH_IMR42_SHIFT                    10                                                  /*!< INTC0_IMRH: IMR42 Position              */
#define INTC_IMRH_IMR43_MASK                     (0x01UL << INTC_IMRH_IMR43_SHIFT)                   /*!< INTC0_IMRH: IMR43 Mask                  */
#define INTC_IMRH_IMR43_SHIFT                    11                                                  /*!< INTC0_IMRH: IMR43 Position              */
#define INTC_IMRH_IMR44_MASK                     (0x01UL << INTC_IMRH_IMR44_SHIFT)                   /*!< INTC0_IMRH: IMR44 Mask                  */
#define INTC_IMRH_IMR44_SHIFT                    12                                                  /*!< INTC0_IMRH: IMR44 Position              */
#define INTC_IMRH_IMR45_MASK                     (0x01UL << INTC_IMRH_IMR45_SHIFT)                   /*!< INTC0_IMRH: IMR45 Mask                  */
#define INTC_IMRH_IMR45_SHIFT                    13                                                  /*!< INTC0_IMRH: IMR45 Position              */
#define INTC_IMRH_IMR46_MASK                     (0x01UL << INTC_IMRH_IMR46_SHIFT)                   /*!< INTC0_IMRH: IMR46 Mask                  */
#define INTC_IMRH_IMR46_SHIFT                    14                                                  /*!< INTC0_IMRH: IMR46 Position              */
#define INTC_IMRH_IMR47_MASK                     (0x01UL << INTC_IMRH_IMR47_SHIFT)                   /*!< INTC0_IMRH: IMR47 Mask                  */
#define INTC_IMRH_IMR47_SHIFT                    15                                                  /*!< INTC0_IMRH: IMR47 Position              */
#define INTC_IMRH_IMR48_MASK                     (0x01UL << INTC_IMRH_IMR48_SHIFT)                   /*!< INTC0_IMRH: IMR48 Mask                  */
#define INTC_IMRH_IMR48_SHIFT                    16                                                  /*!< INTC0_IMRH: IMR48 Position              */
#define INTC_IMRH_IMR49_MASK                     (0x01UL << INTC_IMRH_IMR49_SHIFT)                   /*!< INTC0_IMRH: IMR49 Mask                  */
#define INTC_IMRH_IMR49_SHIFT                    17                                                  /*!< INTC0_IMRH: IMR49 Position              */
#define INTC_IMRH_IMR50_MASK                     (0x01UL << INTC_IMRH_IMR50_SHIFT)                   /*!< INTC0_IMRH: IMR50 Mask                  */
#define INTC_IMRH_IMR50_SHIFT                    18                                                  /*!< INTC0_IMRH: IMR50 Position              */
#define INTC_IMRH_IMR51_MASK                     (0x01UL << INTC_IMRH_IMR51_SHIFT)                   /*!< INTC0_IMRH: IMR51 Mask                  */
#define INTC_IMRH_IMR51_SHIFT                    19                                                  /*!< INTC0_IMRH: IMR51 Position              */
#define INTC_IMRH_IMR52_MASK                     (0x01UL << INTC_IMRH_IMR52_SHIFT)                   /*!< INTC0_IMRH: IMR52 Mask                  */
#define INTC_IMRH_IMR52_SHIFT                    20                                                  /*!< INTC0_IMRH: IMR52 Position              */
#define INTC_IMRH_IMR53_MASK                     (0x01UL << INTC_IMRH_IMR53_SHIFT)                   /*!< INTC0_IMRH: IMR53 Mask                  */
#define INTC_IMRH_IMR53_SHIFT                    21                                                  /*!< INTC0_IMRH: IMR53 Position              */
#define INTC_IMRH_IMR54_MASK                     (0x01UL << INTC_IMRH_IMR54_SHIFT)                   /*!< INTC0_IMRH: IMR54 Mask                  */
#define INTC_IMRH_IMR54_SHIFT                    22                                                  /*!< INTC0_IMRH: IMR54 Position              */
#define INTC_IMRH_IMR55_MASK                     (0x01UL << INTC_IMRH_IMR55_SHIFT)                   /*!< INTC0_IMRH: IMR55 Mask                  */
#define INTC_IMRH_IMR55_SHIFT                    23                                                  /*!< INTC0_IMRH: IMR55 Position              */
#define INTC_IMRH_IMR56_MASK                     (0x01UL << INTC_IMRH_IMR56_SHIFT)                   /*!< INTC0_IMRH: IMR56 Mask                  */
#define INTC_IMRH_IMR56_SHIFT                    24                                                  /*!< INTC0_IMRH: IMR56 Position              */
#define INTC_IMRH_IMR57_MASK                     (0x01UL << INTC_IMRH_IMR57_SHIFT)                   /*!< INTC0_IMRH: IMR57 Mask                  */
#define INTC_IMRH_IMR57_SHIFT                    25                                                  /*!< INTC0_IMRH: IMR57 Position              */
#define INTC_IMRH_IMR58_MASK                     (0x01UL << INTC_IMRH_IMR58_SHIFT)                   /*!< INTC0_IMRH: IMR58 Mask                  */
#define INTC_IMRH_IMR58_SHIFT                    26                                                  /*!< INTC0_IMRH: IMR58 Position              */
#define INTC_IMRH_IMR59_MASK                     (0x01UL << INTC_IMRH_IMR59_SHIFT)                   /*!< INTC0_IMRH: IMR59 Mask                  */
#define INTC_IMRH_IMR59_SHIFT                    27                                                  /*!< INTC0_IMRH: IMR59 Position              */
#define INTC_IMRH_IMR60_MASK                     (0x01UL << INTC_IMRH_IMR60_SHIFT)                   /*!< INTC0_IMRH: IMR60 Mask                  */
#define INTC_IMRH_IMR60_SHIFT                    28                                                  /*!< INTC0_IMRH: IMR60 Position              */
#define INTC_IMRH_IMR61_MASK                     (0x01UL << INTC_IMRH_IMR61_SHIFT)                   /*!< INTC0_IMRH: IMR61 Mask                  */
#define INTC_IMRH_IMR61_SHIFT                    29                                                  /*!< INTC0_IMRH: IMR61 Position              */
#define INTC_IMRH_IMR62_MASK                     (0x01UL << INTC_IMRH_IMR62_SHIFT)                   /*!< INTC0_IMRH: IMR62 Mask                  */
#define INTC_IMRH_IMR62_SHIFT                    30                                                  /*!< INTC0_IMRH: IMR62 Position              */
#define INTC_IMRH_IMR63_MASK                     (0x01UL << INTC_IMRH_IMR63_SHIFT)                   /*!< INTC0_IMRH: IMR63 Mask                  */
#define INTC_IMRH_IMR63_SHIFT                    31                                                  /*!< INTC0_IMRH: IMR63 Position              */
/* ------- IMRL Bit Fields                          ------ */
#define INTC_IMRL_IMR0_MASK                      (0x01UL << INTC_IMRL_IMR0_SHIFT)                    /*!< INTC0_IMRL: IMR0 Mask                   */
#define INTC_IMRL_IMR0_SHIFT                     0                                                   /*!< INTC0_IMRL: IMR0 Position               */
#define INTC_IMRL_IMR1_MASK                      (0x01UL << INTC_IMRL_IMR1_SHIFT)                    /*!< INTC0_IMRL: IMR1 Mask                   */
#define INTC_IMRL_IMR1_SHIFT                     1                                                   /*!< INTC0_IMRL: IMR1 Position               */
#define INTC_IMRL_IMR2_MASK                      (0x01UL << INTC_IMRL_IMR2_SHIFT)                    /*!< INTC0_IMRL: IMR2 Mask                   */
#define INTC_IMRL_IMR2_SHIFT                     2                                                   /*!< INTC0_IMRL: IMR2 Position               */
#define INTC_IMRL_IMR3_MASK                      (0x01UL << INTC_IMRL_IMR3_SHIFT)                    /*!< INTC0_IMRL: IMR3 Mask                   */
#define INTC_IMRL_IMR3_SHIFT                     3                                                   /*!< INTC0_IMRL: IMR3 Position               */
#define INTC_IMRL_IMR4_MASK                      (0x01UL << INTC_IMRL_IMR4_SHIFT)                    /*!< INTC0_IMRL: IMR4 Mask                   */
#define INTC_IMRL_IMR4_SHIFT                     4                                                   /*!< INTC0_IMRL: IMR4 Position               */
#define INTC_IMRL_IMR5_MASK                      (0x01UL << INTC_IMRL_IMR5_SHIFT)                    /*!< INTC0_IMRL: IMR5 Mask                   */
#define INTC_IMRL_IMR5_SHIFT                     5                                                   /*!< INTC0_IMRL: IMR5 Position               */
#define INTC_IMRL_IMR6_MASK                      (0x01UL << INTC_IMRL_IMR6_SHIFT)                    /*!< INTC0_IMRL: IMR6 Mask                   */
#define INTC_IMRL_IMR6_SHIFT                     6                                                   /*!< INTC0_IMRL: IMR6 Position               */
#define INTC_IMRL_IMR7_MASK                      (0x01UL << INTC_IMRL_IMR7_SHIFT)                    /*!< INTC0_IMRL: IMR7 Mask                   */
#define INTC_IMRL_IMR7_SHIFT                     7                                                   /*!< INTC0_IMRL: IMR7 Position               */
#define INTC_IMRL_IMR8_MASK                      (0x01UL << INTC_IMRL_IMR8_SHIFT)                    /*!< INTC0_IMRL: IMR8 Mask                   */
#define INTC_IMRL_IMR8_SHIFT                     8                                                   /*!< INTC0_IMRL: IMR8 Position               */
#define INTC_IMRL_IMR9_MASK                      (0x01UL << INTC_IMRL_IMR9_SHIFT)                    /*!< INTC0_IMRL: IMR9 Mask                   */
#define INTC_IMRL_IMR9_SHIFT                     9                                                   /*!< INTC0_IMRL: IMR9 Position               */
#define INTC_IMRL_IMR10_MASK                     (0x01UL << INTC_IMRL_IMR10_SHIFT)                   /*!< INTC0_IMRL: IMR10 Mask                  */
#define INTC_IMRL_IMR10_SHIFT                    10                                                  /*!< INTC0_IMRL: IMR10 Position              */
#define INTC_IMRL_IMR11_MASK                     (0x01UL << INTC_IMRL_IMR11_SHIFT)                   /*!< INTC0_IMRL: IMR11 Mask                  */
#define INTC_IMRL_IMR11_SHIFT                    11                                                  /*!< INTC0_IMRL: IMR11 Position              */
#define INTC_IMRL_IMR12_MASK                     (0x01UL << INTC_IMRL_IMR12_SHIFT)                   /*!< INTC0_IMRL: IMR12 Mask                  */
#define INTC_IMRL_IMR12_SHIFT                    12                                                  /*!< INTC0_IMRL: IMR12 Position              */
#define INTC_IMRL_IMR13_MASK                     (0x01UL << INTC_IMRL_IMR13_SHIFT)                   /*!< INTC0_IMRL: IMR13 Mask                  */
#define INTC_IMRL_IMR13_SHIFT                    13                                                  /*!< INTC0_IMRL: IMR13 Position              */
#define INTC_IMRL_IMR14_MASK                     (0x01UL << INTC_IMRL_IMR14_SHIFT)                   /*!< INTC0_IMRL: IMR14 Mask                  */
#define INTC_IMRL_IMR14_SHIFT                    14                                                  /*!< INTC0_IMRL: IMR14 Position              */
#define INTC_IMRL_IMR15_MASK                     (0x01UL << INTC_IMRL_IMR15_SHIFT)                   /*!< INTC0_IMRL: IMR15 Mask                  */
#define INTC_IMRL_IMR15_SHIFT                    15                                                  /*!< INTC0_IMRL: IMR15 Position              */
#define INTC_IMRL_IMR16_MASK                     (0x01UL << INTC_IMRL_IMR16_SHIFT)                   /*!< INTC0_IMRL: IMR16 Mask                  */
#define INTC_IMRL_IMR16_SHIFT                    16                                                  /*!< INTC0_IMRL: IMR16 Position              */
#define INTC_IMRL_IMR17_MASK                     (0x01UL << INTC_IMRL_IMR17_SHIFT)                   /*!< INTC0_IMRL: IMR17 Mask                  */
#define INTC_IMRL_IMR17_SHIFT                    17                                                  /*!< INTC0_IMRL: IMR17 Position              */
#define INTC_IMRL_IMR18_MASK                     (0x01UL << INTC_IMRL_IMR18_SHIFT)                   /*!< INTC0_IMRL: IMR18 Mask                  */
#define INTC_IMRL_IMR18_SHIFT                    18                                                  /*!< INTC0_IMRL: IMR18 Position              */
#define INTC_IMRL_IMR19_MASK                     (0x01UL << INTC_IMRL_IMR19_SHIFT)                   /*!< INTC0_IMRL: IMR19 Mask                  */
#define INTC_IMRL_IMR19_SHIFT                    19                                                  /*!< INTC0_IMRL: IMR19 Position              */
#define INTC_IMRL_IMR20_MASK                     (0x01UL << INTC_IMRL_IMR20_SHIFT)                   /*!< INTC0_IMRL: IMR20 Mask                  */
#define INTC_IMRL_IMR20_SHIFT                    20                                                  /*!< INTC0_IMRL: IMR20 Position              */
#define INTC_IMRL_IMR21_MASK                     (0x01UL << INTC_IMRL_IMR21_SHIFT)                   /*!< INTC0_IMRL: IMR21 Mask                  */
#define INTC_IMRL_IMR21_SHIFT                    21                                                  /*!< INTC0_IMRL: IMR21 Position              */
#define INTC_IMRL_IMR22_MASK                     (0x01UL << INTC_IMRL_IMR22_SHIFT)                   /*!< INTC0_IMRL: IMR22 Mask                  */
#define INTC_IMRL_IMR22_SHIFT                    22                                                  /*!< INTC0_IMRL: IMR22 Position              */
#define INTC_IMRL_IMR23_MASK                     (0x01UL << INTC_IMRL_IMR23_SHIFT)                   /*!< INTC0_IMRL: IMR23 Mask                  */
#define INTC_IMRL_IMR23_SHIFT                    23                                                  /*!< INTC0_IMRL: IMR23 Position              */
#define INTC_IMRL_IMR24_MASK                     (0x01UL << INTC_IMRL_IMR24_SHIFT)                   /*!< INTC0_IMRL: IMR24 Mask                  */
#define INTC_IMRL_IMR24_SHIFT                    24                                                  /*!< INTC0_IMRL: IMR24 Position              */
#define INTC_IMRL_IMR25_MASK                     (0x01UL << INTC_IMRL_IMR25_SHIFT)                   /*!< INTC0_IMRL: IMR25 Mask                  */
#define INTC_IMRL_IMR25_SHIFT                    25                                                  /*!< INTC0_IMRL: IMR25 Position              */
#define INTC_IMRL_IMR26_MASK                     (0x01UL << INTC_IMRL_IMR26_SHIFT)                   /*!< INTC0_IMRL: IMR26 Mask                  */
#define INTC_IMRL_IMR26_SHIFT                    26                                                  /*!< INTC0_IMRL: IMR26 Position              */
#define INTC_IMRL_IMR27_MASK                     (0x01UL << INTC_IMRL_IMR27_SHIFT)                   /*!< INTC0_IMRL: IMR27 Mask                  */
#define INTC_IMRL_IMR27_SHIFT                    27                                                  /*!< INTC0_IMRL: IMR27 Position              */
#define INTC_IMRL_IMR28_MASK                     (0x01UL << INTC_IMRL_IMR28_SHIFT)                   /*!< INTC0_IMRL: IMR28 Mask                  */
#define INTC_IMRL_IMR28_SHIFT                    28                                                  /*!< INTC0_IMRL: IMR28 Position              */
#define INTC_IMRL_IMR29_MASK                     (0x01UL << INTC_IMRL_IMR29_SHIFT)                   /*!< INTC0_IMRL: IMR29 Mask                  */
#define INTC_IMRL_IMR29_SHIFT                    29                                                  /*!< INTC0_IMRL: IMR29 Position              */
#define INTC_IMRL_IMR30_MASK                     (0x01UL << INTC_IMRL_IMR30_SHIFT)                   /*!< INTC0_IMRL: IMR30 Mask                  */
#define INTC_IMRL_IMR30_SHIFT                    30                                                  /*!< INTC0_IMRL: IMR30 Position              */
#define INTC_IMRL_IMR31_MASK                     (0x01UL << INTC_IMRL_IMR31_SHIFT)                   /*!< INTC0_IMRL: IMR31 Mask                  */
#define INTC_IMRL_IMR31_SHIFT                    31                                                  /*!< INTC0_IMRL: IMR31 Position              */
/* ------- FRC Bit Fields                           ------ */
#define INTC_FRC_LVL7_MASK                       (0x01UL << INTC_FRC_LVL7_SHIFT)                     /*!< INTC0_FRC: LVL7 Mask                    */
#define INTC_FRC_LVL7_SHIFT                      0                                                   /*!< INTC0_FRC: LVL7 Position                */
#define INTC_FRC_LVL6_MASK                       (0x01UL << INTC_FRC_LVL6_SHIFT)                     /*!< INTC0_FRC: LVL6 Mask                    */
#define INTC_FRC_LVL6_SHIFT                      1                                                   /*!< INTC0_FRC: LVL6 Position                */
#define INTC_FRC_LVL5_MASK                       (0x01UL << INTC_FRC_LVL5_SHIFT)                     /*!< INTC0_FRC: LVL5 Mask                    */
#define INTC_FRC_LVL5_SHIFT                      2                                                   /*!< INTC0_FRC: LVL5 Position                */
#define INTC_FRC_LVL4_MASK                       (0x01UL << INTC_FRC_LVL4_SHIFT)                     /*!< INTC0_FRC: LVL4 Mask                    */
#define INTC_FRC_LVL4_SHIFT                      3                                                   /*!< INTC0_FRC: LVL4 Position                */
#define INTC_FRC_LVL3_MASK                       (0x01UL << INTC_FRC_LVL3_SHIFT)                     /*!< INTC0_FRC: LVL3 Mask                    */
#define INTC_FRC_LVL3_SHIFT                      4                                                   /*!< INTC0_FRC: LVL3 Position                */
#define INTC_FRC_LVL2_MASK                       (0x01UL << INTC_FRC_LVL2_SHIFT)                     /*!< INTC0_FRC: LVL2 Mask                    */
#define INTC_FRC_LVL2_SHIFT                      5                                                   /*!< INTC0_FRC: LVL2 Position                */
#define INTC_FRC_LVL1_MASK                       (0x01UL << INTC_FRC_LVL1_SHIFT)                     /*!< INTC0_FRC: LVL1 Mask                    */
#define INTC_FRC_LVL1_SHIFT                      6                                                   /*!< INTC0_FRC: LVL1 Position                */
/* ------- PL6P Bit Fields                          ------ */
#define INTC_PL6P_REQN_MASK                      (0x3FUL << INTC_PL6P_REQN_SHIFT)                    /*!< INTC0_PL6P: REQN Mask                   */
#define INTC_PL6P_REQN_SHIFT                     0                                                   /*!< INTC0_PL6P: REQN Position               */
#define INTC_PL6P_REQN(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_PL6P_REQN_SHIFT))&INTC_PL6P_REQN_MASK) /*!< INTC0_PL6P                              */
/* ------- WCR Bit Fields                           ------ */
#define INTC_WCR_MASK_MASK                       (0x07UL << INTC_WCR_MASK_SHIFT)                     /*!< INTC0_WCR: MASK Mask                    */
#define INTC_WCR_MASK_SHIFT                      0                                                   /*!< INTC0_WCR: MASK Position                */
#define INTC_WCR_MASK(x)                         (((uint8_t)(((uint8_t)(x))<<INTC_WCR_MASK_SHIFT))&INTC_WCR_MASK_MASK) /*!< INTC0_WCR                               */
#define INTC_WCR_ENB_MASK                        (0x01UL << INTC_WCR_ENB_SHIFT)                      /*!< INTC0_WCR: ENB Mask                     */
#define INTC_WCR_ENB_SHIFT                       7                                                   /*!< INTC0_WCR: ENB Position                 */
/* ------- SIMR Bit Fields                          ------ */
#define INTC_SIMR_SIMR_MASK                      (0x3FUL << INTC_SIMR_SIMR_SHIFT)                    /*!< INTC0_SIMR: SIMR Mask                   */
#define INTC_SIMR_SIMR_SHIFT                     0                                                   /*!< INTC0_SIMR: SIMR Position               */
#define INTC_SIMR_SIMR(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_SIMR_SIMR_SHIFT))&INTC_SIMR_SIMR_MASK) /*!< INTC0_SIMR                              */
#define INTC_SIMR_SALL_MASK                      (0x01UL << INTC_SIMR_SALL_SHIFT)                    /*!< INTC0_SIMR: SALL Mask                   */
#define INTC_SIMR_SALL_SHIFT                     6                                                   /*!< INTC0_SIMR: SALL Position               */
/* ------- CIMR Bit Fields                          ------ */
#define INTC_CIMR_CIMR_MASK                      (0x3FUL << INTC_CIMR_CIMR_SHIFT)                    /*!< INTC0_CIMR: CIMR Mask                   */
#define INTC_CIMR_CIMR_SHIFT                     0                                                   /*!< INTC0_CIMR: CIMR Position               */
#define INTC_CIMR_CIMR(x)                        (((uint8_t)(((uint8_t)(x))<<INTC_CIMR_CIMR_SHIFT))&INTC_CIMR_CIMR_MASK) /*!< INTC0_CIMR                              */
#define INTC_CIMR_CALL_MASK                      (0x01UL << INTC_CIMR_CALL_SHIFT)                    /*!< INTC0_CIMR: CALL Mask                   */
#define INTC_CIMR_CALL_SHIFT                     6                                                   /*!< INTC0_CIMR: CALL Position               */
/* ------- SFRC Bit Fields                          ------ */
#define INTC_SFRC_SET_MASK                       (0x3FUL << INTC_SFRC_SET_SHIFT)                     /*!< INTC0_SFRC: SET Mask                    */
#define INTC_SFRC_SET_SHIFT                      0                                                   /*!< INTC0_SFRC: SET Position                */
#define INTC_SFRC_SET(x)                         (((uint8_t)(((uint8_t)(x))<<INTC_SFRC_SET_SHIFT))&INTC_SFRC_SET_MASK) /*!< INTC0_SFRC                              */
/* ------- CFRC Bit Fields                          ------ */
#define INTC_CFRC_CLR_MASK                       (0x3FUL << INTC_CFRC_CLR_SHIFT)                     /*!< INTC0_CFRC: CLR Mask                    */
#define INTC_CFRC_CLR_SHIFT                      0                                                   /*!< INTC0_CFRC: CLR Position                */
#define INTC_CFRC_CLR(x)                         (((uint8_t)(((uint8_t)(x))<<INTC_CFRC_CLR_SHIFT))&INTC_CFRC_CLR_MASK) /*!< INTC0_CFRC                              */
/* ------- SWIACK Bit Fields                        ------ */
/* ------- LVLIACK Bit Fields                       ------ */
/**
 * @} */ /* End group INTC_Register_Masks_GROUP 
 */

/* INTC0 - Peripheral instance base addresses */
#define INTC0_BasePtr                  0xFFFFFFC0UL //!< Peripheral base address
#define INTC0                          ((INTC_Type *) INTC0_BasePtr) //!< Freescale base pointer
#define INTC0_BASE_PTR                 (INTC0) //!< Freescale style base pointer
/**
 * @} */ /* End group INTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup IRQ_Peripheral_access_layer_GROUP IRQ Peripheral Access Layer
* @brief C Struct for IRQ
* @{
*/

/* ================================================================================ */
/* ================           IRQ (file:IRQ_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief External Interrupt
 */
/**
* @addtogroup IRQ_structs_GROUP IRQ struct
* @brief Struct for IRQ
* @{
*/
typedef struct {                                /*       IRQ Structure                                                */
   __IO uint8_t   SC;                           /**< 0000: Interrupt status and control register                        */
} IRQ_Type;

/**
 * @} */ /* End group IRQ_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'IRQ' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup IRQ_Register_Masks_GROUP IRQ Register Masks
* @brief Register Masks for IRQ
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define IRQ_SC_IRQMOD_MASK                       (0x01UL << IRQ_SC_IRQMOD_SHIFT)                     /*!< IRQ_SC: IRQMOD Mask                     */
#define IRQ_SC_IRQMOD_SHIFT                      0                                                   /*!< IRQ_SC: IRQMOD Position                 */
#define IRQ_SC_IRQIE_MASK                        (0x01UL << IRQ_SC_IRQIE_SHIFT)                      /*!< IRQ_SC: IRQIE Mask                      */
#define IRQ_SC_IRQIE_SHIFT                       1                                                   /*!< IRQ_SC: IRQIE Position                  */
#define IRQ_SC_IRQACK_MASK                       (0x01UL << IRQ_SC_IRQACK_SHIFT)                     /*!< IRQ_SC: IRQACK Mask                     */
#define IRQ_SC_IRQACK_SHIFT                      2                                                   /*!< IRQ_SC: IRQACK Position                 */
#define IRQ_SC_IRQF_MASK                         (0x01UL << IRQ_SC_IRQF_SHIFT)                       /*!< IRQ_SC: IRQF Mask                       */
#define IRQ_SC_IRQF_SHIFT                        3                                                   /*!< IRQ_SC: IRQF Position                   */
#define IRQ_SC_IRQPE_MASK                        (0x01UL << IRQ_SC_IRQPE_SHIFT)                      /*!< IRQ_SC: IRQPE Mask                      */
#define IRQ_SC_IRQPE_SHIFT                       4                                                   /*!< IRQ_SC: IRQPE Position                  */
#define IRQ_SC_IRQEDG_MASK                       (0x01UL << IRQ_SC_IRQEDG_SHIFT)                     /*!< IRQ_SC: IRQEDG Mask                     */
#define IRQ_SC_IRQEDG_SHIFT                      5                                                   /*!< IRQ_SC: IRQEDG Position                 */
#define IRQ_SC_IRQPDD_MASK                       (0x01UL << IRQ_SC_IRQPDD_SHIFT)                     /*!< IRQ_SC: IRQPDD Mask                     */
#define IRQ_SC_IRQPDD_SHIFT                      6                                                   /*!< IRQ_SC: IRQPDD Position                 */
/**
 * @} */ /* End group IRQ_Register_Masks_GROUP 
 */

/* IRQ - Peripheral instance base addresses */
#define IRQ_BasePtr                    0xFFFF80A0UL //!< Peripheral base address
#define IRQ                            ((IRQ_Type *) IRQ_BasePtr) //!< Freescale base pointer
#define IRQ_BASE_PTR                   (IRQ) //!< Freescale style base pointer
/**
 * @} */ /* End group IRQ_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LLWU_Peripheral_access_layer_GROUP LLWU Peripheral Access Layer
* @brief C Struct for LLWU
* @{
*/

/* ================================================================================ */
/* ================           LLWU (file:LLWU_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief Low leakage wakeup unit
 */
/**
* @addtogroup LLWU_structs_GROUP LLWU struct
* @brief Struct for LLWU
* @{
*/
typedef struct {                                /*       LLWU Structure                                               */
   __IO uint8_t   PE1;                          /**< 0000: Pin Enable 1 Register                                        */
   __IO uint8_t   PE2;                          /**< 0001: Pin Enable 2 Register                                        */
   __IO uint8_t   PE3;                          /**< 0002: Pin Enable 3 Register                                        */
   __IO uint8_t   PE4;                          /**< 0003: Pin Enable 4 Register                                        */
   __IO uint8_t   ME;                           /**< 0004: Module Enable Register                                       */
   __IO uint8_t   F1;                           /**< 0005: Flag 1 Register                                              */
   __IO uint8_t   F2;                           /**< 0006: Flag 2 Register                                              */
   __IO uint8_t   F3;                           /**< 0007: Flag 3 Register                                              */
   __IO uint8_t   FILT1;                        /**< 0008: Pin Filter 1 register                                        */
   __IO uint8_t   FILT2;                        /**< 0009: Pin Filter 2 register                                        */
   __IO uint8_t   RST;                          /**< 000A: Reset Enable Register                                        */
} LLWU_Type;

/**
 * @} */ /* End group LLWU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LLWU' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LLWU_Register_Masks_GROUP LLWU Register Masks
* @brief Register Masks for LLWU
* @{
*/
/* ------- PE1 Bit Fields                           ------ */
#define LLWU_PE1_WUPE0_MASK                      (0x03UL << LLWU_PE1_WUPE0_SHIFT)                    /*!< LLWU_PE1: WUPE0 Mask                    */
#define LLWU_PE1_WUPE0_SHIFT                     0                                                   /*!< LLWU_PE1: WUPE0 Position                */
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE1_MASK                      (0x03UL << LLWU_PE1_WUPE1_SHIFT)                    /*!< LLWU_PE1: WUPE1 Mask                    */
#define LLWU_PE1_WUPE1_SHIFT                     2                                                   /*!< LLWU_PE1: WUPE1 Position                */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE2_MASK                      (0x03UL << LLWU_PE1_WUPE2_SHIFT)                    /*!< LLWU_PE1: WUPE2 Mask                    */
#define LLWU_PE1_WUPE2_SHIFT                     4                                                   /*!< LLWU_PE1: WUPE2 Position                */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE3_MASK                      (0x03UL << LLWU_PE1_WUPE3_SHIFT)                    /*!< LLWU_PE1: WUPE3 Mask                    */
#define LLWU_PE1_WUPE3_SHIFT                     6                                                   /*!< LLWU_PE1: WUPE3 Position                */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK) /*!< LLWU_PE1                                */
/* ------- PE2 Bit Fields                           ------ */
#define LLWU_PE2_WUPE4_MASK                      (0x03UL << LLWU_PE2_WUPE4_SHIFT)                    /*!< LLWU_PE2: WUPE4 Mask                    */
#define LLWU_PE2_WUPE4_SHIFT                     0                                                   /*!< LLWU_PE2: WUPE4 Position                */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE5_MASK                      (0x03UL << LLWU_PE2_WUPE5_SHIFT)                    /*!< LLWU_PE2: WUPE5 Mask                    */
#define LLWU_PE2_WUPE5_SHIFT                     2                                                   /*!< LLWU_PE2: WUPE5 Position                */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE6_MASK                      (0x03UL << LLWU_PE2_WUPE6_SHIFT)                    /*!< LLWU_PE2: WUPE6 Mask                    */
#define LLWU_PE2_WUPE6_SHIFT                     4                                                   /*!< LLWU_PE2: WUPE6 Position                */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE7_MASK                      (0x03UL << LLWU_PE2_WUPE7_SHIFT)                    /*!< LLWU_PE2: WUPE7 Mask                    */
#define LLWU_PE2_WUPE7_SHIFT                     6                                                   /*!< LLWU_PE2: WUPE7 Position                */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK) /*!< LLWU_PE2                                */
/* ------- PE3 Bit Fields                           ------ */
#define LLWU_PE3_WUPE8_MASK                      (0x03UL << LLWU_PE3_WUPE8_SHIFT)                    /*!< LLWU_PE3: WUPE8 Mask                    */
#define LLWU_PE3_WUPE8_SHIFT                     0                                                   /*!< LLWU_PE3: WUPE8 Position                */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE9_MASK                      (0x03UL << LLWU_PE3_WUPE9_SHIFT)                    /*!< LLWU_PE3: WUPE9 Mask                    */
#define LLWU_PE3_WUPE9_SHIFT                     2                                                   /*!< LLWU_PE3: WUPE9 Position                */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE10_MASK                     (0x03UL << LLWU_PE3_WUPE10_SHIFT)                   /*!< LLWU_PE3: WUPE10 Mask                   */
#define LLWU_PE3_WUPE10_SHIFT                    4                                                   /*!< LLWU_PE3: WUPE10 Position               */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE11_MASK                     (0x03UL << LLWU_PE3_WUPE11_SHIFT)                   /*!< LLWU_PE3: WUPE11 Mask                   */
#define LLWU_PE3_WUPE11_SHIFT                    6                                                   /*!< LLWU_PE3: WUPE11 Position               */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK) /*!< LLWU_PE3                                */
/* ------- PE4 Bit Fields                           ------ */
#define LLWU_PE4_WUPE12_MASK                     (0x03UL << LLWU_PE4_WUPE12_SHIFT)                   /*!< LLWU_PE4: WUPE12 Mask                   */
#define LLWU_PE4_WUPE12_SHIFT                    0                                                   /*!< LLWU_PE4: WUPE12 Position               */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE13_MASK                     (0x03UL << LLWU_PE4_WUPE13_SHIFT)                   /*!< LLWU_PE4: WUPE13 Mask                   */
#define LLWU_PE4_WUPE13_SHIFT                    2                                                   /*!< LLWU_PE4: WUPE13 Position               */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE14_MASK                     (0x03UL << LLWU_PE4_WUPE14_SHIFT)                   /*!< LLWU_PE4: WUPE14 Mask                   */
#define LLWU_PE4_WUPE14_SHIFT                    4                                                   /*!< LLWU_PE4: WUPE14 Position               */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE15_MASK                     (0x03UL << LLWU_PE4_WUPE15_SHIFT)                   /*!< LLWU_PE4: WUPE15 Mask                   */
#define LLWU_PE4_WUPE15_SHIFT                    6                                                   /*!< LLWU_PE4: WUPE15 Position               */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK) /*!< LLWU_PE4                                */
/* ------- ME Bit Fields                            ------ */
#define LLWU_ME_WUME0_MASK                       (0x01UL << LLWU_ME_WUME0_SHIFT)                     /*!< LLWU_ME: WUME0 Mask                     */
#define LLWU_ME_WUME0_SHIFT                      0                                                   /*!< LLWU_ME: WUME0 Position                 */
#define LLWU_ME_WUME1_MASK                       (0x01UL << LLWU_ME_WUME1_SHIFT)                     /*!< LLWU_ME: WUME1 Mask                     */
#define LLWU_ME_WUME1_SHIFT                      1                                                   /*!< LLWU_ME: WUME1 Position                 */
#define LLWU_ME_WUME2_MASK                       (0x01UL << LLWU_ME_WUME2_SHIFT)                     /*!< LLWU_ME: WUME2 Mask                     */
#define LLWU_ME_WUME2_SHIFT                      2                                                   /*!< LLWU_ME: WUME2 Position                 */
#define LLWU_ME_WUME3_MASK                       (0x01UL << LLWU_ME_WUME3_SHIFT)                     /*!< LLWU_ME: WUME3 Mask                     */
#define LLWU_ME_WUME3_SHIFT                      3                                                   /*!< LLWU_ME: WUME3 Position                 */
#define LLWU_ME_WUME4_MASK                       (0x01UL << LLWU_ME_WUME4_SHIFT)                     /*!< LLWU_ME: WUME4 Mask                     */
#define LLWU_ME_WUME4_SHIFT                      4                                                   /*!< LLWU_ME: WUME4 Position                 */
#define LLWU_ME_WUME5_MASK                       (0x01UL << LLWU_ME_WUME5_SHIFT)                     /*!< LLWU_ME: WUME5 Mask                     */
#define LLWU_ME_WUME5_SHIFT                      5                                                   /*!< LLWU_ME: WUME5 Position                 */
#define LLWU_ME_WUME6_MASK                       (0x01UL << LLWU_ME_WUME6_SHIFT)                     /*!< LLWU_ME: WUME6 Mask                     */
#define LLWU_ME_WUME6_SHIFT                      6                                                   /*!< LLWU_ME: WUME6 Position                 */
#define LLWU_ME_WUME7_MASK                       (0x01UL << LLWU_ME_WUME7_SHIFT)                     /*!< LLWU_ME: WUME7 Mask                     */
#define LLWU_ME_WUME7_SHIFT                      7                                                   /*!< LLWU_ME: WUME7 Position                 */
/* ------- F1 Bit Fields                            ------ */
#define LLWU_F1_WUF0_MASK                        (0x01UL << LLWU_F1_WUF0_SHIFT)                      /*!< LLWU_F1: WUF0 Mask                      */
#define LLWU_F1_WUF0_SHIFT                       0                                                   /*!< LLWU_F1: WUF0 Position                  */
#define LLWU_F1_WUF1_MASK                        (0x01UL << LLWU_F1_WUF1_SHIFT)                      /*!< LLWU_F1: WUF1 Mask                      */
#define LLWU_F1_WUF1_SHIFT                       1                                                   /*!< LLWU_F1: WUF1 Position                  */
#define LLWU_F1_WUF2_MASK                        (0x01UL << LLWU_F1_WUF2_SHIFT)                      /*!< LLWU_F1: WUF2 Mask                      */
#define LLWU_F1_WUF2_SHIFT                       2                                                   /*!< LLWU_F1: WUF2 Position                  */
#define LLWU_F1_WUF3_MASK                        (0x01UL << LLWU_F1_WUF3_SHIFT)                      /*!< LLWU_F1: WUF3 Mask                      */
#define LLWU_F1_WUF3_SHIFT                       3                                                   /*!< LLWU_F1: WUF3 Position                  */
#define LLWU_F1_WUF4_MASK                        (0x01UL << LLWU_F1_WUF4_SHIFT)                      /*!< LLWU_F1: WUF4 Mask                      */
#define LLWU_F1_WUF4_SHIFT                       4                                                   /*!< LLWU_F1: WUF4 Position                  */
#define LLWU_F1_WUF5_MASK                        (0x01UL << LLWU_F1_WUF5_SHIFT)                      /*!< LLWU_F1: WUF5 Mask                      */
#define LLWU_F1_WUF5_SHIFT                       5                                                   /*!< LLWU_F1: WUF5 Position                  */
#define LLWU_F1_WUF6_MASK                        (0x01UL << LLWU_F1_WUF6_SHIFT)                      /*!< LLWU_F1: WUF6 Mask                      */
#define LLWU_F1_WUF6_SHIFT                       6                                                   /*!< LLWU_F1: WUF6 Position                  */
#define LLWU_F1_WUF7_MASK                        (0x01UL << LLWU_F1_WUF7_SHIFT)                      /*!< LLWU_F1: WUF7 Mask                      */
#define LLWU_F1_WUF7_SHIFT                       7                                                   /*!< LLWU_F1: WUF7 Position                  */
/* ------- F2 Bit Fields                            ------ */
#define LLWU_F2_WUF8_MASK                        (0x01UL << LLWU_F2_WUF8_SHIFT)                      /*!< LLWU_F2: WUF8 Mask                      */
#define LLWU_F2_WUF8_SHIFT                       0                                                   /*!< LLWU_F2: WUF8 Position                  */
#define LLWU_F2_WUF9_MASK                        (0x01UL << LLWU_F2_WUF9_SHIFT)                      /*!< LLWU_F2: WUF9 Mask                      */
#define LLWU_F2_WUF9_SHIFT                       1                                                   /*!< LLWU_F2: WUF9 Position                  */
#define LLWU_F2_WUF10_MASK                       (0x01UL << LLWU_F2_WUF10_SHIFT)                     /*!< LLWU_F2: WUF10 Mask                     */
#define LLWU_F2_WUF10_SHIFT                      2                                                   /*!< LLWU_F2: WUF10 Position                 */
#define LLWU_F2_WUF11_MASK                       (0x01UL << LLWU_F2_WUF11_SHIFT)                     /*!< LLWU_F2: WUF11 Mask                     */
#define LLWU_F2_WUF11_SHIFT                      3                                                   /*!< LLWU_F2: WUF11 Position                 */
#define LLWU_F2_WUF12_MASK                       (0x01UL << LLWU_F2_WUF12_SHIFT)                     /*!< LLWU_F2: WUF12 Mask                     */
#define LLWU_F2_WUF12_SHIFT                      4                                                   /*!< LLWU_F2: WUF12 Position                 */
#define LLWU_F2_WUF13_MASK                       (0x01UL << LLWU_F2_WUF13_SHIFT)                     /*!< LLWU_F2: WUF13 Mask                     */
#define LLWU_F2_WUF13_SHIFT                      5                                                   /*!< LLWU_F2: WUF13 Position                 */
#define LLWU_F2_WUF14_MASK                       (0x01UL << LLWU_F2_WUF14_SHIFT)                     /*!< LLWU_F2: WUF14 Mask                     */
#define LLWU_F2_WUF14_SHIFT                      6                                                   /*!< LLWU_F2: WUF14 Position                 */
#define LLWU_F2_WUF15_MASK                       (0x01UL << LLWU_F2_WUF15_SHIFT)                     /*!< LLWU_F2: WUF15 Mask                     */
#define LLWU_F2_WUF15_SHIFT                      7                                                   /*!< LLWU_F2: WUF15 Position                 */
/* ------- F3 Bit Fields                            ------ */
#define LLWU_F3_MWUF0_MASK                       (0x01UL << LLWU_F3_MWUF0_SHIFT)                     /*!< LLWU_F3: MWUF0 Mask                     */
#define LLWU_F3_MWUF0_SHIFT                      0                                                   /*!< LLWU_F3: MWUF0 Position                 */
#define LLWU_F3_MWUF1_MASK                       (0x01UL << LLWU_F3_MWUF1_SHIFT)                     /*!< LLWU_F3: MWUF1 Mask                     */
#define LLWU_F3_MWUF1_SHIFT                      1                                                   /*!< LLWU_F3: MWUF1 Position                 */
#define LLWU_F3_MWUF2_MASK                       (0x01UL << LLWU_F3_MWUF2_SHIFT)                     /*!< LLWU_F3: MWUF2 Mask                     */
#define LLWU_F3_MWUF2_SHIFT                      2                                                   /*!< LLWU_F3: MWUF2 Position                 */
#define LLWU_F3_MWUF3_MASK                       (0x01UL << LLWU_F3_MWUF3_SHIFT)                     /*!< LLWU_F3: MWUF3 Mask                     */
#define LLWU_F3_MWUF3_SHIFT                      3                                                   /*!< LLWU_F3: MWUF3 Position                 */
#define LLWU_F3_MWUF4_MASK                       (0x01UL << LLWU_F3_MWUF4_SHIFT)                     /*!< LLWU_F3: MWUF4 Mask                     */
#define LLWU_F3_MWUF4_SHIFT                      4                                                   /*!< LLWU_F3: MWUF4 Position                 */
#define LLWU_F3_MWUF5_MASK                       (0x01UL << LLWU_F3_MWUF5_SHIFT)                     /*!< LLWU_F3: MWUF5 Mask                     */
#define LLWU_F3_MWUF5_SHIFT                      5                                                   /*!< LLWU_F3: MWUF5 Position                 */
#define LLWU_F3_MWUF6_MASK                       (0x01UL << LLWU_F3_MWUF6_SHIFT)                     /*!< LLWU_F3: MWUF6 Mask                     */
#define LLWU_F3_MWUF6_SHIFT                      6                                                   /*!< LLWU_F3: MWUF6 Position                 */
#define LLWU_F3_MWUF7_MASK                       (0x01UL << LLWU_F3_MWUF7_SHIFT)                     /*!< LLWU_F3: MWUF7 Mask                     */
#define LLWU_F3_MWUF7_SHIFT                      7                                                   /*!< LLWU_F3: MWUF7 Position                 */
/* ------- FILT Bit Fields                          ------ */
#define LLWU_FILT_FILTSEL_MASK                   (0x0FUL << LLWU_FILT_FILTSEL_SHIFT)                 /*!< LLWU_FILT: FILTSEL Mask                 */
#define LLWU_FILT_FILTSEL_SHIFT                  0                                                   /*!< LLWU_FILT: FILTSEL Position             */
#define LLWU_FILT_FILTSEL(x)                     (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTSEL_SHIFT))&LLWU_FILT_FILTSEL_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTE_MASK                     (0x03UL << LLWU_FILT_FILTE_SHIFT)                   /*!< LLWU_FILT: FILTE Mask                   */
#define LLWU_FILT_FILTE_SHIFT                    5                                                   /*!< LLWU_FILT: FILTE Position               */
#define LLWU_FILT_FILTE(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTE_SHIFT))&LLWU_FILT_FILTE_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTF_MASK                     (0x01UL << LLWU_FILT_FILTF_SHIFT)                   /*!< LLWU_FILT: FILTF Mask                   */
#define LLWU_FILT_FILTF_SHIFT                    7                                                   /*!< LLWU_FILT: FILTF Position               */
/* ------- RST Bit Fields                           ------ */
#define LLWU_RST_RSTFILT_MASK                    (0x01UL << LLWU_RST_RSTFILT_SHIFT)                  /*!< LLWU_RST: RSTFILT Mask                  */
#define LLWU_RST_RSTFILT_SHIFT                   0                                                   /*!< LLWU_RST: RSTFILT Position              */
#define LLWU_RST_LLRSTE_MASK                     (0x01UL << LLWU_RST_LLRSTE_SHIFT)                   /*!< LLWU_RST: LLRSTE Mask                   */
#define LLWU_RST_LLRSTE_SHIFT                    1                                                   /*!< LLWU_RST: LLRSTE Position               */
/**
 * @} */ /* End group LLWU_Register_Masks_GROUP 
 */

/* LLWU - Peripheral instance base addresses */
#define LLWU_BasePtr                   0xFFFF80B0UL //!< Peripheral base address
#define LLWU                           ((LLWU_Type *) LLWU_BasePtr) //!< Freescale base pointer
#define LLWU_BASE_PTR                  (LLWU) //!< Freescale style base pointer
/**
 * @} */ /* End group LLWU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPTMR_Peripheral_access_layer_GROUP LPTMR Peripheral Access Layer
* @brief C Struct for LPTMR
* @{
*/

/* ================================================================================ */
/* ================           LPTMR0 (file:LPTMR0_MCF51)           ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */
/**
* @addtogroup LPTMR_structs_GROUP LPTMR struct
* @brief Struct for LPTMR
* @{
*/
typedef struct {                                /*       LPTMR0 Structure                                             */
   __IO uint32_t  CSR;                          /**< 0000: Control Status Register                                      */
   __IO uint32_t  PSR;                          /**< 0004: Prescale Register                                            */
   __IO uint32_t  CMR;                          /**< 0008: Compare Register                                             */
   __I  uint32_t  CNR;                          /**< 000C: Counter Register                                             */
} LPTMR_Type;

/**
 * @} */ /* End group LPTMR_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPTMR0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LPTMR_Register_Masks_GROUP LPTMR Register Masks
* @brief Register Masks for LPTMR
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define LPTMR_CSR_TEN_MASK                       (0x01UL << LPTMR_CSR_TEN_SHIFT)                     /*!< LPTMR0_CSR: TEN Mask                    */
#define LPTMR_CSR_TEN_SHIFT                      0                                                   /*!< LPTMR0_CSR: TEN Position                */
#define LPTMR_CSR_TMS_MASK                       (0x01UL << LPTMR_CSR_TMS_SHIFT)                     /*!< LPTMR0_CSR: TMS Mask                    */
#define LPTMR_CSR_TMS_SHIFT                      1                                                   /*!< LPTMR0_CSR: TMS Position                */
#define LPTMR_CSR_TFC_MASK                       (0x01UL << LPTMR_CSR_TFC_SHIFT)                     /*!< LPTMR0_CSR: TFC Mask                    */
#define LPTMR_CSR_TFC_SHIFT                      2                                                   /*!< LPTMR0_CSR: TFC Position                */
#define LPTMR_CSR_TPP_MASK                       (0x01UL << LPTMR_CSR_TPP_SHIFT)                     /*!< LPTMR0_CSR: TPP Mask                    */
#define LPTMR_CSR_TPP_SHIFT                      3                                                   /*!< LPTMR0_CSR: TPP Position                */
#define LPTMR_CSR_TPS_MASK                       (0x03UL << LPTMR_CSR_TPS_SHIFT)                     /*!< LPTMR0_CSR: TPS Mask                    */
#define LPTMR_CSR_TPS_SHIFT                      4                                                   /*!< LPTMR0_CSR: TPS Position                */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TIE_MASK                       (0x01UL << LPTMR_CSR_TIE_SHIFT)                     /*!< LPTMR0_CSR: TIE Mask                    */
#define LPTMR_CSR_TIE_SHIFT                      6                                                   /*!< LPTMR0_CSR: TIE Position                */
#define LPTMR_CSR_TCF_MASK                       (0x01UL << LPTMR_CSR_TCF_SHIFT)                     /*!< LPTMR0_CSR: TCF Mask                    */
#define LPTMR_CSR_TCF_SHIFT                      7                                                   /*!< LPTMR0_CSR: TCF Position                */
/* ------- PSR Bit Fields                           ------ */
#define LPTMR_PSR_PCS_MASK                       (0x03UL << LPTMR_PSR_PCS_SHIFT)                     /*!< LPTMR0_PSR: PCS Mask                    */
#define LPTMR_PSR_PCS_SHIFT                      0                                                   /*!< LPTMR0_PSR: PCS Position                */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK) /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PBYP_MASK                      (0x01UL << LPTMR_PSR_PBYP_SHIFT)                    /*!< LPTMR0_PSR: PBYP Mask                   */
#define LPTMR_PSR_PBYP_SHIFT                     2                                                   /*!< LPTMR0_PSR: PBYP Position               */
#define LPTMR_PSR_PRESCALE_MASK                  (0x0FUL << LPTMR_PSR_PRESCALE_SHIFT)                /*!< LPTMR0_PSR: PRESCALE Mask               */
#define LPTMR_PSR_PRESCALE_SHIFT                 3                                                   /*!< LPTMR0_PSR: PRESCALE Position           */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK) /*!< LPTMR0_PSR                              */
/* ------- CMR Bit Fields                           ------ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFUL << LPTMR_CMR_COMPARE_SHIFT)               /*!< LPTMR0_CMR: COMPARE Mask                */
#define LPTMR_CMR_COMPARE_SHIFT                  0                                                   /*!< LPTMR0_CMR: COMPARE Position            */
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK) /*!< LPTMR0_CMR                              */
/* ------- CNR Bit Fields                           ------ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFUL << LPTMR_CNR_COUNTER_SHIFT)               /*!< LPTMR0_CNR: COUNTER Mask                */
#define LPTMR_CNR_COUNTER_SHIFT                  0                                                   /*!< LPTMR0_CNR: COUNTER Position            */
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK) /*!< LPTMR0_CNR                              */
/**
 * @} */ /* End group LPTMR_Register_Masks_GROUP 
 */

/* LPTMR0 - Peripheral instance base addresses */
#define LPTMR0_BasePtr                 0xFFFF84C0UL //!< Peripheral base address
#define LPTMR0                         ((LPTMR_Type *) LPTMR0_BasePtr) //!< Freescale base pointer
#define LPTMR0_BASE_PTR                (LPTMR0) //!< Freescale style base pointer
/**
 * @} */ /* End group LPTMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPTMR_Peripheral_access_layer_GROUP LPTMR Peripheral Access Layer
* @brief C Struct for LPTMR
* @{
*/

/* ================================================================================ */
/* ================           LPTMR1 (derived from LPTMR0)         ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */

/* LPTMR1 - Peripheral instance base addresses */
#define LPTMR1_BasePtr                 0xFFFF84D0UL //!< Peripheral base address
#define LPTMR1                         ((LPTMR_Type *) LPTMR1_BasePtr) //!< Freescale base pointer
#define LPTMR1_BASE_PTR                (LPTMR1) //!< Freescale style base pointer
/**
 * @} */ /* End group LPTMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer
* @brief C Struct for MCG
* @{
*/

/* ================================================================================ */
/* ================           MCG (file:MCG_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator module
 */
/**
* @addtogroup MCG_structs_GROUP MCG struct
* @brief Struct for MCG
* @{
*/
typedef struct {                                /*       MCG Structure                                                */
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /**< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /**< 0003: Control 4 Register                                           */
   __IO uint8_t   C5;                           /**< 0004: Control 5 Register                                           */
   __IO uint8_t   C6;                           /**< 0005: Control 6 Register                                           */
   __IO uint8_t   S;                            /**< 0006: Status Register                                              */
   __I  uint8_t   RESERVED0;                   
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
   __I  uint8_t   RESERVED1;                   
   __IO uint8_t   ATCVH;                        /**< 000A: ATM Compare Value High                                       */
   __IO uint8_t   ATCVL;                        /**< 000B: ATM Compare Value Low                                        */
} MCG_Type;

/**
 * @} */ /* End group MCG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCG_Register_Masks_GROUP MCG Register Masks
* @brief Register Masks for MCG
* @{
*/
/* ------- C1 Bit Fields                            ------ */
#define MCG_C1_IREFSTEN_MASK                     (0x01UL << MCG_C1_IREFSTEN_SHIFT)                   /*!< MCG_C1: IREFSTEN Mask                   */
#define MCG_C1_IREFSTEN_SHIFT                    0                                                   /*!< MCG_C1: IREFSTEN Position               */
#define MCG_C1_IRCLKEN_MASK                      (0x01UL << MCG_C1_IRCLKEN_SHIFT)                    /*!< MCG_C1: IRCLKEN Mask                    */
#define MCG_C1_IRCLKEN_SHIFT                     1                                                   /*!< MCG_C1: IRCLKEN Position                */
#define MCG_C1_IREFS_MASK                        (0x01UL << MCG_C1_IREFS_SHIFT)                      /*!< MCG_C1: IREFS Mask                      */
#define MCG_C1_IREFS_SHIFT                       2                                                   /*!< MCG_C1: IREFS Position                  */
#define MCG_C1_FRDIV_MASK                        (0x07UL << MCG_C1_FRDIV_SHIFT)                      /*!< MCG_C1: FRDIV Mask                      */
#define MCG_C1_FRDIV_SHIFT                       3                                                   /*!< MCG_C1: FRDIV Position                  */
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK) /*!< MCG_C1                                  */
#define MCG_C1_CLKS_MASK                         (0x03UL << MCG_C1_CLKS_SHIFT)                       /*!< MCG_C1: CLKS Mask                       */
#define MCG_C1_CLKS_SHIFT                        6                                                   /*!< MCG_C1: CLKS Position                   */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK) /*!< MCG_C1                                  */
/* ------- C2 Bit Fields                            ------ */
#define MCG_C2_IRCS_MASK                         (0x01UL << MCG_C2_IRCS_SHIFT)                       /*!< MCG_C2: IRCS Mask                       */
#define MCG_C2_IRCS_SHIFT                        0                                                   /*!< MCG_C2: IRCS Position                   */
#define MCG_C2_LP_MASK                           (0x01UL << MCG_C2_LP_SHIFT)                         /*!< MCG_C2: LP Mask                         */
#define MCG_C2_LP_SHIFT                          1                                                   /*!< MCG_C2: LP Position                     */
#define MCG_C2_EREFS_MASK                        (0x01UL << MCG_C2_EREFS_SHIFT)                      /*!< MCG_C2: EREFS Mask                      */
#define MCG_C2_EREFS_SHIFT                       2                                                   /*!< MCG_C2: EREFS Position                  */
#define MCG_C2_HGO_MASK                          (0x01UL << MCG_C2_HGO_SHIFT)                        /*!< MCG_C2: HGO Mask                        */
#define MCG_C2_HGO_SHIFT                         3                                                   /*!< MCG_C2: HGO Position                    */
#define MCG_C2_RANGE_MASK                        (0x03UL << MCG_C2_RANGE_SHIFT)                      /*!< MCG_C2: RANGE Mask                      */
#define MCG_C2_RANGE_SHIFT                       4                                                   /*!< MCG_C2: RANGE Position                  */
#define MCG_C2_RANGE(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE_SHIFT))&MCG_C2_RANGE_MASK) /*!< MCG_C2                                  */
/* ------- C3 Bit Fields                            ------ */
#define MCG_C3_SCTRIM_MASK                       (0xFFUL << MCG_C3_SCTRIM_SHIFT)                     /*!< MCG_C3: SCTRIM Mask                     */
#define MCG_C3_SCTRIM_SHIFT                      0                                                   /*!< MCG_C3: SCTRIM Position                 */
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK) /*!< MCG_C3                                  */
/* ------- C4 Bit Fields                            ------ */
#define MCG_C4_SCFTRIM_MASK                      (0x01UL << MCG_C4_SCFTRIM_SHIFT)                    /*!< MCG_C4: SCFTRIM Mask                    */
#define MCG_C4_SCFTRIM_SHIFT                     0                                                   /*!< MCG_C4: SCFTRIM Position                */
#define MCG_C4_FCTRIM_MASK                       (0x0FUL << MCG_C4_FCTRIM_SHIFT)                     /*!< MCG_C4: FCTRIM Mask                     */
#define MCG_C4_FCTRIM_SHIFT                      1                                                   /*!< MCG_C4: FCTRIM Position                 */
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DRST_DRS_MASK                     (0x03UL << MCG_C4_DRST_DRS_SHIFT)                   /*!< MCG_C4: DRST_DRS Mask                   */
#define MCG_C4_DRST_DRS_SHIFT                    5                                                   /*!< MCG_C4: DRST_DRS Position               */
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DMX32_MASK                        (0x01UL << MCG_C4_DMX32_SHIFT)                      /*!< MCG_C4: DMX32 Mask                      */
#define MCG_C4_DMX32_SHIFT                       7                                                   /*!< MCG_C4: DMX32 Position                  */
/* ------- C5 Bit Fields                            ------ */
#define MCG_C5_PRDIV_MASK                        (0x1FUL << MCG_C5_PRDIV_SHIFT)                      /*!< MCG_C5: PRDIV Mask                      */
#define MCG_C5_PRDIV_SHIFT                       0                                                   /*!< MCG_C5: PRDIV Position                  */
#define MCG_C5_PRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C5_PRDIV_SHIFT))&MCG_C5_PRDIV_MASK) /*!< MCG_C5                                  */
#define MCG_C5_PLLSTEN_MASK                      (0x01UL << MCG_C5_PLLSTEN_SHIFT)                    /*!< MCG_C5: PLLSTEN Mask                    */
#define MCG_C5_PLLSTEN_SHIFT                     5                                                   /*!< MCG_C5: PLLSTEN Position                */
#define MCG_C5_PLLCLKEN_MASK                     (0x01UL << MCG_C5_PLLCLKEN_SHIFT)                   /*!< MCG_C5: PLLCLKEN Mask                   */
#define MCG_C5_PLLCLKEN_SHIFT                    6                                                   /*!< MCG_C5: PLLCLKEN Position               */
/* ------- C6 Bit Fields                            ------ */
#define MCG_C6_VDIV_MASK                         (0x1FUL << MCG_C6_VDIV_SHIFT)                       /*!< MCG_C6: VDIV Mask                       */
#define MCG_C6_VDIV_SHIFT                        0                                                   /*!< MCG_C6: VDIV Position                   */
#define MCG_C6_VDIV(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_VDIV_SHIFT))&MCG_C6_VDIV_MASK) /*!< MCG_C6                                  */
#define MCG_C6_CME_MASK                          (0x01UL << MCG_C6_CME_SHIFT)                        /*!< MCG_C6: CME Mask                        */
#define MCG_C6_CME_SHIFT                         5                                                   /*!< MCG_C6: CME Position                    */
#define MCG_C6_PLLS_MASK                         (0x01UL << MCG_C6_PLLS_SHIFT)                       /*!< MCG_C6: PLLS Mask                       */
#define MCG_C6_PLLS_SHIFT                        6                                                   /*!< MCG_C6: PLLS Position                   */
#define MCG_C6_LOLIE_MASK                        (0x01UL << MCG_C6_LOLIE_SHIFT)                      /*!< MCG_C6: LOLIE Mask                      */
#define MCG_C6_LOLIE_SHIFT                       7                                                   /*!< MCG_C6: LOLIE Position                  */
/* ------- S Bit Fields                             ------ */
#define MCG_S_IRCST_MASK                         (0x01UL << MCG_S_IRCST_SHIFT)                       /*!< MCG_S: IRCST Mask                       */
#define MCG_S_IRCST_SHIFT                        0                                                   /*!< MCG_S: IRCST Position                   */
#define MCG_S_OSCINIT_MASK                       (0x01UL << MCG_S_OSCINIT_SHIFT)                     /*!< MCG_S: OSCINIT Mask                     */
#define MCG_S_OSCINIT_SHIFT                      1                                                   /*!< MCG_S: OSCINIT Position                 */
#define MCG_S_CLKST_MASK                         (0x03UL << MCG_S_CLKST_SHIFT)                       /*!< MCG_S: CLKST Mask                       */
#define MCG_S_CLKST_SHIFT                        2                                                   /*!< MCG_S: CLKST Position                   */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK) /*!< MCG_S                                   */
#define MCG_S_IREFST_MASK                        (0x01UL << MCG_S_IREFST_SHIFT)                      /*!< MCG_S: IREFST Mask                      */
#define MCG_S_IREFST_SHIFT                       4                                                   /*!< MCG_S: IREFST Position                  */
#define MCG_S_PLLST_MASK                         (0x01UL << MCG_S_PLLST_SHIFT)                       /*!< MCG_S: PLLST Mask                       */
#define MCG_S_PLLST_SHIFT                        5                                                   /*!< MCG_S: PLLST Position                   */
#define MCG_S_LOCK0_MASK                         (0x01UL << MCG_S_LOCK0_SHIFT)                       /*!< MCG_S: LOCK0 Mask                       */
#define MCG_S_LOCK0_SHIFT                        6                                                   /*!< MCG_S: LOCK0 Position                   */
#define MCG_S_LOLS_MASK                          (0x01UL << MCG_S_LOLS_SHIFT)                        /*!< MCG_S: LOLS Mask                        */
#define MCG_S_LOLS_SHIFT                         7                                                   /*!< MCG_S: LOLS Position                    */
/* ------- SC Bit Fields                            ------ */
#define MCG_SC_LOCS0_MASK                        (0x01UL << MCG_SC_LOCS0_SHIFT)                      /*!< MCG_SC: LOCS0 Mask                      */
#define MCG_SC_LOCS0_SHIFT                       0                                                   /*!< MCG_SC: LOCS0 Position                  */
#define MCG_SC_FCRDIV_MASK                       (0x07UL << MCG_SC_FCRDIV_SHIFT)                     /*!< MCG_SC: FCRDIV Mask                     */
#define MCG_SC_FCRDIV_SHIFT                      1                                                   /*!< MCG_SC: FCRDIV Position                 */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK) /*!< MCG_SC                                  */
#define MCG_SC_FLTPRSRV_MASK                     (0x01UL << MCG_SC_FLTPRSRV_SHIFT)                   /*!< MCG_SC: FLTPRSRV Mask                   */
#define MCG_SC_FLTPRSRV_SHIFT                    4                                                   /*!< MCG_SC: FLTPRSRV Position               */
#define MCG_SC_ATMF_MASK                         (0x01UL << MCG_SC_ATMF_SHIFT)                       /*!< MCG_SC: ATMF Mask                       */
#define MCG_SC_ATMF_SHIFT                        5                                                   /*!< MCG_SC: ATMF Position                   */
#define MCG_SC_ATMS_MASK                         (0x01UL << MCG_SC_ATMS_SHIFT)                       /*!< MCG_SC: ATMS Mask                       */
#define MCG_SC_ATMS_SHIFT                        6                                                   /*!< MCG_SC: ATMS Position                   */
#define MCG_SC_ATME_MASK                         (0x01UL << MCG_SC_ATME_SHIFT)                       /*!< MCG_SC: ATME Mask                       */
#define MCG_SC_ATME_SHIFT                        7                                                   /*!< MCG_SC: ATME Position                   */
/* ------- ATCVH Bit Fields                         ------ */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFUL << MCG_ATCVH_ATCVH_SHIFT)                   /*!< MCG_ATCVH: ATCVH Mask                   */
#define MCG_ATCVH_ATCVH_SHIFT                    0                                                   /*!< MCG_ATCVH: ATCVH Position               */
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK) /*!< MCG_ATCVH                               */
/* ------- ATCVL Bit Fields                         ------ */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFUL << MCG_ATCVL_ATCVL_SHIFT)                   /*!< MCG_ATCVL: ATCVL Mask                   */
#define MCG_ATCVL_ATCVL_SHIFT                    0                                                   /*!< MCG_ATCVL: ATCVL Position               */
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK) /*!< MCG_ATCVL                               */
/**
 * @} */ /* End group MCG_Register_Masks_GROUP 
 */

/* MCG - Peripheral instance base addresses */
#define MCG_BasePtr                    0xFFFF8400UL //!< Peripheral base address
#define MCG                            ((MCG_Type *) MCG_BasePtr) //!< Freescale base pointer
#define MCG_BASE_PTR                   (MCG) //!< Freescale style base pointer
/**
 * @} */ /* End group MCG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MTIM_Peripheral_access_layer_GROUP MTIM Peripheral Access Layer
* @brief C Struct for MTIM
* @{
*/

/* ================================================================================ */
/* ================           MTIM0 (file:MTIM0_MCF51)             ================ */
/* ================================================================================ */

/**
 * @brief Modulo Timer Module
 */
/**
* @addtogroup MTIM_structs_GROUP MTIM struct
* @brief Struct for MTIM
* @{
*/
typedef struct {                                /*       MTIM0 Structure                                              */
   __IO uint8_t   SC;                           /**< 0000: Status and Control                                           */
   __IO uint8_t   CLK;                          /**< 0001: Clock configuration register                                 */
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  CNT;                       /**< 0002: Counter                                                      */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   CNTH;                   /**< 0002: Counter High                                                 */
         __IO uint8_t   CNTL;                   /**< 0003: Counter Low                                                  */
      };
   };
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  MOD;                       /**< 0004: Modulo High                                                  */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   MODH;                   /**< 0004: Modulo High                                                  */
         __IO uint8_t   MODL;                   /**< 0005: Modulo Low                                                   */
      };
   };
} MTIM_Type;

/**
 * @} */ /* End group MTIM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTIM0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MTIM_Register_Masks_GROUP MTIM Register Masks
* @brief Register Masks for MTIM
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define MTIM0_SC_TSTP_MASK                       (0x01UL << MTIM0_SC_TSTP_SHIFT)                     /*!< MTIM0_SC: TSTP Mask                     */
#define MTIM0_SC_TSTP_SHIFT                      4                                                   /*!< MTIM0_SC: TSTP Position                 */
#define MTIM0_SC_TRST_MASK                       (0x01UL << MTIM0_SC_TRST_SHIFT)                     /*!< MTIM0_SC: TRST Mask                     */
#define MTIM0_SC_TRST_SHIFT                      5                                                   /*!< MTIM0_SC: TRST Position                 */
#define MTIM0_SC_TOIE_MASK                       (0x01UL << MTIM0_SC_TOIE_SHIFT)                     /*!< MTIM0_SC: TOIE Mask                     */
#define MTIM0_SC_TOIE_SHIFT                      6                                                   /*!< MTIM0_SC: TOIE Position                 */
#define MTIM0_SC_TOF_MASK                        (0x01UL << MTIM0_SC_TOF_SHIFT)                      /*!< MTIM0_SC: TOF Mask                      */
#define MTIM0_SC_TOF_SHIFT                       7                                                   /*!< MTIM0_SC: TOF Position                  */
/* ------- CLK Bit Fields                           ------ */
#define MTIM0_CLK_PS_MASK                        (0x0FUL << MTIM0_CLK_PS_SHIFT)                      /*!< MTIM0_CLK: PS Mask                      */
#define MTIM0_CLK_PS_SHIFT                       0                                                   /*!< MTIM0_CLK: PS Position                  */
#define MTIM0_CLK_PS(x)                          (((uint8_t)(((uint8_t)(x))<<MTIM0_CLK_PS_SHIFT))&MTIM0_CLK_PS_MASK) /*!< MTIM0_CLK                               */
#define MTIM0_CLK_CLKS_MASK                      (0x03UL << MTIM0_CLK_CLKS_SHIFT)                    /*!< MTIM0_CLK: CLKS Mask                    */
#define MTIM0_CLK_CLKS_SHIFT                     4                                                   /*!< MTIM0_CLK: CLKS Position                */
#define MTIM0_CLK_CLKS(x)                        (((uint8_t)(((uint8_t)(x))<<MTIM0_CLK_CLKS_SHIFT))&MTIM0_CLK_CLKS_MASK) /*!< MTIM0_CLK                               */
/* ------- CNT Bit Fields                           ------ */
#define MTIM0_CNT_COUNT_MASK                     (0xFFFFUL << MTIM0_CNT_COUNT_SHIFT)                 /*!< MTIM0_CNT: COUNT Mask                   */
#define MTIM0_CNT_COUNT_SHIFT                    0                                                   /*!< MTIM0_CNT: COUNT Position               */
#define MTIM0_CNT_COUNT(x)                       (((uint16_t)(((uint16_t)(x))<<MTIM0_CNT_COUNT_SHIFT))&MTIM0_CNT_COUNT_MASK) /*!< MTIM0_CNT                               */
/* ------- CNTH Bit Fields                          ------ */
#define MTIM0_CNTH_COUNT_MASK                    (0xFFUL << MTIM0_CNTH_COUNT_SHIFT)                  /*!< MTIM0_CNTH: COUNT Mask                  */
#define MTIM0_CNTH_COUNT_SHIFT                   0                                                   /*!< MTIM0_CNTH: COUNT Position              */
#define MTIM0_CNTH_COUNT(x)                      (((uint8_t)(((uint8_t)(x))<<MTIM0_CNTH_COUNT_SHIFT))&MTIM0_CNTH_COUNT_MASK) /*!< MTIM0_CNTH                              */
/* ------- CNTL Bit Fields                          ------ */
#define MTIM0_CNTL_COUNT_MASK                    (0xFFUL << MTIM0_CNTL_COUNT_SHIFT)                  /*!< MTIM0_CNTL: COUNT Mask                  */
#define MTIM0_CNTL_COUNT_SHIFT                   0                                                   /*!< MTIM0_CNTL: COUNT Position              */
#define MTIM0_CNTL_COUNT(x)                      (((uint8_t)(((uint8_t)(x))<<MTIM0_CNTL_COUNT_SHIFT))&MTIM0_CNTL_COUNT_MASK) /*!< MTIM0_CNTL                              */
/* ------- MOD Bit Fields                           ------ */
#define MTIM0_MOD_MOD_MASK                       (0xFFFFUL << MTIM0_MOD_MOD_SHIFT)                   /*!< MTIM0_MOD: MOD Mask                     */
#define MTIM0_MOD_MOD_SHIFT                      0                                                   /*!< MTIM0_MOD: MOD Position                 */
#define MTIM0_MOD_MOD(x)                         (((uint16_t)(((uint16_t)(x))<<MTIM0_MOD_MOD_SHIFT))&MTIM0_MOD_MOD_MASK) /*!< MTIM0_MOD                               */
/* ------- MODH Bit Fields                          ------ */
#define MTIM0_MODH_MOD_MASK                      (0xFFUL << MTIM0_MODH_MOD_SHIFT)                    /*!< MTIM0_MODH: MOD Mask                    */
#define MTIM0_MODH_MOD_SHIFT                     0                                                   /*!< MTIM0_MODH: MOD Position                */
#define MTIM0_MODH_MOD(x)                        (((uint8_t)(((uint8_t)(x))<<MTIM0_MODH_MOD_SHIFT))&MTIM0_MODH_MOD_MASK) /*!< MTIM0_MODH                              */
/* ------- MODL Bit Fields                          ------ */
#define MTIM0_MODL_MOD_MASK                      (0xFFUL << MTIM0_MODL_MOD_SHIFT)                    /*!< MTIM0_MODL: MOD Mask                    */
#define MTIM0_MODL_MOD_SHIFT                     0                                                   /*!< MTIM0_MODL: MOD Position                */
#define MTIM0_MODL_MOD(x)                        (((uint8_t)(((uint8_t)(x))<<MTIM0_MODL_MOD_SHIFT))&MTIM0_MODL_MOD_MASK) /*!< MTIM0_MODL                              */
/**
 * @} */ /* End group MTIM_Register_Masks_GROUP 
 */

/* MTIM0 - Peripheral instance base addresses */
#define MTIM0_BasePtr                  0xFFFF8410UL //!< Peripheral base address
#define MTIM0                          ((MTIM_Type *) MTIM0_BasePtr) //!< Freescale base pointer
#define MTIM0_BASE_PTR                 (MTIM0) //!< Freescale style base pointer
/**
 * @} */ /* End group MTIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MXC_Peripheral_access_layer_GROUP MXC Peripheral Access Layer
* @brief C Struct for MXC
* @{
*/

/* ================================================================================ */
/* ================           MXC (file:MXC_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief External Interrupt
 */
/**
* @addtogroup MXC_structs_GROUP MXC struct
* @brief Struct for MXC
* @{
*/
typedef struct {                                /*       MXC Structure                                                */
   __IO uint8_t   PTAPF1;                       /**< 0000: Port A Pin Function 1 Register                               */
   __IO uint8_t   PTAPF2;                       /**< 0001: Port A Pin Function 2 Register                               */
   __IO uint8_t   PTAPF3;                       /**< 0002: Port A Pin Function 3 Register                               */
   __IO uint8_t   PTAPF4;                       /**< 0003: Port A Pin Function 1 Register                               */
   __IO uint8_t   PTBPF1;                       /**< 0004: Port B Pin Function 1 Register                               */
   __IO uint8_t   PTBPF2;                       /**< 0005: Port B Pin Function 2 Register                               */
   __IO uint8_t   PTBPF3;                       /**< 0006: Port B Pin Function 3 Register                               */
   __IO uint8_t   PTBPF4;                       /**< 0007: Port B Pin Function 1 Register                               */
   __IO uint8_t   PTCPF1;                       /**< 0008: Port C Pin Function 1 Register                               */
   __IO uint8_t   PTCPF2;                       /**< 0009: Port C Pin Function 2 Register                               */
   __IO uint8_t   PTCPF3;                       /**< 000A: Port C Pin Function 3 Register                               */
   __IO uint8_t   PTCPF4;                       /**< 000B: Port C Pin Function 1 Register                               */
   __IO uint8_t   PTDPF1;                       /**< 000C: Port D Pin Function 1 Register                               */
   __IO uint8_t   PTDPF2;                       /**< 000D: Port D Pin Function 2 Register                               */
   __IO uint8_t   PTDPF3;                       /**< 000E: Port D Pin Function 3 Register                               */
   __IO uint8_t   PTDPF4;                       /**< 000F: Port D Pin Function 1 Register                               */
   __IO uint8_t   PTEPF1;                       /**< 0010: Port E Pin Function 1 Register                               */
   __IO uint8_t   PTEPF2;                       /**< 0011: Port E Pin Function 2 Register                               */
   __IO uint8_t   PTEPF3;                       /**< 0012: Port E Pin Function 3 Register                               */
   __IO uint8_t   PTEPF4;                       /**< 0013: Port E Pin Function 1 Register                               */
   __IO uint8_t   PTFPF1;                       /**< 0014: Port F Pin Function 1 Register                               */
   __IO uint8_t   PTFPF2;                       /**< 0015: Port F Pin Function 2 Register                               */
   __IO uint8_t   PTFPF3;                       /**< 0016: Port F Pin Function 3 Register                               */
   __IO uint8_t   PTFPF4;                       /**< 0017: Port F Pin Function 1 Register                               */
} MXC_Type;

/**
 * @} */ /* End group MXC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MXC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MXC_Register_Masks_GROUP MXC Register Masks
* @brief Register Masks for MXC
* @{
*/
/* ------- PTAPF1 Bit Fields                        ------ */
#define MXC_PTAPF1_A6_MASK                       (0x0FUL << MXC_PTAPF1_A6_SHIFT)                     /*!< MXC_PTAPF1: A6 Mask                     */
#define MXC_PTAPF1_A6_SHIFT                      0                                                   /*!< MXC_PTAPF1: A6 Position                 */
#define MXC_PTAPF1_A6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF1_A6_SHIFT))&MXC_PTAPF1_A6_MASK) /*!< MXC_PTAPF1                              */
#define MXC_PTAPF1_A7_MASK                       (0x0FUL << MXC_PTAPF1_A7_SHIFT)                     /*!< MXC_PTAPF1: A7 Mask                     */
#define MXC_PTAPF1_A7_SHIFT                      4                                                   /*!< MXC_PTAPF1: A7 Position                 */
#define MXC_PTAPF1_A7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF1_A7_SHIFT))&MXC_PTAPF1_A7_MASK) /*!< MXC_PTAPF1                              */
/* ------- PTAPF2 Bit Fields                        ------ */
#define MXC_PTAPF2_A4_MASK                       (0x0FUL << MXC_PTAPF2_A4_SHIFT)                     /*!< MXC_PTAPF2: A4 Mask                     */
#define MXC_PTAPF2_A4_SHIFT                      0                                                   /*!< MXC_PTAPF2: A4 Position                 */
#define MXC_PTAPF2_A4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF2_A4_SHIFT))&MXC_PTAPF2_A4_MASK) /*!< MXC_PTAPF2                              */
#define MXC_PTAPF2_A5_MASK                       (0x0FUL << MXC_PTAPF2_A5_SHIFT)                     /*!< MXC_PTAPF2: A5 Mask                     */
#define MXC_PTAPF2_A5_SHIFT                      4                                                   /*!< MXC_PTAPF2: A5 Position                 */
#define MXC_PTAPF2_A5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF2_A5_SHIFT))&MXC_PTAPF2_A5_MASK) /*!< MXC_PTAPF2                              */
/* ------- PTAPF3 Bit Fields                        ------ */
#define MXC_PTAPF3_A2_MASK                       (0x0FUL << MXC_PTAPF3_A2_SHIFT)                     /*!< MXC_PTAPF3: A2 Mask                     */
#define MXC_PTAPF3_A2_SHIFT                      0                                                   /*!< MXC_PTAPF3: A2 Position                 */
#define MXC_PTAPF3_A2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF3_A2_SHIFT))&MXC_PTAPF3_A2_MASK) /*!< MXC_PTAPF3                              */
#define MXC_PTAPF3_A3_MASK                       (0x0FUL << MXC_PTAPF3_A3_SHIFT)                     /*!< MXC_PTAPF3: A3 Mask                     */
#define MXC_PTAPF3_A3_SHIFT                      4                                                   /*!< MXC_PTAPF3: A3 Position                 */
#define MXC_PTAPF3_A3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF3_A3_SHIFT))&MXC_PTAPF3_A3_MASK) /*!< MXC_PTAPF3                              */
/* ------- PTAPF4 Bit Fields                        ------ */
#define MXC_PTAPF4_A0_MASK                       (0x0FUL << MXC_PTAPF4_A0_SHIFT)                     /*!< MXC_PTAPF4: A0 Mask                     */
#define MXC_PTAPF4_A0_SHIFT                      0                                                   /*!< MXC_PTAPF4: A0 Position                 */
#define MXC_PTAPF4_A0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF4_A0_SHIFT))&MXC_PTAPF4_A0_MASK) /*!< MXC_PTAPF4                              */
#define MXC_PTAPF4_A1_MASK                       (0x0FUL << MXC_PTAPF4_A1_SHIFT)                     /*!< MXC_PTAPF4: A1 Mask                     */
#define MXC_PTAPF4_A1_SHIFT                      4                                                   /*!< MXC_PTAPF4: A1 Position                 */
#define MXC_PTAPF4_A1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTAPF4_A1_SHIFT))&MXC_PTAPF4_A1_MASK) /*!< MXC_PTAPF4                              */
/* ------- PTBPF1 Bit Fields                        ------ */
#define MXC_PTBPF1_B6_MASK                       (0x0FUL << MXC_PTBPF1_B6_SHIFT)                     /*!< MXC_PTBPF1: B6 Mask                     */
#define MXC_PTBPF1_B6_SHIFT                      0                                                   /*!< MXC_PTBPF1: B6 Position                 */
#define MXC_PTBPF1_B6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF1_B6_SHIFT))&MXC_PTBPF1_B6_MASK) /*!< MXC_PTBPF1                              */
#define MXC_PTBPF1_B7_MASK                       (0x0FUL << MXC_PTBPF1_B7_SHIFT)                     /*!< MXC_PTBPF1: B7 Mask                     */
#define MXC_PTBPF1_B7_SHIFT                      4                                                   /*!< MXC_PTBPF1: B7 Position                 */
#define MXC_PTBPF1_B7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF1_B7_SHIFT))&MXC_PTBPF1_B7_MASK) /*!< MXC_PTBPF1                              */
/* ------- PTBPF2 Bit Fields                        ------ */
#define MXC_PTBPF2_B4_MASK                       (0x0FUL << MXC_PTBPF2_B4_SHIFT)                     /*!< MXC_PTBPF2: B4 Mask                     */
#define MXC_PTBPF2_B4_SHIFT                      0                                                   /*!< MXC_PTBPF2: B4 Position                 */
#define MXC_PTBPF2_B4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF2_B4_SHIFT))&MXC_PTBPF2_B4_MASK) /*!< MXC_PTBPF2                              */
#define MXC_PTBPF2_B5_MASK                       (0x0FUL << MXC_PTBPF2_B5_SHIFT)                     /*!< MXC_PTBPF2: B5 Mask                     */
#define MXC_PTBPF2_B5_SHIFT                      4                                                   /*!< MXC_PTBPF2: B5 Position                 */
#define MXC_PTBPF2_B5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF2_B5_SHIFT))&MXC_PTBPF2_B5_MASK) /*!< MXC_PTBPF2                              */
/* ------- PTBPF3 Bit Fields                        ------ */
#define MXC_PTBPF3_B2_MASK                       (0x0FUL << MXC_PTBPF3_B2_SHIFT)                     /*!< MXC_PTBPF3: B2 Mask                     */
#define MXC_PTBPF3_B2_SHIFT                      0                                                   /*!< MXC_PTBPF3: B2 Position                 */
#define MXC_PTBPF3_B2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF3_B2_SHIFT))&MXC_PTBPF3_B2_MASK) /*!< MXC_PTBPF3                              */
#define MXC_PTBPF3_B3_MASK                       (0x0FUL << MXC_PTBPF3_B3_SHIFT)                     /*!< MXC_PTBPF3: B3 Mask                     */
#define MXC_PTBPF3_B3_SHIFT                      4                                                   /*!< MXC_PTBPF3: B3 Position                 */
#define MXC_PTBPF3_B3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF3_B3_SHIFT))&MXC_PTBPF3_B3_MASK) /*!< MXC_PTBPF3                              */
/* ------- PTBPF4 Bit Fields                        ------ */
#define MXC_PTBPF4_B0_MASK                       (0x0FUL << MXC_PTBPF4_B0_SHIFT)                     /*!< MXC_PTBPF4: B0 Mask                     */
#define MXC_PTBPF4_B0_SHIFT                      0                                                   /*!< MXC_PTBPF4: B0 Position                 */
#define MXC_PTBPF4_B0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF4_B0_SHIFT))&MXC_PTBPF4_B0_MASK) /*!< MXC_PTBPF4                              */
#define MXC_PTBPF4_B1_MASK                       (0x0FUL << MXC_PTBPF4_B1_SHIFT)                     /*!< MXC_PTBPF4: B1 Mask                     */
#define MXC_PTBPF4_B1_SHIFT                      4                                                   /*!< MXC_PTBPF4: B1 Position                 */
#define MXC_PTBPF4_B1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTBPF4_B1_SHIFT))&MXC_PTBPF4_B1_MASK) /*!< MXC_PTBPF4                              */
/* ------- PTCPF1 Bit Fields                        ------ */
#define MXC_PTCPF1_C6_MASK                       (0x0FUL << MXC_PTCPF1_C6_SHIFT)                     /*!< MXC_PTCPF1: C6 Mask                     */
#define MXC_PTCPF1_C6_SHIFT                      0                                                   /*!< MXC_PTCPF1: C6 Position                 */
#define MXC_PTCPF1_C6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF1_C6_SHIFT))&MXC_PTCPF1_C6_MASK) /*!< MXC_PTCPF1                              */
#define MXC_PTCPF1_C7_MASK                       (0x0FUL << MXC_PTCPF1_C7_SHIFT)                     /*!< MXC_PTCPF1: C7 Mask                     */
#define MXC_PTCPF1_C7_SHIFT                      4                                                   /*!< MXC_PTCPF1: C7 Position                 */
#define MXC_PTCPF1_C7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF1_C7_SHIFT))&MXC_PTCPF1_C7_MASK) /*!< MXC_PTCPF1                              */
/* ------- PTCPF2 Bit Fields                        ------ */
#define MXC_PTCPF2_C4_MASK                       (0x0FUL << MXC_PTCPF2_C4_SHIFT)                     /*!< MXC_PTCPF2: C4 Mask                     */
#define MXC_PTCPF2_C4_SHIFT                      0                                                   /*!< MXC_PTCPF2: C4 Position                 */
#define MXC_PTCPF2_C4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF2_C4_SHIFT))&MXC_PTCPF2_C4_MASK) /*!< MXC_PTCPF2                              */
#define MXC_PTCPF2_C5_MASK                       (0x0FUL << MXC_PTCPF2_C5_SHIFT)                     /*!< MXC_PTCPF2: C5 Mask                     */
#define MXC_PTCPF2_C5_SHIFT                      4                                                   /*!< MXC_PTCPF2: C5 Position                 */
#define MXC_PTCPF2_C5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF2_C5_SHIFT))&MXC_PTCPF2_C5_MASK) /*!< MXC_PTCPF2                              */
/* ------- PTCPF3 Bit Fields                        ------ */
#define MXC_PTCPF3_C2_MASK                       (0x0FUL << MXC_PTCPF3_C2_SHIFT)                     /*!< MXC_PTCPF3: C2 Mask                     */
#define MXC_PTCPF3_C2_SHIFT                      0                                                   /*!< MXC_PTCPF3: C2 Position                 */
#define MXC_PTCPF3_C2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF3_C2_SHIFT))&MXC_PTCPF3_C2_MASK) /*!< MXC_PTCPF3                              */
#define MXC_PTCPF3_C3_MASK                       (0x0FUL << MXC_PTCPF3_C3_SHIFT)                     /*!< MXC_PTCPF3: C3 Mask                     */
#define MXC_PTCPF3_C3_SHIFT                      4                                                   /*!< MXC_PTCPF3: C3 Position                 */
#define MXC_PTCPF3_C3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF3_C3_SHIFT))&MXC_PTCPF3_C3_MASK) /*!< MXC_PTCPF3                              */
/* ------- PTCPF4 Bit Fields                        ------ */
#define MXC_PTCPF4_C0_MASK                       (0x0FUL << MXC_PTCPF4_C0_SHIFT)                     /*!< MXC_PTCPF4: C0 Mask                     */
#define MXC_PTCPF4_C0_SHIFT                      0                                                   /*!< MXC_PTCPF4: C0 Position                 */
#define MXC_PTCPF4_C0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF4_C0_SHIFT))&MXC_PTCPF4_C0_MASK) /*!< MXC_PTCPF4                              */
#define MXC_PTCPF4_C1_MASK                       (0x0FUL << MXC_PTCPF4_C1_SHIFT)                     /*!< MXC_PTCPF4: C1 Mask                     */
#define MXC_PTCPF4_C1_SHIFT                      4                                                   /*!< MXC_PTCPF4: C1 Position                 */
#define MXC_PTCPF4_C1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTCPF4_C1_SHIFT))&MXC_PTCPF4_C1_MASK) /*!< MXC_PTCPF4                              */
/* ------- PTDPF1 Bit Fields                        ------ */
#define MXC_PTDPF1_D6_MASK                       (0x0FUL << MXC_PTDPF1_D6_SHIFT)                     /*!< MXC_PTDPF1: D6 Mask                     */
#define MXC_PTDPF1_D6_SHIFT                      0                                                   /*!< MXC_PTDPF1: D6 Position                 */
#define MXC_PTDPF1_D6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF1_D6_SHIFT))&MXC_PTDPF1_D6_MASK) /*!< MXC_PTDPF1                              */
#define MXC_PTDPF1_D7_MASK                       (0x0FUL << MXC_PTDPF1_D7_SHIFT)                     /*!< MXC_PTDPF1: D7 Mask                     */
#define MXC_PTDPF1_D7_SHIFT                      4                                                   /*!< MXC_PTDPF1: D7 Position                 */
#define MXC_PTDPF1_D7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF1_D7_SHIFT))&MXC_PTDPF1_D7_MASK) /*!< MXC_PTDPF1                              */
/* ------- PTDPF2 Bit Fields                        ------ */
#define MXC_PTDPF2_D4_MASK                       (0x0FUL << MXC_PTDPF2_D4_SHIFT)                     /*!< MXC_PTDPF2: D4 Mask                     */
#define MXC_PTDPF2_D4_SHIFT                      0                                                   /*!< MXC_PTDPF2: D4 Position                 */
#define MXC_PTDPF2_D4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF2_D4_SHIFT))&MXC_PTDPF2_D4_MASK) /*!< MXC_PTDPF2                              */
#define MXC_PTDPF2_D5_MASK                       (0x0FUL << MXC_PTDPF2_D5_SHIFT)                     /*!< MXC_PTDPF2: D5 Mask                     */
#define MXC_PTDPF2_D5_SHIFT                      4                                                   /*!< MXC_PTDPF2: D5 Position                 */
#define MXC_PTDPF2_D5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF2_D5_SHIFT))&MXC_PTDPF2_D5_MASK) /*!< MXC_PTDPF2                              */
/* ------- PTDPF3 Bit Fields                        ------ */
#define MXC_PTDPF3_D2_MASK                       (0x0FUL << MXC_PTDPF3_D2_SHIFT)                     /*!< MXC_PTDPF3: D2 Mask                     */
#define MXC_PTDPF3_D2_SHIFT                      0                                                   /*!< MXC_PTDPF3: D2 Position                 */
#define MXC_PTDPF3_D2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF3_D2_SHIFT))&MXC_PTDPF3_D2_MASK) /*!< MXC_PTDPF3                              */
#define MXC_PTDPF3_D3_MASK                       (0x0FUL << MXC_PTDPF3_D3_SHIFT)                     /*!< MXC_PTDPF3: D3 Mask                     */
#define MXC_PTDPF3_D3_SHIFT                      4                                                   /*!< MXC_PTDPF3: D3 Position                 */
#define MXC_PTDPF3_D3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF3_D3_SHIFT))&MXC_PTDPF3_D3_MASK) /*!< MXC_PTDPF3                              */
/* ------- PTDPF4 Bit Fields                        ------ */
#define MXC_PTDPF4_D0_MASK                       (0x0FUL << MXC_PTDPF4_D0_SHIFT)                     /*!< MXC_PTDPF4: D0 Mask                     */
#define MXC_PTDPF4_D0_SHIFT                      0                                                   /*!< MXC_PTDPF4: D0 Position                 */
#define MXC_PTDPF4_D0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF4_D0_SHIFT))&MXC_PTDPF4_D0_MASK) /*!< MXC_PTDPF4                              */
#define MXC_PTDPF4_D1_MASK                       (0x0FUL << MXC_PTDPF4_D1_SHIFT)                     /*!< MXC_PTDPF4: D1 Mask                     */
#define MXC_PTDPF4_D1_SHIFT                      4                                                   /*!< MXC_PTDPF4: D1 Position                 */
#define MXC_PTDPF4_D1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTDPF4_D1_SHIFT))&MXC_PTDPF4_D1_MASK) /*!< MXC_PTDPF4                              */
/* ------- PTEPF1 Bit Fields                        ------ */
#define MXC_PTEPF1_E6_MASK                       (0x0FUL << MXC_PTEPF1_E6_SHIFT)                     /*!< MXC_PTEPF1: E6 Mask                     */
#define MXC_PTEPF1_E6_SHIFT                      0                                                   /*!< MXC_PTEPF1: E6 Position                 */
#define MXC_PTEPF1_E6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF1_E6_SHIFT))&MXC_PTEPF1_E6_MASK) /*!< MXC_PTEPF1                              */
#define MXC_PTEPF1_E7_MASK                       (0x0FUL << MXC_PTEPF1_E7_SHIFT)                     /*!< MXC_PTEPF1: E7 Mask                     */
#define MXC_PTEPF1_E7_SHIFT                      4                                                   /*!< MXC_PTEPF1: E7 Position                 */
#define MXC_PTEPF1_E7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF1_E7_SHIFT))&MXC_PTEPF1_E7_MASK) /*!< MXC_PTEPF1                              */
/* ------- PTEPF2 Bit Fields                        ------ */
#define MXC_PTEPF2_E4_MASK                       (0x0FUL << MXC_PTEPF2_E4_SHIFT)                     /*!< MXC_PTEPF2: E4 Mask                     */
#define MXC_PTEPF2_E4_SHIFT                      0                                                   /*!< MXC_PTEPF2: E4 Position                 */
#define MXC_PTEPF2_E4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF2_E4_SHIFT))&MXC_PTEPF2_E4_MASK) /*!< MXC_PTEPF2                              */
#define MXC_PTEPF2_E5_MASK                       (0x0FUL << MXC_PTEPF2_E5_SHIFT)                     /*!< MXC_PTEPF2: E5 Mask                     */
#define MXC_PTEPF2_E5_SHIFT                      4                                                   /*!< MXC_PTEPF2: E5 Position                 */
#define MXC_PTEPF2_E5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF2_E5_SHIFT))&MXC_PTEPF2_E5_MASK) /*!< MXC_PTEPF2                              */
/* ------- PTEPF3 Bit Fields                        ------ */
#define MXC_PTEPF3_E2_MASK                       (0x0FUL << MXC_PTEPF3_E2_SHIFT)                     /*!< MXC_PTEPF3: E2 Mask                     */
#define MXC_PTEPF3_E2_SHIFT                      0                                                   /*!< MXC_PTEPF3: E2 Position                 */
#define MXC_PTEPF3_E2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF3_E2_SHIFT))&MXC_PTEPF3_E2_MASK) /*!< MXC_PTEPF3                              */
#define MXC_PTEPF3_E3_MASK                       (0x0FUL << MXC_PTEPF3_E3_SHIFT)                     /*!< MXC_PTEPF3: E3 Mask                     */
#define MXC_PTEPF3_E3_SHIFT                      4                                                   /*!< MXC_PTEPF3: E3 Position                 */
#define MXC_PTEPF3_E3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF3_E3_SHIFT))&MXC_PTEPF3_E3_MASK) /*!< MXC_PTEPF3                              */
/* ------- PTEPF4 Bit Fields                        ------ */
#define MXC_PTEPF4_E0_MASK                       (0x0FUL << MXC_PTEPF4_E0_SHIFT)                     /*!< MXC_PTEPF4: E0 Mask                     */
#define MXC_PTEPF4_E0_SHIFT                      0                                                   /*!< MXC_PTEPF4: E0 Position                 */
#define MXC_PTEPF4_E0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF4_E0_SHIFT))&MXC_PTEPF4_E0_MASK) /*!< MXC_PTEPF4                              */
#define MXC_PTEPF4_E1_MASK                       (0x0FUL << MXC_PTEPF4_E1_SHIFT)                     /*!< MXC_PTEPF4: E1 Mask                     */
#define MXC_PTEPF4_E1_SHIFT                      4                                                   /*!< MXC_PTEPF4: E1 Position                 */
#define MXC_PTEPF4_E1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTEPF4_E1_SHIFT))&MXC_PTEPF4_E1_MASK) /*!< MXC_PTEPF4                              */
/* ------- PTFPF1 Bit Fields                        ------ */
#define MXC_PTFPF1_F6_MASK                       (0x0FUL << MXC_PTFPF1_F6_SHIFT)                     /*!< MXC_PTFPF1: F6 Mask                     */
#define MXC_PTFPF1_F6_SHIFT                      0                                                   /*!< MXC_PTFPF1: F6 Position                 */
#define MXC_PTFPF1_F6(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF1_F6_SHIFT))&MXC_PTFPF1_F6_MASK) /*!< MXC_PTFPF1                              */
#define MXC_PTFPF1_F7_MASK                       (0x0FUL << MXC_PTFPF1_F7_SHIFT)                     /*!< MXC_PTFPF1: F7 Mask                     */
#define MXC_PTFPF1_F7_SHIFT                      4                                                   /*!< MXC_PTFPF1: F7 Position                 */
#define MXC_PTFPF1_F7(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF1_F7_SHIFT))&MXC_PTFPF1_F7_MASK) /*!< MXC_PTFPF1                              */
/* ------- PTFPF2 Bit Fields                        ------ */
#define MXC_PTFPF2_F4_MASK                       (0x0FUL << MXC_PTFPF2_F4_SHIFT)                     /*!< MXC_PTFPF2: F4 Mask                     */
#define MXC_PTFPF2_F4_SHIFT                      0                                                   /*!< MXC_PTFPF2: F4 Position                 */
#define MXC_PTFPF2_F4(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF2_F4_SHIFT))&MXC_PTFPF2_F4_MASK) /*!< MXC_PTFPF2                              */
#define MXC_PTFPF2_F5_MASK                       (0x0FUL << MXC_PTFPF2_F5_SHIFT)                     /*!< MXC_PTFPF2: F5 Mask                     */
#define MXC_PTFPF2_F5_SHIFT                      4                                                   /*!< MXC_PTFPF2: F5 Position                 */
#define MXC_PTFPF2_F5(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF2_F5_SHIFT))&MXC_PTFPF2_F5_MASK) /*!< MXC_PTFPF2                              */
/* ------- PTFPF3 Bit Fields                        ------ */
#define MXC_PTFPF3_F2_MASK                       (0x0FUL << MXC_PTFPF3_F2_SHIFT)                     /*!< MXC_PTFPF3: F2 Mask                     */
#define MXC_PTFPF3_F2_SHIFT                      0                                                   /*!< MXC_PTFPF3: F2 Position                 */
#define MXC_PTFPF3_F2(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF3_F2_SHIFT))&MXC_PTFPF3_F2_MASK) /*!< MXC_PTFPF3                              */
#define MXC_PTFPF3_F3_MASK                       (0x0FUL << MXC_PTFPF3_F3_SHIFT)                     /*!< MXC_PTFPF3: F3 Mask                     */
#define MXC_PTFPF3_F3_SHIFT                      4                                                   /*!< MXC_PTFPF3: F3 Position                 */
#define MXC_PTFPF3_F3(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF3_F3_SHIFT))&MXC_PTFPF3_F3_MASK) /*!< MXC_PTFPF3                              */
/* ------- PTFPF4 Bit Fields                        ------ */
#define MXC_PTFPF4_F0_MASK                       (0x0FUL << MXC_PTFPF4_F0_SHIFT)                     /*!< MXC_PTFPF4: F0 Mask                     */
#define MXC_PTFPF4_F0_SHIFT                      0                                                   /*!< MXC_PTFPF4: F0 Position                 */
#define MXC_PTFPF4_F0(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF4_F0_SHIFT))&MXC_PTFPF4_F0_MASK) /*!< MXC_PTFPF4                              */
#define MXC_PTFPF4_F1_MASK                       (0x0FUL << MXC_PTFPF4_F1_SHIFT)                     /*!< MXC_PTFPF4: F1 Mask                     */
#define MXC_PTFPF4_F1_SHIFT                      4                                                   /*!< MXC_PTFPF4: F1 Position                 */
#define MXC_PTFPF4_F1(x)                         (((uint8_t)(((uint8_t)(x))<<MXC_PTFPF4_F1_SHIFT))&MXC_PTFPF4_F1_MASK) /*!< MXC_PTFPF4                              */
/**
 * @} */ /* End group MXC_Register_Masks_GROUP 
 */

/* MXC - Peripheral instance base addresses */
#define MXC_BasePtr                    0xFFFF8080UL //!< Peripheral base address
#define MXC                            ((MXC_Type *) MXC_BasePtr) //!< Freescale base pointer
#define MXC_BASE_PTR                   (MXC) //!< Freescale style base pointer
/**
 * @} */ /* End group MXC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup OSC_Peripheral_access_layer_GROUP OSC Peripheral Access Layer
* @brief C Struct for OSC
* @{
*/

/* ================================================================================ */
/* ================           OSC1 (file:OSC1_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */
/**
* @addtogroup OSC_structs_GROUP OSC struct
* @brief Struct for OSC
* @{
*/
typedef struct {                                /*       OSC1 Structure                                               */
   __IO uint8_t   CR;                           /**< 0000: Control Register                                             */
   __IO uint8_t   OSC1_TSTCTR;                  /**< 0001: Test Control Register                                        */
} OSC_Type;

/**
 * @} */ /* End group OSC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup OSC_Register_Masks_GROUP OSC Register Masks
* @brief Register Masks for OSC
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define OSC_CR_SC16P_MASK                        (0x01UL << OSC_CR_SC16P_SHIFT)                      /*!< OSC1_CR: SC16P Mask                     */
#define OSC_CR_SC16P_SHIFT                       0                                                   /*!< OSC1_CR: SC16P Position                 */
#define OSC_CR_SC8P_MASK                         (0x01UL << OSC_CR_SC8P_SHIFT)                       /*!< OSC1_CR: SC8P Mask                      */
#define OSC_CR_SC8P_SHIFT                        1                                                   /*!< OSC1_CR: SC8P Position                  */
#define OSC_CR_SC4P_MASK                         (0x01UL << OSC_CR_SC4P_SHIFT)                       /*!< OSC1_CR: SC4P Mask                      */
#define OSC_CR_SC4P_SHIFT                        2                                                   /*!< OSC1_CR: SC4P Position                  */
#define OSC_CR_SC2P_MASK                         (0x01UL << OSC_CR_SC2P_SHIFT)                       /*!< OSC1_CR: SC2P Mask                      */
#define OSC_CR_SC2P_SHIFT                        3                                                   /*!< OSC1_CR: SC2P Position                  */
#define OSC_CR_EREFSTEN_MASK                     (0x01UL << OSC_CR_EREFSTEN_SHIFT)                   /*!< OSC1_CR: EREFSTEN Mask                  */
#define OSC_CR_EREFSTEN_SHIFT                    5                                                   /*!< OSC1_CR: EREFSTEN Position              */
#define OSC_CR_ERCLKEN_MASK                      (0x01UL << OSC_CR_ERCLKEN_SHIFT)                    /*!< OSC1_CR: ERCLKEN Mask                   */
#define OSC_CR_ERCLKEN_SHIFT                     7                                                   /*!< OSC1_CR: ERCLKEN Position               */
/* ------- OSC1_TSTCTR Bit Fields                   ------ */
#define OSC_OSC1_TSTCTR_CMPM_MASK                (0x01UL << OSC_OSC1_TSTCTR_CMPM_SHIFT)              /*!< OSC1_OSC1_TSTCTR: CMPM Mask             */
#define OSC_OSC1_TSTCTR_CMPM_SHIFT               0                                                   /*!< OSC1_OSC1_TSTCTR: CMPM Position         */
#define OSC_OSC1_TSTCTR_ALCTST_MASK              (0x01UL << OSC_OSC1_TSTCTR_ALCTST_SHIFT)            /*!< OSC1_OSC1_TSTCTR: ALCTST Mask           */
#define OSC_OSC1_TSTCTR_ALCTST_SHIFT             1                                                   /*!< OSC1_OSC1_TSTCTR: ALCTST Position       */
#define OSC_OSC1_TSTCTR_TSTEN_MASK               (0x01UL << OSC_OSC1_TSTCTR_TSTEN_SHIFT)             /*!< OSC1_OSC1_TSTCTR: TSTEN Mask            */
#define OSC_OSC1_TSTCTR_TSTEN_SHIFT              2                                                   /*!< OSC1_OSC1_TSTCTR: TSTEN Position        */
#define OSC_OSC1_TSTCTR_OSCEN_MASK               (0x01UL << OSC_OSC1_TSTCTR_OSCEN_SHIFT)             /*!< OSC1_OSC1_TSTCTR: OSCEN Mask            */
#define OSC_OSC1_TSTCTR_OSCEN_SHIFT              3                                                   /*!< OSC1_OSC1_TSTCTR: OSCEN Position        */
/**
 * @} */ /* End group OSC_Register_Masks_GROUP 
 */

/* OSC1 - Peripheral instance base addresses */
#define OSC1_BasePtr                   0xFFFF8120UL //!< Peripheral base address
#define OSC1                           ((OSC_Type *) OSC1_BasePtr) //!< Freescale base pointer
#define OSC1_BASE_PTR                  (OSC1) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup OSC_Peripheral_access_layer_GROUP OSC Peripheral Access Layer
* @brief C Struct for OSC
* @{
*/

/* ================================================================================ */
/* ================           OSC2 (derived from OSC1)             ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */

/* OSC2 - Peripheral instance base addresses */
#define OSC2_BasePtr                   0xFFFF8120UL //!< Peripheral base address
#define OSC2                           ((OSC_Type *) OSC2_BasePtr) //!< Freescale base pointer
#define OSC2_BASE_PTR                  (OSC2) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PCTLA_Peripheral_access_layer_GROUP PCTLA Peripheral Access Layer
* @brief C Struct for PCTLA
* @{
*/

/* ================================================================================ */
/* ================           PCTLA (file:PCTLA_MCF51)             ================ */
/* ================================================================================ */

/**
 * @brief Port Pin Control
 */
/**
* @addtogroup PCTLA_structs_GROUP PCTLA struct
* @brief Struct for PCTLA
* @{
*/
typedef struct {                                /*       PCTLA Structure                                              */
   __IO uint8_t   PUE;                          /**< 0000: Pulling Enable Register                                      */
   __IO uint8_t   PUS;                          /**< 0001: Pullup/Pulldown Select Register                              */
   __IO uint8_t   DS;                           /**< 0002: Drive Strength Enable Register                               */
   __IO uint8_t   SRE;                          /**< 0003: Slew Rate Enable Register                                    */
   __IO uint8_t   PFE;                          /**< 0004: Passive Filter Enable Register                               */
   __IO uint8_t   IC;                           /**< 0005: Interrupt Control Register                                   */
   __IO uint8_t   IPE;                          /**< 0006: Interrupt Pin Enable Register                                */
   __IO uint8_t   IF;                           /**< 0007: Interrupt Flag Register                                      */
   __IO uint8_t   IES;                          /**< 0008: Interrupt Edge Select Register                               */
   __IO uint8_t   DFE;                          /**< 0009: Digital Filter Enable Register                               */
   __IO uint8_t   DFC;                          /**< 000A: Digital Filter Control Register                              */
} PCTL_Type;

/**
 * @} */ /* End group PCTLA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PCTLA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PCTLA_Register_Masks_GROUP PCTLA Register Masks
* @brief Register Masks for PCTLA
* @{
*/
/* ------- PUE Bit Fields                           ------ */
#define PCTL_PUE_PTPUE0_MASK                     (0x01UL << PCTL_PUE_PTPUE0_SHIFT)                   /*!< PCTLA_PUE: PTPUE0 Mask                  */
#define PCTL_PUE_PTPUE0_SHIFT                    0                                                   /*!< PCTLA_PUE: PTPUE0 Position              */
#define PCTL_PUE_PTPUE1_MASK                     (0x01UL << PCTL_PUE_PTPUE1_SHIFT)                   /*!< PCTLA_PUE: PTPUE1 Mask                  */
#define PCTL_PUE_PTPUE1_SHIFT                    1                                                   /*!< PCTLA_PUE: PTPUE1 Position              */
#define PCTL_PUE_PTPUE2_MASK                     (0x01UL << PCTL_PUE_PTPUE2_SHIFT)                   /*!< PCTLA_PUE: PTPUE2 Mask                  */
#define PCTL_PUE_PTPUE2_SHIFT                    2                                                   /*!< PCTLA_PUE: PTPUE2 Position              */
#define PCTL_PUE_PTPUE3_MASK                     (0x01UL << PCTL_PUE_PTPUE3_SHIFT)                   /*!< PCTLA_PUE: PTPUE3 Mask                  */
#define PCTL_PUE_PTPUE3_SHIFT                    3                                                   /*!< PCTLA_PUE: PTPUE3 Position              */
#define PCTL_PUE_PTPUE4_MASK                     (0x01UL << PCTL_PUE_PTPUE4_SHIFT)                   /*!< PCTLA_PUE: PTPUE4 Mask                  */
#define PCTL_PUE_PTPUE4_SHIFT                    4                                                   /*!< PCTLA_PUE: PTPUE4 Position              */
#define PCTL_PUE_PTPUE5_MASK                     (0x01UL << PCTL_PUE_PTPUE5_SHIFT)                   /*!< PCTLA_PUE: PTPUE5 Mask                  */
#define PCTL_PUE_PTPUE5_SHIFT                    5                                                   /*!< PCTLA_PUE: PTPUE5 Position              */
#define PCTL_PUE_PTPUE6_MASK                     (0x01UL << PCTL_PUE_PTPUE6_SHIFT)                   /*!< PCTLA_PUE: PTPUE6 Mask                  */
#define PCTL_PUE_PTPUE6_SHIFT                    6                                                   /*!< PCTLA_PUE: PTPUE6 Position              */
#define PCTL_PUE_PTPUE7_MASK                     (0x01UL << PCTL_PUE_PTPUE7_SHIFT)                   /*!< PCTLA_PUE: PTPUE7 Mask                  */
#define PCTL_PUE_PTPUE7_SHIFT                    7                                                   /*!< PCTLA_PUE: PTPUE7 Position              */
/* ------- PUS Bit Fields                           ------ */
#define PCTL_PUS_PTPUS0_MASK                     (0x01UL << PCTL_PUS_PTPUS0_SHIFT)                   /*!< PCTLA_PUS: PTPUS0 Mask                  */
#define PCTL_PUS_PTPUS0_SHIFT                    0                                                   /*!< PCTLA_PUS: PTPUS0 Position              */
#define PCTL_PUS_PTPUS1_MASK                     (0x01UL << PCTL_PUS_PTPUS1_SHIFT)                   /*!< PCTLA_PUS: PTPUS1 Mask                  */
#define PCTL_PUS_PTPUS1_SHIFT                    1                                                   /*!< PCTLA_PUS: PTPUS1 Position              */
#define PCTL_PUS_PTPUS2_MASK                     (0x01UL << PCTL_PUS_PTPUS2_SHIFT)                   /*!< PCTLA_PUS: PTPUS2 Mask                  */
#define PCTL_PUS_PTPUS2_SHIFT                    2                                                   /*!< PCTLA_PUS: PTPUS2 Position              */
#define PCTL_PUS_PTPUS3_MASK                     (0x01UL << PCTL_PUS_PTPUS3_SHIFT)                   /*!< PCTLA_PUS: PTPUS3 Mask                  */
#define PCTL_PUS_PTPUS3_SHIFT                    3                                                   /*!< PCTLA_PUS: PTPUS3 Position              */
#define PCTL_PUS_PTPUS4_MASK                     (0x01UL << PCTL_PUS_PTPUS4_SHIFT)                   /*!< PCTLA_PUS: PTPUS4 Mask                  */
#define PCTL_PUS_PTPUS4_SHIFT                    4                                                   /*!< PCTLA_PUS: PTPUS4 Position              */
#define PCTL_PUS_PTPUS5_MASK                     (0x01UL << PCTL_PUS_PTPUS5_SHIFT)                   /*!< PCTLA_PUS: PTPUS5 Mask                  */
#define PCTL_PUS_PTPUS5_SHIFT                    5                                                   /*!< PCTLA_PUS: PTPUS5 Position              */
#define PCTL_PUS_PTPUS6_MASK                     (0x01UL << PCTL_PUS_PTPUS6_SHIFT)                   /*!< PCTLA_PUS: PTPUS6 Mask                  */
#define PCTL_PUS_PTPUS6_SHIFT                    6                                                   /*!< PCTLA_PUS: PTPUS6 Position              */
#define PCTL_PUS_PTPUS7_MASK                     (0x01UL << PCTL_PUS_PTPUS7_SHIFT)                   /*!< PCTLA_PUS: PTPUS7 Mask                  */
#define PCTL_PUS_PTPUS7_SHIFT                    7                                                   /*!< PCTLA_PUS: PTPUS7 Position              */
/* ------- DS Bit Fields                            ------ */
#define PCTL_DS_PTDSS0_MASK                      (0x01UL << PCTL_DS_PTDSS0_SHIFT)                    /*!< PCTLA_DS: PTDSS0 Mask                   */
#define PCTL_DS_PTDSS0_SHIFT                     0                                                   /*!< PCTLA_DS: PTDSS0 Position               */
#define PCTL_DS_PTDSS1_MASK                      (0x01UL << PCTL_DS_PTDSS1_SHIFT)                    /*!< PCTLA_DS: PTDSS1 Mask                   */
#define PCTL_DS_PTDSS1_SHIFT                     1                                                   /*!< PCTLA_DS: PTDSS1 Position               */
#define PCTL_DS_PTDSS2_MASK                      (0x01UL << PCTL_DS_PTDSS2_SHIFT)                    /*!< PCTLA_DS: PTDSS2 Mask                   */
#define PCTL_DS_PTDSS2_SHIFT                     2                                                   /*!< PCTLA_DS: PTDSS2 Position               */
#define PCTL_DS_PTDSS3_MASK                      (0x01UL << PCTL_DS_PTDSS3_SHIFT)                    /*!< PCTLA_DS: PTDSS3 Mask                   */
#define PCTL_DS_PTDSS3_SHIFT                     3                                                   /*!< PCTLA_DS: PTDSS3 Position               */
#define PCTL_DS_PTDSS4_MASK                      (0x01UL << PCTL_DS_PTDSS4_SHIFT)                    /*!< PCTLA_DS: PTDSS4 Mask                   */
#define PCTL_DS_PTDSS4_SHIFT                     4                                                   /*!< PCTLA_DS: PTDSS4 Position               */
#define PCTL_DS_PTDSS5_MASK                      (0x01UL << PCTL_DS_PTDSS5_SHIFT)                    /*!< PCTLA_DS: PTDSS5 Mask                   */
#define PCTL_DS_PTDSS5_SHIFT                     5                                                   /*!< PCTLA_DS: PTDSS5 Position               */
#define PCTL_DS_PTDSS6_MASK                      (0x01UL << PCTL_DS_PTDSS6_SHIFT)                    /*!< PCTLA_DS: PTDSS6 Mask                   */
#define PCTL_DS_PTDSS6_SHIFT                     6                                                   /*!< PCTLA_DS: PTDSS6 Position               */
#define PCTL_DS_PTDSS7_MASK                      (0x01UL << PCTL_DS_PTDSS7_SHIFT)                    /*!< PCTLA_DS: PTDSS7 Mask                   */
#define PCTL_DS_PTDSS7_SHIFT                     7                                                   /*!< PCTLA_DS: PTDSS7 Position               */
/* ------- SRE Bit Fields                           ------ */
#define PCTL_SRE_PTSRE0_MASK                     (0x01UL << PCTL_SRE_PTSRE0_SHIFT)                   /*!< PCTLA_SRE: PTSRE0 Mask                  */
#define PCTL_SRE_PTSRE0_SHIFT                    0                                                   /*!< PCTLA_SRE: PTSRE0 Position              */
#define PCTL_SRE_PTSRE1_MASK                     (0x01UL << PCTL_SRE_PTSRE1_SHIFT)                   /*!< PCTLA_SRE: PTSRE1 Mask                  */
#define PCTL_SRE_PTSRE1_SHIFT                    1                                                   /*!< PCTLA_SRE: PTSRE1 Position              */
#define PCTL_SRE_PTSRE2_MASK                     (0x01UL << PCTL_SRE_PTSRE2_SHIFT)                   /*!< PCTLA_SRE: PTSRE2 Mask                  */
#define PCTL_SRE_PTSRE2_SHIFT                    2                                                   /*!< PCTLA_SRE: PTSRE2 Position              */
#define PCTL_SRE_PTSRE3_MASK                     (0x01UL << PCTL_SRE_PTSRE3_SHIFT)                   /*!< PCTLA_SRE: PTSRE3 Mask                  */
#define PCTL_SRE_PTSRE3_SHIFT                    3                                                   /*!< PCTLA_SRE: PTSRE3 Position              */
#define PCTL_SRE_PTSRE4_MASK                     (0x01UL << PCTL_SRE_PTSRE4_SHIFT)                   /*!< PCTLA_SRE: PTSRE4 Mask                  */
#define PCTL_SRE_PTSRE4_SHIFT                    4                                                   /*!< PCTLA_SRE: PTSRE4 Position              */
#define PCTL_SRE_PTSRE5_MASK                     (0x01UL << PCTL_SRE_PTSRE5_SHIFT)                   /*!< PCTLA_SRE: PTSRE5 Mask                  */
#define PCTL_SRE_PTSRE5_SHIFT                    5                                                   /*!< PCTLA_SRE: PTSRE5 Position              */
#define PCTL_SRE_PTSRE6_MASK                     (0x01UL << PCTL_SRE_PTSRE6_SHIFT)                   /*!< PCTLA_SRE: PTSRE6 Mask                  */
#define PCTL_SRE_PTSRE6_SHIFT                    6                                                   /*!< PCTLA_SRE: PTSRE6 Position              */
#define PCTL_SRE_PTSRE7_MASK                     (0x01UL << PCTL_SRE_PTSRE7_SHIFT)                   /*!< PCTLA_SRE: PTSRE7 Mask                  */
#define PCTL_SRE_PTSRE7_SHIFT                    7                                                   /*!< PCTLA_SRE: PTSRE7 Position              */
/* ------- PFE Bit Fields                           ------ */
#define PCTL_PFE_PTPFE0_MASK                     (0x01UL << PCTL_PFE_PTPFE0_SHIFT)                   /*!< PCTLA_PFE: PTPFE0 Mask                  */
#define PCTL_PFE_PTPFE0_SHIFT                    0                                                   /*!< PCTLA_PFE: PTPFE0 Position              */
#define PCTL_PFE_PTPFE1_MASK                     (0x01UL << PCTL_PFE_PTPFE1_SHIFT)                   /*!< PCTLA_PFE: PTPFE1 Mask                  */
#define PCTL_PFE_PTPFE1_SHIFT                    1                                                   /*!< PCTLA_PFE: PTPFE1 Position              */
#define PCTL_PFE_PTPFE2_MASK                     (0x01UL << PCTL_PFE_PTPFE2_SHIFT)                   /*!< PCTLA_PFE: PTPFE2 Mask                  */
#define PCTL_PFE_PTPFE2_SHIFT                    2                                                   /*!< PCTLA_PFE: PTPFE2 Position              */
#define PCTL_PFE_PTPFE3_MASK                     (0x01UL << PCTL_PFE_PTPFE3_SHIFT)                   /*!< PCTLA_PFE: PTPFE3 Mask                  */
#define PCTL_PFE_PTPFE3_SHIFT                    3                                                   /*!< PCTLA_PFE: PTPFE3 Position              */
#define PCTL_PFE_PTPFE4_MASK                     (0x01UL << PCTL_PFE_PTPFE4_SHIFT)                   /*!< PCTLA_PFE: PTPFE4 Mask                  */
#define PCTL_PFE_PTPFE4_SHIFT                    4                                                   /*!< PCTLA_PFE: PTPFE4 Position              */
#define PCTL_PFE_PTPFE5_MASK                     (0x01UL << PCTL_PFE_PTPFE5_SHIFT)                   /*!< PCTLA_PFE: PTPFE5 Mask                  */
#define PCTL_PFE_PTPFE5_SHIFT                    5                                                   /*!< PCTLA_PFE: PTPFE5 Position              */
#define PCTL_PFE_PTPFE6_MASK                     (0x01UL << PCTL_PFE_PTPFE6_SHIFT)                   /*!< PCTLA_PFE: PTPFE6 Mask                  */
#define PCTL_PFE_PTPFE6_SHIFT                    6                                                   /*!< PCTLA_PFE: PTPFE6 Position              */
#define PCTL_PFE_PTPFE7_MASK                     (0x01UL << PCTL_PFE_PTPFE7_SHIFT)                   /*!< PCTLA_PFE: PTPFE7 Mask                  */
#define PCTL_PFE_PTPFE7_SHIFT                    7                                                   /*!< PCTLA_PFE: PTPFE7 Position              */
/* ------- IC Bit Fields                            ------ */
#define PCTL_IC_PTMOD_MASK                       (0x01UL << PCTL_IC_PTMOD_SHIFT)                     /*!< PCTLA_IC: PTMOD Mask                    */
#define PCTL_IC_PTMOD_SHIFT                      0                                                   /*!< PCTLA_IC: PTMOD Position                */
#define PCTL_IC_PTIE_MASK                        (0x01UL << PCTL_IC_PTIE_SHIFT)                      /*!< PCTLA_IC: PTIE Mask                     */
#define PCTL_IC_PTIE_SHIFT                       1                                                   /*!< PCTLA_IC: PTIE Position                 */
#define PCTL_IC_PTDMAEN_MASK                     (0x01UL << PCTL_IC_PTDMAEN_SHIFT)                   /*!< PCTLA_IC: PTDMAEN Mask                  */
#define PCTL_IC_PTDMAEN_SHIFT                    7                                                   /*!< PCTLA_IC: PTDMAEN Position              */
/* ------- IPE Bit Fields                           ------ */
#define PCTL_IPE_PTIPE0_MASK                     (0x01UL << PCTL_IPE_PTIPE0_SHIFT)                   /*!< PCTLA_IPE: PTIPE0 Mask                  */
#define PCTL_IPE_PTIPE0_SHIFT                    0                                                   /*!< PCTLA_IPE: PTIPE0 Position              */
#define PCTL_IPE_PTIPE1_MASK                     (0x01UL << PCTL_IPE_PTIPE1_SHIFT)                   /*!< PCTLA_IPE: PTIPE1 Mask                  */
#define PCTL_IPE_PTIPE1_SHIFT                    1                                                   /*!< PCTLA_IPE: PTIPE1 Position              */
#define PCTL_IPE_PTIPE2_MASK                     (0x01UL << PCTL_IPE_PTIPE2_SHIFT)                   /*!< PCTLA_IPE: PTIPE2 Mask                  */
#define PCTL_IPE_PTIPE2_SHIFT                    2                                                   /*!< PCTLA_IPE: PTIPE2 Position              */
#define PCTL_IPE_PTIPE3_MASK                     (0x01UL << PCTL_IPE_PTIPE3_SHIFT)                   /*!< PCTLA_IPE: PTIPE3 Mask                  */
#define PCTL_IPE_PTIPE3_SHIFT                    3                                                   /*!< PCTLA_IPE: PTIPE3 Position              */
#define PCTL_IPE_PTIPE4_MASK                     (0x01UL << PCTL_IPE_PTIPE4_SHIFT)                   /*!< PCTLA_IPE: PTIPE4 Mask                  */
#define PCTL_IPE_PTIPE4_SHIFT                    4                                                   /*!< PCTLA_IPE: PTIPE4 Position              */
#define PCTL_IPE_PTIPE5_MASK                     (0x01UL << PCTL_IPE_PTIPE5_SHIFT)                   /*!< PCTLA_IPE: PTIPE5 Mask                  */
#define PCTL_IPE_PTIPE5_SHIFT                    5                                                   /*!< PCTLA_IPE: PTIPE5 Position              */
#define PCTL_IPE_PTIPE6_MASK                     (0x01UL << PCTL_IPE_PTIPE6_SHIFT)                   /*!< PCTLA_IPE: PTIPE6 Mask                  */
#define PCTL_IPE_PTIPE6_SHIFT                    6                                                   /*!< PCTLA_IPE: PTIPE6 Position              */
#define PCTL_IPE_PTIPE7_MASK                     (0x01UL << PCTL_IPE_PTIPE7_SHIFT)                   /*!< PCTLA_IPE: PTIPE7 Mask                  */
#define PCTL_IPE_PTIPE7_SHIFT                    7                                                   /*!< PCTLA_IPE: PTIPE7 Position              */
/* ------- IF Bit Fields                            ------ */
#define PCTL_IF_PTIF0_MASK                       (0x01UL << PCTL_IF_PTIF0_SHIFT)                     /*!< PCTLA_IF: PTIF0 Mask                    */
#define PCTL_IF_PTIF0_SHIFT                      0                                                   /*!< PCTLA_IF: PTIF0 Position                */
#define PCTL_IF_PTIF1_MASK                       (0x01UL << PCTL_IF_PTIF1_SHIFT)                     /*!< PCTLA_IF: PTIF1 Mask                    */
#define PCTL_IF_PTIF1_SHIFT                      1                                                   /*!< PCTLA_IF: PTIF1 Position                */
#define PCTL_IF_PTIF2_MASK                       (0x01UL << PCTL_IF_PTIF2_SHIFT)                     /*!< PCTLA_IF: PTIF2 Mask                    */
#define PCTL_IF_PTIF2_SHIFT                      2                                                   /*!< PCTLA_IF: PTIF2 Position                */
#define PCTL_IF_PTIF3_MASK                       (0x01UL << PCTL_IF_PTIF3_SHIFT)                     /*!< PCTLA_IF: PTIF3 Mask                    */
#define PCTL_IF_PTIF3_SHIFT                      3                                                   /*!< PCTLA_IF: PTIF3 Position                */
#define PCTL_IF_PTIF4_MASK                       (0x01UL << PCTL_IF_PTIF4_SHIFT)                     /*!< PCTLA_IF: PTIF4 Mask                    */
#define PCTL_IF_PTIF4_SHIFT                      4                                                   /*!< PCTLA_IF: PTIF4 Position                */
#define PCTL_IF_PTIF5_MASK                       (0x01UL << PCTL_IF_PTIF5_SHIFT)                     /*!< PCTLA_IF: PTIF5 Mask                    */
#define PCTL_IF_PTIF5_SHIFT                      5                                                   /*!< PCTLA_IF: PTIF5 Position                */
#define PCTL_IF_PTIF6_MASK                       (0x01UL << PCTL_IF_PTIF6_SHIFT)                     /*!< PCTLA_IF: PTIF6 Mask                    */
#define PCTL_IF_PTIF6_SHIFT                      6                                                   /*!< PCTLA_IF: PTIF6 Position                */
#define PCTL_IF_PTIF7_MASK                       (0x01UL << PCTL_IF_PTIF7_SHIFT)                     /*!< PCTLA_IF: PTIF7 Mask                    */
#define PCTL_IF_PTIF7_SHIFT                      7                                                   /*!< PCTLA_IF: PTIF7 Position                */
/* ------- IES Bit Fields                           ------ */
#define PCTL_IES_PTEDG0_MASK                     (0x01UL << PCTL_IES_PTEDG0_SHIFT)                   /*!< PCTLA_IES: PTEDG0 Mask                  */
#define PCTL_IES_PTEDG0_SHIFT                    0                                                   /*!< PCTLA_IES: PTEDG0 Position              */
#define PCTL_IES_PTEDG1_MASK                     (0x01UL << PCTL_IES_PTEDG1_SHIFT)                   /*!< PCTLA_IES: PTEDG1 Mask                  */
#define PCTL_IES_PTEDG1_SHIFT                    1                                                   /*!< PCTLA_IES: PTEDG1 Position              */
#define PCTL_IES_PTEDG2_MASK                     (0x01UL << PCTL_IES_PTEDG2_SHIFT)                   /*!< PCTLA_IES: PTEDG2 Mask                  */
#define PCTL_IES_PTEDG2_SHIFT                    2                                                   /*!< PCTLA_IES: PTEDG2 Position              */
#define PCTL_IES_PTEDG3_MASK                     (0x01UL << PCTL_IES_PTEDG3_SHIFT)                   /*!< PCTLA_IES: PTEDG3 Mask                  */
#define PCTL_IES_PTEDG3_SHIFT                    3                                                   /*!< PCTLA_IES: PTEDG3 Position              */
#define PCTL_IES_PTEDG4_MASK                     (0x01UL << PCTL_IES_PTEDG4_SHIFT)                   /*!< PCTLA_IES: PTEDG4 Mask                  */
#define PCTL_IES_PTEDG4_SHIFT                    4                                                   /*!< PCTLA_IES: PTEDG4 Position              */
#define PCTL_IES_PTEDG5_MASK                     (0x01UL << PCTL_IES_PTEDG5_SHIFT)                   /*!< PCTLA_IES: PTEDG5 Mask                  */
#define PCTL_IES_PTEDG5_SHIFT                    5                                                   /*!< PCTLA_IES: PTEDG5 Position              */
#define PCTL_IES_PTEDG6_MASK                     (0x01UL << PCTL_IES_PTEDG6_SHIFT)                   /*!< PCTLA_IES: PTEDG6 Mask                  */
#define PCTL_IES_PTEDG6_SHIFT                    6                                                   /*!< PCTLA_IES: PTEDG6 Position              */
#define PCTL_IES_PTEDG7_MASK                     (0x01UL << PCTL_IES_PTEDG7_SHIFT)                   /*!< PCTLA_IES: PTEDG7 Mask                  */
#define PCTL_IES_PTEDG7_SHIFT                    7                                                   /*!< PCTLA_IES: PTEDG7 Position              */
/* ------- DFE Bit Fields                           ------ */
#define PCTL_DFE_PTDFE0_MASK                     (0x01UL << PCTL_DFE_PTDFE0_SHIFT)                   /*!< PCTLA_DFE: PTDFE0 Mask                  */
#define PCTL_DFE_PTDFE0_SHIFT                    0                                                   /*!< PCTLA_DFE: PTDFE0 Position              */
#define PCTL_DFE_PTDFE1_MASK                     (0x01UL << PCTL_DFE_PTDFE1_SHIFT)                   /*!< PCTLA_DFE: PTDFE1 Mask                  */
#define PCTL_DFE_PTDFE1_SHIFT                    1                                                   /*!< PCTLA_DFE: PTDFE1 Position              */
#define PCTL_DFE_PTDFE2_MASK                     (0x01UL << PCTL_DFE_PTDFE2_SHIFT)                   /*!< PCTLA_DFE: PTDFE2 Mask                  */
#define PCTL_DFE_PTDFE2_SHIFT                    2                                                   /*!< PCTLA_DFE: PTDFE2 Position              */
#define PCTL_DFE_PTDFE3_MASK                     (0x01UL << PCTL_DFE_PTDFE3_SHIFT)                   /*!< PCTLA_DFE: PTDFE3 Mask                  */
#define PCTL_DFE_PTDFE3_SHIFT                    3                                                   /*!< PCTLA_DFE: PTDFE3 Position              */
#define PCTL_DFE_PTDFE4_MASK                     (0x01UL << PCTL_DFE_PTDFE4_SHIFT)                   /*!< PCTLA_DFE: PTDFE4 Mask                  */
#define PCTL_DFE_PTDFE4_SHIFT                    4                                                   /*!< PCTLA_DFE: PTDFE4 Position              */
#define PCTL_DFE_PTDFE5_MASK                     (0x01UL << PCTL_DFE_PTDFE5_SHIFT)                   /*!< PCTLA_DFE: PTDFE5 Mask                  */
#define PCTL_DFE_PTDFE5_SHIFT                    5                                                   /*!< PCTLA_DFE: PTDFE5 Position              */
#define PCTL_DFE_PTDFE6_MASK                     (0x01UL << PCTL_DFE_PTDFE6_SHIFT)                   /*!< PCTLA_DFE: PTDFE6 Mask                  */
#define PCTL_DFE_PTDFE6_SHIFT                    6                                                   /*!< PCTLA_DFE: PTDFE6 Position              */
#define PCTL_DFE_PTDFE7_MASK                     (0x01UL << PCTL_DFE_PTDFE7_SHIFT)                   /*!< PCTLA_DFE: PTDFE7 Mask                  */
#define PCTL_DFE_PTDFE7_SHIFT                    7                                                   /*!< PCTLA_DFE: PTDFE7 Position              */
/* ------- DFC Bit Fields                           ------ */
#define PCTL_DFC_PTFF_MASK                       (0x1FUL << PCTL_DFC_PTFF_SHIFT)                     /*!< PCTLA_DFC: PTFF Mask                    */
#define PCTL_DFC_PTFF_SHIFT                      0                                                   /*!< PCTLA_DFC: PTFF Position                */
#define PCTL_DFC_PTFF(x)                         (((uint8_t)(((uint8_t)(x))<<PCTL_DFC_PTFF_SHIFT))&PCTL_DFC_PTFF_MASK) /*!< PCTLA_DFC                               */
#define PCTL_DFC_PTCLKS_MASK                     (0x01UL << PCTL_DFC_PTCLKS_SHIFT)                   /*!< PCTLA_DFC: PTCLKS Mask                  */
#define PCTL_DFC_PTCLKS_SHIFT                    7                                                   /*!< PCTLA_DFC: PTCLKS Position              */
/**
 * @} */ /* End group PCTLA_Register_Masks_GROUP 
 */

/* PCTLA - Peripheral instance base addresses */
#define PCTLA_BasePtr                  0xFFFF9200UL //!< Peripheral base address
#define PCTLA                          ((PCTL_Type *) PCTLA_BasePtr) //!< Freescale base pointer
#define PCTLA_BASE_PTR                 (PCTLA) //!< Freescale style base pointer
/**
 * @} */ /* End group PCTLA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PCTLA_Peripheral_access_layer_GROUP PCTLA Peripheral Access Layer
* @brief C Struct for PCTLA
* @{
*/

/* ================================================================================ */
/* ================           PCTLB (derived from PCTLA)           ================ */
/* ================================================================================ */

/**
 * @brief Port Pin Control
 */

/* PCTLB - Peripheral instance base addresses */
#define PCTLB_BasePtr                  0xFFFF9210UL //!< Peripheral base address
#define PCTLB                          ((PCTL_Type *) PCTLB_BasePtr) //!< Freescale base pointer
#define PCTLB_BASE_PTR                 (PCTLB) //!< Freescale style base pointer
/**
 * @} */ /* End group PCTLA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PCTLA_Peripheral_access_layer_GROUP PCTLA Peripheral Access Layer
* @brief C Struct for PCTLA
* @{
*/

/* ================================================================================ */
/* ================           PCTLC (derived from PCTLA)           ================ */
/* ================================================================================ */

/**
 * @brief Port Pin Control
 */

/* PCTLC - Peripheral instance base addresses */
#define PCTLC_BasePtr                  0xFFFF9220UL //!< Peripheral base address
#define PCTLC                          ((PCTL_Type *) PCTLC_BasePtr) //!< Freescale base pointer
#define PCTLC_BASE_PTR                 (PCTLC) //!< Freescale style base pointer
/**
 * @} */ /* End group PCTLA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PCTLA_Peripheral_access_layer_GROUP PCTLA Peripheral Access Layer
* @brief C Struct for PCTLA
* @{
*/

/* ================================================================================ */
/* ================           PCTLD (derived from PCTLA)           ================ */
/* ================================================================================ */

/**
 * @brief Port Pin Control
 */

/* PCTLD - Peripheral instance base addresses */
#define PCTLD_BasePtr                  0xFFFF9230UL //!< Peripheral base address
#define PCTLD                          ((PCTL_Type *) PCTLD_BasePtr) //!< Freescale base pointer
#define PCTLD_BASE_PTR                 (PCTLD) //!< Freescale style base pointer
/**
 * @} */ /* End group PCTLA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PCTLA_Peripheral_access_layer_GROUP PCTLA Peripheral Access Layer
* @brief C Struct for PCTLA
* @{
*/

/* ================================================================================ */
/* ================           PCTLE (derived from PCTLA)           ================ */
/* ================================================================================ */

/**
 * @brief Port Pin Control
 */

/* PCTLE - Peripheral instance base addresses */
#define PCTLE_BasePtr                  0xFFFF9240UL //!< Peripheral base address
#define PCTLE                          ((PCTL_Type *) PCTLE_BasePtr) //!< Freescale base pointer
#define PCTLE_BASE_PTR                 (PCTLE) //!< Freescale style base pointer
/**
 * @} */ /* End group PCTLA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PCTLA_Peripheral_access_layer_GROUP PCTLA Peripheral Access Layer
* @brief C Struct for PCTLA
* @{
*/

/* ================================================================================ */
/* ================           PCTLF (derived from PCTLA)           ================ */
/* ================================================================================ */

/**
 * @brief Port Pin Control
 */

/* PCTLF - Peripheral instance base addresses */
#define PCTLF_BasePtr                  0xFFFF9250UL //!< Peripheral base address
#define PCTLF                          ((PCTL_Type *) PCTLF_BasePtr) //!< Freescale base pointer
#define PCTLF_BASE_PTR                 (PCTLF) //!< Freescale style base pointer
/**
 * @} */ /* End group PCTLA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB0 (file:PDB0_MCF51_1CH_2TRIG_1PO)       ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (1 channels, 2 trigger, 1 pulse outputs)
 */
/**
* @addtogroup PDB_structs_GROUP PDB struct
* @brief Struct for PDB
* @{
*/
typedef struct {                                /*       PDB0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control Register                                  */
   __IO uint32_t  MOD;                          /**< 0004: Modulus Register                                             */
   __I  uint32_t  CNT;                          /**< 0008: Counter Register                                             */
   __IO uint32_t  IDLY;                         /**< 000C: Interrupt Delay Register                                     */
   struct {
      __IO uint32_t  C1;                        /**< 0010: Channel  Control Register 1                                  */
      __IO uint32_t  S;                         /**< 0014: Channel  Status Register                                     */
      __IO uint32_t  DLY[2];                    /**< 0018: Channel n Delay  Register                                    */
   } CH[1];                                     /**< 0010: (cluster: size=0x0010, 16)                                   */
   struct {
      __IO uint32_t  INTC;                      /**< 0020: DAC Interval Trigger n Control Register                      */
      __IO uint32_t  INT;                       /**< 0024: DAC Interval n Register                                      */
   } DAC[1];                                    /**< 0020: (cluster: size=0x0008, 8)                                    */
   __IO uint32_t  POEN;                         /**< 0028: Pulse-Out Enable Register                                    */
   __IO uint32_t  PODLY[1];                     /**< 002C: Pulse-Out  Delay Register                                    */
} PDB_Type;

/**
 * @} */ /* End group PDB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PDB0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PDB_Register_Masks_GROUP PDB Register Masks
* @brief Register Masks for PDB
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define PDB_SC_LDOK_MASK                         (0x01UL << PDB_SC_LDOK_SHIFT)                       /*!< PDB0_SC: LDOK Mask                      */
#define PDB_SC_LDOK_SHIFT                        0                                                   /*!< PDB0_SC: LDOK Position                  */
#define PDB_SC_CONT_MASK                         (0x01UL << PDB_SC_CONT_SHIFT)                       /*!< PDB0_SC: CONT Mask                      */
#define PDB_SC_CONT_SHIFT                        1                                                   /*!< PDB0_SC: CONT Position                  */
#define PDB_SC_MULT_MASK                         (0x03UL << PDB_SC_MULT_SHIFT)                       /*!< PDB0_SC: MULT Mask                      */
#define PDB_SC_MULT_SHIFT                        2                                                   /*!< PDB0_SC: MULT Position                  */
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBIE_MASK                        (0x01UL << PDB_SC_PDBIE_SHIFT)                      /*!< PDB0_SC: PDBIE Mask                     */
#define PDB_SC_PDBIE_SHIFT                       5                                                   /*!< PDB0_SC: PDBIE Position                 */
#define PDB_SC_PDBIF_MASK                        (0x01UL << PDB_SC_PDBIF_SHIFT)                      /*!< PDB0_SC: PDBIF Mask                     */
#define PDB_SC_PDBIF_SHIFT                       6                                                   /*!< PDB0_SC: PDBIF Position                 */
#define PDB_SC_PDBEN_MASK                        (0x01UL << PDB_SC_PDBEN_SHIFT)                      /*!< PDB0_SC: PDBEN Mask                     */
#define PDB_SC_PDBEN_SHIFT                       7                                                   /*!< PDB0_SC: PDBEN Position                 */
#define PDB_SC_TRGSEL_MASK                       (0x0FUL << PDB_SC_TRGSEL_SHIFT)                     /*!< PDB0_SC: TRGSEL Mask                    */
#define PDB_SC_TRGSEL_SHIFT                      8                                                   /*!< PDB0_SC: TRGSEL Position                */
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PRESCALER_MASK                    (0x07UL << PDB_SC_PRESCALER_SHIFT)                  /*!< PDB0_SC: PRESCALER Mask                 */
#define PDB_SC_PRESCALER_SHIFT                   12                                                  /*!< PDB0_SC: PRESCALER Position             */
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_DMAEN_MASK                        (0x01UL << PDB_SC_DMAEN_SHIFT)                      /*!< PDB0_SC: DMAEN Mask                     */
#define PDB_SC_DMAEN_SHIFT                       15                                                  /*!< PDB0_SC: DMAEN Position                 */
#define PDB_SC_SWTRIG_MASK                       (0x01UL << PDB_SC_SWTRIG_SHIFT)                     /*!< PDB0_SC: SWTRIG Mask                    */
#define PDB_SC_SWTRIG_SHIFT                      16                                                  /*!< PDB0_SC: SWTRIG Position                */
#define PDB_SC_PDBEIE_MASK                       (0x01UL << PDB_SC_PDBEIE_SHIFT)                     /*!< PDB0_SC: PDBEIE Mask                    */
#define PDB_SC_PDBEIE_SHIFT                      17                                                  /*!< PDB0_SC: PDBEIE Position                */
#define PDB_SC_LDMOD_MASK                        (0x03UL << PDB_SC_LDMOD_SHIFT)                      /*!< PDB0_SC: LDMOD Mask                     */
#define PDB_SC_LDMOD_SHIFT                       18                                                  /*!< PDB0_SC: LDMOD Position                 */
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK) /*!< PDB0_SC                                 */
/* ------- MOD Bit Fields                           ------ */
#define PDB_MOD_MOD_MASK                         (0xFFFFUL << PDB_MOD_MOD_SHIFT)                     /*!< PDB0_MOD: MOD Mask                      */
#define PDB_MOD_MOD_SHIFT                        0                                                   /*!< PDB0_MOD: MOD Position                  */
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK) /*!< PDB0_MOD                                */
/* ------- CNT Bit Fields                           ------ */
#define PDB_CNT_CNT_MASK                         (0xFFFFUL << PDB_CNT_CNT_SHIFT)                     /*!< PDB0_CNT: CNT Mask                      */
#define PDB_CNT_CNT_SHIFT                        0                                                   /*!< PDB0_CNT: CNT Position                  */
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK) /*!< PDB0_CNT                                */
/* ------- IDLY Bit Fields                          ------ */
#define PDB_IDLY_IDLY_MASK                       (0xFFFFUL << PDB_IDLY_IDLY_SHIFT)                   /*!< PDB0_IDLY: IDLY Mask                    */
#define PDB_IDLY_IDLY_SHIFT                      0                                                   /*!< PDB0_IDLY: IDLY Position                */
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK) /*!< PDB0_IDLY                               */
/* ------- C1 Bit Fields                            ------ */
#define PDB_C1_EN_MASK                           (0xFFUL << PDB_C1_EN_SHIFT)                         /*!< PDB0_C1: EN Mask                        */
#define PDB_C1_EN_SHIFT                          0                                                   /*!< PDB0_C1: EN Position                    */
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK) /*!< PDB0_C1                                 */
#define PDB_C1_TOS_MASK                          (0xFFUL << PDB_C1_TOS_SHIFT)                        /*!< PDB0_C1: TOS Mask                       */
#define PDB_C1_TOS_SHIFT                         8                                                   /*!< PDB0_C1: TOS Position                   */
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK) /*!< PDB0_C1                                 */
#define PDB_C1_BB_MASK                           (0xFFUL << PDB_C1_BB_SHIFT)                         /*!< PDB0_C1: BB Mask                        */
#define PDB_C1_BB_SHIFT                          16                                                  /*!< PDB0_C1: BB Position                    */
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_BB_SHIFT))&PDB_C1_BB_MASK) /*!< PDB0_C1                                 */
/* ------- S Bit Fields                             ------ */
#define PDB_S_ERR_MASK                           (0xFFUL << PDB_S_ERR_SHIFT)                         /*!< PDB0_S: ERR Mask                        */
#define PDB_S_ERR_SHIFT                          0                                                   /*!< PDB0_S: ERR Position                    */
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK) /*!< PDB0_S                                  */
#define PDB_S_CF_MASK                            (0xFFUL << PDB_S_CF_SHIFT)                          /*!< PDB0_S: CF Mask                         */
#define PDB_S_CF_SHIFT                           16                                                  /*!< PDB0_S: CF Position                     */
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK) /*!< PDB0_S                                  */
/* ------- DLY Bit Fields                           ------ */
#define PDB_DLY_DLY_MASK                         (0xFFFFUL << PDB_DLY_DLY_SHIFT)                     /*!< PDB0_DLY: DLY Mask                      */
#define PDB_DLY_DLY_SHIFT                        0                                                   /*!< PDB0_DLY: DLY Position                  */
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK) /*!< PDB0_DLY                                */
/* ------- INTC Bit Fields                          ------ */
#define PDB_INTC_TOE_MASK                        (0x01UL << PDB_INTC_TOE_SHIFT)                      /*!< PDB0_INTC: TOE Mask                     */
#define PDB_INTC_TOE_SHIFT                       0                                                   /*!< PDB0_INTC: TOE Position                 */
#define PDB_INTC_EXT_MASK                        (0x01UL << PDB_INTC_EXT_SHIFT)                      /*!< PDB0_INTC: EXT Mask                     */
#define PDB_INTC_EXT_SHIFT                       1                                                   /*!< PDB0_INTC: EXT Position                 */
/* ------- INT Bit Fields                           ------ */
#define PDB_INT_INT_MASK                         (0xFFFFUL << PDB_INT_INT_SHIFT)                     /*!< PDB0_INT: INT Mask                      */
#define PDB_INT_INT_SHIFT                        0                                                   /*!< PDB0_INT: INT Position                  */
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_INT_INT_SHIFT))&PDB_INT_INT_MASK) /*!< PDB0_INT                                */
/* ------- POEN Bit Fields                          ------ */
#define PDB_POEN_POEN_MASK                       (0xFFUL << PDB_POEN_POEN_SHIFT)                     /*!< PDB0_POEN: POEN Mask                    */
#define PDB_POEN_POEN_SHIFT                      0                                                   /*!< PDB0_POEN: POEN Position                */
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_POEN_POEN_SHIFT))&PDB_POEN_POEN_MASK) /*!< PDB0_POEN                               */
/* ------- PODLY Bit Fields                         ------ */
#define PDB_PODLY_DLY2_MASK                      (0xFFFFUL << PDB_PODLY_DLY2_SHIFT)                  /*!< PDB0_PODLY: DLY2 Mask                   */
#define PDB_PODLY_DLY2_SHIFT                     0                                                   /*!< PDB0_PODLY: DLY2 Position               */
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY2_SHIFT))&PDB_PODLY_DLY2_MASK) /*!< PDB0_PODLY                              */
#define PDB_PODLY_DLY1_MASK                      (0xFFFFUL << PDB_PODLY_DLY1_SHIFT)                  /*!< PDB0_PODLY: DLY1 Mask                   */
#define PDB_PODLY_DLY1_SHIFT                     16                                                  /*!< PDB0_PODLY: DLY1 Position               */
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY1_SHIFT))&PDB_PODLY_DLY1_MASK) /*!< PDB0_PODLY                              */
/**
 * @} */ /* End group PDB_Register_Masks_GROUP 
 */

/* PDB0 - Peripheral instance base addresses */
#define PDB0_BasePtr                   0xFFFF8540UL //!< Peripheral base address
#define PDB0                           ((PDB_Type *) PDB0_BasePtr) //!< Freescale base pointer
#define PDB0_BASE_PTR                  (PDB0) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer
* @brief C Struct for PMC
* @{
*/

/* ================================================================================ */
/* ================           PMC (file:PMC_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief Power Management Controller
 */
/**
* @addtogroup PMC_structs_GROUP PMC struct
* @brief Struct for PMC
* @{
*/
typedef struct {                                /*       PMC Structure                                                */
   __IO uint8_t   LVDSC1;                       /**< 0000: Low Voltage Status and Control 1                             */
   __IO uint8_t   LVDSC2;                       /**< 0001: Low Voltage Status and Control 2                             */
   __IO uint8_t   REGSC;                        /**< 0002: Regulator Status and Control                                 */
} PMC_Type;

/**
 * @} */ /* End group PMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PMC_Register_Masks_GROUP PMC Register Masks
* @brief Register Masks for PMC
* @{
*/
/* ------- LVDSC1 Bit Fields                        ------ */
#define PMC_LVDSC1_LVDV_MASK                     (0x03UL << PMC_LVDSC1_LVDV_SHIFT)                   /*!< PMC_LVDSC1: LVDV Mask                   */
#define PMC_LVDSC1_LVDV_SHIFT                    0                                                   /*!< PMC_LVDSC1: LVDV Position               */
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDRE_MASK                    (0x01UL << PMC_LVDSC1_LVDRE_SHIFT)                  /*!< PMC_LVDSC1: LVDRE Mask                  */
#define PMC_LVDSC1_LVDRE_SHIFT                   4                                                   /*!< PMC_LVDSC1: LVDRE Position              */
#define PMC_LVDSC1_LVDIE_MASK                    (0x01UL << PMC_LVDSC1_LVDIE_SHIFT)                  /*!< PMC_LVDSC1: LVDIE Mask                  */
#define PMC_LVDSC1_LVDIE_SHIFT                   5                                                   /*!< PMC_LVDSC1: LVDIE Position              */
#define PMC_LVDSC1_LVDACK_MASK                   (0x01UL << PMC_LVDSC1_LVDACK_SHIFT)                 /*!< PMC_LVDSC1: LVDACK Mask                 */
#define PMC_LVDSC1_LVDACK_SHIFT                  6                                                   /*!< PMC_LVDSC1: LVDACK Position             */
#define PMC_LVDSC1_LVDF_MASK                     (0x01UL << PMC_LVDSC1_LVDF_SHIFT)                   /*!< PMC_LVDSC1: LVDF Mask                   */
#define PMC_LVDSC1_LVDF_SHIFT                    7                                                   /*!< PMC_LVDSC1: LVDF Position               */
/* ------- LVDSC2 Bit Fields                        ------ */
#define PMC_LVDSC2_LVWV_MASK                     (0x03UL << PMC_LVDSC2_LVWV_SHIFT)                   /*!< PMC_LVDSC2: LVWV Mask                   */
#define PMC_LVDSC2_LVWV_SHIFT                    0                                                   /*!< PMC_LVDSC2: LVWV Position               */
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWIE_MASK                    (0x01UL << PMC_LVDSC2_LVWIE_SHIFT)                  /*!< PMC_LVDSC2: LVWIE Mask                  */
#define PMC_LVDSC2_LVWIE_SHIFT                   5                                                   /*!< PMC_LVDSC2: LVWIE Position              */
#define PMC_LVDSC2_LVWACK_MASK                   (0x01UL << PMC_LVDSC2_LVWACK_SHIFT)                 /*!< PMC_LVDSC2: LVWACK Mask                 */
#define PMC_LVDSC2_LVWACK_SHIFT                  6                                                   /*!< PMC_LVDSC2: LVWACK Position             */
#define PMC_LVDSC2_LVWF_MASK                     (0x01UL << PMC_LVDSC2_LVWF_SHIFT)                   /*!< PMC_LVDSC2: LVWF Mask                   */
#define PMC_LVDSC2_LVWF_SHIFT                    7                                                   /*!< PMC_LVDSC2: LVWF Position               */
/* ------- REGSC Bit Fields                         ------ */
#define PMC_REGSC_BGBE_MASK                      (0x01UL << PMC_REGSC_BGBE_SHIFT)                    /*!< PMC_REGSC: BGBE Mask                    */
#define PMC_REGSC_BGBE_SHIFT                     0                                                   /*!< PMC_REGSC: BGBE Position                */
#define PMC_REGSC_REGONS_MASK                    (0x01UL << PMC_REGSC_REGONS_SHIFT)                  /*!< PMC_REGSC: REGONS Mask                  */
#define PMC_REGSC_REGONS_SHIFT                   2                                                   /*!< PMC_REGSC: REGONS Position              */
#define PMC_REGSC_ACKISO_MASK                    (0x01UL << PMC_REGSC_ACKISO_SHIFT)                  /*!< PMC_REGSC: ACKISO Mask                  */
#define PMC_REGSC_ACKISO_SHIFT                   3                                                   /*!< PMC_REGSC: ACKISO Position              */
/**
 * @} */ /* End group PMC_Register_Masks_GROUP 
 */

/* PMC - Peripheral instance base addresses */
#define PMC_BasePtr                    0xFFFF8100UL //!< Peripheral base address
#define PMC                            ((PMC_Type *) PMC_BasePtr) //!< Freescale base pointer
#define PMC_BASE_PTR                   (PMC) //!< Freescale style base pointer
/**
 * @} */ /* End group PMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:RCM_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief Reset Control Module
 */
/**
* @addtogroup RCM_structs_GROUP RCM struct
* @brief Struct for RCM
* @{
*/
typedef struct {                                /*       RCM Structure                                                */
   __I  uint8_t   SRS0;                         /**< 0000: System Reset Status Register 0                               */
   __I  uint8_t   SRS1;                         /**< 0001: System Reset Status Register 1                               */
   __I  uint16_t  RESERVED0;                   
   __IO uint8_t   RPFC;                         /**< 0004: Reset Pin Filter Control Register                            */
   __IO uint8_t   RPFW;                         /**< 0005: Reset Pin Filter Width Register                              */
   __I  uint8_t   RESERVED1;                   
   __I  uint8_t   MR;                           /**< 0007: Mode Register                                                */
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
/* ------- SRS0 Bit Fields                          ------ */
#define RCM_SRS0_WAKEUP_MASK                     (0x01UL << RCM_SRS0_WAKEUP_SHIFT)                   /*!< RCM_SRS0: WAKEUP Mask                   */
#define RCM_SRS0_WAKEUP_SHIFT                    0                                                   /*!< RCM_SRS0: WAKEUP Position               */
#define RCM_SRS0_LVD_MASK                        (0x01UL << RCM_SRS0_LVD_SHIFT)                      /*!< RCM_SRS0: LVD Mask                      */
#define RCM_SRS0_LVD_SHIFT                       1                                                   /*!< RCM_SRS0: LVD Position                  */
#define RCM_SRS0_LOC_MASK                        (0x01UL << RCM_SRS0_LOC_SHIFT)                      /*!< RCM_SRS0: LOC Mask                      */
#define RCM_SRS0_LOC_SHIFT                       2                                                   /*!< RCM_SRS0: LOC Position                  */
#define RCM_SRS0_ILAD_MASK                       (0x01UL << RCM_SRS0_ILAD_SHIFT)                     /*!< RCM_SRS0: ILAD Mask                     */
#define RCM_SRS0_ILAD_SHIFT                      3                                                   /*!< RCM_SRS0: ILAD Position                 */
#define RCM_SRS0_ILOP_MASK                       (0x01UL << RCM_SRS0_ILOP_SHIFT)                     /*!< RCM_SRS0: ILOP Mask                     */
#define RCM_SRS0_ILOP_SHIFT                      4                                                   /*!< RCM_SRS0: ILOP Position                 */
#define RCM_SRS0_WDOG_MASK                       (0x01UL << RCM_SRS0_WDOG_SHIFT)                     /*!< RCM_SRS0: WDOG Mask                     */
#define RCM_SRS0_WDOG_SHIFT                      5                                                   /*!< RCM_SRS0: WDOG Position                 */
#define RCM_SRS0_PIN_MASK                        (0x01UL << RCM_SRS0_PIN_SHIFT)                      /*!< RCM_SRS0: PIN Mask                      */
#define RCM_SRS0_PIN_SHIFT                       6                                                   /*!< RCM_SRS0: PIN Position                  */
#define RCM_SRS0_POR_MASK                        (0x01UL << RCM_SRS0_POR_SHIFT)                      /*!< RCM_SRS0: POR Mask                      */
#define RCM_SRS0_POR_SHIFT                       7                                                   /*!< RCM_SRS0: POR Position                  */
/* ------- SRS1 Bit Fields                          ------ */
#define RCM_SRS1_BDFR_MASK                       (0x01UL << RCM_SRS1_BDFR_SHIFT)                     /*!< RCM_SRS1: BDFR Mask                     */
#define RCM_SRS1_BDFR_SHIFT                      3                                                   /*!< RCM_SRS1: BDFR Position                 */
#define RCM_SRS1_EZPT_MASK                       (0x01UL << RCM_SRS1_EZPT_SHIFT)                     /*!< RCM_SRS1: EZPT Mask                     */
#define RCM_SRS1_EZPT_SHIFT                      4                                                   /*!< RCM_SRS1: EZPT Position                 */
#define RCM_SRS1_SACKERR_MASK                    (0x01UL << RCM_SRS1_SACKERR_SHIFT)                  /*!< RCM_SRS1: SACKERR Mask                  */
#define RCM_SRS1_SACKERR_SHIFT                   5                                                   /*!< RCM_SRS1: SACKERR Position              */
/* ------- RPFC Bit Fields                          ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x03UL << RCM_RPFC_RSTFLTSRW_SHIFT)                /*!< RCM_RPFC: RSTFLTSRW Mask                */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 0                                                   /*!< RCM_RPFC: RSTFLTSRW Position            */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK) /*!< RCM_RPFC                                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x01UL << RCM_RPFC_RSTFLTSS_SHIFT)                 /*!< RCM_RPFC: RSTFLTSS Mask                 */
#define RCM_RPFC_RSTFLTSS_SHIFT                  2                                                   /*!< RCM_RPFC: RSTFLTSS Position             */
/* ------- RPFW Bit Fields                          ------ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FUL << RCM_RPFW_RSTFLTSEL_SHIFT)                /*!< RCM_RPFW: RSTFLTSEL Mask                */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 0                                                   /*!< RCM_RPFW: RSTFLTSEL Position            */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK) /*!< RCM_RPFW                                */
/* ------- MR Bit Fields                            ------ */
#define RCM_MR_MS_MASK                           (0x01UL << RCM_MR_MS_SHIFT)                         /*!< RCM_MR: MS Mask                         */
#define RCM_MR_MS_SHIFT                          0                                                   /*!< RCM_MR: MS Position                     */
#define RCM_MR_EZP_MS_MASK                       (0x01UL << RCM_MR_EZP_MS_SHIFT)                     /*!< RCM_MR: EZP_MS Mask                     */
#define RCM_MR_EZP_MS_SHIFT                      1                                                   /*!< RCM_MR: EZP_MS Position                 */
/**
 * @} */ /* End group RCM_Register_Masks_GROUP 
 */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0xFFFF8110UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer
/**
 * @} */ /* End group RCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RFSYS_Peripheral_access_layer_GROUP RFSYS Peripheral Access Layer
* @brief C Struct for RFSYS
* @{
*/

/* ================================================================================ */
/* ================           RFSYS (file:RFSYS_MCF51)             ================ */
/* ================================================================================ */

/**
 * @brief Register File
 */
/**
* @addtogroup RFSYS_structs_GROUP RFSYS struct
* @brief Struct for RFSYS
* @{
*/
typedef struct {                                /*       RFSYS Structure                                              */
   union {                                      /**< 0000: (size=0020)                                                  */
      __IO uint8_t   REGB[32];                  /**< 0000: Battery Backed Register File                                 */
      __IO uint32_t  REGL[8];                   /**< 0000: Battery Backed Register File                                 */
      __IO uint16_t  REGW[16];                  /**< 0000: Battery Backed Register File                                 */
   };
} RFSYS_Type;

/**
 * @} */ /* End group RFSYS_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RFSYS' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RFSYS_Register_Masks_GROUP RFSYS Register Masks
* @brief Register Masks for RFSYS
* @{
*/
/* ------- REGB Bit Fields                          ------ */
/* ------- REGL Bit Fields                          ------ */
/* ------- REGW Bit Fields                          ------ */
/**
 * @} */ /* End group RFSYS_Register_Masks_GROUP 
 */

/* RFSYS - Peripheral instance base addresses */
#define RFSYS_BasePtr                  0xFFFF8060UL //!< Peripheral base address
#define RFSYS                          ((RFSYS_Type *) RFSYS_BasePtr) //!< Freescale base pointer
#define RFSYS_BASE_PTR                 (RFSYS) //!< Freescale style base pointer
/**
 * @} */ /* End group RFSYS_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RGPIO_Peripheral_access_layer_GROUP RGPIO Peripheral Access Layer
* @brief C Struct for RGPIO
* @{
*/

/* ================================================================================ */
/* ================           RGPIO (file:RGPIO_MCF51)             ================ */
/* ================================================================================ */

/**
 * @brief Rapid GPIO
 */
/**
* @addtogroup RGPIO_structs_GROUP RGPIO struct
* @brief Struct for RGPIO
* @{
*/
typedef struct {                                /*       RGPIO Structure                                              */
   __IO uint16_t  DIR;                          /**< 0000: Data Direction Register                                      */
   __IO uint16_t  DATA;                         /**< 0002: Data Register                                                */
   __IO uint16_t  ENB;                          /**< 0004: Pin Enable Register                                          */
   __IO uint16_t  CLR;                          /**< 0006: Clear Data Register                                          */
   __I  uint16_t  RESERVED0;                   
   __IO uint16_t  SET;                          /**< 000A: Set Data Register                                            */
   __I  uint16_t  RESERVED1;                   
   __IO uint16_t  TOG;                          /**< 000E: Toggle Data Register                                         */
} RGPIO_Type;

/**
 * @} */ /* End group RGPIO_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RGPIO' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RGPIO_Register_Masks_GROUP RGPIO Register Masks
* @brief Register Masks for RGPIO
* @{
*/
/* ------- DIR Bit Fields                           ------ */
#define RGPIO_DIR_DIR0_MASK                      (0x01UL << RGPIO_DIR_DIR0_SHIFT)                    /*!< RGPIO_DIR: DIR0 Mask                    */
#define RGPIO_DIR_DIR0_SHIFT                     0                                                   /*!< RGPIO_DIR: DIR0 Position                */
#define RGPIO_DIR_DIR1_MASK                      (0x01UL << RGPIO_DIR_DIR1_SHIFT)                    /*!< RGPIO_DIR: DIR1 Mask                    */
#define RGPIO_DIR_DIR1_SHIFT                     1                                                   /*!< RGPIO_DIR: DIR1 Position                */
#define RGPIO_DIR_DIR2_MASK                      (0x01UL << RGPIO_DIR_DIR2_SHIFT)                    /*!< RGPIO_DIR: DIR2 Mask                    */
#define RGPIO_DIR_DIR2_SHIFT                     2                                                   /*!< RGPIO_DIR: DIR2 Position                */
#define RGPIO_DIR_DIR3_MASK                      (0x01UL << RGPIO_DIR_DIR3_SHIFT)                    /*!< RGPIO_DIR: DIR3 Mask                    */
#define RGPIO_DIR_DIR3_SHIFT                     3                                                   /*!< RGPIO_DIR: DIR3 Position                */
#define RGPIO_DIR_DIR4_MASK                      (0x01UL << RGPIO_DIR_DIR4_SHIFT)                    /*!< RGPIO_DIR: DIR4 Mask                    */
#define RGPIO_DIR_DIR4_SHIFT                     4                                                   /*!< RGPIO_DIR: DIR4 Position                */
#define RGPIO_DIR_DIR5_MASK                      (0x01UL << RGPIO_DIR_DIR5_SHIFT)                    /*!< RGPIO_DIR: DIR5 Mask                    */
#define RGPIO_DIR_DIR5_SHIFT                     5                                                   /*!< RGPIO_DIR: DIR5 Position                */
#define RGPIO_DIR_DIR6_MASK                      (0x01UL << RGPIO_DIR_DIR6_SHIFT)                    /*!< RGPIO_DIR: DIR6 Mask                    */
#define RGPIO_DIR_DIR6_SHIFT                     6                                                   /*!< RGPIO_DIR: DIR6 Position                */
#define RGPIO_DIR_DIR7_MASK                      (0x01UL << RGPIO_DIR_DIR7_SHIFT)                    /*!< RGPIO_DIR: DIR7 Mask                    */
#define RGPIO_DIR_DIR7_SHIFT                     7                                                   /*!< RGPIO_DIR: DIR7 Position                */
#define RGPIO_DIR_DIR8_MASK                      (0x01UL << RGPIO_DIR_DIR8_SHIFT)                    /*!< RGPIO_DIR: DIR8 Mask                    */
#define RGPIO_DIR_DIR8_SHIFT                     8                                                   /*!< RGPIO_DIR: DIR8 Position                */
#define RGPIO_DIR_DIR9_MASK                      (0x01UL << RGPIO_DIR_DIR9_SHIFT)                    /*!< RGPIO_DIR: DIR9 Mask                    */
#define RGPIO_DIR_DIR9_SHIFT                     9                                                   /*!< RGPIO_DIR: DIR9 Position                */
#define RGPIO_DIR_DIR10_MASK                     (0x01UL << RGPIO_DIR_DIR10_SHIFT)                   /*!< RGPIO_DIR: DIR10 Mask                   */
#define RGPIO_DIR_DIR10_SHIFT                    10                                                  /*!< RGPIO_DIR: DIR10 Position               */
#define RGPIO_DIR_DIR11_MASK                     (0x01UL << RGPIO_DIR_DIR11_SHIFT)                   /*!< RGPIO_DIR: DIR11 Mask                   */
#define RGPIO_DIR_DIR11_SHIFT                    11                                                  /*!< RGPIO_DIR: DIR11 Position               */
#define RGPIO_DIR_DIR12_MASK                     (0x01UL << RGPIO_DIR_DIR12_SHIFT)                   /*!< RGPIO_DIR: DIR12 Mask                   */
#define RGPIO_DIR_DIR12_SHIFT                    12                                                  /*!< RGPIO_DIR: DIR12 Position               */
#define RGPIO_DIR_DIR13_MASK                     (0x01UL << RGPIO_DIR_DIR13_SHIFT)                   /*!< RGPIO_DIR: DIR13 Mask                   */
#define RGPIO_DIR_DIR13_SHIFT                    13                                                  /*!< RGPIO_DIR: DIR13 Position               */
#define RGPIO_DIR_DIR14_MASK                     (0x01UL << RGPIO_DIR_DIR14_SHIFT)                   /*!< RGPIO_DIR: DIR14 Mask                   */
#define RGPIO_DIR_DIR14_SHIFT                    14                                                  /*!< RGPIO_DIR: DIR14 Position               */
#define RGPIO_DIR_DIR15_MASK                     (0x01UL << RGPIO_DIR_DIR15_SHIFT)                   /*!< RGPIO_DIR: DIR15 Mask                   */
#define RGPIO_DIR_DIR15_SHIFT                    15                                                  /*!< RGPIO_DIR: DIR15 Position               */
/* ------- DATA Bit Fields                          ------ */
#define RGPIO_DATA_DATA0_MASK                    (0x01UL << RGPIO_DATA_DATA0_SHIFT)                  /*!< RGPIO_DATA: DATA0 Mask                  */
#define RGPIO_DATA_DATA0_SHIFT                   0                                                   /*!< RGPIO_DATA: DATA0 Position              */
#define RGPIO_DATA_DATA1_MASK                    (0x01UL << RGPIO_DATA_DATA1_SHIFT)                  /*!< RGPIO_DATA: DATA1 Mask                  */
#define RGPIO_DATA_DATA1_SHIFT                   1                                                   /*!< RGPIO_DATA: DATA1 Position              */
#define RGPIO_DATA_DATA2_MASK                    (0x01UL << RGPIO_DATA_DATA2_SHIFT)                  /*!< RGPIO_DATA: DATA2 Mask                  */
#define RGPIO_DATA_DATA2_SHIFT                   2                                                   /*!< RGPIO_DATA: DATA2 Position              */
#define RGPIO_DATA_DATA3_MASK                    (0x01UL << RGPIO_DATA_DATA3_SHIFT)                  /*!< RGPIO_DATA: DATA3 Mask                  */
#define RGPIO_DATA_DATA3_SHIFT                   3                                                   /*!< RGPIO_DATA: DATA3 Position              */
#define RGPIO_DATA_DATA4_MASK                    (0x01UL << RGPIO_DATA_DATA4_SHIFT)                  /*!< RGPIO_DATA: DATA4 Mask                  */
#define RGPIO_DATA_DATA4_SHIFT                   4                                                   /*!< RGPIO_DATA: DATA4 Position              */
#define RGPIO_DATA_DATA5_MASK                    (0x01UL << RGPIO_DATA_DATA5_SHIFT)                  /*!< RGPIO_DATA: DATA5 Mask                  */
#define RGPIO_DATA_DATA5_SHIFT                   5                                                   /*!< RGPIO_DATA: DATA5 Position              */
#define RGPIO_DATA_DATA6_MASK                    (0x01UL << RGPIO_DATA_DATA6_SHIFT)                  /*!< RGPIO_DATA: DATA6 Mask                  */
#define RGPIO_DATA_DATA6_SHIFT                   6                                                   /*!< RGPIO_DATA: DATA6 Position              */
#define RGPIO_DATA_DATA7_MASK                    (0x01UL << RGPIO_DATA_DATA7_SHIFT)                  /*!< RGPIO_DATA: DATA7 Mask                  */
#define RGPIO_DATA_DATA7_SHIFT                   7                                                   /*!< RGPIO_DATA: DATA7 Position              */
#define RGPIO_DATA_DATA8_MASK                    (0x01UL << RGPIO_DATA_DATA8_SHIFT)                  /*!< RGPIO_DATA: DATA8 Mask                  */
#define RGPIO_DATA_DATA8_SHIFT                   8                                                   /*!< RGPIO_DATA: DATA8 Position              */
#define RGPIO_DATA_DATA9_MASK                    (0x01UL << RGPIO_DATA_DATA9_SHIFT)                  /*!< RGPIO_DATA: DATA9 Mask                  */
#define RGPIO_DATA_DATA9_SHIFT                   9                                                   /*!< RGPIO_DATA: DATA9 Position              */
#define RGPIO_DATA_DATA10_MASK                   (0x01UL << RGPIO_DATA_DATA10_SHIFT)                 /*!< RGPIO_DATA: DATA10 Mask                 */
#define RGPIO_DATA_DATA10_SHIFT                  10                                                  /*!< RGPIO_DATA: DATA10 Position             */
#define RGPIO_DATA_DATA11_MASK                   (0x01UL << RGPIO_DATA_DATA11_SHIFT)                 /*!< RGPIO_DATA: DATA11 Mask                 */
#define RGPIO_DATA_DATA11_SHIFT                  11                                                  /*!< RGPIO_DATA: DATA11 Position             */
#define RGPIO_DATA_DATA12_MASK                   (0x01UL << RGPIO_DATA_DATA12_SHIFT)                 /*!< RGPIO_DATA: DATA12 Mask                 */
#define RGPIO_DATA_DATA12_SHIFT                  12                                                  /*!< RGPIO_DATA: DATA12 Position             */
#define RGPIO_DATA_DATA13_MASK                   (0x01UL << RGPIO_DATA_DATA13_SHIFT)                 /*!< RGPIO_DATA: DATA13 Mask                 */
#define RGPIO_DATA_DATA13_SHIFT                  13                                                  /*!< RGPIO_DATA: DATA13 Position             */
#define RGPIO_DATA_DATA14_MASK                   (0x01UL << RGPIO_DATA_DATA14_SHIFT)                 /*!< RGPIO_DATA: DATA14 Mask                 */
#define RGPIO_DATA_DATA14_SHIFT                  14                                                  /*!< RGPIO_DATA: DATA14 Position             */
#define RGPIO_DATA_DATA15_MASK                   (0x01UL << RGPIO_DATA_DATA15_SHIFT)                 /*!< RGPIO_DATA: DATA15 Mask                 */
#define RGPIO_DATA_DATA15_SHIFT                  15                                                  /*!< RGPIO_DATA: DATA15 Position             */
/* ------- ENB Bit Fields                           ------ */
#define RGPIO_ENB_ENB0_MASK                      (0x01UL << RGPIO_ENB_ENB0_SHIFT)                    /*!< RGPIO_ENB: ENB0 Mask                    */
#define RGPIO_ENB_ENB0_SHIFT                     0                                                   /*!< RGPIO_ENB: ENB0 Position                */
#define RGPIO_ENB_ENB1_MASK                      (0x01UL << RGPIO_ENB_ENB1_SHIFT)                    /*!< RGPIO_ENB: ENB1 Mask                    */
#define RGPIO_ENB_ENB1_SHIFT                     1                                                   /*!< RGPIO_ENB: ENB1 Position                */
#define RGPIO_ENB_ENB2_MASK                      (0x01UL << RGPIO_ENB_ENB2_SHIFT)                    /*!< RGPIO_ENB: ENB2 Mask                    */
#define RGPIO_ENB_ENB2_SHIFT                     2                                                   /*!< RGPIO_ENB: ENB2 Position                */
#define RGPIO_ENB_ENB3_MASK                      (0x01UL << RGPIO_ENB_ENB3_SHIFT)                    /*!< RGPIO_ENB: ENB3 Mask                    */
#define RGPIO_ENB_ENB3_SHIFT                     3                                                   /*!< RGPIO_ENB: ENB3 Position                */
#define RGPIO_ENB_ENB4_MASK                      (0x01UL << RGPIO_ENB_ENB4_SHIFT)                    /*!< RGPIO_ENB: ENB4 Mask                    */
#define RGPIO_ENB_ENB4_SHIFT                     4                                                   /*!< RGPIO_ENB: ENB4 Position                */
#define RGPIO_ENB_ENB5_MASK                      (0x01UL << RGPIO_ENB_ENB5_SHIFT)                    /*!< RGPIO_ENB: ENB5 Mask                    */
#define RGPIO_ENB_ENB5_SHIFT                     5                                                   /*!< RGPIO_ENB: ENB5 Position                */
#define RGPIO_ENB_ENB6_MASK                      (0x01UL << RGPIO_ENB_ENB6_SHIFT)                    /*!< RGPIO_ENB: ENB6 Mask                    */
#define RGPIO_ENB_ENB6_SHIFT                     6                                                   /*!< RGPIO_ENB: ENB6 Position                */
#define RGPIO_ENB_ENB7_MASK                      (0x01UL << RGPIO_ENB_ENB7_SHIFT)                    /*!< RGPIO_ENB: ENB7 Mask                    */
#define RGPIO_ENB_ENB7_SHIFT                     7                                                   /*!< RGPIO_ENB: ENB7 Position                */
#define RGPIO_ENB_ENB8_MASK                      (0x01UL << RGPIO_ENB_ENB8_SHIFT)                    /*!< RGPIO_ENB: ENB8 Mask                    */
#define RGPIO_ENB_ENB8_SHIFT                     8                                                   /*!< RGPIO_ENB: ENB8 Position                */
#define RGPIO_ENB_ENB9_MASK                      (0x01UL << RGPIO_ENB_ENB9_SHIFT)                    /*!< RGPIO_ENB: ENB9 Mask                    */
#define RGPIO_ENB_ENB9_SHIFT                     9                                                   /*!< RGPIO_ENB: ENB9 Position                */
#define RGPIO_ENB_ENB10_MASK                     (0x01UL << RGPIO_ENB_ENB10_SHIFT)                   /*!< RGPIO_ENB: ENB10 Mask                   */
#define RGPIO_ENB_ENB10_SHIFT                    10                                                  /*!< RGPIO_ENB: ENB10 Position               */
#define RGPIO_ENB_ENB11_MASK                     (0x01UL << RGPIO_ENB_ENB11_SHIFT)                   /*!< RGPIO_ENB: ENB11 Mask                   */
#define RGPIO_ENB_ENB11_SHIFT                    11                                                  /*!< RGPIO_ENB: ENB11 Position               */
#define RGPIO_ENB_ENB12_MASK                     (0x01UL << RGPIO_ENB_ENB12_SHIFT)                   /*!< RGPIO_ENB: ENB12 Mask                   */
#define RGPIO_ENB_ENB12_SHIFT                    12                                                  /*!< RGPIO_ENB: ENB12 Position               */
#define RGPIO_ENB_ENB13_MASK                     (0x01UL << RGPIO_ENB_ENB13_SHIFT)                   /*!< RGPIO_ENB: ENB13 Mask                   */
#define RGPIO_ENB_ENB13_SHIFT                    13                                                  /*!< RGPIO_ENB: ENB13 Position               */
#define RGPIO_ENB_ENB14_MASK                     (0x01UL << RGPIO_ENB_ENB14_SHIFT)                   /*!< RGPIO_ENB: ENB14 Mask                   */
#define RGPIO_ENB_ENB14_SHIFT                    14                                                  /*!< RGPIO_ENB: ENB14 Position               */
#define RGPIO_ENB_ENB15_MASK                     (0x01UL << RGPIO_ENB_ENB15_SHIFT)                   /*!< RGPIO_ENB: ENB15 Mask                   */
#define RGPIO_ENB_ENB15_SHIFT                    15                                                  /*!< RGPIO_ENB: ENB15 Position               */
/* ------- CLR Bit Fields                           ------ */
#define RGPIO_CLR_CLR0_MASK                      (0x01UL << RGPIO_CLR_CLR0_SHIFT)                    /*!< RGPIO_CLR: CLR0 Mask                    */
#define RGPIO_CLR_CLR0_SHIFT                     0                                                   /*!< RGPIO_CLR: CLR0 Position                */
#define RGPIO_CLR_CLR1_MASK                      (0x01UL << RGPIO_CLR_CLR1_SHIFT)                    /*!< RGPIO_CLR: CLR1 Mask                    */
#define RGPIO_CLR_CLR1_SHIFT                     1                                                   /*!< RGPIO_CLR: CLR1 Position                */
#define RGPIO_CLR_CLR2_MASK                      (0x01UL << RGPIO_CLR_CLR2_SHIFT)                    /*!< RGPIO_CLR: CLR2 Mask                    */
#define RGPIO_CLR_CLR2_SHIFT                     2                                                   /*!< RGPIO_CLR: CLR2 Position                */
#define RGPIO_CLR_CLR3_MASK                      (0x01UL << RGPIO_CLR_CLR3_SHIFT)                    /*!< RGPIO_CLR: CLR3 Mask                    */
#define RGPIO_CLR_CLR3_SHIFT                     3                                                   /*!< RGPIO_CLR: CLR3 Position                */
#define RGPIO_CLR_CLR4_MASK                      (0x01UL << RGPIO_CLR_CLR4_SHIFT)                    /*!< RGPIO_CLR: CLR4 Mask                    */
#define RGPIO_CLR_CLR4_SHIFT                     4                                                   /*!< RGPIO_CLR: CLR4 Position                */
#define RGPIO_CLR_CLR5_MASK                      (0x01UL << RGPIO_CLR_CLR5_SHIFT)                    /*!< RGPIO_CLR: CLR5 Mask                    */
#define RGPIO_CLR_CLR5_SHIFT                     5                                                   /*!< RGPIO_CLR: CLR5 Position                */
#define RGPIO_CLR_CLR6_MASK                      (0x01UL << RGPIO_CLR_CLR6_SHIFT)                    /*!< RGPIO_CLR: CLR6 Mask                    */
#define RGPIO_CLR_CLR6_SHIFT                     6                                                   /*!< RGPIO_CLR: CLR6 Position                */
#define RGPIO_CLR_CLR7_MASK                      (0x01UL << RGPIO_CLR_CLR7_SHIFT)                    /*!< RGPIO_CLR: CLR7 Mask                    */
#define RGPIO_CLR_CLR7_SHIFT                     7                                                   /*!< RGPIO_CLR: CLR7 Position                */
#define RGPIO_CLR_CLR8_MASK                      (0x01UL << RGPIO_CLR_CLR8_SHIFT)                    /*!< RGPIO_CLR: CLR8 Mask                    */
#define RGPIO_CLR_CLR8_SHIFT                     8                                                   /*!< RGPIO_CLR: CLR8 Position                */
#define RGPIO_CLR_CLR9_MASK                      (0x01UL << RGPIO_CLR_CLR9_SHIFT)                    /*!< RGPIO_CLR: CLR9 Mask                    */
#define RGPIO_CLR_CLR9_SHIFT                     9                                                   /*!< RGPIO_CLR: CLR9 Position                */
#define RGPIO_CLR_CLR10_MASK                     (0x01UL << RGPIO_CLR_CLR10_SHIFT)                   /*!< RGPIO_CLR: CLR10 Mask                   */
#define RGPIO_CLR_CLR10_SHIFT                    10                                                  /*!< RGPIO_CLR: CLR10 Position               */
#define RGPIO_CLR_CLR11_MASK                     (0x01UL << RGPIO_CLR_CLR11_SHIFT)                   /*!< RGPIO_CLR: CLR11 Mask                   */
#define RGPIO_CLR_CLR11_SHIFT                    11                                                  /*!< RGPIO_CLR: CLR11 Position               */
#define RGPIO_CLR_CLR12_MASK                     (0x01UL << RGPIO_CLR_CLR12_SHIFT)                   /*!< RGPIO_CLR: CLR12 Mask                   */
#define RGPIO_CLR_CLR12_SHIFT                    12                                                  /*!< RGPIO_CLR: CLR12 Position               */
#define RGPIO_CLR_CLR13_MASK                     (0x01UL << RGPIO_CLR_CLR13_SHIFT)                   /*!< RGPIO_CLR: CLR13 Mask                   */
#define RGPIO_CLR_CLR13_SHIFT                    13                                                  /*!< RGPIO_CLR: CLR13 Position               */
#define RGPIO_CLR_CLR14_MASK                     (0x01UL << RGPIO_CLR_CLR14_SHIFT)                   /*!< RGPIO_CLR: CLR14 Mask                   */
#define RGPIO_CLR_CLR14_SHIFT                    14                                                  /*!< RGPIO_CLR: CLR14 Position               */
#define RGPIO_CLR_CLR15_MASK                     (0x01UL << RGPIO_CLR_CLR15_SHIFT)                   /*!< RGPIO_CLR: CLR15 Mask                   */
#define RGPIO_CLR_CLR15_SHIFT                    15                                                  /*!< RGPIO_CLR: CLR15 Position               */
/* ------- SET Bit Fields                           ------ */
#define RGPIO_SET_SET0_MASK                      (0x01UL << RGPIO_SET_SET0_SHIFT)                    /*!< RGPIO_SET: SET0 Mask                    */
#define RGPIO_SET_SET0_SHIFT                     0                                                   /*!< RGPIO_SET: SET0 Position                */
#define RGPIO_SET_SET1_MASK                      (0x01UL << RGPIO_SET_SET1_SHIFT)                    /*!< RGPIO_SET: SET1 Mask                    */
#define RGPIO_SET_SET1_SHIFT                     1                                                   /*!< RGPIO_SET: SET1 Position                */
#define RGPIO_SET_SET2_MASK                      (0x01UL << RGPIO_SET_SET2_SHIFT)                    /*!< RGPIO_SET: SET2 Mask                    */
#define RGPIO_SET_SET2_SHIFT                     2                                                   /*!< RGPIO_SET: SET2 Position                */
#define RGPIO_SET_SET3_MASK                      (0x01UL << RGPIO_SET_SET3_SHIFT)                    /*!< RGPIO_SET: SET3 Mask                    */
#define RGPIO_SET_SET3_SHIFT                     3                                                   /*!< RGPIO_SET: SET3 Position                */
#define RGPIO_SET_SET4_MASK                      (0x01UL << RGPIO_SET_SET4_SHIFT)                    /*!< RGPIO_SET: SET4 Mask                    */
#define RGPIO_SET_SET4_SHIFT                     4                                                   /*!< RGPIO_SET: SET4 Position                */
#define RGPIO_SET_SET5_MASK                      (0x01UL << RGPIO_SET_SET5_SHIFT)                    /*!< RGPIO_SET: SET5 Mask                    */
#define RGPIO_SET_SET5_SHIFT                     5                                                   /*!< RGPIO_SET: SET5 Position                */
#define RGPIO_SET_SET6_MASK                      (0x01UL << RGPIO_SET_SET6_SHIFT)                    /*!< RGPIO_SET: SET6 Mask                    */
#define RGPIO_SET_SET6_SHIFT                     6                                                   /*!< RGPIO_SET: SET6 Position                */
#define RGPIO_SET_SET7_MASK                      (0x01UL << RGPIO_SET_SET7_SHIFT)                    /*!< RGPIO_SET: SET7 Mask                    */
#define RGPIO_SET_SET7_SHIFT                     7                                                   /*!< RGPIO_SET: SET7 Position                */
#define RGPIO_SET_SET8_MASK                      (0x01UL << RGPIO_SET_SET8_SHIFT)                    /*!< RGPIO_SET: SET8 Mask                    */
#define RGPIO_SET_SET8_SHIFT                     8                                                   /*!< RGPIO_SET: SET8 Position                */
#define RGPIO_SET_SET9_MASK                      (0x01UL << RGPIO_SET_SET9_SHIFT)                    /*!< RGPIO_SET: SET9 Mask                    */
#define RGPIO_SET_SET9_SHIFT                     9                                                   /*!< RGPIO_SET: SET9 Position                */
#define RGPIO_SET_SET10_MASK                     (0x01UL << RGPIO_SET_SET10_SHIFT)                   /*!< RGPIO_SET: SET10 Mask                   */
#define RGPIO_SET_SET10_SHIFT                    10                                                  /*!< RGPIO_SET: SET10 Position               */
#define RGPIO_SET_SET11_MASK                     (0x01UL << RGPIO_SET_SET11_SHIFT)                   /*!< RGPIO_SET: SET11 Mask                   */
#define RGPIO_SET_SET11_SHIFT                    11                                                  /*!< RGPIO_SET: SET11 Position               */
#define RGPIO_SET_SET12_MASK                     (0x01UL << RGPIO_SET_SET12_SHIFT)                   /*!< RGPIO_SET: SET12 Mask                   */
#define RGPIO_SET_SET12_SHIFT                    12                                                  /*!< RGPIO_SET: SET12 Position               */
#define RGPIO_SET_SET13_MASK                     (0x01UL << RGPIO_SET_SET13_SHIFT)                   /*!< RGPIO_SET: SET13 Mask                   */
#define RGPIO_SET_SET13_SHIFT                    13                                                  /*!< RGPIO_SET: SET13 Position               */
#define RGPIO_SET_SET14_MASK                     (0x01UL << RGPIO_SET_SET14_SHIFT)                   /*!< RGPIO_SET: SET14 Mask                   */
#define RGPIO_SET_SET14_SHIFT                    14                                                  /*!< RGPIO_SET: SET14 Position               */
#define RGPIO_SET_SET15_MASK                     (0x01UL << RGPIO_SET_SET15_SHIFT)                   /*!< RGPIO_SET: SET15 Mask                   */
#define RGPIO_SET_SET15_SHIFT                    15                                                  /*!< RGPIO_SET: SET15 Position               */
/* ------- TOG Bit Fields                           ------ */
#define RGPIO_TOG_TOG0_MASK                      (0x01UL << RGPIO_TOG_TOG0_SHIFT)                    /*!< RGPIO_TOG: TOG0 Mask                    */
#define RGPIO_TOG_TOG0_SHIFT                     0                                                   /*!< RGPIO_TOG: TOG0 Position                */
#define RGPIO_TOG_TOG1_MASK                      (0x01UL << RGPIO_TOG_TOG1_SHIFT)                    /*!< RGPIO_TOG: TOG1 Mask                    */
#define RGPIO_TOG_TOG1_SHIFT                     1                                                   /*!< RGPIO_TOG: TOG1 Position                */
#define RGPIO_TOG_TOG2_MASK                      (0x01UL << RGPIO_TOG_TOG2_SHIFT)                    /*!< RGPIO_TOG: TOG2 Mask                    */
#define RGPIO_TOG_TOG2_SHIFT                     2                                                   /*!< RGPIO_TOG: TOG2 Position                */
#define RGPIO_TOG_TOG3_MASK                      (0x01UL << RGPIO_TOG_TOG3_SHIFT)                    /*!< RGPIO_TOG: TOG3 Mask                    */
#define RGPIO_TOG_TOG3_SHIFT                     3                                                   /*!< RGPIO_TOG: TOG3 Position                */
#define RGPIO_TOG_TOG4_MASK                      (0x01UL << RGPIO_TOG_TOG4_SHIFT)                    /*!< RGPIO_TOG: TOG4 Mask                    */
#define RGPIO_TOG_TOG4_SHIFT                     4                                                   /*!< RGPIO_TOG: TOG4 Position                */
#define RGPIO_TOG_TOG5_MASK                      (0x01UL << RGPIO_TOG_TOG5_SHIFT)                    /*!< RGPIO_TOG: TOG5 Mask                    */
#define RGPIO_TOG_TOG5_SHIFT                     5                                                   /*!< RGPIO_TOG: TOG5 Position                */
#define RGPIO_TOG_TOG6_MASK                      (0x01UL << RGPIO_TOG_TOG6_SHIFT)                    /*!< RGPIO_TOG: TOG6 Mask                    */
#define RGPIO_TOG_TOG6_SHIFT                     6                                                   /*!< RGPIO_TOG: TOG6 Position                */
#define RGPIO_TOG_TOG7_MASK                      (0x01UL << RGPIO_TOG_TOG7_SHIFT)                    /*!< RGPIO_TOG: TOG7 Mask                    */
#define RGPIO_TOG_TOG7_SHIFT                     7                                                   /*!< RGPIO_TOG: TOG7 Position                */
#define RGPIO_TOG_TOG8_MASK                      (0x01UL << RGPIO_TOG_TOG8_SHIFT)                    /*!< RGPIO_TOG: TOG8 Mask                    */
#define RGPIO_TOG_TOG8_SHIFT                     8                                                   /*!< RGPIO_TOG: TOG8 Position                */
#define RGPIO_TOG_TOG9_MASK                      (0x01UL << RGPIO_TOG_TOG9_SHIFT)                    /*!< RGPIO_TOG: TOG9 Mask                    */
#define RGPIO_TOG_TOG9_SHIFT                     9                                                   /*!< RGPIO_TOG: TOG9 Position                */
#define RGPIO_TOG_TOG10_MASK                     (0x01UL << RGPIO_TOG_TOG10_SHIFT)                   /*!< RGPIO_TOG: TOG10 Mask                   */
#define RGPIO_TOG_TOG10_SHIFT                    10                                                  /*!< RGPIO_TOG: TOG10 Position               */
#define RGPIO_TOG_TOG11_MASK                     (0x01UL << RGPIO_TOG_TOG11_SHIFT)                   /*!< RGPIO_TOG: TOG11 Mask                   */
#define RGPIO_TOG_TOG11_SHIFT                    11                                                  /*!< RGPIO_TOG: TOG11 Position               */
#define RGPIO_TOG_TOG12_MASK                     (0x01UL << RGPIO_TOG_TOG12_SHIFT)                   /*!< RGPIO_TOG: TOG12 Mask                   */
#define RGPIO_TOG_TOG12_SHIFT                    12                                                  /*!< RGPIO_TOG: TOG12 Position               */
#define RGPIO_TOG_TOG13_MASK                     (0x01UL << RGPIO_TOG_TOG13_SHIFT)                   /*!< RGPIO_TOG: TOG13 Mask                   */
#define RGPIO_TOG_TOG13_SHIFT                    13                                                  /*!< RGPIO_TOG: TOG13 Position               */
#define RGPIO_TOG_TOG14_MASK                     (0x01UL << RGPIO_TOG_TOG14_SHIFT)                   /*!< RGPIO_TOG: TOG14 Mask                   */
#define RGPIO_TOG_TOG14_SHIFT                    14                                                  /*!< RGPIO_TOG: TOG14 Position               */
#define RGPIO_TOG_TOG15_MASK                     (0x01UL << RGPIO_TOG_TOG15_SHIFT)                   /*!< RGPIO_TOG: TOG15 Mask                   */
#define RGPIO_TOG_TOG15_SHIFT                    15                                                  /*!< RGPIO_TOG: TOG15 Position               */
/**
 * @} */ /* End group RGPIO_Register_Masks_GROUP 
 */

/* RGPIO - Peripheral instance base addresses */
#define RGPIO_BasePtr                  0xFFC00000UL //!< Peripheral base address
#define RGPIO                          ((RGPIO_Type *) RGPIO_BasePtr) //!< Freescale base pointer
#define RGPIO_BASE_PTR                 (RGPIO) //!< Freescale style base pointer
/**
 * @} */ /* End group RGPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RNG_Peripheral_access_layer_GROUP RNG Peripheral Access Layer
* @brief C Struct for RNG
* @{
*/

/* ================================================================================ */
/* ================           RNG (file:RNG_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief Random Number Generator
 */
/**
* @addtogroup RNG_structs_GROUP RNG struct
* @brief Struct for RNG
* @{
*/
typedef struct {                                /*       RNG Structure                                                */
   __I  uint32_t  VER;                          /**< 0000: RNGB Version ID Register                                     */
   __IO uint32_t  CMD;                          /**< 0004: RNGB Command Register                                        */
   __IO uint32_t  CR;                           /**< 0008: RNGB Control Register                                        */
   __I  uint32_t  SR;                           /**< 000C: RNGB Status Register                                         */
   __I  uint32_t  ESR;                          /**< 0010: RNGB Error Status Register                                   */
   __I  uint32_t  OUT;                          /**< 0014: RNGB Output FIFO                                             */
} RNG_Type;

/**
 * @} */ /* End group RNG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RNG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RNG_Register_Masks_GROUP RNG Register Masks
* @brief Register Masks for RNG
* @{
*/
/* ------- VER Bit Fields                           ------ */
#define RNG_VER_MINOR_MASK                       (0xFFUL << RNG_VER_MINOR_SHIFT)                     /*!< RNG_VER: MINOR Mask                     */
#define RNG_VER_MINOR_SHIFT                      0                                                   /*!< RNG_VER: MINOR Position                 */
#define RNG_VER_MINOR(x)                         (((uint32_t)(((uint32_t)(x))<<RNG_VER_MINOR_SHIFT))&RNG_VER_MINOR_MASK) /*!< RNG_VER                                 */
#define RNG_VER_MAJOR_MASK                       (0xFFUL << RNG_VER_MAJOR_SHIFT)                     /*!< RNG_VER: MAJOR Mask                     */
#define RNG_VER_MAJOR_SHIFT                      8                                                   /*!< RNG_VER: MAJOR Position                 */
#define RNG_VER_MAJOR(x)                         (((uint32_t)(((uint32_t)(x))<<RNG_VER_MAJOR_SHIFT))&RNG_VER_MAJOR_MASK) /*!< RNG_VER                                 */
#define RNG_VER_TYPE_MASK                        (0x0FUL << RNG_VER_TYPE_SHIFT)                      /*!< RNG_VER: TYPE Mask                      */
#define RNG_VER_TYPE_SHIFT                       28                                                  /*!< RNG_VER: TYPE Position                  */
#define RNG_VER_TYPE(x)                          (((uint32_t)(((uint32_t)(x))<<RNG_VER_TYPE_SHIFT))&RNG_VER_TYPE_MASK) /*!< RNG_VER                                 */
/* ------- CMD Bit Fields                           ------ */
#define RNG_CMD_ST_MASK                          (0x01UL << RNG_CMD_ST_SHIFT)                        /*!< RNG_CMD: ST Mask                        */
#define RNG_CMD_ST_SHIFT                         0                                                   /*!< RNG_CMD: ST Position                    */
#define RNG_CMD_GS_MASK                          (0x01UL << RNG_CMD_GS_SHIFT)                        /*!< RNG_CMD: GS Mask                        */
#define RNG_CMD_GS_SHIFT                         1                                                   /*!< RNG_CMD: GS Position                    */
#define RNG_CMD_CI_MASK                          (0x01UL << RNG_CMD_CI_SHIFT)                        /*!< RNG_CMD: CI Mask                        */
#define RNG_CMD_CI_SHIFT                         4                                                   /*!< RNG_CMD: CI Position                    */
#define RNG_CMD_CE_MASK                          (0x01UL << RNG_CMD_CE_SHIFT)                        /*!< RNG_CMD: CE Mask                        */
#define RNG_CMD_CE_SHIFT                         5                                                   /*!< RNG_CMD: CE Position                    */
#define RNG_CMD_SR_MASK                          (0x01UL << RNG_CMD_SR_SHIFT)                        /*!< RNG_CMD: SR Mask                        */
#define RNG_CMD_SR_SHIFT                         6                                                   /*!< RNG_CMD: SR Position                    */
/* ------- CR Bit Fields                            ------ */
#define RNG_CR_FUFMOD_MASK                       (0x03UL << RNG_CR_FUFMOD_SHIFT)                     /*!< RNG_CR: FUFMOD Mask                     */
#define RNG_CR_FUFMOD_SHIFT                      0                                                   /*!< RNG_CR: FUFMOD Position                 */
#define RNG_CR_FUFMOD(x)                         (((uint32_t)(((uint32_t)(x))<<RNG_CR_FUFMOD_SHIFT))&RNG_CR_FUFMOD_MASK) /*!< RNG_CR                                  */
#define RNG_CR_AR_MASK                           (0x01UL << RNG_CR_AR_SHIFT)                         /*!< RNG_CR: AR Mask                         */
#define RNG_CR_AR_SHIFT                          4                                                   /*!< RNG_CR: AR Position                     */
#define RNG_CR_MASKDONE_MASK                     (0x01UL << RNG_CR_MASKDONE_SHIFT)                   /*!< RNG_CR: MASKDONE Mask                   */
#define RNG_CR_MASKDONE_SHIFT                    5                                                   /*!< RNG_CR: MASKDONE Position               */
#define RNG_CR_MASKERR_MASK                      (0x01UL << RNG_CR_MASKERR_SHIFT)                    /*!< RNG_CR: MASKERR Mask                    */
#define RNG_CR_MASKERR_SHIFT                     6                                                   /*!< RNG_CR: MASKERR Position                */
/* ------- SR Bit Fields                            ------ */
#define RNG_SR_BUSY_MASK                         (0x01UL << RNG_SR_BUSY_SHIFT)                       /*!< RNG_SR: BUSY Mask                       */
#define RNG_SR_BUSY_SHIFT                        1                                                   /*!< RNG_SR: BUSY Position                   */
#define RNG_SR_SLP_MASK                          (0x01UL << RNG_SR_SLP_SHIFT)                        /*!< RNG_SR: SLP Mask                        */
#define RNG_SR_SLP_SHIFT                         2                                                   /*!< RNG_SR: SLP Position                    */
#define RNG_SR_RS_MASK                           (0x01UL << RNG_SR_RS_SHIFT)                         /*!< RNG_SR: RS Mask                         */
#define RNG_SR_RS_SHIFT                          3                                                   /*!< RNG_SR: RS Position                     */
#define RNG_SR_STDN_MASK                         (0x01UL << RNG_SR_STDN_SHIFT)                       /*!< RNG_SR: STDN Mask                       */
#define RNG_SR_STDN_SHIFT                        4                                                   /*!< RNG_SR: STDN Position                   */
#define RNG_SR_SDN_MASK                          (0x01UL << RNG_SR_SDN_SHIFT)                        /*!< RNG_SR: SDN Mask                        */
#define RNG_SR_SDN_SHIFT                         5                                                   /*!< RNG_SR: SDN Position                    */
#define RNG_SR_NSDN_MASK                         (0x01UL << RNG_SR_NSDN_SHIFT)                       /*!< RNG_SR: NSDN Mask                       */
#define RNG_SR_NSDN_SHIFT                        6                                                   /*!< RNG_SR: NSDN Position                   */
#define RNG_SR_FIFO_LVL_MASK                     (0x0FUL << RNG_SR_FIFO_LVL_SHIFT)                   /*!< RNG_SR: FIFO_LVL Mask                   */
#define RNG_SR_FIFO_LVL_SHIFT                    8                                                   /*!< RNG_SR: FIFO_LVL Position               */
#define RNG_SR_FIFO_LVL(x)                       (((uint32_t)(((uint32_t)(x))<<RNG_SR_FIFO_LVL_SHIFT))&RNG_SR_FIFO_LVL_MASK) /*!< RNG_SR                                  */
#define RNG_SR_FIFO_SIZE_MASK                    (0x0FUL << RNG_SR_FIFO_SIZE_SHIFT)                  /*!< RNG_SR: FIFO_SIZE Mask                  */
#define RNG_SR_FIFO_SIZE_SHIFT                   12                                                  /*!< RNG_SR: FIFO_SIZE Position              */
#define RNG_SR_FIFO_SIZE(x)                      (((uint32_t)(((uint32_t)(x))<<RNG_SR_FIFO_SIZE_SHIFT))&RNG_SR_FIFO_SIZE_MASK) /*!< RNG_SR                                  */
#define RNG_SR_ERR_MASK                          (0x01UL << RNG_SR_ERR_SHIFT)                        /*!< RNG_SR: ERR Mask                        */
#define RNG_SR_ERR_SHIFT                         16                                                  /*!< RNG_SR: ERR Position                    */
#define RNG_SR_ST_PF_MASK                        (0x07UL << RNG_SR_ST_PF_SHIFT)                      /*!< RNG_SR: ST_PF Mask                      */
#define RNG_SR_ST_PF_SHIFT                       21                                                  /*!< RNG_SR: ST_PF Position                  */
#define RNG_SR_ST_PF(x)                          (((uint32_t)(((uint32_t)(x))<<RNG_SR_ST_PF_SHIFT))&RNG_SR_ST_PF_MASK) /*!< RNG_SR                                  */
#define RNG_SR_STATPF_MASK                       (0xFFUL << RNG_SR_STATPF_SHIFT)                     /*!< RNG_SR: STATPF Mask                     */
#define RNG_SR_STATPF_SHIFT                      24                                                  /*!< RNG_SR: STATPF Position                 */
#define RNG_SR_STATPF(x)                         (((uint32_t)(((uint32_t)(x))<<RNG_SR_STATPF_SHIFT))&RNG_SR_STATPF_MASK) /*!< RNG_SR                                  */
/* ------- ESR Bit Fields                           ------ */
#define RNG_ESR_LFE_MASK                         (0x01UL << RNG_ESR_LFE_SHIFT)                       /*!< RNG_ESR: LFE Mask                       */
#define RNG_ESR_LFE_SHIFT                        0                                                   /*!< RNG_ESR: LFE Position                   */
#define RNG_ESR_OSCE_MASK                        (0x01UL << RNG_ESR_OSCE_SHIFT)                      /*!< RNG_ESR: OSCE Mask                      */
#define RNG_ESR_OSCE_SHIFT                       1                                                   /*!< RNG_ESR: OSCE Position                  */
#define RNG_ESR_STE_MASK                         (0x01UL << RNG_ESR_STE_SHIFT)                       /*!< RNG_ESR: STE Mask                       */
#define RNG_ESR_STE_SHIFT                        2                                                   /*!< RNG_ESR: STE Position                   */
#define RNG_ESR_SATE_MASK                        (0x01UL << RNG_ESR_SATE_SHIFT)                      /*!< RNG_ESR: SATE Mask                      */
#define RNG_ESR_SATE_SHIFT                       3                                                   /*!< RNG_ESR: SATE Position                  */
#define RNG_ESR_FUFE_MASK                        (0x01UL << RNG_ESR_FUFE_SHIFT)                      /*!< RNG_ESR: FUFE Mask                      */
#define RNG_ESR_FUFE_SHIFT                       4                                                   /*!< RNG_ESR: FUFE Position                  */
/* ------- OUT Bit Fields                           ------ */
#define RNG_OUT_RANDOUT_MASK                     (0xFFFFFFFFUL << RNG_OUT_RANDOUT_SHIFT)             /*!< RNG_OUT: RANDOUT Mask                   */
#define RNG_OUT_RANDOUT_SHIFT                    0                                                   /*!< RNG_OUT: RANDOUT Position               */
#define RNG_OUT_RANDOUT(x)                       (((uint32_t)(((uint32_t)(x))<<RNG_OUT_RANDOUT_SHIFT))&RNG_OUT_RANDOUT_MASK) /*!< RNG_OUT                                 */
/**
 * @} */ /* End group RNG_Register_Masks_GROUP 
 */

/* RNG - Peripheral instance base addresses */
#define RNG_BasePtr                    0xFFFF98C0UL //!< Peripheral base address
#define RNG                            ((RNG_Type *) RNG_BasePtr) //!< Freescale base pointer
#define RNG_BASE_PTR                   (RNG) //!< Freescale style base pointer
/**
 * @} */ /* End group RNG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer
* @brief C Struct for SIM
* @{
*/

/* ================================================================================ */
/* ================           SIM (file:SIM_MCF51JM)               ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
/**
* @addtogroup SIM_structs_GROUP SIM struct
* @brief Struct for SIM
* @{
*/
typedef struct {                                /*       SIM Structure                                                */
   __IO uint8_t   SOPT1;                        /**< 0000: System Options Register 1                                    */
   __I  uint8_t   SOPT2;                        /**< 0001: System Options Register 2                                    */
   __IO uint8_t   SOPT3;                        /**< 0002: System Options Register 3                                    */
   __IO uint8_t   SOPT4;                        /**< 0003: System Options Register 4                                    */
   __IO uint8_t   SOPT5;                        /**< 0004: System Options Register 5                                    */
   __IO uint8_t   SOPT6;                        /**< 0005: System Options Register 6                                    */
   __IO uint8_t   SOPT7;                        /**< 0006: System Options Register 7                                    */
   __I  uint8_t   RESERVED0[3];                
   __IO uint8_t   COPC;                         /**< 000A: COP Control Register                                         */
   __IO uint8_t   SRVCOP;                       /**< 000B: Service COP Register                                         */
   __I  uint8_t   RESERVED1;                   
   __IO uint8_t   OSC1_CNTRL;                   /**< 000D: Oscillator 1 Control Register                                */
   __I  uint16_t  RESERVED2;                   
   __I  uint8_t   SDIDH;                        /**< 0010: Device Identification High Register                          */
   __I  uint8_t   SDIDL;                        /**< 0011: Device Identification Low Register                           */
   __IO uint8_t   SCGC1;                        /**< 0012: Clock Gate Control Register 1                                */
   __IO uint8_t   SCGC2;                        /**< 0013: Clock Gate Control Register 2                                */
   __IO uint8_t   SCGC3;                        /**< 0014: Clock Gate Control Register 3                                */
   __IO uint8_t   SCGC4;                        /**< 0015: Clock Gate Control Register 4                                */
   __IO uint8_t   SCGC5;                        /**< 0016: Clock Gate Control Register 5                                */
   __IO uint8_t   SCGC6;                        /**< 0017: Clock Gate Control Register 6                                */
   __I  uint16_t  RESERVED3;                   
   __IO uint8_t   CLKOUT;                       /**< 001A: Clock-out Register                                           */
   __IO uint8_t   CLKDIV0;                      /**< 001B: Clock Divider 0 Register                                     */
   __IO uint8_t   CLKDIV1;                      /**< 001C: Clock Divider 1 Register                                     */
   __I  uint8_t   RESERVED4[3];                
   __I  uint8_t   SPCR;                         /**< 0020: Flash Configuration Register                                 */
   __I  uint8_t   RESERVED5[3];                
   __I  uint32_t  UID[4];                       /**< 0024: Unique Identification Register                               */
} SIM_Type;

/**
 * @} */ /* End group SIM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SIM_Register_Masks_GROUP SIM Register Masks
* @brief Register Masks for SIM
* @{
*/
/* ------- SOPT1 Bit Fields                         ------ */
#define SIM_SOPT1_VSTB_MASK                      (0x01UL << SIM_SOPT1_VSTB_SHIFT)                    /*!< SIM_SOPT1: VSTB Mask                    */
#define SIM_SOPT1_VSTB_SHIFT                     5                                                   /*!< SIM_SOPT1: VSTB Position                */
#define SIM_SOPT1_SSTB_MASK                      (0x01UL << SIM_SOPT1_SSTB_SHIFT)                    /*!< SIM_SOPT1: SSTB Mask                    */
#define SIM_SOPT1_SSTB_SHIFT                     6                                                   /*!< SIM_SOPT1: SSTB Position                */
#define SIM_SOPT1_REGE_MASK                      (0x01UL << SIM_SOPT1_REGE_SHIFT)                    /*!< SIM_SOPT1: REGE Mask                    */
#define SIM_SOPT1_REGE_SHIFT                     7                                                   /*!< SIM_SOPT1: REGE Position                */
/* ------- SOPT2 Bit Fields                         ------ */
#define SIM_SOPT2_RAMSIZE_MASK                   (0x0FUL << SIM_SOPT2_RAMSIZE_SHIFT)                 /*!< SIM_SOPT2: RAMSIZE Mask                 */
#define SIM_SOPT2_RAMSIZE_SHIFT                  4                                                   /*!< SIM_SOPT2: RAMSIZE Position             */
#define SIM_SOPT2_RAMSIZE(x)                     (((uint8_t)(((uint8_t)(x))<<SIM_SOPT2_RAMSIZE_SHIFT))&SIM_SOPT2_RAMSIZE_MASK) /*!< SIM_SOPT2                               */
/* ------- SOPT3 Bit Fields                         ------ */
#define SIM_SOPT3_RWE_MASK                       (0x01UL << SIM_SOPT3_RWE_SHIFT)                     /*!< SIM_SOPT3: RWE Mask                     */
#define SIM_SOPT3_RWE_SHIFT                      0                                                   /*!< SIM_SOPT3: RWE Position                 */
#define SIM_SOPT3_UVSWE_MASK                     (0x01UL << SIM_SOPT3_UVSWE_SHIFT)                   /*!< SIM_SOPT3: UVSWE Mask                   */
#define SIM_SOPT3_UVSWE_SHIFT                    1                                                   /*!< SIM_SOPT3: UVSWE Position               */
/* ------- SOPT4 Bit Fields                         ------ */
#define SIM_SOPT4_VLLDBGREQ_MASK                 (0x01UL << SIM_SOPT4_VLLDBGREQ_SHIFT)               /*!< SIM_SOPT4: VLLDBGREQ Mask               */
#define SIM_SOPT4_VLLDBGREQ_SHIFT                0                                                   /*!< SIM_SOPT4: VLLDBGREQ Position           */
#define SIM_SOPT4_WAITE_MASK                     (0x01UL << SIM_SOPT4_WAITE_SHIFT)                   /*!< SIM_SOPT4: WAITE Mask                   */
#define SIM_SOPT4_WAITE_SHIFT                    4                                                   /*!< SIM_SOPT4: WAITE Position               */
#define SIM_SOPT4_STOPE_MASK                     (0x01UL << SIM_SOPT4_STOPE_SHIFT)                   /*!< SIM_SOPT4: STOPE Mask                   */
#define SIM_SOPT4_STOPE_SHIFT                    5                                                   /*!< SIM_SOPT4: STOPE Position               */
/* ------- SOPT5 Bit Fields                         ------ */
#define SIM_SOPT5_F0ECS_MASK                     (0x01UL << SIM_SOPT5_F0ECS_SHIFT)                   /*!< SIM_SOPT5: F0ECS Mask                   */
#define SIM_SOPT5_F0ECS_SHIFT                    0                                                   /*!< SIM_SOPT5: F0ECS Position               */
#define SIM_SOPT5_F1ECS_MASK                     (0x01UL << SIM_SOPT5_F1ECS_SHIFT)                   /*!< SIM_SOPT5: F1ECS Mask                   */
#define SIM_SOPT5_F1ECS_SHIFT                    1                                                   /*!< SIM_SOPT5: F1ECS Position               */
#define SIM_SOPT5_MECS_MASK                      (0x03UL << SIM_SOPT5_MECS_SHIFT)                    /*!< SIM_SOPT5: MECS Mask                    */
#define SIM_SOPT5_MECS_SHIFT                     2                                                   /*!< SIM_SOPT5: MECS Position                */
#define SIM_SOPT5_MECS(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_SOPT5_MECS_SHIFT))&SIM_SOPT5_MECS_MASK) /*!< SIM_SOPT5                               */
/* ------- SOPT6 Bit Fields                         ------ */
#define SIM_SOPT6_PTC5PAD_MASK                   (0x01UL << SIM_SOPT6_PTC5PAD_SHIFT)                 /*!< SIM_SOPT6: PTC5PAD Mask                 */
#define SIM_SOPT6_PTC5PAD_SHIFT                  0                                                   /*!< SIM_SOPT6: PTC5PAD Position             */
#define SIM_SOPT6_PTC6PAD_MASK                   (0x01UL << SIM_SOPT6_PTC6PAD_SHIFT)                 /*!< SIM_SOPT6: PTC6PAD Mask                 */
#define SIM_SOPT6_PTC6PAD_SHIFT                  1                                                   /*!< SIM_SOPT6: PTC6PAD Position             */
#define SIM_SOPT6_MODTX1_MASK                    (0x01UL << SIM_SOPT6_MODTX1_SHIFT)                  /*!< SIM_SOPT6: MODTX1 Mask                  */
#define SIM_SOPT6_MODTX1_SHIFT                   2                                                   /*!< SIM_SOPT6: MODTX1 Position              */
#define SIM_SOPT6_RX1IN_MASK                     (0x01UL << SIM_SOPT6_RX1IN_SHIFT)                   /*!< SIM_SOPT6: RX1IN Mask                   */
#define SIM_SOPT6_RX1IN_SHIFT                    3                                                   /*!< SIM_SOPT6: RX1IN Position               */
#define SIM_SOPT6_MTBASE1_MASK                   (0x03UL << SIM_SOPT6_MTBASE1_SHIFT)                 /*!< SIM_SOPT6: MTBASE1 Mask                 */
#define SIM_SOPT6_MTBASE1_SHIFT                  4                                                   /*!< SIM_SOPT6: MTBASE1 Position             */
#define SIM_SOPT6_MTBASE1(x)                     (((uint8_t)(((uint8_t)(x))<<SIM_SOPT6_MTBASE1_SHIFT))&SIM_SOPT6_MTBASE1_MASK) /*!< SIM_SOPT6                               */
#define SIM_SOPT6_MBSL_MASK                      (0x03UL << SIM_SOPT6_MBSL_SHIFT)                    /*!< SIM_SOPT6: MBSL Mask                    */
#define SIM_SOPT6_MBSL_SHIFT                     6                                                   /*!< SIM_SOPT6: MBSL Position                */
#define SIM_SOPT6_MBSL(x)                        (((uint8_t)(((uint8_t)(x))<<SIM_SOPT6_MBSL_SHIFT))&SIM_SOPT6_MBSL_MASK) /*!< SIM_SOPT6                               */
/* ------- SOPT7 Bit Fields                         ------ */
#define SIM_SOPT7_FTM0SYNC_MASK                  (0x01UL << SIM_SOPT7_FTM0SYNC_SHIFT)                /*!< SIM_SOPT7: FTM0SYNC Mask                */
#define SIM_SOPT7_FTM0SYNC_SHIFT                 0                                                   /*!< SIM_SOPT7: FTM0SYNC Position            */
#define SIM_SOPT7_FTM1SYNC_MASK                  (0x01UL << SIM_SOPT7_FTM1SYNC_SHIFT)                /*!< SIM_SOPT7: FTM1SYNC Mask                */
#define SIM_SOPT7_FTM1SYNC_SHIFT                 1                                                   /*!< SIM_SOPT7: FTM1SYNC Position            */
#define SIM_SOPT7_I2CDR0_MASK                    (0x01UL << SIM_SOPT7_I2CDR0_SHIFT)                  /*!< SIM_SOPT7: I2CDR0 Mask                  */
#define SIM_SOPT7_I2CDR0_SHIFT                   3                                                   /*!< SIM_SOPT7: I2CDR0 Position              */
#define SIM_SOPT7_I2CDR2_MASK                    (0x01UL << SIM_SOPT7_I2CDR2_SHIFT)                  /*!< SIM_SOPT7: I2CDR2 Mask                  */
#define SIM_SOPT7_I2CDR2_SHIFT                   4                                                   /*!< SIM_SOPT7: I2CDR2 Position              */
#define SIM_SOPT7_ACFTM_MASK                     (0x01UL << SIM_SOPT7_ACFTM_SHIFT)                   /*!< SIM_SOPT7: ACFTM Mask                   */
#define SIM_SOPT7_ACFTM_SHIFT                    5                                                   /*!< SIM_SOPT7: ACFTM Position               */
#define SIM_SOPT7_ADTRGS_MASK                    (0x01UL << SIM_SOPT7_ADTRGS_SHIFT)                  /*!< SIM_SOPT7: ADTRGS Mask                  */
#define SIM_SOPT7_ADTRGS_SHIFT                   6                                                   /*!< SIM_SOPT7: ADTRGS Position              */
#define SIM_SOPT7_USBBE_MASK                     (0x01UL << SIM_SOPT7_USBBE_SHIFT)                   /*!< SIM_SOPT7: USBBE Mask                   */
#define SIM_SOPT7_USBBE_SHIFT                    7                                                   /*!< SIM_SOPT7: USBBE Position               */
/* ------- COPC Bit Fields                          ------ */
#define SIM_COPC_COPW_MASK                       (0x01UL << SIM_COPC_COPW_SHIFT)                     /*!< SIM_COPC: COPW Mask                     */
#define SIM_COPC_COPW_SHIFT                      0                                                   /*!< SIM_COPC: COPW Position                 */
#define SIM_COPC_COPCLKS_MASK                    (0x01UL << SIM_COPC_COPCLKS_SHIFT)                  /*!< SIM_COPC: COPCLKS Mask                  */
#define SIM_COPC_COPCLKS_SHIFT                   1                                                   /*!< SIM_COPC: COPCLKS Position              */
#define SIM_COPC_COPT_MASK                       (0x03UL << SIM_COPC_COPT_SHIFT)                     /*!< SIM_COPC: COPT Mask                     */
#define SIM_COPC_COPT_SHIFT                      4                                                   /*!< SIM_COPC: COPT Position                 */
#define SIM_COPC_COPT(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_COPC_COPT_SHIFT))&SIM_COPC_COPT_MASK) /*!< SIM_COPC                                */
/* ------- SRVCOP Bit Fields                        ------ */
/* ------- OSC1_CNTRL Bit Fields                    ------ */
#define SIM_OSC1_OSC1EREFS_MASK                  (0x01UL << SIM_OSC1_OSC1EREFS_SHIFT)                /*!< SIM_OSC1_CNTRL: OSC1EREFS Mask          */
#define SIM_OSC1_OSC1EREFS_SHIFT                 1                                                   /*!< SIM_OSC1_CNTRL: OSC1EREFS Position      */
#define SIM_OSC1_OSC1HGO_MASK                    (0x01UL << SIM_OSC1_OSC1HGO_SHIFT)                  /*!< SIM_OSC1_CNTRL: OSC1HGO Mask            */
#define SIM_OSC1_OSC1HGO_SHIFT                   2                                                   /*!< SIM_OSC1_CNTRL: OSC1HGO Position        */
#define SIM_OSC1_OSC1RANGE_MASK                  (0x03UL << SIM_OSC1_OSC1RANGE_SHIFT)                /*!< SIM_OSC1_CNTRL: OSC1RANGE Mask          */
#define SIM_OSC1_OSC1RANGE_SHIFT                 3                                                   /*!< SIM_OSC1_CNTRL: OSC1RANGE Position      */
#define SIM_OSC1_OSC1RANGE(x)                    (((uint8_t)(((uint8_t)(x))<<SIM_OSC1_OSC1RANGE_SHIFT))&SIM_OSC1_OSC1RANGE_MASK) /*!< SIM_OSC1_CNTRL                          */
#define SIM_OSC1_OSC1EN_MASK                     (0x01UL << SIM_OSC1_OSC1EN_SHIFT)                   /*!< SIM_OSC1_CNTRL: OSC1EN Mask             */
#define SIM_OSC1_OSC1EN_SHIFT                    7                                                   /*!< SIM_OSC1_CNTRL: OSC1EN Position         */
/* ------- SDIDH Bit Fields                         ------ */
/* ------- SDIDL Bit Fields                         ------ */
/* ------- SCGC1 Bit Fields                         ------ */
#define SIM_SCGC1_UART0_MASK                     (0x01UL << SIM_SCGC1_UART0_SHIFT)                   /*!< SIM_SCGC1: UART0 Mask                   */
#define SIM_SCGC1_UART0_SHIFT                    0                                                   /*!< SIM_SCGC1: UART0 Position               */
#define SIM_SCGC1_UART1_MASK                     (0x01UL << SIM_SCGC1_UART1_SHIFT)                   /*!< SIM_SCGC1: UART1 Mask                   */
#define SIM_SCGC1_UART1_SHIFT                    1                                                   /*!< SIM_SCGC1: UART1 Position               */
#define SIM_SCGC1_SPI0_MASK                      (0x01UL << SIM_SCGC1_SPI0_SHIFT)                    /*!< SIM_SCGC1: SPI0 Mask                    */
#define SIM_SCGC1_SPI0_SHIFT                     2                                                   /*!< SIM_SCGC1: SPI0 Position                */
#define SIM_SCGC1_SPI1_MASK                      (0x01UL << SIM_SCGC1_SPI1_SHIFT)                    /*!< SIM_SCGC1: SPI1 Mask                    */
#define SIM_SCGC1_SPI1_SHIFT                     3                                                   /*!< SIM_SCGC1: SPI1 Position                */
#define SIM_SCGC1_I2C0_MASK                      (0x01UL << SIM_SCGC1_I2C0_SHIFT)                    /*!< SIM_SCGC1: I2C0 Mask                    */
#define SIM_SCGC1_I2C0_SHIFT                     4                                                   /*!< SIM_SCGC1: I2C0 Position                */
#define SIM_SCGC1_I2C1_MASK                      (0x01UL << SIM_SCGC1_I2C1_SHIFT)                    /*!< SIM_SCGC1: I2C1 Mask                    */
#define SIM_SCGC1_I2C1_SHIFT                     5                                                   /*!< SIM_SCGC1: I2C1 Position                */
#define SIM_SCGC1_I2C2_MASK                      (0x01UL << SIM_SCGC1_I2C2_SHIFT)                    /*!< SIM_SCGC1: I2C2 Mask                    */
#define SIM_SCGC1_I2C2_SHIFT                     6                                                   /*!< SIM_SCGC1: I2C2 Position                */
#define SIM_SCGC1_I2C3_MASK                      (0x01UL << SIM_SCGC1_I2C3_SHIFT)                    /*!< SIM_SCGC1: I2C3 Mask                    */
#define SIM_SCGC1_I2C3_SHIFT                     7                                                   /*!< SIM_SCGC1: I2C3 Position                */
/* ------- SCGC2 Bit Fields                         ------ */
#define SIM_SCGC2_DAC12B_MASK                    (0x01UL << SIM_SCGC2_DAC12B_SHIFT)                  /*!< SIM_SCGC2: DAC12B Mask                  */
#define SIM_SCGC2_DAC12B_SHIFT                   0                                                   /*!< SIM_SCGC2: DAC12B Position              */
#define SIM_SCGC2_ADC_MASK                       (0x01UL << SIM_SCGC2_ADC_SHIFT)                     /*!< SIM_SCGC2: ADC Mask                     */
#define SIM_SCGC2_ADC_SHIFT                      1                                                   /*!< SIM_SCGC2: ADC Position                 */
#define SIM_SCGC2_VREF_MASK                      (0x01UL << SIM_SCGC2_VREF_SHIFT)                    /*!< SIM_SCGC2: VREF Mask                    */
#define SIM_SCGC2_VREF_SHIFT                     4                                                   /*!< SIM_SCGC2: VREF Position                */
#define SIM_SCGC2_TSI_MASK                       (0x01UL << SIM_SCGC2_TSI_SHIFT)                     /*!< SIM_SCGC2: TSI Mask                     */
#define SIM_SCGC2_TSI_SHIFT                      5                                                   /*!< SIM_SCGC2: TSI Position                 */
#define SIM_SCGC2_CMP_MASK                       (0x01UL << SIM_SCGC2_CMP_SHIFT)                     /*!< SIM_SCGC2: CMP Mask                     */
#define SIM_SCGC2_CMP_SHIFT                      6                                                   /*!< SIM_SCGC2: CMP Position                 */
#define SIM_SCGC2_I2S_MASK                       (0x01UL << SIM_SCGC2_I2S_SHIFT)                     /*!< SIM_SCGC2: I2S Mask                     */
#define SIM_SCGC2_I2S_SHIFT                      7                                                   /*!< SIM_SCGC2: I2S Position                 */
/* ------- SCGC3 Bit Fields                         ------ */
#define SIM_SCGC3_FTM0_MASK                      (0x01UL << SIM_SCGC3_FTM0_SHIFT)                    /*!< SIM_SCGC3: FTM0 Mask                    */
#define SIM_SCGC3_FTM0_SHIFT                     2                                                   /*!< SIM_SCGC3: FTM0 Position                */
#define SIM_SCGC3_FTM1_MASK                      (0x01UL << SIM_SCGC3_FTM1_SHIFT)                    /*!< SIM_SCGC3: FTM1 Mask                    */
#define SIM_SCGC3_FTM1_SHIFT                     3                                                   /*!< SIM_SCGC3: FTM1 Position                */
#define SIM_SCGC3_MTIM_MASK                      (0x01UL << SIM_SCGC3_MTIM_SHIFT)                    /*!< SIM_SCGC3: MTIM Mask                    */
#define SIM_SCGC3_MTIM_SHIFT                     4                                                   /*!< SIM_SCGC3: MTIM Position                */
#define SIM_SCGC3_CMT_MASK                       (0x01UL << SIM_SCGC3_CMT_SHIFT)                     /*!< SIM_SCGC3: CMT Mask                     */
#define SIM_SCGC3_CMT_SHIFT                      5                                                   /*!< SIM_SCGC3: CMT Position                 */
#define SIM_SCGC3_PDB_MASK                       (0x01UL << SIM_SCGC3_PDB_SHIFT)                     /*!< SIM_SCGC3: PDB Mask                     */
#define SIM_SCGC3_PDB_SHIFT                      6                                                   /*!< SIM_SCGC3: PDB Position                 */
#define SIM_SCGC3_CRC_MASK                       (0x01UL << SIM_SCGC3_CRC_SHIFT)                     /*!< SIM_SCGC3: CRC Mask                     */
#define SIM_SCGC3_CRC_SHIFT                      7                                                   /*!< SIM_SCGC3: CRC Position                 */
/* ------- SCGC4 Bit Fields                         ------ */
#define SIM_SCGC4_WDOG_MASK                      (0x01UL << SIM_SCGC4_WDOG_SHIFT)                    /*!< SIM_SCGC4: WDOG Mask                    */
#define SIM_SCGC4_WDOG_SHIFT                     0                                                   /*!< SIM_SCGC4: WDOG Position                */
#define SIM_SCGC4_IRQ_MASK                       (0x01UL << SIM_SCGC4_IRQ_SHIFT)                     /*!< SIM_SCGC4: IRQ Mask                     */
#define SIM_SCGC4_IRQ_SHIFT                      1                                                   /*!< SIM_SCGC4: IRQ Position                 */
#define SIM_SCGC4_DMA_MASK                       (0x01UL << SIM_SCGC4_DMA_SHIFT)                     /*!< SIM_SCGC4: DMA Mask                     */
#define SIM_SCGC4_DMA_SHIFT                      3                                                   /*!< SIM_SCGC4: DMA Position                 */
#define SIM_SCGC4_FTFL_MASK                      (0x01UL << SIM_SCGC4_FTFL_SHIFT)                    /*!< SIM_SCGC4: FTFL Mask                    */
#define SIM_SCGC4_FTFL_SHIFT                     7                                                   /*!< SIM_SCGC4: FTFL Position                */
/* ------- SCGC5 Bit Fields                         ------ */
#define SIM_SCGC5_MCG_MASK                       (0x01UL << SIM_SCGC5_MCG_SHIFT)                     /*!< SIM_SCGC5: MCG Mask                     */
#define SIM_SCGC5_MCG_SHIFT                      0                                                   /*!< SIM_SCGC5: MCG Position                 */
#define SIM_SCGC5_OSC1_MASK                      (0x01UL << SIM_SCGC5_OSC1_SHIFT)                    /*!< SIM_SCGC5: OSC1 Mask                    */
#define SIM_SCGC5_OSC1_SHIFT                     1                                                   /*!< SIM_SCGC5: OSC1 Position                */
#define SIM_SCGC5_OSC2_MASK                      (0x01UL << SIM_SCGC5_OSC2_SHIFT)                    /*!< SIM_SCGC5: OSC2 Mask                    */
#define SIM_SCGC5_OSC2_SHIFT                     2                                                   /*!< SIM_SCGC5: OSC2 Position                */
#define SIM_SCGC5_MFBUS_MASK                     (0x01UL << SIM_SCGC5_MFBUS_SHIFT)                   /*!< SIM_SCGC5: MFBUS Mask                   */
#define SIM_SCGC5_MFBUS_SHIFT                    6                                                   /*!< SIM_SCGC5: MFBUS Position               */
#define SIM_SCGC5_RNGB_MASK                      (0x01UL << SIM_SCGC5_RNGB_SHIFT)                    /*!< SIM_SCGC5: RNGB Mask                    */
#define SIM_SCGC5_RNGB_SHIFT                     7                                                   /*!< SIM_SCGC5: RNGB Position                */
/* ------- SCGC6 Bit Fields                         ------ */
#define SIM_SCGC6_PORTA_MASK                     (0x01UL << SIM_SCGC6_PORTA_SHIFT)                   /*!< SIM_SCGC6: PORTA Mask                   */
#define SIM_SCGC6_PORTA_SHIFT                    0                                                   /*!< SIM_SCGC6: PORTA Position               */
#define SIM_SCGC6_PORTB_MASK                     (0x01UL << SIM_SCGC6_PORTB_SHIFT)                   /*!< SIM_SCGC6: PORTB Mask                   */
#define SIM_SCGC6_PORTB_SHIFT                    1                                                   /*!< SIM_SCGC6: PORTB Position               */
#define SIM_SCGC6_PORTC_MASK                     (0x01UL << SIM_SCGC6_PORTC_SHIFT)                   /*!< SIM_SCGC6: PORTC Mask                   */
#define SIM_SCGC6_PORTC_SHIFT                    2                                                   /*!< SIM_SCGC6: PORTC Position               */
#define SIM_SCGC6_PORTD_MASK                     (0x01UL << SIM_SCGC6_PORTD_SHIFT)                   /*!< SIM_SCGC6: PORTD Mask                   */
#define SIM_SCGC6_PORTD_SHIFT                    3                                                   /*!< SIM_SCGC6: PORTD Position               */
#define SIM_SCGC6_PORTE_MASK                     (0x01UL << SIM_SCGC6_PORTE_SHIFT)                   /*!< SIM_SCGC6: PORTE Mask                   */
#define SIM_SCGC6_PORTE_SHIFT                    4                                                   /*!< SIM_SCGC6: PORTE Position               */
#define SIM_SCGC6_PORTF_MASK                     (0x01UL << SIM_SCGC6_PORTF_SHIFT)                   /*!< SIM_SCGC6: PORTF Mask                   */
#define SIM_SCGC6_PORTF_SHIFT                    5                                                   /*!< SIM_SCGC6: PORTF Position               */
#define SIM_SCGC6_USBDCD_MASK                    (0x01UL << SIM_SCGC6_USBDCD_SHIFT)                  /*!< SIM_SCGC6: USBDCD Mask                  */
#define SIM_SCGC6_USBDCD_SHIFT                   6                                                   /*!< SIM_SCGC6: USBDCD Position              */
#define SIM_SCGC6_USBOTG_MASK                    (0x01UL << SIM_SCGC6_USBOTG_SHIFT)                  /*!< SIM_SCGC6: USBOTG Mask                  */
#define SIM_SCGC6_USBOTG_SHIFT                   7                                                   /*!< SIM_SCGC6: USBOTG Position              */
/* ------- CLKOUT Bit Fields                        ------ */
#define SIM_CLKOUT_CLKOUTDIV_MASK                (0x07UL << SIM_CLKOUT_CLKOUTDIV_SHIFT)              /*!< SIM_CLKOUT: CLKOUTDIV Mask              */
#define SIM_CLKOUT_CLKOUTDIV_SHIFT               0                                                   /*!< SIM_CLKOUT: CLKOUTDIV Position          */
#define SIM_CLKOUT_CLKOUTDIV(x)                  (((uint8_t)(((uint8_t)(x))<<SIM_CLKOUT_CLKOUTDIV_SHIFT))&SIM_CLKOUT_CLKOUTDIV_MASK) /*!< SIM_CLKOUT                              */
#define SIM_CLKOUT_CS_MASK                       (0x07UL << SIM_CLKOUT_CS_SHIFT)                     /*!< SIM_CLKOUT: CS Mask                     */
#define SIM_CLKOUT_CS_SHIFT                      4                                                   /*!< SIM_CLKOUT: CS Position                 */
#define SIM_CLKOUT_CS(x)                         (((uint8_t)(((uint8_t)(x))<<SIM_CLKOUT_CS_SHIFT))&SIM_CLKOUT_CS_MASK) /*!< SIM_CLKOUT                              */
/* ------- CLKDIV0 Bit Fields                       ------ */
#define SIM_CLKDIV0_OUTDIV_MASK                  (0x0FUL << SIM_CLKDIV0_OUTDIV_SHIFT)                /*!< SIM_CLKDIV0: OUTDIV Mask                */
#define SIM_CLKDIV0_OUTDIV_SHIFT                 0                                                   /*!< SIM_CLKDIV0: OUTDIV Position            */
#define SIM_CLKDIV0_OUTDIV(x)                    (((uint8_t)(((uint8_t)(x))<<SIM_CLKDIV0_OUTDIV_SHIFT))&SIM_CLKDIV0_OUTDIV_MASK) /*!< SIM_CLKDIV0                             */
/* ------- CLKDIV1 Bit Fields                       ------ */
#define SIM_CLKDIV1_USBSRC_MASK                  (0x03UL << SIM_CLKDIV1_USBSRC_SHIFT)                /*!< SIM_CLKDIV1: USBSRC Mask                */
#define SIM_CLKDIV1_USBSRC_SHIFT                 0                                                   /*!< SIM_CLKDIV1: USBSRC Position            */
#define SIM_CLKDIV1_USBSRC(x)                    (((uint8_t)(((uint8_t)(x))<<SIM_CLKDIV1_USBSRC_SHIFT))&SIM_CLKDIV1_USBSRC_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_USBFRAC_MASK                 (0x01UL << SIM_CLKDIV1_USBFRAC_SHIFT)               /*!< SIM_CLKDIV1: USBFRAC Mask               */
#define SIM_CLKDIV1_USBFRAC_SHIFT                4                                                   /*!< SIM_CLKDIV1: USBFRAC Position           */
#define SIM_CLKDIV1_USBDIV_MASK                  (0x07UL << SIM_CLKDIV1_USBDIV_SHIFT)                /*!< SIM_CLKDIV1: USBDIV Mask                */
#define SIM_CLKDIV1_USBDIV_SHIFT                 5                                                   /*!< SIM_CLKDIV1: USBDIV Position            */
#define SIM_CLKDIV1_USBDIV(x)                    (((uint8_t)(((uint8_t)(x))<<SIM_CLKDIV1_USBDIV_SHIFT))&SIM_CLKDIV1_USBDIV_MASK) /*!< SIM_CLKDIV1                             */
/* ------- SPCR Bit Fields                          ------ */
#define SIM_SPCR_PFSIZE_MASK                     (0x0FUL << SIM_SPCR_PFSIZE_SHIFT)                   /*!< SIM_SPCR: PFSIZE Mask                   */
#define SIM_SPCR_PFSIZE_SHIFT                    0                                                   /*!< SIM_SPCR: PFSIZE Position               */
#define SIM_SPCR_PFSIZE(x)                       (((uint8_t)(((uint8_t)(x))<<SIM_SPCR_PFSIZE_SHIFT))&SIM_SPCR_PFSIZE_MASK) /*!< SIM_SPCR                                */
#define SIM_SPCR_NVMSIZE_MASK                    (0x0FUL << SIM_SPCR_NVMSIZE_SHIFT)                  /*!< SIM_SPCR: NVMSIZE Mask                  */
#define SIM_SPCR_NVMSIZE_SHIFT                   4                                                   /*!< SIM_SPCR: NVMSIZE Position              */
#define SIM_SPCR_NVMSIZE(x)                      (((uint8_t)(((uint8_t)(x))<<SIM_SPCR_NVMSIZE_SHIFT))&SIM_SPCR_NVMSIZE_MASK) /*!< SIM_SPCR                                */
/* ------- UID Bit Fields                           ------ */
/**
 * @} */ /* End group SIM_Register_Masks_GROUP 
 */

/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0xFFFF80C0UL //!< Peripheral base address
#define SIM                            ((SIM_Type *) SIM_BasePtr) //!< Freescale base pointer
#define SIM_BASE_PTR                   (SIM) //!< Freescale style base pointer
/**
 * @} */ /* End group SIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SMC_Peripheral_access_layer_GROUP SMC Peripheral Access Layer
* @brief C Struct for SMC
* @{
*/

/* ================================================================================ */
/* ================           SMC (file:SMC_MCF51)                 ================ */
/* ================================================================================ */

/**
 * @brief System Mode Controller
 */
/**
* @addtogroup SMC_structs_GROUP SMC struct
* @brief Struct for SMC
* @{
*/
typedef struct {                                /*       SMC Structure                                                */
   __IO uint8_t   PMPROT;                       /**< 0000: Power Mode Protection Register                               */
   __IO uint8_t   PMCTRL;                       /**< 0001: Power Mode Control Register                                  */
   __IO uint8_t   VLLSCTRL;                     /**< 0002: VLLS Control Register                                        */
   __I  uint8_t   PMSTAT;                       /**< 0003: Power Mode Status Register                                   */
} SMC_Type;

/**
 * @} */ /* End group SMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SMC_Register_Masks_GROUP SMC Register Masks
* @brief Register Masks for SMC
* @{
*/
/* ------- PMPROT Bit Fields                        ------ */
#define SMC_PMPROT_AVLLS_MASK                    (0x01UL << SMC_PMPROT_AVLLS_SHIFT)                  /*!< SMC_PMPROT: AVLLS Mask                  */
#define SMC_PMPROT_AVLLS_SHIFT                   1                                                   /*!< SMC_PMPROT: AVLLS Position              */
#define SMC_PMPROT_ALLS_MASK                     (0x01UL << SMC_PMPROT_ALLS_SHIFT)                   /*!< SMC_PMPROT: ALLS Mask                   */
#define SMC_PMPROT_ALLS_SHIFT                    3                                                   /*!< SMC_PMPROT: ALLS Position               */
#define SMC_PMPROT_AVLP_MASK                     (0x01UL << SMC_PMPROT_AVLP_SHIFT)                   /*!< SMC_PMPROT: AVLP Mask                   */
#define SMC_PMPROT_AVLP_SHIFT                    5                                                   /*!< SMC_PMPROT: AVLP Position               */
/* ------- PMCTRL Bit Fields                        ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x07UL << SMC_PMCTRL_STOPM_SHIFT)                  /*!< SMC_PMCTRL: STOPM Mask                  */
#define SMC_PMCTRL_STOPM_SHIFT                   0                                                   /*!< SMC_PMCTRL: STOPM Position              */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_STOPA_MASK                    (0x01UL << SMC_PMCTRL_STOPA_SHIFT)                  /*!< SMC_PMCTRL: STOPA Mask                  */
#define SMC_PMCTRL_STOPA_SHIFT                   3                                                   /*!< SMC_PMCTRL: STOPA Position              */
#define SMC_PMCTRL_RUNM_MASK                     (0x03UL << SMC_PMCTRL_RUNM_SHIFT)                   /*!< SMC_PMCTRL: RUNM Mask                   */
#define SMC_PMCTRL_RUNM_SHIFT                    5                                                   /*!< SMC_PMCTRL: RUNM Position               */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_LPWUI_MASK                    (0x01UL << SMC_PMCTRL_LPWUI_SHIFT)                  /*!< SMC_PMCTRL: LPWUI Mask                  */
#define SMC_PMCTRL_LPWUI_SHIFT                   7                                                   /*!< SMC_PMCTRL: LPWUI Position              */
/* ------- VLLSCTRL Bit Fields                      ------ */
#define SMC_VLLSCTRL_VLLSM_MASK                  (0x07UL << SMC_VLLSCTRL_VLLSM_SHIFT)                /*!< SMC_VLLSCTRL: VLLSM Mask                */
#define SMC_VLLSCTRL_VLLSM_SHIFT                 0                                                   /*!< SMC_VLLSCTRL: VLLSM Position            */
#define SMC_VLLSCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_VLLSM_SHIFT))&SMC_VLLSCTRL_VLLSM_MASK) /*!< SMC_VLLSCTRL                            */
#define SMC_VLLSCTRL_PORPO_MASK                  (0x01UL << SMC_VLLSCTRL_PORPO_SHIFT)                /*!< SMC_VLLSCTRL: PORPO Mask                */
#define SMC_VLLSCTRL_PORPO_SHIFT                 5                                                   /*!< SMC_VLLSCTRL: PORPO Position            */
/* ------- PMSTAT Bit Fields                        ------ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0x7FUL << SMC_PMSTAT_PMSTAT_SHIFT)                 /*!< SMC_PMSTAT: PMSTAT Mask                 */
#define SMC_PMSTAT_PMSTAT_SHIFT                  0                                                   /*!< SMC_PMSTAT: PMSTAT Position             */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK) /*!< SMC_PMSTAT                              */
/**
 * @} */ /* End group SMC_Register_Masks_GROUP 
 */

/* SMC - Peripheral instance base addresses */
#define SMC_BasePtr                    0xFFFF8118UL //!< Peripheral base address
#define SMC                            ((SMC_Type *) SMC_BasePtr) //!< Freescale base pointer
#define SMC_BASE_PTR                   (SMC) //!< Freescale style base pointer
/**
 * @} */ /* End group SMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI0 (file:SPI0_MCF51_FIFO)          ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
/**
* @addtogroup SPI_structs_GROUP SPI struct
* @brief Struct for SPI
* @{
*/
typedef struct {                                /*       SPI0 Structure                                               */
   __IO uint8_t   C1;                           /**< 0000: Control register 1                                           */
   __IO uint8_t   C2;                           /**< 0001: Control register 2                                           */
   __IO uint8_t   BR;                           /**< 0002: SPI baud rate register                                       */
   __I  uint8_t   S;                            /**< 0003: Status register                                              */
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  D;                         /**< 0004: Data register                                                */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   DH;                     /**< 0004: Data register low                                            */
         __IO uint8_t   DL;                     /**< 0005: Data register high                                           */
      };
   };
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  M;                         /**< 0006: Match register                                               */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   MH;                     /**< 0006: Match register high                                          */
         __IO uint8_t   ML;                     /**< 0007: Match register low                                           */
      };
   };
   __IO uint8_t   C3;                           /**< 0008: Control register 3                                           */
   __IO uint8_t   CI;                           /**< 0009: Clear interrupt register                                     */
} SPI_Type;

/**
 * @} */ /* End group SPI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SPI_Register_Masks_GROUP SPI Register Masks
* @brief Register Masks for SPI
* @{
*/
/* ------- C1 Bit Fields                            ------ */
#define SPI_C1_LSBFE_MASK                        (0x01UL << SPI_C1_LSBFE_SHIFT)                      /*!< SPI0_C1: LSBFE Mask                     */
#define SPI_C1_LSBFE_SHIFT                       0                                                   /*!< SPI0_C1: LSBFE Position                 */
#define SPI_C1_SSOE_MASK                         (0x01UL << SPI_C1_SSOE_SHIFT)                       /*!< SPI0_C1: SSOE Mask                      */
#define SPI_C1_SSOE_SHIFT                        1                                                   /*!< SPI0_C1: SSOE Position                  */
#define SPI_C1_CPHA_MASK                         (0x01UL << SPI_C1_CPHA_SHIFT)                       /*!< SPI0_C1: CPHA Mask                      */
#define SPI_C1_CPHA_SHIFT                        2                                                   /*!< SPI0_C1: CPHA Position                  */
#define SPI_C1_CPOL_MASK                         (0x01UL << SPI_C1_CPOL_SHIFT)                       /*!< SPI0_C1: CPOL Mask                      */
#define SPI_C1_CPOL_SHIFT                        3                                                   /*!< SPI0_C1: CPOL Position                  */
#define SPI_C1_MSTR_MASK                         (0x01UL << SPI_C1_MSTR_SHIFT)                       /*!< SPI0_C1: MSTR Mask                      */
#define SPI_C1_MSTR_SHIFT                        4                                                   /*!< SPI0_C1: MSTR Position                  */
#define SPI_C1_SPTIE_MASK                        (0x01UL << SPI_C1_SPTIE_SHIFT)                      /*!< SPI0_C1: SPTIE Mask                     */
#define SPI_C1_SPTIE_SHIFT                       5                                                   /*!< SPI0_C1: SPTIE Position                 */
#define SPI_C1_SPE_MASK                          (0x01UL << SPI_C1_SPE_SHIFT)                        /*!< SPI0_C1: SPE Mask                       */
#define SPI_C1_SPE_SHIFT                         6                                                   /*!< SPI0_C1: SPE Position                   */
#define SPI_C1_SPIE_MASK                         (0x01UL << SPI_C1_SPIE_SHIFT)                       /*!< SPI0_C1: SPIE Mask                      */
#define SPI_C1_SPIE_SHIFT                        7                                                   /*!< SPI0_C1: SPIE Position                  */
/* ------- C2 Bit Fields                            ------ */
#define SPI_C2_SPC0_MASK                         (0x01UL << SPI_C2_SPC0_SHIFT)                       /*!< SPI0_C2: SPC0 Mask                      */
#define SPI_C2_SPC0_SHIFT                        0                                                   /*!< SPI0_C2: SPC0 Position                  */
#define SPI_C2_SPISWAI_MASK                      (0x01UL << SPI_C2_SPISWAI_SHIFT)                    /*!< SPI0_C2: SPISWAI Mask                   */
#define SPI_C2_SPISWAI_SHIFT                     1                                                   /*!< SPI0_C2: SPISWAI Position               */
#define SPI_C2_RXDMAE_MASK                       (0x01UL << SPI_C2_RXDMAE_SHIFT)                     /*!< SPI0_C2: RXDMAE Mask                    */
#define SPI_C2_RXDMAE_SHIFT                      2                                                   /*!< SPI0_C2: RXDMAE Position                */
#define SPI_C2_BIDIROE_MASK                      (0x01UL << SPI_C2_BIDIROE_SHIFT)                    /*!< SPI0_C2: BIDIROE Mask                   */
#define SPI_C2_BIDIROE_SHIFT                     3                                                   /*!< SPI0_C2: BIDIROE Position               */
#define SPI_C2_MODFEN_MASK                       (0x01UL << SPI_C2_MODFEN_SHIFT)                     /*!< SPI0_C2: MODFEN Mask                    */
#define SPI_C2_MODFEN_SHIFT                      4                                                   /*!< SPI0_C2: MODFEN Position                */
#define SPI_C2_TXDMAE_MASK                       (0x01UL << SPI_C2_TXDMAE_SHIFT)                     /*!< SPI0_C2: TXDMAE Mask                    */
#define SPI_C2_TXDMAE_SHIFT                      5                                                   /*!< SPI0_C2: TXDMAE Position                */
#define SPI_C2_SPIMODE_MASK                      (0x01UL << SPI_C2_SPIMODE_SHIFT)                    /*!< SPI0_C2: SPIMODE Mask                   */
#define SPI_C2_SPIMODE_SHIFT                     6                                                   /*!< SPI0_C2: SPIMODE Position               */
#define SPI_C2_SPMIE_MASK                        (0x01UL << SPI_C2_SPMIE_SHIFT)                      /*!< SPI0_C2: SPMIE Mask                     */
#define SPI_C2_SPMIE_SHIFT                       7                                                   /*!< SPI0_C2: SPMIE Position                 */
/* ------- BR Bit Fields                            ------ */
#define SPI_BR_SPR_MASK                          (0x0FUL << SPI_BR_SPR_SHIFT)                        /*!< SPI0_BR: SPR Mask                       */
#define SPI_BR_SPR_SHIFT                         0                                                   /*!< SPI0_BR: SPR Position                   */
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK) /*!< SPI0_BR                                 */
#define SPI_BR_SPPR_MASK                         (0x07UL << SPI_BR_SPPR_SHIFT)                       /*!< SPI0_BR: SPPR Mask                      */
#define SPI_BR_SPPR_SHIFT                        4                                                   /*!< SPI0_BR: SPPR Position                  */
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK) /*!< SPI0_BR                                 */
/* ------- S Bit Fields                             ------ */
#define SPI_S_RFIFOEF_MASK                       (0x01UL << SPI_S_RFIFOEF_SHIFT)                     /*!< SPI0_S: RFIFOEF Mask                    */
#define SPI_S_RFIFOEF_SHIFT                      0                                                   /*!< SPI0_S: RFIFOEF Position                */
#define SPI_S_TXFULLF_MASK                       (0x01UL << SPI_S_TXFULLF_SHIFT)                     /*!< SPI0_S: TXFULLF Mask                    */
#define SPI_S_TXFULLF_SHIFT                      1                                                   /*!< SPI0_S: TXFULLF Position                */
#define SPI_S_TNEAREF_MASK                       (0x01UL << SPI_S_TNEAREF_SHIFT)                     /*!< SPI0_S: TNEAREF Mask                    */
#define SPI_S_TNEAREF_SHIFT                      2                                                   /*!< SPI0_S: TNEAREF Position                */
#define SPI_S_RNFULLF_MASK                       (0x01UL << SPI_S_RNFULLF_SHIFT)                     /*!< SPI0_S: RNFULLF Mask                    */
#define SPI_S_RNFULLF_SHIFT                      3                                                   /*!< SPI0_S: RNFULLF Position                */
#define SPI_S_MODF_MASK                          (0x01UL << SPI_S_MODF_SHIFT)                        /*!< SPI0_S: MODF Mask                       */
#define SPI_S_MODF_SHIFT                         4                                                   /*!< SPI0_S: MODF Position                   */
#define SPI_S_SPTEF_MASK                         (0x01UL << SPI_S_SPTEF_SHIFT)                       /*!< SPI0_S: SPTEF Mask                      */
#define SPI_S_SPTEF_SHIFT                        5                                                   /*!< SPI0_S: SPTEF Position                  */
#define SPI_S_SPMF_MASK                          (0x01UL << SPI_S_SPMF_SHIFT)                        /*!< SPI0_S: SPMF Mask                       */
#define SPI_S_SPMF_SHIFT                         6                                                   /*!< SPI0_S: SPMF Position                   */
#define SPI_S_SPRF_MASK                          (0x01UL << SPI_S_SPRF_SHIFT)                        /*!< SPI0_S: SPRF Mask                       */
#define SPI_S_SPRF_SHIFT                         7                                                   /*!< SPI0_S: SPRF Position                   */
/* ------- D Bit Fields                             ------ */
#define SPI_D_Bits_MASK                          (0xFFFFUL << SPI_D_Bits_SHIFT)                      /*!< SPI0_D: Bits Mask                       */
#define SPI_D_Bits_SHIFT                         0                                                   /*!< SPI0_D: Bits Position                   */
#define SPI_D_Bits(x)                            (((uint16_t)(((uint16_t)(x))<<SPI_D_Bits_SHIFT))&SPI_D_Bits_MASK) /*!< SPI0_D                                  */
/* ------- DH Bit Fields                            ------ */
#define SPI_DH_Bits_MASK                         (0xFFUL << SPI_DH_Bits_SHIFT)                       /*!< SPI0_DH: Bits Mask                      */
#define SPI_DH_Bits_SHIFT                        0                                                   /*!< SPI0_DH: Bits Position                  */
#define SPI_DH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DH_Bits_SHIFT))&SPI_DH_Bits_MASK) /*!< SPI0_DH                                 */
/* ------- DL Bit Fields                            ------ */
#define SPI_DL_Bits_MASK                         (0xFFUL << SPI_DL_Bits_SHIFT)                       /*!< SPI0_DL: Bits Mask                      */
#define SPI_DL_Bits_SHIFT                        0                                                   /*!< SPI0_DL: Bits Position                  */
#define SPI_DL_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DL_Bits_SHIFT))&SPI_DL_Bits_MASK) /*!< SPI0_DL                                 */
/* ------- M Bit Fields                             ------ */
#define SPI_M_Bits_MASK                          (0xFFFFUL << SPI_M_Bits_SHIFT)                      /*!< SPI0_M: Bits Mask                       */
#define SPI_M_Bits_SHIFT                         0                                                   /*!< SPI0_M: Bits Position                   */
#define SPI_M_Bits(x)                            (((uint16_t)(((uint16_t)(x))<<SPI_M_Bits_SHIFT))&SPI_M_Bits_MASK) /*!< SPI0_M                                  */
/* ------- MH Bit Fields                            ------ */
#define SPI_MH_Bits_MASK                         (0xFFUL << SPI_MH_Bits_SHIFT)                       /*!< SPI0_MH: Bits Mask                      */
#define SPI_MH_Bits_SHIFT                        0                                                   /*!< SPI0_MH: Bits Position                  */
#define SPI_MH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_MH_Bits_SHIFT))&SPI_MH_Bits_MASK) /*!< SPI0_MH                                 */
/* ------- ML Bit Fields                            ------ */
#define SPI_ML_Bits_MASK                         (0xFFUL << SPI_ML_Bits_SHIFT)                       /*!< SPI0_ML: Bits Mask                      */
#define SPI_ML_Bits_SHIFT                        0                                                   /*!< SPI0_ML: Bits Position                  */
#define SPI_ML_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_ML_Bits_SHIFT))&SPI_ML_Bits_MASK) /*!< SPI0_ML                                 */
/* ------- C3 Bit Fields                            ------ */
#define SPI_C3_FIFOMODE_MASK                     (0x01UL << SPI_C3_FIFOMODE_SHIFT)                   /*!< SPI0_C3: FIFOMODE Mask                  */
#define SPI_C3_FIFOMODE_SHIFT                    0                                                   /*!< SPI0_C3: FIFOMODE Position              */
#define SPI_C3_RNFULLIEN_MASK                    (0x01UL << SPI_C3_RNFULLIEN_SHIFT)                  /*!< SPI0_C3: RNFULLIEN Mask                 */
#define SPI_C3_RNFULLIEN_SHIFT                   1                                                   /*!< SPI0_C3: RNFULLIEN Position             */
#define SPI_C3_TNEARIEN_MASK                     (0x01UL << SPI_C3_TNEARIEN_SHIFT)                   /*!< SPI0_C3: TNEARIEN Mask                  */
#define SPI_C3_TNEARIEN_SHIFT                    2                                                   /*!< SPI0_C3: TNEARIEN Position              */
#define SPI_C3_INTCLR_MASK                       (0x01UL << SPI_C3_INTCLR_SHIFT)                     /*!< SPI0_C3: INTCLR Mask                    */
#define SPI_C3_INTCLR_SHIFT                      3                                                   /*!< SPI0_C3: INTCLR Position                */
#define SPI_C3_RNFULLF_MARK_MASK                 (0x01UL << SPI_C3_RNFULLF_MARK_SHIFT)               /*!< SPI0_C3: RNFULLF_MARK Mask              */
#define SPI_C3_RNFULLF_MARK_SHIFT                4                                                   /*!< SPI0_C3: RNFULLF_MARK Position          */
#define SPI_C3_TNEAREF_MARK_MASK                 (0x01UL << SPI_C3_TNEAREF_MARK_SHIFT)               /*!< SPI0_C3: TNEAREF_MARK Mask              */
#define SPI_C3_TNEAREF_MARK_SHIFT                5                                                   /*!< SPI0_C3: TNEAREF_MARK Position          */
/* ------- CI Bit Fields                            ------ */
#define SPI_CI_SPRFCI_MASK                       (0x01UL << SPI_CI_SPRFCI_SHIFT)                     /*!< SPI0_CI: SPRFCI Mask                    */
#define SPI_CI_SPRFCI_SHIFT                      0                                                   /*!< SPI0_CI: SPRFCI Position                */
#define SPI_CI_SPTEFCI_MASK                      (0x01UL << SPI_CI_SPTEFCI_SHIFT)                    /*!< SPI0_CI: SPTEFCI Mask                   */
#define SPI_CI_SPTEFCI_SHIFT                     1                                                   /*!< SPI0_CI: SPTEFCI Position               */
#define SPI_CI_RNFULLFCI_MASK                    (0x01UL << SPI_CI_RNFULLFCI_SHIFT)                  /*!< SPI0_CI: RNFULLFCI Mask                 */
#define SPI_CI_RNFULLFCI_SHIFT                   2                                                   /*!< SPI0_CI: RNFULLFCI Position             */
#define SPI_CI_TNEAREFCI_MASK                    (0x01UL << SPI_CI_TNEAREFCI_SHIFT)                  /*!< SPI0_CI: TNEAREFCI Mask                 */
#define SPI_CI_TNEAREFCI_SHIFT                   3                                                   /*!< SPI0_CI: TNEAREFCI Position             */
#define SPI_CI_RXFOF_MASK                        (0x01UL << SPI_CI_RXFOF_SHIFT)                      /*!< SPI0_CI: RXFOF Mask                     */
#define SPI_CI_RXFOF_SHIFT                       4                                                   /*!< SPI0_CI: RXFOF Position                 */
#define SPI_CI_TXFOF_MASK                        (0x01UL << SPI_CI_TXFOF_SHIFT)                      /*!< SPI0_CI: TXFOF Mask                     */
#define SPI_CI_TXFOF_SHIFT                       5                                                   /*!< SPI0_CI: TXFOF Position                 */
#define SPI_CI_RXFERR_MASK                       (0x01UL << SPI_CI_RXFERR_SHIFT)                     /*!< SPI0_CI: RXFERR Mask                    */
#define SPI_CI_RXFERR_SHIFT                      6                                                   /*!< SPI0_CI: RXFERR Position                */
#define SPI_CI_TXFERR_MASK                       (0x01UL << SPI_CI_TXFERR_SHIFT)                     /*!< SPI0_CI: TXFERR Mask                    */
#define SPI_CI_TXFERR_SHIFT                      7                                                   /*!< SPI0_CI: TXFERR Position                */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0xFFFF81A0UL //!< Peripheral base address
#define SPI0                           ((SPI_Type *) SPI0_BasePtr) //!< Freescale base pointer
#define SPI0_BASE_PTR                  (SPI0) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI1 (file:SPI1_MCF51_DMA)           ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
/**
* @addtogroup SPI_structs_GROUP SPI struct
* @brief Struct for SPI
* @{
*/
typedef struct {                                /*       SPI1 Structure                                               */
   __IO uint8_t   C1;                           /**< 0000: Control register 1                                           */
   __IO uint8_t   C2;                           /**< 0001: Control register 2                                           */
   __IO uint8_t   BR;                           /**< 0002: SPI baud rate register BAUD = (Bus Clock)/Prescaler/Baud Rate Divisor */
   __I  uint8_t   S;                            /**< 0003: Status register                                              */
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  D;                         /**< 0004: Data register                                                */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   DH;                     /**< 0004: Data register low                                            */
         __IO uint8_t   DL;                     /**< 0005: Data register high                                           */
      };
   };
   union {                                      /**< 0000: (size=0002)                                                  */
      __IO uint16_t  M;                         /**< 0006: Match register                                               */
      struct {                                  /**< 0000: (size=0002)                                                  */
         __IO uint8_t   MH;                     /**< 0006: Match register high                                          */
         __IO uint8_t   ML;                     /**< 0007: Match register low                                           */
      };
   };
} SPI1_Type;

/**
 * @} */ /* End group SPI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SPI_Register_Masks_GROUP SPI Register Masks
* @brief Register Masks for SPI
* @{
*/
/* ------- C1 Bit Fields                            ------ */
/* ------- C2 Bit Fields                            ------ */
/* ------- BR Bit Fields                            ------ */
/* ------- S Bit Fields                             ------ */
/* ------- D Bit Fields                             ------ */
/* ------- DH Bit Fields                            ------ */
/* ------- DL Bit Fields                            ------ */
/* ------- M Bit Fields                             ------ */
/* ------- MH Bit Fields                            ------ */
/* ------- ML Bit Fields                            ------ */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI1 - Peripheral instance base addresses */
#define SPI1_BasePtr                   0xFFFF81B0UL //!< Peripheral base address
#define SPI1                           ((SPI1_Type *) SPI1_BasePtr) //!< Freescale base pointer
#define SPI1_BASE_PTR                  (SPI1) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TSI_Peripheral_access_layer_GROUP TSI Peripheral Access Layer
* @brief C Struct for TSI
* @{
*/

/* ================================================================================ */
/* ================           TSI0 (file:TSI0_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief Touch Sensing Input
 */
/**
* @addtogroup TSI_structs_GROUP TSI struct
* @brief Struct for TSI
* @{
*/
typedef struct {                                /*       TSI0 Structure                                               */
   __IO uint32_t  GENCS;                        /**< 0000: General Control and Status Register                          */
   __IO uint32_t  SCANC;                        /**< 0004: SCAN Control Register                                        */
   __IO uint32_t  PEN;                          /**< 0008: Pin Enable Register                                          */
   __IO uint32_t  STATUS;                       /**< 000C: Status Register                                              */
   __I  uint32_t  RESERVED0[60];               
   __I  uint32_t  CNTR1;                        /**< 0100: Counter Register 1                                           */
   __I  uint32_t  CNTR3;                        /**< 0104: Counter Register 3                                           */
   __I  uint32_t  CNTR5;                        /**< 0108: Counter Register 5                                           */
   __I  uint32_t  CNTR7;                        /**< 010C: Counter Register 7                                           */
   __I  uint32_t  CNTR9;                        /**< 0110: Counter Register 9                                           */
   __I  uint32_t  CNTR11;                       /**< 0114: Counter Register 11                                          */
   __I  uint32_t  CNTR13;                       /**< 0118: Counter Register 13                                          */
   __I  uint32_t  CNTR15;                       /**< 011C: Counter Register 15                                          */
   __IO uint32_t  THRESHOLD[16];                /**< 0120: Channel  Threshold Register                                  */
} TSI_Type;

/**
 * @} */ /* End group TSI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TSI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TSI_Register_Masks_GROUP TSI Register Masks
* @brief Register Masks for TSI
* @{
*/
/* ------- GENCS Bit Fields                         ------ */
#define TSI_GENCS_STPE_MASK                      (0x01UL << TSI_GENCS_STPE_SHIFT)                    /*!< TSI0_GENCS: STPE Mask                   */
#define TSI_GENCS_STPE_SHIFT                     0                                                   /*!< TSI0_GENCS: STPE Position               */
#define TSI_GENCS_STM_MASK                       (0x01UL << TSI_GENCS_STM_SHIFT)                     /*!< TSI0_GENCS: STM Mask                    */
#define TSI_GENCS_STM_SHIFT                      1                                                   /*!< TSI0_GENCS: STM Position                */
#define TSI_GENCS_ESOR_MASK                      (0x01UL << TSI_GENCS_ESOR_SHIFT)                    /*!< TSI0_GENCS: ESOR Mask                   */
#define TSI_GENCS_ESOR_SHIFT                     4                                                   /*!< TSI0_GENCS: ESOR Position               */
#define TSI_GENCS_ERIE_MASK                      (0x01UL << TSI_GENCS_ERIE_SHIFT)                    /*!< TSI0_GENCS: ERIE Mask                   */
#define TSI_GENCS_ERIE_SHIFT                     5                                                   /*!< TSI0_GENCS: ERIE Position               */
#define TSI_GENCS_TSIIE_MASK                     (0x01UL << TSI_GENCS_TSIIE_SHIFT)                   /*!< TSI0_GENCS: TSIIE Mask                  */
#define TSI_GENCS_TSIIE_SHIFT                    6                                                   /*!< TSI0_GENCS: TSIIE Position              */
#define TSI_GENCS_TSIEN_MASK                     (0x01UL << TSI_GENCS_TSIEN_SHIFT)                   /*!< TSI0_GENCS: TSIEN Mask                  */
#define TSI_GENCS_TSIEN_SHIFT                    7                                                   /*!< TSI0_GENCS: TSIEN Position              */
#define TSI_GENCS_SWTS_MASK                      (0x01UL << TSI_GENCS_SWTS_SHIFT)                    /*!< TSI0_GENCS: SWTS Mask                   */
#define TSI_GENCS_SWTS_SHIFT                     8                                                   /*!< TSI0_GENCS: SWTS Position               */
#define TSI_GENCS_SCNIP_MASK                     (0x01UL << TSI_GENCS_SCNIP_SHIFT)                   /*!< TSI0_GENCS: SCNIP Mask                  */
#define TSI_GENCS_SCNIP_SHIFT                    9                                                   /*!< TSI0_GENCS: SCNIP Position              */
#define TSI_GENCS_OVRF_MASK                      (0x01UL << TSI_GENCS_OVRF_SHIFT)                    /*!< TSI0_GENCS: OVRF Mask                   */
#define TSI_GENCS_OVRF_SHIFT                     12                                                  /*!< TSI0_GENCS: OVRF Position               */
#define TSI_GENCS_EXTERF_MASK                    (0x01UL << TSI_GENCS_EXTERF_SHIFT)                  /*!< TSI0_GENCS: EXTERF Mask                 */
#define TSI_GENCS_EXTERF_SHIFT                   13                                                  /*!< TSI0_GENCS: EXTERF Position             */
#define TSI_GENCS_OUTRGF_MASK                    (0x01UL << TSI_GENCS_OUTRGF_SHIFT)                  /*!< TSI0_GENCS: OUTRGF Mask                 */
#define TSI_GENCS_OUTRGF_SHIFT                   14                                                  /*!< TSI0_GENCS: OUTRGF Position             */
#define TSI_GENCS_EOSF_MASK                      (0x01UL << TSI_GENCS_EOSF_SHIFT)                    /*!< TSI0_GENCS: EOSF Mask                   */
#define TSI_GENCS_EOSF_SHIFT                     15                                                  /*!< TSI0_GENCS: EOSF Position               */
#define TSI_GENCS_PS_MASK                        (0x07UL << TSI_GENCS_PS_SHIFT)                      /*!< TSI0_GENCS: PS Mask                     */
#define TSI_GENCS_PS_SHIFT                       16                                                  /*!< TSI0_GENCS: PS Position                 */
#define TSI_GENCS_PS(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_PS_SHIFT))&TSI_GENCS_PS_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_NSCN_MASK                      (0x1FUL << TSI_GENCS_NSCN_SHIFT)                    /*!< TSI0_GENCS: NSCN Mask                   */
#define TSI_GENCS_NSCN_SHIFT                     19                                                  /*!< TSI0_GENCS: NSCN Position               */
#define TSI_GENCS_NSCN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_NSCN_SHIFT))&TSI_GENCS_NSCN_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_LPSCNITV_MASK                  (0x0FUL << TSI_GENCS_LPSCNITV_SHIFT)                /*!< TSI0_GENCS: LPSCNITV Mask               */
#define TSI_GENCS_LPSCNITV_SHIFT                 24                                                  /*!< TSI0_GENCS: LPSCNITV Position           */
#define TSI_GENCS_LPSCNITV(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_LPSCNITV_SHIFT))&TSI_GENCS_LPSCNITV_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_LPCLKS_MASK                    (0x01UL << TSI_GENCS_LPCLKS_SHIFT)                  /*!< TSI0_GENCS: LPCLKS Mask                 */
#define TSI_GENCS_LPCLKS_SHIFT                   28                                                  /*!< TSI0_GENCS: LPCLKS Position             */
/* ------- SCANC Bit Fields                         ------ */
#define TSI_SCANC_AMPSC_MASK                     (0x07UL << TSI_SCANC_AMPSC_SHIFT)                   /*!< TSI0_SCANC: AMPSC Mask                  */
#define TSI_SCANC_AMPSC_SHIFT                    0                                                   /*!< TSI0_SCANC: AMPSC Position              */
#define TSI_SCANC_AMPSC(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_AMPSC_SHIFT))&TSI_SCANC_AMPSC_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_AMCLKS_MASK                    (0x03UL << TSI_SCANC_AMCLKS_SHIFT)                  /*!< TSI0_SCANC: AMCLKS Mask                 */
#define TSI_SCANC_AMCLKS_SHIFT                   3                                                   /*!< TSI0_SCANC: AMCLKS Position             */
#define TSI_SCANC_AMCLKS(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_AMCLKS_SHIFT))&TSI_SCANC_AMCLKS_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_AMCLKDIV_MASK                  (0x01UL << TSI_SCANC_AMCLKDIV_SHIFT)                /*!< TSI0_SCANC: AMCLKDIV Mask               */
#define TSI_SCANC_AMCLKDIV_SHIFT                 5                                                   /*!< TSI0_SCANC: AMCLKDIV Position           */
#define TSI_SCANC_SMOD_MASK                      (0xFFUL << TSI_SCANC_SMOD_SHIFT)                    /*!< TSI0_SCANC: SMOD Mask                   */
#define TSI_SCANC_SMOD_SHIFT                     8                                                   /*!< TSI0_SCANC: SMOD Position               */
#define TSI_SCANC_SMOD(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_SMOD_SHIFT))&TSI_SCANC_SMOD_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_DELVOL_MASK                    (0x07UL << TSI_SCANC_DELVOL_SHIFT)                  /*!< TSI0_SCANC: DELVOL Mask                 */
#define TSI_SCANC_DELVOL_SHIFT                   16                                                  /*!< TSI0_SCANC: DELVOL Position             */
#define TSI_SCANC_DELVOL(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_DELVOL_SHIFT))&TSI_SCANC_DELVOL_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_EXTCHRG_MASK                   (0x1FUL << TSI_SCANC_EXTCHRG_SHIFT)                 /*!< TSI0_SCANC: EXTCHRG Mask                */
#define TSI_SCANC_EXTCHRG_SHIFT                  19                                                  /*!< TSI0_SCANC: EXTCHRG Position            */
#define TSI_SCANC_EXTCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_EXTCHRG_SHIFT))&TSI_SCANC_EXTCHRG_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_CAPTRM_MASK                    (0x07UL << TSI_SCANC_CAPTRM_SHIFT)                  /*!< TSI0_SCANC: CAPTRM Mask                 */
#define TSI_SCANC_CAPTRM_SHIFT                   24                                                  /*!< TSI0_SCANC: CAPTRM Position             */
#define TSI_SCANC_CAPTRM(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_CAPTRM_SHIFT))&TSI_SCANC_CAPTRM_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_REFCHRG_MASK                   (0x1FUL << TSI_SCANC_REFCHRG_SHIFT)                 /*!< TSI0_SCANC: REFCHRG Mask                */
#define TSI_SCANC_REFCHRG_SHIFT                  27                                                  /*!< TSI0_SCANC: REFCHRG Position            */
#define TSI_SCANC_REFCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_REFCHRG_SHIFT))&TSI_SCANC_REFCHRG_MASK) /*!< TSI0_SCANC                              */
/* ------- PEN Bit Fields                           ------ */
#define TSI_PEN_PEN0_MASK                        (0x01UL << TSI_PEN_PEN0_SHIFT)                      /*!< TSI0_PEN: PEN0 Mask                     */
#define TSI_PEN_PEN0_SHIFT                       0                                                   /*!< TSI0_PEN: PEN0 Position                 */
#define TSI_PEN_PEN1_MASK                        (0x01UL << TSI_PEN_PEN1_SHIFT)                      /*!< TSI0_PEN: PEN1 Mask                     */
#define TSI_PEN_PEN1_SHIFT                       1                                                   /*!< TSI0_PEN: PEN1 Position                 */
#define TSI_PEN_PEN2_MASK                        (0x01UL << TSI_PEN_PEN2_SHIFT)                      /*!< TSI0_PEN: PEN2 Mask                     */
#define TSI_PEN_PEN2_SHIFT                       2                                                   /*!< TSI0_PEN: PEN2 Position                 */
#define TSI_PEN_PEN3_MASK                        (0x01UL << TSI_PEN_PEN3_SHIFT)                      /*!< TSI0_PEN: PEN3 Mask                     */
#define TSI_PEN_PEN3_SHIFT                       3                                                   /*!< TSI0_PEN: PEN3 Position                 */
#define TSI_PEN_PEN4_MASK                        (0x01UL << TSI_PEN_PEN4_SHIFT)                      /*!< TSI0_PEN: PEN4 Mask                     */
#define TSI_PEN_PEN4_SHIFT                       4                                                   /*!< TSI0_PEN: PEN4 Position                 */
#define TSI_PEN_PEN5_MASK                        (0x01UL << TSI_PEN_PEN5_SHIFT)                      /*!< TSI0_PEN: PEN5 Mask                     */
#define TSI_PEN_PEN5_SHIFT                       5                                                   /*!< TSI0_PEN: PEN5 Position                 */
#define TSI_PEN_PEN6_MASK                        (0x01UL << TSI_PEN_PEN6_SHIFT)                      /*!< TSI0_PEN: PEN6 Mask                     */
#define TSI_PEN_PEN6_SHIFT                       6                                                   /*!< TSI0_PEN: PEN6 Position                 */
#define TSI_PEN_PEN7_MASK                        (0x01UL << TSI_PEN_PEN7_SHIFT)                      /*!< TSI0_PEN: PEN7 Mask                     */
#define TSI_PEN_PEN7_SHIFT                       7                                                   /*!< TSI0_PEN: PEN7 Position                 */
#define TSI_PEN_PEN8_MASK                        (0x01UL << TSI_PEN_PEN8_SHIFT)                      /*!< TSI0_PEN: PEN8 Mask                     */
#define TSI_PEN_PEN8_SHIFT                       8                                                   /*!< TSI0_PEN: PEN8 Position                 */
#define TSI_PEN_PEN9_MASK                        (0x01UL << TSI_PEN_PEN9_SHIFT)                      /*!< TSI0_PEN: PEN9 Mask                     */
#define TSI_PEN_PEN9_SHIFT                       9                                                   /*!< TSI0_PEN: PEN9 Position                 */
#define TSI_PEN_PEN10_MASK                       (0x01UL << TSI_PEN_PEN10_SHIFT)                     /*!< TSI0_PEN: PEN10 Mask                    */
#define TSI_PEN_PEN10_SHIFT                      10                                                  /*!< TSI0_PEN: PEN10 Position                */
#define TSI_PEN_PEN11_MASK                       (0x01UL << TSI_PEN_PEN11_SHIFT)                     /*!< TSI0_PEN: PEN11 Mask                    */
#define TSI_PEN_PEN11_SHIFT                      11                                                  /*!< TSI0_PEN: PEN11 Position                */
#define TSI_PEN_PEN12_MASK                       (0x01UL << TSI_PEN_PEN12_SHIFT)                     /*!< TSI0_PEN: PEN12 Mask                    */
#define TSI_PEN_PEN12_SHIFT                      12                                                  /*!< TSI0_PEN: PEN12 Position                */
#define TSI_PEN_PEN13_MASK                       (0x01UL << TSI_PEN_PEN13_SHIFT)                     /*!< TSI0_PEN: PEN13 Mask                    */
#define TSI_PEN_PEN13_SHIFT                      13                                                  /*!< TSI0_PEN: PEN13 Position                */
#define TSI_PEN_PEN14_MASK                       (0x01UL << TSI_PEN_PEN14_SHIFT)                     /*!< TSI0_PEN: PEN14 Mask                    */
#define TSI_PEN_PEN14_SHIFT                      14                                                  /*!< TSI0_PEN: PEN14 Position                */
#define TSI_PEN_PEN15_MASK                       (0x01UL << TSI_PEN_PEN15_SHIFT)                     /*!< TSI0_PEN: PEN15 Mask                    */
#define TSI_PEN_PEN15_SHIFT                      15                                                  /*!< TSI0_PEN: PEN15 Position                */
#define TSI_PEN_LPSP_MASK                        (0x0FUL << TSI_PEN_LPSP_SHIFT)                      /*!< TSI0_PEN: LPSP Mask                     */
#define TSI_PEN_LPSP_SHIFT                       16                                                  /*!< TSI0_PEN: LPSP Position                 */
#define TSI_PEN_LPSP(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_LPSP_SHIFT))&TSI_PEN_LPSP_MASK) /*!< TSI0_PEN                                */
/* ------- STATUS Bit Fields                        ------ */
#define TSI_STATUS_ORNGF0_MASK                   (0x01UL << TSI_STATUS_ORNGF0_SHIFT)                 /*!< TSI0_STATUS: ORNGF0 Mask                */
#define TSI_STATUS_ORNGF0_SHIFT                  0                                                   /*!< TSI0_STATUS: ORNGF0 Position            */
#define TSI_STATUS_ORNGF1_MASK                   (0x01UL << TSI_STATUS_ORNGF1_SHIFT)                 /*!< TSI0_STATUS: ORNGF1 Mask                */
#define TSI_STATUS_ORNGF1_SHIFT                  1                                                   /*!< TSI0_STATUS: ORNGF1 Position            */
#define TSI_STATUS_ORNGF2_MASK                   (0x01UL << TSI_STATUS_ORNGF2_SHIFT)                 /*!< TSI0_STATUS: ORNGF2 Mask                */
#define TSI_STATUS_ORNGF2_SHIFT                  2                                                   /*!< TSI0_STATUS: ORNGF2 Position            */
#define TSI_STATUS_ORNGF3_MASK                   (0x01UL << TSI_STATUS_ORNGF3_SHIFT)                 /*!< TSI0_STATUS: ORNGF3 Mask                */
#define TSI_STATUS_ORNGF3_SHIFT                  3                                                   /*!< TSI0_STATUS: ORNGF3 Position            */
#define TSI_STATUS_ORNGF4_MASK                   (0x01UL << TSI_STATUS_ORNGF4_SHIFT)                 /*!< TSI0_STATUS: ORNGF4 Mask                */
#define TSI_STATUS_ORNGF4_SHIFT                  4                                                   /*!< TSI0_STATUS: ORNGF4 Position            */
#define TSI_STATUS_ORNGF5_MASK                   (0x01UL << TSI_STATUS_ORNGF5_SHIFT)                 /*!< TSI0_STATUS: ORNGF5 Mask                */
#define TSI_STATUS_ORNGF5_SHIFT                  5                                                   /*!< TSI0_STATUS: ORNGF5 Position            */
#define TSI_STATUS_ORNGF6_MASK                   (0x01UL << TSI_STATUS_ORNGF6_SHIFT)                 /*!< TSI0_STATUS: ORNGF6 Mask                */
#define TSI_STATUS_ORNGF6_SHIFT                  6                                                   /*!< TSI0_STATUS: ORNGF6 Position            */
#define TSI_STATUS_ORNGF7_MASK                   (0x01UL << TSI_STATUS_ORNGF7_SHIFT)                 /*!< TSI0_STATUS: ORNGF7 Mask                */
#define TSI_STATUS_ORNGF7_SHIFT                  7                                                   /*!< TSI0_STATUS: ORNGF7 Position            */
#define TSI_STATUS_ORNGF8_MASK                   (0x01UL << TSI_STATUS_ORNGF8_SHIFT)                 /*!< TSI0_STATUS: ORNGF8 Mask                */
#define TSI_STATUS_ORNGF8_SHIFT                  8                                                   /*!< TSI0_STATUS: ORNGF8 Position            */
#define TSI_STATUS_ORNGF9_MASK                   (0x01UL << TSI_STATUS_ORNGF9_SHIFT)                 /*!< TSI0_STATUS: ORNGF9 Mask                */
#define TSI_STATUS_ORNGF9_SHIFT                  9                                                   /*!< TSI0_STATUS: ORNGF9 Position            */
#define TSI_STATUS_ORNGF10_MASK                  (0x01UL << TSI_STATUS_ORNGF10_SHIFT)                /*!< TSI0_STATUS: ORNGF10 Mask               */
#define TSI_STATUS_ORNGF10_SHIFT                 10                                                  /*!< TSI0_STATUS: ORNGF10 Position           */
#define TSI_STATUS_ORNGF11_MASK                  (0x01UL << TSI_STATUS_ORNGF11_SHIFT)                /*!< TSI0_STATUS: ORNGF11 Mask               */
#define TSI_STATUS_ORNGF11_SHIFT                 11                                                  /*!< TSI0_STATUS: ORNGF11 Position           */
#define TSI_STATUS_ORNGF12_MASK                  (0x01UL << TSI_STATUS_ORNGF12_SHIFT)                /*!< TSI0_STATUS: ORNGF12 Mask               */
#define TSI_STATUS_ORNGF12_SHIFT                 12                                                  /*!< TSI0_STATUS: ORNGF12 Position           */
#define TSI_STATUS_ORNGF13_MASK                  (0x01UL << TSI_STATUS_ORNGF13_SHIFT)                /*!< TSI0_STATUS: ORNGF13 Mask               */
#define TSI_STATUS_ORNGF13_SHIFT                 13                                                  /*!< TSI0_STATUS: ORNGF13 Position           */
#define TSI_STATUS_ORNGF14_MASK                  (0x01UL << TSI_STATUS_ORNGF14_SHIFT)                /*!< TSI0_STATUS: ORNGF14 Mask               */
#define TSI_STATUS_ORNGF14_SHIFT                 14                                                  /*!< TSI0_STATUS: ORNGF14 Position           */
#define TSI_STATUS_ORNGF15_MASK                  (0x01UL << TSI_STATUS_ORNGF15_SHIFT)                /*!< TSI0_STATUS: ORNGF15 Mask               */
#define TSI_STATUS_ORNGF15_SHIFT                 15                                                  /*!< TSI0_STATUS: ORNGF15 Position           */
#define TSI_STATUS_ERROF0_MASK                   (0x01UL << TSI_STATUS_ERROF0_SHIFT)                 /*!< TSI0_STATUS: ERROF0 Mask                */
#define TSI_STATUS_ERROF0_SHIFT                  16                                                  /*!< TSI0_STATUS: ERROF0 Position            */
#define TSI_STATUS_ERROF1_MASK                   (0x01UL << TSI_STATUS_ERROF1_SHIFT)                 /*!< TSI0_STATUS: ERROF1 Mask                */
#define TSI_STATUS_ERROF1_SHIFT                  17                                                  /*!< TSI0_STATUS: ERROF1 Position            */
#define TSI_STATUS_ERROF2_MASK                   (0x01UL << TSI_STATUS_ERROF2_SHIFT)                 /*!< TSI0_STATUS: ERROF2 Mask                */
#define TSI_STATUS_ERROF2_SHIFT                  18                                                  /*!< TSI0_STATUS: ERROF2 Position            */
#define TSI_STATUS_ERROF3_MASK                   (0x01UL << TSI_STATUS_ERROF3_SHIFT)                 /*!< TSI0_STATUS: ERROF3 Mask                */
#define TSI_STATUS_ERROF3_SHIFT                  19                                                  /*!< TSI0_STATUS: ERROF3 Position            */
#define TSI_STATUS_ERROF4_MASK                   (0x01UL << TSI_STATUS_ERROF4_SHIFT)                 /*!< TSI0_STATUS: ERROF4 Mask                */
#define TSI_STATUS_ERROF4_SHIFT                  20                                                  /*!< TSI0_STATUS: ERROF4 Position            */
#define TSI_STATUS_ERROF5_MASK                   (0x01UL << TSI_STATUS_ERROF5_SHIFT)                 /*!< TSI0_STATUS: ERROF5 Mask                */
#define TSI_STATUS_ERROF5_SHIFT                  21                                                  /*!< TSI0_STATUS: ERROF5 Position            */
#define TSI_STATUS_ERROF6_MASK                   (0x01UL << TSI_STATUS_ERROF6_SHIFT)                 /*!< TSI0_STATUS: ERROF6 Mask                */
#define TSI_STATUS_ERROF6_SHIFT                  22                                                  /*!< TSI0_STATUS: ERROF6 Position            */
#define TSI_STATUS_ERROF7_MASK                   (0x01UL << TSI_STATUS_ERROF7_SHIFT)                 /*!< TSI0_STATUS: ERROF7 Mask                */
#define TSI_STATUS_ERROF7_SHIFT                  23                                                  /*!< TSI0_STATUS: ERROF7 Position            */
#define TSI_STATUS_ERROF8_MASK                   (0x01UL << TSI_STATUS_ERROF8_SHIFT)                 /*!< TSI0_STATUS: ERROF8 Mask                */
#define TSI_STATUS_ERROF8_SHIFT                  24                                                  /*!< TSI0_STATUS: ERROF8 Position            */
#define TSI_STATUS_ERROF9_MASK                   (0x01UL << TSI_STATUS_ERROF9_SHIFT)                 /*!< TSI0_STATUS: ERROF9 Mask                */
#define TSI_STATUS_ERROF9_SHIFT                  25                                                  /*!< TSI0_STATUS: ERROF9 Position            */
#define TSI_STATUS_ERROF10_MASK                  (0x01UL << TSI_STATUS_ERROF10_SHIFT)                /*!< TSI0_STATUS: ERROF10 Mask               */
#define TSI_STATUS_ERROF10_SHIFT                 26                                                  /*!< TSI0_STATUS: ERROF10 Position           */
#define TSI_STATUS_ERROF11_MASK                  (0x01UL << TSI_STATUS_ERROF11_SHIFT)                /*!< TSI0_STATUS: ERROF11 Mask               */
#define TSI_STATUS_ERROF11_SHIFT                 27                                                  /*!< TSI0_STATUS: ERROF11 Position           */
#define TSI_STATUS_ERROF12_MASK                  (0x01UL << TSI_STATUS_ERROF12_SHIFT)                /*!< TSI0_STATUS: ERROF12 Mask               */
#define TSI_STATUS_ERROF12_SHIFT                 28                                                  /*!< TSI0_STATUS: ERROF12 Position           */
#define TSI_STATUS_ERROF13_MASK                  (0x01UL << TSI_STATUS_ERROF13_SHIFT)                /*!< TSI0_STATUS: ERROF13 Mask               */
#define TSI_STATUS_ERROF13_SHIFT                 29                                                  /*!< TSI0_STATUS: ERROF13 Position           */
#define TSI_STATUS_ERROF14_MASK                  (0x01UL << TSI_STATUS_ERROF14_SHIFT)                /*!< TSI0_STATUS: ERROF14 Mask               */
#define TSI_STATUS_ERROF14_SHIFT                 30                                                  /*!< TSI0_STATUS: ERROF14 Position           */
#define TSI_STATUS_ERROF15_MASK                  (0x01UL << TSI_STATUS_ERROF15_SHIFT)                /*!< TSI0_STATUS: ERROF15 Mask               */
#define TSI_STATUS_ERROF15_SHIFT                 31                                                  /*!< TSI0_STATUS: ERROF15 Position           */
/* ------- CNTR Bit Fields                          ------ */
#define TSI_CNTR_CTN1_MASK                       (0xFFFFUL << TSI_CNTR_CTN1_SHIFT)                   /*!< TSI0_CNTR: CTN1 Mask                    */
#define TSI_CNTR_CTN1_SHIFT                      0                                                   /*!< TSI0_CNTR: CTN1 Position                */
#define TSI_CNTR_CTN1(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_CNTR_CTN1_SHIFT))&TSI_CNTR_CTN1_MASK) /*!< TSI0_CNTR                               */
#define TSI_CNTR_CTN_MASK                        (0xFFFFUL << TSI_CNTR_CTN_SHIFT)                    /*!< TSI0_CNTR: CTN Mask                     */
#define TSI_CNTR_CTN_SHIFT                       16                                                  /*!< TSI0_CNTR: CTN Position                 */
#define TSI_CNTR_CTN(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_CNTR_CTN_SHIFT))&TSI_CNTR_CTN_MASK) /*!< TSI0_CNTR                               */
/* ------- THRESHOLD Bit Fields                     ------ */
#define TSI_THRESHOLD_HTHH_MASK                  (0xFFFFUL << TSI_THRESHOLD_HTHH_SHIFT)              /*!< TSI0_THRESHOLD: HTHH Mask               */
#define TSI_THRESHOLD_HTHH_SHIFT                 0                                                   /*!< TSI0_THRESHOLD: HTHH Position           */
#define TSI_THRESHOLD_HTHH(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_THRESHOLD_HTHH_SHIFT))&TSI_THRESHOLD_HTHH_MASK) /*!< TSI0_THRESHOLD                          */
#define TSI_THRESHOLD_LTHH_MASK                  (0xFFFFUL << TSI_THRESHOLD_LTHH_SHIFT)              /*!< TSI0_THRESHOLD: LTHH Mask               */
#define TSI_THRESHOLD_LTHH_SHIFT                 16                                                  /*!< TSI0_THRESHOLD: LTHH Position           */
#define TSI_THRESHOLD_LTHH(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_THRESHOLD_LTHH_SHIFT))&TSI_THRESHOLD_LTHH_MASK) /*!< TSI0_THRESHOLD                          */
/**
 * @} */ /* End group TSI_Register_Masks_GROUP 
 */

/* TSI0 - Peripheral instance base addresses */
#define TSI0_BasePtr                   0xFFFF9400UL //!< Peripheral base address
#define TSI0                           ((TSI_Type *) TSI0_BasePtr) //!< Freescale base pointer
#define TSI0_BASE_PTR                  (TSI0) //!< Freescale style base pointer
/**
 * @} */ /* End group TSI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART0 (file:UART0_MCF51_C7816)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART0 Structure                                              */
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /**< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
   __I  uint16_t  RESERVED0;                   
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
   __I  uint8_t   RESERVED1;                   
   __IO uint8_t   C7816;                        /**< 0018: 7816 Control Register                                        */
   __IO uint8_t   IE7816;                       /**< 0019: 7816 Interrupt Enable Register                               */
   __IO uint8_t   IS7816;                       /**< 001A: 7816 Interrupt Status Register                               */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   WP7816T0;                  /**< 001B: 7816 Wait Parameter Register                                 */
      __IO uint8_t   WP7816T1;                  /**< 001B: 7816 Wait Parameter Register                                 */
   };
   __IO uint8_t   WN7816;                       /**< 001C: 7816 Wait N Register                                         */
   __IO uint8_t   WF7816;                       /**< 001D: 7816 Wait FD Register                                        */
   __IO uint8_t   ET7816;                       /**< 001E: 7816 Error Threshold Register                                */
   __IO uint8_t   TL7816;                       /**< 001F: 7816 Transmit Length Register                                */
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
/* ------- BDH Bit Fields                           ------ */
#define UART_BDH_SBR_MASK                        (0x1FUL << UART_BDH_SBR_SHIFT)                      /*!< UART0_BDH: SBR Mask                     */
#define UART_BDH_SBR_SHIFT                       0                                                   /*!< UART0_BDH: SBR Position                 */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK) /*!< UART0_BDH                               */
#define UART_BDH_RXEDGIE_MASK                    (0x01UL << UART_BDH_RXEDGIE_SHIFT)                  /*!< UART0_BDH: RXEDGIE Mask                 */
#define UART_BDH_RXEDGIE_SHIFT                   6                                                   /*!< UART0_BDH: RXEDGIE Position             */
#define UART_BDH_LBKDIE_MASK                     (0x01UL << UART_BDH_LBKDIE_SHIFT)                   /*!< UART0_BDH: LBKDIE Mask                  */
#define UART_BDH_LBKDIE_SHIFT                    7                                                   /*!< UART0_BDH: LBKDIE Position              */
/* ------- BDL Bit Fields                           ------ */
#define UART_BDL_SBR_MASK                        (0xFFUL << UART_BDL_SBR_SHIFT)                      /*!< UART0_BDL: SBR Mask                     */
#define UART_BDL_SBR_SHIFT                       0                                                   /*!< UART0_BDL: SBR Position                 */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK) /*!< UART0_BDL                               */
/* ------- C1 Bit Fields                            ------ */
#define UART_C1_PT_MASK                          (0x01UL << UART_C1_PT_SHIFT)                        /*!< UART0_C1: PT Mask                       */
#define UART_C1_PT_SHIFT                         0                                                   /*!< UART0_C1: PT Position                   */
#define UART_C1_PE_MASK                          (0x01UL << UART_C1_PE_SHIFT)                        /*!< UART0_C1: PE Mask                       */
#define UART_C1_PE_SHIFT                         1                                                   /*!< UART0_C1: PE Position                   */
#define UART_C1_ILT_MASK                         (0x01UL << UART_C1_ILT_SHIFT)                       /*!< UART0_C1: ILT Mask                      */
#define UART_C1_ILT_SHIFT                        2                                                   /*!< UART0_C1: ILT Position                  */
#define UART_C1_WAKE_MASK                        (0x01UL << UART_C1_WAKE_SHIFT)                      /*!< UART0_C1: WAKE Mask                     */
#define UART_C1_WAKE_SHIFT                       3                                                   /*!< UART0_C1: WAKE Position                 */
#define UART_C1_M_MASK                           (0x01UL << UART_C1_M_SHIFT)                         /*!< UART0_C1: M Mask                        */
#define UART_C1_M_SHIFT                          4                                                   /*!< UART0_C1: M Position                    */
#define UART_C1_RSRC_MASK                        (0x01UL << UART_C1_RSRC_SHIFT)                      /*!< UART0_C1: RSRC Mask                     */
#define UART_C1_RSRC_SHIFT                       5                                                   /*!< UART0_C1: RSRC Position                 */
#define UART_C1_UARTSWAI_MASK                    (0x01UL << UART_C1_UARTSWAI_SHIFT)                  /*!< UART0_C1: UARTSWAI Mask                 */
#define UART_C1_UARTSWAI_SHIFT                   6                                                   /*!< UART0_C1: UARTSWAI Position             */
#define UART_C1_LOOPS_MASK                       (0x01UL << UART_C1_LOOPS_SHIFT)                     /*!< UART0_C1: LOOPS Mask                    */
#define UART_C1_LOOPS_SHIFT                      7                                                   /*!< UART0_C1: LOOPS Position                */
/* ------- C2 Bit Fields                            ------ */
#define UART_C2_SBK_MASK                         (0x01UL << UART_C2_SBK_SHIFT)                       /*!< UART0_C2: SBK Mask                      */
#define UART_C2_SBK_SHIFT                        0                                                   /*!< UART0_C2: SBK Position                  */
#define UART_C2_RWU_MASK                         (0x01UL << UART_C2_RWU_SHIFT)                       /*!< UART0_C2: RWU Mask                      */
#define UART_C2_RWU_SHIFT                        1                                                   /*!< UART0_C2: RWU Position                  */
#define UART_C2_RE_MASK                          (0x01UL << UART_C2_RE_SHIFT)                        /*!< UART0_C2: RE Mask                       */
#define UART_C2_RE_SHIFT                         2                                                   /*!< UART0_C2: RE Position                   */
#define UART_C2_TE_MASK                          (0x01UL << UART_C2_TE_SHIFT)                        /*!< UART0_C2: TE Mask                       */
#define UART_C2_TE_SHIFT                         3                                                   /*!< UART0_C2: TE Position                   */
#define UART_C2_ILIE_MASK                        (0x01UL << UART_C2_ILIE_SHIFT)                      /*!< UART0_C2: ILIE Mask                     */
#define UART_C2_ILIE_SHIFT                       4                                                   /*!< UART0_C2: ILIE Position                 */
#define UART_C2_RIE_MASK                         (0x01UL << UART_C2_RIE_SHIFT)                       /*!< UART0_C2: RIE Mask                      */
#define UART_C2_RIE_SHIFT                        5                                                   /*!< UART0_C2: RIE Position                  */
#define UART_C2_TCIE_MASK                        (0x01UL << UART_C2_TCIE_SHIFT)                      /*!< UART0_C2: TCIE Mask                     */
#define UART_C2_TCIE_SHIFT                       6                                                   /*!< UART0_C2: TCIE Position                 */
#define UART_C2_TIE_MASK                         (0x01UL << UART_C2_TIE_SHIFT)                       /*!< UART0_C2: TIE Mask                      */
#define UART_C2_TIE_SHIFT                        7                                                   /*!< UART0_C2: TIE Position                  */
/* ------- S1 Bit Fields                            ------ */
#define UART_S1_PF_MASK                          (0x01UL << UART_S1_PF_SHIFT)                        /*!< UART0_S1: PF Mask                       */
#define UART_S1_PF_SHIFT                         0                                                   /*!< UART0_S1: PF Position                   */
#define UART_S1_FE_MASK                          (0x01UL << UART_S1_FE_SHIFT)                        /*!< UART0_S1: FE Mask                       */
#define UART_S1_FE_SHIFT                         1                                                   /*!< UART0_S1: FE Position                   */
#define UART_S1_NF_MASK                          (0x01UL << UART_S1_NF_SHIFT)                        /*!< UART0_S1: NF Mask                       */
#define UART_S1_NF_SHIFT                         2                                                   /*!< UART0_S1: NF Position                   */
#define UART_S1_OR_MASK                          (0x01UL << UART_S1_OR_SHIFT)                        /*!< UART0_S1: OR Mask                       */
#define UART_S1_OR_SHIFT                         3                                                   /*!< UART0_S1: OR Position                   */
#define UART_S1_IDLE_MASK                        (0x01UL << UART_S1_IDLE_SHIFT)                      /*!< UART0_S1: IDLE Mask                     */
#define UART_S1_IDLE_SHIFT                       4                                                   /*!< UART0_S1: IDLE Position                 */
#define UART_S1_RDRF_MASK                        (0x01UL << UART_S1_RDRF_SHIFT)                      /*!< UART0_S1: RDRF Mask                     */
#define UART_S1_RDRF_SHIFT                       5                                                   /*!< UART0_S1: RDRF Position                 */
#define UART_S1_TC_MASK                          (0x01UL << UART_S1_TC_SHIFT)                        /*!< UART0_S1: TC Mask                       */
#define UART_S1_TC_SHIFT                         6                                                   /*!< UART0_S1: TC Position                   */
#define UART_S1_TDRE_MASK                        (0x01UL << UART_S1_TDRE_SHIFT)                      /*!< UART0_S1: TDRE Mask                     */
#define UART_S1_TDRE_SHIFT                       7                                                   /*!< UART0_S1: TDRE Position                 */
/* ------- S2 Bit Fields                            ------ */
#define UART_S2_RAF_MASK                         (0x01UL << UART_S2_RAF_SHIFT)                       /*!< UART0_S2: RAF Mask                      */
#define UART_S2_RAF_SHIFT                        0                                                   /*!< UART0_S2: RAF Position                  */
#define UART_S2_LBKDE_MASK                       (0x01UL << UART_S2_LBKDE_SHIFT)                     /*!< UART0_S2: LBKDE Mask                    */
#define UART_S2_LBKDE_SHIFT                      1                                                   /*!< UART0_S2: LBKDE Position                */
#define UART_S2_BRK13_MASK                       (0x01UL << UART_S2_BRK13_SHIFT)                     /*!< UART0_S2: BRK13 Mask                    */
#define UART_S2_BRK13_SHIFT                      2                                                   /*!< UART0_S2: BRK13 Position                */
#define UART_S2_RWUID_MASK                       (0x01UL << UART_S2_RWUID_SHIFT)                     /*!< UART0_S2: RWUID Mask                    */
#define UART_S2_RWUID_SHIFT                      3                                                   /*!< UART0_S2: RWUID Position                */
#define UART_S2_RXINV_MASK                       (0x01UL << UART_S2_RXINV_SHIFT)                     /*!< UART0_S2: RXINV Mask                    */
#define UART_S2_RXINV_SHIFT                      4                                                   /*!< UART0_S2: RXINV Position                */
#define UART_S2_MSBF_MASK                        (0x01UL << UART_S2_MSBF_SHIFT)                      /*!< UART0_S2: MSBF Mask                     */
#define UART_S2_MSBF_SHIFT                       5                                                   /*!< UART0_S2: MSBF Position                 */
#define UART_S2_RXEDGIF_MASK                     (0x01UL << UART_S2_RXEDGIF_SHIFT)                   /*!< UART0_S2: RXEDGIF Mask                  */
#define UART_S2_RXEDGIF_SHIFT                    6                                                   /*!< UART0_S2: RXEDGIF Position              */
#define UART_S2_LBKDIF_MASK                      (0x01UL << UART_S2_LBKDIF_SHIFT)                    /*!< UART0_S2: LBKDIF Mask                   */
#define UART_S2_LBKDIF_SHIFT                     7                                                   /*!< UART0_S2: LBKDIF Position               */
/* ------- C3 Bit Fields                            ------ */
#define UART_C3_PEIE_MASK                        (0x01UL << UART_C3_PEIE_SHIFT)                      /*!< UART0_C3: PEIE Mask                     */
#define UART_C3_PEIE_SHIFT                       0                                                   /*!< UART0_C3: PEIE Position                 */
#define UART_C3_FEIE_MASK                        (0x01UL << UART_C3_FEIE_SHIFT)                      /*!< UART0_C3: FEIE Mask                     */
#define UART_C3_FEIE_SHIFT                       1                                                   /*!< UART0_C3: FEIE Position                 */
#define UART_C3_NEIE_MASK                        (0x01UL << UART_C3_NEIE_SHIFT)                      /*!< UART0_C3: NEIE Mask                     */
#define UART_C3_NEIE_SHIFT                       2                                                   /*!< UART0_C3: NEIE Position                 */
#define UART_C3_ORIE_MASK                        (0x01UL << UART_C3_ORIE_SHIFT)                      /*!< UART0_C3: ORIE Mask                     */
#define UART_C3_ORIE_SHIFT                       3                                                   /*!< UART0_C3: ORIE Position                 */
#define UART_C3_TXINV_MASK                       (0x01UL << UART_C3_TXINV_SHIFT)                     /*!< UART0_C3: TXINV Mask                    */
#define UART_C3_TXINV_SHIFT                      4                                                   /*!< UART0_C3: TXINV Position                */
#define UART_C3_TXDIR_MASK                       (0x01UL << UART_C3_TXDIR_SHIFT)                     /*!< UART0_C3: TXDIR Mask                    */
#define UART_C3_TXDIR_SHIFT                      5                                                   /*!< UART0_C3: TXDIR Position                */
#define UART_C3_T8_MASK                          (0x01UL << UART_C3_T8_SHIFT)                        /*!< UART0_C3: T8 Mask                       */
#define UART_C3_T8_SHIFT                         6                                                   /*!< UART0_C3: T8 Position                   */
#define UART_C3_R8_MASK                          (0x01UL << UART_C3_R8_SHIFT)                        /*!< UART0_C3: R8 Mask                       */
#define UART_C3_R8_SHIFT                         7                                                   /*!< UART0_C3: R8 Position                   */
/* ------- D Bit Fields                             ------ */
#define UART_D_RT_MASK                           (0xFFUL << UART_D_RT_SHIFT)                         /*!< UART0_D: RT Mask                        */
#define UART_D_RT_SHIFT                          0                                                   /*!< UART0_D: RT Position                    */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /*!< UART0_D                                 */
/* ------- MA Bit Fields                            ------ */
#define UART_MA_MA_MASK                          (0xFFUL << UART_MA_MA_SHIFT)                        /*!< UART0_MA: MA Mask                       */
#define UART_MA_MA_SHIFT                         0                                                   /*!< UART0_MA: MA Position                   */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<UART_MA_MA_SHIFT))&UART_MA_MA_MASK) /*!< UART0_MA                                */
/* ------- C4 Bit Fields                            ------ */
#define UART_C4_BRFA_MASK                        (0x1FUL << UART_C4_BRFA_SHIFT)                      /*!< UART0_C4: BRFA Mask                     */
#define UART_C4_BRFA_SHIFT                       0                                                   /*!< UART0_C4: BRFA Position                 */
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK) /*!< UART0_C4                                */
#define UART_C4_M10_MASK                         (0x01UL << UART_C4_M10_SHIFT)                       /*!< UART0_C4: M10 Mask                      */
#define UART_C4_M10_SHIFT                        5                                                   /*!< UART0_C4: M10 Position                  */
#define UART_C4_MAEN2_MASK                       (0x01UL << UART_C4_MAEN2_SHIFT)                     /*!< UART0_C4: MAEN2 Mask                    */
#define UART_C4_MAEN2_SHIFT                      6                                                   /*!< UART0_C4: MAEN2 Position                */
#define UART_C4_MAEN1_MASK                       (0x01UL << UART_C4_MAEN1_SHIFT)                     /*!< UART0_C4: MAEN1 Mask                    */
#define UART_C4_MAEN1_SHIFT                      7                                                   /*!< UART0_C4: MAEN1 Position                */
/* ------- C5 Bit Fields                            ------ */
#define UART_C5_RDMAS_MASK                       (0x01UL << UART_C5_RDMAS_SHIFT)                     /*!< UART0_C5: RDMAS Mask                    */
#define UART_C5_RDMAS_SHIFT                      5                                                   /*!< UART0_C5: RDMAS Position                */
#define UART_C5_TDMAS_MASK                       (0x01UL << UART_C5_TDMAS_SHIFT)                     /*!< UART0_C5: TDMAS Mask                    */
#define UART_C5_TDMAS_SHIFT                      7                                                   /*!< UART0_C5: TDMAS Position                */
/* ------- ED Bit Fields                            ------ */
#define UART_ED_PARITYE_MASK                     (0x01UL << UART_ED_PARITYE_SHIFT)                   /*!< UART0_ED: PARITYE Mask                  */
#define UART_ED_PARITYE_SHIFT                    6                                                   /*!< UART0_ED: PARITYE Position              */
#define UART_ED_NOISY_MASK                       (0x01UL << UART_ED_NOISY_SHIFT)                     /*!< UART0_ED: NOISY Mask                    */
#define UART_ED_NOISY_SHIFT                      7                                                   /*!< UART0_ED: NOISY Position                */
/* ------- MODEM Bit Fields                         ------ */
#define UART_MODEM_TXCTSE_MASK                   (0x01UL << UART_MODEM_TXCTSE_SHIFT)                 /*!< UART0_MODEM: TXCTSE Mask                */
#define UART_MODEM_TXCTSE_SHIFT                  0                                                   /*!< UART0_MODEM: TXCTSE Position            */
#define UART_MODEM_TXRTSE_MASK                   (0x01UL << UART_MODEM_TXRTSE_SHIFT)                 /*!< UART0_MODEM: TXRTSE Mask                */
#define UART_MODEM_TXRTSE_SHIFT                  1                                                   /*!< UART0_MODEM: TXRTSE Position            */
#define UART_MODEM_TXRTSPOL_MASK                 (0x01UL << UART_MODEM_TXRTSPOL_SHIFT)               /*!< UART0_MODEM: TXRTSPOL Mask              */
#define UART_MODEM_TXRTSPOL_SHIFT                2                                                   /*!< UART0_MODEM: TXRTSPOL Position          */
#define UART_MODEM_RXRTSE_MASK                   (0x01UL << UART_MODEM_RXRTSE_SHIFT)                 /*!< UART0_MODEM: RXRTSE Mask                */
#define UART_MODEM_RXRTSE_SHIFT                  3                                                   /*!< UART0_MODEM: RXRTSE Position            */
/* ------- PFIFO Bit Fields                         ------ */
#define UART_PFIFO_RXFIFOSIZE_MASK               (0x07UL << UART_PFIFO_RXFIFOSIZE_SHIFT)             /*!< UART0_PFIFO: RXFIFOSIZE Mask            */
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0                                                   /*!< UART0_PFIFO: RXFIFOSIZE Position        */
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_RXFE_MASK                     (0x01UL << UART_PFIFO_RXFE_SHIFT)                   /*!< UART0_PFIFO: RXFE Mask                  */
#define UART_PFIFO_RXFE_SHIFT                    3                                                   /*!< UART0_PFIFO: RXFE Position              */
#define UART_PFIFO_TXFIFOSIZE_MASK               (0x07UL << UART_PFIFO_TXFIFOSIZE_SHIFT)             /*!< UART0_PFIFO: TXFIFOSIZE Mask            */
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4                                                   /*!< UART0_PFIFO: TXFIFOSIZE Position        */
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFE_MASK                     (0x01UL << UART_PFIFO_TXFE_SHIFT)                   /*!< UART0_PFIFO: TXFE Mask                  */
#define UART_PFIFO_TXFE_SHIFT                    7                                                   /*!< UART0_PFIFO: TXFE Position              */
/* ------- CFIFO Bit Fields                         ------ */
#define UART_CFIFO_RXUFE_MASK                    (0x01UL << UART_CFIFO_RXUFE_SHIFT)                  /*!< UART0_CFIFO: RXUFE Mask                 */
#define UART_CFIFO_RXUFE_SHIFT                   0                                                   /*!< UART0_CFIFO: RXUFE Position             */
#define UART_CFIFO_TXOFE_MASK                    (0x01UL << UART_CFIFO_TXOFE_SHIFT)                  /*!< UART0_CFIFO: TXOFE Mask                 */
#define UART_CFIFO_TXOFE_SHIFT                   1                                                   /*!< UART0_CFIFO: TXOFE Position             */
#define UART_CFIFO_RXOFE_MASK                    (0x01UL << UART_CFIFO_RXOFE_SHIFT)                  /*!< UART0_CFIFO: RXOFE Mask                 */
#define UART_CFIFO_RXOFE_SHIFT                   2                                                   /*!< UART0_CFIFO: RXOFE Position             */
#define UART_CFIFO_RXFLUSH_MASK                  (0x01UL << UART_CFIFO_RXFLUSH_SHIFT)                /*!< UART0_CFIFO: RXFLUSH Mask               */
#define UART_CFIFO_RXFLUSH_SHIFT                 6                                                   /*!< UART0_CFIFO: RXFLUSH Position           */
#define UART_CFIFO_TXFLUSH_MASK                  (0x01UL << UART_CFIFO_TXFLUSH_SHIFT)                /*!< UART0_CFIFO: TXFLUSH Mask               */
#define UART_CFIFO_TXFLUSH_SHIFT                 7                                                   /*!< UART0_CFIFO: TXFLUSH Position           */
/* ------- SFIFO Bit Fields                         ------ */
#define UART_SFIFO_RXUF_MASK                     (0x01UL << UART_SFIFO_RXUF_SHIFT)                   /*!< UART0_SFIFO: RXUF Mask                  */
#define UART_SFIFO_RXUF_SHIFT                    0                                                   /*!< UART0_SFIFO: RXUF Position              */
#define UART_SFIFO_TXOF_MASK                     (0x01UL << UART_SFIFO_TXOF_SHIFT)                   /*!< UART0_SFIFO: TXOF Mask                  */
#define UART_SFIFO_TXOF_SHIFT                    1                                                   /*!< UART0_SFIFO: TXOF Position              */
#define UART_SFIFO_RXOF_MASK                     (0x01UL << UART_SFIFO_RXOF_SHIFT)                   /*!< UART0_SFIFO: RXOF Mask                  */
#define UART_SFIFO_RXOF_SHIFT                    2                                                   /*!< UART0_SFIFO: RXOF Position              */
#define UART_SFIFO_RXEMPT_MASK                   (0x01UL << UART_SFIFO_RXEMPT_SHIFT)                 /*!< UART0_SFIFO: RXEMPT Mask                */
#define UART_SFIFO_RXEMPT_SHIFT                  6                                                   /*!< UART0_SFIFO: RXEMPT Position            */
#define UART_SFIFO_TXEMPT_MASK                   (0x01UL << UART_SFIFO_TXEMPT_SHIFT)                 /*!< UART0_SFIFO: TXEMPT Mask                */
#define UART_SFIFO_TXEMPT_SHIFT                  7                                                   /*!< UART0_SFIFO: TXEMPT Position            */
/* ------- TWFIFO Bit Fields                        ------ */
#define UART_TWFIFO_TXWATER_MASK                 (0xFFUL << UART_TWFIFO_TXWATER_SHIFT)               /*!< UART0_TWFIFO: TXWATER Mask              */
#define UART_TWFIFO_TXWATER_SHIFT                0                                                   /*!< UART0_TWFIFO: TXWATER Position          */
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK) /*!< UART0_TWFIFO                            */
/* ------- TCFIFO Bit Fields                        ------ */
#define UART_TCFIFO_TXCOUNT_MASK                 (0xFFUL << UART_TCFIFO_TXCOUNT_SHIFT)               /*!< UART0_TCFIFO: TXCOUNT Mask              */
#define UART_TCFIFO_TXCOUNT_SHIFT                0                                                   /*!< UART0_TCFIFO: TXCOUNT Position          */
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK) /*!< UART0_TCFIFO                            */
/* ------- RWFIFO Bit Fields                        ------ */
#define UART_RWFIFO_RXWATER_MASK                 (0xFFUL << UART_RWFIFO_RXWATER_SHIFT)               /*!< UART0_RWFIFO: RXWATER Mask              */
#define UART_RWFIFO_RXWATER_SHIFT                0                                                   /*!< UART0_RWFIFO: RXWATER Position          */
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK) /*!< UART0_RWFIFO                            */
/* ------- RCFIFO Bit Fields                        ------ */
#define UART_RCFIFO_RXCOUNT_MASK                 (0xFFUL << UART_RCFIFO_RXCOUNT_SHIFT)               /*!< UART0_RCFIFO: RXCOUNT Mask              */
#define UART_RCFIFO_RXCOUNT_SHIFT                0                                                   /*!< UART0_RCFIFO: RXCOUNT Position          */
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK) /*!< UART0_RCFIFO                            */
/* ------- C7816 Bit Fields                         ------ */
#define UART_C7816_ISO_7816E_MASK                (0x01UL << UART_C7816_ISO_7816E_SHIFT)              /*!< UART0_C7816: ISO_7816E Mask             */
#define UART_C7816_ISO_7816E_SHIFT               0                                                   /*!< UART0_C7816: ISO_7816E Position         */
#define UART_C7816_TTYPE_MASK                    (0x01UL << UART_C7816_TTYPE_SHIFT)                  /*!< UART0_C7816: TTYPE Mask                 */
#define UART_C7816_TTYPE_SHIFT                   1                                                   /*!< UART0_C7816: TTYPE Position             */
#define UART_C7816_INIT_MASK                     (0x01UL << UART_C7816_INIT_SHIFT)                   /*!< UART0_C7816: INIT Mask                  */
#define UART_C7816_INIT_SHIFT                    2                                                   /*!< UART0_C7816: INIT Position              */
#define UART_C7816_ANACK_MASK                    (0x01UL << UART_C7816_ANACK_SHIFT)                  /*!< UART0_C7816: ANACK Mask                 */
#define UART_C7816_ANACK_SHIFT                   3                                                   /*!< UART0_C7816: ANACK Position             */
#define UART_C7816_ONACK_MASK                    (0x01UL << UART_C7816_ONACK_SHIFT)                  /*!< UART0_C7816: ONACK Mask                 */
#define UART_C7816_ONACK_SHIFT                   4                                                   /*!< UART0_C7816: ONACK Position             */
/* ------- IE7816 Bit Fields                        ------ */
#define UART_IE7816_RXTE_MASK                    (0x01UL << UART_IE7816_RXTE_SHIFT)                  /*!< UART0_IE7816: RXTE Mask                 */
#define UART_IE7816_RXTE_SHIFT                   0                                                   /*!< UART0_IE7816: RXTE Position             */
#define UART_IE7816_TXTE_MASK                    (0x01UL << UART_IE7816_TXTE_SHIFT)                  /*!< UART0_IE7816: TXTE Mask                 */
#define UART_IE7816_TXTE_SHIFT                   1                                                   /*!< UART0_IE7816: TXTE Position             */
#define UART_IE7816_GTVE_MASK                    (0x01UL << UART_IE7816_GTVE_SHIFT)                  /*!< UART0_IE7816: GTVE Mask                 */
#define UART_IE7816_GTVE_SHIFT                   2                                                   /*!< UART0_IE7816: GTVE Position             */
#define UART_IE7816_INITDE_MASK                  (0x01UL << UART_IE7816_INITDE_SHIFT)                /*!< UART0_IE7816: INITDE Mask               */
#define UART_IE7816_INITDE_SHIFT                 4                                                   /*!< UART0_IE7816: INITDE Position           */
#define UART_IE7816_BWTE_MASK                    (0x01UL << UART_IE7816_BWTE_SHIFT)                  /*!< UART0_IE7816: BWTE Mask                 */
#define UART_IE7816_BWTE_SHIFT                   5                                                   /*!< UART0_IE7816: BWTE Position             */
#define UART_IE7816_CWTE_MASK                    (0x01UL << UART_IE7816_CWTE_SHIFT)                  /*!< UART0_IE7816: CWTE Mask                 */
#define UART_IE7816_CWTE_SHIFT                   6                                                   /*!< UART0_IE7816: CWTE Position             */
#define UART_IE7816_WTE_MASK                     (0x01UL << UART_IE7816_WTE_SHIFT)                   /*!< UART0_IE7816: WTE Mask                  */
#define UART_IE7816_WTE_SHIFT                    7                                                   /*!< UART0_IE7816: WTE Position              */
/* ------- IS7816 Bit Fields                        ------ */
#define UART_IS7816_RXT_MASK                     (0x01UL << UART_IS7816_RXT_SHIFT)                   /*!< UART0_IS7816: RXT Mask                  */
#define UART_IS7816_RXT_SHIFT                    0                                                   /*!< UART0_IS7816: RXT Position              */
#define UART_IS7816_TXT_MASK                     (0x01UL << UART_IS7816_TXT_SHIFT)                   /*!< UART0_IS7816: TXT Mask                  */
#define UART_IS7816_TXT_SHIFT                    1                                                   /*!< UART0_IS7816: TXT Position              */
#define UART_IS7816_GTV_MASK                     (0x01UL << UART_IS7816_GTV_SHIFT)                   /*!< UART0_IS7816: GTV Mask                  */
#define UART_IS7816_GTV_SHIFT                    2                                                   /*!< UART0_IS7816: GTV Position              */
#define UART_IS7816_INITD_MASK                   (0x01UL << UART_IS7816_INITD_SHIFT)                 /*!< UART0_IS7816: INITD Mask                */
#define UART_IS7816_INITD_SHIFT                  4                                                   /*!< UART0_IS7816: INITD Position            */
#define UART_IS7816_BWT_MASK                     (0x01UL << UART_IS7816_BWT_SHIFT)                   /*!< UART0_IS7816: BWT Mask                  */
#define UART_IS7816_BWT_SHIFT                    5                                                   /*!< UART0_IS7816: BWT Position              */
#define UART_IS7816_CWT_MASK                     (0x01UL << UART_IS7816_CWT_SHIFT)                   /*!< UART0_IS7816: CWT Mask                  */
#define UART_IS7816_CWT_SHIFT                    6                                                   /*!< UART0_IS7816: CWT Position              */
#define UART_IS7816_WT_MASK                      (0x01UL << UART_IS7816_WT_SHIFT)                    /*!< UART0_IS7816: WT Mask                   */
#define UART_IS7816_WT_SHIFT                     7                                                   /*!< UART0_IS7816: WT Position               */
/* ------- WP7816T0 Bit Fields                      ------ */
#define UART_WP7816T0_WI_MASK                    (0xFFUL << UART_WP7816T0_WI_SHIFT)                  /*!< UART0_WP7816T0: WI Mask                 */
#define UART_WP7816T0_WI_SHIFT                   0                                                   /*!< UART0_WP7816T0: WI Position             */
#define UART_WP7816T0_WI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WP7816T0_WI_SHIFT))&UART_WP7816T0_WI_MASK) /*!< UART0_WP7816T0                          */
/* ------- WP7816T1 Bit Fields                      ------ */
#define UART_WP7816T1_BWI_MASK                   (0x0FUL << UART_WP7816T1_BWI_SHIFT)                 /*!< UART0_WP7816T1: BWI Mask                */
#define UART_WP7816T1_BWI_SHIFT                  0                                                   /*!< UART0_WP7816T1: BWI Position            */
#define UART_WP7816T1_BWI(x)                     (((uint8_t)(((uint8_t)(x))<<UART_WP7816T1_BWI_SHIFT))&UART_WP7816T1_BWI_MASK) /*!< UART0_WP7816T1                          */
#define UART_WP7816T1_CWI_MASK                   (0x0FUL << UART_WP7816T1_CWI_SHIFT)                 /*!< UART0_WP7816T1: CWI Mask                */
#define UART_WP7816T1_CWI_SHIFT                  4                                                   /*!< UART0_WP7816T1: CWI Position            */
#define UART_WP7816T1_CWI(x)                     (((uint8_t)(((uint8_t)(x))<<UART_WP7816T1_CWI_SHIFT))&UART_WP7816T1_CWI_MASK) /*!< UART0_WP7816T1                          */
/* ------- WN7816 Bit Fields                        ------ */
#define UART_WN7816_GTN_MASK                     (0xFFUL << UART_WN7816_GTN_SHIFT)                   /*!< UART0_WN7816: GTN Mask                  */
#define UART_WN7816_GTN_SHIFT                    0                                                   /*!< UART0_WN7816: GTN Position              */
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK) /*!< UART0_WN7816                            */
/* ------- WF7816 Bit Fields                        ------ */
#define UART_WF7816_GTFD_MASK                    (0xFFUL << UART_WF7816_GTFD_SHIFT)                  /*!< UART0_WF7816: GTFD Mask                 */
#define UART_WF7816_GTFD_SHIFT                   0                                                   /*!< UART0_WF7816: GTFD Position             */
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK) /*!< UART0_WF7816                            */
/* ------- ET7816 Bit Fields                        ------ */
#define UART_ET7816_RXTHRESHOLD_MASK             (0x0FUL << UART_ET7816_RXTHRESHOLD_SHIFT)           /*!< UART0_ET7816: RXTHRESHOLD Mask          */
#define UART_ET7816_RXTHRESHOLD_SHIFT            0                                                   /*!< UART0_ET7816: RXTHRESHOLD Position      */
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK) /*!< UART0_ET7816                            */
#define UART_ET7816_TXTHRESHOLD_MASK             (0x0FUL << UART_ET7816_TXTHRESHOLD_SHIFT)           /*!< UART0_ET7816: TXTHRESHOLD Mask          */
#define UART_ET7816_TXTHRESHOLD_SHIFT            4                                                   /*!< UART0_ET7816: TXTHRESHOLD Position      */
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK) /*!< UART0_ET7816                            */
/* ------- TL7816 Bit Fields                        ------ */
#define UART_TL7816_TLEN_MASK                    (0xFFUL << UART_TL7816_TLEN_SHIFT)                  /*!< UART0_TL7816: TLEN Mask                 */
#define UART_TL7816_TLEN_SHIFT                   0                                                   /*!< UART0_TL7816: TLEN Position             */
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK) /*!< UART0_TL7816                            */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0xFFFF8140UL //!< Peripheral base address
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
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0xFFFF8160UL //!< Peripheral base address
#define UART1                          ((UART_Type *) UART1_BasePtr) //!< Freescale base pointer
#define UART1_BASE_PTR                 (UART1) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USB_Peripheral_access_layer_GROUP USB Peripheral Access Layer
* @brief C Struct for USB
* @{
*/

/* ================================================================================ */
/* ================           USB0 (file:USB0_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief Universal Serial Bus, OTG Capable Controller
 */
/**
* @addtogroup USB_structs_GROUP USB struct
* @brief Struct for USB
* @{
*/
typedef struct {                                /*       USB0 Structure                                               */
   __I  uint8_t   PERID;                        /**< 0000: Peripheral ID Register                                       */
   __I  uint8_t   RESERVED0[3];                
   __I  uint8_t   IDCOMP;                       /**< 0004: Peripheral ID Complement Register                            */
   __I  uint8_t   RESERVED1[3];                
   __I  uint8_t   REV;                          /**< 0008: Peripheral Revision Register                                 */
   __I  uint8_t   RESERVED2[3];                
   __I  uint8_t   ADDINFO;                      /**< 000C: Peripheral Additional Info Register                          */
   __I  uint8_t   RESERVED3[3];                
   __IO uint8_t   OTGISTAT;                     /**< 0010: OTG Interrupt Status Register                                */
   __I  uint8_t   RESERVED4[3];                
   __IO uint8_t   OTGICR;                       /**< 0014: OTG Interrupt Control Register                               */
   __I  uint8_t   RESERVED5[3];                
   __IO uint8_t   OTGSTAT;                      /**< 0018: OTG Status Register                                          */
   __I  uint8_t   RESERVED6[3];                
   __IO uint8_t   OTGCTL;                       /**< 001C: OTG Control Register                                         */
   __I  uint8_t   RESERVED7[99];               
   __IO uint8_t   ISTAT;                        /**< 0080: Interrupt Status Register                                    */
   __I  uint8_t   RESERVED8[3];                
   __IO uint8_t   INTEN;                        /**< 0084: Interrupt Enable Register                                    */
   __I  uint8_t   RESERVED9[3];                
   __IO uint8_t   ERRSTAT;                      /**< 0088: Error Interrupt Status Register                              */
   __I  uint8_t   RESERVED10[3];               
   __IO uint8_t   ERREN;                        /**< 008C: Error Interrupt Enable Register                              */
   __I  uint8_t   RESERVED11[3];               
   __I  uint8_t   STAT;                         /**< 0090: Status Register                                              */
   __I  uint8_t   RESERVED12[3];               
   __IO uint8_t   CTL;                          /**< 0094: Control register                                             */
   __I  uint8_t   RESERVED13[3];               
   __IO uint8_t   ADDR;                         /**< 0098: Address Register                                             */
   __I  uint8_t   RESERVED14[3];               
   __IO uint8_t   BDTPAGE1;                     /**< 009C: BDT Page Register 1                                          */
   __I  uint8_t   RESERVED15[3];               
   __IO uint8_t   FRMNUML;                      /**< 00A0: Frame Number Register Low                                    */
   __I  uint8_t   RESERVED16[3];               
   __IO uint8_t   FRMNUMH;                      /**< 00A4: Frame Number Register High                                   */
   __I  uint8_t   RESERVED17[3];               
   __IO uint8_t   TOKEN;                        /**< 00A8: Token Register                                               */
   __I  uint8_t   RESERVED18[3];               
   __IO uint8_t   SOFTHLD;                      /**< 00AC: SOF Threshold Register                                       */
   __I  uint8_t   RESERVED19[3];               
   __IO uint8_t   BDTPAGE2;                     /**< 00B0: BDT Page Register 2                                          */
   __I  uint8_t   RESERVED20[3];               
   __IO uint8_t   BDTPAGE3;                     /**< 00B4: BDT Page Register 3                                          */
   __I  uint8_t   RESERVED21[11];              
   struct {
      __IO uint8_t   ENDPT;                     /**< 00C0: Endpoint Control Register                                    */
      __I  uint8_t   RESERVED0[3];             
   } ENDPOINT[16];                              /**< 00C0: (cluster: size=0x0040, 64)                                   */
   __IO uint8_t   USBCTRL;                      /**< 0100: USB Control Register                                         */
   __I  uint8_t   RESERVED22[3];               
   __I  uint8_t   OBSERVE;                      /**< 0104: USB OTG Observe Register                                     */
   __I  uint8_t   RESERVED23[3];               
   __IO uint8_t   CONTROL;                      /**< 0108: USB OTG Control Register                                     */
   __I  uint8_t   RESERVED24[3];               
   __IO uint8_t   USBTRC0;                      /**< 010C: USB Transceiver Control Register 0                           */
   __I  uint8_t   RESERVED25[7];               
   __IO uint8_t   USBFRMADJUST;                 /**< 0114: Frame Adjust Register                                        */
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
#define USB_PERID_ID_MASK                        (0x3FUL << USB_PERID_ID_SHIFT)                      /*!< USB0_PERID: ID Mask                     */
#define USB_PERID_ID_SHIFT                       0                                                   /*!< USB0_PERID: ID Position                 */
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<USB_PERID_ID_SHIFT))&USB_PERID_ID_MASK) /*!< USB0_PERID                              */
/* ------- IDCOMP Bit Fields                        ------ */
#define USB_IDCOMP_NID_MASK                      (0x3FUL << USB_IDCOMP_NID_SHIFT)                    /*!< USB0_IDCOMP: NID Mask                   */
#define USB_IDCOMP_NID_SHIFT                     0                                                   /*!< USB0_IDCOMP: NID Position               */
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_IDCOMP_NID_SHIFT))&USB_IDCOMP_NID_MASK) /*!< USB0_IDCOMP                             */
/* ------- REV Bit Fields                           ------ */
#define USB_REV_REV_MASK                         (0xFFUL << USB_REV_REV_SHIFT)                       /*!< USB0_REV: REV Mask                      */
#define USB_REV_REV_SHIFT                        0                                                   /*!< USB0_REV: REV Position                  */
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<USB_REV_REV_SHIFT))&USB_REV_REV_MASK) /*!< USB0_REV                                */
/* ------- ADDINFO Bit Fields                       ------ */
#define USB_ADDINFO_IEHOST_MASK                  (0x01UL << USB_ADDINFO_IEHOST_SHIFT)                /*!< USB0_ADDINFO: IEHOST Mask               */
#define USB_ADDINFO_IEHOST_SHIFT                 0                                                   /*!< USB0_ADDINFO: IEHOST Position           */
#define USB_ADDINFO_IRQNUM_MASK                  (0x1FUL << USB_ADDINFO_IRQNUM_SHIFT)                /*!< USB0_ADDINFO: IRQNUM Mask               */
#define USB_ADDINFO_IRQNUM_SHIFT                 3                                                   /*!< USB0_ADDINFO: IRQNUM Position           */
#define USB_ADDINFO_IRQNUM(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ADDINFO_IRQNUM_SHIFT))&USB_ADDINFO_IRQNUM_MASK) /*!< USB0_ADDINFO                            */
/* ------- OTGISTAT Bit Fields                      ------ */
#define USB_OTGISTAT_AVBUSCHG_MASK               (0x01UL << USB_OTGISTAT_AVBUSCHG_SHIFT)             /*!< USB0_OTGISTAT: AVBUSCHG Mask            */
#define USB_OTGISTAT_AVBUSCHG_SHIFT              0                                                   /*!< USB0_OTGISTAT: AVBUSCHG Position        */
#define USB_OTGISTAT_B_SESS_CHG_MASK             (0x01UL << USB_OTGISTAT_B_SESS_CHG_SHIFT)           /*!< USB0_OTGISTAT: B_SESS_CHG Mask          */
#define USB_OTGISTAT_B_SESS_CHG_SHIFT            2                                                   /*!< USB0_OTGISTAT: B_SESS_CHG Position      */
#define USB_OTGISTAT_SESSVLDCHG_MASK             (0x01UL << USB_OTGISTAT_SESSVLDCHG_SHIFT)           /*!< USB0_OTGISTAT: SESSVLDCHG Mask          */
#define USB_OTGISTAT_SESSVLDCHG_SHIFT            3                                                   /*!< USB0_OTGISTAT: SESSVLDCHG Position      */
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         (0x01UL << USB_OTGISTAT_LINE_STATE_CHG_SHIFT)       /*!< USB0_OTGISTAT: LINE_STATE_CHG Mask      */
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        5                                                   /*!< USB0_OTGISTAT: LINE_STATE_CHG Position  */
#define USB_OTGISTAT_ONEMSEC_MASK                (0x01UL << USB_OTGISTAT_ONEMSEC_SHIFT)              /*!< USB0_OTGISTAT: ONEMSEC Mask             */
#define USB_OTGISTAT_ONEMSEC_SHIFT               6                                                   /*!< USB0_OTGISTAT: ONEMSEC Position         */
#define USB_OTGISTAT_IDCHG_MASK                  (0x01UL << USB_OTGISTAT_IDCHG_SHIFT)                /*!< USB0_OTGISTAT: IDCHG Mask               */
#define USB_OTGISTAT_IDCHG_SHIFT                 7                                                   /*!< USB0_OTGISTAT: IDCHG Position           */
/* ------- OTGICR Bit Fields                        ------ */
#define USB_OTGICR_AVBUSEN_MASK                  (0x01UL << USB_OTGICR_AVBUSEN_SHIFT)                /*!< USB0_OTGICR: AVBUSEN Mask               */
#define USB_OTGICR_AVBUSEN_SHIFT                 0                                                   /*!< USB0_OTGICR: AVBUSEN Position           */
#define USB_OTGICR_BSESSEN_MASK                  (0x01UL << USB_OTGICR_BSESSEN_SHIFT)                /*!< USB0_OTGICR: BSESSEN Mask               */
#define USB_OTGICR_BSESSEN_SHIFT                 2                                                   /*!< USB0_OTGICR: BSESSEN Position           */
#define USB_OTGICR_SESSVLDEN_MASK                (0x01UL << USB_OTGICR_SESSVLDEN_SHIFT)              /*!< USB0_OTGICR: SESSVLDEN Mask             */
#define USB_OTGICR_SESSVLDEN_SHIFT               3                                                   /*!< USB0_OTGICR: SESSVLDEN Position         */
#define USB_OTGICR_LINESTATEEN_MASK              (0x01UL << USB_OTGICR_LINESTATEEN_SHIFT)            /*!< USB0_OTGICR: LINESTATEEN Mask           */
#define USB_OTGICR_LINESTATEEN_SHIFT             5                                                   /*!< USB0_OTGICR: LINESTATEEN Position       */
#define USB_OTGICR_ONEMSECEN_MASK                (0x01UL << USB_OTGICR_ONEMSECEN_SHIFT)              /*!< USB0_OTGICR: ONEMSECEN Mask             */
#define USB_OTGICR_ONEMSECEN_SHIFT               6                                                   /*!< USB0_OTGICR: ONEMSECEN Position         */
#define USB_OTGICR_IDEN_MASK                     (0x01UL << USB_OTGICR_IDEN_SHIFT)                   /*!< USB0_OTGICR: IDEN Mask                  */
#define USB_OTGICR_IDEN_SHIFT                    7                                                   /*!< USB0_OTGICR: IDEN Position              */
/* ------- OTGSTAT Bit Fields                       ------ */
#define USB_OTGSTAT_AVBUSVLD_MASK                (0x01UL << USB_OTGSTAT_AVBUSVLD_SHIFT)              /*!< USB0_OTGSTAT: AVBUSVLD Mask             */
#define USB_OTGSTAT_AVBUSVLD_SHIFT               0                                                   /*!< USB0_OTGSTAT: AVBUSVLD Position         */
#define USB_OTGSTAT_BSESSEND_MASK                (0x01UL << USB_OTGSTAT_BSESSEND_SHIFT)              /*!< USB0_OTGSTAT: BSESSEND Mask             */
#define USB_OTGSTAT_BSESSEND_SHIFT               2                                                   /*!< USB0_OTGSTAT: BSESSEND Position         */
#define USB_OTGSTAT_SESS_VLD_MASK                (0x01UL << USB_OTGSTAT_SESS_VLD_SHIFT)              /*!< USB0_OTGSTAT: SESS_VLD Mask             */
#define USB_OTGSTAT_SESS_VLD_SHIFT               3                                                   /*!< USB0_OTGSTAT: SESS_VLD Position         */
#define USB_OTGSTAT_LINESTATESTABLE_MASK         (0x01UL << USB_OTGSTAT_LINESTATESTABLE_SHIFT)       /*!< USB0_OTGSTAT: LINESTATESTABLE Mask      */
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        5                                                   /*!< USB0_OTGSTAT: LINESTATESTABLE Position  */
#define USB_OTGSTAT_ONEMSECEN_MASK               (0x01UL << USB_OTGSTAT_ONEMSECEN_SHIFT)             /*!< USB0_OTGSTAT: ONEMSECEN Mask            */
#define USB_OTGSTAT_ONEMSECEN_SHIFT              6                                                   /*!< USB0_OTGSTAT: ONEMSECEN Position        */
#define USB_OTGSTAT_ID_MASK                      (0x01UL << USB_OTGSTAT_ID_SHIFT)                    /*!< USB0_OTGSTAT: ID Mask                   */
#define USB_OTGSTAT_ID_SHIFT                     7                                                   /*!< USB0_OTGSTAT: ID Position               */
/* ------- OTGCTL Bit Fields                        ------ */
#define USB_OTGCTL_OTGEN_MASK                    (0x01UL << USB_OTGCTL_OTGEN_SHIFT)                  /*!< USB0_OTGCTL: OTGEN Mask                 */
#define USB_OTGCTL_OTGEN_SHIFT                   2                                                   /*!< USB0_OTGCTL: OTGEN Position             */
#define USB_OTGCTL_DMLOW_MASK                    (0x01UL << USB_OTGCTL_DMLOW_SHIFT)                  /*!< USB0_OTGCTL: DMLOW Mask                 */
#define USB_OTGCTL_DMLOW_SHIFT                   4                                                   /*!< USB0_OTGCTL: DMLOW Position             */
#define USB_OTGCTL_DPLOW_MASK                    (0x01UL << USB_OTGCTL_DPLOW_SHIFT)                  /*!< USB0_OTGCTL: DPLOW Mask                 */
#define USB_OTGCTL_DPLOW_SHIFT                   5                                                   /*!< USB0_OTGCTL: DPLOW Position             */
#define USB_OTGCTL_DPHIGH_MASK                   (0x01UL << USB_OTGCTL_DPHIGH_SHIFT)                 /*!< USB0_OTGCTL: DPHIGH Mask                */
#define USB_OTGCTL_DPHIGH_SHIFT                  7                                                   /*!< USB0_OTGCTL: DPHIGH Position            */
/* ------- ISTAT Bit Fields                         ------ */
#define USB_ISTAT_USBRST_MASK                    (0x01UL << USB_ISTAT_USBRST_SHIFT)                  /*!< USB0_ISTAT: USBRST Mask                 */
#define USB_ISTAT_USBRST_SHIFT                   0                                                   /*!< USB0_ISTAT: USBRST Position             */
#define USB_ISTAT_ERROR_MASK                     (0x01UL << USB_ISTAT_ERROR_SHIFT)                   /*!< USB0_ISTAT: ERROR Mask                  */
#define USB_ISTAT_ERROR_SHIFT                    1                                                   /*!< USB0_ISTAT: ERROR Position              */
#define USB_ISTAT_SOFTOK_MASK                    (0x01UL << USB_ISTAT_SOFTOK_SHIFT)                  /*!< USB0_ISTAT: SOFTOK Mask                 */
#define USB_ISTAT_SOFTOK_SHIFT                   2                                                   /*!< USB0_ISTAT: SOFTOK Position             */
#define USB_ISTAT_TOKDNE_MASK                    (0x01UL << USB_ISTAT_TOKDNE_SHIFT)                  /*!< USB0_ISTAT: TOKDNE Mask                 */
#define USB_ISTAT_TOKDNE_SHIFT                   3                                                   /*!< USB0_ISTAT: TOKDNE Position             */
#define USB_ISTAT_SLEEP_MASK                     (0x01UL << USB_ISTAT_SLEEP_SHIFT)                   /*!< USB0_ISTAT: SLEEP Mask                  */
#define USB_ISTAT_SLEEP_SHIFT                    4                                                   /*!< USB0_ISTAT: SLEEP Position              */
#define USB_ISTAT_RESUME_MASK                    (0x01UL << USB_ISTAT_RESUME_SHIFT)                  /*!< USB0_ISTAT: RESUME Mask                 */
#define USB_ISTAT_RESUME_SHIFT                   5                                                   /*!< USB0_ISTAT: RESUME Position             */
#define USB_ISTAT_ATTACH_MASK                    (0x01UL << USB_ISTAT_ATTACH_SHIFT)                  /*!< USB0_ISTAT: ATTACH Mask                 */
#define USB_ISTAT_ATTACH_SHIFT                   6                                                   /*!< USB0_ISTAT: ATTACH Position             */
#define USB_ISTAT_STALL_MASK                     (0x01UL << USB_ISTAT_STALL_SHIFT)                   /*!< USB0_ISTAT: STALL Mask                  */
#define USB_ISTAT_STALL_SHIFT                    7                                                   /*!< USB0_ISTAT: STALL Position              */
/* ------- INTEN Bit Fields                         ------ */
#define USB_INTEN_USBRSTEN_MASK                  (0x01UL << USB_INTEN_USBRSTEN_SHIFT)                /*!< USB0_INTEN: USBRSTEN Mask               */
#define USB_INTEN_USBRSTEN_SHIFT                 0                                                   /*!< USB0_INTEN: USBRSTEN Position           */
#define USB_INTEN_ERROREN_MASK                   (0x01UL << USB_INTEN_ERROREN_SHIFT)                 /*!< USB0_INTEN: ERROREN Mask                */
#define USB_INTEN_ERROREN_SHIFT                  1                                                   /*!< USB0_INTEN: ERROREN Position            */
#define USB_INTEN_SOFTOKEN_MASK                  (0x01UL << USB_INTEN_SOFTOKEN_SHIFT)                /*!< USB0_INTEN: SOFTOKEN Mask               */
#define USB_INTEN_SOFTOKEN_SHIFT                 2                                                   /*!< USB0_INTEN: SOFTOKEN Position           */
#define USB_INTEN_TOKDNEEN_MASK                  (0x01UL << USB_INTEN_TOKDNEEN_SHIFT)                /*!< USB0_INTEN: TOKDNEEN Mask               */
#define USB_INTEN_TOKDNEEN_SHIFT                 3                                                   /*!< USB0_INTEN: TOKDNEEN Position           */
#define USB_INTEN_SLEEPEN_MASK                   (0x01UL << USB_INTEN_SLEEPEN_SHIFT)                 /*!< USB0_INTEN: SLEEPEN Mask                */
#define USB_INTEN_SLEEPEN_SHIFT                  4                                                   /*!< USB0_INTEN: SLEEPEN Position            */
#define USB_INTEN_RESUMEEN_MASK                  (0x01UL << USB_INTEN_RESUMEEN_SHIFT)                /*!< USB0_INTEN: RESUMEEN Mask               */
#define USB_INTEN_RESUMEEN_SHIFT                 5                                                   /*!< USB0_INTEN: RESUMEEN Position           */
#define USB_INTEN_ATTACHEN_MASK                  (0x01UL << USB_INTEN_ATTACHEN_SHIFT)                /*!< USB0_INTEN: ATTACHEN Mask               */
#define USB_INTEN_ATTACHEN_SHIFT                 6                                                   /*!< USB0_INTEN: ATTACHEN Position           */
#define USB_INTEN_STALLEN_MASK                   (0x01UL << USB_INTEN_STALLEN_SHIFT)                 /*!< USB0_INTEN: STALLEN Mask                */
#define USB_INTEN_STALLEN_SHIFT                  7                                                   /*!< USB0_INTEN: STALLEN Position            */
/* ------- ERRSTAT Bit Fields                       ------ */
#define USB_ERRSTAT_PIDERR_MASK                  (0x01UL << USB_ERRSTAT_PIDERR_SHIFT)                /*!< USB0_ERRSTAT: PIDERR Mask               */
#define USB_ERRSTAT_PIDERR_SHIFT                 0                                                   /*!< USB0_ERRSTAT: PIDERR Position           */
#define USB_ERRSTAT_CRC5EOF_MASK                 (0x01UL << USB_ERRSTAT_CRC5EOF_SHIFT)               /*!< USB0_ERRSTAT: CRC5EOF Mask              */
#define USB_ERRSTAT_CRC5EOF_SHIFT                1                                                   /*!< USB0_ERRSTAT: CRC5EOF Position          */
#define USB_ERRSTAT_CRC16_MASK                   (0x01UL << USB_ERRSTAT_CRC16_SHIFT)                 /*!< USB0_ERRSTAT: CRC16 Mask                */
#define USB_ERRSTAT_CRC16_SHIFT                  2                                                   /*!< USB0_ERRSTAT: CRC16 Position            */
#define USB_ERRSTAT_DFN8_MASK                    (0x01UL << USB_ERRSTAT_DFN8_SHIFT)                  /*!< USB0_ERRSTAT: DFN8 Mask                 */
#define USB_ERRSTAT_DFN8_SHIFT                   3                                                   /*!< USB0_ERRSTAT: DFN8 Position             */
#define USB_ERRSTAT_BTOERR_MASK                  (0x01UL << USB_ERRSTAT_BTOERR_SHIFT)                /*!< USB0_ERRSTAT: BTOERR Mask               */
#define USB_ERRSTAT_BTOERR_SHIFT                 4                                                   /*!< USB0_ERRSTAT: BTOERR Position           */
#define USB_ERRSTAT_DMAERR_MASK                  (0x01UL << USB_ERRSTAT_DMAERR_SHIFT)                /*!< USB0_ERRSTAT: DMAERR Mask               */
#define USB_ERRSTAT_DMAERR_SHIFT                 5                                                   /*!< USB0_ERRSTAT: DMAERR Position           */
#define USB_ERRSTAT_BTSERR_MASK                  (0x01UL << USB_ERRSTAT_BTSERR_SHIFT)                /*!< USB0_ERRSTAT: BTSERR Mask               */
#define USB_ERRSTAT_BTSERR_SHIFT                 7                                                   /*!< USB0_ERRSTAT: BTSERR Position           */
/* ------- ERREN Bit Fields                         ------ */
#define USB_ERREN_PIDERREN_MASK                  (0x01UL << USB_ERREN_PIDERREN_SHIFT)                /*!< USB0_ERREN: PIDERREN Mask               */
#define USB_ERREN_PIDERREN_SHIFT                 0                                                   /*!< USB0_ERREN: PIDERREN Position           */
#define USB_ERREN_CRC5EOFEN_MASK                 (0x01UL << USB_ERREN_CRC5EOFEN_SHIFT)               /*!< USB0_ERREN: CRC5EOFEN Mask              */
#define USB_ERREN_CRC5EOFEN_SHIFT                1                                                   /*!< USB0_ERREN: CRC5EOFEN Position          */
#define USB_ERREN_CRC16EN_MASK                   (0x01UL << USB_ERREN_CRC16EN_SHIFT)                 /*!< USB0_ERREN: CRC16EN Mask                */
#define USB_ERREN_CRC16EN_SHIFT                  2                                                   /*!< USB0_ERREN: CRC16EN Position            */
#define USB_ERREN_DFN8EN_MASK                    (0x01UL << USB_ERREN_DFN8EN_SHIFT)                  /*!< USB0_ERREN: DFN8EN Mask                 */
#define USB_ERREN_DFN8EN_SHIFT                   3                                                   /*!< USB0_ERREN: DFN8EN Position             */
#define USB_ERREN_BTOERREN_MASK                  (0x01UL << USB_ERREN_BTOERREN_SHIFT)                /*!< USB0_ERREN: BTOERREN Mask               */
#define USB_ERREN_BTOERREN_SHIFT                 4                                                   /*!< USB0_ERREN: BTOERREN Position           */
#define USB_ERREN_DMAERREN_MASK                  (0x01UL << USB_ERREN_DMAERREN_SHIFT)                /*!< USB0_ERREN: DMAERREN Mask               */
#define USB_ERREN_DMAERREN_SHIFT                 5                                                   /*!< USB0_ERREN: DMAERREN Position           */
#define USB_ERREN_BTSERREN_MASK                  (0x01UL << USB_ERREN_BTSERREN_SHIFT)                /*!< USB0_ERREN: BTSERREN Mask               */
#define USB_ERREN_BTSERREN_SHIFT                 7                                                   /*!< USB0_ERREN: BTSERREN Position           */
/* ------- STAT Bit Fields                          ------ */
#define USB_STAT_ODD_MASK                        (0x01UL << USB_STAT_ODD_SHIFT)                      /*!< USB0_STAT: ODD Mask                     */
#define USB_STAT_ODD_SHIFT                       2                                                   /*!< USB0_STAT: ODD Position                 */
#define USB_STAT_TX_MASK                         (0x01UL << USB_STAT_TX_SHIFT)                       /*!< USB0_STAT: TX Mask                      */
#define USB_STAT_TX_SHIFT                        3                                                   /*!< USB0_STAT: TX Position                  */
#define USB_STAT_ENDP_MASK                       (0x0FUL << USB_STAT_ENDP_SHIFT)                     /*!< USB0_STAT: ENDP Mask                    */
#define USB_STAT_ENDP_SHIFT                      4                                                   /*!< USB0_STAT: ENDP Position                */
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<USB_STAT_ENDP_SHIFT))&USB_STAT_ENDP_MASK) /*!< USB0_STAT                               */
/* ------- CTL Bit Fields                           ------ */
#define USB_CTL_USBENSOFEN_MASK                  (0x01UL << USB_CTL_USBENSOFEN_SHIFT)                /*!< USB0_CTL: USBENSOFEN Mask               */
#define USB_CTL_USBENSOFEN_SHIFT                 0                                                   /*!< USB0_CTL: USBENSOFEN Position           */
#define USB_CTL_ODDRST_MASK                      (0x01UL << USB_CTL_ODDRST_SHIFT)                    /*!< USB0_CTL: ODDRST Mask                   */
#define USB_CTL_ODDRST_SHIFT                     1                                                   /*!< USB0_CTL: ODDRST Position               */
#define USB_CTL_RESUME_MASK                      (0x01UL << USB_CTL_RESUME_SHIFT)                    /*!< USB0_CTL: RESUME Mask                   */
#define USB_CTL_RESUME_SHIFT                     2                                                   /*!< USB0_CTL: RESUME Position               */
#define USB_CTL_HOSTMODEEN_MASK                  (0x01UL << USB_CTL_HOSTMODEEN_SHIFT)                /*!< USB0_CTL: HOSTMODEEN Mask               */
#define USB_CTL_HOSTMODEEN_SHIFT                 3                                                   /*!< USB0_CTL: HOSTMODEEN Position           */
#define USB_CTL_RESET_MASK                       (0x01UL << USB_CTL_RESET_SHIFT)                     /*!< USB0_CTL: RESET Mask                    */
#define USB_CTL_RESET_SHIFT                      4                                                   /*!< USB0_CTL: RESET Position                */
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          (0x01UL << USB_CTL_TXSUSPENDTOKENBUSY_SHIFT)        /*!< USB0_CTL: TXSUSPENDTOKENBUSY Mask       */
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         5                                                   /*!< USB0_CTL: TXSUSPENDTOKENBUSY Position   */
#define USB_CTL_SE0_MASK                         (0x01UL << USB_CTL_SE0_SHIFT)                       /*!< USB0_CTL: SE0 Mask                      */
#define USB_CTL_SE0_SHIFT                        6                                                   /*!< USB0_CTL: SE0 Position                  */
#define USB_CTL_JSTATE_MASK                      (0x01UL << USB_CTL_JSTATE_SHIFT)                    /*!< USB0_CTL: JSTATE Mask                   */
#define USB_CTL_JSTATE_SHIFT                     7                                                   /*!< USB0_CTL: JSTATE Position               */
/* ------- ADDR Bit Fields                          ------ */
#define USB_ADDR_ADDR_MASK                       (0x7FUL << USB_ADDR_ADDR_SHIFT)                     /*!< USB0_ADDR: ADDR Mask                    */
#define USB_ADDR_ADDR_SHIFT                      0                                                   /*!< USB0_ADDR: ADDR Position                */
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_ADDR_SHIFT))&USB_ADDR_ADDR_MASK) /*!< USB0_ADDR                               */
#define USB_ADDR_LSEN_MASK                       (0x01UL << USB_ADDR_LSEN_SHIFT)                     /*!< USB0_ADDR: LSEN Mask                    */
#define USB_ADDR_LSEN_SHIFT                      7                                                   /*!< USB0_ADDR: LSEN Position                */
/* ------- BDTPAGE1 Bit Fields                      ------ */
#define USB_BDTPAGE1_BDTBA_MASK                  (0x7FUL << USB_BDTPAGE1_BDTBA_SHIFT)                /*!< USB0_BDTPAGE1: BDTBA Mask               */
#define USB_BDTPAGE1_BDTBA_SHIFT                 1                                                   /*!< USB0_BDTPAGE1: BDTBA Position           */
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE1_BDTBA_SHIFT))&USB_BDTPAGE1_BDTBA_MASK) /*!< USB0_BDTPAGE1                           */
/* ------- FRMNUML Bit Fields                       ------ */
#define USB_FRMNUML_FRM_MASK                     (0xFFUL << USB_FRMNUML_FRM_SHIFT)                   /*!< USB0_FRMNUML: FRM Mask                  */
#define USB_FRMNUML_FRM_SHIFT                    0                                                   /*!< USB0_FRMNUML: FRM Position              */
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUML_FRM_SHIFT))&USB_FRMNUML_FRM_MASK) /*!< USB0_FRMNUML                            */
/* ------- FRMNUMH Bit Fields                       ------ */
#define USB_FRMNUMH_FRM_MASK                     (0x07UL << USB_FRMNUMH_FRM_SHIFT)                   /*!< USB0_FRMNUMH: FRM Mask                  */
#define USB_FRMNUMH_FRM_SHIFT                    0                                                   /*!< USB0_FRMNUMH: FRM Position              */
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUMH_FRM_SHIFT))&USB_FRMNUMH_FRM_MASK) /*!< USB0_FRMNUMH                            */
/* ------- TOKEN Bit Fields                         ------ */
#define USB_TOKEN_TOKENENDPT_MASK                (0x0FUL << USB_TOKEN_TOKENENDPT_SHIFT)              /*!< USB0_TOKEN: TOKENENDPT Mask             */
#define USB_TOKEN_TOKENENDPT_SHIFT               0                                                   /*!< USB0_TOKEN: TOKENENDPT Position         */
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENENDPT_SHIFT))&USB_TOKEN_TOKENENDPT_MASK) /*!< USB0_TOKEN                              */
#define USB_TOKEN_TOKENPID_MASK                  (0x0FUL << USB_TOKEN_TOKENPID_SHIFT)                /*!< USB0_TOKEN: TOKENPID Mask               */
#define USB_TOKEN_TOKENPID_SHIFT                 4                                                   /*!< USB0_TOKEN: TOKENPID Position           */
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENPID_SHIFT))&USB_TOKEN_TOKENPID_MASK) /*!< USB0_TOKEN                              */
/* ------- SOFTHLD Bit Fields                       ------ */
#define USB_SOFTHLD_CNT_MASK                     (0xFFUL << USB_SOFTHLD_CNT_SHIFT)                   /*!< USB0_SOFTHLD: CNT Mask                  */
#define USB_SOFTHLD_CNT_SHIFT                    0                                                   /*!< USB0_SOFTHLD: CNT Position              */
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<USB_SOFTHLD_CNT_SHIFT))&USB_SOFTHLD_CNT_MASK) /*!< USB0_SOFTHLD                            */
/* ------- BDTPAGE2 Bit Fields                      ------ */
#define USB_BDTPAGE2_BDTBA_MASK                  (0xFFUL << USB_BDTPAGE2_BDTBA_SHIFT)                /*!< USB0_BDTPAGE2: BDTBA Mask               */
#define USB_BDTPAGE2_BDTBA_SHIFT                 0                                                   /*!< USB0_BDTPAGE2: BDTBA Position           */
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE2_BDTBA_SHIFT))&USB_BDTPAGE2_BDTBA_MASK) /*!< USB0_BDTPAGE2                           */
/* ------- BDTPAGE3 Bit Fields                      ------ */
#define USB_BDTPAGE3_BDTBA_MASK                  (0xFFUL << USB_BDTPAGE3_BDTBA_SHIFT)                /*!< USB0_BDTPAGE3: BDTBA Mask               */
#define USB_BDTPAGE3_BDTBA_SHIFT                 0                                                   /*!< USB0_BDTPAGE3: BDTBA Position           */
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE3_BDTBA_SHIFT))&USB_BDTPAGE3_BDTBA_MASK) /*!< USB0_BDTPAGE3                           */
/* ------- ENDPT Bit Fields                         ------ */
#define USB_ENDPT_EPHSHK_MASK                    (0x01UL << USB_ENDPT_EPHSHK_SHIFT)                  /*!< USB0_ENDPT: EPHSHK Mask                 */
#define USB_ENDPT_EPHSHK_SHIFT                   0                                                   /*!< USB0_ENDPT: EPHSHK Position             */
#define USB_ENDPT_EPSTALL_MASK                   (0x01UL << USB_ENDPT_EPSTALL_SHIFT)                 /*!< USB0_ENDPT: EPSTALL Mask                */
#define USB_ENDPT_EPSTALL_SHIFT                  1                                                   /*!< USB0_ENDPT: EPSTALL Position            */
#define USB_ENDPT_EPTXEN_MASK                    (0x01UL << USB_ENDPT_EPTXEN_SHIFT)                  /*!< USB0_ENDPT: EPTXEN Mask                 */
#define USB_ENDPT_EPTXEN_SHIFT                   2                                                   /*!< USB0_ENDPT: EPTXEN Position             */
#define USB_ENDPT_EPRXEN_MASK                    (0x01UL << USB_ENDPT_EPRXEN_SHIFT)                  /*!< USB0_ENDPT: EPRXEN Mask                 */
#define USB_ENDPT_EPRXEN_SHIFT                   3                                                   /*!< USB0_ENDPT: EPRXEN Position             */
#define USB_ENDPT_EPCTLDIS_MASK                  (0x01UL << USB_ENDPT_EPCTLDIS_SHIFT)                /*!< USB0_ENDPT: EPCTLDIS Mask               */
#define USB_ENDPT_EPCTLDIS_SHIFT                 4                                                   /*!< USB0_ENDPT: EPCTLDIS Position           */
#define USB_ENDPT_RETRYDIS_MASK                  (0x01UL << USB_ENDPT_RETRYDIS_SHIFT)                /*!< USB0_ENDPT: RETRYDIS Mask               */
#define USB_ENDPT_RETRYDIS_SHIFT                 6                                                   /*!< USB0_ENDPT: RETRYDIS Position           */
#define USB_ENDPT_HOSTWOHUB_MASK                 (0x01UL << USB_ENDPT_HOSTWOHUB_SHIFT)               /*!< USB0_ENDPT: HOSTWOHUB Mask              */
#define USB_ENDPT_HOSTWOHUB_SHIFT                7                                                   /*!< USB0_ENDPT: HOSTWOHUB Position          */
/* ------- USBCTRL Bit Fields                       ------ */
#define USB_USBCTRL_PDE_MASK                     (0x01UL << USB_USBCTRL_PDE_SHIFT)                   /*!< USB0_USBCTRL: PDE Mask                  */
#define USB_USBCTRL_PDE_SHIFT                    6                                                   /*!< USB0_USBCTRL: PDE Position              */
#define USB_USBCTRL_SUSP_MASK                    (0x01UL << USB_USBCTRL_SUSP_SHIFT)                  /*!< USB0_USBCTRL: SUSP Mask                 */
#define USB_USBCTRL_SUSP_SHIFT                   7                                                   /*!< USB0_USBCTRL: SUSP Position             */
/* ------- OBSERVE Bit Fields                       ------ */
#define USB_OBSERVE_DMPD_MASK                    (0x01UL << USB_OBSERVE_DMPD_SHIFT)                  /*!< USB0_OBSERVE: DMPD Mask                 */
#define USB_OBSERVE_DMPD_SHIFT                   4                                                   /*!< USB0_OBSERVE: DMPD Position             */
#define USB_OBSERVE_DPPD_MASK                    (0x01UL << USB_OBSERVE_DPPD_SHIFT)                  /*!< USB0_OBSERVE: DPPD Mask                 */
#define USB_OBSERVE_DPPD_SHIFT                   6                                                   /*!< USB0_OBSERVE: DPPD Position             */
#define USB_OBSERVE_DPPU_MASK                    (0x01UL << USB_OBSERVE_DPPU_SHIFT)                  /*!< USB0_OBSERVE: DPPU Mask                 */
#define USB_OBSERVE_DPPU_SHIFT                   7                                                   /*!< USB0_OBSERVE: DPPU Position             */
/* ------- CONTROL Bit Fields                       ------ */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          (0x01UL << USB_CONTROL_DPPULLUPNONOTG_SHIFT)        /*!< USB0_CONTROL: DPPULLUPNONOTG Mask       */
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         4                                                   /*!< USB0_CONTROL: DPPULLUPNONOTG Position   */
/* ------- USBTRC0 Bit Fields                       ------ */
#define USB_USBTRC0_USB_RESUME_INT_MASK          (0x01UL << USB_USBTRC0_USB_RESUME_INT_SHIFT)        /*!< USB0_USBTRC0: USB_RESUME_INT Mask       */
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         0                                                   /*!< USB0_USBTRC0: USB_RESUME_INT Position   */
#define USB_USBTRC0_SYNC_DET_MASK                (0x01UL << USB_USBTRC0_SYNC_DET_SHIFT)              /*!< USB0_USBTRC0: SYNC_DET Mask             */
#define USB_USBTRC0_SYNC_DET_SHIFT               1                                                   /*!< USB0_USBTRC0: SYNC_DET Position         */
#define USB_USBTRC0_USBRESMEN_MASK               (0x01UL << USB_USBTRC0_USBRESMEN_SHIFT)             /*!< USB0_USBTRC0: USBRESMEN Mask            */
#define USB_USBTRC0_USBRESMEN_SHIFT              5                                                   /*!< USB0_USBTRC0: USBRESMEN Position        */
#define USB_USBTRC0_USBRESET_MASK                (0x01UL << USB_USBTRC0_USBRESET_SHIFT)              /*!< USB0_USBTRC0: USBRESET Mask             */
#define USB_USBTRC0_USBRESET_SHIFT               7                                                   /*!< USB0_USBTRC0: USBRESET Position         */
/* ------- USBFRMADJUST Bit Fields                  ------ */
#define USB_USBFRMADJUST_ADJ_MASK                (0xFFUL << USB_USBFRMADJUST_ADJ_SHIFT)              /*!< USB0_USBFRMADJUST: ADJ Mask             */
#define USB_USBFRMADJUST_ADJ_SHIFT               0                                                   /*!< USB0_USBFRMADJUST: ADJ Position         */
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBFRMADJUST_ADJ_SHIFT))&USB_USBFRMADJUST_ADJ_MASK) /*!< USB0_USBFRMADJUST                       */
/**
 * @} */ /* End group USB_Register_Masks_GROUP 
 */

/* USB0 - Peripheral instance base addresses */
#define USB0_BasePtr                   0xFFFF9000UL //!< Peripheral base address
#define USB0                           ((USB_Type *) USB0_BasePtr) //!< Freescale base pointer
#define USB0_BASE_PTR                  (USB0) //!< Freescale style base pointer
/**
 * @} */ /* End group USB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USBDCD_Peripheral_access_layer_GROUP USBDCD Peripheral Access Layer
* @brief C Struct for USBDCD
* @{
*/

/* ================================================================================ */
/* ================           USBDCD (file:USBDCD_MCF51_V1.1)       ================ */
/* ================================================================================ */

/**
 * @brief USB Device Charger Detection module (USB DCD V1.1)
 */
/**
* @addtogroup USBDCD_structs_GROUP USBDCD struct
* @brief Struct for USBDCD
* @{
*/
typedef struct {                                /*       USBDCD Structure                                             */
   __IO uint32_t  CONTROL;                      /**< 0000: Control Register                                             */
   __IO uint32_t  CLOCK;                        /**< 0004: Clock Register                                               */
   __I  uint32_t  STATUS;                       /**< 0008: Status Register                                              */
   __I  uint32_t  RESERVED0;                   
   __IO uint32_t  TIMER0;                       /**< 0010: TIMER0 Register                                              */
   __IO uint32_t  TIMER1;                       /**< 0014: TIMER1 register                                              */
   __IO uint32_t  TIMER2;                       /**< 0018: TIMER2 register                                              */
} USBDCD_Type;

/**
 * @} */ /* End group USBDCD_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'USBDCD' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup USBDCD_Register_Masks_GROUP USBDCD Register Masks
* @brief Register Masks for USBDCD
* @{
*/
/* ------- CONTROL Bit Fields                       ------ */
#define USBDCD_CONTROL_IACK_MASK                 (0x01UL << USBDCD_CONTROL_IACK_SHIFT)               /*!< USBDCD_CONTROL: IACK Mask               */
#define USBDCD_CONTROL_IACK_SHIFT                0                                                   /*!< USBDCD_CONTROL: IACK Position           */
#define USBDCD_CONTROL_IF_MASK                   (0x01UL << USBDCD_CONTROL_IF_SHIFT)                 /*!< USBDCD_CONTROL: IF Mask                 */
#define USBDCD_CONTROL_IF_SHIFT                  8                                                   /*!< USBDCD_CONTROL: IF Position             */
#define USBDCD_CONTROL_IE_MASK                   (0x01UL << USBDCD_CONTROL_IE_SHIFT)                 /*!< USBDCD_CONTROL: IE Mask                 */
#define USBDCD_CONTROL_IE_SHIFT                  16                                                  /*!< USBDCD_CONTROL: IE Position             */
#define USBDCD_CONTROL_START_MASK                (0x01UL << USBDCD_CONTROL_START_SHIFT)              /*!< USBDCD_CONTROL: START Mask              */
#define USBDCD_CONTROL_START_SHIFT               24                                                  /*!< USBDCD_CONTROL: START Position          */
#define USBDCD_CONTROL_SR_MASK                   (0x01UL << USBDCD_CONTROL_SR_SHIFT)                 /*!< USBDCD_CONTROL: SR Mask                 */
#define USBDCD_CONTROL_SR_SHIFT                  25                                                  /*!< USBDCD_CONTROL: SR Position             */
/* ------- CLOCK Bit Fields                         ------ */
#define USBDCD_CLOCK_CLOCK_UNIT_MASK             (0x01UL << USBDCD_CLOCK_CLOCK_UNIT_SHIFT)           /*!< USBDCD_CLOCK: CLOCK_UNIT Mask           */
#define USBDCD_CLOCK_CLOCK_UNIT_SHIFT            0                                                   /*!< USBDCD_CLOCK: CLOCK_UNIT Position       */
#define USBDCD_CLOCK_CLOCK_SPEED_MASK            (0x3FFUL << USBDCD_CLOCK_CLOCK_SPEED_SHIFT)         /*!< USBDCD_CLOCK: CLOCK_SPEED Mask          */
#define USBDCD_CLOCK_CLOCK_SPEED_SHIFT           2                                                   /*!< USBDCD_CLOCK: CLOCK_SPEED Position      */
#define USBDCD_CLOCK_CLOCK_SPEED(x)              (((uint32_t)(((uint32_t)(x))<<USBDCD_CLOCK_CLOCK_SPEED_SHIFT))&USBDCD_CLOCK_CLOCK_SPEED_MASK) /*!< USBDCD_CLOCK                            */
/* ------- STATUS Bit Fields                        ------ */
#define USBDCD_STATUS_SEQ_RES_MASK               (0x03UL << USBDCD_STATUS_SEQ_RES_SHIFT)             /*!< USBDCD_STATUS: SEQ_RES Mask             */
#define USBDCD_STATUS_SEQ_RES_SHIFT              16                                                  /*!< USBDCD_STATUS: SEQ_RES Position         */
#define USBDCD_STATUS_SEQ_RES(x)                 (((uint32_t)(((uint32_t)(x))<<USBDCD_STATUS_SEQ_RES_SHIFT))&USBDCD_STATUS_SEQ_RES_MASK) /*!< USBDCD_STATUS                           */
#define USBDCD_STATUS_SEQ_STAT_MASK              (0x03UL << USBDCD_STATUS_SEQ_STAT_SHIFT)            /*!< USBDCD_STATUS: SEQ_STAT Mask            */
#define USBDCD_STATUS_SEQ_STAT_SHIFT             18                                                  /*!< USBDCD_STATUS: SEQ_STAT Position        */
#define USBDCD_STATUS_SEQ_STAT(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_STATUS_SEQ_STAT_SHIFT))&USBDCD_STATUS_SEQ_STAT_MASK) /*!< USBDCD_STATUS                           */
#define USBDCD_STATUS_ERR_MASK                   (0x01UL << USBDCD_STATUS_ERR_SHIFT)                 /*!< USBDCD_STATUS: ERR Mask                 */
#define USBDCD_STATUS_ERR_SHIFT                  20                                                  /*!< USBDCD_STATUS: ERR Position             */
#define USBDCD_STATUS_TO_MASK                    (0x01UL << USBDCD_STATUS_TO_SHIFT)                  /*!< USBDCD_STATUS: TO Mask                  */
#define USBDCD_STATUS_TO_SHIFT                   21                                                  /*!< USBDCD_STATUS: TO Position              */
#define USBDCD_STATUS_ACTIVE_MASK                (0x01UL << USBDCD_STATUS_ACTIVE_SHIFT)              /*!< USBDCD_STATUS: ACTIVE Mask              */
#define USBDCD_STATUS_ACTIVE_SHIFT               22                                                  /*!< USBDCD_STATUS: ACTIVE Position          */
/* ------- TIMER0 Bit Fields                        ------ */
#define USBDCD_TIMER0_TUNITCON_MASK              (0xFFFUL << USBDCD_TIMER0_TUNITCON_SHIFT)           /*!< USBDCD_TIMER0: TUNITCON Mask            */
#define USBDCD_TIMER0_TUNITCON_SHIFT             0                                                   /*!< USBDCD_TIMER0: TUNITCON Position        */
#define USBDCD_TIMER0_TUNITCON(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER0_TUNITCON_SHIFT))&USBDCD_TIMER0_TUNITCON_MASK) /*!< USBDCD_TIMER0                           */
#define USBDCD_TIMER0_TSEQ_INIT_MASK             (0x3FFUL << USBDCD_TIMER0_TSEQ_INIT_SHIFT)          /*!< USBDCD_TIMER0: TSEQ_INIT Mask           */
#define USBDCD_TIMER0_TSEQ_INIT_SHIFT            16                                                  /*!< USBDCD_TIMER0: TSEQ_INIT Position       */
#define USBDCD_TIMER0_TSEQ_INIT(x)               (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER0_TSEQ_INIT_SHIFT))&USBDCD_TIMER0_TSEQ_INIT_MASK) /*!< USBDCD_TIMER0                           */
/* ------- TIMER1 Bit Fields                        ------ */
#define USBDCD_TIMER1_TVDPSRC_ON_MASK            (0x3FFUL << USBDCD_TIMER1_TVDPSRC_ON_SHIFT)         /*!< USBDCD_TIMER1: TVDPSRC_ON Mask          */
#define USBDCD_TIMER1_TVDPSRC_ON_SHIFT           0                                                   /*!< USBDCD_TIMER1: TVDPSRC_ON Position      */
#define USBDCD_TIMER1_TVDPSRC_ON(x)              (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER1_TVDPSRC_ON_SHIFT))&USBDCD_TIMER1_TVDPSRC_ON_MASK) /*!< USBDCD_TIMER1                           */
#define USBDCD_TIMER1_TDCD_DBNC_MASK             (0x3FFUL << USBDCD_TIMER1_TDCD_DBNC_SHIFT)          /*!< USBDCD_TIMER1: TDCD_DBNC Mask           */
#define USBDCD_TIMER1_TDCD_DBNC_SHIFT            16                                                  /*!< USBDCD_TIMER1: TDCD_DBNC Position       */
#define USBDCD_TIMER1_TDCD_DBNC(x)               (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER1_TDCD_DBNC_SHIFT))&USBDCD_TIMER1_TDCD_DBNC_MASK) /*!< USBDCD_TIMER1                           */
/* ------- TIMER2 Bit Fields                        ------ */
#define USBDCD_TIMER2_CHECK_DM_MASK              (0x0FUL << USBDCD_TIMER2_CHECK_DM_SHIFT)            /*!< USBDCD_TIMER2: CHECK_DM Mask            */
#define USBDCD_TIMER2_CHECK_DM_SHIFT             0                                                   /*!< USBDCD_TIMER2: CHECK_DM Position        */
#define USBDCD_TIMER2_CHECK_DM(x)                (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER2_CHECK_DM_SHIFT))&USBDCD_TIMER2_CHECK_DM_MASK) /*!< USBDCD_TIMER2                           */
#define USBDCD_TIMER2_TVDPSRC_CON_MASK           (0x3FFUL << USBDCD_TIMER2_TVDPSRC_CON_SHIFT)        /*!< USBDCD_TIMER2: TVDPSRC_CON Mask         */
#define USBDCD_TIMER2_TVDPSRC_CON_SHIFT          16                                                  /*!< USBDCD_TIMER2: TVDPSRC_CON Position     */
#define USBDCD_TIMER2_TVDPSRC_CON(x)             (((uint32_t)(((uint32_t)(x))<<USBDCD_TIMER2_TVDPSRC_CON_SHIFT))&USBDCD_TIMER2_TVDPSRC_CON_MASK) /*!< USBDCD_TIMER2                           */
/**
 * @} */ /* End group USBDCD_Register_Masks_GROUP 
 */

/* USBDCD - Peripheral instance base addresses */
#define USBDCD_BasePtr                 0xFFFF8680UL //!< Peripheral base address
#define USBDCD                         ((USBDCD_Type *) USBDCD_BasePtr) //!< Freescale base pointer
#define USBDCD_BASE_PTR                (USBDCD) //!< Freescale style base pointer
/**
 * @} */ /* End group USBDCD_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup VREF_Peripheral_access_layer_GROUP VREF Peripheral Access Layer
* @brief C Struct for VREF
* @{
*/

/* ================================================================================ */
/* ================           VREF (file:VREF_MCF51)               ================ */
/* ================================================================================ */

/**
 * @brief Voltage Reference
 */
/**
* @addtogroup VREF_structs_GROUP VREF struct
* @brief Struct for VREF
* @{
*/
typedef struct {                                /*       VREF Structure                                               */
   __IO uint8_t   TRM;                          /**< 0000: Trim Register                                                */
   __IO uint8_t   SC;                           /**< 0001: Status and Control Register                                  */
} VREF_Type;

/**
 * @} */ /* End group VREF_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'VREF' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup VREF_Register_Masks_GROUP VREF Register Masks
* @brief Register Masks for VREF
* @{
*/
/* ------- TRM Bit Fields                           ------ */
#define VREF_TRM_TRIM_MASK                       (0x3FUL << VREF_TRM_TRIM_SHIFT)                     /*!< VREF_TRM: TRIM Mask                     */
#define VREF_TRM_TRIM_SHIFT                      0                                                   /*!< VREF_TRM: TRIM Position                 */
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_TRIM_SHIFT))&VREF_TRM_TRIM_MASK) /*!< VREF_TRM                                */
/* ------- SC Bit Fields                            ------ */
#define VREF_SC_MODE_LV_MASK                     (0x03UL << VREF_SC_MODE_LV_SHIFT)                   /*!< VREF_SC: MODE_LV Mask                   */
#define VREF_SC_MODE_LV_SHIFT                    0                                                   /*!< VREF_SC: MODE_LV Position               */
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_MODE_LV_SHIFT))&VREF_SC_MODE_LV_MASK) /*!< VREF_SC                                 */
#define VREF_SC_VREFST_MASK                      (0x01UL << VREF_SC_VREFST_SHIFT)                    /*!< VREF_SC: VREFST Mask                    */
#define VREF_SC_VREFST_SHIFT                     2                                                   /*!< VREF_SC: VREFST Position                */
#define VREF_SC_ICOMPEN_MASK                     (0x01UL << VREF_SC_ICOMPEN_SHIFT)                   /*!< VREF_SC: ICOMPEN Mask                   */
#define VREF_SC_ICOMPEN_SHIFT                    5                                                   /*!< VREF_SC: ICOMPEN Position               */
#define VREF_SC_REGEN_MASK                       (0x01UL << VREF_SC_REGEN_SHIFT)                     /*!< VREF_SC: REGEN Mask                     */
#define VREF_SC_REGEN_SHIFT                      6                                                   /*!< VREF_SC: REGEN Position                 */
#define VREF_SC_VREFEN_MASK                      (0x01UL << VREF_SC_VREFEN_SHIFT)                    /*!< VREF_SC: VREFEN Mask                    */
#define VREF_SC_VREFEN_SHIFT                     7                                                   /*!< VREF_SC: VREFEN Position                */
/**
 * @} */ /* End group VREF_Register_Masks_GROUP 
 */

/* VREF - Peripheral instance base addresses */
#define VREF_BasePtr                   0xFFFF8670UL //!< Peripheral base address
#define VREF                           ((VREF_Type *) VREF_BasePtr) //!< Freescale base pointer
#define VREF_BASE_PTR                  (VREF) //!< Freescale style base pointer
/**
 * @} */ /* End group VREF_Peripheral_access_layer_GROUP 
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


#endif  /* MCU_MCF51JF */

