/*!
 * @file     MKL02Z4.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKL02Z4.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2024/01
 *
 */

#ifndef _MKL02Z4_H_
#define _MKL02Z4_H_

#define MCU_MKL02Z4

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
/* ----------------------   MKL02Z4 VectorTable                      ---------------------- */
  FTF_Command_IRQn              =   5,   /**<  21 Flash Memory Interface                                                           */
  PMC_IRQn                      =   6,   /**<  22 Power Management Controller                                                      */
  I2C0_IRQn                     =   8,   /**<  24 Inter-Integrated Circuit                                                         */
  I2C1_IRQn                     =   9,   /**<  25 Inter-Integrated Circuit                                                         */
  SPI0_IRQn                     =  10,   /**<  26 Serial Peripheral Interface                                                      */
  UART0_IRQn                    =  12,   /**<  28 Serial Communication Interface                                                   */
  ADC0_IRQn                     =  15,   /**<  31 Analogue to Digital Converter                                                    */
  CMP0_IRQn                     =  16,   /**<  32 High-Speed Comparator                                                            */
  TPM0_IRQn                     =  17,   /**<  33 Timer/PWM Module                                                                 */
  TPM1_IRQn                     =  18,   /**<  34 Timer/PWM Module                                                                 */
  MCG_IRQn                      =  27,   /**<  43 Multipurpose Clock Generator                                                     */
  LPTMR0_IRQn                   =  28,   /**<  44 Low Power Timer                                                                  */
  PORTA_IRQn                    =  30,   /**<  46 General Purpose Input/Output                                                     */
  PORTB_IRQn                    =  31,   /**<  47 General Purpose Input/Output                                                     */
} IRQn_Type;


/** @brief Prototypes for interrupt handlers */
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                       /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);                 /**< Hard Fault, all classes of Fault                                                 */
extern void SVC_Handler(void);                       /**< System Service Call via SVC instruction                                          */
extern void PendSV_Handler(void);                    /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);                   /**< System Tick Timer                                                                */
extern void FTF_Command_IRQHandler(void);            /**< Flash Memory Interface                                                           */
extern void PMC_IRQHandler(void);                    /**< Power Management Controller                                                      */
extern void I2C0_IRQHandler(void);                   /**< Inter-Integrated Circuit                                                         */
extern void I2C1_IRQHandler(void);                   /**< Inter-Integrated Circuit                                                         */
extern void SPI0_IRQHandler(void);                   /**< Serial Peripheral Interface                                                      */
extern void UART0_IRQHandler(void);                  /**< Serial Communication Interface                                                   */
extern void ADC0_IRQHandler(void);                   /**< Analogue to Digital Converter                                                    */
extern void CMP0_IRQHandler(void);                   /**< High-Speed Comparator                                                            */
extern void TPM0_IRQHandler(void);                   /**< Timer/PWM Module                                                                 */
extern void TPM1_IRQHandler(void);                   /**< Timer/PWM Module                                                                 */
extern void MCG_IRQHandler(void);                    /**< Multipurpose Clock Generator                                                     */
extern void LPTMR0_IRQHandler(void);                 /**< Low Power Timer                                                                  */
extern void PORTA_IRQHandler(void);                  /**< General Purpose Input/Output                                                     */
extern void PORTB_IRQHandler(void);                  /**< General Purpose Input/Output                                                     */


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
/* ================           ADC0 (file:ADC0_MKL)                 ================ */
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
        uint8_t   RESERVED_0[4];                /**< 0030: 0x4 bytes                                                    */
   __IO uint32_t  CLPD;                         /**< 0034: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLPS;                         /**< 0038: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP4;                         /**< 003C: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP3;                         /**< 0040: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP2;                         /**< 0044: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP1;                         /**< 0048: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP0;                         /**< 004C: Plus-Side General Calibration Value                          */
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
/* ================           CMP0 (file:CMP0_TRIGM)               ================ */
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
/** @} */

/** @} */ /* End group CMP_Register_Masks_GROUP */


/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0x40073000UL //!< Peripheral base address
#define CMP0                           ((CMP_Type *) CMP0_BasePtr) //!< Freescale base pointer
#define CMP0_BASE_PTR                  (CMP0) //!< Freescale style base pointer
#define CMP0_IRQS { CMP0_IRQn,  }


/** @} */ /* End group CMP_Peripheral_access_layer_GROUP */


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


/** @brief C Struct for I2C */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MKL)                 ================ */
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
/* ================           MCG (file:MCG_NOPLL_MKL02Z4)         ================ */
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
        uint8_t   RESERVED_0;                   /**< 0004: 0x1 bytes                                                    */
   __IO uint8_t   C6;                           /**< 0005: Control 6 Register                                           */
   __I  uint8_t   S;                            /**< 0006: Status Register                                              */
        uint8_t   RESERVED_1;                   /**< 0007: 0x1 bytes                                                    */
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
        uint8_t   RESERVED_2;                   /**< 0009: 0x1 bytes                                                    */
   __IO uint8_t   ATCVH;                        /**< 000A: ATM Compare Value High                                       */
   __IO uint8_t   ATCVL;                        /**< 000B: ATM Compare Value Low                                        */
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
#define MCG_C2_FCFTRIM_MASK                      (0x40U)                                             /**< MCG_C2.FCFTRIM Mask                     */
#define MCG_C2_FCFTRIM_SHIFT                     (6U)                                                /**< MCG_C2.FCFTRIM Position                 */
#define MCG_C2_FCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C2_FCFTRIM_SHIFT))&MCG_C2_FCFTRIM_MASK) /**< MCG_C2.FCFTRIM Field                    */
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

/** @name C6 - Control 6 Register */ /** @{ */
#define MCG_C6_CME0_MASK                         (0x20U)                                             /**< MCG_C6.CME0 Mask                        */
#define MCG_C6_CME0_SHIFT                        (5U)                                                /**< MCG_C6.CME0 Position                    */
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_CME0_SHIFT))&MCG_C6_CME0_MASK) /**< MCG_C6.CME0 Field                       */
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
/* ================           PORTA (file:PORTA_MKL)               ================ */
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
#define PORTB_IRQS { PORTB_IRQn,  }


/** @} */ /* End group PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for RCM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           RCM (file:RCM_MKL02Z4)               ================ */
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


/** @brief C Struct for SIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SIM (file:SIM_MKL02Z4)               ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
/**
 * @struct SIM_Type
 * @brief  C Struct allowing access to SIM registers
 */
typedef struct SIM_Type {
        uint8_t   RESERVED_0[4100];             /**< 0000: 0x1004 bytes                                                 */
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
        uint8_t   RESERVED_5[4];                /**< 1040: 0x4 bytes                                                    */
   __IO uint32_t  CLKDIV1;                      /**< 1044: System Clock Divider Register 1                              */
        uint8_t   RESERVED_6[4];                /**< 1048: 0x4 bytes                                                    */
   __IO uint32_t  FCFG1;                        /**< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /**< 1050: Flash Configuration Register 2                               */
        uint8_t   RESERVED_7[4];                /**< 1054: 0x4 bytes                                                    */
   __I  uint32_t  UIDMH;                        /**< 1058: Unique Identification Register Mid-High                      */
   __I  uint32_t  UIDML;                        /**< 105C: Unique Identification Register Mid Low                       */
   __I  uint32_t  UIDL;                         /**< 1060: Unique Identification Register Low                           */
        uint8_t   RESERVED_8[156];              /**< 1064: 0x9C bytes                                                   */
   __IO uint32_t  COPC;                         /**< 1100: COP Control Register                                         */
   __O  uint32_t  SRVCOP;                       /**< 1104: Service COP                                                  */
} SIM_Type;


/** @brief Register Masks for SIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SIM_Register_Masks_GROUP SIM Register Masks */
/** @{ */

/** @name SOPT2 - System Options Register 2 */ /** @{ */
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
#define SIM_SOPT4_TPM0CLKSEL_MASK                (0x1000000U)                                        /**< SIM_SOPT4.TPM0CLKSEL Mask               */
#define SIM_SOPT4_TPM0CLKSEL_SHIFT               (24U)                                               /**< SIM_SOPT4.TPM0CLKSEL Position           */
#define SIM_SOPT4_TPM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM0CLKSEL_SHIFT))&SIM_SOPT4_TPM0CLKSEL_MASK) /**< SIM_SOPT4.TPM0CLKSEL Field              */
#define SIM_SOPT4_TPM1CLKSEL_MASK                (0x2000000U)                                        /**< SIM_SOPT4.TPM1CLKSEL Mask               */
#define SIM_SOPT4_TPM1CLKSEL_SHIFT               (25U)                                               /**< SIM_SOPT4.TPM1CLKSEL Position           */
#define SIM_SOPT4_TPM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_TPM1CLKSEL_SHIFT))&SIM_SOPT4_TPM1CLKSEL_MASK) /**< SIM_SOPT4.TPM1CLKSEL Field              */
/** @} */

/** @name SOPT5 - System Options Register 5 */ /** @{ */
#define SIM_SOPT5_UART0TXSRC_MASK                (0x1U)                                              /**< SIM_SOPT5.UART0TXSRC Mask               */
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)                                                /**< SIM_SOPT5.UART0TXSRC Position           */
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0TXSRC_SHIFT))&SIM_SOPT5_UART0TXSRC_MASK) /**< SIM_SOPT5.UART0TXSRC Field              */
#define SIM_SOPT5_UART0RXSRC_MASK                (0x4U)                                              /**< SIM_SOPT5.UART0RXSRC Mask               */
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)                                                /**< SIM_SOPT5.UART0RXSRC Position           */
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0RXSRC_SHIFT))&SIM_SOPT5_UART0RXSRC_MASK) /**< SIM_SOPT5.UART0RXSRC Field              */
#define SIM_SOPT5_UART0ODE_MASK                  (0x10000U)                                          /**< SIM_SOPT5.UART0ODE Mask                 */
#define SIM_SOPT5_UART0ODE_SHIFT                 (16U)                                               /**< SIM_SOPT5.UART0ODE Position             */
#define SIM_SOPT5_UART0ODE(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0ODE_SHIFT))&SIM_SOPT5_UART0ODE_MASK) /**< SIM_SOPT5.UART0ODE Field                */
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
#define SIM_SCGC4_CMP0_MASK                      (0x80000U)                                          /**< SIM_SCGC4.CMP0 Mask                     */
#define SIM_SCGC4_CMP0_SHIFT                     (19U)                                               /**< SIM_SCGC4.CMP0 Position                 */
#define SIM_SCGC4_CMP0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_CMP0_SHIFT))&SIM_SCGC4_CMP0_MASK) /**< SIM_SCGC4.CMP0 Field                    */
#define SIM_SCGC4_SPI0_MASK                      (0x400000U)                                         /**< SIM_SCGC4.SPI0 Mask                     */
#define SIM_SCGC4_SPI0_SHIFT                     (22U)                                               /**< SIM_SCGC4.SPI0 Position                 */
#define SIM_SCGC4_SPI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_SPI0_SHIFT))&SIM_SCGC4_SPI0_MASK) /**< SIM_SCGC4.SPI0 Field                    */
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
/** @} */

/** @name SCGC6 - System Clock Gating Control Register 6 */ /** @{ */
#define SIM_SCGC6_FTF_MASK                       (0x1U)                                              /**< SIM_SCGC6.FTF Mask                      */
#define SIM_SCGC6_FTF_SHIFT                      (0U)                                                /**< SIM_SCGC6.FTF Position                  */
#define SIM_SCGC6_FTF(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTF_SHIFT))&SIM_SCGC6_FTF_MASK) /**< SIM_SCGC6.FTF Field                     */
#define SIM_SCGC6_TPM0_MASK                      (0x1000000U)                                        /**< SIM_SCGC6.TPM0 Mask                     */
#define SIM_SCGC6_TPM0_SHIFT                     (24U)                                               /**< SIM_SCGC6.TPM0 Position                 */
#define SIM_SCGC6_TPM0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TPM0_SHIFT))&SIM_SCGC6_TPM0_MASK) /**< SIM_SCGC6.TPM0 Field                    */
#define SIM_SCGC6_TPM1_MASK                      (0x2000000U)                                        /**< SIM_SCGC6.TPM1 Mask                     */
#define SIM_SCGC6_TPM1_SHIFT                     (25U)                                               /**< SIM_SCGC6.TPM1 Position                 */
#define SIM_SCGC6_TPM1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_TPM1_SHIFT))&SIM_SCGC6_TPM1_MASK) /**< SIM_SCGC6.TPM1 Field                    */
#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)                                        /**< SIM_SCGC6.ADC0 Mask                     */
#define SIM_SCGC6_ADC0_SHIFT                     (27U)                                               /**< SIM_SCGC6.ADC0 Position                 */
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC0_SHIFT))&SIM_SCGC6_ADC0_MASK) /**< SIM_SCGC6.ADC0 Field                    */
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

/** @name SRVCOP - Service COP */ /** @{ */
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
/* ================           SMC (file:SMC_MKL02Z4)               ================ */
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
/* ================           SPI0 (file:SPI0_MKE_8Bit)            ================ */
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
#define SPI_C2_BIDIROE_MASK                      (0x8U)                                              /**< SPI0_C2.BIDIROE Mask                    */
#define SPI_C2_BIDIROE_SHIFT                     (3U)                                                /**< SPI0_C2.BIDIROE Position                */
#define SPI_C2_BIDIROE(x)                        (((uint8_t)(((uint8_t)(x))<<SPI_C2_BIDIROE_SHIFT))&SPI_C2_BIDIROE_MASK) /**< SPI0_C2.BIDIROE Field                   */
#define SPI_C2_MODFEN_MASK                       (0x10U)                                             /**< SPI0_C2.MODFEN Mask                     */
#define SPI_C2_MODFEN_SHIFT                      (4U)                                                /**< SPI0_C2.MODFEN Position                 */
#define SPI_C2_MODFEN(x)                         (((uint8_t)(((uint8_t)(x))<<SPI_C2_MODFEN_SHIFT))&SPI_C2_MODFEN_MASK) /**< SPI0_C2.MODFEN Field                    */
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
/* ================           TPM0 (file:TPM0_2CH_NO_DMA)          ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module (2 channels)
 */
#define TPM_CONTROLS_COUNT   2          /**< Number of FTM channels                             */
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
   } CONTROLS[TPM_CONTROLS_COUNT];              /**< 000C: (cluster: size=0x0010, 16)                                   */
        uint8_t   RESERVED_1[52];               /**< 001C: 0x34 bytes                                                   */
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
/* ================           TPM1 (derived from TPM0)             ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module (2 channels)
 */

/* TPM1 - Peripheral instance base addresses */
#define TPM1_BasePtr                   0x40039000UL //!< Peripheral base address
#define TPM1                           ((TPM_Type *) TPM1_BasePtr) //!< Freescale base pointer
#define TPM1_BASE_PTR                  (TPM1) //!< Freescale style base pointer
#define TPM1_IRQS { TPM1_IRQn,  }


/** @} */ /* End group TPM_Peripheral_access_layer_GROUP */


/** @brief C Struct for UART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           UART0 (file:UART0_MKL02Z4)           ================ */
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
/** @} */

/** @} */ /* End group UART_Register_Masks_GROUP */


/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x4006A000UL //!< Peripheral base address
#define UART0                          ((UART_Type *) UART0_BasePtr) //!< Freescale base pointer
#define UART0_BASE_PTR                 (UART0) //!< Freescale style base pointer
#define UART0_IRQS { UART0_IRQn,  }


/** @} */ /* End group UART_Peripheral_access_layer_GROUP */

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


#endif  /* MCU_MKL02Z4 */

