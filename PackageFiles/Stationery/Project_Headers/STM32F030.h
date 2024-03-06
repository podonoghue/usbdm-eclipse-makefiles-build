/*!
 * @file     STM32F030.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for STM32F030.
 *           Equivalent: 
 *
 * @version  V1.0
 * @date     2024/02
 *
 */

#ifndef _STM32F030_H_
#define _STM32F030_H_

#define MCU_STM32F030

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif


/** @brief Vector numbers required for NVIC functions */
/** @addtogroup Interrupt_vector_numbers_GROUP Interrupt vector numbers */
/** @{ */
#define NUMBER_OF_INT_VECTORS 46 //<! Number of vector table entries
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
/* ----------------------   STM32F030 VectorTable                    ---------------------- */
  WWDG_IRQn                     =   0,   /**<  16 Window Watchdog interrupt                                                        */
  PVD_IRQn                      =   1,   /**<  17 PVD and VDDIO2 supply comparator
interrupt                                       */
  RCC_CRS_IRQn                  =   4,   /**<  20 RCC and CRS global interrupts                                                    */
  EXTI0_1_IRQn                  =   5,   /**<  21 EXTI Line[1:0] interrupts                                                        */
  EXTI2_3_IRQn                  =   6,   /**<  22 EXTI Line[3:2] interrupts                                                        */
  EXTI4_15_IRQn                 =   7,   /**<  23 EXTI Line15 and EXTI4 interrupts                                                 */
  DMA0_Ch1_IRQn                 =   9,   /**<  25 DMA channel 1 interrupt                                                          */
  DMA0_Ch2_3_IRQn               =  10,   /**<  26 DMA channel 2 and 3 interrupts                                                   */
  DMA0_Ch4_5_6_7_IRQn           =  11,   /**<  27 DMA channel 4, 5, 6 and 7
interrupts                                             */
  ADC_COMP_IRQn                 =  12,   /**<  28 ADC and comparator interrupts                                                    */
  TIM1_BRK_UP_TRG_COM_IRQn      =  13,   /**<  29 TIM1 break, update, trigger and commutation
interrupt                            */
  TIM1_CC_IRQn                  =  14,   /**<  30 TIM1 Capture Compare interrupt                                                   */
  TIM2_IRQn                     =  15,   /**<  31 TIM2 global interrupt                                                            */
  TIM3_IRQn                     =  16,   /**<  32 TIM3 global interrupt                                                            */
  TIM6_DAC_IRQn                 =  17,   /**<  33 TIM6 global interrupt and DAC underrun
interrupt                                 */
  TIM7_IRQn                     =  18,   /**<  34 TIM7 global interrupt                                                            */
  TIM14_IRQn                    =  19,   /**<  35 TIM14 global interrupt                                                           */
  I2C1_IRQn                     =  23,   /**<  39 I2C1 global interrupt                                                            */
  I2C2_IRQn                     =  24,   /**<  40 I2C2 global interrupt                                                            */
  SPI1_IRQn                     =  25,   /**<  41 SPI1_global_interrupt                                                            */
  SPI2_IRQn                     =  26,   /**<  42 SPI2 global interrupt                                                            */
  USART1_IRQn                   =  27,   /**<  43 USART1 global interrupt                                                          */
  USART2_IRQn                   =  28,   /**<  44 USART2 global interrupt                                                          */
  USART3_4_IRQn                 =  29,   /**<  45 USART3 and USART4 global
interrupt                                               */
} IRQn_Type;


/** @brief Prototypes for interrupt handlers */
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                       /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);                 /**< Hard Fault, all classes of Fault                                                 */
extern void SVC_Handler(void);                       /**< System Service Call via SVC instruction                                          */
extern void PendSV_Handler(void);                    /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);                   /**< System Tick Timer                                                                */
extern void WWDG_IRQHandler(void);                   /**< Window Watchdog interrupt                                                        */
extern void PVD_IRQHandler(void);                    /**< PVD and VDDIO2 supply comparator
interrupt                                       */
extern void RCC_CRS_IRQHandler(void);                /**< RCC and CRS global interrupts                                                    */
extern void EXTI0_1_IRQHandler(void);                /**< EXTI Line[1:0] interrupts                                                        */
extern void EXTI2_3_IRQHandler(void);                /**< EXTI Line[3:2] interrupts                                                        */
extern void EXTI4_15_IRQHandler(void);               /**< EXTI Line15 and EXTI4 interrupts                                                 */
extern void DMA0_Ch1_IRQHandler(void);               /**< DMA channel 1 interrupt                                                          */
extern void DMA0_Ch2_3_IRQHandler(void);             /**< DMA channel 2 and 3 interrupts                                                   */
extern void DMA0_Ch4_5_6_7_IRQHandler(void);         /**< DMA channel 4, 5, 6 and 7
interrupts                                             */
extern void ADC_COMP_IRQHandler(void);               /**< ADC and comparator interrupts                                                    */
extern void TIM1_BRK_UP_TRG_COM_IRQHandler(void);    /**< TIM1 break, update, trigger and commutation
interrupt                            */
extern void TIM1_CC_IRQHandler(void);                /**< TIM1 Capture Compare interrupt                                                   */
extern void TIM2_IRQHandler(void);                   /**< TIM2 global interrupt                                                            */
extern void TIM3_IRQHandler(void);                   /**< TIM3 global interrupt                                                            */
extern void TIM6_DAC_IRQHandler(void);               /**< TIM6 global interrupt and DAC underrun
interrupt                                 */
extern void TIM7_IRQHandler(void);                   /**< TIM7 global interrupt                                                            */
extern void TIM14_IRQHandler(void);                  /**< TIM14 global interrupt                                                           */
extern void I2C1_IRQHandler(void);                   /**< I2C1 global interrupt                                                            */
extern void I2C2_IRQHandler(void);                   /**< I2C2 global interrupt                                                            */
extern void SPI1_IRQHandler(void);                   /**< SPI1_global_interrupt                                                            */
extern void SPI2_IRQHandler(void);                   /**< SPI2 global interrupt                                                            */
extern void USART1_IRQHandler(void);                 /**< USART1 global interrupt                                                          */
extern void USART2_IRQHandler(void);                 /**< USART2 global interrupt                                                          */
extern void USART3_4_IRQHandler(void);               /**< USART3 and USART4 global
interrupt                                               */


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
/* ================           ADC (file:ADC_STM32F030)             ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-digital converter
 */
/**
 * @struct ADC_Type
 * @brief  C Struct allowing access to ADC registers
 */
typedef struct ADC_Type {
   __IO uint32_t  ISR;                          /**< 0000: interrupt and status register                                */
   __IO uint32_t  IER;                          /**< 0004: interrupt enable register                                    */
   __IO uint32_t  CR;                           /**< 0008: control register                                             */
   __IO uint32_t  CFGR1;                        /**< 000C: configuration register 1                                     */
   __IO uint32_t  CFGR2;                        /**< 0010: configuration register 2                                     */
   __IO uint32_t  SMPR;                         /**< 0014: sampling time register                                       */
        uint8_t   RESERVED_0[8];                /**< 0018: 0x8 bytes                                                    */
   __IO uint32_t  TR;                           /**< 0020: watchdog threshold register                                  */
        uint8_t   RESERVED_1[4];                /**< 0024: 0x4 bytes                                                    */
   __IO uint32_t  CHSELR;                       /**< 0028: channel selection register                                   */
        uint8_t   RESERVED_2[20];               /**< 002C: 0x14 bytes                                                   */
   __I  uint32_t  DR;                           /**< 0040: data register                                                */
        uint8_t   RESERVED_3[708];              /**< 0044: 0x2C4 bytes                                                  */
   __IO uint32_t  CCR;                          /**< 0308: common configuration register                                */
} ADC_Type;


/** @brief Register Masks for ADC */

/* -------------------------------------------------------------------------------- */
/* -----------     'ADC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup ADC_Register_Masks_GROUP ADC Register Masks */
/** @{ */

/** @name ISR - interrupt and status register */ /** @{ */
#define ADC_ISR_ADRDY_MASK                       (0x1U)                                              /**< ADC_ISR.ADRDY Mask                      */
#define ADC_ISR_ADRDY_SHIFT                      (0U)                                                /**< ADC_ISR.ADRDY Position                  */
#define ADC_ISR_ADRDY(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_ISR_ADRDY_SHIFT))&ADC_ISR_ADRDY_MASK) /**< ADC_ISR.ADRDY Field                     */
#define ADC_ISR_EOSMP_MASK                       (0x2U)                                              /**< ADC_ISR.EOSMP Mask                      */
#define ADC_ISR_EOSMP_SHIFT                      (1U)                                                /**< ADC_ISR.EOSMP Position                  */
#define ADC_ISR_EOSMP(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_ISR_EOSMP_SHIFT))&ADC_ISR_EOSMP_MASK) /**< ADC_ISR.EOSMP Field                     */
#define ADC_ISR_EOC_MASK                         (0x4U)                                              /**< ADC_ISR.EOC Mask                        */
#define ADC_ISR_EOC_SHIFT                        (2U)                                                /**< ADC_ISR.EOC Position                    */
#define ADC_ISR_EOC(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_ISR_EOC_SHIFT))&ADC_ISR_EOC_MASK) /**< ADC_ISR.EOC Field                       */
#define ADC_ISR_EOS_MASK                         (0x8U)                                              /**< ADC_ISR.EOS Mask                        */
#define ADC_ISR_EOS_SHIFT                        (3U)                                                /**< ADC_ISR.EOS Position                    */
#define ADC_ISR_EOS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_ISR_EOS_SHIFT))&ADC_ISR_EOS_MASK) /**< ADC_ISR.EOS Field                       */
#define ADC_ISR_OVR_MASK                         (0x10U)                                             /**< ADC_ISR.OVR Mask                        */
#define ADC_ISR_OVR_SHIFT                        (4U)                                                /**< ADC_ISR.OVR Position                    */
#define ADC_ISR_OVR(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_ISR_OVR_SHIFT))&ADC_ISR_OVR_MASK) /**< ADC_ISR.OVR Field                       */
#define ADC_ISR_AWD_MASK                         (0x80U)                                             /**< ADC_ISR.AWD Mask                        */
#define ADC_ISR_AWD_SHIFT                        (7U)                                                /**< ADC_ISR.AWD Position                    */
#define ADC_ISR_AWD(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_ISR_AWD_SHIFT))&ADC_ISR_AWD_MASK) /**< ADC_ISR.AWD Field                       */
/** @} */

/** @name IER - interrupt enable register */ /** @{ */
#define ADC_IER_ADRDYIE_MASK                     (0x1U)                                              /**< ADC_IER.ADRDYIE Mask                    */
#define ADC_IER_ADRDYIE_SHIFT                    (0U)                                                /**< ADC_IER.ADRDYIE Position                */
#define ADC_IER_ADRDYIE(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_IER_ADRDYIE_SHIFT))&ADC_IER_ADRDYIE_MASK) /**< ADC_IER.ADRDYIE Field                   */
#define ADC_IER_EOSMPIE_MASK                     (0x2U)                                              /**< ADC_IER.EOSMPIE Mask                    */
#define ADC_IER_EOSMPIE_SHIFT                    (1U)                                                /**< ADC_IER.EOSMPIE Position                */
#define ADC_IER_EOSMPIE(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_IER_EOSMPIE_SHIFT))&ADC_IER_EOSMPIE_MASK) /**< ADC_IER.EOSMPIE Field                   */
#define ADC_IER_EOCIE_MASK                       (0x4U)                                              /**< ADC_IER.EOCIE Mask                      */
#define ADC_IER_EOCIE_SHIFT                      (2U)                                                /**< ADC_IER.EOCIE Position                  */
#define ADC_IER_EOCIE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_IER_EOCIE_SHIFT))&ADC_IER_EOCIE_MASK) /**< ADC_IER.EOCIE Field                     */
#define ADC_IER_EOSIE_MASK                       (0x8U)                                              /**< ADC_IER.EOSIE Mask                      */
#define ADC_IER_EOSIE_SHIFT                      (3U)                                                /**< ADC_IER.EOSIE Position                  */
#define ADC_IER_EOSIE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_IER_EOSIE_SHIFT))&ADC_IER_EOSIE_MASK) /**< ADC_IER.EOSIE Field                     */
#define ADC_IER_OVRIE_MASK                       (0x10U)                                             /**< ADC_IER.OVRIE Mask                      */
#define ADC_IER_OVRIE_SHIFT                      (4U)                                                /**< ADC_IER.OVRIE Position                  */
#define ADC_IER_OVRIE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_IER_OVRIE_SHIFT))&ADC_IER_OVRIE_MASK) /**< ADC_IER.OVRIE Field                     */
#define ADC_IER_AWDIE_MASK                       (0x80U)                                             /**< ADC_IER.AWDIE Mask                      */
#define ADC_IER_AWDIE_SHIFT                      (7U)                                                /**< ADC_IER.AWDIE Position                  */
#define ADC_IER_AWDIE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_IER_AWDIE_SHIFT))&ADC_IER_AWDIE_MASK) /**< ADC_IER.AWDIE Field                     */
/** @} */

/** @name CR - control register */ /** @{ */
#define ADC_CR_ADEN_MASK                         (0x1U)                                              /**< ADC_CR.ADEN Mask                        */
#define ADC_CR_ADEN_SHIFT                        (0U)                                                /**< ADC_CR.ADEN Position                    */
#define ADC_CR_ADEN(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_CR_ADEN_SHIFT))&ADC_CR_ADEN_MASK) /**< ADC_CR.ADEN Field                       */
#define ADC_CR_ADDIS_MASK                        (0x2U)                                              /**< ADC_CR.ADDIS Mask                       */
#define ADC_CR_ADDIS_SHIFT                       (1U)                                                /**< ADC_CR.ADDIS Position                   */
#define ADC_CR_ADDIS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_CR_ADDIS_SHIFT))&ADC_CR_ADDIS_MASK) /**< ADC_CR.ADDIS Field                      */
#define ADC_CR_ADSTART_MASK                      (0x4U)                                              /**< ADC_CR.ADSTART Mask                     */
#define ADC_CR_ADSTART_SHIFT                     (2U)                                                /**< ADC_CR.ADSTART Position                 */
#define ADC_CR_ADSTART(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CR_ADSTART_SHIFT))&ADC_CR_ADSTART_MASK) /**< ADC_CR.ADSTART Field                    */
#define ADC_CR_ADSTP_MASK                        (0x10U)                                             /**< ADC_CR.ADSTP Mask                       */
#define ADC_CR_ADSTP_SHIFT                       (4U)                                                /**< ADC_CR.ADSTP Position                   */
#define ADC_CR_ADSTP(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_CR_ADSTP_SHIFT))&ADC_CR_ADSTP_MASK) /**< ADC_CR.ADSTP Field                      */
#define ADC_CR_ADCAL_MASK                        (0x80000000U)                                       /**< ADC_CR.ADCAL Mask                       */
#define ADC_CR_ADCAL_SHIFT                       (31U)                                               /**< ADC_CR.ADCAL Position                   */
#define ADC_CR_ADCAL(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_CR_ADCAL_SHIFT))&ADC_CR_ADCAL_MASK) /**< ADC_CR.ADCAL Field                      */
/** @} */

/** @name CFGR1 - configuration register 1 */ /** @{ */
#define ADC_CFGR1_DMAEN_MASK                     (0x1U)                                              /**< ADC_CFGR1.DMAEN Mask                    */
#define ADC_CFGR1_DMAEN_SHIFT                    (0U)                                                /**< ADC_CFGR1.DMAEN Position                */
#define ADC_CFGR1_DMAEN(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_DMAEN_SHIFT))&ADC_CFGR1_DMAEN_MASK) /**< ADC_CFGR1.DMAEN Field                   */
#define ADC_CFGR1_DMACFG_MASK                    (0x2U)                                              /**< ADC_CFGR1.DMACFG Mask                   */
#define ADC_CFGR1_DMACFG_SHIFT                   (1U)                                                /**< ADC_CFGR1.DMACFG Position               */
#define ADC_CFGR1_DMACFG(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_DMACFG_SHIFT))&ADC_CFGR1_DMACFG_MASK) /**< ADC_CFGR1.DMACFG Field                  */
#define ADC_CFGR1_SCANDIR_MASK                   (0x4U)                                              /**< ADC_CFGR1.SCANDIR Mask                  */
#define ADC_CFGR1_SCANDIR_SHIFT                  (2U)                                                /**< ADC_CFGR1.SCANDIR Position              */
#define ADC_CFGR1_SCANDIR(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_SCANDIR_SHIFT))&ADC_CFGR1_SCANDIR_MASK) /**< ADC_CFGR1.SCANDIR Field                 */
#define ADC_CFGR1_RES_MASK                       (0x18U)                                             /**< ADC_CFGR1.RES Mask                      */
#define ADC_CFGR1_RES_SHIFT                      (3U)                                                /**< ADC_CFGR1.RES Position                  */
#define ADC_CFGR1_RES(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_RES_SHIFT))&ADC_CFGR1_RES_MASK) /**< ADC_CFGR1.RES Field                     */
#define ADC_CFGR1_ALIGN_MASK                     (0x20U)                                             /**< ADC_CFGR1.ALIGN Mask                    */
#define ADC_CFGR1_ALIGN_SHIFT                    (5U)                                                /**< ADC_CFGR1.ALIGN Position                */
#define ADC_CFGR1_ALIGN(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_ALIGN_SHIFT))&ADC_CFGR1_ALIGN_MASK) /**< ADC_CFGR1.ALIGN Field                   */
#define ADC_CFGR1_EXTSEL_MASK                    (0x1C0U)                                            /**< ADC_CFGR1.EXTSEL Mask                   */
#define ADC_CFGR1_EXTSEL_SHIFT                   (6U)                                                /**< ADC_CFGR1.EXTSEL Position               */
#define ADC_CFGR1_EXTSEL(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_EXTSEL_SHIFT))&ADC_CFGR1_EXTSEL_MASK) /**< ADC_CFGR1.EXTSEL Field                  */
#define ADC_CFGR1_EXTEN_MASK                     (0xC00U)                                            /**< ADC_CFGR1.EXTEN Mask                    */
#define ADC_CFGR1_EXTEN_SHIFT                    (10U)                                               /**< ADC_CFGR1.EXTEN Position                */
#define ADC_CFGR1_EXTEN(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_EXTEN_SHIFT))&ADC_CFGR1_EXTEN_MASK) /**< ADC_CFGR1.EXTEN Field                   */
#define ADC_CFGR1_OVRMOD_MASK                    (0x1000U)                                           /**< ADC_CFGR1.OVRMOD Mask                   */
#define ADC_CFGR1_OVRMOD_SHIFT                   (12U)                                               /**< ADC_CFGR1.OVRMOD Position               */
#define ADC_CFGR1_OVRMOD(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_OVRMOD_SHIFT))&ADC_CFGR1_OVRMOD_MASK) /**< ADC_CFGR1.OVRMOD Field                  */
#define ADC_CFGR1_CONT_MASK                      (0x2000U)                                           /**< ADC_CFGR1.CONT Mask                     */
#define ADC_CFGR1_CONT_SHIFT                     (13U)                                               /**< ADC_CFGR1.CONT Position                 */
#define ADC_CFGR1_CONT(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_CONT_SHIFT))&ADC_CFGR1_CONT_MASK) /**< ADC_CFGR1.CONT Field                    */
#define ADC_CFGR1_AUTDLY_MASK                    (0x4000U)                                           /**< ADC_CFGR1.AUTDLY Mask                   */
#define ADC_CFGR1_AUTDLY_SHIFT                   (14U)                                               /**< ADC_CFGR1.AUTDLY Position               */
#define ADC_CFGR1_AUTDLY(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_AUTDLY_SHIFT))&ADC_CFGR1_AUTDLY_MASK) /**< ADC_CFGR1.AUTDLY Field                  */
#define ADC_CFGR1_AUTOFF_MASK                    (0x8000U)                                           /**< ADC_CFGR1.AUTOFF Mask                   */
#define ADC_CFGR1_AUTOFF_SHIFT                   (15U)                                               /**< ADC_CFGR1.AUTOFF Position               */
#define ADC_CFGR1_AUTOFF(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_AUTOFF_SHIFT))&ADC_CFGR1_AUTOFF_MASK) /**< ADC_CFGR1.AUTOFF Field                  */
#define ADC_CFGR1_DISCEN_MASK                    (0x10000U)                                          /**< ADC_CFGR1.DISCEN Mask                   */
#define ADC_CFGR1_DISCEN_SHIFT                   (16U)                                               /**< ADC_CFGR1.DISCEN Position               */
#define ADC_CFGR1_DISCEN(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_DISCEN_SHIFT))&ADC_CFGR1_DISCEN_MASK) /**< ADC_CFGR1.DISCEN Field                  */
#define ADC_CFGR1_AWDSGL_MASK                    (0x400000U)                                         /**< ADC_CFGR1.AWDSGL Mask                   */
#define ADC_CFGR1_AWDSGL_SHIFT                   (22U)                                               /**< ADC_CFGR1.AWDSGL Position               */
#define ADC_CFGR1_AWDSGL(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_AWDSGL_SHIFT))&ADC_CFGR1_AWDSGL_MASK) /**< ADC_CFGR1.AWDSGL Field                  */
#define ADC_CFGR1_AWDEN_MASK                     (0x800000U)                                         /**< ADC_CFGR1.AWDEN Mask                    */
#define ADC_CFGR1_AWDEN_SHIFT                    (23U)                                               /**< ADC_CFGR1.AWDEN Position                */
#define ADC_CFGR1_AWDEN(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_AWDEN_SHIFT))&ADC_CFGR1_AWDEN_MASK) /**< ADC_CFGR1.AWDEN Field                   */
#define ADC_CFGR1_AWDCH_MASK                     (0x7C000000U)                                       /**< ADC_CFGR1.AWDCH Mask                    */
#define ADC_CFGR1_AWDCH_SHIFT                    (26U)                                               /**< ADC_CFGR1.AWDCH Position                */
#define ADC_CFGR1_AWDCH(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFGR1_AWDCH_SHIFT))&ADC_CFGR1_AWDCH_MASK) /**< ADC_CFGR1.AWDCH Field                   */
/** @} */

/** @name CFGR2 - configuration register 2 */ /** @{ */
#define ADC_CFGR2_JITOFF_D2_MASK                 (0x40000000U)                                       /**< ADC_CFGR2.JITOFF_D2 Mask                */
#define ADC_CFGR2_JITOFF_D2_SHIFT                (30U)                                               /**< ADC_CFGR2.JITOFF_D2 Position            */
#define ADC_CFGR2_JITOFF_D2(x)                   (((uint32_t)(((uint32_t)(x))<<ADC_CFGR2_JITOFF_D2_SHIFT))&ADC_CFGR2_JITOFF_D2_MASK) /**< ADC_CFGR2.JITOFF_D2 Field               */
#define ADC_CFGR2_JITOFF_D4_MASK                 (0x80000000U)                                       /**< ADC_CFGR2.JITOFF_D4 Mask                */
#define ADC_CFGR2_JITOFF_D4_SHIFT                (31U)                                               /**< ADC_CFGR2.JITOFF_D4 Position            */
#define ADC_CFGR2_JITOFF_D4(x)                   (((uint32_t)(((uint32_t)(x))<<ADC_CFGR2_JITOFF_D4_SHIFT))&ADC_CFGR2_JITOFF_D4_MASK) /**< ADC_CFGR2.JITOFF_D4 Field               */
/** @} */

/** @name SMPR - sampling time register */ /** @{ */
#define ADC_SMPR_SMPR_MASK                       (0x7U)                                              /**< ADC_SMPR.SMPR Mask                      */
#define ADC_SMPR_SMPR_SHIFT                      (0U)                                                /**< ADC_SMPR.SMPR Position                  */
#define ADC_SMPR_SMPR(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SMPR_SMPR_SHIFT))&ADC_SMPR_SMPR_MASK) /**< ADC_SMPR.SMPR Field                     */
/** @} */

/** @name TR - watchdog threshold register */ /** @{ */
#define ADC_TR_LT_MASK                           (0xFFFU)                                            /**< ADC_TR.LT Mask                          */
#define ADC_TR_LT_SHIFT                          (0U)                                                /**< ADC_TR.LT Position                      */
#define ADC_TR_LT(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_TR_LT_SHIFT))&ADC_TR_LT_MASK) /**< ADC_TR.LT Field                         */
#define ADC_TR_HT_MASK                           (0xFFF0000U)                                        /**< ADC_TR.HT Mask                          */
#define ADC_TR_HT_SHIFT                          (16U)                                               /**< ADC_TR.HT Position                      */
#define ADC_TR_HT(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_TR_HT_SHIFT))&ADC_TR_HT_MASK) /**< ADC_TR.HT Field                         */
/** @} */

/** @name CHSELR - channel selection register */ /** @{ */
#define ADC_CHSELR_CHSEL0_MASK                   (0x1U)                                              /**< ADC_CHSELR.CHSEL0 Mask                  */
#define ADC_CHSELR_CHSEL0_SHIFT                  (0U)                                                /**< ADC_CHSELR.CHSEL0 Position              */
#define ADC_CHSELR_CHSEL0(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL0_SHIFT))&ADC_CHSELR_CHSEL0_MASK) /**< ADC_CHSELR.CHSEL0 Field                 */
#define ADC_CHSELR_CHSEL1_MASK                   (0x2U)                                              /**< ADC_CHSELR.CHSEL1 Mask                  */
#define ADC_CHSELR_CHSEL1_SHIFT                  (1U)                                                /**< ADC_CHSELR.CHSEL1 Position              */
#define ADC_CHSELR_CHSEL1(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL1_SHIFT))&ADC_CHSELR_CHSEL1_MASK) /**< ADC_CHSELR.CHSEL1 Field                 */
#define ADC_CHSELR_CHSEL2_MASK                   (0x4U)                                              /**< ADC_CHSELR.CHSEL2 Mask                  */
#define ADC_CHSELR_CHSEL2_SHIFT                  (2U)                                                /**< ADC_CHSELR.CHSEL2 Position              */
#define ADC_CHSELR_CHSEL2(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL2_SHIFT))&ADC_CHSELR_CHSEL2_MASK) /**< ADC_CHSELR.CHSEL2 Field                 */
#define ADC_CHSELR_CHSEL3_MASK                   (0x8U)                                              /**< ADC_CHSELR.CHSEL3 Mask                  */
#define ADC_CHSELR_CHSEL3_SHIFT                  (3U)                                                /**< ADC_CHSELR.CHSEL3 Position              */
#define ADC_CHSELR_CHSEL3(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL3_SHIFT))&ADC_CHSELR_CHSEL3_MASK) /**< ADC_CHSELR.CHSEL3 Field                 */
#define ADC_CHSELR_CHSEL4_MASK                   (0x10U)                                             /**< ADC_CHSELR.CHSEL4 Mask                  */
#define ADC_CHSELR_CHSEL4_SHIFT                  (4U)                                                /**< ADC_CHSELR.CHSEL4 Position              */
#define ADC_CHSELR_CHSEL4(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL4_SHIFT))&ADC_CHSELR_CHSEL4_MASK) /**< ADC_CHSELR.CHSEL4 Field                 */
#define ADC_CHSELR_CHSEL5_MASK                   (0x20U)                                             /**< ADC_CHSELR.CHSEL5 Mask                  */
#define ADC_CHSELR_CHSEL5_SHIFT                  (5U)                                                /**< ADC_CHSELR.CHSEL5 Position              */
#define ADC_CHSELR_CHSEL5(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL5_SHIFT))&ADC_CHSELR_CHSEL5_MASK) /**< ADC_CHSELR.CHSEL5 Field                 */
#define ADC_CHSELR_CHSEL6_MASK                   (0x40U)                                             /**< ADC_CHSELR.CHSEL6 Mask                  */
#define ADC_CHSELR_CHSEL6_SHIFT                  (6U)                                                /**< ADC_CHSELR.CHSEL6 Position              */
#define ADC_CHSELR_CHSEL6(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL6_SHIFT))&ADC_CHSELR_CHSEL6_MASK) /**< ADC_CHSELR.CHSEL6 Field                 */
#define ADC_CHSELR_CHSEL7_MASK                   (0x80U)                                             /**< ADC_CHSELR.CHSEL7 Mask                  */
#define ADC_CHSELR_CHSEL7_SHIFT                  (7U)                                                /**< ADC_CHSELR.CHSEL7 Position              */
#define ADC_CHSELR_CHSEL7(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL7_SHIFT))&ADC_CHSELR_CHSEL7_MASK) /**< ADC_CHSELR.CHSEL7 Field                 */
#define ADC_CHSELR_CHSEL8_MASK                   (0x100U)                                            /**< ADC_CHSELR.CHSEL8 Mask                  */
#define ADC_CHSELR_CHSEL8_SHIFT                  (8U)                                                /**< ADC_CHSELR.CHSEL8 Position              */
#define ADC_CHSELR_CHSEL8(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL8_SHIFT))&ADC_CHSELR_CHSEL8_MASK) /**< ADC_CHSELR.CHSEL8 Field                 */
#define ADC_CHSELR_CHSEL9_MASK                   (0x200U)                                            /**< ADC_CHSELR.CHSEL9 Mask                  */
#define ADC_CHSELR_CHSEL9_SHIFT                  (9U)                                                /**< ADC_CHSELR.CHSEL9 Position              */
#define ADC_CHSELR_CHSEL9(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL9_SHIFT))&ADC_CHSELR_CHSEL9_MASK) /**< ADC_CHSELR.CHSEL9 Field                 */
#define ADC_CHSELR_CHSEL10_MASK                  (0x400U)                                            /**< ADC_CHSELR.CHSEL10 Mask                 */
#define ADC_CHSELR_CHSEL10_SHIFT                 (10U)                                               /**< ADC_CHSELR.CHSEL10 Position             */
#define ADC_CHSELR_CHSEL10(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL10_SHIFT))&ADC_CHSELR_CHSEL10_MASK) /**< ADC_CHSELR.CHSEL10 Field                */
#define ADC_CHSELR_CHSEL11_MASK                  (0x800U)                                            /**< ADC_CHSELR.CHSEL11 Mask                 */
#define ADC_CHSELR_CHSEL11_SHIFT                 (11U)                                               /**< ADC_CHSELR.CHSEL11 Position             */
#define ADC_CHSELR_CHSEL11(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL11_SHIFT))&ADC_CHSELR_CHSEL11_MASK) /**< ADC_CHSELR.CHSEL11 Field                */
#define ADC_CHSELR_CHSEL12_MASK                  (0x1000U)                                           /**< ADC_CHSELR.CHSEL12 Mask                 */
#define ADC_CHSELR_CHSEL12_SHIFT                 (12U)                                               /**< ADC_CHSELR.CHSEL12 Position             */
#define ADC_CHSELR_CHSEL12(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL12_SHIFT))&ADC_CHSELR_CHSEL12_MASK) /**< ADC_CHSELR.CHSEL12 Field                */
#define ADC_CHSELR_CHSEL13_MASK                  (0x2000U)                                           /**< ADC_CHSELR.CHSEL13 Mask                 */
#define ADC_CHSELR_CHSEL13_SHIFT                 (13U)                                               /**< ADC_CHSELR.CHSEL13 Position             */
#define ADC_CHSELR_CHSEL13(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL13_SHIFT))&ADC_CHSELR_CHSEL13_MASK) /**< ADC_CHSELR.CHSEL13 Field                */
#define ADC_CHSELR_CHSEL14_MASK                  (0x4000U)                                           /**< ADC_CHSELR.CHSEL14 Mask                 */
#define ADC_CHSELR_CHSEL14_SHIFT                 (14U)                                               /**< ADC_CHSELR.CHSEL14 Position             */
#define ADC_CHSELR_CHSEL14(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL14_SHIFT))&ADC_CHSELR_CHSEL14_MASK) /**< ADC_CHSELR.CHSEL14 Field                */
#define ADC_CHSELR_CHSEL15_MASK                  (0x8000U)                                           /**< ADC_CHSELR.CHSEL15 Mask                 */
#define ADC_CHSELR_CHSEL15_SHIFT                 (15U)                                               /**< ADC_CHSELR.CHSEL15 Position             */
#define ADC_CHSELR_CHSEL15(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL15_SHIFT))&ADC_CHSELR_CHSEL15_MASK) /**< ADC_CHSELR.CHSEL15 Field                */
#define ADC_CHSELR_CHSEL16_MASK                  (0x10000U)                                          /**< ADC_CHSELR.CHSEL16 Mask                 */
#define ADC_CHSELR_CHSEL16_SHIFT                 (16U)                                               /**< ADC_CHSELR.CHSEL16 Position             */
#define ADC_CHSELR_CHSEL16(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL16_SHIFT))&ADC_CHSELR_CHSEL16_MASK) /**< ADC_CHSELR.CHSEL16 Field                */
#define ADC_CHSELR_CHSEL17_MASK                  (0x20000U)                                          /**< ADC_CHSELR.CHSEL17 Mask                 */
#define ADC_CHSELR_CHSEL17_SHIFT                 (17U)                                               /**< ADC_CHSELR.CHSEL17 Position             */
#define ADC_CHSELR_CHSEL17(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL17_SHIFT))&ADC_CHSELR_CHSEL17_MASK) /**< ADC_CHSELR.CHSEL17 Field                */
#define ADC_CHSELR_CHSEL18_MASK                  (0x40000U)                                          /**< ADC_CHSELR.CHSEL18 Mask                 */
#define ADC_CHSELR_CHSEL18_SHIFT                 (18U)                                               /**< ADC_CHSELR.CHSEL18 Position             */
#define ADC_CHSELR_CHSEL18(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_CHSELR_CHSEL18_SHIFT))&ADC_CHSELR_CHSEL18_MASK) /**< ADC_CHSELR.CHSEL18 Field                */
/** @} */

/** @name DR - data register */ /** @{ */
#define ADC_DR_DATA_MASK                         (0xFFFFU)                                           /**< ADC_DR.DATA Mask                        */
#define ADC_DR_DATA_SHIFT                        (0U)                                                /**< ADC_DR.DATA Position                    */
#define ADC_DR_DATA(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_DR_DATA_SHIFT))&ADC_DR_DATA_MASK) /**< ADC_DR.DATA Field                       */
/** @} */

/** @name CCR - common configuration register */ /** @{ */
#define ADC_CCR_VREFEN_MASK                      (0x400000U)                                         /**< ADC_CCR.VREFEN Mask                     */
#define ADC_CCR_VREFEN_SHIFT                     (22U)                                               /**< ADC_CCR.VREFEN Position                 */
#define ADC_CCR_VREFEN(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CCR_VREFEN_SHIFT))&ADC_CCR_VREFEN_MASK) /**< ADC_CCR.VREFEN Field                    */
#define ADC_CCR_TSEN_MASK                        (0x800000U)                                         /**< ADC_CCR.TSEN Mask                       */
#define ADC_CCR_TSEN_SHIFT                       (23U)                                               /**< ADC_CCR.TSEN Position                   */
#define ADC_CCR_TSEN(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_CCR_TSEN_SHIFT))&ADC_CCR_TSEN_MASK) /**< ADC_CCR.TSEN Field                      */
#define ADC_CCR_VBATEN_MASK                      (0x1000000U)                                        /**< ADC_CCR.VBATEN Mask                     */
#define ADC_CCR_VBATEN_SHIFT                     (24U)                                               /**< ADC_CCR.VBATEN Position                 */
#define ADC_CCR_VBATEN(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CCR_VBATEN_SHIFT))&ADC_CCR_VBATEN_MASK) /**< ADC_CCR.VBATEN Field                    */
/** @} */

/** @} */ /* End group ADC_Register_Masks_GROUP */


/* ADC - Peripheral instance base addresses */
#define ADC_BasePtr                    0x40012400UL //!< Peripheral base address
#define ADC                            ((ADC_Type *) ADC_BasePtr) //!< Freescale base pointer
#define ADC_BASE_PTR                   (ADC) //!< Freescale style base pointer
#define ADC_IRQS { DMA0_Ch1_IRQn, DMA0_Ch2_3_IRQn, DMA0_Ch4_5_6_7_IRQn,  }


/** @} */ /* End group ADC_Peripheral_access_layer_GROUP */


/** @brief C Struct for CRC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           CRC (file:CRC_STM32F030)             ================ */
/* ================================================================================ */

/**
 * @brief cyclic redundancy check calculation
unit
 */
/**
 * @struct CRC_Type
 * @brief  C Struct allowing access to CRC registers
 */
typedef struct CRC_Type {
   __IO uint32_t  DR;                           /**< 0000: Data register                                                */
   __IO uint32_t  IDR;                          /**< 0004: Independent data register                                    */
   __IO uint32_t  CR;                           /**< 0008: Control register                                             */
   __IO uint32_t  INIT;                         /**< 000C: Initial CRC value                                            */
} CRC_Type;


/** @brief Register Masks for CRC */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup CRC_Register_Masks_GROUP CRC Register Masks */
/** @{ */

/** @name DR - Data register */ /** @{ */
#define CRC_DR_DR_MASK                           (0xFFFFFFFFU)                                       /**< CRC_DR.DR Mask                          */
#define CRC_DR_DR_SHIFT                          (0U)                                                /**< CRC_DR.DR Position                      */
#define CRC_DR_DR(x)                             (((uint32_t)(((uint32_t)(x))<<CRC_DR_DR_SHIFT))&CRC_DR_DR_MASK) /**< CRC_DR.DR Field                         */
/** @} */

/** @name IDR - Independent data register */ /** @{ */
#define CRC_IDR_IDR_MASK                         (0xFFU)                                             /**< CRC_IDR.IDR Mask                        */
#define CRC_IDR_IDR_SHIFT                        (0U)                                                /**< CRC_IDR.IDR Position                    */
#define CRC_IDR_IDR(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_IDR_IDR_SHIFT))&CRC_IDR_IDR_MASK) /**< CRC_IDR.IDR Field                       */
/** @} */

/** @name CR - Control register */ /** @{ */
#define CRC_CR_RESET_MASK                        (0x1U)                                              /**< CRC_CR.RESET Mask                       */
#define CRC_CR_RESET_SHIFT                       (0U)                                                /**< CRC_CR.RESET Position                   */
#define CRC_CR_RESET(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CR_RESET_SHIFT))&CRC_CR_RESET_MASK) /**< CRC_CR.RESET Field                      */
#define CRC_CR_REV_IN_MASK                       (0x60U)                                             /**< CRC_CR.REV_IN Mask                      */
#define CRC_CR_REV_IN_SHIFT                      (5U)                                                /**< CRC_CR.REV_IN Position                  */
#define CRC_CR_REV_IN(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CR_REV_IN_SHIFT))&CRC_CR_REV_IN_MASK) /**< CRC_CR.REV_IN Field                     */
#define CRC_CR_REV_OUT_MASK                      (0x80U)                                             /**< CRC_CR.REV_OUT Mask                     */
#define CRC_CR_REV_OUT_SHIFT                     (7U)                                                /**< CRC_CR.REV_OUT Position                 */
#define CRC_CR_REV_OUT(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_CR_REV_OUT_SHIFT))&CRC_CR_REV_OUT_MASK) /**< CRC_CR.REV_OUT Field                    */
/** @} */

/** @name INIT - Initial CRC value */ /** @{ */
#define CRC_INIT_INIT_MASK                       (0xFFFFFFFFU)                                       /**< CRC_INIT.INIT Mask                      */
#define CRC_INIT_INIT_SHIFT                      (0U)                                                /**< CRC_INIT.INIT Position                  */
#define CRC_INIT_INIT(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_INIT_INIT_SHIFT))&CRC_INIT_INIT_MASK) /**< CRC_INIT.INIT Field                     */
/** @} */

/** @} */ /* End group CRC_Register_Masks_GROUP */


/* CRC - Peripheral instance base addresses */
#define CRC_BasePtr                    0x40023000UL //!< Peripheral base address
#define CRC                            ((CRC_Type *) CRC_BasePtr) //!< Freescale base pointer
#define CRC_BASE_PTR                   (CRC) //!< Freescale style base pointer

/** @} */ /* End group CRC_Peripheral_access_layer_GROUP */


/** @brief C Struct for DBGMCU */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup DBGMCU_Peripheral_access_layer_GROUP DBGMCU Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           DBGMCU (file:DBGMCU_STM32F030)       ================ */
/* ================================================================================ */

/**
 * @brief Debug support
 */
/**
 * @struct DBGMCU_Type
 * @brief  C Struct allowing access to DBGMCU registers
 */
typedef struct DBGMCU_Type {
   __I  uint32_t  IDCODE;                       /**< 0000: MCU Device ID Code Register                                  */
   __IO uint32_t  CR;                           /**< 0004: Debug MCU Configuration                                      */
   __IO uint32_t  APBLFZ;                       /**< 0008: APB Low Freeze Register                                      */
   __IO uint32_t  APBHFZ;                       /**< 000C: APB High Freeze Register                                     */
} DBGMCU_Type;


/** @brief Register Masks for DBGMCU */

/* -------------------------------------------------------------------------------- */
/* -----------     'DBGMCU' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup DBGMCU_Register_Masks_GROUP DBGMCU Register Masks */
/** @{ */

/** @name IDCODE - MCU Device ID Code Register */ /** @{ */
#define DBGMCU_IDCODE_DEV_ID_MASK                (0xFFFU)                                            /**< DBGMCU_IDCODE.DEV_ID Mask               */
#define DBGMCU_IDCODE_DEV_ID_SHIFT               (0U)                                                /**< DBGMCU_IDCODE.DEV_ID Position           */
#define DBGMCU_IDCODE_DEV_ID(x)                  (((uint32_t)(((uint32_t)(x))<<DBGMCU_IDCODE_DEV_ID_SHIFT))&DBGMCU_IDCODE_DEV_ID_MASK) /**< DBGMCU_IDCODE.DEV_ID Field              */
#define DBGMCU_IDCODE_DIV_ID_MASK                (0xF000U)                                           /**< DBGMCU_IDCODE.DIV_ID Mask               */
#define DBGMCU_IDCODE_DIV_ID_SHIFT               (12U)                                               /**< DBGMCU_IDCODE.DIV_ID Position           */
#define DBGMCU_IDCODE_DIV_ID(x)                  (((uint32_t)(((uint32_t)(x))<<DBGMCU_IDCODE_DIV_ID_SHIFT))&DBGMCU_IDCODE_DIV_ID_MASK) /**< DBGMCU_IDCODE.DIV_ID Field              */
#define DBGMCU_IDCODE_REV_ID_MASK                (0xFFFF0000U)                                       /**< DBGMCU_IDCODE.REV_ID Mask               */
#define DBGMCU_IDCODE_REV_ID_SHIFT               (16U)                                               /**< DBGMCU_IDCODE.REV_ID Position           */
#define DBGMCU_IDCODE_REV_ID(x)                  (((uint32_t)(((uint32_t)(x))<<DBGMCU_IDCODE_REV_ID_SHIFT))&DBGMCU_IDCODE_REV_ID_MASK) /**< DBGMCU_IDCODE.REV_ID Field              */
/** @} */

/** @name CR - Debug MCU Configuration */ /** @{ */
#define DBGMCU_CR_DBG_STOP_MASK                  (0x2U)                                              /**< DBGMCU_CR.DBG_STOP Mask                 */
#define DBGMCU_CR_DBG_STOP_SHIFT                 (1U)                                                /**< DBGMCU_CR.DBG_STOP Position             */
#define DBGMCU_CR_DBG_STOP(x)                    (((uint32_t)(((uint32_t)(x))<<DBGMCU_CR_DBG_STOP_SHIFT))&DBGMCU_CR_DBG_STOP_MASK) /**< DBGMCU_CR.DBG_STOP Field                */
#define DBGMCU_CR_DBG_STANDBY_MASK               (0x4U)                                              /**< DBGMCU_CR.DBG_STANDBY Mask              */
#define DBGMCU_CR_DBG_STANDBY_SHIFT              (2U)                                                /**< DBGMCU_CR.DBG_STANDBY Position          */
#define DBGMCU_CR_DBG_STANDBY(x)                 (((uint32_t)(((uint32_t)(x))<<DBGMCU_CR_DBG_STANDBY_SHIFT))&DBGMCU_CR_DBG_STANDBY_MASK) /**< DBGMCU_CR.DBG_STANDBY Field             */
/** @} */

/** @name APBLFZ - APB Low Freeze Register */ /** @{ */
#define DBGMCU_APBLFZ_DBG_TIMER2_STOP_MASK       (0x1U)                                              /**< DBGMCU_APBLFZ.DBG_TIMER2_STOP Mask      */
#define DBGMCU_APBLFZ_DBG_TIMER2_STOP_SHIFT      (0U)                                                /**< DBGMCU_APBLFZ.DBG_TIMER2_STOP Position  */
#define DBGMCU_APBLFZ_DBG_TIMER2_STOP(x)         (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBLFZ_DBG_TIMER2_STOP_SHIFT))&DBGMCU_APBLFZ_DBG_TIMER2_STOP_MASK) /**< DBGMCU_APBLFZ.DBG_TIMER2_STOP Field     */
#define DBGMCU_APBLFZ_DBG_TIMER3_STOP_MASK       (0x2U)                                              /**< DBGMCU_APBLFZ.DBG_TIMER3_STOP Mask      */
#define DBGMCU_APBLFZ_DBG_TIMER3_STOP_SHIFT      (1U)                                                /**< DBGMCU_APBLFZ.DBG_TIMER3_STOP Position  */
#define DBGMCU_APBLFZ_DBG_TIMER3_STOP(x)         (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBLFZ_DBG_TIMER3_STOP_SHIFT))&DBGMCU_APBLFZ_DBG_TIMER3_STOP_MASK) /**< DBGMCU_APBLFZ.DBG_TIMER3_STOP Field     */
#define DBGMCU_APBLFZ_DBG_TIMER6_STOP_MASK       (0x10U)                                             /**< DBGMCU_APBLFZ.DBG_TIMER6_STOP Mask      */
#define DBGMCU_APBLFZ_DBG_TIMER6_STOP_SHIFT      (4U)                                                /**< DBGMCU_APBLFZ.DBG_TIMER6_STOP Position  */
#define DBGMCU_APBLFZ_DBG_TIMER6_STOP(x)         (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBLFZ_DBG_TIMER6_STOP_SHIFT))&DBGMCU_APBLFZ_DBG_TIMER6_STOP_MASK) /**< DBGMCU_APBLFZ.DBG_TIMER6_STOP Field     */
#define DBGMCU_APBLFZ_DBG_TIMER14_STOP_MASK      (0x100U)                                            /**< DBGMCU_APBLFZ.DBG_TIMER14_STOP Mask     */
#define DBGMCU_APBLFZ_DBG_TIMER14_STOP_SHIFT     (8U)                                                /**< DBGMCU_APBLFZ.DBG_TIMER14_STOP Position */
#define DBGMCU_APBLFZ_DBG_TIMER14_STOP(x)        (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBLFZ_DBG_TIMER14_STOP_SHIFT))&DBGMCU_APBLFZ_DBG_TIMER14_STOP_MASK) /**< DBGMCU_APBLFZ.DBG_TIMER14_STOP Field    */
#define DBGMCU_APBLFZ_DBG_RTC_STOP_MASK          (0x400U)                                            /**< DBGMCU_APBLFZ.DBG_RTC_STOP Mask         */
#define DBGMCU_APBLFZ_DBG_RTC_STOP_SHIFT         (10U)                                               /**< DBGMCU_APBLFZ.DBG_RTC_STOP Position     */
#define DBGMCU_APBLFZ_DBG_RTC_STOP(x)            (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBLFZ_DBG_RTC_STOP_SHIFT))&DBGMCU_APBLFZ_DBG_RTC_STOP_MASK) /**< DBGMCU_APBLFZ.DBG_RTC_STOP Field        */
#define DBGMCU_APBLFZ_DBG_WWDG_STOP_MASK         (0x800U)                                            /**< DBGMCU_APBLFZ.DBG_WWDG_STOP Mask        */
#define DBGMCU_APBLFZ_DBG_WWDG_STOP_SHIFT        (11U)                                               /**< DBGMCU_APBLFZ.DBG_WWDG_STOP Position    */
#define DBGMCU_APBLFZ_DBG_WWDG_STOP(x)           (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBLFZ_DBG_WWDG_STOP_SHIFT))&DBGMCU_APBLFZ_DBG_WWDG_STOP_MASK) /**< DBGMCU_APBLFZ.DBG_WWDG_STOP Field       */
#define DBGMCU_APBLFZ_DBG_IWDG_STOP_MASK         (0x1000U)                                           /**< DBGMCU_APBLFZ.DBG_IWDG_STOP Mask        */
#define DBGMCU_APBLFZ_DBG_IWDG_STOP_SHIFT        (12U)                                               /**< DBGMCU_APBLFZ.DBG_IWDG_STOP Position    */
#define DBGMCU_APBLFZ_DBG_IWDG_STOP(x)           (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBLFZ_DBG_IWDG_STOP_SHIFT))&DBGMCU_APBLFZ_DBG_IWDG_STOP_MASK) /**< DBGMCU_APBLFZ.DBG_IWDG_STOP Field       */
#define DBGMCU_APBLFZ_I2C1_SMBUS_TIMEOUT_MASK    (0x200000U)                                         /**< DBGMCU_APBLFZ.I2C1_SMBUS_TIMEOUT Mask   */
#define DBGMCU_APBLFZ_I2C1_SMBUS_TIMEOUT_SHIFT   (21U)                                               /**< DBGMCU_APBLFZ.I2C1_SMBUS_TIMEOUT Position*/
#define DBGMCU_APBLFZ_I2C1_SMBUS_TIMEOUT(x)      (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBLFZ_I2C1_SMBUS_TIMEOUT_SHIFT))&DBGMCU_APBLFZ_I2C1_SMBUS_TIMEOUT_MASK) /**< DBGMCU_APBLFZ.I2C1_SMBUS_TIMEOUT Field  */
/** @} */

/** @name APBHFZ - APB High Freeze Register */ /** @{ */
#define DBGMCU_APBHFZ_DBG_TIMER1_STOP_MASK       (0x800U)                                            /**< DBGMCU_APBHFZ.DBG_TIMER1_STOP Mask      */
#define DBGMCU_APBHFZ_DBG_TIMER1_STOP_SHIFT      (11U)                                               /**< DBGMCU_APBHFZ.DBG_TIMER1_STOP Position  */
#define DBGMCU_APBHFZ_DBG_TIMER1_STOP(x)         (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBHFZ_DBG_TIMER1_STOP_SHIFT))&DBGMCU_APBHFZ_DBG_TIMER1_STOP_MASK) /**< DBGMCU_APBHFZ.DBG_TIMER1_STOP Field     */
#define DBGMCU_APBHFZ_DBG_TIMER15_STO_MASK       (0x10000U)                                          /**< DBGMCU_APBHFZ.DBG_TIMER15_STO Mask      */
#define DBGMCU_APBHFZ_DBG_TIMER15_STO_SHIFT      (16U)                                               /**< DBGMCU_APBHFZ.DBG_TIMER15_STO Position  */
#define DBGMCU_APBHFZ_DBG_TIMER15_STO(x)         (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBHFZ_DBG_TIMER15_STO_SHIFT))&DBGMCU_APBHFZ_DBG_TIMER15_STO_MASK) /**< DBGMCU_APBHFZ.DBG_TIMER15_STO Field     */
#define DBGMCU_APBHFZ_DBG_TIMER16_STO_MASK       (0x20000U)                                          /**< DBGMCU_APBHFZ.DBG_TIMER16_STO Mask      */
#define DBGMCU_APBHFZ_DBG_TIMER16_STO_SHIFT      (17U)                                               /**< DBGMCU_APBHFZ.DBG_TIMER16_STO Position  */
#define DBGMCU_APBHFZ_DBG_TIMER16_STO(x)         (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBHFZ_DBG_TIMER16_STO_SHIFT))&DBGMCU_APBHFZ_DBG_TIMER16_STO_MASK) /**< DBGMCU_APBHFZ.DBG_TIMER16_STO Field     */
#define DBGMCU_APBHFZ_DBG_TIMER17_STO_MASK       (0x40000U)                                          /**< DBGMCU_APBHFZ.DBG_TIMER17_STO Mask      */
#define DBGMCU_APBHFZ_DBG_TIMER17_STO_SHIFT      (18U)                                               /**< DBGMCU_APBHFZ.DBG_TIMER17_STO Position  */
#define DBGMCU_APBHFZ_DBG_TIMER17_STO(x)         (((uint32_t)(((uint32_t)(x))<<DBGMCU_APBHFZ_DBG_TIMER17_STO_SHIFT))&DBGMCU_APBHFZ_DBG_TIMER17_STO_MASK) /**< DBGMCU_APBHFZ.DBG_TIMER17_STO Field     */
/** @} */

/** @} */ /* End group DBGMCU_Register_Masks_GROUP */


/* DBGMCU - Peripheral instance base addresses */
#define DBGMCU_BasePtr                 0x40015800UL //!< Peripheral base address
#define DBGMCU                         ((DBGMCU_Type *) DBGMCU_BasePtr) //!< Freescale base pointer
#define DBGMCU_BASE_PTR                (DBGMCU) //!< Freescale style base pointer
#define DBGMCU_IRQS { ADC_COMP_IRQn,  }


/** @} */ /* End group DBGMCU_Peripheral_access_layer_GROUP */


/** @brief C Struct for DMA */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup DMA_Peripheral_access_layer_GROUP DMA Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           DMA (file:DMA_STM32F030)             ================ */
/* ================================================================================ */

/**
 * @brief DMA controller
 */
/**
 * @struct DMA_Type
 * @brief  C Struct allowing access to DMA registers
 */
typedef struct DMA_Type {
   __I  uint32_t  ISR;                          /**< 0000: DMA interrupt status register                                */
   __O  uint32_t  IFCR;                         /**< 0004: DMA interrupt flag clear register                            */
   __IO uint32_t  CCR1;                         /**< 0008: DMA channel configuration register                           */
   __IO uint32_t  CNDTR1;                       /**< 000C: DMA channel 1 number of data                                 */
   __IO uint32_t  CPAR1;                        /**< 0010: DMA channel 1 peripheral address                             */
   __IO uint32_t  CMAR1;                        /**< 0014: DMA channel 1 memory address                                 */
        uint8_t   RESERVED_0[4];                /**< 0018: 0x4 bytes                                                    */
   __IO uint32_t  CCR2;                         /**< 001C: DMA channel configuration register                           */
   __IO uint32_t  CNDTR2;                       /**< 0020: DMA channel 2 number of data                                 */
   __IO uint32_t  CPAR2;                        /**< 0024: DMA channel 2 peripheral address                             */
   __IO uint32_t  CMAR2;                        /**< 0028: DMA channel 2 memory address                                 */
        uint8_t   RESERVED_1[4];                /**< 002C: 0x4 bytes                                                    */
   __IO uint32_t  CCR3;                         /**< 0030: DMA channel configuration register                           */
   __IO uint32_t  CNDTR3;                       /**< 0034: DMA channel 3 number of data                                 */
   __IO uint32_t  CPAR3;                        /**< 0038: DMA channel 3 peripheral address                             */
   __IO uint32_t  CMAR3;                        /**< 003C: DMA channel 3 memory address                                 */
        uint8_t   RESERVED_2[4];                /**< 0040: 0x4 bytes                                                    */
   __IO uint32_t  CCR4;                         /**< 0044: DMA channel configuration register                           */
   __IO uint32_t  CNDTR4;                       /**< 0048: DMA channel 4 number of data                                 */
   __IO uint32_t  CPAR4;                        /**< 004C: DMA channel 4 peripheral address                             */
   __IO uint32_t  CMAR4;                        /**< 0050: DMA channel 4 memory address                                 */
        uint8_t   RESERVED_3[4];                /**< 0054: 0x4 bytes                                                    */
   __IO uint32_t  CCR5;                         /**< 0058: DMA channel configuration register                           */
   __IO uint32_t  CNDTR5;                       /**< 005C: DMA channel 5 number of data                                 */
   __IO uint32_t  CPAR5;                        /**< 0060: DMA channel 5 peripheral address                             */
   __IO uint32_t  CMAR5;                        /**< 0064: DMA channel 5 memory address                                 */
        uint8_t   RESERVED_4[4];                /**< 0068: 0x4 bytes                                                    */
   __IO uint32_t  CCR6;                         /**< 006C: DMA channel configuration register                           */
   __IO uint32_t  CNDTR6;                       /**< 0070: DMA channel 6 number of data                                 */
   __IO uint32_t  CPAR6;                        /**< 0074: DMA channel 6 peripheral address                             */
   __IO uint32_t  CMAR6;                        /**< 0078: DMA channel 6 memory address                                 */
        uint8_t   RESERVED_5[4];                /**< 007C: 0x4 bytes                                                    */
   __IO uint32_t  CCR7;                         /**< 0080: DMA channel configuration register                           */
   __IO uint32_t  CNDTR7;                       /**< 0084: DMA channel 7 number of data                                 */
   __IO uint32_t  CPAR7;                        /**< 0088: DMA channel 7 peripheral address                             */
   __IO uint32_t  CMAR7;                        /**< 008C: DMA channel 7 memory address                                 */
} DMA_Type;


/** @brief Register Masks for DMA */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup DMA_Register_Masks_GROUP DMA Register Masks */
/** @{ */

/** @name ISR - DMA interrupt status register */ /** @{ */
#define DMA_ISR_GIF1_MASK                        (0x1U)                                              /**< DMA_ISR.GIF1 Mask                       */
#define DMA_ISR_GIF1_SHIFT                       (0U)                                                /**< DMA_ISR.GIF1 Position                   */
#define DMA_ISR_GIF1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ISR_GIF1_SHIFT))&DMA_ISR_GIF1_MASK) /**< DMA_ISR.GIF1 Field                      */
#define DMA_ISR_TCIF1_MASK                       (0x2U)                                              /**< DMA_ISR.TCIF1 Mask                      */
#define DMA_ISR_TCIF1_SHIFT                      (1U)                                                /**< DMA_ISR.TCIF1 Position                  */
#define DMA_ISR_TCIF1(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TCIF1_SHIFT))&DMA_ISR_TCIF1_MASK) /**< DMA_ISR.TCIF1 Field                     */
#define DMA_ISR_HTIF1_MASK                       (0x4U)                                              /**< DMA_ISR.HTIF1 Mask                      */
#define DMA_ISR_HTIF1_SHIFT                      (2U)                                                /**< DMA_ISR.HTIF1 Position                  */
#define DMA_ISR_HTIF1(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_HTIF1_SHIFT))&DMA_ISR_HTIF1_MASK) /**< DMA_ISR.HTIF1 Field                     */
#define DMA_ISR_TEIF1_MASK                       (0x8U)                                              /**< DMA_ISR.TEIF1 Mask                      */
#define DMA_ISR_TEIF1_SHIFT                      (3U)                                                /**< DMA_ISR.TEIF1 Position                  */
#define DMA_ISR_TEIF1(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TEIF1_SHIFT))&DMA_ISR_TEIF1_MASK) /**< DMA_ISR.TEIF1 Field                     */
#define DMA_ISR_GIF2_MASK                        (0x10U)                                             /**< DMA_ISR.GIF2 Mask                       */
#define DMA_ISR_GIF2_SHIFT                       (4U)                                                /**< DMA_ISR.GIF2 Position                   */
#define DMA_ISR_GIF2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ISR_GIF2_SHIFT))&DMA_ISR_GIF2_MASK) /**< DMA_ISR.GIF2 Field                      */
#define DMA_ISR_TCIF2_MASK                       (0x20U)                                             /**< DMA_ISR.TCIF2 Mask                      */
#define DMA_ISR_TCIF2_SHIFT                      (5U)                                                /**< DMA_ISR.TCIF2 Position                  */
#define DMA_ISR_TCIF2(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TCIF2_SHIFT))&DMA_ISR_TCIF2_MASK) /**< DMA_ISR.TCIF2 Field                     */
#define DMA_ISR_HTIF2_MASK                       (0x40U)                                             /**< DMA_ISR.HTIF2 Mask                      */
#define DMA_ISR_HTIF2_SHIFT                      (6U)                                                /**< DMA_ISR.HTIF2 Position                  */
#define DMA_ISR_HTIF2(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_HTIF2_SHIFT))&DMA_ISR_HTIF2_MASK) /**< DMA_ISR.HTIF2 Field                     */
#define DMA_ISR_TEIF2_MASK                       (0x80U)                                             /**< DMA_ISR.TEIF2 Mask                      */
#define DMA_ISR_TEIF2_SHIFT                      (7U)                                                /**< DMA_ISR.TEIF2 Position                  */
#define DMA_ISR_TEIF2(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TEIF2_SHIFT))&DMA_ISR_TEIF2_MASK) /**< DMA_ISR.TEIF2 Field                     */
#define DMA_ISR_GIF3_MASK                        (0x100U)                                            /**< DMA_ISR.GIF3 Mask                       */
#define DMA_ISR_GIF3_SHIFT                       (8U)                                                /**< DMA_ISR.GIF3 Position                   */
#define DMA_ISR_GIF3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ISR_GIF3_SHIFT))&DMA_ISR_GIF3_MASK) /**< DMA_ISR.GIF3 Field                      */
#define DMA_ISR_TCIF3_MASK                       (0x200U)                                            /**< DMA_ISR.TCIF3 Mask                      */
#define DMA_ISR_TCIF3_SHIFT                      (9U)                                                /**< DMA_ISR.TCIF3 Position                  */
#define DMA_ISR_TCIF3(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TCIF3_SHIFT))&DMA_ISR_TCIF3_MASK) /**< DMA_ISR.TCIF3 Field                     */
#define DMA_ISR_HTIF3_MASK                       (0x400U)                                            /**< DMA_ISR.HTIF3 Mask                      */
#define DMA_ISR_HTIF3_SHIFT                      (10U)                                               /**< DMA_ISR.HTIF3 Position                  */
#define DMA_ISR_HTIF3(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_HTIF3_SHIFT))&DMA_ISR_HTIF3_MASK) /**< DMA_ISR.HTIF3 Field                     */
#define DMA_ISR_TEIF3_MASK                       (0x800U)                                            /**< DMA_ISR.TEIF3 Mask                      */
#define DMA_ISR_TEIF3_SHIFT                      (11U)                                               /**< DMA_ISR.TEIF3 Position                  */
#define DMA_ISR_TEIF3(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TEIF3_SHIFT))&DMA_ISR_TEIF3_MASK) /**< DMA_ISR.TEIF3 Field                     */
#define DMA_ISR_GIF4_MASK                        (0x1000U)                                           /**< DMA_ISR.GIF4 Mask                       */
#define DMA_ISR_GIF4_SHIFT                       (12U)                                               /**< DMA_ISR.GIF4 Position                   */
#define DMA_ISR_GIF4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ISR_GIF4_SHIFT))&DMA_ISR_GIF4_MASK) /**< DMA_ISR.GIF4 Field                      */
#define DMA_ISR_TCIF4_MASK                       (0x2000U)                                           /**< DMA_ISR.TCIF4 Mask                      */
#define DMA_ISR_TCIF4_SHIFT                      (13U)                                               /**< DMA_ISR.TCIF4 Position                  */
#define DMA_ISR_TCIF4(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TCIF4_SHIFT))&DMA_ISR_TCIF4_MASK) /**< DMA_ISR.TCIF4 Field                     */
#define DMA_ISR_HTIF4_MASK                       (0x4000U)                                           /**< DMA_ISR.HTIF4 Mask                      */
#define DMA_ISR_HTIF4_SHIFT                      (14U)                                               /**< DMA_ISR.HTIF4 Position                  */
#define DMA_ISR_HTIF4(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_HTIF4_SHIFT))&DMA_ISR_HTIF4_MASK) /**< DMA_ISR.HTIF4 Field                     */
#define DMA_ISR_TEIF4_MASK                       (0x8000U)                                           /**< DMA_ISR.TEIF4 Mask                      */
#define DMA_ISR_TEIF4_SHIFT                      (15U)                                               /**< DMA_ISR.TEIF4 Position                  */
#define DMA_ISR_TEIF4(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TEIF4_SHIFT))&DMA_ISR_TEIF4_MASK) /**< DMA_ISR.TEIF4 Field                     */
#define DMA_ISR_GIF5_MASK                        (0x10000U)                                          /**< DMA_ISR.GIF5 Mask                       */
#define DMA_ISR_GIF5_SHIFT                       (16U)                                               /**< DMA_ISR.GIF5 Position                   */
#define DMA_ISR_GIF5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ISR_GIF5_SHIFT))&DMA_ISR_GIF5_MASK) /**< DMA_ISR.GIF5 Field                      */
#define DMA_ISR_TCIF5_MASK                       (0x20000U)                                          /**< DMA_ISR.TCIF5 Mask                      */
#define DMA_ISR_TCIF5_SHIFT                      (17U)                                               /**< DMA_ISR.TCIF5 Position                  */
#define DMA_ISR_TCIF5(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TCIF5_SHIFT))&DMA_ISR_TCIF5_MASK) /**< DMA_ISR.TCIF5 Field                     */
#define DMA_ISR_HTIF5_MASK                       (0x40000U)                                          /**< DMA_ISR.HTIF5 Mask                      */
#define DMA_ISR_HTIF5_SHIFT                      (18U)                                               /**< DMA_ISR.HTIF5 Position                  */
#define DMA_ISR_HTIF5(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_HTIF5_SHIFT))&DMA_ISR_HTIF5_MASK) /**< DMA_ISR.HTIF5 Field                     */
#define DMA_ISR_TEIF5_MASK                       (0x80000U)                                          /**< DMA_ISR.TEIF5 Mask                      */
#define DMA_ISR_TEIF5_SHIFT                      (19U)                                               /**< DMA_ISR.TEIF5 Position                  */
#define DMA_ISR_TEIF5(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TEIF5_SHIFT))&DMA_ISR_TEIF5_MASK) /**< DMA_ISR.TEIF5 Field                     */
#define DMA_ISR_GIF6_MASK                        (0x100000U)                                         /**< DMA_ISR.GIF6 Mask                       */
#define DMA_ISR_GIF6_SHIFT                       (20U)                                               /**< DMA_ISR.GIF6 Position                   */
#define DMA_ISR_GIF6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ISR_GIF6_SHIFT))&DMA_ISR_GIF6_MASK) /**< DMA_ISR.GIF6 Field                      */
#define DMA_ISR_TCIF6_MASK                       (0x200000U)                                         /**< DMA_ISR.TCIF6 Mask                      */
#define DMA_ISR_TCIF6_SHIFT                      (21U)                                               /**< DMA_ISR.TCIF6 Position                  */
#define DMA_ISR_TCIF6(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TCIF6_SHIFT))&DMA_ISR_TCIF6_MASK) /**< DMA_ISR.TCIF6 Field                     */
#define DMA_ISR_HTIF6_MASK                       (0x400000U)                                         /**< DMA_ISR.HTIF6 Mask                      */
#define DMA_ISR_HTIF6_SHIFT                      (22U)                                               /**< DMA_ISR.HTIF6 Position                  */
#define DMA_ISR_HTIF6(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_HTIF6_SHIFT))&DMA_ISR_HTIF6_MASK) /**< DMA_ISR.HTIF6 Field                     */
#define DMA_ISR_TEIF6_MASK                       (0x800000U)                                         /**< DMA_ISR.TEIF6 Mask                      */
#define DMA_ISR_TEIF6_SHIFT                      (23U)                                               /**< DMA_ISR.TEIF6 Position                  */
#define DMA_ISR_TEIF6(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TEIF6_SHIFT))&DMA_ISR_TEIF6_MASK) /**< DMA_ISR.TEIF6 Field                     */
#define DMA_ISR_GIF7_MASK                        (0x1000000U)                                        /**< DMA_ISR.GIF7 Mask                       */
#define DMA_ISR_GIF7_SHIFT                       (24U)                                               /**< DMA_ISR.GIF7 Position                   */
#define DMA_ISR_GIF7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ISR_GIF7_SHIFT))&DMA_ISR_GIF7_MASK) /**< DMA_ISR.GIF7 Field                      */
#define DMA_ISR_TCIF7_MASK                       (0x2000000U)                                        /**< DMA_ISR.TCIF7 Mask                      */
#define DMA_ISR_TCIF7_SHIFT                      (25U)                                               /**< DMA_ISR.TCIF7 Position                  */
#define DMA_ISR_TCIF7(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TCIF7_SHIFT))&DMA_ISR_TCIF7_MASK) /**< DMA_ISR.TCIF7 Field                     */
#define DMA_ISR_HTIF7_MASK                       (0x4000000U)                                        /**< DMA_ISR.HTIF7 Mask                      */
#define DMA_ISR_HTIF7_SHIFT                      (26U)                                               /**< DMA_ISR.HTIF7 Position                  */
#define DMA_ISR_HTIF7(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_HTIF7_SHIFT))&DMA_ISR_HTIF7_MASK) /**< DMA_ISR.HTIF7 Field                     */
#define DMA_ISR_TEIF7_MASK                       (0x8000000U)                                        /**< DMA_ISR.TEIF7 Mask                      */
#define DMA_ISR_TEIF7_SHIFT                      (27U)                                               /**< DMA_ISR.TEIF7 Position                  */
#define DMA_ISR_TEIF7(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ISR_TEIF7_SHIFT))&DMA_ISR_TEIF7_MASK) /**< DMA_ISR.TEIF7 Field                     */
/** @} */

/** @name IFCR - DMA interrupt flag clear register */ /** @{ */
#define DMA_IFCR_CGIF1_MASK                      (0x1U)                                              /**< DMA_IFCR.CGIF1 Mask                     */
#define DMA_IFCR_CGIF1_SHIFT                     (0U)                                                /**< DMA_IFCR.CGIF1 Position                 */
#define DMA_IFCR_CGIF1(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CGIF1_SHIFT))&DMA_IFCR_CGIF1_MASK) /**< DMA_IFCR.CGIF1 Field                    */
#define DMA_IFCR_CTCIF1_MASK                     (0x2U)                                              /**< DMA_IFCR.CTCIF1 Mask                    */
#define DMA_IFCR_CTCIF1_SHIFT                    (1U)                                                /**< DMA_IFCR.CTCIF1 Position                */
#define DMA_IFCR_CTCIF1(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTCIF1_SHIFT))&DMA_IFCR_CTCIF1_MASK) /**< DMA_IFCR.CTCIF1 Field                   */
#define DMA_IFCR_CHTIF1_MASK                     (0x4U)                                              /**< DMA_IFCR.CHTIF1 Mask                    */
#define DMA_IFCR_CHTIF1_SHIFT                    (2U)                                                /**< DMA_IFCR.CHTIF1 Position                */
#define DMA_IFCR_CHTIF1(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CHTIF1_SHIFT))&DMA_IFCR_CHTIF1_MASK) /**< DMA_IFCR.CHTIF1 Field                   */
#define DMA_IFCR_CTEIF1_MASK                     (0x8U)                                              /**< DMA_IFCR.CTEIF1 Mask                    */
#define DMA_IFCR_CTEIF1_SHIFT                    (3U)                                                /**< DMA_IFCR.CTEIF1 Position                */
#define DMA_IFCR_CTEIF1(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTEIF1_SHIFT))&DMA_IFCR_CTEIF1_MASK) /**< DMA_IFCR.CTEIF1 Field                   */
#define DMA_IFCR_CGIF2_MASK                      (0x10U)                                             /**< DMA_IFCR.CGIF2 Mask                     */
#define DMA_IFCR_CGIF2_SHIFT                     (4U)                                                /**< DMA_IFCR.CGIF2 Position                 */
#define DMA_IFCR_CGIF2(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CGIF2_SHIFT))&DMA_IFCR_CGIF2_MASK) /**< DMA_IFCR.CGIF2 Field                    */
#define DMA_IFCR_CTCIF2_MASK                     (0x20U)                                             /**< DMA_IFCR.CTCIF2 Mask                    */
#define DMA_IFCR_CTCIF2_SHIFT                    (5U)                                                /**< DMA_IFCR.CTCIF2 Position                */
#define DMA_IFCR_CTCIF2(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTCIF2_SHIFT))&DMA_IFCR_CTCIF2_MASK) /**< DMA_IFCR.CTCIF2 Field                   */
#define DMA_IFCR_CHTIF2_MASK                     (0x40U)                                             /**< DMA_IFCR.CHTIF2 Mask                    */
#define DMA_IFCR_CHTIF2_SHIFT                    (6U)                                                /**< DMA_IFCR.CHTIF2 Position                */
#define DMA_IFCR_CHTIF2(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CHTIF2_SHIFT))&DMA_IFCR_CHTIF2_MASK) /**< DMA_IFCR.CHTIF2 Field                   */
#define DMA_IFCR_CTEIF2_MASK                     (0x80U)                                             /**< DMA_IFCR.CTEIF2 Mask                    */
#define DMA_IFCR_CTEIF2_SHIFT                    (7U)                                                /**< DMA_IFCR.CTEIF2 Position                */
#define DMA_IFCR_CTEIF2(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTEIF2_SHIFT))&DMA_IFCR_CTEIF2_MASK) /**< DMA_IFCR.CTEIF2 Field                   */
#define DMA_IFCR_CGIF3_MASK                      (0x100U)                                            /**< DMA_IFCR.CGIF3 Mask                     */
#define DMA_IFCR_CGIF3_SHIFT                     (8U)                                                /**< DMA_IFCR.CGIF3 Position                 */
#define DMA_IFCR_CGIF3(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CGIF3_SHIFT))&DMA_IFCR_CGIF3_MASK) /**< DMA_IFCR.CGIF3 Field                    */
#define DMA_IFCR_CTCIF3_MASK                     (0x200U)                                            /**< DMA_IFCR.CTCIF3 Mask                    */
#define DMA_IFCR_CTCIF3_SHIFT                    (9U)                                                /**< DMA_IFCR.CTCIF3 Position                */
#define DMA_IFCR_CTCIF3(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTCIF3_SHIFT))&DMA_IFCR_CTCIF3_MASK) /**< DMA_IFCR.CTCIF3 Field                   */
#define DMA_IFCR_CHTIF3_MASK                     (0x400U)                                            /**< DMA_IFCR.CHTIF3 Mask                    */
#define DMA_IFCR_CHTIF3_SHIFT                    (10U)                                               /**< DMA_IFCR.CHTIF3 Position                */
#define DMA_IFCR_CHTIF3(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CHTIF3_SHIFT))&DMA_IFCR_CHTIF3_MASK) /**< DMA_IFCR.CHTIF3 Field                   */
#define DMA_IFCR_CTEIF3_MASK                     (0x800U)                                            /**< DMA_IFCR.CTEIF3 Mask                    */
#define DMA_IFCR_CTEIF3_SHIFT                    (11U)                                               /**< DMA_IFCR.CTEIF3 Position                */
#define DMA_IFCR_CTEIF3(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTEIF3_SHIFT))&DMA_IFCR_CTEIF3_MASK) /**< DMA_IFCR.CTEIF3 Field                   */
#define DMA_IFCR_CGIF4_MASK                      (0x1000U)                                           /**< DMA_IFCR.CGIF4 Mask                     */
#define DMA_IFCR_CGIF4_SHIFT                     (12U)                                               /**< DMA_IFCR.CGIF4 Position                 */
#define DMA_IFCR_CGIF4(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CGIF4_SHIFT))&DMA_IFCR_CGIF4_MASK) /**< DMA_IFCR.CGIF4 Field                    */
#define DMA_IFCR_CTCIF4_MASK                     (0x2000U)                                           /**< DMA_IFCR.CTCIF4 Mask                    */
#define DMA_IFCR_CTCIF4_SHIFT                    (13U)                                               /**< DMA_IFCR.CTCIF4 Position                */
#define DMA_IFCR_CTCIF4(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTCIF4_SHIFT))&DMA_IFCR_CTCIF4_MASK) /**< DMA_IFCR.CTCIF4 Field                   */
#define DMA_IFCR_CHTIF4_MASK                     (0x4000U)                                           /**< DMA_IFCR.CHTIF4 Mask                    */
#define DMA_IFCR_CHTIF4_SHIFT                    (14U)                                               /**< DMA_IFCR.CHTIF4 Position                */
#define DMA_IFCR_CHTIF4(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CHTIF4_SHIFT))&DMA_IFCR_CHTIF4_MASK) /**< DMA_IFCR.CHTIF4 Field                   */
#define DMA_IFCR_CTEIF4_MASK                     (0x8000U)                                           /**< DMA_IFCR.CTEIF4 Mask                    */
#define DMA_IFCR_CTEIF4_SHIFT                    (15U)                                               /**< DMA_IFCR.CTEIF4 Position                */
#define DMA_IFCR_CTEIF4(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTEIF4_SHIFT))&DMA_IFCR_CTEIF4_MASK) /**< DMA_IFCR.CTEIF4 Field                   */
#define DMA_IFCR_CGIF5_MASK                      (0x10000U)                                          /**< DMA_IFCR.CGIF5 Mask                     */
#define DMA_IFCR_CGIF5_SHIFT                     (16U)                                               /**< DMA_IFCR.CGIF5 Position                 */
#define DMA_IFCR_CGIF5(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CGIF5_SHIFT))&DMA_IFCR_CGIF5_MASK) /**< DMA_IFCR.CGIF5 Field                    */
#define DMA_IFCR_CTCIF5_MASK                     (0x20000U)                                          /**< DMA_IFCR.CTCIF5 Mask                    */
#define DMA_IFCR_CTCIF5_SHIFT                    (17U)                                               /**< DMA_IFCR.CTCIF5 Position                */
#define DMA_IFCR_CTCIF5(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTCIF5_SHIFT))&DMA_IFCR_CTCIF5_MASK) /**< DMA_IFCR.CTCIF5 Field                   */
#define DMA_IFCR_CHTIF5_MASK                     (0x40000U)                                          /**< DMA_IFCR.CHTIF5 Mask                    */
#define DMA_IFCR_CHTIF5_SHIFT                    (18U)                                               /**< DMA_IFCR.CHTIF5 Position                */
#define DMA_IFCR_CHTIF5(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CHTIF5_SHIFT))&DMA_IFCR_CHTIF5_MASK) /**< DMA_IFCR.CHTIF5 Field                   */
#define DMA_IFCR_CTEIF5_MASK                     (0x80000U)                                          /**< DMA_IFCR.CTEIF5 Mask                    */
#define DMA_IFCR_CTEIF5_SHIFT                    (19U)                                               /**< DMA_IFCR.CTEIF5 Position                */
#define DMA_IFCR_CTEIF5(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTEIF5_SHIFT))&DMA_IFCR_CTEIF5_MASK) /**< DMA_IFCR.CTEIF5 Field                   */
#define DMA_IFCR_CGIF6_MASK                      (0x100000U)                                         /**< DMA_IFCR.CGIF6 Mask                     */
#define DMA_IFCR_CGIF6_SHIFT                     (20U)                                               /**< DMA_IFCR.CGIF6 Position                 */
#define DMA_IFCR_CGIF6(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CGIF6_SHIFT))&DMA_IFCR_CGIF6_MASK) /**< DMA_IFCR.CGIF6 Field                    */
#define DMA_IFCR_CTCIF6_MASK                     (0x200000U)                                         /**< DMA_IFCR.CTCIF6 Mask                    */
#define DMA_IFCR_CTCIF6_SHIFT                    (21U)                                               /**< DMA_IFCR.CTCIF6 Position                */
#define DMA_IFCR_CTCIF6(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTCIF6_SHIFT))&DMA_IFCR_CTCIF6_MASK) /**< DMA_IFCR.CTCIF6 Field                   */
#define DMA_IFCR_CHTIF6_MASK                     (0x400000U)                                         /**< DMA_IFCR.CHTIF6 Mask                    */
#define DMA_IFCR_CHTIF6_SHIFT                    (22U)                                               /**< DMA_IFCR.CHTIF6 Position                */
#define DMA_IFCR_CHTIF6(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CHTIF6_SHIFT))&DMA_IFCR_CHTIF6_MASK) /**< DMA_IFCR.CHTIF6 Field                   */
#define DMA_IFCR_CTEIF6_MASK                     (0x800000U)                                         /**< DMA_IFCR.CTEIF6 Mask                    */
#define DMA_IFCR_CTEIF6_SHIFT                    (23U)                                               /**< DMA_IFCR.CTEIF6 Position                */
#define DMA_IFCR_CTEIF6(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTEIF6_SHIFT))&DMA_IFCR_CTEIF6_MASK) /**< DMA_IFCR.CTEIF6 Field                   */
#define DMA_IFCR_CGIF7_MASK                      (0x1000000U)                                        /**< DMA_IFCR.CGIF7 Mask                     */
#define DMA_IFCR_CGIF7_SHIFT                     (24U)                                               /**< DMA_IFCR.CGIF7 Position                 */
#define DMA_IFCR_CGIF7(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CGIF7_SHIFT))&DMA_IFCR_CGIF7_MASK) /**< DMA_IFCR.CGIF7 Field                    */
#define DMA_IFCR_CTCIF7_MASK                     (0x2000000U)                                        /**< DMA_IFCR.CTCIF7 Mask                    */
#define DMA_IFCR_CTCIF7_SHIFT                    (25U)                                               /**< DMA_IFCR.CTCIF7 Position                */
#define DMA_IFCR_CTCIF7(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTCIF7_SHIFT))&DMA_IFCR_CTCIF7_MASK) /**< DMA_IFCR.CTCIF7 Field                   */
#define DMA_IFCR_CHTIF7_MASK                     (0x4000000U)                                        /**< DMA_IFCR.CHTIF7 Mask                    */
#define DMA_IFCR_CHTIF7_SHIFT                    (26U)                                               /**< DMA_IFCR.CHTIF7 Position                */
#define DMA_IFCR_CHTIF7(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CHTIF7_SHIFT))&DMA_IFCR_CHTIF7_MASK) /**< DMA_IFCR.CHTIF7 Field                   */
#define DMA_IFCR_CTEIF7_MASK                     (0x8000000U)                                        /**< DMA_IFCR.CTEIF7 Mask                    */
#define DMA_IFCR_CTEIF7_SHIFT                    (27U)                                               /**< DMA_IFCR.CTEIF7 Position                */
#define DMA_IFCR_CTEIF7(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_IFCR_CTEIF7_SHIFT))&DMA_IFCR_CTEIF7_MASK) /**< DMA_IFCR.CTEIF7 Field                   */
/** @} */

/** @name CCR1 - DMA channel configuration register */ /** @{ */
#define DMA_CCR1_EN_MASK                         (0x1U)                                              /**< DMA_CCR1.EN Mask                        */
#define DMA_CCR1_EN_SHIFT                        (0U)                                                /**< DMA_CCR1.EN Position                    */
#define DMA_CCR1_EN(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_EN_SHIFT))&DMA_CCR1_EN_MASK) /**< DMA_CCR1.EN Field                       */
#define DMA_CCR1_TCIE_MASK                       (0x2U)                                              /**< DMA_CCR1.TCIE Mask                      */
#define DMA_CCR1_TCIE_SHIFT                      (1U)                                                /**< DMA_CCR1.TCIE Position                  */
#define DMA_CCR1_TCIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_TCIE_SHIFT))&DMA_CCR1_TCIE_MASK) /**< DMA_CCR1.TCIE Field                     */
#define DMA_CCR1_HTIE_MASK                       (0x4U)                                              /**< DMA_CCR1.HTIE Mask                      */
#define DMA_CCR1_HTIE_SHIFT                      (2U)                                                /**< DMA_CCR1.HTIE Position                  */
#define DMA_CCR1_HTIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_HTIE_SHIFT))&DMA_CCR1_HTIE_MASK) /**< DMA_CCR1.HTIE Field                     */
#define DMA_CCR1_TEIE_MASK                       (0x8U)                                              /**< DMA_CCR1.TEIE Mask                      */
#define DMA_CCR1_TEIE_SHIFT                      (3U)                                                /**< DMA_CCR1.TEIE Position                  */
#define DMA_CCR1_TEIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_TEIE_SHIFT))&DMA_CCR1_TEIE_MASK) /**< DMA_CCR1.TEIE Field                     */
#define DMA_CCR1_DIR_MASK                        (0x10U)                                             /**< DMA_CCR1.DIR Mask                       */
#define DMA_CCR1_DIR_SHIFT                       (4U)                                                /**< DMA_CCR1.DIR Position                   */
#define DMA_CCR1_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_DIR_SHIFT))&DMA_CCR1_DIR_MASK) /**< DMA_CCR1.DIR Field                      */
#define DMA_CCR1_CIRC_MASK                       (0x20U)                                             /**< DMA_CCR1.CIRC Mask                      */
#define DMA_CCR1_CIRC_SHIFT                      (5U)                                                /**< DMA_CCR1.CIRC Position                  */
#define DMA_CCR1_CIRC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_CIRC_SHIFT))&DMA_CCR1_CIRC_MASK) /**< DMA_CCR1.CIRC Field                     */
#define DMA_CCR1_PINC_MASK                       (0x40U)                                             /**< DMA_CCR1.PINC Mask                      */
#define DMA_CCR1_PINC_SHIFT                      (6U)                                                /**< DMA_CCR1.PINC Position                  */
#define DMA_CCR1_PINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_PINC_SHIFT))&DMA_CCR1_PINC_MASK) /**< DMA_CCR1.PINC Field                     */
#define DMA_CCR1_MINC_MASK                       (0x80U)                                             /**< DMA_CCR1.MINC Mask                      */
#define DMA_CCR1_MINC_SHIFT                      (7U)                                                /**< DMA_CCR1.MINC Position                  */
#define DMA_CCR1_MINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_MINC_SHIFT))&DMA_CCR1_MINC_MASK) /**< DMA_CCR1.MINC Field                     */
#define DMA_CCR1_PSIZE_MASK                      (0x300U)                                            /**< DMA_CCR1.PSIZE Mask                     */
#define DMA_CCR1_PSIZE_SHIFT                     (8U)                                                /**< DMA_CCR1.PSIZE Position                 */
#define DMA_CCR1_PSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_PSIZE_SHIFT))&DMA_CCR1_PSIZE_MASK) /**< DMA_CCR1.PSIZE Field                    */
#define DMA_CCR1_MSIZE_MASK                      (0xC00U)                                            /**< DMA_CCR1.MSIZE Mask                     */
#define DMA_CCR1_MSIZE_SHIFT                     (10U)                                               /**< DMA_CCR1.MSIZE Position                 */
#define DMA_CCR1_MSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_MSIZE_SHIFT))&DMA_CCR1_MSIZE_MASK) /**< DMA_CCR1.MSIZE Field                    */
#define DMA_CCR1_PL_MASK                         (0x3000U)                                           /**< DMA_CCR1.PL Mask                        */
#define DMA_CCR1_PL_SHIFT                        (12U)                                               /**< DMA_CCR1.PL Position                    */
#define DMA_CCR1_PL(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_PL_SHIFT))&DMA_CCR1_PL_MASK) /**< DMA_CCR1.PL Field                       */
#define DMA_CCR1_MEM2MEM_MASK                    (0x4000U)                                           /**< DMA_CCR1.MEM2MEM Mask                   */
#define DMA_CCR1_MEM2MEM_SHIFT                   (14U)                                               /**< DMA_CCR1.MEM2MEM Position               */
#define DMA_CCR1_MEM2MEM(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_CCR1_MEM2MEM_SHIFT))&DMA_CCR1_MEM2MEM_MASK) /**< DMA_CCR1.MEM2MEM Field                  */
/** @} */

/** @name CNDTR1 - DMA channel 1 number of data */ /** @{ */
#define DMA_CNDTR1_NDT_MASK                      (0xFFFFU)                                           /**< DMA_CNDTR1.NDT Mask                     */
#define DMA_CNDTR1_NDT_SHIFT                     (0U)                                                /**< DMA_CNDTR1.NDT Position                 */
#define DMA_CNDTR1_NDT(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CNDTR1_NDT_SHIFT))&DMA_CNDTR1_NDT_MASK) /**< DMA_CNDTR1.NDT Field                    */
/** @} */

/** @name CPAR1 - DMA channel 1 peripheral address */ /** @{ */
#define DMA_CPAR1_PA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CPAR1.PA Mask                       */
#define DMA_CPAR1_PA_SHIFT                       (0U)                                                /**< DMA_CPAR1.PA Position                   */
#define DMA_CPAR1_PA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CPAR1_PA_SHIFT))&DMA_CPAR1_PA_MASK) /**< DMA_CPAR1.PA Field                      */
/** @} */

/** @name CMAR1 - DMA channel 1 memory address */ /** @{ */
#define DMA_CMAR1_MA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CMAR1.MA Mask                       */
#define DMA_CMAR1_MA_SHIFT                       (0U)                                                /**< DMA_CMAR1.MA Position                   */
#define DMA_CMAR1_MA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CMAR1_MA_SHIFT))&DMA_CMAR1_MA_MASK) /**< DMA_CMAR1.MA Field                      */
/** @} */

/** @name CCR2 - DMA channel configuration register */ /** @{ */
#define DMA_CCR2_EN_MASK                         (0x1U)                                              /**< DMA_CCR2.EN Mask                        */
#define DMA_CCR2_EN_SHIFT                        (0U)                                                /**< DMA_CCR2.EN Position                    */
#define DMA_CCR2_EN(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_EN_SHIFT))&DMA_CCR2_EN_MASK) /**< DMA_CCR2.EN Field                       */
#define DMA_CCR2_TCIE_MASK                       (0x2U)                                              /**< DMA_CCR2.TCIE Mask                      */
#define DMA_CCR2_TCIE_SHIFT                      (1U)                                                /**< DMA_CCR2.TCIE Position                  */
#define DMA_CCR2_TCIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_TCIE_SHIFT))&DMA_CCR2_TCIE_MASK) /**< DMA_CCR2.TCIE Field                     */
#define DMA_CCR2_HTIE_MASK                       (0x4U)                                              /**< DMA_CCR2.HTIE Mask                      */
#define DMA_CCR2_HTIE_SHIFT                      (2U)                                                /**< DMA_CCR2.HTIE Position                  */
#define DMA_CCR2_HTIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_HTIE_SHIFT))&DMA_CCR2_HTIE_MASK) /**< DMA_CCR2.HTIE Field                     */
#define DMA_CCR2_TEIE_MASK                       (0x8U)                                              /**< DMA_CCR2.TEIE Mask                      */
#define DMA_CCR2_TEIE_SHIFT                      (3U)                                                /**< DMA_CCR2.TEIE Position                  */
#define DMA_CCR2_TEIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_TEIE_SHIFT))&DMA_CCR2_TEIE_MASK) /**< DMA_CCR2.TEIE Field                     */
#define DMA_CCR2_DIR_MASK                        (0x10U)                                             /**< DMA_CCR2.DIR Mask                       */
#define DMA_CCR2_DIR_SHIFT                       (4U)                                                /**< DMA_CCR2.DIR Position                   */
#define DMA_CCR2_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_DIR_SHIFT))&DMA_CCR2_DIR_MASK) /**< DMA_CCR2.DIR Field                      */
#define DMA_CCR2_CIRC_MASK                       (0x20U)                                             /**< DMA_CCR2.CIRC Mask                      */
#define DMA_CCR2_CIRC_SHIFT                      (5U)                                                /**< DMA_CCR2.CIRC Position                  */
#define DMA_CCR2_CIRC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_CIRC_SHIFT))&DMA_CCR2_CIRC_MASK) /**< DMA_CCR2.CIRC Field                     */
#define DMA_CCR2_PINC_MASK                       (0x40U)                                             /**< DMA_CCR2.PINC Mask                      */
#define DMA_CCR2_PINC_SHIFT                      (6U)                                                /**< DMA_CCR2.PINC Position                  */
#define DMA_CCR2_PINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_PINC_SHIFT))&DMA_CCR2_PINC_MASK) /**< DMA_CCR2.PINC Field                     */
#define DMA_CCR2_MINC_MASK                       (0x80U)                                             /**< DMA_CCR2.MINC Mask                      */
#define DMA_CCR2_MINC_SHIFT                      (7U)                                                /**< DMA_CCR2.MINC Position                  */
#define DMA_CCR2_MINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_MINC_SHIFT))&DMA_CCR2_MINC_MASK) /**< DMA_CCR2.MINC Field                     */
#define DMA_CCR2_PSIZE_MASK                      (0x300U)                                            /**< DMA_CCR2.PSIZE Mask                     */
#define DMA_CCR2_PSIZE_SHIFT                     (8U)                                                /**< DMA_CCR2.PSIZE Position                 */
#define DMA_CCR2_PSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_PSIZE_SHIFT))&DMA_CCR2_PSIZE_MASK) /**< DMA_CCR2.PSIZE Field                    */
#define DMA_CCR2_MSIZE_MASK                      (0xC00U)                                            /**< DMA_CCR2.MSIZE Mask                     */
#define DMA_CCR2_MSIZE_SHIFT                     (10U)                                               /**< DMA_CCR2.MSIZE Position                 */
#define DMA_CCR2_MSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_MSIZE_SHIFT))&DMA_CCR2_MSIZE_MASK) /**< DMA_CCR2.MSIZE Field                    */
#define DMA_CCR2_PL_MASK                         (0x3000U)                                           /**< DMA_CCR2.PL Mask                        */
#define DMA_CCR2_PL_SHIFT                        (12U)                                               /**< DMA_CCR2.PL Position                    */
#define DMA_CCR2_PL(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_PL_SHIFT))&DMA_CCR2_PL_MASK) /**< DMA_CCR2.PL Field                       */
#define DMA_CCR2_MEM2MEM_MASK                    (0x4000U)                                           /**< DMA_CCR2.MEM2MEM Mask                   */
#define DMA_CCR2_MEM2MEM_SHIFT                   (14U)                                               /**< DMA_CCR2.MEM2MEM Position               */
#define DMA_CCR2_MEM2MEM(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_CCR2_MEM2MEM_SHIFT))&DMA_CCR2_MEM2MEM_MASK) /**< DMA_CCR2.MEM2MEM Field                  */
/** @} */

/** @name CNDTR2 - DMA channel 2 number of data */ /** @{ */
#define DMA_CNDTR2_NDT_MASK                      (0xFFFFU)                                           /**< DMA_CNDTR2.NDT Mask                     */
#define DMA_CNDTR2_NDT_SHIFT                     (0U)                                                /**< DMA_CNDTR2.NDT Position                 */
#define DMA_CNDTR2_NDT(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CNDTR2_NDT_SHIFT))&DMA_CNDTR2_NDT_MASK) /**< DMA_CNDTR2.NDT Field                    */
/** @} */

/** @name CPAR2 - DMA channel 2 peripheral address */ /** @{ */
#define DMA_CPAR2_PA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CPAR2.PA Mask                       */
#define DMA_CPAR2_PA_SHIFT                       (0U)                                                /**< DMA_CPAR2.PA Position                   */
#define DMA_CPAR2_PA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CPAR2_PA_SHIFT))&DMA_CPAR2_PA_MASK) /**< DMA_CPAR2.PA Field                      */
/** @} */

/** @name CMAR2 - DMA channel 2 memory address */ /** @{ */
#define DMA_CMAR2_MA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CMAR2.MA Mask                       */
#define DMA_CMAR2_MA_SHIFT                       (0U)                                                /**< DMA_CMAR2.MA Position                   */
#define DMA_CMAR2_MA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CMAR2_MA_SHIFT))&DMA_CMAR2_MA_MASK) /**< DMA_CMAR2.MA Field                      */
/** @} */

/** @name CCR3 - DMA channel configuration register */ /** @{ */
#define DMA_CCR3_EN_MASK                         (0x1U)                                              /**< DMA_CCR3.EN Mask                        */
#define DMA_CCR3_EN_SHIFT                        (0U)                                                /**< DMA_CCR3.EN Position                    */
#define DMA_CCR3_EN(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_EN_SHIFT))&DMA_CCR3_EN_MASK) /**< DMA_CCR3.EN Field                       */
#define DMA_CCR3_TCIE_MASK                       (0x2U)                                              /**< DMA_CCR3.TCIE Mask                      */
#define DMA_CCR3_TCIE_SHIFT                      (1U)                                                /**< DMA_CCR3.TCIE Position                  */
#define DMA_CCR3_TCIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_TCIE_SHIFT))&DMA_CCR3_TCIE_MASK) /**< DMA_CCR3.TCIE Field                     */
#define DMA_CCR3_HTIE_MASK                       (0x4U)                                              /**< DMA_CCR3.HTIE Mask                      */
#define DMA_CCR3_HTIE_SHIFT                      (2U)                                                /**< DMA_CCR3.HTIE Position                  */
#define DMA_CCR3_HTIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_HTIE_SHIFT))&DMA_CCR3_HTIE_MASK) /**< DMA_CCR3.HTIE Field                     */
#define DMA_CCR3_TEIE_MASK                       (0x8U)                                              /**< DMA_CCR3.TEIE Mask                      */
#define DMA_CCR3_TEIE_SHIFT                      (3U)                                                /**< DMA_CCR3.TEIE Position                  */
#define DMA_CCR3_TEIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_TEIE_SHIFT))&DMA_CCR3_TEIE_MASK) /**< DMA_CCR3.TEIE Field                     */
#define DMA_CCR3_DIR_MASK                        (0x10U)                                             /**< DMA_CCR3.DIR Mask                       */
#define DMA_CCR3_DIR_SHIFT                       (4U)                                                /**< DMA_CCR3.DIR Position                   */
#define DMA_CCR3_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_DIR_SHIFT))&DMA_CCR3_DIR_MASK) /**< DMA_CCR3.DIR Field                      */
#define DMA_CCR3_CIRC_MASK                       (0x20U)                                             /**< DMA_CCR3.CIRC Mask                      */
#define DMA_CCR3_CIRC_SHIFT                      (5U)                                                /**< DMA_CCR3.CIRC Position                  */
#define DMA_CCR3_CIRC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_CIRC_SHIFT))&DMA_CCR3_CIRC_MASK) /**< DMA_CCR3.CIRC Field                     */
#define DMA_CCR3_PINC_MASK                       (0x40U)                                             /**< DMA_CCR3.PINC Mask                      */
#define DMA_CCR3_PINC_SHIFT                      (6U)                                                /**< DMA_CCR3.PINC Position                  */
#define DMA_CCR3_PINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_PINC_SHIFT))&DMA_CCR3_PINC_MASK) /**< DMA_CCR3.PINC Field                     */
#define DMA_CCR3_MINC_MASK                       (0x80U)                                             /**< DMA_CCR3.MINC Mask                      */
#define DMA_CCR3_MINC_SHIFT                      (7U)                                                /**< DMA_CCR3.MINC Position                  */
#define DMA_CCR3_MINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_MINC_SHIFT))&DMA_CCR3_MINC_MASK) /**< DMA_CCR3.MINC Field                     */
#define DMA_CCR3_PSIZE_MASK                      (0x300U)                                            /**< DMA_CCR3.PSIZE Mask                     */
#define DMA_CCR3_PSIZE_SHIFT                     (8U)                                                /**< DMA_CCR3.PSIZE Position                 */
#define DMA_CCR3_PSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_PSIZE_SHIFT))&DMA_CCR3_PSIZE_MASK) /**< DMA_CCR3.PSIZE Field                    */
#define DMA_CCR3_MSIZE_MASK                      (0xC00U)                                            /**< DMA_CCR3.MSIZE Mask                     */
#define DMA_CCR3_MSIZE_SHIFT                     (10U)                                               /**< DMA_CCR3.MSIZE Position                 */
#define DMA_CCR3_MSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_MSIZE_SHIFT))&DMA_CCR3_MSIZE_MASK) /**< DMA_CCR3.MSIZE Field                    */
#define DMA_CCR3_PL_MASK                         (0x3000U)                                           /**< DMA_CCR3.PL Mask                        */
#define DMA_CCR3_PL_SHIFT                        (12U)                                               /**< DMA_CCR3.PL Position                    */
#define DMA_CCR3_PL(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_PL_SHIFT))&DMA_CCR3_PL_MASK) /**< DMA_CCR3.PL Field                       */
#define DMA_CCR3_MEM2MEM_MASK                    (0x4000U)                                           /**< DMA_CCR3.MEM2MEM Mask                   */
#define DMA_CCR3_MEM2MEM_SHIFT                   (14U)                                               /**< DMA_CCR3.MEM2MEM Position               */
#define DMA_CCR3_MEM2MEM(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_CCR3_MEM2MEM_SHIFT))&DMA_CCR3_MEM2MEM_MASK) /**< DMA_CCR3.MEM2MEM Field                  */
/** @} */

/** @name CNDTR3 - DMA channel 3 number of data */ /** @{ */
#define DMA_CNDTR3_NDT_MASK                      (0xFFFFU)                                           /**< DMA_CNDTR3.NDT Mask                     */
#define DMA_CNDTR3_NDT_SHIFT                     (0U)                                                /**< DMA_CNDTR3.NDT Position                 */
#define DMA_CNDTR3_NDT(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CNDTR3_NDT_SHIFT))&DMA_CNDTR3_NDT_MASK) /**< DMA_CNDTR3.NDT Field                    */
/** @} */

/** @name CPAR3 - DMA channel 3 peripheral address */ /** @{ */
#define DMA_CPAR3_PA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CPAR3.PA Mask                       */
#define DMA_CPAR3_PA_SHIFT                       (0U)                                                /**< DMA_CPAR3.PA Position                   */
#define DMA_CPAR3_PA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CPAR3_PA_SHIFT))&DMA_CPAR3_PA_MASK) /**< DMA_CPAR3.PA Field                      */
/** @} */

/** @name CMAR3 - DMA channel 3 memory address */ /** @{ */
#define DMA_CMAR3_MA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CMAR3.MA Mask                       */
#define DMA_CMAR3_MA_SHIFT                       (0U)                                                /**< DMA_CMAR3.MA Position                   */
#define DMA_CMAR3_MA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CMAR3_MA_SHIFT))&DMA_CMAR3_MA_MASK) /**< DMA_CMAR3.MA Field                      */
/** @} */

/** @name CCR4 - DMA channel configuration register */ /** @{ */
#define DMA_CCR4_EN_MASK                         (0x1U)                                              /**< DMA_CCR4.EN Mask                        */
#define DMA_CCR4_EN_SHIFT                        (0U)                                                /**< DMA_CCR4.EN Position                    */
#define DMA_CCR4_EN(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_EN_SHIFT))&DMA_CCR4_EN_MASK) /**< DMA_CCR4.EN Field                       */
#define DMA_CCR4_TCIE_MASK                       (0x2U)                                              /**< DMA_CCR4.TCIE Mask                      */
#define DMA_CCR4_TCIE_SHIFT                      (1U)                                                /**< DMA_CCR4.TCIE Position                  */
#define DMA_CCR4_TCIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_TCIE_SHIFT))&DMA_CCR4_TCIE_MASK) /**< DMA_CCR4.TCIE Field                     */
#define DMA_CCR4_HTIE_MASK                       (0x4U)                                              /**< DMA_CCR4.HTIE Mask                      */
#define DMA_CCR4_HTIE_SHIFT                      (2U)                                                /**< DMA_CCR4.HTIE Position                  */
#define DMA_CCR4_HTIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_HTIE_SHIFT))&DMA_CCR4_HTIE_MASK) /**< DMA_CCR4.HTIE Field                     */
#define DMA_CCR4_TEIE_MASK                       (0x8U)                                              /**< DMA_CCR4.TEIE Mask                      */
#define DMA_CCR4_TEIE_SHIFT                      (3U)                                                /**< DMA_CCR4.TEIE Position                  */
#define DMA_CCR4_TEIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_TEIE_SHIFT))&DMA_CCR4_TEIE_MASK) /**< DMA_CCR4.TEIE Field                     */
#define DMA_CCR4_DIR_MASK                        (0x10U)                                             /**< DMA_CCR4.DIR Mask                       */
#define DMA_CCR4_DIR_SHIFT                       (4U)                                                /**< DMA_CCR4.DIR Position                   */
#define DMA_CCR4_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_DIR_SHIFT))&DMA_CCR4_DIR_MASK) /**< DMA_CCR4.DIR Field                      */
#define DMA_CCR4_CIRC_MASK                       (0x20U)                                             /**< DMA_CCR4.CIRC Mask                      */
#define DMA_CCR4_CIRC_SHIFT                      (5U)                                                /**< DMA_CCR4.CIRC Position                  */
#define DMA_CCR4_CIRC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_CIRC_SHIFT))&DMA_CCR4_CIRC_MASK) /**< DMA_CCR4.CIRC Field                     */
#define DMA_CCR4_PINC_MASK                       (0x40U)                                             /**< DMA_CCR4.PINC Mask                      */
#define DMA_CCR4_PINC_SHIFT                      (6U)                                                /**< DMA_CCR4.PINC Position                  */
#define DMA_CCR4_PINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_PINC_SHIFT))&DMA_CCR4_PINC_MASK) /**< DMA_CCR4.PINC Field                     */
#define DMA_CCR4_MINC_MASK                       (0x80U)                                             /**< DMA_CCR4.MINC Mask                      */
#define DMA_CCR4_MINC_SHIFT                      (7U)                                                /**< DMA_CCR4.MINC Position                  */
#define DMA_CCR4_MINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_MINC_SHIFT))&DMA_CCR4_MINC_MASK) /**< DMA_CCR4.MINC Field                     */
#define DMA_CCR4_PSIZE_MASK                      (0x300U)                                            /**< DMA_CCR4.PSIZE Mask                     */
#define DMA_CCR4_PSIZE_SHIFT                     (8U)                                                /**< DMA_CCR4.PSIZE Position                 */
#define DMA_CCR4_PSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_PSIZE_SHIFT))&DMA_CCR4_PSIZE_MASK) /**< DMA_CCR4.PSIZE Field                    */
#define DMA_CCR4_MSIZE_MASK                      (0xC00U)                                            /**< DMA_CCR4.MSIZE Mask                     */
#define DMA_CCR4_MSIZE_SHIFT                     (10U)                                               /**< DMA_CCR4.MSIZE Position                 */
#define DMA_CCR4_MSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_MSIZE_SHIFT))&DMA_CCR4_MSIZE_MASK) /**< DMA_CCR4.MSIZE Field                    */
#define DMA_CCR4_PL_MASK                         (0x3000U)                                           /**< DMA_CCR4.PL Mask                        */
#define DMA_CCR4_PL_SHIFT                        (12U)                                               /**< DMA_CCR4.PL Position                    */
#define DMA_CCR4_PL(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_PL_SHIFT))&DMA_CCR4_PL_MASK) /**< DMA_CCR4.PL Field                       */
#define DMA_CCR4_MEM2MEM_MASK                    (0x4000U)                                           /**< DMA_CCR4.MEM2MEM Mask                   */
#define DMA_CCR4_MEM2MEM_SHIFT                   (14U)                                               /**< DMA_CCR4.MEM2MEM Position               */
#define DMA_CCR4_MEM2MEM(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_CCR4_MEM2MEM_SHIFT))&DMA_CCR4_MEM2MEM_MASK) /**< DMA_CCR4.MEM2MEM Field                  */
/** @} */

/** @name CNDTR4 - DMA channel 4 number of data */ /** @{ */
#define DMA_CNDTR4_NDT_MASK                      (0xFFFFU)                                           /**< DMA_CNDTR4.NDT Mask                     */
#define DMA_CNDTR4_NDT_SHIFT                     (0U)                                                /**< DMA_CNDTR4.NDT Position                 */
#define DMA_CNDTR4_NDT(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CNDTR4_NDT_SHIFT))&DMA_CNDTR4_NDT_MASK) /**< DMA_CNDTR4.NDT Field                    */
/** @} */

/** @name CPAR4 - DMA channel 4 peripheral address */ /** @{ */
#define DMA_CPAR4_PA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CPAR4.PA Mask                       */
#define DMA_CPAR4_PA_SHIFT                       (0U)                                                /**< DMA_CPAR4.PA Position                   */
#define DMA_CPAR4_PA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CPAR4_PA_SHIFT))&DMA_CPAR4_PA_MASK) /**< DMA_CPAR4.PA Field                      */
/** @} */

/** @name CMAR4 - DMA channel 4 memory address */ /** @{ */
#define DMA_CMAR4_MA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CMAR4.MA Mask                       */
#define DMA_CMAR4_MA_SHIFT                       (0U)                                                /**< DMA_CMAR4.MA Position                   */
#define DMA_CMAR4_MA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CMAR4_MA_SHIFT))&DMA_CMAR4_MA_MASK) /**< DMA_CMAR4.MA Field                      */
/** @} */

/** @name CCR5 - DMA channel configuration register */ /** @{ */
#define DMA_CCR5_EN_MASK                         (0x1U)                                              /**< DMA_CCR5.EN Mask                        */
#define DMA_CCR5_EN_SHIFT                        (0U)                                                /**< DMA_CCR5.EN Position                    */
#define DMA_CCR5_EN(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_EN_SHIFT))&DMA_CCR5_EN_MASK) /**< DMA_CCR5.EN Field                       */
#define DMA_CCR5_TCIE_MASK                       (0x2U)                                              /**< DMA_CCR5.TCIE Mask                      */
#define DMA_CCR5_TCIE_SHIFT                      (1U)                                                /**< DMA_CCR5.TCIE Position                  */
#define DMA_CCR5_TCIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_TCIE_SHIFT))&DMA_CCR5_TCIE_MASK) /**< DMA_CCR5.TCIE Field                     */
#define DMA_CCR5_HTIE_MASK                       (0x4U)                                              /**< DMA_CCR5.HTIE Mask                      */
#define DMA_CCR5_HTIE_SHIFT                      (2U)                                                /**< DMA_CCR5.HTIE Position                  */
#define DMA_CCR5_HTIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_HTIE_SHIFT))&DMA_CCR5_HTIE_MASK) /**< DMA_CCR5.HTIE Field                     */
#define DMA_CCR5_TEIE_MASK                       (0x8U)                                              /**< DMA_CCR5.TEIE Mask                      */
#define DMA_CCR5_TEIE_SHIFT                      (3U)                                                /**< DMA_CCR5.TEIE Position                  */
#define DMA_CCR5_TEIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_TEIE_SHIFT))&DMA_CCR5_TEIE_MASK) /**< DMA_CCR5.TEIE Field                     */
#define DMA_CCR5_DIR_MASK                        (0x10U)                                             /**< DMA_CCR5.DIR Mask                       */
#define DMA_CCR5_DIR_SHIFT                       (4U)                                                /**< DMA_CCR5.DIR Position                   */
#define DMA_CCR5_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_DIR_SHIFT))&DMA_CCR5_DIR_MASK) /**< DMA_CCR5.DIR Field                      */
#define DMA_CCR5_CIRC_MASK                       (0x20U)                                             /**< DMA_CCR5.CIRC Mask                      */
#define DMA_CCR5_CIRC_SHIFT                      (5U)                                                /**< DMA_CCR5.CIRC Position                  */
#define DMA_CCR5_CIRC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_CIRC_SHIFT))&DMA_CCR5_CIRC_MASK) /**< DMA_CCR5.CIRC Field                     */
#define DMA_CCR5_PINC_MASK                       (0x40U)                                             /**< DMA_CCR5.PINC Mask                      */
#define DMA_CCR5_PINC_SHIFT                      (6U)                                                /**< DMA_CCR5.PINC Position                  */
#define DMA_CCR5_PINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_PINC_SHIFT))&DMA_CCR5_PINC_MASK) /**< DMA_CCR5.PINC Field                     */
#define DMA_CCR5_MINC_MASK                       (0x80U)                                             /**< DMA_CCR5.MINC Mask                      */
#define DMA_CCR5_MINC_SHIFT                      (7U)                                                /**< DMA_CCR5.MINC Position                  */
#define DMA_CCR5_MINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_MINC_SHIFT))&DMA_CCR5_MINC_MASK) /**< DMA_CCR5.MINC Field                     */
#define DMA_CCR5_PSIZE_MASK                      (0x300U)                                            /**< DMA_CCR5.PSIZE Mask                     */
#define DMA_CCR5_PSIZE_SHIFT                     (8U)                                                /**< DMA_CCR5.PSIZE Position                 */
#define DMA_CCR5_PSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_PSIZE_SHIFT))&DMA_CCR5_PSIZE_MASK) /**< DMA_CCR5.PSIZE Field                    */
#define DMA_CCR5_MSIZE_MASK                      (0xC00U)                                            /**< DMA_CCR5.MSIZE Mask                     */
#define DMA_CCR5_MSIZE_SHIFT                     (10U)                                               /**< DMA_CCR5.MSIZE Position                 */
#define DMA_CCR5_MSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_MSIZE_SHIFT))&DMA_CCR5_MSIZE_MASK) /**< DMA_CCR5.MSIZE Field                    */
#define DMA_CCR5_PL_MASK                         (0x3000U)                                           /**< DMA_CCR5.PL Mask                        */
#define DMA_CCR5_PL_SHIFT                        (12U)                                               /**< DMA_CCR5.PL Position                    */
#define DMA_CCR5_PL(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_PL_SHIFT))&DMA_CCR5_PL_MASK) /**< DMA_CCR5.PL Field                       */
#define DMA_CCR5_MEM2MEM_MASK                    (0x4000U)                                           /**< DMA_CCR5.MEM2MEM Mask                   */
#define DMA_CCR5_MEM2MEM_SHIFT                   (14U)                                               /**< DMA_CCR5.MEM2MEM Position               */
#define DMA_CCR5_MEM2MEM(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_CCR5_MEM2MEM_SHIFT))&DMA_CCR5_MEM2MEM_MASK) /**< DMA_CCR5.MEM2MEM Field                  */
/** @} */

/** @name CNDTR5 - DMA channel 5 number of data */ /** @{ */
#define DMA_CNDTR5_NDT_MASK                      (0xFFFFU)                                           /**< DMA_CNDTR5.NDT Mask                     */
#define DMA_CNDTR5_NDT_SHIFT                     (0U)                                                /**< DMA_CNDTR5.NDT Position                 */
#define DMA_CNDTR5_NDT(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CNDTR5_NDT_SHIFT))&DMA_CNDTR5_NDT_MASK) /**< DMA_CNDTR5.NDT Field                    */
/** @} */

/** @name CPAR5 - DMA channel 5 peripheral address */ /** @{ */
#define DMA_CPAR5_PA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CPAR5.PA Mask                       */
#define DMA_CPAR5_PA_SHIFT                       (0U)                                                /**< DMA_CPAR5.PA Position                   */
#define DMA_CPAR5_PA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CPAR5_PA_SHIFT))&DMA_CPAR5_PA_MASK) /**< DMA_CPAR5.PA Field                      */
/** @} */

/** @name CMAR5 - DMA channel 5 memory address */ /** @{ */
#define DMA_CMAR5_MA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CMAR5.MA Mask                       */
#define DMA_CMAR5_MA_SHIFT                       (0U)                                                /**< DMA_CMAR5.MA Position                   */
#define DMA_CMAR5_MA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CMAR5_MA_SHIFT))&DMA_CMAR5_MA_MASK) /**< DMA_CMAR5.MA Field                      */
/** @} */

/** @name CCR6 - DMA channel configuration register */ /** @{ */
#define DMA_CCR6_EN_MASK                         (0x1U)                                              /**< DMA_CCR6.EN Mask                        */
#define DMA_CCR6_EN_SHIFT                        (0U)                                                /**< DMA_CCR6.EN Position                    */
#define DMA_CCR6_EN(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_EN_SHIFT))&DMA_CCR6_EN_MASK) /**< DMA_CCR6.EN Field                       */
#define DMA_CCR6_TCIE_MASK                       (0x2U)                                              /**< DMA_CCR6.TCIE Mask                      */
#define DMA_CCR6_TCIE_SHIFT                      (1U)                                                /**< DMA_CCR6.TCIE Position                  */
#define DMA_CCR6_TCIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_TCIE_SHIFT))&DMA_CCR6_TCIE_MASK) /**< DMA_CCR6.TCIE Field                     */
#define DMA_CCR6_HTIE_MASK                       (0x4U)                                              /**< DMA_CCR6.HTIE Mask                      */
#define DMA_CCR6_HTIE_SHIFT                      (2U)                                                /**< DMA_CCR6.HTIE Position                  */
#define DMA_CCR6_HTIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_HTIE_SHIFT))&DMA_CCR6_HTIE_MASK) /**< DMA_CCR6.HTIE Field                     */
#define DMA_CCR6_TEIE_MASK                       (0x8U)                                              /**< DMA_CCR6.TEIE Mask                      */
#define DMA_CCR6_TEIE_SHIFT                      (3U)                                                /**< DMA_CCR6.TEIE Position                  */
#define DMA_CCR6_TEIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_TEIE_SHIFT))&DMA_CCR6_TEIE_MASK) /**< DMA_CCR6.TEIE Field                     */
#define DMA_CCR6_DIR_MASK                        (0x10U)                                             /**< DMA_CCR6.DIR Mask                       */
#define DMA_CCR6_DIR_SHIFT                       (4U)                                                /**< DMA_CCR6.DIR Position                   */
#define DMA_CCR6_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_DIR_SHIFT))&DMA_CCR6_DIR_MASK) /**< DMA_CCR6.DIR Field                      */
#define DMA_CCR6_CIRC_MASK                       (0x20U)                                             /**< DMA_CCR6.CIRC Mask                      */
#define DMA_CCR6_CIRC_SHIFT                      (5U)                                                /**< DMA_CCR6.CIRC Position                  */
#define DMA_CCR6_CIRC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_CIRC_SHIFT))&DMA_CCR6_CIRC_MASK) /**< DMA_CCR6.CIRC Field                     */
#define DMA_CCR6_PINC_MASK                       (0x40U)                                             /**< DMA_CCR6.PINC Mask                      */
#define DMA_CCR6_PINC_SHIFT                      (6U)                                                /**< DMA_CCR6.PINC Position                  */
#define DMA_CCR6_PINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_PINC_SHIFT))&DMA_CCR6_PINC_MASK) /**< DMA_CCR6.PINC Field                     */
#define DMA_CCR6_MINC_MASK                       (0x80U)                                             /**< DMA_CCR6.MINC Mask                      */
#define DMA_CCR6_MINC_SHIFT                      (7U)                                                /**< DMA_CCR6.MINC Position                  */
#define DMA_CCR6_MINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_MINC_SHIFT))&DMA_CCR6_MINC_MASK) /**< DMA_CCR6.MINC Field                     */
#define DMA_CCR6_PSIZE_MASK                      (0x300U)                                            /**< DMA_CCR6.PSIZE Mask                     */
#define DMA_CCR6_PSIZE_SHIFT                     (8U)                                                /**< DMA_CCR6.PSIZE Position                 */
#define DMA_CCR6_PSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_PSIZE_SHIFT))&DMA_CCR6_PSIZE_MASK) /**< DMA_CCR6.PSIZE Field                    */
#define DMA_CCR6_MSIZE_MASK                      (0xC00U)                                            /**< DMA_CCR6.MSIZE Mask                     */
#define DMA_CCR6_MSIZE_SHIFT                     (10U)                                               /**< DMA_CCR6.MSIZE Position                 */
#define DMA_CCR6_MSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_MSIZE_SHIFT))&DMA_CCR6_MSIZE_MASK) /**< DMA_CCR6.MSIZE Field                    */
#define DMA_CCR6_PL_MASK                         (0x3000U)                                           /**< DMA_CCR6.PL Mask                        */
#define DMA_CCR6_PL_SHIFT                        (12U)                                               /**< DMA_CCR6.PL Position                    */
#define DMA_CCR6_PL(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_PL_SHIFT))&DMA_CCR6_PL_MASK) /**< DMA_CCR6.PL Field                       */
#define DMA_CCR6_MEM2MEM_MASK                    (0x4000U)                                           /**< DMA_CCR6.MEM2MEM Mask                   */
#define DMA_CCR6_MEM2MEM_SHIFT                   (14U)                                               /**< DMA_CCR6.MEM2MEM Position               */
#define DMA_CCR6_MEM2MEM(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_CCR6_MEM2MEM_SHIFT))&DMA_CCR6_MEM2MEM_MASK) /**< DMA_CCR6.MEM2MEM Field                  */
/** @} */

/** @name CNDTR6 - DMA channel 6 number of data */ /** @{ */
#define DMA_CNDTR6_NDT_MASK                      (0xFFFFU)                                           /**< DMA_CNDTR6.NDT Mask                     */
#define DMA_CNDTR6_NDT_SHIFT                     (0U)                                                /**< DMA_CNDTR6.NDT Position                 */
#define DMA_CNDTR6_NDT(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CNDTR6_NDT_SHIFT))&DMA_CNDTR6_NDT_MASK) /**< DMA_CNDTR6.NDT Field                    */
/** @} */

/** @name CPAR6 - DMA channel 6 peripheral address */ /** @{ */
#define DMA_CPAR6_PA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CPAR6.PA Mask                       */
#define DMA_CPAR6_PA_SHIFT                       (0U)                                                /**< DMA_CPAR6.PA Position                   */
#define DMA_CPAR6_PA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CPAR6_PA_SHIFT))&DMA_CPAR6_PA_MASK) /**< DMA_CPAR6.PA Field                      */
/** @} */

/** @name CMAR6 - DMA channel 6 memory address */ /** @{ */
#define DMA_CMAR6_MA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CMAR6.MA Mask                       */
#define DMA_CMAR6_MA_SHIFT                       (0U)                                                /**< DMA_CMAR6.MA Position                   */
#define DMA_CMAR6_MA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CMAR6_MA_SHIFT))&DMA_CMAR6_MA_MASK) /**< DMA_CMAR6.MA Field                      */
/** @} */

/** @name CCR7 - DMA channel configuration register */ /** @{ */
#define DMA_CCR7_EN_MASK                         (0x1U)                                              /**< DMA_CCR7.EN Mask                        */
#define DMA_CCR7_EN_SHIFT                        (0U)                                                /**< DMA_CCR7.EN Position                    */
#define DMA_CCR7_EN(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_EN_SHIFT))&DMA_CCR7_EN_MASK) /**< DMA_CCR7.EN Field                       */
#define DMA_CCR7_TCIE_MASK                       (0x2U)                                              /**< DMA_CCR7.TCIE Mask                      */
#define DMA_CCR7_TCIE_SHIFT                      (1U)                                                /**< DMA_CCR7.TCIE Position                  */
#define DMA_CCR7_TCIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_TCIE_SHIFT))&DMA_CCR7_TCIE_MASK) /**< DMA_CCR7.TCIE Field                     */
#define DMA_CCR7_HTIE_MASK                       (0x4U)                                              /**< DMA_CCR7.HTIE Mask                      */
#define DMA_CCR7_HTIE_SHIFT                      (2U)                                                /**< DMA_CCR7.HTIE Position                  */
#define DMA_CCR7_HTIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_HTIE_SHIFT))&DMA_CCR7_HTIE_MASK) /**< DMA_CCR7.HTIE Field                     */
#define DMA_CCR7_TEIE_MASK                       (0x8U)                                              /**< DMA_CCR7.TEIE Mask                      */
#define DMA_CCR7_TEIE_SHIFT                      (3U)                                                /**< DMA_CCR7.TEIE Position                  */
#define DMA_CCR7_TEIE(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_TEIE_SHIFT))&DMA_CCR7_TEIE_MASK) /**< DMA_CCR7.TEIE Field                     */
#define DMA_CCR7_DIR_MASK                        (0x10U)                                             /**< DMA_CCR7.DIR Mask                       */
#define DMA_CCR7_DIR_SHIFT                       (4U)                                                /**< DMA_CCR7.DIR Position                   */
#define DMA_CCR7_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_DIR_SHIFT))&DMA_CCR7_DIR_MASK) /**< DMA_CCR7.DIR Field                      */
#define DMA_CCR7_CIRC_MASK                       (0x20U)                                             /**< DMA_CCR7.CIRC Mask                      */
#define DMA_CCR7_CIRC_SHIFT                      (5U)                                                /**< DMA_CCR7.CIRC Position                  */
#define DMA_CCR7_CIRC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_CIRC_SHIFT))&DMA_CCR7_CIRC_MASK) /**< DMA_CCR7.CIRC Field                     */
#define DMA_CCR7_PINC_MASK                       (0x40U)                                             /**< DMA_CCR7.PINC Mask                      */
#define DMA_CCR7_PINC_SHIFT                      (6U)                                                /**< DMA_CCR7.PINC Position                  */
#define DMA_CCR7_PINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_PINC_SHIFT))&DMA_CCR7_PINC_MASK) /**< DMA_CCR7.PINC Field                     */
#define DMA_CCR7_MINC_MASK                       (0x80U)                                             /**< DMA_CCR7.MINC Mask                      */
#define DMA_CCR7_MINC_SHIFT                      (7U)                                                /**< DMA_CCR7.MINC Position                  */
#define DMA_CCR7_MINC(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_MINC_SHIFT))&DMA_CCR7_MINC_MASK) /**< DMA_CCR7.MINC Field                     */
#define DMA_CCR7_PSIZE_MASK                      (0x300U)                                            /**< DMA_CCR7.PSIZE Mask                     */
#define DMA_CCR7_PSIZE_SHIFT                     (8U)                                                /**< DMA_CCR7.PSIZE Position                 */
#define DMA_CCR7_PSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_PSIZE_SHIFT))&DMA_CCR7_PSIZE_MASK) /**< DMA_CCR7.PSIZE Field                    */
#define DMA_CCR7_MSIZE_MASK                      (0xC00U)                                            /**< DMA_CCR7.MSIZE Mask                     */
#define DMA_CCR7_MSIZE_SHIFT                     (10U)                                               /**< DMA_CCR7.MSIZE Position                 */
#define DMA_CCR7_MSIZE(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_MSIZE_SHIFT))&DMA_CCR7_MSIZE_MASK) /**< DMA_CCR7.MSIZE Field                    */
#define DMA_CCR7_PL_MASK                         (0x3000U)                                           /**< DMA_CCR7.PL Mask                        */
#define DMA_CCR7_PL_SHIFT                        (12U)                                               /**< DMA_CCR7.PL Position                    */
#define DMA_CCR7_PL(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_PL_SHIFT))&DMA_CCR7_PL_MASK) /**< DMA_CCR7.PL Field                       */
#define DMA_CCR7_MEM2MEM_MASK                    (0x4000U)                                           /**< DMA_CCR7.MEM2MEM Mask                   */
#define DMA_CCR7_MEM2MEM_SHIFT                   (14U)                                               /**< DMA_CCR7.MEM2MEM Position               */
#define DMA_CCR7_MEM2MEM(x)                      (((uint32_t)(((uint32_t)(x))<<DMA_CCR7_MEM2MEM_SHIFT))&DMA_CCR7_MEM2MEM_MASK) /**< DMA_CCR7.MEM2MEM Field                  */
/** @} */

/** @name CNDTR7 - DMA channel 7 number of data */ /** @{ */
#define DMA_CNDTR7_NDT_MASK                      (0xFFFFU)                                           /**< DMA_CNDTR7.NDT Mask                     */
#define DMA_CNDTR7_NDT_SHIFT                     (0U)                                                /**< DMA_CNDTR7.NDT Position                 */
#define DMA_CNDTR7_NDT(x)                        (((uint32_t)(((uint32_t)(x))<<DMA_CNDTR7_NDT_SHIFT))&DMA_CNDTR7_NDT_MASK) /**< DMA_CNDTR7.NDT Field                    */
/** @} */

/** @name CPAR7 - DMA channel 7 peripheral address */ /** @{ */
#define DMA_CPAR7_PA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CPAR7.PA Mask                       */
#define DMA_CPAR7_PA_SHIFT                       (0U)                                                /**< DMA_CPAR7.PA Position                   */
#define DMA_CPAR7_PA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CPAR7_PA_SHIFT))&DMA_CPAR7_PA_MASK) /**< DMA_CPAR7.PA Field                      */
/** @} */

/** @name CMAR7 - DMA channel 7 memory address */ /** @{ */
#define DMA_CMAR7_MA_MASK                        (0xFFFFFFFFU)                                       /**< DMA_CMAR7.MA Mask                       */
#define DMA_CMAR7_MA_SHIFT                       (0U)                                                /**< DMA_CMAR7.MA Position                   */
#define DMA_CMAR7_MA(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_CMAR7_MA_SHIFT))&DMA_CMAR7_MA_MASK) /**< DMA_CMAR7.MA Field                      */
/** @} */

/** @} */ /* End group DMA_Register_Masks_GROUP */


/* DMA - Peripheral instance base addresses */
#define DMA_BasePtr                    0x40020000UL //!< Peripheral base address
#define DMA                            ((DMA_Type *) DMA_BasePtr) //!< Freescale base pointer
#define DMA_BASE_PTR                   (DMA) //!< Freescale style base pointer
#define DMA_IRQS { TIM7_IRQn,  }


/** @} */ /* End group DMA_Peripheral_access_layer_GROUP */


/** @brief C Struct for EXTI */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup EXTI_Peripheral_access_layer_GROUP EXTI Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           EXTI (file:EXTI_STM32F030)           ================ */
/* ================================================================================ */

/**
 * @brief External interrupt/event
controller
 */
/**
 * @struct EXTI_Type
 * @brief  C Struct allowing access to EXTI registers
 */
typedef struct EXTI_Type {
   __IO uint32_t  IMR;                          /**< 0000: Interrupt mask register                                      */
   __IO uint32_t  EMR;                          /**< 0004: Event mask register (EXTI_EMR)                               */
   __IO uint32_t  RTSR;                         /**< 0008: Rising Trigger selection register                            */
   __IO uint32_t  FTSR;                         /**< 000C: Falling Trigger selection register                           */
   __IO uint32_t  SWIER;                        /**< 0010: Software interrupt event register                            */
   __IO uint32_t  PR;                           /**< 0014: Pending register (EXTI_PR)                                   */
} EXTI_Type;


/** @brief Register Masks for EXTI */

/* -------------------------------------------------------------------------------- */
/* -----------     'EXTI' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup EXTI_Register_Masks_GROUP EXTI Register Masks */
/** @{ */

/** @name IMR - Interrupt mask register */ /** @{ */
#define EXTI_IMR_MR0_MASK                        (0x1U)                                              /**< EXTI_IMR.MR0 Mask                       */
#define EXTI_IMR_MR0_SHIFT                       (0U)                                                /**< EXTI_IMR.MR0 Position                   */
#define EXTI_IMR_MR0(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR0_SHIFT))&EXTI_IMR_MR0_MASK) /**< EXTI_IMR.MR0 Field                      */
#define EXTI_IMR_MR1_MASK                        (0x2U)                                              /**< EXTI_IMR.MR1 Mask                       */
#define EXTI_IMR_MR1_SHIFT                       (1U)                                                /**< EXTI_IMR.MR1 Position                   */
#define EXTI_IMR_MR1(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR1_SHIFT))&EXTI_IMR_MR1_MASK) /**< EXTI_IMR.MR1 Field                      */
#define EXTI_IMR_MR2_MASK                        (0x4U)                                              /**< EXTI_IMR.MR2 Mask                       */
#define EXTI_IMR_MR2_SHIFT                       (2U)                                                /**< EXTI_IMR.MR2 Position                   */
#define EXTI_IMR_MR2(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR2_SHIFT))&EXTI_IMR_MR2_MASK) /**< EXTI_IMR.MR2 Field                      */
#define EXTI_IMR_MR3_MASK                        (0x8U)                                              /**< EXTI_IMR.MR3 Mask                       */
#define EXTI_IMR_MR3_SHIFT                       (3U)                                                /**< EXTI_IMR.MR3 Position                   */
#define EXTI_IMR_MR3(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR3_SHIFT))&EXTI_IMR_MR3_MASK) /**< EXTI_IMR.MR3 Field                      */
#define EXTI_IMR_MR4_MASK                        (0x10U)                                             /**< EXTI_IMR.MR4 Mask                       */
#define EXTI_IMR_MR4_SHIFT                       (4U)                                                /**< EXTI_IMR.MR4 Position                   */
#define EXTI_IMR_MR4(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR4_SHIFT))&EXTI_IMR_MR4_MASK) /**< EXTI_IMR.MR4 Field                      */
#define EXTI_IMR_MR5_MASK                        (0x20U)                                             /**< EXTI_IMR.MR5 Mask                       */
#define EXTI_IMR_MR5_SHIFT                       (5U)                                                /**< EXTI_IMR.MR5 Position                   */
#define EXTI_IMR_MR5(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR5_SHIFT))&EXTI_IMR_MR5_MASK) /**< EXTI_IMR.MR5 Field                      */
#define EXTI_IMR_MR6_MASK                        (0x40U)                                             /**< EXTI_IMR.MR6 Mask                       */
#define EXTI_IMR_MR6_SHIFT                       (6U)                                                /**< EXTI_IMR.MR6 Position                   */
#define EXTI_IMR_MR6(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR6_SHIFT))&EXTI_IMR_MR6_MASK) /**< EXTI_IMR.MR6 Field                      */
#define EXTI_IMR_MR7_MASK                        (0x80U)                                             /**< EXTI_IMR.MR7 Mask                       */
#define EXTI_IMR_MR7_SHIFT                       (7U)                                                /**< EXTI_IMR.MR7 Position                   */
#define EXTI_IMR_MR7(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR7_SHIFT))&EXTI_IMR_MR7_MASK) /**< EXTI_IMR.MR7 Field                      */
#define EXTI_IMR_MR8_MASK                        (0x100U)                                            /**< EXTI_IMR.MR8 Mask                       */
#define EXTI_IMR_MR8_SHIFT                       (8U)                                                /**< EXTI_IMR.MR8 Position                   */
#define EXTI_IMR_MR8(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR8_SHIFT))&EXTI_IMR_MR8_MASK) /**< EXTI_IMR.MR8 Field                      */
#define EXTI_IMR_MR9_MASK                        (0x200U)                                            /**< EXTI_IMR.MR9 Mask                       */
#define EXTI_IMR_MR9_SHIFT                       (9U)                                                /**< EXTI_IMR.MR9 Position                   */
#define EXTI_IMR_MR9(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR9_SHIFT))&EXTI_IMR_MR9_MASK) /**< EXTI_IMR.MR9 Field                      */
#define EXTI_IMR_MR10_MASK                       (0x400U)                                            /**< EXTI_IMR.MR10 Mask                      */
#define EXTI_IMR_MR10_SHIFT                      (10U)                                               /**< EXTI_IMR.MR10 Position                  */
#define EXTI_IMR_MR10(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR10_SHIFT))&EXTI_IMR_MR10_MASK) /**< EXTI_IMR.MR10 Field                     */
#define EXTI_IMR_MR11_MASK                       (0x800U)                                            /**< EXTI_IMR.MR11 Mask                      */
#define EXTI_IMR_MR11_SHIFT                      (11U)                                               /**< EXTI_IMR.MR11 Position                  */
#define EXTI_IMR_MR11(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR11_SHIFT))&EXTI_IMR_MR11_MASK) /**< EXTI_IMR.MR11 Field                     */
#define EXTI_IMR_MR12_MASK                       (0x1000U)                                           /**< EXTI_IMR.MR12 Mask                      */
#define EXTI_IMR_MR12_SHIFT                      (12U)                                               /**< EXTI_IMR.MR12 Position                  */
#define EXTI_IMR_MR12(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR12_SHIFT))&EXTI_IMR_MR12_MASK) /**< EXTI_IMR.MR12 Field                     */
#define EXTI_IMR_MR13_MASK                       (0x2000U)                                           /**< EXTI_IMR.MR13 Mask                      */
#define EXTI_IMR_MR13_SHIFT                      (13U)                                               /**< EXTI_IMR.MR13 Position                  */
#define EXTI_IMR_MR13(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR13_SHIFT))&EXTI_IMR_MR13_MASK) /**< EXTI_IMR.MR13 Field                     */
#define EXTI_IMR_MR14_MASK                       (0x4000U)                                           /**< EXTI_IMR.MR14 Mask                      */
#define EXTI_IMR_MR14_SHIFT                      (14U)                                               /**< EXTI_IMR.MR14 Position                  */
#define EXTI_IMR_MR14(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR14_SHIFT))&EXTI_IMR_MR14_MASK) /**< EXTI_IMR.MR14 Field                     */
#define EXTI_IMR_MR15_MASK                       (0x8000U)                                           /**< EXTI_IMR.MR15 Mask                      */
#define EXTI_IMR_MR15_SHIFT                      (15U)                                               /**< EXTI_IMR.MR15 Position                  */
#define EXTI_IMR_MR15(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR15_SHIFT))&EXTI_IMR_MR15_MASK) /**< EXTI_IMR.MR15 Field                     */
#define EXTI_IMR_MR16_MASK                       (0x10000U)                                          /**< EXTI_IMR.MR16 Mask                      */
#define EXTI_IMR_MR16_SHIFT                      (16U)                                               /**< EXTI_IMR.MR16 Position                  */
#define EXTI_IMR_MR16(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR16_SHIFT))&EXTI_IMR_MR16_MASK) /**< EXTI_IMR.MR16 Field                     */
#define EXTI_IMR_MR17_MASK                       (0x20000U)                                          /**< EXTI_IMR.MR17 Mask                      */
#define EXTI_IMR_MR17_SHIFT                      (17U)                                               /**< EXTI_IMR.MR17 Position                  */
#define EXTI_IMR_MR17(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR17_SHIFT))&EXTI_IMR_MR17_MASK) /**< EXTI_IMR.MR17 Field                     */
#define EXTI_IMR_MR18_MASK                       (0x40000U)                                          /**< EXTI_IMR.MR18 Mask                      */
#define EXTI_IMR_MR18_SHIFT                      (18U)                                               /**< EXTI_IMR.MR18 Position                  */
#define EXTI_IMR_MR18(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR18_SHIFT))&EXTI_IMR_MR18_MASK) /**< EXTI_IMR.MR18 Field                     */
#define EXTI_IMR_MR19_MASK                       (0x80000U)                                          /**< EXTI_IMR.MR19 Mask                      */
#define EXTI_IMR_MR19_SHIFT                      (19U)                                               /**< EXTI_IMR.MR19 Position                  */
#define EXTI_IMR_MR19(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR19_SHIFT))&EXTI_IMR_MR19_MASK) /**< EXTI_IMR.MR19 Field                     */
#define EXTI_IMR_MR20_MASK                       (0x100000U)                                         /**< EXTI_IMR.MR20 Mask                      */
#define EXTI_IMR_MR20_SHIFT                      (20U)                                               /**< EXTI_IMR.MR20 Position                  */
#define EXTI_IMR_MR20(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR20_SHIFT))&EXTI_IMR_MR20_MASK) /**< EXTI_IMR.MR20 Field                     */
#define EXTI_IMR_MR21_MASK                       (0x200000U)                                         /**< EXTI_IMR.MR21 Mask                      */
#define EXTI_IMR_MR21_SHIFT                      (21U)                                               /**< EXTI_IMR.MR21 Position                  */
#define EXTI_IMR_MR21(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR21_SHIFT))&EXTI_IMR_MR21_MASK) /**< EXTI_IMR.MR21 Field                     */
#define EXTI_IMR_MR22_MASK                       (0x400000U)                                         /**< EXTI_IMR.MR22 Mask                      */
#define EXTI_IMR_MR22_SHIFT                      (22U)                                               /**< EXTI_IMR.MR22 Position                  */
#define EXTI_IMR_MR22(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR22_SHIFT))&EXTI_IMR_MR22_MASK) /**< EXTI_IMR.MR22 Field                     */
#define EXTI_IMR_MR23_MASK                       (0x800000U)                                         /**< EXTI_IMR.MR23 Mask                      */
#define EXTI_IMR_MR23_SHIFT                      (23U)                                               /**< EXTI_IMR.MR23 Position                  */
#define EXTI_IMR_MR23(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR23_SHIFT))&EXTI_IMR_MR23_MASK) /**< EXTI_IMR.MR23 Field                     */
#define EXTI_IMR_MR24_MASK                       (0x1000000U)                                        /**< EXTI_IMR.MR24 Mask                      */
#define EXTI_IMR_MR24_SHIFT                      (24U)                                               /**< EXTI_IMR.MR24 Position                  */
#define EXTI_IMR_MR24(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR24_SHIFT))&EXTI_IMR_MR24_MASK) /**< EXTI_IMR.MR24 Field                     */
#define EXTI_IMR_MR25_MASK                       (0x2000000U)                                        /**< EXTI_IMR.MR25 Mask                      */
#define EXTI_IMR_MR25_SHIFT                      (25U)                                               /**< EXTI_IMR.MR25 Position                  */
#define EXTI_IMR_MR25(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR25_SHIFT))&EXTI_IMR_MR25_MASK) /**< EXTI_IMR.MR25 Field                     */
#define EXTI_IMR_MR26_MASK                       (0x4000000U)                                        /**< EXTI_IMR.MR26 Mask                      */
#define EXTI_IMR_MR26_SHIFT                      (26U)                                               /**< EXTI_IMR.MR26 Position                  */
#define EXTI_IMR_MR26(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR26_SHIFT))&EXTI_IMR_MR26_MASK) /**< EXTI_IMR.MR26 Field                     */
#define EXTI_IMR_MR27_MASK                       (0x8000000U)                                        /**< EXTI_IMR.MR27 Mask                      */
#define EXTI_IMR_MR27_SHIFT                      (27U)                                               /**< EXTI_IMR.MR27 Position                  */
#define EXTI_IMR_MR27(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_IMR_MR27_SHIFT))&EXTI_IMR_MR27_MASK) /**< EXTI_IMR.MR27 Field                     */
/** @} */

/** @name EMR - Event mask register (EXTI_EMR) */ /** @{ */
#define EXTI_EMR_MR0_MASK                        (0x1U)                                              /**< EXTI_EMR.MR0 Mask                       */
#define EXTI_EMR_MR0_SHIFT                       (0U)                                                /**< EXTI_EMR.MR0 Position                   */
#define EXTI_EMR_MR0(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR0_SHIFT))&EXTI_EMR_MR0_MASK) /**< EXTI_EMR.MR0 Field                      */
#define EXTI_EMR_MR1_MASK                        (0x2U)                                              /**< EXTI_EMR.MR1 Mask                       */
#define EXTI_EMR_MR1_SHIFT                       (1U)                                                /**< EXTI_EMR.MR1 Position                   */
#define EXTI_EMR_MR1(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR1_SHIFT))&EXTI_EMR_MR1_MASK) /**< EXTI_EMR.MR1 Field                      */
#define EXTI_EMR_MR2_MASK                        (0x4U)                                              /**< EXTI_EMR.MR2 Mask                       */
#define EXTI_EMR_MR2_SHIFT                       (2U)                                                /**< EXTI_EMR.MR2 Position                   */
#define EXTI_EMR_MR2(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR2_SHIFT))&EXTI_EMR_MR2_MASK) /**< EXTI_EMR.MR2 Field                      */
#define EXTI_EMR_MR3_MASK                        (0x8U)                                              /**< EXTI_EMR.MR3 Mask                       */
#define EXTI_EMR_MR3_SHIFT                       (3U)                                                /**< EXTI_EMR.MR3 Position                   */
#define EXTI_EMR_MR3(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR3_SHIFT))&EXTI_EMR_MR3_MASK) /**< EXTI_EMR.MR3 Field                      */
#define EXTI_EMR_MR4_MASK                        (0x10U)                                             /**< EXTI_EMR.MR4 Mask                       */
#define EXTI_EMR_MR4_SHIFT                       (4U)                                                /**< EXTI_EMR.MR4 Position                   */
#define EXTI_EMR_MR4(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR4_SHIFT))&EXTI_EMR_MR4_MASK) /**< EXTI_EMR.MR4 Field                      */
#define EXTI_EMR_MR5_MASK                        (0x20U)                                             /**< EXTI_EMR.MR5 Mask                       */
#define EXTI_EMR_MR5_SHIFT                       (5U)                                                /**< EXTI_EMR.MR5 Position                   */
#define EXTI_EMR_MR5(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR5_SHIFT))&EXTI_EMR_MR5_MASK) /**< EXTI_EMR.MR5 Field                      */
#define EXTI_EMR_MR6_MASK                        (0x40U)                                             /**< EXTI_EMR.MR6 Mask                       */
#define EXTI_EMR_MR6_SHIFT                       (6U)                                                /**< EXTI_EMR.MR6 Position                   */
#define EXTI_EMR_MR6(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR6_SHIFT))&EXTI_EMR_MR6_MASK) /**< EXTI_EMR.MR6 Field                      */
#define EXTI_EMR_MR7_MASK                        (0x80U)                                             /**< EXTI_EMR.MR7 Mask                       */
#define EXTI_EMR_MR7_SHIFT                       (7U)                                                /**< EXTI_EMR.MR7 Position                   */
#define EXTI_EMR_MR7(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR7_SHIFT))&EXTI_EMR_MR7_MASK) /**< EXTI_EMR.MR7 Field                      */
#define EXTI_EMR_MR8_MASK                        (0x100U)                                            /**< EXTI_EMR.MR8 Mask                       */
#define EXTI_EMR_MR8_SHIFT                       (8U)                                                /**< EXTI_EMR.MR8 Position                   */
#define EXTI_EMR_MR8(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR8_SHIFT))&EXTI_EMR_MR8_MASK) /**< EXTI_EMR.MR8 Field                      */
#define EXTI_EMR_MR9_MASK                        (0x200U)                                            /**< EXTI_EMR.MR9 Mask                       */
#define EXTI_EMR_MR9_SHIFT                       (9U)                                                /**< EXTI_EMR.MR9 Position                   */
#define EXTI_EMR_MR9(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR9_SHIFT))&EXTI_EMR_MR9_MASK) /**< EXTI_EMR.MR9 Field                      */
#define EXTI_EMR_MR10_MASK                       (0x400U)                                            /**< EXTI_EMR.MR10 Mask                      */
#define EXTI_EMR_MR10_SHIFT                      (10U)                                               /**< EXTI_EMR.MR10 Position                  */
#define EXTI_EMR_MR10(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR10_SHIFT))&EXTI_EMR_MR10_MASK) /**< EXTI_EMR.MR10 Field                     */
#define EXTI_EMR_MR11_MASK                       (0x800U)                                            /**< EXTI_EMR.MR11 Mask                      */
#define EXTI_EMR_MR11_SHIFT                      (11U)                                               /**< EXTI_EMR.MR11 Position                  */
#define EXTI_EMR_MR11(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR11_SHIFT))&EXTI_EMR_MR11_MASK) /**< EXTI_EMR.MR11 Field                     */
#define EXTI_EMR_MR12_MASK                       (0x1000U)                                           /**< EXTI_EMR.MR12 Mask                      */
#define EXTI_EMR_MR12_SHIFT                      (12U)                                               /**< EXTI_EMR.MR12 Position                  */
#define EXTI_EMR_MR12(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR12_SHIFT))&EXTI_EMR_MR12_MASK) /**< EXTI_EMR.MR12 Field                     */
#define EXTI_EMR_MR13_MASK                       (0x2000U)                                           /**< EXTI_EMR.MR13 Mask                      */
#define EXTI_EMR_MR13_SHIFT                      (13U)                                               /**< EXTI_EMR.MR13 Position                  */
#define EXTI_EMR_MR13(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR13_SHIFT))&EXTI_EMR_MR13_MASK) /**< EXTI_EMR.MR13 Field                     */
#define EXTI_EMR_MR14_MASK                       (0x4000U)                                           /**< EXTI_EMR.MR14 Mask                      */
#define EXTI_EMR_MR14_SHIFT                      (14U)                                               /**< EXTI_EMR.MR14 Position                  */
#define EXTI_EMR_MR14(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR14_SHIFT))&EXTI_EMR_MR14_MASK) /**< EXTI_EMR.MR14 Field                     */
#define EXTI_EMR_MR15_MASK                       (0x8000U)                                           /**< EXTI_EMR.MR15 Mask                      */
#define EXTI_EMR_MR15_SHIFT                      (15U)                                               /**< EXTI_EMR.MR15 Position                  */
#define EXTI_EMR_MR15(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR15_SHIFT))&EXTI_EMR_MR15_MASK) /**< EXTI_EMR.MR15 Field                     */
#define EXTI_EMR_MR16_MASK                       (0x10000U)                                          /**< EXTI_EMR.MR16 Mask                      */
#define EXTI_EMR_MR16_SHIFT                      (16U)                                               /**< EXTI_EMR.MR16 Position                  */
#define EXTI_EMR_MR16(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR16_SHIFT))&EXTI_EMR_MR16_MASK) /**< EXTI_EMR.MR16 Field                     */
#define EXTI_EMR_MR17_MASK                       (0x20000U)                                          /**< EXTI_EMR.MR17 Mask                      */
#define EXTI_EMR_MR17_SHIFT                      (17U)                                               /**< EXTI_EMR.MR17 Position                  */
#define EXTI_EMR_MR17(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR17_SHIFT))&EXTI_EMR_MR17_MASK) /**< EXTI_EMR.MR17 Field                     */
#define EXTI_EMR_MR18_MASK                       (0x40000U)                                          /**< EXTI_EMR.MR18 Mask                      */
#define EXTI_EMR_MR18_SHIFT                      (18U)                                               /**< EXTI_EMR.MR18 Position                  */
#define EXTI_EMR_MR18(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR18_SHIFT))&EXTI_EMR_MR18_MASK) /**< EXTI_EMR.MR18 Field                     */
#define EXTI_EMR_MR19_MASK                       (0x80000U)                                          /**< EXTI_EMR.MR19 Mask                      */
#define EXTI_EMR_MR19_SHIFT                      (19U)                                               /**< EXTI_EMR.MR19 Position                  */
#define EXTI_EMR_MR19(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR19_SHIFT))&EXTI_EMR_MR19_MASK) /**< EXTI_EMR.MR19 Field                     */
#define EXTI_EMR_MR20_MASK                       (0x100000U)                                         /**< EXTI_EMR.MR20 Mask                      */
#define EXTI_EMR_MR20_SHIFT                      (20U)                                               /**< EXTI_EMR.MR20 Position                  */
#define EXTI_EMR_MR20(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR20_SHIFT))&EXTI_EMR_MR20_MASK) /**< EXTI_EMR.MR20 Field                     */
#define EXTI_EMR_MR21_MASK                       (0x200000U)                                         /**< EXTI_EMR.MR21 Mask                      */
#define EXTI_EMR_MR21_SHIFT                      (21U)                                               /**< EXTI_EMR.MR21 Position                  */
#define EXTI_EMR_MR21(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR21_SHIFT))&EXTI_EMR_MR21_MASK) /**< EXTI_EMR.MR21 Field                     */
#define EXTI_EMR_MR22_MASK                       (0x400000U)                                         /**< EXTI_EMR.MR22 Mask                      */
#define EXTI_EMR_MR22_SHIFT                      (22U)                                               /**< EXTI_EMR.MR22 Position                  */
#define EXTI_EMR_MR22(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR22_SHIFT))&EXTI_EMR_MR22_MASK) /**< EXTI_EMR.MR22 Field                     */
#define EXTI_EMR_MR23_MASK                       (0x800000U)                                         /**< EXTI_EMR.MR23 Mask                      */
#define EXTI_EMR_MR23_SHIFT                      (23U)                                               /**< EXTI_EMR.MR23 Position                  */
#define EXTI_EMR_MR23(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR23_SHIFT))&EXTI_EMR_MR23_MASK) /**< EXTI_EMR.MR23 Field                     */
#define EXTI_EMR_MR24_MASK                       (0x1000000U)                                        /**< EXTI_EMR.MR24 Mask                      */
#define EXTI_EMR_MR24_SHIFT                      (24U)                                               /**< EXTI_EMR.MR24 Position                  */
#define EXTI_EMR_MR24(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR24_SHIFT))&EXTI_EMR_MR24_MASK) /**< EXTI_EMR.MR24 Field                     */
#define EXTI_EMR_MR25_MASK                       (0x2000000U)                                        /**< EXTI_EMR.MR25 Mask                      */
#define EXTI_EMR_MR25_SHIFT                      (25U)                                               /**< EXTI_EMR.MR25 Position                  */
#define EXTI_EMR_MR25(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR25_SHIFT))&EXTI_EMR_MR25_MASK) /**< EXTI_EMR.MR25 Field                     */
#define EXTI_EMR_MR26_MASK                       (0x4000000U)                                        /**< EXTI_EMR.MR26 Mask                      */
#define EXTI_EMR_MR26_SHIFT                      (26U)                                               /**< EXTI_EMR.MR26 Position                  */
#define EXTI_EMR_MR26(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR26_SHIFT))&EXTI_EMR_MR26_MASK) /**< EXTI_EMR.MR26 Field                     */
#define EXTI_EMR_MR27_MASK                       (0x8000000U)                                        /**< EXTI_EMR.MR27 Mask                      */
#define EXTI_EMR_MR27_SHIFT                      (27U)                                               /**< EXTI_EMR.MR27 Position                  */
#define EXTI_EMR_MR27(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_EMR_MR27_SHIFT))&EXTI_EMR_MR27_MASK) /**< EXTI_EMR.MR27 Field                     */
/** @} */

/** @name RTSR - Rising Trigger selection register */ /** @{ */
#define EXTI_RTSR_TR0_MASK                       (0x1U)                                              /**< EXTI_RTSR.TR0 Mask                      */
#define EXTI_RTSR_TR0_SHIFT                      (0U)                                                /**< EXTI_RTSR.TR0 Position                  */
#define EXTI_RTSR_TR0(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR0_SHIFT))&EXTI_RTSR_TR0_MASK) /**< EXTI_RTSR.TR0 Field                     */
#define EXTI_RTSR_TR1_MASK                       (0x2U)                                              /**< EXTI_RTSR.TR1 Mask                      */
#define EXTI_RTSR_TR1_SHIFT                      (1U)                                                /**< EXTI_RTSR.TR1 Position                  */
#define EXTI_RTSR_TR1(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR1_SHIFT))&EXTI_RTSR_TR1_MASK) /**< EXTI_RTSR.TR1 Field                     */
#define EXTI_RTSR_TR2_MASK                       (0x4U)                                              /**< EXTI_RTSR.TR2 Mask                      */
#define EXTI_RTSR_TR2_SHIFT                      (2U)                                                /**< EXTI_RTSR.TR2 Position                  */
#define EXTI_RTSR_TR2(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR2_SHIFT))&EXTI_RTSR_TR2_MASK) /**< EXTI_RTSR.TR2 Field                     */
#define EXTI_RTSR_TR3_MASK                       (0x8U)                                              /**< EXTI_RTSR.TR3 Mask                      */
#define EXTI_RTSR_TR3_SHIFT                      (3U)                                                /**< EXTI_RTSR.TR3 Position                  */
#define EXTI_RTSR_TR3(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR3_SHIFT))&EXTI_RTSR_TR3_MASK) /**< EXTI_RTSR.TR3 Field                     */
#define EXTI_RTSR_TR4_MASK                       (0x10U)                                             /**< EXTI_RTSR.TR4 Mask                      */
#define EXTI_RTSR_TR4_SHIFT                      (4U)                                                /**< EXTI_RTSR.TR4 Position                  */
#define EXTI_RTSR_TR4(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR4_SHIFT))&EXTI_RTSR_TR4_MASK) /**< EXTI_RTSR.TR4 Field                     */
#define EXTI_RTSR_TR5_MASK                       (0x20U)                                             /**< EXTI_RTSR.TR5 Mask                      */
#define EXTI_RTSR_TR5_SHIFT                      (5U)                                                /**< EXTI_RTSR.TR5 Position                  */
#define EXTI_RTSR_TR5(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR5_SHIFT))&EXTI_RTSR_TR5_MASK) /**< EXTI_RTSR.TR5 Field                     */
#define EXTI_RTSR_TR6_MASK                       (0x40U)                                             /**< EXTI_RTSR.TR6 Mask                      */
#define EXTI_RTSR_TR6_SHIFT                      (6U)                                                /**< EXTI_RTSR.TR6 Position                  */
#define EXTI_RTSR_TR6(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR6_SHIFT))&EXTI_RTSR_TR6_MASK) /**< EXTI_RTSR.TR6 Field                     */
#define EXTI_RTSR_TR7_MASK                       (0x80U)                                             /**< EXTI_RTSR.TR7 Mask                      */
#define EXTI_RTSR_TR7_SHIFT                      (7U)                                                /**< EXTI_RTSR.TR7 Position                  */
#define EXTI_RTSR_TR7(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR7_SHIFT))&EXTI_RTSR_TR7_MASK) /**< EXTI_RTSR.TR7 Field                     */
#define EXTI_RTSR_TR8_MASK                       (0x100U)                                            /**< EXTI_RTSR.TR8 Mask                      */
#define EXTI_RTSR_TR8_SHIFT                      (8U)                                                /**< EXTI_RTSR.TR8 Position                  */
#define EXTI_RTSR_TR8(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR8_SHIFT))&EXTI_RTSR_TR8_MASK) /**< EXTI_RTSR.TR8 Field                     */
#define EXTI_RTSR_TR9_MASK                       (0x200U)                                            /**< EXTI_RTSR.TR9 Mask                      */
#define EXTI_RTSR_TR9_SHIFT                      (9U)                                                /**< EXTI_RTSR.TR9 Position                  */
#define EXTI_RTSR_TR9(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR9_SHIFT))&EXTI_RTSR_TR9_MASK) /**< EXTI_RTSR.TR9 Field                     */
#define EXTI_RTSR_TR10_MASK                      (0x400U)                                            /**< EXTI_RTSR.TR10 Mask                     */
#define EXTI_RTSR_TR10_SHIFT                     (10U)                                               /**< EXTI_RTSR.TR10 Position                 */
#define EXTI_RTSR_TR10(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR10_SHIFT))&EXTI_RTSR_TR10_MASK) /**< EXTI_RTSR.TR10 Field                    */
#define EXTI_RTSR_TR11_MASK                      (0x800U)                                            /**< EXTI_RTSR.TR11 Mask                     */
#define EXTI_RTSR_TR11_SHIFT                     (11U)                                               /**< EXTI_RTSR.TR11 Position                 */
#define EXTI_RTSR_TR11(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR11_SHIFT))&EXTI_RTSR_TR11_MASK) /**< EXTI_RTSR.TR11 Field                    */
#define EXTI_RTSR_TR12_MASK                      (0x1000U)                                           /**< EXTI_RTSR.TR12 Mask                     */
#define EXTI_RTSR_TR12_SHIFT                     (12U)                                               /**< EXTI_RTSR.TR12 Position                 */
#define EXTI_RTSR_TR12(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR12_SHIFT))&EXTI_RTSR_TR12_MASK) /**< EXTI_RTSR.TR12 Field                    */
#define EXTI_RTSR_TR13_MASK                      (0x2000U)                                           /**< EXTI_RTSR.TR13 Mask                     */
#define EXTI_RTSR_TR13_SHIFT                     (13U)                                               /**< EXTI_RTSR.TR13 Position                 */
#define EXTI_RTSR_TR13(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR13_SHIFT))&EXTI_RTSR_TR13_MASK) /**< EXTI_RTSR.TR13 Field                    */
#define EXTI_RTSR_TR14_MASK                      (0x4000U)                                           /**< EXTI_RTSR.TR14 Mask                     */
#define EXTI_RTSR_TR14_SHIFT                     (14U)                                               /**< EXTI_RTSR.TR14 Position                 */
#define EXTI_RTSR_TR14(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR14_SHIFT))&EXTI_RTSR_TR14_MASK) /**< EXTI_RTSR.TR14 Field                    */
#define EXTI_RTSR_TR15_MASK                      (0x8000U)                                           /**< EXTI_RTSR.TR15 Mask                     */
#define EXTI_RTSR_TR15_SHIFT                     (15U)                                               /**< EXTI_RTSR.TR15 Position                 */
#define EXTI_RTSR_TR15(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR15_SHIFT))&EXTI_RTSR_TR15_MASK) /**< EXTI_RTSR.TR15 Field                    */
#define EXTI_RTSR_TR16_MASK                      (0x10000U)                                          /**< EXTI_RTSR.TR16 Mask                     */
#define EXTI_RTSR_TR16_SHIFT                     (16U)                                               /**< EXTI_RTSR.TR16 Position                 */
#define EXTI_RTSR_TR16(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR16_SHIFT))&EXTI_RTSR_TR16_MASK) /**< EXTI_RTSR.TR16 Field                    */
#define EXTI_RTSR_TR17_MASK                      (0x20000U)                                          /**< EXTI_RTSR.TR17 Mask                     */
#define EXTI_RTSR_TR17_SHIFT                     (17U)                                               /**< EXTI_RTSR.TR17 Position                 */
#define EXTI_RTSR_TR17(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR17_SHIFT))&EXTI_RTSR_TR17_MASK) /**< EXTI_RTSR.TR17 Field                    */
#define EXTI_RTSR_TR19_MASK                      (0x80000U)                                          /**< EXTI_RTSR.TR19 Mask                     */
#define EXTI_RTSR_TR19_SHIFT                     (19U)                                               /**< EXTI_RTSR.TR19 Position                 */
#define EXTI_RTSR_TR19(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_RTSR_TR19_SHIFT))&EXTI_RTSR_TR19_MASK) /**< EXTI_RTSR.TR19 Field                    */
/** @} */

/** @name FTSR - Falling Trigger selection register */ /** @{ */
#define EXTI_FTSR_TR0_MASK                       (0x1U)                                              /**< EXTI_FTSR.TR0 Mask                      */
#define EXTI_FTSR_TR0_SHIFT                      (0U)                                                /**< EXTI_FTSR.TR0 Position                  */
#define EXTI_FTSR_TR0(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR0_SHIFT))&EXTI_FTSR_TR0_MASK) /**< EXTI_FTSR.TR0 Field                     */
#define EXTI_FTSR_TR1_MASK                       (0x2U)                                              /**< EXTI_FTSR.TR1 Mask                      */
#define EXTI_FTSR_TR1_SHIFT                      (1U)                                                /**< EXTI_FTSR.TR1 Position                  */
#define EXTI_FTSR_TR1(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR1_SHIFT))&EXTI_FTSR_TR1_MASK) /**< EXTI_FTSR.TR1 Field                     */
#define EXTI_FTSR_TR2_MASK                       (0x4U)                                              /**< EXTI_FTSR.TR2 Mask                      */
#define EXTI_FTSR_TR2_SHIFT                      (2U)                                                /**< EXTI_FTSR.TR2 Position                  */
#define EXTI_FTSR_TR2(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR2_SHIFT))&EXTI_FTSR_TR2_MASK) /**< EXTI_FTSR.TR2 Field                     */
#define EXTI_FTSR_TR3_MASK                       (0x8U)                                              /**< EXTI_FTSR.TR3 Mask                      */
#define EXTI_FTSR_TR3_SHIFT                      (3U)                                                /**< EXTI_FTSR.TR3 Position                  */
#define EXTI_FTSR_TR3(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR3_SHIFT))&EXTI_FTSR_TR3_MASK) /**< EXTI_FTSR.TR3 Field                     */
#define EXTI_FTSR_TR4_MASK                       (0x10U)                                             /**< EXTI_FTSR.TR4 Mask                      */
#define EXTI_FTSR_TR4_SHIFT                      (4U)                                                /**< EXTI_FTSR.TR4 Position                  */
#define EXTI_FTSR_TR4(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR4_SHIFT))&EXTI_FTSR_TR4_MASK) /**< EXTI_FTSR.TR4 Field                     */
#define EXTI_FTSR_TR5_MASK                       (0x20U)                                             /**< EXTI_FTSR.TR5 Mask                      */
#define EXTI_FTSR_TR5_SHIFT                      (5U)                                                /**< EXTI_FTSR.TR5 Position                  */
#define EXTI_FTSR_TR5(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR5_SHIFT))&EXTI_FTSR_TR5_MASK) /**< EXTI_FTSR.TR5 Field                     */
#define EXTI_FTSR_TR6_MASK                       (0x40U)                                             /**< EXTI_FTSR.TR6 Mask                      */
#define EXTI_FTSR_TR6_SHIFT                      (6U)                                                /**< EXTI_FTSR.TR6 Position                  */
#define EXTI_FTSR_TR6(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR6_SHIFT))&EXTI_FTSR_TR6_MASK) /**< EXTI_FTSR.TR6 Field                     */
#define EXTI_FTSR_TR7_MASK                       (0x80U)                                             /**< EXTI_FTSR.TR7 Mask                      */
#define EXTI_FTSR_TR7_SHIFT                      (7U)                                                /**< EXTI_FTSR.TR7 Position                  */
#define EXTI_FTSR_TR7(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR7_SHIFT))&EXTI_FTSR_TR7_MASK) /**< EXTI_FTSR.TR7 Field                     */
#define EXTI_FTSR_TR8_MASK                       (0x100U)                                            /**< EXTI_FTSR.TR8 Mask                      */
#define EXTI_FTSR_TR8_SHIFT                      (8U)                                                /**< EXTI_FTSR.TR8 Position                  */
#define EXTI_FTSR_TR8(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR8_SHIFT))&EXTI_FTSR_TR8_MASK) /**< EXTI_FTSR.TR8 Field                     */
#define EXTI_FTSR_TR9_MASK                       (0x200U)                                            /**< EXTI_FTSR.TR9 Mask                      */
#define EXTI_FTSR_TR9_SHIFT                      (9U)                                                /**< EXTI_FTSR.TR9 Position                  */
#define EXTI_FTSR_TR9(x)                         (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR9_SHIFT))&EXTI_FTSR_TR9_MASK) /**< EXTI_FTSR.TR9 Field                     */
#define EXTI_FTSR_TR10_MASK                      (0x400U)                                            /**< EXTI_FTSR.TR10 Mask                     */
#define EXTI_FTSR_TR10_SHIFT                     (10U)                                               /**< EXTI_FTSR.TR10 Position                 */
#define EXTI_FTSR_TR10(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR10_SHIFT))&EXTI_FTSR_TR10_MASK) /**< EXTI_FTSR.TR10 Field                    */
#define EXTI_FTSR_TR11_MASK                      (0x800U)                                            /**< EXTI_FTSR.TR11 Mask                     */
#define EXTI_FTSR_TR11_SHIFT                     (11U)                                               /**< EXTI_FTSR.TR11 Position                 */
#define EXTI_FTSR_TR11(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR11_SHIFT))&EXTI_FTSR_TR11_MASK) /**< EXTI_FTSR.TR11 Field                    */
#define EXTI_FTSR_TR12_MASK                      (0x1000U)                                           /**< EXTI_FTSR.TR12 Mask                     */
#define EXTI_FTSR_TR12_SHIFT                     (12U)                                               /**< EXTI_FTSR.TR12 Position                 */
#define EXTI_FTSR_TR12(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR12_SHIFT))&EXTI_FTSR_TR12_MASK) /**< EXTI_FTSR.TR12 Field                    */
#define EXTI_FTSR_TR13_MASK                      (0x2000U)                                           /**< EXTI_FTSR.TR13 Mask                     */
#define EXTI_FTSR_TR13_SHIFT                     (13U)                                               /**< EXTI_FTSR.TR13 Position                 */
#define EXTI_FTSR_TR13(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR13_SHIFT))&EXTI_FTSR_TR13_MASK) /**< EXTI_FTSR.TR13 Field                    */
#define EXTI_FTSR_TR14_MASK                      (0x4000U)                                           /**< EXTI_FTSR.TR14 Mask                     */
#define EXTI_FTSR_TR14_SHIFT                     (14U)                                               /**< EXTI_FTSR.TR14 Position                 */
#define EXTI_FTSR_TR14(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR14_SHIFT))&EXTI_FTSR_TR14_MASK) /**< EXTI_FTSR.TR14 Field                    */
#define EXTI_FTSR_TR15_MASK                      (0x8000U)                                           /**< EXTI_FTSR.TR15 Mask                     */
#define EXTI_FTSR_TR15_SHIFT                     (15U)                                               /**< EXTI_FTSR.TR15 Position                 */
#define EXTI_FTSR_TR15(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR15_SHIFT))&EXTI_FTSR_TR15_MASK) /**< EXTI_FTSR.TR15 Field                    */
#define EXTI_FTSR_TR16_MASK                      (0x10000U)                                          /**< EXTI_FTSR.TR16 Mask                     */
#define EXTI_FTSR_TR16_SHIFT                     (16U)                                               /**< EXTI_FTSR.TR16 Position                 */
#define EXTI_FTSR_TR16(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR16_SHIFT))&EXTI_FTSR_TR16_MASK) /**< EXTI_FTSR.TR16 Field                    */
#define EXTI_FTSR_TR17_MASK                      (0x20000U)                                          /**< EXTI_FTSR.TR17 Mask                     */
#define EXTI_FTSR_TR17_SHIFT                     (17U)                                               /**< EXTI_FTSR.TR17 Position                 */
#define EXTI_FTSR_TR17(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR17_SHIFT))&EXTI_FTSR_TR17_MASK) /**< EXTI_FTSR.TR17 Field                    */
#define EXTI_FTSR_TR19_MASK                      (0x80000U)                                          /**< EXTI_FTSR.TR19 Mask                     */
#define EXTI_FTSR_TR19_SHIFT                     (19U)                                               /**< EXTI_FTSR.TR19 Position                 */
#define EXTI_FTSR_TR19(x)                        (((uint32_t)(((uint32_t)(x))<<EXTI_FTSR_TR19_SHIFT))&EXTI_FTSR_TR19_MASK) /**< EXTI_FTSR.TR19 Field                    */
/** @} */

/** @name SWIER - Software interrupt event register */ /** @{ */
#define EXTI_SWIER_SWIER0_MASK                   (0x1U)                                              /**< EXTI_SWIER.SWIER0 Mask                  */
#define EXTI_SWIER_SWIER0_SHIFT                  (0U)                                                /**< EXTI_SWIER.SWIER0 Position              */
#define EXTI_SWIER_SWIER0(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER0_SHIFT))&EXTI_SWIER_SWIER0_MASK) /**< EXTI_SWIER.SWIER0 Field                 */
#define EXTI_SWIER_SWIER1_MASK                   (0x2U)                                              /**< EXTI_SWIER.SWIER1 Mask                  */
#define EXTI_SWIER_SWIER1_SHIFT                  (1U)                                                /**< EXTI_SWIER.SWIER1 Position              */
#define EXTI_SWIER_SWIER1(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER1_SHIFT))&EXTI_SWIER_SWIER1_MASK) /**< EXTI_SWIER.SWIER1 Field                 */
#define EXTI_SWIER_SWIER2_MASK                   (0x4U)                                              /**< EXTI_SWIER.SWIER2 Mask                  */
#define EXTI_SWIER_SWIER2_SHIFT                  (2U)                                                /**< EXTI_SWIER.SWIER2 Position              */
#define EXTI_SWIER_SWIER2(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER2_SHIFT))&EXTI_SWIER_SWIER2_MASK) /**< EXTI_SWIER.SWIER2 Field                 */
#define EXTI_SWIER_SWIER3_MASK                   (0x8U)                                              /**< EXTI_SWIER.SWIER3 Mask                  */
#define EXTI_SWIER_SWIER3_SHIFT                  (3U)                                                /**< EXTI_SWIER.SWIER3 Position              */
#define EXTI_SWIER_SWIER3(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER3_SHIFT))&EXTI_SWIER_SWIER3_MASK) /**< EXTI_SWIER.SWIER3 Field                 */
#define EXTI_SWIER_SWIER4_MASK                   (0x10U)                                             /**< EXTI_SWIER.SWIER4 Mask                  */
#define EXTI_SWIER_SWIER4_SHIFT                  (4U)                                                /**< EXTI_SWIER.SWIER4 Position              */
#define EXTI_SWIER_SWIER4(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER4_SHIFT))&EXTI_SWIER_SWIER4_MASK) /**< EXTI_SWIER.SWIER4 Field                 */
#define EXTI_SWIER_SWIER5_MASK                   (0x20U)                                             /**< EXTI_SWIER.SWIER5 Mask                  */
#define EXTI_SWIER_SWIER5_SHIFT                  (5U)                                                /**< EXTI_SWIER.SWIER5 Position              */
#define EXTI_SWIER_SWIER5(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER5_SHIFT))&EXTI_SWIER_SWIER5_MASK) /**< EXTI_SWIER.SWIER5 Field                 */
#define EXTI_SWIER_SWIER6_MASK                   (0x40U)                                             /**< EXTI_SWIER.SWIER6 Mask                  */
#define EXTI_SWIER_SWIER6_SHIFT                  (6U)                                                /**< EXTI_SWIER.SWIER6 Position              */
#define EXTI_SWIER_SWIER6(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER6_SHIFT))&EXTI_SWIER_SWIER6_MASK) /**< EXTI_SWIER.SWIER6 Field                 */
#define EXTI_SWIER_SWIER7_MASK                   (0x80U)                                             /**< EXTI_SWIER.SWIER7 Mask                  */
#define EXTI_SWIER_SWIER7_SHIFT                  (7U)                                                /**< EXTI_SWIER.SWIER7 Position              */
#define EXTI_SWIER_SWIER7(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER7_SHIFT))&EXTI_SWIER_SWIER7_MASK) /**< EXTI_SWIER.SWIER7 Field                 */
#define EXTI_SWIER_SWIER8_MASK                   (0x100U)                                            /**< EXTI_SWIER.SWIER8 Mask                  */
#define EXTI_SWIER_SWIER8_SHIFT                  (8U)                                                /**< EXTI_SWIER.SWIER8 Position              */
#define EXTI_SWIER_SWIER8(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER8_SHIFT))&EXTI_SWIER_SWIER8_MASK) /**< EXTI_SWIER.SWIER8 Field                 */
#define EXTI_SWIER_SWIER9_MASK                   (0x200U)                                            /**< EXTI_SWIER.SWIER9 Mask                  */
#define EXTI_SWIER_SWIER9_SHIFT                  (9U)                                                /**< EXTI_SWIER.SWIER9 Position              */
#define EXTI_SWIER_SWIER9(x)                     (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER9_SHIFT))&EXTI_SWIER_SWIER9_MASK) /**< EXTI_SWIER.SWIER9 Field                 */
#define EXTI_SWIER_SWIER10_MASK                  (0x400U)                                            /**< EXTI_SWIER.SWIER10 Mask                 */
#define EXTI_SWIER_SWIER10_SHIFT                 (10U)                                               /**< EXTI_SWIER.SWIER10 Position             */
#define EXTI_SWIER_SWIER10(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER10_SHIFT))&EXTI_SWIER_SWIER10_MASK) /**< EXTI_SWIER.SWIER10 Field                */
#define EXTI_SWIER_SWIER11_MASK                  (0x800U)                                            /**< EXTI_SWIER.SWIER11 Mask                 */
#define EXTI_SWIER_SWIER11_SHIFT                 (11U)                                               /**< EXTI_SWIER.SWIER11 Position             */
#define EXTI_SWIER_SWIER11(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER11_SHIFT))&EXTI_SWIER_SWIER11_MASK) /**< EXTI_SWIER.SWIER11 Field                */
#define EXTI_SWIER_SWIER12_MASK                  (0x1000U)                                           /**< EXTI_SWIER.SWIER12 Mask                 */
#define EXTI_SWIER_SWIER12_SHIFT                 (12U)                                               /**< EXTI_SWIER.SWIER12 Position             */
#define EXTI_SWIER_SWIER12(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER12_SHIFT))&EXTI_SWIER_SWIER12_MASK) /**< EXTI_SWIER.SWIER12 Field                */
#define EXTI_SWIER_SWIER13_MASK                  (0x2000U)                                           /**< EXTI_SWIER.SWIER13 Mask                 */
#define EXTI_SWIER_SWIER13_SHIFT                 (13U)                                               /**< EXTI_SWIER.SWIER13 Position             */
#define EXTI_SWIER_SWIER13(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER13_SHIFT))&EXTI_SWIER_SWIER13_MASK) /**< EXTI_SWIER.SWIER13 Field                */
#define EXTI_SWIER_SWIER14_MASK                  (0x4000U)                                           /**< EXTI_SWIER.SWIER14 Mask                 */
#define EXTI_SWIER_SWIER14_SHIFT                 (14U)                                               /**< EXTI_SWIER.SWIER14 Position             */
#define EXTI_SWIER_SWIER14(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER14_SHIFT))&EXTI_SWIER_SWIER14_MASK) /**< EXTI_SWIER.SWIER14 Field                */
#define EXTI_SWIER_SWIER15_MASK                  (0x8000U)                                           /**< EXTI_SWIER.SWIER15 Mask                 */
#define EXTI_SWIER_SWIER15_SHIFT                 (15U)                                               /**< EXTI_SWIER.SWIER15 Position             */
#define EXTI_SWIER_SWIER15(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER15_SHIFT))&EXTI_SWIER_SWIER15_MASK) /**< EXTI_SWIER.SWIER15 Field                */
#define EXTI_SWIER_SWIER16_MASK                  (0x10000U)                                          /**< EXTI_SWIER.SWIER16 Mask                 */
#define EXTI_SWIER_SWIER16_SHIFT                 (16U)                                               /**< EXTI_SWIER.SWIER16 Position             */
#define EXTI_SWIER_SWIER16(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER16_SHIFT))&EXTI_SWIER_SWIER16_MASK) /**< EXTI_SWIER.SWIER16 Field                */
#define EXTI_SWIER_SWIER17_MASK                  (0x20000U)                                          /**< EXTI_SWIER.SWIER17 Mask                 */
#define EXTI_SWIER_SWIER17_SHIFT                 (17U)                                               /**< EXTI_SWIER.SWIER17 Position             */
#define EXTI_SWIER_SWIER17(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER17_SHIFT))&EXTI_SWIER_SWIER17_MASK) /**< EXTI_SWIER.SWIER17 Field                */
#define EXTI_SWIER_SWIER19_MASK                  (0x80000U)                                          /**< EXTI_SWIER.SWIER19 Mask                 */
#define EXTI_SWIER_SWIER19_SHIFT                 (19U)                                               /**< EXTI_SWIER.SWIER19 Position             */
#define EXTI_SWIER_SWIER19(x)                    (((uint32_t)(((uint32_t)(x))<<EXTI_SWIER_SWIER19_SHIFT))&EXTI_SWIER_SWIER19_MASK) /**< EXTI_SWIER.SWIER19 Field                */
/** @} */

/** @name PR - Pending register (EXTI_PR) */ /** @{ */
#define EXTI_PR_PR0_MASK                         (0x1U)                                              /**< EXTI_PR.PR0 Mask                        */
#define EXTI_PR_PR0_SHIFT                        (0U)                                                /**< EXTI_PR.PR0 Position                    */
#define EXTI_PR_PR0(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR0_SHIFT))&EXTI_PR_PR0_MASK) /**< EXTI_PR.PR0 Field                       */
#define EXTI_PR_PR1_MASK                         (0x2U)                                              /**< EXTI_PR.PR1 Mask                        */
#define EXTI_PR_PR1_SHIFT                        (1U)                                                /**< EXTI_PR.PR1 Position                    */
#define EXTI_PR_PR1(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR1_SHIFT))&EXTI_PR_PR1_MASK) /**< EXTI_PR.PR1 Field                       */
#define EXTI_PR_PR2_MASK                         (0x4U)                                              /**< EXTI_PR.PR2 Mask                        */
#define EXTI_PR_PR2_SHIFT                        (2U)                                                /**< EXTI_PR.PR2 Position                    */
#define EXTI_PR_PR2(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR2_SHIFT))&EXTI_PR_PR2_MASK) /**< EXTI_PR.PR2 Field                       */
#define EXTI_PR_PR3_MASK                         (0x8U)                                              /**< EXTI_PR.PR3 Mask                        */
#define EXTI_PR_PR3_SHIFT                        (3U)                                                /**< EXTI_PR.PR3 Position                    */
#define EXTI_PR_PR3(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR3_SHIFT))&EXTI_PR_PR3_MASK) /**< EXTI_PR.PR3 Field                       */
#define EXTI_PR_PR4_MASK                         (0x10U)                                             /**< EXTI_PR.PR4 Mask                        */
#define EXTI_PR_PR4_SHIFT                        (4U)                                                /**< EXTI_PR.PR4 Position                    */
#define EXTI_PR_PR4(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR4_SHIFT))&EXTI_PR_PR4_MASK) /**< EXTI_PR.PR4 Field                       */
#define EXTI_PR_PR5_MASK                         (0x20U)                                             /**< EXTI_PR.PR5 Mask                        */
#define EXTI_PR_PR5_SHIFT                        (5U)                                                /**< EXTI_PR.PR5 Position                    */
#define EXTI_PR_PR5(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR5_SHIFT))&EXTI_PR_PR5_MASK) /**< EXTI_PR.PR5 Field                       */
#define EXTI_PR_PR6_MASK                         (0x40U)                                             /**< EXTI_PR.PR6 Mask                        */
#define EXTI_PR_PR6_SHIFT                        (6U)                                                /**< EXTI_PR.PR6 Position                    */
#define EXTI_PR_PR6(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR6_SHIFT))&EXTI_PR_PR6_MASK) /**< EXTI_PR.PR6 Field                       */
#define EXTI_PR_PR7_MASK                         (0x80U)                                             /**< EXTI_PR.PR7 Mask                        */
#define EXTI_PR_PR7_SHIFT                        (7U)                                                /**< EXTI_PR.PR7 Position                    */
#define EXTI_PR_PR7(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR7_SHIFT))&EXTI_PR_PR7_MASK) /**< EXTI_PR.PR7 Field                       */
#define EXTI_PR_PR8_MASK                         (0x100U)                                            /**< EXTI_PR.PR8 Mask                        */
#define EXTI_PR_PR8_SHIFT                        (8U)                                                /**< EXTI_PR.PR8 Position                    */
#define EXTI_PR_PR8(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR8_SHIFT))&EXTI_PR_PR8_MASK) /**< EXTI_PR.PR8 Field                       */
#define EXTI_PR_PR9_MASK                         (0x200U)                                            /**< EXTI_PR.PR9 Mask                        */
#define EXTI_PR_PR9_SHIFT                        (9U)                                                /**< EXTI_PR.PR9 Position                    */
#define EXTI_PR_PR9(x)                           (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR9_SHIFT))&EXTI_PR_PR9_MASK) /**< EXTI_PR.PR9 Field                       */
#define EXTI_PR_PR10_MASK                        (0x400U)                                            /**< EXTI_PR.PR10 Mask                       */
#define EXTI_PR_PR10_SHIFT                       (10U)                                               /**< EXTI_PR.PR10 Position                   */
#define EXTI_PR_PR10(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR10_SHIFT))&EXTI_PR_PR10_MASK) /**< EXTI_PR.PR10 Field                      */
#define EXTI_PR_PR11_MASK                        (0x800U)                                            /**< EXTI_PR.PR11 Mask                       */
#define EXTI_PR_PR11_SHIFT                       (11U)                                               /**< EXTI_PR.PR11 Position                   */
#define EXTI_PR_PR11(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR11_SHIFT))&EXTI_PR_PR11_MASK) /**< EXTI_PR.PR11 Field                      */
#define EXTI_PR_PR12_MASK                        (0x1000U)                                           /**< EXTI_PR.PR12 Mask                       */
#define EXTI_PR_PR12_SHIFT                       (12U)                                               /**< EXTI_PR.PR12 Position                   */
#define EXTI_PR_PR12(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR12_SHIFT))&EXTI_PR_PR12_MASK) /**< EXTI_PR.PR12 Field                      */
#define EXTI_PR_PR13_MASK                        (0x2000U)                                           /**< EXTI_PR.PR13 Mask                       */
#define EXTI_PR_PR13_SHIFT                       (13U)                                               /**< EXTI_PR.PR13 Position                   */
#define EXTI_PR_PR13(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR13_SHIFT))&EXTI_PR_PR13_MASK) /**< EXTI_PR.PR13 Field                      */
#define EXTI_PR_PR14_MASK                        (0x4000U)                                           /**< EXTI_PR.PR14 Mask                       */
#define EXTI_PR_PR14_SHIFT                       (14U)                                               /**< EXTI_PR.PR14 Position                   */
#define EXTI_PR_PR14(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR14_SHIFT))&EXTI_PR_PR14_MASK) /**< EXTI_PR.PR14 Field                      */
#define EXTI_PR_PR15_MASK                        (0x8000U)                                           /**< EXTI_PR.PR15 Mask                       */
#define EXTI_PR_PR15_SHIFT                       (15U)                                               /**< EXTI_PR.PR15 Position                   */
#define EXTI_PR_PR15(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR15_SHIFT))&EXTI_PR_PR15_MASK) /**< EXTI_PR.PR15 Field                      */
#define EXTI_PR_PR16_MASK                        (0x10000U)                                          /**< EXTI_PR.PR16 Mask                       */
#define EXTI_PR_PR16_SHIFT                       (16U)                                               /**< EXTI_PR.PR16 Position                   */
#define EXTI_PR_PR16(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR16_SHIFT))&EXTI_PR_PR16_MASK) /**< EXTI_PR.PR16 Field                      */
#define EXTI_PR_PR17_MASK                        (0x20000U)                                          /**< EXTI_PR.PR17 Mask                       */
#define EXTI_PR_PR17_SHIFT                       (17U)                                               /**< EXTI_PR.PR17 Position                   */
#define EXTI_PR_PR17(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR17_SHIFT))&EXTI_PR_PR17_MASK) /**< EXTI_PR.PR17 Field                      */
#define EXTI_PR_PR19_MASK                        (0x80000U)                                          /**< EXTI_PR.PR19 Mask                       */
#define EXTI_PR_PR19_SHIFT                       (19U)                                               /**< EXTI_PR.PR19 Position                   */
#define EXTI_PR_PR19(x)                          (((uint32_t)(((uint32_t)(x))<<EXTI_PR_PR19_SHIFT))&EXTI_PR_PR19_MASK) /**< EXTI_PR.PR19 Field                      */
/** @} */

/** @} */ /* End group EXTI_Register_Masks_GROUP */


/* EXTI - Peripheral instance base addresses */
#define EXTI_BasePtr                   0x40010400UL //!< Peripheral base address
#define EXTI                           ((EXTI_Type *) EXTI_BasePtr) //!< Freescale base pointer
#define EXTI_BASE_PTR                  (EXTI) //!< Freescale style base pointer
#define EXTI_IRQS { TIM14_IRQn,  }


/** @} */ /* End group EXTI_Peripheral_access_layer_GROUP */


/** @brief C Struct for Flash */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup Flash_Peripheral_access_layer_GROUP Flash Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           Flash (file:Flash_STM32F030)         ================ */
/* ================================================================================ */

/**
 * @brief Flash
 */
/**
 * @struct Flash_Type
 * @brief  C Struct allowing access to Flash registers
 */
typedef struct Flash_Type {
   __IO uint32_t  ACR;                          /**< 0000: Flash access control register                                */
   __O  uint32_t  KEYR;                         /**< 0004: Flash key register                                           */
   __O  uint32_t  OPTKEYR;                      /**< 0008: Flash option key register                                    */
   __IO uint32_t  SR;                           /**< 000C: Flash status register                                        */
   __IO uint32_t  CR;                           /**< 0010: Flash control register                                       */
   __O  uint32_t  AR;                           /**< 0014: Flash address register                                       */
        uint8_t   RESERVED_0[4];                /**< 0018: 0x4 bytes                                                    */
   __I  uint32_t  OBR;                          /**< 001C: Option byte register                                         */
   __I  uint32_t  WRPR;                         /**< 0020: Write protection register                                    */
} Flash_Type;


/** @brief Register Masks for Flash */

/* -------------------------------------------------------------------------------- */
/* -----------     'Flash' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup Flash_Register_Masks_GROUP Flash Register Masks */
/** @{ */

/** @name ACR - Flash access control register */ /** @{ */
#define Flash_ACR_LATENCY_MASK                   (0x7U)                                              /**< Flash_ACR.LATENCY Mask                  */
#define Flash_ACR_LATENCY_SHIFT                  (0U)                                                /**< Flash_ACR.LATENCY Position              */
#define Flash_ACR_LATENCY(x)                     (((uint32_t)(((uint32_t)(x))<<Flash_ACR_LATENCY_SHIFT))&Flash_ACR_LATENCY_MASK) /**< Flash_ACR.LATENCY Field                 */
#define Flash_ACR_PRFTBE_MASK                    (0x10U)                                             /**< Flash_ACR.PRFTBE Mask                   */
#define Flash_ACR_PRFTBE_SHIFT                   (4U)                                                /**< Flash_ACR.PRFTBE Position               */
#define Flash_ACR_PRFTBE(x)                      (((uint32_t)(((uint32_t)(x))<<Flash_ACR_PRFTBE_SHIFT))&Flash_ACR_PRFTBE_MASK) /**< Flash_ACR.PRFTBE Field                  */
#define Flash_ACR_PRFTBS_MASK                    (0x20U)                                             /**< Flash_ACR.PRFTBS Mask                   */
#define Flash_ACR_PRFTBS_SHIFT                   (5U)                                                /**< Flash_ACR.PRFTBS Position               */
#define Flash_ACR_PRFTBS(x)                      (((uint32_t)(((uint32_t)(x))<<Flash_ACR_PRFTBS_SHIFT))&Flash_ACR_PRFTBS_MASK) /**< Flash_ACR.PRFTBS Field                  */
/** @} */

/** @name KEYR - Flash key register */ /** @{ */
#define Flash_KEYR_FKEYR_MASK                    (0xFFFFFFFFU)                                       /**< Flash_KEYR.FKEYR Mask                   */
#define Flash_KEYR_FKEYR_SHIFT                   (0U)                                                /**< Flash_KEYR.FKEYR Position               */
#define Flash_KEYR_FKEYR(x)                      (((uint32_t)(((uint32_t)(x))<<Flash_KEYR_FKEYR_SHIFT))&Flash_KEYR_FKEYR_MASK) /**< Flash_KEYR.FKEYR Field                  */
/** @} */

/** @name OPTKEYR - Flash option key register */ /** @{ */
#define Flash_OPTKEYR_OPTKEYR_MASK               (0xFFFFFFFFU)                                       /**< Flash_OPTKEYR.OPTKEYR Mask              */
#define Flash_OPTKEYR_OPTKEYR_SHIFT              (0U)                                                /**< Flash_OPTKEYR.OPTKEYR Position          */
#define Flash_OPTKEYR_OPTKEYR(x)                 (((uint32_t)(((uint32_t)(x))<<Flash_OPTKEYR_OPTKEYR_SHIFT))&Flash_OPTKEYR_OPTKEYR_MASK) /**< Flash_OPTKEYR.OPTKEYR Field             */
/** @} */

/** @name SR - Flash status register */ /** @{ */
#define Flash_SR_BSY_MASK                        (0x1U)                                              /**< Flash_SR.BSY Mask                       */
#define Flash_SR_BSY_SHIFT                       (0U)                                                /**< Flash_SR.BSY Position                   */
#define Flash_SR_BSY(x)                          (((uint32_t)(((uint32_t)(x))<<Flash_SR_BSY_SHIFT))&Flash_SR_BSY_MASK) /**< Flash_SR.BSY Field                      */
#define Flash_SR_PGERR_MASK                      (0x4U)                                              /**< Flash_SR.PGERR Mask                     */
#define Flash_SR_PGERR_SHIFT                     (2U)                                                /**< Flash_SR.PGERR Position                 */
#define Flash_SR_PGERR(x)                        (((uint32_t)(((uint32_t)(x))<<Flash_SR_PGERR_SHIFT))&Flash_SR_PGERR_MASK) /**< Flash_SR.PGERR Field                    */
#define Flash_SR_WRPRT_MASK                      (0x10U)                                             /**< Flash_SR.WRPRT Mask                     */
#define Flash_SR_WRPRT_SHIFT                     (4U)                                                /**< Flash_SR.WRPRT Position                 */
#define Flash_SR_WRPRT(x)                        (((uint32_t)(((uint32_t)(x))<<Flash_SR_WRPRT_SHIFT))&Flash_SR_WRPRT_MASK) /**< Flash_SR.WRPRT Field                    */
#define Flash_SR_EOP_MASK                        (0x20U)                                             /**< Flash_SR.EOP Mask                       */
#define Flash_SR_EOP_SHIFT                       (5U)                                                /**< Flash_SR.EOP Position                   */
#define Flash_SR_EOP(x)                          (((uint32_t)(((uint32_t)(x))<<Flash_SR_EOP_SHIFT))&Flash_SR_EOP_MASK) /**< Flash_SR.EOP Field                      */
/** @} */

/** @name CR - Flash control register */ /** @{ */
#define Flash_CR_PG_MASK                         (0x1U)                                              /**< Flash_CR.PG Mask                        */
#define Flash_CR_PG_SHIFT                        (0U)                                                /**< Flash_CR.PG Position                    */
#define Flash_CR_PG(x)                           (((uint32_t)(((uint32_t)(x))<<Flash_CR_PG_SHIFT))&Flash_CR_PG_MASK) /**< Flash_CR.PG Field                       */
#define Flash_CR_PER_MASK                        (0x2U)                                              /**< Flash_CR.PER Mask                       */
#define Flash_CR_PER_SHIFT                       (1U)                                                /**< Flash_CR.PER Position                   */
#define Flash_CR_PER(x)                          (((uint32_t)(((uint32_t)(x))<<Flash_CR_PER_SHIFT))&Flash_CR_PER_MASK) /**< Flash_CR.PER Field                      */
#define Flash_CR_MER_MASK                        (0x4U)                                              /**< Flash_CR.MER Mask                       */
#define Flash_CR_MER_SHIFT                       (2U)                                                /**< Flash_CR.MER Position                   */
#define Flash_CR_MER(x)                          (((uint32_t)(((uint32_t)(x))<<Flash_CR_MER_SHIFT))&Flash_CR_MER_MASK) /**< Flash_CR.MER Field                      */
#define Flash_CR_OPTPG_MASK                      (0x10U)                                             /**< Flash_CR.OPTPG Mask                     */
#define Flash_CR_OPTPG_SHIFT                     (4U)                                                /**< Flash_CR.OPTPG Position                 */
#define Flash_CR_OPTPG(x)                        (((uint32_t)(((uint32_t)(x))<<Flash_CR_OPTPG_SHIFT))&Flash_CR_OPTPG_MASK) /**< Flash_CR.OPTPG Field                    */
#define Flash_CR_OPTER_MASK                      (0x20U)                                             /**< Flash_CR.OPTER Mask                     */
#define Flash_CR_OPTER_SHIFT                     (5U)                                                /**< Flash_CR.OPTER Position                 */
#define Flash_CR_OPTER(x)                        (((uint32_t)(((uint32_t)(x))<<Flash_CR_OPTER_SHIFT))&Flash_CR_OPTER_MASK) /**< Flash_CR.OPTER Field                    */
#define Flash_CR_STRT_MASK                       (0x40U)                                             /**< Flash_CR.STRT Mask                      */
#define Flash_CR_STRT_SHIFT                      (6U)                                                /**< Flash_CR.STRT Position                  */
#define Flash_CR_STRT(x)                         (((uint32_t)(((uint32_t)(x))<<Flash_CR_STRT_SHIFT))&Flash_CR_STRT_MASK) /**< Flash_CR.STRT Field                     */
#define Flash_CR_LOCK_MASK                       (0x80U)                                             /**< Flash_CR.LOCK Mask                      */
#define Flash_CR_LOCK_SHIFT                      (7U)                                                /**< Flash_CR.LOCK Position                  */
#define Flash_CR_LOCK(x)                         (((uint32_t)(((uint32_t)(x))<<Flash_CR_LOCK_SHIFT))&Flash_CR_LOCK_MASK) /**< Flash_CR.LOCK Field                     */
#define Flash_CR_OPTWRE_MASK                     (0x200U)                                            /**< Flash_CR.OPTWRE Mask                    */
#define Flash_CR_OPTWRE_SHIFT                    (9U)                                                /**< Flash_CR.OPTWRE Position                */
#define Flash_CR_OPTWRE(x)                       (((uint32_t)(((uint32_t)(x))<<Flash_CR_OPTWRE_SHIFT))&Flash_CR_OPTWRE_MASK) /**< Flash_CR.OPTWRE Field                   */
#define Flash_CR_ERRIE_MASK                      (0x400U)                                            /**< Flash_CR.ERRIE Mask                     */
#define Flash_CR_ERRIE_SHIFT                     (10U)                                               /**< Flash_CR.ERRIE Position                 */
#define Flash_CR_ERRIE(x)                        (((uint32_t)(((uint32_t)(x))<<Flash_CR_ERRIE_SHIFT))&Flash_CR_ERRIE_MASK) /**< Flash_CR.ERRIE Field                    */
#define Flash_CR_EOPIE_MASK                      (0x1000U)                                           /**< Flash_CR.EOPIE Mask                     */
#define Flash_CR_EOPIE_SHIFT                     (12U)                                               /**< Flash_CR.EOPIE Position                 */
#define Flash_CR_EOPIE(x)                        (((uint32_t)(((uint32_t)(x))<<Flash_CR_EOPIE_SHIFT))&Flash_CR_EOPIE_MASK) /**< Flash_CR.EOPIE Field                    */
#define Flash_CR_FORCE_OPTLOAD_MASK              (0x2000U)                                           /**< Flash_CR.FORCE_OPTLOAD Mask             */
#define Flash_CR_FORCE_OPTLOAD_SHIFT             (13U)                                               /**< Flash_CR.FORCE_OPTLOAD Position         */
#define Flash_CR_FORCE_OPTLOAD(x)                (((uint32_t)(((uint32_t)(x))<<Flash_CR_FORCE_OPTLOAD_SHIFT))&Flash_CR_FORCE_OPTLOAD_MASK) /**< Flash_CR.FORCE_OPTLOAD Field            */
/** @} */

/** @name AR - Flash address register */ /** @{ */
#define Flash_AR_FAR_MASK                        (0xFFFFFFFFU)                                       /**< Flash_AR.FAR Mask                       */
#define Flash_AR_FAR_SHIFT                       (0U)                                                /**< Flash_AR.FAR Position                   */
#define Flash_AR_FAR(x)                          (((uint32_t)(((uint32_t)(x))<<Flash_AR_FAR_SHIFT))&Flash_AR_FAR_MASK) /**< Flash_AR.FAR Field                      */
/** @} */

/** @name OBR - Option byte register */ /** @{ */
#define Flash_OBR_OPTERR_MASK                    (0x1U)                                              /**< Flash_OBR.OPTERR Mask                   */
#define Flash_OBR_OPTERR_SHIFT                   (0U)                                                /**< Flash_OBR.OPTERR Position               */
#define Flash_OBR_OPTERR(x)                      (((uint32_t)(((uint32_t)(x))<<Flash_OBR_OPTERR_SHIFT))&Flash_OBR_OPTERR_MASK) /**< Flash_OBR.OPTERR Field                  */
#define Flash_OBR_LEVEL1_PROT_MASK               (0x2U)                                              /**< Flash_OBR.LEVEL1_PROT Mask              */
#define Flash_OBR_LEVEL1_PROT_SHIFT              (1U)                                                /**< Flash_OBR.LEVEL1_PROT Position          */
#define Flash_OBR_LEVEL1_PROT(x)                 (((uint32_t)(((uint32_t)(x))<<Flash_OBR_LEVEL1_PROT_SHIFT))&Flash_OBR_LEVEL1_PROT_MASK) /**< Flash_OBR.LEVEL1_PROT Field             */
#define Flash_OBR_LEVEL2_PROT_MASK               (0x4U)                                              /**< Flash_OBR.LEVEL2_PROT Mask              */
#define Flash_OBR_LEVEL2_PROT_SHIFT              (2U)                                                /**< Flash_OBR.LEVEL2_PROT Position          */
#define Flash_OBR_LEVEL2_PROT(x)                 (((uint32_t)(((uint32_t)(x))<<Flash_OBR_LEVEL2_PROT_SHIFT))&Flash_OBR_LEVEL2_PROT_MASK) /**< Flash_OBR.LEVEL2_PROT Field             */
#define Flash_OBR_WDG_SW_MASK                    (0x100U)                                            /**< Flash_OBR.WDG_SW Mask                   */
#define Flash_OBR_WDG_SW_SHIFT                   (8U)                                                /**< Flash_OBR.WDG_SW Position               */
#define Flash_OBR_WDG_SW(x)                      (((uint32_t)(((uint32_t)(x))<<Flash_OBR_WDG_SW_SHIFT))&Flash_OBR_WDG_SW_MASK) /**< Flash_OBR.WDG_SW Field                  */
#define Flash_OBR_nRST_STOP_MASK                 (0x200U)                                            /**< Flash_OBR.nRST_STOP Mask                */
#define Flash_OBR_nRST_STOP_SHIFT                (9U)                                                /**< Flash_OBR.nRST_STOP Position            */
#define Flash_OBR_nRST_STOP(x)                   (((uint32_t)(((uint32_t)(x))<<Flash_OBR_nRST_STOP_SHIFT))&Flash_OBR_nRST_STOP_MASK) /**< Flash_OBR.nRST_STOP Field               */
#define Flash_OBR_nRST_STDBY_MASK                (0x400U)                                            /**< Flash_OBR.nRST_STDBY Mask               */
#define Flash_OBR_nRST_STDBY_SHIFT               (10U)                                               /**< Flash_OBR.nRST_STDBY Position           */
#define Flash_OBR_nRST_STDBY(x)                  (((uint32_t)(((uint32_t)(x))<<Flash_OBR_nRST_STDBY_SHIFT))&Flash_OBR_nRST_STDBY_MASK) /**< Flash_OBR.nRST_STDBY Field              */
#define Flash_OBR_BOOT1_MASK                     (0x1000U)                                           /**< Flash_OBR.BOOT1 Mask                    */
#define Flash_OBR_BOOT1_SHIFT                    (12U)                                               /**< Flash_OBR.BOOT1 Position                */
#define Flash_OBR_BOOT1(x)                       (((uint32_t)(((uint32_t)(x))<<Flash_OBR_BOOT1_SHIFT))&Flash_OBR_BOOT1_MASK) /**< Flash_OBR.BOOT1 Field                   */
#define Flash_OBR_VDDA_MONITOR_MASK              (0x2000U)                                           /**< Flash_OBR.VDDA_MONITOR Mask             */
#define Flash_OBR_VDDA_MONITOR_SHIFT             (13U)                                               /**< Flash_OBR.VDDA_MONITOR Position         */
#define Flash_OBR_VDDA_MONITOR(x)                (((uint32_t)(((uint32_t)(x))<<Flash_OBR_VDDA_MONITOR_SHIFT))&Flash_OBR_VDDA_MONITOR_MASK) /**< Flash_OBR.VDDA_MONITOR Field            */
#define Flash_OBR_Data0_MASK                     (0xFF0000U)                                         /**< Flash_OBR.Data0 Mask                    */
#define Flash_OBR_Data0_SHIFT                    (16U)                                               /**< Flash_OBR.Data0 Position                */
#define Flash_OBR_Data0(x)                       (((uint32_t)(((uint32_t)(x))<<Flash_OBR_Data0_SHIFT))&Flash_OBR_Data0_MASK) /**< Flash_OBR.Data0 Field                   */
#define Flash_OBR_Data1_MASK                     (0xFF000000U)                                       /**< Flash_OBR.Data1 Mask                    */
#define Flash_OBR_Data1_SHIFT                    (24U)                                               /**< Flash_OBR.Data1 Position                */
#define Flash_OBR_Data1(x)                       (((uint32_t)(((uint32_t)(x))<<Flash_OBR_Data1_SHIFT))&Flash_OBR_Data1_MASK) /**< Flash_OBR.Data1 Field                   */
/** @} */

/** @name WRPR - Write protection register */ /** @{ */
#define Flash_WRPR_WRP_MASK                      (0xFFFFFFFFU)                                       /**< Flash_WRPR.WRP Mask                     */
#define Flash_WRPR_WRP_SHIFT                     (0U)                                                /**< Flash_WRPR.WRP Position                 */
#define Flash_WRPR_WRP(x)                        (((uint32_t)(((uint32_t)(x))<<Flash_WRPR_WRP_SHIFT))&Flash_WRPR_WRP_MASK) /**< Flash_WRPR.WRP Field                    */
/** @} */

/** @} */ /* End group Flash_Register_Masks_GROUP */


/* Flash - Peripheral instance base addresses */
#define Flash_BasePtr                  0x40022000UL //!< Peripheral base address
#define Flash                          ((Flash_Type *) Flash_BasePtr) //!< Freescale base pointer
#define Flash_BASE_PTR                 (Flash) //!< Freescale style base pointer
#define Flash_IRQS { USART3_4_IRQn,  }


/** @} */ /* End group Flash_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_STM32F030)         ================ */
/* ================================================================================ */

/**
 * @brief General-purpose I/Os
 */
/**
 * @struct GPIO_Type
 * @brief  C Struct allowing access to GPIO registers
 */
typedef struct GPIO_Type {
   __IO uint32_t  MODER;                        /**< 0000: GPIO port mode register                                      */
   __IO uint32_t  OTYPER;                       /**< 0004: GPIO port output type register                               */
   __IO uint32_t  OSPEEDR;                      /**< 0008: GPIO port output speed                                       */
   __IO uint32_t  PUPDR;                        /**< 000C: GPIO port pull-up/pull-down                                  */
   __I  uint32_t  IDR;                          /**< 0010: GPIO port input data register                                */
   __IO uint32_t  ODR;                          /**< 0014: GPIO port output data register                               */
   __O  uint32_t  BSRR;                         /**< 0018: GPIO port bit set/reset                                      */
   __IO uint32_t  LCKR;                         /**< 001C: GPIO port configuration lock                                 */
   __IO uint32_t  AFRL;                         /**< 0020: GPIO alternate function low                                  */
   __IO uint32_t  AFRH;                         /**< 0024: GPIO alternate function high                                 */
   __O  uint32_t  BRR;                          /**< 0028: Port bit reset register                                      */
} GPIO_Type;


/** @brief Register Masks for GPIO */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup GPIO_Register_Masks_GROUP GPIO Register Masks */
/** @{ */

/** @} */ /* End group GPIO_Register_Masks_GROUP */


/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x48000000UL //!< Peripheral base address
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
 * @brief General-purpose I/Os
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x48000400UL //!< Peripheral base address
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
 * @brief General-purpose I/Os
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x48000800UL //!< Peripheral base address
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
 * @brief General-purpose I/Os
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0x48000C00UL //!< Peripheral base address
#define GPIOD                          ((GPIO_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer

/** @} */ /* End group GPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           GPIOF (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General-purpose I/Os
 */

/* GPIOF - Peripheral instance base addresses */
#define GPIOF_BasePtr                  0x48001400UL //!< Peripheral base address
#define GPIOF                          ((GPIO_Type *) GPIOF_BasePtr) //!< Freescale base pointer
#define GPIOF_BASE_PTR                 (GPIOF) //!< Freescale style base pointer

/** @} */ /* End group GPIO_Peripheral_access_layer_GROUP */


/** @brief C Struct for I2C */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           I2C1 (file:I2C1_STM32F030)           ================ */
/* ================================================================================ */

/**
 * @brief Inter-integrated circuit
 */
/**
 * @struct I2C1_Type
 * @brief  C Struct allowing access to I2C registers
 */
typedef struct I2C1_Type {
   __IO uint32_t  CR1;                          /**< 0000: Control register 1                                           */
   __IO uint32_t  CR2;                          /**< 0004: Control register 2                                           */
   __IO uint32_t  OAR1;                         /**< 0008: Own address register 1                                       */
   __IO uint32_t  OAR2;                         /**< 000C: Own address register 2                                       */
   __IO uint32_t  TIMINGR;                      /**< 0010: Timing register                                              */
   __IO uint32_t  TIMEOUTR;                     /**< 0014: Status register 1                                            */
   __IO uint32_t  ISR;                          /**< 0018: Interrupt and Status register                                */
   __O  uint32_t  ICR;                          /**< 001C: Interrupt clear register                                     */
   __I  uint32_t  PECR;                         /**< 0020: PEC register                                                 */
   __I  uint32_t  RXDR;                         /**< 0024: Receive data register                                        */
   __IO uint32_t  TXDR;                         /**< 0028: Transmit data register                                       */
} I2C1_Type;


/** @brief Register Masks for I2C */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup I2C_Register_Masks_GROUP I2C Register Masks */
/** @{ */

/** @name CR1 - Control register 1 */ /** @{ */
#define I2C_CR1_PE_MASK                          (0x1U)                                              /**< I2C1_CR1.PE Mask                        */
#define I2C_CR1_PE_SHIFT                         (0U)                                                /**< I2C1_CR1.PE Position                    */
#define I2C_CR1_PE(x)                            (((uint32_t)(((uint32_t)(x))<<I2C_CR1_PE_SHIFT))&I2C_CR1_PE_MASK) /**< I2C1_CR1.PE Field                       */
#define I2C_CR1_TXIE_MASK                        (0x2U)                                              /**< I2C1_CR1.TXIE Mask                      */
#define I2C_CR1_TXIE_SHIFT                       (1U)                                                /**< I2C1_CR1.TXIE Position                  */
#define I2C_CR1_TXIE(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_CR1_TXIE_SHIFT))&I2C_CR1_TXIE_MASK) /**< I2C1_CR1.TXIE Field                     */
#define I2C_CR1_RXIE_MASK                        (0x4U)                                              /**< I2C1_CR1.RXIE Mask                      */
#define I2C_CR1_RXIE_SHIFT                       (2U)                                                /**< I2C1_CR1.RXIE Position                  */
#define I2C_CR1_RXIE(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_CR1_RXIE_SHIFT))&I2C_CR1_RXIE_MASK) /**< I2C1_CR1.RXIE Field                     */
#define I2C_CR1_ADDRIE_MASK                      (0x8U)                                              /**< I2C1_CR1.ADDRIE Mask                    */
#define I2C_CR1_ADDRIE_SHIFT                     (3U)                                                /**< I2C1_CR1.ADDRIE Position                */
#define I2C_CR1_ADDRIE(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR1_ADDRIE_SHIFT))&I2C_CR1_ADDRIE_MASK) /**< I2C1_CR1.ADDRIE Field                   */
#define I2C_CR1_NACKIE_MASK                      (0x10U)                                             /**< I2C1_CR1.NACKIE Mask                    */
#define I2C_CR1_NACKIE_SHIFT                     (4U)                                                /**< I2C1_CR1.NACKIE Position                */
#define I2C_CR1_NACKIE(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR1_NACKIE_SHIFT))&I2C_CR1_NACKIE_MASK) /**< I2C1_CR1.NACKIE Field                   */
#define I2C_CR1_STOPIE_MASK                      (0x20U)                                             /**< I2C1_CR1.STOPIE Mask                    */
#define I2C_CR1_STOPIE_SHIFT                     (5U)                                                /**< I2C1_CR1.STOPIE Position                */
#define I2C_CR1_STOPIE(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR1_STOPIE_SHIFT))&I2C_CR1_STOPIE_MASK) /**< I2C1_CR1.STOPIE Field                   */
#define I2C_CR1_TCIE_MASK                        (0x40U)                                             /**< I2C1_CR1.TCIE Mask                      */
#define I2C_CR1_TCIE_SHIFT                       (6U)                                                /**< I2C1_CR1.TCIE Position                  */
#define I2C_CR1_TCIE(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_CR1_TCIE_SHIFT))&I2C_CR1_TCIE_MASK) /**< I2C1_CR1.TCIE Field                     */
#define I2C_CR1_ERRIE_MASK                       (0x80U)                                             /**< I2C1_CR1.ERRIE Mask                     */
#define I2C_CR1_ERRIE_SHIFT                      (7U)                                                /**< I2C1_CR1.ERRIE Position                 */
#define I2C_CR1_ERRIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR1_ERRIE_SHIFT))&I2C_CR1_ERRIE_MASK) /**< I2C1_CR1.ERRIE Field                    */
#define I2C_CR1_DNF_MASK                         (0xF00U)                                            /**< I2C1_CR1.DNF Mask                       */
#define I2C_CR1_DNF_SHIFT                        (8U)                                                /**< I2C1_CR1.DNF Position                   */
#define I2C_CR1_DNF(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_CR1_DNF_SHIFT))&I2C_CR1_DNF_MASK) /**< I2C1_CR1.DNF Field                      */
#define I2C_CR1_ANFOFF_MASK                      (0x1000U)                                           /**< I2C1_CR1.ANFOFF Mask                    */
#define I2C_CR1_ANFOFF_SHIFT                     (12U)                                               /**< I2C1_CR1.ANFOFF Position                */
#define I2C_CR1_ANFOFF(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR1_ANFOFF_SHIFT))&I2C_CR1_ANFOFF_MASK) /**< I2C1_CR1.ANFOFF Field                   */
#define I2C_CR1_SWRST_MASK                       (0x2000U)                                           /**< I2C1_CR1.SWRST Mask                     */
#define I2C_CR1_SWRST_SHIFT                      (13U)                                               /**< I2C1_CR1.SWRST Position                 */
#define I2C_CR1_SWRST(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR1_SWRST_SHIFT))&I2C_CR1_SWRST_MASK) /**< I2C1_CR1.SWRST Field                    */
#define I2C_CR1_TXDMAEN_MASK                     (0x4000U)                                           /**< I2C1_CR1.TXDMAEN Mask                   */
#define I2C_CR1_TXDMAEN_SHIFT                    (14U)                                               /**< I2C1_CR1.TXDMAEN Position               */
#define I2C_CR1_TXDMAEN(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_CR1_TXDMAEN_SHIFT))&I2C_CR1_TXDMAEN_MASK) /**< I2C1_CR1.TXDMAEN Field                  */
#define I2C_CR1_RXDMAEN_MASK                     (0x8000U)                                           /**< I2C1_CR1.RXDMAEN Mask                   */
#define I2C_CR1_RXDMAEN_SHIFT                    (15U)                                               /**< I2C1_CR1.RXDMAEN Position               */
#define I2C_CR1_RXDMAEN(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_CR1_RXDMAEN_SHIFT))&I2C_CR1_RXDMAEN_MASK) /**< I2C1_CR1.RXDMAEN Field                  */
#define I2C_CR1_SBC_MASK                         (0x10000U)                                          /**< I2C1_CR1.SBC Mask                       */
#define I2C_CR1_SBC_SHIFT                        (16U)                                               /**< I2C1_CR1.SBC Position                   */
#define I2C_CR1_SBC(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_CR1_SBC_SHIFT))&I2C_CR1_SBC_MASK) /**< I2C1_CR1.SBC Field                      */
#define I2C_CR1_NOSTRETCH_MASK                   (0x20000U)                                          /**< I2C1_CR1.NOSTRETCH Mask                 */
#define I2C_CR1_NOSTRETCH_SHIFT                  (17U)                                               /**< I2C1_CR1.NOSTRETCH Position             */
#define I2C_CR1_NOSTRETCH(x)                     (((uint32_t)(((uint32_t)(x))<<I2C_CR1_NOSTRETCH_SHIFT))&I2C_CR1_NOSTRETCH_MASK) /**< I2C1_CR1.NOSTRETCH Field                */
#define I2C_CR1_WUPEN_MASK                       (0x40000U)                                          /**< I2C1_CR1.WUPEN Mask                     */
#define I2C_CR1_WUPEN_SHIFT                      (18U)                                               /**< I2C1_CR1.WUPEN Position                 */
#define I2C_CR1_WUPEN(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR1_WUPEN_SHIFT))&I2C_CR1_WUPEN_MASK) /**< I2C1_CR1.WUPEN Field                    */
#define I2C_CR1_GCEN_MASK                        (0x80000U)                                          /**< I2C1_CR1.GCEN Mask                      */
#define I2C_CR1_GCEN_SHIFT                       (19U)                                               /**< I2C1_CR1.GCEN Position                  */
#define I2C_CR1_GCEN(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_CR1_GCEN_SHIFT))&I2C_CR1_GCEN_MASK) /**< I2C1_CR1.GCEN Field                     */
#define I2C_CR1_SMBHEN_MASK                      (0x100000U)                                         /**< I2C1_CR1.SMBHEN Mask                    */
#define I2C_CR1_SMBHEN_SHIFT                     (20U)                                               /**< I2C1_CR1.SMBHEN Position                */
#define I2C_CR1_SMBHEN(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR1_SMBHEN_SHIFT))&I2C_CR1_SMBHEN_MASK) /**< I2C1_CR1.SMBHEN Field                   */
#define I2C_CR1_SMBDEN_MASK                      (0x200000U)                                         /**< I2C1_CR1.SMBDEN Mask                    */
#define I2C_CR1_SMBDEN_SHIFT                     (21U)                                               /**< I2C1_CR1.SMBDEN Position                */
#define I2C_CR1_SMBDEN(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR1_SMBDEN_SHIFT))&I2C_CR1_SMBDEN_MASK) /**< I2C1_CR1.SMBDEN Field                   */
#define I2C_CR1_ALERTEN_MASK                     (0x400000U)                                         /**< I2C1_CR1.ALERTEN Mask                   */
#define I2C_CR1_ALERTEN_SHIFT                    (22U)                                               /**< I2C1_CR1.ALERTEN Position               */
#define I2C_CR1_ALERTEN(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_CR1_ALERTEN_SHIFT))&I2C_CR1_ALERTEN_MASK) /**< I2C1_CR1.ALERTEN Field                  */
#define I2C_CR1_PECEN_MASK                       (0x800000U)                                         /**< I2C1_CR1.PECEN Mask                     */
#define I2C_CR1_PECEN_SHIFT                      (23U)                                               /**< I2C1_CR1.PECEN Position                 */
#define I2C_CR1_PECEN(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR1_PECEN_SHIFT))&I2C_CR1_PECEN_MASK) /**< I2C1_CR1.PECEN Field                    */
/** @} */

/** @name CR2 - Control register 2 */ /** @{ */
#define I2C_CR2_SADD0_MASK                       (0x1U)                                              /**< I2C1_CR2.SADD0 Mask                     */
#define I2C_CR2_SADD0_SHIFT                      (0U)                                                /**< I2C1_CR2.SADD0 Position                 */
#define I2C_CR2_SADD0(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR2_SADD0_SHIFT))&I2C_CR2_SADD0_MASK) /**< I2C1_CR2.SADD0 Field                    */
#define I2C_CR2_SADD1_MASK                       (0xFEU)                                             /**< I2C1_CR2.SADD1 Mask                     */
#define I2C_CR2_SADD1_SHIFT                      (1U)                                                /**< I2C1_CR2.SADD1 Position                 */
#define I2C_CR2_SADD1(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR2_SADD1_SHIFT))&I2C_CR2_SADD1_MASK) /**< I2C1_CR2.SADD1 Field                    */
#define I2C_CR2_SADD8_MASK                       (0x300U)                                            /**< I2C1_CR2.SADD8 Mask                     */
#define I2C_CR2_SADD8_SHIFT                      (8U)                                                /**< I2C1_CR2.SADD8 Position                 */
#define I2C_CR2_SADD8(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR2_SADD8_SHIFT))&I2C_CR2_SADD8_MASK) /**< I2C1_CR2.SADD8 Field                    */
#define I2C_CR2_RD_WRN_MASK                      (0x400U)                                            /**< I2C1_CR2.RD_WRN Mask                    */
#define I2C_CR2_RD_WRN_SHIFT                     (10U)                                               /**< I2C1_CR2.RD_WRN Position                */
#define I2C_CR2_RD_WRN(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR2_RD_WRN_SHIFT))&I2C_CR2_RD_WRN_MASK) /**< I2C1_CR2.RD_WRN Field                   */
#define I2C_CR2_ADD10_MASK                       (0x800U)                                            /**< I2C1_CR2.ADD10 Mask                     */
#define I2C_CR2_ADD10_SHIFT                      (11U)                                               /**< I2C1_CR2.ADD10 Position                 */
#define I2C_CR2_ADD10(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR2_ADD10_SHIFT))&I2C_CR2_ADD10_MASK) /**< I2C1_CR2.ADD10 Field                    */
#define I2C_CR2_HEAD10R_MASK                     (0x1000U)                                           /**< I2C1_CR2.HEAD10R Mask                   */
#define I2C_CR2_HEAD10R_SHIFT                    (12U)                                               /**< I2C1_CR2.HEAD10R Position               */
#define I2C_CR2_HEAD10R(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_CR2_HEAD10R_SHIFT))&I2C_CR2_HEAD10R_MASK) /**< I2C1_CR2.HEAD10R Field                  */
#define I2C_CR2_START_MASK                       (0x2000U)                                           /**< I2C1_CR2.START Mask                     */
#define I2C_CR2_START_SHIFT                      (13U)                                               /**< I2C1_CR2.START Position                 */
#define I2C_CR2_START(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CR2_START_SHIFT))&I2C_CR2_START_MASK) /**< I2C1_CR2.START Field                    */
#define I2C_CR2_STOP_MASK                        (0x4000U)                                           /**< I2C1_CR2.STOP Mask                      */
#define I2C_CR2_STOP_SHIFT                       (14U)                                               /**< I2C1_CR2.STOP Position                  */
#define I2C_CR2_STOP(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_CR2_STOP_SHIFT))&I2C_CR2_STOP_MASK) /**< I2C1_CR2.STOP Field                     */
#define I2C_CR2_NACK_MASK                        (0x8000U)                                           /**< I2C1_CR2.NACK Mask                      */
#define I2C_CR2_NACK_SHIFT                       (15U)                                               /**< I2C1_CR2.NACK Position                  */
#define I2C_CR2_NACK(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_CR2_NACK_SHIFT))&I2C_CR2_NACK_MASK) /**< I2C1_CR2.NACK Field                     */
#define I2C_CR2_NBYTES_MASK                      (0xFF0000U)                                         /**< I2C1_CR2.NBYTES Mask                    */
#define I2C_CR2_NBYTES_SHIFT                     (16U)                                               /**< I2C1_CR2.NBYTES Position                */
#define I2C_CR2_NBYTES(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR2_NBYTES_SHIFT))&I2C_CR2_NBYTES_MASK) /**< I2C1_CR2.NBYTES Field                   */
#define I2C_CR2_RELOAD_MASK                      (0x1000000U)                                        /**< I2C1_CR2.RELOAD Mask                    */
#define I2C_CR2_RELOAD_SHIFT                     (24U)                                               /**< I2C1_CR2.RELOAD Position                */
#define I2C_CR2_RELOAD(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CR2_RELOAD_SHIFT))&I2C_CR2_RELOAD_MASK) /**< I2C1_CR2.RELOAD Field                   */
#define I2C_CR2_AUTOEND_MASK                     (0x2000000U)                                        /**< I2C1_CR2.AUTOEND Mask                   */
#define I2C_CR2_AUTOEND_SHIFT                    (25U)                                               /**< I2C1_CR2.AUTOEND Position               */
#define I2C_CR2_AUTOEND(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_CR2_AUTOEND_SHIFT))&I2C_CR2_AUTOEND_MASK) /**< I2C1_CR2.AUTOEND Field                  */
#define I2C_CR2_PECBYTE_MASK                     (0x4000000U)                                        /**< I2C1_CR2.PECBYTE Mask                   */
#define I2C_CR2_PECBYTE_SHIFT                    (26U)                                               /**< I2C1_CR2.PECBYTE Position               */
#define I2C_CR2_PECBYTE(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_CR2_PECBYTE_SHIFT))&I2C_CR2_PECBYTE_MASK) /**< I2C1_CR2.PECBYTE Field                  */
/** @} */

/** @name OAR1 - Own address register 1 */ /** @{ */
#define I2C_OAR1_OA1_0_MASK                      (0x1U)                                              /**< I2C1_OAR1.OA1_0 Mask                    */
#define I2C_OAR1_OA1_0_SHIFT                     (0U)                                                /**< I2C1_OAR1.OA1_0 Position                */
#define I2C_OAR1_OA1_0(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_OAR1_OA1_0_SHIFT))&I2C_OAR1_OA1_0_MASK) /**< I2C1_OAR1.OA1_0 Field                   */
#define I2C_OAR1_OA1_1_MASK                      (0xFEU)                                             /**< I2C1_OAR1.OA1_1 Mask                    */
#define I2C_OAR1_OA1_1_SHIFT                     (1U)                                                /**< I2C1_OAR1.OA1_1 Position                */
#define I2C_OAR1_OA1_1(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_OAR1_OA1_1_SHIFT))&I2C_OAR1_OA1_1_MASK) /**< I2C1_OAR1.OA1_1 Field                   */
#define I2C_OAR1_OA1_8_MASK                      (0x300U)                                            /**< I2C1_OAR1.OA1_8 Mask                    */
#define I2C_OAR1_OA1_8_SHIFT                     (8U)                                                /**< I2C1_OAR1.OA1_8 Position                */
#define I2C_OAR1_OA1_8(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_OAR1_OA1_8_SHIFT))&I2C_OAR1_OA1_8_MASK) /**< I2C1_OAR1.OA1_8 Field                   */
#define I2C_OAR1_OA1MODE_MASK                    (0x400U)                                            /**< I2C1_OAR1.OA1MODE Mask                  */
#define I2C_OAR1_OA1MODE_SHIFT                   (10U)                                               /**< I2C1_OAR1.OA1MODE Position              */
#define I2C_OAR1_OA1MODE(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_OAR1_OA1MODE_SHIFT))&I2C_OAR1_OA1MODE_MASK) /**< I2C1_OAR1.OA1MODE Field                 */
#define I2C_OAR1_OA1EN_MASK                      (0x8000U)                                           /**< I2C1_OAR1.OA1EN Mask                    */
#define I2C_OAR1_OA1EN_SHIFT                     (15U)                                               /**< I2C1_OAR1.OA1EN Position                */
#define I2C_OAR1_OA1EN(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_OAR1_OA1EN_SHIFT))&I2C_OAR1_OA1EN_MASK) /**< I2C1_OAR1.OA1EN Field                   */
/** @} */

/** @name OAR2 - Own address register 2 */ /** @{ */
#define I2C_OAR2_OA2_MASK                        (0xFEU)                                             /**< I2C1_OAR2.OA2 Mask                      */
#define I2C_OAR2_OA2_SHIFT                       (1U)                                                /**< I2C1_OAR2.OA2 Position                  */
#define I2C_OAR2_OA2(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_OAR2_OA2_SHIFT))&I2C_OAR2_OA2_MASK) /**< I2C1_OAR2.OA2 Field                     */
#define I2C_OAR2_OA2MSK_MASK                     (0x700U)                                            /**< I2C1_OAR2.OA2MSK Mask                   */
#define I2C_OAR2_OA2MSK_SHIFT                    (8U)                                                /**< I2C1_OAR2.OA2MSK Position               */
#define I2C_OAR2_OA2MSK(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_OAR2_OA2MSK_SHIFT))&I2C_OAR2_OA2MSK_MASK) /**< I2C1_OAR2.OA2MSK Field                  */
#define I2C_OAR2_OA2EN_MASK                      (0x8000U)                                           /**< I2C1_OAR2.OA2EN Mask                    */
#define I2C_OAR2_OA2EN_SHIFT                     (15U)                                               /**< I2C1_OAR2.OA2EN Position                */
#define I2C_OAR2_OA2EN(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_OAR2_OA2EN_SHIFT))&I2C_OAR2_OA2EN_MASK) /**< I2C1_OAR2.OA2EN Field                   */
/** @} */

/** @name TIMINGR - Timing register */ /** @{ */
#define I2C_TIMINGR_SCLL_MASK                    (0xFFU)                                             /**< I2C1_TIMINGR.SCLL Mask                  */
#define I2C_TIMINGR_SCLL_SHIFT                   (0U)                                                /**< I2C1_TIMINGR.SCLL Position              */
#define I2C_TIMINGR_SCLL(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_TIMINGR_SCLL_SHIFT))&I2C_TIMINGR_SCLL_MASK) /**< I2C1_TIMINGR.SCLL Field                 */
#define I2C_TIMINGR_SCLH_MASK                    (0xFF00U)                                           /**< I2C1_TIMINGR.SCLH Mask                  */
#define I2C_TIMINGR_SCLH_SHIFT                   (8U)                                                /**< I2C1_TIMINGR.SCLH Position              */
#define I2C_TIMINGR_SCLH(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_TIMINGR_SCLH_SHIFT))&I2C_TIMINGR_SCLH_MASK) /**< I2C1_TIMINGR.SCLH Field                 */
#define I2C_TIMINGR_SDADEL_MASK                  (0xF0000U)                                          /**< I2C1_TIMINGR.SDADEL Mask                */
#define I2C_TIMINGR_SDADEL_SHIFT                 (16U)                                               /**< I2C1_TIMINGR.SDADEL Position            */
#define I2C_TIMINGR_SDADEL(x)                    (((uint32_t)(((uint32_t)(x))<<I2C_TIMINGR_SDADEL_SHIFT))&I2C_TIMINGR_SDADEL_MASK) /**< I2C1_TIMINGR.SDADEL Field               */
#define I2C_TIMINGR_SCLDEL_MASK                  (0xF00000U)                                         /**< I2C1_TIMINGR.SCLDEL Mask                */
#define I2C_TIMINGR_SCLDEL_SHIFT                 (20U)                                               /**< I2C1_TIMINGR.SCLDEL Position            */
#define I2C_TIMINGR_SCLDEL(x)                    (((uint32_t)(((uint32_t)(x))<<I2C_TIMINGR_SCLDEL_SHIFT))&I2C_TIMINGR_SCLDEL_MASK) /**< I2C1_TIMINGR.SCLDEL Field               */
#define I2C_TIMINGR_PRESC_MASK                   (0xF0000000U)                                       /**< I2C1_TIMINGR.PRESC Mask                 */
#define I2C_TIMINGR_PRESC_SHIFT                  (28U)                                               /**< I2C1_TIMINGR.PRESC Position             */
#define I2C_TIMINGR_PRESC(x)                     (((uint32_t)(((uint32_t)(x))<<I2C_TIMINGR_PRESC_SHIFT))&I2C_TIMINGR_PRESC_MASK) /**< I2C1_TIMINGR.PRESC Field                */
/** @} */

/** @name TIMEOUTR - Status register 1 */ /** @{ */
#define I2C_TIMEOUTR_TIMEOUTA_MASK               (0xFFFU)                                            /**< I2C1_TIMEOUTR.TIMEOUTA Mask             */
#define I2C_TIMEOUTR_TIMEOUTA_SHIFT              (0U)                                                /**< I2C1_TIMEOUTR.TIMEOUTA Position         */
#define I2C_TIMEOUTR_TIMEOUTA(x)                 (((uint32_t)(((uint32_t)(x))<<I2C_TIMEOUTR_TIMEOUTA_SHIFT))&I2C_TIMEOUTR_TIMEOUTA_MASK) /**< I2C1_TIMEOUTR.TIMEOUTA Field            */
#define I2C_TIMEOUTR_TIDLE_MASK                  (0x1000U)                                           /**< I2C1_TIMEOUTR.TIDLE Mask                */
#define I2C_TIMEOUTR_TIDLE_SHIFT                 (12U)                                               /**< I2C1_TIMEOUTR.TIDLE Position            */
#define I2C_TIMEOUTR_TIDLE(x)                    (((uint32_t)(((uint32_t)(x))<<I2C_TIMEOUTR_TIDLE_SHIFT))&I2C_TIMEOUTR_TIDLE_MASK) /**< I2C1_TIMEOUTR.TIDLE Field               */
#define I2C_TIMEOUTR_TIMOUTEN_MASK               (0x8000U)                                           /**< I2C1_TIMEOUTR.TIMOUTEN Mask             */
#define I2C_TIMEOUTR_TIMOUTEN_SHIFT              (15U)                                               /**< I2C1_TIMEOUTR.TIMOUTEN Position         */
#define I2C_TIMEOUTR_TIMOUTEN(x)                 (((uint32_t)(((uint32_t)(x))<<I2C_TIMEOUTR_TIMOUTEN_SHIFT))&I2C_TIMEOUTR_TIMOUTEN_MASK) /**< I2C1_TIMEOUTR.TIMOUTEN Field            */
#define I2C_TIMEOUTR_TIMEOUTB_MASK               (0xFFF0000U)                                        /**< I2C1_TIMEOUTR.TIMEOUTB Mask             */
#define I2C_TIMEOUTR_TIMEOUTB_SHIFT              (16U)                                               /**< I2C1_TIMEOUTR.TIMEOUTB Position         */
#define I2C_TIMEOUTR_TIMEOUTB(x)                 (((uint32_t)(((uint32_t)(x))<<I2C_TIMEOUTR_TIMEOUTB_SHIFT))&I2C_TIMEOUTR_TIMEOUTB_MASK) /**< I2C1_TIMEOUTR.TIMEOUTB Field            */
#define I2C_TIMEOUTR_TEXTEN_MASK                 (0x80000000U)                                       /**< I2C1_TIMEOUTR.TEXTEN Mask               */
#define I2C_TIMEOUTR_TEXTEN_SHIFT                (31U)                                               /**< I2C1_TIMEOUTR.TEXTEN Position           */
#define I2C_TIMEOUTR_TEXTEN(x)                   (((uint32_t)(((uint32_t)(x))<<I2C_TIMEOUTR_TEXTEN_SHIFT))&I2C_TIMEOUTR_TEXTEN_MASK) /**< I2C1_TIMEOUTR.TEXTEN Field              */
/** @} */

/** @name ISR - Interrupt and Status register */ /** @{ */
#define I2C_ISR_TXE_MASK                         (0x1U)                                              /**< I2C1_ISR.TXE Mask                       */
#define I2C_ISR_TXE_SHIFT                        (0U)                                                /**< I2C1_ISR.TXE Position                   */
#define I2C_ISR_TXE(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_ISR_TXE_SHIFT))&I2C_ISR_TXE_MASK) /**< I2C1_ISR.TXE Field                      */
#define I2C_ISR_TXIS_MASK                        (0x2U)                                              /**< I2C1_ISR.TXIS Mask                      */
#define I2C_ISR_TXIS_SHIFT                       (1U)                                                /**< I2C1_ISR.TXIS Position                  */
#define I2C_ISR_TXIS(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_ISR_TXIS_SHIFT))&I2C_ISR_TXIS_MASK) /**< I2C1_ISR.TXIS Field                     */
#define I2C_ISR_RXNE_MASK                        (0x4U)                                              /**< I2C1_ISR.RXNE Mask                      */
#define I2C_ISR_RXNE_SHIFT                       (2U)                                                /**< I2C1_ISR.RXNE Position                  */
#define I2C_ISR_RXNE(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_ISR_RXNE_SHIFT))&I2C_ISR_RXNE_MASK) /**< I2C1_ISR.RXNE Field                     */
#define I2C_ISR_ADDR_MASK                        (0x8U)                                              /**< I2C1_ISR.ADDR Mask                      */
#define I2C_ISR_ADDR_SHIFT                       (3U)                                                /**< I2C1_ISR.ADDR Position                  */
#define I2C_ISR_ADDR(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_ISR_ADDR_SHIFT))&I2C_ISR_ADDR_MASK) /**< I2C1_ISR.ADDR Field                     */
#define I2C_ISR_NACKF_MASK                       (0x10U)                                             /**< I2C1_ISR.NACKF Mask                     */
#define I2C_ISR_NACKF_SHIFT                      (4U)                                                /**< I2C1_ISR.NACKF Position                 */
#define I2C_ISR_NACKF(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_ISR_NACKF_SHIFT))&I2C_ISR_NACKF_MASK) /**< I2C1_ISR.NACKF Field                    */
#define I2C_ISR_STOPF_MASK                       (0x20U)                                             /**< I2C1_ISR.STOPF Mask                     */
#define I2C_ISR_STOPF_SHIFT                      (5U)                                                /**< I2C1_ISR.STOPF Position                 */
#define I2C_ISR_STOPF(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_ISR_STOPF_SHIFT))&I2C_ISR_STOPF_MASK) /**< I2C1_ISR.STOPF Field                    */
#define I2C_ISR_TC_MASK                          (0x40U)                                             /**< I2C1_ISR.TC Mask                        */
#define I2C_ISR_TC_SHIFT                         (6U)                                                /**< I2C1_ISR.TC Position                    */
#define I2C_ISR_TC(x)                            (((uint32_t)(((uint32_t)(x))<<I2C_ISR_TC_SHIFT))&I2C_ISR_TC_MASK) /**< I2C1_ISR.TC Field                       */
#define I2C_ISR_TCR_MASK                         (0x80U)                                             /**< I2C1_ISR.TCR Mask                       */
#define I2C_ISR_TCR_SHIFT                        (7U)                                                /**< I2C1_ISR.TCR Position                   */
#define I2C_ISR_TCR(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_ISR_TCR_SHIFT))&I2C_ISR_TCR_MASK) /**< I2C1_ISR.TCR Field                      */
#define I2C_ISR_BERR_MASK                        (0x100U)                                            /**< I2C1_ISR.BERR Mask                      */
#define I2C_ISR_BERR_SHIFT                       (8U)                                                /**< I2C1_ISR.BERR Position                  */
#define I2C_ISR_BERR(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_ISR_BERR_SHIFT))&I2C_ISR_BERR_MASK) /**< I2C1_ISR.BERR Field                     */
#define I2C_ISR_ARLO_MASK                        (0x200U)                                            /**< I2C1_ISR.ARLO Mask                      */
#define I2C_ISR_ARLO_SHIFT                       (9U)                                                /**< I2C1_ISR.ARLO Position                  */
#define I2C_ISR_ARLO(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_ISR_ARLO_SHIFT))&I2C_ISR_ARLO_MASK) /**< I2C1_ISR.ARLO Field                     */
#define I2C_ISR_OVR_MASK                         (0x400U)                                            /**< I2C1_ISR.OVR Mask                       */
#define I2C_ISR_OVR_SHIFT                        (10U)                                               /**< I2C1_ISR.OVR Position                   */
#define I2C_ISR_OVR(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_ISR_OVR_SHIFT))&I2C_ISR_OVR_MASK) /**< I2C1_ISR.OVR Field                      */
#define I2C_ISR_PECERR_MASK                      (0x800U)                                            /**< I2C1_ISR.PECERR Mask                    */
#define I2C_ISR_PECERR_SHIFT                     (11U)                                               /**< I2C1_ISR.PECERR Position                */
#define I2C_ISR_PECERR(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_ISR_PECERR_SHIFT))&I2C_ISR_PECERR_MASK) /**< I2C1_ISR.PECERR Field                   */
#define I2C_ISR_TIMEOUT_MASK                     (0x1000U)                                           /**< I2C1_ISR.TIMEOUT Mask                   */
#define I2C_ISR_TIMEOUT_SHIFT                    (12U)                                               /**< I2C1_ISR.TIMEOUT Position               */
#define I2C_ISR_TIMEOUT(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_ISR_TIMEOUT_SHIFT))&I2C_ISR_TIMEOUT_MASK) /**< I2C1_ISR.TIMEOUT Field                  */
#define I2C_ISR_ALERT_MASK                       (0x2000U)                                           /**< I2C1_ISR.ALERT Mask                     */
#define I2C_ISR_ALERT_SHIFT                      (13U)                                               /**< I2C1_ISR.ALERT Position                 */
#define I2C_ISR_ALERT(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_ISR_ALERT_SHIFT))&I2C_ISR_ALERT_MASK) /**< I2C1_ISR.ALERT Field                    */
#define I2C_ISR_BUSY_MASK                        (0x8000U)                                           /**< I2C1_ISR.BUSY Mask                      */
#define I2C_ISR_BUSY_SHIFT                       (15U)                                               /**< I2C1_ISR.BUSY Position                  */
#define I2C_ISR_BUSY(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_ISR_BUSY_SHIFT))&I2C_ISR_BUSY_MASK) /**< I2C1_ISR.BUSY Field                     */
#define I2C_ISR_DIR_MASK                         (0x10000U)                                          /**< I2C1_ISR.DIR Mask                       */
#define I2C_ISR_DIR_SHIFT                        (16U)                                               /**< I2C1_ISR.DIR Position                   */
#define I2C_ISR_DIR(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_ISR_DIR_SHIFT))&I2C_ISR_DIR_MASK) /**< I2C1_ISR.DIR Field                      */
#define I2C_ISR_ADDCODE_MASK                     (0xFE0000U)                                         /**< I2C1_ISR.ADDCODE Mask                   */
#define I2C_ISR_ADDCODE_SHIFT                    (17U)                                               /**< I2C1_ISR.ADDCODE Position               */
#define I2C_ISR_ADDCODE(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_ISR_ADDCODE_SHIFT))&I2C_ISR_ADDCODE_MASK) /**< I2C1_ISR.ADDCODE Field                  */
/** @} */

/** @name ICR - Interrupt clear register */ /** @{ */
#define I2C_ICR_ADDRCF_MASK                      (0x8U)                                              /**< I2C1_ICR.ADDRCF Mask                    */
#define I2C_ICR_ADDRCF_SHIFT                     (3U)                                                /**< I2C1_ICR.ADDRCF Position                */
#define I2C_ICR_ADDRCF(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_ICR_ADDRCF_SHIFT))&I2C_ICR_ADDRCF_MASK) /**< I2C1_ICR.ADDRCF Field                   */
#define I2C_ICR_NACKCF_MASK                      (0x10U)                                             /**< I2C1_ICR.NACKCF Mask                    */
#define I2C_ICR_NACKCF_SHIFT                     (4U)                                                /**< I2C1_ICR.NACKCF Position                */
#define I2C_ICR_NACKCF(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_ICR_NACKCF_SHIFT))&I2C_ICR_NACKCF_MASK) /**< I2C1_ICR.NACKCF Field                   */
#define I2C_ICR_STOPCF_MASK                      (0x20U)                                             /**< I2C1_ICR.STOPCF Mask                    */
#define I2C_ICR_STOPCF_SHIFT                     (5U)                                                /**< I2C1_ICR.STOPCF Position                */
#define I2C_ICR_STOPCF(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_ICR_STOPCF_SHIFT))&I2C_ICR_STOPCF_MASK) /**< I2C1_ICR.STOPCF Field                   */
#define I2C_ICR_BERRCF_MASK                      (0x100U)                                            /**< I2C1_ICR.BERRCF Mask                    */
#define I2C_ICR_BERRCF_SHIFT                     (8U)                                                /**< I2C1_ICR.BERRCF Position                */
#define I2C_ICR_BERRCF(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_ICR_BERRCF_SHIFT))&I2C_ICR_BERRCF_MASK) /**< I2C1_ICR.BERRCF Field                   */
#define I2C_ICR_ARLOCF_MASK                      (0x200U)                                            /**< I2C1_ICR.ARLOCF Mask                    */
#define I2C_ICR_ARLOCF_SHIFT                     (9U)                                                /**< I2C1_ICR.ARLOCF Position                */
#define I2C_ICR_ARLOCF(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_ICR_ARLOCF_SHIFT))&I2C_ICR_ARLOCF_MASK) /**< I2C1_ICR.ARLOCF Field                   */
#define I2C_ICR_OVRCF_MASK                       (0x400U)                                            /**< I2C1_ICR.OVRCF Mask                     */
#define I2C_ICR_OVRCF_SHIFT                      (10U)                                               /**< I2C1_ICR.OVRCF Position                 */
#define I2C_ICR_OVRCF(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_ICR_OVRCF_SHIFT))&I2C_ICR_OVRCF_MASK) /**< I2C1_ICR.OVRCF Field                    */
#define I2C_ICR_PECCF_MASK                       (0x800U)                                            /**< I2C1_ICR.PECCF Mask                     */
#define I2C_ICR_PECCF_SHIFT                      (11U)                                               /**< I2C1_ICR.PECCF Position                 */
#define I2C_ICR_PECCF(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_ICR_PECCF_SHIFT))&I2C_ICR_PECCF_MASK) /**< I2C1_ICR.PECCF Field                    */
#define I2C_ICR_TIMOUTCF_MASK                    (0x1000U)                                           /**< I2C1_ICR.TIMOUTCF Mask                  */
#define I2C_ICR_TIMOUTCF_SHIFT                   (12U)                                               /**< I2C1_ICR.TIMOUTCF Position              */
#define I2C_ICR_TIMOUTCF(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_ICR_TIMOUTCF_SHIFT))&I2C_ICR_TIMOUTCF_MASK) /**< I2C1_ICR.TIMOUTCF Field                 */
#define I2C_ICR_ALERTCF_MASK                     (0x2000U)                                           /**< I2C1_ICR.ALERTCF Mask                   */
#define I2C_ICR_ALERTCF_SHIFT                    (13U)                                               /**< I2C1_ICR.ALERTCF Position               */
#define I2C_ICR_ALERTCF(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_ICR_ALERTCF_SHIFT))&I2C_ICR_ALERTCF_MASK) /**< I2C1_ICR.ALERTCF Field                  */
/** @} */

/** @name PECR - PEC register */ /** @{ */
#define I2C_PECR_PEC_MASK                        (0xFFU)                                             /**< I2C1_PECR.PEC Mask                      */
#define I2C_PECR_PEC_SHIFT                       (0U)                                                /**< I2C1_PECR.PEC Position                  */
#define I2C_PECR_PEC(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_PECR_PEC_SHIFT))&I2C_PECR_PEC_MASK) /**< I2C1_PECR.PEC Field                     */
/** @} */

/** @name RXDR - Receive data register */ /** @{ */
#define I2C_RXDR_RXDATA_MASK                     (0xFFU)                                             /**< I2C1_RXDR.RXDATA Mask                   */
#define I2C_RXDR_RXDATA_SHIFT                    (0U)                                                /**< I2C1_RXDR.RXDATA Position               */
#define I2C_RXDR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_RXDR_RXDATA_SHIFT))&I2C_RXDR_RXDATA_MASK) /**< I2C1_RXDR.RXDATA Field                  */
/** @} */

/** @name TXDR - Transmit data register */ /** @{ */
#define I2C_TXDR_TXDATA_MASK                     (0xFFU)                                             /**< I2C1_TXDR.TXDATA Mask                   */
#define I2C_TXDR_TXDATA_SHIFT                    (0U)                                                /**< I2C1_TXDR.TXDATA Position               */
#define I2C_TXDR_TXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_TXDR_TXDATA_SHIFT))&I2C_TXDR_TXDATA_MASK) /**< I2C1_TXDR.TXDATA Field                  */
/** @} */

/** @} */ /* End group I2C_Register_Masks_GROUP */


/* I2C1 - Peripheral instance base addresses */
#define I2C1_BasePtr                   0x40005400UL //!< Peripheral base address
#define I2C1                           ((I2C1_Type *) I2C1_BasePtr) //!< Freescale base pointer
#define I2C1_BASE_PTR                  (I2C1) //!< Freescale style base pointer

/** @} */ /* End group I2C_Peripheral_access_layer_GROUP */


/** @brief C Struct for I2C */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           I2C2 (derived from I2C1)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-integrated circuit
 */

/* I2C2 - Peripheral instance base addresses */
#define I2C2_BasePtr                   0x40005800UL //!< Peripheral base address
#define I2C2                           ((I2C1_Type *) I2C2_BasePtr) //!< Freescale base pointer
#define I2C2_BASE_PTR                  (I2C2) //!< Freescale style base pointer
#define I2C2_IRQS { I2C1_IRQn,  }


/** @} */ /* End group I2C_Peripheral_access_layer_GROUP */


/** @brief C Struct for IWDG */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup IWDG_Peripheral_access_layer_GROUP IWDG Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           IWDG (file:IWDG_STM32F030)           ================ */
/* ================================================================================ */

/**
 * @brief Independent watchdog
 */
/**
 * @struct IWDG_Type
 * @brief  C Struct allowing access to IWDG registers
 */
typedef struct IWDG_Type {
   __O  uint32_t  KR;                           /**< 0000: Key register                                                 */
   __IO uint32_t  PR;                           /**< 0004: Prescaler register                                           */
   __IO uint32_t  RLR;                          /**< 0008: Reload register                                              */
   __I  uint32_t  SR;                           /**< 000C: Status register                                              */
   __IO uint32_t  WINR;                         /**< 0010: Window register                                              */
} IWDG_Type;


/** @brief Register Masks for IWDG */

/* -------------------------------------------------------------------------------- */
/* -----------     'IWDG' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup IWDG_Register_Masks_GROUP IWDG Register Masks */
/** @{ */

/** @name KR - Key register */ /** @{ */
#define IWDG_KR_KEY_MASK                         (0xFFFFU)                                           /**< IWDG_KR.KEY Mask                        */
#define IWDG_KR_KEY_SHIFT                        (0U)                                                /**< IWDG_KR.KEY Position                    */
#define IWDG_KR_KEY(x)                           (((uint32_t)(((uint32_t)(x))<<IWDG_KR_KEY_SHIFT))&IWDG_KR_KEY_MASK) /**< IWDG_KR.KEY Field                       */
/** @} */

/** @name PR - Prescaler register */ /** @{ */
#define IWDG_PR_PR_MASK                          (0x7U)                                              /**< IWDG_PR.PR Mask                         */
#define IWDG_PR_PR_SHIFT                         (0U)                                                /**< IWDG_PR.PR Position                     */
#define IWDG_PR_PR(x)                            (((uint32_t)(((uint32_t)(x))<<IWDG_PR_PR_SHIFT))&IWDG_PR_PR_MASK) /**< IWDG_PR.PR Field                        */
/** @} */

/** @name RLR - Reload register */ /** @{ */
#define IWDG_RLR_RL_MASK                         (0xFFFU)                                            /**< IWDG_RLR.RL Mask                        */
#define IWDG_RLR_RL_SHIFT                        (0U)                                                /**< IWDG_RLR.RL Position                    */
#define IWDG_RLR_RL(x)                           (((uint32_t)(((uint32_t)(x))<<IWDG_RLR_RL_SHIFT))&IWDG_RLR_RL_MASK) /**< IWDG_RLR.RL Field                       */
/** @} */

/** @name SR - Status register */ /** @{ */
#define IWDG_SR_PVU_MASK                         (0x1U)                                              /**< IWDG_SR.PVU Mask                        */
#define IWDG_SR_PVU_SHIFT                        (0U)                                                /**< IWDG_SR.PVU Position                    */
#define IWDG_SR_PVU(x)                           (((uint32_t)(((uint32_t)(x))<<IWDG_SR_PVU_SHIFT))&IWDG_SR_PVU_MASK) /**< IWDG_SR.PVU Field                       */
#define IWDG_SR_RVU_MASK                         (0x2U)                                              /**< IWDG_SR.RVU Mask                        */
#define IWDG_SR_RVU_SHIFT                        (1U)                                                /**< IWDG_SR.RVU Position                    */
#define IWDG_SR_RVU(x)                           (((uint32_t)(((uint32_t)(x))<<IWDG_SR_RVU_SHIFT))&IWDG_SR_RVU_MASK) /**< IWDG_SR.RVU Field                       */
#define IWDG_SR_WVU_MASK                         (0x4U)                                              /**< IWDG_SR.WVU Mask                        */
#define IWDG_SR_WVU_SHIFT                        (2U)                                                /**< IWDG_SR.WVU Position                    */
#define IWDG_SR_WVU(x)                           (((uint32_t)(((uint32_t)(x))<<IWDG_SR_WVU_SHIFT))&IWDG_SR_WVU_MASK) /**< IWDG_SR.WVU Field                       */
/** @} */

/** @name WINR - Window register */ /** @{ */
#define IWDG_WINR_WIN_MASK                       (0xFFFU)                                            /**< IWDG_WINR.WIN Mask                      */
#define IWDG_WINR_WIN_SHIFT                      (0U)                                                /**< IWDG_WINR.WIN Position                  */
#define IWDG_WINR_WIN(x)                         (((uint32_t)(((uint32_t)(x))<<IWDG_WINR_WIN_SHIFT))&IWDG_WINR_WIN_MASK) /**< IWDG_WINR.WIN Field                     */
/** @} */

/** @} */ /* End group IWDG_Register_Masks_GROUP */


/* IWDG - Peripheral instance base addresses */
#define IWDG_BasePtr                   0x40003000UL //!< Peripheral base address
#define IWDG                           ((IWDG_Type *) IWDG_BasePtr) //!< Freescale base pointer
#define IWDG_BASE_PTR                  (IWDG) //!< Freescale style base pointer
#define IWDG_IRQS { I2C2_IRQn,  }


/** @} */ /* End group IWDG_Peripheral_access_layer_GROUP */


/** @brief C Struct for PWR */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PWR_Peripheral_access_layer_GROUP PWR Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           PWR (file:PWR_STM32F030)             ================ */
/* ================================================================================ */

/**
 * @brief Power control
 */
/**
 * @struct PWR_Type
 * @brief  C Struct allowing access to PWR registers
 */
typedef struct PWR_Type {
   __IO uint32_t  CR;                           /**< 0000: power control register                                       */
   __IO uint32_t  CSR;                          /**< 0004: power control/status register                                */
} PWR_Type;


/** @brief Register Masks for PWR */

/* -------------------------------------------------------------------------------- */
/* -----------     'PWR' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup PWR_Register_Masks_GROUP PWR Register Masks */
/** @{ */

/** @name CR - power control register */ /** @{ */
#define PWR_CR_LPDS_MASK                         (0x1U)                                              /**< PWR_CR.LPDS Mask                        */
#define PWR_CR_LPDS_SHIFT                        (0U)                                                /**< PWR_CR.LPDS Position                    */
#define PWR_CR_LPDS(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CR_LPDS_SHIFT))&PWR_CR_LPDS_MASK) /**< PWR_CR.LPDS Field                       */
#define PWR_CR_PDDS_MASK                         (0x2U)                                              /**< PWR_CR.PDDS Mask                        */
#define PWR_CR_PDDS_SHIFT                        (1U)                                                /**< PWR_CR.PDDS Position                    */
#define PWR_CR_PDDS(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CR_PDDS_SHIFT))&PWR_CR_PDDS_MASK) /**< PWR_CR.PDDS Field                       */
#define PWR_CR_CWUF_MASK                         (0x4U)                                              /**< PWR_CR.CWUF Mask                        */
#define PWR_CR_CWUF_SHIFT                        (2U)                                                /**< PWR_CR.CWUF Position                    */
#define PWR_CR_CWUF(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CR_CWUF_SHIFT))&PWR_CR_CWUF_MASK) /**< PWR_CR.CWUF Field                       */
#define PWR_CR_CSBF_MASK                         (0x8U)                                              /**< PWR_CR.CSBF Mask                        */
#define PWR_CR_CSBF_SHIFT                        (3U)                                                /**< PWR_CR.CSBF Position                    */
#define PWR_CR_CSBF(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CR_CSBF_SHIFT))&PWR_CR_CSBF_MASK) /**< PWR_CR.CSBF Field                       */
#define PWR_CR_PVDE_MASK                         (0x10U)                                             /**< PWR_CR.PVDE Mask                        */
#define PWR_CR_PVDE_SHIFT                        (4U)                                                /**< PWR_CR.PVDE Position                    */
#define PWR_CR_PVDE(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CR_PVDE_SHIFT))&PWR_CR_PVDE_MASK) /**< PWR_CR.PVDE Field                       */
#define PWR_CR_PLS_MASK                          (0xE0U)                                             /**< PWR_CR.PLS Mask                         */
#define PWR_CR_PLS_SHIFT                         (5U)                                                /**< PWR_CR.PLS Position                     */
#define PWR_CR_PLS(x)                            (((uint32_t)(((uint32_t)(x))<<PWR_CR_PLS_SHIFT))&PWR_CR_PLS_MASK) /**< PWR_CR.PLS Field                        */
#define PWR_CR_DBP_MASK                          (0x100U)                                            /**< PWR_CR.DBP Mask                         */
#define PWR_CR_DBP_SHIFT                         (8U)                                                /**< PWR_CR.DBP Position                     */
#define PWR_CR_DBP(x)                            (((uint32_t)(((uint32_t)(x))<<PWR_CR_DBP_SHIFT))&PWR_CR_DBP_MASK) /**< PWR_CR.DBP Field                        */
#define PWR_CR_FPDS_MASK                         (0x200U)                                            /**< PWR_CR.FPDS Mask                        */
#define PWR_CR_FPDS_SHIFT                        (9U)                                                /**< PWR_CR.FPDS Position                    */
#define PWR_CR_FPDS(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CR_FPDS_SHIFT))&PWR_CR_FPDS_MASK) /**< PWR_CR.FPDS Field                       */
/** @} */

/** @name CSR - power control/status register */ /** @{ */
#define PWR_CSR_WUF_MASK                         (0x1U)                                              /**< PWR_CSR.WUF Mask                        */
#define PWR_CSR_WUF_SHIFT                        (0U)                                                /**< PWR_CSR.WUF Position                    */
#define PWR_CSR_WUF(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CSR_WUF_SHIFT))&PWR_CSR_WUF_MASK) /**< PWR_CSR.WUF Field                       */
#define PWR_CSR_SBF_MASK                         (0x2U)                                              /**< PWR_CSR.SBF Mask                        */
#define PWR_CSR_SBF_SHIFT                        (1U)                                                /**< PWR_CSR.SBF Position                    */
#define PWR_CSR_SBF(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CSR_SBF_SHIFT))&PWR_CSR_SBF_MASK) /**< PWR_CSR.SBF Field                       */
#define PWR_CSR_PVDO_MASK                        (0x4U)                                              /**< PWR_CSR.PVDO Mask                       */
#define PWR_CSR_PVDO_SHIFT                       (2U)                                                /**< PWR_CSR.PVDO Position                   */
#define PWR_CSR_PVDO(x)                          (((uint32_t)(((uint32_t)(x))<<PWR_CSR_PVDO_SHIFT))&PWR_CSR_PVDO_MASK) /**< PWR_CSR.PVDO Field                      */
#define PWR_CSR_BRR_MASK                         (0x8U)                                              /**< PWR_CSR.BRR Mask                        */
#define PWR_CSR_BRR_SHIFT                        (3U)                                                /**< PWR_CSR.BRR Position                    */
#define PWR_CSR_BRR(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CSR_BRR_SHIFT))&PWR_CSR_BRR_MASK) /**< PWR_CSR.BRR Field                       */
#define PWR_CSR_EWUP_MASK                        (0x100U)                                            /**< PWR_CSR.EWUP Mask                       */
#define PWR_CSR_EWUP_SHIFT                       (8U)                                                /**< PWR_CSR.EWUP Position                   */
#define PWR_CSR_EWUP(x)                          (((uint32_t)(((uint32_t)(x))<<PWR_CSR_EWUP_SHIFT))&PWR_CSR_EWUP_MASK) /**< PWR_CSR.EWUP Field                      */
#define PWR_CSR_BRE_MASK                         (0x200U)                                            /**< PWR_CSR.BRE Mask                        */
#define PWR_CSR_BRE_SHIFT                        (9U)                                                /**< PWR_CSR.BRE Position                    */
#define PWR_CSR_BRE(x)                           (((uint32_t)(((uint32_t)(x))<<PWR_CSR_BRE_SHIFT))&PWR_CSR_BRE_MASK) /**< PWR_CSR.BRE Field                       */
/** @} */

/** @} */ /* End group PWR_Register_Masks_GROUP */


/* PWR - Peripheral instance base addresses */
#define PWR_BasePtr                    0x40007000UL //!< Peripheral base address
#define PWR                            ((PWR_Type *) PWR_BasePtr) //!< Freescale base pointer
#define PWR_BASE_PTR                   (PWR) //!< Freescale style base pointer
#define PWR_IRQS { TIM6_DAC_IRQn,  }


/** @} */ /* End group PWR_Peripheral_access_layer_GROUP */


/** @brief C Struct for RCC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup RCC_Peripheral_access_layer_GROUP RCC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           RCC (file:RCC_STM32F030)             ================ */
/* ================================================================================ */

/**
 * @brief Reset and clock control
 */
/**
 * @struct RCC_Type
 * @brief  C Struct allowing access to RCC registers
 */
typedef struct RCC_Type {
   __IO uint32_t  CR;                           /**< 0000: Clock control register                                       */
   __IO uint32_t  CFGR;                         /**< 0004: Clock configuration register                                 */
   __IO uint32_t  CIR;                          /**< 0008: Clock interrupt register                                     */
   __IO uint32_t  APB2RSTR;                     /**< 000C: APB2 peripheral reset register                               */
   __IO uint32_t  APB1RSTR;                     /**< 0010: APB1 peripheral reset register                               */
   __IO uint32_t  AHBENR;                       /**< 0014: AHB Peripheral Clock enable register                         */
   __IO uint32_t  APB2ENR;                      /**< 0018: APB2 peripheral clock enable register                        */
   __IO uint32_t  APB1ENR;                      /**< 001C: APB1 peripheral clock enable register                        */
   __IO uint32_t  BDCR;                         /**< 0020: Backup domain control register                               */
   __IO uint32_t  CSR;                          /**< 0024: Control/status register                                      */
   __IO uint32_t  AHBRSTR;                      /**< 0028: AHB peripheral reset register                                */
   __IO uint32_t  CFGR2;                        /**< 002C: Clock configuration register 2                               */
   __IO uint32_t  CFGR3;                        /**< 0030: Clock configuration register 3                               */
   __IO uint32_t  CR2;                          /**< 0034: Clock control register 2                                     */
} RCC_Type;


/** @brief Register Masks for RCC */

/* -------------------------------------------------------------------------------- */
/* -----------     'RCC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup RCC_Register_Masks_GROUP RCC Register Masks */
/** @{ */

/** @name CR - Clock control register */ /** @{ */
#define RCC_CR_HSION_MASK                        (0x1U)                                              /**< RCC_CR.HSION Mask                       */
#define RCC_CR_HSION_SHIFT                       (0U)                                                /**< RCC_CR.HSION Position                   */
#define RCC_CR_HSION(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CR_HSION_SHIFT))&RCC_CR_HSION_MASK) /**< RCC_CR.HSION Field                      */
#define RCC_CR_HSIRDY_MASK                       (0x2U)                                              /**< RCC_CR.HSIRDY Mask                      */
#define RCC_CR_HSIRDY_SHIFT                      (1U)                                                /**< RCC_CR.HSIRDY Position                  */
#define RCC_CR_HSIRDY(x)                         (((uint32_t)(((uint32_t)(x))<<RCC_CR_HSIRDY_SHIFT))&RCC_CR_HSIRDY_MASK) /**< RCC_CR.HSIRDY Field                     */
#define RCC_CR_HSITRIM_MASK                      (0xF8U)                                             /**< RCC_CR.HSITRIM Mask                     */
#define RCC_CR_HSITRIM_SHIFT                     (3U)                                                /**< RCC_CR.HSITRIM Position                 */
#define RCC_CR_HSITRIM(x)                        (((uint32_t)(((uint32_t)(x))<<RCC_CR_HSITRIM_SHIFT))&RCC_CR_HSITRIM_MASK) /**< RCC_CR.HSITRIM Field                    */
#define RCC_CR_HSICAL_MASK                       (0xFF00U)                                           /**< RCC_CR.HSICAL Mask                      */
#define RCC_CR_HSICAL_SHIFT                      (8U)                                                /**< RCC_CR.HSICAL Position                  */
#define RCC_CR_HSICAL(x)                         (((uint32_t)(((uint32_t)(x))<<RCC_CR_HSICAL_SHIFT))&RCC_CR_HSICAL_MASK) /**< RCC_CR.HSICAL Field                     */
#define RCC_CR_HSEON_MASK                        (0x10000U)                                          /**< RCC_CR.HSEON Mask                       */
#define RCC_CR_HSEON_SHIFT                       (16U)                                               /**< RCC_CR.HSEON Position                   */
#define RCC_CR_HSEON(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CR_HSEON_SHIFT))&RCC_CR_HSEON_MASK) /**< RCC_CR.HSEON Field                      */
#define RCC_CR_HSERDY_MASK                       (0x20000U)                                          /**< RCC_CR.HSERDY Mask                      */
#define RCC_CR_HSERDY_SHIFT                      (17U)                                               /**< RCC_CR.HSERDY Position                  */
#define RCC_CR_HSERDY(x)                         (((uint32_t)(((uint32_t)(x))<<RCC_CR_HSERDY_SHIFT))&RCC_CR_HSERDY_MASK) /**< RCC_CR.HSERDY Field                     */
#define RCC_CR_HSEBYP_MASK                       (0x40000U)                                          /**< RCC_CR.HSEBYP Mask                      */
#define RCC_CR_HSEBYP_SHIFT                      (18U)                                               /**< RCC_CR.HSEBYP Position                  */
#define RCC_CR_HSEBYP(x)                         (((uint32_t)(((uint32_t)(x))<<RCC_CR_HSEBYP_SHIFT))&RCC_CR_HSEBYP_MASK) /**< RCC_CR.HSEBYP Field                     */
#define RCC_CR_CSSON_MASK                        (0x80000U)                                          /**< RCC_CR.CSSON Mask                       */
#define RCC_CR_CSSON_SHIFT                       (19U)                                               /**< RCC_CR.CSSON Position                   */
#define RCC_CR_CSSON(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CR_CSSON_SHIFT))&RCC_CR_CSSON_MASK) /**< RCC_CR.CSSON Field                      */
#define RCC_CR_PLLON_MASK                        (0x1000000U)                                        /**< RCC_CR.PLLON Mask                       */
#define RCC_CR_PLLON_SHIFT                       (24U)                                               /**< RCC_CR.PLLON Position                   */
#define RCC_CR_PLLON(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CR_PLLON_SHIFT))&RCC_CR_PLLON_MASK) /**< RCC_CR.PLLON Field                      */
#define RCC_CR_PLLRDY_MASK                       (0x2000000U)                                        /**< RCC_CR.PLLRDY Mask                      */
#define RCC_CR_PLLRDY_SHIFT                      (25U)                                               /**< RCC_CR.PLLRDY Position                  */
#define RCC_CR_PLLRDY(x)                         (((uint32_t)(((uint32_t)(x))<<RCC_CR_PLLRDY_SHIFT))&RCC_CR_PLLRDY_MASK) /**< RCC_CR.PLLRDY Field                     */
/** @} */

/** @name CFGR - Clock configuration register */ /** @{ */
#define RCC_CFGR_SW_MASK                         (0x3U)                                              /**< RCC_CFGR.SW Mask                        */
#define RCC_CFGR_SW_SHIFT                        (0U)                                                /**< RCC_CFGR.SW Position                    */
#define RCC_CFGR_SW(x)                           (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_SW_SHIFT))&RCC_CFGR_SW_MASK) /**< RCC_CFGR.SW Field                       */
#define RCC_CFGR_SWS_MASK                        (0xCU)                                              /**< RCC_CFGR.SWS Mask                       */
#define RCC_CFGR_SWS_SHIFT                       (2U)                                                /**< RCC_CFGR.SWS Position                   */
#define RCC_CFGR_SWS(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_SWS_SHIFT))&RCC_CFGR_SWS_MASK) /**< RCC_CFGR.SWS Field                      */
#define RCC_CFGR_HPRE_MASK                       (0xF0U)                                             /**< RCC_CFGR.HPRE Mask                      */
#define RCC_CFGR_HPRE_SHIFT                      (4U)                                                /**< RCC_CFGR.HPRE Position                  */
#define RCC_CFGR_HPRE(x)                         (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_HPRE_SHIFT))&RCC_CFGR_HPRE_MASK) /**< RCC_CFGR.HPRE Field                     */
#define RCC_CFGR_PPRE_MASK                       (0x700U)                                            /**< RCC_CFGR.PPRE Mask                      */
#define RCC_CFGR_PPRE_SHIFT                      (8U)                                                /**< RCC_CFGR.PPRE Position                  */
#define RCC_CFGR_PPRE(x)                         (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_PPRE_SHIFT))&RCC_CFGR_PPRE_MASK) /**< RCC_CFGR.PPRE Field                     */
#define RCC_CFGR_ADCPRE_MASK                     (0x4000U)                                           /**< RCC_CFGR.ADCPRE Mask                    */
#define RCC_CFGR_ADCPRE_SHIFT                    (14U)                                               /**< RCC_CFGR.ADCPRE Position                */
#define RCC_CFGR_ADCPRE(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_ADCPRE_SHIFT))&RCC_CFGR_ADCPRE_MASK) /**< RCC_CFGR.ADCPRE Field                   */
#define RCC_CFGR_PLLSRC_MASK                     (0x18000U)                                          /**< RCC_CFGR.PLLSRC Mask                    */
#define RCC_CFGR_PLLSRC_SHIFT                    (15U)                                               /**< RCC_CFGR.PLLSRC Position                */
#define RCC_CFGR_PLLSRC(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_PLLSRC_SHIFT))&RCC_CFGR_PLLSRC_MASK) /**< RCC_CFGR.PLLSRC Field                   */
#define RCC_CFGR_PLLXTPRE_MASK                   (0x20000U)                                          /**< RCC_CFGR.PLLXTPRE Mask                  */
#define RCC_CFGR_PLLXTPRE_SHIFT                  (17U)                                               /**< RCC_CFGR.PLLXTPRE Position              */
#define RCC_CFGR_PLLXTPRE(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_PLLXTPRE_SHIFT))&RCC_CFGR_PLLXTPRE_MASK) /**< RCC_CFGR.PLLXTPRE Field                 */
#define RCC_CFGR_PLLMUL_MASK                     (0x3C0000U)                                         /**< RCC_CFGR.PLLMUL Mask                    */
#define RCC_CFGR_PLLMUL_SHIFT                    (18U)                                               /**< RCC_CFGR.PLLMUL Position                */
#define RCC_CFGR_PLLMUL(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_PLLMUL_SHIFT))&RCC_CFGR_PLLMUL_MASK) /**< RCC_CFGR.PLLMUL Field                   */
#define RCC_CFGR_MCO_MASK                        (0x7000000U)                                        /**< RCC_CFGR.MCO Mask                       */
#define RCC_CFGR_MCO_SHIFT                       (24U)                                               /**< RCC_CFGR.MCO Position                   */
#define RCC_CFGR_MCO(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_MCO_SHIFT))&RCC_CFGR_MCO_MASK) /**< RCC_CFGR.MCO Field                      */
#define RCC_CFGR_MCOPRE_MASK                     (0x70000000U)                                       /**< RCC_CFGR.MCOPRE Mask                    */
#define RCC_CFGR_MCOPRE_SHIFT                    (28U)                                               /**< RCC_CFGR.MCOPRE Position                */
#define RCC_CFGR_MCOPRE(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_MCOPRE_SHIFT))&RCC_CFGR_MCOPRE_MASK) /**< RCC_CFGR.MCOPRE Field                   */
#define RCC_CFGR_PLLNODIV_MASK                   (0x80000000U)                                       /**< RCC_CFGR.PLLNODIV Mask                  */
#define RCC_CFGR_PLLNODIV_SHIFT                  (31U)                                               /**< RCC_CFGR.PLLNODIV Position              */
#define RCC_CFGR_PLLNODIV(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_CFGR_PLLNODIV_SHIFT))&RCC_CFGR_PLLNODIV_MASK) /**< RCC_CFGR.PLLNODIV Field                 */
/** @} */

/** @name CIR - Clock interrupt register */ /** @{ */
#define RCC_CIR_LSIRDYF_MASK                     (0x1U)                                              /**< RCC_CIR.LSIRDYF Mask                    */
#define RCC_CIR_LSIRDYF_SHIFT                    (0U)                                                /**< RCC_CIR.LSIRDYF Position                */
#define RCC_CIR_LSIRDYF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_LSIRDYF_SHIFT))&RCC_CIR_LSIRDYF_MASK) /**< RCC_CIR.LSIRDYF Field                   */
#define RCC_CIR_LSERDYF_MASK                     (0x2U)                                              /**< RCC_CIR.LSERDYF Mask                    */
#define RCC_CIR_LSERDYF_SHIFT                    (1U)                                                /**< RCC_CIR.LSERDYF Position                */
#define RCC_CIR_LSERDYF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_LSERDYF_SHIFT))&RCC_CIR_LSERDYF_MASK) /**< RCC_CIR.LSERDYF Field                   */
#define RCC_CIR_HSIRDYF_MASK                     (0x4U)                                              /**< RCC_CIR.HSIRDYF Mask                    */
#define RCC_CIR_HSIRDYF_SHIFT                    (2U)                                                /**< RCC_CIR.HSIRDYF Position                */
#define RCC_CIR_HSIRDYF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSIRDYF_SHIFT))&RCC_CIR_HSIRDYF_MASK) /**< RCC_CIR.HSIRDYF Field                   */
#define RCC_CIR_HSERDYF_MASK                     (0x8U)                                              /**< RCC_CIR.HSERDYF Mask                    */
#define RCC_CIR_HSERDYF_SHIFT                    (3U)                                                /**< RCC_CIR.HSERDYF Position                */
#define RCC_CIR_HSERDYF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSERDYF_SHIFT))&RCC_CIR_HSERDYF_MASK) /**< RCC_CIR.HSERDYF Field                   */
#define RCC_CIR_PLLRDYF_MASK                     (0x10U)                                             /**< RCC_CIR.PLLRDYF Mask                    */
#define RCC_CIR_PLLRDYF_SHIFT                    (4U)                                                /**< RCC_CIR.PLLRDYF Position                */
#define RCC_CIR_PLLRDYF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_PLLRDYF_SHIFT))&RCC_CIR_PLLRDYF_MASK) /**< RCC_CIR.PLLRDYF Field                   */
#define RCC_CIR_HSI14RDYF_MASK                   (0x20U)                                             /**< RCC_CIR.HSI14RDYF Mask                  */
#define RCC_CIR_HSI14RDYF_SHIFT                  (5U)                                                /**< RCC_CIR.HSI14RDYF Position              */
#define RCC_CIR_HSI14RDYF(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSI14RDYF_SHIFT))&RCC_CIR_HSI14RDYF_MASK) /**< RCC_CIR.HSI14RDYF Field                 */
#define RCC_CIR_HSI48RDYF_MASK                   (0x40U)                                             /**< RCC_CIR.HSI48RDYF Mask                  */
#define RCC_CIR_HSI48RDYF_SHIFT                  (6U)                                                /**< RCC_CIR.HSI48RDYF Position              */
#define RCC_CIR_HSI48RDYF(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSI48RDYF_SHIFT))&RCC_CIR_HSI48RDYF_MASK) /**< RCC_CIR.HSI48RDYF Field                 */
#define RCC_CIR_CSSF_MASK                        (0x80U)                                             /**< RCC_CIR.CSSF Mask                       */
#define RCC_CIR_CSSF_SHIFT                       (7U)                                                /**< RCC_CIR.CSSF Position                   */
#define RCC_CIR_CSSF(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CIR_CSSF_SHIFT))&RCC_CIR_CSSF_MASK) /**< RCC_CIR.CSSF Field                      */
#define RCC_CIR_LSIRDYIE_MASK                    (0x100U)                                            /**< RCC_CIR.LSIRDYIE Mask                   */
#define RCC_CIR_LSIRDYIE_SHIFT                   (8U)                                                /**< RCC_CIR.LSIRDYIE Position               */
#define RCC_CIR_LSIRDYIE(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CIR_LSIRDYIE_SHIFT))&RCC_CIR_LSIRDYIE_MASK) /**< RCC_CIR.LSIRDYIE Field                  */
#define RCC_CIR_LSERDYIE_MASK                    (0x200U)                                            /**< RCC_CIR.LSERDYIE Mask                   */
#define RCC_CIR_LSERDYIE_SHIFT                   (9U)                                                /**< RCC_CIR.LSERDYIE Position               */
#define RCC_CIR_LSERDYIE(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CIR_LSERDYIE_SHIFT))&RCC_CIR_LSERDYIE_MASK) /**< RCC_CIR.LSERDYIE Field                  */
#define RCC_CIR_HSIRDYIE_MASK                    (0x400U)                                            /**< RCC_CIR.HSIRDYIE Mask                   */
#define RCC_CIR_HSIRDYIE_SHIFT                   (10U)                                               /**< RCC_CIR.HSIRDYIE Position               */
#define RCC_CIR_HSIRDYIE(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSIRDYIE_SHIFT))&RCC_CIR_HSIRDYIE_MASK) /**< RCC_CIR.HSIRDYIE Field                  */
#define RCC_CIR_HSERDYIE_MASK                    (0x800U)                                            /**< RCC_CIR.HSERDYIE Mask                   */
#define RCC_CIR_HSERDYIE_SHIFT                   (11U)                                               /**< RCC_CIR.HSERDYIE Position               */
#define RCC_CIR_HSERDYIE(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSERDYIE_SHIFT))&RCC_CIR_HSERDYIE_MASK) /**< RCC_CIR.HSERDYIE Field                  */
#define RCC_CIR_PLLRDYIE_MASK                    (0x1000U)                                           /**< RCC_CIR.PLLRDYIE Mask                   */
#define RCC_CIR_PLLRDYIE_SHIFT                   (12U)                                               /**< RCC_CIR.PLLRDYIE Position               */
#define RCC_CIR_PLLRDYIE(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CIR_PLLRDYIE_SHIFT))&RCC_CIR_PLLRDYIE_MASK) /**< RCC_CIR.PLLRDYIE Field                  */
#define RCC_CIR_HSI14RDYE_MASK                   (0x2000U)                                           /**< RCC_CIR.HSI14RDYE Mask                  */
#define RCC_CIR_HSI14RDYE_SHIFT                  (13U)                                               /**< RCC_CIR.HSI14RDYE Position              */
#define RCC_CIR_HSI14RDYE(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSI14RDYE_SHIFT))&RCC_CIR_HSI14RDYE_MASK) /**< RCC_CIR.HSI14RDYE Field                 */
#define RCC_CIR_HSI48RDYIE_MASK                  (0x4000U)                                           /**< RCC_CIR.HSI48RDYIE Mask                 */
#define RCC_CIR_HSI48RDYIE_SHIFT                 (14U)                                               /**< RCC_CIR.HSI48RDYIE Position             */
#define RCC_CIR_HSI48RDYIE(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSI48RDYIE_SHIFT))&RCC_CIR_HSI48RDYIE_MASK) /**< RCC_CIR.HSI48RDYIE Field                */
#define RCC_CIR_LSIRDYC_MASK                     (0x10000U)                                          /**< RCC_CIR.LSIRDYC Mask                    */
#define RCC_CIR_LSIRDYC_SHIFT                    (16U)                                               /**< RCC_CIR.LSIRDYC Position                */
#define RCC_CIR_LSIRDYC(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_LSIRDYC_SHIFT))&RCC_CIR_LSIRDYC_MASK) /**< RCC_CIR.LSIRDYC Field                   */
#define RCC_CIR_LSERDYC_MASK                     (0x20000U)                                          /**< RCC_CIR.LSERDYC Mask                    */
#define RCC_CIR_LSERDYC_SHIFT                    (17U)                                               /**< RCC_CIR.LSERDYC Position                */
#define RCC_CIR_LSERDYC(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_LSERDYC_SHIFT))&RCC_CIR_LSERDYC_MASK) /**< RCC_CIR.LSERDYC Field                   */
#define RCC_CIR_HSIRDYC_MASK                     (0x40000U)                                          /**< RCC_CIR.HSIRDYC Mask                    */
#define RCC_CIR_HSIRDYC_SHIFT                    (18U)                                               /**< RCC_CIR.HSIRDYC Position                */
#define RCC_CIR_HSIRDYC(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSIRDYC_SHIFT))&RCC_CIR_HSIRDYC_MASK) /**< RCC_CIR.HSIRDYC Field                   */
#define RCC_CIR_HSERDYC_MASK                     (0x80000U)                                          /**< RCC_CIR.HSERDYC Mask                    */
#define RCC_CIR_HSERDYC_SHIFT                    (19U)                                               /**< RCC_CIR.HSERDYC Position                */
#define RCC_CIR_HSERDYC(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSERDYC_SHIFT))&RCC_CIR_HSERDYC_MASK) /**< RCC_CIR.HSERDYC Field                   */
#define RCC_CIR_PLLRDYC_MASK                     (0x100000U)                                         /**< RCC_CIR.PLLRDYC Mask                    */
#define RCC_CIR_PLLRDYC_SHIFT                    (20U)                                               /**< RCC_CIR.PLLRDYC Position                */
#define RCC_CIR_PLLRDYC(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CIR_PLLRDYC_SHIFT))&RCC_CIR_PLLRDYC_MASK) /**< RCC_CIR.PLLRDYC Field                   */
#define RCC_CIR_HSI14RDYC_MASK                   (0x200000U)                                         /**< RCC_CIR.HSI14RDYC Mask                  */
#define RCC_CIR_HSI14RDYC_SHIFT                  (21U)                                               /**< RCC_CIR.HSI14RDYC Position              */
#define RCC_CIR_HSI14RDYC(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSI14RDYC_SHIFT))&RCC_CIR_HSI14RDYC_MASK) /**< RCC_CIR.HSI14RDYC Field                 */
#define RCC_CIR_HSI48RDYC_MASK                   (0x400000U)                                         /**< RCC_CIR.HSI48RDYC Mask                  */
#define RCC_CIR_HSI48RDYC_SHIFT                  (22U)                                               /**< RCC_CIR.HSI48RDYC Position              */
#define RCC_CIR_HSI48RDYC(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_CIR_HSI48RDYC_SHIFT))&RCC_CIR_HSI48RDYC_MASK) /**< RCC_CIR.HSI48RDYC Field                 */
#define RCC_CIR_CSSC_MASK                        (0x800000U)                                         /**< RCC_CIR.CSSC Mask                       */
#define RCC_CIR_CSSC_SHIFT                       (23U)                                               /**< RCC_CIR.CSSC Position                   */
#define RCC_CIR_CSSC(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CIR_CSSC_SHIFT))&RCC_CIR_CSSC_MASK) /**< RCC_CIR.CSSC Field                      */
/** @} */

/** @name APB2RSTR - APB2 peripheral reset register */ /** @{ */
#define RCC_APB2RSTR_SYSCFGRST_MASK              (0x1U)                                              /**< RCC_APB2RSTR.SYSCFGRST Mask             */
#define RCC_APB2RSTR_SYSCFGRST_SHIFT             (0U)                                                /**< RCC_APB2RSTR.SYSCFGRST Position         */
#define RCC_APB2RSTR_SYSCFGRST(x)                (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_SYSCFGRST_SHIFT))&RCC_APB2RSTR_SYSCFGRST_MASK) /**< RCC_APB2RSTR.SYSCFGRST Field            */
#define RCC_APB2RSTR_ADCRST_MASK                 (0x200U)                                            /**< RCC_APB2RSTR.ADCRST Mask                */
#define RCC_APB2RSTR_ADCRST_SHIFT                (9U)                                                /**< RCC_APB2RSTR.ADCRST Position            */
#define RCC_APB2RSTR_ADCRST(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_ADCRST_SHIFT))&RCC_APB2RSTR_ADCRST_MASK) /**< RCC_APB2RSTR.ADCRST Field               */
#define RCC_APB2RSTR_TIM1RST_MASK                (0x800U)                                            /**< RCC_APB2RSTR.TIM1RST Mask               */
#define RCC_APB2RSTR_TIM1RST_SHIFT               (11U)                                               /**< RCC_APB2RSTR.TIM1RST Position           */
#define RCC_APB2RSTR_TIM1RST(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_TIM1RST_SHIFT))&RCC_APB2RSTR_TIM1RST_MASK) /**< RCC_APB2RSTR.TIM1RST Field              */
#define RCC_APB2RSTR_SPI1RST_MASK                (0x1000U)                                           /**< RCC_APB2RSTR.SPI1RST Mask               */
#define RCC_APB2RSTR_SPI1RST_SHIFT               (12U)                                               /**< RCC_APB2RSTR.SPI1RST Position           */
#define RCC_APB2RSTR_SPI1RST(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_SPI1RST_SHIFT))&RCC_APB2RSTR_SPI1RST_MASK) /**< RCC_APB2RSTR.SPI1RST Field              */
#define RCC_APB2RSTR_USART1RST_MASK              (0x4000U)                                           /**< RCC_APB2RSTR.USART1RST Mask             */
#define RCC_APB2RSTR_USART1RST_SHIFT             (14U)                                               /**< RCC_APB2RSTR.USART1RST Position         */
#define RCC_APB2RSTR_USART1RST(x)                (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_USART1RST_SHIFT))&RCC_APB2RSTR_USART1RST_MASK) /**< RCC_APB2RSTR.USART1RST Field            */
#define RCC_APB2RSTR_TIM15RST_MASK               (0x10000U)                                          /**< RCC_APB2RSTR.TIM15RST Mask              */
#define RCC_APB2RSTR_TIM15RST_SHIFT              (16U)                                               /**< RCC_APB2RSTR.TIM15RST Position          */
#define RCC_APB2RSTR_TIM15RST(x)                 (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_TIM15RST_SHIFT))&RCC_APB2RSTR_TIM15RST_MASK) /**< RCC_APB2RSTR.TIM15RST Field             */
#define RCC_APB2RSTR_TIM16RST_MASK               (0x20000U)                                          /**< RCC_APB2RSTR.TIM16RST Mask              */
#define RCC_APB2RSTR_TIM16RST_SHIFT              (17U)                                               /**< RCC_APB2RSTR.TIM16RST Position          */
#define RCC_APB2RSTR_TIM16RST(x)                 (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_TIM16RST_SHIFT))&RCC_APB2RSTR_TIM16RST_MASK) /**< RCC_APB2RSTR.TIM16RST Field             */
#define RCC_APB2RSTR_TIM17RST_MASK               (0x40000U)                                          /**< RCC_APB2RSTR.TIM17RST Mask              */
#define RCC_APB2RSTR_TIM17RST_SHIFT              (18U)                                               /**< RCC_APB2RSTR.TIM17RST Position          */
#define RCC_APB2RSTR_TIM17RST(x)                 (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_TIM17RST_SHIFT))&RCC_APB2RSTR_TIM17RST_MASK) /**< RCC_APB2RSTR.TIM17RST Field             */
#define RCC_APB2RSTR_DBGMCURST_MASK              (0x400000U)                                         /**< RCC_APB2RSTR.DBGMCURST Mask             */
#define RCC_APB2RSTR_DBGMCURST_SHIFT             (22U)                                               /**< RCC_APB2RSTR.DBGMCURST Position         */
#define RCC_APB2RSTR_DBGMCURST(x)                (((uint32_t)(((uint32_t)(x))<<RCC_APB2RSTR_DBGMCURST_SHIFT))&RCC_APB2RSTR_DBGMCURST_MASK) /**< RCC_APB2RSTR.DBGMCURST Field            */
/** @} */

/** @name APB1RSTR - APB1 peripheral reset register */ /** @{ */
#define RCC_APB1RSTR_TIM3RST_MASK                (0x2U)                                              /**< RCC_APB1RSTR.TIM3RST Mask               */
#define RCC_APB1RSTR_TIM3RST_SHIFT               (1U)                                                /**< RCC_APB1RSTR.TIM3RST Position           */
#define RCC_APB1RSTR_TIM3RST(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_TIM3RST_SHIFT))&RCC_APB1RSTR_TIM3RST_MASK) /**< RCC_APB1RSTR.TIM3RST Field              */
#define RCC_APB1RSTR_TIM6RST_MASK                (0x10U)                                             /**< RCC_APB1RSTR.TIM6RST Mask               */
#define RCC_APB1RSTR_TIM6RST_SHIFT               (4U)                                                /**< RCC_APB1RSTR.TIM6RST Position           */
#define RCC_APB1RSTR_TIM6RST(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_TIM6RST_SHIFT))&RCC_APB1RSTR_TIM6RST_MASK) /**< RCC_APB1RSTR.TIM6RST Field              */
#define RCC_APB1RSTR_TIM14RST_MASK               (0x100U)                                            /**< RCC_APB1RSTR.TIM14RST Mask              */
#define RCC_APB1RSTR_TIM14RST_SHIFT              (8U)                                                /**< RCC_APB1RSTR.TIM14RST Position          */
#define RCC_APB1RSTR_TIM14RST(x)                 (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_TIM14RST_SHIFT))&RCC_APB1RSTR_TIM14RST_MASK) /**< RCC_APB1RSTR.TIM14RST Field             */
#define RCC_APB1RSTR_WWDGRST_MASK                (0x800U)                                            /**< RCC_APB1RSTR.WWDGRST Mask               */
#define RCC_APB1RSTR_WWDGRST_SHIFT               (11U)                                               /**< RCC_APB1RSTR.WWDGRST Position           */
#define RCC_APB1RSTR_WWDGRST(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_WWDGRST_SHIFT))&RCC_APB1RSTR_WWDGRST_MASK) /**< RCC_APB1RSTR.WWDGRST Field              */
#define RCC_APB1RSTR_SPI2RST_MASK                (0x4000U)                                           /**< RCC_APB1RSTR.SPI2RST Mask               */
#define RCC_APB1RSTR_SPI2RST_SHIFT               (14U)                                               /**< RCC_APB1RSTR.SPI2RST Position           */
#define RCC_APB1RSTR_SPI2RST(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_SPI2RST_SHIFT))&RCC_APB1RSTR_SPI2RST_MASK) /**< RCC_APB1RSTR.SPI2RST Field              */
#define RCC_APB1RSTR_USART2RST_MASK              (0x20000U)                                          /**< RCC_APB1RSTR.USART2RST Mask             */
#define RCC_APB1RSTR_USART2RST_SHIFT             (17U)                                               /**< RCC_APB1RSTR.USART2RST Position         */
#define RCC_APB1RSTR_USART2RST(x)                (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_USART2RST_SHIFT))&RCC_APB1RSTR_USART2RST_MASK) /**< RCC_APB1RSTR.USART2RST Field            */
#define RCC_APB1RSTR_I2C1RST_MASK                (0x200000U)                                         /**< RCC_APB1RSTR.I2C1RST Mask               */
#define RCC_APB1RSTR_I2C1RST_SHIFT               (21U)                                               /**< RCC_APB1RSTR.I2C1RST Position           */
#define RCC_APB1RSTR_I2C1RST(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_I2C1RST_SHIFT))&RCC_APB1RSTR_I2C1RST_MASK) /**< RCC_APB1RSTR.I2C1RST Field              */
#define RCC_APB1RSTR_I2C2RST_MASK                (0x400000U)                                         /**< RCC_APB1RSTR.I2C2RST Mask               */
#define RCC_APB1RSTR_I2C2RST_SHIFT               (22U)                                               /**< RCC_APB1RSTR.I2C2RST Position           */
#define RCC_APB1RSTR_I2C2RST(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_I2C2RST_SHIFT))&RCC_APB1RSTR_I2C2RST_MASK) /**< RCC_APB1RSTR.I2C2RST Field              */
#define RCC_APB1RSTR_PWRRST_MASK                 (0x10000000U)                                       /**< RCC_APB1RSTR.PWRRST Mask                */
#define RCC_APB1RSTR_PWRRST_SHIFT                (28U)                                               /**< RCC_APB1RSTR.PWRRST Position            */
#define RCC_APB1RSTR_PWRRST(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_APB1RSTR_PWRRST_SHIFT))&RCC_APB1RSTR_PWRRST_MASK) /**< RCC_APB1RSTR.PWRRST Field               */
/** @} */

/** @name AHBENR - AHB Peripheral Clock enable register */ /** @{ */
#define RCC_AHBENR_DMAEN_MASK                    (0x1U)                                              /**< RCC_AHBENR.DMAEN Mask                   */
#define RCC_AHBENR_DMAEN_SHIFT                   (0U)                                                /**< RCC_AHBENR.DMAEN Position               */
#define RCC_AHBENR_DMAEN(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_DMAEN_SHIFT))&RCC_AHBENR_DMAEN_MASK) /**< RCC_AHBENR.DMAEN Field                  */
#define RCC_AHBENR_SRAMEN_MASK                   (0x4U)                                              /**< RCC_AHBENR.SRAMEN Mask                  */
#define RCC_AHBENR_SRAMEN_SHIFT                  (2U)                                                /**< RCC_AHBENR.SRAMEN Position              */
#define RCC_AHBENR_SRAMEN(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_SRAMEN_SHIFT))&RCC_AHBENR_SRAMEN_MASK) /**< RCC_AHBENR.SRAMEN Field                 */
#define RCC_AHBENR_FLITFEN_MASK                  (0x10U)                                             /**< RCC_AHBENR.FLITFEN Mask                 */
#define RCC_AHBENR_FLITFEN_SHIFT                 (4U)                                                /**< RCC_AHBENR.FLITFEN Position             */
#define RCC_AHBENR_FLITFEN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_FLITFEN_SHIFT))&RCC_AHBENR_FLITFEN_MASK) /**< RCC_AHBENR.FLITFEN Field                */
#define RCC_AHBENR_CRCEN_MASK                    (0x40U)                                             /**< RCC_AHBENR.CRCEN Mask                   */
#define RCC_AHBENR_CRCEN_SHIFT                   (6U)                                                /**< RCC_AHBENR.CRCEN Position               */
#define RCC_AHBENR_CRCEN(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_CRCEN_SHIFT))&RCC_AHBENR_CRCEN_MASK) /**< RCC_AHBENR.CRCEN Field                  */
#define RCC_AHBENR_IOPAEN_MASK                   (0x20000U)                                          /**< RCC_AHBENR.IOPAEN Mask                  */
#define RCC_AHBENR_IOPAEN_SHIFT                  (17U)                                               /**< RCC_AHBENR.IOPAEN Position              */
#define RCC_AHBENR_IOPAEN(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_IOPAEN_SHIFT))&RCC_AHBENR_IOPAEN_MASK) /**< RCC_AHBENR.IOPAEN Field                 */
#define RCC_AHBENR_IOPBEN_MASK                   (0x40000U)                                          /**< RCC_AHBENR.IOPBEN Mask                  */
#define RCC_AHBENR_IOPBEN_SHIFT                  (18U)                                               /**< RCC_AHBENR.IOPBEN Position              */
#define RCC_AHBENR_IOPBEN(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_IOPBEN_SHIFT))&RCC_AHBENR_IOPBEN_MASK) /**< RCC_AHBENR.IOPBEN Field                 */
#define RCC_AHBENR_IOPCEN_MASK                   (0x80000U)                                          /**< RCC_AHBENR.IOPCEN Mask                  */
#define RCC_AHBENR_IOPCEN_SHIFT                  (19U)                                               /**< RCC_AHBENR.IOPCEN Position              */
#define RCC_AHBENR_IOPCEN(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_IOPCEN_SHIFT))&RCC_AHBENR_IOPCEN_MASK) /**< RCC_AHBENR.IOPCEN Field                 */
#define RCC_AHBENR_IOPDEN_MASK                   (0x100000U)                                         /**< RCC_AHBENR.IOPDEN Mask                  */
#define RCC_AHBENR_IOPDEN_SHIFT                  (20U)                                               /**< RCC_AHBENR.IOPDEN Position              */
#define RCC_AHBENR_IOPDEN(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_IOPDEN_SHIFT))&RCC_AHBENR_IOPDEN_MASK) /**< RCC_AHBENR.IOPDEN Field                 */
#define RCC_AHBENR_IOPFEN_MASK                   (0x400000U)                                         /**< RCC_AHBENR.IOPFEN Mask                  */
#define RCC_AHBENR_IOPFEN_SHIFT                  (22U)                                               /**< RCC_AHBENR.IOPFEN Position              */
#define RCC_AHBENR_IOPFEN(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_AHBENR_IOPFEN_SHIFT))&RCC_AHBENR_IOPFEN_MASK) /**< RCC_AHBENR.IOPFEN Field                 */
/** @} */

/** @name APB2ENR - APB2 peripheral clock enable register */ /** @{ */
#define RCC_APB2ENR_SYSCFGEN_MASK                (0x1U)                                              /**< RCC_APB2ENR.SYSCFGEN Mask               */
#define RCC_APB2ENR_SYSCFGEN_SHIFT               (0U)                                                /**< RCC_APB2ENR.SYSCFGEN Position           */
#define RCC_APB2ENR_SYSCFGEN(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_SYSCFGEN_SHIFT))&RCC_APB2ENR_SYSCFGEN_MASK) /**< RCC_APB2ENR.SYSCFGEN Field              */
#define RCC_APB2ENR_ADCEN_MASK                   (0x200U)                                            /**< RCC_APB2ENR.ADCEN Mask                  */
#define RCC_APB2ENR_ADCEN_SHIFT                  (9U)                                                /**< RCC_APB2ENR.ADCEN Position              */
#define RCC_APB2ENR_ADCEN(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_ADCEN_SHIFT))&RCC_APB2ENR_ADCEN_MASK) /**< RCC_APB2ENR.ADCEN Field                 */
#define RCC_APB2ENR_TIM1EN_MASK                  (0x800U)                                            /**< RCC_APB2ENR.TIM1EN Mask                 */
#define RCC_APB2ENR_TIM1EN_SHIFT                 (11U)                                               /**< RCC_APB2ENR.TIM1EN Position             */
#define RCC_APB2ENR_TIM1EN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_TIM1EN_SHIFT))&RCC_APB2ENR_TIM1EN_MASK) /**< RCC_APB2ENR.TIM1EN Field                */
#define RCC_APB2ENR_SPI1EN_MASK                  (0x1000U)                                           /**< RCC_APB2ENR.SPI1EN Mask                 */
#define RCC_APB2ENR_SPI1EN_SHIFT                 (12U)                                               /**< RCC_APB2ENR.SPI1EN Position             */
#define RCC_APB2ENR_SPI1EN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_SPI1EN_SHIFT))&RCC_APB2ENR_SPI1EN_MASK) /**< RCC_APB2ENR.SPI1EN Field                */
#define RCC_APB2ENR_USART1EN_MASK                (0x4000U)                                           /**< RCC_APB2ENR.USART1EN Mask               */
#define RCC_APB2ENR_USART1EN_SHIFT               (14U)                                               /**< RCC_APB2ENR.USART1EN Position           */
#define RCC_APB2ENR_USART1EN(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_USART1EN_SHIFT))&RCC_APB2ENR_USART1EN_MASK) /**< RCC_APB2ENR.USART1EN Field              */
#define RCC_APB2ENR_TIM15EN_MASK                 (0x10000U)                                          /**< RCC_APB2ENR.TIM15EN Mask                */
#define RCC_APB2ENR_TIM15EN_SHIFT                (16U)                                               /**< RCC_APB2ENR.TIM15EN Position            */
#define RCC_APB2ENR_TIM15EN(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_TIM15EN_SHIFT))&RCC_APB2ENR_TIM15EN_MASK) /**< RCC_APB2ENR.TIM15EN Field               */
#define RCC_APB2ENR_TIM16EN_MASK                 (0x20000U)                                          /**< RCC_APB2ENR.TIM16EN Mask                */
#define RCC_APB2ENR_TIM16EN_SHIFT                (17U)                                               /**< RCC_APB2ENR.TIM16EN Position            */
#define RCC_APB2ENR_TIM16EN(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_TIM16EN_SHIFT))&RCC_APB2ENR_TIM16EN_MASK) /**< RCC_APB2ENR.TIM16EN Field               */
#define RCC_APB2ENR_TIM17EN_MASK                 (0x40000U)                                          /**< RCC_APB2ENR.TIM17EN Mask                */
#define RCC_APB2ENR_TIM17EN_SHIFT                (18U)                                               /**< RCC_APB2ENR.TIM17EN Position            */
#define RCC_APB2ENR_TIM17EN(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_TIM17EN_SHIFT))&RCC_APB2ENR_TIM17EN_MASK) /**< RCC_APB2ENR.TIM17EN Field               */
#define RCC_APB2ENR_DBGMCUEN_MASK                (0x400000U)                                         /**< RCC_APB2ENR.DBGMCUEN Mask               */
#define RCC_APB2ENR_DBGMCUEN_SHIFT               (22U)                                               /**< RCC_APB2ENR.DBGMCUEN Position           */
#define RCC_APB2ENR_DBGMCUEN(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB2ENR_DBGMCUEN_SHIFT))&RCC_APB2ENR_DBGMCUEN_MASK) /**< RCC_APB2ENR.DBGMCUEN Field              */
/** @} */

/** @name APB1ENR - APB1 peripheral clock enable register */ /** @{ */
#define RCC_APB1ENR_TIM3EN_MASK                  (0x2U)                                              /**< RCC_APB1ENR.TIM3EN Mask                 */
#define RCC_APB1ENR_TIM3EN_SHIFT                 (1U)                                                /**< RCC_APB1ENR.TIM3EN Position             */
#define RCC_APB1ENR_TIM3EN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_TIM3EN_SHIFT))&RCC_APB1ENR_TIM3EN_MASK) /**< RCC_APB1ENR.TIM3EN Field                */
#define RCC_APB1ENR_TIM6EN_MASK                  (0x10U)                                             /**< RCC_APB1ENR.TIM6EN Mask                 */
#define RCC_APB1ENR_TIM6EN_SHIFT                 (4U)                                                /**< RCC_APB1ENR.TIM6EN Position             */
#define RCC_APB1ENR_TIM6EN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_TIM6EN_SHIFT))&RCC_APB1ENR_TIM6EN_MASK) /**< RCC_APB1ENR.TIM6EN Field                */
#define RCC_APB1ENR_TIM14EN_MASK                 (0x100U)                                            /**< RCC_APB1ENR.TIM14EN Mask                */
#define RCC_APB1ENR_TIM14EN_SHIFT                (8U)                                                /**< RCC_APB1ENR.TIM14EN Position            */
#define RCC_APB1ENR_TIM14EN(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_TIM14EN_SHIFT))&RCC_APB1ENR_TIM14EN_MASK) /**< RCC_APB1ENR.TIM14EN Field               */
#define RCC_APB1ENR_WWDGEN_MASK                  (0x800U)                                            /**< RCC_APB1ENR.WWDGEN Mask                 */
#define RCC_APB1ENR_WWDGEN_SHIFT                 (11U)                                               /**< RCC_APB1ENR.WWDGEN Position             */
#define RCC_APB1ENR_WWDGEN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_WWDGEN_SHIFT))&RCC_APB1ENR_WWDGEN_MASK) /**< RCC_APB1ENR.WWDGEN Field                */
#define RCC_APB1ENR_SPI2EN_MASK                  (0x4000U)                                           /**< RCC_APB1ENR.SPI2EN Mask                 */
#define RCC_APB1ENR_SPI2EN_SHIFT                 (14U)                                               /**< RCC_APB1ENR.SPI2EN Position             */
#define RCC_APB1ENR_SPI2EN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_SPI2EN_SHIFT))&RCC_APB1ENR_SPI2EN_MASK) /**< RCC_APB1ENR.SPI2EN Field                */
#define RCC_APB1ENR_USART2EN_MASK                (0x20000U)                                          /**< RCC_APB1ENR.USART2EN Mask               */
#define RCC_APB1ENR_USART2EN_SHIFT               (17U)                                               /**< RCC_APB1ENR.USART2EN Position           */
#define RCC_APB1ENR_USART2EN(x)                  (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_USART2EN_SHIFT))&RCC_APB1ENR_USART2EN_MASK) /**< RCC_APB1ENR.USART2EN Field              */
#define RCC_APB1ENR_I2C1EN_MASK                  (0x200000U)                                         /**< RCC_APB1ENR.I2C1EN Mask                 */
#define RCC_APB1ENR_I2C1EN_SHIFT                 (21U)                                               /**< RCC_APB1ENR.I2C1EN Position             */
#define RCC_APB1ENR_I2C1EN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_I2C1EN_SHIFT))&RCC_APB1ENR_I2C1EN_MASK) /**< RCC_APB1ENR.I2C1EN Field                */
#define RCC_APB1ENR_I2C2EN_MASK                  (0x400000U)                                         /**< RCC_APB1ENR.I2C2EN Mask                 */
#define RCC_APB1ENR_I2C2EN_SHIFT                 (22U)                                               /**< RCC_APB1ENR.I2C2EN Position             */
#define RCC_APB1ENR_I2C2EN(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_I2C2EN_SHIFT))&RCC_APB1ENR_I2C2EN_MASK) /**< RCC_APB1ENR.I2C2EN Field                */
#define RCC_APB1ENR_PWREN_MASK                   (0x10000000U)                                       /**< RCC_APB1ENR.PWREN Mask                  */
#define RCC_APB1ENR_PWREN_SHIFT                  (28U)                                               /**< RCC_APB1ENR.PWREN Position              */
#define RCC_APB1ENR_PWREN(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_APB1ENR_PWREN_SHIFT))&RCC_APB1ENR_PWREN_MASK) /**< RCC_APB1ENR.PWREN Field                 */
/** @} */

/** @name BDCR - Backup domain control register */ /** @{ */
#define RCC_BDCR_LSEON_MASK                      (0x1U)                                              /**< RCC_BDCR.LSEON Mask                     */
#define RCC_BDCR_LSEON_SHIFT                     (0U)                                                /**< RCC_BDCR.LSEON Position                 */
#define RCC_BDCR_LSEON(x)                        (((uint32_t)(((uint32_t)(x))<<RCC_BDCR_LSEON_SHIFT))&RCC_BDCR_LSEON_MASK) /**< RCC_BDCR.LSEON Field                    */
#define RCC_BDCR_LSERDY_MASK                     (0x2U)                                              /**< RCC_BDCR.LSERDY Mask                    */
#define RCC_BDCR_LSERDY_SHIFT                    (1U)                                                /**< RCC_BDCR.LSERDY Position                */
#define RCC_BDCR_LSERDY(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_BDCR_LSERDY_SHIFT))&RCC_BDCR_LSERDY_MASK) /**< RCC_BDCR.LSERDY Field                   */
#define RCC_BDCR_LSEBYP_MASK                     (0x4U)                                              /**< RCC_BDCR.LSEBYP Mask                    */
#define RCC_BDCR_LSEBYP_SHIFT                    (2U)                                                /**< RCC_BDCR.LSEBYP Position                */
#define RCC_BDCR_LSEBYP(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_BDCR_LSEBYP_SHIFT))&RCC_BDCR_LSEBYP_MASK) /**< RCC_BDCR.LSEBYP Field                   */
#define RCC_BDCR_LSEDRV_MASK                     (0x18U)                                             /**< RCC_BDCR.LSEDRV Mask                    */
#define RCC_BDCR_LSEDRV_SHIFT                    (3U)                                                /**< RCC_BDCR.LSEDRV Position                */
#define RCC_BDCR_LSEDRV(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_BDCR_LSEDRV_SHIFT))&RCC_BDCR_LSEDRV_MASK) /**< RCC_BDCR.LSEDRV Field                   */
#define RCC_BDCR_RTCSEL_MASK                     (0x300U)                                            /**< RCC_BDCR.RTCSEL Mask                    */
#define RCC_BDCR_RTCSEL_SHIFT                    (8U)                                                /**< RCC_BDCR.RTCSEL Position                */
#define RCC_BDCR_RTCSEL(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_BDCR_RTCSEL_SHIFT))&RCC_BDCR_RTCSEL_MASK) /**< RCC_BDCR.RTCSEL Field                   */
#define RCC_BDCR_RTCEN_MASK                      (0x8000U)                                           /**< RCC_BDCR.RTCEN Mask                     */
#define RCC_BDCR_RTCEN_SHIFT                     (15U)                                               /**< RCC_BDCR.RTCEN Position                 */
#define RCC_BDCR_RTCEN(x)                        (((uint32_t)(((uint32_t)(x))<<RCC_BDCR_RTCEN_SHIFT))&RCC_BDCR_RTCEN_MASK) /**< RCC_BDCR.RTCEN Field                    */
#define RCC_BDCR_BDRST_MASK                      (0x10000U)                                          /**< RCC_BDCR.BDRST Mask                     */
#define RCC_BDCR_BDRST_SHIFT                     (16U)                                               /**< RCC_BDCR.BDRST Position                 */
#define RCC_BDCR_BDRST(x)                        (((uint32_t)(((uint32_t)(x))<<RCC_BDCR_BDRST_SHIFT))&RCC_BDCR_BDRST_MASK) /**< RCC_BDCR.BDRST Field                    */
/** @} */

/** @name CSR - Control/status register */ /** @{ */
#define RCC_CSR_LSION_MASK                       (0x1U)                                              /**< RCC_CSR.LSION Mask                      */
#define RCC_CSR_LSION_SHIFT                      (0U)                                                /**< RCC_CSR.LSION Position                  */
#define RCC_CSR_LSION(x)                         (((uint32_t)(((uint32_t)(x))<<RCC_CSR_LSION_SHIFT))&RCC_CSR_LSION_MASK) /**< RCC_CSR.LSION Field                     */
#define RCC_CSR_LSIRDY_MASK                      (0x2U)                                              /**< RCC_CSR.LSIRDY Mask                     */
#define RCC_CSR_LSIRDY_SHIFT                     (1U)                                                /**< RCC_CSR.LSIRDY Position                 */
#define RCC_CSR_LSIRDY(x)                        (((uint32_t)(((uint32_t)(x))<<RCC_CSR_LSIRDY_SHIFT))&RCC_CSR_LSIRDY_MASK) /**< RCC_CSR.LSIRDY Field                    */
#define RCC_CSR_RMVF_MASK                        (0x1000000U)                                        /**< RCC_CSR.RMVF Mask                       */
#define RCC_CSR_RMVF_SHIFT                       (24U)                                               /**< RCC_CSR.RMVF Position                   */
#define RCC_CSR_RMVF(x)                          (((uint32_t)(((uint32_t)(x))<<RCC_CSR_RMVF_SHIFT))&RCC_CSR_RMVF_MASK) /**< RCC_CSR.RMVF Field                      */
#define RCC_CSR_OBLRSTF_MASK                     (0x2000000U)                                        /**< RCC_CSR.OBLRSTF Mask                    */
#define RCC_CSR_OBLRSTF_SHIFT                    (25U)                                               /**< RCC_CSR.OBLRSTF Position                */
#define RCC_CSR_OBLRSTF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CSR_OBLRSTF_SHIFT))&RCC_CSR_OBLRSTF_MASK) /**< RCC_CSR.OBLRSTF Field                   */
#define RCC_CSR_PINRSTF_MASK                     (0x4000000U)                                        /**< RCC_CSR.PINRSTF Mask                    */
#define RCC_CSR_PINRSTF_SHIFT                    (26U)                                               /**< RCC_CSR.PINRSTF Position                */
#define RCC_CSR_PINRSTF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CSR_PINRSTF_SHIFT))&RCC_CSR_PINRSTF_MASK) /**< RCC_CSR.PINRSTF Field                   */
#define RCC_CSR_PORRSTF_MASK                     (0x8000000U)                                        /**< RCC_CSR.PORRSTF Mask                    */
#define RCC_CSR_PORRSTF_SHIFT                    (27U)                                               /**< RCC_CSR.PORRSTF Position                */
#define RCC_CSR_PORRSTF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CSR_PORRSTF_SHIFT))&RCC_CSR_PORRSTF_MASK) /**< RCC_CSR.PORRSTF Field                   */
#define RCC_CSR_SFTRSTF_MASK                     (0x10000000U)                                       /**< RCC_CSR.SFTRSTF Mask                    */
#define RCC_CSR_SFTRSTF_SHIFT                    (28U)                                               /**< RCC_CSR.SFTRSTF Position                */
#define RCC_CSR_SFTRSTF(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CSR_SFTRSTF_SHIFT))&RCC_CSR_SFTRSTF_MASK) /**< RCC_CSR.SFTRSTF Field                   */
#define RCC_CSR_IWDGRSTF_MASK                    (0x20000000U)                                       /**< RCC_CSR.IWDGRSTF Mask                   */
#define RCC_CSR_IWDGRSTF_SHIFT                   (29U)                                               /**< RCC_CSR.IWDGRSTF Position               */
#define RCC_CSR_IWDGRSTF(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CSR_IWDGRSTF_SHIFT))&RCC_CSR_IWDGRSTF_MASK) /**< RCC_CSR.IWDGRSTF Field                  */
#define RCC_CSR_WWDGRSTF_MASK                    (0x40000000U)                                       /**< RCC_CSR.WWDGRSTF Mask                   */
#define RCC_CSR_WWDGRSTF_SHIFT                   (30U)                                               /**< RCC_CSR.WWDGRSTF Position               */
#define RCC_CSR_WWDGRSTF(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CSR_WWDGRSTF_SHIFT))&RCC_CSR_WWDGRSTF_MASK) /**< RCC_CSR.WWDGRSTF Field                  */
#define RCC_CSR_LPWRRSTF_MASK                    (0x80000000U)                                       /**< RCC_CSR.LPWRRSTF Mask                   */
#define RCC_CSR_LPWRRSTF_SHIFT                   (31U)                                               /**< RCC_CSR.LPWRRSTF Position               */
#define RCC_CSR_LPWRRSTF(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CSR_LPWRRSTF_SHIFT))&RCC_CSR_LPWRRSTF_MASK) /**< RCC_CSR.LPWRRSTF Field                  */
/** @} */

/** @name AHBRSTR - AHB peripheral reset register */ /** @{ */
#define RCC_AHBRSTR_IOPARST_MASK                 (0x20000U)                                          /**< RCC_AHBRSTR.IOPARST Mask                */
#define RCC_AHBRSTR_IOPARST_SHIFT                (17U)                                               /**< RCC_AHBRSTR.IOPARST Position            */
#define RCC_AHBRSTR_IOPARST(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_AHBRSTR_IOPARST_SHIFT))&RCC_AHBRSTR_IOPARST_MASK) /**< RCC_AHBRSTR.IOPARST Field               */
#define RCC_AHBRSTR_IOPBRST_MASK                 (0x40000U)                                          /**< RCC_AHBRSTR.IOPBRST Mask                */
#define RCC_AHBRSTR_IOPBRST_SHIFT                (18U)                                               /**< RCC_AHBRSTR.IOPBRST Position            */
#define RCC_AHBRSTR_IOPBRST(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_AHBRSTR_IOPBRST_SHIFT))&RCC_AHBRSTR_IOPBRST_MASK) /**< RCC_AHBRSTR.IOPBRST Field               */
#define RCC_AHBRSTR_IOPCRST_MASK                 (0x80000U)                                          /**< RCC_AHBRSTR.IOPCRST Mask                */
#define RCC_AHBRSTR_IOPCRST_SHIFT                (19U)                                               /**< RCC_AHBRSTR.IOPCRST Position            */
#define RCC_AHBRSTR_IOPCRST(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_AHBRSTR_IOPCRST_SHIFT))&RCC_AHBRSTR_IOPCRST_MASK) /**< RCC_AHBRSTR.IOPCRST Field               */
#define RCC_AHBRSTR_IOPDRST_MASK                 (0x100000U)                                         /**< RCC_AHBRSTR.IOPDRST Mask                */
#define RCC_AHBRSTR_IOPDRST_SHIFT                (20U)                                               /**< RCC_AHBRSTR.IOPDRST Position            */
#define RCC_AHBRSTR_IOPDRST(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_AHBRSTR_IOPDRST_SHIFT))&RCC_AHBRSTR_IOPDRST_MASK) /**< RCC_AHBRSTR.IOPDRST Field               */
#define RCC_AHBRSTR_IOPFRST_MASK                 (0x400000U)                                         /**< RCC_AHBRSTR.IOPFRST Mask                */
#define RCC_AHBRSTR_IOPFRST_SHIFT                (22U)                                               /**< RCC_AHBRSTR.IOPFRST Position            */
#define RCC_AHBRSTR_IOPFRST(x)                   (((uint32_t)(((uint32_t)(x))<<RCC_AHBRSTR_IOPFRST_SHIFT))&RCC_AHBRSTR_IOPFRST_MASK) /**< RCC_AHBRSTR.IOPFRST Field               */
/** @} */

/** @name CFGR2 - Clock configuration register 2 */ /** @{ */
#define RCC_CFGR2_PREDIV_MASK                    (0xFU)                                              /**< RCC_CFGR2.PREDIV Mask                   */
#define RCC_CFGR2_PREDIV_SHIFT                   (0U)                                                /**< RCC_CFGR2.PREDIV Position               */
#define RCC_CFGR2_PREDIV(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CFGR2_PREDIV_SHIFT))&RCC_CFGR2_PREDIV_MASK) /**< RCC_CFGR2.PREDIV Field                  */
/** @} */

/** @name CFGR3 - Clock configuration register 3 */ /** @{ */
#define RCC_CFGR3_USART1SW_MASK                  (0x3U)                                              /**< RCC_CFGR3.USART1SW Mask                 */
#define RCC_CFGR3_USART1SW_SHIFT                 (0U)                                                /**< RCC_CFGR3.USART1SW Position             */
#define RCC_CFGR3_USART1SW(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_CFGR3_USART1SW_SHIFT))&RCC_CFGR3_USART1SW_MASK) /**< RCC_CFGR3.USART1SW Field                */
#define RCC_CFGR3_I2C1SW_MASK                    (0x10U)                                             /**< RCC_CFGR3.I2C1SW Mask                   */
#define RCC_CFGR3_I2C1SW_SHIFT                   (4U)                                                /**< RCC_CFGR3.I2C1SW Position               */
#define RCC_CFGR3_I2C1SW(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CFGR3_I2C1SW_SHIFT))&RCC_CFGR3_I2C1SW_MASK) /**< RCC_CFGR3.I2C1SW Field                  */
#define RCC_CFGR3_ADCSW_MASK                     (0x100U)                                            /**< RCC_CFGR3.ADCSW Mask                    */
#define RCC_CFGR3_ADCSW_SHIFT                    (8U)                                                /**< RCC_CFGR3.ADCSW Position                */
#define RCC_CFGR3_ADCSW(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CFGR3_ADCSW_SHIFT))&RCC_CFGR3_ADCSW_MASK) /**< RCC_CFGR3.ADCSW Field                   */
#define RCC_CFGR3_USART2SW_MASK                  (0x30000U)                                          /**< RCC_CFGR3.USART2SW Mask                 */
#define RCC_CFGR3_USART2SW_SHIFT                 (16U)                                               /**< RCC_CFGR3.USART2SW Position             */
#define RCC_CFGR3_USART2SW(x)                    (((uint32_t)(((uint32_t)(x))<<RCC_CFGR3_USART2SW_SHIFT))&RCC_CFGR3_USART2SW_MASK) /**< RCC_CFGR3.USART2SW Field                */
/** @} */

/** @name CR2 - Clock control register 2 */ /** @{ */
#define RCC_CR2_HSI14ON_MASK                     (0x1U)                                              /**< RCC_CR2.HSI14ON Mask                    */
#define RCC_CR2_HSI14ON_SHIFT                    (0U)                                                /**< RCC_CR2.HSI14ON Position                */
#define RCC_CR2_HSI14ON(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CR2_HSI14ON_SHIFT))&RCC_CR2_HSI14ON_MASK) /**< RCC_CR2.HSI14ON Field                   */
#define RCC_CR2_HSI14RDY_MASK                    (0x2U)                                              /**< RCC_CR2.HSI14RDY Mask                   */
#define RCC_CR2_HSI14RDY_SHIFT                   (1U)                                                /**< RCC_CR2.HSI14RDY Position               */
#define RCC_CR2_HSI14RDY(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CR2_HSI14RDY_SHIFT))&RCC_CR2_HSI14RDY_MASK) /**< RCC_CR2.HSI14RDY Field                  */
#define RCC_CR2_HSI14DIS_MASK                    (0x4U)                                              /**< RCC_CR2.HSI14DIS Mask                   */
#define RCC_CR2_HSI14DIS_SHIFT                   (2U)                                                /**< RCC_CR2.HSI14DIS Position               */
#define RCC_CR2_HSI14DIS(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CR2_HSI14DIS_SHIFT))&RCC_CR2_HSI14DIS_MASK) /**< RCC_CR2.HSI14DIS Field                  */
#define RCC_CR2_HSI14TRIM_MASK                   (0xF8U)                                             /**< RCC_CR2.HSI14TRIM Mask                  */
#define RCC_CR2_HSI14TRIM_SHIFT                  (3U)                                                /**< RCC_CR2.HSI14TRIM Position              */
#define RCC_CR2_HSI14TRIM(x)                     (((uint32_t)(((uint32_t)(x))<<RCC_CR2_HSI14TRIM_SHIFT))&RCC_CR2_HSI14TRIM_MASK) /**< RCC_CR2.HSI14TRIM Field                 */
#define RCC_CR2_HSI14CAL_MASK                    (0xFF00U)                                           /**< RCC_CR2.HSI14CAL Mask                   */
#define RCC_CR2_HSI14CAL_SHIFT                   (8U)                                                /**< RCC_CR2.HSI14CAL Position               */
#define RCC_CR2_HSI14CAL(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CR2_HSI14CAL_SHIFT))&RCC_CR2_HSI14CAL_MASK) /**< RCC_CR2.HSI14CAL Field                  */
#define RCC_CR2_HSI48ON_MASK                     (0x10000U)                                          /**< RCC_CR2.HSI48ON Mask                    */
#define RCC_CR2_HSI48ON_SHIFT                    (16U)                                               /**< RCC_CR2.HSI48ON Position                */
#define RCC_CR2_HSI48ON(x)                       (((uint32_t)(((uint32_t)(x))<<RCC_CR2_HSI48ON_SHIFT))&RCC_CR2_HSI48ON_MASK) /**< RCC_CR2.HSI48ON Field                   */
#define RCC_CR2_HSI48RDY_MASK                    (0x20000U)                                          /**< RCC_CR2.HSI48RDY Mask                   */
#define RCC_CR2_HSI48RDY_SHIFT                   (17U)                                               /**< RCC_CR2.HSI48RDY Position               */
#define RCC_CR2_HSI48RDY(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CR2_HSI48RDY_SHIFT))&RCC_CR2_HSI48RDY_MASK) /**< RCC_CR2.HSI48RDY Field                  */
#define RCC_CR2_HSI48CAL_MASK                    (0x1000000U)                                        /**< RCC_CR2.HSI48CAL Mask                   */
#define RCC_CR2_HSI48CAL_SHIFT                   (24U)                                               /**< RCC_CR2.HSI48CAL Position               */
#define RCC_CR2_HSI48CAL(x)                      (((uint32_t)(((uint32_t)(x))<<RCC_CR2_HSI48CAL_SHIFT))&RCC_CR2_HSI48CAL_MASK) /**< RCC_CR2.HSI48CAL Field                  */
/** @} */

/** @} */ /* End group RCC_Register_Masks_GROUP */


/* RCC - Peripheral instance base addresses */
#define RCC_BasePtr                    0x40021000UL //!< Peripheral base address
#define RCC                            ((RCC_Type *) RCC_BasePtr) //!< Freescale base pointer
#define RCC_BASE_PTR                   (RCC) //!< Freescale style base pointer
#define RCC_IRQS { PVD_IRQn, EXTI0_1_IRQn, EXTI2_3_IRQn, EXTI4_15_IRQn,  }


/** @} */ /* End group RCC_Peripheral_access_layer_GROUP */


/** @brief C Struct for RTC */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           RTC (file:RTC_STM32F030)             ================ */
/* ================================================================================ */

/**
 * @brief Real-time clock
 */
/**
 * @struct RTC_Type
 * @brief  C Struct allowing access to RTC registers
 */
typedef struct RTC_Type {
   __IO uint32_t  TR;                           /**< 0000: time register                                                */
   __IO uint32_t  DR;                           /**< 0004: date register                                                */
   __IO uint32_t  CR;                           /**< 0008: control register                                             */
   __IO uint32_t  ISR;                          /**< 000C: initialization and status                                    */
   __IO uint32_t  PRER;                         /**< 0010: prescaler register                                           */
        uint8_t   RESERVED_0[8];                /**< 0014: 0x8 bytes                                                    */
   __IO uint32_t  ALRMAR;                       /**< 001C: alarm A register                                             */
        uint8_t   RESERVED_1[4];                /**< 0020: 0x4 bytes                                                    */
   __O  uint32_t  WPR;                          /**< 0024: write protection register                                    */
   __I  uint32_t  SSR;                          /**< 0028: sub second register                                          */
   __O  uint32_t  SHIFTR;                       /**< 002C: shift control register                                       */
   __I  uint32_t  TSTR;                         /**< 0030: timestamp time register                                      */
   __I  uint32_t  TSDR;                         /**< 0034: timestamp date register                                      */
   __I  uint32_t  TSSSR;                        /**< 0038: time-stamp sub second register                               */
   __IO uint32_t  CALR;                         /**< 003C: calibration register                                         */
   __IO uint32_t  TAFCR;                        /**< 0040: tamper and alternate function configuration                  */
   __IO uint32_t  ALRMASSR;                     /**< 0044: alarm A sub second register                                  */
        uint8_t   RESERVED_2[8];                /**< 0048: 0x8 bytes                                                    */
   __IO uint32_t  BKP0R;                        /**< 0050: backup register                                              */
   __IO uint32_t  BKP1R;                        /**< 0054: backup register                                              */
   __IO uint32_t  BKP2R;                        /**< 0058: backup register                                              */
   __IO uint32_t  BKP3R;                        /**< 005C: backup register                                              */
   __IO uint32_t  BKP4R;                        /**< 0060: backup register                                              */
} RTC_Type;


/** @brief Register Masks for RTC */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup RTC_Register_Masks_GROUP RTC Register Masks */
/** @{ */

/** @name TR - time register */ /** @{ */
#define RTC_TR_SU_MASK                           (0xFU)                                              /**< RTC_TR.SU Mask                          */
#define RTC_TR_SU_SHIFT                          (0U)                                                /**< RTC_TR.SU Position                      */
#define RTC_TR_SU(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_TR_SU_SHIFT))&RTC_TR_SU_MASK) /**< RTC_TR.SU Field                         */
#define RTC_TR_ST_MASK                           (0x70U)                                             /**< RTC_TR.ST Mask                          */
#define RTC_TR_ST_SHIFT                          (4U)                                                /**< RTC_TR.ST Position                      */
#define RTC_TR_ST(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_TR_ST_SHIFT))&RTC_TR_ST_MASK) /**< RTC_TR.ST Field                         */
#define RTC_TR_MNU_MASK                          (0xF00U)                                            /**< RTC_TR.MNU Mask                         */
#define RTC_TR_MNU_SHIFT                         (8U)                                                /**< RTC_TR.MNU Position                     */
#define RTC_TR_MNU(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_TR_MNU_SHIFT))&RTC_TR_MNU_MASK) /**< RTC_TR.MNU Field                        */
#define RTC_TR_MNT_MASK                          (0x7000U)                                           /**< RTC_TR.MNT Mask                         */
#define RTC_TR_MNT_SHIFT                         (12U)                                               /**< RTC_TR.MNT Position                     */
#define RTC_TR_MNT(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_TR_MNT_SHIFT))&RTC_TR_MNT_MASK) /**< RTC_TR.MNT Field                        */
#define RTC_TR_HU_MASK                           (0xF0000U)                                          /**< RTC_TR.HU Mask                          */
#define RTC_TR_HU_SHIFT                          (16U)                                               /**< RTC_TR.HU Position                      */
#define RTC_TR_HU(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_TR_HU_SHIFT))&RTC_TR_HU_MASK) /**< RTC_TR.HU Field                         */
#define RTC_TR_HT_MASK                           (0x300000U)                                         /**< RTC_TR.HT Mask                          */
#define RTC_TR_HT_SHIFT                          (20U)                                               /**< RTC_TR.HT Position                      */
#define RTC_TR_HT(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_TR_HT_SHIFT))&RTC_TR_HT_MASK) /**< RTC_TR.HT Field                         */
#define RTC_TR_PM_MASK                           (0x400000U)                                         /**< RTC_TR.PM Mask                          */
#define RTC_TR_PM_SHIFT                          (22U)                                               /**< RTC_TR.PM Position                      */
#define RTC_TR_PM(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_TR_PM_SHIFT))&RTC_TR_PM_MASK) /**< RTC_TR.PM Field                         */
/** @} */

/** @name DR - date register */ /** @{ */
#define RTC_DR_DU_MASK                           (0xFU)                                              /**< RTC_DR.DU Mask                          */
#define RTC_DR_DU_SHIFT                          (0U)                                                /**< RTC_DR.DU Position                      */
#define RTC_DR_DU(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_DR_DU_SHIFT))&RTC_DR_DU_MASK) /**< RTC_DR.DU Field                         */
#define RTC_DR_DT_MASK                           (0x30U)                                             /**< RTC_DR.DT Mask                          */
#define RTC_DR_DT_SHIFT                          (4U)                                                /**< RTC_DR.DT Position                      */
#define RTC_DR_DT(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_DR_DT_SHIFT))&RTC_DR_DT_MASK) /**< RTC_DR.DT Field                         */
#define RTC_DR_MU_MASK                           (0xF00U)                                            /**< RTC_DR.MU Mask                          */
#define RTC_DR_MU_SHIFT                          (8U)                                                /**< RTC_DR.MU Position                      */
#define RTC_DR_MU(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_DR_MU_SHIFT))&RTC_DR_MU_MASK) /**< RTC_DR.MU Field                         */
#define RTC_DR_MT_MASK                           (0x1000U)                                           /**< RTC_DR.MT Mask                          */
#define RTC_DR_MT_SHIFT                          (12U)                                               /**< RTC_DR.MT Position                      */
#define RTC_DR_MT(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_DR_MT_SHIFT))&RTC_DR_MT_MASK) /**< RTC_DR.MT Field                         */
#define RTC_DR_WDU_MASK                          (0xE000U)                                           /**< RTC_DR.WDU Mask                         */
#define RTC_DR_WDU_SHIFT                         (13U)                                               /**< RTC_DR.WDU Position                     */
#define RTC_DR_WDU(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_DR_WDU_SHIFT))&RTC_DR_WDU_MASK) /**< RTC_DR.WDU Field                        */
#define RTC_DR_YU_MASK                           (0xF0000U)                                          /**< RTC_DR.YU Mask                          */
#define RTC_DR_YU_SHIFT                          (16U)                                               /**< RTC_DR.YU Position                      */
#define RTC_DR_YU(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_DR_YU_SHIFT))&RTC_DR_YU_MASK) /**< RTC_DR.YU Field                         */
#define RTC_DR_YT_MASK                           (0xF00000U)                                         /**< RTC_DR.YT Mask                          */
#define RTC_DR_YT_SHIFT                          (20U)                                               /**< RTC_DR.YT Position                      */
#define RTC_DR_YT(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_DR_YT_SHIFT))&RTC_DR_YT_MASK) /**< RTC_DR.YT Field                         */
/** @} */

/** @name CR - control register */ /** @{ */
#define RTC_CR_TSEDGE_MASK                       (0x8U)                                              /**< RTC_CR.TSEDGE Mask                      */
#define RTC_CR_TSEDGE_SHIFT                      (3U)                                                /**< RTC_CR.TSEDGE Position                  */
#define RTC_CR_TSEDGE(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_CR_TSEDGE_SHIFT))&RTC_CR_TSEDGE_MASK) /**< RTC_CR.TSEDGE Field                     */
#define RTC_CR_REFCKON_MASK                      (0x10U)                                             /**< RTC_CR.REFCKON Mask                     */
#define RTC_CR_REFCKON_SHIFT                     (4U)                                                /**< RTC_CR.REFCKON Position                 */
#define RTC_CR_REFCKON(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_CR_REFCKON_SHIFT))&RTC_CR_REFCKON_MASK) /**< RTC_CR.REFCKON Field                    */
#define RTC_CR_BYPSHAD_MASK                      (0x20U)                                             /**< RTC_CR.BYPSHAD Mask                     */
#define RTC_CR_BYPSHAD_SHIFT                     (5U)                                                /**< RTC_CR.BYPSHAD Position                 */
#define RTC_CR_BYPSHAD(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_CR_BYPSHAD_SHIFT))&RTC_CR_BYPSHAD_MASK) /**< RTC_CR.BYPSHAD Field                    */
#define RTC_CR_FMT_MASK                          (0x40U)                                             /**< RTC_CR.FMT Mask                         */
#define RTC_CR_FMT_SHIFT                         (6U)                                                /**< RTC_CR.FMT Position                     */
#define RTC_CR_FMT(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_FMT_SHIFT))&RTC_CR_FMT_MASK) /**< RTC_CR.FMT Field                        */
#define RTC_CR_ALRAE_MASK                        (0x100U)                                            /**< RTC_CR.ALRAE Mask                       */
#define RTC_CR_ALRAE_SHIFT                       (8U)                                                /**< RTC_CR.ALRAE Position                   */
#define RTC_CR_ALRAE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_ALRAE_SHIFT))&RTC_CR_ALRAE_MASK) /**< RTC_CR.ALRAE Field                      */
#define RTC_CR_TSE_MASK                          (0x800U)                                            /**< RTC_CR.TSE Mask                         */
#define RTC_CR_TSE_SHIFT                         (11U)                                               /**< RTC_CR.TSE Position                     */
#define RTC_CR_TSE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_TSE_SHIFT))&RTC_CR_TSE_MASK) /**< RTC_CR.TSE Field                        */
#define RTC_CR_ALRAIE_MASK                       (0x1000U)                                           /**< RTC_CR.ALRAIE Mask                      */
#define RTC_CR_ALRAIE_SHIFT                      (12U)                                               /**< RTC_CR.ALRAIE Position                  */
#define RTC_CR_ALRAIE(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_CR_ALRAIE_SHIFT))&RTC_CR_ALRAIE_MASK) /**< RTC_CR.ALRAIE Field                     */
#define RTC_CR_TSIE_MASK                         (0x8000U)                                           /**< RTC_CR.TSIE Mask                        */
#define RTC_CR_TSIE_SHIFT                        (15U)                                               /**< RTC_CR.TSIE Position                    */
#define RTC_CR_TSIE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_TSIE_SHIFT))&RTC_CR_TSIE_MASK) /**< RTC_CR.TSIE Field                       */
#define RTC_CR_ADD1H_MASK                        (0x10000U)                                          /**< RTC_CR.ADD1H Mask                       */
#define RTC_CR_ADD1H_SHIFT                       (16U)                                               /**< RTC_CR.ADD1H Position                   */
#define RTC_CR_ADD1H(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_ADD1H_SHIFT))&RTC_CR_ADD1H_MASK) /**< RTC_CR.ADD1H Field                      */
#define RTC_CR_SUB1H_MASK                        (0x20000U)                                          /**< RTC_CR.SUB1H Mask                       */
#define RTC_CR_SUB1H_SHIFT                       (17U)                                               /**< RTC_CR.SUB1H Position                   */
#define RTC_CR_SUB1H(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_SUB1H_SHIFT))&RTC_CR_SUB1H_MASK) /**< RTC_CR.SUB1H Field                      */
#define RTC_CR_BKP_MASK                          (0x40000U)                                          /**< RTC_CR.BKP Mask                         */
#define RTC_CR_BKP_SHIFT                         (18U)                                               /**< RTC_CR.BKP Position                     */
#define RTC_CR_BKP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_BKP_SHIFT))&RTC_CR_BKP_MASK) /**< RTC_CR.BKP Field                        */
#define RTC_CR_COSEL_MASK                        (0x80000U)                                          /**< RTC_CR.COSEL Mask                       */
#define RTC_CR_COSEL_SHIFT                       (19U)                                               /**< RTC_CR.COSEL Position                   */
#define RTC_CR_COSEL(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_COSEL_SHIFT))&RTC_CR_COSEL_MASK) /**< RTC_CR.COSEL Field                      */
#define RTC_CR_POL_MASK                          (0x100000U)                                         /**< RTC_CR.POL Mask                         */
#define RTC_CR_POL_SHIFT                         (20U)                                               /**< RTC_CR.POL Position                     */
#define RTC_CR_POL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_POL_SHIFT))&RTC_CR_POL_MASK) /**< RTC_CR.POL Field                        */
#define RTC_CR_OSEL_MASK                         (0x600000U)                                         /**< RTC_CR.OSEL Mask                        */
#define RTC_CR_OSEL_SHIFT                        (21U)                                               /**< RTC_CR.OSEL Position                    */
#define RTC_CR_OSEL(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_OSEL_SHIFT))&RTC_CR_OSEL_MASK) /**< RTC_CR.OSEL Field                       */
#define RTC_CR_COE_MASK                          (0x800000U)                                         /**< RTC_CR.COE Mask                         */
#define RTC_CR_COE_SHIFT                         (23U)                                               /**< RTC_CR.COE Position                     */
#define RTC_CR_COE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_COE_SHIFT))&RTC_CR_COE_MASK) /**< RTC_CR.COE Field                        */
/** @} */

/** @name ISR - initialization and status */ /** @{ */
#define RTC_ISR_ALRAWF_MASK                      (0x1U)                                              /**< RTC_ISR.ALRAWF Mask                     */
#define RTC_ISR_ALRAWF_SHIFT                     (0U)                                                /**< RTC_ISR.ALRAWF Position                 */
#define RTC_ISR_ALRAWF(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_ISR_ALRAWF_SHIFT))&RTC_ISR_ALRAWF_MASK) /**< RTC_ISR.ALRAWF Field                    */
#define RTC_ISR_SHPF_MASK                        (0x8U)                                              /**< RTC_ISR.SHPF Mask                       */
#define RTC_ISR_SHPF_SHIFT                       (3U)                                                /**< RTC_ISR.SHPF Position                   */
#define RTC_ISR_SHPF(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_ISR_SHPF_SHIFT))&RTC_ISR_SHPF_MASK) /**< RTC_ISR.SHPF Field                      */
#define RTC_ISR_INITS_MASK                       (0x10U)                                             /**< RTC_ISR.INITS Mask                      */
#define RTC_ISR_INITS_SHIFT                      (4U)                                                /**< RTC_ISR.INITS Position                  */
#define RTC_ISR_INITS(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ISR_INITS_SHIFT))&RTC_ISR_INITS_MASK) /**< RTC_ISR.INITS Field                     */
#define RTC_ISR_RSF_MASK                         (0x20U)                                             /**< RTC_ISR.RSF Mask                        */
#define RTC_ISR_RSF_SHIFT                        (5U)                                                /**< RTC_ISR.RSF Position                    */
#define RTC_ISR_RSF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_ISR_RSF_SHIFT))&RTC_ISR_RSF_MASK) /**< RTC_ISR.RSF Field                       */
#define RTC_ISR_INITF_MASK                       (0x40U)                                             /**< RTC_ISR.INITF Mask                      */
#define RTC_ISR_INITF_SHIFT                      (6U)                                                /**< RTC_ISR.INITF Position                  */
#define RTC_ISR_INITF(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ISR_INITF_SHIFT))&RTC_ISR_INITF_MASK) /**< RTC_ISR.INITF Field                     */
#define RTC_ISR_INIT_MASK                        (0x80U)                                             /**< RTC_ISR.INIT Mask                       */
#define RTC_ISR_INIT_SHIFT                       (7U)                                                /**< RTC_ISR.INIT Position                   */
#define RTC_ISR_INIT(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_ISR_INIT_SHIFT))&RTC_ISR_INIT_MASK) /**< RTC_ISR.INIT Field                      */
#define RTC_ISR_ALRAF_MASK                       (0x100U)                                            /**< RTC_ISR.ALRAF Mask                      */
#define RTC_ISR_ALRAF_SHIFT                      (8U)                                                /**< RTC_ISR.ALRAF Position                  */
#define RTC_ISR_ALRAF(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ISR_ALRAF_SHIFT))&RTC_ISR_ALRAF_MASK) /**< RTC_ISR.ALRAF Field                     */
#define RTC_ISR_TSF_MASK                         (0x800U)                                            /**< RTC_ISR.TSF Mask                        */
#define RTC_ISR_TSF_SHIFT                        (11U)                                               /**< RTC_ISR.TSF Position                    */
#define RTC_ISR_TSF(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_ISR_TSF_SHIFT))&RTC_ISR_TSF_MASK) /**< RTC_ISR.TSF Field                       */
#define RTC_ISR_TSOVF_MASK                       (0x1000U)                                           /**< RTC_ISR.TSOVF Mask                      */
#define RTC_ISR_TSOVF_SHIFT                      (12U)                                               /**< RTC_ISR.TSOVF Position                  */
#define RTC_ISR_TSOVF(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ISR_TSOVF_SHIFT))&RTC_ISR_TSOVF_MASK) /**< RTC_ISR.TSOVF Field                     */
#define RTC_ISR_TAMP1F_MASK                      (0x2000U)                                           /**< RTC_ISR.TAMP1F Mask                     */
#define RTC_ISR_TAMP1F_SHIFT                     (13U)                                               /**< RTC_ISR.TAMP1F Position                 */
#define RTC_ISR_TAMP1F(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_ISR_TAMP1F_SHIFT))&RTC_ISR_TAMP1F_MASK) /**< RTC_ISR.TAMP1F Field                    */
#define RTC_ISR_TAMP2F_MASK                      (0x4000U)                                           /**< RTC_ISR.TAMP2F Mask                     */
#define RTC_ISR_TAMP2F_SHIFT                     (14U)                                               /**< RTC_ISR.TAMP2F Position                 */
#define RTC_ISR_TAMP2F(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_ISR_TAMP2F_SHIFT))&RTC_ISR_TAMP2F_MASK) /**< RTC_ISR.TAMP2F Field                    */
#define RTC_ISR_RECALPF_MASK                     (0x10000U)                                          /**< RTC_ISR.RECALPF Mask                    */
#define RTC_ISR_RECALPF_SHIFT                    (16U)                                               /**< RTC_ISR.RECALPF Position                */
#define RTC_ISR_RECALPF(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_ISR_RECALPF_SHIFT))&RTC_ISR_RECALPF_MASK) /**< RTC_ISR.RECALPF Field                   */
/** @} */

/** @name PRER - prescaler register */ /** @{ */
#define RTC_PRER_PREDIV_S_MASK                   (0x7FFFU)                                           /**< RTC_PRER.PREDIV_S Mask                  */
#define RTC_PRER_PREDIV_S_SHIFT                  (0U)                                                /**< RTC_PRER.PREDIV_S Position              */
#define RTC_PRER_PREDIV_S(x)                     (((uint32_t)(((uint32_t)(x))<<RTC_PRER_PREDIV_S_SHIFT))&RTC_PRER_PREDIV_S_MASK) /**< RTC_PRER.PREDIV_S Field                 */
#define RTC_PRER_PREDIV_A_MASK                   (0x7F0000U)                                         /**< RTC_PRER.PREDIV_A Mask                  */
#define RTC_PRER_PREDIV_A_SHIFT                  (16U)                                               /**< RTC_PRER.PREDIV_A Position              */
#define RTC_PRER_PREDIV_A(x)                     (((uint32_t)(((uint32_t)(x))<<RTC_PRER_PREDIV_A_SHIFT))&RTC_PRER_PREDIV_A_MASK) /**< RTC_PRER.PREDIV_A Field                 */
/** @} */

/** @name ALRMAR - alarm A register */ /** @{ */
#define RTC_ALRMAR_SU_MASK                       (0xFU)                                              /**< RTC_ALRMAR.SU Mask                      */
#define RTC_ALRMAR_SU_SHIFT                      (0U)                                                /**< RTC_ALRMAR.SU Position                  */
#define RTC_ALRMAR_SU(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_SU_SHIFT))&RTC_ALRMAR_SU_MASK) /**< RTC_ALRMAR.SU Field                     */
#define RTC_ALRMAR_ST_MASK                       (0x70U)                                             /**< RTC_ALRMAR.ST Mask                      */
#define RTC_ALRMAR_ST_SHIFT                      (4U)                                                /**< RTC_ALRMAR.ST Position                  */
#define RTC_ALRMAR_ST(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_ST_SHIFT))&RTC_ALRMAR_ST_MASK) /**< RTC_ALRMAR.ST Field                     */
#define RTC_ALRMAR_MSK1_MASK                     (0x80U)                                             /**< RTC_ALRMAR.MSK1 Mask                    */
#define RTC_ALRMAR_MSK1_SHIFT                    (7U)                                                /**< RTC_ALRMAR.MSK1 Position                */
#define RTC_ALRMAR_MSK1(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_MSK1_SHIFT))&RTC_ALRMAR_MSK1_MASK) /**< RTC_ALRMAR.MSK1 Field                   */
#define RTC_ALRMAR_MNU_MASK                      (0xF00U)                                            /**< RTC_ALRMAR.MNU Mask                     */
#define RTC_ALRMAR_MNU_SHIFT                     (8U)                                                /**< RTC_ALRMAR.MNU Position                 */
#define RTC_ALRMAR_MNU(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_MNU_SHIFT))&RTC_ALRMAR_MNU_MASK) /**< RTC_ALRMAR.MNU Field                    */
#define RTC_ALRMAR_MNT_MASK                      (0x7000U)                                           /**< RTC_ALRMAR.MNT Mask                     */
#define RTC_ALRMAR_MNT_SHIFT                     (12U)                                               /**< RTC_ALRMAR.MNT Position                 */
#define RTC_ALRMAR_MNT(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_MNT_SHIFT))&RTC_ALRMAR_MNT_MASK) /**< RTC_ALRMAR.MNT Field                    */
#define RTC_ALRMAR_MSK2_MASK                     (0x8000U)                                           /**< RTC_ALRMAR.MSK2 Mask                    */
#define RTC_ALRMAR_MSK2_SHIFT                    (15U)                                               /**< RTC_ALRMAR.MSK2 Position                */
#define RTC_ALRMAR_MSK2(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_MSK2_SHIFT))&RTC_ALRMAR_MSK2_MASK) /**< RTC_ALRMAR.MSK2 Field                   */
#define RTC_ALRMAR_HU_MASK                       (0xF0000U)                                          /**< RTC_ALRMAR.HU Mask                      */
#define RTC_ALRMAR_HU_SHIFT                      (16U)                                               /**< RTC_ALRMAR.HU Position                  */
#define RTC_ALRMAR_HU(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_HU_SHIFT))&RTC_ALRMAR_HU_MASK) /**< RTC_ALRMAR.HU Field                     */
#define RTC_ALRMAR_HT_MASK                       (0x300000U)                                         /**< RTC_ALRMAR.HT Mask                      */
#define RTC_ALRMAR_HT_SHIFT                      (20U)                                               /**< RTC_ALRMAR.HT Position                  */
#define RTC_ALRMAR_HT(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_HT_SHIFT))&RTC_ALRMAR_HT_MASK) /**< RTC_ALRMAR.HT Field                     */
#define RTC_ALRMAR_PM_MASK                       (0x400000U)                                         /**< RTC_ALRMAR.PM Mask                      */
#define RTC_ALRMAR_PM_SHIFT                      (22U)                                               /**< RTC_ALRMAR.PM Position                  */
#define RTC_ALRMAR_PM(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_PM_SHIFT))&RTC_ALRMAR_PM_MASK) /**< RTC_ALRMAR.PM Field                     */
#define RTC_ALRMAR_MSK3_MASK                     (0x800000U)                                         /**< RTC_ALRMAR.MSK3 Mask                    */
#define RTC_ALRMAR_MSK3_SHIFT                    (23U)                                               /**< RTC_ALRMAR.MSK3 Position                */
#define RTC_ALRMAR_MSK3(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_MSK3_SHIFT))&RTC_ALRMAR_MSK3_MASK) /**< RTC_ALRMAR.MSK3 Field                   */
#define RTC_ALRMAR_DU_MASK                       (0xF000000U)                                        /**< RTC_ALRMAR.DU Mask                      */
#define RTC_ALRMAR_DU_SHIFT                      (24U)                                               /**< RTC_ALRMAR.DU Position                  */
#define RTC_ALRMAR_DU(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_DU_SHIFT))&RTC_ALRMAR_DU_MASK) /**< RTC_ALRMAR.DU Field                     */
#define RTC_ALRMAR_DT_MASK                       (0x30000000U)                                       /**< RTC_ALRMAR.DT Mask                      */
#define RTC_ALRMAR_DT_SHIFT                      (28U)                                               /**< RTC_ALRMAR.DT Position                  */
#define RTC_ALRMAR_DT(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_DT_SHIFT))&RTC_ALRMAR_DT_MASK) /**< RTC_ALRMAR.DT Field                     */
#define RTC_ALRMAR_WDSEL_MASK                    (0x40000000U)                                       /**< RTC_ALRMAR.WDSEL Mask                   */
#define RTC_ALRMAR_WDSEL_SHIFT                   (30U)                                               /**< RTC_ALRMAR.WDSEL Position               */
#define RTC_ALRMAR_WDSEL(x)                      (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_WDSEL_SHIFT))&RTC_ALRMAR_WDSEL_MASK) /**< RTC_ALRMAR.WDSEL Field                  */
#define RTC_ALRMAR_MSK4_MASK                     (0x80000000U)                                       /**< RTC_ALRMAR.MSK4 Mask                    */
#define RTC_ALRMAR_MSK4_SHIFT                    (31U)                                               /**< RTC_ALRMAR.MSK4 Position                */
#define RTC_ALRMAR_MSK4(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_ALRMAR_MSK4_SHIFT))&RTC_ALRMAR_MSK4_MASK) /**< RTC_ALRMAR.MSK4 Field                   */
/** @} */

/** @name WPR - write protection register */ /** @{ */
#define RTC_WPR_KEY_MASK                         (0xFFU)                                             /**< RTC_WPR.KEY Mask                        */
#define RTC_WPR_KEY_SHIFT                        (0U)                                                /**< RTC_WPR.KEY Position                    */
#define RTC_WPR_KEY(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_WPR_KEY_SHIFT))&RTC_WPR_KEY_MASK) /**< RTC_WPR.KEY Field                       */
/** @} */

/** @name SSR - sub second register */ /** @{ */
#define RTC_SSR_SS_MASK                          (0xFFFFU)                                           /**< RTC_SSR.SS Mask                         */
#define RTC_SSR_SS_SHIFT                         (0U)                                                /**< RTC_SSR.SS Position                     */
#define RTC_SSR_SS(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SSR_SS_SHIFT))&RTC_SSR_SS_MASK) /**< RTC_SSR.SS Field                        */
/** @} */

/** @name SHIFTR - shift control register */ /** @{ */
#define RTC_SHIFTR_SUBFS_MASK                    (0x7FFFU)                                           /**< RTC_SHIFTR.SUBFS Mask                   */
#define RTC_SHIFTR_SUBFS_SHIFT                   (0U)                                                /**< RTC_SHIFTR.SUBFS Position               */
#define RTC_SHIFTR_SUBFS(x)                      (((uint32_t)(((uint32_t)(x))<<RTC_SHIFTR_SUBFS_SHIFT))&RTC_SHIFTR_SUBFS_MASK) /**< RTC_SHIFTR.SUBFS Field                  */
#define RTC_SHIFTR_ADD1S_MASK                    (0x80000000U)                                       /**< RTC_SHIFTR.ADD1S Mask                   */
#define RTC_SHIFTR_ADD1S_SHIFT                   (31U)                                               /**< RTC_SHIFTR.ADD1S Position               */
#define RTC_SHIFTR_ADD1S(x)                      (((uint32_t)(((uint32_t)(x))<<RTC_SHIFTR_ADD1S_SHIFT))&RTC_SHIFTR_ADD1S_MASK) /**< RTC_SHIFTR.ADD1S Field                  */
/** @} */

/** @name TSTR - timestamp time register */ /** @{ */
#define RTC_TSTR_SU_MASK                         (0xFU)                                              /**< RTC_TSTR.SU Mask                        */
#define RTC_TSTR_SU_SHIFT                        (0U)                                                /**< RTC_TSTR.SU Position                    */
#define RTC_TSTR_SU(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSTR_SU_SHIFT))&RTC_TSTR_SU_MASK) /**< RTC_TSTR.SU Field                       */
#define RTC_TSTR_ST_MASK                         (0x70U)                                             /**< RTC_TSTR.ST Mask                        */
#define RTC_TSTR_ST_SHIFT                        (4U)                                                /**< RTC_TSTR.ST Position                    */
#define RTC_TSTR_ST(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSTR_ST_SHIFT))&RTC_TSTR_ST_MASK) /**< RTC_TSTR.ST Field                       */
#define RTC_TSTR_MNU_MASK                        (0xF00U)                                            /**< RTC_TSTR.MNU Mask                       */
#define RTC_TSTR_MNU_SHIFT                       (8U)                                                /**< RTC_TSTR.MNU Position                   */
#define RTC_TSTR_MNU(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TSTR_MNU_SHIFT))&RTC_TSTR_MNU_MASK) /**< RTC_TSTR.MNU Field                      */
#define RTC_TSTR_MNT_MASK                        (0x7000U)                                           /**< RTC_TSTR.MNT Mask                       */
#define RTC_TSTR_MNT_SHIFT                       (12U)                                               /**< RTC_TSTR.MNT Position                   */
#define RTC_TSTR_MNT(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TSTR_MNT_SHIFT))&RTC_TSTR_MNT_MASK) /**< RTC_TSTR.MNT Field                      */
#define RTC_TSTR_HU_MASK                         (0xF0000U)                                          /**< RTC_TSTR.HU Mask                        */
#define RTC_TSTR_HU_SHIFT                        (16U)                                               /**< RTC_TSTR.HU Position                    */
#define RTC_TSTR_HU(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSTR_HU_SHIFT))&RTC_TSTR_HU_MASK) /**< RTC_TSTR.HU Field                       */
#define RTC_TSTR_HT_MASK                         (0x300000U)                                         /**< RTC_TSTR.HT Mask                        */
#define RTC_TSTR_HT_SHIFT                        (20U)                                               /**< RTC_TSTR.HT Position                    */
#define RTC_TSTR_HT(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSTR_HT_SHIFT))&RTC_TSTR_HT_MASK) /**< RTC_TSTR.HT Field                       */
#define RTC_TSTR_PM_MASK                         (0x400000U)                                         /**< RTC_TSTR.PM Mask                        */
#define RTC_TSTR_PM_SHIFT                        (22U)                                               /**< RTC_TSTR.PM Position                    */
#define RTC_TSTR_PM(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSTR_PM_SHIFT))&RTC_TSTR_PM_MASK) /**< RTC_TSTR.PM Field                       */
/** @} */

/** @name TSDR - timestamp date register */ /** @{ */
#define RTC_TSDR_DU_MASK                         (0xFU)                                              /**< RTC_TSDR.DU Mask                        */
#define RTC_TSDR_DU_SHIFT                        (0U)                                                /**< RTC_TSDR.DU Position                    */
#define RTC_TSDR_DU(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSDR_DU_SHIFT))&RTC_TSDR_DU_MASK) /**< RTC_TSDR.DU Field                       */
#define RTC_TSDR_DT_MASK                         (0x30U)                                             /**< RTC_TSDR.DT Mask                        */
#define RTC_TSDR_DT_SHIFT                        (4U)                                                /**< RTC_TSDR.DT Position                    */
#define RTC_TSDR_DT(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSDR_DT_SHIFT))&RTC_TSDR_DT_MASK) /**< RTC_TSDR.DT Field                       */
#define RTC_TSDR_MU_MASK                         (0xF00U)                                            /**< RTC_TSDR.MU Mask                        */
#define RTC_TSDR_MU_SHIFT                        (8U)                                                /**< RTC_TSDR.MU Position                    */
#define RTC_TSDR_MU(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSDR_MU_SHIFT))&RTC_TSDR_MU_MASK) /**< RTC_TSDR.MU Field                       */
#define RTC_TSDR_MT_MASK                         (0x1000U)                                           /**< RTC_TSDR.MT Mask                        */
#define RTC_TSDR_MT_SHIFT                        (12U)                                               /**< RTC_TSDR.MT Position                    */
#define RTC_TSDR_MT(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSDR_MT_SHIFT))&RTC_TSDR_MT_MASK) /**< RTC_TSDR.MT Field                       */
#define RTC_TSDR_WDU_MASK                        (0xE000U)                                           /**< RTC_TSDR.WDU Mask                       */
#define RTC_TSDR_WDU_SHIFT                       (13U)                                               /**< RTC_TSDR.WDU Position                   */
#define RTC_TSDR_WDU(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TSDR_WDU_SHIFT))&RTC_TSDR_WDU_MASK) /**< RTC_TSDR.WDU Field                      */
/** @} */

/** @name TSSSR - time-stamp sub second register */ /** @{ */
#define RTC_TSSSR_SS_MASK                        (0xFFFFU)                                           /**< RTC_TSSSR.SS Mask                       */
#define RTC_TSSSR_SS_SHIFT                       (0U)                                                /**< RTC_TSSSR.SS Position                   */
#define RTC_TSSSR_SS(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_TSSSR_SS_SHIFT))&RTC_TSSSR_SS_MASK) /**< RTC_TSSSR.SS Field                      */
/** @} */

/** @name CALR - calibration register */ /** @{ */
#define RTC_CALR_CALM_MASK                       (0x1FFU)                                            /**< RTC_CALR.CALM Mask                      */
#define RTC_CALR_CALM_SHIFT                      (0U)                                                /**< RTC_CALR.CALM Position                  */
#define RTC_CALR_CALM(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_CALR_CALM_SHIFT))&RTC_CALR_CALM_MASK) /**< RTC_CALR.CALM Field                     */
#define RTC_CALR_CALW16_MASK                     (0x2000U)                                           /**< RTC_CALR.CALW16 Mask                    */
#define RTC_CALR_CALW16_SHIFT                    (13U)                                               /**< RTC_CALR.CALW16 Position                */
#define RTC_CALR_CALW16(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_CALR_CALW16_SHIFT))&RTC_CALR_CALW16_MASK) /**< RTC_CALR.CALW16 Field                   */
#define RTC_CALR_CALW8_MASK                      (0x4000U)                                           /**< RTC_CALR.CALW8 Mask                     */
#define RTC_CALR_CALW8_SHIFT                     (14U)                                               /**< RTC_CALR.CALW8 Position                 */
#define RTC_CALR_CALW8(x)                        (((uint32_t)(((uint32_t)(x))<<RTC_CALR_CALW8_SHIFT))&RTC_CALR_CALW8_MASK) /**< RTC_CALR.CALW8 Field                    */
#define RTC_CALR_CALP_MASK                       (0x8000U)                                           /**< RTC_CALR.CALP Mask                      */
#define RTC_CALR_CALP_SHIFT                      (15U)                                               /**< RTC_CALR.CALP Position                  */
#define RTC_CALR_CALP(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_CALR_CALP_SHIFT))&RTC_CALR_CALP_MASK) /**< RTC_CALR.CALP Field                     */
/** @} */

/** @name TAFCR - tamper and alternate function configuration */ /** @{ */
#define RTC_TAFCR_TAMP1E_MASK                    (0x1U)                                              /**< RTC_TAFCR.TAMP1E Mask                   */
#define RTC_TAFCR_TAMP1E_SHIFT                   (0U)                                                /**< RTC_TAFCR.TAMP1E Position               */
#define RTC_TAFCR_TAMP1E(x)                      (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMP1E_SHIFT))&RTC_TAFCR_TAMP1E_MASK) /**< RTC_TAFCR.TAMP1E Field                  */
#define RTC_TAFCR_TAMP1TRG_MASK                  (0x2U)                                              /**< RTC_TAFCR.TAMP1TRG Mask                 */
#define RTC_TAFCR_TAMP1TRG_SHIFT                 (1U)                                                /**< RTC_TAFCR.TAMP1TRG Position             */
#define RTC_TAFCR_TAMP1TRG(x)                    (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMP1TRG_SHIFT))&RTC_TAFCR_TAMP1TRG_MASK) /**< RTC_TAFCR.TAMP1TRG Field                */
#define RTC_TAFCR_TAMPIE_MASK                    (0x4U)                                              /**< RTC_TAFCR.TAMPIE Mask                   */
#define RTC_TAFCR_TAMPIE_SHIFT                   (2U)                                                /**< RTC_TAFCR.TAMPIE Position               */
#define RTC_TAFCR_TAMPIE(x)                      (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMPIE_SHIFT))&RTC_TAFCR_TAMPIE_MASK) /**< RTC_TAFCR.TAMPIE Field                  */
#define RTC_TAFCR_TAMP2E_MASK                    (0x8U)                                              /**< RTC_TAFCR.TAMP2E Mask                   */
#define RTC_TAFCR_TAMP2E_SHIFT                   (3U)                                                /**< RTC_TAFCR.TAMP2E Position               */
#define RTC_TAFCR_TAMP2E(x)                      (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMP2E_SHIFT))&RTC_TAFCR_TAMP2E_MASK) /**< RTC_TAFCR.TAMP2E Field                  */
#define RTC_TAFCR_TAMP2_TRG_MASK                 (0x10U)                                             /**< RTC_TAFCR.TAMP2_TRG Mask                */
#define RTC_TAFCR_TAMP2_TRG_SHIFT                (4U)                                                /**< RTC_TAFCR.TAMP2_TRG Position            */
#define RTC_TAFCR_TAMP2_TRG(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMP2_TRG_SHIFT))&RTC_TAFCR_TAMP2_TRG_MASK) /**< RTC_TAFCR.TAMP2_TRG Field               */
#define RTC_TAFCR_TAMPTS_MASK                    (0x80U)                                             /**< RTC_TAFCR.TAMPTS Mask                   */
#define RTC_TAFCR_TAMPTS_SHIFT                   (7U)                                                /**< RTC_TAFCR.TAMPTS Position               */
#define RTC_TAFCR_TAMPTS(x)                      (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMPTS_SHIFT))&RTC_TAFCR_TAMPTS_MASK) /**< RTC_TAFCR.TAMPTS Field                  */
#define RTC_TAFCR_TAMPFREQ_MASK                  (0x700U)                                            /**< RTC_TAFCR.TAMPFREQ Mask                 */
#define RTC_TAFCR_TAMPFREQ_SHIFT                 (8U)                                                /**< RTC_TAFCR.TAMPFREQ Position             */
#define RTC_TAFCR_TAMPFREQ(x)                    (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMPFREQ_SHIFT))&RTC_TAFCR_TAMPFREQ_MASK) /**< RTC_TAFCR.TAMPFREQ Field                */
#define RTC_TAFCR_TAMPFLT_MASK                   (0x1800U)                                           /**< RTC_TAFCR.TAMPFLT Mask                  */
#define RTC_TAFCR_TAMPFLT_SHIFT                  (11U)                                               /**< RTC_TAFCR.TAMPFLT Position              */
#define RTC_TAFCR_TAMPFLT(x)                     (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMPFLT_SHIFT))&RTC_TAFCR_TAMPFLT_MASK) /**< RTC_TAFCR.TAMPFLT Field                 */
#define RTC_TAFCR_TAMP_PRCH_MASK                 (0x6000U)                                           /**< RTC_TAFCR.TAMP_PRCH Mask                */
#define RTC_TAFCR_TAMP_PRCH_SHIFT                (13U)                                               /**< RTC_TAFCR.TAMP_PRCH Position            */
#define RTC_TAFCR_TAMP_PRCH(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMP_PRCH_SHIFT))&RTC_TAFCR_TAMP_PRCH_MASK) /**< RTC_TAFCR.TAMP_PRCH Field               */
#define RTC_TAFCR_TAMP_PUDIS_MASK                (0x8000U)                                           /**< RTC_TAFCR.TAMP_PUDIS Mask               */
#define RTC_TAFCR_TAMP_PUDIS_SHIFT               (15U)                                               /**< RTC_TAFCR.TAMP_PUDIS Position           */
#define RTC_TAFCR_TAMP_PUDIS(x)                  (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_TAMP_PUDIS_SHIFT))&RTC_TAFCR_TAMP_PUDIS_MASK) /**< RTC_TAFCR.TAMP_PUDIS Field              */
#define RTC_TAFCR_PC13VALUE_MASK                 (0x40000U)                                          /**< RTC_TAFCR.PC13VALUE Mask                */
#define RTC_TAFCR_PC13VALUE_SHIFT                (18U)                                               /**< RTC_TAFCR.PC13VALUE Position            */
#define RTC_TAFCR_PC13VALUE(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_PC13VALUE_SHIFT))&RTC_TAFCR_PC13VALUE_MASK) /**< RTC_TAFCR.PC13VALUE Field               */
#define RTC_TAFCR_PC13MODE_MASK                  (0x80000U)                                          /**< RTC_TAFCR.PC13MODE Mask                 */
#define RTC_TAFCR_PC13MODE_SHIFT                 (19U)                                               /**< RTC_TAFCR.PC13MODE Position             */
#define RTC_TAFCR_PC13MODE(x)                    (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_PC13MODE_SHIFT))&RTC_TAFCR_PC13MODE_MASK) /**< RTC_TAFCR.PC13MODE Field                */
#define RTC_TAFCR_PC14VALUE_MASK                 (0x100000U)                                         /**< RTC_TAFCR.PC14VALUE Mask                */
#define RTC_TAFCR_PC14VALUE_SHIFT                (20U)                                               /**< RTC_TAFCR.PC14VALUE Position            */
#define RTC_TAFCR_PC14VALUE(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_PC14VALUE_SHIFT))&RTC_TAFCR_PC14VALUE_MASK) /**< RTC_TAFCR.PC14VALUE Field               */
#define RTC_TAFCR_PC14MODE_MASK                  (0x200000U)                                         /**< RTC_TAFCR.PC14MODE Mask                 */
#define RTC_TAFCR_PC14MODE_SHIFT                 (21U)                                               /**< RTC_TAFCR.PC14MODE Position             */
#define RTC_TAFCR_PC14MODE(x)                    (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_PC14MODE_SHIFT))&RTC_TAFCR_PC14MODE_MASK) /**< RTC_TAFCR.PC14MODE Field                */
#define RTC_TAFCR_PC15VALUE_MASK                 (0x400000U)                                         /**< RTC_TAFCR.PC15VALUE Mask                */
#define RTC_TAFCR_PC15VALUE_SHIFT                (22U)                                               /**< RTC_TAFCR.PC15VALUE Position            */
#define RTC_TAFCR_PC15VALUE(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_PC15VALUE_SHIFT))&RTC_TAFCR_PC15VALUE_MASK) /**< RTC_TAFCR.PC15VALUE Field               */
#define RTC_TAFCR_PC15MODE_MASK                  (0x800000U)                                         /**< RTC_TAFCR.PC15MODE Mask                 */
#define RTC_TAFCR_PC15MODE_SHIFT                 (23U)                                               /**< RTC_TAFCR.PC15MODE Position             */
#define RTC_TAFCR_PC15MODE(x)                    (((uint32_t)(((uint32_t)(x))<<RTC_TAFCR_PC15MODE_SHIFT))&RTC_TAFCR_PC15MODE_MASK) /**< RTC_TAFCR.PC15MODE Field                */
/** @} */

/** @name ALRMASSR - alarm A sub second register */ /** @{ */
#define RTC_ALRMASSR_SS_MASK                     (0x7FFFU)                                           /**< RTC_ALRMASSR.SS Mask                    */
#define RTC_ALRMASSR_SS_SHIFT                    (0U)                                                /**< RTC_ALRMASSR.SS Position                */
#define RTC_ALRMASSR_SS(x)                       (((uint32_t)(((uint32_t)(x))<<RTC_ALRMASSR_SS_SHIFT))&RTC_ALRMASSR_SS_MASK) /**< RTC_ALRMASSR.SS Field                   */
#define RTC_ALRMASSR_MASKSS_MASK                 (0xF000000U)                                        /**< RTC_ALRMASSR.MASKSS Mask                */
#define RTC_ALRMASSR_MASKSS_SHIFT                (24U)                                               /**< RTC_ALRMASSR.MASKSS Position            */
#define RTC_ALRMASSR_MASKSS(x)                   (((uint32_t)(((uint32_t)(x))<<RTC_ALRMASSR_MASKSS_SHIFT))&RTC_ALRMASSR_MASKSS_MASK) /**< RTC_ALRMASSR.MASKSS Field               */
/** @} */

/** @name BKP0R - backup register */ /** @{ */
#define RTC_BKP0R_BKP_MASK                       (0xFFFFFFFFU)                                       /**< RTC_BKP0R.BKP Mask                      */
#define RTC_BKP0R_BKP_SHIFT                      (0U)                                                /**< RTC_BKP0R.BKP Position                  */
#define RTC_BKP0R_BKP(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_BKP0R_BKP_SHIFT))&RTC_BKP0R_BKP_MASK) /**< RTC_BKP0R.BKP Field                     */
/** @} */

/** @name BKP1R - backup register */ /** @{ */
#define RTC_BKP1R_BKP_MASK                       (0xFFFFFFFFU)                                       /**< RTC_BKP1R.BKP Mask                      */
#define RTC_BKP1R_BKP_SHIFT                      (0U)                                                /**< RTC_BKP1R.BKP Position                  */
#define RTC_BKP1R_BKP(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_BKP1R_BKP_SHIFT))&RTC_BKP1R_BKP_MASK) /**< RTC_BKP1R.BKP Field                     */
/** @} */

/** @name BKP2R - backup register */ /** @{ */
#define RTC_BKP2R_BKP_MASK                       (0xFFFFFFFFU)                                       /**< RTC_BKP2R.BKP Mask                      */
#define RTC_BKP2R_BKP_SHIFT                      (0U)                                                /**< RTC_BKP2R.BKP Position                  */
#define RTC_BKP2R_BKP(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_BKP2R_BKP_SHIFT))&RTC_BKP2R_BKP_MASK) /**< RTC_BKP2R.BKP Field                     */
/** @} */

/** @name BKP3R - backup register */ /** @{ */
#define RTC_BKP3R_BKP_MASK                       (0xFFFFFFFFU)                                       /**< RTC_BKP3R.BKP Mask                      */
#define RTC_BKP3R_BKP_SHIFT                      (0U)                                                /**< RTC_BKP3R.BKP Position                  */
#define RTC_BKP3R_BKP(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_BKP3R_BKP_SHIFT))&RTC_BKP3R_BKP_MASK) /**< RTC_BKP3R.BKP Field                     */
/** @} */

/** @name BKP4R - backup register */ /** @{ */
#define RTC_BKP4R_BKP_MASK                       (0xFFFFFFFFU)                                       /**< RTC_BKP4R.BKP Mask                      */
#define RTC_BKP4R_BKP_SHIFT                      (0U)                                                /**< RTC_BKP4R.BKP Position                  */
#define RTC_BKP4R_BKP(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_BKP4R_BKP_SHIFT))&RTC_BKP4R_BKP_MASK) /**< RTC_BKP4R.BKP Field                     */
/** @} */

/** @} */ /* End group RTC_Register_Masks_GROUP */


/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x40002800UL //!< Peripheral base address
#define RTC                            ((RTC_Type *) RTC_BasePtr) //!< Freescale base pointer
#define RTC_BASE_PTR                   (RTC) //!< Freescale style base pointer
#define RTC_IRQS { ADC_COMP_IRQn,  }


/** @} */ /* End group RTC_Peripheral_access_layer_GROUP */


/** @brief C Struct for SPI */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SPI1 (file:SPI1_STM32F030)           ================ */
/* ================================================================================ */

/**
 * @brief Serial peripheral interface
 */
/**
 * @struct SPI1_Type
 * @brief  C Struct allowing access to SPI registers
 */
typedef struct SPI1_Type {
   __IO uint32_t  CR1;                          /**< 0000: control register 1                                           */
   __IO uint32_t  CR2;                          /**< 0004: control register 2                                           */
   __IO uint32_t  SR;                           /**< 0008: status register                                              */
   __IO uint32_t  DR;                           /**< 000C: data register                                                */
   __IO uint32_t  CRCPR;                        /**< 0010: CRC polynomial register                                      */
   __I  uint32_t  RXCRCR;                       /**< 0014: RX CRC register                                              */
   __I  uint32_t  TXCRCR;                       /**< 0018: TX CRC register                                              */
   __IO uint32_t  I2SCFGR;                      /**< 001C: I2S configuration register                                   */
   __IO uint32_t  I2SPR;                        /**< 0020: I2S prescaler register                                       */
} SPI1_Type;


/** @brief Register Masks for SPI */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SPI_Register_Masks_GROUP SPI Register Masks */
/** @{ */

/** @name CR1 - control register 1 */ /** @{ */
#define SPI_CR1_CPHA_MASK                        (0x1U)                                              /**< SPI1_CR1.CPHA Mask                      */
#define SPI_CR1_CPHA_SHIFT                       (0U)                                                /**< SPI1_CR1.CPHA Position                  */
#define SPI_CR1_CPHA(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CR1_CPHA_SHIFT))&SPI_CR1_CPHA_MASK) /**< SPI1_CR1.CPHA Field                     */
#define SPI_CR1_CPOL_MASK                        (0x2U)                                              /**< SPI1_CR1.CPOL Mask                      */
#define SPI_CR1_CPOL_SHIFT                       (1U)                                                /**< SPI1_CR1.CPOL Position                  */
#define SPI_CR1_CPOL(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CR1_CPOL_SHIFT))&SPI_CR1_CPOL_MASK) /**< SPI1_CR1.CPOL Field                     */
#define SPI_CR1_MSTR_MASK                        (0x4U)                                              /**< SPI1_CR1.MSTR Mask                      */
#define SPI_CR1_MSTR_SHIFT                       (2U)                                                /**< SPI1_CR1.MSTR Position                  */
#define SPI_CR1_MSTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CR1_MSTR_SHIFT))&SPI_CR1_MSTR_MASK) /**< SPI1_CR1.MSTR Field                     */
#define SPI_CR1_BR_MASK                          (0x38U)                                             /**< SPI1_CR1.BR Mask                        */
#define SPI_CR1_BR_SHIFT                         (3U)                                                /**< SPI1_CR1.BR Position                    */
#define SPI_CR1_BR(x)                            (((uint32_t)(((uint32_t)(x))<<SPI_CR1_BR_SHIFT))&SPI_CR1_BR_MASK) /**< SPI1_CR1.BR Field                       */
#define SPI_CR1_SPE_MASK                         (0x40U)                                             /**< SPI1_CR1.SPE Mask                       */
#define SPI_CR1_SPE_SHIFT                        (6U)                                                /**< SPI1_CR1.SPE Position                   */
#define SPI_CR1_SPE(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CR1_SPE_SHIFT))&SPI_CR1_SPE_MASK) /**< SPI1_CR1.SPE Field                      */
#define SPI_CR1_LSBFIRST_MASK                    (0x80U)                                             /**< SPI1_CR1.LSBFIRST Mask                  */
#define SPI_CR1_LSBFIRST_SHIFT                   (7U)                                                /**< SPI1_CR1.LSBFIRST Position              */
#define SPI_CR1_LSBFIRST(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_CR1_LSBFIRST_SHIFT))&SPI_CR1_LSBFIRST_MASK) /**< SPI1_CR1.LSBFIRST Field                 */
#define SPI_CR1_SSI_MASK                         (0x100U)                                            /**< SPI1_CR1.SSI Mask                       */
#define SPI_CR1_SSI_SHIFT                        (8U)                                                /**< SPI1_CR1.SSI Position                   */
#define SPI_CR1_SSI(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CR1_SSI_SHIFT))&SPI_CR1_SSI_MASK) /**< SPI1_CR1.SSI Field                      */
#define SPI_CR1_SSM_MASK                         (0x200U)                                            /**< SPI1_CR1.SSM Mask                       */
#define SPI_CR1_SSM_SHIFT                        (9U)                                                /**< SPI1_CR1.SSM Position                   */
#define SPI_CR1_SSM(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CR1_SSM_SHIFT))&SPI_CR1_SSM_MASK) /**< SPI1_CR1.SSM Field                      */
#define SPI_CR1_RXONLY_MASK                      (0x400U)                                            /**< SPI1_CR1.RXONLY Mask                    */
#define SPI_CR1_RXONLY_SHIFT                     (10U)                                               /**< SPI1_CR1.RXONLY Position                */
#define SPI_CR1_RXONLY(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CR1_RXONLY_SHIFT))&SPI_CR1_RXONLY_MASK) /**< SPI1_CR1.RXONLY Field                   */
#define SPI_CR1_DFF_MASK                         (0x800U)                                            /**< SPI1_CR1.DFF Mask                       */
#define SPI_CR1_DFF_SHIFT                        (11U)                                               /**< SPI1_CR1.DFF Position                   */
#define SPI_CR1_DFF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CR1_DFF_SHIFT))&SPI_CR1_DFF_MASK) /**< SPI1_CR1.DFF Field                      */
#define SPI_CR1_CRCNEXT_MASK                     (0x1000U)                                           /**< SPI1_CR1.CRCNEXT Mask                   */
#define SPI_CR1_CRCNEXT_SHIFT                    (12U)                                               /**< SPI1_CR1.CRCNEXT Position               */
#define SPI_CR1_CRCNEXT(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CR1_CRCNEXT_SHIFT))&SPI_CR1_CRCNEXT_MASK) /**< SPI1_CR1.CRCNEXT Field                  */
#define SPI_CR1_CRCEN_MASK                       (0x2000U)                                           /**< SPI1_CR1.CRCEN Mask                     */
#define SPI_CR1_CRCEN_SHIFT                      (13U)                                               /**< SPI1_CR1.CRCEN Position                 */
#define SPI_CR1_CRCEN(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CR1_CRCEN_SHIFT))&SPI_CR1_CRCEN_MASK) /**< SPI1_CR1.CRCEN Field                    */
#define SPI_CR1_BIDIOE_MASK                      (0x4000U)                                           /**< SPI1_CR1.BIDIOE Mask                    */
#define SPI_CR1_BIDIOE_SHIFT                     (14U)                                               /**< SPI1_CR1.BIDIOE Position                */
#define SPI_CR1_BIDIOE(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CR1_BIDIOE_SHIFT))&SPI_CR1_BIDIOE_MASK) /**< SPI1_CR1.BIDIOE Field                   */
#define SPI_CR1_BIDIMODE_MASK                    (0x8000U)                                           /**< SPI1_CR1.BIDIMODE Mask                  */
#define SPI_CR1_BIDIMODE_SHIFT                   (15U)                                               /**< SPI1_CR1.BIDIMODE Position              */
#define SPI_CR1_BIDIMODE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_CR1_BIDIMODE_SHIFT))&SPI_CR1_BIDIMODE_MASK) /**< SPI1_CR1.BIDIMODE Field                 */
/** @} */

/** @name CR2 - control register 2 */ /** @{ */
#define SPI_CR2_RXDMAEN_MASK                     (0x1U)                                              /**< SPI1_CR2.RXDMAEN Mask                   */
#define SPI_CR2_RXDMAEN_SHIFT                    (0U)                                                /**< SPI1_CR2.RXDMAEN Position               */
#define SPI_CR2_RXDMAEN(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CR2_RXDMAEN_SHIFT))&SPI_CR2_RXDMAEN_MASK) /**< SPI1_CR2.RXDMAEN Field                  */
#define SPI_CR2_TXDMAEN_MASK                     (0x2U)                                              /**< SPI1_CR2.TXDMAEN Mask                   */
#define SPI_CR2_TXDMAEN_SHIFT                    (1U)                                                /**< SPI1_CR2.TXDMAEN Position               */
#define SPI_CR2_TXDMAEN(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CR2_TXDMAEN_SHIFT))&SPI_CR2_TXDMAEN_MASK) /**< SPI1_CR2.TXDMAEN Field                  */
#define SPI_CR2_SSOE_MASK                        (0x4U)                                              /**< SPI1_CR2.SSOE Mask                      */
#define SPI_CR2_SSOE_SHIFT                       (2U)                                                /**< SPI1_CR2.SSOE Position                  */
#define SPI_CR2_SSOE(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CR2_SSOE_SHIFT))&SPI_CR2_SSOE_MASK) /**< SPI1_CR2.SSOE Field                     */
#define SPI_CR2_NSSP_MASK                        (0x8U)                                              /**< SPI1_CR2.NSSP Mask                      */
#define SPI_CR2_NSSP_SHIFT                       (3U)                                                /**< SPI1_CR2.NSSP Position                  */
#define SPI_CR2_NSSP(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CR2_NSSP_SHIFT))&SPI_CR2_NSSP_MASK) /**< SPI1_CR2.NSSP Field                     */
#define SPI_CR2_FRF_MASK                         (0x10U)                                             /**< SPI1_CR2.FRF Mask                       */
#define SPI_CR2_FRF_SHIFT                        (4U)                                                /**< SPI1_CR2.FRF Position                   */
#define SPI_CR2_FRF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CR2_FRF_SHIFT))&SPI_CR2_FRF_MASK) /**< SPI1_CR2.FRF Field                      */
#define SPI_CR2_ERRIE_MASK                       (0x20U)                                             /**< SPI1_CR2.ERRIE Mask                     */
#define SPI_CR2_ERRIE_SHIFT                      (5U)                                                /**< SPI1_CR2.ERRIE Position                 */
#define SPI_CR2_ERRIE(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CR2_ERRIE_SHIFT))&SPI_CR2_ERRIE_MASK) /**< SPI1_CR2.ERRIE Field                    */
#define SPI_CR2_RXNEIE_MASK                      (0x40U)                                             /**< SPI1_CR2.RXNEIE Mask                    */
#define SPI_CR2_RXNEIE_SHIFT                     (6U)                                                /**< SPI1_CR2.RXNEIE Position                */
#define SPI_CR2_RXNEIE(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CR2_RXNEIE_SHIFT))&SPI_CR2_RXNEIE_MASK) /**< SPI1_CR2.RXNEIE Field                   */
#define SPI_CR2_TXEIE_MASK                       (0x80U)                                             /**< SPI1_CR2.TXEIE Mask                     */
#define SPI_CR2_TXEIE_SHIFT                      (7U)                                                /**< SPI1_CR2.TXEIE Position                 */
#define SPI_CR2_TXEIE(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CR2_TXEIE_SHIFT))&SPI_CR2_TXEIE_MASK) /**< SPI1_CR2.TXEIE Field                    */
#define SPI_CR2_DS_MASK                          (0xF00U)                                            /**< SPI1_CR2.DS Mask                        */
#define SPI_CR2_DS_SHIFT                         (8U)                                                /**< SPI1_CR2.DS Position                    */
#define SPI_CR2_DS(x)                            (((uint32_t)(((uint32_t)(x))<<SPI_CR2_DS_SHIFT))&SPI_CR2_DS_MASK) /**< SPI1_CR2.DS Field                       */
#define SPI_CR2_FRXTH_MASK                       (0x1000U)                                           /**< SPI1_CR2.FRXTH Mask                     */
#define SPI_CR2_FRXTH_SHIFT                      (12U)                                               /**< SPI1_CR2.FRXTH Position                 */
#define SPI_CR2_FRXTH(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CR2_FRXTH_SHIFT))&SPI_CR2_FRXTH_MASK) /**< SPI1_CR2.FRXTH Field                    */
#define SPI_CR2_LDMA_RX_MASK                     (0x2000U)                                           /**< SPI1_CR2.LDMA_RX Mask                   */
#define SPI_CR2_LDMA_RX_SHIFT                    (13U)                                               /**< SPI1_CR2.LDMA_RX Position               */
#define SPI_CR2_LDMA_RX(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CR2_LDMA_RX_SHIFT))&SPI_CR2_LDMA_RX_MASK) /**< SPI1_CR2.LDMA_RX Field                  */
#define SPI_CR2_LDMA_TX_MASK                     (0x4000U)                                           /**< SPI1_CR2.LDMA_TX Mask                   */
#define SPI_CR2_LDMA_TX_SHIFT                    (14U)                                               /**< SPI1_CR2.LDMA_TX Position               */
#define SPI_CR2_LDMA_TX(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CR2_LDMA_TX_SHIFT))&SPI_CR2_LDMA_TX_MASK) /**< SPI1_CR2.LDMA_TX Field                  */
/** @} */

/** @name SR - status register */ /** @{ */
#define SPI_SR_RXNE_MASK                         (0x1U)                                              /**< SPI1_SR.RXNE Mask                       */
#define SPI_SR_RXNE_SHIFT                        (0U)                                                /**< SPI1_SR.RXNE Position                   */
#define SPI_SR_RXNE(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_RXNE_SHIFT))&SPI_SR_RXNE_MASK) /**< SPI1_SR.RXNE Field                      */
#define SPI_SR_TXE_MASK                          (0x2U)                                              /**< SPI1_SR.TXE Mask                        */
#define SPI_SR_TXE_SHIFT                         (1U)                                                /**< SPI1_SR.TXE Position                    */
#define SPI_SR_TXE(x)                            (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXE_SHIFT))&SPI_SR_TXE_MASK) /**< SPI1_SR.TXE Field                       */
#define SPI_SR_CHSIDE_MASK                       (0x4U)                                              /**< SPI1_SR.CHSIDE Mask                     */
#define SPI_SR_CHSIDE_SHIFT                      (2U)                                                /**< SPI1_SR.CHSIDE Position                 */
#define SPI_SR_CHSIDE(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_SR_CHSIDE_SHIFT))&SPI_SR_CHSIDE_MASK) /**< SPI1_SR.CHSIDE Field                    */
#define SPI_SR_UDR_MASK                          (0x8U)                                              /**< SPI1_SR.UDR Mask                        */
#define SPI_SR_UDR_SHIFT                         (3U)                                                /**< SPI1_SR.UDR Position                    */
#define SPI_SR_UDR(x)                            (((uint32_t)(((uint32_t)(x))<<SPI_SR_UDR_SHIFT))&SPI_SR_UDR_MASK) /**< SPI1_SR.UDR Field                       */
#define SPI_SR_CRCERR_MASK                       (0x10U)                                             /**< SPI1_SR.CRCERR Mask                     */
#define SPI_SR_CRCERR_SHIFT                      (4U)                                                /**< SPI1_SR.CRCERR Position                 */
#define SPI_SR_CRCERR(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_SR_CRCERR_SHIFT))&SPI_SR_CRCERR_MASK) /**< SPI1_SR.CRCERR Field                    */
#define SPI_SR_MODF_MASK                         (0x20U)                                             /**< SPI1_SR.MODF Mask                       */
#define SPI_SR_MODF_SHIFT                        (5U)                                                /**< SPI1_SR.MODF Position                   */
#define SPI_SR_MODF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_MODF_SHIFT))&SPI_SR_MODF_MASK) /**< SPI1_SR.MODF Field                      */
#define SPI_SR_OVR_MASK                          (0x40U)                                             /**< SPI1_SR.OVR Mask                        */
#define SPI_SR_OVR_SHIFT                         (6U)                                                /**< SPI1_SR.OVR Position                    */
#define SPI_SR_OVR(x)                            (((uint32_t)(((uint32_t)(x))<<SPI_SR_OVR_SHIFT))&SPI_SR_OVR_MASK) /**< SPI1_SR.OVR Field                       */
#define SPI_SR_BSY_MASK                          (0x80U)                                             /**< SPI1_SR.BSY Mask                        */
#define SPI_SR_BSY_SHIFT                         (7U)                                                /**< SPI1_SR.BSY Position                    */
#define SPI_SR_BSY(x)                            (((uint32_t)(((uint32_t)(x))<<SPI_SR_BSY_SHIFT))&SPI_SR_BSY_MASK) /**< SPI1_SR.BSY Field                       */
#define SPI_SR_TIFRFE_MASK                       (0x100U)                                            /**< SPI1_SR.TIFRFE Mask                     */
#define SPI_SR_TIFRFE_SHIFT                      (8U)                                                /**< SPI1_SR.TIFRFE Position                 */
#define SPI_SR_TIFRFE(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_SR_TIFRFE_SHIFT))&SPI_SR_TIFRFE_MASK) /**< SPI1_SR.TIFRFE Field                    */
#define SPI_SR_FRLVL_MASK                        (0x600U)                                            /**< SPI1_SR.FRLVL Mask                      */
#define SPI_SR_FRLVL_SHIFT                       (9U)                                                /**< SPI1_SR.FRLVL Position                  */
#define SPI_SR_FRLVL(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_FRLVL_SHIFT))&SPI_SR_FRLVL_MASK) /**< SPI1_SR.FRLVL Field                     */
#define SPI_SR_FTLVL_MASK                        (0x1800U)                                           /**< SPI1_SR.FTLVL Mask                      */
#define SPI_SR_FTLVL_SHIFT                       (11U)                                               /**< SPI1_SR.FTLVL Position                  */
#define SPI_SR_FTLVL(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_FTLVL_SHIFT))&SPI_SR_FTLVL_MASK) /**< SPI1_SR.FTLVL Field                     */
/** @} */

/** @name DR - data register */ /** @{ */
#define SPI_DR_DR_MASK                           (0xFFFFU)                                           /**< SPI1_DR.DR Mask                         */
#define SPI_DR_DR_SHIFT                          (0U)                                                /**< SPI1_DR.DR Position                     */
#define SPI_DR_DR(x)                             (((uint32_t)(((uint32_t)(x))<<SPI_DR_DR_SHIFT))&SPI_DR_DR_MASK) /**< SPI1_DR.DR Field                        */
/** @} */

/** @name CRCPR - CRC polynomial register */ /** @{ */
#define SPI_CRCPR_CRCPOLY_MASK                   (0xFFFFU)                                           /**< SPI1_CRCPR.CRCPOLY Mask                 */
#define SPI_CRCPR_CRCPOLY_SHIFT                  (0U)                                                /**< SPI1_CRCPR.CRCPOLY Position             */
#define SPI_CRCPR_CRCPOLY(x)                     (((uint32_t)(((uint32_t)(x))<<SPI_CRCPR_CRCPOLY_SHIFT))&SPI_CRCPR_CRCPOLY_MASK) /**< SPI1_CRCPR.CRCPOLY Field                */
/** @} */

/** @name RXCRCR - RX CRC register */ /** @{ */
#define SPI_RXCRCR_RxCRC_MASK                    (0xFFFFU)                                           /**< SPI1_RXCRCR.RxCRC Mask                  */
#define SPI_RXCRCR_RxCRC_SHIFT                   (0U)                                                /**< SPI1_RXCRCR.RxCRC Position              */
#define SPI_RXCRCR_RxCRC(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RXCRCR_RxCRC_SHIFT))&SPI_RXCRCR_RxCRC_MASK) /**< SPI1_RXCRCR.RxCRC Field                 */
/** @} */

/** @name TXCRCR - TX CRC register */ /** @{ */
#define SPI_TXCRCR_TxCRC_MASK                    (0xFFFFU)                                           /**< SPI1_TXCRCR.TxCRC Mask                  */
#define SPI_TXCRCR_TxCRC_SHIFT                   (0U)                                                /**< SPI1_TXCRCR.TxCRC Position              */
#define SPI_TXCRCR_TxCRC(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TXCRCR_TxCRC_SHIFT))&SPI_TXCRCR_TxCRC_MASK) /**< SPI1_TXCRCR.TxCRC Field                 */
/** @} */

/** @name I2SCFGR - I2S configuration register */ /** @{ */
#define SPI_I2SCFGR_CHLEN_MASK                   (0x1U)                                              /**< SPI1_I2SCFGR.CHLEN Mask                 */
#define SPI_I2SCFGR_CHLEN_SHIFT                  (0U)                                                /**< SPI1_I2SCFGR.CHLEN Position             */
#define SPI_I2SCFGR_CHLEN(x)                     (((uint32_t)(((uint32_t)(x))<<SPI_I2SCFGR_CHLEN_SHIFT))&SPI_I2SCFGR_CHLEN_MASK) /**< SPI1_I2SCFGR.CHLEN Field                */
#define SPI_I2SCFGR_DATLEN_MASK                  (0x6U)                                              /**< SPI1_I2SCFGR.DATLEN Mask                */
#define SPI_I2SCFGR_DATLEN_SHIFT                 (1U)                                                /**< SPI1_I2SCFGR.DATLEN Position            */
#define SPI_I2SCFGR_DATLEN(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_I2SCFGR_DATLEN_SHIFT))&SPI_I2SCFGR_DATLEN_MASK) /**< SPI1_I2SCFGR.DATLEN Field               */
#define SPI_I2SCFGR_CKPOL_MASK                   (0x8U)                                              /**< SPI1_I2SCFGR.CKPOL Mask                 */
#define SPI_I2SCFGR_CKPOL_SHIFT                  (3U)                                                /**< SPI1_I2SCFGR.CKPOL Position             */
#define SPI_I2SCFGR_CKPOL(x)                     (((uint32_t)(((uint32_t)(x))<<SPI_I2SCFGR_CKPOL_SHIFT))&SPI_I2SCFGR_CKPOL_MASK) /**< SPI1_I2SCFGR.CKPOL Field                */
#define SPI_I2SCFGR_I2SSTD_MASK                  (0x30U)                                             /**< SPI1_I2SCFGR.I2SSTD Mask                */
#define SPI_I2SCFGR_I2SSTD_SHIFT                 (4U)                                                /**< SPI1_I2SCFGR.I2SSTD Position            */
#define SPI_I2SCFGR_I2SSTD(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_I2SCFGR_I2SSTD_SHIFT))&SPI_I2SCFGR_I2SSTD_MASK) /**< SPI1_I2SCFGR.I2SSTD Field               */
#define SPI_I2SCFGR_PCMSYNC_MASK                 (0x80U)                                             /**< SPI1_I2SCFGR.PCMSYNC Mask               */
#define SPI_I2SCFGR_PCMSYNC_SHIFT                (7U)                                                /**< SPI1_I2SCFGR.PCMSYNC Position           */
#define SPI_I2SCFGR_PCMSYNC(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_I2SCFGR_PCMSYNC_SHIFT))&SPI_I2SCFGR_PCMSYNC_MASK) /**< SPI1_I2SCFGR.PCMSYNC Field              */
#define SPI_I2SCFGR_I2SCFG_MASK                  (0x300U)                                            /**< SPI1_I2SCFGR.I2SCFG Mask                */
#define SPI_I2SCFGR_I2SCFG_SHIFT                 (8U)                                                /**< SPI1_I2SCFGR.I2SCFG Position            */
#define SPI_I2SCFGR_I2SCFG(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_I2SCFGR_I2SCFG_SHIFT))&SPI_I2SCFGR_I2SCFG_MASK) /**< SPI1_I2SCFGR.I2SCFG Field               */
#define SPI_I2SCFGR_I2SE_MASK                    (0x400U)                                            /**< SPI1_I2SCFGR.I2SE Mask                  */
#define SPI_I2SCFGR_I2SE_SHIFT                   (10U)                                               /**< SPI1_I2SCFGR.I2SE Position              */
#define SPI_I2SCFGR_I2SE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_I2SCFGR_I2SE_SHIFT))&SPI_I2SCFGR_I2SE_MASK) /**< SPI1_I2SCFGR.I2SE Field                 */
#define SPI_I2SCFGR_I2SMOD_MASK                  (0x800U)                                            /**< SPI1_I2SCFGR.I2SMOD Mask                */
#define SPI_I2SCFGR_I2SMOD_SHIFT                 (11U)                                               /**< SPI1_I2SCFGR.I2SMOD Position            */
#define SPI_I2SCFGR_I2SMOD(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_I2SCFGR_I2SMOD_SHIFT))&SPI_I2SCFGR_I2SMOD_MASK) /**< SPI1_I2SCFGR.I2SMOD Field               */
/** @} */

/** @name I2SPR - I2S prescaler register */ /** @{ */
#define SPI_I2SPR_I2SDIV_MASK                    (0xFFU)                                             /**< SPI1_I2SPR.I2SDIV Mask                  */
#define SPI_I2SPR_I2SDIV_SHIFT                   (0U)                                                /**< SPI1_I2SPR.I2SDIV Position              */
#define SPI_I2SPR_I2SDIV(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_I2SPR_I2SDIV_SHIFT))&SPI_I2SPR_I2SDIV_MASK) /**< SPI1_I2SPR.I2SDIV Field                 */
#define SPI_I2SPR_ODD_MASK                       (0x100U)                                            /**< SPI1_I2SPR.ODD Mask                     */
#define SPI_I2SPR_ODD_SHIFT                      (8U)                                                /**< SPI1_I2SPR.ODD Position                 */
#define SPI_I2SPR_ODD(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_I2SPR_ODD_SHIFT))&SPI_I2SPR_ODD_MASK) /**< SPI1_I2SPR.ODD Field                    */
#define SPI_I2SPR_MCKOE_MASK                     (0x200U)                                            /**< SPI1_I2SPR.MCKOE Mask                   */
#define SPI_I2SPR_MCKOE_SHIFT                    (9U)                                                /**< SPI1_I2SPR.MCKOE Position               */
#define SPI_I2SPR_MCKOE(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_I2SPR_MCKOE_SHIFT))&SPI_I2SPR_MCKOE_MASK) /**< SPI1_I2SPR.MCKOE Field                  */
/** @} */

/** @} */ /* End group SPI_Register_Masks_GROUP */


/* SPI1 - Peripheral instance base addresses */
#define SPI1_BasePtr                   0x40013000UL //!< Peripheral base address
#define SPI1                           ((SPI1_Type *) SPI1_BasePtr) //!< Freescale base pointer
#define SPI1_BASE_PTR                  (SPI1) //!< Freescale style base pointer
#define SPI1_IRQS { SPI1_IRQn,  }


/** @} */ /* End group SPI_Peripheral_access_layer_GROUP */


/** @brief C Struct for SPI */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SPI2 (derived from SPI1)             ================ */
/* ================================================================================ */

/**
 * @brief Serial peripheral interface
 */

/* SPI2 - Peripheral instance base addresses */
#define SPI2_BasePtr                   0x40003800UL //!< Peripheral base address
#define SPI2                           ((SPI1_Type *) SPI2_BasePtr) //!< Freescale base pointer
#define SPI2_BASE_PTR                  (SPI2) //!< Freescale style base pointer
#define SPI2_IRQS { SPI2_IRQn,  }


/** @} */ /* End group SPI_Peripheral_access_layer_GROUP */


/** @brief C Struct for SYSCFG */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SYSCFG_Peripheral_access_layer_GROUP SYSCFG Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           SYSCFG (file:SYSCFG_STM32F030)       ================ */
/* ================================================================================ */

/**
 * @brief System configuration controller
 */
/**
 * @struct SYSCFG_Type
 * @brief  C Struct allowing access to SYSCFG registers
 */
typedef struct SYSCFG_Type {
   __IO uint32_t  CFGR1;                        /**< 0000: configuration register 1                                     */
        uint8_t   RESERVED_0[4];                /**< 0004: 0x4 bytes                                                    */
   __IO uint32_t  EXTICR1;                      /**< 0008: external interrupt configuration register                    */
   __IO uint32_t  EXTICR2;                      /**< 000C: external interrupt configuration register                    */
   __IO uint32_t  EXTICR3;                      /**< 0010: external interrupt configuration register                    */
   __IO uint32_t  EXTICR4;                      /**< 0014: external interrupt configuration register                    */
   __IO uint32_t  CFGR2;                        /**< 0018: configuration register 2                                     */
} SYSCFG_Type;


/** @brief Register Masks for SYSCFG */

/* -------------------------------------------------------------------------------- */
/* -----------     'SYSCFG' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SYSCFG_Register_Masks_GROUP SYSCFG Register Masks */
/** @{ */

/** @name CFGR1 - configuration register 1 */ /** @{ */
#define SYSCFG_CFGR1_MEM_MODE_MASK               (0x3U)                                              /**< SYSCFG_CFGR1.MEM_MODE Mask              */
#define SYSCFG_CFGR1_MEM_MODE_SHIFT              (0U)                                                /**< SYSCFG_CFGR1.MEM_MODE Position          */
#define SYSCFG_CFGR1_MEM_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_MEM_MODE_SHIFT))&SYSCFG_CFGR1_MEM_MODE_MASK) /**< SYSCFG_CFGR1.MEM_MODE Field             */
#define SYSCFG_CFGR1_ADC_DMA_RMP_MASK            (0x100U)                                            /**< SYSCFG_CFGR1.ADC_DMA_RMP Mask           */
#define SYSCFG_CFGR1_ADC_DMA_RMP_SHIFT           (8U)                                                /**< SYSCFG_CFGR1.ADC_DMA_RMP Position       */
#define SYSCFG_CFGR1_ADC_DMA_RMP(x)              (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_ADC_DMA_RMP_SHIFT))&SYSCFG_CFGR1_ADC_DMA_RMP_MASK) /**< SYSCFG_CFGR1.ADC_DMA_RMP Field          */
#define SYSCFG_CFGR1_USART1_TX_DMA_RMP_MASK      (0x200U)                                            /**< SYSCFG_CFGR1.USART1_TX_DMA_RMP Mask     */
#define SYSCFG_CFGR1_USART1_TX_DMA_RMP_SHIFT     (9U)                                                /**< SYSCFG_CFGR1.USART1_TX_DMA_RMP Position */
#define SYSCFG_CFGR1_USART1_TX_DMA_RMP(x)        (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_USART1_TX_DMA_RMP_SHIFT))&SYSCFG_CFGR1_USART1_TX_DMA_RMP_MASK) /**< SYSCFG_CFGR1.USART1_TX_DMA_RMP Field    */
#define SYSCFG_CFGR1_USART1_RX_DMA_RMP_MASK      (0x400U)                                            /**< SYSCFG_CFGR1.USART1_RX_DMA_RMP Mask     */
#define SYSCFG_CFGR1_USART1_RX_DMA_RMP_SHIFT     (10U)                                               /**< SYSCFG_CFGR1.USART1_RX_DMA_RMP Position */
#define SYSCFG_CFGR1_USART1_RX_DMA_RMP(x)        (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_USART1_RX_DMA_RMP_SHIFT))&SYSCFG_CFGR1_USART1_RX_DMA_RMP_MASK) /**< SYSCFG_CFGR1.USART1_RX_DMA_RMP Field    */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_MASK          (0x800U)                                            /**< SYSCFG_CFGR1.TIM16_DMA_RMP Mask         */
#define SYSCFG_CFGR1_TIM16_DMA_RMP_SHIFT         (11U)                                               /**< SYSCFG_CFGR1.TIM16_DMA_RMP Position     */
#define SYSCFG_CFGR1_TIM16_DMA_RMP(x)            (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_TIM16_DMA_RMP_SHIFT))&SYSCFG_CFGR1_TIM16_DMA_RMP_MASK) /**< SYSCFG_CFGR1.TIM16_DMA_RMP Field        */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_MASK          (0x1000U)                                           /**< SYSCFG_CFGR1.TIM17_DMA_RMP Mask         */
#define SYSCFG_CFGR1_TIM17_DMA_RMP_SHIFT         (12U)                                               /**< SYSCFG_CFGR1.TIM17_DMA_RMP Position     */
#define SYSCFG_CFGR1_TIM17_DMA_RMP(x)            (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_TIM17_DMA_RMP_SHIFT))&SYSCFG_CFGR1_TIM17_DMA_RMP_MASK) /**< SYSCFG_CFGR1.TIM17_DMA_RMP Field        */
#define SYSCFG_CFGR1_I2C_PB6_FM_MASK             (0x10000U)                                          /**< SYSCFG_CFGR1.I2C_PB6_FM Mask            */
#define SYSCFG_CFGR1_I2C_PB6_FM_SHIFT            (16U)                                               /**< SYSCFG_CFGR1.I2C_PB6_FM Position        */
#define SYSCFG_CFGR1_I2C_PB6_FM(x)               (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_I2C_PB6_FM_SHIFT))&SYSCFG_CFGR1_I2C_PB6_FM_MASK) /**< SYSCFG_CFGR1.I2C_PB6_FM Field           */
#define SYSCFG_CFGR1_I2C_PB7_FM_MASK             (0x20000U)                                          /**< SYSCFG_CFGR1.I2C_PB7_FM Mask            */
#define SYSCFG_CFGR1_I2C_PB7_FM_SHIFT            (17U)                                               /**< SYSCFG_CFGR1.I2C_PB7_FM Position        */
#define SYSCFG_CFGR1_I2C_PB7_FM(x)               (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_I2C_PB7_FM_SHIFT))&SYSCFG_CFGR1_I2C_PB7_FM_MASK) /**< SYSCFG_CFGR1.I2C_PB7_FM Field           */
#define SYSCFG_CFGR1_I2C_PB8_FM_MASK             (0x40000U)                                          /**< SYSCFG_CFGR1.I2C_PB8_FM Mask            */
#define SYSCFG_CFGR1_I2C_PB8_FM_SHIFT            (18U)                                               /**< SYSCFG_CFGR1.I2C_PB8_FM Position        */
#define SYSCFG_CFGR1_I2C_PB8_FM(x)               (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_I2C_PB8_FM_SHIFT))&SYSCFG_CFGR1_I2C_PB8_FM_MASK) /**< SYSCFG_CFGR1.I2C_PB8_FM Field           */
#define SYSCFG_CFGR1_I2C_PB9_FM_MASK             (0x80000U)                                          /**< SYSCFG_CFGR1.I2C_PB9_FM Mask            */
#define SYSCFG_CFGR1_I2C_PB9_FM_SHIFT            (19U)                                               /**< SYSCFG_CFGR1.I2C_PB9_FM Position        */
#define SYSCFG_CFGR1_I2C_PB9_FM(x)               (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_I2C_PB9_FM_SHIFT))&SYSCFG_CFGR1_I2C_PB9_FM_MASK) /**< SYSCFG_CFGR1.I2C_PB9_FM Field           */
#define SYSCFG_CFGR1_I2C1_FM_plus_MASK           (0x100000U)                                         /**< SYSCFG_CFGR1.I2C1_FM_plus Mask          */
#define SYSCFG_CFGR1_I2C1_FM_plus_SHIFT          (20U)                                               /**< SYSCFG_CFGR1.I2C1_FM_plus Position      */
#define SYSCFG_CFGR1_I2C1_FM_plus(x)             (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_I2C1_FM_plus_SHIFT))&SYSCFG_CFGR1_I2C1_FM_plus_MASK) /**< SYSCFG_CFGR1.I2C1_FM_plus Field         */
#define SYSCFG_CFGR1_I2C2_FM_plus_MASK           (0x200000U)                                         /**< SYSCFG_CFGR1.I2C2_FM_plus Mask          */
#define SYSCFG_CFGR1_I2C2_FM_plus_SHIFT          (21U)                                               /**< SYSCFG_CFGR1.I2C2_FM_plus Position      */
#define SYSCFG_CFGR1_I2C2_FM_plus(x)             (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_I2C2_FM_plus_SHIFT))&SYSCFG_CFGR1_I2C2_FM_plus_MASK) /**< SYSCFG_CFGR1.I2C2_FM_plus Field         */
#define SYSCFG_CFGR1_SPI2_DMA_RMP_MASK           (0x1000000U)                                        /**< SYSCFG_CFGR1.SPI2_DMA_RMP Mask          */
#define SYSCFG_CFGR1_SPI2_DMA_RMP_SHIFT          (24U)                                               /**< SYSCFG_CFGR1.SPI2_DMA_RMP Position      */
#define SYSCFG_CFGR1_SPI2_DMA_RMP(x)             (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_SPI2_DMA_RMP_SHIFT))&SYSCFG_CFGR1_SPI2_DMA_RMP_MASK) /**< SYSCFG_CFGR1.SPI2_DMA_RMP Field         */
#define SYSCFG_CFGR1_USART2_DMA_RMP_MASK         (0x2000000U)                                        /**< SYSCFG_CFGR1.USART2_DMA_RMP Mask        */
#define SYSCFG_CFGR1_USART2_DMA_RMP_SHIFT        (25U)                                               /**< SYSCFG_CFGR1.USART2_DMA_RMP Position    */
#define SYSCFG_CFGR1_USART2_DMA_RMP(x)           (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_USART2_DMA_RMP_SHIFT))&SYSCFG_CFGR1_USART2_DMA_RMP_MASK) /**< SYSCFG_CFGR1.USART2_DMA_RMP Field       */
#define SYSCFG_CFGR1_USART3_DMA_RMP_MASK         (0x4000000U)                                        /**< SYSCFG_CFGR1.USART3_DMA_RMP Mask        */
#define SYSCFG_CFGR1_USART3_DMA_RMP_SHIFT        (26U)                                               /**< SYSCFG_CFGR1.USART3_DMA_RMP Position    */
#define SYSCFG_CFGR1_USART3_DMA_RMP(x)           (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_USART3_DMA_RMP_SHIFT))&SYSCFG_CFGR1_USART3_DMA_RMP_MASK) /**< SYSCFG_CFGR1.USART3_DMA_RMP Field       */
#define SYSCFG_CFGR1_I2C1_DMA_RMP_MASK           (0x8000000U)                                        /**< SYSCFG_CFGR1.I2C1_DMA_RMP Mask          */
#define SYSCFG_CFGR1_I2C1_DMA_RMP_SHIFT          (27U)                                               /**< SYSCFG_CFGR1.I2C1_DMA_RMP Position      */
#define SYSCFG_CFGR1_I2C1_DMA_RMP(x)             (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_I2C1_DMA_RMP_SHIFT))&SYSCFG_CFGR1_I2C1_DMA_RMP_MASK) /**< SYSCFG_CFGR1.I2C1_DMA_RMP Field         */
#define SYSCFG_CFGR1_TIM1_DMA_RMP_MASK           (0x10000000U)                                       /**< SYSCFG_CFGR1.TIM1_DMA_RMP Mask          */
#define SYSCFG_CFGR1_TIM1_DMA_RMP_SHIFT          (28U)                                               /**< SYSCFG_CFGR1.TIM1_DMA_RMP Position      */
#define SYSCFG_CFGR1_TIM1_DMA_RMP(x)             (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_TIM1_DMA_RMP_SHIFT))&SYSCFG_CFGR1_TIM1_DMA_RMP_MASK) /**< SYSCFG_CFGR1.TIM1_DMA_RMP Field         */
#define SYSCFG_CFGR1_TIM2_DMA_RMP_MASK           (0x20000000U)                                       /**< SYSCFG_CFGR1.TIM2_DMA_RMP Mask          */
#define SYSCFG_CFGR1_TIM2_DMA_RMP_SHIFT          (29U)                                               /**< SYSCFG_CFGR1.TIM2_DMA_RMP Position      */
#define SYSCFG_CFGR1_TIM2_DMA_RMP(x)             (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_TIM2_DMA_RMP_SHIFT))&SYSCFG_CFGR1_TIM2_DMA_RMP_MASK) /**< SYSCFG_CFGR1.TIM2_DMA_RMP Field         */
#define SYSCFG_CFGR1_TIM3_DMA_RMP_MASK           (0x40000000U)                                       /**< SYSCFG_CFGR1.TIM3_DMA_RMP Mask          */
#define SYSCFG_CFGR1_TIM3_DMA_RMP_SHIFT          (30U)                                               /**< SYSCFG_CFGR1.TIM3_DMA_RMP Position      */
#define SYSCFG_CFGR1_TIM3_DMA_RMP(x)             (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR1_TIM3_DMA_RMP_SHIFT))&SYSCFG_CFGR1_TIM3_DMA_RMP_MASK) /**< SYSCFG_CFGR1.TIM3_DMA_RMP Field         */
/** @} */

/** @name EXTICR1 - external interrupt configuration register */ /** @{ */
#define SYSCFG_EXTICR1_EXTI0_MASK                (0xFU)                                              /**< SYSCFG_EXTICR1.EXTI0 Mask               */
#define SYSCFG_EXTICR1_EXTI0_SHIFT               (0U)                                                /**< SYSCFG_EXTICR1.EXTI0 Position           */
#define SYSCFG_EXTICR1_EXTI0(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR1_EXTI0_SHIFT))&SYSCFG_EXTICR1_EXTI0_MASK) /**< SYSCFG_EXTICR1.EXTI0 Field              */
#define SYSCFG_EXTICR1_EXTI1_MASK                (0xF0U)                                             /**< SYSCFG_EXTICR1.EXTI1 Mask               */
#define SYSCFG_EXTICR1_EXTI1_SHIFT               (4U)                                                /**< SYSCFG_EXTICR1.EXTI1 Position           */
#define SYSCFG_EXTICR1_EXTI1(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR1_EXTI1_SHIFT))&SYSCFG_EXTICR1_EXTI1_MASK) /**< SYSCFG_EXTICR1.EXTI1 Field              */
#define SYSCFG_EXTICR1_EXTI2_MASK                (0xF00U)                                            /**< SYSCFG_EXTICR1.EXTI2 Mask               */
#define SYSCFG_EXTICR1_EXTI2_SHIFT               (8U)                                                /**< SYSCFG_EXTICR1.EXTI2 Position           */
#define SYSCFG_EXTICR1_EXTI2(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR1_EXTI2_SHIFT))&SYSCFG_EXTICR1_EXTI2_MASK) /**< SYSCFG_EXTICR1.EXTI2 Field              */
#define SYSCFG_EXTICR1_EXTI3_MASK                (0xF000U)                                           /**< SYSCFG_EXTICR1.EXTI3 Mask               */
#define SYSCFG_EXTICR1_EXTI3_SHIFT               (12U)                                               /**< SYSCFG_EXTICR1.EXTI3 Position           */
#define SYSCFG_EXTICR1_EXTI3(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR1_EXTI3_SHIFT))&SYSCFG_EXTICR1_EXTI3_MASK) /**< SYSCFG_EXTICR1.EXTI3 Field              */
/** @} */

/** @name EXTICR2 - external interrupt configuration register */ /** @{ */
#define SYSCFG_EXTICR2_EXTI4_MASK                (0xFU)                                              /**< SYSCFG_EXTICR2.EXTI4 Mask               */
#define SYSCFG_EXTICR2_EXTI4_SHIFT               (0U)                                                /**< SYSCFG_EXTICR2.EXTI4 Position           */
#define SYSCFG_EXTICR2_EXTI4(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR2_EXTI4_SHIFT))&SYSCFG_EXTICR2_EXTI4_MASK) /**< SYSCFG_EXTICR2.EXTI4 Field              */
#define SYSCFG_EXTICR2_EXTI5_MASK                (0xF0U)                                             /**< SYSCFG_EXTICR2.EXTI5 Mask               */
#define SYSCFG_EXTICR2_EXTI5_SHIFT               (4U)                                                /**< SYSCFG_EXTICR2.EXTI5 Position           */
#define SYSCFG_EXTICR2_EXTI5(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR2_EXTI5_SHIFT))&SYSCFG_EXTICR2_EXTI5_MASK) /**< SYSCFG_EXTICR2.EXTI5 Field              */
#define SYSCFG_EXTICR2_EXTI6_MASK                (0xF00U)                                            /**< SYSCFG_EXTICR2.EXTI6 Mask               */
#define SYSCFG_EXTICR2_EXTI6_SHIFT               (8U)                                                /**< SYSCFG_EXTICR2.EXTI6 Position           */
#define SYSCFG_EXTICR2_EXTI6(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR2_EXTI6_SHIFT))&SYSCFG_EXTICR2_EXTI6_MASK) /**< SYSCFG_EXTICR2.EXTI6 Field              */
#define SYSCFG_EXTICR2_EXTI7_MASK                (0xF000U)                                           /**< SYSCFG_EXTICR2.EXTI7 Mask               */
#define SYSCFG_EXTICR2_EXTI7_SHIFT               (12U)                                               /**< SYSCFG_EXTICR2.EXTI7 Position           */
#define SYSCFG_EXTICR2_EXTI7(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR2_EXTI7_SHIFT))&SYSCFG_EXTICR2_EXTI7_MASK) /**< SYSCFG_EXTICR2.EXTI7 Field              */
/** @} */

/** @name EXTICR3 - external interrupt configuration register */ /** @{ */
#define SYSCFG_EXTICR3_EXTI8_MASK                (0xFU)                                              /**< SYSCFG_EXTICR3.EXTI8 Mask               */
#define SYSCFG_EXTICR3_EXTI8_SHIFT               (0U)                                                /**< SYSCFG_EXTICR3.EXTI8 Position           */
#define SYSCFG_EXTICR3_EXTI8(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR3_EXTI8_SHIFT))&SYSCFG_EXTICR3_EXTI8_MASK) /**< SYSCFG_EXTICR3.EXTI8 Field              */
#define SYSCFG_EXTICR3_EXTI9_MASK                (0xF0U)                                             /**< SYSCFG_EXTICR3.EXTI9 Mask               */
#define SYSCFG_EXTICR3_EXTI9_SHIFT               (4U)                                                /**< SYSCFG_EXTICR3.EXTI9 Position           */
#define SYSCFG_EXTICR3_EXTI9(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR3_EXTI9_SHIFT))&SYSCFG_EXTICR3_EXTI9_MASK) /**< SYSCFG_EXTICR3.EXTI9 Field              */
#define SYSCFG_EXTICR3_EXTI10_MASK               (0xF00U)                                            /**< SYSCFG_EXTICR3.EXTI10 Mask              */
#define SYSCFG_EXTICR3_EXTI10_SHIFT              (8U)                                                /**< SYSCFG_EXTICR3.EXTI10 Position          */
#define SYSCFG_EXTICR3_EXTI10(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR3_EXTI10_SHIFT))&SYSCFG_EXTICR3_EXTI10_MASK) /**< SYSCFG_EXTICR3.EXTI10 Field             */
#define SYSCFG_EXTICR3_EXTI11_MASK               (0xF000U)                                           /**< SYSCFG_EXTICR3.EXTI11 Mask              */
#define SYSCFG_EXTICR3_EXTI11_SHIFT              (12U)                                               /**< SYSCFG_EXTICR3.EXTI11 Position          */
#define SYSCFG_EXTICR3_EXTI11(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR3_EXTI11_SHIFT))&SYSCFG_EXTICR3_EXTI11_MASK) /**< SYSCFG_EXTICR3.EXTI11 Field             */
/** @} */

/** @name EXTICR4 - external interrupt configuration register */ /** @{ */
#define SYSCFG_EXTICR4_EXTI12_MASK               (0xFU)                                              /**< SYSCFG_EXTICR4.EXTI12 Mask              */
#define SYSCFG_EXTICR4_EXTI12_SHIFT              (0U)                                                /**< SYSCFG_EXTICR4.EXTI12 Position          */
#define SYSCFG_EXTICR4_EXTI12(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR4_EXTI12_SHIFT))&SYSCFG_EXTICR4_EXTI12_MASK) /**< SYSCFG_EXTICR4.EXTI12 Field             */
#define SYSCFG_EXTICR4_EXTI13_MASK               (0xF0U)                                             /**< SYSCFG_EXTICR4.EXTI13 Mask              */
#define SYSCFG_EXTICR4_EXTI13_SHIFT              (4U)                                                /**< SYSCFG_EXTICR4.EXTI13 Position          */
#define SYSCFG_EXTICR4_EXTI13(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR4_EXTI13_SHIFT))&SYSCFG_EXTICR4_EXTI13_MASK) /**< SYSCFG_EXTICR4.EXTI13 Field             */
#define SYSCFG_EXTICR4_EXTI14_MASK               (0xF00U)                                            /**< SYSCFG_EXTICR4.EXTI14 Mask              */
#define SYSCFG_EXTICR4_EXTI14_SHIFT              (8U)                                                /**< SYSCFG_EXTICR4.EXTI14 Position          */
#define SYSCFG_EXTICR4_EXTI14(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR4_EXTI14_SHIFT))&SYSCFG_EXTICR4_EXTI14_MASK) /**< SYSCFG_EXTICR4.EXTI14 Field             */
#define SYSCFG_EXTICR4_EXTI15_MASK               (0xF000U)                                           /**< SYSCFG_EXTICR4.EXTI15 Mask              */
#define SYSCFG_EXTICR4_EXTI15_SHIFT              (12U)                                               /**< SYSCFG_EXTICR4.EXTI15 Position          */
#define SYSCFG_EXTICR4_EXTI15(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_EXTICR4_EXTI15_SHIFT))&SYSCFG_EXTICR4_EXTI15_MASK) /**< SYSCFG_EXTICR4.EXTI15 Field             */
/** @} */

/** @name CFGR2 - configuration register 2 */ /** @{ */
#define SYSCFG_CFGR2_LOCUP_LOCK_MASK             (0x1U)                                              /**< SYSCFG_CFGR2.LOCUP_LOCK Mask            */
#define SYSCFG_CFGR2_LOCUP_LOCK_SHIFT            (0U)                                                /**< SYSCFG_CFGR2.LOCUP_LOCK Position        */
#define SYSCFG_CFGR2_LOCUP_LOCK(x)               (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR2_LOCUP_LOCK_SHIFT))&SYSCFG_CFGR2_LOCUP_LOCK_MASK) /**< SYSCFG_CFGR2.LOCUP_LOCK Field           */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK_MASK       (0x2U)                                              /**< SYSCFG_CFGR2.SRAM_PARITY_LOCK Mask      */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK_SHIFT      (1U)                                                /**< SYSCFG_CFGR2.SRAM_PARITY_LOCK Position  */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK(x)         (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR2_SRAM_PARITY_LOCK_SHIFT))&SYSCFG_CFGR2_SRAM_PARITY_LOCK_MASK) /**< SYSCFG_CFGR2.SRAM_PARITY_LOCK Field     */
#define SYSCFG_CFGR2_PVD_LOCK_MASK               (0x4U)                                              /**< SYSCFG_CFGR2.PVD_LOCK Mask              */
#define SYSCFG_CFGR2_PVD_LOCK_SHIFT              (2U)                                                /**< SYSCFG_CFGR2.PVD_LOCK Position          */
#define SYSCFG_CFGR2_PVD_LOCK(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR2_PVD_LOCK_SHIFT))&SYSCFG_CFGR2_PVD_LOCK_MASK) /**< SYSCFG_CFGR2.PVD_LOCK Field             */
#define SYSCFG_CFGR2_SRAM_PEF_MASK               (0x100U)                                            /**< SYSCFG_CFGR2.SRAM_PEF Mask              */
#define SYSCFG_CFGR2_SRAM_PEF_SHIFT              (8U)                                                /**< SYSCFG_CFGR2.SRAM_PEF Position          */
#define SYSCFG_CFGR2_SRAM_PEF(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCFG_CFGR2_SRAM_PEF_SHIFT))&SYSCFG_CFGR2_SRAM_PEF_MASK) /**< SYSCFG_CFGR2.SRAM_PEF Field             */
/** @} */

/** @} */ /* End group SYSCFG_Register_Masks_GROUP */


/* SYSCFG - Peripheral instance base addresses */
#define SYSCFG_BasePtr                 0x40010000UL //!< Peripheral base address
#define SYSCFG                         ((SYSCFG_Type *) SYSCFG_BasePtr) //!< Freescale base pointer
#define SYSCFG_BASE_PTR                (SYSCFG) //!< Freescale style base pointer

/** @} */ /* End group SYSCFG_Peripheral_access_layer_GROUP */


/** @brief C Struct for TIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TIM_Peripheral_access_layer_GROUP TIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TIM1 (file:TIM1_STM32F030)           ================ */
/* ================================================================================ */

/**
 * @brief Advanced-timers
 */
/**
 * @struct TIM1_Type
 * @brief  C Struct allowing access to TIM registers
 */
typedef struct TIM1_Type {
   __IO uint32_t  CR1;                          /**< 0000: control register 1                                           */
   __IO uint32_t  CR2;                          /**< 0004: control register 2                                           */
   __IO uint32_t  SMCR;                         /**< 0008: slave mode control register                                  */
   __IO uint32_t  DIER;                         /**< 000C: DMA/Interrupt enable register                                */
   __IO uint32_t  SR;                           /**< 0010: status register                                              */
   __O  uint32_t  EGR;                          /**< 0014: event generation register                                    */
   union {                                      /**< 0018: (size=0004)                                                  */
      __IO uint32_t  CCMR1_Input;               /**< 0018: capture/compare mode register 1 (input                       */
      __IO uint32_t  CCMR1_Output;              /**< 0018: capture/compare mode register (output                        */
   };
   union {                                      /**< 001C: (size=0004)                                                  */
      __IO uint32_t  CCMR2_Input;               /**< 001C: capture/compare mode register 2 (input                       */
      __IO uint32_t  CCMR2_Output;              /**< 001C: capture/compare mode register (output                        */
   };
   __IO uint32_t  CCER;                         /**< 0020: capture/compare enable                                       */
   __IO uint32_t  CNT;                          /**< 0024: counter                                                      */
   __IO uint32_t  PSC;                          /**< 0028: prescaler                                                    */
   __IO uint32_t  ARR;                          /**< 002C: auto-reload register                                         */
   __IO uint32_t  RCR;                          /**< 0030: repetition counter register                                  */
   __IO uint32_t  CCR1;                         /**< 0034: capture/compare register 1                                   */
   __IO uint32_t  CCR2;                         /**< 0038: capture/compare register 2                                   */
   __IO uint32_t  CCR3;                         /**< 003C: capture/compare register 3                                   */
   __IO uint32_t  CCR4;                         /**< 0040: capture/compare register 4                                   */
   __IO uint32_t  BDTR;                         /**< 0044: break and dead-time register                                 */
   __IO uint32_t  DCR;                          /**< 0048: DMA control register                                         */
   __IO uint32_t  DMAR;                         /**< 004C: DMA address for full transfer                                */
} TIM1_Type;


/** @brief Register Masks for TIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'TIM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TIM_Register_Masks_GROUP TIM Register Masks */
/** @{ */

/** @name CR1 - control register 1 */ /** @{ */
#define TIM1_CR1_CEN_MASK                        (0x1U)                                              /**< TIM1_CR1.CEN Mask                       */
#define TIM1_CR1_CEN_SHIFT                       (0U)                                                /**< TIM1_CR1.CEN Position                   */
#define TIM1_CR1_CEN(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CR1_CEN_SHIFT))&TIM1_CR1_CEN_MASK) /**< TIM1_CR1.CEN Field                      */
#define TIM1_CR1_UDIS_MASK                       (0x2U)                                              /**< TIM1_CR1.UDIS Mask                      */
#define TIM1_CR1_UDIS_SHIFT                      (1U)                                                /**< TIM1_CR1.UDIS Position                  */
#define TIM1_CR1_UDIS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR1_UDIS_SHIFT))&TIM1_CR1_UDIS_MASK) /**< TIM1_CR1.UDIS Field                     */
#define TIM1_CR1_URS_MASK                        (0x4U)                                              /**< TIM1_CR1.URS Mask                       */
#define TIM1_CR1_URS_SHIFT                       (2U)                                                /**< TIM1_CR1.URS Position                   */
#define TIM1_CR1_URS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CR1_URS_SHIFT))&TIM1_CR1_URS_MASK) /**< TIM1_CR1.URS Field                      */
#define TIM1_CR1_OPM_MASK                        (0x8U)                                              /**< TIM1_CR1.OPM Mask                       */
#define TIM1_CR1_OPM_SHIFT                       (3U)                                                /**< TIM1_CR1.OPM Position                   */
#define TIM1_CR1_OPM(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CR1_OPM_SHIFT))&TIM1_CR1_OPM_MASK) /**< TIM1_CR1.OPM Field                      */
#define TIM1_CR1_DIR_MASK                        (0x10U)                                             /**< TIM1_CR1.DIR Mask                       */
#define TIM1_CR1_DIR_SHIFT                       (4U)                                                /**< TIM1_CR1.DIR Position                   */
#define TIM1_CR1_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CR1_DIR_SHIFT))&TIM1_CR1_DIR_MASK) /**< TIM1_CR1.DIR Field                      */
#define TIM1_CR1_CMS_MASK                        (0x60U)                                             /**< TIM1_CR1.CMS Mask                       */
#define TIM1_CR1_CMS_SHIFT                       (5U)                                                /**< TIM1_CR1.CMS Position                   */
#define TIM1_CR1_CMS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CR1_CMS_SHIFT))&TIM1_CR1_CMS_MASK) /**< TIM1_CR1.CMS Field                      */
#define TIM1_CR1_ARPE_MASK                       (0x80U)                                             /**< TIM1_CR1.ARPE Mask                      */
#define TIM1_CR1_ARPE_SHIFT                      (7U)                                                /**< TIM1_CR1.ARPE Position                  */
#define TIM1_CR1_ARPE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR1_ARPE_SHIFT))&TIM1_CR1_ARPE_MASK) /**< TIM1_CR1.ARPE Field                     */
#define TIM1_CR1_CKD_MASK                        (0x300U)                                            /**< TIM1_CR1.CKD Mask                       */
#define TIM1_CR1_CKD_SHIFT                       (8U)                                                /**< TIM1_CR1.CKD Position                   */
#define TIM1_CR1_CKD(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CR1_CKD_SHIFT))&TIM1_CR1_CKD_MASK) /**< TIM1_CR1.CKD Field                      */
/** @} */

/** @name CR2 - control register 2 */ /** @{ */
#define TIM1_CR2_CCPC_MASK                       (0x1U)                                              /**< TIM1_CR2.CCPC Mask                      */
#define TIM1_CR2_CCPC_SHIFT                      (0U)                                                /**< TIM1_CR2.CCPC Position                  */
#define TIM1_CR2_CCPC(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_CCPC_SHIFT))&TIM1_CR2_CCPC_MASK) /**< TIM1_CR2.CCPC Field                     */
#define TIM1_CR2_CCUS_MASK                       (0x4U)                                              /**< TIM1_CR2.CCUS Mask                      */
#define TIM1_CR2_CCUS_SHIFT                      (2U)                                                /**< TIM1_CR2.CCUS Position                  */
#define TIM1_CR2_CCUS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_CCUS_SHIFT))&TIM1_CR2_CCUS_MASK) /**< TIM1_CR2.CCUS Field                     */
#define TIM1_CR2_CCDS_MASK                       (0x8U)                                              /**< TIM1_CR2.CCDS Mask                      */
#define TIM1_CR2_CCDS_SHIFT                      (3U)                                                /**< TIM1_CR2.CCDS Position                  */
#define TIM1_CR2_CCDS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_CCDS_SHIFT))&TIM1_CR2_CCDS_MASK) /**< TIM1_CR2.CCDS Field                     */
#define TIM1_CR2_MMS_MASK                        (0x70U)                                             /**< TIM1_CR2.MMS Mask                       */
#define TIM1_CR2_MMS_SHIFT                       (4U)                                                /**< TIM1_CR2.MMS Position                   */
#define TIM1_CR2_MMS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_MMS_SHIFT))&TIM1_CR2_MMS_MASK) /**< TIM1_CR2.MMS Field                      */
#define TIM1_CR2_TI1S_MASK                       (0x80U)                                             /**< TIM1_CR2.TI1S Mask                      */
#define TIM1_CR2_TI1S_SHIFT                      (7U)                                                /**< TIM1_CR2.TI1S Position                  */
#define TIM1_CR2_TI1S(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_TI1S_SHIFT))&TIM1_CR2_TI1S_MASK) /**< TIM1_CR2.TI1S Field                     */
#define TIM1_CR2_OIS1_MASK                       (0x100U)                                            /**< TIM1_CR2.OIS1 Mask                      */
#define TIM1_CR2_OIS1_SHIFT                      (8U)                                                /**< TIM1_CR2.OIS1 Position                  */
#define TIM1_CR2_OIS1(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_OIS1_SHIFT))&TIM1_CR2_OIS1_MASK) /**< TIM1_CR2.OIS1 Field                     */
#define TIM1_CR2_OIS1N_MASK                      (0x200U)                                            /**< TIM1_CR2.OIS1N Mask                     */
#define TIM1_CR2_OIS1N_SHIFT                     (9U)                                                /**< TIM1_CR2.OIS1N Position                 */
#define TIM1_CR2_OIS1N(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_OIS1N_SHIFT))&TIM1_CR2_OIS1N_MASK) /**< TIM1_CR2.OIS1N Field                    */
#define TIM1_CR2_OIS2_MASK                       (0x400U)                                            /**< TIM1_CR2.OIS2 Mask                      */
#define TIM1_CR2_OIS2_SHIFT                      (10U)                                               /**< TIM1_CR2.OIS2 Position                  */
#define TIM1_CR2_OIS2(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_OIS2_SHIFT))&TIM1_CR2_OIS2_MASK) /**< TIM1_CR2.OIS2 Field                     */
#define TIM1_CR2_OIS2N_MASK                      (0x800U)                                            /**< TIM1_CR2.OIS2N Mask                     */
#define TIM1_CR2_OIS2N_SHIFT                     (11U)                                               /**< TIM1_CR2.OIS2N Position                 */
#define TIM1_CR2_OIS2N(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_OIS2N_SHIFT))&TIM1_CR2_OIS2N_MASK) /**< TIM1_CR2.OIS2N Field                    */
#define TIM1_CR2_OIS3_MASK                       (0x1000U)                                           /**< TIM1_CR2.OIS3 Mask                      */
#define TIM1_CR2_OIS3_SHIFT                      (12U)                                               /**< TIM1_CR2.OIS3 Position                  */
#define TIM1_CR2_OIS3(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_OIS3_SHIFT))&TIM1_CR2_OIS3_MASK) /**< TIM1_CR2.OIS3 Field                     */
#define TIM1_CR2_OIS3N_MASK                      (0x2000U)                                           /**< TIM1_CR2.OIS3N Mask                     */
#define TIM1_CR2_OIS3N_SHIFT                     (13U)                                               /**< TIM1_CR2.OIS3N Position                 */
#define TIM1_CR2_OIS3N(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_OIS3N_SHIFT))&TIM1_CR2_OIS3N_MASK) /**< TIM1_CR2.OIS3N Field                    */
#define TIM1_CR2_OIS4_MASK                       (0x4000U)                                           /**< TIM1_CR2.OIS4 Mask                      */
#define TIM1_CR2_OIS4_SHIFT                      (14U)                                               /**< TIM1_CR2.OIS4 Position                  */
#define TIM1_CR2_OIS4(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_CR2_OIS4_SHIFT))&TIM1_CR2_OIS4_MASK) /**< TIM1_CR2.OIS4 Field                     */
/** @} */

/** @name SMCR - slave mode control register */ /** @{ */
#define TIM1_SMCR_SMS_MASK                       (0x7U)                                              /**< TIM1_SMCR.SMS Mask                      */
#define TIM1_SMCR_SMS_SHIFT                      (0U)                                                /**< TIM1_SMCR.SMS Position                  */
#define TIM1_SMCR_SMS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SMCR_SMS_SHIFT))&TIM1_SMCR_SMS_MASK) /**< TIM1_SMCR.SMS Field                     */
#define TIM1_SMCR_TS_MASK                        (0x70U)                                             /**< TIM1_SMCR.TS Mask                       */
#define TIM1_SMCR_TS_SHIFT                       (4U)                                                /**< TIM1_SMCR.TS Position                   */
#define TIM1_SMCR_TS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_SMCR_TS_SHIFT))&TIM1_SMCR_TS_MASK) /**< TIM1_SMCR.TS Field                      */
#define TIM1_SMCR_MSM_MASK                       (0x80U)                                             /**< TIM1_SMCR.MSM Mask                      */
#define TIM1_SMCR_MSM_SHIFT                      (7U)                                                /**< TIM1_SMCR.MSM Position                  */
#define TIM1_SMCR_MSM(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SMCR_MSM_SHIFT))&TIM1_SMCR_MSM_MASK) /**< TIM1_SMCR.MSM Field                     */
#define TIM1_SMCR_ETF_MASK                       (0xF00U)                                            /**< TIM1_SMCR.ETF Mask                      */
#define TIM1_SMCR_ETF_SHIFT                      (8U)                                                /**< TIM1_SMCR.ETF Position                  */
#define TIM1_SMCR_ETF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SMCR_ETF_SHIFT))&TIM1_SMCR_ETF_MASK) /**< TIM1_SMCR.ETF Field                     */
#define TIM1_SMCR_ETPS_MASK                      (0x3000U)                                           /**< TIM1_SMCR.ETPS Mask                     */
#define TIM1_SMCR_ETPS_SHIFT                     (12U)                                               /**< TIM1_SMCR.ETPS Position                 */
#define TIM1_SMCR_ETPS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_SMCR_ETPS_SHIFT))&TIM1_SMCR_ETPS_MASK) /**< TIM1_SMCR.ETPS Field                    */
#define TIM1_SMCR_ECE_MASK                       (0x4000U)                                           /**< TIM1_SMCR.ECE Mask                      */
#define TIM1_SMCR_ECE_SHIFT                      (14U)                                               /**< TIM1_SMCR.ECE Position                  */
#define TIM1_SMCR_ECE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SMCR_ECE_SHIFT))&TIM1_SMCR_ECE_MASK) /**< TIM1_SMCR.ECE Field                     */
#define TIM1_SMCR_ETP_MASK                       (0x8000U)                                           /**< TIM1_SMCR.ETP Mask                      */
#define TIM1_SMCR_ETP_SHIFT                      (15U)                                               /**< TIM1_SMCR.ETP Position                  */
#define TIM1_SMCR_ETP(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SMCR_ETP_SHIFT))&TIM1_SMCR_ETP_MASK) /**< TIM1_SMCR.ETP Field                     */
/** @} */

/** @name DIER - DMA/Interrupt enable register */ /** @{ */
#define TIM1_DIER_UIE_MASK                       (0x1U)                                              /**< TIM1_DIER.UIE Mask                      */
#define TIM1_DIER_UIE_SHIFT                      (0U)                                                /**< TIM1_DIER.UIE Position                  */
#define TIM1_DIER_UIE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_UIE_SHIFT))&TIM1_DIER_UIE_MASK) /**< TIM1_DIER.UIE Field                     */
#define TIM1_DIER_CC1IE_MASK                     (0x2U)                                              /**< TIM1_DIER.CC1IE Mask                    */
#define TIM1_DIER_CC1IE_SHIFT                    (1U)                                                /**< TIM1_DIER.CC1IE Position                */
#define TIM1_DIER_CC1IE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_CC1IE_SHIFT))&TIM1_DIER_CC1IE_MASK) /**< TIM1_DIER.CC1IE Field                   */
#define TIM1_DIER_CC2IE_MASK                     (0x4U)                                              /**< TIM1_DIER.CC2IE Mask                    */
#define TIM1_DIER_CC2IE_SHIFT                    (2U)                                                /**< TIM1_DIER.CC2IE Position                */
#define TIM1_DIER_CC2IE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_CC2IE_SHIFT))&TIM1_DIER_CC2IE_MASK) /**< TIM1_DIER.CC2IE Field                   */
#define TIM1_DIER_CC3IE_MASK                     (0x8U)                                              /**< TIM1_DIER.CC3IE Mask                    */
#define TIM1_DIER_CC3IE_SHIFT                    (3U)                                                /**< TIM1_DIER.CC3IE Position                */
#define TIM1_DIER_CC3IE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_CC3IE_SHIFT))&TIM1_DIER_CC3IE_MASK) /**< TIM1_DIER.CC3IE Field                   */
#define TIM1_DIER_CC4IE_MASK                     (0x10U)                                             /**< TIM1_DIER.CC4IE Mask                    */
#define TIM1_DIER_CC4IE_SHIFT                    (4U)                                                /**< TIM1_DIER.CC4IE Position                */
#define TIM1_DIER_CC4IE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_CC4IE_SHIFT))&TIM1_DIER_CC4IE_MASK) /**< TIM1_DIER.CC4IE Field                   */
#define TIM1_DIER_COMIE_MASK                     (0x20U)                                             /**< TIM1_DIER.COMIE Mask                    */
#define TIM1_DIER_COMIE_SHIFT                    (5U)                                                /**< TIM1_DIER.COMIE Position                */
#define TIM1_DIER_COMIE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_COMIE_SHIFT))&TIM1_DIER_COMIE_MASK) /**< TIM1_DIER.COMIE Field                   */
#define TIM1_DIER_TIE_MASK                       (0x40U)                                             /**< TIM1_DIER.TIE Mask                      */
#define TIM1_DIER_TIE_SHIFT                      (6U)                                                /**< TIM1_DIER.TIE Position                  */
#define TIM1_DIER_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_TIE_SHIFT))&TIM1_DIER_TIE_MASK) /**< TIM1_DIER.TIE Field                     */
#define TIM1_DIER_BIE_MASK                       (0x80U)                                             /**< TIM1_DIER.BIE Mask                      */
#define TIM1_DIER_BIE_SHIFT                      (7U)                                                /**< TIM1_DIER.BIE Position                  */
#define TIM1_DIER_BIE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_BIE_SHIFT))&TIM1_DIER_BIE_MASK) /**< TIM1_DIER.BIE Field                     */
#define TIM1_DIER_UDE_MASK                       (0x100U)                                            /**< TIM1_DIER.UDE Mask                      */
#define TIM1_DIER_UDE_SHIFT                      (8U)                                                /**< TIM1_DIER.UDE Position                  */
#define TIM1_DIER_UDE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_UDE_SHIFT))&TIM1_DIER_UDE_MASK) /**< TIM1_DIER.UDE Field                     */
#define TIM1_DIER_CC1DE_MASK                     (0x200U)                                            /**< TIM1_DIER.CC1DE Mask                    */
#define TIM1_DIER_CC1DE_SHIFT                    (9U)                                                /**< TIM1_DIER.CC1DE Position                */
#define TIM1_DIER_CC1DE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_CC1DE_SHIFT))&TIM1_DIER_CC1DE_MASK) /**< TIM1_DIER.CC1DE Field                   */
#define TIM1_DIER_CC2DE_MASK                     (0x400U)                                            /**< TIM1_DIER.CC2DE Mask                    */
#define TIM1_DIER_CC2DE_SHIFT                    (10U)                                               /**< TIM1_DIER.CC2DE Position                */
#define TIM1_DIER_CC2DE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_CC2DE_SHIFT))&TIM1_DIER_CC2DE_MASK) /**< TIM1_DIER.CC2DE Field                   */
#define TIM1_DIER_CC3DE_MASK                     (0x800U)                                            /**< TIM1_DIER.CC3DE Mask                    */
#define TIM1_DIER_CC3DE_SHIFT                    (11U)                                               /**< TIM1_DIER.CC3DE Position                */
#define TIM1_DIER_CC3DE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_CC3DE_SHIFT))&TIM1_DIER_CC3DE_MASK) /**< TIM1_DIER.CC3DE Field                   */
#define TIM1_DIER_CC4DE_MASK                     (0x1000U)                                           /**< TIM1_DIER.CC4DE Mask                    */
#define TIM1_DIER_CC4DE_SHIFT                    (12U)                                               /**< TIM1_DIER.CC4DE Position                */
#define TIM1_DIER_CC4DE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_CC4DE_SHIFT))&TIM1_DIER_CC4DE_MASK) /**< TIM1_DIER.CC4DE Field                   */
#define TIM1_DIER_COMDE_MASK                     (0x2000U)                                           /**< TIM1_DIER.COMDE Mask                    */
#define TIM1_DIER_COMDE_SHIFT                    (13U)                                               /**< TIM1_DIER.COMDE Position                */
#define TIM1_DIER_COMDE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_COMDE_SHIFT))&TIM1_DIER_COMDE_MASK) /**< TIM1_DIER.COMDE Field                   */
#define TIM1_DIER_TDE_MASK                       (0x4000U)                                           /**< TIM1_DIER.TDE Mask                      */
#define TIM1_DIER_TDE_SHIFT                      (14U)                                               /**< TIM1_DIER.TDE Position                  */
#define TIM1_DIER_TDE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_DIER_TDE_SHIFT))&TIM1_DIER_TDE_MASK) /**< TIM1_DIER.TDE Field                     */
/** @} */

/** @name SR - status register */ /** @{ */
#define TIM1_SR_UIF_MASK                         (0x1U)                                              /**< TIM1_SR.UIF Mask                        */
#define TIM1_SR_UIF_SHIFT                        (0U)                                                /**< TIM1_SR.UIF Position                    */
#define TIM1_SR_UIF(x)                           (((uint32_t)(((uint32_t)(x))<<TIM1_SR_UIF_SHIFT))&TIM1_SR_UIF_MASK) /**< TIM1_SR.UIF Field                       */
#define TIM1_SR_CC1IF_MASK                       (0x2U)                                              /**< TIM1_SR.CC1IF Mask                      */
#define TIM1_SR_CC1IF_SHIFT                      (1U)                                                /**< TIM1_SR.CC1IF Position                  */
#define TIM1_SR_CC1IF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_CC1IF_SHIFT))&TIM1_SR_CC1IF_MASK) /**< TIM1_SR.CC1IF Field                     */
#define TIM1_SR_CC2IF_MASK                       (0x4U)                                              /**< TIM1_SR.CC2IF Mask                      */
#define TIM1_SR_CC2IF_SHIFT                      (2U)                                                /**< TIM1_SR.CC2IF Position                  */
#define TIM1_SR_CC2IF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_CC2IF_SHIFT))&TIM1_SR_CC2IF_MASK) /**< TIM1_SR.CC2IF Field                     */
#define TIM1_SR_CC3IF_MASK                       (0x8U)                                              /**< TIM1_SR.CC3IF Mask                      */
#define TIM1_SR_CC3IF_SHIFT                      (3U)                                                /**< TIM1_SR.CC3IF Position                  */
#define TIM1_SR_CC3IF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_CC3IF_SHIFT))&TIM1_SR_CC3IF_MASK) /**< TIM1_SR.CC3IF Field                     */
#define TIM1_SR_CC4IF_MASK                       (0x10U)                                             /**< TIM1_SR.CC4IF Mask                      */
#define TIM1_SR_CC4IF_SHIFT                      (4U)                                                /**< TIM1_SR.CC4IF Position                  */
#define TIM1_SR_CC4IF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_CC4IF_SHIFT))&TIM1_SR_CC4IF_MASK) /**< TIM1_SR.CC4IF Field                     */
#define TIM1_SR_COMIF_MASK                       (0x20U)                                             /**< TIM1_SR.COMIF Mask                      */
#define TIM1_SR_COMIF_SHIFT                      (5U)                                                /**< TIM1_SR.COMIF Position                  */
#define TIM1_SR_COMIF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_COMIF_SHIFT))&TIM1_SR_COMIF_MASK) /**< TIM1_SR.COMIF Field                     */
#define TIM1_SR_TIF_MASK                         (0x40U)                                             /**< TIM1_SR.TIF Mask                        */
#define TIM1_SR_TIF_SHIFT                        (6U)                                                /**< TIM1_SR.TIF Position                    */
#define TIM1_SR_TIF(x)                           (((uint32_t)(((uint32_t)(x))<<TIM1_SR_TIF_SHIFT))&TIM1_SR_TIF_MASK) /**< TIM1_SR.TIF Field                       */
#define TIM1_SR_BIF_MASK                         (0x80U)                                             /**< TIM1_SR.BIF Mask                        */
#define TIM1_SR_BIF_SHIFT                        (7U)                                                /**< TIM1_SR.BIF Position                    */
#define TIM1_SR_BIF(x)                           (((uint32_t)(((uint32_t)(x))<<TIM1_SR_BIF_SHIFT))&TIM1_SR_BIF_MASK) /**< TIM1_SR.BIF Field                       */
#define TIM1_SR_CC1OF_MASK                       (0x200U)                                            /**< TIM1_SR.CC1OF Mask                      */
#define TIM1_SR_CC1OF_SHIFT                      (9U)                                                /**< TIM1_SR.CC1OF Position                  */
#define TIM1_SR_CC1OF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_CC1OF_SHIFT))&TIM1_SR_CC1OF_MASK) /**< TIM1_SR.CC1OF Field                     */
#define TIM1_SR_CC2OF_MASK                       (0x400U)                                            /**< TIM1_SR.CC2OF Mask                      */
#define TIM1_SR_CC2OF_SHIFT                      (10U)                                               /**< TIM1_SR.CC2OF Position                  */
#define TIM1_SR_CC2OF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_CC2OF_SHIFT))&TIM1_SR_CC2OF_MASK) /**< TIM1_SR.CC2OF Field                     */
#define TIM1_SR_CC3OF_MASK                       (0x800U)                                            /**< TIM1_SR.CC3OF Mask                      */
#define TIM1_SR_CC3OF_SHIFT                      (11U)                                               /**< TIM1_SR.CC3OF Position                  */
#define TIM1_SR_CC3OF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_CC3OF_SHIFT))&TIM1_SR_CC3OF_MASK) /**< TIM1_SR.CC3OF Field                     */
#define TIM1_SR_CC4OF_MASK                       (0x1000U)                                           /**< TIM1_SR.CC4OF Mask                      */
#define TIM1_SR_CC4OF_SHIFT                      (12U)                                               /**< TIM1_SR.CC4OF Position                  */
#define TIM1_SR_CC4OF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_SR_CC4OF_SHIFT))&TIM1_SR_CC4OF_MASK) /**< TIM1_SR.CC4OF Field                     */
/** @} */

/** @name EGR - event generation register */ /** @{ */
#define TIM1_EGR_UG_MASK                         (0x1U)                                              /**< TIM1_EGR.UG Mask                        */
#define TIM1_EGR_UG_SHIFT                        (0U)                                                /**< TIM1_EGR.UG Position                    */
#define TIM1_EGR_UG(x)                           (((uint32_t)(((uint32_t)(x))<<TIM1_EGR_UG_SHIFT))&TIM1_EGR_UG_MASK) /**< TIM1_EGR.UG Field                       */
#define TIM1_EGR_CC1G_MASK                       (0x2U)                                              /**< TIM1_EGR.CC1G Mask                      */
#define TIM1_EGR_CC1G_SHIFT                      (1U)                                                /**< TIM1_EGR.CC1G Position                  */
#define TIM1_EGR_CC1G(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_EGR_CC1G_SHIFT))&TIM1_EGR_CC1G_MASK) /**< TIM1_EGR.CC1G Field                     */
#define TIM1_EGR_CC2G_MASK                       (0x4U)                                              /**< TIM1_EGR.CC2G Mask                      */
#define TIM1_EGR_CC2G_SHIFT                      (2U)                                                /**< TIM1_EGR.CC2G Position                  */
#define TIM1_EGR_CC2G(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_EGR_CC2G_SHIFT))&TIM1_EGR_CC2G_MASK) /**< TIM1_EGR.CC2G Field                     */
#define TIM1_EGR_CC3G_MASK                       (0x8U)                                              /**< TIM1_EGR.CC3G Mask                      */
#define TIM1_EGR_CC3G_SHIFT                      (3U)                                                /**< TIM1_EGR.CC3G Position                  */
#define TIM1_EGR_CC3G(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_EGR_CC3G_SHIFT))&TIM1_EGR_CC3G_MASK) /**< TIM1_EGR.CC3G Field                     */
#define TIM1_EGR_CC4G_MASK                       (0x10U)                                             /**< TIM1_EGR.CC4G Mask                      */
#define TIM1_EGR_CC4G_SHIFT                      (4U)                                                /**< TIM1_EGR.CC4G Position                  */
#define TIM1_EGR_CC4G(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_EGR_CC4G_SHIFT))&TIM1_EGR_CC4G_MASK) /**< TIM1_EGR.CC4G Field                     */
#define TIM1_EGR_COMG_MASK                       (0x20U)                                             /**< TIM1_EGR.COMG Mask                      */
#define TIM1_EGR_COMG_SHIFT                      (5U)                                                /**< TIM1_EGR.COMG Position                  */
#define TIM1_EGR_COMG(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_EGR_COMG_SHIFT))&TIM1_EGR_COMG_MASK) /**< TIM1_EGR.COMG Field                     */
#define TIM1_EGR_TG_MASK                         (0x40U)                                             /**< TIM1_EGR.TG Mask                        */
#define TIM1_EGR_TG_SHIFT                        (6U)                                                /**< TIM1_EGR.TG Position                    */
#define TIM1_EGR_TG(x)                           (((uint32_t)(((uint32_t)(x))<<TIM1_EGR_TG_SHIFT))&TIM1_EGR_TG_MASK) /**< TIM1_EGR.TG Field                       */
#define TIM1_EGR_BG_MASK                         (0x80U)                                             /**< TIM1_EGR.BG Mask                        */
#define TIM1_EGR_BG_SHIFT                        (7U)                                                /**< TIM1_EGR.BG Position                    */
#define TIM1_EGR_BG(x)                           (((uint32_t)(((uint32_t)(x))<<TIM1_EGR_BG_SHIFT))&TIM1_EGR_BG_MASK) /**< TIM1_EGR.BG Field                       */
/** @} */

/** @name CCMR1_Input - capture/compare mode register 1 (input */ /** @{ */
#define TIM1_CCMR1_Input_CC1S_MASK               (0x3U)                                              /**< TIM1_CCMR1_Input.CC1S Mask              */
#define TIM1_CCMR1_Input_CC1S_SHIFT              (0U)                                                /**< TIM1_CCMR1_Input.CC1S Position          */
#define TIM1_CCMR1_Input_CC1S(x)                 (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Input_CC1S_SHIFT))&TIM1_CCMR1_Input_CC1S_MASK) /**< TIM1_CCMR1_Input.CC1S Field             */
#define TIM1_CCMR1_Input_IC1PCS_MASK             (0xCU)                                              /**< TIM1_CCMR1_Input.IC1PCS Mask            */
#define TIM1_CCMR1_Input_IC1PCS_SHIFT            (2U)                                                /**< TIM1_CCMR1_Input.IC1PCS Position        */
#define TIM1_CCMR1_Input_IC1PCS(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Input_IC1PCS_SHIFT))&TIM1_CCMR1_Input_IC1PCS_MASK) /**< TIM1_CCMR1_Input.IC1PCS Field           */
#define TIM1_CCMR1_Input_IC1F_MASK               (0xF0U)                                             /**< TIM1_CCMR1_Input.IC1F Mask              */
#define TIM1_CCMR1_Input_IC1F_SHIFT              (4U)                                                /**< TIM1_CCMR1_Input.IC1F Position          */
#define TIM1_CCMR1_Input_IC1F(x)                 (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Input_IC1F_SHIFT))&TIM1_CCMR1_Input_IC1F_MASK) /**< TIM1_CCMR1_Input.IC1F Field             */
#define TIM1_CCMR1_Input_CC2S_MASK               (0x300U)                                            /**< TIM1_CCMR1_Input.CC2S Mask              */
#define TIM1_CCMR1_Input_CC2S_SHIFT              (8U)                                                /**< TIM1_CCMR1_Input.CC2S Position          */
#define TIM1_CCMR1_Input_CC2S(x)                 (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Input_CC2S_SHIFT))&TIM1_CCMR1_Input_CC2S_MASK) /**< TIM1_CCMR1_Input.CC2S Field             */
#define TIM1_CCMR1_Input_IC2PCS_MASK             (0xC00U)                                            /**< TIM1_CCMR1_Input.IC2PCS Mask            */
#define TIM1_CCMR1_Input_IC2PCS_SHIFT            (10U)                                               /**< TIM1_CCMR1_Input.IC2PCS Position        */
#define TIM1_CCMR1_Input_IC2PCS(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Input_IC2PCS_SHIFT))&TIM1_CCMR1_Input_IC2PCS_MASK) /**< TIM1_CCMR1_Input.IC2PCS Field           */
#define TIM1_CCMR1_Input_IC2F_MASK               (0xF000U)                                           /**< TIM1_CCMR1_Input.IC2F Mask              */
#define TIM1_CCMR1_Input_IC2F_SHIFT              (12U)                                               /**< TIM1_CCMR1_Input.IC2F Position          */
#define TIM1_CCMR1_Input_IC2F(x)                 (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Input_IC2F_SHIFT))&TIM1_CCMR1_Input_IC2F_MASK) /**< TIM1_CCMR1_Input.IC2F Field             */
/** @} */

/** @name CCMR1_Output - capture/compare mode register (output */ /** @{ */
#define TIM1_CCMR1_Output_CC1S_MASK              (0x3U)                                              /**< TIM1_CCMR1_Output.CC1S Mask             */
#define TIM1_CCMR1_Output_CC1S_SHIFT             (0U)                                                /**< TIM1_CCMR1_Output.CC1S Position         */
#define TIM1_CCMR1_Output_CC1S(x)                (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_CC1S_SHIFT))&TIM1_CCMR1_Output_CC1S_MASK) /**< TIM1_CCMR1_Output.CC1S Field            */
#define TIM1_CCMR1_Output_OC1FE_MASK             (0x4U)                                              /**< TIM1_CCMR1_Output.OC1FE Mask            */
#define TIM1_CCMR1_Output_OC1FE_SHIFT            (2U)                                                /**< TIM1_CCMR1_Output.OC1FE Position        */
#define TIM1_CCMR1_Output_OC1FE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_OC1FE_SHIFT))&TIM1_CCMR1_Output_OC1FE_MASK) /**< TIM1_CCMR1_Output.OC1FE Field           */
#define TIM1_CCMR1_Output_OC1PE_MASK             (0x8U)                                              /**< TIM1_CCMR1_Output.OC1PE Mask            */
#define TIM1_CCMR1_Output_OC1PE_SHIFT            (3U)                                                /**< TIM1_CCMR1_Output.OC1PE Position        */
#define TIM1_CCMR1_Output_OC1PE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_OC1PE_SHIFT))&TIM1_CCMR1_Output_OC1PE_MASK) /**< TIM1_CCMR1_Output.OC1PE Field           */
#define TIM1_CCMR1_Output_OC1M_MASK              (0x70U)                                             /**< TIM1_CCMR1_Output.OC1M Mask             */
#define TIM1_CCMR1_Output_OC1M_SHIFT             (4U)                                                /**< TIM1_CCMR1_Output.OC1M Position         */
#define TIM1_CCMR1_Output_OC1M(x)                (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_OC1M_SHIFT))&TIM1_CCMR1_Output_OC1M_MASK) /**< TIM1_CCMR1_Output.OC1M Field            */
#define TIM1_CCMR1_Output_OC1CE_MASK             (0x80U)                                             /**< TIM1_CCMR1_Output.OC1CE Mask            */
#define TIM1_CCMR1_Output_OC1CE_SHIFT            (7U)                                                /**< TIM1_CCMR1_Output.OC1CE Position        */
#define TIM1_CCMR1_Output_OC1CE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_OC1CE_SHIFT))&TIM1_CCMR1_Output_OC1CE_MASK) /**< TIM1_CCMR1_Output.OC1CE Field           */
#define TIM1_CCMR1_Output_CC2S_MASK              (0x300U)                                            /**< TIM1_CCMR1_Output.CC2S Mask             */
#define TIM1_CCMR1_Output_CC2S_SHIFT             (8U)                                                /**< TIM1_CCMR1_Output.CC2S Position         */
#define TIM1_CCMR1_Output_CC2S(x)                (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_CC2S_SHIFT))&TIM1_CCMR1_Output_CC2S_MASK) /**< TIM1_CCMR1_Output.CC2S Field            */
#define TIM1_CCMR1_Output_OC2FE_MASK             (0x400U)                                            /**< TIM1_CCMR1_Output.OC2FE Mask            */
#define TIM1_CCMR1_Output_OC2FE_SHIFT            (10U)                                               /**< TIM1_CCMR1_Output.OC2FE Position        */
#define TIM1_CCMR1_Output_OC2FE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_OC2FE_SHIFT))&TIM1_CCMR1_Output_OC2FE_MASK) /**< TIM1_CCMR1_Output.OC2FE Field           */
#define TIM1_CCMR1_Output_OC2PE_MASK             (0x800U)                                            /**< TIM1_CCMR1_Output.OC2PE Mask            */
#define TIM1_CCMR1_Output_OC2PE_SHIFT            (11U)                                               /**< TIM1_CCMR1_Output.OC2PE Position        */
#define TIM1_CCMR1_Output_OC2PE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_OC2PE_SHIFT))&TIM1_CCMR1_Output_OC2PE_MASK) /**< TIM1_CCMR1_Output.OC2PE Field           */
#define TIM1_CCMR1_Output_OC2M_MASK              (0x7000U)                                           /**< TIM1_CCMR1_Output.OC2M Mask             */
#define TIM1_CCMR1_Output_OC2M_SHIFT             (12U)                                               /**< TIM1_CCMR1_Output.OC2M Position         */
#define TIM1_CCMR1_Output_OC2M(x)                (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_OC2M_SHIFT))&TIM1_CCMR1_Output_OC2M_MASK) /**< TIM1_CCMR1_Output.OC2M Field            */
#define TIM1_CCMR1_Output_OC2CE_MASK             (0x8000U)                                           /**< TIM1_CCMR1_Output.OC2CE Mask            */
#define TIM1_CCMR1_Output_OC2CE_SHIFT            (15U)                                               /**< TIM1_CCMR1_Output.OC2CE Position        */
#define TIM1_CCMR1_Output_OC2CE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR1_Output_OC2CE_SHIFT))&TIM1_CCMR1_Output_OC2CE_MASK) /**< TIM1_CCMR1_Output.OC2CE Field           */
/** @} */

/** @name CCMR2_Input - capture/compare mode register 2 (input */ /** @{ */
#define TIM1_CCMR2_Input_CC3S_MASK               (0x3U)                                              /**< TIM1_CCMR2_Input.CC3S Mask              */
#define TIM1_CCMR2_Input_CC3S_SHIFT              (0U)                                                /**< TIM1_CCMR2_Input.CC3S Position          */
#define TIM1_CCMR2_Input_CC3S(x)                 (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Input_CC3S_SHIFT))&TIM1_CCMR2_Input_CC3S_MASK) /**< TIM1_CCMR2_Input.CC3S Field             */
#define TIM1_CCMR2_Input_IC3PSC_MASK             (0xCU)                                              /**< TIM1_CCMR2_Input.IC3PSC Mask            */
#define TIM1_CCMR2_Input_IC3PSC_SHIFT            (2U)                                                /**< TIM1_CCMR2_Input.IC3PSC Position        */
#define TIM1_CCMR2_Input_IC3PSC(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Input_IC3PSC_SHIFT))&TIM1_CCMR2_Input_IC3PSC_MASK) /**< TIM1_CCMR2_Input.IC3PSC Field           */
#define TIM1_CCMR2_Input_IC3F_MASK               (0xF0U)                                             /**< TIM1_CCMR2_Input.IC3F Mask              */
#define TIM1_CCMR2_Input_IC3F_SHIFT              (4U)                                                /**< TIM1_CCMR2_Input.IC3F Position          */
#define TIM1_CCMR2_Input_IC3F(x)                 (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Input_IC3F_SHIFT))&TIM1_CCMR2_Input_IC3F_MASK) /**< TIM1_CCMR2_Input.IC3F Field             */
#define TIM1_CCMR2_Input_CC4S_MASK               (0x300U)                                            /**< TIM1_CCMR2_Input.CC4S Mask              */
#define TIM1_CCMR2_Input_CC4S_SHIFT              (8U)                                                /**< TIM1_CCMR2_Input.CC4S Position          */
#define TIM1_CCMR2_Input_CC4S(x)                 (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Input_CC4S_SHIFT))&TIM1_CCMR2_Input_CC4S_MASK) /**< TIM1_CCMR2_Input.CC4S Field             */
#define TIM1_CCMR2_Input_IC4PSC_MASK             (0xC00U)                                            /**< TIM1_CCMR2_Input.IC4PSC Mask            */
#define TIM1_CCMR2_Input_IC4PSC_SHIFT            (10U)                                               /**< TIM1_CCMR2_Input.IC4PSC Position        */
#define TIM1_CCMR2_Input_IC4PSC(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Input_IC4PSC_SHIFT))&TIM1_CCMR2_Input_IC4PSC_MASK) /**< TIM1_CCMR2_Input.IC4PSC Field           */
#define TIM1_CCMR2_Input_IC4F_MASK               (0xF000U)                                           /**< TIM1_CCMR2_Input.IC4F Mask              */
#define TIM1_CCMR2_Input_IC4F_SHIFT              (12U)                                               /**< TIM1_CCMR2_Input.IC4F Position          */
#define TIM1_CCMR2_Input_IC4F(x)                 (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Input_IC4F_SHIFT))&TIM1_CCMR2_Input_IC4F_MASK) /**< TIM1_CCMR2_Input.IC4F Field             */
/** @} */

/** @name CCMR2_Output - capture/compare mode register (output */ /** @{ */
#define TIM1_CCMR2_Output_CC3S_MASK              (0x3U)                                              /**< TIM1_CCMR2_Output.CC3S Mask             */
#define TIM1_CCMR2_Output_CC3S_SHIFT             (0U)                                                /**< TIM1_CCMR2_Output.CC3S Position         */
#define TIM1_CCMR2_Output_CC3S(x)                (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_CC3S_SHIFT))&TIM1_CCMR2_Output_CC3S_MASK) /**< TIM1_CCMR2_Output.CC3S Field            */
#define TIM1_CCMR2_Output_OC3FE_MASK             (0x4U)                                              /**< TIM1_CCMR2_Output.OC3FE Mask            */
#define TIM1_CCMR2_Output_OC3FE_SHIFT            (2U)                                                /**< TIM1_CCMR2_Output.OC3FE Position        */
#define TIM1_CCMR2_Output_OC3FE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_OC3FE_SHIFT))&TIM1_CCMR2_Output_OC3FE_MASK) /**< TIM1_CCMR2_Output.OC3FE Field           */
#define TIM1_CCMR2_Output_OC3PE_MASK             (0x8U)                                              /**< TIM1_CCMR2_Output.OC3PE Mask            */
#define TIM1_CCMR2_Output_OC3PE_SHIFT            (3U)                                                /**< TIM1_CCMR2_Output.OC3PE Position        */
#define TIM1_CCMR2_Output_OC3PE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_OC3PE_SHIFT))&TIM1_CCMR2_Output_OC3PE_MASK) /**< TIM1_CCMR2_Output.OC3PE Field           */
#define TIM1_CCMR2_Output_OC3M_MASK              (0x70U)                                             /**< TIM1_CCMR2_Output.OC3M Mask             */
#define TIM1_CCMR2_Output_OC3M_SHIFT             (4U)                                                /**< TIM1_CCMR2_Output.OC3M Position         */
#define TIM1_CCMR2_Output_OC3M(x)                (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_OC3M_SHIFT))&TIM1_CCMR2_Output_OC3M_MASK) /**< TIM1_CCMR2_Output.OC3M Field            */
#define TIM1_CCMR2_Output_OC3CE_MASK             (0x80U)                                             /**< TIM1_CCMR2_Output.OC3CE Mask            */
#define TIM1_CCMR2_Output_OC3CE_SHIFT            (7U)                                                /**< TIM1_CCMR2_Output.OC3CE Position        */
#define TIM1_CCMR2_Output_OC3CE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_OC3CE_SHIFT))&TIM1_CCMR2_Output_OC3CE_MASK) /**< TIM1_CCMR2_Output.OC3CE Field           */
#define TIM1_CCMR2_Output_CC4S_MASK              (0x300U)                                            /**< TIM1_CCMR2_Output.CC4S Mask             */
#define TIM1_CCMR2_Output_CC4S_SHIFT             (8U)                                                /**< TIM1_CCMR2_Output.CC4S Position         */
#define TIM1_CCMR2_Output_CC4S(x)                (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_CC4S_SHIFT))&TIM1_CCMR2_Output_CC4S_MASK) /**< TIM1_CCMR2_Output.CC4S Field            */
#define TIM1_CCMR2_Output_OC4FE_MASK             (0x400U)                                            /**< TIM1_CCMR2_Output.OC4FE Mask            */
#define TIM1_CCMR2_Output_OC4FE_SHIFT            (10U)                                               /**< TIM1_CCMR2_Output.OC4FE Position        */
#define TIM1_CCMR2_Output_OC4FE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_OC4FE_SHIFT))&TIM1_CCMR2_Output_OC4FE_MASK) /**< TIM1_CCMR2_Output.OC4FE Field           */
#define TIM1_CCMR2_Output_OC4PE_MASK             (0x800U)                                            /**< TIM1_CCMR2_Output.OC4PE Mask            */
#define TIM1_CCMR2_Output_OC4PE_SHIFT            (11U)                                               /**< TIM1_CCMR2_Output.OC4PE Position        */
#define TIM1_CCMR2_Output_OC4PE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_OC4PE_SHIFT))&TIM1_CCMR2_Output_OC4PE_MASK) /**< TIM1_CCMR2_Output.OC4PE Field           */
#define TIM1_CCMR2_Output_OC4M_MASK              (0x7000U)                                           /**< TIM1_CCMR2_Output.OC4M Mask             */
#define TIM1_CCMR2_Output_OC4M_SHIFT             (12U)                                               /**< TIM1_CCMR2_Output.OC4M Position         */
#define TIM1_CCMR2_Output_OC4M(x)                (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_OC4M_SHIFT))&TIM1_CCMR2_Output_OC4M_MASK) /**< TIM1_CCMR2_Output.OC4M Field            */
#define TIM1_CCMR2_Output_OC4CE_MASK             (0x8000U)                                           /**< TIM1_CCMR2_Output.OC4CE Mask            */
#define TIM1_CCMR2_Output_OC4CE_SHIFT            (15U)                                               /**< TIM1_CCMR2_Output.OC4CE Position        */
#define TIM1_CCMR2_Output_OC4CE(x)               (((uint32_t)(((uint32_t)(x))<<TIM1_CCMR2_Output_OC4CE_SHIFT))&TIM1_CCMR2_Output_OC4CE_MASK) /**< TIM1_CCMR2_Output.OC4CE Field           */
/** @} */

/** @name CCER - capture/compare enable */ /** @{ */
#define TIM1_CCER_CC1E_MASK                      (0x1U)                                              /**< TIM1_CCER.CC1E Mask                     */
#define TIM1_CCER_CC1E_SHIFT                     (0U)                                                /**< TIM1_CCER.CC1E Position                 */
#define TIM1_CCER_CC1E(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC1E_SHIFT))&TIM1_CCER_CC1E_MASK) /**< TIM1_CCER.CC1E Field                    */
#define TIM1_CCER_CC1P_MASK                      (0x2U)                                              /**< TIM1_CCER.CC1P Mask                     */
#define TIM1_CCER_CC1P_SHIFT                     (1U)                                                /**< TIM1_CCER.CC1P Position                 */
#define TIM1_CCER_CC1P(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC1P_SHIFT))&TIM1_CCER_CC1P_MASK) /**< TIM1_CCER.CC1P Field                    */
#define TIM1_CCER_CC1NE_MASK                     (0x4U)                                              /**< TIM1_CCER.CC1NE Mask                    */
#define TIM1_CCER_CC1NE_SHIFT                    (2U)                                                /**< TIM1_CCER.CC1NE Position                */
#define TIM1_CCER_CC1NE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC1NE_SHIFT))&TIM1_CCER_CC1NE_MASK) /**< TIM1_CCER.CC1NE Field                   */
#define TIM1_CCER_CC1NP_MASK                     (0x8U)                                              /**< TIM1_CCER.CC1NP Mask                    */
#define TIM1_CCER_CC1NP_SHIFT                    (3U)                                                /**< TIM1_CCER.CC1NP Position                */
#define TIM1_CCER_CC1NP(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC1NP_SHIFT))&TIM1_CCER_CC1NP_MASK) /**< TIM1_CCER.CC1NP Field                   */
#define TIM1_CCER_CC2E_MASK                      (0x10U)                                             /**< TIM1_CCER.CC2E Mask                     */
#define TIM1_CCER_CC2E_SHIFT                     (4U)                                                /**< TIM1_CCER.CC2E Position                 */
#define TIM1_CCER_CC2E(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC2E_SHIFT))&TIM1_CCER_CC2E_MASK) /**< TIM1_CCER.CC2E Field                    */
#define TIM1_CCER_CC2P_MASK                      (0x20U)                                             /**< TIM1_CCER.CC2P Mask                     */
#define TIM1_CCER_CC2P_SHIFT                     (5U)                                                /**< TIM1_CCER.CC2P Position                 */
#define TIM1_CCER_CC2P(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC2P_SHIFT))&TIM1_CCER_CC2P_MASK) /**< TIM1_CCER.CC2P Field                    */
#define TIM1_CCER_CC2NE_MASK                     (0x40U)                                             /**< TIM1_CCER.CC2NE Mask                    */
#define TIM1_CCER_CC2NE_SHIFT                    (6U)                                                /**< TIM1_CCER.CC2NE Position                */
#define TIM1_CCER_CC2NE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC2NE_SHIFT))&TIM1_CCER_CC2NE_MASK) /**< TIM1_CCER.CC2NE Field                   */
#define TIM1_CCER_CC2NP_MASK                     (0x80U)                                             /**< TIM1_CCER.CC2NP Mask                    */
#define TIM1_CCER_CC2NP_SHIFT                    (7U)                                                /**< TIM1_CCER.CC2NP Position                */
#define TIM1_CCER_CC2NP(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC2NP_SHIFT))&TIM1_CCER_CC2NP_MASK) /**< TIM1_CCER.CC2NP Field                   */
#define TIM1_CCER_CC3E_MASK                      (0x100U)                                            /**< TIM1_CCER.CC3E Mask                     */
#define TIM1_CCER_CC3E_SHIFT                     (8U)                                                /**< TIM1_CCER.CC3E Position                 */
#define TIM1_CCER_CC3E(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC3E_SHIFT))&TIM1_CCER_CC3E_MASK) /**< TIM1_CCER.CC3E Field                    */
#define TIM1_CCER_CC3P_MASK                      (0x200U)                                            /**< TIM1_CCER.CC3P Mask                     */
#define TIM1_CCER_CC3P_SHIFT                     (9U)                                                /**< TIM1_CCER.CC3P Position                 */
#define TIM1_CCER_CC3P(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC3P_SHIFT))&TIM1_CCER_CC3P_MASK) /**< TIM1_CCER.CC3P Field                    */
#define TIM1_CCER_CC3NE_MASK                     (0x400U)                                            /**< TIM1_CCER.CC3NE Mask                    */
#define TIM1_CCER_CC3NE_SHIFT                    (10U)                                               /**< TIM1_CCER.CC3NE Position                */
#define TIM1_CCER_CC3NE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC3NE_SHIFT))&TIM1_CCER_CC3NE_MASK) /**< TIM1_CCER.CC3NE Field                   */
#define TIM1_CCER_CC3NP_MASK                     (0x800U)                                            /**< TIM1_CCER.CC3NP Mask                    */
#define TIM1_CCER_CC3NP_SHIFT                    (11U)                                               /**< TIM1_CCER.CC3NP Position                */
#define TIM1_CCER_CC3NP(x)                       (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC3NP_SHIFT))&TIM1_CCER_CC3NP_MASK) /**< TIM1_CCER.CC3NP Field                   */
#define TIM1_CCER_CC4E_MASK                      (0x1000U)                                           /**< TIM1_CCER.CC4E Mask                     */
#define TIM1_CCER_CC4E_SHIFT                     (12U)                                               /**< TIM1_CCER.CC4E Position                 */
#define TIM1_CCER_CC4E(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC4E_SHIFT))&TIM1_CCER_CC4E_MASK) /**< TIM1_CCER.CC4E Field                    */
#define TIM1_CCER_CC4P_MASK                      (0x2000U)                                           /**< TIM1_CCER.CC4P Mask                     */
#define TIM1_CCER_CC4P_SHIFT                     (13U)                                               /**< TIM1_CCER.CC4P Position                 */
#define TIM1_CCER_CC4P(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_CCER_CC4P_SHIFT))&TIM1_CCER_CC4P_MASK) /**< TIM1_CCER.CC4P Field                    */
/** @} */

/** @name CNT - counter */ /** @{ */
#define TIM1_CNT_CNT_MASK                        (0xFFFFU)                                           /**< TIM1_CNT.CNT Mask                       */
#define TIM1_CNT_CNT_SHIFT                       (0U)                                                /**< TIM1_CNT.CNT Position                   */
#define TIM1_CNT_CNT(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CNT_CNT_SHIFT))&TIM1_CNT_CNT_MASK) /**< TIM1_CNT.CNT Field                      */
/** @} */

/** @name PSC - prescaler */ /** @{ */
#define TIM1_PSC_PSC_MASK                        (0xFFFFU)                                           /**< TIM1_PSC.PSC Mask                       */
#define TIM1_PSC_PSC_SHIFT                       (0U)                                                /**< TIM1_PSC.PSC Position                   */
#define TIM1_PSC_PSC(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_PSC_PSC_SHIFT))&TIM1_PSC_PSC_MASK) /**< TIM1_PSC.PSC Field                      */
/** @} */

/** @name ARR - auto-reload register */ /** @{ */
#define TIM1_ARR_ARR_MASK                        (0xFFFFU)                                           /**< TIM1_ARR.ARR Mask                       */
#define TIM1_ARR_ARR_SHIFT                       (0U)                                                /**< TIM1_ARR.ARR Position                   */
#define TIM1_ARR_ARR(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_ARR_ARR_SHIFT))&TIM1_ARR_ARR_MASK) /**< TIM1_ARR.ARR Field                      */
/** @} */

/** @name RCR - repetition counter register */ /** @{ */
#define TIM1_RCR_REP_MASK                        (0xFFU)                                             /**< TIM1_RCR.REP Mask                       */
#define TIM1_RCR_REP_SHIFT                       (0U)                                                /**< TIM1_RCR.REP Position                   */
#define TIM1_RCR_REP(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_RCR_REP_SHIFT))&TIM1_RCR_REP_MASK) /**< TIM1_RCR.REP Field                      */
/** @} */

/** @name CCR - capture/compare register %s */ /** @{ */
#define TIM1_CCR_CCR_MASK                        (0xFFFFU)                                           /**< TIM1_CCR.CCR Mask                       */
#define TIM1_CCR_CCR_SHIFT                       (0U)                                                /**< TIM1_CCR.CCR Position                   */
#define TIM1_CCR_CCR(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_CCR_CCR_SHIFT))&TIM1_CCR_CCR_MASK) /**< TIM1_CCR.CCR Field                      */
/** @} */

/** @name BDTR - break and dead-time register */ /** @{ */
#define TIM1_BDTR_DTG_MASK                       (0xFFU)                                             /**< TIM1_BDTR.DTG Mask                      */
#define TIM1_BDTR_DTG_SHIFT                      (0U)                                                /**< TIM1_BDTR.DTG Position                  */
#define TIM1_BDTR_DTG(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_BDTR_DTG_SHIFT))&TIM1_BDTR_DTG_MASK) /**< TIM1_BDTR.DTG Field                     */
#define TIM1_BDTR_LOCK_MASK                      (0x300U)                                            /**< TIM1_BDTR.LOCK Mask                     */
#define TIM1_BDTR_LOCK_SHIFT                     (8U)                                                /**< TIM1_BDTR.LOCK Position                 */
#define TIM1_BDTR_LOCK(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_BDTR_LOCK_SHIFT))&TIM1_BDTR_LOCK_MASK) /**< TIM1_BDTR.LOCK Field                    */
#define TIM1_BDTR_OSSI_MASK                      (0x400U)                                            /**< TIM1_BDTR.OSSI Mask                     */
#define TIM1_BDTR_OSSI_SHIFT                     (10U)                                               /**< TIM1_BDTR.OSSI Position                 */
#define TIM1_BDTR_OSSI(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_BDTR_OSSI_SHIFT))&TIM1_BDTR_OSSI_MASK) /**< TIM1_BDTR.OSSI Field                    */
#define TIM1_BDTR_OSSR_MASK                      (0x800U)                                            /**< TIM1_BDTR.OSSR Mask                     */
#define TIM1_BDTR_OSSR_SHIFT                     (11U)                                               /**< TIM1_BDTR.OSSR Position                 */
#define TIM1_BDTR_OSSR(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_BDTR_OSSR_SHIFT))&TIM1_BDTR_OSSR_MASK) /**< TIM1_BDTR.OSSR Field                    */
#define TIM1_BDTR_BKE_MASK                       (0x1000U)                                           /**< TIM1_BDTR.BKE Mask                      */
#define TIM1_BDTR_BKE_SHIFT                      (12U)                                               /**< TIM1_BDTR.BKE Position                  */
#define TIM1_BDTR_BKE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_BDTR_BKE_SHIFT))&TIM1_BDTR_BKE_MASK) /**< TIM1_BDTR.BKE Field                     */
#define TIM1_BDTR_BKP_MASK                       (0x2000U)                                           /**< TIM1_BDTR.BKP Mask                      */
#define TIM1_BDTR_BKP_SHIFT                      (13U)                                               /**< TIM1_BDTR.BKP Position                  */
#define TIM1_BDTR_BKP(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_BDTR_BKP_SHIFT))&TIM1_BDTR_BKP_MASK) /**< TIM1_BDTR.BKP Field                     */
#define TIM1_BDTR_AOE_MASK                       (0x4000U)                                           /**< TIM1_BDTR.AOE Mask                      */
#define TIM1_BDTR_AOE_SHIFT                      (14U)                                               /**< TIM1_BDTR.AOE Position                  */
#define TIM1_BDTR_AOE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_BDTR_AOE_SHIFT))&TIM1_BDTR_AOE_MASK) /**< TIM1_BDTR.AOE Field                     */
#define TIM1_BDTR_MOE_MASK                       (0x8000U)                                           /**< TIM1_BDTR.MOE Mask                      */
#define TIM1_BDTR_MOE_SHIFT                      (15U)                                               /**< TIM1_BDTR.MOE Position                  */
#define TIM1_BDTR_MOE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM1_BDTR_MOE_SHIFT))&TIM1_BDTR_MOE_MASK) /**< TIM1_BDTR.MOE Field                     */
/** @} */

/** @name DCR - DMA control register */ /** @{ */
#define TIM1_DCR_DBA_MASK                        (0x1FU)                                             /**< TIM1_DCR.DBA Mask                       */
#define TIM1_DCR_DBA_SHIFT                       (0U)                                                /**< TIM1_DCR.DBA Position                   */
#define TIM1_DCR_DBA(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_DCR_DBA_SHIFT))&TIM1_DCR_DBA_MASK) /**< TIM1_DCR.DBA Field                      */
#define TIM1_DCR_DBL_MASK                        (0x1F00U)                                           /**< TIM1_DCR.DBL Mask                       */
#define TIM1_DCR_DBL_SHIFT                       (8U)                                                /**< TIM1_DCR.DBL Position                   */
#define TIM1_DCR_DBL(x)                          (((uint32_t)(((uint32_t)(x))<<TIM1_DCR_DBL_SHIFT))&TIM1_DCR_DBL_MASK) /**< TIM1_DCR.DBL Field                      */
/** @} */

/** @name DMAR - DMA address for full transfer */ /** @{ */
#define TIM1_DMAR_DMAB_MASK                      (0xFFFFU)                                           /**< TIM1_DMAR.DMAB Mask                     */
#define TIM1_DMAR_DMAB_SHIFT                     (0U)                                                /**< TIM1_DMAR.DMAB Position                 */
#define TIM1_DMAR_DMAB(x)                        (((uint32_t)(((uint32_t)(x))<<TIM1_DMAR_DMAB_SHIFT))&TIM1_DMAR_DMAB_MASK) /**< TIM1_DMAR.DMAB Field                    */
/** @} */

/** @} */ /* End group TIM_Register_Masks_GROUP */


/* TIM1 - Peripheral instance base addresses */
#define TIM1_BasePtr                   0x40012C00UL //!< Peripheral base address
#define TIM1                           ((TIM1_Type *) TIM1_BasePtr) //!< Freescale base pointer
#define TIM1_BASE_PTR                  (TIM1) //!< Freescale style base pointer
#define TIM1_IRQS { WWDG_IRQn,  }


/** @} */ /* End group TIM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TIM_Peripheral_access_layer_GROUP TIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TIM14 (file:TIM14_STM32F030)         ================ */
/* ================================================================================ */

/**
 * @brief General-purpose-timers
 */
/**
 * @struct TIM14_Type
 * @brief  C Struct allowing access to TIM registers
 */
typedef struct TIM14_Type {
   __IO uint32_t  CR1;                          /**< 0000: control register 1                                           */
        uint8_t   RESERVED_0[8];                /**< 0004: 0x8 bytes                                                    */
   __IO uint32_t  DIER;                         /**< 000C: DMA/Interrupt enable register                                */
   __IO uint32_t  SR;                           /**< 0010: status register                                              */
   __O  uint32_t  EGR;                          /**< 0014: event generation register                                    */
   union {                                      /**< 0018: (size=0004)                                                  */
      __IO uint32_t  CCMR1_Input;               /**< 0018: capture/compare mode register (input                         */
      __IO uint32_t  CCMR1_Output;              /**< 0018: capture/compare mode register (output                        */
   };
        uint8_t   RESERVED_1[4];                /**< 001C: 0x4 bytes                                                    */
   __IO uint32_t  CCER;                         /**< 0020: capture/compare enable                                       */
   __IO uint32_t  CNT;                          /**< 0024: counter                                                      */
   __IO uint32_t  PSC;                          /**< 0028: prescaler                                                    */
   __IO uint32_t  ARR;                          /**< 002C: auto-reload register                                         */
        uint8_t   RESERVED_2[4];                /**< 0030: 0x4 bytes                                                    */
   __IO uint32_t  CCR1;                         /**< 0034: capture/compare register 1                                   */
        uint8_t   RESERVED_3[24];               /**< 0038: 0x18 bytes                                                   */
   __IO uint32_t  OR;                           /**< 0050: option register                                              */
} TIM14_Type;


/** @brief Register Masks for TIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'TIM14' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TIM_Register_Masks_GROUP TIM Register Masks */
/** @{ */

/** @name CR1 - control register 1 */ /** @{ */
#define TIM14_CR1_CEN_MASK                       (0x1U)                                              /**< TIM14_CR1.CEN Mask                      */
#define TIM14_CR1_CEN_SHIFT                      (0U)                                                /**< TIM14_CR1.CEN Position                  */
#define TIM14_CR1_CEN(x)                         (((uint32_t)(((uint32_t)(x))<<TIM14_CR1_CEN_SHIFT))&TIM14_CR1_CEN_MASK) /**< TIM14_CR1.CEN Field                     */
#define TIM14_CR1_UDIS_MASK                      (0x2U)                                              /**< TIM14_CR1.UDIS Mask                     */
#define TIM14_CR1_UDIS_SHIFT                     (1U)                                                /**< TIM14_CR1.UDIS Position                 */
#define TIM14_CR1_UDIS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM14_CR1_UDIS_SHIFT))&TIM14_CR1_UDIS_MASK) /**< TIM14_CR1.UDIS Field                    */
#define TIM14_CR1_URS_MASK                       (0x4U)                                              /**< TIM14_CR1.URS Mask                      */
#define TIM14_CR1_URS_SHIFT                      (2U)                                                /**< TIM14_CR1.URS Position                  */
#define TIM14_CR1_URS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM14_CR1_URS_SHIFT))&TIM14_CR1_URS_MASK) /**< TIM14_CR1.URS Field                     */
#define TIM14_CR1_ARPE_MASK                      (0x80U)                                             /**< TIM14_CR1.ARPE Mask                     */
#define TIM14_CR1_ARPE_SHIFT                     (7U)                                                /**< TIM14_CR1.ARPE Position                 */
#define TIM14_CR1_ARPE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM14_CR1_ARPE_SHIFT))&TIM14_CR1_ARPE_MASK) /**< TIM14_CR1.ARPE Field                    */
#define TIM14_CR1_CKD_MASK                       (0x300U)                                            /**< TIM14_CR1.CKD Mask                      */
#define TIM14_CR1_CKD_SHIFT                      (8U)                                                /**< TIM14_CR1.CKD Position                  */
#define TIM14_CR1_CKD(x)                         (((uint32_t)(((uint32_t)(x))<<TIM14_CR1_CKD_SHIFT))&TIM14_CR1_CKD_MASK) /**< TIM14_CR1.CKD Field                     */
/** @} */

/** @name DIER - DMA/Interrupt enable register */ /** @{ */
#define TIM14_DIER_UIE_MASK                      (0x1U)                                              /**< TIM14_DIER.UIE Mask                     */
#define TIM14_DIER_UIE_SHIFT                     (0U)                                                /**< TIM14_DIER.UIE Position                 */
#define TIM14_DIER_UIE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM14_DIER_UIE_SHIFT))&TIM14_DIER_UIE_MASK) /**< TIM14_DIER.UIE Field                    */
#define TIM14_DIER_CC1IE_MASK                    (0x2U)                                              /**< TIM14_DIER.CC1IE Mask                   */
#define TIM14_DIER_CC1IE_SHIFT                   (1U)                                                /**< TIM14_DIER.CC1IE Position               */
#define TIM14_DIER_CC1IE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM14_DIER_CC1IE_SHIFT))&TIM14_DIER_CC1IE_MASK) /**< TIM14_DIER.CC1IE Field                  */
/** @} */

/** @name SR - status register */ /** @{ */
#define TIM14_SR_UIF_MASK                        (0x1U)                                              /**< TIM14_SR.UIF Mask                       */
#define TIM14_SR_UIF_SHIFT                       (0U)                                                /**< TIM14_SR.UIF Position                   */
#define TIM14_SR_UIF(x)                          (((uint32_t)(((uint32_t)(x))<<TIM14_SR_UIF_SHIFT))&TIM14_SR_UIF_MASK) /**< TIM14_SR.UIF Field                      */
#define TIM14_SR_CC1IF_MASK                      (0x2U)                                              /**< TIM14_SR.CC1IF Mask                     */
#define TIM14_SR_CC1IF_SHIFT                     (1U)                                                /**< TIM14_SR.CC1IF Position                 */
#define TIM14_SR_CC1IF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM14_SR_CC1IF_SHIFT))&TIM14_SR_CC1IF_MASK) /**< TIM14_SR.CC1IF Field                    */
#define TIM14_SR_CC1OF_MASK                      (0x200U)                                            /**< TIM14_SR.CC1OF Mask                     */
#define TIM14_SR_CC1OF_SHIFT                     (9U)                                                /**< TIM14_SR.CC1OF Position                 */
#define TIM14_SR_CC1OF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM14_SR_CC1OF_SHIFT))&TIM14_SR_CC1OF_MASK) /**< TIM14_SR.CC1OF Field                    */
/** @} */

/** @name EGR - event generation register */ /** @{ */
#define TIM14_EGR_UG_MASK                        (0x1U)                                              /**< TIM14_EGR.UG Mask                       */
#define TIM14_EGR_UG_SHIFT                       (0U)                                                /**< TIM14_EGR.UG Position                   */
#define TIM14_EGR_UG(x)                          (((uint32_t)(((uint32_t)(x))<<TIM14_EGR_UG_SHIFT))&TIM14_EGR_UG_MASK) /**< TIM14_EGR.UG Field                      */
#define TIM14_EGR_CC1G_MASK                      (0x2U)                                              /**< TIM14_EGR.CC1G Mask                     */
#define TIM14_EGR_CC1G_SHIFT                     (1U)                                                /**< TIM14_EGR.CC1G Position                 */
#define TIM14_EGR_CC1G(x)                        (((uint32_t)(((uint32_t)(x))<<TIM14_EGR_CC1G_SHIFT))&TIM14_EGR_CC1G_MASK) /**< TIM14_EGR.CC1G Field                    */
/** @} */

/** @name CCMR1_Input - capture/compare mode register (input */ /** @{ */
#define TIM14_CCMR1_Input_CC1S_MASK              (0x3U)                                              /**< TIM14_CCMR1_Input.CC1S Mask             */
#define TIM14_CCMR1_Input_CC1S_SHIFT             (0U)                                                /**< TIM14_CCMR1_Input.CC1S Position         */
#define TIM14_CCMR1_Input_CC1S(x)                (((uint32_t)(((uint32_t)(x))<<TIM14_CCMR1_Input_CC1S_SHIFT))&TIM14_CCMR1_Input_CC1S_MASK) /**< TIM14_CCMR1_Input.CC1S Field            */
#define TIM14_CCMR1_Input_IC1PSC_MASK            (0xCU)                                              /**< TIM14_CCMR1_Input.IC1PSC Mask           */
#define TIM14_CCMR1_Input_IC1PSC_SHIFT           (2U)                                                /**< TIM14_CCMR1_Input.IC1PSC Position       */
#define TIM14_CCMR1_Input_IC1PSC(x)              (((uint32_t)(((uint32_t)(x))<<TIM14_CCMR1_Input_IC1PSC_SHIFT))&TIM14_CCMR1_Input_IC1PSC_MASK) /**< TIM14_CCMR1_Input.IC1PSC Field          */
#define TIM14_CCMR1_Input_IC1F_MASK              (0xF0U)                                             /**< TIM14_CCMR1_Input.IC1F Mask             */
#define TIM14_CCMR1_Input_IC1F_SHIFT             (4U)                                                /**< TIM14_CCMR1_Input.IC1F Position         */
#define TIM14_CCMR1_Input_IC1F(x)                (((uint32_t)(((uint32_t)(x))<<TIM14_CCMR1_Input_IC1F_SHIFT))&TIM14_CCMR1_Input_IC1F_MASK) /**< TIM14_CCMR1_Input.IC1F Field            */
/** @} */

/** @name CCMR1_Output - capture/compare mode register (output */ /** @{ */
#define TIM14_CCMR1_Output_CC1S_MASK             (0x3U)                                              /**< TIM14_CCMR1_Output.CC1S Mask            */
#define TIM14_CCMR1_Output_CC1S_SHIFT            (0U)                                                /**< TIM14_CCMR1_Output.CC1S Position        */
#define TIM14_CCMR1_Output_CC1S(x)               (((uint32_t)(((uint32_t)(x))<<TIM14_CCMR1_Output_CC1S_SHIFT))&TIM14_CCMR1_Output_CC1S_MASK) /**< TIM14_CCMR1_Output.CC1S Field           */
#define TIM14_CCMR1_Output_OC1FE_MASK            (0x4U)                                              /**< TIM14_CCMR1_Output.OC1FE Mask           */
#define TIM14_CCMR1_Output_OC1FE_SHIFT           (2U)                                                /**< TIM14_CCMR1_Output.OC1FE Position       */
#define TIM14_CCMR1_Output_OC1FE(x)              (((uint32_t)(((uint32_t)(x))<<TIM14_CCMR1_Output_OC1FE_SHIFT))&TIM14_CCMR1_Output_OC1FE_MASK) /**< TIM14_CCMR1_Output.OC1FE Field          */
#define TIM14_CCMR1_Output_OC1PE_MASK            (0x8U)                                              /**< TIM14_CCMR1_Output.OC1PE Mask           */
#define TIM14_CCMR1_Output_OC1PE_SHIFT           (3U)                                                /**< TIM14_CCMR1_Output.OC1PE Position       */
#define TIM14_CCMR1_Output_OC1PE(x)              (((uint32_t)(((uint32_t)(x))<<TIM14_CCMR1_Output_OC1PE_SHIFT))&TIM14_CCMR1_Output_OC1PE_MASK) /**< TIM14_CCMR1_Output.OC1PE Field          */
#define TIM14_CCMR1_Output_OC1M_MASK             (0x70U)                                             /**< TIM14_CCMR1_Output.OC1M Mask            */
#define TIM14_CCMR1_Output_OC1M_SHIFT            (4U)                                                /**< TIM14_CCMR1_Output.OC1M Position        */
#define TIM14_CCMR1_Output_OC1M(x)               (((uint32_t)(((uint32_t)(x))<<TIM14_CCMR1_Output_OC1M_SHIFT))&TIM14_CCMR1_Output_OC1M_MASK) /**< TIM14_CCMR1_Output.OC1M Field           */
/** @} */

/** @name CCER - capture/compare enable */ /** @{ */
#define TIM14_CCER_CC1E_MASK                     (0x1U)                                              /**< TIM14_CCER.CC1E Mask                    */
#define TIM14_CCER_CC1E_SHIFT                    (0U)                                                /**< TIM14_CCER.CC1E Position                */
#define TIM14_CCER_CC1E(x)                       (((uint32_t)(((uint32_t)(x))<<TIM14_CCER_CC1E_SHIFT))&TIM14_CCER_CC1E_MASK) /**< TIM14_CCER.CC1E Field                   */
#define TIM14_CCER_CC1P_MASK                     (0x2U)                                              /**< TIM14_CCER.CC1P Mask                    */
#define TIM14_CCER_CC1P_SHIFT                    (1U)                                                /**< TIM14_CCER.CC1P Position                */
#define TIM14_CCER_CC1P(x)                       (((uint32_t)(((uint32_t)(x))<<TIM14_CCER_CC1P_SHIFT))&TIM14_CCER_CC1P_MASK) /**< TIM14_CCER.CC1P Field                   */
#define TIM14_CCER_CC1NP_MASK                    (0x8U)                                              /**< TIM14_CCER.CC1NP Mask                   */
#define TIM14_CCER_CC1NP_SHIFT                   (3U)                                                /**< TIM14_CCER.CC1NP Position               */
#define TIM14_CCER_CC1NP(x)                      (((uint32_t)(((uint32_t)(x))<<TIM14_CCER_CC1NP_SHIFT))&TIM14_CCER_CC1NP_MASK) /**< TIM14_CCER.CC1NP Field                  */
/** @} */

/** @name CNT - counter */ /** @{ */
#define TIM14_CNT_CNT_MASK                       (0xFFFFU)                                           /**< TIM14_CNT.CNT Mask                      */
#define TIM14_CNT_CNT_SHIFT                      (0U)                                                /**< TIM14_CNT.CNT Position                  */
#define TIM14_CNT_CNT(x)                         (((uint32_t)(((uint32_t)(x))<<TIM14_CNT_CNT_SHIFT))&TIM14_CNT_CNT_MASK) /**< TIM14_CNT.CNT Field                     */
/** @} */

/** @name PSC - prescaler */ /** @{ */
#define TIM14_PSC_PSC_MASK                       (0xFFFFU)                                           /**< TIM14_PSC.PSC Mask                      */
#define TIM14_PSC_PSC_SHIFT                      (0U)                                                /**< TIM14_PSC.PSC Position                  */
#define TIM14_PSC_PSC(x)                         (((uint32_t)(((uint32_t)(x))<<TIM14_PSC_PSC_SHIFT))&TIM14_PSC_PSC_MASK) /**< TIM14_PSC.PSC Field                     */
/** @} */

/** @name ARR - auto-reload register */ /** @{ */
#define TIM14_ARR_ARR_MASK                       (0xFFFFU)                                           /**< TIM14_ARR.ARR Mask                      */
#define TIM14_ARR_ARR_SHIFT                      (0U)                                                /**< TIM14_ARR.ARR Position                  */
#define TIM14_ARR_ARR(x)                         (((uint32_t)(((uint32_t)(x))<<TIM14_ARR_ARR_SHIFT))&TIM14_ARR_ARR_MASK) /**< TIM14_ARR.ARR Field                     */
/** @} */

/** @name CCR1 - capture/compare register 1 */ /** @{ */
#define TIM14_CCR1_CCR_MASK                      (0xFFFFU)                                           /**< TIM14_CCR1.CCR Mask                     */
#define TIM14_CCR1_CCR_SHIFT                     (0U)                                                /**< TIM14_CCR1.CCR Position                 */
#define TIM14_CCR1_CCR(x)                        (((uint32_t)(((uint32_t)(x))<<TIM14_CCR1_CCR_SHIFT))&TIM14_CCR1_CCR_MASK) /**< TIM14_CCR1.CCR Field                    */
/** @} */

/** @name OR - option register */ /** @{ */
#define TIM14_OR_RMP_MASK                        (0x3U)                                              /**< TIM14_OR.RMP Mask                       */
#define TIM14_OR_RMP_SHIFT                       (0U)                                                /**< TIM14_OR.RMP Position                   */
#define TIM14_OR_RMP(x)                          (((uint32_t)(((uint32_t)(x))<<TIM14_OR_RMP_SHIFT))&TIM14_OR_RMP_MASK) /**< TIM14_OR.RMP Field                      */
/** @} */

/** @} */ /* End group TIM_Register_Masks_GROUP */


/* TIM14 - Peripheral instance base addresses */
#define TIM14_BasePtr                  0x40002000UL //!< Peripheral base address
#define TIM14                          ((TIM14_Type *) TIM14_BasePtr) //!< Freescale base pointer
#define TIM14_BASE_PTR                 (TIM14) //!< Freescale style base pointer
#define TIM14_IRQS { TIM2_IRQn,  }


/** @} */ /* End group TIM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TIM_Peripheral_access_layer_GROUP TIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TIM15 (file:TIM15_STM32F030)         ================ */
/* ================================================================================ */

/**
 * @brief General-purpose-timers
 */
/**
 * @struct TIM15_Type
 * @brief  C Struct allowing access to TIM registers
 */
typedef struct TIM15_Type {
   __IO uint32_t  CR1;                          /**< 0000: control register 1                                           */
   __IO uint32_t  CR2;                          /**< 0004: control register 2                                           */
   __IO uint32_t  SMCR;                         /**< 0008: slave mode control register                                  */
   __IO uint32_t  DIER;                         /**< 000C: DMA/Interrupt enable register                                */
   __IO uint32_t  SR;                           /**< 0010: status register                                              */
   __O  uint32_t  EGR;                          /**< 0014: event generation register                                    */
   union {                                      /**< 0018: (size=0004)                                                  */
      __IO uint32_t  CCMR1_Input;               /**< 0018: capture/compare mode register 1 (input                       */
      __IO uint32_t  CCMR1_Output;              /**< 0018: capture/compare mode register (output                        */
   };
        uint8_t   RESERVED_0[4];                /**< 001C: 0x4 bytes                                                    */
   __IO uint32_t  CCER;                         /**< 0020: capture/compare enable                                       */
   __IO uint32_t  CNT;                          /**< 0024: counter                                                      */
   __IO uint32_t  PSC;                          /**< 0028: prescaler                                                    */
   __IO uint32_t  ARR;                          /**< 002C: auto-reload register                                         */
   __IO uint32_t  RCR;                          /**< 0030: repetition counter register                                  */
   __IO uint32_t  CCR1;                         /**< 0034: capture/compare register 1                                   */
   __IO uint32_t  CCR2;                         /**< 0038: capture/compare register 2                                   */
        uint8_t   RESERVED_1[8];                /**< 003C: 0x8 bytes                                                    */
   __IO uint32_t  BDTR;                         /**< 0044: break and dead-time register                                 */
   __IO uint32_t  DCR;                          /**< 0048: DMA control register                                         */
   __IO uint32_t  DMAR;                         /**< 004C: DMA address for full transfer                                */
} TIM15_Type;


/** @brief Register Masks for TIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'TIM15' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TIM_Register_Masks_GROUP TIM Register Masks */
/** @{ */

/** @name CR1 - control register 1 */ /** @{ */
#define TIM15_CR1_CEN_MASK                       (0x1U)                                              /**< TIM15_CR1.CEN Mask                      */
#define TIM15_CR1_CEN_SHIFT                      (0U)                                                /**< TIM15_CR1.CEN Position                  */
#define TIM15_CR1_CEN(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_CR1_CEN_SHIFT))&TIM15_CR1_CEN_MASK) /**< TIM15_CR1.CEN Field                     */
#define TIM15_CR1_UDIS_MASK                      (0x2U)                                              /**< TIM15_CR1.UDIS Mask                     */
#define TIM15_CR1_UDIS_SHIFT                     (1U)                                                /**< TIM15_CR1.UDIS Position                 */
#define TIM15_CR1_UDIS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_CR1_UDIS_SHIFT))&TIM15_CR1_UDIS_MASK) /**< TIM15_CR1.UDIS Field                    */
#define TIM15_CR1_URS_MASK                       (0x4U)                                              /**< TIM15_CR1.URS Mask                      */
#define TIM15_CR1_URS_SHIFT                      (2U)                                                /**< TIM15_CR1.URS Position                  */
#define TIM15_CR1_URS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_CR1_URS_SHIFT))&TIM15_CR1_URS_MASK) /**< TIM15_CR1.URS Field                     */
#define TIM15_CR1_OPM_MASK                       (0x8U)                                              /**< TIM15_CR1.OPM Mask                      */
#define TIM15_CR1_OPM_SHIFT                      (3U)                                                /**< TIM15_CR1.OPM Position                  */
#define TIM15_CR1_OPM(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_CR1_OPM_SHIFT))&TIM15_CR1_OPM_MASK) /**< TIM15_CR1.OPM Field                     */
#define TIM15_CR1_ARPE_MASK                      (0x80U)                                             /**< TIM15_CR1.ARPE Mask                     */
#define TIM15_CR1_ARPE_SHIFT                     (7U)                                                /**< TIM15_CR1.ARPE Position                 */
#define TIM15_CR1_ARPE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_CR1_ARPE_SHIFT))&TIM15_CR1_ARPE_MASK) /**< TIM15_CR1.ARPE Field                    */
#define TIM15_CR1_CKD_MASK                       (0x300U)                                            /**< TIM15_CR1.CKD Mask                      */
#define TIM15_CR1_CKD_SHIFT                      (8U)                                                /**< TIM15_CR1.CKD Position                  */
#define TIM15_CR1_CKD(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_CR1_CKD_SHIFT))&TIM15_CR1_CKD_MASK) /**< TIM15_CR1.CKD Field                     */
/** @} */

/** @name CR2 - control register 2 */ /** @{ */
#define TIM15_CR2_CCPC_MASK                      (0x1U)                                              /**< TIM15_CR2.CCPC Mask                     */
#define TIM15_CR2_CCPC_SHIFT                     (0U)                                                /**< TIM15_CR2.CCPC Position                 */
#define TIM15_CR2_CCPC(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_CR2_CCPC_SHIFT))&TIM15_CR2_CCPC_MASK) /**< TIM15_CR2.CCPC Field                    */
#define TIM15_CR2_CCUS_MASK                      (0x4U)                                              /**< TIM15_CR2.CCUS Mask                     */
#define TIM15_CR2_CCUS_SHIFT                     (2U)                                                /**< TIM15_CR2.CCUS Position                 */
#define TIM15_CR2_CCUS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_CR2_CCUS_SHIFT))&TIM15_CR2_CCUS_MASK) /**< TIM15_CR2.CCUS Field                    */
#define TIM15_CR2_CCDS_MASK                      (0x8U)                                              /**< TIM15_CR2.CCDS Mask                     */
#define TIM15_CR2_CCDS_SHIFT                     (3U)                                                /**< TIM15_CR2.CCDS Position                 */
#define TIM15_CR2_CCDS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_CR2_CCDS_SHIFT))&TIM15_CR2_CCDS_MASK) /**< TIM15_CR2.CCDS Field                    */
#define TIM15_CR2_MMS_MASK                       (0x70U)                                             /**< TIM15_CR2.MMS Mask                      */
#define TIM15_CR2_MMS_SHIFT                      (4U)                                                /**< TIM15_CR2.MMS Position                  */
#define TIM15_CR2_MMS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_CR2_MMS_SHIFT))&TIM15_CR2_MMS_MASK) /**< TIM15_CR2.MMS Field                     */
#define TIM15_CR2_OIS1_MASK                      (0x100U)                                            /**< TIM15_CR2.OIS1 Mask                     */
#define TIM15_CR2_OIS1_SHIFT                     (8U)                                                /**< TIM15_CR2.OIS1 Position                 */
#define TIM15_CR2_OIS1(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_CR2_OIS1_SHIFT))&TIM15_CR2_OIS1_MASK) /**< TIM15_CR2.OIS1 Field                    */
#define TIM15_CR2_OIS1N_MASK                     (0x200U)                                            /**< TIM15_CR2.OIS1N Mask                    */
#define TIM15_CR2_OIS1N_SHIFT                    (9U)                                                /**< TIM15_CR2.OIS1N Position                */
#define TIM15_CR2_OIS1N(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_CR2_OIS1N_SHIFT))&TIM15_CR2_OIS1N_MASK) /**< TIM15_CR2.OIS1N Field                   */
#define TIM15_CR2_OIS2_MASK                      (0x400U)                                            /**< TIM15_CR2.OIS2 Mask                     */
#define TIM15_CR2_OIS2_SHIFT                     (10U)                                               /**< TIM15_CR2.OIS2 Position                 */
#define TIM15_CR2_OIS2(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_CR2_OIS2_SHIFT))&TIM15_CR2_OIS2_MASK) /**< TIM15_CR2.OIS2 Field                    */
/** @} */

/** @name SMCR - slave mode control register */ /** @{ */
#define TIM15_SMCR_SMS_MASK                      (0x7U)                                              /**< TIM15_SMCR.SMS Mask                     */
#define TIM15_SMCR_SMS_SHIFT                     (0U)                                                /**< TIM15_SMCR.SMS Position                 */
#define TIM15_SMCR_SMS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_SMCR_SMS_SHIFT))&TIM15_SMCR_SMS_MASK) /**< TIM15_SMCR.SMS Field                    */
#define TIM15_SMCR_TS_MASK                       (0x70U)                                             /**< TIM15_SMCR.TS Mask                      */
#define TIM15_SMCR_TS_SHIFT                      (4U)                                                /**< TIM15_SMCR.TS Position                  */
#define TIM15_SMCR_TS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_SMCR_TS_SHIFT))&TIM15_SMCR_TS_MASK) /**< TIM15_SMCR.TS Field                     */
#define TIM15_SMCR_MSM_MASK                      (0x80U)                                             /**< TIM15_SMCR.MSM Mask                     */
#define TIM15_SMCR_MSM_SHIFT                     (7U)                                                /**< TIM15_SMCR.MSM Position                 */
#define TIM15_SMCR_MSM(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_SMCR_MSM_SHIFT))&TIM15_SMCR_MSM_MASK) /**< TIM15_SMCR.MSM Field                    */
/** @} */

/** @name DIER - DMA/Interrupt enable register */ /** @{ */
#define TIM15_DIER_UIE_MASK                      (0x1U)                                              /**< TIM15_DIER.UIE Mask                     */
#define TIM15_DIER_UIE_SHIFT                     (0U)                                                /**< TIM15_DIER.UIE Position                 */
#define TIM15_DIER_UIE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_UIE_SHIFT))&TIM15_DIER_UIE_MASK) /**< TIM15_DIER.UIE Field                    */
#define TIM15_DIER_CC1IE_MASK                    (0x2U)                                              /**< TIM15_DIER.CC1IE Mask                   */
#define TIM15_DIER_CC1IE_SHIFT                   (1U)                                                /**< TIM15_DIER.CC1IE Position               */
#define TIM15_DIER_CC1IE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_CC1IE_SHIFT))&TIM15_DIER_CC1IE_MASK) /**< TIM15_DIER.CC1IE Field                  */
#define TIM15_DIER_CC2IE_MASK                    (0x4U)                                              /**< TIM15_DIER.CC2IE Mask                   */
#define TIM15_DIER_CC2IE_SHIFT                   (2U)                                                /**< TIM15_DIER.CC2IE Position               */
#define TIM15_DIER_CC2IE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_CC2IE_SHIFT))&TIM15_DIER_CC2IE_MASK) /**< TIM15_DIER.CC2IE Field                  */
#define TIM15_DIER_COMIE_MASK                    (0x20U)                                             /**< TIM15_DIER.COMIE Mask                   */
#define TIM15_DIER_COMIE_SHIFT                   (5U)                                                /**< TIM15_DIER.COMIE Position               */
#define TIM15_DIER_COMIE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_COMIE_SHIFT))&TIM15_DIER_COMIE_MASK) /**< TIM15_DIER.COMIE Field                  */
#define TIM15_DIER_TIE_MASK                      (0x40U)                                             /**< TIM15_DIER.TIE Mask                     */
#define TIM15_DIER_TIE_SHIFT                     (6U)                                                /**< TIM15_DIER.TIE Position                 */
#define TIM15_DIER_TIE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_TIE_SHIFT))&TIM15_DIER_TIE_MASK) /**< TIM15_DIER.TIE Field                    */
#define TIM15_DIER_BIE_MASK                      (0x80U)                                             /**< TIM15_DIER.BIE Mask                     */
#define TIM15_DIER_BIE_SHIFT                     (7U)                                                /**< TIM15_DIER.BIE Position                 */
#define TIM15_DIER_BIE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_BIE_SHIFT))&TIM15_DIER_BIE_MASK) /**< TIM15_DIER.BIE Field                    */
#define TIM15_DIER_UDE_MASK                      (0x100U)                                            /**< TIM15_DIER.UDE Mask                     */
#define TIM15_DIER_UDE_SHIFT                     (8U)                                                /**< TIM15_DIER.UDE Position                 */
#define TIM15_DIER_UDE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_UDE_SHIFT))&TIM15_DIER_UDE_MASK) /**< TIM15_DIER.UDE Field                    */
#define TIM15_DIER_CC1DE_MASK                    (0x200U)                                            /**< TIM15_DIER.CC1DE Mask                   */
#define TIM15_DIER_CC1DE_SHIFT                   (9U)                                                /**< TIM15_DIER.CC1DE Position               */
#define TIM15_DIER_CC1DE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_CC1DE_SHIFT))&TIM15_DIER_CC1DE_MASK) /**< TIM15_DIER.CC1DE Field                  */
#define TIM15_DIER_CC2DE_MASK                    (0x400U)                                            /**< TIM15_DIER.CC2DE Mask                   */
#define TIM15_DIER_CC2DE_SHIFT                   (10U)                                               /**< TIM15_DIER.CC2DE Position               */
#define TIM15_DIER_CC2DE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_CC2DE_SHIFT))&TIM15_DIER_CC2DE_MASK) /**< TIM15_DIER.CC2DE Field                  */
#define TIM15_DIER_TDE_MASK                      (0x4000U)                                           /**< TIM15_DIER.TDE Mask                     */
#define TIM15_DIER_TDE_SHIFT                     (14U)                                               /**< TIM15_DIER.TDE Position                 */
#define TIM15_DIER_TDE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_DIER_TDE_SHIFT))&TIM15_DIER_TDE_MASK) /**< TIM15_DIER.TDE Field                    */
/** @} */

/** @name SR - status register */ /** @{ */
#define TIM15_SR_UIF_MASK                        (0x1U)                                              /**< TIM15_SR.UIF Mask                       */
#define TIM15_SR_UIF_SHIFT                       (0U)                                                /**< TIM15_SR.UIF Position                   */
#define TIM15_SR_UIF(x)                          (((uint32_t)(((uint32_t)(x))<<TIM15_SR_UIF_SHIFT))&TIM15_SR_UIF_MASK) /**< TIM15_SR.UIF Field                      */
#define TIM15_SR_CC1IF_MASK                      (0x2U)                                              /**< TIM15_SR.CC1IF Mask                     */
#define TIM15_SR_CC1IF_SHIFT                     (1U)                                                /**< TIM15_SR.CC1IF Position                 */
#define TIM15_SR_CC1IF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_SR_CC1IF_SHIFT))&TIM15_SR_CC1IF_MASK) /**< TIM15_SR.CC1IF Field                    */
#define TIM15_SR_CC2IF_MASK                      (0x4U)                                              /**< TIM15_SR.CC2IF Mask                     */
#define TIM15_SR_CC2IF_SHIFT                     (2U)                                                /**< TIM15_SR.CC2IF Position                 */
#define TIM15_SR_CC2IF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_SR_CC2IF_SHIFT))&TIM15_SR_CC2IF_MASK) /**< TIM15_SR.CC2IF Field                    */
#define TIM15_SR_COMIF_MASK                      (0x20U)                                             /**< TIM15_SR.COMIF Mask                     */
#define TIM15_SR_COMIF_SHIFT                     (5U)                                                /**< TIM15_SR.COMIF Position                 */
#define TIM15_SR_COMIF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_SR_COMIF_SHIFT))&TIM15_SR_COMIF_MASK) /**< TIM15_SR.COMIF Field                    */
#define TIM15_SR_TIF_MASK                        (0x40U)                                             /**< TIM15_SR.TIF Mask                       */
#define TIM15_SR_TIF_SHIFT                       (6U)                                                /**< TIM15_SR.TIF Position                   */
#define TIM15_SR_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<TIM15_SR_TIF_SHIFT))&TIM15_SR_TIF_MASK) /**< TIM15_SR.TIF Field                      */
#define TIM15_SR_BIF_MASK                        (0x80U)                                             /**< TIM15_SR.BIF Mask                       */
#define TIM15_SR_BIF_SHIFT                       (7U)                                                /**< TIM15_SR.BIF Position                   */
#define TIM15_SR_BIF(x)                          (((uint32_t)(((uint32_t)(x))<<TIM15_SR_BIF_SHIFT))&TIM15_SR_BIF_MASK) /**< TIM15_SR.BIF Field                      */
#define TIM15_SR_CC1OF_MASK                      (0x200U)                                            /**< TIM15_SR.CC1OF Mask                     */
#define TIM15_SR_CC1OF_SHIFT                     (9U)                                                /**< TIM15_SR.CC1OF Position                 */
#define TIM15_SR_CC1OF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_SR_CC1OF_SHIFT))&TIM15_SR_CC1OF_MASK) /**< TIM15_SR.CC1OF Field                    */
#define TIM15_SR_CC2OF_MASK                      (0x400U)                                            /**< TIM15_SR.CC2OF Mask                     */
#define TIM15_SR_CC2OF_SHIFT                     (10U)                                               /**< TIM15_SR.CC2OF Position                 */
#define TIM15_SR_CC2OF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_SR_CC2OF_SHIFT))&TIM15_SR_CC2OF_MASK) /**< TIM15_SR.CC2OF Field                    */
/** @} */

/** @name EGR - event generation register */ /** @{ */
#define TIM15_EGR_UG_MASK                        (0x1U)                                              /**< TIM15_EGR.UG Mask                       */
#define TIM15_EGR_UG_SHIFT                       (0U)                                                /**< TIM15_EGR.UG Position                   */
#define TIM15_EGR_UG(x)                          (((uint32_t)(((uint32_t)(x))<<TIM15_EGR_UG_SHIFT))&TIM15_EGR_UG_MASK) /**< TIM15_EGR.UG Field                      */
#define TIM15_EGR_CC1G_MASK                      (0x2U)                                              /**< TIM15_EGR.CC1G Mask                     */
#define TIM15_EGR_CC1G_SHIFT                     (1U)                                                /**< TIM15_EGR.CC1G Position                 */
#define TIM15_EGR_CC1G(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_EGR_CC1G_SHIFT))&TIM15_EGR_CC1G_MASK) /**< TIM15_EGR.CC1G Field                    */
#define TIM15_EGR_CC2G_MASK                      (0x4U)                                              /**< TIM15_EGR.CC2G Mask                     */
#define TIM15_EGR_CC2G_SHIFT                     (2U)                                                /**< TIM15_EGR.CC2G Position                 */
#define TIM15_EGR_CC2G(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_EGR_CC2G_SHIFT))&TIM15_EGR_CC2G_MASK) /**< TIM15_EGR.CC2G Field                    */
#define TIM15_EGR_COMG_MASK                      (0x20U)                                             /**< TIM15_EGR.COMG Mask                     */
#define TIM15_EGR_COMG_SHIFT                     (5U)                                                /**< TIM15_EGR.COMG Position                 */
#define TIM15_EGR_COMG(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_EGR_COMG_SHIFT))&TIM15_EGR_COMG_MASK) /**< TIM15_EGR.COMG Field                    */
#define TIM15_EGR_TG_MASK                        (0x40U)                                             /**< TIM15_EGR.TG Mask                       */
#define TIM15_EGR_TG_SHIFT                       (6U)                                                /**< TIM15_EGR.TG Position                   */
#define TIM15_EGR_TG(x)                          (((uint32_t)(((uint32_t)(x))<<TIM15_EGR_TG_SHIFT))&TIM15_EGR_TG_MASK) /**< TIM15_EGR.TG Field                      */
#define TIM15_EGR_BG_MASK                        (0x80U)                                             /**< TIM15_EGR.BG Mask                       */
#define TIM15_EGR_BG_SHIFT                       (7U)                                                /**< TIM15_EGR.BG Position                   */
#define TIM15_EGR_BG(x)                          (((uint32_t)(((uint32_t)(x))<<TIM15_EGR_BG_SHIFT))&TIM15_EGR_BG_MASK) /**< TIM15_EGR.BG Field                      */
/** @} */

/** @name CCMR1_Input - capture/compare mode register 1 (input */ /** @{ */
#define TIM15_CCMR1_Input_CC1S_MASK              (0x3U)                                              /**< TIM15_CCMR1_Input.CC1S Mask             */
#define TIM15_CCMR1_Input_CC1S_SHIFT             (0U)                                                /**< TIM15_CCMR1_Input.CC1S Position         */
#define TIM15_CCMR1_Input_CC1S(x)                (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Input_CC1S_SHIFT))&TIM15_CCMR1_Input_CC1S_MASK) /**< TIM15_CCMR1_Input.CC1S Field            */
#define TIM15_CCMR1_Input_IC1PSC_MASK            (0xCU)                                              /**< TIM15_CCMR1_Input.IC1PSC Mask           */
#define TIM15_CCMR1_Input_IC1PSC_SHIFT           (2U)                                                /**< TIM15_CCMR1_Input.IC1PSC Position       */
#define TIM15_CCMR1_Input_IC1PSC(x)              (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Input_IC1PSC_SHIFT))&TIM15_CCMR1_Input_IC1PSC_MASK) /**< TIM15_CCMR1_Input.IC1PSC Field          */
#define TIM15_CCMR1_Input_IC1F_MASK              (0xF0U)                                             /**< TIM15_CCMR1_Input.IC1F Mask             */
#define TIM15_CCMR1_Input_IC1F_SHIFT             (4U)                                                /**< TIM15_CCMR1_Input.IC1F Position         */
#define TIM15_CCMR1_Input_IC1F(x)                (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Input_IC1F_SHIFT))&TIM15_CCMR1_Input_IC1F_MASK) /**< TIM15_CCMR1_Input.IC1F Field            */
#define TIM15_CCMR1_Input_CC2S_MASK              (0x300U)                                            /**< TIM15_CCMR1_Input.CC2S Mask             */
#define TIM15_CCMR1_Input_CC2S_SHIFT             (8U)                                                /**< TIM15_CCMR1_Input.CC2S Position         */
#define TIM15_CCMR1_Input_CC2S(x)                (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Input_CC2S_SHIFT))&TIM15_CCMR1_Input_CC2S_MASK) /**< TIM15_CCMR1_Input.CC2S Field            */
#define TIM15_CCMR1_Input_IC2PSC_MASK            (0xC00U)                                            /**< TIM15_CCMR1_Input.IC2PSC Mask           */
#define TIM15_CCMR1_Input_IC2PSC_SHIFT           (10U)                                               /**< TIM15_CCMR1_Input.IC2PSC Position       */
#define TIM15_CCMR1_Input_IC2PSC(x)              (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Input_IC2PSC_SHIFT))&TIM15_CCMR1_Input_IC2PSC_MASK) /**< TIM15_CCMR1_Input.IC2PSC Field          */
#define TIM15_CCMR1_Input_IC2F_MASK              (0xF000U)                                           /**< TIM15_CCMR1_Input.IC2F Mask             */
#define TIM15_CCMR1_Input_IC2F_SHIFT             (12U)                                               /**< TIM15_CCMR1_Input.IC2F Position         */
#define TIM15_CCMR1_Input_IC2F(x)                (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Input_IC2F_SHIFT))&TIM15_CCMR1_Input_IC2F_MASK) /**< TIM15_CCMR1_Input.IC2F Field            */
/** @} */

/** @name CCMR1_Output - capture/compare mode register (output */ /** @{ */
#define TIM15_CCMR1_Output_CC1S_MASK             (0x3U)                                              /**< TIM15_CCMR1_Output.CC1S Mask            */
#define TIM15_CCMR1_Output_CC1S_SHIFT            (0U)                                                /**< TIM15_CCMR1_Output.CC1S Position        */
#define TIM15_CCMR1_Output_CC1S(x)               (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Output_CC1S_SHIFT))&TIM15_CCMR1_Output_CC1S_MASK) /**< TIM15_CCMR1_Output.CC1S Field           */
#define TIM15_CCMR1_Output_OC1FE_MASK            (0x4U)                                              /**< TIM15_CCMR1_Output.OC1FE Mask           */
#define TIM15_CCMR1_Output_OC1FE_SHIFT           (2U)                                                /**< TIM15_CCMR1_Output.OC1FE Position       */
#define TIM15_CCMR1_Output_OC1FE(x)              (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Output_OC1FE_SHIFT))&TIM15_CCMR1_Output_OC1FE_MASK) /**< TIM15_CCMR1_Output.OC1FE Field          */
#define TIM15_CCMR1_Output_OC1PE_MASK            (0x8U)                                              /**< TIM15_CCMR1_Output.OC1PE Mask           */
#define TIM15_CCMR1_Output_OC1PE_SHIFT           (3U)                                                /**< TIM15_CCMR1_Output.OC1PE Position       */
#define TIM15_CCMR1_Output_OC1PE(x)              (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Output_OC1PE_SHIFT))&TIM15_CCMR1_Output_OC1PE_MASK) /**< TIM15_CCMR1_Output.OC1PE Field          */
#define TIM15_CCMR1_Output_OC1M_MASK             (0x70U)                                             /**< TIM15_CCMR1_Output.OC1M Mask            */
#define TIM15_CCMR1_Output_OC1M_SHIFT            (4U)                                                /**< TIM15_CCMR1_Output.OC1M Position        */
#define TIM15_CCMR1_Output_OC1M(x)               (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Output_OC1M_SHIFT))&TIM15_CCMR1_Output_OC1M_MASK) /**< TIM15_CCMR1_Output.OC1M Field           */
#define TIM15_CCMR1_Output_CC2S_MASK             (0x300U)                                            /**< TIM15_CCMR1_Output.CC2S Mask            */
#define TIM15_CCMR1_Output_CC2S_SHIFT            (8U)                                                /**< TIM15_CCMR1_Output.CC2S Position        */
#define TIM15_CCMR1_Output_CC2S(x)               (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Output_CC2S_SHIFT))&TIM15_CCMR1_Output_CC2S_MASK) /**< TIM15_CCMR1_Output.CC2S Field           */
#define TIM15_CCMR1_Output_OC2FE_MASK            (0x400U)                                            /**< TIM15_CCMR1_Output.OC2FE Mask           */
#define TIM15_CCMR1_Output_OC2FE_SHIFT           (10U)                                               /**< TIM15_CCMR1_Output.OC2FE Position       */
#define TIM15_CCMR1_Output_OC2FE(x)              (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Output_OC2FE_SHIFT))&TIM15_CCMR1_Output_OC2FE_MASK) /**< TIM15_CCMR1_Output.OC2FE Field          */
#define TIM15_CCMR1_Output_OC2PE_MASK            (0x800U)                                            /**< TIM15_CCMR1_Output.OC2PE Mask           */
#define TIM15_CCMR1_Output_OC2PE_SHIFT           (11U)                                               /**< TIM15_CCMR1_Output.OC2PE Position       */
#define TIM15_CCMR1_Output_OC2PE(x)              (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Output_OC2PE_SHIFT))&TIM15_CCMR1_Output_OC2PE_MASK) /**< TIM15_CCMR1_Output.OC2PE Field          */
#define TIM15_CCMR1_Output_OC2M_MASK             (0x7000U)                                           /**< TIM15_CCMR1_Output.OC2M Mask            */
#define TIM15_CCMR1_Output_OC2M_SHIFT            (12U)                                               /**< TIM15_CCMR1_Output.OC2M Position        */
#define TIM15_CCMR1_Output_OC2M(x)               (((uint32_t)(((uint32_t)(x))<<TIM15_CCMR1_Output_OC2M_SHIFT))&TIM15_CCMR1_Output_OC2M_MASK) /**< TIM15_CCMR1_Output.OC2M Field           */
/** @} */

/** @name CCER - capture/compare enable */ /** @{ */
#define TIM15_CCER_CC1E_MASK                     (0x1U)                                              /**< TIM15_CCER.CC1E Mask                    */
#define TIM15_CCER_CC1E_SHIFT                    (0U)                                                /**< TIM15_CCER.CC1E Position                */
#define TIM15_CCER_CC1E(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_CCER_CC1E_SHIFT))&TIM15_CCER_CC1E_MASK) /**< TIM15_CCER.CC1E Field                   */
#define TIM15_CCER_CC1P_MASK                     (0x2U)                                              /**< TIM15_CCER.CC1P Mask                    */
#define TIM15_CCER_CC1P_SHIFT                    (1U)                                                /**< TIM15_CCER.CC1P Position                */
#define TIM15_CCER_CC1P(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_CCER_CC1P_SHIFT))&TIM15_CCER_CC1P_MASK) /**< TIM15_CCER.CC1P Field                   */
#define TIM15_CCER_CC1NE_MASK                    (0x4U)                                              /**< TIM15_CCER.CC1NE Mask                   */
#define TIM15_CCER_CC1NE_SHIFT                   (2U)                                                /**< TIM15_CCER.CC1NE Position               */
#define TIM15_CCER_CC1NE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM15_CCER_CC1NE_SHIFT))&TIM15_CCER_CC1NE_MASK) /**< TIM15_CCER.CC1NE Field                  */
#define TIM15_CCER_CC1NP_MASK                    (0x8U)                                              /**< TIM15_CCER.CC1NP Mask                   */
#define TIM15_CCER_CC1NP_SHIFT                   (3U)                                                /**< TIM15_CCER.CC1NP Position               */
#define TIM15_CCER_CC1NP(x)                      (((uint32_t)(((uint32_t)(x))<<TIM15_CCER_CC1NP_SHIFT))&TIM15_CCER_CC1NP_MASK) /**< TIM15_CCER.CC1NP Field                  */
#define TIM15_CCER_CC2E_MASK                     (0x10U)                                             /**< TIM15_CCER.CC2E Mask                    */
#define TIM15_CCER_CC2E_SHIFT                    (4U)                                                /**< TIM15_CCER.CC2E Position                */
#define TIM15_CCER_CC2E(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_CCER_CC2E_SHIFT))&TIM15_CCER_CC2E_MASK) /**< TIM15_CCER.CC2E Field                   */
#define TIM15_CCER_CC2P_MASK                     (0x20U)                                             /**< TIM15_CCER.CC2P Mask                    */
#define TIM15_CCER_CC2P_SHIFT                    (5U)                                                /**< TIM15_CCER.CC2P Position                */
#define TIM15_CCER_CC2P(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_CCER_CC2P_SHIFT))&TIM15_CCER_CC2P_MASK) /**< TIM15_CCER.CC2P Field                   */
#define TIM15_CCER_CC2NP_MASK                    (0x80U)                                             /**< TIM15_CCER.CC2NP Mask                   */
#define TIM15_CCER_CC2NP_SHIFT                   (7U)                                                /**< TIM15_CCER.CC2NP Position               */
#define TIM15_CCER_CC2NP(x)                      (((uint32_t)(((uint32_t)(x))<<TIM15_CCER_CC2NP_SHIFT))&TIM15_CCER_CC2NP_MASK) /**< TIM15_CCER.CC2NP Field                  */
/** @} */

/** @name CNT - counter */ /** @{ */
#define TIM15_CNT_CNT_MASK                       (0xFFFFU)                                           /**< TIM15_CNT.CNT Mask                      */
#define TIM15_CNT_CNT_SHIFT                      (0U)                                                /**< TIM15_CNT.CNT Position                  */
#define TIM15_CNT_CNT(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_CNT_CNT_SHIFT))&TIM15_CNT_CNT_MASK) /**< TIM15_CNT.CNT Field                     */
/** @} */

/** @name PSC - prescaler */ /** @{ */
#define TIM15_PSC_PSC_MASK                       (0xFFFFU)                                           /**< TIM15_PSC.PSC Mask                      */
#define TIM15_PSC_PSC_SHIFT                      (0U)                                                /**< TIM15_PSC.PSC Position                  */
#define TIM15_PSC_PSC(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_PSC_PSC_SHIFT))&TIM15_PSC_PSC_MASK) /**< TIM15_PSC.PSC Field                     */
/** @} */

/** @name ARR - auto-reload register */ /** @{ */
#define TIM15_ARR_ARR_MASK                       (0xFFFFU)                                           /**< TIM15_ARR.ARR Mask                      */
#define TIM15_ARR_ARR_SHIFT                      (0U)                                                /**< TIM15_ARR.ARR Position                  */
#define TIM15_ARR_ARR(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_ARR_ARR_SHIFT))&TIM15_ARR_ARR_MASK) /**< TIM15_ARR.ARR Field                     */
/** @} */

/** @name RCR - repetition counter register */ /** @{ */
#define TIM15_RCR_REP_MASK                       (0xFFU)                                             /**< TIM15_RCR.REP Mask                      */
#define TIM15_RCR_REP_SHIFT                      (0U)                                                /**< TIM15_RCR.REP Position                  */
#define TIM15_RCR_REP(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_RCR_REP_SHIFT))&TIM15_RCR_REP_MASK) /**< TIM15_RCR.REP Field                     */
/** @} */

/** @name CCR - capture/compare register %s */ /** @{ */
#define TIM15_CCR_CCR_MASK                       (0xFFFFU)                                           /**< TIM15_CCR.CCR Mask                      */
#define TIM15_CCR_CCR_SHIFT                      (0U)                                                /**< TIM15_CCR.CCR Position                  */
#define TIM15_CCR_CCR(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_CCR_CCR_SHIFT))&TIM15_CCR_CCR_MASK) /**< TIM15_CCR.CCR Field                     */
/** @} */

/** @name BDTR - break and dead-time register */ /** @{ */
#define TIM15_BDTR_DTG_MASK                      (0xFFU)                                             /**< TIM15_BDTR.DTG Mask                     */
#define TIM15_BDTR_DTG_SHIFT                     (0U)                                                /**< TIM15_BDTR.DTG Position                 */
#define TIM15_BDTR_DTG(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_BDTR_DTG_SHIFT))&TIM15_BDTR_DTG_MASK) /**< TIM15_BDTR.DTG Field                    */
#define TIM15_BDTR_LOCK_MASK                     (0x300U)                                            /**< TIM15_BDTR.LOCK Mask                    */
#define TIM15_BDTR_LOCK_SHIFT                    (8U)                                                /**< TIM15_BDTR.LOCK Position                */
#define TIM15_BDTR_LOCK(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_BDTR_LOCK_SHIFT))&TIM15_BDTR_LOCK_MASK) /**< TIM15_BDTR.LOCK Field                   */
#define TIM15_BDTR_OSSI_MASK                     (0x400U)                                            /**< TIM15_BDTR.OSSI Mask                    */
#define TIM15_BDTR_OSSI_SHIFT                    (10U)                                               /**< TIM15_BDTR.OSSI Position                */
#define TIM15_BDTR_OSSI(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_BDTR_OSSI_SHIFT))&TIM15_BDTR_OSSI_MASK) /**< TIM15_BDTR.OSSI Field                   */
#define TIM15_BDTR_OSSR_MASK                     (0x800U)                                            /**< TIM15_BDTR.OSSR Mask                    */
#define TIM15_BDTR_OSSR_SHIFT                    (11U)                                               /**< TIM15_BDTR.OSSR Position                */
#define TIM15_BDTR_OSSR(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_BDTR_OSSR_SHIFT))&TIM15_BDTR_OSSR_MASK) /**< TIM15_BDTR.OSSR Field                   */
#define TIM15_BDTR_BKE_MASK                      (0x1000U)                                           /**< TIM15_BDTR.BKE Mask                     */
#define TIM15_BDTR_BKE_SHIFT                     (12U)                                               /**< TIM15_BDTR.BKE Position                 */
#define TIM15_BDTR_BKE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_BDTR_BKE_SHIFT))&TIM15_BDTR_BKE_MASK) /**< TIM15_BDTR.BKE Field                    */
#define TIM15_BDTR_BKP_MASK                      (0x2000U)                                           /**< TIM15_BDTR.BKP Mask                     */
#define TIM15_BDTR_BKP_SHIFT                     (13U)                                               /**< TIM15_BDTR.BKP Position                 */
#define TIM15_BDTR_BKP(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_BDTR_BKP_SHIFT))&TIM15_BDTR_BKP_MASK) /**< TIM15_BDTR.BKP Field                    */
#define TIM15_BDTR_AOE_MASK                      (0x4000U)                                           /**< TIM15_BDTR.AOE Mask                     */
#define TIM15_BDTR_AOE_SHIFT                     (14U)                                               /**< TIM15_BDTR.AOE Position                 */
#define TIM15_BDTR_AOE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_BDTR_AOE_SHIFT))&TIM15_BDTR_AOE_MASK) /**< TIM15_BDTR.AOE Field                    */
#define TIM15_BDTR_MOE_MASK                      (0x8000U)                                           /**< TIM15_BDTR.MOE Mask                     */
#define TIM15_BDTR_MOE_SHIFT                     (15U)                                               /**< TIM15_BDTR.MOE Position                 */
#define TIM15_BDTR_MOE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM15_BDTR_MOE_SHIFT))&TIM15_BDTR_MOE_MASK) /**< TIM15_BDTR.MOE Field                    */
/** @} */

/** @name DCR - DMA control register */ /** @{ */
#define TIM15_DCR_DBA_MASK                       (0x1FU)                                             /**< TIM15_DCR.DBA Mask                      */
#define TIM15_DCR_DBA_SHIFT                      (0U)                                                /**< TIM15_DCR.DBA Position                  */
#define TIM15_DCR_DBA(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_DCR_DBA_SHIFT))&TIM15_DCR_DBA_MASK) /**< TIM15_DCR.DBA Field                     */
#define TIM15_DCR_DBL_MASK                       (0x1F00U)                                           /**< TIM15_DCR.DBL Mask                      */
#define TIM15_DCR_DBL_SHIFT                      (8U)                                                /**< TIM15_DCR.DBL Position                  */
#define TIM15_DCR_DBL(x)                         (((uint32_t)(((uint32_t)(x))<<TIM15_DCR_DBL_SHIFT))&TIM15_DCR_DBL_MASK) /**< TIM15_DCR.DBL Field                     */
/** @} */

/** @name DMAR - DMA address for full transfer */ /** @{ */
#define TIM15_DMAR_DMAB_MASK                     (0xFFFFU)                                           /**< TIM15_DMAR.DMAB Mask                    */
#define TIM15_DMAR_DMAB_SHIFT                    (0U)                                                /**< TIM15_DMAR.DMAB Position                */
#define TIM15_DMAR_DMAB(x)                       (((uint32_t)(((uint32_t)(x))<<TIM15_DMAR_DMAB_SHIFT))&TIM15_DMAR_DMAB_MASK) /**< TIM15_DMAR.DMAB Field                   */
/** @} */

/** @} */ /* End group TIM_Register_Masks_GROUP */


/* TIM15 - Peripheral instance base addresses */
#define TIM15_BasePtr                  0x40014000UL //!< Peripheral base address
#define TIM15                          ((TIM15_Type *) TIM15_BasePtr) //!< Freescale base pointer
#define TIM15_BASE_PTR                 (TIM15) //!< Freescale style base pointer
#define TIM15_IRQS { USART1_IRQn,  }


/** @} */ /* End group TIM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TIM_Peripheral_access_layer_GROUP TIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TIM16 (file:TIM16_STM32F030)         ================ */
/* ================================================================================ */

/**
 * @brief General-purpose-timers
 */
/**
 * @struct TIM16_Type
 * @brief  C Struct allowing access to TIM registers
 */
typedef struct TIM16_Type {
   __IO uint32_t  CR1;                          /**< 0000: control register 1                                           */
   __IO uint32_t  CR2;                          /**< 0004: control register 2                                           */
        uint8_t   RESERVED_0[4];                /**< 0008: 0x4 bytes                                                    */
   __IO uint32_t  DIER;                         /**< 000C: DMA/Interrupt enable register                                */
   __IO uint32_t  SR;                           /**< 0010: status register                                              */
   __O  uint32_t  EGR;                          /**< 0014: event generation register                                    */
   union {                                      /**< 0018: (size=0004)                                                  */
      __IO uint32_t  CCMR1_Input;               /**< 0018: capture/compare mode register 1 (input                       */
      __IO uint32_t  CCMR1_Output;              /**< 0018: capture/compare mode register (output                        */
   };
        uint8_t   RESERVED_1[4];                /**< 001C: 0x4 bytes                                                    */
   __IO uint32_t  CCER;                         /**< 0020: capture/compare enable                                       */
   __IO uint32_t  CNT;                          /**< 0024: counter                                                      */
   __IO uint32_t  PSC;                          /**< 0028: prescaler                                                    */
   __IO uint32_t  ARR;                          /**< 002C: auto-reload register                                         */
   __IO uint32_t  RCR;                          /**< 0030: repetition counter register                                  */
   __IO uint32_t  CCR1;                         /**< 0034: capture/compare register 1                                   */
        uint8_t   RESERVED_2[12];               /**< 0038: 0xC bytes                                                    */
   __IO uint32_t  BDTR;                         /**< 0044: break and dead-time register                                 */
   __IO uint32_t  DCR;                          /**< 0048: DMA control register                                         */
   __IO uint32_t  DMAR;                         /**< 004C: DMA address for full transfer                                */
} TIM16_Type;


/** @brief Register Masks for TIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'TIM16' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TIM_Register_Masks_GROUP TIM Register Masks */
/** @{ */

/** @name CR1 - control register 1 */ /** @{ */
#define TIM16_CR1_CEN_MASK                       (0x1U)                                              /**< TIM16_CR1.CEN Mask                      */
#define TIM16_CR1_CEN_SHIFT                      (0U)                                                /**< TIM16_CR1.CEN Position                  */
#define TIM16_CR1_CEN(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_CR1_CEN_SHIFT))&TIM16_CR1_CEN_MASK) /**< TIM16_CR1.CEN Field                     */
#define TIM16_CR1_UDIS_MASK                      (0x2U)                                              /**< TIM16_CR1.UDIS Mask                     */
#define TIM16_CR1_UDIS_SHIFT                     (1U)                                                /**< TIM16_CR1.UDIS Position                 */
#define TIM16_CR1_UDIS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_CR1_UDIS_SHIFT))&TIM16_CR1_UDIS_MASK) /**< TIM16_CR1.UDIS Field                    */
#define TIM16_CR1_URS_MASK                       (0x4U)                                              /**< TIM16_CR1.URS Mask                      */
#define TIM16_CR1_URS_SHIFT                      (2U)                                                /**< TIM16_CR1.URS Position                  */
#define TIM16_CR1_URS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_CR1_URS_SHIFT))&TIM16_CR1_URS_MASK) /**< TIM16_CR1.URS Field                     */
#define TIM16_CR1_OPM_MASK                       (0x8U)                                              /**< TIM16_CR1.OPM Mask                      */
#define TIM16_CR1_OPM_SHIFT                      (3U)                                                /**< TIM16_CR1.OPM Position                  */
#define TIM16_CR1_OPM(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_CR1_OPM_SHIFT))&TIM16_CR1_OPM_MASK) /**< TIM16_CR1.OPM Field                     */
#define TIM16_CR1_ARPE_MASK                      (0x80U)                                             /**< TIM16_CR1.ARPE Mask                     */
#define TIM16_CR1_ARPE_SHIFT                     (7U)                                                /**< TIM16_CR1.ARPE Position                 */
#define TIM16_CR1_ARPE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_CR1_ARPE_SHIFT))&TIM16_CR1_ARPE_MASK) /**< TIM16_CR1.ARPE Field                    */
#define TIM16_CR1_CKD_MASK                       (0x300U)                                            /**< TIM16_CR1.CKD Mask                      */
#define TIM16_CR1_CKD_SHIFT                      (8U)                                                /**< TIM16_CR1.CKD Position                  */
#define TIM16_CR1_CKD(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_CR1_CKD_SHIFT))&TIM16_CR1_CKD_MASK) /**< TIM16_CR1.CKD Field                     */
/** @} */

/** @name CR2 - control register 2 */ /** @{ */
#define TIM16_CR2_CCPC_MASK                      (0x1U)                                              /**< TIM16_CR2.CCPC Mask                     */
#define TIM16_CR2_CCPC_SHIFT                     (0U)                                                /**< TIM16_CR2.CCPC Position                 */
#define TIM16_CR2_CCPC(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_CR2_CCPC_SHIFT))&TIM16_CR2_CCPC_MASK) /**< TIM16_CR2.CCPC Field                    */
#define TIM16_CR2_CCUS_MASK                      (0x4U)                                              /**< TIM16_CR2.CCUS Mask                     */
#define TIM16_CR2_CCUS_SHIFT                     (2U)                                                /**< TIM16_CR2.CCUS Position                 */
#define TIM16_CR2_CCUS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_CR2_CCUS_SHIFT))&TIM16_CR2_CCUS_MASK) /**< TIM16_CR2.CCUS Field                    */
#define TIM16_CR2_CCDS_MASK                      (0x8U)                                              /**< TIM16_CR2.CCDS Mask                     */
#define TIM16_CR2_CCDS_SHIFT                     (3U)                                                /**< TIM16_CR2.CCDS Position                 */
#define TIM16_CR2_CCDS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_CR2_CCDS_SHIFT))&TIM16_CR2_CCDS_MASK) /**< TIM16_CR2.CCDS Field                    */
#define TIM16_CR2_OIS1_MASK                      (0x100U)                                            /**< TIM16_CR2.OIS1 Mask                     */
#define TIM16_CR2_OIS1_SHIFT                     (8U)                                                /**< TIM16_CR2.OIS1 Position                 */
#define TIM16_CR2_OIS1(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_CR2_OIS1_SHIFT))&TIM16_CR2_OIS1_MASK) /**< TIM16_CR2.OIS1 Field                    */
#define TIM16_CR2_OIS1N_MASK                     (0x200U)                                            /**< TIM16_CR2.OIS1N Mask                    */
#define TIM16_CR2_OIS1N_SHIFT                    (9U)                                                /**< TIM16_CR2.OIS1N Position                */
#define TIM16_CR2_OIS1N(x)                       (((uint32_t)(((uint32_t)(x))<<TIM16_CR2_OIS1N_SHIFT))&TIM16_CR2_OIS1N_MASK) /**< TIM16_CR2.OIS1N Field                   */
/** @} */

/** @name DIER - DMA/Interrupt enable register */ /** @{ */
#define TIM16_DIER_UIE_MASK                      (0x1U)                                              /**< TIM16_DIER.UIE Mask                     */
#define TIM16_DIER_UIE_SHIFT                     (0U)                                                /**< TIM16_DIER.UIE Position                 */
#define TIM16_DIER_UIE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_DIER_UIE_SHIFT))&TIM16_DIER_UIE_MASK) /**< TIM16_DIER.UIE Field                    */
#define TIM16_DIER_CC1IE_MASK                    (0x2U)                                              /**< TIM16_DIER.CC1IE Mask                   */
#define TIM16_DIER_CC1IE_SHIFT                   (1U)                                                /**< TIM16_DIER.CC1IE Position               */
#define TIM16_DIER_CC1IE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM16_DIER_CC1IE_SHIFT))&TIM16_DIER_CC1IE_MASK) /**< TIM16_DIER.CC1IE Field                  */
#define TIM16_DIER_COMIE_MASK                    (0x20U)                                             /**< TIM16_DIER.COMIE Mask                   */
#define TIM16_DIER_COMIE_SHIFT                   (5U)                                                /**< TIM16_DIER.COMIE Position               */
#define TIM16_DIER_COMIE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM16_DIER_COMIE_SHIFT))&TIM16_DIER_COMIE_MASK) /**< TIM16_DIER.COMIE Field                  */
#define TIM16_DIER_TIE_MASK                      (0x40U)                                             /**< TIM16_DIER.TIE Mask                     */
#define TIM16_DIER_TIE_SHIFT                     (6U)                                                /**< TIM16_DIER.TIE Position                 */
#define TIM16_DIER_TIE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_DIER_TIE_SHIFT))&TIM16_DIER_TIE_MASK) /**< TIM16_DIER.TIE Field                    */
#define TIM16_DIER_BIE_MASK                      (0x80U)                                             /**< TIM16_DIER.BIE Mask                     */
#define TIM16_DIER_BIE_SHIFT                     (7U)                                                /**< TIM16_DIER.BIE Position                 */
#define TIM16_DIER_BIE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_DIER_BIE_SHIFT))&TIM16_DIER_BIE_MASK) /**< TIM16_DIER.BIE Field                    */
#define TIM16_DIER_UDE_MASK                      (0x100U)                                            /**< TIM16_DIER.UDE Mask                     */
#define TIM16_DIER_UDE_SHIFT                     (8U)                                                /**< TIM16_DIER.UDE Position                 */
#define TIM16_DIER_UDE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_DIER_UDE_SHIFT))&TIM16_DIER_UDE_MASK) /**< TIM16_DIER.UDE Field                    */
#define TIM16_DIER_CC1DE_MASK                    (0x200U)                                            /**< TIM16_DIER.CC1DE Mask                   */
#define TIM16_DIER_CC1DE_SHIFT                   (9U)                                                /**< TIM16_DIER.CC1DE Position               */
#define TIM16_DIER_CC1DE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM16_DIER_CC1DE_SHIFT))&TIM16_DIER_CC1DE_MASK) /**< TIM16_DIER.CC1DE Field                  */
#define TIM16_DIER_TDE_MASK                      (0x4000U)                                           /**< TIM16_DIER.TDE Mask                     */
#define TIM16_DIER_TDE_SHIFT                     (14U)                                               /**< TIM16_DIER.TDE Position                 */
#define TIM16_DIER_TDE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_DIER_TDE_SHIFT))&TIM16_DIER_TDE_MASK) /**< TIM16_DIER.TDE Field                    */
/** @} */

/** @name SR - status register */ /** @{ */
#define TIM16_SR_UIF_MASK                        (0x1U)                                              /**< TIM16_SR.UIF Mask                       */
#define TIM16_SR_UIF_SHIFT                       (0U)                                                /**< TIM16_SR.UIF Position                   */
#define TIM16_SR_UIF(x)                          (((uint32_t)(((uint32_t)(x))<<TIM16_SR_UIF_SHIFT))&TIM16_SR_UIF_MASK) /**< TIM16_SR.UIF Field                      */
#define TIM16_SR_CC1IF_MASK                      (0x2U)                                              /**< TIM16_SR.CC1IF Mask                     */
#define TIM16_SR_CC1IF_SHIFT                     (1U)                                                /**< TIM16_SR.CC1IF Position                 */
#define TIM16_SR_CC1IF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_SR_CC1IF_SHIFT))&TIM16_SR_CC1IF_MASK) /**< TIM16_SR.CC1IF Field                    */
#define TIM16_SR_COMIF_MASK                      (0x20U)                                             /**< TIM16_SR.COMIF Mask                     */
#define TIM16_SR_COMIF_SHIFT                     (5U)                                                /**< TIM16_SR.COMIF Position                 */
#define TIM16_SR_COMIF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_SR_COMIF_SHIFT))&TIM16_SR_COMIF_MASK) /**< TIM16_SR.COMIF Field                    */
#define TIM16_SR_TIF_MASK                        (0x40U)                                             /**< TIM16_SR.TIF Mask                       */
#define TIM16_SR_TIF_SHIFT                       (6U)                                                /**< TIM16_SR.TIF Position                   */
#define TIM16_SR_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<TIM16_SR_TIF_SHIFT))&TIM16_SR_TIF_MASK) /**< TIM16_SR.TIF Field                      */
#define TIM16_SR_BIF_MASK                        (0x80U)                                             /**< TIM16_SR.BIF Mask                       */
#define TIM16_SR_BIF_SHIFT                       (7U)                                                /**< TIM16_SR.BIF Position                   */
#define TIM16_SR_BIF(x)                          (((uint32_t)(((uint32_t)(x))<<TIM16_SR_BIF_SHIFT))&TIM16_SR_BIF_MASK) /**< TIM16_SR.BIF Field                      */
#define TIM16_SR_CC1OF_MASK                      (0x200U)                                            /**< TIM16_SR.CC1OF Mask                     */
#define TIM16_SR_CC1OF_SHIFT                     (9U)                                                /**< TIM16_SR.CC1OF Position                 */
#define TIM16_SR_CC1OF(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_SR_CC1OF_SHIFT))&TIM16_SR_CC1OF_MASK) /**< TIM16_SR.CC1OF Field                    */
/** @} */

/** @name EGR - event generation register */ /** @{ */
#define TIM16_EGR_UG_MASK                        (0x1U)                                              /**< TIM16_EGR.UG Mask                       */
#define TIM16_EGR_UG_SHIFT                       (0U)                                                /**< TIM16_EGR.UG Position                   */
#define TIM16_EGR_UG(x)                          (((uint32_t)(((uint32_t)(x))<<TIM16_EGR_UG_SHIFT))&TIM16_EGR_UG_MASK) /**< TIM16_EGR.UG Field                      */
#define TIM16_EGR_CC1G_MASK                      (0x2U)                                              /**< TIM16_EGR.CC1G Mask                     */
#define TIM16_EGR_CC1G_SHIFT                     (1U)                                                /**< TIM16_EGR.CC1G Position                 */
#define TIM16_EGR_CC1G(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_EGR_CC1G_SHIFT))&TIM16_EGR_CC1G_MASK) /**< TIM16_EGR.CC1G Field                    */
#define TIM16_EGR_COMG_MASK                      (0x20U)                                             /**< TIM16_EGR.COMG Mask                     */
#define TIM16_EGR_COMG_SHIFT                     (5U)                                                /**< TIM16_EGR.COMG Position                 */
#define TIM16_EGR_COMG(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_EGR_COMG_SHIFT))&TIM16_EGR_COMG_MASK) /**< TIM16_EGR.COMG Field                    */
#define TIM16_EGR_TG_MASK                        (0x40U)                                             /**< TIM16_EGR.TG Mask                       */
#define TIM16_EGR_TG_SHIFT                       (6U)                                                /**< TIM16_EGR.TG Position                   */
#define TIM16_EGR_TG(x)                          (((uint32_t)(((uint32_t)(x))<<TIM16_EGR_TG_SHIFT))&TIM16_EGR_TG_MASK) /**< TIM16_EGR.TG Field                      */
#define TIM16_EGR_BG_MASK                        (0x80U)                                             /**< TIM16_EGR.BG Mask                       */
#define TIM16_EGR_BG_SHIFT                       (7U)                                                /**< TIM16_EGR.BG Position                   */
#define TIM16_EGR_BG(x)                          (((uint32_t)(((uint32_t)(x))<<TIM16_EGR_BG_SHIFT))&TIM16_EGR_BG_MASK) /**< TIM16_EGR.BG Field                      */
/** @} */

/** @name CCMR1_Input - capture/compare mode register 1 (input */ /** @{ */
#define TIM16_CCMR1_Input_CC1S_MASK              (0x3U)                                              /**< TIM16_CCMR1_Input.CC1S Mask             */
#define TIM16_CCMR1_Input_CC1S_SHIFT             (0U)                                                /**< TIM16_CCMR1_Input.CC1S Position         */
#define TIM16_CCMR1_Input_CC1S(x)                (((uint32_t)(((uint32_t)(x))<<TIM16_CCMR1_Input_CC1S_SHIFT))&TIM16_CCMR1_Input_CC1S_MASK) /**< TIM16_CCMR1_Input.CC1S Field            */
#define TIM16_CCMR1_Input_IC1PSC_MASK            (0xCU)                                              /**< TIM16_CCMR1_Input.IC1PSC Mask           */
#define TIM16_CCMR1_Input_IC1PSC_SHIFT           (2U)                                                /**< TIM16_CCMR1_Input.IC1PSC Position       */
#define TIM16_CCMR1_Input_IC1PSC(x)              (((uint32_t)(((uint32_t)(x))<<TIM16_CCMR1_Input_IC1PSC_SHIFT))&TIM16_CCMR1_Input_IC1PSC_MASK) /**< TIM16_CCMR1_Input.IC1PSC Field          */
#define TIM16_CCMR1_Input_IC1F_MASK              (0xF0U)                                             /**< TIM16_CCMR1_Input.IC1F Mask             */
#define TIM16_CCMR1_Input_IC1F_SHIFT             (4U)                                                /**< TIM16_CCMR1_Input.IC1F Position         */
#define TIM16_CCMR1_Input_IC1F(x)                (((uint32_t)(((uint32_t)(x))<<TIM16_CCMR1_Input_IC1F_SHIFT))&TIM16_CCMR1_Input_IC1F_MASK) /**< TIM16_CCMR1_Input.IC1F Field            */
/** @} */

/** @name CCMR1_Output - capture/compare mode register (output */ /** @{ */
#define TIM16_CCMR1_Output_CC1S_MASK             (0x3U)                                              /**< TIM16_CCMR1_Output.CC1S Mask            */
#define TIM16_CCMR1_Output_CC1S_SHIFT            (0U)                                                /**< TIM16_CCMR1_Output.CC1S Position        */
#define TIM16_CCMR1_Output_CC1S(x)               (((uint32_t)(((uint32_t)(x))<<TIM16_CCMR1_Output_CC1S_SHIFT))&TIM16_CCMR1_Output_CC1S_MASK) /**< TIM16_CCMR1_Output.CC1S Field           */
#define TIM16_CCMR1_Output_OC1FE_MASK            (0x4U)                                              /**< TIM16_CCMR1_Output.OC1FE Mask           */
#define TIM16_CCMR1_Output_OC1FE_SHIFT           (2U)                                                /**< TIM16_CCMR1_Output.OC1FE Position       */
#define TIM16_CCMR1_Output_OC1FE(x)              (((uint32_t)(((uint32_t)(x))<<TIM16_CCMR1_Output_OC1FE_SHIFT))&TIM16_CCMR1_Output_OC1FE_MASK) /**< TIM16_CCMR1_Output.OC1FE Field          */
#define TIM16_CCMR1_Output_OC1PE_MASK            (0x8U)                                              /**< TIM16_CCMR1_Output.OC1PE Mask           */
#define TIM16_CCMR1_Output_OC1PE_SHIFT           (3U)                                                /**< TIM16_CCMR1_Output.OC1PE Position       */
#define TIM16_CCMR1_Output_OC1PE(x)              (((uint32_t)(((uint32_t)(x))<<TIM16_CCMR1_Output_OC1PE_SHIFT))&TIM16_CCMR1_Output_OC1PE_MASK) /**< TIM16_CCMR1_Output.OC1PE Field          */
#define TIM16_CCMR1_Output_OC1M_MASK             (0x70U)                                             /**< TIM16_CCMR1_Output.OC1M Mask            */
#define TIM16_CCMR1_Output_OC1M_SHIFT            (4U)                                                /**< TIM16_CCMR1_Output.OC1M Position        */
#define TIM16_CCMR1_Output_OC1M(x)               (((uint32_t)(((uint32_t)(x))<<TIM16_CCMR1_Output_OC1M_SHIFT))&TIM16_CCMR1_Output_OC1M_MASK) /**< TIM16_CCMR1_Output.OC1M Field           */
/** @} */

/** @name CCER - capture/compare enable */ /** @{ */
#define TIM16_CCER_CC1E_MASK                     (0x1U)                                              /**< TIM16_CCER.CC1E Mask                    */
#define TIM16_CCER_CC1E_SHIFT                    (0U)                                                /**< TIM16_CCER.CC1E Position                */
#define TIM16_CCER_CC1E(x)                       (((uint32_t)(((uint32_t)(x))<<TIM16_CCER_CC1E_SHIFT))&TIM16_CCER_CC1E_MASK) /**< TIM16_CCER.CC1E Field                   */
#define TIM16_CCER_CC1P_MASK                     (0x2U)                                              /**< TIM16_CCER.CC1P Mask                    */
#define TIM16_CCER_CC1P_SHIFT                    (1U)                                                /**< TIM16_CCER.CC1P Position                */
#define TIM16_CCER_CC1P(x)                       (((uint32_t)(((uint32_t)(x))<<TIM16_CCER_CC1P_SHIFT))&TIM16_CCER_CC1P_MASK) /**< TIM16_CCER.CC1P Field                   */
#define TIM16_CCER_CC1NE_MASK                    (0x4U)                                              /**< TIM16_CCER.CC1NE Mask                   */
#define TIM16_CCER_CC1NE_SHIFT                   (2U)                                                /**< TIM16_CCER.CC1NE Position               */
#define TIM16_CCER_CC1NE(x)                      (((uint32_t)(((uint32_t)(x))<<TIM16_CCER_CC1NE_SHIFT))&TIM16_CCER_CC1NE_MASK) /**< TIM16_CCER.CC1NE Field                  */
#define TIM16_CCER_CC1NP_MASK                    (0x8U)                                              /**< TIM16_CCER.CC1NP Mask                   */
#define TIM16_CCER_CC1NP_SHIFT                   (3U)                                                /**< TIM16_CCER.CC1NP Position               */
#define TIM16_CCER_CC1NP(x)                      (((uint32_t)(((uint32_t)(x))<<TIM16_CCER_CC1NP_SHIFT))&TIM16_CCER_CC1NP_MASK) /**< TIM16_CCER.CC1NP Field                  */
/** @} */

/** @name CNT - counter */ /** @{ */
#define TIM16_CNT_CNT_MASK                       (0xFFFFU)                                           /**< TIM16_CNT.CNT Mask                      */
#define TIM16_CNT_CNT_SHIFT                      (0U)                                                /**< TIM16_CNT.CNT Position                  */
#define TIM16_CNT_CNT(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_CNT_CNT_SHIFT))&TIM16_CNT_CNT_MASK) /**< TIM16_CNT.CNT Field                     */
/** @} */

/** @name PSC - prescaler */ /** @{ */
#define TIM16_PSC_PSC_MASK                       (0xFFFFU)                                           /**< TIM16_PSC.PSC Mask                      */
#define TIM16_PSC_PSC_SHIFT                      (0U)                                                /**< TIM16_PSC.PSC Position                  */
#define TIM16_PSC_PSC(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_PSC_PSC_SHIFT))&TIM16_PSC_PSC_MASK) /**< TIM16_PSC.PSC Field                     */
/** @} */

/** @name ARR - auto-reload register */ /** @{ */
#define TIM16_ARR_ARR_MASK                       (0xFFFFU)                                           /**< TIM16_ARR.ARR Mask                      */
#define TIM16_ARR_ARR_SHIFT                      (0U)                                                /**< TIM16_ARR.ARR Position                  */
#define TIM16_ARR_ARR(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_ARR_ARR_SHIFT))&TIM16_ARR_ARR_MASK) /**< TIM16_ARR.ARR Field                     */
/** @} */

/** @name RCR - repetition counter register */ /** @{ */
#define TIM16_RCR_REP_MASK                       (0xFFU)                                             /**< TIM16_RCR.REP Mask                      */
#define TIM16_RCR_REP_SHIFT                      (0U)                                                /**< TIM16_RCR.REP Position                  */
#define TIM16_RCR_REP(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_RCR_REP_SHIFT))&TIM16_RCR_REP_MASK) /**< TIM16_RCR.REP Field                     */
/** @} */

/** @name CCR1 - capture/compare register 1 */ /** @{ */
#define TIM16_CCR1_CCR_MASK                      (0xFFFFU)                                           /**< TIM16_CCR1.CCR Mask                     */
#define TIM16_CCR1_CCR_SHIFT                     (0U)                                                /**< TIM16_CCR1.CCR Position                 */
#define TIM16_CCR1_CCR(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_CCR1_CCR_SHIFT))&TIM16_CCR1_CCR_MASK) /**< TIM16_CCR1.CCR Field                    */
/** @} */

/** @name BDTR - break and dead-time register */ /** @{ */
#define TIM16_BDTR_DTG_MASK                      (0xFFU)                                             /**< TIM16_BDTR.DTG Mask                     */
#define TIM16_BDTR_DTG_SHIFT                     (0U)                                                /**< TIM16_BDTR.DTG Position                 */
#define TIM16_BDTR_DTG(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_BDTR_DTG_SHIFT))&TIM16_BDTR_DTG_MASK) /**< TIM16_BDTR.DTG Field                    */
#define TIM16_BDTR_LOCK_MASK                     (0x300U)                                            /**< TIM16_BDTR.LOCK Mask                    */
#define TIM16_BDTR_LOCK_SHIFT                    (8U)                                                /**< TIM16_BDTR.LOCK Position                */
#define TIM16_BDTR_LOCK(x)                       (((uint32_t)(((uint32_t)(x))<<TIM16_BDTR_LOCK_SHIFT))&TIM16_BDTR_LOCK_MASK) /**< TIM16_BDTR.LOCK Field                   */
#define TIM16_BDTR_OSSI_MASK                     (0x400U)                                            /**< TIM16_BDTR.OSSI Mask                    */
#define TIM16_BDTR_OSSI_SHIFT                    (10U)                                               /**< TIM16_BDTR.OSSI Position                */
#define TIM16_BDTR_OSSI(x)                       (((uint32_t)(((uint32_t)(x))<<TIM16_BDTR_OSSI_SHIFT))&TIM16_BDTR_OSSI_MASK) /**< TIM16_BDTR.OSSI Field                   */
#define TIM16_BDTR_OSSR_MASK                     (0x800U)                                            /**< TIM16_BDTR.OSSR Mask                    */
#define TIM16_BDTR_OSSR_SHIFT                    (11U)                                               /**< TIM16_BDTR.OSSR Position                */
#define TIM16_BDTR_OSSR(x)                       (((uint32_t)(((uint32_t)(x))<<TIM16_BDTR_OSSR_SHIFT))&TIM16_BDTR_OSSR_MASK) /**< TIM16_BDTR.OSSR Field                   */
#define TIM16_BDTR_BKE_MASK                      (0x1000U)                                           /**< TIM16_BDTR.BKE Mask                     */
#define TIM16_BDTR_BKE_SHIFT                     (12U)                                               /**< TIM16_BDTR.BKE Position                 */
#define TIM16_BDTR_BKE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_BDTR_BKE_SHIFT))&TIM16_BDTR_BKE_MASK) /**< TIM16_BDTR.BKE Field                    */
#define TIM16_BDTR_BKP_MASK                      (0x2000U)                                           /**< TIM16_BDTR.BKP Mask                     */
#define TIM16_BDTR_BKP_SHIFT                     (13U)                                               /**< TIM16_BDTR.BKP Position                 */
#define TIM16_BDTR_BKP(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_BDTR_BKP_SHIFT))&TIM16_BDTR_BKP_MASK) /**< TIM16_BDTR.BKP Field                    */
#define TIM16_BDTR_AOE_MASK                      (0x4000U)                                           /**< TIM16_BDTR.AOE Mask                     */
#define TIM16_BDTR_AOE_SHIFT                     (14U)                                               /**< TIM16_BDTR.AOE Position                 */
#define TIM16_BDTR_AOE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_BDTR_AOE_SHIFT))&TIM16_BDTR_AOE_MASK) /**< TIM16_BDTR.AOE Field                    */
#define TIM16_BDTR_MOE_MASK                      (0x8000U)                                           /**< TIM16_BDTR.MOE Mask                     */
#define TIM16_BDTR_MOE_SHIFT                     (15U)                                               /**< TIM16_BDTR.MOE Position                 */
#define TIM16_BDTR_MOE(x)                        (((uint32_t)(((uint32_t)(x))<<TIM16_BDTR_MOE_SHIFT))&TIM16_BDTR_MOE_MASK) /**< TIM16_BDTR.MOE Field                    */
/** @} */

/** @name DCR - DMA control register */ /** @{ */
#define TIM16_DCR_DBA_MASK                       (0x1FU)                                             /**< TIM16_DCR.DBA Mask                      */
#define TIM16_DCR_DBA_SHIFT                      (0U)                                                /**< TIM16_DCR.DBA Position                  */
#define TIM16_DCR_DBA(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_DCR_DBA_SHIFT))&TIM16_DCR_DBA_MASK) /**< TIM16_DCR.DBA Field                     */
#define TIM16_DCR_DBL_MASK                       (0x1F00U)                                           /**< TIM16_DCR.DBL Mask                      */
#define TIM16_DCR_DBL_SHIFT                      (8U)                                                /**< TIM16_DCR.DBL Position                  */
#define TIM16_DCR_DBL(x)                         (((uint32_t)(((uint32_t)(x))<<TIM16_DCR_DBL_SHIFT))&TIM16_DCR_DBL_MASK) /**< TIM16_DCR.DBL Field                     */
/** @} */

/** @name DMAR - DMA address for full transfer */ /** @{ */
#define TIM16_DMAR_DMAB_MASK                     (0xFFFFU)                                           /**< TIM16_DMAR.DMAB Mask                    */
#define TIM16_DMAR_DMAB_SHIFT                    (0U)                                                /**< TIM16_DMAR.DMAB Position                */
#define TIM16_DMAR_DMAB(x)                       (((uint32_t)(((uint32_t)(x))<<TIM16_DMAR_DMAB_SHIFT))&TIM16_DMAR_DMAB_MASK) /**< TIM16_DMAR.DMAB Field                   */
/** @} */

/** @} */ /* End group TIM_Register_Masks_GROUP */


/* TIM16 - Peripheral instance base addresses */
#define TIM16_BasePtr                  0x40014400UL //!< Peripheral base address
#define TIM16                          ((TIM16_Type *) TIM16_BasePtr) //!< Freescale base pointer
#define TIM16_BASE_PTR                 (TIM16) //!< Freescale style base pointer
#define TIM16_IRQS { USART2_IRQn,  }


/** @} */ /* End group TIM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TIM_Peripheral_access_layer_GROUP TIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TIM17 (derived from TIM16)           ================ */
/* ================================================================================ */

/**
 * @brief General-purpose-timers
 */

/* TIM17 - Peripheral instance base addresses */
#define TIM17_BasePtr                  0x40014800UL //!< Peripheral base address
#define TIM17                          ((TIM16_Type *) TIM17_BasePtr) //!< Freescale base pointer
#define TIM17_BASE_PTR                 (TIM17) //!< Freescale style base pointer
#define TIM17_IRQS { USART3_4_IRQn,  }


/** @} */ /* End group TIM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TIM_Peripheral_access_layer_GROUP TIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TIM3 (file:TIM3_STM32F030)           ================ */
/* ================================================================================ */

/**
 * @brief General-purpose-timers
 */
/**
 * @struct TIM3_Type
 * @brief  C Struct allowing access to TIM registers
 */
typedef struct TIM3_Type {
   __IO uint32_t  CR1;                          /**< 0000: control register 1                                           */
   __IO uint32_t  CR2;                          /**< 0004: control register 2                                           */
   __IO uint32_t  SMCR;                         /**< 0008: slave mode control register                                  */
   __IO uint32_t  DIER;                         /**< 000C: DMA/Interrupt enable register                                */
   __IO uint32_t  SR;                           /**< 0010: status register                                              */
   __O  uint32_t  EGR;                          /**< 0014: event generation register                                    */
   union {                                      /**< 0018: (size=0004)                                                  */
      __IO uint32_t  CCMR1_Input;               /**< 0018: capture/compare mode register 1 (input                       */
      __IO uint32_t  CCMR1_Output;              /**< 0018: capture/compare mode register 1 (output                      */
   };
   union {                                      /**< 001C: (size=0004)                                                  */
      __IO uint32_t  CCMR2_Input;               /**< 001C: capture/compare mode register 2 (input                       */
      __IO uint32_t  CCMR2_Output;              /**< 001C: capture/compare mode register 2 (output                      */
   };
   __IO uint32_t  CCER;                         /**< 0020: capture/compare enable                                       */
   __IO uint32_t  CNT;                          /**< 0024: counter                                                      */
   __IO uint32_t  PSC;                          /**< 0028: prescaler                                                    */
   __IO uint32_t  ARR;                          /**< 002C: auto-reload register                                         */
        uint8_t   RESERVED_0[4];                /**< 0030: 0x4 bytes                                                    */
   __IO uint32_t  CCR1;                         /**< 0034: capture/compare register 1                                   */
   __IO uint32_t  CCR2;                         /**< 0038: capture/compare register 2                                   */
   __IO uint32_t  CCR3;                         /**< 003C: capture/compare register 3                                   */
   __IO uint32_t  CCR4;                         /**< 0040: capture/compare register 4                                   */
        uint8_t   RESERVED_1[4];                /**< 0044: 0x4 bytes                                                    */
   __IO uint32_t  DCR;                          /**< 0048: DMA control register                                         */
   __IO uint32_t  DMAR;                         /**< 004C: DMA address for full transfer                                */
} TIM3_Type;


/** @brief Register Masks for TIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'TIM3' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TIM_Register_Masks_GROUP TIM Register Masks */
/** @{ */

/** @name CR1 - control register 1 */ /** @{ */
#define TIM3_CR1_CEN_MASK                        (0x1U)                                              /**< TIM3_CR1.CEN Mask                       */
#define TIM3_CR1_CEN_SHIFT                       (0U)                                                /**< TIM3_CR1.CEN Position                   */
#define TIM3_CR1_CEN(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_CR1_CEN_SHIFT))&TIM3_CR1_CEN_MASK) /**< TIM3_CR1.CEN Field                      */
#define TIM3_CR1_UDIS_MASK                       (0x2U)                                              /**< TIM3_CR1.UDIS Mask                      */
#define TIM3_CR1_UDIS_SHIFT                      (1U)                                                /**< TIM3_CR1.UDIS Position                  */
#define TIM3_CR1_UDIS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_CR1_UDIS_SHIFT))&TIM3_CR1_UDIS_MASK) /**< TIM3_CR1.UDIS Field                     */
#define TIM3_CR1_URS_MASK                        (0x4U)                                              /**< TIM3_CR1.URS Mask                       */
#define TIM3_CR1_URS_SHIFT                       (2U)                                                /**< TIM3_CR1.URS Position                   */
#define TIM3_CR1_URS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_CR1_URS_SHIFT))&TIM3_CR1_URS_MASK) /**< TIM3_CR1.URS Field                      */
#define TIM3_CR1_OPM_MASK                        (0x8U)                                              /**< TIM3_CR1.OPM Mask                       */
#define TIM3_CR1_OPM_SHIFT                       (3U)                                                /**< TIM3_CR1.OPM Position                   */
#define TIM3_CR1_OPM(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_CR1_OPM_SHIFT))&TIM3_CR1_OPM_MASK) /**< TIM3_CR1.OPM Field                      */
#define TIM3_CR1_DIR_MASK                        (0x10U)                                             /**< TIM3_CR1.DIR Mask                       */
#define TIM3_CR1_DIR_SHIFT                       (4U)                                                /**< TIM3_CR1.DIR Position                   */
#define TIM3_CR1_DIR(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_CR1_DIR_SHIFT))&TIM3_CR1_DIR_MASK) /**< TIM3_CR1.DIR Field                      */
#define TIM3_CR1_CMS_MASK                        (0x60U)                                             /**< TIM3_CR1.CMS Mask                       */
#define TIM3_CR1_CMS_SHIFT                       (5U)                                                /**< TIM3_CR1.CMS Position                   */
#define TIM3_CR1_CMS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_CR1_CMS_SHIFT))&TIM3_CR1_CMS_MASK) /**< TIM3_CR1.CMS Field                      */
#define TIM3_CR1_ARPE_MASK                       (0x80U)                                             /**< TIM3_CR1.ARPE Mask                      */
#define TIM3_CR1_ARPE_SHIFT                      (7U)                                                /**< TIM3_CR1.ARPE Position                  */
#define TIM3_CR1_ARPE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_CR1_ARPE_SHIFT))&TIM3_CR1_ARPE_MASK) /**< TIM3_CR1.ARPE Field                     */
#define TIM3_CR1_CKD_MASK                        (0x300U)                                            /**< TIM3_CR1.CKD Mask                       */
#define TIM3_CR1_CKD_SHIFT                       (8U)                                                /**< TIM3_CR1.CKD Position                   */
#define TIM3_CR1_CKD(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_CR1_CKD_SHIFT))&TIM3_CR1_CKD_MASK) /**< TIM3_CR1.CKD Field                      */
/** @} */

/** @name CR2 - control register 2 */ /** @{ */
#define TIM3_CR2_CCDS_MASK                       (0x8U)                                              /**< TIM3_CR2.CCDS Mask                      */
#define TIM3_CR2_CCDS_SHIFT                      (3U)                                                /**< TIM3_CR2.CCDS Position                  */
#define TIM3_CR2_CCDS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_CR2_CCDS_SHIFT))&TIM3_CR2_CCDS_MASK) /**< TIM3_CR2.CCDS Field                     */
#define TIM3_CR2_MMS_MASK                        (0x70U)                                             /**< TIM3_CR2.MMS Mask                       */
#define TIM3_CR2_MMS_SHIFT                       (4U)                                                /**< TIM3_CR2.MMS Position                   */
#define TIM3_CR2_MMS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_CR2_MMS_SHIFT))&TIM3_CR2_MMS_MASK) /**< TIM3_CR2.MMS Field                      */
#define TIM3_CR2_TI1S_MASK                       (0x80U)                                             /**< TIM3_CR2.TI1S Mask                      */
#define TIM3_CR2_TI1S_SHIFT                      (7U)                                                /**< TIM3_CR2.TI1S Position                  */
#define TIM3_CR2_TI1S(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_CR2_TI1S_SHIFT))&TIM3_CR2_TI1S_MASK) /**< TIM3_CR2.TI1S Field                     */
/** @} */

/** @name SMCR - slave mode control register */ /** @{ */
#define TIM3_SMCR_SMS_MASK                       (0x7U)                                              /**< TIM3_SMCR.SMS Mask                      */
#define TIM3_SMCR_SMS_SHIFT                      (0U)                                                /**< TIM3_SMCR.SMS Position                  */
#define TIM3_SMCR_SMS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SMCR_SMS_SHIFT))&TIM3_SMCR_SMS_MASK) /**< TIM3_SMCR.SMS Field                     */
#define TIM3_SMCR_TS_MASK                        (0x70U)                                             /**< TIM3_SMCR.TS Mask                       */
#define TIM3_SMCR_TS_SHIFT                       (4U)                                                /**< TIM3_SMCR.TS Position                   */
#define TIM3_SMCR_TS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_SMCR_TS_SHIFT))&TIM3_SMCR_TS_MASK) /**< TIM3_SMCR.TS Field                      */
#define TIM3_SMCR_MSM_MASK                       (0x80U)                                             /**< TIM3_SMCR.MSM Mask                      */
#define TIM3_SMCR_MSM_SHIFT                      (7U)                                                /**< TIM3_SMCR.MSM Position                  */
#define TIM3_SMCR_MSM(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SMCR_MSM_SHIFT))&TIM3_SMCR_MSM_MASK) /**< TIM3_SMCR.MSM Field                     */
#define TIM3_SMCR_ETF_MASK                       (0xF00U)                                            /**< TIM3_SMCR.ETF Mask                      */
#define TIM3_SMCR_ETF_SHIFT                      (8U)                                                /**< TIM3_SMCR.ETF Position                  */
#define TIM3_SMCR_ETF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SMCR_ETF_SHIFT))&TIM3_SMCR_ETF_MASK) /**< TIM3_SMCR.ETF Field                     */
#define TIM3_SMCR_ETPS_MASK                      (0x3000U)                                           /**< TIM3_SMCR.ETPS Mask                     */
#define TIM3_SMCR_ETPS_SHIFT                     (12U)                                               /**< TIM3_SMCR.ETPS Position                 */
#define TIM3_SMCR_ETPS(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_SMCR_ETPS_SHIFT))&TIM3_SMCR_ETPS_MASK) /**< TIM3_SMCR.ETPS Field                    */
#define TIM3_SMCR_ECE_MASK                       (0x4000U)                                           /**< TIM3_SMCR.ECE Mask                      */
#define TIM3_SMCR_ECE_SHIFT                      (14U)                                               /**< TIM3_SMCR.ECE Position                  */
#define TIM3_SMCR_ECE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SMCR_ECE_SHIFT))&TIM3_SMCR_ECE_MASK) /**< TIM3_SMCR.ECE Field                     */
#define TIM3_SMCR_ETP_MASK                       (0x8000U)                                           /**< TIM3_SMCR.ETP Mask                      */
#define TIM3_SMCR_ETP_SHIFT                      (15U)                                               /**< TIM3_SMCR.ETP Position                  */
#define TIM3_SMCR_ETP(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SMCR_ETP_SHIFT))&TIM3_SMCR_ETP_MASK) /**< TIM3_SMCR.ETP Field                     */
/** @} */

/** @name DIER - DMA/Interrupt enable register */ /** @{ */
#define TIM3_DIER_UIE_MASK                       (0x1U)                                              /**< TIM3_DIER.UIE Mask                      */
#define TIM3_DIER_UIE_SHIFT                      (0U)                                                /**< TIM3_DIER.UIE Position                  */
#define TIM3_DIER_UIE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_UIE_SHIFT))&TIM3_DIER_UIE_MASK) /**< TIM3_DIER.UIE Field                     */
#define TIM3_DIER_CC1IE_MASK                     (0x2U)                                              /**< TIM3_DIER.CC1IE Mask                    */
#define TIM3_DIER_CC1IE_SHIFT                    (1U)                                                /**< TIM3_DIER.CC1IE Position                */
#define TIM3_DIER_CC1IE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_CC1IE_SHIFT))&TIM3_DIER_CC1IE_MASK) /**< TIM3_DIER.CC1IE Field                   */
#define TIM3_DIER_CC2IE_MASK                     (0x4U)                                              /**< TIM3_DIER.CC2IE Mask                    */
#define TIM3_DIER_CC2IE_SHIFT                    (2U)                                                /**< TIM3_DIER.CC2IE Position                */
#define TIM3_DIER_CC2IE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_CC2IE_SHIFT))&TIM3_DIER_CC2IE_MASK) /**< TIM3_DIER.CC2IE Field                   */
#define TIM3_DIER_CC3IE_MASK                     (0x8U)                                              /**< TIM3_DIER.CC3IE Mask                    */
#define TIM3_DIER_CC3IE_SHIFT                    (3U)                                                /**< TIM3_DIER.CC3IE Position                */
#define TIM3_DIER_CC3IE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_CC3IE_SHIFT))&TIM3_DIER_CC3IE_MASK) /**< TIM3_DIER.CC3IE Field                   */
#define TIM3_DIER_CC4IE_MASK                     (0x10U)                                             /**< TIM3_DIER.CC4IE Mask                    */
#define TIM3_DIER_CC4IE_SHIFT                    (4U)                                                /**< TIM3_DIER.CC4IE Position                */
#define TIM3_DIER_CC4IE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_CC4IE_SHIFT))&TIM3_DIER_CC4IE_MASK) /**< TIM3_DIER.CC4IE Field                   */
#define TIM3_DIER_TIE_MASK                       (0x40U)                                             /**< TIM3_DIER.TIE Mask                      */
#define TIM3_DIER_TIE_SHIFT                      (6U)                                                /**< TIM3_DIER.TIE Position                  */
#define TIM3_DIER_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_TIE_SHIFT))&TIM3_DIER_TIE_MASK) /**< TIM3_DIER.TIE Field                     */
#define TIM3_DIER_UDE_MASK                       (0x100U)                                            /**< TIM3_DIER.UDE Mask                      */
#define TIM3_DIER_UDE_SHIFT                      (8U)                                                /**< TIM3_DIER.UDE Position                  */
#define TIM3_DIER_UDE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_UDE_SHIFT))&TIM3_DIER_UDE_MASK) /**< TIM3_DIER.UDE Field                     */
#define TIM3_DIER_CC1DE_MASK                     (0x200U)                                            /**< TIM3_DIER.CC1DE Mask                    */
#define TIM3_DIER_CC1DE_SHIFT                    (9U)                                                /**< TIM3_DIER.CC1DE Position                */
#define TIM3_DIER_CC1DE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_CC1DE_SHIFT))&TIM3_DIER_CC1DE_MASK) /**< TIM3_DIER.CC1DE Field                   */
#define TIM3_DIER_CC2DE_MASK                     (0x400U)                                            /**< TIM3_DIER.CC2DE Mask                    */
#define TIM3_DIER_CC2DE_SHIFT                    (10U)                                               /**< TIM3_DIER.CC2DE Position                */
#define TIM3_DIER_CC2DE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_CC2DE_SHIFT))&TIM3_DIER_CC2DE_MASK) /**< TIM3_DIER.CC2DE Field                   */
#define TIM3_DIER_CC3DE_MASK                     (0x800U)                                            /**< TIM3_DIER.CC3DE Mask                    */
#define TIM3_DIER_CC3DE_SHIFT                    (11U)                                               /**< TIM3_DIER.CC3DE Position                */
#define TIM3_DIER_CC3DE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_CC3DE_SHIFT))&TIM3_DIER_CC3DE_MASK) /**< TIM3_DIER.CC3DE Field                   */
#define TIM3_DIER_CC4DE_MASK                     (0x1000U)                                           /**< TIM3_DIER.CC4DE Mask                    */
#define TIM3_DIER_CC4DE_SHIFT                    (12U)                                               /**< TIM3_DIER.CC4DE Position                */
#define TIM3_DIER_CC4DE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_CC4DE_SHIFT))&TIM3_DIER_CC4DE_MASK) /**< TIM3_DIER.CC4DE Field                   */
#define TIM3_DIER_COMDE_MASK                     (0x2000U)                                           /**< TIM3_DIER.COMDE Mask                    */
#define TIM3_DIER_COMDE_SHIFT                    (13U)                                               /**< TIM3_DIER.COMDE Position                */
#define TIM3_DIER_COMDE(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_COMDE_SHIFT))&TIM3_DIER_COMDE_MASK) /**< TIM3_DIER.COMDE Field                   */
#define TIM3_DIER_TDE_MASK                       (0x4000U)                                           /**< TIM3_DIER.TDE Mask                      */
#define TIM3_DIER_TDE_SHIFT                      (14U)                                               /**< TIM3_DIER.TDE Position                  */
#define TIM3_DIER_TDE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_DIER_TDE_SHIFT))&TIM3_DIER_TDE_MASK) /**< TIM3_DIER.TDE Field                     */
/** @} */

/** @name SR - status register */ /** @{ */
#define TIM3_SR_UIF_MASK                         (0x1U)                                              /**< TIM3_SR.UIF Mask                        */
#define TIM3_SR_UIF_SHIFT                        (0U)                                                /**< TIM3_SR.UIF Position                    */
#define TIM3_SR_UIF(x)                           (((uint32_t)(((uint32_t)(x))<<TIM3_SR_UIF_SHIFT))&TIM3_SR_UIF_MASK) /**< TIM3_SR.UIF Field                       */
#define TIM3_SR_CC1IF_MASK                       (0x2U)                                              /**< TIM3_SR.CC1IF Mask                      */
#define TIM3_SR_CC1IF_SHIFT                      (1U)                                                /**< TIM3_SR.CC1IF Position                  */
#define TIM3_SR_CC1IF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SR_CC1IF_SHIFT))&TIM3_SR_CC1IF_MASK) /**< TIM3_SR.CC1IF Field                     */
#define TIM3_SR_CC2IF_MASK                       (0x4U)                                              /**< TIM3_SR.CC2IF Mask                      */
#define TIM3_SR_CC2IF_SHIFT                      (2U)                                                /**< TIM3_SR.CC2IF Position                  */
#define TIM3_SR_CC2IF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SR_CC2IF_SHIFT))&TIM3_SR_CC2IF_MASK) /**< TIM3_SR.CC2IF Field                     */
#define TIM3_SR_CC3IF_MASK                       (0x8U)                                              /**< TIM3_SR.CC3IF Mask                      */
#define TIM3_SR_CC3IF_SHIFT                      (3U)                                                /**< TIM3_SR.CC3IF Position                  */
#define TIM3_SR_CC3IF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SR_CC3IF_SHIFT))&TIM3_SR_CC3IF_MASK) /**< TIM3_SR.CC3IF Field                     */
#define TIM3_SR_CC4IF_MASK                       (0x10U)                                             /**< TIM3_SR.CC4IF Mask                      */
#define TIM3_SR_CC4IF_SHIFT                      (4U)                                                /**< TIM3_SR.CC4IF Position                  */
#define TIM3_SR_CC4IF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SR_CC4IF_SHIFT))&TIM3_SR_CC4IF_MASK) /**< TIM3_SR.CC4IF Field                     */
#define TIM3_SR_TIF_MASK                         (0x40U)                                             /**< TIM3_SR.TIF Mask                        */
#define TIM3_SR_TIF_SHIFT                        (6U)                                                /**< TIM3_SR.TIF Position                    */
#define TIM3_SR_TIF(x)                           (((uint32_t)(((uint32_t)(x))<<TIM3_SR_TIF_SHIFT))&TIM3_SR_TIF_MASK) /**< TIM3_SR.TIF Field                       */
#define TIM3_SR_CC1OF_MASK                       (0x200U)                                            /**< TIM3_SR.CC1OF Mask                      */
#define TIM3_SR_CC1OF_SHIFT                      (9U)                                                /**< TIM3_SR.CC1OF Position                  */
#define TIM3_SR_CC1OF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SR_CC1OF_SHIFT))&TIM3_SR_CC1OF_MASK) /**< TIM3_SR.CC1OF Field                     */
#define TIM3_SR_CC2OF_MASK                       (0x400U)                                            /**< TIM3_SR.CC2OF Mask                      */
#define TIM3_SR_CC2OF_SHIFT                      (10U)                                               /**< TIM3_SR.CC2OF Position                  */
#define TIM3_SR_CC2OF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SR_CC2OF_SHIFT))&TIM3_SR_CC2OF_MASK) /**< TIM3_SR.CC2OF Field                     */
#define TIM3_SR_CC3OF_MASK                       (0x800U)                                            /**< TIM3_SR.CC3OF Mask                      */
#define TIM3_SR_CC3OF_SHIFT                      (11U)                                               /**< TIM3_SR.CC3OF Position                  */
#define TIM3_SR_CC3OF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SR_CC3OF_SHIFT))&TIM3_SR_CC3OF_MASK) /**< TIM3_SR.CC3OF Field                     */
#define TIM3_SR_CC4OF_MASK                       (0x1000U)                                           /**< TIM3_SR.CC4OF Mask                      */
#define TIM3_SR_CC4OF_SHIFT                      (12U)                                               /**< TIM3_SR.CC4OF Position                  */
#define TIM3_SR_CC4OF(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_SR_CC4OF_SHIFT))&TIM3_SR_CC4OF_MASK) /**< TIM3_SR.CC4OF Field                     */
/** @} */

/** @name EGR - event generation register */ /** @{ */
#define TIM3_EGR_UG_MASK                         (0x1U)                                              /**< TIM3_EGR.UG Mask                        */
#define TIM3_EGR_UG_SHIFT                        (0U)                                                /**< TIM3_EGR.UG Position                    */
#define TIM3_EGR_UG(x)                           (((uint32_t)(((uint32_t)(x))<<TIM3_EGR_UG_SHIFT))&TIM3_EGR_UG_MASK) /**< TIM3_EGR.UG Field                       */
#define TIM3_EGR_CC1G_MASK                       (0x2U)                                              /**< TIM3_EGR.CC1G Mask                      */
#define TIM3_EGR_CC1G_SHIFT                      (1U)                                                /**< TIM3_EGR.CC1G Position                  */
#define TIM3_EGR_CC1G(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_EGR_CC1G_SHIFT))&TIM3_EGR_CC1G_MASK) /**< TIM3_EGR.CC1G Field                     */
#define TIM3_EGR_CC2G_MASK                       (0x4U)                                              /**< TIM3_EGR.CC2G Mask                      */
#define TIM3_EGR_CC2G_SHIFT                      (2U)                                                /**< TIM3_EGR.CC2G Position                  */
#define TIM3_EGR_CC2G(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_EGR_CC2G_SHIFT))&TIM3_EGR_CC2G_MASK) /**< TIM3_EGR.CC2G Field                     */
#define TIM3_EGR_CC3G_MASK                       (0x8U)                                              /**< TIM3_EGR.CC3G Mask                      */
#define TIM3_EGR_CC3G_SHIFT                      (3U)                                                /**< TIM3_EGR.CC3G Position                  */
#define TIM3_EGR_CC3G(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_EGR_CC3G_SHIFT))&TIM3_EGR_CC3G_MASK) /**< TIM3_EGR.CC3G Field                     */
#define TIM3_EGR_CC4G_MASK                       (0x10U)                                             /**< TIM3_EGR.CC4G Mask                      */
#define TIM3_EGR_CC4G_SHIFT                      (4U)                                                /**< TIM3_EGR.CC4G Position                  */
#define TIM3_EGR_CC4G(x)                         (((uint32_t)(((uint32_t)(x))<<TIM3_EGR_CC4G_SHIFT))&TIM3_EGR_CC4G_MASK) /**< TIM3_EGR.CC4G Field                     */
#define TIM3_EGR_TG_MASK                         (0x40U)                                             /**< TIM3_EGR.TG Mask                        */
#define TIM3_EGR_TG_SHIFT                        (6U)                                                /**< TIM3_EGR.TG Position                    */
#define TIM3_EGR_TG(x)                           (((uint32_t)(((uint32_t)(x))<<TIM3_EGR_TG_SHIFT))&TIM3_EGR_TG_MASK) /**< TIM3_EGR.TG Field                       */
/** @} */

/** @name CCMR1_Input - capture/compare mode register 1 (input */ /** @{ */
#define TIM3_CCMR1_Input_CC1S_MASK               (0x3U)                                              /**< TIM3_CCMR1_Input.CC1S Mask              */
#define TIM3_CCMR1_Input_CC1S_SHIFT              (0U)                                                /**< TIM3_CCMR1_Input.CC1S Position          */
#define TIM3_CCMR1_Input_CC1S(x)                 (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Input_CC1S_SHIFT))&TIM3_CCMR1_Input_CC1S_MASK) /**< TIM3_CCMR1_Input.CC1S Field             */
#define TIM3_CCMR1_Input_IC1PSC_MASK             (0xCU)                                              /**< TIM3_CCMR1_Input.IC1PSC Mask            */
#define TIM3_CCMR1_Input_IC1PSC_SHIFT            (2U)                                                /**< TIM3_CCMR1_Input.IC1PSC Position        */
#define TIM3_CCMR1_Input_IC1PSC(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Input_IC1PSC_SHIFT))&TIM3_CCMR1_Input_IC1PSC_MASK) /**< TIM3_CCMR1_Input.IC1PSC Field           */
#define TIM3_CCMR1_Input_IC1F_MASK               (0xF0U)                                             /**< TIM3_CCMR1_Input.IC1F Mask              */
#define TIM3_CCMR1_Input_IC1F_SHIFT              (4U)                                                /**< TIM3_CCMR1_Input.IC1F Position          */
#define TIM3_CCMR1_Input_IC1F(x)                 (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Input_IC1F_SHIFT))&TIM3_CCMR1_Input_IC1F_MASK) /**< TIM3_CCMR1_Input.IC1F Field             */
#define TIM3_CCMR1_Input_CC2S_MASK               (0x300U)                                            /**< TIM3_CCMR1_Input.CC2S Mask              */
#define TIM3_CCMR1_Input_CC2S_SHIFT              (8U)                                                /**< TIM3_CCMR1_Input.CC2S Position          */
#define TIM3_CCMR1_Input_CC2S(x)                 (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Input_CC2S_SHIFT))&TIM3_CCMR1_Input_CC2S_MASK) /**< TIM3_CCMR1_Input.CC2S Field             */
#define TIM3_CCMR1_Input_IC2PSC_MASK             (0xC00U)                                            /**< TIM3_CCMR1_Input.IC2PSC Mask            */
#define TIM3_CCMR1_Input_IC2PSC_SHIFT            (10U)                                               /**< TIM3_CCMR1_Input.IC2PSC Position        */
#define TIM3_CCMR1_Input_IC2PSC(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Input_IC2PSC_SHIFT))&TIM3_CCMR1_Input_IC2PSC_MASK) /**< TIM3_CCMR1_Input.IC2PSC Field           */
#define TIM3_CCMR1_Input_IC2F_MASK               (0xF000U)                                           /**< TIM3_CCMR1_Input.IC2F Mask              */
#define TIM3_CCMR1_Input_IC2F_SHIFT              (12U)                                               /**< TIM3_CCMR1_Input.IC2F Position          */
#define TIM3_CCMR1_Input_IC2F(x)                 (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Input_IC2F_SHIFT))&TIM3_CCMR1_Input_IC2F_MASK) /**< TIM3_CCMR1_Input.IC2F Field             */
/** @} */

/** @name CCMR1_Output - capture/compare mode register 1 (output */ /** @{ */
#define TIM3_CCMR1_Output_CC1S_MASK              (0x3U)                                              /**< TIM3_CCMR1_Output.CC1S Mask             */
#define TIM3_CCMR1_Output_CC1S_SHIFT             (0U)                                                /**< TIM3_CCMR1_Output.CC1S Position         */
#define TIM3_CCMR1_Output_CC1S(x)                (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_CC1S_SHIFT))&TIM3_CCMR1_Output_CC1S_MASK) /**< TIM3_CCMR1_Output.CC1S Field            */
#define TIM3_CCMR1_Output_OC1FE_MASK             (0x4U)                                              /**< TIM3_CCMR1_Output.OC1FE Mask            */
#define TIM3_CCMR1_Output_OC1FE_SHIFT            (2U)                                                /**< TIM3_CCMR1_Output.OC1FE Position        */
#define TIM3_CCMR1_Output_OC1FE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_OC1FE_SHIFT))&TIM3_CCMR1_Output_OC1FE_MASK) /**< TIM3_CCMR1_Output.OC1FE Field           */
#define TIM3_CCMR1_Output_OC1PE_MASK             (0x8U)                                              /**< TIM3_CCMR1_Output.OC1PE Mask            */
#define TIM3_CCMR1_Output_OC1PE_SHIFT            (3U)                                                /**< TIM3_CCMR1_Output.OC1PE Position        */
#define TIM3_CCMR1_Output_OC1PE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_OC1PE_SHIFT))&TIM3_CCMR1_Output_OC1PE_MASK) /**< TIM3_CCMR1_Output.OC1PE Field           */
#define TIM3_CCMR1_Output_OC1M_MASK              (0x70U)                                             /**< TIM3_CCMR1_Output.OC1M Mask             */
#define TIM3_CCMR1_Output_OC1M_SHIFT             (4U)                                                /**< TIM3_CCMR1_Output.OC1M Position         */
#define TIM3_CCMR1_Output_OC1M(x)                (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_OC1M_SHIFT))&TIM3_CCMR1_Output_OC1M_MASK) /**< TIM3_CCMR1_Output.OC1M Field            */
#define TIM3_CCMR1_Output_OC1CE_MASK             (0x80U)                                             /**< TIM3_CCMR1_Output.OC1CE Mask            */
#define TIM3_CCMR1_Output_OC1CE_SHIFT            (7U)                                                /**< TIM3_CCMR1_Output.OC1CE Position        */
#define TIM3_CCMR1_Output_OC1CE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_OC1CE_SHIFT))&TIM3_CCMR1_Output_OC1CE_MASK) /**< TIM3_CCMR1_Output.OC1CE Field           */
#define TIM3_CCMR1_Output_CC2S_MASK              (0x300U)                                            /**< TIM3_CCMR1_Output.CC2S Mask             */
#define TIM3_CCMR1_Output_CC2S_SHIFT             (8U)                                                /**< TIM3_CCMR1_Output.CC2S Position         */
#define TIM3_CCMR1_Output_CC2S(x)                (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_CC2S_SHIFT))&TIM3_CCMR1_Output_CC2S_MASK) /**< TIM3_CCMR1_Output.CC2S Field            */
#define TIM3_CCMR1_Output_OC2FE_MASK             (0x400U)                                            /**< TIM3_CCMR1_Output.OC2FE Mask            */
#define TIM3_CCMR1_Output_OC2FE_SHIFT            (10U)                                               /**< TIM3_CCMR1_Output.OC2FE Position        */
#define TIM3_CCMR1_Output_OC2FE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_OC2FE_SHIFT))&TIM3_CCMR1_Output_OC2FE_MASK) /**< TIM3_CCMR1_Output.OC2FE Field           */
#define TIM3_CCMR1_Output_OC2PE_MASK             (0x800U)                                            /**< TIM3_CCMR1_Output.OC2PE Mask            */
#define TIM3_CCMR1_Output_OC2PE_SHIFT            (11U)                                               /**< TIM3_CCMR1_Output.OC2PE Position        */
#define TIM3_CCMR1_Output_OC2PE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_OC2PE_SHIFT))&TIM3_CCMR1_Output_OC2PE_MASK) /**< TIM3_CCMR1_Output.OC2PE Field           */
#define TIM3_CCMR1_Output_OC2M_MASK              (0x7000U)                                           /**< TIM3_CCMR1_Output.OC2M Mask             */
#define TIM3_CCMR1_Output_OC2M_SHIFT             (12U)                                               /**< TIM3_CCMR1_Output.OC2M Position         */
#define TIM3_CCMR1_Output_OC2M(x)                (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_OC2M_SHIFT))&TIM3_CCMR1_Output_OC2M_MASK) /**< TIM3_CCMR1_Output.OC2M Field            */
#define TIM3_CCMR1_Output_OC2CE_MASK             (0x8000U)                                           /**< TIM3_CCMR1_Output.OC2CE Mask            */
#define TIM3_CCMR1_Output_OC2CE_SHIFT            (15U)                                               /**< TIM3_CCMR1_Output.OC2CE Position        */
#define TIM3_CCMR1_Output_OC2CE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR1_Output_OC2CE_SHIFT))&TIM3_CCMR1_Output_OC2CE_MASK) /**< TIM3_CCMR1_Output.OC2CE Field           */
/** @} */

/** @name CCMR2_Input - capture/compare mode register 2 (input */ /** @{ */
#define TIM3_CCMR2_Input_CC3S_MASK               (0x3U)                                              /**< TIM3_CCMR2_Input.CC3S Mask              */
#define TIM3_CCMR2_Input_CC3S_SHIFT              (0U)                                                /**< TIM3_CCMR2_Input.CC3S Position          */
#define TIM3_CCMR2_Input_CC3S(x)                 (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Input_CC3S_SHIFT))&TIM3_CCMR2_Input_CC3S_MASK) /**< TIM3_CCMR2_Input.CC3S Field             */
#define TIM3_CCMR2_Input_IC3PSC_MASK             (0xCU)                                              /**< TIM3_CCMR2_Input.IC3PSC Mask            */
#define TIM3_CCMR2_Input_IC3PSC_SHIFT            (2U)                                                /**< TIM3_CCMR2_Input.IC3PSC Position        */
#define TIM3_CCMR2_Input_IC3PSC(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Input_IC3PSC_SHIFT))&TIM3_CCMR2_Input_IC3PSC_MASK) /**< TIM3_CCMR2_Input.IC3PSC Field           */
#define TIM3_CCMR2_Input_IC3F_MASK               (0xF0U)                                             /**< TIM3_CCMR2_Input.IC3F Mask              */
#define TIM3_CCMR2_Input_IC3F_SHIFT              (4U)                                                /**< TIM3_CCMR2_Input.IC3F Position          */
#define TIM3_CCMR2_Input_IC3F(x)                 (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Input_IC3F_SHIFT))&TIM3_CCMR2_Input_IC3F_MASK) /**< TIM3_CCMR2_Input.IC3F Field             */
#define TIM3_CCMR2_Input_CC4S_MASK               (0x300U)                                            /**< TIM3_CCMR2_Input.CC4S Mask              */
#define TIM3_CCMR2_Input_CC4S_SHIFT              (8U)                                                /**< TIM3_CCMR2_Input.CC4S Position          */
#define TIM3_CCMR2_Input_CC4S(x)                 (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Input_CC4S_SHIFT))&TIM3_CCMR2_Input_CC4S_MASK) /**< TIM3_CCMR2_Input.CC4S Field             */
#define TIM3_CCMR2_Input_IC4PSC_MASK             (0xC00U)                                            /**< TIM3_CCMR2_Input.IC4PSC Mask            */
#define TIM3_CCMR2_Input_IC4PSC_SHIFT            (10U)                                               /**< TIM3_CCMR2_Input.IC4PSC Position        */
#define TIM3_CCMR2_Input_IC4PSC(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Input_IC4PSC_SHIFT))&TIM3_CCMR2_Input_IC4PSC_MASK) /**< TIM3_CCMR2_Input.IC4PSC Field           */
#define TIM3_CCMR2_Input_IC4F_MASK               (0xF000U)                                           /**< TIM3_CCMR2_Input.IC4F Mask              */
#define TIM3_CCMR2_Input_IC4F_SHIFT              (12U)                                               /**< TIM3_CCMR2_Input.IC4F Position          */
#define TIM3_CCMR2_Input_IC4F(x)                 (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Input_IC4F_SHIFT))&TIM3_CCMR2_Input_IC4F_MASK) /**< TIM3_CCMR2_Input.IC4F Field             */
/** @} */

/** @name CCMR2_Output - capture/compare mode register 2 (output */ /** @{ */
#define TIM3_CCMR2_Output_CC3S_MASK              (0x3U)                                              /**< TIM3_CCMR2_Output.CC3S Mask             */
#define TIM3_CCMR2_Output_CC3S_SHIFT             (0U)                                                /**< TIM3_CCMR2_Output.CC3S Position         */
#define TIM3_CCMR2_Output_CC3S(x)                (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_CC3S_SHIFT))&TIM3_CCMR2_Output_CC3S_MASK) /**< TIM3_CCMR2_Output.CC3S Field            */
#define TIM3_CCMR2_Output_OC3FE_MASK             (0x4U)                                              /**< TIM3_CCMR2_Output.OC3FE Mask            */
#define TIM3_CCMR2_Output_OC3FE_SHIFT            (2U)                                                /**< TIM3_CCMR2_Output.OC3FE Position        */
#define TIM3_CCMR2_Output_OC3FE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_OC3FE_SHIFT))&TIM3_CCMR2_Output_OC3FE_MASK) /**< TIM3_CCMR2_Output.OC3FE Field           */
#define TIM3_CCMR2_Output_OC3PE_MASK             (0x8U)                                              /**< TIM3_CCMR2_Output.OC3PE Mask            */
#define TIM3_CCMR2_Output_OC3PE_SHIFT            (3U)                                                /**< TIM3_CCMR2_Output.OC3PE Position        */
#define TIM3_CCMR2_Output_OC3PE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_OC3PE_SHIFT))&TIM3_CCMR2_Output_OC3PE_MASK) /**< TIM3_CCMR2_Output.OC3PE Field           */
#define TIM3_CCMR2_Output_OC3M_MASK              (0x70U)                                             /**< TIM3_CCMR2_Output.OC3M Mask             */
#define TIM3_CCMR2_Output_OC3M_SHIFT             (4U)                                                /**< TIM3_CCMR2_Output.OC3M Position         */
#define TIM3_CCMR2_Output_OC3M(x)                (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_OC3M_SHIFT))&TIM3_CCMR2_Output_OC3M_MASK) /**< TIM3_CCMR2_Output.OC3M Field            */
#define TIM3_CCMR2_Output_OC3CE_MASK             (0x80U)                                             /**< TIM3_CCMR2_Output.OC3CE Mask            */
#define TIM3_CCMR2_Output_OC3CE_SHIFT            (7U)                                                /**< TIM3_CCMR2_Output.OC3CE Position        */
#define TIM3_CCMR2_Output_OC3CE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_OC3CE_SHIFT))&TIM3_CCMR2_Output_OC3CE_MASK) /**< TIM3_CCMR2_Output.OC3CE Field           */
#define TIM3_CCMR2_Output_CC4S_MASK              (0x300U)                                            /**< TIM3_CCMR2_Output.CC4S Mask             */
#define TIM3_CCMR2_Output_CC4S_SHIFT             (8U)                                                /**< TIM3_CCMR2_Output.CC4S Position         */
#define TIM3_CCMR2_Output_CC4S(x)                (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_CC4S_SHIFT))&TIM3_CCMR2_Output_CC4S_MASK) /**< TIM3_CCMR2_Output.CC4S Field            */
#define TIM3_CCMR2_Output_OC4FE_MASK             (0x400U)                                            /**< TIM3_CCMR2_Output.OC4FE Mask            */
#define TIM3_CCMR2_Output_OC4FE_SHIFT            (10U)                                               /**< TIM3_CCMR2_Output.OC4FE Position        */
#define TIM3_CCMR2_Output_OC4FE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_OC4FE_SHIFT))&TIM3_CCMR2_Output_OC4FE_MASK) /**< TIM3_CCMR2_Output.OC4FE Field           */
#define TIM3_CCMR2_Output_OC4PE_MASK             (0x800U)                                            /**< TIM3_CCMR2_Output.OC4PE Mask            */
#define TIM3_CCMR2_Output_OC4PE_SHIFT            (11U)                                               /**< TIM3_CCMR2_Output.OC4PE Position        */
#define TIM3_CCMR2_Output_OC4PE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_OC4PE_SHIFT))&TIM3_CCMR2_Output_OC4PE_MASK) /**< TIM3_CCMR2_Output.OC4PE Field           */
#define TIM3_CCMR2_Output_OC4M_MASK              (0x7000U)                                           /**< TIM3_CCMR2_Output.OC4M Mask             */
#define TIM3_CCMR2_Output_OC4M_SHIFT             (12U)                                               /**< TIM3_CCMR2_Output.OC4M Position         */
#define TIM3_CCMR2_Output_OC4M(x)                (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_OC4M_SHIFT))&TIM3_CCMR2_Output_OC4M_MASK) /**< TIM3_CCMR2_Output.OC4M Field            */
#define TIM3_CCMR2_Output_OC4CE_MASK             (0x8000U)                                           /**< TIM3_CCMR2_Output.OC4CE Mask            */
#define TIM3_CCMR2_Output_OC4CE_SHIFT            (15U)                                               /**< TIM3_CCMR2_Output.OC4CE Position        */
#define TIM3_CCMR2_Output_OC4CE(x)               (((uint32_t)(((uint32_t)(x))<<TIM3_CCMR2_Output_OC4CE_SHIFT))&TIM3_CCMR2_Output_OC4CE_MASK) /**< TIM3_CCMR2_Output.OC4CE Field           */
/** @} */

/** @name CCER - capture/compare enable */ /** @{ */
#define TIM3_CCER_CC1E_MASK                      (0x1U)                                              /**< TIM3_CCER.CC1E Mask                     */
#define TIM3_CCER_CC1E_SHIFT                     (0U)                                                /**< TIM3_CCER.CC1E Position                 */
#define TIM3_CCER_CC1E(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC1E_SHIFT))&TIM3_CCER_CC1E_MASK) /**< TIM3_CCER.CC1E Field                    */
#define TIM3_CCER_CC1P_MASK                      (0x2U)                                              /**< TIM3_CCER.CC1P Mask                     */
#define TIM3_CCER_CC1P_SHIFT                     (1U)                                                /**< TIM3_CCER.CC1P Position                 */
#define TIM3_CCER_CC1P(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC1P_SHIFT))&TIM3_CCER_CC1P_MASK) /**< TIM3_CCER.CC1P Field                    */
#define TIM3_CCER_CC1NP_MASK                     (0x8U)                                              /**< TIM3_CCER.CC1NP Mask                    */
#define TIM3_CCER_CC1NP_SHIFT                    (3U)                                                /**< TIM3_CCER.CC1NP Position                */
#define TIM3_CCER_CC1NP(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC1NP_SHIFT))&TIM3_CCER_CC1NP_MASK) /**< TIM3_CCER.CC1NP Field                   */
#define TIM3_CCER_CC2E_MASK                      (0x10U)                                             /**< TIM3_CCER.CC2E Mask                     */
#define TIM3_CCER_CC2E_SHIFT                     (4U)                                                /**< TIM3_CCER.CC2E Position                 */
#define TIM3_CCER_CC2E(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC2E_SHIFT))&TIM3_CCER_CC2E_MASK) /**< TIM3_CCER.CC2E Field                    */
#define TIM3_CCER_CC2P_MASK                      (0x20U)                                             /**< TIM3_CCER.CC2P Mask                     */
#define TIM3_CCER_CC2P_SHIFT                     (5U)                                                /**< TIM3_CCER.CC2P Position                 */
#define TIM3_CCER_CC2P(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC2P_SHIFT))&TIM3_CCER_CC2P_MASK) /**< TIM3_CCER.CC2P Field                    */
#define TIM3_CCER_CC2NP_MASK                     (0x80U)                                             /**< TIM3_CCER.CC2NP Mask                    */
#define TIM3_CCER_CC2NP_SHIFT                    (7U)                                                /**< TIM3_CCER.CC2NP Position                */
#define TIM3_CCER_CC2NP(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC2NP_SHIFT))&TIM3_CCER_CC2NP_MASK) /**< TIM3_CCER.CC2NP Field                   */
#define TIM3_CCER_CC3E_MASK                      (0x100U)                                            /**< TIM3_CCER.CC3E Mask                     */
#define TIM3_CCER_CC3E_SHIFT                     (8U)                                                /**< TIM3_CCER.CC3E Position                 */
#define TIM3_CCER_CC3E(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC3E_SHIFT))&TIM3_CCER_CC3E_MASK) /**< TIM3_CCER.CC3E Field                    */
#define TIM3_CCER_CC3P_MASK                      (0x200U)                                            /**< TIM3_CCER.CC3P Mask                     */
#define TIM3_CCER_CC3P_SHIFT                     (9U)                                                /**< TIM3_CCER.CC3P Position                 */
#define TIM3_CCER_CC3P(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC3P_SHIFT))&TIM3_CCER_CC3P_MASK) /**< TIM3_CCER.CC3P Field                    */
#define TIM3_CCER_CC3NP_MASK                     (0x800U)                                            /**< TIM3_CCER.CC3NP Mask                    */
#define TIM3_CCER_CC3NP_SHIFT                    (11U)                                               /**< TIM3_CCER.CC3NP Position                */
#define TIM3_CCER_CC3NP(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC3NP_SHIFT))&TIM3_CCER_CC3NP_MASK) /**< TIM3_CCER.CC3NP Field                   */
#define TIM3_CCER_CC4E_MASK                      (0x1000U)                                           /**< TIM3_CCER.CC4E Mask                     */
#define TIM3_CCER_CC4E_SHIFT                     (12U)                                               /**< TIM3_CCER.CC4E Position                 */
#define TIM3_CCER_CC4E(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC4E_SHIFT))&TIM3_CCER_CC4E_MASK) /**< TIM3_CCER.CC4E Field                    */
#define TIM3_CCER_CC4P_MASK                      (0x2000U)                                           /**< TIM3_CCER.CC4P Mask                     */
#define TIM3_CCER_CC4P_SHIFT                     (13U)                                               /**< TIM3_CCER.CC4P Position                 */
#define TIM3_CCER_CC4P(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC4P_SHIFT))&TIM3_CCER_CC4P_MASK) /**< TIM3_CCER.CC4P Field                    */
#define TIM3_CCER_CC4NP_MASK                     (0x8000U)                                           /**< TIM3_CCER.CC4NP Mask                    */
#define TIM3_CCER_CC4NP_SHIFT                    (15U)                                               /**< TIM3_CCER.CC4NP Position                */
#define TIM3_CCER_CC4NP(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_CCER_CC4NP_SHIFT))&TIM3_CCER_CC4NP_MASK) /**< TIM3_CCER.CC4NP Field                   */
/** @} */

/** @name CNT - counter */ /** @{ */
#define TIM3_CNT_CNT_L_MASK                      (0xFFFFU)                                           /**< TIM3_CNT.CNT_L Mask                     */
#define TIM3_CNT_CNT_L_SHIFT                     (0U)                                                /**< TIM3_CNT.CNT_L Position                 */
#define TIM3_CNT_CNT_L(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CNT_CNT_L_SHIFT))&TIM3_CNT_CNT_L_MASK) /**< TIM3_CNT.CNT_L Field                    */
#define TIM3_CNT_CNT_H_MASK                      (0xFFFF0000U)                                       /**< TIM3_CNT.CNT_H Mask                     */
#define TIM3_CNT_CNT_H_SHIFT                     (16U)                                               /**< TIM3_CNT.CNT_H Position                 */
#define TIM3_CNT_CNT_H(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_CNT_CNT_H_SHIFT))&TIM3_CNT_CNT_H_MASK) /**< TIM3_CNT.CNT_H Field                    */
/** @} */

/** @name PSC - prescaler */ /** @{ */
#define TIM3_PSC_PSC_MASK                        (0xFFFFU)                                           /**< TIM3_PSC.PSC Mask                       */
#define TIM3_PSC_PSC_SHIFT                       (0U)                                                /**< TIM3_PSC.PSC Position                   */
#define TIM3_PSC_PSC(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_PSC_PSC_SHIFT))&TIM3_PSC_PSC_MASK) /**< TIM3_PSC.PSC Field                      */
/** @} */

/** @name ARR - auto-reload register */ /** @{ */
#define TIM3_ARR_ARR_L_MASK                      (0xFFFFU)                                           /**< TIM3_ARR.ARR_L Mask                     */
#define TIM3_ARR_ARR_L_SHIFT                     (0U)                                                /**< TIM3_ARR.ARR_L Position                 */
#define TIM3_ARR_ARR_L(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_ARR_ARR_L_SHIFT))&TIM3_ARR_ARR_L_MASK) /**< TIM3_ARR.ARR_L Field                    */
#define TIM3_ARR_ARR_H_MASK                      (0xFFFF0000U)                                       /**< TIM3_ARR.ARR_H Mask                     */
#define TIM3_ARR_ARR_H_SHIFT                     (16U)                                               /**< TIM3_ARR.ARR_H Position                 */
#define TIM3_ARR_ARR_H(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_ARR_ARR_H_SHIFT))&TIM3_ARR_ARR_H_MASK) /**< TIM3_ARR.ARR_H Field                    */
/** @} */

/** @name CCR - capture/compare register %s */ /** @{ */
#define TIM3_CCR_CCR1_L_MASK                     (0xFFFFU)                                           /**< TIM3_CCR.CCR1_L Mask                    */
#define TIM3_CCR_CCR1_L_SHIFT                    (0U)                                                /**< TIM3_CCR.CCR1_L Position                */
#define TIM3_CCR_CCR1_L(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_CCR_CCR1_L_SHIFT))&TIM3_CCR_CCR1_L_MASK) /**< TIM3_CCR.CCR1_L Field                   */
#define TIM3_CCR_CCR1_H_MASK                     (0xFFFF0000U)                                       /**< TIM3_CCR.CCR1_H Mask                    */
#define TIM3_CCR_CCR1_H_SHIFT                    (16U)                                               /**< TIM3_CCR.CCR1_H Position                */
#define TIM3_CCR_CCR1_H(x)                       (((uint32_t)(((uint32_t)(x))<<TIM3_CCR_CCR1_H_SHIFT))&TIM3_CCR_CCR1_H_MASK) /**< TIM3_CCR.CCR1_H Field                   */
/** @} */

/** @name DCR - DMA control register */ /** @{ */
#define TIM3_DCR_DBA_MASK                        (0x1FU)                                             /**< TIM3_DCR.DBA Mask                       */
#define TIM3_DCR_DBA_SHIFT                       (0U)                                                /**< TIM3_DCR.DBA Position                   */
#define TIM3_DCR_DBA(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_DCR_DBA_SHIFT))&TIM3_DCR_DBA_MASK) /**< TIM3_DCR.DBA Field                      */
#define TIM3_DCR_DBL_MASK                        (0x1F00U)                                           /**< TIM3_DCR.DBL Mask                       */
#define TIM3_DCR_DBL_SHIFT                       (8U)                                                /**< TIM3_DCR.DBL Position                   */
#define TIM3_DCR_DBL(x)                          (((uint32_t)(((uint32_t)(x))<<TIM3_DCR_DBL_SHIFT))&TIM3_DCR_DBL_MASK) /**< TIM3_DCR.DBL Field                      */
/** @} */

/** @name DMAR - DMA address for full transfer */ /** @{ */
#define TIM3_DMAR_DMAR_MASK                      (0xFFFFU)                                           /**< TIM3_DMAR.DMAR Mask                     */
#define TIM3_DMAR_DMAR_SHIFT                     (0U)                                                /**< TIM3_DMAR.DMAR Position                 */
#define TIM3_DMAR_DMAR(x)                        (((uint32_t)(((uint32_t)(x))<<TIM3_DMAR_DMAR_SHIFT))&TIM3_DMAR_DMAR_MASK) /**< TIM3_DMAR.DMAR Field                    */
/** @} */

/** @} */ /* End group TIM_Register_Masks_GROUP */


/* TIM3 - Peripheral instance base addresses */
#define TIM3_BasePtr                   0x40000400UL //!< Peripheral base address
#define TIM3                           ((TIM3_Type *) TIM3_BasePtr) //!< Freescale base pointer
#define TIM3_BASE_PTR                  (TIM3) //!< Freescale style base pointer
#define TIM3_IRQS { TIM1_BRK_UP_TRG_COM_IRQn, TIM1_CC_IRQn,  }


/** @} */ /* End group TIM_Peripheral_access_layer_GROUP */


/** @brief C Struct for TIM */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup TIM_Peripheral_access_layer_GROUP TIM Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           TIM6 (file:TIM6_STM32F030)           ================ */
/* ================================================================================ */

/**
 * @brief Basic-timers
 */
/**
 * @struct TIM6_Type
 * @brief  C Struct allowing access to TIM registers
 */
typedef struct TIM6_Type {
   __IO uint32_t  CR1;                          /**< 0000: control register 1                                           */
   __IO uint32_t  CR2;                          /**< 0004: control register 2                                           */
        uint8_t   RESERVED_0[4];                /**< 0008: 0x4 bytes                                                    */
   __IO uint32_t  DIER;                         /**< 000C: DMA/Interrupt enable register                                */
   __IO uint32_t  SR;                           /**< 0010: status register                                              */
   __O  uint32_t  EGR;                          /**< 0014: event generation register                                    */
        uint8_t   RESERVED_1[12];               /**< 0018: 0xC bytes                                                    */
   __IO uint32_t  CNT;                          /**< 0024: counter                                                      */
   __IO uint32_t  PSC;                          /**< 0028: prescaler                                                    */
   __IO uint32_t  ARR;                          /**< 002C: auto-reload register                                         */
} TIM6_Type;


/** @brief Register Masks for TIM */

/* -------------------------------------------------------------------------------- */
/* -----------     'TIM6' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup TIM_Register_Masks_GROUP TIM Register Masks */
/** @{ */

/** @name CR1 - control register 1 */ /** @{ */
#define TIM6_CR1_CEN_MASK                        (0x1U)                                              /**< TIM6_CR1.CEN Mask                       */
#define TIM6_CR1_CEN_SHIFT                       (0U)                                                /**< TIM6_CR1.CEN Position                   */
#define TIM6_CR1_CEN(x)                          (((uint32_t)(((uint32_t)(x))<<TIM6_CR1_CEN_SHIFT))&TIM6_CR1_CEN_MASK) /**< TIM6_CR1.CEN Field                      */
#define TIM6_CR1_UDIS_MASK                       (0x2U)                                              /**< TIM6_CR1.UDIS Mask                      */
#define TIM6_CR1_UDIS_SHIFT                      (1U)                                                /**< TIM6_CR1.UDIS Position                  */
#define TIM6_CR1_UDIS(x)                         (((uint32_t)(((uint32_t)(x))<<TIM6_CR1_UDIS_SHIFT))&TIM6_CR1_UDIS_MASK) /**< TIM6_CR1.UDIS Field                     */
#define TIM6_CR1_URS_MASK                        (0x4U)                                              /**< TIM6_CR1.URS Mask                       */
#define TIM6_CR1_URS_SHIFT                       (2U)                                                /**< TIM6_CR1.URS Position                   */
#define TIM6_CR1_URS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM6_CR1_URS_SHIFT))&TIM6_CR1_URS_MASK) /**< TIM6_CR1.URS Field                      */
#define TIM6_CR1_OPM_MASK                        (0x8U)                                              /**< TIM6_CR1.OPM Mask                       */
#define TIM6_CR1_OPM_SHIFT                       (3U)                                                /**< TIM6_CR1.OPM Position                   */
#define TIM6_CR1_OPM(x)                          (((uint32_t)(((uint32_t)(x))<<TIM6_CR1_OPM_SHIFT))&TIM6_CR1_OPM_MASK) /**< TIM6_CR1.OPM Field                      */
#define TIM6_CR1_ARPE_MASK                       (0x80U)                                             /**< TIM6_CR1.ARPE Mask                      */
#define TIM6_CR1_ARPE_SHIFT                      (7U)                                                /**< TIM6_CR1.ARPE Position                  */
#define TIM6_CR1_ARPE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM6_CR1_ARPE_SHIFT))&TIM6_CR1_ARPE_MASK) /**< TIM6_CR1.ARPE Field                     */
/** @} */

/** @name CR2 - control register 2 */ /** @{ */
#define TIM6_CR2_MMS_MASK                        (0x70U)                                             /**< TIM6_CR2.MMS Mask                       */
#define TIM6_CR2_MMS_SHIFT                       (4U)                                                /**< TIM6_CR2.MMS Position                   */
#define TIM6_CR2_MMS(x)                          (((uint32_t)(((uint32_t)(x))<<TIM6_CR2_MMS_SHIFT))&TIM6_CR2_MMS_MASK) /**< TIM6_CR2.MMS Field                      */
/** @} */

/** @name DIER - DMA/Interrupt enable register */ /** @{ */
#define TIM6_DIER_UIE_MASK                       (0x1U)                                              /**< TIM6_DIER.UIE Mask                      */
#define TIM6_DIER_UIE_SHIFT                      (0U)                                                /**< TIM6_DIER.UIE Position                  */
#define TIM6_DIER_UIE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM6_DIER_UIE_SHIFT))&TIM6_DIER_UIE_MASK) /**< TIM6_DIER.UIE Field                     */
#define TIM6_DIER_UDE_MASK                       (0x100U)                                            /**< TIM6_DIER.UDE Mask                      */
#define TIM6_DIER_UDE_SHIFT                      (8U)                                                /**< TIM6_DIER.UDE Position                  */
#define TIM6_DIER_UDE(x)                         (((uint32_t)(((uint32_t)(x))<<TIM6_DIER_UDE_SHIFT))&TIM6_DIER_UDE_MASK) /**< TIM6_DIER.UDE Field                     */
/** @} */

/** @name SR - status register */ /** @{ */
#define TIM6_SR_UIF_MASK                         (0x1U)                                              /**< TIM6_SR.UIF Mask                        */
#define TIM6_SR_UIF_SHIFT                        (0U)                                                /**< TIM6_SR.UIF Position                    */
#define TIM6_SR_UIF(x)                           (((uint32_t)(((uint32_t)(x))<<TIM6_SR_UIF_SHIFT))&TIM6_SR_UIF_MASK) /**< TIM6_SR.UIF Field                       */
/** @} */

/** @name EGR - event generation register */ /** @{ */
#define TIM6_EGR_UG_MASK                         (0x1U)                                              /**< TIM6_EGR.UG Mask                        */
#define TIM6_EGR_UG_SHIFT                        (0U)                                                /**< TIM6_EGR.UG Position                    */
#define TIM6_EGR_UG(x)                           (((uint32_t)(((uint32_t)(x))<<TIM6_EGR_UG_SHIFT))&TIM6_EGR_UG_MASK) /**< TIM6_EGR.UG Field                       */
/** @} */

/** @name CNT - counter */ /** @{ */
#define TIM6_CNT_CNT_MASK                        (0xFFFFU)                                           /**< TIM6_CNT.CNT Mask                       */
#define TIM6_CNT_CNT_SHIFT                       (0U)                                                /**< TIM6_CNT.CNT Position                   */
#define TIM6_CNT_CNT(x)                          (((uint32_t)(((uint32_t)(x))<<TIM6_CNT_CNT_SHIFT))&TIM6_CNT_CNT_MASK) /**< TIM6_CNT.CNT Field                      */
/** @} */

/** @name PSC - prescaler */ /** @{ */
#define TIM6_PSC_PSC_MASK                        (0xFFFFU)                                           /**< TIM6_PSC.PSC Mask                       */
#define TIM6_PSC_PSC_SHIFT                       (0U)                                                /**< TIM6_PSC.PSC Position                   */
#define TIM6_PSC_PSC(x)                          (((uint32_t)(((uint32_t)(x))<<TIM6_PSC_PSC_SHIFT))&TIM6_PSC_PSC_MASK) /**< TIM6_PSC.PSC Field                      */
/** @} */

/** @name ARR - auto-reload register */ /** @{ */
#define TIM6_ARR_ARR_MASK                        (0xFFFFU)                                           /**< TIM6_ARR.ARR Mask                       */
#define TIM6_ARR_ARR_SHIFT                       (0U)                                                /**< TIM6_ARR.ARR Position                   */
#define TIM6_ARR_ARR(x)                          (((uint32_t)(((uint32_t)(x))<<TIM6_ARR_ARR_SHIFT))&TIM6_ARR_ARR_MASK) /**< TIM6_ARR.ARR Field                      */
/** @} */

/** @} */ /* End group TIM_Register_Masks_GROUP */


/* TIM6 - Peripheral instance base addresses */
#define TIM6_BasePtr                   0x40001000UL //!< Peripheral base address
#define TIM6                           ((TIM6_Type *) TIM6_BasePtr) //!< Freescale base pointer
#define TIM6_BASE_PTR                  (TIM6) //!< Freescale style base pointer
#define TIM6_IRQS { TIM3_IRQn,  }


/** @} */ /* End group TIM_Peripheral_access_layer_GROUP */


/** @brief C Struct for USART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup USART_Peripheral_access_layer_GROUP USART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           USART1 (file:USART1_STM32F030)       ================ */
/* ================================================================================ */

/**
 * @brief Universal synchronous asynchronous receiver
transmitter
 */
/**
 * @struct USART1_Type
 * @brief  C Struct allowing access to USART registers
 */
typedef struct USART1_Type {
   __IO uint32_t  CR1;                          /**< 0000: Control register 1                                           */
   __IO uint32_t  CR2;                          /**< 0004: Control register 2                                           */
   __IO uint32_t  CR3;                          /**< 0008: Control register 3                                           */
   __IO uint32_t  BRR;                          /**< 000C: Baud rate register                                           */
   __IO uint32_t  GTPR;                         /**< 0010: Guard time and prescaler                                     */
   __IO uint32_t  RTOR;                         /**< 0014: Receiver timeout register                                    */
   __IO uint32_t  RQR;                          /**< 0018: Request register                                             */
   __I  uint32_t  ISR;                          /**< 001C: Interrupt & status                                           */
   __IO uint32_t  ICR;                          /**< 0020: Interrupt flag clear register                                */
   __I  uint32_t  RDR;                          /**< 0024: Receive data register                                        */
   __IO uint32_t  TDR;                          /**< 0028: Transmit data register                                       */
} USART1_Type;


/** @brief Register Masks for USART */

/* -------------------------------------------------------------------------------- */
/* -----------     'USART1' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup USART_Register_Masks_GROUP USART Register Masks */
/** @{ */

/** @name CR1 - Control register 1 */ /** @{ */
#define USART1_CR1_UE_MASK                       (0x1U)                                              /**< USART1_CR1.UE Mask                      */
#define USART1_CR1_UE_SHIFT                      (0U)                                                /**< USART1_CR1.UE Position                  */
#define USART1_CR1_UE(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_CR1_UE_SHIFT))&USART1_CR1_UE_MASK) /**< USART1_CR1.UE Field                     */
#define USART1_CR1_UESM_MASK                     (0x2U)                                              /**< USART1_CR1.UESM Mask                    */
#define USART1_CR1_UESM_SHIFT                    (1U)                                                /**< USART1_CR1.UESM Position                */
#define USART1_CR1_UESM(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR1_UESM_SHIFT))&USART1_CR1_UESM_MASK) /**< USART1_CR1.UESM Field                   */
#define USART1_CR1_RE_MASK                       (0x4U)                                              /**< USART1_CR1.RE Mask                      */
#define USART1_CR1_RE_SHIFT                      (2U)                                                /**< USART1_CR1.RE Position                  */
#define USART1_CR1_RE(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_CR1_RE_SHIFT))&USART1_CR1_RE_MASK) /**< USART1_CR1.RE Field                     */
#define USART1_CR1_TE_MASK                       (0x8U)                                              /**< USART1_CR1.TE Mask                      */
#define USART1_CR1_TE_SHIFT                      (3U)                                                /**< USART1_CR1.TE Position                  */
#define USART1_CR1_TE(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_CR1_TE_SHIFT))&USART1_CR1_TE_MASK) /**< USART1_CR1.TE Field                     */
#define USART1_CR1_IDLEIE_MASK                   (0x10U)                                             /**< USART1_CR1.IDLEIE Mask                  */
#define USART1_CR1_IDLEIE_SHIFT                  (4U)                                                /**< USART1_CR1.IDLEIE Position              */
#define USART1_CR1_IDLEIE(x)                     (((uint32_t)(((uint32_t)(x))<<USART1_CR1_IDLEIE_SHIFT))&USART1_CR1_IDLEIE_MASK) /**< USART1_CR1.IDLEIE Field                 */
#define USART1_CR1_RXNEIE_MASK                   (0x20U)                                             /**< USART1_CR1.RXNEIE Mask                  */
#define USART1_CR1_RXNEIE_SHIFT                  (5U)                                                /**< USART1_CR1.RXNEIE Position              */
#define USART1_CR1_RXNEIE(x)                     (((uint32_t)(((uint32_t)(x))<<USART1_CR1_RXNEIE_SHIFT))&USART1_CR1_RXNEIE_MASK) /**< USART1_CR1.RXNEIE Field                 */
#define USART1_CR1_TCIE_MASK                     (0x40U)                                             /**< USART1_CR1.TCIE Mask                    */
#define USART1_CR1_TCIE_SHIFT                    (6U)                                                /**< USART1_CR1.TCIE Position                */
#define USART1_CR1_TCIE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR1_TCIE_SHIFT))&USART1_CR1_TCIE_MASK) /**< USART1_CR1.TCIE Field                   */
#define USART1_CR1_TXEIE_MASK                    (0x80U)                                             /**< USART1_CR1.TXEIE Mask                   */
#define USART1_CR1_TXEIE_SHIFT                   (7U)                                                /**< USART1_CR1.TXEIE Position               */
#define USART1_CR1_TXEIE(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR1_TXEIE_SHIFT))&USART1_CR1_TXEIE_MASK) /**< USART1_CR1.TXEIE Field                  */
#define USART1_CR1_PEIE_MASK                     (0x100U)                                            /**< USART1_CR1.PEIE Mask                    */
#define USART1_CR1_PEIE_SHIFT                    (8U)                                                /**< USART1_CR1.PEIE Position                */
#define USART1_CR1_PEIE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR1_PEIE_SHIFT))&USART1_CR1_PEIE_MASK) /**< USART1_CR1.PEIE Field                   */
#define USART1_CR1_PS_MASK                       (0x200U)                                            /**< USART1_CR1.PS Mask                      */
#define USART1_CR1_PS_SHIFT                      (9U)                                                /**< USART1_CR1.PS Position                  */
#define USART1_CR1_PS(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_CR1_PS_SHIFT))&USART1_CR1_PS_MASK) /**< USART1_CR1.PS Field                     */
#define USART1_CR1_PCE_MASK                      (0x400U)                                            /**< USART1_CR1.PCE Mask                     */
#define USART1_CR1_PCE_SHIFT                     (10U)                                               /**< USART1_CR1.PCE Position                 */
#define USART1_CR1_PCE(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_CR1_PCE_SHIFT))&USART1_CR1_PCE_MASK) /**< USART1_CR1.PCE Field                    */
#define USART1_CR1_WAKE_MASK                     (0x800U)                                            /**< USART1_CR1.WAKE Mask                    */
#define USART1_CR1_WAKE_SHIFT                    (11U)                                               /**< USART1_CR1.WAKE Position                */
#define USART1_CR1_WAKE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR1_WAKE_SHIFT))&USART1_CR1_WAKE_MASK) /**< USART1_CR1.WAKE Field                   */
#define USART1_CR1_M_MASK                        (0x1000U)                                           /**< USART1_CR1.M Mask                       */
#define USART1_CR1_M_SHIFT                       (12U)                                               /**< USART1_CR1.M Position                   */
#define USART1_CR1_M(x)                          (((uint32_t)(((uint32_t)(x))<<USART1_CR1_M_SHIFT))&USART1_CR1_M_MASK) /**< USART1_CR1.M Field                      */
#define USART1_CR1_MME_MASK                      (0x2000U)                                           /**< USART1_CR1.MME Mask                     */
#define USART1_CR1_MME_SHIFT                     (13U)                                               /**< USART1_CR1.MME Position                 */
#define USART1_CR1_MME(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_CR1_MME_SHIFT))&USART1_CR1_MME_MASK) /**< USART1_CR1.MME Field                    */
#define USART1_CR1_CMIE_MASK                     (0x4000U)                                           /**< USART1_CR1.CMIE Mask                    */
#define USART1_CR1_CMIE_SHIFT                    (14U)                                               /**< USART1_CR1.CMIE Position                */
#define USART1_CR1_CMIE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR1_CMIE_SHIFT))&USART1_CR1_CMIE_MASK) /**< USART1_CR1.CMIE Field                   */
#define USART1_CR1_OVER8_MASK                    (0x8000U)                                           /**< USART1_CR1.OVER8 Mask                   */
#define USART1_CR1_OVER8_SHIFT                   (15U)                                               /**< USART1_CR1.OVER8 Position               */
#define USART1_CR1_OVER8(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR1_OVER8_SHIFT))&USART1_CR1_OVER8_MASK) /**< USART1_CR1.OVER8 Field                  */
#define USART1_CR1_DEDT_MASK                     (0x1F0000U)                                         /**< USART1_CR1.DEDT Mask                    */
#define USART1_CR1_DEDT_SHIFT                    (16U)                                               /**< USART1_CR1.DEDT Position                */
#define USART1_CR1_DEDT(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR1_DEDT_SHIFT))&USART1_CR1_DEDT_MASK) /**< USART1_CR1.DEDT Field                   */
#define USART1_CR1_DEAT_MASK                     (0x3E00000U)                                        /**< USART1_CR1.DEAT Mask                    */
#define USART1_CR1_DEAT_SHIFT                    (21U)                                               /**< USART1_CR1.DEAT Position                */
#define USART1_CR1_DEAT(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR1_DEAT_SHIFT))&USART1_CR1_DEAT_MASK) /**< USART1_CR1.DEAT Field                   */
#define USART1_CR1_RTOIE_MASK                    (0x4000000U)                                        /**< USART1_CR1.RTOIE Mask                   */
#define USART1_CR1_RTOIE_SHIFT                   (26U)                                               /**< USART1_CR1.RTOIE Position               */
#define USART1_CR1_RTOIE(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR1_RTOIE_SHIFT))&USART1_CR1_RTOIE_MASK) /**< USART1_CR1.RTOIE Field                  */
#define USART1_CR1_EOBIE_MASK                    (0x8000000U)                                        /**< USART1_CR1.EOBIE Mask                   */
#define USART1_CR1_EOBIE_SHIFT                   (27U)                                               /**< USART1_CR1.EOBIE Position               */
#define USART1_CR1_EOBIE(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR1_EOBIE_SHIFT))&USART1_CR1_EOBIE_MASK) /**< USART1_CR1.EOBIE Field                  */
#define USART1_CR1_M1_MASK                       (0x10000000U)                                       /**< USART1_CR1.M1 Mask                      */
#define USART1_CR1_M1_SHIFT                      (28U)                                               /**< USART1_CR1.M1 Position                  */
#define USART1_CR1_M1(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_CR1_M1_SHIFT))&USART1_CR1_M1_MASK) /**< USART1_CR1.M1 Field                     */
/** @} */

/** @name CR2 - Control register 2 */ /** @{ */
#define USART1_CR2_ADDM7_MASK                    (0x10U)                                             /**< USART1_CR2.ADDM7 Mask                   */
#define USART1_CR2_ADDM7_SHIFT                   (4U)                                                /**< USART1_CR2.ADDM7 Position               */
#define USART1_CR2_ADDM7(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR2_ADDM7_SHIFT))&USART1_CR2_ADDM7_MASK) /**< USART1_CR2.ADDM7 Field                  */
#define USART1_CR2_LBDL_MASK                     (0x20U)                                             /**< USART1_CR2.LBDL Mask                    */
#define USART1_CR2_LBDL_SHIFT                    (5U)                                                /**< USART1_CR2.LBDL Position                */
#define USART1_CR2_LBDL(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR2_LBDL_SHIFT))&USART1_CR2_LBDL_MASK) /**< USART1_CR2.LBDL Field                   */
#define USART1_CR2_LBDIE_MASK                    (0x40U)                                             /**< USART1_CR2.LBDIE Mask                   */
#define USART1_CR2_LBDIE_SHIFT                   (6U)                                                /**< USART1_CR2.LBDIE Position               */
#define USART1_CR2_LBDIE(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR2_LBDIE_SHIFT))&USART1_CR2_LBDIE_MASK) /**< USART1_CR2.LBDIE Field                  */
#define USART1_CR2_LBCL_MASK                     (0x100U)                                            /**< USART1_CR2.LBCL Mask                    */
#define USART1_CR2_LBCL_SHIFT                    (8U)                                                /**< USART1_CR2.LBCL Position                */
#define USART1_CR2_LBCL(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR2_LBCL_SHIFT))&USART1_CR2_LBCL_MASK) /**< USART1_CR2.LBCL Field                   */
#define USART1_CR2_CPHA_MASK                     (0x200U)                                            /**< USART1_CR2.CPHA Mask                    */
#define USART1_CR2_CPHA_SHIFT                    (9U)                                                /**< USART1_CR2.CPHA Position                */
#define USART1_CR2_CPHA(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR2_CPHA_SHIFT))&USART1_CR2_CPHA_MASK) /**< USART1_CR2.CPHA Field                   */
#define USART1_CR2_CPOL_MASK                     (0x400U)                                            /**< USART1_CR2.CPOL Mask                    */
#define USART1_CR2_CPOL_SHIFT                    (10U)                                               /**< USART1_CR2.CPOL Position                */
#define USART1_CR2_CPOL(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR2_CPOL_SHIFT))&USART1_CR2_CPOL_MASK) /**< USART1_CR2.CPOL Field                   */
#define USART1_CR2_CLKEN_MASK                    (0x800U)                                            /**< USART1_CR2.CLKEN Mask                   */
#define USART1_CR2_CLKEN_SHIFT                   (11U)                                               /**< USART1_CR2.CLKEN Position               */
#define USART1_CR2_CLKEN(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR2_CLKEN_SHIFT))&USART1_CR2_CLKEN_MASK) /**< USART1_CR2.CLKEN Field                  */
#define USART1_CR2_STOP_MASK                     (0x3000U)                                           /**< USART1_CR2.STOP Mask                    */
#define USART1_CR2_STOP_SHIFT                    (12U)                                               /**< USART1_CR2.STOP Position                */
#define USART1_CR2_STOP(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR2_STOP_SHIFT))&USART1_CR2_STOP_MASK) /**< USART1_CR2.STOP Field                   */
#define USART1_CR2_LINEN_MASK                    (0x4000U)                                           /**< USART1_CR2.LINEN Mask                   */
#define USART1_CR2_LINEN_SHIFT                   (14U)                                               /**< USART1_CR2.LINEN Position               */
#define USART1_CR2_LINEN(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR2_LINEN_SHIFT))&USART1_CR2_LINEN_MASK) /**< USART1_CR2.LINEN Field                  */
#define USART1_CR2_SWAP_MASK                     (0x8000U)                                           /**< USART1_CR2.SWAP Mask                    */
#define USART1_CR2_SWAP_SHIFT                    (15U)                                               /**< USART1_CR2.SWAP Position                */
#define USART1_CR2_SWAP(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR2_SWAP_SHIFT))&USART1_CR2_SWAP_MASK) /**< USART1_CR2.SWAP Field                   */
#define USART1_CR2_RXINV_MASK                    (0x10000U)                                          /**< USART1_CR2.RXINV Mask                   */
#define USART1_CR2_RXINV_SHIFT                   (16U)                                               /**< USART1_CR2.RXINV Position               */
#define USART1_CR2_RXINV(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR2_RXINV_SHIFT))&USART1_CR2_RXINV_MASK) /**< USART1_CR2.RXINV Field                  */
#define USART1_CR2_TXINV_MASK                    (0x20000U)                                          /**< USART1_CR2.TXINV Mask                   */
#define USART1_CR2_TXINV_SHIFT                   (17U)                                               /**< USART1_CR2.TXINV Position               */
#define USART1_CR2_TXINV(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR2_TXINV_SHIFT))&USART1_CR2_TXINV_MASK) /**< USART1_CR2.TXINV Field                  */
#define USART1_CR2_DATAINV_MASK                  (0x40000U)                                          /**< USART1_CR2.DATAINV Mask                 */
#define USART1_CR2_DATAINV_SHIFT                 (18U)                                               /**< USART1_CR2.DATAINV Position             */
#define USART1_CR2_DATAINV(x)                    (((uint32_t)(((uint32_t)(x))<<USART1_CR2_DATAINV_SHIFT))&USART1_CR2_DATAINV_MASK) /**< USART1_CR2.DATAINV Field                */
#define USART1_CR2_MSBFIRST_MASK                 (0x80000U)                                          /**< USART1_CR2.MSBFIRST Mask                */
#define USART1_CR2_MSBFIRST_SHIFT                (19U)                                               /**< USART1_CR2.MSBFIRST Position            */
#define USART1_CR2_MSBFIRST(x)                   (((uint32_t)(((uint32_t)(x))<<USART1_CR2_MSBFIRST_SHIFT))&USART1_CR2_MSBFIRST_MASK) /**< USART1_CR2.MSBFIRST Field               */
#define USART1_CR2_ABREN_MASK                    (0x100000U)                                         /**< USART1_CR2.ABREN Mask                   */
#define USART1_CR2_ABREN_SHIFT                   (20U)                                               /**< USART1_CR2.ABREN Position               */
#define USART1_CR2_ABREN(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR2_ABREN_SHIFT))&USART1_CR2_ABREN_MASK) /**< USART1_CR2.ABREN Field                  */
#define USART1_CR2_ABRMOD_MASK                   (0x600000U)                                         /**< USART1_CR2.ABRMOD Mask                  */
#define USART1_CR2_ABRMOD_SHIFT                  (21U)                                               /**< USART1_CR2.ABRMOD Position              */
#define USART1_CR2_ABRMOD(x)                     (((uint32_t)(((uint32_t)(x))<<USART1_CR2_ABRMOD_SHIFT))&USART1_CR2_ABRMOD_MASK) /**< USART1_CR2.ABRMOD Field                 */
#define USART1_CR2_RTOEN_MASK                    (0x800000U)                                         /**< USART1_CR2.RTOEN Mask                   */
#define USART1_CR2_RTOEN_SHIFT                   (23U)                                               /**< USART1_CR2.RTOEN Position               */
#define USART1_CR2_RTOEN(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR2_RTOEN_SHIFT))&USART1_CR2_RTOEN_MASK) /**< USART1_CR2.RTOEN Field                  */
#define USART1_CR2_ADD0_MASK                     (0xF000000U)                                        /**< USART1_CR2.ADD0 Mask                    */
#define USART1_CR2_ADD0_SHIFT                    (24U)                                               /**< USART1_CR2.ADD0 Position                */
#define USART1_CR2_ADD0(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR2_ADD0_SHIFT))&USART1_CR2_ADD0_MASK) /**< USART1_CR2.ADD0 Field                   */
#define USART1_CR2_ADD4_MASK                     (0xF0000000U)                                       /**< USART1_CR2.ADD4 Mask                    */
#define USART1_CR2_ADD4_SHIFT                    (28U)                                               /**< USART1_CR2.ADD4 Position                */
#define USART1_CR2_ADD4(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR2_ADD4_SHIFT))&USART1_CR2_ADD4_MASK) /**< USART1_CR2.ADD4 Field                   */
/** @} */

/** @name CR3 - Control register 3 */ /** @{ */
#define USART1_CR3_EIE_MASK                      (0x1U)                                              /**< USART1_CR3.EIE Mask                     */
#define USART1_CR3_EIE_SHIFT                     (0U)                                                /**< USART1_CR3.EIE Position                 */
#define USART1_CR3_EIE(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_CR3_EIE_SHIFT))&USART1_CR3_EIE_MASK) /**< USART1_CR3.EIE Field                    */
#define USART1_CR3_IREN_MASK                     (0x2U)                                              /**< USART1_CR3.IREN Mask                    */
#define USART1_CR3_IREN_SHIFT                    (1U)                                                /**< USART1_CR3.IREN Position                */
#define USART1_CR3_IREN(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_IREN_SHIFT))&USART1_CR3_IREN_MASK) /**< USART1_CR3.IREN Field                   */
#define USART1_CR3_IRLP_MASK                     (0x4U)                                              /**< USART1_CR3.IRLP Mask                    */
#define USART1_CR3_IRLP_SHIFT                    (2U)                                                /**< USART1_CR3.IRLP Position                */
#define USART1_CR3_IRLP(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_IRLP_SHIFT))&USART1_CR3_IRLP_MASK) /**< USART1_CR3.IRLP Field                   */
#define USART1_CR3_HDSEL_MASK                    (0x8U)                                              /**< USART1_CR3.HDSEL Mask                   */
#define USART1_CR3_HDSEL_SHIFT                   (3U)                                                /**< USART1_CR3.HDSEL Position               */
#define USART1_CR3_HDSEL(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR3_HDSEL_SHIFT))&USART1_CR3_HDSEL_MASK) /**< USART1_CR3.HDSEL Field                  */
#define USART1_CR3_NACK_MASK                     (0x10U)                                             /**< USART1_CR3.NACK Mask                    */
#define USART1_CR3_NACK_SHIFT                    (4U)                                                /**< USART1_CR3.NACK Position                */
#define USART1_CR3_NACK(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_NACK_SHIFT))&USART1_CR3_NACK_MASK) /**< USART1_CR3.NACK Field                   */
#define USART1_CR3_SCEN_MASK                     (0x20U)                                             /**< USART1_CR3.SCEN Mask                    */
#define USART1_CR3_SCEN_SHIFT                    (5U)                                                /**< USART1_CR3.SCEN Position                */
#define USART1_CR3_SCEN(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_SCEN_SHIFT))&USART1_CR3_SCEN_MASK) /**< USART1_CR3.SCEN Field                   */
#define USART1_CR3_DMAR_MASK                     (0x40U)                                             /**< USART1_CR3.DMAR Mask                    */
#define USART1_CR3_DMAR_SHIFT                    (6U)                                                /**< USART1_CR3.DMAR Position                */
#define USART1_CR3_DMAR(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_DMAR_SHIFT))&USART1_CR3_DMAR_MASK) /**< USART1_CR3.DMAR Field                   */
#define USART1_CR3_DMAT_MASK                     (0x80U)                                             /**< USART1_CR3.DMAT Mask                    */
#define USART1_CR3_DMAT_SHIFT                    (7U)                                                /**< USART1_CR3.DMAT Position                */
#define USART1_CR3_DMAT(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_DMAT_SHIFT))&USART1_CR3_DMAT_MASK) /**< USART1_CR3.DMAT Field                   */
#define USART1_CR3_RTSE_MASK                     (0x100U)                                            /**< USART1_CR3.RTSE Mask                    */
#define USART1_CR3_RTSE_SHIFT                    (8U)                                                /**< USART1_CR3.RTSE Position                */
#define USART1_CR3_RTSE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_RTSE_SHIFT))&USART1_CR3_RTSE_MASK) /**< USART1_CR3.RTSE Field                   */
#define USART1_CR3_CTSE_MASK                     (0x200U)                                            /**< USART1_CR3.CTSE Mask                    */
#define USART1_CR3_CTSE_SHIFT                    (9U)                                                /**< USART1_CR3.CTSE Position                */
#define USART1_CR3_CTSE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_CTSE_SHIFT))&USART1_CR3_CTSE_MASK) /**< USART1_CR3.CTSE Field                   */
#define USART1_CR3_CTSIE_MASK                    (0x400U)                                            /**< USART1_CR3.CTSIE Mask                   */
#define USART1_CR3_CTSIE_SHIFT                   (10U)                                               /**< USART1_CR3.CTSIE Position               */
#define USART1_CR3_CTSIE(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR3_CTSIE_SHIFT))&USART1_CR3_CTSIE_MASK) /**< USART1_CR3.CTSIE Field                  */
#define USART1_CR3_ONEBIT_MASK                   (0x800U)                                            /**< USART1_CR3.ONEBIT Mask                  */
#define USART1_CR3_ONEBIT_SHIFT                  (11U)                                               /**< USART1_CR3.ONEBIT Position              */
#define USART1_CR3_ONEBIT(x)                     (((uint32_t)(((uint32_t)(x))<<USART1_CR3_ONEBIT_SHIFT))&USART1_CR3_ONEBIT_MASK) /**< USART1_CR3.ONEBIT Field                 */
#define USART1_CR3_OVRDIS_MASK                   (0x1000U)                                           /**< USART1_CR3.OVRDIS Mask                  */
#define USART1_CR3_OVRDIS_SHIFT                  (12U)                                               /**< USART1_CR3.OVRDIS Position              */
#define USART1_CR3_OVRDIS(x)                     (((uint32_t)(((uint32_t)(x))<<USART1_CR3_OVRDIS_SHIFT))&USART1_CR3_OVRDIS_MASK) /**< USART1_CR3.OVRDIS Field                 */
#define USART1_CR3_DDRE_MASK                     (0x2000U)                                           /**< USART1_CR3.DDRE Mask                    */
#define USART1_CR3_DDRE_SHIFT                    (13U)                                               /**< USART1_CR3.DDRE Position                */
#define USART1_CR3_DDRE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_CR3_DDRE_SHIFT))&USART1_CR3_DDRE_MASK) /**< USART1_CR3.DDRE Field                   */
#define USART1_CR3_DEM_MASK                      (0x4000U)                                           /**< USART1_CR3.DEM Mask                     */
#define USART1_CR3_DEM_SHIFT                     (14U)                                               /**< USART1_CR3.DEM Position                 */
#define USART1_CR3_DEM(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_CR3_DEM_SHIFT))&USART1_CR3_DEM_MASK) /**< USART1_CR3.DEM Field                    */
#define USART1_CR3_DEP_MASK                      (0x8000U)                                           /**< USART1_CR3.DEP Mask                     */
#define USART1_CR3_DEP_SHIFT                     (15U)                                               /**< USART1_CR3.DEP Position                 */
#define USART1_CR3_DEP(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_CR3_DEP_SHIFT))&USART1_CR3_DEP_MASK) /**< USART1_CR3.DEP Field                    */
#define USART1_CR3_SCARCNT_MASK                  (0xE0000U)                                          /**< USART1_CR3.SCARCNT Mask                 */
#define USART1_CR3_SCARCNT_SHIFT                 (17U)                                               /**< USART1_CR3.SCARCNT Position             */
#define USART1_CR3_SCARCNT(x)                    (((uint32_t)(((uint32_t)(x))<<USART1_CR3_SCARCNT_SHIFT))&USART1_CR3_SCARCNT_MASK) /**< USART1_CR3.SCARCNT Field                */
#define USART1_CR3_WUS_MASK                      (0x300000U)                                         /**< USART1_CR3.WUS Mask                     */
#define USART1_CR3_WUS_SHIFT                     (20U)                                               /**< USART1_CR3.WUS Position                 */
#define USART1_CR3_WUS(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_CR3_WUS_SHIFT))&USART1_CR3_WUS_MASK) /**< USART1_CR3.WUS Field                    */
#define USART1_CR3_WUFIE_MASK                    (0x400000U)                                         /**< USART1_CR3.WUFIE Mask                   */
#define USART1_CR3_WUFIE_SHIFT                   (22U)                                               /**< USART1_CR3.WUFIE Position               */
#define USART1_CR3_WUFIE(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_CR3_WUFIE_SHIFT))&USART1_CR3_WUFIE_MASK) /**< USART1_CR3.WUFIE Field                  */
/** @} */

/** @name BRR - Baud rate register */ /** @{ */
#define USART1_BRR_DIV_Fraction_MASK             (0xFU)                                              /**< USART1_BRR.DIV_Fraction Mask            */
#define USART1_BRR_DIV_Fraction_SHIFT            (0U)                                                /**< USART1_BRR.DIV_Fraction Position        */
#define USART1_BRR_DIV_Fraction(x)               (((uint32_t)(((uint32_t)(x))<<USART1_BRR_DIV_Fraction_SHIFT))&USART1_BRR_DIV_Fraction_MASK) /**< USART1_BRR.DIV_Fraction Field           */
#define USART1_BRR_DIV_Mantissa_MASK             (0xFFF0U)                                           /**< USART1_BRR.DIV_Mantissa Mask            */
#define USART1_BRR_DIV_Mantissa_SHIFT            (4U)                                                /**< USART1_BRR.DIV_Mantissa Position        */
#define USART1_BRR_DIV_Mantissa(x)               (((uint32_t)(((uint32_t)(x))<<USART1_BRR_DIV_Mantissa_SHIFT))&USART1_BRR_DIV_Mantissa_MASK) /**< USART1_BRR.DIV_Mantissa Field           */
/** @} */

/** @name GTPR - Guard time and prescaler */ /** @{ */
#define USART1_GTPR_PSC_MASK                     (0xFFU)                                             /**< USART1_GTPR.PSC Mask                    */
#define USART1_GTPR_PSC_SHIFT                    (0U)                                                /**< USART1_GTPR.PSC Position                */
#define USART1_GTPR_PSC(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_GTPR_PSC_SHIFT))&USART1_GTPR_PSC_MASK) /**< USART1_GTPR.PSC Field                   */
#define USART1_GTPR_GT_MASK                      (0xFF00U)                                           /**< USART1_GTPR.GT Mask                     */
#define USART1_GTPR_GT_SHIFT                     (8U)                                                /**< USART1_GTPR.GT Position                 */
#define USART1_GTPR_GT(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_GTPR_GT_SHIFT))&USART1_GTPR_GT_MASK) /**< USART1_GTPR.GT Field                    */
/** @} */

/** @name RTOR - Receiver timeout register */ /** @{ */
#define USART1_RTOR_RTO_MASK                     (0xFFFFFFU)                                         /**< USART1_RTOR.RTO Mask                    */
#define USART1_RTOR_RTO_SHIFT                    (0U)                                                /**< USART1_RTOR.RTO Position                */
#define USART1_RTOR_RTO(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_RTOR_RTO_SHIFT))&USART1_RTOR_RTO_MASK) /**< USART1_RTOR.RTO Field                   */
#define USART1_RTOR_BLEN_MASK                    (0xFF000000U)                                       /**< USART1_RTOR.BLEN Mask                   */
#define USART1_RTOR_BLEN_SHIFT                   (24U)                                               /**< USART1_RTOR.BLEN Position               */
#define USART1_RTOR_BLEN(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_RTOR_BLEN_SHIFT))&USART1_RTOR_BLEN_MASK) /**< USART1_RTOR.BLEN Field                  */
/** @} */

/** @name RQR - Request register */ /** @{ */
#define USART1_RQR_ABRRQ_MASK                    (0x1U)                                              /**< USART1_RQR.ABRRQ Mask                   */
#define USART1_RQR_ABRRQ_SHIFT                   (0U)                                                /**< USART1_RQR.ABRRQ Position               */
#define USART1_RQR_ABRRQ(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_RQR_ABRRQ_SHIFT))&USART1_RQR_ABRRQ_MASK) /**< USART1_RQR.ABRRQ Field                  */
#define USART1_RQR_SBKRQ_MASK                    (0x2U)                                              /**< USART1_RQR.SBKRQ Mask                   */
#define USART1_RQR_SBKRQ_SHIFT                   (1U)                                                /**< USART1_RQR.SBKRQ Position               */
#define USART1_RQR_SBKRQ(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_RQR_SBKRQ_SHIFT))&USART1_RQR_SBKRQ_MASK) /**< USART1_RQR.SBKRQ Field                  */
#define USART1_RQR_MMRQ_MASK                     (0x4U)                                              /**< USART1_RQR.MMRQ Mask                    */
#define USART1_RQR_MMRQ_SHIFT                    (2U)                                                /**< USART1_RQR.MMRQ Position                */
#define USART1_RQR_MMRQ(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_RQR_MMRQ_SHIFT))&USART1_RQR_MMRQ_MASK) /**< USART1_RQR.MMRQ Field                   */
#define USART1_RQR_RXFRQ_MASK                    (0x8U)                                              /**< USART1_RQR.RXFRQ Mask                   */
#define USART1_RQR_RXFRQ_SHIFT                   (3U)                                                /**< USART1_RQR.RXFRQ Position               */
#define USART1_RQR_RXFRQ(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_RQR_RXFRQ_SHIFT))&USART1_RQR_RXFRQ_MASK) /**< USART1_RQR.RXFRQ Field                  */
#define USART1_RQR_TXFRQ_MASK                    (0x10U)                                             /**< USART1_RQR.TXFRQ Mask                   */
#define USART1_RQR_TXFRQ_SHIFT                   (4U)                                                /**< USART1_RQR.TXFRQ Position               */
#define USART1_RQR_TXFRQ(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_RQR_TXFRQ_SHIFT))&USART1_RQR_TXFRQ_MASK) /**< USART1_RQR.TXFRQ Field                  */
/** @} */

/** @name ISR - Interrupt & status */ /** @{ */
#define USART1_ISR_PE_MASK                       (0x1U)                                              /**< USART1_ISR.PE Mask                      */
#define USART1_ISR_PE_SHIFT                      (0U)                                                /**< USART1_ISR.PE Position                  */
#define USART1_ISR_PE(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_ISR_PE_SHIFT))&USART1_ISR_PE_MASK) /**< USART1_ISR.PE Field                     */
#define USART1_ISR_FE_MASK                       (0x2U)                                              /**< USART1_ISR.FE Mask                      */
#define USART1_ISR_FE_SHIFT                      (1U)                                                /**< USART1_ISR.FE Position                  */
#define USART1_ISR_FE(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_ISR_FE_SHIFT))&USART1_ISR_FE_MASK) /**< USART1_ISR.FE Field                     */
#define USART1_ISR_NF_MASK                       (0x4U)                                              /**< USART1_ISR.NF Mask                      */
#define USART1_ISR_NF_SHIFT                      (2U)                                                /**< USART1_ISR.NF Position                  */
#define USART1_ISR_NF(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_ISR_NF_SHIFT))&USART1_ISR_NF_MASK) /**< USART1_ISR.NF Field                     */
#define USART1_ISR_ORE_MASK                      (0x8U)                                              /**< USART1_ISR.ORE Mask                     */
#define USART1_ISR_ORE_SHIFT                     (3U)                                                /**< USART1_ISR.ORE Position                 */
#define USART1_ISR_ORE(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_ISR_ORE_SHIFT))&USART1_ISR_ORE_MASK) /**< USART1_ISR.ORE Field                    */
#define USART1_ISR_IDLE_MASK                     (0x10U)                                             /**< USART1_ISR.IDLE Mask                    */
#define USART1_ISR_IDLE_SHIFT                    (4U)                                                /**< USART1_ISR.IDLE Position                */
#define USART1_ISR_IDLE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_IDLE_SHIFT))&USART1_ISR_IDLE_MASK) /**< USART1_ISR.IDLE Field                   */
#define USART1_ISR_RXNE_MASK                     (0x20U)                                             /**< USART1_ISR.RXNE Mask                    */
#define USART1_ISR_RXNE_SHIFT                    (5U)                                                /**< USART1_ISR.RXNE Position                */
#define USART1_ISR_RXNE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_RXNE_SHIFT))&USART1_ISR_RXNE_MASK) /**< USART1_ISR.RXNE Field                   */
#define USART1_ISR_TC_MASK                       (0x40U)                                             /**< USART1_ISR.TC Mask                      */
#define USART1_ISR_TC_SHIFT                      (6U)                                                /**< USART1_ISR.TC Position                  */
#define USART1_ISR_TC(x)                         (((uint32_t)(((uint32_t)(x))<<USART1_ISR_TC_SHIFT))&USART1_ISR_TC_MASK) /**< USART1_ISR.TC Field                     */
#define USART1_ISR_TXE_MASK                      (0x80U)                                             /**< USART1_ISR.TXE Mask                     */
#define USART1_ISR_TXE_SHIFT                     (7U)                                                /**< USART1_ISR.TXE Position                 */
#define USART1_ISR_TXE(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_ISR_TXE_SHIFT))&USART1_ISR_TXE_MASK) /**< USART1_ISR.TXE Field                    */
#define USART1_ISR_LBDF_MASK                     (0x100U)                                            /**< USART1_ISR.LBDF Mask                    */
#define USART1_ISR_LBDF_SHIFT                    (8U)                                                /**< USART1_ISR.LBDF Position                */
#define USART1_ISR_LBDF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_LBDF_SHIFT))&USART1_ISR_LBDF_MASK) /**< USART1_ISR.LBDF Field                   */
#define USART1_ISR_CTSIF_MASK                    (0x200U)                                            /**< USART1_ISR.CTSIF Mask                   */
#define USART1_ISR_CTSIF_SHIFT                   (9U)                                                /**< USART1_ISR.CTSIF Position               */
#define USART1_ISR_CTSIF(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_ISR_CTSIF_SHIFT))&USART1_ISR_CTSIF_MASK) /**< USART1_ISR.CTSIF Field                  */
#define USART1_ISR_CTS_MASK                      (0x400U)                                            /**< USART1_ISR.CTS Mask                     */
#define USART1_ISR_CTS_SHIFT                     (10U)                                               /**< USART1_ISR.CTS Position                 */
#define USART1_ISR_CTS(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_ISR_CTS_SHIFT))&USART1_ISR_CTS_MASK) /**< USART1_ISR.CTS Field                    */
#define USART1_ISR_RTOF_MASK                     (0x800U)                                            /**< USART1_ISR.RTOF Mask                    */
#define USART1_ISR_RTOF_SHIFT                    (11U)                                               /**< USART1_ISR.RTOF Position                */
#define USART1_ISR_RTOF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_RTOF_SHIFT))&USART1_ISR_RTOF_MASK) /**< USART1_ISR.RTOF Field                   */
#define USART1_ISR_EOBF_MASK                     (0x1000U)                                           /**< USART1_ISR.EOBF Mask                    */
#define USART1_ISR_EOBF_SHIFT                    (12U)                                               /**< USART1_ISR.EOBF Position                */
#define USART1_ISR_EOBF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_EOBF_SHIFT))&USART1_ISR_EOBF_MASK) /**< USART1_ISR.EOBF Field                   */
#define USART1_ISR_ABRE_MASK                     (0x4000U)                                           /**< USART1_ISR.ABRE Mask                    */
#define USART1_ISR_ABRE_SHIFT                    (14U)                                               /**< USART1_ISR.ABRE Position                */
#define USART1_ISR_ABRE(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_ABRE_SHIFT))&USART1_ISR_ABRE_MASK) /**< USART1_ISR.ABRE Field                   */
#define USART1_ISR_ABRF_MASK                     (0x8000U)                                           /**< USART1_ISR.ABRF Mask                    */
#define USART1_ISR_ABRF_SHIFT                    (15U)                                               /**< USART1_ISR.ABRF Position                */
#define USART1_ISR_ABRF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_ABRF_SHIFT))&USART1_ISR_ABRF_MASK) /**< USART1_ISR.ABRF Field                   */
#define USART1_ISR_BUSY_MASK                     (0x10000U)                                          /**< USART1_ISR.BUSY Mask                    */
#define USART1_ISR_BUSY_SHIFT                    (16U)                                               /**< USART1_ISR.BUSY Position                */
#define USART1_ISR_BUSY(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_BUSY_SHIFT))&USART1_ISR_BUSY_MASK) /**< USART1_ISR.BUSY Field                   */
#define USART1_ISR_CMF_MASK                      (0x20000U)                                          /**< USART1_ISR.CMF Mask                     */
#define USART1_ISR_CMF_SHIFT                     (17U)                                               /**< USART1_ISR.CMF Position                 */
#define USART1_ISR_CMF(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_ISR_CMF_SHIFT))&USART1_ISR_CMF_MASK) /**< USART1_ISR.CMF Field                    */
#define USART1_ISR_SBKF_MASK                     (0x40000U)                                          /**< USART1_ISR.SBKF Mask                    */
#define USART1_ISR_SBKF_SHIFT                    (18U)                                               /**< USART1_ISR.SBKF Position                */
#define USART1_ISR_SBKF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ISR_SBKF_SHIFT))&USART1_ISR_SBKF_MASK) /**< USART1_ISR.SBKF Field                   */
#define USART1_ISR_RWU_MASK                      (0x80000U)                                          /**< USART1_ISR.RWU Mask                     */
#define USART1_ISR_RWU_SHIFT                     (19U)                                               /**< USART1_ISR.RWU Position                 */
#define USART1_ISR_RWU(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_ISR_RWU_SHIFT))&USART1_ISR_RWU_MASK) /**< USART1_ISR.RWU Field                    */
#define USART1_ISR_WUF_MASK                      (0x100000U)                                         /**< USART1_ISR.WUF Mask                     */
#define USART1_ISR_WUF_SHIFT                     (20U)                                               /**< USART1_ISR.WUF Position                 */
#define USART1_ISR_WUF(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_ISR_WUF_SHIFT))&USART1_ISR_WUF_MASK) /**< USART1_ISR.WUF Field                    */
#define USART1_ISR_TEACK_MASK                    (0x200000U)                                         /**< USART1_ISR.TEACK Mask                   */
#define USART1_ISR_TEACK_SHIFT                   (21U)                                               /**< USART1_ISR.TEACK Position               */
#define USART1_ISR_TEACK(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_ISR_TEACK_SHIFT))&USART1_ISR_TEACK_MASK) /**< USART1_ISR.TEACK Field                  */
#define USART1_ISR_REACK_MASK                    (0x400000U)                                         /**< USART1_ISR.REACK Mask                   */
#define USART1_ISR_REACK_SHIFT                   (22U)                                               /**< USART1_ISR.REACK Position               */
#define USART1_ISR_REACK(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_ISR_REACK_SHIFT))&USART1_ISR_REACK_MASK) /**< USART1_ISR.REACK Field                  */
/** @} */

/** @name ICR - Interrupt flag clear register */ /** @{ */
#define USART1_ICR_PECF_MASK                     (0x1U)                                              /**< USART1_ICR.PECF Mask                    */
#define USART1_ICR_PECF_SHIFT                    (0U)                                                /**< USART1_ICR.PECF Position                */
#define USART1_ICR_PECF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ICR_PECF_SHIFT))&USART1_ICR_PECF_MASK) /**< USART1_ICR.PECF Field                   */
#define USART1_ICR_FECF_MASK                     (0x2U)                                              /**< USART1_ICR.FECF Mask                    */
#define USART1_ICR_FECF_SHIFT                    (1U)                                                /**< USART1_ICR.FECF Position                */
#define USART1_ICR_FECF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ICR_FECF_SHIFT))&USART1_ICR_FECF_MASK) /**< USART1_ICR.FECF Field                   */
#define USART1_ICR_NCF_MASK                      (0x4U)                                              /**< USART1_ICR.NCF Mask                     */
#define USART1_ICR_NCF_SHIFT                     (2U)                                                /**< USART1_ICR.NCF Position                 */
#define USART1_ICR_NCF(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_ICR_NCF_SHIFT))&USART1_ICR_NCF_MASK) /**< USART1_ICR.NCF Field                    */
#define USART1_ICR_ORECF_MASK                    (0x8U)                                              /**< USART1_ICR.ORECF Mask                   */
#define USART1_ICR_ORECF_SHIFT                   (3U)                                                /**< USART1_ICR.ORECF Position               */
#define USART1_ICR_ORECF(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_ICR_ORECF_SHIFT))&USART1_ICR_ORECF_MASK) /**< USART1_ICR.ORECF Field                  */
#define USART1_ICR_IDLECF_MASK                   (0x10U)                                             /**< USART1_ICR.IDLECF Mask                  */
#define USART1_ICR_IDLECF_SHIFT                  (4U)                                                /**< USART1_ICR.IDLECF Position              */
#define USART1_ICR_IDLECF(x)                     (((uint32_t)(((uint32_t)(x))<<USART1_ICR_IDLECF_SHIFT))&USART1_ICR_IDLECF_MASK) /**< USART1_ICR.IDLECF Field                 */
#define USART1_ICR_TCCF_MASK                     (0x40U)                                             /**< USART1_ICR.TCCF Mask                    */
#define USART1_ICR_TCCF_SHIFT                    (6U)                                                /**< USART1_ICR.TCCF Position                */
#define USART1_ICR_TCCF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ICR_TCCF_SHIFT))&USART1_ICR_TCCF_MASK) /**< USART1_ICR.TCCF Field                   */
#define USART1_ICR_LBDCF_MASK                    (0x100U)                                            /**< USART1_ICR.LBDCF Mask                   */
#define USART1_ICR_LBDCF_SHIFT                   (8U)                                                /**< USART1_ICR.LBDCF Position               */
#define USART1_ICR_LBDCF(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_ICR_LBDCF_SHIFT))&USART1_ICR_LBDCF_MASK) /**< USART1_ICR.LBDCF Field                  */
#define USART1_ICR_CTSCF_MASK                    (0x200U)                                            /**< USART1_ICR.CTSCF Mask                   */
#define USART1_ICR_CTSCF_SHIFT                   (9U)                                                /**< USART1_ICR.CTSCF Position               */
#define USART1_ICR_CTSCF(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_ICR_CTSCF_SHIFT))&USART1_ICR_CTSCF_MASK) /**< USART1_ICR.CTSCF Field                  */
#define USART1_ICR_RTOCF_MASK                    (0x800U)                                            /**< USART1_ICR.RTOCF Mask                   */
#define USART1_ICR_RTOCF_SHIFT                   (11U)                                               /**< USART1_ICR.RTOCF Position               */
#define USART1_ICR_RTOCF(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_ICR_RTOCF_SHIFT))&USART1_ICR_RTOCF_MASK) /**< USART1_ICR.RTOCF Field                  */
#define USART1_ICR_EOBCF_MASK                    (0x1000U)                                           /**< USART1_ICR.EOBCF Mask                   */
#define USART1_ICR_EOBCF_SHIFT                   (12U)                                               /**< USART1_ICR.EOBCF Position               */
#define USART1_ICR_EOBCF(x)                      (((uint32_t)(((uint32_t)(x))<<USART1_ICR_EOBCF_SHIFT))&USART1_ICR_EOBCF_MASK) /**< USART1_ICR.EOBCF Field                  */
#define USART1_ICR_CMCF_MASK                     (0x20000U)                                          /**< USART1_ICR.CMCF Mask                    */
#define USART1_ICR_CMCF_SHIFT                    (17U)                                               /**< USART1_ICR.CMCF Position                */
#define USART1_ICR_CMCF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ICR_CMCF_SHIFT))&USART1_ICR_CMCF_MASK) /**< USART1_ICR.CMCF Field                   */
#define USART1_ICR_WUCF_MASK                     (0x100000U)                                         /**< USART1_ICR.WUCF Mask                    */
#define USART1_ICR_WUCF_SHIFT                    (20U)                                               /**< USART1_ICR.WUCF Position                */
#define USART1_ICR_WUCF(x)                       (((uint32_t)(((uint32_t)(x))<<USART1_ICR_WUCF_SHIFT))&USART1_ICR_WUCF_MASK) /**< USART1_ICR.WUCF Field                   */
/** @} */

/** @name RDR - Receive data register */ /** @{ */
#define USART1_RDR_RDR_MASK                      (0x1FFU)                                            /**< USART1_RDR.RDR Mask                     */
#define USART1_RDR_RDR_SHIFT                     (0U)                                                /**< USART1_RDR.RDR Position                 */
#define USART1_RDR_RDR(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_RDR_RDR_SHIFT))&USART1_RDR_RDR_MASK) /**< USART1_RDR.RDR Field                    */
/** @} */

/** @name TDR - Transmit data register */ /** @{ */
#define USART1_TDR_TDR_MASK                      (0x1FFU)                                            /**< USART1_TDR.TDR Mask                     */
#define USART1_TDR_TDR_SHIFT                     (0U)                                                /**< USART1_TDR.TDR Position                 */
#define USART1_TDR_TDR(x)                        (((uint32_t)(((uint32_t)(x))<<USART1_TDR_TDR_SHIFT))&USART1_TDR_TDR_MASK) /**< USART1_TDR.TDR Field                    */
/** @} */

/** @} */ /* End group USART_Register_Masks_GROUP */


/* USART1 - Peripheral instance base addresses */
#define USART1_BasePtr                 0x40013800UL //!< Peripheral base address
#define USART1                         ((USART1_Type *) USART1_BasePtr) //!< Freescale base pointer
#define USART1_BASE_PTR                (USART1) //!< Freescale style base pointer
#define USART1_IRQS { RCC_CRS_IRQn,  }


/** @} */ /* End group USART_Peripheral_access_layer_GROUP */


/** @brief C Struct for USART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup USART_Peripheral_access_layer_GROUP USART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           USART2 (derived from USART1)         ================ */
/* ================================================================================ */

/**
 * @brief Universal synchronous asynchronous receiver
transmitter
 */

/* USART2 - Peripheral instance base addresses */
#define USART2_BasePtr                 0x40004400UL //!< Peripheral base address
#define USART2                         ((USART1_Type *) USART2_BasePtr) //!< Freescale base pointer
#define USART2_BASE_PTR                (USART2) //!< Freescale style base pointer

/** @} */ /* End group USART_Peripheral_access_layer_GROUP */


/** @brief C Struct for WWDG */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup WWDG_Peripheral_access_layer_GROUP WWDG Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           WWDG (file:WWDG_STM32F030)           ================ */
/* ================================================================================ */

/**
 * @brief Window watchdog
 */
/**
 * @struct WWDG_Type
 * @brief  C Struct allowing access to WWDG registers
 */
typedef struct WWDG_Type {
   __IO uint32_t  CR;                           /**< 0000: Control register                                             */
   __IO uint32_t  CFR;                          /**< 0004: Configuration register                                       */
   __IO uint32_t  SR;                           /**< 0008: Status register                                              */
} WWDG_Type;


/** @brief Register Masks for WWDG */

/* -------------------------------------------------------------------------------- */
/* -----------     'WWDG' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup WWDG_Register_Masks_GROUP WWDG Register Masks */
/** @{ */

/** @name CR - Control register */ /** @{ */
#define WWDG_CR_T_MASK                           (0x7FU)                                             /**< WWDG_CR.T Mask                          */
#define WWDG_CR_T_SHIFT                          (0U)                                                /**< WWDG_CR.T Position                      */
#define WWDG_CR_T(x)                             (((uint32_t)(((uint32_t)(x))<<WWDG_CR_T_SHIFT))&WWDG_CR_T_MASK) /**< WWDG_CR.T Field                         */
#define WWDG_CR_WDGA_MASK                        (0x80U)                                             /**< WWDG_CR.WDGA Mask                       */
#define WWDG_CR_WDGA_SHIFT                       (7U)                                                /**< WWDG_CR.WDGA Position                   */
#define WWDG_CR_WDGA(x)                          (((uint32_t)(((uint32_t)(x))<<WWDG_CR_WDGA_SHIFT))&WWDG_CR_WDGA_MASK) /**< WWDG_CR.WDGA Field                      */
/** @} */

/** @name CFR - Configuration register */ /** @{ */
#define WWDG_CFR_W_MASK                          (0x7FU)                                             /**< WWDG_CFR.W Mask                         */
#define WWDG_CFR_W_SHIFT                         (0U)                                                /**< WWDG_CFR.W Position                     */
#define WWDG_CFR_W(x)                            (((uint32_t)(((uint32_t)(x))<<WWDG_CFR_W_SHIFT))&WWDG_CFR_W_MASK) /**< WWDG_CFR.W Field                        */
#define WWDG_CFR_WDGTB_MASK                      (0x180U)                                            /**< WWDG_CFR.WDGTB Mask                     */
#define WWDG_CFR_WDGTB_SHIFT                     (7U)                                                /**< WWDG_CFR.WDGTB Position                 */
#define WWDG_CFR_WDGTB(x)                        (((uint32_t)(((uint32_t)(x))<<WWDG_CFR_WDGTB_SHIFT))&WWDG_CFR_WDGTB_MASK) /**< WWDG_CFR.WDGTB Field                    */
#define WWDG_CFR_EWI_MASK                        (0x200U)                                            /**< WWDG_CFR.EWI Mask                       */
#define WWDG_CFR_EWI_SHIFT                       (9U)                                                /**< WWDG_CFR.EWI Position                   */
#define WWDG_CFR_EWI(x)                          (((uint32_t)(((uint32_t)(x))<<WWDG_CFR_EWI_SHIFT))&WWDG_CFR_EWI_MASK) /**< WWDG_CFR.EWI Field                      */
/** @} */

/** @name SR - Status register */ /** @{ */
#define WWDG_SR_EWIF_MASK                        (0x1U)                                              /**< WWDG_SR.EWIF Mask                       */
#define WWDG_SR_EWIF_SHIFT                       (0U)                                                /**< WWDG_SR.EWIF Position                   */
#define WWDG_SR_EWIF(x)                          (((uint32_t)(((uint32_t)(x))<<WWDG_SR_EWIF_SHIFT))&WWDG_SR_EWIF_MASK) /**< WWDG_SR.EWIF Field                      */
/** @} */

/** @} */ /* End group WWDG_Register_Masks_GROUP */


/* WWDG - Peripheral instance base addresses */
#define WWDG_BasePtr                   0x40002C00UL //!< Peripheral base address
#define WWDG                           ((WWDG_Type *) WWDG_BasePtr) //!< Freescale base pointer
#define WWDG_BASE_PTR                  (WWDG) //!< Freescale style base pointer

/** @} */ /* End group WWDG_Peripheral_access_layer_GROUP */

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


#endif  /* MCU_STM32F030 */

