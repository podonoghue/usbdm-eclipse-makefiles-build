/*!
 * @file     MKL27Z644.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKL27Z644.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2025/02
 *
 */

#ifndef _MKL27Z644_H_
#define _MKL27Z644_H_

#define MCU_MKL27Z644

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
  NMI_IRQn                      = -14,   /**<   2 Non maskable Interrupt, cannot be stopped or preempted                           */
  HardFault_IRQn                = -13,   /**<   3 Hard Fault, all classes of Fault                                                 */
  SVC_IRQn                      =  -5,   /**<  11 System Service Call via SVC instruction                                          */
  PendSV_IRQn                   =  -2,   /**<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /**<  15 System Tick Timer                                                                */
/* ----------------------   MKL27Z4 (32K and 64K) VectorTable        ---------------------- */
  DMA0_Ch0_IRQn                 =   0,   /**<  16 Direct memory access controller                                                  */
  DMA0_Ch1_IRQn                 =   1,   /**<  17 Direct memory access controller                                                  */
  DMA0_Ch2_IRQn                 =   2,   /**<  18 Direct memory access controller                                                  */
  DMA0_Ch3_IRQn                 =   3,   /**<  19 Direct memory access controller                                                  */
  FTFA_IRQn                     =   5,   /**<  21 Flash Memory Interface                                                           */
  PMC_IRQn                      =   6,   /**<  22 Power Management Controller                                                      */
  LLWU_IRQn                     =   7,   /**<  23 Low Leakage Wakeup                                                               */
  I2C0_IRQn                     =   8,   /**<  24 Inter-Integrated Circuit                                                         */
  I2C1_IRQn                     =   9,   /**<  25 Inter-Integrated Circuit                                                         */
  SPI0_IRQn                     =  10,   /**<  26 Serial Peripheral Interface                                                      */
  SPI1_IRQn                     =  11,   /**<  27 Serial Peripheral Interface                                                      */
  LPUART0_IRQn                  =  12,   /**<  28 Serial Communication Interface                                                   */
  LPUART1_IRQn                  =  13,   /**<  29 Serial Communication Interface                                                   */
  UART2_FLEXIO_IRQn             =  14,   /**<  30 UART2 or FLEXIO Status and error                                                 */
  ADC0_IRQn                     =  15,   /**<  31 Analogue to Digital Converter                                                    */
  CMP0_IRQn                     =  16,   /**<  32 High-Speed Comparator                                                            */
  TPM0_IRQn                     =  17,   /**<  33 Timer/PWM Module                                                                 */
  TPM1_IRQn                     =  18,   /**<  34 Timer/PWM Module                                                                 */
  TPM2_IRQn                     =  19,   /**<  35 Timer/PWM Module                                                                 */
  RTC_Alarm_IRQn                =  20,   /**<  36 Real Time Clock                                                                  */
  RTC_Seconds_IRQn              =  21,   /**<  37 Real Time Clock                                                                  */
  PIT_IRQn                      =  22,   /**<  38 Periodic Interrupt Timer (All channels)                                          */
  USB0_IRQn                     =  24,   /**<  40 Universal Serial Bus                                                             */
  LPTMR0_IRQn                   =  28,   /**<  44 Low Power Timer                                                                  */
  PORTA_IRQn                    =  30,   /**<  46 General Purpose Input/Output                                                     */
  PORTBCDE_IRQn                 =  31,   /**<  47 General Purpose Input/Output                                                     */
} IRQn_Type;


/** @brief Prototypes for interrupt handlers */
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                       /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);                 /**< Hard Fault, all classes of Fault                                                 */
extern void SVC_Handler(void);                       /**< System Service Call via SVC instruction                                          */
extern void PendSV_Handler(void);                    /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);                   /**< System Tick Timer                                                                */
extern void DMA0_Ch0_IRQHandler(void);               /**< Direct memory access controller                                                  */
extern void DMA0_Ch1_IRQHandler(void);               /**< Direct memory access controller                                                  */
extern void DMA0_Ch2_IRQHandler(void);               /**< Direct memory access controller                                                  */
extern void DMA0_Ch3_IRQHandler(void);               /**< Direct memory access controller                                                  */
extern void FTFA_IRQHandler(void);                   /**< Flash Memory Interface                                                           */
extern void PMC_IRQHandler(void);                    /**< Power Management Controller                                                      */
extern void LLWU_IRQHandler(void);                   /**< Low Leakage Wakeup                                                               */
extern void I2C0_IRQHandler(void);                   /**< Inter-Integrated Circuit                                                         */
extern void I2C1_IRQHandler(void);                   /**< Inter-Integrated Circuit                                                         */
extern void SPI0_IRQHandler(void);                   /**< Serial Peripheral Interface                                                      */
extern void SPI1_IRQHandler(void);                   /**< Serial Peripheral Interface                                                      */
extern void LPUART0_IRQHandler(void);                /**< Serial Communication Interface                                                   */
extern void LPUART1_IRQHandler(void);                /**< Serial Communication Interface                                                   */
extern void UART2_FLEXIO_IRQHandler(void);           /**< UART2 or FLEXIO Status and error                                                 */
extern void ADC0_IRQHandler(void);                   /**< Analogue to Digital Converter                                                    */
extern void CMP0_IRQHandler(void);                   /**< High-Speed Comparator                                                            */
extern void TPM0_IRQHandler(void);                   /**< Timer/PWM Module                                                                 */
extern void TPM1_IRQHandler(void);                   /**< Timer/PWM Module                                                                 */
extern void TPM2_IRQHandler(void);                   /**< Timer/PWM Module                                                                 */
extern void RTC_Alarm_IRQHandler(void);              /**< Real Time Clock                                                                  */
extern void RTC_Seconds_IRQHandler(void);            /**< Real Time Clock                                                                  */
extern void PIT_IRQHandler(void);                    /**< Periodic Interrupt Timer (All channels)                                          */
extern void USB0_IRQHandler(void);                   /**< Universal Serial Bus                                                             */
extern void LPTMR0_IRQHandler(void);                 /**< Low Power Timer                                                                  */
extern void PORTA_IRQHandler(void);                  /**< General Purpose Input/Output                                                     */
extern void PORTBCDE_IRQHandler(void);               /**< General Purpose Input/Output                                                     */


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


/** @brief C Struct for CRC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           CRC0 (file:CRC0_0x40032000)          ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check
 */
/**
 * @struct CRC_Type
 * @brief  C Struct allowing access to CRC registers
 */
typedef struct CRC_Type {
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DATA;                      /**< 0000: Data register                                                */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAL;               /**< 0000: DATAL register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATALL;           /**< 0000: DATALL register                                              */
               __IO uint8_t   DATALU;           /**< 0001: DATALU register                                              */
            };
         };
         union {                                /**< 0002: (size=0002)                                                  */
            __IO uint16_t  DATAH;               /**< 0002: DATAH register                                               */
            struct {                            /**< 0002: (size=0002)                                                  */
               __IO uint8_t   DATAHL;           /**< 0002: DATAHL register                                              */
               __IO uint8_t   DATAHU;           /**< 0003: DATAHU register                                              */
            };
         };
      };
   };
   union {                                      /**< 0004: (size=0004)                                                  */
      __IO uint32_t  GPOLY;                     /**< 0004: Polynomial register                                          */
      struct {                                  /**< 0004: (size=0004)                                                  */
         __IO uint16_t  GPOLYL;                 /**< 0004: GPOLYL register                                              */
         __IO uint16_t  GPOLYH;                 /**< 0006: GPOLYH register                                              */
      };
   };
   union {                                      /**< 0008: (size=0004)                                                  */
      __IO uint32_t  CTRL;                      /**< 0008: Control register                                             */
      struct {                                  /**< 0008: (size=0004)                                                  */
              uint8_t   RESERVED_4[3];          /**< 0008: 0x3 bytes                                                    */
         __IO uint8_t   CTRLHU;                 /**< 000B: Control register (byte access)                               */
      };
   };
} CRC_Type;


/** @brief Register Masks for CRC */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup CRC_Register_Masks_GROUP CRC Register Masks */
/** @{ */

/** @name DATA - Data register */ /** @{ */
#define CRC_DATA_DATA_MASK                       (0xFFFFFFFFU)                                       /**< CRC0_DATA.DATA Mask                     */
#define CRC_DATA_DATA_SHIFT                      (0U)                                                /**< CRC0_DATA.DATA Position                 */
#define CRC_DATA_DATA(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_DATA_DATA_SHIFT))&CRC_DATA_DATA_MASK) /**< CRC0_DATA.DATA Field                    */
#define CRC_DATA_LL_MASK                         (0xFFU)                                             /**< CRC0_DATA.LL Mask                       */
#define CRC_DATA_LL_SHIFT                        (0U)                                                /**< CRC0_DATA.LL Position                   */
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK) /**< CRC0_DATA.LL Field                      */
#define CRC_DATA_LU_MASK                         (0xFF00U)                                           /**< CRC0_DATA.LU Mask                       */
#define CRC_DATA_LU_SHIFT                        (8U)                                                /**< CRC0_DATA.LU Position                   */
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK) /**< CRC0_DATA.LU Field                      */
#define CRC_DATA_HL_MASK                         (0xFF0000U)                                         /**< CRC0_DATA.HL Mask                       */
#define CRC_DATA_HL_SHIFT                        (16U)                                               /**< CRC0_DATA.HL Position                   */
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK) /**< CRC0_DATA.HL Field                      */
#define CRC_DATA_HU_MASK                         (0xFF000000U)                                       /**< CRC0_DATA.HU Mask                       */
#define CRC_DATA_HU_SHIFT                        (24U)                                               /**< CRC0_DATA.HU Position                   */
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK) /**< CRC0_DATA.HU Field                      */
/** @} */

/** @name DATAL - DATAL register */ /** @{ */
#define CRC_DATAL_DATAL_MASK                     (0xFFFFU)                                           /**< CRC0_DATAL.DATAL Mask                   */
#define CRC_DATAL_DATAL_SHIFT                    (0U)                                                /**< CRC0_DATAL.DATAL Position               */
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK) /**< CRC0_DATAL.DATAL Field                  */
/** @} */

/** @name DATALL - DATALL register */ /** @{ */
#define CRC_DATALL_DATALL_MASK                   (0xFFU)                                             /**< CRC0_DATALL.DATALL Mask                 */
#define CRC_DATALL_DATALL_SHIFT                  (0U)                                                /**< CRC0_DATALL.DATALL Position             */
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALL_DATALL_SHIFT))&CRC_DATALL_DATALL_MASK) /**< CRC0_DATALL.DATALL Field                */
/** @} */

/** @name DATALU - DATALU register */ /** @{ */
#define CRC_DATALU_DATALU_MASK                   (0xFFU)                                             /**< CRC0_DATALU.DATALU Mask                 */
#define CRC_DATALU_DATALU_SHIFT                  (0U)                                                /**< CRC0_DATALU.DATALU Position             */
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALU_DATALU_SHIFT))&CRC_DATALU_DATALU_MASK) /**< CRC0_DATALU.DATALU Field                */
/** @} */

/** @name DATAH - DATAH register */ /** @{ */
#define CRC_DATAH_DATAH_MASK                     (0xFFFFU)                                           /**< CRC0_DATAH.DATAH Mask                   */
#define CRC_DATAH_DATAH_SHIFT                    (0U)                                                /**< CRC0_DATAH.DATAH Position               */
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK) /**< CRC0_DATAH.DATAH Field                  */
/** @} */

/** @name DATAHL - DATAHL register */ /** @{ */
#define CRC_DATAHL_DATAHL_MASK                   (0xFFU)                                             /**< CRC0_DATAHL.DATAHL Mask                 */
#define CRC_DATAHL_DATAHL_SHIFT                  (0U)                                                /**< CRC0_DATAHL.DATAHL Position             */
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHL_DATAHL_SHIFT))&CRC_DATAHL_DATAHL_MASK) /**< CRC0_DATAHL.DATAHL Field                */
/** @} */

/** @name DATAHU - DATAHU register */ /** @{ */
#define CRC_DATAHU_DATAHU_MASK                   (0xFFU)                                             /**< CRC0_DATAHU.DATAHU Mask                 */
#define CRC_DATAHU_DATAHU_SHIFT                  (0U)                                                /**< CRC0_DATAHU.DATAHU Position             */
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHU_DATAHU_SHIFT))&CRC_DATAHU_DATAHU_MASK) /**< CRC0_DATAHU.DATAHU Field                */
/** @} */

/** @name GPOLY - Polynomial register */ /** @{ */
#define CRC_GPOLY_GPOLY_MASK                     (0xFFFFFFFFU)                                       /**< CRC0_GPOLY.GPOLY Mask                   */
#define CRC_GPOLY_GPOLY_SHIFT                    (0U)                                                /**< CRC0_GPOLY.GPOLY Position               */
#define CRC_GPOLY_GPOLY(x)                       (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_GPOLY_SHIFT))&CRC_GPOLY_GPOLY_MASK) /**< CRC0_GPOLY.GPOLY Field                  */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFU)                                           /**< CRC0_GPOLY.LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      (0U)                                                /**< CRC0_GPOLY.LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK) /**< CRC0_GPOLY.LOW Field                    */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000U)                                       /**< CRC0_GPOLY.HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     (16U)                                               /**< CRC0_GPOLY.HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK) /**< CRC0_GPOLY.HIGH Field                   */
/** @} */

/** @name GPOLYL - GPOLYL register */ /** @{ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFU)                                           /**< CRC0_GPOLYL.GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  (0U)                                                /**< CRC0_GPOLYL.GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK) /**< CRC0_GPOLYL.GPOLYL Field                */
/** @} */

/** @name GPOLYH - GPOLYH register */ /** @{ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFU)                                           /**< CRC0_GPOLYH.GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  (0U)                                                /**< CRC0_GPOLYH.GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK) /**< CRC0_GPOLYH.GPOLYH Field                */
/** @} */

/** @name CTRL - Control register */ /** @{ */
#define CRC_CTRL_TCRC_MASK                       (0x1000000U)                                        /**< CRC0_CTRL.TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      (24U)                                               /**< CRC0_CTRL.TCRC Position                 */
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TCRC_SHIFT))&CRC_CTRL_TCRC_MASK) /**< CRC0_CTRL.TCRC Field                    */
#define CRC_CTRL_WAS_MASK                        (0x2000000U)                                        /**< CRC0_CTRL.WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       (25U)                                               /**< CRC0_CTRL.WAS Position                  */
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_WAS_SHIFT))&CRC_CTRL_WAS_MASK) /**< CRC0_CTRL.WAS Field                     */
#define CRC_CTRL_FXOR_MASK                       (0x4000000U)                                        /**< CRC0_CTRL.FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      (26U)                                               /**< CRC0_CTRL.FXOR Position                 */
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_FXOR_SHIFT))&CRC_CTRL_FXOR_MASK) /**< CRC0_CTRL.FXOR Field                    */
#define CRC_CTRL_TOTR_MASK                       (0x30000000U)                                       /**< CRC0_CTRL.TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      (28U)                                               /**< CRC0_CTRL.TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK) /**< CRC0_CTRL.TOTR Field                    */
#define CRC_CTRL_TOT_MASK                        (0xC0000000U)                                       /**< CRC0_CTRL.TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       (30U)                                               /**< CRC0_CTRL.TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK) /**< CRC0_CTRL.TOT Field                     */
/** @} */

/** @name CTRLHU - Control register (byte access) */ /** @{ */
#define CRC_CTRLHU_TCRC_MASK                     (0x1U)                                              /**< CRC0_CTRLHU.TCRC Mask                   */
#define CRC_CTRLHU_TCRC_SHIFT                    (0U)                                                /**< CRC0_CTRLHU.TCRC Position               */
#define CRC_CTRLHU_TCRC(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TCRC_SHIFT))&CRC_CTRLHU_TCRC_MASK) /**< CRC0_CTRLHU.TCRC Field                  */
#define CRC_CTRLHU_WAS_MASK                      (0x2U)                                              /**< CRC0_CTRLHU.WAS Mask                    */
#define CRC_CTRLHU_WAS_SHIFT                     (1U)                                                /**< CRC0_CTRLHU.WAS Position                */
#define CRC_CTRLHU_WAS(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_WAS_SHIFT))&CRC_CTRLHU_WAS_MASK) /**< CRC0_CTRLHU.WAS Field                   */
#define CRC_CTRLHU_FXOR_MASK                     (0x4U)                                              /**< CRC0_CTRLHU.FXOR Mask                   */
#define CRC_CTRLHU_FXOR_SHIFT                    (2U)                                                /**< CRC0_CTRLHU.FXOR Position               */
#define CRC_CTRLHU_FXOR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_FXOR_SHIFT))&CRC_CTRLHU_FXOR_MASK) /**< CRC0_CTRLHU.FXOR Field                  */
#define CRC_CTRLHU_TOTR_MASK                     (0x30U)                                             /**< CRC0_CTRLHU.TOTR Mask                   */
#define CRC_CTRLHU_TOTR_SHIFT                    (4U)                                                /**< CRC0_CTRLHU.TOTR Position               */
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK) /**< CRC0_CTRLHU.TOTR Field                  */
#define CRC_CTRLHU_TOT_MASK                      (0xC0U)                                             /**< CRC0_CTRLHU.TOT Mask                    */
#define CRC_CTRLHU_TOT_SHIFT                     (6U)                                                /**< CRC0_CTRLHU.TOT Position                */
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK) /**< CRC0_CTRLHU.TOT Field                   */
/** @} */

/** @} */ /* End group CRC_Register_Masks_GROUP */


/* CRC0 - Peripheral instance base addresses */
#define CRC0_BasePtr                   0x40032000UL //!< Peripheral base address
#define CRC0                           ((CRC_Type *) CRC0_BasePtr) //!< Freescale base pointer
#define CRC0_BASE_PTR                  (CRC0) //!< Freescale style base pointer

/** @} */ /* End group CRC_Peripheral_access_layer_GROUP */


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
#define DMA0_IRQS { DMA0_Ch0_IRQn, DMA0_Ch1_IRQn, DMA0_Ch2_IRQn, DMA0_Ch3_IRQn,  }


/** @} */ /* End group DMA0_Peripheral_access_layer_GROUP */


/** @brief C Struct for DMAMUX */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           DMAMUX0 (file:DMAMUX0_4CH_TRIG_MKL27Z644)       ================ */
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
   Dma0Slot_LPUART0_Rx                 =        2, //!<  LPUART0 Receive
   Dma0Slot_LPUART0_Tx                 =        3, //!<  LPUART0 Transmit
   Dma0Slot_LPUART1_Rx                 =        4, //!<  LPUART1 Receive
   Dma0Slot_LPUART1_Tx                 =        5, //!<  LPUART1 Transmit
   Dma0Slot_UART2_Rx                   =        6, //!<  UART2 Receive
   Dma0Slot_UART2_Tx                   =        7, //!<  UART2 Transmit
   Dma0Slot_FlexIO_Ch0                 =       10, //!<  FlexIO Channel 0
   Dma0Slot_FlexIO_Ch1                 =       11, //!<  FlexIO Channel 1
   Dma0Slot_FlexIO_Ch2                 =       12, //!<  FlexIO Channel 2
   Dma0Slot_FlexIO_Ch3                 =       13, //!<  FlexIO Channel 3
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
   Dma0Slot_PortA                      =       49, //!<  Port A
   Dma0Slot_PortB                      =       50, //!<  Port B
   Dma0Slot_PortC                      =       51, //!<  Port C
   Dma0Slot_PortD                      =       52, //!<  Port D
   Dma0Slot_PortE                      =       53, //!<  Port E
   Dma0Slot_TPM0_Overflow              =       54, //!<  TPM0 Overflow
   Dma0Slot_TPM1_Overflow              =       55, //!<  TPM1 Overflow
   Dma0Slot_TPM2_Overflow              =       56, //!<  TPM2 Overflow
   Dma0Slot_AlwaysEnabled60            =       60, //!<  AlwaysEnabled60
   Dma0Slot_AlwaysEnabled61            =       61, //!<  AlwaysEnabled61
   Dma0Slot_AlwaysEnabled62            =       62, //!<  AlwaysEnabled62
   Dma0Slot_AlwaysEnabled63            =       63, //!<  AlwaysEnabled63
} DmaSlot;


/** @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP */


/** @brief C Struct for FLEXIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FLEXIO_Peripheral_access_layer_GROUP FLEXIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FLEXIO (file:FLEXIO_4SH_4TMR_0x4005F000)       ================ */
/* ================================================================================ */

/**
 * @brief Flexible I/O
 */
#define FLEXIO_PIN_COUNT     8          /**< Number of Pins implemented                         */
#define FLEXIO_SHIFTER_COUNT 4          /**< Number of Shifters implemented                     */
#define FLEXIO_TIMER_COUNT   4          /**< Number of Timers implemented                       */
#define FLEXIO_TRIGGER_COUNT 16         /**< Number of external triggers implemented            */
/**
 * @struct FLEXIO_Type
 * @brief  C Struct allowing access to FLEXIO registers
 */
typedef struct FLEXIO_Type {
   __I  uint32_t  VERID;                        /**< 0000: Version ID Register                                          */
   __I  uint32_t  PARAM;                        /**< 0004: Parameter Register                                           */
   __IO uint32_t  CTRL;                         /**< 0008: FlexIO Control Register                                      */
        uint8_t   RESERVED_0[4];                /**< 000C: 0x4 bytes                                                    */
   __IO uint32_t  SHIFTSTAT;                    /**< 0010: Shifter Status Register                                      */
   __IO uint32_t  SHIFTERR;                     /**< 0014: Shifter Error Register                                       */
   __IO uint32_t  TIMSTAT;                      /**< 0018: Timer Status Register                                        */
        uint8_t   RESERVED_1[4];                /**< 001C: 0x4 bytes                                                    */
   __IO uint32_t  SHIFTSIEN;                    /**< 0020: Shifter Status Interrupt Enable                              */
   __IO uint32_t  SHIFTEIEN;                    /**< 0024: Shifter Error Interrupt Enable                               */
   __IO uint32_t  TIMIEN;                       /**< 0028: Timer Interrupt Enable Register                              */
        uint8_t   RESERVED_2[4];                /**< 002C: 0x4 bytes                                                    */
   __IO uint32_t  SHIFTSDEN;                    /**< 0030: Shifter Status DMA Enable                                    */
        uint8_t   RESERVED_3[76];               /**< 0034: 0x4C bytes                                                   */
   __IO uint32_t  SHIFTCTL[FLEXIO_SHIFTER_COUNT]; /**< 0080: Shifter Control N Register                                   */
        uint8_t   RESERVED_4[112];              /**< 0090: 0x70 bytes                                                   */
   __IO uint32_t  SHIFTCFG[FLEXIO_SHIFTER_COUNT]; /**< 0100: Shifter Configuration N Register                             */
        uint8_t   RESERVED_5[240];              /**< 0110: 0xF0 bytes                                                   */
   __IO uint32_t  SHIFTBUF[FLEXIO_SHIFTER_COUNT]; /**< 0200: Shifter Buffer N Register                                    */
        uint8_t   RESERVED_6[112];              /**< 0210: 0x70 bytes                                                   */
   __IO uint32_t  SHIFTBUFBIS[FLEXIO_SHIFTER_COUNT]; /**< 0280: Shifter Buffer N Bit Swapped Register                        */
        uint8_t   RESERVED_7[112];              /**< 0290: 0x70 bytes                                                   */
   __IO uint32_t  SHIFTBUFBYS[FLEXIO_SHIFTER_COUNT]; /**< 0300: Shifter Buffer N Byte Swapped Register                       */
        uint8_t   RESERVED_8[112];              /**< 0310: 0x70 bytes                                                   */
   __IO uint32_t  SHIFTBUFBBS[FLEXIO_SHIFTER_COUNT]; /**< 0380: Shifter Buffer N Bit Byte Swapped Register                   */
        uint8_t   RESERVED_9[112];              /**< 0390: 0x70 bytes                                                   */
   __IO uint32_t  TIMCTL[FLEXIO_TIMER_COUNT];   /**< 0400: Timer Control N Register                                     */
        uint8_t   RESERVED_10[112];             /**< 0410: 0x70 bytes                                                   */
   __IO uint32_t  TIMCFG[FLEXIO_TIMER_COUNT];   /**< 0480: Timer Configuration N Register                               */
        uint8_t   RESERVED_11[112];             /**< 0490: 0x70 bytes                                                   */
   __IO uint32_t  TIMCMP[FLEXIO_TIMER_COUNT];   /**< 0500: Timer Compare N Register                                     */
} FLEXIO_Type;


/** @brief Register Masks for FLEXIO */

/* -------------------------------------------------------------------------------- */
/* -----------     'FLEXIO' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FLEXIO_Register_Masks_GROUP FLEXIO Register Masks */
/** @{ */

/** @name VERID - Version ID Register */ /** @{ */
#define FLEXIO_VERID_FEATURE_MASK                (0xFFFFU)                                           /**< FLEXIO_VERID.FEATURE Mask               */
#define FLEXIO_VERID_FEATURE_SHIFT               (0U)                                                /**< FLEXIO_VERID.FEATURE Position           */
#define FLEXIO_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_FEATURE_SHIFT))&FLEXIO_VERID_FEATURE_MASK) /**< FLEXIO_VERID.FEATURE Field              */
#define FLEXIO_VERID_MINOR_MASK                  (0xFF0000U)                                         /**< FLEXIO_VERID.MINOR Mask                 */
#define FLEXIO_VERID_MINOR_SHIFT                 (16U)                                               /**< FLEXIO_VERID.MINOR Position             */
#define FLEXIO_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_MINOR_SHIFT))&FLEXIO_VERID_MINOR_MASK) /**< FLEXIO_VERID.MINOR Field                */
#define FLEXIO_VERID_MAJOR_MASK                  (0xFF000000U)                                       /**< FLEXIO_VERID.MAJOR Mask                 */
#define FLEXIO_VERID_MAJOR_SHIFT                 (24U)                                               /**< FLEXIO_VERID.MAJOR Position             */
#define FLEXIO_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_VERID_MAJOR_SHIFT))&FLEXIO_VERID_MAJOR_MASK) /**< FLEXIO_VERID.MAJOR Field                */
/** @} */

/** @name PARAM - Parameter Register */ /** @{ */
#define FLEXIO_PARAM_SHIFTER_MASK                (0xFFU)                                             /**< FLEXIO_PARAM.SHIFTER Mask               */
#define FLEXIO_PARAM_SHIFTER_SHIFT               (0U)                                                /**< FLEXIO_PARAM.SHIFTER Position           */
#define FLEXIO_PARAM_SHIFTER(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_SHIFTER_SHIFT))&FLEXIO_PARAM_SHIFTER_MASK) /**< FLEXIO_PARAM.SHIFTER Field              */
#define FLEXIO_PARAM_TIMER_MASK                  (0xFF00U)                                           /**< FLEXIO_PARAM.TIMER Mask                 */
#define FLEXIO_PARAM_TIMER_SHIFT                 (8U)                                                /**< FLEXIO_PARAM.TIMER Position             */
#define FLEXIO_PARAM_TIMER(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_TIMER_SHIFT))&FLEXIO_PARAM_TIMER_MASK) /**< FLEXIO_PARAM.TIMER Field                */
#define FLEXIO_PARAM_PIN_MASK                    (0xFF0000U)                                         /**< FLEXIO_PARAM.PIN Mask                   */
#define FLEXIO_PARAM_PIN_SHIFT                   (16U)                                               /**< FLEXIO_PARAM.PIN Position               */
#define FLEXIO_PARAM_PIN(x)                      (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_PIN_SHIFT))&FLEXIO_PARAM_PIN_MASK) /**< FLEXIO_PARAM.PIN Field                  */
#define FLEXIO_PARAM_TRIGGER_MASK                (0xFF000000U)                                       /**< FLEXIO_PARAM.TRIGGER Mask               */
#define FLEXIO_PARAM_TRIGGER_SHIFT               (24U)                                               /**< FLEXIO_PARAM.TRIGGER Position           */
#define FLEXIO_PARAM_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_PARAM_TRIGGER_SHIFT))&FLEXIO_PARAM_TRIGGER_MASK) /**< FLEXIO_PARAM.TRIGGER Field              */
/** @} */

/** @name CTRL - FlexIO Control Register */ /** @{ */
#define FLEXIO_CTRL_FLEXEN_MASK                  (0x1U)                                              /**< FLEXIO_CTRL.FLEXEN Mask                 */
#define FLEXIO_CTRL_FLEXEN_SHIFT                 (0U)                                                /**< FLEXIO_CTRL.FLEXEN Position             */
#define FLEXIO_CTRL_FLEXEN(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_FLEXEN_SHIFT))&FLEXIO_CTRL_FLEXEN_MASK) /**< FLEXIO_CTRL.FLEXEN Field                */
#define FLEXIO_CTRL_SWRST_MASK                   (0x2U)                                              /**< FLEXIO_CTRL.SWRST Mask                  */
#define FLEXIO_CTRL_SWRST_SHIFT                  (1U)                                                /**< FLEXIO_CTRL.SWRST Position              */
#define FLEXIO_CTRL_SWRST(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_SWRST_SHIFT))&FLEXIO_CTRL_SWRST_MASK) /**< FLEXIO_CTRL.SWRST Field                 */
#define FLEXIO_CTRL_FASTACC_MASK                 (0x4U)                                              /**< FLEXIO_CTRL.FASTACC Mask                */
#define FLEXIO_CTRL_FASTACC_SHIFT                (2U)                                                /**< FLEXIO_CTRL.FASTACC Position            */
#define FLEXIO_CTRL_FASTACC(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_FASTACC_SHIFT))&FLEXIO_CTRL_FASTACC_MASK) /**< FLEXIO_CTRL.FASTACC Field               */
#define FLEXIO_CTRL_DBGE_MASK                    (0x40000000U)                                       /**< FLEXIO_CTRL.DBGE Mask                   */
#define FLEXIO_CTRL_DBGE_SHIFT                   (30U)                                               /**< FLEXIO_CTRL.DBGE Position               */
#define FLEXIO_CTRL_DBGE(x)                      (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_DBGE_SHIFT))&FLEXIO_CTRL_DBGE_MASK) /**< FLEXIO_CTRL.DBGE Field                  */
#define FLEXIO_CTRL_DOZEN_MASK                   (0x80000000U)                                       /**< FLEXIO_CTRL.DOZEN Mask                  */
#define FLEXIO_CTRL_DOZEN_SHIFT                  (31U)                                               /**< FLEXIO_CTRL.DOZEN Position              */
#define FLEXIO_CTRL_DOZEN(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_CTRL_DOZEN_SHIFT))&FLEXIO_CTRL_DOZEN_MASK) /**< FLEXIO_CTRL.DOZEN Field                 */
/** @} */

/** @name SHIFTSTAT - Shifter Status Register */ /** @{ */
#define FLEXIO_SHIFTSTAT_SSF_MASK                (0xFU)                                              /**< FLEXIO_SHIFTSTAT.SSF Mask               */
#define FLEXIO_SHIFTSTAT_SSF_SHIFT               (0U)                                                /**< FLEXIO_SHIFTSTAT.SSF Position           */
#define FLEXIO_SHIFTSTAT_SSF(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSTAT_SSF_SHIFT))&FLEXIO_SHIFTSTAT_SSF_MASK) /**< FLEXIO_SHIFTSTAT.SSF Field              */
/** @} */

/** @name SHIFTERR - Shifter Error Register */ /** @{ */
#define FLEXIO_SHIFTERR_SEF_MASK                 (0xFU)                                              /**< FLEXIO_SHIFTERR.SEF Mask                */
#define FLEXIO_SHIFTERR_SEF_SHIFT                (0U)                                                /**< FLEXIO_SHIFTERR.SEF Position            */
#define FLEXIO_SHIFTERR_SEF(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTERR_SEF_SHIFT))&FLEXIO_SHIFTERR_SEF_MASK) /**< FLEXIO_SHIFTERR.SEF Field               */
/** @} */

/** @name TIMSTAT - Timer Status Register */ /** @{ */
#define FLEXIO_TIMSTAT_TSF_MASK                  (0xFU)                                              /**< FLEXIO_TIMSTAT.TSF Mask                 */
#define FLEXIO_TIMSTAT_TSF_SHIFT                 (0U)                                                /**< FLEXIO_TIMSTAT.TSF Position             */
#define FLEXIO_TIMSTAT_TSF(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMSTAT_TSF_SHIFT))&FLEXIO_TIMSTAT_TSF_MASK) /**< FLEXIO_TIMSTAT.TSF Field                */
/** @} */

/** @name SHIFTSIEN - Shifter Status Interrupt Enable */ /** @{ */
#define FLEXIO_SHIFTSIEN_SSIE_MASK               (0xFU)                                              /**< FLEXIO_SHIFTSIEN.SSIE Mask              */
#define FLEXIO_SHIFTSIEN_SSIE_SHIFT              (0U)                                                /**< FLEXIO_SHIFTSIEN.SSIE Position          */
#define FLEXIO_SHIFTSIEN_SSIE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSIEN_SSIE_SHIFT))&FLEXIO_SHIFTSIEN_SSIE_MASK) /**< FLEXIO_SHIFTSIEN.SSIE Field             */
/** @} */

/** @name SHIFTEIEN - Shifter Error Interrupt Enable */ /** @{ */
#define FLEXIO_SHIFTEIEN_SEIE_MASK               (0xFU)                                              /**< FLEXIO_SHIFTEIEN.SEIE Mask              */
#define FLEXIO_SHIFTEIEN_SEIE_SHIFT              (0U)                                                /**< FLEXIO_SHIFTEIEN.SEIE Position          */
#define FLEXIO_SHIFTEIEN_SEIE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTEIEN_SEIE_SHIFT))&FLEXIO_SHIFTEIEN_SEIE_MASK) /**< FLEXIO_SHIFTEIEN.SEIE Field             */
/** @} */

/** @name TIMIEN - Timer Interrupt Enable Register */ /** @{ */
#define FLEXIO_TIMIEN_TEIE_MASK                  (0xFU)                                              /**< FLEXIO_TIMIEN.TEIE Mask                 */
#define FLEXIO_TIMIEN_TEIE_SHIFT                 (0U)                                                /**< FLEXIO_TIMIEN.TEIE Position             */
#define FLEXIO_TIMIEN_TEIE(x)                    (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMIEN_TEIE_SHIFT))&FLEXIO_TIMIEN_TEIE_MASK) /**< FLEXIO_TIMIEN.TEIE Field                */
/** @} */

/** @name SHIFTSDEN - Shifter Status DMA Enable */ /** @{ */
#define FLEXIO_SHIFTSDEN_SSDE_MASK               (0xFU)                                              /**< FLEXIO_SHIFTSDEN.SSDE Mask              */
#define FLEXIO_SHIFTSDEN_SSDE_SHIFT              (0U)                                                /**< FLEXIO_SHIFTSDEN.SSDE Position          */
#define FLEXIO_SHIFTSDEN_SSDE(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTSDEN_SSDE_SHIFT))&FLEXIO_SHIFTSDEN_SSDE_MASK) /**< FLEXIO_SHIFTSDEN.SSDE Field             */
/** @} */

/** @name SHIFTCTL - Shifter Control N Register */ /** @{ */
#define FLEXIO_SHIFTCTL_SMOD_MASK                (0x7U)                                              /**< FLEXIO_SHIFTCTL.SMOD Mask               */
#define FLEXIO_SHIFTCTL_SMOD_SHIFT               (0U)                                                /**< FLEXIO_SHIFTCTL.SMOD Position           */
#define FLEXIO_SHIFTCTL_SMOD(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_SMOD_SHIFT))&FLEXIO_SHIFTCTL_SMOD_MASK) /**< FLEXIO_SHIFTCTL.SMOD Field              */
#define FLEXIO_SHIFTCTL_PINPOL_MASK              (0x80U)                                             /**< FLEXIO_SHIFTCTL.PINPOL Mask             */
#define FLEXIO_SHIFTCTL_PINPOL_SHIFT             (7U)                                                /**< FLEXIO_SHIFTCTL.PINPOL Position         */
#define FLEXIO_SHIFTCTL_PINPOL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINPOL_SHIFT))&FLEXIO_SHIFTCTL_PINPOL_MASK) /**< FLEXIO_SHIFTCTL.PINPOL Field            */
#define FLEXIO_SHIFTCTL_PINSEL_MASK              (0x700U)                                            /**< FLEXIO_SHIFTCTL.PINSEL Mask             */
#define FLEXIO_SHIFTCTL_PINSEL_SHIFT             (8U)                                                /**< FLEXIO_SHIFTCTL.PINSEL Position         */
#define FLEXIO_SHIFTCTL_PINSEL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINSEL_SHIFT))&FLEXIO_SHIFTCTL_PINSEL_MASK) /**< FLEXIO_SHIFTCTL.PINSEL Field            */
#define FLEXIO_SHIFTCTL_PINCFG_MASK              (0x30000U)                                          /**< FLEXIO_SHIFTCTL.PINCFG Mask             */
#define FLEXIO_SHIFTCTL_PINCFG_SHIFT             (16U)                                               /**< FLEXIO_SHIFTCTL.PINCFG Position         */
#define FLEXIO_SHIFTCTL_PINCFG(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_PINCFG_SHIFT))&FLEXIO_SHIFTCTL_PINCFG_MASK) /**< FLEXIO_SHIFTCTL.PINCFG Field            */
#define FLEXIO_SHIFTCTL_TIMPOL_MASK              (0x800000U)                                         /**< FLEXIO_SHIFTCTL.TIMPOL Mask             */
#define FLEXIO_SHIFTCTL_TIMPOL_SHIFT             (23U)                                               /**< FLEXIO_SHIFTCTL.TIMPOL Position         */
#define FLEXIO_SHIFTCTL_TIMPOL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_TIMPOL_SHIFT))&FLEXIO_SHIFTCTL_TIMPOL_MASK) /**< FLEXIO_SHIFTCTL.TIMPOL Field            */
#define FLEXIO_SHIFTCTL_TIMSEL_MASK              (0x3000000U)                                        /**< FLEXIO_SHIFTCTL.TIMSEL Mask             */
#define FLEXIO_SHIFTCTL_TIMSEL_SHIFT             (24U)                                               /**< FLEXIO_SHIFTCTL.TIMSEL Position         */
#define FLEXIO_SHIFTCTL_TIMSEL(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCTL_TIMSEL_SHIFT))&FLEXIO_SHIFTCTL_TIMSEL_MASK) /**< FLEXIO_SHIFTCTL.TIMSEL Field            */
/** @} */

/** @name SHIFTCFG - Shifter Configuration N Register */ /** @{ */
#define FLEXIO_SHIFTCFG_SSTART_MASK              (0x3U)                                              /**< FLEXIO_SHIFTCFG.SSTART Mask             */
#define FLEXIO_SHIFTCFG_SSTART_SHIFT             (0U)                                                /**< FLEXIO_SHIFTCFG.SSTART Position         */
#define FLEXIO_SHIFTCFG_SSTART(x)                (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_SSTART_SHIFT))&FLEXIO_SHIFTCFG_SSTART_MASK) /**< FLEXIO_SHIFTCFG.SSTART Field            */
#define FLEXIO_SHIFTCFG_SSTOP_MASK               (0x30U)                                             /**< FLEXIO_SHIFTCFG.SSTOP Mask              */
#define FLEXIO_SHIFTCFG_SSTOP_SHIFT              (4U)                                                /**< FLEXIO_SHIFTCFG.SSTOP Position          */
#define FLEXIO_SHIFTCFG_SSTOP(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_SSTOP_SHIFT))&FLEXIO_SHIFTCFG_SSTOP_MASK) /**< FLEXIO_SHIFTCFG.SSTOP Field             */
#define FLEXIO_SHIFTCFG_INSRC_MASK               (0x100U)                                            /**< FLEXIO_SHIFTCFG.INSRC Mask              */
#define FLEXIO_SHIFTCFG_INSRC_SHIFT              (8U)                                                /**< FLEXIO_SHIFTCFG.INSRC Position          */
#define FLEXIO_SHIFTCFG_INSRC(x)                 (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTCFG_INSRC_SHIFT))&FLEXIO_SHIFTCFG_INSRC_MASK) /**< FLEXIO_SHIFTCFG.INSRC Field             */
/** @} */

/** @name SHIFTBUF - Shifter Buffer N Register */ /** @{ */
#define FLEXIO_SHIFTBUF_SHIFTBUF_MASK            (0xFFFFFFFFU)                                       /**< FLEXIO_SHIFTBUF.SHIFTBUF Mask           */
#define FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT           (0U)                                                /**< FLEXIO_SHIFTBUF.SHIFTBUF Position       */
#define FLEXIO_SHIFTBUF_SHIFTBUF(x)              (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT))&FLEXIO_SHIFTBUF_SHIFTBUF_MASK) /**< FLEXIO_SHIFTBUF.SHIFTBUF Field          */
/** @} */

/** @name SHIFTBUFBIS - Shifter Buffer N Bit Swapped Register */ /** @{ */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK      (0xFFFFFFFFU)                                       /**< FLEXIO_SHIFTBUFBIS.SHIFTBUFBIS Mask     */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT     (0U)                                                /**< FLEXIO_SHIFTBUFBIS.SHIFTBUFBIS Position */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT))&FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK) /**< FLEXIO_SHIFTBUFBIS.SHIFTBUFBIS Field    */
/** @} */

/** @name SHIFTBUFBYS - Shifter Buffer N Byte Swapped Register */ /** @{ */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK      (0xFFFFFFFFU)                                       /**< FLEXIO_SHIFTBUFBYS.SHIFTBUFBYS Mask     */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT     (0U)                                                /**< FLEXIO_SHIFTBUFBYS.SHIFTBUFBYS Position */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT))&FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK) /**< FLEXIO_SHIFTBUFBYS.SHIFTBUFBYS Field    */
/** @} */

/** @name SHIFTBUFBBS - Shifter Buffer N Bit Byte Swapped Register */ /** @{ */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK      (0xFFFFFFFFU)                                       /**< FLEXIO_SHIFTBUFBBS.SHIFTBUFBBS Mask     */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT     (0U)                                                /**< FLEXIO_SHIFTBUFBBS.SHIFTBUFBBS Position */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS(x)        (((uint32_t)(((uint32_t)(x))<<FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT))&FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK) /**< FLEXIO_SHIFTBUFBBS.SHIFTBUFBBS Field    */
/** @} */

/** @name TIMCTL - Timer Control N Register */ /** @{ */
#define FLEXIO_TIMCTL_TIMOD_MASK                 (0x3U)                                              /**< FLEXIO_TIMCTL.TIMOD Mask                */
#define FLEXIO_TIMCTL_TIMOD_SHIFT                (0U)                                                /**< FLEXIO_TIMCTL.TIMOD Position            */
#define FLEXIO_TIMCTL_TIMOD(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TIMOD_SHIFT))&FLEXIO_TIMCTL_TIMOD_MASK) /**< FLEXIO_TIMCTL.TIMOD Field               */
#define FLEXIO_TIMCTL_PINPOL_MASK                (0x80U)                                             /**< FLEXIO_TIMCTL.PINPOL Mask               */
#define FLEXIO_TIMCTL_PINPOL_SHIFT               (7U)                                                /**< FLEXIO_TIMCTL.PINPOL Position           */
#define FLEXIO_TIMCTL_PINPOL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINPOL_SHIFT))&FLEXIO_TIMCTL_PINPOL_MASK) /**< FLEXIO_TIMCTL.PINPOL Field              */
#define FLEXIO_TIMCTL_PINSEL_MASK                (0x700U)                                            /**< FLEXIO_TIMCTL.PINSEL Mask               */
#define FLEXIO_TIMCTL_PINSEL_SHIFT               (8U)                                                /**< FLEXIO_TIMCTL.PINSEL Position           */
#define FLEXIO_TIMCTL_PINSEL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINSEL_SHIFT))&FLEXIO_TIMCTL_PINSEL_MASK) /**< FLEXIO_TIMCTL.PINSEL Field              */
#define FLEXIO_TIMCTL_PINCFG_MASK                (0x30000U)                                          /**< FLEXIO_TIMCTL.PINCFG Mask               */
#define FLEXIO_TIMCTL_PINCFG_SHIFT               (16U)                                               /**< FLEXIO_TIMCTL.PINCFG Position           */
#define FLEXIO_TIMCTL_PINCFG(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_PINCFG_SHIFT))&FLEXIO_TIMCTL_PINCFG_MASK) /**< FLEXIO_TIMCTL.PINCFG Field              */
#define FLEXIO_TIMCTL_TRGSRC_MASK                (0x400000U)                                         /**< FLEXIO_TIMCTL.TRGSRC Mask               */
#define FLEXIO_TIMCTL_TRGSRC_SHIFT               (22U)                                               /**< FLEXIO_TIMCTL.TRGSRC Position           */
#define FLEXIO_TIMCTL_TRGSRC(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGSRC_SHIFT))&FLEXIO_TIMCTL_TRGSRC_MASK) /**< FLEXIO_TIMCTL.TRGSRC Field              */
#define FLEXIO_TIMCTL_TRGPOL_MASK                (0x800000U)                                         /**< FLEXIO_TIMCTL.TRGPOL Mask               */
#define FLEXIO_TIMCTL_TRGPOL_SHIFT               (23U)                                               /**< FLEXIO_TIMCTL.TRGPOL Position           */
#define FLEXIO_TIMCTL_TRGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGPOL_SHIFT))&FLEXIO_TIMCTL_TRGPOL_MASK) /**< FLEXIO_TIMCTL.TRGPOL Field              */
#define FLEXIO_TIMCTL_TRGSEL_MASK                (0xF000000U)                                        /**< FLEXIO_TIMCTL.TRGSEL Mask               */
#define FLEXIO_TIMCTL_TRGSEL_SHIFT               (24U)                                               /**< FLEXIO_TIMCTL.TRGSEL Position           */
#define FLEXIO_TIMCTL_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCTL_TRGSEL_SHIFT))&FLEXIO_TIMCTL_TRGSEL_MASK) /**< FLEXIO_TIMCTL.TRGSEL Field              */
/** @} */

/** @name TIMCFG - Timer Configuration N Register */ /** @{ */
#define FLEXIO_TIMCFG_TSTART_MASK                (0x2U)                                              /**< FLEXIO_TIMCFG.TSTART Mask               */
#define FLEXIO_TIMCFG_TSTART_SHIFT               (1U)                                                /**< FLEXIO_TIMCFG.TSTART Position           */
#define FLEXIO_TIMCFG_TSTART(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TSTART_SHIFT))&FLEXIO_TIMCFG_TSTART_MASK) /**< FLEXIO_TIMCFG.TSTART Field              */
#define FLEXIO_TIMCFG_TSTOP_MASK                 (0x30U)                                             /**< FLEXIO_TIMCFG.TSTOP Mask                */
#define FLEXIO_TIMCFG_TSTOP_SHIFT                (4U)                                                /**< FLEXIO_TIMCFG.TSTOP Position            */
#define FLEXIO_TIMCFG_TSTOP(x)                   (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TSTOP_SHIFT))&FLEXIO_TIMCFG_TSTOP_MASK) /**< FLEXIO_TIMCFG.TSTOP Field               */
#define FLEXIO_TIMCFG_TIMENA_MASK                (0x700U)                                            /**< FLEXIO_TIMCFG.TIMENA Mask               */
#define FLEXIO_TIMCFG_TIMENA_SHIFT               (8U)                                                /**< FLEXIO_TIMCFG.TIMENA Position           */
#define FLEXIO_TIMCFG_TIMENA(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMENA_SHIFT))&FLEXIO_TIMCFG_TIMENA_MASK) /**< FLEXIO_TIMCFG.TIMENA Field              */
#define FLEXIO_TIMCFG_TIMDIS_MASK                (0x7000U)                                           /**< FLEXIO_TIMCFG.TIMDIS Mask               */
#define FLEXIO_TIMCFG_TIMDIS_SHIFT               (12U)                                               /**< FLEXIO_TIMCFG.TIMDIS Position           */
#define FLEXIO_TIMCFG_TIMDIS(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMDIS_SHIFT))&FLEXIO_TIMCFG_TIMDIS_MASK) /**< FLEXIO_TIMCFG.TIMDIS Field              */
#define FLEXIO_TIMCFG_TIMRST_MASK                (0x70000U)                                          /**< FLEXIO_TIMCFG.TIMRST Mask               */
#define FLEXIO_TIMCFG_TIMRST_SHIFT               (16U)                                               /**< FLEXIO_TIMCFG.TIMRST Position           */
#define FLEXIO_TIMCFG_TIMRST(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMRST_SHIFT))&FLEXIO_TIMCFG_TIMRST_MASK) /**< FLEXIO_TIMCFG.TIMRST Field              */
#define FLEXIO_TIMCFG_TIMDEC_MASK                (0x300000U)                                         /**< FLEXIO_TIMCFG.TIMDEC Mask               */
#define FLEXIO_TIMCFG_TIMDEC_SHIFT               (20U)                                               /**< FLEXIO_TIMCFG.TIMDEC Position           */
#define FLEXIO_TIMCFG_TIMDEC(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMDEC_SHIFT))&FLEXIO_TIMCFG_TIMDEC_MASK) /**< FLEXIO_TIMCFG.TIMDEC Field              */
#define FLEXIO_TIMCFG_TIMOUT_MASK                (0x3000000U)                                        /**< FLEXIO_TIMCFG.TIMOUT Mask               */
#define FLEXIO_TIMCFG_TIMOUT_SHIFT               (24U)                                               /**< FLEXIO_TIMCFG.TIMOUT Position           */
#define FLEXIO_TIMCFG_TIMOUT(x)                  (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCFG_TIMOUT_SHIFT))&FLEXIO_TIMCFG_TIMOUT_MASK) /**< FLEXIO_TIMCFG.TIMOUT Field              */
/** @} */

/** @name TIMCMP - Timer Compare N Register */ /** @{ */
#define FLEXIO_TIMCMP_CMP_MASK                   (0xFFFFU)                                           /**< FLEXIO_TIMCMP.CMP Mask                  */
#define FLEXIO_TIMCMP_CMP_SHIFT                  (0U)                                                /**< FLEXIO_TIMCMP.CMP Position              */
#define FLEXIO_TIMCMP_CMP(x)                     (((uint32_t)(((uint32_t)(x))<<FLEXIO_TIMCMP_CMP_SHIFT))&FLEXIO_TIMCMP_CMP_MASK) /**< FLEXIO_TIMCMP.CMP Field                 */
/** @} */

/** @} */ /* End group FLEXIO_Register_Masks_GROUP */


/* FLEXIO - Peripheral instance base addresses */
#define FLEXIO_BasePtr                 0x4005F000UL //!< Peripheral base address
#define FLEXIO                         ((FLEXIO_Type *) FLEXIO_BasePtr) //!< Freescale base pointer
#define FLEXIO_BASE_PTR                (FLEXIO) //!< Freescale style base pointer
#define FLEXIO_IRQS { UART2_FLEXIO_IRQn,  }


/** @} */ /* End group FLEXIO_Peripheral_access_layer_GROUP */


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
#define FTFA_IRQS { FTFA_IRQn,  }


/** @} */ /* End group FTFA_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_0x400FF000)        ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
 * @struct GPIO_Type
 * @brief  C Struct allowing access to GPIO registers
 */
typedef struct GPIO_Type {
   __IO uint32_t  PDOR;                         /**< 0000: Port Data Output Register                                    */
   __O  uint32_t  PSOR;                         /**< 0004: Port Set Output Register                                     */
   __O  uint32_t  PCOR;                         /**< 0008: Port Clear Output Register                                   */
   __O  uint32_t  PTOR;                         /**< 000C: Port Toggle Output Register                                  */
   __I  uint32_t  PDIR;                         /**< 0010: Port Data Input Register                                     */
   __IO uint32_t  PDDR;                         /**< 0014: Port Data Direction Register                                 */
} GPIO_Type;


/** @brief Register Masks for GPIO */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup GPIO_Register_Masks_GROUP GPIO Register Masks */
/** @{ */

/** @} */ /* End group GPIO_Register_Masks_GROUP */


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
/* ================           GPIOB (derived from GPIOA)           ================ */
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
/* ================           GPIOC (derived from GPIOA)           ================ */
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
/* ================           GPIOD (derived from GPIOA)           ================ */
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
/* ================           GPIOE (derived from GPIOA)           ================ */
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
/* ================           I2C0 (file:I2C0_MK28F15)             ================ */
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
   __IO uint8_t   S2;                           /**< 000C: Status register 2                                            */
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
#define I2C_FLT_FLT_MASK                         (0xFU)                                              /**< I2C0_FLT.FLT Mask                       */
#define I2C_FLT_FLT_SHIFT                        (0U)                                                /**< I2C0_FLT.FLT Position                   */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK) /**< I2C0_FLT.FLT Field                      */
#define I2C_FLT_STARTF_MASK                      (0x10U)                                             /**< I2C0_FLT.STARTF Mask                    */
#define I2C_FLT_STARTF_SHIFT                     (4U)                                                /**< I2C0_FLT.STARTF Position                */
#define I2C_FLT_STARTF(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_FLT_STARTF_SHIFT))&I2C_FLT_STARTF_MASK) /**< I2C0_FLT.STARTF Field                   */
#define I2C_FLT_SSIE_MASK                        (0x20U)                                             /**< I2C0_FLT.SSIE Mask                      */
#define I2C_FLT_SSIE_SHIFT                       (5U)                                                /**< I2C0_FLT.SSIE Position                  */
#define I2C_FLT_SSIE(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_FLT_SSIE_SHIFT))&I2C_FLT_SSIE_MASK) /**< I2C0_FLT.SSIE Field                     */
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

/** @name S2 - Status register 2 */ /** @{ */
#define I2C_S2_EMPTY_MASK                        (0x1U)                                              /**< I2C0_S2.EMPTY Mask                      */
#define I2C_S2_EMPTY_SHIFT                       (0U)                                                /**< I2C0_S2.EMPTY Position                  */
#define I2C_S2_EMPTY(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_S2_EMPTY_SHIFT))&I2C_S2_EMPTY_MASK) /**< I2C0_S2.EMPTY Field                     */
#define I2C_S2_ERROR_MASK                        (0x2U)                                              /**< I2C0_S2.ERROR Mask                      */
#define I2C_S2_ERROR_SHIFT                       (1U)                                                /**< I2C0_S2.ERROR Position                  */
#define I2C_S2_ERROR(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_S2_ERROR_SHIFT))&I2C_S2_ERROR_MASK) /**< I2C0_S2.ERROR Field                     */
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


/** @brief C Struct for LPUART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup LPUART_Peripheral_access_layer_GROUP LPUART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPUART0 (file:LPUART0_MKL03)         ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
 * @struct LPUART_Type
 * @brief  C Struct allowing access to LPUART registers
 */
typedef struct LPUART_Type {
   __IO uint32_t  BAUD;                         /**< 0000: Baud Rate Register                                           */
   __IO uint32_t  STAT;                         /**< 0004: Status Register                                              */
   __IO uint32_t  CTRL;                         /**< 0008: Control Register                                             */
   __IO uint32_t  DATA;                         /**< 000C: Data Register                                                */
   __IO uint32_t  MATCH;                        /**< 0010: Match Address Register                                       */
} LPUART_Type;


/** @brief Register Masks for LPUART */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPUART0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup LPUART_Register_Masks_GROUP LPUART Register Masks */
/** @{ */

/** @name BAUD - Baud Rate Register */ /** @{ */
#define LPUART_BAUD_SBR_MASK                     (0x1FFFU)                                           /**< LPUART0_BAUD.SBR Mask                   */
#define LPUART_BAUD_SBR_SHIFT                    (0U)                                                /**< LPUART0_BAUD.SBR Position               */
#define LPUART_BAUD_SBR(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_SBR_SHIFT))&LPUART_BAUD_SBR_MASK) /**< LPUART0_BAUD.SBR Field                  */
#define LPUART_BAUD_SBNS_MASK                    (0x2000U)                                           /**< LPUART0_BAUD.SBNS Mask                  */
#define LPUART_BAUD_SBNS_SHIFT                   (13U)                                               /**< LPUART0_BAUD.SBNS Position              */
#define LPUART_BAUD_SBNS(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_SBNS_SHIFT))&LPUART_BAUD_SBNS_MASK) /**< LPUART0_BAUD.SBNS Field                 */
#define LPUART_BAUD_RXEDGIE_MASK                 (0x4000U)                                           /**< LPUART0_BAUD.RXEDGIE Mask               */
#define LPUART_BAUD_RXEDGIE_SHIFT                (14U)                                               /**< LPUART0_BAUD.RXEDGIE Position           */
#define LPUART_BAUD_RXEDGIE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RXEDGIE_SHIFT))&LPUART_BAUD_RXEDGIE_MASK) /**< LPUART0_BAUD.RXEDGIE Field              */
#define LPUART_BAUD_LBKDIE_MASK                  (0x8000U)                                           /**< LPUART0_BAUD.LBKDIE Mask                */
#define LPUART_BAUD_LBKDIE_SHIFT                 (15U)                                               /**< LPUART0_BAUD.LBKDIE Position            */
#define LPUART_BAUD_LBKDIE(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_LBKDIE_SHIFT))&LPUART_BAUD_LBKDIE_MASK) /**< LPUART0_BAUD.LBKDIE Field               */
#define LPUART_BAUD_RESYNCDIS_MASK               (0x10000U)                                          /**< LPUART0_BAUD.RESYNCDIS Mask             */
#define LPUART_BAUD_RESYNCDIS_SHIFT              (16U)                                               /**< LPUART0_BAUD.RESYNCDIS Position         */
#define LPUART_BAUD_RESYNCDIS(x)                 (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RESYNCDIS_SHIFT))&LPUART_BAUD_RESYNCDIS_MASK) /**< LPUART0_BAUD.RESYNCDIS Field            */
#define LPUART_BAUD_BOTHEDGE_MASK                (0x20000U)                                          /**< LPUART0_BAUD.BOTHEDGE Mask              */
#define LPUART_BAUD_BOTHEDGE_SHIFT               (17U)                                               /**< LPUART0_BAUD.BOTHEDGE Position          */
#define LPUART_BAUD_BOTHEDGE(x)                  (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_BOTHEDGE_SHIFT))&LPUART_BAUD_BOTHEDGE_MASK) /**< LPUART0_BAUD.BOTHEDGE Field             */
#define LPUART_BAUD_MATCFG_MASK                  (0xC0000U)                                          /**< LPUART0_BAUD.MATCFG Mask                */
#define LPUART_BAUD_MATCFG_SHIFT                 (18U)                                               /**< LPUART0_BAUD.MATCFG Position            */
#define LPUART_BAUD_MATCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MATCFG_SHIFT))&LPUART_BAUD_MATCFG_MASK) /**< LPUART0_BAUD.MATCFG Field               */
#define LPUART_BAUD_RDMAE_MASK                   (0x200000U)                                         /**< LPUART0_BAUD.RDMAE Mask                 */
#define LPUART_BAUD_RDMAE_SHIFT                  (21U)                                               /**< LPUART0_BAUD.RDMAE Position             */
#define LPUART_BAUD_RDMAE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_RDMAE_SHIFT))&LPUART_BAUD_RDMAE_MASK) /**< LPUART0_BAUD.RDMAE Field                */
#define LPUART_BAUD_TDMAE_MASK                   (0x800000U)                                         /**< LPUART0_BAUD.TDMAE Mask                 */
#define LPUART_BAUD_TDMAE_SHIFT                  (23U)                                               /**< LPUART0_BAUD.TDMAE Position             */
#define LPUART_BAUD_TDMAE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_TDMAE_SHIFT))&LPUART_BAUD_TDMAE_MASK) /**< LPUART0_BAUD.TDMAE Field                */
#define LPUART_BAUD_OSR_MASK                     (0x1F000000U)                                       /**< LPUART0_BAUD.OSR Mask                   */
#define LPUART_BAUD_OSR_SHIFT                    (24U)                                               /**< LPUART0_BAUD.OSR Position               */
#define LPUART_BAUD_OSR(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_OSR_SHIFT))&LPUART_BAUD_OSR_MASK) /**< LPUART0_BAUD.OSR Field                  */
#define LPUART_BAUD_M10_MASK                     (0x20000000U)                                       /**< LPUART0_BAUD.M10 Mask                   */
#define LPUART_BAUD_M10_SHIFT                    (29U)                                               /**< LPUART0_BAUD.M10 Position               */
#define LPUART_BAUD_M10(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_M10_SHIFT))&LPUART_BAUD_M10_MASK) /**< LPUART0_BAUD.M10 Field                  */
#define LPUART_BAUD_MAEN2_MASK                   (0x40000000U)                                       /**< LPUART0_BAUD.MAEN2 Mask                 */
#define LPUART_BAUD_MAEN2_SHIFT                  (30U)                                               /**< LPUART0_BAUD.MAEN2 Position             */
#define LPUART_BAUD_MAEN2(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MAEN2_SHIFT))&LPUART_BAUD_MAEN2_MASK) /**< LPUART0_BAUD.MAEN2 Field                */
#define LPUART_BAUD_MAEN1_MASK                   (0x80000000U)                                       /**< LPUART0_BAUD.MAEN1 Mask                 */
#define LPUART_BAUD_MAEN1_SHIFT                  (31U)                                               /**< LPUART0_BAUD.MAEN1 Position             */
#define LPUART_BAUD_MAEN1(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_BAUD_MAEN1_SHIFT))&LPUART_BAUD_MAEN1_MASK) /**< LPUART0_BAUD.MAEN1 Field                */
/** @} */

/** @name STAT - Status Register */ /** @{ */
#define LPUART_STAT_STAT_MASK                    (0xFFFFFFFFU)                                       /**< LPUART0_STAT.STAT Mask                  */
#define LPUART_STAT_STAT_SHIFT                   (0U)                                                /**< LPUART0_STAT.STAT Position              */
#define LPUART_STAT_STAT(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_STAT_SHIFT))&LPUART_STAT_STAT_MASK) /**< LPUART0_STAT.STAT Field                 */
#define LPUART_STAT_MA2F_MASK                    (0x4000U)                                           /**< LPUART0_STAT.MA2F Mask                  */
#define LPUART_STAT_MA2F_SHIFT                   (14U)                                               /**< LPUART0_STAT.MA2F Position              */
#define LPUART_STAT_MA2F(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MA2F_SHIFT))&LPUART_STAT_MA2F_MASK) /**< LPUART0_STAT.MA2F Field                 */
#define LPUART_STAT_MA1F_MASK                    (0x8000U)                                           /**< LPUART0_STAT.MA1F Mask                  */
#define LPUART_STAT_MA1F_SHIFT                   (15U)                                               /**< LPUART0_STAT.MA1F Position              */
#define LPUART_STAT_MA1F(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MA1F_SHIFT))&LPUART_STAT_MA1F_MASK) /**< LPUART0_STAT.MA1F Field                 */
#define LPUART_STAT_PF_MASK                      (0x10000U)                                          /**< LPUART0_STAT.PF Mask                    */
#define LPUART_STAT_PF_SHIFT                     (16U)                                               /**< LPUART0_STAT.PF Position                */
#define LPUART_STAT_PF(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_PF_SHIFT))&LPUART_STAT_PF_MASK) /**< LPUART0_STAT.PF Field                   */
#define LPUART_STAT_FE_MASK                      (0x20000U)                                          /**< LPUART0_STAT.FE Mask                    */
#define LPUART_STAT_FE_SHIFT                     (17U)                                               /**< LPUART0_STAT.FE Position                */
#define LPUART_STAT_FE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_FE_SHIFT))&LPUART_STAT_FE_MASK) /**< LPUART0_STAT.FE Field                   */
#define LPUART_STAT_NF_MASK                      (0x40000U)                                          /**< LPUART0_STAT.NF Mask                    */
#define LPUART_STAT_NF_SHIFT                     (18U)                                               /**< LPUART0_STAT.NF Position                */
#define LPUART_STAT_NF(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_NF_SHIFT))&LPUART_STAT_NF_MASK) /**< LPUART0_STAT.NF Field                   */
#define LPUART_STAT_OR_MASK                      (0x80000U)                                          /**< LPUART0_STAT.OR Mask                    */
#define LPUART_STAT_OR_SHIFT                     (19U)                                               /**< LPUART0_STAT.OR Position                */
#define LPUART_STAT_OR(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_OR_SHIFT))&LPUART_STAT_OR_MASK) /**< LPUART0_STAT.OR Field                   */
#define LPUART_STAT_IDLE_MASK                    (0x100000U)                                         /**< LPUART0_STAT.IDLE Mask                  */
#define LPUART_STAT_IDLE_SHIFT                   (20U)                                               /**< LPUART0_STAT.IDLE Position              */
#define LPUART_STAT_IDLE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_IDLE_SHIFT))&LPUART_STAT_IDLE_MASK) /**< LPUART0_STAT.IDLE Field                 */
#define LPUART_STAT_RDRF_MASK                    (0x200000U)                                         /**< LPUART0_STAT.RDRF Mask                  */
#define LPUART_STAT_RDRF_SHIFT                   (21U)                                               /**< LPUART0_STAT.RDRF Position              */
#define LPUART_STAT_RDRF(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RDRF_SHIFT))&LPUART_STAT_RDRF_MASK) /**< LPUART0_STAT.RDRF Field                 */
#define LPUART_STAT_TC_MASK                      (0x400000U)                                         /**< LPUART0_STAT.TC Mask                    */
#define LPUART_STAT_TC_SHIFT                     (22U)                                               /**< LPUART0_STAT.TC Position                */
#define LPUART_STAT_TC(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_TC_SHIFT))&LPUART_STAT_TC_MASK) /**< LPUART0_STAT.TC Field                   */
#define LPUART_STAT_TDRE_MASK                    (0x800000U)                                         /**< LPUART0_STAT.TDRE Mask                  */
#define LPUART_STAT_TDRE_SHIFT                   (23U)                                               /**< LPUART0_STAT.TDRE Position              */
#define LPUART_STAT_TDRE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_TDRE_SHIFT))&LPUART_STAT_TDRE_MASK) /**< LPUART0_STAT.TDRE Field                 */
#define LPUART_STAT_RAF_MASK                     (0x1000000U)                                        /**< LPUART0_STAT.RAF Mask                   */
#define LPUART_STAT_RAF_SHIFT                    (24U)                                               /**< LPUART0_STAT.RAF Position               */
#define LPUART_STAT_RAF(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RAF_SHIFT))&LPUART_STAT_RAF_MASK) /**< LPUART0_STAT.RAF Field                  */
#define LPUART_STAT_LBKDE_MASK                   (0x2000000U)                                        /**< LPUART0_STAT.LBKDE Mask                 */
#define LPUART_STAT_LBKDE_SHIFT                  (25U)                                               /**< LPUART0_STAT.LBKDE Position             */
#define LPUART_STAT_LBKDE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_LBKDE_SHIFT))&LPUART_STAT_LBKDE_MASK) /**< LPUART0_STAT.LBKDE Field                */
#define LPUART_STAT_BRK13_MASK                   (0x4000000U)                                        /**< LPUART0_STAT.BRK13 Mask                 */
#define LPUART_STAT_BRK13_SHIFT                  (26U)                                               /**< LPUART0_STAT.BRK13 Position             */
#define LPUART_STAT_BRK13(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_BRK13_SHIFT))&LPUART_STAT_BRK13_MASK) /**< LPUART0_STAT.BRK13 Field                */
#define LPUART_STAT_RWUID_MASK                   (0x8000000U)                                        /**< LPUART0_STAT.RWUID Mask                 */
#define LPUART_STAT_RWUID_SHIFT                  (27U)                                               /**< LPUART0_STAT.RWUID Position             */
#define LPUART_STAT_RWUID(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RWUID_SHIFT))&LPUART_STAT_RWUID_MASK) /**< LPUART0_STAT.RWUID Field                */
#define LPUART_STAT_RXINV_MASK                   (0x10000000U)                                       /**< LPUART0_STAT.RXINV Mask                 */
#define LPUART_STAT_RXINV_SHIFT                  (28U)                                               /**< LPUART0_STAT.RXINV Position             */
#define LPUART_STAT_RXINV(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RXINV_SHIFT))&LPUART_STAT_RXINV_MASK) /**< LPUART0_STAT.RXINV Field                */
#define LPUART_STAT_MSBF_MASK                    (0x20000000U)                                       /**< LPUART0_STAT.MSBF Mask                  */
#define LPUART_STAT_MSBF_SHIFT                   (29U)                                               /**< LPUART0_STAT.MSBF Position              */
#define LPUART_STAT_MSBF(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_MSBF_SHIFT))&LPUART_STAT_MSBF_MASK) /**< LPUART0_STAT.MSBF Field                 */
#define LPUART_STAT_RXEDGIF_MASK                 (0x40000000U)                                       /**< LPUART0_STAT.RXEDGIF Mask               */
#define LPUART_STAT_RXEDGIF_SHIFT                (30U)                                               /**< LPUART0_STAT.RXEDGIF Position           */
#define LPUART_STAT_RXEDGIF(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_RXEDGIF_SHIFT))&LPUART_STAT_RXEDGIF_MASK) /**< LPUART0_STAT.RXEDGIF Field              */
#define LPUART_STAT_LBKDIF_MASK                  (0x80000000U)                                       /**< LPUART0_STAT.LBKDIF Mask                */
#define LPUART_STAT_LBKDIF_SHIFT                 (31U)                                               /**< LPUART0_STAT.LBKDIF Position            */
#define LPUART_STAT_LBKDIF(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_STAT_LBKDIF_SHIFT))&LPUART_STAT_LBKDIF_MASK) /**< LPUART0_STAT.LBKDIF Field               */
/** @} */

/** @name CTRL - Control Register */ /** @{ */
#define LPUART_CTRL_CTRL_MASK                    (0xFFFFFFFFU)                                       /**< LPUART0_CTRL.CTRL Mask                  */
#define LPUART_CTRL_CTRL_SHIFT                   (0U)                                                /**< LPUART0_CTRL.CTRL Position              */
#define LPUART_CTRL_CTRL(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_CTRL_SHIFT))&LPUART_CTRL_CTRL_MASK) /**< LPUART0_CTRL.CTRL Field                 */
#define LPUART_CTRL_PT_MASK                      (0x1U)                                              /**< LPUART0_CTRL.PT Mask                    */
#define LPUART_CTRL_PT_SHIFT                     (0U)                                                /**< LPUART0_CTRL.PT Position                */
#define LPUART_CTRL_PT(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PT_SHIFT))&LPUART_CTRL_PT_MASK) /**< LPUART0_CTRL.PT Field                   */
#define LPUART_CTRL_PE_MASK                      (0x2U)                                              /**< LPUART0_CTRL.PE Mask                    */
#define LPUART_CTRL_PE_SHIFT                     (1U)                                                /**< LPUART0_CTRL.PE Position                */
#define LPUART_CTRL_PE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PE_SHIFT))&LPUART_CTRL_PE_MASK) /**< LPUART0_CTRL.PE Field                   */
#define LPUART_CTRL_ILT_MASK                     (0x4U)                                              /**< LPUART0_CTRL.ILT Mask                   */
#define LPUART_CTRL_ILT_SHIFT                    (2U)                                                /**< LPUART0_CTRL.ILT Position               */
#define LPUART_CTRL_ILT(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ILT_SHIFT))&LPUART_CTRL_ILT_MASK) /**< LPUART0_CTRL.ILT Field                  */
#define LPUART_CTRL_WAKE_MASK                    (0x8U)                                              /**< LPUART0_CTRL.WAKE Mask                  */
#define LPUART_CTRL_WAKE_SHIFT                   (3U)                                                /**< LPUART0_CTRL.WAKE Position              */
#define LPUART_CTRL_WAKE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_WAKE_SHIFT))&LPUART_CTRL_WAKE_MASK) /**< LPUART0_CTRL.WAKE Field                 */
#define LPUART_CTRL_M_MASK                       (0x10U)                                             /**< LPUART0_CTRL.M Mask                     */
#define LPUART_CTRL_M_SHIFT                      (4U)                                                /**< LPUART0_CTRL.M Position                 */
#define LPUART_CTRL_M(x)                         (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_M_SHIFT))&LPUART_CTRL_M_MASK) /**< LPUART0_CTRL.M Field                    */
#define LPUART_CTRL_RSRC_MASK                    (0x20U)                                             /**< LPUART0_CTRL.RSRC Mask                  */
#define LPUART_CTRL_RSRC_SHIFT                   (5U)                                                /**< LPUART0_CTRL.RSRC Position              */
#define LPUART_CTRL_RSRC(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RSRC_SHIFT))&LPUART_CTRL_RSRC_MASK) /**< LPUART0_CTRL.RSRC Field                 */
#define LPUART_CTRL_DOZEEN_MASK                  (0x40U)                                             /**< LPUART0_CTRL.DOZEEN Mask                */
#define LPUART_CTRL_DOZEEN_SHIFT                 (6U)                                                /**< LPUART0_CTRL.DOZEEN Position            */
#define LPUART_CTRL_DOZEEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_DOZEEN_SHIFT))&LPUART_CTRL_DOZEEN_MASK) /**< LPUART0_CTRL.DOZEEN Field               */
#define LPUART_CTRL_LOOPS_MASK                   (0x80U)                                             /**< LPUART0_CTRL.LOOPS Mask                 */
#define LPUART_CTRL_LOOPS_SHIFT                  (7U)                                                /**< LPUART0_CTRL.LOOPS Position             */
#define LPUART_CTRL_LOOPS(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_LOOPS_SHIFT))&LPUART_CTRL_LOOPS_MASK) /**< LPUART0_CTRL.LOOPS Field                */
#define LPUART_CTRL_IDLECFG_MASK                 (0x700U)                                            /**< LPUART0_CTRL.IDLECFG Mask               */
#define LPUART_CTRL_IDLECFG_SHIFT                (8U)                                                /**< LPUART0_CTRL.IDLECFG Position           */
#define LPUART_CTRL_IDLECFG(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_IDLECFG_SHIFT))&LPUART_CTRL_IDLECFG_MASK) /**< LPUART0_CTRL.IDLECFG Field              */
#define LPUART_CTRL_MA2IE_MASK                   (0x4000U)                                           /**< LPUART0_CTRL.MA2IE Mask                 */
#define LPUART_CTRL_MA2IE_SHIFT                  (14U)                                               /**< LPUART0_CTRL.MA2IE Position             */
#define LPUART_CTRL_MA2IE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_MA2IE_SHIFT))&LPUART_CTRL_MA2IE_MASK) /**< LPUART0_CTRL.MA2IE Field                */
#define LPUART_CTRL_MA1IE_MASK                   (0x8000U)                                           /**< LPUART0_CTRL.MA1IE Mask                 */
#define LPUART_CTRL_MA1IE_SHIFT                  (15U)                                               /**< LPUART0_CTRL.MA1IE Position             */
#define LPUART_CTRL_MA1IE(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_MA1IE_SHIFT))&LPUART_CTRL_MA1IE_MASK) /**< LPUART0_CTRL.MA1IE Field                */
#define LPUART_CTRL_SBK_MASK                     (0x10000U)                                          /**< LPUART0_CTRL.SBK Mask                   */
#define LPUART_CTRL_SBK_SHIFT                    (16U)                                               /**< LPUART0_CTRL.SBK Position               */
#define LPUART_CTRL_SBK(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_SBK_SHIFT))&LPUART_CTRL_SBK_MASK) /**< LPUART0_CTRL.SBK Field                  */
#define LPUART_CTRL_RWU_MASK                     (0x20000U)                                          /**< LPUART0_CTRL.RWU Mask                   */
#define LPUART_CTRL_RWU_SHIFT                    (17U)                                               /**< LPUART0_CTRL.RWU Position               */
#define LPUART_CTRL_RWU(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RWU_SHIFT))&LPUART_CTRL_RWU_MASK) /**< LPUART0_CTRL.RWU Field                  */
#define LPUART_CTRL_RE_MASK                      (0x40000U)                                          /**< LPUART0_CTRL.RE Mask                    */
#define LPUART_CTRL_RE_SHIFT                     (18U)                                               /**< LPUART0_CTRL.RE Position                */
#define LPUART_CTRL_RE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RE_SHIFT))&LPUART_CTRL_RE_MASK) /**< LPUART0_CTRL.RE Field                   */
#define LPUART_CTRL_TE_MASK                      (0x80000U)                                          /**< LPUART0_CTRL.TE Mask                    */
#define LPUART_CTRL_TE_SHIFT                     (19U)                                               /**< LPUART0_CTRL.TE Position                */
#define LPUART_CTRL_TE(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TE_SHIFT))&LPUART_CTRL_TE_MASK) /**< LPUART0_CTRL.TE Field                   */
#define LPUART_CTRL_ILIE_MASK                    (0x100000U)                                         /**< LPUART0_CTRL.ILIE Mask                  */
#define LPUART_CTRL_ILIE_SHIFT                   (20U)                                               /**< LPUART0_CTRL.ILIE Position              */
#define LPUART_CTRL_ILIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ILIE_SHIFT))&LPUART_CTRL_ILIE_MASK) /**< LPUART0_CTRL.ILIE Field                 */
#define LPUART_CTRL_RIE_MASK                     (0x200000U)                                         /**< LPUART0_CTRL.RIE Mask                   */
#define LPUART_CTRL_RIE_SHIFT                    (21U)                                               /**< LPUART0_CTRL.RIE Position               */
#define LPUART_CTRL_RIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_RIE_SHIFT))&LPUART_CTRL_RIE_MASK) /**< LPUART0_CTRL.RIE Field                  */
#define LPUART_CTRL_TCIE_MASK                    (0x400000U)                                         /**< LPUART0_CTRL.TCIE Mask                  */
#define LPUART_CTRL_TCIE_SHIFT                   (22U)                                               /**< LPUART0_CTRL.TCIE Position              */
#define LPUART_CTRL_TCIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TCIE_SHIFT))&LPUART_CTRL_TCIE_MASK) /**< LPUART0_CTRL.TCIE Field                 */
#define LPUART_CTRL_TIE_MASK                     (0x800000U)                                         /**< LPUART0_CTRL.TIE Mask                   */
#define LPUART_CTRL_TIE_SHIFT                    (23U)                                               /**< LPUART0_CTRL.TIE Position               */
#define LPUART_CTRL_TIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TIE_SHIFT))&LPUART_CTRL_TIE_MASK) /**< LPUART0_CTRL.TIE Field                  */
#define LPUART_CTRL_PEIE_MASK                    (0x1000000U)                                        /**< LPUART0_CTRL.PEIE Mask                  */
#define LPUART_CTRL_PEIE_SHIFT                   (24U)                                               /**< LPUART0_CTRL.PEIE Position              */
#define LPUART_CTRL_PEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_PEIE_SHIFT))&LPUART_CTRL_PEIE_MASK) /**< LPUART0_CTRL.PEIE Field                 */
#define LPUART_CTRL_FEIE_MASK                    (0x2000000U)                                        /**< LPUART0_CTRL.FEIE Mask                  */
#define LPUART_CTRL_FEIE_SHIFT                   (25U)                                               /**< LPUART0_CTRL.FEIE Position              */
#define LPUART_CTRL_FEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_FEIE_SHIFT))&LPUART_CTRL_FEIE_MASK) /**< LPUART0_CTRL.FEIE Field                 */
#define LPUART_CTRL_NEIE_MASK                    (0x4000000U)                                        /**< LPUART0_CTRL.NEIE Mask                  */
#define LPUART_CTRL_NEIE_SHIFT                   (26U)                                               /**< LPUART0_CTRL.NEIE Position              */
#define LPUART_CTRL_NEIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_NEIE_SHIFT))&LPUART_CTRL_NEIE_MASK) /**< LPUART0_CTRL.NEIE Field                 */
#define LPUART_CTRL_ORIE_MASK                    (0x8000000U)                                        /**< LPUART0_CTRL.ORIE Mask                  */
#define LPUART_CTRL_ORIE_SHIFT                   (27U)                                               /**< LPUART0_CTRL.ORIE Position              */
#define LPUART_CTRL_ORIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_ORIE_SHIFT))&LPUART_CTRL_ORIE_MASK) /**< LPUART0_CTRL.ORIE Field                 */
#define LPUART_CTRL_TXINV_MASK                   (0x10000000U)                                       /**< LPUART0_CTRL.TXINV Mask                 */
#define LPUART_CTRL_TXINV_SHIFT                  (28U)                                               /**< LPUART0_CTRL.TXINV Position             */
#define LPUART_CTRL_TXINV(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TXINV_SHIFT))&LPUART_CTRL_TXINV_MASK) /**< LPUART0_CTRL.TXINV Field                */
#define LPUART_CTRL_TXDIR_MASK                   (0x20000000U)                                       /**< LPUART0_CTRL.TXDIR Mask                 */
#define LPUART_CTRL_TXDIR_SHIFT                  (29U)                                               /**< LPUART0_CTRL.TXDIR Position             */
#define LPUART_CTRL_TXDIR(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_TXDIR_SHIFT))&LPUART_CTRL_TXDIR_MASK) /**< LPUART0_CTRL.TXDIR Field                */
#define LPUART_CTRL_R9T8_MASK                    (0x40000000U)                                       /**< LPUART0_CTRL.R9T8 Mask                  */
#define LPUART_CTRL_R9T8_SHIFT                   (30U)                                               /**< LPUART0_CTRL.R9T8 Position              */
#define LPUART_CTRL_R9T8(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_R9T8_SHIFT))&LPUART_CTRL_R9T8_MASK) /**< LPUART0_CTRL.R9T8 Field                 */
#define LPUART_CTRL_R8T9_MASK                    (0x80000000U)                                       /**< LPUART0_CTRL.R8T9 Mask                  */
#define LPUART_CTRL_R8T9_SHIFT                   (31U)                                               /**< LPUART0_CTRL.R8T9 Position              */
#define LPUART_CTRL_R8T9(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_CTRL_R8T9_SHIFT))&LPUART_CTRL_R8T9_MASK) /**< LPUART0_CTRL.R8T9 Field                 */
/** @} */

/** @name DATA - Data Register */ /** @{ */
#define LPUART_DATA_RT_MASK                      (0x3FFU)                                            /**< LPUART0_DATA.RT Mask                    */
#define LPUART_DATA_RT_SHIFT                     (0U)                                                /**< LPUART0_DATA.RT Position                */
#define LPUART_DATA_RT(x)                        (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_RT_SHIFT))&LPUART_DATA_RT_MASK) /**< LPUART0_DATA.RT Field                   */
#define LPUART_DATA_IDLINE_MASK                  (0x800U)                                            /**< LPUART0_DATA.IDLINE Mask                */
#define LPUART_DATA_IDLINE_SHIFT                 (11U)                                               /**< LPUART0_DATA.IDLINE Position            */
#define LPUART_DATA_IDLINE(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_IDLINE_SHIFT))&LPUART_DATA_IDLINE_MASK) /**< LPUART0_DATA.IDLINE Field               */
#define LPUART_DATA_RXEMPT_MASK                  (0x1000U)                                           /**< LPUART0_DATA.RXEMPT Mask                */
#define LPUART_DATA_RXEMPT_SHIFT                 (12U)                                               /**< LPUART0_DATA.RXEMPT Position            */
#define LPUART_DATA_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_RXEMPT_SHIFT))&LPUART_DATA_RXEMPT_MASK) /**< LPUART0_DATA.RXEMPT Field               */
#define LPUART_DATA_FRAME_MASK                   (0x2000U)                                           /**< LPUART0_DATA.FRAME Mask                 */
#define LPUART_DATA_FRAME_SHIFT                  (13U)                                               /**< LPUART0_DATA.FRAME Position             */
#define LPUART_DATA_FRAME(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_FRAME_SHIFT))&LPUART_DATA_FRAME_MASK) /**< LPUART0_DATA.FRAME Field                */
#define LPUART_DATA_TXSPECIAL_MASK               (0x2000U)                                           /**< LPUART0_DATA.TXSPECIAL Mask             */
#define LPUART_DATA_TXSPECIAL_SHIFT              (13U)                                               /**< LPUART0_DATA.TXSPECIAL Position         */
#define LPUART_DATA_TXSPECIAL(x)                 (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_TXSPECIAL_SHIFT))&LPUART_DATA_TXSPECIAL_MASK) /**< LPUART0_DATA.TXSPECIAL Field            */
#define LPUART_DATA_PARITYE_MASK                 (0x4000U)                                           /**< LPUART0_DATA.PARITYE Mask               */
#define LPUART_DATA_PARITYE_SHIFT                (14U)                                               /**< LPUART0_DATA.PARITYE Position           */
#define LPUART_DATA_PARITYE(x)                   (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_PARITYE_SHIFT))&LPUART_DATA_PARITYE_MASK) /**< LPUART0_DATA.PARITYE Field              */
#define LPUART_DATA_NOISY_MASK                   (0x8000U)                                           /**< LPUART0_DATA.NOISY Mask                 */
#define LPUART_DATA_NOISY_SHIFT                  (15U)                                               /**< LPUART0_DATA.NOISY Position             */
#define LPUART_DATA_NOISY(x)                     (((uint32_t)(((uint32_t)(x))<<LPUART_DATA_NOISY_SHIFT))&LPUART_DATA_NOISY_MASK) /**< LPUART0_DATA.NOISY Field                */
/** @} */

/** @name MATCH - Match Address Register */ /** @{ */
#define LPUART_MATCH_MA1_MASK                    (0x3FFU)                                            /**< LPUART0_MATCH.MA1 Mask                  */
#define LPUART_MATCH_MA1_SHIFT                   (0U)                                                /**< LPUART0_MATCH.MA1 Position              */
#define LPUART_MATCH_MA1(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_MATCH_MA1_SHIFT))&LPUART_MATCH_MA1_MASK) /**< LPUART0_MATCH.MA1 Field                 */
#define LPUART_MATCH_MA2_MASK                    (0x3FF0000U)                                        /**< LPUART0_MATCH.MA2 Mask                  */
#define LPUART_MATCH_MA2_SHIFT                   (16U)                                               /**< LPUART0_MATCH.MA2 Position              */
#define LPUART_MATCH_MA2(x)                      (((uint32_t)(((uint32_t)(x))<<LPUART_MATCH_MA2_SHIFT))&LPUART_MATCH_MA2_MASK) /**< LPUART0_MATCH.MA2 Field                 */
/** @} */

/** @} */ /* End group LPUART_Register_Masks_GROUP */


/* LPUART0 - Peripheral instance base addresses */
#define LPUART0_BasePtr                0x40054000UL //!< Peripheral base address
#define LPUART0                        ((LPUART_Type *) LPUART0_BasePtr) //!< Freescale base pointer
#define LPUART0_BASE_PTR               (LPUART0) //!< Freescale style base pointer
#define LPUART0_IRQS { LPUART0_IRQn,  }


/** @} */ /* End group LPUART_Peripheral_access_layer_GROUP */


/** @brief C Struct for LPUART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup LPUART_Peripheral_access_layer_GROUP LPUART Peripheral Access Layer */
/** @{ */

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
#define LPUART1_IRQS { LPUART1_IRQn,  }


/** @} */ /* End group LPUART_Peripheral_access_layer_GROUP */


/** @brief C Struct for MCG */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           MCG (file:MCG_LITE_HIRCLPEN)         ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator Lite
 */
/**
 * @struct MCG_Type
 * @brief  C Struct allowing access to MCG registers
 */
typedef struct MCG_Type {
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
        uint8_t   RESERVED_0[4];                /**< 0002: 0x4 bytes                                                    */
   __I  uint8_t   S;                            /**< 0006: Status Register                                              */
        uint8_t   RESERVED_1;                   /**< 0007: 0x1 bytes                                                    */
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
        uint8_t   RESERVED_2[11];               /**< 0009: 0xB bytes                                                    */
   __I  uint8_t   HCTRIM;                       /**< 0014: High-frequency IRC Coarse Trim Register                      */
   __I  uint8_t   HTTRIM;                       /**< 0015: High-frequency IRC Tempco (Temperature Coefficient) Trim Register */
   __I  uint8_t   HFTRIM;                       /**< 0016: High-frequency IRC Fine Trim Register                        */
        uint8_t   RESERVED_3;                   /**< 0017: 0x1 bytes                                                    */
   __IO uint8_t   MC;                           /**< 0018: Miscellaneous Control Register                               */
   __I  uint8_t   LTRIMRNG;                     /**< 0019: Low-frequency IRC Trim Range Register                        */
   __I  uint8_t   LFTRIM;                       /**< 001A: Low-frequency IRC8M Trim Register                            */
   __I  uint8_t   LSTRIM;                       /**< 001B: Low-frequency IRC2M Trim Register                            */
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
#define MCG_C1_CLKS_MASK                         (0xC0U)                                             /**< MCG_C1.CLKS Mask                        */
#define MCG_C1_CLKS_SHIFT                        (6U)                                                /**< MCG_C1.CLKS Position                    */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK) /**< MCG_C1.CLKS Field                       */
/** @} */

/** @name C2 - Control 2 Register */ /** @{ */
#define MCG_C2_IRCS_MASK                         (0x1U)                                              /**< MCG_C2.IRCS Mask                        */
#define MCG_C2_IRCS_SHIFT                        (0U)                                                /**< MCG_C2.IRCS Position                    */
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_IRCS_SHIFT))&MCG_C2_IRCS_MASK) /**< MCG_C2.IRCS Field                       */
#define MCG_C2_EREFS0_MASK                       (0x4U)                                              /**< MCG_C2.EREFS0 Mask                      */
#define MCG_C2_EREFS0_SHIFT                      (2U)                                                /**< MCG_C2.EREFS0 Position                  */
#define MCG_C2_EREFS0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_EREFS0_SHIFT))&MCG_C2_EREFS0_MASK) /**< MCG_C2.EREFS0 Field                     */
#define MCG_C2_HGO0_MASK                         (0x8U)                                              /**< MCG_C2.HGO0 Mask                        */
#define MCG_C2_HGO0_SHIFT                        (3U)                                                /**< MCG_C2.HGO0 Position                    */
#define MCG_C2_HGO0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_HGO0_SHIFT))&MCG_C2_HGO0_MASK) /**< MCG_C2.HGO0 Field                       */
#define MCG_C2_RANGE0_MASK                       (0x30U)                                             /**< MCG_C2.RANGE0 Mask                      */
#define MCG_C2_RANGE0_SHIFT                      (4U)                                                /**< MCG_C2.RANGE0 Position                  */
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK) /**< MCG_C2.RANGE0 Field                     */
/** @} */

/** @name S - Status Register */ /** @{ */
#define MCG_S_OSCINIT0_MASK                      (0x2U)                                              /**< MCG_S.OSCINIT0 Mask                     */
#define MCG_S_OSCINIT0_SHIFT                     (1U)                                                /**< MCG_S.OSCINIT0 Position                 */
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_S_OSCINIT0_SHIFT))&MCG_S_OSCINIT0_MASK) /**< MCG_S.OSCINIT0 Field                    */
#define MCG_S_CLKST_MASK                         (0xCU)                                              /**< MCG_S.CLKST Mask                        */
#define MCG_S_CLKST_SHIFT                        (2U)                                                /**< MCG_S.CLKST Position                    */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK) /**< MCG_S.CLKST Field                       */
/** @} */

/** @name SC - Status and Control Register */ /** @{ */
#define MCG_SC_FCRDIV_MASK                       (0xEU)                                              /**< MCG_SC.FCRDIV Mask                      */
#define MCG_SC_FCRDIV_SHIFT                      (1U)                                                /**< MCG_SC.FCRDIV Position                  */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK) /**< MCG_SC.FCRDIV Field                     */
/** @} */

/** @name HCTRIM - High-frequency IRC Coarse Trim Register */ /** @{ */
#define MCG_HCTRIM_COARSE_TRIM_MASK              (0x3FU)                                             /**< MCG_HCTRIM.COARSE_TRIM Mask             */
#define MCG_HCTRIM_COARSE_TRIM_SHIFT             (0U)                                                /**< MCG_HCTRIM.COARSE_TRIM Position         */
#define MCG_HCTRIM_COARSE_TRIM(x)                (((uint8_t)(((uint8_t)(x))<<MCG_HCTRIM_COARSE_TRIM_SHIFT))&MCG_HCTRIM_COARSE_TRIM_MASK) /**< MCG_HCTRIM.COARSE_TRIM Field            */
/** @} */

/** @name HTTRIM - High-frequency IRC Tempco (Temperature Coefficient) Trim Register */ /** @{ */
#define MCG_HTTRIM_TEMPCO_TRIM_MASK              (0x1FU)                                             /**< MCG_HTTRIM.TEMPCO_TRIM Mask             */
#define MCG_HTTRIM_TEMPCO_TRIM_SHIFT             (0U)                                                /**< MCG_HTTRIM.TEMPCO_TRIM Position         */
#define MCG_HTTRIM_TEMPCO_TRIM(x)                (((uint8_t)(((uint8_t)(x))<<MCG_HTTRIM_TEMPCO_TRIM_SHIFT))&MCG_HTTRIM_TEMPCO_TRIM_MASK) /**< MCG_HTTRIM.TEMPCO_TRIM Field            */
/** @} */

/** @name HFTRIM - High-frequency IRC Fine Trim Register */ /** @{ */
#define MCG_HFTRIM_FINE_TRIM_MASK                (0x7FU)                                             /**< MCG_HFTRIM.FINE_TRIM Mask               */
#define MCG_HFTRIM_FINE_TRIM_SHIFT               (0U)                                                /**< MCG_HFTRIM.FINE_TRIM Position           */
#define MCG_HFTRIM_FINE_TRIM(x)                  (((uint8_t)(((uint8_t)(x))<<MCG_HFTRIM_FINE_TRIM_SHIFT))&MCG_HFTRIM_FINE_TRIM_MASK) /**< MCG_HFTRIM.FINE_TRIM Field              */
/** @} */

/** @name MC - Miscellaneous Control Register */ /** @{ */
#define MCG_MC_LIRC_DIV2_MASK                    (0x7U)                                              /**< MCG_MC.LIRC_DIV2 Mask                   */
#define MCG_MC_LIRC_DIV2_SHIFT                   (0U)                                                /**< MCG_MC.LIRC_DIV2 Position               */
#define MCG_MC_LIRC_DIV2(x)                      (((uint8_t)(((uint8_t)(x))<<MCG_MC_LIRC_DIV2_SHIFT))&MCG_MC_LIRC_DIV2_MASK) /**< MCG_MC.LIRC_DIV2 Field                  */
#define MCG_MC_HIRCLPEN_MASK                     (0x40U)                                             /**< MCG_MC.HIRCLPEN Mask                    */
#define MCG_MC_HIRCLPEN_SHIFT                    (6U)                                                /**< MCG_MC.HIRCLPEN Position                */
#define MCG_MC_HIRCLPEN(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_MC_HIRCLPEN_SHIFT))&MCG_MC_HIRCLPEN_MASK) /**< MCG_MC.HIRCLPEN Field                   */
#define MCG_MC_HIRCEN_MASK                       (0x80U)                                             /**< MCG_MC.HIRCEN Mask                      */
#define MCG_MC_HIRCEN_SHIFT                      (7U)                                                /**< MCG_MC.HIRCEN Position                  */
#define MCG_MC_HIRCEN(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_MC_HIRCEN_SHIFT))&MCG_MC_HIRCEN_MASK) /**< MCG_MC.HIRCEN Field                     */
/** @} */

/** @name LTRIMRNG - Low-frequency IRC Trim Range Register */ /** @{ */
#define MCG_LTRIMRNG_STRIMRNG_MASK               (0x3U)                                              /**< MCG_LTRIMRNG.STRIMRNG Mask              */
#define MCG_LTRIMRNG_STRIMRNG_SHIFT              (0U)                                                /**< MCG_LTRIMRNG.STRIMRNG Position          */
#define MCG_LTRIMRNG_STRIMRNG(x)                 (((uint8_t)(((uint8_t)(x))<<MCG_LTRIMRNG_STRIMRNG_SHIFT))&MCG_LTRIMRNG_STRIMRNG_MASK) /**< MCG_LTRIMRNG.STRIMRNG Field             */
#define MCG_LTRIMRNG_FTRIMRNG_MASK               (0xCU)                                              /**< MCG_LTRIMRNG.FTRIMRNG Mask              */
#define MCG_LTRIMRNG_FTRIMRNG_SHIFT              (2U)                                                /**< MCG_LTRIMRNG.FTRIMRNG Position          */
#define MCG_LTRIMRNG_FTRIMRNG(x)                 (((uint8_t)(((uint8_t)(x))<<MCG_LTRIMRNG_FTRIMRNG_SHIFT))&MCG_LTRIMRNG_FTRIMRNG_MASK) /**< MCG_LTRIMRNG.FTRIMRNG Field             */
/** @} */

/** @name LFTRIM - Low-frequency IRC8M Trim Register */ /** @{ */
#define MCG_LFTRIM_LIRC_FTRIM_MASK               (0x7FU)                                             /**< MCG_LFTRIM.LIRC_FTRIM Mask              */
#define MCG_LFTRIM_LIRC_FTRIM_SHIFT              (0U)                                                /**< MCG_LFTRIM.LIRC_FTRIM Position          */
#define MCG_LFTRIM_LIRC_FTRIM(x)                 (((uint8_t)(((uint8_t)(x))<<MCG_LFTRIM_LIRC_FTRIM_SHIFT))&MCG_LFTRIM_LIRC_FTRIM_MASK) /**< MCG_LFTRIM.LIRC_FTRIM Field             */
/** @} */

/** @name LSTRIM - Low-frequency IRC2M Trim Register */ /** @{ */
#define MCG_LSTRIM_LIRC_STRIM_MASK               (0x7FU)                                             /**< MCG_LSTRIM.LIRC_STRIM Mask              */
#define MCG_LSTRIM_LIRC_STRIM_SHIFT              (0U)                                                /**< MCG_LSTRIM.LIRC_STRIM Position          */
#define MCG_LSTRIM_LIRC_STRIM(x)                 (((uint8_t)(((uint8_t)(x))<<MCG_LSTRIM_LIRC_STRIM_SHIFT))&MCG_LSTRIM_LIRC_STRIM_MASK) /**< MCG_LSTRIM.LIRC_STRIM Field             */
/** @} */

/** @} */ /* End group MCG_Register_Masks_GROUP */


/* MCG - Peripheral instance base addresses */
#define MCG_BasePtr                    0x40064000UL //!< Peripheral base address
#define MCG                            ((MCG_Type *) MCG_BasePtr) //!< Freescale base pointer
#define MCG_BASE_PTR                   (MCG) //!< Freescale style base pointer

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
/* ================           NV (file:NV_MKL5)                    ================ */
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
   __I  uint8_t   FPROT3;                       /**< 0008: Non-volatile P-Flash Protection 1 - Low Register             */
   __I  uint8_t   FPROT2;                       /**< 0009: Non-volatile P-Flash Protection 1 - High Register            */
   __I  uint8_t   FPROT1;                       /**< 000A: Non-volatile P-Flash Protection 0 - Low Register             */
   __I  uint8_t   FPROT0;                       /**< 000B: Non-volatile P-Flash Protection 0 - High Register            */
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

/** @name FPROT3 - Non-volatile P-Flash Protection 1 - Low Register */ /** @{ */
#define NV_FPROT3_PROT_MASK                      (0xFFU)                                             /**< NV_FPROT3.PROT Mask                     */
#define NV_FPROT3_PROT_SHIFT                     (0U)                                                /**< NV_FPROT3.PROT Position                 */
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT3_PROT_SHIFT))&NV_FPROT3_PROT_MASK) /**< NV_FPROT3.PROT Field                    */
/** @} */

/** @name FPROT2 - Non-volatile P-Flash Protection 1 - High Register */ /** @{ */
#define NV_FPROT2_PROT_MASK                      (0xFFU)                                             /**< NV_FPROT2.PROT Mask                     */
#define NV_FPROT2_PROT_SHIFT                     (0U)                                                /**< NV_FPROT2.PROT Position                 */
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT2_PROT_SHIFT))&NV_FPROT2_PROT_MASK) /**< NV_FPROT2.PROT Field                    */
/** @} */

/** @name FPROT1 - Non-volatile P-Flash Protection 0 - Low Register */ /** @{ */
#define NV_FPROT1_PROT_MASK                      (0xFFU)                                             /**< NV_FPROT1.PROT Mask                     */
#define NV_FPROT1_PROT_SHIFT                     (0U)                                                /**< NV_FPROT1.PROT Position                 */
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT1_PROT_SHIFT))&NV_FPROT1_PROT_MASK) /**< NV_FPROT1.PROT Field                    */
/** @} */

/** @name FPROT0 - Non-volatile P-Flash Protection 0 - High Register */ /** @{ */
#define NV_FPROT0_PROT_MASK                      (0xFFU)                                             /**< NV_FPROT0.PROT Mask                     */
#define NV_FPROT0_PROT_SHIFT                     (0U)                                                /**< NV_FPROT0.PROT Position                 */
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FPROT0_PROT_SHIFT))&NV_FPROT0_PROT_MASK) /**< NV_FPROT0.PROT Field                    */
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
#define NV_FOPT_BOOTPIN_OPT_MASK                 (0x2U)                                              /**< NV_FOPT.BOOTPIN_OPT Mask                */
#define NV_FOPT_BOOTPIN_OPT_SHIFT                (1U)                                                /**< NV_FOPT.BOOTPIN_OPT Position            */
#define NV_FOPT_BOOTPIN_OPT(x)                   (((uint8_t)(((uint8_t)(x))<<NV_FOPT_BOOTPIN_OPT_SHIFT))&NV_FOPT_BOOTPIN_OPT_MASK) /**< NV_FOPT.BOOTPIN_OPT Field               */
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
#define NV_FOPT_BOOTSRC_SEL_MASK                 (0xC0U)                                             /**< NV_FOPT.BOOTSRC_SEL Mask                */
#define NV_FOPT_BOOTSRC_SEL_SHIFT                (6U)                                                /**< NV_FOPT.BOOTSRC_SEL Position            */
#define NV_FOPT_BOOTSRC_SEL(x)                   (((uint8_t)(((uint8_t)(x))<<NV_FOPT_BOOTSRC_SEL_SHIFT))&NV_FOPT_BOOTSRC_SEL_MASK) /**< NV_FOPT.BOOTSRC_SEL Field               */
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
/* ================           PMC (file:PMC_MKL27644)              ================ */
/* ================================================================================ */

/**
 * @brief Power Management Controller
 */
/**
 * @struct PMC_Type
 * @brief  C Struct allowing access to PMC registers
 */
typedef struct PMC_Type {
   __IO uint8_t   LVDSC1;                       /**< 0000: Low Voltage Detect Status and Control 1 Register             */
   __IO uint8_t   LVDSC2;                       /**< 0001: Low Voltage Status and Control 2                             */
   __IO uint8_t   REGSC;                        /**< 0002: Regulator Status and Control                                 */
} PMC_Type;


/** @brief Register Masks for PMC */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup PMC_Register_Masks_GROUP PMC Register Masks */
/** @{ */

/** @name LVDSC1 - Low Voltage Detect Status and Control 1 Register */ /** @{ */
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
#define PMC_REGSC_VLPO_MASK                      (0x40U)                                             /**< PMC_REGSC.VLPO Mask                     */
#define PMC_REGSC_VLPO_SHIFT                     (6U)                                                /**< PMC_REGSC.VLPO Position                 */
#define PMC_REGSC_VLPO(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_VLPO_SHIFT))&PMC_REGSC_VLPO_MASK) /**< PMC_REGSC.VLPO Field                    */
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
#define PORTB_IRQS { PORTBCDE_IRQn,  }


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
#define PORTC_IRQS { PORTBCDE_IRQn,  }


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
#define PORTD_IRQS { PORTBCDE_IRQn,  }


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
#define PORTE_IRQS { PORTBCDE_IRQn,  }


/** @} */ /* End group PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for RCM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           RCM (file:RCM_MKL03Z4)               ================ */
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
   __IO uint8_t   FM;                           /**< 0006: Force Mode Register                                          */
   __IO uint8_t   MR;                           /**< 0007: Mode Register                                                */
   __IO uint8_t   SSRS0;                        /**< 0008: Sticky System Reset Status Register 0                        */
   __IO uint8_t   SSRS1;                        /**< 0009: Sticky System Reset Status Register 1                        */
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

/** @name FM - Force Mode Register */ /** @{ */
#define RCM_FM_FORCEROM_MASK                     (0x6U)                                              /**< RCM_FM.FORCEROM Mask                    */
#define RCM_FM_FORCEROM_SHIFT                    (1U)                                                /**< RCM_FM.FORCEROM Position                */
#define RCM_FM_FORCEROM(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_FM_FORCEROM_SHIFT))&RCM_FM_FORCEROM_MASK) /**< RCM_FM.FORCEROM Field                   */
/** @} */

/** @name MR - Mode Register */ /** @{ */
#define RCM_MR_BOOTROM_MASK                      (0x6U)                                              /**< RCM_MR.BOOTROM Mask                     */
#define RCM_MR_BOOTROM_SHIFT                     (1U)                                                /**< RCM_MR.BOOTROM Position                 */
#define RCM_MR_BOOTROM(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_MR_BOOTROM_SHIFT))&RCM_MR_BOOTROM_MASK) /**< RCM_MR.BOOTROM Field                    */
/** @} */

/** @name SSRS0 - Sticky System Reset Status Register 0 */ /** @{ */
#define RCM_SSRS0_SWAKEUP_MASK                   (0x1U)                                              /**< RCM_SSRS0.SWAKEUP Mask                  */
#define RCM_SSRS0_SWAKEUP_SHIFT                  (0U)                                                /**< RCM_SSRS0.SWAKEUP Position              */
#define RCM_SSRS0_SWAKEUP(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SWAKEUP_SHIFT))&RCM_SSRS0_SWAKEUP_MASK) /**< RCM_SSRS0.SWAKEUP Field                 */
#define RCM_SSRS0_SLVD_MASK                      (0x2U)                                              /**< RCM_SSRS0.SLVD Mask                     */
#define RCM_SSRS0_SLVD_SHIFT                     (1U)                                                /**< RCM_SSRS0.SLVD Position                 */
#define RCM_SSRS0_SLVD(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SLVD_SHIFT))&RCM_SSRS0_SLVD_MASK) /**< RCM_SSRS0.SLVD Field                    */
#define RCM_SSRS0_SWDOG_MASK                     (0x20U)                                             /**< RCM_SSRS0.SWDOG Mask                    */
#define RCM_SSRS0_SWDOG_SHIFT                    (5U)                                                /**< RCM_SSRS0.SWDOG Position                */
#define RCM_SSRS0_SWDOG(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SWDOG_SHIFT))&RCM_SSRS0_SWDOG_MASK) /**< RCM_SSRS0.SWDOG Field                   */
#define RCM_SSRS0_SPIN_MASK                      (0x40U)                                             /**< RCM_SSRS0.SPIN Mask                     */
#define RCM_SSRS0_SPIN_SHIFT                     (6U)                                                /**< RCM_SSRS0.SPIN Position                 */
#define RCM_SSRS0_SPIN(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SPIN_SHIFT))&RCM_SSRS0_SPIN_MASK) /**< RCM_SSRS0.SPIN Field                    */
#define RCM_SSRS0_SPOR_MASK                      (0x80U)                                             /**< RCM_SSRS0.SPOR Mask                     */
#define RCM_SSRS0_SPOR_SHIFT                     (7U)                                                /**< RCM_SSRS0.SPOR Position                 */
#define RCM_SSRS0_SPOR(x)                        (((uint8_t)(((uint8_t)(x))<<RCM_SSRS0_SPOR_SHIFT))&RCM_SSRS0_SPOR_MASK) /**< RCM_SSRS0.SPOR Field                    */
/** @} */

/** @name SSRS1 - Sticky System Reset Status Register 1 */ /** @{ */
#define RCM_SSRS1_SLOCKUP_MASK                   (0x2U)                                              /**< RCM_SSRS1.SLOCKUP Mask                  */
#define RCM_SSRS1_SLOCKUP_SHIFT                  (1U)                                                /**< RCM_SSRS1.SLOCKUP Position              */
#define RCM_SSRS1_SLOCKUP(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_SSRS1_SLOCKUP_SHIFT))&RCM_SSRS1_SLOCKUP_MASK) /**< RCM_SSRS1.SLOCKUP Field                 */
#define RCM_SSRS1_SSW_MASK                       (0x4U)                                              /**< RCM_SSRS1.SSW Mask                      */
#define RCM_SSRS1_SSW_SHIFT                      (2U)                                                /**< RCM_SSRS1.SSW Position                  */
#define RCM_SSRS1_SSW(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SSRS1_SSW_SHIFT))&RCM_SSRS1_SSW_MASK) /**< RCM_SSRS1.SSW Field                     */
#define RCM_SSRS1_SMDM_AP_MASK                   (0x8U)                                              /**< RCM_SSRS1.SMDM_AP Mask                  */
#define RCM_SSRS1_SMDM_AP_SHIFT                  (3U)                                                /**< RCM_SSRS1.SMDM_AP Position              */
#define RCM_SSRS1_SMDM_AP(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_SSRS1_SMDM_AP_SHIFT))&RCM_SSRS1_SMDM_AP_MASK) /**< RCM_SSRS1.SMDM_AP Field                 */
#define RCM_SSRS1_SSACKERR_MASK                  (0x20U)                                             /**< RCM_SSRS1.SSACKERR Mask                 */
#define RCM_SSRS1_SSACKERR_SHIFT                 (5U)                                                /**< RCM_SSRS1.SSACKERR Position             */
#define RCM_SSRS1_SSACKERR(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_SSRS1_SSACKERR_SHIFT))&RCM_SSRS1_SSACKERR_MASK) /**< RCM_SSRS1.SSACKERR Field                */
/** @} */

/** @} */ /* End group RCM_Register_Masks_GROUP */


/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x4007F000UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer

/** @} */ /* End group RCM_Peripheral_access_layer_GROUP */


/** @brief C Struct for RFSYS */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup RFSYS_Peripheral_access_layer_GROUP RFSYS Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           RFSYS (file:RFSYS_0)                 ================ */
/* ================================================================================ */

/**
 * @brief System register file
 */
/**
 * @struct RFSYS_Type
 * @brief  C Struct allowing access to RFSYS registers
 */
typedef struct RFSYS_Type {
   __IO uint32_t  REG[8];                       /**< 0000: Register file register                                       */
} RFSYS_Type;


/** @brief Register Masks for RFSYS */

/* -------------------------------------------------------------------------------- */
/* -----------     'RFSYS' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup RFSYS_Register_Masks_GROUP RFSYS Register Masks */
/** @{ */

/** @name REG - Register file register */ /** @{ */
#define RFSYS_REG_LL_MASK                        (0xFFU)                                             /**< RFSYS_REG.LL Mask                       */
#define RFSYS_REG_LL_SHIFT                       (0U)                                                /**< RFSYS_REG.LL Position                   */
#define RFSYS_REG_LL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LL_SHIFT))&RFSYS_REG_LL_MASK) /**< RFSYS_REG.LL Field                      */
#define RFSYS_REG_LH_MASK                        (0xFF00U)                                           /**< RFSYS_REG.LH Mask                       */
#define RFSYS_REG_LH_SHIFT                       (8U)                                                /**< RFSYS_REG.LH Position                   */
#define RFSYS_REG_LH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LH_SHIFT))&RFSYS_REG_LH_MASK) /**< RFSYS_REG.LH Field                      */
#define RFSYS_REG_HL_MASK                        (0xFF0000U)                                         /**< RFSYS_REG.HL Mask                       */
#define RFSYS_REG_HL_SHIFT                       (16U)                                               /**< RFSYS_REG.HL Position                   */
#define RFSYS_REG_HL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HL_SHIFT))&RFSYS_REG_HL_MASK) /**< RFSYS_REG.HL Field                      */
#define RFSYS_REG_HH_MASK                        (0xFF000000U)                                       /**< RFSYS_REG.HH Mask                       */
#define RFSYS_REG_HH_SHIFT                       (24U)                                               /**< RFSYS_REG.HH Position                   */
#define RFSYS_REG_HH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HH_SHIFT))&RFSYS_REG_HH_MASK) /**< RFSYS_REG.HH Field                      */
/** @} */

/** @} */ /* End group RFSYS_Register_Masks_GROUP */


/* RFSYS - Peripheral instance base addresses */
#define RFSYS_BasePtr                  0x40041000UL //!< Peripheral base address
#define RFSYS                          ((RFSYS_Type *) RFSYS_BasePtr) //!< Freescale base pointer
#define RFSYS_BASE_PTR                 (RFSYS) //!< Freescale style base pointer

/** @} */ /* End group RFSYS_Peripheral_access_layer_GROUP */


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
/* ================           RTC (file:RTC_WPS_MKL03Z4)           ================ */
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
#define RTC_CR_WPS_MASK                          (0x10U)                                             /**< RTC_CR.WPS Mask                         */
#define RTC_CR_WPS_SHIFT                         (4U)                                                /**< RTC_CR.WPS Position                     */
#define RTC_CR_WPS(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_WPS_SHIFT))&RTC_CR_WPS_MASK) /**< RTC_CR.WPS Field                        */
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
/* ================           SIM (file:SIM_MKL27Z644)             ================ */
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
        uint8_t   RESERVED_0[4096];             /**< 0004: 0x1000 bytes                                                 */
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
#define SIM_SOPT1_OSC32KOUT_MASK                 (0x30000U)                                          /**< SIM_SOPT1.OSC32KOUT Mask                */
#define SIM_SOPT1_OSC32KOUT_SHIFT                (16U)                                               /**< SIM_SOPT1.OSC32KOUT Position            */
#define SIM_SOPT1_OSC32KOUT(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KOUT_SHIFT))&SIM_SOPT1_OSC32KOUT_MASK) /**< SIM_SOPT1.OSC32KOUT Field               */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)                                          /**< SIM_SOPT1.OSC32KSEL Mask                */
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)                                               /**< SIM_SOPT1.OSC32KSEL Position            */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK) /**< SIM_SOPT1.OSC32KSEL Field               */
/** @} */

/** @name SOPT2 - System Options Register 2 */ /** @{ */
#define SIM_SOPT2_RTCCLKOUTSEL_MASK              (0x10U)                                             /**< SIM_SOPT2.RTCCLKOUTSEL Mask             */
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT             (4U)                                                /**< SIM_SOPT2.RTCCLKOUTSEL Position         */
#define SIM_SOPT2_RTCCLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_RTCCLKOUTSEL_SHIFT))&SIM_SOPT2_RTCCLKOUTSEL_MASK) /**< SIM_SOPT2.RTCCLKOUTSEL Field            */
#define SIM_SOPT2_CLKOUTSEL_MASK                 (0xE0U)                                             /**< SIM_SOPT2.CLKOUTSEL Mask                */
#define SIM_SOPT2_CLKOUTSEL_SHIFT                (5U)                                                /**< SIM_SOPT2.CLKOUTSEL Position            */
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_CLKOUTSEL_SHIFT))&SIM_SOPT2_CLKOUTSEL_MASK) /**< SIM_SOPT2.CLKOUTSEL Field               */
#define SIM_SOPT2_USBSRC_MASK                    (0x40000U)                                          /**< SIM_SOPT2.USBSRC Mask                   */
#define SIM_SOPT2_USBSRC_SHIFT                   (18U)                                               /**< SIM_SOPT2.USBSRC Position               */
#define SIM_SOPT2_USBSRC(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_USBSRC_SHIFT))&SIM_SOPT2_USBSRC_MASK) /**< SIM_SOPT2.USBSRC Field                  */
#define SIM_SOPT2_FLEXIOSRC_MASK                 (0xC00000U)                                         /**< SIM_SOPT2.FLEXIOSRC Mask                */
#define SIM_SOPT2_FLEXIOSRC_SHIFT                (22U)                                               /**< SIM_SOPT2.FLEXIOSRC Position            */
#define SIM_SOPT2_FLEXIOSRC(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_FLEXIOSRC_SHIFT))&SIM_SOPT2_FLEXIOSRC_MASK) /**< SIM_SOPT2.FLEXIOSRC Field               */
#define SIM_SOPT2_TPMSRC_MASK                    (0x3000000U)                                        /**< SIM_SOPT2.TPMSRC Mask                   */
#define SIM_SOPT2_TPMSRC_SHIFT                   (24U)                                               /**< SIM_SOPT2.TPMSRC Position               */
#define SIM_SOPT2_TPMSRC(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_TPMSRC_SHIFT))&SIM_SOPT2_TPMSRC_MASK) /**< SIM_SOPT2.TPMSRC Field                  */
#define SIM_SOPT2_LPUART0SRC_MASK                (0xC000000U)                                        /**< SIM_SOPT2.LPUART0SRC Mask               */
#define SIM_SOPT2_LPUART0SRC_SHIFT               (26U)                                               /**< SIM_SOPT2.LPUART0SRC Position           */
#define SIM_SOPT2_LPUART0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_LPUART0SRC_SHIFT))&SIM_SOPT2_LPUART0SRC_MASK) /**< SIM_SOPT2.LPUART0SRC Field              */
#define SIM_SOPT2_LPUART1SRC_MASK                (0x30000000U)                                       /**< SIM_SOPT2.LPUART1SRC Mask               */
#define SIM_SOPT2_LPUART1SRC_SHIFT               (28U)                                               /**< SIM_SOPT2.LPUART1SRC Position           */
#define SIM_SOPT2_LPUART1SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_LPUART1SRC_SHIFT))&SIM_SOPT2_LPUART1SRC_MASK) /**< SIM_SOPT2.LPUART1SRC Field              */
/** @} */

/** @name SOPT4 - System Options Register 4 */ /** @{ */
#define SIM_SOPT4_TPM1CH0SRC_MASK                (0xC0000U)                                          /**< SIM_SOPT4.TPM1CH0SRC Mask               */
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
#define SIM_SOPT5_LPUART0TXSRC_MASK              (0x3U)                                              /**< SIM_SOPT5.LPUART0TXSRC Mask             */
#define SIM_SOPT5_LPUART0TXSRC_SHIFT             (0U)                                                /**< SIM_SOPT5.LPUART0TXSRC Position         */
#define SIM_SOPT5_LPUART0TXSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART0TXSRC_SHIFT))&SIM_SOPT5_LPUART0TXSRC_MASK) /**< SIM_SOPT5.LPUART0TXSRC Field            */
#define SIM_SOPT5_LPUART0RXSRC_MASK              (0x4U)                                              /**< SIM_SOPT5.LPUART0RXSRC Mask             */
#define SIM_SOPT5_LPUART0RXSRC_SHIFT             (2U)                                                /**< SIM_SOPT5.LPUART0RXSRC Position         */
#define SIM_SOPT5_LPUART0RXSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART0RXSRC_SHIFT))&SIM_SOPT5_LPUART0RXSRC_MASK) /**< SIM_SOPT5.LPUART0RXSRC Field            */
#define SIM_SOPT5_LPUART1TXSRC_MASK              (0x30U)                                             /**< SIM_SOPT5.LPUART1TXSRC Mask             */
#define SIM_SOPT5_LPUART1TXSRC_SHIFT             (4U)                                                /**< SIM_SOPT5.LPUART1TXSRC Position         */
#define SIM_SOPT5_LPUART1TXSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART1TXSRC_SHIFT))&SIM_SOPT5_LPUART1TXSRC_MASK) /**< SIM_SOPT5.LPUART1TXSRC Field            */
#define SIM_SOPT5_LPUART1RXSRC_MASK              (0x40U)                                             /**< SIM_SOPT5.LPUART1RXSRC Mask             */
#define SIM_SOPT5_LPUART1RXSRC_SHIFT             (6U)                                                /**< SIM_SOPT5.LPUART1RXSRC Position         */
#define SIM_SOPT5_LPUART1RXSRC(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART1RXSRC_SHIFT))&SIM_SOPT5_LPUART1RXSRC_MASK) /**< SIM_SOPT5.LPUART1RXSRC Field            */
#define SIM_SOPT5_LPUART0ODE_MASK                (0x10000U)                                          /**< SIM_SOPT5.LPUART0ODE Mask               */
#define SIM_SOPT5_LPUART0ODE_SHIFT               (16U)                                               /**< SIM_SOPT5.LPUART0ODE Position           */
#define SIM_SOPT5_LPUART0ODE(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART0ODE_SHIFT))&SIM_SOPT5_LPUART0ODE_MASK) /**< SIM_SOPT5.LPUART0ODE Field              */
#define SIM_SOPT5_LPUART1ODE_MASK                (0x20000U)                                          /**< SIM_SOPT5.LPUART1ODE Mask               */
#define SIM_SOPT5_LPUART1ODE_SHIFT               (17U)                                               /**< SIM_SOPT5.LPUART1ODE Position           */
#define SIM_SOPT5_LPUART1ODE(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_LPUART1ODE_SHIFT))&SIM_SOPT5_LPUART1ODE_MASK) /**< SIM_SOPT5.LPUART1ODE Field              */
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
#define SIM_SCGC4_UART2_MASK                     (0x1000U)                                           /**< SIM_SCGC4.UART2 Mask                    */
#define SIM_SCGC4_UART2_SHIFT                    (12U)                                               /**< SIM_SCGC4.UART2 Position                */
#define SIM_SCGC4_UART2(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART2_SHIFT))&SIM_SCGC4_UART2_MASK) /**< SIM_SCGC4.UART2 Field                   */
#define SIM_SCGC4_USB0_MASK                      (0x40000U)                                          /**< SIM_SCGC4.USB0 Mask                     */
#define SIM_SCGC4_USB0_SHIFT                     (18U)                                               /**< SIM_SCGC4.USB0 Position                 */
#define SIM_SCGC4_USB0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_USB0_SHIFT))&SIM_SCGC4_USB0_MASK) /**< SIM_SCGC4.USB0 Field                    */
#define SIM_SCGC4_CMP0_MASK                      (0x80000U)                                          /**< SIM_SCGC4.CMP0 Mask                     */
#define SIM_SCGC4_CMP0_SHIFT                     (19U)                                               /**< SIM_SCGC4.CMP0 Position                 */
#define SIM_SCGC4_CMP0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_CMP0_SHIFT))&SIM_SCGC4_CMP0_MASK) /**< SIM_SCGC4.CMP0 Field                    */
#define SIM_SCGC4_VREF_MASK                      (0x100000U)                                         /**< SIM_SCGC4.VREF Mask                     */
#define SIM_SCGC4_VREF_SHIFT                     (20U)                                               /**< SIM_SCGC4.VREF Position                 */
#define SIM_SCGC4_VREF(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_VREF_SHIFT))&SIM_SCGC4_VREF_MASK) /**< SIM_SCGC4.VREF Field                    */
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
#define SIM_SCGC5_LPUART0_MASK                   (0x100000U)                                         /**< SIM_SCGC5.LPUART0 Mask                  */
#define SIM_SCGC5_LPUART0_SHIFT                  (20U)                                               /**< SIM_SCGC5.LPUART0 Position              */
#define SIM_SCGC5_LPUART0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_LPUART0_SHIFT))&SIM_SCGC5_LPUART0_MASK) /**< SIM_SCGC5.LPUART0 Field                 */
#define SIM_SCGC5_LPUART1_MASK                   (0x200000U)                                         /**< SIM_SCGC5.LPUART1 Mask                  */
#define SIM_SCGC5_LPUART1_SHIFT                  (21U)                                               /**< SIM_SCGC5.LPUART1 Position              */
#define SIM_SCGC5_LPUART1(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_LPUART1_SHIFT))&SIM_SCGC5_LPUART1_MASK) /**< SIM_SCGC5.LPUART1 Field                 */
#define SIM_SCGC5_FLEXIO_MASK                    (0x80000000U)                                       /**< SIM_SCGC5.FLEXIO Mask                   */
#define SIM_SCGC5_FLEXIO_SHIFT                   (31U)                                               /**< SIM_SCGC5.FLEXIO Position               */
#define SIM_SCGC5_FLEXIO(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_FLEXIO_SHIFT))&SIM_SCGC5_FLEXIO_MASK) /**< SIM_SCGC5.FLEXIO Field                  */
/** @} */

/** @name SCGC6 - System Clock Gating Control Register 6 */ /** @{ */
#define SIM_SCGC6_FTF_MASK                       (0x1U)                                              /**< SIM_SCGC6.FTF Mask                      */
#define SIM_SCGC6_FTF_SHIFT                      (0U)                                                /**< SIM_SCGC6.FTF Position                  */
#define SIM_SCGC6_FTF(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTF_SHIFT))&SIM_SCGC6_FTF_MASK) /**< SIM_SCGC6.FTF Field                     */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x2U)                                              /**< SIM_SCGC6.DMAMUX0 Mask                  */
#define SIM_SCGC6_DMAMUX0_SHIFT                  (1U)                                                /**< SIM_SCGC6.DMAMUX0 Position              */
#define SIM_SCGC6_DMAMUX0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DMAMUX0_SHIFT))&SIM_SCGC6_DMAMUX0_MASK) /**< SIM_SCGC6.DMAMUX0 Field                 */
#define SIM_SCGC6_CRC0_MASK                      (0x40000U)                                          /**< SIM_SCGC6.CRC0 Mask                     */
#define SIM_SCGC6_CRC0_SHIFT                     (18U)                                               /**< SIM_SCGC6.CRC0 Position                 */
#define SIM_SCGC6_CRC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_CRC0_SHIFT))&SIM_SCGC6_CRC0_MASK) /**< SIM_SCGC6.CRC0 Field                    */
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
#define SIM_FCFG2_MAXADDR1_MASK                  (0x7F0000U)                                         /**< SIM_FCFG2.MAXADDR1 Mask                 */
#define SIM_FCFG2_MAXADDR1_SHIFT                 (16U)                                               /**< SIM_FCFG2.MAXADDR1 Position             */
#define SIM_FCFG2_MAXADDR1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR1_SHIFT))&SIM_FCFG2_MAXADDR1_MASK) /**< SIM_FCFG2.MAXADDR1 Field                */
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
#define SIM_COPC_COPSTPEN_MASK                   (0x10U)                                             /**< SIM_COPC.COPSTPEN Mask                  */
#define SIM_COPC_COPSTPEN_SHIFT                  (4U)                                                /**< SIM_COPC.COPSTPEN Position              */
#define SIM_COPC_COPSTPEN(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPSTPEN_SHIFT))&SIM_COPC_COPSTPEN_MASK) /**< SIM_COPC.COPSTPEN Field                 */
#define SIM_COPC_COPDBGEN_MASK                   (0x20U)                                             /**< SIM_COPC.COPDBGEN Mask                  */
#define SIM_COPC_COPDBGEN_SHIFT                  (5U)                                                /**< SIM_COPC.COPDBGEN Position              */
#define SIM_COPC_COPDBGEN(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPDBGEN_SHIFT))&SIM_COPC_COPDBGEN_MASK) /**< SIM_COPC.COPDBGEN Field                 */
#define SIM_COPC_COPCLKSEL_MASK                  (0xC0U)                                             /**< SIM_COPC.COPCLKSEL Mask                 */
#define SIM_COPC_COPCLKSEL_SHIFT                 (6U)                                                /**< SIM_COPC.COPCLKSEL Position             */
#define SIM_COPC_COPCLKSEL(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_COPC_COPCLKSEL_SHIFT))&SIM_COPC_COPCLKSEL_MASK) /**< SIM_COPC.COPCLKSEL Field                */
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
/* ================           SMC (file:SMC_LPOPO_PSTOPO_MKL27Z644)       ================ */
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
#define SMC_STOPCTRL_LPOPO_MASK                  (0x8U)                                              /**< SMC_STOPCTRL.LPOPO Mask                 */
#define SMC_STOPCTRL_LPOPO_SHIFT                 (3U)                                                /**< SMC_STOPCTRL.LPOPO Position             */
#define SMC_STOPCTRL_LPOPO(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_STOPCTRL_LPOPO_SHIFT))&SMC_STOPCTRL_LPOPO_MASK) /**< SMC_STOPCTRL.LPOPO Field                */
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
#define SMC_VLLSCTRL_LPOPO_MASK                  (0x8U)                                              /**< SMC_VLLSCTRL.LPOPO Mask                 */
#define SMC_VLLSCTRL_LPOPO_SHIFT                 (3U)                                                /**< SMC_VLLSCTRL.LPOPO Position             */
#define SMC_VLLSCTRL_LPOPO(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_LPOPO_SHIFT))&SMC_VLLSCTRL_LPOPO_MASK) /**< SMC_VLLSCTRL.LPOPO Field                */
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
/* ================           SPI0 (file:SPI0_16Bit_MKL)           ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
/**
 * @struct SPI_Type
 * @brief  C Struct allowing access to SPI registers
 */
typedef struct SPI_Type {
   __I  uint8_t   S;                            /**< 0000: Status register                                              */
   __IO uint8_t   BR;                           /**< 0001: Baud rate register                                           */
   __IO uint8_t   C2;                           /**< 0002: Control register 2                                           */
   __IO uint8_t   C1;                           /**< 0003: Control register 1                                           */
   union {                                      /**< 0004: (size=0002)                                                  */
      __IO uint16_t  M16;                       /**< 0004: 16-bit Match register                                        */
      __IO uint8_t   M;                         /**< 0004: 8-bit Match register                                         */
   };
   union {                                      /**< 0006: (size=0002)                                                  */
      __IO uint16_t  D16;                       /**< 0006: 16-bit Data register                                         */
      __IO uint8_t   D;                         /**< 0006: 8-bit Data register                                          */
   };
        uint8_t   RESERVED_0[2];                /**< 0008: 0x2 bytes                                                    */
   __IO uint8_t   CI;                           /**< 000A: Clear interrupt register                                     */
   __IO uint8_t   C3;                           /**< 000B: Control register 3                                           */
} SPI_Type;


/** @brief Register Masks for SPI */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SPI_Register_Masks_GROUP SPI Register Masks */
/** @{ */

/** @name S - Status register */ /** @{ */
#define SPI_S_RFIFOEF_MASK                       (0x1U)                                              /**< SPI0_S.RFIFOEF Mask                     */
#define SPI_S_RFIFOEF_SHIFT                      (0U)                                                /**< SPI0_S.RFIFOEF Position                 */
#define SPI_S_RFIFOEF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_RFIFOEF_SHIFT))&SPI_S_RFIFOEF_MASK) /**< SPI0_S.RFIFOEF Field                    */
#define SPI_S_TXFULLF_MASK                       (0x2U)                                              /**< SPI0_S.TXFULLF Mask                     */
#define SPI_S_TXFULLF_SHIFT                      (1U)                                                /**< SPI0_S.TXFULLF Position                 */
#define SPI_S_TXFULLF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_TXFULLF_SHIFT))&SPI_S_TXFULLF_MASK) /**< SPI0_S.TXFULLF Field                    */
#define SPI_S_TNEAREF_MASK                       (0x4U)                                              /**< SPI0_S.TNEAREF Mask                     */
#define SPI_S_TNEAREF_SHIFT                      (2U)                                                /**< SPI0_S.TNEAREF Position                 */
#define SPI_S_TNEAREF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_TNEAREF_SHIFT))&SPI_S_TNEAREF_MASK) /**< SPI0_S.TNEAREF Field                    */
#define SPI_S_RNFULLF_MASK                       (0x8U)                                              /**< SPI0_S.RNFULLF Mask                     */
#define SPI_S_RNFULLF_SHIFT                      (3U)                                                /**< SPI0_S.RNFULLF Position                 */
#define SPI_S_RNFULLF(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_S_RNFULLF_SHIFT))&SPI_S_RNFULLF_MASK) /**< SPI0_S.RNFULLF Field                    */
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

/** @name BR - Baud rate register */ /** @{ */
#define SPI_BR_SPR_MASK                          (0xFU)                                              /**< SPI0_BR.SPR Mask                        */
#define SPI_BR_SPR_SHIFT                         (0U)                                                /**< SPI0_BR.SPR Position                    */
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK) /**< SPI0_BR.SPR Field                       */
#define SPI_BR_SPPR_MASK                         (0x70U)                                             /**< SPI0_BR.SPPR Mask                       */
#define SPI_BR_SPPR_SHIFT                        (4U)                                                /**< SPI0_BR.SPPR Position                   */
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK) /**< SPI0_BR.SPPR Field                      */
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
#define SPI_C2_SPIMODE_MASK                      (0x40U)                                             /**< SPI0_C2.SPIMODE Mask                    */
#define SPI_C2_SPIMODE_SHIFT                     (6U)                                                /**< SPI0_C2.SPIMODE Position                */
#define SPI_C2_SPIMODE(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPIMODE_SHIFT))&SPI_C2_SPIMODE_MASK) /**< SPI0_C2.SPIMODE Field                   */
#define SPI_C2_SPMIE_MASK                        (0x80U)                                             /**< SPI0_C2.SPMIE Mask                      */
#define SPI_C2_SPMIE_SHIFT                       (7U)                                                /**< SPI0_C2.SPMIE Position                  */
#define SPI_C2_SPMIE(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_C2_SPMIE_SHIFT))&SPI_C2_SPMIE_MASK) /**< SPI0_C2.SPMIE Field                     */
/** @} */

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

/** @name M16 - 16-bit Match register */ /** @{ */
#define SPI_M16_Bits_MASK                        (0xFFFFU)                                           /**< SPI0_M16.Bits Mask                      */
#define SPI_M16_Bits_SHIFT                       (0U)                                                /**< SPI0_M16.Bits Position                  */
#define SPI_M16_Bits(x)                          (((uint16_t)(((uint16_t)(x))<<SPI_M16_Bits_SHIFT))&SPI_M16_Bits_MASK) /**< SPI0_M16.Bits Field                     */
/** @} */

/** @name M - 8-bit Match register */ /** @{ */
#define SPI_M_Bits_MASK                          (0xFFU)                                             /**< SPI0_M.Bits Mask                        */
#define SPI_M_Bits_SHIFT                         (0U)                                                /**< SPI0_M.Bits Position                    */
#define SPI_M_Bits(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_M_Bits_SHIFT))&SPI_M_Bits_MASK) /**< SPI0_M.Bits Field                       */
/** @} */

/** @name D16 - 16-bit Data register */ /** @{ */
#define SPI_D16_Bits_MASK                        (0xFFFFU)                                           /**< SPI0_D16.Bits Mask                      */
#define SPI_D16_Bits_SHIFT                       (0U)                                                /**< SPI0_D16.Bits Position                  */
#define SPI_D16_Bits(x)                          (((uint16_t)(((uint16_t)(x))<<SPI_D16_Bits_SHIFT))&SPI_D16_Bits_MASK) /**< SPI0_D16.Bits Field                     */
/** @} */

/** @name D - 8-bit Data register */ /** @{ */
#define SPI_D_Bits_MASK                          (0xFFU)                                             /**< SPI0_D.Bits Mask                        */
#define SPI_D_Bits_SHIFT                         (0U)                                                /**< SPI0_D.Bits Position                    */
#define SPI_D_Bits(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_D_Bits_SHIFT))&SPI_D_Bits_MASK) /**< SPI0_D.Bits Field                       */
/** @} */

/** @name CI - Clear interrupt register */ /** @{ */
#define SPI_CI_SPRFCI_MASK                       (0x1U)                                              /**< SPI0_CI.SPRFCI Mask                     */
#define SPI_CI_SPRFCI_SHIFT                      (0U)                                                /**< SPI0_CI.SPRFCI Position                 */
#define SPI_CI_SPRFCI(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_SPRFCI_SHIFT))&SPI_CI_SPRFCI_MASK) /**< SPI0_CI.SPRFCI Field                    */
#define SPI_CI_SPTEFCI_MASK                      (0x2U)                                              /**< SPI0_CI.SPTEFCI Mask                    */
#define SPI_CI_SPTEFCI_SHIFT                     (1U)                                                /**< SPI0_CI.SPTEFCI Position                */
#define SPI_CI_SPTEFCI(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_CI_SPTEFCI_SHIFT))&SPI_CI_SPTEFCI_MASK) /**< SPI0_CI.SPTEFCI Field                   */
#define SPI_CI_RNFULLFCI_MASK                    (0x4U)                                              /**< SPI0_CI.RNFULLFCI Mask                  */
#define SPI_CI_RNFULLFCI_SHIFT                   (2U)                                                /**< SPI0_CI.RNFULLFCI Position              */
#define SPI_CI_RNFULLFCI(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_CI_RNFULLFCI_SHIFT))&SPI_CI_RNFULLFCI_MASK) /**< SPI0_CI.RNFULLFCI Field                 */
#define SPI_CI_TNEAREFCI_MASK                    (0x8U)                                              /**< SPI0_CI.TNEAREFCI Mask                  */
#define SPI_CI_TNEAREFCI_SHIFT                   (3U)                                                /**< SPI0_CI.TNEAREFCI Position              */
#define SPI_CI_TNEAREFCI(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_CI_TNEAREFCI_SHIFT))&SPI_CI_TNEAREFCI_MASK) /**< SPI0_CI.TNEAREFCI Field                 */
#define SPI_CI_RXFOF_MASK                        (0x10U)                                             /**< SPI0_CI.RXFOF Mask                      */
#define SPI_CI_RXFOF_SHIFT                       (4U)                                                /**< SPI0_CI.RXFOF Position                  */
#define SPI_CI_RXFOF(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_CI_RXFOF_SHIFT))&SPI_CI_RXFOF_MASK) /**< SPI0_CI.RXFOF Field                     */
#define SPI_CI_TXFOF_MASK                        (0x20U)                                             /**< SPI0_CI.TXFOF Mask                      */
#define SPI_CI_TXFOF_SHIFT                       (5U)                                                /**< SPI0_CI.TXFOF Position                  */
#define SPI_CI_TXFOF(x)                          (((uint8_t)(((uint8_t)(x))<<SPI_CI_TXFOF_SHIFT))&SPI_CI_TXFOF_MASK) /**< SPI0_CI.TXFOF Field                     */
#define SPI_CI_RXFERR_MASK                       (0x40U)                                             /**< SPI0_CI.RXFERR Mask                     */
#define SPI_CI_RXFERR_SHIFT                      (6U)                                                /**< SPI0_CI.RXFERR Position                 */
#define SPI_CI_RXFERR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_RXFERR_SHIFT))&SPI_CI_RXFERR_MASK) /**< SPI0_CI.RXFERR Field                    */
#define SPI_CI_TXFERR_MASK                       (0x80U)                                             /**< SPI0_CI.TXFERR Mask                     */
#define SPI_CI_TXFERR_SHIFT                      (7U)                                                /**< SPI0_CI.TXFERR Position                 */
#define SPI_CI_TXFERR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_CI_TXFERR_SHIFT))&SPI_CI_TXFERR_MASK) /**< SPI0_CI.TXFERR Field                    */
/** @} */

/** @name C3 - Control register 3 */ /** @{ */
#define SPI_C3_FIFOMODE_MASK                     (0x1U)                                              /**< SPI0_C3.FIFOMODE Mask                   */
#define SPI_C3_FIFOMODE_SHIFT                    (0U)                                                /**< SPI0_C3.FIFOMODE Position               */
#define SPI_C3_FIFOMODE(x)                       (((uint8_t)(((uint8_t)(x))<<SPI_C3_FIFOMODE_SHIFT))&SPI_C3_FIFOMODE_MASK) /**< SPI0_C3.FIFOMODE Field                  */
#define SPI_C3_RNFULLIEN_MASK                    (0x2U)                                              /**< SPI0_C3.RNFULLIEN Mask                  */
#define SPI_C3_RNFULLIEN_SHIFT                   (1U)                                                /**< SPI0_C3.RNFULLIEN Position              */
#define SPI_C3_RNFULLIEN(x)                      (((uint8_t)(((uint8_t)(x))<<SPI_C3_RNFULLIEN_SHIFT))&SPI_C3_RNFULLIEN_MASK) /**< SPI0_C3.RNFULLIEN Field                 */
#define SPI_C3_TNEARIEN_MASK                     (0x4U)                                              /**< SPI0_C3.TNEARIEN Mask                   */
#define SPI_C3_TNEARIEN_SHIFT                    (2U)                                                /**< SPI0_C3.TNEARIEN Position               */
#define SPI_C3_TNEARIEN(x)                       (((uint8_t)(((uint8_t)(x))<<SPI_C3_TNEARIEN_SHIFT))&SPI_C3_TNEARIEN_MASK) /**< SPI0_C3.TNEARIEN Field                  */
#define SPI_C3_INTCLR_MASK                       (0x8U)                                              /**< SPI0_C3.INTCLR Mask                     */
#define SPI_C3_INTCLR_SHIFT                      (3U)                                                /**< SPI0_C3.INTCLR Position                 */
#define SPI_C3_INTCLR(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C3_INTCLR_SHIFT))&SPI_C3_INTCLR_MASK) /**< SPI0_C3.INTCLR Field                    */
#define SPI_C3_RNFULLF_MARK_MASK                 (0x10U)                                             /**< SPI0_C3.RNFULLF_MARK Mask               */
#define SPI_C3_RNFULLF_MARK_SHIFT                (4U)                                                /**< SPI0_C3.RNFULLF_MARK Position           */
#define SPI_C3_RNFULLF_MARK(x)                   (((uint8_t)(((uint8_t)(x))<<SPI_C3_RNFULLF_MARK_SHIFT))&SPI_C3_RNFULLF_MARK_MASK) /**< SPI0_C3.RNFULLF_MARK Field              */
#define SPI_C3_TNEAREF_MARK_MASK                 (0x20U)                                             /**< SPI0_C3.TNEAREF_MARK Mask               */
#define SPI_C3_TNEAREF_MARK_SHIFT                (5U)                                                /**< SPI0_C3.TNEAREF_MARK Position           */
#define SPI_C3_TNEAREF_MARK(x)                   (((uint8_t)(((uint8_t)(x))<<SPI_C3_TNEAREF_MARK_SHIFT))&SPI_C3_TNEAREF_MARK_MASK) /**< SPI0_C3.TNEAREF_MARK Field              */
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
#define SPI1_HAS_FIFO (1)
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
/* ================           TPM0 (file:TPM0_6CH_POL)             ================ */
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
        uint8_t   RESERVED_2[28];               /**< 0054: 0x1C bytes                                                   */
   __IO uint32_t  POL;                          /**< 0070: Channel Polarity                                             */
        uint8_t   RESERVED_3[16];               /**< 0074: 0x10 bytes                                                   */
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
#define TPM_STATUS_STATUS_MASK                   (0xFFFFU)                                           /**< TPM0_STATUS.STATUS Mask                 */
#define TPM_STATUS_STATUS_SHIFT                  (0U)                                                /**< TPM0_STATUS.STATUS Position             */
#define TPM_STATUS_STATUS(x)                     (((uint32_t)(((uint32_t)(x))<<TPM_STATUS_STATUS_SHIFT))&TPM_STATUS_STATUS_MASK) /**< TPM0_STATUS.STATUS Field                */
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

/** @name POL - Channel Polarity */ /** @{ */
#define TPM_POL_POL_MASK                         (0xFFU)                                             /**< TPM0_POL.POL Mask                       */
#define TPM_POL_POL_SHIFT                        (0U)                                                /**< TPM0_POL.POL Position                   */
#define TPM_POL_POL(x)                           (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL_SHIFT))&TPM_POL_POL_MASK) /**< TPM0_POL.POL Field                      */
#define TPM_POL_POL0_MASK                        (0x1U)                                              /**< TPM0_POL.POL0 Mask                      */
#define TPM_POL_POL0_SHIFT                       (0U)                                                /**< TPM0_POL.POL0 Position                  */
#define TPM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL0_SHIFT))&TPM_POL_POL0_MASK) /**< TPM0_POL.POL0 Field                     */
#define TPM_POL_POL1_MASK                        (0x2U)                                              /**< TPM0_POL.POL1 Mask                      */
#define TPM_POL_POL1_SHIFT                       (1U)                                                /**< TPM0_POL.POL1 Position                  */
#define TPM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL1_SHIFT))&TPM_POL_POL1_MASK) /**< TPM0_POL.POL1 Field                     */
#define TPM_POL_POL2_MASK                        (0x4U)                                              /**< TPM0_POL.POL2 Mask                      */
#define TPM_POL_POL2_SHIFT                       (2U)                                                /**< TPM0_POL.POL2 Position                  */
#define TPM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL2_SHIFT))&TPM_POL_POL2_MASK) /**< TPM0_POL.POL2 Field                     */
#define TPM_POL_POL3_MASK                        (0x8U)                                              /**< TPM0_POL.POL3 Mask                      */
#define TPM_POL_POL3_SHIFT                       (3U)                                                /**< TPM0_POL.POL3 Position                  */
#define TPM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL3_SHIFT))&TPM_POL_POL3_MASK) /**< TPM0_POL.POL3 Field                     */
#define TPM_POL_POL4_MASK                        (0x10U)                                             /**< TPM0_POL.POL4 Mask                      */
#define TPM_POL_POL4_SHIFT                       (4U)                                                /**< TPM0_POL.POL4 Position                  */
#define TPM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL4_SHIFT))&TPM_POL_POL4_MASK) /**< TPM0_POL.POL4 Field                     */
#define TPM_POL_POL5_MASK                        (0x20U)                                             /**< TPM0_POL.POL5 Mask                      */
#define TPM_POL_POL5_SHIFT                       (5U)                                                /**< TPM0_POL.POL5 Position                  */
#define TPM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<TPM_POL_POL5_SHIFT))&TPM_POL_POL5_MASK) /**< TPM0_POL.POL5 Field                     */
/** @} */

/** @name CONF - Configuration */ /** @{ */
#define TPM_CONF_DOZEEN_MASK                     (0x20U)                                             /**< TPM0_CONF.DOZEEN Mask                   */
#define TPM_CONF_DOZEEN_SHIFT                    (5U)                                                /**< TPM0_CONF.DOZEEN Position               */
#define TPM_CONF_DOZEEN(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_DOZEEN_SHIFT))&TPM_CONF_DOZEEN_MASK) /**< TPM0_CONF.DOZEEN Field                  */
#define TPM_CONF_DBGMODE_MASK                    (0xC0U)                                             /**< TPM0_CONF.DBGMODE Mask                  */
#define TPM_CONF_DBGMODE_SHIFT                   (6U)                                                /**< TPM0_CONF.DBGMODE Position              */
#define TPM_CONF_DBGMODE(x)                      (((uint32_t)(((uint32_t)(x))<<TPM_CONF_DBGMODE_SHIFT))&TPM_CONF_DBGMODE_MASK) /**< TPM0_CONF.DBGMODE Field                 */
#define TPM_CONF_GTBSYNC_MASK                    (0x100U)                                            /**< TPM0_CONF.GTBSYNC Mask                  */
#define TPM_CONF_GTBSYNC_SHIFT                   (8U)                                                /**< TPM0_CONF.GTBSYNC Position              */
#define TPM_CONF_GTBSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<TPM_CONF_GTBSYNC_SHIFT))&TPM_CONF_GTBSYNC_MASK) /**< TPM0_CONF.GTBSYNC Field                 */
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
#define TPM_CONF_CPOT_MASK                       (0x80000U)                                          /**< TPM0_CONF.CPOT Mask                     */
#define TPM_CONF_CPOT_SHIFT                      (19U)                                               /**< TPM0_CONF.CPOT Position                 */
#define TPM_CONF_CPOT(x)                         (((uint32_t)(((uint32_t)(x))<<TPM_CONF_CPOT_SHIFT))&TPM_CONF_CPOT_MASK) /**< TPM0_CONF.CPOT Field                    */
#define TPM_CONF_TRGPOL_MASK                     (0x400000U)                                         /**< TPM0_CONF.TRGPOL Mask                   */
#define TPM_CONF_TRGPOL_SHIFT                    (22U)                                               /**< TPM0_CONF.TRGPOL Position               */
#define TPM_CONF_TRGPOL(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGPOL_SHIFT))&TPM_CONF_TRGPOL_MASK) /**< TPM0_CONF.TRGPOL Field                  */
#define TPM_CONF_TRGSRC_MASK                     (0x800000U)                                         /**< TPM0_CONF.TRGSRC Mask                   */
#define TPM_CONF_TRGSRC_SHIFT                    (23U)                                               /**< TPM0_CONF.TRGSRC Position               */
#define TPM_CONF_TRGSRC(x)                       (((uint32_t)(((uint32_t)(x))<<TPM_CONF_TRGSRC_SHIFT))&TPM_CONF_TRGSRC_MASK) /**< TPM0_CONF.TRGSRC Field                  */
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
/* ================           TPM1 (file:TPM1_2CH_POL)             ================ */
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
        uint8_t   RESERVED_2[28];               /**< 0054: 0x1C bytes                                                   */
   __IO uint32_t  POL;                          /**< 0070: Channel Polarity                                             */
        uint8_t   RESERVED_3[16];               /**< 0074: 0x10 bytes                                                   */
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


/** @brief C Struct for UART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           UART2 (file:UART2_MKL17Z4_C7816)       ================ */
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
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Register 1                                     */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Register 2                                     */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
        uint8_t   RESERVED_0[12];               /**< 000C: 0xC bytes                                                    */
   __IO uint8_t   C7816;                        /**< 0018: 7816 Control Register                                        */
   __IO uint8_t   IE7816;                       /**< 0019: 7816 Interrupt Enable Register                               */
   __IO uint8_t   IS7816;                       /**< 001A: 7816 Interrupt Status Register                               */
   __IO uint8_t   WP7816;                       /**< 001B: 7816 Wait Parameter Register                                 */
   __IO uint8_t   WN7816;                       /**< 001C: 7816 Wait N Register                                         */
   __IO uint8_t   WF7816;                       /**< 001D: 7816 Wait FD Register                                        */
   __IO uint8_t   ET7816;                       /**< 001E: 7816 Error Threshold Register                                */
   __IO uint8_t   TL7816;                       /**< 001F: 7816 Transmit Length Register                                */
        uint8_t   RESERVED_1[26];               /**< 0020: 0x1A bytes                                                   */
   __IO uint8_t   AP7816A_T0;                   /**< 003A: 7816 ATR Duration Timer Register A                           */
   __IO uint8_t   AP7816B_T0;                   /**< 003B: 7816 ATR Duration Timer Register B                           */
   union {                                      /**< 003C: (size=0001)                                                  */
      __IO uint8_t   WP7816A_T0;                /**< 003C: 7816 Wait Parameter Register A                               */
      __IO uint8_t   WP7816A_T1;                /**< 003C: 7816 Wait Parameter Register A                               */
   };
   union {                                      /**< 003D: (size=0001)                                                  */
      __IO uint8_t   WP7816B_T0;                /**< 003D: 7816 Wait Parameter Register B                               */
      __IO uint8_t   WP7816B_T1;                /**< 003D: 7816 Wait Parameter Register B                               */
   };
   __IO uint8_t   WGP7816_T1;                   /**< 003E: 7816 Wait and Guard Parameter Register                       */
   __IO uint8_t   WP7816C_T1;                   /**< 003F: 7816 Wait Parameter Register C                               */
} UART_Type;


/** @brief Register Masks for UART */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART2' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup UART_Register_Masks_GROUP UART Register Masks */
/** @{ */

/** @name BDH - Baud Rate Register: High */ /** @{ */
#define UART_BDH_SBR_MASK                        (0x1FU)                                             /**< UART2_BDH.SBR Mask                      */
#define UART_BDH_SBR_SHIFT                       (0U)                                                /**< UART2_BDH.SBR Position                  */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK) /**< UART2_BDH.SBR Field                     */
#define UART_BDH_RXEDGIE_MASK                    (0x40U)                                             /**< UART2_BDH.RXEDGIE Mask                  */
#define UART_BDH_RXEDGIE_SHIFT                   (6U)                                                /**< UART2_BDH.RXEDGIE Position              */
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_BDH_RXEDGIE_SHIFT))&UART_BDH_RXEDGIE_MASK) /**< UART2_BDH.RXEDGIE Field                 */
/** @} */

/** @name BDL - Baud Rate Register: Low */ /** @{ */
#define UART_BDL_SBR_MASK                        (0xFFU)                                             /**< UART2_BDL.SBR Mask                      */
#define UART_BDL_SBR_SHIFT                       (0U)                                                /**< UART2_BDL.SBR Position                  */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK) /**< UART2_BDL.SBR Field                     */
/** @} */

/** @name C1 - Control Register 1 */ /** @{ */
#define UART_C1_PT_MASK                          (0x1U)                                              /**< UART2_C1.PT Mask                        */
#define UART_C1_PT_SHIFT                         (0U)                                                /**< UART2_C1.PT Position                    */
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PT_SHIFT))&UART_C1_PT_MASK) /**< UART2_C1.PT Field                       */
#define UART_C1_PE_MASK                          (0x2U)                                              /**< UART2_C1.PE Mask                        */
#define UART_C1_PE_SHIFT                         (1U)                                                /**< UART2_C1.PE Position                    */
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PE_SHIFT))&UART_C1_PE_MASK) /**< UART2_C1.PE Field                       */
#define UART_C1_ILT_MASK                         (0x4U)                                              /**< UART2_C1.ILT Mask                       */
#define UART_C1_ILT_SHIFT                        (2U)                                                /**< UART2_C1.ILT Position                   */
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C1_ILT_SHIFT))&UART_C1_ILT_MASK) /**< UART2_C1.ILT Field                      */
#define UART_C1_WAKE_MASK                        (0x8U)                                              /**< UART2_C1.WAKE Mask                      */
#define UART_C1_WAKE_SHIFT                       (3U)                                                /**< UART2_C1.WAKE Position                  */
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_WAKE_SHIFT))&UART_C1_WAKE_MASK) /**< UART2_C1.WAKE Field                     */
#define UART_C1_M_MASK                           (0x10U)                                             /**< UART2_C1.M Mask                         */
#define UART_C1_M_SHIFT                          (4U)                                                /**< UART2_C1.M Position                     */
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x))<<UART_C1_M_SHIFT))&UART_C1_M_MASK) /**< UART2_C1.M Field                        */
#define UART_C1_RSRC_MASK                        (0x20U)                                             /**< UART2_C1.RSRC Mask                      */
#define UART_C1_RSRC_SHIFT                       (5U)                                                /**< UART2_C1.RSRC Position                  */
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_RSRC_SHIFT))&UART_C1_RSRC_MASK) /**< UART2_C1.RSRC Field                     */
#define UART_C1_LOOPS_MASK                       (0x80U)                                             /**< UART2_C1.LOOPS Mask                     */
#define UART_C1_LOOPS_SHIFT                      (7U)                                                /**< UART2_C1.LOOPS Position                 */
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C1_LOOPS_SHIFT))&UART_C1_LOOPS_MASK) /**< UART2_C1.LOOPS Field                    */
/** @} */

/** @name C2 - Control Register 2 */ /** @{ */
#define UART_C2_SBK_MASK                         (0x1U)                                              /**< UART2_C2.SBK Mask                       */
#define UART_C2_SBK_SHIFT                        (0U)                                                /**< UART2_C2.SBK Position                   */
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_SBK_SHIFT))&UART_C2_SBK_MASK) /**< UART2_C2.SBK Field                      */
#define UART_C2_RWU_MASK                         (0x2U)                                              /**< UART2_C2.RWU Mask                       */
#define UART_C2_RWU_SHIFT                        (1U)                                                /**< UART2_C2.RWU Position                   */
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RWU_SHIFT))&UART_C2_RWU_MASK) /**< UART2_C2.RWU Field                      */
#define UART_C2_RE_MASK                          (0x4U)                                              /**< UART2_C2.RE Mask                        */
#define UART_C2_RE_SHIFT                         (2U)                                                /**< UART2_C2.RE Position                    */
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_RE_SHIFT))&UART_C2_RE_MASK) /**< UART2_C2.RE Field                       */
#define UART_C2_TE_MASK                          (0x8U)                                              /**< UART2_C2.TE Mask                        */
#define UART_C2_TE_SHIFT                         (3U)                                                /**< UART2_C2.TE Position                    */
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_TE_SHIFT))&UART_C2_TE_MASK) /**< UART2_C2.TE Field                       */
#define UART_C2_ILIE_MASK                        (0x10U)                                             /**< UART2_C2.ILIE Mask                      */
#define UART_C2_ILIE_SHIFT                       (4U)                                                /**< UART2_C2.ILIE Position                  */
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_ILIE_SHIFT))&UART_C2_ILIE_MASK) /**< UART2_C2.ILIE Field                     */
#define UART_C2_RIE_MASK                         (0x20U)                                             /**< UART2_C2.RIE Mask                       */
#define UART_C2_RIE_SHIFT                        (5U)                                                /**< UART2_C2.RIE Position                   */
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RIE_SHIFT))&UART_C2_RIE_MASK) /**< UART2_C2.RIE Field                      */
#define UART_C2_TCIE_MASK                        (0x40U)                                             /**< UART2_C2.TCIE Mask                      */
#define UART_C2_TCIE_SHIFT                       (6U)                                                /**< UART2_C2.TCIE Position                  */
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_TCIE_SHIFT))&UART_C2_TCIE_MASK) /**< UART2_C2.TCIE Field                     */
#define UART_C2_TIE_MASK                         (0x80U)                                             /**< UART2_C2.TIE Mask                       */
#define UART_C2_TIE_SHIFT                        (7U)                                                /**< UART2_C2.TIE Position                   */
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_TIE_SHIFT))&UART_C2_TIE_MASK) /**< UART2_C2.TIE Field                      */
/** @} */

/** @name S1 - Status Register 1 */ /** @{ */
#define UART_S1_PF_MASK                          (0x1U)                                              /**< UART2_S1.PF Mask                        */
#define UART_S1_PF_SHIFT                         (0U)                                                /**< UART2_S1.PF Position                    */
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_PF_SHIFT))&UART_S1_PF_MASK) /**< UART2_S1.PF Field                       */
#define UART_S1_FE_MASK                          (0x2U)                                              /**< UART2_S1.FE Mask                        */
#define UART_S1_FE_SHIFT                         (1U)                                                /**< UART2_S1.FE Position                    */
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_FE_SHIFT))&UART_S1_FE_MASK) /**< UART2_S1.FE Field                       */
#define UART_S1_NF_MASK                          (0x4U)                                              /**< UART2_S1.NF Mask                        */
#define UART_S1_NF_SHIFT                         (2U)                                                /**< UART2_S1.NF Position                    */
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_NF_SHIFT))&UART_S1_NF_MASK) /**< UART2_S1.NF Field                       */
#define UART_S1_OR_MASK                          (0x8U)                                              /**< UART2_S1.OR Mask                        */
#define UART_S1_OR_SHIFT                         (3U)                                                /**< UART2_S1.OR Position                    */
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_OR_SHIFT))&UART_S1_OR_MASK) /**< UART2_S1.OR Field                       */
#define UART_S1_IDLE_MASK                        (0x10U)                                             /**< UART2_S1.IDLE Mask                      */
#define UART_S1_IDLE_SHIFT                       (4U)                                                /**< UART2_S1.IDLE Position                  */
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_IDLE_SHIFT))&UART_S1_IDLE_MASK) /**< UART2_S1.IDLE Field                     */
#define UART_S1_RDRF_MASK                        (0x20U)                                             /**< UART2_S1.RDRF Mask                      */
#define UART_S1_RDRF_SHIFT                       (5U)                                                /**< UART2_S1.RDRF Position                  */
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_RDRF_SHIFT))&UART_S1_RDRF_MASK) /**< UART2_S1.RDRF Field                     */
#define UART_S1_TC_MASK                          (0x40U)                                             /**< UART2_S1.TC Mask                        */
#define UART_S1_TC_SHIFT                         (6U)                                                /**< UART2_S1.TC Position                    */
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_TC_SHIFT))&UART_S1_TC_MASK) /**< UART2_S1.TC Field                       */
#define UART_S1_TDRE_MASK                        (0x80U)                                             /**< UART2_S1.TDRE Mask                      */
#define UART_S1_TDRE_SHIFT                       (7U)                                                /**< UART2_S1.TDRE Position                  */
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_TDRE_SHIFT))&UART_S1_TDRE_MASK) /**< UART2_S1.TDRE Field                     */
/** @} */

/** @name S2 - Status Register 2 */ /** @{ */
#define UART_S2_RAF_MASK                         (0x1U)                                              /**< UART2_S2.RAF Mask                       */
#define UART_S2_RAF_SHIFT                        (0U)                                                /**< UART2_S2.RAF Position                   */
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x))<<UART_S2_RAF_SHIFT))&UART_S2_RAF_MASK) /**< UART2_S2.RAF Field                      */
#define UART_S2_BRK13_MASK                       (0x4U)                                              /**< UART2_S2.BRK13 Mask                     */
#define UART_S2_BRK13_SHIFT                      (2U)                                                /**< UART2_S2.BRK13 Position                 */
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_BRK13_SHIFT))&UART_S2_BRK13_MASK) /**< UART2_S2.BRK13 Field                    */
#define UART_S2_RWUID_MASK                       (0x8U)                                              /**< UART2_S2.RWUID Mask                     */
#define UART_S2_RWUID_SHIFT                      (3U)                                                /**< UART2_S2.RWUID Position                 */
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RWUID_SHIFT))&UART_S2_RWUID_MASK) /**< UART2_S2.RWUID Field                    */
#define UART_S2_RXINV_MASK                       (0x10U)                                             /**< UART2_S2.RXINV Mask                     */
#define UART_S2_RXINV_SHIFT                      (4U)                                                /**< UART2_S2.RXINV Position                 */
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RXINV_SHIFT))&UART_S2_RXINV_MASK) /**< UART2_S2.RXINV Field                    */
#define UART_S2_MSBF_MASK                        (0x20U)                                             /**< UART2_S2.MSBF Mask                      */
#define UART_S2_MSBF_SHIFT                       (5U)                                                /**< UART2_S2.MSBF Position                  */
#define UART_S2_MSBF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S2_MSBF_SHIFT))&UART_S2_MSBF_MASK) /**< UART2_S2.MSBF Field                     */
#define UART_S2_RXEDGIF_MASK                     (0x40U)                                             /**< UART2_S2.RXEDGIF Mask                   */
#define UART_S2_RXEDGIF_SHIFT                    (6U)                                                /**< UART2_S2.RXEDGIF Position               */
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_S2_RXEDGIF_SHIFT))&UART_S2_RXEDGIF_MASK) /**< UART2_S2.RXEDGIF Field                  */
/** @} */

/** @name C3 - Control Register 3 */ /** @{ */
#define UART_C3_PEIE_MASK                        (0x1U)                                              /**< UART2_C3.PEIE Mask                      */
#define UART_C3_PEIE_SHIFT                       (0U)                                                /**< UART2_C3.PEIE Position                  */
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_PEIE_SHIFT))&UART_C3_PEIE_MASK) /**< UART2_C3.PEIE Field                     */
#define UART_C3_FEIE_MASK                        (0x2U)                                              /**< UART2_C3.FEIE Mask                      */
#define UART_C3_FEIE_SHIFT                       (1U)                                                /**< UART2_C3.FEIE Position                  */
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_FEIE_SHIFT))&UART_C3_FEIE_MASK) /**< UART2_C3.FEIE Field                     */
#define UART_C3_NEIE_MASK                        (0x4U)                                              /**< UART2_C3.NEIE Mask                      */
#define UART_C3_NEIE_SHIFT                       (2U)                                                /**< UART2_C3.NEIE Position                  */
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_NEIE_SHIFT))&UART_C3_NEIE_MASK) /**< UART2_C3.NEIE Field                     */
#define UART_C3_ORIE_MASK                        (0x8U)                                              /**< UART2_C3.ORIE Mask                      */
#define UART_C3_ORIE_SHIFT                       (3U)                                                /**< UART2_C3.ORIE Position                  */
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_ORIE_SHIFT))&UART_C3_ORIE_MASK) /**< UART2_C3.ORIE Field                     */
#define UART_C3_TXINV_MASK                       (0x10U)                                             /**< UART2_C3.TXINV Mask                     */
#define UART_C3_TXINV_SHIFT                      (4U)                                                /**< UART2_C3.TXINV Position                 */
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXINV_SHIFT))&UART_C3_TXINV_MASK) /**< UART2_C3.TXINV Field                    */
#define UART_C3_TXDIR_MASK                       (0x20U)                                             /**< UART2_C3.TXDIR Mask                     */
#define UART_C3_TXDIR_SHIFT                      (5U)                                                /**< UART2_C3.TXDIR Position                 */
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXDIR_SHIFT))&UART_C3_TXDIR_MASK) /**< UART2_C3.TXDIR Field                    */
#define UART_C3_T8_MASK                          (0x40U)                                             /**< UART2_C3.T8 Mask                        */
#define UART_C3_T8_SHIFT                         (6U)                                                /**< UART2_C3.T8 Position                    */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_T8_SHIFT))&UART_C3_T8_MASK) /**< UART2_C3.T8 Field                       */
#define UART_C3_R8_MASK                          (0x80U)                                             /**< UART2_C3.R8 Mask                        */
#define UART_C3_R8_SHIFT                         (7U)                                                /**< UART2_C3.R8 Position                    */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_R8_SHIFT))&UART_C3_R8_MASK) /**< UART2_C3.R8 Field                       */
/** @} */

/** @name D - Data Register */ /** @{ */
#define UART_D_RT_MASK                           (0xFFU)                                             /**< UART2_D.RT Mask                         */
#define UART_D_RT_SHIFT                          (0U)                                                /**< UART2_D.RT Position                     */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /**< UART2_D.RT Field                        */
/** @} */

/** @name MA - Match Address Register %s */ /** @{ */
#define UART_MA_MA_MASK                          (0xFFU)                                             /**< UART2_MA.MA Mask                        */
#define UART_MA_MA_SHIFT                         (0U)                                                /**< UART2_MA.MA Position                    */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<UART_MA_MA_SHIFT))&UART_MA_MA_MASK) /**< UART2_MA.MA Field                       */
/** @} */

/** @name C4 - Control Register 4 */ /** @{ */
#define UART_C4_BRFA_MASK                        (0x1FU)                                             /**< UART2_C4.BRFA Mask                      */
#define UART_C4_BRFA_SHIFT                       (0U)                                                /**< UART2_C4.BRFA Position                  */
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK) /**< UART2_C4.BRFA Field                     */
#define UART_C4_M10_MASK                         (0x20U)                                             /**< UART2_C4.M10 Mask                       */
#define UART_C4_M10_SHIFT                        (5U)                                                /**< UART2_C4.M10 Position                   */
#define UART_C4_M10(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C4_M10_SHIFT))&UART_C4_M10_MASK) /**< UART2_C4.M10 Field                      */
#define UART_C4_MAEN2_MASK                       (0x40U)                                             /**< UART2_C4.MAEN2 Mask                     */
#define UART_C4_MAEN2_SHIFT                      (6U)                                                /**< UART2_C4.MAEN2 Position                 */
#define UART_C4_MAEN2(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN2_SHIFT))&UART_C4_MAEN2_MASK) /**< UART2_C4.MAEN2 Field                    */
#define UART_C4_MAEN1_MASK                       (0x80U)                                             /**< UART2_C4.MAEN1 Mask                     */
#define UART_C4_MAEN1_SHIFT                      (7U)                                                /**< UART2_C4.MAEN1 Position                 */
#define UART_C4_MAEN1(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN1_SHIFT))&UART_C4_MAEN1_MASK) /**< UART2_C4.MAEN1 Field                    */
/** @} */

/** @name C5 - Control Register 5 */ /** @{ */
#define UART_C5_RDMAS_MASK                       (0x20U)                                             /**< UART2_C5.RDMAS Mask                     */
#define UART_C5_RDMAS_SHIFT                      (5U)                                                /**< UART2_C5.RDMAS Position                 */
#define UART_C5_RDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_RDMAS_SHIFT))&UART_C5_RDMAS_MASK) /**< UART2_C5.RDMAS Field                    */
#define UART_C5_TDMAS_MASK                       (0x80U)                                             /**< UART2_C5.TDMAS Mask                     */
#define UART_C5_TDMAS_SHIFT                      (7U)                                                /**< UART2_C5.TDMAS Position                 */
#define UART_C5_TDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_TDMAS_SHIFT))&UART_C5_TDMAS_MASK) /**< UART2_C5.TDMAS Field                    */
/** @} */

/** @name C7816 - 7816 Control Register */ /** @{ */
#define UART_C7816_ISO_7816E_MASK                (0x1U)                                              /**< UART2_C7816.ISO_7816E Mask              */
#define UART_C7816_ISO_7816E_SHIFT               (0U)                                                /**< UART2_C7816.ISO_7816E Position          */
#define UART_C7816_ISO_7816E(x)                  (((uint8_t)(((uint8_t)(x))<<UART_C7816_ISO_7816E_SHIFT))&UART_C7816_ISO_7816E_MASK) /**< UART2_C7816.ISO_7816E Field             */
#define UART_C7816_TTYPE_MASK                    (0x2U)                                              /**< UART2_C7816.TTYPE Mask                  */
#define UART_C7816_TTYPE_SHIFT                   (1U)                                                /**< UART2_C7816.TTYPE Position              */
#define UART_C7816_TTYPE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_TTYPE_SHIFT))&UART_C7816_TTYPE_MASK) /**< UART2_C7816.TTYPE Field                 */
#define UART_C7816_INIT_MASK                     (0x4U)                                              /**< UART2_C7816.INIT Mask                   */
#define UART_C7816_INIT_SHIFT                    (2U)                                                /**< UART2_C7816.INIT Position               */
#define UART_C7816_INIT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_C7816_INIT_SHIFT))&UART_C7816_INIT_MASK) /**< UART2_C7816.INIT Field                  */
#define UART_C7816_ANACK_MASK                    (0x8U)                                              /**< UART2_C7816.ANACK Mask                  */
#define UART_C7816_ANACK_SHIFT                   (3U)                                                /**< UART2_C7816.ANACK Position              */
#define UART_C7816_ANACK(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_ANACK_SHIFT))&UART_C7816_ANACK_MASK) /**< UART2_C7816.ANACK Field                 */
#define UART_C7816_ONACK_MASK                    (0x10U)                                             /**< UART2_C7816.ONACK Mask                  */
#define UART_C7816_ONACK_SHIFT                   (4U)                                                /**< UART2_C7816.ONACK Position              */
#define UART_C7816_ONACK(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_ONACK_SHIFT))&UART_C7816_ONACK_MASK) /**< UART2_C7816.ONACK Field                 */
/** @} */

/** @name IE7816 - 7816 Interrupt Enable Register */ /** @{ */
#define UART_IE7816_RXTE_MASK                    (0x1U)                                              /**< UART2_IE7816.RXTE Mask                  */
#define UART_IE7816_RXTE_SHIFT                   (0U)                                                /**< UART2_IE7816.RXTE Position              */
#define UART_IE7816_RXTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_RXTE_SHIFT))&UART_IE7816_RXTE_MASK) /**< UART2_IE7816.RXTE Field                 */
#define UART_IE7816_TXTE_MASK                    (0x2U)                                              /**< UART2_IE7816.TXTE Mask                  */
#define UART_IE7816_TXTE_SHIFT                   (1U)                                                /**< UART2_IE7816.TXTE Position              */
#define UART_IE7816_TXTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_TXTE_SHIFT))&UART_IE7816_TXTE_MASK) /**< UART2_IE7816.TXTE Field                 */
#define UART_IE7816_GTVE_MASK                    (0x4U)                                              /**< UART2_IE7816.GTVE Mask                  */
#define UART_IE7816_GTVE_SHIFT                   (2U)                                                /**< UART2_IE7816.GTVE Position              */
#define UART_IE7816_GTVE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_GTVE_SHIFT))&UART_IE7816_GTVE_MASK) /**< UART2_IE7816.GTVE Field                 */
#define UART_IE7816_ADTE_MASK                    (0x8U)                                              /**< UART2_IE7816.ADTE Mask                  */
#define UART_IE7816_ADTE_SHIFT                   (3U)                                                /**< UART2_IE7816.ADTE Position              */
#define UART_IE7816_ADTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_ADTE_SHIFT))&UART_IE7816_ADTE_MASK) /**< UART2_IE7816.ADTE Field                 */
#define UART_IE7816_INITDE_MASK                  (0x10U)                                             /**< UART2_IE7816.INITDE Mask                */
#define UART_IE7816_INITDE_SHIFT                 (4U)                                                /**< UART2_IE7816.INITDE Position            */
#define UART_IE7816_INITDE(x)                    (((uint8_t)(((uint8_t)(x))<<UART_IE7816_INITDE_SHIFT))&UART_IE7816_INITDE_MASK) /**< UART2_IE7816.INITDE Field               */
#define UART_IE7816_BWTE_MASK                    (0x20U)                                             /**< UART2_IE7816.BWTE Mask                  */
#define UART_IE7816_BWTE_SHIFT                   (5U)                                                /**< UART2_IE7816.BWTE Position              */
#define UART_IE7816_BWTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_BWTE_SHIFT))&UART_IE7816_BWTE_MASK) /**< UART2_IE7816.BWTE Field                 */
#define UART_IE7816_CWTE_MASK                    (0x40U)                                             /**< UART2_IE7816.CWTE Mask                  */
#define UART_IE7816_CWTE_SHIFT                   (6U)                                                /**< UART2_IE7816.CWTE Position              */
#define UART_IE7816_CWTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_CWTE_SHIFT))&UART_IE7816_CWTE_MASK) /**< UART2_IE7816.CWTE Field                 */
#define UART_IE7816_WTE_MASK                     (0x80U)                                             /**< UART2_IE7816.WTE Mask                   */
#define UART_IE7816_WTE_SHIFT                    (7U)                                                /**< UART2_IE7816.WTE Position               */
#define UART_IE7816_WTE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IE7816_WTE_SHIFT))&UART_IE7816_WTE_MASK) /**< UART2_IE7816.WTE Field                  */
/** @} */

/** @name IS7816 - 7816 Interrupt Status Register */ /** @{ */
#define UART_IS7816_RXT_MASK                     (0x1U)                                              /**< UART2_IS7816.RXT Mask                   */
#define UART_IS7816_RXT_SHIFT                    (0U)                                                /**< UART2_IS7816.RXT Position               */
#define UART_IS7816_RXT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_RXT_SHIFT))&UART_IS7816_RXT_MASK) /**< UART2_IS7816.RXT Field                  */
#define UART_IS7816_TXT_MASK                     (0x2U)                                              /**< UART2_IS7816.TXT Mask                   */
#define UART_IS7816_TXT_SHIFT                    (1U)                                                /**< UART2_IS7816.TXT Position               */
#define UART_IS7816_TXT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_TXT_SHIFT))&UART_IS7816_TXT_MASK) /**< UART2_IS7816.TXT Field                  */
#define UART_IS7816_GTV_MASK                     (0x4U)                                              /**< UART2_IS7816.GTV Mask                   */
#define UART_IS7816_GTV_SHIFT                    (2U)                                                /**< UART2_IS7816.GTV Position               */
#define UART_IS7816_GTV(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_GTV_SHIFT))&UART_IS7816_GTV_MASK) /**< UART2_IS7816.GTV Field                  */
#define UART_IS7816_ADT_MASK                     (0x8U)                                              /**< UART2_IS7816.ADT Mask                   */
#define UART_IS7816_ADT_SHIFT                    (3U)                                                /**< UART2_IS7816.ADT Position               */
#define UART_IS7816_ADT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_ADT_SHIFT))&UART_IS7816_ADT_MASK) /**< UART2_IS7816.ADT Field                  */
#define UART_IS7816_INITD_MASK                   (0x10U)                                             /**< UART2_IS7816.INITD Mask                 */
#define UART_IS7816_INITD_SHIFT                  (4U)                                                /**< UART2_IS7816.INITD Position             */
#define UART_IS7816_INITD(x)                     (((uint8_t)(((uint8_t)(x))<<UART_IS7816_INITD_SHIFT))&UART_IS7816_INITD_MASK) /**< UART2_IS7816.INITD Field                */
#define UART_IS7816_BWT_MASK                     (0x20U)                                             /**< UART2_IS7816.BWT Mask                   */
#define UART_IS7816_BWT_SHIFT                    (5U)                                                /**< UART2_IS7816.BWT Position               */
#define UART_IS7816_BWT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_BWT_SHIFT))&UART_IS7816_BWT_MASK) /**< UART2_IS7816.BWT Field                  */
#define UART_IS7816_CWT_MASK                     (0x40U)                                             /**< UART2_IS7816.CWT Mask                   */
#define UART_IS7816_CWT_SHIFT                    (6U)                                                /**< UART2_IS7816.CWT Position               */
#define UART_IS7816_CWT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_CWT_SHIFT))&UART_IS7816_CWT_MASK) /**< UART2_IS7816.CWT Field                  */
#define UART_IS7816_WT_MASK                      (0x80U)                                             /**< UART2_IS7816.WT Mask                    */
#define UART_IS7816_WT_SHIFT                     (7U)                                                /**< UART2_IS7816.WT Position                */
#define UART_IS7816_WT(x)                        (((uint8_t)(((uint8_t)(x))<<UART_IS7816_WT_SHIFT))&UART_IS7816_WT_MASK) /**< UART2_IS7816.WT Field                   */
/** @} */

/** @name WP7816 - 7816 Wait Parameter Register */ /** @{ */
#define UART_WP7816_WTX_MASK                     (0xFFU)                                             /**< UART2_WP7816.WTX Mask                   */
#define UART_WP7816_WTX_SHIFT                    (0U)                                                /**< UART2_WP7816.WTX Position               */
#define UART_WP7816_WTX(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WP7816_WTX_SHIFT))&UART_WP7816_WTX_MASK) /**< UART2_WP7816.WTX Field                  */
/** @} */

/** @name WN7816 - 7816 Wait N Register */ /** @{ */
#define UART_WN7816_GTN_MASK                     (0xFFU)                                             /**< UART2_WN7816.GTN Mask                   */
#define UART_WN7816_GTN_SHIFT                    (0U)                                                /**< UART2_WN7816.GTN Position               */
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK) /**< UART2_WN7816.GTN Field                  */
/** @} */

/** @name WF7816 - 7816 Wait FD Register */ /** @{ */
#define UART_WF7816_GTFD_MASK                    (0xFFU)                                             /**< UART2_WF7816.GTFD Mask                  */
#define UART_WF7816_GTFD_SHIFT                   (0U)                                                /**< UART2_WF7816.GTFD Position              */
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK) /**< UART2_WF7816.GTFD Field                 */
/** @} */

/** @name ET7816 - 7816 Error Threshold Register */ /** @{ */
#define UART_ET7816_RXTHRESHOLD_MASK             (0xFU)                                              /**< UART2_ET7816.RXTHRESHOLD Mask           */
#define UART_ET7816_RXTHRESHOLD_SHIFT            (0U)                                                /**< UART2_ET7816.RXTHRESHOLD Position       */
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK) /**< UART2_ET7816.RXTHRESHOLD Field          */
#define UART_ET7816_TXTHRESHOLD_MASK             (0xF0U)                                             /**< UART2_ET7816.TXTHRESHOLD Mask           */
#define UART_ET7816_TXTHRESHOLD_SHIFT            (4U)                                                /**< UART2_ET7816.TXTHRESHOLD Position       */
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK) /**< UART2_ET7816.TXTHRESHOLD Field          */
/** @} */

/** @name TL7816 - 7816 Transmit Length Register */ /** @{ */
#define UART_TL7816_TLEN_MASK                    (0xFFU)                                             /**< UART2_TL7816.TLEN Mask                  */
#define UART_TL7816_TLEN_SHIFT                   (0U)                                                /**< UART2_TL7816.TLEN Position              */
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK) /**< UART2_TL7816.TLEN Field                 */
/** @} */

/** @name AP7816A_T0 - 7816 ATR Duration Timer Register A */ /** @{ */
#define UART_AP7816A_T0_ADTI_H_MASK              (0xFFU)                                             /**< UART2_AP7816A_T0.ADTI_H Mask            */
#define UART_AP7816A_T0_ADTI_H_SHIFT             (0U)                                                /**< UART2_AP7816A_T0.ADTI_H Position        */
#define UART_AP7816A_T0_ADTI_H(x)                (((uint8_t)(((uint8_t)(x))<<UART_AP7816A_T0_ADTI_H_SHIFT))&UART_AP7816A_T0_ADTI_H_MASK) /**< UART2_AP7816A_T0.ADTI_H Field           */
/** @} */

/** @name AP7816B_T0 - 7816 ATR Duration Timer Register B */ /** @{ */
#define UART_AP7816B_T0_ADTI_L_MASK              (0xFFU)                                             /**< UART2_AP7816B_T0.ADTI_L Mask            */
#define UART_AP7816B_T0_ADTI_L_SHIFT             (0U)                                                /**< UART2_AP7816B_T0.ADTI_L Position        */
#define UART_AP7816B_T0_ADTI_L(x)                (((uint8_t)(((uint8_t)(x))<<UART_AP7816B_T0_ADTI_L_SHIFT))&UART_AP7816B_T0_ADTI_L_MASK) /**< UART2_AP7816B_T0.ADTI_L Field           */
/** @} */

/** @name WP7816A_T0 - 7816 Wait Parameter Register A */ /** @{ */
#define UART_WP7816A_T0_WI_H_MASK                (0xFFU)                                             /**< UART2_WP7816A_T0.WI_H Mask              */
#define UART_WP7816A_T0_WI_H_SHIFT               (0U)                                                /**< UART2_WP7816A_T0.WI_H Position          */
#define UART_WP7816A_T0_WI_H(x)                  (((uint8_t)(((uint8_t)(x))<<UART_WP7816A_T0_WI_H_SHIFT))&UART_WP7816A_T0_WI_H_MASK) /**< UART2_WP7816A_T0.WI_H Field             */
/** @} */

/** @name WP7816A_T1 - 7816 Wait Parameter Register A */ /** @{ */
#define UART_WP7816A_T1_BWI_H_MASK               (0xFFU)                                             /**< UART2_WP7816A_T1.BWI_H Mask             */
#define UART_WP7816A_T1_BWI_H_SHIFT              (0U)                                                /**< UART2_WP7816A_T1.BWI_H Position         */
#define UART_WP7816A_T1_BWI_H(x)                 (((uint8_t)(((uint8_t)(x))<<UART_WP7816A_T1_BWI_H_SHIFT))&UART_WP7816A_T1_BWI_H_MASK) /**< UART2_WP7816A_T1.BWI_H Field            */
/** @} */

/** @name WP7816B_T0 - 7816 Wait Parameter Register B */ /** @{ */
#define UART_WP7816B_T0_WI_L_MASK                (0xFFU)                                             /**< UART2_WP7816B_T0.WI_L Mask              */
#define UART_WP7816B_T0_WI_L_SHIFT               (0U)                                                /**< UART2_WP7816B_T0.WI_L Position          */
#define UART_WP7816B_T0_WI_L(x)                  (((uint8_t)(((uint8_t)(x))<<UART_WP7816B_T0_WI_L_SHIFT))&UART_WP7816B_T0_WI_L_MASK) /**< UART2_WP7816B_T0.WI_L Field             */
/** @} */

/** @name WP7816B_T1 - 7816 Wait Parameter Register B */ /** @{ */
#define UART_WP7816B_T1_BWI_L_MASK               (0xFFU)                                             /**< UART2_WP7816B_T1.BWI_L Mask             */
#define UART_WP7816B_T1_BWI_L_SHIFT              (0U)                                                /**< UART2_WP7816B_T1.BWI_L Position         */
#define UART_WP7816B_T1_BWI_L(x)                 (((uint8_t)(((uint8_t)(x))<<UART_WP7816B_T1_BWI_L_SHIFT))&UART_WP7816B_T1_BWI_L_MASK) /**< UART2_WP7816B_T1.BWI_L Field            */
/** @} */

/** @name WGP7816_T1 - 7816 Wait and Guard Parameter Register */ /** @{ */
#define UART_WGP7816_T1_BGI_MASK                 (0xFU)                                              /**< UART2_WGP7816_T1.BGI Mask               */
#define UART_WGP7816_T1_BGI_SHIFT                (0U)                                                /**< UART2_WGP7816_T1.BGI Position           */
#define UART_WGP7816_T1_BGI(x)                   (((uint8_t)(((uint8_t)(x))<<UART_WGP7816_T1_BGI_SHIFT))&UART_WGP7816_T1_BGI_MASK) /**< UART2_WGP7816_T1.BGI Field              */
#define UART_WGP7816_T1_CWI1_MASK                (0xF0U)                                             /**< UART2_WGP7816_T1.CWI1 Mask              */
#define UART_WGP7816_T1_CWI1_SHIFT               (4U)                                                /**< UART2_WGP7816_T1.CWI1 Position          */
#define UART_WGP7816_T1_CWI1(x)                  (((uint8_t)(((uint8_t)(x))<<UART_WGP7816_T1_CWI1_SHIFT))&UART_WGP7816_T1_CWI1_MASK) /**< UART2_WGP7816_T1.CWI1 Field             */
/** @} */

/** @name WP7816C_T1 - 7816 Wait Parameter Register C */ /** @{ */
#define UART_WP7816C_T1_CWI2_MASK                (0x1FU)                                             /**< UART2_WP7816C_T1.CWI2 Mask              */
#define UART_WP7816C_T1_CWI2_SHIFT               (0U)                                                /**< UART2_WP7816C_T1.CWI2 Position          */
#define UART_WP7816C_T1_CWI2(x)                  (((uint8_t)(((uint8_t)(x))<<UART_WP7816C_T1_CWI2_SHIFT))&UART_WP7816C_T1_CWI2_MASK) /**< UART2_WP7816C_T1.CWI2 Field             */
/** @} */

/** @} */ /* End group UART_Register_Masks_GROUP */


/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x4006C000UL //!< Peripheral base address
#define UART2                          ((UART_Type *) UART2_BasePtr) //!< Freescale base pointer
#define UART2_BASE_PTR                 (UART2) //!< Freescale style base pointer
#define UART2_IRQS { UART2_FLEXIO_IRQn,  }


/** @} */ /* End group UART_Peripheral_access_layer_GROUP */


/** @brief C Struct for USB */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup USB_Peripheral_access_layer_GROUP USB Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           USB0 (file:USB0_CLKRCV_B)            ================ */
/* ================================================================================ */

/**
 * @brief USB Controller with clock recovery
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
        uint8_t   RESERVED_3[15];               /**< 000D: 0xF bytes                                                    */
   __IO uint8_t   OTGCTL;                       /**< 001C: OTG Control Register                                         */
        uint8_t   RESERVED_4[99];               /**< 001D: 0x63 bytes                                                   */
   __IO uint8_t   ISTAT;                        /**< 0080: Interrupt Status Register                                    */
        uint8_t   RESERVED_5[3];                /**< 0081: 0x3 bytes                                                    */
   __IO uint8_t   INTEN;                        /**< 0084: Interrupt Enable Register                                    */
        uint8_t   RESERVED_6[3];                /**< 0085: 0x3 bytes                                                    */
   __IO uint8_t   ERRSTAT;                      /**< 0088: Error Interrupt Status Register                              */
        uint8_t   RESERVED_7[3];                /**< 0089: 0x3 bytes                                                    */
   __IO uint8_t   ERREN;                        /**< 008C: Error Interrupt Enable Register                              */
        uint8_t   RESERVED_8[3];                /**< 008D: 0x3 bytes                                                    */
   __I  uint8_t   STAT;                         /**< 0090: Status Register                                              */
        uint8_t   RESERVED_9[3];                /**< 0091: 0x3 bytes                                                    */
   __IO uint8_t   CTL;                          /**< 0094: Control Register                                             */
        uint8_t   RESERVED_10[3];               /**< 0095: 0x3 bytes                                                    */
   __IO uint8_t   ADDR;                         /**< 0098: Address Register                                             */
        uint8_t   RESERVED_11[3];               /**< 0099: 0x3 bytes                                                    */
   __IO uint8_t   BDTPAGE1;                     /**< 009C: BDT Page Register 1                                          */
        uint8_t   RESERVED_12[3];               /**< 009D: 0x3 bytes                                                    */
   __IO uint8_t   FRMNUML;                      /**< 00A0: Frame Number Register Low                                    */
        uint8_t   RESERVED_13[3];               /**< 00A1: 0x3 bytes                                                    */
   __IO uint8_t   FRMNUMH;                      /**< 00A4: Frame Number Register High                                   */
        uint8_t   RESERVED_14[11];              /**< 00A5: 0xB bytes                                                    */
   __IO uint8_t   BDTPAGE2;                     /**< 00B0: BDT Page Register 2                                          */
        uint8_t   RESERVED_15[3];               /**< 00B1: 0x3 bytes                                                    */
   __IO uint8_t   BDTPAGE3;                     /**< 00B4: BDT Page Register 3                                          */
        uint8_t   RESERVED_16[11];              /**< 00B5: 0xB bytes                                                    */
   struct {
      __IO uint8_t   ENDPT;                     /**< 00C0: Endpoint Control Register                                    */
           uint8_t   RESERVED_17[3];            /**< 00C1: 0x3 bytes                                                    */
   } ENDPOINT[16];                              /**< 00C0: (cluster: size=0x0040, 64)                                   */
   __IO uint8_t   USBCTRL;                      /**< 0100: USB Control Register                                         */
        uint8_t   RESERVED_18[3];               /**< 0101: 0x3 bytes                                                    */
   __I  uint8_t   OBSERVE;                      /**< 0104: USB OTG Observe Register                                     */
        uint8_t   RESERVED_19[3];               /**< 0105: 0x3 bytes                                                    */
   __IO uint8_t   CONTROL;                      /**< 0108: USB OTG Control Register                                     */
        uint8_t   RESERVED_20[3];               /**< 0109: 0x3 bytes                                                    */
   __IO uint8_t   USBTRC0;                      /**< 010C: USB Transceiver Control Register 0                           */
        uint8_t   RESERVED_21[7];               /**< 010D: 0x7 bytes                                                    */
   __IO uint8_t   USBFRMADJUST;                 /**< 0114: Frame Adjust Register                                        */
        uint8_t   RESERVED_22[15];              /**< 0115: 0xF bytes                                                    */
   __IO uint8_t   KEEP_ALIVE_CTRL;              /**< 0124: Keep Alive mode control                                      */
        uint8_t   RESERVED_23[3];               /**< 0125: 0x3 bytes                                                    */
   __IO uint8_t   KEEP_ALIVE_WKCTRL;            /**< 0128: Keep Alive mode wakeup control                               */
        uint8_t   RESERVED_24[23];              /**< 0129: 0x17 bytes                                                   */
   __IO uint8_t   CLK_RECOVER_CTRL;             /**< 0140: USB Clock recovery control                                   */
        uint8_t   RESERVED_25[3];               /**< 0141: 0x3 bytes                                                    */
   __IO uint8_t   CLK_RECOVER_IRC_EN;           /**< 0144: IRC48M oscillator enable register                            */
        uint8_t   RESERVED_26[15];              /**< 0145: 0xF bytes                                                    */
   __IO uint8_t   CLK_RECOVER_INT_EN;           /**< 0154: Clock recovery combined interrupt enable                     */
        uint8_t   RESERVED_27[7];               /**< 0155: 0x7 bytes                                                    */
   __IO uint8_t   CLK_RECOVER_INT_STATUS;       /**< 015C: Clock recovery separated interrupt status                    */
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
/** @} */

/** @name OTGCTL - OTG Control Register */ /** @{ */
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
#define USB_INTEN_STALLEN_MASK                   (0x80U)                                             /**< USB0_INTEN.STALLEN Mask                 */
#define USB_INTEN_STALLEN_SHIFT                  (7U)                                                /**< USB0_INTEN.STALLEN Position             */
#define USB_INTEN_STALLEN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_STALLEN_SHIFT))&USB_INTEN_STALLEN_MASK) /**< USB0_INTEN.STALLEN Field                */
/** @} */

/** @name ERRSTAT - Error Interrupt Status Register */ /** @{ */
#define USB_ERRSTAT_PIDERR_MASK                  (0x1U)                                              /**< USB0_ERRSTAT.PIDERR Mask                */
#define USB_ERRSTAT_PIDERR_SHIFT                 (0U)                                                /**< USB0_ERRSTAT.PIDERR Position            */
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_PIDERR_SHIFT))&USB_ERRSTAT_PIDERR_MASK) /**< USB0_ERRSTAT.PIDERR Field               */
#define USB_ERRSTAT_CRC5_MASK                    (0x2U)                                              /**< USB0_ERRSTAT.CRC5 Mask                  */
#define USB_ERRSTAT_CRC5_SHIFT                   (1U)                                                /**< USB0_ERRSTAT.CRC5 Position              */
#define USB_ERRSTAT_CRC5(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_CRC5_SHIFT))&USB_ERRSTAT_CRC5_MASK) /**< USB0_ERRSTAT.CRC5 Field                 */
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
#define USB_ERREN_CRC5EN_MASK                    (0x2U)                                              /**< USB0_ERREN.CRC5EN Mask                  */
#define USB_ERREN_CRC5EN_SHIFT                   (1U)                                                /**< USB0_ERREN.CRC5EN Position              */
#define USB_ERREN_CRC5EN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ERREN_CRC5EN_SHIFT))&USB_ERREN_CRC5EN_MASK) /**< USB0_ERREN.CRC5EN Field                 */
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
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK    (0x4U)                                              /**< USB0_USBTRC0.USB_CLK_RECOVERY_INT Mask  */
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT   (2U)                                                /**< USB0_USBTRC0.USB_CLK_RECOVERY_INT Position*/
#define USB_USBTRC0_USB_CLK_RECOVERY_INT(x)      (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT))&USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK) /**< USB0_USBTRC0.USB_CLK_RECOVERY_INT Field */
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

/** @name KEEP_ALIVE_CTRL - Keep Alive mode control */ /** @{ */
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_MASK   (0x1U)                                              /**< USB0_KEEP_ALIVE_CTRL.KEEP_ALIVE_EN Mask */
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_SHIFT  (0U)                                                /**< USB0_KEEP_ALIVE_CTRL.KEEP_ALIVE_EN Position*/
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN(x)     (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_MASK) /**< USB0_KEEP_ALIVE_CTRL.KEEP_ALIVE_EN Field*/
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_MASK   (0x2U)                                              /**< USB0_KEEP_ALIVE_CTRL.OWN_OVERRD_EN Mask */
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_SHIFT  (1U)                                                /**< USB0_KEEP_ALIVE_CTRL.OWN_OVERRD_EN Position*/
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN(x)     (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_MASK) /**< USB0_KEEP_ALIVE_CTRL.OWN_OVERRD_EN Field*/
#define USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN_MASK (0x4U)                                              /**< USB0_KEEP_ALIVE_CTRL.STOP_ACK_DLY_EN Mask*/
#define USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN_SHIFT (2U)                                               /**< USB0_KEEP_ALIVE_CTRL.STOP_ACK_DLY_EN Position*/
#define USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN(x)   (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN_MASK) /**< USB0_KEEP_ALIVE_CTRL.STOP_ACK_DLY_EN Field*/
#define USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_MASK      (0x8U)                                              /**< USB0_KEEP_ALIVE_CTRL.AHB_DLY_EN Mask    */
#define USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_SHIFT     (3U)                                                /**< USB0_KEEP_ALIVE_CTRL.AHB_DLY_EN Position*/
#define USB_KEEP_ALIVE_CTRL_AHB_DLY_EN(x)        (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_AHB_DLY_EN_MASK) /**< USB0_KEEP_ALIVE_CTRL.AHB_DLY_EN Field   */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_MASK     (0x10U)                                             /**< USB0_KEEP_ALIVE_CTRL.WAKE_INT_EN Mask   */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_SHIFT    (4U)                                                /**< USB0_KEEP_ALIVE_CTRL.WAKE_INT_EN Position*/
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN(x)       (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_SHIFT))&USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_MASK) /**< USB0_KEEP_ALIVE_CTRL.WAKE_INT_EN Field  */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_MASK    (0x80U)                                             /**< USB0_KEEP_ALIVE_CTRL.WAKE_INT_STS Mask  */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_SHIFT   (7U)                                                /**< USB0_KEEP_ALIVE_CTRL.WAKE_INT_STS Position*/
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS(x)      (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_SHIFT))&USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_MASK) /**< USB0_KEEP_ALIVE_CTRL.WAKE_INT_STS Field */
/** @} */

/** @name KEEP_ALIVE_WKCTRL - Keep Alive mode wakeup control */ /** @{ */
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_MASK  (0xFU)                                              /**< USB0_KEEP_ALIVE_WKCTRL.WAKE_ON_THIS Mask*/
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_SHIFT (0U)                                                /**< USB0_KEEP_ALIVE_WKCTRL.WAKE_ON_THIS Position*/
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS(x)    (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_SHIFT))&USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_MASK) /**< USB0_KEEP_ALIVE_WKCTRL.WAKE_ON_THIS Field*/
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_MASK    (0xF0U)                                             /**< USB0_KEEP_ALIVE_WKCTRL.WAKE_ENDPT Mask  */
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_SHIFT   (4U)                                                /**< USB0_KEEP_ALIVE_WKCTRL.WAKE_ENDPT Position*/
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT(x)      (((uint8_t)(((uint8_t)(x))<<USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_SHIFT))&USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_MASK) /**< USB0_KEEP_ALIVE_WKCTRL.WAKE_ENDPT Field */
/** @} */

/** @name CLK_RECOVER_CTRL - USB Clock recovery control */ /** @{ */
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK (0x20U)                                         /**< USB0_CLK_RECOVER_CTRL.RESTART_IFRTRIM_EN Mask*/
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT (5U)                                           /**< USB0_CLK_RECOVER_CTRL.RESTART_IFRTRIM_EN Position*/
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT))&USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK) /**< USB0_CLK_RECOVER_CTRL.RESTART_IFRTRIM_EN Field*/
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK (0x40U)                                      /**< USB0_CLK_RECOVER_CTRL.RESET_RESUME_ROUGH_EN Mask*/
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT (6U)                                        /**< USB0_CLK_RECOVER_CTRL.RESET_RESUME_ROUGH_EN Position*/
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT))&USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK) /**< USB0_CLK_RECOVER_CTRL.RESET_RESUME_ROUGH_EN Field*/
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK (0x80U)                                           /**< USB0_CLK_RECOVER_CTRL.CLOCK_RECOVER_EN Mask*/
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT (7U)                                             /**< USB0_CLK_RECOVER_CTRL.CLOCK_RECOVER_EN Position*/
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT))&USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK) /**< USB0_CLK_RECOVER_CTRL.CLOCK_RECOVER_EN Field*/
/** @} */

/** @name CLK_RECOVER_IRC_EN - IRC48M oscillator enable register */ /** @{ */
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK       (0x2U)                                              /**< USB0_CLK_RECOVER_IRC_EN.IRC_EN Mask     */
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT      (1U)                                                /**< USB0_CLK_RECOVER_IRC_EN.IRC_EN Position */
#define USB_CLK_RECOVER_IRC_EN_IRC_EN(x)         (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT))&USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK) /**< USB0_CLK_RECOVER_IRC_EN.IRC_EN Field    */
/** @} */

/** @name CLK_RECOVER_INT_EN - Clock recovery combined interrupt enable */ /** @{ */
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK (0x10U)                                             /**< USB0_CLK_RECOVER_INT_EN.OVF_ERROR_EN Mask*/
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT (4U)                                               /**< USB0_CLK_RECOVER_INT_EN.OVF_ERROR_EN Position*/
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN(x)   (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT))&USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK) /**< USB0_CLK_RECOVER_INT_EN.OVF_ERROR_EN Field*/
/** @} */

/** @name CLK_RECOVER_INT_STATUS - Clock recovery separated interrupt status */ /** @{ */
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK (0x10U)                                            /**< USB0_CLK_RECOVER_INT_STATUS.OVF_ERROR Mask*/
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT (4U)                                              /**< USB0_CLK_RECOVER_INT_STATUS.OVF_ERROR Position*/
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR(x)  (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT))&USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK) /**< USB0_CLK_RECOVER_INT_STATUS.OVF_ERROR Field*/
/** @} */

/** @} */ /* End group USB_Register_Masks_GROUP */


/* USB0 - Peripheral instance base addresses */
#define USB0_BasePtr                   0x40072000UL //!< Peripheral base address
#define USB0                           ((USB_Type *) USB0_BasePtr) //!< Freescale base pointer
#define USB0_BASE_PTR                  (USB0) //!< Freescale style base pointer
#define USB0_IRQS { USB0_IRQn,  }


/** @} */ /* End group USB_Peripheral_access_layer_GROUP */


/** @brief C Struct for VREF */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup VREF_Peripheral_access_layer_GROUP VREF Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           VREF (file:VREF_C)                   ================ */
/* ================================================================================ */

/**
 * @brief Voltage Reference
 */
/**
 * @struct VREF_Type
 * @brief  C Struct allowing access to VREF registers
 */
typedef struct VREF_Type {
   __IO uint8_t   TRM;                          /**< 0000: Trim Register                                                */
   __IO uint8_t   SC;                           /**< 0001: Status and Control Register                                  */
} VREF_Type;


/** @brief Register Masks for VREF */

/* -------------------------------------------------------------------------------- */
/* -----------     'VREF' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup VREF_Register_Masks_GROUP VREF Register Masks */
/** @{ */

/** @name TRM - Trim Register */ /** @{ */
#define VREF_TRM_TRIM_MASK                       (0x3FU)                                             /**< VREF_TRM.TRIM Mask                      */
#define VREF_TRM_TRIM_SHIFT                      (0U)                                                /**< VREF_TRM.TRIM Position                  */
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_TRIM_SHIFT))&VREF_TRM_TRIM_MASK) /**< VREF_TRM.TRIM Field                     */
#define VREF_TRM_CHOPEN_MASK                     (0x40U)                                             /**< VREF_TRM.CHOPEN Mask                    */
#define VREF_TRM_CHOPEN_SHIFT                    (6U)                                                /**< VREF_TRM.CHOPEN Position                */
#define VREF_TRM_CHOPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_TRM_CHOPEN_SHIFT))&VREF_TRM_CHOPEN_MASK) /**< VREF_TRM.CHOPEN Field                   */
/** @} */

/** @name SC - Status and Control Register */ /** @{ */
#define VREF_SC_MODE_LV_MASK                     (0x3U)                                              /**< VREF_SC.MODE_LV Mask                    */
#define VREF_SC_MODE_LV_SHIFT                    (0U)                                                /**< VREF_SC.MODE_LV Position                */
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_MODE_LV_SHIFT))&VREF_SC_MODE_LV_MASK) /**< VREF_SC.MODE_LV Field                   */
#define VREF_SC_VREFST_MASK                      (0x4U)                                              /**< VREF_SC.VREFST Mask                     */
#define VREF_SC_VREFST_SHIFT                     (2U)                                                /**< VREF_SC.VREFST Position                 */
#define VREF_SC_VREFST(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFST_SHIFT))&VREF_SC_VREFST_MASK) /**< VREF_SC.VREFST Field                    */
#define VREF_SC_ICOMPEN_MASK                     (0x20U)                                             /**< VREF_SC.ICOMPEN Mask                    */
#define VREF_SC_ICOMPEN_SHIFT                    (5U)                                                /**< VREF_SC.ICOMPEN Position                */
#define VREF_SC_ICOMPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_ICOMPEN_SHIFT))&VREF_SC_ICOMPEN_MASK) /**< VREF_SC.ICOMPEN Field                   */
#define VREF_SC_REGEN_MASK                       (0x40U)                                             /**< VREF_SC.REGEN Mask                      */
#define VREF_SC_REGEN_SHIFT                      (6U)                                                /**< VREF_SC.REGEN Position                  */
#define VREF_SC_REGEN(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_SC_REGEN_SHIFT))&VREF_SC_REGEN_MASK) /**< VREF_SC.REGEN Field                     */
#define VREF_SC_VREFEN_MASK                      (0x80U)                                             /**< VREF_SC.VREFEN Mask                     */
#define VREF_SC_VREFEN_SHIFT                     (7U)                                                /**< VREF_SC.VREFEN Position                 */
#define VREF_SC_VREFEN(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFEN_SHIFT))&VREF_SC_VREFEN_MASK) /**< VREF_SC.VREFEN Field                    */
/** @} */

/** @} */ /* End group VREF_Register_Masks_GROUP */


/* VREF - Peripheral instance base addresses */
#define VREF_BasePtr                   0x40074000UL //!< Peripheral base address
#define VREF                           ((VREF_Type *) VREF_BasePtr) //!< Freescale base pointer
#define VREF_BASE_PTR                  (VREF) //!< Freescale style base pointer

/** @} */ /* End group VREF_Peripheral_access_layer_GROUP */

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


#endif  /* MCU_MKL27Z644 */

