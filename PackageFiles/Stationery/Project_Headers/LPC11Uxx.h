/*!
 * @file     LPC11Uxx.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for LPC11Uxx.
 *           Equivalent: 
 *
 * @version  V7
 * @date     2022/09
 *
 */

#ifndef _LPC11UXX_H_
#define _LPC11UXX_H_

#define MCU_LPC11UXX

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif


/** @brief Vector numbers required for NVIC functions */
/** @addtogroup Interrupt_vector_numbers_GROUP Interrupt vector numbers */
/** @{ */
#define NUMBER_OF_INT_VECTORS 47 //<! Number of vector table entries
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
/* ----------------------   LPC11Uxx VectorTable                     ---------------------- */
  PIN_INT0_IRQn                 =   0,   /**<  16 GPIO pin interrupt                                                               */
  PIN_INT1_IRQn                 =   1,   /**<  17 GPIO pin interrupt                                                               */
  PIN_INT2_IRQn                 =   2,   /**<  18 GPIO pin interrupt                                                               */
  PIN_INT3_IRQn                 =   3,   /**<  19 GPIO pin interrupt                                                               */
  PIN_INT4_IRQn                 =   4,   /**<  20 GPIO pin interrupt                                                               */
  PIN_INT5_IRQn                 =   5,   /**<  21 GPIO pin interrupt                                                               */
  PIN_INT6_IRQn                 =   6,   /**<  22 GPIO pin interrupt                                                               */
  PIN_INT7_IRQn                 =   7,   /**<  23 GPIO pin interrupt                                                               */
  GINT0_IRQn                    =   8,   /**<  24 GPIO group interrupt                                                             */
  GINT1_IRQn                    =   9,   /**<  25 GPIO group interrupt                                                             */
  SSP1_IRQn                     =  14,   /**<  30 SSP/SPI                                                                          */
  I2C_IRQn                      =  15,   /**<  31 I2C-bus controller                                                               */
  CT16B0_IRQn                   =  16,   /**<  32 16-bit counter/timers CT16B0                                                     */
  CT16B1_IRQn                   =  17,   /**<  33 16-bit counter/timers CT16B1                                                     */
  CT32B0_IRQn                   =  18,   /**<  34 32-bit counter/timers CT32B0                                                     */
  CT32B1_IRQn                   =  19,   /**<  35 32-bit counter/timers CT32B1                                                     */
  SSP0_IRQn                     =  20,   /**<  36 SSP/SPI                                                                          */
  USART_IRQn                    =  21,   /**<  37 USART                                                                            */
  USB_IRQ_IRQn                  =  22,   /**<  38 USB2.0 device controller                                                         */
  USB_FIQ_IRQn                  =  23,   /**<  39 USB2.0 device controller                                                         */
  ADC_IRQn                      =  24,   /**<  40 ADC                                                                              */
  WDT_IRQn                      =  25,   /**<  41 Windowed Watchdog Timer                                                          */
  BOD_IRQ_IRQn                  =  26,   /**<  42 System control block                                                             */
  FLASH_IRQ_IRQn                =  27,   /**<  43 Flash
controller                                                                 */
  USBWAKEUP_IRQn                =  30,   /**<  46 USB2.0 device controller                                                         */
} IRQn_Type;


/** @brief Prototypes for interrupt handlers */
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                       /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);                 /**< Hard Fault, all classes of Fault                                                 */
extern void SVC_Handler(void);                       /**< System Service Call via SVC instruction                                          */
extern void PendSV_Handler(void);                    /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);                   /**< System Tick Timer                                                                */
extern void PIN_INT0_IRQHandler(void);               /**< GPIO pin interrupt                                                               */
extern void PIN_INT1_IRQHandler(void);               /**< GPIO pin interrupt                                                               */
extern void PIN_INT2_IRQHandler(void);               /**< GPIO pin interrupt                                                               */
extern void PIN_INT3_IRQHandler(void);               /**< GPIO pin interrupt                                                               */
extern void PIN_INT4_IRQHandler(void);               /**< GPIO pin interrupt                                                               */
extern void PIN_INT5_IRQHandler(void);               /**< GPIO pin interrupt                                                               */
extern void PIN_INT6_IRQHandler(void);               /**< GPIO pin interrupt                                                               */
extern void PIN_INT7_IRQHandler(void);               /**< GPIO pin interrupt                                                               */
extern void GINT0_IRQHandler(void);                  /**< GPIO group interrupt                                                             */
extern void GINT1_IRQHandler(void);                  /**< GPIO group interrupt                                                             */
extern void SSP1_IRQHandler(void);                   /**< SSP/SPI                                                                          */
extern void I2C_IRQHandler(void);                    /**< I2C-bus controller                                                               */
extern void CT16B0_IRQHandler(void);                 /**< 16-bit counter/timers CT16B0                                                     */
extern void CT16B1_IRQHandler(void);                 /**< 16-bit counter/timers CT16B1                                                     */
extern void CT32B0_IRQHandler(void);                 /**< 32-bit counter/timers CT32B0                                                     */
extern void CT32B1_IRQHandler(void);                 /**< 32-bit counter/timers CT32B1                                                     */
extern void SSP0_IRQHandler(void);                   /**< SSP/SPI                                                                          */
extern void USART_IRQHandler(void);                  /**< USART                                                                            */
extern void USB_IRQ_IRQHandler(void);                /**< USB2.0 device controller                                                         */
extern void USB_FIQ_IRQHandler(void);                /**< USB2.0 device controller                                                         */
extern void ADC_IRQHandler(void);                    /**< ADC                                                                              */
extern void WDT_IRQHandler(void);                    /**< Windowed Watchdog Timer                                                          */
extern void BOD_IRQ_IRQHandler(void);                /**< System control block                                                             */
extern void FLASH_IRQ_IRQHandler(void);              /**< Flash
controller                                                                 */
extern void USBWAKEUP_IRQHandler(void);              /**< USB2.0 device controller                                                         */


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
#define __CM0PLUS_REV             0x0000     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          2          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             0          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            0          /**< Whether VTOR register is present                    */


/** @} */ /* End group Cortex_Core_Configuration_GROUP */

#include "core_cm0.h"           /* Processor and core peripherals     */
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
/* ================           LPC_ADC (file:ADC_LPC11Uxx)          ================ */
/* ================================================================================ */

/**
 * @brief ADC
 */
/**
 * @struct LPC_ADC_Type
 * @brief  C Struct allowing access to ADC registers
 */
typedef struct LPC_ADC_Type {
   __IO uint32_t  CR;                           /**< 0000: A/D Control Register. The CR register must be written to select the operating mode before A/D conversion can occur */
   __IO uint32_t  GDR;                          /**< 0004: A/D Global Data Register. Contains the result of the most recent A/D conversion */
        uint8_t   RESERVED_0[4];                /**< 0008: 0x4 bytes                                                    */
   __IO uint32_t  INTEN;                        /**< 000C: A/D Interrupt Enable Register. This register contains enable bits that allow the DONE flag of each A/D channel to be included or excluded from contributing to the generation of an A/D interrupt */
   __I  uint32_t  DR[8];                        /**< 0010: A/D Channel Data Register. This register contains the result of the most recent conversion completed on channel N */
   __I  uint32_t  STAT;                         /**< 0030: A/D Status Register. This register contains DONE and OVERRUN flags for all of the A/D channels, as well as the A/D interrupt flag */
} LPC_ADC_Type;


/** @brief Register Masks for ADC */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_ADC' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup ADC_Register_Masks_GROUP ADC Register Masks */
/** @{ */

/** @name CR - A/D Control Register. The CR register must be written to select the operating mode before A/D conversion can occur */ /** @{ */
#define LPC_ADC_CR_SEL_MASK                      (0xFFU)                                             /**< LPC_ADC_CR.SEL Mask                     */
#define LPC_ADC_CR_SEL_SHIFT                     (0U)                                                /**< LPC_ADC_CR.SEL Position                 */
#define LPC_ADC_CR_SEL(x)                        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CR_SEL_SHIFT))&LPC_ADC_CR_SEL_MASK) /**< LPC_ADC_CR.SEL Field                    */
#define LPC_ADC_CR_CLKDIV_MASK                   (0xFF00U)                                           /**< LPC_ADC_CR.CLKDIV Mask                  */
#define LPC_ADC_CR_CLKDIV_SHIFT                  (8U)                                                /**< LPC_ADC_CR.CLKDIV Position              */
#define LPC_ADC_CR_CLKDIV(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CR_CLKDIV_SHIFT))&LPC_ADC_CR_CLKDIV_MASK) /**< LPC_ADC_CR.CLKDIV Field                 */
#define LPC_ADC_CR_BURST_MASK                    (0x10000U)                                          /**< LPC_ADC_CR.BURST Mask                   */
#define LPC_ADC_CR_BURST_SHIFT                   (16U)                                               /**< LPC_ADC_CR.BURST Position               */
#define LPC_ADC_CR_BURST(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CR_BURST_SHIFT))&LPC_ADC_CR_BURST_MASK) /**< LPC_ADC_CR.BURST Field                  */
#define LPC_ADC_CR_CLKS_MASK                     (0xE0000U)                                          /**< LPC_ADC_CR.CLKS Mask                    */
#define LPC_ADC_CR_CLKS_SHIFT                    (17U)                                               /**< LPC_ADC_CR.CLKS Position                */
#define LPC_ADC_CR_CLKS(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CR_CLKS_SHIFT))&LPC_ADC_CR_CLKS_MASK) /**< LPC_ADC_CR.CLKS Field                   */
#define LPC_ADC_CR_START_MASK                    (0x7000000U)                                        /**< LPC_ADC_CR.START Mask                   */
#define LPC_ADC_CR_START_SHIFT                   (24U)                                               /**< LPC_ADC_CR.START Position               */
#define LPC_ADC_CR_START(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CR_START_SHIFT))&LPC_ADC_CR_START_MASK) /**< LPC_ADC_CR.START Field                  */
#define LPC_ADC_CR_EDGE_MASK                     (0x8000000U)                                        /**< LPC_ADC_CR.EDGE Mask                    */
#define LPC_ADC_CR_EDGE_SHIFT                    (27U)                                               /**< LPC_ADC_CR.EDGE Position                */
#define LPC_ADC_CR_EDGE(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CR_EDGE_SHIFT))&LPC_ADC_CR_EDGE_MASK) /**< LPC_ADC_CR.EDGE Field                   */
/** @} */

/** @name GDR - A/D Global Data Register. Contains the result of the most recent A/D conversion */ /** @{ */
#define LPC_ADC_GDR_V_VREF_MASK                  (0xFFC0U)                                           /**< LPC_ADC_GDR.V_VREF Mask                 */
#define LPC_ADC_GDR_V_VREF_SHIFT                 (6U)                                                /**< LPC_ADC_GDR.V_VREF Position             */
#define LPC_ADC_GDR_V_VREF(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_ADC_GDR_V_VREF_SHIFT))&LPC_ADC_GDR_V_VREF_MASK) /**< LPC_ADC_GDR.V_VREF Field                */
#define LPC_ADC_GDR_CHN_MASK                     (0x7000000U)                                        /**< LPC_ADC_GDR.CHN Mask                    */
#define LPC_ADC_GDR_CHN_SHIFT                    (24U)                                               /**< LPC_ADC_GDR.CHN Position                */
#define LPC_ADC_GDR_CHN(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_ADC_GDR_CHN_SHIFT))&LPC_ADC_GDR_CHN_MASK) /**< LPC_ADC_GDR.CHN Field                   */
#define LPC_ADC_GDR_OVERRUN_MASK                 (0x40000000U)                                       /**< LPC_ADC_GDR.OVERRUN Mask                */
#define LPC_ADC_GDR_OVERRUN_SHIFT                (30U)                                               /**< LPC_ADC_GDR.OVERRUN Position            */
#define LPC_ADC_GDR_OVERRUN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_ADC_GDR_OVERRUN_SHIFT))&LPC_ADC_GDR_OVERRUN_MASK) /**< LPC_ADC_GDR.OVERRUN Field               */
#define LPC_ADC_GDR_DONE_MASK                    (0x80000000U)                                       /**< LPC_ADC_GDR.DONE Mask                   */
#define LPC_ADC_GDR_DONE_SHIFT                   (31U)                                               /**< LPC_ADC_GDR.DONE Position               */
#define LPC_ADC_GDR_DONE(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_ADC_GDR_DONE_SHIFT))&LPC_ADC_GDR_DONE_MASK) /**< LPC_ADC_GDR.DONE Field                  */
/** @} */

/** @name INTEN - A/D Interrupt Enable Register. This register contains enable bits that allow the DONE flag of each A/D channel to be included or excluded from contributing to the generation of an A/D interrupt */ /** @{ */
#define LPC_ADC_INTEN_ADINTEN_MASK               (0xFFU)                                             /**< LPC_ADC_INTEN.ADINTEN Mask              */
#define LPC_ADC_INTEN_ADINTEN_SHIFT              (0U)                                                /**< LPC_ADC_INTEN.ADINTEN Position          */
#define LPC_ADC_INTEN_ADINTEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADINTEN_SHIFT))&LPC_ADC_INTEN_ADINTEN_MASK) /**< LPC_ADC_INTEN.ADINTEN Field             */
#define LPC_ADC_INTEN_ADGINTEN_MASK              (0x100U)                                            /**< LPC_ADC_INTEN.ADGINTEN Mask             */
#define LPC_ADC_INTEN_ADGINTEN_SHIFT             (8U)                                                /**< LPC_ADC_INTEN.ADGINTEN Position         */
#define LPC_ADC_INTEN_ADGINTEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADGINTEN_SHIFT))&LPC_ADC_INTEN_ADGINTEN_MASK) /**< LPC_ADC_INTEN.ADGINTEN Field            */
/** @} */

/** @name DR - A/D Channel Data Register. This register contains the result of the most recent conversion completed on channel N */ /** @{ */
#define LPC_ADC_DR_V_VREF_MASK                   (0xFFC0U)                                           /**< LPC_ADC_DR.V_VREF Mask                  */
#define LPC_ADC_DR_V_VREF_SHIFT                  (6U)                                                /**< LPC_ADC_DR.V_VREF Position              */
#define LPC_ADC_DR_V_VREF(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DR_V_VREF_SHIFT))&LPC_ADC_DR_V_VREF_MASK) /**< LPC_ADC_DR.V_VREF Field                 */
#define LPC_ADC_DR_OVERRUN_MASK                  (0x40000000U)                                       /**< LPC_ADC_DR.OVERRUN Mask                 */
#define LPC_ADC_DR_OVERRUN_SHIFT                 (30U)                                               /**< LPC_ADC_DR.OVERRUN Position             */
#define LPC_ADC_DR_OVERRUN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DR_OVERRUN_SHIFT))&LPC_ADC_DR_OVERRUN_MASK) /**< LPC_ADC_DR.OVERRUN Field                */
#define LPC_ADC_DR_DONE_MASK                     (0x80000000U)                                       /**< LPC_ADC_DR.DONE Mask                    */
#define LPC_ADC_DR_DONE_SHIFT                    (31U)                                               /**< LPC_ADC_DR.DONE Position                */
#define LPC_ADC_DR_DONE(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DR_DONE_SHIFT))&LPC_ADC_DR_DONE_MASK) /**< LPC_ADC_DR.DONE Field                   */
/** @} */

/** @name STAT - A/D Status Register. This register contains DONE and OVERRUN flags for all of the A/D channels, as well as the A/D interrupt flag */ /** @{ */
#define LPC_ADC_STAT_DONE_MASK                   (0xFFU)                                             /**< LPC_ADC_STAT.DONE Mask                  */
#define LPC_ADC_STAT_DONE_SHIFT                  (0U)                                                /**< LPC_ADC_STAT.DONE Position              */
#define LPC_ADC_STAT_DONE(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_ADC_STAT_DONE_SHIFT))&LPC_ADC_STAT_DONE_MASK) /**< LPC_ADC_STAT.DONE Field                 */
#define LPC_ADC_STAT_OVERRUN_MASK                (0xFF00U)                                           /**< LPC_ADC_STAT.OVERRUN Mask               */
#define LPC_ADC_STAT_OVERRUN_SHIFT               (8U)                                                /**< LPC_ADC_STAT.OVERRUN Position           */
#define LPC_ADC_STAT_OVERRUN(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_STAT_OVERRUN_SHIFT))&LPC_ADC_STAT_OVERRUN_MASK) /**< LPC_ADC_STAT.OVERRUN Field              */
#define LPC_ADC_STAT_ADINT_MASK                  (0x10000U)                                          /**< LPC_ADC_STAT.ADINT Mask                 */
#define LPC_ADC_STAT_ADINT_SHIFT                 (16U)                                               /**< LPC_ADC_STAT.ADINT Position             */
#define LPC_ADC_STAT_ADINT(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_ADC_STAT_ADINT_SHIFT))&LPC_ADC_STAT_ADINT_MASK) /**< LPC_ADC_STAT.ADINT Field                */
/** @} */

/** @} */ /* End group ADC_Register_Masks_GROUP */


/* LPC_ADC - Peripheral instance base addresses */
#define LPC_ADC_BasePtr                0x4001C000UL //!< Peripheral base address
#define LPC_ADC                        ((LPC_ADC_Type *) LPC_ADC_BasePtr) //!< Freescale base pointer
#define LPC_ADC_BASE_PTR               (LPC_ADC) //!< Freescale style base pointer

/** @} */ /* End group ADC_Peripheral_access_layer_GROUP */


/** @brief C Struct for CT16B0 */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup CT16B0_Peripheral_access_layer_GROUP CT16B0 Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_CT16B0 (file:CT16B0_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief 16-bit counter/timers CT16B0
 */
/**
 * @struct LPC_CT16B0_Type
 * @brief  C Struct allowing access to CT16B0 registers
 */
typedef struct LPC_CT16B0_Type {
   __IO uint32_t  IR;                           /**< 0000: Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */
   __IO uint32_t  TCR;                          /**< 0004: Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  TC;                           /**< 0008: Timer Counter. The 16-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  PR;                           /**< 000C: Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  PC;                           /**< 0010: Prescale Counter. The 16-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  MCR;                          /**< 0014: Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  MR[4];                        /**< 0018: Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */
   __IO uint32_t  CCR;                          /**< 0028: Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  CR0;                          /**< 002C: Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT16B0_CAP0 input */
        uint8_t   RESERVED_0[4];                /**< 0030: 0x4 bytes                                                    */
   __I  uint32_t  CR1;                          /**< 0034: Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT16B0_CAP1 input */
        uint8_t   RESERVED_1[4];                /**< 0038: 0x4 bytes                                                    */
   __IO uint32_t  EMR;                          /**< 003C: External Match Register. The EMR controls the match function and the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */
        uint8_t   RESERVED_2[48];               /**< 0040: 0x30 bytes                                                   */
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register. The PWMCON enables PWM mode for the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */
} LPC_CT16B0_Type;


/** @brief Register Masks for CT16B0 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_CT16B0' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup CT16B0_Register_Masks_GROUP CT16B0 Register Masks */
/** @{ */

/** @name IR - Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */ /** @{ */
#define LPC_CT16B0_IR_MR0INT_MASK                (0x1U)                                              /**< LPC_CT16B0_IR.MR0INT Mask               */
#define LPC_CT16B0_IR_MR0INT_SHIFT               (0U)                                                /**< LPC_CT16B0_IR.MR0INT Position           */
#define LPC_CT16B0_IR_MR0INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_IR_MR0INT_SHIFT))&LPC_CT16B0_IR_MR0INT_MASK) /**< LPC_CT16B0_IR.MR0INT Field              */
#define LPC_CT16B0_IR_MR1INT_MASK                (0x2U)                                              /**< LPC_CT16B0_IR.MR1INT Mask               */
#define LPC_CT16B0_IR_MR1INT_SHIFT               (1U)                                                /**< LPC_CT16B0_IR.MR1INT Position           */
#define LPC_CT16B0_IR_MR1INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_IR_MR1INT_SHIFT))&LPC_CT16B0_IR_MR1INT_MASK) /**< LPC_CT16B0_IR.MR1INT Field              */
#define LPC_CT16B0_IR_MR2INT_MASK                (0x4U)                                              /**< LPC_CT16B0_IR.MR2INT Mask               */
#define LPC_CT16B0_IR_MR2INT_SHIFT               (2U)                                                /**< LPC_CT16B0_IR.MR2INT Position           */
#define LPC_CT16B0_IR_MR2INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_IR_MR2INT_SHIFT))&LPC_CT16B0_IR_MR2INT_MASK) /**< LPC_CT16B0_IR.MR2INT Field              */
#define LPC_CT16B0_IR_MR3INT_MASK                (0x8U)                                              /**< LPC_CT16B0_IR.MR3INT Mask               */
#define LPC_CT16B0_IR_MR3INT_SHIFT               (3U)                                                /**< LPC_CT16B0_IR.MR3INT Position           */
#define LPC_CT16B0_IR_MR3INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_IR_MR3INT_SHIFT))&LPC_CT16B0_IR_MR3INT_MASK) /**< LPC_CT16B0_IR.MR3INT Field              */
#define LPC_CT16B0_IR_CR0INT_MASK                (0x10U)                                             /**< LPC_CT16B0_IR.CR0INT Mask               */
#define LPC_CT16B0_IR_CR0INT_SHIFT               (4U)                                                /**< LPC_CT16B0_IR.CR0INT Position           */
#define LPC_CT16B0_IR_CR0INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_IR_CR0INT_SHIFT))&LPC_CT16B0_IR_CR0INT_MASK) /**< LPC_CT16B0_IR.CR0INT Field              */
#define LPC_CT16B0_IR_CR1INT_MASK                (0x40U)                                             /**< LPC_CT16B0_IR.CR1INT Mask               */
#define LPC_CT16B0_IR_CR1INT_SHIFT               (6U)                                                /**< LPC_CT16B0_IR.CR1INT Position           */
#define LPC_CT16B0_IR_CR1INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_IR_CR1INT_SHIFT))&LPC_CT16B0_IR_CR1INT_MASK) /**< LPC_CT16B0_IR.CR1INT Field              */
/** @} */

/** @name TCR - Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */ /** @{ */
#define LPC_CT16B0_TCR_CEN_MASK                  (0x1U)                                              /**< LPC_CT16B0_TCR.CEN Mask                 */
#define LPC_CT16B0_TCR_CEN_SHIFT                 (0U)                                                /**< LPC_CT16B0_TCR.CEN Position             */
#define LPC_CT16B0_TCR_CEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_TCR_CEN_SHIFT))&LPC_CT16B0_TCR_CEN_MASK) /**< LPC_CT16B0_TCR.CEN Field                */
#define LPC_CT16B0_TCR_CRST_MASK                 (0x2U)                                              /**< LPC_CT16B0_TCR.CRST Mask                */
#define LPC_CT16B0_TCR_CRST_SHIFT                (1U)                                                /**< LPC_CT16B0_TCR.CRST Position            */
#define LPC_CT16B0_TCR_CRST(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_TCR_CRST_SHIFT))&LPC_CT16B0_TCR_CRST_MASK) /**< LPC_CT16B0_TCR.CRST Field               */
/** @} */

/** @name TC - Timer Counter. The 16-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */ /** @{ */
#define LPC_CT16B0_TC_TC_MASK                    (0xFFFFU)                                           /**< LPC_CT16B0_TC.TC Mask                   */
#define LPC_CT16B0_TC_TC_SHIFT                   (0U)                                                /**< LPC_CT16B0_TC.TC Position               */
#define LPC_CT16B0_TC_TC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_TC_TC_SHIFT))&LPC_CT16B0_TC_TC_MASK) /**< LPC_CT16B0_TC.TC Field                  */
/** @} */

/** @name PR - Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */ /** @{ */
#define LPC_CT16B0_PR_PCVAL_MASK                 (0xFFFFU)                                           /**< LPC_CT16B0_PR.PCVAL Mask                */
#define LPC_CT16B0_PR_PCVAL_SHIFT                (0U)                                                /**< LPC_CT16B0_PR.PCVAL Position            */
#define LPC_CT16B0_PR_PCVAL(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_PR_PCVAL_SHIFT))&LPC_CT16B0_PR_PCVAL_MASK) /**< LPC_CT16B0_PR.PCVAL Field               */
/** @} */

/** @name PC - Prescale Counter. The 16-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */ /** @{ */
#define LPC_CT16B0_PC_PC_MASK                    (0xFFFFU)                                           /**< LPC_CT16B0_PC.PC Mask                   */
#define LPC_CT16B0_PC_PC_SHIFT                   (0U)                                                /**< LPC_CT16B0_PC.PC Position               */
#define LPC_CT16B0_PC_PC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_PC_PC_SHIFT))&LPC_CT16B0_PC_PC_MASK) /**< LPC_CT16B0_PC.PC Field                  */
/** @} */

/** @name MCR - Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */ /** @{ */
#define LPC_CT16B0_MCR_MR0I_MASK                 (0x1U)                                              /**< LPC_CT16B0_MCR.MR0I Mask                */
#define LPC_CT16B0_MCR_MR0I_SHIFT                (0U)                                                /**< LPC_CT16B0_MCR.MR0I Position            */
#define LPC_CT16B0_MCR_MR0I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR0I_SHIFT))&LPC_CT16B0_MCR_MR0I_MASK) /**< LPC_CT16B0_MCR.MR0I Field               */
#define LPC_CT16B0_MCR_MR0R_MASK                 (0x2U)                                              /**< LPC_CT16B0_MCR.MR0R Mask                */
#define LPC_CT16B0_MCR_MR0R_SHIFT                (1U)                                                /**< LPC_CT16B0_MCR.MR0R Position            */
#define LPC_CT16B0_MCR_MR0R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR0R_SHIFT))&LPC_CT16B0_MCR_MR0R_MASK) /**< LPC_CT16B0_MCR.MR0R Field               */
#define LPC_CT16B0_MCR_MR0S_MASK                 (0x4U)                                              /**< LPC_CT16B0_MCR.MR0S Mask                */
#define LPC_CT16B0_MCR_MR0S_SHIFT                (2U)                                                /**< LPC_CT16B0_MCR.MR0S Position            */
#define LPC_CT16B0_MCR_MR0S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR0S_SHIFT))&LPC_CT16B0_MCR_MR0S_MASK) /**< LPC_CT16B0_MCR.MR0S Field               */
#define LPC_CT16B0_MCR_MR1I_MASK                 (0x8U)                                              /**< LPC_CT16B0_MCR.MR1I Mask                */
#define LPC_CT16B0_MCR_MR1I_SHIFT                (3U)                                                /**< LPC_CT16B0_MCR.MR1I Position            */
#define LPC_CT16B0_MCR_MR1I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR1I_SHIFT))&LPC_CT16B0_MCR_MR1I_MASK) /**< LPC_CT16B0_MCR.MR1I Field               */
#define LPC_CT16B0_MCR_MR1R_MASK                 (0x10U)                                             /**< LPC_CT16B0_MCR.MR1R Mask                */
#define LPC_CT16B0_MCR_MR1R_SHIFT                (4U)                                                /**< LPC_CT16B0_MCR.MR1R Position            */
#define LPC_CT16B0_MCR_MR1R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR1R_SHIFT))&LPC_CT16B0_MCR_MR1R_MASK) /**< LPC_CT16B0_MCR.MR1R Field               */
#define LPC_CT16B0_MCR_MR1S_MASK                 (0x20U)                                             /**< LPC_CT16B0_MCR.MR1S Mask                */
#define LPC_CT16B0_MCR_MR1S_SHIFT                (5U)                                                /**< LPC_CT16B0_MCR.MR1S Position            */
#define LPC_CT16B0_MCR_MR1S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR1S_SHIFT))&LPC_CT16B0_MCR_MR1S_MASK) /**< LPC_CT16B0_MCR.MR1S Field               */
#define LPC_CT16B0_MCR_MR2I_MASK                 (0x40U)                                             /**< LPC_CT16B0_MCR.MR2I Mask                */
#define LPC_CT16B0_MCR_MR2I_SHIFT                (6U)                                                /**< LPC_CT16B0_MCR.MR2I Position            */
#define LPC_CT16B0_MCR_MR2I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR2I_SHIFT))&LPC_CT16B0_MCR_MR2I_MASK) /**< LPC_CT16B0_MCR.MR2I Field               */
#define LPC_CT16B0_MCR_MR2R_MASK                 (0x80U)                                             /**< LPC_CT16B0_MCR.MR2R Mask                */
#define LPC_CT16B0_MCR_MR2R_SHIFT                (7U)                                                /**< LPC_CT16B0_MCR.MR2R Position            */
#define LPC_CT16B0_MCR_MR2R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR2R_SHIFT))&LPC_CT16B0_MCR_MR2R_MASK) /**< LPC_CT16B0_MCR.MR2R Field               */
#define LPC_CT16B0_MCR_MR2S_MASK                 (0x100U)                                            /**< LPC_CT16B0_MCR.MR2S Mask                */
#define LPC_CT16B0_MCR_MR2S_SHIFT                (8U)                                                /**< LPC_CT16B0_MCR.MR2S Position            */
#define LPC_CT16B0_MCR_MR2S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR2S_SHIFT))&LPC_CT16B0_MCR_MR2S_MASK) /**< LPC_CT16B0_MCR.MR2S Field               */
#define LPC_CT16B0_MCR_MR3I_MASK                 (0x200U)                                            /**< LPC_CT16B0_MCR.MR3I Mask                */
#define LPC_CT16B0_MCR_MR3I_SHIFT                (9U)                                                /**< LPC_CT16B0_MCR.MR3I Position            */
#define LPC_CT16B0_MCR_MR3I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR3I_SHIFT))&LPC_CT16B0_MCR_MR3I_MASK) /**< LPC_CT16B0_MCR.MR3I Field               */
#define LPC_CT16B0_MCR_MR3R_MASK                 (0x400U)                                            /**< LPC_CT16B0_MCR.MR3R Mask                */
#define LPC_CT16B0_MCR_MR3R_SHIFT                (10U)                                               /**< LPC_CT16B0_MCR.MR3R Position            */
#define LPC_CT16B0_MCR_MR3R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR3R_SHIFT))&LPC_CT16B0_MCR_MR3R_MASK) /**< LPC_CT16B0_MCR.MR3R Field               */
#define LPC_CT16B0_MCR_MR3S_MASK                 (0x800U)                                            /**< LPC_CT16B0_MCR.MR3S Mask                */
#define LPC_CT16B0_MCR_MR3S_SHIFT                (11U)                                               /**< LPC_CT16B0_MCR.MR3S Position            */
#define LPC_CT16B0_MCR_MR3S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MCR_MR3S_SHIFT))&LPC_CT16B0_MCR_MR3S_MASK) /**< LPC_CT16B0_MCR.MR3S Field               */
/** @} */

/** @name MR - Match Register %s. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */ /** @{ */
#define LPC_CT16B0_MR_MATCH_MASK                 (0xFFFFU)                                           /**< LPC_CT16B0_MR.MATCH Mask                */
#define LPC_CT16B0_MR_MATCH_SHIFT                (0U)                                                /**< LPC_CT16B0_MR.MATCH Position            */
#define LPC_CT16B0_MR_MATCH(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_MR_MATCH_SHIFT))&LPC_CT16B0_MR_MATCH_MASK) /**< LPC_CT16B0_MR.MATCH Field               */
/** @} */

/** @name CCR - Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */ /** @{ */
#define LPC_CT16B0_CCR_CAP0RE_MASK               (0x1U)                                              /**< LPC_CT16B0_CCR.CAP0RE Mask              */
#define LPC_CT16B0_CCR_CAP0RE_SHIFT              (0U)                                                /**< LPC_CT16B0_CCR.CAP0RE Position          */
#define LPC_CT16B0_CCR_CAP0RE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CCR_CAP0RE_SHIFT))&LPC_CT16B0_CCR_CAP0RE_MASK) /**< LPC_CT16B0_CCR.CAP0RE Field             */
#define LPC_CT16B0_CCR_CAP0FE_MASK               (0x2U)                                              /**< LPC_CT16B0_CCR.CAP0FE Mask              */
#define LPC_CT16B0_CCR_CAP0FE_SHIFT              (1U)                                                /**< LPC_CT16B0_CCR.CAP0FE Position          */
#define LPC_CT16B0_CCR_CAP0FE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CCR_CAP0FE_SHIFT))&LPC_CT16B0_CCR_CAP0FE_MASK) /**< LPC_CT16B0_CCR.CAP0FE Field             */
#define LPC_CT16B0_CCR_CAP0I_MASK                (0x4U)                                              /**< LPC_CT16B0_CCR.CAP0I Mask               */
#define LPC_CT16B0_CCR_CAP0I_SHIFT               (2U)                                                /**< LPC_CT16B0_CCR.CAP0I Position           */
#define LPC_CT16B0_CCR_CAP0I(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CCR_CAP0I_SHIFT))&LPC_CT16B0_CCR_CAP0I_MASK) /**< LPC_CT16B0_CCR.CAP0I Field              */
#define LPC_CT16B0_CCR_CAP1RE_MASK               (0x40U)                                             /**< LPC_CT16B0_CCR.CAP1RE Mask              */
#define LPC_CT16B0_CCR_CAP1RE_SHIFT              (6U)                                                /**< LPC_CT16B0_CCR.CAP1RE Position          */
#define LPC_CT16B0_CCR_CAP1RE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CCR_CAP1RE_SHIFT))&LPC_CT16B0_CCR_CAP1RE_MASK) /**< LPC_CT16B0_CCR.CAP1RE Field             */
#define LPC_CT16B0_CCR_CAP1FE_MASK               (0x80U)                                             /**< LPC_CT16B0_CCR.CAP1FE Mask              */
#define LPC_CT16B0_CCR_CAP1FE_SHIFT              (7U)                                                /**< LPC_CT16B0_CCR.CAP1FE Position          */
#define LPC_CT16B0_CCR_CAP1FE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CCR_CAP1FE_SHIFT))&LPC_CT16B0_CCR_CAP1FE_MASK) /**< LPC_CT16B0_CCR.CAP1FE Field             */
#define LPC_CT16B0_CCR_CAP1I_MASK                (0x100U)                                            /**< LPC_CT16B0_CCR.CAP1I Mask               */
#define LPC_CT16B0_CCR_CAP1I_SHIFT               (8U)                                                /**< LPC_CT16B0_CCR.CAP1I Position           */
#define LPC_CT16B0_CCR_CAP1I(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CCR_CAP1I_SHIFT))&LPC_CT16B0_CCR_CAP1I_MASK) /**< LPC_CT16B0_CCR.CAP1I Field              */
/** @} */

/** @name CR0 - Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT16B0_CAP0 input */ /** @{ */
#define LPC_CT16B0_CR0_CAP_MASK                  (0xFFFFU)                                           /**< LPC_CT16B0_CR0.CAP Mask                 */
#define LPC_CT16B0_CR0_CAP_SHIFT                 (0U)                                                /**< LPC_CT16B0_CR0.CAP Position             */
#define LPC_CT16B0_CR0_CAP(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CR0_CAP_SHIFT))&LPC_CT16B0_CR0_CAP_MASK) /**< LPC_CT16B0_CR0.CAP Field                */
/** @} */

/** @name CR1 - Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT16B0_CAP1 input */ /** @{ */
#define LPC_CT16B0_CR1_CAP_MASK                  (0xFFFFU)                                           /**< LPC_CT16B0_CR1.CAP Mask                 */
#define LPC_CT16B0_CR1_CAP_SHIFT                 (0U)                                                /**< LPC_CT16B0_CR1.CAP Position             */
#define LPC_CT16B0_CR1_CAP(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CR1_CAP_SHIFT))&LPC_CT16B0_CR1_CAP_MASK) /**< LPC_CT16B0_CR1.CAP Field                */
/** @} */

/** @name EMR - External Match Register. The EMR controls the match function and the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */ /** @{ */
#define LPC_CT16B0_EMR_EM0_MASK                  (0x1U)                                              /**< LPC_CT16B0_EMR.EM0 Mask                 */
#define LPC_CT16B0_EMR_EM0_SHIFT                 (0U)                                                /**< LPC_CT16B0_EMR.EM0 Position             */
#define LPC_CT16B0_EMR_EM0(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_EMR_EM0_SHIFT))&LPC_CT16B0_EMR_EM0_MASK) /**< LPC_CT16B0_EMR.EM0 Field                */
#define LPC_CT16B0_EMR_EM1_MASK                  (0x2U)                                              /**< LPC_CT16B0_EMR.EM1 Mask                 */
#define LPC_CT16B0_EMR_EM1_SHIFT                 (1U)                                                /**< LPC_CT16B0_EMR.EM1 Position             */
#define LPC_CT16B0_EMR_EM1(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_EMR_EM1_SHIFT))&LPC_CT16B0_EMR_EM1_MASK) /**< LPC_CT16B0_EMR.EM1 Field                */
#define LPC_CT16B0_EMR_EM2_MASK                  (0x4U)                                              /**< LPC_CT16B0_EMR.EM2 Mask                 */
#define LPC_CT16B0_EMR_EM2_SHIFT                 (2U)                                                /**< LPC_CT16B0_EMR.EM2 Position             */
#define LPC_CT16B0_EMR_EM2(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_EMR_EM2_SHIFT))&LPC_CT16B0_EMR_EM2_MASK) /**< LPC_CT16B0_EMR.EM2 Field                */
#define LPC_CT16B0_EMR_EM3_MASK                  (0x8U)                                              /**< LPC_CT16B0_EMR.EM3 Mask                 */
#define LPC_CT16B0_EMR_EM3_SHIFT                 (3U)                                                /**< LPC_CT16B0_EMR.EM3 Position             */
#define LPC_CT16B0_EMR_EM3(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_EMR_EM3_SHIFT))&LPC_CT16B0_EMR_EM3_MASK) /**< LPC_CT16B0_EMR.EM3 Field                */
#define LPC_CT16B0_EMR_EMC0_MASK                 (0x30U)                                             /**< LPC_CT16B0_EMR.EMC0 Mask                */
#define LPC_CT16B0_EMR_EMC0_SHIFT                (4U)                                                /**< LPC_CT16B0_EMR.EMC0 Position            */
#define LPC_CT16B0_EMR_EMC0(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_EMR_EMC0_SHIFT))&LPC_CT16B0_EMR_EMC0_MASK) /**< LPC_CT16B0_EMR.EMC0 Field               */
#define LPC_CT16B0_EMR_EMC1_MASK                 (0xC0U)                                             /**< LPC_CT16B0_EMR.EMC1 Mask                */
#define LPC_CT16B0_EMR_EMC1_SHIFT                (6U)                                                /**< LPC_CT16B0_EMR.EMC1 Position            */
#define LPC_CT16B0_EMR_EMC1(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_EMR_EMC1_SHIFT))&LPC_CT16B0_EMR_EMC1_MASK) /**< LPC_CT16B0_EMR.EMC1 Field               */
#define LPC_CT16B0_EMR_EMC2_MASK                 (0x300U)                                            /**< LPC_CT16B0_EMR.EMC2 Mask                */
#define LPC_CT16B0_EMR_EMC2_SHIFT                (8U)                                                /**< LPC_CT16B0_EMR.EMC2 Position            */
#define LPC_CT16B0_EMR_EMC2(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_EMR_EMC2_SHIFT))&LPC_CT16B0_EMR_EMC2_MASK) /**< LPC_CT16B0_EMR.EMC2 Field               */
#define LPC_CT16B0_EMR_EMC3_MASK                 (0xC00U)                                            /**< LPC_CT16B0_EMR.EMC3 Mask                */
#define LPC_CT16B0_EMR_EMC3_SHIFT                (10U)                                               /**< LPC_CT16B0_EMR.EMC3 Position            */
#define LPC_CT16B0_EMR_EMC3(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_EMR_EMC3_SHIFT))&LPC_CT16B0_EMR_EMC3_MASK) /**< LPC_CT16B0_EMR.EMC3 Field               */
/** @} */

/** @name CTCR - Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */ /** @{ */
#define LPC_CT16B0_CTCR_CTM_MASK                 (0x3U)                                              /**< LPC_CT16B0_CTCR.CTM Mask                */
#define LPC_CT16B0_CTCR_CTM_SHIFT                (0U)                                                /**< LPC_CT16B0_CTCR.CTM Position            */
#define LPC_CT16B0_CTCR_CTM(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CTCR_CTM_SHIFT))&LPC_CT16B0_CTCR_CTM_MASK) /**< LPC_CT16B0_CTCR.CTM Field               */
#define LPC_CT16B0_CTCR_CIS_MASK                 (0xCU)                                              /**< LPC_CT16B0_CTCR.CIS Mask                */
#define LPC_CT16B0_CTCR_CIS_SHIFT                (2U)                                                /**< LPC_CT16B0_CTCR.CIS Position            */
#define LPC_CT16B0_CTCR_CIS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CTCR_CIS_SHIFT))&LPC_CT16B0_CTCR_CIS_MASK) /**< LPC_CT16B0_CTCR.CIS Field               */
#define LPC_CT16B0_CTCR_ENCC_MASK                (0x10U)                                             /**< LPC_CT16B0_CTCR.ENCC Mask               */
#define LPC_CT16B0_CTCR_ENCC_SHIFT               (4U)                                                /**< LPC_CT16B0_CTCR.ENCC Position           */
#define LPC_CT16B0_CTCR_ENCC(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CTCR_ENCC_SHIFT))&LPC_CT16B0_CTCR_ENCC_MASK) /**< LPC_CT16B0_CTCR.ENCC Field              */
#define LPC_CT16B0_CTCR_SELCC_MASK               (0xE0U)                                             /**< LPC_CT16B0_CTCR.SELCC Mask              */
#define LPC_CT16B0_CTCR_SELCC_SHIFT              (5U)                                                /**< LPC_CT16B0_CTCR.SELCC Position          */
#define LPC_CT16B0_CTCR_SELCC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_CTCR_SELCC_SHIFT))&LPC_CT16B0_CTCR_SELCC_MASK) /**< LPC_CT16B0_CTCR.SELCC Field             */
/** @} */

/** @name PWMC - PWM Control Register. The PWMCON enables PWM mode for the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */ /** @{ */
#define LPC_CT16B0_PWMC_PWMEN0_MASK              (0x1U)                                              /**< LPC_CT16B0_PWMC.PWMEN0 Mask             */
#define LPC_CT16B0_PWMC_PWMEN0_SHIFT             (0U)                                                /**< LPC_CT16B0_PWMC.PWMEN0 Position         */
#define LPC_CT16B0_PWMC_PWMEN0(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_PWMC_PWMEN0_SHIFT))&LPC_CT16B0_PWMC_PWMEN0_MASK) /**< LPC_CT16B0_PWMC.PWMEN0 Field            */
#define LPC_CT16B0_PWMC_PWMEN1_MASK              (0x2U)                                              /**< LPC_CT16B0_PWMC.PWMEN1 Mask             */
#define LPC_CT16B0_PWMC_PWMEN1_SHIFT             (1U)                                                /**< LPC_CT16B0_PWMC.PWMEN1 Position         */
#define LPC_CT16B0_PWMC_PWMEN1(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_PWMC_PWMEN1_SHIFT))&LPC_CT16B0_PWMC_PWMEN1_MASK) /**< LPC_CT16B0_PWMC.PWMEN1 Field            */
#define LPC_CT16B0_PWMC_PWMEN2_MASK              (0x4U)                                              /**< LPC_CT16B0_PWMC.PWMEN2 Mask             */
#define LPC_CT16B0_PWMC_PWMEN2_SHIFT             (2U)                                                /**< LPC_CT16B0_PWMC.PWMEN2 Position         */
#define LPC_CT16B0_PWMC_PWMEN2(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_PWMC_PWMEN2_SHIFT))&LPC_CT16B0_PWMC_PWMEN2_MASK) /**< LPC_CT16B0_PWMC.PWMEN2 Field            */
#define LPC_CT16B0_PWMC_PWMEN3_MASK              (0x8U)                                              /**< LPC_CT16B0_PWMC.PWMEN3 Mask             */
#define LPC_CT16B0_PWMC_PWMEN3_SHIFT             (3U)                                                /**< LPC_CT16B0_PWMC.PWMEN3 Position         */
#define LPC_CT16B0_PWMC_PWMEN3(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT16B0_PWMC_PWMEN3_SHIFT))&LPC_CT16B0_PWMC_PWMEN3_MASK) /**< LPC_CT16B0_PWMC.PWMEN3 Field            */
/** @} */

/** @} */ /* End group CT16B0_Register_Masks_GROUP */


/* LPC_CT16B0 - Peripheral instance base addresses */
#define LPC_CT16B0_BasePtr             0x4000C000UL //!< Peripheral base address
#define LPC_CT16B0                     ((LPC_CT16B0_Type *) LPC_CT16B0_BasePtr) //!< Freescale base pointer
#define LPC_CT16B0_BASE_PTR            (LPC_CT16B0) //!< Freescale style base pointer

/** @} */ /* End group CT16B0_Peripheral_access_layer_GROUP */


/** @brief C Struct for CT16B */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup CT16B_Peripheral_access_layer_GROUP CT16B Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_CT16B1 (file:CT16B1_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief 16-bit counter/timers CT16B1
 */
/**
 * @struct LPC_CT16B1_Type
 * @brief  C Struct allowing access to CT16B registers
 */
typedef struct LPC_CT16B1_Type {
   __IO uint32_t  IR;                           /**< 0000: Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */
   __IO uint32_t  TCR;                          /**< 0004: Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  TC;                           /**< 0008: Timer Counter. The 16-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  PR;                           /**< 000C: Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  PC;                           /**< 0010: Prescale Counter. The 16-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  MCR;                          /**< 0014: Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  MR[4];                        /**< 0018: Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */
   __IO uint32_t  CCR;                          /**< 0028: Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  CR0;                          /**< 002C: Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT16B0_CAP0 input */
   __I  uint32_t  CR1;                          /**< 0030: Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT16B1_CAP1 input */
        uint8_t   RESERVED_0[8];                /**< 0034: 0x8 bytes                                                    */
   __IO uint32_t  EMR;                          /**< 003C: External Match Register. The EMR controls the match function and the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */
        uint8_t   RESERVED_1[48];               /**< 0040: 0x30 bytes                                                   */
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register. The PWMCON enables PWM mode for the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */
} LPC_CT16B1_Type;


/** @brief Register Masks for CT16B */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_CT16B1' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup CT16B_Register_Masks_GROUP CT16B Register Masks */
/** @{ */

/** @name IR - Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */ /** @{ */
#define LPC_CT16B1_IR_MR0INT_MASK                (0x1U)                                              /**< LPC_CT16B1_IR.MR0INT Mask               */
#define LPC_CT16B1_IR_MR0INT_SHIFT               (0U)                                                /**< LPC_CT16B1_IR.MR0INT Position           */
#define LPC_CT16B1_IR_MR0INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_IR_MR0INT_SHIFT))&LPC_CT16B1_IR_MR0INT_MASK) /**< LPC_CT16B1_IR.MR0INT Field              */
#define LPC_CT16B1_IR_MR1INT_MASK                (0x2U)                                              /**< LPC_CT16B1_IR.MR1INT Mask               */
#define LPC_CT16B1_IR_MR1INT_SHIFT               (1U)                                                /**< LPC_CT16B1_IR.MR1INT Position           */
#define LPC_CT16B1_IR_MR1INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_IR_MR1INT_SHIFT))&LPC_CT16B1_IR_MR1INT_MASK) /**< LPC_CT16B1_IR.MR1INT Field              */
#define LPC_CT16B1_IR_MR2INT_MASK                (0x4U)                                              /**< LPC_CT16B1_IR.MR2INT Mask               */
#define LPC_CT16B1_IR_MR2INT_SHIFT               (2U)                                                /**< LPC_CT16B1_IR.MR2INT Position           */
#define LPC_CT16B1_IR_MR2INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_IR_MR2INT_SHIFT))&LPC_CT16B1_IR_MR2INT_MASK) /**< LPC_CT16B1_IR.MR2INT Field              */
#define LPC_CT16B1_IR_MR3INT_MASK                (0x8U)                                              /**< LPC_CT16B1_IR.MR3INT Mask               */
#define LPC_CT16B1_IR_MR3INT_SHIFT               (3U)                                                /**< LPC_CT16B1_IR.MR3INT Position           */
#define LPC_CT16B1_IR_MR3INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_IR_MR3INT_SHIFT))&LPC_CT16B1_IR_MR3INT_MASK) /**< LPC_CT16B1_IR.MR3INT Field              */
#define LPC_CT16B1_IR_CR0INT_MASK                (0x10U)                                             /**< LPC_CT16B1_IR.CR0INT Mask               */
#define LPC_CT16B1_IR_CR0INT_SHIFT               (4U)                                                /**< LPC_CT16B1_IR.CR0INT Position           */
#define LPC_CT16B1_IR_CR0INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_IR_CR0INT_SHIFT))&LPC_CT16B1_IR_CR0INT_MASK) /**< LPC_CT16B1_IR.CR0INT Field              */
#define LPC_CT16B1_IR_CR1INT_MASK                (0x20U)                                             /**< LPC_CT16B1_IR.CR1INT Mask               */
#define LPC_CT16B1_IR_CR1INT_SHIFT               (5U)                                                /**< LPC_CT16B1_IR.CR1INT Position           */
#define LPC_CT16B1_IR_CR1INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_IR_CR1INT_SHIFT))&LPC_CT16B1_IR_CR1INT_MASK) /**< LPC_CT16B1_IR.CR1INT Field              */
/** @} */

/** @name TCR - Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */ /** @{ */
#define LPC_CT16B1_TCR_CEN_MASK                  (0x1U)                                              /**< LPC_CT16B1_TCR.CEN Mask                 */
#define LPC_CT16B1_TCR_CEN_SHIFT                 (0U)                                                /**< LPC_CT16B1_TCR.CEN Position             */
#define LPC_CT16B1_TCR_CEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_TCR_CEN_SHIFT))&LPC_CT16B1_TCR_CEN_MASK) /**< LPC_CT16B1_TCR.CEN Field                */
#define LPC_CT16B1_TCR_CRST_MASK                 (0x2U)                                              /**< LPC_CT16B1_TCR.CRST Mask                */
#define LPC_CT16B1_TCR_CRST_SHIFT                (1U)                                                /**< LPC_CT16B1_TCR.CRST Position            */
#define LPC_CT16B1_TCR_CRST(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_TCR_CRST_SHIFT))&LPC_CT16B1_TCR_CRST_MASK) /**< LPC_CT16B1_TCR.CRST Field               */
/** @} */

/** @name TC - Timer Counter. The 16-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */ /** @{ */
#define LPC_CT16B1_TC_TC_MASK                    (0xFFFFU)                                           /**< LPC_CT16B1_TC.TC Mask                   */
#define LPC_CT16B1_TC_TC_SHIFT                   (0U)                                                /**< LPC_CT16B1_TC.TC Position               */
#define LPC_CT16B1_TC_TC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_TC_TC_SHIFT))&LPC_CT16B1_TC_TC_MASK) /**< LPC_CT16B1_TC.TC Field                  */
/** @} */

/** @name PR - Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */ /** @{ */
#define LPC_CT16B1_PR_PCVAL_MASK                 (0xFFFFU)                                           /**< LPC_CT16B1_PR.PCVAL Mask                */
#define LPC_CT16B1_PR_PCVAL_SHIFT                (0U)                                                /**< LPC_CT16B1_PR.PCVAL Position            */
#define LPC_CT16B1_PR_PCVAL(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_PR_PCVAL_SHIFT))&LPC_CT16B1_PR_PCVAL_MASK) /**< LPC_CT16B1_PR.PCVAL Field               */
/** @} */

/** @name PC - Prescale Counter. The 16-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */ /** @{ */
#define LPC_CT16B1_PC_PC_MASK                    (0xFFFFU)                                           /**< LPC_CT16B1_PC.PC Mask                   */
#define LPC_CT16B1_PC_PC_SHIFT                   (0U)                                                /**< LPC_CT16B1_PC.PC Position               */
#define LPC_CT16B1_PC_PC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_PC_PC_SHIFT))&LPC_CT16B1_PC_PC_MASK) /**< LPC_CT16B1_PC.PC Field                  */
/** @} */

/** @name MCR - Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */ /** @{ */
#define LPC_CT16B1_MCR_MR0I_MASK                 (0x1U)                                              /**< LPC_CT16B1_MCR.MR0I Mask                */
#define LPC_CT16B1_MCR_MR0I_SHIFT                (0U)                                                /**< LPC_CT16B1_MCR.MR0I Position            */
#define LPC_CT16B1_MCR_MR0I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR0I_SHIFT))&LPC_CT16B1_MCR_MR0I_MASK) /**< LPC_CT16B1_MCR.MR0I Field               */
#define LPC_CT16B1_MCR_MR0R_MASK                 (0x2U)                                              /**< LPC_CT16B1_MCR.MR0R Mask                */
#define LPC_CT16B1_MCR_MR0R_SHIFT                (1U)                                                /**< LPC_CT16B1_MCR.MR0R Position            */
#define LPC_CT16B1_MCR_MR0R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR0R_SHIFT))&LPC_CT16B1_MCR_MR0R_MASK) /**< LPC_CT16B1_MCR.MR0R Field               */
#define LPC_CT16B1_MCR_MR0S_MASK                 (0x4U)                                              /**< LPC_CT16B1_MCR.MR0S Mask                */
#define LPC_CT16B1_MCR_MR0S_SHIFT                (2U)                                                /**< LPC_CT16B1_MCR.MR0S Position            */
#define LPC_CT16B1_MCR_MR0S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR0S_SHIFT))&LPC_CT16B1_MCR_MR0S_MASK) /**< LPC_CT16B1_MCR.MR0S Field               */
#define LPC_CT16B1_MCR_MR1I_MASK                 (0x8U)                                              /**< LPC_CT16B1_MCR.MR1I Mask                */
#define LPC_CT16B1_MCR_MR1I_SHIFT                (3U)                                                /**< LPC_CT16B1_MCR.MR1I Position            */
#define LPC_CT16B1_MCR_MR1I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR1I_SHIFT))&LPC_CT16B1_MCR_MR1I_MASK) /**< LPC_CT16B1_MCR.MR1I Field               */
#define LPC_CT16B1_MCR_MR1R_MASK                 (0x10U)                                             /**< LPC_CT16B1_MCR.MR1R Mask                */
#define LPC_CT16B1_MCR_MR1R_SHIFT                (4U)                                                /**< LPC_CT16B1_MCR.MR1R Position            */
#define LPC_CT16B1_MCR_MR1R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR1R_SHIFT))&LPC_CT16B1_MCR_MR1R_MASK) /**< LPC_CT16B1_MCR.MR1R Field               */
#define LPC_CT16B1_MCR_MR1S_MASK                 (0x20U)                                             /**< LPC_CT16B1_MCR.MR1S Mask                */
#define LPC_CT16B1_MCR_MR1S_SHIFT                (5U)                                                /**< LPC_CT16B1_MCR.MR1S Position            */
#define LPC_CT16B1_MCR_MR1S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR1S_SHIFT))&LPC_CT16B1_MCR_MR1S_MASK) /**< LPC_CT16B1_MCR.MR1S Field               */
#define LPC_CT16B1_MCR_MR2I_MASK                 (0x40U)                                             /**< LPC_CT16B1_MCR.MR2I Mask                */
#define LPC_CT16B1_MCR_MR2I_SHIFT                (6U)                                                /**< LPC_CT16B1_MCR.MR2I Position            */
#define LPC_CT16B1_MCR_MR2I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR2I_SHIFT))&LPC_CT16B1_MCR_MR2I_MASK) /**< LPC_CT16B1_MCR.MR2I Field               */
#define LPC_CT16B1_MCR_MR2R_MASK                 (0x80U)                                             /**< LPC_CT16B1_MCR.MR2R Mask                */
#define LPC_CT16B1_MCR_MR2R_SHIFT                (7U)                                                /**< LPC_CT16B1_MCR.MR2R Position            */
#define LPC_CT16B1_MCR_MR2R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR2R_SHIFT))&LPC_CT16B1_MCR_MR2R_MASK) /**< LPC_CT16B1_MCR.MR2R Field               */
#define LPC_CT16B1_MCR_MR2S_MASK                 (0x100U)                                            /**< LPC_CT16B1_MCR.MR2S Mask                */
#define LPC_CT16B1_MCR_MR2S_SHIFT                (8U)                                                /**< LPC_CT16B1_MCR.MR2S Position            */
#define LPC_CT16B1_MCR_MR2S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR2S_SHIFT))&LPC_CT16B1_MCR_MR2S_MASK) /**< LPC_CT16B1_MCR.MR2S Field               */
#define LPC_CT16B1_MCR_MR3I_MASK                 (0x200U)                                            /**< LPC_CT16B1_MCR.MR3I Mask                */
#define LPC_CT16B1_MCR_MR3I_SHIFT                (9U)                                                /**< LPC_CT16B1_MCR.MR3I Position            */
#define LPC_CT16B1_MCR_MR3I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR3I_SHIFT))&LPC_CT16B1_MCR_MR3I_MASK) /**< LPC_CT16B1_MCR.MR3I Field               */
#define LPC_CT16B1_MCR_MR3R_MASK                 (0x400U)                                            /**< LPC_CT16B1_MCR.MR3R Mask                */
#define LPC_CT16B1_MCR_MR3R_SHIFT                (10U)                                               /**< LPC_CT16B1_MCR.MR3R Position            */
#define LPC_CT16B1_MCR_MR3R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR3R_SHIFT))&LPC_CT16B1_MCR_MR3R_MASK) /**< LPC_CT16B1_MCR.MR3R Field               */
#define LPC_CT16B1_MCR_MR3S_MASK                 (0x800U)                                            /**< LPC_CT16B1_MCR.MR3S Mask                */
#define LPC_CT16B1_MCR_MR3S_SHIFT                (11U)                                               /**< LPC_CT16B1_MCR.MR3S Position            */
#define LPC_CT16B1_MCR_MR3S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MCR_MR3S_SHIFT))&LPC_CT16B1_MCR_MR3S_MASK) /**< LPC_CT16B1_MCR.MR3S Field               */
/** @} */

/** @name MR - Match Register %s. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */ /** @{ */
#define LPC_CT16B1_MR_MATCH_MASK                 (0xFFFFU)                                           /**< LPC_CT16B1_MR.MATCH Mask                */
#define LPC_CT16B1_MR_MATCH_SHIFT                (0U)                                                /**< LPC_CT16B1_MR.MATCH Position            */
#define LPC_CT16B1_MR_MATCH(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_MR_MATCH_SHIFT))&LPC_CT16B1_MR_MATCH_MASK) /**< LPC_CT16B1_MR.MATCH Field               */
/** @} */

/** @name CCR - Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */ /** @{ */
#define LPC_CT16B1_CCR_CAP0RE_MASK               (0x1U)                                              /**< LPC_CT16B1_CCR.CAP0RE Mask              */
#define LPC_CT16B1_CCR_CAP0RE_SHIFT              (0U)                                                /**< LPC_CT16B1_CCR.CAP0RE Position          */
#define LPC_CT16B1_CCR_CAP0RE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CCR_CAP0RE_SHIFT))&LPC_CT16B1_CCR_CAP0RE_MASK) /**< LPC_CT16B1_CCR.CAP0RE Field             */
#define LPC_CT16B1_CCR_CAP0FE_MASK               (0x2U)                                              /**< LPC_CT16B1_CCR.CAP0FE Mask              */
#define LPC_CT16B1_CCR_CAP0FE_SHIFT              (1U)                                                /**< LPC_CT16B1_CCR.CAP0FE Position          */
#define LPC_CT16B1_CCR_CAP0FE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CCR_CAP0FE_SHIFT))&LPC_CT16B1_CCR_CAP0FE_MASK) /**< LPC_CT16B1_CCR.CAP0FE Field             */
#define LPC_CT16B1_CCR_CAP0I_MASK                (0x4U)                                              /**< LPC_CT16B1_CCR.CAP0I Mask               */
#define LPC_CT16B1_CCR_CAP0I_SHIFT               (2U)                                                /**< LPC_CT16B1_CCR.CAP0I Position           */
#define LPC_CT16B1_CCR_CAP0I(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CCR_CAP0I_SHIFT))&LPC_CT16B1_CCR_CAP0I_MASK) /**< LPC_CT16B1_CCR.CAP0I Field              */
#define LPC_CT16B1_CCR_CAP1RE_MASK               (0x8U)                                              /**< LPC_CT16B1_CCR.CAP1RE Mask              */
#define LPC_CT16B1_CCR_CAP1RE_SHIFT              (3U)                                                /**< LPC_CT16B1_CCR.CAP1RE Position          */
#define LPC_CT16B1_CCR_CAP1RE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CCR_CAP1RE_SHIFT))&LPC_CT16B1_CCR_CAP1RE_MASK) /**< LPC_CT16B1_CCR.CAP1RE Field             */
#define LPC_CT16B1_CCR_CAP1FE_MASK               (0x10U)                                             /**< LPC_CT16B1_CCR.CAP1FE Mask              */
#define LPC_CT16B1_CCR_CAP1FE_SHIFT              (4U)                                                /**< LPC_CT16B1_CCR.CAP1FE Position          */
#define LPC_CT16B1_CCR_CAP1FE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CCR_CAP1FE_SHIFT))&LPC_CT16B1_CCR_CAP1FE_MASK) /**< LPC_CT16B1_CCR.CAP1FE Field             */
#define LPC_CT16B1_CCR_CAP1I_MASK                (0x20U)                                             /**< LPC_CT16B1_CCR.CAP1I Mask               */
#define LPC_CT16B1_CCR_CAP1I_SHIFT               (5U)                                                /**< LPC_CT16B1_CCR.CAP1I Position           */
#define LPC_CT16B1_CCR_CAP1I(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CCR_CAP1I_SHIFT))&LPC_CT16B1_CCR_CAP1I_MASK) /**< LPC_CT16B1_CCR.CAP1I Field              */
/** @} */

/** @name CR0 - Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT16B0_CAP0 input */ /** @{ */
#define LPC_CT16B1_CR0_CAP_MASK                  (0xFFFFU)                                           /**< LPC_CT16B1_CR0.CAP Mask                 */
#define LPC_CT16B1_CR0_CAP_SHIFT                 (0U)                                                /**< LPC_CT16B1_CR0.CAP Position             */
#define LPC_CT16B1_CR0_CAP(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CR0_CAP_SHIFT))&LPC_CT16B1_CR0_CAP_MASK) /**< LPC_CT16B1_CR0.CAP Field                */
/** @} */

/** @name CR1 - Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT16B1_CAP1 input */ /** @{ */
#define LPC_CT16B1_CR1_CAP_MASK                  (0xFFFFU)                                           /**< LPC_CT16B1_CR1.CAP Mask                 */
#define LPC_CT16B1_CR1_CAP_SHIFT                 (0U)                                                /**< LPC_CT16B1_CR1.CAP Position             */
#define LPC_CT16B1_CR1_CAP(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CR1_CAP_SHIFT))&LPC_CT16B1_CR1_CAP_MASK) /**< LPC_CT16B1_CR1.CAP Field                */
/** @} */

/** @name EMR - External Match Register. The EMR controls the match function and the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */ /** @{ */
#define LPC_CT16B1_EMR_EM0_MASK                  (0x1U)                                              /**< LPC_CT16B1_EMR.EM0 Mask                 */
#define LPC_CT16B1_EMR_EM0_SHIFT                 (0U)                                                /**< LPC_CT16B1_EMR.EM0 Position             */
#define LPC_CT16B1_EMR_EM0(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_EMR_EM0_SHIFT))&LPC_CT16B1_EMR_EM0_MASK) /**< LPC_CT16B1_EMR.EM0 Field                */
#define LPC_CT16B1_EMR_EM1_MASK                  (0x2U)                                              /**< LPC_CT16B1_EMR.EM1 Mask                 */
#define LPC_CT16B1_EMR_EM1_SHIFT                 (1U)                                                /**< LPC_CT16B1_EMR.EM1 Position             */
#define LPC_CT16B1_EMR_EM1(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_EMR_EM1_SHIFT))&LPC_CT16B1_EMR_EM1_MASK) /**< LPC_CT16B1_EMR.EM1 Field                */
#define LPC_CT16B1_EMR_EM2_MASK                  (0x4U)                                              /**< LPC_CT16B1_EMR.EM2 Mask                 */
#define LPC_CT16B1_EMR_EM2_SHIFT                 (2U)                                                /**< LPC_CT16B1_EMR.EM2 Position             */
#define LPC_CT16B1_EMR_EM2(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_EMR_EM2_SHIFT))&LPC_CT16B1_EMR_EM2_MASK) /**< LPC_CT16B1_EMR.EM2 Field                */
#define LPC_CT16B1_EMR_EM3_MASK                  (0x8U)                                              /**< LPC_CT16B1_EMR.EM3 Mask                 */
#define LPC_CT16B1_EMR_EM3_SHIFT                 (3U)                                                /**< LPC_CT16B1_EMR.EM3 Position             */
#define LPC_CT16B1_EMR_EM3(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_EMR_EM3_SHIFT))&LPC_CT16B1_EMR_EM3_MASK) /**< LPC_CT16B1_EMR.EM3 Field                */
#define LPC_CT16B1_EMR_EMC0_MASK                 (0x30U)                                             /**< LPC_CT16B1_EMR.EMC0 Mask                */
#define LPC_CT16B1_EMR_EMC0_SHIFT                (4U)                                                /**< LPC_CT16B1_EMR.EMC0 Position            */
#define LPC_CT16B1_EMR_EMC0(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_EMR_EMC0_SHIFT))&LPC_CT16B1_EMR_EMC0_MASK) /**< LPC_CT16B1_EMR.EMC0 Field               */
#define LPC_CT16B1_EMR_EMC1_MASK                 (0xC0U)                                             /**< LPC_CT16B1_EMR.EMC1 Mask                */
#define LPC_CT16B1_EMR_EMC1_SHIFT                (6U)                                                /**< LPC_CT16B1_EMR.EMC1 Position            */
#define LPC_CT16B1_EMR_EMC1(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_EMR_EMC1_SHIFT))&LPC_CT16B1_EMR_EMC1_MASK) /**< LPC_CT16B1_EMR.EMC1 Field               */
#define LPC_CT16B1_EMR_EMC2_MASK                 (0x300U)                                            /**< LPC_CT16B1_EMR.EMC2 Mask                */
#define LPC_CT16B1_EMR_EMC2_SHIFT                (8U)                                                /**< LPC_CT16B1_EMR.EMC2 Position            */
#define LPC_CT16B1_EMR_EMC2(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_EMR_EMC2_SHIFT))&LPC_CT16B1_EMR_EMC2_MASK) /**< LPC_CT16B1_EMR.EMC2 Field               */
#define LPC_CT16B1_EMR_EMC3_MASK                 (0xC00U)                                            /**< LPC_CT16B1_EMR.EMC3 Mask                */
#define LPC_CT16B1_EMR_EMC3_SHIFT                (10U)                                               /**< LPC_CT16B1_EMR.EMC3 Position            */
#define LPC_CT16B1_EMR_EMC3(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_EMR_EMC3_SHIFT))&LPC_CT16B1_EMR_EMC3_MASK) /**< LPC_CT16B1_EMR.EMC3 Field               */
/** @} */

/** @name CTCR - Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */ /** @{ */
#define LPC_CT16B1_CTCR_CTM_MASK                 (0x3U)                                              /**< LPC_CT16B1_CTCR.CTM Mask                */
#define LPC_CT16B1_CTCR_CTM_SHIFT                (0U)                                                /**< LPC_CT16B1_CTCR.CTM Position            */
#define LPC_CT16B1_CTCR_CTM(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CTCR_CTM_SHIFT))&LPC_CT16B1_CTCR_CTM_MASK) /**< LPC_CT16B1_CTCR.CTM Field               */
#define LPC_CT16B1_CTCR_CIS_MASK                 (0xCU)                                              /**< LPC_CT16B1_CTCR.CIS Mask                */
#define LPC_CT16B1_CTCR_CIS_SHIFT                (2U)                                                /**< LPC_CT16B1_CTCR.CIS Position            */
#define LPC_CT16B1_CTCR_CIS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CTCR_CIS_SHIFT))&LPC_CT16B1_CTCR_CIS_MASK) /**< LPC_CT16B1_CTCR.CIS Field               */
#define LPC_CT16B1_CTCR_ENCC_MASK                (0x10U)                                             /**< LPC_CT16B1_CTCR.ENCC Mask               */
#define LPC_CT16B1_CTCR_ENCC_SHIFT               (4U)                                                /**< LPC_CT16B1_CTCR.ENCC Position           */
#define LPC_CT16B1_CTCR_ENCC(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CTCR_ENCC_SHIFT))&LPC_CT16B1_CTCR_ENCC_MASK) /**< LPC_CT16B1_CTCR.ENCC Field              */
#define LPC_CT16B1_CTCR_SELCC_MASK               (0xE0U)                                             /**< LPC_CT16B1_CTCR.SELCC Mask              */
#define LPC_CT16B1_CTCR_SELCC_SHIFT              (5U)                                                /**< LPC_CT16B1_CTCR.SELCC Position          */
#define LPC_CT16B1_CTCR_SELCC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_CTCR_SELCC_SHIFT))&LPC_CT16B1_CTCR_SELCC_MASK) /**< LPC_CT16B1_CTCR.SELCC Field             */
/** @} */

/** @name PWMC - PWM Control Register. The PWMCON enables PWM mode for the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */ /** @{ */
#define LPC_CT16B1_PWMC_PWMEN0_MASK              (0x1U)                                              /**< LPC_CT16B1_PWMC.PWMEN0 Mask             */
#define LPC_CT16B1_PWMC_PWMEN0_SHIFT             (0U)                                                /**< LPC_CT16B1_PWMC.PWMEN0 Position         */
#define LPC_CT16B1_PWMC_PWMEN0(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_PWMC_PWMEN0_SHIFT))&LPC_CT16B1_PWMC_PWMEN0_MASK) /**< LPC_CT16B1_PWMC.PWMEN0 Field            */
#define LPC_CT16B1_PWMC_PWMEN1_MASK              (0x2U)                                              /**< LPC_CT16B1_PWMC.PWMEN1 Mask             */
#define LPC_CT16B1_PWMC_PWMEN1_SHIFT             (1U)                                                /**< LPC_CT16B1_PWMC.PWMEN1 Position         */
#define LPC_CT16B1_PWMC_PWMEN1(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_PWMC_PWMEN1_SHIFT))&LPC_CT16B1_PWMC_PWMEN1_MASK) /**< LPC_CT16B1_PWMC.PWMEN1 Field            */
#define LPC_CT16B1_PWMC_PWMEN2_MASK              (0x4U)                                              /**< LPC_CT16B1_PWMC.PWMEN2 Mask             */
#define LPC_CT16B1_PWMC_PWMEN2_SHIFT             (2U)                                                /**< LPC_CT16B1_PWMC.PWMEN2 Position         */
#define LPC_CT16B1_PWMC_PWMEN2(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_PWMC_PWMEN2_SHIFT))&LPC_CT16B1_PWMC_PWMEN2_MASK) /**< LPC_CT16B1_PWMC.PWMEN2 Field            */
#define LPC_CT16B1_PWMC_PWMEN3_MASK              (0x8U)                                              /**< LPC_CT16B1_PWMC.PWMEN3 Mask             */
#define LPC_CT16B1_PWMC_PWMEN3_SHIFT             (3U)                                                /**< LPC_CT16B1_PWMC.PWMEN3 Position         */
#define LPC_CT16B1_PWMC_PWMEN3(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT16B1_PWMC_PWMEN3_SHIFT))&LPC_CT16B1_PWMC_PWMEN3_MASK) /**< LPC_CT16B1_PWMC.PWMEN3 Field            */
/** @} */

/** @} */ /* End group CT16B_Register_Masks_GROUP */


/* LPC_CT16B1 - Peripheral instance base addresses */
#define LPC_CT16B1_BasePtr             0x40010000UL //!< Peripheral base address
#define LPC_CT16B1                     ((LPC_CT16B1_Type *) LPC_CT16B1_BasePtr) //!< Freescale base pointer
#define LPC_CT16B1_BASE_PTR            (LPC_CT16B1) //!< Freescale style base pointer

/** @} */ /* End group CT16B_Peripheral_access_layer_GROUP */


/** @brief C Struct for CT32B0 */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup CT32B0_Peripheral_access_layer_GROUP CT32B0 Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_CT32B0 (file:CT32B0_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief 32-bit counter/timers CT32B0
 */
/**
 * @struct LPC_CT32B0_Type
 * @brief  C Struct allowing access to CT32B0 registers
 */
typedef struct LPC_CT32B0_Type {
   __IO uint32_t  IR;                           /**< 0000: Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */
   __IO uint32_t  TCR;                          /**< 0004: Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  TC;                           /**< 0008: Timer Counter. The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  PR;                           /**< 000C: Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  PC;                           /**< 0010: Prescale Counter. The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  MCR;                          /**< 0014: Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  MR[4];                        /**< 0018: Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */
   __IO uint32_t  CCR;                          /**< 0028: Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  CR0;                          /**< 002C: Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT32B0_CAP0 input */
        uint8_t   RESERVED_0[4];                /**< 0030: 0x4 bytes                                                    */
   __IO uint32_t  CR1;                          /**< 0034: Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT32B0_CAP1 input */
        uint8_t   RESERVED_1[4];                /**< 0038: 0x4 bytes                                                    */
   __IO uint32_t  EMR;                          /**< 003C: External Match Register. The EMR controls the match function and the external match pins CT32Bn_MAT[3:0] */
        uint8_t   RESERVED_2[48];               /**< 0040: 0x30 bytes                                                   */
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register. The PWMCON enables PWM mode for the external match pins CT32Bn_MAT[3:0] */
} LPC_CT32B0_Type;


/** @brief Register Masks for CT32B0 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_CT32B0' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup CT32B0_Register_Masks_GROUP CT32B0 Register Masks */
/** @{ */

/** @name IR - Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */ /** @{ */
#define LPC_CT32B0_IR_MR0INT_MASK                (0x1U)                                              /**< LPC_CT32B0_IR.MR0INT Mask               */
#define LPC_CT32B0_IR_MR0INT_SHIFT               (0U)                                                /**< LPC_CT32B0_IR.MR0INT Position           */
#define LPC_CT32B0_IR_MR0INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_IR_MR0INT_SHIFT))&LPC_CT32B0_IR_MR0INT_MASK) /**< LPC_CT32B0_IR.MR0INT Field              */
#define LPC_CT32B0_IR_MR1INT_MASK                (0x2U)                                              /**< LPC_CT32B0_IR.MR1INT Mask               */
#define LPC_CT32B0_IR_MR1INT_SHIFT               (1U)                                                /**< LPC_CT32B0_IR.MR1INT Position           */
#define LPC_CT32B0_IR_MR1INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_IR_MR1INT_SHIFT))&LPC_CT32B0_IR_MR1INT_MASK) /**< LPC_CT32B0_IR.MR1INT Field              */
#define LPC_CT32B0_IR_MR2INT_MASK                (0x4U)                                              /**< LPC_CT32B0_IR.MR2INT Mask               */
#define LPC_CT32B0_IR_MR2INT_SHIFT               (2U)                                                /**< LPC_CT32B0_IR.MR2INT Position           */
#define LPC_CT32B0_IR_MR2INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_IR_MR2INT_SHIFT))&LPC_CT32B0_IR_MR2INT_MASK) /**< LPC_CT32B0_IR.MR2INT Field              */
#define LPC_CT32B0_IR_MR3INT_MASK                (0x8U)                                              /**< LPC_CT32B0_IR.MR3INT Mask               */
#define LPC_CT32B0_IR_MR3INT_SHIFT               (3U)                                                /**< LPC_CT32B0_IR.MR3INT Position           */
#define LPC_CT32B0_IR_MR3INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_IR_MR3INT_SHIFT))&LPC_CT32B0_IR_MR3INT_MASK) /**< LPC_CT32B0_IR.MR3INT Field              */
#define LPC_CT32B0_IR_CR0INT_MASK                (0x10U)                                             /**< LPC_CT32B0_IR.CR0INT Mask               */
#define LPC_CT32B0_IR_CR0INT_SHIFT               (4U)                                                /**< LPC_CT32B0_IR.CR0INT Position           */
#define LPC_CT32B0_IR_CR0INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_IR_CR0INT_SHIFT))&LPC_CT32B0_IR_CR0INT_MASK) /**< LPC_CT32B0_IR.CR0INT Field              */
#define LPC_CT32B0_IR_CR1INT_MASK                (0x40U)                                             /**< LPC_CT32B0_IR.CR1INT Mask               */
#define LPC_CT32B0_IR_CR1INT_SHIFT               (6U)                                                /**< LPC_CT32B0_IR.CR1INT Position           */
#define LPC_CT32B0_IR_CR1INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_IR_CR1INT_SHIFT))&LPC_CT32B0_IR_CR1INT_MASK) /**< LPC_CT32B0_IR.CR1INT Field              */
/** @} */

/** @name TCR - Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */ /** @{ */
#define LPC_CT32B0_TCR_CEN_MASK                  (0x1U)                                              /**< LPC_CT32B0_TCR.CEN Mask                 */
#define LPC_CT32B0_TCR_CEN_SHIFT                 (0U)                                                /**< LPC_CT32B0_TCR.CEN Position             */
#define LPC_CT32B0_TCR_CEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_TCR_CEN_SHIFT))&LPC_CT32B0_TCR_CEN_MASK) /**< LPC_CT32B0_TCR.CEN Field                */
#define LPC_CT32B0_TCR_CRST_MASK                 (0x2U)                                              /**< LPC_CT32B0_TCR.CRST Mask                */
#define LPC_CT32B0_TCR_CRST_SHIFT                (1U)                                                /**< LPC_CT32B0_TCR.CRST Position            */
#define LPC_CT32B0_TCR_CRST(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_TCR_CRST_SHIFT))&LPC_CT32B0_TCR_CRST_MASK) /**< LPC_CT32B0_TCR.CRST Field               */
/** @} */

/** @name TC - Timer Counter. The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */ /** @{ */
#define LPC_CT32B0_TC_TC_MASK                    (0xFFFFFFFFU)                                       /**< LPC_CT32B0_TC.TC Mask                   */
#define LPC_CT32B0_TC_TC_SHIFT                   (0U)                                                /**< LPC_CT32B0_TC.TC Position               */
#define LPC_CT32B0_TC_TC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_TC_TC_SHIFT))&LPC_CT32B0_TC_TC_MASK) /**< LPC_CT32B0_TC.TC Field                  */
/** @} */

/** @name PR - Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */ /** @{ */
#define LPC_CT32B0_PR_PCVAL_MASK                 (0xFFFFFFFFU)                                       /**< LPC_CT32B0_PR.PCVAL Mask                */
#define LPC_CT32B0_PR_PCVAL_SHIFT                (0U)                                                /**< LPC_CT32B0_PR.PCVAL Position            */
#define LPC_CT32B0_PR_PCVAL(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_PR_PCVAL_SHIFT))&LPC_CT32B0_PR_PCVAL_MASK) /**< LPC_CT32B0_PR.PCVAL Field               */
/** @} */

/** @name PC - Prescale Counter. The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */ /** @{ */
#define LPC_CT32B0_PC_PC_MASK                    (0xFFFFFFFFU)                                       /**< LPC_CT32B0_PC.PC Mask                   */
#define LPC_CT32B0_PC_PC_SHIFT                   (0U)                                                /**< LPC_CT32B0_PC.PC Position               */
#define LPC_CT32B0_PC_PC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_PC_PC_SHIFT))&LPC_CT32B0_PC_PC_MASK) /**< LPC_CT32B0_PC.PC Field                  */
/** @} */

/** @name MCR - Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */ /** @{ */
#define LPC_CT32B0_MCR_MR0I_MASK                 (0x1U)                                              /**< LPC_CT32B0_MCR.MR0I Mask                */
#define LPC_CT32B0_MCR_MR0I_SHIFT                (0U)                                                /**< LPC_CT32B0_MCR.MR0I Position            */
#define LPC_CT32B0_MCR_MR0I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR0I_SHIFT))&LPC_CT32B0_MCR_MR0I_MASK) /**< LPC_CT32B0_MCR.MR0I Field               */
#define LPC_CT32B0_MCR_MR0R_MASK                 (0x2U)                                              /**< LPC_CT32B0_MCR.MR0R Mask                */
#define LPC_CT32B0_MCR_MR0R_SHIFT                (1U)                                                /**< LPC_CT32B0_MCR.MR0R Position            */
#define LPC_CT32B0_MCR_MR0R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR0R_SHIFT))&LPC_CT32B0_MCR_MR0R_MASK) /**< LPC_CT32B0_MCR.MR0R Field               */
#define LPC_CT32B0_MCR_MR0S_MASK                 (0x4U)                                              /**< LPC_CT32B0_MCR.MR0S Mask                */
#define LPC_CT32B0_MCR_MR0S_SHIFT                (2U)                                                /**< LPC_CT32B0_MCR.MR0S Position            */
#define LPC_CT32B0_MCR_MR0S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR0S_SHIFT))&LPC_CT32B0_MCR_MR0S_MASK) /**< LPC_CT32B0_MCR.MR0S Field               */
#define LPC_CT32B0_MCR_MR1I_MASK                 (0x8U)                                              /**< LPC_CT32B0_MCR.MR1I Mask                */
#define LPC_CT32B0_MCR_MR1I_SHIFT                (3U)                                                /**< LPC_CT32B0_MCR.MR1I Position            */
#define LPC_CT32B0_MCR_MR1I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR1I_SHIFT))&LPC_CT32B0_MCR_MR1I_MASK) /**< LPC_CT32B0_MCR.MR1I Field               */
#define LPC_CT32B0_MCR_MR1R_MASK                 (0x10U)                                             /**< LPC_CT32B0_MCR.MR1R Mask                */
#define LPC_CT32B0_MCR_MR1R_SHIFT                (4U)                                                /**< LPC_CT32B0_MCR.MR1R Position            */
#define LPC_CT32B0_MCR_MR1R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR1R_SHIFT))&LPC_CT32B0_MCR_MR1R_MASK) /**< LPC_CT32B0_MCR.MR1R Field               */
#define LPC_CT32B0_MCR_MR1S_MASK                 (0x20U)                                             /**< LPC_CT32B0_MCR.MR1S Mask                */
#define LPC_CT32B0_MCR_MR1S_SHIFT                (5U)                                                /**< LPC_CT32B0_MCR.MR1S Position            */
#define LPC_CT32B0_MCR_MR1S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR1S_SHIFT))&LPC_CT32B0_MCR_MR1S_MASK) /**< LPC_CT32B0_MCR.MR1S Field               */
#define LPC_CT32B0_MCR_MR2I_MASK                 (0x40U)                                             /**< LPC_CT32B0_MCR.MR2I Mask                */
#define LPC_CT32B0_MCR_MR2I_SHIFT                (6U)                                                /**< LPC_CT32B0_MCR.MR2I Position            */
#define LPC_CT32B0_MCR_MR2I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR2I_SHIFT))&LPC_CT32B0_MCR_MR2I_MASK) /**< LPC_CT32B0_MCR.MR2I Field               */
#define LPC_CT32B0_MCR_MR2R_MASK                 (0x80U)                                             /**< LPC_CT32B0_MCR.MR2R Mask                */
#define LPC_CT32B0_MCR_MR2R_SHIFT                (7U)                                                /**< LPC_CT32B0_MCR.MR2R Position            */
#define LPC_CT32B0_MCR_MR2R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR2R_SHIFT))&LPC_CT32B0_MCR_MR2R_MASK) /**< LPC_CT32B0_MCR.MR2R Field               */
#define LPC_CT32B0_MCR_MR2S_MASK                 (0x100U)                                            /**< LPC_CT32B0_MCR.MR2S Mask                */
#define LPC_CT32B0_MCR_MR2S_SHIFT                (8U)                                                /**< LPC_CT32B0_MCR.MR2S Position            */
#define LPC_CT32B0_MCR_MR2S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR2S_SHIFT))&LPC_CT32B0_MCR_MR2S_MASK) /**< LPC_CT32B0_MCR.MR2S Field               */
#define LPC_CT32B0_MCR_MR3I_MASK                 (0x200U)                                            /**< LPC_CT32B0_MCR.MR3I Mask                */
#define LPC_CT32B0_MCR_MR3I_SHIFT                (9U)                                                /**< LPC_CT32B0_MCR.MR3I Position            */
#define LPC_CT32B0_MCR_MR3I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR3I_SHIFT))&LPC_CT32B0_MCR_MR3I_MASK) /**< LPC_CT32B0_MCR.MR3I Field               */
#define LPC_CT32B0_MCR_MR3R_MASK                 (0x400U)                                            /**< LPC_CT32B0_MCR.MR3R Mask                */
#define LPC_CT32B0_MCR_MR3R_SHIFT                (10U)                                               /**< LPC_CT32B0_MCR.MR3R Position            */
#define LPC_CT32B0_MCR_MR3R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR3R_SHIFT))&LPC_CT32B0_MCR_MR3R_MASK) /**< LPC_CT32B0_MCR.MR3R Field               */
#define LPC_CT32B0_MCR_MR3S_MASK                 (0x800U)                                            /**< LPC_CT32B0_MCR.MR3S Mask                */
#define LPC_CT32B0_MCR_MR3S_SHIFT                (11U)                                               /**< LPC_CT32B0_MCR.MR3S Position            */
#define LPC_CT32B0_MCR_MR3S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MCR_MR3S_SHIFT))&LPC_CT32B0_MCR_MR3S_MASK) /**< LPC_CT32B0_MCR.MR3S Field               */
/** @} */

/** @name MR - Match Register %s. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */ /** @{ */
#define LPC_CT32B0_MR_MATCH_MASK                 (0xFFFFFFFFU)                                       /**< LPC_CT32B0_MR.MATCH Mask                */
#define LPC_CT32B0_MR_MATCH_SHIFT                (0U)                                                /**< LPC_CT32B0_MR.MATCH Position            */
#define LPC_CT32B0_MR_MATCH(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_MR_MATCH_SHIFT))&LPC_CT32B0_MR_MATCH_MASK) /**< LPC_CT32B0_MR.MATCH Field               */
/** @} */

/** @name CCR - Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */ /** @{ */
#define LPC_CT32B0_CCR_CAP0RE_MASK               (0x1U)                                              /**< LPC_CT32B0_CCR.CAP0RE Mask              */
#define LPC_CT32B0_CCR_CAP0RE_SHIFT              (0U)                                                /**< LPC_CT32B0_CCR.CAP0RE Position          */
#define LPC_CT32B0_CCR_CAP0RE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CCR_CAP0RE_SHIFT))&LPC_CT32B0_CCR_CAP0RE_MASK) /**< LPC_CT32B0_CCR.CAP0RE Field             */
#define LPC_CT32B0_CCR_CAP0FE_MASK               (0x2U)                                              /**< LPC_CT32B0_CCR.CAP0FE Mask              */
#define LPC_CT32B0_CCR_CAP0FE_SHIFT              (1U)                                                /**< LPC_CT32B0_CCR.CAP0FE Position          */
#define LPC_CT32B0_CCR_CAP0FE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CCR_CAP0FE_SHIFT))&LPC_CT32B0_CCR_CAP0FE_MASK) /**< LPC_CT32B0_CCR.CAP0FE Field             */
#define LPC_CT32B0_CCR_CAP0I_MASK                (0x4U)                                              /**< LPC_CT32B0_CCR.CAP0I Mask               */
#define LPC_CT32B0_CCR_CAP0I_SHIFT               (2U)                                                /**< LPC_CT32B0_CCR.CAP0I Position           */
#define LPC_CT32B0_CCR_CAP0I(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CCR_CAP0I_SHIFT))&LPC_CT32B0_CCR_CAP0I_MASK) /**< LPC_CT32B0_CCR.CAP0I Field              */
#define LPC_CT32B0_CCR_CAP1RE_MASK               (0x40U)                                             /**< LPC_CT32B0_CCR.CAP1RE Mask              */
#define LPC_CT32B0_CCR_CAP1RE_SHIFT              (6U)                                                /**< LPC_CT32B0_CCR.CAP1RE Position          */
#define LPC_CT32B0_CCR_CAP1RE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CCR_CAP1RE_SHIFT))&LPC_CT32B0_CCR_CAP1RE_MASK) /**< LPC_CT32B0_CCR.CAP1RE Field             */
#define LPC_CT32B0_CCR_CAP1FE_MASK               (0x80U)                                             /**< LPC_CT32B0_CCR.CAP1FE Mask              */
#define LPC_CT32B0_CCR_CAP1FE_SHIFT              (7U)                                                /**< LPC_CT32B0_CCR.CAP1FE Position          */
#define LPC_CT32B0_CCR_CAP1FE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CCR_CAP1FE_SHIFT))&LPC_CT32B0_CCR_CAP1FE_MASK) /**< LPC_CT32B0_CCR.CAP1FE Field             */
#define LPC_CT32B0_CCR_CAP1I_MASK                (0x100U)                                            /**< LPC_CT32B0_CCR.CAP1I Mask               */
#define LPC_CT32B0_CCR_CAP1I_SHIFT               (8U)                                                /**< LPC_CT32B0_CCR.CAP1I Position           */
#define LPC_CT32B0_CCR_CAP1I(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CCR_CAP1I_SHIFT))&LPC_CT32B0_CCR_CAP1I_MASK) /**< LPC_CT32B0_CCR.CAP1I Field              */
/** @} */

/** @name CR0 - Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT32B0_CAP0 input */ /** @{ */
#define LPC_CT32B0_CR0_CAP_MASK                  (0xFFFFFFFFU)                                       /**< LPC_CT32B0_CR0.CAP Mask                 */
#define LPC_CT32B0_CR0_CAP_SHIFT                 (0U)                                                /**< LPC_CT32B0_CR0.CAP Position             */
#define LPC_CT32B0_CR0_CAP(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CR0_CAP_SHIFT))&LPC_CT32B0_CR0_CAP_MASK) /**< LPC_CT32B0_CR0.CAP Field                */
/** @} */

/** @name CR1 - Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT32B0_CAP1 input */ /** @{ */
#define LPC_CT32B0_CR1_CAP_MASK                  (0xFFFFFFFFU)                                       /**< LPC_CT32B0_CR1.CAP Mask                 */
#define LPC_CT32B0_CR1_CAP_SHIFT                 (0U)                                                /**< LPC_CT32B0_CR1.CAP Position             */
#define LPC_CT32B0_CR1_CAP(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CR1_CAP_SHIFT))&LPC_CT32B0_CR1_CAP_MASK) /**< LPC_CT32B0_CR1.CAP Field                */
/** @} */

/** @name EMR - External Match Register. The EMR controls the match function and the external match pins CT32Bn_MAT[3:0] */ /** @{ */
#define LPC_CT32B0_EMR_EM0_MASK                  (0x1U)                                              /**< LPC_CT32B0_EMR.EM0 Mask                 */
#define LPC_CT32B0_EMR_EM0_SHIFT                 (0U)                                                /**< LPC_CT32B0_EMR.EM0 Position             */
#define LPC_CT32B0_EMR_EM0(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_EMR_EM0_SHIFT))&LPC_CT32B0_EMR_EM0_MASK) /**< LPC_CT32B0_EMR.EM0 Field                */
#define LPC_CT32B0_EMR_EM1_MASK                  (0x2U)                                              /**< LPC_CT32B0_EMR.EM1 Mask                 */
#define LPC_CT32B0_EMR_EM1_SHIFT                 (1U)                                                /**< LPC_CT32B0_EMR.EM1 Position             */
#define LPC_CT32B0_EMR_EM1(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_EMR_EM1_SHIFT))&LPC_CT32B0_EMR_EM1_MASK) /**< LPC_CT32B0_EMR.EM1 Field                */
#define LPC_CT32B0_EMR_EM2_MASK                  (0x4U)                                              /**< LPC_CT32B0_EMR.EM2 Mask                 */
#define LPC_CT32B0_EMR_EM2_SHIFT                 (2U)                                                /**< LPC_CT32B0_EMR.EM2 Position             */
#define LPC_CT32B0_EMR_EM2(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_EMR_EM2_SHIFT))&LPC_CT32B0_EMR_EM2_MASK) /**< LPC_CT32B0_EMR.EM2 Field                */
#define LPC_CT32B0_EMR_EM3_MASK                  (0x8U)                                              /**< LPC_CT32B0_EMR.EM3 Mask                 */
#define LPC_CT32B0_EMR_EM3_SHIFT                 (3U)                                                /**< LPC_CT32B0_EMR.EM3 Position             */
#define LPC_CT32B0_EMR_EM3(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_EMR_EM3_SHIFT))&LPC_CT32B0_EMR_EM3_MASK) /**< LPC_CT32B0_EMR.EM3 Field                */
#define LPC_CT32B0_EMR_EMC0_MASK                 (0x30U)                                             /**< LPC_CT32B0_EMR.EMC0 Mask                */
#define LPC_CT32B0_EMR_EMC0_SHIFT                (4U)                                                /**< LPC_CT32B0_EMR.EMC0 Position            */
#define LPC_CT32B0_EMR_EMC0(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_EMR_EMC0_SHIFT))&LPC_CT32B0_EMR_EMC0_MASK) /**< LPC_CT32B0_EMR.EMC0 Field               */
#define LPC_CT32B0_EMR_EMC1_MASK                 (0xC0U)                                             /**< LPC_CT32B0_EMR.EMC1 Mask                */
#define LPC_CT32B0_EMR_EMC1_SHIFT                (6U)                                                /**< LPC_CT32B0_EMR.EMC1 Position            */
#define LPC_CT32B0_EMR_EMC1(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_EMR_EMC1_SHIFT))&LPC_CT32B0_EMR_EMC1_MASK) /**< LPC_CT32B0_EMR.EMC1 Field               */
#define LPC_CT32B0_EMR_EMC2_MASK                 (0x300U)                                            /**< LPC_CT32B0_EMR.EMC2 Mask                */
#define LPC_CT32B0_EMR_EMC2_SHIFT                (8U)                                                /**< LPC_CT32B0_EMR.EMC2 Position            */
#define LPC_CT32B0_EMR_EMC2(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_EMR_EMC2_SHIFT))&LPC_CT32B0_EMR_EMC2_MASK) /**< LPC_CT32B0_EMR.EMC2 Field               */
#define LPC_CT32B0_EMR_EMC3_MASK                 (0xC00U)                                            /**< LPC_CT32B0_EMR.EMC3 Mask                */
#define LPC_CT32B0_EMR_EMC3_SHIFT                (10U)                                               /**< LPC_CT32B0_EMR.EMC3 Position            */
#define LPC_CT32B0_EMR_EMC3(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_EMR_EMC3_SHIFT))&LPC_CT32B0_EMR_EMC3_MASK) /**< LPC_CT32B0_EMR.EMC3 Field               */
/** @} */

/** @name CTCR - Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */ /** @{ */
#define LPC_CT32B0_CTCR_CTM_MASK                 (0x3U)                                              /**< LPC_CT32B0_CTCR.CTM Mask                */
#define LPC_CT32B0_CTCR_CTM_SHIFT                (0U)                                                /**< LPC_CT32B0_CTCR.CTM Position            */
#define LPC_CT32B0_CTCR_CTM(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CTCR_CTM_SHIFT))&LPC_CT32B0_CTCR_CTM_MASK) /**< LPC_CT32B0_CTCR.CTM Field               */
#define LPC_CT32B0_CTCR_CIS_MASK                 (0xCU)                                              /**< LPC_CT32B0_CTCR.CIS Mask                */
#define LPC_CT32B0_CTCR_CIS_SHIFT                (2U)                                                /**< LPC_CT32B0_CTCR.CIS Position            */
#define LPC_CT32B0_CTCR_CIS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CTCR_CIS_SHIFT))&LPC_CT32B0_CTCR_CIS_MASK) /**< LPC_CT32B0_CTCR.CIS Field               */
#define LPC_CT32B0_CTCR_ENCC_MASK                (0x10U)                                             /**< LPC_CT32B0_CTCR.ENCC Mask               */
#define LPC_CT32B0_CTCR_ENCC_SHIFT               (4U)                                                /**< LPC_CT32B0_CTCR.ENCC Position           */
#define LPC_CT32B0_CTCR_ENCC(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CTCR_ENCC_SHIFT))&LPC_CT32B0_CTCR_ENCC_MASK) /**< LPC_CT32B0_CTCR.ENCC Field              */
#define LPC_CT32B0_CTCR_SElCC_MASK               (0xE0U)                                             /**< LPC_CT32B0_CTCR.SElCC Mask              */
#define LPC_CT32B0_CTCR_SElCC_SHIFT              (5U)                                                /**< LPC_CT32B0_CTCR.SElCC Position          */
#define LPC_CT32B0_CTCR_SElCC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_CTCR_SElCC_SHIFT))&LPC_CT32B0_CTCR_SElCC_MASK) /**< LPC_CT32B0_CTCR.SElCC Field             */
/** @} */

/** @name PWMC - PWM Control Register. The PWMCON enables PWM mode for the external match pins CT32Bn_MAT[3:0] */ /** @{ */
#define LPC_CT32B0_PWMC_PWMEN0_MASK              (0x1U)                                              /**< LPC_CT32B0_PWMC.PWMEN0 Mask             */
#define LPC_CT32B0_PWMC_PWMEN0_SHIFT             (0U)                                                /**< LPC_CT32B0_PWMC.PWMEN0 Position         */
#define LPC_CT32B0_PWMC_PWMEN0(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_PWMC_PWMEN0_SHIFT))&LPC_CT32B0_PWMC_PWMEN0_MASK) /**< LPC_CT32B0_PWMC.PWMEN0 Field            */
#define LPC_CT32B0_PWMC_PWMEN1_MASK              (0x2U)                                              /**< LPC_CT32B0_PWMC.PWMEN1 Mask             */
#define LPC_CT32B0_PWMC_PWMEN1_SHIFT             (1U)                                                /**< LPC_CT32B0_PWMC.PWMEN1 Position         */
#define LPC_CT32B0_PWMC_PWMEN1(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_PWMC_PWMEN1_SHIFT))&LPC_CT32B0_PWMC_PWMEN1_MASK) /**< LPC_CT32B0_PWMC.PWMEN1 Field            */
#define LPC_CT32B0_PWMC_PWMEN2_MASK              (0x4U)                                              /**< LPC_CT32B0_PWMC.PWMEN2 Mask             */
#define LPC_CT32B0_PWMC_PWMEN2_SHIFT             (2U)                                                /**< LPC_CT32B0_PWMC.PWMEN2 Position         */
#define LPC_CT32B0_PWMC_PWMEN2(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_PWMC_PWMEN2_SHIFT))&LPC_CT32B0_PWMC_PWMEN2_MASK) /**< LPC_CT32B0_PWMC.PWMEN2 Field            */
#define LPC_CT32B0_PWMC_PWMEN3_MASK              (0x8U)                                              /**< LPC_CT32B0_PWMC.PWMEN3 Mask             */
#define LPC_CT32B0_PWMC_PWMEN3_SHIFT             (3U)                                                /**< LPC_CT32B0_PWMC.PWMEN3 Position         */
#define LPC_CT32B0_PWMC_PWMEN3(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT32B0_PWMC_PWMEN3_SHIFT))&LPC_CT32B0_PWMC_PWMEN3_MASK) /**< LPC_CT32B0_PWMC.PWMEN3 Field            */
/** @} */

/** @} */ /* End group CT32B0_Register_Masks_GROUP */


/* LPC_CT32B0 - Peripheral instance base addresses */
#define LPC_CT32B0_BasePtr             0x40014000UL //!< Peripheral base address
#define LPC_CT32B0                     ((LPC_CT32B0_Type *) LPC_CT32B0_BasePtr) //!< Freescale base pointer
#define LPC_CT32B0_BASE_PTR            (LPC_CT32B0) //!< Freescale style base pointer

/** @} */ /* End group CT32B0_Peripheral_access_layer_GROUP */


/** @brief C Struct for CT32B */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup CT32B_Peripheral_access_layer_GROUP CT32B Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_CT32B1 (file:CT32B1_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief 32-bit counter/timers CT32B1
 */
/**
 * @struct LPC_CT32B1_Type
 * @brief  C Struct allowing access to CT32B registers
 */
typedef struct LPC_CT32B1_Type {
   __IO uint32_t  IR;                           /**< 0000: Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */
   __IO uint32_t  TCR;                          /**< 0004: Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  TC;                           /**< 0008: Timer Counter. The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  PR;                           /**< 000C: Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  PC;                           /**< 0010: Prescale Counter. The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  MCR;                          /**< 0014: Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  MR[4];                        /**< 0018: Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */
   __IO uint32_t  CCR;                          /**< 0028: Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  CR0;                          /**< 002C: Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT32B0_CAP0 input */
   __IO uint32_t  CR1;                          /**< 0030: Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT32B1_CAP1 input */
        uint8_t   RESERVED_0[8];                /**< 0034: 0x8 bytes                                                    */
   __IO uint32_t  EMR;                          /**< 003C: External Match Register. The EMR controls the match function and the external match pins CT32Bn_MAT[3:0] */
        uint8_t   RESERVED_1[48];               /**< 0040: 0x30 bytes                                                   */
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register. The PWMCON enables PWM mode for the external match pins CT32Bn_MAT[3:0] */
} LPC_CT32B1_Type;


/** @brief Register Masks for CT32B */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_CT32B1' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup CT32B_Register_Masks_GROUP CT32B Register Masks */
/** @{ */

/** @name IR - Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */ /** @{ */
#define LPC_CT32B1_IR_MR0INT_MASK                (0x1U)                                              /**< LPC_CT32B1_IR.MR0INT Mask               */
#define LPC_CT32B1_IR_MR0INT_SHIFT               (0U)                                                /**< LPC_CT32B1_IR.MR0INT Position           */
#define LPC_CT32B1_IR_MR0INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_IR_MR0INT_SHIFT))&LPC_CT32B1_IR_MR0INT_MASK) /**< LPC_CT32B1_IR.MR0INT Field              */
#define LPC_CT32B1_IR_MR1INT_MASK                (0x2U)                                              /**< LPC_CT32B1_IR.MR1INT Mask               */
#define LPC_CT32B1_IR_MR1INT_SHIFT               (1U)                                                /**< LPC_CT32B1_IR.MR1INT Position           */
#define LPC_CT32B1_IR_MR1INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_IR_MR1INT_SHIFT))&LPC_CT32B1_IR_MR1INT_MASK) /**< LPC_CT32B1_IR.MR1INT Field              */
#define LPC_CT32B1_IR_MR2INT_MASK                (0x4U)                                              /**< LPC_CT32B1_IR.MR2INT Mask               */
#define LPC_CT32B1_IR_MR2INT_SHIFT               (2U)                                                /**< LPC_CT32B1_IR.MR2INT Position           */
#define LPC_CT32B1_IR_MR2INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_IR_MR2INT_SHIFT))&LPC_CT32B1_IR_MR2INT_MASK) /**< LPC_CT32B1_IR.MR2INT Field              */
#define LPC_CT32B1_IR_MR3INT_MASK                (0x8U)                                              /**< LPC_CT32B1_IR.MR3INT Mask               */
#define LPC_CT32B1_IR_MR3INT_SHIFT               (3U)                                                /**< LPC_CT32B1_IR.MR3INT Position           */
#define LPC_CT32B1_IR_MR3INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_IR_MR3INT_SHIFT))&LPC_CT32B1_IR_MR3INT_MASK) /**< LPC_CT32B1_IR.MR3INT Field              */
#define LPC_CT32B1_IR_CR0INT_MASK                (0x10U)                                             /**< LPC_CT32B1_IR.CR0INT Mask               */
#define LPC_CT32B1_IR_CR0INT_SHIFT               (4U)                                                /**< LPC_CT32B1_IR.CR0INT Position           */
#define LPC_CT32B1_IR_CR0INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_IR_CR0INT_SHIFT))&LPC_CT32B1_IR_CR0INT_MASK) /**< LPC_CT32B1_IR.CR0INT Field              */
#define LPC_CT32B1_IR_CR1INT_MASK                (0x20U)                                             /**< LPC_CT32B1_IR.CR1INT Mask               */
#define LPC_CT32B1_IR_CR1INT_SHIFT               (5U)                                                /**< LPC_CT32B1_IR.CR1INT Position           */
#define LPC_CT32B1_IR_CR1INT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_IR_CR1INT_SHIFT))&LPC_CT32B1_IR_CR1INT_MASK) /**< LPC_CT32B1_IR.CR1INT Field              */
/** @} */

/** @name TCR - Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */ /** @{ */
#define LPC_CT32B1_TCR_CEN_MASK                  (0x1U)                                              /**< LPC_CT32B1_TCR.CEN Mask                 */
#define LPC_CT32B1_TCR_CEN_SHIFT                 (0U)                                                /**< LPC_CT32B1_TCR.CEN Position             */
#define LPC_CT32B1_TCR_CEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_TCR_CEN_SHIFT))&LPC_CT32B1_TCR_CEN_MASK) /**< LPC_CT32B1_TCR.CEN Field                */
#define LPC_CT32B1_TCR_CRST_MASK                 (0x2U)                                              /**< LPC_CT32B1_TCR.CRST Mask                */
#define LPC_CT32B1_TCR_CRST_SHIFT                (1U)                                                /**< LPC_CT32B1_TCR.CRST Position            */
#define LPC_CT32B1_TCR_CRST(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_TCR_CRST_SHIFT))&LPC_CT32B1_TCR_CRST_MASK) /**< LPC_CT32B1_TCR.CRST Field               */
/** @} */

/** @name TC - Timer Counter. The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */ /** @{ */
#define LPC_CT32B1_TC_TC_MASK                    (0xFFFFFFFFU)                                       /**< LPC_CT32B1_TC.TC Mask                   */
#define LPC_CT32B1_TC_TC_SHIFT                   (0U)                                                /**< LPC_CT32B1_TC.TC Position               */
#define LPC_CT32B1_TC_TC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_TC_TC_SHIFT))&LPC_CT32B1_TC_TC_MASK) /**< LPC_CT32B1_TC.TC Field                  */
/** @} */

/** @name PR - Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */ /** @{ */
#define LPC_CT32B1_PR_PCVAL_MASK                 (0xFFFFFFFFU)                                       /**< LPC_CT32B1_PR.PCVAL Mask                */
#define LPC_CT32B1_PR_PCVAL_SHIFT                (0U)                                                /**< LPC_CT32B1_PR.PCVAL Position            */
#define LPC_CT32B1_PR_PCVAL(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_PR_PCVAL_SHIFT))&LPC_CT32B1_PR_PCVAL_MASK) /**< LPC_CT32B1_PR.PCVAL Field               */
/** @} */

/** @name PC - Prescale Counter. The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */ /** @{ */
#define LPC_CT32B1_PC_PC_MASK                    (0xFFFFFFFFU)                                       /**< LPC_CT32B1_PC.PC Mask                   */
#define LPC_CT32B1_PC_PC_SHIFT                   (0U)                                                /**< LPC_CT32B1_PC.PC Position               */
#define LPC_CT32B1_PC_PC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_PC_PC_SHIFT))&LPC_CT32B1_PC_PC_MASK) /**< LPC_CT32B1_PC.PC Field                  */
/** @} */

/** @name MCR - Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */ /** @{ */
#define LPC_CT32B1_MCR_MR0I_MASK                 (0x1U)                                              /**< LPC_CT32B1_MCR.MR0I Mask                */
#define LPC_CT32B1_MCR_MR0I_SHIFT                (0U)                                                /**< LPC_CT32B1_MCR.MR0I Position            */
#define LPC_CT32B1_MCR_MR0I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR0I_SHIFT))&LPC_CT32B1_MCR_MR0I_MASK) /**< LPC_CT32B1_MCR.MR0I Field               */
#define LPC_CT32B1_MCR_MR0R_MASK                 (0x2U)                                              /**< LPC_CT32B1_MCR.MR0R Mask                */
#define LPC_CT32B1_MCR_MR0R_SHIFT                (1U)                                                /**< LPC_CT32B1_MCR.MR0R Position            */
#define LPC_CT32B1_MCR_MR0R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR0R_SHIFT))&LPC_CT32B1_MCR_MR0R_MASK) /**< LPC_CT32B1_MCR.MR0R Field               */
#define LPC_CT32B1_MCR_MR0S_MASK                 (0x4U)                                              /**< LPC_CT32B1_MCR.MR0S Mask                */
#define LPC_CT32B1_MCR_MR0S_SHIFT                (2U)                                                /**< LPC_CT32B1_MCR.MR0S Position            */
#define LPC_CT32B1_MCR_MR0S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR0S_SHIFT))&LPC_CT32B1_MCR_MR0S_MASK) /**< LPC_CT32B1_MCR.MR0S Field               */
#define LPC_CT32B1_MCR_MR1I_MASK                 (0x8U)                                              /**< LPC_CT32B1_MCR.MR1I Mask                */
#define LPC_CT32B1_MCR_MR1I_SHIFT                (3U)                                                /**< LPC_CT32B1_MCR.MR1I Position            */
#define LPC_CT32B1_MCR_MR1I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR1I_SHIFT))&LPC_CT32B1_MCR_MR1I_MASK) /**< LPC_CT32B1_MCR.MR1I Field               */
#define LPC_CT32B1_MCR_MR1R_MASK                 (0x10U)                                             /**< LPC_CT32B1_MCR.MR1R Mask                */
#define LPC_CT32B1_MCR_MR1R_SHIFT                (4U)                                                /**< LPC_CT32B1_MCR.MR1R Position            */
#define LPC_CT32B1_MCR_MR1R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR1R_SHIFT))&LPC_CT32B1_MCR_MR1R_MASK) /**< LPC_CT32B1_MCR.MR1R Field               */
#define LPC_CT32B1_MCR_MR1S_MASK                 (0x20U)                                             /**< LPC_CT32B1_MCR.MR1S Mask                */
#define LPC_CT32B1_MCR_MR1S_SHIFT                (5U)                                                /**< LPC_CT32B1_MCR.MR1S Position            */
#define LPC_CT32B1_MCR_MR1S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR1S_SHIFT))&LPC_CT32B1_MCR_MR1S_MASK) /**< LPC_CT32B1_MCR.MR1S Field               */
#define LPC_CT32B1_MCR_MR2I_MASK                 (0x40U)                                             /**< LPC_CT32B1_MCR.MR2I Mask                */
#define LPC_CT32B1_MCR_MR2I_SHIFT                (6U)                                                /**< LPC_CT32B1_MCR.MR2I Position            */
#define LPC_CT32B1_MCR_MR2I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR2I_SHIFT))&LPC_CT32B1_MCR_MR2I_MASK) /**< LPC_CT32B1_MCR.MR2I Field               */
#define LPC_CT32B1_MCR_MR2R_MASK                 (0x80U)                                             /**< LPC_CT32B1_MCR.MR2R Mask                */
#define LPC_CT32B1_MCR_MR2R_SHIFT                (7U)                                                /**< LPC_CT32B1_MCR.MR2R Position            */
#define LPC_CT32B1_MCR_MR2R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR2R_SHIFT))&LPC_CT32B1_MCR_MR2R_MASK) /**< LPC_CT32B1_MCR.MR2R Field               */
#define LPC_CT32B1_MCR_MR2S_MASK                 (0x100U)                                            /**< LPC_CT32B1_MCR.MR2S Mask                */
#define LPC_CT32B1_MCR_MR2S_SHIFT                (8U)                                                /**< LPC_CT32B1_MCR.MR2S Position            */
#define LPC_CT32B1_MCR_MR2S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR2S_SHIFT))&LPC_CT32B1_MCR_MR2S_MASK) /**< LPC_CT32B1_MCR.MR2S Field               */
#define LPC_CT32B1_MCR_MR3I_MASK                 (0x200U)                                            /**< LPC_CT32B1_MCR.MR3I Mask                */
#define LPC_CT32B1_MCR_MR3I_SHIFT                (9U)                                                /**< LPC_CT32B1_MCR.MR3I Position            */
#define LPC_CT32B1_MCR_MR3I(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR3I_SHIFT))&LPC_CT32B1_MCR_MR3I_MASK) /**< LPC_CT32B1_MCR.MR3I Field               */
#define LPC_CT32B1_MCR_MR3R_MASK                 (0x400U)                                            /**< LPC_CT32B1_MCR.MR3R Mask                */
#define LPC_CT32B1_MCR_MR3R_SHIFT                (10U)                                               /**< LPC_CT32B1_MCR.MR3R Position            */
#define LPC_CT32B1_MCR_MR3R(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR3R_SHIFT))&LPC_CT32B1_MCR_MR3R_MASK) /**< LPC_CT32B1_MCR.MR3R Field               */
#define LPC_CT32B1_MCR_MR3S_MASK                 (0x800U)                                            /**< LPC_CT32B1_MCR.MR3S Mask                */
#define LPC_CT32B1_MCR_MR3S_SHIFT                (11U)                                               /**< LPC_CT32B1_MCR.MR3S Position            */
#define LPC_CT32B1_MCR_MR3S(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MCR_MR3S_SHIFT))&LPC_CT32B1_MCR_MR3S_MASK) /**< LPC_CT32B1_MCR.MR3S Field               */
/** @} */

/** @name MR - Match Register %s. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */ /** @{ */
#define LPC_CT32B1_MR_MATCH_MASK                 (0xFFFFFFFFU)                                       /**< LPC_CT32B1_MR.MATCH Mask                */
#define LPC_CT32B1_MR_MATCH_SHIFT                (0U)                                                /**< LPC_CT32B1_MR.MATCH Position            */
#define LPC_CT32B1_MR_MATCH(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_MR_MATCH_SHIFT))&LPC_CT32B1_MR_MATCH_MASK) /**< LPC_CT32B1_MR.MATCH Field               */
/** @} */

/** @name CCR - Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */ /** @{ */
#define LPC_CT32B1_CCR_CAP0RE_MASK               (0x1U)                                              /**< LPC_CT32B1_CCR.CAP0RE Mask              */
#define LPC_CT32B1_CCR_CAP0RE_SHIFT              (0U)                                                /**< LPC_CT32B1_CCR.CAP0RE Position          */
#define LPC_CT32B1_CCR_CAP0RE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CCR_CAP0RE_SHIFT))&LPC_CT32B1_CCR_CAP0RE_MASK) /**< LPC_CT32B1_CCR.CAP0RE Field             */
#define LPC_CT32B1_CCR_CAP0FE_MASK               (0x2U)                                              /**< LPC_CT32B1_CCR.CAP0FE Mask              */
#define LPC_CT32B1_CCR_CAP0FE_SHIFT              (1U)                                                /**< LPC_CT32B1_CCR.CAP0FE Position          */
#define LPC_CT32B1_CCR_CAP0FE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CCR_CAP0FE_SHIFT))&LPC_CT32B1_CCR_CAP0FE_MASK) /**< LPC_CT32B1_CCR.CAP0FE Field             */
#define LPC_CT32B1_CCR_CAP0I_MASK                (0x4U)                                              /**< LPC_CT32B1_CCR.CAP0I Mask               */
#define LPC_CT32B1_CCR_CAP0I_SHIFT               (2U)                                                /**< LPC_CT32B1_CCR.CAP0I Position           */
#define LPC_CT32B1_CCR_CAP0I(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CCR_CAP0I_SHIFT))&LPC_CT32B1_CCR_CAP0I_MASK) /**< LPC_CT32B1_CCR.CAP0I Field              */
#define LPC_CT32B1_CCR_CAP1RE_MASK               (0x8U)                                              /**< LPC_CT32B1_CCR.CAP1RE Mask              */
#define LPC_CT32B1_CCR_CAP1RE_SHIFT              (3U)                                                /**< LPC_CT32B1_CCR.CAP1RE Position          */
#define LPC_CT32B1_CCR_CAP1RE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CCR_CAP1RE_SHIFT))&LPC_CT32B1_CCR_CAP1RE_MASK) /**< LPC_CT32B1_CCR.CAP1RE Field             */
#define LPC_CT32B1_CCR_CAP1FE_MASK               (0x10U)                                             /**< LPC_CT32B1_CCR.CAP1FE Mask              */
#define LPC_CT32B1_CCR_CAP1FE_SHIFT              (4U)                                                /**< LPC_CT32B1_CCR.CAP1FE Position          */
#define LPC_CT32B1_CCR_CAP1FE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CCR_CAP1FE_SHIFT))&LPC_CT32B1_CCR_CAP1FE_MASK) /**< LPC_CT32B1_CCR.CAP1FE Field             */
#define LPC_CT32B1_CCR_CAP1I_MASK                (0x20U)                                             /**< LPC_CT32B1_CCR.CAP1I Mask               */
#define LPC_CT32B1_CCR_CAP1I_SHIFT               (5U)                                                /**< LPC_CT32B1_CCR.CAP1I Position           */
#define LPC_CT32B1_CCR_CAP1I(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CCR_CAP1I_SHIFT))&LPC_CT32B1_CCR_CAP1I_MASK) /**< LPC_CT32B1_CCR.CAP1I Field              */
/** @} */

/** @name CR0 - Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT32B0_CAP0 input */ /** @{ */
#define LPC_CT32B1_CR0_CAP_MASK                  (0xFFFFFFFFU)                                       /**< LPC_CT32B1_CR0.CAP Mask                 */
#define LPC_CT32B1_CR0_CAP_SHIFT                 (0U)                                                /**< LPC_CT32B1_CR0.CAP Position             */
#define LPC_CT32B1_CR0_CAP(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CR0_CAP_SHIFT))&LPC_CT32B1_CR0_CAP_MASK) /**< LPC_CT32B1_CR0.CAP Field                */
/** @} */

/** @name CR1 - Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT32B1_CAP1 input */ /** @{ */
#define LPC_CT32B1_CR1_CAP_MASK                  (0xFFFFFFFFU)                                       /**< LPC_CT32B1_CR1.CAP Mask                 */
#define LPC_CT32B1_CR1_CAP_SHIFT                 (0U)                                                /**< LPC_CT32B1_CR1.CAP Position             */
#define LPC_CT32B1_CR1_CAP(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CR1_CAP_SHIFT))&LPC_CT32B1_CR1_CAP_MASK) /**< LPC_CT32B1_CR1.CAP Field                */
/** @} */

/** @name EMR - External Match Register. The EMR controls the match function and the external match pins CT32Bn_MAT[3:0] */ /** @{ */
#define LPC_CT32B1_EMR_EM0_MASK                  (0x1U)                                              /**< LPC_CT32B1_EMR.EM0 Mask                 */
#define LPC_CT32B1_EMR_EM0_SHIFT                 (0U)                                                /**< LPC_CT32B1_EMR.EM0 Position             */
#define LPC_CT32B1_EMR_EM0(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_EMR_EM0_SHIFT))&LPC_CT32B1_EMR_EM0_MASK) /**< LPC_CT32B1_EMR.EM0 Field                */
#define LPC_CT32B1_EMR_EM1_MASK                  (0x2U)                                              /**< LPC_CT32B1_EMR.EM1 Mask                 */
#define LPC_CT32B1_EMR_EM1_SHIFT                 (1U)                                                /**< LPC_CT32B1_EMR.EM1 Position             */
#define LPC_CT32B1_EMR_EM1(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_EMR_EM1_SHIFT))&LPC_CT32B1_EMR_EM1_MASK) /**< LPC_CT32B1_EMR.EM1 Field                */
#define LPC_CT32B1_EMR_EM2_MASK                  (0x4U)                                              /**< LPC_CT32B1_EMR.EM2 Mask                 */
#define LPC_CT32B1_EMR_EM2_SHIFT                 (2U)                                                /**< LPC_CT32B1_EMR.EM2 Position             */
#define LPC_CT32B1_EMR_EM2(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_EMR_EM2_SHIFT))&LPC_CT32B1_EMR_EM2_MASK) /**< LPC_CT32B1_EMR.EM2 Field                */
#define LPC_CT32B1_EMR_EM3_MASK                  (0x8U)                                              /**< LPC_CT32B1_EMR.EM3 Mask                 */
#define LPC_CT32B1_EMR_EM3_SHIFT                 (3U)                                                /**< LPC_CT32B1_EMR.EM3 Position             */
#define LPC_CT32B1_EMR_EM3(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_EMR_EM3_SHIFT))&LPC_CT32B1_EMR_EM3_MASK) /**< LPC_CT32B1_EMR.EM3 Field                */
#define LPC_CT32B1_EMR_EMC0_MASK                 (0x30U)                                             /**< LPC_CT32B1_EMR.EMC0 Mask                */
#define LPC_CT32B1_EMR_EMC0_SHIFT                (4U)                                                /**< LPC_CT32B1_EMR.EMC0 Position            */
#define LPC_CT32B1_EMR_EMC0(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_EMR_EMC0_SHIFT))&LPC_CT32B1_EMR_EMC0_MASK) /**< LPC_CT32B1_EMR.EMC0 Field               */
#define LPC_CT32B1_EMR_EMC1_MASK                 (0xC0U)                                             /**< LPC_CT32B1_EMR.EMC1 Mask                */
#define LPC_CT32B1_EMR_EMC1_SHIFT                (6U)                                                /**< LPC_CT32B1_EMR.EMC1 Position            */
#define LPC_CT32B1_EMR_EMC1(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_EMR_EMC1_SHIFT))&LPC_CT32B1_EMR_EMC1_MASK) /**< LPC_CT32B1_EMR.EMC1 Field               */
#define LPC_CT32B1_EMR_EMC2_MASK                 (0x300U)                                            /**< LPC_CT32B1_EMR.EMC2 Mask                */
#define LPC_CT32B1_EMR_EMC2_SHIFT                (8U)                                                /**< LPC_CT32B1_EMR.EMC2 Position            */
#define LPC_CT32B1_EMR_EMC2(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_EMR_EMC2_SHIFT))&LPC_CT32B1_EMR_EMC2_MASK) /**< LPC_CT32B1_EMR.EMC2 Field               */
#define LPC_CT32B1_EMR_EMC3_MASK                 (0xC00U)                                            /**< LPC_CT32B1_EMR.EMC3 Mask                */
#define LPC_CT32B1_EMR_EMC3_SHIFT                (10U)                                               /**< LPC_CT32B1_EMR.EMC3 Position            */
#define LPC_CT32B1_EMR_EMC3(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_EMR_EMC3_SHIFT))&LPC_CT32B1_EMR_EMC3_MASK) /**< LPC_CT32B1_EMR.EMC3 Field               */
/** @} */

/** @name CTCR - Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */ /** @{ */
#define LPC_CT32B1_CTCR_CTM_MASK                 (0x3U)                                              /**< LPC_CT32B1_CTCR.CTM Mask                */
#define LPC_CT32B1_CTCR_CTM_SHIFT                (0U)                                                /**< LPC_CT32B1_CTCR.CTM Position            */
#define LPC_CT32B1_CTCR_CTM(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CTCR_CTM_SHIFT))&LPC_CT32B1_CTCR_CTM_MASK) /**< LPC_CT32B1_CTCR.CTM Field               */
#define LPC_CT32B1_CTCR_CIS_MASK                 (0xCU)                                              /**< LPC_CT32B1_CTCR.CIS Mask                */
#define LPC_CT32B1_CTCR_CIS_SHIFT                (2U)                                                /**< LPC_CT32B1_CTCR.CIS Position            */
#define LPC_CT32B1_CTCR_CIS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CTCR_CIS_SHIFT))&LPC_CT32B1_CTCR_CIS_MASK) /**< LPC_CT32B1_CTCR.CIS Field               */
#define LPC_CT32B1_CTCR_ENCC_MASK                (0x10U)                                             /**< LPC_CT32B1_CTCR.ENCC Mask               */
#define LPC_CT32B1_CTCR_ENCC_SHIFT               (4U)                                                /**< LPC_CT32B1_CTCR.ENCC Position           */
#define LPC_CT32B1_CTCR_ENCC(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CTCR_ENCC_SHIFT))&LPC_CT32B1_CTCR_ENCC_MASK) /**< LPC_CT32B1_CTCR.ENCC Field              */
#define LPC_CT32B1_CTCR_SElCC_MASK               (0xE0U)                                             /**< LPC_CT32B1_CTCR.SElCC Mask              */
#define LPC_CT32B1_CTCR_SElCC_SHIFT              (5U)                                                /**< LPC_CT32B1_CTCR.SElCC Position          */
#define LPC_CT32B1_CTCR_SElCC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_CTCR_SElCC_SHIFT))&LPC_CT32B1_CTCR_SElCC_MASK) /**< LPC_CT32B1_CTCR.SElCC Field             */
/** @} */

/** @name PWMC - PWM Control Register. The PWMCON enables PWM mode for the external match pins CT32Bn_MAT[3:0] */ /** @{ */
#define LPC_CT32B1_PWMC_PWMEN0_MASK              (0x1U)                                              /**< LPC_CT32B1_PWMC.PWMEN0 Mask             */
#define LPC_CT32B1_PWMC_PWMEN0_SHIFT             (0U)                                                /**< LPC_CT32B1_PWMC.PWMEN0 Position         */
#define LPC_CT32B1_PWMC_PWMEN0(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_PWMC_PWMEN0_SHIFT))&LPC_CT32B1_PWMC_PWMEN0_MASK) /**< LPC_CT32B1_PWMC.PWMEN0 Field            */
#define LPC_CT32B1_PWMC_PWMEN1_MASK              (0x2U)                                              /**< LPC_CT32B1_PWMC.PWMEN1 Mask             */
#define LPC_CT32B1_PWMC_PWMEN1_SHIFT             (1U)                                                /**< LPC_CT32B1_PWMC.PWMEN1 Position         */
#define LPC_CT32B1_PWMC_PWMEN1(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_PWMC_PWMEN1_SHIFT))&LPC_CT32B1_PWMC_PWMEN1_MASK) /**< LPC_CT32B1_PWMC.PWMEN1 Field            */
#define LPC_CT32B1_PWMC_PWMEN2_MASK              (0x4U)                                              /**< LPC_CT32B1_PWMC.PWMEN2 Mask             */
#define LPC_CT32B1_PWMC_PWMEN2_SHIFT             (2U)                                                /**< LPC_CT32B1_PWMC.PWMEN2 Position         */
#define LPC_CT32B1_PWMC_PWMEN2(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_PWMC_PWMEN2_SHIFT))&LPC_CT32B1_PWMC_PWMEN2_MASK) /**< LPC_CT32B1_PWMC.PWMEN2 Field            */
#define LPC_CT32B1_PWMC_PWMEN3_MASK              (0x8U)                                              /**< LPC_CT32B1_PWMC.PWMEN3 Mask             */
#define LPC_CT32B1_PWMC_PWMEN3_SHIFT             (3U)                                                /**< LPC_CT32B1_PWMC.PWMEN3 Position         */
#define LPC_CT32B1_PWMC_PWMEN3(x)                (((uint32_t)(((uint32_t)(x))<<LPC_CT32B1_PWMC_PWMEN3_SHIFT))&LPC_CT32B1_PWMC_PWMEN3_MASK) /**< LPC_CT32B1_PWMC.PWMEN3 Field            */
/** @} */

/** @} */ /* End group CT32B_Register_Masks_GROUP */


/* LPC_CT32B1 - Peripheral instance base addresses */
#define LPC_CT32B1_BasePtr             0x40018000UL //!< Peripheral base address
#define LPC_CT32B1                     ((LPC_CT32B1_Type *) LPC_CT32B1_BasePtr) //!< Freescale base pointer
#define LPC_CT32B1_BASE_PTR            (LPC_CT32B1) //!< Freescale style base pointer

/** @} */ /* End group CT32B_Peripheral_access_layer_GROUP */


/** @brief C Struct for FLASHCTRL */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup FLASHCTRL_Peripheral_access_layer_GROUP FLASHCTRL Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_FLASHCTRL (file:FLASHCTRL_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief Flash
controller
 */
/**
 * @struct LPC_FLASHCTRL_Type
 * @brief  C Struct allowing access to FLASHCTRL registers
 */
typedef struct LPC_FLASHCTRL_Type {
        uint8_t   RESERVED_0[16];               /**< 0000: 0x10 bytes                                                   */
   __IO uint32_t  FLASHCFG;                     /**< 0010: Flash memory access time configuration register              */
        uint8_t   RESERVED_1[12];               /**< 0014: 0xC bytes                                                    */
   __IO uint32_t  FMSSTART;                     /**< 0020: Signature start address register                             */
   __IO uint32_t  FMSSTOP;                      /**< 0024: Signature stop-address register                              */
        uint8_t   RESERVED_2[4];                /**< 0028: 0x4 bytes                                                    */
   __I  uint32_t  FMSW0;                        /**< 002C: Word 0 [31:0]                                                */
   __I  uint32_t  FMSW1;                        /**< 0030: Word 1 [63:32]                                               */
   __I  uint32_t  FMSW2;                        /**< 0034: Word 2 [95:64]                                               */
   __I  uint32_t  FMSW3;                        /**< 0038: Word 3 [127:96]                                              */
        uint8_t   RESERVED_3[96];               /**< 003C: 0x60 bytes                                                   */
   __IO uint32_t  EEMSSTART;                    /**< 009C: EEPROM BIST start address register                           */
   __IO uint32_t  EEMSSTOP;                     /**< 00A0: EEPROM BIST stop address register                            */
   __I  uint32_t  EEMSSIG;                      /**< 00A4: EEPROM 24-bit BIST signature register                        */
        uint8_t   RESERVED_4[3896];             /**< 00A8: 0xF38 bytes                                                  */
   __I  uint32_t  FMSTAT;                       /**< 0FE0: Signature generation status register                         */
        uint8_t   RESERVED_5[4];                /**< 0FE4: 0x4 bytes                                                    */
   __O  uint32_t  FMSTATCLR;                    /**< 0FE8: Signature generation status clear register                   */
} LPC_FLASHCTRL_Type;


/** @brief Register Masks for FLASHCTRL */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_FLASHCTRL' Position & Mask macros               ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup FLASHCTRL_Register_Masks_GROUP FLASHCTRL Register Masks */
/** @{ */

/** @name FLASHCFG - Flash memory access time configuration register */ /** @{ */
#define LPC_FLASHCTRL_FLASHCFG_FLASHTIM_MASK     (0x3U)                                              /**< LPC_FLASHCTRL_FLASHCFG.FLASHTIM Mask    */
#define LPC_FLASHCTRL_FLASHCFG_FLASHTIM_SHIFT    (0U)                                                /**< LPC_FLASHCTRL_FLASHCFG.FLASHTIM Position*/
#define LPC_FLASHCTRL_FLASHCFG_FLASHTIM(x)       (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FLASHCFG_FLASHTIM_SHIFT))&LPC_FLASHCTRL_FLASHCFG_FLASHTIM_MASK) /**< LPC_FLASHCTRL_FLASHCFG.FLASHTIM Field   */
/** @} */

/** @name FMSSTART - Signature start address register */ /** @{ */
#define LPC_FLASHCTRL_FMSSTART_START_MASK        (0x1FFFFU)                                          /**< LPC_FLASHCTRL_FMSSTART.START Mask       */
#define LPC_FLASHCTRL_FMSSTART_START_SHIFT       (0U)                                                /**< LPC_FLASHCTRL_FMSSTART.START Position   */
#define LPC_FLASHCTRL_FMSSTART_START(x)          (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSSTART_START_SHIFT))&LPC_FLASHCTRL_FMSSTART_START_MASK) /**< LPC_FLASHCTRL_FMSSTART.START Field      */
/** @} */

/** @name FMSSTOP - Signature stop-address register */ /** @{ */
#define LPC_FLASHCTRL_FMSSTOP_STOP_MASK          (0x1FFFFU)                                          /**< LPC_FLASHCTRL_FMSSTOP.STOP Mask         */
#define LPC_FLASHCTRL_FMSSTOP_STOP_SHIFT         (0U)                                                /**< LPC_FLASHCTRL_FMSSTOP.STOP Position     */
#define LPC_FLASHCTRL_FMSSTOP_STOP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSSTOP_STOP_SHIFT))&LPC_FLASHCTRL_FMSSTOP_STOP_MASK) /**< LPC_FLASHCTRL_FMSSTOP.STOP Field        */
#define LPC_FLASHCTRL_FMSSTOP_SIG_START_MASK     (0x20000U)                                          /**< LPC_FLASHCTRL_FMSSTOP.SIG_START Mask    */
#define LPC_FLASHCTRL_FMSSTOP_SIG_START_SHIFT    (17U)                                               /**< LPC_FLASHCTRL_FMSSTOP.SIG_START Position*/
#define LPC_FLASHCTRL_FMSSTOP_SIG_START(x)       (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSSTOP_SIG_START_SHIFT))&LPC_FLASHCTRL_FMSSTOP_SIG_START_MASK) /**< LPC_FLASHCTRL_FMSSTOP.SIG_START Field   */
/** @} */

/** @name FMSW0 - Word 0 [31:0] */ /** @{ */
#define LPC_FLASHCTRL_FMSW0_SW0_31_0_MASK        (0xFFFFFFFFU)                                       /**< LPC_FLASHCTRL_FMSW0.SW0_31_0 Mask       */
#define LPC_FLASHCTRL_FMSW0_SW0_31_0_SHIFT       (0U)                                                /**< LPC_FLASHCTRL_FMSW0.SW0_31_0 Position   */
#define LPC_FLASHCTRL_FMSW0_SW0_31_0(x)          (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSW0_SW0_31_0_SHIFT))&LPC_FLASHCTRL_FMSW0_SW0_31_0_MASK) /**< LPC_FLASHCTRL_FMSW0.SW0_31_0 Field      */
/** @} */

/** @name FMSW1 - Word 1 [63:32] */ /** @{ */
#define LPC_FLASHCTRL_FMSW1_SW1_63_32_MASK       (0xFFFFFFFFU)                                       /**< LPC_FLASHCTRL_FMSW1.SW1_63_32 Mask      */
#define LPC_FLASHCTRL_FMSW1_SW1_63_32_SHIFT      (0U)                                                /**< LPC_FLASHCTRL_FMSW1.SW1_63_32 Position  */
#define LPC_FLASHCTRL_FMSW1_SW1_63_32(x)         (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSW1_SW1_63_32_SHIFT))&LPC_FLASHCTRL_FMSW1_SW1_63_32_MASK) /**< LPC_FLASHCTRL_FMSW1.SW1_63_32 Field     */
/** @} */

/** @name FMSW2 - Word 2 [95:64] */ /** @{ */
#define LPC_FLASHCTRL_FMSW2_SW2_95_64_MASK       (0xFFFFFFFFU)                                       /**< LPC_FLASHCTRL_FMSW2.SW2_95_64 Mask      */
#define LPC_FLASHCTRL_FMSW2_SW2_95_64_SHIFT      (0U)                                                /**< LPC_FLASHCTRL_FMSW2.SW2_95_64 Position  */
#define LPC_FLASHCTRL_FMSW2_SW2_95_64(x)         (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSW2_SW2_95_64_SHIFT))&LPC_FLASHCTRL_FMSW2_SW2_95_64_MASK) /**< LPC_FLASHCTRL_FMSW2.SW2_95_64 Field     */
/** @} */

/** @name FMSW3 - Word 3 [127:96] */ /** @{ */
#define LPC_FLASHCTRL_FMSW3_SW3_127_96_MASK      (0xFFFFFFFFU)                                       /**< LPC_FLASHCTRL_FMSW3.SW3_127_96 Mask     */
#define LPC_FLASHCTRL_FMSW3_SW3_127_96_SHIFT     (0U)                                                /**< LPC_FLASHCTRL_FMSW3.SW3_127_96 Position */
#define LPC_FLASHCTRL_FMSW3_SW3_127_96(x)        (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSW3_SW3_127_96_SHIFT))&LPC_FLASHCTRL_FMSW3_SW3_127_96_MASK) /**< LPC_FLASHCTRL_FMSW3.SW3_127_96 Field    */
/** @} */

/** @name EEMSSTART - EEPROM BIST start address register */ /** @{ */
#define LPC_FLASHCTRL_EEMSSTART_STARTA_MASK      (0x3FFFU)                                           /**< LPC_FLASHCTRL_EEMSSTART.STARTA Mask     */
#define LPC_FLASHCTRL_EEMSSTART_STARTA_SHIFT     (0U)                                                /**< LPC_FLASHCTRL_EEMSSTART.STARTA Position */
#define LPC_FLASHCTRL_EEMSSTART_STARTA(x)        (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_EEMSSTART_STARTA_SHIFT))&LPC_FLASHCTRL_EEMSSTART_STARTA_MASK) /**< LPC_FLASHCTRL_EEMSSTART.STARTA Field    */
/** @} */

/** @name EEMSSTOP - EEPROM BIST stop address register */ /** @{ */
#define LPC_FLASHCTRL_EEMSSTOP_STOPA_MASK        (0x3FFFU)                                           /**< LPC_FLASHCTRL_EEMSSTOP.STOPA Mask       */
#define LPC_FLASHCTRL_EEMSSTOP_STOPA_SHIFT       (0U)                                                /**< LPC_FLASHCTRL_EEMSSTOP.STOPA Position   */
#define LPC_FLASHCTRL_EEMSSTOP_STOPA(x)          (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_EEMSSTOP_STOPA_SHIFT))&LPC_FLASHCTRL_EEMSSTOP_STOPA_MASK) /**< LPC_FLASHCTRL_EEMSSTOP.STOPA Field      */
#define LPC_FLASHCTRL_EEMSSTOP_DEVSEL_MASK       (0x40000000U)                                       /**< LPC_FLASHCTRL_EEMSSTOP.DEVSEL Mask      */
#define LPC_FLASHCTRL_EEMSSTOP_DEVSEL_SHIFT      (30U)                                               /**< LPC_FLASHCTRL_EEMSSTOP.DEVSEL Position  */
#define LPC_FLASHCTRL_EEMSSTOP_DEVSEL(x)         (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_EEMSSTOP_DEVSEL_SHIFT))&LPC_FLASHCTRL_EEMSSTOP_DEVSEL_MASK) /**< LPC_FLASHCTRL_EEMSSTOP.DEVSEL Field     */
#define LPC_FLASHCTRL_EEMSSTOP_STRTBIST_MASK     (0x80000000U)                                       /**< LPC_FLASHCTRL_EEMSSTOP.STRTBIST Mask    */
#define LPC_FLASHCTRL_EEMSSTOP_STRTBIST_SHIFT    (31U)                                               /**< LPC_FLASHCTRL_EEMSSTOP.STRTBIST Position*/
#define LPC_FLASHCTRL_EEMSSTOP_STRTBIST(x)       (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_EEMSSTOP_STRTBIST_SHIFT))&LPC_FLASHCTRL_EEMSSTOP_STRTBIST_MASK) /**< LPC_FLASHCTRL_EEMSSTOP.STRTBIST Field   */
/** @} */

/** @name EEMSSIG - EEPROM 24-bit BIST signature register */ /** @{ */
#define LPC_FLASHCTRL_EEMSSIG_DATA_SIG_MASK      (0xFFFFU)                                           /**< LPC_FLASHCTRL_EEMSSIG.DATA_SIG Mask     */
#define LPC_FLASHCTRL_EEMSSIG_DATA_SIG_SHIFT     (0U)                                                /**< LPC_FLASHCTRL_EEMSSIG.DATA_SIG Position */
#define LPC_FLASHCTRL_EEMSSIG_DATA_SIG(x)        (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_EEMSSIG_DATA_SIG_SHIFT))&LPC_FLASHCTRL_EEMSSIG_DATA_SIG_MASK) /**< LPC_FLASHCTRL_EEMSSIG.DATA_SIG Field    */
#define LPC_FLASHCTRL_EEMSSIG_PARITY_SIG_MASK    (0xFFFF0000U)                                       /**< LPC_FLASHCTRL_EEMSSIG.PARITY_SIG Mask   */
#define LPC_FLASHCTRL_EEMSSIG_PARITY_SIG_SHIFT   (16U)                                               /**< LPC_FLASHCTRL_EEMSSIG.PARITY_SIG Position*/
#define LPC_FLASHCTRL_EEMSSIG_PARITY_SIG(x)      (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_EEMSSIG_PARITY_SIG_SHIFT))&LPC_FLASHCTRL_EEMSSIG_PARITY_SIG_MASK) /**< LPC_FLASHCTRL_EEMSSIG.PARITY_SIG Field  */
/** @} */

/** @name FMSTAT - Signature generation status register */ /** @{ */
#define LPC_FLASHCTRL_FMSTAT_SIG_DONE_MASK       (0x4U)                                              /**< LPC_FLASHCTRL_FMSTAT.SIG_DONE Mask      */
#define LPC_FLASHCTRL_FMSTAT_SIG_DONE_SHIFT      (2U)                                                /**< LPC_FLASHCTRL_FMSTAT.SIG_DONE Position  */
#define LPC_FLASHCTRL_FMSTAT_SIG_DONE(x)         (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSTAT_SIG_DONE_SHIFT))&LPC_FLASHCTRL_FMSTAT_SIG_DONE_MASK) /**< LPC_FLASHCTRL_FMSTAT.SIG_DONE Field     */
/** @} */

/** @name FMSTATCLR - Signature generation status clear register */ /** @{ */
#define LPC_FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_MASK (0x4U)                                             /**< LPC_FLASHCTRL_FMSTATCLR.SIG_DONE_CLR Mask*/
#define LPC_FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_SHIFT (2U)                                              /**< LPC_FLASHCTRL_FMSTATCLR.SIG_DONE_CLR Position*/
#define LPC_FLASHCTRL_FMSTATCLR_SIG_DONE_CLR(x)  (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_SHIFT))&LPC_FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_MASK) /**< LPC_FLASHCTRL_FMSTATCLR.SIG_DONE_CLR Field*/
/** @} */

/** @} */ /* End group FLASHCTRL_Register_Masks_GROUP */


/* LPC_FLASHCTRL - Peripheral instance base addresses */
#define LPC_FLASHCTRL_BasePtr          0x4003C000UL //!< Peripheral base address
#define LPC_FLASHCTRL                  ((LPC_FLASHCTRL_Type *) LPC_FLASHCTRL_BasePtr) //!< Freescale base pointer
#define LPC_FLASHCTRL_BASE_PTR         (LPC_FLASHCTRL) //!< Freescale style base pointer

/** @} */ /* End group FLASHCTRL_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO_GROUP_INT0 */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_GROUP_INT0_Peripheral_access_layer_GROUP GPIO_GROUP_INT0 Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_GPIO_GROUP_INT0 (file:GPIO_GROUP_INT0_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief GPIO group interrupt
 */
/**
 * @struct LPC_GPIO_GROUP_INT0_Type
 * @brief  C Struct allowing access to GPIO_GROUP_INT0 registers
 */
typedef struct LPC_GPIO_GROUP_INT0_Type {
   __IO uint32_t  CTRL;                         /**< 0000: GPIO grouped interrupt control register                      */
        uint8_t   RESERVED_0[28];               /**< 0004: 0x1C bytes                                                   */
   __IO uint32_t  PORT_POL[2];                  /**< 0020: GPIO grouped interrupt port  polarity register               */
        uint8_t   RESERVED_1[24];               /**< 0028: 0x18 bytes                                                   */
   __IO uint32_t  PORT_ENA[2];                  /**< 0040: GPIO grouped interrupt port  enable register                 */
} LPC_GPIO_GROUP_INT0_Type;


/** @brief Register Masks for GPIO_GROUP_INT0 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_GPIO_GROUP_INT0' Position & Mask macros         ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup GPIO_GROUP_INT0_Register_Masks_GROUP GPIO_GROUP_INT0 Register Masks */
/** @{ */

/** @name CTRL - GPIO grouped interrupt control register */ /** @{ */
#define LPC_GPIO_GROUP_INT0_CTRL_INT_MASK        (0x1U)                                              /**< LPC_GPIO_GROUP_INT0_CTRL.INT Mask       */
#define LPC_GPIO_GROUP_INT0_CTRL_INT_SHIFT       (0U)                                                /**< LPC_GPIO_GROUP_INT0_CTRL.INT Position   */
#define LPC_GPIO_GROUP_INT0_CTRL_INT(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_CTRL_INT_SHIFT))&LPC_GPIO_GROUP_INT0_CTRL_INT_MASK) /**< LPC_GPIO_GROUP_INT0_CTRL.INT Field      */
#define LPC_GPIO_GROUP_INT0_CTRL_COMB_MASK       (0x2U)                                              /**< LPC_GPIO_GROUP_INT0_CTRL.COMB Mask      */
#define LPC_GPIO_GROUP_INT0_CTRL_COMB_SHIFT      (1U)                                                /**< LPC_GPIO_GROUP_INT0_CTRL.COMB Position  */
#define LPC_GPIO_GROUP_INT0_CTRL_COMB(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_CTRL_COMB_SHIFT))&LPC_GPIO_GROUP_INT0_CTRL_COMB_MASK) /**< LPC_GPIO_GROUP_INT0_CTRL.COMB Field     */
#define LPC_GPIO_GROUP_INT0_CTRL_TRIG_MASK       (0x4U)                                              /**< LPC_GPIO_GROUP_INT0_CTRL.TRIG Mask      */
#define LPC_GPIO_GROUP_INT0_CTRL_TRIG_SHIFT      (2U)                                                /**< LPC_GPIO_GROUP_INT0_CTRL.TRIG Position  */
#define LPC_GPIO_GROUP_INT0_CTRL_TRIG(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_CTRL_TRIG_SHIFT))&LPC_GPIO_GROUP_INT0_CTRL_TRIG_MASK) /**< LPC_GPIO_GROUP_INT0_CTRL.TRIG Field     */
/** @} */

/** @name PORT_POL - GPIO grouped interrupt port %s polarity register */ /** @{ */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_0_MASK  (0x1U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_0 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_0_SHIFT (0U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_0 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_0(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_0_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_0_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_0 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_1_MASK  (0x2U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_1 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_1_SHIFT (1U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_1 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_1(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_1_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_1_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_1 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_2_MASK  (0x4U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_2 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_2_SHIFT (2U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_2 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_2(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_2_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_2_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_2 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_3_MASK  (0x8U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_3 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_3_SHIFT (3U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_3 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_3(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_3_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_3_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_3 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_4_MASK  (0x10U)                                             /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_4 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_4_SHIFT (4U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_4 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_4(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_4_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_4_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_4 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_5_MASK  (0x20U)                                             /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_5 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_5_SHIFT (5U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_5 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_5(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_5_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_5_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_5 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_6_MASK  (0x40U)                                             /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_6 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_6_SHIFT (6U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_6 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_6(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_6_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_6_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_6 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_7_MASK  (0x80U)                                             /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_7 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_7_SHIFT (7U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_7 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_7(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_7_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_7_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_7 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_8_MASK  (0x100U)                                            /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_8 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_8_SHIFT (8U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_8 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_8(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_8_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_8_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_8 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_9_MASK  (0x200U)                                            /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_9 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_9_SHIFT (9U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_9 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_9(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_9_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_9_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_9 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_10_MASK (0x400U)                                            /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_10 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_10_SHIFT (10U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_10 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_10(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_10_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_10_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_10 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_11_MASK (0x800U)                                            /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_11 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_11_SHIFT (11U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_11 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_11(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_11_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_11_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_11 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_12_MASK (0x1000U)                                           /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_12 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_12_SHIFT (12U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_12 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_12(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_12_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_12_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_12 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_13_MASK (0x2000U)                                           /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_13 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_13_SHIFT (13U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_13 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_13(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_13_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_13_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_13 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_14_MASK (0x4000U)                                           /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_14 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_14_SHIFT (14U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_14 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_14(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_14_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_14_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_14 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_15_MASK (0x8000U)                                           /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_15 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_15_SHIFT (15U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_15 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_15(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_15_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_15_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_15 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_16_MASK (0x10000U)                                          /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_16 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_16_SHIFT (16U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_16 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_16(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_16_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_16_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_16 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_17_MASK (0x20000U)                                          /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_17 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_17_SHIFT (17U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_17 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_17(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_17_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_17_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_17 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_18_MASK (0x40000U)                                          /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_18 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_18_SHIFT (18U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_18 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_18(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_18_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_18_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_18 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_19_MASK (0x80000U)                                          /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_19 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_19_SHIFT (19U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_19 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_19(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_19_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_19_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_19 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_20_MASK (0x100000U)                                         /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_20 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_20_SHIFT (20U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_20 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_20(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_20_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_20_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_20 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_21_MASK (0x200000U)                                         /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_21 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_21_SHIFT (21U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_21 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_21(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_21_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_21_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_21 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_22_MASK (0x400000U)                                         /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_22 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_22_SHIFT (22U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_22 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_22(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_22_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_22_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_22 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_23_MASK (0x800000U)                                         /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_23 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_23_SHIFT (23U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_23 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_23(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_23_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_23_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_23 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_24_MASK (0x1000000U)                                        /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_24 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_24_SHIFT (24U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_24 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_24(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_24_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_24_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_24 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_25_MASK (0x2000000U)                                        /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_25 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_25_SHIFT (25U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_25 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_25(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_25_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_25_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_25 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_26_MASK (0x4000000U)                                        /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_26 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_26_SHIFT (26U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_26 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_26(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_26_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_26_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_26 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_27_MASK (0x8000000U)                                        /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_27 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_27_SHIFT (27U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_27 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_27(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_27_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_27_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_27 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_28_MASK (0x10000000U)                                       /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_28 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_28_SHIFT (28U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_28 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_28(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_28_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_28_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_28 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_29_MASK (0x20000000U)                                       /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_29 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_29_SHIFT (29U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_29 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_29(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_29_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_29_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_29 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_30_MASK (0x40000000U)                                       /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_30 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_30_SHIFT (30U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_30 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_30(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_30_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_30_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_30 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_31_MASK (0x80000000U)                                       /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_31 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_31_SHIFT (31U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_31 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_POL_POL_31(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_POL_POL_31_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_POL_POL_31_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_POL.POL_31 Field*/
/** @} */

/** @name PORT_ENA - GPIO grouped interrupt port %s enable register */ /** @{ */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_0_MASK  (0x1U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_0 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_0_SHIFT (0U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_0 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_0(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_0_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_0_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_0 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_1_MASK  (0x2U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_1 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_1_SHIFT (1U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_1 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_1(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_1_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_1_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_1 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_2_MASK  (0x4U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_2 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_2_SHIFT (2U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_2 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_2(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_2_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_2_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_2 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_3_MASK  (0x8U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_3 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_3_SHIFT (3U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_3 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_3(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_3_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_3_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_3 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_4_MASK  (0x10U)                                             /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_4 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_4_SHIFT (4U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_4 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_4(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_4_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_4_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_4 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_5_MASK  (0x20U)                                             /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_5 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_5_SHIFT (5U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_5 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_5(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_5_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_5_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_5 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_6_MASK  (0x40U)                                             /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_6 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_6_SHIFT (6U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_6 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_6(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_6_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_6_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_6 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_7_MASK  (0x80U)                                             /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_7 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_7_SHIFT (7U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_7 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_7(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_7_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_7_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_7 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_8_MASK  (0x100U)                                            /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_8 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_8_SHIFT (8U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_8 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_8(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_8_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_8_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_8 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_9_MASK  (0x200U)                                            /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_9 Mask */
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_9_SHIFT (9U)                                                /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_9 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_9(x)    (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_9_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_9_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_9 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_10_MASK (0x400U)                                            /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_10 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_10_SHIFT (10U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_10 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_10(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_10_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_10_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_10 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_11_MASK (0x800U)                                            /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_11 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_11_SHIFT (11U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_11 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_11(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_11_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_11_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_11 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_12_MASK (0x1000U)                                           /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_12 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_12_SHIFT (12U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_12 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_12(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_12_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_12_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_12 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_13_MASK (0x2000U)                                           /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_13 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_13_SHIFT (13U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_13 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_13(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_13_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_13_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_13 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_14_MASK (0x4000U)                                           /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_14 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_14_SHIFT (14U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_14 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_14(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_14_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_14_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_14 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_15_MASK (0x8000U)                                           /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_15 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_15_SHIFT (15U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_15 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_15(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_15_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_15_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_15 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_16_MASK (0x10000U)                                          /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_16 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_16_SHIFT (16U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_16 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_16(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_16_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_16_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_16 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_17_MASK (0x20000U)                                          /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_17 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_17_SHIFT (17U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_17 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_17(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_17_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_17_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_17 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_18_MASK (0x40000U)                                          /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_18 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_18_SHIFT (18U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_18 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_18(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_18_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_18_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_18 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_19_MASK (0x80000U)                                          /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_19 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_19_SHIFT (19U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_19 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_19(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_19_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_19_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_19 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_20_MASK (0x100000U)                                         /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_20 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_20_SHIFT (20U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_20 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_20(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_20_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_20_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_20 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_21_MASK (0x200000U)                                         /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_21 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_21_SHIFT (21U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_21 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_21(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_21_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_21_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_21 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_22_MASK (0x400000U)                                         /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_22 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_22_SHIFT (22U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_22 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_22(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_22_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_22_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_22 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_23_MASK (0x800000U)                                         /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_23 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_23_SHIFT (23U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_23 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_23(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_23_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_23_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_23 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_24_MASK (0x1000000U)                                        /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_24 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_24_SHIFT (24U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_24 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_24(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_24_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_24_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_24 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_25_MASK (0x2000000U)                                        /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_25 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_25_SHIFT (25U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_25 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_25(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_25_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_25_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_25 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_26_MASK (0x4000000U)                                        /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_26 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_26_SHIFT (26U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_26 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_26(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_26_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_26_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_26 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_27_MASK (0x8000000U)                                        /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_27 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_27_SHIFT (27U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_27 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_27(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_27_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_27_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_27 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_28_MASK (0x10000000U)                                       /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_28 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_28_SHIFT (28U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_28 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_28(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_28_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_28_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_28 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_29_MASK (0x20000000U)                                       /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_29 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_29_SHIFT (29U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_29 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_29(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_29_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_29_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_29 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_30_MASK (0x40000000U)                                       /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_30 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_30_SHIFT (30U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_30 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_30(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_30_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_30_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_30 Field*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_31_MASK (0x80000000U)                                       /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_31 Mask*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_31_SHIFT (31U)                                              /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_31 Position*/
#define LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_31(x)   (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_31_SHIFT))&LPC_GPIO_GROUP_INT0_PORT_ENA_ENA_31_MASK) /**< LPC_GPIO_GROUP_INT0_PORT_ENA.ENA_31 Field*/
/** @} */

/** @} */ /* End group GPIO_GROUP_INT0_Register_Masks_GROUP */


/* LPC_GPIO_GROUP_INT0 - Peripheral instance base addresses */
#define LPC_GPIO_GROUP_INT0_BasePtr    0x4005C000UL //!< Peripheral base address
#define LPC_GPIO_GROUP_INT0            ((LPC_GPIO_GROUP_INT0_Type *) LPC_GPIO_GROUP_INT0_BasePtr) //!< Freescale base pointer
#define LPC_GPIO_GROUP_INT0_BASE_PTR   (LPC_GPIO_GROUP_INT0) //!< Freescale style base pointer

/** @} */ /* End group GPIO_GROUP_INT0_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO_GROUP_INT0 */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_GROUP_INT0_Peripheral_access_layer_GROUP GPIO_GROUP_INT0 Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_GPIO_GROUP_INT1 (derived from GPIO_GROUP_INT0)       ================ */
/* ================================================================================ */

/**
 * @brief GPIO group interrupt
 */

/* LPC_GPIO_GROUP_INT1 - Peripheral instance base addresses */
#define LPC_GPIO_GROUP_INT1_BasePtr    0x40060000UL //!< Peripheral base address
#define LPC_GPIO_GROUP_INT1            ((LPC_GPIO_GROUP_INT0_Type *) LPC_GPIO_GROUP_INT1_BasePtr) //!< Freescale base pointer
#define LPC_GPIO_GROUP_INT1_BASE_PTR   (LPC_GPIO_GROUP_INT1) //!< Freescale style base pointer

/** @} */ /* End group GPIO_GROUP_INT0_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO_PIN_INT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_PIN_INT_Peripheral_access_layer_GROUP GPIO_PIN_INT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_GPIO_PIN_INT (file:GPIO_PIN_INT_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief GPIO pin interrupt
 */
/**
 * @struct LPC_GPIO_PIN_INT_Type
 * @brief  C Struct allowing access to GPIO_PIN_INT registers
 */
typedef struct LPC_GPIO_PIN_INT_Type {
   __IO uint32_t  ISEL;                         /**< 0000: Pin Interrupt Mode register                                  */
   __IO uint32_t  IENR;                         /**< 0004: Pin Interrupt Enable (Rising) register                       */
   __O  uint32_t  SIENR;                        /**< 0008: Set Pin Interrupt Enable (Rising) register                   */
   __O  uint32_t  CIENR;                        /**< 000C: Clear Pin Interrupt Enable (Rising) register                 */
   __IO uint32_t  IENF;                         /**< 0010: Pin Interrupt Enable Falling Edge / Active Level register    */
   __O  uint32_t  SIENF;                        /**< 0014: Set Pin Interrupt Enable Falling Edge / Active Level register */
   __O  uint32_t  CIENF;                        /**< 0018: Clear Pin Interrupt Enable Falling Edge / Active Level address */
   __IO uint32_t  RISE;                         /**< 001C: Pin Interrupt Rising Edge register                           */
   __IO uint32_t  FALL;                         /**< 0020: Pin Interrupt Falling Edge register                          */
   __IO uint32_t  IST;                          /**< 0024: Pin Interrupt Status register                                */
} LPC_GPIO_PIN_INT_Type;


/** @brief Register Masks for GPIO_PIN_INT */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_GPIO_PIN_INT' Position & Mask macros            ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup GPIO_PIN_INT_Register_Masks_GROUP GPIO_PIN_INT Register Masks */
/** @{ */

/** @name ISEL - Pin Interrupt Mode register */ /** @{ */
#define LPC_GPIO_PIN_INT_ISEL_PMODE0_MASK        (0x1U)                                              /**< LPC_GPIO_PIN_INT_ISEL.PMODE0 Mask       */
#define LPC_GPIO_PIN_INT_ISEL_PMODE0_SHIFT       (0U)                                                /**< LPC_GPIO_PIN_INT_ISEL.PMODE0 Position   */
#define LPC_GPIO_PIN_INT_ISEL_PMODE0(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_ISEL_PMODE0_SHIFT))&LPC_GPIO_PIN_INT_ISEL_PMODE0_MASK) /**< LPC_GPIO_PIN_INT_ISEL.PMODE0 Field      */
#define LPC_GPIO_PIN_INT_ISEL_PMODE1_MASK        (0x2U)                                              /**< LPC_GPIO_PIN_INT_ISEL.PMODE1 Mask       */
#define LPC_GPIO_PIN_INT_ISEL_PMODE1_SHIFT       (1U)                                                /**< LPC_GPIO_PIN_INT_ISEL.PMODE1 Position   */
#define LPC_GPIO_PIN_INT_ISEL_PMODE1(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_ISEL_PMODE1_SHIFT))&LPC_GPIO_PIN_INT_ISEL_PMODE1_MASK) /**< LPC_GPIO_PIN_INT_ISEL.PMODE1 Field      */
#define LPC_GPIO_PIN_INT_ISEL_PMODE2_MASK        (0x4U)                                              /**< LPC_GPIO_PIN_INT_ISEL.PMODE2 Mask       */
#define LPC_GPIO_PIN_INT_ISEL_PMODE2_SHIFT       (2U)                                                /**< LPC_GPIO_PIN_INT_ISEL.PMODE2 Position   */
#define LPC_GPIO_PIN_INT_ISEL_PMODE2(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_ISEL_PMODE2_SHIFT))&LPC_GPIO_PIN_INT_ISEL_PMODE2_MASK) /**< LPC_GPIO_PIN_INT_ISEL.PMODE2 Field      */
#define LPC_GPIO_PIN_INT_ISEL_PMODE3_MASK        (0x8U)                                              /**< LPC_GPIO_PIN_INT_ISEL.PMODE3 Mask       */
#define LPC_GPIO_PIN_INT_ISEL_PMODE3_SHIFT       (3U)                                                /**< LPC_GPIO_PIN_INT_ISEL.PMODE3 Position   */
#define LPC_GPIO_PIN_INT_ISEL_PMODE3(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_ISEL_PMODE3_SHIFT))&LPC_GPIO_PIN_INT_ISEL_PMODE3_MASK) /**< LPC_GPIO_PIN_INT_ISEL.PMODE3 Field      */
#define LPC_GPIO_PIN_INT_ISEL_PMODE4_MASK        (0x10U)                                             /**< LPC_GPIO_PIN_INT_ISEL.PMODE4 Mask       */
#define LPC_GPIO_PIN_INT_ISEL_PMODE4_SHIFT       (4U)                                                /**< LPC_GPIO_PIN_INT_ISEL.PMODE4 Position   */
#define LPC_GPIO_PIN_INT_ISEL_PMODE4(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_ISEL_PMODE4_SHIFT))&LPC_GPIO_PIN_INT_ISEL_PMODE4_MASK) /**< LPC_GPIO_PIN_INT_ISEL.PMODE4 Field      */
#define LPC_GPIO_PIN_INT_ISEL_PMODE5_MASK        (0x20U)                                             /**< LPC_GPIO_PIN_INT_ISEL.PMODE5 Mask       */
#define LPC_GPIO_PIN_INT_ISEL_PMODE5_SHIFT       (5U)                                                /**< LPC_GPIO_PIN_INT_ISEL.PMODE5 Position   */
#define LPC_GPIO_PIN_INT_ISEL_PMODE5(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_ISEL_PMODE5_SHIFT))&LPC_GPIO_PIN_INT_ISEL_PMODE5_MASK) /**< LPC_GPIO_PIN_INT_ISEL.PMODE5 Field      */
#define LPC_GPIO_PIN_INT_ISEL_PMODE6_MASK        (0x40U)                                             /**< LPC_GPIO_PIN_INT_ISEL.PMODE6 Mask       */
#define LPC_GPIO_PIN_INT_ISEL_PMODE6_SHIFT       (6U)                                                /**< LPC_GPIO_PIN_INT_ISEL.PMODE6 Position   */
#define LPC_GPIO_PIN_INT_ISEL_PMODE6(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_ISEL_PMODE6_SHIFT))&LPC_GPIO_PIN_INT_ISEL_PMODE6_MASK) /**< LPC_GPIO_PIN_INT_ISEL.PMODE6 Field      */
#define LPC_GPIO_PIN_INT_ISEL_PMODE7_MASK        (0x80U)                                             /**< LPC_GPIO_PIN_INT_ISEL.PMODE7 Mask       */
#define LPC_GPIO_PIN_INT_ISEL_PMODE7_SHIFT       (7U)                                                /**< LPC_GPIO_PIN_INT_ISEL.PMODE7 Position   */
#define LPC_GPIO_PIN_INT_ISEL_PMODE7(x)          (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_ISEL_PMODE7_SHIFT))&LPC_GPIO_PIN_INT_ISEL_PMODE7_MASK) /**< LPC_GPIO_PIN_INT_ISEL.PMODE7 Field      */
/** @} */

/** @name IENR - Pin Interrupt Enable (Rising) register */ /** @{ */
#define LPC_GPIO_PIN_INT_IENR_ENRL0_MASK         (0x1U)                                              /**< LPC_GPIO_PIN_INT_IENR.ENRL0 Mask        */
#define LPC_GPIO_PIN_INT_IENR_ENRL0_SHIFT        (0U)                                                /**< LPC_GPIO_PIN_INT_IENR.ENRL0 Position    */
#define LPC_GPIO_PIN_INT_IENR_ENRL0(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENR_ENRL0_SHIFT))&LPC_GPIO_PIN_INT_IENR_ENRL0_MASK) /**< LPC_GPIO_PIN_INT_IENR.ENRL0 Field       */
#define LPC_GPIO_PIN_INT_IENR_ENRL1_MASK         (0x2U)                                              /**< LPC_GPIO_PIN_INT_IENR.ENRL1 Mask        */
#define LPC_GPIO_PIN_INT_IENR_ENRL1_SHIFT        (1U)                                                /**< LPC_GPIO_PIN_INT_IENR.ENRL1 Position    */
#define LPC_GPIO_PIN_INT_IENR_ENRL1(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENR_ENRL1_SHIFT))&LPC_GPIO_PIN_INT_IENR_ENRL1_MASK) /**< LPC_GPIO_PIN_INT_IENR.ENRL1 Field       */
#define LPC_GPIO_PIN_INT_IENR_ENRL2_MASK         (0x4U)                                              /**< LPC_GPIO_PIN_INT_IENR.ENRL2 Mask        */
#define LPC_GPIO_PIN_INT_IENR_ENRL2_SHIFT        (2U)                                                /**< LPC_GPIO_PIN_INT_IENR.ENRL2 Position    */
#define LPC_GPIO_PIN_INT_IENR_ENRL2(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENR_ENRL2_SHIFT))&LPC_GPIO_PIN_INT_IENR_ENRL2_MASK) /**< LPC_GPIO_PIN_INT_IENR.ENRL2 Field       */
#define LPC_GPIO_PIN_INT_IENR_ENRL3_MASK         (0x8U)                                              /**< LPC_GPIO_PIN_INT_IENR.ENRL3 Mask        */
#define LPC_GPIO_PIN_INT_IENR_ENRL3_SHIFT        (3U)                                                /**< LPC_GPIO_PIN_INT_IENR.ENRL3 Position    */
#define LPC_GPIO_PIN_INT_IENR_ENRL3(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENR_ENRL3_SHIFT))&LPC_GPIO_PIN_INT_IENR_ENRL3_MASK) /**< LPC_GPIO_PIN_INT_IENR.ENRL3 Field       */
#define LPC_GPIO_PIN_INT_IENR_ENRL4_MASK         (0x10U)                                             /**< LPC_GPIO_PIN_INT_IENR.ENRL4 Mask        */
#define LPC_GPIO_PIN_INT_IENR_ENRL4_SHIFT        (4U)                                                /**< LPC_GPIO_PIN_INT_IENR.ENRL4 Position    */
#define LPC_GPIO_PIN_INT_IENR_ENRL4(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENR_ENRL4_SHIFT))&LPC_GPIO_PIN_INT_IENR_ENRL4_MASK) /**< LPC_GPIO_PIN_INT_IENR.ENRL4 Field       */
#define LPC_GPIO_PIN_INT_IENR_ENRL5_MASK         (0x20U)                                             /**< LPC_GPIO_PIN_INT_IENR.ENRL5 Mask        */
#define LPC_GPIO_PIN_INT_IENR_ENRL5_SHIFT        (5U)                                                /**< LPC_GPIO_PIN_INT_IENR.ENRL5 Position    */
#define LPC_GPIO_PIN_INT_IENR_ENRL5(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENR_ENRL5_SHIFT))&LPC_GPIO_PIN_INT_IENR_ENRL5_MASK) /**< LPC_GPIO_PIN_INT_IENR.ENRL5 Field       */
#define LPC_GPIO_PIN_INT_IENR_ENRL6_MASK         (0x40U)                                             /**< LPC_GPIO_PIN_INT_IENR.ENRL6 Mask        */
#define LPC_GPIO_PIN_INT_IENR_ENRL6_SHIFT        (6U)                                                /**< LPC_GPIO_PIN_INT_IENR.ENRL6 Position    */
#define LPC_GPIO_PIN_INT_IENR_ENRL6(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENR_ENRL6_SHIFT))&LPC_GPIO_PIN_INT_IENR_ENRL6_MASK) /**< LPC_GPIO_PIN_INT_IENR.ENRL6 Field       */
#define LPC_GPIO_PIN_INT_IENR_ENRL7_MASK         (0x80U)                                             /**< LPC_GPIO_PIN_INT_IENR.ENRL7 Mask        */
#define LPC_GPIO_PIN_INT_IENR_ENRL7_SHIFT        (7U)                                                /**< LPC_GPIO_PIN_INT_IENR.ENRL7 Position    */
#define LPC_GPIO_PIN_INT_IENR_ENRL7(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENR_ENRL7_SHIFT))&LPC_GPIO_PIN_INT_IENR_ENRL7_MASK) /**< LPC_GPIO_PIN_INT_IENR.ENRL7 Field       */
/** @} */

/** @name SIENR - Set Pin Interrupt Enable (Rising) register */ /** @{ */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL0_MASK     (0x1U)                                              /**< LPC_GPIO_PIN_INT_SIENR.SETENRL0 Mask    */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL0_SHIFT    (0U)                                                /**< LPC_GPIO_PIN_INT_SIENR.SETENRL0 Position*/
#define LPC_GPIO_PIN_INT_SIENR_SETENRL0(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENR_SETENRL0_SHIFT))&LPC_GPIO_PIN_INT_SIENR_SETENRL0_MASK) /**< LPC_GPIO_PIN_INT_SIENR.SETENRL0 Field   */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL1_MASK     (0x2U)                                              /**< LPC_GPIO_PIN_INT_SIENR.SETENRL1 Mask    */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL1_SHIFT    (1U)                                                /**< LPC_GPIO_PIN_INT_SIENR.SETENRL1 Position*/
#define LPC_GPIO_PIN_INT_SIENR_SETENRL1(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENR_SETENRL1_SHIFT))&LPC_GPIO_PIN_INT_SIENR_SETENRL1_MASK) /**< LPC_GPIO_PIN_INT_SIENR.SETENRL1 Field   */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL2_MASK     (0x4U)                                              /**< LPC_GPIO_PIN_INT_SIENR.SETENRL2 Mask    */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL2_SHIFT    (2U)                                                /**< LPC_GPIO_PIN_INT_SIENR.SETENRL2 Position*/
#define LPC_GPIO_PIN_INT_SIENR_SETENRL2(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENR_SETENRL2_SHIFT))&LPC_GPIO_PIN_INT_SIENR_SETENRL2_MASK) /**< LPC_GPIO_PIN_INT_SIENR.SETENRL2 Field   */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL3_MASK     (0x8U)                                              /**< LPC_GPIO_PIN_INT_SIENR.SETENRL3 Mask    */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL3_SHIFT    (3U)                                                /**< LPC_GPIO_PIN_INT_SIENR.SETENRL3 Position*/
#define LPC_GPIO_PIN_INT_SIENR_SETENRL3(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENR_SETENRL3_SHIFT))&LPC_GPIO_PIN_INT_SIENR_SETENRL3_MASK) /**< LPC_GPIO_PIN_INT_SIENR.SETENRL3 Field   */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL4_MASK     (0x10U)                                             /**< LPC_GPIO_PIN_INT_SIENR.SETENRL4 Mask    */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL4_SHIFT    (4U)                                                /**< LPC_GPIO_PIN_INT_SIENR.SETENRL4 Position*/
#define LPC_GPIO_PIN_INT_SIENR_SETENRL4(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENR_SETENRL4_SHIFT))&LPC_GPIO_PIN_INT_SIENR_SETENRL4_MASK) /**< LPC_GPIO_PIN_INT_SIENR.SETENRL4 Field   */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL5_MASK     (0x20U)                                             /**< LPC_GPIO_PIN_INT_SIENR.SETENRL5 Mask    */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL5_SHIFT    (5U)                                                /**< LPC_GPIO_PIN_INT_SIENR.SETENRL5 Position*/
#define LPC_GPIO_PIN_INT_SIENR_SETENRL5(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENR_SETENRL5_SHIFT))&LPC_GPIO_PIN_INT_SIENR_SETENRL5_MASK) /**< LPC_GPIO_PIN_INT_SIENR.SETENRL5 Field   */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL6_MASK     (0x40U)                                             /**< LPC_GPIO_PIN_INT_SIENR.SETENRL6 Mask    */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL6_SHIFT    (6U)                                                /**< LPC_GPIO_PIN_INT_SIENR.SETENRL6 Position*/
#define LPC_GPIO_PIN_INT_SIENR_SETENRL6(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENR_SETENRL6_SHIFT))&LPC_GPIO_PIN_INT_SIENR_SETENRL6_MASK) /**< LPC_GPIO_PIN_INT_SIENR.SETENRL6 Field   */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL7_MASK     (0x80U)                                             /**< LPC_GPIO_PIN_INT_SIENR.SETENRL7 Mask    */
#define LPC_GPIO_PIN_INT_SIENR_SETENRL7_SHIFT    (7U)                                                /**< LPC_GPIO_PIN_INT_SIENR.SETENRL7 Position*/
#define LPC_GPIO_PIN_INT_SIENR_SETENRL7(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENR_SETENRL7_SHIFT))&LPC_GPIO_PIN_INT_SIENR_SETENRL7_MASK) /**< LPC_GPIO_PIN_INT_SIENR.SETENRL7 Field   */
/** @} */

/** @name CIENR - Clear Pin Interrupt Enable (Rising) register */ /** @{ */
#define LPC_GPIO_PIN_INT_CIENR_CENRL0_MASK       (0x1U)                                              /**< LPC_GPIO_PIN_INT_CIENR.CENRL0 Mask      */
#define LPC_GPIO_PIN_INT_CIENR_CENRL0_SHIFT      (0U)                                                /**< LPC_GPIO_PIN_INT_CIENR.CENRL0 Position  */
#define LPC_GPIO_PIN_INT_CIENR_CENRL0(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENR_CENRL0_SHIFT))&LPC_GPIO_PIN_INT_CIENR_CENRL0_MASK) /**< LPC_GPIO_PIN_INT_CIENR.CENRL0 Field     */
#define LPC_GPIO_PIN_INT_CIENR_CENRL1_MASK       (0x2U)                                              /**< LPC_GPIO_PIN_INT_CIENR.CENRL1 Mask      */
#define LPC_GPIO_PIN_INT_CIENR_CENRL1_SHIFT      (1U)                                                /**< LPC_GPIO_PIN_INT_CIENR.CENRL1 Position  */
#define LPC_GPIO_PIN_INT_CIENR_CENRL1(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENR_CENRL1_SHIFT))&LPC_GPIO_PIN_INT_CIENR_CENRL1_MASK) /**< LPC_GPIO_PIN_INT_CIENR.CENRL1 Field     */
#define LPC_GPIO_PIN_INT_CIENR_CENRL2_MASK       (0x4U)                                              /**< LPC_GPIO_PIN_INT_CIENR.CENRL2 Mask      */
#define LPC_GPIO_PIN_INT_CIENR_CENRL2_SHIFT      (2U)                                                /**< LPC_GPIO_PIN_INT_CIENR.CENRL2 Position  */
#define LPC_GPIO_PIN_INT_CIENR_CENRL2(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENR_CENRL2_SHIFT))&LPC_GPIO_PIN_INT_CIENR_CENRL2_MASK) /**< LPC_GPIO_PIN_INT_CIENR.CENRL2 Field     */
#define LPC_GPIO_PIN_INT_CIENR_CENRL3_MASK       (0x8U)                                              /**< LPC_GPIO_PIN_INT_CIENR.CENRL3 Mask      */
#define LPC_GPIO_PIN_INT_CIENR_CENRL3_SHIFT      (3U)                                                /**< LPC_GPIO_PIN_INT_CIENR.CENRL3 Position  */
#define LPC_GPIO_PIN_INT_CIENR_CENRL3(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENR_CENRL3_SHIFT))&LPC_GPIO_PIN_INT_CIENR_CENRL3_MASK) /**< LPC_GPIO_PIN_INT_CIENR.CENRL3 Field     */
#define LPC_GPIO_PIN_INT_CIENR_CENRL4_MASK       (0x10U)                                             /**< LPC_GPIO_PIN_INT_CIENR.CENRL4 Mask      */
#define LPC_GPIO_PIN_INT_CIENR_CENRL4_SHIFT      (4U)                                                /**< LPC_GPIO_PIN_INT_CIENR.CENRL4 Position  */
#define LPC_GPIO_PIN_INT_CIENR_CENRL4(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENR_CENRL4_SHIFT))&LPC_GPIO_PIN_INT_CIENR_CENRL4_MASK) /**< LPC_GPIO_PIN_INT_CIENR.CENRL4 Field     */
#define LPC_GPIO_PIN_INT_CIENR_CENRL5_MASK       (0x20U)                                             /**< LPC_GPIO_PIN_INT_CIENR.CENRL5 Mask      */
#define LPC_GPIO_PIN_INT_CIENR_CENRL5_SHIFT      (5U)                                                /**< LPC_GPIO_PIN_INT_CIENR.CENRL5 Position  */
#define LPC_GPIO_PIN_INT_CIENR_CENRL5(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENR_CENRL5_SHIFT))&LPC_GPIO_PIN_INT_CIENR_CENRL5_MASK) /**< LPC_GPIO_PIN_INT_CIENR.CENRL5 Field     */
#define LPC_GPIO_PIN_INT_CIENR_CENRL6_MASK       (0x40U)                                             /**< LPC_GPIO_PIN_INT_CIENR.CENRL6 Mask      */
#define LPC_GPIO_PIN_INT_CIENR_CENRL6_SHIFT      (6U)                                                /**< LPC_GPIO_PIN_INT_CIENR.CENRL6 Position  */
#define LPC_GPIO_PIN_INT_CIENR_CENRL6(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENR_CENRL6_SHIFT))&LPC_GPIO_PIN_INT_CIENR_CENRL6_MASK) /**< LPC_GPIO_PIN_INT_CIENR.CENRL6 Field     */
#define LPC_GPIO_PIN_INT_CIENR_CENRL7_MASK       (0x80U)                                             /**< LPC_GPIO_PIN_INT_CIENR.CENRL7 Mask      */
#define LPC_GPIO_PIN_INT_CIENR_CENRL7_SHIFT      (7U)                                                /**< LPC_GPIO_PIN_INT_CIENR.CENRL7 Position  */
#define LPC_GPIO_PIN_INT_CIENR_CENRL7(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENR_CENRL7_SHIFT))&LPC_GPIO_PIN_INT_CIENR_CENRL7_MASK) /**< LPC_GPIO_PIN_INT_CIENR.CENRL7 Field     */
/** @} */

/** @name IENF - Pin Interrupt Enable Falling Edge / Active Level register */ /** @{ */
#define LPC_GPIO_PIN_INT_IENF_ENAF0_MASK         (0x1U)                                              /**< LPC_GPIO_PIN_INT_IENF.ENAF0 Mask        */
#define LPC_GPIO_PIN_INT_IENF_ENAF0_SHIFT        (0U)                                                /**< LPC_GPIO_PIN_INT_IENF.ENAF0 Position    */
#define LPC_GPIO_PIN_INT_IENF_ENAF0(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENF_ENAF0_SHIFT))&LPC_GPIO_PIN_INT_IENF_ENAF0_MASK) /**< LPC_GPIO_PIN_INT_IENF.ENAF0 Field       */
#define LPC_GPIO_PIN_INT_IENF_ENAF1_MASK         (0x2U)                                              /**< LPC_GPIO_PIN_INT_IENF.ENAF1 Mask        */
#define LPC_GPIO_PIN_INT_IENF_ENAF1_SHIFT        (1U)                                                /**< LPC_GPIO_PIN_INT_IENF.ENAF1 Position    */
#define LPC_GPIO_PIN_INT_IENF_ENAF1(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENF_ENAF1_SHIFT))&LPC_GPIO_PIN_INT_IENF_ENAF1_MASK) /**< LPC_GPIO_PIN_INT_IENF.ENAF1 Field       */
#define LPC_GPIO_PIN_INT_IENF_ENAF2_MASK         (0x4U)                                              /**< LPC_GPIO_PIN_INT_IENF.ENAF2 Mask        */
#define LPC_GPIO_PIN_INT_IENF_ENAF2_SHIFT        (2U)                                                /**< LPC_GPIO_PIN_INT_IENF.ENAF2 Position    */
#define LPC_GPIO_PIN_INT_IENF_ENAF2(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENF_ENAF2_SHIFT))&LPC_GPIO_PIN_INT_IENF_ENAF2_MASK) /**< LPC_GPIO_PIN_INT_IENF.ENAF2 Field       */
#define LPC_GPIO_PIN_INT_IENF_ENAF3_MASK         (0x8U)                                              /**< LPC_GPIO_PIN_INT_IENF.ENAF3 Mask        */
#define LPC_GPIO_PIN_INT_IENF_ENAF3_SHIFT        (3U)                                                /**< LPC_GPIO_PIN_INT_IENF.ENAF3 Position    */
#define LPC_GPIO_PIN_INT_IENF_ENAF3(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENF_ENAF3_SHIFT))&LPC_GPIO_PIN_INT_IENF_ENAF3_MASK) /**< LPC_GPIO_PIN_INT_IENF.ENAF3 Field       */
#define LPC_GPIO_PIN_INT_IENF_ENAF4_MASK         (0x10U)                                             /**< LPC_GPIO_PIN_INT_IENF.ENAF4 Mask        */
#define LPC_GPIO_PIN_INT_IENF_ENAF4_SHIFT        (4U)                                                /**< LPC_GPIO_PIN_INT_IENF.ENAF4 Position    */
#define LPC_GPIO_PIN_INT_IENF_ENAF4(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENF_ENAF4_SHIFT))&LPC_GPIO_PIN_INT_IENF_ENAF4_MASK) /**< LPC_GPIO_PIN_INT_IENF.ENAF4 Field       */
#define LPC_GPIO_PIN_INT_IENF_ENAF5_MASK         (0x20U)                                             /**< LPC_GPIO_PIN_INT_IENF.ENAF5 Mask        */
#define LPC_GPIO_PIN_INT_IENF_ENAF5_SHIFT        (5U)                                                /**< LPC_GPIO_PIN_INT_IENF.ENAF5 Position    */
#define LPC_GPIO_PIN_INT_IENF_ENAF5(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENF_ENAF5_SHIFT))&LPC_GPIO_PIN_INT_IENF_ENAF5_MASK) /**< LPC_GPIO_PIN_INT_IENF.ENAF5 Field       */
#define LPC_GPIO_PIN_INT_IENF_ENAF6_MASK         (0x40U)                                             /**< LPC_GPIO_PIN_INT_IENF.ENAF6 Mask        */
#define LPC_GPIO_PIN_INT_IENF_ENAF6_SHIFT        (6U)                                                /**< LPC_GPIO_PIN_INT_IENF.ENAF6 Position    */
#define LPC_GPIO_PIN_INT_IENF_ENAF6(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENF_ENAF6_SHIFT))&LPC_GPIO_PIN_INT_IENF_ENAF6_MASK) /**< LPC_GPIO_PIN_INT_IENF.ENAF6 Field       */
#define LPC_GPIO_PIN_INT_IENF_ENAF7_MASK         (0x80U)                                             /**< LPC_GPIO_PIN_INT_IENF.ENAF7 Mask        */
#define LPC_GPIO_PIN_INT_IENF_ENAF7_SHIFT        (7U)                                                /**< LPC_GPIO_PIN_INT_IENF.ENAF7 Position    */
#define LPC_GPIO_PIN_INT_IENF_ENAF7(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IENF_ENAF7_SHIFT))&LPC_GPIO_PIN_INT_IENF_ENAF7_MASK) /**< LPC_GPIO_PIN_INT_IENF.ENAF7 Field       */
/** @} */

/** @name SIENF - Set Pin Interrupt Enable Falling Edge / Active Level register */ /** @{ */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF0_MASK     (0x1U)                                              /**< LPC_GPIO_PIN_INT_SIENF.SETENAF0 Mask    */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF0_SHIFT    (0U)                                                /**< LPC_GPIO_PIN_INT_SIENF.SETENAF0 Position*/
#define LPC_GPIO_PIN_INT_SIENF_SETENAF0(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENF_SETENAF0_SHIFT))&LPC_GPIO_PIN_INT_SIENF_SETENAF0_MASK) /**< LPC_GPIO_PIN_INT_SIENF.SETENAF0 Field   */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF1_MASK     (0x2U)                                              /**< LPC_GPIO_PIN_INT_SIENF.SETENAF1 Mask    */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF1_SHIFT    (1U)                                                /**< LPC_GPIO_PIN_INT_SIENF.SETENAF1 Position*/
#define LPC_GPIO_PIN_INT_SIENF_SETENAF1(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENF_SETENAF1_SHIFT))&LPC_GPIO_PIN_INT_SIENF_SETENAF1_MASK) /**< LPC_GPIO_PIN_INT_SIENF.SETENAF1 Field   */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF2_MASK     (0x4U)                                              /**< LPC_GPIO_PIN_INT_SIENF.SETENAF2 Mask    */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF2_SHIFT    (2U)                                                /**< LPC_GPIO_PIN_INT_SIENF.SETENAF2 Position*/
#define LPC_GPIO_PIN_INT_SIENF_SETENAF2(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENF_SETENAF2_SHIFT))&LPC_GPIO_PIN_INT_SIENF_SETENAF2_MASK) /**< LPC_GPIO_PIN_INT_SIENF.SETENAF2 Field   */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF3_MASK     (0x8U)                                              /**< LPC_GPIO_PIN_INT_SIENF.SETENAF3 Mask    */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF3_SHIFT    (3U)                                                /**< LPC_GPIO_PIN_INT_SIENF.SETENAF3 Position*/
#define LPC_GPIO_PIN_INT_SIENF_SETENAF3(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENF_SETENAF3_SHIFT))&LPC_GPIO_PIN_INT_SIENF_SETENAF3_MASK) /**< LPC_GPIO_PIN_INT_SIENF.SETENAF3 Field   */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF4_MASK     (0x10U)                                             /**< LPC_GPIO_PIN_INT_SIENF.SETENAF4 Mask    */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF4_SHIFT    (4U)                                                /**< LPC_GPIO_PIN_INT_SIENF.SETENAF4 Position*/
#define LPC_GPIO_PIN_INT_SIENF_SETENAF4(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENF_SETENAF4_SHIFT))&LPC_GPIO_PIN_INT_SIENF_SETENAF4_MASK) /**< LPC_GPIO_PIN_INT_SIENF.SETENAF4 Field   */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF5_MASK     (0x20U)                                             /**< LPC_GPIO_PIN_INT_SIENF.SETENAF5 Mask    */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF5_SHIFT    (5U)                                                /**< LPC_GPIO_PIN_INT_SIENF.SETENAF5 Position*/
#define LPC_GPIO_PIN_INT_SIENF_SETENAF5(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENF_SETENAF5_SHIFT))&LPC_GPIO_PIN_INT_SIENF_SETENAF5_MASK) /**< LPC_GPIO_PIN_INT_SIENF.SETENAF5 Field   */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF6_MASK     (0x40U)                                             /**< LPC_GPIO_PIN_INT_SIENF.SETENAF6 Mask    */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF6_SHIFT    (6U)                                                /**< LPC_GPIO_PIN_INT_SIENF.SETENAF6 Position*/
#define LPC_GPIO_PIN_INT_SIENF_SETENAF6(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENF_SETENAF6_SHIFT))&LPC_GPIO_PIN_INT_SIENF_SETENAF6_MASK) /**< LPC_GPIO_PIN_INT_SIENF.SETENAF6 Field   */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF7_MASK     (0x80U)                                             /**< LPC_GPIO_PIN_INT_SIENF.SETENAF7 Mask    */
#define LPC_GPIO_PIN_INT_SIENF_SETENAF7_SHIFT    (7U)                                                /**< LPC_GPIO_PIN_INT_SIENF.SETENAF7 Position*/
#define LPC_GPIO_PIN_INT_SIENF_SETENAF7(x)       (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_SIENF_SETENAF7_SHIFT))&LPC_GPIO_PIN_INT_SIENF_SETENAF7_MASK) /**< LPC_GPIO_PIN_INT_SIENF.SETENAF7 Field   */
/** @} */

/** @name CIENF - Clear Pin Interrupt Enable Falling Edge / Active Level address */ /** @{ */
#define LPC_GPIO_PIN_INT_CIENF_CENAF0_MASK       (0x1U)                                              /**< LPC_GPIO_PIN_INT_CIENF.CENAF0 Mask      */
#define LPC_GPIO_PIN_INT_CIENF_CENAF0_SHIFT      (0U)                                                /**< LPC_GPIO_PIN_INT_CIENF.CENAF0 Position  */
#define LPC_GPIO_PIN_INT_CIENF_CENAF0(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENF_CENAF0_SHIFT))&LPC_GPIO_PIN_INT_CIENF_CENAF0_MASK) /**< LPC_GPIO_PIN_INT_CIENF.CENAF0 Field     */
#define LPC_GPIO_PIN_INT_CIENF_CENAF1_MASK       (0x2U)                                              /**< LPC_GPIO_PIN_INT_CIENF.CENAF1 Mask      */
#define LPC_GPIO_PIN_INT_CIENF_CENAF1_SHIFT      (1U)                                                /**< LPC_GPIO_PIN_INT_CIENF.CENAF1 Position  */
#define LPC_GPIO_PIN_INT_CIENF_CENAF1(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENF_CENAF1_SHIFT))&LPC_GPIO_PIN_INT_CIENF_CENAF1_MASK) /**< LPC_GPIO_PIN_INT_CIENF.CENAF1 Field     */
#define LPC_GPIO_PIN_INT_CIENF_CENAF2_MASK       (0x4U)                                              /**< LPC_GPIO_PIN_INT_CIENF.CENAF2 Mask      */
#define LPC_GPIO_PIN_INT_CIENF_CENAF2_SHIFT      (2U)                                                /**< LPC_GPIO_PIN_INT_CIENF.CENAF2 Position  */
#define LPC_GPIO_PIN_INT_CIENF_CENAF2(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENF_CENAF2_SHIFT))&LPC_GPIO_PIN_INT_CIENF_CENAF2_MASK) /**< LPC_GPIO_PIN_INT_CIENF.CENAF2 Field     */
#define LPC_GPIO_PIN_INT_CIENF_CENAF3_MASK       (0x8U)                                              /**< LPC_GPIO_PIN_INT_CIENF.CENAF3 Mask      */
#define LPC_GPIO_PIN_INT_CIENF_CENAF3_SHIFT      (3U)                                                /**< LPC_GPIO_PIN_INT_CIENF.CENAF3 Position  */
#define LPC_GPIO_PIN_INT_CIENF_CENAF3(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENF_CENAF3_SHIFT))&LPC_GPIO_PIN_INT_CIENF_CENAF3_MASK) /**< LPC_GPIO_PIN_INT_CIENF.CENAF3 Field     */
#define LPC_GPIO_PIN_INT_CIENF_CENAF4_MASK       (0x10U)                                             /**< LPC_GPIO_PIN_INT_CIENF.CENAF4 Mask      */
#define LPC_GPIO_PIN_INT_CIENF_CENAF4_SHIFT      (4U)                                                /**< LPC_GPIO_PIN_INT_CIENF.CENAF4 Position  */
#define LPC_GPIO_PIN_INT_CIENF_CENAF4(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENF_CENAF4_SHIFT))&LPC_GPIO_PIN_INT_CIENF_CENAF4_MASK) /**< LPC_GPIO_PIN_INT_CIENF.CENAF4 Field     */
#define LPC_GPIO_PIN_INT_CIENF_CENAF5_MASK       (0x20U)                                             /**< LPC_GPIO_PIN_INT_CIENF.CENAF5 Mask      */
#define LPC_GPIO_PIN_INT_CIENF_CENAF5_SHIFT      (5U)                                                /**< LPC_GPIO_PIN_INT_CIENF.CENAF5 Position  */
#define LPC_GPIO_PIN_INT_CIENF_CENAF5(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENF_CENAF5_SHIFT))&LPC_GPIO_PIN_INT_CIENF_CENAF5_MASK) /**< LPC_GPIO_PIN_INT_CIENF.CENAF5 Field     */
#define LPC_GPIO_PIN_INT_CIENF_CENAF6_MASK       (0x40U)                                             /**< LPC_GPIO_PIN_INT_CIENF.CENAF6 Mask      */
#define LPC_GPIO_PIN_INT_CIENF_CENAF6_SHIFT      (6U)                                                /**< LPC_GPIO_PIN_INT_CIENF.CENAF6 Position  */
#define LPC_GPIO_PIN_INT_CIENF_CENAF6(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENF_CENAF6_SHIFT))&LPC_GPIO_PIN_INT_CIENF_CENAF6_MASK) /**< LPC_GPIO_PIN_INT_CIENF.CENAF6 Field     */
#define LPC_GPIO_PIN_INT_CIENF_CENAF7_MASK       (0x80U)                                             /**< LPC_GPIO_PIN_INT_CIENF.CENAF7 Mask      */
#define LPC_GPIO_PIN_INT_CIENF_CENAF7_SHIFT      (7U)                                                /**< LPC_GPIO_PIN_INT_CIENF.CENAF7 Position  */
#define LPC_GPIO_PIN_INT_CIENF_CENAF7(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_CIENF_CENAF7_SHIFT))&LPC_GPIO_PIN_INT_CIENF_CENAF7_MASK) /**< LPC_GPIO_PIN_INT_CIENF.CENAF7 Field     */
/** @} */

/** @name RISE - Pin Interrupt Rising Edge register */ /** @{ */
#define LPC_GPIO_PIN_INT_RISE_RDET0_MASK         (0x1U)                                              /**< LPC_GPIO_PIN_INT_RISE.RDET0 Mask        */
#define LPC_GPIO_PIN_INT_RISE_RDET0_SHIFT        (0U)                                                /**< LPC_GPIO_PIN_INT_RISE.RDET0 Position    */
#define LPC_GPIO_PIN_INT_RISE_RDET0(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_RISE_RDET0_SHIFT))&LPC_GPIO_PIN_INT_RISE_RDET0_MASK) /**< LPC_GPIO_PIN_INT_RISE.RDET0 Field       */
#define LPC_GPIO_PIN_INT_RISE_RDET1_MASK         (0x2U)                                              /**< LPC_GPIO_PIN_INT_RISE.RDET1 Mask        */
#define LPC_GPIO_PIN_INT_RISE_RDET1_SHIFT        (1U)                                                /**< LPC_GPIO_PIN_INT_RISE.RDET1 Position    */
#define LPC_GPIO_PIN_INT_RISE_RDET1(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_RISE_RDET1_SHIFT))&LPC_GPIO_PIN_INT_RISE_RDET1_MASK) /**< LPC_GPIO_PIN_INT_RISE.RDET1 Field       */
#define LPC_GPIO_PIN_INT_RISE_RDET2_MASK         (0x4U)                                              /**< LPC_GPIO_PIN_INT_RISE.RDET2 Mask        */
#define LPC_GPIO_PIN_INT_RISE_RDET2_SHIFT        (2U)                                                /**< LPC_GPIO_PIN_INT_RISE.RDET2 Position    */
#define LPC_GPIO_PIN_INT_RISE_RDET2(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_RISE_RDET2_SHIFT))&LPC_GPIO_PIN_INT_RISE_RDET2_MASK) /**< LPC_GPIO_PIN_INT_RISE.RDET2 Field       */
#define LPC_GPIO_PIN_INT_RISE_RDET3_MASK         (0x8U)                                              /**< LPC_GPIO_PIN_INT_RISE.RDET3 Mask        */
#define LPC_GPIO_PIN_INT_RISE_RDET3_SHIFT        (3U)                                                /**< LPC_GPIO_PIN_INT_RISE.RDET3 Position    */
#define LPC_GPIO_PIN_INT_RISE_RDET3(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_RISE_RDET3_SHIFT))&LPC_GPIO_PIN_INT_RISE_RDET3_MASK) /**< LPC_GPIO_PIN_INT_RISE.RDET3 Field       */
#define LPC_GPIO_PIN_INT_RISE_RDET4_MASK         (0x10U)                                             /**< LPC_GPIO_PIN_INT_RISE.RDET4 Mask        */
#define LPC_GPIO_PIN_INT_RISE_RDET4_SHIFT        (4U)                                                /**< LPC_GPIO_PIN_INT_RISE.RDET4 Position    */
#define LPC_GPIO_PIN_INT_RISE_RDET4(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_RISE_RDET4_SHIFT))&LPC_GPIO_PIN_INT_RISE_RDET4_MASK) /**< LPC_GPIO_PIN_INT_RISE.RDET4 Field       */
#define LPC_GPIO_PIN_INT_RISE_RDET5_MASK         (0x20U)                                             /**< LPC_GPIO_PIN_INT_RISE.RDET5 Mask        */
#define LPC_GPIO_PIN_INT_RISE_RDET5_SHIFT        (5U)                                                /**< LPC_GPIO_PIN_INT_RISE.RDET5 Position    */
#define LPC_GPIO_PIN_INT_RISE_RDET5(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_RISE_RDET5_SHIFT))&LPC_GPIO_PIN_INT_RISE_RDET5_MASK) /**< LPC_GPIO_PIN_INT_RISE.RDET5 Field       */
#define LPC_GPIO_PIN_INT_RISE_RDET6_MASK         (0x40U)                                             /**< LPC_GPIO_PIN_INT_RISE.RDET6 Mask        */
#define LPC_GPIO_PIN_INT_RISE_RDET6_SHIFT        (6U)                                                /**< LPC_GPIO_PIN_INT_RISE.RDET6 Position    */
#define LPC_GPIO_PIN_INT_RISE_RDET6(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_RISE_RDET6_SHIFT))&LPC_GPIO_PIN_INT_RISE_RDET6_MASK) /**< LPC_GPIO_PIN_INT_RISE.RDET6 Field       */
#define LPC_GPIO_PIN_INT_RISE_RDET7_MASK         (0x80U)                                             /**< LPC_GPIO_PIN_INT_RISE.RDET7 Mask        */
#define LPC_GPIO_PIN_INT_RISE_RDET7_SHIFT        (7U)                                                /**< LPC_GPIO_PIN_INT_RISE.RDET7 Position    */
#define LPC_GPIO_PIN_INT_RISE_RDET7(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_RISE_RDET7_SHIFT))&LPC_GPIO_PIN_INT_RISE_RDET7_MASK) /**< LPC_GPIO_PIN_INT_RISE.RDET7 Field       */
/** @} */

/** @name FALL - Pin Interrupt Falling Edge register */ /** @{ */
#define LPC_GPIO_PIN_INT_FALL_FDET0_MASK         (0x1U)                                              /**< LPC_GPIO_PIN_INT_FALL.FDET0 Mask        */
#define LPC_GPIO_PIN_INT_FALL_FDET0_SHIFT        (0U)                                                /**< LPC_GPIO_PIN_INT_FALL.FDET0 Position    */
#define LPC_GPIO_PIN_INT_FALL_FDET0(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_FALL_FDET0_SHIFT))&LPC_GPIO_PIN_INT_FALL_FDET0_MASK) /**< LPC_GPIO_PIN_INT_FALL.FDET0 Field       */
#define LPC_GPIO_PIN_INT_FALL_FDET1_MASK         (0x2U)                                              /**< LPC_GPIO_PIN_INT_FALL.FDET1 Mask        */
#define LPC_GPIO_PIN_INT_FALL_FDET1_SHIFT        (1U)                                                /**< LPC_GPIO_PIN_INT_FALL.FDET1 Position    */
#define LPC_GPIO_PIN_INT_FALL_FDET1(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_FALL_FDET1_SHIFT))&LPC_GPIO_PIN_INT_FALL_FDET1_MASK) /**< LPC_GPIO_PIN_INT_FALL.FDET1 Field       */
#define LPC_GPIO_PIN_INT_FALL_FDET2_MASK         (0x4U)                                              /**< LPC_GPIO_PIN_INT_FALL.FDET2 Mask        */
#define LPC_GPIO_PIN_INT_FALL_FDET2_SHIFT        (2U)                                                /**< LPC_GPIO_PIN_INT_FALL.FDET2 Position    */
#define LPC_GPIO_PIN_INT_FALL_FDET2(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_FALL_FDET2_SHIFT))&LPC_GPIO_PIN_INT_FALL_FDET2_MASK) /**< LPC_GPIO_PIN_INT_FALL.FDET2 Field       */
#define LPC_GPIO_PIN_INT_FALL_FDET3_MASK         (0x8U)                                              /**< LPC_GPIO_PIN_INT_FALL.FDET3 Mask        */
#define LPC_GPIO_PIN_INT_FALL_FDET3_SHIFT        (3U)                                                /**< LPC_GPIO_PIN_INT_FALL.FDET3 Position    */
#define LPC_GPIO_PIN_INT_FALL_FDET3(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_FALL_FDET3_SHIFT))&LPC_GPIO_PIN_INT_FALL_FDET3_MASK) /**< LPC_GPIO_PIN_INT_FALL.FDET3 Field       */
#define LPC_GPIO_PIN_INT_FALL_FDET4_MASK         (0x10U)                                             /**< LPC_GPIO_PIN_INT_FALL.FDET4 Mask        */
#define LPC_GPIO_PIN_INT_FALL_FDET4_SHIFT        (4U)                                                /**< LPC_GPIO_PIN_INT_FALL.FDET4 Position    */
#define LPC_GPIO_PIN_INT_FALL_FDET4(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_FALL_FDET4_SHIFT))&LPC_GPIO_PIN_INT_FALL_FDET4_MASK) /**< LPC_GPIO_PIN_INT_FALL.FDET4 Field       */
#define LPC_GPIO_PIN_INT_FALL_FDET5_MASK         (0x20U)                                             /**< LPC_GPIO_PIN_INT_FALL.FDET5 Mask        */
#define LPC_GPIO_PIN_INT_FALL_FDET5_SHIFT        (5U)                                                /**< LPC_GPIO_PIN_INT_FALL.FDET5 Position    */
#define LPC_GPIO_PIN_INT_FALL_FDET5(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_FALL_FDET5_SHIFT))&LPC_GPIO_PIN_INT_FALL_FDET5_MASK) /**< LPC_GPIO_PIN_INT_FALL.FDET5 Field       */
#define LPC_GPIO_PIN_INT_FALL_FDET6_MASK         (0x40U)                                             /**< LPC_GPIO_PIN_INT_FALL.FDET6 Mask        */
#define LPC_GPIO_PIN_INT_FALL_FDET6_SHIFT        (6U)                                                /**< LPC_GPIO_PIN_INT_FALL.FDET6 Position    */
#define LPC_GPIO_PIN_INT_FALL_FDET6(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_FALL_FDET6_SHIFT))&LPC_GPIO_PIN_INT_FALL_FDET6_MASK) /**< LPC_GPIO_PIN_INT_FALL.FDET6 Field       */
#define LPC_GPIO_PIN_INT_FALL_FDET7_MASK         (0x80U)                                             /**< LPC_GPIO_PIN_INT_FALL.FDET7 Mask        */
#define LPC_GPIO_PIN_INT_FALL_FDET7_SHIFT        (7U)                                                /**< LPC_GPIO_PIN_INT_FALL.FDET7 Position    */
#define LPC_GPIO_PIN_INT_FALL_FDET7(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_FALL_FDET7_SHIFT))&LPC_GPIO_PIN_INT_FALL_FDET7_MASK) /**< LPC_GPIO_PIN_INT_FALL.FDET7 Field       */
/** @} */

/** @name IST - Pin Interrupt Status register */ /** @{ */
#define LPC_GPIO_PIN_INT_IST_PSTAT0_MASK         (0x1U)                                              /**< LPC_GPIO_PIN_INT_IST.PSTAT0 Mask        */
#define LPC_GPIO_PIN_INT_IST_PSTAT0_SHIFT        (0U)                                                /**< LPC_GPIO_PIN_INT_IST.PSTAT0 Position    */
#define LPC_GPIO_PIN_INT_IST_PSTAT0(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IST_PSTAT0_SHIFT))&LPC_GPIO_PIN_INT_IST_PSTAT0_MASK) /**< LPC_GPIO_PIN_INT_IST.PSTAT0 Field       */
#define LPC_GPIO_PIN_INT_IST_PSTAT1_MASK         (0x2U)                                              /**< LPC_GPIO_PIN_INT_IST.PSTAT1 Mask        */
#define LPC_GPIO_PIN_INT_IST_PSTAT1_SHIFT        (1U)                                                /**< LPC_GPIO_PIN_INT_IST.PSTAT1 Position    */
#define LPC_GPIO_PIN_INT_IST_PSTAT1(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IST_PSTAT1_SHIFT))&LPC_GPIO_PIN_INT_IST_PSTAT1_MASK) /**< LPC_GPIO_PIN_INT_IST.PSTAT1 Field       */
#define LPC_GPIO_PIN_INT_IST_PSTAT2_MASK         (0x4U)                                              /**< LPC_GPIO_PIN_INT_IST.PSTAT2 Mask        */
#define LPC_GPIO_PIN_INT_IST_PSTAT2_SHIFT        (2U)                                                /**< LPC_GPIO_PIN_INT_IST.PSTAT2 Position    */
#define LPC_GPIO_PIN_INT_IST_PSTAT2(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IST_PSTAT2_SHIFT))&LPC_GPIO_PIN_INT_IST_PSTAT2_MASK) /**< LPC_GPIO_PIN_INT_IST.PSTAT2 Field       */
#define LPC_GPIO_PIN_INT_IST_PSTAT3_MASK         (0x8U)                                              /**< LPC_GPIO_PIN_INT_IST.PSTAT3 Mask        */
#define LPC_GPIO_PIN_INT_IST_PSTAT3_SHIFT        (3U)                                                /**< LPC_GPIO_PIN_INT_IST.PSTAT3 Position    */
#define LPC_GPIO_PIN_INT_IST_PSTAT3(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IST_PSTAT3_SHIFT))&LPC_GPIO_PIN_INT_IST_PSTAT3_MASK) /**< LPC_GPIO_PIN_INT_IST.PSTAT3 Field       */
#define LPC_GPIO_PIN_INT_IST_PSTAT4_MASK         (0x10U)                                             /**< LPC_GPIO_PIN_INT_IST.PSTAT4 Mask        */
#define LPC_GPIO_PIN_INT_IST_PSTAT4_SHIFT        (4U)                                                /**< LPC_GPIO_PIN_INT_IST.PSTAT4 Position    */
#define LPC_GPIO_PIN_INT_IST_PSTAT4(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IST_PSTAT4_SHIFT))&LPC_GPIO_PIN_INT_IST_PSTAT4_MASK) /**< LPC_GPIO_PIN_INT_IST.PSTAT4 Field       */
#define LPC_GPIO_PIN_INT_IST_PSTAT5_MASK         (0x20U)                                             /**< LPC_GPIO_PIN_INT_IST.PSTAT5 Mask        */
#define LPC_GPIO_PIN_INT_IST_PSTAT5_SHIFT        (5U)                                                /**< LPC_GPIO_PIN_INT_IST.PSTAT5 Position    */
#define LPC_GPIO_PIN_INT_IST_PSTAT5(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IST_PSTAT5_SHIFT))&LPC_GPIO_PIN_INT_IST_PSTAT5_MASK) /**< LPC_GPIO_PIN_INT_IST.PSTAT5 Field       */
#define LPC_GPIO_PIN_INT_IST_PSTAT6_MASK         (0x40U)                                             /**< LPC_GPIO_PIN_INT_IST.PSTAT6 Mask        */
#define LPC_GPIO_PIN_INT_IST_PSTAT6_SHIFT        (6U)                                                /**< LPC_GPIO_PIN_INT_IST.PSTAT6 Position    */
#define LPC_GPIO_PIN_INT_IST_PSTAT6(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IST_PSTAT6_SHIFT))&LPC_GPIO_PIN_INT_IST_PSTAT6_MASK) /**< LPC_GPIO_PIN_INT_IST.PSTAT6 Field       */
#define LPC_GPIO_PIN_INT_IST_PSTAT7_MASK         (0x80U)                                             /**< LPC_GPIO_PIN_INT_IST.PSTAT7 Mask        */
#define LPC_GPIO_PIN_INT_IST_PSTAT7_SHIFT        (7U)                                                /**< LPC_GPIO_PIN_INT_IST.PSTAT7 Position    */
#define LPC_GPIO_PIN_INT_IST_PSTAT7(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PIN_INT_IST_PSTAT7_SHIFT))&LPC_GPIO_PIN_INT_IST_PSTAT7_MASK) /**< LPC_GPIO_PIN_INT_IST.PSTAT7 Field       */
/** @} */

/** @} */ /* End group GPIO_PIN_INT_Register_Masks_GROUP */


/* LPC_GPIO_PIN_INT - Peripheral instance base addresses */
#define LPC_GPIO_PIN_INT_BasePtr       0x4004C000UL //!< Peripheral base address
#define LPC_GPIO_PIN_INT               ((LPC_GPIO_PIN_INT_Type *) LPC_GPIO_PIN_INT_BasePtr) //!< Freescale base pointer
#define LPC_GPIO_PIN_INT_BASE_PTR      (LPC_GPIO_PIN_INT) //!< Freescale style base pointer

/** @} */ /* End group GPIO_PIN_INT_Peripheral_access_layer_GROUP */


/** @brief C Struct for GPIO_PORT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup GPIO_PORT_Peripheral_access_layer_GROUP GPIO_PORT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_GPIO_PORT (file:GPIO_PORT_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief GPIO port
 */
/**
 * @struct LPC_GPIO_PORT_Type
 * @brief  C Struct allowing access to GPIO_PORT registers
 */
typedef struct LPC_GPIO_PORT_Type {
   __IO uint8_t   B[32];                        /**< 0000: Byte pin registers port 0; pins PIO0_0 to PIO0_31            */
   __IO uint8_t   B132;                         /**< 0020: Byte pin registers port 1                                    */
   __IO uint8_t   B133;                         /**< 0021: Byte pin registers port 1                                    */
   __IO uint8_t   B134;                         /**< 0022: Byte pin registers port 1                                    */
   __IO uint8_t   B135;                         /**< 0023: Byte pin registers port 1                                    */
   __IO uint8_t   B136;                         /**< 0024: Byte pin registers port 1                                    */
   __IO uint8_t   B137;                         /**< 0025: Byte pin registers port 1                                    */
   __IO uint8_t   B138;                         /**< 0026: Byte pin registers port 1                                    */
   __IO uint8_t   B139;                         /**< 0027: Byte pin registers port 1                                    */
   __IO uint8_t   B140;                         /**< 0028: Byte pin registers port 1                                    */
   __IO uint8_t   B141;                         /**< 0029: Byte pin registers port 1                                    */
   __IO uint8_t   B142;                         /**< 002A: Byte pin registers port 1                                    */
   __IO uint8_t   B143;                         /**< 002B: Byte pin registers port 1                                    */
   __IO uint8_t   B144;                         /**< 002C: Byte pin registers port 1                                    */
   __IO uint8_t   B145;                         /**< 002D: Byte pin registers port 1                                    */
   __IO uint8_t   B146;                         /**< 002E: Byte pin registers port 1                                    */
   __IO uint8_t   B147;                         /**< 002F: Byte pin registers port 1                                    */
   __IO uint8_t   B148;                         /**< 0030: Byte pin registers port 1                                    */
   __IO uint8_t   B149;                         /**< 0031: Byte pin registers port 1                                    */
   __IO uint8_t   B150;                         /**< 0032: Byte pin registers port 1                                    */
   __IO uint8_t   B151;                         /**< 0033: Byte pin registers port 1                                    */
   __IO uint8_t   B152;                         /**< 0034: Byte pin registers port 1                                    */
   __IO uint8_t   B153;                         /**< 0035: Byte pin registers port 1                                    */
   __IO uint8_t   B154;                         /**< 0036: Byte pin registers port 1                                    */
   __IO uint8_t   B155;                         /**< 0037: Byte pin registers port 1                                    */
   __IO uint8_t   B156;                         /**< 0038: Byte pin registers port 1                                    */
   __IO uint8_t   B157;                         /**< 0039: Byte pin registers port 1                                    */
   __IO uint8_t   B158;                         /**< 003A: Byte pin registers port 1                                    */
   __IO uint8_t   B159;                         /**< 003B: Byte pin registers port 1                                    */
   __IO uint8_t   B160;                         /**< 003C: Byte pin registers port 1                                    */
   __IO uint8_t   B161;                         /**< 003D: Byte pin registers port 1                                    */
   __IO uint8_t   B162;                         /**< 003E: Byte pin registers port 1                                    */
   __IO uint8_t   B163;                         /**< 003F: Byte pin registers port 1                                    */
        uint8_t   RESERVED_0[4032];             /**< 0040: 0xFC0 bytes                                                  */
   __IO uint32_t  W[32];                        /**< 1000: Word pin registers port                                      */
   __IO uint32_t  W32;                          /**< 1080: Word pin registers port 1                                    */
   __IO uint32_t  W33;                          /**< 1084: Word pin registers port 1                                    */
   __IO uint32_t  W34;                          /**< 1088: Word pin registers port 1                                    */
   __IO uint32_t  W35;                          /**< 108C: Word pin registers port 1                                    */
   __IO uint32_t  W36;                          /**< 1090: Word pin registers port 1                                    */
   __IO uint32_t  W37;                          /**< 1094: Word pin registers port 1                                    */
   __IO uint32_t  W38;                          /**< 1098: Word pin registers port 1                                    */
   __IO uint32_t  W39;                          /**< 109C: Word pin registers port 1                                    */
   __IO uint32_t  W40;                          /**< 10A0: Word pin registers port 1                                    */
   __IO uint32_t  W41;                          /**< 10A4: Word pin registers port 1                                    */
   __IO uint32_t  W42;                          /**< 10A8: Word pin registers port 1                                    */
   __IO uint32_t  W43;                          /**< 10AC: Word pin registers port 1                                    */
   __IO uint32_t  W44;                          /**< 10B0: Word pin registers port 1                                    */
   __IO uint32_t  W45;                          /**< 10B4: Word pin registers port 1                                    */
   __IO uint32_t  W46;                          /**< 10B8: Word pin registers port 1                                    */
   __IO uint32_t  W47;                          /**< 10BC: Word pin registers port 1                                    */
   __IO uint32_t  W48;                          /**< 10C0: Word pin registers port 1                                    */
   __IO uint32_t  W49;                          /**< 10C4: Word pin registers port 1                                    */
   __IO uint32_t  W50;                          /**< 10C8: Word pin registers port 1                                    */
   __IO uint32_t  W51;                          /**< 10CC: Word pin registers port 1                                    */
   __IO uint32_t  W52;                          /**< 10D0: Word pin registers port 1                                    */
   __IO uint32_t  W53;                          /**< 10D4: Word pin registers port 1                                    */
   __IO uint32_t  W54;                          /**< 10D8: Word pin registers port 1                                    */
   __IO uint32_t  W55;                          /**< 10DC: Word pin registers port 1                                    */
   __IO uint32_t  W56;                          /**< 10E0: Word pin registers port 1                                    */
   __IO uint32_t  W57;                          /**< 10E4: Word pin registers port 1                                    */
   __IO uint32_t  W58;                          /**< 10E8: Word pin registers port 1                                    */
   __IO uint32_t  W59;                          /**< 10EC: Word pin registers port 1                                    */
   __IO uint32_t  W60;                          /**< 10F0: Word pin registers port 1                                    */
   __IO uint32_t  W61;                          /**< 10F4: Word pin registers port 1                                    */
   __IO uint32_t  W62;                          /**< 10F8: Word pin registers port 1                                    */
   __IO uint32_t  W63;                          /**< 10FC: Word pin registers port 1                                    */
        uint8_t   RESERVED_1[3840];             /**< 1100: 0xF00 bytes                                                  */
   __IO uint32_t  DIR[2];                       /**< 2000: Direction registers port                                     */
        uint8_t   RESERVED_2[120];              /**< 2008: 0x78 bytes                                                   */
   __IO uint32_t  MASK[2];                      /**< 2080: Mask register port %                                         */
        uint8_t   RESERVED_3[120];              /**< 2088: 0x78 bytes                                                   */
   __IO uint32_t  PIN[2];                       /**< 2100: Portpin register port                                        */
        uint8_t   RESERVED_4[120];              /**< 2108: 0x78 bytes                                                   */
   __IO uint32_t  MPIN[2];                      /**< 2180: Masked port register port                                    */
        uint8_t   RESERVED_5[120];              /**< 2188: 0x78 bytes                                                   */
   __IO uint32_t  SET[2];                       /**< 2200: Write: Set register for port,  Read: output bits for port    */
        uint8_t   RESERVED_6[120];              /**< 2208: 0x78 bytes                                                   */
   __O  uint32_t  CLR[2];                       /**< 2280: Clear port                                                   */
        uint8_t   RESERVED_7[120];              /**< 2288: 0x78 bytes                                                   */
   __O  uint32_t  NOT[2];                       /**< 2300: Toggle port                                                  */
} LPC_GPIO_PORT_Type;


/** @brief Register Masks for GPIO_PORT */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_GPIO_PORT' Position & Mask macros               ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup GPIO_PORT_Register_Masks_GROUP GPIO_PORT Register Masks */
/** @{ */

/** @name B - Byte pin registers port 0; pins PIO0_0 to PIO0_31 */ /** @{ */
#define LPC_GPIO_PORT_B_PBYTE_MASK               (0x1U)                                              /**< LPC_GPIO_PORT_B.PBYTE Mask              */
#define LPC_GPIO_PORT_B_PBYTE_SHIFT              (0U)                                                /**< LPC_GPIO_PORT_B.PBYTE Position          */
#define LPC_GPIO_PORT_B_PBYTE(x)                 (((uint8_t)(((uint8_t)(x))<<LPC_GPIO_PORT_B_PBYTE_SHIFT))&LPC_GPIO_PORT_B_PBYTE_MASK) /**< LPC_GPIO_PORT_B.PBYTE Field             */
/** @} */

/** @name W - Word pin registers port %s */ /** @{ */
#define LPC_GPIO_PORT_W_PWORD_MASK               (0xFFFFFFFFU)                                       /**< LPC_GPIO_PORT_W.PWORD Mask              */
#define LPC_GPIO_PORT_W_PWORD_SHIFT              (0U)                                                /**< LPC_GPIO_PORT_W.PWORD Position          */
#define LPC_GPIO_PORT_W_PWORD(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_W_PWORD_SHIFT))&LPC_GPIO_PORT_W_PWORD_MASK) /**< LPC_GPIO_PORT_W.PWORD Field             */
/** @} */

/** @name DIR - Direction registers port %s */ /** @{ */
#define LPC_GPIO_PORT_DIR_DIRP0_MASK             (0x1U)                                              /**< LPC_GPIO_PORT_DIR.DIRP0 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP0_SHIFT            (0U)                                                /**< LPC_GPIO_PORT_DIR.DIRP0 Position        */
#define LPC_GPIO_PORT_DIR_DIRP0(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP0_SHIFT))&LPC_GPIO_PORT_DIR_DIRP0_MASK) /**< LPC_GPIO_PORT_DIR.DIRP0 Field           */
#define LPC_GPIO_PORT_DIR_DIRP1_MASK             (0x2U)                                              /**< LPC_GPIO_PORT_DIR.DIRP1 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP1_SHIFT            (1U)                                                /**< LPC_GPIO_PORT_DIR.DIRP1 Position        */
#define LPC_GPIO_PORT_DIR_DIRP1(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP1_SHIFT))&LPC_GPIO_PORT_DIR_DIRP1_MASK) /**< LPC_GPIO_PORT_DIR.DIRP1 Field           */
#define LPC_GPIO_PORT_DIR_DIRP2_MASK             (0x4U)                                              /**< LPC_GPIO_PORT_DIR.DIRP2 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP2_SHIFT            (2U)                                                /**< LPC_GPIO_PORT_DIR.DIRP2 Position        */
#define LPC_GPIO_PORT_DIR_DIRP2(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP2_SHIFT))&LPC_GPIO_PORT_DIR_DIRP2_MASK) /**< LPC_GPIO_PORT_DIR.DIRP2 Field           */
#define LPC_GPIO_PORT_DIR_DIRP3_MASK             (0x8U)                                              /**< LPC_GPIO_PORT_DIR.DIRP3 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP3_SHIFT            (3U)                                                /**< LPC_GPIO_PORT_DIR.DIRP3 Position        */
#define LPC_GPIO_PORT_DIR_DIRP3(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP3_SHIFT))&LPC_GPIO_PORT_DIR_DIRP3_MASK) /**< LPC_GPIO_PORT_DIR.DIRP3 Field           */
#define LPC_GPIO_PORT_DIR_DIRP4_MASK             (0x10U)                                             /**< LPC_GPIO_PORT_DIR.DIRP4 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP4_SHIFT            (4U)                                                /**< LPC_GPIO_PORT_DIR.DIRP4 Position        */
#define LPC_GPIO_PORT_DIR_DIRP4(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP4_SHIFT))&LPC_GPIO_PORT_DIR_DIRP4_MASK) /**< LPC_GPIO_PORT_DIR.DIRP4 Field           */
#define LPC_GPIO_PORT_DIR_DIRP5_MASK             (0x20U)                                             /**< LPC_GPIO_PORT_DIR.DIRP5 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP5_SHIFT            (5U)                                                /**< LPC_GPIO_PORT_DIR.DIRP5 Position        */
#define LPC_GPIO_PORT_DIR_DIRP5(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP5_SHIFT))&LPC_GPIO_PORT_DIR_DIRP5_MASK) /**< LPC_GPIO_PORT_DIR.DIRP5 Field           */
#define LPC_GPIO_PORT_DIR_DIRP6_MASK             (0x40U)                                             /**< LPC_GPIO_PORT_DIR.DIRP6 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP6_SHIFT            (6U)                                                /**< LPC_GPIO_PORT_DIR.DIRP6 Position        */
#define LPC_GPIO_PORT_DIR_DIRP6(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP6_SHIFT))&LPC_GPIO_PORT_DIR_DIRP6_MASK) /**< LPC_GPIO_PORT_DIR.DIRP6 Field           */
#define LPC_GPIO_PORT_DIR_DIRP7_MASK             (0x80U)                                             /**< LPC_GPIO_PORT_DIR.DIRP7 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP7_SHIFT            (7U)                                                /**< LPC_GPIO_PORT_DIR.DIRP7 Position        */
#define LPC_GPIO_PORT_DIR_DIRP7(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP7_SHIFT))&LPC_GPIO_PORT_DIR_DIRP7_MASK) /**< LPC_GPIO_PORT_DIR.DIRP7 Field           */
#define LPC_GPIO_PORT_DIR_DIRP8_MASK             (0x100U)                                            /**< LPC_GPIO_PORT_DIR.DIRP8 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP8_SHIFT            (8U)                                                /**< LPC_GPIO_PORT_DIR.DIRP8 Position        */
#define LPC_GPIO_PORT_DIR_DIRP8(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP8_SHIFT))&LPC_GPIO_PORT_DIR_DIRP8_MASK) /**< LPC_GPIO_PORT_DIR.DIRP8 Field           */
#define LPC_GPIO_PORT_DIR_DIRP9_MASK             (0x200U)                                            /**< LPC_GPIO_PORT_DIR.DIRP9 Mask            */
#define LPC_GPIO_PORT_DIR_DIRP9_SHIFT            (9U)                                                /**< LPC_GPIO_PORT_DIR.DIRP9 Position        */
#define LPC_GPIO_PORT_DIR_DIRP9(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP9_SHIFT))&LPC_GPIO_PORT_DIR_DIRP9_MASK) /**< LPC_GPIO_PORT_DIR.DIRP9 Field           */
#define LPC_GPIO_PORT_DIR_DIRP10_MASK            (0x400U)                                            /**< LPC_GPIO_PORT_DIR.DIRP10 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP10_SHIFT           (10U)                                               /**< LPC_GPIO_PORT_DIR.DIRP10 Position       */
#define LPC_GPIO_PORT_DIR_DIRP10(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP10_SHIFT))&LPC_GPIO_PORT_DIR_DIRP10_MASK) /**< LPC_GPIO_PORT_DIR.DIRP10 Field          */
#define LPC_GPIO_PORT_DIR_DIRP11_MASK            (0x800U)                                            /**< LPC_GPIO_PORT_DIR.DIRP11 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP11_SHIFT           (11U)                                               /**< LPC_GPIO_PORT_DIR.DIRP11 Position       */
#define LPC_GPIO_PORT_DIR_DIRP11(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP11_SHIFT))&LPC_GPIO_PORT_DIR_DIRP11_MASK) /**< LPC_GPIO_PORT_DIR.DIRP11 Field          */
#define LPC_GPIO_PORT_DIR_DIRP12_MASK            (0x1000U)                                           /**< LPC_GPIO_PORT_DIR.DIRP12 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP12_SHIFT           (12U)                                               /**< LPC_GPIO_PORT_DIR.DIRP12 Position       */
#define LPC_GPIO_PORT_DIR_DIRP12(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP12_SHIFT))&LPC_GPIO_PORT_DIR_DIRP12_MASK) /**< LPC_GPIO_PORT_DIR.DIRP12 Field          */
#define LPC_GPIO_PORT_DIR_DIRP13_MASK            (0x2000U)                                           /**< LPC_GPIO_PORT_DIR.DIRP13 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP13_SHIFT           (13U)                                               /**< LPC_GPIO_PORT_DIR.DIRP13 Position       */
#define LPC_GPIO_PORT_DIR_DIRP13(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP13_SHIFT))&LPC_GPIO_PORT_DIR_DIRP13_MASK) /**< LPC_GPIO_PORT_DIR.DIRP13 Field          */
#define LPC_GPIO_PORT_DIR_DIRP14_MASK            (0x4000U)                                           /**< LPC_GPIO_PORT_DIR.DIRP14 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP14_SHIFT           (14U)                                               /**< LPC_GPIO_PORT_DIR.DIRP14 Position       */
#define LPC_GPIO_PORT_DIR_DIRP14(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP14_SHIFT))&LPC_GPIO_PORT_DIR_DIRP14_MASK) /**< LPC_GPIO_PORT_DIR.DIRP14 Field          */
#define LPC_GPIO_PORT_DIR_DIRP15_MASK            (0x8000U)                                           /**< LPC_GPIO_PORT_DIR.DIRP15 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP15_SHIFT           (15U)                                               /**< LPC_GPIO_PORT_DIR.DIRP15 Position       */
#define LPC_GPIO_PORT_DIR_DIRP15(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP15_SHIFT))&LPC_GPIO_PORT_DIR_DIRP15_MASK) /**< LPC_GPIO_PORT_DIR.DIRP15 Field          */
#define LPC_GPIO_PORT_DIR_DIRP16_MASK            (0x10000U)                                          /**< LPC_GPIO_PORT_DIR.DIRP16 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP16_SHIFT           (16U)                                               /**< LPC_GPIO_PORT_DIR.DIRP16 Position       */
#define LPC_GPIO_PORT_DIR_DIRP16(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP16_SHIFT))&LPC_GPIO_PORT_DIR_DIRP16_MASK) /**< LPC_GPIO_PORT_DIR.DIRP16 Field          */
#define LPC_GPIO_PORT_DIR_DIRP17_MASK            (0x20000U)                                          /**< LPC_GPIO_PORT_DIR.DIRP17 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP17_SHIFT           (17U)                                               /**< LPC_GPIO_PORT_DIR.DIRP17 Position       */
#define LPC_GPIO_PORT_DIR_DIRP17(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP17_SHIFT))&LPC_GPIO_PORT_DIR_DIRP17_MASK) /**< LPC_GPIO_PORT_DIR.DIRP17 Field          */
#define LPC_GPIO_PORT_DIR_DIRP18_MASK            (0x40000U)                                          /**< LPC_GPIO_PORT_DIR.DIRP18 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP18_SHIFT           (18U)                                               /**< LPC_GPIO_PORT_DIR.DIRP18 Position       */
#define LPC_GPIO_PORT_DIR_DIRP18(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP18_SHIFT))&LPC_GPIO_PORT_DIR_DIRP18_MASK) /**< LPC_GPIO_PORT_DIR.DIRP18 Field          */
#define LPC_GPIO_PORT_DIR_DIRP19_MASK            (0x80000U)                                          /**< LPC_GPIO_PORT_DIR.DIRP19 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP19_SHIFT           (19U)                                               /**< LPC_GPIO_PORT_DIR.DIRP19 Position       */
#define LPC_GPIO_PORT_DIR_DIRP19(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP19_SHIFT))&LPC_GPIO_PORT_DIR_DIRP19_MASK) /**< LPC_GPIO_PORT_DIR.DIRP19 Field          */
#define LPC_GPIO_PORT_DIR_DIRP20_MASK            (0x100000U)                                         /**< LPC_GPIO_PORT_DIR.DIRP20 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP20_SHIFT           (20U)                                               /**< LPC_GPIO_PORT_DIR.DIRP20 Position       */
#define LPC_GPIO_PORT_DIR_DIRP20(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP20_SHIFT))&LPC_GPIO_PORT_DIR_DIRP20_MASK) /**< LPC_GPIO_PORT_DIR.DIRP20 Field          */
#define LPC_GPIO_PORT_DIR_DIRP21_MASK            (0x200000U)                                         /**< LPC_GPIO_PORT_DIR.DIRP21 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP21_SHIFT           (21U)                                               /**< LPC_GPIO_PORT_DIR.DIRP21 Position       */
#define LPC_GPIO_PORT_DIR_DIRP21(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP21_SHIFT))&LPC_GPIO_PORT_DIR_DIRP21_MASK) /**< LPC_GPIO_PORT_DIR.DIRP21 Field          */
#define LPC_GPIO_PORT_DIR_DIRP22_MASK            (0x400000U)                                         /**< LPC_GPIO_PORT_DIR.DIRP22 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP22_SHIFT           (22U)                                               /**< LPC_GPIO_PORT_DIR.DIRP22 Position       */
#define LPC_GPIO_PORT_DIR_DIRP22(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP22_SHIFT))&LPC_GPIO_PORT_DIR_DIRP22_MASK) /**< LPC_GPIO_PORT_DIR.DIRP22 Field          */
#define LPC_GPIO_PORT_DIR_DIRP23_MASK            (0x800000U)                                         /**< LPC_GPIO_PORT_DIR.DIRP23 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP23_SHIFT           (23U)                                               /**< LPC_GPIO_PORT_DIR.DIRP23 Position       */
#define LPC_GPIO_PORT_DIR_DIRP23(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP23_SHIFT))&LPC_GPIO_PORT_DIR_DIRP23_MASK) /**< LPC_GPIO_PORT_DIR.DIRP23 Field          */
#define LPC_GPIO_PORT_DIR_DIRP24_MASK            (0x1000000U)                                        /**< LPC_GPIO_PORT_DIR.DIRP24 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP24_SHIFT           (24U)                                               /**< LPC_GPIO_PORT_DIR.DIRP24 Position       */
#define LPC_GPIO_PORT_DIR_DIRP24(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP24_SHIFT))&LPC_GPIO_PORT_DIR_DIRP24_MASK) /**< LPC_GPIO_PORT_DIR.DIRP24 Field          */
#define LPC_GPIO_PORT_DIR_DIRP25_MASK            (0x2000000U)                                        /**< LPC_GPIO_PORT_DIR.DIRP25 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP25_SHIFT           (25U)                                               /**< LPC_GPIO_PORT_DIR.DIRP25 Position       */
#define LPC_GPIO_PORT_DIR_DIRP25(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP25_SHIFT))&LPC_GPIO_PORT_DIR_DIRP25_MASK) /**< LPC_GPIO_PORT_DIR.DIRP25 Field          */
#define LPC_GPIO_PORT_DIR_DIRP26_MASK            (0x4000000U)                                        /**< LPC_GPIO_PORT_DIR.DIRP26 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP26_SHIFT           (26U)                                               /**< LPC_GPIO_PORT_DIR.DIRP26 Position       */
#define LPC_GPIO_PORT_DIR_DIRP26(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP26_SHIFT))&LPC_GPIO_PORT_DIR_DIRP26_MASK) /**< LPC_GPIO_PORT_DIR.DIRP26 Field          */
#define LPC_GPIO_PORT_DIR_DIRP27_MASK            (0x8000000U)                                        /**< LPC_GPIO_PORT_DIR.DIRP27 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP27_SHIFT           (27U)                                               /**< LPC_GPIO_PORT_DIR.DIRP27 Position       */
#define LPC_GPIO_PORT_DIR_DIRP27(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP27_SHIFT))&LPC_GPIO_PORT_DIR_DIRP27_MASK) /**< LPC_GPIO_PORT_DIR.DIRP27 Field          */
#define LPC_GPIO_PORT_DIR_DIRP28_MASK            (0x10000000U)                                       /**< LPC_GPIO_PORT_DIR.DIRP28 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP28_SHIFT           (28U)                                               /**< LPC_GPIO_PORT_DIR.DIRP28 Position       */
#define LPC_GPIO_PORT_DIR_DIRP28(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP28_SHIFT))&LPC_GPIO_PORT_DIR_DIRP28_MASK) /**< LPC_GPIO_PORT_DIR.DIRP28 Field          */
#define LPC_GPIO_PORT_DIR_DIRP29_MASK            (0x20000000U)                                       /**< LPC_GPIO_PORT_DIR.DIRP29 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP29_SHIFT           (29U)                                               /**< LPC_GPIO_PORT_DIR.DIRP29 Position       */
#define LPC_GPIO_PORT_DIR_DIRP29(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP29_SHIFT))&LPC_GPIO_PORT_DIR_DIRP29_MASK) /**< LPC_GPIO_PORT_DIR.DIRP29 Field          */
#define LPC_GPIO_PORT_DIR_DIRP30_MASK            (0x40000000U)                                       /**< LPC_GPIO_PORT_DIR.DIRP30 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP30_SHIFT           (30U)                                               /**< LPC_GPIO_PORT_DIR.DIRP30 Position       */
#define LPC_GPIO_PORT_DIR_DIRP30(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP30_SHIFT))&LPC_GPIO_PORT_DIR_DIRP30_MASK) /**< LPC_GPIO_PORT_DIR.DIRP30 Field          */
#define LPC_GPIO_PORT_DIR_DIRP31_MASK            (0x80000000U)                                       /**< LPC_GPIO_PORT_DIR.DIRP31 Mask           */
#define LPC_GPIO_PORT_DIR_DIRP31_SHIFT           (31U)                                               /**< LPC_GPIO_PORT_DIR.DIRP31 Position       */
#define LPC_GPIO_PORT_DIR_DIRP31(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR_DIRP31_SHIFT))&LPC_GPIO_PORT_DIR_DIRP31_MASK) /**< LPC_GPIO_PORT_DIR.DIRP31 Field          */
/** @} */

/** @name MASK - Mask register port % */ /** @{ */
#define LPC_GPIO_PORT_MASK_MASKP0_MASK           (0x1U)                                              /**< LPC_GPIO_PORT_MASK.MASKP0 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP0_SHIFT          (0U)                                                /**< LPC_GPIO_PORT_MASK.MASKP0 Position      */
#define LPC_GPIO_PORT_MASK_MASKP0(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP0_SHIFT))&LPC_GPIO_PORT_MASK_MASKP0_MASK) /**< LPC_GPIO_PORT_MASK.MASKP0 Field         */
#define LPC_GPIO_PORT_MASK_MASKP1_MASK           (0x2U)                                              /**< LPC_GPIO_PORT_MASK.MASKP1 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP1_SHIFT          (1U)                                                /**< LPC_GPIO_PORT_MASK.MASKP1 Position      */
#define LPC_GPIO_PORT_MASK_MASKP1(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP1_SHIFT))&LPC_GPIO_PORT_MASK_MASKP1_MASK) /**< LPC_GPIO_PORT_MASK.MASKP1 Field         */
#define LPC_GPIO_PORT_MASK_MASKP2_MASK           (0x4U)                                              /**< LPC_GPIO_PORT_MASK.MASKP2 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP2_SHIFT          (2U)                                                /**< LPC_GPIO_PORT_MASK.MASKP2 Position      */
#define LPC_GPIO_PORT_MASK_MASKP2(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP2_SHIFT))&LPC_GPIO_PORT_MASK_MASKP2_MASK) /**< LPC_GPIO_PORT_MASK.MASKP2 Field         */
#define LPC_GPIO_PORT_MASK_MASKP3_MASK           (0x8U)                                              /**< LPC_GPIO_PORT_MASK.MASKP3 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP3_SHIFT          (3U)                                                /**< LPC_GPIO_PORT_MASK.MASKP3 Position      */
#define LPC_GPIO_PORT_MASK_MASKP3(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP3_SHIFT))&LPC_GPIO_PORT_MASK_MASKP3_MASK) /**< LPC_GPIO_PORT_MASK.MASKP3 Field         */
#define LPC_GPIO_PORT_MASK_MASKP4_MASK           (0x10U)                                             /**< LPC_GPIO_PORT_MASK.MASKP4 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP4_SHIFT          (4U)                                                /**< LPC_GPIO_PORT_MASK.MASKP4 Position      */
#define LPC_GPIO_PORT_MASK_MASKP4(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP4_SHIFT))&LPC_GPIO_PORT_MASK_MASKP4_MASK) /**< LPC_GPIO_PORT_MASK.MASKP4 Field         */
#define LPC_GPIO_PORT_MASK_MASKP5_MASK           (0x20U)                                             /**< LPC_GPIO_PORT_MASK.MASKP5 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP5_SHIFT          (5U)                                                /**< LPC_GPIO_PORT_MASK.MASKP5 Position      */
#define LPC_GPIO_PORT_MASK_MASKP5(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP5_SHIFT))&LPC_GPIO_PORT_MASK_MASKP5_MASK) /**< LPC_GPIO_PORT_MASK.MASKP5 Field         */
#define LPC_GPIO_PORT_MASK_MASKP6_MASK           (0x40U)                                             /**< LPC_GPIO_PORT_MASK.MASKP6 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP6_SHIFT          (6U)                                                /**< LPC_GPIO_PORT_MASK.MASKP6 Position      */
#define LPC_GPIO_PORT_MASK_MASKP6(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP6_SHIFT))&LPC_GPIO_PORT_MASK_MASKP6_MASK) /**< LPC_GPIO_PORT_MASK.MASKP6 Field         */
#define LPC_GPIO_PORT_MASK_MASKP7_MASK           (0x80U)                                             /**< LPC_GPIO_PORT_MASK.MASKP7 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP7_SHIFT          (7U)                                                /**< LPC_GPIO_PORT_MASK.MASKP7 Position      */
#define LPC_GPIO_PORT_MASK_MASKP7(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP7_SHIFT))&LPC_GPIO_PORT_MASK_MASKP7_MASK) /**< LPC_GPIO_PORT_MASK.MASKP7 Field         */
#define LPC_GPIO_PORT_MASK_MASKP8_MASK           (0x100U)                                            /**< LPC_GPIO_PORT_MASK.MASKP8 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP8_SHIFT          (8U)                                                /**< LPC_GPIO_PORT_MASK.MASKP8 Position      */
#define LPC_GPIO_PORT_MASK_MASKP8(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP8_SHIFT))&LPC_GPIO_PORT_MASK_MASKP8_MASK) /**< LPC_GPIO_PORT_MASK.MASKP8 Field         */
#define LPC_GPIO_PORT_MASK_MASKP9_MASK           (0x200U)                                            /**< LPC_GPIO_PORT_MASK.MASKP9 Mask          */
#define LPC_GPIO_PORT_MASK_MASKP9_SHIFT          (9U)                                                /**< LPC_GPIO_PORT_MASK.MASKP9 Position      */
#define LPC_GPIO_PORT_MASK_MASKP9(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP9_SHIFT))&LPC_GPIO_PORT_MASK_MASKP9_MASK) /**< LPC_GPIO_PORT_MASK.MASKP9 Field         */
#define LPC_GPIO_PORT_MASK_MASKP10_MASK          (0x400U)                                            /**< LPC_GPIO_PORT_MASK.MASKP10 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP10_SHIFT         (10U)                                               /**< LPC_GPIO_PORT_MASK.MASKP10 Position     */
#define LPC_GPIO_PORT_MASK_MASKP10(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP10_SHIFT))&LPC_GPIO_PORT_MASK_MASKP10_MASK) /**< LPC_GPIO_PORT_MASK.MASKP10 Field        */
#define LPC_GPIO_PORT_MASK_MASKP11_MASK          (0x800U)                                            /**< LPC_GPIO_PORT_MASK.MASKP11 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP11_SHIFT         (11U)                                               /**< LPC_GPIO_PORT_MASK.MASKP11 Position     */
#define LPC_GPIO_PORT_MASK_MASKP11(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP11_SHIFT))&LPC_GPIO_PORT_MASK_MASKP11_MASK) /**< LPC_GPIO_PORT_MASK.MASKP11 Field        */
#define LPC_GPIO_PORT_MASK_MASKP12_MASK          (0x1000U)                                           /**< LPC_GPIO_PORT_MASK.MASKP12 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP12_SHIFT         (12U)                                               /**< LPC_GPIO_PORT_MASK.MASKP12 Position     */
#define LPC_GPIO_PORT_MASK_MASKP12(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP12_SHIFT))&LPC_GPIO_PORT_MASK_MASKP12_MASK) /**< LPC_GPIO_PORT_MASK.MASKP12 Field        */
#define LPC_GPIO_PORT_MASK_MASKP13_MASK          (0x2000U)                                           /**< LPC_GPIO_PORT_MASK.MASKP13 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP13_SHIFT         (13U)                                               /**< LPC_GPIO_PORT_MASK.MASKP13 Position     */
#define LPC_GPIO_PORT_MASK_MASKP13(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP13_SHIFT))&LPC_GPIO_PORT_MASK_MASKP13_MASK) /**< LPC_GPIO_PORT_MASK.MASKP13 Field        */
#define LPC_GPIO_PORT_MASK_MASKP14_MASK          (0x4000U)                                           /**< LPC_GPIO_PORT_MASK.MASKP14 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP14_SHIFT         (14U)                                               /**< LPC_GPIO_PORT_MASK.MASKP14 Position     */
#define LPC_GPIO_PORT_MASK_MASKP14(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP14_SHIFT))&LPC_GPIO_PORT_MASK_MASKP14_MASK) /**< LPC_GPIO_PORT_MASK.MASKP14 Field        */
#define LPC_GPIO_PORT_MASK_MASKP15_MASK          (0x8000U)                                           /**< LPC_GPIO_PORT_MASK.MASKP15 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP15_SHIFT         (15U)                                               /**< LPC_GPIO_PORT_MASK.MASKP15 Position     */
#define LPC_GPIO_PORT_MASK_MASKP15(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP15_SHIFT))&LPC_GPIO_PORT_MASK_MASKP15_MASK) /**< LPC_GPIO_PORT_MASK.MASKP15 Field        */
#define LPC_GPIO_PORT_MASK_MASKP16_MASK          (0x10000U)                                          /**< LPC_GPIO_PORT_MASK.MASKP16 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP16_SHIFT         (16U)                                               /**< LPC_GPIO_PORT_MASK.MASKP16 Position     */
#define LPC_GPIO_PORT_MASK_MASKP16(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP16_SHIFT))&LPC_GPIO_PORT_MASK_MASKP16_MASK) /**< LPC_GPIO_PORT_MASK.MASKP16 Field        */
#define LPC_GPIO_PORT_MASK_MASKP17_MASK          (0x20000U)                                          /**< LPC_GPIO_PORT_MASK.MASKP17 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP17_SHIFT         (17U)                                               /**< LPC_GPIO_PORT_MASK.MASKP17 Position     */
#define LPC_GPIO_PORT_MASK_MASKP17(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP17_SHIFT))&LPC_GPIO_PORT_MASK_MASKP17_MASK) /**< LPC_GPIO_PORT_MASK.MASKP17 Field        */
#define LPC_GPIO_PORT_MASK_MASKP18_MASK          (0x40000U)                                          /**< LPC_GPIO_PORT_MASK.MASKP18 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP18_SHIFT         (18U)                                               /**< LPC_GPIO_PORT_MASK.MASKP18 Position     */
#define LPC_GPIO_PORT_MASK_MASKP18(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP18_SHIFT))&LPC_GPIO_PORT_MASK_MASKP18_MASK) /**< LPC_GPIO_PORT_MASK.MASKP18 Field        */
#define LPC_GPIO_PORT_MASK_MASKP19_MASK          (0x80000U)                                          /**< LPC_GPIO_PORT_MASK.MASKP19 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP19_SHIFT         (19U)                                               /**< LPC_GPIO_PORT_MASK.MASKP19 Position     */
#define LPC_GPIO_PORT_MASK_MASKP19(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP19_SHIFT))&LPC_GPIO_PORT_MASK_MASKP19_MASK) /**< LPC_GPIO_PORT_MASK.MASKP19 Field        */
#define LPC_GPIO_PORT_MASK_MASKP20_MASK          (0x100000U)                                         /**< LPC_GPIO_PORT_MASK.MASKP20 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP20_SHIFT         (20U)                                               /**< LPC_GPIO_PORT_MASK.MASKP20 Position     */
#define LPC_GPIO_PORT_MASK_MASKP20(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP20_SHIFT))&LPC_GPIO_PORT_MASK_MASKP20_MASK) /**< LPC_GPIO_PORT_MASK.MASKP20 Field        */
#define LPC_GPIO_PORT_MASK_MASKP21_MASK          (0x200000U)                                         /**< LPC_GPIO_PORT_MASK.MASKP21 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP21_SHIFT         (21U)                                               /**< LPC_GPIO_PORT_MASK.MASKP21 Position     */
#define LPC_GPIO_PORT_MASK_MASKP21(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP21_SHIFT))&LPC_GPIO_PORT_MASK_MASKP21_MASK) /**< LPC_GPIO_PORT_MASK.MASKP21 Field        */
#define LPC_GPIO_PORT_MASK_MASKP22_MASK          (0x400000U)                                         /**< LPC_GPIO_PORT_MASK.MASKP22 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP22_SHIFT         (22U)                                               /**< LPC_GPIO_PORT_MASK.MASKP22 Position     */
#define LPC_GPIO_PORT_MASK_MASKP22(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP22_SHIFT))&LPC_GPIO_PORT_MASK_MASKP22_MASK) /**< LPC_GPIO_PORT_MASK.MASKP22 Field        */
#define LPC_GPIO_PORT_MASK_MASKP23_MASK          (0x800000U)                                         /**< LPC_GPIO_PORT_MASK.MASKP23 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP23_SHIFT         (23U)                                               /**< LPC_GPIO_PORT_MASK.MASKP23 Position     */
#define LPC_GPIO_PORT_MASK_MASKP23(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP23_SHIFT))&LPC_GPIO_PORT_MASK_MASKP23_MASK) /**< LPC_GPIO_PORT_MASK.MASKP23 Field        */
#define LPC_GPIO_PORT_MASK_MASKP24_MASK          (0x1000000U)                                        /**< LPC_GPIO_PORT_MASK.MASKP24 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP24_SHIFT         (24U)                                               /**< LPC_GPIO_PORT_MASK.MASKP24 Position     */
#define LPC_GPIO_PORT_MASK_MASKP24(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP24_SHIFT))&LPC_GPIO_PORT_MASK_MASKP24_MASK) /**< LPC_GPIO_PORT_MASK.MASKP24 Field        */
#define LPC_GPIO_PORT_MASK_MASKP25_MASK          (0x2000000U)                                        /**< LPC_GPIO_PORT_MASK.MASKP25 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP25_SHIFT         (25U)                                               /**< LPC_GPIO_PORT_MASK.MASKP25 Position     */
#define LPC_GPIO_PORT_MASK_MASKP25(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP25_SHIFT))&LPC_GPIO_PORT_MASK_MASKP25_MASK) /**< LPC_GPIO_PORT_MASK.MASKP25 Field        */
#define LPC_GPIO_PORT_MASK_MASKP26_MASK          (0x4000000U)                                        /**< LPC_GPIO_PORT_MASK.MASKP26 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP26_SHIFT         (26U)                                               /**< LPC_GPIO_PORT_MASK.MASKP26 Position     */
#define LPC_GPIO_PORT_MASK_MASKP26(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP26_SHIFT))&LPC_GPIO_PORT_MASK_MASKP26_MASK) /**< LPC_GPIO_PORT_MASK.MASKP26 Field        */
#define LPC_GPIO_PORT_MASK_MASKP27_MASK          (0x8000000U)                                        /**< LPC_GPIO_PORT_MASK.MASKP27 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP27_SHIFT         (27U)                                               /**< LPC_GPIO_PORT_MASK.MASKP27 Position     */
#define LPC_GPIO_PORT_MASK_MASKP27(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP27_SHIFT))&LPC_GPIO_PORT_MASK_MASKP27_MASK) /**< LPC_GPIO_PORT_MASK.MASKP27 Field        */
#define LPC_GPIO_PORT_MASK_MASKP28_MASK          (0x10000000U)                                       /**< LPC_GPIO_PORT_MASK.MASKP28 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP28_SHIFT         (28U)                                               /**< LPC_GPIO_PORT_MASK.MASKP28 Position     */
#define LPC_GPIO_PORT_MASK_MASKP28(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP28_SHIFT))&LPC_GPIO_PORT_MASK_MASKP28_MASK) /**< LPC_GPIO_PORT_MASK.MASKP28 Field        */
#define LPC_GPIO_PORT_MASK_MASKP29_MASK          (0x20000000U)                                       /**< LPC_GPIO_PORT_MASK.MASKP29 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP29_SHIFT         (29U)                                               /**< LPC_GPIO_PORT_MASK.MASKP29 Position     */
#define LPC_GPIO_PORT_MASK_MASKP29(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP29_SHIFT))&LPC_GPIO_PORT_MASK_MASKP29_MASK) /**< LPC_GPIO_PORT_MASK.MASKP29 Field        */
#define LPC_GPIO_PORT_MASK_MASKP30_MASK          (0x40000000U)                                       /**< LPC_GPIO_PORT_MASK.MASKP30 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP30_SHIFT         (30U)                                               /**< LPC_GPIO_PORT_MASK.MASKP30 Position     */
#define LPC_GPIO_PORT_MASK_MASKP30(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP30_SHIFT))&LPC_GPIO_PORT_MASK_MASKP30_MASK) /**< LPC_GPIO_PORT_MASK.MASKP30 Field        */
#define LPC_GPIO_PORT_MASK_MASKP31_MASK          (0x80000000U)                                       /**< LPC_GPIO_PORT_MASK.MASKP31 Mask         */
#define LPC_GPIO_PORT_MASK_MASKP31_SHIFT         (31U)                                               /**< LPC_GPIO_PORT_MASK.MASKP31 Position     */
#define LPC_GPIO_PORT_MASK_MASKP31(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK_MASKP31_SHIFT))&LPC_GPIO_PORT_MASK_MASKP31_MASK) /**< LPC_GPIO_PORT_MASK.MASKP31 Field        */
/** @} */

/** @name PIN - Portpin register port %s */ /** @{ */
#define LPC_GPIO_PORT_PIN_PORT0_MASK             (0x1U)                                              /**< LPC_GPIO_PORT_PIN.PORT0 Mask            */
#define LPC_GPIO_PORT_PIN_PORT0_SHIFT            (0U)                                                /**< LPC_GPIO_PORT_PIN.PORT0 Position        */
#define LPC_GPIO_PORT_PIN_PORT0(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT0_SHIFT))&LPC_GPIO_PORT_PIN_PORT0_MASK) /**< LPC_GPIO_PORT_PIN.PORT0 Field           */
#define LPC_GPIO_PORT_PIN_PORT1_MASK             (0x2U)                                              /**< LPC_GPIO_PORT_PIN.PORT1 Mask            */
#define LPC_GPIO_PORT_PIN_PORT1_SHIFT            (1U)                                                /**< LPC_GPIO_PORT_PIN.PORT1 Position        */
#define LPC_GPIO_PORT_PIN_PORT1(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT1_SHIFT))&LPC_GPIO_PORT_PIN_PORT1_MASK) /**< LPC_GPIO_PORT_PIN.PORT1 Field           */
#define LPC_GPIO_PORT_PIN_PORT2_MASK             (0x4U)                                              /**< LPC_GPIO_PORT_PIN.PORT2 Mask            */
#define LPC_GPIO_PORT_PIN_PORT2_SHIFT            (2U)                                                /**< LPC_GPIO_PORT_PIN.PORT2 Position        */
#define LPC_GPIO_PORT_PIN_PORT2(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT2_SHIFT))&LPC_GPIO_PORT_PIN_PORT2_MASK) /**< LPC_GPIO_PORT_PIN.PORT2 Field           */
#define LPC_GPIO_PORT_PIN_PORT3_MASK             (0x8U)                                              /**< LPC_GPIO_PORT_PIN.PORT3 Mask            */
#define LPC_GPIO_PORT_PIN_PORT3_SHIFT            (3U)                                                /**< LPC_GPIO_PORT_PIN.PORT3 Position        */
#define LPC_GPIO_PORT_PIN_PORT3(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT3_SHIFT))&LPC_GPIO_PORT_PIN_PORT3_MASK) /**< LPC_GPIO_PORT_PIN.PORT3 Field           */
#define LPC_GPIO_PORT_PIN_PORT4_MASK             (0x10U)                                             /**< LPC_GPIO_PORT_PIN.PORT4 Mask            */
#define LPC_GPIO_PORT_PIN_PORT4_SHIFT            (4U)                                                /**< LPC_GPIO_PORT_PIN.PORT4 Position        */
#define LPC_GPIO_PORT_PIN_PORT4(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT4_SHIFT))&LPC_GPIO_PORT_PIN_PORT4_MASK) /**< LPC_GPIO_PORT_PIN.PORT4 Field           */
#define LPC_GPIO_PORT_PIN_PORT5_MASK             (0x20U)                                             /**< LPC_GPIO_PORT_PIN.PORT5 Mask            */
#define LPC_GPIO_PORT_PIN_PORT5_SHIFT            (5U)                                                /**< LPC_GPIO_PORT_PIN.PORT5 Position        */
#define LPC_GPIO_PORT_PIN_PORT5(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT5_SHIFT))&LPC_GPIO_PORT_PIN_PORT5_MASK) /**< LPC_GPIO_PORT_PIN.PORT5 Field           */
#define LPC_GPIO_PORT_PIN_PORT6_MASK             (0x40U)                                             /**< LPC_GPIO_PORT_PIN.PORT6 Mask            */
#define LPC_GPIO_PORT_PIN_PORT6_SHIFT            (6U)                                                /**< LPC_GPIO_PORT_PIN.PORT6 Position        */
#define LPC_GPIO_PORT_PIN_PORT6(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT6_SHIFT))&LPC_GPIO_PORT_PIN_PORT6_MASK) /**< LPC_GPIO_PORT_PIN.PORT6 Field           */
#define LPC_GPIO_PORT_PIN_PORT7_MASK             (0x80U)                                             /**< LPC_GPIO_PORT_PIN.PORT7 Mask            */
#define LPC_GPIO_PORT_PIN_PORT7_SHIFT            (7U)                                                /**< LPC_GPIO_PORT_PIN.PORT7 Position        */
#define LPC_GPIO_PORT_PIN_PORT7(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT7_SHIFT))&LPC_GPIO_PORT_PIN_PORT7_MASK) /**< LPC_GPIO_PORT_PIN.PORT7 Field           */
#define LPC_GPIO_PORT_PIN_PORT8_MASK             (0x100U)                                            /**< LPC_GPIO_PORT_PIN.PORT8 Mask            */
#define LPC_GPIO_PORT_PIN_PORT8_SHIFT            (8U)                                                /**< LPC_GPIO_PORT_PIN.PORT8 Position        */
#define LPC_GPIO_PORT_PIN_PORT8(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT8_SHIFT))&LPC_GPIO_PORT_PIN_PORT8_MASK) /**< LPC_GPIO_PORT_PIN.PORT8 Field           */
#define LPC_GPIO_PORT_PIN_PORT9_MASK             (0x200U)                                            /**< LPC_GPIO_PORT_PIN.PORT9 Mask            */
#define LPC_GPIO_PORT_PIN_PORT9_SHIFT            (9U)                                                /**< LPC_GPIO_PORT_PIN.PORT9 Position        */
#define LPC_GPIO_PORT_PIN_PORT9(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT9_SHIFT))&LPC_GPIO_PORT_PIN_PORT9_MASK) /**< LPC_GPIO_PORT_PIN.PORT9 Field           */
#define LPC_GPIO_PORT_PIN_PORT10_MASK            (0x400U)                                            /**< LPC_GPIO_PORT_PIN.PORT10 Mask           */
#define LPC_GPIO_PORT_PIN_PORT10_SHIFT           (10U)                                               /**< LPC_GPIO_PORT_PIN.PORT10 Position       */
#define LPC_GPIO_PORT_PIN_PORT10(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT10_SHIFT))&LPC_GPIO_PORT_PIN_PORT10_MASK) /**< LPC_GPIO_PORT_PIN.PORT10 Field          */
#define LPC_GPIO_PORT_PIN_PORT11_MASK            (0x800U)                                            /**< LPC_GPIO_PORT_PIN.PORT11 Mask           */
#define LPC_GPIO_PORT_PIN_PORT11_SHIFT           (11U)                                               /**< LPC_GPIO_PORT_PIN.PORT11 Position       */
#define LPC_GPIO_PORT_PIN_PORT11(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT11_SHIFT))&LPC_GPIO_PORT_PIN_PORT11_MASK) /**< LPC_GPIO_PORT_PIN.PORT11 Field          */
#define LPC_GPIO_PORT_PIN_PORT12_MASK            (0x1000U)                                           /**< LPC_GPIO_PORT_PIN.PORT12 Mask           */
#define LPC_GPIO_PORT_PIN_PORT12_SHIFT           (12U)                                               /**< LPC_GPIO_PORT_PIN.PORT12 Position       */
#define LPC_GPIO_PORT_PIN_PORT12(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT12_SHIFT))&LPC_GPIO_PORT_PIN_PORT12_MASK) /**< LPC_GPIO_PORT_PIN.PORT12 Field          */
#define LPC_GPIO_PORT_PIN_PORT13_MASK            (0x2000U)                                           /**< LPC_GPIO_PORT_PIN.PORT13 Mask           */
#define LPC_GPIO_PORT_PIN_PORT13_SHIFT           (13U)                                               /**< LPC_GPIO_PORT_PIN.PORT13 Position       */
#define LPC_GPIO_PORT_PIN_PORT13(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT13_SHIFT))&LPC_GPIO_PORT_PIN_PORT13_MASK) /**< LPC_GPIO_PORT_PIN.PORT13 Field          */
#define LPC_GPIO_PORT_PIN_PORT14_MASK            (0x4000U)                                           /**< LPC_GPIO_PORT_PIN.PORT14 Mask           */
#define LPC_GPIO_PORT_PIN_PORT14_SHIFT           (14U)                                               /**< LPC_GPIO_PORT_PIN.PORT14 Position       */
#define LPC_GPIO_PORT_PIN_PORT14(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT14_SHIFT))&LPC_GPIO_PORT_PIN_PORT14_MASK) /**< LPC_GPIO_PORT_PIN.PORT14 Field          */
#define LPC_GPIO_PORT_PIN_PORT15_MASK            (0x8000U)                                           /**< LPC_GPIO_PORT_PIN.PORT15 Mask           */
#define LPC_GPIO_PORT_PIN_PORT15_SHIFT           (15U)                                               /**< LPC_GPIO_PORT_PIN.PORT15 Position       */
#define LPC_GPIO_PORT_PIN_PORT15(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT15_SHIFT))&LPC_GPIO_PORT_PIN_PORT15_MASK) /**< LPC_GPIO_PORT_PIN.PORT15 Field          */
#define LPC_GPIO_PORT_PIN_PORT16_MASK            (0x10000U)                                          /**< LPC_GPIO_PORT_PIN.PORT16 Mask           */
#define LPC_GPIO_PORT_PIN_PORT16_SHIFT           (16U)                                               /**< LPC_GPIO_PORT_PIN.PORT16 Position       */
#define LPC_GPIO_PORT_PIN_PORT16(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT16_SHIFT))&LPC_GPIO_PORT_PIN_PORT16_MASK) /**< LPC_GPIO_PORT_PIN.PORT16 Field          */
#define LPC_GPIO_PORT_PIN_PORT17_MASK            (0x20000U)                                          /**< LPC_GPIO_PORT_PIN.PORT17 Mask           */
#define LPC_GPIO_PORT_PIN_PORT17_SHIFT           (17U)                                               /**< LPC_GPIO_PORT_PIN.PORT17 Position       */
#define LPC_GPIO_PORT_PIN_PORT17(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT17_SHIFT))&LPC_GPIO_PORT_PIN_PORT17_MASK) /**< LPC_GPIO_PORT_PIN.PORT17 Field          */
#define LPC_GPIO_PORT_PIN_PORT18_MASK            (0x40000U)                                          /**< LPC_GPIO_PORT_PIN.PORT18 Mask           */
#define LPC_GPIO_PORT_PIN_PORT18_SHIFT           (18U)                                               /**< LPC_GPIO_PORT_PIN.PORT18 Position       */
#define LPC_GPIO_PORT_PIN_PORT18(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT18_SHIFT))&LPC_GPIO_PORT_PIN_PORT18_MASK) /**< LPC_GPIO_PORT_PIN.PORT18 Field          */
#define LPC_GPIO_PORT_PIN_PORT19_MASK            (0x80000U)                                          /**< LPC_GPIO_PORT_PIN.PORT19 Mask           */
#define LPC_GPIO_PORT_PIN_PORT19_SHIFT           (19U)                                               /**< LPC_GPIO_PORT_PIN.PORT19 Position       */
#define LPC_GPIO_PORT_PIN_PORT19(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT19_SHIFT))&LPC_GPIO_PORT_PIN_PORT19_MASK) /**< LPC_GPIO_PORT_PIN.PORT19 Field          */
#define LPC_GPIO_PORT_PIN_PORT20_MASK            (0x100000U)                                         /**< LPC_GPIO_PORT_PIN.PORT20 Mask           */
#define LPC_GPIO_PORT_PIN_PORT20_SHIFT           (20U)                                               /**< LPC_GPIO_PORT_PIN.PORT20 Position       */
#define LPC_GPIO_PORT_PIN_PORT20(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT20_SHIFT))&LPC_GPIO_PORT_PIN_PORT20_MASK) /**< LPC_GPIO_PORT_PIN.PORT20 Field          */
#define LPC_GPIO_PORT_PIN_PORT21_MASK            (0x200000U)                                         /**< LPC_GPIO_PORT_PIN.PORT21 Mask           */
#define LPC_GPIO_PORT_PIN_PORT21_SHIFT           (21U)                                               /**< LPC_GPIO_PORT_PIN.PORT21 Position       */
#define LPC_GPIO_PORT_PIN_PORT21(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT21_SHIFT))&LPC_GPIO_PORT_PIN_PORT21_MASK) /**< LPC_GPIO_PORT_PIN.PORT21 Field          */
#define LPC_GPIO_PORT_PIN_PORT22_MASK            (0x400000U)                                         /**< LPC_GPIO_PORT_PIN.PORT22 Mask           */
#define LPC_GPIO_PORT_PIN_PORT22_SHIFT           (22U)                                               /**< LPC_GPIO_PORT_PIN.PORT22 Position       */
#define LPC_GPIO_PORT_PIN_PORT22(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT22_SHIFT))&LPC_GPIO_PORT_PIN_PORT22_MASK) /**< LPC_GPIO_PORT_PIN.PORT22 Field          */
#define LPC_GPIO_PORT_PIN_PORT23_MASK            (0x800000U)                                         /**< LPC_GPIO_PORT_PIN.PORT23 Mask           */
#define LPC_GPIO_PORT_PIN_PORT23_SHIFT           (23U)                                               /**< LPC_GPIO_PORT_PIN.PORT23 Position       */
#define LPC_GPIO_PORT_PIN_PORT23(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT23_SHIFT))&LPC_GPIO_PORT_PIN_PORT23_MASK) /**< LPC_GPIO_PORT_PIN.PORT23 Field          */
#define LPC_GPIO_PORT_PIN_PORT24_MASK            (0x1000000U)                                        /**< LPC_GPIO_PORT_PIN.PORT24 Mask           */
#define LPC_GPIO_PORT_PIN_PORT24_SHIFT           (24U)                                               /**< LPC_GPIO_PORT_PIN.PORT24 Position       */
#define LPC_GPIO_PORT_PIN_PORT24(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT24_SHIFT))&LPC_GPIO_PORT_PIN_PORT24_MASK) /**< LPC_GPIO_PORT_PIN.PORT24 Field          */
#define LPC_GPIO_PORT_PIN_PORT25_MASK            (0x2000000U)                                        /**< LPC_GPIO_PORT_PIN.PORT25 Mask           */
#define LPC_GPIO_PORT_PIN_PORT25_SHIFT           (25U)                                               /**< LPC_GPIO_PORT_PIN.PORT25 Position       */
#define LPC_GPIO_PORT_PIN_PORT25(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT25_SHIFT))&LPC_GPIO_PORT_PIN_PORT25_MASK) /**< LPC_GPIO_PORT_PIN.PORT25 Field          */
#define LPC_GPIO_PORT_PIN_PORT26_MASK            (0x4000000U)                                        /**< LPC_GPIO_PORT_PIN.PORT26 Mask           */
#define LPC_GPIO_PORT_PIN_PORT26_SHIFT           (26U)                                               /**< LPC_GPIO_PORT_PIN.PORT26 Position       */
#define LPC_GPIO_PORT_PIN_PORT26(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT26_SHIFT))&LPC_GPIO_PORT_PIN_PORT26_MASK) /**< LPC_GPIO_PORT_PIN.PORT26 Field          */
#define LPC_GPIO_PORT_PIN_PORT27_MASK            (0x8000000U)                                        /**< LPC_GPIO_PORT_PIN.PORT27 Mask           */
#define LPC_GPIO_PORT_PIN_PORT27_SHIFT           (27U)                                               /**< LPC_GPIO_PORT_PIN.PORT27 Position       */
#define LPC_GPIO_PORT_PIN_PORT27(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT27_SHIFT))&LPC_GPIO_PORT_PIN_PORT27_MASK) /**< LPC_GPIO_PORT_PIN.PORT27 Field          */
#define LPC_GPIO_PORT_PIN_PORT28_MASK            (0x10000000U)                                       /**< LPC_GPIO_PORT_PIN.PORT28 Mask           */
#define LPC_GPIO_PORT_PIN_PORT28_SHIFT           (28U)                                               /**< LPC_GPIO_PORT_PIN.PORT28 Position       */
#define LPC_GPIO_PORT_PIN_PORT28(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT28_SHIFT))&LPC_GPIO_PORT_PIN_PORT28_MASK) /**< LPC_GPIO_PORT_PIN.PORT28 Field          */
#define LPC_GPIO_PORT_PIN_PORT29_MASK            (0x20000000U)                                       /**< LPC_GPIO_PORT_PIN.PORT29 Mask           */
#define LPC_GPIO_PORT_PIN_PORT29_SHIFT           (29U)                                               /**< LPC_GPIO_PORT_PIN.PORT29 Position       */
#define LPC_GPIO_PORT_PIN_PORT29(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT29_SHIFT))&LPC_GPIO_PORT_PIN_PORT29_MASK) /**< LPC_GPIO_PORT_PIN.PORT29 Field          */
#define LPC_GPIO_PORT_PIN_PORT30_MASK            (0x40000000U)                                       /**< LPC_GPIO_PORT_PIN.PORT30 Mask           */
#define LPC_GPIO_PORT_PIN_PORT30_SHIFT           (30U)                                               /**< LPC_GPIO_PORT_PIN.PORT30 Position       */
#define LPC_GPIO_PORT_PIN_PORT30(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT30_SHIFT))&LPC_GPIO_PORT_PIN_PORT30_MASK) /**< LPC_GPIO_PORT_PIN.PORT30 Field          */
#define LPC_GPIO_PORT_PIN_PORT31_MASK            (0x80000000U)                                       /**< LPC_GPIO_PORT_PIN.PORT31 Mask           */
#define LPC_GPIO_PORT_PIN_PORT31_SHIFT           (31U)                                               /**< LPC_GPIO_PORT_PIN.PORT31 Position       */
#define LPC_GPIO_PORT_PIN_PORT31(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN_PORT31_SHIFT))&LPC_GPIO_PORT_PIN_PORT31_MASK) /**< LPC_GPIO_PORT_PIN.PORT31 Field          */
/** @} */

/** @name MPIN - Masked port register port %s */ /** @{ */
#define LPC_GPIO_PORT_MPIN_MPORTP0_MASK          (0x1U)                                              /**< LPC_GPIO_PORT_MPIN.MPORTP0 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP0_SHIFT         (0U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP0 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP0(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP0_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP0_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP0 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP1_MASK          (0x2U)                                              /**< LPC_GPIO_PORT_MPIN.MPORTP1 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP1_SHIFT         (1U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP1 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP1(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP1_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP1_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP1 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP2_MASK          (0x4U)                                              /**< LPC_GPIO_PORT_MPIN.MPORTP2 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP2_SHIFT         (2U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP2 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP2(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP2_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP2_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP2 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP3_MASK          (0x8U)                                              /**< LPC_GPIO_PORT_MPIN.MPORTP3 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP3_SHIFT         (3U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP3 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP3(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP3_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP3_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP3 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP4_MASK          (0x10U)                                             /**< LPC_GPIO_PORT_MPIN.MPORTP4 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP4_SHIFT         (4U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP4 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP4(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP4_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP4_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP4 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP5_MASK          (0x20U)                                             /**< LPC_GPIO_PORT_MPIN.MPORTP5 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP5_SHIFT         (5U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP5 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP5(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP5_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP5_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP5 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP6_MASK          (0x40U)                                             /**< LPC_GPIO_PORT_MPIN.MPORTP6 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP6_SHIFT         (6U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP6 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP6(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP6_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP6_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP6 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP7_MASK          (0x80U)                                             /**< LPC_GPIO_PORT_MPIN.MPORTP7 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP7_SHIFT         (7U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP7 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP7(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP7_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP7_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP7 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP8_MASK          (0x100U)                                            /**< LPC_GPIO_PORT_MPIN.MPORTP8 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP8_SHIFT         (8U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP8 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP8(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP8_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP8_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP8 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP9_MASK          (0x200U)                                            /**< LPC_GPIO_PORT_MPIN.MPORTP9 Mask         */
#define LPC_GPIO_PORT_MPIN_MPORTP9_SHIFT         (9U)                                                /**< LPC_GPIO_PORT_MPIN.MPORTP9 Position     */
#define LPC_GPIO_PORT_MPIN_MPORTP9(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP9_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP9_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP9 Field        */
#define LPC_GPIO_PORT_MPIN_MPORTP10_MASK         (0x400U)                                            /**< LPC_GPIO_PORT_MPIN.MPORTP10 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP10_SHIFT        (10U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP10 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP10(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP10_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP10_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP10 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP11_MASK         (0x800U)                                            /**< LPC_GPIO_PORT_MPIN.MPORTP11 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP11_SHIFT        (11U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP11 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP11(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP11_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP11_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP11 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP12_MASK         (0x1000U)                                           /**< LPC_GPIO_PORT_MPIN.MPORTP12 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP12_SHIFT        (12U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP12 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP12(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP12_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP12_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP12 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP13_MASK         (0x2000U)                                           /**< LPC_GPIO_PORT_MPIN.MPORTP13 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP13_SHIFT        (13U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP13 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP13(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP13_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP13_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP13 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP14_MASK         (0x4000U)                                           /**< LPC_GPIO_PORT_MPIN.MPORTP14 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP14_SHIFT        (14U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP14 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP14(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP14_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP14_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP14 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP15_MASK         (0x8000U)                                           /**< LPC_GPIO_PORT_MPIN.MPORTP15 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP15_SHIFT        (15U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP15 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP15(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP15_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP15_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP15 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP16_MASK         (0x10000U)                                          /**< LPC_GPIO_PORT_MPIN.MPORTP16 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP16_SHIFT        (16U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP16 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP16(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP16_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP16_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP16 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP17_MASK         (0x20000U)                                          /**< LPC_GPIO_PORT_MPIN.MPORTP17 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP17_SHIFT        (17U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP17 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP17(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP17_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP17_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP17 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP18_MASK         (0x40000U)                                          /**< LPC_GPIO_PORT_MPIN.MPORTP18 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP18_SHIFT        (18U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP18 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP18(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP18_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP18_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP18 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP19_MASK         (0x80000U)                                          /**< LPC_GPIO_PORT_MPIN.MPORTP19 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP19_SHIFT        (19U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP19 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP19(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP19_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP19_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP19 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP20_MASK         (0x100000U)                                         /**< LPC_GPIO_PORT_MPIN.MPORTP20 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP20_SHIFT        (20U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP20 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP20(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP20_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP20_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP20 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP21_MASK         (0x200000U)                                         /**< LPC_GPIO_PORT_MPIN.MPORTP21 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP21_SHIFT        (21U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP21 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP21(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP21_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP21_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP21 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP22_MASK         (0x400000U)                                         /**< LPC_GPIO_PORT_MPIN.MPORTP22 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP22_SHIFT        (22U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP22 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP22(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP22_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP22_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP22 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP23_MASK         (0x800000U)                                         /**< LPC_GPIO_PORT_MPIN.MPORTP23 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP23_SHIFT        (23U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP23 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP23(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP23_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP23_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP23 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP24_MASK         (0x1000000U)                                        /**< LPC_GPIO_PORT_MPIN.MPORTP24 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP24_SHIFT        (24U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP24 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP24(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP24_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP24_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP24 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP25_MASK         (0x2000000U)                                        /**< LPC_GPIO_PORT_MPIN.MPORTP25 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP25_SHIFT        (25U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP25 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP25(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP25_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP25_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP25 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP26_MASK         (0x4000000U)                                        /**< LPC_GPIO_PORT_MPIN.MPORTP26 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP26_SHIFT        (26U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP26 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP26(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP26_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP26_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP26 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP27_MASK         (0x8000000U)                                        /**< LPC_GPIO_PORT_MPIN.MPORTP27 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP27_SHIFT        (27U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP27 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP27(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP27_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP27_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP27 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP28_MASK         (0x10000000U)                                       /**< LPC_GPIO_PORT_MPIN.MPORTP28 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP28_SHIFT        (28U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP28 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP28(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP28_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP28_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP28 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP29_MASK         (0x20000000U)                                       /**< LPC_GPIO_PORT_MPIN.MPORTP29 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP29_SHIFT        (29U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP29 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP29(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP29_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP29_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP29 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP30_MASK         (0x40000000U)                                       /**< LPC_GPIO_PORT_MPIN.MPORTP30 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP30_SHIFT        (30U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP30 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP30(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP30_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP30_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP30 Field       */
#define LPC_GPIO_PORT_MPIN_MPORTP31_MASK         (0x80000000U)                                       /**< LPC_GPIO_PORT_MPIN.MPORTP31 Mask        */
#define LPC_GPIO_PORT_MPIN_MPORTP31_SHIFT        (31U)                                               /**< LPC_GPIO_PORT_MPIN.MPORTP31 Position    */
#define LPC_GPIO_PORT_MPIN_MPORTP31(x)           (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN_MPORTP31_SHIFT))&LPC_GPIO_PORT_MPIN_MPORTP31_MASK) /**< LPC_GPIO_PORT_MPIN.MPORTP31 Field       */
/** @} */

/** @name SET - Write: Set register for port,  Read: output bits for port */ /** @{ */
#define LPC_GPIO_PORT_SET_SETP0_MASK             (0x1U)                                              /**< LPC_GPIO_PORT_SET.SETP0 Mask            */
#define LPC_GPIO_PORT_SET_SETP0_SHIFT            (0U)                                                /**< LPC_GPIO_PORT_SET.SETP0 Position        */
#define LPC_GPIO_PORT_SET_SETP0(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP0_SHIFT))&LPC_GPIO_PORT_SET_SETP0_MASK) /**< LPC_GPIO_PORT_SET.SETP0 Field           */
#define LPC_GPIO_PORT_SET_SETP1_MASK             (0x2U)                                              /**< LPC_GPIO_PORT_SET.SETP1 Mask            */
#define LPC_GPIO_PORT_SET_SETP1_SHIFT            (1U)                                                /**< LPC_GPIO_PORT_SET.SETP1 Position        */
#define LPC_GPIO_PORT_SET_SETP1(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP1_SHIFT))&LPC_GPIO_PORT_SET_SETP1_MASK) /**< LPC_GPIO_PORT_SET.SETP1 Field           */
#define LPC_GPIO_PORT_SET_SETP2_MASK             (0x4U)                                              /**< LPC_GPIO_PORT_SET.SETP2 Mask            */
#define LPC_GPIO_PORT_SET_SETP2_SHIFT            (2U)                                                /**< LPC_GPIO_PORT_SET.SETP2 Position        */
#define LPC_GPIO_PORT_SET_SETP2(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP2_SHIFT))&LPC_GPIO_PORT_SET_SETP2_MASK) /**< LPC_GPIO_PORT_SET.SETP2 Field           */
#define LPC_GPIO_PORT_SET_SETP3_MASK             (0x8U)                                              /**< LPC_GPIO_PORT_SET.SETP3 Mask            */
#define LPC_GPIO_PORT_SET_SETP3_SHIFT            (3U)                                                /**< LPC_GPIO_PORT_SET.SETP3 Position        */
#define LPC_GPIO_PORT_SET_SETP3(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP3_SHIFT))&LPC_GPIO_PORT_SET_SETP3_MASK) /**< LPC_GPIO_PORT_SET.SETP3 Field           */
#define LPC_GPIO_PORT_SET_SETP4_MASK             (0x10U)                                             /**< LPC_GPIO_PORT_SET.SETP4 Mask            */
#define LPC_GPIO_PORT_SET_SETP4_SHIFT            (4U)                                                /**< LPC_GPIO_PORT_SET.SETP4 Position        */
#define LPC_GPIO_PORT_SET_SETP4(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP4_SHIFT))&LPC_GPIO_PORT_SET_SETP4_MASK) /**< LPC_GPIO_PORT_SET.SETP4 Field           */
#define LPC_GPIO_PORT_SET_SETP5_MASK             (0x20U)                                             /**< LPC_GPIO_PORT_SET.SETP5 Mask            */
#define LPC_GPIO_PORT_SET_SETP5_SHIFT            (5U)                                                /**< LPC_GPIO_PORT_SET.SETP5 Position        */
#define LPC_GPIO_PORT_SET_SETP5(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP5_SHIFT))&LPC_GPIO_PORT_SET_SETP5_MASK) /**< LPC_GPIO_PORT_SET.SETP5 Field           */
#define LPC_GPIO_PORT_SET_SETP6_MASK             (0x40U)                                             /**< LPC_GPIO_PORT_SET.SETP6 Mask            */
#define LPC_GPIO_PORT_SET_SETP6_SHIFT            (6U)                                                /**< LPC_GPIO_PORT_SET.SETP6 Position        */
#define LPC_GPIO_PORT_SET_SETP6(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP6_SHIFT))&LPC_GPIO_PORT_SET_SETP6_MASK) /**< LPC_GPIO_PORT_SET.SETP6 Field           */
#define LPC_GPIO_PORT_SET_SETP7_MASK             (0x80U)                                             /**< LPC_GPIO_PORT_SET.SETP7 Mask            */
#define LPC_GPIO_PORT_SET_SETP7_SHIFT            (7U)                                                /**< LPC_GPIO_PORT_SET.SETP7 Position        */
#define LPC_GPIO_PORT_SET_SETP7(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP7_SHIFT))&LPC_GPIO_PORT_SET_SETP7_MASK) /**< LPC_GPIO_PORT_SET.SETP7 Field           */
#define LPC_GPIO_PORT_SET_SETP8_MASK             (0x100U)                                            /**< LPC_GPIO_PORT_SET.SETP8 Mask            */
#define LPC_GPIO_PORT_SET_SETP8_SHIFT            (8U)                                                /**< LPC_GPIO_PORT_SET.SETP8 Position        */
#define LPC_GPIO_PORT_SET_SETP8(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP8_SHIFT))&LPC_GPIO_PORT_SET_SETP8_MASK) /**< LPC_GPIO_PORT_SET.SETP8 Field           */
#define LPC_GPIO_PORT_SET_SETP9_MASK             (0x200U)                                            /**< LPC_GPIO_PORT_SET.SETP9 Mask            */
#define LPC_GPIO_PORT_SET_SETP9_SHIFT            (9U)                                                /**< LPC_GPIO_PORT_SET.SETP9 Position        */
#define LPC_GPIO_PORT_SET_SETP9(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP9_SHIFT))&LPC_GPIO_PORT_SET_SETP9_MASK) /**< LPC_GPIO_PORT_SET.SETP9 Field           */
#define LPC_GPIO_PORT_SET_SETP10_MASK            (0x400U)                                            /**< LPC_GPIO_PORT_SET.SETP10 Mask           */
#define LPC_GPIO_PORT_SET_SETP10_SHIFT           (10U)                                               /**< LPC_GPIO_PORT_SET.SETP10 Position       */
#define LPC_GPIO_PORT_SET_SETP10(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP10_SHIFT))&LPC_GPIO_PORT_SET_SETP10_MASK) /**< LPC_GPIO_PORT_SET.SETP10 Field          */
#define LPC_GPIO_PORT_SET_SETP11_MASK            (0x800U)                                            /**< LPC_GPIO_PORT_SET.SETP11 Mask           */
#define LPC_GPIO_PORT_SET_SETP11_SHIFT           (11U)                                               /**< LPC_GPIO_PORT_SET.SETP11 Position       */
#define LPC_GPIO_PORT_SET_SETP11(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP11_SHIFT))&LPC_GPIO_PORT_SET_SETP11_MASK) /**< LPC_GPIO_PORT_SET.SETP11 Field          */
#define LPC_GPIO_PORT_SET_SETP12_MASK            (0x1000U)                                           /**< LPC_GPIO_PORT_SET.SETP12 Mask           */
#define LPC_GPIO_PORT_SET_SETP12_SHIFT           (12U)                                               /**< LPC_GPIO_PORT_SET.SETP12 Position       */
#define LPC_GPIO_PORT_SET_SETP12(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP12_SHIFT))&LPC_GPIO_PORT_SET_SETP12_MASK) /**< LPC_GPIO_PORT_SET.SETP12 Field          */
#define LPC_GPIO_PORT_SET_SETP13_MASK            (0x2000U)                                           /**< LPC_GPIO_PORT_SET.SETP13 Mask           */
#define LPC_GPIO_PORT_SET_SETP13_SHIFT           (13U)                                               /**< LPC_GPIO_PORT_SET.SETP13 Position       */
#define LPC_GPIO_PORT_SET_SETP13(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP13_SHIFT))&LPC_GPIO_PORT_SET_SETP13_MASK) /**< LPC_GPIO_PORT_SET.SETP13 Field          */
#define LPC_GPIO_PORT_SET_SETP14_MASK            (0x4000U)                                           /**< LPC_GPIO_PORT_SET.SETP14 Mask           */
#define LPC_GPIO_PORT_SET_SETP14_SHIFT           (14U)                                               /**< LPC_GPIO_PORT_SET.SETP14 Position       */
#define LPC_GPIO_PORT_SET_SETP14(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP14_SHIFT))&LPC_GPIO_PORT_SET_SETP14_MASK) /**< LPC_GPIO_PORT_SET.SETP14 Field          */
#define LPC_GPIO_PORT_SET_SETP15_MASK            (0x8000U)                                           /**< LPC_GPIO_PORT_SET.SETP15 Mask           */
#define LPC_GPIO_PORT_SET_SETP15_SHIFT           (15U)                                               /**< LPC_GPIO_PORT_SET.SETP15 Position       */
#define LPC_GPIO_PORT_SET_SETP15(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP15_SHIFT))&LPC_GPIO_PORT_SET_SETP15_MASK) /**< LPC_GPIO_PORT_SET.SETP15 Field          */
#define LPC_GPIO_PORT_SET_SETP16_MASK            (0x10000U)                                          /**< LPC_GPIO_PORT_SET.SETP16 Mask           */
#define LPC_GPIO_PORT_SET_SETP16_SHIFT           (16U)                                               /**< LPC_GPIO_PORT_SET.SETP16 Position       */
#define LPC_GPIO_PORT_SET_SETP16(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP16_SHIFT))&LPC_GPIO_PORT_SET_SETP16_MASK) /**< LPC_GPIO_PORT_SET.SETP16 Field          */
#define LPC_GPIO_PORT_SET_SETP17_MASK            (0x20000U)                                          /**< LPC_GPIO_PORT_SET.SETP17 Mask           */
#define LPC_GPIO_PORT_SET_SETP17_SHIFT           (17U)                                               /**< LPC_GPIO_PORT_SET.SETP17 Position       */
#define LPC_GPIO_PORT_SET_SETP17(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP17_SHIFT))&LPC_GPIO_PORT_SET_SETP17_MASK) /**< LPC_GPIO_PORT_SET.SETP17 Field          */
#define LPC_GPIO_PORT_SET_SETP18_MASK            (0x40000U)                                          /**< LPC_GPIO_PORT_SET.SETP18 Mask           */
#define LPC_GPIO_PORT_SET_SETP18_SHIFT           (18U)                                               /**< LPC_GPIO_PORT_SET.SETP18 Position       */
#define LPC_GPIO_PORT_SET_SETP18(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP18_SHIFT))&LPC_GPIO_PORT_SET_SETP18_MASK) /**< LPC_GPIO_PORT_SET.SETP18 Field          */
#define LPC_GPIO_PORT_SET_SETP19_MASK            (0x80000U)                                          /**< LPC_GPIO_PORT_SET.SETP19 Mask           */
#define LPC_GPIO_PORT_SET_SETP19_SHIFT           (19U)                                               /**< LPC_GPIO_PORT_SET.SETP19 Position       */
#define LPC_GPIO_PORT_SET_SETP19(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP19_SHIFT))&LPC_GPIO_PORT_SET_SETP19_MASK) /**< LPC_GPIO_PORT_SET.SETP19 Field          */
#define LPC_GPIO_PORT_SET_SETP20_MASK            (0x100000U)                                         /**< LPC_GPIO_PORT_SET.SETP20 Mask           */
#define LPC_GPIO_PORT_SET_SETP20_SHIFT           (20U)                                               /**< LPC_GPIO_PORT_SET.SETP20 Position       */
#define LPC_GPIO_PORT_SET_SETP20(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP20_SHIFT))&LPC_GPIO_PORT_SET_SETP20_MASK) /**< LPC_GPIO_PORT_SET.SETP20 Field          */
#define LPC_GPIO_PORT_SET_SETP21_MASK            (0x200000U)                                         /**< LPC_GPIO_PORT_SET.SETP21 Mask           */
#define LPC_GPIO_PORT_SET_SETP21_SHIFT           (21U)                                               /**< LPC_GPIO_PORT_SET.SETP21 Position       */
#define LPC_GPIO_PORT_SET_SETP21(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP21_SHIFT))&LPC_GPIO_PORT_SET_SETP21_MASK) /**< LPC_GPIO_PORT_SET.SETP21 Field          */
#define LPC_GPIO_PORT_SET_SETP22_MASK            (0x400000U)                                         /**< LPC_GPIO_PORT_SET.SETP22 Mask           */
#define LPC_GPIO_PORT_SET_SETP22_SHIFT           (22U)                                               /**< LPC_GPIO_PORT_SET.SETP22 Position       */
#define LPC_GPIO_PORT_SET_SETP22(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP22_SHIFT))&LPC_GPIO_PORT_SET_SETP22_MASK) /**< LPC_GPIO_PORT_SET.SETP22 Field          */
#define LPC_GPIO_PORT_SET_SETP23_MASK            (0x800000U)                                         /**< LPC_GPIO_PORT_SET.SETP23 Mask           */
#define LPC_GPIO_PORT_SET_SETP23_SHIFT           (23U)                                               /**< LPC_GPIO_PORT_SET.SETP23 Position       */
#define LPC_GPIO_PORT_SET_SETP23(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP23_SHIFT))&LPC_GPIO_PORT_SET_SETP23_MASK) /**< LPC_GPIO_PORT_SET.SETP23 Field          */
#define LPC_GPIO_PORT_SET_SETP24_MASK            (0x1000000U)                                        /**< LPC_GPIO_PORT_SET.SETP24 Mask           */
#define LPC_GPIO_PORT_SET_SETP24_SHIFT           (24U)                                               /**< LPC_GPIO_PORT_SET.SETP24 Position       */
#define LPC_GPIO_PORT_SET_SETP24(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP24_SHIFT))&LPC_GPIO_PORT_SET_SETP24_MASK) /**< LPC_GPIO_PORT_SET.SETP24 Field          */
#define LPC_GPIO_PORT_SET_SETP25_MASK            (0x2000000U)                                        /**< LPC_GPIO_PORT_SET.SETP25 Mask           */
#define LPC_GPIO_PORT_SET_SETP25_SHIFT           (25U)                                               /**< LPC_GPIO_PORT_SET.SETP25 Position       */
#define LPC_GPIO_PORT_SET_SETP25(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP25_SHIFT))&LPC_GPIO_PORT_SET_SETP25_MASK) /**< LPC_GPIO_PORT_SET.SETP25 Field          */
#define LPC_GPIO_PORT_SET_SETP26_MASK            (0x4000000U)                                        /**< LPC_GPIO_PORT_SET.SETP26 Mask           */
#define LPC_GPIO_PORT_SET_SETP26_SHIFT           (26U)                                               /**< LPC_GPIO_PORT_SET.SETP26 Position       */
#define LPC_GPIO_PORT_SET_SETP26(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP26_SHIFT))&LPC_GPIO_PORT_SET_SETP26_MASK) /**< LPC_GPIO_PORT_SET.SETP26 Field          */
#define LPC_GPIO_PORT_SET_SETP27_MASK            (0x8000000U)                                        /**< LPC_GPIO_PORT_SET.SETP27 Mask           */
#define LPC_GPIO_PORT_SET_SETP27_SHIFT           (27U)                                               /**< LPC_GPIO_PORT_SET.SETP27 Position       */
#define LPC_GPIO_PORT_SET_SETP27(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP27_SHIFT))&LPC_GPIO_PORT_SET_SETP27_MASK) /**< LPC_GPIO_PORT_SET.SETP27 Field          */
#define LPC_GPIO_PORT_SET_SETP28_MASK            (0x10000000U)                                       /**< LPC_GPIO_PORT_SET.SETP28 Mask           */
#define LPC_GPIO_PORT_SET_SETP28_SHIFT           (28U)                                               /**< LPC_GPIO_PORT_SET.SETP28 Position       */
#define LPC_GPIO_PORT_SET_SETP28(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP28_SHIFT))&LPC_GPIO_PORT_SET_SETP28_MASK) /**< LPC_GPIO_PORT_SET.SETP28 Field          */
#define LPC_GPIO_PORT_SET_SETP29_MASK            (0x20000000U)                                       /**< LPC_GPIO_PORT_SET.SETP29 Mask           */
#define LPC_GPIO_PORT_SET_SETP29_SHIFT           (29U)                                               /**< LPC_GPIO_PORT_SET.SETP29 Position       */
#define LPC_GPIO_PORT_SET_SETP29(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP29_SHIFT))&LPC_GPIO_PORT_SET_SETP29_MASK) /**< LPC_GPIO_PORT_SET.SETP29 Field          */
#define LPC_GPIO_PORT_SET_SETP30_MASK            (0x40000000U)                                       /**< LPC_GPIO_PORT_SET.SETP30 Mask           */
#define LPC_GPIO_PORT_SET_SETP30_SHIFT           (30U)                                               /**< LPC_GPIO_PORT_SET.SETP30 Position       */
#define LPC_GPIO_PORT_SET_SETP30(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP30_SHIFT))&LPC_GPIO_PORT_SET_SETP30_MASK) /**< LPC_GPIO_PORT_SET.SETP30 Field          */
#define LPC_GPIO_PORT_SET_SETP31_MASK            (0x80000000U)                                       /**< LPC_GPIO_PORT_SET.SETP31 Mask           */
#define LPC_GPIO_PORT_SET_SETP31_SHIFT           (31U)                                               /**< LPC_GPIO_PORT_SET.SETP31 Position       */
#define LPC_GPIO_PORT_SET_SETP31(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET_SETP31_SHIFT))&LPC_GPIO_PORT_SET_SETP31_MASK) /**< LPC_GPIO_PORT_SET.SETP31 Field          */
/** @} */

/** @name CLR - Clear port %s */ /** @{ */
#define LPC_GPIO_PORT_CLR_CLRP00_MASK            (0x1U)                                              /**< LPC_GPIO_PORT_CLR.CLRP00 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP00_SHIFT           (0U)                                                /**< LPC_GPIO_PORT_CLR.CLRP00 Position       */
#define LPC_GPIO_PORT_CLR_CLRP00(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP00_SHIFT))&LPC_GPIO_PORT_CLR_CLRP00_MASK) /**< LPC_GPIO_PORT_CLR.CLRP00 Field          */
#define LPC_GPIO_PORT_CLR_CLRP01_MASK            (0x2U)                                              /**< LPC_GPIO_PORT_CLR.CLRP01 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP01_SHIFT           (1U)                                                /**< LPC_GPIO_PORT_CLR.CLRP01 Position       */
#define LPC_GPIO_PORT_CLR_CLRP01(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP01_SHIFT))&LPC_GPIO_PORT_CLR_CLRP01_MASK) /**< LPC_GPIO_PORT_CLR.CLRP01 Field          */
#define LPC_GPIO_PORT_CLR_CLRP02_MASK            (0x4U)                                              /**< LPC_GPIO_PORT_CLR.CLRP02 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP02_SHIFT           (2U)                                                /**< LPC_GPIO_PORT_CLR.CLRP02 Position       */
#define LPC_GPIO_PORT_CLR_CLRP02(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP02_SHIFT))&LPC_GPIO_PORT_CLR_CLRP02_MASK) /**< LPC_GPIO_PORT_CLR.CLRP02 Field          */
#define LPC_GPIO_PORT_CLR_CLRP03_MASK            (0x8U)                                              /**< LPC_GPIO_PORT_CLR.CLRP03 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP03_SHIFT           (3U)                                                /**< LPC_GPIO_PORT_CLR.CLRP03 Position       */
#define LPC_GPIO_PORT_CLR_CLRP03(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP03_SHIFT))&LPC_GPIO_PORT_CLR_CLRP03_MASK) /**< LPC_GPIO_PORT_CLR.CLRP03 Field          */
#define LPC_GPIO_PORT_CLR_CLRP04_MASK            (0x10U)                                             /**< LPC_GPIO_PORT_CLR.CLRP04 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP04_SHIFT           (4U)                                                /**< LPC_GPIO_PORT_CLR.CLRP04 Position       */
#define LPC_GPIO_PORT_CLR_CLRP04(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP04_SHIFT))&LPC_GPIO_PORT_CLR_CLRP04_MASK) /**< LPC_GPIO_PORT_CLR.CLRP04 Field          */
#define LPC_GPIO_PORT_CLR_CLRP05_MASK            (0x20U)                                             /**< LPC_GPIO_PORT_CLR.CLRP05 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP05_SHIFT           (5U)                                                /**< LPC_GPIO_PORT_CLR.CLRP05 Position       */
#define LPC_GPIO_PORT_CLR_CLRP05(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP05_SHIFT))&LPC_GPIO_PORT_CLR_CLRP05_MASK) /**< LPC_GPIO_PORT_CLR.CLRP05 Field          */
#define LPC_GPIO_PORT_CLR_CLRP06_MASK            (0x40U)                                             /**< LPC_GPIO_PORT_CLR.CLRP06 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP06_SHIFT           (6U)                                                /**< LPC_GPIO_PORT_CLR.CLRP06 Position       */
#define LPC_GPIO_PORT_CLR_CLRP06(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP06_SHIFT))&LPC_GPIO_PORT_CLR_CLRP06_MASK) /**< LPC_GPIO_PORT_CLR.CLRP06 Field          */
#define LPC_GPIO_PORT_CLR_CLRP07_MASK            (0x80U)                                             /**< LPC_GPIO_PORT_CLR.CLRP07 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP07_SHIFT           (7U)                                                /**< LPC_GPIO_PORT_CLR.CLRP07 Position       */
#define LPC_GPIO_PORT_CLR_CLRP07(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP07_SHIFT))&LPC_GPIO_PORT_CLR_CLRP07_MASK) /**< LPC_GPIO_PORT_CLR.CLRP07 Field          */
#define LPC_GPIO_PORT_CLR_CLRP08_MASK            (0x100U)                                            /**< LPC_GPIO_PORT_CLR.CLRP08 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP08_SHIFT           (8U)                                                /**< LPC_GPIO_PORT_CLR.CLRP08 Position       */
#define LPC_GPIO_PORT_CLR_CLRP08(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP08_SHIFT))&LPC_GPIO_PORT_CLR_CLRP08_MASK) /**< LPC_GPIO_PORT_CLR.CLRP08 Field          */
#define LPC_GPIO_PORT_CLR_CLRP09_MASK            (0x200U)                                            /**< LPC_GPIO_PORT_CLR.CLRP09 Mask           */
#define LPC_GPIO_PORT_CLR_CLRP09_SHIFT           (9U)                                                /**< LPC_GPIO_PORT_CLR.CLRP09 Position       */
#define LPC_GPIO_PORT_CLR_CLRP09(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP09_SHIFT))&LPC_GPIO_PORT_CLR_CLRP09_MASK) /**< LPC_GPIO_PORT_CLR.CLRP09 Field          */
#define LPC_GPIO_PORT_CLR_CLRP010_MASK           (0x400U)                                            /**< LPC_GPIO_PORT_CLR.CLRP010 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP010_SHIFT          (10U)                                               /**< LPC_GPIO_PORT_CLR.CLRP010 Position      */
#define LPC_GPIO_PORT_CLR_CLRP010(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP010_SHIFT))&LPC_GPIO_PORT_CLR_CLRP010_MASK) /**< LPC_GPIO_PORT_CLR.CLRP010 Field         */
#define LPC_GPIO_PORT_CLR_CLRP011_MASK           (0x800U)                                            /**< LPC_GPIO_PORT_CLR.CLRP011 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP011_SHIFT          (11U)                                               /**< LPC_GPIO_PORT_CLR.CLRP011 Position      */
#define LPC_GPIO_PORT_CLR_CLRP011(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP011_SHIFT))&LPC_GPIO_PORT_CLR_CLRP011_MASK) /**< LPC_GPIO_PORT_CLR.CLRP011 Field         */
#define LPC_GPIO_PORT_CLR_CLRP012_MASK           (0x1000U)                                           /**< LPC_GPIO_PORT_CLR.CLRP012 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP012_SHIFT          (12U)                                               /**< LPC_GPIO_PORT_CLR.CLRP012 Position      */
#define LPC_GPIO_PORT_CLR_CLRP012(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP012_SHIFT))&LPC_GPIO_PORT_CLR_CLRP012_MASK) /**< LPC_GPIO_PORT_CLR.CLRP012 Field         */
#define LPC_GPIO_PORT_CLR_CLRP013_MASK           (0x2000U)                                           /**< LPC_GPIO_PORT_CLR.CLRP013 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP013_SHIFT          (13U)                                               /**< LPC_GPIO_PORT_CLR.CLRP013 Position      */
#define LPC_GPIO_PORT_CLR_CLRP013(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP013_SHIFT))&LPC_GPIO_PORT_CLR_CLRP013_MASK) /**< LPC_GPIO_PORT_CLR.CLRP013 Field         */
#define LPC_GPIO_PORT_CLR_CLRP014_MASK           (0x4000U)                                           /**< LPC_GPIO_PORT_CLR.CLRP014 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP014_SHIFT          (14U)                                               /**< LPC_GPIO_PORT_CLR.CLRP014 Position      */
#define LPC_GPIO_PORT_CLR_CLRP014(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP014_SHIFT))&LPC_GPIO_PORT_CLR_CLRP014_MASK) /**< LPC_GPIO_PORT_CLR.CLRP014 Field         */
#define LPC_GPIO_PORT_CLR_CLRP015_MASK           (0x8000U)                                           /**< LPC_GPIO_PORT_CLR.CLRP015 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP015_SHIFT          (15U)                                               /**< LPC_GPIO_PORT_CLR.CLRP015 Position      */
#define LPC_GPIO_PORT_CLR_CLRP015(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP015_SHIFT))&LPC_GPIO_PORT_CLR_CLRP015_MASK) /**< LPC_GPIO_PORT_CLR.CLRP015 Field         */
#define LPC_GPIO_PORT_CLR_CLRP016_MASK           (0x10000U)                                          /**< LPC_GPIO_PORT_CLR.CLRP016 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP016_SHIFT          (16U)                                               /**< LPC_GPIO_PORT_CLR.CLRP016 Position      */
#define LPC_GPIO_PORT_CLR_CLRP016(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP016_SHIFT))&LPC_GPIO_PORT_CLR_CLRP016_MASK) /**< LPC_GPIO_PORT_CLR.CLRP016 Field         */
#define LPC_GPIO_PORT_CLR_CLRP017_MASK           (0x20000U)                                          /**< LPC_GPIO_PORT_CLR.CLRP017 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP017_SHIFT          (17U)                                               /**< LPC_GPIO_PORT_CLR.CLRP017 Position      */
#define LPC_GPIO_PORT_CLR_CLRP017(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP017_SHIFT))&LPC_GPIO_PORT_CLR_CLRP017_MASK) /**< LPC_GPIO_PORT_CLR.CLRP017 Field         */
#define LPC_GPIO_PORT_CLR_CLRP018_MASK           (0x40000U)                                          /**< LPC_GPIO_PORT_CLR.CLRP018 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP018_SHIFT          (18U)                                               /**< LPC_GPIO_PORT_CLR.CLRP018 Position      */
#define LPC_GPIO_PORT_CLR_CLRP018(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP018_SHIFT))&LPC_GPIO_PORT_CLR_CLRP018_MASK) /**< LPC_GPIO_PORT_CLR.CLRP018 Field         */
#define LPC_GPIO_PORT_CLR_CLRP019_MASK           (0x80000U)                                          /**< LPC_GPIO_PORT_CLR.CLRP019 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP019_SHIFT          (19U)                                               /**< LPC_GPIO_PORT_CLR.CLRP019 Position      */
#define LPC_GPIO_PORT_CLR_CLRP019(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP019_SHIFT))&LPC_GPIO_PORT_CLR_CLRP019_MASK) /**< LPC_GPIO_PORT_CLR.CLRP019 Field         */
#define LPC_GPIO_PORT_CLR_CLRP020_MASK           (0x100000U)                                         /**< LPC_GPIO_PORT_CLR.CLRP020 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP020_SHIFT          (20U)                                               /**< LPC_GPIO_PORT_CLR.CLRP020 Position      */
#define LPC_GPIO_PORT_CLR_CLRP020(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP020_SHIFT))&LPC_GPIO_PORT_CLR_CLRP020_MASK) /**< LPC_GPIO_PORT_CLR.CLRP020 Field         */
#define LPC_GPIO_PORT_CLR_CLRP021_MASK           (0x200000U)                                         /**< LPC_GPIO_PORT_CLR.CLRP021 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP021_SHIFT          (21U)                                               /**< LPC_GPIO_PORT_CLR.CLRP021 Position      */
#define LPC_GPIO_PORT_CLR_CLRP021(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP021_SHIFT))&LPC_GPIO_PORT_CLR_CLRP021_MASK) /**< LPC_GPIO_PORT_CLR.CLRP021 Field         */
#define LPC_GPIO_PORT_CLR_CLRP022_MASK           (0x400000U)                                         /**< LPC_GPIO_PORT_CLR.CLRP022 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP022_SHIFT          (22U)                                               /**< LPC_GPIO_PORT_CLR.CLRP022 Position      */
#define LPC_GPIO_PORT_CLR_CLRP022(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP022_SHIFT))&LPC_GPIO_PORT_CLR_CLRP022_MASK) /**< LPC_GPIO_PORT_CLR.CLRP022 Field         */
#define LPC_GPIO_PORT_CLR_CLRP023_MASK           (0x800000U)                                         /**< LPC_GPIO_PORT_CLR.CLRP023 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP023_SHIFT          (23U)                                               /**< LPC_GPIO_PORT_CLR.CLRP023 Position      */
#define LPC_GPIO_PORT_CLR_CLRP023(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP023_SHIFT))&LPC_GPIO_PORT_CLR_CLRP023_MASK) /**< LPC_GPIO_PORT_CLR.CLRP023 Field         */
#define LPC_GPIO_PORT_CLR_CLRP024_MASK           (0x1000000U)                                        /**< LPC_GPIO_PORT_CLR.CLRP024 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP024_SHIFT          (24U)                                               /**< LPC_GPIO_PORT_CLR.CLRP024 Position      */
#define LPC_GPIO_PORT_CLR_CLRP024(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP024_SHIFT))&LPC_GPIO_PORT_CLR_CLRP024_MASK) /**< LPC_GPIO_PORT_CLR.CLRP024 Field         */
#define LPC_GPIO_PORT_CLR_CLRP025_MASK           (0x2000000U)                                        /**< LPC_GPIO_PORT_CLR.CLRP025 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP025_SHIFT          (25U)                                               /**< LPC_GPIO_PORT_CLR.CLRP025 Position      */
#define LPC_GPIO_PORT_CLR_CLRP025(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP025_SHIFT))&LPC_GPIO_PORT_CLR_CLRP025_MASK) /**< LPC_GPIO_PORT_CLR.CLRP025 Field         */
#define LPC_GPIO_PORT_CLR_CLRP026_MASK           (0x4000000U)                                        /**< LPC_GPIO_PORT_CLR.CLRP026 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP026_SHIFT          (26U)                                               /**< LPC_GPIO_PORT_CLR.CLRP026 Position      */
#define LPC_GPIO_PORT_CLR_CLRP026(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP026_SHIFT))&LPC_GPIO_PORT_CLR_CLRP026_MASK) /**< LPC_GPIO_PORT_CLR.CLRP026 Field         */
#define LPC_GPIO_PORT_CLR_CLRP027_MASK           (0x8000000U)                                        /**< LPC_GPIO_PORT_CLR.CLRP027 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP027_SHIFT          (27U)                                               /**< LPC_GPIO_PORT_CLR.CLRP027 Position      */
#define LPC_GPIO_PORT_CLR_CLRP027(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP027_SHIFT))&LPC_GPIO_PORT_CLR_CLRP027_MASK) /**< LPC_GPIO_PORT_CLR.CLRP027 Field         */
#define LPC_GPIO_PORT_CLR_CLRP028_MASK           (0x10000000U)                                       /**< LPC_GPIO_PORT_CLR.CLRP028 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP028_SHIFT          (28U)                                               /**< LPC_GPIO_PORT_CLR.CLRP028 Position      */
#define LPC_GPIO_PORT_CLR_CLRP028(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP028_SHIFT))&LPC_GPIO_PORT_CLR_CLRP028_MASK) /**< LPC_GPIO_PORT_CLR.CLRP028 Field         */
#define LPC_GPIO_PORT_CLR_CLRP029_MASK           (0x20000000U)                                       /**< LPC_GPIO_PORT_CLR.CLRP029 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP029_SHIFT          (29U)                                               /**< LPC_GPIO_PORT_CLR.CLRP029 Position      */
#define LPC_GPIO_PORT_CLR_CLRP029(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP029_SHIFT))&LPC_GPIO_PORT_CLR_CLRP029_MASK) /**< LPC_GPIO_PORT_CLR.CLRP029 Field         */
#define LPC_GPIO_PORT_CLR_CLRP030_MASK           (0x40000000U)                                       /**< LPC_GPIO_PORT_CLR.CLRP030 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP030_SHIFT          (30U)                                               /**< LPC_GPIO_PORT_CLR.CLRP030 Position      */
#define LPC_GPIO_PORT_CLR_CLRP030(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP030_SHIFT))&LPC_GPIO_PORT_CLR_CLRP030_MASK) /**< LPC_GPIO_PORT_CLR.CLRP030 Field         */
#define LPC_GPIO_PORT_CLR_CLRP031_MASK           (0x80000000U)                                       /**< LPC_GPIO_PORT_CLR.CLRP031 Mask          */
#define LPC_GPIO_PORT_CLR_CLRP031_SHIFT          (31U)                                               /**< LPC_GPIO_PORT_CLR.CLRP031 Position      */
#define LPC_GPIO_PORT_CLR_CLRP031(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR_CLRP031_SHIFT))&LPC_GPIO_PORT_CLR_CLRP031_MASK) /**< LPC_GPIO_PORT_CLR.CLRP031 Field         */
/** @} */

/** @name NOT - Toggle port %s */ /** @{ */
#define LPC_GPIO_PORT_NOT_NOTP0_MASK             (0x1U)                                              /**< LPC_GPIO_PORT_NOT.NOTP0 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP0_SHIFT            (0U)                                                /**< LPC_GPIO_PORT_NOT.NOTP0 Position        */
#define LPC_GPIO_PORT_NOT_NOTP0(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP0_SHIFT))&LPC_GPIO_PORT_NOT_NOTP0_MASK) /**< LPC_GPIO_PORT_NOT.NOTP0 Field           */
#define LPC_GPIO_PORT_NOT_NOTP1_MASK             (0x2U)                                              /**< LPC_GPIO_PORT_NOT.NOTP1 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP1_SHIFT            (1U)                                                /**< LPC_GPIO_PORT_NOT.NOTP1 Position        */
#define LPC_GPIO_PORT_NOT_NOTP1(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP1_SHIFT))&LPC_GPIO_PORT_NOT_NOTP1_MASK) /**< LPC_GPIO_PORT_NOT.NOTP1 Field           */
#define LPC_GPIO_PORT_NOT_NOTP2_MASK             (0x4U)                                              /**< LPC_GPIO_PORT_NOT.NOTP2 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP2_SHIFT            (2U)                                                /**< LPC_GPIO_PORT_NOT.NOTP2 Position        */
#define LPC_GPIO_PORT_NOT_NOTP2(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP2_SHIFT))&LPC_GPIO_PORT_NOT_NOTP2_MASK) /**< LPC_GPIO_PORT_NOT.NOTP2 Field           */
#define LPC_GPIO_PORT_NOT_NOTP3_MASK             (0x8U)                                              /**< LPC_GPIO_PORT_NOT.NOTP3 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP3_SHIFT            (3U)                                                /**< LPC_GPIO_PORT_NOT.NOTP3 Position        */
#define LPC_GPIO_PORT_NOT_NOTP3(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP3_SHIFT))&LPC_GPIO_PORT_NOT_NOTP3_MASK) /**< LPC_GPIO_PORT_NOT.NOTP3 Field           */
#define LPC_GPIO_PORT_NOT_NOTP4_MASK             (0x10U)                                             /**< LPC_GPIO_PORT_NOT.NOTP4 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP4_SHIFT            (4U)                                                /**< LPC_GPIO_PORT_NOT.NOTP4 Position        */
#define LPC_GPIO_PORT_NOT_NOTP4(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP4_SHIFT))&LPC_GPIO_PORT_NOT_NOTP4_MASK) /**< LPC_GPIO_PORT_NOT.NOTP4 Field           */
#define LPC_GPIO_PORT_NOT_NOTP5_MASK             (0x20U)                                             /**< LPC_GPIO_PORT_NOT.NOTP5 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP5_SHIFT            (5U)                                                /**< LPC_GPIO_PORT_NOT.NOTP5 Position        */
#define LPC_GPIO_PORT_NOT_NOTP5(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP5_SHIFT))&LPC_GPIO_PORT_NOT_NOTP5_MASK) /**< LPC_GPIO_PORT_NOT.NOTP5 Field           */
#define LPC_GPIO_PORT_NOT_NOTP6_MASK             (0x40U)                                             /**< LPC_GPIO_PORT_NOT.NOTP6 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP6_SHIFT            (6U)                                                /**< LPC_GPIO_PORT_NOT.NOTP6 Position        */
#define LPC_GPIO_PORT_NOT_NOTP6(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP6_SHIFT))&LPC_GPIO_PORT_NOT_NOTP6_MASK) /**< LPC_GPIO_PORT_NOT.NOTP6 Field           */
#define LPC_GPIO_PORT_NOT_NOTP7_MASK             (0x80U)                                             /**< LPC_GPIO_PORT_NOT.NOTP7 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP7_SHIFT            (7U)                                                /**< LPC_GPIO_PORT_NOT.NOTP7 Position        */
#define LPC_GPIO_PORT_NOT_NOTP7(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP7_SHIFT))&LPC_GPIO_PORT_NOT_NOTP7_MASK) /**< LPC_GPIO_PORT_NOT.NOTP7 Field           */
#define LPC_GPIO_PORT_NOT_NOTP8_MASK             (0x100U)                                            /**< LPC_GPIO_PORT_NOT.NOTP8 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP8_SHIFT            (8U)                                                /**< LPC_GPIO_PORT_NOT.NOTP8 Position        */
#define LPC_GPIO_PORT_NOT_NOTP8(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP8_SHIFT))&LPC_GPIO_PORT_NOT_NOTP8_MASK) /**< LPC_GPIO_PORT_NOT.NOTP8 Field           */
#define LPC_GPIO_PORT_NOT_NOTP9_MASK             (0x200U)                                            /**< LPC_GPIO_PORT_NOT.NOTP9 Mask            */
#define LPC_GPIO_PORT_NOT_NOTP9_SHIFT            (9U)                                                /**< LPC_GPIO_PORT_NOT.NOTP9 Position        */
#define LPC_GPIO_PORT_NOT_NOTP9(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP9_SHIFT))&LPC_GPIO_PORT_NOT_NOTP9_MASK) /**< LPC_GPIO_PORT_NOT.NOTP9 Field           */
#define LPC_GPIO_PORT_NOT_NOTP10_MASK            (0x400U)                                            /**< LPC_GPIO_PORT_NOT.NOTP10 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP10_SHIFT           (10U)                                               /**< LPC_GPIO_PORT_NOT.NOTP10 Position       */
#define LPC_GPIO_PORT_NOT_NOTP10(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP10_SHIFT))&LPC_GPIO_PORT_NOT_NOTP10_MASK) /**< LPC_GPIO_PORT_NOT.NOTP10 Field          */
#define LPC_GPIO_PORT_NOT_NOTP11_MASK            (0x800U)                                            /**< LPC_GPIO_PORT_NOT.NOTP11 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP11_SHIFT           (11U)                                               /**< LPC_GPIO_PORT_NOT.NOTP11 Position       */
#define LPC_GPIO_PORT_NOT_NOTP11(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP11_SHIFT))&LPC_GPIO_PORT_NOT_NOTP11_MASK) /**< LPC_GPIO_PORT_NOT.NOTP11 Field          */
#define LPC_GPIO_PORT_NOT_NOTP12_MASK            (0x1000U)                                           /**< LPC_GPIO_PORT_NOT.NOTP12 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP12_SHIFT           (12U)                                               /**< LPC_GPIO_PORT_NOT.NOTP12 Position       */
#define LPC_GPIO_PORT_NOT_NOTP12(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP12_SHIFT))&LPC_GPIO_PORT_NOT_NOTP12_MASK) /**< LPC_GPIO_PORT_NOT.NOTP12 Field          */
#define LPC_GPIO_PORT_NOT_NOTP13_MASK            (0x2000U)                                           /**< LPC_GPIO_PORT_NOT.NOTP13 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP13_SHIFT           (13U)                                               /**< LPC_GPIO_PORT_NOT.NOTP13 Position       */
#define LPC_GPIO_PORT_NOT_NOTP13(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP13_SHIFT))&LPC_GPIO_PORT_NOT_NOTP13_MASK) /**< LPC_GPIO_PORT_NOT.NOTP13 Field          */
#define LPC_GPIO_PORT_NOT_NOTP14_MASK            (0x4000U)                                           /**< LPC_GPIO_PORT_NOT.NOTP14 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP14_SHIFT           (14U)                                               /**< LPC_GPIO_PORT_NOT.NOTP14 Position       */
#define LPC_GPIO_PORT_NOT_NOTP14(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP14_SHIFT))&LPC_GPIO_PORT_NOT_NOTP14_MASK) /**< LPC_GPIO_PORT_NOT.NOTP14 Field          */
#define LPC_GPIO_PORT_NOT_NOTP15_MASK            (0x8000U)                                           /**< LPC_GPIO_PORT_NOT.NOTP15 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP15_SHIFT           (15U)                                               /**< LPC_GPIO_PORT_NOT.NOTP15 Position       */
#define LPC_GPIO_PORT_NOT_NOTP15(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP15_SHIFT))&LPC_GPIO_PORT_NOT_NOTP15_MASK) /**< LPC_GPIO_PORT_NOT.NOTP15 Field          */
#define LPC_GPIO_PORT_NOT_NOTP16_MASK            (0x10000U)                                          /**< LPC_GPIO_PORT_NOT.NOTP16 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP16_SHIFT           (16U)                                               /**< LPC_GPIO_PORT_NOT.NOTP16 Position       */
#define LPC_GPIO_PORT_NOT_NOTP16(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP16_SHIFT))&LPC_GPIO_PORT_NOT_NOTP16_MASK) /**< LPC_GPIO_PORT_NOT.NOTP16 Field          */
#define LPC_GPIO_PORT_NOT_NOTP17_MASK            (0x20000U)                                          /**< LPC_GPIO_PORT_NOT.NOTP17 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP17_SHIFT           (17U)                                               /**< LPC_GPIO_PORT_NOT.NOTP17 Position       */
#define LPC_GPIO_PORT_NOT_NOTP17(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP17_SHIFT))&LPC_GPIO_PORT_NOT_NOTP17_MASK) /**< LPC_GPIO_PORT_NOT.NOTP17 Field          */
#define LPC_GPIO_PORT_NOT_NOTP18_MASK            (0x40000U)                                          /**< LPC_GPIO_PORT_NOT.NOTP18 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP18_SHIFT           (18U)                                               /**< LPC_GPIO_PORT_NOT.NOTP18 Position       */
#define LPC_GPIO_PORT_NOT_NOTP18(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP18_SHIFT))&LPC_GPIO_PORT_NOT_NOTP18_MASK) /**< LPC_GPIO_PORT_NOT.NOTP18 Field          */
#define LPC_GPIO_PORT_NOT_NOTP19_MASK            (0x80000U)                                          /**< LPC_GPIO_PORT_NOT.NOTP19 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP19_SHIFT           (19U)                                               /**< LPC_GPIO_PORT_NOT.NOTP19 Position       */
#define LPC_GPIO_PORT_NOT_NOTP19(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP19_SHIFT))&LPC_GPIO_PORT_NOT_NOTP19_MASK) /**< LPC_GPIO_PORT_NOT.NOTP19 Field          */
#define LPC_GPIO_PORT_NOT_NOTP20_MASK            (0x100000U)                                         /**< LPC_GPIO_PORT_NOT.NOTP20 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP20_SHIFT           (20U)                                               /**< LPC_GPIO_PORT_NOT.NOTP20 Position       */
#define LPC_GPIO_PORT_NOT_NOTP20(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP20_SHIFT))&LPC_GPIO_PORT_NOT_NOTP20_MASK) /**< LPC_GPIO_PORT_NOT.NOTP20 Field          */
#define LPC_GPIO_PORT_NOT_NOTP21_MASK            (0x200000U)                                         /**< LPC_GPIO_PORT_NOT.NOTP21 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP21_SHIFT           (21U)                                               /**< LPC_GPIO_PORT_NOT.NOTP21 Position       */
#define LPC_GPIO_PORT_NOT_NOTP21(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP21_SHIFT))&LPC_GPIO_PORT_NOT_NOTP21_MASK) /**< LPC_GPIO_PORT_NOT.NOTP21 Field          */
#define LPC_GPIO_PORT_NOT_NOTP22_MASK            (0x400000U)                                         /**< LPC_GPIO_PORT_NOT.NOTP22 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP22_SHIFT           (22U)                                               /**< LPC_GPIO_PORT_NOT.NOTP22 Position       */
#define LPC_GPIO_PORT_NOT_NOTP22(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP22_SHIFT))&LPC_GPIO_PORT_NOT_NOTP22_MASK) /**< LPC_GPIO_PORT_NOT.NOTP22 Field          */
#define LPC_GPIO_PORT_NOT_NOTP23_MASK            (0x800000U)                                         /**< LPC_GPIO_PORT_NOT.NOTP23 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP23_SHIFT           (23U)                                               /**< LPC_GPIO_PORT_NOT.NOTP23 Position       */
#define LPC_GPIO_PORT_NOT_NOTP23(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP23_SHIFT))&LPC_GPIO_PORT_NOT_NOTP23_MASK) /**< LPC_GPIO_PORT_NOT.NOTP23 Field          */
#define LPC_GPIO_PORT_NOT_NOTP24_MASK            (0x1000000U)                                        /**< LPC_GPIO_PORT_NOT.NOTP24 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP24_SHIFT           (24U)                                               /**< LPC_GPIO_PORT_NOT.NOTP24 Position       */
#define LPC_GPIO_PORT_NOT_NOTP24(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP24_SHIFT))&LPC_GPIO_PORT_NOT_NOTP24_MASK) /**< LPC_GPIO_PORT_NOT.NOTP24 Field          */
#define LPC_GPIO_PORT_NOT_NOTP25_MASK            (0x2000000U)                                        /**< LPC_GPIO_PORT_NOT.NOTP25 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP25_SHIFT           (25U)                                               /**< LPC_GPIO_PORT_NOT.NOTP25 Position       */
#define LPC_GPIO_PORT_NOT_NOTP25(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP25_SHIFT))&LPC_GPIO_PORT_NOT_NOTP25_MASK) /**< LPC_GPIO_PORT_NOT.NOTP25 Field          */
#define LPC_GPIO_PORT_NOT_NOTP26_MASK            (0x4000000U)                                        /**< LPC_GPIO_PORT_NOT.NOTP26 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP26_SHIFT           (26U)                                               /**< LPC_GPIO_PORT_NOT.NOTP26 Position       */
#define LPC_GPIO_PORT_NOT_NOTP26(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP26_SHIFT))&LPC_GPIO_PORT_NOT_NOTP26_MASK) /**< LPC_GPIO_PORT_NOT.NOTP26 Field          */
#define LPC_GPIO_PORT_NOT_NOTP27_MASK            (0x8000000U)                                        /**< LPC_GPIO_PORT_NOT.NOTP27 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP27_SHIFT           (27U)                                               /**< LPC_GPIO_PORT_NOT.NOTP27 Position       */
#define LPC_GPIO_PORT_NOT_NOTP27(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP27_SHIFT))&LPC_GPIO_PORT_NOT_NOTP27_MASK) /**< LPC_GPIO_PORT_NOT.NOTP27 Field          */
#define LPC_GPIO_PORT_NOT_NOTP28_MASK            (0x10000000U)                                       /**< LPC_GPIO_PORT_NOT.NOTP28 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP28_SHIFT           (28U)                                               /**< LPC_GPIO_PORT_NOT.NOTP28 Position       */
#define LPC_GPIO_PORT_NOT_NOTP28(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP28_SHIFT))&LPC_GPIO_PORT_NOT_NOTP28_MASK) /**< LPC_GPIO_PORT_NOT.NOTP28 Field          */
#define LPC_GPIO_PORT_NOT_NOTP29_MASK            (0x20000000U)                                       /**< LPC_GPIO_PORT_NOT.NOTP29 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP29_SHIFT           (29U)                                               /**< LPC_GPIO_PORT_NOT.NOTP29 Position       */
#define LPC_GPIO_PORT_NOT_NOTP29(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP29_SHIFT))&LPC_GPIO_PORT_NOT_NOTP29_MASK) /**< LPC_GPIO_PORT_NOT.NOTP29 Field          */
#define LPC_GPIO_PORT_NOT_NOTP30_MASK            (0x40000000U)                                       /**< LPC_GPIO_PORT_NOT.NOTP30 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP30_SHIFT           (30U)                                               /**< LPC_GPIO_PORT_NOT.NOTP30 Position       */
#define LPC_GPIO_PORT_NOT_NOTP30(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP30_SHIFT))&LPC_GPIO_PORT_NOT_NOTP30_MASK) /**< LPC_GPIO_PORT_NOT.NOTP30 Field          */
#define LPC_GPIO_PORT_NOT_NOTP31_MASK            (0x80000000U)                                       /**< LPC_GPIO_PORT_NOT.NOTP31 Mask           */
#define LPC_GPIO_PORT_NOT_NOTP31_SHIFT           (31U)                                               /**< LPC_GPIO_PORT_NOT.NOTP31 Position       */
#define LPC_GPIO_PORT_NOT_NOTP31(x)              (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT_NOTP31_SHIFT))&LPC_GPIO_PORT_NOT_NOTP31_MASK) /**< LPC_GPIO_PORT_NOT.NOTP31 Field          */
/** @} */

/** @} */ /* End group GPIO_PORT_Register_Masks_GROUP */


/* LPC_GPIO_PORT - Peripheral instance base addresses */
#define LPC_GPIO_PORT_BasePtr          0x50000000UL //!< Peripheral base address
#define LPC_GPIO_PORT                  ((LPC_GPIO_PORT_Type *) LPC_GPIO_PORT_BasePtr) //!< Freescale base pointer
#define LPC_GPIO_PORT_BASE_PTR         (LPC_GPIO_PORT) //!< Freescale style base pointer

/** @} */ /* End group GPIO_PORT_Peripheral_access_layer_GROUP */


/** @brief C Struct for I2C */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_I2C (file:I2C_LPC11Uxx)          ================ */
/* ================================================================================ */

/**
 * @brief I2C-bus controller
 */
/**
 * @struct LPC_I2C_Type
 * @brief  C Struct allowing access to I2C registers
 */
typedef struct LPC_I2C_Type {
   __IO uint32_t  CONSET;                       /**< 0000: I2C Control Set Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is set. Writing a zero has no effect on the corresponding bit in the I2C control register */
   __I  uint32_t  STAT;                         /**< 0004: I2C Status Register. During I2C operation, this register provides detailed status codes that allow software to determine the next action needed */
   __IO uint32_t  DAT;                          /**< 0008: I2C Data Register. During master or slave transmit mode, data to be transmitted is written to this register. During master or slave receive mode, data that has been received may be read from this register */
   __IO uint32_t  ADR0;                         /**< 000C: I2C Slave Address Register 0. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
   __IO uint32_t  SCLH;                         /**< 0010: SCH Duty Cycle Register High Half Word. Determines the high time of the I2C clock */
   __IO uint32_t  SCLL;                         /**< 0014: SCL Duty Cycle Register Low Half Word. Determines the low time of the I2C clock. I2nSCLL and I2nSCLH together determine the clock frequency generated by an I2C master and certain times used in slave mode */
   __O  uint32_t  CONCLR;                       /**< 0018: I2C Control Clear Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is cleared. Writing a zero has no effect on the corresponding bit in the I2C control register */
   __IO uint32_t  MMCTRL;                       /**< 001C: Monitor mode control register                                */
   __IO uint32_t  ADR1;                         /**< 0020: I2C Slave Address Register. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
   __IO uint32_t  ADR2;                         /**< 0024: I2C Slave Address Register. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
   __IO uint32_t  ADR3;                         /**< 0028: I2C Slave Address Register. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
   __I  uint32_t  DATA_BUFFER;                  /**< 002C: Data buffer register. The contents of the 8 MSBs of the I2DAT shift register will be transferred to the DATA_BUFFER automatically after every nine bits (8 bits of data plus ACK or NACK) has been received on the bus */
   __IO uint32_t  MASK[4];                      /**< 0030: I2C Slave address mask register. This mask register is associated with I2ADR to determine an address match. The mask register has no effect when comparing to the General Call address (zero) */
} LPC_I2C_Type;


/** @brief Register Masks for I2C */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_I2C' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup I2C_Register_Masks_GROUP I2C Register Masks */
/** @{ */

/** @name CONSET - I2C Control Set Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is set. Writing a zero has no effect on the corresponding bit in the I2C control register */ /** @{ */
#define LPC_I2C_CONSET_AA_MASK                   (0x4U)                                              /**< LPC_I2C_CONSET.AA Mask                  */
#define LPC_I2C_CONSET_AA_SHIFT                  (2U)                                                /**< LPC_I2C_CONSET.AA Position              */
#define LPC_I2C_CONSET_AA(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONSET_AA_SHIFT))&LPC_I2C_CONSET_AA_MASK) /**< LPC_I2C_CONSET.AA Field                 */
#define LPC_I2C_CONSET_SI_MASK                   (0x8U)                                              /**< LPC_I2C_CONSET.SI Mask                  */
#define LPC_I2C_CONSET_SI_SHIFT                  (3U)                                                /**< LPC_I2C_CONSET.SI Position              */
#define LPC_I2C_CONSET_SI(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONSET_SI_SHIFT))&LPC_I2C_CONSET_SI_MASK) /**< LPC_I2C_CONSET.SI Field                 */
#define LPC_I2C_CONSET_STO_MASK                  (0x10U)                                             /**< LPC_I2C_CONSET.STO Mask                 */
#define LPC_I2C_CONSET_STO_SHIFT                 (4U)                                                /**< LPC_I2C_CONSET.STO Position             */
#define LPC_I2C_CONSET_STO(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONSET_STO_SHIFT))&LPC_I2C_CONSET_STO_MASK) /**< LPC_I2C_CONSET.STO Field                */
#define LPC_I2C_CONSET_STA_MASK                  (0x20U)                                             /**< LPC_I2C_CONSET.STA Mask                 */
#define LPC_I2C_CONSET_STA_SHIFT                 (5U)                                                /**< LPC_I2C_CONSET.STA Position             */
#define LPC_I2C_CONSET_STA(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONSET_STA_SHIFT))&LPC_I2C_CONSET_STA_MASK) /**< LPC_I2C_CONSET.STA Field                */
#define LPC_I2C_CONSET_I2EN_MASK                 (0x40U)                                             /**< LPC_I2C_CONSET.I2EN Mask                */
#define LPC_I2C_CONSET_I2EN_SHIFT                (6U)                                                /**< LPC_I2C_CONSET.I2EN Position            */
#define LPC_I2C_CONSET_I2EN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONSET_I2EN_SHIFT))&LPC_I2C_CONSET_I2EN_MASK) /**< LPC_I2C_CONSET.I2EN Field               */
/** @} */

/** @name STAT - I2C Status Register. During I2C operation, this register provides detailed status codes that allow software to determine the next action needed */ /** @{ */
#define LPC_I2C_STAT_Status_MASK                 (0xF8U)                                             /**< LPC_I2C_STAT.Status Mask                */
#define LPC_I2C_STAT_Status_SHIFT                (3U)                                                /**< LPC_I2C_STAT.Status Position            */
#define LPC_I2C_STAT_Status(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_I2C_STAT_Status_SHIFT))&LPC_I2C_STAT_Status_MASK) /**< LPC_I2C_STAT.Status Field               */
/** @} */

/** @name DAT - I2C Data Register. During master or slave transmit mode, data to be transmitted is written to this register. During master or slave receive mode, data that has been received may be read from this register */ /** @{ */
#define LPC_I2C_DAT_Data_MASK                    (0xFFU)                                             /**< LPC_I2C_DAT.Data Mask                   */
#define LPC_I2C_DAT_Data_SHIFT                   (0U)                                                /**< LPC_I2C_DAT.Data Position               */
#define LPC_I2C_DAT_Data(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_I2C_DAT_Data_SHIFT))&LPC_I2C_DAT_Data_MASK) /**< LPC_I2C_DAT.Data Field                  */
/** @} */

/** @name ADR0 - I2C Slave Address Register 0. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */ /** @{ */
#define LPC_I2C_ADR0_GC_MASK                     (0x1U)                                              /**< LPC_I2C_ADR0.GC Mask                    */
#define LPC_I2C_ADR0_GC_SHIFT                    (0U)                                                /**< LPC_I2C_ADR0.GC Position                */
#define LPC_I2C_ADR0_GC(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_I2C_ADR0_GC_SHIFT))&LPC_I2C_ADR0_GC_MASK) /**< LPC_I2C_ADR0.GC Field                   */
#define LPC_I2C_ADR0_Address_MASK                (0xFEU)                                             /**< LPC_I2C_ADR0.Address Mask               */
#define LPC_I2C_ADR0_Address_SHIFT               (1U)                                                /**< LPC_I2C_ADR0.Address Position           */
#define LPC_I2C_ADR0_Address(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_I2C_ADR0_Address_SHIFT))&LPC_I2C_ADR0_Address_MASK) /**< LPC_I2C_ADR0.Address Field              */
/** @} */

/** @name SCLH - SCH Duty Cycle Register High Half Word. Determines the high time of the I2C clock */ /** @{ */
#define LPC_I2C_SCLH_SCLH_MASK                   (0xFFFFU)                                           /**< LPC_I2C_SCLH.SCLH Mask                  */
#define LPC_I2C_SCLH_SCLH_SHIFT                  (0U)                                                /**< LPC_I2C_SCLH.SCLH Position              */
#define LPC_I2C_SCLH_SCLH(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_I2C_SCLH_SCLH_SHIFT))&LPC_I2C_SCLH_SCLH_MASK) /**< LPC_I2C_SCLH.SCLH Field                 */
/** @} */

/** @name SCLL - SCL Duty Cycle Register Low Half Word. Determines the low time of the I2C clock. I2nSCLL and I2nSCLH together determine the clock frequency generated by an I2C master and certain times used in slave mode */ /** @{ */
#define LPC_I2C_SCLL_SCLL_MASK                   (0xFFFFU)                                           /**< LPC_I2C_SCLL.SCLL Mask                  */
#define LPC_I2C_SCLL_SCLL_SHIFT                  (0U)                                                /**< LPC_I2C_SCLL.SCLL Position              */
#define LPC_I2C_SCLL_SCLL(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_I2C_SCLL_SCLL_SHIFT))&LPC_I2C_SCLL_SCLL_MASK) /**< LPC_I2C_SCLL.SCLL Field                 */
/** @} */

/** @name CONCLR - I2C Control Clear Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is cleared. Writing a zero has no effect on the corresponding bit in the I2C control register */ /** @{ */
#define LPC_I2C_CONCLR_AAC_MASK                  (0x4U)                                              /**< LPC_I2C_CONCLR.AAC Mask                 */
#define LPC_I2C_CONCLR_AAC_SHIFT                 (2U)                                                /**< LPC_I2C_CONCLR.AAC Position             */
#define LPC_I2C_CONCLR_AAC(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONCLR_AAC_SHIFT))&LPC_I2C_CONCLR_AAC_MASK) /**< LPC_I2C_CONCLR.AAC Field                */
#define LPC_I2C_CONCLR_SIC_MASK                  (0x8U)                                              /**< LPC_I2C_CONCLR.SIC Mask                 */
#define LPC_I2C_CONCLR_SIC_SHIFT                 (3U)                                                /**< LPC_I2C_CONCLR.SIC Position             */
#define LPC_I2C_CONCLR_SIC(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONCLR_SIC_SHIFT))&LPC_I2C_CONCLR_SIC_MASK) /**< LPC_I2C_CONCLR.SIC Field                */
#define LPC_I2C_CONCLR_STAC_MASK                 (0x20U)                                             /**< LPC_I2C_CONCLR.STAC Mask                */
#define LPC_I2C_CONCLR_STAC_SHIFT                (5U)                                                /**< LPC_I2C_CONCLR.STAC Position            */
#define LPC_I2C_CONCLR_STAC(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONCLR_STAC_SHIFT))&LPC_I2C_CONCLR_STAC_MASK) /**< LPC_I2C_CONCLR.STAC Field               */
#define LPC_I2C_CONCLR_I2ENC_MASK                (0x40U)                                             /**< LPC_I2C_CONCLR.I2ENC Mask               */
#define LPC_I2C_CONCLR_I2ENC_SHIFT               (6U)                                                /**< LPC_I2C_CONCLR.I2ENC Position           */
#define LPC_I2C_CONCLR_I2ENC(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_I2C_CONCLR_I2ENC_SHIFT))&LPC_I2C_CONCLR_I2ENC_MASK) /**< LPC_I2C_CONCLR.I2ENC Field              */
/** @} */

/** @name MMCTRL - Monitor mode control register */ /** @{ */
#define LPC_I2C_MMCTRL_MM_ENA_MASK               (0x1U)                                              /**< LPC_I2C_MMCTRL.MM_ENA Mask              */
#define LPC_I2C_MMCTRL_MM_ENA_SHIFT              (0U)                                                /**< LPC_I2C_MMCTRL.MM_ENA Position          */
#define LPC_I2C_MMCTRL_MM_ENA(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_I2C_MMCTRL_MM_ENA_SHIFT))&LPC_I2C_MMCTRL_MM_ENA_MASK) /**< LPC_I2C_MMCTRL.MM_ENA Field             */
#define LPC_I2C_MMCTRL_ENA_SCL_MASK              (0x2U)                                              /**< LPC_I2C_MMCTRL.ENA_SCL Mask             */
#define LPC_I2C_MMCTRL_ENA_SCL_SHIFT             (1U)                                                /**< LPC_I2C_MMCTRL.ENA_SCL Position         */
#define LPC_I2C_MMCTRL_ENA_SCL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C_MMCTRL_ENA_SCL_SHIFT))&LPC_I2C_MMCTRL_ENA_SCL_MASK) /**< LPC_I2C_MMCTRL.ENA_SCL Field            */
#define LPC_I2C_MMCTRL_MATCH_ALL_MASK            (0x4U)                                              /**< LPC_I2C_MMCTRL.MATCH_ALL Mask           */
#define LPC_I2C_MMCTRL_MATCH_ALL_SHIFT           (2U)                                                /**< LPC_I2C_MMCTRL.MATCH_ALL Position       */
#define LPC_I2C_MMCTRL_MATCH_ALL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_I2C_MMCTRL_MATCH_ALL_SHIFT))&LPC_I2C_MMCTRL_MATCH_ALL_MASK) /**< LPC_I2C_MMCTRL.MATCH_ALL Field          */
/** @} */

/** @name ADR - I2C Slave Address Register. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */ /** @{ */
#define LPC_I2C_ADR_GC_MASK                      (0x1U)                                              /**< LPC_I2C_ADR.GC Mask                     */
#define LPC_I2C_ADR_GC_SHIFT                     (0U)                                                /**< LPC_I2C_ADR.GC Position                 */
#define LPC_I2C_ADR_GC(x)                        (((uint32_t)(((uint32_t)(x))<<LPC_I2C_ADR_GC_SHIFT))&LPC_I2C_ADR_GC_MASK) /**< LPC_I2C_ADR.GC Field                    */
#define LPC_I2C_ADR_Address_MASK                 (0xFEU)                                             /**< LPC_I2C_ADR.Address Mask                */
#define LPC_I2C_ADR_Address_SHIFT                (1U)                                                /**< LPC_I2C_ADR.Address Position            */
#define LPC_I2C_ADR_Address(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_I2C_ADR_Address_SHIFT))&LPC_I2C_ADR_Address_MASK) /**< LPC_I2C_ADR.Address Field               */
/** @} */

/** @name DATA_BUFFER - Data buffer register. The contents of the 8 MSBs of the I2DAT shift register will be transferred to the DATA_BUFFER automatically after every nine bits (8 bits of data plus ACK or NACK) has been received on the bus */ /** @{ */
#define LPC_I2C_DATA_BUFFER_Data_MASK            (0xFFU)                                             /**< LPC_I2C_DATA_BUFFER.Data Mask           */
#define LPC_I2C_DATA_BUFFER_Data_SHIFT           (0U)                                                /**< LPC_I2C_DATA_BUFFER.Data Position       */
#define LPC_I2C_DATA_BUFFER_Data(x)              (((uint32_t)(((uint32_t)(x))<<LPC_I2C_DATA_BUFFER_Data_SHIFT))&LPC_I2C_DATA_BUFFER_Data_MASK) /**< LPC_I2C_DATA_BUFFER.Data Field          */
/** @} */

/** @name MASK - I2C Slave address mask register. This mask register is associated with I2ADR%s to determine an address match. The mask register has no effect when comparing to the General Call address (zero) */ /** @{ */
#define LPC_I2C_MASK_MASK_MASK                   (0xFEU)                                             /**< LPC_I2C_MASK.MASK Mask                  */
#define LPC_I2C_MASK_MASK_SHIFT                  (1U)                                                /**< LPC_I2C_MASK.MASK Position              */
#define LPC_I2C_MASK_MASK(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_I2C_MASK_MASK_SHIFT))&LPC_I2C_MASK_MASK_MASK) /**< LPC_I2C_MASK.MASK Field                 */
/** @} */

/** @} */ /* End group I2C_Register_Masks_GROUP */


/* LPC_I2C - Peripheral instance base addresses */
#define LPC_I2C_BasePtr                0x40000000UL //!< Peripheral base address
#define LPC_I2C                        ((LPC_I2C_Type *) LPC_I2C_BasePtr) //!< Freescale base pointer
#define LPC_I2C_BASE_PTR               (LPC_I2C) //!< Freescale style base pointer

/** @} */ /* End group I2C_Peripheral_access_layer_GROUP */


/** @brief C Struct for IOCON */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup IOCON_Peripheral_access_layer_GROUP IOCON Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_IOCON (file:IOCON_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief I/O configuration Modification
 */
/**
 * @struct LPC_IOCON_Type
 * @brief  C Struct allowing access to IOCON registers
 */
typedef struct LPC_IOCON_Type {
   __IO uint32_t  RESET_PIO0_0;                 /**< 0000: I/O configuration for pin RESET/PIO0_0                       */
   __IO uint32_t  PIO0_1;                       /**< 0004: I/O configuration for pin PIO0_1/CLKOUT/CT32B0_MAT2/USB_FTOGGLE */
   __IO uint32_t  PIO0_2;                       /**< 0008: I/O configuration for pin PIO0_2/SSEL0/CT16B0_CAP0           */
   __IO uint32_t  PIO0_3;                       /**< 000C: I/O configuration for pin PIO0_3/USB_VBUS                    */
   __IO uint32_t  PIO0_4;                       /**< 0010: I/O configuration for pin PIO0_4/SCL                         */
   __IO uint32_t  PIO0_5;                       /**< 0014: I/O configuration for pin PIO0_5/SDA                         */
   __IO uint32_t  PIO0_6;                       /**< 0018: I/O configuration for pin PIO0_6/USB_CONNECT/SCK0            */
   __IO uint32_t  PIO0_7;                       /**< 001C: I/O configuration for pin PIO0_7/CTS                         */
   __IO uint32_t  PIO0_8;                       /**< 0020: I/O configuration for pin PIO0_8/MISO0/CT16B0_MAT0           */
   __IO uint32_t  PIO0_9;                       /**< 0024: I/O configuration for pin PIO0_9/MOSI0/CT16B0_MAT1           */
   __IO uint32_t  SWCLK_PIO0_10;                /**< 0028: I/O configuration for pin SWCLK/PIO0_10/ SCK0/CT16B0_MAT2    */
   __IO uint32_t  TDI_PIO0_11;                  /**< 002C: I/O configuration for pin TDI/PIO0_11/AD0/CT32B0_MAT3        */
   __IO uint32_t  TMS_PIO0_12;                  /**< 0030: I/O configuration for pin TMS/PIO0_12/AD1/CT32B1_CAP0        */
   __IO uint32_t  TDO_PIO0_13;                  /**< 0034: I/O configuration for pin TDO/PIO0_13/AD2/CT32B1_MAT0        */
   __IO uint32_t  TRST_PIO0_14;                 /**< 0038: I/O configuration for pin TRST/PIO0_14/AD3/CT32B1_MAT1       */
   __IO uint32_t  SWDIO_PIO0_15;                /**< 003C: I/O configuration for pin SWDIO/PIO0_15/AD4/CT32B1_MAT2      */
   __IO uint32_t  PIO0_16;                      /**< 0040: I/O configuration for pin PIO0_16/AD5/CT32B1_MAT3/ WAKEUP    */
   __IO uint32_t  PIO0_17;                      /**< 0044: I/O configuration for pin PIO0_17/RTS/CT32B0_CAP0/SCLK       */
   __IO uint32_t  PIO0_18;                      /**< 0048: I/O configuration for pin PIO0_18/RXD/CT32B0_MAT0            */
   __IO uint32_t  PIO0_19;                      /**< 004C: I/O configuration for pin PIO0_19/TXD/CT32B0_MAT1            */
   __IO uint32_t  PIO0_20;                      /**< 0050: I/O configuration for pin PIO0_20/CT16B1_CAP0                */
   __IO uint32_t  PIO0_21;                      /**< 0054: I/O configuration for pin PIO0_21/CT16B1_MAT0/MOSI1          */
   __IO uint32_t  PIO0_22;                      /**< 0058: I/O configuration for pin PIO0_22/AD6/CT16B1_MAT1/MISO1      */
   __IO uint32_t  PIO0_23;                      /**< 005C: I/O configuration for pin PIO0_23/AD7                        */
   __IO uint32_t  PIO1_0;                       /**< 0060: I/O configuration for pin PIO1_0/CT32B1_MAT0                 */
   __IO uint32_t  PIO1_1;                       /**< 0064: I/O configuration for pin PIO1_1/CT32B1_MAT1                 */
   __IO uint32_t  PIO1_2;                       /**< 0068: I/O configuration for pin PIO1_2/CT32B1_MAT2                 */
   __IO uint32_t  PIO1_3;                       /**< 006C: I/O configuration for pin PIO1_3/CT32B1_MAT3                 */
   __IO uint32_t  PIO1_4;                       /**< 0070: I/O configuration for pin PIO1_4/CT32B1_CAP0                 */
   __IO uint32_t  PIO1_5;                       /**< 0074: I/O configuration for pin PIO1_5/CT32B1_CAP1                 */
   __IO uint32_t  PIO1_6;                       /**< 0078: I/O configuration for pin PIO1_6                             */
   __IO uint32_t  PIO1_7;                       /**< 007C: I/O configuration for pin PIO1_7                             */
   __IO uint32_t  PIO1_8;                       /**< 0080: I/O configuration for pin PIO1_8                             */
   __IO uint32_t  PIO1_9;                       /**< 0084: I/O configuration for pin PIO1_9                             */
   __IO uint32_t  PIO1_10;                      /**< 0088: I/O configuration for pin PIO1_10                            */
   __IO uint32_t  PIO1_11;                      /**< 008C: I/O configuration for pin PIO1_11                            */
   __IO uint32_t  PIO1_12;                      /**< 0090: I/O configuration for pin PIO1_12                            */
   __IO uint32_t  PIO1_13;                      /**< 0094: I/O configuration for pin PIO1_13/DTR/CT16B0_MAT0/TXD        */
   __IO uint32_t  PIO1_14;                      /**< 0098: I/O configuration for pin PIO1_14/DSR/CT16B0_MAT1/RXD        */
   __IO uint32_t  PIO1_15;                      /**< 009C: I/O configuration for pin PIO1_15/DCD/  CT16B0_MAT2/SCK1     */
   __IO uint32_t  PIO1_16;                      /**< 00A0: I/O configuration for pin PIO1_16/RI/CT16B0_CAP0             */
   __IO uint32_t  PIO1_17;                      /**< 00A4: I/O configuration for PIO1_17/CT16B0_CAP1/RXD                */
   __IO uint32_t  PIO1_18;                      /**< 00A8: I/O configuration for PIO1_18/CT16B1_CAP1/TXD                */
   __IO uint32_t  PIO1_19;                      /**< 00AC: I/O configuration for pin PIO1_19/DTR/SSEL1                  */
   __IO uint32_t  PIO1_20;                      /**< 00B0: I/O configuration for pin PIO1_20/DSR/SCK1                   */
   __IO uint32_t  PIO1_21;                      /**< 00B4: I/O configuration for pin PIO1_21/DCD/MISO1                  */
   __IO uint32_t  PIO1_22;                      /**< 00B8: I/O configuration for pin PIO1_22/RI/MOSI1                   */
   __IO uint32_t  PIO1_23;                      /**< 00BC: I/O configuration for pin PIO1_23/CT16B1_MAT1/SSEL1          */
   __IO uint32_t  PIO1_24;                      /**< 00C0: I/O configuration for pin PIO1_24/ CT32B0_MAT0               */
   __IO uint32_t  PIO1_25;                      /**< 00C4: I/O configuration for pin PIO1_25/CT32B0_MAT1                */
   __IO uint32_t  PIO1_26;                      /**< 00C8: I/O configuration for pin PIO1_26/CT32B0_MAT2/ RXD           */
   __IO uint32_t  PIO1_27;                      /**< 00CC: I/O configuration for pin PIO1_27/CT32B0_MAT3/ TXD           */
   __IO uint32_t  PIO1_28;                      /**< 00D0: I/O configuration for pin PIO1_28/CT32B0_CAP0/ SCLK          */
   __IO uint32_t  PIO1_29;                      /**< 00D4: I/O configuration for pin PIO1_29/SCK0/ CT32B0_CAP1          */
        uint8_t   RESERVED_0[4];                /**< 00D8: 0x4 bytes                                                    */
   __IO uint32_t  PIO1_31;                      /**< 00DC: I/O configuration for pin PIO1_31                            */
} LPC_IOCON_Type;


/** @brief Register Masks for IOCON */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_IOCON' Position & Mask macros                   ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup IOCON_Register_Masks_GROUP IOCON Register Masks */
/** @{ */

/** @name RESET_PIO0_0 - I/O configuration for pin RESET/PIO0_0 */ /** @{ */
#define LPC_IOCON_RESET_PIO0_0_FUNC_MASK         (0x7U)                                              /**< LPC_IOCON_RESET_PIO0_0.FUNC Mask        */
#define LPC_IOCON_RESET_PIO0_0_FUNC_SHIFT        (0U)                                                /**< LPC_IOCON_RESET_PIO0_0.FUNC Position    */
#define LPC_IOCON_RESET_PIO0_0_FUNC(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_RESET_PIO0_0_FUNC_SHIFT))&LPC_IOCON_RESET_PIO0_0_FUNC_MASK) /**< LPC_IOCON_RESET_PIO0_0.FUNC Field       */
#define LPC_IOCON_RESET_PIO0_0_MODE_MASK         (0x18U)                                             /**< LPC_IOCON_RESET_PIO0_0.MODE Mask        */
#define LPC_IOCON_RESET_PIO0_0_MODE_SHIFT        (3U)                                                /**< LPC_IOCON_RESET_PIO0_0.MODE Position    */
#define LPC_IOCON_RESET_PIO0_0_MODE(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_RESET_PIO0_0_MODE_SHIFT))&LPC_IOCON_RESET_PIO0_0_MODE_MASK) /**< LPC_IOCON_RESET_PIO0_0.MODE Field       */
#define LPC_IOCON_RESET_PIO0_0_HYS_MASK          (0x20U)                                             /**< LPC_IOCON_RESET_PIO0_0.HYS Mask         */
#define LPC_IOCON_RESET_PIO0_0_HYS_SHIFT         (5U)                                                /**< LPC_IOCON_RESET_PIO0_0.HYS Position     */
#define LPC_IOCON_RESET_PIO0_0_HYS(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_RESET_PIO0_0_HYS_SHIFT))&LPC_IOCON_RESET_PIO0_0_HYS_MASK) /**< LPC_IOCON_RESET_PIO0_0.HYS Field        */
#define LPC_IOCON_RESET_PIO0_0_INV_MASK          (0x40U)                                             /**< LPC_IOCON_RESET_PIO0_0.INV Mask         */
#define LPC_IOCON_RESET_PIO0_0_INV_SHIFT         (6U)                                                /**< LPC_IOCON_RESET_PIO0_0.INV Position     */
#define LPC_IOCON_RESET_PIO0_0_INV(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_RESET_PIO0_0_INV_SHIFT))&LPC_IOCON_RESET_PIO0_0_INV_MASK) /**< LPC_IOCON_RESET_PIO0_0.INV Field        */
#define LPC_IOCON_RESET_PIO0_0_OD_MASK           (0x400U)                                            /**< LPC_IOCON_RESET_PIO0_0.OD Mask          */
#define LPC_IOCON_RESET_PIO0_0_OD_SHIFT          (10U)                                               /**< LPC_IOCON_RESET_PIO0_0.OD Position      */
#define LPC_IOCON_RESET_PIO0_0_OD(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_RESET_PIO0_0_OD_SHIFT))&LPC_IOCON_RESET_PIO0_0_OD_MASK) /**< LPC_IOCON_RESET_PIO0_0.OD Field         */
/** @} */

/** @name PIO0_1 - I/O configuration for pin PIO0_1/CLKOUT/CT32B0_MAT2/USB_FTOGGLE */ /** @{ */
#define LPC_IOCON_PIO0_1_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_1.FUNC Mask              */
#define LPC_IOCON_PIO0_1_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_1.FUNC Position          */
#define LPC_IOCON_PIO0_1_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_FUNC_SHIFT))&LPC_IOCON_PIO0_1_FUNC_MASK) /**< LPC_IOCON_PIO0_1.FUNC Field             */
#define LPC_IOCON_PIO0_1_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO0_1.MODE Mask              */
#define LPC_IOCON_PIO0_1_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO0_1.MODE Position          */
#define LPC_IOCON_PIO0_1_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_MODE_SHIFT))&LPC_IOCON_PIO0_1_MODE_MASK) /**< LPC_IOCON_PIO0_1.MODE Field             */
#define LPC_IOCON_PIO0_1_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO0_1.HYS Mask               */
#define LPC_IOCON_PIO0_1_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO0_1.HYS Position           */
#define LPC_IOCON_PIO0_1_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_HYS_SHIFT))&LPC_IOCON_PIO0_1_HYS_MASK) /**< LPC_IOCON_PIO0_1.HYS Field              */
#define LPC_IOCON_PIO0_1_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO0_1.INV Mask               */
#define LPC_IOCON_PIO0_1_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO0_1.INV Position           */
#define LPC_IOCON_PIO0_1_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_INV_SHIFT))&LPC_IOCON_PIO0_1_INV_MASK) /**< LPC_IOCON_PIO0_1.INV Field              */
#define LPC_IOCON_PIO0_1_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO0_1.OD Mask                */
#define LPC_IOCON_PIO0_1_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO0_1.OD Position            */
#define LPC_IOCON_PIO0_1_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_OD_SHIFT))&LPC_IOCON_PIO0_1_OD_MASK) /**< LPC_IOCON_PIO0_1.OD Field               */
/** @} */

/** @name PIO0_2 - I/O configuration for pin PIO0_2/SSEL0/CT16B0_CAP0 */ /** @{ */
#define LPC_IOCON_PIO0_2_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_2.FUNC Mask              */
#define LPC_IOCON_PIO0_2_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_2.FUNC Position          */
#define LPC_IOCON_PIO0_2_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_FUNC_SHIFT))&LPC_IOCON_PIO0_2_FUNC_MASK) /**< LPC_IOCON_PIO0_2.FUNC Field             */
#define LPC_IOCON_PIO0_2_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO0_2.MODE Mask              */
#define LPC_IOCON_PIO0_2_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO0_2.MODE Position          */
#define LPC_IOCON_PIO0_2_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_MODE_SHIFT))&LPC_IOCON_PIO0_2_MODE_MASK) /**< LPC_IOCON_PIO0_2.MODE Field             */
#define LPC_IOCON_PIO0_2_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO0_2.HYS Mask               */
#define LPC_IOCON_PIO0_2_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO0_2.HYS Position           */
#define LPC_IOCON_PIO0_2_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_HYS_SHIFT))&LPC_IOCON_PIO0_2_HYS_MASK) /**< LPC_IOCON_PIO0_2.HYS Field              */
#define LPC_IOCON_PIO0_2_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO0_2.INV Mask               */
#define LPC_IOCON_PIO0_2_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO0_2.INV Position           */
#define LPC_IOCON_PIO0_2_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_INV_SHIFT))&LPC_IOCON_PIO0_2_INV_MASK) /**< LPC_IOCON_PIO0_2.INV Field              */
#define LPC_IOCON_PIO0_2_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO0_2.OD Mask                */
#define LPC_IOCON_PIO0_2_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO0_2.OD Position            */
#define LPC_IOCON_PIO0_2_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_OD_SHIFT))&LPC_IOCON_PIO0_2_OD_MASK) /**< LPC_IOCON_PIO0_2.OD Field               */
/** @} */

/** @name PIO0_3 - I/O configuration for pin PIO0_3/USB_VBUS */ /** @{ */
#define LPC_IOCON_PIO0_3_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_3.FUNC Mask              */
#define LPC_IOCON_PIO0_3_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_3.FUNC Position          */
#define LPC_IOCON_PIO0_3_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_FUNC_SHIFT))&LPC_IOCON_PIO0_3_FUNC_MASK) /**< LPC_IOCON_PIO0_3.FUNC Field             */
#define LPC_IOCON_PIO0_3_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO0_3.MODE Mask              */
#define LPC_IOCON_PIO0_3_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO0_3.MODE Position          */
#define LPC_IOCON_PIO0_3_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_MODE_SHIFT))&LPC_IOCON_PIO0_3_MODE_MASK) /**< LPC_IOCON_PIO0_3.MODE Field             */
#define LPC_IOCON_PIO0_3_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO0_3.HYS Mask               */
#define LPC_IOCON_PIO0_3_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO0_3.HYS Position           */
#define LPC_IOCON_PIO0_3_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_HYS_SHIFT))&LPC_IOCON_PIO0_3_HYS_MASK) /**< LPC_IOCON_PIO0_3.HYS Field              */
#define LPC_IOCON_PIO0_3_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO0_3.INV Mask               */
#define LPC_IOCON_PIO0_3_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO0_3.INV Position           */
#define LPC_IOCON_PIO0_3_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_INV_SHIFT))&LPC_IOCON_PIO0_3_INV_MASK) /**< LPC_IOCON_PIO0_3.INV Field              */
#define LPC_IOCON_PIO0_3_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO0_3.OD Mask                */
#define LPC_IOCON_PIO0_3_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO0_3.OD Position            */
#define LPC_IOCON_PIO0_3_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_OD_SHIFT))&LPC_IOCON_PIO0_3_OD_MASK) /**< LPC_IOCON_PIO0_3.OD Field               */
/** @} */

/** @name PIO0_4 - I/O configuration for pin PIO0_4/SCL */ /** @{ */
#define LPC_IOCON_PIO0_4_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_4.FUNC Mask              */
#define LPC_IOCON_PIO0_4_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_4.FUNC Position          */
#define LPC_IOCON_PIO0_4_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_4_FUNC_SHIFT))&LPC_IOCON_PIO0_4_FUNC_MASK) /**< LPC_IOCON_PIO0_4.FUNC Field             */
#define LPC_IOCON_PIO0_4_I2CMODE_MASK            (0x300U)                                            /**< LPC_IOCON_PIO0_4.I2CMODE Mask           */
#define LPC_IOCON_PIO0_4_I2CMODE_SHIFT           (8U)                                                /**< LPC_IOCON_PIO0_4.I2CMODE Position       */
#define LPC_IOCON_PIO0_4_I2CMODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_4_I2CMODE_SHIFT))&LPC_IOCON_PIO0_4_I2CMODE_MASK) /**< LPC_IOCON_PIO0_4.I2CMODE Field          */
/** @} */

/** @name PIO0_5 - I/O configuration for pin PIO0_5/SDA */ /** @{ */
#define LPC_IOCON_PIO0_5_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_5.FUNC Mask              */
#define LPC_IOCON_PIO0_5_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_5.FUNC Position          */
#define LPC_IOCON_PIO0_5_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_5_FUNC_SHIFT))&LPC_IOCON_PIO0_5_FUNC_MASK) /**< LPC_IOCON_PIO0_5.FUNC Field             */
#define LPC_IOCON_PIO0_5_I2CMODE_MASK            (0x300U)                                            /**< LPC_IOCON_PIO0_5.I2CMODE Mask           */
#define LPC_IOCON_PIO0_5_I2CMODE_SHIFT           (8U)                                                /**< LPC_IOCON_PIO0_5.I2CMODE Position       */
#define LPC_IOCON_PIO0_5_I2CMODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_5_I2CMODE_SHIFT))&LPC_IOCON_PIO0_5_I2CMODE_MASK) /**< LPC_IOCON_PIO0_5.I2CMODE Field          */
/** @} */

/** @name PIO0_6 - I/O configuration for pin PIO0_6/USB_CONNECT/SCK0 */ /** @{ */
#define LPC_IOCON_PIO0_6_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_6.FUNC Mask              */
#define LPC_IOCON_PIO0_6_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_6.FUNC Position          */
#define LPC_IOCON_PIO0_6_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_FUNC_SHIFT))&LPC_IOCON_PIO0_6_FUNC_MASK) /**< LPC_IOCON_PIO0_6.FUNC Field             */
#define LPC_IOCON_PIO0_6_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO0_6.MODE Mask              */
#define LPC_IOCON_PIO0_6_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO0_6.MODE Position          */
#define LPC_IOCON_PIO0_6_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_MODE_SHIFT))&LPC_IOCON_PIO0_6_MODE_MASK) /**< LPC_IOCON_PIO0_6.MODE Field             */
#define LPC_IOCON_PIO0_6_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO0_6.HYS Mask               */
#define LPC_IOCON_PIO0_6_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO0_6.HYS Position           */
#define LPC_IOCON_PIO0_6_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_HYS_SHIFT))&LPC_IOCON_PIO0_6_HYS_MASK) /**< LPC_IOCON_PIO0_6.HYS Field              */
#define LPC_IOCON_PIO0_6_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO0_6.INV Mask               */
#define LPC_IOCON_PIO0_6_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO0_6.INV Position           */
#define LPC_IOCON_PIO0_6_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_INV_SHIFT))&LPC_IOCON_PIO0_6_INV_MASK) /**< LPC_IOCON_PIO0_6.INV Field              */
#define LPC_IOCON_PIO0_6_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO0_6.OD Mask                */
#define LPC_IOCON_PIO0_6_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO0_6.OD Position            */
#define LPC_IOCON_PIO0_6_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_OD_SHIFT))&LPC_IOCON_PIO0_6_OD_MASK) /**< LPC_IOCON_PIO0_6.OD Field               */
/** @} */

/** @name PIO0_7 - I/O configuration for pin PIO0_7/CTS */ /** @{ */
#define LPC_IOCON_PIO0_7_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_7.FUNC Mask              */
#define LPC_IOCON_PIO0_7_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_7.FUNC Position          */
#define LPC_IOCON_PIO0_7_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_FUNC_SHIFT))&LPC_IOCON_PIO0_7_FUNC_MASK) /**< LPC_IOCON_PIO0_7.FUNC Field             */
#define LPC_IOCON_PIO0_7_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO0_7.MODE Mask              */
#define LPC_IOCON_PIO0_7_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO0_7.MODE Position          */
#define LPC_IOCON_PIO0_7_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_MODE_SHIFT))&LPC_IOCON_PIO0_7_MODE_MASK) /**< LPC_IOCON_PIO0_7.MODE Field             */
#define LPC_IOCON_PIO0_7_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO0_7.HYS Mask               */
#define LPC_IOCON_PIO0_7_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO0_7.HYS Position           */
#define LPC_IOCON_PIO0_7_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_HYS_SHIFT))&LPC_IOCON_PIO0_7_HYS_MASK) /**< LPC_IOCON_PIO0_7.HYS Field              */
#define LPC_IOCON_PIO0_7_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO0_7.INV Mask               */
#define LPC_IOCON_PIO0_7_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO0_7.INV Position           */
#define LPC_IOCON_PIO0_7_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_INV_SHIFT))&LPC_IOCON_PIO0_7_INV_MASK) /**< LPC_IOCON_PIO0_7.INV Field              */
#define LPC_IOCON_PIO0_7_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO0_7.OD Mask                */
#define LPC_IOCON_PIO0_7_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO0_7.OD Position            */
#define LPC_IOCON_PIO0_7_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_OD_SHIFT))&LPC_IOCON_PIO0_7_OD_MASK) /**< LPC_IOCON_PIO0_7.OD Field               */
/** @} */

/** @name PIO0_8 - I/O configuration for pin PIO0_8/MISO0/CT16B0_MAT0 */ /** @{ */
#define LPC_IOCON_PIO0_8_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_8.FUNC Mask              */
#define LPC_IOCON_PIO0_8_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_8.FUNC Position          */
#define LPC_IOCON_PIO0_8_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_FUNC_SHIFT))&LPC_IOCON_PIO0_8_FUNC_MASK) /**< LPC_IOCON_PIO0_8.FUNC Field             */
#define LPC_IOCON_PIO0_8_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO0_8.MODE Mask              */
#define LPC_IOCON_PIO0_8_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO0_8.MODE Position          */
#define LPC_IOCON_PIO0_8_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_MODE_SHIFT))&LPC_IOCON_PIO0_8_MODE_MASK) /**< LPC_IOCON_PIO0_8.MODE Field             */
#define LPC_IOCON_PIO0_8_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO0_8.HYS Mask               */
#define LPC_IOCON_PIO0_8_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO0_8.HYS Position           */
#define LPC_IOCON_PIO0_8_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_HYS_SHIFT))&LPC_IOCON_PIO0_8_HYS_MASK) /**< LPC_IOCON_PIO0_8.HYS Field              */
#define LPC_IOCON_PIO0_8_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO0_8.INV Mask               */
#define LPC_IOCON_PIO0_8_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO0_8.INV Position           */
#define LPC_IOCON_PIO0_8_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_INV_SHIFT))&LPC_IOCON_PIO0_8_INV_MASK) /**< LPC_IOCON_PIO0_8.INV Field              */
#define LPC_IOCON_PIO0_8_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO0_8.OD Mask                */
#define LPC_IOCON_PIO0_8_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO0_8.OD Position            */
#define LPC_IOCON_PIO0_8_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_OD_SHIFT))&LPC_IOCON_PIO0_8_OD_MASK) /**< LPC_IOCON_PIO0_8.OD Field               */
/** @} */

/** @name PIO0_9 - I/O configuration for pin PIO0_9/MOSI0/CT16B0_MAT1 */ /** @{ */
#define LPC_IOCON_PIO0_9_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO0_9.FUNC Mask              */
#define LPC_IOCON_PIO0_9_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO0_9.FUNC Position          */
#define LPC_IOCON_PIO0_9_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_FUNC_SHIFT))&LPC_IOCON_PIO0_9_FUNC_MASK) /**< LPC_IOCON_PIO0_9.FUNC Field             */
#define LPC_IOCON_PIO0_9_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO0_9.MODE Mask              */
#define LPC_IOCON_PIO0_9_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO0_9.MODE Position          */
#define LPC_IOCON_PIO0_9_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_MODE_SHIFT))&LPC_IOCON_PIO0_9_MODE_MASK) /**< LPC_IOCON_PIO0_9.MODE Field             */
#define LPC_IOCON_PIO0_9_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO0_9.HYS Mask               */
#define LPC_IOCON_PIO0_9_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO0_9.HYS Position           */
#define LPC_IOCON_PIO0_9_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_HYS_SHIFT))&LPC_IOCON_PIO0_9_HYS_MASK) /**< LPC_IOCON_PIO0_9.HYS Field              */
#define LPC_IOCON_PIO0_9_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO0_9.INV Mask               */
#define LPC_IOCON_PIO0_9_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO0_9.INV Position           */
#define LPC_IOCON_PIO0_9_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_INV_SHIFT))&LPC_IOCON_PIO0_9_INV_MASK) /**< LPC_IOCON_PIO0_9.INV Field              */
#define LPC_IOCON_PIO0_9_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO0_9.OD Mask                */
#define LPC_IOCON_PIO0_9_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO0_9.OD Position            */
#define LPC_IOCON_PIO0_9_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_OD_SHIFT))&LPC_IOCON_PIO0_9_OD_MASK) /**< LPC_IOCON_PIO0_9.OD Field               */
/** @} */

/** @name SWCLK_PIO0_10 - I/O configuration for pin SWCLK/PIO0_10/ SCK0/CT16B0_MAT2 */ /** @{ */
#define LPC_IOCON_SWCLK_PIO0_10_FUNC_MASK        (0x7U)                                              /**< LPC_IOCON_SWCLK_PIO0_10.FUNC Mask       */
#define LPC_IOCON_SWCLK_PIO0_10_FUNC_SHIFT       (0U)                                                /**< LPC_IOCON_SWCLK_PIO0_10.FUNC Position   */
#define LPC_IOCON_SWCLK_PIO0_10_FUNC(x)          (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWCLK_PIO0_10_FUNC_SHIFT))&LPC_IOCON_SWCLK_PIO0_10_FUNC_MASK) /**< LPC_IOCON_SWCLK_PIO0_10.FUNC Field      */
#define LPC_IOCON_SWCLK_PIO0_10_MODE_MASK        (0x18U)                                             /**< LPC_IOCON_SWCLK_PIO0_10.MODE Mask       */
#define LPC_IOCON_SWCLK_PIO0_10_MODE_SHIFT       (3U)                                                /**< LPC_IOCON_SWCLK_PIO0_10.MODE Position   */
#define LPC_IOCON_SWCLK_PIO0_10_MODE(x)          (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWCLK_PIO0_10_MODE_SHIFT))&LPC_IOCON_SWCLK_PIO0_10_MODE_MASK) /**< LPC_IOCON_SWCLK_PIO0_10.MODE Field      */
#define LPC_IOCON_SWCLK_PIO0_10_HYS_MASK         (0x20U)                                             /**< LPC_IOCON_SWCLK_PIO0_10.HYS Mask        */
#define LPC_IOCON_SWCLK_PIO0_10_HYS_SHIFT        (5U)                                                /**< LPC_IOCON_SWCLK_PIO0_10.HYS Position    */
#define LPC_IOCON_SWCLK_PIO0_10_HYS(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWCLK_PIO0_10_HYS_SHIFT))&LPC_IOCON_SWCLK_PIO0_10_HYS_MASK) /**< LPC_IOCON_SWCLK_PIO0_10.HYS Field       */
#define LPC_IOCON_SWCLK_PIO0_10_INV_MASK         (0x40U)                                             /**< LPC_IOCON_SWCLK_PIO0_10.INV Mask        */
#define LPC_IOCON_SWCLK_PIO0_10_INV_SHIFT        (6U)                                                /**< LPC_IOCON_SWCLK_PIO0_10.INV Position    */
#define LPC_IOCON_SWCLK_PIO0_10_INV(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWCLK_PIO0_10_INV_SHIFT))&LPC_IOCON_SWCLK_PIO0_10_INV_MASK) /**< LPC_IOCON_SWCLK_PIO0_10.INV Field       */
#define LPC_IOCON_SWCLK_PIO0_10_OD_MASK          (0x400U)                                            /**< LPC_IOCON_SWCLK_PIO0_10.OD Mask         */
#define LPC_IOCON_SWCLK_PIO0_10_OD_SHIFT         (10U)                                               /**< LPC_IOCON_SWCLK_PIO0_10.OD Position     */
#define LPC_IOCON_SWCLK_PIO0_10_OD(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWCLK_PIO0_10_OD_SHIFT))&LPC_IOCON_SWCLK_PIO0_10_OD_MASK) /**< LPC_IOCON_SWCLK_PIO0_10.OD Field        */
/** @} */

/** @name TDI_PIO0_11 - I/O configuration for pin TDI/PIO0_11/AD0/CT32B0_MAT3 */ /** @{ */
#define LPC_IOCON_TDI_PIO0_11_FUNC_MASK          (0x7U)                                              /**< LPC_IOCON_TDI_PIO0_11.FUNC Mask         */
#define LPC_IOCON_TDI_PIO0_11_FUNC_SHIFT         (0U)                                                /**< LPC_IOCON_TDI_PIO0_11.FUNC Position     */
#define LPC_IOCON_TDI_PIO0_11_FUNC(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDI_PIO0_11_FUNC_SHIFT))&LPC_IOCON_TDI_PIO0_11_FUNC_MASK) /**< LPC_IOCON_TDI_PIO0_11.FUNC Field        */
#define LPC_IOCON_TDI_PIO0_11_MODE_MASK          (0x18U)                                             /**< LPC_IOCON_TDI_PIO0_11.MODE Mask         */
#define LPC_IOCON_TDI_PIO0_11_MODE_SHIFT         (3U)                                                /**< LPC_IOCON_TDI_PIO0_11.MODE Position     */
#define LPC_IOCON_TDI_PIO0_11_MODE(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDI_PIO0_11_MODE_SHIFT))&LPC_IOCON_TDI_PIO0_11_MODE_MASK) /**< LPC_IOCON_TDI_PIO0_11.MODE Field        */
#define LPC_IOCON_TDI_PIO0_11_HYS_MASK           (0x20U)                                             /**< LPC_IOCON_TDI_PIO0_11.HYS Mask          */
#define LPC_IOCON_TDI_PIO0_11_HYS_SHIFT          (5U)                                                /**< LPC_IOCON_TDI_PIO0_11.HYS Position      */
#define LPC_IOCON_TDI_PIO0_11_HYS(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDI_PIO0_11_HYS_SHIFT))&LPC_IOCON_TDI_PIO0_11_HYS_MASK) /**< LPC_IOCON_TDI_PIO0_11.HYS Field         */
#define LPC_IOCON_TDI_PIO0_11_INV_MASK           (0x40U)                                             /**< LPC_IOCON_TDI_PIO0_11.INV Mask          */
#define LPC_IOCON_TDI_PIO0_11_INV_SHIFT          (6U)                                                /**< LPC_IOCON_TDI_PIO0_11.INV Position      */
#define LPC_IOCON_TDI_PIO0_11_INV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDI_PIO0_11_INV_SHIFT))&LPC_IOCON_TDI_PIO0_11_INV_MASK) /**< LPC_IOCON_TDI_PIO0_11.INV Field         */
#define LPC_IOCON_TDI_PIO0_11_ADMODE_MASK        (0x80U)                                             /**< LPC_IOCON_TDI_PIO0_11.ADMODE Mask       */
#define LPC_IOCON_TDI_PIO0_11_ADMODE_SHIFT       (7U)                                                /**< LPC_IOCON_TDI_PIO0_11.ADMODE Position   */
#define LPC_IOCON_TDI_PIO0_11_ADMODE(x)          (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDI_PIO0_11_ADMODE_SHIFT))&LPC_IOCON_TDI_PIO0_11_ADMODE_MASK) /**< LPC_IOCON_TDI_PIO0_11.ADMODE Field      */
#define LPC_IOCON_TDI_PIO0_11_FILTR_MASK         (0x100U)                                            /**< LPC_IOCON_TDI_PIO0_11.FILTR Mask        */
#define LPC_IOCON_TDI_PIO0_11_FILTR_SHIFT        (8U)                                                /**< LPC_IOCON_TDI_PIO0_11.FILTR Position    */
#define LPC_IOCON_TDI_PIO0_11_FILTR(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDI_PIO0_11_FILTR_SHIFT))&LPC_IOCON_TDI_PIO0_11_FILTR_MASK) /**< LPC_IOCON_TDI_PIO0_11.FILTR Field       */
#define LPC_IOCON_TDI_PIO0_11_OD_MASK            (0x400U)                                            /**< LPC_IOCON_TDI_PIO0_11.OD Mask           */
#define LPC_IOCON_TDI_PIO0_11_OD_SHIFT           (10U)                                               /**< LPC_IOCON_TDI_PIO0_11.OD Position       */
#define LPC_IOCON_TDI_PIO0_11_OD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDI_PIO0_11_OD_SHIFT))&LPC_IOCON_TDI_PIO0_11_OD_MASK) /**< LPC_IOCON_TDI_PIO0_11.OD Field          */
/** @} */

/** @name TMS_PIO0_12 - I/O configuration for pin TMS/PIO0_12/AD1/CT32B1_CAP0 */ /** @{ */
#define LPC_IOCON_TMS_PIO0_12_FUNC_MASK          (0x7U)                                              /**< LPC_IOCON_TMS_PIO0_12.FUNC Mask         */
#define LPC_IOCON_TMS_PIO0_12_FUNC_SHIFT         (0U)                                                /**< LPC_IOCON_TMS_PIO0_12.FUNC Position     */
#define LPC_IOCON_TMS_PIO0_12_FUNC(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TMS_PIO0_12_FUNC_SHIFT))&LPC_IOCON_TMS_PIO0_12_FUNC_MASK) /**< LPC_IOCON_TMS_PIO0_12.FUNC Field        */
#define LPC_IOCON_TMS_PIO0_12_MODE_MASK          (0x18U)                                             /**< LPC_IOCON_TMS_PIO0_12.MODE Mask         */
#define LPC_IOCON_TMS_PIO0_12_MODE_SHIFT         (3U)                                                /**< LPC_IOCON_TMS_PIO0_12.MODE Position     */
#define LPC_IOCON_TMS_PIO0_12_MODE(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TMS_PIO0_12_MODE_SHIFT))&LPC_IOCON_TMS_PIO0_12_MODE_MASK) /**< LPC_IOCON_TMS_PIO0_12.MODE Field        */
#define LPC_IOCON_TMS_PIO0_12_HYS_MASK           (0x20U)                                             /**< LPC_IOCON_TMS_PIO0_12.HYS Mask          */
#define LPC_IOCON_TMS_PIO0_12_HYS_SHIFT          (5U)                                                /**< LPC_IOCON_TMS_PIO0_12.HYS Position      */
#define LPC_IOCON_TMS_PIO0_12_HYS(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TMS_PIO0_12_HYS_SHIFT))&LPC_IOCON_TMS_PIO0_12_HYS_MASK) /**< LPC_IOCON_TMS_PIO0_12.HYS Field         */
#define LPC_IOCON_TMS_PIO0_12_INV_MASK           (0x40U)                                             /**< LPC_IOCON_TMS_PIO0_12.INV Mask          */
#define LPC_IOCON_TMS_PIO0_12_INV_SHIFT          (6U)                                                /**< LPC_IOCON_TMS_PIO0_12.INV Position      */
#define LPC_IOCON_TMS_PIO0_12_INV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TMS_PIO0_12_INV_SHIFT))&LPC_IOCON_TMS_PIO0_12_INV_MASK) /**< LPC_IOCON_TMS_PIO0_12.INV Field         */
#define LPC_IOCON_TMS_PIO0_12_ADMODE_MASK        (0x80U)                                             /**< LPC_IOCON_TMS_PIO0_12.ADMODE Mask       */
#define LPC_IOCON_TMS_PIO0_12_ADMODE_SHIFT       (7U)                                                /**< LPC_IOCON_TMS_PIO0_12.ADMODE Position   */
#define LPC_IOCON_TMS_PIO0_12_ADMODE(x)          (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TMS_PIO0_12_ADMODE_SHIFT))&LPC_IOCON_TMS_PIO0_12_ADMODE_MASK) /**< LPC_IOCON_TMS_PIO0_12.ADMODE Field      */
#define LPC_IOCON_TMS_PIO0_12_FILTR_MASK         (0x100U)                                            /**< LPC_IOCON_TMS_PIO0_12.FILTR Mask        */
#define LPC_IOCON_TMS_PIO0_12_FILTR_SHIFT        (8U)                                                /**< LPC_IOCON_TMS_PIO0_12.FILTR Position    */
#define LPC_IOCON_TMS_PIO0_12_FILTR(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TMS_PIO0_12_FILTR_SHIFT))&LPC_IOCON_TMS_PIO0_12_FILTR_MASK) /**< LPC_IOCON_TMS_PIO0_12.FILTR Field       */
#define LPC_IOCON_TMS_PIO0_12_OD_MASK            (0x400U)                                            /**< LPC_IOCON_TMS_PIO0_12.OD Mask           */
#define LPC_IOCON_TMS_PIO0_12_OD_SHIFT           (10U)                                               /**< LPC_IOCON_TMS_PIO0_12.OD Position       */
#define LPC_IOCON_TMS_PIO0_12_OD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TMS_PIO0_12_OD_SHIFT))&LPC_IOCON_TMS_PIO0_12_OD_MASK) /**< LPC_IOCON_TMS_PIO0_12.OD Field          */
/** @} */

/** @name TDO_PIO0_13 - I/O configuration for pin TDO/PIO0_13/AD2/CT32B1_MAT0 */ /** @{ */
#define LPC_IOCON_TDO_PIO0_13_FUNC_MASK          (0x7U)                                              /**< LPC_IOCON_TDO_PIO0_13.FUNC Mask         */
#define LPC_IOCON_TDO_PIO0_13_FUNC_SHIFT         (0U)                                                /**< LPC_IOCON_TDO_PIO0_13.FUNC Position     */
#define LPC_IOCON_TDO_PIO0_13_FUNC(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDO_PIO0_13_FUNC_SHIFT))&LPC_IOCON_TDO_PIO0_13_FUNC_MASK) /**< LPC_IOCON_TDO_PIO0_13.FUNC Field        */
#define LPC_IOCON_TDO_PIO0_13_MODE_MASK          (0x18U)                                             /**< LPC_IOCON_TDO_PIO0_13.MODE Mask         */
#define LPC_IOCON_TDO_PIO0_13_MODE_SHIFT         (3U)                                                /**< LPC_IOCON_TDO_PIO0_13.MODE Position     */
#define LPC_IOCON_TDO_PIO0_13_MODE(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDO_PIO0_13_MODE_SHIFT))&LPC_IOCON_TDO_PIO0_13_MODE_MASK) /**< LPC_IOCON_TDO_PIO0_13.MODE Field        */
#define LPC_IOCON_TDO_PIO0_13_HYS_MASK           (0x20U)                                             /**< LPC_IOCON_TDO_PIO0_13.HYS Mask          */
#define LPC_IOCON_TDO_PIO0_13_HYS_SHIFT          (5U)                                                /**< LPC_IOCON_TDO_PIO0_13.HYS Position      */
#define LPC_IOCON_TDO_PIO0_13_HYS(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDO_PIO0_13_HYS_SHIFT))&LPC_IOCON_TDO_PIO0_13_HYS_MASK) /**< LPC_IOCON_TDO_PIO0_13.HYS Field         */
#define LPC_IOCON_TDO_PIO0_13_INV_MASK           (0x40U)                                             /**< LPC_IOCON_TDO_PIO0_13.INV Mask          */
#define LPC_IOCON_TDO_PIO0_13_INV_SHIFT          (6U)                                                /**< LPC_IOCON_TDO_PIO0_13.INV Position      */
#define LPC_IOCON_TDO_PIO0_13_INV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDO_PIO0_13_INV_SHIFT))&LPC_IOCON_TDO_PIO0_13_INV_MASK) /**< LPC_IOCON_TDO_PIO0_13.INV Field         */
#define LPC_IOCON_TDO_PIO0_13_ADMODE_MASK        (0x80U)                                             /**< LPC_IOCON_TDO_PIO0_13.ADMODE Mask       */
#define LPC_IOCON_TDO_PIO0_13_ADMODE_SHIFT       (7U)                                                /**< LPC_IOCON_TDO_PIO0_13.ADMODE Position   */
#define LPC_IOCON_TDO_PIO0_13_ADMODE(x)          (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDO_PIO0_13_ADMODE_SHIFT))&LPC_IOCON_TDO_PIO0_13_ADMODE_MASK) /**< LPC_IOCON_TDO_PIO0_13.ADMODE Field      */
#define LPC_IOCON_TDO_PIO0_13_FILTR_MASK         (0x100U)                                            /**< LPC_IOCON_TDO_PIO0_13.FILTR Mask        */
#define LPC_IOCON_TDO_PIO0_13_FILTR_SHIFT        (8U)                                                /**< LPC_IOCON_TDO_PIO0_13.FILTR Position    */
#define LPC_IOCON_TDO_PIO0_13_FILTR(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDO_PIO0_13_FILTR_SHIFT))&LPC_IOCON_TDO_PIO0_13_FILTR_MASK) /**< LPC_IOCON_TDO_PIO0_13.FILTR Field       */
#define LPC_IOCON_TDO_PIO0_13_OD_MASK            (0x400U)                                            /**< LPC_IOCON_TDO_PIO0_13.OD Mask           */
#define LPC_IOCON_TDO_PIO0_13_OD_SHIFT           (10U)                                               /**< LPC_IOCON_TDO_PIO0_13.OD Position       */
#define LPC_IOCON_TDO_PIO0_13_OD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TDO_PIO0_13_OD_SHIFT))&LPC_IOCON_TDO_PIO0_13_OD_MASK) /**< LPC_IOCON_TDO_PIO0_13.OD Field          */
/** @} */

/** @name TRST_PIO0_14 - I/O configuration for pin TRST/PIO0_14/AD3/CT32B1_MAT1 */ /** @{ */
#define LPC_IOCON_TRST_PIO0_14_FUNC_MASK         (0x7U)                                              /**< LPC_IOCON_TRST_PIO0_14.FUNC Mask        */
#define LPC_IOCON_TRST_PIO0_14_FUNC_SHIFT        (0U)                                                /**< LPC_IOCON_TRST_PIO0_14.FUNC Position    */
#define LPC_IOCON_TRST_PIO0_14_FUNC(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TRST_PIO0_14_FUNC_SHIFT))&LPC_IOCON_TRST_PIO0_14_FUNC_MASK) /**< LPC_IOCON_TRST_PIO0_14.FUNC Field       */
#define LPC_IOCON_TRST_PIO0_14_MODE_MASK         (0x18U)                                             /**< LPC_IOCON_TRST_PIO0_14.MODE Mask        */
#define LPC_IOCON_TRST_PIO0_14_MODE_SHIFT        (3U)                                                /**< LPC_IOCON_TRST_PIO0_14.MODE Position    */
#define LPC_IOCON_TRST_PIO0_14_MODE(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TRST_PIO0_14_MODE_SHIFT))&LPC_IOCON_TRST_PIO0_14_MODE_MASK) /**< LPC_IOCON_TRST_PIO0_14.MODE Field       */
#define LPC_IOCON_TRST_PIO0_14_HYS_MASK          (0x20U)                                             /**< LPC_IOCON_TRST_PIO0_14.HYS Mask         */
#define LPC_IOCON_TRST_PIO0_14_HYS_SHIFT         (5U)                                                /**< LPC_IOCON_TRST_PIO0_14.HYS Position     */
#define LPC_IOCON_TRST_PIO0_14_HYS(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TRST_PIO0_14_HYS_SHIFT))&LPC_IOCON_TRST_PIO0_14_HYS_MASK) /**< LPC_IOCON_TRST_PIO0_14.HYS Field        */
#define LPC_IOCON_TRST_PIO0_14_INV_MASK          (0x40U)                                             /**< LPC_IOCON_TRST_PIO0_14.INV Mask         */
#define LPC_IOCON_TRST_PIO0_14_INV_SHIFT         (6U)                                                /**< LPC_IOCON_TRST_PIO0_14.INV Position     */
#define LPC_IOCON_TRST_PIO0_14_INV(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TRST_PIO0_14_INV_SHIFT))&LPC_IOCON_TRST_PIO0_14_INV_MASK) /**< LPC_IOCON_TRST_PIO0_14.INV Field        */
#define LPC_IOCON_TRST_PIO0_14_ADMODE_MASK       (0x80U)                                             /**< LPC_IOCON_TRST_PIO0_14.ADMODE Mask      */
#define LPC_IOCON_TRST_PIO0_14_ADMODE_SHIFT      (7U)                                                /**< LPC_IOCON_TRST_PIO0_14.ADMODE Position  */
#define LPC_IOCON_TRST_PIO0_14_ADMODE(x)         (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TRST_PIO0_14_ADMODE_SHIFT))&LPC_IOCON_TRST_PIO0_14_ADMODE_MASK) /**< LPC_IOCON_TRST_PIO0_14.ADMODE Field     */
#define LPC_IOCON_TRST_PIO0_14_FILTR_MASK        (0x100U)                                            /**< LPC_IOCON_TRST_PIO0_14.FILTR Mask       */
#define LPC_IOCON_TRST_PIO0_14_FILTR_SHIFT       (8U)                                                /**< LPC_IOCON_TRST_PIO0_14.FILTR Position   */
#define LPC_IOCON_TRST_PIO0_14_FILTR(x)          (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TRST_PIO0_14_FILTR_SHIFT))&LPC_IOCON_TRST_PIO0_14_FILTR_MASK) /**< LPC_IOCON_TRST_PIO0_14.FILTR Field      */
#define LPC_IOCON_TRST_PIO0_14_OD_MASK           (0x400U)                                            /**< LPC_IOCON_TRST_PIO0_14.OD Mask          */
#define LPC_IOCON_TRST_PIO0_14_OD_SHIFT          (10U)                                               /**< LPC_IOCON_TRST_PIO0_14.OD Position      */
#define LPC_IOCON_TRST_PIO0_14_OD(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_TRST_PIO0_14_OD_SHIFT))&LPC_IOCON_TRST_PIO0_14_OD_MASK) /**< LPC_IOCON_TRST_PIO0_14.OD Field         */
/** @} */

/** @name SWDIO_PIO0_15 - I/O configuration for pin SWDIO/PIO0_15/AD4/CT32B1_MAT2 */ /** @{ */
#define LPC_IOCON_SWDIO_PIO0_15_FUNC_MASK        (0x7U)                                              /**< LPC_IOCON_SWDIO_PIO0_15.FUNC Mask       */
#define LPC_IOCON_SWDIO_PIO0_15_FUNC_SHIFT       (0U)                                                /**< LPC_IOCON_SWDIO_PIO0_15.FUNC Position   */
#define LPC_IOCON_SWDIO_PIO0_15_FUNC(x)          (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWDIO_PIO0_15_FUNC_SHIFT))&LPC_IOCON_SWDIO_PIO0_15_FUNC_MASK) /**< LPC_IOCON_SWDIO_PIO0_15.FUNC Field      */
#define LPC_IOCON_SWDIO_PIO0_15_MODE_MASK        (0x18U)                                             /**< LPC_IOCON_SWDIO_PIO0_15.MODE Mask       */
#define LPC_IOCON_SWDIO_PIO0_15_MODE_SHIFT       (3U)                                                /**< LPC_IOCON_SWDIO_PIO0_15.MODE Position   */
#define LPC_IOCON_SWDIO_PIO0_15_MODE(x)          (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWDIO_PIO0_15_MODE_SHIFT))&LPC_IOCON_SWDIO_PIO0_15_MODE_MASK) /**< LPC_IOCON_SWDIO_PIO0_15.MODE Field      */
#define LPC_IOCON_SWDIO_PIO0_15_HYS_MASK         (0x20U)                                             /**< LPC_IOCON_SWDIO_PIO0_15.HYS Mask        */
#define LPC_IOCON_SWDIO_PIO0_15_HYS_SHIFT        (5U)                                                /**< LPC_IOCON_SWDIO_PIO0_15.HYS Position    */
#define LPC_IOCON_SWDIO_PIO0_15_HYS(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWDIO_PIO0_15_HYS_SHIFT))&LPC_IOCON_SWDIO_PIO0_15_HYS_MASK) /**< LPC_IOCON_SWDIO_PIO0_15.HYS Field       */
#define LPC_IOCON_SWDIO_PIO0_15_INV_MASK         (0x40U)                                             /**< LPC_IOCON_SWDIO_PIO0_15.INV Mask        */
#define LPC_IOCON_SWDIO_PIO0_15_INV_SHIFT        (6U)                                                /**< LPC_IOCON_SWDIO_PIO0_15.INV Position    */
#define LPC_IOCON_SWDIO_PIO0_15_INV(x)           (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWDIO_PIO0_15_INV_SHIFT))&LPC_IOCON_SWDIO_PIO0_15_INV_MASK) /**< LPC_IOCON_SWDIO_PIO0_15.INV Field       */
#define LPC_IOCON_SWDIO_PIO0_15_ADMODE_MASK      (0x80U)                                             /**< LPC_IOCON_SWDIO_PIO0_15.ADMODE Mask     */
#define LPC_IOCON_SWDIO_PIO0_15_ADMODE_SHIFT     (7U)                                                /**< LPC_IOCON_SWDIO_PIO0_15.ADMODE Position */
#define LPC_IOCON_SWDIO_PIO0_15_ADMODE(x)        (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWDIO_PIO0_15_ADMODE_SHIFT))&LPC_IOCON_SWDIO_PIO0_15_ADMODE_MASK) /**< LPC_IOCON_SWDIO_PIO0_15.ADMODE Field    */
#define LPC_IOCON_SWDIO_PIO0_15_FILTR_MASK       (0x100U)                                            /**< LPC_IOCON_SWDIO_PIO0_15.FILTR Mask      */
#define LPC_IOCON_SWDIO_PIO0_15_FILTR_SHIFT      (8U)                                                /**< LPC_IOCON_SWDIO_PIO0_15.FILTR Position  */
#define LPC_IOCON_SWDIO_PIO0_15_FILTR(x)         (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWDIO_PIO0_15_FILTR_SHIFT))&LPC_IOCON_SWDIO_PIO0_15_FILTR_MASK) /**< LPC_IOCON_SWDIO_PIO0_15.FILTR Field     */
#define LPC_IOCON_SWDIO_PIO0_15_OD_MASK          (0x400U)                                            /**< LPC_IOCON_SWDIO_PIO0_15.OD Mask         */
#define LPC_IOCON_SWDIO_PIO0_15_OD_SHIFT         (10U)                                               /**< LPC_IOCON_SWDIO_PIO0_15.OD Position     */
#define LPC_IOCON_SWDIO_PIO0_15_OD(x)            (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_SWDIO_PIO0_15_OD_SHIFT))&LPC_IOCON_SWDIO_PIO0_15_OD_MASK) /**< LPC_IOCON_SWDIO_PIO0_15.OD Field        */
/** @} */

/** @name PIO0_16 - I/O configuration for pin PIO0_16/AD5/CT32B1_MAT3/ WAKEUP */ /** @{ */
#define LPC_IOCON_PIO0_16_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO0_16.FUNC Mask             */
#define LPC_IOCON_PIO0_16_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO0_16.FUNC Position         */
#define LPC_IOCON_PIO0_16_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_16_FUNC_SHIFT))&LPC_IOCON_PIO0_16_FUNC_MASK) /**< LPC_IOCON_PIO0_16.FUNC Field            */
#define LPC_IOCON_PIO0_16_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO0_16.MODE Mask             */
#define LPC_IOCON_PIO0_16_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO0_16.MODE Position         */
#define LPC_IOCON_PIO0_16_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_16_MODE_SHIFT))&LPC_IOCON_PIO0_16_MODE_MASK) /**< LPC_IOCON_PIO0_16.MODE Field            */
#define LPC_IOCON_PIO0_16_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO0_16.HYS Mask              */
#define LPC_IOCON_PIO0_16_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO0_16.HYS Position          */
#define LPC_IOCON_PIO0_16_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_16_HYS_SHIFT))&LPC_IOCON_PIO0_16_HYS_MASK) /**< LPC_IOCON_PIO0_16.HYS Field             */
#define LPC_IOCON_PIO0_16_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO0_16.INV Mask              */
#define LPC_IOCON_PIO0_16_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO0_16.INV Position          */
#define LPC_IOCON_PIO0_16_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_16_INV_SHIFT))&LPC_IOCON_PIO0_16_INV_MASK) /**< LPC_IOCON_PIO0_16.INV Field             */
#define LPC_IOCON_PIO0_16_ADMODE_MASK            (0x80U)                                             /**< LPC_IOCON_PIO0_16.ADMODE Mask           */
#define LPC_IOCON_PIO0_16_ADMODE_SHIFT           (7U)                                                /**< LPC_IOCON_PIO0_16.ADMODE Position       */
#define LPC_IOCON_PIO0_16_ADMODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_16_ADMODE_SHIFT))&LPC_IOCON_PIO0_16_ADMODE_MASK) /**< LPC_IOCON_PIO0_16.ADMODE Field          */
#define LPC_IOCON_PIO0_16_FILTR_MASK             (0x100U)                                            /**< LPC_IOCON_PIO0_16.FILTR Mask            */
#define LPC_IOCON_PIO0_16_FILTR_SHIFT            (8U)                                                /**< LPC_IOCON_PIO0_16.FILTR Position        */
#define LPC_IOCON_PIO0_16_FILTR(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_16_FILTR_SHIFT))&LPC_IOCON_PIO0_16_FILTR_MASK) /**< LPC_IOCON_PIO0_16.FILTR Field           */
#define LPC_IOCON_PIO0_16_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO0_16.OD Mask               */
#define LPC_IOCON_PIO0_16_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO0_16.OD Position           */
#define LPC_IOCON_PIO0_16_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_16_OD_SHIFT))&LPC_IOCON_PIO0_16_OD_MASK) /**< LPC_IOCON_PIO0_16.OD Field              */
/** @} */

/** @name PIO0_17 - I/O configuration for pin PIO0_17/RTS/CT32B0_CAP0/SCLK */ /** @{ */
#define LPC_IOCON_PIO0_17_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO0_17.FUNC Mask             */
#define LPC_IOCON_PIO0_17_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO0_17.FUNC Position         */
#define LPC_IOCON_PIO0_17_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_17_FUNC_SHIFT))&LPC_IOCON_PIO0_17_FUNC_MASK) /**< LPC_IOCON_PIO0_17.FUNC Field            */
#define LPC_IOCON_PIO0_17_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO0_17.MODE Mask             */
#define LPC_IOCON_PIO0_17_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO0_17.MODE Position         */
#define LPC_IOCON_PIO0_17_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_17_MODE_SHIFT))&LPC_IOCON_PIO0_17_MODE_MASK) /**< LPC_IOCON_PIO0_17.MODE Field            */
#define LPC_IOCON_PIO0_17_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO0_17.HYS Mask              */
#define LPC_IOCON_PIO0_17_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO0_17.HYS Position          */
#define LPC_IOCON_PIO0_17_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_17_HYS_SHIFT))&LPC_IOCON_PIO0_17_HYS_MASK) /**< LPC_IOCON_PIO0_17.HYS Field             */
#define LPC_IOCON_PIO0_17_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO0_17.INV Mask              */
#define LPC_IOCON_PIO0_17_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO0_17.INV Position          */
#define LPC_IOCON_PIO0_17_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_17_INV_SHIFT))&LPC_IOCON_PIO0_17_INV_MASK) /**< LPC_IOCON_PIO0_17.INV Field             */
#define LPC_IOCON_PIO0_17_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO0_17.OD Mask               */
#define LPC_IOCON_PIO0_17_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO0_17.OD Position           */
#define LPC_IOCON_PIO0_17_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_17_OD_SHIFT))&LPC_IOCON_PIO0_17_OD_MASK) /**< LPC_IOCON_PIO0_17.OD Field              */
/** @} */

/** @name PIO0_18 - I/O configuration for pin PIO0_18/RXD/CT32B0_MAT0 */ /** @{ */
#define LPC_IOCON_PIO0_18_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO0_18.FUNC Mask             */
#define LPC_IOCON_PIO0_18_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO0_18.FUNC Position         */
#define LPC_IOCON_PIO0_18_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_FUNC_SHIFT))&LPC_IOCON_PIO0_18_FUNC_MASK) /**< LPC_IOCON_PIO0_18.FUNC Field            */
#define LPC_IOCON_PIO0_18_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO0_18.MODE Mask             */
#define LPC_IOCON_PIO0_18_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO0_18.MODE Position         */
#define LPC_IOCON_PIO0_18_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_MODE_SHIFT))&LPC_IOCON_PIO0_18_MODE_MASK) /**< LPC_IOCON_PIO0_18.MODE Field            */
#define LPC_IOCON_PIO0_18_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO0_18.HYS Mask              */
#define LPC_IOCON_PIO0_18_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO0_18.HYS Position          */
#define LPC_IOCON_PIO0_18_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_HYS_SHIFT))&LPC_IOCON_PIO0_18_HYS_MASK) /**< LPC_IOCON_PIO0_18.HYS Field             */
#define LPC_IOCON_PIO0_18_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO0_18.INV Mask              */
#define LPC_IOCON_PIO0_18_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO0_18.INV Position          */
#define LPC_IOCON_PIO0_18_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_INV_SHIFT))&LPC_IOCON_PIO0_18_INV_MASK) /**< LPC_IOCON_PIO0_18.INV Field             */
#define LPC_IOCON_PIO0_18_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO0_18.OD Mask               */
#define LPC_IOCON_PIO0_18_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO0_18.OD Position           */
#define LPC_IOCON_PIO0_18_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_OD_SHIFT))&LPC_IOCON_PIO0_18_OD_MASK) /**< LPC_IOCON_PIO0_18.OD Field              */
/** @} */

/** @name PIO0_19 - I/O configuration for pin PIO0_19/TXD/CT32B0_MAT1 */ /** @{ */
#define LPC_IOCON_PIO0_19_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO0_19.FUNC Mask             */
#define LPC_IOCON_PIO0_19_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO0_19.FUNC Position         */
#define LPC_IOCON_PIO0_19_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_FUNC_SHIFT))&LPC_IOCON_PIO0_19_FUNC_MASK) /**< LPC_IOCON_PIO0_19.FUNC Field            */
#define LPC_IOCON_PIO0_19_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO0_19.MODE Mask             */
#define LPC_IOCON_PIO0_19_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO0_19.MODE Position         */
#define LPC_IOCON_PIO0_19_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_MODE_SHIFT))&LPC_IOCON_PIO0_19_MODE_MASK) /**< LPC_IOCON_PIO0_19.MODE Field            */
#define LPC_IOCON_PIO0_19_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO0_19.HYS Mask              */
#define LPC_IOCON_PIO0_19_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO0_19.HYS Position          */
#define LPC_IOCON_PIO0_19_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_HYS_SHIFT))&LPC_IOCON_PIO0_19_HYS_MASK) /**< LPC_IOCON_PIO0_19.HYS Field             */
#define LPC_IOCON_PIO0_19_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO0_19.INV Mask              */
#define LPC_IOCON_PIO0_19_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO0_19.INV Position          */
#define LPC_IOCON_PIO0_19_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_INV_SHIFT))&LPC_IOCON_PIO0_19_INV_MASK) /**< LPC_IOCON_PIO0_19.INV Field             */
#define LPC_IOCON_PIO0_19_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO0_19.OD Mask               */
#define LPC_IOCON_PIO0_19_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO0_19.OD Position           */
#define LPC_IOCON_PIO0_19_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_OD_SHIFT))&LPC_IOCON_PIO0_19_OD_MASK) /**< LPC_IOCON_PIO0_19.OD Field              */
/** @} */

/** @name PIO0_20 - I/O configuration for pin PIO0_20/CT16B1_CAP0 */ /** @{ */
#define LPC_IOCON_PIO0_20_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO0_20.FUNC Mask             */
#define LPC_IOCON_PIO0_20_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO0_20.FUNC Position         */
#define LPC_IOCON_PIO0_20_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_FUNC_SHIFT))&LPC_IOCON_PIO0_20_FUNC_MASK) /**< LPC_IOCON_PIO0_20.FUNC Field            */
#define LPC_IOCON_PIO0_20_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO0_20.MODE Mask             */
#define LPC_IOCON_PIO0_20_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO0_20.MODE Position         */
#define LPC_IOCON_PIO0_20_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_MODE_SHIFT))&LPC_IOCON_PIO0_20_MODE_MASK) /**< LPC_IOCON_PIO0_20.MODE Field            */
#define LPC_IOCON_PIO0_20_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO0_20.HYS Mask              */
#define LPC_IOCON_PIO0_20_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO0_20.HYS Position          */
#define LPC_IOCON_PIO0_20_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_HYS_SHIFT))&LPC_IOCON_PIO0_20_HYS_MASK) /**< LPC_IOCON_PIO0_20.HYS Field             */
#define LPC_IOCON_PIO0_20_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO0_20.INV Mask              */
#define LPC_IOCON_PIO0_20_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO0_20.INV Position          */
#define LPC_IOCON_PIO0_20_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_INV_SHIFT))&LPC_IOCON_PIO0_20_INV_MASK) /**< LPC_IOCON_PIO0_20.INV Field             */
#define LPC_IOCON_PIO0_20_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO0_20.OD Mask               */
#define LPC_IOCON_PIO0_20_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO0_20.OD Position           */
#define LPC_IOCON_PIO0_20_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_OD_SHIFT))&LPC_IOCON_PIO0_20_OD_MASK) /**< LPC_IOCON_PIO0_20.OD Field              */
/** @} */

/** @name PIO0_21 - I/O configuration for pin PIO0_21/CT16B1_MAT0/MOSI1 */ /** @{ */
#define LPC_IOCON_PIO0_21_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO0_21.FUNC Mask             */
#define LPC_IOCON_PIO0_21_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO0_21.FUNC Position         */
#define LPC_IOCON_PIO0_21_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_FUNC_SHIFT))&LPC_IOCON_PIO0_21_FUNC_MASK) /**< LPC_IOCON_PIO0_21.FUNC Field            */
#define LPC_IOCON_PIO0_21_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO0_21.MODE Mask             */
#define LPC_IOCON_PIO0_21_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO0_21.MODE Position         */
#define LPC_IOCON_PIO0_21_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_MODE_SHIFT))&LPC_IOCON_PIO0_21_MODE_MASK) /**< LPC_IOCON_PIO0_21.MODE Field            */
#define LPC_IOCON_PIO0_21_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO0_21.HYS Mask              */
#define LPC_IOCON_PIO0_21_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO0_21.HYS Position          */
#define LPC_IOCON_PIO0_21_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_HYS_SHIFT))&LPC_IOCON_PIO0_21_HYS_MASK) /**< LPC_IOCON_PIO0_21.HYS Field             */
#define LPC_IOCON_PIO0_21_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO0_21.INV Mask              */
#define LPC_IOCON_PIO0_21_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO0_21.INV Position          */
#define LPC_IOCON_PIO0_21_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_INV_SHIFT))&LPC_IOCON_PIO0_21_INV_MASK) /**< LPC_IOCON_PIO0_21.INV Field             */
#define LPC_IOCON_PIO0_21_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO0_21.OD Mask               */
#define LPC_IOCON_PIO0_21_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO0_21.OD Position           */
#define LPC_IOCON_PIO0_21_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_OD_SHIFT))&LPC_IOCON_PIO0_21_OD_MASK) /**< LPC_IOCON_PIO0_21.OD Field              */
/** @} */

/** @name PIO0_22 - I/O configuration for pin PIO0_22/AD6/CT16B1_MAT1/MISO1 */ /** @{ */
#define LPC_IOCON_PIO0_22_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO0_22.FUNC Mask             */
#define LPC_IOCON_PIO0_22_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO0_22.FUNC Position         */
#define LPC_IOCON_PIO0_22_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_FUNC_SHIFT))&LPC_IOCON_PIO0_22_FUNC_MASK) /**< LPC_IOCON_PIO0_22.FUNC Field            */
#define LPC_IOCON_PIO0_22_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO0_22.MODE Mask             */
#define LPC_IOCON_PIO0_22_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO0_22.MODE Position         */
#define LPC_IOCON_PIO0_22_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_MODE_SHIFT))&LPC_IOCON_PIO0_22_MODE_MASK) /**< LPC_IOCON_PIO0_22.MODE Field            */
#define LPC_IOCON_PIO0_22_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO0_22.HYS Mask              */
#define LPC_IOCON_PIO0_22_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO0_22.HYS Position          */
#define LPC_IOCON_PIO0_22_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_HYS_SHIFT))&LPC_IOCON_PIO0_22_HYS_MASK) /**< LPC_IOCON_PIO0_22.HYS Field             */
#define LPC_IOCON_PIO0_22_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO0_22.INV Mask              */
#define LPC_IOCON_PIO0_22_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO0_22.INV Position          */
#define LPC_IOCON_PIO0_22_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_INV_SHIFT))&LPC_IOCON_PIO0_22_INV_MASK) /**< LPC_IOCON_PIO0_22.INV Field             */
#define LPC_IOCON_PIO0_22_ADMODE_MASK            (0x80U)                                             /**< LPC_IOCON_PIO0_22.ADMODE Mask           */
#define LPC_IOCON_PIO0_22_ADMODE_SHIFT           (7U)                                                /**< LPC_IOCON_PIO0_22.ADMODE Position       */
#define LPC_IOCON_PIO0_22_ADMODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_ADMODE_SHIFT))&LPC_IOCON_PIO0_22_ADMODE_MASK) /**< LPC_IOCON_PIO0_22.ADMODE Field          */
#define LPC_IOCON_PIO0_22_FILTR_MASK             (0x100U)                                            /**< LPC_IOCON_PIO0_22.FILTR Mask            */
#define LPC_IOCON_PIO0_22_FILTR_SHIFT            (8U)                                                /**< LPC_IOCON_PIO0_22.FILTR Position        */
#define LPC_IOCON_PIO0_22_FILTR(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_FILTR_SHIFT))&LPC_IOCON_PIO0_22_FILTR_MASK) /**< LPC_IOCON_PIO0_22.FILTR Field           */
#define LPC_IOCON_PIO0_22_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO0_22.OD Mask               */
#define LPC_IOCON_PIO0_22_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO0_22.OD Position           */
#define LPC_IOCON_PIO0_22_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_OD_SHIFT))&LPC_IOCON_PIO0_22_OD_MASK) /**< LPC_IOCON_PIO0_22.OD Field              */
/** @} */

/** @name PIO0_23 - I/O configuration for pin PIO0_23/AD7 */ /** @{ */
#define LPC_IOCON_PIO0_23_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO0_23.FUNC Mask             */
#define LPC_IOCON_PIO0_23_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO0_23.FUNC Position         */
#define LPC_IOCON_PIO0_23_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_FUNC_SHIFT))&LPC_IOCON_PIO0_23_FUNC_MASK) /**< LPC_IOCON_PIO0_23.FUNC Field            */
#define LPC_IOCON_PIO0_23_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO0_23.MODE Mask             */
#define LPC_IOCON_PIO0_23_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO0_23.MODE Position         */
#define LPC_IOCON_PIO0_23_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_MODE_SHIFT))&LPC_IOCON_PIO0_23_MODE_MASK) /**< LPC_IOCON_PIO0_23.MODE Field            */
#define LPC_IOCON_PIO0_23_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO0_23.HYS Mask              */
#define LPC_IOCON_PIO0_23_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO0_23.HYS Position          */
#define LPC_IOCON_PIO0_23_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_HYS_SHIFT))&LPC_IOCON_PIO0_23_HYS_MASK) /**< LPC_IOCON_PIO0_23.HYS Field             */
#define LPC_IOCON_PIO0_23_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO0_23.INV Mask              */
#define LPC_IOCON_PIO0_23_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO0_23.INV Position          */
#define LPC_IOCON_PIO0_23_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_INV_SHIFT))&LPC_IOCON_PIO0_23_INV_MASK) /**< LPC_IOCON_PIO0_23.INV Field             */
#define LPC_IOCON_PIO0_23_ADMODE_MASK            (0x80U)                                             /**< LPC_IOCON_PIO0_23.ADMODE Mask           */
#define LPC_IOCON_PIO0_23_ADMODE_SHIFT           (7U)                                                /**< LPC_IOCON_PIO0_23.ADMODE Position       */
#define LPC_IOCON_PIO0_23_ADMODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_ADMODE_SHIFT))&LPC_IOCON_PIO0_23_ADMODE_MASK) /**< LPC_IOCON_PIO0_23.ADMODE Field          */
#define LPC_IOCON_PIO0_23_FILTR_MASK             (0x100U)                                            /**< LPC_IOCON_PIO0_23.FILTR Mask            */
#define LPC_IOCON_PIO0_23_FILTR_SHIFT            (8U)                                                /**< LPC_IOCON_PIO0_23.FILTR Position        */
#define LPC_IOCON_PIO0_23_FILTR(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_FILTR_SHIFT))&LPC_IOCON_PIO0_23_FILTR_MASK) /**< LPC_IOCON_PIO0_23.FILTR Field           */
#define LPC_IOCON_PIO0_23_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO0_23.OD Mask               */
#define LPC_IOCON_PIO0_23_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO0_23.OD Position           */
#define LPC_IOCON_PIO0_23_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_OD_SHIFT))&LPC_IOCON_PIO0_23_OD_MASK) /**< LPC_IOCON_PIO0_23.OD Field              */
/** @} */

/** @name PIO1_0 - I/O configuration for pin PIO1_0/CT32B1_MAT0 */ /** @{ */
#define LPC_IOCON_PIO1_0_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO1_0.FUNC Mask              */
#define LPC_IOCON_PIO1_0_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO1_0.FUNC Position          */
#define LPC_IOCON_PIO1_0_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_0_FUNC_SHIFT))&LPC_IOCON_PIO1_0_FUNC_MASK) /**< LPC_IOCON_PIO1_0.FUNC Field             */
#define LPC_IOCON_PIO1_0_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO1_0.MODE Mask              */
#define LPC_IOCON_PIO1_0_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO1_0.MODE Position          */
#define LPC_IOCON_PIO1_0_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_0_MODE_SHIFT))&LPC_IOCON_PIO1_0_MODE_MASK) /**< LPC_IOCON_PIO1_0.MODE Field             */
#define LPC_IOCON_PIO1_0_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO1_0.HYS Mask               */
#define LPC_IOCON_PIO1_0_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO1_0.HYS Position           */
#define LPC_IOCON_PIO1_0_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_0_HYS_SHIFT))&LPC_IOCON_PIO1_0_HYS_MASK) /**< LPC_IOCON_PIO1_0.HYS Field              */
#define LPC_IOCON_PIO1_0_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO1_0.INV Mask               */
#define LPC_IOCON_PIO1_0_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO1_0.INV Position           */
#define LPC_IOCON_PIO1_0_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_0_INV_SHIFT))&LPC_IOCON_PIO1_0_INV_MASK) /**< LPC_IOCON_PIO1_0.INV Field              */
#define LPC_IOCON_PIO1_0_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO1_0.OD Mask                */
#define LPC_IOCON_PIO1_0_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO1_0.OD Position            */
#define LPC_IOCON_PIO1_0_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_0_OD_SHIFT))&LPC_IOCON_PIO1_0_OD_MASK) /**< LPC_IOCON_PIO1_0.OD Field               */
/** @} */

/** @name PIO1_1 - I/O configuration for pin PIO1_1/CT32B1_MAT1 */ /** @{ */
#define LPC_IOCON_PIO1_1_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO1_1.FUNC Mask              */
#define LPC_IOCON_PIO1_1_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO1_1.FUNC Position          */
#define LPC_IOCON_PIO1_1_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_1_FUNC_SHIFT))&LPC_IOCON_PIO1_1_FUNC_MASK) /**< LPC_IOCON_PIO1_1.FUNC Field             */
#define LPC_IOCON_PIO1_1_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO1_1.MODE Mask              */
#define LPC_IOCON_PIO1_1_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO1_1.MODE Position          */
#define LPC_IOCON_PIO1_1_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_1_MODE_SHIFT))&LPC_IOCON_PIO1_1_MODE_MASK) /**< LPC_IOCON_PIO1_1.MODE Field             */
#define LPC_IOCON_PIO1_1_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO1_1.HYS Mask               */
#define LPC_IOCON_PIO1_1_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO1_1.HYS Position           */
#define LPC_IOCON_PIO1_1_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_1_HYS_SHIFT))&LPC_IOCON_PIO1_1_HYS_MASK) /**< LPC_IOCON_PIO1_1.HYS Field              */
#define LPC_IOCON_PIO1_1_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO1_1.INV Mask               */
#define LPC_IOCON_PIO1_1_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO1_1.INV Position           */
#define LPC_IOCON_PIO1_1_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_1_INV_SHIFT))&LPC_IOCON_PIO1_1_INV_MASK) /**< LPC_IOCON_PIO1_1.INV Field              */
#define LPC_IOCON_PIO1_1_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO1_1.OD Mask                */
#define LPC_IOCON_PIO1_1_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO1_1.OD Position            */
#define LPC_IOCON_PIO1_1_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_1_OD_SHIFT))&LPC_IOCON_PIO1_1_OD_MASK) /**< LPC_IOCON_PIO1_1.OD Field               */
/** @} */

/** @name PIO1_2 - I/O configuration for pin PIO1_2/CT32B1_MAT2 */ /** @{ */
#define LPC_IOCON_PIO1_2_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO1_2.FUNC Mask              */
#define LPC_IOCON_PIO1_2_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO1_2.FUNC Position          */
#define LPC_IOCON_PIO1_2_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_2_FUNC_SHIFT))&LPC_IOCON_PIO1_2_FUNC_MASK) /**< LPC_IOCON_PIO1_2.FUNC Field             */
#define LPC_IOCON_PIO1_2_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO1_2.MODE Mask              */
#define LPC_IOCON_PIO1_2_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO1_2.MODE Position          */
#define LPC_IOCON_PIO1_2_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_2_MODE_SHIFT))&LPC_IOCON_PIO1_2_MODE_MASK) /**< LPC_IOCON_PIO1_2.MODE Field             */
#define LPC_IOCON_PIO1_2_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO1_2.HYS Mask               */
#define LPC_IOCON_PIO1_2_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO1_2.HYS Position           */
#define LPC_IOCON_PIO1_2_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_2_HYS_SHIFT))&LPC_IOCON_PIO1_2_HYS_MASK) /**< LPC_IOCON_PIO1_2.HYS Field              */
#define LPC_IOCON_PIO1_2_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO1_2.INV Mask               */
#define LPC_IOCON_PIO1_2_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO1_2.INV Position           */
#define LPC_IOCON_PIO1_2_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_2_INV_SHIFT))&LPC_IOCON_PIO1_2_INV_MASK) /**< LPC_IOCON_PIO1_2.INV Field              */
#define LPC_IOCON_PIO1_2_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO1_2.OD Mask                */
#define LPC_IOCON_PIO1_2_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO1_2.OD Position            */
#define LPC_IOCON_PIO1_2_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_2_OD_SHIFT))&LPC_IOCON_PIO1_2_OD_MASK) /**< LPC_IOCON_PIO1_2.OD Field               */
/** @} */

/** @name PIO1_3 - I/O configuration for pin PIO1_3/CT32B1_MAT3 */ /** @{ */
#define LPC_IOCON_PIO1_3_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO1_3.FUNC Mask              */
#define LPC_IOCON_PIO1_3_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO1_3.FUNC Position          */
#define LPC_IOCON_PIO1_3_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_3_FUNC_SHIFT))&LPC_IOCON_PIO1_3_FUNC_MASK) /**< LPC_IOCON_PIO1_3.FUNC Field             */
#define LPC_IOCON_PIO1_3_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO1_3.MODE Mask              */
#define LPC_IOCON_PIO1_3_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO1_3.MODE Position          */
#define LPC_IOCON_PIO1_3_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_3_MODE_SHIFT))&LPC_IOCON_PIO1_3_MODE_MASK) /**< LPC_IOCON_PIO1_3.MODE Field             */
#define LPC_IOCON_PIO1_3_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO1_3.HYS Mask               */
#define LPC_IOCON_PIO1_3_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO1_3.HYS Position           */
#define LPC_IOCON_PIO1_3_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_3_HYS_SHIFT))&LPC_IOCON_PIO1_3_HYS_MASK) /**< LPC_IOCON_PIO1_3.HYS Field              */
#define LPC_IOCON_PIO1_3_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO1_3.INV Mask               */
#define LPC_IOCON_PIO1_3_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO1_3.INV Position           */
#define LPC_IOCON_PIO1_3_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_3_INV_SHIFT))&LPC_IOCON_PIO1_3_INV_MASK) /**< LPC_IOCON_PIO1_3.INV Field              */
#define LPC_IOCON_PIO1_3_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO1_3.OD Mask                */
#define LPC_IOCON_PIO1_3_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO1_3.OD Position            */
#define LPC_IOCON_PIO1_3_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_3_OD_SHIFT))&LPC_IOCON_PIO1_3_OD_MASK) /**< LPC_IOCON_PIO1_3.OD Field               */
/** @} */

/** @name PIO1_4 - I/O configuration for pin PIO1_4/CT32B1_CAP0 */ /** @{ */
#define LPC_IOCON_PIO1_4_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO1_4.FUNC Mask              */
#define LPC_IOCON_PIO1_4_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO1_4.FUNC Position          */
#define LPC_IOCON_PIO1_4_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_4_FUNC_SHIFT))&LPC_IOCON_PIO1_4_FUNC_MASK) /**< LPC_IOCON_PIO1_4.FUNC Field             */
#define LPC_IOCON_PIO1_4_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO1_4.MODE Mask              */
#define LPC_IOCON_PIO1_4_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO1_4.MODE Position          */
#define LPC_IOCON_PIO1_4_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_4_MODE_SHIFT))&LPC_IOCON_PIO1_4_MODE_MASK) /**< LPC_IOCON_PIO1_4.MODE Field             */
#define LPC_IOCON_PIO1_4_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO1_4.HYS Mask               */
#define LPC_IOCON_PIO1_4_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO1_4.HYS Position           */
#define LPC_IOCON_PIO1_4_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_4_HYS_SHIFT))&LPC_IOCON_PIO1_4_HYS_MASK) /**< LPC_IOCON_PIO1_4.HYS Field              */
#define LPC_IOCON_PIO1_4_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO1_4.INV Mask               */
#define LPC_IOCON_PIO1_4_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO1_4.INV Position           */
#define LPC_IOCON_PIO1_4_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_4_INV_SHIFT))&LPC_IOCON_PIO1_4_INV_MASK) /**< LPC_IOCON_PIO1_4.INV Field              */
#define LPC_IOCON_PIO1_4_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO1_4.OD Mask                */
#define LPC_IOCON_PIO1_4_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO1_4.OD Position            */
#define LPC_IOCON_PIO1_4_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_4_OD_SHIFT))&LPC_IOCON_PIO1_4_OD_MASK) /**< LPC_IOCON_PIO1_4.OD Field               */
/** @} */

/** @name PIO1_5 - I/O configuration for pin PIO1_5/CT32B1_CAP1 */ /** @{ */
#define LPC_IOCON_PIO1_5_FUNC_MASK               (0x7U)                                              /**< LPC_IOCON_PIO1_5.FUNC Mask              */
#define LPC_IOCON_PIO1_5_FUNC_SHIFT              (0U)                                                /**< LPC_IOCON_PIO1_5.FUNC Position          */
#define LPC_IOCON_PIO1_5_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_5_FUNC_SHIFT))&LPC_IOCON_PIO1_5_FUNC_MASK) /**< LPC_IOCON_PIO1_5.FUNC Field             */
#define LPC_IOCON_PIO1_5_MODE_MASK               (0x18U)                                             /**< LPC_IOCON_PIO1_5.MODE Mask              */
#define LPC_IOCON_PIO1_5_MODE_SHIFT              (3U)                                                /**< LPC_IOCON_PIO1_5.MODE Position          */
#define LPC_IOCON_PIO1_5_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_5_MODE_SHIFT))&LPC_IOCON_PIO1_5_MODE_MASK) /**< LPC_IOCON_PIO1_5.MODE Field             */
#define LPC_IOCON_PIO1_5_HYS_MASK                (0x20U)                                             /**< LPC_IOCON_PIO1_5.HYS Mask               */
#define LPC_IOCON_PIO1_5_HYS_SHIFT               (5U)                                                /**< LPC_IOCON_PIO1_5.HYS Position           */
#define LPC_IOCON_PIO1_5_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_5_HYS_SHIFT))&LPC_IOCON_PIO1_5_HYS_MASK) /**< LPC_IOCON_PIO1_5.HYS Field              */
#define LPC_IOCON_PIO1_5_INV_MASK                (0x40U)                                             /**< LPC_IOCON_PIO1_5.INV Mask               */
#define LPC_IOCON_PIO1_5_INV_SHIFT               (6U)                                                /**< LPC_IOCON_PIO1_5.INV Position           */
#define LPC_IOCON_PIO1_5_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_5_INV_SHIFT))&LPC_IOCON_PIO1_5_INV_MASK) /**< LPC_IOCON_PIO1_5.INV Field              */
#define LPC_IOCON_PIO1_5_OD_MASK                 (0x400U)                                            /**< LPC_IOCON_PIO1_5.OD Mask                */
#define LPC_IOCON_PIO1_5_OD_SHIFT                (10U)                                               /**< LPC_IOCON_PIO1_5.OD Position            */
#define LPC_IOCON_PIO1_5_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_5_OD_SHIFT))&LPC_IOCON_PIO1_5_OD_MASK) /**< LPC_IOCON_PIO1_5.OD Field               */
/** @} */

/** @name PIO1_ - I/O configuration for pin PIO1_%s */ /** @{ */
#define LPC_IOCON_PIO1__FUNC_MASK                (0x7U)                                              /**< LPC_IOCON_PIO1_.FUNC Mask               */
#define LPC_IOCON_PIO1__FUNC_SHIFT               (0U)                                                /**< LPC_IOCON_PIO1_.FUNC Position           */
#define LPC_IOCON_PIO1__FUNC(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1__FUNC_SHIFT))&LPC_IOCON_PIO1__FUNC_MASK) /**< LPC_IOCON_PIO1_.FUNC Field              */
#define LPC_IOCON_PIO1__MODE_MASK                (0x18U)                                             /**< LPC_IOCON_PIO1_.MODE Mask               */
#define LPC_IOCON_PIO1__MODE_SHIFT               (3U)                                                /**< LPC_IOCON_PIO1_.MODE Position           */
#define LPC_IOCON_PIO1__MODE(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1__MODE_SHIFT))&LPC_IOCON_PIO1__MODE_MASK) /**< LPC_IOCON_PIO1_.MODE Field              */
#define LPC_IOCON_PIO1__HYS_MASK                 (0x20U)                                             /**< LPC_IOCON_PIO1_.HYS Mask                */
#define LPC_IOCON_PIO1__HYS_SHIFT                (5U)                                                /**< LPC_IOCON_PIO1_.HYS Position            */
#define LPC_IOCON_PIO1__HYS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1__HYS_SHIFT))&LPC_IOCON_PIO1__HYS_MASK) /**< LPC_IOCON_PIO1_.HYS Field               */
#define LPC_IOCON_PIO1__INV_MASK                 (0x40U)                                             /**< LPC_IOCON_PIO1_.INV Mask                */
#define LPC_IOCON_PIO1__INV_SHIFT                (6U)                                                /**< LPC_IOCON_PIO1_.INV Position            */
#define LPC_IOCON_PIO1__INV(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1__INV_SHIFT))&LPC_IOCON_PIO1__INV_MASK) /**< LPC_IOCON_PIO1_.INV Field               */
#define LPC_IOCON_PIO1__OD_MASK                  (0x400U)                                            /**< LPC_IOCON_PIO1_.OD Mask                 */
#define LPC_IOCON_PIO1__OD_SHIFT                 (10U)                                               /**< LPC_IOCON_PIO1_.OD Position             */
#define LPC_IOCON_PIO1__OD(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1__OD_SHIFT))&LPC_IOCON_PIO1__OD_MASK) /**< LPC_IOCON_PIO1_.OD Field                */
/** @} */

/** @name PIO1_13 - I/O configuration for pin PIO1_13/DTR/CT16B0_MAT0/TXD */ /** @{ */
#define LPC_IOCON_PIO1_13_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_13.FUNC Mask             */
#define LPC_IOCON_PIO1_13_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_13.FUNC Position         */
#define LPC_IOCON_PIO1_13_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_13_FUNC_SHIFT))&LPC_IOCON_PIO1_13_FUNC_MASK) /**< LPC_IOCON_PIO1_13.FUNC Field            */
#define LPC_IOCON_PIO1_13_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_13.MODE Mask             */
#define LPC_IOCON_PIO1_13_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_13.MODE Position         */
#define LPC_IOCON_PIO1_13_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_13_MODE_SHIFT))&LPC_IOCON_PIO1_13_MODE_MASK) /**< LPC_IOCON_PIO1_13.MODE Field            */
#define LPC_IOCON_PIO1_13_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_13.HYS Mask              */
#define LPC_IOCON_PIO1_13_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_13.HYS Position          */
#define LPC_IOCON_PIO1_13_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_13_HYS_SHIFT))&LPC_IOCON_PIO1_13_HYS_MASK) /**< LPC_IOCON_PIO1_13.HYS Field             */
#define LPC_IOCON_PIO1_13_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_13.INV Mask              */
#define LPC_IOCON_PIO1_13_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_13.INV Position          */
#define LPC_IOCON_PIO1_13_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_13_INV_SHIFT))&LPC_IOCON_PIO1_13_INV_MASK) /**< LPC_IOCON_PIO1_13.INV Field             */
#define LPC_IOCON_PIO1_13_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_13.OD Mask               */
#define LPC_IOCON_PIO1_13_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_13.OD Position           */
#define LPC_IOCON_PIO1_13_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_13_OD_SHIFT))&LPC_IOCON_PIO1_13_OD_MASK) /**< LPC_IOCON_PIO1_13.OD Field              */
/** @} */

/** @name PIO1_14 - I/O configuration for pin PIO1_14/DSR/CT16B0_MAT1/RXD */ /** @{ */
#define LPC_IOCON_PIO1_14_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_14.FUNC Mask             */
#define LPC_IOCON_PIO1_14_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_14.FUNC Position         */
#define LPC_IOCON_PIO1_14_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_14_FUNC_SHIFT))&LPC_IOCON_PIO1_14_FUNC_MASK) /**< LPC_IOCON_PIO1_14.FUNC Field            */
#define LPC_IOCON_PIO1_14_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_14.MODE Mask             */
#define LPC_IOCON_PIO1_14_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_14.MODE Position         */
#define LPC_IOCON_PIO1_14_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_14_MODE_SHIFT))&LPC_IOCON_PIO1_14_MODE_MASK) /**< LPC_IOCON_PIO1_14.MODE Field            */
#define LPC_IOCON_PIO1_14_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_14.HYS Mask              */
#define LPC_IOCON_PIO1_14_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_14.HYS Position          */
#define LPC_IOCON_PIO1_14_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_14_HYS_SHIFT))&LPC_IOCON_PIO1_14_HYS_MASK) /**< LPC_IOCON_PIO1_14.HYS Field             */
#define LPC_IOCON_PIO1_14_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_14.INV Mask              */
#define LPC_IOCON_PIO1_14_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_14.INV Position          */
#define LPC_IOCON_PIO1_14_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_14_INV_SHIFT))&LPC_IOCON_PIO1_14_INV_MASK) /**< LPC_IOCON_PIO1_14.INV Field             */
#define LPC_IOCON_PIO1_14_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_14.OD Mask               */
#define LPC_IOCON_PIO1_14_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_14.OD Position           */
#define LPC_IOCON_PIO1_14_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_14_OD_SHIFT))&LPC_IOCON_PIO1_14_OD_MASK) /**< LPC_IOCON_PIO1_14.OD Field              */
/** @} */

/** @name PIO1_15 - I/O configuration for pin PIO1_15/DCD/  CT16B0_MAT2/SCK1 */ /** @{ */
#define LPC_IOCON_PIO1_15_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_15.FUNC Mask             */
#define LPC_IOCON_PIO1_15_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_15.FUNC Position         */
#define LPC_IOCON_PIO1_15_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_15_FUNC_SHIFT))&LPC_IOCON_PIO1_15_FUNC_MASK) /**< LPC_IOCON_PIO1_15.FUNC Field            */
#define LPC_IOCON_PIO1_15_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_15.MODE Mask             */
#define LPC_IOCON_PIO1_15_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_15.MODE Position         */
#define LPC_IOCON_PIO1_15_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_15_MODE_SHIFT))&LPC_IOCON_PIO1_15_MODE_MASK) /**< LPC_IOCON_PIO1_15.MODE Field            */
#define LPC_IOCON_PIO1_15_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_15.HYS Mask              */
#define LPC_IOCON_PIO1_15_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_15.HYS Position          */
#define LPC_IOCON_PIO1_15_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_15_HYS_SHIFT))&LPC_IOCON_PIO1_15_HYS_MASK) /**< LPC_IOCON_PIO1_15.HYS Field             */
#define LPC_IOCON_PIO1_15_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_15.INV Mask              */
#define LPC_IOCON_PIO1_15_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_15.INV Position          */
#define LPC_IOCON_PIO1_15_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_15_INV_SHIFT))&LPC_IOCON_PIO1_15_INV_MASK) /**< LPC_IOCON_PIO1_15.INV Field             */
#define LPC_IOCON_PIO1_15_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_15.OD Mask               */
#define LPC_IOCON_PIO1_15_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_15.OD Position           */
#define LPC_IOCON_PIO1_15_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_15_OD_SHIFT))&LPC_IOCON_PIO1_15_OD_MASK) /**< LPC_IOCON_PIO1_15.OD Field              */
/** @} */

/** @name PIO1_16 - I/O configuration for pin PIO1_16/RI/CT16B0_CAP0 */ /** @{ */
#define LPC_IOCON_PIO1_16_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_16.FUNC Mask             */
#define LPC_IOCON_PIO1_16_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_16.FUNC Position         */
#define LPC_IOCON_PIO1_16_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_16_FUNC_SHIFT))&LPC_IOCON_PIO1_16_FUNC_MASK) /**< LPC_IOCON_PIO1_16.FUNC Field            */
#define LPC_IOCON_PIO1_16_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_16.MODE Mask             */
#define LPC_IOCON_PIO1_16_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_16.MODE Position         */
#define LPC_IOCON_PIO1_16_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_16_MODE_SHIFT))&LPC_IOCON_PIO1_16_MODE_MASK) /**< LPC_IOCON_PIO1_16.MODE Field            */
#define LPC_IOCON_PIO1_16_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_16.HYS Mask              */
#define LPC_IOCON_PIO1_16_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_16.HYS Position          */
#define LPC_IOCON_PIO1_16_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_16_HYS_SHIFT))&LPC_IOCON_PIO1_16_HYS_MASK) /**< LPC_IOCON_PIO1_16.HYS Field             */
#define LPC_IOCON_PIO1_16_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_16.INV Mask              */
#define LPC_IOCON_PIO1_16_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_16.INV Position          */
#define LPC_IOCON_PIO1_16_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_16_INV_SHIFT))&LPC_IOCON_PIO1_16_INV_MASK) /**< LPC_IOCON_PIO1_16.INV Field             */
#define LPC_IOCON_PIO1_16_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_16.OD Mask               */
#define LPC_IOCON_PIO1_16_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_16.OD Position           */
#define LPC_IOCON_PIO1_16_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_16_OD_SHIFT))&LPC_IOCON_PIO1_16_OD_MASK) /**< LPC_IOCON_PIO1_16.OD Field              */
/** @} */

/** @name PIO1_17 - I/O configuration for PIO1_17/CT16B0_CAP1/RXD */ /** @{ */
#define LPC_IOCON_PIO1_17_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_17.FUNC Mask             */
#define LPC_IOCON_PIO1_17_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_17.FUNC Position         */
#define LPC_IOCON_PIO1_17_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_17_FUNC_SHIFT))&LPC_IOCON_PIO1_17_FUNC_MASK) /**< LPC_IOCON_PIO1_17.FUNC Field            */
#define LPC_IOCON_PIO1_17_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_17.MODE Mask             */
#define LPC_IOCON_PIO1_17_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_17.MODE Position         */
#define LPC_IOCON_PIO1_17_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_17_MODE_SHIFT))&LPC_IOCON_PIO1_17_MODE_MASK) /**< LPC_IOCON_PIO1_17.MODE Field            */
#define LPC_IOCON_PIO1_17_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_17.HYS Mask              */
#define LPC_IOCON_PIO1_17_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_17.HYS Position          */
#define LPC_IOCON_PIO1_17_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_17_HYS_SHIFT))&LPC_IOCON_PIO1_17_HYS_MASK) /**< LPC_IOCON_PIO1_17.HYS Field             */
#define LPC_IOCON_PIO1_17_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_17.INV Mask              */
#define LPC_IOCON_PIO1_17_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_17.INV Position          */
#define LPC_IOCON_PIO1_17_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_17_INV_SHIFT))&LPC_IOCON_PIO1_17_INV_MASK) /**< LPC_IOCON_PIO1_17.INV Field             */
#define LPC_IOCON_PIO1_17_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_17.OD Mask               */
#define LPC_IOCON_PIO1_17_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_17.OD Position           */
#define LPC_IOCON_PIO1_17_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_17_OD_SHIFT))&LPC_IOCON_PIO1_17_OD_MASK) /**< LPC_IOCON_PIO1_17.OD Field              */
/** @} */

/** @name PIO1_18 - I/O configuration for PIO1_18/CT16B1_CAP1/TXD */ /** @{ */
#define LPC_IOCON_PIO1_18_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_18.FUNC Mask             */
#define LPC_IOCON_PIO1_18_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_18.FUNC Position         */
#define LPC_IOCON_PIO1_18_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_18_FUNC_SHIFT))&LPC_IOCON_PIO1_18_FUNC_MASK) /**< LPC_IOCON_PIO1_18.FUNC Field            */
#define LPC_IOCON_PIO1_18_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_18.MODE Mask             */
#define LPC_IOCON_PIO1_18_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_18.MODE Position         */
#define LPC_IOCON_PIO1_18_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_18_MODE_SHIFT))&LPC_IOCON_PIO1_18_MODE_MASK) /**< LPC_IOCON_PIO1_18.MODE Field            */
#define LPC_IOCON_PIO1_18_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_18.HYS Mask              */
#define LPC_IOCON_PIO1_18_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_18.HYS Position          */
#define LPC_IOCON_PIO1_18_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_18_HYS_SHIFT))&LPC_IOCON_PIO1_18_HYS_MASK) /**< LPC_IOCON_PIO1_18.HYS Field             */
#define LPC_IOCON_PIO1_18_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_18.INV Mask              */
#define LPC_IOCON_PIO1_18_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_18.INV Position          */
#define LPC_IOCON_PIO1_18_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_18_INV_SHIFT))&LPC_IOCON_PIO1_18_INV_MASK) /**< LPC_IOCON_PIO1_18.INV Field             */
#define LPC_IOCON_PIO1_18_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_18.OD Mask               */
#define LPC_IOCON_PIO1_18_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_18.OD Position           */
#define LPC_IOCON_PIO1_18_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_18_OD_SHIFT))&LPC_IOCON_PIO1_18_OD_MASK) /**< LPC_IOCON_PIO1_18.OD Field              */
/** @} */

/** @name PIO1_19 - I/O configuration for pin PIO1_19/DTR/SSEL1 */ /** @{ */
#define LPC_IOCON_PIO1_19_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_19.FUNC Mask             */
#define LPC_IOCON_PIO1_19_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_19.FUNC Position         */
#define LPC_IOCON_PIO1_19_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_19_FUNC_SHIFT))&LPC_IOCON_PIO1_19_FUNC_MASK) /**< LPC_IOCON_PIO1_19.FUNC Field            */
#define LPC_IOCON_PIO1_19_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_19.MODE Mask             */
#define LPC_IOCON_PIO1_19_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_19.MODE Position         */
#define LPC_IOCON_PIO1_19_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_19_MODE_SHIFT))&LPC_IOCON_PIO1_19_MODE_MASK) /**< LPC_IOCON_PIO1_19.MODE Field            */
#define LPC_IOCON_PIO1_19_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_19.HYS Mask              */
#define LPC_IOCON_PIO1_19_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_19.HYS Position          */
#define LPC_IOCON_PIO1_19_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_19_HYS_SHIFT))&LPC_IOCON_PIO1_19_HYS_MASK) /**< LPC_IOCON_PIO1_19.HYS Field             */
#define LPC_IOCON_PIO1_19_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_19.INV Mask              */
#define LPC_IOCON_PIO1_19_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_19.INV Position          */
#define LPC_IOCON_PIO1_19_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_19_INV_SHIFT))&LPC_IOCON_PIO1_19_INV_MASK) /**< LPC_IOCON_PIO1_19.INV Field             */
#define LPC_IOCON_PIO1_19_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_19.OD Mask               */
#define LPC_IOCON_PIO1_19_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_19.OD Position           */
#define LPC_IOCON_PIO1_19_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_19_OD_SHIFT))&LPC_IOCON_PIO1_19_OD_MASK) /**< LPC_IOCON_PIO1_19.OD Field              */
/** @} */

/** @name PIO1_20 - I/O configuration for pin PIO1_20/DSR/SCK1 */ /** @{ */
#define LPC_IOCON_PIO1_20_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_20.FUNC Mask             */
#define LPC_IOCON_PIO1_20_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_20.FUNC Position         */
#define LPC_IOCON_PIO1_20_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_20_FUNC_SHIFT))&LPC_IOCON_PIO1_20_FUNC_MASK) /**< LPC_IOCON_PIO1_20.FUNC Field            */
#define LPC_IOCON_PIO1_20_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_20.MODE Mask             */
#define LPC_IOCON_PIO1_20_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_20.MODE Position         */
#define LPC_IOCON_PIO1_20_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_20_MODE_SHIFT))&LPC_IOCON_PIO1_20_MODE_MASK) /**< LPC_IOCON_PIO1_20.MODE Field            */
#define LPC_IOCON_PIO1_20_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_20.HYS Mask              */
#define LPC_IOCON_PIO1_20_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_20.HYS Position          */
#define LPC_IOCON_PIO1_20_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_20_HYS_SHIFT))&LPC_IOCON_PIO1_20_HYS_MASK) /**< LPC_IOCON_PIO1_20.HYS Field             */
#define LPC_IOCON_PIO1_20_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_20.INV Mask              */
#define LPC_IOCON_PIO1_20_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_20.INV Position          */
#define LPC_IOCON_PIO1_20_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_20_INV_SHIFT))&LPC_IOCON_PIO1_20_INV_MASK) /**< LPC_IOCON_PIO1_20.INV Field             */
#define LPC_IOCON_PIO1_20_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_20.OD Mask               */
#define LPC_IOCON_PIO1_20_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_20.OD Position           */
#define LPC_IOCON_PIO1_20_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_20_OD_SHIFT))&LPC_IOCON_PIO1_20_OD_MASK) /**< LPC_IOCON_PIO1_20.OD Field              */
/** @} */

/** @name PIO1_21 - I/O configuration for pin PIO1_21/DCD/MISO1 */ /** @{ */
#define LPC_IOCON_PIO1_21_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_21.FUNC Mask             */
#define LPC_IOCON_PIO1_21_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_21.FUNC Position         */
#define LPC_IOCON_PIO1_21_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_21_FUNC_SHIFT))&LPC_IOCON_PIO1_21_FUNC_MASK) /**< LPC_IOCON_PIO1_21.FUNC Field            */
#define LPC_IOCON_PIO1_21_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_21.MODE Mask             */
#define LPC_IOCON_PIO1_21_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_21.MODE Position         */
#define LPC_IOCON_PIO1_21_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_21_MODE_SHIFT))&LPC_IOCON_PIO1_21_MODE_MASK) /**< LPC_IOCON_PIO1_21.MODE Field            */
#define LPC_IOCON_PIO1_21_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_21.HYS Mask              */
#define LPC_IOCON_PIO1_21_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_21.HYS Position          */
#define LPC_IOCON_PIO1_21_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_21_HYS_SHIFT))&LPC_IOCON_PIO1_21_HYS_MASK) /**< LPC_IOCON_PIO1_21.HYS Field             */
#define LPC_IOCON_PIO1_21_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_21.INV Mask              */
#define LPC_IOCON_PIO1_21_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_21.INV Position          */
#define LPC_IOCON_PIO1_21_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_21_INV_SHIFT))&LPC_IOCON_PIO1_21_INV_MASK) /**< LPC_IOCON_PIO1_21.INV Field             */
#define LPC_IOCON_PIO1_21_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_21.OD Mask               */
#define LPC_IOCON_PIO1_21_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_21.OD Position           */
#define LPC_IOCON_PIO1_21_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_21_OD_SHIFT))&LPC_IOCON_PIO1_21_OD_MASK) /**< LPC_IOCON_PIO1_21.OD Field              */
/** @} */

/** @name PIO1_22 - I/O configuration for pin PIO1_22/RI/MOSI1 */ /** @{ */
#define LPC_IOCON_PIO1_22_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_22.FUNC Mask             */
#define LPC_IOCON_PIO1_22_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_22.FUNC Position         */
#define LPC_IOCON_PIO1_22_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_22_FUNC_SHIFT))&LPC_IOCON_PIO1_22_FUNC_MASK) /**< LPC_IOCON_PIO1_22.FUNC Field            */
#define LPC_IOCON_PIO1_22_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_22.MODE Mask             */
#define LPC_IOCON_PIO1_22_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_22.MODE Position         */
#define LPC_IOCON_PIO1_22_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_22_MODE_SHIFT))&LPC_IOCON_PIO1_22_MODE_MASK) /**< LPC_IOCON_PIO1_22.MODE Field            */
#define LPC_IOCON_PIO1_22_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_22.HYS Mask              */
#define LPC_IOCON_PIO1_22_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_22.HYS Position          */
#define LPC_IOCON_PIO1_22_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_22_HYS_SHIFT))&LPC_IOCON_PIO1_22_HYS_MASK) /**< LPC_IOCON_PIO1_22.HYS Field             */
#define LPC_IOCON_PIO1_22_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_22.INV Mask              */
#define LPC_IOCON_PIO1_22_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_22.INV Position          */
#define LPC_IOCON_PIO1_22_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_22_INV_SHIFT))&LPC_IOCON_PIO1_22_INV_MASK) /**< LPC_IOCON_PIO1_22.INV Field             */
#define LPC_IOCON_PIO1_22_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_22.OD Mask               */
#define LPC_IOCON_PIO1_22_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_22.OD Position           */
#define LPC_IOCON_PIO1_22_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_22_OD_SHIFT))&LPC_IOCON_PIO1_22_OD_MASK) /**< LPC_IOCON_PIO1_22.OD Field              */
/** @} */

/** @name PIO1_23 - I/O configuration for pin PIO1_23/CT16B1_MAT1/SSEL1 */ /** @{ */
#define LPC_IOCON_PIO1_23_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_23.FUNC Mask             */
#define LPC_IOCON_PIO1_23_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_23.FUNC Position         */
#define LPC_IOCON_PIO1_23_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_23_FUNC_SHIFT))&LPC_IOCON_PIO1_23_FUNC_MASK) /**< LPC_IOCON_PIO1_23.FUNC Field            */
#define LPC_IOCON_PIO1_23_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_23.MODE Mask             */
#define LPC_IOCON_PIO1_23_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_23.MODE Position         */
#define LPC_IOCON_PIO1_23_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_23_MODE_SHIFT))&LPC_IOCON_PIO1_23_MODE_MASK) /**< LPC_IOCON_PIO1_23.MODE Field            */
#define LPC_IOCON_PIO1_23_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_23.HYS Mask              */
#define LPC_IOCON_PIO1_23_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_23.HYS Position          */
#define LPC_IOCON_PIO1_23_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_23_HYS_SHIFT))&LPC_IOCON_PIO1_23_HYS_MASK) /**< LPC_IOCON_PIO1_23.HYS Field             */
#define LPC_IOCON_PIO1_23_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_23.INV Mask              */
#define LPC_IOCON_PIO1_23_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_23.INV Position          */
#define LPC_IOCON_PIO1_23_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_23_INV_SHIFT))&LPC_IOCON_PIO1_23_INV_MASK) /**< LPC_IOCON_PIO1_23.INV Field             */
#define LPC_IOCON_PIO1_23_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_23.OD Mask               */
#define LPC_IOCON_PIO1_23_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_23.OD Position           */
#define LPC_IOCON_PIO1_23_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_23_OD_SHIFT))&LPC_IOCON_PIO1_23_OD_MASK) /**< LPC_IOCON_PIO1_23.OD Field              */
/** @} */

/** @name PIO1_24 - I/O configuration for pin PIO1_24/ CT32B0_MAT0 */ /** @{ */
#define LPC_IOCON_PIO1_24_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_24.FUNC Mask             */
#define LPC_IOCON_PIO1_24_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_24.FUNC Position         */
#define LPC_IOCON_PIO1_24_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_24_FUNC_SHIFT))&LPC_IOCON_PIO1_24_FUNC_MASK) /**< LPC_IOCON_PIO1_24.FUNC Field            */
#define LPC_IOCON_PIO1_24_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_24.MODE Mask             */
#define LPC_IOCON_PIO1_24_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_24.MODE Position         */
#define LPC_IOCON_PIO1_24_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_24_MODE_SHIFT))&LPC_IOCON_PIO1_24_MODE_MASK) /**< LPC_IOCON_PIO1_24.MODE Field            */
#define LPC_IOCON_PIO1_24_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_24.HYS Mask              */
#define LPC_IOCON_PIO1_24_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_24.HYS Position          */
#define LPC_IOCON_PIO1_24_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_24_HYS_SHIFT))&LPC_IOCON_PIO1_24_HYS_MASK) /**< LPC_IOCON_PIO1_24.HYS Field             */
#define LPC_IOCON_PIO1_24_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_24.INV Mask              */
#define LPC_IOCON_PIO1_24_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_24.INV Position          */
#define LPC_IOCON_PIO1_24_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_24_INV_SHIFT))&LPC_IOCON_PIO1_24_INV_MASK) /**< LPC_IOCON_PIO1_24.INV Field             */
#define LPC_IOCON_PIO1_24_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_24.OD Mask               */
#define LPC_IOCON_PIO1_24_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_24.OD Position           */
#define LPC_IOCON_PIO1_24_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_24_OD_SHIFT))&LPC_IOCON_PIO1_24_OD_MASK) /**< LPC_IOCON_PIO1_24.OD Field              */
/** @} */

/** @name PIO1_25 - I/O configuration for pin PIO1_25/CT32B0_MAT1 */ /** @{ */
#define LPC_IOCON_PIO1_25_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_25.FUNC Mask             */
#define LPC_IOCON_PIO1_25_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_25.FUNC Position         */
#define LPC_IOCON_PIO1_25_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_25_FUNC_SHIFT))&LPC_IOCON_PIO1_25_FUNC_MASK) /**< LPC_IOCON_PIO1_25.FUNC Field            */
#define LPC_IOCON_PIO1_25_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_25.MODE Mask             */
#define LPC_IOCON_PIO1_25_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_25.MODE Position         */
#define LPC_IOCON_PIO1_25_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_25_MODE_SHIFT))&LPC_IOCON_PIO1_25_MODE_MASK) /**< LPC_IOCON_PIO1_25.MODE Field            */
#define LPC_IOCON_PIO1_25_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_25.HYS Mask              */
#define LPC_IOCON_PIO1_25_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_25.HYS Position          */
#define LPC_IOCON_PIO1_25_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_25_HYS_SHIFT))&LPC_IOCON_PIO1_25_HYS_MASK) /**< LPC_IOCON_PIO1_25.HYS Field             */
#define LPC_IOCON_PIO1_25_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_25.INV Mask              */
#define LPC_IOCON_PIO1_25_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_25.INV Position          */
#define LPC_IOCON_PIO1_25_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_25_INV_SHIFT))&LPC_IOCON_PIO1_25_INV_MASK) /**< LPC_IOCON_PIO1_25.INV Field             */
#define LPC_IOCON_PIO1_25_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_25.OD Mask               */
#define LPC_IOCON_PIO1_25_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_25.OD Position           */
#define LPC_IOCON_PIO1_25_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_25_OD_SHIFT))&LPC_IOCON_PIO1_25_OD_MASK) /**< LPC_IOCON_PIO1_25.OD Field              */
/** @} */

/** @name PIO1_26 - I/O configuration for pin PIO1_26/CT32B0_MAT2/ RXD */ /** @{ */
#define LPC_IOCON_PIO1_26_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_26.FUNC Mask             */
#define LPC_IOCON_PIO1_26_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_26.FUNC Position         */
#define LPC_IOCON_PIO1_26_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_26_FUNC_SHIFT))&LPC_IOCON_PIO1_26_FUNC_MASK) /**< LPC_IOCON_PIO1_26.FUNC Field            */
#define LPC_IOCON_PIO1_26_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_26.MODE Mask             */
#define LPC_IOCON_PIO1_26_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_26.MODE Position         */
#define LPC_IOCON_PIO1_26_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_26_MODE_SHIFT))&LPC_IOCON_PIO1_26_MODE_MASK) /**< LPC_IOCON_PIO1_26.MODE Field            */
#define LPC_IOCON_PIO1_26_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_26.HYS Mask              */
#define LPC_IOCON_PIO1_26_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_26.HYS Position          */
#define LPC_IOCON_PIO1_26_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_26_HYS_SHIFT))&LPC_IOCON_PIO1_26_HYS_MASK) /**< LPC_IOCON_PIO1_26.HYS Field             */
#define LPC_IOCON_PIO1_26_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_26.INV Mask              */
#define LPC_IOCON_PIO1_26_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_26.INV Position          */
#define LPC_IOCON_PIO1_26_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_26_INV_SHIFT))&LPC_IOCON_PIO1_26_INV_MASK) /**< LPC_IOCON_PIO1_26.INV Field             */
#define LPC_IOCON_PIO1_26_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_26.OD Mask               */
#define LPC_IOCON_PIO1_26_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_26.OD Position           */
#define LPC_IOCON_PIO1_26_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_26_OD_SHIFT))&LPC_IOCON_PIO1_26_OD_MASK) /**< LPC_IOCON_PIO1_26.OD Field              */
/** @} */

/** @name PIO1_27 - I/O configuration for pin PIO1_27/CT32B0_MAT3/ TXD */ /** @{ */
#define LPC_IOCON_PIO1_27_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_27.FUNC Mask             */
#define LPC_IOCON_PIO1_27_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_27.FUNC Position         */
#define LPC_IOCON_PIO1_27_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_27_FUNC_SHIFT))&LPC_IOCON_PIO1_27_FUNC_MASK) /**< LPC_IOCON_PIO1_27.FUNC Field            */
#define LPC_IOCON_PIO1_27_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_27.MODE Mask             */
#define LPC_IOCON_PIO1_27_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_27.MODE Position         */
#define LPC_IOCON_PIO1_27_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_27_MODE_SHIFT))&LPC_IOCON_PIO1_27_MODE_MASK) /**< LPC_IOCON_PIO1_27.MODE Field            */
#define LPC_IOCON_PIO1_27_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_27.HYS Mask              */
#define LPC_IOCON_PIO1_27_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_27.HYS Position          */
#define LPC_IOCON_PIO1_27_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_27_HYS_SHIFT))&LPC_IOCON_PIO1_27_HYS_MASK) /**< LPC_IOCON_PIO1_27.HYS Field             */
#define LPC_IOCON_PIO1_27_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_27.INV Mask              */
#define LPC_IOCON_PIO1_27_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_27.INV Position          */
#define LPC_IOCON_PIO1_27_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_27_INV_SHIFT))&LPC_IOCON_PIO1_27_INV_MASK) /**< LPC_IOCON_PIO1_27.INV Field             */
#define LPC_IOCON_PIO1_27_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_27.OD Mask               */
#define LPC_IOCON_PIO1_27_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_27.OD Position           */
#define LPC_IOCON_PIO1_27_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_27_OD_SHIFT))&LPC_IOCON_PIO1_27_OD_MASK) /**< LPC_IOCON_PIO1_27.OD Field              */
/** @} */

/** @name PIO1_28 - I/O configuration for pin PIO1_28/CT32B0_CAP0/ SCLK */ /** @{ */
#define LPC_IOCON_PIO1_28_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_28.FUNC Mask             */
#define LPC_IOCON_PIO1_28_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_28.FUNC Position         */
#define LPC_IOCON_PIO1_28_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_28_FUNC_SHIFT))&LPC_IOCON_PIO1_28_FUNC_MASK) /**< LPC_IOCON_PIO1_28.FUNC Field            */
#define LPC_IOCON_PIO1_28_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_28.MODE Mask             */
#define LPC_IOCON_PIO1_28_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_28.MODE Position         */
#define LPC_IOCON_PIO1_28_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_28_MODE_SHIFT))&LPC_IOCON_PIO1_28_MODE_MASK) /**< LPC_IOCON_PIO1_28.MODE Field            */
#define LPC_IOCON_PIO1_28_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_28.HYS Mask              */
#define LPC_IOCON_PIO1_28_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_28.HYS Position          */
#define LPC_IOCON_PIO1_28_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_28_HYS_SHIFT))&LPC_IOCON_PIO1_28_HYS_MASK) /**< LPC_IOCON_PIO1_28.HYS Field             */
#define LPC_IOCON_PIO1_28_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_28.INV Mask              */
#define LPC_IOCON_PIO1_28_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_28.INV Position          */
#define LPC_IOCON_PIO1_28_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_28_INV_SHIFT))&LPC_IOCON_PIO1_28_INV_MASK) /**< LPC_IOCON_PIO1_28.INV Field             */
#define LPC_IOCON_PIO1_28_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_28.OD Mask               */
#define LPC_IOCON_PIO1_28_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_28.OD Position           */
#define LPC_IOCON_PIO1_28_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_28_OD_SHIFT))&LPC_IOCON_PIO1_28_OD_MASK) /**< LPC_IOCON_PIO1_28.OD Field              */
/** @} */

/** @name PIO1_29 - I/O configuration for pin PIO1_29/SCK0/ CT32B0_CAP1 */ /** @{ */
#define LPC_IOCON_PIO1_29_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_29.FUNC Mask             */
#define LPC_IOCON_PIO1_29_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_29.FUNC Position         */
#define LPC_IOCON_PIO1_29_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_29_FUNC_SHIFT))&LPC_IOCON_PIO1_29_FUNC_MASK) /**< LPC_IOCON_PIO1_29.FUNC Field            */
#define LPC_IOCON_PIO1_29_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_29.MODE Mask             */
#define LPC_IOCON_PIO1_29_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_29.MODE Position         */
#define LPC_IOCON_PIO1_29_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_29_MODE_SHIFT))&LPC_IOCON_PIO1_29_MODE_MASK) /**< LPC_IOCON_PIO1_29.MODE Field            */
#define LPC_IOCON_PIO1_29_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_29.HYS Mask              */
#define LPC_IOCON_PIO1_29_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_29.HYS Position          */
#define LPC_IOCON_PIO1_29_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_29_HYS_SHIFT))&LPC_IOCON_PIO1_29_HYS_MASK) /**< LPC_IOCON_PIO1_29.HYS Field             */
#define LPC_IOCON_PIO1_29_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_29.INV Mask              */
#define LPC_IOCON_PIO1_29_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_29.INV Position          */
#define LPC_IOCON_PIO1_29_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_29_INV_SHIFT))&LPC_IOCON_PIO1_29_INV_MASK) /**< LPC_IOCON_PIO1_29.INV Field             */
#define LPC_IOCON_PIO1_29_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_29.OD Mask               */
#define LPC_IOCON_PIO1_29_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_29.OD Position           */
#define LPC_IOCON_PIO1_29_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_29_OD_SHIFT))&LPC_IOCON_PIO1_29_OD_MASK) /**< LPC_IOCON_PIO1_29.OD Field              */
/** @} */

/** @name PIO1_31 - I/O configuration for pin PIO1_31 */ /** @{ */
#define LPC_IOCON_PIO1_31_FUNC_MASK              (0x7U)                                              /**< LPC_IOCON_PIO1_31.FUNC Mask             */
#define LPC_IOCON_PIO1_31_FUNC_SHIFT             (0U)                                                /**< LPC_IOCON_PIO1_31.FUNC Position         */
#define LPC_IOCON_PIO1_31_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_31_FUNC_SHIFT))&LPC_IOCON_PIO1_31_FUNC_MASK) /**< LPC_IOCON_PIO1_31.FUNC Field            */
#define LPC_IOCON_PIO1_31_MODE_MASK              (0x18U)                                             /**< LPC_IOCON_PIO1_31.MODE Mask             */
#define LPC_IOCON_PIO1_31_MODE_SHIFT             (3U)                                                /**< LPC_IOCON_PIO1_31.MODE Position         */
#define LPC_IOCON_PIO1_31_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_31_MODE_SHIFT))&LPC_IOCON_PIO1_31_MODE_MASK) /**< LPC_IOCON_PIO1_31.MODE Field            */
#define LPC_IOCON_PIO1_31_HYS_MASK               (0x20U)                                             /**< LPC_IOCON_PIO1_31.HYS Mask              */
#define LPC_IOCON_PIO1_31_HYS_SHIFT              (5U)                                                /**< LPC_IOCON_PIO1_31.HYS Position          */
#define LPC_IOCON_PIO1_31_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_31_HYS_SHIFT))&LPC_IOCON_PIO1_31_HYS_MASK) /**< LPC_IOCON_PIO1_31.HYS Field             */
#define LPC_IOCON_PIO1_31_INV_MASK               (0x40U)                                             /**< LPC_IOCON_PIO1_31.INV Mask              */
#define LPC_IOCON_PIO1_31_INV_SHIFT              (6U)                                                /**< LPC_IOCON_PIO1_31.INV Position          */
#define LPC_IOCON_PIO1_31_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_31_INV_SHIFT))&LPC_IOCON_PIO1_31_INV_MASK) /**< LPC_IOCON_PIO1_31.INV Field             */
#define LPC_IOCON_PIO1_31_OD_MASK                (0x400U)                                            /**< LPC_IOCON_PIO1_31.OD Mask               */
#define LPC_IOCON_PIO1_31_OD_SHIFT               (10U)                                               /**< LPC_IOCON_PIO1_31.OD Position           */
#define LPC_IOCON_PIO1_31_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO1_31_OD_SHIFT))&LPC_IOCON_PIO1_31_OD_MASK) /**< LPC_IOCON_PIO1_31.OD Field              */
/** @} */

/** @} */ /* End group IOCON_Register_Masks_GROUP */


/* LPC_IOCON - Peripheral instance base addresses */
#define LPC_IOCON_BasePtr              0x40044000UL //!< Peripheral base address
#define LPC_IOCON                      ((LPC_IOCON_Type *) LPC_IOCON_BasePtr) //!< Freescale base pointer
#define LPC_IOCON_BASE_PTR             (LPC_IOCON) //!< Freescale style base pointer

/** @} */ /* End group IOCON_Peripheral_access_layer_GROUP */


/** @brief C Struct for PMU */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup PMU_Peripheral_access_layer_GROUP PMU Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_PMU (file:PMU_LPC11Uxx)          ================ */
/* ================================================================================ */

/**
 * @brief Power Management Unit
 */
/**
 * @struct LPC_PMU_Type
 * @brief  C Struct allowing access to PMU registers
 */
typedef struct LPC_PMU_Type {
   __IO uint32_t  PCON;                         /**< 0000: Power control register                                       */
   __IO uint32_t  GPREG[4];                     /**< 0004: General purpose register                                     */
   __IO uint32_t  GPREG4;                       /**< 0014: General purpose register 4                                   */
} LPC_PMU_Type;


/** @brief Register Masks for PMU */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_PMU' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup PMU_Register_Masks_GROUP PMU Register Masks */
/** @{ */

/** @name PCON - Power control register */ /** @{ */
#define LPC_PMU_PCON_PM_MASK                     (0x7U)                                              /**< LPC_PMU_PCON.PM Mask                    */
#define LPC_PMU_PCON_PM_SHIFT                    (0U)                                                /**< LPC_PMU_PCON.PM Position                */
#define LPC_PMU_PCON_PM(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_PMU_PCON_PM_SHIFT))&LPC_PMU_PCON_PM_MASK) /**< LPC_PMU_PCON.PM Field                   */
#define LPC_PMU_PCON_NODPD_MASK                  (0x8U)                                              /**< LPC_PMU_PCON.NODPD Mask                 */
#define LPC_PMU_PCON_NODPD_SHIFT                 (3U)                                                /**< LPC_PMU_PCON.NODPD Position             */
#define LPC_PMU_PCON_NODPD(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_PMU_PCON_NODPD_SHIFT))&LPC_PMU_PCON_NODPD_MASK) /**< LPC_PMU_PCON.NODPD Field                */
#define LPC_PMU_PCON_SLEEPFLAG_MASK              (0x100U)                                            /**< LPC_PMU_PCON.SLEEPFLAG Mask             */
#define LPC_PMU_PCON_SLEEPFLAG_SHIFT             (8U)                                                /**< LPC_PMU_PCON.SLEEPFLAG Position         */
#define LPC_PMU_PCON_SLEEPFLAG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PMU_PCON_SLEEPFLAG_SHIFT))&LPC_PMU_PCON_SLEEPFLAG_MASK) /**< LPC_PMU_PCON.SLEEPFLAG Field            */
#define LPC_PMU_PCON_DPDFLAG_MASK                (0x800U)                                            /**< LPC_PMU_PCON.DPDFLAG Mask               */
#define LPC_PMU_PCON_DPDFLAG_SHIFT               (11U)                                               /**< LPC_PMU_PCON.DPDFLAG Position           */
#define LPC_PMU_PCON_DPDFLAG(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_PMU_PCON_DPDFLAG_SHIFT))&LPC_PMU_PCON_DPDFLAG_MASK) /**< LPC_PMU_PCON.DPDFLAG Field              */
/** @} */

/** @name GPREG - General purpose register %s */ /** @{ */
#define LPC_PMU_GPREG_GPDATA_MASK                (0xFFFFFFFFU)                                       /**< LPC_PMU_GPREG.GPDATA Mask               */
#define LPC_PMU_GPREG_GPDATA_SHIFT               (0U)                                                /**< LPC_PMU_GPREG.GPDATA Position           */
#define LPC_PMU_GPREG_GPDATA(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_PMU_GPREG_GPDATA_SHIFT))&LPC_PMU_GPREG_GPDATA_MASK) /**< LPC_PMU_GPREG.GPDATA Field              */
/** @} */

/** @name GPREG4 - General purpose register 4 */ /** @{ */
#define LPC_PMU_GPREG4_WAKEUPHYS_MASK            (0x400U)                                            /**< LPC_PMU_GPREG4.WAKEUPHYS Mask           */
#define LPC_PMU_GPREG4_WAKEUPHYS_SHIFT           (10U)                                               /**< LPC_PMU_GPREG4.WAKEUPHYS Position       */
#define LPC_PMU_GPREG4_WAKEUPHYS(x)              (((uint32_t)(((uint32_t)(x))<<LPC_PMU_GPREG4_WAKEUPHYS_SHIFT))&LPC_PMU_GPREG4_WAKEUPHYS_MASK) /**< LPC_PMU_GPREG4.WAKEUPHYS Field          */
#define LPC_PMU_GPREG4_GPDATA_MASK               (0xFFFFF800U)                                       /**< LPC_PMU_GPREG4.GPDATA Mask              */
#define LPC_PMU_GPREG4_GPDATA_SHIFT              (11U)                                               /**< LPC_PMU_GPREG4.GPDATA Position          */
#define LPC_PMU_GPREG4_GPDATA(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_PMU_GPREG4_GPDATA_SHIFT))&LPC_PMU_GPREG4_GPDATA_MASK) /**< LPC_PMU_GPREG4.GPDATA Field             */
/** @} */

/** @} */ /* End group PMU_Register_Masks_GROUP */


/* LPC_PMU - Peripheral instance base addresses */
#define LPC_PMU_BasePtr                0x40038000UL //!< Peripheral base address
#define LPC_PMU                        ((LPC_PMU_Type *) LPC_PMU_BasePtr) //!< Freescale base pointer
#define LPC_PMU_BASE_PTR               (LPC_PMU) //!< Freescale style base pointer

/** @} */ /* End group PMU_Peripheral_access_layer_GROUP */


/** @brief C Struct for SSP0 */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SSP0_Peripheral_access_layer_GROUP SSP0 Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_SSP0 (file:SSP0_LPC11Uxx)        ================ */
/* ================================================================================ */

/**
 * @brief SSP/SPI
 */
/**
 * @struct LPC_SSP0_Type
 * @brief  C Struct allowing access to SSP0 registers
 */
typedef struct LPC_SSP0_Type {
   __IO uint32_t  CR0;                          /**< 0000: Control Register 0. Selects the serial clock rate, bus type, and data size */
   __IO uint32_t  CR1;                          /**< 0004: Control Register 1. Selects master/slave and other modes     */
   __IO uint32_t  DR;                           /**< 0008: Data Register. Writes fill the transmit FIFO, and reads empty the receive FIFO */
   __I  uint32_t  SR;                           /**< 000C: Status Register                                              */
   __IO uint32_t  CPSR;                         /**< 0010: Clock Prescale Register                                      */
   __IO uint32_t  IMSC;                         /**< 0014: Interrupt Mask Set and Clear Register                        */
   __I  uint32_t  RIS;                          /**< 0018: Raw Interrupt Status Register                                */
   __I  uint32_t  MIS;                          /**< 001C: Masked Interrupt Status Register                             */
   __O  uint32_t  ICR;                          /**< 0020: SSPICR Interrupt Clear Register                              */
} LPC_SSP0_Type;


/** @brief Register Masks for SSP0 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_SSP0' Position & Mask macros                    ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SSP0_Register_Masks_GROUP SSP0 Register Masks */
/** @{ */

/** @name CR0 - Control Register 0. Selects the serial clock rate, bus type, and data size */ /** @{ */
#define LPC_SSP0_CR0_DSS_MASK                    (0xFU)                                              /**< LPC_SSP0_CR0.DSS Mask                   */
#define LPC_SSP0_CR0_DSS_SHIFT                   (0U)                                                /**< LPC_SSP0_CR0.DSS Position               */
#define LPC_SSP0_CR0_DSS(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR0_DSS_SHIFT))&LPC_SSP0_CR0_DSS_MASK) /**< LPC_SSP0_CR0.DSS Field                  */
#define LPC_SSP0_CR0_FRF_MASK                    (0x30U)                                             /**< LPC_SSP0_CR0.FRF Mask                   */
#define LPC_SSP0_CR0_FRF_SHIFT                   (4U)                                                /**< LPC_SSP0_CR0.FRF Position               */
#define LPC_SSP0_CR0_FRF(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR0_FRF_SHIFT))&LPC_SSP0_CR0_FRF_MASK) /**< LPC_SSP0_CR0.FRF Field                  */
#define LPC_SSP0_CR0_CPOL_MASK                   (0x40U)                                             /**< LPC_SSP0_CR0.CPOL Mask                  */
#define LPC_SSP0_CR0_CPOL_SHIFT                  (6U)                                                /**< LPC_SSP0_CR0.CPOL Position              */
#define LPC_SSP0_CR0_CPOL(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR0_CPOL_SHIFT))&LPC_SSP0_CR0_CPOL_MASK) /**< LPC_SSP0_CR0.CPOL Field                 */
#define LPC_SSP0_CR0_CPHA_MASK                   (0x80U)                                             /**< LPC_SSP0_CR0.CPHA Mask                  */
#define LPC_SSP0_CR0_CPHA_SHIFT                  (7U)                                                /**< LPC_SSP0_CR0.CPHA Position              */
#define LPC_SSP0_CR0_CPHA(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR0_CPHA_SHIFT))&LPC_SSP0_CR0_CPHA_MASK) /**< LPC_SSP0_CR0.CPHA Field                 */
#define LPC_SSP0_CR0_SCR_MASK                    (0xFF00U)                                           /**< LPC_SSP0_CR0.SCR Mask                   */
#define LPC_SSP0_CR0_SCR_SHIFT                   (8U)                                                /**< LPC_SSP0_CR0.SCR Position               */
#define LPC_SSP0_CR0_SCR(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR0_SCR_SHIFT))&LPC_SSP0_CR0_SCR_MASK) /**< LPC_SSP0_CR0.SCR Field                  */
/** @} */

/** @name CR1 - Control Register 1. Selects master/slave and other modes */ /** @{ */
#define LPC_SSP0_CR1_LBM_MASK                    (0x1U)                                              /**< LPC_SSP0_CR1.LBM Mask                   */
#define LPC_SSP0_CR1_LBM_SHIFT                   (0U)                                                /**< LPC_SSP0_CR1.LBM Position               */
#define LPC_SSP0_CR1_LBM(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR1_LBM_SHIFT))&LPC_SSP0_CR1_LBM_MASK) /**< LPC_SSP0_CR1.LBM Field                  */
#define LPC_SSP0_CR1_SSE_MASK                    (0x2U)                                              /**< LPC_SSP0_CR1.SSE Mask                   */
#define LPC_SSP0_CR1_SSE_SHIFT                   (1U)                                                /**< LPC_SSP0_CR1.SSE Position               */
#define LPC_SSP0_CR1_SSE(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR1_SSE_SHIFT))&LPC_SSP0_CR1_SSE_MASK) /**< LPC_SSP0_CR1.SSE Field                  */
#define LPC_SSP0_CR1_MS_MASK                     (0x4U)                                              /**< LPC_SSP0_CR1.MS Mask                    */
#define LPC_SSP0_CR1_MS_SHIFT                    (2U)                                                /**< LPC_SSP0_CR1.MS Position                */
#define LPC_SSP0_CR1_MS(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR1_MS_SHIFT))&LPC_SSP0_CR1_MS_MASK) /**< LPC_SSP0_CR1.MS Field                   */
#define LPC_SSP0_CR1_SOD_MASK                    (0x8U)                                              /**< LPC_SSP0_CR1.SOD Mask                   */
#define LPC_SSP0_CR1_SOD_SHIFT                   (3U)                                                /**< LPC_SSP0_CR1.SOD Position               */
#define LPC_SSP0_CR1_SOD(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CR1_SOD_SHIFT))&LPC_SSP0_CR1_SOD_MASK) /**< LPC_SSP0_CR1.SOD Field                  */
/** @} */

/** @name DR - Data Register. Writes fill the transmit FIFO, and reads empty the receive FIFO */ /** @{ */
#define LPC_SSP0_DR_DATA_MASK                    (0xFFFFU)                                           /**< LPC_SSP0_DR.DATA Mask                   */
#define LPC_SSP0_DR_DATA_SHIFT                   (0U)                                                /**< LPC_SSP0_DR.DATA Position               */
#define LPC_SSP0_DR_DATA(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_DR_DATA_SHIFT))&LPC_SSP0_DR_DATA_MASK) /**< LPC_SSP0_DR.DATA Field                  */
/** @} */

/** @name SR - Status Register */ /** @{ */
#define LPC_SSP0_SR_TFE_MASK                     (0x1U)                                              /**< LPC_SSP0_SR.TFE Mask                    */
#define LPC_SSP0_SR_TFE_SHIFT                    (0U)                                                /**< LPC_SSP0_SR.TFE Position                */
#define LPC_SSP0_SR_TFE(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_SR_TFE_SHIFT))&LPC_SSP0_SR_TFE_MASK) /**< LPC_SSP0_SR.TFE Field                   */
#define LPC_SSP0_SR_TNF_MASK                     (0x2U)                                              /**< LPC_SSP0_SR.TNF Mask                    */
#define LPC_SSP0_SR_TNF_SHIFT                    (1U)                                                /**< LPC_SSP0_SR.TNF Position                */
#define LPC_SSP0_SR_TNF(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_SR_TNF_SHIFT))&LPC_SSP0_SR_TNF_MASK) /**< LPC_SSP0_SR.TNF Field                   */
#define LPC_SSP0_SR_RNE_MASK                     (0x4U)                                              /**< LPC_SSP0_SR.RNE Mask                    */
#define LPC_SSP0_SR_RNE_SHIFT                    (2U)                                                /**< LPC_SSP0_SR.RNE Position                */
#define LPC_SSP0_SR_RNE(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_SR_RNE_SHIFT))&LPC_SSP0_SR_RNE_MASK) /**< LPC_SSP0_SR.RNE Field                   */
#define LPC_SSP0_SR_RFF_MASK                     (0x8U)                                              /**< LPC_SSP0_SR.RFF Mask                    */
#define LPC_SSP0_SR_RFF_SHIFT                    (3U)                                                /**< LPC_SSP0_SR.RFF Position                */
#define LPC_SSP0_SR_RFF(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_SR_RFF_SHIFT))&LPC_SSP0_SR_RFF_MASK) /**< LPC_SSP0_SR.RFF Field                   */
#define LPC_SSP0_SR_BSY_MASK                     (0x10U)                                             /**< LPC_SSP0_SR.BSY Mask                    */
#define LPC_SSP0_SR_BSY_SHIFT                    (4U)                                                /**< LPC_SSP0_SR.BSY Position                */
#define LPC_SSP0_SR_BSY(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_SR_BSY_SHIFT))&LPC_SSP0_SR_BSY_MASK) /**< LPC_SSP0_SR.BSY Field                   */
/** @} */

/** @name CPSR - Clock Prescale Register */ /** @{ */
#define LPC_SSP0_CPSR_CPSDVSR_MASK               (0xFFU)                                             /**< LPC_SSP0_CPSR.CPSDVSR Mask              */
#define LPC_SSP0_CPSR_CPSDVSR_SHIFT              (0U)                                                /**< LPC_SSP0_CPSR.CPSDVSR Position          */
#define LPC_SSP0_CPSR_CPSDVSR(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_CPSR_CPSDVSR_SHIFT))&LPC_SSP0_CPSR_CPSDVSR_MASK) /**< LPC_SSP0_CPSR.CPSDVSR Field             */
/** @} */

/** @name IMSC - Interrupt Mask Set and Clear Register */ /** @{ */
#define LPC_SSP0_IMSC_RORIM_MASK                 (0x1U)                                              /**< LPC_SSP0_IMSC.RORIM Mask                */
#define LPC_SSP0_IMSC_RORIM_SHIFT                (0U)                                                /**< LPC_SSP0_IMSC.RORIM Position            */
#define LPC_SSP0_IMSC_RORIM(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_IMSC_RORIM_SHIFT))&LPC_SSP0_IMSC_RORIM_MASK) /**< LPC_SSP0_IMSC.RORIM Field               */
#define LPC_SSP0_IMSC_RTIM_MASK                  (0x2U)                                              /**< LPC_SSP0_IMSC.RTIM Mask                 */
#define LPC_SSP0_IMSC_RTIM_SHIFT                 (1U)                                                /**< LPC_SSP0_IMSC.RTIM Position             */
#define LPC_SSP0_IMSC_RTIM(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_IMSC_RTIM_SHIFT))&LPC_SSP0_IMSC_RTIM_MASK) /**< LPC_SSP0_IMSC.RTIM Field                */
#define LPC_SSP0_IMSC_RXIM_MASK                  (0x4U)                                              /**< LPC_SSP0_IMSC.RXIM Mask                 */
#define LPC_SSP0_IMSC_RXIM_SHIFT                 (2U)                                                /**< LPC_SSP0_IMSC.RXIM Position             */
#define LPC_SSP0_IMSC_RXIM(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_IMSC_RXIM_SHIFT))&LPC_SSP0_IMSC_RXIM_MASK) /**< LPC_SSP0_IMSC.RXIM Field                */
#define LPC_SSP0_IMSC_TXIM_MASK                  (0x8U)                                              /**< LPC_SSP0_IMSC.TXIM Mask                 */
#define LPC_SSP0_IMSC_TXIM_SHIFT                 (3U)                                                /**< LPC_SSP0_IMSC.TXIM Position             */
#define LPC_SSP0_IMSC_TXIM(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_IMSC_TXIM_SHIFT))&LPC_SSP0_IMSC_TXIM_MASK) /**< LPC_SSP0_IMSC.TXIM Field                */
/** @} */

/** @name RIS - Raw Interrupt Status Register */ /** @{ */
#define LPC_SSP0_RIS_RORRIS_MASK                 (0x1U)                                              /**< LPC_SSP0_RIS.RORRIS Mask                */
#define LPC_SSP0_RIS_RORRIS_SHIFT                (0U)                                                /**< LPC_SSP0_RIS.RORRIS Position            */
#define LPC_SSP0_RIS_RORRIS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_RIS_RORRIS_SHIFT))&LPC_SSP0_RIS_RORRIS_MASK) /**< LPC_SSP0_RIS.RORRIS Field               */
#define LPC_SSP0_RIS_RTRIS_MASK                  (0x2U)                                              /**< LPC_SSP0_RIS.RTRIS Mask                 */
#define LPC_SSP0_RIS_RTRIS_SHIFT                 (1U)                                                /**< LPC_SSP0_RIS.RTRIS Position             */
#define LPC_SSP0_RIS_RTRIS(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_RIS_RTRIS_SHIFT))&LPC_SSP0_RIS_RTRIS_MASK) /**< LPC_SSP0_RIS.RTRIS Field                */
#define LPC_SSP0_RIS_RXRIS_MASK                  (0x4U)                                              /**< LPC_SSP0_RIS.RXRIS Mask                 */
#define LPC_SSP0_RIS_RXRIS_SHIFT                 (2U)                                                /**< LPC_SSP0_RIS.RXRIS Position             */
#define LPC_SSP0_RIS_RXRIS(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_RIS_RXRIS_SHIFT))&LPC_SSP0_RIS_RXRIS_MASK) /**< LPC_SSP0_RIS.RXRIS Field                */
#define LPC_SSP0_RIS_TXRIS_MASK                  (0x8U)                                              /**< LPC_SSP0_RIS.TXRIS Mask                 */
#define LPC_SSP0_RIS_TXRIS_SHIFT                 (3U)                                                /**< LPC_SSP0_RIS.TXRIS Position             */
#define LPC_SSP0_RIS_TXRIS(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_RIS_TXRIS_SHIFT))&LPC_SSP0_RIS_TXRIS_MASK) /**< LPC_SSP0_RIS.TXRIS Field                */
/** @} */

/** @name MIS - Masked Interrupt Status Register */ /** @{ */
#define LPC_SSP0_MIS_RORMIS_MASK                 (0x1U)                                              /**< LPC_SSP0_MIS.RORMIS Mask                */
#define LPC_SSP0_MIS_RORMIS_SHIFT                (0U)                                                /**< LPC_SSP0_MIS.RORMIS Position            */
#define LPC_SSP0_MIS_RORMIS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_MIS_RORMIS_SHIFT))&LPC_SSP0_MIS_RORMIS_MASK) /**< LPC_SSP0_MIS.RORMIS Field               */
#define LPC_SSP0_MIS_RTMIS_MASK                  (0x2U)                                              /**< LPC_SSP0_MIS.RTMIS Mask                 */
#define LPC_SSP0_MIS_RTMIS_SHIFT                 (1U)                                                /**< LPC_SSP0_MIS.RTMIS Position             */
#define LPC_SSP0_MIS_RTMIS(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_MIS_RTMIS_SHIFT))&LPC_SSP0_MIS_RTMIS_MASK) /**< LPC_SSP0_MIS.RTMIS Field                */
#define LPC_SSP0_MIS_RXMIS_MASK                  (0x4U)                                              /**< LPC_SSP0_MIS.RXMIS Mask                 */
#define LPC_SSP0_MIS_RXMIS_SHIFT                 (2U)                                                /**< LPC_SSP0_MIS.RXMIS Position             */
#define LPC_SSP0_MIS_RXMIS(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_MIS_RXMIS_SHIFT))&LPC_SSP0_MIS_RXMIS_MASK) /**< LPC_SSP0_MIS.RXMIS Field                */
#define LPC_SSP0_MIS_TXMIS_MASK                  (0x8U)                                              /**< LPC_SSP0_MIS.TXMIS Mask                 */
#define LPC_SSP0_MIS_TXMIS_SHIFT                 (3U)                                                /**< LPC_SSP0_MIS.TXMIS Position             */
#define LPC_SSP0_MIS_TXMIS(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_MIS_TXMIS_SHIFT))&LPC_SSP0_MIS_TXMIS_MASK) /**< LPC_SSP0_MIS.TXMIS Field                */
/** @} */

/** @name ICR - SSPICR Interrupt Clear Register */ /** @{ */
#define LPC_SSP0_ICR_RORIC_MASK                  (0x1U)                                              /**< LPC_SSP0_ICR.RORIC Mask                 */
#define LPC_SSP0_ICR_RORIC_SHIFT                 (0U)                                                /**< LPC_SSP0_ICR.RORIC Position             */
#define LPC_SSP0_ICR_RORIC(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_ICR_RORIC_SHIFT))&LPC_SSP0_ICR_RORIC_MASK) /**< LPC_SSP0_ICR.RORIC Field                */
#define LPC_SSP0_ICR_RTIC_MASK                   (0x2U)                                              /**< LPC_SSP0_ICR.RTIC Mask                  */
#define LPC_SSP0_ICR_RTIC_SHIFT                  (1U)                                                /**< LPC_SSP0_ICR.RTIC Position              */
#define LPC_SSP0_ICR_RTIC(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SSP0_ICR_RTIC_SHIFT))&LPC_SSP0_ICR_RTIC_MASK) /**< LPC_SSP0_ICR.RTIC Field                 */
/** @} */

/** @} */ /* End group SSP0_Register_Masks_GROUP */


/* LPC_SSP0 - Peripheral instance base addresses */
#define LPC_SSP0_BasePtr               0x40040000UL //!< Peripheral base address
#define LPC_SSP0                       ((LPC_SSP0_Type *) LPC_SSP0_BasePtr) //!< Freescale base pointer
#define LPC_SSP0_BASE_PTR              (LPC_SSP0) //!< Freescale style base pointer

/** @} */ /* End group SSP0_Peripheral_access_layer_GROUP */


/** @brief C Struct for SSP0 */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SSP0_Peripheral_access_layer_GROUP SSP0 Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_SSP1 (derived from SSP0)         ================ */
/* ================================================================================ */

/**
 * @brief SSP/SPI
 */

/* LPC_SSP1 - Peripheral instance base addresses */
#define LPC_SSP1_BasePtr               0x40058000UL //!< Peripheral base address
#define LPC_SSP1                       ((LPC_SSP0_Type *) LPC_SSP1_BasePtr) //!< Freescale base pointer
#define LPC_SSP1_BASE_PTR              (LPC_SSP1) //!< Freescale style base pointer

/** @} */ /* End group SSP0_Peripheral_access_layer_GROUP */


/** @brief C Struct for SYSCON */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup SYSCON_Peripheral_access_layer_GROUP SYSCON Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_SYSCON (file:SYSCON_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief System control block
 */
/**
 * @struct LPC_SYSCON_Type
 * @brief  C Struct allowing access to SYSCON registers
 */
typedef struct LPC_SYSCON_Type {
   __IO uint32_t  SYSMEMREMAP;                  /**< 0000: System memory remap                                          */
   __IO uint32_t  PRESETCTRL;                   /**< 0004: Peripheral reset control                                     */
   __IO uint32_t  SYSPLLCTRL;                   /**< 0008: System PLL control                                           */
   __I  uint32_t  SYSPLLSTAT;                   /**< 000C: System PLL status                                            */
   __IO uint32_t  USBPLLCTRL;                   /**< 0010: USB PLL control                                              */
   __I  uint32_t  USBPLLSTAT;                   /**< 0014: USB PLL status                                               */
        uint8_t   RESERVED_0[8];                /**< 0018: 0x8 bytes                                                    */
   __IO uint32_t  SYSOSCCTRL;                   /**< 0020: System oscillator control                                    */
   __IO uint32_t  WDTOSCCTRL;                   /**< 0024: Watchdog oscillator control                                  */
        uint8_t   RESERVED_1[8];                /**< 0028: 0x8 bytes                                                    */
   __IO uint32_t  SYSRSTSTAT;                   /**< 0030: System reset status register                                 */
        uint8_t   RESERVED_2[12];               /**< 0034: 0xC bytes                                                    */
   __IO uint32_t  SYSPLLCLKSEL;                 /**< 0040: System PLL clock source select                               */
   __IO uint32_t  SYSPLLCLKUEN;                 /**< 0044: System PLL clock source update enable                        */
   __IO uint32_t  USBPLLCLKSEL;                 /**< 0048: USB PLL clock source select                                  */
   __IO uint32_t  USBPLLCLKUEN;                 /**< 004C: USB PLL clock source update enable                           */
        uint8_t   RESERVED_3[32];               /**< 0050: 0x20 bytes                                                   */
   __IO uint32_t  MAINCLKSEL;                   /**< 0070: Main clock source select                                     */
   __IO uint32_t  MAINCLKUEN;                   /**< 0074: Main clock source update enable                              */
   __IO uint32_t  SYSAHBCLKDIV;                 /**< 0078: System clock divider                                         */
        uint8_t   RESERVED_4[4];                /**< 007C: 0x4 bytes                                                    */
   __IO uint32_t  SYSAHBCLKCTRL;                /**< 0080: System clock control                                         */
        uint8_t   RESERVED_5[16];               /**< 0084: 0x10 bytes                                                   */
   __IO uint32_t  SSP0CLKDIV;                   /**< 0094: SSP0 clock divider                                           */
   __IO uint32_t  UARTCLKDIV;                   /**< 0098: UART clock divider                                           */
   __IO uint32_t  SSP1CLKDIV;                   /**< 009C: SSP1 clock divider                                           */
        uint8_t   RESERVED_6[32];               /**< 00A0: 0x20 bytes                                                   */
   __IO uint32_t  USBCLKSEL;                    /**< 00C0: USB clock source select                                      */
   __IO uint32_t  USBCLKUEN;                    /**< 00C4: USB clock source update enable                               */
   __IO uint32_t  USBCLKDIV;                    /**< 00C8: USB clock source divider                                     */
        uint8_t   RESERVED_7[20];               /**< 00CC: 0x14 bytes                                                   */
   __IO uint32_t  CLKOUTSEL;                    /**< 00E0: CLKOUT clock source select                                   */
   __IO uint32_t  CLKOUTUEN;                    /**< 00E4: CLKOUT clock source update enable                            */
   __IO uint32_t  CLKOUTDIV;                    /**< 00E8: CLKOUT clock divider                                         */
        uint8_t   RESERVED_8[20];               /**< 00EC: 0x14 bytes                                                   */
   __I  uint32_t  PIOPORCAP0;                   /**< 0100: POR captured PIO status 0                                    */
   __I  uint32_t  PIOPORCAP1;                   /**< 0104: POR captured PIO status 1                                    */
        uint8_t   RESERVED_9[72];               /**< 0108: 0x48 bytes                                                   */
   __IO uint32_t  BODCTRL;                      /**< 0150: Brown-Out Detect                                             */
   __IO uint32_t  SYSTCKCAL;                    /**< 0154: System tick counter calibration                              */
        uint8_t   RESERVED_10[24];              /**< 0158: 0x18 bytes                                                   */
   __IO uint32_t  IRQLATENCY;                   /**< 0170: IQR delay. Allows trade-off between interrupt latency and determinism */
   __IO uint32_t  NMISRC;                       /**< 0174: NMI Source Control                                           */
   __IO uint32_t  PINTSEL[8];                   /**< 0178: GPIO Pin Interrupt Select register %                         */
   __IO uint32_t  USBCLKCTRL;                   /**< 0198: USB clock control                                            */
   __I  uint32_t  USBCLKST;                     /**< 019C: USB clock status                                             */
        uint8_t   RESERVED_11[100];             /**< 01A0: 0x64 bytes                                                   */
   __IO uint32_t  STARTERP0;                    /**< 0204: Start logic 0 interrupt wake-up enable register 0            */
        uint8_t   RESERVED_12[12];              /**< 0208: 0xC bytes                                                    */
   __IO uint32_t  STARTERP1;                    /**< 0214: Start logic 1 interrupt wake-up enable register 1            */
        uint8_t   RESERVED_13[24];              /**< 0218: 0x18 bytes                                                   */
   __IO uint32_t  PDSLEEPCFG;                   /**< 0230: Power-down states in deep-sleep mode                         */
   __IO uint32_t  PDAWAKECFG;                   /**< 0234: Power-down states for wake-up from deep-sleep                */
   __IO uint32_t  PDRUNCFG;                     /**< 0238: Power configuration register                                 */
        uint8_t   RESERVED_14[440];             /**< 023C: 0x1B8 bytes                                                  */
   __I  uint32_t  DEVICE_ID;                    /**< 03F4: Device ID                                                    */
} LPC_SYSCON_Type;


/** @brief Register Masks for SYSCON */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_SYSCON' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup SYSCON_Register_Masks_GROUP SYSCON Register Masks */
/** @{ */

/** @name SYSMEMREMAP - System memory remap */ /** @{ */
#define LPC_SYSCON_SYSMEMREMAP_MAP_MASK          (0x3U)                                              /**< LPC_SYSCON_SYSMEMREMAP.MAP Mask         */
#define LPC_SYSCON_SYSMEMREMAP_MAP_SHIFT         (0U)                                                /**< LPC_SYSCON_SYSMEMREMAP.MAP Position     */
#define LPC_SYSCON_SYSMEMREMAP_MAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSMEMREMAP_MAP_SHIFT))&LPC_SYSCON_SYSMEMREMAP_MAP_MASK) /**< LPC_SYSCON_SYSMEMREMAP.MAP Field        */
/** @} */

/** @name PRESETCTRL - Peripheral reset control */ /** @{ */
#define LPC_SYSCON_PRESETCTRL_SSP0_RST_N_MASK    (0x1U)                                              /**< LPC_SYSCON_PRESETCTRL.SSP0_RST_N Mask   */
#define LPC_SYSCON_PRESETCTRL_SSP0_RST_N_SHIFT   (0U)                                                /**< LPC_SYSCON_PRESETCTRL.SSP0_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_SSP0_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_SSP0_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_SSP0_RST_N_MASK) /**< LPC_SYSCON_PRESETCTRL.SSP0_RST_N Field  */
#define LPC_SYSCON_PRESETCTRL_I2C_RST_N_MASK     (0x2U)                                              /**< LPC_SYSCON_PRESETCTRL.I2C_RST_N Mask    */
#define LPC_SYSCON_PRESETCTRL_I2C_RST_N_SHIFT    (1U)                                                /**< LPC_SYSCON_PRESETCTRL.I2C_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_I2C_RST_N(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_I2C_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_I2C_RST_N_MASK) /**< LPC_SYSCON_PRESETCTRL.I2C_RST_N Field   */
#define LPC_SYSCON_PRESETCTRL_SSP1_RST_N_MASK    (0x4U)                                              /**< LPC_SYSCON_PRESETCTRL.SSP1_RST_N Mask   */
#define LPC_SYSCON_PRESETCTRL_SSP1_RST_N_SHIFT   (2U)                                                /**< LPC_SYSCON_PRESETCTRL.SSP1_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_SSP1_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_SSP1_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_SSP1_RST_N_MASK) /**< LPC_SYSCON_PRESETCTRL.SSP1_RST_N Field  */
/** @} */

/** @name SYSPLLCTRL - System PLL control */ /** @{ */
#define LPC_SYSCON_SYSPLLCTRL_MSEL_MASK          (0x1FU)                                             /**< LPC_SYSCON_SYSPLLCTRL.MSEL Mask         */
#define LPC_SYSCON_SYSPLLCTRL_MSEL_SHIFT         (0U)                                                /**< LPC_SYSCON_SYSPLLCTRL.MSEL Position     */
#define LPC_SYSCON_SYSPLLCTRL_MSEL(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLCTRL_MSEL_SHIFT))&LPC_SYSCON_SYSPLLCTRL_MSEL_MASK) /**< LPC_SYSCON_SYSPLLCTRL.MSEL Field        */
#define LPC_SYSCON_SYSPLLCTRL_PSEL_MASK          (0x60U)                                             /**< LPC_SYSCON_SYSPLLCTRL.PSEL Mask         */
#define LPC_SYSCON_SYSPLLCTRL_PSEL_SHIFT         (5U)                                                /**< LPC_SYSCON_SYSPLLCTRL.PSEL Position     */
#define LPC_SYSCON_SYSPLLCTRL_PSEL(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLCTRL_PSEL_SHIFT))&LPC_SYSCON_SYSPLLCTRL_PSEL_MASK) /**< LPC_SYSCON_SYSPLLCTRL.PSEL Field        */
/** @} */

/** @name SYSPLLSTAT - System PLL status */ /** @{ */
#define LPC_SYSCON_SYSPLLSTAT_LOCK_MASK          (0x1U)                                              /**< LPC_SYSCON_SYSPLLSTAT.LOCK Mask         */
#define LPC_SYSCON_SYSPLLSTAT_LOCK_SHIFT         (0U)                                                /**< LPC_SYSCON_SYSPLLSTAT.LOCK Position     */
#define LPC_SYSCON_SYSPLLSTAT_LOCK(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLSTAT_LOCK_SHIFT))&LPC_SYSCON_SYSPLLSTAT_LOCK_MASK) /**< LPC_SYSCON_SYSPLLSTAT.LOCK Field        */
/** @} */

/** @name USBPLLCTRL - USB PLL control */ /** @{ */
#define LPC_SYSCON_USBPLLCTRL_MSEL_MASK          (0x1FU)                                             /**< LPC_SYSCON_USBPLLCTRL.MSEL Mask         */
#define LPC_SYSCON_USBPLLCTRL_MSEL_SHIFT         (0U)                                                /**< LPC_SYSCON_USBPLLCTRL.MSEL Position     */
#define LPC_SYSCON_USBPLLCTRL_MSEL(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBPLLCTRL_MSEL_SHIFT))&LPC_SYSCON_USBPLLCTRL_MSEL_MASK) /**< LPC_SYSCON_USBPLLCTRL.MSEL Field        */
#define LPC_SYSCON_USBPLLCTRL_PSEL_MASK          (0x60U)                                             /**< LPC_SYSCON_USBPLLCTRL.PSEL Mask         */
#define LPC_SYSCON_USBPLLCTRL_PSEL_SHIFT         (5U)                                                /**< LPC_SYSCON_USBPLLCTRL.PSEL Position     */
#define LPC_SYSCON_USBPLLCTRL_PSEL(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBPLLCTRL_PSEL_SHIFT))&LPC_SYSCON_USBPLLCTRL_PSEL_MASK) /**< LPC_SYSCON_USBPLLCTRL.PSEL Field        */
/** @} */

/** @name USBPLLSTAT - USB PLL status */ /** @{ */
#define LPC_SYSCON_USBPLLSTAT_LOCK_MASK          (0x1U)                                              /**< LPC_SYSCON_USBPLLSTAT.LOCK Mask         */
#define LPC_SYSCON_USBPLLSTAT_LOCK_SHIFT         (0U)                                                /**< LPC_SYSCON_USBPLLSTAT.LOCK Position     */
#define LPC_SYSCON_USBPLLSTAT_LOCK(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBPLLSTAT_LOCK_SHIFT))&LPC_SYSCON_USBPLLSTAT_LOCK_MASK) /**< LPC_SYSCON_USBPLLSTAT.LOCK Field        */
/** @} */

/** @name SYSOSCCTRL - System oscillator control */ /** @{ */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS_MASK        (0x1U)                                              /**< LPC_SYSCON_SYSOSCCTRL.BYPASS Mask       */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS_SHIFT       (0U)                                                /**< LPC_SYSCON_SYSOSCCTRL.BYPASS Position   */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSOSCCTRL_BYPASS_SHIFT))&LPC_SYSCON_SYSOSCCTRL_BYPASS_MASK) /**< LPC_SYSCON_SYSOSCCTRL.BYPASS Field      */
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE_MASK     (0x2U)                                              /**< LPC_SYSCON_SYSOSCCTRL.FREQRANGE Mask    */
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT    (1U)                                                /**< LPC_SYSCON_SYSOSCCTRL.FREQRANGE Position*/
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT))&LPC_SYSCON_SYSOSCCTRL_FREQRANGE_MASK) /**< LPC_SYSCON_SYSOSCCTRL.FREQRANGE Field   */
/** @} */

/** @name WDTOSCCTRL - Watchdog oscillator control */ /** @{ */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL_MASK        (0x1FU)                                             /**< LPC_SYSCON_WDTOSCCTRL.DIVSEL Mask       */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL_SHIFT       (0U)                                                /**< LPC_SYSCON_WDTOSCCTRL.DIVSEL Position   */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_WDTOSCCTRL_DIVSEL_SHIFT))&LPC_SYSCON_WDTOSCCTRL_DIVSEL_MASK) /**< LPC_SYSCON_WDTOSCCTRL.DIVSEL Field      */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL_MASK       (0x1E0U)                                            /**< LPC_SYSCON_WDTOSCCTRL.FREQSEL Mask      */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL_SHIFT      (5U)                                                /**< LPC_SYSCON_WDTOSCCTRL.FREQSEL Position  */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_WDTOSCCTRL_FREQSEL_SHIFT))&LPC_SYSCON_WDTOSCCTRL_FREQSEL_MASK) /**< LPC_SYSCON_WDTOSCCTRL.FREQSEL Field     */
/** @} */

/** @name SYSRSTSTAT - System reset status register */ /** @{ */
#define LPC_SYSCON_SYSRSTSTAT_POR_MASK           (0x1U)                                              /**< LPC_SYSCON_SYSRSTSTAT.POR Mask          */
#define LPC_SYSCON_SYSRSTSTAT_POR_SHIFT          (0U)                                                /**< LPC_SYSCON_SYSRSTSTAT.POR Position      */
#define LPC_SYSCON_SYSRSTSTAT_POR(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_POR_SHIFT))&LPC_SYSCON_SYSRSTSTAT_POR_MASK) /**< LPC_SYSCON_SYSRSTSTAT.POR Field         */
#define LPC_SYSCON_SYSRSTSTAT_EXTRST_MASK        (0x2U)                                              /**< LPC_SYSCON_SYSRSTSTAT.EXTRST Mask       */
#define LPC_SYSCON_SYSRSTSTAT_EXTRST_SHIFT       (1U)                                                /**< LPC_SYSCON_SYSRSTSTAT.EXTRST Position   */
#define LPC_SYSCON_SYSRSTSTAT_EXTRST(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_EXTRST_SHIFT))&LPC_SYSCON_SYSRSTSTAT_EXTRST_MASK) /**< LPC_SYSCON_SYSRSTSTAT.EXTRST Field      */
#define LPC_SYSCON_SYSRSTSTAT_WDT_MASK           (0x4U)                                              /**< LPC_SYSCON_SYSRSTSTAT.WDT Mask          */
#define LPC_SYSCON_SYSRSTSTAT_WDT_SHIFT          (2U)                                                /**< LPC_SYSCON_SYSRSTSTAT.WDT Position      */
#define LPC_SYSCON_SYSRSTSTAT_WDT(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_WDT_SHIFT))&LPC_SYSCON_SYSRSTSTAT_WDT_MASK) /**< LPC_SYSCON_SYSRSTSTAT.WDT Field         */
#define LPC_SYSCON_SYSRSTSTAT_BOD_MASK           (0x8U)                                              /**< LPC_SYSCON_SYSRSTSTAT.BOD Mask          */
#define LPC_SYSCON_SYSRSTSTAT_BOD_SHIFT          (3U)                                                /**< LPC_SYSCON_SYSRSTSTAT.BOD Position      */
#define LPC_SYSCON_SYSRSTSTAT_BOD(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_BOD_SHIFT))&LPC_SYSCON_SYSRSTSTAT_BOD_MASK) /**< LPC_SYSCON_SYSRSTSTAT.BOD Field         */
#define LPC_SYSCON_SYSRSTSTAT_SYSRST_MASK        (0x10U)                                             /**< LPC_SYSCON_SYSRSTSTAT.SYSRST Mask       */
#define LPC_SYSCON_SYSRSTSTAT_SYSRST_SHIFT       (4U)                                                /**< LPC_SYSCON_SYSRSTSTAT.SYSRST Position   */
#define LPC_SYSCON_SYSRSTSTAT_SYSRST(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_SYSRST_SHIFT))&LPC_SYSCON_SYSRSTSTAT_SYSRST_MASK) /**< LPC_SYSCON_SYSRSTSTAT.SYSRST Field      */
/** @} */

/** @name SYSPLLCLKSEL - System PLL clock source select */ /** @{ */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL_MASK         (0x3U)                                              /**< LPC_SYSCON_SYSPLLCLKSEL.SEL Mask        */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL_SHIFT        (0U)                                                /**< LPC_SYSCON_SYSPLLCLKSEL.SEL Position    */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLCLKSEL_SEL_SHIFT))&LPC_SYSCON_SYSPLLCLKSEL_SEL_MASK) /**< LPC_SYSCON_SYSPLLCLKSEL.SEL Field       */
/** @} */

/** @name SYSPLLCLKUEN - System PLL clock source update enable */ /** @{ */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA_MASK         (0x1U)                                              /**< LPC_SYSCON_SYSPLLCLKUEN.ENA Mask        */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA_SHIFT        (0U)                                                /**< LPC_SYSCON_SYSPLLCLKUEN.ENA Position    */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLCLKUEN_ENA_SHIFT))&LPC_SYSCON_SYSPLLCLKUEN_ENA_MASK) /**< LPC_SYSCON_SYSPLLCLKUEN.ENA Field       */
/** @} */

/** @name USBPLLCLKSEL - USB PLL clock source select */ /** @{ */
#define LPC_SYSCON_USBPLLCLKSEL_SEL_MASK         (0x3U)                                              /**< LPC_SYSCON_USBPLLCLKSEL.SEL Mask        */
#define LPC_SYSCON_USBPLLCLKSEL_SEL_SHIFT        (0U)                                                /**< LPC_SYSCON_USBPLLCLKSEL.SEL Position    */
#define LPC_SYSCON_USBPLLCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBPLLCLKSEL_SEL_SHIFT))&LPC_SYSCON_USBPLLCLKSEL_SEL_MASK) /**< LPC_SYSCON_USBPLLCLKSEL.SEL Field       */
/** @} */

/** @name USBPLLCLKUEN - USB PLL clock source update enable */ /** @{ */
#define LPC_SYSCON_USBPLLCLKUEN_ENA_MASK         (0x1U)                                              /**< LPC_SYSCON_USBPLLCLKUEN.ENA Mask        */
#define LPC_SYSCON_USBPLLCLKUEN_ENA_SHIFT        (0U)                                                /**< LPC_SYSCON_USBPLLCLKUEN.ENA Position    */
#define LPC_SYSCON_USBPLLCLKUEN_ENA(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBPLLCLKUEN_ENA_SHIFT))&LPC_SYSCON_USBPLLCLKUEN_ENA_MASK) /**< LPC_SYSCON_USBPLLCLKUEN.ENA Field       */
/** @} */

/** @name MAINCLKSEL - Main clock source select */ /** @{ */
#define LPC_SYSCON_MAINCLKSEL_SEL_MASK           (0x3U)                                              /**< LPC_SYSCON_MAINCLKSEL.SEL Mask          */
#define LPC_SYSCON_MAINCLKSEL_SEL_SHIFT          (0U)                                                /**< LPC_SYSCON_MAINCLKSEL.SEL Position      */
#define LPC_SYSCON_MAINCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_MAINCLKSEL_SEL_SHIFT))&LPC_SYSCON_MAINCLKSEL_SEL_MASK) /**< LPC_SYSCON_MAINCLKSEL.SEL Field         */
/** @} */

/** @name MAINCLKUEN - Main clock source update enable */ /** @{ */
#define LPC_SYSCON_MAINCLKUEN_ENA_MASK           (0x1U)                                              /**< LPC_SYSCON_MAINCLKUEN.ENA Mask          */
#define LPC_SYSCON_MAINCLKUEN_ENA_SHIFT          (0U)                                                /**< LPC_SYSCON_MAINCLKUEN.ENA Position      */
#define LPC_SYSCON_MAINCLKUEN_ENA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_MAINCLKUEN_ENA_SHIFT))&LPC_SYSCON_MAINCLKUEN_ENA_MASK) /**< LPC_SYSCON_MAINCLKUEN.ENA Field         */
/** @} */

/** @name SYSAHBCLKDIV - System clock divider */ /** @{ */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV_MASK         (0xFFU)                                             /**< LPC_SYSCON_SYSAHBCLKDIV.DIV Mask        */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV_SHIFT        (0U)                                                /**< LPC_SYSCON_SYSAHBCLKDIV.DIV Position    */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKDIV_DIV_SHIFT))&LPC_SYSCON_SYSAHBCLKDIV_DIV_MASK) /**< LPC_SYSCON_SYSAHBCLKDIV.DIV Field       */
/** @} */

/** @name SYSAHBCLKCTRL - System clock control */ /** @{ */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS_MASK        (0x1U)                                              /**< LPC_SYSCON_SYSAHBCLKCTRL.SYS Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS_SHIFT       (0U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.SYS Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_SYS_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_SYS_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.SYS Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM_MASK        (0x2U)                                              /**< LPC_SYSCON_SYSAHBCLKCTRL.ROM Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM_SHIFT       (1U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.ROM Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_ROM_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_ROM_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.ROM Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM0_MASK       (0x4U)                                              /**< LPC_SYSCON_SYSAHBCLKCTRL.RAM0 Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM0_SHIFT      (2U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.RAM0 Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM0(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_RAM0_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_RAM0_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.RAM0 Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK   (0x8U)                                              /**< LPC_SYSCON_SYSAHBCLKCTRL.FLASHREG Mask  */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT  (3U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.FLASHREG Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG(x)     (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.FLASHREG Field */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK (0x10U)                                             /**< LPC_SYSCON_SYSAHBCLKCTRL.FLASHARRAY Mask*/
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHARRAY_SHIFT (4U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.FLASHARRAY Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHARRAY(x)   (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_FLASHARRAY_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.FLASHARRAY Field*/
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C_MASK        (0x20U)                                             /**< LPC_SYSCON_SYSAHBCLKCTRL.I2C Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C_SHIFT       (5U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.I2C Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_I2C_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_I2C_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.I2C Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO_MASK       (0x40U)                                             /**< LPC_SYSCON_SYSAHBCLKCTRL.GPIO Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT      (6U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.GPIO Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_GPIO_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.GPIO Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B0_MASK     (0x80U)                                             /**< LPC_SYSCON_SYSAHBCLKCTRL.CT16B0 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B0_SHIFT    (7U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.CT16B0 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B0(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_CT16B0_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_CT16B0_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.CT16B0 Field   */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B1_MASK     (0x100U)                                            /**< LPC_SYSCON_SYSAHBCLKCTRL.CT16B1 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B1_SHIFT    (8U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.CT16B1 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B1(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_CT16B1_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_CT16B1_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.CT16B1 Field   */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B0_MASK     (0x200U)                                            /**< LPC_SYSCON_SYSAHBCLKCTRL.CT32B0 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B0_SHIFT    (9U)                                                /**< LPC_SYSCON_SYSAHBCLKCTRL.CT32B0 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B0(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_CT32B0_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_CT32B0_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.CT32B0 Field   */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B1_MASK     (0x400U)                                            /**< LPC_SYSCON_SYSAHBCLKCTRL.CT32B1 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B1_SHIFT    (10U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.CT32B1 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B1(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_CT32B1_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_CT32B1_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.CT32B1 Field   */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP0_MASK       (0x800U)                                            /**< LPC_SYSCON_SYSAHBCLKCTRL.SSP0 Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP0_SHIFT      (11U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.SSP0 Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP0(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_SSP0_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_SSP0_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.SSP0 Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_USART_MASK      (0x1000U)                                           /**< LPC_SYSCON_SYSAHBCLKCTRL.USART Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_USART_SHIFT     (12U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.USART Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_USART(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_USART_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_USART_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.USART Field    */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC_MASK        (0x2000U)                                           /**< LPC_SYSCON_SYSAHBCLKCTRL.ADC Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC_SHIFT       (13U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.ADC Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_ADC_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_ADC_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.ADC Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_USB_MASK        (0x4000U)                                           /**< LPC_SYSCON_SYSAHBCLKCTRL.USB Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_USB_SHIFT       (14U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.USB Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_USB(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_USB_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_USB_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.USB Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_WWDT_MASK       (0x8000U)                                           /**< LPC_SYSCON_SYSAHBCLKCTRL.WWDT Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_WWDT_SHIFT      (15U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.WWDT Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_WWDT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_WWDT_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_WWDT_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.WWDT Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON_MASK      (0x10000U)                                          /**< LPC_SYSCON_SYSAHBCLKCTRL.IOCON Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT     (16U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.IOCON Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_IOCON_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.IOCON Field    */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP1_MASK       (0x40000U)                                          /**< LPC_SYSCON_SYSAHBCLKCTRL.SSP1 Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP1_SHIFT      (18U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.SSP1 Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP1(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_SSP1_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_SSP1_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.SSP1 Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_PINT_MASK       (0x80000U)                                          /**< LPC_SYSCON_SYSAHBCLKCTRL.PINT Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_PINT_SHIFT      (19U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.PINT Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_PINT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_PINT_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_PINT_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.PINT Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_GROUP0INT_MASK  (0x800000U)                                         /**< LPC_SYSCON_SYSAHBCLKCTRL.GROUP0INT Mask */
#define LPC_SYSCON_SYSAHBCLKCTRL_GROUP0INT_SHIFT (23U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.GROUP0INT Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_GROUP0INT(x)    (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_GROUP0INT_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_GROUP0INT_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.GROUP0INT Field*/
#define LPC_SYSCON_SYSAHBCLKCTRL_GROUP1INT_MASK  (0x1000000U)                                        /**< LPC_SYSCON_SYSAHBCLKCTRL.GROUP1INT Mask */
#define LPC_SYSCON_SYSAHBCLKCTRL_GROUP1INT_SHIFT (24U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.GROUP1INT Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_GROUP1INT(x)    (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_GROUP1INT_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_GROUP1INT_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.GROUP1INT Field*/
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM1_MASK       (0x4000000U)                                        /**< LPC_SYSCON_SYSAHBCLKCTRL.RAM1 Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM1_SHIFT      (26U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.RAM1 Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM1(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_RAM1_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_RAM1_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.RAM1 Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_USBRAM_MASK     (0x8000000U)                                        /**< LPC_SYSCON_SYSAHBCLKCTRL.USBRAM Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_USBRAM_SHIFT    (27U)                                               /**< LPC_SYSCON_SYSAHBCLKCTRL.USBRAM Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_USBRAM(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_USBRAM_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_USBRAM_MASK) /**< LPC_SYSCON_SYSAHBCLKCTRL.USBRAM Field   */
/** @} */

/** @name SSP0CLKDIV - SSP0 clock divider */ /** @{ */
#define LPC_SYSCON_SSP0CLKDIV_DIV_MASK           (0xFFU)                                             /**< LPC_SYSCON_SSP0CLKDIV.DIV Mask          */
#define LPC_SYSCON_SSP0CLKDIV_DIV_SHIFT          (0U)                                                /**< LPC_SYSCON_SSP0CLKDIV.DIV Position      */
#define LPC_SYSCON_SSP0CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SSP0CLKDIV_DIV_SHIFT))&LPC_SYSCON_SSP0CLKDIV_DIV_MASK) /**< LPC_SYSCON_SSP0CLKDIV.DIV Field         */
/** @} */

/** @name UARTCLKDIV - UART clock divider */ /** @{ */
#define LPC_SYSCON_UARTCLKDIV_DIV_MASK           (0xFFU)                                             /**< LPC_SYSCON_UARTCLKDIV.DIV Mask          */
#define LPC_SYSCON_UARTCLKDIV_DIV_SHIFT          (0U)                                                /**< LPC_SYSCON_UARTCLKDIV.DIV Position      */
#define LPC_SYSCON_UARTCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_UARTCLKDIV_DIV_SHIFT))&LPC_SYSCON_UARTCLKDIV_DIV_MASK) /**< LPC_SYSCON_UARTCLKDIV.DIV Field         */
/** @} */

/** @name SSP1CLKDIV - SSP1 clock divider */ /** @{ */
#define LPC_SYSCON_SSP1CLKDIV_DIV_MASK           (0xFFU)                                             /**< LPC_SYSCON_SSP1CLKDIV.DIV Mask          */
#define LPC_SYSCON_SSP1CLKDIV_DIV_SHIFT          (0U)                                                /**< LPC_SYSCON_SSP1CLKDIV.DIV Position      */
#define LPC_SYSCON_SSP1CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SSP1CLKDIV_DIV_SHIFT))&LPC_SYSCON_SSP1CLKDIV_DIV_MASK) /**< LPC_SYSCON_SSP1CLKDIV.DIV Field         */
/** @} */

/** @name USBCLKSEL - USB clock source select */ /** @{ */
#define LPC_SYSCON_USBCLKSEL_SEL_MASK            (0x3U)                                              /**< LPC_SYSCON_USBCLKSEL.SEL Mask           */
#define LPC_SYSCON_USBCLKSEL_SEL_SHIFT           (0U)                                                /**< LPC_SYSCON_USBCLKSEL.SEL Position       */
#define LPC_SYSCON_USBCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBCLKSEL_SEL_SHIFT))&LPC_SYSCON_USBCLKSEL_SEL_MASK) /**< LPC_SYSCON_USBCLKSEL.SEL Field          */
/** @} */

/** @name USBCLKUEN - USB clock source update enable */ /** @{ */
#define LPC_SYSCON_USBCLKUEN_ENA_MASK            (0x1U)                                              /**< LPC_SYSCON_USBCLKUEN.ENA Mask           */
#define LPC_SYSCON_USBCLKUEN_ENA_SHIFT           (0U)                                                /**< LPC_SYSCON_USBCLKUEN.ENA Position       */
#define LPC_SYSCON_USBCLKUEN_ENA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBCLKUEN_ENA_SHIFT))&LPC_SYSCON_USBCLKUEN_ENA_MASK) /**< LPC_SYSCON_USBCLKUEN.ENA Field          */
/** @} */

/** @name USBCLKDIV - USB clock source divider */ /** @{ */
#define LPC_SYSCON_USBCLKDIV_DIV_MASK            (0xFFU)                                             /**< LPC_SYSCON_USBCLKDIV.DIV Mask           */
#define LPC_SYSCON_USBCLKDIV_DIV_SHIFT           (0U)                                                /**< LPC_SYSCON_USBCLKDIV.DIV Position       */
#define LPC_SYSCON_USBCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBCLKDIV_DIV_SHIFT))&LPC_SYSCON_USBCLKDIV_DIV_MASK) /**< LPC_SYSCON_USBCLKDIV.DIV Field          */
/** @} */

/** @name CLKOUTSEL - CLKOUT clock source select */ /** @{ */
#define LPC_SYSCON_CLKOUTSEL_SEL_MASK            (0x3U)                                              /**< LPC_SYSCON_CLKOUTSEL.SEL Mask           */
#define LPC_SYSCON_CLKOUTSEL_SEL_SHIFT           (0U)                                                /**< LPC_SYSCON_CLKOUTSEL.SEL Position       */
#define LPC_SYSCON_CLKOUTSEL_SEL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_CLKOUTSEL_SEL_SHIFT))&LPC_SYSCON_CLKOUTSEL_SEL_MASK) /**< LPC_SYSCON_CLKOUTSEL.SEL Field          */
/** @} */

/** @name CLKOUTUEN - CLKOUT clock source update enable */ /** @{ */
#define LPC_SYSCON_CLKOUTUEN_ENA_MASK            (0x1U)                                              /**< LPC_SYSCON_CLKOUTUEN.ENA Mask           */
#define LPC_SYSCON_CLKOUTUEN_ENA_SHIFT           (0U)                                                /**< LPC_SYSCON_CLKOUTUEN.ENA Position       */
#define LPC_SYSCON_CLKOUTUEN_ENA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_CLKOUTUEN_ENA_SHIFT))&LPC_SYSCON_CLKOUTUEN_ENA_MASK) /**< LPC_SYSCON_CLKOUTUEN.ENA Field          */
/** @} */

/** @name CLKOUTDIV - CLKOUT clock divider */ /** @{ */
#define LPC_SYSCON_CLKOUTDIV_DIV_MASK            (0xFFU)                                             /**< LPC_SYSCON_CLKOUTDIV.DIV Mask           */
#define LPC_SYSCON_CLKOUTDIV_DIV_SHIFT           (0U)                                                /**< LPC_SYSCON_CLKOUTDIV.DIV Position       */
#define LPC_SYSCON_CLKOUTDIV_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_CLKOUTDIV_DIV_SHIFT))&LPC_SYSCON_CLKOUTDIV_DIV_MASK) /**< LPC_SYSCON_CLKOUTDIV.DIV Field          */
/** @} */

/** @name PIOPORCAP0 - POR captured PIO status 0 */ /** @{ */
#define LPC_SYSCON_PIOPORCAP0_PIOSTAT_MASK       (0xFFFFFFU)                                         /**< LPC_SYSCON_PIOPORCAP0.PIOSTAT Mask      */
#define LPC_SYSCON_PIOPORCAP0_PIOSTAT_SHIFT      (0U)                                                /**< LPC_SYSCON_PIOPORCAP0.PIOSTAT Position  */
#define LPC_SYSCON_PIOPORCAP0_PIOSTAT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PIOPORCAP0_PIOSTAT_SHIFT))&LPC_SYSCON_PIOPORCAP0_PIOSTAT_MASK) /**< LPC_SYSCON_PIOPORCAP0.PIOSTAT Field     */
/** @} */

/** @name PIOPORCAP1 - POR captured PIO status 1 */ /** @{ */
#define LPC_SYSCON_PIOPORCAP1_PIOSTAT_MASK       (0xFFFFFFFFU)                                       /**< LPC_SYSCON_PIOPORCAP1.PIOSTAT Mask      */
#define LPC_SYSCON_PIOPORCAP1_PIOSTAT_SHIFT      (0U)                                                /**< LPC_SYSCON_PIOPORCAP1.PIOSTAT Position  */
#define LPC_SYSCON_PIOPORCAP1_PIOSTAT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PIOPORCAP1_PIOSTAT_SHIFT))&LPC_SYSCON_PIOPORCAP1_PIOSTAT_MASK) /**< LPC_SYSCON_PIOPORCAP1.PIOSTAT Field     */
/** @} */

/** @name BODCTRL - Brown-Out Detect */ /** @{ */
#define LPC_SYSCON_BODCTRL_BODRSTLEV_MASK        (0x3U)                                              /**< LPC_SYSCON_BODCTRL.BODRSTLEV Mask       */
#define LPC_SYSCON_BODCTRL_BODRSTLEV_SHIFT       (0U)                                                /**< LPC_SYSCON_BODCTRL.BODRSTLEV Position   */
#define LPC_SYSCON_BODCTRL_BODRSTLEV(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_BODCTRL_BODRSTLEV_SHIFT))&LPC_SYSCON_BODCTRL_BODRSTLEV_MASK) /**< LPC_SYSCON_BODCTRL.BODRSTLEV Field      */
#define LPC_SYSCON_BODCTRL_BODINTVAL_MASK        (0xCU)                                              /**< LPC_SYSCON_BODCTRL.BODINTVAL Mask       */
#define LPC_SYSCON_BODCTRL_BODINTVAL_SHIFT       (2U)                                                /**< LPC_SYSCON_BODCTRL.BODINTVAL Position   */
#define LPC_SYSCON_BODCTRL_BODINTVAL(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_BODCTRL_BODINTVAL_SHIFT))&LPC_SYSCON_BODCTRL_BODINTVAL_MASK) /**< LPC_SYSCON_BODCTRL.BODINTVAL Field      */
#define LPC_SYSCON_BODCTRL_BODRSTENA_MASK        (0x10U)                                             /**< LPC_SYSCON_BODCTRL.BODRSTENA Mask       */
#define LPC_SYSCON_BODCTRL_BODRSTENA_SHIFT       (4U)                                                /**< LPC_SYSCON_BODCTRL.BODRSTENA Position   */
#define LPC_SYSCON_BODCTRL_BODRSTENA(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_BODCTRL_BODRSTENA_SHIFT))&LPC_SYSCON_BODCTRL_BODRSTENA_MASK) /**< LPC_SYSCON_BODCTRL.BODRSTENA Field      */
/** @} */

/** @name SYSTCKCAL - System tick counter calibration */ /** @{ */
#define LPC_SYSCON_SYSTCKCAL_CAL_MASK            (0x3FFFFFFU)                                        /**< LPC_SYSCON_SYSTCKCAL.CAL Mask           */
#define LPC_SYSCON_SYSTCKCAL_CAL_SHIFT           (0U)                                                /**< LPC_SYSCON_SYSTCKCAL.CAL Position       */
#define LPC_SYSCON_SYSTCKCAL_CAL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSTCKCAL_CAL_SHIFT))&LPC_SYSCON_SYSTCKCAL_CAL_MASK) /**< LPC_SYSCON_SYSTCKCAL.CAL Field          */
/** @} */

/** @name IRQLATENCY - IQR delay. Allows trade-off between interrupt latency and determinism */ /** @{ */
#define LPC_SYSCON_IRQLATENCY_LATENCY_MASK       (0xFFU)                                             /**< LPC_SYSCON_IRQLATENCY.LATENCY Mask      */
#define LPC_SYSCON_IRQLATENCY_LATENCY_SHIFT      (0U)                                                /**< LPC_SYSCON_IRQLATENCY.LATENCY Position  */
#define LPC_SYSCON_IRQLATENCY_LATENCY(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_IRQLATENCY_LATENCY_SHIFT))&LPC_SYSCON_IRQLATENCY_LATENCY_MASK) /**< LPC_SYSCON_IRQLATENCY.LATENCY Field     */
/** @} */

/** @name NMISRC - NMI Source Control */ /** @{ */
#define LPC_SYSCON_NMISRC_IRQNO_MASK             (0x1FU)                                             /**< LPC_SYSCON_NMISRC.IRQNO Mask            */
#define LPC_SYSCON_NMISRC_IRQNO_SHIFT            (0U)                                                /**< LPC_SYSCON_NMISRC.IRQNO Position        */
#define LPC_SYSCON_NMISRC_IRQNO(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_NMISRC_IRQNO_SHIFT))&LPC_SYSCON_NMISRC_IRQNO_MASK) /**< LPC_SYSCON_NMISRC.IRQNO Field           */
#define LPC_SYSCON_NMISRC_NMIEN_MASK             (0x80000000U)                                       /**< LPC_SYSCON_NMISRC.NMIEN Mask            */
#define LPC_SYSCON_NMISRC_NMIEN_SHIFT            (31U)                                               /**< LPC_SYSCON_NMISRC.NMIEN Position        */
#define LPC_SYSCON_NMISRC_NMIEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_NMISRC_NMIEN_SHIFT))&LPC_SYSCON_NMISRC_NMIEN_MASK) /**< LPC_SYSCON_NMISRC.NMIEN Field           */
/** @} */

/** @name PINTSEL - GPIO Pin Interrupt Select register % */ /** @{ */
#define LPC_SYSCON_PINTSEL_INTPIN_MASK           (0x3FU)                                             /**< LPC_SYSCON_PINTSEL.INTPIN Mask          */
#define LPC_SYSCON_PINTSEL_INTPIN_SHIFT          (0U)                                                /**< LPC_SYSCON_PINTSEL.INTPIN Position      */
#define LPC_SYSCON_PINTSEL_INTPIN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PINTSEL_INTPIN_SHIFT))&LPC_SYSCON_PINTSEL_INTPIN_MASK) /**< LPC_SYSCON_PINTSEL.INTPIN Field         */
/** @} */

/** @name USBCLKCTRL - USB clock control */ /** @{ */
#define LPC_SYSCON_USBCLKCTRL_AP_CLK_MASK        (0x1U)                                              /**< LPC_SYSCON_USBCLKCTRL.AP_CLK Mask       */
#define LPC_SYSCON_USBCLKCTRL_AP_CLK_SHIFT       (0U)                                                /**< LPC_SYSCON_USBCLKCTRL.AP_CLK Position   */
#define LPC_SYSCON_USBCLKCTRL_AP_CLK(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBCLKCTRL_AP_CLK_SHIFT))&LPC_SYSCON_USBCLKCTRL_AP_CLK_MASK) /**< LPC_SYSCON_USBCLKCTRL.AP_CLK Field      */
#define LPC_SYSCON_USBCLKCTRL_POL_CLK_MASK       (0x2U)                                              /**< LPC_SYSCON_USBCLKCTRL.POL_CLK Mask      */
#define LPC_SYSCON_USBCLKCTRL_POL_CLK_SHIFT      (1U)                                                /**< LPC_SYSCON_USBCLKCTRL.POL_CLK Position  */
#define LPC_SYSCON_USBCLKCTRL_POL_CLK(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBCLKCTRL_POL_CLK_SHIFT))&LPC_SYSCON_USBCLKCTRL_POL_CLK_MASK) /**< LPC_SYSCON_USBCLKCTRL.POL_CLK Field     */
/** @} */

/** @name USBCLKST - USB clock status */ /** @{ */
#define LPC_SYSCON_USBCLKST_NEED_CLKST_MASK      (0x1U)                                              /**< LPC_SYSCON_USBCLKST.NEED_CLKST Mask     */
#define LPC_SYSCON_USBCLKST_NEED_CLKST_SHIFT     (0U)                                                /**< LPC_SYSCON_USBCLKST.NEED_CLKST Position */
#define LPC_SYSCON_USBCLKST_NEED_CLKST(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_USBCLKST_NEED_CLKST_SHIFT))&LPC_SYSCON_USBCLKST_NEED_CLKST_MASK) /**< LPC_SYSCON_USBCLKST.NEED_CLKST Field    */
/** @} */

/** @name STARTERP0 - Start logic 0 interrupt wake-up enable register 0 */ /** @{ */
#define LPC_SYSCON_STARTERP0_PINT0_MASK          (0x1U)                                              /**< LPC_SYSCON_STARTERP0.PINT0 Mask         */
#define LPC_SYSCON_STARTERP0_PINT0_SHIFT         (0U)                                                /**< LPC_SYSCON_STARTERP0.PINT0 Position     */
#define LPC_SYSCON_STARTERP0_PINT0(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT0_SHIFT))&LPC_SYSCON_STARTERP0_PINT0_MASK) /**< LPC_SYSCON_STARTERP0.PINT0 Field        */
#define LPC_SYSCON_STARTERP0_PINT1_MASK          (0x2U)                                              /**< LPC_SYSCON_STARTERP0.PINT1 Mask         */
#define LPC_SYSCON_STARTERP0_PINT1_SHIFT         (1U)                                                /**< LPC_SYSCON_STARTERP0.PINT1 Position     */
#define LPC_SYSCON_STARTERP0_PINT1(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT1_SHIFT))&LPC_SYSCON_STARTERP0_PINT1_MASK) /**< LPC_SYSCON_STARTERP0.PINT1 Field        */
#define LPC_SYSCON_STARTERP0_PINT2_MASK          (0x4U)                                              /**< LPC_SYSCON_STARTERP0.PINT2 Mask         */
#define LPC_SYSCON_STARTERP0_PINT2_SHIFT         (2U)                                                /**< LPC_SYSCON_STARTERP0.PINT2 Position     */
#define LPC_SYSCON_STARTERP0_PINT2(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT2_SHIFT))&LPC_SYSCON_STARTERP0_PINT2_MASK) /**< LPC_SYSCON_STARTERP0.PINT2 Field        */
#define LPC_SYSCON_STARTERP0_PINT3_MASK          (0x8U)                                              /**< LPC_SYSCON_STARTERP0.PINT3 Mask         */
#define LPC_SYSCON_STARTERP0_PINT3_SHIFT         (3U)                                                /**< LPC_SYSCON_STARTERP0.PINT3 Position     */
#define LPC_SYSCON_STARTERP0_PINT3(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT3_SHIFT))&LPC_SYSCON_STARTERP0_PINT3_MASK) /**< LPC_SYSCON_STARTERP0.PINT3 Field        */
#define LPC_SYSCON_STARTERP0_PINT4_MASK          (0x10U)                                             /**< LPC_SYSCON_STARTERP0.PINT4 Mask         */
#define LPC_SYSCON_STARTERP0_PINT4_SHIFT         (4U)                                                /**< LPC_SYSCON_STARTERP0.PINT4 Position     */
#define LPC_SYSCON_STARTERP0_PINT4(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT4_SHIFT))&LPC_SYSCON_STARTERP0_PINT4_MASK) /**< LPC_SYSCON_STARTERP0.PINT4 Field        */
#define LPC_SYSCON_STARTERP0_PINT5_MASK          (0x20U)                                             /**< LPC_SYSCON_STARTERP0.PINT5 Mask         */
#define LPC_SYSCON_STARTERP0_PINT5_SHIFT         (5U)                                                /**< LPC_SYSCON_STARTERP0.PINT5 Position     */
#define LPC_SYSCON_STARTERP0_PINT5(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT5_SHIFT))&LPC_SYSCON_STARTERP0_PINT5_MASK) /**< LPC_SYSCON_STARTERP0.PINT5 Field        */
#define LPC_SYSCON_STARTERP0_PINT6_MASK          (0x40U)                                             /**< LPC_SYSCON_STARTERP0.PINT6 Mask         */
#define LPC_SYSCON_STARTERP0_PINT6_SHIFT         (6U)                                                /**< LPC_SYSCON_STARTERP0.PINT6 Position     */
#define LPC_SYSCON_STARTERP0_PINT6(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT6_SHIFT))&LPC_SYSCON_STARTERP0_PINT6_MASK) /**< LPC_SYSCON_STARTERP0.PINT6 Field        */
#define LPC_SYSCON_STARTERP0_PINT7_MASK          (0x80U)                                             /**< LPC_SYSCON_STARTERP0.PINT7 Mask         */
#define LPC_SYSCON_STARTERP0_PINT7_SHIFT         (7U)                                                /**< LPC_SYSCON_STARTERP0.PINT7 Position     */
#define LPC_SYSCON_STARTERP0_PINT7(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT7_SHIFT))&LPC_SYSCON_STARTERP0_PINT7_MASK) /**< LPC_SYSCON_STARTERP0.PINT7 Field        */
/** @} */

/** @name STARTERP1 - Start logic 1 interrupt wake-up enable register 1 */ /** @{ */
#define LPC_SYSCON_STARTERP1_WWDTINT_MASK        (0x1000U)                                           /**< LPC_SYSCON_STARTERP1.WWDTINT Mask       */
#define LPC_SYSCON_STARTERP1_WWDTINT_SHIFT       (12U)                                               /**< LPC_SYSCON_STARTERP1.WWDTINT Position   */
#define LPC_SYSCON_STARTERP1_WWDTINT(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_WWDTINT_SHIFT))&LPC_SYSCON_STARTERP1_WWDTINT_MASK) /**< LPC_SYSCON_STARTERP1.WWDTINT Field      */
#define LPC_SYSCON_STARTERP1_BODINT_MASK         (0x2000U)                                           /**< LPC_SYSCON_STARTERP1.BODINT Mask        */
#define LPC_SYSCON_STARTERP1_BODINT_SHIFT        (13U)                                               /**< LPC_SYSCON_STARTERP1.BODINT Position    */
#define LPC_SYSCON_STARTERP1_BODINT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_BODINT_SHIFT))&LPC_SYSCON_STARTERP1_BODINT_MASK) /**< LPC_SYSCON_STARTERP1.BODINT Field       */
#define LPC_SYSCON_STARTERP1_USB_WAKEUP_MASK     (0x80000U)                                          /**< LPC_SYSCON_STARTERP1.USB_WAKEUP Mask    */
#define LPC_SYSCON_STARTERP1_USB_WAKEUP_SHIFT    (19U)                                               /**< LPC_SYSCON_STARTERP1.USB_WAKEUP Position*/
#define LPC_SYSCON_STARTERP1_USB_WAKEUP(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_USB_WAKEUP_SHIFT))&LPC_SYSCON_STARTERP1_USB_WAKEUP_MASK) /**< LPC_SYSCON_STARTERP1.USB_WAKEUP Field   */
#define LPC_SYSCON_STARTERP1_GPIOINT0_MASK       (0x100000U)                                         /**< LPC_SYSCON_STARTERP1.GPIOINT0 Mask      */
#define LPC_SYSCON_STARTERP1_GPIOINT0_SHIFT      (20U)                                               /**< LPC_SYSCON_STARTERP1.GPIOINT0 Position  */
#define LPC_SYSCON_STARTERP1_GPIOINT0(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_GPIOINT0_SHIFT))&LPC_SYSCON_STARTERP1_GPIOINT0_MASK) /**< LPC_SYSCON_STARTERP1.GPIOINT0 Field     */
#define LPC_SYSCON_STARTERP1_GPIOINT1_MASK       (0x200000U)                                         /**< LPC_SYSCON_STARTERP1.GPIOINT1 Mask      */
#define LPC_SYSCON_STARTERP1_GPIOINT1_SHIFT      (21U)                                               /**< LPC_SYSCON_STARTERP1.GPIOINT1 Position  */
#define LPC_SYSCON_STARTERP1_GPIOINT1(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_GPIOINT1_SHIFT))&LPC_SYSCON_STARTERP1_GPIOINT1_MASK) /**< LPC_SYSCON_STARTERP1.GPIOINT1 Field     */
/** @} */

/** @name PDSLEEPCFG - Power-down states in deep-sleep mode */ /** @{ */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD_MASK        (0x8U)                                              /**< LPC_SYSCON_PDSLEEPCFG.BOD_PD Mask       */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD_SHIFT       (3U)                                                /**< LPC_SYSCON_PDSLEEPCFG.BOD_PD Position   */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDSLEEPCFG_BOD_PD_SHIFT))&LPC_SYSCON_PDSLEEPCFG_BOD_PD_MASK) /**< LPC_SYSCON_PDSLEEPCFG.BOD_PD Field      */
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK     (0x40U)                                             /**< LPC_SYSCON_PDSLEEPCFG.WDTOSC_PD Mask    */
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT    (6U)                                                /**< LPC_SYSCON_PDSLEEPCFG.WDTOSC_PD Position*/
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT))&LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK) /**< LPC_SYSCON_PDSLEEPCFG.WDTOSC_PD Field   */
/** @} */

/** @name PDAWAKECFG - Power-down states for wake-up from deep-sleep */ /** @{ */
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_MASK     (0x1U)                                              /**< LPC_SYSCON_PDAWAKECFG.IRCOUT_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT    (0U)                                                /**< LPC_SYSCON_PDAWAKECFG.IRCOUT_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.IRCOUT_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD_MASK        (0x2U)                                              /**< LPC_SYSCON_PDAWAKECFG.IRC_PD Mask       */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD_SHIFT       (1U)                                                /**< LPC_SYSCON_PDAWAKECFG.IRC_PD Position   */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_IRC_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_IRC_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.IRC_PD Field      */
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD_MASK      (0x4U)                                              /**< LPC_SYSCON_PDAWAKECFG.FLASH_PD Mask     */
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD_SHIFT     (2U)                                                /**< LPC_SYSCON_PDAWAKECFG.FLASH_PD Position */
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_FLASH_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_FLASH_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.FLASH_PD Field    */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD_MASK        (0x8U)                                              /**< LPC_SYSCON_PDAWAKECFG.BOD_PD Mask       */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD_SHIFT       (3U)                                                /**< LPC_SYSCON_PDAWAKECFG.BOD_PD Position   */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_BOD_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_BOD_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.BOD_PD Field      */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD_MASK        (0x10U)                                             /**< LPC_SYSCON_PDAWAKECFG.ADC_PD Mask       */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD_SHIFT       (4U)                                                /**< LPC_SYSCON_PDAWAKECFG.ADC_PD Position   */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_ADC_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_ADC_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.ADC_PD Field      */
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_MASK     (0x20U)                                             /**< LPC_SYSCON_PDAWAKECFG.SYSOSC_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT    (5U)                                                /**< LPC_SYSCON_PDAWAKECFG.SYSOSC_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.SYSOSC_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_MASK     (0x40U)                                             /**< LPC_SYSCON_PDAWAKECFG.WDTOSC_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT    (6U)                                                /**< LPC_SYSCON_PDAWAKECFG.WDTOSC_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.WDTOSC_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_MASK     (0x80U)                                             /**< LPC_SYSCON_PDAWAKECFG.SYSPLL_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT    (7U)                                                /**< LPC_SYSCON_PDAWAKECFG.SYSPLL_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.SYSPLL_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_USBPLL_PD_MASK     (0x100U)                                            /**< LPC_SYSCON_PDAWAKECFG.USBPLL_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_USBPLL_PD_SHIFT    (8U)                                                /**< LPC_SYSCON_PDAWAKECFG.USBPLL_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_USBPLL_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_USBPLL_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_USBPLL_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.USBPLL_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_USBPAD_PD_MASK     (0x400U)                                            /**< LPC_SYSCON_PDAWAKECFG.USBPAD_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_USBPAD_PD_SHIFT    (10U)                                               /**< LPC_SYSCON_PDAWAKECFG.USBPAD_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_USBPAD_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_USBPAD_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_USBPAD_PD_MASK) /**< LPC_SYSCON_PDAWAKECFG.USBPAD_PD Field   */
/** @} */

/** @name PDRUNCFG - Power configuration register */ /** @{ */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD_MASK       (0x1U)                                              /**< LPC_SYSCON_PDRUNCFG.IRCOUT_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT      (0U)                                                /**< LPC_SYSCON_PDRUNCFG.IRCOUT_PD Position  */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_IRCOUT_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.IRCOUT_PD Field     */
#define LPC_SYSCON_PDRUNCFG_IRC_PD_MASK          (0x2U)                                              /**< LPC_SYSCON_PDRUNCFG.IRC_PD Mask         */
#define LPC_SYSCON_PDRUNCFG_IRC_PD_SHIFT         (1U)                                                /**< LPC_SYSCON_PDRUNCFG.IRC_PD Position     */
#define LPC_SYSCON_PDRUNCFG_IRC_PD(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_IRC_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_IRC_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.IRC_PD Field        */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD_MASK        (0x4U)                                              /**< LPC_SYSCON_PDRUNCFG.FLASH_PD Mask       */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD_SHIFT       (2U)                                                /**< LPC_SYSCON_PDRUNCFG.FLASH_PD Position   */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_FLASH_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_FLASH_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.FLASH_PD Field      */
#define LPC_SYSCON_PDRUNCFG_BOD_PD_MASK          (0x8U)                                              /**< LPC_SYSCON_PDRUNCFG.BOD_PD Mask         */
#define LPC_SYSCON_PDRUNCFG_BOD_PD_SHIFT         (3U)                                                /**< LPC_SYSCON_PDRUNCFG.BOD_PD Position     */
#define LPC_SYSCON_PDRUNCFG_BOD_PD(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_BOD_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_BOD_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.BOD_PD Field        */
#define LPC_SYSCON_PDRUNCFG_ADC_PD_MASK          (0x10U)                                             /**< LPC_SYSCON_PDRUNCFG.ADC_PD Mask         */
#define LPC_SYSCON_PDRUNCFG_ADC_PD_SHIFT         (4U)                                                /**< LPC_SYSCON_PDRUNCFG.ADC_PD Position     */
#define LPC_SYSCON_PDRUNCFG_ADC_PD(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_ADC_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_ADC_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.ADC_PD Field        */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD_MASK       (0x20U)                                             /**< LPC_SYSCON_PDRUNCFG.SYSOSC_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT      (5U)                                                /**< LPC_SYSCON_PDRUNCFG.SYSOSC_PD Position  */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_SYSOSC_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.SYSOSC_PD Field     */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD_MASK       (0x40U)                                             /**< LPC_SYSCON_PDRUNCFG.WDTOSC_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT      (6U)                                                /**< LPC_SYSCON_PDRUNCFG.WDTOSC_PD Position  */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_WDTOSC_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.WDTOSC_PD Field     */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD_MASK       (0x80U)                                             /**< LPC_SYSCON_PDRUNCFG.SYSPLL_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT      (7U)                                                /**< LPC_SYSCON_PDRUNCFG.SYSPLL_PD Position  */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_SYSPLL_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.SYSPLL_PD Field     */
#define LPC_SYSCON_PDRUNCFG_USBPLL_PD_MASK       (0x100U)                                            /**< LPC_SYSCON_PDRUNCFG.USBPLL_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_USBPLL_PD_SHIFT      (8U)                                                /**< LPC_SYSCON_PDRUNCFG.USBPLL_PD Position  */
#define LPC_SYSCON_PDRUNCFG_USBPLL_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_USBPLL_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_USBPLL_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.USBPLL_PD Field     */
#define LPC_SYSCON_PDRUNCFG_USBPAD_PD_MASK       (0x400U)                                            /**< LPC_SYSCON_PDRUNCFG.USBPAD_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_USBPAD_PD_SHIFT      (10U)                                               /**< LPC_SYSCON_PDRUNCFG.USBPAD_PD Position  */
#define LPC_SYSCON_PDRUNCFG_USBPAD_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_USBPAD_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_USBPAD_PD_MASK) /**< LPC_SYSCON_PDRUNCFG.USBPAD_PD Field     */
/** @} */

/** @name DEVICE_ID - Device ID */ /** @{ */
#define LPC_SYSCON_DEVICE_ID_DEVICEID_MASK       (0xFFFFFFFFU)                                       /**< LPC_SYSCON_DEVICE_ID.DEVICEID Mask      */
#define LPC_SYSCON_DEVICE_ID_DEVICEID_SHIFT      (0U)                                                /**< LPC_SYSCON_DEVICE_ID.DEVICEID Position  */
#define LPC_SYSCON_DEVICE_ID_DEVICEID(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_DEVICE_ID_DEVICEID_SHIFT))&LPC_SYSCON_DEVICE_ID_DEVICEID_MASK) /**< LPC_SYSCON_DEVICE_ID.DEVICEID Field     */
/** @} */

/** @} */ /* End group SYSCON_Register_Masks_GROUP */


/* LPC_SYSCON - Peripheral instance base addresses */
#define LPC_SYSCON_BasePtr             0x40048000UL //!< Peripheral base address
#define LPC_SYSCON                     ((LPC_SYSCON_Type *) LPC_SYSCON_BasePtr) //!< Freescale base pointer
#define LPC_SYSCON_BASE_PTR            (LPC_SYSCON) //!< Freescale style base pointer

/** @} */ /* End group SYSCON_Peripheral_access_layer_GROUP */


/** @brief C Struct for USART */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup USART_Peripheral_access_layer_GROUP USART Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_USART (file:USART_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief USART
 */
/**
 * @struct LPC_USART_Type
 * @brief  C Struct allowing access to USART registers
 */
typedef struct LPC_USART_Type {
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DLL;                       /**< 0000: Divisor Latch LSB. Least significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. (DLAB=1) */
      __I  uint32_t  RBR;                       /**< 0000: Receiver Buffer Register. Contains the next received character to be read. (DLAB=0) */
      __O  uint32_t  THR;                       /**< 0000: Transmit Holding Register. The next character to be transmitted is written here. (DLAB=0) */
   };
   union {                                      /**< 0004: (size=0004)                                                  */
      __IO uint32_t  DLM;                       /**< 0004: Divisor Latch MSB. Most significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. (DLAB=1) */
      __IO uint32_t  IER;                       /**< 0004: Interrupt Enable Register. Contains individual interrupt enable bits for the 7 potential USART interrupts. (DLAB=0) */
   };
   union {                                      /**< 0008: (size=0004)                                                  */
      __O  uint32_t  FCR;                       /**< 0008: FIFO Control Register. Controls USART FIFO usage and modes   */
      __I  uint32_t  IIR;                       /**< 0008: Interrupt ID Register. Identifies which interrupt(s) are pending */
   };
   __IO uint32_t  LCR;                          /**< 000C: Line Control Register. Contains controls for frame formatting and break generation */
   __IO uint32_t  MCR;                          /**< 0010: Modem Control Register                                       */
   __I  uint32_t  LSR;                          /**< 0014: Line Status Register. Contains flags for transmit and receive status, including line errors */
   __I  uint32_t  MSR;                          /**< 0018: Modem Status Register                                        */
   __IO uint32_t  SCR;                          /**< 001C: Scratch Pad Register. Eight-bit temporary storage for software */
   __IO uint32_t  ACR;                          /**< 0020: Auto-baud Control Register. Contains controls for the auto-baud feature */
   __IO uint32_t  ICR;                          /**< 0024: IrDA Control Register. Enables and configures the IrDA (remote control) mode */
   __IO uint32_t  FDR;                          /**< 0028: Fractional Divider Register. Generates a clock input for the baud rate divider */
   __IO uint32_t  OSR;                          /**< 002C: Oversampling Register. Controls the degree of oversampling during each bit time */
   __IO uint32_t  TER;                          /**< 0030: Transmit Enable Register. Turns off USART transmitter for use with software flow control */
        uint8_t   RESERVED_0[12];               /**< 0034: 0xC bytes                                                    */
   __IO uint32_t  HDEN;                         /**< 0040: Half duplex enable register                                  */
        uint8_t   RESERVED_1[4];                /**< 0044: 0x4 bytes                                                    */
   __IO uint32_t  SCICTRL;                      /**< 0048: Smart Card Interface Control register. Enables and configures the Smart Card Interface feature */
   __IO uint32_t  RS485CTRL;                    /**< 004C: RS-485/EIA-485 Control. Contains controls to configure various aspects of RS-485/EIA-485 modes */
   __IO uint32_t  RS485ADRMATCH;                /**< 0050: RS-485/EIA-485 address match. Contains the address match value for RS-485/EIA-485 mode */
   __IO uint32_t  RS485DLY;                     /**< 0054: RS-485/EIA-485 direction control delay                       */
   __IO uint32_t  SYNCCTRL;                     /**< 0058: Synchronous mode control register                            */
} LPC_USART_Type;


/** @brief Register Masks for USART */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_USART' Position & Mask macros                   ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup USART_Register_Masks_GROUP USART Register Masks */
/** @{ */

/** @name DLL - Divisor Latch LSB. Least significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. (DLAB=1) */ /** @{ */
#define LPC_USART_DLL_DLLSB_MASK                 (0xFFU)                                             /**< LPC_USART_DLL.DLLSB Mask                */
#define LPC_USART_DLL_DLLSB_SHIFT                (0U)                                                /**< LPC_USART_DLL.DLLSB Position            */
#define LPC_USART_DLL_DLLSB(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_DLL_DLLSB_SHIFT))&LPC_USART_DLL_DLLSB_MASK) /**< LPC_USART_DLL.DLLSB Field               */
/** @} */

/** @name RBR - Receiver Buffer Register. Contains the next received character to be read. (DLAB=0) */ /** @{ */
#define LPC_USART_RBR_RBR_MASK                   (0xFFU)                                             /**< LPC_USART_RBR.RBR Mask                  */
#define LPC_USART_RBR_RBR_SHIFT                  (0U)                                                /**< LPC_USART_RBR.RBR Position              */
#define LPC_USART_RBR_RBR(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_RBR_RBR_SHIFT))&LPC_USART_RBR_RBR_MASK) /**< LPC_USART_RBR.RBR Field                 */
/** @} */

/** @name THR - Transmit Holding Register. The next character to be transmitted is written here. (DLAB=0) */ /** @{ */
#define LPC_USART_THR_THR_MASK                   (0xFFU)                                             /**< LPC_USART_THR.THR Mask                  */
#define LPC_USART_THR_THR_SHIFT                  (0U)                                                /**< LPC_USART_THR.THR Position              */
#define LPC_USART_THR_THR(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_THR_THR_SHIFT))&LPC_USART_THR_THR_MASK) /**< LPC_USART_THR.THR Field                 */
/** @} */

/** @name DLM - Divisor Latch MSB. Most significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. (DLAB=1) */ /** @{ */
#define LPC_USART_DLM_DLMSB_MASK                 (0xFFU)                                             /**< LPC_USART_DLM.DLMSB Mask                */
#define LPC_USART_DLM_DLMSB_SHIFT                (0U)                                                /**< LPC_USART_DLM.DLMSB Position            */
#define LPC_USART_DLM_DLMSB(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_DLM_DLMSB_SHIFT))&LPC_USART_DLM_DLMSB_MASK) /**< LPC_USART_DLM.DLMSB Field               */
/** @} */

/** @name IER - Interrupt Enable Register. Contains individual interrupt enable bits for the 7 potential USART interrupts. (DLAB=0) */ /** @{ */
#define LPC_USART_IER_RBRINTEN_MASK              (0x1U)                                              /**< LPC_USART_IER.RBRINTEN Mask             */
#define LPC_USART_IER_RBRINTEN_SHIFT             (0U)                                                /**< LPC_USART_IER.RBRINTEN Position         */
#define LPC_USART_IER_RBRINTEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART_IER_RBRINTEN_SHIFT))&LPC_USART_IER_RBRINTEN_MASK) /**< LPC_USART_IER.RBRINTEN Field            */
#define LPC_USART_IER_THREINTEN_MASK             (0x2U)                                              /**< LPC_USART_IER.THREINTEN Mask            */
#define LPC_USART_IER_THREINTEN_SHIFT            (1U)                                                /**< LPC_USART_IER.THREINTEN Position        */
#define LPC_USART_IER_THREINTEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_IER_THREINTEN_SHIFT))&LPC_USART_IER_THREINTEN_MASK) /**< LPC_USART_IER.THREINTEN Field           */
#define LPC_USART_IER_RLSINTEN_MASK              (0x4U)                                              /**< LPC_USART_IER.RLSINTEN Mask             */
#define LPC_USART_IER_RLSINTEN_SHIFT             (2U)                                                /**< LPC_USART_IER.RLSINTEN Position         */
#define LPC_USART_IER_RLSINTEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART_IER_RLSINTEN_SHIFT))&LPC_USART_IER_RLSINTEN_MASK) /**< LPC_USART_IER.RLSINTEN Field            */
#define LPC_USART_IER_MSINTEN_MASK               (0x8U)                                              /**< LPC_USART_IER.MSINTEN Mask              */
#define LPC_USART_IER_MSINTEN_SHIFT              (3U)                                                /**< LPC_USART_IER.MSINTEN Position          */
#define LPC_USART_IER_MSINTEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART_IER_MSINTEN_SHIFT))&LPC_USART_IER_MSINTEN_MASK) /**< LPC_USART_IER.MSINTEN Field             */
#define LPC_USART_IER_ABEOINTEN_MASK             (0x100U)                                            /**< LPC_USART_IER.ABEOINTEN Mask            */
#define LPC_USART_IER_ABEOINTEN_SHIFT            (8U)                                                /**< LPC_USART_IER.ABEOINTEN Position        */
#define LPC_USART_IER_ABEOINTEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_IER_ABEOINTEN_SHIFT))&LPC_USART_IER_ABEOINTEN_MASK) /**< LPC_USART_IER.ABEOINTEN Field           */
#define LPC_USART_IER_ABTOINTEN_MASK             (0x200U)                                            /**< LPC_USART_IER.ABTOINTEN Mask            */
#define LPC_USART_IER_ABTOINTEN_SHIFT            (9U)                                                /**< LPC_USART_IER.ABTOINTEN Position        */
#define LPC_USART_IER_ABTOINTEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_IER_ABTOINTEN_SHIFT))&LPC_USART_IER_ABTOINTEN_MASK) /**< LPC_USART_IER.ABTOINTEN Field           */
/** @} */

/** @name FCR - FIFO Control Register. Controls USART FIFO usage and modes */ /** @{ */
#define LPC_USART_FCR_FIFOEN_MASK                (0x1U)                                              /**< LPC_USART_FCR.FIFOEN Mask               */
#define LPC_USART_FCR_FIFOEN_SHIFT               (0U)                                                /**< LPC_USART_FCR.FIFOEN Position           */
#define LPC_USART_FCR_FIFOEN(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART_FCR_FIFOEN_SHIFT))&LPC_USART_FCR_FIFOEN_MASK) /**< LPC_USART_FCR.FIFOEN Field              */
#define LPC_USART_FCR_RXFIFORES_MASK             (0x2U)                                              /**< LPC_USART_FCR.RXFIFORES Mask            */
#define LPC_USART_FCR_RXFIFORES_SHIFT            (1U)                                                /**< LPC_USART_FCR.RXFIFORES Position        */
#define LPC_USART_FCR_RXFIFORES(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_FCR_RXFIFORES_SHIFT))&LPC_USART_FCR_RXFIFORES_MASK) /**< LPC_USART_FCR.RXFIFORES Field           */
#define LPC_USART_FCR_TXFIFORES_MASK             (0x4U)                                              /**< LPC_USART_FCR.TXFIFORES Mask            */
#define LPC_USART_FCR_TXFIFORES_SHIFT            (2U)                                                /**< LPC_USART_FCR.TXFIFORES Position        */
#define LPC_USART_FCR_TXFIFORES(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_FCR_TXFIFORES_SHIFT))&LPC_USART_FCR_TXFIFORES_MASK) /**< LPC_USART_FCR.TXFIFORES Field           */
#define LPC_USART_FCR_RXTL_MASK                  (0xC0U)                                             /**< LPC_USART_FCR.RXTL Mask                 */
#define LPC_USART_FCR_RXTL_SHIFT                 (6U)                                                /**< LPC_USART_FCR.RXTL Position             */
#define LPC_USART_FCR_RXTL(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_FCR_RXTL_SHIFT))&LPC_USART_FCR_RXTL_MASK) /**< LPC_USART_FCR.RXTL Field                */
/** @} */

/** @name IIR - Interrupt ID Register. Identifies which interrupt(s) are pending */ /** @{ */
#define LPC_USART_IIR_INTSTATUS_MASK             (0x1U)                                              /**< LPC_USART_IIR.INTSTATUS Mask            */
#define LPC_USART_IIR_INTSTATUS_SHIFT            (0U)                                                /**< LPC_USART_IIR.INTSTATUS Position        */
#define LPC_USART_IIR_INTSTATUS(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_IIR_INTSTATUS_SHIFT))&LPC_USART_IIR_INTSTATUS_MASK) /**< LPC_USART_IIR.INTSTATUS Field           */
#define LPC_USART_IIR_INTID_MASK                 (0xEU)                                              /**< LPC_USART_IIR.INTID Mask                */
#define LPC_USART_IIR_INTID_SHIFT                (1U)                                                /**< LPC_USART_IIR.INTID Position            */
#define LPC_USART_IIR_INTID(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_IIR_INTID_SHIFT))&LPC_USART_IIR_INTID_MASK) /**< LPC_USART_IIR.INTID Field               */
#define LPC_USART_IIR_FIFOEN_MASK                (0xC0U)                                             /**< LPC_USART_IIR.FIFOEN Mask               */
#define LPC_USART_IIR_FIFOEN_SHIFT               (6U)                                                /**< LPC_USART_IIR.FIFOEN Position           */
#define LPC_USART_IIR_FIFOEN(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART_IIR_FIFOEN_SHIFT))&LPC_USART_IIR_FIFOEN_MASK) /**< LPC_USART_IIR.FIFOEN Field              */
#define LPC_USART_IIR_ABEOINT_MASK               (0x100U)                                            /**< LPC_USART_IIR.ABEOINT Mask              */
#define LPC_USART_IIR_ABEOINT_SHIFT              (8U)                                                /**< LPC_USART_IIR.ABEOINT Position          */
#define LPC_USART_IIR_ABEOINT(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART_IIR_ABEOINT_SHIFT))&LPC_USART_IIR_ABEOINT_MASK) /**< LPC_USART_IIR.ABEOINT Field             */
#define LPC_USART_IIR_ABTOINT_MASK               (0x200U)                                            /**< LPC_USART_IIR.ABTOINT Mask              */
#define LPC_USART_IIR_ABTOINT_SHIFT              (9U)                                                /**< LPC_USART_IIR.ABTOINT Position          */
#define LPC_USART_IIR_ABTOINT(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART_IIR_ABTOINT_SHIFT))&LPC_USART_IIR_ABTOINT_MASK) /**< LPC_USART_IIR.ABTOINT Field             */
/** @} */

/** @name LCR - Line Control Register. Contains controls for frame formatting and break generation */ /** @{ */
#define LPC_USART_LCR_WLS_MASK                   (0x3U)                                              /**< LPC_USART_LCR.WLS Mask                  */
#define LPC_USART_LCR_WLS_SHIFT                  (0U)                                                /**< LPC_USART_LCR.WLS Position              */
#define LPC_USART_LCR_WLS(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_LCR_WLS_SHIFT))&LPC_USART_LCR_WLS_MASK) /**< LPC_USART_LCR.WLS Field                 */
#define LPC_USART_LCR_SBS_MASK                   (0x4U)                                              /**< LPC_USART_LCR.SBS Mask                  */
#define LPC_USART_LCR_SBS_SHIFT                  (2U)                                                /**< LPC_USART_LCR.SBS Position              */
#define LPC_USART_LCR_SBS(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_LCR_SBS_SHIFT))&LPC_USART_LCR_SBS_MASK) /**< LPC_USART_LCR.SBS Field                 */
#define LPC_USART_LCR_PE_MASK                    (0x8U)                                              /**< LPC_USART_LCR.PE Mask                   */
#define LPC_USART_LCR_PE_SHIFT                   (3U)                                                /**< LPC_USART_LCR.PE Position               */
#define LPC_USART_LCR_PE(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_USART_LCR_PE_SHIFT))&LPC_USART_LCR_PE_MASK) /**< LPC_USART_LCR.PE Field                  */
#define LPC_USART_LCR_PS_MASK                    (0x30U)                                             /**< LPC_USART_LCR.PS Mask                   */
#define LPC_USART_LCR_PS_SHIFT                   (4U)                                                /**< LPC_USART_LCR.PS Position               */
#define LPC_USART_LCR_PS(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_USART_LCR_PS_SHIFT))&LPC_USART_LCR_PS_MASK) /**< LPC_USART_LCR.PS Field                  */
#define LPC_USART_LCR_BC_MASK                    (0x40U)                                             /**< LPC_USART_LCR.BC Mask                   */
#define LPC_USART_LCR_BC_SHIFT                   (6U)                                                /**< LPC_USART_LCR.BC Position               */
#define LPC_USART_LCR_BC(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_USART_LCR_BC_SHIFT))&LPC_USART_LCR_BC_MASK) /**< LPC_USART_LCR.BC Field                  */
#define LPC_USART_LCR_DLAB_MASK                  (0x80U)                                             /**< LPC_USART_LCR.DLAB Mask                 */
#define LPC_USART_LCR_DLAB_SHIFT                 (7U)                                                /**< LPC_USART_LCR.DLAB Position             */
#define LPC_USART_LCR_DLAB(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_LCR_DLAB_SHIFT))&LPC_USART_LCR_DLAB_MASK) /**< LPC_USART_LCR.DLAB Field                */
/** @} */

/** @name MCR - Modem Control Register */ /** @{ */
#define LPC_USART_MCR_DTRCTRL_MASK               (0x1U)                                              /**< LPC_USART_MCR.DTRCTRL Mask              */
#define LPC_USART_MCR_DTRCTRL_SHIFT              (0U)                                                /**< LPC_USART_MCR.DTRCTRL Position          */
#define LPC_USART_MCR_DTRCTRL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART_MCR_DTRCTRL_SHIFT))&LPC_USART_MCR_DTRCTRL_MASK) /**< LPC_USART_MCR.DTRCTRL Field             */
#define LPC_USART_MCR_RTSCTRL_MASK               (0x2U)                                              /**< LPC_USART_MCR.RTSCTRL Mask              */
#define LPC_USART_MCR_RTSCTRL_SHIFT              (1U)                                                /**< LPC_USART_MCR.RTSCTRL Position          */
#define LPC_USART_MCR_RTSCTRL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART_MCR_RTSCTRL_SHIFT))&LPC_USART_MCR_RTSCTRL_MASK) /**< LPC_USART_MCR.RTSCTRL Field             */
#define LPC_USART_MCR_LMS_MASK                   (0x10U)                                             /**< LPC_USART_MCR.LMS Mask                  */
#define LPC_USART_MCR_LMS_SHIFT                  (4U)                                                /**< LPC_USART_MCR.LMS Position              */
#define LPC_USART_MCR_LMS(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_MCR_LMS_SHIFT))&LPC_USART_MCR_LMS_MASK) /**< LPC_USART_MCR.LMS Field                 */
#define LPC_USART_MCR_RTSEN_MASK                 (0x40U)                                             /**< LPC_USART_MCR.RTSEN Mask                */
#define LPC_USART_MCR_RTSEN_SHIFT                (6U)                                                /**< LPC_USART_MCR.RTSEN Position            */
#define LPC_USART_MCR_RTSEN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_MCR_RTSEN_SHIFT))&LPC_USART_MCR_RTSEN_MASK) /**< LPC_USART_MCR.RTSEN Field               */
#define LPC_USART_MCR_CTSEN_MASK                 (0x80U)                                             /**< LPC_USART_MCR.CTSEN Mask                */
#define LPC_USART_MCR_CTSEN_SHIFT                (7U)                                                /**< LPC_USART_MCR.CTSEN Position            */
#define LPC_USART_MCR_CTSEN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_MCR_CTSEN_SHIFT))&LPC_USART_MCR_CTSEN_MASK) /**< LPC_USART_MCR.CTSEN Field               */
/** @} */

/** @name LSR - Line Status Register. Contains flags for transmit and receive status, including line errors */ /** @{ */
#define LPC_USART_LSR_RDR_MASK                   (0x1U)                                              /**< LPC_USART_LSR.RDR Mask                  */
#define LPC_USART_LSR_RDR_SHIFT                  (0U)                                                /**< LPC_USART_LSR.RDR Position              */
#define LPC_USART_LSR_RDR(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_RDR_SHIFT))&LPC_USART_LSR_RDR_MASK) /**< LPC_USART_LSR.RDR Field                 */
#define LPC_USART_LSR_OE_MASK                    (0x2U)                                              /**< LPC_USART_LSR.OE Mask                   */
#define LPC_USART_LSR_OE_SHIFT                   (1U)                                                /**< LPC_USART_LSR.OE Position               */
#define LPC_USART_LSR_OE(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_OE_SHIFT))&LPC_USART_LSR_OE_MASK) /**< LPC_USART_LSR.OE Field                  */
#define LPC_USART_LSR_PE_MASK                    (0x4U)                                              /**< LPC_USART_LSR.PE Mask                   */
#define LPC_USART_LSR_PE_SHIFT                   (2U)                                                /**< LPC_USART_LSR.PE Position               */
#define LPC_USART_LSR_PE(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_PE_SHIFT))&LPC_USART_LSR_PE_MASK) /**< LPC_USART_LSR.PE Field                  */
#define LPC_USART_LSR_FE_MASK                    (0x8U)                                              /**< LPC_USART_LSR.FE Mask                   */
#define LPC_USART_LSR_FE_SHIFT                   (3U)                                                /**< LPC_USART_LSR.FE Position               */
#define LPC_USART_LSR_FE(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_FE_SHIFT))&LPC_USART_LSR_FE_MASK) /**< LPC_USART_LSR.FE Field                  */
#define LPC_USART_LSR_BI_MASK                    (0x10U)                                             /**< LPC_USART_LSR.BI Mask                   */
#define LPC_USART_LSR_BI_SHIFT                   (4U)                                                /**< LPC_USART_LSR.BI Position               */
#define LPC_USART_LSR_BI(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_BI_SHIFT))&LPC_USART_LSR_BI_MASK) /**< LPC_USART_LSR.BI Field                  */
#define LPC_USART_LSR_THRE_MASK                  (0x20U)                                             /**< LPC_USART_LSR.THRE Mask                 */
#define LPC_USART_LSR_THRE_SHIFT                 (5U)                                                /**< LPC_USART_LSR.THRE Position             */
#define LPC_USART_LSR_THRE(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_THRE_SHIFT))&LPC_USART_LSR_THRE_MASK) /**< LPC_USART_LSR.THRE Field                */
#define LPC_USART_LSR_TEMT_MASK                  (0x40U)                                             /**< LPC_USART_LSR.TEMT Mask                 */
#define LPC_USART_LSR_TEMT_SHIFT                 (6U)                                                /**< LPC_USART_LSR.TEMT Position             */
#define LPC_USART_LSR_TEMT(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_TEMT_SHIFT))&LPC_USART_LSR_TEMT_MASK) /**< LPC_USART_LSR.TEMT Field                */
#define LPC_USART_LSR_RXFE_MASK                  (0x80U)                                             /**< LPC_USART_LSR.RXFE Mask                 */
#define LPC_USART_LSR_RXFE_SHIFT                 (7U)                                                /**< LPC_USART_LSR.RXFE Position             */
#define LPC_USART_LSR_RXFE(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_RXFE_SHIFT))&LPC_USART_LSR_RXFE_MASK) /**< LPC_USART_LSR.RXFE Field                */
#define LPC_USART_LSR_TXERR_MASK                 (0x100U)                                            /**< LPC_USART_LSR.TXERR Mask                */
#define LPC_USART_LSR_TXERR_SHIFT                (8U)                                                /**< LPC_USART_LSR.TXERR Position            */
#define LPC_USART_LSR_TXERR(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_LSR_TXERR_SHIFT))&LPC_USART_LSR_TXERR_MASK) /**< LPC_USART_LSR.TXERR Field               */
/** @} */

/** @name MSR - Modem Status Register */ /** @{ */
#define LPC_USART_MSR_DCTS_MASK                  (0x1U)                                              /**< LPC_USART_MSR.DCTS Mask                 */
#define LPC_USART_MSR_DCTS_SHIFT                 (0U)                                                /**< LPC_USART_MSR.DCTS Position             */
#define LPC_USART_MSR_DCTS(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_MSR_DCTS_SHIFT))&LPC_USART_MSR_DCTS_MASK) /**< LPC_USART_MSR.DCTS Field                */
#define LPC_USART_MSR_DDSR_MASK                  (0x2U)                                              /**< LPC_USART_MSR.DDSR Mask                 */
#define LPC_USART_MSR_DDSR_SHIFT                 (1U)                                                /**< LPC_USART_MSR.DDSR Position             */
#define LPC_USART_MSR_DDSR(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_MSR_DDSR_SHIFT))&LPC_USART_MSR_DDSR_MASK) /**< LPC_USART_MSR.DDSR Field                */
#define LPC_USART_MSR_TERI_MASK                  (0x4U)                                              /**< LPC_USART_MSR.TERI Mask                 */
#define LPC_USART_MSR_TERI_SHIFT                 (2U)                                                /**< LPC_USART_MSR.TERI Position             */
#define LPC_USART_MSR_TERI(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_MSR_TERI_SHIFT))&LPC_USART_MSR_TERI_MASK) /**< LPC_USART_MSR.TERI Field                */
#define LPC_USART_MSR_DDCD_MASK                  (0x8U)                                              /**< LPC_USART_MSR.DDCD Mask                 */
#define LPC_USART_MSR_DDCD_SHIFT                 (3U)                                                /**< LPC_USART_MSR.DDCD Position             */
#define LPC_USART_MSR_DDCD(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_MSR_DDCD_SHIFT))&LPC_USART_MSR_DDCD_MASK) /**< LPC_USART_MSR.DDCD Field                */
#define LPC_USART_MSR_CTS_MASK                   (0x10U)                                             /**< LPC_USART_MSR.CTS Mask                  */
#define LPC_USART_MSR_CTS_SHIFT                  (4U)                                                /**< LPC_USART_MSR.CTS Position              */
#define LPC_USART_MSR_CTS(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_MSR_CTS_SHIFT))&LPC_USART_MSR_CTS_MASK) /**< LPC_USART_MSR.CTS Field                 */
#define LPC_USART_MSR_DSR_MASK                   (0x20U)                                             /**< LPC_USART_MSR.DSR Mask                  */
#define LPC_USART_MSR_DSR_SHIFT                  (5U)                                                /**< LPC_USART_MSR.DSR Position              */
#define LPC_USART_MSR_DSR(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_MSR_DSR_SHIFT))&LPC_USART_MSR_DSR_MASK) /**< LPC_USART_MSR.DSR Field                 */
#define LPC_USART_MSR_RI_MASK                    (0x40U)                                             /**< LPC_USART_MSR.RI Mask                   */
#define LPC_USART_MSR_RI_SHIFT                   (6U)                                                /**< LPC_USART_MSR.RI Position               */
#define LPC_USART_MSR_RI(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_USART_MSR_RI_SHIFT))&LPC_USART_MSR_RI_MASK) /**< LPC_USART_MSR.RI Field                  */
#define LPC_USART_MSR_DCD_MASK                   (0x80U)                                             /**< LPC_USART_MSR.DCD Mask                  */
#define LPC_USART_MSR_DCD_SHIFT                  (7U)                                                /**< LPC_USART_MSR.DCD Position              */
#define LPC_USART_MSR_DCD(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_MSR_DCD_SHIFT))&LPC_USART_MSR_DCD_MASK) /**< LPC_USART_MSR.DCD Field                 */
/** @} */

/** @name SCR - Scratch Pad Register. Eight-bit temporary storage for software */ /** @{ */
#define LPC_USART_SCR_PAD_MASK                   (0xFFU)                                             /**< LPC_USART_SCR.PAD Mask                  */
#define LPC_USART_SCR_PAD_SHIFT                  (0U)                                                /**< LPC_USART_SCR.PAD Position              */
#define LPC_USART_SCR_PAD(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART_SCR_PAD_SHIFT))&LPC_USART_SCR_PAD_MASK) /**< LPC_USART_SCR.PAD Field                 */
/** @} */

/** @name ACR - Auto-baud Control Register. Contains controls for the auto-baud feature */ /** @{ */
#define LPC_USART_ACR_START_MASK                 (0x1U)                                              /**< LPC_USART_ACR.START Mask                */
#define LPC_USART_ACR_START_SHIFT                (0U)                                                /**< LPC_USART_ACR.START Position            */
#define LPC_USART_ACR_START(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_ACR_START_SHIFT))&LPC_USART_ACR_START_MASK) /**< LPC_USART_ACR.START Field               */
#define LPC_USART_ACR_MODE_MASK                  (0x2U)                                              /**< LPC_USART_ACR.MODE Mask                 */
#define LPC_USART_ACR_MODE_SHIFT                 (1U)                                                /**< LPC_USART_ACR.MODE Position             */
#define LPC_USART_ACR_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_ACR_MODE_SHIFT))&LPC_USART_ACR_MODE_MASK) /**< LPC_USART_ACR.MODE Field                */
#define LPC_USART_ACR_AUTORESTART_MASK           (0x4U)                                              /**< LPC_USART_ACR.AUTORESTART Mask          */
#define LPC_USART_ACR_AUTORESTART_SHIFT          (2U)                                                /**< LPC_USART_ACR.AUTORESTART Position      */
#define LPC_USART_ACR_AUTORESTART(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART_ACR_AUTORESTART_SHIFT))&LPC_USART_ACR_AUTORESTART_MASK) /**< LPC_USART_ACR.AUTORESTART Field         */
#define LPC_USART_ACR_ABEOINTCLR_MASK            (0x100U)                                            /**< LPC_USART_ACR.ABEOINTCLR Mask           */
#define LPC_USART_ACR_ABEOINTCLR_SHIFT           (8U)                                                /**< LPC_USART_ACR.ABEOINTCLR Position       */
#define LPC_USART_ACR_ABEOINTCLR(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART_ACR_ABEOINTCLR_SHIFT))&LPC_USART_ACR_ABEOINTCLR_MASK) /**< LPC_USART_ACR.ABEOINTCLR Field          */
#define LPC_USART_ACR_ABTOINTCLR_MASK            (0x200U)                                            /**< LPC_USART_ACR.ABTOINTCLR Mask           */
#define LPC_USART_ACR_ABTOINTCLR_SHIFT           (9U)                                                /**< LPC_USART_ACR.ABTOINTCLR Position       */
#define LPC_USART_ACR_ABTOINTCLR(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART_ACR_ABTOINTCLR_SHIFT))&LPC_USART_ACR_ABTOINTCLR_MASK) /**< LPC_USART_ACR.ABTOINTCLR Field          */
/** @} */

/** @name ICR - IrDA Control Register. Enables and configures the IrDA (remote control) mode */ /** @{ */
#define LPC_USART_ICR_IRDAEN_MASK                (0x1U)                                              /**< LPC_USART_ICR.IRDAEN Mask               */
#define LPC_USART_ICR_IRDAEN_SHIFT               (0U)                                                /**< LPC_USART_ICR.IRDAEN Position           */
#define LPC_USART_ICR_IRDAEN(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART_ICR_IRDAEN_SHIFT))&LPC_USART_ICR_IRDAEN_MASK) /**< LPC_USART_ICR.IRDAEN Field              */
#define LPC_USART_ICR_IRDAINV_MASK               (0x2U)                                              /**< LPC_USART_ICR.IRDAINV Mask              */
#define LPC_USART_ICR_IRDAINV_SHIFT              (1U)                                                /**< LPC_USART_ICR.IRDAINV Position          */
#define LPC_USART_ICR_IRDAINV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART_ICR_IRDAINV_SHIFT))&LPC_USART_ICR_IRDAINV_MASK) /**< LPC_USART_ICR.IRDAINV Field             */
#define LPC_USART_ICR_FIXPULSEEN_MASK            (0x4U)                                              /**< LPC_USART_ICR.FIXPULSEEN Mask           */
#define LPC_USART_ICR_FIXPULSEEN_SHIFT           (2U)                                                /**< LPC_USART_ICR.FIXPULSEEN Position       */
#define LPC_USART_ICR_FIXPULSEEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART_ICR_FIXPULSEEN_SHIFT))&LPC_USART_ICR_FIXPULSEEN_MASK) /**< LPC_USART_ICR.FIXPULSEEN Field          */
#define LPC_USART_ICR_PULSEDIV_MASK              (0x38U)                                             /**< LPC_USART_ICR.PULSEDIV Mask             */
#define LPC_USART_ICR_PULSEDIV_SHIFT             (3U)                                                /**< LPC_USART_ICR.PULSEDIV Position         */
#define LPC_USART_ICR_PULSEDIV(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART_ICR_PULSEDIV_SHIFT))&LPC_USART_ICR_PULSEDIV_MASK) /**< LPC_USART_ICR.PULSEDIV Field            */
/** @} */

/** @name FDR - Fractional Divider Register. Generates a clock input for the baud rate divider */ /** @{ */
#define LPC_USART_FDR_DIVADDVAL_MASK             (0xFU)                                              /**< LPC_USART_FDR.DIVADDVAL Mask            */
#define LPC_USART_FDR_DIVADDVAL_SHIFT            (0U)                                                /**< LPC_USART_FDR.DIVADDVAL Position        */
#define LPC_USART_FDR_DIVADDVAL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_FDR_DIVADDVAL_SHIFT))&LPC_USART_FDR_DIVADDVAL_MASK) /**< LPC_USART_FDR.DIVADDVAL Field           */
#define LPC_USART_FDR_MULVAL_MASK                (0xF0U)                                             /**< LPC_USART_FDR.MULVAL Mask               */
#define LPC_USART_FDR_MULVAL_SHIFT               (4U)                                                /**< LPC_USART_FDR.MULVAL Position           */
#define LPC_USART_FDR_MULVAL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART_FDR_MULVAL_SHIFT))&LPC_USART_FDR_MULVAL_MASK) /**< LPC_USART_FDR.MULVAL Field              */
/** @} */

/** @name OSR - Oversampling Register. Controls the degree of oversampling during each bit time */ /** @{ */
#define LPC_USART_OSR_OSFRAC_MASK                (0xEU)                                              /**< LPC_USART_OSR.OSFRAC Mask               */
#define LPC_USART_OSR_OSFRAC_SHIFT               (1U)                                                /**< LPC_USART_OSR.OSFRAC Position           */
#define LPC_USART_OSR_OSFRAC(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART_OSR_OSFRAC_SHIFT))&LPC_USART_OSR_OSFRAC_MASK) /**< LPC_USART_OSR.OSFRAC Field              */
#define LPC_USART_OSR_OSINT_MASK                 (0xF0U)                                             /**< LPC_USART_OSR.OSINT Mask                */
#define LPC_USART_OSR_OSINT_SHIFT                (4U)                                                /**< LPC_USART_OSR.OSINT Position            */
#define LPC_USART_OSR_OSINT(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_OSR_OSINT_SHIFT))&LPC_USART_OSR_OSINT_MASK) /**< LPC_USART_OSR.OSINT Field               */
#define LPC_USART_OSR_FDINT_MASK                 (0x7F00U)                                           /**< LPC_USART_OSR.FDINT Mask                */
#define LPC_USART_OSR_FDINT_SHIFT                (8U)                                                /**< LPC_USART_OSR.FDINT Position            */
#define LPC_USART_OSR_FDINT(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_OSR_FDINT_SHIFT))&LPC_USART_OSR_FDINT_MASK) /**< LPC_USART_OSR.FDINT Field               */
/** @} */

/** @name TER - Transmit Enable Register. Turns off USART transmitter for use with software flow control */ /** @{ */
#define LPC_USART_TER_TXEN_MASK                  (0x80U)                                             /**< LPC_USART_TER.TXEN Mask                 */
#define LPC_USART_TER_TXEN_SHIFT                 (7U)                                                /**< LPC_USART_TER.TXEN Position             */
#define LPC_USART_TER_TXEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_USART_TER_TXEN_SHIFT))&LPC_USART_TER_TXEN_MASK) /**< LPC_USART_TER.TXEN Field                */
/** @} */

/** @name HDEN - Half duplex enable register */ /** @{ */
#define LPC_USART_HDEN_HDEN_MASK                 (0x1U)                                              /**< LPC_USART_HDEN.HDEN Mask                */
#define LPC_USART_HDEN_HDEN_SHIFT                (0U)                                                /**< LPC_USART_HDEN.HDEN Position            */
#define LPC_USART_HDEN_HDEN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART_HDEN_HDEN_SHIFT))&LPC_USART_HDEN_HDEN_MASK) /**< LPC_USART_HDEN.HDEN Field               */
/** @} */

/** @name SCICTRL - Smart Card Interface Control register. Enables and configures the Smart Card Interface feature */ /** @{ */
#define LPC_USART_SCICTRL_SCIEN_MASK             (0x1U)                                              /**< LPC_USART_SCICTRL.SCIEN Mask            */
#define LPC_USART_SCICTRL_SCIEN_SHIFT            (0U)                                                /**< LPC_USART_SCICTRL.SCIEN Position        */
#define LPC_USART_SCICTRL_SCIEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_SCICTRL_SCIEN_SHIFT))&LPC_USART_SCICTRL_SCIEN_MASK) /**< LPC_USART_SCICTRL.SCIEN Field           */
#define LPC_USART_SCICTRL_NACKDIS_MASK           (0x2U)                                              /**< LPC_USART_SCICTRL.NACKDIS Mask          */
#define LPC_USART_SCICTRL_NACKDIS_SHIFT          (1U)                                                /**< LPC_USART_SCICTRL.NACKDIS Position      */
#define LPC_USART_SCICTRL_NACKDIS(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART_SCICTRL_NACKDIS_SHIFT))&LPC_USART_SCICTRL_NACKDIS_MASK) /**< LPC_USART_SCICTRL.NACKDIS Field         */
#define LPC_USART_SCICTRL_PROTSEL_MASK           (0x4U)                                              /**< LPC_USART_SCICTRL.PROTSEL Mask          */
#define LPC_USART_SCICTRL_PROTSEL_SHIFT          (2U)                                                /**< LPC_USART_SCICTRL.PROTSEL Position      */
#define LPC_USART_SCICTRL_PROTSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART_SCICTRL_PROTSEL_SHIFT))&LPC_USART_SCICTRL_PROTSEL_MASK) /**< LPC_USART_SCICTRL.PROTSEL Field         */
#define LPC_USART_SCICTRL_TXRETRY_MASK           (0xE0U)                                             /**< LPC_USART_SCICTRL.TXRETRY Mask          */
#define LPC_USART_SCICTRL_TXRETRY_SHIFT          (5U)                                                /**< LPC_USART_SCICTRL.TXRETRY Position      */
#define LPC_USART_SCICTRL_TXRETRY(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART_SCICTRL_TXRETRY_SHIFT))&LPC_USART_SCICTRL_TXRETRY_MASK) /**< LPC_USART_SCICTRL.TXRETRY Field         */
#define LPC_USART_SCICTRL_XTRAGUARD_MASK         (0xFF00U)                                           /**< LPC_USART_SCICTRL.XTRAGUARD Mask        */
#define LPC_USART_SCICTRL_XTRAGUARD_SHIFT        (8U)                                                /**< LPC_USART_SCICTRL.XTRAGUARD Position    */
#define LPC_USART_SCICTRL_XTRAGUARD(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART_SCICTRL_XTRAGUARD_SHIFT))&LPC_USART_SCICTRL_XTRAGUARD_MASK) /**< LPC_USART_SCICTRL.XTRAGUARD Field       */
/** @} */

/** @name RS485CTRL - RS-485/EIA-485 Control. Contains controls to configure various aspects of RS-485/EIA-485 modes */ /** @{ */
#define LPC_USART_RS485CTRL_NMMEN_MASK           (0x1U)                                              /**< LPC_USART_RS485CTRL.NMMEN Mask          */
#define LPC_USART_RS485CTRL_NMMEN_SHIFT          (0U)                                                /**< LPC_USART_RS485CTRL.NMMEN Position      */
#define LPC_USART_RS485CTRL_NMMEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART_RS485CTRL_NMMEN_SHIFT))&LPC_USART_RS485CTRL_NMMEN_MASK) /**< LPC_USART_RS485CTRL.NMMEN Field         */
#define LPC_USART_RS485CTRL_RXDIS_MASK           (0x2U)                                              /**< LPC_USART_RS485CTRL.RXDIS Mask          */
#define LPC_USART_RS485CTRL_RXDIS_SHIFT          (1U)                                                /**< LPC_USART_RS485CTRL.RXDIS Position      */
#define LPC_USART_RS485CTRL_RXDIS(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART_RS485CTRL_RXDIS_SHIFT))&LPC_USART_RS485CTRL_RXDIS_MASK) /**< LPC_USART_RS485CTRL.RXDIS Field         */
#define LPC_USART_RS485CTRL_AADEN_MASK           (0x4U)                                              /**< LPC_USART_RS485CTRL.AADEN Mask          */
#define LPC_USART_RS485CTRL_AADEN_SHIFT          (2U)                                                /**< LPC_USART_RS485CTRL.AADEN Position      */
#define LPC_USART_RS485CTRL_AADEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART_RS485CTRL_AADEN_SHIFT))&LPC_USART_RS485CTRL_AADEN_MASK) /**< LPC_USART_RS485CTRL.AADEN Field         */
#define LPC_USART_RS485CTRL_SEL_MASK             (0x8U)                                              /**< LPC_USART_RS485CTRL.SEL Mask            */
#define LPC_USART_RS485CTRL_SEL_SHIFT            (3U)                                                /**< LPC_USART_RS485CTRL.SEL Position        */
#define LPC_USART_RS485CTRL_SEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_RS485CTRL_SEL_SHIFT))&LPC_USART_RS485CTRL_SEL_MASK) /**< LPC_USART_RS485CTRL.SEL Field           */
#define LPC_USART_RS485CTRL_DCTRL_MASK           (0x10U)                                             /**< LPC_USART_RS485CTRL.DCTRL Mask          */
#define LPC_USART_RS485CTRL_DCTRL_SHIFT          (4U)                                                /**< LPC_USART_RS485CTRL.DCTRL Position      */
#define LPC_USART_RS485CTRL_DCTRL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART_RS485CTRL_DCTRL_SHIFT))&LPC_USART_RS485CTRL_DCTRL_MASK) /**< LPC_USART_RS485CTRL.DCTRL Field         */
#define LPC_USART_RS485CTRL_OINV_MASK            (0x20U)                                             /**< LPC_USART_RS485CTRL.OINV Mask           */
#define LPC_USART_RS485CTRL_OINV_SHIFT           (5U)                                                /**< LPC_USART_RS485CTRL.OINV Position       */
#define LPC_USART_RS485CTRL_OINV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART_RS485CTRL_OINV_SHIFT))&LPC_USART_RS485CTRL_OINV_MASK) /**< LPC_USART_RS485CTRL.OINV Field          */
/** @} */

/** @name RS485ADRMATCH - RS-485/EIA-485 address match. Contains the address match value for RS-485/EIA-485 mode */ /** @{ */
#define LPC_USART_RS485ADRMATCH_ADRMATCH_MASK    (0xFFU)                                             /**< LPC_USART_RS485ADRMATCH.ADRMATCH Mask   */
#define LPC_USART_RS485ADRMATCH_ADRMATCH_SHIFT   (0U)                                                /**< LPC_USART_RS485ADRMATCH.ADRMATCH Position*/
#define LPC_USART_RS485ADRMATCH_ADRMATCH(x)      (((uint32_t)(((uint32_t)(x))<<LPC_USART_RS485ADRMATCH_ADRMATCH_SHIFT))&LPC_USART_RS485ADRMATCH_ADRMATCH_MASK) /**< LPC_USART_RS485ADRMATCH.ADRMATCH Field  */
/** @} */

/** @name RS485DLY - RS-485/EIA-485 direction control delay */ /** @{ */
#define LPC_USART_RS485DLY_DLY_MASK              (0xFFU)                                             /**< LPC_USART_RS485DLY.DLY Mask             */
#define LPC_USART_RS485DLY_DLY_SHIFT             (0U)                                                /**< LPC_USART_RS485DLY.DLY Position         */
#define LPC_USART_RS485DLY_DLY(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART_RS485DLY_DLY_SHIFT))&LPC_USART_RS485DLY_DLY_MASK) /**< LPC_USART_RS485DLY.DLY Field            */
/** @} */

/** @name SYNCCTRL - Synchronous mode control register */ /** @{ */
#define LPC_USART_SYNCCTRL_SYNC_MASK             (0x1U)                                              /**< LPC_USART_SYNCCTRL.SYNC Mask            */
#define LPC_USART_SYNCCTRL_SYNC_SHIFT            (0U)                                                /**< LPC_USART_SYNCCTRL.SYNC Position        */
#define LPC_USART_SYNCCTRL_SYNC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_SYNCCTRL_SYNC_SHIFT))&LPC_USART_SYNCCTRL_SYNC_MASK) /**< LPC_USART_SYNCCTRL.SYNC Field           */
#define LPC_USART_SYNCCTRL_CSRC_MASK             (0x2U)                                              /**< LPC_USART_SYNCCTRL.CSRC Mask            */
#define LPC_USART_SYNCCTRL_CSRC_SHIFT            (1U)                                                /**< LPC_USART_SYNCCTRL.CSRC Position        */
#define LPC_USART_SYNCCTRL_CSRC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART_SYNCCTRL_CSRC_SHIFT))&LPC_USART_SYNCCTRL_CSRC_MASK) /**< LPC_USART_SYNCCTRL.CSRC Field           */
#define LPC_USART_SYNCCTRL_FES_MASK              (0x4U)                                              /**< LPC_USART_SYNCCTRL.FES Mask             */
#define LPC_USART_SYNCCTRL_FES_SHIFT             (2U)                                                /**< LPC_USART_SYNCCTRL.FES Position         */
#define LPC_USART_SYNCCTRL_FES(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART_SYNCCTRL_FES_SHIFT))&LPC_USART_SYNCCTRL_FES_MASK) /**< LPC_USART_SYNCCTRL.FES Field            */
#define LPC_USART_SYNCCTRL_TSBYPASS_MASK         (0x8U)                                              /**< LPC_USART_SYNCCTRL.TSBYPASS Mask        */
#define LPC_USART_SYNCCTRL_TSBYPASS_SHIFT        (3U)                                                /**< LPC_USART_SYNCCTRL.TSBYPASS Position    */
#define LPC_USART_SYNCCTRL_TSBYPASS(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART_SYNCCTRL_TSBYPASS_SHIFT))&LPC_USART_SYNCCTRL_TSBYPASS_MASK) /**< LPC_USART_SYNCCTRL.TSBYPASS Field       */
#define LPC_USART_SYNCCTRL_CSCEN_MASK            (0x10U)                                             /**< LPC_USART_SYNCCTRL.CSCEN Mask           */
#define LPC_USART_SYNCCTRL_CSCEN_SHIFT           (4U)                                                /**< LPC_USART_SYNCCTRL.CSCEN Position       */
#define LPC_USART_SYNCCTRL_CSCEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART_SYNCCTRL_CSCEN_SHIFT))&LPC_USART_SYNCCTRL_CSCEN_MASK) /**< LPC_USART_SYNCCTRL.CSCEN Field          */
#define LPC_USART_SYNCCTRL_SSDIS_MASK            (0x20U)                                             /**< LPC_USART_SYNCCTRL.SSDIS Mask           */
#define LPC_USART_SYNCCTRL_SSDIS_SHIFT           (5U)                                                /**< LPC_USART_SYNCCTRL.SSDIS Position       */
#define LPC_USART_SYNCCTRL_SSDIS(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART_SYNCCTRL_SSDIS_SHIFT))&LPC_USART_SYNCCTRL_SSDIS_MASK) /**< LPC_USART_SYNCCTRL.SSDIS Field          */
#define LPC_USART_SYNCCTRL_CCCLR_MASK            (0x40U)                                             /**< LPC_USART_SYNCCTRL.CCCLR Mask           */
#define LPC_USART_SYNCCTRL_CCCLR_SHIFT           (6U)                                                /**< LPC_USART_SYNCCTRL.CCCLR Position       */
#define LPC_USART_SYNCCTRL_CCCLR(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART_SYNCCTRL_CCCLR_SHIFT))&LPC_USART_SYNCCTRL_CCCLR_MASK) /**< LPC_USART_SYNCCTRL.CCCLR Field          */
/** @} */

/** @} */ /* End group USART_Register_Masks_GROUP */


/* LPC_USART - Peripheral instance base addresses */
#define LPC_USART_BasePtr              0x40008000UL //!< Peripheral base address
#define LPC_USART                      ((LPC_USART_Type *) LPC_USART_BasePtr) //!< Freescale base pointer
#define LPC_USART_BASE_PTR             (LPC_USART) //!< Freescale style base pointer

/** @} */ /* End group USART_Peripheral_access_layer_GROUP */


/** @brief C Struct for USB */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup USB_Peripheral_access_layer_GROUP USB Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_USB (file:USB_LPC11Uxx)          ================ */
/* ================================================================================ */

/**
 * @brief USB2.0 device controller
 */
/**
 * @struct LPC_USB_Type
 * @brief  C Struct allowing access to USB registers
 */
typedef struct LPC_USB_Type {
   __IO uint32_t  DEVCMDSTAT;                   /**< 0000: USB Device Command/Status register                           */
   __IO uint32_t  INFO;                         /**< 0004: USB Info register                                            */
   __IO uint32_t  EPLISTSTART;                  /**< 0008: USB EP Command/Status List start address                     */
   __IO uint32_t  DATABUFSTART;                 /**< 000C: USB Data buffer start address                                */
   __IO uint32_t  LPM;                          /**< 0010: Link Power Management register                               */
   __IO uint32_t  EPSKIP;                       /**< 0014: USB Endpoint skip                                            */
   __IO uint32_t  EPINUSE;                      /**< 0018: USB Endpoint Buffer in use                                   */
   __IO uint32_t  EPBUFCFG;                     /**< 001C: USB Endpoint Buffer Configuration register                   */
   __IO uint32_t  INTSTAT;                      /**< 0020: USB interrupt status register                                */
   __IO uint32_t  INTEN;                        /**< 0024: USB interrupt enable register                                */
   __IO uint32_t  INTSETSTAT;                   /**< 0028: USB set interrupt status register                            */
   __IO uint32_t  INTROUTING;                   /**< 002C: USB interrupt routing register                               */
        uint8_t   RESERVED_0[4];                /**< 0030: 0x4 bytes                                                    */
   __I  uint32_t  EPTOGGLE;                     /**< 0034: USB Endpoint toggle register                                 */
} LPC_USB_Type;


/** @brief Register Masks for USB */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_USB' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup USB_Register_Masks_GROUP USB Register Masks */
/** @{ */

/** @name DEVCMDSTAT - USB Device Command/Status register */ /** @{ */
#define LPC_USB_DEVCMDSTAT_DEV_ADDR_MASK         (0x7FU)                                             /**< LPC_USB_DEVCMDSTAT.DEV_ADDR Mask        */
#define LPC_USB_DEVCMDSTAT_DEV_ADDR_SHIFT        (0U)                                                /**< LPC_USB_DEVCMDSTAT.DEV_ADDR Position    */
#define LPC_USB_DEVCMDSTAT_DEV_ADDR(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_DEV_ADDR_SHIFT))&LPC_USB_DEVCMDSTAT_DEV_ADDR_MASK) /**< LPC_USB_DEVCMDSTAT.DEV_ADDR Field       */
#define LPC_USB_DEVCMDSTAT_DEV_EN_MASK           (0x80U)                                             /**< LPC_USB_DEVCMDSTAT.DEV_EN Mask          */
#define LPC_USB_DEVCMDSTAT_DEV_EN_SHIFT          (7U)                                                /**< LPC_USB_DEVCMDSTAT.DEV_EN Position      */
#define LPC_USB_DEVCMDSTAT_DEV_EN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_DEV_EN_SHIFT))&LPC_USB_DEVCMDSTAT_DEV_EN_MASK) /**< LPC_USB_DEVCMDSTAT.DEV_EN Field         */
#define LPC_USB_DEVCMDSTAT_SETUP_MASK            (0x100U)                                            /**< LPC_USB_DEVCMDSTAT.SETUP Mask           */
#define LPC_USB_DEVCMDSTAT_SETUP_SHIFT           (8U)                                                /**< LPC_USB_DEVCMDSTAT.SETUP Position       */
#define LPC_USB_DEVCMDSTAT_SETUP(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_SETUP_SHIFT))&LPC_USB_DEVCMDSTAT_SETUP_MASK) /**< LPC_USB_DEVCMDSTAT.SETUP Field          */
#define LPC_USB_DEVCMDSTAT_PLL_ON_MASK           (0x200U)                                            /**< LPC_USB_DEVCMDSTAT.PLL_ON Mask          */
#define LPC_USB_DEVCMDSTAT_PLL_ON_SHIFT          (9U)                                                /**< LPC_USB_DEVCMDSTAT.PLL_ON Position      */
#define LPC_USB_DEVCMDSTAT_PLL_ON(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_PLL_ON_SHIFT))&LPC_USB_DEVCMDSTAT_PLL_ON_MASK) /**< LPC_USB_DEVCMDSTAT.PLL_ON Field         */
#define LPC_USB_DEVCMDSTAT_LPM_SUP_MASK          (0x800U)                                            /**< LPC_USB_DEVCMDSTAT.LPM_SUP Mask         */
#define LPC_USB_DEVCMDSTAT_LPM_SUP_SHIFT         (11U)                                               /**< LPC_USB_DEVCMDSTAT.LPM_SUP Position     */
#define LPC_USB_DEVCMDSTAT_LPM_SUP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_LPM_SUP_SHIFT))&LPC_USB_DEVCMDSTAT_LPM_SUP_MASK) /**< LPC_USB_DEVCMDSTAT.LPM_SUP Field        */
#define LPC_USB_DEVCMDSTAT_INTONNAK_AO_MASK      (0x1000U)                                           /**< LPC_USB_DEVCMDSTAT.INTONNAK_AO Mask     */
#define LPC_USB_DEVCMDSTAT_INTONNAK_AO_SHIFT     (12U)                                               /**< LPC_USB_DEVCMDSTAT.INTONNAK_AO Position */
#define LPC_USB_DEVCMDSTAT_INTONNAK_AO(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_INTONNAK_AO_SHIFT))&LPC_USB_DEVCMDSTAT_INTONNAK_AO_MASK) /**< LPC_USB_DEVCMDSTAT.INTONNAK_AO Field    */
#define LPC_USB_DEVCMDSTAT_INTONNAK_AI_MASK      (0x2000U)                                           /**< LPC_USB_DEVCMDSTAT.INTONNAK_AI Mask     */
#define LPC_USB_DEVCMDSTAT_INTONNAK_AI_SHIFT     (13U)                                               /**< LPC_USB_DEVCMDSTAT.INTONNAK_AI Position */
#define LPC_USB_DEVCMDSTAT_INTONNAK_AI(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_INTONNAK_AI_SHIFT))&LPC_USB_DEVCMDSTAT_INTONNAK_AI_MASK) /**< LPC_USB_DEVCMDSTAT.INTONNAK_AI Field    */
#define LPC_USB_DEVCMDSTAT_INTONNAK_CO_MASK      (0x4000U)                                           /**< LPC_USB_DEVCMDSTAT.INTONNAK_CO Mask     */
#define LPC_USB_DEVCMDSTAT_INTONNAK_CO_SHIFT     (14U)                                               /**< LPC_USB_DEVCMDSTAT.INTONNAK_CO Position */
#define LPC_USB_DEVCMDSTAT_INTONNAK_CO(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_INTONNAK_CO_SHIFT))&LPC_USB_DEVCMDSTAT_INTONNAK_CO_MASK) /**< LPC_USB_DEVCMDSTAT.INTONNAK_CO Field    */
#define LPC_USB_DEVCMDSTAT_INTONNAK_CI_MASK      (0x8000U)                                           /**< LPC_USB_DEVCMDSTAT.INTONNAK_CI Mask     */
#define LPC_USB_DEVCMDSTAT_INTONNAK_CI_SHIFT     (15U)                                               /**< LPC_USB_DEVCMDSTAT.INTONNAK_CI Position */
#define LPC_USB_DEVCMDSTAT_INTONNAK_CI(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_INTONNAK_CI_SHIFT))&LPC_USB_DEVCMDSTAT_INTONNAK_CI_MASK) /**< LPC_USB_DEVCMDSTAT.INTONNAK_CI Field    */
#define LPC_USB_DEVCMDSTAT_DCON_MASK             (0x10000U)                                          /**< LPC_USB_DEVCMDSTAT.DCON Mask            */
#define LPC_USB_DEVCMDSTAT_DCON_SHIFT            (16U)                                               /**< LPC_USB_DEVCMDSTAT.DCON Position        */
#define LPC_USB_DEVCMDSTAT_DCON(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_DCON_SHIFT))&LPC_USB_DEVCMDSTAT_DCON_MASK) /**< LPC_USB_DEVCMDSTAT.DCON Field           */
#define LPC_USB_DEVCMDSTAT_DSUS_MASK             (0x20000U)                                          /**< LPC_USB_DEVCMDSTAT.DSUS Mask            */
#define LPC_USB_DEVCMDSTAT_DSUS_SHIFT            (17U)                                               /**< LPC_USB_DEVCMDSTAT.DSUS Position        */
#define LPC_USB_DEVCMDSTAT_DSUS(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_DSUS_SHIFT))&LPC_USB_DEVCMDSTAT_DSUS_MASK) /**< LPC_USB_DEVCMDSTAT.DSUS Field           */
#define LPC_USB_DEVCMDSTAT_LPM_SUS_MASK          (0x80000U)                                          /**< LPC_USB_DEVCMDSTAT.LPM_SUS Mask         */
#define LPC_USB_DEVCMDSTAT_LPM_SUS_SHIFT         (19U)                                               /**< LPC_USB_DEVCMDSTAT.LPM_SUS Position     */
#define LPC_USB_DEVCMDSTAT_LPM_SUS(x)            (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_LPM_SUS_SHIFT))&LPC_USB_DEVCMDSTAT_LPM_SUS_MASK) /**< LPC_USB_DEVCMDSTAT.LPM_SUS Field        */
#define LPC_USB_DEVCMDSTAT_LPM_REWP_MASK         (0x100000U)                                         /**< LPC_USB_DEVCMDSTAT.LPM_REWP Mask        */
#define LPC_USB_DEVCMDSTAT_LPM_REWP_SHIFT        (20U)                                               /**< LPC_USB_DEVCMDSTAT.LPM_REWP Position    */
#define LPC_USB_DEVCMDSTAT_LPM_REWP(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_LPM_REWP_SHIFT))&LPC_USB_DEVCMDSTAT_LPM_REWP_MASK) /**< LPC_USB_DEVCMDSTAT.LPM_REWP Field       */
#define LPC_USB_DEVCMDSTAT_DCON_C_MASK           (0x1000000U)                                        /**< LPC_USB_DEVCMDSTAT.DCON_C Mask          */
#define LPC_USB_DEVCMDSTAT_DCON_C_SHIFT          (24U)                                               /**< LPC_USB_DEVCMDSTAT.DCON_C Position      */
#define LPC_USB_DEVCMDSTAT_DCON_C(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_DCON_C_SHIFT))&LPC_USB_DEVCMDSTAT_DCON_C_MASK) /**< LPC_USB_DEVCMDSTAT.DCON_C Field         */
#define LPC_USB_DEVCMDSTAT_DSUS_C_MASK           (0x2000000U)                                        /**< LPC_USB_DEVCMDSTAT.DSUS_C Mask          */
#define LPC_USB_DEVCMDSTAT_DSUS_C_SHIFT          (25U)                                               /**< LPC_USB_DEVCMDSTAT.DSUS_C Position      */
#define LPC_USB_DEVCMDSTAT_DSUS_C(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_DSUS_C_SHIFT))&LPC_USB_DEVCMDSTAT_DSUS_C_MASK) /**< LPC_USB_DEVCMDSTAT.DSUS_C Field         */
#define LPC_USB_DEVCMDSTAT_DRES_C_MASK           (0x4000000U)                                        /**< LPC_USB_DEVCMDSTAT.DRES_C Mask          */
#define LPC_USB_DEVCMDSTAT_DRES_C_SHIFT          (26U)                                               /**< LPC_USB_DEVCMDSTAT.DRES_C Position      */
#define LPC_USB_DEVCMDSTAT_DRES_C(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_DRES_C_SHIFT))&LPC_USB_DEVCMDSTAT_DRES_C_MASK) /**< LPC_USB_DEVCMDSTAT.DRES_C Field         */
#define LPC_USB_DEVCMDSTAT_VBUSDEBOUNCED_MASK    (0x10000000U)                                       /**< LPC_USB_DEVCMDSTAT.VBUSDEBOUNCED Mask   */
#define LPC_USB_DEVCMDSTAT_VBUSDEBOUNCED_SHIFT   (28U)                                               /**< LPC_USB_DEVCMDSTAT.VBUSDEBOUNCED Position*/
#define LPC_USB_DEVCMDSTAT_VBUSDEBOUNCED(x)      (((uint32_t)(((uint32_t)(x))<<LPC_USB_DEVCMDSTAT_VBUSDEBOUNCED_SHIFT))&LPC_USB_DEVCMDSTAT_VBUSDEBOUNCED_MASK) /**< LPC_USB_DEVCMDSTAT.VBUSDEBOUNCED Field  */
/** @} */

/** @name INFO - USB Info register */ /** @{ */
#define LPC_USB_INFO_FRAME_NR_MASK               (0x7FFU)                                            /**< LPC_USB_INFO.FRAME_NR Mask              */
#define LPC_USB_INFO_FRAME_NR_SHIFT              (0U)                                                /**< LPC_USB_INFO.FRAME_NR Position          */
#define LPC_USB_INFO_FRAME_NR(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USB_INFO_FRAME_NR_SHIFT))&LPC_USB_INFO_FRAME_NR_MASK) /**< LPC_USB_INFO.FRAME_NR Field             */
#define LPC_USB_INFO_ERR_CODE_MASK               (0x7800U)                                           /**< LPC_USB_INFO.ERR_CODE Mask              */
#define LPC_USB_INFO_ERR_CODE_SHIFT              (11U)                                               /**< LPC_USB_INFO.ERR_CODE Position          */
#define LPC_USB_INFO_ERR_CODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USB_INFO_ERR_CODE_SHIFT))&LPC_USB_INFO_ERR_CODE_MASK) /**< LPC_USB_INFO.ERR_CODE Field             */
/** @} */

/** @name EPLISTSTART - USB EP Command/Status List start address */ /** @{ */
#define LPC_USB_EPLISTSTART_EP_LIST_MASK         (0xFFFFFF00U)                                       /**< LPC_USB_EPLISTSTART.EP_LIST Mask        */
#define LPC_USB_EPLISTSTART_EP_LIST_SHIFT        (8U)                                                /**< LPC_USB_EPLISTSTART.EP_LIST Position    */
#define LPC_USB_EPLISTSTART_EP_LIST(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USB_EPLISTSTART_EP_LIST_SHIFT))&LPC_USB_EPLISTSTART_EP_LIST_MASK) /**< LPC_USB_EPLISTSTART.EP_LIST Field       */
/** @} */

/** @name DATABUFSTART - USB Data buffer start address */ /** @{ */
#define LPC_USB_DATABUFSTART_DA_BUF_MASK         (0xFFC00000U)                                       /**< LPC_USB_DATABUFSTART.DA_BUF Mask        */
#define LPC_USB_DATABUFSTART_DA_BUF_SHIFT        (22U)                                               /**< LPC_USB_DATABUFSTART.DA_BUF Position    */
#define LPC_USB_DATABUFSTART_DA_BUF(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USB_DATABUFSTART_DA_BUF_SHIFT))&LPC_USB_DATABUFSTART_DA_BUF_MASK) /**< LPC_USB_DATABUFSTART.DA_BUF Field       */
/** @} */

/** @name LPM - Link Power Management register */ /** @{ */
#define LPC_USB_LPM_HIRD_HW_MASK                 (0xFU)                                              /**< LPC_USB_LPM.HIRD_HW Mask                */
#define LPC_USB_LPM_HIRD_HW_SHIFT                (0U)                                                /**< LPC_USB_LPM.HIRD_HW Position            */
#define LPC_USB_LPM_HIRD_HW(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USB_LPM_HIRD_HW_SHIFT))&LPC_USB_LPM_HIRD_HW_MASK) /**< LPC_USB_LPM.HIRD_HW Field               */
#define LPC_USB_LPM_HIRD_SW_MASK                 (0xF0U)                                             /**< LPC_USB_LPM.HIRD_SW Mask                */
#define LPC_USB_LPM_HIRD_SW_SHIFT                (4U)                                                /**< LPC_USB_LPM.HIRD_SW Position            */
#define LPC_USB_LPM_HIRD_SW(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USB_LPM_HIRD_SW_SHIFT))&LPC_USB_LPM_HIRD_SW_MASK) /**< LPC_USB_LPM.HIRD_SW Field               */
#define LPC_USB_LPM_DATA_PENDING_MASK            (0x100U)                                            /**< LPC_USB_LPM.DATA_PENDING Mask           */
#define LPC_USB_LPM_DATA_PENDING_SHIFT           (8U)                                                /**< LPC_USB_LPM.DATA_PENDING Position       */
#define LPC_USB_LPM_DATA_PENDING(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USB_LPM_DATA_PENDING_SHIFT))&LPC_USB_LPM_DATA_PENDING_MASK) /**< LPC_USB_LPM.DATA_PENDING Field          */
/** @} */

/** @name EPSKIP - USB Endpoint skip */ /** @{ */
#define LPC_USB_EPSKIP_SKIP_MASK                 (0x3FFFFFFFU)                                       /**< LPC_USB_EPSKIP.SKIP Mask                */
#define LPC_USB_EPSKIP_SKIP_SHIFT                (0U)                                                /**< LPC_USB_EPSKIP.SKIP Position            */
#define LPC_USB_EPSKIP_SKIP(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USB_EPSKIP_SKIP_SHIFT))&LPC_USB_EPSKIP_SKIP_MASK) /**< LPC_USB_EPSKIP.SKIP Field               */
/** @} */

/** @name EPINUSE - USB Endpoint Buffer in use */ /** @{ */
#define LPC_USB_EPINUSE_BUF_MASK                 (0x3FCU)                                            /**< LPC_USB_EPINUSE.BUF Mask                */
#define LPC_USB_EPINUSE_BUF_SHIFT                (2U)                                                /**< LPC_USB_EPINUSE.BUF Position            */
#define LPC_USB_EPINUSE_BUF(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USB_EPINUSE_BUF_SHIFT))&LPC_USB_EPINUSE_BUF_MASK) /**< LPC_USB_EPINUSE.BUF Field               */
/** @} */

/** @name EPBUFCFG - USB Endpoint Buffer Configuration register */ /** @{ */
#define LPC_USB_EPBUFCFG_BUF_SB_MASK             (0x3FCU)                                            /**< LPC_USB_EPBUFCFG.BUF_SB Mask            */
#define LPC_USB_EPBUFCFG_BUF_SB_SHIFT            (2U)                                                /**< LPC_USB_EPBUFCFG.BUF_SB Position        */
#define LPC_USB_EPBUFCFG_BUF_SB(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USB_EPBUFCFG_BUF_SB_SHIFT))&LPC_USB_EPBUFCFG_BUF_SB_MASK) /**< LPC_USB_EPBUFCFG.BUF_SB Field           */
/** @} */

/** @name INTSTAT - USB interrupt status register */ /** @{ */
#define LPC_USB_INTSTAT_EP0OUT_MASK              (0x1U)                                              /**< LPC_USB_INTSTAT.EP0OUT Mask             */
#define LPC_USB_INTSTAT_EP0OUT_SHIFT             (0U)                                                /**< LPC_USB_INTSTAT.EP0OUT Position         */
#define LPC_USB_INTSTAT_EP0OUT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP0OUT_SHIFT))&LPC_USB_INTSTAT_EP0OUT_MASK) /**< LPC_USB_INTSTAT.EP0OUT Field            */
#define LPC_USB_INTSTAT_EP0IN_MASK               (0x2U)                                              /**< LPC_USB_INTSTAT.EP0IN Mask              */
#define LPC_USB_INTSTAT_EP0IN_SHIFT              (1U)                                                /**< LPC_USB_INTSTAT.EP0IN Position          */
#define LPC_USB_INTSTAT_EP0IN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP0IN_SHIFT))&LPC_USB_INTSTAT_EP0IN_MASK) /**< LPC_USB_INTSTAT.EP0IN Field             */
#define LPC_USB_INTSTAT_EP1OUT_MASK              (0x4U)                                              /**< LPC_USB_INTSTAT.EP1OUT Mask             */
#define LPC_USB_INTSTAT_EP1OUT_SHIFT             (2U)                                                /**< LPC_USB_INTSTAT.EP1OUT Position         */
#define LPC_USB_INTSTAT_EP1OUT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP1OUT_SHIFT))&LPC_USB_INTSTAT_EP1OUT_MASK) /**< LPC_USB_INTSTAT.EP1OUT Field            */
#define LPC_USB_INTSTAT_EP1IN_MASK               (0x8U)                                              /**< LPC_USB_INTSTAT.EP1IN Mask              */
#define LPC_USB_INTSTAT_EP1IN_SHIFT              (3U)                                                /**< LPC_USB_INTSTAT.EP1IN Position          */
#define LPC_USB_INTSTAT_EP1IN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP1IN_SHIFT))&LPC_USB_INTSTAT_EP1IN_MASK) /**< LPC_USB_INTSTAT.EP1IN Field             */
#define LPC_USB_INTSTAT_EP2OUT_MASK              (0x10U)                                             /**< LPC_USB_INTSTAT.EP2OUT Mask             */
#define LPC_USB_INTSTAT_EP2OUT_SHIFT             (4U)                                                /**< LPC_USB_INTSTAT.EP2OUT Position         */
#define LPC_USB_INTSTAT_EP2OUT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP2OUT_SHIFT))&LPC_USB_INTSTAT_EP2OUT_MASK) /**< LPC_USB_INTSTAT.EP2OUT Field            */
#define LPC_USB_INTSTAT_EP2IN_MASK               (0x20U)                                             /**< LPC_USB_INTSTAT.EP2IN Mask              */
#define LPC_USB_INTSTAT_EP2IN_SHIFT              (5U)                                                /**< LPC_USB_INTSTAT.EP2IN Position          */
#define LPC_USB_INTSTAT_EP2IN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP2IN_SHIFT))&LPC_USB_INTSTAT_EP2IN_MASK) /**< LPC_USB_INTSTAT.EP2IN Field             */
#define LPC_USB_INTSTAT_EP3OUT_MASK              (0x40U)                                             /**< LPC_USB_INTSTAT.EP3OUT Mask             */
#define LPC_USB_INTSTAT_EP3OUT_SHIFT             (6U)                                                /**< LPC_USB_INTSTAT.EP3OUT Position         */
#define LPC_USB_INTSTAT_EP3OUT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP3OUT_SHIFT))&LPC_USB_INTSTAT_EP3OUT_MASK) /**< LPC_USB_INTSTAT.EP3OUT Field            */
#define LPC_USB_INTSTAT_EP3IN_MASK               (0x80U)                                             /**< LPC_USB_INTSTAT.EP3IN Mask              */
#define LPC_USB_INTSTAT_EP3IN_SHIFT              (7U)                                                /**< LPC_USB_INTSTAT.EP3IN Position          */
#define LPC_USB_INTSTAT_EP3IN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP3IN_SHIFT))&LPC_USB_INTSTAT_EP3IN_MASK) /**< LPC_USB_INTSTAT.EP3IN Field             */
#define LPC_USB_INTSTAT_EP4OUT_MASK              (0x100U)                                            /**< LPC_USB_INTSTAT.EP4OUT Mask             */
#define LPC_USB_INTSTAT_EP4OUT_SHIFT             (8U)                                                /**< LPC_USB_INTSTAT.EP4OUT Position         */
#define LPC_USB_INTSTAT_EP4OUT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP4OUT_SHIFT))&LPC_USB_INTSTAT_EP4OUT_MASK) /**< LPC_USB_INTSTAT.EP4OUT Field            */
#define LPC_USB_INTSTAT_EP4IN_MASK               (0x200U)                                            /**< LPC_USB_INTSTAT.EP4IN Mask              */
#define LPC_USB_INTSTAT_EP4IN_SHIFT              (9U)                                                /**< LPC_USB_INTSTAT.EP4IN Position          */
#define LPC_USB_INTSTAT_EP4IN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_EP4IN_SHIFT))&LPC_USB_INTSTAT_EP4IN_MASK) /**< LPC_USB_INTSTAT.EP4IN Field             */
#define LPC_USB_INTSTAT_FRAME_INT_MASK           (0x40000000U)                                       /**< LPC_USB_INTSTAT.FRAME_INT Mask          */
#define LPC_USB_INTSTAT_FRAME_INT_SHIFT          (30U)                                               /**< LPC_USB_INTSTAT.FRAME_INT Position      */
#define LPC_USB_INTSTAT_FRAME_INT(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_FRAME_INT_SHIFT))&LPC_USB_INTSTAT_FRAME_INT_MASK) /**< LPC_USB_INTSTAT.FRAME_INT Field         */
#define LPC_USB_INTSTAT_DEV_INT_MASK             (0x80000000U)                                       /**< LPC_USB_INTSTAT.DEV_INT Mask            */
#define LPC_USB_INTSTAT_DEV_INT_SHIFT            (31U)                                               /**< LPC_USB_INTSTAT.DEV_INT Position        */
#define LPC_USB_INTSTAT_DEV_INT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSTAT_DEV_INT_SHIFT))&LPC_USB_INTSTAT_DEV_INT_MASK) /**< LPC_USB_INTSTAT.DEV_INT Field           */
/** @} */

/** @name INTEN - USB interrupt enable register */ /** @{ */
#define LPC_USB_INTEN_EP_INT_EN_MASK             (0x3FFU)                                            /**< LPC_USB_INTEN.EP_INT_EN Mask            */
#define LPC_USB_INTEN_EP_INT_EN_SHIFT            (0U)                                                /**< LPC_USB_INTEN.EP_INT_EN Position        */
#define LPC_USB_INTEN_EP_INT_EN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTEN_EP_INT_EN_SHIFT))&LPC_USB_INTEN_EP_INT_EN_MASK) /**< LPC_USB_INTEN.EP_INT_EN Field           */
#define LPC_USB_INTEN_FRAME_INT_EN_MASK          (0x40000000U)                                       /**< LPC_USB_INTEN.FRAME_INT_EN Mask         */
#define LPC_USB_INTEN_FRAME_INT_EN_SHIFT         (30U)                                               /**< LPC_USB_INTEN.FRAME_INT_EN Position     */
#define LPC_USB_INTEN_FRAME_INT_EN(x)            (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTEN_FRAME_INT_EN_SHIFT))&LPC_USB_INTEN_FRAME_INT_EN_MASK) /**< LPC_USB_INTEN.FRAME_INT_EN Field        */
#define LPC_USB_INTEN_DEV_INT_EN_MASK            (0x80000000U)                                       /**< LPC_USB_INTEN.DEV_INT_EN Mask           */
#define LPC_USB_INTEN_DEV_INT_EN_SHIFT           (31U)                                               /**< LPC_USB_INTEN.DEV_INT_EN Position       */
#define LPC_USB_INTEN_DEV_INT_EN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTEN_DEV_INT_EN_SHIFT))&LPC_USB_INTEN_DEV_INT_EN_MASK) /**< LPC_USB_INTEN.DEV_INT_EN Field          */
/** @} */

/** @name INTSETSTAT - USB set interrupt status register */ /** @{ */
#define LPC_USB_INTSETSTAT_EP_SET_INT_MASK       (0x3FFU)                                            /**< LPC_USB_INTSETSTAT.EP_SET_INT Mask      */
#define LPC_USB_INTSETSTAT_EP_SET_INT_SHIFT      (0U)                                                /**< LPC_USB_INTSETSTAT.EP_SET_INT Position  */
#define LPC_USB_INTSETSTAT_EP_SET_INT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSETSTAT_EP_SET_INT_SHIFT))&LPC_USB_INTSETSTAT_EP_SET_INT_MASK) /**< LPC_USB_INTSETSTAT.EP_SET_INT Field     */
#define LPC_USB_INTSETSTAT_FRAME_SET_INT_MASK    (0x40000000U)                                       /**< LPC_USB_INTSETSTAT.FRAME_SET_INT Mask   */
#define LPC_USB_INTSETSTAT_FRAME_SET_INT_SHIFT   (30U)                                               /**< LPC_USB_INTSETSTAT.FRAME_SET_INT Position*/
#define LPC_USB_INTSETSTAT_FRAME_SET_INT(x)      (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSETSTAT_FRAME_SET_INT_SHIFT))&LPC_USB_INTSETSTAT_FRAME_SET_INT_MASK) /**< LPC_USB_INTSETSTAT.FRAME_SET_INT Field  */
#define LPC_USB_INTSETSTAT_DEV_SET_INT_MASK      (0x80000000U)                                       /**< LPC_USB_INTSETSTAT.DEV_SET_INT Mask     */
#define LPC_USB_INTSETSTAT_DEV_SET_INT_SHIFT     (31U)                                               /**< LPC_USB_INTSETSTAT.DEV_SET_INT Position */
#define LPC_USB_INTSETSTAT_DEV_SET_INT(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTSETSTAT_DEV_SET_INT_SHIFT))&LPC_USB_INTSETSTAT_DEV_SET_INT_MASK) /**< LPC_USB_INTSETSTAT.DEV_SET_INT Field    */
/** @} */

/** @name INTROUTING - USB interrupt routing register */ /** @{ */
#define LPC_USB_INTROUTING_ROUTE_INT9_0_MASK     (0x3FFU)                                            /**< LPC_USB_INTROUTING.ROUTE_INT9_0 Mask    */
#define LPC_USB_INTROUTING_ROUTE_INT9_0_SHIFT    (0U)                                                /**< LPC_USB_INTROUTING.ROUTE_INT9_0 Position*/
#define LPC_USB_INTROUTING_ROUTE_INT9_0(x)       (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTROUTING_ROUTE_INT9_0_SHIFT))&LPC_USB_INTROUTING_ROUTE_INT9_0_MASK) /**< LPC_USB_INTROUTING.ROUTE_INT9_0 Field   */
#define LPC_USB_INTROUTING_ROUTE_INT30_MASK      (0x40000000U)                                       /**< LPC_USB_INTROUTING.ROUTE_INT30 Mask     */
#define LPC_USB_INTROUTING_ROUTE_INT30_SHIFT     (30U)                                               /**< LPC_USB_INTROUTING.ROUTE_INT30 Position */
#define LPC_USB_INTROUTING_ROUTE_INT30(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTROUTING_ROUTE_INT30_SHIFT))&LPC_USB_INTROUTING_ROUTE_INT30_MASK) /**< LPC_USB_INTROUTING.ROUTE_INT30 Field    */
#define LPC_USB_INTROUTING_ROUTE_INT31_MASK      (0x80000000U)                                       /**< LPC_USB_INTROUTING.ROUTE_INT31 Mask     */
#define LPC_USB_INTROUTING_ROUTE_INT31_SHIFT     (31U)                                               /**< LPC_USB_INTROUTING.ROUTE_INT31 Position */
#define LPC_USB_INTROUTING_ROUTE_INT31(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USB_INTROUTING_ROUTE_INT31_SHIFT))&LPC_USB_INTROUTING_ROUTE_INT31_MASK) /**< LPC_USB_INTROUTING.ROUTE_INT31 Field    */
/** @} */

/** @name EPTOGGLE - USB Endpoint toggle register */ /** @{ */
#define LPC_USB_EPTOGGLE_TOGGLE_MASK             (0x3FFU)                                            /**< LPC_USB_EPTOGGLE.TOGGLE Mask            */
#define LPC_USB_EPTOGGLE_TOGGLE_SHIFT            (0U)                                                /**< LPC_USB_EPTOGGLE.TOGGLE Position        */
#define LPC_USB_EPTOGGLE_TOGGLE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USB_EPTOGGLE_TOGGLE_SHIFT))&LPC_USB_EPTOGGLE_TOGGLE_MASK) /**< LPC_USB_EPTOGGLE.TOGGLE Field           */
/** @} */

/** @} */ /* End group USB_Register_Masks_GROUP */


/* LPC_USB - Peripheral instance base addresses */
#define LPC_USB_BasePtr                0x40080000UL //!< Peripheral base address
#define LPC_USB                        ((LPC_USB_Type *) LPC_USB_BasePtr) //!< Freescale base pointer
#define LPC_USB_BASE_PTR               (LPC_USB) //!< Freescale style base pointer

/** @} */ /* End group USB_Peripheral_access_layer_GROUP */


/** @brief C Struct for WWDT */
/** @ingroup Peripheral_access_layer_GROUP */
/** @addtogroup WWDT_Peripheral_access_layer_GROUP WWDT Peripheral Access Layer */
/** @{ */

/* ================================================================================ */
/* ================           LPC_WWDT (file:WWDT_LPC11Uxx)        ================ */
/* ================================================================================ */

/**
 * @brief Windowed Watchdog Timer
 */
/**
 * @struct LPC_WWDT_Type
 * @brief  C Struct allowing access to WWDT registers
 */
typedef struct LPC_WWDT_Type {
   __IO uint32_t  MOD;                          /**< 0000: Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer */
   __IO uint32_t  TC;                           /**< 0004: Watchdog timer constant register. This 24-bit register determines the time-out value */
   __O  uint32_t  FEED;                         /**< 0008: Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC */
   __I  uint32_t  TV;                           /**< 000C: Watchdog timer value register. This 24-bit register reads out the current value of the Watchdog timer */
   __IO uint32_t  CLKSEL;                       /**< 0010: Watchdog clock select register                               */
   __IO uint32_t  WARNINT;                      /**< 0014: Watchdog Warning Interrupt compare value                     */
   __IO uint32_t  WINDOW;                       /**< 0018: Watchdog Window compare value                                */
} LPC_WWDT_Type;


/** @brief Register Masks for WWDT */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_WWDT' Position & Mask macros                    ----------- */
/* -------------------------------------------------------------------------------- */

/** @addtogroup WWDT_Register_Masks_GROUP WWDT Register Masks */
/** @{ */

/** @name MOD - Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer */ /** @{ */
#define LPC_WWDT_MOD_WDEN_MASK                   (0x1U)                                              /**< LPC_WWDT_MOD.WDEN Mask                  */
#define LPC_WWDT_MOD_WDEN_SHIFT                  (0U)                                                /**< LPC_WWDT_MOD.WDEN Position              */
#define LPC_WWDT_MOD_WDEN(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDEN_SHIFT))&LPC_WWDT_MOD_WDEN_MASK) /**< LPC_WWDT_MOD.WDEN Field                 */
#define LPC_WWDT_MOD_WDRESET_MASK                (0x2U)                                              /**< LPC_WWDT_MOD.WDRESET Mask               */
#define LPC_WWDT_MOD_WDRESET_SHIFT               (1U)                                                /**< LPC_WWDT_MOD.WDRESET Position           */
#define LPC_WWDT_MOD_WDRESET(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDRESET_SHIFT))&LPC_WWDT_MOD_WDRESET_MASK) /**< LPC_WWDT_MOD.WDRESET Field              */
#define LPC_WWDT_MOD_WDTOF_MASK                  (0x4U)                                              /**< LPC_WWDT_MOD.WDTOF Mask                 */
#define LPC_WWDT_MOD_WDTOF_SHIFT                 (2U)                                                /**< LPC_WWDT_MOD.WDTOF Position             */
#define LPC_WWDT_MOD_WDTOF(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDTOF_SHIFT))&LPC_WWDT_MOD_WDTOF_MASK) /**< LPC_WWDT_MOD.WDTOF Field                */
#define LPC_WWDT_MOD_WDINT_MASK                  (0x8U)                                              /**< LPC_WWDT_MOD.WDINT Mask                 */
#define LPC_WWDT_MOD_WDINT_SHIFT                 (3U)                                                /**< LPC_WWDT_MOD.WDINT Position             */
#define LPC_WWDT_MOD_WDINT(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDINT_SHIFT))&LPC_WWDT_MOD_WDINT_MASK) /**< LPC_WWDT_MOD.WDINT Field                */
#define LPC_WWDT_MOD_WDPROTECT_MASK              (0x10U)                                             /**< LPC_WWDT_MOD.WDPROTECT Mask             */
#define LPC_WWDT_MOD_WDPROTECT_SHIFT             (4U)                                                /**< LPC_WWDT_MOD.WDPROTECT Position         */
#define LPC_WWDT_MOD_WDPROTECT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDPROTECT_SHIFT))&LPC_WWDT_MOD_WDPROTECT_MASK) /**< LPC_WWDT_MOD.WDPROTECT Field            */
#define LPC_WWDT_MOD_LOCK_MASK                   (0x20U)                                             /**< LPC_WWDT_MOD.LOCK Mask                  */
#define LPC_WWDT_MOD_LOCK_SHIFT                  (5U)                                                /**< LPC_WWDT_MOD.LOCK Position              */
#define LPC_WWDT_MOD_LOCK(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_LOCK_SHIFT))&LPC_WWDT_MOD_LOCK_MASK) /**< LPC_WWDT_MOD.LOCK Field                 */
/** @} */

/** @name TC - Watchdog timer constant register. This 24-bit register determines the time-out value */ /** @{ */
#define LPC_WWDT_TC_COUNT_MASK                   (0xFFFFFFU)                                         /**< LPC_WWDT_TC.COUNT Mask                  */
#define LPC_WWDT_TC_COUNT_SHIFT                  (0U)                                                /**< LPC_WWDT_TC.COUNT Position              */
#define LPC_WWDT_TC_COUNT(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_TC_COUNT_SHIFT))&LPC_WWDT_TC_COUNT_MASK) /**< LPC_WWDT_TC.COUNT Field                 */
/** @} */

/** @name FEED - Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC */ /** @{ */
#define LPC_WWDT_FEED_FEED_MASK                  (0xFFU)                                             /**< LPC_WWDT_FEED.FEED Mask                 */
#define LPC_WWDT_FEED_FEED_SHIFT                 (0U)                                                /**< LPC_WWDT_FEED.FEED Position             */
#define LPC_WWDT_FEED_FEED(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_FEED_FEED_SHIFT))&LPC_WWDT_FEED_FEED_MASK) /**< LPC_WWDT_FEED.FEED Field                */
/** @} */

/** @name TV - Watchdog timer value register. This 24-bit register reads out the current value of the Watchdog timer */ /** @{ */
#define LPC_WWDT_TV_COUNT_MASK                   (0xFFFFFFU)                                         /**< LPC_WWDT_TV.COUNT Mask                  */
#define LPC_WWDT_TV_COUNT_SHIFT                  (0U)                                                /**< LPC_WWDT_TV.COUNT Position              */
#define LPC_WWDT_TV_COUNT(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_TV_COUNT_SHIFT))&LPC_WWDT_TV_COUNT_MASK) /**< LPC_WWDT_TV.COUNT Field                 */
/** @} */

/** @name CLKSEL - Watchdog clock select register */ /** @{ */
#define LPC_WWDT_CLKSEL_CLKSEL_MASK              (0x1U)                                              /**< LPC_WWDT_CLKSEL.CLKSEL Mask             */
#define LPC_WWDT_CLKSEL_CLKSEL_SHIFT             (0U)                                                /**< LPC_WWDT_CLKSEL.CLKSEL Position         */
#define LPC_WWDT_CLKSEL_CLKSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_CLKSEL_CLKSEL_SHIFT))&LPC_WWDT_CLKSEL_CLKSEL_MASK) /**< LPC_WWDT_CLKSEL.CLKSEL Field            */
#define LPC_WWDT_CLKSEL_LOCK_MASK                (0x80000000U)                                       /**< LPC_WWDT_CLKSEL.LOCK Mask               */
#define LPC_WWDT_CLKSEL_LOCK_SHIFT               (31U)                                               /**< LPC_WWDT_CLKSEL.LOCK Position           */
#define LPC_WWDT_CLKSEL_LOCK(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_CLKSEL_LOCK_SHIFT))&LPC_WWDT_CLKSEL_LOCK_MASK) /**< LPC_WWDT_CLKSEL.LOCK Field              */
/** @} */

/** @name WARNINT - Watchdog Warning Interrupt compare value */ /** @{ */
#define LPC_WWDT_WARNINT_WARNINT_MASK            (0x3FFU)                                            /**< LPC_WWDT_WARNINT.WARNINT Mask           */
#define LPC_WWDT_WARNINT_WARNINT_SHIFT           (0U)                                                /**< LPC_WWDT_WARNINT.WARNINT Position       */
#define LPC_WWDT_WARNINT_WARNINT(x)              (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_WARNINT_WARNINT_SHIFT))&LPC_WWDT_WARNINT_WARNINT_MASK) /**< LPC_WWDT_WARNINT.WARNINT Field          */
/** @} */

/** @name WINDOW - Watchdog Window compare value */ /** @{ */
#define LPC_WWDT_WINDOW_WINDOW_MASK              (0xFFFFFFU)                                         /**< LPC_WWDT_WINDOW.WINDOW Mask             */
#define LPC_WWDT_WINDOW_WINDOW_SHIFT             (0U)                                                /**< LPC_WWDT_WINDOW.WINDOW Position         */
#define LPC_WWDT_WINDOW_WINDOW(x)                (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_WINDOW_WINDOW_SHIFT))&LPC_WWDT_WINDOW_WINDOW_MASK) /**< LPC_WWDT_WINDOW.WINDOW Field            */
/** @} */

/** @} */ /* End group WWDT_Register_Masks_GROUP */


/* LPC_WWDT - Peripheral instance base addresses */
#define LPC_WWDT_BasePtr               0x40004000UL //!< Peripheral base address
#define LPC_WWDT                       ((LPC_WWDT_Type *) LPC_WWDT_BasePtr) //!< Freescale base pointer
#define LPC_WWDT_BASE_PTR              (LPC_WWDT) //!< Freescale style base pointer

/** @} */ /* End group WWDT_Peripheral_access_layer_GROUP */

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


#endif  /* MCU_LPC11UXX */

