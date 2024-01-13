/*!
 * @file     MKL25Z4.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKL25Z4.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2024/01
 *
 */

#ifndef _MKL25Z4_H_
#define _MKL25Z4_H_

#define MCU_MKL25Z4

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif


/** @brief Vector numbers required for NVIC functions */
/** @addtogroup Interrupt_vector_numbers_GROUP Interrupt vector numbers */
/** @{ */
#define NUMBER_OF_INT_VECTORS 48 //<! Number of vector table entries
/* -------------------------  Interrupt Number Definitions  ------------------------ */

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
/* ----------------------   MKL25Z4 VectorTable                      ---------------------- */
  DMA0_IRQn                     =   0,   /**<  16 Direct memory access controller                                                  */
  DMA1_IRQn                     =   1,   /**<  17 Direct memory access controller                                                  */
  DMA2_IRQn                     =   2,   /**<  18 Direct memory access controller                                                  */
  DMA3_IRQn                     =   3,   /**<  19 Direct memory access controller                                                  */
  FTF_Command_IRQn              =   5,   /**<  21 Flash Memory Interface                                                           */
  PMC_IRQn                      =   6,   /**<  22 Power Management Controller                                                      */
  LLWU_IRQn                     =   7,   /**<  23 Low Leakage Wakeup                                                               */
  I2C0_IRQn                     =   8,   /**<  24 Inter-Integrated Circuit                                                         */
  I2C1_IRQn                     =   9,   /**<  25 Inter-Integrated Circuit                                                         */
  SPI0_IRQn                     =  10,   /**<  26 Serial Peripheral Interface                                                      */
  SPI1_IRQn                     =  11,   /**<  27 Serial Peripheral Interface                                                      */
  UART0_IRQn                    =  12,   /**<  28 Serial Communication Interface                                                   */
  UART1_IRQn                    =  13,   /**<  29 Serial Communication Interface                                                   */
  UART2_IRQn                    =  14,   /**<  30 Serial Communication Interface                                                   */
  ADC0_IRQn                     =  15,   /**<  31 Analogue to Digital Converter                                                    */
  CMP0_IRQn                     =  16,   /**<  32 High-Speed Comparator                                                            */
  TPM0_IRQn                     =  17,   /**<  33 Timer/PWM Module                                                                 */
  TPM1_IRQn                     =  18,   /**<  34 Timer/PWM Module                                                                 */
  TPM2_IRQn                     =  19,   /**<  35 Timer/PWM Module                                                                 */
  RTC_Alarm_IRQn                =  20,   /**<  36 Real Time Clock                                                                  */
  RTC_Seconds_IRQn              =  21,   /**<  37 Real Time Clock                                                                  */
  PIT_IRQn                      =  22,   /**<  38 Periodic Interrupt Timer (All channels)                                          */
  USB0_IRQn                     =  24,   /**<  40 Universal Serial Bus                                                             */
  DAC0_IRQn                     =  25,   /**<  41 Digital to Analogue Converter                                                    */
  TSI0_IRQn                     =  26,   /**<  42 Touch Sense Input                                                                */
  MCG_IRQn                      =  27,   /**<  43 Multipurpose Clock Generator                                                     */
  LPTMR0_IRQn                   =  28,   /**<  44 Low Power Timer                                                                  */
  PORTA_IRQn                    =  30,   /**<  46 General Purpose Input/Output                                                     */
  PORTD_IRQn                    =  31,   /**<  47 General Purpose Input/Output                                                     */
} IRQn_Type;


/** @brief Prototypes for interrupt handlers */
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                       /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);                 /**< Hard Fault, all classes of Fault                                                 */
extern void SVC_Handler(void);                       /**< System Service Call via SVC instruction                                          */
extern void PendSV_Handler(void);                    /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);                   /**< System Tick Timer                                                                */
extern void DMA0_IRQHandler(void);                   /**< Direct memory access controller                                                  */
extern void DMA1_IRQHandler(void);                   /**< Direct memory access controller                                                  */
extern void DMA2_IRQHandler(void);                   /**< Direct memory access controller                                                  */
extern void DMA3_IRQHandler(void);                   /**< Direct memory access controller                                                  */
extern void FTF_Command_IRQHandler(void);            /**< Flash Memory Interface                                                           */
extern void PMC_IRQHandler(void);                    /**< Power Management Controller                                                      */
extern void LLWU_IRQHandler(void);                   /**< Low Leakage Wakeup                                                               */
extern void I2C0_IRQHandler(void);                   /**< Inter-Integrated Circuit                                                         */
extern void I2C1_IRQHandler(void);                   /**< Inter-Integrated Circuit                                                         */
extern void SPI0_IRQHandler(void);                   /**< Serial Peripheral Interface                                                      */
extern void SPI1_IRQHandler(void);                   /**< Serial Peripheral Interface                                                      */
extern void UART0_IRQHandler(void);                  /**< Serial Communication Interface                                                   */
extern void UART1_IRQHandler(void);                  /**< Serial Communication Interface                                                   */
extern void UART2_IRQHandler(void);                  /**< Serial Communication Interface                                                   */
extern void ADC0_IRQHandler(void);                   /**< Analogue to Digital Converter                                                    */
extern void CMP0_IRQHandler(void);                   /**< High-Speed Comparator                                                            */
extern void TPM0_IRQHandler(void);                   /**< Timer/PWM Module                                                                 */
extern void TPM1_IRQHandler(void);                   /**< Timer/PWM Module                                                                 */
extern void TPM2_IRQHandler(void);                   /**< Timer/PWM Module                                                                 */
extern void RTC_Alarm_IRQHandler(void);              /**< Real Time Clock                                                                  */
extern void RTC_Seconds_IRQHandler(void);            /**< Real Time Clock                                                                  */
extern void PIT_IRQHandler(void);                    /**< Periodic Interrupt Timer (All channels)                                          */
extern void USB0_IRQHandler(void);                   /**< Universal Serial Bus                                                             */
extern void DAC0_IRQHandler(void);                   /**< Digital to Analogue Converter                                                    */
extern void TSI0_IRQHandler(void);                   /**< Touch Sense Input                                                                */
extern void MCG_IRQHandler(void);                    /**< Multipurpose Clock Generator                                                     */
extern void LPTMR0_IRQHandler(void);                 /**< Low Power Timer                                                                  */
extern void PORTA_IRQHandler(void);                  /**< General Purpose Input/Output                                                     */
extern void PORTD_IRQHandler(void);                  /**< General Purpose Input/Output                                                     */


/** @} */ /* End group Interrupt_vector_numbers_GROUP */

/** @addtogroup Interrupt_handler_prototypes_GROUP Interrupt handler prototypes */
/** @{ */

/** @} */ /* End group Interrupt_handler_prototypes_GROUP */

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */


/** @brief Configuration of the cm4 Processor and Core Peripherals */
/** @addtogroup Cortex_Core_Configuration_GROUP Cortex Core Configuration */
/** @{ */
#define __CM0PLUS_REV             0x0100     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          2          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             0          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */


/** @} */ /* End group Cortex_Core_Configuration_GROUP */

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
 * @defgroup Peripheral_access_layer_GROUP  Device Peripheral Access Layer
 *
 * C structs allowing access to peripheral registers
 */

/** @brief C Struct for ADC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           ADC0 (file:ADC0_DIFF_A)              ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */
#define ADC_SC1_COUNT        2          /**< Number of ADC channels                             */
/**
 * @struct ADC_Type
 * @brief  C Struct allowing access to ADC registers
 */
typedef struct ADC_Type {
   __IO uint32_t  SC1[ADC_SC1_COUNT];           /**< 0000: Status and Control Register 1                                */
   __IO uint32_t  CFG1;                         /**< 0008: Configuration Register 1                                     */
   __IO uint32_t  CFG2;                         /**< 000C: Configuration Register 2                                     */
   __I  uint32_t  R[ADC_SC1_COUNT];             /**< 0010: Data Result Register                                         */
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
        uint8_t   RESERVED_0[4];                /**< 0050: 0x4 bytes                                                    */
   __IO uint32_t  CLMD;                         /**< 0054: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLMS;                         /**< 0058: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM4;                         /**< 005C: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM3;                         /**< 0060: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM2;                         /**< 0064: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM1;                         /**< 0068: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM0;                         /**< 006C: Minus-Side General Calibration Value                         */
} ADC_Type;


/** @brief Register Masks for ADC */

/* -------------------------------------------------------------------------------- */
/* -----------     'ADC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup ADC_Register_Masks_GROUP ADC Register Masks */
/** @{ */

/** @name SC1 - Status and Control Register 1 */ /** @{ */
#define ADC_SC1_ADCH_MASK                        (0x1FU)                                             /**< ADC0_SC1.ADCH Mask                      */
#define ADC_SC1_ADCH_SHIFT                       (0U)                                                /**< ADC0_SC1.ADCH Position                  */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK) /**< ADC0_SC1.ADCH Field                     */
#define ADC_SC1_DIFF_MASK                        (0x20U)                                             /**< ADC0_SC1.DIFF Mask                      */
#define ADC_SC1_DIFF_SHIFT                       (5U)                                                /**< ADC0_SC1.DIFF Position                  */
#define ADC_SC1_DIFF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_DIFF_SHIFT))&ADC_SC1_DIFF_MASK) /**< ADC0_SC1.DIFF Field                     */
#define ADC_SC1_AIEN_MASK                        (0x40U)                                             /**< ADC0_SC1.AIEN Mask                      */
#define ADC_SC1_AIEN_SHIFT                       (6U)                                                /**< ADC0_SC1.AIEN Position                  */
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_AIEN_SHIFT))&ADC_SC1_AIEN_MASK) /**< ADC0_SC1.AIEN Field                     */
#define ADC_SC1_COCO_MASK                        (0x80U)                                             /**< ADC0_SC1.COCO Mask                      */
#define ADC_SC1_COCO_SHIFT                       (7U)                                                /**< ADC0_SC1.COCO Position                  */
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_COCO_SHIFT))&ADC_SC1_COCO_MASK) /**< ADC0_SC1.COCO Field                     */
/** @} */

/** @name CFG1 - Configuration Register 1 */ /** @{ */
#define ADC_CFG1_ADICLK_MASK                     (0x3U)                                              /**< ADC0_CFG1.ADICLK Mask                   */
#define ADC_CFG1_ADICLK_SHIFT                    (0U)                                                /**< ADC0_CFG1.ADICLK Position               */
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK) /**< ADC0_CFG1.ADICLK Field                  */
#define ADC_CFG1_MODE_MASK                       (0xCU)                                              /**< ADC0_CFG1.MODE Mask                     */
#define ADC_CFG1_MODE_SHIFT                      (2U)                                                /**< ADC0_CFG1.MODE Position                 */
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK) /**< ADC0_CFG1.MODE Field                    */
#define ADC_CFG1_ADLSMP_MASK                     (0x10U)                                             /**< ADC0_CFG1.ADLSMP Mask                   */
#define ADC_CFG1_ADLSMP_SHIFT                    (4U)                                                /**< ADC0_CFG1.ADLSMP Position               */
#define ADC_CFG1_ADLSMP(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLSMP_SHIFT))&ADC_CFG1_ADLSMP_MASK) /**< ADC0_CFG1.ADLSMP Field                  */
#define ADC_CFG1_ADIV_MASK                       (0x60U)                                             /**< ADC0_CFG1.ADIV Mask                     */
#define ADC_CFG1_ADIV_SHIFT                      (5U)                                                /**< ADC0_CFG1.ADIV Position                 */
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK) /**< ADC0_CFG1.ADIV Field                    */
#define ADC_CFG1_ADLPC_MASK                      (0x80U)                                             /**< ADC0_CFG1.ADLPC Mask                    */
#define ADC_CFG1_ADLPC_SHIFT                     (7U)                                                /**< ADC0_CFG1.ADLPC Position                */
#define ADC_CFG1_ADLPC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLPC_SHIFT))&ADC_CFG1_ADLPC_MASK) /**< ADC0_CFG1.ADLPC Field                   */
/** @} */

/** @name CFG2 - Configuration Register 2 */ /** @{ */
#define ADC_CFG2_ADLSTS_MASK                     (0x3U)                                              /**< ADC0_CFG2.ADLSTS Mask                   */
#define ADC_CFG2_ADLSTS_SHIFT                    (0U)                                                /**< ADC0_CFG2.ADLSTS Position               */
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK) /**< ADC0_CFG2.ADLSTS Field                  */
#define ADC_CFG2_ADHSC_MASK                      (0x4U)                                              /**< ADC0_CFG2.ADHSC Mask                    */
#define ADC_CFG2_ADHSC_SHIFT                     (2U)                                                /**< ADC0_CFG2.ADHSC Position                */
#define ADC_CFG2_ADHSC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADHSC_SHIFT))&ADC_CFG2_ADHSC_MASK) /**< ADC0_CFG2.ADHSC Field                   */
#define ADC_CFG2_ADACKEN_MASK                    (0x8U)                                              /**< ADC0_CFG2.ADACKEN Mask                  */
#define ADC_CFG2_ADACKEN_SHIFT                   (3U)                                                /**< ADC0_CFG2.ADACKEN Position              */
#define ADC_CFG2_ADACKEN(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADACKEN_SHIFT))&ADC_CFG2_ADACKEN_MASK) /**< ADC0_CFG2.ADACKEN Field                 */
#define ADC_CFG2_MUXSEL_MASK                     (0x10U)                                             /**< ADC0_CFG2.MUXSEL Mask                   */
#define ADC_CFG2_MUXSEL_SHIFT                    (4U)                                                /**< ADC0_CFG2.MUXSEL Position               */
#define ADC_CFG2_MUXSEL(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_MUXSEL_SHIFT))&ADC_CFG2_MUXSEL_MASK) /**< ADC0_CFG2.MUXSEL Field                  */
/** @} */

/** @name R - Data Result Register */ /** @{ */
#define ADC_R_D_MASK                             (0xFFFFU)                                           /**< ADC0_R.D Mask                           */
#define ADC_R_D_SHIFT                            (0U)                                                /**< ADC0_R.D Position                       */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK) /**< ADC0_R.D Field                          */
/** @} */

/** @name CV - Compare Value */ /** @{ */
#define ADC_CV_CV_MASK                           (0xFFFFU)                                           /**< ADC0_CV.CV Mask                         */
#define ADC_CV_CV_SHIFT                          (0U)                                                /**< ADC0_CV.CV Position                     */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK) /**< ADC0_CV.CV Field                        */
/** @} */

/** @name SC2 - Status and Control Register 2 */ /** @{ */
#define ADC_SC2_REFSEL_MASK                      (0x3U)                                              /**< ADC0_SC2.REFSEL Mask                    */
#define ADC_SC2_REFSEL_SHIFT                     (0U)                                                /**< ADC0_SC2.REFSEL Position                */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK) /**< ADC0_SC2.REFSEL Field                   */
#define ADC_SC2_DMAEN_MASK                       (0x4U)                                              /**< ADC0_SC2.DMAEN Mask                     */
#define ADC_SC2_DMAEN_SHIFT                      (2U)                                                /**< ADC0_SC2.DMAEN Position                 */
#define ADC_SC2_DMAEN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_DMAEN_SHIFT))&ADC_SC2_DMAEN_MASK) /**< ADC0_SC2.DMAEN Field                    */
#define ADC_SC2_ACREN_MASK                       (0x8U)                                              /**< ADC0_SC2.ACREN Mask                     */
#define ADC_SC2_ACREN_SHIFT                      (3U)                                                /**< ADC0_SC2.ACREN Position                 */
#define ADC_SC2_ACREN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACREN_SHIFT))&ADC_SC2_ACREN_MASK) /**< ADC0_SC2.ACREN Field                    */
#define ADC_SC2_ACFGT_MASK                       (0x10U)                                             /**< ADC0_SC2.ACFGT Mask                     */
#define ADC_SC2_ACFGT_SHIFT                      (4U)                                                /**< ADC0_SC2.ACFGT Position                 */
#define ADC_SC2_ACFGT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFGT_SHIFT))&ADC_SC2_ACFGT_MASK) /**< ADC0_SC2.ACFGT Field                    */
#define ADC_SC2_ACFE_MASK                        (0x20U)                                             /**< ADC0_SC2.ACFE Mask                      */
#define ADC_SC2_ACFE_SHIFT                       (5U)                                                /**< ADC0_SC2.ACFE Position                  */
#define ADC_SC2_ACFE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFE_SHIFT))&ADC_SC2_ACFE_MASK) /**< ADC0_SC2.ACFE Field                     */
#define ADC_SC2_ADTRG_MASK                       (0x40U)                                             /**< ADC0_SC2.ADTRG Mask                     */
#define ADC_SC2_ADTRG_SHIFT                      (6U)                                                /**< ADC0_SC2.ADTRG Position                 */
#define ADC_SC2_ADTRG(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADTRG_SHIFT))&ADC_SC2_ADTRG_MASK) /**< ADC0_SC2.ADTRG Field                    */
#define ADC_SC2_ADACT_MASK                       (0x80U)                                             /**< ADC0_SC2.ADACT Mask                     */
#define ADC_SC2_ADACT_SHIFT                      (7U)                                                /**< ADC0_SC2.ADACT Position                 */
#define ADC_SC2_ADACT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADACT_SHIFT))&ADC_SC2_ADACT_MASK) /**< ADC0_SC2.ADACT Field                    */
/** @} */

/** @name SC3 - Status and Control Register 3 */ /** @{ */
#define ADC_SC3_AVGS_MASK                        (0x3U)                                              /**< ADC0_SC3.AVGS Mask                      */
#define ADC_SC3_AVGS_SHIFT                       (0U)                                                /**< ADC0_SC3.AVGS Position                  */
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK) /**< ADC0_SC3.AVGS Field                     */
#define ADC_SC3_AVGE_MASK                        (0x4U)                                              /**< ADC0_SC3.AVGE Mask                      */
#define ADC_SC3_AVGE_SHIFT                       (2U)                                                /**< ADC0_SC3.AVGE Position                  */
#define ADC_SC3_AVGE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGE_SHIFT))&ADC_SC3_AVGE_MASK) /**< ADC0_SC3.AVGE Field                     */
#define ADC_SC3_ADCO_MASK                        (0x8U)                                              /**< ADC0_SC3.ADCO Mask                      */
#define ADC_SC3_ADCO_SHIFT                       (3U)                                                /**< ADC0_SC3.ADCO Position                  */
#define ADC_SC3_ADCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADCO_SHIFT))&ADC_SC3_ADCO_MASK) /**< ADC0_SC3.ADCO Field                     */
#define ADC_SC3_CALF_MASK                        (0x40U)                                             /**< ADC0_SC3.CALF Mask                      */
#define ADC_SC3_CALF_SHIFT                       (6U)                                                /**< ADC0_SC3.CALF Position                  */
#define ADC_SC3_CALF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CALF_SHIFT))&ADC_SC3_CALF_MASK) /**< ADC0_SC3.CALF Field                     */
#define ADC_SC3_CAL_MASK                         (0x80U)                                             /**< ADC0_SC3.CAL Mask                       */
#define ADC_SC3_CAL_SHIFT                        (7U)                                                /**< ADC0_SC3.CAL Position                   */
#define ADC_SC3_CAL(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CAL_SHIFT))&ADC_SC3_CAL_MASK) /**< ADC0_SC3.CAL Field                      */
/** @} */

/** @name OFS - Offset Correction Register */ /** @{ */
#define ADC_OFS_OFS_MASK                         (0xFFFFU)                                           /**< ADC0_OFS.OFS Mask                       */
#define ADC_OFS_OFS_SHIFT                        (0U)                                                /**< ADC0_OFS.OFS Position                   */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK) /**< ADC0_OFS.OFS Field                      */
/** @} */

/** @name PG - Plus-Side Gain Register */ /** @{ */
#define ADC_PG_PG_MASK                           (0xFFFFU)                                           /**< ADC0_PG.PG Mask                         */
#define ADC_PG_PG_SHIFT                          (0U)                                                /**< ADC0_PG.PG Position                     */
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK) /**< ADC0_PG.PG Field                        */
/** @} */

/** @name MG - Minus-Side Gain Register */ /** @{ */
#define ADC_MG_MG_MASK                           (0xFFFFU)                                           /**< ADC0_MG.MG Mask                         */
#define ADC_MG_MG_SHIFT                          (0U)                                                /**< ADC0_MG.MG Position                     */
#define ADC_MG_MG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_MG_MG_SHIFT))&ADC_MG_MG_MASK) /**< ADC0_MG.MG Field                        */
/** @} */

/** @name CLPD - Plus-Side General Calibration Value */ /** @{ */
#define ADC_CLPD_CLPD_MASK                       (0x3FU)                                             /**< ADC0_CLPD.CLPD Mask                     */
#define ADC_CLPD_CLPD_SHIFT                      (0U)                                                /**< ADC0_CLPD.CLPD Position                 */
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK) /**< ADC0_CLPD.CLPD Field                    */
/** @} */

/** @name CLPS - Plus-Side General Calibration Value */ /** @{ */
#define ADC_CLPS_CLPS_MASK                       (0x3FU)                                             /**< ADC0_CLPS.CLPS Mask                     */
#define ADC_CLPS_CLPS_SHIFT                      (0U)                                                /**< ADC0_CLPS.CLPS Position                 */
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK) /**< ADC0_CLPS.CLPS Field                    */
/** @} */

/** @name CLP4 - Plus-Side General Calibration Value */ /** @{ */
#define ADC_CLP4_CLP4_MASK                       (0x3FFU)                                            /**< ADC0_CLP4.CLP4 Mask                     */
#define ADC_CLP4_CLP4_SHIFT                      (0U)                                                /**< ADC0_CLP4.CLP4 Position                 */
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK) /**< ADC0_CLP4.CLP4 Field                    */
/** @} */

/** @name CLP3 - Plus-Side General Calibration Value */ /** @{ */
#define ADC_CLP3_CLP3_MASK                       (0x1FFU)                                            /**< ADC0_CLP3.CLP3 Mask                     */
#define ADC_CLP3_CLP3_SHIFT                      (0U)                                                /**< ADC0_CLP3.CLP3 Position                 */
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK) /**< ADC0_CLP3.CLP3 Field                    */
/** @} */

/** @name CLP2 - Plus-Side General Calibration Value */ /** @{ */
#define ADC_CLP2_CLP2_MASK                       (0xFFU)                                             /**< ADC0_CLP2.CLP2 Mask                     */
#define ADC_CLP2_CLP2_SHIFT                      (0U)                                                /**< ADC0_CLP2.CLP2 Position                 */
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK) /**< ADC0_CLP2.CLP2 Field                    */
/** @} */

/** @name CLP1 - Plus-Side General Calibration Value */ /** @{ */
#define ADC_CLP1_CLP1_MASK                       (0x7FU)                                             /**< ADC0_CLP1.CLP1 Mask                     */
#define ADC_CLP1_CLP1_SHIFT                      (0U)                                                /**< ADC0_CLP1.CLP1 Position                 */
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK) /**< ADC0_CLP1.CLP1 Field                    */
/** @} */

/** @name CLP0 - Plus-Side General Calibration Value */ /** @{ */
#define ADC_CLP0_CLP0_MASK                       (0x3FU)                                             /**< ADC0_CLP0.CLP0 Mask                     */
#define ADC_CLP0_CLP0_SHIFT                      (0U)                                                /**< ADC0_CLP0.CLP0 Position                 */
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK) /**< ADC0_CLP0.CLP0 Field                    */
/** @} */

/** @name CLMD - Minus-Side General Calibration Value */ /** @{ */
#define ADC_CLMD_CLMD_MASK                       (0x3FU)                                             /**< ADC0_CLMD.CLMD Mask                     */
#define ADC_CLMD_CLMD_SHIFT                      (0U)                                                /**< ADC0_CLMD.CLMD Position                 */
#define ADC_CLMD_CLMD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMD_CLMD_SHIFT))&ADC_CLMD_CLMD_MASK) /**< ADC0_CLMD.CLMD Field                    */
/** @} */

/** @name CLMS - Minus-Side General Calibration Value */ /** @{ */
#define ADC_CLMS_CLMS_MASK                       (0x3FU)                                             /**< ADC0_CLMS.CLMS Mask                     */
#define ADC_CLMS_CLMS_SHIFT                      (0U)                                                /**< ADC0_CLMS.CLMS Position                 */
#define ADC_CLMS_CLMS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMS_CLMS_SHIFT))&ADC_CLMS_CLMS_MASK) /**< ADC0_CLMS.CLMS Field                    */
/** @} */

/** @name CLM4 - Minus-Side General Calibration Value */ /** @{ */
#define ADC_CLM4_CLM4_MASK                       (0x3FFU)                                            /**< ADC0_CLM4.CLM4 Mask                     */
#define ADC_CLM4_CLM4_SHIFT                      (0U)                                                /**< ADC0_CLM4.CLM4 Position                 */
#define ADC_CLM4_CLM4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM4_CLM4_SHIFT))&ADC_CLM4_CLM4_MASK) /**< ADC0_CLM4.CLM4 Field                    */
/** @} */

/** @name CLM3 - Minus-Side General Calibration Value */ /** @{ */
#define ADC_CLM3_CLM3_MASK                       (0x1FFU)                                            /**< ADC0_CLM3.CLM3 Mask                     */
#define ADC_CLM3_CLM3_SHIFT                      (0U)                                                /**< ADC0_CLM3.CLM3 Position                 */
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM3_CLM3_SHIFT))&ADC_CLM3_CLM3_MASK) /**< ADC0_CLM3.CLM3 Field                    */
/** @} */

/** @name CLM2 - Minus-Side General Calibration Value */ /** @{ */
#define ADC_CLM2_CLM2_MASK                       (0xFFU)                                             /**< ADC0_CLM2.CLM2 Mask                     */
#define ADC_CLM2_CLM2_SHIFT                      (0U)                                                /**< ADC0_CLM2.CLM2 Position                 */
#define ADC_CLM2_CLM2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM2_CLM2_SHIFT))&ADC_CLM2_CLM2_MASK) /**< ADC0_CLM2.CLM2 Field                    */
/** @} */

/** @name CLM1 - Minus-Side General Calibration Value */ /** @{ */
#define ADC_CLM1_CLM1_MASK                       (0x7FU)                                             /**< ADC0_CLM1.CLM1 Mask                     */
#define ADC_CLM1_CLM1_SHIFT                      (0U)                                                /**< ADC0_CLM1.CLM1 Position                 */
#define ADC_CLM1_CLM1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM1_CLM1_SHIFT))&ADC_CLM1_CLM1_MASK) /**< ADC0_CLM1.CLM1 Field                    */
/** @} */

/** @name CLM0 - Minus-Side General Calibration Value */ /** @{ */
#define ADC_CLM0_CLM0_MASK                       (0x3FU)                                             /**< ADC0_CLM0.CLM0 Mask                     */
#define ADC_CLM0_CLM0_SHIFT                      (0U)                                                /**< ADC0_CLM0.CLM0 Position                 */
#define ADC_CLM0_CLM0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM0_CLM0_SHIFT))&ADC_CLM0_CLM0_MASK) /**< ADC0_CLM0.CLM0 Field                    */
/** @} */

/** @} */ /* End group ADC_Register_Masks_GROUP */


/* ADC0 - Peripheral instance base addresses */
#define ADC0_BasePtr                   0x4003B000UL //!< Peripheral base address
#define ADC0                           ((ADC_Type *) ADC0_BasePtr) //!< Freescale base pointer
#define ADC0_BASE_PTR                  (ADC0) //!< Freescale style base pointer
#define ADC0_IRQS { ADC0_IRQn,  }


/** @} */ /* End group ADC_Peripheral_access_layer_GROUP */


/** @brief C Struct for BP */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup BP_Peripheral_access_layer_GROUP BP Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           BP (file:BP_CM0)                     ================ */
/* ================================================================================ */

/**
 * @brief Breakpoint Unit
 */
/**
 * @struct BP_Type
 * @brief  C Struct allowing access to BP registers
 */
typedef struct BP_Type {
   __IO uint32_t  CTRL;                         /**< 0000: FlashPatch Control Register                                  */
        uint8_t   RESERVED_0[4];                /**< 0004: 0x4 bytes                                                    */
   __IO uint32_t  COMP[2];                      /**< 0008: FlashPatch Comparator Register                               */
        uint8_t   RESERVED_1[4032];             /**< 0010: 0xFC0 bytes                                                  */
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


/** @brief Register Masks for BP */

/* -------------------------------------------------------------------------------- */
/* -----------     'BP' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup BP_Register_Masks_GROUP BP Register Masks */
/** @{ */

/** @name CTRL - FlashPatch Control Register */ /** @{ */
#define BP_CTRL_ENABLE_MASK                      (0x1U)                                              /**< BP_CTRL.ENABLE Mask                     */
#define BP_CTRL_ENABLE_SHIFT                     (0U)                                                /**< BP_CTRL.ENABLE Position                 */
#define BP_CTRL_ENABLE(x)                        (((uint32_t)(((uint32_t)(x))<<BP_CTRL_ENABLE_SHIFT))&BP_CTRL_ENABLE_MASK) /**< BP_CTRL.ENABLE Field                    */
#define BP_CTRL_KEY_MASK                         (0x2U)                                              /**< BP_CTRL.KEY Mask                        */
#define BP_CTRL_KEY_SHIFT                        (1U)                                                /**< BP_CTRL.KEY Position                    */
#define BP_CTRL_KEY(x)                           (((uint32_t)(((uint32_t)(x))<<BP_CTRL_KEY_SHIFT))&BP_CTRL_KEY_MASK) /**< BP_CTRL.KEY Field                       */
#define BP_CTRL_NUM_CODE_MASK                    (0xF0U)                                             /**< BP_CTRL.NUM_CODE Mask                   */
#define BP_CTRL_NUM_CODE_SHIFT                   (4U)                                                /**< BP_CTRL.NUM_CODE Position               */
#define BP_CTRL_NUM_CODE(x)                      (((uint32_t)(((uint32_t)(x))<<BP_CTRL_NUM_CODE_SHIFT))&BP_CTRL_NUM_CODE_MASK) /**< BP_CTRL.NUM_CODE Field                  */
/** @} */

/** @name COMP - FlashPatch Comparator Register %s */ /** @{ */
#define BP_COMP_ENABLE_MASK                      (0x1U)                                              /**< BP_COMP.ENABLE Mask                     */
#define BP_COMP_ENABLE_SHIFT                     (0U)                                                /**< BP_COMP.ENABLE Position                 */
#define BP_COMP_ENABLE(x)                        (((uint32_t)(((uint32_t)(x))<<BP_COMP_ENABLE_SHIFT))&BP_COMP_ENABLE_MASK) /**< BP_COMP.ENABLE Field                    */
#define BP_COMP_COMP_MASK                        (0x1FFFFFFCU)                                       /**< BP_COMP.COMP Mask                       */
#define BP_COMP_COMP_SHIFT                       (2U)                                                /**< BP_COMP.COMP Position                   */
#define BP_COMP_COMP(x)                          (((uint32_t)(((uint32_t)(x))<<BP_COMP_COMP_SHIFT))&BP_COMP_COMP_MASK) /**< BP_COMP.COMP Field                      */
#define BP_COMP_BP_MATCH_MASK                    (0xC0000000U)                                       /**< BP_COMP.BP_MATCH Mask                   */
#define BP_COMP_BP_MATCH_SHIFT                   (30U)                                               /**< BP_COMP.BP_MATCH Position               */
#define BP_COMP_BP_MATCH(x)                      (((uint32_t)(((uint32_t)(x))<<BP_COMP_BP_MATCH_SHIFT))&BP_COMP_BP_MATCH_MASK) /**< BP_COMP.BP_MATCH Field                  */
/** @} */

/** @} */ /* End group BP_Register_Masks_GROUP */


/* BP - Peripheral instance base addresses */
#define BP_BasePtr                     0xE0002000UL //!< Peripheral base address
#define BP                             ((BP_Type *) BP_BasePtr) //!< Freescale base pointer
#define BP_BASE_PTR                    (BP) //!< Freescale style base pointer

/** @} */ /* End group BP_Peripheral_access_layer_GROUP */


/** @brief C Struct for CMP */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           CMP0 (file:CMP0_PSTM_TRIGM)          ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */
/**
 * @struct CMP_Type
 * @brief  C Struct allowing access to CMP registers
 */
typedef struct CMP_Type {
   __IO uint8_t   CR0;                          /**< 0000: CMP Control Register 0                                       */
   __IO uint8_t   CR1;                          /**< 0001: CMP Control Register 1                                       */
   __IO uint8_t   FPR;                          /**< 0002: CMP Filter Period Register                                   */
   __IO uint8_t   SCR;                          /**< 0003: CMP Status and Control Register                              */
   __IO uint8_t   DACCR;                        /**< 0004: DAC Control Register                                         */
   __IO uint8_t   MUXCR;                        /**< 0005: MUX Control Register                                         */
} CMP_Type;


/** @brief Register Masks for CMP */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMP0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup CMP_Register_Masks_GROUP CMP Register Masks */
/** @{ */

/** @name CR0 - CMP Control Register 0 */ /** @{ */
#define CMP_CR0_HYSTCTR_MASK                     (0x3U)                                              /**< CMP0_CR0.HYSTCTR Mask                   */
#define CMP_CR0_HYSTCTR_SHIFT                    (0U)                                                /**< CMP0_CR0.HYSTCTR Position               */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK) /**< CMP0_CR0.HYSTCTR Field                  */
#define CMP_CR0_FILTER_CNT_MASK                  (0x70U)                                             /**< CMP0_CR0.FILTER_CNT Mask                */
#define CMP_CR0_FILTER_CNT_SHIFT                 (4U)                                                /**< CMP0_CR0.FILTER_CNT Position            */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK) /**< CMP0_CR0.FILTER_CNT Field               */
/** @} */

/** @name CR1 - CMP Control Register 1 */ /** @{ */
#define CMP_CR1_EN_MASK                          (0x1U)                                              /**< CMP0_CR1.EN Mask                        */
#define CMP_CR1_EN_SHIFT                         (0U)                                                /**< CMP0_CR1.EN Position                    */
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_EN_SHIFT))&CMP_CR1_EN_MASK) /**< CMP0_CR1.EN Field                       */
#define CMP_CR1_OPE_MASK                         (0x2U)                                              /**< CMP0_CR1.OPE Mask                       */
#define CMP_CR1_OPE_SHIFT                        (1U)                                                /**< CMP0_CR1.OPE Position                   */
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_OPE_SHIFT))&CMP_CR1_OPE_MASK) /**< CMP0_CR1.OPE Field                      */
#define CMP_CR1_COS_MASK                         (0x4U)                                              /**< CMP0_CR1.COS Mask                       */
#define CMP_CR1_COS_SHIFT                        (2U)                                                /**< CMP0_CR1.COS Position                   */
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_COS_SHIFT))&CMP_CR1_COS_MASK) /**< CMP0_CR1.COS Field                      */
#define CMP_CR1_INV_MASK                         (0x8U)                                              /**< CMP0_CR1.INV Mask                       */
#define CMP_CR1_INV_SHIFT                        (3U)                                                /**< CMP0_CR1.INV Position                   */
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_INV_SHIFT))&CMP_CR1_INV_MASK) /**< CMP0_CR1.INV Field                      */
#define CMP_CR1_PMODE_MASK                       (0x10U)                                             /**< CMP0_CR1.PMODE Mask                     */
#define CMP_CR1_PMODE_SHIFT                      (4U)                                                /**< CMP0_CR1.PMODE Position                 */
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_PMODE_SHIFT))&CMP_CR1_PMODE_MASK) /**< CMP0_CR1.PMODE Field                    */
#define CMP_CR1_TRIGM_MASK                       (0x20U)                                             /**< CMP0_CR1.TRIGM Mask                     */
#define CMP_CR1_TRIGM_SHIFT                      (5U)                                                /**< CMP0_CR1.TRIGM Position                 */
#define CMP_CR1_TRIGM(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_TRIGM_SHIFT))&CMP_CR1_TRIGM_MASK) /**< CMP0_CR1.TRIGM Field                    */
#define CMP_CR1_WE_MASK                          (0x40U)                                             /**< CMP0_CR1.WE Mask                        */
#define CMP_CR1_WE_SHIFT                         (6U)                                                /**< CMP0_CR1.WE Position                    */
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_WE_SHIFT))&CMP_CR1_WE_MASK) /**< CMP0_CR1.WE Field                       */
#define CMP_CR1_SE_MASK                          (0x80U)                                             /**< CMP0_CR1.SE Mask                        */
#define CMP_CR1_SE_SHIFT                         (7U)                                                /**< CMP0_CR1.SE Position                    */
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_SE_SHIFT))&CMP_CR1_SE_MASK) /**< CMP0_CR1.SE Field                       */
/** @} */

/** @name FPR - CMP Filter Period Register */ /** @{ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFU)                                             /**< CMP0_FPR.FILT_PER Mask                  */
#define CMP_FPR_FILT_PER_SHIFT                   (0U)                                                /**< CMP0_FPR.FILT_PER Position              */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK) /**< CMP0_FPR.FILT_PER Field                 */
/** @} */

/** @name SCR - CMP Status and Control Register */ /** @{ */
#define CMP_SCR_COUT_MASK                        (0x1U)                                              /**< CMP0_SCR.COUT Mask                      */
#define CMP_SCR_COUT_SHIFT                       (0U)                                                /**< CMP0_SCR.COUT Position                  */
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x))<<CMP_SCR_COUT_SHIFT))&CMP_SCR_COUT_MASK) /**< CMP0_SCR.COUT Field                     */
#define CMP_SCR_CFF_MASK                         (0x2U)                                              /**< CMP0_SCR.CFF Mask                       */
#define CMP_SCR_CFF_SHIFT                        (1U)                                                /**< CMP0_SCR.CFF Position                   */
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFF_SHIFT))&CMP_SCR_CFF_MASK) /**< CMP0_SCR.CFF Field                      */
#define CMP_SCR_CFR_MASK                         (0x4U)                                              /**< CMP0_SCR.CFR Mask                       */
#define CMP_SCR_CFR_SHIFT                        (2U)                                                /**< CMP0_SCR.CFR Position                   */
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFR_SHIFT))&CMP_SCR_CFR_MASK) /**< CMP0_SCR.CFR Field                      */
#define CMP_SCR_IEF_MASK                         (0x8U)                                              /**< CMP0_SCR.IEF Mask                       */
#define CMP_SCR_IEF_SHIFT                        (3U)                                                /**< CMP0_SCR.IEF Position                   */
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IEF_SHIFT))&CMP_SCR_IEF_MASK) /**< CMP0_SCR.IEF Field                      */
#define CMP_SCR_IER_MASK                         (0x10U)                                             /**< CMP0_SCR.IER Mask                       */
#define CMP_SCR_IER_SHIFT                        (4U)                                                /**< CMP0_SCR.IER Position                   */
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IER_SHIFT))&CMP_SCR_IER_MASK) /**< CMP0_SCR.IER Field                      */
#define CMP_SCR_DMAEN_MASK                       (0x40U)                                             /**< CMP0_SCR.DMAEN Mask                     */
#define CMP_SCR_DMAEN_SHIFT                      (6U)                                                /**< CMP0_SCR.DMAEN Position                 */
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_SCR_DMAEN_SHIFT))&CMP_SCR_DMAEN_MASK) /**< CMP0_SCR.DMAEN Field                    */
/** @} */

/** @name DACCR - DAC Control Register */ /** @{ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FU)                                             /**< CMP0_DACCR.VOSEL Mask                   */
#define CMP_DACCR_VOSEL_SHIFT                    (0U)                                                /**< CMP0_DACCR.VOSEL Position               */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK) /**< CMP0_DACCR.VOSEL Field                  */
#define CMP_DACCR_VRSEL_MASK                     (0x40U)                                             /**< CMP0_DACCR.VRSEL Mask                   */
#define CMP_DACCR_VRSEL_SHIFT                    (6U)                                                /**< CMP0_DACCR.VRSEL Position               */
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VRSEL_SHIFT))&CMP_DACCR_VRSEL_MASK) /**< CMP0_DACCR.VRSEL Field                  */
#define CMP_DACCR_DACEN_MASK                     (0x80U)                                             /**< CMP0_DACCR.DACEN Mask                   */
#define CMP_DACCR_DACEN_SHIFT                    (7U)                                                /**< CMP0_DACCR.DACEN Position               */
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_DACEN_SHIFT))&CMP_DACCR_DACEN_MASK) /**< CMP0_DACCR.DACEN Field                  */
/** @} */

/** @name MUXCR - MUX Control Register */ /** @{ */
#define CMP_MUXCR_MSEL_MASK                      (0x7U)                                              /**< CMP0_MUXCR.MSEL Mask                    */
#define CMP_MUXCR_MSEL_SHIFT                     (0U)                                                /**< CMP0_MUXCR.MSEL Position                */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK) /**< CMP0_MUXCR.MSEL Field                   */
#define CMP_MUXCR_PSEL_MASK                      (0x38U)                                             /**< CMP0_MUXCR.PSEL Mask                    */
#define CMP_MUXCR_PSEL_SHIFT                     (3U)                                                /**< CMP0_MUXCR.PSEL Position                */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK) /**< CMP0_MUXCR.PSEL Field                   */
#define CMP_MUXCR_PSTM_MASK                      (0x80U)                                             /**< CMP0_MUXCR.PSTM Mask                    */
#define CMP_MUXCR_PSTM_SHIFT                     (7U)                                                /**< CMP0_MUXCR.PSTM Position                */
#define CMP_MUXCR_PSTM(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSTM_SHIFT))&CMP_MUXCR_PSTM_MASK) /**< CMP0_MUXCR.PSTM Field                   */
/** @} */

/** @} */ /* End group CMP_Register_Masks_GROUP */


/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0x40073000UL //!< Peripheral base address
#define CMP0                           ((CMP_Type *) CMP0_BasePtr) //!< Freescale base pointer
#define CMP0_BASE_PTR                  (CMP0) //!< Freescale style base pointer
#define CMP0_IRQS { CMP0_IRQn,  }


/** @} */ /* End group CMP_Peripheral_access_layer_GROUP */


/** @brief C Struct for DAC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup DAC_Peripheral_access_layer_GROUP DAC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           DAC0 (file:DAC0_2DAT_MKL05)          ================ */
/* ================================================================================ */

/**
 * @brief 12-Bit Digital-to-Analog Converter
 */
#define DAC_DAT_COUNT        2          /**< Number of Data registers                           */
/**
 * @struct DAC_Type
 * @brief  C Struct allowing access to DAC registers
 */
typedef struct DAC_Type {
   union {                                      /**< 0000: (size=0004)                                                  */
      struct {
         __IO uint8_t   DATL;                   /**< 0000: Data Low Register                                            */
         __IO uint8_t   DATH;                   /**< 0001: Data High Register                                           */
      } DAT[DAC_DAT_COUNT];                     /**< 0000: (cluster: size=0x0004, 4)                                    */
      __IO uint16_t  DATA[DAC_DAT_COUNT];       /**< 0000: Data Register                                                */
   };
        uint8_t   RESERVED_1[28];               /**< 0004: 0x1C bytes                                                   */
   __IO uint8_t   SR;                           /**< 0020: Status Register                                              */
   __IO uint8_t   C0;                           /**< 0021: Control Register 0                                           */
   __IO uint8_t   C1;                           /**< 0022: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0023: Control Register 2                                           */
} DAC_Type;


/** @brief Register Masks for DAC */

/* -------------------------------------------------------------------------------- */
/* -----------     'DAC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup DAC_Register_Masks_GROUP DAC Register Masks */
/** @{ */

/** @name DATL - Data Low Register */ /** @{ */
#define DAC_DATL_DATA_MASK                       (0xFFU)                                             /**< DAC0_DATL.DATA Mask                     */
#define DAC_DATL_DATA_SHIFT                      (0U)                                                /**< DAC0_DATL.DATA Position                 */
#define DAC_DATL_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA_SHIFT))&DAC_DATL_DATA_MASK) /**< DAC0_DATL.DATA Field                    */
/** @} */

/** @name DATH - Data High Register */ /** @{ */
#define DAC_DATH_DATA_MASK                       (0xFU)                                              /**< DAC0_DATH.DATA Mask                     */
#define DAC_DATH_DATA_SHIFT                      (0U)                                                /**< DAC0_DATH.DATA Position                 */
#define DAC_DATH_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA_SHIFT))&DAC_DATH_DATA_MASK) /**< DAC0_DATH.DATA Field                    */
/** @} */

/** @name DATA - Data Register */ /** @{ */
#define DAC_DATA_DATA_MASK                       (0xFFFU)                                            /**< DAC0_DATA.DATA Mask                     */
#define DAC_DATA_DATA_SHIFT                      (0U)                                                /**< DAC0_DATA.DATA Position                 */
#define DAC_DATA_DATA(x)                         (((uint16_t)(((uint16_t)(x))<<DAC_DATA_DATA_SHIFT))&DAC_DATA_DATA_MASK) /**< DAC0_DATA.DATA Field                    */
/** @} */

/** @name SR - Status Register */ /** @{ */
#define DAC_SR_DACBFRPBF_MASK                    (0x1U)                                              /**< DAC0_SR.DACBFRPBF Mask                  */
#define DAC_SR_DACBFRPBF_SHIFT                   (0U)                                                /**< DAC0_SR.DACBFRPBF Position              */
#define DAC_SR_DACBFRPBF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPBF_SHIFT))&DAC_SR_DACBFRPBF_MASK) /**< DAC0_SR.DACBFRPBF Field                 */
#define DAC_SR_DACBFRPTF_MASK                    (0x2U)                                              /**< DAC0_SR.DACBFRPTF Mask                  */
#define DAC_SR_DACBFRPTF_SHIFT                   (1U)                                                /**< DAC0_SR.DACBFRPTF Position              */
#define DAC_SR_DACBFRPTF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPTF_SHIFT))&DAC_SR_DACBFRPTF_MASK) /**< DAC0_SR.DACBFRPTF Field                 */
/** @} */

/** @name C0 - Control Register 0 */ /** @{ */
#define DAC_C0_DACBBIEN_MASK                     (0x1U)                                              /**< DAC0_C0.DACBBIEN Mask                   */
#define DAC_C0_DACBBIEN_SHIFT                    (0U)                                                /**< DAC0_C0.DACBBIEN Position               */
#define DAC_C0_DACBBIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBBIEN_SHIFT))&DAC_C0_DACBBIEN_MASK) /**< DAC0_C0.DACBBIEN Field                  */
#define DAC_C0_DACBTIEN_MASK                     (0x2U)                                              /**< DAC0_C0.DACBTIEN Mask                   */
#define DAC_C0_DACBTIEN_SHIFT                    (1U)                                                /**< DAC0_C0.DACBTIEN Position               */
#define DAC_C0_DACBTIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBTIEN_SHIFT))&DAC_C0_DACBTIEN_MASK) /**< DAC0_C0.DACBTIEN Field                  */
#define DAC_C0_LPEN_MASK                         (0x8U)                                              /**< DAC0_C0.LPEN Mask                       */
#define DAC_C0_LPEN_SHIFT                        (3U)                                                /**< DAC0_C0.LPEN Position                   */
#define DAC_C0_LPEN(x)                           (((uint8_t)(((uint8_t)(x))<<DAC_C0_LPEN_SHIFT))&DAC_C0_LPEN_MASK) /**< DAC0_C0.LPEN Field                      */
#define DAC_C0_DACSWTRG_MASK                     (0x10U)                                             /**< DAC0_C0.DACSWTRG Mask                   */
#define DAC_C0_DACSWTRG_SHIFT                    (4U)                                                /**< DAC0_C0.DACSWTRG Position               */
#define DAC_C0_DACSWTRG(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACSWTRG_SHIFT))&DAC_C0_DACSWTRG_MASK) /**< DAC0_C0.DACSWTRG Field                  */
#define DAC_C0_DACTRGSEL_MASK                    (0x20U)                                             /**< DAC0_C0.DACTRGSEL Mask                  */
#define DAC_C0_DACTRGSEL_SHIFT                   (5U)                                                /**< DAC0_C0.DACTRGSEL Position              */
#define DAC_C0_DACTRGSEL(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACTRGSEL_SHIFT))&DAC_C0_DACTRGSEL_MASK) /**< DAC0_C0.DACTRGSEL Field                 */
#define DAC_C0_DACRFS_MASK                       (0x40U)                                             /**< DAC0_C0.DACRFS Mask                     */
#define DAC_C0_DACRFS_SHIFT                      (6U)                                                /**< DAC0_C0.DACRFS Position                 */
#define DAC_C0_DACRFS(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACRFS_SHIFT))&DAC_C0_DACRFS_MASK) /**< DAC0_C0.DACRFS Field                    */
#define DAC_C0_DACEN_MASK                        (0x80U)                                             /**< DAC0_C0.DACEN Mask                      */
#define DAC_C0_DACEN_SHIFT                       (7U)                                                /**< DAC0_C0.DACEN Position                  */
#define DAC_C0_DACEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACEN_SHIFT))&DAC_C0_DACEN_MASK) /**< DAC0_C0.DACEN Field                     */
/** @} */

/** @name C1 - Control Register 1 */ /** @{ */
#define DAC_C1_DACBFEN_MASK                      (0x1U)                                              /**< DAC0_C1.DACBFEN Mask                    */
#define DAC_C1_DACBFEN_SHIFT                     (0U)                                                /**< DAC0_C1.DACBFEN Position                */
#define DAC_C1_DACBFEN(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFEN_SHIFT))&DAC_C1_DACBFEN_MASK) /**< DAC0_C1.DACBFEN Field                   */
#define DAC_C1_DACBFMD_MASK                      (0x4U)                                              /**< DAC0_C1.DACBFMD Mask                    */
#define DAC_C1_DACBFMD_SHIFT                     (2U)                                                /**< DAC0_C1.DACBFMD Position                */
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK) /**< DAC0_C1.DACBFMD Field                   */
#define DAC_C1_DMAEN_MASK                        (0x80U)                                             /**< DAC0_C1.DMAEN Mask                      */
#define DAC_C1_DMAEN_SHIFT                       (7U)                                                /**< DAC0_C1.DMAEN Position                  */
#define DAC_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C1_DMAEN_SHIFT))&DAC_C1_DMAEN_MASK) /**< DAC0_C1.DMAEN Field                     */
/** @} */

/** @name C2 - Control Register 2 */ /** @{ */
#define DAC_C2_DACBFUP_MASK                      (0x1U)                                              /**< DAC0_C2.DACBFUP Mask                    */
#define DAC_C2_DACBFUP_SHIFT                     (0U)                                                /**< DAC0_C2.DACBFUP Position                */
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK) /**< DAC0_C2.DACBFUP Field                   */
#define DAC_C2_DACBFRP_MASK                      (0x10U)                                             /**< DAC0_C2.DACBFRP Mask                    */
#define DAC_C2_DACBFRP_SHIFT                     (4U)                                                /**< DAC0_C2.DACBFRP Position                */
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK) /**< DAC0_C2.DACBFRP Field                   */
/** @} */

/** @} */ /* End group DAC_Register_Masks_GROUP */


/* DAC0 - Peripheral instance base addresses */
#define DAC0_BasePtr                   0x4003F000UL //!< Peripheral base address
#define DAC0                           ((DAC_Type *) DAC0_BasePtr) //!< Freescale base pointer
#define DAC0_BASE_PTR                  (DAC0) //!< Freescale style base pointer
#define DAC0_IRQS { DAC0_IRQn,  }


/** @} */ /* End group DAC_Peripheral_access_layer_GROUP */


/** @brief C Struct for DMA0 */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup DMA0_Peripheral_access_layer_GROUP DMA0 Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           DMA0 (file:DMA0_MKL)                 ================ */
/* ================================================================================ */

/**
 * @brief Enhanced direct memory access controller
 */
/**
 * @struct DMA_Type
 * @brief  C Struct allowing access to DMA0 registers
 */
typedef struct DMA_Type {
        uint8_t   RESERVED_0[256];              /**< 0000: 0x100 bytes                                                  */
   struct {
      __IO uint32_t  SAR;                       /**< 0100: Source Address Register                                      */
      __IO uint32_t  DAR;                       /**< 0104: Destination Address Register                                 */
      union {                                   /**< 0108: (size=0004)                                                  */
         __IO uint32_t  DSR_BCR;                /**< 0108: DMA Status / Byte Count Register                             */
         struct {                               /**< 0108: (size=0004)                                                  */
                 uint8_t   RESERVED_1[3];       /**< 0108: 0x3 bytes                                                    */
            __IO uint8_t   DSR;                 /**< 010B: DMA Status Register                                          */
         };
      };
      __IO uint32_t  DCR;                       /**< 010C: DMA Control Register                                         */
   } DMA[4];                                    /**< 0100: (cluster: size=0x0040, 64)                                   */
} DMA_Type;


/** @brief Register Masks for DMA0 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup DMA0_Register_Masks_GROUP DMA0 Register Masks */
/** @{ */

/** @name SAR - Source Address Register */ /** @{ */
#define DMA_SAR_ADDR_MASK                        (0xFFFFFFFFU)                                       /**< DMA0_SAR.ADDR Mask                      */
#define DMA_SAR_ADDR_SHIFT                       (0U)                                                /**< DMA0_SAR.ADDR Position                  */
#define DMA_SAR_ADDR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_SAR_ADDR_SHIFT))&DMA_SAR_ADDR_MASK) /**< DMA0_SAR.ADDR Field                     */
/** @} */

/** @name DAR - Destination Address Register */ /** @{ */
#define DMA_DAR_ADDR_MASK                        (0xFFFFFFFFU)                                       /**< DMA0_DAR.ADDR Mask                      */
#define DMA_DAR_ADDR_SHIFT                       (0U)                                                /**< DMA0_DAR.ADDR Position                  */
#define DMA_DAR_ADDR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DAR_ADDR_SHIFT))&DMA_DAR_ADDR_MASK) /**< DMA0_DAR.ADDR Field                     */
/** @} */

/** @name DSR_BCR - DMA Status / Byte Count Register */ /** @{ */
#define DMA_DSR_BCR_BCR_MASK                     (0xFFFFFFU)                                         /**< DMA0_DSR_BCR.BCR Mask                   */
#define DMA_DSR_BCR_BCR_SHIFT                    (0U)                                                /**< DMA0_DSR_BCR.BCR Position               */
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BCR_SHIFT))&DMA_DSR_BCR_BCR_MASK) /**< DMA0_DSR_BCR.BCR Field                  */
#define DMA_DSR_BCR_DONE_MASK                    (0x1000000U)                                        /**< DMA0_DSR_BCR.DONE Mask                  */
#define DMA_DSR_BCR_DONE_SHIFT                   (24U)                                               /**< DMA0_DSR_BCR.DONE Position              */
#define DMA_DSR_BCR_DONE(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_DONE_SHIFT))&DMA_DSR_BCR_DONE_MASK) /**< DMA0_DSR_BCR.DONE Field                 */
#define DMA_DSR_BCR_BSY_MASK                     (0x2000000U)                                        /**< DMA0_DSR_BCR.BSY Mask                   */
#define DMA_DSR_BCR_BSY_SHIFT                    (25U)                                               /**< DMA0_DSR_BCR.BSY Position               */
#define DMA_DSR_BCR_BSY(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BSY_SHIFT))&DMA_DSR_BCR_BSY_MASK) /**< DMA0_DSR_BCR.BSY Field                  */
#define DMA_DSR_BCR_REQ_MASK                     (0x4000000U)                                        /**< DMA0_DSR_BCR.REQ Mask                   */
#define DMA_DSR_BCR_REQ_SHIFT                    (26U)                                               /**< DMA0_DSR_BCR.REQ Position               */
#define DMA_DSR_BCR_REQ(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_REQ_SHIFT))&DMA_DSR_BCR_REQ_MASK) /**< DMA0_DSR_BCR.REQ Field                  */
#define DMA_DSR_BCR_BED_MASK                     (0x10000000U)                                       /**< DMA0_DSR_BCR.BED Mask                   */
#define DMA_DSR_BCR_BED_SHIFT                    (28U)                                               /**< DMA0_DSR_BCR.BED Position               */
#define DMA_DSR_BCR_BED(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BED_SHIFT))&DMA_DSR_BCR_BED_MASK) /**< DMA0_DSR_BCR.BED Field                  */
#define DMA_DSR_BCR_BES_MASK                     (0x20000000U)                                       /**< DMA0_DSR_BCR.BES Mask                   */
#define DMA_DSR_BCR_BES_SHIFT                    (29U)                                               /**< DMA0_DSR_BCR.BES Position               */
#define DMA_DSR_BCR_BES(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_BES_SHIFT))&DMA_DSR_BCR_BES_MASK) /**< DMA0_DSR_BCR.BES Field                  */
#define DMA_DSR_BCR_CE_MASK                      (0x40000000U)                                       /**< DMA0_DSR_BCR.CE Mask                    */
#define DMA_DSR_BCR_CE_SHIFT                     (30U)                                               /**< DMA0_DSR_BCR.CE Position                */
#define DMA_DSR_BCR_CE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DSR_BCR_CE_SHIFT))&DMA_DSR_BCR_CE_MASK) /**< DMA0_DSR_BCR.CE Field                   */
/** @} */

/** @name DSR - DMA Status Register */ /** @{ */
#define DMA_DSR_DONE_MASK                        (0x1U)                                              /**< DMA0_DSR.DONE Mask                      */
#define DMA_DSR_DONE_SHIFT                       (0U)                                                /**< DMA0_DSR.DONE Position                  */
#define DMA_DSR_DONE(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_DSR_DONE_SHIFT))&DMA_DSR_DONE_MASK) /**< DMA0_DSR.DONE Field                     */
#define DMA_DSR_BSY_MASK                         (0x2U)                                              /**< DMA0_DSR.BSY Mask                       */
#define DMA_DSR_BSY_SHIFT                        (1U)                                                /**< DMA0_DSR.BSY Position                   */
#define DMA_DSR_BSY(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BSY_SHIFT))&DMA_DSR_BSY_MASK) /**< DMA0_DSR.BSY Field                      */
#define DMA_DSR_REQ_MASK                         (0x4U)                                              /**< DMA0_DSR.REQ Mask                       */
#define DMA_DSR_REQ_SHIFT                        (2U)                                                /**< DMA0_DSR.REQ Position                   */
#define DMA_DSR_REQ(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_REQ_SHIFT))&DMA_DSR_REQ_MASK) /**< DMA0_DSR.REQ Field                      */
#define DMA_DSR_BED_MASK                         (0x10U)                                             /**< DMA0_DSR.BED Mask                       */
#define DMA_DSR_BED_SHIFT                        (4U)                                                /**< DMA0_DSR.BED Position                   */
#define DMA_DSR_BED(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BED_SHIFT))&DMA_DSR_BED_MASK) /**< DMA0_DSR.BED Field                      */
#define DMA_DSR_BES_MASK                         (0x20U)                                             /**< DMA0_DSR.BES Mask                       */
#define DMA_DSR_BES_SHIFT                        (5U)                                                /**< DMA0_DSR.BES Position                   */
#define DMA_DSR_BES(x)                           (((uint8_t)(((uint8_t)(x))<<DMA_DSR_BES_SHIFT))&DMA_DSR_BES_MASK) /**< DMA0_DSR.BES Field                      */
#define DMA_DSR_CE_MASK                          (0x40U)                                             /**< DMA0_DSR.CE Mask                        */
#define DMA_DSR_CE_SHIFT                         (6U)                                                /**< DMA0_DSR.CE Position                    */
#define DMA_DSR_CE(x)                            (((uint8_t)(((uint8_t)(x))<<DMA_DSR_CE_SHIFT))&DMA_DSR_CE_MASK) /**< DMA0_DSR.CE Field                       */
/** @} */

/** @name DCR - DMA Control Register */ /** @{ */
#define DMA_DCR_LCH2_MASK                        (0x3U)                                              /**< DMA0_DCR.LCH2 Mask                      */
#define DMA_DCR_LCH2_SHIFT                       (0U)                                                /**< DMA0_DCR.LCH2 Position                  */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH2_SHIFT))&DMA_DCR_LCH2_MASK) /**< DMA0_DCR.LCH2 Field                     */
#define DMA_DCR_LCH1_MASK                        (0xCU)                                              /**< DMA0_DCR.LCH1 Mask                      */
#define DMA_DCR_LCH1_SHIFT                       (2U)                                                /**< DMA0_DCR.LCH1 Position                  */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LCH1_SHIFT))&DMA_DCR_LCH1_MASK) /**< DMA0_DCR.LCH1 Field                     */
#define DMA_DCR_LINKCC_MASK                      (0x30U)                                             /**< DMA0_DCR.LINKCC Mask                    */
#define DMA_DCR_LINKCC_SHIFT                     (4U)                                                /**< DMA0_DCR.LINKCC Position                */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_LINKCC_SHIFT))&DMA_DCR_LINKCC_MASK) /**< DMA0_DCR.LINKCC Field                   */
#define DMA_DCR_D_REQ_MASK                       (0x80U)                                             /**< DMA0_DCR.D_REQ Mask                     */
#define DMA_DCR_D_REQ_SHIFT                      (7U)                                                /**< DMA0_DCR.D_REQ Position                 */
#define DMA_DCR_D_REQ(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_D_REQ_SHIFT))&DMA_DCR_D_REQ_MASK) /**< DMA0_DCR.D_REQ Field                    */
#define DMA_DCR_DMOD_MASK                        (0xF00U)                                            /**< DMA0_DCR.DMOD Mask                      */
#define DMA_DCR_DMOD_SHIFT                       (8U)                                                /**< DMA0_DCR.DMOD Position                  */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DMOD_SHIFT))&DMA_DCR_DMOD_MASK) /**< DMA0_DCR.DMOD Field                     */
#define DMA_DCR_SMOD_MASK                        (0xF000U)                                           /**< DMA0_DCR.SMOD Mask                      */
#define DMA_DCR_SMOD_SHIFT                       (12U)                                               /**< DMA0_DCR.SMOD Position                  */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SMOD_SHIFT))&DMA_DCR_SMOD_MASK) /**< DMA0_DCR.SMOD Field                     */
#define DMA_DCR_START_MASK                       (0x10000U)                                          /**< DMA0_DCR.START Mask                     */
#define DMA_DCR_START_SHIFT                      (16U)                                               /**< DMA0_DCR.START Position                 */
#define DMA_DCR_START(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_START_SHIFT))&DMA_DCR_START_MASK) /**< DMA0_DCR.START Field                    */
#define DMA_DCR_DSIZE_MASK                       (0x60000U)                                          /**< DMA0_DCR.DSIZE Mask                     */
#define DMA_DCR_DSIZE_SHIFT                      (17U)                                               /**< DMA0_DCR.DSIZE Position                 */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DSIZE_SHIFT))&DMA_DCR_DSIZE_MASK) /**< DMA0_DCR.DSIZE Field                    */
#define DMA_DCR_DINC_MASK                        (0x80000U)                                          /**< DMA0_DCR.DINC Mask                      */
#define DMA_DCR_DINC_SHIFT                       (19U)                                               /**< DMA0_DCR.DINC Position                  */
#define DMA_DCR_DINC(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_DINC_SHIFT))&DMA_DCR_DINC_MASK) /**< DMA0_DCR.DINC Field                     */
#define DMA_DCR_SSIZE_MASK                       (0x300000U)                                         /**< DMA0_DCR.SSIZE Mask                     */
#define DMA_DCR_SSIZE_SHIFT                      (20U)                                               /**< DMA0_DCR.SSIZE Position                 */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SSIZE_SHIFT))&DMA_DCR_SSIZE_MASK) /**< DMA0_DCR.SSIZE Field                    */
#define DMA_DCR_SINC_MASK                        (0x400000U)                                         /**< DMA0_DCR.SINC Mask                      */
#define DMA_DCR_SINC_SHIFT                       (22U)                                               /**< DMA0_DCR.SINC Position                  */
#define DMA_DCR_SINC(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_SINC_SHIFT))&DMA_DCR_SINC_MASK) /**< DMA0_DCR.SINC Field                     */
#define DMA_DCR_EADREQ_MASK                      (0x800000U)                                         /**< DMA0_DCR.EADREQ Mask                    */
#define DMA_DCR_EADREQ_SHIFT                     (23U)                                               /**< DMA0_DCR.EADREQ Position                */
#define DMA_DCR_EADREQ(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_DCR_EADREQ_SHIFT))&DMA_DCR_EADREQ_MASK) /**< DMA0_DCR.EADREQ Field                   */
#define DMA_DCR_AA_MASK                          (0x10000000U)                                       /**< DMA0_DCR.AA Mask                        */
#define DMA_DCR_AA_SHIFT                         (28U)                                               /**< DMA0_DCR.AA Position                    */
#define DMA_DCR_AA(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_DCR_AA_SHIFT))&DMA_DCR_AA_MASK) /**< DMA0_DCR.AA Field                       */
#define DMA_DCR_CS_MASK                          (0x20000000U)                                       /**< DMA0_DCR.CS Mask                        */
#define DMA_DCR_CS_SHIFT                         (29U)                                               /**< DMA0_DCR.CS Position                    */
#define DMA_DCR_CS(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_DCR_CS_SHIFT))&DMA_DCR_CS_MASK) /**< DMA0_DCR.CS Field                       */
#define DMA_DCR_ERQ_MASK                         (0x40000000U)                                       /**< DMA0_DCR.ERQ Mask                       */
#define DMA_DCR_ERQ_SHIFT                        (30U)                                               /**< DMA0_DCR.ERQ Position                   */
#define DMA_DCR_ERQ(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_DCR_ERQ_SHIFT))&DMA_DCR_ERQ_MASK) /**< DMA0_DCR.ERQ Field                      */
#define DMA_DCR_EINT_MASK                        (0x80000000U)                                       /**< DMA0_DCR.EINT Mask                      */
#define DMA_DCR_EINT_SHIFT                       (31U)                                               /**< DMA0_DCR.EINT Position                  */
#define DMA_DCR_EINT(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_DCR_EINT_SHIFT))&DMA_DCR_EINT_MASK) /**< DMA0_DCR.EINT Field                     */
/** @} */

/** @} */ /* End group DMA0_Register_Masks_GROUP */


/* DMA0 - Peripheral instance base addresses */
#define DMA0_BasePtr                   0x40008000UL //!< Peripheral base address
#define DMA0                           ((DMA_Type *) DMA0_BasePtr) //!< Freescale base pointer
#define DMA0_BASE_PTR                  (DMA0) //!< Freescale style base pointer
#define DMA0_IRQS { DMA0_IRQn, DMA1_IRQn, DMA2_IRQn, DMA3_IRQn,  }


/** @} */ /* End group DMA0_Peripheral_access_layer_GROUP */


/** @brief C Struct for DMAMUX */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           DMAMUX0 (file:DMAMUX0_4CH_TRIG_MKL25Z4)       ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */
/**
 * @struct DMAMUX_Type
 * @brief  C Struct allowing access to DMAMUX registers
 */
typedef struct DMAMUX_Type {
   __IO uint8_t   CHCFG[4];                     /**< 0000: Channel Configuration Register                               */
} DMAMUX_Type;


/** @brief Register Masks for DMAMUX */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMAMUX0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup DMAMUX_Register_Masks_GROUP DMAMUX Register Masks */
/** @{ */

/** @name CHCFG - Channel Configuration Register */ /** @{ */
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)                                             /**< DMAMUX0_CHCFG.SOURCE Mask               */
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)                                                /**< DMAMUX0_CHCFG.SOURCE Position           */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK) /**< DMAMUX0_CHCFG.SOURCE Field              */
#define DMAMUX_CHCFG_TRIG_MASK                   (0x40U)                                             /**< DMAMUX0_CHCFG.TRIG Mask                 */
#define DMAMUX_CHCFG_TRIG_SHIFT                  (6U)                                                /**< DMAMUX0_CHCFG.TRIG Position             */
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_TRIG_SHIFT))&DMAMUX_CHCFG_TRIG_MASK) /**< DMAMUX0_CHCFG.TRIG Field                */
#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)                                             /**< DMAMUX0_CHCFG.ENBL Mask                 */
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)                                                /**< DMAMUX0_CHCFG.ENBL Position             */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_ENBL_SHIFT))&DMAMUX_CHCFG_ENBL_MASK) /**< DMAMUX0_CHCFG.ENBL Field                */
/** @} */

/** @} */ /* End group DMAMUX_Register_Masks_GROUP */


/* DMAMUX0 - Peripheral instance base addresses */
#define DMAMUX0_BasePtr                0x40021000UL //!< Peripheral base address
#define DMAMUX0                        ((DMAMUX_Type *) DMAMUX0_BasePtr) //!< Freescale base pointer
#define DMAMUX0_BASE_PTR               (DMAMUX0) //!< Freescale style base pointer

/**
 * DMA multiplexor slot (source) numbers
 */
typedef enum DmaSlot {
   Dma0Slot_Disabled                   =        0, //!<  Disabled
   Dma0Slot_UART0_Rx                   =        2, //!<  UART0 Receive
   Dma0Slot_UART0_Tx                   =        3, //!<  UART0 Transmit
   Dma0Slot_UART1_Rx                   =        4, //!<  UART1 Receive
   Dma0Slot_UART1_Tx                   =        5, //!<  UART1 Transmit
   Dma0Slot_UART2_Rx                   =        6, //!<  UART2 Receive
   Dma0Slot_UART2_Tx                   =        7, //!<  UART2 Transmit
   Dma0Slot_SPI0_Rx                    =       16, //!<  SPI0 Receive
   Dma0Slot_SPI0_Tx                    =       17, //!<  SPI0 Transmit
   Dma0Slot_SPI1_Rx                    =       18, //!<  SPI1 Receive
   Dma0Slot_SPI1_Tx                    =       19, //!<  SPI1 Transmit
   Dma0Slot_I2C0                       =       22, //!<  I2C0
   Dma0Slot_I2C1                       =       23, //!<  I2C1
   Dma0Slot_TPM0_Ch0                   =       24, //!<  TPM0 Channel 0
   Dma0Slot_TPM0_Ch1                   =       25, //!<  TPM0 Channel 1
   Dma0Slot_TPM0_Ch2                   =       26, //!<  TPM0 Channel 2
   Dma0Slot_TPM0_Ch3                   =       27, //!<  TPM0 Channel 3
   Dma0Slot_TPM0_Ch4                   =       28, //!<  TPM0 Channel 4
   Dma0Slot_TPM0_Ch5                   =       29, //!<  TPM0 Channel 5
   Dma0Slot_TPM1_Ch0                   =       32, //!<  TPM1 Channel 0
   Dma0Slot_TPM1_Ch1                   =       33, //!<  TPM1 Channel 1
   Dma0Slot_TPM2_Ch0                   =       34, //!<  TPM2 Channel 0
   Dma0Slot_TPM2_Ch1                   =       35, //!<  TPM2 Channel 1
   Dma0Slot_ADC0                       =       40, //!<  ADC0
   Dma0Slot_CMP0                       =       42, //!<  CMP0
   Dma0Slot_DAC0                       =       45, //!<  DAC0
   Dma0Slot_PortA                      =       49, //!<  Port A
   Dma0Slot_PortD                      =       52, //!<  Port D
   Dma0Slot_TPM0_Overflow              =       54, //!<  TPM0 Overflow
   Dma0Slot_TPM1_Overflow              =       55, //!<  TPM1 Overflow
   Dma0Slot_TPM2_Overflow              =       56, //!<  TPM2 Overflow
   Dma0Slot_TSI                        =       57, //!<  TSI
   Dma0Slot_AlwaysEnabled60            =       60, //!<  AlwaysEnabled60
   Dma0Slot_AlwaysEnabled61            =       61, //!<  AlwaysEnabled61
   Dma0Slot_AlwaysEnabled62            =       62, //!<  AlwaysEnabled62
   Dma0Slot_AlwaysEnabled63            =       63, //!<  AlwaysEnabled63
} DmaSlot;


/** @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FGPIOA (file:FGPIOA_0xF80FF000)       ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
 * @struct GPIO_Type
 * @brief  C Struct allowing access to FGPIO registers
 */
typedef struct GPIO_Type {
   __IO uint32_t  PDOR;                         /**< 0000: Port Data Output Register                                    */
   __O  uint32_t  PSOR;                         /**< 0004: Port Set Output Register                                     */
   __O  uint32_t  PCOR;                         /**< 0008: Port Clear Output Register                                   */
   __O  uint32_t  PTOR;                         /**< 000C: Port Toggle Output Register                                  */
   __I  uint32_t  PDIR;                         /**< 0010: Port Data Input Register                                     */
   __IO uint32_t  PDDR;                         /**< 0014: Port Data Direction Register                                 */
} GPIO_Type;


/** @brief Register Masks for FGPIO */

/* -------------------------------------------------------------------------------- */
/* -----------     'FGPIOA' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FGPIO_Register_Masks_GROUP FGPIO Register Masks */
/** @{ */

/** @} */ /* End group FGPIO_Register_Masks_GROUP */


/* FGPIOA - Peripheral instance base addresses */
#define FGPIOA_BasePtr                 0xF80FF000UL //!< Peripheral base address
#define FGPIOA                         ((GPIO_Type *) FGPIOA_BasePtr) //!< Freescale base pointer
#define FGPIOA_BASE_PTR                (FGPIOA) //!< Freescale style base pointer

/** @} */ /* End group FGPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FGPIOB (derived from FGPIOA)         ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* FGPIOB - Peripheral instance base addresses */
#define FGPIOB_BasePtr                 0xF80FF040UL //!< Peripheral base address
#define FGPIOB                         ((GPIO_Type *) FGPIOB_BasePtr) //!< Freescale base pointer
#define FGPIOB_BASE_PTR                (FGPIOB) //!< Freescale style base pointer

/** @} */ /* End group FGPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FGPIOC (derived from FGPIOA)         ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* FGPIOC - Peripheral instance base addresses */
#define FGPIOC_BasePtr                 0xF80FF080UL //!< Peripheral base address
#define FGPIOC                         ((GPIO_Type *) FGPIOC_BasePtr) //!< Freescale base pointer
#define FGPIOC_BASE_PTR                (FGPIOC) //!< Freescale style base pointer

/** @} */ /* End group FGPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FGPIOD (derived from FGPIOA)         ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* FGPIOD - Peripheral instance base addresses */
#define FGPIOD_BasePtr                 0xF80FF0C0UL //!< Peripheral base address
#define FGPIOD                         ((GPIO_Type *) FGPIOD_BasePtr) //!< Freescale base pointer
#define FGPIOD_BASE_PTR                (FGPIOD) //!< Freescale style base pointer

/** @} */ /* End group FGPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FGPIOE (derived from FGPIOA)         ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* FGPIOE - Peripheral instance base addresses */
#define FGPIOE_BasePtr                 0xF80FF100UL //!< Peripheral base address
#define FGPIOE                         ((GPIO_Type *) FGPIOE_BasePtr) //!< Freescale base pointer
#define FGPIOE_BASE_PTR                (FGPIOE) //!< Freescale style base pointer

/** @} */ /* End group FGPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for FTFA */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FTFA_Peripheral_access_layer_GROUP FTFA Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FTFA (file:FTFA)                     ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
 * @struct FTFA_Type
 * @brief  C Struct allowing access to FTFA registers
 */
typedef struct FTFA_Type {
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


/** @brief Register Masks for FTFA */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FTFA_Register_Masks_GROUP FTFA Register Masks */
/** @{ */

/** @name FSTAT - Flash Status Register */ /** @{ */
#define FTFA_FSTAT_MGSTAT0_MASK                  (0x1U)                                              /**< FTFA_FSTAT.MGSTAT0 Mask                 */
#define FTFA_FSTAT_MGSTAT0_SHIFT                 (0U)                                                /**< FTFA_FSTAT.MGSTAT0 Position             */
#define FTFA_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_MGSTAT0_SHIFT))&FTFA_FSTAT_MGSTAT0_MASK) /**< FTFA_FSTAT.MGSTAT0 Field                */
#define FTFA_FSTAT_FPVIOL_MASK                   (0x10U)                                             /**< FTFA_FSTAT.FPVIOL Mask                  */
#define FTFA_FSTAT_FPVIOL_SHIFT                  (4U)                                                /**< FTFA_FSTAT.FPVIOL Position              */
#define FTFA_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_FPVIOL_SHIFT))&FTFA_FSTAT_FPVIOL_MASK) /**< FTFA_FSTAT.FPVIOL Field                 */
#define FTFA_FSTAT_ACCERR_MASK                   (0x20U)                                             /**< FTFA_FSTAT.ACCERR Mask                  */
#define FTFA_FSTAT_ACCERR_SHIFT                  (5U)                                                /**< FTFA_FSTAT.ACCERR Position              */
#define FTFA_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_ACCERR_SHIFT))&FTFA_FSTAT_ACCERR_MASK) /**< FTFA_FSTAT.ACCERR Field                 */
#define FTFA_FSTAT_RDCOLERR_MASK                 (0x40U)                                             /**< FTFA_FSTAT.RDCOLERR Mask                */
#define FTFA_FSTAT_RDCOLERR_SHIFT                (6U)                                                /**< FTFA_FSTAT.RDCOLERR Position            */
#define FTFA_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_RDCOLERR_SHIFT))&FTFA_FSTAT_RDCOLERR_MASK) /**< FTFA_FSTAT.RDCOLERR Field               */
#define FTFA_FSTAT_CCIF_MASK                     (0x80U)                                             /**< FTFA_FSTAT.CCIF Mask                    */
#define FTFA_FSTAT_CCIF_SHIFT                    (7U)                                                /**< FTFA_FSTAT.CCIF Position                */
#define FTFA_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSTAT_CCIF_SHIFT))&FTFA_FSTAT_CCIF_MASK) /**< FTFA_FSTAT.CCIF Field                   */
/** @} */

/** @name FCNFG - Flash Configuration Register */ /** @{ */
#define FTFA_FCNFG_ERSSUSP_MASK                  (0x10U)                                             /**< FTFA_FCNFG.ERSSUSP Mask                 */
#define FTFA_FCNFG_ERSSUSP_SHIFT                 (4U)                                                /**< FTFA_FCNFG.ERSSUSP Position             */
#define FTFA_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_ERSSUSP_SHIFT))&FTFA_FCNFG_ERSSUSP_MASK) /**< FTFA_FCNFG.ERSSUSP Field                */
#define FTFA_FCNFG_ERSAREQ_MASK                  (0x20U)                                             /**< FTFA_FCNFG.ERSAREQ Mask                 */
#define FTFA_FCNFG_ERSAREQ_SHIFT                 (5U)                                                /**< FTFA_FCNFG.ERSAREQ Position             */
#define FTFA_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_ERSAREQ_SHIFT))&FTFA_FCNFG_ERSAREQ_MASK) /**< FTFA_FCNFG.ERSAREQ Field                */
#define FTFA_FCNFG_RDCOLLIE_MASK                 (0x40U)                                             /**< FTFA_FCNFG.RDCOLLIE Mask                */
#define FTFA_FCNFG_RDCOLLIE_SHIFT                (6U)                                                /**< FTFA_FCNFG.RDCOLLIE Position            */
#define FTFA_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_RDCOLLIE_SHIFT))&FTFA_FCNFG_RDCOLLIE_MASK) /**< FTFA_FCNFG.RDCOLLIE Field               */
#define FTFA_FCNFG_CCIE_MASK                     (0x80U)                                             /**< FTFA_FCNFG.CCIE Mask                    */
#define FTFA_FCNFG_CCIE_SHIFT                    (7U)                                                /**< FTFA_FCNFG.CCIE Position                */
#define FTFA_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FCNFG_CCIE_SHIFT))&FTFA_FCNFG_CCIE_MASK) /**< FTFA_FCNFG.CCIE Field                   */
/** @} */

/** @name FSEC - Flash Security Register */ /** @{ */
#define FTFA_FSEC_SEC_MASK                       (0x3U)                                              /**< FTFA_FSEC.SEC Mask                      */
#define FTFA_FSEC_SEC_SHIFT                      (0U)                                                /**< FTFA_FSEC.SEC Position                  */
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_SEC_SHIFT))&FTFA_FSEC_SEC_MASK) /**< FTFA_FSEC.SEC Field                     */
#define FTFA_FSEC_FSLACC_MASK                    (0xCU)                                              /**< FTFA_FSEC.FSLACC Mask                   */
#define FTFA_FSEC_FSLACC_SHIFT                   (2U)                                                /**< FTFA_FSEC.FSLACC Position               */
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_FSLACC_SHIFT))&FTFA_FSEC_FSLACC_MASK) /**< FTFA_FSEC.FSLACC Field                  */
#define FTFA_FSEC_MEEN_MASK                      (0x30U)                                             /**< FTFA_FSEC.MEEN Mask                     */
#define FTFA_FSEC_MEEN_SHIFT                     (4U)                                                /**< FTFA_FSEC.MEEN Position                 */
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_MEEN_SHIFT))&FTFA_FSEC_MEEN_MASK) /**< FTFA_FSEC.MEEN Field                    */
#define FTFA_FSEC_KEYEN_MASK                     (0xC0U)                                             /**< FTFA_FSEC.KEYEN Mask                    */
#define FTFA_FSEC_KEYEN_SHIFT                    (6U)                                                /**< FTFA_FSEC.KEYEN Position                */
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FSEC_KEYEN_SHIFT))&FTFA_FSEC_KEYEN_MASK) /**< FTFA_FSEC.KEYEN Field                   */
/** @} */

/** @name FOPT - Flash Option Register  */ /** @{ */
#define FTFA_FOPT_OPT_MASK                       (0xFFU)                                             /**< FTFA_FOPT.OPT Mask                      */
#define FTFA_FOPT_OPT_SHIFT                      (0U)                                                /**< FTFA_FOPT.OPT Position                  */
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFA_FOPT_OPT_SHIFT))&FTFA_FOPT_OPT_MASK) /**< FTFA_FOPT.OPT Field                     */
/** @} */

/** @name FCCOB - FCCOB %s - Usually %m  */ /** @{ */
#define FTFA_FCCOB_CCOBn_MASK                    (0xFFU)                                             /**< FTFA_FCCOB.CCOBn Mask                   */
#define FTFA_FCCOB_CCOBn_SHIFT                   (0U)                                                /**< FTFA_FCCOB.CCOBn Position               */
#define FTFA_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x))<<FTFA_FCCOB_CCOBn_SHIFT))&FTFA_FCCOB_CCOBn_MASK) /**< FTFA_FCCOB.CCOBn Field                  */
/** @} */

/** @name FPROT - Program Flash Protection  */ /** @{ */
#define FTFA_FPROT_PROT_MASK                     (0xFFU)                                             /**< FTFA_FPROT.PROT Mask                    */
#define FTFA_FPROT_PROT_SHIFT                    (0U)                                                /**< FTFA_FPROT.PROT Position                */
#define FTFA_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x))<<FTFA_FPROT_PROT_SHIFT))&FTFA_FPROT_PROT_MASK) /**< FTFA_FPROT.PROT Field                   */
/** @} */

/** @} */ /* End group FTFA_Register_Masks_GROUP */


/* FTFA - Peripheral instance base addresses */
#define FTFA_BasePtr                   0x40020000UL //!< Peripheral base address
#define FTFA                           ((FTFA_Type *) FTFA_BasePtr) //!< Freescale base pointer
#define FTFA_BASE_PTR                  (FTFA) //!< Freescale style base pointer
#define FTFA_IRQS { FTF_Command_IRQn,  }


/** @} */ /* End group FTFA_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOA (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x400FF000UL //!< Peripheral base address
#define GPIOA                          ((GPIO_Type *) GPIOA_BasePtr) //!< Freescale base pointer
#define GPIOA_BASE_PTR                 (GPIOA) //!< Freescale style base pointer

/** @} */ /* End group GPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOB (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x400FF040UL //!< Peripheral base address
#define GPIOB                          ((GPIO_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer

/** @} */ /* End group GPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOC (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x400FF080UL //!< Peripheral base address
#define GPIOC                          ((GPIO_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer

/** @} */ /* End group GPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOD (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0x400FF0C0UL //!< Peripheral base address
#define GPIOD                          ((GPIO_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer

/** @} */ /* End group GPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOE (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOE - Peripheral instance base addresses */
#define GPIOE_BasePtr                  0x400FF100UL //!< Peripheral base address
#define GPIOE                          ((GPIO_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer

/** @} */ /* End group GPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for I2C */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MKL04Z4)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */
/**
 * @struct I2C_Type
 * @brief  C Struct allowing access to I2C registers
 */
typedef struct I2C_Type {
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


/** @brief Register Masks for I2C */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup I2C_Register_Masks_GROUP I2C Register Masks */
/** @{ */

/** @name A1 - Address Register 1 */ /** @{ */
#define I2C_A1_AD_MASK                           (0xFEU)                                             /**< I2C0_A1.AD Mask                         */
#define I2C_A1_AD_SHIFT                          (1U)                                                /**< I2C0_A1.AD Position                     */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK) /**< I2C0_A1.AD Field                        */
/** @} */

/** @name F - Frequency Divider register */ /** @{ */
#define I2C_F_ICR_MASK                           (0x3FU)                                             /**< I2C0_F.ICR Mask                         */
#define I2C_F_ICR_SHIFT                          (0U)                                                /**< I2C0_F.ICR Position                     */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK) /**< I2C0_F.ICR Field                        */
#define I2C_F_MULT_MASK                          (0xC0U)                                             /**< I2C0_F.MULT Mask                        */
#define I2C_F_MULT_SHIFT                         (6U)                                                /**< I2C0_F.MULT Position                    */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK) /**< I2C0_F.MULT Field                       */
/** @} */

/** @name C1 - Control Register 1 */ /** @{ */
#define I2C_C1_DMAEN_MASK                        (0x1U)                                              /**< I2C0_C1.DMAEN Mask                      */
#define I2C_C1_DMAEN_SHIFT                       (0U)                                                /**< I2C0_C1.DMAEN Position                  */
#define I2C_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_DMAEN_SHIFT))&I2C_C1_DMAEN_MASK) /**< I2C0_C1.DMAEN Field                     */
#define I2C_C1_WUEN_MASK                         (0x2U)                                              /**< I2C0_C1.WUEN Mask                       */
#define I2C_C1_WUEN_SHIFT                        (1U)                                                /**< I2C0_C1.WUEN Position                   */
#define I2C_C1_WUEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_WUEN_SHIFT))&I2C_C1_WUEN_MASK) /**< I2C0_C1.WUEN Field                      */
#define I2C_C1_RSTA_MASK                         (0x4U)                                              /**< I2C0_C1.RSTA Mask                       */
#define I2C_C1_RSTA_SHIFT                        (2U)                                                /**< I2C0_C1.RSTA Position                   */
#define I2C_C1_RSTA(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_RSTA_SHIFT))&I2C_C1_RSTA_MASK) /**< I2C0_C1.RSTA Field                      */
#define I2C_C1_TXAK_MASK                         (0x8U)                                              /**< I2C0_C1.TXAK Mask                       */
#define I2C_C1_TXAK_SHIFT                        (3U)                                                /**< I2C0_C1.TXAK Position                   */
#define I2C_C1_TXAK(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_TXAK_SHIFT))&I2C_C1_TXAK_MASK) /**< I2C0_C1.TXAK Field                      */
#define I2C_C1_TX_MASK                           (0x10U)                                             /**< I2C0_C1.TX Mask                         */
#define I2C_C1_TX_SHIFT                          (4U)                                                /**< I2C0_C1.TX Position                     */
#define I2C_C1_TX(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C1_TX_SHIFT))&I2C_C1_TX_MASK) /**< I2C0_C1.TX Field                        */
#define I2C_C1_MST_MASK                          (0x20U)                                             /**< I2C0_C1.MST Mask                        */
#define I2C_C1_MST_SHIFT                         (5U)                                                /**< I2C0_C1.MST Position                    */
#define I2C_C1_MST(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_C1_MST_SHIFT))&I2C_C1_MST_MASK) /**< I2C0_C1.MST Field                       */
#define I2C_C1_IICIE_MASK                        (0x40U)                                             /**< I2C0_C1.IICIE Mask                      */
#define I2C_C1_IICIE_SHIFT                       (6U)                                                /**< I2C0_C1.IICIE Position                  */
#define I2C_C1_IICIE(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICIE_SHIFT))&I2C_C1_IICIE_MASK) /**< I2C0_C1.IICIE Field                     */
#define I2C_C1_IICEN_MASK                        (0x80U)                                             /**< I2C0_C1.IICEN Mask                      */
#define I2C_C1_IICEN_SHIFT                       (7U)                                                /**< I2C0_C1.IICEN Position                  */
#define I2C_C1_IICEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICEN_SHIFT))&I2C_C1_IICEN_MASK) /**< I2C0_C1.IICEN Field                     */
/** @} */

/** @name S - Status Register */ /** @{ */
#define I2C_S_RXAK_MASK                          (0x1U)                                              /**< I2C0_S.RXAK Mask                        */
#define I2C_S_RXAK_SHIFT                         (0U)                                                /**< I2C0_S.RXAK Position                    */
#define I2C_S_RXAK(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_RXAK_SHIFT))&I2C_S_RXAK_MASK) /**< I2C0_S.RXAK Field                       */
#define I2C_S_IICIF_MASK                         (0x2U)                                              /**< I2C0_S.IICIF Mask                       */
#define I2C_S_IICIF_SHIFT                        (1U)                                                /**< I2C0_S.IICIF Position                   */
#define I2C_S_IICIF(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_S_IICIF_SHIFT))&I2C_S_IICIF_MASK) /**< I2C0_S.IICIF Field                      */
#define I2C_S_SRW_MASK                           (0x4U)                                              /**< I2C0_S.SRW Mask                         */
#define I2C_S_SRW_SHIFT                          (2U)                                                /**< I2C0_S.SRW Position                     */
#define I2C_S_SRW(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_SRW_SHIFT))&I2C_S_SRW_MASK) /**< I2C0_S.SRW Field                        */
#define I2C_S_RAM_MASK                           (0x8U)                                              /**< I2C0_S.RAM Mask                         */
#define I2C_S_RAM_SHIFT                          (3U)                                                /**< I2C0_S.RAM Position                     */
#define I2C_S_RAM(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_RAM_SHIFT))&I2C_S_RAM_MASK) /**< I2C0_S.RAM Field                        */
#define I2C_S_ARBL_MASK                          (0x10U)                                             /**< I2C0_S.ARBL Mask                        */
#define I2C_S_ARBL_SHIFT                         (4U)                                                /**< I2C0_S.ARBL Position                    */
#define I2C_S_ARBL(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_ARBL_SHIFT))&I2C_S_ARBL_MASK) /**< I2C0_S.ARBL Field                       */
#define I2C_S_BUSY_MASK                          (0x20U)                                             /**< I2C0_S.BUSY Mask                        */
#define I2C_S_BUSY_SHIFT                         (5U)                                                /**< I2C0_S.BUSY Position                    */
#define I2C_S_BUSY(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_BUSY_SHIFT))&I2C_S_BUSY_MASK) /**< I2C0_S.BUSY Field                       */
#define I2C_S_IAAS_MASK                          (0x40U)                                             /**< I2C0_S.IAAS Mask                        */
#define I2C_S_IAAS_SHIFT                         (6U)                                                /**< I2C0_S.IAAS Position                    */
#define I2C_S_IAAS(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_IAAS_SHIFT))&I2C_S_IAAS_MASK) /**< I2C0_S.IAAS Field                       */
#define I2C_S_TCF_MASK                           (0x80U)                                             /**< I2C0_S.TCF Mask                         */
#define I2C_S_TCF_SHIFT                          (7U)                                                /**< I2C0_S.TCF Position                     */
#define I2C_S_TCF(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_TCF_SHIFT))&I2C_S_TCF_MASK) /**< I2C0_S.TCF Field                        */
/** @} */

/** @name D - Data I/O register */ /** @{ */
#define I2C_D_DATA_MASK                          (0xFFU)                                             /**< I2C0_D.DATA Mask                        */
#define I2C_D_DATA_SHIFT                         (0U)                                                /**< I2C0_D.DATA Position                    */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK) /**< I2C0_D.DATA Field                       */
/** @} */

/** @name C2 - Control Register 2 */ /** @{ */
#define I2C_C2_AD_MASK                           (0x7U)                                              /**< I2C0_C2.AD Mask                         */
#define I2C_C2_AD_SHIFT                          (0U)                                                /**< I2C0_C2.AD Position                     */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK) /**< I2C0_C2.AD Field                        */
#define I2C_C2_RMEN_MASK                         (0x8U)                                              /**< I2C0_C2.RMEN Mask                       */
#define I2C_C2_RMEN_SHIFT                        (3U)                                                /**< I2C0_C2.RMEN Position                   */
#define I2C_C2_RMEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_RMEN_SHIFT))&I2C_C2_RMEN_MASK) /**< I2C0_C2.RMEN Field                      */
#define I2C_C2_SBRC_MASK                         (0x10U)                                             /**< I2C0_C2.SBRC Mask                       */
#define I2C_C2_SBRC_SHIFT                        (4U)                                                /**< I2C0_C2.SBRC Position                   */
#define I2C_C2_SBRC(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_SBRC_SHIFT))&I2C_C2_SBRC_MASK) /**< I2C0_C2.SBRC Field                      */
#define I2C_C2_HDRS_MASK                         (0x20U)                                             /**< I2C0_C2.HDRS Mask                       */
#define I2C_C2_HDRS_SHIFT                        (5U)                                                /**< I2C0_C2.HDRS Position                   */
#define I2C_C2_HDRS(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_HDRS_SHIFT))&I2C_C2_HDRS_MASK) /**< I2C0_C2.HDRS Field                      */
#define I2C_C2_ADEXT_MASK                        (0x40U)                                             /**< I2C0_C2.ADEXT Mask                      */
#define I2C_C2_ADEXT_SHIFT                       (6U)                                                /**< I2C0_C2.ADEXT Position                  */
#define I2C_C2_ADEXT(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_ADEXT_SHIFT))&I2C_C2_ADEXT_MASK) /**< I2C0_C2.ADEXT Field                     */
#define I2C_C2_GCAEN_MASK                        (0x80U)                                             /**< I2C0_C2.GCAEN Mask                      */
#define I2C_C2_GCAEN_SHIFT                       (7U)                                                /**< I2C0_C2.GCAEN Position                  */
#define I2C_C2_GCAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_GCAEN_SHIFT))&I2C_C2_GCAEN_MASK) /**< I2C0_C2.GCAEN Field                     */
/** @} */

/** @name FLT - Programmable Input Glitch Filter register */ /** @{ */
#define I2C_FLT_FLT_MASK                         (0x1FU)                                             /**< I2C0_FLT.FLT Mask                       */
#define I2C_FLT_FLT_SHIFT                        (0U)                                                /**< I2C0_FLT.FLT Position                   */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK) /**< I2C0_FLT.FLT Field                      */
#define I2C_FLT_STOPIE_MASK                      (0x20U)                                             /**< I2C0_FLT.STOPIE Mask                    */
#define I2C_FLT_STOPIE_SHIFT                     (5U)                                                /**< I2C0_FLT.STOPIE Position                */
#define I2C_FLT_STOPIE(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_FLT_STOPIE_SHIFT))&I2C_FLT_STOPIE_MASK) /**< I2C0_FLT.STOPIE Field                   */
#define I2C_FLT_STOPF_MASK                       (0x40U)                                             /**< I2C0_FLT.STOPF Mask                     */
#define I2C_FLT_STOPF_SHIFT                      (6U)                                                /**< I2C0_FLT.STOPF Position                 */
#define I2C_FLT_STOPF(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_FLT_STOPF_SHIFT))&I2C_FLT_STOPF_MASK) /**< I2C0_FLT.STOPF Field                    */
#define I2C_FLT_SHEN_MASK                        (0x80U)                                             /**< I2C0_FLT.SHEN Mask                      */
#define I2C_FLT_SHEN_SHIFT                       (7U)                                                /**< I2C0_FLT.SHEN Position                  */
#define I2C_FLT_SHEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_FLT_SHEN_SHIFT))&I2C_FLT_SHEN_MASK) /**< I2C0_FLT.SHEN Field                     */
/** @} */

/** @name RA - Range Address register */ /** @{ */
#define I2C_RA_RAD_MASK                          (0xFEU)                                             /**< I2C0_RA.RAD Mask                        */
#define I2C_RA_RAD_SHIFT                         (1U)                                                /**< I2C0_RA.RAD Position                    */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK) /**< I2C0_RA.RAD Field                       */
/** @} */

/** @name SMB - SMBus Control and Status register */ /** @{ */
#define I2C_SMB_SHTF2IE_MASK                     (0x1U)                                              /**< I2C0_SMB.SHTF2IE Mask                   */
#define I2C_SMB_SHTF2IE_SHIFT                    (0U)                                                /**< I2C0_SMB.SHTF2IE Position               */
#define I2C_SMB_SHTF2IE(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2IE_SHIFT))&I2C_SMB_SHTF2IE_MASK) /**< I2C0_SMB.SHTF2IE Field                  */
#define I2C_SMB_SHTF2_MASK                       (0x2U)                                              /**< I2C0_SMB.SHTF2 Mask                     */
#define I2C_SMB_SHTF2_SHIFT                      (1U)                                                /**< I2C0_SMB.SHTF2 Position                 */
#define I2C_SMB_SHTF2(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2_SHIFT))&I2C_SMB_SHTF2_MASK) /**< I2C0_SMB.SHTF2 Field                    */
#define I2C_SMB_SHTF1_MASK                       (0x4U)                                              /**< I2C0_SMB.SHTF1 Mask                     */
#define I2C_SMB_SHTF1_SHIFT                      (2U)                                                /**< I2C0_SMB.SHTF1 Position                 */
#define I2C_SMB_SHTF1(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF1_SHIFT))&I2C_SMB_SHTF1_MASK) /**< I2C0_SMB.SHTF1 Field                    */
#define I2C_SMB_SLTF_MASK                        (0x8U)                                              /**< I2C0_SMB.SLTF Mask                      */
#define I2C_SMB_SLTF_SHIFT                       (3U)                                                /**< I2C0_SMB.SLTF Position                  */
#define I2C_SMB_SLTF(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SLTF_SHIFT))&I2C_SMB_SLTF_MASK) /**< I2C0_SMB.SLTF Field                     */
#define I2C_SMB_TCKSEL_MASK                      (0x10U)                                             /**< I2C0_SMB.TCKSEL Mask                    */
#define I2C_SMB_TCKSEL_SHIFT                     (4U)                                                /**< I2C0_SMB.TCKSEL Position                */
#define I2C_SMB_TCKSEL(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_SMB_TCKSEL_SHIFT))&I2C_SMB_TCKSEL_MASK) /**< I2C0_SMB.TCKSEL Field                   */
#define I2C_SMB_SIICAEN_MASK                     (0x20U)                                             /**< I2C0_SMB.SIICAEN Mask                   */
#define I2C_SMB_SIICAEN_SHIFT                    (5U)                                                /**< I2C0_SMB.SIICAEN Position               */
#define I2C_SMB_SIICAEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SIICAEN_SHIFT))&I2C_SMB_SIICAEN_MASK) /**< I2C0_SMB.SIICAEN Field                  */
#define I2C_SMB_ALERTEN_MASK                     (0x40U)                                             /**< I2C0_SMB.ALERTEN Mask                   */
#define I2C_SMB_ALERTEN_SHIFT                    (6U)                                                /**< I2C0_SMB.ALERTEN Position               */
#define I2C_SMB_ALERTEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_ALERTEN_SHIFT))&I2C_SMB_ALERTEN_MASK) /**< I2C0_SMB.ALERTEN Field                  */
#define I2C_SMB_FACK_MASK                        (0x80U)                                             /**< I2C0_SMB.FACK Mask                      */
#define I2C_SMB_FACK_SHIFT                       (7U)                                                /**< I2C0_SMB.FACK Position                  */
#define I2C_SMB_FACK(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_FACK_SHIFT))&I2C_SMB_FACK_MASK) /**< I2C0_SMB.FACK Field                     */
/** @} */

/** @name A2 - Address Register 2 */ /** @{ */
#define I2C_A2_SAD_MASK                          (0xFEU)                                             /**< I2C0_A2.SAD Mask                        */
#define I2C_A2_SAD_SHIFT                         (1U)                                                /**< I2C0_A2.SAD Position                    */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK) /**< I2C0_A2.SAD Field                       */
/** @} */

/** @name SLTH - SCL Low Timeout Register High */ /** @{ */
#define I2C_SLTH_SSLT_MASK                       (0xFFU)                                             /**< I2C0_SLTH.SSLT Mask                     */
#define I2C_SLTH_SSLT_SHIFT                      (0U)                                                /**< I2C0_SLTH.SSLT Position                 */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK) /**< I2C0_SLTH.SSLT Field                    */
/** @} */

/** @name SLTL - SCL Low Timeout Register Low */ /** @{ */
#define I2C_SLTL_SSLT_MASK                       (0xFFU)                                             /**< I2C0_SLTL.SSLT Mask                     */
#define I2C_SLTL_SSLT_SHIFT                      (0U)                                                /**< I2C0_SLTL.SSLT Position                 */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK) /**< I2C0_SLTL.SSLT Field                    */
/** @} */

/** @} */ /* End group I2C_Register_Masks_GROUP */


/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40066000UL //!< Peripheral base address
#define I2C0                           ((I2C_Type *) I2C0_BasePtr) //!< Freescale base pointer
#define I2C0_BASE_PTR                  (I2C0) //!< Freescale style base pointer
#define I2C0_IRQS { I2C0_IRQn,  }


/** @} */ /* End group I2C_Peripheral_access_layer_GROUP */


/** @brief C Struct for I2C */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer */
/** @{ */

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
#define I2C1_IRQS { I2C1_IRQn,  }


/** @} */ /* End group I2C_Peripheral_access_layer_GROUP */


/** @brief C Struct for LLWU */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup LLWU_Peripheral_access_layer_GROUP LLWU Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LLWU (file:LLWU_ME_PE4_FILT2_MKL25Z4)       ================ */
/* ================================================================================ */

/**
 * @brief Low leakage wakeup unit
 */
/**
 * @struct LLWU_Type
 * @brief  C Struct allowing access to LLWU registers
 */
typedef struct LLWU_Type {
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint8_t   PE[4];                     /**< 0000: Pin Enable  Register                                         */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint8_t   PE1;                    /**< 0000: Pin Enable 1 Register                                        */
         __IO uint8_t   PE2;                    /**< 0001: Pin Enable 2 Register                                        */
         __IO uint8_t   PE3;                    /**< 0002: Pin Enable 3 Register                                        */
         __IO uint8_t   PE4;                    /**< 0003: Pin Enable 4 Register                                        */
      };
   };
   __IO uint8_t   ME;                           /**< 0004: Module Enable Register                                       */
   union {                                      /**< 0005: (size=0002)                                                  */
      __IO uint8_t   PF[2];                     /**< 0005: Pin Flag  Register                                           */
      struct {                                  /**< 0005: (size=0002)                                                  */
         __IO uint8_t   PF1;                    /**< 0005: Pin Flag 1 Register                                          */
         __IO uint8_t   F2;                     /**< 0006: Pin Flag 2 Register                                          */
      };
   };
   __I  uint8_t   MF;                           /**< 0007: Module Flag Register                                         */
   union {                                      /**< 0008: (size=0002)                                                  */
      __IO uint8_t   FILT[2];                   /**< 0008: Pin Filter register                                          */
      struct {                                  /**< 0008: (size=0002)                                                  */
         __IO uint8_t   FILT1;                  /**< 0008: Pin Filter register                                          */
         __IO uint8_t   FILT2;                  /**< 0009: Pin Filter register                                          */
      };
   };
} LLWU_Type;


/** @brief Register Masks for LLWU */

/* -------------------------------------------------------------------------------- */
/* -----------     'LLWU' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup LLWU_Register_Masks_GROUP LLWU Register Masks */
/** @{ */

/** @name PE - Pin Enable %s Register */ /** @{ */
#define LLWU_PE_WUPE0_MASK                       (0x3U)                                              /**< LLWU_PE.WUPE0 Mask                      */
#define LLWU_PE_WUPE0_SHIFT                      (0U)                                                /**< LLWU_PE.WUPE0 Position                  */
#define LLWU_PE_WUPE0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PE_WUPE0_SHIFT))&LLWU_PE_WUPE0_MASK) /**< LLWU_PE.WUPE0 Field                     */
#define LLWU_PE_WUPE1_MASK                       (0xCU)                                              /**< LLWU_PE.WUPE1 Mask                      */
#define LLWU_PE_WUPE1_SHIFT                      (2U)                                                /**< LLWU_PE.WUPE1 Position                  */
#define LLWU_PE_WUPE1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PE_WUPE1_SHIFT))&LLWU_PE_WUPE1_MASK) /**< LLWU_PE.WUPE1 Field                     */
#define LLWU_PE_WUPE2_MASK                       (0x30U)                                             /**< LLWU_PE.WUPE2 Mask                      */
#define LLWU_PE_WUPE2_SHIFT                      (4U)                                                /**< LLWU_PE.WUPE2 Position                  */
#define LLWU_PE_WUPE2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PE_WUPE2_SHIFT))&LLWU_PE_WUPE2_MASK) /**< LLWU_PE.WUPE2 Field                     */
#define LLWU_PE_WUPE3_MASK                       (0xC0U)                                             /**< LLWU_PE.WUPE3 Mask                      */
#define LLWU_PE_WUPE3_SHIFT                      (6U)                                                /**< LLWU_PE.WUPE3 Position                  */
#define LLWU_PE_WUPE3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PE_WUPE3_SHIFT))&LLWU_PE_WUPE3_MASK) /**< LLWU_PE.WUPE3 Field                     */
/** @} */

/** @name PE1 - Pin Enable 1 Register */ /** @{ */
#define LLWU_PE1_WUPE0_MASK                      (0x3U)                                              /**< LLWU_PE1.WUPE0 Mask                     */
#define LLWU_PE1_WUPE0_SHIFT                     (0U)                                                /**< LLWU_PE1.WUPE0 Position                 */
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK) /**< LLWU_PE1.WUPE0 Field                    */
#define LLWU_PE1_WUPE1_MASK                      (0xCU)                                              /**< LLWU_PE1.WUPE1 Mask                     */
#define LLWU_PE1_WUPE1_SHIFT                     (2U)                                                /**< LLWU_PE1.WUPE1 Position                 */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK) /**< LLWU_PE1.WUPE1 Field                    */
#define LLWU_PE1_WUPE2_MASK                      (0x30U)                                             /**< LLWU_PE1.WUPE2 Mask                     */
#define LLWU_PE1_WUPE2_SHIFT                     (4U)                                                /**< LLWU_PE1.WUPE2 Position                 */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK) /**< LLWU_PE1.WUPE2 Field                    */
#define LLWU_PE1_WUPE3_MASK                      (0xC0U)                                             /**< LLWU_PE1.WUPE3 Mask                     */
#define LLWU_PE1_WUPE3_SHIFT                     (6U)                                                /**< LLWU_PE1.WUPE3 Position                 */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK) /**< LLWU_PE1.WUPE3 Field                    */
/** @} */

/** @name PE2 - Pin Enable 2 Register */ /** @{ */
#define LLWU_PE2_WUPE4_MASK                      (0x3U)                                              /**< LLWU_PE2.WUPE4 Mask                     */
#define LLWU_PE2_WUPE4_SHIFT                     (0U)                                                /**< LLWU_PE2.WUPE4 Position                 */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK) /**< LLWU_PE2.WUPE4 Field                    */
#define LLWU_PE2_WUPE5_MASK                      (0xCU)                                              /**< LLWU_PE2.WUPE5 Mask                     */
#define LLWU_PE2_WUPE5_SHIFT                     (2U)                                                /**< LLWU_PE2.WUPE5 Position                 */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK) /**< LLWU_PE2.WUPE5 Field                    */
#define LLWU_PE2_WUPE6_MASK                      (0x30U)                                             /**< LLWU_PE2.WUPE6 Mask                     */
#define LLWU_PE2_WUPE6_SHIFT                     (4U)                                                /**< LLWU_PE2.WUPE6 Position                 */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK) /**< LLWU_PE2.WUPE6 Field                    */
#define LLWU_PE2_WUPE7_MASK                      (0xC0U)                                             /**< LLWU_PE2.WUPE7 Mask                     */
#define LLWU_PE2_WUPE7_SHIFT                     (6U)                                                /**< LLWU_PE2.WUPE7 Position                 */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK) /**< LLWU_PE2.WUPE7 Field                    */
/** @} */

/** @name PE3 - Pin Enable 3 Register */ /** @{ */
#define LLWU_PE3_WUPE8_MASK                      (0x3U)                                              /**< LLWU_PE3.WUPE8 Mask                     */
#define LLWU_PE3_WUPE8_SHIFT                     (0U)                                                /**< LLWU_PE3.WUPE8 Position                 */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK) /**< LLWU_PE3.WUPE8 Field                    */
#define LLWU_PE3_WUPE9_MASK                      (0xCU)                                              /**< LLWU_PE3.WUPE9 Mask                     */
#define LLWU_PE3_WUPE9_SHIFT                     (2U)                                                /**< LLWU_PE3.WUPE9 Position                 */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK) /**< LLWU_PE3.WUPE9 Field                    */
#define LLWU_PE3_WUPE10_MASK                     (0x30U)                                             /**< LLWU_PE3.WUPE10 Mask                    */
#define LLWU_PE3_WUPE10_SHIFT                    (4U)                                                /**< LLWU_PE3.WUPE10 Position                */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK) /**< LLWU_PE3.WUPE10 Field                   */
#define LLWU_PE3_WUPE11_MASK                     (0xC0U)                                             /**< LLWU_PE3.WUPE11 Mask                    */
#define LLWU_PE3_WUPE11_SHIFT                    (6U)                                                /**< LLWU_PE3.WUPE11 Position                */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK) /**< LLWU_PE3.WUPE11 Field                   */
/** @} */

/** @name PE4 - Pin Enable 4 Register */ /** @{ */
#define LLWU_PE4_WUPE12_MASK                     (0x3U)                                              /**< LLWU_PE4.WUPE12 Mask                    */
#define LLWU_PE4_WUPE12_SHIFT                    (0U)                                                /**< LLWU_PE4.WUPE12 Position                */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK) /**< LLWU_PE4.WUPE12 Field                   */
#define LLWU_PE4_WUPE13_MASK                     (0xCU)                                              /**< LLWU_PE4.WUPE13 Mask                    */
#define LLWU_PE4_WUPE13_SHIFT                    (2U)                                                /**< LLWU_PE4.WUPE13 Position                */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK) /**< LLWU_PE4.WUPE13 Field                   */
#define LLWU_PE4_WUPE14_MASK                     (0x30U)                                             /**< LLWU_PE4.WUPE14 Mask                    */
#define LLWU_PE4_WUPE14_SHIFT                    (4U)                                                /**< LLWU_PE4.WUPE14 Position                */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK) /**< LLWU_PE4.WUPE14 Field                   */
#define LLWU_PE4_WUPE15_MASK                     (0xC0U)                                             /**< LLWU_PE4.WUPE15 Mask                    */
#define LLWU_PE4_WUPE15_SHIFT                    (6U)                                                /**< LLWU_PE4.WUPE15 Position                */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK) /**< LLWU_PE4.WUPE15 Field                   */
/** @} */

/** @name ME - Module Enable Register */ /** @{ */
#define LLWU_ME_WUME0_MASK                       (0x1U)                                              /**< LLWU_ME.WUME0 Mask                      */
#define LLWU_ME_WUME0_SHIFT                      (0U)                                                /**< LLWU_ME.WUME0 Position                  */
#define LLWU_ME_WUME0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME0_SHIFT))&LLWU_ME_WUME0_MASK) /**< LLWU_ME.WUME0 Field                     */
#define LLWU_ME_WUME1_MASK                       (0x2U)                                              /**< LLWU_ME.WUME1 Mask                      */
#define LLWU_ME_WUME1_SHIFT                      (1U)                                                /**< LLWU_ME.WUME1 Position                  */
#define LLWU_ME_WUME1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME1_SHIFT))&LLWU_ME_WUME1_MASK) /**< LLWU_ME.WUME1 Field                     */
#define LLWU_ME_WUME2_MASK                       (0x4U)                                              /**< LLWU_ME.WUME2 Mask                      */
#define LLWU_ME_WUME2_SHIFT                      (2U)                                                /**< LLWU_ME.WUME2 Position                  */
#define LLWU_ME_WUME2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME2_SHIFT))&LLWU_ME_WUME2_MASK) /**< LLWU_ME.WUME2 Field                     */
#define LLWU_ME_WUME3_MASK                       (0x8U)                                              /**< LLWU_ME.WUME3 Mask                      */
#define LLWU_ME_WUME3_SHIFT                      (3U)                                                /**< LLWU_ME.WUME3 Position                  */
#define LLWU_ME_WUME3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME3_SHIFT))&LLWU_ME_WUME3_MASK) /**< LLWU_ME.WUME3 Field                     */
#define LLWU_ME_WUME4_MASK                       (0x10U)                                             /**< LLWU_ME.WUME4 Mask                      */
#define LLWU_ME_WUME4_SHIFT                      (4U)                                                /**< LLWU_ME.WUME4 Position                  */
#define LLWU_ME_WUME4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME4_SHIFT))&LLWU_ME_WUME4_MASK) /**< LLWU_ME.WUME4 Field                     */
#define LLWU_ME_WUME5_MASK                       (0x20U)                                             /**< LLWU_ME.WUME5 Mask                      */
#define LLWU_ME_WUME5_SHIFT                      (5U)                                                /**< LLWU_ME.WUME5 Position                  */
#define LLWU_ME_WUME5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME5_SHIFT))&LLWU_ME_WUME5_MASK) /**< LLWU_ME.WUME5 Field                     */
#define LLWU_ME_WUME6_MASK                       (0x40U)                                             /**< LLWU_ME.WUME6 Mask                      */
#define LLWU_ME_WUME6_SHIFT                      (6U)                                                /**< LLWU_ME.WUME6 Position                  */
#define LLWU_ME_WUME6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME6_SHIFT))&LLWU_ME_WUME6_MASK) /**< LLWU_ME.WUME6 Field                     */
#define LLWU_ME_WUME7_MASK                       (0x80U)                                             /**< LLWU_ME.WUME7 Mask                      */
#define LLWU_ME_WUME7_SHIFT                      (7U)                                                /**< LLWU_ME.WUME7 Position                  */
#define LLWU_ME_WUME7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME7_SHIFT))&LLWU_ME_WUME7_MASK) /**< LLWU_ME.WUME7 Field                     */
/** @} */

/** @name PF - Pin Flag %s Register */ /** @{ */
#define LLWU_PF_WUF0_MASK                        (0x1U)                                              /**< LLWU_PF.WUF0 Mask                       */
#define LLWU_PF_WUF0_SHIFT                       (0U)                                                /**< LLWU_PF.WUF0 Position                   */
#define LLWU_PF_WUF0(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_PF_WUF0_SHIFT))&LLWU_PF_WUF0_MASK) /**< LLWU_PF.WUF0 Field                      */
#define LLWU_PF_WUF1_MASK                        (0x2U)                                              /**< LLWU_PF.WUF1 Mask                       */
#define LLWU_PF_WUF1_SHIFT                       (1U)                                                /**< LLWU_PF.WUF1 Position                   */
#define LLWU_PF_WUF1(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_PF_WUF1_SHIFT))&LLWU_PF_WUF1_MASK) /**< LLWU_PF.WUF1 Field                      */
#define LLWU_PF_WUF2_MASK                        (0x4U)                                              /**< LLWU_PF.WUF2 Mask                       */
#define LLWU_PF_WUF2_SHIFT                       (2U)                                                /**< LLWU_PF.WUF2 Position                   */
#define LLWU_PF_WUF2(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_PF_WUF2_SHIFT))&LLWU_PF_WUF2_MASK) /**< LLWU_PF.WUF2 Field                      */
#define LLWU_PF_WUF3_MASK                        (0x8U)                                              /**< LLWU_PF.WUF3 Mask                       */
#define LLWU_PF_WUF3_SHIFT                       (3U)                                                /**< LLWU_PF.WUF3 Position                   */
#define LLWU_PF_WUF3(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_PF_WUF3_SHIFT))&LLWU_PF_WUF3_MASK) /**< LLWU_PF.WUF3 Field                      */
#define LLWU_PF_WUF4_MASK                        (0x10U)                                             /**< LLWU_PF.WUF4 Mask                       */
#define LLWU_PF_WUF4_SHIFT                       (4U)                                                /**< LLWU_PF.WUF4 Position                   */
#define LLWU_PF_WUF4(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_PF_WUF4_SHIFT))&LLWU_PF_WUF4_MASK) /**< LLWU_PF.WUF4 Field                      */
#define LLWU_PF_WUF5_MASK                        (0x20U)                                             /**< LLWU_PF.WUF5 Mask                       */
#define LLWU_PF_WUF5_SHIFT                       (5U)                                                /**< LLWU_PF.WUF5 Position                   */
#define LLWU_PF_WUF5(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_PF_WUF5_SHIFT))&LLWU_PF_WUF5_MASK) /**< LLWU_PF.WUF5 Field                      */
#define LLWU_PF_WUF6_MASK                        (0x40U)                                             /**< LLWU_PF.WUF6 Mask                       */
#define LLWU_PF_WUF6_SHIFT                       (6U)                                                /**< LLWU_PF.WUF6 Position                   */
#define LLWU_PF_WUF6(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_PF_WUF6_SHIFT))&LLWU_PF_WUF6_MASK) /**< LLWU_PF.WUF6 Field                      */
#define LLWU_PF_WUF7_MASK                        (0x80U)                                             /**< LLWU_PF.WUF7 Mask                       */
#define LLWU_PF_WUF7_SHIFT                       (7U)                                                /**< LLWU_PF.WUF7 Position                   */
#define LLWU_PF_WUF7(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_PF_WUF7_SHIFT))&LLWU_PF_WUF7_MASK) /**< LLWU_PF.WUF7 Field                      */
/** @} */

/** @name PF1 - Pin Flag 1 Register */ /** @{ */
#define LLWU_PF1_WUF0_MASK                       (0x1U)                                              /**< LLWU_PF1.WUF0 Mask                      */
#define LLWU_PF1_WUF0_SHIFT                      (0U)                                                /**< LLWU_PF1.WUF0 Position                  */
#define LLWU_PF1_WUF0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PF1_WUF0_SHIFT))&LLWU_PF1_WUF0_MASK) /**< LLWU_PF1.WUF0 Field                     */
#define LLWU_PF1_WUF1_MASK                       (0x2U)                                              /**< LLWU_PF1.WUF1 Mask                      */
#define LLWU_PF1_WUF1_SHIFT                      (1U)                                                /**< LLWU_PF1.WUF1 Position                  */
#define LLWU_PF1_WUF1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PF1_WUF1_SHIFT))&LLWU_PF1_WUF1_MASK) /**< LLWU_PF1.WUF1 Field                     */
#define LLWU_PF1_WUF2_MASK                       (0x4U)                                              /**< LLWU_PF1.WUF2 Mask                      */
#define LLWU_PF1_WUF2_SHIFT                      (2U)                                                /**< LLWU_PF1.WUF2 Position                  */
#define LLWU_PF1_WUF2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PF1_WUF2_SHIFT))&LLWU_PF1_WUF2_MASK) /**< LLWU_PF1.WUF2 Field                     */
#define LLWU_PF1_WUF3_MASK                       (0x8U)                                              /**< LLWU_PF1.WUF3 Mask                      */
#define LLWU_PF1_WUF3_SHIFT                      (3U)                                                /**< LLWU_PF1.WUF3 Position                  */
#define LLWU_PF1_WUF3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PF1_WUF3_SHIFT))&LLWU_PF1_WUF3_MASK) /**< LLWU_PF1.WUF3 Field                     */
#define LLWU_PF1_WUF4_MASK                       (0x10U)                                             /**< LLWU_PF1.WUF4 Mask                      */
#define LLWU_PF1_WUF4_SHIFT                      (4U)                                                /**< LLWU_PF1.WUF4 Position                  */
#define LLWU_PF1_WUF4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PF1_WUF4_SHIFT))&LLWU_PF1_WUF4_MASK) /**< LLWU_PF1.WUF4 Field                     */
#define LLWU_PF1_WUF5_MASK                       (0x20U)                                             /**< LLWU_PF1.WUF5 Mask                      */
#define LLWU_PF1_WUF5_SHIFT                      (5U)                                                /**< LLWU_PF1.WUF5 Position                  */
#define LLWU_PF1_WUF5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PF1_WUF5_SHIFT))&LLWU_PF1_WUF5_MASK) /**< LLWU_PF1.WUF5 Field                     */
#define LLWU_PF1_WUF6_MASK                       (0x40U)                                             /**< LLWU_PF1.WUF6 Mask                      */
#define LLWU_PF1_WUF6_SHIFT                      (6U)                                                /**< LLWU_PF1.WUF6 Position                  */
#define LLWU_PF1_WUF6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PF1_WUF6_SHIFT))&LLWU_PF1_WUF6_MASK) /**< LLWU_PF1.WUF6 Field                     */
#define LLWU_PF1_WUF7_MASK                       (0x80U)                                             /**< LLWU_PF1.WUF7 Mask                      */
#define LLWU_PF1_WUF7_SHIFT                      (7U)                                                /**< LLWU_PF1.WUF7 Position                  */
#define LLWU_PF1_WUF7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_PF1_WUF7_SHIFT))&LLWU_PF1_WUF7_MASK) /**< LLWU_PF1.WUF7 Field                     */
/** @} */

/** @name F2 - Pin Flag 2 Register */ /** @{ */
#define LLWU_F2_WUF8_MASK                        (0x1U)                                              /**< LLWU_F2.WUF8 Mask                       */
#define LLWU_F2_WUF8_SHIFT                       (0U)                                                /**< LLWU_F2.WUF8 Position                   */
#define LLWU_F2_WUF8(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF8_SHIFT))&LLWU_F2_WUF8_MASK) /**< LLWU_F2.WUF8 Field                      */
#define LLWU_F2_WUF9_MASK                        (0x2U)                                              /**< LLWU_F2.WUF9 Mask                       */
#define LLWU_F2_WUF9_SHIFT                       (1U)                                                /**< LLWU_F2.WUF9 Position                   */
#define LLWU_F2_WUF9(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF9_SHIFT))&LLWU_F2_WUF9_MASK) /**< LLWU_F2.WUF9 Field                      */
#define LLWU_F2_WUF10_MASK                       (0x4U)                                              /**< LLWU_F2.WUF10 Mask                      */
#define LLWU_F2_WUF10_SHIFT                      (2U)                                                /**< LLWU_F2.WUF10 Position                  */
#define LLWU_F2_WUF10(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF10_SHIFT))&LLWU_F2_WUF10_MASK) /**< LLWU_F2.WUF10 Field                     */
#define LLWU_F2_WUF11_MASK                       (0x8U)                                              /**< LLWU_F2.WUF11 Mask                      */
#define LLWU_F2_WUF11_SHIFT                      (3U)                                                /**< LLWU_F2.WUF11 Position                  */
#define LLWU_F2_WUF11(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF11_SHIFT))&LLWU_F2_WUF11_MASK) /**< LLWU_F2.WUF11 Field                     */
#define LLWU_F2_WUF12_MASK                       (0x10U)                                             /**< LLWU_F2.WUF12 Mask                      */
#define LLWU_F2_WUF12_SHIFT                      (4U)                                                /**< LLWU_F2.WUF12 Position                  */
#define LLWU_F2_WUF12(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF12_SHIFT))&LLWU_F2_WUF12_MASK) /**< LLWU_F2.WUF12 Field                     */
#define LLWU_F2_WUF13_MASK                       (0x20U)                                             /**< LLWU_F2.WUF13 Mask                      */
#define LLWU_F2_WUF13_SHIFT                      (5U)                                                /**< LLWU_F2.WUF13 Position                  */
#define LLWU_F2_WUF13(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF13_SHIFT))&LLWU_F2_WUF13_MASK) /**< LLWU_F2.WUF13 Field                     */
#define LLWU_F2_WUF14_MASK                       (0x40U)                                             /**< LLWU_F2.WUF14 Mask                      */
#define LLWU_F2_WUF14_SHIFT                      (6U)                                                /**< LLWU_F2.WUF14 Position                  */
#define LLWU_F2_WUF14(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF14_SHIFT))&LLWU_F2_WUF14_MASK) /**< LLWU_F2.WUF14 Field                     */
#define LLWU_F2_WUF15_MASK                       (0x80U)                                             /**< LLWU_F2.WUF15 Mask                      */
#define LLWU_F2_WUF15_SHIFT                      (7U)                                                /**< LLWU_F2.WUF15 Position                  */
#define LLWU_F2_WUF15(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF15_SHIFT))&LLWU_F2_WUF15_MASK) /**< LLWU_F2.WUF15 Field                     */
/** @} */

/** @name MF - Module Flag Register */ /** @{ */
#define LLWU_MF_MWUF0_MASK                       (0x1U)                                              /**< LLWU_MF.MWUF0 Mask                      */
#define LLWU_MF_MWUF0_SHIFT                      (0U)                                                /**< LLWU_MF.MWUF0 Position                  */
#define LLWU_MF_MWUF0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_MF_MWUF0_SHIFT))&LLWU_MF_MWUF0_MASK) /**< LLWU_MF.MWUF0 Field                     */
#define LLWU_MF_MWUF1_MASK                       (0x2U)                                              /**< LLWU_MF.MWUF1 Mask                      */
#define LLWU_MF_MWUF1_SHIFT                      (1U)                                                /**< LLWU_MF.MWUF1 Position                  */
#define LLWU_MF_MWUF1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_MF_MWUF1_SHIFT))&LLWU_MF_MWUF1_MASK) /**< LLWU_MF.MWUF1 Field                     */
#define LLWU_MF_MWUF2_MASK                       (0x4U)                                              /**< LLWU_MF.MWUF2 Mask                      */
#define LLWU_MF_MWUF2_SHIFT                      (2U)                                                /**< LLWU_MF.MWUF2 Position                  */
#define LLWU_MF_MWUF2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_MF_MWUF2_SHIFT))&LLWU_MF_MWUF2_MASK) /**< LLWU_MF.MWUF2 Field                     */
#define LLWU_MF_MWUF3_MASK                       (0x8U)                                              /**< LLWU_MF.MWUF3 Mask                      */
#define LLWU_MF_MWUF3_SHIFT                      (3U)                                                /**< LLWU_MF.MWUF3 Position                  */
#define LLWU_MF_MWUF3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_MF_MWUF3_SHIFT))&LLWU_MF_MWUF3_MASK) /**< LLWU_MF.MWUF3 Field                     */
#define LLWU_MF_MWUF4_MASK                       (0x10U)                                             /**< LLWU_MF.MWUF4 Mask                      */
#define LLWU_MF_MWUF4_SHIFT                      (4U)                                                /**< LLWU_MF.MWUF4 Position                  */
#define LLWU_MF_MWUF4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_MF_MWUF4_SHIFT))&LLWU_MF_MWUF4_MASK) /**< LLWU_MF.MWUF4 Field                     */
#define LLWU_MF_MWUF5_MASK                       (0x20U)                                             /**< LLWU_MF.MWUF5 Mask                      */
#define LLWU_MF_MWUF5_SHIFT                      (5U)                                                /**< LLWU_MF.MWUF5 Position                  */
#define LLWU_MF_MWUF5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_MF_MWUF5_SHIFT))&LLWU_MF_MWUF5_MASK) /**< LLWU_MF.MWUF5 Field                     */
#define LLWU_MF_MWUF6_MASK                       (0x40U)                                             /**< LLWU_MF.MWUF6 Mask                      */
#define LLWU_MF_MWUF6_SHIFT                      (6U)                                                /**< LLWU_MF.MWUF6 Position                  */
#define LLWU_MF_MWUF6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_MF_MWUF6_SHIFT))&LLWU_MF_MWUF6_MASK) /**< LLWU_MF.MWUF6 Field                     */
#define LLWU_MF_MWUF7_MASK                       (0x80U)                                             /**< LLWU_MF.MWUF7 Mask                      */
#define LLWU_MF_MWUF7_SHIFT                      (7U)                                                /**< LLWU_MF.MWUF7 Position                  */
#define LLWU_MF_MWUF7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_MF_MWUF7_SHIFT))&LLWU_MF_MWUF7_MASK) /**< LLWU_MF.MWUF7 Field                     */
/** @} */

/** @name FILT - Pin Filter register */ /** @{ */
#define LLWU_FILT_FILTSEL_MASK                   (0xFU)                                              /**< LLWU_FILT.FILTSEL Mask                  */
#define LLWU_FILT_FILTSEL_SHIFT                  (0U)                                                /**< LLWU_FILT.FILTSEL Position              */
#define LLWU_FILT_FILTSEL(x)                     (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTSEL_SHIFT))&LLWU_FILT_FILTSEL_MASK) /**< LLWU_FILT.FILTSEL Field                 */
#define LLWU_FILT_FILTE_MASK                     (0x60U)                                             /**< LLWU_FILT.FILTE Mask                    */
#define LLWU_FILT_FILTE_SHIFT                    (5U)                                                /**< LLWU_FILT.FILTE Position                */
#define LLWU_FILT_FILTE(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTE_SHIFT))&LLWU_FILT_FILTE_MASK) /**< LLWU_FILT.FILTE Field                   */
#define LLWU_FILT_FILTF_MASK                     (0x80U)                                             /**< LLWU_FILT.FILTF Mask                    */
#define LLWU_FILT_FILTF_SHIFT                    (7U)                                                /**< LLWU_FILT.FILTF Position                */
#define LLWU_FILT_FILTF(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTF_SHIFT))&LLWU_FILT_FILTF_MASK) /**< LLWU_FILT.FILTF Field                   */
/** @} */

/** @name FILT1 - Pin Filter register */ /** @{ */
#define LLWU_FILT1_FILTSEL_MASK                  (0xFU)                                              /**< LLWU_FILT1.FILTSEL Mask                 */
#define LLWU_FILT1_FILTSEL_SHIFT                 (0U)                                                /**< LLWU_FILT1.FILTSEL Position             */
#define LLWU_FILT1_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTSEL_SHIFT))&LLWU_FILT1_FILTSEL_MASK) /**< LLWU_FILT1.FILTSEL Field                */
#define LLWU_FILT1_FILTE_MASK                    (0x60U)                                             /**< LLWU_FILT1.FILTE Mask                   */
#define LLWU_FILT1_FILTE_SHIFT                   (5U)                                                /**< LLWU_FILT1.FILTE Position               */
#define LLWU_FILT1_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTE_SHIFT))&LLWU_FILT1_FILTE_MASK) /**< LLWU_FILT1.FILTE Field                  */
#define LLWU_FILT1_FILTF_MASK                    (0x80U)                                             /**< LLWU_FILT1.FILTF Mask                   */
#define LLWU_FILT1_FILTF_SHIFT                   (7U)                                                /**< LLWU_FILT1.FILTF Position               */
#define LLWU_FILT1_FILTF(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT1_FILTF_SHIFT))&LLWU_FILT1_FILTF_MASK) /**< LLWU_FILT1.FILTF Field                  */
/** @} */

/** @name FILT2 - Pin Filter register */ /** @{ */
#define LLWU_FILT2_FILTSEL_MASK                  (0xFU)                                              /**< LLWU_FILT2.FILTSEL Mask                 */
#define LLWU_FILT2_FILTSEL_SHIFT                 (0U)                                                /**< LLWU_FILT2.FILTSEL Position             */
#define LLWU_FILT2_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTSEL_SHIFT))&LLWU_FILT2_FILTSEL_MASK) /**< LLWU_FILT2.FILTSEL Field                */
#define LLWU_FILT2_FILTE_MASK                    (0x60U)                                             /**< LLWU_FILT2.FILTE Mask                   */
#define LLWU_FILT2_FILTE_SHIFT                   (5U)                                                /**< LLWU_FILT2.FILTE Position               */
#define LLWU_FILT2_FILTE(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTE_SHIFT))&LLWU_FILT2_FILTE_MASK) /**< LLWU_FILT2.FILTE Field                  */
#define LLWU_FILT2_FILTF_MASK                    (0x80U)                                             /**< LLWU_FILT2.FILTF Mask                   */
#define LLWU_FILT2_FILTF_SHIFT                   (7U)                                                /**< LLWU_FILT2.FILTF Position               */
#define LLWU_FILT2_FILTF(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_FILT2_FILTF_SHIFT))&LLWU_FILT2_FILTF_MASK) /**< LLWU_FILT2.FILTF Field                  */
/** @} */

/** @} */ /* End group LLWU_Register_Masks_GROUP */


/* LLWU - Peripheral instance base addresses */
#define LLWU_BasePtr                   0x4007C000UL //!< Peripheral base address
#define LLWU                           ((LLWU_Type *) LLWU_BasePtr) //!< Freescale base pointer
#define LLWU_BASE_PTR                  (LLWU) //!< Freescale style base pointer
#define LLWU_IRQS { LLWU_IRQn,  }


/** @} */ /* End group LLWU_Peripheral_access_layer_GROUP */


/** @brief C Struct for LPTMR */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup LPTMR_Peripheral_access_layer_GROUP LPTMR Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPTMR0 (file:LPTMR0)                 ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */
/**
 * @struct LPTMR_Type
 * @brief  C Struct allowing access to LPTMR registers
 */
typedef struct LPTMR_Type {
   __IO uint32_t  CSR;                          /**< 0000: Control Status Register                                      */
   __IO uint32_t  PSR;                          /**< 0004: Prescale Register                                            */
   __IO uint32_t  CMR;                          /**< 0008: Compare Register                                             */
   __IO uint32_t  CNR;                          /**< 000C: Counter Register                                             */
} LPTMR_Type;


/** @brief Register Masks for LPTMR */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPTMR0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup LPTMR_Register_Masks_GROUP LPTMR Register Masks */
/** @{ */

/** @name CSR - Control Status Register */ /** @{ */
#define LPTMR_CSR_TEN_MASK                       (0x1U)                                              /**< LPTMR0_CSR.TEN Mask                     */
#define LPTMR_CSR_TEN_SHIFT                      (0U)                                                /**< LPTMR0_CSR.TEN Position                 */
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TEN_SHIFT))&LPTMR_CSR_TEN_MASK) /**< LPTMR0_CSR.TEN Field                    */
#define LPTMR_CSR_TMS_MASK                       (0x2U)                                              /**< LPTMR0_CSR.TMS Mask                     */
#define LPTMR_CSR_TMS_SHIFT                      (1U)                                                /**< LPTMR0_CSR.TMS Position                 */
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TMS_SHIFT))&LPTMR_CSR_TMS_MASK) /**< LPTMR0_CSR.TMS Field                    */
#define LPTMR_CSR_TFC_MASK                       (0x4U)                                              /**< LPTMR0_CSR.TFC Mask                     */
#define LPTMR_CSR_TFC_SHIFT                      (2U)                                                /**< LPTMR0_CSR.TFC Position                 */
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TFC_SHIFT))&LPTMR_CSR_TFC_MASK) /**< LPTMR0_CSR.TFC Field                    */
#define LPTMR_CSR_TPP_MASK                       (0x8U)                                              /**< LPTMR0_CSR.TPP Mask                     */
#define LPTMR_CSR_TPP_SHIFT                      (3U)                                                /**< LPTMR0_CSR.TPP Position                 */
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPP_SHIFT))&LPTMR_CSR_TPP_MASK) /**< LPTMR0_CSR.TPP Field                    */
#define LPTMR_CSR_TPS_MASK                       (0x30U)                                             /**< LPTMR0_CSR.TPS Mask                     */
#define LPTMR_CSR_TPS_SHIFT                      (4U)                                                /**< LPTMR0_CSR.TPS Position                 */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK) /**< LPTMR0_CSR.TPS Field                    */
#define LPTMR_CSR_TIE_MASK                       (0x40U)                                             /**< LPTMR0_CSR.TIE Mask                     */
#define LPTMR_CSR_TIE_SHIFT                      (6U)                                                /**< LPTMR0_CSR.TIE Position                 */
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TIE_SHIFT))&LPTMR_CSR_TIE_MASK) /**< LPTMR0_CSR.TIE Field                    */
#define LPTMR_CSR_TCF_MASK                       (0x80U)                                             /**< LPTMR0_CSR.TCF Mask                     */
#define LPTMR_CSR_TCF_SHIFT                      (7U)                                                /**< LPTMR0_CSR.TCF Position                 */
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TCF_SHIFT))&LPTMR_CSR_TCF_MASK) /**< LPTMR0_CSR.TCF Field                    */
/** @} */

/** @name PSR - Prescale Register */ /** @{ */
#define LPTMR_PSR_PCS_MASK                       (0x3U)                                              /**< LPTMR0_PSR.PCS Mask                     */
#define LPTMR_PSR_PCS_SHIFT                      (0U)                                                /**< LPTMR0_PSR.PCS Position                 */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK) /**< LPTMR0_PSR.PCS Field                    */
#define LPTMR_PSR_PBYP_MASK                      (0x4U)                                              /**< LPTMR0_PSR.PBYP Mask                    */
#define LPTMR_PSR_PBYP_SHIFT                     (2U)                                                /**< LPTMR0_PSR.PBYP Position                */
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PBYP_SHIFT))&LPTMR_PSR_PBYP_MASK) /**< LPTMR0_PSR.PBYP Field                   */
#define LPTMR_PSR_PRESCALE_MASK                  (0x78U)                                             /**< LPTMR0_PSR.PRESCALE Mask                */
#define LPTMR_PSR_PRESCALE_SHIFT                 (3U)                                                /**< LPTMR0_PSR.PRESCALE Position            */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK) /**< LPTMR0_PSR.PRESCALE Field               */
/** @} */

/** @name CMR - Compare Register */ /** @{ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFU)                                           /**< LPTMR0_CMR.COMPARE Mask                 */
#define LPTMR_CMR_COMPARE_SHIFT                  (0U)                                                /**< LPTMR0_CMR.COMPARE Position             */
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK) /**< LPTMR0_CMR.COMPARE Field                */
/** @} */

/** @name CNR - Counter Register */ /** @{ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFU)                                           /**< LPTMR0_CNR.COUNTER Mask                 */
#define LPTMR_CNR_COUNTER_SHIFT                  (0U)                                                /**< LPTMR0_CNR.COUNTER Position             */
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK) /**< LPTMR0_CNR.COUNTER Field                */
/** @} */

/** @} */ /* End group LPTMR_Register_Masks_GROUP */


/* LPTMR0 - Peripheral instance base addresses */
#define LPTMR0_BasePtr                 0x40040000UL //!< Peripheral base address
#define LPTMR0                         ((LPTMR_Type *) LPTMR0_BasePtr) //!< Freescale base pointer
#define LPTMR0_BASE_PTR                (LPTMR0) //!< Freescale style base pointer
#define LPTMR0_IRQS { LPTMR0_IRQn,  }


/** @} */ /* End group LPTMR_Peripheral_access_layer_GROUP */


/** @brief C Struct for MCG */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           MCG (file:MCG_MKL14Z4)               ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator module
 */
/**
 * @struct MCG_Type
 * @brief  C Struct allowing access to MCG registers
 */
typedef struct MCG_Type {
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /**< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /**< 0003: Control 4 Register                                           */
   __IO uint8_t   C5;                           /**< 0004: Control 5 Register                                           */
   __IO uint8_t   C6;                           /**< 0005: Control 6 Register                                           */
   __IO uint8_t   S;                            /**< 0006: Status Register                                              */
        uint8_t   RESERVED_0;                   /**< 0007: 0x1 bytes                                                    */
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
        uint8_t   RESERVED_1;                   /**< 0009: 0x1 bytes                                                    */
   __IO uint8_t   ATCVH;                        /**< 000A: ATM Compare Value High                                       */
   __IO uint8_t   ATCVL;                        /**< 000B: ATM Compare Value Low                                        */
   __I  uint8_t   C7;                           /**< 000C: Control 7 Register                                           */
   __IO uint8_t   C8;                           /**< 000D: Control 8 Register                                           */
   __I  uint8_t   C9;                           /**< 000E: Control 9 Register                                           */
   __I  uint8_t   C10;                          /**< 000F: Control 10 Register                                          */
} MCG_Type;


/** @brief Register Masks for MCG */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup MCG_Register_Masks_GROUP MCG Register Masks */
/** @{ */

/** @name C1 - Control 1 Register */ /** @{ */
#define MCG_C1_IREFSTEN_MASK                     (0x1U)                                              /**< MCG_C1.IREFSTEN Mask                    */
#define MCG_C1_IREFSTEN_SHIFT                    (0U)                                                /**< MCG_C1.IREFSTEN Position                */
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFSTEN_SHIFT))&MCG_C1_IREFSTEN_MASK) /**< MCG_C1.IREFSTEN Field                   */
#define MCG_C1_IRCLKEN_MASK                      (0x2U)                                              /**< MCG_C1.IRCLKEN Mask                     */
#define MCG_C1_IRCLKEN_SHIFT                     (1U)                                                /**< MCG_C1.IRCLKEN Position                 */
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C1_IRCLKEN_SHIFT))&MCG_C1_IRCLKEN_MASK) /**< MCG_C1.IRCLKEN Field                    */
#define MCG_C1_IREFS_MASK                        (0x4U)                                              /**< MCG_C1.IREFS Mask                       */
#define MCG_C1_IREFS_SHIFT                       (2U)                                                /**< MCG_C1.IREFS Position                   */
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFS_SHIFT))&MCG_C1_IREFS_MASK) /**< MCG_C1.IREFS Field                      */
#define MCG_C1_FRDIV_MASK                        (0x38U)                                             /**< MCG_C1.FRDIV Mask                       */
#define MCG_C1_FRDIV_SHIFT                       (3U)                                                /**< MCG_C1.FRDIV Position                   */
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK) /**< MCG_C1.FRDIV Field                      */
#define MCG_C1_CLKS_MASK                         (0xC0U)                                             /**< MCG_C1.CLKS Mask                        */
#define MCG_C1_CLKS_SHIFT                        (6U)                                                /**< MCG_C1.CLKS Position                    */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK) /**< MCG_C1.CLKS Field                       */
/** @} */

/** @name C2 - Control 2 Register */ /** @{ */
#define MCG_C2_IRCS_MASK                         (0x1U)                                              /**< MCG_C2.IRCS Mask                        */
#define MCG_C2_IRCS_SHIFT                        (0U)                                                /**< MCG_C2.IRCS Position                    */
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_IRCS_SHIFT))&MCG_C2_IRCS_MASK) /**< MCG_C2.IRCS Field                       */
#define MCG_C2_LP_MASK                           (0x2U)                                              /**< MCG_C2.LP Mask                          */
#define MCG_C2_LP_SHIFT                          (1U)                                                /**< MCG_C2.LP Position                      */
#define MCG_C2_LP(x)                             (((uint8_t)(((uint8_t)(x))<<MCG_C2_LP_SHIFT))&MCG_C2_LP_MASK) /**< MCG_C2.LP Field                         */
#define MCG_C2_EREFS0_MASK                       (0x4U)                                              /**< MCG_C2.EREFS0 Mask                      */
#define MCG_C2_EREFS0_SHIFT                      (2U)                                                /**< MCG_C2.EREFS0 Position                  */
#define MCG_C2_EREFS0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_EREFS0_SHIFT))&MCG_C2_EREFS0_MASK) /**< MCG_C2.EREFS0 Field                     */
#define MCG_C2_HGO0_MASK                         (0x8U)                                              /**< MCG_C2.HGO0 Mask                        */
#define MCG_C2_HGO0_SHIFT                        (3U)                                                /**< MCG_C2.HGO0 Position                    */
#define MCG_C2_HGO0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_HGO0_SHIFT))&MCG_C2_HGO0_MASK) /**< MCG_C2.HGO0 Field                       */
#define MCG_C2_RANGE0_MASK                       (0x30U)                                             /**< MCG_C2.RANGE0 Mask                      */
#define MCG_C2_RANGE0_SHIFT                      (4U)                                                /**< MCG_C2.RANGE0 Position                  */
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK) /**< MCG_C2.RANGE0 Field                     */
#define MCG_C2_LOCRE0_MASK                       (0x80U)                                             /**< MCG_C2.LOCRE0 Mask                      */
#define MCG_C2_LOCRE0_SHIFT                      (7U)                                                /**< MCG_C2.LOCRE0 Position                  */
#define MCG_C2_LOCRE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_LOCRE0_SHIFT))&MCG_C2_LOCRE0_MASK) /**< MCG_C2.LOCRE0 Field                     */
/** @} */

/** @name C3 - Control 3 Register */ /** @{ */
#define MCG_C3_SCTRIM_MASK                       (0xFFU)                                             /**< MCG_C3.SCTRIM Mask                      */
#define MCG_C3_SCTRIM_SHIFT                      (0U)                                                /**< MCG_C3.SCTRIM Position                  */
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK) /**< MCG_C3.SCTRIM Field                     */
/** @} */

/** @name C4 - Control 4 Register */ /** @{ */
#define MCG_C4_SCFTRIM_MASK                      (0x1U)                                              /**< MCG_C4.SCFTRIM Mask                     */
#define MCG_C4_SCFTRIM_SHIFT                     (0U)                                                /**< MCG_C4.SCFTRIM Position                 */
#define MCG_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C4_SCFTRIM_SHIFT))&MCG_C4_SCFTRIM_MASK) /**< MCG_C4.SCFTRIM Field                    */
#define MCG_C4_FCTRIM_MASK                       (0x1EU)                                             /**< MCG_C4.FCTRIM Mask                      */
#define MCG_C4_FCTRIM_SHIFT                      (1U)                                                /**< MCG_C4.FCTRIM Position                  */
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK) /**< MCG_C4.FCTRIM Field                     */
#define MCG_C4_DRST_DRS_MASK                     (0x60U)                                             /**< MCG_C4.DRST_DRS Mask                    */
#define MCG_C4_DRST_DRS_SHIFT                    (5U)                                                /**< MCG_C4.DRST_DRS Position                */
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK) /**< MCG_C4.DRST_DRS Field                   */
#define MCG_C4_DMX32_MASK                        (0x80U)                                             /**< MCG_C4.DMX32 Mask                       */
#define MCG_C4_DMX32_SHIFT                       (7U)                                                /**< MCG_C4.DMX32 Position                   */
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C4_DMX32_SHIFT))&MCG_C4_DMX32_MASK) /**< MCG_C4.DMX32 Field                      */
/** @} */

/** @name C5 - Control 5 Register */ /** @{ */
#define MCG_C5_PRDIV0_MASK                       (0x1FU)                                             /**< MCG_C5.PRDIV0 Mask                      */
#define MCG_C5_PRDIV0_SHIFT                      (0U)                                                /**< MCG_C5.PRDIV0 Position                  */
#define MCG_C5_PRDIV0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C5_PRDIV0_SHIFT))&MCG_C5_PRDIV0_MASK) /**< MCG_C5.PRDIV0 Field                     */
#define MCG_C5_PLLSTEN0_MASK                     (0x20U)                                             /**< MCG_C5.PLLSTEN0 Mask                    */
#define MCG_C5_PLLSTEN0_SHIFT                    (5U)                                                /**< MCG_C5.PLLSTEN0 Position                */
#define MCG_C5_PLLSTEN0(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C5_PLLSTEN0_SHIFT))&MCG_C5_PLLSTEN0_MASK) /**< MCG_C5.PLLSTEN0 Field                   */
#define MCG_C5_PLLCLKEN0_MASK                    (0x40U)                                             /**< MCG_C5.PLLCLKEN0 Mask                   */
#define MCG_C5_PLLCLKEN0_SHIFT                   (6U)                                                /**< MCG_C5.PLLCLKEN0 Position               */
#define MCG_C5_PLLCLKEN0(x)                      (((uint8_t)(((uint8_t)(x))<<MCG_C5_PLLCLKEN0_SHIFT))&MCG_C5_PLLCLKEN0_MASK) /**< MCG_C5.PLLCLKEN0 Field                  */
/** @} */

/** @name C6 - Control 6 Register */ /** @{ */
#define MCG_C6_VDIV0_MASK                        (0x1FU)                                             /**< MCG_C6.VDIV0 Mask                       */
#define MCG_C6_VDIV0_SHIFT                       (0U)                                                /**< MCG_C6.VDIV0 Position                   */
#define MCG_C6_VDIV0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C6_VDIV0_SHIFT))&MCG_C6_VDIV0_MASK) /**< MCG_C6.VDIV0 Field                      */
#define MCG_C6_CME0_MASK                         (0x20U)                                             /**< MCG_C6.CME0 Mask                        */
#define MCG_C6_CME0_SHIFT                        (5U)                                                /**< MCG_C6.CME0 Position                    */
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_CME0_SHIFT))&MCG_C6_CME0_MASK) /**< MCG_C6.CME0 Field                       */
#define MCG_C6_PLLS_MASK                         (0x40U)                                             /**< MCG_C6.PLLS Mask                        */
#define MCG_C6_PLLS_SHIFT                        (6U)                                                /**< MCG_C6.PLLS Position                    */
#define MCG_C6_PLLS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_PLLS_SHIFT))&MCG_C6_PLLS_MASK) /**< MCG_C6.PLLS Field                       */
#define MCG_C6_LOLIE0_MASK                       (0x80U)                                             /**< MCG_C6.LOLIE0 Mask                      */
#define MCG_C6_LOLIE0_SHIFT                      (7U)                                                /**< MCG_C6.LOLIE0 Position                  */
#define MCG_C6_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C6_LOLIE0_SHIFT))&MCG_C6_LOLIE0_MASK) /**< MCG_C6.LOLIE0 Field                     */
/** @} */

/** @name S - Status Register */ /** @{ */
#define MCG_S_IRCST_MASK                         (0x1U)                                              /**< MCG_S.IRCST Mask                        */
#define MCG_S_IRCST_SHIFT                        (0U)                                                /**< MCG_S.IRCST Position                    */
#define MCG_S_IRCST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_IRCST_SHIFT))&MCG_S_IRCST_MASK) /**< MCG_S.IRCST Field                       */
#define MCG_S_OSCINIT0_MASK                      (0x2U)                                              /**< MCG_S.OSCINIT0 Mask                     */
#define MCG_S_OSCINIT0_SHIFT                     (1U)                                                /**< MCG_S.OSCINIT0 Position                 */
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_S_OSCINIT0_SHIFT))&MCG_S_OSCINIT0_MASK) /**< MCG_S.OSCINIT0 Field                    */
#define MCG_S_CLKST_MASK                         (0xCU)                                              /**< MCG_S.CLKST Mask                        */
#define MCG_S_CLKST_SHIFT                        (2U)                                                /**< MCG_S.CLKST Position                    */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK) /**< MCG_S.CLKST Field                       */
#define MCG_S_IREFST_MASK                        (0x10U)                                             /**< MCG_S.IREFST Mask                       */
#define MCG_S_IREFST_SHIFT                       (4U)                                                /**< MCG_S.IREFST Position                   */
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_S_IREFST_SHIFT))&MCG_S_IREFST_MASK) /**< MCG_S.IREFST Field                      */
#define MCG_S_PLLST_MASK                         (0x20U)                                             /**< MCG_S.PLLST Mask                        */
#define MCG_S_PLLST_SHIFT                        (5U)                                                /**< MCG_S.PLLST Position                    */
#define MCG_S_PLLST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_PLLST_SHIFT))&MCG_S_PLLST_MASK) /**< MCG_S.PLLST Field                       */
#define MCG_S_LOCK0_MASK                         (0x40U)                                             /**< MCG_S.LOCK0 Mask                        */
#define MCG_S_LOCK0_SHIFT                        (6U)                                                /**< MCG_S.LOCK0 Position                    */
#define MCG_S_LOCK0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_LOCK0_SHIFT))&MCG_S_LOCK0_MASK) /**< MCG_S.LOCK0 Field                       */
#define MCG_S_LOLS0_MASK                         (0x80U)                                             /**< MCG_S.LOLS0 Mask                        */
#define MCG_S_LOLS0_SHIFT                        (7U)                                                /**< MCG_S.LOLS0 Position                    */
#define MCG_S_LOLS0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_LOLS0_SHIFT))&MCG_S_LOLS0_MASK) /**< MCG_S.LOLS0 Field                       */
/** @} */

/** @name SC - Status and Control Register */ /** @{ */
#define MCG_SC_LOCS0_MASK                        (0x1U)                                              /**< MCG_SC.LOCS0 Mask                       */
#define MCG_SC_LOCS0_SHIFT                       (0U)                                                /**< MCG_SC.LOCS0 Position                   */
#define MCG_SC_LOCS0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_SC_LOCS0_SHIFT))&MCG_SC_LOCS0_MASK) /**< MCG_SC.LOCS0 Field                      */
#define MCG_SC_FCRDIV_MASK                       (0xEU)                                              /**< MCG_SC.FCRDIV Mask                      */
#define MCG_SC_FCRDIV_SHIFT                      (1U)                                                /**< MCG_SC.FCRDIV Position                  */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK) /**< MCG_SC.FCRDIV Field                     */
#define MCG_SC_FLTPRSRV_MASK                     (0x10U)                                             /**< MCG_SC.FLTPRSRV Mask                    */
#define MCG_SC_FLTPRSRV_SHIFT                    (4U)                                                /**< MCG_SC.FLTPRSRV Position                */
#define MCG_SC_FLTPRSRV(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_SC_FLTPRSRV_SHIFT))&MCG_SC_FLTPRSRV_MASK) /**< MCG_SC.FLTPRSRV Field                   */
#define MCG_SC_ATMF_MASK                         (0x20U)                                             /**< MCG_SC.ATMF Mask                        */
#define MCG_SC_ATMF_SHIFT                        (5U)                                                /**< MCG_SC.ATMF Position                    */
#define MCG_SC_ATMF(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATMF_SHIFT))&MCG_SC_ATMF_MASK) /**< MCG_SC.ATMF Field                       */
#define MCG_SC_ATMS_MASK                         (0x40U)                                             /**< MCG_SC.ATMS Mask                        */
#define MCG_SC_ATMS_SHIFT                        (6U)                                                /**< MCG_SC.ATMS Position                    */
#define MCG_SC_ATMS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATMS_SHIFT))&MCG_SC_ATMS_MASK) /**< MCG_SC.ATMS Field                       */
#define MCG_SC_ATME_MASK                         (0x80U)                                             /**< MCG_SC.ATME Mask                        */
#define MCG_SC_ATME_SHIFT                        (7U)                                                /**< MCG_SC.ATME Position                    */
#define MCG_SC_ATME(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATME_SHIFT))&MCG_SC_ATME_MASK) /**< MCG_SC.ATME Field                       */
/** @} */

/** @name ATCVH - ATM Compare Value High */ /** @{ */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFU)                                             /**< MCG_ATCVH.ATCVH Mask                    */
#define MCG_ATCVH_ATCVH_SHIFT                    (0U)                                                /**< MCG_ATCVH.ATCVH Position                */
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK) /**< MCG_ATCVH.ATCVH Field                   */
/** @} */

/** @name ATCVL - ATM Compare Value Low */ /** @{ */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFU)                                             /**< MCG_ATCVL.ATCVL Mask                    */
#define MCG_ATCVL_ATCVL_SHIFT                    (0U)                                                /**< MCG_ATCVL.ATCVL Position                */
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK) /**< MCG_ATCVL.ATCVL Field                   */
/** @} */

/** @name C8 - Control 8 Register */ /** @{ */
#define MCG_C8_LOLRE_MASK                        (0x40U)                                             /**< MCG_C8.LOLRE Mask                       */
#define MCG_C8_LOLRE_SHIFT                       (6U)                                                /**< MCG_C8.LOLRE Position                   */
#define MCG_C8_LOLRE(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOLRE_SHIFT))&MCG_C8_LOLRE_MASK) /**< MCG_C8.LOLRE Field                      */
/** @} */

/** @} */ /* End group MCG_Register_Masks_GROUP */


/* MCG - Peripheral instance base addresses */
#define MCG_BasePtr                    0x40064000UL //!< Peripheral base address
#define MCG                            ((MCG_Type *) MCG_BasePtr) //!< Freescale base pointer
#define MCG_BASE_PTR                   (MCG) //!< Freescale style base pointer
#define MCG_IRQS { MCG_IRQn,  }


/** @} */ /* End group MCG_Peripheral_access_layer_GROUP */


/** @brief C Struct for MCM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup MCM_Peripheral_access_layer_GROUP MCM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           MCM (file:MCM_MKL02Z4)               ================ */
/* ================================================================================ */

/**
 * @brief Core Platform Miscellaneous Control Module
 */
/**
 * @struct MCM_Type
 * @brief  C Struct allowing access to MCM registers
 */
typedef struct MCM_Type {
        uint8_t   RESERVED_0[8];                /**< 0000: 0x8 bytes                                                    */
   __I  uint16_t  PLASC;                        /**< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /**< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  PLACR;                        /**< 000C: Platform Control Register                                    */
        uint8_t   RESERVED_1[48];               /**< 0010: 0x30 bytes                                                   */
   __IO uint32_t  CPO;                          /**< 0040: Compute Operation Control Register                           */
} MCM_Type;


/** @brief Register Masks for MCM */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup MCM_Register_Masks_GROUP MCM Register Masks */
/** @{ */

/** @name PLASC - Crossbar Switch (AXBS) Slave Configuration */ /** @{ */
#define MCM_PLASC_ASC_MASK                       (0xFFU)                                             /**< MCM_PLASC.ASC Mask                      */
#define MCM_PLASC_ASC_SHIFT                      (0U)                                                /**< MCM_PLASC.ASC Position                  */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK) /**< MCM_PLASC.ASC Field                     */
/** @} */

/** @name PLAMC - Crossbar Switch (AXBS) Master Configuration */ /** @{ */
#define MCM_PLAMC_AMC_MASK                       (0xFFU)                                             /**< MCM_PLAMC.AMC Mask                      */
#define MCM_PLAMC_AMC_SHIFT                      (0U)                                                /**< MCM_PLAMC.AMC Position                  */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK) /**< MCM_PLAMC.AMC Field                     */
/** @} */

/** @name PLACR - Platform Control Register */ /** @{ */
#define MCM_PLACR_ARB_MASK                       (0x200U)                                            /**< MCM_PLACR.ARB Mask                      */
#define MCM_PLACR_ARB_SHIFT                      (9U)                                                /**< MCM_PLACR.ARB Position                  */
#define MCM_PLACR_ARB(x)                         (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_ARB_SHIFT))&MCM_PLACR_ARB_MASK) /**< MCM_PLACR.ARB Field                     */
#define MCM_PLACR_CFCC_MASK                      (0x400U)                                            /**< MCM_PLACR.CFCC Mask                     */
#define MCM_PLACR_CFCC_SHIFT                     (10U)                                               /**< MCM_PLACR.CFCC Position                 */
#define MCM_PLACR_CFCC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_CFCC_SHIFT))&MCM_PLACR_CFCC_MASK) /**< MCM_PLACR.CFCC Field                    */
#define MCM_PLACR_DFCDA_MASK                     (0x800U)                                            /**< MCM_PLACR.DFCDA Mask                    */
#define MCM_PLACR_DFCDA_SHIFT                    (11U)                                               /**< MCM_PLACR.DFCDA Position                */
#define MCM_PLACR_DFCDA(x)                       (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCDA_SHIFT))&MCM_PLACR_DFCDA_MASK) /**< MCM_PLACR.DFCDA Field                   */
#define MCM_PLACR_DFCIC_MASK                     (0x1000U)                                           /**< MCM_PLACR.DFCIC Mask                    */
#define MCM_PLACR_DFCIC_SHIFT                    (12U)                                               /**< MCM_PLACR.DFCIC Position                */
#define MCM_PLACR_DFCIC(x)                       (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCIC_SHIFT))&MCM_PLACR_DFCIC_MASK) /**< MCM_PLACR.DFCIC Field                   */
#define MCM_PLACR_DFCC_MASK                      (0x2000U)                                           /**< MCM_PLACR.DFCC Mask                     */
#define MCM_PLACR_DFCC_SHIFT                     (13U)                                               /**< MCM_PLACR.DFCC Position                 */
#define MCM_PLACR_DFCC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCC_SHIFT))&MCM_PLACR_DFCC_MASK) /**< MCM_PLACR.DFCC Field                    */
#define MCM_PLACR_EFDS_MASK                      (0x4000U)                                           /**< MCM_PLACR.EFDS Mask                     */
#define MCM_PLACR_EFDS_SHIFT                     (14U)                                               /**< MCM_PLACR.EFDS Position                 */
#define MCM_PLACR_EFDS(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_EFDS_SHIFT))&MCM_PLACR_EFDS_MASK) /**< MCM_PLACR.EFDS Field                    */
#define MCM_PLACR_DFCS_MASK                      (0x8000U)                                           /**< MCM_PLACR.DFCS Mask                     */
#define MCM_PLACR_DFCS_SHIFT                     (15U)                                               /**< MCM_PLACR.DFCS Position                 */
#define MCM_PLACR_DFCS(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_DFCS_SHIFT))&MCM_PLACR_DFCS_MASK) /**< MCM_PLACR.DFCS Field                    */
#define MCM_PLACR_ESFC_MASK                      (0x10000U)                                          /**< MCM_PLACR.ESFC Mask                     */
#define MCM_PLACR_ESFC_SHIFT                     (16U)                                               /**< MCM_PLACR.ESFC Position                 */
#define MCM_PLACR_ESFC(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_PLACR_ESFC_SHIFT))&MCM_PLACR_ESFC_MASK) /**< MCM_PLACR.ESFC Field                    */
/** @} */

/** @name CPO - Compute Operation Control Register */ /** @{ */
#define MCM_CPO_CPOREQ_MASK                      (0x1U)                                              /**< MCM_CPO.CPOREQ Mask                     */
#define MCM_CPO_CPOREQ_SHIFT                     (0U)                                                /**< MCM_CPO.CPOREQ Position                 */
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOREQ_SHIFT))&MCM_CPO_CPOREQ_MASK) /**< MCM_CPO.CPOREQ Field                    */
#define MCM_CPO_CPOACK_MASK                      (0x2U)                                              /**< MCM_CPO.CPOACK Mask                     */
#define MCM_CPO_CPOACK_SHIFT                     (1U)                                                /**< MCM_CPO.CPOACK Position                 */
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOACK_SHIFT))&MCM_CPO_CPOACK_MASK) /**< MCM_CPO.CPOACK Field                    */
#define MCM_CPO_CPOWOI_MASK                      (0x4U)                                              /**< MCM_CPO.CPOWOI Mask                     */
#define MCM_CPO_CPOWOI_SHIFT                     (2U)                                                /**< MCM_CPO.CPOWOI Position                 */
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CPO_CPOWOI_SHIFT))&MCM_CPO_CPOWOI_MASK) /**< MCM_CPO.CPOWOI Field                    */
/** @} */

/** @} */ /* End group MCM_Register_Masks_GROUP */


/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xF0003000UL //!< Peripheral base address
#define MCM                            ((MCM_Type *) MCM_BasePtr) //!< Freescale base pointer
#define MCM_BASE_PTR                   (MCM) //!< Freescale style base pointer

/** @} */ /* End group MCM_Peripheral_access_layer_GROUP */


/** @brief C Struct for MTB */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup MTB_Peripheral_access_layer_GROUP MTB Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           MTB (file:MTB_MKE15Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Micro Trace Buffer
 */
/**
 * @struct MTB_Type
 * @brief  C Struct allowing access to MTB registers
 */
typedef struct MTB_Type {
   __IO uint32_t  POSITION;                     /**< 0000: MTB Position Register                                        */
   __IO uint32_t  MASTER;                       /**< 0004: MTB Master Register                                          */
   __IO uint32_t  FLOW;                         /**< 0008: MTB Flow Register                                            */
   __I  uint32_t  BASE;                         /**< 000C: MTB Base Register                                            */
        uint8_t   RESERVED_0[3824];             /**< 0010: 0xEF0 bytes                                                  */
   __I  uint32_t  MODECTRL;                     /**< 0F00: Integration Mode Control Register                            */
        uint8_t   RESERVED_1[156];              /**< 0F04: 0x9C bytes                                                   */
   __I  uint32_t  TAGSET;                       /**< 0FA0: Claim TAG Set Register                                       */
   __I  uint32_t  TAGCLEAR;                     /**< 0FA4: Claim TAG Clear Register                                     */
        uint8_t   RESERVED_2[8];                /**< 0FA8: 0x8 bytes                                                    */
   __I  uint32_t  LOCKACCESS;                   /**< 0FB0: Lock Access Register                                         */
   __I  uint32_t  LOCKSTAT;                     /**< 0FB4: Lock Status Register                                         */
   __I  uint32_t  AUTHSTAT;                     /**< 0FB8: Authentication Status Register                               */
   __I  uint32_t  DEVICEARCH;                   /**< 0FBC: Device Architecture Register                                 */
        uint8_t   RESERVED_3[8];                /**< 0FC0: 0x8 bytes                                                    */
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


/** @brief Register Masks for MTB */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTB' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup MTB_Register_Masks_GROUP MTB Register Masks */
/** @{ */

/** @name POSITION - MTB Position Register */ /** @{ */
#define MTB_POSITION_WRAP_MASK                   (0x4U)                                              /**< MTB_POSITION.WRAP Mask                  */
#define MTB_POSITION_WRAP_SHIFT                  (2U)                                                /**< MTB_POSITION.WRAP Position              */
#define MTB_POSITION_WRAP(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_POSITION_WRAP_SHIFT))&MTB_POSITION_WRAP_MASK) /**< MTB_POSITION.WRAP Field                 */
#define MTB_POSITION_POINTER_MASK                (0xFFFFFFF8U)                                       /**< MTB_POSITION.POINTER Mask               */
#define MTB_POSITION_POINTER_SHIFT               (3U)                                                /**< MTB_POSITION.POINTER Position           */
#define MTB_POSITION_POINTER(x)                  (((uint32_t)(((uint32_t)(x))<<MTB_POSITION_POINTER_SHIFT))&MTB_POSITION_POINTER_MASK) /**< MTB_POSITION.POINTER Field              */
/** @} */

/** @name MASTER - MTB Master Register */ /** @{ */
#define MTB_MASTER_MASK_MASK                     (0x1FU)                                             /**< MTB_MASTER.MASK Mask                    */
#define MTB_MASTER_MASK_SHIFT                    (0U)                                                /**< MTB_MASTER.MASK Position                */
#define MTB_MASTER_MASK(x)                       (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_MASK_SHIFT))&MTB_MASTER_MASK_MASK) /**< MTB_MASTER.MASK Field                   */
#define MTB_MASTER_TSTARTEN_MASK                 (0x20U)                                             /**< MTB_MASTER.TSTARTEN Mask                */
#define MTB_MASTER_TSTARTEN_SHIFT                (5U)                                                /**< MTB_MASTER.TSTARTEN Position            */
#define MTB_MASTER_TSTARTEN(x)                   (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_TSTARTEN_SHIFT))&MTB_MASTER_TSTARTEN_MASK) /**< MTB_MASTER.TSTARTEN Field               */
#define MTB_MASTER_TSTOPEN_MASK                  (0x40U)                                             /**< MTB_MASTER.TSTOPEN Mask                 */
#define MTB_MASTER_TSTOPEN_SHIFT                 (6U)                                                /**< MTB_MASTER.TSTOPEN Position             */
#define MTB_MASTER_TSTOPEN(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_TSTOPEN_SHIFT))&MTB_MASTER_TSTOPEN_MASK) /**< MTB_MASTER.TSTOPEN Field                */
#define MTB_MASTER_SFRWPRIV_MASK                 (0x80U)                                             /**< MTB_MASTER.SFRWPRIV Mask                */
#define MTB_MASTER_SFRWPRIV_SHIFT                (7U)                                                /**< MTB_MASTER.SFRWPRIV Position            */
#define MTB_MASTER_SFRWPRIV(x)                   (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_SFRWPRIV_SHIFT))&MTB_MASTER_SFRWPRIV_MASK) /**< MTB_MASTER.SFRWPRIV Field               */
#define MTB_MASTER_RAMPRIV_MASK                  (0x100U)                                            /**< MTB_MASTER.RAMPRIV Mask                 */
#define MTB_MASTER_RAMPRIV_SHIFT                 (8U)                                                /**< MTB_MASTER.RAMPRIV Position             */
#define MTB_MASTER_RAMPRIV(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_RAMPRIV_SHIFT))&MTB_MASTER_RAMPRIV_MASK) /**< MTB_MASTER.RAMPRIV Field                */
#define MTB_MASTER_HALTREQ_MASK                  (0x200U)                                            /**< MTB_MASTER.HALTREQ Mask                 */
#define MTB_MASTER_HALTREQ_SHIFT                 (9U)                                                /**< MTB_MASTER.HALTREQ Position             */
#define MTB_MASTER_HALTREQ(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_HALTREQ_SHIFT))&MTB_MASTER_HALTREQ_MASK) /**< MTB_MASTER.HALTREQ Field                */
#define MTB_MASTER_EN_MASK                       (0x80000000U)                                       /**< MTB_MASTER.EN Mask                      */
#define MTB_MASTER_EN_SHIFT                      (31U)                                               /**< MTB_MASTER.EN Position                  */
#define MTB_MASTER_EN(x)                         (((uint32_t)(((uint32_t)(x))<<MTB_MASTER_EN_SHIFT))&MTB_MASTER_EN_MASK) /**< MTB_MASTER.EN Field                     */
/** @} */

/** @name FLOW - MTB Flow Register */ /** @{ */
#define MTB_FLOW_AUTOSTOP_MASK                   (0x1U)                                              /**< MTB_FLOW.AUTOSTOP Mask                  */
#define MTB_FLOW_AUTOSTOP_SHIFT                  (0U)                                                /**< MTB_FLOW.AUTOSTOP Position              */
#define MTB_FLOW_AUTOSTOP(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_AUTOSTOP_SHIFT))&MTB_FLOW_AUTOSTOP_MASK) /**< MTB_FLOW.AUTOSTOP Field                 */
#define MTB_FLOW_AUTOHALT_MASK                   (0x2U)                                              /**< MTB_FLOW.AUTOHALT Mask                  */
#define MTB_FLOW_AUTOHALT_SHIFT                  (1U)                                                /**< MTB_FLOW.AUTOHALT Position              */
#define MTB_FLOW_AUTOHALT(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_AUTOHALT_SHIFT))&MTB_FLOW_AUTOHALT_MASK) /**< MTB_FLOW.AUTOHALT Field                 */
#define MTB_FLOW_WATERMARK_MASK                  (0xFFFFFFF8U)                                       /**< MTB_FLOW.WATERMARK Mask                 */
#define MTB_FLOW_WATERMARK_SHIFT                 (3U)                                                /**< MTB_FLOW.WATERMARK Position             */
#define MTB_FLOW_WATERMARK(x)                    (((uint32_t)(((uint32_t)(x))<<MTB_FLOW_WATERMARK_SHIFT))&MTB_FLOW_WATERMARK_MASK) /**< MTB_FLOW.WATERMARK Field                */
/** @} */

/** @name BASE - MTB Base Register */ /** @{ */
#define MTB_BASE_BASEADDR_MASK                   (0xFFFFFFFFU)                                       /**< MTB_BASE.BASEADDR Mask                  */
#define MTB_BASE_BASEADDR_SHIFT                  (0U)                                                /**< MTB_BASE.BASEADDR Position              */
#define MTB_BASE_BASEADDR(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_BASE_BASEADDR_SHIFT))&MTB_BASE_BASEADDR_MASK) /**< MTB_BASE.BASEADDR Field                 */
/** @} */

/** @name MODECTRL - Integration Mode Control Register */ /** @{ */
#define MTB_MODECTRL_MODECTRL_MASK               (0xFFFFFFFFU)                                       /**< MTB_MODECTRL.MODECTRL Mask              */
#define MTB_MODECTRL_MODECTRL_SHIFT              (0U)                                                /**< MTB_MODECTRL.MODECTRL Position          */
#define MTB_MODECTRL_MODECTRL(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_MODECTRL_MODECTRL_SHIFT))&MTB_MODECTRL_MODECTRL_MASK) /**< MTB_MODECTRL.MODECTRL Field             */
/** @} */

/** @name TAGSET - Claim TAG Set Register */ /** @{ */
#define MTB_TAGSET_TAGSET_MASK                   (0xFFFFFFFFU)                                       /**< MTB_TAGSET.TAGSET Mask                  */
#define MTB_TAGSET_TAGSET_SHIFT                  (0U)                                                /**< MTB_TAGSET.TAGSET Position              */
#define MTB_TAGSET_TAGSET(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_TAGSET_TAGSET_SHIFT))&MTB_TAGSET_TAGSET_MASK) /**< MTB_TAGSET.TAGSET Field                 */
/** @} */

/** @name TAGCLEAR - Claim TAG Clear Register */ /** @{ */
#define MTB_TAGCLEAR_TAGCLEAR_MASK               (0xFFFFFFFFU)                                       /**< MTB_TAGCLEAR.TAGCLEAR Mask              */
#define MTB_TAGCLEAR_TAGCLEAR_SHIFT              (0U)                                                /**< MTB_TAGCLEAR.TAGCLEAR Position          */
#define MTB_TAGCLEAR_TAGCLEAR(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_TAGCLEAR_TAGCLEAR_SHIFT))&MTB_TAGCLEAR_TAGCLEAR_MASK) /**< MTB_TAGCLEAR.TAGCLEAR Field             */
/** @} */

/** @name LOCKACCESS - Lock Access Register */ /** @{ */
#define MTB_LOCKACCESS_LOCKACCESS_MASK           (0xFFFFFFFFU)                                       /**< MTB_LOCKACCESS.LOCKACCESS Mask          */
#define MTB_LOCKACCESS_LOCKACCESS_SHIFT          (0U)                                                /**< MTB_LOCKACCESS.LOCKACCESS Position      */
#define MTB_LOCKACCESS_LOCKACCESS(x)             (((uint32_t)(((uint32_t)(x))<<MTB_LOCKACCESS_LOCKACCESS_SHIFT))&MTB_LOCKACCESS_LOCKACCESS_MASK) /**< MTB_LOCKACCESS.LOCKACCESS Field         */
/** @} */

/** @name LOCKSTAT - Lock Status Register */ /** @{ */
#define MTB_LOCKSTAT_LOCKSTAT_MASK               (0xFFFFFFFFU)                                       /**< MTB_LOCKSTAT.LOCKSTAT Mask              */
#define MTB_LOCKSTAT_LOCKSTAT_SHIFT              (0U)                                                /**< MTB_LOCKSTAT.LOCKSTAT Position          */
#define MTB_LOCKSTAT_LOCKSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_LOCKSTAT_LOCKSTAT_SHIFT))&MTB_LOCKSTAT_LOCKSTAT_MASK) /**< MTB_LOCKSTAT.LOCKSTAT Field             */
/** @} */

/** @name AUTHSTAT - Authentication Status Register */ /** @{ */
#define MTB_AUTHSTAT_BIT0_MASK                   (0x1U)                                              /**< MTB_AUTHSTAT.BIT0 Mask                  */
#define MTB_AUTHSTAT_BIT0_SHIFT                  (0U)                                                /**< MTB_AUTHSTAT.BIT0 Position              */
#define MTB_AUTHSTAT_BIT0(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT0_SHIFT))&MTB_AUTHSTAT_BIT0_MASK) /**< MTB_AUTHSTAT.BIT0 Field                 */
#define MTB_AUTHSTAT_BIT1_MASK                   (0x2U)                                              /**< MTB_AUTHSTAT.BIT1 Mask                  */
#define MTB_AUTHSTAT_BIT1_SHIFT                  (1U)                                                /**< MTB_AUTHSTAT.BIT1 Position              */
#define MTB_AUTHSTAT_BIT1(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT1_SHIFT))&MTB_AUTHSTAT_BIT1_MASK) /**< MTB_AUTHSTAT.BIT1 Field                 */
#define MTB_AUTHSTAT_BIT2_MASK                   (0x4U)                                              /**< MTB_AUTHSTAT.BIT2 Mask                  */
#define MTB_AUTHSTAT_BIT2_SHIFT                  (2U)                                                /**< MTB_AUTHSTAT.BIT2 Position              */
#define MTB_AUTHSTAT_BIT2(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT2_SHIFT))&MTB_AUTHSTAT_BIT2_MASK) /**< MTB_AUTHSTAT.BIT2 Field                 */
#define MTB_AUTHSTAT_BIT3_MASK                   (0x8U)                                              /**< MTB_AUTHSTAT.BIT3 Mask                  */
#define MTB_AUTHSTAT_BIT3_SHIFT                  (3U)                                                /**< MTB_AUTHSTAT.BIT3 Position              */
#define MTB_AUTHSTAT_BIT3(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_AUTHSTAT_BIT3_SHIFT))&MTB_AUTHSTAT_BIT3_MASK) /**< MTB_AUTHSTAT.BIT3 Field                 */
/** @} */

/** @name DEVICEARCH - Device Architecture Register */ /** @{ */
#define MTB_DEVICEARCH_DEVICEARCH_MASK           (0xFFFFFFFFU)                                       /**< MTB_DEVICEARCH.DEVICEARCH Mask          */
#define MTB_DEVICEARCH_DEVICEARCH_SHIFT          (0U)                                                /**< MTB_DEVICEARCH.DEVICEARCH Position      */
#define MTB_DEVICEARCH_DEVICEARCH(x)             (((uint32_t)(((uint32_t)(x))<<MTB_DEVICEARCH_DEVICEARCH_SHIFT))&MTB_DEVICEARCH_DEVICEARCH_MASK) /**< MTB_DEVICEARCH.DEVICEARCH Field         */
/** @} */

/** @name DEVICECFG - Device Configuration Register */ /** @{ */
#define MTB_DEVICECFG_DEVICECFG_MASK             (0xFFFFFFFFU)                                       /**< MTB_DEVICECFG.DEVICECFG Mask            */
#define MTB_DEVICECFG_DEVICECFG_SHIFT            (0U)                                                /**< MTB_DEVICECFG.DEVICECFG Position        */
#define MTB_DEVICECFG_DEVICECFG(x)               (((uint32_t)(((uint32_t)(x))<<MTB_DEVICECFG_DEVICECFG_SHIFT))&MTB_DEVICECFG_DEVICECFG_MASK) /**< MTB_DEVICECFG.DEVICECFG Field           */
/** @} */

/** @name DEVICETYPID - Device Type Identifier Register */ /** @{ */
#define MTB_DEVICETYPID_DEVICETYPID_MASK         (0xFFFFFFFFU)                                       /**< MTB_DEVICETYPID.DEVICETYPID Mask        */
#define MTB_DEVICETYPID_DEVICETYPID_SHIFT        (0U)                                                /**< MTB_DEVICETYPID.DEVICETYPID Position    */
#define MTB_DEVICETYPID_DEVICETYPID(x)           (((uint32_t)(((uint32_t)(x))<<MTB_DEVICETYPID_DEVICETYPID_SHIFT))&MTB_DEVICETYPID_DEVICETYPID_MASK) /**< MTB_DEVICETYPID.DEVICETYPID Field       */
/** @} */

/** @name PERIPHID - Peripheral ID Register */ /** @{ */
#define MTB_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFU)                                       /**< MTB_PERIPHID.PERIPHID Mask              */
#define MTB_PERIPHID_PERIPHID_SHIFT              (0U)                                                /**< MTB_PERIPHID.PERIPHID Position          */
#define MTB_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<MTB_PERIPHID_PERIPHID_SHIFT))&MTB_PERIPHID_PERIPHID_MASK) /**< MTB_PERIPHID.PERIPHID Field             */
/** @} */

/** @name COMPID - Component ID Register */ /** @{ */
#define MTB_COMPID_COMPID_MASK                   (0xFFFFFFFFU)                                       /**< MTB_COMPID.COMPID Mask                  */
#define MTB_COMPID_COMPID_SHIFT                  (0U)                                                /**< MTB_COMPID.COMPID Position              */
#define MTB_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<MTB_COMPID_COMPID_SHIFT))&MTB_COMPID_COMPID_MASK) /**< MTB_COMPID.COMPID Field                 */
/** @} */

/** @} */ /* End group MTB_Register_Masks_GROUP */


/* MTB - Peripheral instance base addresses */
#define MTB_BasePtr                    0xF0000000UL //!< Peripheral base address
#define MTB                            ((MTB_Type *) MTB_BasePtr) //!< Freescale base pointer
#define MTB_BASE_PTR                   (MTB) //!< Freescale style base pointer

/** @} */ /* End group MTB_Peripheral_access_layer_GROUP */


/** @brief C Struct for MTBDWT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup MTBDWT_Peripheral_access_layer_GROUP MTBDWT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           MTBDWT (file:MTBDWT_MKE15Z7)         ================ */
/* ================================================================================ */

/**
 * @brief MTB data watchpoint and trace
 */
/**
 * @struct MTBDWT_Type
 * @brief  C Struct allowing access to MTBDWT registers
 */
typedef struct MTBDWT_Type {
   __I  uint32_t  CTRL;                         /**< 0000: MTB DWT Control Register                                     */
        uint8_t   RESERVED_0[28];               /**< 0004: 0x1C bytes                                                   */
   struct {
      __IO uint32_t  COMP;                      /**< 0020: MTB_DWT Comparator Register                                  */
      __IO uint32_t  MASK;                      /**< 0024: MTB_DWT Comparator Mask Register                             */
      __IO uint32_t  FCT;                       /**< 0028: MTB_DWT Comparator Function Register 0                       */
           uint8_t   RESERVED_1[4];             /**< 002C: 0x4 bytes                                                    */
   } COMPARATOR[2];                             /**< 0020: (cluster: size=0x0020, 32)                                   */
        uint8_t   RESERVED_2[448];              /**< 0040: 0x1C0 bytes                                                  */
   __IO uint32_t  TBCTRL;                       /**< 0200: MTB_DWT Trace Buffer Control Register                        */
        uint8_t   RESERVED_3[3524];             /**< 0204: 0xDC4 bytes                                                  */
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


/** @brief Register Masks for MTBDWT */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTBDWT' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup MTBDWT_Register_Masks_GROUP MTBDWT Register Masks */
/** @{ */

/** @name CTRL - MTB DWT Control Register */ /** @{ */
#define MTBDWT_CTRL_DWTCFGCTRL_MASK              (0xFFFFFFFU)                                        /**< MTBDWT_CTRL.DWTCFGCTRL Mask             */
#define MTBDWT_CTRL_DWTCFGCTRL_SHIFT             (0U)                                                /**< MTBDWT_CTRL.DWTCFGCTRL Position         */
#define MTBDWT_CTRL_DWTCFGCTRL(x)                (((uint32_t)(((uint32_t)(x))<<MTBDWT_CTRL_DWTCFGCTRL_SHIFT))&MTBDWT_CTRL_DWTCFGCTRL_MASK) /**< MTBDWT_CTRL.DWTCFGCTRL Field            */
#define MTBDWT_CTRL_NUMCMP_MASK                  (0xF0000000U)                                       /**< MTBDWT_CTRL.NUMCMP Mask                 */
#define MTBDWT_CTRL_NUMCMP_SHIFT                 (28U)                                               /**< MTBDWT_CTRL.NUMCMP Position             */
#define MTBDWT_CTRL_NUMCMP(x)                    (((uint32_t)(((uint32_t)(x))<<MTBDWT_CTRL_NUMCMP_SHIFT))&MTBDWT_CTRL_NUMCMP_MASK) /**< MTBDWT_CTRL.NUMCMP Field                */
/** @} */

/** @name COMP - MTB_DWT Comparator Register */ /** @{ */
#define MTBDWT_COMP_COMP_MASK                    (0xFFFFFFFFU)                                       /**< MTBDWT_COMP.COMP Mask                   */
#define MTBDWT_COMP_COMP_SHIFT                   (0U)                                                /**< MTBDWT_COMP.COMP Position               */
#define MTBDWT_COMP_COMP(x)                      (((uint32_t)(((uint32_t)(x))<<MTBDWT_COMP_COMP_SHIFT))&MTBDWT_COMP_COMP_MASK) /**< MTBDWT_COMP.COMP Field                  */
/** @} */

/** @name MASK - MTB_DWT Comparator Mask Register */ /** @{ */
#define MTBDWT_MASK_MASK_MASK                    (0x1FU)                                             /**< MTBDWT_MASK.MASK Mask                   */
#define MTBDWT_MASK_MASK_SHIFT                   (0U)                                                /**< MTBDWT_MASK.MASK Position               */
#define MTBDWT_MASK_MASK(x)                      (((uint32_t)(((uint32_t)(x))<<MTBDWT_MASK_MASK_SHIFT))&MTBDWT_MASK_MASK_MASK) /**< MTBDWT_MASK.MASK Field                  */
/** @} */

/** @name FCT - MTB_DWT Comparator Function Register 0 */ /** @{ */
#define MTBDWT_FCT_FUNCTION_MASK                 (0xFU)                                              /**< MTBDWT_FCT.FUNCTION Mask                */
#define MTBDWT_FCT_FUNCTION_SHIFT                (0U)                                                /**< MTBDWT_FCT.FUNCTION Position            */
#define MTBDWT_FCT_FUNCTION(x)                   (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_FUNCTION_SHIFT))&MTBDWT_FCT_FUNCTION_MASK) /**< MTBDWT_FCT.FUNCTION Field               */
#define MTBDWT_FCT_DATAVMATCH_MASK               (0x100U)                                            /**< MTBDWT_FCT.DATAVMATCH Mask              */
#define MTBDWT_FCT_DATAVMATCH_SHIFT              (8U)                                                /**< MTBDWT_FCT.DATAVMATCH Position          */
#define MTBDWT_FCT_DATAVMATCH(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVMATCH_SHIFT))&MTBDWT_FCT_DATAVMATCH_MASK) /**< MTBDWT_FCT.DATAVMATCH Field             */
#define MTBDWT_FCT_DATAVSIZE_MASK                (0xC00U)                                            /**< MTBDWT_FCT.DATAVSIZE Mask               */
#define MTBDWT_FCT_DATAVSIZE_SHIFT               (10U)                                               /**< MTBDWT_FCT.DATAVSIZE Position           */
#define MTBDWT_FCT_DATAVSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVSIZE_SHIFT))&MTBDWT_FCT_DATAVSIZE_MASK) /**< MTBDWT_FCT.DATAVSIZE Field              */
#define MTBDWT_FCT_DATAVADDR0_MASK               (0xF000U)                                           /**< MTBDWT_FCT.DATAVADDR0 Mask              */
#define MTBDWT_FCT_DATAVADDR0_SHIFT              (12U)                                               /**< MTBDWT_FCT.DATAVADDR0 Position          */
#define MTBDWT_FCT_DATAVADDR0(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_DATAVADDR0_SHIFT))&MTBDWT_FCT_DATAVADDR0_MASK) /**< MTBDWT_FCT.DATAVADDR0 Field             */
#define MTBDWT_FCT_MATCHED_MASK                  (0x1000000U)                                        /**< MTBDWT_FCT.MATCHED Mask                 */
#define MTBDWT_FCT_MATCHED_SHIFT                 (24U)                                               /**< MTBDWT_FCT.MATCHED Position             */
#define MTBDWT_FCT_MATCHED(x)                    (((uint32_t)(((uint32_t)(x))<<MTBDWT_FCT_MATCHED_SHIFT))&MTBDWT_FCT_MATCHED_MASK) /**< MTBDWT_FCT.MATCHED Field                */
/** @} */

/** @name TBCTRL - MTB_DWT Trace Buffer Control Register */ /** @{ */
#define MTBDWT_TBCTRL_ACOMP0_MASK                (0x1U)                                              /**< MTBDWT_TBCTRL.ACOMP0 Mask               */
#define MTBDWT_TBCTRL_ACOMP0_SHIFT               (0U)                                                /**< MTBDWT_TBCTRL.ACOMP0 Position           */
#define MTBDWT_TBCTRL_ACOMP0(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_TBCTRL_ACOMP0_SHIFT))&MTBDWT_TBCTRL_ACOMP0_MASK) /**< MTBDWT_TBCTRL.ACOMP0 Field              */
#define MTBDWT_TBCTRL_ACOMP1_MASK                (0x2U)                                              /**< MTBDWT_TBCTRL.ACOMP1 Mask               */
#define MTBDWT_TBCTRL_ACOMP1_SHIFT               (1U)                                                /**< MTBDWT_TBCTRL.ACOMP1 Position           */
#define MTBDWT_TBCTRL_ACOMP1(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_TBCTRL_ACOMP1_SHIFT))&MTBDWT_TBCTRL_ACOMP1_MASK) /**< MTBDWT_TBCTRL.ACOMP1 Field              */
#define MTBDWT_TBCTRL_NUMCOMP_MASK               (0xF0000000U)                                       /**< MTBDWT_TBCTRL.NUMCOMP Mask              */
#define MTBDWT_TBCTRL_NUMCOMP_SHIFT              (28U)                                               /**< MTBDWT_TBCTRL.NUMCOMP Position          */
#define MTBDWT_TBCTRL_NUMCOMP(x)                 (((uint32_t)(((uint32_t)(x))<<MTBDWT_TBCTRL_NUMCOMP_SHIFT))&MTBDWT_TBCTRL_NUMCOMP_MASK) /**< MTBDWT_TBCTRL.NUMCOMP Field             */
/** @} */

/** @name DEVICECFG - Device Configuration Register */ /** @{ */
#define MTBDWT_DEVICECFG_DEVICECFG_MASK          (0xFFFFFFFFU)                                       /**< MTBDWT_DEVICECFG.DEVICECFG Mask         */
#define MTBDWT_DEVICECFG_DEVICECFG_SHIFT         (0U)                                                /**< MTBDWT_DEVICECFG.DEVICECFG Position     */
#define MTBDWT_DEVICECFG_DEVICECFG(x)            (((uint32_t)(((uint32_t)(x))<<MTBDWT_DEVICECFG_DEVICECFG_SHIFT))&MTBDWT_DEVICECFG_DEVICECFG_MASK) /**< MTBDWT_DEVICECFG.DEVICECFG Field        */
/** @} */

/** @name DEVICETYPID - Device Type Identifier Register */ /** @{ */
#define MTBDWT_DEVICETYPID_DEVICETYPID_MASK      (0xFFFFFFFFU)                                       /**< MTBDWT_DEVICETYPID.DEVICETYPID Mask     */
#define MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT     (0U)                                                /**< MTBDWT_DEVICETYPID.DEVICETYPID Position */
#define MTBDWT_DEVICETYPID_DEVICETYPID(x)        (((uint32_t)(((uint32_t)(x))<<MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT))&MTBDWT_DEVICETYPID_DEVICETYPID_MASK) /**< MTBDWT_DEVICETYPID.DEVICETYPID Field    */
/** @} */

/** @name PERIPHID - Peripheral ID Register */ /** @{ */
#define MTBDWT_PERIPHID_PERIPHID_MASK            (0xFFFFFFFFU)                                       /**< MTBDWT_PERIPHID.PERIPHID Mask           */
#define MTBDWT_PERIPHID_PERIPHID_SHIFT           (0U)                                                /**< MTBDWT_PERIPHID.PERIPHID Position       */
#define MTBDWT_PERIPHID_PERIPHID(x)              (((uint32_t)(((uint32_t)(x))<<MTBDWT_PERIPHID_PERIPHID_SHIFT))&MTBDWT_PERIPHID_PERIPHID_MASK) /**< MTBDWT_PERIPHID.PERIPHID Field          */
/** @} */

/** @name COMPID - Component ID Register */ /** @{ */
#define MTBDWT_COMPID_COMPID_MASK                (0xFFFFFFFFU)                                       /**< MTBDWT_COMPID.COMPID Mask               */
#define MTBDWT_COMPID_COMPID_SHIFT               (0U)                                                /**< MTBDWT_COMPID.COMPID Position           */
#define MTBDWT_COMPID_COMPID(x)                  (((uint32_t)(((uint32_t)(x))<<MTBDWT_COMPID_COMPID_SHIFT))&MTBDWT_COMPID_COMPID_MASK) /**< MTBDWT_COMPID.COMPID Field              */
/** @} */

/** @} */ /* End group MTBDWT_Register_Masks_GROUP */


/* MTBDWT - Peripheral instance base addresses */
#define MTBDWT_BasePtr                 0xF0001000UL //!< Peripheral base address
#define MTBDWT                         ((MTBDWT_Type *) MTBDWT_BasePtr) //!< Freescale base pointer
#define MTBDWT_BASE_PTR                (MTBDWT) //!< Freescale style base pointer

/** @} */ /* End group MTBDWT_Peripheral_access_layer_GROUP */


/** @brief C Struct for NV */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           NV (file:NV_FTFA)                    ================ */
/* ================================================================================ */

/**
 * @brief Flash configuration field
 */
/**
 * @struct NV_Type
 * @brief  C Struct allowing access to NV registers
 */
typedef struct NV_Type {
   __I  uint8_t   BACKKEY3;                     /**< 0000: Backdoor Comparison Key 3                                    */
   __I  uint8_t   BACKKEY2;                     /**< 0001: Backdoor Comparison Key 2                                    */
   __I  uint8_t   BACKKEY1;                     /**< 0002: Backdoor Comparison Key 1                                    */
   __I  uint8_t   BACKKEY0;                     /**< 0003: Backdoor Comparison Key 0                                    */
   __I  uint8_t   BACKKEY7;                     /**< 0004: Backdoor Comparison Key 7                                    */
   __I  uint8_t   BACKKEY6;                     /**< 0005: Backdoor Comparison Key 6                                    */
   __I  uint8_t   BACKKEY5;                     /**< 0006: Backdoor Comparison Key 5                                    */
   __I  uint8_t   BACKKEY4;                     /**< 0007: Backdoor Comparison Key 4                                    */
   __I  uint8_t   FPROT3;                       /**< 0008: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT2;                       /**< 0009: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT1;                       /**< 000A: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT0;                       /**< 000B: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FSEC;                         /**< 000C: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /**< 000D: Non-volatile Flash Option Register                           */
} NV_Type;


/** @brief Register Masks for NV */

/* -------------------------------------------------------------------------------- */
/* -----------     'NV' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup NV_Register_Masks_GROUP NV Register Masks */
/** @{ */

/** @name BACKKEY - Backdoor Comparison Key %s */ /** @{ */
#define NV_BACKKEY_KEY_MASK                      (0xFFU)                                             /**< NV_BACKKEY.KEY Mask                     */
#define NV_BACKKEY_KEY_SHIFT                     (0U)                                                /**< NV_BACKKEY.KEY Position                 */
#define NV_BACKKEY_KEY(x)                        (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY_KEY_SHIFT))&NV_BACKKEY_KEY_MASK) /**< NV_BACKKEY.KEY Field                    */
/** @} */

/** @name FPROT - Non-volatile P-Flash Protection Register */ /** @{ */
#define NV_FPROT_PROT_MASK                       (0xFFU)                                             /**< NV_FPROT.PROT Mask                      */
#define NV_FPROT_PROT_SHIFT                      (0U)                                                /**< NV_FPROT.PROT Position                  */
#define NV_FPROT_PROT(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_PROT_SHIFT))&NV_FPROT_PROT_MASK) /**< NV_FPROT.PROT Field                     */
/** @} */

/** @name FSEC - Non-volatile Flash Security Register */ /** @{ */
#define NV_FSEC_SEC_MASK                         (0x3U)                                              /**< NV_FSEC.SEC Mask                        */
#define NV_FSEC_SEC_SHIFT                        (0U)                                                /**< NV_FSEC.SEC Position                    */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK) /**< NV_FSEC.SEC Field                       */
#define NV_FSEC_FSLACC_MASK                      (0xCU)                                              /**< NV_FSEC.FSLACC Mask                     */
#define NV_FSEC_FSLACC_SHIFT                     (2U)                                                /**< NV_FSEC.FSLACC Position                 */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK) /**< NV_FSEC.FSLACC Field                    */
#define NV_FSEC_MEEN_MASK                        (0x30U)                                             /**< NV_FSEC.MEEN Mask                       */
#define NV_FSEC_MEEN_SHIFT                       (4U)                                                /**< NV_FSEC.MEEN Position                   */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK) /**< NV_FSEC.MEEN Field                      */
#define NV_FSEC_KEYEN_MASK                       (0xC0U)                                             /**< NV_FSEC.KEYEN Mask                      */
#define NV_FSEC_KEYEN_SHIFT                      (6U)                                                /**< NV_FSEC.KEYEN Position                  */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK) /**< NV_FSEC.KEYEN Field                     */
/** @} */

/** @name FOPT - Non-volatile Flash Option Register */ /** @{ */
#define NV_FOPT_LPBOOT0_MASK                     (0x1U)                                              /**< NV_FOPT.LPBOOT0 Mask                    */
#define NV_FOPT_LPBOOT0_SHIFT                    (0U)                                                /**< NV_FOPT.LPBOOT0 Position                */
#define NV_FOPT_LPBOOT0(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_LPBOOT0_SHIFT))&NV_FOPT_LPBOOT0_MASK) /**< NV_FOPT.LPBOOT0 Field                   */
#define NV_FOPT_NMI_DIS_MASK                     (0x4U)                                              /**< NV_FOPT.NMI_DIS Mask                    */
#define NV_FOPT_NMI_DIS_SHIFT                    (2U)                                                /**< NV_FOPT.NMI_DIS Position                */
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_NMI_DIS_SHIFT))&NV_FOPT_NMI_DIS_MASK) /**< NV_FOPT.NMI_DIS Field                   */
#define NV_FOPT_RESET_PIN_CFG_MASK               (0x8U)                                              /**< NV_FOPT.RESET_PIN_CFG Mask              */
#define NV_FOPT_RESET_PIN_CFG_SHIFT              (3U)                                                /**< NV_FOPT.RESET_PIN_CFG Position          */
#define NV_FOPT_RESET_PIN_CFG(x)                 (((uint8_t)(((uint8_t)(x))<<NV_FOPT_RESET_PIN_CFG_SHIFT))&NV_FOPT_RESET_PIN_CFG_MASK) /**< NV_FOPT.RESET_PIN_CFG Field             */
#define NV_FOPT_LPBOOT1_MASK                     (0x10U)                                             /**< NV_FOPT.LPBOOT1 Mask                    */
#define NV_FOPT_LPBOOT1_SHIFT                    (4U)                                                /**< NV_FOPT.LPBOOT1 Position                */
#define NV_FOPT_LPBOOT1(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_LPBOOT1_SHIFT))&NV_FOPT_LPBOOT1_MASK) /**< NV_FOPT.LPBOOT1 Field                   */
#define NV_FOPT_FAST_INIT_MASK                   (0x20U)                                             /**< NV_FOPT.FAST_INIT Mask                  */
#define NV_FOPT_FAST_INIT_SHIFT                  (5U)                                                /**< NV_FOPT.FAST_INIT Position              */
#define NV_FOPT_FAST_INIT(x)                     (((uint8_t)(((uint8_t)(x))<<NV_FOPT_FAST_INIT_SHIFT))&NV_FOPT_FAST_INIT_MASK) /**< NV_FOPT.FAST_INIT Field                 */
/** @} */

/** @} */ /* End group NV_Register_Masks_GROUP */


/* NV - Peripheral instance base addresses */
#define NV_BasePtr                     0x00000400UL //!< Peripheral base address
#define NV                             ((NV_Type *) NV_BasePtr) //!< Freescale base pointer
#define NV_BASE_PTR                    (NV) //!< Freescale style base pointer

/** @} */ /* End group NV_Peripheral_access_layer_GROUP */


/** @brief C Struct for OSC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup OSC_Peripheral_access_layer_GROUP OSC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           OSC0 (file:OSC0_MK)                  ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */
/**
 * @struct OSC_Type
 * @brief  C Struct allowing access to OSC registers
 */
typedef struct OSC_Type {
   __IO uint8_t   CR;                           /**< 0000: Control Register                                             */
} OSC_Type;


/** @brief Register Masks for OSC */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup OSC_Register_Masks_GROUP OSC Register Masks */
/** @{ */

/** @name CR - Control Register */ /** @{ */
#define OSC_CR_SCP_MASK                          (0xFU)                                              /**< OSC0_CR.SCP Mask                        */
#define OSC_CR_SCP_SHIFT                         (0U)                                                /**< OSC0_CR.SCP Position                    */
#define OSC_CR_SCP(x)                            (((uint8_t)(((uint8_t)(x))<<OSC_CR_SCP_SHIFT))&OSC_CR_SCP_MASK) /**< OSC0_CR.SCP Field                       */
#define OSC_CR_SC16P_MASK                        (0x1U)                                              /**< OSC0_CR.SC16P Mask                      */
#define OSC_CR_SC16P_SHIFT                       (0U)                                                /**< OSC0_CR.SC16P Position                  */
#define OSC_CR_SC16P(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC16P_SHIFT))&OSC_CR_SC16P_MASK) /**< OSC0_CR.SC16P Field                     */
#define OSC_CR_SC8P_MASK                         (0x2U)                                              /**< OSC0_CR.SC8P Mask                       */
#define OSC_CR_SC8P_SHIFT                        (1U)                                                /**< OSC0_CR.SC8P Position                   */
#define OSC_CR_SC8P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC8P_SHIFT))&OSC_CR_SC8P_MASK) /**< OSC0_CR.SC8P Field                      */
#define OSC_CR_SC4P_MASK                         (0x4U)                                              /**< OSC0_CR.SC4P Mask                       */
#define OSC_CR_SC4P_SHIFT                        (2U)                                                /**< OSC0_CR.SC4P Position                   */
#define OSC_CR_SC4P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC4P_SHIFT))&OSC_CR_SC4P_MASK) /**< OSC0_CR.SC4P Field                      */
#define OSC_CR_SC2P_MASK                         (0x8U)                                              /**< OSC0_CR.SC2P Mask                       */
#define OSC_CR_SC2P_SHIFT                        (3U)                                                /**< OSC0_CR.SC2P Position                   */
#define OSC_CR_SC2P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC2P_SHIFT))&OSC_CR_SC2P_MASK) /**< OSC0_CR.SC2P Field                      */
#define OSC_CR_EREFSTEN_MASK                     (0x20U)                                             /**< OSC0_CR.EREFSTEN Mask                   */
#define OSC_CR_EREFSTEN_SHIFT                    (5U)                                                /**< OSC0_CR.EREFSTEN Position               */
#define OSC_CR_EREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<OSC_CR_EREFSTEN_SHIFT))&OSC_CR_EREFSTEN_MASK) /**< OSC0_CR.EREFSTEN Field                  */
#define OSC_CR_ERCLKEN_MASK                      (0x80U)                                             /**< OSC0_CR.ERCLKEN Mask                    */
#define OSC_CR_ERCLKEN_SHIFT                     (7U)                                                /**< OSC0_CR.ERCLKEN Position                */
#define OSC_CR_ERCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<OSC_CR_ERCLKEN_SHIFT))&OSC_CR_ERCLKEN_MASK) /**< OSC0_CR.ERCLKEN Field                   */
/** @} */

/** @} */ /* End group OSC_Register_Masks_GROUP */


/* OSC0 - Peripheral instance base addresses */
#define OSC0_BasePtr                   0x40065000UL //!< Peripheral base address
#define OSC0                           ((OSC_Type *) OSC0_BasePtr) //!< Freescale base pointer
#define OSC0_BASE_PTR                  (OSC0) //!< Freescale style base pointer

/** @} */ /* End group OSC_Peripheral_access_layer_GROUP */


/** @brief C Struct for PIT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           PIT (file:PIT_2CH_CHAIN_LTMR)        ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer (2 channels)
 */
#define PIT_TMR_COUNT        2          /**< Number of timer channels                           */
/**
 * @struct PIT_Type
 * @brief  C Struct allowing access to PIT registers
 */
typedef struct PIT_Type {
   __IO uint32_t  MCR;                          /**< 0000: Module Control Register                                      */
        uint8_t   RESERVED_0[220];              /**< 0004: 0xDC bytes                                                   */
   __I  uint32_t  LTMR64H;                      /**< 00E0: Upper Lifetime Timer Register                                */
   __I  uint32_t  LTMR64L;                      /**< 00E4: Lower Lifetime Timer Register                                */
        uint8_t   RESERVED_1[24];               /**< 00E8: 0x18 bytes                                                   */
   struct {
      __IO uint32_t  LDVAL;                     /**< 0100: Timer Load Value Register                                    */
      __I  uint32_t  CVAL;                      /**< 0104: Current Timer Value Register                                 */
      __IO uint32_t  TCTRL;                     /**< 0108: Timer Control Register                                       */
      __IO uint32_t  TFLG;                      /**< 010C: Timer Flag Register                                          */
   } CHANNEL[PIT_TMR_COUNT];                    /**< 0100: (cluster: size=0x0020, 32)                                   */
} PIT_Type;


/** @brief Register Masks for PIT */

/* -------------------------------------------------------------------------------- */
/* -----------     'PIT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup PIT_Register_Masks_GROUP PIT Register Masks */
/** @{ */

/** @name MCR - Module Control Register */ /** @{ */
#define PIT_MCR_FRZ_MASK                         (0x1U)                                              /**< PIT_MCR.FRZ Mask                        */
#define PIT_MCR_FRZ_SHIFT                        (0U)                                                /**< PIT_MCR.FRZ Position                    */
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<PIT_MCR_FRZ_SHIFT))&PIT_MCR_FRZ_MASK) /**< PIT_MCR.FRZ Field                       */
#define PIT_MCR_MDIS_MASK                        (0x2U)                                              /**< PIT_MCR.MDIS Mask                       */
#define PIT_MCR_MDIS_SHIFT                       (1U)                                                /**< PIT_MCR.MDIS Position                   */
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_MCR_MDIS_SHIFT))&PIT_MCR_MDIS_MASK) /**< PIT_MCR.MDIS Field                      */
/** @} */

/** @name LTMR64H - Upper Lifetime Timer Register */ /** @{ */
#define PIT_LTMR64H_LTH_MASK                     (0xFFFFFFFFU)                                       /**< PIT_LTMR64H.LTH Mask                    */
#define PIT_LTMR64H_LTH_SHIFT                    (0U)                                                /**< PIT_LTMR64H.LTH Position                */
#define PIT_LTMR64H_LTH(x)                       (((uint32_t)(((uint32_t)(x))<<PIT_LTMR64H_LTH_SHIFT))&PIT_LTMR64H_LTH_MASK) /**< PIT_LTMR64H.LTH Field                   */
/** @} */

/** @name LTMR64L - Lower Lifetime Timer Register */ /** @{ */
#define PIT_LTMR64L_LTL_MASK                     (0xFFFFFFFFU)                                       /**< PIT_LTMR64L.LTL Mask                    */
#define PIT_LTMR64L_LTL_SHIFT                    (0U)                                                /**< PIT_LTMR64L.LTL Position                */
#define PIT_LTMR64L_LTL(x)                       (((uint32_t)(((uint32_t)(x))<<PIT_LTMR64L_LTL_SHIFT))&PIT_LTMR64L_LTL_MASK) /**< PIT_LTMR64L.LTL Field                   */
/** @} */

/** @name LDVAL - Timer Load Value Register */ /** @{ */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)                                       /**< PIT_LDVAL.TSV Mask                      */
#define PIT_LDVAL_TSV_SHIFT                      (0U)                                                /**< PIT_LDVAL.TSV Position                  */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK) /**< PIT_LDVAL.TSV Field                     */
/** @} */

/** @name CVAL - Current Timer Value Register */ /** @{ */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)                                       /**< PIT_CVAL.TVL Mask                       */
#define PIT_CVAL_TVL_SHIFT                       (0U)                                                /**< PIT_CVAL.TVL Position                   */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK) /**< PIT_CVAL.TVL Field                      */
/** @} */

/** @name TCTRL - Timer Control Register */ /** @{ */
#define PIT_TCTRL_TEN_MASK                       (0x1U)                                              /**< PIT_TCTRL.TEN Mask                      */
#define PIT_TCTRL_TEN_SHIFT                      (0U)                                                /**< PIT_TCTRL.TEN Position                  */
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TEN_SHIFT))&PIT_TCTRL_TEN_MASK) /**< PIT_TCTRL.TEN Field                     */
#define PIT_TCTRL_TIE_MASK                       (0x2U)                                              /**< PIT_TCTRL.TIE Mask                      */
#define PIT_TCTRL_TIE_SHIFT                      (1U)                                                /**< PIT_TCTRL.TIE Position                  */
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TIE_SHIFT))&PIT_TCTRL_TIE_MASK) /**< PIT_TCTRL.TIE Field                     */
#define PIT_TCTRL_CHN_MASK                       (0x4U)                                              /**< PIT_TCTRL.CHN Mask                      */
#define PIT_TCTRL_CHN_SHIFT                      (2U)                                                /**< PIT_TCTRL.CHN Position                  */
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_CHN_SHIFT))&PIT_TCTRL_CHN_MASK) /**< PIT_TCTRL.CHN Field                     */
/** @} */

/** @name TFLG - Timer Flag Register */ /** @{ */
#define PIT_TFLG_TIF_MASK                        (0x1U)                                              /**< PIT_TFLG.TIF Mask                       */
#define PIT_TFLG_TIF_SHIFT                       (0U)                                                /**< PIT_TFLG.TIF Position                   */
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_TFLG_TIF_SHIFT))&PIT_TFLG_TIF_MASK) /**< PIT_TFLG.TIF Field                      */
/** @} */

/** @} */ /* End group PIT_Register_Masks_GROUP */


/* PIT - Peripheral instance base addresses */
#define PIT_BasePtr                    0x40037000UL //!< Peripheral base address
#define PIT                            ((PIT_Type *) PIT_BasePtr) //!< Freescale base pointer
#define PIT_BASE_PTR                   (PIT) //!< Freescale style base pointer
#define PIT_IRQS { PIT_IRQn,  }


/** @} */ /* End group PIT_Peripheral_access_layer_GROUP */


/** @brief C Struct for PMC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           PMC (file:PMC_MK)                    ================ */
/* ================================================================================ */

/**
 * @brief Power Management Controller
 */
/**
 * @struct PMC_Type
 * @brief  C Struct allowing access to PMC registers
 */
typedef struct PMC_Type {
   __IO uint8_t   LVDSC1;                       /**< 0000: Low Voltage Status and Control 1                             */
   __IO uint8_t   LVDSC2;                       /**< 0001: Low Voltage Status and Control 2                             */
   __IO uint8_t   REGSC;                        /**< 0002: Regulator Status and Control                                 */
} PMC_Type;


/** @brief Register Masks for PMC */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup PMC_Register_Masks_GROUP PMC Register Masks */
/** @{ */

/** @name LVDSC1 - Low Voltage Status and Control 1 */ /** @{ */
#define PMC_LVDSC1_LVDV_MASK                     (0x3U)                                              /**< PMC_LVDSC1.LVDV Mask                    */
#define PMC_LVDSC1_LVDV_SHIFT                    (0U)                                                /**< PMC_LVDSC1.LVDV Position                */
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK) /**< PMC_LVDSC1.LVDV Field                   */
#define PMC_LVDSC1_LVDRE_MASK                    (0x10U)                                             /**< PMC_LVDSC1.LVDRE Mask                   */
#define PMC_LVDSC1_LVDRE_SHIFT                   (4U)                                                /**< PMC_LVDSC1.LVDRE Position               */
#define PMC_LVDSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDRE_SHIFT))&PMC_LVDSC1_LVDRE_MASK) /**< PMC_LVDSC1.LVDRE Field                  */
#define PMC_LVDSC1_LVDIE_MASK                    (0x20U)                                             /**< PMC_LVDSC1.LVDIE Mask                   */
#define PMC_LVDSC1_LVDIE_SHIFT                   (5U)                                                /**< PMC_LVDSC1.LVDIE Position               */
#define PMC_LVDSC1_LVDIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDIE_SHIFT))&PMC_LVDSC1_LVDIE_MASK) /**< PMC_LVDSC1.LVDIE Field                  */
#define PMC_LVDSC1_LVDACK_MASK                   (0x40U)                                             /**< PMC_LVDSC1.LVDACK Mask                  */
#define PMC_LVDSC1_LVDACK_SHIFT                  (6U)                                                /**< PMC_LVDSC1.LVDACK Position              */
#define PMC_LVDSC1_LVDACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDACK_SHIFT))&PMC_LVDSC1_LVDACK_MASK) /**< PMC_LVDSC1.LVDACK Field                 */
#define PMC_LVDSC1_LVDF_MASK                     (0x80U)                                             /**< PMC_LVDSC1.LVDF Mask                    */
#define PMC_LVDSC1_LVDF_SHIFT                    (7U)                                                /**< PMC_LVDSC1.LVDF Position                */
#define PMC_LVDSC1_LVDF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDF_SHIFT))&PMC_LVDSC1_LVDF_MASK) /**< PMC_LVDSC1.LVDF Field                   */
/** @} */

/** @name LVDSC2 - Low Voltage Status and Control 2 */ /** @{ */
#define PMC_LVDSC2_LVWV_MASK                     (0x3U)                                              /**< PMC_LVDSC2.LVWV Mask                    */
#define PMC_LVDSC2_LVWV_SHIFT                    (0U)                                                /**< PMC_LVDSC2.LVWV Position                */
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK) /**< PMC_LVDSC2.LVWV Field                   */
#define PMC_LVDSC2_LVWIE_MASK                    (0x20U)                                             /**< PMC_LVDSC2.LVWIE Mask                   */
#define PMC_LVDSC2_LVWIE_SHIFT                   (5U)                                                /**< PMC_LVDSC2.LVWIE Position               */
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWIE_SHIFT))&PMC_LVDSC2_LVWIE_MASK) /**< PMC_LVDSC2.LVWIE Field                  */
#define PMC_LVDSC2_LVWACK_MASK                   (0x40U)                                             /**< PMC_LVDSC2.LVWACK Mask                  */
#define PMC_LVDSC2_LVWACK_SHIFT                  (6U)                                                /**< PMC_LVDSC2.LVWACK Position              */
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWACK_SHIFT))&PMC_LVDSC2_LVWACK_MASK) /**< PMC_LVDSC2.LVWACK Field                 */
#define PMC_LVDSC2_LVWF_MASK                     (0x80U)                                             /**< PMC_LVDSC2.LVWF Mask                    */
#define PMC_LVDSC2_LVWF_SHIFT                    (7U)                                                /**< PMC_LVDSC2.LVWF Position                */
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWF_SHIFT))&PMC_LVDSC2_LVWF_MASK) /**< PMC_LVDSC2.LVWF Field                   */
/** @} */

/** @name REGSC - Regulator Status and Control */ /** @{ */
#define PMC_REGSC_BGBE_MASK                      (0x1U)                                              /**< PMC_REGSC.BGBE Mask                     */
#define PMC_REGSC_BGBE_SHIFT                     (0U)                                                /**< PMC_REGSC.BGBE Position                 */
#define PMC_REGSC_BGBE(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_BGBE_SHIFT))&PMC_REGSC_BGBE_MASK) /**< PMC_REGSC.BGBE Field                    */
#define PMC_REGSC_REGONS_MASK                    (0x4U)                                              /**< PMC_REGSC.REGONS Mask                   */
#define PMC_REGSC_REGONS_SHIFT                   (2U)                                                /**< PMC_REGSC.REGONS Position               */
#define PMC_REGSC_REGONS(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_REGONS_SHIFT))&PMC_REGSC_REGONS_MASK) /**< PMC_REGSC.REGONS Field                  */
#define PMC_REGSC_ACKISO_MASK                    (0x8U)                                              /**< PMC_REGSC.ACKISO Mask                   */
#define PMC_REGSC_ACKISO_SHIFT                   (3U)                                                /**< PMC_REGSC.ACKISO Position               */
#define PMC_REGSC_ACKISO(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_ACKISO_SHIFT))&PMC_REGSC_ACKISO_MASK) /**< PMC_REGSC.ACKISO Field                  */
#define PMC_REGSC_BGEN_MASK                      (0x10U)                                             /**< PMC_REGSC.BGEN Mask                     */
#define PMC_REGSC_BGEN_SHIFT                     (4U)                                                /**< PMC_REGSC.BGEN Position                 */
#define PMC_REGSC_BGEN(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_BGEN_SHIFT))&PMC_REGSC_BGEN_MASK) /**< PMC_REGSC.BGEN Field                    */
/** @} */

/** @} */ /* End group PMC_Register_Masks_GROUP */


/* PMC - Peripheral instance base addresses */
#define PMC_BasePtr                    0x4007D000UL //!< Peripheral base address
#define PMC                            ((PMC_Type *) PMC_BasePtr) //!< Freescale base pointer
#define PMC_BASE_PTR                   (PMC) //!< Freescale style base pointer
#define PMC_IRQS { PMC_IRQn,  }


/** @} */ /* End group PMC_Peripheral_access_layer_GROUP */


/** @brief C Struct for PORT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           PORTA (file:PORTA_MKL_DMA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
/**
 * @struct PORT_Type
 * @brief  C Struct allowing access to PORT registers
 */
typedef struct PORT_Type {
   __IO uint32_t  PCR[32];                      /**< 0000: Pin Control Register                                         */
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
        uint8_t   RESERVED_0[24];               /**< 0088: 0x18 bytes                                                   */
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
} PORT_Type;


/** @brief Register Masks for PORT */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup PORT_Register_Masks_GROUP PORT Register Masks */
/** @{ */

/** @name PCR - Pin Control Register %s */ /** @{ */
#define PORT_PCR_PD_MASK                         (0x3U)                                              /**< PORTA_PCR.PD Mask                       */
#define PORT_PCR_PD_SHIFT                        (0U)                                                /**< PORTA_PCR.PD Position                   */
#define PORT_PCR_PD(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PD_SHIFT))&PORT_PCR_PD_MASK) /**< PORTA_PCR.PD Field                      */
#define PORT_PCR_PS_MASK                         (0x1U)                                              /**< PORTA_PCR.PS Mask                       */
#define PORT_PCR_PS_SHIFT                        (0U)                                                /**< PORTA_PCR.PS Position                   */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PS_SHIFT))&PORT_PCR_PS_MASK) /**< PORTA_PCR.PS Field                      */
#define PORT_PCR_PE_MASK                         (0x2U)                                              /**< PORTA_PCR.PE Mask                       */
#define PORT_PCR_PE_SHIFT                        (1U)                                                /**< PORTA_PCR.PE Position                   */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK) /**< PORTA_PCR.PE Field                      */
#define PORT_PCR_SRE_MASK                        (0x4U)                                              /**< PORTA_PCR.SRE Mask                      */
#define PORT_PCR_SRE_SHIFT                       (2U)                                                /**< PORTA_PCR.SRE Position                  */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_SRE_SHIFT))&PORT_PCR_SRE_MASK) /**< PORTA_PCR.SRE Field                     */
#define PORT_PCR_PFE_MASK                        (0x10U)                                             /**< PORTA_PCR.PFE Mask                      */
#define PORT_PCR_PFE_SHIFT                       (4U)                                                /**< PORTA_PCR.PFE Position                  */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PFE_SHIFT))&PORT_PCR_PFE_MASK) /**< PORTA_PCR.PFE Field                     */
#define PORT_PCR_DSE_MASK                        (0x40U)                                             /**< PORTA_PCR.DSE Mask                      */
#define PORT_PCR_DSE_SHIFT                       (6U)                                                /**< PORTA_PCR.DSE Position                  */
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_DSE_SHIFT))&PORT_PCR_DSE_MASK) /**< PORTA_PCR.DSE Field                     */
#define PORT_PCR_MUX_MASK                        (0x700U)                                            /**< PORTA_PCR.MUX Mask                      */
#define PORT_PCR_MUX_SHIFT                       (8U)                                                /**< PORTA_PCR.MUX Position                  */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK) /**< PORTA_PCR.MUX Field                     */
#define PORT_PCR_IRQC_MASK                       (0xF0000U)                                          /**< PORTA_PCR.IRQC Mask                     */
#define PORT_PCR_IRQC_SHIFT                      (16U)                                               /**< PORTA_PCR.IRQC Position                 */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK) /**< PORTA_PCR.IRQC Field                    */
#define PORT_PCR_ISF_MASK                        (0x1000000U)                                        /**< PORTA_PCR.ISF Mask                      */
#define PORT_PCR_ISF_SHIFT                       (24U)                                               /**< PORTA_PCR.ISF Position                  */
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK) /**< PORTA_PCR.ISF Field                     */
/** @} */

/** @name GPCLR - Global Pin Control Low Register */ /** @{ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)                                           /**< PORTA_GPCLR.GPWD Mask                   */
#define PORT_GPCLR_GPWD_SHIFT                    (0U)                                                /**< PORTA_GPCLR.GPWD Position               */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK) /**< PORTA_GPCLR.GPWD Field                  */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)                                       /**< PORTA_GPCLR.GPWE Mask                   */
#define PORT_GPCLR_GPWE_SHIFT                    (16U)                                               /**< PORTA_GPCLR.GPWE Position               */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK) /**< PORTA_GPCLR.GPWE Field                  */
/** @} */

/** @name GPCHR - Global Pin Control High Register */ /** @{ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)                                           /**< PORTA_GPCHR.GPWD Mask                   */
#define PORT_GPCHR_GPWD_SHIFT                    (0U)                                                /**< PORTA_GPCHR.GPWD Position               */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK) /**< PORTA_GPCHR.GPWD Field                  */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)                                       /**< PORTA_GPCHR.GPWE Mask                   */
#define PORT_GPCHR_GPWE_SHIFT                    (16U)                                               /**< PORTA_GPCHR.GPWE Position               */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK) /**< PORTA_GPCHR.GPWE Field                  */
/** @} */

/** @} */ /* End group PORT_Register_Masks_GROUP */


/* PORTA - Peripheral instance base addresses */
#define PORTA_BasePtr                  0x40049000UL //!< Peripheral base address
#define PORTA                          ((PORT_Type *) PORTA_BasePtr) //!< Freescale base pointer
#define PORTA_BASE_PTR                 (PORTA) //!< Freescale style base pointer
#define PORTA_IRQS { PORTA_IRQn,  }


/** @} */ /* End group PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for PORT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer */
/** @{ */

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

/** @} */ /* End group PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for PORT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           PORTC (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTC - Peripheral instance base addresses */
#define PORTC_BasePtr                  0x4004B000UL //!< Peripheral base address
#define PORTC                          ((PORT_Type *) PORTC_BasePtr) //!< Freescale base pointer
#define PORTC_BASE_PTR                 (PORTC) //!< Freescale style base pointer

/** @} */ /* End group PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for PORT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           PORTD (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTD - Peripheral instance base addresses */
#define PORTD_BasePtr                  0x4004C000UL //!< Peripheral base address
#define PORTD                          ((PORT_Type *) PORTD_BasePtr) //!< Freescale base pointer
#define PORTD_BASE_PTR                 (PORTD) //!< Freescale style base pointer
#define PORTD_IRQS { PORTD_IRQn,  }


/** @} */ /* End group PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for PORT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           PORTE (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTE - Peripheral instance base addresses */
#define PORTE_BasePtr                  0x4004D000UL //!< Peripheral base address
#define PORTE                          ((PORT_Type *) PORTE_BasePtr) //!< Freescale base pointer
#define PORTE_BASE_PTR                 (PORTE) //!< Freescale style base pointer

/** @} */ /* End group PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for RCM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           RCM (file:RCM_MKL_0x4007F000)        ================ */
/* ================================================================================ */

/**
 * @brief Reset Control Module
 */
/**
 * @struct RCM_Type
 * @brief  C Struct allowing access to RCM registers
 */
typedef struct RCM_Type {
   __I  uint8_t   SRS0;                         /**< 0000: System Reset Status Register 0                               */
   __I  uint8_t   SRS1;                         /**< 0001: System Reset Status Register 1                               */
        uint8_t   RESERVED_0[2];                /**< 0002: 0x2 bytes                                                    */
   __IO uint8_t   RPFC;                         /**< 0004: Reset Pin Filter Control Register                            */
   __IO uint8_t   RPFW;                         /**< 0005: Reset Pin Filter Width Register                              */
} RCM_Type;


/** @brief Register Masks for RCM */

/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup RCM_Register_Masks_GROUP RCM Register Masks */
/** @{ */

/** @name SRS0 - System Reset Status Register 0 */ /** @{ */
#define RCM_SRS0_WAKEUP_MASK                     (0x1U)                                              /**< RCM_SRS0.WAKEUP Mask                    */
#define RCM_SRS0_WAKEUP_SHIFT                    (0U)                                                /**< RCM_SRS0.WAKEUP Position                */
#define RCM_SRS0_WAKEUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_WAKEUP_SHIFT))&RCM_SRS0_WAKEUP_MASK) /**< RCM_SRS0.WAKEUP Field                   */
#define RCM_SRS0_LVD_MASK                        (0x2U)                                              /**< RCM_SRS0.LVD Mask                       */
#define RCM_SRS0_LVD_SHIFT                       (1U)                                                /**< RCM_SRS0.LVD Position                   */
#define RCM_SRS0_LVD(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LVD_SHIFT))&RCM_SRS0_LVD_MASK) /**< RCM_SRS0.LVD Field                      */
#define RCM_SRS0_LOC_MASK                        (0x4U)                                              /**< RCM_SRS0.LOC Mask                       */
#define RCM_SRS0_LOC_SHIFT                       (2U)                                                /**< RCM_SRS0.LOC Position                   */
#define RCM_SRS0_LOC(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LOC_SHIFT))&RCM_SRS0_LOC_MASK) /**< RCM_SRS0.LOC Field                      */
#define RCM_SRS0_LOL_MASK                        (0x8U)                                              /**< RCM_SRS0.LOL Mask                       */
#define RCM_SRS0_LOL_SHIFT                       (3U)                                                /**< RCM_SRS0.LOL Position                   */
#define RCM_SRS0_LOL(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LOL_SHIFT))&RCM_SRS0_LOL_MASK) /**< RCM_SRS0.LOL Field                      */
#define RCM_SRS0_WDOG_MASK                       (0x20U)                                             /**< RCM_SRS0.WDOG Mask                      */
#define RCM_SRS0_WDOG_SHIFT                      (5U)                                                /**< RCM_SRS0.WDOG Position                  */
#define RCM_SRS0_WDOG(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_WDOG_SHIFT))&RCM_SRS0_WDOG_MASK) /**< RCM_SRS0.WDOG Field                     */
#define RCM_SRS0_PIN_MASK                        (0x40U)                                             /**< RCM_SRS0.PIN Mask                       */
#define RCM_SRS0_PIN_SHIFT                       (6U)                                                /**< RCM_SRS0.PIN Position                   */
#define RCM_SRS0_PIN(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_PIN_SHIFT))&RCM_SRS0_PIN_MASK) /**< RCM_SRS0.PIN Field                      */
#define RCM_SRS0_POR_MASK                        (0x80U)                                             /**< RCM_SRS0.POR Mask                       */
#define RCM_SRS0_POR_SHIFT                       (7U)                                                /**< RCM_SRS0.POR Position                   */
#define RCM_SRS0_POR(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_POR_SHIFT))&RCM_SRS0_POR_MASK) /**< RCM_SRS0.POR Field                      */
/** @} */

/** @name SRS1 - System Reset Status Register 1 */ /** @{ */
#define RCM_SRS1_LOCKUP_MASK                     (0x2U)                                              /**< RCM_SRS1.LOCKUP Mask                    */
#define RCM_SRS1_LOCKUP_SHIFT                    (1U)                                                /**< RCM_SRS1.LOCKUP Position                */
#define RCM_SRS1_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_LOCKUP_SHIFT))&RCM_SRS1_LOCKUP_MASK) /**< RCM_SRS1.LOCKUP Field                   */
#define RCM_SRS1_SW_MASK                         (0x4U)                                              /**< RCM_SRS1.SW Mask                        */
#define RCM_SRS1_SW_SHIFT                        (2U)                                                /**< RCM_SRS1.SW Position                    */
#define RCM_SRS1_SW(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_SW_SHIFT))&RCM_SRS1_SW_MASK) /**< RCM_SRS1.SW Field                       */
#define RCM_SRS1_MDM_AP_MASK                     (0x8U)                                              /**< RCM_SRS1.MDM_AP Mask                    */
#define RCM_SRS1_MDM_AP_SHIFT                    (3U)                                                /**< RCM_SRS1.MDM_AP Position                */
#define RCM_SRS1_MDM_AP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_MDM_AP_SHIFT))&RCM_SRS1_MDM_AP_MASK) /**< RCM_SRS1.MDM_AP Field                   */
#define RCM_SRS1_SACKERR_MASK                    (0x20U)                                             /**< RCM_SRS1.SACKERR Mask                   */
#define RCM_SRS1_SACKERR_SHIFT                   (5U)                                                /**< RCM_SRS1.SACKERR Position               */
#define RCM_SRS1_SACKERR(x)                      (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_SACKERR_SHIFT))&RCM_SRS1_SACKERR_MASK) /**< RCM_SRS1.SACKERR Field                  */
/** @} */

/** @name RPFC - Reset Pin Filter Control Register */ /** @{ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)                                              /**< RCM_RPFC.RSTFLTSRW Mask                 */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)                                                /**< RCM_RPFC.RSTFLTSRW Position             */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK) /**< RCM_RPFC.RSTFLTSRW Field                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)                                              /**< RCM_RPFC.RSTFLTSS Mask                  */
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)                                                /**< RCM_RPFC.RSTFLTSS Position              */
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSS_SHIFT))&RCM_RPFC_RSTFLTSS_MASK) /**< RCM_RPFC.RSTFLTSS Field                 */
/** @} */

/** @name RPFW - Reset Pin Filter Width Register */ /** @{ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FU)                                             /**< RCM_RPFW.RSTFLTSEL Mask                 */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 (0U)                                                /**< RCM_RPFW.RSTFLTSEL Position             */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK) /**< RCM_RPFW.RSTFLTSEL Field                */
/** @} */

/** @} */ /* End group RCM_Register_Masks_GROUP */


/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x4007F000UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer

/** @} */ /* End group RCM_Peripheral_access_layer_GROUP */


/** @brief C Struct for ROM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup ROM_Peripheral_access_layer_GROUP ROM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           ROM (file:ROM_MKL)                   ================ */
/* ================================================================================ */

/**
 * @brief System ROM
 */
/**
 * @struct ROM_Type
 * @brief  C Struct allowing access to ROM registers
 */
typedef struct ROM_Type {
   __I  uint32_t  ENTRY[3];                     /**< 0000: Entry                                                        */
   __I  uint32_t  TABLEMARK;                    /**< 000C: End of Table Marker Register                                 */
        uint8_t   RESERVED_0[4028];             /**< 0010: 0xFBC bytes                                                  */
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


/** @brief Register Masks for ROM */

/* -------------------------------------------------------------------------------- */
/* -----------     'ROM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup ROM_Register_Masks_GROUP ROM Register Masks */
/** @{ */

/** @name ENTRY - Entry */ /** @{ */
#define ROM_ENTRY_ENTRY_MASK                     (0xFFFFFFFFU)                                       /**< ROM_ENTRY.ENTRY Mask                    */
#define ROM_ENTRY_ENTRY_SHIFT                    (0U)                                                /**< ROM_ENTRY.ENTRY Position                */
#define ROM_ENTRY_ENTRY(x)                       (((uint32_t)(((uint32_t)(x))<<ROM_ENTRY_ENTRY_SHIFT))&ROM_ENTRY_ENTRY_MASK) /**< ROM_ENTRY.ENTRY Field                   */
/** @} */

/** @name TABLEMARK - End of Table Marker Register */ /** @{ */
#define ROM_TABLEMARK_MARK_MASK                  (0xFFFFFFFFU)                                       /**< ROM_TABLEMARK.MARK Mask                 */
#define ROM_TABLEMARK_MARK_SHIFT                 (0U)                                                /**< ROM_TABLEMARK.MARK Position             */
#define ROM_TABLEMARK_MARK(x)                    (((uint32_t)(((uint32_t)(x))<<ROM_TABLEMARK_MARK_SHIFT))&ROM_TABLEMARK_MARK_MASK) /**< ROM_TABLEMARK.MARK Field                */
/** @} */

/** @name SYSACCESS - System Access Register */ /** @{ */
#define ROM_SYSACCESS_SYSACCESS_MASK             (0xFFFFFFFFU)                                       /**< ROM_SYSACCESS.SYSACCESS Mask            */
#define ROM_SYSACCESS_SYSACCESS_SHIFT            (0U)                                                /**< ROM_SYSACCESS.SYSACCESS Position        */
#define ROM_SYSACCESS_SYSACCESS(x)               (((uint32_t)(((uint32_t)(x))<<ROM_SYSACCESS_SYSACCESS_SHIFT))&ROM_SYSACCESS_SYSACCESS_MASK) /**< ROM_SYSACCESS.SYSACCESS Field           */
/** @} */

/** @name PERIPHID - Peripheral ID Register */ /** @{ */
#define ROM_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFU)                                       /**< ROM_PERIPHID.PERIPHID Mask              */
#define ROM_PERIPHID_PERIPHID_SHIFT              (0U)                                                /**< ROM_PERIPHID.PERIPHID Position          */
#define ROM_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID_PERIPHID_SHIFT))&ROM_PERIPHID_PERIPHID_MASK) /**< ROM_PERIPHID.PERIPHID Field             */
/** @} */

/** @name COMPID - Component ID Register */ /** @{ */
#define ROM_COMPID_COMPID_MASK                   (0xFFFFFFFFU)                                       /**< ROM_COMPID.COMPID Mask                  */
#define ROM_COMPID_COMPID_SHIFT                  (0U)                                                /**< ROM_COMPID.COMPID Position              */
#define ROM_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<ROM_COMPID_COMPID_SHIFT))&ROM_COMPID_COMPID_MASK) /**< ROM_COMPID.COMPID Field                 */
/** @} */

/** @} */ /* End group ROM_Register_Masks_GROUP */


/* ROM - Peripheral instance base addresses */
#define ROM_BasePtr                    0xF0002000UL //!< Peripheral base address
#define ROM                            ((ROM_Type *) ROM_BasePtr) //!< Freescale base pointer
#define ROM_BASE_PTR                   (ROM) //!< Freescale style base pointer

/** @} */ /* End group ROM_Peripheral_access_layer_GROUP */


/** @brief C Struct for RTC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           RTC (file:RTC_MKL04Z4)               ================ */
/* ================================================================================ */

/**
 * @brief Secure Real Time Clock
 */
/**
 * @struct RTC_Type
 * @brief  C Struct allowing access to RTC registers
 */
typedef struct RTC_Type {
   __IO uint32_t  TSR;                          /**< 0000: Time Seconds Register                                        */
   __IO uint32_t  TPR;                          /**< 0004: Time Prescaler Register                                      */
   __IO uint32_t  TAR;                          /**< 0008: Time Alarm Register                                          */
   __IO uint32_t  TCR;                          /**< 000C: Time Compensation Register                                   */
   __IO uint32_t  CR;                           /**< 0010: Control Register                                             */
   __IO uint32_t  SR;                           /**< 0014: Status Register                                              */
   __IO uint32_t  LR;                           /**< 0018: Lock Register                                                */
   __IO uint32_t  IER;                          /**< 001C: Interrupt Enable Register                                    */
} RTC_Type;


/** @brief Register Masks for RTC */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup RTC_Register_Masks_GROUP RTC Register Masks */
/** @{ */

/** @name TSR - Time Seconds Register */ /** @{ */
#define RTC_TSR_TSR_MASK                         (0xFFFFFFFFU)                                       /**< RTC_TSR.TSR Mask                        */
#define RTC_TSR_TSR_SHIFT                        (0U)                                                /**< RTC_TSR.TSR Position                    */
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSR_TSR_SHIFT))&RTC_TSR_TSR_MASK) /**< RTC_TSR.TSR Field                       */
/** @} */

/** @name TPR - Time Prescaler Register */ /** @{ */
#define RTC_TPR_TPR_MASK                         (0xFFFFU)                                           /**< RTC_TPR.TPR Mask                        */
#define RTC_TPR_TPR_SHIFT                        (0U)                                                /**< RTC_TPR.TPR Position                    */
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TPR_TPR_SHIFT))&RTC_TPR_TPR_MASK) /**< RTC_TPR.TPR Field                       */
/** @} */

/** @name TAR - Time Alarm Register */ /** @{ */
#define RTC_TAR_TAR_MASK                         (0xFFFFFFFFU)                                       /**< RTC_TAR.TAR Mask                        */
#define RTC_TAR_TAR_SHIFT                        (0U)                                                /**< RTC_TAR.TAR Position                    */
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TAR_TAR_SHIFT))&RTC_TAR_TAR_MASK) /**< RTC_TAR.TAR Field                       */
/** @} */

/** @name TCR - Time Compensation Register */ /** @{ */
#define RTC_TCR_TCR_MASK                         (0xFFU)                                             /**< RTC_TCR.TCR Mask                        */
#define RTC_TCR_TCR_SHIFT                        (0U)                                                /**< RTC_TCR.TCR Position                    */
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCR_SHIFT))&RTC_TCR_TCR_MASK) /**< RTC_TCR.TCR Field                       */
#define RTC_TCR_CIR_MASK                         (0xFF00U)                                           /**< RTC_TCR.CIR Mask                        */
#define RTC_TCR_CIR_SHIFT                        (8U)                                                /**< RTC_TCR.CIR Position                    */
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIR_SHIFT))&RTC_TCR_CIR_MASK) /**< RTC_TCR.CIR Field                       */
#define RTC_TCR_TCV_MASK                         (0xFF0000U)                                         /**< RTC_TCR.TCV Mask                        */
#define RTC_TCR_TCV_SHIFT                        (16U)                                               /**< RTC_TCR.TCV Position                    */
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK) /**< RTC_TCR.TCV Field                       */
#define RTC_TCR_CIC_MASK                         (0xFF000000U)                                       /**< RTC_TCR.CIC Mask                        */
#define RTC_TCR_CIC_SHIFT                        (24U)                                               /**< RTC_TCR.CIC Position                    */
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIC_SHIFT))&RTC_TCR_CIC_MASK) /**< RTC_TCR.CIC Field                       */
/** @} */

/** @name CR - Control Register */ /** @{ */
#define RTC_CR_SWR_MASK                          (0x1U)                                              /**< RTC_CR.SWR Mask                         */
#define RTC_CR_SWR_SHIFT                         (0U)                                                /**< RTC_CR.SWR Position                     */
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SWR_SHIFT))&RTC_CR_SWR_MASK) /**< RTC_CR.SWR Field                        */
#define RTC_CR_WPE_MASK                          (0x2U)                                              /**< RTC_CR.WPE Mask                         */
#define RTC_CR_WPE_SHIFT                         (1U)                                                /**< RTC_CR.WPE Position                     */
#define RTC_CR_WPE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_WPE_SHIFT))&RTC_CR_WPE_MASK) /**< RTC_CR.WPE Field                        */
#define RTC_CR_SUP_MASK                          (0x4U)                                              /**< RTC_CR.SUP Mask                         */
#define RTC_CR_SUP_SHIFT                         (2U)                                                /**< RTC_CR.SUP Position                     */
#define RTC_CR_SUP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SUP_SHIFT))&RTC_CR_SUP_MASK) /**< RTC_CR.SUP Field                        */
#define RTC_CR_UM_MASK                           (0x8U)                                              /**< RTC_CR.UM Mask                          */
#define RTC_CR_UM_SHIFT                          (3U)                                                /**< RTC_CR.UM Position                      */
#define RTC_CR_UM(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_CR_UM_SHIFT))&RTC_CR_UM_MASK) /**< RTC_CR.UM Field                         */
#define RTC_CR_OSCE_MASK                         (0x100U)                                            /**< RTC_CR.OSCE Mask                        */
#define RTC_CR_OSCE_SHIFT                        (8U)                                                /**< RTC_CR.OSCE Position                    */
#define RTC_CR_OSCE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_OSCE_SHIFT))&RTC_CR_OSCE_MASK) /**< RTC_CR.OSCE Field                       */
#define RTC_CR_CLKO_MASK                         (0x200U)                                            /**< RTC_CR.CLKO Mask                        */
#define RTC_CR_CLKO_SHIFT                        (9U)                                                /**< RTC_CR.CLKO Position                    */
#define RTC_CR_CLKO(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_CLKO_SHIFT))&RTC_CR_CLKO_MASK) /**< RTC_CR.CLKO Field                       */
#define RTC_CR_SCP_MASK                          (0x3C00U)                                           /**< RTC_CR.SCP Mask                         */
#define RTC_CR_SCP_SHIFT                         (10U)                                               /**< RTC_CR.SCP Position                     */
#define RTC_CR_SCP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SCP_SHIFT))&RTC_CR_SCP_MASK) /**< RTC_CR.SCP Field                        */
#define RTC_CR_SC16P_MASK                        (0x400U)                                            /**< RTC_CR.SC16P Mask                       */
#define RTC_CR_SC16P_SHIFT                       (10U)                                               /**< RTC_CR.SC16P Position                   */
#define RTC_CR_SC16P(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC16P_SHIFT))&RTC_CR_SC16P_MASK) /**< RTC_CR.SC16P Field                      */
#define RTC_CR_SC8P_MASK                         (0x800U)                                            /**< RTC_CR.SC8P Mask                        */
#define RTC_CR_SC8P_SHIFT                        (11U)                                               /**< RTC_CR.SC8P Position                    */
#define RTC_CR_SC8P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC8P_SHIFT))&RTC_CR_SC8P_MASK) /**< RTC_CR.SC8P Field                       */
#define RTC_CR_SC4P_MASK                         (0x1000U)                                           /**< RTC_CR.SC4P Mask                        */
#define RTC_CR_SC4P_SHIFT                        (12U)                                               /**< RTC_CR.SC4P Position                    */
#define RTC_CR_SC4P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC4P_SHIFT))&RTC_CR_SC4P_MASK) /**< RTC_CR.SC4P Field                       */
#define RTC_CR_SC2P_MASK                         (0x2000U)                                           /**< RTC_CR.SC2P Mask                        */
#define RTC_CR_SC2P_SHIFT                        (13U)                                               /**< RTC_CR.SC2P Position                    */
#define RTC_CR_SC2P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC2P_SHIFT))&RTC_CR_SC2P_MASK) /**< RTC_CR.SC2P Field                       */
/** @} */

/** @name SR - Status Register */ /** @{ */
#define RTC_SR_TIF_MASK                          (0x1U)                                              /**< RTC_SR.TIF Mask                         */
#define RTC_SR_TIF_SHIFT                         (0U)                                                /**< RTC_SR.TIF Position                     */
#define RTC_SR_TIF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TIF_SHIFT))&RTC_SR_TIF_MASK) /**< RTC_SR.TIF Field                        */
#define RTC_SR_TOF_MASK                          (0x2U)                                              /**< RTC_SR.TOF Mask                         */
#define RTC_SR_TOF_SHIFT                         (1U)                                                /**< RTC_SR.TOF Position                     */
#define RTC_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TOF_SHIFT))&RTC_SR_TOF_MASK) /**< RTC_SR.TOF Field                        */
#define RTC_SR_TAF_MASK                          (0x4U)                                              /**< RTC_SR.TAF Mask                         */
#define RTC_SR_TAF_SHIFT                         (2U)                                                /**< RTC_SR.TAF Position                     */
#define RTC_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TAF_SHIFT))&RTC_SR_TAF_MASK) /**< RTC_SR.TAF Field                        */
#define RTC_SR_TCE_MASK                          (0x10U)                                             /**< RTC_SR.TCE Mask                         */
#define RTC_SR_TCE_SHIFT                         (4U)                                                /**< RTC_SR.TCE Position                     */
#define RTC_SR_TCE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TCE_SHIFT))&RTC_SR_TCE_MASK) /**< RTC_SR.TCE Field                        */
/** @} */

/** @name LR - Lock Register */ /** @{ */
#define RTC_LR_TCL_MASK                          (0x8U)                                              /**< RTC_LR.TCL Mask                         */
#define RTC_LR_TCL_SHIFT                         (3U)                                                /**< RTC_LR.TCL Position                     */
#define RTC_LR_TCL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TCL_SHIFT))&RTC_LR_TCL_MASK) /**< RTC_LR.TCL Field                        */
#define RTC_LR_CRL_MASK                          (0x10U)                                             /**< RTC_LR.CRL Mask                         */
#define RTC_LR_CRL_SHIFT                         (4U)                                                /**< RTC_LR.CRL Position                     */
#define RTC_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_CRL_SHIFT))&RTC_LR_CRL_MASK) /**< RTC_LR.CRL Field                        */
#define RTC_LR_SRL_MASK                          (0x20U)                                             /**< RTC_LR.SRL Mask                         */
#define RTC_LR_SRL_SHIFT                         (5U)                                                /**< RTC_LR.SRL Position                     */
#define RTC_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_SRL_SHIFT))&RTC_LR_SRL_MASK) /**< RTC_LR.SRL Field                        */
#define RTC_LR_LRL_MASK                          (0x40U)                                             /**< RTC_LR.LRL Mask                         */
#define RTC_LR_LRL_SHIFT                         (6U)                                                /**< RTC_LR.LRL Position                     */
#define RTC_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_LRL_SHIFT))&RTC_LR_LRL_MASK) /**< RTC_LR.LRL Field                        */
/** @} */

/** @name IER - Interrupt Enable Register */ /** @{ */
#define RTC_IER_TIIE_MASK                        (0x1U)                                              /**< RTC_IER.TIIE Mask                       */
#define RTC_IER_TIIE_SHIFT                       (0U)                                                /**< RTC_IER.TIIE Position                   */
#define RTC_IER_TIIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TIIE_SHIFT))&RTC_IER_TIIE_MASK) /**< RTC_IER.TIIE Field                      */
#define RTC_IER_TOIE_MASK                        (0x2U)                                              /**< RTC_IER.TOIE Mask                       */
#define RTC_IER_TOIE_SHIFT                       (1U)                                                /**< RTC_IER.TOIE Position                   */
#define RTC_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TOIE_SHIFT))&RTC_IER_TOIE_MASK) /**< RTC_IER.TOIE Field                      */
#define RTC_IER_TAIE_MASK                        (0x4U)                                              /**< RTC_IER.TAIE Mask                       */
#define RTC_IER_TAIE_SHIFT                       (2U)                                                /**< RTC_IER.TAIE Position                   */
#define RTC_IER_TAIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TAIE_SHIFT))&RTC_IER_TAIE_MASK) /**< RTC_IER.TAIE Field                      */
#define RTC_IER_TSIE_MASK                        (0x10U)                                             /**< RTC_IER.TSIE Mask                       */
#define RTC_IER_TSIE_SHIFT                       (4U)                                                /**< RTC_IER.TSIE Position                   */
#define RTC_IER_TSIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TSIE_SHIFT))&RTC_IER_TSIE_MASK) /**< RTC_IER.TSIE Field                      */
#define RTC_IER_WPON_MASK                        (0x80U)                                             /**< RTC_IER.WPON Mask                       */
#define RTC_IER_WPON_SHIFT                       (7U)                                                /**< RTC_IER.WPON Position                   */
#define RTC_IER_WPON(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_WPON_SHIFT))&RTC_IER_WPON_MASK) /**< RTC_IER.WPON Field                      */
/** @} */

/** @} */ /* End group RTC_Register_Masks_GROUP */


/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x4003D000UL //!< Peripheral base address
#define RTC                            ((RTC_Type *) RTC_BasePtr) //!< Freescale base pointer
#define RTC_BASE_PTR                   (RTC) //!< Freescale style base pointer
#define RTC_IRQS { RTC_Alarm_IRQn, RTC_Seconds_IRQn,  }


/** @} */ /* End group RTC_Peripheral_access_layer_GROUP */


/** @brief C Struct for SIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SIM (file:SIM_MKL25Z4)               ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
/**
 * @struct SIM_Type
 * @brief  C Struct allowing access to SIM registers
 */
typedef struct SIM_Type {
   __IO uint32_t  SOPT1;                        /**< 0000: System Options Register 1                                    */
   __IO uint32_t  SOPT1CFG;                     /**< 0004: SOPT1 Configuration Register                                 */
        uint8_t   RESERVED_0[4092];             /**< 0008: 0xFFC bytes                                                  */
   __IO uint32_t  SOPT2;                        /**< 1004: System Options Register 2                                    */
        uint8_t   RESERVED_1[4];                /**< 1008: 0x4 bytes                                                    */
   __IO uint32_t  SOPT4;                        /**< 100C: System Options Register 4                                    */
   __IO uint32_t  SOPT5;                        /**< 1010: System Options Register 5                                    */
        uint8_t   RESERVED_2[4];                /**< 1014: 0x4 bytes                                                    */
   __IO uint32_t  SOPT7;                        /**< 1018: System Options Register 7                                    */
        uint8_t   RESERVED_3[8];                /**< 101C: 0x8 bytes                                                    */
   __I  uint32_t  SDID;                         /**< 1024: System Device Identification Register                        */
        uint8_t   RESERVED_4[12];               /**< 1028: 0xC bytes                                                    */
   __IO uint32_t  SCGC4;                        /**< 1034: System Clock Gating Control Register 4                       */
   __IO uint32_t  SCGC5;                        /**< 1038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /**< 103C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /**< 1040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /**< 1044: System Clock Divider Register 1                              */
        uint8_t   RESERVED_5[4];                /**< 1048: 0x4 bytes                                                    */
   __IO uint32_t  FCFG1;                        /**< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /**< 1050: Flash Configuration Register 2                               */
        uint8_t   RESERVED_6[4];                /**< 1054: 0x4 bytes                                                    */
   __I  uint32_t  UIDMH;                        /**< 1058: Unique Identification Register Mid-High                      */
   __I  uint32_t  UIDML;                        /**< 105C: Unique Identification Register Mid Low                       */
   __I  uint32_t  UIDL;                         /**< 1060: Unique Identification Register Low                           */
        uint8_t   RESERVED_7[156];              /**< 1064: 0x9C bytes                                                   */
   __IO uint32_t  COPC;                         /**< 1100: COP Control Register                                         */
   __O  uint32_t  SRVCOP;                       /**< 1104: Service COP Register                                         */
} SIM_Type;


/** @brief Register Masks for SIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SIM_Register_Masks_GROUP SIM Register Masks */
/** @{ */

/** @name SOPT1 - System Options Register 1 */ /** @{ */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)                                          /**< SIM_SOPT1.OSC32KSEL Mask                */
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)                                               /**< SIM_SOPT1.OSC32KSEL Position            */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK) /**< SIM_SOPT1.OSC32KSEL Field               */
#define SIM_SOPT1_USBVSTBY_MASK                  (0x20000000U)                                       /**< SIM_SOPT1.USBVSTBY Mask                 */
#define SIM_SOPT1_USBVSTBY_SHIFT                 (29U)                                               /**< SIM_SOPT1.USBVSTBY Position             */
#define SIM_SOPT1_USBVSTBY(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_USBVSTBY_SHIFT))&SIM_SOPT1_USBVSTBY_MASK) /**< SIM_SOPT1.USBVSTBY Field                */
#define SIM_SOPT1_USBSSTBY_MASK                  (0x40000000U)                                       /**< SIM_SOPT1.USBSSTBY Mask                 */
#define SIM_SOPT1_USBSSTBY_SHIFT                 (30U)                                               /**< SIM_SOPT1.USBSSTBY Position             */
#define SIM_SOPT1_USBSSTBY(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_USBSSTBY_SHIFT))&SIM_SOPT1_USBSSTBY_MASK) /**< SIM_SOPT1.USBSSTBY Field                */
#define SIM_SOPT1_USBREGEN_MASK                  (0x80000000U)                                       /**< SIM_SOPT1.USBREGEN Mask                 */
#define SIM_SOPT1_USBREGEN_SHIFT                 (31U)                                               /**< SIM_SOPT1.USBREGEN Position             */
#define SIM_SOPT1_USBREGEN(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_USBREGEN_SHIFT))&SIM_SOPT1_USBREGEN_MASK) /**< SIM_SOPT1.USBREGEN Field                */
/** @} */

/** @name SOPT1CFG - SOPT1 Configuration Register */ /** @{ */
#define SIM_SOPT1CFG_URWE_MASK                   (0x1000000U)                                        /**< SIM_SOPT1CFG.URWE Mask                  */
#define SIM_SOPT1CFG_URWE_SHIFT                  (24U)                                               /**< SIM_SOPT1CFG.URWE Position              */
#define SIM_SOPT1CFG_URWE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1CFG_URWE_SHIFT))&SIM_SOPT1CFG_URWE_MASK) /**< SIM_SOPT1CFG.URWE Field                 */
#define SIM_SOPT1CFG_UVSWE_MASK                  (0x2000000U)                                        /**< SIM_SOPT1CFG.UVSWE Mask                 */
#define SIM_SOPT1CFG_UVSWE_SHIFT                 (25U)                                               /**< SIM_SOPT1CFG.UVSWE Position             */
#define SIM_SOPT1CFG_UVSWE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1CFG_UVSWE_SHIFT))&SIM_SOPT1CFG_UVSWE_MASK) /**< SIM_SOPT1CFG.UVSWE Field                */
#define SIM_SOPT1CFG_USSWE_MASK                  (0x4000000U)                                        /**< SIM_SOPT1CFG.USSWE Mask                 */
#define SIM_SOPT1CFG_USSWE_SHIFT                 (26U)                                               /**< SIM_SOPT1CFG.USSWE Position             */
#define SIM_SOPT1CFG_USSWE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1CFG_USSWE_SHIFT))&SIM_SOPT1CFG_USSWE_MASK) /**< SIM_SOPT1CFG.USSWE Field                */
/** @} */

/** @name SOPT2 - System Options Register 2 */ /** @{ */
#define SIM_SOPT2_RTCCLKOUTSEL_MASK              (0x10U)                                             /**< SIM_SOPT2.RTCCLKOUTSEL Mask             */
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT             (4U)                                                /**< SIM_SOPT2.RTCCLKOUTSEL Position         */
#define SIM_SOPT2_RTCCLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_RTCCLKOUTSEL_SHIFT))&SIM_SOPT2_RTCCLKOUTSEL_MASK) /**< SIM_SOPT2.RTCCLKOUTSEL Field            */
#define SIM_SOPT2_CLKOUTSEL_MASK                 (0xE0U)                                             /**< SIM_SOPT2.CLKOUTSEL Mask                */
#define SIM_SOPT2_CLKOUTSEL_SHIFT                (5U)                                                /**< SIM_SOPT2.CLKOUTSEL Position            */
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_CLKOUTSEL_SHIFT))&SIM_SOPT2_CLKOUTSEL_MASK) /**< SIM_SOPT2.CLKOUTSEL Field               */
#define SIM_SOPT2_PLLFLLSEL_MASK                 (0x10000U)                                          /**< SIM_SOPT2.PLLFLLSEL Mask                */
#define SIM_SOPT2_PLLFLLSEL_SHIFT                (16U)                                               /**< SIM_SOPT2.PLLFLLSEL Position            */
#define SIM_SOPT2_PLLFLLSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_PLLFLLSEL_SHIFT))&SIM_SOPT2_PLLFLLSEL_MASK) /**< SIM_SOPT2.PLLFLLSEL Field               */
#define SIM_SOPT2_USBSRC_MASK                    (0x40000U)                                          /**< SIM_SOPT2.USBSRC Mask                   */
#define SIM_SOPT2_USBSRC_SHIFT                   (18U)                                               /**< SIM_SOPT2.USBSRC Position               */
#define SIM_SOPT2_USBSRC(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_USBSRC_SHIFT))&SIM_SOPT2_USBSRC_MASK) /**< SIM_SOPT2.USBSRC Field                  */
#define SIM_SOPT2_TPMSRC_MASK                    (0x3000000U)                                        /**< SIM_SOPT2.TPMSRC Mask                   */
#define SIM_SOPT2_TPMSRC_SHIFT                   (24U)                                               /**< SIM_SOPT2.TPMSRC Position               */
#define SIM_SOPT2_TPMSRC(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_TPMSRC_SHIFT))&SIM_SOPT2_TPMSRC_MASK) /**< SIM_SOPT2.TPMSRC Field                  */
#define SIM_SOPT2_UART0SRC_MASK                  (0xC000000U)                                        /**< SIM_SOPT2.UART0SRC Mask                 */
#define SIM_SOPT2_UART0SRC_SHIFT                 (26U)                                               /**< SIM_SOPT2.UART0SRC Position             */
#define SIM_SOPT2_UART0SRC(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_UART0SRC_SHIFT))&SIM_SOPT2_UART0SRC_MASK) /**< SIM_SOPT2.UART0SRC Field                */
/** @} */

/** @name SOPT4 - System Options Register 4 */ /** @{ */
#define SIM_SOPT4_TPM1CH0SRC_MASK                (0x40000U)                                          /**< SIM_SOPT4.TPM1CH0SRC Mask               */
#define SIM_SOPT4_TPM1CH0SRC_SHIFT               (18U)                                               /**< SIM_SOPT4.TPM1CH0SRC Position           */
#define SIM_SOPT4_TPM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM1CH0SRC_SHIFT))&SIM_SOPT4_TPM1CH0SRC_MASK) /**< SIM_SOPT4.TPM1CH0SRC Field              */
#define SIM_SOPT4_TPM2CH0SRC_MASK                (0x100000U)                                         /**< SIM_SOPT4.TPM2CH0SRC Mask               */
#define SIM_SOPT4_TPM2CH0SRC_SHIFT               (20U)                                               /**< SIM_SOPT4.TPM2CH0SRC Position           */
#define SIM_SOPT4_TPM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM2CH0SRC_SHIFT))&SIM_SOPT4_TPM2CH0SRC_MASK) /**< SIM_SOPT4.TPM2CH0SRC Field              */
#define SIM_SOPT4_TPM0CLKSEL_MASK                (0x1000000U)                                        /**< SIM_SOPT4.TPM0CLKSEL Mask               */
#define SIM_SOPT4_TPM0CLKSEL_SHIFT               (24U)                                               /**< SIM_SOPT4.TPM0CLKSEL Position           */
#define SIM_SOPT4_TPM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM0CLKSEL_SHIFT))&SIM_SOPT4_TPM0CLKSEL_MASK) /**< SIM_SOPT4.TPM0CLKSEL Field              */
#define SIM_SOPT4_TPM1CLKSEL_MASK                (0x2000000U)                                        /**< SIM_SOPT4.TPM1CLKSEL Mask               */
#define SIM_SOPT4_TPM1CLKSEL_SHIFT               (25U)                                               /**< SIM_SOPT4.TPM1CLKSEL Position           */
#define SIM_SOPT4_TPM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM1CLKSEL_SHIFT))&SIM_SOPT4_TPM1CLKSEL_MASK) /**< SIM_SOPT4.TPM1CLKSEL Field              */
#define SIM_SOPT4_TPM2CLKSEL_MASK                (0x4000000U)                                        /**< SIM_SOPT4.TPM2CLKSEL Mask               */
#define SIM_SOPT4_TPM2CLKSEL_SHIFT               (26U)                                               /**< SIM_SOPT4.TPM2CLKSEL Position           */
#define SIM_SOPT4_TPM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM2CLKSEL_SHIFT))&SIM_SOPT4_TPM2CLKSEL_MASK) /**< SIM_SOPT4.TPM2CLKSEL Field              */
/** @} */

/** @name SOPT5 - System Options Register 5 */ /** @{ */
#define SIM_SOPT5_UART0TXSRC_MASK                (0x3U)                                              /**< SIM_SOPT5.UART0TXSRC Mask               */
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)                                                /**< SIM_SOPT5.UART0TXSRC Position           */
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0TXSRC_SHIFT))&SIM_SOPT5_UART0TXSRC_MASK) /**< SIM_SOPT5.UART0TXSRC Field              */
#define SIM_SOPT5_UART0RXSRC_MASK                (0x4U)                                              /**< SIM_SOPT5.UART0RXSRC Mask               */
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)                                                /**< SIM_SOPT5.UART0RXSRC Position           */
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0RXSRC_SHIFT))&SIM_SOPT5_UART0RXSRC_MASK) /**< SIM_SOPT5.UART0RXSRC Field              */
#define SIM_SOPT5_UART1TXSRC_MASK                (0x30U)                                             /**< SIM_SOPT5.UART1TXSRC Mask               */
#define SIM_SOPT5_UART1TXSRC_SHIFT               (4U)                                                /**< SIM_SOPT5.UART1TXSRC Position           */
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1TXSRC_SHIFT))&SIM_SOPT5_UART1TXSRC_MASK) /**< SIM_SOPT5.UART1TXSRC Field              */
#define SIM_SOPT5_UART1RXSRC_MASK                (0x40U)                                             /**< SIM_SOPT5.UART1RXSRC Mask               */
#define SIM_SOPT5_UART1RXSRC_SHIFT               (6U)                                                /**< SIM_SOPT5.UART1RXSRC Position           */
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1RXSRC_SHIFT))&SIM_SOPT5_UART1RXSRC_MASK) /**< SIM_SOPT5.UART1RXSRC Field              */
#define SIM_SOPT5_UART0ODE_MASK                  (0x10000U)                                          /**< SIM_SOPT5.UART0ODE Mask                 */
#define SIM_SOPT5_UART0ODE_SHIFT                 (16U)                                               /**< SIM_SOPT5.UART0ODE Position             */
#define SIM_SOPT5_UART0ODE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0ODE_SHIFT))&SIM_SOPT5_UART0ODE_MASK) /**< SIM_SOPT5.UART0ODE Field                */
#define SIM_SOPT5_UART1ODE_MASK                  (0x20000U)                                          /**< SIM_SOPT5.UART1ODE Mask                 */
#define SIM_SOPT5_UART1ODE_SHIFT                 (17U)                                               /**< SIM_SOPT5.UART1ODE Position             */
#define SIM_SOPT5_UART1ODE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1ODE_SHIFT))&SIM_SOPT5_UART1ODE_MASK) /**< SIM_SOPT5.UART1ODE Field                */
#define SIM_SOPT5_UART2ODE_MASK                  (0x40000U)                                          /**< SIM_SOPT5.UART2ODE Mask                 */
#define SIM_SOPT5_UART2ODE_SHIFT                 (18U)                                               /**< SIM_SOPT5.UART2ODE Position             */
#define SIM_SOPT5_UART2ODE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART2ODE_SHIFT))&SIM_SOPT5_UART2ODE_MASK) /**< SIM_SOPT5.UART2ODE Field                */
/** @} */

/** @name SOPT7 - System Options Register 7 */ /** @{ */
#define SIM_SOPT7_ADC0TRGSEL_MASK                (0xFU)                                              /**< SIM_SOPT7.ADC0TRGSEL Mask               */
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               (0U)                                                /**< SIM_SOPT7.ADC0TRGSEL Position           */
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0TRGSEL_SHIFT))&SIM_SOPT7_ADC0TRGSEL_MASK) /**< SIM_SOPT7.ADC0TRGSEL Field              */
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             (0x10U)                                             /**< SIM_SOPT7.ADC0PRETRGSEL Mask            */
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            (4U)                                                /**< SIM_SOPT7.ADC0PRETRGSEL Position        */
#define SIM_SOPT7_ADC0PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0PRETRGSEL_SHIFT))&SIM_SOPT7_ADC0PRETRGSEL_MASK) /**< SIM_SOPT7.ADC0PRETRGSEL Field           */
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              (0x80U)                                             /**< SIM_SOPT7.ADC0ALTTRGEN Mask             */
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             (7U)                                                /**< SIM_SOPT7.ADC0ALTTRGEN Position         */
#define SIM_SOPT7_ADC0ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0ALTTRGEN_SHIFT))&SIM_SOPT7_ADC0ALTTRGEN_MASK) /**< SIM_SOPT7.ADC0ALTTRGEN Field            */
/** @} */

/** @name SDID - System Device Identification Register */ /** @{ */
#define SIM_SDID_PINID_MASK                      (0xFU)                                              /**< SIM_SDID.PINID Mask                     */
#define SIM_SDID_PINID_SHIFT                     (0U)                                                /**< SIM_SDID.PINID Position                 */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK) /**< SIM_SDID.PINID Field                    */
#define SIM_SDID_DIEID_MASK                      (0xF80U)                                            /**< SIM_SDID.DIEID Mask                     */
#define SIM_SDID_DIEID_SHIFT                     (7U)                                                /**< SIM_SDID.DIEID Position                 */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_DIEID_SHIFT))&SIM_SDID_DIEID_MASK) /**< SIM_SDID.DIEID Field                    */
#define SIM_SDID_REVID_MASK                      (0xF000U)                                           /**< SIM_SDID.REVID Mask                     */
#define SIM_SDID_REVID_SHIFT                     (12U)                                               /**< SIM_SDID.REVID Position                 */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK) /**< SIM_SDID.REVID Field                    */
#define SIM_SDID_SRAMSIZE_MASK                   (0xF0000U)                                          /**< SIM_SDID.SRAMSIZE Mask                  */
#define SIM_SDID_SRAMSIZE_SHIFT                  (16U)                                               /**< SIM_SDID.SRAMSIZE Position              */
#define SIM_SDID_SRAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SRAMSIZE_SHIFT))&SIM_SDID_SRAMSIZE_MASK) /**< SIM_SDID.SRAMSIZE Field                 */
#define SIM_SDID_SERIESID_MASK                   (0xF00000U)                                         /**< SIM_SDID.SERIESID Mask                  */
#define SIM_SDID_SERIESID_SHIFT                  (20U)                                               /**< SIM_SDID.SERIESID Position              */
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SERIESID_SHIFT))&SIM_SDID_SERIESID_MASK) /**< SIM_SDID.SERIESID Field                 */
#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)                                        /**< SIM_SDID.SUBFAMID Mask                  */
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)                                               /**< SIM_SDID.SUBFAMID Position              */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SDID_SUBFAMID_SHIFT))&SIM_SDID_SUBFAMID_MASK) /**< SIM_SDID.SUBFAMID Field                 */
#define SIM_SDID_FAMID_MASK                      (0xF0000000U)                                       /**< SIM_SDID.FAMID Mask                     */
#define SIM_SDID_FAMID_SHIFT                     (28U)                                               /**< SIM_SDID.FAMID Position                 */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK) /**< SIM_SDID.FAMID Field                    */
/** @} */

/** @name SCGC4 - System Clock Gating Control Register 4 */ /** @{ */
#define SIM_SCGC4_I2C0_MASK                      (0x40U)                                             /**< SIM_SCGC4.I2C0 Mask                     */
#define SIM_SCGC4_I2C0_SHIFT                     (6U)                                                /**< SIM_SCGC4.I2C0 Position                 */
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_I2C0_SHIFT))&SIM_SCGC4_I2C0_MASK) /**< SIM_SCGC4.I2C0 Field                    */
#define SIM_SCGC4_I2C1_MASK                      (0x80U)                                             /**< SIM_SCGC4.I2C1 Mask                     */
#define SIM_SCGC4_I2C1_SHIFT                     (7U)                                                /**< SIM_SCGC4.I2C1 Position                 */
#define SIM_SCGC4_I2C1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_I2C1_SHIFT))&SIM_SCGC4_I2C1_MASK) /**< SIM_SCGC4.I2C1 Field                    */
#define SIM_SCGC4_UART0_MASK                     (0x400U)                                            /**< SIM_SCGC4.UART0 Mask                    */
#define SIM_SCGC4_UART0_SHIFT                    (10U)                                               /**< SIM_SCGC4.UART0 Position                */
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART0_SHIFT))&SIM_SCGC4_UART0_MASK) /**< SIM_SCGC4.UART0 Field                   */
#define SIM_SCGC4_UART1_MASK                     (0x800U)                                            /**< SIM_SCGC4.UART1 Mask                    */
#define SIM_SCGC4_UART1_SHIFT                    (11U)                                               /**< SIM_SCGC4.UART1 Position                */
#define SIM_SCGC4_UART1(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART1_SHIFT))&SIM_SCGC4_UART1_MASK) /**< SIM_SCGC4.UART1 Field                   */
#define SIM_SCGC4_UART2_MASK                     (0x1000U)                                           /**< SIM_SCGC4.UART2 Mask                    */
#define SIM_SCGC4_UART2_SHIFT                    (12U)                                               /**< SIM_SCGC4.UART2 Position                */
#define SIM_SCGC4_UART2(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART2_SHIFT))&SIM_SCGC4_UART2_MASK) /**< SIM_SCGC4.UART2 Field                   */
#define SIM_SCGC4_USB0_MASK                      (0x40000U)                                          /**< SIM_SCGC4.USB0 Mask                     */
#define SIM_SCGC4_USB0_SHIFT                     (18U)                                               /**< SIM_SCGC4.USB0 Position                 */
#define SIM_SCGC4_USB0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_USB0_SHIFT))&SIM_SCGC4_USB0_MASK) /**< SIM_SCGC4.USB0 Field                    */
#define SIM_SCGC4_CMP0_MASK                      (0x80000U)                                          /**< SIM_SCGC4.CMP0 Mask                     */
#define SIM_SCGC4_CMP0_SHIFT                     (19U)                                               /**< SIM_SCGC4.CMP0 Position                 */
#define SIM_SCGC4_CMP0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_CMP0_SHIFT))&SIM_SCGC4_CMP0_MASK) /**< SIM_SCGC4.CMP0 Field                    */
#define SIM_SCGC4_SPI0_MASK                      (0x400000U)                                         /**< SIM_SCGC4.SPI0 Mask                     */
#define SIM_SCGC4_SPI0_SHIFT                     (22U)                                               /**< SIM_SCGC4.SPI0 Position                 */
#define SIM_SCGC4_SPI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_SPI0_SHIFT))&SIM_SCGC4_SPI0_MASK) /**< SIM_SCGC4.SPI0 Field                    */
#define SIM_SCGC4_SPI1_MASK                      (0x800000U)                                         /**< SIM_SCGC4.SPI1 Mask                     */
#define SIM_SCGC4_SPI1_SHIFT                     (23U)                                               /**< SIM_SCGC4.SPI1 Position                 */
#define SIM_SCGC4_SPI1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_SPI1_SHIFT))&SIM_SCGC4_SPI1_MASK) /**< SIM_SCGC4.SPI1 Field                    */
/** @} */

/** @name SCGC5 - System Clock Gating Control Register 5 */ /** @{ */
#define SIM_SCGC5_LPTMR0_MASK                    (0x1U)                                              /**< SIM_SCGC5.LPTMR0 Mask                   */
#define SIM_SCGC5_LPTMR0_SHIFT                   (0U)                                                /**< SIM_SCGC5.LPTMR0 Position               */
#define SIM_SCGC5_LPTMR0(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_LPTMR0_SHIFT))&SIM_SCGC5_LPTMR0_MASK) /**< SIM_SCGC5.LPTMR0 Field                  */
#define SIM_SCGC5_TSI0_MASK                      (0x20U)                                             /**< SIM_SCGC5.TSI0 Mask                     */
#define SIM_SCGC5_TSI0_SHIFT                     (5U)                                                /**< SIM_SCGC5.TSI0 Position                 */
#define SIM_SCGC5_TSI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_TSI0_SHIFT))&SIM_SCGC5_TSI0_MASK) /**< SIM_SCGC5.TSI0 Field                    */
#define SIM_SCGC5_PORTA_MASK                     (0x200U)                                            /**< SIM_SCGC5.PORTA Mask                    */
#define SIM_SCGC5_PORTA_SHIFT                    (9U)                                                /**< SIM_SCGC5.PORTA Position                */
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTA_SHIFT))&SIM_SCGC5_PORTA_MASK) /**< SIM_SCGC5.PORTA Field                   */
#define SIM_SCGC5_PORTB_MASK                     (0x400U)                                            /**< SIM_SCGC5.PORTB Mask                    */
#define SIM_SCGC5_PORTB_SHIFT                    (10U)                                               /**< SIM_SCGC5.PORTB Position                */
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTB_SHIFT))&SIM_SCGC5_PORTB_MASK) /**< SIM_SCGC5.PORTB Field                   */
#define SIM_SCGC5_PORTC_MASK                     (0x800U)                                            /**< SIM_SCGC5.PORTC Mask                    */
#define SIM_SCGC5_PORTC_SHIFT                    (11U)                                               /**< SIM_SCGC5.PORTC Position                */
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTC_SHIFT))&SIM_SCGC5_PORTC_MASK) /**< SIM_SCGC5.PORTC Field                   */
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)                                           /**< SIM_SCGC5.PORTD Mask                    */
#define SIM_SCGC5_PORTD_SHIFT                    (12U)                                               /**< SIM_SCGC5.PORTD Position                */
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTD_SHIFT))&SIM_SCGC5_PORTD_MASK) /**< SIM_SCGC5.PORTD Field                   */
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)                                           /**< SIM_SCGC5.PORTE Mask                    */
#define SIM_SCGC5_PORTE_SHIFT                    (13U)                                               /**< SIM_SCGC5.PORTE Position                */
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTE_SHIFT))&SIM_SCGC5_PORTE_MASK) /**< SIM_SCGC5.PORTE Field                   */
/** @} */

/** @name SCGC6 - System Clock Gating Control Register 6 */ /** @{ */
#define SIM_SCGC6_FTF_MASK                       (0x1U)                                              /**< SIM_SCGC6.FTF Mask                      */
#define SIM_SCGC6_FTF_SHIFT                      (0U)                                                /**< SIM_SCGC6.FTF Position                  */
#define SIM_SCGC6_FTF(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTF_SHIFT))&SIM_SCGC6_FTF_MASK) /**< SIM_SCGC6.FTF Field                     */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x2U)                                              /**< SIM_SCGC6.DMAMUX0 Mask                  */
#define SIM_SCGC6_DMAMUX0_SHIFT                  (1U)                                                /**< SIM_SCGC6.DMAMUX0 Position              */
#define SIM_SCGC6_DMAMUX0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DMAMUX0_SHIFT))&SIM_SCGC6_DMAMUX0_MASK) /**< SIM_SCGC6.DMAMUX0 Field                 */
#define SIM_SCGC6_PIT_MASK                       (0x800000U)                                         /**< SIM_SCGC6.PIT Mask                      */
#define SIM_SCGC6_PIT_SHIFT                      (23U)                                               /**< SIM_SCGC6.PIT Position                  */
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PIT_SHIFT))&SIM_SCGC6_PIT_MASK) /**< SIM_SCGC6.PIT Field                     */
#define SIM_SCGC6_TPM0_MASK                      (0x1000000U)                                        /**< SIM_SCGC6.TPM0 Mask                     */
#define SIM_SCGC6_TPM0_SHIFT                     (24U)                                               /**< SIM_SCGC6.TPM0 Position                 */
#define SIM_SCGC6_TPM0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TPM0_SHIFT))&SIM_SCGC6_TPM0_MASK) /**< SIM_SCGC6.TPM0 Field                    */
#define SIM_SCGC6_TPM1_MASK                      (0x2000000U)                                        /**< SIM_SCGC6.TPM1 Mask                     */
#define SIM_SCGC6_TPM1_SHIFT                     (25U)                                               /**< SIM_SCGC6.TPM1 Position                 */
#define SIM_SCGC6_TPM1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TPM1_SHIFT))&SIM_SCGC6_TPM1_MASK) /**< SIM_SCGC6.TPM1 Field                    */
#define SIM_SCGC6_TPM2_MASK                      (0x4000000U)                                        /**< SIM_SCGC6.TPM2 Mask                     */
#define SIM_SCGC6_TPM2_SHIFT                     (26U)                                               /**< SIM_SCGC6.TPM2 Position                 */
#define SIM_SCGC6_TPM2(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TPM2_SHIFT))&SIM_SCGC6_TPM2_MASK) /**< SIM_SCGC6.TPM2 Field                    */
#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)                                        /**< SIM_SCGC6.ADC0 Mask                     */
#define SIM_SCGC6_ADC0_SHIFT                     (27U)                                               /**< SIM_SCGC6.ADC0 Position                 */
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC0_SHIFT))&SIM_SCGC6_ADC0_MASK) /**< SIM_SCGC6.ADC0 Field                    */
#define SIM_SCGC6_RTC_MASK                       (0x20000000U)                                       /**< SIM_SCGC6.RTC Mask                      */
#define SIM_SCGC6_RTC_SHIFT                      (29U)                                               /**< SIM_SCGC6.RTC Position                  */
#define SIM_SCGC6_RTC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_RTC_SHIFT))&SIM_SCGC6_RTC_MASK) /**< SIM_SCGC6.RTC Field                     */
#define SIM_SCGC6_DAC0_MASK                      (0x80000000U)                                       /**< SIM_SCGC6.DAC0 Mask                     */
#define SIM_SCGC6_DAC0_SHIFT                     (31U)                                               /**< SIM_SCGC6.DAC0 Position                 */
#define SIM_SCGC6_DAC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DAC0_SHIFT))&SIM_SCGC6_DAC0_MASK) /**< SIM_SCGC6.DAC0 Field                    */
/** @} */

/** @name SCGC7 - System Clock Gating Control Register 7 */ /** @{ */
#define SIM_SCGC7_DMA0_MASK                      (0x100U)                                            /**< SIM_SCGC7.DMA0 Mask                     */
#define SIM_SCGC7_DMA0_SHIFT                     (8U)                                                /**< SIM_SCGC7.DMA0 Position                 */
#define SIM_SCGC7_DMA0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC7_DMA0_SHIFT))&SIM_SCGC7_DMA0_MASK) /**< SIM_SCGC7.DMA0 Field                    */
/** @} */

/** @name CLKDIV1 - System Clock Divider Register 1 */ /** @{ */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0x70000U)                                          /**< SIM_CLKDIV1.OUTDIV4 Mask                */
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)                                               /**< SIM_CLKDIV1.OUTDIV4 Position            */
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV4_SHIFT))&SIM_CLKDIV1_OUTDIV4_MASK) /**< SIM_CLKDIV1.OUTDIV4 Field               */
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)                                       /**< SIM_CLKDIV1.OUTDIV1 Mask                */
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)                                               /**< SIM_CLKDIV1.OUTDIV1 Position            */
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV1_SHIFT))&SIM_CLKDIV1_OUTDIV1_MASK) /**< SIM_CLKDIV1.OUTDIV1 Field               */
/** @} */

/** @name FCFG1 - Flash Configuration Register 1 */ /** @{ */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)                                              /**< SIM_FCFG1.FLASHDIS Mask                 */
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)                                                /**< SIM_FCFG1.FLASHDIS Position             */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDIS_SHIFT))&SIM_FCFG1_FLASHDIS_MASK) /**< SIM_FCFG1.FLASHDIS Field                */
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)                                              /**< SIM_FCFG1.FLASHDOZE Mask                */
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)                                                /**< SIM_FCFG1.FLASHDOZE Position            */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDOZE_SHIFT))&SIM_FCFG1_FLASHDOZE_MASK) /**< SIM_FCFG1.FLASHDOZE Field               */
#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)                                        /**< SIM_FCFG1.PFSIZE Mask                   */
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)                                               /**< SIM_FCFG1.PFSIZE Position               */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK) /**< SIM_FCFG1.PFSIZE Field                  */
/** @} */

/** @name FCFG2 - Flash Configuration Register 2 */ /** @{ */
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)                                       /**< SIM_FCFG2.MAXADDR0 Mask                 */
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)                                               /**< SIM_FCFG2.MAXADDR0 Position             */
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR0_SHIFT))&SIM_FCFG2_MAXADDR0_MASK) /**< SIM_FCFG2.MAXADDR0 Field                */
/** @} */

/** @name UIDMH - Unique Identification Register Mid-High */ /** @{ */
#define SIM_UIDMH_UID_MASK                       (0xFFFFU)                                           /**< SIM_UIDMH.UID Mask                      */
#define SIM_UIDMH_UID_SHIFT                      (0U)                                                /**< SIM_UIDMH.UID Position                  */
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK) /**< SIM_UIDMH.UID Field                     */
/** @} */

/** @name UIDML - Unique Identification Register Mid Low */ /** @{ */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)                                       /**< SIM_UIDML.UID Mask                      */
#define SIM_UIDML_UID_SHIFT                      (0U)                                                /**< SIM_UIDML.UID Position                  */
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK) /**< SIM_UIDML.UID Field                     */
/** @} */

/** @name UIDL - Unique Identification Register Low */ /** @{ */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)                                       /**< SIM_UIDL.UID Mask                       */
#define SIM_UIDL_UID_SHIFT                       (0U)                                                /**< SIM_UIDL.UID Position                   */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK) /**< SIM_UIDL.UID Field                      */
/** @} */

/** @name COPC - COP Control Register */ /** @{ */
#define SIM_COPC_COPW_MASK                       (0x1U)                                              /**< SIM_COPC.COPW Mask                      */
#define SIM_COPC_COPW_SHIFT                      (0U)                                                /**< SIM_COPC.COPW Position                  */
#define SIM_COPC_COPW(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPW_SHIFT))&SIM_COPC_COPW_MASK) /**< SIM_COPC.COPW Field                     */
#define SIM_COPC_COPCLKS_MASK                    (0x2U)                                              /**< SIM_COPC.COPCLKS Mask                   */
#define SIM_COPC_COPCLKS_SHIFT                   (1U)                                                /**< SIM_COPC.COPCLKS Position               */
#define SIM_COPC_COPCLKS(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPCLKS_SHIFT))&SIM_COPC_COPCLKS_MASK) /**< SIM_COPC.COPCLKS Field                  */
#define SIM_COPC_COPT_MASK                       (0xCU)                                              /**< SIM_COPC.COPT Mask                      */
#define SIM_COPC_COPT_SHIFT                      (2U)                                                /**< SIM_COPC.COPT Position                  */
#define SIM_COPC_COPT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPT_SHIFT))&SIM_COPC_COPT_MASK) /**< SIM_COPC.COPT Field                     */
/** @} */

/** @name SRVCOP - Service COP Register */ /** @{ */
#define SIM_SRVCOP_SRVCOP_MASK                   (0xFFU)                                             /**< SIM_SRVCOP.SRVCOP Mask                  */
#define SIM_SRVCOP_SRVCOP_SHIFT                  (0U)                                                /**< SIM_SRVCOP.SRVCOP Position              */
#define SIM_SRVCOP_SRVCOP(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SRVCOP_SRVCOP_SHIFT))&SIM_SRVCOP_SRVCOP_MASK) /**< SIM_SRVCOP.SRVCOP Field                 */
/** @} */

/** @} */ /* End group SIM_Register_Masks_GROUP */


/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0x40047000UL //!< Peripheral base address
#define SIM                            ((SIM_Type *) SIM_BasePtr) //!< Freescale base pointer
#define SIM_BASE_PTR                   (SIM) //!< Freescale style base pointer

/** @} */ /* End group SIM_Peripheral_access_layer_GROUP */


/** @brief C Struct for SMC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SMC_Peripheral_access_layer_GROUP SMC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SMC (file:SMC_ALLS_MKL04Z4)          ================ */
/* ================================================================================ */

/**
 * @brief System Mode Controller
 */
/**
 * @struct SMC_Type
 * @brief  C Struct allowing access to SMC registers
 */
typedef struct SMC_Type {
   __IO uint8_t   PMPROT;                       /**< 0000: Power Mode Protection Register                               */
   __IO uint8_t   PMCTRL;                       /**< 0001: Power Mode Control Register                                  */
   union {                                      /**< 0002: (size=0001)                                                  */
      __IO uint8_t   STOPCTRL;                  /**< 0002: Stop Control Register                                        */
      __IO uint8_t   VLLSCTRL;                  /**< 0002: VLLS Control Register (old name)                             */
   };
   __I  uint8_t   PMSTAT;                       /**< 0003: Power Mode Status Register                                   */
} SMC_Type;


/** @brief Register Masks for SMC */

/* -------------------------------------------------------------------------------- */
/* -----------     'SMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SMC_Register_Masks_GROUP SMC Register Masks */
/** @{ */

/** @name PMPROT - Power Mode Protection Register */ /** @{ */
#define SMC_PMPROT_AVLLS_MASK                    (0x2U)                                              /**< SMC_PMPROT.AVLLS Mask                   */
#define SMC_PMPROT_AVLLS_SHIFT                   (1U)                                                /**< SMC_PMPROT.AVLLS Position               */
#define SMC_PMPROT_AVLLS(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLLS_SHIFT))&SMC_PMPROT_AVLLS_MASK) /**< SMC_PMPROT.AVLLS Field                  */
#define SMC_PMPROT_ALLS_MASK                     (0x8U)                                              /**< SMC_PMPROT.ALLS Mask                    */
#define SMC_PMPROT_ALLS_SHIFT                    (3U)                                                /**< SMC_PMPROT.ALLS Position                */
#define SMC_PMPROT_ALLS(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_ALLS_SHIFT))&SMC_PMPROT_ALLS_MASK) /**< SMC_PMPROT.ALLS Field                   */
#define SMC_PMPROT_AVLP_MASK                     (0x20U)                                             /**< SMC_PMPROT.AVLP Mask                    */
#define SMC_PMPROT_AVLP_SHIFT                    (5U)                                                /**< SMC_PMPROT.AVLP Position                */
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLP_SHIFT))&SMC_PMPROT_AVLP_MASK) /**< SMC_PMPROT.AVLP Field                   */
/** @} */

/** @name PMCTRL - Power Mode Control Register */ /** @{ */
#define SMC_PMCTRL_STOPM_MASK                    (0x7U)                                              /**< SMC_PMCTRL.STOPM Mask                   */
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)                                                /**< SMC_PMCTRL.STOPM Position               */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK) /**< SMC_PMCTRL.STOPM Field                  */
#define SMC_PMCTRL_STOPA_MASK                    (0x8U)                                              /**< SMC_PMCTRL.STOPA Mask                   */
#define SMC_PMCTRL_STOPA_SHIFT                   (3U)                                                /**< SMC_PMCTRL.STOPA Position               */
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPA_SHIFT))&SMC_PMCTRL_STOPA_MASK) /**< SMC_PMCTRL.STOPA Field                  */
#define SMC_PMCTRL_RUNM_MASK                     (0x60U)                                             /**< SMC_PMCTRL.RUNM Mask                    */
#define SMC_PMCTRL_RUNM_SHIFT                    (5U)                                                /**< SMC_PMCTRL.RUNM Position                */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK) /**< SMC_PMCTRL.RUNM Field                   */
/** @} */

/** @name STOPCTRL - Stop Control Register */ /** @{ */
#define SMC_STOPCTRL_VLLSM_MASK                  (0x7U)                                              /**< SMC_STOPCTRL.VLLSM Mask                 */
#define SMC_STOPCTRL_VLLSM_SHIFT                 (0U)                                                /**< SMC_STOPCTRL.VLLSM Position             */
#define SMC_STOPCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_VLLSM_SHIFT))&SMC_STOPCTRL_VLLSM_MASK) /**< SMC_STOPCTRL.VLLSM Field                */
#define SMC_STOPCTRL_PORPO_MASK                  (0x20U)                                             /**< SMC_STOPCTRL.PORPO Mask                 */
#define SMC_STOPCTRL_PORPO_SHIFT                 (5U)                                                /**< SMC_STOPCTRL.PORPO Position             */
#define SMC_STOPCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PORPO_SHIFT))&SMC_STOPCTRL_PORPO_MASK) /**< SMC_STOPCTRL.PORPO Field                */
#define SMC_STOPCTRL_PSTOPO_MASK                 (0xC0U)                                             /**< SMC_STOPCTRL.PSTOPO Mask                */
#define SMC_STOPCTRL_PSTOPO_SHIFT                (6U)                                                /**< SMC_STOPCTRL.PSTOPO Position            */
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_PSTOPO_SHIFT))&SMC_STOPCTRL_PSTOPO_MASK) /**< SMC_STOPCTRL.PSTOPO Field               */
/** @} */

/** @name VLLSCTRL - VLLS Control Register (old name) */ /** @{ */
#define SMC_VLLSCTRL_VLLSM_MASK                  (0x7U)                                              /**< SMC_VLLSCTRL.VLLSM Mask                 */
#define SMC_VLLSCTRL_VLLSM_SHIFT                 (0U)                                                /**< SMC_VLLSCTRL.VLLSM Position             */
#define SMC_VLLSCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_VLLSM_SHIFT))&SMC_VLLSCTRL_VLLSM_MASK) /**< SMC_VLLSCTRL.VLLSM Field                */
#define SMC_VLLSCTRL_PORPO_MASK                  (0x20U)                                             /**< SMC_VLLSCTRL.PORPO Mask                 */
#define SMC_VLLSCTRL_PORPO_SHIFT                 (5U)                                                /**< SMC_VLLSCTRL.PORPO Position             */
#define SMC_VLLSCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_PORPO_SHIFT))&SMC_VLLSCTRL_PORPO_MASK) /**< SMC_VLLSCTRL.PORPO Field                */
#define SMC_VLLSCTRL_PSTOPO_MASK                 (0xC0U)                                             /**< SMC_VLLSCTRL.PSTOPO Mask                */
#define SMC_VLLSCTRL_PSTOPO_SHIFT                (6U)                                                /**< SMC_VLLSCTRL.PSTOPO Position            */
#define SMC_VLLSCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_PSTOPO_SHIFT))&SMC_VLLSCTRL_PSTOPO_MASK) /**< SMC_VLLSCTRL.PSTOPO Field               */
/** @} */

/** @name PMSTAT - Power Mode Status Register */ /** @{ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0xFFU)                                             /**< SMC_PMSTAT.PMSTAT Mask                  */
#define SMC_PMSTAT_PMSTAT_SHIFT                  (0U)                                                /**< SMC_PMSTAT.PMSTAT Position              */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK) /**< SMC_PMSTAT.PMSTAT Field                 */
/** @} */

/** @} */ /* End group SMC_Register_Masks_GROUP */


/* SMC - Peripheral instance base addresses */
#define SMC_BasePtr                    0x4007E000UL //!< Peripheral base address
#define SMC                            ((SMC_Type *) SMC_BasePtr) //!< Freescale base pointer
#define SMC_BASE_PTR                   (SMC) //!< Freescale style base pointer

/** @} */ /* End group SMC_Peripheral_access_layer_GROUP */


/** @brief C Struct for SPI */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SPI0 (file:SPI0_MKL04Z4_DMA)         ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
/**
 * @struct SPI_Type
 * @brief  C Struct allowing access to SPI registers
 */
typedef struct SPI_Type {
   __IO uint8_t   C1;                           /**< 0000: Control register 1                                           */
   __IO uint8_t   C2;                           /**< 0001: Control register 2                                           */
   __IO uint8_t   BR;                           /**< 0002: Baud rate register                                           */
   __I  uint8_t   S;                            /**< 0003: Status register                                              */
        uint8_t   RESERVED_0;                   /**< 0004: 0x1 bytes                                                    */
   __IO uint8_t   D;                            /**< 0005: Data register                                                */
        uint8_t   RESERVED_1;                   /**< 0006: 0x1 bytes                                                    */
   __IO uint8_t   M;                            /**< 0007: Match register:                                              */
} SPI_Type;


/** @brief Register Masks for SPI */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SPI_Register_Masks_GROUP SPI Register Masks */
/** @{ */

/** @name C1 - Control register 1 */ /** @{ */
#define SPI_C1_LSBFE_MASK                        (0x1U)                                              /**< SPI0_C1.LSBFE Mask                      */
#define SPI_C1_LSBFE_SHIFT                       (0U)                                                /**< SPI0_C1.LSBFE Position                  */
#define SPI_C1_LSBFE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C1_LSBFE_SHIFT))&SPI_C1_LSBFE_MASK) /**< SPI0_C1.LSBFE Field                     */
#define SPI_C1_SSOE_MASK                         (0x2U)                                              /**< SPI0_C1.SSOE Mask                       */
#define SPI_C1_SSOE_SHIFT                        (1U)                                                /**< SPI0_C1.SSOE Position                   */
#define SPI_C1_SSOE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_SSOE_SHIFT))&SPI_C1_SSOE_MASK) /**< SPI0_C1.SSOE Field                      */
#define SPI_C1_MODE_MASK                         (0xCU)                                              /**< SPI0_C1.MODE Mask                       */
#define SPI_C1_MODE_SHIFT                        (2U)                                                /**< SPI0_C1.MODE Position                   */
#define SPI_C1_MODE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_MODE_SHIFT))&SPI_C1_MODE_MASK) /**< SPI0_C1.MODE Field                      */
#define SPI_C1_CPHA_MASK                         (0x4U)                                              /**< SPI0_C1.CPHA Mask                       */
#define SPI_C1_CPHA_SHIFT                        (2U)                                                /**< SPI0_C1.CPHA Position                   */
#define SPI_C1_CPHA(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_CPHA_SHIFT))&SPI_C1_CPHA_MASK) /**< SPI0_C1.CPHA Field                      */
#define SPI_C1_CPOL_MASK                         (0x8U)                                              /**< SPI0_C1.CPOL Mask                       */
#define SPI_C1_CPOL_SHIFT                        (3U)                                                /**< SPI0_C1.CPOL Position                   */
#define SPI_C1_CPOL(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_CPOL_SHIFT))&SPI_C1_CPOL_MASK) /**< SPI0_C1.CPOL Field                      */
#define SPI_C1_MSTR_MASK                         (0x10U)                                             /**< SPI0_C1.MSTR Mask                       */
#define SPI_C1_MSTR_SHIFT                        (4U)                                                /**< SPI0_C1.MSTR Position                   */
#define SPI_C1_MSTR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_MSTR_SHIFT))&SPI_C1_MSTR_MASK) /**< SPI0_C1.MSTR Field                      */
#define SPI_C1_SPTIE_MASK                        (0x20U)                                             /**< SPI0_C1.SPTIE Mask                      */
#define SPI_C1_SPTIE_SHIFT                       (5U)                                                /**< SPI0_C1.SPTIE Position                  */
#define SPI_C1_SPTIE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPTIE_SHIFT))&SPI_C1_SPTIE_MASK) /**< SPI0_C1.SPTIE Field                     */
#define SPI_C1_SPE_MASK                          (0x40U)                                             /**< SPI0_C1.SPE Mask                        */
#define SPI_C1_SPE_SHIFT                         (6U)                                                /**< SPI0_C1.SPE Position                    */
#define SPI_C1_SPE(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPE_SHIFT))&SPI_C1_SPE_MASK) /**< SPI0_C1.SPE Field                       */
#define SPI_C1_SPIE_MASK                         (0x80U)                                             /**< SPI0_C1.SPIE Mask                       */
#define SPI_C1_SPIE_SHIFT                        (7U)                                                /**< SPI0_C1.SPIE Position                   */
#define SPI_C1_SPIE(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C1_SPIE_SHIFT))&SPI_C1_SPIE_MASK) /**< SPI0_C1.SPIE Field                      */
/** @} */

/** @name C2 - Control register 2 */ /** @{ */
#define SPI_C2_SPC0_MASK                         (0x1U)                                              /**< SPI0_C2.SPC0 Mask                       */
#define SPI_C2_SPC0_SHIFT                        (0U)                                                /**< SPI0_C2.SPC0 Position                   */
#define SPI_C2_SPC0(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPC0_SHIFT))&SPI_C2_SPC0_MASK) /**< SPI0_C2.SPC0 Field                      */
#define SPI_C2_SPISWAI_MASK                      (0x2U)                                              /**< SPI0_C2.SPISWAI Mask                    */
#define SPI_C2_SPISWAI_SHIFT                     (1U)                                                /**< SPI0_C2.SPISWAI Position                */
#define SPI_C2_SPISWAI(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPISWAI_SHIFT))&SPI_C2_SPISWAI_MASK) /**< SPI0_C2.SPISWAI Field                   */
#define SPI_C2_RXDMAE_MASK                       (0x4U)                                              /**< SPI0_C2.RXDMAE Mask                     */
#define SPI_C2_RXDMAE_SHIFT                      (2U)                                                /**< SPI0_C2.RXDMAE Position                 */
#define SPI_C2_RXDMAE(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_RXDMAE_SHIFT))&SPI_C2_RXDMAE_MASK) /**< SPI0_C2.RXDMAE Field                    */
#define SPI_C2_BIDIROE_MASK                      (0x8U)                                              /**< SPI0_C2.BIDIROE Mask                    */
#define SPI_C2_BIDIROE_SHIFT                     (3U)                                                /**< SPI0_C2.BIDIROE Position                */
#define SPI_C2_BIDIROE(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_BIDIROE_SHIFT))&SPI_C2_BIDIROE_MASK) /**< SPI0_C2.BIDIROE Field                   */
#define SPI_C2_MODFEN_MASK                       (0x10U)                                             /**< SPI0_C2.MODFEN Mask                     */
#define SPI_C2_MODFEN_SHIFT                      (4U)                                                /**< SPI0_C2.MODFEN Position                 */
#define SPI_C2_MODFEN(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_MODFEN_SHIFT))&SPI_C2_MODFEN_MASK) /**< SPI0_C2.MODFEN Field                    */
#define SPI_C2_TXDMAE_MASK                       (0x20U)                                             /**< SPI0_C2.TXDMAE Mask                     */
#define SPI_C2_TXDMAE_SHIFT                      (5U)                                                /**< SPI0_C2.TXDMAE Position                 */
#define SPI_C2_TXDMAE(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_TXDMAE_SHIFT))&SPI_C2_TXDMAE_MASK) /**< SPI0_C2.TXDMAE Field                    */
#define SPI_C2_SPMIE_MASK                        (0x80U)                                             /**< SPI0_C2.SPMIE Mask                      */
#define SPI_C2_SPMIE_SHIFT                       (7U)                                                /**< SPI0_C2.SPMIE Position                  */
#define SPI_C2_SPMIE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPMIE_SHIFT))&SPI_C2_SPMIE_MASK) /**< SPI0_C2.SPMIE Field                     */
/** @} */

/** @name BR - Baud rate register */ /** @{ */
#define SPI_BR_SPR_MASK                          (0xFU)                                              /**< SPI0_BR.SPR Mask                        */
#define SPI_BR_SPR_SHIFT                         (0U)                                                /**< SPI0_BR.SPR Position                    */
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK) /**< SPI0_BR.SPR Field                       */
#define SPI_BR_SPPR_MASK                         (0x70U)                                             /**< SPI0_BR.SPPR Mask                       */
#define SPI_BR_SPPR_SHIFT                        (4U)                                                /**< SPI0_BR.SPPR Position                   */
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK) /**< SPI0_BR.SPPR Field                      */
/** @} */

/** @name S - Status register */ /** @{ */
#define SPI_S_MODF_MASK                          (0x10U)                                             /**< SPI0_S.MODF Mask                        */
#define SPI_S_MODF_SHIFT                         (4U)                                                /**< SPI0_S.MODF Position                    */
#define SPI_S_MODF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_MODF_SHIFT))&SPI_S_MODF_MASK) /**< SPI0_S.MODF Field                       */
#define SPI_S_SPTEF_MASK                         (0x20U)                                             /**< SPI0_S.SPTEF Mask                       */
#define SPI_S_SPTEF_SHIFT                        (5U)                                                /**< SPI0_S.SPTEF Position                   */
#define SPI_S_SPTEF(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_S_SPTEF_SHIFT))&SPI_S_SPTEF_MASK) /**< SPI0_S.SPTEF Field                      */
#define SPI_S_SPMF_MASK                          (0x40U)                                             /**< SPI0_S.SPMF Mask                        */
#define SPI_S_SPMF_SHIFT                         (6U)                                                /**< SPI0_S.SPMF Position                    */
#define SPI_S_SPMF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_SPMF_SHIFT))&SPI_S_SPMF_MASK) /**< SPI0_S.SPMF Field                       */
#define SPI_S_SPRF_MASK                          (0x80U)                                             /**< SPI0_S.SPRF Mask                        */
#define SPI_S_SPRF_SHIFT                         (7U)                                                /**< SPI0_S.SPRF Position                    */
#define SPI_S_SPRF(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_S_SPRF_SHIFT))&SPI_S_SPRF_MASK) /**< SPI0_S.SPRF Field                       */
/** @} */

/** @name D - Data register */ /** @{ */
#define SPI_D_Bits_MASK                          (0xFFU)                                             /**< SPI0_D.Bits Mask                        */
#define SPI_D_Bits_SHIFT                         (0U)                                                /**< SPI0_D.Bits Position                    */
#define SPI_D_Bits(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_D_Bits_SHIFT))&SPI_D_Bits_MASK) /**< SPI0_D.Bits Field                       */
/** @} */

/** @name M - Match register: */ /** @{ */
#define SPI_M_Bits_MASK                          (0xFFU)                                             /**< SPI0_M.Bits Mask                        */
#define SPI_M_Bits_SHIFT                         (0U)                                                /**< SPI0_M.Bits Position                    */
#define SPI_M_Bits(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_M_Bits_SHIFT))&SPI_M_Bits_MASK) /**< SPI0_M.Bits Field                       */
/** @} */

/** @} */ /* End group SPI_Register_Masks_GROUP */


/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0x40076000UL //!< Peripheral base address
#define SPI0                           ((SPI_Type *) SPI0_BasePtr) //!< Freescale base pointer
#define SPI0_BASE_PTR                  (SPI0) //!< Freescale style base pointer
#define SPI0_IRQS { SPI0_IRQn,  }


/** @} */ /* End group SPI_Peripheral_access_layer_GROUP */


/** @brief C Struct for SPI */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer */
/** @{ */

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
#define SPI1_IRQS { SPI1_IRQn,  }


/** @} */ /* End group SPI_Peripheral_access_layer_GROUP */


/** @brief C Struct for SYST */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SYST_Peripheral_access_layer_GROUP SYST Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SYST (file:SYST)                     ================ */
/* ================================================================================ */

/**
 * @brief System timer
 */
/**
 * @struct SYST_Type
 * @brief  C Struct allowing access to SYST registers
 */
typedef struct SYST_Type {
   __IO uint32_t  CSR;                          /**< 0000: Control and Status Register                                  */
   __IO uint32_t  RVR;                          /**< 0004: Reload Value Register                                        */
   __IO uint32_t  CVR;                          /**< 0008: Current Value Register                                       */
   __I  uint32_t  CALIB;                        /**< 000C: Calibration Value Register                                   */
} SYST_Type;


/** @brief Register Masks for SYST */

/* -------------------------------------------------------------------------------- */
/* -----------     'SYST' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SYST_Register_Masks_GROUP SYST Register Masks */
/** @{ */

/** @name CSR - Control and Status Register */ /** @{ */
#define SYST_CSR_ENABLE_MASK                     (0x1U)                                              /**< SYST_CSR.ENABLE Mask                    */
#define SYST_CSR_ENABLE_SHIFT                    (0U)                                                /**< SYST_CSR.ENABLE Position                */
#define SYST_CSR_ENABLE(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_CSR_ENABLE_SHIFT))&SYST_CSR_ENABLE_MASK) /**< SYST_CSR.ENABLE Field                   */
#define SYST_CSR_TICKINT_MASK                    (0x2U)                                              /**< SYST_CSR.TICKINT Mask                   */
#define SYST_CSR_TICKINT_SHIFT                   (1U)                                                /**< SYST_CSR.TICKINT Position               */
#define SYST_CSR_TICKINT(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CSR_TICKINT_SHIFT))&SYST_CSR_TICKINT_MASK) /**< SYST_CSR.TICKINT Field                  */
#define SYST_CSR_CLKSOURCE_MASK                  (0x4U)                                              /**< SYST_CSR.CLKSOURCE Mask                 */
#define SYST_CSR_CLKSOURCE_SHIFT                 (2U)                                                /**< SYST_CSR.CLKSOURCE Position             */
#define SYST_CSR_CLKSOURCE(x)                    (((uint32_t)(((uint32_t)(x))<<SYST_CSR_CLKSOURCE_SHIFT))&SYST_CSR_CLKSOURCE_MASK) /**< SYST_CSR.CLKSOURCE Field                */
#define SYST_CSR_COUNTFLAG_MASK                  (0x10000U)                                          /**< SYST_CSR.COUNTFLAG Mask                 */
#define SYST_CSR_COUNTFLAG_SHIFT                 (16U)                                               /**< SYST_CSR.COUNTFLAG Position             */
#define SYST_CSR_COUNTFLAG(x)                    (((uint32_t)(((uint32_t)(x))<<SYST_CSR_COUNTFLAG_SHIFT))&SYST_CSR_COUNTFLAG_MASK) /**< SYST_CSR.COUNTFLAG Field                */
/** @} */

/** @name RVR - Reload Value Register */ /** @{ */
#define SYST_RVR_RELOAD_MASK                     (0xFFFFFFU)                                         /**< SYST_RVR.RELOAD Mask                    */
#define SYST_RVR_RELOAD_SHIFT                    (0U)                                                /**< SYST_RVR.RELOAD Position                */
#define SYST_RVR_RELOAD(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_RVR_RELOAD_SHIFT))&SYST_RVR_RELOAD_MASK) /**< SYST_RVR.RELOAD Field                   */
/** @} */

/** @name CVR - Current Value Register */ /** @{ */
#define SYST_CVR_CURRENT_MASK                    (0xFFFFFFU)                                         /**< SYST_CVR.CURRENT Mask                   */
#define SYST_CVR_CURRENT_SHIFT                   (0U)                                                /**< SYST_CVR.CURRENT Position               */
#define SYST_CVR_CURRENT(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CVR_CURRENT_SHIFT))&SYST_CVR_CURRENT_MASK) /**< SYST_CVR.CURRENT Field                  */
/** @} */

/** @name CALIB - Calibration Value Register */ /** @{ */
#define SYST_CALIB_TENMS_MASK                    (0xFFFFFFU)                                         /**< SYST_CALIB.TENMS Mask                   */
#define SYST_CALIB_TENMS_SHIFT                   (0U)                                                /**< SYST_CALIB.TENMS Position               */
#define SYST_CALIB_TENMS(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_TENMS_SHIFT))&SYST_CALIB_TENMS_MASK) /**< SYST_CALIB.TENMS Field                  */
#define SYST_CALIB_SKEW_MASK                     (0x40000000U)                                       /**< SYST_CALIB.SKEW Mask                    */
#define SYST_CALIB_SKEW_SHIFT                    (30U)                                               /**< SYST_CALIB.SKEW Position                */
#define SYST_CALIB_SKEW(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_SKEW_SHIFT))&SYST_CALIB_SKEW_MASK) /**< SYST_CALIB.SKEW Field                   */
#define SYST_CALIB_NOREF_MASK                    (0x80000000U)                                       /**< SYST_CALIB.NOREF Mask                   */
#define SYST_CALIB_NOREF_SHIFT                   (31U)                                               /**< SYST_CALIB.NOREF Position               */
#define SYST_CALIB_NOREF(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_NOREF_SHIFT))&SYST_CALIB_NOREF_MASK) /**< SYST_CALIB.NOREF Field                  */
/** @} */

/** @} */ /* End group SYST_Register_Masks_GROUP */


/* SYST - Peripheral instance base addresses */
#define SYST_BasePtr                   0xE000E010UL //!< Peripheral base address
#define SYST                           ((SYST_Type *) SYST_BasePtr) //!< Freescale base pointer
#define SYST_BASE_PTR                  (SYST) //!< Freescale style base pointer

/** @} */ /* End group SYST_Peripheral_access_layer_GROUP */


/** @brief C Struct for TPM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TPM0 (file:TPM0_6CH)                 ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module (6 channels)
 */
#define TPM_CONTROLS_COUNT   6          /**< Number of FTM channels                             */
/**
 * @struct TPM_Type
 * @brief  C Struct allowing access to TPM registers
 */
typedef struct TPM_Type {
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[TPM_CONTROLS_COUNT];              /**< 000C: (cluster: size=0x0030, 48)                                   */
        uint8_t   RESERVED_1[20];               /**< 003C: 0x14 bytes                                                   */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
        uint8_t   RESERVED_2[48];               /**< 0054: 0x30 bytes                                                   */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
} TPM_Type;


/** @brief Register Masks for TPM */

/* -------------------------------------------------------------------------------- */
/* -----------     'TPM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TPM_Register_Masks_GROUP TPM Register Masks */
/** @{ */

/** @name SC - Status and Control */ /** @{ */
#define TPM_SC_PS_MASK                           (0x7U)                                              /**< TPM0_SC.PS Mask                         */
#define TPM_SC_PS_SHIFT                          (0U)                                                /**< TPM0_SC.PS Position                     */
#define TPM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<TPM_SC_PS_SHIFT))&TPM_SC_PS_MASK) /**< TPM0_SC.PS Field                        */
#define TPM_SC_CMOD_MASK                         (0x18U)                                             /**< TPM0_SC.CMOD Mask                       */
#define TPM_SC_CMOD_SHIFT                        (3U)                                                /**< TPM0_SC.CMOD Position                   */
#define TPM_SC_CMOD(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_SC_CMOD_SHIFT))&TPM_SC_CMOD_MASK) /**< TPM0_SC.CMOD Field                      */
#define TPM_SC_CPWMS_MASK                        (0x20U)                                             /**< TPM0_SC.CPWMS Mask                      */
#define TPM_SC_CPWMS_SHIFT                       (5U)                                                /**< TPM0_SC.CPWMS Position                  */
#define TPM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_SC_CPWMS_SHIFT))&TPM_SC_CPWMS_MASK) /**< TPM0_SC.CPWMS Field                     */
#define TPM_SC_TOIE_MASK                         (0x40U)                                             /**< TPM0_SC.TOIE Mask                       */
#define TPM_SC_TOIE_SHIFT                        (6U)                                                /**< TPM0_SC.TOIE Position                   */
#define TPM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_SC_TOIE_SHIFT))&TPM_SC_TOIE_MASK) /**< TPM0_SC.TOIE Field                      */
#define TPM_SC_TOF_MASK                          (0x80U)                                             /**< TPM0_SC.TOF Mask                        */
#define TPM_SC_TOF_SHIFT                         (7U)                                                /**< TPM0_SC.TOF Position                    */
#define TPM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<TPM_SC_TOF_SHIFT))&TPM_SC_TOF_MASK) /**< TPM0_SC.TOF Field                       */
#define TPM_SC_DMA_MASK                          (0x100U)                                            /**< TPM0_SC.DMA Mask                        */
#define TPM_SC_DMA_SHIFT                         (8U)                                                /**< TPM0_SC.DMA Position                    */
#define TPM_SC_DMA(x)                            (((uint32_t)(((uint32_t)(x))<<TPM_SC_DMA_SHIFT))&TPM_SC_DMA_MASK) /**< TPM0_SC.DMA Field                       */
/** @} */

/** @name CNT - Counter */ /** @{ */
#define TPM_CNT_COUNT_MASK                       (0xFFFFU)                                           /**< TPM0_CNT.COUNT Mask                     */
#define TPM_CNT_COUNT_SHIFT                      (0U)                                                /**< TPM0_CNT.COUNT Position                 */
#define TPM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CNT_COUNT_SHIFT))&TPM_CNT_COUNT_MASK) /**< TPM0_CNT.COUNT Field                    */
/** @} */

/** @name MOD - Modulo */ /** @{ */
#define TPM_MOD_MOD_MASK                         (0xFFFFU)                                           /**< TPM0_MOD.MOD Mask                       */
#define TPM_MOD_MOD_SHIFT                        (0U)                                                /**< TPM0_MOD.MOD Position                   */
#define TPM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_MOD_MOD_SHIFT))&TPM_MOD_MOD_MASK) /**< TPM0_MOD.MOD Field                      */
/** @} */

/** @name CnSC - Channel %s Status and Control */ /** @{ */
#define TPM_CnSC_DMA_MASK                        (0x1U)                                              /**< TPM0_CnSC.DMA Mask                      */
#define TPM_CnSC_DMA_SHIFT                       (0U)                                                /**< TPM0_CnSC.DMA Position                  */
#define TPM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_DMA_SHIFT))&TPM_CnSC_DMA_MASK) /**< TPM0_CnSC.DMA Field                     */
#define TPM_CnSC_ELS_MASK                        (0xCU)                                              /**< TPM0_CnSC.ELS Mask                      */
#define TPM_CnSC_ELS_SHIFT                       (2U)                                                /**< TPM0_CnSC.ELS Position                  */
#define TPM_CnSC_ELS(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_ELS_SHIFT))&TPM_CnSC_ELS_MASK) /**< TPM0_CnSC.ELS Field                     */
#define TPM_CnSC_ELSA_MASK                       (0x4U)                                              /**< TPM0_CnSC.ELSA Mask                     */
#define TPM_CnSC_ELSA_SHIFT                      (2U)                                                /**< TPM0_CnSC.ELSA Position                 */
#define TPM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_ELSA_SHIFT))&TPM_CnSC_ELSA_MASK) /**< TPM0_CnSC.ELSA Field                    */
#define TPM_CnSC_ELSB_MASK                       (0x8U)                                              /**< TPM0_CnSC.ELSB Mask                     */
#define TPM_CnSC_ELSB_SHIFT                      (3U)                                                /**< TPM0_CnSC.ELSB Position                 */
#define TPM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_ELSB_SHIFT))&TPM_CnSC_ELSB_MASK) /**< TPM0_CnSC.ELSB Field                    */
#define TPM_CnSC_MS_MASK                         (0x30U)                                             /**< TPM0_CnSC.MS Mask                       */
#define TPM_CnSC_MS_SHIFT                        (4U)                                                /**< TPM0_CnSC.MS Position                   */
#define TPM_CnSC_MS(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_MS_SHIFT))&TPM_CnSC_MS_MASK) /**< TPM0_CnSC.MS Field                      */
#define TPM_CnSC_MSA_MASK                        (0x10U)                                             /**< TPM0_CnSC.MSA Mask                      */
#define TPM_CnSC_MSA_SHIFT                       (4U)                                                /**< TPM0_CnSC.MSA Position                  */
#define TPM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_MSA_SHIFT))&TPM_CnSC_MSA_MASK) /**< TPM0_CnSC.MSA Field                     */
#define TPM_CnSC_MSB_MASK                        (0x20U)                                             /**< TPM0_CnSC.MSB Mask                      */
#define TPM_CnSC_MSB_SHIFT                       (5U)                                                /**< TPM0_CnSC.MSB Position                  */
#define TPM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_MSB_SHIFT))&TPM_CnSC_MSB_MASK) /**< TPM0_CnSC.MSB Field                     */
#define TPM_CnSC_CHIE_MASK                       (0x40U)                                             /**< TPM0_CnSC.CHIE Mask                     */
#define TPM_CnSC_CHIE_SHIFT                      (6U)                                                /**< TPM0_CnSC.CHIE Position                 */
#define TPM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_CHIE_SHIFT))&TPM_CnSC_CHIE_MASK) /**< TPM0_CnSC.CHIE Field                    */
#define TPM_CnSC_CHF_MASK                        (0x80U)                                             /**< TPM0_CnSC.CHF Mask                      */
#define TPM_CnSC_CHF_SHIFT                       (7U)                                                /**< TPM0_CnSC.CHF Position                  */
#define TPM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_CnSC_CHF_SHIFT))&TPM_CnSC_CHF_MASK) /**< TPM0_CnSC.CHF Field                     */
/** @} */

/** @name CnV - Channel %s Value */ /** @{ */
#define TPM_CnV_VAL_MASK                         (0xFFFFU)                                           /**< TPM0_CnV.VAL Mask                       */
#define TPM_CnV_VAL_SHIFT                        (0U)                                                /**< TPM0_CnV.VAL Position                   */
#define TPM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_CnV_VAL_SHIFT))&TPM_CnV_VAL_MASK) /**< TPM0_CnV.VAL Field                      */
/** @} */

/** @name STATUS - Capture and Compare Status */ /** @{ */
#define TPM_STATUS_CH0F_MASK                     (0x1U)                                              /**< TPM0_STATUS.CH0F Mask                   */
#define TPM_STATUS_CH0F_SHIFT                    (0U)                                                /**< TPM0_STATUS.CH0F Position               */
#define TPM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH0F_SHIFT))&TPM_STATUS_CH0F_MASK) /**< TPM0_STATUS.CH0F Field                  */
#define TPM_STATUS_CH1F_MASK                     (0x2U)                                              /**< TPM0_STATUS.CH1F Mask                   */
#define TPM_STATUS_CH1F_SHIFT                    (1U)                                                /**< TPM0_STATUS.CH1F Position               */
#define TPM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH1F_SHIFT))&TPM_STATUS_CH1F_MASK) /**< TPM0_STATUS.CH1F Field                  */
#define TPM_STATUS_CH2F_MASK                     (0x4U)                                              /**< TPM0_STATUS.CH2F Mask                   */
#define TPM_STATUS_CH2F_SHIFT                    (2U)                                                /**< TPM0_STATUS.CH2F Position               */
#define TPM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH2F_SHIFT))&TPM_STATUS_CH2F_MASK) /**< TPM0_STATUS.CH2F Field                  */
#define TPM_STATUS_CH3F_MASK                     (0x8U)                                              /**< TPM0_STATUS.CH3F Mask                   */
#define TPM_STATUS_CH3F_SHIFT                    (3U)                                                /**< TPM0_STATUS.CH3F Position               */
#define TPM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH3F_SHIFT))&TPM_STATUS_CH3F_MASK) /**< TPM0_STATUS.CH3F Field                  */
#define TPM_STATUS_CH4F_MASK                     (0x10U)                                             /**< TPM0_STATUS.CH4F Mask                   */
#define TPM_STATUS_CH4F_SHIFT                    (4U)                                                /**< TPM0_STATUS.CH4F Position               */
#define TPM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH4F_SHIFT))&TPM_STATUS_CH4F_MASK) /**< TPM0_STATUS.CH4F Field                  */
#define TPM_STATUS_CH5F_MASK                     (0x20U)                                             /**< TPM0_STATUS.CH5F Mask                   */
#define TPM_STATUS_CH5F_SHIFT                    (5U)                                                /**< TPM0_STATUS.CH5F Position               */
#define TPM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_CH5F_SHIFT))&TPM_STATUS_CH5F_MASK) /**< TPM0_STATUS.CH5F Field                  */
#define TPM_STATUS_TOF_MASK                      (0x100U)                                            /**< TPM0_STATUS.TOF Mask                    */
#define TPM_STATUS_TOF_SHIFT                     (8U)                                                /**< TPM0_STATUS.TOF Position                */
#define TPM_STATUS_TOF(x)                        (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_TOF_SHIFT))&TPM_STATUS_TOF_MASK) /**< TPM0_STATUS.TOF Field                   */
/** @} */

/** @name CONF - Configuration */ /** @{ */
#define TPM_CONF_DOZEEN_MASK                     (0x20U)                                             /**< TPM0_CONF.DOZEEN Mask                   */
#define TPM_CONF_DOZEEN_SHIFT                    (5U)                                                /**< TPM0_CONF.DOZEEN Position               */
#define TPM_CONF_DOZEEN(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_DOZEEN_SHIFT))&TPM_CONF_DOZEEN_MASK) /**< TPM0_CONF.DOZEEN Field                  */
#define TPM_CONF_DBGMODE_MASK                    (0xC0U)                                             /**< TPM0_CONF.DBGMODE Mask                  */
#define TPM_CONF_DBGMODE_SHIFT                   (6U)                                                /**< TPM0_CONF.DBGMODE Position              */
#define TPM_CONF_DBGMODE(x)                      (((uint32_t)(((uint32_t)(x))<<TPM_CONF_DBGMODE_SHIFT))&TPM_CONF_DBGMODE_MASK) /**< TPM0_CONF.DBGMODE Field                 */
#define TPM_CONF_GTBEEN_MASK                     (0x200U)                                            /**< TPM0_CONF.GTBEEN Mask                   */
#define TPM_CONF_GTBEEN_SHIFT                    (9U)                                                /**< TPM0_CONF.GTBEEN Position               */
#define TPM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_GTBEEN_SHIFT))&TPM_CONF_GTBEEN_MASK) /**< TPM0_CONF.GTBEEN Field                  */
#define TPM_CONF_CSOT_MASK                       (0x10000U)                                          /**< TPM0_CONF.CSOT Mask                     */
#define TPM_CONF_CSOT_SHIFT                      (16U)                                               /**< TPM0_CONF.CSOT Position                 */
#define TPM_CONF_CSOT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CSOT_SHIFT))&TPM_CONF_CSOT_MASK) /**< TPM0_CONF.CSOT Field                    */
#define TPM_CONF_CSOO_MASK                       (0x20000U)                                          /**< TPM0_CONF.CSOO Mask                     */
#define TPM_CONF_CSOO_SHIFT                      (17U)                                               /**< TPM0_CONF.CSOO Position                 */
#define TPM_CONF_CSOO(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CSOO_SHIFT))&TPM_CONF_CSOO_MASK) /**< TPM0_CONF.CSOO Field                    */
#define TPM_CONF_CROT_MASK                       (0x40000U)                                          /**< TPM0_CONF.CROT Mask                     */
#define TPM_CONF_CROT_SHIFT                      (18U)                                               /**< TPM0_CONF.CROT Position                 */
#define TPM_CONF_CROT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CROT_SHIFT))&TPM_CONF_CROT_MASK) /**< TPM0_CONF.CROT Field                    */
#define TPM_CONF_TRGSEL_MASK                     (0xF000000U)                                        /**< TPM0_CONF.TRGSEL Mask                   */
#define TPM_CONF_TRGSEL_SHIFT                    (24U)                                               /**< TPM0_CONF.TRGSEL Position               */
#define TPM_CONF_TRGSEL(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGSEL_SHIFT))&TPM_CONF_TRGSEL_MASK) /**< TPM0_CONF.TRGSEL Field                  */
/** @} */

/** @} */ /* End group TPM_Register_Masks_GROUP */


/* TPM0 - Peripheral instance base addresses */
#define TPM0_BasePtr                   0x40038000UL //!< Peripheral base address
#define TPM0                           ((TPM_Type *) TPM0_BasePtr) //!< Freescale base pointer
#define TPM0_BASE_PTR                  (TPM0) //!< Freescale style base pointer
#define TPM0_IRQS { TPM0_IRQn,  }


/** @} */ /* End group TPM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TPM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TPM1 (file:TPM1_2CH)                 ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module (2 channels)
 */
#define TPM1_CONTROLS_COUNT  2          /**< Number of FTM channels                             */
/**
 * @struct TPM1_Type
 * @brief  C Struct allowing access to TPM registers
 */
typedef struct TPM1_Type {
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[TPM1_CONTROLS_COUNT];             /**< 000C: (cluster: size=0x0010, 16)                                   */
        uint8_t   RESERVED_1[52];               /**< 001C: 0x34 bytes                                                   */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
        uint8_t   RESERVED_2[48];               /**< 0054: 0x30 bytes                                                   */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
} TPM1_Type;


/** @brief Register Masks for TPM */

/* -------------------------------------------------------------------------------- */
/* -----------     'TPM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TPM_Register_Masks_GROUP TPM Register Masks */
/** @{ */

/** @} */ /* End group TPM_Register_Masks_GROUP */


/* TPM1 - Peripheral instance base addresses */
#define TPM1_BasePtr                   0x40039000UL //!< Peripheral base address
#define TPM1                           ((TPM1_Type *) TPM1_BasePtr) //!< Freescale base pointer
#define TPM1_BASE_PTR                  (TPM1) //!< Freescale style base pointer
#define TPM1_IRQS { TPM1_IRQn,  }


/** @} */ /* End group TPM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TPM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TPM2 (derived from TPM1)             ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module (2 channels)
 */

/* TPM2 - Peripheral instance base addresses */
#define TPM2_BasePtr                   0x4003A000UL //!< Peripheral base address
#define TPM2                           ((TPM1_Type *) TPM2_BasePtr) //!< Freescale base pointer
#define TPM2_BASE_PTR                  (TPM2) //!< Freescale style base pointer
#define TPM2_IRQS { TPM2_IRQn,  }


/** @} */ /* End group TPM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TSI */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TSI_Peripheral_access_layer_GROUP TSI Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TSI0 (file:TSI0_MKL)                 ================ */
/* ================================================================================ */

/**
 * @brief Touch Sensing Input
 */
/**
 * @struct TSI_Type
 * @brief  C Struct allowing access to TSI registers
 */
typedef struct TSI_Type {
   __IO uint32_t  GENCS;                        /**< 0000: General Control and Status Register                          */
   __IO uint32_t  DATA;                         /**< 0004: DATA Register                                                */
   __IO uint32_t  TSHD;                         /**< 0008: Threshold Register                                           */
} TSI_Type;


/** @brief Register Masks for TSI */

/* -------------------------------------------------------------------------------- */
/* -----------     'TSI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TSI_Register_Masks_GROUP TSI Register Masks */
/** @{ */

/** @name GENCS - General Control and Status Register */ /** @{ */
#define TSI_GENCS_CURSW_MASK                     (0x2U)                                              /**< TSI0_GENCS.CURSW Mask                   */
#define TSI_GENCS_CURSW_SHIFT                    (1U)                                                /**< TSI0_GENCS.CURSW Position               */
#define TSI_GENCS_CURSW(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_CURSW_SHIFT))&TSI_GENCS_CURSW_MASK) /**< TSI0_GENCS.CURSW Field                  */
#define TSI_GENCS_EOSF_MASK                      (0x4U)                                              /**< TSI0_GENCS.EOSF Mask                    */
#define TSI_GENCS_EOSF_SHIFT                     (2U)                                                /**< TSI0_GENCS.EOSF Position                */
#define TSI_GENCS_EOSF(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_EOSF_SHIFT))&TSI_GENCS_EOSF_MASK) /**< TSI0_GENCS.EOSF Field                   */
#define TSI_GENCS_SCNIP_MASK                     (0x8U)                                              /**< TSI0_GENCS.SCNIP Mask                   */
#define TSI_GENCS_SCNIP_SHIFT                    (3U)                                                /**< TSI0_GENCS.SCNIP Position               */
#define TSI_GENCS_SCNIP(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_SCNIP_SHIFT))&TSI_GENCS_SCNIP_MASK) /**< TSI0_GENCS.SCNIP Field                  */
#define TSI_GENCS_STM_MASK                       (0x10U)                                             /**< TSI0_GENCS.STM Mask                     */
#define TSI_GENCS_STM_SHIFT                      (4U)                                                /**< TSI0_GENCS.STM Position                 */
#define TSI_GENCS_STM(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_STM_SHIFT))&TSI_GENCS_STM_MASK) /**< TSI0_GENCS.STM Field                    */
#define TSI_GENCS_STPE_MASK                      (0x20U)                                             /**< TSI0_GENCS.STPE Mask                    */
#define TSI_GENCS_STPE_SHIFT                     (5U)                                                /**< TSI0_GENCS.STPE Position                */
#define TSI_GENCS_STPE(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_STPE_SHIFT))&TSI_GENCS_STPE_MASK) /**< TSI0_GENCS.STPE Field                   */
#define TSI_GENCS_TSIIEN_MASK                    (0x40U)                                             /**< TSI0_GENCS.TSIIEN Mask                  */
#define TSI_GENCS_TSIIEN_SHIFT                   (6U)                                                /**< TSI0_GENCS.TSIIEN Position              */
#define TSI_GENCS_TSIIEN(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_TSIIEN_SHIFT))&TSI_GENCS_TSIIEN_MASK) /**< TSI0_GENCS.TSIIEN Field                 */
#define TSI_GENCS_TSIEN_MASK                     (0x80U)                                             /**< TSI0_GENCS.TSIEN Mask                   */
#define TSI_GENCS_TSIEN_SHIFT                    (7U)                                                /**< TSI0_GENCS.TSIEN Position               */
#define TSI_GENCS_TSIEN(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_TSIEN_SHIFT))&TSI_GENCS_TSIEN_MASK) /**< TSI0_GENCS.TSIEN Field                  */
#define TSI_GENCS_NSCN_MASK                      (0x1F00U)                                           /**< TSI0_GENCS.NSCN Mask                    */
#define TSI_GENCS_NSCN_SHIFT                     (8U)                                                /**< TSI0_GENCS.NSCN Position                */
#define TSI_GENCS_NSCN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_NSCN_SHIFT))&TSI_GENCS_NSCN_MASK) /**< TSI0_GENCS.NSCN Field                   */
#define TSI_GENCS_PS_MASK                        (0xE000U)                                           /**< TSI0_GENCS.PS Mask                      */
#define TSI_GENCS_PS_SHIFT                       (13U)                                               /**< TSI0_GENCS.PS Position                  */
#define TSI_GENCS_PS(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_PS_SHIFT))&TSI_GENCS_PS_MASK) /**< TSI0_GENCS.PS Field                     */
#define TSI_GENCS_EXTCHRG_MASK                   (0x70000U)                                          /**< TSI0_GENCS.EXTCHRG Mask                 */
#define TSI_GENCS_EXTCHRG_SHIFT                  (16U)                                               /**< TSI0_GENCS.EXTCHRG Position             */
#define TSI_GENCS_EXTCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_EXTCHRG_SHIFT))&TSI_GENCS_EXTCHRG_MASK) /**< TSI0_GENCS.EXTCHRG Field                */
#define TSI_GENCS_RS_MASK                        (0x70000U)                                          /**< TSI0_GENCS.RS Mask                      */
#define TSI_GENCS_RS_SHIFT                       (16U)                                               /**< TSI0_GENCS.RS Position                  */
#define TSI_GENCS_RS(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_RS_SHIFT))&TSI_GENCS_RS_MASK) /**< TSI0_GENCS.RS Field                     */
#define TSI_GENCS_RESISTOR_MASK                  (0x10000U)                                          /**< TSI0_GENCS.RESISTOR Mask                */
#define TSI_GENCS_RESISTOR_SHIFT                 (16U)                                               /**< TSI0_GENCS.RESISTOR Position            */
#define TSI_GENCS_RESISTOR(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_RESISTOR_SHIFT))&TSI_GENCS_RESISTOR_MASK) /**< TSI0_GENCS.RESISTOR Field               */
#define TSI_GENCS_NOISE_THRESHOLD_MASK           (0x1E0000U)                                         /**< TSI0_GENCS.NOISE_THRESHOLD Mask         */
#define TSI_GENCS_NOISE_THRESHOLD_SHIFT          (17U)                                               /**< TSI0_GENCS.NOISE_THRESHOLD Position     */
#define TSI_GENCS_NOISE_THRESHOLD(x)             (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_NOISE_THRESHOLD_SHIFT))&TSI_GENCS_NOISE_THRESHOLD_MASK) /**< TSI0_GENCS.NOISE_THRESHOLD Field        */
#define TSI_GENCS_FILTER_MASK                    (0x60000U)                                          /**< TSI0_GENCS.FILTER Mask                  */
#define TSI_GENCS_FILTER_SHIFT                   (17U)                                               /**< TSI0_GENCS.FILTER Position              */
#define TSI_GENCS_FILTER(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_FILTER_SHIFT))&TSI_GENCS_FILTER_MASK) /**< TSI0_GENCS.FILTER Field                 */
#define TSI_GENCS_DVOLT_MASK                     (0x180000U)                                         /**< TSI0_GENCS.DVOLT Mask                   */
#define TSI_GENCS_DVOLT_SHIFT                    (19U)                                               /**< TSI0_GENCS.DVOLT Position               */
#define TSI_GENCS_DVOLT(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_DVOLT_SHIFT))&TSI_GENCS_DVOLT_MASK) /**< TSI0_GENCS.DVOLT Field                  */
#define TSI_GENCS_REFCHRG_MASK                   (0xE00000U)                                         /**< TSI0_GENCS.REFCHRG Mask                 */
#define TSI_GENCS_REFCHRG_SHIFT                  (21U)                                               /**< TSI0_GENCS.REFCHRG Position             */
#define TSI_GENCS_REFCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_REFCHRG_SHIFT))&TSI_GENCS_REFCHRG_MASK) /**< TSI0_GENCS.REFCHRG Field                */
#define TSI_GENCS_MODE_MASK                      (0xF000000U)                                        /**< TSI0_GENCS.MODE Mask                    */
#define TSI_GENCS_MODE_SHIFT                     (24U)                                               /**< TSI0_GENCS.MODE Position                */
#define TSI_GENCS_MODE(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_MODE_SHIFT))&TSI_GENCS_MODE_MASK) /**< TSI0_GENCS.MODE Field                   */
#define TSI_GENCS_ESOR_MASK                      (0x10000000U)                                       /**< TSI0_GENCS.ESOR Mask                    */
#define TSI_GENCS_ESOR_SHIFT                     (28U)                                               /**< TSI0_GENCS.ESOR Position                */
#define TSI_GENCS_ESOR(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_ESOR_SHIFT))&TSI_GENCS_ESOR_MASK) /**< TSI0_GENCS.ESOR Field                   */
#define TSI_GENCS_OUTRGF_MASK                    (0x80000000U)                                       /**< TSI0_GENCS.OUTRGF Mask                  */
#define TSI_GENCS_OUTRGF_SHIFT                   (31U)                                               /**< TSI0_GENCS.OUTRGF Position              */
#define TSI_GENCS_OUTRGF(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_OUTRGF_SHIFT))&TSI_GENCS_OUTRGF_MASK) /**< TSI0_GENCS.OUTRGF Field                 */
/** @} */

/** @name DATA - DATA Register */ /** @{ */
#define TSI_DATA_TSICNT_MASK                     (0xFFFFU)                                           /**< TSI0_DATA.TSICNT Mask                   */
#define TSI_DATA_TSICNT_SHIFT                    (0U)                                                /**< TSI0_DATA.TSICNT Position               */
#define TSI_DATA_TSICNT(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_DATA_TSICNT_SHIFT))&TSI_DATA_TSICNT_MASK) /**< TSI0_DATA.TSICNT Field                  */
#define TSI_DATA_SWTS_MASK                       (0x400000U)                                         /**< TSI0_DATA.SWTS Mask                     */
#define TSI_DATA_SWTS_SHIFT                      (22U)                                               /**< TSI0_DATA.SWTS Position                 */
#define TSI_DATA_SWTS(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_DATA_SWTS_SHIFT))&TSI_DATA_SWTS_MASK) /**< TSI0_DATA.SWTS Field                    */
#define TSI_DATA_DMAEN_MASK                      (0x800000U)                                         /**< TSI0_DATA.DMAEN Mask                    */
#define TSI_DATA_DMAEN_SHIFT                     (23U)                                               /**< TSI0_DATA.DMAEN Position                */
#define TSI_DATA_DMAEN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_DATA_DMAEN_SHIFT))&TSI_DATA_DMAEN_MASK) /**< TSI0_DATA.DMAEN Field                   */
#define TSI_DATA_TSICH_MASK                      (0xF0000000U)                                       /**< TSI0_DATA.TSICH Mask                    */
#define TSI_DATA_TSICH_SHIFT                     (28U)                                               /**< TSI0_DATA.TSICH Position                */
#define TSI_DATA_TSICH(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_DATA_TSICH_SHIFT))&TSI_DATA_TSICH_MASK) /**< TSI0_DATA.TSICH Field                   */
/** @} */

/** @name TSHD - Threshold Register */ /** @{ */
#define TSI_TSHD_THRESL_MASK                     (0xFFFFU)                                           /**< TSI0_TSHD.THRESL Mask                   */
#define TSI_TSHD_THRESL_SHIFT                    (0U)                                                /**< TSI0_TSHD.THRESL Position               */
#define TSI_TSHD_THRESL(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_TSHD_THRESL_SHIFT))&TSI_TSHD_THRESL_MASK) /**< TSI0_TSHD.THRESL Field                  */
#define TSI_TSHD_THRESH_MASK                     (0xFFFF0000U)                                       /**< TSI0_TSHD.THRESH Mask                   */
#define TSI_TSHD_THRESH_SHIFT                    (16U)                                               /**< TSI0_TSHD.THRESH Position               */
#define TSI_TSHD_THRESH(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_TSHD_THRESH_SHIFT))&TSI_TSHD_THRESH_MASK) /**< TSI0_TSHD.THRESH Field                  */
/** @} */

/** @} */ /* End group TSI_Register_Masks_GROUP */


/* TSI0 - Peripheral instance base addresses */
#define TSI0_BasePtr                   0x40045000UL //!< Peripheral base address
#define TSI0                           ((TSI_Type *) TSI0_BasePtr) //!< Freescale base pointer
#define TSI0_BASE_PTR                  (TSI0) //!< Freescale style base pointer
#define TSI0_IRQS { TSI0_IRQn,  }


/** @} */ /* End group TSI_Peripheral_access_layer_GROUP */


/** @brief C Struct for UART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           UART0 (file:UART0_MKL04Z4)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
 * @struct UART_Type
 * @brief  C Struct allowing access to UART registers
 */
typedef struct UART_Type {
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __IO uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
} UART_Type;


/** @brief Register Masks for UART */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup UART_Register_Masks_GROUP UART Register Masks */
/** @{ */

/** @name BDH - Baud Rate Register: High */ /** @{ */
#define UART_BDH_SBR_MASK                        (0x1FU)                                             /**< UART0_BDH.SBR Mask                      */
#define UART_BDH_SBR_SHIFT                       (0U)                                                /**< UART0_BDH.SBR Position                  */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK) /**< UART0_BDH.SBR Field                     */
#define UART_BDH_SBNS_MASK                       (0x20U)                                             /**< UART0_BDH.SBNS Mask                     */
#define UART_BDH_SBNS_SHIFT                      (5U)                                                /**< UART0_BDH.SBNS Position                 */
#define UART_BDH_SBNS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBNS_SHIFT))&UART_BDH_SBNS_MASK) /**< UART0_BDH.SBNS Field                    */
#define UART_BDH_RXEDGIE_MASK                    (0x40U)                                             /**< UART0_BDH.RXEDGIE Mask                  */
#define UART_BDH_RXEDGIE_SHIFT                   (6U)                                                /**< UART0_BDH.RXEDGIE Position              */
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_BDH_RXEDGIE_SHIFT))&UART_BDH_RXEDGIE_MASK) /**< UART0_BDH.RXEDGIE Field                 */
#define UART_BDH_LBKDIE_MASK                     (0x80U)                                             /**< UART0_BDH.LBKDIE Mask                   */
#define UART_BDH_LBKDIE_SHIFT                    (7U)                                                /**< UART0_BDH.LBKDIE Position               */
#define UART_BDH_LBKDIE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_BDH_LBKDIE_SHIFT))&UART_BDH_LBKDIE_MASK) /**< UART0_BDH.LBKDIE Field                  */
/** @} */

/** @name BDL - Baud Rate Register: Low */ /** @{ */
#define UART_BDL_SBR_MASK                        (0xFFU)                                             /**< UART0_BDL.SBR Mask                      */
#define UART_BDL_SBR_SHIFT                       (0U)                                                /**< UART0_BDL.SBR Position                  */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK) /**< UART0_BDL.SBR Field                     */
/** @} */

/** @name C1 - Control Register 1 */ /** @{ */
#define UART_C1_PT_MASK                          (0x1U)                                              /**< UART0_C1.PT Mask                        */
#define UART_C1_PT_SHIFT                         (0U)                                                /**< UART0_C1.PT Position                    */
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PT_SHIFT))&UART_C1_PT_MASK) /**< UART0_C1.PT Field                       */
#define UART_C1_PE_MASK                          (0x2U)                                              /**< UART0_C1.PE Mask                        */
#define UART_C1_PE_SHIFT                         (1U)                                                /**< UART0_C1.PE Position                    */
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PE_SHIFT))&UART_C1_PE_MASK) /**< UART0_C1.PE Field                       */
#define UART_C1_ILT_MASK                         (0x4U)                                              /**< UART0_C1.ILT Mask                       */
#define UART_C1_ILT_SHIFT                        (2U)                                                /**< UART0_C1.ILT Position                   */
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C1_ILT_SHIFT))&UART_C1_ILT_MASK) /**< UART0_C1.ILT Field                      */
#define UART_C1_WAKE_MASK                        (0x8U)                                              /**< UART0_C1.WAKE Mask                      */
#define UART_C1_WAKE_SHIFT                       (3U)                                                /**< UART0_C1.WAKE Position                  */
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_WAKE_SHIFT))&UART_C1_WAKE_MASK) /**< UART0_C1.WAKE Field                     */
#define UART_C1_M_MASK                           (0x10U)                                             /**< UART0_C1.M Mask                         */
#define UART_C1_M_SHIFT                          (4U)                                                /**< UART0_C1.M Position                     */
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x))<<UART_C1_M_SHIFT))&UART_C1_M_MASK) /**< UART0_C1.M Field                        */
#define UART_C1_RSRC_MASK                        (0x20U)                                             /**< UART0_C1.RSRC Mask                      */
#define UART_C1_RSRC_SHIFT                       (5U)                                                /**< UART0_C1.RSRC Position                  */
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_RSRC_SHIFT))&UART_C1_RSRC_MASK) /**< UART0_C1.RSRC Field                     */
#define UART_C1_DOZEEN_MASK                      (0x40U)                                             /**< UART0_C1.DOZEEN Mask                    */
#define UART_C1_DOZEEN_SHIFT                     (6U)                                                /**< UART0_C1.DOZEEN Position                */
#define UART_C1_DOZEEN(x)                        (((uint8_t)(((uint8_t)(x))<<UART_C1_DOZEEN_SHIFT))&UART_C1_DOZEEN_MASK) /**< UART0_C1.DOZEEN Field                   */
#define UART_C1_LOOPS_MASK                       (0x80U)                                             /**< UART0_C1.LOOPS Mask                     */
#define UART_C1_LOOPS_SHIFT                      (7U)                                                /**< UART0_C1.LOOPS Position                 */
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C1_LOOPS_SHIFT))&UART_C1_LOOPS_MASK) /**< UART0_C1.LOOPS Field                    */
/** @} */

/** @name C2 - Control Register 2 */ /** @{ */
#define UART_C2_SBK_MASK                         (0x1U)                                              /**< UART0_C2.SBK Mask                       */
#define UART_C2_SBK_SHIFT                        (0U)                                                /**< UART0_C2.SBK Position                   */
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_SBK_SHIFT))&UART_C2_SBK_MASK) /**< UART0_C2.SBK Field                      */
#define UART_C2_RWU_MASK                         (0x2U)                                              /**< UART0_C2.RWU Mask                       */
#define UART_C2_RWU_SHIFT                        (1U)                                                /**< UART0_C2.RWU Position                   */
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RWU_SHIFT))&UART_C2_RWU_MASK) /**< UART0_C2.RWU Field                      */
#define UART_C2_RE_MASK                          (0x4U)                                              /**< UART0_C2.RE Mask                        */
#define UART_C2_RE_SHIFT                         (2U)                                                /**< UART0_C2.RE Position                    */
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_RE_SHIFT))&UART_C2_RE_MASK) /**< UART0_C2.RE Field                       */
#define UART_C2_TE_MASK                          (0x8U)                                              /**< UART0_C2.TE Mask                        */
#define UART_C2_TE_SHIFT                         (3U)                                                /**< UART0_C2.TE Position                    */
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_TE_SHIFT))&UART_C2_TE_MASK) /**< UART0_C2.TE Field                       */
#define UART_C2_ILIE_MASK                        (0x10U)                                             /**< UART0_C2.ILIE Mask                      */
#define UART_C2_ILIE_SHIFT                       (4U)                                                /**< UART0_C2.ILIE Position                  */
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_ILIE_SHIFT))&UART_C2_ILIE_MASK) /**< UART0_C2.ILIE Field                     */
#define UART_C2_RIE_MASK                         (0x20U)                                             /**< UART0_C2.RIE Mask                       */
#define UART_C2_RIE_SHIFT                        (5U)                                                /**< UART0_C2.RIE Position                   */
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RIE_SHIFT))&UART_C2_RIE_MASK) /**< UART0_C2.RIE Field                      */
#define UART_C2_TCIE_MASK                        (0x40U)                                             /**< UART0_C2.TCIE Mask                      */
#define UART_C2_TCIE_SHIFT                       (6U)                                                /**< UART0_C2.TCIE Position                  */
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_TCIE_SHIFT))&UART_C2_TCIE_MASK) /**< UART0_C2.TCIE Field                     */
#define UART_C2_TIE_MASK                         (0x80U)                                             /**< UART0_C2.TIE Mask                       */
#define UART_C2_TIE_SHIFT                        (7U)                                                /**< UART0_C2.TIE Position                   */
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_TIE_SHIFT))&UART_C2_TIE_MASK) /**< UART0_C2.TIE Field                      */
/** @} */

/** @name S1 - Status Register 1 */ /** @{ */
#define UART_S1_PF_MASK                          (0x1U)                                              /**< UART0_S1.PF Mask                        */
#define UART_S1_PF_SHIFT                         (0U)                                                /**< UART0_S1.PF Position                    */
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_PF_SHIFT))&UART_S1_PF_MASK) /**< UART0_S1.PF Field                       */
#define UART_S1_FE_MASK                          (0x2U)                                              /**< UART0_S1.FE Mask                        */
#define UART_S1_FE_SHIFT                         (1U)                                                /**< UART0_S1.FE Position                    */
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_FE_SHIFT))&UART_S1_FE_MASK) /**< UART0_S1.FE Field                       */
#define UART_S1_NF_MASK                          (0x4U)                                              /**< UART0_S1.NF Mask                        */
#define UART_S1_NF_SHIFT                         (2U)                                                /**< UART0_S1.NF Position                    */
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_NF_SHIFT))&UART_S1_NF_MASK) /**< UART0_S1.NF Field                       */
#define UART_S1_OR_MASK                          (0x8U)                                              /**< UART0_S1.OR Mask                        */
#define UART_S1_OR_SHIFT                         (3U)                                                /**< UART0_S1.OR Position                    */
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_OR_SHIFT))&UART_S1_OR_MASK) /**< UART0_S1.OR Field                       */
#define UART_S1_IDLE_MASK                        (0x10U)                                             /**< UART0_S1.IDLE Mask                      */
#define UART_S1_IDLE_SHIFT                       (4U)                                                /**< UART0_S1.IDLE Position                  */
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_IDLE_SHIFT))&UART_S1_IDLE_MASK) /**< UART0_S1.IDLE Field                     */
#define UART_S1_RDRF_MASK                        (0x20U)                                             /**< UART0_S1.RDRF Mask                      */
#define UART_S1_RDRF_SHIFT                       (5U)                                                /**< UART0_S1.RDRF Position                  */
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_RDRF_SHIFT))&UART_S1_RDRF_MASK) /**< UART0_S1.RDRF Field                     */
#define UART_S1_TC_MASK                          (0x40U)                                             /**< UART0_S1.TC Mask                        */
#define UART_S1_TC_SHIFT                         (6U)                                                /**< UART0_S1.TC Position                    */
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_TC_SHIFT))&UART_S1_TC_MASK) /**< UART0_S1.TC Field                       */
#define UART_S1_TDRE_MASK                        (0x80U)                                             /**< UART0_S1.TDRE Mask                      */
#define UART_S1_TDRE_SHIFT                       (7U)                                                /**< UART0_S1.TDRE Position                  */
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_TDRE_SHIFT))&UART_S1_TDRE_MASK) /**< UART0_S1.TDRE Field                     */
/** @} */

/** @name S2 - Status Register 2 */ /** @{ */
#define UART_S2_RAF_MASK                         (0x1U)                                              /**< UART0_S2.RAF Mask                       */
#define UART_S2_RAF_SHIFT                        (0U)                                                /**< UART0_S2.RAF Position                   */
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x))<<UART_S2_RAF_SHIFT))&UART_S2_RAF_MASK) /**< UART0_S2.RAF Field                      */
#define UART_S2_LBKDE_MASK                       (0x2U)                                              /**< UART0_S2.LBKDE Mask                     */
#define UART_S2_LBKDE_SHIFT                      (1U)                                                /**< UART0_S2.LBKDE Position                 */
#define UART_S2_LBKDE(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_LBKDE_SHIFT))&UART_S2_LBKDE_MASK) /**< UART0_S2.LBKDE Field                    */
#define UART_S2_BRK13_MASK                       (0x4U)                                              /**< UART0_S2.BRK13 Mask                     */
#define UART_S2_BRK13_SHIFT                      (2U)                                                /**< UART0_S2.BRK13 Position                 */
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_BRK13_SHIFT))&UART_S2_BRK13_MASK) /**< UART0_S2.BRK13 Field                    */
#define UART_S2_RWUID_MASK                       (0x8U)                                              /**< UART0_S2.RWUID Mask                     */
#define UART_S2_RWUID_SHIFT                      (3U)                                                /**< UART0_S2.RWUID Position                 */
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RWUID_SHIFT))&UART_S2_RWUID_MASK) /**< UART0_S2.RWUID Field                    */
#define UART_S2_RXINV_MASK                       (0x10U)                                             /**< UART0_S2.RXINV Mask                     */
#define UART_S2_RXINV_SHIFT                      (4U)                                                /**< UART0_S2.RXINV Position                 */
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RXINV_SHIFT))&UART_S2_RXINV_MASK) /**< UART0_S2.RXINV Field                    */
#define UART_S2_MSBF_MASK                        (0x20U)                                             /**< UART0_S2.MSBF Mask                      */
#define UART_S2_MSBF_SHIFT                       (5U)                                                /**< UART0_S2.MSBF Position                  */
#define UART_S2_MSBF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S2_MSBF_SHIFT))&UART_S2_MSBF_MASK) /**< UART0_S2.MSBF Field                     */
#define UART_S2_RXEDGIF_MASK                     (0x40U)                                             /**< UART0_S2.RXEDGIF Mask                   */
#define UART_S2_RXEDGIF_SHIFT                    (6U)                                                /**< UART0_S2.RXEDGIF Position               */
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_S2_RXEDGIF_SHIFT))&UART_S2_RXEDGIF_MASK) /**< UART0_S2.RXEDGIF Field                  */
#define UART_S2_LBKDIF_MASK                      (0x80U)                                             /**< UART0_S2.LBKDIF Mask                    */
#define UART_S2_LBKDIF_SHIFT                     (7U)                                                /**< UART0_S2.LBKDIF Position                */
#define UART_S2_LBKDIF(x)                        (((uint8_t)(((uint8_t)(x))<<UART_S2_LBKDIF_SHIFT))&UART_S2_LBKDIF_MASK) /**< UART0_S2.LBKDIF Field                   */
/** @} */

/** @name C3 - Control Register 3 */ /** @{ */
#define UART_C3_PEIE_MASK                        (0x1U)                                              /**< UART0_C3.PEIE Mask                      */
#define UART_C3_PEIE_SHIFT                       (0U)                                                /**< UART0_C3.PEIE Position                  */
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_PEIE_SHIFT))&UART_C3_PEIE_MASK) /**< UART0_C3.PEIE Field                     */
#define UART_C3_FEIE_MASK                        (0x2U)                                              /**< UART0_C3.FEIE Mask                      */
#define UART_C3_FEIE_SHIFT                       (1U)                                                /**< UART0_C3.FEIE Position                  */
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_FEIE_SHIFT))&UART_C3_FEIE_MASK) /**< UART0_C3.FEIE Field                     */
#define UART_C3_NEIE_MASK                        (0x4U)                                              /**< UART0_C3.NEIE Mask                      */
#define UART_C3_NEIE_SHIFT                       (2U)                                                /**< UART0_C3.NEIE Position                  */
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_NEIE_SHIFT))&UART_C3_NEIE_MASK) /**< UART0_C3.NEIE Field                     */
#define UART_C3_ORIE_MASK                        (0x8U)                                              /**< UART0_C3.ORIE Mask                      */
#define UART_C3_ORIE_SHIFT                       (3U)                                                /**< UART0_C3.ORIE Position                  */
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_ORIE_SHIFT))&UART_C3_ORIE_MASK) /**< UART0_C3.ORIE Field                     */
#define UART_C3_TXINV_MASK                       (0x10U)                                             /**< UART0_C3.TXINV Mask                     */
#define UART_C3_TXINV_SHIFT                      (4U)                                                /**< UART0_C3.TXINV Position                 */
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXINV_SHIFT))&UART_C3_TXINV_MASK) /**< UART0_C3.TXINV Field                    */
#define UART_C3_TXDIR_MASK                       (0x20U)                                             /**< UART0_C3.TXDIR Mask                     */
#define UART_C3_TXDIR_SHIFT                      (5U)                                                /**< UART0_C3.TXDIR Position                 */
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXDIR_SHIFT))&UART_C3_TXDIR_MASK) /**< UART0_C3.TXDIR Field                    */
#define UART_C3_R9T8_MASK                        (0x40U)                                             /**< UART0_C3.R9T8 Mask                      */
#define UART_C3_R9T8_SHIFT                       (6U)                                                /**< UART0_C3.R9T8 Position                  */
#define UART_C3_R9T8(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_R9T8_SHIFT))&UART_C3_R9T8_MASK) /**< UART0_C3.R9T8 Field                     */
#define UART_C3_R8T9_MASK                        (0x80U)                                             /**< UART0_C3.R8T9 Mask                      */
#define UART_C3_R8T9_SHIFT                       (7U)                                                /**< UART0_C3.R8T9 Position                  */
#define UART_C3_R8T9(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_R8T9_SHIFT))&UART_C3_R8T9_MASK) /**< UART0_C3.R8T9 Field                     */
/** @} */

/** @name D - Data Register */ /** @{ */
#define UART_D_RT_MASK                           (0xFFU)                                             /**< UART0_D.RT Mask                         */
#define UART_D_RT_SHIFT                          (0U)                                                /**< UART0_D.RT Position                     */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /**< UART0_D.RT Field                        */
/** @} */

/** @name MA - Match Address Registers %s */ /** @{ */
#define UART_MA_MA_MASK                          (0xFFU)                                             /**< UART0_MA.MA Mask                        */
#define UART_MA_MA_SHIFT                         (0U)                                                /**< UART0_MA.MA Position                    */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<UART_MA_MA_SHIFT))&UART_MA_MA_MASK) /**< UART0_MA.MA Field                       */
/** @} */

/** @name C4 - Control Register 4 */ /** @{ */
#define UART_C4_OSR_MASK                         (0x1FU)                                             /**< UART0_C4.OSR Mask                       */
#define UART_C4_OSR_SHIFT                        (0U)                                                /**< UART0_C4.OSR Position                   */
#define UART_C4_OSR(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C4_OSR_SHIFT))&UART_C4_OSR_MASK) /**< UART0_C4.OSR Field                      */
#define UART_C4_M10_MASK                         (0x20U)                                             /**< UART0_C4.M10 Mask                       */
#define UART_C4_M10_SHIFT                        (5U)                                                /**< UART0_C4.M10 Position                   */
#define UART_C4_M10(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C4_M10_SHIFT))&UART_C4_M10_MASK) /**< UART0_C4.M10 Field                      */
#define UART_C4_MAEN2_MASK                       (0x40U)                                             /**< UART0_C4.MAEN2 Mask                     */
#define UART_C4_MAEN2_SHIFT                      (6U)                                                /**< UART0_C4.MAEN2 Position                 */
#define UART_C4_MAEN2(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN2_SHIFT))&UART_C4_MAEN2_MASK) /**< UART0_C4.MAEN2 Field                    */
#define UART_C4_MAEN1_MASK                       (0x80U)                                             /**< UART0_C4.MAEN1 Mask                     */
#define UART_C4_MAEN1_SHIFT                      (7U)                                                /**< UART0_C4.MAEN1 Position                 */
#define UART_C4_MAEN1(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN1_SHIFT))&UART_C4_MAEN1_MASK) /**< UART0_C4.MAEN1 Field                    */
/** @} */

/** @name C5 - Control Register 5 */ /** @{ */
#define UART_C5_RESYNCDIS_MASK                   (0x1U)                                              /**< UART0_C5.RESYNCDIS Mask                 */
#define UART_C5_RESYNCDIS_SHIFT                  (0U)                                                /**< UART0_C5.RESYNCDIS Position             */
#define UART_C5_RESYNCDIS(x)                     (((uint8_t)(((uint8_t)(x))<<UART_C5_RESYNCDIS_SHIFT))&UART_C5_RESYNCDIS_MASK) /**< UART0_C5.RESYNCDIS Field                */
#define UART_C5_BOTHEDGE_MASK                    (0x2U)                                              /**< UART0_C5.BOTHEDGE Mask                  */
#define UART_C5_BOTHEDGE_SHIFT                   (1U)                                                /**< UART0_C5.BOTHEDGE Position              */
#define UART_C5_BOTHEDGE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C5_BOTHEDGE_SHIFT))&UART_C5_BOTHEDGE_MASK) /**< UART0_C5.BOTHEDGE Field                 */
#define UART_C5_RDMAE_MASK                       (0x20U)                                             /**< UART0_C5.RDMAE Mask                     */
#define UART_C5_RDMAE_SHIFT                      (5U)                                                /**< UART0_C5.RDMAE Position                 */
#define UART_C5_RDMAE(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_RDMAE_SHIFT))&UART_C5_RDMAE_MASK) /**< UART0_C5.RDMAE Field                    */
#define UART_C5_TDMAE_MASK                       (0x80U)                                             /**< UART0_C5.TDMAE Mask                     */
#define UART_C5_TDMAE_SHIFT                      (7U)                                                /**< UART0_C5.TDMAE Position                 */
#define UART_C5_TDMAE(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_TDMAE_SHIFT))&UART_C5_TDMAE_MASK) /**< UART0_C5.TDMAE Field                    */
/** @} */

/** @} */ /* End group UART_Register_Masks_GROUP */


/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x4006A000UL //!< Peripheral base address
#define UART0                          ((UART_Type *) UART0_BasePtr) //!< Freescale base pointer
#define UART0_BASE_PTR                 (UART0) //!< Freescale style base pointer
#define UART0_IRQS { UART0_IRQn,  }


/** @} */ /* End group UART_Peripheral_access_layer_GROUP */


/** @brief C Struct for UART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           UART1 (file:UART1_MKL14Z4)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
 * @struct UART1_Type
 * @brief  C Struct allowing access to UART registers
 */
typedef struct UART1_Type {
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   C4;                           /**< 0008: Control Register 4                                           */
} UART1_Type;


/** @brief Register Masks for UART */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART1' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup UART_Register_Masks_GROUP UART Register Masks */
/** @{ */

/** @name C1 - Control Register 1 */ /** @{ */
#define UART_C1_UARTSWAI_MASK                    (0x40U)                                             /**< UART1_C1.UARTSWAI Mask                  */
#define UART_C1_UARTSWAI_SHIFT                   (6U)                                                /**< UART1_C1.UARTSWAI Position              */
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C1_UARTSWAI_SHIFT))&UART_C1_UARTSWAI_MASK) /**< UART1_C1.UARTSWAI Field                 */
/** @} */

/** @name C3 - Control Register 3 */ /** @{ */
#define UART_C3_T8_MASK                          (0x40U)                                             /**< UART1_C3.T8 Mask                        */
#define UART_C3_T8_SHIFT                         (6U)                                                /**< UART1_C3.T8 Position                    */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_T8_SHIFT))&UART_C3_T8_MASK) /**< UART1_C3.T8 Field                       */
#define UART_C3_R8_MASK                          (0x80U)                                             /**< UART1_C3.R8 Mask                        */
#define UART_C3_R8_SHIFT                         (7U)                                                /**< UART1_C3.R8 Position                    */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_R8_SHIFT))&UART_C3_R8_MASK) /**< UART1_C3.R8 Field                       */
/** @} */

/** @name C4 - Control Register 4 */ /** @{ */
#define UART_C4_RDMAS_MASK                       (0x20U)                                             /**< UART1_C4.RDMAS Mask                     */
#define UART_C4_RDMAS_SHIFT                      (5U)                                                /**< UART1_C4.RDMAS Position                 */
#define UART_C4_RDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_RDMAS_SHIFT))&UART_C4_RDMAS_MASK) /**< UART1_C4.RDMAS Field                    */
#define UART_C4_TDMAS_MASK                       (0x80U)                                             /**< UART1_C4.TDMAS Mask                     */
#define UART_C4_TDMAS_SHIFT                      (7U)                                                /**< UART1_C4.TDMAS Position                 */
#define UART_C4_TDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_TDMAS_SHIFT))&UART_C4_TDMAS_MASK) /**< UART1_C4.TDMAS Field                    */
/** @} */

/** @} */ /* End group UART_Register_Masks_GROUP */


/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x4006B000UL //!< Peripheral base address
#define UART1                          ((UART1_Type *) UART1_BasePtr) //!< Freescale base pointer
#define UART1_BASE_PTR                 (UART1) //!< Freescale style base pointer
#define UART1_IRQS { UART1_IRQn,  }


/** @} */ /* End group UART_Peripheral_access_layer_GROUP */


/** @brief C Struct for UART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           UART2 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x4006C000UL //!< Peripheral base address
#define UART2                          ((UART1_Type *) UART2_BasePtr) //!< Freescale base pointer
#define UART2_BASE_PTR                 (UART2) //!< Freescale style base pointer
#define UART2_IRQS { UART2_IRQn,  }


/** @} */ /* End group UART_Peripheral_access_layer_GROUP */


/** @brief C Struct for USB */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup USB_Peripheral_access_layer_GROUP USB Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           USB0 (file:USB0_OTG_C)               ================ */
/* ================================================================================ */

/**
 * @brief USB OTG Controller
 */
/**
 * @struct USB_Type
 * @brief  C Struct allowing access to USB registers
 */
typedef struct USB_Type {
   __I  uint8_t   PERID;                        /**< 0000: Peripheral ID Register                                       */
        uint8_t   RESERVED_0[3];                /**< 0001: 0x3 bytes                                                    */
   __I  uint8_t   IDCOMP;                       /**< 0004: Peripheral ID Complement Register                            */
        uint8_t   RESERVED_1[3];                /**< 0005: 0x3 bytes                                                    */
   __I  uint8_t   REV;                          /**< 0008: Peripheral Revision Register                                 */
        uint8_t   RESERVED_2[3];                /**< 0009: 0x3 bytes                                                    */
   __I  uint8_t   ADDINFO;                      /**< 000C: Peripheral Additional Info Register                          */
        uint8_t   RESERVED_3[3];                /**< 000D: 0x3 bytes                                                    */
   __IO uint8_t   OTGISTAT;                     /**< 0010: OTG Interrupt Status Register                                */
        uint8_t   RESERVED_4[3];                /**< 0011: 0x3 bytes                                                    */
   __IO uint8_t   OTGICR;                       /**< 0014: OTG Interrupt Control Register                               */
        uint8_t   RESERVED_5[3];                /**< 0015: 0x3 bytes                                                    */
   __IO uint8_t   OTGSTAT;                      /**< 0018: OTG Status Register                                          */
        uint8_t   RESERVED_6[3];                /**< 0019: 0x3 bytes                                                    */
   __IO uint8_t   OTGCTL;                       /**< 001C: OTG Control Register                                         */
        uint8_t   RESERVED_7[99];               /**< 001D: 0x63 bytes                                                   */
   __IO uint8_t   ISTAT;                        /**< 0080: Interrupt Status Register                                    */
        uint8_t   RESERVED_8[3];                /**< 0081: 0x3 bytes                                                    */
   __IO uint8_t   INTEN;                        /**< 0084: Interrupt Enable Register                                    */
        uint8_t   RESERVED_9[3];                /**< 0085: 0x3 bytes                                                    */
   __IO uint8_t   ERRSTAT;                      /**< 0088: Error Interrupt Status Register                              */
        uint8_t   RESERVED_10[3];               /**< 0089: 0x3 bytes                                                    */
   __IO uint8_t   ERREN;                        /**< 008C: Error Interrupt Enable Register                              */
        uint8_t   RESERVED_11[3];               /**< 008D: 0x3 bytes                                                    */
   __I  uint8_t   STAT;                         /**< 0090: Status Register                                              */
        uint8_t   RESERVED_12[3];               /**< 0091: 0x3 bytes                                                    */
   __IO uint8_t   CTL;                          /**< 0094: Control Register                                             */
        uint8_t   RESERVED_13[3];               /**< 0095: 0x3 bytes                                                    */
   __IO uint8_t   ADDR;                         /**< 0098: Address Register                                             */
        uint8_t   RESERVED_14[3];               /**< 0099: 0x3 bytes                                                    */
   __IO uint8_t   BDTPAGE1;                     /**< 009C: BDT Page Register 1                                          */
        uint8_t   RESERVED_15[3];               /**< 009D: 0x3 bytes                                                    */
   __IO uint8_t   FRMNUML;                      /**< 00A0: Frame Number Register Low                                    */
        uint8_t   RESERVED_16[3];               /**< 00A1: 0x3 bytes                                                    */
   __IO uint8_t   FRMNUMH;                      /**< 00A4: Frame Number Register High                                   */
        uint8_t   RESERVED_17[3];               /**< 00A5: 0x3 bytes                                                    */
   __IO uint8_t   TOKEN;                        /**< 00A8: Token Register                                               */
        uint8_t   RESERVED_18[3];               /**< 00A9: 0x3 bytes                                                    */
   __IO uint8_t   SOFTHLD;                      /**< 00AC: SOF Threshold Register                                       */
        uint8_t   RESERVED_19[3];               /**< 00AD: 0x3 bytes                                                    */
   __IO uint8_t   BDTPAGE2;                     /**< 00B0: BDT Page Register 2                                          */
        uint8_t   RESERVED_20[3];               /**< 00B1: 0x3 bytes                                                    */
   __IO uint8_t   BDTPAGE3;                     /**< 00B4: BDT Page Register 3                                          */
        uint8_t   RESERVED_21[11];              /**< 00B5: 0xB bytes                                                    */
   struct {
      __IO uint8_t   ENDPT;                     /**< 00C0: Endpoint Control Register                                    */
           uint8_t   RESERVED_22[3];            /**< 00C1: 0x3 bytes                                                    */
   } ENDPOINT[16];                              /**< 00C0: (cluster: size=0x0040, 64)                                   */
   __IO uint8_t   USBCTRL;                      /**< 0100: USB Control Register                                         */
        uint8_t   RESERVED_23[3];               /**< 0101: 0x3 bytes                                                    */
   __I  uint8_t   OBSERVE;                      /**< 0104: USB OTG Observe Register                                     */
        uint8_t   RESERVED_24[3];               /**< 0105: 0x3 bytes                                                    */
   __IO uint8_t   CONTROL;                      /**< 0108: USB OTG Control Register                                     */
        uint8_t   RESERVED_25[3];               /**< 0109: 0x3 bytes                                                    */
   __IO uint8_t   USBTRC0;                      /**< 010C: USB Transceiver Control Register 0                           */
        uint8_t   RESERVED_26[7];               /**< 010D: 0x7 bytes                                                    */
   __IO uint8_t   USBFRMADJUST;                 /**< 0114: Frame Adjust Register                                        */
} USB_Type;


/** @brief Register Masks for USB */

/* -------------------------------------------------------------------------------- */
/* -----------     'USB0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup USB_Register_Masks_GROUP USB Register Masks */
/** @{ */

/** @name PERID - Peripheral ID Register */ /** @{ */
#define USB_PERID_ID_MASK                        (0x3FU)                                             /**< USB0_PERID.ID Mask                      */
#define USB_PERID_ID_SHIFT                       (0U)                                                /**< USB0_PERID.ID Position                  */
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<USB_PERID_ID_SHIFT))&USB_PERID_ID_MASK) /**< USB0_PERID.ID Field                     */
/** @} */

/** @name IDCOMP - Peripheral ID Complement Register */ /** @{ */
#define USB_IDCOMP_NID_MASK                      (0x3FU)                                             /**< USB0_IDCOMP.NID Mask                    */
#define USB_IDCOMP_NID_SHIFT                     (0U)                                                /**< USB0_IDCOMP.NID Position                */
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_IDCOMP_NID_SHIFT))&USB_IDCOMP_NID_MASK) /**< USB0_IDCOMP.NID Field                   */
/** @} */

/** @name REV - Peripheral Revision Register */ /** @{ */
#define USB_REV_REV_MASK                         (0xFFU)                                             /**< USB0_REV.REV Mask                       */
#define USB_REV_REV_SHIFT                        (0U)                                                /**< USB0_REV.REV Position                   */
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<USB_REV_REV_SHIFT))&USB_REV_REV_MASK) /**< USB0_REV.REV Field                      */
/** @} */

/** @name ADDINFO - Peripheral Additional Info Register */ /** @{ */
#define USB_ADDINFO_IEHOST_MASK                  (0x1U)                                              /**< USB0_ADDINFO.IEHOST Mask                */
#define USB_ADDINFO_IEHOST_SHIFT                 (0U)                                                /**< USB0_ADDINFO.IEHOST Position            */
#define USB_ADDINFO_IEHOST(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ADDINFO_IEHOST_SHIFT))&USB_ADDINFO_IEHOST_MASK) /**< USB0_ADDINFO.IEHOST Field               */
#define USB_ADDINFO_IRQNUM_MASK                  (0xF8U)                                             /**< USB0_ADDINFO.IRQNUM Mask                */
#define USB_ADDINFO_IRQNUM_SHIFT                 (3U)                                                /**< USB0_ADDINFO.IRQNUM Position            */
#define USB_ADDINFO_IRQNUM(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ADDINFO_IRQNUM_SHIFT))&USB_ADDINFO_IRQNUM_MASK) /**< USB0_ADDINFO.IRQNUM Field               */
/** @} */

/** @name OTGISTAT - OTG Interrupt Status Register */ /** @{ */
#define USB_OTGISTAT_AVBUSCHG_MASK               (0x1U)                                              /**< USB0_OTGISTAT.AVBUSCHG Mask             */
#define USB_OTGISTAT_AVBUSCHG_SHIFT              (0U)                                                /**< USB0_OTGISTAT.AVBUSCHG Position         */
#define USB_OTGISTAT_AVBUSCHG(x)                 (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_AVBUSCHG_SHIFT))&USB_OTGISTAT_AVBUSCHG_MASK) /**< USB0_OTGISTAT.AVBUSCHG Field            */
#define USB_OTGISTAT_B_SESS_CHG_MASK             (0x4U)                                              /**< USB0_OTGISTAT.B_SESS_CHG Mask           */
#define USB_OTGISTAT_B_SESS_CHG_SHIFT            (2U)                                                /**< USB0_OTGISTAT.B_SESS_CHG Position       */
#define USB_OTGISTAT_B_SESS_CHG(x)               (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_B_SESS_CHG_SHIFT))&USB_OTGISTAT_B_SESS_CHG_MASK) /**< USB0_OTGISTAT.B_SESS_CHG Field          */
#define USB_OTGISTAT_SESSVLDCHG_MASK             (0x8U)                                              /**< USB0_OTGISTAT.SESSVLDCHG Mask           */
#define USB_OTGISTAT_SESSVLDCHG_SHIFT            (3U)                                                /**< USB0_OTGISTAT.SESSVLDCHG Position       */
#define USB_OTGISTAT_SESSVLDCHG(x)               (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_SESSVLDCHG_SHIFT))&USB_OTGISTAT_SESSVLDCHG_MASK) /**< USB0_OTGISTAT.SESSVLDCHG Field          */
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         (0x20U)                                             /**< USB0_OTGISTAT.LINE_STATE_CHG Mask       */
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        (5U)                                                /**< USB0_OTGISTAT.LINE_STATE_CHG Position   */
#define USB_OTGISTAT_LINE_STATE_CHG(x)           (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_LINE_STATE_CHG_SHIFT))&USB_OTGISTAT_LINE_STATE_CHG_MASK) /**< USB0_OTGISTAT.LINE_STATE_CHG Field      */
#define USB_OTGISTAT_ONEMSEC_MASK                (0x40U)                                             /**< USB0_OTGISTAT.ONEMSEC Mask              */
#define USB_OTGISTAT_ONEMSEC_SHIFT               (6U)                                                /**< USB0_OTGISTAT.ONEMSEC Position          */
#define USB_OTGISTAT_ONEMSEC(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_ONEMSEC_SHIFT))&USB_OTGISTAT_ONEMSEC_MASK) /**< USB0_OTGISTAT.ONEMSEC Field             */
#define USB_OTGISTAT_IDCHG_MASK                  (0x80U)                                             /**< USB0_OTGISTAT.IDCHG Mask                */
#define USB_OTGISTAT_IDCHG_SHIFT                 (7U)                                                /**< USB0_OTGISTAT.IDCHG Position            */
#define USB_OTGISTAT_IDCHG(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_IDCHG_SHIFT))&USB_OTGISTAT_IDCHG_MASK) /**< USB0_OTGISTAT.IDCHG Field               */
/** @} */

/** @name OTGICR - OTG Interrupt Control Register */ /** @{ */
#define USB_OTGICR_AVBUSEN_MASK                  (0x1U)                                              /**< USB0_OTGICR.AVBUSEN Mask                */
#define USB_OTGICR_AVBUSEN_SHIFT                 (0U)                                                /**< USB0_OTGICR.AVBUSEN Position            */
#define USB_OTGICR_AVBUSEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_AVBUSEN_SHIFT))&USB_OTGICR_AVBUSEN_MASK) /**< USB0_OTGICR.AVBUSEN Field               */
#define USB_OTGICR_BSESSEN_MASK                  (0x4U)                                              /**< USB0_OTGICR.BSESSEN Mask                */
#define USB_OTGICR_BSESSEN_SHIFT                 (2U)                                                /**< USB0_OTGICR.BSESSEN Position            */
#define USB_OTGICR_BSESSEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_BSESSEN_SHIFT))&USB_OTGICR_BSESSEN_MASK) /**< USB0_OTGICR.BSESSEN Field               */
#define USB_OTGICR_SESSVLDEN_MASK                (0x8U)                                              /**< USB0_OTGICR.SESSVLDEN Mask              */
#define USB_OTGICR_SESSVLDEN_SHIFT               (3U)                                                /**< USB0_OTGICR.SESSVLDEN Position          */
#define USB_OTGICR_SESSVLDEN(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_SESSVLDEN_SHIFT))&USB_OTGICR_SESSVLDEN_MASK) /**< USB0_OTGICR.SESSVLDEN Field             */
#define USB_OTGICR_LINESTATEEN_MASK              (0x20U)                                             /**< USB0_OTGICR.LINESTATEEN Mask            */
#define USB_OTGICR_LINESTATEEN_SHIFT             (5U)                                                /**< USB0_OTGICR.LINESTATEEN Position        */
#define USB_OTGICR_LINESTATEEN(x)                (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_LINESTATEEN_SHIFT))&USB_OTGICR_LINESTATEEN_MASK) /**< USB0_OTGICR.LINESTATEEN Field           */
#define USB_OTGICR_ONEMSECEN_MASK                (0x40U)                                             /**< USB0_OTGICR.ONEMSECEN Mask              */
#define USB_OTGICR_ONEMSECEN_SHIFT               (6U)                                                /**< USB0_OTGICR.ONEMSECEN Position          */
#define USB_OTGICR_ONEMSECEN(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_ONEMSECEN_SHIFT))&USB_OTGICR_ONEMSECEN_MASK) /**< USB0_OTGICR.ONEMSECEN Field             */
#define USB_OTGICR_IDEN_MASK                     (0x80U)                                             /**< USB0_OTGICR.IDEN Mask                   */
#define USB_OTGICR_IDEN_SHIFT                    (7U)                                                /**< USB0_OTGICR.IDEN Position               */
#define USB_OTGICR_IDEN(x)                       (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_IDEN_SHIFT))&USB_OTGICR_IDEN_MASK) /**< USB0_OTGICR.IDEN Field                  */
/** @} */

/** @name OTGSTAT - OTG Status Register */ /** @{ */
#define USB_OTGSTAT_AVBUSVLD_MASK                (0x1U)                                              /**< USB0_OTGSTAT.AVBUSVLD Mask              */
#define USB_OTGSTAT_AVBUSVLD_SHIFT               (0U)                                                /**< USB0_OTGSTAT.AVBUSVLD Position          */
#define USB_OTGSTAT_AVBUSVLD(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_AVBUSVLD_SHIFT))&USB_OTGSTAT_AVBUSVLD_MASK) /**< USB0_OTGSTAT.AVBUSVLD Field             */
#define USB_OTGSTAT_BSESSEND_MASK                (0x4U)                                              /**< USB0_OTGSTAT.BSESSEND Mask              */
#define USB_OTGSTAT_BSESSEND_SHIFT               (2U)                                                /**< USB0_OTGSTAT.BSESSEND Position          */
#define USB_OTGSTAT_BSESSEND(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_BSESSEND_SHIFT))&USB_OTGSTAT_BSESSEND_MASK) /**< USB0_OTGSTAT.BSESSEND Field             */
#define USB_OTGSTAT_SESS_VLD_MASK                (0x8U)                                              /**< USB0_OTGSTAT.SESS_VLD Mask              */
#define USB_OTGSTAT_SESS_VLD_SHIFT               (3U)                                                /**< USB0_OTGSTAT.SESS_VLD Position          */
#define USB_OTGSTAT_SESS_VLD(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_SESS_VLD_SHIFT))&USB_OTGSTAT_SESS_VLD_MASK) /**< USB0_OTGSTAT.SESS_VLD Field             */
#define USB_OTGSTAT_LINESTATESTABLE_MASK         (0x20U)                                             /**< USB0_OTGSTAT.LINESTATESTABLE Mask       */
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        (5U)                                                /**< USB0_OTGSTAT.LINESTATESTABLE Position   */
#define USB_OTGSTAT_LINESTATESTABLE(x)           (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_LINESTATESTABLE_SHIFT))&USB_OTGSTAT_LINESTATESTABLE_MASK) /**< USB0_OTGSTAT.LINESTATESTABLE Field      */
#define USB_OTGSTAT_ONEMSECEN_MASK               (0x40U)                                             /**< USB0_OTGSTAT.ONEMSECEN Mask             */
#define USB_OTGSTAT_ONEMSECEN_SHIFT              (6U)                                                /**< USB0_OTGSTAT.ONEMSECEN Position         */
#define USB_OTGSTAT_ONEMSECEN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_ONEMSECEN_SHIFT))&USB_OTGSTAT_ONEMSECEN_MASK) /**< USB0_OTGSTAT.ONEMSECEN Field            */
#define USB_OTGSTAT_ID_MASK                      (0x80U)                                             /**< USB0_OTGSTAT.ID Mask                    */
#define USB_OTGSTAT_ID_SHIFT                     (7U)                                                /**< USB0_OTGSTAT.ID Position                */
#define USB_OTGSTAT_ID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_ID_SHIFT))&USB_OTGSTAT_ID_MASK) /**< USB0_OTGSTAT.ID Field                   */
/** @} */

/** @name OTGCTL - OTG Control Register */ /** @{ */
#define USB_OTGCTL_OTGEN_MASK                    (0x4U)                                              /**< USB0_OTGCTL.OTGEN Mask                  */
#define USB_OTGCTL_OTGEN_SHIFT                   (2U)                                                /**< USB0_OTGCTL.OTGEN Position              */
#define USB_OTGCTL_OTGEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_OTGEN_SHIFT))&USB_OTGCTL_OTGEN_MASK) /**< USB0_OTGCTL.OTGEN Field                 */
#define USB_OTGCTL_DMLOW_MASK                    (0x10U)                                             /**< USB0_OTGCTL.DMLOW Mask                  */
#define USB_OTGCTL_DMLOW_SHIFT                   (4U)                                                /**< USB0_OTGCTL.DMLOW Position              */
#define USB_OTGCTL_DMLOW(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DMLOW_SHIFT))&USB_OTGCTL_DMLOW_MASK) /**< USB0_OTGCTL.DMLOW Field                 */
#define USB_OTGCTL_DPLOW_MASK                    (0x20U)                                             /**< USB0_OTGCTL.DPLOW Mask                  */
#define USB_OTGCTL_DPLOW_SHIFT                   (5U)                                                /**< USB0_OTGCTL.DPLOW Position              */
#define USB_OTGCTL_DPLOW(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DPLOW_SHIFT))&USB_OTGCTL_DPLOW_MASK) /**< USB0_OTGCTL.DPLOW Field                 */
#define USB_OTGCTL_DPHIGH_MASK                   (0x80U)                                             /**< USB0_OTGCTL.DPHIGH Mask                 */
#define USB_OTGCTL_DPHIGH_SHIFT                  (7U)                                                /**< USB0_OTGCTL.DPHIGH Position             */
#define USB_OTGCTL_DPHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DPHIGH_SHIFT))&USB_OTGCTL_DPHIGH_MASK) /**< USB0_OTGCTL.DPHIGH Field                */
/** @} */

/** @name ISTAT - Interrupt Status Register */ /** @{ */
#define USB_ISTAT_USBRST_MASK                    (0x1U)                                              /**< USB0_ISTAT.USBRST Mask                  */
#define USB_ISTAT_USBRST_SHIFT                   (0U)                                                /**< USB0_ISTAT.USBRST Position              */
#define USB_ISTAT_USBRST(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_USBRST_SHIFT))&USB_ISTAT_USBRST_MASK) /**< USB0_ISTAT.USBRST Field                 */
#define USB_ISTAT_ERROR_MASK                     (0x2U)                                              /**< USB0_ISTAT.ERROR Mask                   */
#define USB_ISTAT_ERROR_SHIFT                    (1U)                                                /**< USB0_ISTAT.ERROR Position               */
#define USB_ISTAT_ERROR(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_ERROR_SHIFT))&USB_ISTAT_ERROR_MASK) /**< USB0_ISTAT.ERROR Field                  */
#define USB_ISTAT_SOFTOK_MASK                    (0x4U)                                              /**< USB0_ISTAT.SOFTOK Mask                  */
#define USB_ISTAT_SOFTOK_SHIFT                   (2U)                                                /**< USB0_ISTAT.SOFTOK Position              */
#define USB_ISTAT_SOFTOK(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_SOFTOK_SHIFT))&USB_ISTAT_SOFTOK_MASK) /**< USB0_ISTAT.SOFTOK Field                 */
#define USB_ISTAT_TOKDNE_MASK                    (0x8U)                                              /**< USB0_ISTAT.TOKDNE Mask                  */
#define USB_ISTAT_TOKDNE_SHIFT                   (3U)                                                /**< USB0_ISTAT.TOKDNE Position              */
#define USB_ISTAT_TOKDNE(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_TOKDNE_SHIFT))&USB_ISTAT_TOKDNE_MASK) /**< USB0_ISTAT.TOKDNE Field                 */
#define USB_ISTAT_SLEEP_MASK                     (0x10U)                                             /**< USB0_ISTAT.SLEEP Mask                   */
#define USB_ISTAT_SLEEP_SHIFT                    (4U)                                                /**< USB0_ISTAT.SLEEP Position               */
#define USB_ISTAT_SLEEP(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_SLEEP_SHIFT))&USB_ISTAT_SLEEP_MASK) /**< USB0_ISTAT.SLEEP Field                  */
#define USB_ISTAT_RESUME_MASK                    (0x20U)                                             /**< USB0_ISTAT.RESUME Mask                  */
#define USB_ISTAT_RESUME_SHIFT                   (5U)                                                /**< USB0_ISTAT.RESUME Position              */
#define USB_ISTAT_RESUME(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_RESUME_SHIFT))&USB_ISTAT_RESUME_MASK) /**< USB0_ISTAT.RESUME Field                 */
#define USB_ISTAT_ATTACH_MASK                    (0x40U)                                             /**< USB0_ISTAT.ATTACH Mask                  */
#define USB_ISTAT_ATTACH_SHIFT                   (6U)                                                /**< USB0_ISTAT.ATTACH Position              */
#define USB_ISTAT_ATTACH(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_ATTACH_SHIFT))&USB_ISTAT_ATTACH_MASK) /**< USB0_ISTAT.ATTACH Field                 */
#define USB_ISTAT_STALL_MASK                     (0x80U)                                             /**< USB0_ISTAT.STALL Mask                   */
#define USB_ISTAT_STALL_SHIFT                    (7U)                                                /**< USB0_ISTAT.STALL Position               */
#define USB_ISTAT_STALL(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_STALL_SHIFT))&USB_ISTAT_STALL_MASK) /**< USB0_ISTAT.STALL Field                  */
/** @} */

/** @name INTEN - Interrupt Enable Register */ /** @{ */
#define USB_INTEN_USBRSTEN_MASK                  (0x1U)                                              /**< USB0_INTEN.USBRSTEN Mask                */
#define USB_INTEN_USBRSTEN_SHIFT                 (0U)                                                /**< USB0_INTEN.USBRSTEN Position            */
#define USB_INTEN_USBRSTEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_USBRSTEN_SHIFT))&USB_INTEN_USBRSTEN_MASK) /**< USB0_INTEN.USBRSTEN Field               */
#define USB_INTEN_ERROREN_MASK                   (0x2U)                                              /**< USB0_INTEN.ERROREN Mask                 */
#define USB_INTEN_ERROREN_SHIFT                  (1U)                                                /**< USB0_INTEN.ERROREN Position             */
#define USB_INTEN_ERROREN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_ERROREN_SHIFT))&USB_INTEN_ERROREN_MASK) /**< USB0_INTEN.ERROREN Field                */
#define USB_INTEN_SOFTOKEN_MASK                  (0x4U)                                              /**< USB0_INTEN.SOFTOKEN Mask                */
#define USB_INTEN_SOFTOKEN_SHIFT                 (2U)                                                /**< USB0_INTEN.SOFTOKEN Position            */
#define USB_INTEN_SOFTOKEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_SOFTOKEN_SHIFT))&USB_INTEN_SOFTOKEN_MASK) /**< USB0_INTEN.SOFTOKEN Field               */
#define USB_INTEN_TOKDNEEN_MASK                  (0x8U)                                              /**< USB0_INTEN.TOKDNEEN Mask                */
#define USB_INTEN_TOKDNEEN_SHIFT                 (3U)                                                /**< USB0_INTEN.TOKDNEEN Position            */
#define USB_INTEN_TOKDNEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_TOKDNEEN_SHIFT))&USB_INTEN_TOKDNEEN_MASK) /**< USB0_INTEN.TOKDNEEN Field               */
#define USB_INTEN_SLEEPEN_MASK                   (0x10U)                                             /**< USB0_INTEN.SLEEPEN Mask                 */
#define USB_INTEN_SLEEPEN_SHIFT                  (4U)                                                /**< USB0_INTEN.SLEEPEN Position             */
#define USB_INTEN_SLEEPEN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_SLEEPEN_SHIFT))&USB_INTEN_SLEEPEN_MASK) /**< USB0_INTEN.SLEEPEN Field                */
#define USB_INTEN_RESUMEEN_MASK                  (0x20U)                                             /**< USB0_INTEN.RESUMEEN Mask                */
#define USB_INTEN_RESUMEEN_SHIFT                 (5U)                                                /**< USB0_INTEN.RESUMEEN Position            */
#define USB_INTEN_RESUMEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_RESUMEEN_SHIFT))&USB_INTEN_RESUMEEN_MASK) /**< USB0_INTEN.RESUMEEN Field               */
#define USB_INTEN_ATTACHEN_MASK                  (0x40U)                                             /**< USB0_INTEN.ATTACHEN Mask                */
#define USB_INTEN_ATTACHEN_SHIFT                 (6U)                                                /**< USB0_INTEN.ATTACHEN Position            */
#define USB_INTEN_ATTACHEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_ATTACHEN_SHIFT))&USB_INTEN_ATTACHEN_MASK) /**< USB0_INTEN.ATTACHEN Field               */
#define USB_INTEN_STALLEN_MASK                   (0x80U)                                             /**< USB0_INTEN.STALLEN Mask                 */
#define USB_INTEN_STALLEN_SHIFT                  (7U)                                                /**< USB0_INTEN.STALLEN Position             */
#define USB_INTEN_STALLEN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_STALLEN_SHIFT))&USB_INTEN_STALLEN_MASK) /**< USB0_INTEN.STALLEN Field                */
/** @} */

/** @name ERRSTAT - Error Interrupt Status Register */ /** @{ */
#define USB_ERRSTAT_PIDERR_MASK                  (0x1U)                                              /**< USB0_ERRSTAT.PIDERR Mask                */
#define USB_ERRSTAT_PIDERR_SHIFT                 (0U)                                                /**< USB0_ERRSTAT.PIDERR Position            */
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_PIDERR_SHIFT))&USB_ERRSTAT_PIDERR_MASK) /**< USB0_ERRSTAT.PIDERR Field               */
#define USB_ERRSTAT_CRC5EOF_MASK                 (0x2U)                                              /**< USB0_ERRSTAT.CRC5EOF Mask               */
#define USB_ERRSTAT_CRC5EOF_SHIFT                (1U)                                                /**< USB0_ERRSTAT.CRC5EOF Position           */
#define USB_ERRSTAT_CRC5EOF(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_CRC5EOF_SHIFT))&USB_ERRSTAT_CRC5EOF_MASK) /**< USB0_ERRSTAT.CRC5EOF Field              */
#define USB_ERRSTAT_CRC16_MASK                   (0x4U)                                              /**< USB0_ERRSTAT.CRC16 Mask                 */
#define USB_ERRSTAT_CRC16_SHIFT                  (2U)                                                /**< USB0_ERRSTAT.CRC16 Position             */
#define USB_ERRSTAT_CRC16(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_CRC16_SHIFT))&USB_ERRSTAT_CRC16_MASK) /**< USB0_ERRSTAT.CRC16 Field                */
#define USB_ERRSTAT_DFN8_MASK                    (0x8U)                                              /**< USB0_ERRSTAT.DFN8 Mask                  */
#define USB_ERRSTAT_DFN8_SHIFT                   (3U)                                                /**< USB0_ERRSTAT.DFN8 Position              */
#define USB_ERRSTAT_DFN8(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_DFN8_SHIFT))&USB_ERRSTAT_DFN8_MASK) /**< USB0_ERRSTAT.DFN8 Field                 */
#define USB_ERRSTAT_BTOERR_MASK                  (0x10U)                                             /**< USB0_ERRSTAT.BTOERR Mask                */
#define USB_ERRSTAT_BTOERR_SHIFT                 (4U)                                                /**< USB0_ERRSTAT.BTOERR Position            */
#define USB_ERRSTAT_BTOERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_BTOERR_SHIFT))&USB_ERRSTAT_BTOERR_MASK) /**< USB0_ERRSTAT.BTOERR Field               */
#define USB_ERRSTAT_DMAERR_MASK                  (0x20U)                                             /**< USB0_ERRSTAT.DMAERR Mask                */
#define USB_ERRSTAT_DMAERR_SHIFT                 (5U)                                                /**< USB0_ERRSTAT.DMAERR Position            */
#define USB_ERRSTAT_DMAERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_DMAERR_SHIFT))&USB_ERRSTAT_DMAERR_MASK) /**< USB0_ERRSTAT.DMAERR Field               */
#define USB_ERRSTAT_BTSERR_MASK                  (0x80U)                                             /**< USB0_ERRSTAT.BTSERR Mask                */
#define USB_ERRSTAT_BTSERR_SHIFT                 (7U)                                                /**< USB0_ERRSTAT.BTSERR Position            */
#define USB_ERRSTAT_BTSERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_BTSERR_SHIFT))&USB_ERRSTAT_BTSERR_MASK) /**< USB0_ERRSTAT.BTSERR Field               */
/** @} */

/** @name ERREN - Error Interrupt Enable Register */ /** @{ */
#define USB_ERREN_PIDERREN_MASK                  (0x1U)                                              /**< USB0_ERREN.PIDERREN Mask                */
#define USB_ERREN_PIDERREN_SHIFT                 (0U)                                                /**< USB0_ERREN.PIDERREN Position            */
#define USB_ERREN_PIDERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_PIDERREN_SHIFT))&USB_ERREN_PIDERREN_MASK) /**< USB0_ERREN.PIDERREN Field               */
#define USB_ERREN_CRC5EOFEN_MASK                 (0x2U)                                              /**< USB0_ERREN.CRC5EOFEN Mask               */
#define USB_ERREN_CRC5EOFEN_SHIFT                (1U)                                                /**< USB0_ERREN.CRC5EOFEN Position           */
#define USB_ERREN_CRC5EOFEN(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ERREN_CRC5EOFEN_SHIFT))&USB_ERREN_CRC5EOFEN_MASK) /**< USB0_ERREN.CRC5EOFEN Field              */
#define USB_ERREN_CRC16EN_MASK                   (0x4U)                                              /**< USB0_ERREN.CRC16EN Mask                 */
#define USB_ERREN_CRC16EN_SHIFT                  (2U)                                                /**< USB0_ERREN.CRC16EN Position             */
#define USB_ERREN_CRC16EN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ERREN_CRC16EN_SHIFT))&USB_ERREN_CRC16EN_MASK) /**< USB0_ERREN.CRC16EN Field                */
#define USB_ERREN_DFN8EN_MASK                    (0x8U)                                              /**< USB0_ERREN.DFN8EN Mask                  */
#define USB_ERREN_DFN8EN_SHIFT                   (3U)                                                /**< USB0_ERREN.DFN8EN Position              */
#define USB_ERREN_DFN8EN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ERREN_DFN8EN_SHIFT))&USB_ERREN_DFN8EN_MASK) /**< USB0_ERREN.DFN8EN Field                 */
#define USB_ERREN_BTOERREN_MASK                  (0x10U)                                             /**< USB0_ERREN.BTOERREN Mask                */
#define USB_ERREN_BTOERREN_SHIFT                 (4U)                                                /**< USB0_ERREN.BTOERREN Position            */
#define USB_ERREN_BTOERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_BTOERREN_SHIFT))&USB_ERREN_BTOERREN_MASK) /**< USB0_ERREN.BTOERREN Field               */
#define USB_ERREN_DMAERREN_MASK                  (0x20U)                                             /**< USB0_ERREN.DMAERREN Mask                */
#define USB_ERREN_DMAERREN_SHIFT                 (5U)                                                /**< USB0_ERREN.DMAERREN Position            */
#define USB_ERREN_DMAERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_DMAERREN_SHIFT))&USB_ERREN_DMAERREN_MASK) /**< USB0_ERREN.DMAERREN Field               */
#define USB_ERREN_BTSERREN_MASK                  (0x80U)                                             /**< USB0_ERREN.BTSERREN Mask                */
#define USB_ERREN_BTSERREN_SHIFT                 (7U)                                                /**< USB0_ERREN.BTSERREN Position            */
#define USB_ERREN_BTSERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_BTSERREN_SHIFT))&USB_ERREN_BTSERREN_MASK) /**< USB0_ERREN.BTSERREN Field               */
/** @} */

/** @name STAT - Status Register */ /** @{ */
#define USB_STAT_ODD_MASK                        (0x4U)                                              /**< USB0_STAT.ODD Mask                      */
#define USB_STAT_ODD_SHIFT                       (2U)                                                /**< USB0_STAT.ODD Position                  */
#define USB_STAT_ODD(x)                          (((uint8_t)(((uint8_t)(x))<<USB_STAT_ODD_SHIFT))&USB_STAT_ODD_MASK) /**< USB0_STAT.ODD Field                     */
#define USB_STAT_TX_MASK                         (0x8U)                                              /**< USB0_STAT.TX Mask                       */
#define USB_STAT_TX_SHIFT                        (3U)                                                /**< USB0_STAT.TX Position                   */
#define USB_STAT_TX(x)                           (((uint8_t)(((uint8_t)(x))<<USB_STAT_TX_SHIFT))&USB_STAT_TX_MASK) /**< USB0_STAT.TX Field                      */
#define USB_STAT_ENDP_MASK                       (0xF0U)                                             /**< USB0_STAT.ENDP Mask                     */
#define USB_STAT_ENDP_SHIFT                      (4U)                                                /**< USB0_STAT.ENDP Position                 */
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<USB_STAT_ENDP_SHIFT))&USB_STAT_ENDP_MASK) /**< USB0_STAT.ENDP Field                    */
/** @} */

/** @name CTL - Control Register */ /** @{ */
#define USB_CTL_USBENSOFEN_MASK                  (0x1U)                                              /**< USB0_CTL.USBENSOFEN Mask                */
#define USB_CTL_USBENSOFEN_SHIFT                 (0U)                                                /**< USB0_CTL.USBENSOFEN Position            */
#define USB_CTL_USBENSOFEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_CTL_USBENSOFEN_SHIFT))&USB_CTL_USBENSOFEN_MASK) /**< USB0_CTL.USBENSOFEN Field               */
#define USB_CTL_ODDRST_MASK                      (0x2U)                                              /**< USB0_CTL.ODDRST Mask                    */
#define USB_CTL_ODDRST_SHIFT                     (1U)                                                /**< USB0_CTL.ODDRST Position                */
#define USB_CTL_ODDRST(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_ODDRST_SHIFT))&USB_CTL_ODDRST_MASK) /**< USB0_CTL.ODDRST Field                   */
#define USB_CTL_RESUME_MASK                      (0x4U)                                              /**< USB0_CTL.RESUME Mask                    */
#define USB_CTL_RESUME_SHIFT                     (2U)                                                /**< USB0_CTL.RESUME Position                */
#define USB_CTL_RESUME(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_RESUME_SHIFT))&USB_CTL_RESUME_MASK) /**< USB0_CTL.RESUME Field                   */
#define USB_CTL_HOSTMODEEN_MASK                  (0x8U)                                              /**< USB0_CTL.HOSTMODEEN Mask                */
#define USB_CTL_HOSTMODEEN_SHIFT                 (3U)                                                /**< USB0_CTL.HOSTMODEEN Position            */
#define USB_CTL_HOSTMODEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_CTL_HOSTMODEEN_SHIFT))&USB_CTL_HOSTMODEEN_MASK) /**< USB0_CTL.HOSTMODEEN Field               */
#define USB_CTL_RESET_MASK                       (0x10U)                                             /**< USB0_CTL.RESET Mask                     */
#define USB_CTL_RESET_SHIFT                      (4U)                                                /**< USB0_CTL.RESET Position                 */
#define USB_CTL_RESET(x)                         (((uint8_t)(((uint8_t)(x))<<USB_CTL_RESET_SHIFT))&USB_CTL_RESET_MASK) /**< USB0_CTL.RESET Field                    */
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          (0x20U)                                             /**< USB0_CTL.TXSUSPENDTOKENBUSY Mask        */
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         (5U)                                                /**< USB0_CTL.TXSUSPENDTOKENBUSY Position    */
#define USB_CTL_TXSUSPENDTOKENBUSY(x)            (((uint8_t)(((uint8_t)(x))<<USB_CTL_TXSUSPENDTOKENBUSY_SHIFT))&USB_CTL_TXSUSPENDTOKENBUSY_MASK) /**< USB0_CTL.TXSUSPENDTOKENBUSY Field       */
#define USB_CTL_SE0_MASK                         (0x40U)                                             /**< USB0_CTL.SE0 Mask                       */
#define USB_CTL_SE0_SHIFT                        (6U)                                                /**< USB0_CTL.SE0 Position                   */
#define USB_CTL_SE0(x)                           (((uint8_t)(((uint8_t)(x))<<USB_CTL_SE0_SHIFT))&USB_CTL_SE0_MASK) /**< USB0_CTL.SE0 Field                      */
#define USB_CTL_JSTATE_MASK                      (0x80U)                                             /**< USB0_CTL.JSTATE Mask                    */
#define USB_CTL_JSTATE_SHIFT                     (7U)                                                /**< USB0_CTL.JSTATE Position                */
#define USB_CTL_JSTATE(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_JSTATE_SHIFT))&USB_CTL_JSTATE_MASK) /**< USB0_CTL.JSTATE Field                   */
/** @} */

/** @name ADDR - Address Register */ /** @{ */
#define USB_ADDR_ADDR_MASK                       (0x7FU)                                             /**< USB0_ADDR.ADDR Mask                     */
#define USB_ADDR_ADDR_SHIFT                      (0U)                                                /**< USB0_ADDR.ADDR Position                 */
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_ADDR_SHIFT))&USB_ADDR_ADDR_MASK) /**< USB0_ADDR.ADDR Field                    */
#define USB_ADDR_LSEN_MASK                       (0x80U)                                             /**< USB0_ADDR.LSEN Mask                     */
#define USB_ADDR_LSEN_SHIFT                      (7U)                                                /**< USB0_ADDR.LSEN Position                 */
#define USB_ADDR_LSEN(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_LSEN_SHIFT))&USB_ADDR_LSEN_MASK) /**< USB0_ADDR.LSEN Field                    */
/** @} */

/** @name BDTPAGE1 - BDT Page Register 1 */ /** @{ */
#define USB_BDTPAGE1_BDTBA_MASK                  (0xFEU)                                             /**< USB0_BDTPAGE1.BDTBA Mask                */
#define USB_BDTPAGE1_BDTBA_SHIFT                 (1U)                                                /**< USB0_BDTPAGE1.BDTBA Position            */
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE1_BDTBA_SHIFT))&USB_BDTPAGE1_BDTBA_MASK) /**< USB0_BDTPAGE1.BDTBA Field               */
/** @} */

/** @name FRMNUML - Frame Number Register Low */ /** @{ */
#define USB_FRMNUML_FRM_MASK                     (0xFFU)                                             /**< USB0_FRMNUML.FRM Mask                   */
#define USB_FRMNUML_FRM_SHIFT                    (0U)                                                /**< USB0_FRMNUML.FRM Position               */
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUML_FRM_SHIFT))&USB_FRMNUML_FRM_MASK) /**< USB0_FRMNUML.FRM Field                  */
/** @} */

/** @name FRMNUMH - Frame Number Register High */ /** @{ */
#define USB_FRMNUMH_FRM_MASK                     (0x7U)                                              /**< USB0_FRMNUMH.FRM Mask                   */
#define USB_FRMNUMH_FRM_SHIFT                    (0U)                                                /**< USB0_FRMNUMH.FRM Position               */
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUMH_FRM_SHIFT))&USB_FRMNUMH_FRM_MASK) /**< USB0_FRMNUMH.FRM Field                  */
/** @} */

/** @name TOKEN - Token Register */ /** @{ */
#define USB_TOKEN_TOKENENDPT_MASK                (0xFU)                                              /**< USB0_TOKEN.TOKENENDPT Mask              */
#define USB_TOKEN_TOKENENDPT_SHIFT               (0U)                                                /**< USB0_TOKEN.TOKENENDPT Position          */
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENENDPT_SHIFT))&USB_TOKEN_TOKENENDPT_MASK) /**< USB0_TOKEN.TOKENENDPT Field             */
#define USB_TOKEN_TOKENPID_MASK                  (0xF0U)                                             /**< USB0_TOKEN.TOKENPID Mask                */
#define USB_TOKEN_TOKENPID_SHIFT                 (4U)                                                /**< USB0_TOKEN.TOKENPID Position            */
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENPID_SHIFT))&USB_TOKEN_TOKENPID_MASK) /**< USB0_TOKEN.TOKENPID Field               */
/** @} */

/** @name SOFTHLD - SOF Threshold Register */ /** @{ */
#define USB_SOFTHLD_CNT_MASK                     (0xFFU)                                             /**< USB0_SOFTHLD.CNT Mask                   */
#define USB_SOFTHLD_CNT_SHIFT                    (0U)                                                /**< USB0_SOFTHLD.CNT Position               */
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<USB_SOFTHLD_CNT_SHIFT))&USB_SOFTHLD_CNT_MASK) /**< USB0_SOFTHLD.CNT Field                  */
/** @} */

/** @name BDTPAGE2 - BDT Page Register 2 */ /** @{ */
#define USB_BDTPAGE2_BDTBA_MASK                  (0xFFU)                                             /**< USB0_BDTPAGE2.BDTBA Mask                */
#define USB_BDTPAGE2_BDTBA_SHIFT                 (0U)                                                /**< USB0_BDTPAGE2.BDTBA Position            */
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE2_BDTBA_SHIFT))&USB_BDTPAGE2_BDTBA_MASK) /**< USB0_BDTPAGE2.BDTBA Field               */
/** @} */

/** @name BDTPAGE3 - BDT Page Register 3 */ /** @{ */
#define USB_BDTPAGE3_BDTBA_MASK                  (0xFFU)                                             /**< USB0_BDTPAGE3.BDTBA Mask                */
#define USB_BDTPAGE3_BDTBA_SHIFT                 (0U)                                                /**< USB0_BDTPAGE3.BDTBA Position            */
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE3_BDTBA_SHIFT))&USB_BDTPAGE3_BDTBA_MASK) /**< USB0_BDTPAGE3.BDTBA Field               */
/** @} */

/** @name ENDPT - Endpoint Control Register */ /** @{ */
#define USB_ENDPT_EPHSHK_MASK                    (0x1U)                                              /**< USB0_ENDPT.EPHSHK Mask                  */
#define USB_ENDPT_EPHSHK_SHIFT                   (0U)                                                /**< USB0_ENDPT.EPHSHK Position              */
#define USB_ENDPT_EPHSHK(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPHSHK_SHIFT))&USB_ENDPT_EPHSHK_MASK) /**< USB0_ENDPT.EPHSHK Field                 */
#define USB_ENDPT_EPSTALL_MASK                   (0x2U)                                              /**< USB0_ENDPT.EPSTALL Mask                 */
#define USB_ENDPT_EPSTALL_SHIFT                  (1U)                                                /**< USB0_ENDPT.EPSTALL Position             */
#define USB_ENDPT_EPSTALL(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPSTALL_SHIFT))&USB_ENDPT_EPSTALL_MASK) /**< USB0_ENDPT.EPSTALL Field                */
#define USB_ENDPT_EPTXEN_MASK                    (0x4U)                                              /**< USB0_ENDPT.EPTXEN Mask                  */
#define USB_ENDPT_EPTXEN_SHIFT                   (2U)                                                /**< USB0_ENDPT.EPTXEN Position              */
#define USB_ENDPT_EPTXEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPTXEN_SHIFT))&USB_ENDPT_EPTXEN_MASK) /**< USB0_ENDPT.EPTXEN Field                 */
#define USB_ENDPT_EPRXEN_MASK                    (0x8U)                                              /**< USB0_ENDPT.EPRXEN Mask                  */
#define USB_ENDPT_EPRXEN_SHIFT                   (3U)                                                /**< USB0_ENDPT.EPRXEN Position              */
#define USB_ENDPT_EPRXEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPRXEN_SHIFT))&USB_ENDPT_EPRXEN_MASK) /**< USB0_ENDPT.EPRXEN Field                 */
#define USB_ENDPT_EPCTLDIS_MASK                  (0x10U)                                             /**< USB0_ENDPT.EPCTLDIS Mask                */
#define USB_ENDPT_EPCTLDIS_SHIFT                 (4U)                                                /**< USB0_ENDPT.EPCTLDIS Position            */
#define USB_ENDPT_EPCTLDIS(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPCTLDIS_SHIFT))&USB_ENDPT_EPCTLDIS_MASK) /**< USB0_ENDPT.EPCTLDIS Field               */
#define USB_ENDPT_RETRYDIS_MASK                  (0x40U)                                             /**< USB0_ENDPT.RETRYDIS Mask                */
#define USB_ENDPT_RETRYDIS_SHIFT                 (6U)                                                /**< USB0_ENDPT.RETRYDIS Position            */
#define USB_ENDPT_RETRYDIS(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_RETRYDIS_SHIFT))&USB_ENDPT_RETRYDIS_MASK) /**< USB0_ENDPT.RETRYDIS Field               */
#define USB_ENDPT_HOSTWOHUB_MASK                 (0x80U)                                             /**< USB0_ENDPT.HOSTWOHUB Mask               */
#define USB_ENDPT_HOSTWOHUB_SHIFT                (7U)                                                /**< USB0_ENDPT.HOSTWOHUB Position           */
#define USB_ENDPT_HOSTWOHUB(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_HOSTWOHUB_SHIFT))&USB_ENDPT_HOSTWOHUB_MASK) /**< USB0_ENDPT.HOSTWOHUB Field              */
/** @} */

/** @name USBCTRL - USB Control Register */ /** @{ */
#define USB_USBCTRL_PDE_MASK                     (0x40U)                                             /**< USB0_USBCTRL.PDE Mask                   */
#define USB_USBCTRL_PDE_SHIFT                    (6U)                                                /**< USB0_USBCTRL.PDE Position               */
#define USB_USBCTRL_PDE(x)                       (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_PDE_SHIFT))&USB_USBCTRL_PDE_MASK) /**< USB0_USBCTRL.PDE Field                  */
#define USB_USBCTRL_SUSP_MASK                    (0x80U)                                             /**< USB0_USBCTRL.SUSP Mask                  */
#define USB_USBCTRL_SUSP_SHIFT                   (7U)                                                /**< USB0_USBCTRL.SUSP Position              */
#define USB_USBCTRL_SUSP(x)                      (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_SUSP_SHIFT))&USB_USBCTRL_SUSP_MASK) /**< USB0_USBCTRL.SUSP Field                 */
/** @} */

/** @name OBSERVE - USB OTG Observe Register */ /** @{ */
#define USB_OBSERVE_DMPD_MASK                    (0x10U)                                             /**< USB0_OBSERVE.DMPD Mask                  */
#define USB_OBSERVE_DMPD_SHIFT                   (4U)                                                /**< USB0_OBSERVE.DMPD Position              */
#define USB_OBSERVE_DMPD(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DMPD_SHIFT))&USB_OBSERVE_DMPD_MASK) /**< USB0_OBSERVE.DMPD Field                 */
#define USB_OBSERVE_DPPD_MASK                    (0x40U)                                             /**< USB0_OBSERVE.DPPD Mask                  */
#define USB_OBSERVE_DPPD_SHIFT                   (6U)                                                /**< USB0_OBSERVE.DPPD Position              */
#define USB_OBSERVE_DPPD(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DPPD_SHIFT))&USB_OBSERVE_DPPD_MASK) /**< USB0_OBSERVE.DPPD Field                 */
#define USB_OBSERVE_DPPU_MASK                    (0x80U)                                             /**< USB0_OBSERVE.DPPU Mask                  */
#define USB_OBSERVE_DPPU_SHIFT                   (7U)                                                /**< USB0_OBSERVE.DPPU Position              */
#define USB_OBSERVE_DPPU(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DPPU_SHIFT))&USB_OBSERVE_DPPU_MASK) /**< USB0_OBSERVE.DPPU Field                 */
/** @} */

/** @name CONTROL - USB OTG Control Register */ /** @{ */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          (0x10U)                                             /**< USB0_CONTROL.DPPULLUPNONOTG Mask        */
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         (4U)                                                /**< USB0_CONTROL.DPPULLUPNONOTG Position    */
#define USB_CONTROL_DPPULLUPNONOTG(x)            (((uint8_t)(((uint8_t)(x))<<USB_CONTROL_DPPULLUPNONOTG_SHIFT))&USB_CONTROL_DPPULLUPNONOTG_MASK) /**< USB0_CONTROL.DPPULLUPNONOTG Field       */
/** @} */

/** @name USBTRC0 - USB Transceiver Control Register 0 */ /** @{ */
#define USB_USBTRC0_USB_RESUME_INT_MASK          (0x1U)                                              /**< USB0_USBTRC0.USB_RESUME_INT Mask        */
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         (0U)                                                /**< USB0_USBTRC0.USB_RESUME_INT Position    */
#define USB_USBTRC0_USB_RESUME_INT(x)            (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USB_RESUME_INT_SHIFT))&USB_USBTRC0_USB_RESUME_INT_MASK) /**< USB0_USBTRC0.USB_RESUME_INT Field       */
#define USB_USBTRC0_SYNC_DET_MASK                (0x2U)                                              /**< USB0_USBTRC0.SYNC_DET Mask              */
#define USB_USBTRC0_SYNC_DET_SHIFT               (1U)                                                /**< USB0_USBTRC0.SYNC_DET Position          */
#define USB_USBTRC0_SYNC_DET(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_SYNC_DET_SHIFT))&USB_USBTRC0_SYNC_DET_MASK) /**< USB0_USBTRC0.SYNC_DET Field             */
#define USB_USBTRC0_USBRESMEN_MASK               (0x20U)                                             /**< USB0_USBTRC0.USBRESMEN Mask             */
#define USB_USBTRC0_USBRESMEN_SHIFT              (5U)                                                /**< USB0_USBTRC0.USBRESMEN Position         */
#define USB_USBTRC0_USBRESMEN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USBRESMEN_SHIFT))&USB_USBTRC0_USBRESMEN_MASK) /**< USB0_USBTRC0.USBRESMEN Field            */
#define USB_USBTRC0_USBRESET_MASK                (0x80U)                                             /**< USB0_USBTRC0.USBRESET Mask              */
#define USB_USBTRC0_USBRESET_SHIFT               (7U)                                                /**< USB0_USBTRC0.USBRESET Position          */
#define USB_USBTRC0_USBRESET(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USBRESET_SHIFT))&USB_USBTRC0_USBRESET_MASK) /**< USB0_USBTRC0.USBRESET Field             */
/** @} */

/** @name USBFRMADJUST - Frame Adjust Register */ /** @{ */
#define USB_USBFRMADJUST_ADJ_MASK                (0xFFU)                                             /**< USB0_USBFRMADJUST.ADJ Mask              */
#define USB_USBFRMADJUST_ADJ_SHIFT               (0U)                                                /**< USB0_USBFRMADJUST.ADJ Position          */
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBFRMADJUST_ADJ_SHIFT))&USB_USBFRMADJUST_ADJ_MASK) /**< USB0_USBFRMADJUST.ADJ Field             */
/** @} */

/** @} */ /* End group USB_Register_Masks_GROUP */


/* USB0 - Peripheral instance base addresses */
#define USB0_BasePtr                   0x40072000UL //!< Peripheral base address
#define USB0                           ((USB_Type *) USB0_BasePtr) //!< Freescale base pointer
#define USB0_BASE_PTR                  (USB0) //!< Freescale style base pointer
#define USB0_IRQS { USB0_IRQn,  }


/** @} */ /* End group USB_Peripheral_access_layer_GROUP */

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


#endif  /* MCU_MKL25Z4 */

