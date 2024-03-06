/*!
 * @file     MKE02Z4.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKE02Z4.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2024/02
 *
 */

#ifndef _MKE02Z4_H_
#define _MKE02Z4_H_

#define MCU_MKE02Z4

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif


/** @brief Vector numbers required for NVIC functions */
/** @addtogroup Interrupt_vector_numbers_GROUP Interrupt vector numbers */
/** @{ */
#define NUMBER_OF_INT_VECTORS 45 //<! Number of vector table entries
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
/* ----------------------   MKE02Z2 VectorTable                      ---------------------- */
  FTMRH_IRQn                    =   5,   /**<  21 Flash Memory                                                                     */
  PMC_IRQn                      =   6,   /**<  22 Power Management Controller                                                      */
  IRQ_IRQn                      =   7,   /**<  23 External Interrupt                                                               */
  I2C0_IRQn                     =   8,   /**<  24 Inter-Integrated Circuit                                                         */
  SPI0_IRQn                     =  10,   /**<  26 Serial Peripheral Interface                                                      */
  SPI1_IRQn                     =  11,   /**<  27 Serial Peripheral Interface                                                      */
  UART0_IRQn                    =  12,   /**<  28 Serial Communication Interface                                                   */
  UART1_IRQn                    =  13,   /**<  29 Serial Communication Interface                                                   */
  UART2_IRQn                    =  14,   /**<  30 Serial Communication Interface                                                   */
  ADC0_IRQn                     =  15,   /**<  31 Analogue to Digital Converter                                                    */
  ACMP0_IRQn                    =  16,   /**<  32 Analogue comparator                                                              */
  FTM0_IRQn                     =  17,   /**<  33 FlexTimer Module                                                                 */
  FTM1_IRQn                     =  18,   /**<  34 FlexTimer Module                                                                 */
  FTM2_IRQn                     =  19,   /**<  35 FlexTimer Module                                                                 */
  RTC_Alarm_IRQn                =  20,   /**<  36 Real Time Clock                                                                  */
  ACMP1_IRQn                    =  21,   /**<  37 Analogue comparator                                                              */
  PIT_Ch0_IRQn                  =  22,   /**<  38 Periodic Interrupt Timer                                                         */
  PIT_Ch1_IRQn                  =  23,   /**<  39 Periodic Interrupt Timer                                                         */
  KBI0_IRQn                     =  24,   /**<  40 Keyboard Interrupt                                                               */
  KBI1_IRQn                     =  25,   /**<  41 Keyboard Interrupt                                                               */
  ICS_IRQn                      =  27,   /**<  43 Clock Management                                                                 */
  WDOG_IRQn                     =  28,   /**<  44 Watchdog Timer                                                                   */
} IRQn_Type;


/** @brief Prototypes for interrupt handlers */
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                       /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);                 /**< Hard Fault, all classes of Fault                                                 */
extern void SVC_Handler(void);                       /**< System Service Call via SVC instruction                                          */
extern void PendSV_Handler(void);                    /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);                   /**< System Tick Timer                                                                */
extern void FTMRH_IRQHandler(void);                  /**< Flash Memory                                                                     */
extern void PMC_IRQHandler(void);                    /**< Power Management Controller                                                      */
extern void IRQ_IRQHandler(void);                    /**< External Interrupt                                                               */
extern void I2C0_IRQHandler(void);                   /**< Inter-Integrated Circuit                                                         */
extern void SPI0_IRQHandler(void);                   /**< Serial Peripheral Interface                                                      */
extern void SPI1_IRQHandler(void);                   /**< Serial Peripheral Interface                                                      */
extern void UART0_IRQHandler(void);                  /**< Serial Communication Interface                                                   */
extern void UART1_IRQHandler(void);                  /**< Serial Communication Interface                                                   */
extern void UART2_IRQHandler(void);                  /**< Serial Communication Interface                                                   */
extern void ADC0_IRQHandler(void);                   /**< Analogue to Digital Converter                                                    */
extern void ACMP0_IRQHandler(void);                  /**< Analogue comparator                                                              */
extern void FTM0_IRQHandler(void);                   /**< FlexTimer Module                                                                 */
extern void FTM1_IRQHandler(void);                   /**< FlexTimer Module                                                                 */
extern void FTM2_IRQHandler(void);                   /**< FlexTimer Module                                                                 */
extern void RTC_Alarm_IRQHandler(void);              /**< Real Time Clock                                                                  */
extern void ACMP1_IRQHandler(void);                  /**< Analogue comparator                                                              */
extern void PIT_Ch0_IRQHandler(void);                /**< Periodic Interrupt Timer                                                         */
extern void PIT_Ch1_IRQHandler(void);                /**< Periodic Interrupt Timer                                                         */
extern void KBI0_IRQHandler(void);                   /**< Keyboard Interrupt                                                               */
extern void KBI1_IRQHandler(void);                   /**< Keyboard Interrupt                                                               */
extern void ICS_IRQHandler(void);                    /**< Clock Management                                                                 */
extern void WDOG_IRQHandler(void);                   /**< Watchdog Timer                                                                   */


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

/** @brief C Struct for ACMP */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup ACMP_Peripheral_access_layer_GROUP ACMP Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           ACMP0 (file:ACMP0_MKE)               ================ */
/* ================================================================================ */

/**
 * @brief Analog comparator
 */
/**
 * @struct ACMP_Type
 * @brief  C Struct allowing access to ACMP registers
 */
typedef struct ACMP_Type {
   __IO uint8_t   CS;                           /**< 0000: ACMP Control and Status Register                             */
   __IO uint8_t   C0;                           /**< 0001: ACMP Control Register 0                                      */
   __IO uint8_t   C1;                           /**< 0002: ACMP Control Register 1                                      */
   __IO uint8_t   C2;                           /**< 0003: ACMP Control Register 2                                      */
} ACMP_Type;


/** @brief Register Masks for ACMP */

/* -------------------------------------------------------------------------------- */
/* -----------     'ACMP0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup ACMP_Register_Masks_GROUP ACMP Register Masks */
/** @{ */

/** @name CS - ACMP Control and Status Register */ /** @{ */
#define ACMP_CS_ACMOD_MASK                       (0x3U)                                              /**< ACMP0_CS.ACMOD Mask                     */
#define ACMP_CS_ACMOD_SHIFT                      (0U)                                                /**< ACMP0_CS.ACMOD Position                 */
#define ACMP_CS_ACMOD(x)                         (((uint8_t)(((uint8_t)(x))<<ACMP_CS_ACMOD_SHIFT))&ACMP_CS_ACMOD_MASK) /**< ACMP0_CS.ACMOD Field                    */
#define ACMP_CS_ACOPE_MASK                       (0x4U)                                              /**< ACMP0_CS.ACOPE Mask                     */
#define ACMP_CS_ACOPE_SHIFT                      (2U)                                                /**< ACMP0_CS.ACOPE Position                 */
#define ACMP_CS_ACOPE(x)                         (((uint8_t)(((uint8_t)(x))<<ACMP_CS_ACOPE_SHIFT))&ACMP_CS_ACOPE_MASK) /**< ACMP0_CS.ACOPE Field                    */
#define ACMP_CS_ACO_MASK                         (0x8U)                                              /**< ACMP0_CS.ACO Mask                       */
#define ACMP_CS_ACO_SHIFT                        (3U)                                                /**< ACMP0_CS.ACO Position                   */
#define ACMP_CS_ACO(x)                           (((uint8_t)(((uint8_t)(x))<<ACMP_CS_ACO_SHIFT))&ACMP_CS_ACO_MASK) /**< ACMP0_CS.ACO Field                      */
#define ACMP_CS_ACIE_MASK                        (0x10U)                                             /**< ACMP0_CS.ACIE Mask                      */
#define ACMP_CS_ACIE_SHIFT                       (4U)                                                /**< ACMP0_CS.ACIE Position                  */
#define ACMP_CS_ACIE(x)                          (((uint8_t)(((uint8_t)(x))<<ACMP_CS_ACIE_SHIFT))&ACMP_CS_ACIE_MASK) /**< ACMP0_CS.ACIE Field                     */
#define ACMP_CS_ACF_MASK                         (0x20U)                                             /**< ACMP0_CS.ACF Mask                       */
#define ACMP_CS_ACF_SHIFT                        (5U)                                                /**< ACMP0_CS.ACF Position                   */
#define ACMP_CS_ACF(x)                           (((uint8_t)(((uint8_t)(x))<<ACMP_CS_ACF_SHIFT))&ACMP_CS_ACF_MASK) /**< ACMP0_CS.ACF Field                      */
#define ACMP_CS_HYST_MASK                        (0x40U)                                             /**< ACMP0_CS.HYST Mask                      */
#define ACMP_CS_HYST_SHIFT                       (6U)                                                /**< ACMP0_CS.HYST Position                  */
#define ACMP_CS_HYST(x)                          (((uint8_t)(((uint8_t)(x))<<ACMP_CS_HYST_SHIFT))&ACMP_CS_HYST_MASK) /**< ACMP0_CS.HYST Field                     */
#define ACMP_CS_ACE_MASK                         (0x80U)                                             /**< ACMP0_CS.ACE Mask                       */
#define ACMP_CS_ACE_SHIFT                        (7U)                                                /**< ACMP0_CS.ACE Position                   */
#define ACMP_CS_ACE(x)                           (((uint8_t)(((uint8_t)(x))<<ACMP_CS_ACE_SHIFT))&ACMP_CS_ACE_MASK) /**< ACMP0_CS.ACE Field                      */
/** @} */

/** @name C0 - ACMP Control Register 0 */ /** @{ */
#define ACMP_C0_ACNSEL_MASK                      (0x3U)                                              /**< ACMP0_C0.ACNSEL Mask                    */
#define ACMP_C0_ACNSEL_SHIFT                     (0U)                                                /**< ACMP0_C0.ACNSEL Position                */
#define ACMP_C0_ACNSEL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C0_ACNSEL_SHIFT))&ACMP_C0_ACNSEL_MASK) /**< ACMP0_C0.ACNSEL Field                   */
#define ACMP_C0_ACPSEL_MASK                      (0x30U)                                             /**< ACMP0_C0.ACPSEL Mask                    */
#define ACMP_C0_ACPSEL_SHIFT                     (4U)                                                /**< ACMP0_C0.ACPSEL Position                */
#define ACMP_C0_ACPSEL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C0_ACPSEL_SHIFT))&ACMP_C0_ACPSEL_MASK) /**< ACMP0_C0.ACPSEL Field                   */
/** @} */

/** @name C1 - ACMP Control Register 1 */ /** @{ */
#define ACMP_C1_DACVAL_MASK                      (0x3FU)                                             /**< ACMP0_C1.DACVAL Mask                    */
#define ACMP_C1_DACVAL_SHIFT                     (0U)                                                /**< ACMP0_C1.DACVAL Position                */
#define ACMP_C1_DACVAL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C1_DACVAL_SHIFT))&ACMP_C1_DACVAL_MASK) /**< ACMP0_C1.DACVAL Field                   */
#define ACMP_C1_DACREF_MASK                      (0x40U)                                             /**< ACMP0_C1.DACREF Mask                    */
#define ACMP_C1_DACREF_SHIFT                     (6U)                                                /**< ACMP0_C1.DACREF Position                */
#define ACMP_C1_DACREF(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C1_DACREF_SHIFT))&ACMP_C1_DACREF_MASK) /**< ACMP0_C1.DACREF Field                   */
#define ACMP_C1_DACEN_MASK                       (0x80U)                                             /**< ACMP0_C1.DACEN Mask                     */
#define ACMP_C1_DACEN_SHIFT                      (7U)                                                /**< ACMP0_C1.DACEN Position                 */
#define ACMP_C1_DACEN(x)                         (((uint8_t)(((uint8_t)(x))<<ACMP_C1_DACEN_SHIFT))&ACMP_C1_DACEN_MASK) /**< ACMP0_C1.DACEN Field                    */
/** @} */

/** @name C2 - ACMP Control Register 2 */ /** @{ */
#define ACMP_C2_ACIPE_MASK                       (0x7U)                                              /**< ACMP0_C2.ACIPE Mask                     */
#define ACMP_C2_ACIPE_SHIFT                      (0U)                                                /**< ACMP0_C2.ACIPE Position                 */
#define ACMP_C2_ACIPE(x)                         (((uint8_t)(((uint8_t)(x))<<ACMP_C2_ACIPE_SHIFT))&ACMP_C2_ACIPE_MASK) /**< ACMP0_C2.ACIPE Field                    */
/** @} */

/** @} */ /* End group ACMP_Register_Masks_GROUP */


/* ACMP0 - Peripheral instance base addresses */
#define ACMP0_BasePtr                  0x40073000UL //!< Peripheral base address
#define ACMP0                          ((ACMP_Type *) ACMP0_BasePtr) //!< Freescale base pointer
#define ACMP0_BASE_PTR                 (ACMP0) //!< Freescale style base pointer
#define ACMP0_IRQS { ACMP0_IRQn,  }


/** @} */ /* End group ACMP_Peripheral_access_layer_GROUP */


/** @brief C Struct for ACMP */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup ACMP_Peripheral_access_layer_GROUP ACMP Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           ACMP1 (derived from ACMP0)           ================ */
/* ================================================================================ */

/**
 * @brief Analog comparator
 */

/* ACMP1 - Peripheral instance base addresses */
#define ACMP1_BasePtr                  0x40074000UL //!< Peripheral base address
#define ACMP1                          ((ACMP_Type *) ACMP1_BasePtr) //!< Freescale base pointer
#define ACMP1_BASE_PTR                 (ACMP1) //!< Freescale style base pointer
#define ACMP1_IRQS { ACMP1_IRQn,  }


/** @} */ /* End group ACMP_Peripheral_access_layer_GROUP */


/** @brief C Struct for ADC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           ADC0 (file:ADC0_MKE02)               ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */
#define ADC_SC1_COUNT        1          /**< Number of ADC channels                             */
/**
 * @struct ADC_Type
 * @brief  C Struct allowing access to ADC registers
 */
typedef struct ADC_Type {
   __IO uint32_t  SC1[ADC_SC1_COUNT];           /**< 0000: Status and Control Register 1                                */
   __IO uint32_t  SC2;                          /**< 0004: Status and Control Register 2                                */
   __IO uint32_t  SC3;                          /**< 0008: Status and Control Register 3                                */
   __IO uint32_t  SC4;                          /**< 000C: Status and Control Register 4                                */
   __I  uint32_t  R[ADC_SC1_COUNT];             /**< 0010: Data Result Register                                         */
   __IO uint32_t  CV;                           /**< 0014: Compare Value Register                                       */
   __IO uint32_t  APCTL1;                       /**< 0018: Pin Control 1 Register                                       */
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
#define ADC_SC1_ADCO_MASK                        (0x20U)                                             /**< ADC0_SC1.ADCO Mask                      */
#define ADC_SC1_ADCO_SHIFT                       (5U)                                                /**< ADC0_SC1.ADCO Position                  */
#define ADC_SC1_ADCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCO_SHIFT))&ADC_SC1_ADCO_MASK) /**< ADC0_SC1.ADCO Field                     */
#define ADC_SC1_AIEN_MASK                        (0x40U)                                             /**< ADC0_SC1.AIEN Mask                      */
#define ADC_SC1_AIEN_SHIFT                       (6U)                                                /**< ADC0_SC1.AIEN Position                  */
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_AIEN_SHIFT))&ADC_SC1_AIEN_MASK) /**< ADC0_SC1.AIEN Field                     */
#define ADC_SC1_COCO_MASK                        (0x80U)                                             /**< ADC0_SC1.COCO Mask                      */
#define ADC_SC1_COCO_SHIFT                       (7U)                                                /**< ADC0_SC1.COCO Position                  */
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_COCO_SHIFT))&ADC_SC1_COCO_MASK) /**< ADC0_SC1.COCO Field                     */
/** @} */

/** @name SC2 - Status and Control Register 2 */ /** @{ */
#define ADC_SC2_REFSEL_MASK                      (0x3U)                                              /**< ADC0_SC2.REFSEL Mask                    */
#define ADC_SC2_REFSEL_SHIFT                     (0U)                                                /**< ADC0_SC2.REFSEL Position                */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK) /**< ADC0_SC2.REFSEL Field                   */
#define ADC_SC2_FFULL_MASK                       (0x4U)                                              /**< ADC0_SC2.FFULL Mask                     */
#define ADC_SC2_FFULL_SHIFT                      (2U)                                                /**< ADC0_SC2.FFULL Position                 */
#define ADC_SC2_FFULL(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_FFULL_SHIFT))&ADC_SC2_FFULL_MASK) /**< ADC0_SC2.FFULL Field                    */
#define ADC_SC2_FEMPTY_MASK                      (0x8U)                                              /**< ADC0_SC2.FEMPTY Mask                    */
#define ADC_SC2_FEMPTY_SHIFT                     (3U)                                                /**< ADC0_SC2.FEMPTY Position                */
#define ADC_SC2_FEMPTY(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_FEMPTY_SHIFT))&ADC_SC2_FEMPTY_MASK) /**< ADC0_SC2.FEMPTY Field                   */
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
#define ADC_SC3_ADICLK_MASK                      (0x3U)                                              /**< ADC0_SC3.ADICLK Mask                    */
#define ADC_SC3_ADICLK_SHIFT                     (0U)                                                /**< ADC0_SC3.ADICLK Position                */
#define ADC_SC3_ADICLK(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADICLK_SHIFT))&ADC_SC3_ADICLK_MASK) /**< ADC0_SC3.ADICLK Field                   */
#define ADC_SC3_MODE_MASK                        (0xCU)                                              /**< ADC0_SC3.MODE Mask                      */
#define ADC_SC3_MODE_SHIFT                       (2U)                                                /**< ADC0_SC3.MODE Position                  */
#define ADC_SC3_MODE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_MODE_SHIFT))&ADC_SC3_MODE_MASK) /**< ADC0_SC3.MODE Field                     */
#define ADC_SC3_ADLSMP_MASK                      (0x10U)                                             /**< ADC0_SC3.ADLSMP Mask                    */
#define ADC_SC3_ADLSMP_SHIFT                     (4U)                                                /**< ADC0_SC3.ADLSMP Position                */
#define ADC_SC3_ADLSMP(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADLSMP_SHIFT))&ADC_SC3_ADLSMP_MASK) /**< ADC0_SC3.ADLSMP Field                   */
#define ADC_SC3_ADIV_MASK                        (0x60U)                                             /**< ADC0_SC3.ADIV Mask                      */
#define ADC_SC3_ADIV_SHIFT                       (5U)                                                /**< ADC0_SC3.ADIV Position                  */
#define ADC_SC3_ADIV(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADIV_SHIFT))&ADC_SC3_ADIV_MASK) /**< ADC0_SC3.ADIV Field                     */
#define ADC_SC3_ADLPC_MASK                       (0x80U)                                             /**< ADC0_SC3.ADLPC Mask                     */
#define ADC_SC3_ADLPC_SHIFT                      (7U)                                                /**< ADC0_SC3.ADLPC Position                 */
#define ADC_SC3_ADLPC(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADLPC_SHIFT))&ADC_SC3_ADLPC_MASK) /**< ADC0_SC3.ADLPC Field                    */
/** @} */

/** @name SC4 - Status and Control Register 4 */ /** @{ */
#define ADC_SC4_AFDEP_MASK                       (0x7U)                                              /**< ADC0_SC4.AFDEP Mask                     */
#define ADC_SC4_AFDEP_SHIFT                      (0U)                                                /**< ADC0_SC4.AFDEP Position                 */
#define ADC_SC4_AFDEP(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC4_AFDEP_SHIFT))&ADC_SC4_AFDEP_MASK) /**< ADC0_SC4.AFDEP Field                    */
#define ADC_SC4_ACFSEL_MASK                      (0x20U)                                             /**< ADC0_SC4.ACFSEL Mask                    */
#define ADC_SC4_ACFSEL_SHIFT                     (5U)                                                /**< ADC0_SC4.ACFSEL Position                */
#define ADC_SC4_ACFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC4_ACFSEL_SHIFT))&ADC_SC4_ACFSEL_MASK) /**< ADC0_SC4.ACFSEL Field                   */
#define ADC_SC4_ASCANE_MASK                      (0x40U)                                             /**< ADC0_SC4.ASCANE Mask                    */
#define ADC_SC4_ASCANE_SHIFT                     (6U)                                                /**< ADC0_SC4.ASCANE Position                */
#define ADC_SC4_ASCANE(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC4_ASCANE_SHIFT))&ADC_SC4_ASCANE_MASK) /**< ADC0_SC4.ASCANE Field                   */
/** @} */

/** @name R - Data Result Register */ /** @{ */
#define ADC_R_D_MASK                             (0xFFFU)                                            /**< ADC0_R.D Mask                           */
#define ADC_R_D_SHIFT                            (0U)                                                /**< ADC0_R.D Position                       */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK) /**< ADC0_R.D Field                          */
/** @} */

/** @name CV - Compare Value Register */ /** @{ */
#define ADC_CV_CV_MASK                           (0xFFFU)                                            /**< ADC0_CV.CV Mask                         */
#define ADC_CV_CV_SHIFT                          (0U)                                                /**< ADC0_CV.CV Position                     */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK) /**< ADC0_CV.CV Field                        */
/** @} */

/** @name APCTL1 - Pin Control 1 Register */ /** @{ */
#define ADC_APCTL1_ADPC_MASK                     (0xFFFFU)                                           /**< ADC0_APCTL1.ADPC Mask                   */
#define ADC_APCTL1_ADPC_SHIFT                    (0U)                                                /**< ADC0_APCTL1.ADPC Position               */
#define ADC_APCTL1_ADPC(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_APCTL1_ADPC_SHIFT))&ADC_APCTL1_ADPC_MASK) /**< ADC0_APCTL1.ADPC Field                  */
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


/** @brief C Struct for FGPIOA */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIOA_Peripheral_access_layer_GROUP FGPIOA Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FGPIOA (file:FGPIOA_MKE)             ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
 * @struct GPIO_Type
 * @brief  C Struct allowing access to FGPIOA registers
 */
typedef struct GPIO_Type {
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  PDOR;                      /**< 0000: Port Data Output Register                                    */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint8_t   PDORA;                  /**< 0000: Port Data Output Register                                    */
         __IO uint8_t   PDORB;                  /**< 0001: Port Data Output Register                                    */
         __IO uint8_t   PDORC;                  /**< 0002: Port Data Output Register                                    */
         __IO uint8_t   PDORD;                  /**< 0003: Port Data Output Register                                    */
      };
   };
   union {                                      /**< 0004: (size=0004)                                                  */
      __O  uint32_t  PSOR;                      /**< 0004: Port Set Output Register                                     */
      struct {                                  /**< 0004: (size=0004)                                                  */
         __O  uint8_t   PSORA;                  /**< 0004: Port Set Output Register                                     */
         __O  uint8_t   PSORB;                  /**< 0005: Port Set Output Register                                     */
         __O  uint8_t   PSORC;                  /**< 0006: Port Set Output Register                                     */
         __O  uint8_t   PSORD;                  /**< 0007: Port Set Output Register                                     */
      };
   };
   union {                                      /**< 0008: (size=0004)                                                  */
      __O  uint32_t  PCOR;                      /**< 0008: Port Clear Output Register                                   */
      struct {                                  /**< 0008: (size=0004)                                                  */
         __O  uint8_t   PCORA;                  /**< 0008: Port Clear Output Register                                   */
         __O  uint8_t   PCORB;                  /**< 0009: Port Clear Output Register                                   */
         __O  uint8_t   PCORC;                  /**< 000A: Port Clear Output Register                                   */
         __O  uint8_t   PCORD;                  /**< 000B: Port Clear Output Register                                   */
      };
   };
   union {                                      /**< 000C: (size=0004)                                                  */
      __O  uint32_t  PTOR;                      /**< 000C: Port Toggle Output Register                                  */
      struct {                                  /**< 000C: (size=0004)                                                  */
         __O  uint8_t   PTORA;                  /**< 000C: Port Toggle Output Register                                  */
         __O  uint8_t   PTORB;                  /**< 000D: Port Toggle Output Register                                  */
         __O  uint8_t   PTORC;                  /**< 000E: Port Toggle Output Register                                  */
         __O  uint8_t   PTORD;                  /**< 000F: Port Toggle Output Register                                  */
      };
   };
   union {                                      /**< 0010: (size=0004)                                                  */
      __I  uint32_t  PDIR;                      /**< 0010: Port Data Input Register                                     */
      struct {                                  /**< 0010: (size=0004)                                                  */
         __I  uint8_t   PDIRA;                  /**< 0010: Port Data Input Register                                     */
         __I  uint8_t   PDIRB;                  /**< 0011: Port Data Input Register                                     */
         __I  uint8_t   PDIRC;                  /**< 0012: Port Data Input Register                                     */
         __I  uint8_t   PDIRD;                  /**< 0013: Port Data Input Register                                     */
      };
   };
   union {                                      /**< 0014: (size=0004)                                                  */
      __IO uint32_t  PDDR;                      /**< 0014: Port Data Direction Register                                 */
      struct {                                  /**< 0014: (size=0004)                                                  */
         __IO uint8_t   PDDRA;                  /**< 0014: Port Data Direction Register                                 */
         __IO uint8_t   PDDRB;                  /**< 0015: Port Data Direction Register                                 */
         __IO uint8_t   PDDRC;                  /**< 0016: Port Data Direction Register                                 */
         __IO uint8_t   PDDRD;                  /**< 0017: Port Data Direction Register                                 */
      };
   };
   union {                                      /**< 0018: (size=0004)                                                  */
      __IO uint32_t  PIDR;                      /**< 0018: Port Input Disable Register                                  */
      struct {                                  /**< 0018: (size=0004)                                                  */
         __IO uint8_t   PIDRA;                  /**< 0018: Port Input Disable Register                                  */
         __IO uint8_t   PIDRB;                  /**< 0019: Port Input Disable Register                                  */
         __IO uint8_t   PIDRC;                  /**< 001A: Port Input Disable Register                                  */
         __IO uint8_t   PIDRD;                  /**< 001B: Port Input Disable Register                                  */
      };
   };
} GPIO_Type;


/** @brief Register Masks for FGPIOA */

/* -------------------------------------------------------------------------------- */
/* -----------     'FGPIOA' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FGPIOA_Register_Masks_GROUP FGPIOA Register Masks */
/** @{ */

/** @} */ /* End group FGPIOA_Register_Masks_GROUP */


/* FGPIOA - Peripheral instance base addresses */
#define FGPIOA_BasePtr                 0xF8000000UL //!< Peripheral base address
#define FGPIOA                         ((GPIO_Type *) FGPIOA_BasePtr) //!< Freescale base pointer
#define FGPIOA_BASE_PTR                (FGPIOA) //!< Freescale style base pointer

/** @} */ /* End group FGPIOA_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIOB */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIOB_Peripheral_access_layer_GROUP FGPIOB Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FGPIOB (file:FGPIOB_MKE)             ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
 * @struct FGPIOB_Type
 * @brief  C Struct allowing access to FGPIOB registers
 */
typedef struct FGPIOB_Type {
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  PDOR;                      /**< 0000: Port Data Output Register                                    */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint8_t   PDORE;                  /**< 0000: Port Data Output Register                                    */
         __IO uint8_t   PDORF;                  /**< 0001: Port Data Output Register                                    */
         __IO uint8_t   PDORG;                  /**< 0002: Port Data Output Register                                    */
         __IO uint8_t   PDORH;                  /**< 0003: Port Data Output Register                                    */
      };
   };
   union {                                      /**< 0004: (size=0004)                                                  */
      __O  uint32_t  PSOR;                      /**< 0004: Port Set Output Register                                     */
      struct {                                  /**< 0004: (size=0004)                                                  */
         __O  uint8_t   PSORE;                  /**< 0004: Port Set Output Register                                     */
         __O  uint8_t   PSORF;                  /**< 0005: Port Set Output Register                                     */
         __O  uint8_t   PSORG;                  /**< 0006: Port Set Output Register                                     */
         __O  uint8_t   PSORH;                  /**< 0007: Port Set Output Register                                     */
      };
   };
   union {                                      /**< 0008: (size=0004)                                                  */
      __O  uint32_t  PCOR;                      /**< 0008: Port Clear Output Register                                   */
      struct {                                  /**< 0008: (size=0004)                                                  */
         __O  uint8_t   PCORE;                  /**< 0008: Port Clear Output Register                                   */
         __O  uint8_t   PCORF;                  /**< 0009: Port Clear Output Register                                   */
         __O  uint8_t   PCORG;                  /**< 000A: Port Clear Output Register                                   */
         __O  uint8_t   PCORH;                  /**< 000B: Port Clear Output Register                                   */
      };
   };
   union {                                      /**< 000C: (size=0004)                                                  */
      __O  uint32_t  PTOR;                      /**< 000C: Port Toggle Output Register                                  */
      struct {                                  /**< 000C: (size=0004)                                                  */
         __O  uint8_t   PTORE;                  /**< 000C: Port Toggle Output Register                                  */
         __O  uint8_t   PTORF;                  /**< 000D: Port Toggle Output Register                                  */
         __O  uint8_t   PTORG;                  /**< 000E: Port Toggle Output Register                                  */
         __O  uint8_t   PTORH;                  /**< 000F: Port Toggle Output Register                                  */
      };
   };
   union {                                      /**< 0010: (size=0004)                                                  */
      __I  uint32_t  PDIR;                      /**< 0010: Port Data Input Register                                     */
      struct {                                  /**< 0010: (size=0004)                                                  */
         __I  uint8_t   PDIRE;                  /**< 0010: Port Data Input Register                                     */
         __I  uint8_t   PDIRF;                  /**< 0011: Port Data Input Register                                     */
         __I  uint8_t   PDIRG;                  /**< 0012: Port Data Input Register                                     */
         __I  uint8_t   PDIRH;                  /**< 0013: Port Data Input Register                                     */
      };
   };
   union {                                      /**< 0014: (size=0004)                                                  */
      __IO uint32_t  PDDR;                      /**< 0014: Port Data Direction Register                                 */
      struct {                                  /**< 0014: (size=0004)                                                  */
         __IO uint8_t   PDDRE;                  /**< 0014: Port Data Direction Register                                 */
         __IO uint8_t   PDDRF;                  /**< 0015: Port Data Direction Register                                 */
         __IO uint8_t   PDDRG;                  /**< 0016: Port Data Direction Register                                 */
         __IO uint8_t   PDDRH;                  /**< 0017: Port Data Direction Register                                 */
      };
   };
   union {                                      /**< 0018: (size=0004)                                                  */
      __IO uint32_t  PIDR;                      /**< 0018: Port Input Disable Register                                  */
      struct {                                  /**< 0018: (size=0004)                                                  */
         __IO uint8_t   PIDRE;                  /**< 0018: Port Input Disable Register                                  */
         __IO uint8_t   PIDRF;                  /**< 0019: Port Input Disable Register                                  */
         __IO uint8_t   PIDRG;                  /**< 001A: Port Input Disable Register                                  */
         __IO uint8_t   PIDRH;                  /**< 001B: Port Input Disable Register                                  */
      };
   };
} FGPIOB_Type;


/** @brief Register Masks for FGPIOB */

/* -------------------------------------------------------------------------------- */
/* -----------     'FGPIOB' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FGPIOB_Register_Masks_GROUP FGPIOB Register Masks */
/** @{ */

/** @} */ /* End group FGPIOB_Register_Masks_GROUP */


/* FGPIOB - Peripheral instance base addresses */
#define FGPIOB_BasePtr                 0xF8000040UL //!< Peripheral base address
#define FGPIOB                         ((FGPIOB_Type *) FGPIOB_BasePtr) //!< Freescale base pointer
#define FGPIOB_BASE_PTR                (FGPIOB) //!< Freescale style base pointer

/** @} */ /* End group FGPIOB_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIOC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIOC_Peripheral_access_layer_GROUP FGPIOC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FGPIOC (file:FGPIOC_MKE)             ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
 * @struct FGPIOC_Type
 * @brief  C Struct allowing access to FGPIOC registers
 */
typedef struct FGPIOC_Type {
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  PDOR;                      /**< 0000: Port Data Output Register                                    */
      __IO uint8_t   PDORI;                     /**< 0000: Port Data Output Register                                    */
   };
   union {                                      /**< 0004: (size=0004)                                                  */
      __O  uint32_t  PSOR;                      /**< 0004: Port Set Output Register                                     */
      __O  uint8_t   PSORI;                     /**< 0004: Port Set Output Register                                     */
   };
   union {                                      /**< 0008: (size=0004)                                                  */
      __O  uint32_t  PCOR;                      /**< 0008: Port Clear Output Register                                   */
      __O  uint8_t   PCORI;                     /**< 0008: Port Clear Output Register                                   */
   };
   union {                                      /**< 000C: (size=0004)                                                  */
      __O  uint32_t  PTOR;                      /**< 000C: Port Toggle Output Register                                  */
      __O  uint8_t   PTORI;                     /**< 000C: Port Toggle Output Register                                  */
   };
   union {                                      /**< 0010: (size=0004)                                                  */
      __I  uint32_t  PDIR;                      /**< 0010: Port Data Input Register                                     */
      __I  uint8_t   PDIRI;                     /**< 0010: Port Data Input Register                                     */
   };
   union {                                      /**< 0014: (size=0004)                                                  */
      __IO uint32_t  PDDR;                      /**< 0014: Port Data Direction Register                                 */
      __IO uint8_t   PDDRI;                     /**< 0014: Port Data Direction Register                                 */
   };
   union {                                      /**< 0018: (size=0004)                                                  */
      __IO uint32_t  PIDR;                      /**< 0018: Port Input Disable Register                                  */
      __IO uint8_t   PIDRI;                     /**< 0018: Port Input Disable Register                                  */
   };
} FGPIOC_Type;


/** @brief Register Masks for FGPIOC */

/* -------------------------------------------------------------------------------- */
/* -----------     'FGPIOC' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FGPIOC_Register_Masks_GROUP FGPIOC Register Masks */
/** @{ */

/** @} */ /* End group FGPIOC_Register_Masks_GROUP */


/* FGPIOC - Peripheral instance base addresses */
#define FGPIOC_BasePtr                 0xF8000000UL //!< Peripheral base address
#define FGPIOC                         ((FGPIOC_Type *) FGPIOC_BasePtr) //!< Freescale base pointer
#define FGPIOC_BASE_PTR                (FGPIOC) //!< Freescale style base pointer

/** @} */ /* End group FGPIOC_Peripheral_access_layer_GROUP */


/** @brief C Struct for FTM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FTM0 (file:FTM0_2CH_MKE)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */
#define FTM0_CONTROLS_COUNT  2          /**< Number of FTM channels                             */
/**
 * @struct FTM0_Type
 * @brief  C Struct allowing access to FTM registers
 */
typedef struct FTM0_Type {
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[FTM0_CONTROLS_COUNT];             /**< 000C: (cluster: size=0x0010, 16)                                   */
} FTM0_Type;


/** @brief Register Masks for FTM */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FTM_Register_Masks_GROUP FTM Register Masks */
/** @{ */

/** @name SC - Status and Control */ /** @{ */
#define FTM_SC_PS_MASK                           (0x7U)                                              /**< FTM0_SC.PS Mask                         */
#define FTM_SC_PS_SHIFT                          (0U)                                                /**< FTM0_SC.PS Position                     */
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK) /**< FTM0_SC.PS Field                        */
#define FTM_SC_CLKS_MASK                         (0x18U)                                             /**< FTM0_SC.CLKS Mask                       */
#define FTM_SC_CLKS_SHIFT                        (3U)                                                /**< FTM0_SC.CLKS Position                   */
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK) /**< FTM0_SC.CLKS Field                      */
#define FTM_SC_CPWMS_MASK                        (0x20U)                                             /**< FTM0_SC.CPWMS Mask                      */
#define FTM_SC_CPWMS_SHIFT                       (5U)                                                /**< FTM0_SC.CPWMS Position                  */
#define FTM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_SC_CPWMS_SHIFT))&FTM_SC_CPWMS_MASK) /**< FTM0_SC.CPWMS Field                     */
#define FTM_SC_TOIE_MASK                         (0x40U)                                             /**< FTM0_SC.TOIE Mask                       */
#define FTM_SC_TOIE_SHIFT                        (6U)                                                /**< FTM0_SC.TOIE Position                   */
#define FTM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOIE_SHIFT))&FTM_SC_TOIE_MASK) /**< FTM0_SC.TOIE Field                      */
#define FTM_SC_TOF_MASK                          (0x80U)                                             /**< FTM0_SC.TOF Mask                        */
#define FTM_SC_TOF_SHIFT                         (7U)                                                /**< FTM0_SC.TOF Position                    */
#define FTM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOF_SHIFT))&FTM_SC_TOF_MASK) /**< FTM0_SC.TOF Field                       */
/** @} */

/** @name CNT - Counter */ /** @{ */
#define FTM_CNT_COUNT_MASK                       (0xFFFFU)                                           /**< FTM0_CNT.COUNT Mask                     */
#define FTM_CNT_COUNT_SHIFT                      (0U)                                                /**< FTM0_CNT.COUNT Position                 */
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK) /**< FTM0_CNT.COUNT Field                    */
/** @} */

/** @name MOD - Modulo */ /** @{ */
#define FTM_MOD_MOD_MASK                         (0xFFFFU)                                           /**< FTM0_MOD.MOD Mask                       */
#define FTM_MOD_MOD_SHIFT                        (0U)                                                /**< FTM0_MOD.MOD Position                   */
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK) /**< FTM0_MOD.MOD Field                      */
/** @} */

/** @name CnSC - Channel %s Status and Control */ /** @{ */
#define FTM_CnSC_ELS_MASK                        (0xCU)                                              /**< FTM0_CnSC.ELS Mask                      */
#define FTM_CnSC_ELS_SHIFT                       (2U)                                                /**< FTM0_CnSC.ELS Position                  */
#define FTM_CnSC_ELS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELS_SHIFT))&FTM_CnSC_ELS_MASK) /**< FTM0_CnSC.ELS Field                     */
#define FTM_CnSC_ELSA_MASK                       (0x4U)                                              /**< FTM0_CnSC.ELSA Mask                     */
#define FTM_CnSC_ELSA_SHIFT                      (2U)                                                /**< FTM0_CnSC.ELSA Position                 */
#define FTM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSA_SHIFT))&FTM_CnSC_ELSA_MASK) /**< FTM0_CnSC.ELSA Field                    */
#define FTM_CnSC_ELSB_MASK                       (0x8U)                                              /**< FTM0_CnSC.ELSB Mask                     */
#define FTM_CnSC_ELSB_SHIFT                      (3U)                                                /**< FTM0_CnSC.ELSB Position                 */
#define FTM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSB_SHIFT))&FTM_CnSC_ELSB_MASK) /**< FTM0_CnSC.ELSB Field                    */
#define FTM_CnSC_MS_MASK                         (0x30U)                                             /**< FTM0_CnSC.MS Mask                       */
#define FTM_CnSC_MS_SHIFT                        (4U)                                                /**< FTM0_CnSC.MS Position                   */
#define FTM_CnSC_MS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MS_SHIFT))&FTM_CnSC_MS_MASK) /**< FTM0_CnSC.MS Field                      */
#define FTM_CnSC_MSA_MASK                        (0x10U)                                             /**< FTM0_CnSC.MSA Mask                      */
#define FTM_CnSC_MSA_SHIFT                       (4U)                                                /**< FTM0_CnSC.MSA Position                  */
#define FTM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSA_SHIFT))&FTM_CnSC_MSA_MASK) /**< FTM0_CnSC.MSA Field                     */
#define FTM_CnSC_MSB_MASK                        (0x20U)                                             /**< FTM0_CnSC.MSB Mask                      */
#define FTM_CnSC_MSB_SHIFT                       (5U)                                                /**< FTM0_CnSC.MSB Position                  */
#define FTM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSB_SHIFT))&FTM_CnSC_MSB_MASK) /**< FTM0_CnSC.MSB Field                     */
#define FTM_CnSC_CHIE_MASK                       (0x40U)                                             /**< FTM0_CnSC.CHIE Mask                     */
#define FTM_CnSC_CHIE_SHIFT                      (6U)                                                /**< FTM0_CnSC.CHIE Position                 */
#define FTM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHIE_SHIFT))&FTM_CnSC_CHIE_MASK) /**< FTM0_CnSC.CHIE Field                    */
#define FTM_CnSC_CHF_MASK                        (0x80U)                                             /**< FTM0_CnSC.CHF Mask                      */
#define FTM_CnSC_CHF_SHIFT                       (7U)                                                /**< FTM0_CnSC.CHF Position                  */
#define FTM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHF_SHIFT))&FTM_CnSC_CHF_MASK) /**< FTM0_CnSC.CHF Field                     */
/** @} */

/** @name CnV - Channel %s Value */ /** @{ */
#define FTM_CnV_VAL_MASK                         (0xFFFFU)                                           /**< FTM0_CnV.VAL Mask                       */
#define FTM_CnV_VAL_SHIFT                        (0U)                                                /**< FTM0_CnV.VAL Position                   */
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK) /**< FTM0_CnV.VAL Field                      */
/** @} */

/** @} */ /* End group FTM_Register_Masks_GROUP */


/* FTM0 - Peripheral instance base addresses */
#define FTM0_BasePtr                   0x40038000UL //!< Peripheral base address
#define FTM0                           ((FTM0_Type *) FTM0_BasePtr) //!< Freescale base pointer
#define FTM0_BASE_PTR                  (FTM0) //!< Freescale style base pointer
#define FTM0_IRQS { FTM0_IRQn,  }


/** @} */ /* End group FTM_Peripheral_access_layer_GROUP */


/** @brief C Struct for FTM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FTM1 (derived from FTM0)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */

/* FTM1 - Peripheral instance base addresses */
#define FTM1_BasePtr                   0x40039000UL //!< Peripheral base address
#define FTM1                           ((FTM0_Type *) FTM1_BasePtr) //!< Freescale base pointer
#define FTM1_BASE_PTR                  (FTM1) //!< Freescale style base pointer
#define FTM1_IRQS { FTM1_IRQn,  }


/** @} */ /* End group FTM_Peripheral_access_layer_GROUP */


/** @brief C Struct for FTM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FTM2 (file:FTM2_6CH_MKE)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (6 channels)
 */
#define FTM_CONTROLS_COUNT   6          /**< Number of FTM channels                             */
/**
 * @struct FTM_Type
 * @brief  C Struct allowing access to FTM registers
 */
typedef struct FTM_Type {
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[FTM_CONTROLS_COUNT];              /**< 000C: (cluster: size=0x0030, 48)                                   */
        uint8_t   RESERVED_1[16];               /**< 003C: 0x10 bytes                                                   */
   __IO uint32_t  CNTIN;                        /**< 004C: Counter Initial Value                                        */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
   __IO uint32_t  MODE;                         /**< 0054: Features Mode Selection                                      */
   __IO uint32_t  SYNC;                         /**< 0058: Synchronization                                              */
   __IO uint32_t  OUTINIT;                      /**< 005C: Initial State for Channels Output                            */
   __IO uint32_t  OUTMASK;                      /**< 0060: Output Mask                                                  */
   __IO uint32_t  COMBINE;                      /**< 0064: Function for Linked Channels                                 */
   __IO uint32_t  DEADTIME;                     /**< 0068: Deadtime Insertion Control                                   */
   __IO uint32_t  EXTTRIG;                      /**< 006C: FTM External Trigger                                         */
   __IO uint32_t  POL;                          /**< 0070: Channels Polarity                                            */
   __IO uint32_t  FMS;                          /**< 0074: Fault Mode Status                                            */
   __IO uint32_t  FILTER;                       /**< 0078: Input Capture Filter Control                                 */
   __IO uint32_t  FLTCTRL;                      /**< 007C: Fault Control                                                */
        uint8_t   RESERVED_2[4];                /**< 0080: 0x4 bytes                                                    */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM_Type;


/** @brief Register Masks for FTM */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM2' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FTM_Register_Masks_GROUP FTM Register Masks */
/** @{ */

/** @name CNTIN - Counter Initial Value */ /** @{ */
#define FTM_CNTIN_INIT_MASK                      (0xFFFFU)                                           /**< FTM2_CNTIN.INIT Mask                    */
#define FTM_CNTIN_INIT_SHIFT                     (0U)                                                /**< FTM2_CNTIN.INIT Position                */
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK) /**< FTM2_CNTIN.INIT Field                   */
/** @} */

/** @name STATUS - Capture and Compare Status */ /** @{ */
#define FTM_STATUS_STATUS_MASK                   (0xFFU)                                             /**< FTM2_STATUS.STATUS Mask                 */
#define FTM_STATUS_STATUS_SHIFT                  (0U)                                                /**< FTM2_STATUS.STATUS Position             */
#define FTM_STATUS_STATUS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_STATUS_SHIFT))&FTM_STATUS_STATUS_MASK) /**< FTM2_STATUS.STATUS Field                */
#define FTM_STATUS_CH0F_MASK                     (0x1U)                                              /**< FTM2_STATUS.CH0F Mask                   */
#define FTM_STATUS_CH0F_SHIFT                    (0U)                                                /**< FTM2_STATUS.CH0F Position               */
#define FTM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH0F_SHIFT))&FTM_STATUS_CH0F_MASK) /**< FTM2_STATUS.CH0F Field                  */
#define FTM_STATUS_CH1F_MASK                     (0x2U)                                              /**< FTM2_STATUS.CH1F Mask                   */
#define FTM_STATUS_CH1F_SHIFT                    (1U)                                                /**< FTM2_STATUS.CH1F Position               */
#define FTM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH1F_SHIFT))&FTM_STATUS_CH1F_MASK) /**< FTM2_STATUS.CH1F Field                  */
#define FTM_STATUS_CH2F_MASK                     (0x4U)                                              /**< FTM2_STATUS.CH2F Mask                   */
#define FTM_STATUS_CH2F_SHIFT                    (2U)                                                /**< FTM2_STATUS.CH2F Position               */
#define FTM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH2F_SHIFT))&FTM_STATUS_CH2F_MASK) /**< FTM2_STATUS.CH2F Field                  */
#define FTM_STATUS_CH3F_MASK                     (0x8U)                                              /**< FTM2_STATUS.CH3F Mask                   */
#define FTM_STATUS_CH3F_SHIFT                    (3U)                                                /**< FTM2_STATUS.CH3F Position               */
#define FTM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH3F_SHIFT))&FTM_STATUS_CH3F_MASK) /**< FTM2_STATUS.CH3F Field                  */
#define FTM_STATUS_CH4F_MASK                     (0x10U)                                             /**< FTM2_STATUS.CH4F Mask                   */
#define FTM_STATUS_CH4F_SHIFT                    (4U)                                                /**< FTM2_STATUS.CH4F Position               */
#define FTM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH4F_SHIFT))&FTM_STATUS_CH4F_MASK) /**< FTM2_STATUS.CH4F Field                  */
#define FTM_STATUS_CH5F_MASK                     (0x20U)                                             /**< FTM2_STATUS.CH5F Mask                   */
#define FTM_STATUS_CH5F_SHIFT                    (5U)                                                /**< FTM2_STATUS.CH5F Position               */
#define FTM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH5F_SHIFT))&FTM_STATUS_CH5F_MASK) /**< FTM2_STATUS.CH5F Field                  */
/** @} */

/** @name MODE - Features Mode Selection */ /** @{ */
#define FTM_MODE_FTMEN_MASK                      (0x1U)                                              /**< FTM2_MODE.FTMEN Mask                    */
#define FTM_MODE_FTMEN_SHIFT                     (0U)                                                /**< FTM2_MODE.FTMEN Position                */
#define FTM_MODE_FTMEN(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FTMEN_SHIFT))&FTM_MODE_FTMEN_MASK) /**< FTM2_MODE.FTMEN Field                   */
#define FTM_MODE_INIT_MASK                       (0x2U)                                              /**< FTM2_MODE.INIT Mask                     */
#define FTM_MODE_INIT_SHIFT                      (1U)                                                /**< FTM2_MODE.INIT Position                 */
#define FTM_MODE_INIT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_MODE_INIT_SHIFT))&FTM_MODE_INIT_MASK) /**< FTM2_MODE.INIT Field                    */
#define FTM_MODE_WPDIS_MASK                      (0x4U)                                              /**< FTM2_MODE.WPDIS Mask                    */
#define FTM_MODE_WPDIS_SHIFT                     (2U)                                                /**< FTM2_MODE.WPDIS Position                */
#define FTM_MODE_WPDIS(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_WPDIS_SHIFT))&FTM_MODE_WPDIS_MASK) /**< FTM2_MODE.WPDIS Field                   */
#define FTM_MODE_PWMSYNC_MASK                    (0x8U)                                              /**< FTM2_MODE.PWMSYNC Mask                  */
#define FTM_MODE_PWMSYNC_SHIFT                   (3U)                                                /**< FTM2_MODE.PWMSYNC Position              */
#define FTM_MODE_PWMSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_PWMSYNC_SHIFT))&FTM_MODE_PWMSYNC_MASK) /**< FTM2_MODE.PWMSYNC Field                 */
#define FTM_MODE_CAPTEST_MASK                    (0x10U)                                             /**< FTM2_MODE.CAPTEST Mask                  */
#define FTM_MODE_CAPTEST_SHIFT                   (4U)                                                /**< FTM2_MODE.CAPTEST Position              */
#define FTM_MODE_CAPTEST(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_CAPTEST_SHIFT))&FTM_MODE_CAPTEST_MASK) /**< FTM2_MODE.CAPTEST Field                 */
#define FTM_MODE_FAULTM_MASK                     (0x60U)                                             /**< FTM2_MODE.FAULTM Mask                   */
#define FTM_MODE_FAULTM_SHIFT                    (5U)                                                /**< FTM2_MODE.FAULTM Position               */
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK) /**< FTM2_MODE.FAULTM Field                  */
#define FTM_MODE_FAULTIE_MASK                    (0x80U)                                             /**< FTM2_MODE.FAULTIE Mask                  */
#define FTM_MODE_FAULTIE_SHIFT                   (7U)                                                /**< FTM2_MODE.FAULTIE Position              */
#define FTM_MODE_FAULTIE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTIE_SHIFT))&FTM_MODE_FAULTIE_MASK) /**< FTM2_MODE.FAULTIE Field                 */
/** @} */

/** @name SYNC - Synchronization */ /** @{ */
#define FTM_SYNC_CNTMIN_MASK                     (0x1U)                                              /**< FTM2_SYNC.CNTMIN Mask                   */
#define FTM_SYNC_CNTMIN_SHIFT                    (0U)                                                /**< FTM2_SYNC.CNTMIN Position               */
#define FTM_SYNC_CNTMIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMIN_SHIFT))&FTM_SYNC_CNTMIN_MASK) /**< FTM2_SYNC.CNTMIN Field                  */
#define FTM_SYNC_CNTMAX_MASK                     (0x2U)                                              /**< FTM2_SYNC.CNTMAX Mask                   */
#define FTM_SYNC_CNTMAX_SHIFT                    (1U)                                                /**< FTM2_SYNC.CNTMAX Position               */
#define FTM_SYNC_CNTMAX(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMAX_SHIFT))&FTM_SYNC_CNTMAX_MASK) /**< FTM2_SYNC.CNTMAX Field                  */
#define FTM_SYNC_REINIT_MASK                     (0x4U)                                              /**< FTM2_SYNC.REINIT Mask                   */
#define FTM_SYNC_REINIT_SHIFT                    (2U)                                                /**< FTM2_SYNC.REINIT Position               */
#define FTM_SYNC_REINIT(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_REINIT_SHIFT))&FTM_SYNC_REINIT_MASK) /**< FTM2_SYNC.REINIT Field                  */
#define FTM_SYNC_SYNCHOM_MASK                    (0x8U)                                              /**< FTM2_SYNC.SYNCHOM Mask                  */
#define FTM_SYNC_SYNCHOM_SHIFT                   (3U)                                                /**< FTM2_SYNC.SYNCHOM Position              */
#define FTM_SYNC_SYNCHOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SYNCHOM_SHIFT))&FTM_SYNC_SYNCHOM_MASK) /**< FTM2_SYNC.SYNCHOM Field                 */
#define FTM_SYNC_TRIG_MASK                       (0x70U)                                             /**< FTM2_SYNC.TRIG Mask                     */
#define FTM_SYNC_TRIG_SHIFT                      (4U)                                                /**< FTM2_SYNC.TRIG Position                 */
#define FTM_SYNC_TRIG(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG_SHIFT))&FTM_SYNC_TRIG_MASK) /**< FTM2_SYNC.TRIG Field                    */
#define FTM_SYNC_TRIG0_MASK                      (0x10U)                                             /**< FTM2_SYNC.TRIG0 Mask                    */
#define FTM_SYNC_TRIG0_SHIFT                     (4U)                                                /**< FTM2_SYNC.TRIG0 Position                */
#define FTM_SYNC_TRIG0(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG0_SHIFT))&FTM_SYNC_TRIG0_MASK) /**< FTM2_SYNC.TRIG0 Field                   */
#define FTM_SYNC_TRIG1_MASK                      (0x20U)                                             /**< FTM2_SYNC.TRIG1 Mask                    */
#define FTM_SYNC_TRIG1_SHIFT                     (5U)                                                /**< FTM2_SYNC.TRIG1 Position                */
#define FTM_SYNC_TRIG1(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG1_SHIFT))&FTM_SYNC_TRIG1_MASK) /**< FTM2_SYNC.TRIG1 Field                   */
#define FTM_SYNC_TRIG2_MASK                      (0x40U)                                             /**< FTM2_SYNC.TRIG2 Mask                    */
#define FTM_SYNC_TRIG2_SHIFT                     (6U)                                                /**< FTM2_SYNC.TRIG2 Position                */
#define FTM_SYNC_TRIG2(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG2_SHIFT))&FTM_SYNC_TRIG2_MASK) /**< FTM2_SYNC.TRIG2 Field                   */
#define FTM_SYNC_SWSYNC_MASK                     (0x80U)                                             /**< FTM2_SYNC.SWSYNC Mask                   */
#define FTM_SYNC_SWSYNC_SHIFT                    (7U)                                                /**< FTM2_SYNC.SWSYNC Position               */
#define FTM_SYNC_SWSYNC(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SWSYNC_SHIFT))&FTM_SYNC_SWSYNC_MASK) /**< FTM2_SYNC.SWSYNC Field                  */
/** @} */

/** @name OUTINIT - Initial State for Channels Output */ /** @{ */
#define FTM_OUTINIT_CHOI_MASK                    (0xFFU)                                             /**< FTM2_OUTINIT.CHOI Mask                  */
#define FTM_OUTINIT_CHOI_SHIFT                   (0U)                                                /**< FTM2_OUTINIT.CHOI Position              */
#define FTM_OUTINIT_CHOI(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CHOI_SHIFT))&FTM_OUTINIT_CHOI_MASK) /**< FTM2_OUTINIT.CHOI Field                 */
#define FTM_OUTINIT_CH0OI_MASK                   (0x1U)                                              /**< FTM2_OUTINIT.CH0OI Mask                 */
#define FTM_OUTINIT_CH0OI_SHIFT                  (0U)                                                /**< FTM2_OUTINIT.CH0OI Position             */
#define FTM_OUTINIT_CH0OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH0OI_SHIFT))&FTM_OUTINIT_CH0OI_MASK) /**< FTM2_OUTINIT.CH0OI Field                */
#define FTM_OUTINIT_CH1OI_MASK                   (0x2U)                                              /**< FTM2_OUTINIT.CH1OI Mask                 */
#define FTM_OUTINIT_CH1OI_SHIFT                  (1U)                                                /**< FTM2_OUTINIT.CH1OI Position             */
#define FTM_OUTINIT_CH1OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH1OI_SHIFT))&FTM_OUTINIT_CH1OI_MASK) /**< FTM2_OUTINIT.CH1OI Field                */
#define FTM_OUTINIT_CH2OI_MASK                   (0x4U)                                              /**< FTM2_OUTINIT.CH2OI Mask                 */
#define FTM_OUTINIT_CH2OI_SHIFT                  (2U)                                                /**< FTM2_OUTINIT.CH2OI Position             */
#define FTM_OUTINIT_CH2OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH2OI_SHIFT))&FTM_OUTINIT_CH2OI_MASK) /**< FTM2_OUTINIT.CH2OI Field                */
#define FTM_OUTINIT_CH3OI_MASK                   (0x8U)                                              /**< FTM2_OUTINIT.CH3OI Mask                 */
#define FTM_OUTINIT_CH3OI_SHIFT                  (3U)                                                /**< FTM2_OUTINIT.CH3OI Position             */
#define FTM_OUTINIT_CH3OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH3OI_SHIFT))&FTM_OUTINIT_CH3OI_MASK) /**< FTM2_OUTINIT.CH3OI Field                */
#define FTM_OUTINIT_CH4OI_MASK                   (0x10U)                                             /**< FTM2_OUTINIT.CH4OI Mask                 */
#define FTM_OUTINIT_CH4OI_SHIFT                  (4U)                                                /**< FTM2_OUTINIT.CH4OI Position             */
#define FTM_OUTINIT_CH4OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH4OI_SHIFT))&FTM_OUTINIT_CH4OI_MASK) /**< FTM2_OUTINIT.CH4OI Field                */
#define FTM_OUTINIT_CH5OI_MASK                   (0x20U)                                             /**< FTM2_OUTINIT.CH5OI Mask                 */
#define FTM_OUTINIT_CH5OI_SHIFT                  (5U)                                                /**< FTM2_OUTINIT.CH5OI Position             */
#define FTM_OUTINIT_CH5OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH5OI_SHIFT))&FTM_OUTINIT_CH5OI_MASK) /**< FTM2_OUTINIT.CH5OI Field                */
/** @} */

/** @name OUTMASK - Output Mask */ /** @{ */
#define FTM_OUTMASK_CHOM_MASK                    (0xFFU)                                             /**< FTM2_OUTMASK.CHOM Mask                  */
#define FTM_OUTMASK_CHOM_SHIFT                   (0U)                                                /**< FTM2_OUTMASK.CHOM Position              */
#define FTM_OUTMASK_CHOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CHOM_SHIFT))&FTM_OUTMASK_CHOM_MASK) /**< FTM2_OUTMASK.CHOM Field                 */
#define FTM_OUTMASK_CH0OM_MASK                   (0x1U)                                              /**< FTM2_OUTMASK.CH0OM Mask                 */
#define FTM_OUTMASK_CH0OM_SHIFT                  (0U)                                                /**< FTM2_OUTMASK.CH0OM Position             */
#define FTM_OUTMASK_CH0OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH0OM_SHIFT))&FTM_OUTMASK_CH0OM_MASK) /**< FTM2_OUTMASK.CH0OM Field                */
#define FTM_OUTMASK_CH1OM_MASK                   (0x2U)                                              /**< FTM2_OUTMASK.CH1OM Mask                 */
#define FTM_OUTMASK_CH1OM_SHIFT                  (1U)                                                /**< FTM2_OUTMASK.CH1OM Position             */
#define FTM_OUTMASK_CH1OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH1OM_SHIFT))&FTM_OUTMASK_CH1OM_MASK) /**< FTM2_OUTMASK.CH1OM Field                */
#define FTM_OUTMASK_CH2OM_MASK                   (0x4U)                                              /**< FTM2_OUTMASK.CH2OM Mask                 */
#define FTM_OUTMASK_CH2OM_SHIFT                  (2U)                                                /**< FTM2_OUTMASK.CH2OM Position             */
#define FTM_OUTMASK_CH2OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH2OM_SHIFT))&FTM_OUTMASK_CH2OM_MASK) /**< FTM2_OUTMASK.CH2OM Field                */
#define FTM_OUTMASK_CH3OM_MASK                   (0x8U)                                              /**< FTM2_OUTMASK.CH3OM Mask                 */
#define FTM_OUTMASK_CH3OM_SHIFT                  (3U)                                                /**< FTM2_OUTMASK.CH3OM Position             */
#define FTM_OUTMASK_CH3OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH3OM_SHIFT))&FTM_OUTMASK_CH3OM_MASK) /**< FTM2_OUTMASK.CH3OM Field                */
#define FTM_OUTMASK_CH4OM_MASK                   (0x10U)                                             /**< FTM2_OUTMASK.CH4OM Mask                 */
#define FTM_OUTMASK_CH4OM_SHIFT                  (4U)                                                /**< FTM2_OUTMASK.CH4OM Position             */
#define FTM_OUTMASK_CH4OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH4OM_SHIFT))&FTM_OUTMASK_CH4OM_MASK) /**< FTM2_OUTMASK.CH4OM Field                */
#define FTM_OUTMASK_CH5OM_MASK                   (0x20U)                                             /**< FTM2_OUTMASK.CH5OM Mask                 */
#define FTM_OUTMASK_CH5OM_SHIFT                  (5U)                                                /**< FTM2_OUTMASK.CH5OM Position             */
#define FTM_OUTMASK_CH5OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH5OM_SHIFT))&FTM_OUTMASK_CH5OM_MASK) /**< FTM2_OUTMASK.CH5OM Field                */
/** @} */

/** @name COMBINE - Function for Linked Channels */ /** @{ */
#define FTM_COMBINE_COMBINE_MASK                 (0x7FU)                                             /**< FTM2_COMBINE.COMBINE Mask               */
#define FTM_COMBINE_COMBINE_SHIFT                (0U)                                                /**< FTM2_COMBINE.COMBINE Position           */
#define FTM_COMBINE_COMBINE(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE_SHIFT))&FTM_COMBINE_COMBINE_MASK) /**< FTM2_COMBINE.COMBINE Field              */
#define FTM_COMBINE_COMBINE0_MASK                (0x1U)                                              /**< FTM2_COMBINE.COMBINE0 Mask              */
#define FTM_COMBINE_COMBINE0_SHIFT               (0U)                                                /**< FTM2_COMBINE.COMBINE0 Position          */
#define FTM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE0_SHIFT))&FTM_COMBINE_COMBINE0_MASK) /**< FTM2_COMBINE.COMBINE0 Field             */
#define FTM_COMBINE_COMP0_MASK                   (0x2U)                                              /**< FTM2_COMBINE.COMP0 Mask                 */
#define FTM_COMBINE_COMP0_SHIFT                  (1U)                                                /**< FTM2_COMBINE.COMP0 Position             */
#define FTM_COMBINE_COMP0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP0_SHIFT))&FTM_COMBINE_COMP0_MASK) /**< FTM2_COMBINE.COMP0 Field                */
#define FTM_COMBINE_DECAPEN0_MASK                (0x4U)                                              /**< FTM2_COMBINE.DECAPEN0 Mask              */
#define FTM_COMBINE_DECAPEN0_SHIFT               (2U)                                                /**< FTM2_COMBINE.DECAPEN0 Position          */
#define FTM_COMBINE_DECAPEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN0_SHIFT))&FTM_COMBINE_DECAPEN0_MASK) /**< FTM2_COMBINE.DECAPEN0 Field             */
#define FTM_COMBINE_DECAP0_MASK                  (0x8U)                                              /**< FTM2_COMBINE.DECAP0 Mask                */
#define FTM_COMBINE_DECAP0_SHIFT                 (3U)                                                /**< FTM2_COMBINE.DECAP0 Position            */
#define FTM_COMBINE_DECAP0(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP0_SHIFT))&FTM_COMBINE_DECAP0_MASK) /**< FTM2_COMBINE.DECAP0 Field               */
#define FTM_COMBINE_DTEN0_MASK                   (0x10U)                                             /**< FTM2_COMBINE.DTEN0 Mask                 */
#define FTM_COMBINE_DTEN0_SHIFT                  (4U)                                                /**< FTM2_COMBINE.DTEN0 Position             */
#define FTM_COMBINE_DTEN0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN0_SHIFT))&FTM_COMBINE_DTEN0_MASK) /**< FTM2_COMBINE.DTEN0 Field                */
#define FTM_COMBINE_SYNCEN0_MASK                 (0x20U)                                             /**< FTM2_COMBINE.SYNCEN0 Mask               */
#define FTM_COMBINE_SYNCEN0_SHIFT                (5U)                                                /**< FTM2_COMBINE.SYNCEN0 Position           */
#define FTM_COMBINE_SYNCEN0(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN0_SHIFT))&FTM_COMBINE_SYNCEN0_MASK) /**< FTM2_COMBINE.SYNCEN0 Field              */
#define FTM_COMBINE_FAULTEN0_MASK                (0x40U)                                             /**< FTM2_COMBINE.FAULTEN0 Mask              */
#define FTM_COMBINE_FAULTEN0_SHIFT               (6U)                                                /**< FTM2_COMBINE.FAULTEN0 Position          */
#define FTM_COMBINE_FAULTEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN0_SHIFT))&FTM_COMBINE_FAULTEN0_MASK) /**< FTM2_COMBINE.FAULTEN0 Field             */
#define FTM_COMBINE_COMBINE1_MASK                (0x100U)                                            /**< FTM2_COMBINE.COMBINE1 Mask              */
#define FTM_COMBINE_COMBINE1_SHIFT               (8U)                                                /**< FTM2_COMBINE.COMBINE1 Position          */
#define FTM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE1_SHIFT))&FTM_COMBINE_COMBINE1_MASK) /**< FTM2_COMBINE.COMBINE1 Field             */
#define FTM_COMBINE_COMP1_MASK                   (0x200U)                                            /**< FTM2_COMBINE.COMP1 Mask                 */
#define FTM_COMBINE_COMP1_SHIFT                  (9U)                                                /**< FTM2_COMBINE.COMP1 Position             */
#define FTM_COMBINE_COMP1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP1_SHIFT))&FTM_COMBINE_COMP1_MASK) /**< FTM2_COMBINE.COMP1 Field                */
#define FTM_COMBINE_DECAPEN1_MASK                (0x400U)                                            /**< FTM2_COMBINE.DECAPEN1 Mask              */
#define FTM_COMBINE_DECAPEN1_SHIFT               (10U)                                               /**< FTM2_COMBINE.DECAPEN1 Position          */
#define FTM_COMBINE_DECAPEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN1_SHIFT))&FTM_COMBINE_DECAPEN1_MASK) /**< FTM2_COMBINE.DECAPEN1 Field             */
#define FTM_COMBINE_DECAP1_MASK                  (0x800U)                                            /**< FTM2_COMBINE.DECAP1 Mask                */
#define FTM_COMBINE_DECAP1_SHIFT                 (11U)                                               /**< FTM2_COMBINE.DECAP1 Position            */
#define FTM_COMBINE_DECAP1(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP1_SHIFT))&FTM_COMBINE_DECAP1_MASK) /**< FTM2_COMBINE.DECAP1 Field               */
#define FTM_COMBINE_DTEN1_MASK                   (0x1000U)                                           /**< FTM2_COMBINE.DTEN1 Mask                 */
#define FTM_COMBINE_DTEN1_SHIFT                  (12U)                                               /**< FTM2_COMBINE.DTEN1 Position             */
#define FTM_COMBINE_DTEN1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN1_SHIFT))&FTM_COMBINE_DTEN1_MASK) /**< FTM2_COMBINE.DTEN1 Field                */
#define FTM_COMBINE_SYNCEN1_MASK                 (0x2000U)                                           /**< FTM2_COMBINE.SYNCEN1 Mask               */
#define FTM_COMBINE_SYNCEN1_SHIFT                (13U)                                               /**< FTM2_COMBINE.SYNCEN1 Position           */
#define FTM_COMBINE_SYNCEN1(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN1_SHIFT))&FTM_COMBINE_SYNCEN1_MASK) /**< FTM2_COMBINE.SYNCEN1 Field              */
#define FTM_COMBINE_FAULTEN1_MASK                (0x4000U)                                           /**< FTM2_COMBINE.FAULTEN1 Mask              */
#define FTM_COMBINE_FAULTEN1_SHIFT               (14U)                                               /**< FTM2_COMBINE.FAULTEN1 Position          */
#define FTM_COMBINE_FAULTEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN1_SHIFT))&FTM_COMBINE_FAULTEN1_MASK) /**< FTM2_COMBINE.FAULTEN1 Field             */
#define FTM_COMBINE_COMBINE2_MASK                (0x10000U)                                          /**< FTM2_COMBINE.COMBINE2 Mask              */
#define FTM_COMBINE_COMBINE2_SHIFT               (16U)                                               /**< FTM2_COMBINE.COMBINE2 Position          */
#define FTM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE2_SHIFT))&FTM_COMBINE_COMBINE2_MASK) /**< FTM2_COMBINE.COMBINE2 Field             */
#define FTM_COMBINE_COMP2_MASK                   (0x20000U)                                          /**< FTM2_COMBINE.COMP2 Mask                 */
#define FTM_COMBINE_COMP2_SHIFT                  (17U)                                               /**< FTM2_COMBINE.COMP2 Position             */
#define FTM_COMBINE_COMP2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP2_SHIFT))&FTM_COMBINE_COMP2_MASK) /**< FTM2_COMBINE.COMP2 Field                */
#define FTM_COMBINE_DECAPEN2_MASK                (0x40000U)                                          /**< FTM2_COMBINE.DECAPEN2 Mask              */
#define FTM_COMBINE_DECAPEN2_SHIFT               (18U)                                               /**< FTM2_COMBINE.DECAPEN2 Position          */
#define FTM_COMBINE_DECAPEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN2_SHIFT))&FTM_COMBINE_DECAPEN2_MASK) /**< FTM2_COMBINE.DECAPEN2 Field             */
#define FTM_COMBINE_DECAP2_MASK                  (0x80000U)                                          /**< FTM2_COMBINE.DECAP2 Mask                */
#define FTM_COMBINE_DECAP2_SHIFT                 (19U)                                               /**< FTM2_COMBINE.DECAP2 Position            */
#define FTM_COMBINE_DECAP2(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP2_SHIFT))&FTM_COMBINE_DECAP2_MASK) /**< FTM2_COMBINE.DECAP2 Field               */
#define FTM_COMBINE_DTEN2_MASK                   (0x100000U)                                         /**< FTM2_COMBINE.DTEN2 Mask                 */
#define FTM_COMBINE_DTEN2_SHIFT                  (20U)                                               /**< FTM2_COMBINE.DTEN2 Position             */
#define FTM_COMBINE_DTEN2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN2_SHIFT))&FTM_COMBINE_DTEN2_MASK) /**< FTM2_COMBINE.DTEN2 Field                */
#define FTM_COMBINE_SYNCEN2_MASK                 (0x200000U)                                         /**< FTM2_COMBINE.SYNCEN2 Mask               */
#define FTM_COMBINE_SYNCEN2_SHIFT                (21U)                                               /**< FTM2_COMBINE.SYNCEN2 Position           */
#define FTM_COMBINE_SYNCEN2(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN2_SHIFT))&FTM_COMBINE_SYNCEN2_MASK) /**< FTM2_COMBINE.SYNCEN2 Field              */
#define FTM_COMBINE_FAULTEN2_MASK                (0x400000U)                                         /**< FTM2_COMBINE.FAULTEN2 Mask              */
#define FTM_COMBINE_FAULTEN2_SHIFT               (22U)                                               /**< FTM2_COMBINE.FAULTEN2 Position          */
#define FTM_COMBINE_FAULTEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN2_SHIFT))&FTM_COMBINE_FAULTEN2_MASK) /**< FTM2_COMBINE.FAULTEN2 Field             */
/** @} */

/** @name DEADTIME - Deadtime Insertion Control */ /** @{ */
#define FTM_DEADTIME_DTVAL_MASK                  (0x3FU)                                             /**< FTM2_DEADTIME.DTVAL Mask                */
#define FTM_DEADTIME_DTVAL_SHIFT                 (0U)                                                /**< FTM2_DEADTIME.DTVAL Position            */
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK) /**< FTM2_DEADTIME.DTVAL Field               */
#define FTM_DEADTIME_DTPS_MASK                   (0xC0U)                                             /**< FTM2_DEADTIME.DTPS Mask                 */
#define FTM_DEADTIME_DTPS_SHIFT                  (6U)                                                /**< FTM2_DEADTIME.DTPS Position             */
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK) /**< FTM2_DEADTIME.DTPS Field                */
/** @} */

/** @name EXTTRIG - FTM External Trigger */ /** @{ */
#define FTM_EXTTRIG_CHTRIG_MASK                  (0xFFU)                                             /**< FTM2_EXTTRIG.CHTRIG Mask                */
#define FTM_EXTTRIG_CHTRIG_SHIFT                 (0U)                                                /**< FTM2_EXTTRIG.CHTRIG Position            */
#define FTM_EXTTRIG_CHTRIG(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CHTRIG_SHIFT))&FTM_EXTTRIG_CHTRIG_MASK) /**< FTM2_EXTTRIG.CHTRIG Field               */
#define FTM_EXTTRIG_CH2TRIG_MASK                 (0x1U)                                              /**< FTM2_EXTTRIG.CH2TRIG Mask               */
#define FTM_EXTTRIG_CH2TRIG_SHIFT                (0U)                                                /**< FTM2_EXTTRIG.CH2TRIG Position           */
#define FTM_EXTTRIG_CH2TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH2TRIG_SHIFT))&FTM_EXTTRIG_CH2TRIG_MASK) /**< FTM2_EXTTRIG.CH2TRIG Field              */
#define FTM_EXTTRIG_CH3TRIG_MASK                 (0x2U)                                              /**< FTM2_EXTTRIG.CH3TRIG Mask               */
#define FTM_EXTTRIG_CH3TRIG_SHIFT                (1U)                                                /**< FTM2_EXTTRIG.CH3TRIG Position           */
#define FTM_EXTTRIG_CH3TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH3TRIG_SHIFT))&FTM_EXTTRIG_CH3TRIG_MASK) /**< FTM2_EXTTRIG.CH3TRIG Field              */
#define FTM_EXTTRIG_CH4TRIG_MASK                 (0x4U)                                              /**< FTM2_EXTTRIG.CH4TRIG Mask               */
#define FTM_EXTTRIG_CH4TRIG_SHIFT                (2U)                                                /**< FTM2_EXTTRIG.CH4TRIG Position           */
#define FTM_EXTTRIG_CH4TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH4TRIG_SHIFT))&FTM_EXTTRIG_CH4TRIG_MASK) /**< FTM2_EXTTRIG.CH4TRIG Field              */
#define FTM_EXTTRIG_CH5TRIG_MASK                 (0x8U)                                              /**< FTM2_EXTTRIG.CH5TRIG Mask               */
#define FTM_EXTTRIG_CH5TRIG_SHIFT                (3U)                                                /**< FTM2_EXTTRIG.CH5TRIG Position           */
#define FTM_EXTTRIG_CH5TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH5TRIG_SHIFT))&FTM_EXTTRIG_CH5TRIG_MASK) /**< FTM2_EXTTRIG.CH5TRIG Field              */
#define FTM_EXTTRIG_CH0TRIG_MASK                 (0x10U)                                             /**< FTM2_EXTTRIG.CH0TRIG Mask               */
#define FTM_EXTTRIG_CH0TRIG_SHIFT                (4U)                                                /**< FTM2_EXTTRIG.CH0TRIG Position           */
#define FTM_EXTTRIG_CH0TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH0TRIG_SHIFT))&FTM_EXTTRIG_CH0TRIG_MASK) /**< FTM2_EXTTRIG.CH0TRIG Field              */
#define FTM_EXTTRIG_CH1TRIG_MASK                 (0x20U)                                             /**< FTM2_EXTTRIG.CH1TRIG Mask               */
#define FTM_EXTTRIG_CH1TRIG_SHIFT                (5U)                                                /**< FTM2_EXTTRIG.CH1TRIG Position           */
#define FTM_EXTTRIG_CH1TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH1TRIG_SHIFT))&FTM_EXTTRIG_CH1TRIG_MASK) /**< FTM2_EXTTRIG.CH1TRIG Field              */
#define FTM_EXTTRIG_INITTRIGEN_MASK              (0x40U)                                             /**< FTM2_EXTTRIG.INITTRIGEN Mask            */
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             (6U)                                                /**< FTM2_EXTTRIG.INITTRIGEN Position        */
#define FTM_EXTTRIG_INITTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_INITTRIGEN_SHIFT))&FTM_EXTTRIG_INITTRIGEN_MASK) /**< FTM2_EXTTRIG.INITTRIGEN Field           */
#define FTM_EXTTRIG_TRIGF_MASK                   (0x80U)                                             /**< FTM2_EXTTRIG.TRIGF Mask                 */
#define FTM_EXTTRIG_TRIGF_SHIFT                  (7U)                                                /**< FTM2_EXTTRIG.TRIGF Position             */
#define FTM_EXTTRIG_TRIGF(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_TRIGF_SHIFT))&FTM_EXTTRIG_TRIGF_MASK) /**< FTM2_EXTTRIG.TRIGF Field                */
/** @} */

/** @name POL - Channels Polarity */ /** @{ */
#define FTM_POL_POL_MASK                         (0xFFU)                                             /**< FTM2_POL.POL Mask                       */
#define FTM_POL_POL_SHIFT                        (0U)                                                /**< FTM2_POL.POL Position                   */
#define FTM_POL_POL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL_SHIFT))&FTM_POL_POL_MASK) /**< FTM2_POL.POL Field                      */
#define FTM_POL_POL0_MASK                        (0x1U)                                              /**< FTM2_POL.POL0 Mask                      */
#define FTM_POL_POL0_SHIFT                       (0U)                                                /**< FTM2_POL.POL0 Position                  */
#define FTM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL0_SHIFT))&FTM_POL_POL0_MASK) /**< FTM2_POL.POL0 Field                     */
#define FTM_POL_POL1_MASK                        (0x2U)                                              /**< FTM2_POL.POL1 Mask                      */
#define FTM_POL_POL1_SHIFT                       (1U)                                                /**< FTM2_POL.POL1 Position                  */
#define FTM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL1_SHIFT))&FTM_POL_POL1_MASK) /**< FTM2_POL.POL1 Field                     */
#define FTM_POL_POL2_MASK                        (0x4U)                                              /**< FTM2_POL.POL2 Mask                      */
#define FTM_POL_POL2_SHIFT                       (2U)                                                /**< FTM2_POL.POL2 Position                  */
#define FTM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL2_SHIFT))&FTM_POL_POL2_MASK) /**< FTM2_POL.POL2 Field                     */
#define FTM_POL_POL3_MASK                        (0x8U)                                              /**< FTM2_POL.POL3 Mask                      */
#define FTM_POL_POL3_SHIFT                       (3U)                                                /**< FTM2_POL.POL3 Position                  */
#define FTM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL3_SHIFT))&FTM_POL_POL3_MASK) /**< FTM2_POL.POL3 Field                     */
#define FTM_POL_POL4_MASK                        (0x10U)                                             /**< FTM2_POL.POL4 Mask                      */
#define FTM_POL_POL4_SHIFT                       (4U)                                                /**< FTM2_POL.POL4 Position                  */
#define FTM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL4_SHIFT))&FTM_POL_POL4_MASK) /**< FTM2_POL.POL4 Field                     */
#define FTM_POL_POL5_MASK                        (0x20U)                                             /**< FTM2_POL.POL5 Mask                      */
#define FTM_POL_POL5_SHIFT                       (5U)                                                /**< FTM2_POL.POL5 Position                  */
#define FTM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL5_SHIFT))&FTM_POL_POL5_MASK) /**< FTM2_POL.POL5 Field                     */
/** @} */

/** @name FMS - Fault Mode Status */ /** @{ */
#define FTM_FMS_FAULTF0_MASK                     (0x1U)                                              /**< FTM2_FMS.FAULTF0 Mask                   */
#define FTM_FMS_FAULTF0_SHIFT                    (0U)                                                /**< FTM2_FMS.FAULTF0 Position               */
#define FTM_FMS_FAULTF0(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF0_SHIFT))&FTM_FMS_FAULTF0_MASK) /**< FTM2_FMS.FAULTF0 Field                  */
#define FTM_FMS_FAULTF1_MASK                     (0x2U)                                              /**< FTM2_FMS.FAULTF1 Mask                   */
#define FTM_FMS_FAULTF1_SHIFT                    (1U)                                                /**< FTM2_FMS.FAULTF1 Position               */
#define FTM_FMS_FAULTF1(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF1_SHIFT))&FTM_FMS_FAULTF1_MASK) /**< FTM2_FMS.FAULTF1 Field                  */
#define FTM_FMS_FAULTF2_MASK                     (0x4U)                                              /**< FTM2_FMS.FAULTF2 Mask                   */
#define FTM_FMS_FAULTF2_SHIFT                    (2U)                                                /**< FTM2_FMS.FAULTF2 Position               */
#define FTM_FMS_FAULTF2(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF2_SHIFT))&FTM_FMS_FAULTF2_MASK) /**< FTM2_FMS.FAULTF2 Field                  */
#define FTM_FMS_FAULTF3_MASK                     (0x8U)                                              /**< FTM2_FMS.FAULTF3 Mask                   */
#define FTM_FMS_FAULTF3_SHIFT                    (3U)                                                /**< FTM2_FMS.FAULTF3 Position               */
#define FTM_FMS_FAULTF3(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF3_SHIFT))&FTM_FMS_FAULTF3_MASK) /**< FTM2_FMS.FAULTF3 Field                  */
#define FTM_FMS_FAULTIN_MASK                     (0x20U)                                             /**< FTM2_FMS.FAULTIN Mask                   */
#define FTM_FMS_FAULTIN_SHIFT                    (5U)                                                /**< FTM2_FMS.FAULTIN Position               */
#define FTM_FMS_FAULTIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTIN_SHIFT))&FTM_FMS_FAULTIN_MASK) /**< FTM2_FMS.FAULTIN Field                  */
#define FTM_FMS_WPEN_MASK                        (0x40U)                                             /**< FTM2_FMS.WPEN Mask                      */
#define FTM_FMS_WPEN_SHIFT                       (6U)                                                /**< FTM2_FMS.WPEN Position                  */
#define FTM_FMS_WPEN(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_FMS_WPEN_SHIFT))&FTM_FMS_WPEN_MASK) /**< FTM2_FMS.WPEN Field                     */
#define FTM_FMS_FAULTF_MASK                      (0x80U)                                             /**< FTM2_FMS.FAULTF Mask                    */
#define FTM_FMS_FAULTF_SHIFT                     (7U)                                                /**< FTM2_FMS.FAULTF Position                */
#define FTM_FMS_FAULTF(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF_SHIFT))&FTM_FMS_FAULTF_MASK) /**< FTM2_FMS.FAULTF Field                   */
/** @} */

/** @name FILTER - Input Capture Filter Control */ /** @{ */
#define FTM_FILTER_CH0FVAL_MASK                  (0xFU)                                              /**< FTM2_FILTER.CH0FVAL Mask                */
#define FTM_FILTER_CH0FVAL_SHIFT                 (0U)                                                /**< FTM2_FILTER.CH0FVAL Position            */
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK) /**< FTM2_FILTER.CH0FVAL Field               */
#define FTM_FILTER_CH1FVAL_MASK                  (0xF0U)                                             /**< FTM2_FILTER.CH1FVAL Mask                */
#define FTM_FILTER_CH1FVAL_SHIFT                 (4U)                                                /**< FTM2_FILTER.CH1FVAL Position            */
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK) /**< FTM2_FILTER.CH1FVAL Field               */
#define FTM_FILTER_CH2FVAL_MASK                  (0xF00U)                                            /**< FTM2_FILTER.CH2FVAL Mask                */
#define FTM_FILTER_CH2FVAL_SHIFT                 (8U)                                                /**< FTM2_FILTER.CH2FVAL Position            */
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK) /**< FTM2_FILTER.CH2FVAL Field               */
#define FTM_FILTER_CH3FVAL_MASK                  (0xF000U)                                           /**< FTM2_FILTER.CH3FVAL Mask                */
#define FTM_FILTER_CH3FVAL_SHIFT                 (12U)                                               /**< FTM2_FILTER.CH3FVAL Position            */
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK) /**< FTM2_FILTER.CH3FVAL Field               */
/** @} */

/** @name FLTCTRL - Fault Control */ /** @{ */
#define FTM_FLTCTRL_FAULTEN_MASK                 (0xFU)                                              /**< FTM2_FLTCTRL.FAULTEN Mask               */
#define FTM_FLTCTRL_FAULTEN_SHIFT                (0U)                                                /**< FTM2_FLTCTRL.FAULTEN Position           */
#define FTM_FLTCTRL_FAULTEN(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULTEN_SHIFT))&FTM_FLTCTRL_FAULTEN_MASK) /**< FTM2_FLTCTRL.FAULTEN Field              */
#define FTM_FLTCTRL_FAULT0EN_MASK                (0x1U)                                              /**< FTM2_FLTCTRL.FAULT0EN Mask              */
#define FTM_FLTCTRL_FAULT0EN_SHIFT               (0U)                                                /**< FTM2_FLTCTRL.FAULT0EN Position          */
#define FTM_FLTCTRL_FAULT0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT0EN_SHIFT))&FTM_FLTCTRL_FAULT0EN_MASK) /**< FTM2_FLTCTRL.FAULT0EN Field             */
#define FTM_FLTCTRL_FAULT1EN_MASK                (0x2U)                                              /**< FTM2_FLTCTRL.FAULT1EN Mask              */
#define FTM_FLTCTRL_FAULT1EN_SHIFT               (1U)                                                /**< FTM2_FLTCTRL.FAULT1EN Position          */
#define FTM_FLTCTRL_FAULT1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT1EN_SHIFT))&FTM_FLTCTRL_FAULT1EN_MASK) /**< FTM2_FLTCTRL.FAULT1EN Field             */
#define FTM_FLTCTRL_FAULT2EN_MASK                (0x4U)                                              /**< FTM2_FLTCTRL.FAULT2EN Mask              */
#define FTM_FLTCTRL_FAULT2EN_SHIFT               (2U)                                                /**< FTM2_FLTCTRL.FAULT2EN Position          */
#define FTM_FLTCTRL_FAULT2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT2EN_SHIFT))&FTM_FLTCTRL_FAULT2EN_MASK) /**< FTM2_FLTCTRL.FAULT2EN Field             */
#define FTM_FLTCTRL_FAULT3EN_MASK                (0x8U)                                              /**< FTM2_FLTCTRL.FAULT3EN Mask              */
#define FTM_FLTCTRL_FAULT3EN_SHIFT               (3U)                                                /**< FTM2_FLTCTRL.FAULT3EN Position          */
#define FTM_FLTCTRL_FAULT3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT3EN_SHIFT))&FTM_FLTCTRL_FAULT3EN_MASK) /**< FTM2_FLTCTRL.FAULT3EN Field             */
#define FTM_FLTCTRL_FFLTREN_MASK                 (0xF0U)                                             /**< FTM2_FLTCTRL.FFLTREN Mask               */
#define FTM_FLTCTRL_FFLTREN_SHIFT                (4U)                                                /**< FTM2_FLTCTRL.FFLTREN Position           */
#define FTM_FLTCTRL_FFLTREN(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTREN_SHIFT))&FTM_FLTCTRL_FFLTREN_MASK) /**< FTM2_FLTCTRL.FFLTREN Field              */
#define FTM_FLTCTRL_FFLTR0EN_MASK                (0x10U)                                             /**< FTM2_FLTCTRL.FFLTR0EN Mask              */
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               (4U)                                                /**< FTM2_FLTCTRL.FFLTR0EN Position          */
#define FTM_FLTCTRL_FFLTR0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR0EN_SHIFT))&FTM_FLTCTRL_FFLTR0EN_MASK) /**< FTM2_FLTCTRL.FFLTR0EN Field             */
#define FTM_FLTCTRL_FFLTR1EN_MASK                (0x20U)                                             /**< FTM2_FLTCTRL.FFLTR1EN Mask              */
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               (5U)                                                /**< FTM2_FLTCTRL.FFLTR1EN Position          */
#define FTM_FLTCTRL_FFLTR1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR1EN_SHIFT))&FTM_FLTCTRL_FFLTR1EN_MASK) /**< FTM2_FLTCTRL.FFLTR1EN Field             */
#define FTM_FLTCTRL_FFLTR2EN_MASK                (0x40U)                                             /**< FTM2_FLTCTRL.FFLTR2EN Mask              */
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               (6U)                                                /**< FTM2_FLTCTRL.FFLTR2EN Position          */
#define FTM_FLTCTRL_FFLTR2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR2EN_SHIFT))&FTM_FLTCTRL_FFLTR2EN_MASK) /**< FTM2_FLTCTRL.FFLTR2EN Field             */
#define FTM_FLTCTRL_FFLTR3EN_MASK                (0x80U)                                             /**< FTM2_FLTCTRL.FFLTR3EN Mask              */
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               (7U)                                                /**< FTM2_FLTCTRL.FFLTR3EN Position          */
#define FTM_FLTCTRL_FFLTR3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR3EN_SHIFT))&FTM_FLTCTRL_FFLTR3EN_MASK) /**< FTM2_FLTCTRL.FFLTR3EN Field             */
#define FTM_FLTCTRL_FFVAL_MASK                   (0xF00U)                                            /**< FTM2_FLTCTRL.FFVAL Mask                 */
#define FTM_FLTCTRL_FFVAL_SHIFT                  (8U)                                                /**< FTM2_FLTCTRL.FFVAL Position             */
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK) /**< FTM2_FLTCTRL.FFVAL Field                */
/** @} */

/** @name CONF - Configuration */ /** @{ */
#define FTM_CONF_NUMTOF_MASK                     (0x1FU)                                             /**< FTM2_CONF.NUMTOF Mask                   */
#define FTM_CONF_NUMTOF_SHIFT                    (0U)                                                /**< FTM2_CONF.NUMTOF Position               */
#define FTM_CONF_NUMTOF(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_NUMTOF_SHIFT))&FTM_CONF_NUMTOF_MASK) /**< FTM2_CONF.NUMTOF Field                  */
#define FTM_CONF_BDMMODE_MASK                    (0xC0U)                                             /**< FTM2_CONF.BDMMODE Mask                  */
#define FTM_CONF_BDMMODE_SHIFT                   (6U)                                                /**< FTM2_CONF.BDMMODE Position              */
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK) /**< FTM2_CONF.BDMMODE Field                 */
#define FTM_CONF_GTBEEN_MASK                     (0x200U)                                            /**< FTM2_CONF.GTBEEN Mask                   */
#define FTM_CONF_GTBEEN_SHIFT                    (9U)                                                /**< FTM2_CONF.GTBEEN Position               */
#define FTM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEEN_SHIFT))&FTM_CONF_GTBEEN_MASK) /**< FTM2_CONF.GTBEEN Field                  */
#define FTM_CONF_GTBEOUT_MASK                    (0x400U)                                            /**< FTM2_CONF.GTBEOUT Mask                  */
#define FTM_CONF_GTBEOUT_SHIFT                   (10U)                                               /**< FTM2_CONF.GTBEOUT Position              */
#define FTM_CONF_GTBEOUT(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEOUT_SHIFT))&FTM_CONF_GTBEOUT_MASK) /**< FTM2_CONF.GTBEOUT Field                 */
/** @} */

/** @name FLTPOL - FTM Fault Input Polarity */ /** @{ */
#define FTM_FLTPOL_FLTPOL_MASK                   (0xFU)                                              /**< FTM2_FLTPOL.FLTPOL Mask                 */
#define FTM_FLTPOL_FLTPOL_SHIFT                  (0U)                                                /**< FTM2_FLTPOL.FLTPOL Position             */
#define FTM_FLTPOL_FLTPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLTPOL_SHIFT))&FTM_FLTPOL_FLTPOL_MASK) /**< FTM2_FLTPOL.FLTPOL Field                */
#define FTM_FLTPOL_FLT0POL_MASK                  (0x1U)                                              /**< FTM2_FLTPOL.FLT0POL Mask                */
#define FTM_FLTPOL_FLT0POL_SHIFT                 (0U)                                                /**< FTM2_FLTPOL.FLT0POL Position            */
#define FTM_FLTPOL_FLT0POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT0POL_SHIFT))&FTM_FLTPOL_FLT0POL_MASK) /**< FTM2_FLTPOL.FLT0POL Field               */
#define FTM_FLTPOL_FLT1POL_MASK                  (0x2U)                                              /**< FTM2_FLTPOL.FLT1POL Mask                */
#define FTM_FLTPOL_FLT1POL_SHIFT                 (1U)                                                /**< FTM2_FLTPOL.FLT1POL Position            */
#define FTM_FLTPOL_FLT1POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT1POL_SHIFT))&FTM_FLTPOL_FLT1POL_MASK) /**< FTM2_FLTPOL.FLT1POL Field               */
#define FTM_FLTPOL_FLT2POL_MASK                  (0x4U)                                              /**< FTM2_FLTPOL.FLT2POL Mask                */
#define FTM_FLTPOL_FLT2POL_SHIFT                 (2U)                                                /**< FTM2_FLTPOL.FLT2POL Position            */
#define FTM_FLTPOL_FLT2POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT2POL_SHIFT))&FTM_FLTPOL_FLT2POL_MASK) /**< FTM2_FLTPOL.FLT2POL Field               */
#define FTM_FLTPOL_FLT3POL_MASK                  (0x8U)                                              /**< FTM2_FLTPOL.FLT3POL Mask                */
#define FTM_FLTPOL_FLT3POL_SHIFT                 (3U)                                                /**< FTM2_FLTPOL.FLT3POL Position            */
#define FTM_FLTPOL_FLT3POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT3POL_SHIFT))&FTM_FLTPOL_FLT3POL_MASK) /**< FTM2_FLTPOL.FLT3POL Field               */
/** @} */

/** @name SYNCONF - Synchronization Configuration */ /** @{ */
#define FTM_SYNCONF_HWTRIGMODE_MASK              (0x1U)                                              /**< FTM2_SYNCONF.HWTRIGMODE Mask            */
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             (0U)                                                /**< FTM2_SYNCONF.HWTRIGMODE Position        */
#define FTM_SYNCONF_HWTRIGMODE(x)                (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWTRIGMODE_SHIFT))&FTM_SYNCONF_HWTRIGMODE_MASK) /**< FTM2_SYNCONF.HWTRIGMODE Field           */
#define FTM_SYNCONF_CNTINC_MASK                  (0x4U)                                              /**< FTM2_SYNCONF.CNTINC Mask                */
#define FTM_SYNCONF_CNTINC_SHIFT                 (2U)                                                /**< FTM2_SYNCONF.CNTINC Position            */
#define FTM_SYNCONF_CNTINC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_CNTINC_SHIFT))&FTM_SYNCONF_CNTINC_MASK) /**< FTM2_SYNCONF.CNTINC Field               */
#define FTM_SYNCONF_INVC_MASK                    (0x10U)                                             /**< FTM2_SYNCONF.INVC Mask                  */
#define FTM_SYNCONF_INVC_SHIFT                   (4U)                                                /**< FTM2_SYNCONF.INVC Position              */
#define FTM_SYNCONF_INVC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_INVC_SHIFT))&FTM_SYNCONF_INVC_MASK) /**< FTM2_SYNCONF.INVC Field                 */
#define FTM_SYNCONF_SWOC_MASK                    (0x20U)                                             /**< FTM2_SYNCONF.SWOC Mask                  */
#define FTM_SYNCONF_SWOC_SHIFT                   (5U)                                                /**< FTM2_SYNCONF.SWOC Position              */
#define FTM_SYNCONF_SWOC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOC_SHIFT))&FTM_SYNCONF_SWOC_MASK) /**< FTM2_SYNCONF.SWOC Field                 */
#define FTM_SYNCONF_SYNCMODE_MASK                (0x80U)                                             /**< FTM2_SYNCONF.SYNCMODE Mask              */
#define FTM_SYNCONF_SYNCMODE_SHIFT               (7U)                                                /**< FTM2_SYNCONF.SYNCMODE Position          */
#define FTM_SYNCONF_SYNCMODE(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SYNCMODE_SHIFT))&FTM_SYNCONF_SYNCMODE_MASK) /**< FTM2_SYNCONF.SYNCMODE Field             */
#define FTM_SYNCONF_SWRSTCNT_MASK                (0x100U)                                            /**< FTM2_SYNCONF.SWRSTCNT Mask              */
#define FTM_SYNCONF_SWRSTCNT_SHIFT               (8U)                                                /**< FTM2_SYNCONF.SWRSTCNT Position          */
#define FTM_SYNCONF_SWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWRSTCNT_SHIFT))&FTM_SYNCONF_SWRSTCNT_MASK) /**< FTM2_SYNCONF.SWRSTCNT Field             */
#define FTM_SYNCONF_SWWRBUF_MASK                 (0x200U)                                            /**< FTM2_SYNCONF.SWWRBUF Mask               */
#define FTM_SYNCONF_SWWRBUF_SHIFT                (9U)                                                /**< FTM2_SYNCONF.SWWRBUF Position           */
#define FTM_SYNCONF_SWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWWRBUF_SHIFT))&FTM_SYNCONF_SWWRBUF_MASK) /**< FTM2_SYNCONF.SWWRBUF Field              */
#define FTM_SYNCONF_SWOM_MASK                    (0x400U)                                            /**< FTM2_SYNCONF.SWOM Mask                  */
#define FTM_SYNCONF_SWOM_SHIFT                   (10U)                                               /**< FTM2_SYNCONF.SWOM Position              */
#define FTM_SYNCONF_SWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOM_SHIFT))&FTM_SYNCONF_SWOM_MASK) /**< FTM2_SYNCONF.SWOM Field                 */
#define FTM_SYNCONF_SWINVC_MASK                  (0x800U)                                            /**< FTM2_SYNCONF.SWINVC Mask                */
#define FTM_SYNCONF_SWINVC_SHIFT                 (11U)                                               /**< FTM2_SYNCONF.SWINVC Position            */
#define FTM_SYNCONF_SWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWINVC_SHIFT))&FTM_SYNCONF_SWINVC_MASK) /**< FTM2_SYNCONF.SWINVC Field               */
#define FTM_SYNCONF_SWSOC_MASK                   (0x1000U)                                           /**< FTM2_SYNCONF.SWSOC Mask                 */
#define FTM_SYNCONF_SWSOC_SHIFT                  (12U)                                               /**< FTM2_SYNCONF.SWSOC Position             */
#define FTM_SYNCONF_SWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWSOC_SHIFT))&FTM_SYNCONF_SWSOC_MASK) /**< FTM2_SYNCONF.SWSOC Field                */
#define FTM_SYNCONF_HWRSTCNT_MASK                (0x10000U)                                          /**< FTM2_SYNCONF.HWRSTCNT Mask              */
#define FTM_SYNCONF_HWRSTCNT_SHIFT               (16U)                                               /**< FTM2_SYNCONF.HWRSTCNT Position          */
#define FTM_SYNCONF_HWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWRSTCNT_SHIFT))&FTM_SYNCONF_HWRSTCNT_MASK) /**< FTM2_SYNCONF.HWRSTCNT Field             */
#define FTM_SYNCONF_HWWRBUF_MASK                 (0x20000U)                                          /**< FTM2_SYNCONF.HWWRBUF Mask               */
#define FTM_SYNCONF_HWWRBUF_SHIFT                (17U)                                               /**< FTM2_SYNCONF.HWWRBUF Position           */
#define FTM_SYNCONF_HWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWWRBUF_SHIFT))&FTM_SYNCONF_HWWRBUF_MASK) /**< FTM2_SYNCONF.HWWRBUF Field              */
#define FTM_SYNCONF_HWOM_MASK                    (0x40000U)                                          /**< FTM2_SYNCONF.HWOM Mask                  */
#define FTM_SYNCONF_HWOM_SHIFT                   (18U)                                               /**< FTM2_SYNCONF.HWOM Position              */
#define FTM_SYNCONF_HWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWOM_SHIFT))&FTM_SYNCONF_HWOM_MASK) /**< FTM2_SYNCONF.HWOM Field                 */
#define FTM_SYNCONF_HWINVC_MASK                  (0x80000U)                                          /**< FTM2_SYNCONF.HWINVC Mask                */
#define FTM_SYNCONF_HWINVC_SHIFT                 (19U)                                               /**< FTM2_SYNCONF.HWINVC Position            */
#define FTM_SYNCONF_HWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWINVC_SHIFT))&FTM_SYNCONF_HWINVC_MASK) /**< FTM2_SYNCONF.HWINVC Field               */
#define FTM_SYNCONF_HWSOC_MASK                   (0x100000U)                                         /**< FTM2_SYNCONF.HWSOC Mask                 */
#define FTM_SYNCONF_HWSOC_SHIFT                  (20U)                                               /**< FTM2_SYNCONF.HWSOC Position             */
#define FTM_SYNCONF_HWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWSOC_SHIFT))&FTM_SYNCONF_HWSOC_MASK) /**< FTM2_SYNCONF.HWSOC Field                */
/** @} */

/** @name INVCTRL - FTM Inverting Control */ /** @{ */
#define FTM_INVCTRL_INVEN_MASK                   (0xFU)                                              /**< FTM2_INVCTRL.INVEN Mask                 */
#define FTM_INVCTRL_INVEN_SHIFT                  (0U)                                                /**< FTM2_INVCTRL.INVEN Position             */
#define FTM_INVCTRL_INVEN(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INVEN_SHIFT))&FTM_INVCTRL_INVEN_MASK) /**< FTM2_INVCTRL.INVEN Field                */
#define FTM_INVCTRL_INV0EN_MASK                  (0x1U)                                              /**< FTM2_INVCTRL.INV0EN Mask                */
#define FTM_INVCTRL_INV0EN_SHIFT                 (0U)                                                /**< FTM2_INVCTRL.INV0EN Position            */
#define FTM_INVCTRL_INV0EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV0EN_SHIFT))&FTM_INVCTRL_INV0EN_MASK) /**< FTM2_INVCTRL.INV0EN Field               */
#define FTM_INVCTRL_INV1EN_MASK                  (0x2U)                                              /**< FTM2_INVCTRL.INV1EN Mask                */
#define FTM_INVCTRL_INV1EN_SHIFT                 (1U)                                                /**< FTM2_INVCTRL.INV1EN Position            */
#define FTM_INVCTRL_INV1EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV1EN_SHIFT))&FTM_INVCTRL_INV1EN_MASK) /**< FTM2_INVCTRL.INV1EN Field               */
#define FTM_INVCTRL_INV2EN_MASK                  (0x4U)                                              /**< FTM2_INVCTRL.INV2EN Mask                */
#define FTM_INVCTRL_INV2EN_SHIFT                 (2U)                                                /**< FTM2_INVCTRL.INV2EN Position            */
#define FTM_INVCTRL_INV2EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV2EN_SHIFT))&FTM_INVCTRL_INV2EN_MASK) /**< FTM2_INVCTRL.INV2EN Field               */
/** @} */

/** @name SWOCTRL - FTM Software Output Control */ /** @{ */
#define FTM_SWOCTRL_CHOC_MASK                    (0xFFU)                                             /**< FTM2_SWOCTRL.CHOC Mask                  */
#define FTM_SWOCTRL_CHOC_SHIFT                   (0U)                                                /**< FTM2_SWOCTRL.CHOC Position              */
#define FTM_SWOCTRL_CHOC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CHOC_SHIFT))&FTM_SWOCTRL_CHOC_MASK) /**< FTM2_SWOCTRL.CHOC Field                 */
#define FTM_SWOCTRL_CH0OC_MASK                   (0x1U)                                              /**< FTM2_SWOCTRL.CH0OC Mask                 */
#define FTM_SWOCTRL_CH0OC_SHIFT                  (0U)                                                /**< FTM2_SWOCTRL.CH0OC Position             */
#define FTM_SWOCTRL_CH0OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OC_SHIFT))&FTM_SWOCTRL_CH0OC_MASK) /**< FTM2_SWOCTRL.CH0OC Field                */
#define FTM_SWOCTRL_CH1OC_MASK                   (0x2U)                                              /**< FTM2_SWOCTRL.CH1OC Mask                 */
#define FTM_SWOCTRL_CH1OC_SHIFT                  (1U)                                                /**< FTM2_SWOCTRL.CH1OC Position             */
#define FTM_SWOCTRL_CH1OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OC_SHIFT))&FTM_SWOCTRL_CH1OC_MASK) /**< FTM2_SWOCTRL.CH1OC Field                */
#define FTM_SWOCTRL_CH2OC_MASK                   (0x4U)                                              /**< FTM2_SWOCTRL.CH2OC Mask                 */
#define FTM_SWOCTRL_CH2OC_SHIFT                  (2U)                                                /**< FTM2_SWOCTRL.CH2OC Position             */
#define FTM_SWOCTRL_CH2OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OC_SHIFT))&FTM_SWOCTRL_CH2OC_MASK) /**< FTM2_SWOCTRL.CH2OC Field                */
#define FTM_SWOCTRL_CH3OC_MASK                   (0x8U)                                              /**< FTM2_SWOCTRL.CH3OC Mask                 */
#define FTM_SWOCTRL_CH3OC_SHIFT                  (3U)                                                /**< FTM2_SWOCTRL.CH3OC Position             */
#define FTM_SWOCTRL_CH3OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OC_SHIFT))&FTM_SWOCTRL_CH3OC_MASK) /**< FTM2_SWOCTRL.CH3OC Field                */
#define FTM_SWOCTRL_CH4OC_MASK                   (0x10U)                                             /**< FTM2_SWOCTRL.CH4OC Mask                 */
#define FTM_SWOCTRL_CH4OC_SHIFT                  (4U)                                                /**< FTM2_SWOCTRL.CH4OC Position             */
#define FTM_SWOCTRL_CH4OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OC_SHIFT))&FTM_SWOCTRL_CH4OC_MASK) /**< FTM2_SWOCTRL.CH4OC Field                */
#define FTM_SWOCTRL_CH5OC_MASK                   (0x20U)                                             /**< FTM2_SWOCTRL.CH5OC Mask                 */
#define FTM_SWOCTRL_CH5OC_SHIFT                  (5U)                                                /**< FTM2_SWOCTRL.CH5OC Position             */
#define FTM_SWOCTRL_CH5OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OC_SHIFT))&FTM_SWOCTRL_CH5OC_MASK) /**< FTM2_SWOCTRL.CH5OC Field                */
#define FTM_SWOCTRL_CHOCV_MASK                   (0xFF00U)                                           /**< FTM2_SWOCTRL.CHOCV Mask                 */
#define FTM_SWOCTRL_CHOCV_SHIFT                  (8U)                                                /**< FTM2_SWOCTRL.CHOCV Position             */
#define FTM_SWOCTRL_CHOCV(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CHOCV_SHIFT))&FTM_SWOCTRL_CHOCV_MASK) /**< FTM2_SWOCTRL.CHOCV Field                */
#define FTM_SWOCTRL_CH0OCV_MASK                  (0x100U)                                            /**< FTM2_SWOCTRL.CH0OCV Mask                */
#define FTM_SWOCTRL_CH0OCV_SHIFT                 (8U)                                                /**< FTM2_SWOCTRL.CH0OCV Position            */
#define FTM_SWOCTRL_CH0OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OCV_SHIFT))&FTM_SWOCTRL_CH0OCV_MASK) /**< FTM2_SWOCTRL.CH0OCV Field               */
#define FTM_SWOCTRL_CH1OCV_MASK                  (0x200U)                                            /**< FTM2_SWOCTRL.CH1OCV Mask                */
#define FTM_SWOCTRL_CH1OCV_SHIFT                 (9U)                                                /**< FTM2_SWOCTRL.CH1OCV Position            */
#define FTM_SWOCTRL_CH1OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OCV_SHIFT))&FTM_SWOCTRL_CH1OCV_MASK) /**< FTM2_SWOCTRL.CH1OCV Field               */
#define FTM_SWOCTRL_CH2OCV_MASK                  (0x400U)                                            /**< FTM2_SWOCTRL.CH2OCV Mask                */
#define FTM_SWOCTRL_CH2OCV_SHIFT                 (10U)                                               /**< FTM2_SWOCTRL.CH2OCV Position            */
#define FTM_SWOCTRL_CH2OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OCV_SHIFT))&FTM_SWOCTRL_CH2OCV_MASK) /**< FTM2_SWOCTRL.CH2OCV Field               */
#define FTM_SWOCTRL_CH3OCV_MASK                  (0x800U)                                            /**< FTM2_SWOCTRL.CH3OCV Mask                */
#define FTM_SWOCTRL_CH3OCV_SHIFT                 (11U)                                               /**< FTM2_SWOCTRL.CH3OCV Position            */
#define FTM_SWOCTRL_CH3OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OCV_SHIFT))&FTM_SWOCTRL_CH3OCV_MASK) /**< FTM2_SWOCTRL.CH3OCV Field               */
#define FTM_SWOCTRL_CH4OCV_MASK                  (0x1000U)                                           /**< FTM2_SWOCTRL.CH4OCV Mask                */
#define FTM_SWOCTRL_CH4OCV_SHIFT                 (12U)                                               /**< FTM2_SWOCTRL.CH4OCV Position            */
#define FTM_SWOCTRL_CH4OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OCV_SHIFT))&FTM_SWOCTRL_CH4OCV_MASK) /**< FTM2_SWOCTRL.CH4OCV Field               */
#define FTM_SWOCTRL_CH5OCV_MASK                  (0x2000U)                                           /**< FTM2_SWOCTRL.CH5OCV Mask                */
#define FTM_SWOCTRL_CH5OCV_SHIFT                 (13U)                                               /**< FTM2_SWOCTRL.CH5OCV Position            */
#define FTM_SWOCTRL_CH5OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OCV_SHIFT))&FTM_SWOCTRL_CH5OCV_MASK) /**< FTM2_SWOCTRL.CH5OCV Field               */
/** @} */

/** @name PWMLOAD - FTM PWM Load */ /** @{ */
#define FTM_PWMLOAD_CHSEL_MASK                   (0xFFU)                                             /**< FTM2_PWMLOAD.CHSEL Mask                 */
#define FTM_PWMLOAD_CHSEL_SHIFT                  (0U)                                                /**< FTM2_PWMLOAD.CHSEL Position             */
#define FTM_PWMLOAD_CHSEL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CHSEL_SHIFT))&FTM_PWMLOAD_CHSEL_MASK) /**< FTM2_PWMLOAD.CHSEL Field                */
#define FTM_PWMLOAD_CH0SEL_MASK                  (0x1U)                                              /**< FTM2_PWMLOAD.CH0SEL Mask                */
#define FTM_PWMLOAD_CH0SEL_SHIFT                 (0U)                                                /**< FTM2_PWMLOAD.CH0SEL Position            */
#define FTM_PWMLOAD_CH0SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH0SEL_SHIFT))&FTM_PWMLOAD_CH0SEL_MASK) /**< FTM2_PWMLOAD.CH0SEL Field               */
#define FTM_PWMLOAD_CH1SEL_MASK                  (0x2U)                                              /**< FTM2_PWMLOAD.CH1SEL Mask                */
#define FTM_PWMLOAD_CH1SEL_SHIFT                 (1U)                                                /**< FTM2_PWMLOAD.CH1SEL Position            */
#define FTM_PWMLOAD_CH1SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH1SEL_SHIFT))&FTM_PWMLOAD_CH1SEL_MASK) /**< FTM2_PWMLOAD.CH1SEL Field               */
#define FTM_PWMLOAD_CH2SEL_MASK                  (0x4U)                                              /**< FTM2_PWMLOAD.CH2SEL Mask                */
#define FTM_PWMLOAD_CH2SEL_SHIFT                 (2U)                                                /**< FTM2_PWMLOAD.CH2SEL Position            */
#define FTM_PWMLOAD_CH2SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH2SEL_SHIFT))&FTM_PWMLOAD_CH2SEL_MASK) /**< FTM2_PWMLOAD.CH2SEL Field               */
#define FTM_PWMLOAD_CH3SEL_MASK                  (0x8U)                                              /**< FTM2_PWMLOAD.CH3SEL Mask                */
#define FTM_PWMLOAD_CH3SEL_SHIFT                 (3U)                                                /**< FTM2_PWMLOAD.CH3SEL Position            */
#define FTM_PWMLOAD_CH3SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH3SEL_SHIFT))&FTM_PWMLOAD_CH3SEL_MASK) /**< FTM2_PWMLOAD.CH3SEL Field               */
#define FTM_PWMLOAD_CH4SEL_MASK                  (0x10U)                                             /**< FTM2_PWMLOAD.CH4SEL Mask                */
#define FTM_PWMLOAD_CH4SEL_SHIFT                 (4U)                                                /**< FTM2_PWMLOAD.CH4SEL Position            */
#define FTM_PWMLOAD_CH4SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH4SEL_SHIFT))&FTM_PWMLOAD_CH4SEL_MASK) /**< FTM2_PWMLOAD.CH4SEL Field               */
#define FTM_PWMLOAD_CH5SEL_MASK                  (0x20U)                                             /**< FTM2_PWMLOAD.CH5SEL Mask                */
#define FTM_PWMLOAD_CH5SEL_SHIFT                 (5U)                                                /**< FTM2_PWMLOAD.CH5SEL Position            */
#define FTM_PWMLOAD_CH5SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH5SEL_SHIFT))&FTM_PWMLOAD_CH5SEL_MASK) /**< FTM2_PWMLOAD.CH5SEL Field               */
#define FTM_PWMLOAD_LDOK_MASK                    (0x200U)                                            /**< FTM2_PWMLOAD.LDOK Mask                  */
#define FTM_PWMLOAD_LDOK_SHIFT                   (9U)                                                /**< FTM2_PWMLOAD.LDOK Position              */
#define FTM_PWMLOAD_LDOK(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_LDOK_SHIFT))&FTM_PWMLOAD_LDOK_MASK) /**< FTM2_PWMLOAD.LDOK Field                 */
/** @} */

/** @} */ /* End group FTM_Register_Masks_GROUP */


/* FTM2 - Peripheral instance base addresses */
#define FTM2_BasePtr                   0x4003A000UL //!< Peripheral base address
#define FTM2                           ((FTM_Type *) FTM2_BasePtr) //!< Freescale base pointer
#define FTM2_BASE_PTR                  (FTM2) //!< Freescale style base pointer
#define FTM2_IRQS { FTM2_IRQn,  }


/** @} */ /* End group FTM_Peripheral_access_layer_GROUP */


/** @brief C Struct for FTMRH */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FTMRH_Peripheral_access_layer_GROUP FTMRH Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           FTMRH (file:FTMRH)                   ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
 * @struct FTMRH_Type
 * @brief  C Struct allowing access to FTMRH registers
 */
typedef struct FTMRH_Type {
   __IO uint8_t   FCLKDIV;                      /**< 0000: Flash Clock Divider Register                                 */
   __I  uint8_t   FSEC;                         /**< 0001: Flash Security Register                                      */
   __IO uint8_t   FCCOBIX;                      /**< 0002: Flash CCOB Index Register                                    */
        uint8_t   RESERVED_0;                   /**< 0003: 0x1 bytes                                                    */
   __IO uint8_t   FCNFG;                        /**< 0004: Flash Configuration Register                                 */
   __IO uint8_t   FERCNFG;                      /**< 0005: Flash Error Configuration Register                           */
   __IO uint8_t   FSTAT;                        /**< 0006: Flash Status Register                                        */
   __IO uint8_t   FERSTAT;                      /**< 0007: Flash Error Status Register                                  */
   __IO uint8_t   FPROT;                        /**< 0008: Flash Protection Register                                    */
   __IO uint8_t   EEPROT;                       /**< 0009: EEPROM Protection Register                                   */
   union {                                      /**< 000A: (size=0002)                                                  */
      __IO uint16_t  FCCOB;                     /**< 000A: Flash Common Command Object Register (FCCOBLO:FCCOBHI)       */
      struct {                                  /**< 000A: (size=0002)                                                  */
         __IO uint8_t   FCCOBHI;                /**< 000A: Flash Common Command Object Register:High                    */
         __IO uint8_t   FCCOBLO;                /**< 000B: Flash Common Command Object Register:Low                     */
      };
   };
   __I  uint8_t   FOPT;                         /**< 000C: Flash Option Register                                        */
} FTMRH_Type;


/** @brief Register Masks for FTMRH */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTMRH' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FTMRH_Register_Masks_GROUP FTMRH Register Masks */
/** @{ */

/** @name FCLKDIV - Flash Clock Divider Register  */ /** @{ */
#define FTMRH_FCLKDIV_FDIV_MASK                  (0x3FU)                                             /**< FTMRH_FCLKDIV.FDIV Mask                 */
#define FTMRH_FCLKDIV_FDIV_SHIFT                 (0U)                                                /**< FTMRH_FCLKDIV.FDIV Position             */
#define FTMRH_FCLKDIV_FDIV(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FCLKDIV_FDIV_SHIFT))&FTMRH_FCLKDIV_FDIV_MASK) /**< FTMRH_FCLKDIV.FDIV Field                */
#define FTMRH_FCLKDIV_FDIVLCK_MASK               (0x40U)                                             /**< FTMRH_FCLKDIV.FDIVLCK Mask              */
#define FTMRH_FCLKDIV_FDIVLCK_SHIFT              (6U)                                                /**< FTMRH_FCLKDIV.FDIVLCK Position          */
#define FTMRH_FCLKDIV_FDIVLCK(x)                 (((uint8_t)(((uint8_t)(x))<<FTMRH_FCLKDIV_FDIVLCK_SHIFT))&FTMRH_FCLKDIV_FDIVLCK_MASK) /**< FTMRH_FCLKDIV.FDIVLCK Field             */
#define FTMRH_FCLKDIV_FDIVLD_MASK                (0x80U)                                             /**< FTMRH_FCLKDIV.FDIVLD Mask               */
#define FTMRH_FCLKDIV_FDIVLD_SHIFT               (7U)                                                /**< FTMRH_FCLKDIV.FDIVLD Position           */
#define FTMRH_FCLKDIV_FDIVLD(x)                  (((uint8_t)(((uint8_t)(x))<<FTMRH_FCLKDIV_FDIVLD_SHIFT))&FTMRH_FCLKDIV_FDIVLD_MASK) /**< FTMRH_FCLKDIV.FDIVLD Field              */
/** @} */

/** @name FSEC - Flash Security Register  */ /** @{ */
#define FTMRH_FSEC_SEC_MASK                      (0x3U)                                              /**< FTMRH_FSEC.SEC Mask                     */
#define FTMRH_FSEC_SEC_SHIFT                     (0U)                                                /**< FTMRH_FSEC.SEC Position                 */
#define FTMRH_FSEC_SEC(x)                        (((uint8_t)(((uint8_t)(x))<<FTMRH_FSEC_SEC_SHIFT))&FTMRH_FSEC_SEC_MASK) /**< FTMRH_FSEC.SEC Field                    */
#define FTMRH_FSEC_KEYEN_MASK                    (0xC0U)                                             /**< FTMRH_FSEC.KEYEN Mask                   */
#define FTMRH_FSEC_KEYEN_SHIFT                   (6U)                                                /**< FTMRH_FSEC.KEYEN Position               */
#define FTMRH_FSEC_KEYEN(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FSEC_KEYEN_SHIFT))&FTMRH_FSEC_KEYEN_MASK) /**< FTMRH_FSEC.KEYEN Field                  */
/** @} */

/** @name FCCOBIX - Flash CCOB Index Register  */ /** @{ */
#define FTMRH_FCCOBIX_CCOBIX_MASK                (0x7U)                                              /**< FTMRH_FCCOBIX.CCOBIX Mask               */
#define FTMRH_FCCOBIX_CCOBIX_SHIFT               (0U)                                                /**< FTMRH_FCCOBIX.CCOBIX Position           */
#define FTMRH_FCCOBIX_CCOBIX(x)                  (((uint8_t)(((uint8_t)(x))<<FTMRH_FCCOBIX_CCOBIX_SHIFT))&FTMRH_FCCOBIX_CCOBIX_MASK) /**< FTMRH_FCCOBIX.CCOBIX Field              */
/** @} */

/** @name FCNFG - Flash Configuration Register  */ /** @{ */
#define FTMRH_FCNFG_FSFD_MASK                    (0x1U)                                              /**< FTMRH_FCNFG.FSFD Mask                   */
#define FTMRH_FCNFG_FSFD_SHIFT                   (0U)                                                /**< FTMRH_FCNFG.FSFD Position               */
#define FTMRH_FCNFG_FSFD(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FCNFG_FSFD_SHIFT))&FTMRH_FCNFG_FSFD_MASK) /**< FTMRH_FCNFG.FSFD Field                  */
#define FTMRH_FCNFG_FDFD_MASK                    (0x2U)                                              /**< FTMRH_FCNFG.FDFD Mask                   */
#define FTMRH_FCNFG_FDFD_SHIFT                   (1U)                                                /**< FTMRH_FCNFG.FDFD Position               */
#define FTMRH_FCNFG_FDFD(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FCNFG_FDFD_SHIFT))&FTMRH_FCNFG_FDFD_MASK) /**< FTMRH_FCNFG.FDFD Field                  */
#define FTMRH_FCNFG_IGNSF_MASK                   (0x10U)                                             /**< FTMRH_FCNFG.IGNSF Mask                  */
#define FTMRH_FCNFG_IGNSF_SHIFT                  (4U)                                                /**< FTMRH_FCNFG.IGNSF Position              */
#define FTMRH_FCNFG_IGNSF(x)                     (((uint8_t)(((uint8_t)(x))<<FTMRH_FCNFG_IGNSF_SHIFT))&FTMRH_FCNFG_IGNSF_MASK) /**< FTMRH_FCNFG.IGNSF Field                 */
#define FTMRH_FCNFG_CCIE_MASK                    (0x80U)                                             /**< FTMRH_FCNFG.CCIE Mask                   */
#define FTMRH_FCNFG_CCIE_SHIFT                   (7U)                                                /**< FTMRH_FCNFG.CCIE Position               */
#define FTMRH_FCNFG_CCIE(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FCNFG_CCIE_SHIFT))&FTMRH_FCNFG_CCIE_MASK) /**< FTMRH_FCNFG.CCIE Field                  */
/** @} */

/** @name FERCNFG - Flash Error Configuration Register  */ /** @{ */
#define FTMRH_FERCNFG_SFDIE_MASK                 (0x1U)                                              /**< FTMRH_FERCNFG.SFDIE Mask                */
#define FTMRH_FERCNFG_SFDIE_SHIFT                (0U)                                                /**< FTMRH_FERCNFG.SFDIE Position            */
#define FTMRH_FERCNFG_SFDIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRH_FERCNFG_SFDIE_SHIFT))&FTMRH_FERCNFG_SFDIE_MASK) /**< FTMRH_FERCNFG.SFDIE Field               */
#define FTMRH_FERCNFG_DFDIE_MASK                 (0x2U)                                              /**< FTMRH_FERCNFG.DFDIE Mask                */
#define FTMRH_FERCNFG_DFDIE_SHIFT                (1U)                                                /**< FTMRH_FERCNFG.DFDIE Position            */
#define FTMRH_FERCNFG_DFDIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRH_FERCNFG_DFDIE_SHIFT))&FTMRH_FERCNFG_DFDIE_MASK) /**< FTMRH_FERCNFG.DFDIE Field               */
/** @} */

/** @name FSTAT - Flash Status Register  */ /** @{ */
#define FTMRH_FSTAT_MGSTAT_MASK                  (0x3U)                                              /**< FTMRH_FSTAT.MGSTAT Mask                 */
#define FTMRH_FSTAT_MGSTAT_SHIFT                 (0U)                                                /**< FTMRH_FSTAT.MGSTAT Position             */
#define FTMRH_FSTAT_MGSTAT(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FSTAT_MGSTAT_SHIFT))&FTMRH_FSTAT_MGSTAT_MASK) /**< FTMRH_FSTAT.MGSTAT Field                */
#define FTMRH_FSTAT_MGBUSY_MASK                  (0x8U)                                              /**< FTMRH_FSTAT.MGBUSY Mask                 */
#define FTMRH_FSTAT_MGBUSY_SHIFT                 (3U)                                                /**< FTMRH_FSTAT.MGBUSY Position             */
#define FTMRH_FSTAT_MGBUSY(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FSTAT_MGBUSY_SHIFT))&FTMRH_FSTAT_MGBUSY_MASK) /**< FTMRH_FSTAT.MGBUSY Field                */
#define FTMRH_FSTAT_FPVIOL_MASK                  (0x10U)                                             /**< FTMRH_FSTAT.FPVIOL Mask                 */
#define FTMRH_FSTAT_FPVIOL_SHIFT                 (4U)                                                /**< FTMRH_FSTAT.FPVIOL Position             */
#define FTMRH_FSTAT_FPVIOL(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FSTAT_FPVIOL_SHIFT))&FTMRH_FSTAT_FPVIOL_MASK) /**< FTMRH_FSTAT.FPVIOL Field                */
#define FTMRH_FSTAT_ACCERR_MASK                  (0x20U)                                             /**< FTMRH_FSTAT.ACCERR Mask                 */
#define FTMRH_FSTAT_ACCERR_SHIFT                 (5U)                                                /**< FTMRH_FSTAT.ACCERR Position             */
#define FTMRH_FSTAT_ACCERR(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FSTAT_ACCERR_SHIFT))&FTMRH_FSTAT_ACCERR_MASK) /**< FTMRH_FSTAT.ACCERR Field                */
#define FTMRH_FSTAT_CCIF_MASK                    (0x80U)                                             /**< FTMRH_FSTAT.CCIF Mask                   */
#define FTMRH_FSTAT_CCIF_SHIFT                   (7U)                                                /**< FTMRH_FSTAT.CCIF Position               */
#define FTMRH_FSTAT_CCIF(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FSTAT_CCIF_SHIFT))&FTMRH_FSTAT_CCIF_MASK) /**< FTMRH_FSTAT.CCIF Field                  */
/** @} */

/** @name FERSTAT - Flash Error Status Register  */ /** @{ */
#define FTMRH_FERSTAT_SFDIF_MASK                 (0x1U)                                              /**< FTMRH_FERSTAT.SFDIF Mask                */
#define FTMRH_FERSTAT_SFDIF_SHIFT                (0U)                                                /**< FTMRH_FERSTAT.SFDIF Position            */
#define FTMRH_FERSTAT_SFDIF(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRH_FERSTAT_SFDIF_SHIFT))&FTMRH_FERSTAT_SFDIF_MASK) /**< FTMRH_FERSTAT.SFDIF Field               */
#define FTMRH_FERSTAT_DFDIF_MASK                 (0x2U)                                              /**< FTMRH_FERSTAT.DFDIF Mask                */
#define FTMRH_FERSTAT_DFDIF_SHIFT                (1U)                                                /**< FTMRH_FERSTAT.DFDIF Position            */
#define FTMRH_FERSTAT_DFDIF(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRH_FERSTAT_DFDIF_SHIFT))&FTMRH_FERSTAT_DFDIF_MASK) /**< FTMRH_FERSTAT.DFDIF Field               */
/** @} */

/** @name FPROT - Flash Protection Register  */ /** @{ */
#define FTMRH_FPROT_FPLS_MASK                    (0x3U)                                              /**< FTMRH_FPROT.FPLS Mask                   */
#define FTMRH_FPROT_FPLS_SHIFT                   (0U)                                                /**< FTMRH_FPROT.FPLS Position               */
#define FTMRH_FPROT_FPLS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FPROT_FPLS_SHIFT))&FTMRH_FPROT_FPLS_MASK) /**< FTMRH_FPROT.FPLS Field                  */
#define FTMRH_FPROT_FPLDIS_MASK                  (0x4U)                                              /**< FTMRH_FPROT.FPLDIS Mask                 */
#define FTMRH_FPROT_FPLDIS_SHIFT                 (2U)                                                /**< FTMRH_FPROT.FPLDIS Position             */
#define FTMRH_FPROT_FPLDIS(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FPROT_FPLDIS_SHIFT))&FTMRH_FPROT_FPLDIS_MASK) /**< FTMRH_FPROT.FPLDIS Field                */
#define FTMRH_FPROT_FPHS_MASK                    (0x18U)                                             /**< FTMRH_FPROT.FPHS Mask                   */
#define FTMRH_FPROT_FPHS_SHIFT                   (3U)                                                /**< FTMRH_FPROT.FPHS Position               */
#define FTMRH_FPROT_FPHS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FPROT_FPHS_SHIFT))&FTMRH_FPROT_FPHS_MASK) /**< FTMRH_FPROT.FPHS Field                  */
#define FTMRH_FPROT_FPHDIS_MASK                  (0x20U)                                             /**< FTMRH_FPROT.FPHDIS Mask                 */
#define FTMRH_FPROT_FPHDIS_SHIFT                 (5U)                                                /**< FTMRH_FPROT.FPHDIS Position             */
#define FTMRH_FPROT_FPHDIS(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FPROT_FPHDIS_SHIFT))&FTMRH_FPROT_FPHDIS_MASK) /**< FTMRH_FPROT.FPHDIS Field                */
#define FTMRH_FPROT_FPOPEN_MASK                  (0x80U)                                             /**< FTMRH_FPROT.FPOPEN Mask                 */
#define FTMRH_FPROT_FPOPEN_SHIFT                 (7U)                                                /**< FTMRH_FPROT.FPOPEN Position             */
#define FTMRH_FPROT_FPOPEN(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FPROT_FPOPEN_SHIFT))&FTMRH_FPROT_FPOPEN_MASK) /**< FTMRH_FPROT.FPOPEN Field                */
/** @} */

/** @name EEPROT - EEPROM Protection Register  */ /** @{ */
#define FTMRH_EEPROT_DPS_MASK                    (0x7U)                                              /**< FTMRH_EEPROT.DPS Mask                   */
#define FTMRH_EEPROT_DPS_SHIFT                   (0U)                                                /**< FTMRH_EEPROT.DPS Position               */
#define FTMRH_EEPROT_DPS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_EEPROT_DPS_SHIFT))&FTMRH_EEPROT_DPS_MASK) /**< FTMRH_EEPROT.DPS Field                  */
#define FTMRH_EEPROT_DPOPEN_MASK                 (0x80U)                                             /**< FTMRH_EEPROT.DPOPEN Mask                */
#define FTMRH_EEPROT_DPOPEN_SHIFT                (7U)                                                /**< FTMRH_EEPROT.DPOPEN Position            */
#define FTMRH_EEPROT_DPOPEN(x)                   (((uint8_t)(((uint8_t)(x))<<FTMRH_EEPROT_DPOPEN_SHIFT))&FTMRH_EEPROT_DPOPEN_MASK) /**< FTMRH_EEPROT.DPOPEN Field               */
/** @} */

/** @} */ /* End group FTMRH_Register_Masks_GROUP */


/* FTMRH - Peripheral instance base addresses */
#define FTMRH_BasePtr                  0x40020000UL //!< Peripheral base address
#define FTMRH                          ((FTMRH_Type *) FTMRH_BasePtr) //!< Freescale base pointer
#define FTMRH_BASE_PTR                 (FTMRH) //!< Freescale style base pointer
#define FTMRH_IRQS { FTMRH_IRQn,  }


/** @} */ /* End group FTMRH_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIOA */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIOA_Peripheral_access_layer_GROUP FGPIOA Peripheral Access Layer */
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

/** @} */ /* End group FGPIOA_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIOB */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIOB_Peripheral_access_layer_GROUP FGPIOB Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOB (derived from FGPIOB)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x400FF040UL //!< Peripheral base address
#define GPIOB                          ((FGPIOB_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer

/** @} */ /* End group FGPIOB_Peripheral_access_layer_GROUP */


/** @brief C Struct for FGPIOC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FGPIOC_Peripheral_access_layer_GROUP FGPIOC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOC (derived from FGPIOC)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x400FF080UL //!< Peripheral base address
#define GPIOC                          ((FGPIOC_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer

/** @} */ /* End group FGPIOC_Peripheral_access_layer_GROUP */


/** @brief C Struct for I2C */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MKE)                 ================ */
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

/** @} */ /* End group I2C_Register_Masks_GROUP */


/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40066000UL //!< Peripheral base address
#define I2C0                           ((I2C_Type *) I2C0_BasePtr) //!< Freescale base pointer
#define I2C0_BASE_PTR                  (I2C0) //!< Freescale style base pointer
#define I2C0_IRQS { I2C0_IRQn,  }


/** @} */ /* End group I2C_Peripheral_access_layer_GROUP */


/** @brief C Struct for ICS */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup ICS_Peripheral_access_layer_GROUP ICS Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           ICS (file:ICS_MKE)                   ================ */
/* ================================================================================ */

/**
 * @brief Internal clock source
 */
/**
 * @struct ICS_Type
 * @brief  C Struct allowing access to ICS registers
 */
typedef struct ICS_Type {
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /**< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /**< 0003: Control 4 Register                                           */
   __I  uint8_t   S;                            /**< 0004: ICS Status Register                                          */
} ICS_Type;


/** @brief Register Masks for ICS */

/* -------------------------------------------------------------------------------- */
/* -----------     'ICS' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup ICS_Register_Masks_GROUP ICS Register Masks */
/** @{ */

/** @name C1 - Control 1 Register */ /** @{ */
#define ICS_C1_IREFSTEN_MASK                     (0x1U)                                              /**< ICS_C1.IREFSTEN Mask                    */
#define ICS_C1_IREFSTEN_SHIFT                    (0U)                                                /**< ICS_C1.IREFSTEN Position                */
#define ICS_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<ICS_C1_IREFSTEN_SHIFT))&ICS_C1_IREFSTEN_MASK) /**< ICS_C1.IREFSTEN Field                   */
#define ICS_C1_IRCLKEN_MASK                      (0x2U)                                              /**< ICS_C1.IRCLKEN Mask                     */
#define ICS_C1_IRCLKEN_SHIFT                     (1U)                                                /**< ICS_C1.IRCLKEN Position                 */
#define ICS_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<ICS_C1_IRCLKEN_SHIFT))&ICS_C1_IRCLKEN_MASK) /**< ICS_C1.IRCLKEN Field                    */
#define ICS_C1_IREFS_MASK                        (0x4U)                                              /**< ICS_C1.IREFS Mask                       */
#define ICS_C1_IREFS_SHIFT                       (2U)                                                /**< ICS_C1.IREFS Position                   */
#define ICS_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x))<<ICS_C1_IREFS_SHIFT))&ICS_C1_IREFS_MASK) /**< ICS_C1.IREFS Field                      */
#define ICS_C1_RDIV_MASK                         (0x38U)                                             /**< ICS_C1.RDIV Mask                        */
#define ICS_C1_RDIV_SHIFT                        (3U)                                                /**< ICS_C1.RDIV Position                    */
#define ICS_C1_RDIV(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C1_RDIV_SHIFT))&ICS_C1_RDIV_MASK) /**< ICS_C1.RDIV Field                       */
#define ICS_C1_CLKS_MASK                         (0xC0U)                                             /**< ICS_C1.CLKS Mask                        */
#define ICS_C1_CLKS_SHIFT                        (6U)                                                /**< ICS_C1.CLKS Position                    */
#define ICS_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C1_CLKS_SHIFT))&ICS_C1_CLKS_MASK) /**< ICS_C1.CLKS Field                       */
/** @} */

/** @name C2 - Control 2 Register */ /** @{ */
#define ICS_C2_LP_MASK                           (0x10U)                                             /**< ICS_C2.LP Mask                          */
#define ICS_C2_LP_SHIFT                          (4U)                                                /**< ICS_C2.LP Position                      */
#define ICS_C2_LP(x)                             (((uint8_t)(((uint8_t)(x))<<ICS_C2_LP_SHIFT))&ICS_C2_LP_MASK) /**< ICS_C2.LP Field                         */
#define ICS_C2_BDIV_MASK                         (0xE0U)                                             /**< ICS_C2.BDIV Mask                        */
#define ICS_C2_BDIV_SHIFT                        (5U)                                                /**< ICS_C2.BDIV Position                    */
#define ICS_C2_BDIV(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C2_BDIV_SHIFT))&ICS_C2_BDIV_MASK) /**< ICS_C2.BDIV Field                       */
/** @} */

/** @name C3 - Control 3 Register */ /** @{ */
#define ICS_C3_SCTRIM_MASK                       (0xFFU)                                             /**< ICS_C3.SCTRIM Mask                      */
#define ICS_C3_SCTRIM_SHIFT                      (0U)                                                /**< ICS_C3.SCTRIM Position                  */
#define ICS_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<ICS_C3_SCTRIM_SHIFT))&ICS_C3_SCTRIM_MASK) /**< ICS_C3.SCTRIM Field                     */
/** @} */

/** @name C4 - Control 4 Register */ /** @{ */
#define ICS_C4_SCFTRIM_MASK                      (0x1U)                                              /**< ICS_C4.SCFTRIM Mask                     */
#define ICS_C4_SCFTRIM_SHIFT                     (0U)                                                /**< ICS_C4.SCFTRIM Position                 */
#define ICS_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<ICS_C4_SCFTRIM_SHIFT))&ICS_C4_SCFTRIM_MASK) /**< ICS_C4.SCFTRIM Field                    */
#define ICS_C4_CME_MASK                          (0x20U)                                             /**< ICS_C4.CME Mask                         */
#define ICS_C4_CME_SHIFT                         (5U)                                                /**< ICS_C4.CME Position                     */
#define ICS_C4_CME(x)                            (((uint8_t)(((uint8_t)(x))<<ICS_C4_CME_SHIFT))&ICS_C4_CME_MASK) /**< ICS_C4.CME Field                        */
#define ICS_C4_LOLIE0_MASK                       (0x80U)                                             /**< ICS_C4.LOLIE0 Mask                      */
#define ICS_C4_LOLIE0_SHIFT                      (7U)                                                /**< ICS_C4.LOLIE0 Position                  */
#define ICS_C4_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x))<<ICS_C4_LOLIE0_SHIFT))&ICS_C4_LOLIE0_MASK) /**< ICS_C4.LOLIE0 Field                     */
/** @} */

/** @name S - ICS Status Register */ /** @{ */
#define ICS_S_CLKST_MASK                         (0xCU)                                              /**< ICS_S.CLKST Mask                        */
#define ICS_S_CLKST_SHIFT                        (2U)                                                /**< ICS_S.CLKST Position                    */
#define ICS_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_S_CLKST_SHIFT))&ICS_S_CLKST_MASK) /**< ICS_S.CLKST Field                       */
#define ICS_S_IREFST_MASK                        (0x10U)                                             /**< ICS_S.IREFST Mask                       */
#define ICS_S_IREFST_SHIFT                       (4U)                                                /**< ICS_S.IREFST Position                   */
#define ICS_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x))<<ICS_S_IREFST_SHIFT))&ICS_S_IREFST_MASK) /**< ICS_S.IREFST Field                      */
#define ICS_S_LOCK_MASK                          (0x40U)                                             /**< ICS_S.LOCK Mask                         */
#define ICS_S_LOCK_SHIFT                         (6U)                                                /**< ICS_S.LOCK Position                     */
#define ICS_S_LOCK(x)                            (((uint8_t)(((uint8_t)(x))<<ICS_S_LOCK_SHIFT))&ICS_S_LOCK_MASK) /**< ICS_S.LOCK Field                        */
#define ICS_S_LOLS_MASK                          (0x80U)                                             /**< ICS_S.LOLS Mask                         */
#define ICS_S_LOLS_SHIFT                         (7U)                                                /**< ICS_S.LOLS Position                     */
#define ICS_S_LOLS(x)                            (((uint8_t)(((uint8_t)(x))<<ICS_S_LOLS_SHIFT))&ICS_S_LOLS_MASK) /**< ICS_S.LOLS Field                        */
/** @} */

/** @} */ /* End group ICS_Register_Masks_GROUP */


/* ICS - Peripheral instance base addresses */
#define ICS_BasePtr                    0x40064000UL //!< Peripheral base address
#define ICS                            ((ICS_Type *) ICS_BasePtr) //!< Freescale base pointer
#define ICS_BASE_PTR                   (ICS) //!< Freescale style base pointer
#define ICS_IRQS { ICS_IRQn,  }


/** @} */ /* End group ICS_Peripheral_access_layer_GROUP */


/** @brief C Struct for IRQ */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup IRQ_Peripheral_access_layer_GROUP IRQ Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           IRQ (file:IRQ_MKE)                   ================ */
/* ================================================================================ */

/**
 * @brief Interrupt
 */
/**
 * @struct IRQ_Type
 * @brief  C Struct allowing access to IRQ registers
 */
typedef struct IRQ_Type {
   __IO uint8_t   SC;                           /**< 0000: Interrupt Pin Request Status and Control Register            */
} IRQ_Type;


/** @brief Register Masks for IRQ */

/* -------------------------------------------------------------------------------- */
/* -----------     'IRQ' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup IRQ_Register_Masks_GROUP IRQ Register Masks */
/** @{ */

/** @name SC - Interrupt Pin Request Status and Control Register */ /** @{ */
#define IRQ_SC_IRQMOD_MASK                       (0x1U)                                              /**< IRQ_SC.IRQMOD Mask                      */
#define IRQ_SC_IRQMOD_SHIFT                      (0U)                                                /**< IRQ_SC.IRQMOD Position                  */
#define IRQ_SC_IRQMOD(x)                         (((uint8_t)(((uint8_t)(x))<<IRQ_SC_IRQMOD_SHIFT))&IRQ_SC_IRQMOD_MASK) /**< IRQ_SC.IRQMOD Field                     */
#define IRQ_SC_IRQIE_MASK                        (0x2U)                                              /**< IRQ_SC.IRQIE Mask                       */
#define IRQ_SC_IRQIE_SHIFT                       (1U)                                                /**< IRQ_SC.IRQIE Position                   */
#define IRQ_SC_IRQIE(x)                          (((uint8_t)(((uint8_t)(x))<<IRQ_SC_IRQIE_SHIFT))&IRQ_SC_IRQIE_MASK) /**< IRQ_SC.IRQIE Field                      */
#define IRQ_SC_IRQACK_MASK                       (0x4U)                                              /**< IRQ_SC.IRQACK Mask                      */
#define IRQ_SC_IRQACK_SHIFT                      (2U)                                                /**< IRQ_SC.IRQACK Position                  */
#define IRQ_SC_IRQACK(x)                         (((uint8_t)(((uint8_t)(x))<<IRQ_SC_IRQACK_SHIFT))&IRQ_SC_IRQACK_MASK) /**< IRQ_SC.IRQACK Field                     */
#define IRQ_SC_IRQF_MASK                         (0x8U)                                              /**< IRQ_SC.IRQF Mask                        */
#define IRQ_SC_IRQF_SHIFT                        (3U)                                                /**< IRQ_SC.IRQF Position                    */
#define IRQ_SC_IRQF(x)                           (((uint8_t)(((uint8_t)(x))<<IRQ_SC_IRQF_SHIFT))&IRQ_SC_IRQF_MASK) /**< IRQ_SC.IRQF Field                       */
#define IRQ_SC_IRQPE_MASK                        (0x10U)                                             /**< IRQ_SC.IRQPE Mask                       */
#define IRQ_SC_IRQPE_SHIFT                       (4U)                                                /**< IRQ_SC.IRQPE Position                   */
#define IRQ_SC_IRQPE(x)                          (((uint8_t)(((uint8_t)(x))<<IRQ_SC_IRQPE_SHIFT))&IRQ_SC_IRQPE_MASK) /**< IRQ_SC.IRQPE Field                      */
#define IRQ_SC_IRQEDG_MASK                       (0x20U)                                             /**< IRQ_SC.IRQEDG Mask                      */
#define IRQ_SC_IRQEDG_SHIFT                      (5U)                                                /**< IRQ_SC.IRQEDG Position                  */
#define IRQ_SC_IRQEDG(x)                         (((uint8_t)(((uint8_t)(x))<<IRQ_SC_IRQEDG_SHIFT))&IRQ_SC_IRQEDG_MASK) /**< IRQ_SC.IRQEDG Field                     */
#define IRQ_SC_IRQPDD_MASK                       (0x40U)                                             /**< IRQ_SC.IRQPDD Mask                      */
#define IRQ_SC_IRQPDD_SHIFT                      (6U)                                                /**< IRQ_SC.IRQPDD Position                  */
#define IRQ_SC_IRQPDD(x)                         (((uint8_t)(((uint8_t)(x))<<IRQ_SC_IRQPDD_SHIFT))&IRQ_SC_IRQPDD_MASK) /**< IRQ_SC.IRQPDD Field                     */
/** @} */

/** @} */ /* End group IRQ_Register_Masks_GROUP */


/* IRQ - Peripheral instance base addresses */
#define IRQ_BasePtr                    0x40031000UL //!< Peripheral base address
#define IRQ                            ((IRQ_Type *) IRQ_BasePtr) //!< Freescale base pointer
#define IRQ_BASE_PTR                   (IRQ) //!< Freescale style base pointer
#define IRQ_IRQS { IRQ_IRQn,  }


/** @} */ /* End group IRQ_Peripheral_access_layer_GROUP */


/** @brief C Struct for KBI */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup KBI_Peripheral_access_layer_GROUP KBI Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           KBI0 (file:KBI0_MKE02)               ================ */
/* ================================================================================ */

/**
 * @brief Keyboard interrupts
 */
/**
 * @struct KBI_Type
 * @brief  C Struct allowing access to KBI registers
 */
typedef struct KBI_Type {
   __IO uint8_t   SC;                           /**< 0000: KBI Status and Control Register                              */
   __IO uint8_t   PE;                           /**< 0001: KBI Pin Enables                                              */
   __IO uint8_t   ES;                           /**< 0002: KBI Edge Selects                                             */
} KBI_Type;


/** @brief Register Masks for KBI */

/* -------------------------------------------------------------------------------- */
/* -----------     'KBI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup KBI_Register_Masks_GROUP KBI Register Masks */
/** @{ */

/** @name SC - KBI Status and Control Register */ /** @{ */
#define KBI_SC_KBMOD_MASK                        (0x1U)                                              /**< KBI0_SC.KBMOD Mask                      */
#define KBI_SC_KBMOD_SHIFT                       (0U)                                                /**< KBI0_SC.KBMOD Position                  */
#define KBI_SC_KBMOD(x)                          (((uint8_t)(((uint8_t)(x))<<KBI_SC_KBMOD_SHIFT))&KBI_SC_KBMOD_MASK) /**< KBI0_SC.KBMOD Field                     */
#define KBI_SC_KBIE_MASK                         (0x2U)                                              /**< KBI0_SC.KBIE Mask                       */
#define KBI_SC_KBIE_SHIFT                        (1U)                                                /**< KBI0_SC.KBIE Position                   */
#define KBI_SC_KBIE(x)                           (((uint8_t)(((uint8_t)(x))<<KBI_SC_KBIE_SHIFT))&KBI_SC_KBIE_MASK) /**< KBI0_SC.KBIE Field                      */
#define KBI_SC_KBACK_MASK                        (0x4U)                                              /**< KBI0_SC.KBACK Mask                      */
#define KBI_SC_KBACK_SHIFT                       (2U)                                                /**< KBI0_SC.KBACK Position                  */
#define KBI_SC_KBACK(x)                          (((uint8_t)(((uint8_t)(x))<<KBI_SC_KBACK_SHIFT))&KBI_SC_KBACK_MASK) /**< KBI0_SC.KBACK Field                     */
#define KBI_SC_KBF_MASK                          (0x8U)                                              /**< KBI0_SC.KBF Mask                        */
#define KBI_SC_KBF_SHIFT                         (3U)                                                /**< KBI0_SC.KBF Position                    */
#define KBI_SC_KBF(x)                            (((uint8_t)(((uint8_t)(x))<<KBI_SC_KBF_SHIFT))&KBI_SC_KBF_MASK) /**< KBI0_SC.KBF Field                       */
/** @} */

/** @name PE - KBI Pin Enables */ /** @{ */
#define KBI_PE_KBIPE_MASK                        (0x1U)                                              /**< KBI0_PE.KBIPE Mask                      */
#define KBI_PE_KBIPE_SHIFT                       (0U)                                                /**< KBI0_PE.KBIPE Position                  */
#define KBI_PE_KBIPE(x)                          (((uint8_t)(((uint8_t)(x))<<KBI_PE_KBIPE_SHIFT))&KBI_PE_KBIPE_MASK) /**< KBI0_PE.KBIPE Field                     */
/** @} */

/** @name ES - KBI Edge Selects */ /** @{ */
#define KBI_ES_KBEDG_MASK                        (0x1U)                                              /**< KBI0_ES.KBEDG Mask                      */
#define KBI_ES_KBEDG_SHIFT                       (0U)                                                /**< KBI0_ES.KBEDG Position                  */
#define KBI_ES_KBEDG(x)                          (((uint8_t)(((uint8_t)(x))<<KBI_ES_KBEDG_SHIFT))&KBI_ES_KBEDG_MASK) /**< KBI0_ES.KBEDG Field                     */
/** @} */

/** @} */ /* End group KBI_Register_Masks_GROUP */


/* KBI0 - Peripheral instance base addresses */
#define KBI0_BasePtr                   0x40079000UL //!< Peripheral base address
#define KBI0                           ((KBI_Type *) KBI0_BasePtr) //!< Freescale base pointer
#define KBI0_BASE_PTR                  (KBI0) //!< Freescale style base pointer
#define KBI0_IRQS { KBI0_IRQn,  }


/** @} */ /* End group KBI_Peripheral_access_layer_GROUP */


/** @brief C Struct for KBI */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup KBI_Peripheral_access_layer_GROUP KBI Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           KBI1 (derived from KBI0)             ================ */
/* ================================================================================ */

/**
 * @brief Keyboard interrupts
 */

/* KBI1 - Peripheral instance base addresses */
#define KBI1_BasePtr                   0x4007A000UL //!< Peripheral base address
#define KBI1                           ((KBI_Type *) KBI1_BasePtr) //!< Freescale base pointer
#define KBI1_BASE_PTR                  (KBI1) //!< Freescale style base pointer
#define KBI1_IRQS { KBI1_IRQn,  }


/** @} */ /* End group KBI_Peripheral_access_layer_GROUP */


/** @brief C Struct for MCM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup MCM_Peripheral_access_layer_GROUP MCM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           MCM (file:MCM_MKE02Z2)               ================ */
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

/** @} */ /* End group MCM_Register_Masks_GROUP */


/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xF0003000UL //!< Peripheral base address
#define MCM                            ((MCM_Type *) MCM_BasePtr) //!< Freescale base pointer
#define MCM_BASE_PTR                   (MCM) //!< Freescale style base pointer

/** @} */ /* End group MCM_Peripheral_access_layer_GROUP */


/** @brief C Struct for NV */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           NV (file:NV_FTMRH)                   ================ */
/* ================================================================================ */

/**
 * @brief Flash configuration field
 */
/**
 * @struct NV_Type
 * @brief  C Struct allowing access to NV registers
 */
typedef struct NV_Type {
   __I  uint8_t   BACKKEY[8];                   /**< 0000: Backdoor Comparison Key                                      */
        uint8_t   RESERVED_0[4];                /**< 0008: 0x4 bytes                                                    */
   __I  uint8_t   EEPROT;                       /**< 000C: Non-volatile E-Flash Protection Register (If implemented)    */
   __I  uint8_t   FPROT;                        /**< 000D: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FSEC;                         /**< 000E: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /**< 000F: Non-volatile Flash Option Register                           */
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

/** @name EEPROT - Non-volatile E-Flash Protection Register (If implemented) */ /** @{ */
#define NV_EEPROT_DPS_MASK                       (0x7U)                                              /**< NV_EEPROT.DPS Mask                      */
#define NV_EEPROT_DPS_SHIFT                      (0U)                                                /**< NV_EEPROT.DPS Position                  */
#define NV_EEPROT_DPS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_EEPROT_DPS_SHIFT))&NV_EEPROT_DPS_MASK) /**< NV_EEPROT.DPS Field                     */
#define NV_EEPROT_DPOPEN_MASK                    (0x80U)                                             /**< NV_EEPROT.DPOPEN Mask                   */
#define NV_EEPROT_DPOPEN_SHIFT                   (7U)                                                /**< NV_EEPROT.DPOPEN Position               */
#define NV_EEPROT_DPOPEN(x)                      (((uint8_t)(((uint8_t)(x))<<NV_EEPROT_DPOPEN_SHIFT))&NV_EEPROT_DPOPEN_MASK) /**< NV_EEPROT.DPOPEN Field                  */
/** @} */

/** @name FPROT - Non-volatile P-Flash Protection Register */ /** @{ */
#define NV_FPROT_FPLS_MASK                       (0x3U)                                              /**< NV_FPROT.FPLS Mask                      */
#define NV_FPROT_FPLS_SHIFT                      (0U)                                                /**< NV_FPROT.FPLS Position                  */
#define NV_FPROT_FPLS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPLS_SHIFT))&NV_FPROT_FPLS_MASK) /**< NV_FPROT.FPLS Field                     */
#define NV_FPROT_FPLDIS_MASK                     (0x4U)                                              /**< NV_FPROT.FPLDIS Mask                    */
#define NV_FPROT_FPLDIS_SHIFT                    (2U)                                                /**< NV_FPROT.FPLDIS Position                */
#define NV_FPROT_FPLDIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPLDIS_SHIFT))&NV_FPROT_FPLDIS_MASK) /**< NV_FPROT.FPLDIS Field                   */
#define NV_FPROT_FPHS_MASK                       (0x18U)                                             /**< NV_FPROT.FPHS Mask                      */
#define NV_FPROT_FPHS_SHIFT                      (3U)                                                /**< NV_FPROT.FPHS Position                  */
#define NV_FPROT_FPHS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPHS_SHIFT))&NV_FPROT_FPHS_MASK) /**< NV_FPROT.FPHS Field                     */
#define NV_FPROT_FPHDIS_MASK                     (0x20U)                                             /**< NV_FPROT.FPHDIS Mask                    */
#define NV_FPROT_FPHDIS_SHIFT                    (5U)                                                /**< NV_FPROT.FPHDIS Position                */
#define NV_FPROT_FPHDIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPHDIS_SHIFT))&NV_FPROT_FPHDIS_MASK) /**< NV_FPROT.FPHDIS Field                   */
#define NV_FPROT_FPOPEN_MASK                     (0x80U)                                             /**< NV_FPROT.FPOPEN Mask                    */
#define NV_FPROT_FPOPEN_SHIFT                    (7U)                                                /**< NV_FPROT.FPOPEN Position                */
#define NV_FPROT_FPOPEN(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPOPEN_SHIFT))&NV_FPROT_FPOPEN_MASK) /**< NV_FPROT.FPOPEN Field                   */
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
/* ================           OSC0 (file:OSC0_MKE)                 ================ */
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
#define OSC_CR_OSCINIT_MASK                      (0x1U)                                              /**< OSC0_CR.OSCINIT Mask                    */
#define OSC_CR_OSCINIT_SHIFT                     (0U)                                                /**< OSC0_CR.OSCINIT Position                */
#define OSC_CR_OSCINIT(x)                        (((uint8_t)(((uint8_t)(x))<<OSC_CR_OSCINIT_SHIFT))&OSC_CR_OSCINIT_MASK) /**< OSC0_CR.OSCINIT Field                   */
#define OSC_CR_HGO_MASK                          (0x2U)                                              /**< OSC0_CR.HGO Mask                        */
#define OSC_CR_HGO_SHIFT                         (1U)                                                /**< OSC0_CR.HGO Position                    */
#define OSC_CR_HGO(x)                            (((uint8_t)(((uint8_t)(x))<<OSC_CR_HGO_SHIFT))&OSC_CR_HGO_MASK) /**< OSC0_CR.HGO Field                       */
#define OSC_CR_RANGE_MASK                        (0x4U)                                              /**< OSC0_CR.RANGE Mask                      */
#define OSC_CR_RANGE_SHIFT                       (2U)                                                /**< OSC0_CR.RANGE Position                  */
#define OSC_CR_RANGE(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_RANGE_SHIFT))&OSC_CR_RANGE_MASK) /**< OSC0_CR.RANGE Field                     */
#define OSC_CR_OSCOS_MASK                        (0x10U)                                             /**< OSC0_CR.OSCOS Mask                      */
#define OSC_CR_OSCOS_SHIFT                       (4U)                                                /**< OSC0_CR.OSCOS Position                  */
#define OSC_CR_OSCOS(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_OSCOS_SHIFT))&OSC_CR_OSCOS_MASK) /**< OSC0_CR.OSCOS Field                     */
#define OSC_CR_OSCSTEN_MASK                      (0x20U)                                             /**< OSC0_CR.OSCSTEN Mask                    */
#define OSC_CR_OSCSTEN_SHIFT                     (5U)                                                /**< OSC0_CR.OSCSTEN Position                */
#define OSC_CR_OSCSTEN(x)                        (((uint8_t)(((uint8_t)(x))<<OSC_CR_OSCSTEN_SHIFT))&OSC_CR_OSCSTEN_MASK) /**< OSC0_CR.OSCSTEN Field                   */
#define OSC_CR_OSCEN_MASK                        (0x80U)                                             /**< OSC0_CR.OSCEN Mask                      */
#define OSC_CR_OSCEN_SHIFT                       (7U)                                                /**< OSC0_CR.OSCEN Position                  */
#define OSC_CR_OSCEN(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_OSCEN_SHIFT))&OSC_CR_OSCEN_MASK) /**< OSC0_CR.OSCEN Field                     */
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
/* ================           PIT (file:PIT_2CH_CHAIN_0x40037000)       ================ */
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
        uint8_t   RESERVED_0[252];              /**< 0004: 0xFC bytes                                                   */
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
#define PIT_IRQS { PIT_Ch0_IRQn, PIT_Ch1_IRQn,  }


/** @} */ /* End group PIT_Peripheral_access_layer_GROUP */


/** @brief C Struct for PMC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           PMC (file:PMC_MKE)                   ================ */
/* ================================================================================ */

/**
 * @brief Power Management Controller
 */
/**
 * @struct PMC_Type
 * @brief  C Struct allowing access to PMC registers
 */
typedef struct PMC_Type {
   __IO uint8_t   SPMSC1;                       /**< 0000: System Power Management Status and Control 1 Register        */
   __IO uint8_t   SPMSC2;                       /**< 0001: System Power Management Status and Control 2 Register        */
} PMC_Type;


/** @brief Register Masks for PMC */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup PMC_Register_Masks_GROUP PMC Register Masks */
/** @{ */

/** @name SPMSC1 - System Power Management Status and Control 1 Register */ /** @{ */
#define PMC_SPMSC1_BGBE_MASK                     (0x1U)                                              /**< PMC_SPMSC1.BGBE Mask                    */
#define PMC_SPMSC1_BGBE_SHIFT                    (0U)                                                /**< PMC_SPMSC1.BGBE Position                */
#define PMC_SPMSC1_BGBE(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_BGBE_SHIFT))&PMC_SPMSC1_BGBE_MASK) /**< PMC_SPMSC1.BGBE Field                   */
#define PMC_SPMSC1_LVDE_MASK                     (0x4U)                                              /**< PMC_SPMSC1.LVDE Mask                    */
#define PMC_SPMSC1_LVDE_SHIFT                    (2U)                                                /**< PMC_SPMSC1.LVDE Position                */
#define PMC_SPMSC1_LVDE(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVDE_SHIFT))&PMC_SPMSC1_LVDE_MASK) /**< PMC_SPMSC1.LVDE Field                   */
#define PMC_SPMSC1_LVDSE_MASK                    (0x8U)                                              /**< PMC_SPMSC1.LVDSE Mask                   */
#define PMC_SPMSC1_LVDSE_SHIFT                   (3U)                                                /**< PMC_SPMSC1.LVDSE Position               */
#define PMC_SPMSC1_LVDSE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVDSE_SHIFT))&PMC_SPMSC1_LVDSE_MASK) /**< PMC_SPMSC1.LVDSE Field                  */
#define PMC_SPMSC1_LVDRE_MASK                    (0x10U)                                             /**< PMC_SPMSC1.LVDRE Mask                   */
#define PMC_SPMSC1_LVDRE_SHIFT                   (4U)                                                /**< PMC_SPMSC1.LVDRE Position               */
#define PMC_SPMSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVDRE_SHIFT))&PMC_SPMSC1_LVDRE_MASK) /**< PMC_SPMSC1.LVDRE Field                  */
#define PMC_SPMSC1_LVWIE_MASK                    (0x20U)                                             /**< PMC_SPMSC1.LVWIE Mask                   */
#define PMC_SPMSC1_LVWIE_SHIFT                   (5U)                                                /**< PMC_SPMSC1.LVWIE Position               */
#define PMC_SPMSC1_LVWIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVWIE_SHIFT))&PMC_SPMSC1_LVWIE_MASK) /**< PMC_SPMSC1.LVWIE Field                  */
#define PMC_SPMSC1_LVWACK_MASK                   (0x40U)                                             /**< PMC_SPMSC1.LVWACK Mask                  */
#define PMC_SPMSC1_LVWACK_SHIFT                  (6U)                                                /**< PMC_SPMSC1.LVWACK Position              */
#define PMC_SPMSC1_LVWACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVWACK_SHIFT))&PMC_SPMSC1_LVWACK_MASK) /**< PMC_SPMSC1.LVWACK Field                 */
#define PMC_SPMSC1_LVWF_MASK                     (0x80U)                                             /**< PMC_SPMSC1.LVWF Mask                    */
#define PMC_SPMSC1_LVWF_SHIFT                    (7U)                                                /**< PMC_SPMSC1.LVWF Position                */
#define PMC_SPMSC1_LVWF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC1_LVWF_SHIFT))&PMC_SPMSC1_LVWF_MASK) /**< PMC_SPMSC1.LVWF Field                   */
/** @} */

/** @name SPMSC2 - System Power Management Status and Control 2 Register */ /** @{ */
#define PMC_SPMSC2_LVWV_MASK                     (0x30U)                                             /**< PMC_SPMSC2.LVWV Mask                    */
#define PMC_SPMSC2_LVWV_SHIFT                    (4U)                                                /**< PMC_SPMSC2.LVWV Position                */
#define PMC_SPMSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC2_LVWV_SHIFT))&PMC_SPMSC2_LVWV_MASK) /**< PMC_SPMSC2.LVWV Field                   */
#define PMC_SPMSC2_LVDV_MASK                     (0x40U)                                             /**< PMC_SPMSC2.LVDV Mask                    */
#define PMC_SPMSC2_LVDV_SHIFT                    (6U)                                                /**< PMC_SPMSC2.LVDV Position                */
#define PMC_SPMSC2_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC2_LVDV_SHIFT))&PMC_SPMSC2_LVDV_MASK) /**< PMC_SPMSC2.LVDV Field                   */
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
/* ================           PORT (file:PORT_MKE02)               ================ */
/* ================================================================================ */

/**
 * @brief Port control
 */
/**
 * @struct PORT_Type
 * @brief  C Struct allowing access to PORT registers
 */
typedef struct PORT_Type {
   __IO uint32_t  IOFLT;                        /**< 0000: Port Filter Register                                         */
   __IO uint32_t  PUEL;                         /**< 0004: Port Pull-up Enable Low Register                             */
   __IO uint32_t  PUEH;                         /**< 0008: Port Pull-up Enable High Register                            */
   __IO uint32_t  HDRVE;                        /**< 000C: Port High Drive Enable Register                              */
} PORT_Type;


/** @brief Register Masks for PORT */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORT' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup PORT_Register_Masks_GROUP PORT Register Masks */
/** @{ */

/** @name IOFLT - Port Filter Register */ /** @{ */
#define PORT_IOFLT_FLTA_MASK                     (0x3U)                                              /**< PORT_IOFLT.FLTA Mask                    */
#define PORT_IOFLT_FLTA_SHIFT                    (0U)                                                /**< PORT_IOFLT.FLTA Position                */
#define PORT_IOFLT_FLTA(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTA_SHIFT))&PORT_IOFLT_FLTA_MASK) /**< PORT_IOFLT.FLTA Field                   */
#define PORT_IOFLT_FLTB_MASK                     (0xCU)                                              /**< PORT_IOFLT.FLTB Mask                    */
#define PORT_IOFLT_FLTB_SHIFT                    (2U)                                                /**< PORT_IOFLT.FLTB Position                */
#define PORT_IOFLT_FLTB(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTB_SHIFT))&PORT_IOFLT_FLTB_MASK) /**< PORT_IOFLT.FLTB Field                   */
#define PORT_IOFLT_FLTC_MASK                     (0x30U)                                             /**< PORT_IOFLT.FLTC Mask                    */
#define PORT_IOFLT_FLTC_SHIFT                    (4U)                                                /**< PORT_IOFLT.FLTC Position                */
#define PORT_IOFLT_FLTC(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTC_SHIFT))&PORT_IOFLT_FLTC_MASK) /**< PORT_IOFLT.FLTC Field                   */
#define PORT_IOFLT_FLTD_MASK                     (0xC0U)                                             /**< PORT_IOFLT.FLTD Mask                    */
#define PORT_IOFLT_FLTD_SHIFT                    (6U)                                                /**< PORT_IOFLT.FLTD Position                */
#define PORT_IOFLT_FLTD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTD_SHIFT))&PORT_IOFLT_FLTD_MASK) /**< PORT_IOFLT.FLTD Field                   */
#define PORT_IOFLT_FLTE_MASK                     (0x300U)                                            /**< PORT_IOFLT.FLTE Mask                    */
#define PORT_IOFLT_FLTE_SHIFT                    (8U)                                                /**< PORT_IOFLT.FLTE Position                */
#define PORT_IOFLT_FLTE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTE_SHIFT))&PORT_IOFLT_FLTE_MASK) /**< PORT_IOFLT.FLTE Field                   */
#define PORT_IOFLT_FLTF_MASK                     (0xC00U)                                            /**< PORT_IOFLT.FLTF Mask                    */
#define PORT_IOFLT_FLTF_SHIFT                    (10U)                                               /**< PORT_IOFLT.FLTF Position                */
#define PORT_IOFLT_FLTF(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTF_SHIFT))&PORT_IOFLT_FLTF_MASK) /**< PORT_IOFLT.FLTF Field                   */
#define PORT_IOFLT_FLTG_MASK                     (0x3000U)                                           /**< PORT_IOFLT.FLTG Mask                    */
#define PORT_IOFLT_FLTG_SHIFT                    (12U)                                               /**< PORT_IOFLT.FLTG Position                */
#define PORT_IOFLT_FLTG(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTG_SHIFT))&PORT_IOFLT_FLTG_MASK) /**< PORT_IOFLT.FLTG Field                   */
#define PORT_IOFLT_FLTH_MASK                     (0xC000U)                                           /**< PORT_IOFLT.FLTH Mask                    */
#define PORT_IOFLT_FLTH_SHIFT                    (14U)                                               /**< PORT_IOFLT.FLTH Position                */
#define PORT_IOFLT_FLTH(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTH_SHIFT))&PORT_IOFLT_FLTH_MASK) /**< PORT_IOFLT.FLTH Field                   */
#define PORT_IOFLT_FLTRST_MASK                   (0x30000U)                                          /**< PORT_IOFLT.FLTRST Mask                  */
#define PORT_IOFLT_FLTRST_SHIFT                  (16U)                                               /**< PORT_IOFLT.FLTRST Position              */
#define PORT_IOFLT_FLTRST(x)                     (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTRST_SHIFT))&PORT_IOFLT_FLTRST_MASK) /**< PORT_IOFLT.FLTRST Field                 */
#define PORT_IOFLT_FLTKBI0_MASK                  (0xC0000U)                                          /**< PORT_IOFLT.FLTKBI0 Mask                 */
#define PORT_IOFLT_FLTKBI0_SHIFT                 (18U)                                               /**< PORT_IOFLT.FLTKBI0 Position             */
#define PORT_IOFLT_FLTKBI0(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTKBI0_SHIFT))&PORT_IOFLT_FLTKBI0_MASK) /**< PORT_IOFLT.FLTKBI0 Field                */
#define PORT_IOFLT_FLTKBI1_MASK                  (0x300000U)                                         /**< PORT_IOFLT.FLTKBI1 Mask                 */
#define PORT_IOFLT_FLTKBI1_SHIFT                 (20U)                                               /**< PORT_IOFLT.FLTKBI1 Position             */
#define PORT_IOFLT_FLTKBI1(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTKBI1_SHIFT))&PORT_IOFLT_FLTKBI1_MASK) /**< PORT_IOFLT.FLTKBI1 Field                */
#define PORT_IOFLT_FLTNMI_MASK                   (0xC00000U)                                         /**< PORT_IOFLT.FLTNMI Mask                  */
#define PORT_IOFLT_FLTNMI_SHIFT                  (22U)                                               /**< PORT_IOFLT.FLTNMI Position              */
#define PORT_IOFLT_FLTNMI(x)                     (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTNMI_SHIFT))&PORT_IOFLT_FLTNMI_MASK) /**< PORT_IOFLT.FLTNMI Field                 */
#define PORT_IOFLT_FLTDIV1_MASK                  (0x3000000U)                                        /**< PORT_IOFLT.FLTDIV1 Mask                 */
#define PORT_IOFLT_FLTDIV1_SHIFT                 (24U)                                               /**< PORT_IOFLT.FLTDIV1 Position             */
#define PORT_IOFLT_FLTDIV1(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTDIV1_SHIFT))&PORT_IOFLT_FLTDIV1_MASK) /**< PORT_IOFLT.FLTDIV1 Field                */
#define PORT_IOFLT_FLTDIV2_MASK                  (0x1C000000U)                                       /**< PORT_IOFLT.FLTDIV2 Mask                 */
#define PORT_IOFLT_FLTDIV2_SHIFT                 (26U)                                               /**< PORT_IOFLT.FLTDIV2 Position             */
#define PORT_IOFLT_FLTDIV2(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTDIV2_SHIFT))&PORT_IOFLT_FLTDIV2_MASK) /**< PORT_IOFLT.FLTDIV2 Field                */
#define PORT_IOFLT_FLTDIV3_MASK                  (0xE0000000U)                                       /**< PORT_IOFLT.FLTDIV3 Mask                 */
#define PORT_IOFLT_FLTDIV3_SHIFT                 (29U)                                               /**< PORT_IOFLT.FLTDIV3 Position             */
#define PORT_IOFLT_FLTDIV3(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTDIV3_SHIFT))&PORT_IOFLT_FLTDIV3_MASK) /**< PORT_IOFLT.FLTDIV3 Field                */
/** @} */

/** @name PUEL - Port Pull-up Enable Low Register */ /** @{ */
#define PORT_PUEL_PTAPE_MASK                     (0xFFU)                                             /**< PORT_PUEL.PTAPE Mask                    */
#define PORT_PUEL_PTAPE_SHIFT                    (0U)                                                /**< PORT_PUEL.PTAPE Position                */
#define PORT_PUEL_PTAPE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_PUEL_PTAPE_SHIFT))&PORT_PUEL_PTAPE_MASK) /**< PORT_PUEL.PTAPE Field                   */
#define PORT_PUEL_PTBPE_MASK                     (0xFF00U)                                           /**< PORT_PUEL.PTBPE Mask                    */
#define PORT_PUEL_PTBPE_SHIFT                    (8U)                                                /**< PORT_PUEL.PTBPE Position                */
#define PORT_PUEL_PTBPE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_PUEL_PTBPE_SHIFT))&PORT_PUEL_PTBPE_MASK) /**< PORT_PUEL.PTBPE Field                   */
#define PORT_PUEL_PTCPE_MASK                     (0xFF0000U)                                         /**< PORT_PUEL.PTCPE Mask                    */
#define PORT_PUEL_PTCPE_SHIFT                    (16U)                                               /**< PORT_PUEL.PTCPE Position                */
#define PORT_PUEL_PTCPE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_PUEL_PTCPE_SHIFT))&PORT_PUEL_PTCPE_MASK) /**< PORT_PUEL.PTCPE Field                   */
#define PORT_PUEL_PTDPE_MASK                     (0xFF000000U)                                       /**< PORT_PUEL.PTDPE Mask                    */
#define PORT_PUEL_PTDPE_SHIFT                    (24U)                                               /**< PORT_PUEL.PTDPE Position                */
#define PORT_PUEL_PTDPE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_PUEL_PTDPE_SHIFT))&PORT_PUEL_PTDPE_MASK) /**< PORT_PUEL.PTDPE Field                   */
/** @} */

/** @name PUEH - Port Pull-up Enable High Register */ /** @{ */
#define PORT_PUEH_PTEPE_MASK                     (0xFFU)                                             /**< PORT_PUEH.PTEPE Mask                    */
#define PORT_PUEH_PTEPE_SHIFT                    (0U)                                                /**< PORT_PUEH.PTEPE Position                */
#define PORT_PUEH_PTEPE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_PUEH_PTEPE_SHIFT))&PORT_PUEH_PTEPE_MASK) /**< PORT_PUEH.PTEPE Field                   */
#define PORT_PUEH_PTFPE_MASK                     (0xFF00U)                                           /**< PORT_PUEH.PTFPE Mask                    */
#define PORT_PUEH_PTFPE_SHIFT                    (8U)                                                /**< PORT_PUEH.PTFPE Position                */
#define PORT_PUEH_PTFPE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_PUEH_PTFPE_SHIFT))&PORT_PUEH_PTFPE_MASK) /**< PORT_PUEH.PTFPE Field                   */
#define PORT_PUEH_PTGPE_MASK                     (0xFF0000U)                                         /**< PORT_PUEH.PTGPE Mask                    */
#define PORT_PUEH_PTGPE_SHIFT                    (16U)                                               /**< PORT_PUEH.PTGPE Position                */
#define PORT_PUEH_PTGPE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_PUEH_PTGPE_SHIFT))&PORT_PUEH_PTGPE_MASK) /**< PORT_PUEH.PTGPE Field                   */
#define PORT_PUEH_PTHPE_MASK                     (0xFF000000U)                                       /**< PORT_PUEH.PTHPE Mask                    */
#define PORT_PUEH_PTHPE_SHIFT                    (24U)                                               /**< PORT_PUEH.PTHPE Position                */
#define PORT_PUEH_PTHPE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_PUEH_PTHPE_SHIFT))&PORT_PUEH_PTHPE_MASK) /**< PORT_PUEH.PTHPE Field                   */
/** @} */

/** @name HDRVE - Port High Drive Enable Register */ /** @{ */
#define PORT_HDRVE_PTB4_MASK                     (0x1U)                                              /**< PORT_HDRVE.PTB4 Mask                    */
#define PORT_HDRVE_PTB4_SHIFT                    (0U)                                                /**< PORT_HDRVE.PTB4 Position                */
#define PORT_HDRVE_PTB4(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_HDRVE_PTB4_SHIFT))&PORT_HDRVE_PTB4_MASK) /**< PORT_HDRVE.PTB4 Field                   */
#define PORT_HDRVE_PTB5_MASK                     (0x2U)                                              /**< PORT_HDRVE.PTB5 Mask                    */
#define PORT_HDRVE_PTB5_SHIFT                    (1U)                                                /**< PORT_HDRVE.PTB5 Position                */
#define PORT_HDRVE_PTB5(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_HDRVE_PTB5_SHIFT))&PORT_HDRVE_PTB5_MASK) /**< PORT_HDRVE.PTB5 Field                   */
#define PORT_HDRVE_PTD0_MASK                     (0x4U)                                              /**< PORT_HDRVE.PTD0 Mask                    */
#define PORT_HDRVE_PTD0_SHIFT                    (2U)                                                /**< PORT_HDRVE.PTD0 Position                */
#define PORT_HDRVE_PTD0(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_HDRVE_PTD0_SHIFT))&PORT_HDRVE_PTD0_MASK) /**< PORT_HDRVE.PTD0 Field                   */
#define PORT_HDRVE_PTD1_MASK                     (0x8U)                                              /**< PORT_HDRVE.PTD1 Mask                    */
#define PORT_HDRVE_PTD1_SHIFT                    (3U)                                                /**< PORT_HDRVE.PTD1 Position                */
#define PORT_HDRVE_PTD1(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_HDRVE_PTD1_SHIFT))&PORT_HDRVE_PTD1_MASK) /**< PORT_HDRVE.PTD1 Field                   */
#define PORT_HDRVE_PTE0_MASK                     (0x10U)                                             /**< PORT_HDRVE.PTE0 Mask                    */
#define PORT_HDRVE_PTE0_SHIFT                    (4U)                                                /**< PORT_HDRVE.PTE0 Position                */
#define PORT_HDRVE_PTE0(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_HDRVE_PTE0_SHIFT))&PORT_HDRVE_PTE0_MASK) /**< PORT_HDRVE.PTE0 Field                   */
#define PORT_HDRVE_PTE1_MASK                     (0x20U)                                             /**< PORT_HDRVE.PTE1 Mask                    */
#define PORT_HDRVE_PTE1_SHIFT                    (5U)                                                /**< PORT_HDRVE.PTE1 Position                */
#define PORT_HDRVE_PTE1(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_HDRVE_PTE1_SHIFT))&PORT_HDRVE_PTE1_MASK) /**< PORT_HDRVE.PTE1 Field                   */
#define PORT_HDRVE_PTH0_MASK                     (0x40U)                                             /**< PORT_HDRVE.PTH0 Mask                    */
#define PORT_HDRVE_PTH0_SHIFT                    (6U)                                                /**< PORT_HDRVE.PTH0 Position                */
#define PORT_HDRVE_PTH0(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_HDRVE_PTH0_SHIFT))&PORT_HDRVE_PTH0_MASK) /**< PORT_HDRVE.PTH0 Field                   */
#define PORT_HDRVE_PTH1_MASK                     (0x80U)                                             /**< PORT_HDRVE.PTH1 Mask                    */
#define PORT_HDRVE_PTH1_SHIFT                    (7U)                                                /**< PORT_HDRVE.PTH1 Position                */
#define PORT_HDRVE_PTH1(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_HDRVE_PTH1_SHIFT))&PORT_HDRVE_PTH1_MASK) /**< PORT_HDRVE.PTH1 Field                   */
/** @} */

/** @} */ /* End group PORT_Register_Masks_GROUP */


/* PORT - Peripheral instance base addresses */
#define PORT_BasePtr                   0x40049000UL //!< Peripheral base address
#define PORT                           ((PORT_Type *) PORT_BasePtr) //!< Freescale base pointer
#define PORT_BASE_PTR                  (PORT) //!< Freescale style base pointer

/** @} */ /* End group PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for ROM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup ROM_Peripheral_access_layer_GROUP ROM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           ROM (file:ROM_0)                     ================ */
/* ================================================================================ */

/**
 * @brief System ROM
 */
/**
 * @struct ROM_Type
 * @brief  C Struct allowing access to ROM registers
 */
typedef struct ROM_Type {
   __I  uint32_t  ENTRY;                        /**< 0000: Entry                                                        */
   __I  uint32_t  TABLEMARK;                    /**< 0004: End of Table Marker Register                                 */
        uint8_t   RESERVED_0[4036];             /**< 0008: 0xFC4 bytes                                                  */
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
/* ================           RTC (file:RTCNTR_MKE)                ================ */
/* ================================================================================ */

/**
 * @brief Real-time counter
 */
/**
 * @struct RTC_Type
 * @brief  C Struct allowing access to RTC registers
 */
typedef struct RTC_Type {
   __IO uint32_t  SC;                           /**< 0000: Status and Control Register                                  */
   __IO uint32_t  MOD;                          /**< 0004: Modulo Register                                              */
   __I  uint32_t  CNT;                          /**< 0008: Counter Register                                             */
} RTC_Type;


/** @brief Register Masks for RTC */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup RTC_Register_Masks_GROUP RTC Register Masks */
/** @{ */

/** @name SC - Status and Control Register */ /** @{ */
#define RTC_SC_RTCO_MASK                         (0x10U)                                             /**< RTC_SC.RTCO Mask                        */
#define RTC_SC_RTCO_SHIFT                        (4U)                                                /**< RTC_SC.RTCO Position                    */
#define RTC_SC_RTCO(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCO_SHIFT))&RTC_SC_RTCO_MASK) /**< RTC_SC.RTCO Field                       */
#define RTC_SC_RTIE_MASK                         (0x40U)                                             /**< RTC_SC.RTIE Mask                        */
#define RTC_SC_RTIE_SHIFT                        (6U)                                                /**< RTC_SC.RTIE Position                    */
#define RTC_SC_RTIE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTIE_SHIFT))&RTC_SC_RTIE_MASK) /**< RTC_SC.RTIE Field                       */
#define RTC_SC_RTIF_MASK                         (0x80U)                                             /**< RTC_SC.RTIF Mask                        */
#define RTC_SC_RTIF_SHIFT                        (7U)                                                /**< RTC_SC.RTIF Position                    */
#define RTC_SC_RTIF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTIF_SHIFT))&RTC_SC_RTIF_MASK) /**< RTC_SC.RTIF Field                       */
#define RTC_SC_RTCPS_MASK                        (0x700U)                                            /**< RTC_SC.RTCPS Mask                       */
#define RTC_SC_RTCPS_SHIFT                       (8U)                                                /**< RTC_SC.RTCPS Position                   */
#define RTC_SC_RTCPS(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCPS_SHIFT))&RTC_SC_RTCPS_MASK) /**< RTC_SC.RTCPS Field                      */
#define RTC_SC_RTCLKS_MASK                       (0xC000U)                                           /**< RTC_SC.RTCLKS Mask                      */
#define RTC_SC_RTCLKS_SHIFT                      (14U)                                               /**< RTC_SC.RTCLKS Position                  */
#define RTC_SC_RTCLKS(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCLKS_SHIFT))&RTC_SC_RTCLKS_MASK) /**< RTC_SC.RTCLKS Field                     */
/** @} */

/** @name MOD - Modulo Register */ /** @{ */
#define RTC_MOD_MOD_MASK                         (0xFFFFU)                                           /**< RTC_MOD.MOD Mask                        */
#define RTC_MOD_MOD_SHIFT                        (0U)                                                /**< RTC_MOD.MOD Position                    */
#define RTC_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_MOD_MOD_SHIFT))&RTC_MOD_MOD_MASK) /**< RTC_MOD.MOD Field                       */
/** @} */

/** @name CNT - Counter Register */ /** @{ */
#define RTC_CNT_CNT_MASK                         (0xFFFFU)                                           /**< RTC_CNT.CNT Mask                        */
#define RTC_CNT_CNT_SHIFT                        (0U)                                                /**< RTC_CNT.CNT Position                    */
#define RTC_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CNT_CNT_SHIFT))&RTC_CNT_CNT_MASK) /**< RTC_CNT.CNT Field                       */
/** @} */

/** @} */ /* End group RTC_Register_Masks_GROUP */


/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x4003D000UL //!< Peripheral base address
#define RTC                            ((RTC_Type *) RTC_BasePtr) //!< Freescale base pointer
#define RTC_BASE_PTR                   (RTC) //!< Freescale style base pointer
#define RTC_IRQS { RTC_Alarm_IRQn,  }


/** @} */ /* End group RTC_Peripheral_access_layer_GROUP */


/** @brief C Struct for SIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SIM (file:SIM_MKE02Z2)               ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
/**
 * @struct SIM_Type
 * @brief  C Struct allowing access to SIM registers
 */
typedef struct SIM_Type {
   __I  uint32_t  SRSID;                        /**< 0000: System Reset Status and ID Register                          */
   __IO uint32_t  SOPT;                         /**< 0004: System Options Register                                      */
   __IO uint32_t  PINSEL;                       /**< 0008: Pin Selection Register                                       */
   __IO uint32_t  SCGC;                         /**< 000C: System Clock Gating Control Register                         */
   __IO uint32_t  UUIDL;                        /**< 0010: Universally Unique Identifier Low Register                   */
   __IO uint32_t  UUIDH;                        /**< 0014: Universally Unique Identifier High Register                  */
   __IO uint32_t  BUSDIV;                       /**< 0018: BUS Clock Divider Register                                   */
} SIM_Type;


/** @brief Register Masks for SIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SIM_Register_Masks_GROUP SIM Register Masks */
/** @{ */

/** @name SRSID - System Reset Status and ID Register */ /** @{ */
#define SIM_SRSID_LVD_MASK                       (0x2U)                                              /**< SIM_SRSID.LVD Mask                      */
#define SIM_SRSID_LVD_SHIFT                      (1U)                                                /**< SIM_SRSID.LVD Position                  */
#define SIM_SRSID_LVD(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_LVD_SHIFT))&SIM_SRSID_LVD_MASK) /**< SIM_SRSID.LVD Field                     */
#define SIM_SRSID_LOC_MASK                       (0x4U)                                              /**< SIM_SRSID.LOC Mask                      */
#define SIM_SRSID_LOC_SHIFT                      (2U)                                                /**< SIM_SRSID.LOC Position                  */
#define SIM_SRSID_LOC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_LOC_SHIFT))&SIM_SRSID_LOC_MASK) /**< SIM_SRSID.LOC Field                     */
#define SIM_SRSID_WDOG_MASK                      (0x20U)                                             /**< SIM_SRSID.WDOG Mask                     */
#define SIM_SRSID_WDOG_SHIFT                     (5U)                                                /**< SIM_SRSID.WDOG Position                 */
#define SIM_SRSID_WDOG(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_WDOG_SHIFT))&SIM_SRSID_WDOG_MASK) /**< SIM_SRSID.WDOG Field                    */
#define SIM_SRSID_PIN_MASK                       (0x40U)                                             /**< SIM_SRSID.PIN Mask                      */
#define SIM_SRSID_PIN_SHIFT                      (6U)                                                /**< SIM_SRSID.PIN Position                  */
#define SIM_SRSID_PIN(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_PIN_SHIFT))&SIM_SRSID_PIN_MASK) /**< SIM_SRSID.PIN Field                     */
#define SIM_SRSID_POR_MASK                       (0x80U)                                             /**< SIM_SRSID.POR Mask                      */
#define SIM_SRSID_POR_SHIFT                      (7U)                                                /**< SIM_SRSID.POR Position                  */
#define SIM_SRSID_POR(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_POR_SHIFT))&SIM_SRSID_POR_MASK) /**< SIM_SRSID.POR Field                     */
#define SIM_SRSID_LOCKUP_MASK                    (0x200U)                                            /**< SIM_SRSID.LOCKUP Mask                   */
#define SIM_SRSID_LOCKUP_SHIFT                   (9U)                                                /**< SIM_SRSID.LOCKUP Position               */
#define SIM_SRSID_LOCKUP(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_LOCKUP_SHIFT))&SIM_SRSID_LOCKUP_MASK) /**< SIM_SRSID.LOCKUP Field                  */
#define SIM_SRSID_SW_MASK                        (0x400U)                                            /**< SIM_SRSID.SW Mask                       */
#define SIM_SRSID_SW_SHIFT                       (10U)                                               /**< SIM_SRSID.SW Position                   */
#define SIM_SRSID_SW(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_SW_SHIFT))&SIM_SRSID_SW_MASK) /**< SIM_SRSID.SW Field                      */
#define SIM_SRSID_MDMAP_MASK                     (0x800U)                                            /**< SIM_SRSID.MDMAP Mask                    */
#define SIM_SRSID_MDMAP_SHIFT                    (11U)                                               /**< SIM_SRSID.MDMAP Position                */
#define SIM_SRSID_MDMAP(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_MDMAP_SHIFT))&SIM_SRSID_MDMAP_MASK) /**< SIM_SRSID.MDMAP Field                   */
#define SIM_SRSID_SACKERR_MASK                   (0x2000U)                                           /**< SIM_SRSID.SACKERR Mask                  */
#define SIM_SRSID_SACKERR_SHIFT                  (13U)                                               /**< SIM_SRSID.SACKERR Position              */
#define SIM_SRSID_SACKERR(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_SACKERR_SHIFT))&SIM_SRSID_SACKERR_MASK) /**< SIM_SRSID.SACKERR Field                 */
#define SIM_SRSID_PINID_MASK                     (0xF0000U)                                          /**< SIM_SRSID.PINID Mask                    */
#define SIM_SRSID_PINID_SHIFT                    (16U)                                               /**< SIM_SRSID.PINID Position                */
#define SIM_SRSID_PINID(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_PINID_SHIFT))&SIM_SRSID_PINID_MASK) /**< SIM_SRSID.PINID Field                   */
#define SIM_SRSID_REVID_MASK                     (0xF00000U)                                         /**< SIM_SRSID.REVID Mask                    */
#define SIM_SRSID_REVID_SHIFT                    (20U)                                               /**< SIM_SRSID.REVID Position                */
#define SIM_SRSID_REVID(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_REVID_SHIFT))&SIM_SRSID_REVID_MASK) /**< SIM_SRSID.REVID Field                   */
#define SIM_SRSID_SUBFAMID_MASK                  (0xF000000U)                                        /**< SIM_SRSID.SUBFAMID Mask                 */
#define SIM_SRSID_SUBFAMID_SHIFT                 (24U)                                               /**< SIM_SRSID.SUBFAMID Position             */
#define SIM_SRSID_SUBFAMID(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_SUBFAMID_SHIFT))&SIM_SRSID_SUBFAMID_MASK) /**< SIM_SRSID.SUBFAMID Field                */
#define SIM_SRSID_FAMID_MASK                     (0xF0000000U)                                       /**< SIM_SRSID.FAMID Mask                    */
#define SIM_SRSID_FAMID_SHIFT                    (28U)                                               /**< SIM_SRSID.FAMID Position                */
#define SIM_SRSID_FAMID(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_FAMID_SHIFT))&SIM_SRSID_FAMID_MASK) /**< SIM_SRSID.FAMID Field                   */
/** @} */

/** @name SOPT - System Options Register */ /** @{ */
#define SIM_SOPT_NMIE_MASK                       (0x2U)                                              /**< SIM_SOPT.NMIE Mask                      */
#define SIM_SOPT_NMIE_SHIFT                      (1U)                                                /**< SIM_SOPT.NMIE Position                  */
#define SIM_SOPT_NMIE(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_NMIE_SHIFT))&SIM_SOPT_NMIE_MASK) /**< SIM_SOPT.NMIE Field                     */
#define SIM_SOPT_RSTPE_MASK                      (0x4U)                                              /**< SIM_SOPT.RSTPE Mask                     */
#define SIM_SOPT_RSTPE_SHIFT                     (2U)                                                /**< SIM_SOPT.RSTPE Position                 */
#define SIM_SOPT_RSTPE(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_RSTPE_SHIFT))&SIM_SOPT_RSTPE_MASK) /**< SIM_SOPT.RSTPE Field                    */
#define SIM_SOPT_SWDE_MASK                       (0x8U)                                              /**< SIM_SOPT.SWDE Mask                      */
#define SIM_SOPT_SWDE_SHIFT                      (3U)                                                /**< SIM_SOPT.SWDE Position                  */
#define SIM_SOPT_SWDE(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_SWDE_SHIFT))&SIM_SOPT_SWDE_MASK) /**< SIM_SOPT.SWDE Field                     */
#define SIM_SOPT_ADHWT_MASK                      (0x300U)                                            /**< SIM_SOPT.ADHWT Mask                     */
#define SIM_SOPT_ADHWT_SHIFT                     (8U)                                                /**< SIM_SOPT.ADHWT Position                 */
#define SIM_SOPT_ADHWT(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_ADHWT_SHIFT))&SIM_SOPT_ADHWT_MASK) /**< SIM_SOPT.ADHWT Field                    */
#define SIM_SOPT_RTCC_MASK                       (0x400U)                                            /**< SIM_SOPT.RTCC Mask                      */
#define SIM_SOPT_RTCC_SHIFT                      (10U)                                               /**< SIM_SOPT.RTCC Position                  */
#define SIM_SOPT_RTCC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_RTCC_SHIFT))&SIM_SOPT_RTCC_MASK) /**< SIM_SOPT.RTCC Field                     */
#define SIM_SOPT_ACIC_MASK                       (0x800U)                                            /**< SIM_SOPT.ACIC Mask                      */
#define SIM_SOPT_ACIC_SHIFT                      (11U)                                               /**< SIM_SOPT.ACIC Position                  */
#define SIM_SOPT_ACIC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_ACIC_SHIFT))&SIM_SOPT_ACIC_MASK) /**< SIM_SOPT.ACIC Field                     */
#define SIM_SOPT_RXDCE_MASK                      (0x1000U)                                           /**< SIM_SOPT.RXDCE Mask                     */
#define SIM_SOPT_RXDCE_SHIFT                     (12U)                                               /**< SIM_SOPT.RXDCE Position                 */
#define SIM_SOPT_RXDCE(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_RXDCE_SHIFT))&SIM_SOPT_RXDCE_MASK) /**< SIM_SOPT.RXDCE Field                    */
#define SIM_SOPT_RXDFE_MASK                      (0x2000U)                                           /**< SIM_SOPT.RXDFE Mask                     */
#define SIM_SOPT_RXDFE_SHIFT                     (13U)                                               /**< SIM_SOPT.RXDFE Position                 */
#define SIM_SOPT_RXDFE(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_RXDFE_SHIFT))&SIM_SOPT_RXDFE_MASK) /**< SIM_SOPT.RXDFE Field                    */
#define SIM_SOPT_FTMSYNC_MASK                    (0x4000U)                                           /**< SIM_SOPT.FTMSYNC Mask                   */
#define SIM_SOPT_FTMSYNC_SHIFT                   (14U)                                               /**< SIM_SOPT.FTMSYNC Position               */
#define SIM_SOPT_FTMSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_FTMSYNC_SHIFT))&SIM_SOPT_FTMSYNC_MASK) /**< SIM_SOPT.FTMSYNC Field                  */
#define SIM_SOPT_TXDME_MASK                      (0x8000U)                                           /**< SIM_SOPT.TXDME Mask                     */
#define SIM_SOPT_TXDME_SHIFT                     (15U)                                               /**< SIM_SOPT.TXDME Position                 */
#define SIM_SOPT_TXDME(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_TXDME_SHIFT))&SIM_SOPT_TXDME_MASK) /**< SIM_SOPT.TXDME Field                    */
#define SIM_SOPT_BUSREF_MASK                     (0x70000U)                                          /**< SIM_SOPT.BUSREF Mask                    */
#define SIM_SOPT_BUSREF_SHIFT                    (16U)                                               /**< SIM_SOPT.BUSREF Position                */
#define SIM_SOPT_BUSREF(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_BUSREF_SHIFT))&SIM_SOPT_BUSREF_MASK) /**< SIM_SOPT.BUSREF Field                   */
#define SIM_SOPT_CLKOE_MASK                      (0x80000U)                                          /**< SIM_SOPT.CLKOE Mask                     */
#define SIM_SOPT_CLKOE_SHIFT                     (19U)                                               /**< SIM_SOPT.CLKOE Position                 */
#define SIM_SOPT_CLKOE(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_CLKOE_SHIFT))&SIM_SOPT_CLKOE_MASK) /**< SIM_SOPT.CLKOE Field                    */
#define SIM_SOPT_DLYACT_MASK                     (0x800000U)                                         /**< SIM_SOPT.DLYACT Mask                    */
#define SIM_SOPT_DLYACT_SHIFT                    (23U)                                               /**< SIM_SOPT.DLYACT Position                */
#define SIM_SOPT_DLYACT(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_DLYACT_SHIFT))&SIM_SOPT_DLYACT_MASK) /**< SIM_SOPT.DLYACT Field                   */
#define SIM_SOPT_DELAY_MASK                      (0xFF000000U)                                       /**< SIM_SOPT.DELAY Mask                     */
#define SIM_SOPT_DELAY_SHIFT                     (24U)                                               /**< SIM_SOPT.DELAY Position                 */
#define SIM_SOPT_DELAY(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_DELAY_SHIFT))&SIM_SOPT_DELAY_MASK) /**< SIM_SOPT.DELAY Field                    */
/** @} */

/** @name PINSEL - Pin Selection Register */ /** @{ */
#define SIM_PINSEL_RTCPS_MASK                    (0x10U)                                             /**< SIM_PINSEL.RTCPS Mask                   */
#define SIM_PINSEL_RTCPS_SHIFT                   (4U)                                                /**< SIM_PINSEL.RTCPS Position               */
#define SIM_PINSEL_RTCPS(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_RTCPS_SHIFT))&SIM_PINSEL_RTCPS_MASK) /**< SIM_PINSEL.RTCPS Field                  */
#define SIM_PINSEL_I2C0PS_MASK                   (0x20U)                                             /**< SIM_PINSEL.I2C0PS Mask                  */
#define SIM_PINSEL_I2C0PS_SHIFT                  (5U)                                                /**< SIM_PINSEL.I2C0PS Position              */
#define SIM_PINSEL_I2C0PS(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_I2C0PS_SHIFT))&SIM_PINSEL_I2C0PS_MASK) /**< SIM_PINSEL.I2C0PS Field                 */
#define SIM_PINSEL_SPI0PS_MASK                   (0x40U)                                             /**< SIM_PINSEL.SPI0PS Mask                  */
#define SIM_PINSEL_SPI0PS_SHIFT                  (6U)                                                /**< SIM_PINSEL.SPI0PS Position              */
#define SIM_PINSEL_SPI0PS(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_SPI0PS_SHIFT))&SIM_PINSEL_SPI0PS_MASK) /**< SIM_PINSEL.SPI0PS Field                 */
#define SIM_PINSEL_UART0PS_MASK                  (0x80U)                                             /**< SIM_PINSEL.UART0PS Mask                 */
#define SIM_PINSEL_UART0PS_SHIFT                 (7U)                                                /**< SIM_PINSEL.UART0PS Position             */
#define SIM_PINSEL_UART0PS(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_UART0PS_SHIFT))&SIM_PINSEL_UART0PS_MASK) /**< SIM_PINSEL.UART0PS Field                */
#define SIM_PINSEL_FTM0PS0_MASK                  (0x100U)                                            /**< SIM_PINSEL.FTM0PS0 Mask                 */
#define SIM_PINSEL_FTM0PS0_SHIFT                 (8U)                                                /**< SIM_PINSEL.FTM0PS0 Position             */
#define SIM_PINSEL_FTM0PS0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_FTM0PS0_SHIFT))&SIM_PINSEL_FTM0PS0_MASK) /**< SIM_PINSEL.FTM0PS0 Field                */
#define SIM_PINSEL_FTM0PS1_MASK                  (0x200U)                                            /**< SIM_PINSEL.FTM0PS1 Mask                 */
#define SIM_PINSEL_FTM0PS1_SHIFT                 (9U)                                                /**< SIM_PINSEL.FTM0PS1 Position             */
#define SIM_PINSEL_FTM0PS1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_FTM0PS1_SHIFT))&SIM_PINSEL_FTM0PS1_MASK) /**< SIM_PINSEL.FTM0PS1 Field                */
#define SIM_PINSEL_FTM1PS0_MASK                  (0x400U)                                            /**< SIM_PINSEL.FTM1PS0 Mask                 */
#define SIM_PINSEL_FTM1PS0_SHIFT                 (10U)                                               /**< SIM_PINSEL.FTM1PS0 Position             */
#define SIM_PINSEL_FTM1PS0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_FTM1PS0_SHIFT))&SIM_PINSEL_FTM1PS0_MASK) /**< SIM_PINSEL.FTM1PS0 Field                */
#define SIM_PINSEL_FTM1PS1_MASK                  (0x800U)                                            /**< SIM_PINSEL.FTM1PS1 Mask                 */
#define SIM_PINSEL_FTM1PS1_SHIFT                 (11U)                                               /**< SIM_PINSEL.FTM1PS1 Position             */
#define SIM_PINSEL_FTM1PS1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_FTM1PS1_SHIFT))&SIM_PINSEL_FTM1PS1_MASK) /**< SIM_PINSEL.FTM1PS1 Field                */
#define SIM_PINSEL_FTM2PS0_MASK                  (0x1000U)                                           /**< SIM_PINSEL.FTM2PS0 Mask                 */
#define SIM_PINSEL_FTM2PS0_SHIFT                 (12U)                                               /**< SIM_PINSEL.FTM2PS0 Position             */
#define SIM_PINSEL_FTM2PS0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_FTM2PS0_SHIFT))&SIM_PINSEL_FTM2PS0_MASK) /**< SIM_PINSEL.FTM2PS0 Field                */
#define SIM_PINSEL_FTM2PS1_MASK                  (0x2000U)                                           /**< SIM_PINSEL.FTM2PS1 Mask                 */
#define SIM_PINSEL_FTM2PS1_SHIFT                 (13U)                                               /**< SIM_PINSEL.FTM2PS1 Position             */
#define SIM_PINSEL_FTM2PS1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_FTM2PS1_SHIFT))&SIM_PINSEL_FTM2PS1_MASK) /**< SIM_PINSEL.FTM2PS1 Field                */
#define SIM_PINSEL_FTM2PS2_MASK                  (0x4000U)                                           /**< SIM_PINSEL.FTM2PS2 Mask                 */
#define SIM_PINSEL_FTM2PS2_SHIFT                 (14U)                                               /**< SIM_PINSEL.FTM2PS2 Position             */
#define SIM_PINSEL_FTM2PS2(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_FTM2PS2_SHIFT))&SIM_PINSEL_FTM2PS2_MASK) /**< SIM_PINSEL.FTM2PS2 Field                */
#define SIM_PINSEL_FTM2PS3_MASK                  (0x8000U)                                           /**< SIM_PINSEL.FTM2PS3 Mask                 */
#define SIM_PINSEL_FTM2PS3_SHIFT                 (15U)                                               /**< SIM_PINSEL.FTM2PS3 Position             */
#define SIM_PINSEL_FTM2PS3(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_PINSEL_FTM2PS3_SHIFT))&SIM_PINSEL_FTM2PS3_MASK) /**< SIM_PINSEL.FTM2PS3 Field                */
/** @} */

/** @name SCGC - System Clock Gating Control Register */ /** @{ */
#define SIM_SCGC_RTC_MASK                        (0x1U)                                              /**< SIM_SCGC.RTC Mask                       */
#define SIM_SCGC_RTC_SHIFT                       (0U)                                                /**< SIM_SCGC.RTC Position                   */
#define SIM_SCGC_RTC(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_RTC_SHIFT))&SIM_SCGC_RTC_MASK) /**< SIM_SCGC.RTC Field                      */
#define SIM_SCGC_PIT_MASK                        (0x2U)                                              /**< SIM_SCGC.PIT Mask                       */
#define SIM_SCGC_PIT_SHIFT                       (1U)                                                /**< SIM_SCGC.PIT Position                   */
#define SIM_SCGC_PIT(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_PIT_SHIFT))&SIM_SCGC_PIT_MASK) /**< SIM_SCGC.PIT Field                      */
#define SIM_SCGC_FTM0_MASK                       (0x20U)                                             /**< SIM_SCGC.FTM0 Mask                      */
#define SIM_SCGC_FTM0_SHIFT                      (5U)                                                /**< SIM_SCGC.FTM0 Position                  */
#define SIM_SCGC_FTM0(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_FTM0_SHIFT))&SIM_SCGC_FTM0_MASK) /**< SIM_SCGC.FTM0 Field                     */
#define SIM_SCGC_FTM1_MASK                       (0x40U)                                             /**< SIM_SCGC.FTM1 Mask                      */
#define SIM_SCGC_FTM1_SHIFT                      (6U)                                                /**< SIM_SCGC.FTM1 Position                  */
#define SIM_SCGC_FTM1(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_FTM1_SHIFT))&SIM_SCGC_FTM1_MASK) /**< SIM_SCGC.FTM1 Field                     */
#define SIM_SCGC_FTM2_MASK                       (0x80U)                                             /**< SIM_SCGC.FTM2 Mask                      */
#define SIM_SCGC_FTM2_SHIFT                      (7U)                                                /**< SIM_SCGC.FTM2 Position                  */
#define SIM_SCGC_FTM2(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_FTM2_SHIFT))&SIM_SCGC_FTM2_MASK) /**< SIM_SCGC.FTM2 Field                     */
#define SIM_SCGC_CRC_MASK                        (0x400U)                                            /**< SIM_SCGC.CRC Mask                       */
#define SIM_SCGC_CRC_SHIFT                       (10U)                                               /**< SIM_SCGC.CRC Position                   */
#define SIM_SCGC_CRC(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_CRC_SHIFT))&SIM_SCGC_CRC_MASK) /**< SIM_SCGC.CRC Field                      */
#define SIM_SCGC_FLASH_MASK                      (0x1000U)                                           /**< SIM_SCGC.FLASH Mask                     */
#define SIM_SCGC_FLASH_SHIFT                     (12U)                                               /**< SIM_SCGC.FLASH Position                 */
#define SIM_SCGC_FLASH(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_FLASH_SHIFT))&SIM_SCGC_FLASH_MASK) /**< SIM_SCGC.FLASH Field                    */
#define SIM_SCGC_SWD_MASK                        (0x2000U)                                           /**< SIM_SCGC.SWD Mask                       */
#define SIM_SCGC_SWD_SHIFT                       (13U)                                               /**< SIM_SCGC.SWD Position                   */
#define SIM_SCGC_SWD(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_SWD_SHIFT))&SIM_SCGC_SWD_MASK) /**< SIM_SCGC.SWD Field                      */
#define SIM_SCGC_I2C_MASK                        (0x20000U)                                          /**< SIM_SCGC.I2C Mask                       */
#define SIM_SCGC_I2C_SHIFT                       (17U)                                               /**< SIM_SCGC.I2C Position                   */
#define SIM_SCGC_I2C(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_I2C_SHIFT))&SIM_SCGC_I2C_MASK) /**< SIM_SCGC.I2C Field                      */
#define SIM_SCGC_SPI0_MASK                       (0x40000U)                                          /**< SIM_SCGC.SPI0 Mask                      */
#define SIM_SCGC_SPI0_SHIFT                      (18U)                                               /**< SIM_SCGC.SPI0 Position                  */
#define SIM_SCGC_SPI0(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_SPI0_SHIFT))&SIM_SCGC_SPI0_MASK) /**< SIM_SCGC.SPI0 Field                     */
#define SIM_SCGC_SPI1_MASK                       (0x80000U)                                          /**< SIM_SCGC.SPI1 Mask                      */
#define SIM_SCGC_SPI1_SHIFT                      (19U)                                               /**< SIM_SCGC.SPI1 Position                  */
#define SIM_SCGC_SPI1(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_SPI1_SHIFT))&SIM_SCGC_SPI1_MASK) /**< SIM_SCGC.SPI1 Field                     */
#define SIM_SCGC_UART0_MASK                      (0x100000U)                                         /**< SIM_SCGC.UART0 Mask                     */
#define SIM_SCGC_UART0_SHIFT                     (20U)                                               /**< SIM_SCGC.UART0 Position                 */
#define SIM_SCGC_UART0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_UART0_SHIFT))&SIM_SCGC_UART0_MASK) /**< SIM_SCGC.UART0 Field                    */
#define SIM_SCGC_UART1_MASK                      (0x200000U)                                         /**< SIM_SCGC.UART1 Mask                     */
#define SIM_SCGC_UART1_SHIFT                     (21U)                                               /**< SIM_SCGC.UART1 Position                 */
#define SIM_SCGC_UART1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_UART1_SHIFT))&SIM_SCGC_UART1_MASK) /**< SIM_SCGC.UART1 Field                    */
#define SIM_SCGC_UART2_MASK                      (0x400000U)                                         /**< SIM_SCGC.UART2 Mask                     */
#define SIM_SCGC_UART2_SHIFT                     (22U)                                               /**< SIM_SCGC.UART2 Position                 */
#define SIM_SCGC_UART2(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_UART2_SHIFT))&SIM_SCGC_UART2_MASK) /**< SIM_SCGC.UART2 Field                    */
#define SIM_SCGC_KBI0_MASK                       (0x1000000U)                                        /**< SIM_SCGC.KBI0 Mask                      */
#define SIM_SCGC_KBI0_SHIFT                      (24U)                                               /**< SIM_SCGC.KBI0 Position                  */
#define SIM_SCGC_KBI0(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_KBI0_SHIFT))&SIM_SCGC_KBI0_MASK) /**< SIM_SCGC.KBI0 Field                     */
#define SIM_SCGC_KBI1_MASK                       (0x2000000U)                                        /**< SIM_SCGC.KBI1 Mask                      */
#define SIM_SCGC_KBI1_SHIFT                      (25U)                                               /**< SIM_SCGC.KBI1 Position                  */
#define SIM_SCGC_KBI1(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_KBI1_SHIFT))&SIM_SCGC_KBI1_MASK) /**< SIM_SCGC.KBI1 Field                     */
#define SIM_SCGC_IRQ_MASK                        (0x8000000U)                                        /**< SIM_SCGC.IRQ Mask                       */
#define SIM_SCGC_IRQ_SHIFT                       (27U)                                               /**< SIM_SCGC.IRQ Position                   */
#define SIM_SCGC_IRQ(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_IRQ_SHIFT))&SIM_SCGC_IRQ_MASK) /**< SIM_SCGC.IRQ Field                      */
#define SIM_SCGC_ADC_MASK                        (0x20000000U)                                       /**< SIM_SCGC.ADC Mask                       */
#define SIM_SCGC_ADC_SHIFT                       (29U)                                               /**< SIM_SCGC.ADC Position                   */
#define SIM_SCGC_ADC(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_ADC_SHIFT))&SIM_SCGC_ADC_MASK) /**< SIM_SCGC.ADC Field                      */
#define SIM_SCGC_ACMP0_MASK                      (0x40000000U)                                       /**< SIM_SCGC.ACMP0 Mask                     */
#define SIM_SCGC_ACMP0_SHIFT                     (30U)                                               /**< SIM_SCGC.ACMP0 Position                 */
#define SIM_SCGC_ACMP0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_ACMP0_SHIFT))&SIM_SCGC_ACMP0_MASK) /**< SIM_SCGC.ACMP0 Field                    */
#define SIM_SCGC_ACMP1_MASK                      (0x80000000U)                                       /**< SIM_SCGC.ACMP1 Mask                     */
#define SIM_SCGC_ACMP1_SHIFT                     (31U)                                               /**< SIM_SCGC.ACMP1 Position                 */
#define SIM_SCGC_ACMP1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC_ACMP1_SHIFT))&SIM_SCGC_ACMP1_MASK) /**< SIM_SCGC.ACMP1 Field                    */
/** @} */

/** @name BUSDIV - BUS Clock Divider Register */ /** @{ */
#define SIM_BUSDIV_BUSDIV_MASK                   (0x1U)                                              /**< SIM_BUSDIV.BUSDIV Mask                  */
#define SIM_BUSDIV_BUSDIV_SHIFT                  (0U)                                                /**< SIM_BUSDIV.BUSDIV Position              */
#define SIM_BUSDIV_BUSDIV(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_BUSDIV_BUSDIV_SHIFT))&SIM_BUSDIV_BUSDIV_MASK) /**< SIM_BUSDIV.BUSDIV Field                 */
/** @} */

/** @} */ /* End group SIM_Register_Masks_GROUP */


/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0x40048000UL //!< Peripheral base address
#define SIM                            ((SIM_Type *) SIM_BasePtr) //!< Freescale base pointer
#define SIM_BASE_PTR                   (SIM) //!< Freescale style base pointer

/** @} */ /* End group SIM_Peripheral_access_layer_GROUP */


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


/** @brief C Struct for UART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           UART0 (file:UART0_MKE)               ================ */
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
#define UART_C1_UARTSWAI_MASK                    (0x40U)                                             /**< UART0_C1.UARTSWAI Mask                  */
#define UART_C1_UARTSWAI_SHIFT                   (6U)                                                /**< UART0_C1.UARTSWAI Position              */
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C1_UARTSWAI_SHIFT))&UART_C1_UARTSWAI_MASK) /**< UART0_C1.UARTSWAI Field                 */
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
#define UART_C3_T8_MASK                          (0x40U)                                             /**< UART0_C3.T8 Mask                        */
#define UART_C3_T8_SHIFT                         (6U)                                                /**< UART0_C3.T8 Position                    */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_T8_SHIFT))&UART_C3_T8_MASK) /**< UART0_C3.T8 Field                       */
#define UART_C3_R8_MASK                          (0x80U)                                             /**< UART0_C3.R8 Mask                        */
#define UART_C3_R8_SHIFT                         (7U)                                                /**< UART0_C3.R8 Position                    */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_R8_SHIFT))&UART_C3_R8_MASK) /**< UART0_C3.R8 Field                       */
/** @} */

/** @name D - Data Register */ /** @{ */
#define UART_D_RT_MASK                           (0xFFU)                                             /**< UART0_D.RT Mask                         */
#define UART_D_RT_SHIFT                          (0U)                                                /**< UART0_D.RT Position                     */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /**< UART0_D.RT Field                        */
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
/* ================           UART1 (derived from UART0)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x4006B000UL //!< Peripheral base address
#define UART1                          ((UART_Type *) UART1_BasePtr) //!< Freescale base pointer
#define UART1_BASE_PTR                 (UART1) //!< Freescale style base pointer
#define UART1_IRQS { UART1_IRQn,  }


/** @} */ /* End group UART_Peripheral_access_layer_GROUP */


/** @brief C Struct for UART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           UART2 (derived from UART0)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x4006C000UL //!< Peripheral base address
#define UART2                          ((UART_Type *) UART2_BasePtr) //!< Freescale base pointer
#define UART2_BASE_PTR                 (UART2) //!< Freescale style base pointer
#define UART2_IRQS { UART2_IRQn,  }


/** @} */ /* End group UART_Peripheral_access_layer_GROUP */


/** @brief C Struct for WDOG */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup WDOG_Peripheral_access_layer_GROUP WDOG Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           WDOG (file:WDOG_MKE)                 ================ */
/* ================================================================================ */

/**
 * @brief Watchdog timer
 */
/**
 * @struct WDOG_Type
 * @brief  C Struct allowing access to WDOG registers
 */
typedef struct WDOG_Type {
   __IO uint8_t   CS1;                          /**< 0000: Control and Status Register 1                                */
   __IO uint8_t   CS2;                          /**< 0001: Control and Status Register 2                                */
   union {                                      /**< 0002: (size=0002)                                                  */
      __IO uint16_t  CNT;                       /**< 0002: Counter Register: (Note: Transposed CNTL:CNTH)               */
      struct {                                  /**< 0002: (size=0002)                                                  */
         __I  uint8_t   CNTH;                   /**< 0002: Counter Register: High (see CNT for description)             */
         __I  uint8_t   CNTL;                   /**< 0003: Counter Register: Low (see CNT for description)              */
      };
   };
   union {                                      /**< 0004: (size=0002)                                                  */
      __IO uint16_t  TOVAL;                     /**< 0004: Timeout Value Register: (Note Transposed TOVALL:TOVALH)      */
      struct {                                  /**< 0004: (size=0002)                                                  */
         __IO uint8_t   TOVALH;                 /**< 0004: Timeout Value Register: High (see TOVAL for description)     */
         __IO uint8_t   TOVALL;                 /**< 0005: Timeout Value Register: Low (see TOVAL for description)      */
      };
   };
   union {                                      /**< 0006: (size=0002)                                                  */
      __IO uint16_t  WIN;                       /**< 0006: Window Register:(Note Transposed WINL:WINH)                  */
      struct {                                  /**< 0006: (size=0002)                                                  */
         __IO uint8_t   WINH;                   /**< 0006: Window Register: High (see WIN for description)              */
         __IO uint8_t   WINL;                   /**< 0007: Window Register: Low (see WIN for description)               */
      };
   };
} WDOG_Type;


/** @brief Register Masks for WDOG */

/* -------------------------------------------------------------------------------- */
/* -----------     'WDOG' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup WDOG_Register_Masks_GROUP WDOG Register Masks */
/** @{ */

/** @name CS1 - Control and Status Register 1 */ /** @{ */
#define WDOG_CS1_STOP_MASK                       (0x1U)                                              /**< WDOG_CS1.STOP Mask                      */
#define WDOG_CS1_STOP_SHIFT                      (0U)                                                /**< WDOG_CS1.STOP Position                  */
#define WDOG_CS1_STOP(x)                         (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_STOP_SHIFT))&WDOG_CS1_STOP_MASK) /**< WDOG_CS1.STOP Field                     */
#define WDOG_CS1_WAIT_MASK                       (0x2U)                                              /**< WDOG_CS1.WAIT Mask                      */
#define WDOG_CS1_WAIT_SHIFT                      (1U)                                                /**< WDOG_CS1.WAIT Position                  */
#define WDOG_CS1_WAIT(x)                         (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_WAIT_SHIFT))&WDOG_CS1_WAIT_MASK) /**< WDOG_CS1.WAIT Field                     */
#define WDOG_CS1_DBG_MASK                        (0x4U)                                              /**< WDOG_CS1.DBG Mask                       */
#define WDOG_CS1_DBG_SHIFT                       (2U)                                                /**< WDOG_CS1.DBG Position                   */
#define WDOG_CS1_DBG(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_DBG_SHIFT))&WDOG_CS1_DBG_MASK) /**< WDOG_CS1.DBG Field                      */
#define WDOG_CS1_TST_MASK                        (0x18U)                                             /**< WDOG_CS1.TST Mask                       */
#define WDOG_CS1_TST_SHIFT                       (3U)                                                /**< WDOG_CS1.TST Position                   */
#define WDOG_CS1_TST(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_TST_SHIFT))&WDOG_CS1_TST_MASK) /**< WDOG_CS1.TST Field                      */
#define WDOG_CS1_UPDATE_MASK                     (0x20U)                                             /**< WDOG_CS1.UPDATE Mask                    */
#define WDOG_CS1_UPDATE_SHIFT                    (5U)                                                /**< WDOG_CS1.UPDATE Position                */
#define WDOG_CS1_UPDATE(x)                       (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_UPDATE_SHIFT))&WDOG_CS1_UPDATE_MASK) /**< WDOG_CS1.UPDATE Field                   */
#define WDOG_CS1_INT_MASK                        (0x40U)                                             /**< WDOG_CS1.INT Mask                       */
#define WDOG_CS1_INT_SHIFT                       (6U)                                                /**< WDOG_CS1.INT Position                   */
#define WDOG_CS1_INT(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_INT_SHIFT))&WDOG_CS1_INT_MASK) /**< WDOG_CS1.INT Field                      */
#define WDOG_CS1_EN_MASK                         (0x80U)                                             /**< WDOG_CS1.EN Mask                        */
#define WDOG_CS1_EN_SHIFT                        (7U)                                                /**< WDOG_CS1.EN Position                    */
#define WDOG_CS1_EN(x)                           (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_EN_SHIFT))&WDOG_CS1_EN_MASK) /**< WDOG_CS1.EN Field                       */
/** @} */

/** @name CS2 - Control and Status Register 2 */ /** @{ */
#define WDOG_CS2_CLK_MASK                        (0x3U)                                              /**< WDOG_CS2.CLK Mask                       */
#define WDOG_CS2_CLK_SHIFT                       (0U)                                                /**< WDOG_CS2.CLK Position                   */
#define WDOG_CS2_CLK(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS2_CLK_SHIFT))&WDOG_CS2_CLK_MASK) /**< WDOG_CS2.CLK Field                      */
#define WDOG_CS2_PRES_MASK                       (0x10U)                                             /**< WDOG_CS2.PRES Mask                      */
#define WDOG_CS2_PRES_SHIFT                      (4U)                                                /**< WDOG_CS2.PRES Position                  */
#define WDOG_CS2_PRES(x)                         (((uint8_t)(((uint8_t)(x))<<WDOG_CS2_PRES_SHIFT))&WDOG_CS2_PRES_MASK) /**< WDOG_CS2.PRES Field                     */
#define WDOG_CS2_FLG_MASK                        (0x40U)                                             /**< WDOG_CS2.FLG Mask                       */
#define WDOG_CS2_FLG_SHIFT                       (6U)                                                /**< WDOG_CS2.FLG Position                   */
#define WDOG_CS2_FLG(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS2_FLG_SHIFT))&WDOG_CS2_FLG_MASK) /**< WDOG_CS2.FLG Field                      */
#define WDOG_CS2_WIN_MASK                        (0x80U)                                             /**< WDOG_CS2.WIN Mask                       */
#define WDOG_CS2_WIN_SHIFT                       (7U)                                                /**< WDOG_CS2.WIN Position                   */
#define WDOG_CS2_WIN(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS2_WIN_SHIFT))&WDOG_CS2_WIN_MASK) /**< WDOG_CS2.WIN Field                      */
/** @} */

/** @name CNT - Counter Register: (Note: Transposed CNTL:CNTH) */ /** @{ */
#define WDOG_CNT_COUNT_MASK                      (0xFFFFU)                                           /**< WDOG_CNT.COUNT Mask                     */
#define WDOG_CNT_COUNT_SHIFT                     (0U)                                                /**< WDOG_CNT.COUNT Position                 */
#define WDOG_CNT_COUNT(x)                        (((uint16_t)(((uint16_t)(x))<<WDOG_CNT_COUNT_SHIFT))&WDOG_CNT_COUNT_MASK) /**< WDOG_CNT.COUNT Field                    */
/** @} */

/** @name TOVAL - Timeout Value Register: (Note Transposed TOVALL:TOVALH) */ /** @{ */
#define WDOG_TOVAL_TOVAL_MASK                    (0xFFFFU)                                           /**< WDOG_TOVAL.TOVAL Mask                   */
#define WDOG_TOVAL_TOVAL_SHIFT                   (0U)                                                /**< WDOG_TOVAL.TOVAL Position               */
#define WDOG_TOVAL_TOVAL(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_TOVAL_TOVAL_SHIFT))&WDOG_TOVAL_TOVAL_MASK) /**< WDOG_TOVAL.TOVAL Field                  */
/** @} */

/** @name WIN - Window Register:(Note Transposed WINL:WINH) */ /** @{ */
#define WDOG_WIN_WIN_MASK                        (0xFFFFU)                                           /**< WDOG_WIN.WIN Mask                       */
#define WDOG_WIN_WIN_SHIFT                       (0U)                                                /**< WDOG_WIN.WIN Position                   */
#define WDOG_WIN_WIN(x)                          (((uint16_t)(((uint16_t)(x))<<WDOG_WIN_WIN_SHIFT))&WDOG_WIN_WIN_MASK) /**< WDOG_WIN.WIN Field                      */
/** @} */

/** @} */ /* End group WDOG_Register_Masks_GROUP */


/* WDOG - Peripheral instance base addresses */
#define WDOG_BasePtr                   0x40052000UL //!< Peripheral base address
#define WDOG                           ((WDOG_Type *) WDOG_BasePtr) //!< Freescale base pointer
#define WDOG_BASE_PTR                  (WDOG) //!< Freescale style base pointer
#define WDOG_IRQS { WDOG_IRQn,  }


/** @} */ /* End group WDOG_Peripheral_access_layer_GROUP */

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


#endif  /* MCU_MKE02Z4 */

