/****************************************************************************************************//**
 * @file     MKL17Z4.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKL17Z4.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2017/03
 *
 *******************************************************************************************************/

#ifndef MCU_MKL17Z4
#define MCU_MKL17Z4

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
* @addtogroup Interrupt_vector_numbers_GROUP Interrupt vector numbers
* @brief Vector numbers required for NVIC functions
* @{
*/
/* -------------------------  Interrupt Number Definition  ------------------------ */

/**
 * Interrupt vector numbers
 */
typedef enum {
/* ------------------------  Processor Exceptions Numbers  ------------------------- */
  Reset_IRQn                    = -15,   /**<   1 Reset Vector, invoked on Power up and warm reset                                 */
  NonMaskableInt_IRQn           = -14,   /**<   2 Non maskable Interrupt, cannot be stopped or preempted                           */
  HardFault_IRQn                = -13,   /**<   3 Hard Fault, all classes of Fault                                                 */
  SVCall_IRQn                   =  -5,   /**<  11 System Service Call via SVC instruction                                          */
  PendSV_IRQn                   =  -2,   /**<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /**<  15 System Tick Timer                                                                */
/* ----------------------   MKL17Z4 VectorTable                      ---------------------- */
  DMA0_IRQn                     =   0,   /**<  16 DMA Controller                                                                   */
  DMA1_IRQn                     =   1,   /**<  17 DMA Controller                                                                   */
  DMA2_IRQn                     =   2,   /**<  18 DMA Controller                                                                   */
  DMA3_IRQn                     =   3,   /**<  19 DMA Controller                                                                   */
  FTF_Command_IRQn              =   5,   /**<  21 Flash Memory Interface                                                           */
  PMC_IRQn                      =   6,   /**<  22 Power Management Controller                                                      */
  LLWU_IRQn                     =   7,   /**<  23 Low Leakage Wakeup                                                               */
  I2C0_IRQn                     =   8,   /**<  24 Inter-Integrated Circuit                                                         */
  I2C1_IRQn                     =   9,   /**<  25 Inter-Integrated Circuit                                                         */
  SPI0_IRQn                     =  10,   /**<  26 Serial Peripheral Interface                                                      */
  SPI1_IRQn                     =  11,   /**<  27 Serial Peripheral Interface                                                      */
  LPUART0_IRQn                  =  12,   /**<  28 Serial Communication Interface                                                   */
  LPUART1_IRQn                  =  13,   /**<  29 Serial Communication Interface                                                   */
  UART2_FLEXIO_IRQn             =  14,   /**<  30 FLEXIO                                                                           */
  ADC0_IRQn                     =  15,   /**<  31 Analogue to Digital Converter                                                    */
  CMP0_IRQn                     =  16,   /**<  32 High-Speed Comparator                                                            */
  TPM0_IRQn                     =  17,   /**<  33 Timer/PWM Module                                                                 */
  TPM1_IRQn                     =  18,   /**<  34 Timer/PWM Module                                                                 */
  TPM2_IRQn                     =  19,   /**<  35 Timer/PWM Module                                                                 */
  RTC_Alarm_IRQn                =  20,   /**<  36 Real Time Clock                                                                  */
  RTC_Seconds_IRQn              =  21,   /**<  37 Real Time Clock                                                                  */
  PIT_IRQn                      =  22,   /**<  38 Periodic Interrupt Timer (All channels)                                          */
  I2S0_IRQn                     =  23,   /**<  39 Synchronous Serial Interface                                                     */
  DAC0_IRQn                     =  25,   /**<  41 Digital to Analogue Converter                                                    */
  LPTMR0_IRQn                   =  28,   /**<  44 Low Power Timer                                                                  */
  PORTA_IRQn                    =  30,   /**<  46 General Purpose Input/Output                                                     */
  PORTCD_IRQn                   =  31,   /**<  47 General Purpose Input/Output                                                     */
} IRQn_Type;

/**
 * @} */ /* End group Interrupt_vector_numbers_GROUP 
 */
/**
* @addtogroup Interrupt_handler_prototypes_GROUP Interrupt handler prototypes
* @brief Prototypes for interrupt handlers
* @{
*/
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                 /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);           /**< Hard Fault, all classes of Fault                                                 */
extern void SVC_Handler(void);                 /**< System Service Call via SVC instruction                                          */
extern void PendSV_Handler(void);              /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);             /**< System Tick Timer                                                                */
extern void DMA0_IRQHandler(void);             /**< DMA Controller                                                                   */
extern void DMA1_IRQHandler(void);             /**< DMA Controller                                                                   */
extern void DMA2_IRQHandler(void);             /**< DMA Controller                                                                   */
extern void DMA3_IRQHandler(void);             /**< DMA Controller                                                                   */
extern void FTF_Command_IRQHandler(void);      /**< Flash Memory Interface                                                           */
extern void PMC_IRQHandler(void);              /**< Power Management Controller                                                      */
extern void LLWU_IRQHandler(void);             /**< Low Leakage Wakeup                                                               */
extern void I2C0_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void I2C1_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void SPI0_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void SPI1_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void LPUART0_IRQHandler(void);          /**< Serial Communication Interface                                                   */
extern void LPUART1_IRQHandler(void);          /**< Serial Communication Interface                                                   */
extern void UART2_FLEXIO_IRQHandler(void);     /**< FLEXIO                                                                           */
extern void ADC0_IRQHandler(void);             /**< Analogue to Digital Converter                                                    */
extern void CMP0_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void TPM0_IRQHandler(void);             /**< Timer/PWM Module                                                                 */
extern void TPM1_IRQHandler(void);             /**< Timer/PWM Module                                                                 */
extern void TPM2_IRQHandler(void);             /**< Timer/PWM Module                                                                 */
extern void RTC_Alarm_IRQHandler(void);        /**< Real Time Clock                                                                  */
extern void RTC_Seconds_IRQHandler(void);      /**< Real Time Clock                                                                  */
extern void PIT_IRQHandler(void);              /**< Periodic Interrupt Timer (All channels)                                          */
extern void I2S0_IRQHandler(void);             /**< Synchronous Serial Interface                                                     */
extern void DAC0_IRQHandler(void);             /**< Digital to Analogue Converter                                                    */
extern void LPTMR0_IRQHandler(void);           /**< Low Power Timer                                                                  */
extern void PORTA_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTCD_IRQHandler(void);           /**< General Purpose Input/Output                                                     */

/**
 * @} */ /* End group Interrupt_handler_prototypes_GROUP 
 */
/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/**
* @addtogroup Cortex_Core_Configuration_GROUP Cortex Core Configuration
* @brief Configuration of the cm4 Processor and Core Peripherals
* @{
*/
#define __CM0PLUS_REV             0x0100     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          2          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             0          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
#include "core_cm0plus.h"       /* Processor and core peripherals     */
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
/* ================           ADC0 (file:ADC0_DIFF_A)              ================ */
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
   __IO uint32_t  SC1[2];                       /**< 0000: Status and Control Register 1                                */
   __IO uint32_t  CFG1;                         /**< 0008: Configuration Register 1                                     */
   __IO uint32_t  CFG2;                         /**< 000C: Configuration Register 2                                     */
   __I  uint32_t  R[2];                         /**< 0010: Data Result Register                                         */
   __IO uint32_t  CV1;                          /**< 0018: Compare Value                                                */
   __IO uint32_t  CV2;                          /**< 001C: Compare Value                                                */
   __IO uint32_t  SC2;                          /**< 0020: Status and Control Register 2                                */
   __IO uint32_t  SC3;                          /**< 0024: Status and Control Register 3                                */
   __IO uint32_t  OFS;                          /**< 0028: Offset Correction Register                                   */
   __IO uint32_t  PG;                           /**< 002C: Plus-Side Gain Register                                      */
   __IO uint32_t  MG;                           /**< 0030: Minus-Side Gain Register                                     */
   __IO uint32_t  CLPD;                         /**< 0034: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLPS;                         /**< 0038: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP4;                         /**< 003C: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP3;                         /**< 0040: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP2;                         /**< 0044: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP1;                         /**< 0048: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP0;                         /**< 004C: Plus-Side General Calibration Value                          */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  CLMD;                         /**< 0054: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLMS;                         /**< 0058: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM4;                         /**< 005C: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM3;                         /**< 0060: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM2;                         /**< 0064: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM1;                         /**< 0068: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM0;                         /**< 006C: Minus-Side General Calibration Value                         */
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
#define ADC_SC1_ADCH_MASK                        (0x1FU)                                             /*!< ADC0_SC1: ADCH Mask                     */
#define ADC_SC1_ADCH_SHIFT                       (0U)                                                /*!< ADC0_SC1: ADCH Position                 */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_DIFF_MASK                        (0x20U)                                             /*!< ADC0_SC1: DIFF Mask                     */
#define ADC_SC1_DIFF_SHIFT                       (5U)                                                /*!< ADC0_SC1: DIFF Position                 */
#define ADC_SC1_DIFF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_DIFF_SHIFT))&ADC_SC1_DIFF_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_AIEN_MASK                        (0x40U)                                             /*!< ADC0_SC1: AIEN Mask                     */
#define ADC_SC1_AIEN_SHIFT                       (6U)                                                /*!< ADC0_SC1: AIEN Position                 */
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_AIEN_SHIFT))&ADC_SC1_AIEN_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_COCO_MASK                        (0x80U)                                             /*!< ADC0_SC1: COCO Mask                     */
#define ADC_SC1_COCO_SHIFT                       (7U)                                                /*!< ADC0_SC1: COCO Position                 */
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_COCO_SHIFT))&ADC_SC1_COCO_MASK) /*!< ADC0_SC1                                */
/* ------- CFG1 Bit Fields                          ------ */
#define ADC_CFG1_ADICLK_MASK                     (0x3U)                                              /*!< ADC0_CFG1: ADICLK Mask                  */
#define ADC_CFG1_ADICLK_SHIFT                    (0U)                                                /*!< ADC0_CFG1: ADICLK Position              */
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_MODE_MASK                       (0xCU)                                              /*!< ADC0_CFG1: MODE Mask                    */
#define ADC_CFG1_MODE_SHIFT                      (2U)                                                /*!< ADC0_CFG1: MODE Position                */
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLSMP_MASK                     (0x10U)                                             /*!< ADC0_CFG1: ADLSMP Mask                  */
#define ADC_CFG1_ADLSMP_SHIFT                    (4U)                                                /*!< ADC0_CFG1: ADLSMP Position              */
#define ADC_CFG1_ADLSMP(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLSMP_SHIFT))&ADC_CFG1_ADLSMP_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADIV_MASK                       (0x60U)                                             /*!< ADC0_CFG1: ADIV Mask                    */
#define ADC_CFG1_ADIV_SHIFT                      (5U)                                                /*!< ADC0_CFG1: ADIV Position                */
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLPC_MASK                      (0x80U)                                             /*!< ADC0_CFG1: ADLPC Mask                   */
#define ADC_CFG1_ADLPC_SHIFT                     (7U)                                                /*!< ADC0_CFG1: ADLPC Position               */
#define ADC_CFG1_ADLPC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLPC_SHIFT))&ADC_CFG1_ADLPC_MASK) /*!< ADC0_CFG1                               */
/* ------- CFG2 Bit Fields                          ------ */
#define ADC_CFG2_ADLSTS_MASK                     (0x3U)                                              /*!< ADC0_CFG2: ADLSTS Mask                  */
#define ADC_CFG2_ADLSTS_SHIFT                    (0U)                                                /*!< ADC0_CFG2: ADLSTS Position              */
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_ADHSC_MASK                      (0x4U)                                              /*!< ADC0_CFG2: ADHSC Mask                   */
#define ADC_CFG2_ADHSC_SHIFT                     (2U)                                                /*!< ADC0_CFG2: ADHSC Position               */
#define ADC_CFG2_ADHSC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADHSC_SHIFT))&ADC_CFG2_ADHSC_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_ADACKEN_MASK                    (0x8U)                                              /*!< ADC0_CFG2: ADACKEN Mask                 */
#define ADC_CFG2_ADACKEN_SHIFT                   (3U)                                                /*!< ADC0_CFG2: ADACKEN Position             */
#define ADC_CFG2_ADACKEN(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADACKEN_SHIFT))&ADC_CFG2_ADACKEN_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_MUXSEL_MASK                     (0x10U)                                             /*!< ADC0_CFG2: MUXSEL Mask                  */
#define ADC_CFG2_MUXSEL_SHIFT                    (4U)                                                /*!< ADC0_CFG2: MUXSEL Position              */
#define ADC_CFG2_MUXSEL(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_MUXSEL_SHIFT))&ADC_CFG2_MUXSEL_MASK) /*!< ADC0_CFG2                               */
/* ------- R Bit Fields                             ------ */
#define ADC_R_D_MASK                             (0xFFFFU)                                           /*!< ADC0_R: D Mask                          */
#define ADC_R_D_SHIFT                            (0U)                                                /*!< ADC0_R: D Position                      */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK) /*!< ADC0_R                                  */
/* ------- CV Bit Fields                            ------ */
#define ADC_CV_CV_MASK                           (0xFFFFU)                                           /*!< ADC0_CV: CV Mask                        */
#define ADC_CV_CV_SHIFT                          (0U)                                                /*!< ADC0_CV: CV Position                    */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK) /*!< ADC0_CV                                 */
/* ------- SC2 Bit Fields                           ------ */
#define ADC_SC2_REFSEL_MASK                      (0x3U)                                              /*!< ADC0_SC2: REFSEL Mask                   */
#define ADC_SC2_REFSEL_SHIFT                     (0U)                                                /*!< ADC0_SC2: REFSEL Position               */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_DMAEN_MASK                       (0x4U)                                              /*!< ADC0_SC2: DMAEN Mask                    */
#define ADC_SC2_DMAEN_SHIFT                      (2U)                                                /*!< ADC0_SC2: DMAEN Position                */
#define ADC_SC2_DMAEN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_DMAEN_SHIFT))&ADC_SC2_DMAEN_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACREN_MASK                       (0x8U)                                              /*!< ADC0_SC2: ACREN Mask                    */
#define ADC_SC2_ACREN_SHIFT                      (3U)                                                /*!< ADC0_SC2: ACREN Position                */
#define ADC_SC2_ACREN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACREN_SHIFT))&ADC_SC2_ACREN_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACFGT_MASK                       (0x10U)                                             /*!< ADC0_SC2: ACFGT Mask                    */
#define ADC_SC2_ACFGT_SHIFT                      (4U)                                                /*!< ADC0_SC2: ACFGT Position                */
#define ADC_SC2_ACFGT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFGT_SHIFT))&ADC_SC2_ACFGT_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACFE_MASK                        (0x20U)                                             /*!< ADC0_SC2: ACFE Mask                     */
#define ADC_SC2_ACFE_SHIFT                       (5U)                                                /*!< ADC0_SC2: ACFE Position                 */
#define ADC_SC2_ACFE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFE_SHIFT))&ADC_SC2_ACFE_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ADTRG_MASK                       (0x40U)                                             /*!< ADC0_SC2: ADTRG Mask                    */
#define ADC_SC2_ADTRG_SHIFT                      (6U)                                                /*!< ADC0_SC2: ADTRG Position                */
#define ADC_SC2_ADTRG(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADTRG_SHIFT))&ADC_SC2_ADTRG_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ADACT_MASK                       (0x80U)                                             /*!< ADC0_SC2: ADACT Mask                    */
#define ADC_SC2_ADACT_SHIFT                      (7U)                                                /*!< ADC0_SC2: ADACT Position                */
#define ADC_SC2_ADACT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADACT_SHIFT))&ADC_SC2_ADACT_MASK) /*!< ADC0_SC2                                */
/* ------- SC3 Bit Fields                           ------ */
#define ADC_SC3_AVGS_MASK                        (0x3U)                                              /*!< ADC0_SC3: AVGS Mask                     */
#define ADC_SC3_AVGS_SHIFT                       (0U)                                                /*!< ADC0_SC3: AVGS Position                 */
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_AVGE_MASK                        (0x4U)                                              /*!< ADC0_SC3: AVGE Mask                     */
#define ADC_SC3_AVGE_SHIFT                       (2U)                                                /*!< ADC0_SC3: AVGE Position                 */
#define ADC_SC3_AVGE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGE_SHIFT))&ADC_SC3_AVGE_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_ADCO_MASK                        (0x8U)                                              /*!< ADC0_SC3: ADCO Mask                     */
#define ADC_SC3_ADCO_SHIFT                       (3U)                                                /*!< ADC0_SC3: ADCO Position                 */
#define ADC_SC3_ADCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADCO_SHIFT))&ADC_SC3_ADCO_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_CALF_MASK                        (0x40U)                                             /*!< ADC0_SC3: CALF Mask                     */
#define ADC_SC3_CALF_SHIFT                       (6U)                                                /*!< ADC0_SC3: CALF Position                 */
#define ADC_SC3_CALF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CALF_SHIFT))&ADC_SC3_CALF_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_CAL_MASK                         (0x80U)                                             /*!< ADC0_SC3: CAL Mask                      */
#define ADC_SC3_CAL_SHIFT                        (7U)                                                /*!< ADC0_SC3: CAL Position                  */
#define ADC_SC3_CAL(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CAL_SHIFT))&ADC_SC3_CAL_MASK) /*!< ADC0_SC3                                */
/* ------- OFS Bit Fields                           ------ */
#define ADC_OFS_OFS_MASK                         (0xFFFFU)                                           /*!< ADC0_OFS: OFS Mask                      */
#define ADC_OFS_OFS_SHIFT                        (0U)                                                /*!< ADC0_OFS: OFS Position                  */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK) /*!< ADC0_OFS                                */
/* ------- PG Bit Fields                            ------ */
#define ADC_PG_PG_MASK                           (0xFFFFU)                                           /*!< ADC0_PG: PG Mask                        */
#define ADC_PG_PG_SHIFT                          (0U)                                                /*!< ADC0_PG: PG Position                    */
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK) /*!< ADC0_PG                                 */
/* ------- MG Bit Fields                            ------ */
#define ADC_MG_MG_MASK                           (0xFFFFU)                                           /*!< ADC0_MG: MG Mask                        */
#define ADC_MG_MG_SHIFT                          (0U)                                                /*!< ADC0_MG: MG Position                    */
#define ADC_MG_MG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_MG_MG_SHIFT))&ADC_MG_MG_MASK) /*!< ADC0_MG                                 */
/* ------- CLPD Bit Fields                          ------ */
#define ADC_CLPD_CLPD_MASK                       (0x3FU)                                             /*!< ADC0_CLPD: CLPD Mask                    */
#define ADC_CLPD_CLPD_SHIFT                      (0U)                                                /*!< ADC0_CLPD: CLPD Position                */
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK) /*!< ADC0_CLPD                               */
/* ------- CLPS Bit Fields                          ------ */
#define ADC_CLPS_CLPS_MASK                       (0x3FU)                                             /*!< ADC0_CLPS: CLPS Mask                    */
#define ADC_CLPS_CLPS_SHIFT                      (0U)                                                /*!< ADC0_CLPS: CLPS Position                */
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK) /*!< ADC0_CLPS                               */
/* ------- CLP4 Bit Fields                          ------ */
#define ADC_CLP4_CLP4_MASK                       (0x3FFU)                                            /*!< ADC0_CLP4: CLP4 Mask                    */
#define ADC_CLP4_CLP4_SHIFT                      (0U)                                                /*!< ADC0_CLP4: CLP4 Position                */
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK) /*!< ADC0_CLP4                               */
/* ------- CLP3 Bit Fields                          ------ */
#define ADC_CLP3_CLP3_MASK                       (0x1FFU)                                            /*!< ADC0_CLP3: CLP3 Mask                    */
#define ADC_CLP3_CLP3_SHIFT                      (0U)                                                /*!< ADC0_CLP3: CLP3 Position                */
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK) /*!< ADC0_CLP3                               */
/* ------- CLP2 Bit Fields                          ------ */
#define ADC_CLP2_CLP2_MASK                       (0xFFU)                                             /*!< ADC0_CLP2: CLP2 Mask                    */
#define ADC_CLP2_CLP2_SHIFT                      (0U)                                                /*!< ADC0_CLP2: CLP2 Position                */
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK) /*!< ADC0_CLP2                               */
/* ------- CLP1 Bit Fields                          ------ */
#define ADC_CLP1_CLP1_MASK                       (0x7FU)                                             /*!< ADC0_CLP1: CLP1 Mask                    */
#define ADC_CLP1_CLP1_SHIFT                      (0U)                                                /*!< ADC0_CLP1: CLP1 Position                */
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK) /*!< ADC0_CLP1                               */
/* ------- CLP0 Bit Fields                          ------ */
#define ADC_CLP0_CLP0_MASK                       (0x3FU)                                             /*!< ADC0_CLP0: CLP0 Mask                    */
#define ADC_CLP0_CLP0_SHIFT                      (0U)                                                /*!< ADC0_CLP0: CLP0 Position                */
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK) /*!< ADC0_CLP0                               */
/* ------- CLMD Bit Fields                          ------ */
#define ADC_CLMD_CLMD_MASK                       (0x3FU)                                             /*!< ADC0_CLMD: CLMD Mask                    */
#define ADC_CLMD_CLMD_SHIFT                      (0U)                                                /*!< ADC0_CLMD: CLMD Position                */
#define ADC_CLMD_CLMD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMD_CLMD_SHIFT))&ADC_CLMD_CLMD_MASK) /*!< ADC0_CLMD                               */
/* ------- CLMS Bit Fields                          ------ */
#define ADC_CLMS_CLMS_MASK                       (0x3FU)                                             /*!< ADC0_CLMS: CLMS Mask                    */
#define ADC_CLMS_CLMS_SHIFT                      (0U)                                                /*!< ADC0_CLMS: CLMS Position                */
#define ADC_CLMS_CLMS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMS_CLMS_SHIFT))&ADC_CLMS_CLMS_MASK) /*!< ADC0_CLMS                               */
/* ------- CLM4 Bit Fields                          ------ */
#define ADC_CLM4_CLM4_MASK                       (0x3FFU)                                            /*!< ADC0_CLM4: CLM4 Mask                    */
#define ADC_CLM4_CLM4_SHIFT                      (0U)                                                /*!< ADC0_CLM4: CLM4 Position                */
#define ADC_CLM4_CLM4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM4_CLM4_SHIFT))&ADC_CLM4_CLM4_MASK) /*!< ADC0_CLM4                               */
/* ------- CLM3 Bit Fields                          ------ */
#define ADC_CLM3_CLM3_MASK                       (0x1FFU)                                            /*!< ADC0_CLM3: CLM3 Mask                    */
#define ADC_CLM3_CLM3_SHIFT                      (0U)                                                /*!< ADC0_CLM3: CLM3 Position                */
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM3_CLM3_SHIFT))&ADC_CLM3_CLM3_MASK) /*!< ADC0_CLM3                               */
/* ------- CLM2 Bit Fields                          ------ */
#define ADC_CLM2_CLM2_MASK                       (0xFFU)                                             /*!< ADC0_CLM2: CLM2 Mask                    */
#define ADC_CLM2_CLM2_SHIFT                      (0U)                                                /*!< ADC0_CLM2: CLM2 Position                */
#define ADC_CLM2_CLM2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM2_CLM2_SHIFT))&ADC_CLM2_CLM2_MASK) /*!< ADC0_CLM2                               */
/* ------- CLM1 Bit Fields                          ------ */
#define ADC_CLM1_CLM1_MASK                       (0x7FU)                                             /*!< ADC0_CLM1: CLM1 Mask                    */
#define ADC_CLM1_CLM1_SHIFT                      (0U)                                                /*!< ADC0_CLM1: CLM1 Position                */
#define ADC_CLM1_CLM1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM1_CLM1_SHIFT))&ADC_CLM1_CLM1_MASK) /*!< ADC0_CLM1                               */
/* ------- CLM0 Bit Fields                          ------ */
#define ADC_CLM0_CLM0_MASK                       (0x3FU)                                             /*!< ADC0_CLM0: CLM0 Mask                    */
#define ADC_CLM0_CLM0_SHIFT                      (0U)                                                /*!< ADC0_CLM0: CLM0 Position                */
#define ADC_CLM0_CLM0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM0_CLM0_SHIFT))&ADC_CLM0_CLM0_MASK) /*!< ADC0_CLM0                               */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC0 - Peripheral instance base addresses */
#define ADC0_BasePtr                   0x4003B000UL //!< Peripheral base address
#define ADC0                           ((ADC_Type *) ADC0_BasePtr) //!< Freescale base pointer
#define ADC0_BASE_PTR                  (ADC0) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup BP_Peripheral_access_layer_GROUP BP Peripheral Access Layer
* @brief C Struct for BP
* @{
*/

/* ================================================================================ */
/* ================           BP (file:BP_CM0)                     ================ */
/* ================================================================================ */

/**
 * @brief Breakpoint Unit
 */
/**
* @addtogroup BP_structs_GROUP BP struct
* @brief Struct for BP
* @{
*/
typedef struct {                                /*       BP Structure                                                 */
   __IO uint32_t  CTRL;                         /**< 0000: FlashPatch Control Register                                  */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  COMP[2];                      /**< 0008: FlashPatch Comparator Register                               */
        uint8_t   RESERVED_1[4032];            
   __I  uint32_t  PID4;                         /**< 0FD0: Peripheral Identification Register 4                         */
   __I  uint32_t  PID5;                         /**< 0FD4: Peripheral Identification Register 5                         */
   __I  uint32_t  PID6;                         /**< 0FD8: Peripheral Identification Register 6                         */
   __I  uint32_t  PID7;                         /**< 0FDC: Peripheral Identification Register 7                         */
   __I  uint32_t  PID0;                         /**< 0FE0: Peripheral Identification Register 0                         */
   __I  uint32_t  PID1;                         /**< 0FE4: Peripheral Identification Register 1                         */
   __I  uint32_t  PID2;                         /**< 0FE8: Peripheral Identification Register 2                         */
   __I  uint32_t  PID3;                         /**< 0FEC: Peripheral Identification Register 3                         */
   __I  uint32_t  CID[4];                       /**< 0FF0: Component Identification Register 0                          */
} BP_Type;

/**
 * @} */ /* End group BP_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'BP' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup BP_Register_Masks_GROUP BP Register Masks
* @brief Register Masks for BP
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define BP_CTRL_ENABLE_MASK                      (0x1U)                                              /*!< BP_CTRL: ENABLE Mask                    */
#define BP_CTRL_ENABLE_SHIFT                     (0U)                                                /*!< BP_CTRL: ENABLE Position                */
#define BP_CTRL_ENABLE(x)                        (((uint32_t)(((uint32_t)(x))<<BP_CTRL_ENABLE_SHIFT))&BP_CTRL_ENABLE_MASK) /*!< BP_CTRL                                 */
#define BP_CTRL_KEY_MASK                         (0x2U)                                              /*!< BP_CTRL: KEY Mask                       */
#define BP_CTRL_KEY_SHIFT                        (1U)                                                /*!< BP_CTRL: KEY Position                   */
#define BP_CTRL_KEY(x)                           (((uint32_t)(((uint32_t)(x))<<BP_CTRL_KEY_SHIFT))&BP_CTRL_KEY_MASK) /*!< BP_CTRL                                 */
#define BP_CTRL_NUM_CODE_MASK                    (0xF0U)                                             /*!< BP_CTRL: NUM_CODE Mask                  */
#define BP_CTRL_NUM_CODE_SHIFT                   (4U)                                                /*!< BP_CTRL: NUM_CODE Position              */
#define BP_CTRL_NUM_CODE(x)                      (((uint32_t)(((uint32_t)(x))<<BP_CTRL_NUM_CODE_SHIFT))&BP_CTRL_NUM_CODE_MASK) /*!< BP_CTRL                                 */
/* ------- COMP Bit Fields                          ------ */
#define BP_COMP_ENABLE_MASK                      (0x1U)                                              /*!< BP_COMP: ENABLE Mask                    */
#define BP_COMP_ENABLE_SHIFT                     (0U)                                                /*!< BP_COMP: ENABLE Position                */
#define BP_COMP_ENABLE(x)                        (((uint32_t)(((uint32_t)(x))<<BP_COMP_ENABLE_SHIFT))&BP_COMP_ENABLE_MASK) /*!< BP_COMP                                 */
#define BP_COMP_COMP_MASK                        (0x1FFFFFFCU)                                       /*!< BP_COMP: COMP Mask                      */
#define BP_COMP_COMP_SHIFT                       (2U)                                                /*!< BP_COMP: COMP Position                  */
#define BP_COMP_COMP(x)                          (((uint32_t)(((uint32_t)(x))<<BP_COMP_COMP_SHIFT))&BP_COMP_COMP_MASK) /*!< BP_COMP                                 */
#define BP_COMP_BP_MATCH_MASK                    (0xC0000000U)                                       /*!< BP_COMP: BP_MATCH Mask                  */
#define BP_COMP_BP_MATCH_SHIFT                   (30U)                                               /*!< BP_COMP: BP_MATCH Position              */
#define BP_COMP_BP_MATCH(x)                      (((uint32_t)(((uint32_t)(x))<<BP_COMP_BP_MATCH_SHIFT))&BP_COMP_BP_MATCH_MASK) /*!< BP_COMP                                 */
/* ------- PID Bit Fields                           ------ */
/* ------- CID Bit Fields                           ------ */
/**
 * @} */ /* End group BP_Register_Masks_GROUP 
 */

/* BP - Peripheral instance base addresses */
#define BP_BasePtr                     0xE0002000UL //!< Peripheral base address
#define BP                             ((BP_Type *) BP_BasePtr) //!< Freescale base pointer
#define BP_BASE_PTR                    (BP) //!< Freescale style base pointer
/**
 * @} */ /* End group BP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP0 (file:CMP0_PSTM_TRIGM)          ================ */
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
#define CMP_CR0_HYSTCTR_MASK                     (0x3U)                                              /*!< CMP0_CR0: HYSTCTR Mask                  */
#define CMP_CR0_HYSTCTR_SHIFT                    (0U)                                                /*!< CMP0_CR0: HYSTCTR Position              */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK) /*!< CMP0_CR0                                */
#define CMP_CR0_FILTER_CNT_MASK                  (0x70U)                                             /*!< CMP0_CR0: FILTER_CNT Mask               */
#define CMP_CR0_FILTER_CNT_SHIFT                 (4U)                                                /*!< CMP0_CR0: FILTER_CNT Position           */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK) /*!< CMP0_CR0                                */
/* ------- CR1 Bit Fields                           ------ */
#define CMP_CR1_EN_MASK                          (0x1U)                                              /*!< CMP0_CR1: EN Mask                       */
#define CMP_CR1_EN_SHIFT                         (0U)                                                /*!< CMP0_CR1: EN Position                   */
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_EN_SHIFT))&CMP_CR1_EN_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_OPE_MASK                         (0x2U)                                              /*!< CMP0_CR1: OPE Mask                      */
#define CMP_CR1_OPE_SHIFT                        (1U)                                                /*!< CMP0_CR1: OPE Position                  */
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_OPE_SHIFT))&CMP_CR1_OPE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_COS_MASK                         (0x4U)                                              /*!< CMP0_CR1: COS Mask                      */
#define CMP_CR1_COS_SHIFT                        (2U)                                                /*!< CMP0_CR1: COS Position                  */
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_COS_SHIFT))&CMP_CR1_COS_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_INV_MASK                         (0x8U)                                              /*!< CMP0_CR1: INV Mask                      */
#define CMP_CR1_INV_SHIFT                        (3U)                                                /*!< CMP0_CR1: INV Position                  */
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_INV_SHIFT))&CMP_CR1_INV_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_PMODE_MASK                       (0x10U)                                             /*!< CMP0_CR1: PMODE Mask                    */
#define CMP_CR1_PMODE_SHIFT                      (4U)                                                /*!< CMP0_CR1: PMODE Position                */
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_PMODE_SHIFT))&CMP_CR1_PMODE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_TRIGM_MASK                       (0x20U)                                             /*!< CMP0_CR1: TRIGM Mask                    */
#define CMP_CR1_TRIGM_SHIFT                      (5U)                                                /*!< CMP0_CR1: TRIGM Position                */
#define CMP_CR1_TRIGM(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_TRIGM_SHIFT))&CMP_CR1_TRIGM_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_WE_MASK                          (0x40U)                                             /*!< CMP0_CR1: WE Mask                       */
#define CMP_CR1_WE_SHIFT                         (6U)                                                /*!< CMP0_CR1: WE Position                   */
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_WE_SHIFT))&CMP_CR1_WE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_SE_MASK                          (0x80U)                                             /*!< CMP0_CR1: SE Mask                       */
#define CMP_CR1_SE_SHIFT                         (7U)                                                /*!< CMP0_CR1: SE Position                   */
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_SE_SHIFT))&CMP_CR1_SE_MASK) /*!< CMP0_CR1                                */
/* ------- FPR Bit Fields                           ------ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFU)                                             /*!< CMP0_FPR: FILT_PER Mask                 */
#define CMP_FPR_FILT_PER_SHIFT                   (0U)                                                /*!< CMP0_FPR: FILT_PER Position             */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK) /*!< CMP0_FPR                                */
/* ------- SCR Bit Fields                           ------ */
#define CMP_SCR_COUT_MASK                        (0x1U)                                              /*!< CMP0_SCR: COUT Mask                     */
#define CMP_SCR_COUT_SHIFT                       (0U)                                                /*!< CMP0_SCR: COUT Position                 */
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x))<<CMP_SCR_COUT_SHIFT))&CMP_SCR_COUT_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_CFF_MASK                         (0x2U)                                              /*!< CMP0_SCR: CFF Mask                      */
#define CMP_SCR_CFF_SHIFT                        (1U)                                                /*!< CMP0_SCR: CFF Position                  */
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFF_SHIFT))&CMP_SCR_CFF_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_CFR_MASK                         (0x4U)                                              /*!< CMP0_SCR: CFR Mask                      */
#define CMP_SCR_CFR_SHIFT                        (2U)                                                /*!< CMP0_SCR: CFR Position                  */
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFR_SHIFT))&CMP_SCR_CFR_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_IEF_MASK                         (0x8U)                                              /*!< CMP0_SCR: IEF Mask                      */
#define CMP_SCR_IEF_SHIFT                        (3U)                                                /*!< CMP0_SCR: IEF Position                  */
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IEF_SHIFT))&CMP_SCR_IEF_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_IER_MASK                         (0x10U)                                             /*!< CMP0_SCR: IER Mask                      */
#define CMP_SCR_IER_SHIFT                        (4U)                                                /*!< CMP0_SCR: IER Position                  */
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IER_SHIFT))&CMP_SCR_IER_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_DMAEN_MASK                       (0x40U)                                             /*!< CMP0_SCR: DMAEN Mask                    */
#define CMP_SCR_DMAEN_SHIFT                      (6U)                                                /*!< CMP0_SCR: DMAEN Position                */
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_SCR_DMAEN_SHIFT))&CMP_SCR_DMAEN_MASK) /*!< CMP0_SCR                                */
/* ------- DACCR Bit Fields                         ------ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FU)                                             /*!< CMP0_DACCR: VOSEL Mask                  */
#define CMP_DACCR_VOSEL_SHIFT                    (0U)                                                /*!< CMP0_DACCR: VOSEL Position              */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_VRSEL_MASK                     (0x40U)                                             /*!< CMP0_DACCR: VRSEL Mask                  */
#define CMP_DACCR_VRSEL_SHIFT                    (6U)                                                /*!< CMP0_DACCR: VRSEL Position              */
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VRSEL_SHIFT))&CMP_DACCR_VRSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_DACEN_MASK                     (0x80U)                                             /*!< CMP0_DACCR: DACEN Mask                  */
#define CMP_DACCR_DACEN_SHIFT                    (7U)                                                /*!< CMP0_DACCR: DACEN Position              */
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_DACEN_SHIFT))&CMP_DACCR_DACEN_MASK) /*!< CMP0_DACCR                              */
/* ------- MUXCR Bit Fields                         ------ */
#define CMP_MUXCR_MSEL_MASK                      (0x7U)                                              /*!< CMP0_MUXCR: MSEL Mask                   */
#define CMP_MUXCR_MSEL_SHIFT                     (0U)                                                /*!< CMP0_MUXCR: MSEL Position               */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_PSEL_MASK                      (0x38U)                                             /*!< CMP0_MUXCR: PSEL Mask                   */
#define CMP_MUXCR_PSEL_SHIFT                     (3U)                                                /*!< CMP0_MUXCR: PSEL Position               */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_PSTM_MASK                      (0x80U)                                             /*!< CMP0_MUXCR: PSTM Mask                   */
#define CMP_MUXCR_PSTM_SHIFT                     (7U)                                                /*!< CMP0_MUXCR: PSTM Position               */
#define CMP_MUXCR_PSTM(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSTM_SHIFT))&CMP_MUXCR_PSTM_MASK) /*!< CMP0_MUXCR                              */
/**
 * @} */ /* End group CMP_Register_Masks_GROUP 
 */

/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0x40073000UL //!< Peripheral base address
#define CMP0                           ((CMP_Type *) CMP0_BasePtr) //!< Freescale base pointer
#define CMP0_BASE_PTR                  (CMP0) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DAC_Peripheral_access_layer_GROUP DAC Peripheral Access Layer
* @brief C Struct for DAC
* @{
*/

/* ================================================================================ */
/* ================           DAC0 (file:DAC0_2CH_FIFO_MKL17)       ================ */
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
   union {                                      /**< 0000: (size=0004)                                                  */
      struct {
         __IO uint8_t   DATL;                   /**< 0000: Data Low Register                                            */
         __IO uint8_t   DATH;                   /**< 0001: Data High Register                                           */
      } DAT[2];                                 /**< 0000: (cluster: size=0x0004, 4)                                    */
      __IO uint16_t  DATA[2];                   /**< 0000: Data Register                                                */
   };
        uint8_t   RESERVED_1[28];              
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
/* ------- DATL Bit Fields                          ------ */
#define DAC_DATL_DATA_MASK                       (0xFFU)                                             /*!< DAC0_DATL: DATA Mask                    */
#define DAC_DATL_DATA_SHIFT                      (0U)                                                /*!< DAC0_DATL: DATA Position                */
#define DAC_DATL_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA_SHIFT))&DAC_DATL_DATA_MASK) /*!< DAC0_DATL                               */
/* ------- DATH Bit Fields                          ------ */
#define DAC_DATH_DATA_MASK                       (0xFU)                                              /*!< DAC0_DATH: DATA Mask                    */
#define DAC_DATH_DATA_SHIFT                      (0U)                                                /*!< DAC0_DATH: DATA Position                */
#define DAC_DATH_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA_SHIFT))&DAC_DATH_DATA_MASK) /*!< DAC0_DATH                               */
/* ------- DATA Bit Fields                          ------ */
#define DAC_DATA_DATA_MASK                       (0xFFFU)                                            /*!< DAC0_DATA: DATA Mask                    */
#define DAC_DATA_DATA_SHIFT                      (0U)                                                /*!< DAC0_DATA: DATA Position                */
#define DAC_DATA_DATA(x)                         (((uint16_t)(((uint16_t)(x))<<DAC_DATA_DATA_SHIFT))&DAC_DATA_DATA_MASK) /*!< DAC0_DATA                               */
/* ------- SR Bit Fields                            ------ */
#define DAC_SR_DACBFRPBF_MASK                    (0x1U)                                              /*!< DAC0_SR: DACBFRPBF Mask                 */
#define DAC_SR_DACBFRPBF_SHIFT                   (0U)                                                /*!< DAC0_SR: DACBFRPBF Position             */
#define DAC_SR_DACBFRPBF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPBF_SHIFT))&DAC_SR_DACBFRPBF_MASK) /*!< DAC0_SR                                 */
#define DAC_SR_DACBFRPTF_MASK                    (0x2U)                                              /*!< DAC0_SR: DACBFRPTF Mask                 */
#define DAC_SR_DACBFRPTF_SHIFT                   (1U)                                                /*!< DAC0_SR: DACBFRPTF Position             */
#define DAC_SR_DACBFRPTF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPTF_SHIFT))&DAC_SR_DACBFRPTF_MASK) /*!< DAC0_SR                                 */
/* ------- C0 Bit Fields                            ------ */
#define DAC_C0_DACBBIEN_MASK                     (0x1U)                                              /*!< DAC0_C0: DACBBIEN Mask                  */
#define DAC_C0_DACBBIEN_SHIFT                    (0U)                                                /*!< DAC0_C0: DACBBIEN Position              */
#define DAC_C0_DACBBIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBBIEN_SHIFT))&DAC_C0_DACBBIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACBTIEN_MASK                     (0x2U)                                              /*!< DAC0_C0: DACBTIEN Mask                  */
#define DAC_C0_DACBTIEN_SHIFT                    (1U)                                                /*!< DAC0_C0: DACBTIEN Position              */
#define DAC_C0_DACBTIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBTIEN_SHIFT))&DAC_C0_DACBTIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACBWIEN_MASK                     (0x4U)                                              /*!< DAC0_C0: DACBWIEN Mask                  */
#define DAC_C0_DACBWIEN_SHIFT                    (2U)                                                /*!< DAC0_C0: DACBWIEN Position              */
#define DAC_C0_DACBWIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBWIEN_SHIFT))&DAC_C0_DACBWIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_LPEN_MASK                         (0x8U)                                              /*!< DAC0_C0: LPEN Mask                      */
#define DAC_C0_LPEN_SHIFT                        (3U)                                                /*!< DAC0_C0: LPEN Position                  */
#define DAC_C0_LPEN(x)                           (((uint8_t)(((uint8_t)(x))<<DAC_C0_LPEN_SHIFT))&DAC_C0_LPEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACSWTRG_MASK                     (0x10U)                                             /*!< DAC0_C0: DACSWTRG Mask                  */
#define DAC_C0_DACSWTRG_SHIFT                    (4U)                                                /*!< DAC0_C0: DACSWTRG Position              */
#define DAC_C0_DACSWTRG(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACSWTRG_SHIFT))&DAC_C0_DACSWTRG_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACTRGSEL_MASK                    (0x20U)                                             /*!< DAC0_C0: DACTRGSEL Mask                 */
#define DAC_C0_DACTRGSEL_SHIFT                   (5U)                                                /*!< DAC0_C0: DACTRGSEL Position             */
#define DAC_C0_DACTRGSEL(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACTRGSEL_SHIFT))&DAC_C0_DACTRGSEL_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACRFS_MASK                       (0x40U)                                             /*!< DAC0_C0: DACRFS Mask                    */
#define DAC_C0_DACRFS_SHIFT                      (6U)                                                /*!< DAC0_C0: DACRFS Position                */
#define DAC_C0_DACRFS(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACRFS_SHIFT))&DAC_C0_DACRFS_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACEN_MASK                        (0x80U)                                             /*!< DAC0_C0: DACEN Mask                     */
#define DAC_C0_DACEN_SHIFT                       (7U)                                                /*!< DAC0_C0: DACEN Position                 */
#define DAC_C0_DACEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACEN_SHIFT))&DAC_C0_DACEN_MASK) /*!< DAC0_C0                                 */
/* ------- C1 Bit Fields                            ------ */
#define DAC_C1_DACBFEN_MASK                      (0x1U)                                              /*!< DAC0_C1: DACBFEN Mask                   */
#define DAC_C1_DACBFEN_SHIFT                     (0U)                                                /*!< DAC0_C1: DACBFEN Position               */
#define DAC_C1_DACBFEN(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFEN_SHIFT))&DAC_C1_DACBFEN_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DACBFMD_MASK                      (0x6U)                                              /*!< DAC0_C1: DACBFMD Mask                   */
#define DAC_C1_DACBFMD_SHIFT                     (1U)                                                /*!< DAC0_C1: DACBFMD Position               */
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DMAEN_MASK                        (0x80U)                                             /*!< DAC0_C1: DMAEN Mask                     */
#define DAC_C1_DMAEN_SHIFT                       (7U)                                                /*!< DAC0_C1: DMAEN Position                 */
#define DAC_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C1_DMAEN_SHIFT))&DAC_C1_DMAEN_MASK) /*!< DAC0_C1                                 */
/* ------- C2 Bit Fields                            ------ */
#define DAC_C2_DACBFUP_MASK                      (0x1U)                                              /*!< DAC0_C2: DACBFUP Mask                   */
#define DAC_C2_DACBFUP_SHIFT                     (0U)                                                /*!< DAC0_C2: DACBFUP Position               */
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK) /*!< DAC0_C2                                 */
#define DAC_C2_DACBFRP_MASK                      (0x10U)                                             /*!< DAC0_C2: DACBFRP Mask                   */
#define DAC_C2_DACBFRP_SHIFT                     (4U)                                                /*!< DAC0_C2: DACBFRP Position               */
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK) /*!< DAC0_C2                                 */
/**
 * @} */ /* End group DAC_Register_Masks_GROUP 
 */

/* DAC0 - Peripheral instance base addresses */
#define DAC0_BasePtr                   0x4003F000UL //!< Peripheral base address
#define DAC0                           ((DAC_Type *) DAC0_BasePtr) //!< Freescale base pointer
#define DAC0_BASE_PTR                  (DAC0) //!< Freescale style base pointer
/**
 * @} */ /* End group DAC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA0_Peripheral_access_layer_GROUP DMA0 Peripheral Access Layer
* @brief C Struct for DMA0
* @{
*/

/* ================================================================================ */
/* ================           DMA0 (file:DMA0_MKL)                 ================ */
/* ================================================================================ */

/**
 * @brief Enhanced direct memory access controller
 */
/**
* @addtogroup DMA0_structs_GROUP DMA0 struct
* @brief Struct for DMA0
* @{
*/
typedef struct {                                /*       DMA0 Structure                                               */
        uint8_t   RESERVED_0[256];             
   struct {
      __IO uint32_t  SAR;                       /**< 0100: Source Address Register                                      */
      __IO uint32_t  DAR;                       /**< 0104: Destination Address Register                                 */
      union {                                   /**< 0100: (size=0004)                                                  */
         __IO uint32_t  DSR_BCR;                /**< 0108: DMA Status / Byte Count Register                             */
         struct {                               /**< 0100: (size=0004)                                                  */
                 uint8_t   RESERVED_1[3];      
            __IO uint8_t   DSR;                 /**< 010B: DMA Status Register                                          */
         };
      };
      __IO uint32_t  DCR;                       /**< 010C: DMA Control Register                                         */
   } DMA[4];                                    /**< 0100: (cluster: size=0x0040, 64)                                   */
} DMA_Type;

/**
 * @} */ /* End group DMA0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA0_Register_Masks_GROUP DMA0 Register Masks
* @brief Register Masks for DMA0
* @{
*/
/* ------- SAR Bit Fields                           ------ */
/* ------- DAR Bit Fields                           ------ */
/* ------- DSR_BCR Bit Fields                       ------ */
#define DMA_DSR_BCR_BCR_MASK                     (0xFFFFFFU)                                         /*!< DMA0_DSR_BCR: BCR Mask                  */
#define DMA_DSR_BCR_BCR_SHIFT                    (0U)                                                /*!< DMA0_DSR_BCR: BCR Position              */
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BCR_SHIFT))&DMA_DSR_BCR_BCR_MASK) /*!< DMA0_DSR_BCR                            */
#define DMA_DSR_BCR_DONE_MASK                    (0x1000000U)                                        /*!< DMA0_DSR_BCR: DONE Mask                 */
#define DMA_DSR_BCR_DONE_SHIFT                   (24U)                                               /*!< DMA0_DSR_BCR: DONE Position             */
#define DMA_DSR_BCR_DONE(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_DONE_SHIFT))&DMA_DSR_BCR_DONE_MASK) /*!< DMA0_DSR_BCR                            */
#define DMA_DSR_BCR_BSY_MASK                     (0x2000000U)                                        /*!< DMA0_DSR_BCR: BSY Mask                  */
#define DMA_DSR_BCR_BSY_SHIFT                    (25U)                                               /*!< DMA0_DSR_BCR: BSY Position              */
#define DMA_DSR_BCR_BSY(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BSY_SHIFT))&DMA_DSR_BCR_BSY_MASK) /*!< DMA0_DSR_BCR                            */
#define DMA_DSR_BCR_REQ_MASK                     (0x4000000U)                                        /*!< DMA0_DSR_BCR: REQ Mask                  */
#define DMA_DSR_BCR_REQ_SHIFT                    (26U)                                               /*!< DMA0_DSR_BCR: REQ Position              */
#define DMA_DSR_BCR_REQ(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_REQ_SHIFT))&DMA_DSR_BCR_REQ_MASK) /*!< DMA0_DSR_BCR                            */
#define DMA_DSR_BCR_BED_MASK                     (0x10000000U)                                       /*!< DMA0_DSR_BCR: BED Mask                  */
#define DMA_DSR_BCR_BED_SHIFT                    (28U)                                               /*!< DMA0_DSR_BCR: BED Position              */
#define DMA_DSR_BCR_BED(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BED_SHIFT))&DMA_DSR_BCR_BED_MASK) /*!< DMA0_DSR_BCR                            */
#define DMA_DSR_BCR_BES_MASK                     (0x20000000U)                                       /*!< DMA0_DSR_BCR: BES Mask                  */
#define DMA_DSR_BCR_BES_SHIFT                    (29U)                                               /*!< DMA0_DSR_BCR: BES Position              */
#define DMA_DSR_BCR_BES(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BES_SHIFT))&DMA_DSR_BCR_BES_MASK) /*!< DMA0_DSR_BCR                            */
#define DMA_DSR_BCR_CE_MASK                      (0x40000000U)                                       /*!< DMA0_DSR_BCR: CE Mask                   */
#define DMA_DSR_BCR_CE_SHIFT                     (30U)                                               /*!< DMA0_DSR_BCR: CE Position               */
#define DMA_DSR_BCR_CE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_CE_SHIFT))&DMA_DSR_BCR_CE_MASK) /*!< DMA0_DSR_BCR                            */
/* ------- DSR Bit Fields                           ------ */
#define DMA_DSR_DONE_MASK                        (0x1U)                                              /*!< DMA0_DSR: DONE Mask                     */
#define DMA_DSR_DONE_SHIFT                       (0U)                                                /*!< DMA0_DSR: DONE Position                 */
#define DMA_DSR_DONE(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_DSR_DONE_SHIFT))&DMA_DSR_DONE_MASK) /*!< DMA0_DSR                                */
#define DMA_DSR_BSY_MASK                         (0x2U)                                              /*!< DMA0_DSR: BSY Mask                      */
#define DMA_DSR_BSY_SHIFT                        (1U)                                                /*!< DMA0_DSR: BSY Position                  */
#define DMA_DSR_BSY(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BSY_SHIFT))&DMA_DSR_BSY_MASK) /*!< DMA0_DSR                                */
#define DMA_DSR_REQ_MASK                         (0x4U)                                              /*!< DMA0_DSR: REQ Mask                      */
#define DMA_DSR_REQ_SHIFT                        (2U)                                                /*!< DMA0_DSR: REQ Position                  */
#define DMA_DSR_REQ(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_REQ_SHIFT))&DMA_DSR_REQ_MASK) /*!< DMA0_DSR                                */
#define DMA_DSR_BED_MASK                         (0x10U)                                             /*!< DMA0_DSR: BED Mask                      */
#define DMA_DSR_BED_SHIFT                        (4U)                                                /*!< DMA0_DSR: BED Position                  */
#define DMA_DSR_BED(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BED_SHIFT))&DMA_DSR_BED_MASK) /*!< DMA0_DSR                                */
#define DMA_DSR_BES_MASK                         (0x20U)                                             /*!< DMA0_DSR: BES Mask                      */
#define DMA_DSR_BES_SHIFT                        (5U)                                                /*!< DMA0_DSR: BES Position                  */
#define DMA_DSR_BES(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BES_SHIFT))&DMA_DSR_BES_MASK) /*!< DMA0_DSR                                */
#define DMA_DSR_CE_MASK                          (0x40U)                                             /*!< DMA0_DSR: CE Mask                       */
#define DMA_DSR_CE_SHIFT                         (6U)                                                /*!< DMA0_DSR: CE Position                   */
#define DMA_DSR_CE(x)                            (((uint8_t)(((uint8_t)(x))<<DMA_DSR_CE_SHIFT))&DMA_DSR_CE_MASK) /*!< DMA0_DSR                                */
/* ------- DCR Bit Fields                           ------ */
#define DMA_DCR_LCH2_MASK                        (0x3U)                                              /*!< DMA0_DCR: LCH2 Mask                     */
#define DMA_DCR_LCH2_SHIFT                       (0U)                                                /*!< DMA0_DCR: LCH2 Position                 */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH2_SHIFT))&DMA_DCR_LCH2_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_LCH1_MASK                        (0xCU)                                              /*!< DMA0_DCR: LCH1 Mask                     */
#define DMA_DCR_LCH1_SHIFT                       (2U)                                                /*!< DMA0_DCR: LCH1 Position                 */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH1_SHIFT))&DMA_DCR_LCH1_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_LINKCC_MASK                      (0x30U)                                             /*!< DMA0_DCR: LINKCC Mask                   */
#define DMA_DCR_LINKCC_SHIFT                     (4U)                                                /*!< DMA0_DCR: LINKCC Position               */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LINKCC_SHIFT))&DMA_DCR_LINKCC_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_D_REQ_MASK                       (0x80U)                                             /*!< DMA0_DCR: D_REQ Mask                    */
#define DMA_DCR_D_REQ_SHIFT                      (7U)                                                /*!< DMA0_DCR: D_REQ Position                */
#define DMA_DCR_D_REQ(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_D_REQ_SHIFT))&DMA_DCR_D_REQ_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_DMOD_MASK                        (0xF00U)                                            /*!< DMA0_DCR: DMOD Mask                     */
#define DMA_DCR_DMOD_SHIFT                       (8U)                                                /*!< DMA0_DCR: DMOD Position                 */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DMOD_SHIFT))&DMA_DCR_DMOD_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_SMOD_MASK                        (0xF000U)                                           /*!< DMA0_DCR: SMOD Mask                     */
#define DMA_DCR_SMOD_SHIFT                       (12U)                                               /*!< DMA0_DCR: SMOD Position                 */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SMOD_SHIFT))&DMA_DCR_SMOD_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_START_MASK                       (0x10000U)                                          /*!< DMA0_DCR: START Mask                    */
#define DMA_DCR_START_SHIFT                      (16U)                                               /*!< DMA0_DCR: START Position                */
#define DMA_DCR_START(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_START_SHIFT))&DMA_DCR_START_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_DSIZE_MASK                       (0x60000U)                                          /*!< DMA0_DCR: DSIZE Mask                    */
#define DMA_DCR_DSIZE_SHIFT                      (17U)                                               /*!< DMA0_DCR: DSIZE Position                */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DSIZE_SHIFT))&DMA_DCR_DSIZE_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_DINC_MASK                        (0x80000U)                                          /*!< DMA0_DCR: DINC Mask                     */
#define DMA_DCR_DINC_SHIFT                       (19U)                                               /*!< DMA0_DCR: DINC Position                 */
#define DMA_DCR_DINC(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DINC_SHIFT))&DMA_DCR_DINC_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_SSIZE_MASK                       (0x300000U)                                         /*!< DMA0_DCR: SSIZE Mask                    */
#define DMA_DCR_SSIZE_SHIFT                      (20U)                                               /*!< DMA0_DCR: SSIZE Position                */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SSIZE_SHIFT))&DMA_DCR_SSIZE_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_SINC_MASK                        (0x400000U)                                         /*!< DMA0_DCR: SINC Mask                     */
#define DMA_DCR_SINC_SHIFT                       (22U)                                               /*!< DMA0_DCR: SINC Position                 */
#define DMA_DCR_SINC(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SINC_SHIFT))&DMA_DCR_SINC_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_EADREQ_MASK                      (0x800000U)                                         /*!< DMA0_DCR: EADREQ Mask                   */
#define DMA_DCR_EADREQ_SHIFT                     (23U)                                               /*!< DMA0_DCR: EADREQ Position               */
#define DMA_DCR_EADREQ(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_EADREQ_SHIFT))&DMA_DCR_EADREQ_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_AA_MASK                          (0x10000000U)                                       /*!< DMA0_DCR: AA Mask                       */
#define DMA_DCR_AA_SHIFT                         (28U)                                               /*!< DMA0_DCR: AA Position                   */
#define DMA_DCR_AA(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_DCR_AA_SHIFT))&DMA_DCR_AA_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_CS_MASK                          (0x20000000U)                                       /*!< DMA0_DCR: CS Mask                       */
#define DMA_DCR_CS_SHIFT                         (29U)                                               /*!< DMA0_DCR: CS Position                   */
#define DMA_DCR_CS(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_DCR_CS_SHIFT))&DMA_DCR_CS_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_ERQ_MASK                         (0x40000000U)                                       /*!< DMA0_DCR: ERQ Mask                      */
#define DMA_DCR_ERQ_SHIFT                        (30U)                                               /*!< DMA0_DCR: ERQ Position                  */
#define DMA_DCR_ERQ(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DCR_ERQ_SHIFT))&DMA_DCR_ERQ_MASK) /*!< DMA0_DCR                                */
#define DMA_DCR_EINT_MASK                        (0x80000000U)                                       /*!< DMA0_DCR: EINT Mask                     */
#define DMA_DCR_EINT_SHIFT                       (31U)                                               /*!< DMA0_DCR: EINT Position                 */
#define DMA_DCR_EINT(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_EINT_SHIFT))&DMA_DCR_EINT_MASK) /*!< DMA0_DCR                                */
/**
 * @} */ /* End group DMA0_Register_Masks_GROUP 
 */

/* DMA0 - Peripheral instance base addresses */
#define DMA0_BasePtr                   0x40008000UL //!< Peripheral base address
#define DMA0                           ((DMA_Type *) DMA0_BasePtr) //!< Freescale base pointer
#define DMA0_BASE_PTR                  (DMA0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX0 (file:DMAMUX0_4CH)           ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */
/**
* @addtogroup DMAMUX_structs_GROUP DMAMUX struct
* @brief Struct for DMAMUX
* @{
*/
typedef struct {                                /*       DMAMUX0 Structure                                            */
   __IO uint8_t   CHCFG[4];                     /**< 0000: Channel Configuration Register                               */
} DMAMUX_Type;

/**
 * @} */ /* End group DMAMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMAMUX0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMAMUX_Register_Masks_GROUP DMAMUX Register Masks
* @brief Register Masks for DMAMUX
* @{
*/
/* ------- CHCFG Bit Fields                         ------ */
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)                                             /*!< DMAMUX0_CHCFG: SOURCE Mask              */
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)                                                /*!< DMAMUX0_CHCFG: SOURCE Position          */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK) /*!< DMAMUX0_CHCFG                           */
#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)                                             /*!< DMAMUX0_CHCFG: ENBL Mask                */
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)                                                /*!< DMAMUX0_CHCFG: ENBL Position            */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_ENBL_SHIFT))&DMAMUX_CHCFG_ENBL_MASK) /*!< DMAMUX0_CHCFG                           */
/**
 * @} */ /* End group DMAMUX_Register_Masks_GROUP 
 */

/* DMAMUX0 - Peripheral instance base addresses */
#define DMAMUX0_BasePtr                0x40021000UL //!< Peripheral base address
#define DMAMUX0                        ((DMAMUX_Type *) DMAMUX0_BasePtr) //!< Freescale base pointer
#define DMAMUX0_BASE_PTR               (DMAMUX0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FLEXIO_Peripheral_access_layer_GROUP FLEXIO Peripheral Access Layer
* @brief C Struct for FLEXIO
* @{
*/

/* ================================================================================ */
/* ================           FLEXIO (file:FLEXIO_0)               ================ */
/* ================================================================================ */

/**
 * @brief The FLEXIO Memory Map/Register Definition can be found here
 */
/**
* @addtogroup FLEXIO_structs_GROUP FLEXIO struct
* @brief Struct for FLEXIO
* @{
*/
typedef struct {                                /*       FLEXIO Structure                                             */
   __I  uint32_t  VERID;                        /**< 0000: Version ID Register                                          */
   __I  uint32_t  PARAM;                        /**< 0004: Parameter Register                                           */
   __IO uint32_t  CTRL;                         /**< 0008: FlexIO Control Register                                      */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  SHIFTSTAT;                    /**< 0010: Shifter Status Register                                      */
   __IO uint32_t  SHIFTERR;                     /**< 0014: Shifter Error Register                                       */
   __IO uint32_t  TIMSTAT;                      /**< 0018: Timer Status Register                                        */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  SHIFTSIEN;                    /**< 0020: Shifter Status Interrupt Enable                              */
   __IO uint32_t  SHIFTEIEN;                    /**< 0024: Shifter Error Interrupt Enable                               */
   __IO uint32_t  TIMIEN;                       /**< 0028: Timer Interrupt Enable Register                              */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  SHIFTSDEN;                    /**< 0030: Shifter Status DMA Enable                                    */
        uint8_t   RESERVED_3[76];              
   __IO uint32_t  SHIFTCTL[4];                  /**< 0080: Shifter Control N Register                                   */
        uint8_t   RESERVED_4[112];             
   __IO uint32_t  SHIFTCFG[4];                  /**< 0100: Shifter Configuration N Register                             */
        uint8_t   RESERVED_5[240];             
   __IO uint32_t  SHIFTBUF[4];                  /**< 0200: Shifter Buffer N Register                                    */
        uint8_t   RESERVED_6[112];             
   __IO uint32_t  SHIFTBUFBIS[4];               /**< 0280: Shifter Buffer N Bit Swapped Register                        */
        uint8_t   RESERVED_7[112];             
   __IO uint32_t  SHIFTBUFBYS[4];               /**< 0300: Shifter Buffer N Byte Swapped Register                       */
        uint8_t   RESERVED_8[112];             
   __IO uint32_t  SHIFTBUFBBS[4];               /**< 0380: Shifter Buffer N Bit Byte Swapped Register                   */
        uint8_t   RESERVED_9[112];             
   __IO uint32_t  TIMCTL[4];                    /**< 0400: Timer Control N Register                                     */
        uint8_t   RESERVED_10[112];            
   __IO uint32_t  TIMCFG[4];                    /**< 0480: Timer Configuration N Register                               */
        uint8_t   RESERVED_11[112];            
   __IO uint32_t  TIMCMP[4];                    /**< 0500: Timer Compare N Register                                     */
} FLEXIO_Type;

/**
 * @} */ /* End group FLEXIO_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FLEXIO' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FLEXIO_Register_Masks_GROUP FLEXIO Register Masks
* @brief Register Masks for FLEXIO
* @{
*/
/* ------- VERID Bit Fields                         ------ */
#define FLEXIO_VERID_FEATURE_MASK                (0xFFFFU)                                           /*!< FLEXIO_VERID: FEATURE Mask              */
#define FLEXIO_VERID_FEATURE_SHIFT               (0U)                                                /*!< FLEXIO_VERID: FEATURE Position          */
#define FLEXIO_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_FEATURE_SHIFT))&FLEXIO_VERID_FEATURE_MASK) /*!< FLEXIO_VERID                            */
#define FLEXIO_VERID_MINOR_MASK                  (0xFF0000U)                                         /*!< FLEXIO_VERID: MINOR Mask                */
#define FLEXIO_VERID_MINOR_SHIFT                 (16U)                                               /*!< FLEXIO_VERID: MINOR Position            */
#define FLEXIO_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_MINOR_SHIFT))&FLEXIO_VERID_MINOR_MASK) /*!< FLEXIO_VERID                            */
#define FLEXIO_VERID_MAJOR_MASK                  (0xFF000000U)                                       /*!< FLEXIO_VERID: MAJOR Mask                */
#define FLEXIO_VERID_MAJOR_SHIFT                 (24U)                                               /*!< FLEXIO_VERID: MAJOR Position            */
#define FLEXIO_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_MAJOR_SHIFT))&FLEXIO_VERID_MAJOR_MASK) /*!< FLEXIO_VERID                            */
/* ------- PARAM Bit Fields                         ------ */
#define FLEXIO_PARAM_SHIFTER_MASK                (0xFFU)                                             /*!< FLEXIO_PARAM: SHIFTER Mask              */
#define FLEXIO_PARAM_SHIFTER_SHIFT               (0U)                                                /*!< FLEXIO_PARAM: SHIFTER Position          */
#define FLEXIO_PARAM_SHIFTER(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_SHIFTER_SHIFT))&FLEXIO_PARAM_SHIFTER_MASK) /*!< FLEXIO_PARAM                            */
#define FLEXIO_PARAM_TIMER_MASK                  (0xFF00U)                                           /*!< FLEXIO_PARAM: TIMER Mask                */
#define FLEXIO_PARAM_TIMER_SHIFT                 (8U)                                                /*!< FLEXIO_PARAM: TIMER Position            */
#define FLEXIO_PARAM_TIMER(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_TIMER_SHIFT))&FLEXIO_PARAM_TIMER_MASK) /*!< FLEXIO_PARAM                            */
#define FLEXIO_PARAM_PIN_MASK                    (0xFF0000U)                                         /*!< FLEXIO_PARAM: PIN Mask                  */
#define FLEXIO_PARAM_PIN_SHIFT                   (16U)                                               /*!< FLEXIO_PARAM: PIN Position              */
#define FLEXIO_PARAM_PIN(x)                      (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_PIN_SHIFT))&FLEXIO_PARAM_PIN_MASK) /*!< FLEXIO_PARAM                            */
#define FLEXIO_PARAM_TRIGGER_MASK                (0xFF000000U)                                       /*!< FLEXIO_PARAM: TRIGGER Mask              */
#define FLEXIO_PARAM_TRIGGER_SHIFT               (24U)                                               /*!< FLEXIO_PARAM: TRIGGER Position          */
#define FLEXIO_PARAM_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_TRIGGER_SHIFT))&FLEXIO_PARAM_TRIGGER_MASK) /*!< FLEXIO_PARAM                            */
/* ------- CTRL Bit Fields                          ------ */
#define FLEXIO_CTRL_FLEXEN_MASK                  (0x1U)                                              /*!< FLEXIO_CTRL: FLEXEN Mask                */
#define FLEXIO_CTRL_FLEXEN_SHIFT                 (0U)                                                /*!< FLEXIO_CTRL: FLEXEN Position            */
#define FLEXIO_CTRL_FLEXEN(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_FLEXEN_SHIFT))&FLEXIO_CTRL_FLEXEN_MASK) /*!< FLEXIO_CTRL                             */
#define FLEXIO_CTRL_SWRST_MASK                   (0x2U)                                              /*!< FLEXIO_CTRL: SWRST Mask                 */
#define FLEXIO_CTRL_SWRST_SHIFT                  (1U)                                                /*!< FLEXIO_CTRL: SWRST Position             */
#define FLEXIO_CTRL_SWRST(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_SWRST_SHIFT))&FLEXIO_CTRL_SWRST_MASK) /*!< FLEXIO_CTRL                             */
#define FLEXIO_CTRL_FASTACC_MASK                 (0x4U)                                              /*!< FLEXIO_CTRL: FASTACC Mask               */
#define FLEXIO_CTRL_FASTACC_SHIFT                (2U)                                                /*!< FLEXIO_CTRL: FASTACC Position           */
#define FLEXIO_CTRL_FASTACC(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_FASTACC_SHIFT))&FLEXIO_CTRL_FASTACC_MASK) /*!< FLEXIO_CTRL                             */
#define FLEXIO_CTRL_DBGE_MASK                    (0x40000000U)                                       /*!< FLEXIO_CTRL: DBGE Mask                  */
#define FLEXIO_CTRL_DBGE_SHIFT                   (30U)                                               /*!< FLEXIO_CTRL: DBGE Position              */
#define FLEXIO_CTRL_DBGE(x)                      (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_DBGE_SHIFT))&FLEXIO_CTRL_DBGE_MASK) /*!< FLEXIO_CTRL                             */
#define FLEXIO_CTRL_DOZEN_MASK                   (0x80000000U)                                       /*!< FLEXIO_CTRL: DOZEN Mask                 */
#define FLEXIO_CTRL_DOZEN_SHIFT                  (31U)                                               /*!< FLEXIO_CTRL: DOZEN Position             */
#define FLEXIO_CTRL_DOZEN(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_DOZEN_SHIFT))&FLEXIO_CTRL_DOZEN_MASK) /*!< FLEXIO_CTRL                             */
/* ------- SHIFTSTAT Bit Fields                     ------ */
#define FLEXIO_SHIFTSTAT_SSF_MASK                (0xFU)                                              /*!< FLEXIO_SHIFTSTAT: SSF Mask              */
#define FLEXIO_SHIFTSTAT_SSF_SHIFT               (0U)                                                /*!< FLEXIO_SHIFTSTAT: SSF Position          */
#define FLEXIO_SHIFTSTAT_SSF(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSTAT_SSF_SHIFT))&FLEXIO_SHIFTSTAT_SSF_MASK) /*!< FLEXIO_SHIFTSTAT                        */
/* ------- SHIFTERR Bit Fields                      ------ */
#define FLEXIO_SHIFTERR_SEF_MASK                 (0xFU)                                              /*!< FLEXIO_SHIFTERR: SEF Mask               */
#define FLEXIO_SHIFTERR_SEF_SHIFT                (0U)                                                /*!< FLEXIO_SHIFTERR: SEF Position           */
#define FLEXIO_SHIFTERR_SEF(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTERR_SEF_SHIFT))&FLEXIO_SHIFTERR_SEF_MASK) /*!< FLEXIO_SHIFTERR                         */
/* ------- TIMSTAT Bit Fields                       ------ */
#define FLEXIO_TIMSTAT_TSF_MASK                  (0xFU)                                              /*!< FLEXIO_TIMSTAT: TSF Mask                */
#define FLEXIO_TIMSTAT_TSF_SHIFT                 (0U)                                                /*!< FLEXIO_TIMSTAT: TSF Position            */
#define FLEXIO_TIMSTAT_TSF(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMSTAT_TSF_SHIFT))&FLEXIO_TIMSTAT_TSF_MASK) /*!< FLEXIO_TIMSTAT                          */
/* ------- SHIFTSIEN Bit Fields                     ------ */
#define FLEXIO_SHIFTSIEN_SSIE_MASK               (0xFU)                                              /*!< FLEXIO_SHIFTSIEN: SSIE Mask             */
#define FLEXIO_SHIFTSIEN_SSIE_SHIFT              (0U)                                                /*!< FLEXIO_SHIFTSIEN: SSIE Position         */
#define FLEXIO_SHIFTSIEN_SSIE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSIEN_SSIE_SHIFT))&FLEXIO_SHIFTSIEN_SSIE_MASK) /*!< FLEXIO_SHIFTSIEN                        */
/* ------- SHIFTEIEN Bit Fields                     ------ */
#define FLEXIO_SHIFTEIEN_SEIE_MASK               (0xFU)                                              /*!< FLEXIO_SHIFTEIEN: SEIE Mask             */
#define FLEXIO_SHIFTEIEN_SEIE_SHIFT              (0U)                                                /*!< FLEXIO_SHIFTEIEN: SEIE Position         */
#define FLEXIO_SHIFTEIEN_SEIE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTEIEN_SEIE_SHIFT))&FLEXIO_SHIFTEIEN_SEIE_MASK) /*!< FLEXIO_SHIFTEIEN                        */
/* ------- TIMIEN Bit Fields                        ------ */
#define FLEXIO_TIMIEN_TEIE_MASK                  (0xFU)                                              /*!< FLEXIO_TIMIEN: TEIE Mask                */
#define FLEXIO_TIMIEN_TEIE_SHIFT                 (0U)                                                /*!< FLEXIO_TIMIEN: TEIE Position            */
#define FLEXIO_TIMIEN_TEIE(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMIEN_TEIE_SHIFT))&FLEXIO_TIMIEN_TEIE_MASK) /*!< FLEXIO_TIMIEN                           */
/* ------- SHIFTSDEN Bit Fields                     ------ */
#define FLEXIO_SHIFTSDEN_SSDE_MASK               (0xFU)                                              /*!< FLEXIO_SHIFTSDEN: SSDE Mask             */
#define FLEXIO_SHIFTSDEN_SSDE_SHIFT              (0U)                                                /*!< FLEXIO_SHIFTSDEN: SSDE Position         */
#define FLEXIO_SHIFTSDEN_SSDE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSDEN_SSDE_SHIFT))&FLEXIO_SHIFTSDEN_SSDE_MASK) /*!< FLEXIO_SHIFTSDEN                        */
/* ------- SHIFTCTL Bit Fields                      ------ */
#define FLEXIO_SHIFTCTL_SMOD_MASK                (0x7U)                                              /*!< FLEXIO_SHIFTCTL: SMOD Mask              */
#define FLEXIO_SHIFTCTL_SMOD_SHIFT               (0U)                                                /*!< FLEXIO_SHIFTCTL: SMOD Position          */
#define FLEXIO_SHIFTCTL_SMOD(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_SMOD_SHIFT))&FLEXIO_SHIFTCTL_SMOD_MASK) /*!< FLEXIO_SHIFTCTL                         */
#define FLEXIO_SHIFTCTL_PINPOL_MASK              (0x80U)                                             /*!< FLEXIO_SHIFTCTL: PINPOL Mask            */
#define FLEXIO_SHIFTCTL_PINPOL_SHIFT             (7U)                                                /*!< FLEXIO_SHIFTCTL: PINPOL Position        */
#define FLEXIO_SHIFTCTL_PINPOL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINPOL_SHIFT))&FLEXIO_SHIFTCTL_PINPOL_MASK) /*!< FLEXIO_SHIFTCTL                         */
#define FLEXIO_SHIFTCTL_PINSEL_MASK              (0x700U)                                            /*!< FLEXIO_SHIFTCTL: PINSEL Mask            */
#define FLEXIO_SHIFTCTL_PINSEL_SHIFT             (8U)                                                /*!< FLEXIO_SHIFTCTL: PINSEL Position        */
#define FLEXIO_SHIFTCTL_PINSEL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINSEL_SHIFT))&FLEXIO_SHIFTCTL_PINSEL_MASK) /*!< FLEXIO_SHIFTCTL                         */
#define FLEXIO_SHIFTCTL_PINCFG_MASK              (0x30000U)                                          /*!< FLEXIO_SHIFTCTL: PINCFG Mask            */
#define FLEXIO_SHIFTCTL_PINCFG_SHIFT             (16U)                                               /*!< FLEXIO_SHIFTCTL: PINCFG Position        */
#define FLEXIO_SHIFTCTL_PINCFG(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINCFG_SHIFT))&FLEXIO_SHIFTCTL_PINCFG_MASK) /*!< FLEXIO_SHIFTCTL                         */
#define FLEXIO_SHIFTCTL_TIMPOL_MASK              (0x800000U)                                         /*!< FLEXIO_SHIFTCTL: TIMPOL Mask            */
#define FLEXIO_SHIFTCTL_TIMPOL_SHIFT             (23U)                                               /*!< FLEXIO_SHIFTCTL: TIMPOL Position        */
#define FLEXIO_SHIFTCTL_TIMPOL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_TIMPOL_SHIFT))&FLEXIO_SHIFTCTL_TIMPOL_MASK) /*!< FLEXIO_SHIFTCTL                         */
#define FLEXIO_SHIFTCTL_TIMSEL_MASK              (0x3000000U)                                        /*!< FLEXIO_SHIFTCTL: TIMSEL Mask            */
#define FLEXIO_SHIFTCTL_TIMSEL_SHIFT             (24U)                                               /*!< FLEXIO_SHIFTCTL: TIMSEL Position        */
#define FLEXIO_SHIFTCTL_TIMSEL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_TIMSEL_SHIFT))&FLEXIO_SHIFTCTL_TIMSEL_MASK) /*!< FLEXIO_SHIFTCTL                         */
/* ------- SHIFTCFG Bit Fields                      ------ */
#define FLEXIO_SHIFTCFG_SSTART_MASK              (0x3U)                                              /*!< FLEXIO_SHIFTCFG: SSTART Mask            */
#define FLEXIO_SHIFTCFG_SSTART_SHIFT             (0U)                                                /*!< FLEXIO_SHIFTCFG: SSTART Position        */
#define FLEXIO_SHIFTCFG_SSTART(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_SSTART_SHIFT))&FLEXIO_SHIFTCFG_SSTART_MASK) /*!< FLEXIO_SHIFTCFG                         */
#define FLEXIO_SHIFTCFG_SSTOP_MASK               (0x30U)                                             /*!< FLEXIO_SHIFTCFG: SSTOP Mask             */
#define FLEXIO_SHIFTCFG_SSTOP_SHIFT              (4U)                                                /*!< FLEXIO_SHIFTCFG: SSTOP Position         */
#define FLEXIO_SHIFTCFG_SSTOP(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_SSTOP_SHIFT))&FLEXIO_SHIFTCFG_SSTOP_MASK) /*!< FLEXIO_SHIFTCFG                         */
#define FLEXIO_SHIFTCFG_INSRC_MASK               (0x100U)                                            /*!< FLEXIO_SHIFTCFG: INSRC Mask             */
#define FLEXIO_SHIFTCFG_INSRC_SHIFT              (8U)                                                /*!< FLEXIO_SHIFTCFG: INSRC Position         */
#define FLEXIO_SHIFTCFG_INSRC(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_INSRC_SHIFT))&FLEXIO_SHIFTCFG_INSRC_MASK) /*!< FLEXIO_SHIFTCFG                         */
/* ------- SHIFTBUF Bit Fields                      ------ */
#define FLEXIO_SHIFTBUF_SHIFTBUF_MASK            (0xFFFFFFFFU)                                       /*!< FLEXIO_SHIFTBUF: SHIFTBUF Mask          */
#define FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT           (0U)                                                /*!< FLEXIO_SHIFTBUF: SHIFTBUF Position      */
#define FLEXIO_SHIFTBUF_SHIFTBUF(x)              (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT))&FLEXIO_SHIFTBUF_SHIFTBUF_MASK) /*!< FLEXIO_SHIFTBUF                         */
/* ------- SHIFTBUFBIS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO_SHIFTBUFBIS: SHIFTBUFBIS Mask    */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT     (0U)                                                /*!< FLEXIO_SHIFTBUFBIS: SHIFTBUFBIS Position*/
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT))&FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK) /*!< FLEXIO_SHIFTBUFBIS                      */
/* ------- SHIFTBUFBYS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO_SHIFTBUFBYS: SHIFTBUFBYS Mask    */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT     (0U)                                                /*!< FLEXIO_SHIFTBUFBYS: SHIFTBUFBYS Position*/
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT))&FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK) /*!< FLEXIO_SHIFTBUFBYS                      */
/* ------- SHIFTBUFBBS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO_SHIFTBUFBBS: SHIFTBUFBBS Mask    */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT     (0U)                                                /*!< FLEXIO_SHIFTBUFBBS: SHIFTBUFBBS Position*/
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT))&FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK) /*!< FLEXIO_SHIFTBUFBBS                      */
/* ------- TIMCTL Bit Fields                        ------ */
#define FLEXIO_TIMCTL_TIMOD_MASK                 (0x3U)                                              /*!< FLEXIO_TIMCTL: TIMOD Mask               */
#define FLEXIO_TIMCTL_TIMOD_SHIFT                (0U)                                                /*!< FLEXIO_TIMCTL: TIMOD Position           */
#define FLEXIO_TIMCTL_TIMOD(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TIMOD_SHIFT))&FLEXIO_TIMCTL_TIMOD_MASK) /*!< FLEXIO_TIMCTL                           */
#define FLEXIO_TIMCTL_PINPOL_MASK                (0x80U)                                             /*!< FLEXIO_TIMCTL: PINPOL Mask              */
#define FLEXIO_TIMCTL_PINPOL_SHIFT               (7U)                                                /*!< FLEXIO_TIMCTL: PINPOL Position          */
#define FLEXIO_TIMCTL_PINPOL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINPOL_SHIFT))&FLEXIO_TIMCTL_PINPOL_MASK) /*!< FLEXIO_TIMCTL                           */
#define FLEXIO_TIMCTL_PINSEL_MASK                (0x700U)                                            /*!< FLEXIO_TIMCTL: PINSEL Mask              */
#define FLEXIO_TIMCTL_PINSEL_SHIFT               (8U)                                                /*!< FLEXIO_TIMCTL: PINSEL Position          */
#define FLEXIO_TIMCTL_PINSEL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINSEL_SHIFT))&FLEXIO_TIMCTL_PINSEL_MASK) /*!< FLEXIO_TIMCTL                           */
#define FLEXIO_TIMCTL_PINCFG_MASK                (0x30000U)                                          /*!< FLEXIO_TIMCTL: PINCFG Mask              */
#define FLEXIO_TIMCTL_PINCFG_SHIFT               (16U)                                               /*!< FLEXIO_TIMCTL: PINCFG Position          */
#define FLEXIO_TIMCTL_PINCFG(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINCFG_SHIFT))&FLEXIO_TIMCTL_PINCFG_MASK) /*!< FLEXIO_TIMCTL                           */
#define FLEXIO_TIMCTL_TRGSRC_MASK                (0x400000U)                                         /*!< FLEXIO_TIMCTL: TRGSRC Mask              */
#define FLEXIO_TIMCTL_TRGSRC_SHIFT               (22U)                                               /*!< FLEXIO_TIMCTL: TRGSRC Position          */
#define FLEXIO_TIMCTL_TRGSRC(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGSRC_SHIFT))&FLEXIO_TIMCTL_TRGSRC_MASK) /*!< FLEXIO_TIMCTL                           */
#define FLEXIO_TIMCTL_TRGPOL_MASK                (0x800000U)                                         /*!< FLEXIO_TIMCTL: TRGPOL Mask              */
#define FLEXIO_TIMCTL_TRGPOL_SHIFT               (23U)                                               /*!< FLEXIO_TIMCTL: TRGPOL Position          */
#define FLEXIO_TIMCTL_TRGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGPOL_SHIFT))&FLEXIO_TIMCTL_TRGPOL_MASK) /*!< FLEXIO_TIMCTL                           */
#define FLEXIO_TIMCTL_TRGSEL_MASK                (0xF000000U)                                        /*!< FLEXIO_TIMCTL: TRGSEL Mask              */
#define FLEXIO_TIMCTL_TRGSEL_SHIFT               (24U)                                               /*!< FLEXIO_TIMCTL: TRGSEL Position          */
#define FLEXIO_TIMCTL_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGSEL_SHIFT))&FLEXIO_TIMCTL_TRGSEL_MASK) /*!< FLEXIO_TIMCTL                           */
/* ------- TIMCFG Bit Fields                        ------ */
#define FLEXIO_TIMCFG_TSTART_MASK                (0x2U)                                              /*!< FLEXIO_TIMCFG: TSTART Mask              */
#define FLEXIO_TIMCFG_TSTART_SHIFT               (1U)                                                /*!< FLEXIO_TIMCFG: TSTART Position          */
#define FLEXIO_TIMCFG_TSTART(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TSTART_SHIFT))&FLEXIO_TIMCFG_TSTART_MASK) /*!< FLEXIO_TIMCFG                           */
#define FLEXIO_TIMCFG_TSTOP_MASK                 (0x30U)                                             /*!< FLEXIO_TIMCFG: TSTOP Mask               */
#define FLEXIO_TIMCFG_TSTOP_SHIFT                (4U)                                                /*!< FLEXIO_TIMCFG: TSTOP Position           */
#define FLEXIO_TIMCFG_TSTOP(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TSTOP_SHIFT))&FLEXIO_TIMCFG_TSTOP_MASK) /*!< FLEXIO_TIMCFG                           */
#define FLEXIO_TIMCFG_TIMENA_MASK                (0x700U)                                            /*!< FLEXIO_TIMCFG: TIMENA Mask              */
#define FLEXIO_TIMCFG_TIMENA_SHIFT               (8U)                                                /*!< FLEXIO_TIMCFG: TIMENA Position          */
#define FLEXIO_TIMCFG_TIMENA(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMENA_SHIFT))&FLEXIO_TIMCFG_TIMENA_MASK) /*!< FLEXIO_TIMCFG                           */
#define FLEXIO_TIMCFG_TIMDIS_MASK                (0x7000U)                                           /*!< FLEXIO_TIMCFG: TIMDIS Mask              */
#define FLEXIO_TIMCFG_TIMDIS_SHIFT               (12U)                                               /*!< FLEXIO_TIMCFG: TIMDIS Position          */
#define FLEXIO_TIMCFG_TIMDIS(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMDIS_SHIFT))&FLEXIO_TIMCFG_TIMDIS_MASK) /*!< FLEXIO_TIMCFG                           */
#define FLEXIO_TIMCFG_TIMRST_MASK                (0x70000U)                                          /*!< FLEXIO_TIMCFG: TIMRST Mask              */
#define FLEXIO_TIMCFG_TIMRST_SHIFT               (16U)                                               /*!< FLEXIO_TIMCFG: TIMRST Position          */
#define FLEXIO_TIMCFG_TIMRST(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMRST_SHIFT))&FLEXIO_TIMCFG_TIMRST_MASK) /*!< FLEXIO_TIMCFG                           */
#define FLEXIO_TIMCFG_TIMDEC_MASK                (0x300000U)                                         /*!< FLEXIO_TIMCFG: TIMDEC Mask              */
#define FLEXIO_TIMCFG_TIMDEC_SHIFT               (20U)                                               /*!< FLEXIO_TIMCFG: TIMDEC Position          */
#define FLEXIO_TIMCFG_TIMDEC(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMDEC_SHIFT))&FLEXIO_TIMCFG_TIMDEC_MASK) /*!< FLEXIO_TIMCFG                           */
#define FLEXIO_TIMCFG_TIMOUT_MASK                (0x3000000U)                                        /*!< FLEXIO_TIMCFG: TIMOUT Mask              */
#define FLEXIO_TIMCFG_TIMOUT_SHIFT               (24U)                                               /*!< FLEXIO_TIMCFG: TIMOUT Position          */
#define FLEXIO_TIMCFG_TIMOUT(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMOUT_SHIFT))&FLEXIO_TIMCFG_TIMOUT_MASK) /*!< FLEXIO_TIMCFG                           */
/* ------- TIMCMP Bit Fields                        ------ */
#define FLEXIO_TIMCMP_CMP_MASK                   (0xFFFFU)                                           /*!< FLEXIO_TIMCMP: CMP Mask                 */
#define FLEXIO_TIMCMP_CMP_SHIFT                  (0U)                                                /*!< FLEXIO_TIMCMP: CMP Position             */
#define FLEXIO_TIMCMP_CMP(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCMP_CMP_SHIFT))&FLEXIO_TIMCMP_CMP_MASK) /*!< FLEXIO_TIMCMP                           */
/**
 * @} */ /* End group FLEXIO_Register_Masks_GROUP 
 */

/* FLEXIO - Peripheral instance base addresses */
#define FLEXIO_BasePtr                 0x4005F000UL //!< Peripheral base address
#define FLEXIO                         ((FLEXIO_Type *) FLEXIO_BasePtr) //!< Freescale base pointer
#define FLEXIO_BASE_PTR                (FLEXIO) //!< Freescale style base pointer
/**
 * @} */ /* End group FLEXIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTFA_Peripheral_access_layer_GROUP FTFA Peripheral Access Layer
* @brief C Struct for FTFA
* @{
*/

/* ================================================================================ */
/* ================           FTFA (file:FTFA)                     ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
* @addtogroup FTFA_structs_GROUP FTFA struct
* @brief Struct for FTFA
* @{
*/
typedef struct {                                /*       FTFA Structure                                               */
   __IO uint8_t   FSTAT;                        /**< 0000: Flash Status Register                                        */
   __IO uint8_t   FCNFG;                        /**< 0001: Flash Configuration Register                                 */
   __I  uint8_t   FSEC;                         /**< 0002: Flash Security Register                                      */
   __I  uint8_t   FOPT;                         /**< 0003: Flash Option Register                                        */
   __IO uint8_t   FCCOB3;                       /**< 0004: FCCOB 3 - Usually Flash address [7..0]                       */
   __IO uint8_t   FCCOB2;                       /**< 0005: FCCOB 2 - Usually Flash address [15..8]                      */
   __IO uint8_t   FCCOB1;                       /**< 0006: FCCOB 1 - Usually Flash address [23..16]                     */
   __IO uint8_t   FCCOB0;                       /**< 0007: FCCOB 0 - Usually FCMD (Flash command)                       */
   __IO uint8_t   FCCOB7;                       /**< 0008: FCCOB 7 - Usually Data Byte 3                                */
   __IO uint8_t   FCCOB6;                       /**< 0009: FCCOB 6 - Usually Data Byte 2                                */
   __IO uint8_t   FCCOB5;                       /**< 000A: FCCOB 5 - Usually Data Byte 1                                */
   __IO uint8_t   FCCOB4;                       /**< 000B: FCCOB 4 - Usually Data Byte 0                                */
   __IO uint8_t   FCCOBB;                       /**< 000C: FCCOB B - Usually Data Byte 7                                */
   __IO uint8_t   FCCOBA;                       /**< 000D: FCCOB A - Usually Data Byte 6                                */
   __IO uint8_t   FCCOB9;                       /**< 000E: FCCOB 9 - Usually Data Byte 5                                */
   __IO uint8_t   FCCOB8;                       /**< 000F: FCCOB 8 - Usually Data Byte 4                                */
   __IO uint8_t   FPROT3;                       /**< 0010: Program Flash Protection                                     */
   __IO uint8_t   FPROT2;                       /**< 0011: Program Flash Protection                                     */
   __IO uint8_t   FPROT1;                       /**< 0012: Program Flash Protection                                     */
   __IO uint8_t   FPROT0;                       /**< 0013: Program Flash Protection                                     */
} FTFA_Type;

/**
 * @} */ /* End group FTFA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTFA_Register_Masks_GROUP FTFA Register Masks
* @brief Register Masks for FTFA
* @{
*/
/* ------- FSTAT Bit Fields                         ------ */
#define FTFA_FSTAT_MGSTAT0_MASK                  (0x1U)                                              /*!< FTFA_FSTAT: MGSTAT0 Mask                */
#define FTFA_FSTAT_MGSTAT0_SHIFT                 (0U)                                                /*!< FTFA_FSTAT: MGSTAT0 Position            */
#define FTFA_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_MGSTAT0_SHIFT))&FTFA_FSTAT_MGSTAT0_MASK) /*!< FTFA_FSTAT                              */
#define FTFA_FSTAT_FPVIOL_MASK                   (0x10U)                                             /*!< FTFA_FSTAT: FPVIOL Mask                 */
#define FTFA_FSTAT_FPVIOL_SHIFT                  (4U)                                                /*!< FTFA_FSTAT: FPVIOL Position             */
#define FTFA_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_FPVIOL_SHIFT))&FTFA_FSTAT_FPVIOL_MASK) /*!< FTFA_FSTAT                              */
#define FTFA_FSTAT_ACCERR_MASK                   (0x20U)                                             /*!< FTFA_FSTAT: ACCERR Mask                 */
#define FTFA_FSTAT_ACCERR_SHIFT                  (5U)                                                /*!< FTFA_FSTAT: ACCERR Position             */
#define FTFA_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_ACCERR_SHIFT))&FTFA_FSTAT_ACCERR_MASK) /*!< FTFA_FSTAT                              */
#define FTFA_FSTAT_RDCOLERR_MASK                 (0x40U)                                             /*!< FTFA_FSTAT: RDCOLERR Mask               */
#define FTFA_FSTAT_RDCOLERR_SHIFT                (6U)                                                /*!< FTFA_FSTAT: RDCOLERR Position           */
#define FTFA_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_RDCOLERR_SHIFT))&FTFA_FSTAT_RDCOLERR_MASK) /*!< FTFA_FSTAT                              */
#define FTFA_FSTAT_CCIF_MASK                     (0x80U)                                             /*!< FTFA_FSTAT: CCIF Mask                   */
#define FTFA_FSTAT_CCIF_SHIFT                    (7U)                                                /*!< FTFA_FSTAT: CCIF Position               */
#define FTFA_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_CCIF_SHIFT))&FTFA_FSTAT_CCIF_MASK) /*!< FTFA_FSTAT                              */
/* ------- FCNFG Bit Fields                         ------ */
#define FTFA_FCNFG_ERSSUSP_MASK                  (0x10U)                                             /*!< FTFA_FCNFG: ERSSUSP Mask                */
#define FTFA_FCNFG_ERSSUSP_SHIFT                 (4U)                                                /*!< FTFA_FCNFG: ERSSUSP Position            */
#define FTFA_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_ERSSUSP_SHIFT))&FTFA_FCNFG_ERSSUSP_MASK) /*!< FTFA_FCNFG                              */
#define FTFA_FCNFG_ERSAREQ_MASK                  (0x20U)                                             /*!< FTFA_FCNFG: ERSAREQ Mask                */
#define FTFA_FCNFG_ERSAREQ_SHIFT                 (5U)                                                /*!< FTFA_FCNFG: ERSAREQ Position            */
#define FTFA_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_ERSAREQ_SHIFT))&FTFA_FCNFG_ERSAREQ_MASK) /*!< FTFA_FCNFG                              */
#define FTFA_FCNFG_RDCOLLIE_MASK                 (0x40U)                                             /*!< FTFA_FCNFG: RDCOLLIE Mask               */
#define FTFA_FCNFG_RDCOLLIE_SHIFT                (6U)                                                /*!< FTFA_FCNFG: RDCOLLIE Position           */
#define FTFA_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_RDCOLLIE_SHIFT))&FTFA_FCNFG_RDCOLLIE_MASK) /*!< FTFA_FCNFG                              */
#define FTFA_FCNFG_CCIE_MASK                     (0x80U)                                             /*!< FTFA_FCNFG: CCIE Mask                   */
#define FTFA_FCNFG_CCIE_SHIFT                    (7U)                                                /*!< FTFA_FCNFG: CCIE Position               */
#define FTFA_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_CCIE_SHIFT))&FTFA_FCNFG_CCIE_MASK) /*!< FTFA_FCNFG                              */
/* ------- FSEC Bit Fields                          ------ */
#define FTFA_FSEC_SEC_MASK                       (0x3U)                                              /*!< FTFA_FSEC: SEC Mask                     */
#define FTFA_FSEC_SEC_SHIFT                      (0U)                                                /*!< FTFA_FSEC: SEC Position                 */
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_SEC_SHIFT))&FTFA_FSEC_SEC_MASK) /*!< FTFA_FSEC                               */
#define FTFA_FSEC_FSLACC_MASK                    (0xCU)                                              /*!< FTFA_FSEC: FSLACC Mask                  */
#define FTFA_FSEC_FSLACC_SHIFT                   (2U)                                                /*!< FTFA_FSEC: FSLACC Position              */
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_FSLACC_SHIFT))&FTFA_FSEC_FSLACC_MASK) /*!< FTFA_FSEC                               */
#define FTFA_FSEC_MEEN_MASK                      (0x30U)                                             /*!< FTFA_FSEC: MEEN Mask                    */
#define FTFA_FSEC_MEEN_SHIFT                     (4U)                                                /*!< FTFA_FSEC: MEEN Position                */
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_MEEN_SHIFT))&FTFA_FSEC_MEEN_MASK) /*!< FTFA_FSEC                               */
#define FTFA_FSEC_KEYEN_MASK                     (0xC0U)                                             /*!< FTFA_FSEC: KEYEN Mask                   */
#define FTFA_FSEC_KEYEN_SHIFT                    (6U)                                                /*!< FTFA_FSEC: KEYEN Position               */
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_KEYEN_SHIFT))&FTFA_FSEC_KEYEN_MASK) /*!< FTFA_FSEC                               */
/* ------- FOPT Bit Fields                          ------ */
#define FTFA_FOPT_OPT_MASK                       (0xFFU)                                             /*!< FTFA_FOPT: OPT Mask                     */
#define FTFA_FOPT_OPT_SHIFT                      (0U)                                                /*!< FTFA_FOPT: OPT Position                 */
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FOPT_OPT_SHIFT))&FTFA_FOPT_OPT_MASK) /*!< FTFA_FOPT                               */
/* ------- FCCOB Bit Fields                         ------ */
#define FTFA_FCCOB_CCOBn_MASK                    (0xFFU)                                             /*!< FTFA_FCCOB: CCOBn Mask                  */
#define FTFA_FCCOB_CCOBn_SHIFT                   (0U)                                                /*!< FTFA_FCCOB: CCOBn Position              */
#define FTFA_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB_CCOBn_SHIFT))&FTFA_FCCOB_CCOBn_MASK) /*!< FTFA_FCCOB                              */
/* ------- FPROT Bit Fields                         ------ */
#define FTFA_FPROT_PROT_MASK                     (0xFFU)                                             /*!< FTFA_FPROT: PROT Mask                   */
#define FTFA_FPROT_PROT_SHIFT                    (0U)                                                /*!< FTFA_FPROT: PROT Position               */
#define FTFA_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT_PROT_SHIFT))&FTFA_FPROT_PROT_MASK) /*!< FTFA_FPROT                              */
/**
 * @} */ /* End group FTFA_Register_Masks_GROUP 
 */

/* FTFA - Peripheral instance base addresses */
#define FTFA_BasePtr                   0x40020000UL //!< Peripheral base address
#define FTFA                           ((FTFA_Type *) FTFA_BasePtr) //!< Freescale base pointer
#define FTFA_BASE_PTR                  (FTFA) //!< Freescale style base pointer
/**
 * @} */ /* End group FTFA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_0x400FF000)        ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
* @addtogroup GPIOA_structs_GROUP GPIOA struct
* @brief Struct for GPIOA
* @{
*/
typedef struct {                                /*       GPIOA Structure                                              */
   __IO uint32_t  PDOR;                         /**< 0000: Port Data Output Register                                    */
   __O  uint32_t  PSOR;                         /**< 0004: Port Set Output Register                                     */
   __O  uint32_t  PCOR;                         /**< 0008: Port Clear Output Register                                   */
   __O  uint32_t  PTOR;                         /**< 000C: Port Toggle Output Register                                  */
   __I  uint32_t  PDIR;                         /**< 0010: Port Data Input Register                                     */
   __IO uint32_t  PDDR;                         /**< 0014: Port Data Direction Register                                 */
} GPIO_Type;

/**
 * @} */ /* End group GPIOA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIOA_Register_Masks_GROUP GPIOA Register Masks
* @brief Register Masks for GPIOA
* @{
*/
/* ------- PDOR Bit Fields                          ------ */
/* ------- PSOR Bit Fields                          ------ */
/* ------- PCOR Bit Fields                          ------ */
/* ------- PTOR Bit Fields                          ------ */
/* ------- PDIR Bit Fields                          ------ */
/* ------- PDDR Bit Fields                          ------ */
/**
 * @} */ /* End group GPIOA_Register_Masks_GROUP 
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x400FF000UL //!< Peripheral base address
#define GPIOA                          ((GPIO_Type *) GPIOA_BasePtr) //!< Freescale base pointer
#define GPIOA_BASE_PTR                 (GPIOA) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOB (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x400FF040UL //!< Peripheral base address
#define GPIOB                          ((GPIO_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOC (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x400FF080UL //!< Peripheral base address
#define GPIOC                          ((GPIO_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOD (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0x400FF0C0UL //!< Peripheral base address
#define GPIOD                          ((GPIO_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOE (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOE - Peripheral instance base addresses */
#define GPIOE_BasePtr                  0x400FF100UL //!< Peripheral base address
#define GPIOE                          ((GPIO_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MKL17)               ================ */
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
   __IO uint8_t   S2;                           /**< 000C: Status register 2                                            */
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
#define I2C_A1_AD_MASK                           (0xFEU)                                             /*!< I2C0_A1: AD Mask                        */
#define I2C_A1_AD_SHIFT                          (1U)                                                /*!< I2C0_A1: AD Position                    */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK) /*!< I2C0_A1                                 */
/* ------- F Bit Fields                             ------ */
#define I2C_F_ICR_MASK                           (0x3FU)                                             /*!< I2C0_F: ICR Mask                        */
#define I2C_F_ICR_SHIFT                          (0U)                                                /*!< I2C0_F: ICR Position                    */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK) /*!< I2C0_F                                  */
#define I2C_F_MULT_MASK                          (0xC0U)                                             /*!< I2C0_F: MULT Mask                       */
#define I2C_F_MULT_SHIFT                         (6U)                                                /*!< I2C0_F: MULT Position                   */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK) /*!< I2C0_F                                  */
/* ------- C1 Bit Fields                            ------ */
#define I2C_C1_DMAEN_MASK                        (0x1U)                                              /*!< I2C0_C1: DMAEN Mask                     */
#define I2C_C1_DMAEN_SHIFT                       (0U)                                                /*!< I2C0_C1: DMAEN Position                 */
#define I2C_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_DMAEN_SHIFT))&I2C_C1_DMAEN_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_WUEN_MASK                         (0x2U)                                              /*!< I2C0_C1: WUEN Mask                      */
#define I2C_C1_WUEN_SHIFT                        (1U)                                                /*!< I2C0_C1: WUEN Position                  */
#define I2C_C1_WUEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_WUEN_SHIFT))&I2C_C1_WUEN_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_RSTA_MASK                         (0x4U)                                              /*!< I2C0_C1: RSTA Mask                      */
#define I2C_C1_RSTA_SHIFT                        (2U)                                                /*!< I2C0_C1: RSTA Position                  */
#define I2C_C1_RSTA(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_RSTA_SHIFT))&I2C_C1_RSTA_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_TXAK_MASK                         (0x8U)                                              /*!< I2C0_C1: TXAK Mask                      */
#define I2C_C1_TXAK_SHIFT                        (3U)                                                /*!< I2C0_C1: TXAK Position                  */
#define I2C_C1_TXAK(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_TXAK_SHIFT))&I2C_C1_TXAK_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_TX_MASK                           (0x10U)                                             /*!< I2C0_C1: TX Mask                        */
#define I2C_C1_TX_SHIFT                          (4U)                                                /*!< I2C0_C1: TX Position                    */
#define I2C_C1_TX(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C1_TX_SHIFT))&I2C_C1_TX_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_MST_MASK                          (0x20U)                                             /*!< I2C0_C1: MST Mask                       */
#define I2C_C1_MST_SHIFT                         (5U)                                                /*!< I2C0_C1: MST Position                   */
#define I2C_C1_MST(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_C1_MST_SHIFT))&I2C_C1_MST_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_IICIE_MASK                        (0x40U)                                             /*!< I2C0_C1: IICIE Mask                     */
#define I2C_C1_IICIE_SHIFT                       (6U)                                                /*!< I2C0_C1: IICIE Position                 */
#define I2C_C1_IICIE(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICIE_SHIFT))&I2C_C1_IICIE_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_IICEN_MASK                        (0x80U)                                             /*!< I2C0_C1: IICEN Mask                     */
#define I2C_C1_IICEN_SHIFT                       (7U)                                                /*!< I2C0_C1: IICEN Position                 */
#define I2C_C1_IICEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICEN_SHIFT))&I2C_C1_IICEN_MASK) /*!< I2C0_C1                                 */
/* ------- S Bit Fields                             ------ */
#define I2C_S_RXAK_MASK                          (0x1U)                                              /*!< I2C0_S: RXAK Mask                       */
#define I2C_S_RXAK_SHIFT                         (0U)                                                /*!< I2C0_S: RXAK Position                   */
#define I2C_S_RXAK(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_RXAK_SHIFT))&I2C_S_RXAK_MASK) /*!< I2C0_S                                  */
#define I2C_S_IICIF_MASK                         (0x2U)                                              /*!< I2C0_S: IICIF Mask                      */
#define I2C_S_IICIF_SHIFT                        (1U)                                                /*!< I2C0_S: IICIF Position                  */
#define I2C_S_IICIF(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_S_IICIF_SHIFT))&I2C_S_IICIF_MASK) /*!< I2C0_S                                  */
#define I2C_S_SRW_MASK                           (0x4U)                                              /*!< I2C0_S: SRW Mask                        */
#define I2C_S_SRW_SHIFT                          (2U)                                                /*!< I2C0_S: SRW Position                    */
#define I2C_S_SRW(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_SRW_SHIFT))&I2C_S_SRW_MASK) /*!< I2C0_S                                  */
#define I2C_S_RAM_MASK                           (0x8U)                                              /*!< I2C0_S: RAM Mask                        */
#define I2C_S_RAM_SHIFT                          (3U)                                                /*!< I2C0_S: RAM Position                    */
#define I2C_S_RAM(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_RAM_SHIFT))&I2C_S_RAM_MASK) /*!< I2C0_S                                  */
#define I2C_S_ARBL_MASK                          (0x10U)                                             /*!< I2C0_S: ARBL Mask                       */
#define I2C_S_ARBL_SHIFT                         (4U)                                                /*!< I2C0_S: ARBL Position                   */
#define I2C_S_ARBL(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_ARBL_SHIFT))&I2C_S_ARBL_MASK) /*!< I2C0_S                                  */
#define I2C_S_BUSY_MASK                          (0x20U)                                             /*!< I2C0_S: BUSY Mask                       */
#define I2C_S_BUSY_SHIFT                         (5U)                                                /*!< I2C0_S: BUSY Position                   */
#define I2C_S_BUSY(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_BUSY_SHIFT))&I2C_S_BUSY_MASK) /*!< I2C0_S                                  */
#define I2C_S_IAAS_MASK                          (0x40U)                                             /*!< I2C0_S: IAAS Mask                       */
#define I2C_S_IAAS_SHIFT                         (6U)                                                /*!< I2C0_S: IAAS Position                   */
#define I2C_S_IAAS(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_IAAS_SHIFT))&I2C_S_IAAS_MASK) /*!< I2C0_S                                  */
#define I2C_S_TCF_MASK                           (0x80U)                                             /*!< I2C0_S: TCF Mask                        */
#define I2C_S_TCF_SHIFT                          (7U)                                                /*!< I2C0_S: TCF Position                    */
#define I2C_S_TCF(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_TCF_SHIFT))&I2C_S_TCF_MASK) /*!< I2C0_S                                  */
/* ------- D Bit Fields                             ------ */
#define I2C_D_DATA_MASK                          (0xFFU)                                             /*!< I2C0_D: DATA Mask                       */
#define I2C_D_DATA_SHIFT                         (0U)                                                /*!< I2C0_D: DATA Position                   */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK) /*!< I2C0_D                                  */
/* ------- C2 Bit Fields                            ------ */
#define I2C_C2_AD_MASK                           (0x7U)                                              /*!< I2C0_C2: AD Mask                        */
#define I2C_C2_AD_SHIFT                          (0U)                                                /*!< I2C0_C2: AD Position                    */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_RMEN_MASK                         (0x8U)                                              /*!< I2C0_C2: RMEN Mask                      */
#define I2C_C2_RMEN_SHIFT                        (3U)                                                /*!< I2C0_C2: RMEN Position                  */
#define I2C_C2_RMEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_RMEN_SHIFT))&I2C_C2_RMEN_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_SBRC_MASK                         (0x10U)                                             /*!< I2C0_C2: SBRC Mask                      */
#define I2C_C2_SBRC_SHIFT                        (4U)                                                /*!< I2C0_C2: SBRC Position                  */
#define I2C_C2_SBRC(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_SBRC_SHIFT))&I2C_C2_SBRC_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_HDRS_MASK                         (0x20U)                                             /*!< I2C0_C2: HDRS Mask                      */
#define I2C_C2_HDRS_SHIFT                        (5U)                                                /*!< I2C0_C2: HDRS Position                  */
#define I2C_C2_HDRS(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_HDRS_SHIFT))&I2C_C2_HDRS_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_ADEXT_MASK                        (0x40U)                                             /*!< I2C0_C2: ADEXT Mask                     */
#define I2C_C2_ADEXT_SHIFT                       (6U)                                                /*!< I2C0_C2: ADEXT Position                 */
#define I2C_C2_ADEXT(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_ADEXT_SHIFT))&I2C_C2_ADEXT_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_GCAEN_MASK                        (0x80U)                                             /*!< I2C0_C2: GCAEN Mask                     */
#define I2C_C2_GCAEN_SHIFT                       (7U)                                                /*!< I2C0_C2: GCAEN Position                 */
#define I2C_C2_GCAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_GCAEN_SHIFT))&I2C_C2_GCAEN_MASK) /*!< I2C0_C2                                 */
/* ------- FLT Bit Fields                           ------ */
#define I2C_FLT_FLT_MASK                         (0xFU)                                              /*!< I2C0_FLT: FLT Mask                      */
#define I2C_FLT_FLT_SHIFT                        (0U)                                                /*!< I2C0_FLT: FLT Position                  */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK) /*!< I2C0_FLT                                */
#define I2C_FLT_STARTF_MASK                      (0x10U)                                             /*!< I2C0_FLT: STARTF Mask                   */
#define I2C_FLT_STARTF_SHIFT                     (4U)                                                /*!< I2C0_FLT: STARTF Position               */
#define I2C_FLT_STARTF(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_FLT_STARTF_SHIFT))&I2C_FLT_STARTF_MASK) /*!< I2C0_FLT                                */
#define I2C_FLT_SSIE_MASK                        (0x20U)                                             /*!< I2C0_FLT: SSIE Mask                     */
#define I2C_FLT_SSIE_SHIFT                       (5U)                                                /*!< I2C0_FLT: SSIE Position                 */
#define I2C_FLT_SSIE(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_FLT_SSIE_SHIFT))&I2C_FLT_SSIE_MASK) /*!< I2C0_FLT                                */
#define I2C_FLT_STOPF_MASK                       (0x40U)                                             /*!< I2C0_FLT: STOPF Mask                    */
#define I2C_FLT_STOPF_SHIFT                      (6U)                                                /*!< I2C0_FLT: STOPF Position                */
#define I2C_FLT_STOPF(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_FLT_STOPF_SHIFT))&I2C_FLT_STOPF_MASK) /*!< I2C0_FLT                                */
#define I2C_FLT_SHEN_MASK                        (0x80U)                                             /*!< I2C0_FLT: SHEN Mask                     */
#define I2C_FLT_SHEN_SHIFT                       (7U)                                                /*!< I2C0_FLT: SHEN Position                 */
#define I2C_FLT_SHEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_FLT_SHEN_SHIFT))&I2C_FLT_SHEN_MASK) /*!< I2C0_FLT                                */
/* ------- RA Bit Fields                            ------ */
#define I2C_RA_RAD_MASK                          (0xFEU)                                             /*!< I2C0_RA: RAD Mask                       */
#define I2C_RA_RAD_SHIFT                         (1U)                                                /*!< I2C0_RA: RAD Position                   */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK) /*!< I2C0_RA                                 */
/* ------- SMB Bit Fields                           ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x1U)                                              /*!< I2C0_SMB: SHTF2IE Mask                  */
#define I2C_SMB_SHTF2IE_SHIFT                    (0U)                                                /*!< I2C0_SMB: SHTF2IE Position              */
#define I2C_SMB_SHTF2IE(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2IE_SHIFT))&I2C_SMB_SHTF2IE_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SHTF2_MASK                       (0x2U)                                              /*!< I2C0_SMB: SHTF2 Mask                    */
#define I2C_SMB_SHTF2_SHIFT                      (1U)                                                /*!< I2C0_SMB: SHTF2 Position                */
#define I2C_SMB_SHTF2(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2_SHIFT))&I2C_SMB_SHTF2_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SHTF1_MASK                       (0x4U)                                              /*!< I2C0_SMB: SHTF1 Mask                    */
#define I2C_SMB_SHTF1_SHIFT                      (2U)                                                /*!< I2C0_SMB: SHTF1 Position                */
#define I2C_SMB_SHTF1(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF1_SHIFT))&I2C_SMB_SHTF1_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SLTF_MASK                        (0x8U)                                              /*!< I2C0_SMB: SLTF Mask                     */
#define I2C_SMB_SLTF_SHIFT                       (3U)                                                /*!< I2C0_SMB: SLTF Position                 */
#define I2C_SMB_SLTF(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SLTF_SHIFT))&I2C_SMB_SLTF_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_TCKSEL_MASK                      (0x10U)                                             /*!< I2C0_SMB: TCKSEL Mask                   */
#define I2C_SMB_TCKSEL_SHIFT                     (4U)                                                /*!< I2C0_SMB: TCKSEL Position               */
#define I2C_SMB_TCKSEL(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_SMB_TCKSEL_SHIFT))&I2C_SMB_TCKSEL_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SIICAEN_MASK                     (0x20U)                                             /*!< I2C0_SMB: SIICAEN Mask                  */
#define I2C_SMB_SIICAEN_SHIFT                    (5U)                                                /*!< I2C0_SMB: SIICAEN Position              */
#define I2C_SMB_SIICAEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SIICAEN_SHIFT))&I2C_SMB_SIICAEN_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_ALERTEN_MASK                     (0x40U)                                             /*!< I2C0_SMB: ALERTEN Mask                  */
#define I2C_SMB_ALERTEN_SHIFT                    (6U)                                                /*!< I2C0_SMB: ALERTEN Position              */
#define I2C_SMB_ALERTEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_ALERTEN_SHIFT))&I2C_SMB_ALERTEN_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_FACK_MASK                        (0x80U)                                             /*!< I2C0_SMB: FACK Mask                     */
#define I2C_SMB_FACK_SHIFT                       (7U)                                                /*!< I2C0_SMB: FACK Position                 */
#define I2C_SMB_FACK(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_FACK_SHIFT))&I2C_SMB_FACK_MASK) /*!< I2C0_SMB                                */
/* ------- A2 Bit Fields                            ------ */
#define I2C_A2_SAD_MASK                          (0xFEU)                                             /*!< I2C0_A2: SAD Mask                       */
#define I2C_A2_SAD_SHIFT                         (1U)                                                /*!< I2C0_A2: SAD Position                   */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK) /*!< I2C0_A2                                 */
/* ------- SLTH Bit Fields                          ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTH: SSLT Mask                    */
#define I2C_SLTH_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTH: SSLT Position                */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK) /*!< I2C0_SLTH                               */
/* ------- SLTL Bit Fields                          ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTL: SSLT Mask                    */
#define I2C_SLTL_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTL: SSLT Position                */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK) /*!< I2C0_SLTL                               */
/* ------- S2 Bit Fields                            ------ */
#define I2C_S2_EMPTY_MASK                        (0x1U)                                              /*!< I2C0_S2: EMPTY Mask                     */
#define I2C_S2_EMPTY_SHIFT                       (0U)                                                /*!< I2C0_S2: EMPTY Position                 */
#define I2C_S2_EMPTY(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_S2_EMPTY_SHIFT))&I2C_S2_EMPTY_MASK) /*!< I2C0_S2                                 */
#define I2C_S2_ERROR_MASK                        (0x2U)                                              /*!< I2C0_S2: ERROR Mask                     */
#define I2C_S2_ERROR_SHIFT                       (1U)                                                /*!< I2C0_S2: ERROR Position                 */
#define I2C_S2_ERROR(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_S2_ERROR_SHIFT))&I2C_S2_ERROR_MASK) /*!< I2C0_S2                                 */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40066000UL //!< Peripheral base address
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
#define I2C1_BasePtr                   0x40067000UL //!< Peripheral base address
#define I2C1                           ((I2C_Type *) I2C1_BasePtr) //!< Freescale base pointer
#define I2C1_BASE_PTR                  (I2C1) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2S_Peripheral_access_layer_GROUP I2S Peripheral Access Layer
* @brief C Struct for I2S
* @{
*/

/* ================================================================================ */
/* ================           I2S0 (file:I2S0_MKL_B)               ================ */
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
   __IO uint32_t  TCSR;                         /**< 0000: SAI Transmit Control Register                                */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  TCR2;                         /**< 0008: SAI Transmit Configuration 2 Register                        */
   __IO uint32_t  TCR3;                         /**< 000C: SAI Transmit Configuration 3 Register                        */
   __IO uint32_t  TCR4;                         /**< 0010: SAI Transmit Configuration 4 Register                        */
   __IO uint32_t  TCR5;                         /**< 0014: SAI Transmit Configuration 5 Register                        */
        uint8_t   RESERVED_1[8];               
   __O  uint32_t  TDR[1];                       /**< 0020: SAI Transmit Data Register                                   */
        uint8_t   RESERVED_2[60];              
   __IO uint32_t  TMR;                          /**< 0060: SAI Transmit Mask Register                                   */
        uint8_t   RESERVED_3[28];              
   __IO uint32_t  RCSR;                         /**< 0080: SAI Receive Control Register                                 */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  RCR2;                         /**< 0088: SAI Receive Configuration 2 Register                         */
   __IO uint32_t  RCR3;                         /**< 008C: SAI Receive Configuration 3 Register                         */
   __IO uint32_t  RCR4;                         /**< 0090: SAI Receive Configuration 4 Register                         */
   __IO uint32_t  RCR5;                         /**< 0094: SAI Receive Configuration 5 Register                         */
        uint8_t   RESERVED_5[8];               
   __I  uint32_t  RDR[1];                       /**< 00A0: SAI Receive Data Register                                    */
        uint8_t   RESERVED_6[60];              
   __IO uint32_t  RMR;                          /**< 00E0: SAI Receive Mask Register                                    */
        uint8_t   RESERVED_7[28];              
   __IO uint32_t  MCR;                          /**< 0100: SAI MCLK Control Register                                    */
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
#define I2S_TCSR_FWDE_MASK                       (0x2U)                                              /*!< I2S0_TCSR: FWDE Mask                    */
#define I2S_TCSR_FWDE_SHIFT                      (1U)                                                /*!< I2S0_TCSR: FWDE Position                */
#define I2S_TCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWDE_SHIFT))&I2S_TCSR_FWDE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FWIE_MASK                       (0x200U)                                            /*!< I2S0_TCSR: FWIE Mask                    */
#define I2S_TCSR_FWIE_SHIFT                      (9U)                                                /*!< I2S0_TCSR: FWIE Position                */
#define I2S_TCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWIE_SHIFT))&I2S_TCSR_FWIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FEIE_MASK                       (0x400U)                                            /*!< I2S0_TCSR: FEIE Mask                    */
#define I2S_TCSR_FEIE_SHIFT                      (10U)                                               /*!< I2S0_TCSR: FEIE Position                */
#define I2S_TCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FEIE_SHIFT))&I2S_TCSR_FEIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SEIE_MASK                       (0x800U)                                            /*!< I2S0_TCSR: SEIE Mask                    */
#define I2S_TCSR_SEIE_SHIFT                      (11U)                                               /*!< I2S0_TCSR: SEIE Position                */
#define I2S_TCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SEIE_SHIFT))&I2S_TCSR_SEIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_WSIE_MASK                       (0x1000U)                                           /*!< I2S0_TCSR: WSIE Mask                    */
#define I2S_TCSR_WSIE_SHIFT                      (12U)                                               /*!< I2S0_TCSR: WSIE Position                */
#define I2S_TCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_WSIE_SHIFT))&I2S_TCSR_WSIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FWF_MASK                        (0x20000U)                                          /*!< I2S0_TCSR: FWF Mask                     */
#define I2S_TCSR_FWF_SHIFT                       (17U)                                               /*!< I2S0_TCSR: FWF Position                 */
#define I2S_TCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWF_SHIFT))&I2S_TCSR_FWF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FEF_MASK                        (0x40000U)                                          /*!< I2S0_TCSR: FEF Mask                     */
#define I2S_TCSR_FEF_SHIFT                       (18U)                                               /*!< I2S0_TCSR: FEF Position                 */
#define I2S_TCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FEF_SHIFT))&I2S_TCSR_FEF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SEF_MASK                        (0x80000U)                                          /*!< I2S0_TCSR: SEF Mask                     */
#define I2S_TCSR_SEF_SHIFT                       (19U)                                               /*!< I2S0_TCSR: SEF Position                 */
#define I2S_TCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SEF_SHIFT))&I2S_TCSR_SEF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_WSF_MASK                        (0x100000U)                                         /*!< I2S0_TCSR: WSF Mask                     */
#define I2S_TCSR_WSF_SHIFT                       (20U)                                               /*!< I2S0_TCSR: WSF Position                 */
#define I2S_TCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_WSF_SHIFT))&I2S_TCSR_WSF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SR_MASK                         (0x1000000U)                                        /*!< I2S0_TCSR: SR Mask                      */
#define I2S_TCSR_SR_SHIFT                        (24U)                                               /*!< I2S0_TCSR: SR Position                  */
#define I2S_TCSR_SR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SR_SHIFT))&I2S_TCSR_SR_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FR_MASK                         (0x2000000U)                                        /*!< I2S0_TCSR: FR Mask                      */
#define I2S_TCSR_FR_SHIFT                        (25U)                                               /*!< I2S0_TCSR: FR Position                  */
#define I2S_TCSR_FR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FR_SHIFT))&I2S_TCSR_FR_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_BCE_MASK                        (0x10000000U)                                       /*!< I2S0_TCSR: BCE Mask                     */
#define I2S_TCSR_BCE_SHIFT                       (28U)                                               /*!< I2S0_TCSR: BCE Position                 */
#define I2S_TCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_BCE_SHIFT))&I2S_TCSR_BCE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_DBGE_MASK                       (0x20000000U)                                       /*!< I2S0_TCSR: DBGE Mask                    */
#define I2S_TCSR_DBGE_SHIFT                      (29U)                                               /*!< I2S0_TCSR: DBGE Position                */
#define I2S_TCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_DBGE_SHIFT))&I2S_TCSR_DBGE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_STOPE_MASK                      (0x40000000U)                                       /*!< I2S0_TCSR: STOPE Mask                   */
#define I2S_TCSR_STOPE_SHIFT                     (30U)                                               /*!< I2S0_TCSR: STOPE Position               */
#define I2S_TCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_STOPE_SHIFT))&I2S_TCSR_STOPE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_TE_MASK                         (0x80000000U)                                       /*!< I2S0_TCSR: TE Mask                      */
#define I2S_TCSR_TE_SHIFT                        (31U)                                               /*!< I2S0_TCSR: TE Position                  */
#define I2S_TCSR_TE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_TE_SHIFT))&I2S_TCSR_TE_MASK) /*!< I2S0_TCSR                               */
/* ------- TCR2 Bit Fields                          ------ */
#define I2S_TCR2_DIV_MASK                        (0xFFU)                                             /*!< I2S0_TCR2: DIV Mask                     */
#define I2S_TCR2_DIV_SHIFT                       (0U)                                                /*!< I2S0_TCR2: DIV Position                 */
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_DIV_SHIFT))&I2S_TCR2_DIV_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCD_MASK                        (0x1000000U)                                        /*!< I2S0_TCR2: BCD Mask                     */
#define I2S_TCR2_BCD_SHIFT                       (24U)                                               /*!< I2S0_TCR2: BCD Position                 */
#define I2S_TCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCD_SHIFT))&I2S_TCR2_BCD_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCP_MASK                        (0x2000000U)                                        /*!< I2S0_TCR2: BCP Mask                     */
#define I2S_TCR2_BCP_SHIFT                       (25U)                                               /*!< I2S0_TCR2: BCP Position                 */
#define I2S_TCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCP_SHIFT))&I2S_TCR2_BCP_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_MSEL_MASK                       (0xC000000U)                                        /*!< I2S0_TCR2: MSEL Mask                    */
#define I2S_TCR2_MSEL_SHIFT                      (26U)                                               /*!< I2S0_TCR2: MSEL Position                */
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_MSEL_SHIFT))&I2S_TCR2_MSEL_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCI_MASK                        (0x10000000U)                                       /*!< I2S0_TCR2: BCI Mask                     */
#define I2S_TCR2_BCI_SHIFT                       (28U)                                               /*!< I2S0_TCR2: BCI Position                 */
#define I2S_TCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCI_SHIFT))&I2S_TCR2_BCI_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCS_MASK                        (0x20000000U)                                       /*!< I2S0_TCR2: BCS Mask                     */
#define I2S_TCR2_BCS_SHIFT                       (29U)                                               /*!< I2S0_TCR2: BCS Position                 */
#define I2S_TCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCS_SHIFT))&I2S_TCR2_BCS_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_SYNC_MASK                       (0xC0000000U)                                       /*!< I2S0_TCR2: SYNC Mask                    */
#define I2S_TCR2_SYNC_SHIFT                      (30U)                                               /*!< I2S0_TCR2: SYNC Position                */
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_SYNC_SHIFT))&I2S_TCR2_SYNC_MASK) /*!< I2S0_TCR2                               */
/* ------- TCR3 Bit Fields                          ------ */
#define I2S_TCR3_WDFL_MASK                       (0x1U)                                              /*!< I2S0_TCR3: WDFL Mask                    */
#define I2S_TCR3_WDFL_SHIFT                      (0U)                                                /*!< I2S0_TCR3: WDFL Position                */
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_WDFL_SHIFT))&I2S_TCR3_WDFL_MASK) /*!< I2S0_TCR3                               */
#define I2S_TCR3_TCE_MASK                        (0x10000U)                                          /*!< I2S0_TCR3: TCE Mask                     */
#define I2S_TCR3_TCE_SHIFT                       (16U)                                               /*!< I2S0_TCR3: TCE Position                 */
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_TCE_SHIFT))&I2S_TCR3_TCE_MASK) /*!< I2S0_TCR3                               */
/* ------- TCR4 Bit Fields                          ------ */
#define I2S_TCR4_FSD_MASK                        (0x1U)                                              /*!< I2S0_TCR4: FSD Mask                     */
#define I2S_TCR4_FSD_SHIFT                       (0U)                                                /*!< I2S0_TCR4: FSD Position                 */
#define I2S_TCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSD_SHIFT))&I2S_TCR4_FSD_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FSP_MASK                        (0x2U)                                              /*!< I2S0_TCR4: FSP Mask                     */
#define I2S_TCR4_FSP_SHIFT                       (1U)                                                /*!< I2S0_TCR4: FSP Position                 */
#define I2S_TCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSP_SHIFT))&I2S_TCR4_FSP_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_ONDEM_MASK                      (0x4U)                                              /*!< I2S0_TCR4: ONDEM Mask                   */
#define I2S_TCR4_ONDEM_SHIFT                     (2U)                                                /*!< I2S0_TCR4: ONDEM Position               */
#define I2S_TCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_ONDEM_SHIFT))&I2S_TCR4_ONDEM_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FSE_MASK                        (0x8U)                                              /*!< I2S0_TCR4: FSE Mask                     */
#define I2S_TCR4_FSE_SHIFT                       (3U)                                                /*!< I2S0_TCR4: FSE Position                 */
#define I2S_TCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSE_SHIFT))&I2S_TCR4_FSE_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_MF_MASK                         (0x10U)                                             /*!< I2S0_TCR4: MF Mask                      */
#define I2S_TCR4_MF_SHIFT                        (4U)                                                /*!< I2S0_TCR4: MF Position                  */
#define I2S_TCR4_MF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_MF_SHIFT))&I2S_TCR4_MF_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_SYWD_MASK                       (0x1F00U)                                           /*!< I2S0_TCR4: SYWD Mask                    */
#define I2S_TCR4_SYWD_SHIFT                      (8U)                                                /*!< I2S0_TCR4: SYWD Position                */
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_SYWD_SHIFT))&I2S_TCR4_SYWD_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FRSZ_MASK                       (0x10000U)                                          /*!< I2S0_TCR4: FRSZ Mask                    */
#define I2S_TCR4_FRSZ_SHIFT                      (16U)                                               /*!< I2S0_TCR4: FRSZ Position                */
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FRSZ_SHIFT))&I2S_TCR4_FRSZ_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FPACK_MASK                      (0x3000000U)                                        /*!< I2S0_TCR4: FPACK Mask                   */
#define I2S_TCR4_FPACK_SHIFT                     (24U)                                               /*!< I2S0_TCR4: FPACK Position               */
#define I2S_TCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FPACK_SHIFT))&I2S_TCR4_FPACK_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FCONT_MASK                      (0x10000000U)                                       /*!< I2S0_TCR4: FCONT Mask                   */
#define I2S_TCR4_FCONT_SHIFT                     (28U)                                               /*!< I2S0_TCR4: FCONT Position               */
#define I2S_TCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FCONT_SHIFT))&I2S_TCR4_FCONT_MASK) /*!< I2S0_TCR4                               */
/* ------- TCR5 Bit Fields                          ------ */
#define I2S_TCR5_FBT_MASK                        (0x1F00U)                                           /*!< I2S0_TCR5: FBT Mask                     */
#define I2S_TCR5_FBT_SHIFT                       (8U)                                                /*!< I2S0_TCR5: FBT Position                 */
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_FBT_SHIFT))&I2S_TCR5_FBT_MASK) /*!< I2S0_TCR5                               */
#define I2S_TCR5_W0W_MASK                        (0x1F0000U)                                         /*!< I2S0_TCR5: W0W Mask                     */
#define I2S_TCR5_W0W_SHIFT                       (16U)                                               /*!< I2S0_TCR5: W0W Position                 */
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_W0W_SHIFT))&I2S_TCR5_W0W_MASK) /*!< I2S0_TCR5                               */
#define I2S_TCR5_WNW_MASK                        (0x1F000000U)                                       /*!< I2S0_TCR5: WNW Mask                     */
#define I2S_TCR5_WNW_SHIFT                       (24U)                                               /*!< I2S0_TCR5: WNW Position                 */
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_WNW_SHIFT))&I2S_TCR5_WNW_MASK) /*!< I2S0_TCR5                               */
/* ------- TDR Bit Fields                           ------ */
#define I2S_TDR_TDR_MASK                         (0xFFFFFFFFU)                                       /*!< I2S0_TDR: TDR Mask                      */
#define I2S_TDR_TDR_SHIFT                        (0U)                                                /*!< I2S0_TDR: TDR Position                  */
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TDR_TDR_SHIFT))&I2S_TDR_TDR_MASK) /*!< I2S0_TDR                                */
/* ------- TMR Bit Fields                           ------ */
#define I2S_TMR_TWM_MASK                         (0x3U)                                              /*!< I2S0_TMR: TWM Mask                      */
#define I2S_TMR_TWM_SHIFT                        (0U)                                                /*!< I2S0_TMR: TWM Position                  */
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TMR_TWM_SHIFT))&I2S_TMR_TWM_MASK) /*!< I2S0_TMR                                */
/* ------- RCSR Bit Fields                          ------ */
#define I2S_RCSR_FWDE_MASK                       (0x2U)                                              /*!< I2S0_RCSR: FWDE Mask                    */
#define I2S_RCSR_FWDE_SHIFT                      (1U)                                                /*!< I2S0_RCSR: FWDE Position                */
#define I2S_RCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWDE_SHIFT))&I2S_RCSR_FWDE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FWIE_MASK                       (0x200U)                                            /*!< I2S0_RCSR: FWIE Mask                    */
#define I2S_RCSR_FWIE_SHIFT                      (9U)                                                /*!< I2S0_RCSR: FWIE Position                */
#define I2S_RCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWIE_SHIFT))&I2S_RCSR_FWIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FEIE_MASK                       (0x400U)                                            /*!< I2S0_RCSR: FEIE Mask                    */
#define I2S_RCSR_FEIE_SHIFT                      (10U)                                               /*!< I2S0_RCSR: FEIE Position                */
#define I2S_RCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FEIE_SHIFT))&I2S_RCSR_FEIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SEIE_MASK                       (0x800U)                                            /*!< I2S0_RCSR: SEIE Mask                    */
#define I2S_RCSR_SEIE_SHIFT                      (11U)                                               /*!< I2S0_RCSR: SEIE Position                */
#define I2S_RCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SEIE_SHIFT))&I2S_RCSR_SEIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_WSIE_MASK                       (0x1000U)                                           /*!< I2S0_RCSR: WSIE Mask                    */
#define I2S_RCSR_WSIE_SHIFT                      (12U)                                               /*!< I2S0_RCSR: WSIE Position                */
#define I2S_RCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_WSIE_SHIFT))&I2S_RCSR_WSIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FWF_MASK                        (0x20000U)                                          /*!< I2S0_RCSR: FWF Mask                     */
#define I2S_RCSR_FWF_SHIFT                       (17U)                                               /*!< I2S0_RCSR: FWF Position                 */
#define I2S_RCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWF_SHIFT))&I2S_RCSR_FWF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FEF_MASK                        (0x40000U)                                          /*!< I2S0_RCSR: FEF Mask                     */
#define I2S_RCSR_FEF_SHIFT                       (18U)                                               /*!< I2S0_RCSR: FEF Position                 */
#define I2S_RCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FEF_SHIFT))&I2S_RCSR_FEF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SEF_MASK                        (0x80000U)                                          /*!< I2S0_RCSR: SEF Mask                     */
#define I2S_RCSR_SEF_SHIFT                       (19U)                                               /*!< I2S0_RCSR: SEF Position                 */
#define I2S_RCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SEF_SHIFT))&I2S_RCSR_SEF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_WSF_MASK                        (0x100000U)                                         /*!< I2S0_RCSR: WSF Mask                     */
#define I2S_RCSR_WSF_SHIFT                       (20U)                                               /*!< I2S0_RCSR: WSF Position                 */
#define I2S_RCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_WSF_SHIFT))&I2S_RCSR_WSF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SR_MASK                         (0x1000000U)                                        /*!< I2S0_RCSR: SR Mask                      */
#define I2S_RCSR_SR_SHIFT                        (24U)                                               /*!< I2S0_RCSR: SR Position                  */
#define I2S_RCSR_SR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SR_SHIFT))&I2S_RCSR_SR_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FR_MASK                         (0x2000000U)                                        /*!< I2S0_RCSR: FR Mask                      */
#define I2S_RCSR_FR_SHIFT                        (25U)                                               /*!< I2S0_RCSR: FR Position                  */
#define I2S_RCSR_FR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FR_SHIFT))&I2S_RCSR_FR_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_BCE_MASK                        (0x10000000U)                                       /*!< I2S0_RCSR: BCE Mask                     */
#define I2S_RCSR_BCE_SHIFT                       (28U)                                               /*!< I2S0_RCSR: BCE Position                 */
#define I2S_RCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_BCE_SHIFT))&I2S_RCSR_BCE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_DBGE_MASK                       (0x20000000U)                                       /*!< I2S0_RCSR: DBGE Mask                    */
#define I2S_RCSR_DBGE_SHIFT                      (29U)                                               /*!< I2S0_RCSR: DBGE Position                */
#define I2S_RCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_DBGE_SHIFT))&I2S_RCSR_DBGE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_STOPE_MASK                      (0x40000000U)                                       /*!< I2S0_RCSR: STOPE Mask                   */
#define I2S_RCSR_STOPE_SHIFT                     (30U)                                               /*!< I2S0_RCSR: STOPE Position               */
#define I2S_RCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_STOPE_SHIFT))&I2S_RCSR_STOPE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_RE_MASK                         (0x80000000U)                                       /*!< I2S0_RCSR: RE Mask                      */
#define I2S_RCSR_RE_SHIFT                        (31U)                                               /*!< I2S0_RCSR: RE Position                  */
#define I2S_RCSR_RE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_RE_SHIFT))&I2S_RCSR_RE_MASK) /*!< I2S0_RCSR                               */
/* ------- RCR2 Bit Fields                          ------ */
#define I2S_RCR2_DIV_MASK                        (0xFFU)                                             /*!< I2S0_RCR2: DIV Mask                     */
#define I2S_RCR2_DIV_SHIFT                       (0U)                                                /*!< I2S0_RCR2: DIV Position                 */
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_DIV_SHIFT))&I2S_RCR2_DIV_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCD_MASK                        (0x1000000U)                                        /*!< I2S0_RCR2: BCD Mask                     */
#define I2S_RCR2_BCD_SHIFT                       (24U)                                               /*!< I2S0_RCR2: BCD Position                 */
#define I2S_RCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCD_SHIFT))&I2S_RCR2_BCD_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCP_MASK                        (0x2000000U)                                        /*!< I2S0_RCR2: BCP Mask                     */
#define I2S_RCR2_BCP_SHIFT                       (25U)                                               /*!< I2S0_RCR2: BCP Position                 */
#define I2S_RCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCP_SHIFT))&I2S_RCR2_BCP_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_MSEL_MASK                       (0xC000000U)                                        /*!< I2S0_RCR2: MSEL Mask                    */
#define I2S_RCR2_MSEL_SHIFT                      (26U)                                               /*!< I2S0_RCR2: MSEL Position                */
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_MSEL_SHIFT))&I2S_RCR2_MSEL_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCI_MASK                        (0x10000000U)                                       /*!< I2S0_RCR2: BCI Mask                     */
#define I2S_RCR2_BCI_SHIFT                       (28U)                                               /*!< I2S0_RCR2: BCI Position                 */
#define I2S_RCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCI_SHIFT))&I2S_RCR2_BCI_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCS_MASK                        (0x20000000U)                                       /*!< I2S0_RCR2: BCS Mask                     */
#define I2S_RCR2_BCS_SHIFT                       (29U)                                               /*!< I2S0_RCR2: BCS Position                 */
#define I2S_RCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCS_SHIFT))&I2S_RCR2_BCS_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_SYNC_MASK                       (0xC0000000U)                                       /*!< I2S0_RCR2: SYNC Mask                    */
#define I2S_RCR2_SYNC_SHIFT                      (30U)                                               /*!< I2S0_RCR2: SYNC Position                */
#define I2S_RCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_SYNC_SHIFT))&I2S_RCR2_SYNC_MASK) /*!< I2S0_RCR2                               */
/* ------- RCR3 Bit Fields                          ------ */
#define I2S_RCR3_WDFL_MASK                       (0x1U)                                              /*!< I2S0_RCR3: WDFL Mask                    */
#define I2S_RCR3_WDFL_SHIFT                      (0U)                                                /*!< I2S0_RCR3: WDFL Position                */
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_WDFL_SHIFT))&I2S_RCR3_WDFL_MASK) /*!< I2S0_RCR3                               */
#define I2S_RCR3_RCE_MASK                        (0x10000U)                                          /*!< I2S0_RCR3: RCE Mask                     */
#define I2S_RCR3_RCE_SHIFT                       (16U)                                               /*!< I2S0_RCR3: RCE Position                 */
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_RCE_SHIFT))&I2S_RCR3_RCE_MASK) /*!< I2S0_RCR3                               */
/* ------- RCR4 Bit Fields                          ------ */
#define I2S_RCR4_FSD_MASK                        (0x1U)                                              /*!< I2S0_RCR4: FSD Mask                     */
#define I2S_RCR4_FSD_SHIFT                       (0U)                                                /*!< I2S0_RCR4: FSD Position                 */
#define I2S_RCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSD_SHIFT))&I2S_RCR4_FSD_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FSP_MASK                        (0x2U)                                              /*!< I2S0_RCR4: FSP Mask                     */
#define I2S_RCR4_FSP_SHIFT                       (1U)                                                /*!< I2S0_RCR4: FSP Position                 */
#define I2S_RCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSP_SHIFT))&I2S_RCR4_FSP_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_ONDEM_MASK                      (0x4U)                                              /*!< I2S0_RCR4: ONDEM Mask                   */
#define I2S_RCR4_ONDEM_SHIFT                     (2U)                                                /*!< I2S0_RCR4: ONDEM Position               */
#define I2S_RCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_ONDEM_SHIFT))&I2S_RCR4_ONDEM_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FSE_MASK                        (0x8U)                                              /*!< I2S0_RCR4: FSE Mask                     */
#define I2S_RCR4_FSE_SHIFT                       (3U)                                                /*!< I2S0_RCR4: FSE Position                 */
#define I2S_RCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSE_SHIFT))&I2S_RCR4_FSE_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_MF_MASK                         (0x10U)                                             /*!< I2S0_RCR4: MF Mask                      */
#define I2S_RCR4_MF_SHIFT                        (4U)                                                /*!< I2S0_RCR4: MF Position                  */
#define I2S_RCR4_MF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_MF_SHIFT))&I2S_RCR4_MF_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_SYWD_MASK                       (0x1F00U)                                           /*!< I2S0_RCR4: SYWD Mask                    */
#define I2S_RCR4_SYWD_SHIFT                      (8U)                                                /*!< I2S0_RCR4: SYWD Position                */
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_SYWD_SHIFT))&I2S_RCR4_SYWD_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FRSZ_MASK                       (0x10000U)                                          /*!< I2S0_RCR4: FRSZ Mask                    */
#define I2S_RCR4_FRSZ_SHIFT                      (16U)                                               /*!< I2S0_RCR4: FRSZ Position                */
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FRSZ_SHIFT))&I2S_RCR4_FRSZ_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FPACK_MASK                      (0x3000000U)                                        /*!< I2S0_RCR4: FPACK Mask                   */
#define I2S_RCR4_FPACK_SHIFT                     (24U)                                               /*!< I2S0_RCR4: FPACK Position               */
#define I2S_RCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FPACK_SHIFT))&I2S_RCR4_FPACK_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FCONT_MASK                      (0x10000000U)                                       /*!< I2S0_RCR4: FCONT Mask                   */
#define I2S_RCR4_FCONT_SHIFT                     (28U)                                               /*!< I2S0_RCR4: FCONT Position               */
#define I2S_RCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FCONT_SHIFT))&I2S_RCR4_FCONT_MASK) /*!< I2S0_RCR4                               */
/* ------- RCR5 Bit Fields                          ------ */
#define I2S_RCR5_FBT_MASK                        (0x1F00U)                                           /*!< I2S0_RCR5: FBT Mask                     */
#define I2S_RCR5_FBT_SHIFT                       (8U)                                                /*!< I2S0_RCR5: FBT Position                 */
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_FBT_SHIFT))&I2S_RCR5_FBT_MASK) /*!< I2S0_RCR5                               */
#define I2S_RCR5_W0W_MASK                        (0x1F0000U)                                         /*!< I2S0_RCR5: W0W Mask                     */
#define I2S_RCR5_W0W_SHIFT                       (16U)                                               /*!< I2S0_RCR5: W0W Position                 */
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_W0W_SHIFT))&I2S_RCR5_W0W_MASK) /*!< I2S0_RCR5                               */
#define I2S_RCR5_WNW_MASK                        (0x1F000000U)                                       /*!< I2S0_RCR5: WNW Mask                     */
#define I2S_RCR5_WNW_SHIFT                       (24U)                                               /*!< I2S0_RCR5: WNW Position                 */
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_WNW_SHIFT))&I2S_RCR5_WNW_MASK) /*!< I2S0_RCR5                               */
/* ------- RDR Bit Fields                           ------ */
#define I2S_RDR_RDR_MASK                         (0xFFFFFFFFU)                                       /*!< I2S0_RDR: RDR Mask                      */
#define I2S_RDR_RDR_SHIFT                        (0U)                                                /*!< I2S0_RDR: RDR Position                  */
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RDR_RDR_SHIFT))&I2S_RDR_RDR_MASK) /*!< I2S0_RDR                                */
/* ------- RMR Bit Fields                           ------ */
#define I2S_RMR_RWM_MASK                         (0x3U)                                              /*!< I2S0_RMR: RWM Mask                      */
#define I2S_RMR_RWM_SHIFT                        (0U)                                                /*!< I2S0_RMR: RWM Position                  */
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RMR_RWM_SHIFT))&I2S_RMR_RWM_MASK) /*!< I2S0_RMR                                */
/* ------- MCR Bit Fields                           ------ */
#define I2S_MCR_MICS_MASK                        (0x3000000U)                                        /*!< I2S0_MCR: MICS Mask                     */
#define I2S_MCR_MICS_SHIFT                       (24U)                                               /*!< I2S0_MCR: MICS Position                 */
#define I2S_MCR_MICS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MICS_SHIFT))&I2S_MCR_MICS_MASK) /*!< I2S0_MCR                                */
#define I2S_MCR_MOE_MASK                         (0x40000000U)                                       /*!< I2S0_MCR: MOE Mask                      */
#define I2S_MCR_MOE_SHIFT                        (30U)                                               /*!< I2S0_MCR: MOE Position                  */
#define I2S_MCR_MOE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MOE_SHIFT))&I2S_MCR_MOE_MASK) /*!< I2S0_MCR                                */
#define I2S_MCR_DUF_MASK                         (0x80000000U)                                       /*!< I2S0_MCR: DUF Mask                      */
#define I2S_MCR_DUF_SHIFT                        (31U)                                               /*!< I2S0_MCR: DUF Position                  */
#define I2S_MCR_DUF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_MCR_DUF_SHIFT))&I2S_MCR_DUF_MASK) /*!< I2S0_MCR                                */
/**
 * @} */ /* End group I2S_Register_Masks_GROUP 
 */

/* I2S0 - Peripheral instance base addresses */
#define I2S0_BasePtr                   0x4002F000UL //!< Peripheral base address
#define I2S0                           ((I2S_Type *) I2S0_BasePtr) //!< Freescale base pointer
#define I2S0_BASE_PTR                  (I2S0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2S_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LLWU_Peripheral_access_layer_GROUP LLWU Peripheral Access Layer
* @brief C Struct for LLWU
* @{
*/

/* ================================================================================ */
/* ================           LLWU (file:LLWU_PE3_FILT2)           ================ */
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
   union {                                      /**< 0000: (size=0001)                                                  */
      __I  uint8_t   F3;                        /**< 0007: Flag 3 Register                                              */
      __I  uint8_t   MF0;                       /**< 0007: Module Flag 0 Register                                       */
   };
   __IO uint8_t   FILT1;                        /**< 0008: Pin Filter 1 register                                        */
   __IO uint8_t   FILT2;                        /**< 0009: Pin Filter 2 register                                        */
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
#define LLWU_PE1_WUPE0_MASK                      (0x3U)                                              /*!< LLWU_PE1: WUPE0 Mask                    */
#define LLWU_PE1_WUPE0_SHIFT                     (0U)                                                /*!< LLWU_PE1: WUPE0 Position                */
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE1_MASK                      (0xCU)                                              /*!< LLWU_PE1: WUPE1 Mask                    */
#define LLWU_PE1_WUPE1_SHIFT                     (2U)                                                /*!< LLWU_PE1: WUPE1 Position                */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE2_MASK                      (0x30U)                                             /*!< LLWU_PE1: WUPE2 Mask                    */
#define LLWU_PE1_WUPE2_SHIFT                     (4U)                                                /*!< LLWU_PE1: WUPE2 Position                */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE3_MASK                      (0xC0U)                                             /*!< LLWU_PE1: WUPE3 Mask                    */
#define LLWU_PE1_WUPE3_SHIFT                     (6U)                                                /*!< LLWU_PE1: WUPE3 Position                */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK) /*!< LLWU_PE1                                */
/* ------- PE2 Bit Fields                           ------ */
#define LLWU_PE2_WUPE4_MASK                      (0x3U)                                              /*!< LLWU_PE2: WUPE4 Mask                    */
#define LLWU_PE2_WUPE4_SHIFT                     (0U)                                                /*!< LLWU_PE2: WUPE4 Position                */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE5_MASK                      (0xCU)                                              /*!< LLWU_PE2: WUPE5 Mask                    */
#define LLWU_PE2_WUPE5_SHIFT                     (2U)                                                /*!< LLWU_PE2: WUPE5 Position                */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE6_MASK                      (0x30U)                                             /*!< LLWU_PE2: WUPE6 Mask                    */
#define LLWU_PE2_WUPE6_SHIFT                     (4U)                                                /*!< LLWU_PE2: WUPE6 Position                */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE7_MASK                      (0xC0U)                                             /*!< LLWU_PE2: WUPE7 Mask                    */
#define LLWU_PE2_WUPE7_SHIFT                     (6U)                                                /*!< LLWU_PE2: WUPE7 Position                */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK) /*!< LLWU_PE2                                */
/* ------- PE3 Bit Fields                           ------ */
#define LLWU_PE3_WUPE8_MASK                      (0x3U)                                              /*!< LLWU_PE3: WUPE8 Mask                    */
#define LLWU_PE3_WUPE8_SHIFT                     (0U)                                                /*!< LLWU_PE3: WUPE8 Position                */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE9_MASK                      (0xCU)                                              /*!< LLWU_PE3: WUPE9 Mask                    */
#define LLWU_PE3_WUPE9_SHIFT                     (2U)                                                /*!< LLWU_PE3: WUPE9 Position                */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE10_MASK                     (0x30U)                                             /*!< LLWU_PE3: WUPE10 Mask                   */
#define LLWU_PE3_WUPE10_SHIFT                    (4U)                                                /*!< LLWU_PE3: WUPE10 Position               */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE11_MASK                     (0xC0U)                                             /*!< LLWU_PE3: WUPE11 Mask                   */
#define LLWU_PE3_WUPE11_SHIFT                    (6U)                                                /*!< LLWU_PE3: WUPE11 Position               */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK) /*!< LLWU_PE3                                */
/* ------- PE4 Bit Fields                           ------ */
#define LLWU_PE4_WUPE12_MASK                     (0x3U)                                              /*!< LLWU_PE4: WUPE12 Mask                   */
#define LLWU_PE4_WUPE12_SHIFT                    (0U)                                                /*!< LLWU_PE4: WUPE12 Position               */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE13_MASK                     (0xCU)                                              /*!< LLWU_PE4: WUPE13 Mask                   */
#define LLWU_PE4_WUPE13_SHIFT                    (2U)                                                /*!< LLWU_PE4: WUPE13 Position               */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE14_MASK                     (0x30U)                                             /*!< LLWU_PE4: WUPE14 Mask                   */
#define LLWU_PE4_WUPE14_SHIFT                    (4U)                                                /*!< LLWU_PE4: WUPE14 Position               */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE15_MASK                     (0xC0U)                                             /*!< LLWU_PE4: WUPE15 Mask                   */
#define LLWU_PE4_WUPE15_SHIFT                    (6U)                                                /*!< LLWU_PE4: WUPE15 Position               */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK) /*!< LLWU_PE4                                */
/* ------- ME Bit Fields                            ------ */
#define LLWU_ME_WUME0_MASK                       (0x1U)                                              /*!< LLWU_ME: WUME0 Mask                     */
#define LLWU_ME_WUME0_SHIFT                      (0U)                                                /*!< LLWU_ME: WUME0 Position                 */
#define LLWU_ME_WUME0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME0_SHIFT))&LLWU_ME_WUME0_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME1_MASK                       (0x2U)                                              /*!< LLWU_ME: WUME1 Mask                     */
#define LLWU_ME_WUME1_SHIFT                      (1U)                                                /*!< LLWU_ME: WUME1 Position                 */
#define LLWU_ME_WUME1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME1_SHIFT))&LLWU_ME_WUME1_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME2_MASK                       (0x4U)                                              /*!< LLWU_ME: WUME2 Mask                     */
#define LLWU_ME_WUME2_SHIFT                      (2U)                                                /*!< LLWU_ME: WUME2 Position                 */
#define LLWU_ME_WUME2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME2_SHIFT))&LLWU_ME_WUME2_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME3_MASK                       (0x8U)                                              /*!< LLWU_ME: WUME3 Mask                     */
#define LLWU_ME_WUME3_SHIFT                      (3U)                                                /*!< LLWU_ME: WUME3 Position                 */
#define LLWU_ME_WUME3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME3_SHIFT))&LLWU_ME_WUME3_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME4_MASK                       (0x10U)                                             /*!< LLWU_ME: WUME4 Mask                     */
#define LLWU_ME_WUME4_SHIFT                      (4U)                                                /*!< LLWU_ME: WUME4 Position                 */
#define LLWU_ME_WUME4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME4_SHIFT))&LLWU_ME_WUME4_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME5_MASK                       (0x20U)                                             /*!< LLWU_ME: WUME5 Mask                     */
#define LLWU_ME_WUME5_SHIFT                      (5U)                                                /*!< LLWU_ME: WUME5 Position                 */
#define LLWU_ME_WUME5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME5_SHIFT))&LLWU_ME_WUME5_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME6_MASK                       (0x40U)                                             /*!< LLWU_ME: WUME6 Mask                     */
#define LLWU_ME_WUME6_SHIFT                      (6U)                                                /*!< LLWU_ME: WUME6 Position                 */
#define LLWU_ME_WUME6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME6_SHIFT))&LLWU_ME_WUME6_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME7_MASK                       (0x80U)                                             /*!< LLWU_ME: WUME7 Mask                     */
#define LLWU_ME_WUME7_SHIFT                      (7U)                                                /*!< LLWU_ME: WUME7 Position                 */
#define LLWU_ME_WUME7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME7_SHIFT))&LLWU_ME_WUME7_MASK) /*!< LLWU_ME                                 */
/* ------- F1 Bit Fields                            ------ */
#define LLWU_F1_WUF0_MASK                        (0x1U)                                              /*!< LLWU_F1: WUF0 Mask                      */
#define LLWU_F1_WUF0_SHIFT                       (0U)                                                /*!< LLWU_F1: WUF0 Position                  */
#define LLWU_F1_WUF0(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF0_SHIFT))&LLWU_F1_WUF0_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF1_MASK                        (0x2U)                                              /*!< LLWU_F1: WUF1 Mask                      */
#define LLWU_F1_WUF1_SHIFT                       (1U)                                                /*!< LLWU_F1: WUF1 Position                  */
#define LLWU_F1_WUF1(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF1_SHIFT))&LLWU_F1_WUF1_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF2_MASK                        (0x4U)                                              /*!< LLWU_F1: WUF2 Mask                      */
#define LLWU_F1_WUF2_SHIFT                       (2U)                                                /*!< LLWU_F1: WUF2 Position                  */
#define LLWU_F1_WUF2(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF2_SHIFT))&LLWU_F1_WUF2_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF3_MASK                        (0x8U)                                              /*!< LLWU_F1: WUF3 Mask                      */
#define LLWU_F1_WUF3_SHIFT                       (3U)                                                /*!< LLWU_F1: WUF3 Position                  */
#define LLWU_F1_WUF3(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF3_SHIFT))&LLWU_F1_WUF3_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF4_MASK                        (0x10U)                                             /*!< LLWU_F1: WUF4 Mask                      */
#define LLWU_F1_WUF4_SHIFT                       (4U)                                                /*!< LLWU_F1: WUF4 Position                  */
#define LLWU_F1_WUF4(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF4_SHIFT))&LLWU_F1_WUF4_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF5_MASK                        (0x20U)                                             /*!< LLWU_F1: WUF5 Mask                      */
#define LLWU_F1_WUF5_SHIFT                       (5U)                                                /*!< LLWU_F1: WUF5 Position                  */
#define LLWU_F1_WUF5(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF5_SHIFT))&LLWU_F1_WUF5_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF6_MASK                        (0x40U)                                             /*!< LLWU_F1: WUF6 Mask                      */
#define LLWU_F1_WUF6_SHIFT                       (6U)                                                /*!< LLWU_F1: WUF6 Position                  */
#define LLWU_F1_WUF6(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF6_SHIFT))&LLWU_F1_WUF6_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF7_MASK                        (0x80U)                                             /*!< LLWU_F1: WUF7 Mask                      */
#define LLWU_F1_WUF7_SHIFT                       (7U)                                                /*!< LLWU_F1: WUF7 Position                  */
#define LLWU_F1_WUF7(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF7_SHIFT))&LLWU_F1_WUF7_MASK) /*!< LLWU_F1                                 */
/* ------- F2 Bit Fields                            ------ */
#define LLWU_F2_WUF8_MASK                        (0x1U)                                              /*!< LLWU_F2: WUF8 Mask                      */
#define LLWU_F2_WUF8_SHIFT                       (0U)                                                /*!< LLWU_F2: WUF8 Position                  */
#define LLWU_F2_WUF8(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF8_SHIFT))&LLWU_F2_WUF8_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF9_MASK                        (0x2U)                                              /*!< LLWU_F2: WUF9 Mask                      */
#define LLWU_F2_WUF9_SHIFT                       (1U)                                                /*!< LLWU_F2: WUF9 Position                  */
#define LLWU_F2_WUF9(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF9_SHIFT))&LLWU_F2_WUF9_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF10_MASK                       (0x4U)                                              /*!< LLWU_F2: WUF10 Mask                     */
#define LLWU_F2_WUF10_SHIFT                      (2U)                                                /*!< LLWU_F2: WUF10 Position                 */
#define LLWU_F2_WUF10(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF10_SHIFT))&LLWU_F2_WUF10_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF11_MASK                       (0x8U)                                              /*!< LLWU_F2: WUF11 Mask                     */
#define LLWU_F2_WUF11_SHIFT                      (3U)                                                /*!< LLWU_F2: WUF11 Position                 */
#define LLWU_F2_WUF11(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF11_SHIFT))&LLWU_F2_WUF11_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF12_MASK                       (0x10U)                                             /*!< LLWU_F2: WUF12 Mask                     */
#define LLWU_F2_WUF12_SHIFT                      (4U)                                                /*!< LLWU_F2: WUF12 Position                 */
#define LLWU_F2_WUF12(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF12_SHIFT))&LLWU_F2_WUF12_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF13_MASK                       (0x20U)                                             /*!< LLWU_F2: WUF13 Mask                     */
#define LLWU_F2_WUF13_SHIFT                      (5U)                                                /*!< LLWU_F2: WUF13 Position                 */
#define LLWU_F2_WUF13(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF13_SHIFT))&LLWU_F2_WUF13_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF14_MASK                       (0x40U)                                             /*!< LLWU_F2: WUF14 Mask                     */
#define LLWU_F2_WUF14_SHIFT                      (6U)                                                /*!< LLWU_F2: WUF14 Position                 */
#define LLWU_F2_WUF14(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF14_SHIFT))&LLWU_F2_WUF14_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF15_MASK                       (0x80U)                                             /*!< LLWU_F2: WUF15 Mask                     */
#define LLWU_F2_WUF15_SHIFT                      (7U)                                                /*!< LLWU_F2: WUF15 Position                 */
#define LLWU_F2_WUF15(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF15_SHIFT))&LLWU_F2_WUF15_MASK) /*!< LLWU_F2                                 */
/* ------- F3 Bit Fields                            ------ */
#define LLWU_F3_MWUF0_MASK                       (0x1U)                                              /*!< LLWU_F3: MWUF0 Mask                     */
#define LLWU_F3_MWUF0_SHIFT                      (0U)                                                /*!< LLWU_F3: MWUF0 Position                 */
#define LLWU_F3_MWUF0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF0_SHIFT))&LLWU_F3_MWUF0_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF1_MASK                       (0x2U)                                              /*!< LLWU_F3: MWUF1 Mask                     */
#define LLWU_F3_MWUF1_SHIFT                      (1U)                                                /*!< LLWU_F3: MWUF1 Position                 */
#define LLWU_F3_MWUF1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF1_SHIFT))&LLWU_F3_MWUF1_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF2_MASK                       (0x4U)                                              /*!< LLWU_F3: MWUF2 Mask                     */
#define LLWU_F3_MWUF2_SHIFT                      (2U)                                                /*!< LLWU_F3: MWUF2 Position                 */
#define LLWU_F3_MWUF2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF2_SHIFT))&LLWU_F3_MWUF2_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF3_MASK                       (0x8U)                                              /*!< LLWU_F3: MWUF3 Mask                     */
#define LLWU_F3_MWUF3_SHIFT                      (3U)                                                /*!< LLWU_F3: MWUF3 Position                 */
#define LLWU_F3_MWUF3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF3_SHIFT))&LLWU_F3_MWUF3_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF4_MASK                       (0x10U)                                             /*!< LLWU_F3: MWUF4 Mask                     */
#define LLWU_F3_MWUF4_SHIFT                      (4U)                                                /*!< LLWU_F3: MWUF4 Position                 */
#define LLWU_F3_MWUF4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF4_SHIFT))&LLWU_F3_MWUF4_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF5_MASK                       (0x20U)                                             /*!< LLWU_F3: MWUF5 Mask                     */
#define LLWU_F3_MWUF5_SHIFT                      (5U)                                                /*!< LLWU_F3: MWUF5 Position                 */
#define LLWU_F3_MWUF5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF5_SHIFT))&LLWU_F3_MWUF5_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF6_MASK                       (0x40U)                                             /*!< LLWU_F3: MWUF6 Mask                     */
#define LLWU_F3_MWUF6_SHIFT                      (6U)                                                /*!< LLWU_F3: MWUF6 Position                 */
#define LLWU_F3_MWUF6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF6_SHIFT))&LLWU_F3_MWUF6_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF7_MASK                       (0x80U)                                             /*!< LLWU_F3: MWUF7 Mask                     */
#define LLWU_F3_MWUF7_SHIFT                      (7U)                                                /*!< LLWU_F3: MWUF7 Position                 */
#define LLWU_F3_MWUF7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF7_SHIFT))&LLWU_F3_MWUF7_MASK) /*!< LLWU_F3                                 */
/* ------- MF0 Bit Fields                           ------ */
/* ------- FILT Bit Fields                          ------ */
#define LLWU_FILT_FILTSEL_MASK                   (0xFU)                                              /*!< LLWU_FILT: FILTSEL Mask                 */
#define LLWU_FILT_FILTSEL_SHIFT                  (0U)                                                /*!< LLWU_FILT: FILTSEL Position             */
#define LLWU_FILT_FILTSEL(x)                     (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTSEL_SHIFT))&LLWU_FILT_FILTSEL_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTE_MASK                     (0x60U)                                             /*!< LLWU_FILT: FILTE Mask                   */
#define LLWU_FILT_FILTE_SHIFT                    (5U)                                                /*!< LLWU_FILT: FILTE Position               */
#define LLWU_FILT_FILTE(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTE_SHIFT))&LLWU_FILT_FILTE_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTF_MASK                     (0x80U)                                             /*!< LLWU_FILT: FILTF Mask                   */
#define LLWU_FILT_FILTF_SHIFT                    (7U)                                                /*!< LLWU_FILT: FILTF Position               */
#define LLWU_FILT_FILTF(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTF_SHIFT))&LLWU_FILT_FILTF_MASK) /*!< LLWU_FILT                               */
/**
 * @} */ /* End group LLWU_Register_Masks_GROUP 
 */

/* LLWU - Peripheral instance base addresses */
#define LLWU_BasePtr                   0x4007C000UL //!< Peripheral base address
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
/* ================           LPTMR0 (file:LPTMR0_0)               ================ */
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
   __IO uint32_t  CNR;                          /**< 000C: Counter Register                                             */
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
#define LPTMR_CSR_TEN_MASK                       (0x1U)                                              /*!< LPTMR0_CSR: TEN Mask                    */
#define LPTMR_CSR_TEN_SHIFT                      (0U)                                                /*!< LPTMR0_CSR: TEN Position                */
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TEN_SHIFT))&LPTMR_CSR_TEN_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TMS_MASK                       (0x2U)                                              /*!< LPTMR0_CSR: TMS Mask                    */
#define LPTMR_CSR_TMS_SHIFT                      (1U)                                                /*!< LPTMR0_CSR: TMS Position                */
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TMS_SHIFT))&LPTMR_CSR_TMS_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TFC_MASK                       (0x4U)                                              /*!< LPTMR0_CSR: TFC Mask                    */
#define LPTMR_CSR_TFC_SHIFT                      (2U)                                                /*!< LPTMR0_CSR: TFC Position                */
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TFC_SHIFT))&LPTMR_CSR_TFC_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TPP_MASK                       (0x8U)                                              /*!< LPTMR0_CSR: TPP Mask                    */
#define LPTMR_CSR_TPP_SHIFT                      (3U)                                                /*!< LPTMR0_CSR: TPP Position                */
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPP_SHIFT))&LPTMR_CSR_TPP_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TPS_MASK                       (0x30U)                                             /*!< LPTMR0_CSR: TPS Mask                    */
#define LPTMR_CSR_TPS_SHIFT                      (4U)                                                /*!< LPTMR0_CSR: TPS Position                */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TIE_MASK                       (0x40U)                                             /*!< LPTMR0_CSR: TIE Mask                    */
#define LPTMR_CSR_TIE_SHIFT                      (6U)                                                /*!< LPTMR0_CSR: TIE Position                */
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TIE_SHIFT))&LPTMR_CSR_TIE_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TCF_MASK                       (0x80U)                                             /*!< LPTMR0_CSR: TCF Mask                    */
#define LPTMR_CSR_TCF_SHIFT                      (7U)                                                /*!< LPTMR0_CSR: TCF Position                */
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TCF_SHIFT))&LPTMR_CSR_TCF_MASK) /*!< LPTMR0_CSR                              */
/* ------- PSR Bit Fields                           ------ */
#define LPTMR_PSR_PCS_MASK                       (0x3U)                                              /*!< LPTMR0_PSR: PCS Mask                    */
#define LPTMR_PSR_PCS_SHIFT                      (0U)                                                /*!< LPTMR0_PSR: PCS Position                */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK) /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PBYP_MASK                      (0x4U)                                              /*!< LPTMR0_PSR: PBYP Mask                   */
#define LPTMR_PSR_PBYP_SHIFT                     (2U)                                                /*!< LPTMR0_PSR: PBYP Position               */
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PBYP_SHIFT))&LPTMR_PSR_PBYP_MASK) /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PRESCALE_MASK                  (0x78U)                                             /*!< LPTMR0_PSR: PRESCALE Mask               */
#define LPTMR_PSR_PRESCALE_SHIFT                 (3U)                                                /*!< LPTMR0_PSR: PRESCALE Position           */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK) /*!< LPTMR0_PSR                              */
/* ------- CMR Bit Fields                           ------ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFU)                                           /*!< LPTMR0_CMR: COMPARE Mask                */
#define LPTMR_CMR_COMPARE_SHIFT                  (0U)                                                /*!< LPTMR0_CMR: COMPARE Position            */
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK) /*!< LPTMR0_CMR                              */
/* ------- CNR Bit Fields                           ------ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFU)                                           /*!< LPTMR0_CNR: COUNTER Mask                */
#define LPTMR_CNR_COUNTER_SHIFT                  (0U)                                                /*!< LPTMR0_CNR: COUNTER Position            */
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK) /*!< LPTMR0_CNR                              */
/**
 * @} */ /* End group LPTMR_Register_Masks_GROUP 
 */

/* LPTMR0 - Peripheral instance base addresses */
#define LPTMR0_BasePtr                 0x40040000UL //!< Peripheral base address
#define LPTMR0                         ((LPTMR_Type *) LPTMR0_BasePtr) //!< Freescale base pointer
#define LPTMR0_BASE_PTR                (LPTMR0) //!< Freescale style base pointer
/**
 * @} */ /* End group LPTMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPUART_Peripheral_access_layer_GROUP LPUART Peripheral Access Layer
* @brief C Struct for LPUART
* @{
*/

/* ================================================================================ */
/* ================           LPUART0 (file:LPUART0_MKL17)         ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup LPUART_structs_GROUP LPUART struct
* @brief Struct for LPUART
* @{
*/
typedef struct {                                /*       LPUART0 Structure                                            */
   __IO uint32_t  BAUD;                         /**< 0000: Baud Rate Register                                           */
   __IO uint32_t  STAT;                         /**< 0004: Status Register                                              */
   __IO uint32_t  CTRL;                         /**< 0008: Control Register                                             */
   __IO uint32_t  DATA;                         /**< 000C: Data Register                                                */
   __IO uint32_t  MATCH;                        /**< 0010: Match Address Register                                       */
} LPUART_Type;

/**
 * @} */ /* End group LPUART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPUART0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LPUART_Register_Masks_GROUP LPUART Register Masks
* @brief Register Masks for LPUART
* @{
*/
/* ------- BAUD Bit Fields                          ------ */
#define LPUART_BAUD_SBR_MASK                     (0x1FFFU)                                           /*!< LPUART0_BAUD: SBR Mask                  */
#define LPUART_BAUD_SBR_SHIFT                    (0U)                                                /*!< LPUART0_BAUD: SBR Position              */
#define LPUART_BAUD_SBR(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_SBR_SHIFT))&LPUART_BAUD_SBR_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_SBNS_MASK                    (0x2000U)                                           /*!< LPUART0_BAUD: SBNS Mask                 */
#define LPUART_BAUD_SBNS_SHIFT                   (13U)                                               /*!< LPUART0_BAUD: SBNS Position             */
#define LPUART_BAUD_SBNS(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_SBNS_SHIFT))&LPUART_BAUD_SBNS_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_RXEDGIE_MASK                 (0x4000U)                                           /*!< LPUART0_BAUD: RXEDGIE Mask              */
#define LPUART_BAUD_RXEDGIE_SHIFT                (14U)                                               /*!< LPUART0_BAUD: RXEDGIE Position          */
#define LPUART_BAUD_RXEDGIE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RXEDGIE_SHIFT))&LPUART_BAUD_RXEDGIE_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_LBKDIE_MASK                  (0x8000U)                                           /*!< LPUART0_BAUD: LBKDIE Mask               */
#define LPUART_BAUD_LBKDIE_SHIFT                 (15U)                                               /*!< LPUART0_BAUD: LBKDIE Position           */
#define LPUART_BAUD_LBKDIE(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_LBKDIE_SHIFT))&LPUART_BAUD_LBKDIE_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_RESYNCDIS_MASK               (0x10000U)                                          /*!< LPUART0_BAUD: RESYNCDIS Mask            */
#define LPUART_BAUD_RESYNCDIS_SHIFT              (16U)                                               /*!< LPUART0_BAUD: RESYNCDIS Position        */
#define LPUART_BAUD_RESYNCDIS(x)                 (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RESYNCDIS_SHIFT))&LPUART_BAUD_RESYNCDIS_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_BOTHEDGE_MASK                (0x20000U)                                          /*!< LPUART0_BAUD: BOTHEDGE Mask             */
#define LPUART_BAUD_BOTHEDGE_SHIFT               (17U)                                               /*!< LPUART0_BAUD: BOTHEDGE Position         */
#define LPUART_BAUD_BOTHEDGE(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_BOTHEDGE_SHIFT))&LPUART_BAUD_BOTHEDGE_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_MATCFG_MASK                  (0xC0000U)                                          /*!< LPUART0_BAUD: MATCFG Mask               */
#define LPUART_BAUD_MATCFG_SHIFT                 (18U)                                               /*!< LPUART0_BAUD: MATCFG Position           */
#define LPUART_BAUD_MATCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MATCFG_SHIFT))&LPUART_BAUD_MATCFG_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_RDMAE_MASK                   (0x200000U)                                         /*!< LPUART0_BAUD: RDMAE Mask                */
#define LPUART_BAUD_RDMAE_SHIFT                  (21U)                                               /*!< LPUART0_BAUD: RDMAE Position            */
#define LPUART_BAUD_RDMAE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RDMAE_SHIFT))&LPUART_BAUD_RDMAE_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_TDMAE_MASK                   (0x800000U)                                         /*!< LPUART0_BAUD: TDMAE Mask                */
#define LPUART_BAUD_TDMAE_SHIFT                  (23U)                                               /*!< LPUART0_BAUD: TDMAE Position            */
#define LPUART_BAUD_TDMAE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_TDMAE_SHIFT))&LPUART_BAUD_TDMAE_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_OSR_MASK                     (0x1F000000U)                                       /*!< LPUART0_BAUD: OSR Mask                  */
#define LPUART_BAUD_OSR_SHIFT                    (24U)                                               /*!< LPUART0_BAUD: OSR Position              */
#define LPUART_BAUD_OSR(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_OSR_SHIFT))&LPUART_BAUD_OSR_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_M10_MASK                     (0x20000000U)                                       /*!< LPUART0_BAUD: M10 Mask                  */
#define LPUART_BAUD_M10_SHIFT                    (29U)                                               /*!< LPUART0_BAUD: M10 Position              */
#define LPUART_BAUD_M10(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_M10_SHIFT))&LPUART_BAUD_M10_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_MAEN2_MASK                   (0x40000000U)                                       /*!< LPUART0_BAUD: MAEN2 Mask                */
#define LPUART_BAUD_MAEN2_SHIFT                  (30U)                                               /*!< LPUART0_BAUD: MAEN2 Position            */
#define LPUART_BAUD_MAEN2(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MAEN2_SHIFT))&LPUART_BAUD_MAEN2_MASK) /*!< LPUART0_BAUD                            */
#define LPUART_BAUD_MAEN1_MASK                   (0x80000000U)                                       /*!< LPUART0_BAUD: MAEN1 Mask                */
#define LPUART_BAUD_MAEN1_SHIFT                  (31U)                                               /*!< LPUART0_BAUD: MAEN1 Position            */
#define LPUART_BAUD_MAEN1(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MAEN1_SHIFT))&LPUART_BAUD_MAEN1_MASK) /*!< LPUART0_BAUD                            */
/* ------- STAT Bit Fields                          ------ */
#define LPUART_STAT_MA2F_MASK                    (0x4000U)                                           /*!< LPUART0_STAT: MA2F Mask                 */
#define LPUART_STAT_MA2F_SHIFT                   (14U)                                               /*!< LPUART0_STAT: MA2F Position             */
#define LPUART_STAT_MA2F(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MA2F_SHIFT))&LPUART_STAT_MA2F_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_MA1F_MASK                    (0x8000U)                                           /*!< LPUART0_STAT: MA1F Mask                 */
#define LPUART_STAT_MA1F_SHIFT                   (15U)                                               /*!< LPUART0_STAT: MA1F Position             */
#define LPUART_STAT_MA1F(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MA1F_SHIFT))&LPUART_STAT_MA1F_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_PF_MASK                      (0x10000U)                                          /*!< LPUART0_STAT: PF Mask                   */
#define LPUART_STAT_PF_SHIFT                     (16U)                                               /*!< LPUART0_STAT: PF Position               */
#define LPUART_STAT_PF(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_PF_SHIFT))&LPUART_STAT_PF_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_FE_MASK                      (0x20000U)                                          /*!< LPUART0_STAT: FE Mask                   */
#define LPUART_STAT_FE_SHIFT                     (17U)                                               /*!< LPUART0_STAT: FE Position               */
#define LPUART_STAT_FE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_FE_SHIFT))&LPUART_STAT_FE_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_NF_MASK                      (0x40000U)                                          /*!< LPUART0_STAT: NF Mask                   */
#define LPUART_STAT_NF_SHIFT                     (18U)                                               /*!< LPUART0_STAT: NF Position               */
#define LPUART_STAT_NF(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_NF_SHIFT))&LPUART_STAT_NF_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_OR_MASK                      (0x80000U)                                          /*!< LPUART0_STAT: OR Mask                   */
#define LPUART_STAT_OR_SHIFT                     (19U)                                               /*!< LPUART0_STAT: OR Position               */
#define LPUART_STAT_OR(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_OR_SHIFT))&LPUART_STAT_OR_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_IDLE_MASK                    (0x100000U)                                         /*!< LPUART0_STAT: IDLE Mask                 */
#define LPUART_STAT_IDLE_SHIFT                   (20U)                                               /*!< LPUART0_STAT: IDLE Position             */
#define LPUART_STAT_IDLE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_IDLE_SHIFT))&LPUART_STAT_IDLE_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_RDRF_MASK                    (0x200000U)                                         /*!< LPUART0_STAT: RDRF Mask                 */
#define LPUART_STAT_RDRF_SHIFT                   (21U)                                               /*!< LPUART0_STAT: RDRF Position             */
#define LPUART_STAT_RDRF(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RDRF_SHIFT))&LPUART_STAT_RDRF_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_TC_MASK                      (0x400000U)                                         /*!< LPUART0_STAT: TC Mask                   */
#define LPUART_STAT_TC_SHIFT                     (22U)                                               /*!< LPUART0_STAT: TC Position               */
#define LPUART_STAT_TC(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_TC_SHIFT))&LPUART_STAT_TC_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_TDRE_MASK                    (0x800000U)                                         /*!< LPUART0_STAT: TDRE Mask                 */
#define LPUART_STAT_TDRE_SHIFT                   (23U)                                               /*!< LPUART0_STAT: TDRE Position             */
#define LPUART_STAT_TDRE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_TDRE_SHIFT))&LPUART_STAT_TDRE_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_RAF_MASK                     (0x1000000U)                                        /*!< LPUART0_STAT: RAF Mask                  */
#define LPUART_STAT_RAF_SHIFT                    (24U)                                               /*!< LPUART0_STAT: RAF Position              */
#define LPUART_STAT_RAF(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RAF_SHIFT))&LPUART_STAT_RAF_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_LBKDE_MASK                   (0x2000000U)                                        /*!< LPUART0_STAT: LBKDE Mask                */
#define LPUART_STAT_LBKDE_SHIFT                  (25U)                                               /*!< LPUART0_STAT: LBKDE Position            */
#define LPUART_STAT_LBKDE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_LBKDE_SHIFT))&LPUART_STAT_LBKDE_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_BRK13_MASK                   (0x4000000U)                                        /*!< LPUART0_STAT: BRK13 Mask                */
#define LPUART_STAT_BRK13_SHIFT                  (26U)                                               /*!< LPUART0_STAT: BRK13 Position            */
#define LPUART_STAT_BRK13(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_BRK13_SHIFT))&LPUART_STAT_BRK13_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_RWUID_MASK                   (0x8000000U)                                        /*!< LPUART0_STAT: RWUID Mask                */
#define LPUART_STAT_RWUID_SHIFT                  (27U)                                               /*!< LPUART0_STAT: RWUID Position            */
#define LPUART_STAT_RWUID(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RWUID_SHIFT))&LPUART_STAT_RWUID_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_RXINV_MASK                   (0x10000000U)                                       /*!< LPUART0_STAT: RXINV Mask                */
#define LPUART_STAT_RXINV_SHIFT                  (28U)                                               /*!< LPUART0_STAT: RXINV Position            */
#define LPUART_STAT_RXINV(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RXINV_SHIFT))&LPUART_STAT_RXINV_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_MSBF_MASK                    (0x20000000U)                                       /*!< LPUART0_STAT: MSBF Mask                 */
#define LPUART_STAT_MSBF_SHIFT                   (29U)                                               /*!< LPUART0_STAT: MSBF Position             */
#define LPUART_STAT_MSBF(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MSBF_SHIFT))&LPUART_STAT_MSBF_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_RXEDGIF_MASK                 (0x40000000U)                                       /*!< LPUART0_STAT: RXEDGIF Mask              */
#define LPUART_STAT_RXEDGIF_SHIFT                (30U)                                               /*!< LPUART0_STAT: RXEDGIF Position          */
#define LPUART_STAT_RXEDGIF(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RXEDGIF_SHIFT))&LPUART_STAT_RXEDGIF_MASK) /*!< LPUART0_STAT                            */
#define LPUART_STAT_LBKDIF_MASK                  (0x80000000U)                                       /*!< LPUART0_STAT: LBKDIF Mask               */
#define LPUART_STAT_LBKDIF_SHIFT                 (31U)                                               /*!< LPUART0_STAT: LBKDIF Position           */
#define LPUART_STAT_LBKDIF(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_LBKDIF_SHIFT))&LPUART_STAT_LBKDIF_MASK) /*!< LPUART0_STAT                            */
/* ------- CTRL Bit Fields                          ------ */
#define LPUART_CTRL_PT_MASK                      (0x1U)                                              /*!< LPUART0_CTRL: PT Mask                   */
#define LPUART_CTRL_PT_SHIFT                     (0U)                                                /*!< LPUART0_CTRL: PT Position               */
#define LPUART_CTRL_PT(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PT_SHIFT))&LPUART_CTRL_PT_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_PE_MASK                      (0x2U)                                              /*!< LPUART0_CTRL: PE Mask                   */
#define LPUART_CTRL_PE_SHIFT                     (1U)                                                /*!< LPUART0_CTRL: PE Position               */
#define LPUART_CTRL_PE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PE_SHIFT))&LPUART_CTRL_PE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_ILT_MASK                     (0x4U)                                              /*!< LPUART0_CTRL: ILT Mask                  */
#define LPUART_CTRL_ILT_SHIFT                    (2U)                                                /*!< LPUART0_CTRL: ILT Position              */
#define LPUART_CTRL_ILT(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ILT_SHIFT))&LPUART_CTRL_ILT_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_WAKE_MASK                    (0x8U)                                              /*!< LPUART0_CTRL: WAKE Mask                 */
#define LPUART_CTRL_WAKE_SHIFT                   (3U)                                                /*!< LPUART0_CTRL: WAKE Position             */
#define LPUART_CTRL_WAKE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_WAKE_SHIFT))&LPUART_CTRL_WAKE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_M_MASK                       (0x10U)                                             /*!< LPUART0_CTRL: M Mask                    */
#define LPUART_CTRL_M_SHIFT                      (4U)                                                /*!< LPUART0_CTRL: M Position                */
#define LPUART_CTRL_M(x)                         (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_M_SHIFT))&LPUART_CTRL_M_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_RSRC_MASK                    (0x20U)                                             /*!< LPUART0_CTRL: RSRC Mask                 */
#define LPUART_CTRL_RSRC_SHIFT                   (5U)                                                /*!< LPUART0_CTRL: RSRC Position             */
#define LPUART_CTRL_RSRC(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RSRC_SHIFT))&LPUART_CTRL_RSRC_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_DOZEEN_MASK                  (0x40U)                                             /*!< LPUART0_CTRL: DOZEEN Mask               */
#define LPUART_CTRL_DOZEEN_SHIFT                 (6U)                                                /*!< LPUART0_CTRL: DOZEEN Position           */
#define LPUART_CTRL_DOZEEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_DOZEEN_SHIFT))&LPUART_CTRL_DOZEEN_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_LOOPS_MASK                   (0x80U)                                             /*!< LPUART0_CTRL: LOOPS Mask                */
#define LPUART_CTRL_LOOPS_SHIFT                  (7U)                                                /*!< LPUART0_CTRL: LOOPS Position            */
#define LPUART_CTRL_LOOPS(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_LOOPS_SHIFT))&LPUART_CTRL_LOOPS_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_IDLECFG_MASK                 (0x700U)                                            /*!< LPUART0_CTRL: IDLECFG Mask              */
#define LPUART_CTRL_IDLECFG_SHIFT                (8U)                                                /*!< LPUART0_CTRL: IDLECFG Position          */
#define LPUART_CTRL_IDLECFG(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_IDLECFG_SHIFT))&LPUART_CTRL_IDLECFG_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_MA2IE_MASK                   (0x4000U)                                           /*!< LPUART0_CTRL: MA2IE Mask                */
#define LPUART_CTRL_MA2IE_SHIFT                  (14U)                                               /*!< LPUART0_CTRL: MA2IE Position            */
#define LPUART_CTRL_MA2IE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_MA2IE_SHIFT))&LPUART_CTRL_MA2IE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_MA1IE_MASK                   (0x8000U)                                           /*!< LPUART0_CTRL: MA1IE Mask                */
#define LPUART_CTRL_MA1IE_SHIFT                  (15U)                                               /*!< LPUART0_CTRL: MA1IE Position            */
#define LPUART_CTRL_MA1IE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_MA1IE_SHIFT))&LPUART_CTRL_MA1IE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_SBK_MASK                     (0x10000U)                                          /*!< LPUART0_CTRL: SBK Mask                  */
#define LPUART_CTRL_SBK_SHIFT                    (16U)                                               /*!< LPUART0_CTRL: SBK Position              */
#define LPUART_CTRL_SBK(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_SBK_SHIFT))&LPUART_CTRL_SBK_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_RWU_MASK                     (0x20000U)                                          /*!< LPUART0_CTRL: RWU Mask                  */
#define LPUART_CTRL_RWU_SHIFT                    (17U)                                               /*!< LPUART0_CTRL: RWU Position              */
#define LPUART_CTRL_RWU(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RWU_SHIFT))&LPUART_CTRL_RWU_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_RE_MASK                      (0x40000U)                                          /*!< LPUART0_CTRL: RE Mask                   */
#define LPUART_CTRL_RE_SHIFT                     (18U)                                               /*!< LPUART0_CTRL: RE Position               */
#define LPUART_CTRL_RE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RE_SHIFT))&LPUART_CTRL_RE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_TE_MASK                      (0x80000U)                                          /*!< LPUART0_CTRL: TE Mask                   */
#define LPUART_CTRL_TE_SHIFT                     (19U)                                               /*!< LPUART0_CTRL: TE Position               */
#define LPUART_CTRL_TE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TE_SHIFT))&LPUART_CTRL_TE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_ILIE_MASK                    (0x100000U)                                         /*!< LPUART0_CTRL: ILIE Mask                 */
#define LPUART_CTRL_ILIE_SHIFT                   (20U)                                               /*!< LPUART0_CTRL: ILIE Position             */
#define LPUART_CTRL_ILIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ILIE_SHIFT))&LPUART_CTRL_ILIE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_RIE_MASK                     (0x200000U)                                         /*!< LPUART0_CTRL: RIE Mask                  */
#define LPUART_CTRL_RIE_SHIFT                    (21U)                                               /*!< LPUART0_CTRL: RIE Position              */
#define LPUART_CTRL_RIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RIE_SHIFT))&LPUART_CTRL_RIE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_TCIE_MASK                    (0x400000U)                                         /*!< LPUART0_CTRL: TCIE Mask                 */
#define LPUART_CTRL_TCIE_SHIFT                   (22U)                                               /*!< LPUART0_CTRL: TCIE Position             */
#define LPUART_CTRL_TCIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TCIE_SHIFT))&LPUART_CTRL_TCIE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_TIE_MASK                     (0x800000U)                                         /*!< LPUART0_CTRL: TIE Mask                  */
#define LPUART_CTRL_TIE_SHIFT                    (23U)                                               /*!< LPUART0_CTRL: TIE Position              */
#define LPUART_CTRL_TIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TIE_SHIFT))&LPUART_CTRL_TIE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_PEIE_MASK                    (0x1000000U)                                        /*!< LPUART0_CTRL: PEIE Mask                 */
#define LPUART_CTRL_PEIE_SHIFT                   (24U)                                               /*!< LPUART0_CTRL: PEIE Position             */
#define LPUART_CTRL_PEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PEIE_SHIFT))&LPUART_CTRL_PEIE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_FEIE_MASK                    (0x2000000U)                                        /*!< LPUART0_CTRL: FEIE Mask                 */
#define LPUART_CTRL_FEIE_SHIFT                   (25U)                                               /*!< LPUART0_CTRL: FEIE Position             */
#define LPUART_CTRL_FEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_FEIE_SHIFT))&LPUART_CTRL_FEIE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_NEIE_MASK                    (0x4000000U)                                        /*!< LPUART0_CTRL: NEIE Mask                 */
#define LPUART_CTRL_NEIE_SHIFT                   (26U)                                               /*!< LPUART0_CTRL: NEIE Position             */
#define LPUART_CTRL_NEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_NEIE_SHIFT))&LPUART_CTRL_NEIE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_ORIE_MASK                    (0x8000000U)                                        /*!< LPUART0_CTRL: ORIE Mask                 */
#define LPUART_CTRL_ORIE_SHIFT                   (27U)                                               /*!< LPUART0_CTRL: ORIE Position             */
#define LPUART_CTRL_ORIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ORIE_SHIFT))&LPUART_CTRL_ORIE_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_TXINV_MASK                   (0x10000000U)                                       /*!< LPUART0_CTRL: TXINV Mask                */
#define LPUART_CTRL_TXINV_SHIFT                  (28U)                                               /*!< LPUART0_CTRL: TXINV Position            */
#define LPUART_CTRL_TXINV(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TXINV_SHIFT))&LPUART_CTRL_TXINV_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_TXDIR_MASK                   (0x20000000U)                                       /*!< LPUART0_CTRL: TXDIR Mask                */
#define LPUART_CTRL_TXDIR_SHIFT                  (29U)                                               /*!< LPUART0_CTRL: TXDIR Position            */
#define LPUART_CTRL_TXDIR(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TXDIR_SHIFT))&LPUART_CTRL_TXDIR_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_R9T8_MASK                    (0x40000000U)                                       /*!< LPUART0_CTRL: R9T8 Mask                 */
#define LPUART_CTRL_R9T8_SHIFT                   (30U)                                               /*!< LPUART0_CTRL: R9T8 Position             */
#define LPUART_CTRL_R9T8(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_R9T8_SHIFT))&LPUART_CTRL_R9T8_MASK) /*!< LPUART0_CTRL                            */
#define LPUART_CTRL_R8T9_MASK                    (0x80000000U)                                       /*!< LPUART0_CTRL: R8T9 Mask                 */
#define LPUART_CTRL_R8T9_SHIFT                   (31U)                                               /*!< LPUART0_CTRL: R8T9 Position             */
#define LPUART_CTRL_R8T9(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_R8T9_SHIFT))&LPUART_CTRL_R8T9_MASK) /*!< LPUART0_CTRL                            */
/* ------- DATA Bit Fields                          ------ */
#define LPUART_DATA_RT_MASK                      (0x3FFU)                                            /*!< LPUART0_DATA: RT Mask                   */
#define LPUART_DATA_RT_SHIFT                     (0U)                                                /*!< LPUART0_DATA: RT Position               */
#define LPUART_DATA_RT(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_RT_SHIFT))&LPUART_DATA_RT_MASK) /*!< LPUART0_DATA                            */
#define LPUART_DATA_IDLINE_MASK                  (0x800U)                                            /*!< LPUART0_DATA: IDLINE Mask               */
#define LPUART_DATA_IDLINE_SHIFT                 (11U)                                               /*!< LPUART0_DATA: IDLINE Position           */
#define LPUART_DATA_IDLINE(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_IDLINE_SHIFT))&LPUART_DATA_IDLINE_MASK) /*!< LPUART0_DATA                            */
#define LPUART_DATA_RXEMPT_MASK                  (0x1000U)                                           /*!< LPUART0_DATA: RXEMPT Mask               */
#define LPUART_DATA_RXEMPT_SHIFT                 (12U)                                               /*!< LPUART0_DATA: RXEMPT Position           */
#define LPUART_DATA_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_RXEMPT_SHIFT))&LPUART_DATA_RXEMPT_MASK) /*!< LPUART0_DATA                            */
#define LPUART_DATA_FRETSC_MASK                  (0x2000U)                                           /*!< LPUART0_DATA: FRETSC Mask               */
#define LPUART_DATA_FRETSC_SHIFT                 (13U)                                               /*!< LPUART0_DATA: FRETSC Position           */
#define LPUART_DATA_FRETSC(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_FRETSC_SHIFT))&LPUART_DATA_FRETSC_MASK) /*!< LPUART0_DATA                            */
#define LPUART_DATA_PARITYE_MASK                 (0x4000U)                                           /*!< LPUART0_DATA: PARITYE Mask              */
#define LPUART_DATA_PARITYE_SHIFT                (14U)                                               /*!< LPUART0_DATA: PARITYE Position          */
#define LPUART_DATA_PARITYE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_PARITYE_SHIFT))&LPUART_DATA_PARITYE_MASK) /*!< LPUART0_DATA                            */
#define LPUART_DATA_NOISY_MASK                   (0x8000U)                                           /*!< LPUART0_DATA: NOISY Mask                */
#define LPUART_DATA_NOISY_SHIFT                  (15U)                                               /*!< LPUART0_DATA: NOISY Position            */
#define LPUART_DATA_NOISY(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_NOISY_SHIFT))&LPUART_DATA_NOISY_MASK) /*!< LPUART0_DATA                            */
/* ------- MATCH Bit Fields                         ------ */
#define LPUART_MATCH_MA1_MASK                    (0x3FFU)                                            /*!< LPUART0_MATCH: MA1 Mask                 */
#define LPUART_MATCH_MA1_SHIFT                   (0U)                                                /*!< LPUART0_MATCH: MA1 Position             */
#define LPUART_MATCH_MA1(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_MATCH_MA1_SHIFT))&LPUART_MATCH_MA1_MASK) /*!< LPUART0_MATCH                           */
#define LPUART_MATCH_MA2_MASK                    (0x3FF0000U)                                        /*!< LPUART0_MATCH: MA2 Mask                 */
#define LPUART_MATCH_MA2_SHIFT                   (16U)                                               /*!< LPUART0_MATCH: MA2 Position             */
#define LPUART_MATCH_MA2(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_MATCH_MA2_SHIFT))&LPUART_MATCH_MA2_MASK) /*!< LPUART0_MATCH                           */
/**
 * @} */ /* End group LPUART_Register_Masks_GROUP 
 */

/* LPUART0 - Peripheral instance base addresses */
#define LPUART0_BasePtr                0x40054000UL //!< Peripheral base address
#define LPUART0                        ((LPUART_Type *) LPUART0_BasePtr) //!< Freescale base pointer
#define LPUART0_BASE_PTR               (LPUART0) //!< Freescale style base pointer
/**
 * @} */ /* End group LPUART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPUART_Peripheral_access_layer_GROUP LPUART Peripheral Access Layer
* @brief C Struct for LPUART
* @{
*/

/* ================================================================================ */
/* ================           LPUART1 (derived from LPUART0)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* LPUART1 - Peripheral instance base addresses */
#define LPUART1_BasePtr                0x40055000UL //!< Peripheral base address
#define LPUART1                        ((LPUART_Type *) LPUART1_BasePtr) //!< Freescale base pointer
#define LPUART1_BASE_PTR               (LPUART1) //!< Freescale style base pointer
/**
 * @} */ /* End group LPUART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer
* @brief C Struct for MCG
* @{
*/

/* ================================================================================ */
/* ================           MCG (file:MCG_LITE_MKL17Z4)          ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator Lite
 */
/**
* @addtogroup MCG_structs_GROUP MCG struct
* @brief Struct for MCG
* @{
*/
typedef struct {                                /*       MCG Structure                                                */
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
        uint8_t   RESERVED_0[4];               
   __I  uint8_t   S;                            /**< 0006: Status Register                                              */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
        uint8_t   RESERVED_2[11];              
   __I  uint8_t   HCTRIM;                       /**< 0014: High-frequency IRC Coarse Trim Register                      */
   __I  uint8_t   HTTRIM;                       /**< 0015: High-frequency IRC Tempco (Temperature Coefficient) Trim Register */
   __I  uint8_t   HFTRIM;                       /**< 0016: High-frequency IRC Fine Trim Register                        */
        uint8_t   RESERVED_3;                  
   __IO uint8_t   MC;                           /**< 0018: Miscellaneous Control Register                               */
   __I  uint8_t   LTRIMRNG;                     /**< 0019: Low-frequency IRC Trim Range Register                        */
   __I  uint8_t   LFTRIM;                       /**< 001A: Low-frequency IRC8M Trim Register                            */
   __I  uint8_t   LSTRIM;                       /**< 001B: Low-frequency IRC2M Trim Register                            */
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
#define MCG_C1_IREFSTEN_MASK                     (0x1U)                                              /*!< MCG_C1: IREFSTEN Mask                   */
#define MCG_C1_IREFSTEN_SHIFT                    (0U)                                                /*!< MCG_C1: IREFSTEN Position               */
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFSTEN_SHIFT))&MCG_C1_IREFSTEN_MASK) /*!< MCG_C1                                  */
#define MCG_C1_IRCLKEN_MASK                      (0x2U)                                              /*!< MCG_C1: IRCLKEN Mask                    */
#define MCG_C1_IRCLKEN_SHIFT                     (1U)                                                /*!< MCG_C1: IRCLKEN Position                */
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C1_IRCLKEN_SHIFT))&MCG_C1_IRCLKEN_MASK) /*!< MCG_C1                                  */
#define MCG_C1_CLKS_MASK                         (0xC0U)                                             /*!< MCG_C1: CLKS Mask                       */
#define MCG_C1_CLKS_SHIFT                        (6U)                                                /*!< MCG_C1: CLKS Position                   */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK) /*!< MCG_C1                                  */
/* ------- C2 Bit Fields                            ------ */
#define MCG_C2_IRCS_MASK                         (0x1U)                                              /*!< MCG_C2: IRCS Mask                       */
#define MCG_C2_IRCS_SHIFT                        (0U)                                                /*!< MCG_C2: IRCS Position                   */
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_IRCS_SHIFT))&MCG_C2_IRCS_MASK) /*!< MCG_C2                                  */
#define MCG_C2_EREFS0_MASK                       (0x4U)                                              /*!< MCG_C2: EREFS0 Mask                     */
#define MCG_C2_EREFS0_SHIFT                      (2U)                                                /*!< MCG_C2: EREFS0 Position                 */
#define MCG_C2_EREFS0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_EREFS0_SHIFT))&MCG_C2_EREFS0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_HGO0_MASK                         (0x8U)                                              /*!< MCG_C2: HGO0 Mask                       */
#define MCG_C2_HGO0_SHIFT                        (3U)                                                /*!< MCG_C2: HGO0 Position                   */
#define MCG_C2_HGO0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_HGO0_SHIFT))&MCG_C2_HGO0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_RANGE0_MASK                       (0x30U)                                             /*!< MCG_C2: RANGE0 Mask                     */
#define MCG_C2_RANGE0_SHIFT                      (4U)                                                /*!< MCG_C2: RANGE0 Position                 */
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK) /*!< MCG_C2                                  */
/* ------- S Bit Fields                             ------ */
#define MCG_S_OSCINIT0_MASK                      (0x2U)                                              /*!< MCG_S: OSCINIT0 Mask                    */
#define MCG_S_OSCINIT0_SHIFT                     (1U)                                                /*!< MCG_S: OSCINIT0 Position                */
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_S_OSCINIT0_SHIFT))&MCG_S_OSCINIT0_MASK) /*!< MCG_S                                   */
#define MCG_S_CLKST_MASK                         (0xCU)                                              /*!< MCG_S: CLKST Mask                       */
#define MCG_S_CLKST_SHIFT                        (2U)                                                /*!< MCG_S: CLKST Position                   */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK) /*!< MCG_S                                   */
/* ------- SC Bit Fields                            ------ */
#define MCG_SC_FCRDIV_MASK                       (0xEU)                                              /*!< MCG_SC: FCRDIV Mask                     */
#define MCG_SC_FCRDIV_SHIFT                      (1U)                                                /*!< MCG_SC: FCRDIV Position                 */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK) /*!< MCG_SC                                  */
/* ------- HCTRIM Bit Fields                        ------ */
#define MCG_HCTRIM_COARSE_TRIM_MASK              (0x3FU)                                             /*!< MCG_HCTRIM: COARSE_TRIM Mask            */
#define MCG_HCTRIM_COARSE_TRIM_SHIFT             (0U)                                                /*!< MCG_HCTRIM: COARSE_TRIM Position        */
#define MCG_HCTRIM_COARSE_TRIM(x)                (((uint8_t)(((uint8_t)(x))<<MCG_HCTRIM_COARSE_TRIM_SHIFT))&MCG_HCTRIM_COARSE_TRIM_MASK) /*!< MCG_HCTRIM                              */
/* ------- HTTRIM Bit Fields                        ------ */
#define MCG_HTTRIM_TEMPCO_TRIM_MASK              (0x1FU)                                             /*!< MCG_HTTRIM: TEMPCO_TRIM Mask            */
#define MCG_HTTRIM_TEMPCO_TRIM_SHIFT             (0U)                                                /*!< MCG_HTTRIM: TEMPCO_TRIM Position        */
#define MCG_HTTRIM_TEMPCO_TRIM(x)                (((uint8_t)(((uint8_t)(x))<<MCG_HTTRIM_TEMPCO_TRIM_SHIFT))&MCG_HTTRIM_TEMPCO_TRIM_MASK) /*!< MCG_HTTRIM                              */
/* ------- HFTRIM Bit Fields                        ------ */
#define MCG_HFTRIM_FINE_TRIM_MASK                (0x7FU)                                             /*!< MCG_HFTRIM: FINE_TRIM Mask              */
#define MCG_HFTRIM_FINE_TRIM_SHIFT               (0U)                                                /*!< MCG_HFTRIM: FINE_TRIM Position          */
#define MCG_HFTRIM_FINE_TRIM(x)                  (((uint8_t)(((uint8_t)(x))<<MCG_HFTRIM_FINE_TRIM_SHIFT))&MCG_HFTRIM_FINE_TRIM_MASK) /*!< MCG_HFTRIM                              */
/* ------- MC Bit Fields                            ------ */
#define MCG_MC_LIRC_DIV2_MASK                    (0x7U)                                              /*!< MCG_MC: LIRC_DIV2 Mask                  */
#define MCG_MC_LIRC_DIV2_SHIFT                   (0U)                                                /*!< MCG_MC: LIRC_DIV2 Position              */
#define MCG_MC_LIRC_DIV2(x)                      (((uint8_t)(((uint8_t)(x))<<MCG_MC_LIRC_DIV2_SHIFT))&MCG_MC_LIRC_DIV2_MASK) /*!< MCG_MC                                  */
#define MCG_MC_HIRCEN_MASK                       (0x80U)                                             /*!< MCG_MC: HIRCEN Mask                     */
#define MCG_MC_HIRCEN_SHIFT                      (7U)                                                /*!< MCG_MC: HIRCEN Position                 */
#define MCG_MC_HIRCEN(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_MC_HIRCEN_SHIFT))&MCG_MC_HIRCEN_MASK) /*!< MCG_MC                                  */
/* ------- LTRIMRNG Bit Fields                      ------ */
#define MCG_LTRIMRNG_STRIMRNG_MASK               (0x3U)                                              /*!< MCG_LTRIMRNG: STRIMRNG Mask             */
#define MCG_LTRIMRNG_STRIMRNG_SHIFT              (0U)                                                /*!< MCG_LTRIMRNG: STRIMRNG Position         */
#define MCG_LTRIMRNG_STRIMRNG(x)                 (((uint8_t)(((uint8_t)(x))<<MCG_LTRIMRNG_STRIMRNG_SHIFT))&MCG_LTRIMRNG_STRIMRNG_MASK) /*!< MCG_LTRIMRNG                            */
#define MCG_LTRIMRNG_FTRIMRNG_MASK               (0xCU)                                              /*!< MCG_LTRIMRNG: FTRIMRNG Mask             */
#define MCG_LTRIMRNG_FTRIMRNG_SHIFT              (2U)                                                /*!< MCG_LTRIMRNG: FTRIMRNG Position         */
#define MCG_LTRIMRNG_FTRIMRNG(x)                 (((uint8_t)(((uint8_t)(x))<<MCG_LTRIMRNG_FTRIMRNG_SHIFT))&MCG_LTRIMRNG_FTRIMRNG_MASK) /*!< MCG_LTRIMRNG                            */
/* ------- LFTRIM Bit Fields                        ------ */
#define MCG_LFTRIM_LIRC_FTRIM_MASK               (0x7FU)                                             /*!< MCG_LFTRIM: LIRC_FTRIM Mask             */
#define MCG_LFTRIM_LIRC_FTRIM_SHIFT              (0U)                                                /*!< MCG_LFTRIM: LIRC_FTRIM Position         */
#define MCG_LFTRIM_LIRC_FTRIM(x)                 (((uint8_t)(((uint8_t)(x))<<MCG_LFTRIM_LIRC_FTRIM_SHIFT))&MCG_LFTRIM_LIRC_FTRIM_MASK) /*!< MCG_LFTRIM                              */
/* ------- LSTRIM Bit Fields                        ------ */
#define MCG_LSTRIM_LIRC_STRIM_MASK               (0x7FU)                                             /*!< MCG_LSTRIM: LIRC_STRIM Mask             */
#define MCG_LSTRIM_LIRC_STRIM_SHIFT              (0U)                                                /*!< MCG_LSTRIM: LIRC_STRIM Position         */
#define MCG_LSTRIM_LIRC_STRIM(x)                 (((uint8_t)(((uint8_t)(x))<<MCG_LSTRIM_LIRC_STRIM_SHIFT))&MCG_LSTRIM_LIRC_STRIM_MASK) /*!< MCG_LSTRIM                              */
/**
 * @} */ /* End group MCG_Register_Masks_GROUP 
 */

/* MCG - Peripheral instance base addresses */
#define MCG_BasePtr                    0x40064000UL //!< Peripheral base address
#define MCG                            ((MCG_Type *) MCG_BasePtr) //!< Freescale base pointer
#define MCG_BASE_PTR                   (MCG) //!< Freescale style base pointer
/**
 * @} */ /* End group MCG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCM_Peripheral_access_layer_GROUP MCM Peripheral Access Layer
* @brief C Struct for MCM
* @{
*/

/* ================================================================================ */
/* ================           MCM (file:MCM_MKL02Z4)               ================ */
/* ================================================================================ */

/**
 * @brief Core Platform Miscellaneous Control Module
 */
/**
* @addtogroup MCM_structs_GROUP MCM struct
* @brief Struct for MCM
* @{
*/
typedef struct {                                /*       MCM Structure                                                */
        uint8_t   RESERVED_0[8];               
   __I  uint16_t  PLASC;                        /**< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /**< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  PLACR;                        /**< 000C: Platform Control Register                                    */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  CPO;                          /**< 0040: Compute Operation Control Register                           */
} MCM_Type;

/**
 * @} */ /* End group MCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCM_Register_Masks_GROUP MCM Register Masks
* @brief Register Masks for MCM
* @{
*/
/* ------- PLASC Bit Fields                         ------ */
#define MCM_PLASC_ASC_MASK                       (0xFFU)                                             /*!< MCM_PLASC: ASC Mask                     */
#define MCM_PLASC_ASC_SHIFT                      (0U)                                                /*!< MCM_PLASC: ASC Position                 */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK) /*!< MCM_PLASC                               */
/* ------- PLAMC Bit Fields                         ------ */
#define MCM_PLAMC_AMC_MASK                       (0xFFU)                                             /*!< MCM_PLAMC: AMC Mask                     */
#define MCM_PLAMC_AMC_SHIFT                      (0U)                                                /*!< MCM_PLAMC: AMC Position                 */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK) /*!< MCM_PLAMC                               */
/* ------- PLACR Bit Fields                         ------ */
#define MCM_PLACR_ARB_MASK                       (0x200U)                                            /*!< MCM_PLACR: ARB Mask                     */
#define MCM_PLACR_ARB_SHIFT                      (9U)                                                /*!< MCM_PLACR: ARB Position                 */
#define MCM_PLACR_ARB(x)                         (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_ARB_SHIFT))&MCM_PLACR_ARB_MASK) /*!< MCM_PLACR                               */
#define MCM_PLACR_CFCC_MASK                      (0x400U)                                            /*!< MCM_PLACR: CFCC Mask                    */
#define MCM_PLACR_CFCC_SHIFT                     (10U)                                               /*!< MCM_PLACR: CFCC Position                */
#define MCM_PLACR_CFCC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_CFCC_SHIFT))&MCM_PLACR_CFCC_MASK) /*!< MCM_PLACR                               */
#define MCM_PLACR_DFCDA_MASK                     (0x800U)                                            /*!< MCM_PLACR: DFCDA Mask                   */
#define MCM_PLACR_DFCDA_SHIFT                    (11U)                                               /*!< MCM_PLACR: DFCDA Position               */
#define MCM_PLACR_DFCDA(x)                       (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCDA_SHIFT))&MCM_PLACR_DFCDA_MASK) /*!< MCM_PLACR                               */
#define MCM_PLACR_DFCIC_MASK                     (0x1000U)                                           /*!< MCM_PLACR: DFCIC Mask                   */
#define MCM_PLACR_DFCIC_SHIFT                    (12U)                                               /*!< MCM_PLACR: DFCIC Position               */
#define MCM_PLACR_DFCIC(x)                       (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCIC_SHIFT))&MCM_PLACR_DFCIC_MASK) /*!< MCM_PLACR                               */
#define MCM_PLACR_DFCC_MASK                      (0x2000U)                                           /*!< MCM_PLACR: DFCC Mask                    */
#define MCM_PLACR_DFCC_SHIFT                     (13U)                                               /*!< MCM_PLACR: DFCC Position                */
#define MCM_PLACR_DFCC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCC_SHIFT))&MCM_PLACR_DFCC_MASK) /*!< MCM_PLACR                               */
#define MCM_PLACR_EFDS_MASK                      (0x4000U)                                           /*!< MCM_PLACR: EFDS Mask                    */
#define MCM_PLACR_EFDS_SHIFT                     (14U)                                               /*!< MCM_PLACR: EFDS Position                */
#define MCM_PLACR_EFDS(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_EFDS_SHIFT))&MCM_PLACR_EFDS_MASK) /*!< MCM_PLACR                               */
#define MCM_PLACR_DFCS_MASK                      (0x8000U)                                           /*!< MCM_PLACR: DFCS Mask                    */
#define MCM_PLACR_DFCS_SHIFT                     (15U)                                               /*!< MCM_PLACR: DFCS Position                */
#define MCM_PLACR_DFCS(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCS_SHIFT))&MCM_PLACR_DFCS_MASK) /*!< MCM_PLACR                               */
#define MCM_PLACR_ESFC_MASK                      (0x10000U)                                          /*!< MCM_PLACR: ESFC Mask                    */
#define MCM_PLACR_ESFC_SHIFT                     (16U)                                               /*!< MCM_PLACR: ESFC Position                */
#define MCM_PLACR_ESFC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_ESFC_SHIFT))&MCM_PLACR_ESFC_MASK) /*!< MCM_PLACR                               */
/* ------- CPO Bit Fields                           ------ */
#define MCM_CPO_CPOREQ_MASK                      (0x1U)                                              /*!< MCM_CPO: CPOREQ Mask                    */
#define MCM_CPO_CPOREQ_SHIFT                     (0U)                                                /*!< MCM_CPO: CPOREQ Position                */
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOREQ_SHIFT))&MCM_CPO_CPOREQ_MASK) /*!< MCM_CPO                                 */
#define MCM_CPO_CPOACK_MASK                      (0x2U)                                              /*!< MCM_CPO: CPOACK Mask                    */
#define MCM_CPO_CPOACK_SHIFT                     (1U)                                                /*!< MCM_CPO: CPOACK Position                */
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOACK_SHIFT))&MCM_CPO_CPOACK_MASK) /*!< MCM_CPO                                 */
#define MCM_CPO_CPOWOI_MASK                      (0x4U)                                              /*!< MCM_CPO: CPOWOI Mask                    */
#define MCM_CPO_CPOWOI_SHIFT                     (2U)                                                /*!< MCM_CPO: CPOWOI Position                */
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOWOI_SHIFT))&MCM_CPO_CPOWOI_MASK) /*!< MCM_CPO                                 */
/**
 * @} */ /* End group MCM_Register_Masks_GROUP 
 */

/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xF0003000UL //!< Peripheral base address
#define MCM                            ((MCM_Type *) MCM_BasePtr) //!< Freescale base pointer
#define MCM_BASE_PTR                   (MCM) //!< Freescale style base pointer
/**
 * @} */ /* End group MCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MTB_Peripheral_access_layer_GROUP MTB Peripheral Access Layer
* @brief C Struct for MTB
* @{
*/

/* ================================================================================ */
/* ================           MTB (file:MTB)                       ================ */
/* ================================================================================ */

/**
 * @brief Micro Trace Buffer
 */
/**
* @addtogroup MTB_structs_GROUP MTB struct
* @brief Struct for MTB
* @{
*/
typedef struct {                                /*       MTB Structure                                                */
   __IO uint32_t  POSITION;                     /**< 0000: MTB Position Register                                        */
   __IO uint32_t  MASTER;                       /**< 0004: MTB Master Register                                          */
   __IO uint32_t  FLOW;                         /**< 0008: MTB Flow Register                                            */
   __I  uint32_t  BASE;                         /**< 000C: MTB Base Register                                            */
        uint8_t   RESERVED_0[3824];            
   __I  uint32_t  MODECTRL;                     /**< 0F00: Integration Mode Control Register                            */
        uint8_t   RESERVED_1[156];             
   __I  uint32_t  TAGSET;                       /**< 0FA0: Claim TAG Set Register                                       */
   __I  uint32_t  TAGCLEAR;                     /**< 0FA4: Claim TAG Clear Register                                     */
        uint8_t   RESERVED_2[8];               
   __I  uint32_t  LOCKACCESS;                   /**< 0FB0: Lock Access Register                                         */
   __I  uint32_t  LOCKSTAT;                     /**< 0FB4: Lock Status Register                                         */
   __I  uint32_t  AUTHSTAT;                     /**< 0FB8: Authentication Status Register                               */
   __I  uint32_t  DEVICEARCH;                   /**< 0FBC: Device Architecture Register                                 */
        uint8_t   RESERVED_3[8];               
   __I  uint32_t  DEVICECFG;                    /**< 0FC8: Device Configuration Register                                */
   __I  uint32_t  DEVICETYPID;                  /**< 0FCC: Device Type Identifier Register                              */
   __I  uint32_t  PERIPHID4;                    /**< 0FD0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID5;                    /**< 0FD4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID6;                    /**< 0FD8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID7;                    /**< 0FDC: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID0;                    /**< 0FE0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID1;                    /**< 0FE4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID2;                    /**< 0FE8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID3;                    /**< 0FEC: Peripheral ID Register                                       */
   __I  uint32_t  COMPID[4];                    /**< 0FF0: Component ID Register                                        */
} MTB_Type;

/**
 * @} */ /* End group MTB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTB' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MTB_Register_Masks_GROUP MTB Register Masks
* @brief Register Masks for MTB
* @{
*/
/* ------- POSITION Bit Fields                      ------ */
#define MTB_POSITION_WRAP_MASK                   (0x4U)                                              /*!< MTB_POSITION: WRAP Mask                 */
#define MTB_POSITION_WRAP_SHIFT                  (2U)                                                /*!< MTB_POSITION: WRAP Position             */
#define MTB_POSITION_WRAP(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_POSITION_WRAP_SHIFT))&MTB_POSITION_WRAP_MASK) /*!< MTB_POSITION                            */
#define MTB_POSITION_POINTER_MASK                (0xFFFFFFF8U)                                       /*!< MTB_POSITION: POINTER Mask              */
#define MTB_POSITION_POINTER_SHIFT               (3U)                                                /*!< MTB_POSITION: POINTER Position          */
#define MTB_POSITION_POINTER(x)                  (((uint32_t)(((uint32_t)(x))<<MTB_POSITION_POINTER_SHIFT))&MTB_POSITION_POINTER_MASK) /*!< MTB_POSITION                            */
/* ------- MASTER Bit Fields                        ------ */
#define MTB_MASTER_MASK_MASK                     (0x1FU)                                             /*!< MTB_MASTER: MASK Mask                   */
#define MTB_MASTER_MASK_SHIFT                    (0U)                                                /*!< MTB_MASTER: MASK Position               */
#define MTB_MASTER_MASK(x)                       (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_MASK_SHIFT))&MTB_MASTER_MASK_MASK) /*!< MTB_MASTER                              */
#define MTB_MASTER_TSTARTEN_MASK                 (0x20U)                                             /*!< MTB_MASTER: TSTARTEN Mask               */
#define MTB_MASTER_TSTARTEN_SHIFT                (5U)                                                /*!< MTB_MASTER: TSTARTEN Position           */
#define MTB_MASTER_TSTARTEN(x)                   (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_TSTARTEN_SHIFT))&MTB_MASTER_TSTARTEN_MASK) /*!< MTB_MASTER                              */
#define MTB_MASTER_TSTOPEN_MASK                  (0x40U)                                             /*!< MTB_MASTER: TSTOPEN Mask                */
#define MTB_MASTER_TSTOPEN_SHIFT                 (6U)                                                /*!< MTB_MASTER: TSTOPEN Position            */
#define MTB_MASTER_TSTOPEN(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_TSTOPEN_SHIFT))&MTB_MASTER_TSTOPEN_MASK) /*!< MTB_MASTER                              */
#define MTB_MASTER_SFRWPRIV_MASK                 (0x80U)                                             /*!< MTB_MASTER: SFRWPRIV Mask               */
#define MTB_MASTER_SFRWPRIV_SHIFT                (7U)                                                /*!< MTB_MASTER: SFRWPRIV Position           */
#define MTB_MASTER_SFRWPRIV(x)                   (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_SFRWPRIV_SHIFT))&MTB_MASTER_SFRWPRIV_MASK) /*!< MTB_MASTER                              */
#define MTB_MASTER_RAMPRIV_MASK                  (0x100U)                                            /*!< MTB_MASTER: RAMPRIV Mask                */
#define MTB_MASTER_RAMPRIV_SHIFT                 (8U)                                                /*!< MTB_MASTER: RAMPRIV Position            */
#define MTB_MASTER_RAMPRIV(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_RAMPRIV_SHIFT))&MTB_MASTER_RAMPRIV_MASK) /*!< MTB_MASTER                              */
#define MTB_MASTER_HALTREQ_MASK                  (0x200U)                                            /*!< MTB_MASTER: HALTREQ Mask                */
#define MTB_MASTER_HALTREQ_SHIFT                 (9U)                                                /*!< MTB_MASTER: HALTREQ Position            */
#define MTB_MASTER_HALTREQ(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_HALTREQ_SHIFT))&MTB_MASTER_HALTREQ_MASK) /*!< MTB_MASTER                              */
#define MTB_MASTER_EN_MASK                       (0x80000000U)                                       /*!< MTB_MASTER: EN Mask                     */
#define MTB_MASTER_EN_SHIFT                      (31U)                                               /*!< MTB_MASTER: EN Position                 */
#define MTB_MASTER_EN(x)                         (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_EN_SHIFT))&MTB_MASTER_EN_MASK) /*!< MTB_MASTER                              */
/* ------- FLOW Bit Fields                          ------ */
#define MTB_FLOW_AUTOSTOP_MASK                   (0x1U)                                              /*!< MTB_FLOW: AUTOSTOP Mask                 */
#define MTB_FLOW_AUTOSTOP_SHIFT                  (0U)                                                /*!< MTB_FLOW: AUTOSTOP Position             */
#define MTB_FLOW_AUTOSTOP(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_AUTOSTOP_SHIFT))&MTB_FLOW_AUTOSTOP_MASK) /*!< MTB_FLOW                                */
#define MTB_FLOW_AUTOHALT_MASK                   (0x2U)                                              /*!< MTB_FLOW: AUTOHALT Mask                 */
#define MTB_FLOW_AUTOHALT_SHIFT                  (1U)                                                /*!< MTB_FLOW: AUTOHALT Position             */
#define MTB_FLOW_AUTOHALT(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_AUTOHALT_SHIFT))&MTB_FLOW_AUTOHALT_MASK) /*!< MTB_FLOW                                */
#define MTB_FLOW_WATERMARK_MASK                  (0xFFFFFFF8U)                                       /*!< MTB_FLOW: WATERMARK Mask                */
#define MTB_FLOW_WATERMARK_SHIFT                 (3U)                                                /*!< MTB_FLOW: WATERMARK Position            */
#define MTB_FLOW_WATERMARK(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_WATERMARK_SHIFT))&MTB_FLOW_WATERMARK_MASK) /*!< MTB_FLOW                                */
/* ------- BASE Bit Fields                          ------ */
#define MTB_BASE_BASEADDR_MASK                   (0xFFFFFFFFU)                                       /*!< MTB_BASE: BASEADDR Mask                 */
#define MTB_BASE_BASEADDR_SHIFT                  (0U)                                                /*!< MTB_BASE: BASEADDR Position             */
#define MTB_BASE_BASEADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_BASE_BASEADDR_SHIFT))&MTB_BASE_BASEADDR_MASK) /*!< MTB_BASE                                */
/* ------- MODECTRL Bit Fields                      ------ */
#define MTB_MODECTRL_MODECTRL_MASK               (0xFFFFFFFFU)                                       /*!< MTB_MODECTRL: MODECTRL Mask             */
#define MTB_MODECTRL_MODECTRL_SHIFT              (0U)                                                /*!< MTB_MODECTRL: MODECTRL Position         */
#define MTB_MODECTRL_MODECTRL(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_MODECTRL_MODECTRL_SHIFT))&MTB_MODECTRL_MODECTRL_MASK) /*!< MTB_MODECTRL                            */
/* ------- TAGSET Bit Fields                        ------ */
#define MTB_TAGSET_TAGSET_MASK                   (0xFFFFFFFFU)                                       /*!< MTB_TAGSET: TAGSET Mask                 */
#define MTB_TAGSET_TAGSET_SHIFT                  (0U)                                                /*!< MTB_TAGSET: TAGSET Position             */
#define MTB_TAGSET_TAGSET(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_TAGSET_TAGSET_SHIFT))&MTB_TAGSET_TAGSET_MASK) /*!< MTB_TAGSET                              */
/* ------- TAGCLEAR Bit Fields                      ------ */
#define MTB_TAGCLEAR_TAGCLEAR_MASK               (0xFFFFFFFFU)                                       /*!< MTB_TAGCLEAR: TAGCLEAR Mask             */
#define MTB_TAGCLEAR_TAGCLEAR_SHIFT              (0U)                                                /*!< MTB_TAGCLEAR: TAGCLEAR Position         */
#define MTB_TAGCLEAR_TAGCLEAR(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_TAGCLEAR_TAGCLEAR_SHIFT))&MTB_TAGCLEAR_TAGCLEAR_MASK) /*!< MTB_TAGCLEAR                            */
/* ------- LOCKACCESS Bit Fields                    ------ */
#define MTB_LOCKACCESS_LOCKACCESS_MASK           (0xFFFFFFFFU)                                       /*!< MTB_LOCKACCESS: LOCKACCESS Mask         */
#define MTB_LOCKACCESS_LOCKACCESS_SHIFT          (0U)                                                /*!< MTB_LOCKACCESS: LOCKACCESS Position     */
#define MTB_LOCKACCESS_LOCKACCESS(x)             (((uint32_t)(((uint32_t)(x))<<MTB_LOCKACCESS_LOCKACCESS_SHIFT))&MTB_LOCKACCESS_LOCKACCESS_MASK) /*!< MTB_LOCKACCESS                          */
/* ------- LOCKSTAT Bit Fields                      ------ */
#define MTB_LOCKSTAT_LOCKSTAT_MASK               (0xFFFFFFFFU)                                       /*!< MTB_LOCKSTAT: LOCKSTAT Mask             */
#define MTB_LOCKSTAT_LOCKSTAT_SHIFT              (0U)                                                /*!< MTB_LOCKSTAT: LOCKSTAT Position         */
#define MTB_LOCKSTAT_LOCKSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_LOCKSTAT_LOCKSTAT_SHIFT))&MTB_LOCKSTAT_LOCKSTAT_MASK) /*!< MTB_LOCKSTAT                            */
/* ------- AUTHSTAT Bit Fields                      ------ */
#define MTB_AUTHSTAT_BIT0_MASK                   (0x1U)                                              /*!< MTB_AUTHSTAT: BIT0 Mask                 */
#define MTB_AUTHSTAT_BIT0_SHIFT                  (0U)                                                /*!< MTB_AUTHSTAT: BIT0 Position             */
#define MTB_AUTHSTAT_BIT0(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT0_SHIFT))&MTB_AUTHSTAT_BIT0_MASK) /*!< MTB_AUTHSTAT                            */
#define MTB_AUTHSTAT_BIT1_MASK                   (0x2U)                                              /*!< MTB_AUTHSTAT: BIT1 Mask                 */
#define MTB_AUTHSTAT_BIT1_SHIFT                  (1U)                                                /*!< MTB_AUTHSTAT: BIT1 Position             */
#define MTB_AUTHSTAT_BIT1(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT1_SHIFT))&MTB_AUTHSTAT_BIT1_MASK) /*!< MTB_AUTHSTAT                            */
#define MTB_AUTHSTAT_BIT2_MASK                   (0x4U)                                              /*!< MTB_AUTHSTAT: BIT2 Mask                 */
#define MTB_AUTHSTAT_BIT2_SHIFT                  (2U)                                                /*!< MTB_AUTHSTAT: BIT2 Position             */
#define MTB_AUTHSTAT_BIT2(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT2_SHIFT))&MTB_AUTHSTAT_BIT2_MASK) /*!< MTB_AUTHSTAT                            */
#define MTB_AUTHSTAT_BIT3_MASK                   (0x8U)                                              /*!< MTB_AUTHSTAT: BIT3 Mask                 */
#define MTB_AUTHSTAT_BIT3_SHIFT                  (3U)                                                /*!< MTB_AUTHSTAT: BIT3 Position             */
#define MTB_AUTHSTAT_BIT3(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT3_SHIFT))&MTB_AUTHSTAT_BIT3_MASK) /*!< MTB_AUTHSTAT                            */
/* ------- DEVICEARCH Bit Fields                    ------ */
#define MTB_DEVICEARCH_DEVICEARCH_MASK           (0xFFFFFFFFU)                                       /*!< MTB_DEVICEARCH: DEVICEARCH Mask         */
#define MTB_DEVICEARCH_DEVICEARCH_SHIFT          (0U)                                                /*!< MTB_DEVICEARCH: DEVICEARCH Position     */
#define MTB_DEVICEARCH_DEVICEARCH(x)             (((uint32_t)(((uint32_t)(x))<<MTB_DEVICEARCH_DEVICEARCH_SHIFT))&MTB_DEVICEARCH_DEVICEARCH_MASK) /*!< MTB_DEVICEARCH                          */
/* ------- DEVICECFG Bit Fields                     ------ */
#define MTB_DEVICECFG_DEVICECFG_MASK             (0xFFFFFFFFU)                                       /*!< MTB_DEVICECFG: DEVICECFG Mask           */
#define MTB_DEVICECFG_DEVICECFG_SHIFT            (0U)                                                /*!< MTB_DEVICECFG: DEVICECFG Position       */
#define MTB_DEVICECFG_DEVICECFG(x)               (((uint32_t)(((uint32_t)(x))<<MTB_DEVICECFG_DEVICECFG_SHIFT))&MTB_DEVICECFG_DEVICECFG_MASK) /*!< MTB_DEVICECFG                           */
/* ------- DEVICETYPID Bit Fields                   ------ */
#define MTB_DEVICETYPID_DEVICETYPID_MASK         (0xFFFFFFFFU)                                       /*!< MTB_DEVICETYPID: DEVICETYPID Mask       */
#define MTB_DEVICETYPID_DEVICETYPID_SHIFT        (0U)                                                /*!< MTB_DEVICETYPID: DEVICETYPID Position   */
#define MTB_DEVICETYPID_DEVICETYPID(x)           (((uint32_t)(((uint32_t)(x))<<MTB_DEVICETYPID_DEVICETYPID_SHIFT))&MTB_DEVICETYPID_DEVICETYPID_MASK) /*!< MTB_DEVICETYPID                         */
/* ------- PERIPHID Bit Fields                      ------ */
#define MTB_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFU)                                       /*!< MTB_PERIPHID: PERIPHID Mask             */
#define MTB_PERIPHID_PERIPHID_SHIFT              (0U)                                                /*!< MTB_PERIPHID: PERIPHID Position         */
#define MTB_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_PERIPHID_PERIPHID_SHIFT))&MTB_PERIPHID_PERIPHID_MASK) /*!< MTB_PERIPHID                            */
/* ------- COMPID Bit Fields                        ------ */
#define MTB_COMPID_COMPID_MASK                   (0xFFFFFFFFU)                                       /*!< MTB_COMPID: COMPID Mask                 */
#define MTB_COMPID_COMPID_SHIFT                  (0U)                                                /*!< MTB_COMPID: COMPID Position             */
#define MTB_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_COMPID_COMPID_SHIFT))&MTB_COMPID_COMPID_MASK) /*!< MTB_COMPID                              */
/**
 * @} */ /* End group MTB_Register_Masks_GROUP 
 */

/* MTB - Peripheral instance base addresses */
#define MTB_BasePtr                    0xF0000000UL //!< Peripheral base address
#define MTB                            ((MTB_Type *) MTB_BasePtr) //!< Freescale base pointer
#define MTB_BASE_PTR                   (MTB) //!< Freescale style base pointer
/**
 * @} */ /* End group MTB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MTBDWT_Peripheral_access_layer_GROUP MTBDWT Peripheral Access Layer
* @brief C Struct for MTBDWT
* @{
*/

/* ================================================================================ */
/* ================           MTBDWT (file:MTBDWT_MKL)             ================ */
/* ================================================================================ */

/**
 * @brief MTB data watchpoint and trace
 */
/**
* @addtogroup MTBDWT_structs_GROUP MTBDWT struct
* @brief Struct for MTBDWT
* @{
*/
typedef struct {                                /*       MTBDWT Structure                                             */
   __I  uint32_t  CTRL;                         /**< 0000: MTB DWT Control Register                                     */
        uint8_t   RESERVED_0[28];              
   struct {
      __IO uint32_t  COMP;                      /**< 0020: MTB_DWT Comparator Register                                  */
      __IO uint32_t  MASK;                      /**< 0024: MTB_DWT Comparator Mask Register                             */
      __IO uint32_t  FCT;                       /**< 0028: MTB_DWT Comparator Function Register 0                       */
           uint8_t   RESERVED_1[4];            
   } COMPARATOR[2];                             /**< 0020: (cluster: size=0x0020, 32)                                   */
        uint8_t   RESERVED_2[448];             
   __IO uint32_t  TBCTRL;                       /**< 0200: MTB_DWT Trace Buffer Control Register                        */
        uint8_t   RESERVED_3[3524];            
   __I  uint32_t  DEVICECFG;                    /**< 0FC8: Device Configuration Register                                */
   __I  uint32_t  DEVICETYPID;                  /**< 0FCC: Device Type Identifier Register                              */
   __I  uint32_t  PERIPHID4;                    /**< 0FD0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID5;                    /**< 0FD4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID6;                    /**< 0FD8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID7;                    /**< 0FDC: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID0;                    /**< 0FE0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID1;                    /**< 0FE4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID2;                    /**< 0FE8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID3;                    /**< 0FEC: Peripheral ID Register                                       */
   __I  uint32_t  COMPID[4];                    /**< 0FF0: Component ID Register                                        */
} MTBDWT_Type;

/**
 * @} */ /* End group MTBDWT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTBDWT' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MTBDWT_Register_Masks_GROUP MTBDWT Register Masks
* @brief Register Masks for MTBDWT
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define MTBDWT_CTRL_DWTCFGCTRL_MASK              (0xFFFFFFFU)                                        /*!< MTBDWT_CTRL: DWTCFGCTRL Mask            */
#define MTBDWT_CTRL_DWTCFGCTRL_SHIFT             (0U)                                                /*!< MTBDWT_CTRL: DWTCFGCTRL Position        */
#define MTBDWT_CTRL_DWTCFGCTRL(x)                (((uint32_t)(((uint32_t)(x))<<MTBDWT_CTRL_DWTCFGCTRL_SHIFT))&MTBDWT_CTRL_DWTCFGCTRL_MASK) /*!< MTBDWT_CTRL                             */
#define MTBDWT_CTRL_NUMCMP_MASK                  (0xF0000000U)                                       /*!< MTBDWT_CTRL: NUMCMP Mask                */
#define MTBDWT_CTRL_NUMCMP_SHIFT                 (28U)                                               /*!< MTBDWT_CTRL: NUMCMP Position            */
#define MTBDWT_CTRL_NUMCMP(x)                    (((uint32_t)(((uint32_t)(x))<<MTBDWT_CTRL_NUMCMP_SHIFT))&MTBDWT_CTRL_NUMCMP_MASK) /*!< MTBDWT_CTRL                             */
/* ------- COMP Bit Fields                          ------ */
#define MTBDWT_COMP_COMP_MASK                    (0xFFFFFFFFU)                                       /*!< MTBDWT_COMP: COMP Mask                  */
#define MTBDWT_COMP_COMP_SHIFT                   (0U)                                                /*!< MTBDWT_COMP: COMP Position              */
#define MTBDWT_COMP_COMP(x)                      (((uint32_t)(((uint32_t)(x))<<MTBDWT_COMP_COMP_SHIFT))&MTBDWT_COMP_COMP_MASK) /*!< MTBDWT_COMP                             */
/* ------- MASK Bit Fields                          ------ */
#define MTBDWT_MASK_MASK_MASK                    (0x1FU)                                             /*!< MTBDWT_MASK: MASK Mask                  */
#define MTBDWT_MASK_MASK_SHIFT                   (0U)                                                /*!< MTBDWT_MASK: MASK Position              */
#define MTBDWT_MASK_MASK(x)                      (((uint32_t)(((uint32_t)(x))<<MTBDWT_MASK_MASK_SHIFT))&MTBDWT_MASK_MASK_MASK) /*!< MTBDWT_MASK                             */
/* ------- FCT Bit Fields                           ------ */
#define MTBDWT_FCT_FUNCTION_MASK                 (0xFU)                                              /*!< MTBDWT_FCT: FUNCTION Mask               */
#define MTBDWT_FCT_FUNCTION_SHIFT                (0U)                                                /*!< MTBDWT_FCT: FUNCTION Position           */
#define MTBDWT_FCT_FUNCTION(x)                   (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_FUNCTION_SHIFT))&MTBDWT_FCT_FUNCTION_MASK) /*!< MTBDWT_FCT                              */
#define MTBDWT_FCT_DATAVMATCH_MASK               (0x100U)                                            /*!< MTBDWT_FCT: DATAVMATCH Mask             */
#define MTBDWT_FCT_DATAVMATCH_SHIFT              (8U)                                                /*!< MTBDWT_FCT: DATAVMATCH Position         */
#define MTBDWT_FCT_DATAVMATCH(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVMATCH_SHIFT))&MTBDWT_FCT_DATAVMATCH_MASK) /*!< MTBDWT_FCT                              */
#define MTBDWT_FCT_DATAVSIZE_MASK                (0xC00U)                                            /*!< MTBDWT_FCT: DATAVSIZE Mask              */
#define MTBDWT_FCT_DATAVSIZE_SHIFT               (10U)                                               /*!< MTBDWT_FCT: DATAVSIZE Position          */
#define MTBDWT_FCT_DATAVSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVSIZE_SHIFT))&MTBDWT_FCT_DATAVSIZE_MASK) /*!< MTBDWT_FCT                              */
#define MTBDWT_FCT_DATAVADDR0_MASK               (0xF000U)                                           /*!< MTBDWT_FCT: DATAVADDR0 Mask             */
#define MTBDWT_FCT_DATAVADDR0_SHIFT              (12U)                                               /*!< MTBDWT_FCT: DATAVADDR0 Position         */
#define MTBDWT_FCT_DATAVADDR0(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVADDR0_SHIFT))&MTBDWT_FCT_DATAVADDR0_MASK) /*!< MTBDWT_FCT                              */
#define MTBDWT_FCT_MATCHED_MASK                  (0x1000000U)                                        /*!< MTBDWT_FCT: MATCHED Mask                */
#define MTBDWT_FCT_MATCHED_SHIFT                 (24U)                                               /*!< MTBDWT_FCT: MATCHED Position            */
#define MTBDWT_FCT_MATCHED(x)                    (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_MATCHED_SHIFT))&MTBDWT_FCT_MATCHED_MASK) /*!< MTBDWT_FCT                              */
/* ------- TBCTRL Bit Fields                        ------ */
#define MTBDWT_TBCTRL_ACOMP0_MASK                (0x1U)                                              /*!< MTBDWT_TBCTRL: ACOMP0 Mask              */
#define MTBDWT_TBCTRL_ACOMP0_SHIFT               (0U)                                                /*!< MTBDWT_TBCTRL: ACOMP0 Position          */
#define MTBDWT_TBCTRL_ACOMP0(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_TBCTRL_ACOMP0_SHIFT))&MTBDWT_TBCTRL_ACOMP0_MASK) /*!< MTBDWT_TBCTRL                           */
#define MTBDWT_TBCTRL_ACOMP1_MASK                (0x2U)                                              /*!< MTBDWT_TBCTRL: ACOMP1 Mask              */
#define MTBDWT_TBCTRL_ACOMP1_SHIFT               (1U)                                                /*!< MTBDWT_TBCTRL: ACOMP1 Position          */
#define MTBDWT_TBCTRL_ACOMP1(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_TBCTRL_ACOMP1_SHIFT))&MTBDWT_TBCTRL_ACOMP1_MASK) /*!< MTBDWT_TBCTRL                           */
#define MTBDWT_TBCTRL_NUMCOMP_MASK               (0xF0000000U)                                       /*!< MTBDWT_TBCTRL: NUMCOMP Mask             */
#define MTBDWT_TBCTRL_NUMCOMP_SHIFT              (28U)                                               /*!< MTBDWT_TBCTRL: NUMCOMP Position         */
#define MTBDWT_TBCTRL_NUMCOMP(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_TBCTRL_NUMCOMP_SHIFT))&MTBDWT_TBCTRL_NUMCOMP_MASK) /*!< MTBDWT_TBCTRL                           */
/* ------- DEVICECFG Bit Fields                     ------ */
#define MTBDWT_DEVICECFG_DEVICECFG_MASK          (0xFFFFFFFFU)                                       /*!< MTBDWT_DEVICECFG: DEVICECFG Mask        */
#define MTBDWT_DEVICECFG_DEVICECFG_SHIFT         (0U)                                                /*!< MTBDWT_DEVICECFG: DEVICECFG Position    */
#define MTBDWT_DEVICECFG_DEVICECFG(x)            (((uint32_t)(((uint32_t)(x))<<MTBDWT_DEVICECFG_DEVICECFG_SHIFT))&MTBDWT_DEVICECFG_DEVICECFG_MASK) /*!< MTBDWT_DEVICECFG                        */
/* ------- DEVICETYPID Bit Fields                   ------ */
#define MTBDWT_DEVICETYPID_DEVICETYPID_MASK      (0xFFFFFFFFU)                                       /*!< MTBDWT_DEVICETYPID: DEVICETYPID Mask    */
#define MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT     (0U)                                                /*!< MTBDWT_DEVICETYPID: DEVICETYPID Position*/
#define MTBDWT_DEVICETYPID_DEVICETYPID(x)        (((uint32_t)(((uint32_t)(x))<<MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT))&MTBDWT_DEVICETYPID_DEVICETYPID_MASK) /*!< MTBDWT_DEVICETYPID                      */
/* ------- PERIPHID Bit Fields                      ------ */
#define MTBDWT_PERIPHID_PERIPHID_MASK            (0xFFFFFFFFU)                                       /*!< MTBDWT_PERIPHID: PERIPHID Mask          */
#define MTBDWT_PERIPHID_PERIPHID_SHIFT           (0U)                                                /*!< MTBDWT_PERIPHID: PERIPHID Position      */
#define MTBDWT_PERIPHID_PERIPHID(x)              (((uint32_t)(((uint32_t)(x))<<MTBDWT_PERIPHID_PERIPHID_SHIFT))&MTBDWT_PERIPHID_PERIPHID_MASK) /*!< MTBDWT_PERIPHID                         */
/* ------- COMPID Bit Fields                        ------ */
#define MTBDWT_COMPID_COMPID_MASK                (0xFFFFFFFFU)                                       /*!< MTBDWT_COMPID: COMPID Mask              */
#define MTBDWT_COMPID_COMPID_SHIFT               (0U)                                                /*!< MTBDWT_COMPID: COMPID Position          */
#define MTBDWT_COMPID_COMPID(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_COMPID_COMPID_SHIFT))&MTBDWT_COMPID_COMPID_MASK) /*!< MTBDWT_COMPID                           */
/**
 * @} */ /* End group MTBDWT_Register_Masks_GROUP 
 */

/* MTBDWT - Peripheral instance base addresses */
#define MTBDWT_BasePtr                 0xF0001000UL //!< Peripheral base address
#define MTBDWT                         ((MTBDWT_Type *) MTBDWT_BasePtr) //!< Freescale base pointer
#define MTBDWT_BASE_PTR                (MTBDWT) //!< Freescale style base pointer
/**
 * @} */ /* End group MTBDWT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer
* @brief C Struct for NV
* @{
*/

/* ================================================================================ */
/* ================           NV (file:NV_MKL5)                    ================ */
/* ================================================================================ */

/**
 * @brief Flash configuration field
 */
/**
* @addtogroup NV_structs_GROUP NV struct
* @brief Struct for NV
* @{
*/
typedef struct {                                /*       NV Structure                                                 */
   __I  uint8_t   BACKKEY3;                     /**< 0000: Backdoor Comparison Key 3                                    */
   __I  uint8_t   BACKKEY2;                     /**< 0001: Backdoor Comparison Key 2                                    */
   __I  uint8_t   BACKKEY1;                     /**< 0002: Backdoor Comparison Key 1                                    */
   __I  uint8_t   BACKKEY0;                     /**< 0003: Backdoor Comparison Key 0                                    */
   __I  uint8_t   BACKKEY7;                     /**< 0004: Backdoor Comparison Key 7                                    */
   __I  uint8_t   BACKKEY6;                     /**< 0005: Backdoor Comparison Key 6                                    */
   __I  uint8_t   BACKKEY5;                     /**< 0006: Backdoor Comparison Key 5                                    */
   __I  uint8_t   BACKKEY4;                     /**< 0007: Backdoor Comparison Key 4                                    */
   __I  uint8_t   FPROT3;                       /**< 0008: Non-volatile P-Flash Protection 1 - Low Register             */
   __I  uint8_t   FPROT2;                       /**< 0009: Non-volatile P-Flash Protection 1 - High Register            */
   __I  uint8_t   FPROT1;                       /**< 000A: Non-volatile P-Flash Protection 0 - Low Register             */
   __I  uint8_t   FPROT0;                       /**< 000B: Non-volatile P-Flash Protection 0 - High Register            */
   __I  uint8_t   FSEC;                         /**< 000C: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /**< 000D: Non-volatile Flash Option Register                           */
} NV_Type;

/**
 * @} */ /* End group NV_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'NV' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup NV_Register_Masks_GROUP NV Register Masks
* @brief Register Masks for NV
* @{
*/
/* ------- BACKKEY Bit Fields                       ------ */
#define NV_BACKKEY_KEY_MASK                      (0xFFU)                                             /*!< NV_BACKKEY: KEY Mask                    */
#define NV_BACKKEY_KEY_SHIFT                     (0U)                                                /*!< NV_BACKKEY: KEY Position                */
#define NV_BACKKEY_KEY(x)                        (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY_KEY_SHIFT))&NV_BACKKEY_KEY_MASK) /*!< NV_BACKKEY                              */
/* ------- FPROT3 Bit Fields                        ------ */
#define NV_FPROT3_PROT_MASK                      (0xFFU)                                             /*!< NV_FPROT3: PROT Mask                    */
#define NV_FPROT3_PROT_SHIFT                     (0U)                                                /*!< NV_FPROT3: PROT Position                */
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT3_PROT_SHIFT))&NV_FPROT3_PROT_MASK) /*!< NV_FPROT3                               */
/* ------- FPROT2 Bit Fields                        ------ */
#define NV_FPROT2_PROT_MASK                      (0xFFU)                                             /*!< NV_FPROT2: PROT Mask                    */
#define NV_FPROT2_PROT_SHIFT                     (0U)                                                /*!< NV_FPROT2: PROT Position                */
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT2_PROT_SHIFT))&NV_FPROT2_PROT_MASK) /*!< NV_FPROT2                               */
/* ------- FPROT1 Bit Fields                        ------ */
#define NV_FPROT1_PROT_MASK                      (0xFFU)                                             /*!< NV_FPROT1: PROT Mask                    */
#define NV_FPROT1_PROT_SHIFT                     (0U)                                                /*!< NV_FPROT1: PROT Position                */
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT1_PROT_SHIFT))&NV_FPROT1_PROT_MASK) /*!< NV_FPROT1                               */
/* ------- FPROT0 Bit Fields                        ------ */
#define NV_FPROT0_PROT_MASK                      (0xFFU)                                             /*!< NV_FPROT0: PROT Mask                    */
#define NV_FPROT0_PROT_SHIFT                     (0U)                                                /*!< NV_FPROT0: PROT Position                */
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK) /*!< NV_FPROT0                               */
/* ------- FSEC Bit Fields                          ------ */
#define NV_FSEC_SEC_MASK                         (0x3U)                                              /*!< NV_FSEC: SEC Mask                       */
#define NV_FSEC_SEC_SHIFT                        (0U)                                                /*!< NV_FSEC: SEC Position                   */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_FSLACC_MASK                      (0xCU)                                              /*!< NV_FSEC: FSLACC Mask                    */
#define NV_FSEC_FSLACC_SHIFT                     (2U)                                                /*!< NV_FSEC: FSLACC Position                */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_MEEN_MASK                        (0x30U)                                             /*!< NV_FSEC: MEEN Mask                      */
#define NV_FSEC_MEEN_SHIFT                       (4U)                                                /*!< NV_FSEC: MEEN Position                  */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_KEYEN_MASK                       (0xC0U)                                             /*!< NV_FSEC: KEYEN Mask                     */
#define NV_FSEC_KEYEN_SHIFT                      (6U)                                                /*!< NV_FSEC: KEYEN Position                 */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK) /*!< NV_FSEC                                 */
/* ------- FOPT Bit Fields                          ------ */
#define NV_FOPT_LPBOOT0_MASK                     (0x1U)                                              /*!< NV_FOPT: LPBOOT0 Mask                   */
#define NV_FOPT_LPBOOT0_SHIFT                    (0U)                                                /*!< NV_FOPT: LPBOOT0 Position               */
#define NV_FOPT_LPBOOT0(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_LPBOOT0_SHIFT))&NV_FOPT_LPBOOT0_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_BOOTPIN_OPT_MASK                 (0x2U)                                              /*!< NV_FOPT: BOOTPIN_OPT Mask               */
#define NV_FOPT_BOOTPIN_OPT_SHIFT                (1U)                                                /*!< NV_FOPT: BOOTPIN_OPT Position           */
#define NV_FOPT_BOOTPIN_OPT(x)                   (((uint8_t)(((uint8_t)(x))<<NV_FOPT_BOOTPIN_OPT_SHIFT))&NV_FOPT_BOOTPIN_OPT_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_NMI_DIS_MASK                     (0x4U)                                              /*!< NV_FOPT: NMI_DIS Mask                   */
#define NV_FOPT_NMI_DIS_SHIFT                    (2U)                                                /*!< NV_FOPT: NMI_DIS Position               */
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_NMI_DIS_SHIFT))&NV_FOPT_NMI_DIS_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_RESET_PIN_CFG_MASK               (0x8U)                                              /*!< NV_FOPT: RESET_PIN_CFG Mask             */
#define NV_FOPT_RESET_PIN_CFG_SHIFT              (3U)                                                /*!< NV_FOPT: RESET_PIN_CFG Position         */
#define NV_FOPT_RESET_PIN_CFG(x)                 (((uint8_t)(((uint8_t)(x))<<NV_FOPT_RESET_PIN_CFG_SHIFT))&NV_FOPT_RESET_PIN_CFG_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_LPBOOT1_MASK                     (0x10U)                                             /*!< NV_FOPT: LPBOOT1 Mask                   */
#define NV_FOPT_LPBOOT1_SHIFT                    (4U)                                                /*!< NV_FOPT: LPBOOT1 Position               */
#define NV_FOPT_LPBOOT1(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_LPBOOT1_SHIFT))&NV_FOPT_LPBOOT1_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_FAST_INIT_MASK                   (0x20U)                                             /*!< NV_FOPT: FAST_INIT Mask                 */
#define NV_FOPT_FAST_INIT_SHIFT                  (5U)                                                /*!< NV_FOPT: FAST_INIT Position             */
#define NV_FOPT_FAST_INIT(x)                     (((uint8_t)(((uint8_t)(x))<<NV_FOPT_FAST_INIT_SHIFT))&NV_FOPT_FAST_INIT_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_BOOTSRC_SEL_MASK                 (0xC0U)                                             /*!< NV_FOPT: BOOTSRC_SEL Mask               */
#define NV_FOPT_BOOTSRC_SEL_SHIFT                (6U)                                                /*!< NV_FOPT: BOOTSRC_SEL Position           */
#define NV_FOPT_BOOTSRC_SEL(x)                   (((uint8_t)(((uint8_t)(x))<<NV_FOPT_BOOTSRC_SEL_SHIFT))&NV_FOPT_BOOTSRC_SEL_MASK) /*!< NV_FOPT                                 */
/**
 * @} */ /* End group NV_Register_Masks_GROUP 
 */

/* NV - Peripheral instance base addresses */
#define NV_BasePtr                     0x00000400UL //!< Peripheral base address
#define NV                             ((NV_Type *) NV_BasePtr) //!< Freescale base pointer
#define NV_BASE_PTR                    (NV) //!< Freescale style base pointer
/**
 * @} */ /* End group NV_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup OSC_Peripheral_access_layer_GROUP OSC Peripheral Access Layer
* @brief C Struct for OSC
* @{
*/

/* ================================================================================ */
/* ================           OSC0 (file:OSC0_MK)                  ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */
/**
* @addtogroup OSC_structs_GROUP OSC struct
* @brief Struct for OSC
* @{
*/
typedef struct {                                /*       OSC0 Structure                                               */
   __IO uint8_t   CR;                           /**< 0000: Control Register                                             */
} OSC_Type;

/**
 * @} */ /* End group OSC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup OSC_Register_Masks_GROUP OSC Register Masks
* @brief Register Masks for OSC
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define OSC_CR_SCP_MASK                          (0xFU)                                              /*!< OSC0_CR: SCP Mask                       */
#define OSC_CR_SCP_SHIFT                         (0U)                                                /*!< OSC0_CR: SCP Position                   */
#define OSC_CR_SCP(x)                            (((uint8_t)(((uint8_t)(x))<<OSC_CR_SCP_SHIFT))&OSC_CR_SCP_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC16P_MASK                        (0x1U)                                              /*!< OSC0_CR: SC16P Mask                     */
#define OSC_CR_SC16P_SHIFT                       (0U)                                                /*!< OSC0_CR: SC16P Position                 */
#define OSC_CR_SC16P(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC16P_SHIFT))&OSC_CR_SC16P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC8P_MASK                         (0x2U)                                              /*!< OSC0_CR: SC8P Mask                      */
#define OSC_CR_SC8P_SHIFT                        (1U)                                                /*!< OSC0_CR: SC8P Position                  */
#define OSC_CR_SC8P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC8P_SHIFT))&OSC_CR_SC8P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC4P_MASK                         (0x4U)                                              /*!< OSC0_CR: SC4P Mask                      */
#define OSC_CR_SC4P_SHIFT                        (2U)                                                /*!< OSC0_CR: SC4P Position                  */
#define OSC_CR_SC4P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC4P_SHIFT))&OSC_CR_SC4P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC2P_MASK                         (0x8U)                                              /*!< OSC0_CR: SC2P Mask                      */
#define OSC_CR_SC2P_SHIFT                        (3U)                                                /*!< OSC0_CR: SC2P Position                  */
#define OSC_CR_SC2P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC2P_SHIFT))&OSC_CR_SC2P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_EREFSTEN_MASK                     (0x20U)                                             /*!< OSC0_CR: EREFSTEN Mask                  */
#define OSC_CR_EREFSTEN_SHIFT                    (5U)                                                /*!< OSC0_CR: EREFSTEN Position              */
#define OSC_CR_EREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<OSC_CR_EREFSTEN_SHIFT))&OSC_CR_EREFSTEN_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_ERCLKEN_MASK                      (0x80U)                                             /*!< OSC0_CR: ERCLKEN Mask                   */
#define OSC_CR_ERCLKEN_SHIFT                     (7U)                                                /*!< OSC0_CR: ERCLKEN Position               */
#define OSC_CR_ERCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<OSC_CR_ERCLKEN_SHIFT))&OSC_CR_ERCLKEN_MASK) /*!< OSC0_CR                                 */
/**
 * @} */ /* End group OSC_Register_Masks_GROUP 
 */

/* OSC0 - Peripheral instance base addresses */
#define OSC0_BasePtr                   0x40065000UL //!< Peripheral base address
#define OSC0                           ((OSC_Type *) OSC0_BasePtr) //!< Freescale base pointer
#define OSC0_BASE_PTR                  (OSC0) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT (file:PIT_2CH_CHAIN_LTMR)        ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer (2 channels)
 */
/**
* @addtogroup PIT_structs_GROUP PIT struct
* @brief Struct for PIT
* @{
*/
typedef struct {                                /*       PIT Structure                                                */
   __IO uint32_t  MCR;                          /**< 0000: Module Control Register                                      */
        uint8_t   RESERVED_0[220];             
   __I  uint32_t  LTMR64H;                      /**< 00E0: Upper Lifetime Timer Register                                */
   __I  uint32_t  LTMR64L;                      /**< 00E4: Lower Lifetime Timer Register                                */
        uint8_t   RESERVED_1[24];              
   struct {
      __IO uint32_t  LDVAL;                     /**< 0100: Timer Load Value Register                                    */
      __I  uint32_t  CVAL;                      /**< 0104: Current Timer Value Register                                 */
      __IO uint32_t  TCTRL;                     /**< 0108: Timer Control Register                                       */
      __IO uint32_t  TFLG;                      /**< 010C: Timer Flag Register                                          */
   } CHANNEL[2];                                /**< 0100: (cluster: size=0x0020, 32)                                   */
} PIT_Type;

/**
 * @} */ /* End group PIT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PIT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PIT_Register_Masks_GROUP PIT Register Masks
* @brief Register Masks for PIT
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define PIT_MCR_FRZ_MASK                         (0x1U)                                              /*!< PIT_MCR: FRZ Mask                       */
#define PIT_MCR_FRZ_SHIFT                        (0U)                                                /*!< PIT_MCR: FRZ Position                   */
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<PIT_MCR_FRZ_SHIFT))&PIT_MCR_FRZ_MASK) /*!< PIT_MCR                                 */
#define PIT_MCR_MDIS_MASK                        (0x2U)                                              /*!< PIT_MCR: MDIS Mask                      */
#define PIT_MCR_MDIS_SHIFT                       (1U)                                                /*!< PIT_MCR: MDIS Position                  */
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_MCR_MDIS_SHIFT))&PIT_MCR_MDIS_MASK) /*!< PIT_MCR                                 */
/* ------- LTMR64H Bit Fields                       ------ */
#define PIT_LTMR64H_LTH_MASK                     (0xFFFFFFFFU)                                       /*!< PIT_LTMR64H: LTH Mask                   */
#define PIT_LTMR64H_LTH_SHIFT                    (0U)                                                /*!< PIT_LTMR64H: LTH Position               */
#define PIT_LTMR64H_LTH(x)                       (((uint32_t)(((uint32_t)(x))<<PIT_LTMR64H_LTH_SHIFT))&PIT_LTMR64H_LTH_MASK) /*!< PIT_LTMR64H                             */
/* ------- LTMR64L Bit Fields                       ------ */
#define PIT_LTMR64L_LTL_MASK                     (0xFFFFFFFFU)                                       /*!< PIT_LTMR64L: LTL Mask                   */
#define PIT_LTMR64L_LTL_SHIFT                    (0U)                                                /*!< PIT_LTMR64L: LTL Position               */
#define PIT_LTMR64L_LTL(x)                       (((uint32_t)(((uint32_t)(x))<<PIT_LTMR64L_LTL_SHIFT))&PIT_LTMR64L_LTL_MASK) /*!< PIT_LTMR64L                             */
/* ------- LDVAL Bit Fields                         ------ */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)                                       /*!< PIT_LDVAL: TSV Mask                     */
#define PIT_LDVAL_TSV_SHIFT                      (0U)                                                /*!< PIT_LDVAL: TSV Position                 */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK) /*!< PIT_LDVAL                               */
/* ------- CVAL Bit Fields                          ------ */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)                                       /*!< PIT_CVAL: TVL Mask                      */
#define PIT_CVAL_TVL_SHIFT                       (0U)                                                /*!< PIT_CVAL: TVL Position                  */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK) /*!< PIT_CVAL                                */
/* ------- TCTRL Bit Fields                         ------ */
#define PIT_TCTRL_TEN_MASK                       (0x1U)                                              /*!< PIT_TCTRL: TEN Mask                     */
#define PIT_TCTRL_TEN_SHIFT                      (0U)                                                /*!< PIT_TCTRL: TEN Position                 */
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TEN_SHIFT))&PIT_TCTRL_TEN_MASK) /*!< PIT_TCTRL                               */
#define PIT_TCTRL_TIE_MASK                       (0x2U)                                              /*!< PIT_TCTRL: TIE Mask                     */
#define PIT_TCTRL_TIE_SHIFT                      (1U)                                                /*!< PIT_TCTRL: TIE Position                 */
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TIE_SHIFT))&PIT_TCTRL_TIE_MASK) /*!< PIT_TCTRL                               */
#define PIT_TCTRL_CHN_MASK                       (0x4U)                                              /*!< PIT_TCTRL: CHN Mask                     */
#define PIT_TCTRL_CHN_SHIFT                      (2U)                                                /*!< PIT_TCTRL: CHN Position                 */
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_CHN_SHIFT))&PIT_TCTRL_CHN_MASK) /*!< PIT_TCTRL                               */
/* ------- TFLG Bit Fields                          ------ */
#define PIT_TFLG_TIF_MASK                        (0x1U)                                              /*!< PIT_TFLG: TIF Mask                      */
#define PIT_TFLG_TIF_SHIFT                       (0U)                                                /*!< PIT_TFLG: TIF Position                  */
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_TFLG_TIF_SHIFT))&PIT_TFLG_TIF_MASK) /*!< PIT_TFLG                                */
/**
 * @} */ /* End group PIT_Register_Masks_GROUP 
 */

/* PIT - Peripheral instance base addresses */
#define PIT_BasePtr                    0x40037000UL //!< Peripheral base address
#define PIT                            ((PIT_Type *) PIT_BasePtr) //!< Freescale base pointer
#define PIT_BASE_PTR                   (PIT) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer
* @brief C Struct for PMC
* @{
*/

/* ================================================================================ */
/* ================           PMC (file:PMC_MK)                    ================ */
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
#define PMC_LVDSC1_LVDV_MASK                     (0x3U)                                              /*!< PMC_LVDSC1: LVDV Mask                   */
#define PMC_LVDSC1_LVDV_SHIFT                    (0U)                                                /*!< PMC_LVDSC1: LVDV Position               */
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDRE_MASK                    (0x10U)                                             /*!< PMC_LVDSC1: LVDRE Mask                  */
#define PMC_LVDSC1_LVDRE_SHIFT                   (4U)                                                /*!< PMC_LVDSC1: LVDRE Position              */
#define PMC_LVDSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDRE_SHIFT))&PMC_LVDSC1_LVDRE_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDIE_MASK                    (0x20U)                                             /*!< PMC_LVDSC1: LVDIE Mask                  */
#define PMC_LVDSC1_LVDIE_SHIFT                   (5U)                                                /*!< PMC_LVDSC1: LVDIE Position              */
#define PMC_LVDSC1_LVDIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDIE_SHIFT))&PMC_LVDSC1_LVDIE_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDACK_MASK                   (0x40U)                                             /*!< PMC_LVDSC1: LVDACK Mask                 */
#define PMC_LVDSC1_LVDACK_SHIFT                  (6U)                                                /*!< PMC_LVDSC1: LVDACK Position             */
#define PMC_LVDSC1_LVDACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDACK_SHIFT))&PMC_LVDSC1_LVDACK_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDF_MASK                     (0x80U)                                             /*!< PMC_LVDSC1: LVDF Mask                   */
#define PMC_LVDSC1_LVDF_SHIFT                    (7U)                                                /*!< PMC_LVDSC1: LVDF Position               */
#define PMC_LVDSC1_LVDF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDF_SHIFT))&PMC_LVDSC1_LVDF_MASK) /*!< PMC_LVDSC1                              */
/* ------- LVDSC2 Bit Fields                        ------ */
#define PMC_LVDSC2_LVWV_MASK                     (0x3U)                                              /*!< PMC_LVDSC2: LVWV Mask                   */
#define PMC_LVDSC2_LVWV_SHIFT                    (0U)                                                /*!< PMC_LVDSC2: LVWV Position               */
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWIE_MASK                    (0x20U)                                             /*!< PMC_LVDSC2: LVWIE Mask                  */
#define PMC_LVDSC2_LVWIE_SHIFT                   (5U)                                                /*!< PMC_LVDSC2: LVWIE Position              */
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWIE_SHIFT))&PMC_LVDSC2_LVWIE_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWACK_MASK                   (0x40U)                                             /*!< PMC_LVDSC2: LVWACK Mask                 */
#define PMC_LVDSC2_LVWACK_SHIFT                  (6U)                                                /*!< PMC_LVDSC2: LVWACK Position             */
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWACK_SHIFT))&PMC_LVDSC2_LVWACK_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWF_MASK                     (0x80U)                                             /*!< PMC_LVDSC2: LVWF Mask                   */
#define PMC_LVDSC2_LVWF_SHIFT                    (7U)                                                /*!< PMC_LVDSC2: LVWF Position               */
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWF_SHIFT))&PMC_LVDSC2_LVWF_MASK) /*!< PMC_LVDSC2                              */
/* ------- REGSC Bit Fields                         ------ */
#define PMC_REGSC_BGBE_MASK                      (0x1U)                                              /*!< PMC_REGSC: BGBE Mask                    */
#define PMC_REGSC_BGBE_SHIFT                     (0U)                                                /*!< PMC_REGSC: BGBE Position                */
#define PMC_REGSC_BGBE(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_BGBE_SHIFT))&PMC_REGSC_BGBE_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_REGONS_MASK                    (0x4U)                                              /*!< PMC_REGSC: REGONS Mask                  */
#define PMC_REGSC_REGONS_SHIFT                   (2U)                                                /*!< PMC_REGSC: REGONS Position              */
#define PMC_REGSC_REGONS(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_REGONS_SHIFT))&PMC_REGSC_REGONS_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_ACKISO_MASK                    (0x8U)                                              /*!< PMC_REGSC: ACKISO Mask                  */
#define PMC_REGSC_ACKISO_SHIFT                   (3U)                                                /*!< PMC_REGSC: ACKISO Position              */
#define PMC_REGSC_ACKISO(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_ACKISO_SHIFT))&PMC_REGSC_ACKISO_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_BGEN_MASK                      (0x10U)                                             /*!< PMC_REGSC: BGEN Mask                    */
#define PMC_REGSC_BGEN_SHIFT                     (4U)                                                /*!< PMC_REGSC: BGEN Position                */
#define PMC_REGSC_BGEN(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_BGEN_SHIFT))&PMC_REGSC_BGEN_MASK) /*!< PMC_REGSC                               */
/**
 * @} */ /* End group PMC_Register_Masks_GROUP 
 */

/* PMC - Peripheral instance base addresses */
#define PMC_BasePtr                    0x4007D000UL //!< Peripheral base address
#define PMC                            ((PMC_Type *) PMC_BasePtr) //!< Freescale base pointer
#define PMC_BASE_PTR                   (PMC) //!< Freescale style base pointer
/**
 * @} */ /* End group PMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORTA_Peripheral_access_layer_GROUP PORTA Peripheral Access Layer
* @brief C Struct for PORTA
* @{
*/

/* ================================================================================ */
/* ================           PORTA (file:PORTA_MKL04Z4)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
/**
* @addtogroup PORTA_structs_GROUP PORTA struct
* @brief Struct for PORTA
* @{
*/
typedef struct {                                /*       PORTA Structure                                              */
   __IO uint32_t  PCR[32];                      /**< 0000: Pin Control Register                                         */
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
        uint8_t   RESERVED_0[24];              
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
} PORT_Type;

/**
 * @} */ /* End group PORTA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PORTA_Register_Masks_GROUP PORTA Register Masks
* @brief Register Masks for PORTA
* @{
*/
/* ------- PCR Bit Fields                           ------ */
#define PORT_PCR_PS_MASK                         (0x1U)                                              /*!< PORTA_PCR: PS Mask                      */
#define PORT_PCR_PS_SHIFT                        (0U)                                                /*!< PORTA_PCR: PS Position                  */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PS_SHIFT))&PORT_PCR_PS_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_PE_MASK                         (0x2U)                                              /*!< PORTA_PCR: PE Mask                      */
#define PORT_PCR_PE_SHIFT                        (1U)                                                /*!< PORTA_PCR: PE Position                  */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_SRE_MASK                        (0x4U)                                              /*!< PORTA_PCR: SRE Mask                     */
#define PORT_PCR_SRE_SHIFT                       (2U)                                                /*!< PORTA_PCR: SRE Position                 */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_SRE_SHIFT))&PORT_PCR_SRE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_PFE_MASK                        (0x10U)                                             /*!< PORTA_PCR: PFE Mask                     */
#define PORT_PCR_PFE_SHIFT                       (4U)                                                /*!< PORTA_PCR: PFE Position                 */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PFE_SHIFT))&PORT_PCR_PFE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_DSE_MASK                        (0x40U)                                             /*!< PORTA_PCR: DSE Mask                     */
#define PORT_PCR_DSE_SHIFT                       (6U)                                                /*!< PORTA_PCR: DSE Position                 */
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_DSE_SHIFT))&PORT_PCR_DSE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_MUX_MASK                        (0x700U)                                            /*!< PORTA_PCR: MUX Mask                     */
#define PORT_PCR_MUX_SHIFT                       (8U)                                                /*!< PORTA_PCR: MUX Position                 */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_IRQC_MASK                       (0xF0000U)                                          /*!< PORTA_PCR: IRQC Mask                    */
#define PORT_PCR_IRQC_SHIFT                      (16U)                                               /*!< PORTA_PCR: IRQC Position                */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_ISF_MASK                        (0x1000000U)                                        /*!< PORTA_PCR: ISF Mask                     */
#define PORT_PCR_ISF_SHIFT                       (24U)                                               /*!< PORTA_PCR: ISF Position                 */
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK) /*!< PORTA_PCR                               */
/* ------- GPCLR Bit Fields                         ------ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCLR: GPWD Mask                  */
#define PORT_GPCLR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCLR: GPWD Position              */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK) /*!< PORTA_GPCLR                             */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCLR: GPWE Mask                  */
#define PORT_GPCLR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCLR: GPWE Position              */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK) /*!< PORTA_GPCLR                             */
/* ------- GPCHR Bit Fields                         ------ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCHR: GPWD Mask                  */
#define PORT_GPCHR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCHR: GPWD Position              */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK) /*!< PORTA_GPCHR                             */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCHR: GPWE Mask                  */
#define PORT_GPCHR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCHR: GPWE Position              */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK) /*!< PORTA_GPCHR                             */
/* ------- ISFR Bit Fields                          ------ */
/**
 * @} */ /* End group PORTA_Register_Masks_GROUP 
 */

/* PORTA - Peripheral instance base addresses */
#define PORTA_BasePtr                  0x40049000UL //!< Peripheral base address
#define PORTA                          ((PORT_Type *) PORTA_BasePtr) //!< Freescale base pointer
#define PORTA_BASE_PTR                 (PORTA) //!< Freescale style base pointer
/**
 * @} */ /* End group PORTA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTB (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTB - Peripheral instance base addresses */
#define PORTB_BasePtr                  0x4004A000UL //!< Peripheral base address
#define PORTB                          ((PORT_Type *) PORTB_BasePtr) //!< Freescale base pointer
#define PORTB_BASE_PTR                 (PORTB) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTC (derived from PORTB)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTC - Peripheral instance base addresses */
#define PORTC_BasePtr                  0x4004B000UL //!< Peripheral base address
#define PORTC                          ((PORT_Type *) PORTC_BasePtr) //!< Freescale base pointer
#define PORTC_BASE_PTR                 (PORTC) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTD (derived from PORTB)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTD - Peripheral instance base addresses */
#define PORTD_BasePtr                  0x4004C000UL //!< Peripheral base address
#define PORTD                          ((PORT_Type *) PORTD_BasePtr) //!< Freescale base pointer
#define PORTD_BASE_PTR                 (PORTD) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTE (derived from PORTB)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTE - Peripheral instance base addresses */
#define PORTE_BasePtr                  0x4004D000UL //!< Peripheral base address
#define PORTE                          ((PORT_Type *) PORTE_BasePtr) //!< Freescale base pointer
#define PORTE_BASE_PTR                 (PORTE) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:RCM_MKL03Z4)               ================ */
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
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   RPFC;                         /**< 0004: Reset Pin Filter Control Register                            */
   __IO uint8_t   RPFW;                         /**< 0005: Reset Pin Filter Width Register                              */
   __IO uint8_t   FM;                           /**< 0006: Force Mode Register                                          */
   __IO uint8_t   MR;                           /**< 0007: Mode Register                                                */
   __IO uint8_t   SSRS0;                        /**< 0008: Sticky System Reset Status Register 0                        */
   __IO uint8_t   SSRS1;                        /**< 0009: Sticky System Reset Status Register 1                        */
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
#define RCM_SRS0_WAKEUP_MASK                     (0x1U)                                              /*!< RCM_SRS0: WAKEUP Mask                   */
#define RCM_SRS0_WAKEUP_SHIFT                    (0U)                                                /*!< RCM_SRS0: WAKEUP Position               */
#define RCM_SRS0_WAKEUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_WAKEUP_SHIFT))&RCM_SRS0_WAKEUP_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_LVD_MASK                        (0x2U)                                              /*!< RCM_SRS0: LVD Mask                      */
#define RCM_SRS0_LVD_SHIFT                       (1U)                                                /*!< RCM_SRS0: LVD Position                  */
#define RCM_SRS0_LVD(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LVD_SHIFT))&RCM_SRS0_LVD_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_WDOG_MASK                       (0x20U)                                             /*!< RCM_SRS0: WDOG Mask                     */
#define RCM_SRS0_WDOG_SHIFT                      (5U)                                                /*!< RCM_SRS0: WDOG Position                 */
#define RCM_SRS0_WDOG(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_WDOG_SHIFT))&RCM_SRS0_WDOG_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_PIN_MASK                        (0x40U)                                             /*!< RCM_SRS0: PIN Mask                      */
#define RCM_SRS0_PIN_SHIFT                       (6U)                                                /*!< RCM_SRS0: PIN Position                  */
#define RCM_SRS0_PIN(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_PIN_SHIFT))&RCM_SRS0_PIN_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_POR_MASK                        (0x80U)                                             /*!< RCM_SRS0: POR Mask                      */
#define RCM_SRS0_POR_SHIFT                       (7U)                                                /*!< RCM_SRS0: POR Position                  */
#define RCM_SRS0_POR(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_POR_SHIFT))&RCM_SRS0_POR_MASK) /*!< RCM_SRS0                                */
/* ------- SRS1 Bit Fields                          ------ */
#define RCM_SRS1_LOCKUP_MASK                     (0x2U)                                              /*!< RCM_SRS1: LOCKUP Mask                   */
#define RCM_SRS1_LOCKUP_SHIFT                    (1U)                                                /*!< RCM_SRS1: LOCKUP Position               */
#define RCM_SRS1_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_LOCKUP_SHIFT))&RCM_SRS1_LOCKUP_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_SW_MASK                         (0x4U)                                              /*!< RCM_SRS1: SW Mask                       */
#define RCM_SRS1_SW_SHIFT                        (2U)                                                /*!< RCM_SRS1: SW Position                   */
#define RCM_SRS1_SW(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_SW_SHIFT))&RCM_SRS1_SW_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_MDM_AP_MASK                     (0x8U)                                              /*!< RCM_SRS1: MDM_AP Mask                   */
#define RCM_SRS1_MDM_AP_SHIFT                    (3U)                                                /*!< RCM_SRS1: MDM_AP Position               */
#define RCM_SRS1_MDM_AP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_MDM_AP_SHIFT))&RCM_SRS1_MDM_AP_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_SACKERR_MASK                    (0x20U)                                             /*!< RCM_SRS1: SACKERR Mask                  */
#define RCM_SRS1_SACKERR_SHIFT                   (5U)                                                /*!< RCM_SRS1: SACKERR Position              */
#define RCM_SRS1_SACKERR(x)                      (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_SACKERR_SHIFT))&RCM_SRS1_SACKERR_MASK) /*!< RCM_SRS1                                */
/* ------- RPFC Bit Fields                          ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)                                              /*!< RCM_RPFC: RSTFLTSRW Mask                */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)                                                /*!< RCM_RPFC: RSTFLTSRW Position            */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK) /*!< RCM_RPFC                                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)                                              /*!< RCM_RPFC: RSTFLTSS Mask                 */
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)                                                /*!< RCM_RPFC: RSTFLTSS Position             */
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSS_SHIFT))&RCM_RPFC_RSTFLTSS_MASK) /*!< RCM_RPFC                                */
/* ------- RPFW Bit Fields                          ------ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FU)                                             /*!< RCM_RPFW: RSTFLTSEL Mask                */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 (0U)                                                /*!< RCM_RPFW: RSTFLTSEL Position            */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK) /*!< RCM_RPFW                                */
/* ------- FM Bit Fields                            ------ */
#define RCM_FM_FORCEROM_MASK                     (0x6U)                                              /*!< RCM_FM: FORCEROM Mask                   */
#define RCM_FM_FORCEROM_SHIFT                    (1U)                                                /*!< RCM_FM: FORCEROM Position               */
#define RCM_FM_FORCEROM(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_FM_FORCEROM_SHIFT))&RCM_FM_FORCEROM_MASK) /*!< RCM_FM                                  */
/* ------- MR Bit Fields                            ------ */
#define RCM_MR_BOOTROM_MASK                      (0x6U)                                              /*!< RCM_MR: BOOTROM Mask                    */
#define RCM_MR_BOOTROM_SHIFT                     (1U)                                                /*!< RCM_MR: BOOTROM Position                */
#define RCM_MR_BOOTROM(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_MR_BOOTROM_SHIFT))&RCM_MR_BOOTROM_MASK) /*!< RCM_MR                                  */
/* ------- SSRS0 Bit Fields                         ------ */
#define RCM_SSRS0_SWAKEUP_MASK                   (0x1U)                                              /*!< RCM_SSRS0: SWAKEUP Mask                 */
#define RCM_SSRS0_SWAKEUP_SHIFT                  (0U)                                                /*!< RCM_SSRS0: SWAKEUP Position             */
#define RCM_SSRS0_SWAKEUP(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SWAKEUP_SHIFT))&RCM_SSRS0_SWAKEUP_MASK) /*!< RCM_SSRS0                               */
#define RCM_SSRS0_SLVD_MASK                      (0x2U)                                              /*!< RCM_SSRS0: SLVD Mask                    */
#define RCM_SSRS0_SLVD_SHIFT                     (1U)                                                /*!< RCM_SSRS0: SLVD Position                */
#define RCM_SSRS0_SLVD(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SLVD_SHIFT))&RCM_SSRS0_SLVD_MASK) /*!< RCM_SSRS0                               */
#define RCM_SSRS0_SWDOG_MASK                     (0x20U)                                             /*!< RCM_SSRS0: SWDOG Mask                   */
#define RCM_SSRS0_SWDOG_SHIFT                    (5U)                                                /*!< RCM_SSRS0: SWDOG Position               */
#define RCM_SSRS0_SWDOG(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SWDOG_SHIFT))&RCM_SSRS0_SWDOG_MASK) /*!< RCM_SSRS0                               */
#define RCM_SSRS0_SPIN_MASK                      (0x40U)                                             /*!< RCM_SSRS0: SPIN Mask                    */
#define RCM_SSRS0_SPIN_SHIFT                     (6U)                                                /*!< RCM_SSRS0: SPIN Position                */
#define RCM_SSRS0_SPIN(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SPIN_SHIFT))&RCM_SSRS0_SPIN_MASK) /*!< RCM_SSRS0                               */
#define RCM_SSRS0_SPOR_MASK                      (0x80U)                                             /*!< RCM_SSRS0: SPOR Mask                    */
#define RCM_SSRS0_SPOR_SHIFT                     (7U)                                                /*!< RCM_SSRS0: SPOR Position                */
#define RCM_SSRS0_SPOR(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SPOR_SHIFT))&RCM_SSRS0_SPOR_MASK) /*!< RCM_SSRS0                               */
/* ------- SSRS1 Bit Fields                         ------ */
#define RCM_SSRS1_SLOCKUP_MASK                   (0x2U)                                              /*!< RCM_SSRS1: SLOCKUP Mask                 */
#define RCM_SSRS1_SLOCKUP_SHIFT                  (1U)                                                /*!< RCM_SSRS1: SLOCKUP Position             */
#define RCM_SSRS1_SLOCKUP(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_SSRS1_SLOCKUP_SHIFT))&RCM_SSRS1_SLOCKUP_MASK) /*!< RCM_SSRS1                               */
#define RCM_SSRS1_SSW_MASK                       (0x4U)                                              /*!< RCM_SSRS1: SSW Mask                     */
#define RCM_SSRS1_SSW_SHIFT                      (2U)                                                /*!< RCM_SSRS1: SSW Position                 */
#define RCM_SSRS1_SSW(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SSRS1_SSW_SHIFT))&RCM_SSRS1_SSW_MASK) /*!< RCM_SSRS1                               */
#define RCM_SSRS1_SMDM_AP_MASK                   (0x8U)                                              /*!< RCM_SSRS1: SMDM_AP Mask                 */
#define RCM_SSRS1_SMDM_AP_SHIFT                  (3U)                                                /*!< RCM_SSRS1: SMDM_AP Position             */
#define RCM_SSRS1_SMDM_AP(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_SSRS1_SMDM_AP_SHIFT))&RCM_SSRS1_SMDM_AP_MASK) /*!< RCM_SSRS1                               */
#define RCM_SSRS1_SSACKERR_MASK                  (0x20U)                                             /*!< RCM_SSRS1: SSACKERR Mask                */
#define RCM_SSRS1_SSACKERR_SHIFT                 (5U)                                                /*!< RCM_SSRS1: SSACKERR Position            */
#define RCM_SSRS1_SSACKERR(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_SSRS1_SSACKERR_SHIFT))&RCM_SSRS1_SSACKERR_MASK) /*!< RCM_SSRS1                               */
/**
 * @} */ /* End group RCM_Register_Masks_GROUP 
 */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x4007F000UL //!< Peripheral base address
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
/* ================           RFSYS (file:RFSYS_0)                 ================ */
/* ================================================================================ */

/**
 * @brief System register file
 */
/**
* @addtogroup RFSYS_structs_GROUP RFSYS struct
* @brief Struct for RFSYS
* @{
*/
typedef struct {                                /*       RFSYS Structure                                              */
   __IO uint32_t  REG[8];                       /**< 0000: Register file register                                       */
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
/* ------- REG Bit Fields                           ------ */
#define RFSYS_REG_LL_MASK                        (0xFFU)                                             /*!< RFSYS_REG: LL Mask                      */
#define RFSYS_REG_LL_SHIFT                       (0U)                                                /*!< RFSYS_REG: LL Position                  */
#define RFSYS_REG_LL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LL_SHIFT))&RFSYS_REG_LL_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_LH_MASK                        (0xFF00U)                                           /*!< RFSYS_REG: LH Mask                      */
#define RFSYS_REG_LH_SHIFT                       (8U)                                                /*!< RFSYS_REG: LH Position                  */
#define RFSYS_REG_LH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LH_SHIFT))&RFSYS_REG_LH_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_HL_MASK                        (0xFF0000U)                                         /*!< RFSYS_REG: HL Mask                      */
#define RFSYS_REG_HL_SHIFT                       (16U)                                               /*!< RFSYS_REG: HL Position                  */
#define RFSYS_REG_HL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HL_SHIFT))&RFSYS_REG_HL_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_HH_MASK                        (0xFF000000U)                                       /*!< RFSYS_REG: HH Mask                      */
#define RFSYS_REG_HH_SHIFT                       (24U)                                               /*!< RFSYS_REG: HH Position                  */
#define RFSYS_REG_HH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HH_SHIFT))&RFSYS_REG_HH_MASK) /*!< RFSYS_REG                               */
/**
 * @} */ /* End group RFSYS_Register_Masks_GROUP 
 */

/* RFSYS - Peripheral instance base addresses */
#define RFSYS_BasePtr                  0x40041000UL //!< Peripheral base address
#define RFSYS                          ((RFSYS_Type *) RFSYS_BasePtr) //!< Freescale base pointer
#define RFSYS_BASE_PTR                 (RFSYS) //!< Freescale style base pointer
/**
 * @} */ /* End group RFSYS_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ROM_Peripheral_access_layer_GROUP ROM Peripheral Access Layer
* @brief C Struct for ROM
* @{
*/

/* ================================================================================ */
/* ================           ROM (file:ROM_MKL)                   ================ */
/* ================================================================================ */

/**
 * @brief System ROM
 */
/**
* @addtogroup ROM_structs_GROUP ROM struct
* @brief Struct for ROM
* @{
*/
typedef struct {                                /*       ROM Structure                                                */
   __I  uint32_t  ENTRY[3];                     /**< 0000: Entry                                                        */
   __I  uint32_t  TABLEMARK;                    /**< 000C: End of Table Marker Register                                 */
        uint8_t   RESERVED_0[4028];            
   __I  uint32_t  SYSACCESS;                    /**< 0FCC: System Access Register                                       */
   __I  uint32_t  PERIPHID4;                    /**< 0FD0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID5;                    /**< 0FD4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID6;                    /**< 0FD8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID7;                    /**< 0FDC: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID0;                    /**< 0FE0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID1;                    /**< 0FE4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID2;                    /**< 0FE8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID3;                    /**< 0FEC: Peripheral ID Register                                       */
   __I  uint32_t  COMPID[4];                    /**< 0FF0: Component ID Register                                        */
} ROM_Type;

/**
 * @} */ /* End group ROM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ROM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ROM_Register_Masks_GROUP ROM Register Masks
* @brief Register Masks for ROM
* @{
*/
/* ------- ENTRY Bit Fields                         ------ */
#define ROM_ENTRY_ENTRY_MASK                     (0xFFFFFFFFU)                                       /*!< ROM_ENTRY: ENTRY Mask                   */
#define ROM_ENTRY_ENTRY_SHIFT                    (0U)                                                /*!< ROM_ENTRY: ENTRY Position               */
#define ROM_ENTRY_ENTRY(x)                       (((uint32_t)(((uint32_t)(x))<<ROM_ENTRY_ENTRY_SHIFT))&ROM_ENTRY_ENTRY_MASK) /*!< ROM_ENTRY                               */
/* ------- TABLEMARK Bit Fields                     ------ */
#define ROM_TABLEMARK_MARK_MASK                  (0xFFFFFFFFU)                                       /*!< ROM_TABLEMARK: MARK Mask                */
#define ROM_TABLEMARK_MARK_SHIFT                 (0U)                                                /*!< ROM_TABLEMARK: MARK Position            */
#define ROM_TABLEMARK_MARK(x)                    (((uint32_t)(((uint32_t)(x))<<ROM_TABLEMARK_MARK_SHIFT))&ROM_TABLEMARK_MARK_MASK) /*!< ROM_TABLEMARK                           */
/* ------- SYSACCESS Bit Fields                     ------ */
#define ROM_SYSACCESS_SYSACCESS_MASK             (0xFFFFFFFFU)                                       /*!< ROM_SYSACCESS: SYSACCESS Mask           */
#define ROM_SYSACCESS_SYSACCESS_SHIFT            (0U)                                                /*!< ROM_SYSACCESS: SYSACCESS Position       */
#define ROM_SYSACCESS_SYSACCESS(x)               (((uint32_t)(((uint32_t)(x))<<ROM_SYSACCESS_SYSACCESS_SHIFT))&ROM_SYSACCESS_SYSACCESS_MASK) /*!< ROM_SYSACCESS                           */
/* ------- PERIPHID Bit Fields                      ------ */
#define ROM_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFU)                                       /*!< ROM_PERIPHID: PERIPHID Mask             */
#define ROM_PERIPHID_PERIPHID_SHIFT              (0U)                                                /*!< ROM_PERIPHID: PERIPHID Position         */
#define ROM_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID_PERIPHID_SHIFT))&ROM_PERIPHID_PERIPHID_MASK) /*!< ROM_PERIPHID                            */
/* ------- COMPID Bit Fields                        ------ */
#define ROM_COMPID_COMPID_MASK                   (0xFFFFFFFFU)                                       /*!< ROM_COMPID: COMPID Mask                 */
#define ROM_COMPID_COMPID_SHIFT                  (0U)                                                /*!< ROM_COMPID: COMPID Position             */
#define ROM_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<ROM_COMPID_COMPID_SHIFT))&ROM_COMPID_COMPID_MASK) /*!< ROM_COMPID                              */
/**
 * @} */ /* End group ROM_Register_Masks_GROUP 
 */

/* ROM - Peripheral instance base addresses */
#define ROM_BasePtr                    0xF0002000UL //!< Peripheral base address
#define ROM                            ((ROM_Type *) ROM_BasePtr) //!< Freescale base pointer
#define ROM_BASE_PTR                   (ROM) //!< Freescale style base pointer
/**
 * @} */ /* End group ROM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer
* @brief C Struct for RTC
* @{
*/

/* ================================================================================ */
/* ================           RTC (file:RTC_MKL03Z4)               ================ */
/* ================================================================================ */

/**
 * @brief Secure Real Time Clock
 */
/**
* @addtogroup RTC_structs_GROUP RTC struct
* @brief Struct for RTC
* @{
*/
typedef struct {                                /*       RTC Structure                                                */
   __IO uint32_t  TSR;                          /**< 0000: Time Seconds Register                                        */
   __IO uint32_t  TPR;                          /**< 0004: Time Prescaler Register                                      */
   __IO uint32_t  TAR;                          /**< 0008: Time Alarm Register                                          */
   __IO uint32_t  TCR;                          /**< 000C: Time Compensation Register                                   */
   __IO uint32_t  CR;                           /**< 0010: Control Register                                             */
   __IO uint32_t  SR;                           /**< 0014: Status Register                                              */
   __IO uint32_t  LR;                           /**< 0018: Lock Register                                                */
   __IO uint32_t  IER;                          /**< 001C: Interrupt Enable Register                                    */
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
/* ------- TSR Bit Fields                           ------ */
#define RTC_TSR_TSR_MASK                         (0xFFFFFFFFU)                                       /*!< RTC_TSR: TSR Mask                       */
#define RTC_TSR_TSR_SHIFT                        (0U)                                                /*!< RTC_TSR: TSR Position                   */
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSR_TSR_SHIFT))&RTC_TSR_TSR_MASK) /*!< RTC_TSR                                 */
/* ------- TPR Bit Fields                           ------ */
#define RTC_TPR_TPR_MASK                         (0xFFFFU)                                           /*!< RTC_TPR: TPR Mask                       */
#define RTC_TPR_TPR_SHIFT                        (0U)                                                /*!< RTC_TPR: TPR Position                   */
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TPR_TPR_SHIFT))&RTC_TPR_TPR_MASK) /*!< RTC_TPR                                 */
/* ------- TAR Bit Fields                           ------ */
#define RTC_TAR_TAR_MASK                         (0xFFFFFFFFU)                                       /*!< RTC_TAR: TAR Mask                       */
#define RTC_TAR_TAR_SHIFT                        (0U)                                                /*!< RTC_TAR: TAR Position                   */
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TAR_TAR_SHIFT))&RTC_TAR_TAR_MASK) /*!< RTC_TAR                                 */
/* ------- TCR Bit Fields                           ------ */
#define RTC_TCR_TCR_MASK                         (0xFFU)                                             /*!< RTC_TCR: TCR Mask                       */
#define RTC_TCR_TCR_SHIFT                        (0U)                                                /*!< RTC_TCR: TCR Position                   */
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCR_SHIFT))&RTC_TCR_TCR_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_CIR_MASK                         (0xFF00U)                                           /*!< RTC_TCR: CIR Mask                       */
#define RTC_TCR_CIR_SHIFT                        (8U)                                                /*!< RTC_TCR: CIR Position                   */
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIR_SHIFT))&RTC_TCR_CIR_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_TCV_MASK                         (0xFF0000U)                                         /*!< RTC_TCR: TCV Mask                       */
#define RTC_TCR_TCV_SHIFT                        (16U)                                               /*!< RTC_TCR: TCV Position                   */
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_CIC_MASK                         (0xFF000000U)                                       /*!< RTC_TCR: CIC Mask                       */
#define RTC_TCR_CIC_SHIFT                        (24U)                                               /*!< RTC_TCR: CIC Position                   */
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIC_SHIFT))&RTC_TCR_CIC_MASK) /*!< RTC_TCR                                 */
/* ------- CR Bit Fields                            ------ */
#define RTC_CR_SWR_MASK                          (0x1U)                                              /*!< RTC_CR: SWR Mask                        */
#define RTC_CR_SWR_SHIFT                         (0U)                                                /*!< RTC_CR: SWR Position                    */
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SWR_SHIFT))&RTC_CR_SWR_MASK) /*!< RTC_CR                                  */
#define RTC_CR_WPE_MASK                          (0x2U)                                              /*!< RTC_CR: WPE Mask                        */
#define RTC_CR_WPE_SHIFT                         (1U)                                                /*!< RTC_CR: WPE Position                    */
#define RTC_CR_WPE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_WPE_SHIFT))&RTC_CR_WPE_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SUP_MASK                          (0x4U)                                              /*!< RTC_CR: SUP Mask                        */
#define RTC_CR_SUP_SHIFT                         (2U)                                                /*!< RTC_CR: SUP Position                    */
#define RTC_CR_SUP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SUP_SHIFT))&RTC_CR_SUP_MASK) /*!< RTC_CR                                  */
#define RTC_CR_UM_MASK                           (0x8U)                                              /*!< RTC_CR: UM Mask                         */
#define RTC_CR_UM_SHIFT                          (3U)                                                /*!< RTC_CR: UM Position                     */
#define RTC_CR_UM(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_CR_UM_SHIFT))&RTC_CR_UM_MASK) /*!< RTC_CR                                  */
#define RTC_CR_WPS_MASK                          (0x10U)                                             /*!< RTC_CR: WPS Mask                        */
#define RTC_CR_WPS_SHIFT                         (4U)                                                /*!< RTC_CR: WPS Position                    */
#define RTC_CR_WPS(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_WPS_SHIFT))&RTC_CR_WPS_MASK) /*!< RTC_CR                                  */
#define RTC_CR_OSCE_MASK                         (0x100U)                                            /*!< RTC_CR: OSCE Mask                       */
#define RTC_CR_OSCE_SHIFT                        (8U)                                                /*!< RTC_CR: OSCE Position                   */
#define RTC_CR_OSCE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_OSCE_SHIFT))&RTC_CR_OSCE_MASK) /*!< RTC_CR                                  */
#define RTC_CR_CLKO_MASK                         (0x200U)                                            /*!< RTC_CR: CLKO Mask                       */
#define RTC_CR_CLKO_SHIFT                        (9U)                                                /*!< RTC_CR: CLKO Position                   */
#define RTC_CR_CLKO(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_CLKO_SHIFT))&RTC_CR_CLKO_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SCP_MASK                          (0x3C00U)                                           /*!< RTC_CR: SCP Mask                        */
#define RTC_CR_SCP_SHIFT                         (10U)                                               /*!< RTC_CR: SCP Position                    */
#define RTC_CR_SCP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SCP_SHIFT))&RTC_CR_SCP_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC16P_MASK                        (0x400U)                                            /*!< RTC_CR: SC16P Mask                      */
#define RTC_CR_SC16P_SHIFT                       (10U)                                               /*!< RTC_CR: SC16P Position                  */
#define RTC_CR_SC16P(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC16P_SHIFT))&RTC_CR_SC16P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC8P_MASK                         (0x800U)                                            /*!< RTC_CR: SC8P Mask                       */
#define RTC_CR_SC8P_SHIFT                        (11U)                                               /*!< RTC_CR: SC8P Position                   */
#define RTC_CR_SC8P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC8P_SHIFT))&RTC_CR_SC8P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC4P_MASK                         (0x1000U)                                           /*!< RTC_CR: SC4P Mask                       */
#define RTC_CR_SC4P_SHIFT                        (12U)                                               /*!< RTC_CR: SC4P Position                   */
#define RTC_CR_SC4P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC4P_SHIFT))&RTC_CR_SC4P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC2P_MASK                         (0x2000U)                                           /*!< RTC_CR: SC2P Mask                       */
#define RTC_CR_SC2P_SHIFT                        (13U)                                               /*!< RTC_CR: SC2P Position                   */
#define RTC_CR_SC2P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC2P_SHIFT))&RTC_CR_SC2P_MASK) /*!< RTC_CR                                  */
/* ------- SR Bit Fields                            ------ */
#define RTC_SR_TIF_MASK                          (0x1U)                                              /*!< RTC_SR: TIF Mask                        */
#define RTC_SR_TIF_SHIFT                         (0U)                                                /*!< RTC_SR: TIF Position                    */
#define RTC_SR_TIF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TIF_SHIFT))&RTC_SR_TIF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TOF_MASK                          (0x2U)                                              /*!< RTC_SR: TOF Mask                        */
#define RTC_SR_TOF_SHIFT                         (1U)                                                /*!< RTC_SR: TOF Position                    */
#define RTC_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TOF_SHIFT))&RTC_SR_TOF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TAF_MASK                          (0x4U)                                              /*!< RTC_SR: TAF Mask                        */
#define RTC_SR_TAF_SHIFT                         (2U)                                                /*!< RTC_SR: TAF Position                    */
#define RTC_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TAF_SHIFT))&RTC_SR_TAF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TCE_MASK                          (0x10U)                                             /*!< RTC_SR: TCE Mask                        */
#define RTC_SR_TCE_SHIFT                         (4U)                                                /*!< RTC_SR: TCE Position                    */
#define RTC_SR_TCE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TCE_SHIFT))&RTC_SR_TCE_MASK) /*!< RTC_SR                                  */
/* ------- LR Bit Fields                            ------ */
#define RTC_LR_TCL_MASK                          (0x8U)                                              /*!< RTC_LR: TCL Mask                        */
#define RTC_LR_TCL_SHIFT                         (3U)                                                /*!< RTC_LR: TCL Position                    */
#define RTC_LR_TCL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TCL_SHIFT))&RTC_LR_TCL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_CRL_MASK                          (0x10U)                                             /*!< RTC_LR: CRL Mask                        */
#define RTC_LR_CRL_SHIFT                         (4U)                                                /*!< RTC_LR: CRL Position                    */
#define RTC_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_CRL_SHIFT))&RTC_LR_CRL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_SRL_MASK                          (0x20U)                                             /*!< RTC_LR: SRL Mask                        */
#define RTC_LR_SRL_SHIFT                         (5U)                                                /*!< RTC_LR: SRL Position                    */
#define RTC_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_SRL_SHIFT))&RTC_LR_SRL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_LRL_MASK                          (0x40U)                                             /*!< RTC_LR: LRL Mask                        */
#define RTC_LR_LRL_SHIFT                         (6U)                                                /*!< RTC_LR: LRL Position                    */
#define RTC_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_LRL_SHIFT))&RTC_LR_LRL_MASK) /*!< RTC_LR                                  */
/* ------- IER Bit Fields                           ------ */
#define RTC_IER_TIIE_MASK                        (0x1U)                                              /*!< RTC_IER: TIIE Mask                      */
#define RTC_IER_TIIE_SHIFT                       (0U)                                                /*!< RTC_IER: TIIE Position                  */
#define RTC_IER_TIIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TIIE_SHIFT))&RTC_IER_TIIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TOIE_MASK                        (0x2U)                                              /*!< RTC_IER: TOIE Mask                      */
#define RTC_IER_TOIE_SHIFT                       (1U)                                                /*!< RTC_IER: TOIE Position                  */
#define RTC_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TOIE_SHIFT))&RTC_IER_TOIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TAIE_MASK                        (0x4U)                                              /*!< RTC_IER: TAIE Mask                      */
#define RTC_IER_TAIE_SHIFT                       (2U)                                                /*!< RTC_IER: TAIE Position                  */
#define RTC_IER_TAIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TAIE_SHIFT))&RTC_IER_TAIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TSIE_MASK                        (0x10U)                                             /*!< RTC_IER: TSIE Mask                      */
#define RTC_IER_TSIE_SHIFT                       (4U)                                                /*!< RTC_IER: TSIE Position                  */
#define RTC_IER_TSIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TSIE_SHIFT))&RTC_IER_TSIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_WPON_MASK                        (0x80U)                                             /*!< RTC_IER: WPON Mask                      */
#define RTC_IER_WPON_SHIFT                       (7U)                                                /*!< RTC_IER: WPON Position                  */
#define RTC_IER_WPON(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_WPON_SHIFT))&RTC_IER_WPON_MASK) /*!< RTC_IER                                 */
/**
 * @} */ /* End group RTC_Register_Masks_GROUP 
 */

/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x4003D000UL //!< Peripheral base address
#define RTC                            ((RTC_Type *) RTC_BasePtr) //!< Freescale base pointer
#define RTC_BASE_PTR                   (RTC) //!< Freescale style base pointer
/**
 * @} */ /* End group RTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer
* @brief C Struct for SIM
* @{
*/

/* ================================================================================ */
/* ================           SIM (file:SIM_MKL17Z4)               ================ */
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
   __IO uint32_t  SOPT1;                        /**< 0000: System Options Register 1                                    */
   __IO uint32_t  SOPT1CFG;                     /**< 0004: SOPT1 Configuration Register                                 */
        uint8_t   RESERVED_0[4092];            
   __IO uint32_t  SOPT2;                        /**< 1004: System Options Register 2                                    */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  SOPT4;                        /**< 100C: System Options Register 4                                    */
   __IO uint32_t  SOPT5;                        /**< 1010: System Options Register 5                                    */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  SOPT7;                        /**< 1018: System Options Register 7                                    */
        uint8_t   RESERVED_3[8];               
   __I  uint32_t  SDID;                         /**< 1024: System Device Identification Register                        */
        uint8_t   RESERVED_4[12];              
   __IO uint32_t  SCGC4;                        /**< 1034: System Clock Gating Control Register 4                       */
   __IO uint32_t  SCGC5;                        /**< 1038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /**< 103C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /**< 1040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /**< 1044: System Clock Divider Register 1                              */
        uint8_t   RESERVED_5[4];               
   __IO uint32_t  FCFG1;                        /**< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /**< 1050: Flash Configuration Register 2                               */
        uint8_t   RESERVED_6[4];               
   __I  uint32_t  UIDMH;                        /**< 1058: Unique Identification Register Mid-High                      */
   __I  uint32_t  UIDML;                        /**< 105C: Unique Identification Register Mid Low                       */
   __I  uint32_t  UIDL;                         /**< 1060: Unique Identification Register Low                           */
        uint8_t   RESERVED_7[156];             
   __IO uint32_t  COPC;                         /**< 1100: COP Control Register                                         */
   __O  uint32_t  SRVCOP;                       /**< 1104: Service COP                                                  */
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
#define SIM_SOPT1_OSC32KOUT_MASK                 (0x30000U)                                          /*!< SIM_SOPT1: OSC32KOUT Mask               */
#define SIM_SOPT1_OSC32KOUT_SHIFT                (16U)                                               /*!< SIM_SOPT1: OSC32KOUT Position           */
#define SIM_SOPT1_OSC32KOUT(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KOUT_SHIFT))&SIM_SOPT1_OSC32KOUT_MASK) /*!< SIM_SOPT1                               */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)                                          /*!< SIM_SOPT1: OSC32KSEL Mask               */
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)                                               /*!< SIM_SOPT1: OSC32KSEL Position           */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK) /*!< SIM_SOPT1                               */
/* ------- SOPT1CFG Bit Fields                      ------ */
/* ------- SOPT2 Bit Fields                         ------ */
#define SIM_SOPT2_RTCCLKOUTSEL_MASK              (0x10U)                                             /*!< SIM_SOPT2: RTCCLKOUTSEL Mask            */
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT             (4U)                                                /*!< SIM_SOPT2: RTCCLKOUTSEL Position        */
#define SIM_SOPT2_RTCCLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_RTCCLKOUTSEL_SHIFT))&SIM_SOPT2_RTCCLKOUTSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_CLKOUTSEL_MASK                 (0xE0U)                                             /*!< SIM_SOPT2: CLKOUTSEL Mask               */
#define SIM_SOPT2_CLKOUTSEL_SHIFT                (5U)                                                /*!< SIM_SOPT2: CLKOUTSEL Position           */
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_CLKOUTSEL_SHIFT))&SIM_SOPT2_CLKOUTSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_USBSRC_MASK                    (0x40000U)                                          /*!< SIM_SOPT2: USBSRC Mask                  */
#define SIM_SOPT2_USBSRC_SHIFT                   (18U)                                               /*!< SIM_SOPT2: USBSRC Position              */
#define SIM_SOPT2_USBSRC(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_USBSRC_SHIFT))&SIM_SOPT2_USBSRC_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_FLEXIOSRC_MASK                 (0xC00000U)                                         /*!< SIM_SOPT2: FLEXIOSRC Mask               */
#define SIM_SOPT2_FLEXIOSRC_SHIFT                (22U)                                               /*!< SIM_SOPT2: FLEXIOSRC Position           */
#define SIM_SOPT2_FLEXIOSRC(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_FLEXIOSRC_SHIFT))&SIM_SOPT2_FLEXIOSRC_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_TPMSRC_MASK                    (0x3000000U)                                        /*!< SIM_SOPT2: TPMSRC Mask                  */
#define SIM_SOPT2_TPMSRC_SHIFT                   (24U)                                               /*!< SIM_SOPT2: TPMSRC Position              */
#define SIM_SOPT2_TPMSRC(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_TPMSRC_SHIFT))&SIM_SOPT2_TPMSRC_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_LPUART0SRC_MASK                (0xC000000U)                                        /*!< SIM_SOPT2: LPUART0SRC Mask              */
#define SIM_SOPT2_LPUART0SRC_SHIFT               (26U)                                               /*!< SIM_SOPT2: LPUART0SRC Position          */
#define SIM_SOPT2_LPUART0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_LPUART0SRC_SHIFT))&SIM_SOPT2_LPUART0SRC_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_LPUART1SRC_MASK                (0x30000000U)                                       /*!< SIM_SOPT2: LPUART1SRC Mask              */
#define SIM_SOPT2_LPUART1SRC_SHIFT               (28U)                                               /*!< SIM_SOPT2: LPUART1SRC Position          */
#define SIM_SOPT2_LPUART1SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_LPUART1SRC_SHIFT))&SIM_SOPT2_LPUART1SRC_MASK) /*!< SIM_SOPT2                               */
/* ------- SOPT4 Bit Fields                         ------ */
#define SIM_SOPT4_TPM1CH0SRC_MASK                (0xC0000U)                                          /*!< SIM_SOPT4: TPM1CH0SRC Mask              */
#define SIM_SOPT4_TPM1CH0SRC_SHIFT               (18U)                                               /*!< SIM_SOPT4: TPM1CH0SRC Position          */
#define SIM_SOPT4_TPM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM1CH0SRC_SHIFT))&SIM_SOPT4_TPM1CH0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_TPM2CH0SRC_MASK                (0x100000U)                                         /*!< SIM_SOPT4: TPM2CH0SRC Mask              */
#define SIM_SOPT4_TPM2CH0SRC_SHIFT               (20U)                                               /*!< SIM_SOPT4: TPM2CH0SRC Position          */
#define SIM_SOPT4_TPM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM2CH0SRC_SHIFT))&SIM_SOPT4_TPM2CH0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_TPM0CLKSEL_MASK                (0x1000000U)                                        /*!< SIM_SOPT4: TPM0CLKSEL Mask              */
#define SIM_SOPT4_TPM0CLKSEL_SHIFT               (24U)                                               /*!< SIM_SOPT4: TPM0CLKSEL Position          */
#define SIM_SOPT4_TPM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM0CLKSEL_SHIFT))&SIM_SOPT4_TPM0CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_TPM1CLKSEL_MASK                (0x2000000U)                                        /*!< SIM_SOPT4: TPM1CLKSEL Mask              */
#define SIM_SOPT4_TPM1CLKSEL_SHIFT               (25U)                                               /*!< SIM_SOPT4: TPM1CLKSEL Position          */
#define SIM_SOPT4_TPM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM1CLKSEL_SHIFT))&SIM_SOPT4_TPM1CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_TPM2CLKSEL_MASK                (0x4000000U)                                        /*!< SIM_SOPT4: TPM2CLKSEL Mask              */
#define SIM_SOPT4_TPM2CLKSEL_SHIFT               (26U)                                               /*!< SIM_SOPT4: TPM2CLKSEL Position          */
#define SIM_SOPT4_TPM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM2CLKSEL_SHIFT))&SIM_SOPT4_TPM2CLKSEL_MASK) /*!< SIM_SOPT4                               */
/* ------- SOPT5 Bit Fields                         ------ */
#define SIM_SOPT5_LPUART0TXSRC_MASK              (0x3U)                                              /*!< SIM_SOPT5: LPUART0TXSRC Mask            */
#define SIM_SOPT5_LPUART0TXSRC_SHIFT             (0U)                                                /*!< SIM_SOPT5: LPUART0TXSRC Position        */
#define SIM_SOPT5_LPUART0TXSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART0TXSRC_SHIFT))&SIM_SOPT5_LPUART0TXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_LPUART0RXSRC_MASK              (0x4U)                                              /*!< SIM_SOPT5: LPUART0RXSRC Mask            */
#define SIM_SOPT5_LPUART0RXSRC_SHIFT             (2U)                                                /*!< SIM_SOPT5: LPUART0RXSRC Position        */
#define SIM_SOPT5_LPUART0RXSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART0RXSRC_SHIFT))&SIM_SOPT5_LPUART0RXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_LPUART1TXSRC_MASK              (0x30U)                                             /*!< SIM_SOPT5: LPUART1TXSRC Mask            */
#define SIM_SOPT5_LPUART1TXSRC_SHIFT             (4U)                                                /*!< SIM_SOPT5: LPUART1TXSRC Position        */
#define SIM_SOPT5_LPUART1TXSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART1TXSRC_SHIFT))&SIM_SOPT5_LPUART1TXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_LPUART1RXSRC_MASK              (0x40U)                                             /*!< SIM_SOPT5: LPUART1RXSRC Mask            */
#define SIM_SOPT5_LPUART1RXSRC_SHIFT             (6U)                                                /*!< SIM_SOPT5: LPUART1RXSRC Position        */
#define SIM_SOPT5_LPUART1RXSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART1RXSRC_SHIFT))&SIM_SOPT5_LPUART1RXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_LPUART0ODE_MASK                (0x10000U)                                          /*!< SIM_SOPT5: LPUART0ODE Mask              */
#define SIM_SOPT5_LPUART0ODE_SHIFT               (16U)                                               /*!< SIM_SOPT5: LPUART0ODE Position          */
#define SIM_SOPT5_LPUART0ODE(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART0ODE_SHIFT))&SIM_SOPT5_LPUART0ODE_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_LPUART1ODE_MASK                (0x20000U)                                          /*!< SIM_SOPT5: LPUART1ODE Mask              */
#define SIM_SOPT5_LPUART1ODE_SHIFT               (17U)                                               /*!< SIM_SOPT5: LPUART1ODE Position          */
#define SIM_SOPT5_LPUART1ODE(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART1ODE_SHIFT))&SIM_SOPT5_LPUART1ODE_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART2ODE_MASK                  (0x40000U)                                          /*!< SIM_SOPT5: UART2ODE Mask                */
#define SIM_SOPT5_UART2ODE_SHIFT                 (18U)                                               /*!< SIM_SOPT5: UART2ODE Position            */
#define SIM_SOPT5_UART2ODE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART2ODE_SHIFT))&SIM_SOPT5_UART2ODE_MASK) /*!< SIM_SOPT5                               */
/* ------- SOPT7 Bit Fields                         ------ */
#define SIM_SOPT7_ADC0TRGSEL_MASK                (0xFU)                                              /*!< SIM_SOPT7: ADC0TRGSEL Mask              */
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               (0U)                                                /*!< SIM_SOPT7: ADC0TRGSEL Position          */
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0TRGSEL_SHIFT))&SIM_SOPT7_ADC0TRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             (0x10U)                                             /*!< SIM_SOPT7: ADC0PRETRGSEL Mask           */
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            (4U)                                                /*!< SIM_SOPT7: ADC0PRETRGSEL Position       */
#define SIM_SOPT7_ADC0PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0PRETRGSEL_SHIFT))&SIM_SOPT7_ADC0PRETRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              (0x80U)                                             /*!< SIM_SOPT7: ADC0ALTTRGEN Mask            */
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             (7U)                                                /*!< SIM_SOPT7: ADC0ALTTRGEN Position        */
#define SIM_SOPT7_ADC0ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0ALTTRGEN_SHIFT))&SIM_SOPT7_ADC0ALTTRGEN_MASK) /*!< SIM_SOPT7                               */
/* ------- SDID Bit Fields                          ------ */
#define SIM_SDID_PINID_MASK                      (0xFU)                                              /*!< SIM_SDID: PINID Mask                    */
#define SIM_SDID_PINID_SHIFT                     (0U)                                                /*!< SIM_SDID: PINID Position                */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_REVID_MASK                      (0xF000U)                                           /*!< SIM_SDID: REVID Mask                    */
#define SIM_SDID_REVID_SHIFT                     (12U)                                               /*!< SIM_SDID: REVID Position                */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_SRAMSIZE_MASK                   (0xF0000U)                                          /*!< SIM_SDID: SRAMSIZE Mask                 */
#define SIM_SDID_SRAMSIZE_SHIFT                  (16U)                                               /*!< SIM_SDID: SRAMSIZE Position             */
#define SIM_SDID_SRAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SRAMSIZE_SHIFT))&SIM_SDID_SRAMSIZE_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_SERIESID_MASK                   (0xF00000U)                                         /*!< SIM_SDID: SERIESID Mask                 */
#define SIM_SDID_SERIESID_SHIFT                  (20U)                                               /*!< SIM_SDID: SERIESID Position             */
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SERIESID_SHIFT))&SIM_SDID_SERIESID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)                                        /*!< SIM_SDID: SUBFAMID Mask                 */
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)                                               /*!< SIM_SDID: SUBFAMID Position             */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SUBFAMID_SHIFT))&SIM_SDID_SUBFAMID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_FAMID_MASK                      (0xF0000000U)                                       /*!< SIM_SDID: FAMID Mask                    */
#define SIM_SDID_FAMID_SHIFT                     (28U)                                               /*!< SIM_SDID: FAMID Position                */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK) /*!< SIM_SDID                                */
/* ------- SCGC4 Bit Fields                         ------ */
#define SIM_SCGC4_I2C0_MASK                      (0x40U)                                             /*!< SIM_SCGC4: I2C0 Mask                    */
#define SIM_SCGC4_I2C0_SHIFT                     (6U)                                                /*!< SIM_SCGC4: I2C0 Position                */
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_I2C0_SHIFT))&SIM_SCGC4_I2C0_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_I2C1_MASK                      (0x80U)                                             /*!< SIM_SCGC4: I2C1 Mask                    */
#define SIM_SCGC4_I2C1_SHIFT                     (7U)                                                /*!< SIM_SCGC4: I2C1 Position                */
#define SIM_SCGC4_I2C1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_I2C1_SHIFT))&SIM_SCGC4_I2C1_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART2_MASK                     (0x1000U)                                           /*!< SIM_SCGC4: UART2 Mask                   */
#define SIM_SCGC4_UART2_SHIFT                    (12U)                                               /*!< SIM_SCGC4: UART2 Position               */
#define SIM_SCGC4_UART2(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART2_SHIFT))&SIM_SCGC4_UART2_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_USBFS_MASK                     (0x40000U)                                          /*!< SIM_SCGC4: USBFS Mask                   */
#define SIM_SCGC4_USBFS_SHIFT                    (18U)                                               /*!< SIM_SCGC4: USBFS Position               */
#define SIM_SCGC4_USBFS(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_USBFS_SHIFT))&SIM_SCGC4_USBFS_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_CMP0_MASK                      (0x80000U)                                          /*!< SIM_SCGC4: CMP0 Mask                    */
#define SIM_SCGC4_CMP0_SHIFT                     (19U)                                               /*!< SIM_SCGC4: CMP0 Position                */
#define SIM_SCGC4_CMP0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_CMP0_SHIFT))&SIM_SCGC4_CMP0_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_VREF_MASK                      (0x100000U)                                         /*!< SIM_SCGC4: VREF Mask                    */
#define SIM_SCGC4_VREF_SHIFT                     (20U)                                               /*!< SIM_SCGC4: VREF Position                */
#define SIM_SCGC4_VREF(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_VREF_SHIFT))&SIM_SCGC4_VREF_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_SPI0_MASK                      (0x400000U)                                         /*!< SIM_SCGC4: SPI0 Mask                    */
#define SIM_SCGC4_SPI0_SHIFT                     (22U)                                               /*!< SIM_SCGC4: SPI0 Position                */
#define SIM_SCGC4_SPI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_SPI0_SHIFT))&SIM_SCGC4_SPI0_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_SPI1_MASK                      (0x800000U)                                         /*!< SIM_SCGC4: SPI1 Mask                    */
#define SIM_SCGC4_SPI1_SHIFT                     (23U)                                               /*!< SIM_SCGC4: SPI1 Position                */
#define SIM_SCGC4_SPI1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_SPI1_SHIFT))&SIM_SCGC4_SPI1_MASK) /*!< SIM_SCGC4                               */
/* ------- SCGC5 Bit Fields                         ------ */
#define SIM_SCGC5_LPTMR_MASK                     (0x1U)                                              /*!< SIM_SCGC5: LPTMR Mask                   */
#define SIM_SCGC5_LPTMR_SHIFT                    (0U)                                                /*!< SIM_SCGC5: LPTMR Position               */
#define SIM_SCGC5_LPTMR(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_LPTMR_SHIFT))&SIM_SCGC5_LPTMR_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTA_MASK                     (0x200U)                                            /*!< SIM_SCGC5: PORTA Mask                   */
#define SIM_SCGC5_PORTA_SHIFT                    (9U)                                                /*!< SIM_SCGC5: PORTA Position               */
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTA_SHIFT))&SIM_SCGC5_PORTA_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTB_MASK                     (0x400U)                                            /*!< SIM_SCGC5: PORTB Mask                   */
#define SIM_SCGC5_PORTB_SHIFT                    (10U)                                               /*!< SIM_SCGC5: PORTB Position               */
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTB_SHIFT))&SIM_SCGC5_PORTB_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTC_MASK                     (0x800U)                                            /*!< SIM_SCGC5: PORTC Mask                   */
#define SIM_SCGC5_PORTC_SHIFT                    (11U)                                               /*!< SIM_SCGC5: PORTC Position               */
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTC_SHIFT))&SIM_SCGC5_PORTC_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)                                           /*!< SIM_SCGC5: PORTD Mask                   */
#define SIM_SCGC5_PORTD_SHIFT                    (12U)                                               /*!< SIM_SCGC5: PORTD Position               */
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTD_SHIFT))&SIM_SCGC5_PORTD_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)                                           /*!< SIM_SCGC5: PORTE Mask                   */
#define SIM_SCGC5_PORTE_SHIFT                    (13U)                                               /*!< SIM_SCGC5: PORTE Position               */
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTE_SHIFT))&SIM_SCGC5_PORTE_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_SLCD_MASK                      (0x80000U)                                          /*!< SIM_SCGC5: SLCD Mask                    */
#define SIM_SCGC5_SLCD_SHIFT                     (19U)                                               /*!< SIM_SCGC5: SLCD Position                */
#define SIM_SCGC5_SLCD(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_SLCD_SHIFT))&SIM_SCGC5_SLCD_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_LPUART0_MASK                   (0x100000U)                                         /*!< SIM_SCGC5: LPUART0 Mask                 */
#define SIM_SCGC5_LPUART0_SHIFT                  (20U)                                               /*!< SIM_SCGC5: LPUART0 Position             */
#define SIM_SCGC5_LPUART0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_LPUART0_SHIFT))&SIM_SCGC5_LPUART0_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_LPUART1_MASK                   (0x200000U)                                         /*!< SIM_SCGC5: LPUART1 Mask                 */
#define SIM_SCGC5_LPUART1_SHIFT                  (21U)                                               /*!< SIM_SCGC5: LPUART1 Position             */
#define SIM_SCGC5_LPUART1(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_LPUART1_SHIFT))&SIM_SCGC5_LPUART1_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_FLEXIO_MASK                    (0x80000000U)                                       /*!< SIM_SCGC5: FLEXIO Mask                  */
#define SIM_SCGC5_FLEXIO_SHIFT                   (31U)                                               /*!< SIM_SCGC5: FLEXIO Position              */
#define SIM_SCGC5_FLEXIO(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_FLEXIO_SHIFT))&SIM_SCGC5_FLEXIO_MASK) /*!< SIM_SCGC5                               */
/* ------- SCGC6 Bit Fields                         ------ */
#define SIM_SCGC6_FTF_MASK                       (0x1U)                                              /*!< SIM_SCGC6: FTF Mask                     */
#define SIM_SCGC6_FTF_SHIFT                      (0U)                                                /*!< SIM_SCGC6: FTF Position                 */
#define SIM_SCGC6_FTF(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTF_SHIFT))&SIM_SCGC6_FTF_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x2U)                                              /*!< SIM_SCGC6: DMAMUX0 Mask                 */
#define SIM_SCGC6_DMAMUX0_SHIFT                  (1U)                                                /*!< SIM_SCGC6: DMAMUX0 Position             */
#define SIM_SCGC6_DMAMUX0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DMAMUX0_SHIFT))&SIM_SCGC6_DMAMUX0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_I2S_MASK                       (0x8000U)                                           /*!< SIM_SCGC6: I2S Mask                     */
#define SIM_SCGC6_I2S_SHIFT                      (15U)                                               /*!< SIM_SCGC6: I2S Position                 */
#define SIM_SCGC6_I2S(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_I2S_SHIFT))&SIM_SCGC6_I2S_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PIT_MASK                       (0x800000U)                                         /*!< SIM_SCGC6: PIT Mask                     */
#define SIM_SCGC6_PIT_SHIFT                      (23U)                                               /*!< SIM_SCGC6: PIT Position                 */
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PIT_SHIFT))&SIM_SCGC6_PIT_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_TPM0_MASK                      (0x1000000U)                                        /*!< SIM_SCGC6: TPM0 Mask                    */
#define SIM_SCGC6_TPM0_SHIFT                     (24U)                                               /*!< SIM_SCGC6: TPM0 Position                */
#define SIM_SCGC6_TPM0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TPM0_SHIFT))&SIM_SCGC6_TPM0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_TPM1_MASK                      (0x2000000U)                                        /*!< SIM_SCGC6: TPM1 Mask                    */
#define SIM_SCGC6_TPM1_SHIFT                     (25U)                                               /*!< SIM_SCGC6: TPM1 Position                */
#define SIM_SCGC6_TPM1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TPM1_SHIFT))&SIM_SCGC6_TPM1_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_TPM2_MASK                      (0x4000000U)                                        /*!< SIM_SCGC6: TPM2 Mask                    */
#define SIM_SCGC6_TPM2_SHIFT                     (26U)                                               /*!< SIM_SCGC6: TPM2 Position                */
#define SIM_SCGC6_TPM2(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TPM2_SHIFT))&SIM_SCGC6_TPM2_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)                                        /*!< SIM_SCGC6: ADC0 Mask                    */
#define SIM_SCGC6_ADC0_SHIFT                     (27U)                                               /*!< SIM_SCGC6: ADC0 Position                */
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC0_SHIFT))&SIM_SCGC6_ADC0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_RTC_MASK                       (0x20000000U)                                       /*!< SIM_SCGC6: RTC Mask                     */
#define SIM_SCGC6_RTC_SHIFT                      (29U)                                               /*!< SIM_SCGC6: RTC Position                 */
#define SIM_SCGC6_RTC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_RTC_SHIFT))&SIM_SCGC6_RTC_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_DAC0_MASK                      (0x80000000U)                                       /*!< SIM_SCGC6: DAC0 Mask                    */
#define SIM_SCGC6_DAC0_SHIFT                     (31U)                                               /*!< SIM_SCGC6: DAC0 Position                */
#define SIM_SCGC6_DAC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DAC0_SHIFT))&SIM_SCGC6_DAC0_MASK) /*!< SIM_SCGC6                               */
/* ------- SCGC7 Bit Fields                         ------ */
#define SIM_SCGC7_DMA_MASK                       (0x100U)                                            /*!< SIM_SCGC7: DMA Mask                     */
#define SIM_SCGC7_DMA_SHIFT                      (8U)                                                /*!< SIM_SCGC7: DMA Position                 */
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC7_DMA_SHIFT))&SIM_SCGC7_DMA_MASK) /*!< SIM_SCGC7                               */
/* ------- CLKDIV1 Bit Fields                       ------ */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0x70000U)                                          /*!< SIM_CLKDIV1: OUTDIV4 Mask               */
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)                                               /*!< SIM_CLKDIV1: OUTDIV4 Position           */
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV4_SHIFT))&SIM_CLKDIV1_OUTDIV4_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)                                       /*!< SIM_CLKDIV1: OUTDIV1 Mask               */
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)                                               /*!< SIM_CLKDIV1: OUTDIV1 Position           */
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV1_SHIFT))&SIM_CLKDIV1_OUTDIV1_MASK) /*!< SIM_CLKDIV1                             */
/* ------- FCFG1 Bit Fields                         ------ */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)                                              /*!< SIM_FCFG1: FLASHDIS Mask                */
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)                                                /*!< SIM_FCFG1: FLASHDIS Position            */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDIS_SHIFT))&SIM_FCFG1_FLASHDIS_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)                                              /*!< SIM_FCFG1: FLASHDOZE Mask               */
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)                                                /*!< SIM_FCFG1: FLASHDOZE Position           */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDOZE_SHIFT))&SIM_FCFG1_FLASHDOZE_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)                                        /*!< SIM_FCFG1: PFSIZE Mask                  */
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)                                               /*!< SIM_FCFG1: PFSIZE Position              */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK) /*!< SIM_FCFG1                               */
/* ------- FCFG2 Bit Fields                         ------ */
#define SIM_FCFG2_MAXADDR1_MASK                  (0x7F0000U)                                         /*!< SIM_FCFG2: MAXADDR1 Mask                */
#define SIM_FCFG2_MAXADDR1_SHIFT                 (16U)                                               /*!< SIM_FCFG2: MAXADDR1 Position            */
#define SIM_FCFG2_MAXADDR1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR1_SHIFT))&SIM_FCFG2_MAXADDR1_MASK) /*!< SIM_FCFG2                               */
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)                                       /*!< SIM_FCFG2: MAXADDR0 Mask                */
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)                                               /*!< SIM_FCFG2: MAXADDR0 Position            */
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR0_SHIFT))&SIM_FCFG2_MAXADDR0_MASK) /*!< SIM_FCFG2                               */
/* ------- UIDMH Bit Fields                         ------ */
#define SIM_UIDMH_UID_MASK                       (0xFFFFU)                                           /*!< SIM_UIDMH: UID Mask                     */
#define SIM_UIDMH_UID_SHIFT                      (0U)                                                /*!< SIM_UIDMH: UID Position                 */
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK) /*!< SIM_UIDMH                               */
/* ------- UIDML Bit Fields                         ------ */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDML: UID Mask                     */
#define SIM_UIDML_UID_SHIFT                      (0U)                                                /*!< SIM_UIDML: UID Position                 */
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK) /*!< SIM_UIDML                               */
/* ------- UIDL Bit Fields                          ------ */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDL: UID Mask                      */
#define SIM_UIDL_UID_SHIFT                       (0U)                                                /*!< SIM_UIDL: UID Position                  */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK) /*!< SIM_UIDL                                */
/* ------- COPC Bit Fields                          ------ */
#define SIM_COPC_COPW_MASK                       (0x1U)                                              /*!< SIM_COPC: COPW Mask                     */
#define SIM_COPC_COPW_SHIFT                      (0U)                                                /*!< SIM_COPC: COPW Position                 */
#define SIM_COPC_COPW(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPW_SHIFT))&SIM_COPC_COPW_MASK) /*!< SIM_COPC                                */
#define SIM_COPC_COPCLKS_MASK                    (0x2U)                                              /*!< SIM_COPC: COPCLKS Mask                  */
#define SIM_COPC_COPCLKS_SHIFT                   (1U)                                                /*!< SIM_COPC: COPCLKS Position              */
#define SIM_COPC_COPCLKS(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPCLKS_SHIFT))&SIM_COPC_COPCLKS_MASK) /*!< SIM_COPC                                */
#define SIM_COPC_COPT_MASK                       (0xCU)                                              /*!< SIM_COPC: COPT Mask                     */
#define SIM_COPC_COPT_SHIFT                      (2U)                                                /*!< SIM_COPC: COPT Position                 */
#define SIM_COPC_COPT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPT_SHIFT))&SIM_COPC_COPT_MASK) /*!< SIM_COPC                                */
#define SIM_COPC_COPSTPEN_MASK                   (0x10U)                                             /*!< SIM_COPC: COPSTPEN Mask                 */
#define SIM_COPC_COPSTPEN_SHIFT                  (4U)                                                /*!< SIM_COPC: COPSTPEN Position             */
#define SIM_COPC_COPSTPEN(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPSTPEN_SHIFT))&SIM_COPC_COPSTPEN_MASK) /*!< SIM_COPC                                */
#define SIM_COPC_COPDBGEN_MASK                   (0x20U)                                             /*!< SIM_COPC: COPDBGEN Mask                 */
#define SIM_COPC_COPDBGEN_SHIFT                  (5U)                                                /*!< SIM_COPC: COPDBGEN Position             */
#define SIM_COPC_COPDBGEN(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPDBGEN_SHIFT))&SIM_COPC_COPDBGEN_MASK) /*!< SIM_COPC                                */
#define SIM_COPC_COPCLKSEL_MASK                  (0xC0U)                                             /*!< SIM_COPC: COPCLKSEL Mask                */
#define SIM_COPC_COPCLKSEL_SHIFT                 (6U)                                                /*!< SIM_COPC: COPCLKSEL Position            */
#define SIM_COPC_COPCLKSEL(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPCLKSEL_SHIFT))&SIM_COPC_COPCLKSEL_MASK) /*!< SIM_COPC                                */
/* ------- SRVCOP Bit Fields                        ------ */
#define SIM_SRVCOP_SRVCOP_MASK                   (0xFFU)                                             /*!< SIM_SRVCOP: SRVCOP Mask                 */
#define SIM_SRVCOP_SRVCOP_SHIFT                  (0U)                                                /*!< SIM_SRVCOP: SRVCOP Position             */
#define SIM_SRVCOP_SRVCOP(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SRVCOP_SRVCOP_SHIFT))&SIM_SRVCOP_SRVCOP_MASK) /*!< SIM_SRVCOP                              */
/**
 * @} */ /* End group SIM_Register_Masks_GROUP 
 */

/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0x40047000UL //!< Peripheral base address
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
/* ================           SMC (file:SMC_MKL04Z4)               ================ */
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
   __IO uint8_t   STOPCTRL;                     /**< 0002: Stop Control Register                                        */
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
#define SMC_PMPROT_AVLLS_MASK                    (0x2U)                                              /*!< SMC_PMPROT: AVLLS Mask                  */
#define SMC_PMPROT_AVLLS_SHIFT                   (1U)                                                /*!< SMC_PMPROT: AVLLS Position              */
#define SMC_PMPROT_AVLLS(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLLS_SHIFT))&SMC_PMPROT_AVLLS_MASK) /*!< SMC_PMPROT                              */
#define SMC_PMPROT_ALLS_MASK                     (0x8U)                                              /*!< SMC_PMPROT: ALLS Mask                   */
#define SMC_PMPROT_ALLS_SHIFT                    (3U)                                                /*!< SMC_PMPROT: ALLS Position               */
#define SMC_PMPROT_ALLS(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_ALLS_SHIFT))&SMC_PMPROT_ALLS_MASK) /*!< SMC_PMPROT                              */
#define SMC_PMPROT_AVLP_MASK                     (0x20U)                                             /*!< SMC_PMPROT: AVLP Mask                   */
#define SMC_PMPROT_AVLP_SHIFT                    (5U)                                                /*!< SMC_PMPROT: AVLP Position               */
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLP_SHIFT))&SMC_PMPROT_AVLP_MASK) /*!< SMC_PMPROT                              */
/* ------- PMCTRL Bit Fields                        ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x7U)                                              /*!< SMC_PMCTRL: STOPM Mask                  */
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)                                                /*!< SMC_PMCTRL: STOPM Position              */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_STOPA_MASK                    (0x8U)                                              /*!< SMC_PMCTRL: STOPA Mask                  */
#define SMC_PMCTRL_STOPA_SHIFT                   (3U)                                                /*!< SMC_PMCTRL: STOPA Position              */
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPA_SHIFT))&SMC_PMCTRL_STOPA_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_RUNM_MASK                     (0x60U)                                             /*!< SMC_PMCTRL: RUNM Mask                   */
#define SMC_PMCTRL_RUNM_SHIFT                    (5U)                                                /*!< SMC_PMCTRL: RUNM Position               */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK) /*!< SMC_PMCTRL                              */
/* ------- STOPCTRL Bit Fields                      ------ */
#define SMC_STOPCTRL_LLSM_MASK                   (0x7U)                                              /*!< SMC_STOPCTRL: LLSM Mask                 */
#define SMC_STOPCTRL_LLSM_SHIFT                  (0U)                                                /*!< SMC_STOPCTRL: LLSM Position             */
#define SMC_STOPCTRL_LLSM(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_LLSM_SHIFT))&SMC_STOPCTRL_LLSM_MASK) /*!< SMC_STOPCTRL                            */
#define SMC_STOPCTRL_VLLSM_MASK                  (0x7U)                                              /*!< SMC_STOPCTRL: VLLSM Mask                */
#define SMC_STOPCTRL_VLLSM_SHIFT                 (0U)                                                /*!< SMC_STOPCTRL: VLLSM Position            */
#define SMC_STOPCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_VLLSM_SHIFT))&SMC_STOPCTRL_VLLSM_MASK) /*!< SMC_STOPCTRL                            */
#define SMC_STOPCTRL_PORPO_MASK                  (0x20U)                                             /*!< SMC_STOPCTRL: PORPO Mask                */
#define SMC_STOPCTRL_PORPO_SHIFT                 (5U)                                                /*!< SMC_STOPCTRL: PORPO Position            */
#define SMC_STOPCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PORPO_SHIFT))&SMC_STOPCTRL_PORPO_MASK) /*!< SMC_STOPCTRL                            */
#define SMC_STOPCTRL_PSTOPO_MASK                 (0xC0U)                                             /*!< SMC_STOPCTRL: PSTOPO Mask               */
#define SMC_STOPCTRL_PSTOPO_SHIFT                (6U)                                                /*!< SMC_STOPCTRL: PSTOPO Position           */
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PSTOPO_SHIFT))&SMC_STOPCTRL_PSTOPO_MASK) /*!< SMC_STOPCTRL                            */
/* ------- PMSTAT Bit Fields                        ------ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0xFFU)                                             /*!< SMC_PMSTAT: PMSTAT Mask                 */
#define SMC_PMSTAT_PMSTAT_SHIFT                  (0U)                                                /*!< SMC_PMSTAT: PMSTAT Position             */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK) /*!< SMC_PMSTAT                              */
/**
 * @} */ /* End group SMC_Register_Masks_GROUP 
 */

/* SMC - Peripheral instance base addresses */
#define SMC_BasePtr                    0x4007E000UL //!< Peripheral base address
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
/* ================           SPI0 (file:SPI0_MKL_16Bit)           ================ */
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
   __I  uint8_t   S;                            /**< 0000: Status register                                              */
   __IO uint8_t   BR;                           /**< 0001: Baud rate register                                           */
   __IO uint8_t   C2;                           /**< 0002: Control register 2                                           */
   __IO uint8_t   C1;                           /**< 0003: Control register 1                                           */
   __IO uint8_t   ML;                           /**< 0004: Match register low                                           */
   __IO uint8_t   MH;                           /**< 0005: Match register high                                          */
   __IO uint8_t   DL;                           /**< 0006: Data register low                                            */
   __IO uint8_t   DH;                           /**< 0007: Data register high                                           */
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   CI;                           /**< 000A: Clear interrupt register                                     */
   __IO uint8_t   C3;                           /**< 000B: Control register 3                                           */
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
/* ------- S Bit Fields                             ------ */
#define SPI_S_RFIFOEF_MASK                       (0x1U)                                              /*!< SPI0_S: RFIFOEF Mask                    */
#define SPI_S_RFIFOEF_SHIFT                      (0U)                                                /*!< SPI0_S: RFIFOEF Position                */
#define SPI_S_RFIFOEF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_RFIFOEF_SHIFT))&SPI_S_RFIFOEF_MASK) /*!< SPI0_S                                  */
#define SPI_S_TXFULLF_MASK                       (0x2U)                                              /*!< SPI0_S: TXFULLF Mask                    */
#define SPI_S_TXFULLF_SHIFT                      (1U)                                                /*!< SPI0_S: TXFULLF Position                */
#define SPI_S_TXFULLF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_TXFULLF_SHIFT))&SPI_S_TXFULLF_MASK) /*!< SPI0_S                                  */
#define SPI_S_TNEAREF_MASK                       (0x4U)                                              /*!< SPI0_S: TNEAREF Mask                    */
#define SPI_S_TNEAREF_SHIFT                      (2U)                                                /*!< SPI0_S: TNEAREF Position                */
#define SPI_S_TNEAREF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_TNEAREF_SHIFT))&SPI_S_TNEAREF_MASK) /*!< SPI0_S                                  */
#define SPI_S_RNFULLF_MASK                       (0x8U)                                              /*!< SPI0_S: RNFULLF Mask                    */
#define SPI_S_RNFULLF_SHIFT                      (3U)                                                /*!< SPI0_S: RNFULLF Position                */
#define SPI_S_RNFULLF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_RNFULLF_SHIFT))&SPI_S_RNFULLF_MASK) /*!< SPI0_S                                  */
#define SPI_S_MODF_MASK                          (0x10U)                                             /*!< SPI0_S: MODF Mask                       */
#define SPI_S_MODF_SHIFT                         (4U)                                                /*!< SPI0_S: MODF Position                   */
#define SPI_S_MODF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_MODF_SHIFT))&SPI_S_MODF_MASK) /*!< SPI0_S                                  */
#define SPI_S_SPTEF_MASK                         (0x20U)                                             /*!< SPI0_S: SPTEF Mask                      */
#define SPI_S_SPTEF_SHIFT                        (5U)                                                /*!< SPI0_S: SPTEF Position                  */
#define SPI_S_SPTEF(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_S_SPTEF_SHIFT))&SPI_S_SPTEF_MASK) /*!< SPI0_S                                  */
#define SPI_S_SPMF_MASK                          (0x40U)                                             /*!< SPI0_S: SPMF Mask                       */
#define SPI_S_SPMF_SHIFT                         (6U)                                                /*!< SPI0_S: SPMF Position                   */
#define SPI_S_SPMF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_SPMF_SHIFT))&SPI_S_SPMF_MASK) /*!< SPI0_S                                  */
#define SPI_S_SPRF_MASK                          (0x80U)                                             /*!< SPI0_S: SPRF Mask                       */
#define SPI_S_SPRF_SHIFT                         (7U)                                                /*!< SPI0_S: SPRF Position                   */
#define SPI_S_SPRF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_SPRF_SHIFT))&SPI_S_SPRF_MASK) /*!< SPI0_S                                  */
/* ------- BR Bit Fields                            ------ */
#define SPI_BR_SPR_MASK                          (0xFU)                                              /*!< SPI0_BR: SPR Mask                       */
#define SPI_BR_SPR_SHIFT                         (0U)                                                /*!< SPI0_BR: SPR Position                   */
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK) /*!< SPI0_BR                                 */
#define SPI_BR_SPPR_MASK                         (0x70U)                                             /*!< SPI0_BR: SPPR Mask                      */
#define SPI_BR_SPPR_SHIFT                        (4U)                                                /*!< SPI0_BR: SPPR Position                  */
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK) /*!< SPI0_BR                                 */
/* ------- C2 Bit Fields                            ------ */
#define SPI_C2_SPC0_MASK                         (0x1U)                                              /*!< SPI0_C2: SPC0 Mask                      */
#define SPI_C2_SPC0_SHIFT                        (0U)                                                /*!< SPI0_C2: SPC0 Position                  */
#define SPI_C2_SPC0(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPC0_SHIFT))&SPI_C2_SPC0_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_SPISWAI_MASK                      (0x2U)                                              /*!< SPI0_C2: SPISWAI Mask                   */
#define SPI_C2_SPISWAI_SHIFT                     (1U)                                                /*!< SPI0_C2: SPISWAI Position               */
#define SPI_C2_SPISWAI(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPISWAI_SHIFT))&SPI_C2_SPISWAI_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_RXDMAE_MASK                       (0x4U)                                              /*!< SPI0_C2: RXDMAE Mask                    */
#define SPI_C2_RXDMAE_SHIFT                      (2U)                                                /*!< SPI0_C2: RXDMAE Position                */
#define SPI_C2_RXDMAE(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_RXDMAE_SHIFT))&SPI_C2_RXDMAE_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_BIDIROE_MASK                      (0x8U)                                              /*!< SPI0_C2: BIDIROE Mask                   */
#define SPI_C2_BIDIROE_SHIFT                     (3U)                                                /*!< SPI0_C2: BIDIROE Position               */
#define SPI_C2_BIDIROE(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_BIDIROE_SHIFT))&SPI_C2_BIDIROE_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_MODFEN_MASK                       (0x10U)                                             /*!< SPI0_C2: MODFEN Mask                    */
#define SPI_C2_MODFEN_SHIFT                      (4U)                                                /*!< SPI0_C2: MODFEN Position                */
#define SPI_C2_MODFEN(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_MODFEN_SHIFT))&SPI_C2_MODFEN_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_TXDMAE_MASK                       (0x20U)                                             /*!< SPI0_C2: TXDMAE Mask                    */
#define SPI_C2_TXDMAE_SHIFT                      (5U)                                                /*!< SPI0_C2: TXDMAE Position                */
#define SPI_C2_TXDMAE(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_TXDMAE_SHIFT))&SPI_C2_TXDMAE_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_SPIMODE_MASK                      (0x40U)                                             /*!< SPI0_C2: SPIMODE Mask                   */
#define SPI_C2_SPIMODE_SHIFT                     (6U)                                                /*!< SPI0_C2: SPIMODE Position               */
#define SPI_C2_SPIMODE(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPIMODE_SHIFT))&SPI_C2_SPIMODE_MASK) /*!< SPI0_C2                                 */
#define SPI_C2_SPMIE_MASK                        (0x80U)                                             /*!< SPI0_C2: SPMIE Mask                     */
#define SPI_C2_SPMIE_SHIFT                       (7U)                                                /*!< SPI0_C2: SPMIE Position                 */
#define SPI_C2_SPMIE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPMIE_SHIFT))&SPI_C2_SPMIE_MASK) /*!< SPI0_C2                                 */
/* ------- C1 Bit Fields                            ------ */
#define SPI_C1_LSBFE_MASK                        (0x1U)                                              /*!< SPI0_C1: LSBFE Mask                     */
#define SPI_C1_LSBFE_SHIFT                       (0U)                                                /*!< SPI0_C1: LSBFE Position                 */
#define SPI_C1_LSBFE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C1_LSBFE_SHIFT))&SPI_C1_LSBFE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_SSOE_MASK                         (0x2U)                                              /*!< SPI0_C1: SSOE Mask                      */
#define SPI_C1_SSOE_SHIFT                        (1U)                                                /*!< SPI0_C1: SSOE Position                  */
#define SPI_C1_SSOE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_SSOE_SHIFT))&SPI_C1_SSOE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_MODE_MASK                         (0xCU)                                              /*!< SPI0_C1: MODE Mask                      */
#define SPI_C1_MODE_SHIFT                        (2U)                                                /*!< SPI0_C1: MODE Position                  */
#define SPI_C1_MODE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_MODE_SHIFT))&SPI_C1_MODE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_CPHA_MASK                         (0x4U)                                              /*!< SPI0_C1: CPHA Mask                      */
#define SPI_C1_CPHA_SHIFT                        (2U)                                                /*!< SPI0_C1: CPHA Position                  */
#define SPI_C1_CPHA(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_CPHA_SHIFT))&SPI_C1_CPHA_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_CPOL_MASK                         (0x8U)                                              /*!< SPI0_C1: CPOL Mask                      */
#define SPI_C1_CPOL_SHIFT                        (3U)                                                /*!< SPI0_C1: CPOL Position                  */
#define SPI_C1_CPOL(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_CPOL_SHIFT))&SPI_C1_CPOL_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_MSTR_MASK                         (0x10U)                                             /*!< SPI0_C1: MSTR Mask                      */
#define SPI_C1_MSTR_SHIFT                        (4U)                                                /*!< SPI0_C1: MSTR Position                  */
#define SPI_C1_MSTR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_MSTR_SHIFT))&SPI_C1_MSTR_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_SPTIE_MASK                        (0x20U)                                             /*!< SPI0_C1: SPTIE Mask                     */
#define SPI_C1_SPTIE_SHIFT                       (5U)                                                /*!< SPI0_C1: SPTIE Position                 */
#define SPI_C1_SPTIE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPTIE_SHIFT))&SPI_C1_SPTIE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_SPE_MASK                          (0x40U)                                             /*!< SPI0_C1: SPE Mask                       */
#define SPI_C1_SPE_SHIFT                         (6U)                                                /*!< SPI0_C1: SPE Position                   */
#define SPI_C1_SPE(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPE_SHIFT))&SPI_C1_SPE_MASK) /*!< SPI0_C1                                 */
#define SPI_C1_SPIE_MASK                         (0x80U)                                             /*!< SPI0_C1: SPIE Mask                      */
#define SPI_C1_SPIE_SHIFT                        (7U)                                                /*!< SPI0_C1: SPIE Position                  */
#define SPI_C1_SPIE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPIE_SHIFT))&SPI_C1_SPIE_MASK) /*!< SPI0_C1                                 */
/* ------- ML Bit Fields                            ------ */
#define SPI_ML_Bits_MASK                         (0xFFU)                                             /*!< SPI0_ML: Bits Mask                      */
#define SPI_ML_Bits_SHIFT                        (0U)                                                /*!< SPI0_ML: Bits Position                  */
#define SPI_ML_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_ML_Bits_SHIFT))&SPI_ML_Bits_MASK) /*!< SPI0_ML                                 */
/* ------- MH Bit Fields                            ------ */
#define SPI_MH_Bits_MASK                         (0xFFU)                                             /*!< SPI0_MH: Bits Mask                      */
#define SPI_MH_Bits_SHIFT                        (0U)                                                /*!< SPI0_MH: Bits Position                  */
#define SPI_MH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_MH_Bits_SHIFT))&SPI_MH_Bits_MASK) /*!< SPI0_MH                                 */
/* ------- DL Bit Fields                            ------ */
#define SPI_DL_Bits_MASK                         (0xFFU)                                             /*!< SPI0_DL: Bits Mask                      */
#define SPI_DL_Bits_SHIFT                        (0U)                                                /*!< SPI0_DL: Bits Position                  */
#define SPI_DL_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DL_Bits_SHIFT))&SPI_DL_Bits_MASK) /*!< SPI0_DL                                 */
/* ------- DH Bit Fields                            ------ */
#define SPI_DH_Bits_MASK                         (0xFFU)                                             /*!< SPI0_DH: Bits Mask                      */
#define SPI_DH_Bits_SHIFT                        (0U)                                                /*!< SPI0_DH: Bits Position                  */
#define SPI_DH_Bits(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_DH_Bits_SHIFT))&SPI_DH_Bits_MASK) /*!< SPI0_DH                                 */
/* ------- CI Bit Fields                            ------ */
#define SPI_CI_SPRFCI_MASK                       (0x1U)                                              /*!< SPI0_CI: SPRFCI Mask                    */
#define SPI_CI_SPRFCI_SHIFT                      (0U)                                                /*!< SPI0_CI: SPRFCI Position                */
#define SPI_CI_SPRFCI(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_SPRFCI_SHIFT))&SPI_CI_SPRFCI_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_SPTEFCI_MASK                      (0x2U)                                              /*!< SPI0_CI: SPTEFCI Mask                   */
#define SPI_CI_SPTEFCI_SHIFT                     (1U)                                                /*!< SPI0_CI: SPTEFCI Position               */
#define SPI_CI_SPTEFCI(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_CI_SPTEFCI_SHIFT))&SPI_CI_SPTEFCI_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_RNFULLFCI_MASK                    (0x4U)                                              /*!< SPI0_CI: RNFULLFCI Mask                 */
#define SPI_CI_RNFULLFCI_SHIFT                   (2U)                                                /*!< SPI0_CI: RNFULLFCI Position             */
#define SPI_CI_RNFULLFCI(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_CI_RNFULLFCI_SHIFT))&SPI_CI_RNFULLFCI_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_TNEAREFCI_MASK                    (0x8U)                                              /*!< SPI0_CI: TNEAREFCI Mask                 */
#define SPI_CI_TNEAREFCI_SHIFT                   (3U)                                                /*!< SPI0_CI: TNEAREFCI Position             */
#define SPI_CI_TNEAREFCI(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_CI_TNEAREFCI_SHIFT))&SPI_CI_TNEAREFCI_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_RXFOF_MASK                        (0x10U)                                             /*!< SPI0_CI: RXFOF Mask                     */
#define SPI_CI_RXFOF_SHIFT                       (4U)                                                /*!< SPI0_CI: RXFOF Position                 */
#define SPI_CI_RXFOF(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_CI_RXFOF_SHIFT))&SPI_CI_RXFOF_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_TXFOF_MASK                        (0x20U)                                             /*!< SPI0_CI: TXFOF Mask                     */
#define SPI_CI_TXFOF_SHIFT                       (5U)                                                /*!< SPI0_CI: TXFOF Position                 */
#define SPI_CI_TXFOF(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_CI_TXFOF_SHIFT))&SPI_CI_TXFOF_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_RXFERR_MASK                       (0x40U)                                             /*!< SPI0_CI: RXFERR Mask                    */
#define SPI_CI_RXFERR_SHIFT                      (6U)                                                /*!< SPI0_CI: RXFERR Position                */
#define SPI_CI_RXFERR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_RXFERR_SHIFT))&SPI_CI_RXFERR_MASK) /*!< SPI0_CI                                 */
#define SPI_CI_TXFERR_MASK                       (0x80U)                                             /*!< SPI0_CI: TXFERR Mask                    */
#define SPI_CI_TXFERR_SHIFT                      (7U)                                                /*!< SPI0_CI: TXFERR Position                */
#define SPI_CI_TXFERR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_TXFERR_SHIFT))&SPI_CI_TXFERR_MASK) /*!< SPI0_CI                                 */
/* ------- C3 Bit Fields                            ------ */
#define SPI_C3_FIFOMODE_MASK                     (0x1U)                                              /*!< SPI0_C3: FIFOMODE Mask                  */
#define SPI_C3_FIFOMODE_SHIFT                    (0U)                                                /*!< SPI0_C3: FIFOMODE Position              */
#define SPI_C3_FIFOMODE(x)                       (((uint8_t)(((uint8_t)(x))<<SPI_C3_FIFOMODE_SHIFT))&SPI_C3_FIFOMODE_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_RNFULLIEN_MASK                    (0x2U)                                              /*!< SPI0_C3: RNFULLIEN Mask                 */
#define SPI_C3_RNFULLIEN_SHIFT                   (1U)                                                /*!< SPI0_C3: RNFULLIEN Position             */
#define SPI_C3_RNFULLIEN(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_C3_RNFULLIEN_SHIFT))&SPI_C3_RNFULLIEN_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_TNEARIEN_MASK                     (0x4U)                                              /*!< SPI0_C3: TNEARIEN Mask                  */
#define SPI_C3_TNEARIEN_SHIFT                    (2U)                                                /*!< SPI0_C3: TNEARIEN Position              */
#define SPI_C3_TNEARIEN(x)                       (((uint8_t)(((uint8_t)(x))<<SPI_C3_TNEARIEN_SHIFT))&SPI_C3_TNEARIEN_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_INTCLR_MASK                       (0x8U)                                              /*!< SPI0_C3: INTCLR Mask                    */
#define SPI_C3_INTCLR_SHIFT                      (3U)                                                /*!< SPI0_C3: INTCLR Position                */
#define SPI_C3_INTCLR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C3_INTCLR_SHIFT))&SPI_C3_INTCLR_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_RNFULLF_MARK_MASK                 (0x10U)                                             /*!< SPI0_C3: RNFULLF_MARK Mask              */
#define SPI_C3_RNFULLF_MARK_SHIFT                (4U)                                                /*!< SPI0_C3: RNFULLF_MARK Position          */
#define SPI_C3_RNFULLF_MARK(x)                   (((uint8_t)(((uint8_t)(x))<<SPI_C3_RNFULLF_MARK_SHIFT))&SPI_C3_RNFULLF_MARK_MASK) /*!< SPI0_C3                                 */
#define SPI_C3_TNEAREF_MARK_MASK                 (0x20U)                                             /*!< SPI0_C3: TNEAREF_MARK Mask              */
#define SPI_C3_TNEAREF_MARK_SHIFT                (5U)                                                /*!< SPI0_C3: TNEAREF_MARK Position          */
#define SPI_C3_TNEAREF_MARK(x)                   (((uint8_t)(((uint8_t)(x))<<SPI_C3_TNEAREF_MARK_SHIFT))&SPI_C3_TNEAREF_MARK_MASK) /*!< SPI0_C3                                 */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0x40076000UL //!< Peripheral base address
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
/* ================           SPI1 (derived from SPI0)             ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */

/* SPI1 - Peripheral instance base addresses */
#define SPI1_BasePtr                   0x40077000UL //!< Peripheral base address
#define SPI1                           ((SPI_Type *) SPI1_BasePtr) //!< Freescale base pointer
#define SPI1_BASE_PTR                  (SPI1) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SYST_Peripheral_access_layer_GROUP SYST Peripheral Access Layer
* @brief C Struct for SYST
* @{
*/

/* ================================================================================ */
/* ================           SYST (file:SYST)                     ================ */
/* ================================================================================ */

/**
 * @brief System timer
 */
/**
* @addtogroup SYST_structs_GROUP SYST struct
* @brief Struct for SYST
* @{
*/
typedef struct {                                /*       SYST Structure                                               */
   __IO uint32_t  CSR;                          /**< 0000: Control and Status Register                                  */
   __IO uint32_t  RVR;                          /**< 0004: Reload Value Register                                        */
   __IO uint32_t  CVR;                          /**< 0008: Current Value Register                                       */
   __I  uint32_t  CALIB;                        /**< 000C: Calibration Value Register                                   */
} SYST_Type;

/**
 * @} */ /* End group SYST_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SYST' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SYST_Register_Masks_GROUP SYST Register Masks
* @brief Register Masks for SYST
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define SYST_CSR_ENABLE_MASK                     (0x1U)                                              /*!< SYST_CSR: ENABLE Mask                   */
#define SYST_CSR_ENABLE_SHIFT                    (0U)                                                /*!< SYST_CSR: ENABLE Position               */
#define SYST_CSR_ENABLE(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_CSR_ENABLE_SHIFT))&SYST_CSR_ENABLE_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_TICKINT_MASK                    (0x2U)                                              /*!< SYST_CSR: TICKINT Mask                  */
#define SYST_CSR_TICKINT_SHIFT                   (1U)                                                /*!< SYST_CSR: TICKINT Position              */
#define SYST_CSR_TICKINT(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CSR_TICKINT_SHIFT))&SYST_CSR_TICKINT_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_CLKSOURCE_MASK                  (0x4U)                                              /*!< SYST_CSR: CLKSOURCE Mask                */
#define SYST_CSR_CLKSOURCE_SHIFT                 (2U)                                                /*!< SYST_CSR: CLKSOURCE Position            */
#define SYST_CSR_CLKSOURCE(x)                    (((uint32_t)(((uint32_t)(x))<<SYST_CSR_CLKSOURCE_SHIFT))&SYST_CSR_CLKSOURCE_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_COUNTFLAG_MASK                  (0x10000U)                                          /*!< SYST_CSR: COUNTFLAG Mask                */
#define SYST_CSR_COUNTFLAG_SHIFT                 (16U)                                               /*!< SYST_CSR: COUNTFLAG Position            */
#define SYST_CSR_COUNTFLAG(x)                    (((uint32_t)(((uint32_t)(x))<<SYST_CSR_COUNTFLAG_SHIFT))&SYST_CSR_COUNTFLAG_MASK) /*!< SYST_CSR                                */
/* ------- RVR Bit Fields                           ------ */
#define SYST_RVR_RELOAD_MASK                     (0xFFFFFFU)                                         /*!< SYST_RVR: RELOAD Mask                   */
#define SYST_RVR_RELOAD_SHIFT                    (0U)                                                /*!< SYST_RVR: RELOAD Position               */
#define SYST_RVR_RELOAD(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_RVR_RELOAD_SHIFT))&SYST_RVR_RELOAD_MASK) /*!< SYST_RVR                                */
/* ------- CVR Bit Fields                           ------ */
#define SYST_CVR_CURRENT_MASK                    (0xFFFFFFU)                                         /*!< SYST_CVR: CURRENT Mask                  */
#define SYST_CVR_CURRENT_SHIFT                   (0U)                                                /*!< SYST_CVR: CURRENT Position              */
#define SYST_CVR_CURRENT(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CVR_CURRENT_SHIFT))&SYST_CVR_CURRENT_MASK) /*!< SYST_CVR                                */
/* ------- CALIB Bit Fields                         ------ */
#define SYST_CALIB_TENMS_MASK                    (0xFFFFFFU)                                         /*!< SYST_CALIB: TENMS Mask                  */
#define SYST_CALIB_TENMS_SHIFT                   (0U)                                                /*!< SYST_CALIB: TENMS Position              */
#define SYST_CALIB_TENMS(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_TENMS_SHIFT))&SYST_CALIB_TENMS_MASK) /*!< SYST_CALIB                              */
#define SYST_CALIB_SKEW_MASK                     (0x40000000U)                                       /*!< SYST_CALIB: SKEW Mask                   */
#define SYST_CALIB_SKEW_SHIFT                    (30U)                                               /*!< SYST_CALIB: SKEW Position               */
#define SYST_CALIB_SKEW(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_SKEW_SHIFT))&SYST_CALIB_SKEW_MASK) /*!< SYST_CALIB                              */
#define SYST_CALIB_NOREF_MASK                    (0x80000000U)                                       /*!< SYST_CALIB: NOREF Mask                  */
#define SYST_CALIB_NOREF_SHIFT                   (31U)                                               /*!< SYST_CALIB: NOREF Position              */
#define SYST_CALIB_NOREF(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_NOREF_SHIFT))&SYST_CALIB_NOREF_MASK) /*!< SYST_CALIB                              */
/**
 * @} */ /* End group SYST_Register_Masks_GROUP 
 */

/* SYST - Peripheral instance base addresses */
#define SYST_BasePtr                   0xE000E010UL //!< Peripheral base address
#define SYST                           ((SYST_Type *) SYST_BasePtr) //!< Freescale base pointer
#define SYST_BASE_PTR                  (SYST) //!< Freescale style base pointer
/**
 * @} */ /* End group SYST_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer
* @brief C Struct for TPM
* @{
*/

/* ================================================================================ */
/* ================           TPM0 (file:TPM0_6CH_POL)             ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module (6 channels)
 */
/**
* @addtogroup TPM_structs_GROUP TPM struct
* @brief Struct for TPM
* @{
*/
typedef struct {                                /*       TPM0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[6];                               /**< 000C: (cluster: size=0x0030, 48)                                   */
        uint8_t   RESERVED_1[20];              
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
        uint8_t   RESERVED_2[28];              
   __IO uint32_t  POL;                          /**< 0070: Channel Polarity                                             */
        uint8_t   RESERVED_3[16];              
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
} TPM_Type;

/**
 * @} */ /* End group TPM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TPM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TPM_Register_Masks_GROUP TPM Register Masks
* @brief Register Masks for TPM
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define TPM_SC_PS_MASK                           (0x7U)                                              /*!< TPM0_SC: PS Mask                        */
#define TPM_SC_PS_SHIFT                          (0U)                                                /*!< TPM0_SC: PS Position                    */
#define TPM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<TPM_SC_PS_SHIFT))&TPM_SC_PS_MASK) /*!< TPM0_SC                                 */
#define TPM_SC_CMOD_MASK                         (0x18U)                                             /*!< TPM0_SC: CMOD Mask                      */
#define TPM_SC_CMOD_SHIFT                        (3U)                                                /*!< TPM0_SC: CMOD Position                  */
#define TPM_SC_CMOD(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_SC_CMOD_SHIFT))&TPM_SC_CMOD_MASK) /*!< TPM0_SC                                 */
#define TPM_SC_CPWMS_MASK                        (0x20U)                                             /*!< TPM0_SC: CPWMS Mask                     */
#define TPM_SC_CPWMS_SHIFT                       (5U)                                                /*!< TPM0_SC: CPWMS Position                 */
#define TPM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_SC_CPWMS_SHIFT))&TPM_SC_CPWMS_MASK) /*!< TPM0_SC                                 */
#define TPM_SC_TOIE_MASK                         (0x40U)                                             /*!< TPM0_SC: TOIE Mask                      */
#define TPM_SC_TOIE_SHIFT                        (6U)                                                /*!< TPM0_SC: TOIE Position                  */
#define TPM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_SC_TOIE_SHIFT))&TPM_SC_TOIE_MASK) /*!< TPM0_SC                                 */
#define TPM_SC_TOF_MASK                          (0x80U)                                             /*!< TPM0_SC: TOF Mask                       */
#define TPM_SC_TOF_SHIFT                         (7U)                                                /*!< TPM0_SC: TOF Position                   */
#define TPM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<TPM_SC_TOF_SHIFT))&TPM_SC_TOF_MASK) /*!< TPM0_SC                                 */
#define TPM_SC_DMA_MASK                          (0x100U)                                            /*!< TPM0_SC: DMA Mask                       */
#define TPM_SC_DMA_SHIFT                         (8U)                                                /*!< TPM0_SC: DMA Position                   */
#define TPM_SC_DMA(x)                            (((uint32_t)(((uint32_t)(x))<<TPM_SC_DMA_SHIFT))&TPM_SC_DMA_MASK) /*!< TPM0_SC                                 */
/* ------- CNT Bit Fields                           ------ */
#define TPM_CNT_COUNT_MASK                       (0xFFFFU)                                           /*!< TPM0_CNT: COUNT Mask                    */
#define TPM_CNT_COUNT_SHIFT                      (0U)                                                /*!< TPM0_CNT: COUNT Position                */
#define TPM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CNT_COUNT_SHIFT))&TPM_CNT_COUNT_MASK) /*!< TPM0_CNT                                */
/* ------- MOD Bit Fields                           ------ */
#define TPM_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< TPM0_MOD: MOD Mask                      */
#define TPM_MOD_MOD_SHIFT                        (0U)                                                /*!< TPM0_MOD: MOD Position                  */
#define TPM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_MOD_MOD_SHIFT))&TPM_MOD_MOD_MASK) /*!< TPM0_MOD                                */
/* ------- CnSC Bit Fields                          ------ */
#define TPM_CnSC_DMA_MASK                        (0x1U)                                              /*!< TPM0_CnSC: DMA Mask                     */
#define TPM_CnSC_DMA_SHIFT                       (0U)                                                /*!< TPM0_CnSC: DMA Position                 */
#define TPM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_DMA_SHIFT))&TPM_CnSC_DMA_MASK) /*!< TPM0_CnSC                               */
#define TPM_CnSC_ELS_MASK                        (0xCU)                                              /*!< TPM0_CnSC: ELS Mask                     */
#define TPM_CnSC_ELS_SHIFT                       (2U)                                                /*!< TPM0_CnSC: ELS Position                 */
#define TPM_CnSC_ELS(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_ELS_SHIFT))&TPM_CnSC_ELS_MASK) /*!< TPM0_CnSC                               */
#define TPM_CnSC_ELSA_MASK                       (0x4U)                                              /*!< TPM0_CnSC: ELSA Mask                    */
#define TPM_CnSC_ELSA_SHIFT                      (2U)                                                /*!< TPM0_CnSC: ELSA Position                */
#define TPM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_ELSA_SHIFT))&TPM_CnSC_ELSA_MASK) /*!< TPM0_CnSC                               */
#define TPM_CnSC_ELSB_MASK                       (0x8U)                                              /*!< TPM0_CnSC: ELSB Mask                    */
#define TPM_CnSC_ELSB_SHIFT                      (3U)                                                /*!< TPM0_CnSC: ELSB Position                */
#define TPM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_ELSB_SHIFT))&TPM_CnSC_ELSB_MASK) /*!< TPM0_CnSC                               */
#define TPM_CnSC_MS_MASK                         (0x30U)                                             /*!< TPM0_CnSC: MS Mask                      */
#define TPM_CnSC_MS_SHIFT                        (4U)                                                /*!< TPM0_CnSC: MS Position                  */
#define TPM_CnSC_MS(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_MS_SHIFT))&TPM_CnSC_MS_MASK) /*!< TPM0_CnSC                               */
#define TPM_CnSC_MSA_MASK                        (0x10U)                                             /*!< TPM0_CnSC: MSA Mask                     */
#define TPM_CnSC_MSA_SHIFT                       (4U)                                                /*!< TPM0_CnSC: MSA Position                 */
#define TPM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_MSA_SHIFT))&TPM_CnSC_MSA_MASK) /*!< TPM0_CnSC                               */
#define TPM_CnSC_MSB_MASK                        (0x20U)                                             /*!< TPM0_CnSC: MSB Mask                     */
#define TPM_CnSC_MSB_SHIFT                       (5U)                                                /*!< TPM0_CnSC: MSB Position                 */
#define TPM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_MSB_SHIFT))&TPM_CnSC_MSB_MASK) /*!< TPM0_CnSC                               */
#define TPM_CnSC_CHIE_MASK                       (0x40U)                                             /*!< TPM0_CnSC: CHIE Mask                    */
#define TPM_CnSC_CHIE_SHIFT                      (6U)                                                /*!< TPM0_CnSC: CHIE Position                */
#define TPM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_CHIE_SHIFT))&TPM_CnSC_CHIE_MASK) /*!< TPM0_CnSC                               */
#define TPM_CnSC_CHF_MASK                        (0x80U)                                             /*!< TPM0_CnSC: CHF Mask                     */
#define TPM_CnSC_CHF_SHIFT                       (7U)                                                /*!< TPM0_CnSC: CHF Position                 */
#define TPM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_CHF_SHIFT))&TPM_CnSC_CHF_MASK) /*!< TPM0_CnSC                               */
/* ------- CnV Bit Fields                           ------ */
#define TPM_CnV_VAL_MASK                         (0xFFFFU)                                           /*!< TPM0_CnV: VAL Mask                      */
#define TPM_CnV_VAL_SHIFT                        (0U)                                                /*!< TPM0_CnV: VAL Position                  */
#define TPM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_CnV_VAL_SHIFT))&TPM_CnV_VAL_MASK) /*!< TPM0_CnV                                */
/* ------- STATUS Bit Fields                        ------ */
#define TPM_STATUS_CH0F_MASK                     (0x1U)                                              /*!< TPM0_STATUS: CH0F Mask                  */
#define TPM_STATUS_CH0F_SHIFT                    (0U)                                                /*!< TPM0_STATUS: CH0F Position              */
#define TPM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH0F_SHIFT))&TPM_STATUS_CH0F_MASK) /*!< TPM0_STATUS                             */
#define TPM_STATUS_CH1F_MASK                     (0x2U)                                              /*!< TPM0_STATUS: CH1F Mask                  */
#define TPM_STATUS_CH1F_SHIFT                    (1U)                                                /*!< TPM0_STATUS: CH1F Position              */
#define TPM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH1F_SHIFT))&TPM_STATUS_CH1F_MASK) /*!< TPM0_STATUS                             */
#define TPM_STATUS_CH2F_MASK                     (0x4U)                                              /*!< TPM0_STATUS: CH2F Mask                  */
#define TPM_STATUS_CH2F_SHIFT                    (2U)                                                /*!< TPM0_STATUS: CH2F Position              */
#define TPM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH2F_SHIFT))&TPM_STATUS_CH2F_MASK) /*!< TPM0_STATUS                             */
#define TPM_STATUS_CH3F_MASK                     (0x8U)                                              /*!< TPM0_STATUS: CH3F Mask                  */
#define TPM_STATUS_CH3F_SHIFT                    (3U)                                                /*!< TPM0_STATUS: CH3F Position              */
#define TPM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH3F_SHIFT))&TPM_STATUS_CH3F_MASK) /*!< TPM0_STATUS                             */
#define TPM_STATUS_CH4F_MASK                     (0x10U)                                             /*!< TPM0_STATUS: CH4F Mask                  */
#define TPM_STATUS_CH4F_SHIFT                    (4U)                                                /*!< TPM0_STATUS: CH4F Position              */
#define TPM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH4F_SHIFT))&TPM_STATUS_CH4F_MASK) /*!< TPM0_STATUS                             */
#define TPM_STATUS_CH5F_MASK                     (0x20U)                                             /*!< TPM0_STATUS: CH5F Mask                  */
#define TPM_STATUS_CH5F_SHIFT                    (5U)                                                /*!< TPM0_STATUS: CH5F Position              */
#define TPM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH5F_SHIFT))&TPM_STATUS_CH5F_MASK) /*!< TPM0_STATUS                             */
#define TPM_STATUS_TOF_MASK                      (0x100U)                                            /*!< TPM0_STATUS: TOF Mask                   */
#define TPM_STATUS_TOF_SHIFT                     (8U)                                                /*!< TPM0_STATUS: TOF Position               */
#define TPM_STATUS_TOF(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_TOF_SHIFT))&TPM_STATUS_TOF_MASK) /*!< TPM0_STATUS                             */
/* ------- POL Bit Fields                           ------ */
#define TPM_POL_POL0_MASK                        (0x1U)                                              /*!< TPM0_POL: POL0 Mask                     */
#define TPM_POL_POL0_SHIFT                       (0U)                                                /*!< TPM0_POL: POL0 Position                 */
#define TPM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL0_SHIFT))&TPM_POL_POL0_MASK) /*!< TPM0_POL                                */
#define TPM_POL_POL1_MASK                        (0x2U)                                              /*!< TPM0_POL: POL1 Mask                     */
#define TPM_POL_POL1_SHIFT                       (1U)                                                /*!< TPM0_POL: POL1 Position                 */
#define TPM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL1_SHIFT))&TPM_POL_POL1_MASK) /*!< TPM0_POL                                */
#define TPM_POL_POL2_MASK                        (0x4U)                                              /*!< TPM0_POL: POL2 Mask                     */
#define TPM_POL_POL2_SHIFT                       (2U)                                                /*!< TPM0_POL: POL2 Position                 */
#define TPM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL2_SHIFT))&TPM_POL_POL2_MASK) /*!< TPM0_POL                                */
#define TPM_POL_POL3_MASK                        (0x8U)                                              /*!< TPM0_POL: POL3 Mask                     */
#define TPM_POL_POL3_SHIFT                       (3U)                                                /*!< TPM0_POL: POL3 Position                 */
#define TPM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL3_SHIFT))&TPM_POL_POL3_MASK) /*!< TPM0_POL                                */
#define TPM_POL_POL4_MASK                        (0x10U)                                             /*!< TPM0_POL: POL4 Mask                     */
#define TPM_POL_POL4_SHIFT                       (4U)                                                /*!< TPM0_POL: POL4 Position                 */
#define TPM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL4_SHIFT))&TPM_POL_POL4_MASK) /*!< TPM0_POL                                */
#define TPM_POL_POL5_MASK                        (0x20U)                                             /*!< TPM0_POL: POL5 Mask                     */
#define TPM_POL_POL5_SHIFT                       (5U)                                                /*!< TPM0_POL: POL5 Position                 */
#define TPM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL5_SHIFT))&TPM_POL_POL5_MASK) /*!< TPM0_POL                                */
/* ------- CONF Bit Fields                          ------ */
#define TPM_CONF_DOZEEN_MASK                     (0x20U)                                             /*!< TPM0_CONF: DOZEEN Mask                  */
#define TPM_CONF_DOZEEN_SHIFT                    (5U)                                                /*!< TPM0_CONF: DOZEEN Position              */
#define TPM_CONF_DOZEEN(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_DOZEEN_SHIFT))&TPM_CONF_DOZEEN_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_DBGMODE_MASK                    (0xC0U)                                             /*!< TPM0_CONF: DBGMODE Mask                 */
#define TPM_CONF_DBGMODE_SHIFT                   (6U)                                                /*!< TPM0_CONF: DBGMODE Position             */
#define TPM_CONF_DBGMODE(x)                      (((uint32_t)(((uint32_t)(x))<<TPM_CONF_DBGMODE_SHIFT))&TPM_CONF_DBGMODE_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_GTBSYNC_MASK                    (0x100U)                                            /*!< TPM0_CONF: GTBSYNC Mask                 */
#define TPM_CONF_GTBSYNC_SHIFT                   (8U)                                                /*!< TPM0_CONF: GTBSYNC Position             */
#define TPM_CONF_GTBSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<TPM_CONF_GTBSYNC_SHIFT))&TPM_CONF_GTBSYNC_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_GTBEEN_MASK                     (0x200U)                                            /*!< TPM0_CONF: GTBEEN Mask                  */
#define TPM_CONF_GTBEEN_SHIFT                    (9U)                                                /*!< TPM0_CONF: GTBEEN Position              */
#define TPM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_GTBEEN_SHIFT))&TPM_CONF_GTBEEN_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_CSOT_MASK                       (0x10000U)                                          /*!< TPM0_CONF: CSOT Mask                    */
#define TPM_CONF_CSOT_SHIFT                      (16U)                                               /*!< TPM0_CONF: CSOT Position                */
#define TPM_CONF_CSOT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CSOT_SHIFT))&TPM_CONF_CSOT_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_CSOO_MASK                       (0x20000U)                                          /*!< TPM0_CONF: CSOO Mask                    */
#define TPM_CONF_CSOO_SHIFT                      (17U)                                               /*!< TPM0_CONF: CSOO Position                */
#define TPM_CONF_CSOO(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CSOO_SHIFT))&TPM_CONF_CSOO_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_CROT_MASK                       (0x40000U)                                          /*!< TPM0_CONF: CROT Mask                    */
#define TPM_CONF_CROT_SHIFT                      (18U)                                               /*!< TPM0_CONF: CROT Position                */
#define TPM_CONF_CROT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CROT_SHIFT))&TPM_CONF_CROT_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_CPOT_MASK                       (0x80000U)                                          /*!< TPM0_CONF: CPOT Mask                    */
#define TPM_CONF_CPOT_SHIFT                      (19U)                                               /*!< TPM0_CONF: CPOT Position                */
#define TPM_CONF_CPOT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CPOT_SHIFT))&TPM_CONF_CPOT_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_TRGPOL_MASK                     (0x400000U)                                         /*!< TPM0_CONF: TRGPOL Mask                  */
#define TPM_CONF_TRGPOL_SHIFT                    (22U)                                               /*!< TPM0_CONF: TRGPOL Position              */
#define TPM_CONF_TRGPOL(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGPOL_SHIFT))&TPM_CONF_TRGPOL_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_TRGSRC_MASK                     (0x800000U)                                         /*!< TPM0_CONF: TRGSRC Mask                  */
#define TPM_CONF_TRGSRC_SHIFT                    (23U)                                               /*!< TPM0_CONF: TRGSRC Position              */
#define TPM_CONF_TRGSRC(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGSRC_SHIFT))&TPM_CONF_TRGSRC_MASK) /*!< TPM0_CONF                               */
#define TPM_CONF_TRGSEL_MASK                     (0xF000000U)                                        /*!< TPM0_CONF: TRGSEL Mask                  */
#define TPM_CONF_TRGSEL_SHIFT                    (24U)                                               /*!< TPM0_CONF: TRGSEL Position              */
#define TPM_CONF_TRGSEL(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGSEL_SHIFT))&TPM_CONF_TRGSEL_MASK) /*!< TPM0_CONF                               */
/**
 * @} */ /* End group TPM_Register_Masks_GROUP 
 */

/* TPM0 - Peripheral instance base addresses */
#define TPM0_BasePtr                   0x40038000UL //!< Peripheral base address
#define TPM0                           ((TPM_Type *) TPM0_BasePtr) //!< Freescale base pointer
#define TPM0_BASE_PTR                  (TPM0) //!< Freescale style base pointer
/**
 * @} */ /* End group TPM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer
* @brief C Struct for TPM
* @{
*/

/* ================================================================================ */
/* ================           TPM1 (file:TPM1_2CH_POL)             ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module
 */
/**
* @addtogroup TPM_structs_GROUP TPM struct
* @brief Struct for TPM
* @{
*/
typedef struct {                                /*       TPM1 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[2];                               /**< 000C: (cluster: size=0x0010, 16)                                   */
        uint8_t   RESERVED_1[52];              
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
        uint8_t   RESERVED_2[28];              
   __IO uint32_t  POL;                          /**< 0070: Channel Polarity                                             */
        uint8_t   RESERVED_3[16];              
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
} TPM1_Type;

/**
 * @} */ /* End group TPM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TPM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TPM_Register_Masks_GROUP TPM Register Masks
* @brief Register Masks for TPM
* @{
*/
/* ------- SC Bit Fields                            ------ */
/* ------- CNT Bit Fields                           ------ */
/* ------- MOD Bit Fields                           ------ */
/* ------- CnSC Bit Fields                          ------ */
/* ------- CnV Bit Fields                           ------ */
/* ------- STATUS Bit Fields                        ------ */
/* ------- POL Bit Fields                           ------ */
/* ------- CONF Bit Fields                          ------ */
/**
 * @} */ /* End group TPM_Register_Masks_GROUP 
 */

/* TPM1 - Peripheral instance base addresses */
#define TPM1_BasePtr                   0x40039000UL //!< Peripheral base address
#define TPM1                           ((TPM1_Type *) TPM1_BasePtr) //!< Freescale base pointer
#define TPM1_BASE_PTR                  (TPM1) //!< Freescale style base pointer
/**
 * @} */ /* End group TPM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer
* @brief C Struct for TPM
* @{
*/

/* ================================================================================ */
/* ================           TPM2 (derived from TPM1)             ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module
 */

/* TPM2 - Peripheral instance base addresses */
#define TPM2_BasePtr                   0x4003A000UL //!< Peripheral base address
#define TPM2                           ((TPM1_Type *) TPM2_BasePtr) //!< Freescale base pointer
#define TPM2_BASE_PTR                  (TPM2) //!< Freescale style base pointer
/**
 * @} */ /* End group TPM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART2 (file:UART2_MKL17Z4_C7816)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART2 Structure                                              */
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
        uint8_t   RESERVED_0[12];              
   __IO uint8_t   C7816;                        /**< 0018: 7816 Control Register                                        */
   __IO uint8_t   IE7816;                       /**< 0019: 7816 Interrupt Enable Register                               */
   __IO uint8_t   IS7816;                       /**< 001A: 7816 Interrupt Status Register                               */
   __IO uint8_t   WP7816;                       /**< 001B: 7816 Wait Parameter Register                                 */
   __IO uint8_t   WN7816;                       /**< 001C: 7816 Wait N Register                                         */
   __IO uint8_t   WF7816;                       /**< 001D: 7816 Wait FD Register                                        */
   __IO uint8_t   ET7816;                       /**< 001E: 7816 Error Threshold Register                                */
   __IO uint8_t   TL7816;                       /**< 001F: 7816 Transmit Length Register                                */
        uint8_t   RESERVED_1[26];              
   __IO uint8_t   AP7816A_T0;                   /**< 003A: 7816 ATR Duration Timer Register A                           */
   __IO uint8_t   AP7816B_T0;                   /**< 003B: 7816 ATR Duration Timer Register B                           */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   WP7816A_T0;                /**< 003C: 7816 Wait Parameter Register A                               */
      __IO uint8_t   WP7816A_T1;                /**< 003C: 7816 Wait Parameter Register A                               */
   };
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   WP7816B_T0;                /**< 003D: 7816 Wait Parameter Register B                               */
      __IO uint8_t   WP7816B_T1;                /**< 003D: 7816 Wait Parameter Register B                               */
   };
   __IO uint8_t   WGP7816_T1;                   /**< 003E: 7816 Wait and Guard Parameter Register                       */
   __IO uint8_t   WP7816C_T1;                   /**< 003F: 7816 Wait Parameter Register C                               */
} UART_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART2' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- BDH Bit Fields                           ------ */
#define UART_BDH_SBR_MASK                        (0x1FU)                                             /*!< UART2_BDH: SBR Mask                     */
#define UART_BDH_SBR_SHIFT                       (0U)                                                /*!< UART2_BDH: SBR Position                 */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK) /*!< UART2_BDH                               */
#define UART_BDH_RXEDGIE_MASK                    (0x40U)                                             /*!< UART2_BDH: RXEDGIE Mask                 */
#define UART_BDH_RXEDGIE_SHIFT                   (6U)                                                /*!< UART2_BDH: RXEDGIE Position             */
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_BDH_RXEDGIE_SHIFT))&UART_BDH_RXEDGIE_MASK) /*!< UART2_BDH                               */
/* ------- BDL Bit Fields                           ------ */
#define UART_BDL_SBR_MASK                        (0xFFU)                                             /*!< UART2_BDL: SBR Mask                     */
#define UART_BDL_SBR_SHIFT                       (0U)                                                /*!< UART2_BDL: SBR Position                 */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK) /*!< UART2_BDL                               */
/* ------- C1 Bit Fields                            ------ */
#define UART_C1_PT_MASK                          (0x1U)                                              /*!< UART2_C1: PT Mask                       */
#define UART_C1_PT_SHIFT                         (0U)                                                /*!< UART2_C1: PT Position                   */
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PT_SHIFT))&UART_C1_PT_MASK) /*!< UART2_C1                                */
#define UART_C1_PE_MASK                          (0x2U)                                              /*!< UART2_C1: PE Mask                       */
#define UART_C1_PE_SHIFT                         (1U)                                                /*!< UART2_C1: PE Position                   */
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PE_SHIFT))&UART_C1_PE_MASK) /*!< UART2_C1                                */
#define UART_C1_ILT_MASK                         (0x4U)                                              /*!< UART2_C1: ILT Mask                      */
#define UART_C1_ILT_SHIFT                        (2U)                                                /*!< UART2_C1: ILT Position                  */
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C1_ILT_SHIFT))&UART_C1_ILT_MASK) /*!< UART2_C1                                */
#define UART_C1_WAKE_MASK                        (0x8U)                                              /*!< UART2_C1: WAKE Mask                     */
#define UART_C1_WAKE_SHIFT                       (3U)                                                /*!< UART2_C1: WAKE Position                 */
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_WAKE_SHIFT))&UART_C1_WAKE_MASK) /*!< UART2_C1                                */
#define UART_C1_M_MASK                           (0x10U)                                             /*!< UART2_C1: M Mask                        */
#define UART_C1_M_SHIFT                          (4U)                                                /*!< UART2_C1: M Position                    */
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x))<<UART_C1_M_SHIFT))&UART_C1_M_MASK) /*!< UART2_C1                                */
#define UART_C1_RSRC_MASK                        (0x20U)                                             /*!< UART2_C1: RSRC Mask                     */
#define UART_C1_RSRC_SHIFT                       (5U)                                                /*!< UART2_C1: RSRC Position                 */
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_RSRC_SHIFT))&UART_C1_RSRC_MASK) /*!< UART2_C1                                */
#define UART_C1_LOOPS_MASK                       (0x80U)                                             /*!< UART2_C1: LOOPS Mask                    */
#define UART_C1_LOOPS_SHIFT                      (7U)                                                /*!< UART2_C1: LOOPS Position                */
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C1_LOOPS_SHIFT))&UART_C1_LOOPS_MASK) /*!< UART2_C1                                */
/* ------- C2 Bit Fields                            ------ */
#define UART_C2_SBK_MASK                         (0x1U)                                              /*!< UART2_C2: SBK Mask                      */
#define UART_C2_SBK_SHIFT                        (0U)                                                /*!< UART2_C2: SBK Position                  */
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_SBK_SHIFT))&UART_C2_SBK_MASK) /*!< UART2_C2                                */
#define UART_C2_RWU_MASK                         (0x2U)                                              /*!< UART2_C2: RWU Mask                      */
#define UART_C2_RWU_SHIFT                        (1U)                                                /*!< UART2_C2: RWU Position                  */
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RWU_SHIFT))&UART_C2_RWU_MASK) /*!< UART2_C2                                */
#define UART_C2_RE_MASK                          (0x4U)                                              /*!< UART2_C2: RE Mask                       */
#define UART_C2_RE_SHIFT                         (2U)                                                /*!< UART2_C2: RE Position                   */
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_RE_SHIFT))&UART_C2_RE_MASK) /*!< UART2_C2                                */
#define UART_C2_TE_MASK                          (0x8U)                                              /*!< UART2_C2: TE Mask                       */
#define UART_C2_TE_SHIFT                         (3U)                                                /*!< UART2_C2: TE Position                   */
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_TE_SHIFT))&UART_C2_TE_MASK) /*!< UART2_C2                                */
#define UART_C2_ILIE_MASK                        (0x10U)                                             /*!< UART2_C2: ILIE Mask                     */
#define UART_C2_ILIE_SHIFT                       (4U)                                                /*!< UART2_C2: ILIE Position                 */
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_ILIE_SHIFT))&UART_C2_ILIE_MASK) /*!< UART2_C2                                */
#define UART_C2_RIE_MASK                         (0x20U)                                             /*!< UART2_C2: RIE Mask                      */
#define UART_C2_RIE_SHIFT                        (5U)                                                /*!< UART2_C2: RIE Position                  */
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RIE_SHIFT))&UART_C2_RIE_MASK) /*!< UART2_C2                                */
#define UART_C2_TCIE_MASK                        (0x40U)                                             /*!< UART2_C2: TCIE Mask                     */
#define UART_C2_TCIE_SHIFT                       (6U)                                                /*!< UART2_C2: TCIE Position                 */
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_TCIE_SHIFT))&UART_C2_TCIE_MASK) /*!< UART2_C2                                */
#define UART_C2_TIE_MASK                         (0x80U)                                             /*!< UART2_C2: TIE Mask                      */
#define UART_C2_TIE_SHIFT                        (7U)                                                /*!< UART2_C2: TIE Position                  */
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_TIE_SHIFT))&UART_C2_TIE_MASK) /*!< UART2_C2                                */
/* ------- S1 Bit Fields                            ------ */
#define UART_S1_PF_MASK                          (0x1U)                                              /*!< UART2_S1: PF Mask                       */
#define UART_S1_PF_SHIFT                         (0U)                                                /*!< UART2_S1: PF Position                   */
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_PF_SHIFT))&UART_S1_PF_MASK) /*!< UART2_S1                                */
#define UART_S1_FE_MASK                          (0x2U)                                              /*!< UART2_S1: FE Mask                       */
#define UART_S1_FE_SHIFT                         (1U)                                                /*!< UART2_S1: FE Position                   */
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_FE_SHIFT))&UART_S1_FE_MASK) /*!< UART2_S1                                */
#define UART_S1_NF_MASK                          (0x4U)                                              /*!< UART2_S1: NF Mask                       */
#define UART_S1_NF_SHIFT                         (2U)                                                /*!< UART2_S1: NF Position                   */
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_NF_SHIFT))&UART_S1_NF_MASK) /*!< UART2_S1                                */
#define UART_S1_OR_MASK                          (0x8U)                                              /*!< UART2_S1: OR Mask                       */
#define UART_S1_OR_SHIFT                         (3U)                                                /*!< UART2_S1: OR Position                   */
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_OR_SHIFT))&UART_S1_OR_MASK) /*!< UART2_S1                                */
#define UART_S1_IDLE_MASK                        (0x10U)                                             /*!< UART2_S1: IDLE Mask                     */
#define UART_S1_IDLE_SHIFT                       (4U)                                                /*!< UART2_S1: IDLE Position                 */
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_IDLE_SHIFT))&UART_S1_IDLE_MASK) /*!< UART2_S1                                */
#define UART_S1_RDRF_MASK                        (0x20U)                                             /*!< UART2_S1: RDRF Mask                     */
#define UART_S1_RDRF_SHIFT                       (5U)                                                /*!< UART2_S1: RDRF Position                 */
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_RDRF_SHIFT))&UART_S1_RDRF_MASK) /*!< UART2_S1                                */
#define UART_S1_TC_MASK                          (0x40U)                                             /*!< UART2_S1: TC Mask                       */
#define UART_S1_TC_SHIFT                         (6U)                                                /*!< UART2_S1: TC Position                   */
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_TC_SHIFT))&UART_S1_TC_MASK) /*!< UART2_S1                                */
#define UART_S1_TDRE_MASK                        (0x80U)                                             /*!< UART2_S1: TDRE Mask                     */
#define UART_S1_TDRE_SHIFT                       (7U)                                                /*!< UART2_S1: TDRE Position                 */
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_TDRE_SHIFT))&UART_S1_TDRE_MASK) /*!< UART2_S1                                */
/* ------- S2 Bit Fields                            ------ */
#define UART_S2_RAF_MASK                         (0x1U)                                              /*!< UART2_S2: RAF Mask                      */
#define UART_S2_RAF_SHIFT                        (0U)                                                /*!< UART2_S2: RAF Position                  */
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x))<<UART_S2_RAF_SHIFT))&UART_S2_RAF_MASK) /*!< UART2_S2                                */
#define UART_S2_BRK13_MASK                       (0x4U)                                              /*!< UART2_S2: BRK13 Mask                    */
#define UART_S2_BRK13_SHIFT                      (2U)                                                /*!< UART2_S2: BRK13 Position                */
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_BRK13_SHIFT))&UART_S2_BRK13_MASK) /*!< UART2_S2                                */
#define UART_S2_RWUID_MASK                       (0x8U)                                              /*!< UART2_S2: RWUID Mask                    */
#define UART_S2_RWUID_SHIFT                      (3U)                                                /*!< UART2_S2: RWUID Position                */
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RWUID_SHIFT))&UART_S2_RWUID_MASK) /*!< UART2_S2                                */
#define UART_S2_RXINV_MASK                       (0x10U)                                             /*!< UART2_S2: RXINV Mask                    */
#define UART_S2_RXINV_SHIFT                      (4U)                                                /*!< UART2_S2: RXINV Position                */
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RXINV_SHIFT))&UART_S2_RXINV_MASK) /*!< UART2_S2                                */
#define UART_S2_MSBF_MASK                        (0x20U)                                             /*!< UART2_S2: MSBF Mask                     */
#define UART_S2_MSBF_SHIFT                       (5U)                                                /*!< UART2_S2: MSBF Position                 */
#define UART_S2_MSBF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S2_MSBF_SHIFT))&UART_S2_MSBF_MASK) /*!< UART2_S2                                */
#define UART_S2_RXEDGIF_MASK                     (0x40U)                                             /*!< UART2_S2: RXEDGIF Mask                  */
#define UART_S2_RXEDGIF_SHIFT                    (6U)                                                /*!< UART2_S2: RXEDGIF Position              */
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_S2_RXEDGIF_SHIFT))&UART_S2_RXEDGIF_MASK) /*!< UART2_S2                                */
/* ------- C3 Bit Fields                            ------ */
#define UART_C3_PEIE_MASK                        (0x1U)                                              /*!< UART2_C3: PEIE Mask                     */
#define UART_C3_PEIE_SHIFT                       (0U)                                                /*!< UART2_C3: PEIE Position                 */
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_PEIE_SHIFT))&UART_C3_PEIE_MASK) /*!< UART2_C3                                */
#define UART_C3_FEIE_MASK                        (0x2U)                                              /*!< UART2_C3: FEIE Mask                     */
#define UART_C3_FEIE_SHIFT                       (1U)                                                /*!< UART2_C3: FEIE Position                 */
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_FEIE_SHIFT))&UART_C3_FEIE_MASK) /*!< UART2_C3                                */
#define UART_C3_NEIE_MASK                        (0x4U)                                              /*!< UART2_C3: NEIE Mask                     */
#define UART_C3_NEIE_SHIFT                       (2U)                                                /*!< UART2_C3: NEIE Position                 */
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_NEIE_SHIFT))&UART_C3_NEIE_MASK) /*!< UART2_C3                                */
#define UART_C3_ORIE_MASK                        (0x8U)                                              /*!< UART2_C3: ORIE Mask                     */
#define UART_C3_ORIE_SHIFT                       (3U)                                                /*!< UART2_C3: ORIE Position                 */
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_ORIE_SHIFT))&UART_C3_ORIE_MASK) /*!< UART2_C3                                */
#define UART_C3_TXINV_MASK                       (0x10U)                                             /*!< UART2_C3: TXINV Mask                    */
#define UART_C3_TXINV_SHIFT                      (4U)                                                /*!< UART2_C3: TXINV Position                */
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXINV_SHIFT))&UART_C3_TXINV_MASK) /*!< UART2_C3                                */
#define UART_C3_TXDIR_MASK                       (0x20U)                                             /*!< UART2_C3: TXDIR Mask                    */
#define UART_C3_TXDIR_SHIFT                      (5U)                                                /*!< UART2_C3: TXDIR Position                */
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXDIR_SHIFT))&UART_C3_TXDIR_MASK) /*!< UART2_C3                                */
#define UART_C3_T8_MASK                          (0x40U)                                             /*!< UART2_C3: T8 Mask                       */
#define UART_C3_T8_SHIFT                         (6U)                                                /*!< UART2_C3: T8 Position                   */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_T8_SHIFT))&UART_C3_T8_MASK) /*!< UART2_C3                                */
#define UART_C3_R8_MASK                          (0x80U)                                             /*!< UART2_C3: R8 Mask                       */
#define UART_C3_R8_SHIFT                         (7U)                                                /*!< UART2_C3: R8 Position                   */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_R8_SHIFT))&UART_C3_R8_MASK) /*!< UART2_C3                                */
/* ------- D Bit Fields                             ------ */
#define UART_D_RT_MASK                           (0xFFU)                                             /*!< UART2_D: RT Mask                        */
#define UART_D_RT_SHIFT                          (0U)                                                /*!< UART2_D: RT Position                    */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /*!< UART2_D                                 */
/* ------- MA Bit Fields                            ------ */
#define UART_MA_MA_MASK                          (0xFFU)                                             /*!< UART2_MA: MA Mask                       */
#define UART_MA_MA_SHIFT                         (0U)                                                /*!< UART2_MA: MA Position                   */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<UART_MA_MA_SHIFT))&UART_MA_MA_MASK) /*!< UART2_MA                                */
/* ------- C4 Bit Fields                            ------ */
#define UART_C4_BRFA_MASK                        (0x1FU)                                             /*!< UART2_C4: BRFA Mask                     */
#define UART_C4_BRFA_SHIFT                       (0U)                                                /*!< UART2_C4: BRFA Position                 */
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK) /*!< UART2_C4                                */
#define UART_C4_M10_MASK                         (0x20U)                                             /*!< UART2_C4: M10 Mask                      */
#define UART_C4_M10_SHIFT                        (5U)                                                /*!< UART2_C4: M10 Position                  */
#define UART_C4_M10(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C4_M10_SHIFT))&UART_C4_M10_MASK) /*!< UART2_C4                                */
#define UART_C4_MAEN2_MASK                       (0x40U)                                             /*!< UART2_C4: MAEN2 Mask                    */
#define UART_C4_MAEN2_SHIFT                      (6U)                                                /*!< UART2_C4: MAEN2 Position                */
#define UART_C4_MAEN2(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN2_SHIFT))&UART_C4_MAEN2_MASK) /*!< UART2_C4                                */
#define UART_C4_MAEN1_MASK                       (0x80U)                                             /*!< UART2_C4: MAEN1 Mask                    */
#define UART_C4_MAEN1_SHIFT                      (7U)                                                /*!< UART2_C4: MAEN1 Position                */
#define UART_C4_MAEN1(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN1_SHIFT))&UART_C4_MAEN1_MASK) /*!< UART2_C4                                */
/* ------- C5 Bit Fields                            ------ */
#define UART_C5_RDMAS_MASK                       (0x20U)                                             /*!< UART2_C5: RDMAS Mask                    */
#define UART_C5_RDMAS_SHIFT                      (5U)                                                /*!< UART2_C5: RDMAS Position                */
#define UART_C5_RDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_RDMAS_SHIFT))&UART_C5_RDMAS_MASK) /*!< UART2_C5                                */
#define UART_C5_TDMAS_MASK                       (0x80U)                                             /*!< UART2_C5: TDMAS Mask                    */
#define UART_C5_TDMAS_SHIFT                      (7U)                                                /*!< UART2_C5: TDMAS Position                */
#define UART_C5_TDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_TDMAS_SHIFT))&UART_C5_TDMAS_MASK) /*!< UART2_C5                                */
/* ------- C7816 Bit Fields                         ------ */
#define UART_C7816_ISO_7816E_MASK                (0x1U)                                              /*!< UART2_C7816: ISO_7816E Mask             */
#define UART_C7816_ISO_7816E_SHIFT               (0U)                                                /*!< UART2_C7816: ISO_7816E Position         */
#define UART_C7816_ISO_7816E(x)                  (((uint8_t)(((uint8_t)(x))<<UART_C7816_ISO_7816E_SHIFT))&UART_C7816_ISO_7816E_MASK) /*!< UART2_C7816                             */
#define UART_C7816_TTYPE_MASK                    (0x2U)                                              /*!< UART2_C7816: TTYPE Mask                 */
#define UART_C7816_TTYPE_SHIFT                   (1U)                                                /*!< UART2_C7816: TTYPE Position             */
#define UART_C7816_TTYPE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_TTYPE_SHIFT))&UART_C7816_TTYPE_MASK) /*!< UART2_C7816                             */
#define UART_C7816_INIT_MASK                     (0x4U)                                              /*!< UART2_C7816: INIT Mask                  */
#define UART_C7816_INIT_SHIFT                    (2U)                                                /*!< UART2_C7816: INIT Position              */
#define UART_C7816_INIT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_C7816_INIT_SHIFT))&UART_C7816_INIT_MASK) /*!< UART2_C7816                             */
#define UART_C7816_ANACK_MASK                    (0x8U)                                              /*!< UART2_C7816: ANACK Mask                 */
#define UART_C7816_ANACK_SHIFT                   (3U)                                                /*!< UART2_C7816: ANACK Position             */
#define UART_C7816_ANACK(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_ANACK_SHIFT))&UART_C7816_ANACK_MASK) /*!< UART2_C7816                             */
#define UART_C7816_ONACK_MASK                    (0x10U)                                             /*!< UART2_C7816: ONACK Mask                 */
#define UART_C7816_ONACK_SHIFT                   (4U)                                                /*!< UART2_C7816: ONACK Position             */
#define UART_C7816_ONACK(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_ONACK_SHIFT))&UART_C7816_ONACK_MASK) /*!< UART2_C7816                             */
/* ------- IE7816 Bit Fields                        ------ */
#define UART_IE7816_RXTE_MASK                    (0x1U)                                              /*!< UART2_IE7816: RXTE Mask                 */
#define UART_IE7816_RXTE_SHIFT                   (0U)                                                /*!< UART2_IE7816: RXTE Position             */
#define UART_IE7816_RXTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_RXTE_SHIFT))&UART_IE7816_RXTE_MASK) /*!< UART2_IE7816                            */
#define UART_IE7816_TXTE_MASK                    (0x2U)                                              /*!< UART2_IE7816: TXTE Mask                 */
#define UART_IE7816_TXTE_SHIFT                   (1U)                                                /*!< UART2_IE7816: TXTE Position             */
#define UART_IE7816_TXTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_TXTE_SHIFT))&UART_IE7816_TXTE_MASK) /*!< UART2_IE7816                            */
#define UART_IE7816_GTVE_MASK                    (0x4U)                                              /*!< UART2_IE7816: GTVE Mask                 */
#define UART_IE7816_GTVE_SHIFT                   (2U)                                                /*!< UART2_IE7816: GTVE Position             */
#define UART_IE7816_GTVE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_GTVE_SHIFT))&UART_IE7816_GTVE_MASK) /*!< UART2_IE7816                            */
#define UART_IE7816_ADTE_MASK                    (0x8U)                                              /*!< UART2_IE7816: ADTE Mask                 */
#define UART_IE7816_ADTE_SHIFT                   (3U)                                                /*!< UART2_IE7816: ADTE Position             */
#define UART_IE7816_ADTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_ADTE_SHIFT))&UART_IE7816_ADTE_MASK) /*!< UART2_IE7816                            */
#define UART_IE7816_INITDE_MASK                  (0x10U)                                             /*!< UART2_IE7816: INITDE Mask               */
#define UART_IE7816_INITDE_SHIFT                 (4U)                                                /*!< UART2_IE7816: INITDE Position           */
#define UART_IE7816_INITDE(x)                    (((uint8_t)(((uint8_t)(x))<<UART_IE7816_INITDE_SHIFT))&UART_IE7816_INITDE_MASK) /*!< UART2_IE7816                            */
#define UART_IE7816_BWTE_MASK                    (0x20U)                                             /*!< UART2_IE7816: BWTE Mask                 */
#define UART_IE7816_BWTE_SHIFT                   (5U)                                                /*!< UART2_IE7816: BWTE Position             */
#define UART_IE7816_BWTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_BWTE_SHIFT))&UART_IE7816_BWTE_MASK) /*!< UART2_IE7816                            */
#define UART_IE7816_CWTE_MASK                    (0x40U)                                             /*!< UART2_IE7816: CWTE Mask                 */
#define UART_IE7816_CWTE_SHIFT                   (6U)                                                /*!< UART2_IE7816: CWTE Position             */
#define UART_IE7816_CWTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_CWTE_SHIFT))&UART_IE7816_CWTE_MASK) /*!< UART2_IE7816                            */
#define UART_IE7816_WTE_MASK                     (0x80U)                                             /*!< UART2_IE7816: WTE Mask                  */
#define UART_IE7816_WTE_SHIFT                    (7U)                                                /*!< UART2_IE7816: WTE Position              */
#define UART_IE7816_WTE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IE7816_WTE_SHIFT))&UART_IE7816_WTE_MASK) /*!< UART2_IE7816                            */
/* ------- IS7816 Bit Fields                        ------ */
#define UART_IS7816_RXT_MASK                     (0x1U)                                              /*!< UART2_IS7816: RXT Mask                  */
#define UART_IS7816_RXT_SHIFT                    (0U)                                                /*!< UART2_IS7816: RXT Position              */
#define UART_IS7816_RXT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_RXT_SHIFT))&UART_IS7816_RXT_MASK) /*!< UART2_IS7816                            */
#define UART_IS7816_TXT_MASK                     (0x2U)                                              /*!< UART2_IS7816: TXT Mask                  */
#define UART_IS7816_TXT_SHIFT                    (1U)                                                /*!< UART2_IS7816: TXT Position              */
#define UART_IS7816_TXT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_TXT_SHIFT))&UART_IS7816_TXT_MASK) /*!< UART2_IS7816                            */
#define UART_IS7816_GTV_MASK                     (0x4U)                                              /*!< UART2_IS7816: GTV Mask                  */
#define UART_IS7816_GTV_SHIFT                    (2U)                                                /*!< UART2_IS7816: GTV Position              */
#define UART_IS7816_GTV(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_GTV_SHIFT))&UART_IS7816_GTV_MASK) /*!< UART2_IS7816                            */
#define UART_IS7816_ADT_MASK                     (0x8U)                                              /*!< UART2_IS7816: ADT Mask                  */
#define UART_IS7816_ADT_SHIFT                    (3U)                                                /*!< UART2_IS7816: ADT Position              */
#define UART_IS7816_ADT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_ADT_SHIFT))&UART_IS7816_ADT_MASK) /*!< UART2_IS7816                            */
#define UART_IS7816_INITD_MASK                   (0x10U)                                             /*!< UART2_IS7816: INITD Mask                */
#define UART_IS7816_INITD_SHIFT                  (4U)                                                /*!< UART2_IS7816: INITD Position            */
#define UART_IS7816_INITD(x)                     (((uint8_t)(((uint8_t)(x))<<UART_IS7816_INITD_SHIFT))&UART_IS7816_INITD_MASK) /*!< UART2_IS7816                            */
#define UART_IS7816_BWT_MASK                     (0x20U)                                             /*!< UART2_IS7816: BWT Mask                  */
#define UART_IS7816_BWT_SHIFT                    (5U)                                                /*!< UART2_IS7816: BWT Position              */
#define UART_IS7816_BWT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_BWT_SHIFT))&UART_IS7816_BWT_MASK) /*!< UART2_IS7816                            */
#define UART_IS7816_CWT_MASK                     (0x40U)                                             /*!< UART2_IS7816: CWT Mask                  */
#define UART_IS7816_CWT_SHIFT                    (6U)                                                /*!< UART2_IS7816: CWT Position              */
#define UART_IS7816_CWT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_CWT_SHIFT))&UART_IS7816_CWT_MASK) /*!< UART2_IS7816                            */
#define UART_IS7816_WT_MASK                      (0x80U)                                             /*!< UART2_IS7816: WT Mask                   */
#define UART_IS7816_WT_SHIFT                     (7U)                                                /*!< UART2_IS7816: WT Position               */
#define UART_IS7816_WT(x)                        (((uint8_t)(((uint8_t)(x))<<UART_IS7816_WT_SHIFT))&UART_IS7816_WT_MASK) /*!< UART2_IS7816                            */
/* ------- WP7816 Bit Fields                        ------ */
#define UART_WP7816_WTX_MASK                     (0xFFU)                                             /*!< UART2_WP7816: WTX Mask                  */
#define UART_WP7816_WTX_SHIFT                    (0U)                                                /*!< UART2_WP7816: WTX Position              */
#define UART_WP7816_WTX(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WP7816_WTX_SHIFT))&UART_WP7816_WTX_MASK) /*!< UART2_WP7816                            */
/* ------- WN7816 Bit Fields                        ------ */
#define UART_WN7816_GTN_MASK                     (0xFFU)                                             /*!< UART2_WN7816: GTN Mask                  */
#define UART_WN7816_GTN_SHIFT                    (0U)                                                /*!< UART2_WN7816: GTN Position              */
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK) /*!< UART2_WN7816                            */
/* ------- WF7816 Bit Fields                        ------ */
#define UART_WF7816_GTFD_MASK                    (0xFFU)                                             /*!< UART2_WF7816: GTFD Mask                 */
#define UART_WF7816_GTFD_SHIFT                   (0U)                                                /*!< UART2_WF7816: GTFD Position             */
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK) /*!< UART2_WF7816                            */
/* ------- ET7816 Bit Fields                        ------ */
#define UART_ET7816_RXTHRESHOLD_MASK             (0xFU)                                              /*!< UART2_ET7816: RXTHRESHOLD Mask          */
#define UART_ET7816_RXTHRESHOLD_SHIFT            (0U)                                                /*!< UART2_ET7816: RXTHRESHOLD Position      */
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK) /*!< UART2_ET7816                            */
#define UART_ET7816_TXTHRESHOLD_MASK             (0xF0U)                                             /*!< UART2_ET7816: TXTHRESHOLD Mask          */
#define UART_ET7816_TXTHRESHOLD_SHIFT            (4U)                                                /*!< UART2_ET7816: TXTHRESHOLD Position      */
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK) /*!< UART2_ET7816                            */
/* ------- TL7816 Bit Fields                        ------ */
#define UART_TL7816_TLEN_MASK                    (0xFFU)                                             /*!< UART2_TL7816: TLEN Mask                 */
#define UART_TL7816_TLEN_SHIFT                   (0U)                                                /*!< UART2_TL7816: TLEN Position             */
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK) /*!< UART2_TL7816                            */
/* ------- AP7816A_T0 Bit Fields                    ------ */
#define UART_AP7816A_T0_ADTI_H_MASK              (0xFFU)                                             /*!< UART2_AP7816A_T0: ADTI_H Mask           */
#define UART_AP7816A_T0_ADTI_H_SHIFT             (0U)                                                /*!< UART2_AP7816A_T0: ADTI_H Position       */
#define UART_AP7816A_T0_ADTI_H(x)                (((uint8_t)(((uint8_t)(x))<<UART_AP7816A_T0_ADTI_H_SHIFT))&UART_AP7816A_T0_ADTI_H_MASK) /*!< UART2_AP7816A_T0                        */
/* ------- AP7816B_T0 Bit Fields                    ------ */
#define UART_AP7816B_T0_ADTI_L_MASK              (0xFFU)                                             /*!< UART2_AP7816B_T0: ADTI_L Mask           */
#define UART_AP7816B_T0_ADTI_L_SHIFT             (0U)                                                /*!< UART2_AP7816B_T0: ADTI_L Position       */
#define UART_AP7816B_T0_ADTI_L(x)                (((uint8_t)(((uint8_t)(x))<<UART_AP7816B_T0_ADTI_L_SHIFT))&UART_AP7816B_T0_ADTI_L_MASK) /*!< UART2_AP7816B_T0                        */
/* ------- WP7816A_T0 Bit Fields                    ------ */
#define UART_WP7816A_T0_WI_H_MASK                (0xFFU)                                             /*!< UART2_WP7816A_T0: WI_H Mask             */
#define UART_WP7816A_T0_WI_H_SHIFT               (0U)                                                /*!< UART2_WP7816A_T0: WI_H Position         */
#define UART_WP7816A_T0_WI_H(x)                  (((uint8_t)(((uint8_t)(x))<<UART_WP7816A_T0_WI_H_SHIFT))&UART_WP7816A_T0_WI_H_MASK) /*!< UART2_WP7816A_T0                        */
/* ------- WP7816A_T1 Bit Fields                    ------ */
#define UART_WP7816A_T1_BWI_H_MASK               (0xFFU)                                             /*!< UART2_WP7816A_T1: BWI_H Mask            */
#define UART_WP7816A_T1_BWI_H_SHIFT              (0U)                                                /*!< UART2_WP7816A_T1: BWI_H Position        */
#define UART_WP7816A_T1_BWI_H(x)                 (((uint8_t)(((uint8_t)(x))<<UART_WP7816A_T1_BWI_H_SHIFT))&UART_WP7816A_T1_BWI_H_MASK) /*!< UART2_WP7816A_T1                        */
/* ------- WP7816B_T0 Bit Fields                    ------ */
#define UART_WP7816B_T0_WI_L_MASK                (0xFFU)                                             /*!< UART2_WP7816B_T0: WI_L Mask             */
#define UART_WP7816B_T0_WI_L_SHIFT               (0U)                                                /*!< UART2_WP7816B_T0: WI_L Position         */
#define UART_WP7816B_T0_WI_L(x)                  (((uint8_t)(((uint8_t)(x))<<UART_WP7816B_T0_WI_L_SHIFT))&UART_WP7816B_T0_WI_L_MASK) /*!< UART2_WP7816B_T0                        */
/* ------- WP7816B_T1 Bit Fields                    ------ */
#define UART_WP7816B_T1_BWI_L_MASK               (0xFFU)                                             /*!< UART2_WP7816B_T1: BWI_L Mask            */
#define UART_WP7816B_T1_BWI_L_SHIFT              (0U)                                                /*!< UART2_WP7816B_T1: BWI_L Position        */
#define UART_WP7816B_T1_BWI_L(x)                 (((uint8_t)(((uint8_t)(x))<<UART_WP7816B_T1_BWI_L_SHIFT))&UART_WP7816B_T1_BWI_L_MASK) /*!< UART2_WP7816B_T1                        */
/* ------- WGP7816_T1 Bit Fields                    ------ */
#define UART_WGP7816_T1_BGI_MASK                 (0xFU)                                              /*!< UART2_WGP7816_T1: BGI Mask              */
#define UART_WGP7816_T1_BGI_SHIFT                (0U)                                                /*!< UART2_WGP7816_T1: BGI Position          */
#define UART_WGP7816_T1_BGI(x)                   (((uint8_t)(((uint8_t)(x))<<UART_WGP7816_T1_BGI_SHIFT))&UART_WGP7816_T1_BGI_MASK) /*!< UART2_WGP7816_T1                        */
#define UART_WGP7816_T1_CWI1_MASK                (0xF0U)                                             /*!< UART2_WGP7816_T1: CWI1 Mask             */
#define UART_WGP7816_T1_CWI1_SHIFT               (4U)                                                /*!< UART2_WGP7816_T1: CWI1 Position         */
#define UART_WGP7816_T1_CWI1(x)                  (((uint8_t)(((uint8_t)(x))<<UART_WGP7816_T1_CWI1_SHIFT))&UART_WGP7816_T1_CWI1_MASK) /*!< UART2_WGP7816_T1                        */
/* ------- WP7816C_T1 Bit Fields                    ------ */
#define UART_WP7816C_T1_CWI2_MASK                (0x1FU)                                             /*!< UART2_WP7816C_T1: CWI2 Mask             */
#define UART_WP7816C_T1_CWI2_SHIFT               (0U)                                                /*!< UART2_WP7816C_T1: CWI2 Position         */
#define UART_WP7816C_T1_CWI2(x)                  (((uint8_t)(((uint8_t)(x))<<UART_WP7816C_T1_CWI2_SHIFT))&UART_WP7816C_T1_CWI2_MASK) /*!< UART2_WP7816C_T1                        */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x4006C000UL //!< Peripheral base address
#define UART2                          ((UART_Type *) UART2_BasePtr) //!< Freescale base pointer
#define UART2_BASE_PTR                 (UART2) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup VREF_Peripheral_access_layer_GROUP VREF Peripheral Access Layer
* @brief C Struct for VREF
* @{
*/

/* ================================================================================ */
/* ================           VREF (file:VREF_C)                   ================ */
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
#define VREF_TRM_TRIM_MASK                       (0x3FU)                                             /*!< VREF_TRM: TRIM Mask                     */
#define VREF_TRM_TRIM_SHIFT                      (0U)                                                /*!< VREF_TRM: TRIM Position                 */
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_TRIM_SHIFT))&VREF_TRM_TRIM_MASK) /*!< VREF_TRM                                */
#define VREF_TRM_CHOPEN_MASK                     (0x40U)                                             /*!< VREF_TRM: CHOPEN Mask                   */
#define VREF_TRM_CHOPEN_SHIFT                    (6U)                                                /*!< VREF_TRM: CHOPEN Position               */
#define VREF_TRM_CHOPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_TRM_CHOPEN_SHIFT))&VREF_TRM_CHOPEN_MASK) /*!< VREF_TRM                                */
/* ------- SC Bit Fields                            ------ */
#define VREF_SC_MODE_LV_MASK                     (0x3U)                                              /*!< VREF_SC: MODE_LV Mask                   */
#define VREF_SC_MODE_LV_SHIFT                    (0U)                                                /*!< VREF_SC: MODE_LV Position               */
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_MODE_LV_SHIFT))&VREF_SC_MODE_LV_MASK) /*!< VREF_SC                                 */
#define VREF_SC_VREFST_MASK                      (0x4U)                                              /*!< VREF_SC: VREFST Mask                    */
#define VREF_SC_VREFST_SHIFT                     (2U)                                                /*!< VREF_SC: VREFST Position                */
#define VREF_SC_VREFST(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFST_SHIFT))&VREF_SC_VREFST_MASK) /*!< VREF_SC                                 */
#define VREF_SC_ICOMPEN_MASK                     (0x20U)                                             /*!< VREF_SC: ICOMPEN Mask                   */
#define VREF_SC_ICOMPEN_SHIFT                    (5U)                                                /*!< VREF_SC: ICOMPEN Position               */
#define VREF_SC_ICOMPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_ICOMPEN_SHIFT))&VREF_SC_ICOMPEN_MASK) /*!< VREF_SC                                 */
#define VREF_SC_REGEN_MASK                       (0x40U)                                             /*!< VREF_SC: REGEN Mask                     */
#define VREF_SC_REGEN_SHIFT                      (6U)                                                /*!< VREF_SC: REGEN Position                 */
#define VREF_SC_REGEN(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_SC_REGEN_SHIFT))&VREF_SC_REGEN_MASK) /*!< VREF_SC                                 */
#define VREF_SC_VREFEN_MASK                      (0x80U)                                             /*!< VREF_SC: VREFEN Mask                    */
#define VREF_SC_VREFEN_SHIFT                     (7U)                                                /*!< VREF_SC: VREFEN Position                */
#define VREF_SC_VREFEN(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFEN_SHIFT))&VREF_SC_VREFEN_MASK) /*!< VREF_SC                                 */
/**
 * @} */ /* End group VREF_Register_Masks_GROUP 
 */

/* VREF - Peripheral instance base addresses */
#define VREF_BasePtr                   0x40074000UL //!< Peripheral base address
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


#endif  /* MCU_MKL17Z4 */

