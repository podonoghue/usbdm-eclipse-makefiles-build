/****************************************************************************************************//**
 * @file     LPC11Uxx.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for LPC11Uxx.
 *           Equivalent: 
 *
 * @version  V7
 * @date     2017/05
 *
 *******************************************************************************************************/

#ifndef MCU_LPC11UXX
#define MCU_LPC11UXX

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
extern void PIN_INT0_IRQHandler(void);         /**< GPIO pin interrupt                                                               */
extern void PIN_INT1_IRQHandler(void);         /**< GPIO pin interrupt                                                               */
extern void PIN_INT2_IRQHandler(void);         /**< GPIO pin interrupt                                                               */
extern void PIN_INT3_IRQHandler(void);         /**< GPIO pin interrupt                                                               */
extern void PIN_INT4_IRQHandler(void);         /**< GPIO pin interrupt                                                               */
extern void PIN_INT5_IRQHandler(void);         /**< GPIO pin interrupt                                                               */
extern void PIN_INT6_IRQHandler(void);         /**< GPIO pin interrupt                                                               */
extern void PIN_INT7_IRQHandler(void);         /**< GPIO pin interrupt                                                               */
extern void GINT0_IRQHandler(void);            /**< GPIO group interrupt                                                             */
extern void GINT1_IRQHandler(void);            /**< GPIO group interrupt                                                             */
extern void SSP1_IRQHandler(void);             /**< SSP/SPI                                                                          */
extern void I2C_IRQHandler(void);              /**< I2C-bus controller                                                               */
extern void CT16B0_IRQHandler(void);           /**< 16-bit counter/timers CT16B0                                                     */
extern void CT16B1_IRQHandler(void);           /**< 16-bit counter/timers CT16B1                                                     */
extern void CT32B0_IRQHandler(void);           /**< 32-bit counter/timers CT32B0                                                     */
extern void CT32B1_IRQHandler(void);           /**< 32-bit counter/timers CT32B1                                                     */
extern void SSP0_IRQHandler(void);             /**< SSP/SPI                                                                          */
extern void USART_IRQHandler(void);            /**< USART                                                                            */
extern void USB_IRQ_IRQHandler(void);          /**< USB2.0 device controller                                                         */
extern void USB_FIQ_IRQHandler(void);          /**< USB2.0 device controller                                                         */
extern void ADC_IRQHandler(void);              /**< ADC                                                                              */
extern void WDT_IRQHandler(void);              /**< Windowed Watchdog Timer                                                          */
extern void BOD_IRQ_IRQHandler(void);          /**< System control block                                                             */
extern void FLASH_IRQ_IRQHandler(void);        /**< Flash
controller                                                                 */
extern void USBWAKEUP_IRQHandler(void);        /**< USB2.0 device controller                                                         */

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
#define __CM0PLUS_REV             0x0000     /**< CPU Revision                                        */
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
/* ================           ADC (file:ADC_LPC11Uxx)              ================ */
/* ================================================================================ */

/**
 * @brief ADC
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC Structure                                                */
   __IO uint32_t  CR;                           /**< 0000: A/D Control Register. The CR register must be written to select the operating mode before A/D conversion can occur */
   __IO uint32_t  GDR;                          /**< 0004: A/D Global Data Register. Contains the result of the most recent A/D conversion */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  INTEN;                        /**< 000C: A/D Interrupt Enable Register. This register contains enable bits that allow the DONE flag of each A/D channel to be included or excluded from contributing to the generation of an A/D interrupt */
   __I  uint32_t  DR[8];                        /**< 0010: A/D Channel Data Register. This register contains the result of the most recent conversion completed on channel N */
   __I  uint32_t  STAT;                         /**< 0030: A/D Status Register. This register contains DONE and OVERRUN flags for all of the A/D channels, as well as the A/D interrupt flag */
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
/* ------- CR Bit Fields                            ------ */
#define ADC_CR_SEL_MASK                          (0xFFU)                                             /*!< ADC_CR: SEL Mask                        */
#define ADC_CR_SEL_SHIFT                         (0U)                                                /*!< ADC_CR: SEL Position                    */
#define ADC_CR_SEL(x)                            (((uint32_t)(((uint32_t)(x))<<ADC_CR_SEL_SHIFT))&ADC_CR_SEL_MASK) /*!< ADC_CR                                  */
#define ADC_CR_CLKDIV_MASK                       (0xFF00U)                                           /*!< ADC_CR: CLKDIV Mask                     */
#define ADC_CR_CLKDIV_SHIFT                      (8U)                                                /*!< ADC_CR: CLKDIV Position                 */
#define ADC_CR_CLKDIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CR_CLKDIV_SHIFT))&ADC_CR_CLKDIV_MASK) /*!< ADC_CR                                  */
#define ADC_CR_BURST_MASK                        (0x10000U)                                          /*!< ADC_CR: BURST Mask                      */
#define ADC_CR_BURST_SHIFT                       (16U)                                               /*!< ADC_CR: BURST Position                  */
#define ADC_CR_BURST(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_CR_BURST_SHIFT))&ADC_CR_BURST_MASK) /*!< ADC_CR                                  */
#define ADC_CR_CLKS_MASK                         (0xE0000U)                                          /*!< ADC_CR: CLKS Mask                       */
#define ADC_CR_CLKS_SHIFT                        (17U)                                               /*!< ADC_CR: CLKS Position                   */
#define ADC_CR_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_CR_CLKS_SHIFT))&ADC_CR_CLKS_MASK) /*!< ADC_CR                                  */
#define ADC_CR_START_MASK                        (0x7000000U)                                        /*!< ADC_CR: START Mask                      */
#define ADC_CR_START_SHIFT                       (24U)                                               /*!< ADC_CR: START Position                  */
#define ADC_CR_START(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_CR_START_SHIFT))&ADC_CR_START_MASK) /*!< ADC_CR                                  */
#define ADC_CR_EDGE_MASK                         (0x8000000U)                                        /*!< ADC_CR: EDGE Mask                       */
#define ADC_CR_EDGE_SHIFT                        (27U)                                               /*!< ADC_CR: EDGE Position                   */
#define ADC_CR_EDGE(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_CR_EDGE_SHIFT))&ADC_CR_EDGE_MASK) /*!< ADC_CR                                  */
/* ------- GDR Bit Fields                           ------ */
#define ADC_GDR_V_VREF_MASK                      (0xFFC0U)                                           /*!< ADC_GDR: V_VREF Mask                    */
#define ADC_GDR_V_VREF_SHIFT                     (6U)                                                /*!< ADC_GDR: V_VREF Position                */
#define ADC_GDR_V_VREF(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_GDR_V_VREF_SHIFT))&ADC_GDR_V_VREF_MASK) /*!< ADC_GDR                                 */
#define ADC_GDR_CHN_MASK                         (0x7000000U)                                        /*!< ADC_GDR: CHN Mask                       */
#define ADC_GDR_CHN_SHIFT                        (24U)                                               /*!< ADC_GDR: CHN Position                   */
#define ADC_GDR_CHN(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_GDR_CHN_SHIFT))&ADC_GDR_CHN_MASK) /*!< ADC_GDR                                 */
#define ADC_GDR_OVERRUN_MASK                     (0x40000000U)                                       /*!< ADC_GDR: OVERRUN Mask                   */
#define ADC_GDR_OVERRUN_SHIFT                    (30U)                                               /*!< ADC_GDR: OVERRUN Position               */
#define ADC_GDR_OVERRUN(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_GDR_OVERRUN_SHIFT))&ADC_GDR_OVERRUN_MASK) /*!< ADC_GDR                                 */
#define ADC_GDR_DONE_MASK                        (0x80000000U)                                       /*!< ADC_GDR: DONE Mask                      */
#define ADC_GDR_DONE_SHIFT                       (31U)                                               /*!< ADC_GDR: DONE Position                  */
#define ADC_GDR_DONE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_GDR_DONE_SHIFT))&ADC_GDR_DONE_MASK) /*!< ADC_GDR                                 */
/* ------- INTEN Bit Fields                         ------ */
#define ADC_INTEN_ADINTEN_MASK                   (0xFFU)                                             /*!< ADC_INTEN: ADINTEN Mask                 */
#define ADC_INTEN_ADINTEN_SHIFT                  (0U)                                                /*!< ADC_INTEN: ADINTEN Position             */
#define ADC_INTEN_ADINTEN(x)                     (((uint32_t)(((uint32_t)(x))<<ADC_INTEN_ADINTEN_SHIFT))&ADC_INTEN_ADINTEN_MASK) /*!< ADC_INTEN                               */
#define ADC_INTEN_ADGINTEN_MASK                  (0x100U)                                            /*!< ADC_INTEN: ADGINTEN Mask                */
#define ADC_INTEN_ADGINTEN_SHIFT                 (8U)                                                /*!< ADC_INTEN: ADGINTEN Position            */
#define ADC_INTEN_ADGINTEN(x)                    (((uint32_t)(((uint32_t)(x))<<ADC_INTEN_ADGINTEN_SHIFT))&ADC_INTEN_ADGINTEN_MASK) /*!< ADC_INTEN                               */
/* ------- DR Bit Fields                            ------ */
#define ADC_DR_V_VREF_MASK                       (0xFFC0U)                                           /*!< ADC_DR: V_VREF Mask                     */
#define ADC_DR_V_VREF_SHIFT                      (6U)                                                /*!< ADC_DR: V_VREF Position                 */
#define ADC_DR_V_VREF(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_DR_V_VREF_SHIFT))&ADC_DR_V_VREF_MASK) /*!< ADC_DR                                  */
#define ADC_DR_OVERRUN_MASK                      (0x40000000U)                                       /*!< ADC_DR: OVERRUN Mask                    */
#define ADC_DR_OVERRUN_SHIFT                     (30U)                                               /*!< ADC_DR: OVERRUN Position                */
#define ADC_DR_OVERRUN(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_DR_OVERRUN_SHIFT))&ADC_DR_OVERRUN_MASK) /*!< ADC_DR                                  */
#define ADC_DR_DONE_MASK                         (0x80000000U)                                       /*!< ADC_DR: DONE Mask                       */
#define ADC_DR_DONE_SHIFT                        (31U)                                               /*!< ADC_DR: DONE Position                   */
#define ADC_DR_DONE(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_DR_DONE_SHIFT))&ADC_DR_DONE_MASK) /*!< ADC_DR                                  */
/* ------- STAT Bit Fields                          ------ */
#define ADC_STAT_DONE_MASK                       (0xFFU)                                             /*!< ADC_STAT: DONE Mask                     */
#define ADC_STAT_DONE_SHIFT                      (0U)                                                /*!< ADC_STAT: DONE Position                 */
#define ADC_STAT_DONE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_STAT_DONE_SHIFT))&ADC_STAT_DONE_MASK) /*!< ADC_STAT                                */
#define ADC_STAT_OVERRUN_MASK                    (0xFF00U)                                           /*!< ADC_STAT: OVERRUN Mask                  */
#define ADC_STAT_OVERRUN_SHIFT                   (8U)                                                /*!< ADC_STAT: OVERRUN Position              */
#define ADC_STAT_OVERRUN(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_STAT_OVERRUN_SHIFT))&ADC_STAT_OVERRUN_MASK) /*!< ADC_STAT                                */
#define ADC_STAT_ADINT_MASK                      (0x10000U)                                          /*!< ADC_STAT: ADINT Mask                    */
#define ADC_STAT_ADINT_SHIFT                     (16U)                                               /*!< ADC_STAT: ADINT Position                */
#define ADC_STAT_ADINT(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_STAT_ADINT_SHIFT))&ADC_STAT_ADINT_MASK) /*!< ADC_STAT                                */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC - Peripheral instance base addresses */
#define ADC_BasePtr                    0x4001C000UL //!< Peripheral base address
#define ADC                            ((ADC_Type *) ADC_BasePtr) //!< Freescale base pointer
#define ADC_BASE_PTR                   (ADC) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT16B0_Peripheral_access_layer_GROUP CT16B0 Peripheral Access Layer
* @brief C Struct for CT16B0
* @{
*/

/* ================================================================================ */
/* ================           CT16B0 (file:CT16B0_LPC11Uxx)        ================ */
/* ================================================================================ */

/**
 * @brief 16-bit counter/timers CT16B0
 */
/**
* @addtogroup CT16B0_structs_GROUP CT16B0 struct
* @brief Struct for CT16B0
* @{
*/
typedef struct {                                /*       CT16B0 Structure                                             */
   __IO uint32_t  IR;                           /**< 0000: Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */
   __IO uint32_t  TCR;                          /**< 0004: Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  TC;                           /**< 0008: Timer Counter. The 16-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  PR;                           /**< 000C: Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  PC;                           /**< 0010: Prescale Counter. The 16-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  MCR;                          /**< 0014: Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  MR[4];                        /**< 0018: Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */
   __IO uint32_t  CCR;                          /**< 0028: Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  CR0;                          /**< 002C: Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT16B0_CAP0 input */
        uint8_t   RESERVED_0[4];               
   __I  uint32_t  CR1;                          /**< 0034: Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT16B0_CAP1 input */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  EMR;                          /**< 003C: External Match Register. The EMR controls the match function and the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */
        uint8_t   RESERVED_2[48];              
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register. The PWMCON enables PWM mode for the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */
} CT16B0_Type;

/**
 * @} */ /* End group CT16B0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CT16B0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CT16B0_Register_Masks_GROUP CT16B0 Register Masks
* @brief Register Masks for CT16B0
* @{
*/
/* ------- IR Bit Fields                            ------ */
#define CT16B0_IR_MR0INT_MASK                    (0x1U)                                              /*!< CT16B0_IR: MR0INT Mask                  */
#define CT16B0_IR_MR0INT_SHIFT                   (0U)                                                /*!< CT16B0_IR: MR0INT Position              */
#define CT16B0_IR_MR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_IR_MR0INT_SHIFT))&CT16B0_IR_MR0INT_MASK) /*!< CT16B0_IR                               */
#define CT16B0_IR_MR1INT_MASK                    (0x2U)                                              /*!< CT16B0_IR: MR1INT Mask                  */
#define CT16B0_IR_MR1INT_SHIFT                   (1U)                                                /*!< CT16B0_IR: MR1INT Position              */
#define CT16B0_IR_MR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_IR_MR1INT_SHIFT))&CT16B0_IR_MR1INT_MASK) /*!< CT16B0_IR                               */
#define CT16B0_IR_MR2INT_MASK                    (0x4U)                                              /*!< CT16B0_IR: MR2INT Mask                  */
#define CT16B0_IR_MR2INT_SHIFT                   (2U)                                                /*!< CT16B0_IR: MR2INT Position              */
#define CT16B0_IR_MR2INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_IR_MR2INT_SHIFT))&CT16B0_IR_MR2INT_MASK) /*!< CT16B0_IR                               */
#define CT16B0_IR_MR3INT_MASK                    (0x8U)                                              /*!< CT16B0_IR: MR3INT Mask                  */
#define CT16B0_IR_MR3INT_SHIFT                   (3U)                                                /*!< CT16B0_IR: MR3INT Position              */
#define CT16B0_IR_MR3INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_IR_MR3INT_SHIFT))&CT16B0_IR_MR3INT_MASK) /*!< CT16B0_IR                               */
#define CT16B0_IR_CR0INT_MASK                    (0x10U)                                             /*!< CT16B0_IR: CR0INT Mask                  */
#define CT16B0_IR_CR0INT_SHIFT                   (4U)                                                /*!< CT16B0_IR: CR0INT Position              */
#define CT16B0_IR_CR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_IR_CR0INT_SHIFT))&CT16B0_IR_CR0INT_MASK) /*!< CT16B0_IR                               */
#define CT16B0_IR_CR1INT_MASK                    (0x40U)                                             /*!< CT16B0_IR: CR1INT Mask                  */
#define CT16B0_IR_CR1INT_SHIFT                   (6U)                                                /*!< CT16B0_IR: CR1INT Position              */
#define CT16B0_IR_CR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_IR_CR1INT_SHIFT))&CT16B0_IR_CR1INT_MASK) /*!< CT16B0_IR                               */
/* ------- TCR Bit Fields                           ------ */
#define CT16B0_TCR_CEN_MASK                      (0x1U)                                              /*!< CT16B0_TCR: CEN Mask                    */
#define CT16B0_TCR_CEN_SHIFT                     (0U)                                                /*!< CT16B0_TCR: CEN Position                */
#define CT16B0_TCR_CEN(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B0_TCR_CEN_SHIFT))&CT16B0_TCR_CEN_MASK) /*!< CT16B0_TCR                              */
#define CT16B0_TCR_CRST_MASK                     (0x2U)                                              /*!< CT16B0_TCR: CRST Mask                   */
#define CT16B0_TCR_CRST_SHIFT                    (1U)                                                /*!< CT16B0_TCR: CRST Position               */
#define CT16B0_TCR_CRST(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_TCR_CRST_SHIFT))&CT16B0_TCR_CRST_MASK) /*!< CT16B0_TCR                              */
/* ------- TC Bit Fields                            ------ */
#define CT16B0_TC_TC_MASK                        (0xFFFFU)                                           /*!< CT16B0_TC: TC Mask                      */
#define CT16B0_TC_TC_SHIFT                       (0U)                                                /*!< CT16B0_TC: TC Position                  */
#define CT16B0_TC_TC(x)                          (((uint32_t)(((uint32_t)(x))<<CT16B0_TC_TC_SHIFT))&CT16B0_TC_TC_MASK) /*!< CT16B0_TC                               */
/* ------- PR Bit Fields                            ------ */
#define CT16B0_PR_PCVAL_MASK                     (0xFFFFU)                                           /*!< CT16B0_PR: PCVAL Mask                   */
#define CT16B0_PR_PCVAL_SHIFT                    (0U)                                                /*!< CT16B0_PR: PCVAL Position               */
#define CT16B0_PR_PCVAL(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_PR_PCVAL_SHIFT))&CT16B0_PR_PCVAL_MASK) /*!< CT16B0_PR                               */
/* ------- PC Bit Fields                            ------ */
#define CT16B0_PC_PC_MASK                        (0xFFFFU)                                           /*!< CT16B0_PC: PC Mask                      */
#define CT16B0_PC_PC_SHIFT                       (0U)                                                /*!< CT16B0_PC: PC Position                  */
#define CT16B0_PC_PC(x)                          (((uint32_t)(((uint32_t)(x))<<CT16B0_PC_PC_SHIFT))&CT16B0_PC_PC_MASK) /*!< CT16B0_PC                               */
/* ------- MCR Bit Fields                           ------ */
#define CT16B0_MCR_MR0I_MASK                     (0x1U)                                              /*!< CT16B0_MCR: MR0I Mask                   */
#define CT16B0_MCR_MR0I_SHIFT                    (0U)                                                /*!< CT16B0_MCR: MR0I Position               */
#define CT16B0_MCR_MR0I(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR0I_SHIFT))&CT16B0_MCR_MR0I_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR0R_MASK                     (0x2U)                                              /*!< CT16B0_MCR: MR0R Mask                   */
#define CT16B0_MCR_MR0R_SHIFT                    (1U)                                                /*!< CT16B0_MCR: MR0R Position               */
#define CT16B0_MCR_MR0R(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR0R_SHIFT))&CT16B0_MCR_MR0R_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR0S_MASK                     (0x4U)                                              /*!< CT16B0_MCR: MR0S Mask                   */
#define CT16B0_MCR_MR0S_SHIFT                    (2U)                                                /*!< CT16B0_MCR: MR0S Position               */
#define CT16B0_MCR_MR0S(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR0S_SHIFT))&CT16B0_MCR_MR0S_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR1I_MASK                     (0x8U)                                              /*!< CT16B0_MCR: MR1I Mask                   */
#define CT16B0_MCR_MR1I_SHIFT                    (3U)                                                /*!< CT16B0_MCR: MR1I Position               */
#define CT16B0_MCR_MR1I(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR1I_SHIFT))&CT16B0_MCR_MR1I_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR1R_MASK                     (0x10U)                                             /*!< CT16B0_MCR: MR1R Mask                   */
#define CT16B0_MCR_MR1R_SHIFT                    (4U)                                                /*!< CT16B0_MCR: MR1R Position               */
#define CT16B0_MCR_MR1R(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR1R_SHIFT))&CT16B0_MCR_MR1R_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR1S_MASK                     (0x20U)                                             /*!< CT16B0_MCR: MR1S Mask                   */
#define CT16B0_MCR_MR1S_SHIFT                    (5U)                                                /*!< CT16B0_MCR: MR1S Position               */
#define CT16B0_MCR_MR1S(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR1S_SHIFT))&CT16B0_MCR_MR1S_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR2I_MASK                     (0x40U)                                             /*!< CT16B0_MCR: MR2I Mask                   */
#define CT16B0_MCR_MR2I_SHIFT                    (6U)                                                /*!< CT16B0_MCR: MR2I Position               */
#define CT16B0_MCR_MR2I(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR2I_SHIFT))&CT16B0_MCR_MR2I_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR2R_MASK                     (0x80U)                                             /*!< CT16B0_MCR: MR2R Mask                   */
#define CT16B0_MCR_MR2R_SHIFT                    (7U)                                                /*!< CT16B0_MCR: MR2R Position               */
#define CT16B0_MCR_MR2R(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR2R_SHIFT))&CT16B0_MCR_MR2R_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR2S_MASK                     (0x100U)                                            /*!< CT16B0_MCR: MR2S Mask                   */
#define CT16B0_MCR_MR2S_SHIFT                    (8U)                                                /*!< CT16B0_MCR: MR2S Position               */
#define CT16B0_MCR_MR2S(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR2S_SHIFT))&CT16B0_MCR_MR2S_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR3I_MASK                     (0x200U)                                            /*!< CT16B0_MCR: MR3I Mask                   */
#define CT16B0_MCR_MR3I_SHIFT                    (9U)                                                /*!< CT16B0_MCR: MR3I Position               */
#define CT16B0_MCR_MR3I(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR3I_SHIFT))&CT16B0_MCR_MR3I_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR3R_MASK                     (0x400U)                                            /*!< CT16B0_MCR: MR3R Mask                   */
#define CT16B0_MCR_MR3R_SHIFT                    (10U)                                               /*!< CT16B0_MCR: MR3R Position               */
#define CT16B0_MCR_MR3R(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR3R_SHIFT))&CT16B0_MCR_MR3R_MASK) /*!< CT16B0_MCR                              */
#define CT16B0_MCR_MR3S_MASK                     (0x800U)                                            /*!< CT16B0_MCR: MR3S Mask                   */
#define CT16B0_MCR_MR3S_SHIFT                    (11U)                                               /*!< CT16B0_MCR: MR3S Position               */
#define CT16B0_MCR_MR3S(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MCR_MR3S_SHIFT))&CT16B0_MCR_MR3S_MASK) /*!< CT16B0_MCR                              */
/* ------- MR Bit Fields                            ------ */
#define CT16B0_MR_MATCH_MASK                     (0xFFFFU)                                           /*!< CT16B0_MR: MATCH Mask                   */
#define CT16B0_MR_MATCH_SHIFT                    (0U)                                                /*!< CT16B0_MR: MATCH Position               */
#define CT16B0_MR_MATCH(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_MR_MATCH_SHIFT))&CT16B0_MR_MATCH_MASK) /*!< CT16B0_MR                               */
/* ------- CCR Bit Fields                           ------ */
#define CT16B0_CCR_CAP0RE_MASK                   (0x1U)                                              /*!< CT16B0_CCR: CAP0RE Mask                 */
#define CT16B0_CCR_CAP0RE_SHIFT                  (0U)                                                /*!< CT16B0_CCR: CAP0RE Position             */
#define CT16B0_CCR_CAP0RE(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B0_CCR_CAP0RE_SHIFT))&CT16B0_CCR_CAP0RE_MASK) /*!< CT16B0_CCR                              */
#define CT16B0_CCR_CAP0FE_MASK                   (0x2U)                                              /*!< CT16B0_CCR: CAP0FE Mask                 */
#define CT16B0_CCR_CAP0FE_SHIFT                  (1U)                                                /*!< CT16B0_CCR: CAP0FE Position             */
#define CT16B0_CCR_CAP0FE(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B0_CCR_CAP0FE_SHIFT))&CT16B0_CCR_CAP0FE_MASK) /*!< CT16B0_CCR                              */
#define CT16B0_CCR_CAP0I_MASK                    (0x4U)                                              /*!< CT16B0_CCR: CAP0I Mask                  */
#define CT16B0_CCR_CAP0I_SHIFT                   (2U)                                                /*!< CT16B0_CCR: CAP0I Position              */
#define CT16B0_CCR_CAP0I(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_CCR_CAP0I_SHIFT))&CT16B0_CCR_CAP0I_MASK) /*!< CT16B0_CCR                              */
#define CT16B0_CCR_CAP1RE_MASK                   (0x40U)                                             /*!< CT16B0_CCR: CAP1RE Mask                 */
#define CT16B0_CCR_CAP1RE_SHIFT                  (6U)                                                /*!< CT16B0_CCR: CAP1RE Position             */
#define CT16B0_CCR_CAP1RE(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B0_CCR_CAP1RE_SHIFT))&CT16B0_CCR_CAP1RE_MASK) /*!< CT16B0_CCR                              */
#define CT16B0_CCR_CAP1FE_MASK                   (0x80U)                                             /*!< CT16B0_CCR: CAP1FE Mask                 */
#define CT16B0_CCR_CAP1FE_SHIFT                  (7U)                                                /*!< CT16B0_CCR: CAP1FE Position             */
#define CT16B0_CCR_CAP1FE(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B0_CCR_CAP1FE_SHIFT))&CT16B0_CCR_CAP1FE_MASK) /*!< CT16B0_CCR                              */
#define CT16B0_CCR_CAP1I_MASK                    (0x100U)                                            /*!< CT16B0_CCR: CAP1I Mask                  */
#define CT16B0_CCR_CAP1I_SHIFT                   (8U)                                                /*!< CT16B0_CCR: CAP1I Position              */
#define CT16B0_CCR_CAP1I(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_CCR_CAP1I_SHIFT))&CT16B0_CCR_CAP1I_MASK) /*!< CT16B0_CCR                              */
/* ------- CR0 Bit Fields                           ------ */
#define CT16B0_CR0_CAP_MASK                      (0xFFFFU)                                           /*!< CT16B0_CR0: CAP Mask                    */
#define CT16B0_CR0_CAP_SHIFT                     (0U)                                                /*!< CT16B0_CR0: CAP Position                */
#define CT16B0_CR0_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B0_CR0_CAP_SHIFT))&CT16B0_CR0_CAP_MASK) /*!< CT16B0_CR0                              */
/* ------- CR1 Bit Fields                           ------ */
#define CT16B0_CR1_CAP_MASK                      (0xFFFFU)                                           /*!< CT16B0_CR1: CAP Mask                    */
#define CT16B0_CR1_CAP_SHIFT                     (0U)                                                /*!< CT16B0_CR1: CAP Position                */
#define CT16B0_CR1_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B0_CR1_CAP_SHIFT))&CT16B0_CR1_CAP_MASK) /*!< CT16B0_CR1                              */
/* ------- EMR Bit Fields                           ------ */
#define CT16B0_EMR_EM0_MASK                      (0x1U)                                              /*!< CT16B0_EMR: EM0 Mask                    */
#define CT16B0_EMR_EM0_SHIFT                     (0U)                                                /*!< CT16B0_EMR: EM0 Position                */
#define CT16B0_EMR_EM0(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B0_EMR_EM0_SHIFT))&CT16B0_EMR_EM0_MASK) /*!< CT16B0_EMR                              */
#define CT16B0_EMR_EM1_MASK                      (0x2U)                                              /*!< CT16B0_EMR: EM1 Mask                    */
#define CT16B0_EMR_EM1_SHIFT                     (1U)                                                /*!< CT16B0_EMR: EM1 Position                */
#define CT16B0_EMR_EM1(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B0_EMR_EM1_SHIFT))&CT16B0_EMR_EM1_MASK) /*!< CT16B0_EMR                              */
#define CT16B0_EMR_EM2_MASK                      (0x4U)                                              /*!< CT16B0_EMR: EM2 Mask                    */
#define CT16B0_EMR_EM2_SHIFT                     (2U)                                                /*!< CT16B0_EMR: EM2 Position                */
#define CT16B0_EMR_EM2(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B0_EMR_EM2_SHIFT))&CT16B0_EMR_EM2_MASK) /*!< CT16B0_EMR                              */
#define CT16B0_EMR_EM3_MASK                      (0x8U)                                              /*!< CT16B0_EMR: EM3 Mask                    */
#define CT16B0_EMR_EM3_SHIFT                     (3U)                                                /*!< CT16B0_EMR: EM3 Position                */
#define CT16B0_EMR_EM3(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B0_EMR_EM3_SHIFT))&CT16B0_EMR_EM3_MASK) /*!< CT16B0_EMR                              */
#define CT16B0_EMR_EMC0_MASK                     (0x30U)                                             /*!< CT16B0_EMR: EMC0 Mask                   */
#define CT16B0_EMR_EMC0_SHIFT                    (4U)                                                /*!< CT16B0_EMR: EMC0 Position               */
#define CT16B0_EMR_EMC0(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_EMR_EMC0_SHIFT))&CT16B0_EMR_EMC0_MASK) /*!< CT16B0_EMR                              */
#define CT16B0_EMR_EMC1_MASK                     (0xC0U)                                             /*!< CT16B0_EMR: EMC1 Mask                   */
#define CT16B0_EMR_EMC1_SHIFT                    (6U)                                                /*!< CT16B0_EMR: EMC1 Position               */
#define CT16B0_EMR_EMC1(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_EMR_EMC1_SHIFT))&CT16B0_EMR_EMC1_MASK) /*!< CT16B0_EMR                              */
#define CT16B0_EMR_EMC2_MASK                     (0x300U)                                            /*!< CT16B0_EMR: EMC2 Mask                   */
#define CT16B0_EMR_EMC2_SHIFT                    (8U)                                                /*!< CT16B0_EMR: EMC2 Position               */
#define CT16B0_EMR_EMC2(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_EMR_EMC2_SHIFT))&CT16B0_EMR_EMC2_MASK) /*!< CT16B0_EMR                              */
#define CT16B0_EMR_EMC3_MASK                     (0xC00U)                                            /*!< CT16B0_EMR: EMC3 Mask                   */
#define CT16B0_EMR_EMC3_SHIFT                    (10U)                                               /*!< CT16B0_EMR: EMC3 Position               */
#define CT16B0_EMR_EMC3(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_EMR_EMC3_SHIFT))&CT16B0_EMR_EMC3_MASK) /*!< CT16B0_EMR                              */
/* ------- CTCR Bit Fields                          ------ */
#define CT16B0_CTCR_CTM_MASK                     (0x3U)                                              /*!< CT16B0_CTCR: CTM Mask                   */
#define CT16B0_CTCR_CTM_SHIFT                    (0U)                                                /*!< CT16B0_CTCR: CTM Position               */
#define CT16B0_CTCR_CTM(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_CTCR_CTM_SHIFT))&CT16B0_CTCR_CTM_MASK) /*!< CT16B0_CTCR                             */
#define CT16B0_CTCR_CIS_MASK                     (0xCU)                                              /*!< CT16B0_CTCR: CIS Mask                   */
#define CT16B0_CTCR_CIS_SHIFT                    (2U)                                                /*!< CT16B0_CTCR: CIS Position               */
#define CT16B0_CTCR_CIS(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B0_CTCR_CIS_SHIFT))&CT16B0_CTCR_CIS_MASK) /*!< CT16B0_CTCR                             */
#define CT16B0_CTCR_ENCC_MASK                    (0x10U)                                             /*!< CT16B0_CTCR: ENCC Mask                  */
#define CT16B0_CTCR_ENCC_SHIFT                   (4U)                                                /*!< CT16B0_CTCR: ENCC Position              */
#define CT16B0_CTCR_ENCC(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B0_CTCR_ENCC_SHIFT))&CT16B0_CTCR_ENCC_MASK) /*!< CT16B0_CTCR                             */
#define CT16B0_CTCR_SELCC_MASK                   (0xE0U)                                             /*!< CT16B0_CTCR: SELCC Mask                 */
#define CT16B0_CTCR_SELCC_SHIFT                  (5U)                                                /*!< CT16B0_CTCR: SELCC Position             */
#define CT16B0_CTCR_SELCC(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B0_CTCR_SELCC_SHIFT))&CT16B0_CTCR_SELCC_MASK) /*!< CT16B0_CTCR                             */
/* ------- PWMC Bit Fields                          ------ */
#define CT16B0_PWMC_PWMEN0_MASK                  (0x1U)                                              /*!< CT16B0_PWMC: PWMEN0 Mask                */
#define CT16B0_PWMC_PWMEN0_SHIFT                 (0U)                                                /*!< CT16B0_PWMC: PWMEN0 Position            */
#define CT16B0_PWMC_PWMEN0(x)                    (((uint32_t)(((uint32_t)(x))<<CT16B0_PWMC_PWMEN0_SHIFT))&CT16B0_PWMC_PWMEN0_MASK) /*!< CT16B0_PWMC                             */
#define CT16B0_PWMC_PWMEN1_MASK                  (0x2U)                                              /*!< CT16B0_PWMC: PWMEN1 Mask                */
#define CT16B0_PWMC_PWMEN1_SHIFT                 (1U)                                                /*!< CT16B0_PWMC: PWMEN1 Position            */
#define CT16B0_PWMC_PWMEN1(x)                    (((uint32_t)(((uint32_t)(x))<<CT16B0_PWMC_PWMEN1_SHIFT))&CT16B0_PWMC_PWMEN1_MASK) /*!< CT16B0_PWMC                             */
#define CT16B0_PWMC_PWMEN2_MASK                  (0x4U)                                              /*!< CT16B0_PWMC: PWMEN2 Mask                */
#define CT16B0_PWMC_PWMEN2_SHIFT                 (2U)                                                /*!< CT16B0_PWMC: PWMEN2 Position            */
#define CT16B0_PWMC_PWMEN2(x)                    (((uint32_t)(((uint32_t)(x))<<CT16B0_PWMC_PWMEN2_SHIFT))&CT16B0_PWMC_PWMEN2_MASK) /*!< CT16B0_PWMC                             */
#define CT16B0_PWMC_PWMEN3_MASK                  (0x8U)                                              /*!< CT16B0_PWMC: PWMEN3 Mask                */
#define CT16B0_PWMC_PWMEN3_SHIFT                 (3U)                                                /*!< CT16B0_PWMC: PWMEN3 Position            */
#define CT16B0_PWMC_PWMEN3(x)                    (((uint32_t)(((uint32_t)(x))<<CT16B0_PWMC_PWMEN3_SHIFT))&CT16B0_PWMC_PWMEN3_MASK) /*!< CT16B0_PWMC                             */
/**
 * @} */ /* End group CT16B0_Register_Masks_GROUP 
 */

/* CT16B0 - Peripheral instance base addresses */
#define CT16B0_BasePtr                 0x4000C000UL //!< Peripheral base address
#define CT16B0                         ((CT16B0_Type *) CT16B0_BasePtr) //!< Freescale base pointer
#define CT16B0_BASE_PTR                (CT16B0) //!< Freescale style base pointer
/**
 * @} */ /* End group CT16B0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT16B_Peripheral_access_layer_GROUP CT16B Peripheral Access Layer
* @brief C Struct for CT16B
* @{
*/

/* ================================================================================ */
/* ================           CT16B1 (file:CT16B1_LPC11Uxx)        ================ */
/* ================================================================================ */

/**
 * @brief 16-bit counter/timers CT16B1
 */
/**
* @addtogroup CT16B_structs_GROUP CT16B struct
* @brief Struct for CT16B
* @{
*/
typedef struct {                                /*       CT16B1 Structure                                             */
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
        uint8_t   RESERVED_0[8];               
   __IO uint32_t  EMR;                          /**< 003C: External Match Register. The EMR controls the match function and the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register. The PWMCON enables PWM mode for the external match pins CT16B0_MAT[1:0] and CT16B1_MAT[1:0] */
} CT16B1_Type;

/**
 * @} */ /* End group CT16B_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CT16B1' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CT16B_Register_Masks_GROUP CT16B Register Masks
* @brief Register Masks for CT16B
* @{
*/
/* ------- IR Bit Fields                            ------ */
#define CT16B1_IR_MR0INT_MASK                    (0x1U)                                              /*!< CT16B1_IR: MR0INT Mask                  */
#define CT16B1_IR_MR0INT_SHIFT                   (0U)                                                /*!< CT16B1_IR: MR0INT Position              */
#define CT16B1_IR_MR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_IR_MR0INT_SHIFT))&CT16B1_IR_MR0INT_MASK) /*!< CT16B1_IR                               */
#define CT16B1_IR_MR1INT_MASK                    (0x2U)                                              /*!< CT16B1_IR: MR1INT Mask                  */
#define CT16B1_IR_MR1INT_SHIFT                   (1U)                                                /*!< CT16B1_IR: MR1INT Position              */
#define CT16B1_IR_MR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_IR_MR1INT_SHIFT))&CT16B1_IR_MR1INT_MASK) /*!< CT16B1_IR                               */
#define CT16B1_IR_MR2INT_MASK                    (0x4U)                                              /*!< CT16B1_IR: MR2INT Mask                  */
#define CT16B1_IR_MR2INT_SHIFT                   (2U)                                                /*!< CT16B1_IR: MR2INT Position              */
#define CT16B1_IR_MR2INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_IR_MR2INT_SHIFT))&CT16B1_IR_MR2INT_MASK) /*!< CT16B1_IR                               */
#define CT16B1_IR_MR3INT_MASK                    (0x8U)                                              /*!< CT16B1_IR: MR3INT Mask                  */
#define CT16B1_IR_MR3INT_SHIFT                   (3U)                                                /*!< CT16B1_IR: MR3INT Position              */
#define CT16B1_IR_MR3INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_IR_MR3INT_SHIFT))&CT16B1_IR_MR3INT_MASK) /*!< CT16B1_IR                               */
#define CT16B1_IR_CR0INT_MASK                    (0x10U)                                             /*!< CT16B1_IR: CR0INT Mask                  */
#define CT16B1_IR_CR0INT_SHIFT                   (4U)                                                /*!< CT16B1_IR: CR0INT Position              */
#define CT16B1_IR_CR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_IR_CR0INT_SHIFT))&CT16B1_IR_CR0INT_MASK) /*!< CT16B1_IR                               */
#define CT16B1_IR_CR1INT_MASK                    (0x20U)                                             /*!< CT16B1_IR: CR1INT Mask                  */
#define CT16B1_IR_CR1INT_SHIFT                   (5U)                                                /*!< CT16B1_IR: CR1INT Position              */
#define CT16B1_IR_CR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_IR_CR1INT_SHIFT))&CT16B1_IR_CR1INT_MASK) /*!< CT16B1_IR                               */
/* ------- TCR Bit Fields                           ------ */
#define CT16B1_TCR_CEN_MASK                      (0x1U)                                              /*!< CT16B1_TCR: CEN Mask                    */
#define CT16B1_TCR_CEN_SHIFT                     (0U)                                                /*!< CT16B1_TCR: CEN Position                */
#define CT16B1_TCR_CEN(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B1_TCR_CEN_SHIFT))&CT16B1_TCR_CEN_MASK) /*!< CT16B1_TCR                              */
#define CT16B1_TCR_CRST_MASK                     (0x2U)                                              /*!< CT16B1_TCR: CRST Mask                   */
#define CT16B1_TCR_CRST_SHIFT                    (1U)                                                /*!< CT16B1_TCR: CRST Position               */
#define CT16B1_TCR_CRST(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_TCR_CRST_SHIFT))&CT16B1_TCR_CRST_MASK) /*!< CT16B1_TCR                              */
/* ------- TC Bit Fields                            ------ */
#define CT16B1_TC_TC_MASK                        (0xFFFFU)                                           /*!< CT16B1_TC: TC Mask                      */
#define CT16B1_TC_TC_SHIFT                       (0U)                                                /*!< CT16B1_TC: TC Position                  */
#define CT16B1_TC_TC(x)                          (((uint32_t)(((uint32_t)(x))<<CT16B1_TC_TC_SHIFT))&CT16B1_TC_TC_MASK) /*!< CT16B1_TC                               */
/* ------- PR Bit Fields                            ------ */
#define CT16B1_PR_PCVAL_MASK                     (0xFFFFU)                                           /*!< CT16B1_PR: PCVAL Mask                   */
#define CT16B1_PR_PCVAL_SHIFT                    (0U)                                                /*!< CT16B1_PR: PCVAL Position               */
#define CT16B1_PR_PCVAL(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_PR_PCVAL_SHIFT))&CT16B1_PR_PCVAL_MASK) /*!< CT16B1_PR                               */
/* ------- PC Bit Fields                            ------ */
#define CT16B1_PC_PC_MASK                        (0xFFFFU)                                           /*!< CT16B1_PC: PC Mask                      */
#define CT16B1_PC_PC_SHIFT                       (0U)                                                /*!< CT16B1_PC: PC Position                  */
#define CT16B1_PC_PC(x)                          (((uint32_t)(((uint32_t)(x))<<CT16B1_PC_PC_SHIFT))&CT16B1_PC_PC_MASK) /*!< CT16B1_PC                               */
/* ------- MCR Bit Fields                           ------ */
#define CT16B1_MCR_MR0I_MASK                     (0x1U)                                              /*!< CT16B1_MCR: MR0I Mask                   */
#define CT16B1_MCR_MR0I_SHIFT                    (0U)                                                /*!< CT16B1_MCR: MR0I Position               */
#define CT16B1_MCR_MR0I(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR0I_SHIFT))&CT16B1_MCR_MR0I_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR0R_MASK                     (0x2U)                                              /*!< CT16B1_MCR: MR0R Mask                   */
#define CT16B1_MCR_MR0R_SHIFT                    (1U)                                                /*!< CT16B1_MCR: MR0R Position               */
#define CT16B1_MCR_MR0R(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR0R_SHIFT))&CT16B1_MCR_MR0R_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR0S_MASK                     (0x4U)                                              /*!< CT16B1_MCR: MR0S Mask                   */
#define CT16B1_MCR_MR0S_SHIFT                    (2U)                                                /*!< CT16B1_MCR: MR0S Position               */
#define CT16B1_MCR_MR0S(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR0S_SHIFT))&CT16B1_MCR_MR0S_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR1I_MASK                     (0x8U)                                              /*!< CT16B1_MCR: MR1I Mask                   */
#define CT16B1_MCR_MR1I_SHIFT                    (3U)                                                /*!< CT16B1_MCR: MR1I Position               */
#define CT16B1_MCR_MR1I(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR1I_SHIFT))&CT16B1_MCR_MR1I_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR1R_MASK                     (0x10U)                                             /*!< CT16B1_MCR: MR1R Mask                   */
#define CT16B1_MCR_MR1R_SHIFT                    (4U)                                                /*!< CT16B1_MCR: MR1R Position               */
#define CT16B1_MCR_MR1R(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR1R_SHIFT))&CT16B1_MCR_MR1R_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR1S_MASK                     (0x20U)                                             /*!< CT16B1_MCR: MR1S Mask                   */
#define CT16B1_MCR_MR1S_SHIFT                    (5U)                                                /*!< CT16B1_MCR: MR1S Position               */
#define CT16B1_MCR_MR1S(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR1S_SHIFT))&CT16B1_MCR_MR1S_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR2I_MASK                     (0x40U)                                             /*!< CT16B1_MCR: MR2I Mask                   */
#define CT16B1_MCR_MR2I_SHIFT                    (6U)                                                /*!< CT16B1_MCR: MR2I Position               */
#define CT16B1_MCR_MR2I(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR2I_SHIFT))&CT16B1_MCR_MR2I_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR2R_MASK                     (0x80U)                                             /*!< CT16B1_MCR: MR2R Mask                   */
#define CT16B1_MCR_MR2R_SHIFT                    (7U)                                                /*!< CT16B1_MCR: MR2R Position               */
#define CT16B1_MCR_MR2R(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR2R_SHIFT))&CT16B1_MCR_MR2R_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR2S_MASK                     (0x100U)                                            /*!< CT16B1_MCR: MR2S Mask                   */
#define CT16B1_MCR_MR2S_SHIFT                    (8U)                                                /*!< CT16B1_MCR: MR2S Position               */
#define CT16B1_MCR_MR2S(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR2S_SHIFT))&CT16B1_MCR_MR2S_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR3I_MASK                     (0x200U)                                            /*!< CT16B1_MCR: MR3I Mask                   */
#define CT16B1_MCR_MR3I_SHIFT                    (9U)                                                /*!< CT16B1_MCR: MR3I Position               */
#define CT16B1_MCR_MR3I(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR3I_SHIFT))&CT16B1_MCR_MR3I_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR3R_MASK                     (0x400U)                                            /*!< CT16B1_MCR: MR3R Mask                   */
#define CT16B1_MCR_MR3R_SHIFT                    (10U)                                               /*!< CT16B1_MCR: MR3R Position               */
#define CT16B1_MCR_MR3R(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR3R_SHIFT))&CT16B1_MCR_MR3R_MASK) /*!< CT16B1_MCR                              */
#define CT16B1_MCR_MR3S_MASK                     (0x800U)                                            /*!< CT16B1_MCR: MR3S Mask                   */
#define CT16B1_MCR_MR3S_SHIFT                    (11U)                                               /*!< CT16B1_MCR: MR3S Position               */
#define CT16B1_MCR_MR3S(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MCR_MR3S_SHIFT))&CT16B1_MCR_MR3S_MASK) /*!< CT16B1_MCR                              */
/* ------- MR Bit Fields                            ------ */
#define CT16B1_MR_MATCH_MASK                     (0xFFFFU)                                           /*!< CT16B1_MR: MATCH Mask                   */
#define CT16B1_MR_MATCH_SHIFT                    (0U)                                                /*!< CT16B1_MR: MATCH Position               */
#define CT16B1_MR_MATCH(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_MR_MATCH_SHIFT))&CT16B1_MR_MATCH_MASK) /*!< CT16B1_MR                               */
/* ------- CCR Bit Fields                           ------ */
#define CT16B1_CCR_CAP0RE_MASK                   (0x1U)                                              /*!< CT16B1_CCR: CAP0RE Mask                 */
#define CT16B1_CCR_CAP0RE_SHIFT                  (0U)                                                /*!< CT16B1_CCR: CAP0RE Position             */
#define CT16B1_CCR_CAP0RE(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B1_CCR_CAP0RE_SHIFT))&CT16B1_CCR_CAP0RE_MASK) /*!< CT16B1_CCR                              */
#define CT16B1_CCR_CAP0FE_MASK                   (0x2U)                                              /*!< CT16B1_CCR: CAP0FE Mask                 */
#define CT16B1_CCR_CAP0FE_SHIFT                  (1U)                                                /*!< CT16B1_CCR: CAP0FE Position             */
#define CT16B1_CCR_CAP0FE(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B1_CCR_CAP0FE_SHIFT))&CT16B1_CCR_CAP0FE_MASK) /*!< CT16B1_CCR                              */
#define CT16B1_CCR_CAP0I_MASK                    (0x4U)                                              /*!< CT16B1_CCR: CAP0I Mask                  */
#define CT16B1_CCR_CAP0I_SHIFT                   (2U)                                                /*!< CT16B1_CCR: CAP0I Position              */
#define CT16B1_CCR_CAP0I(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_CCR_CAP0I_SHIFT))&CT16B1_CCR_CAP0I_MASK) /*!< CT16B1_CCR                              */
#define CT16B1_CCR_CAP1RE_MASK                   (0x8U)                                              /*!< CT16B1_CCR: CAP1RE Mask                 */
#define CT16B1_CCR_CAP1RE_SHIFT                  (3U)                                                /*!< CT16B1_CCR: CAP1RE Position             */
#define CT16B1_CCR_CAP1RE(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B1_CCR_CAP1RE_SHIFT))&CT16B1_CCR_CAP1RE_MASK) /*!< CT16B1_CCR                              */
#define CT16B1_CCR_CAP1FE_MASK                   (0x10U)                                             /*!< CT16B1_CCR: CAP1FE Mask                 */
#define CT16B1_CCR_CAP1FE_SHIFT                  (4U)                                                /*!< CT16B1_CCR: CAP1FE Position             */
#define CT16B1_CCR_CAP1FE(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B1_CCR_CAP1FE_SHIFT))&CT16B1_CCR_CAP1FE_MASK) /*!< CT16B1_CCR                              */
#define CT16B1_CCR_CAP1I_MASK                    (0x20U)                                             /*!< CT16B1_CCR: CAP1I Mask                  */
#define CT16B1_CCR_CAP1I_SHIFT                   (5U)                                                /*!< CT16B1_CCR: CAP1I Position              */
#define CT16B1_CCR_CAP1I(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_CCR_CAP1I_SHIFT))&CT16B1_CCR_CAP1I_MASK) /*!< CT16B1_CCR                              */
/* ------- CR0 Bit Fields                           ------ */
#define CT16B1_CR0_CAP_MASK                      (0xFFFFU)                                           /*!< CT16B1_CR0: CAP Mask                    */
#define CT16B1_CR0_CAP_SHIFT                     (0U)                                                /*!< CT16B1_CR0: CAP Position                */
#define CT16B1_CR0_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B1_CR0_CAP_SHIFT))&CT16B1_CR0_CAP_MASK) /*!< CT16B1_CR0                              */
/* ------- CR1 Bit Fields                           ------ */
#define CT16B1_CR1_CAP_MASK                      (0xFFFFU)                                           /*!< CT16B1_CR1: CAP Mask                    */
#define CT16B1_CR1_CAP_SHIFT                     (0U)                                                /*!< CT16B1_CR1: CAP Position                */
#define CT16B1_CR1_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B1_CR1_CAP_SHIFT))&CT16B1_CR1_CAP_MASK) /*!< CT16B1_CR1                              */
/* ------- EMR Bit Fields                           ------ */
#define CT16B1_EMR_EM0_MASK                      (0x1U)                                              /*!< CT16B1_EMR: EM0 Mask                    */
#define CT16B1_EMR_EM0_SHIFT                     (0U)                                                /*!< CT16B1_EMR: EM0 Position                */
#define CT16B1_EMR_EM0(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B1_EMR_EM0_SHIFT))&CT16B1_EMR_EM0_MASK) /*!< CT16B1_EMR                              */
#define CT16B1_EMR_EM1_MASK                      (0x2U)                                              /*!< CT16B1_EMR: EM1 Mask                    */
#define CT16B1_EMR_EM1_SHIFT                     (1U)                                                /*!< CT16B1_EMR: EM1 Position                */
#define CT16B1_EMR_EM1(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B1_EMR_EM1_SHIFT))&CT16B1_EMR_EM1_MASK) /*!< CT16B1_EMR                              */
#define CT16B1_EMR_EM2_MASK                      (0x4U)                                              /*!< CT16B1_EMR: EM2 Mask                    */
#define CT16B1_EMR_EM2_SHIFT                     (2U)                                                /*!< CT16B1_EMR: EM2 Position                */
#define CT16B1_EMR_EM2(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B1_EMR_EM2_SHIFT))&CT16B1_EMR_EM2_MASK) /*!< CT16B1_EMR                              */
#define CT16B1_EMR_EM3_MASK                      (0x8U)                                              /*!< CT16B1_EMR: EM3 Mask                    */
#define CT16B1_EMR_EM3_SHIFT                     (3U)                                                /*!< CT16B1_EMR: EM3 Position                */
#define CT16B1_EMR_EM3(x)                        (((uint32_t)(((uint32_t)(x))<<CT16B1_EMR_EM3_SHIFT))&CT16B1_EMR_EM3_MASK) /*!< CT16B1_EMR                              */
#define CT16B1_EMR_EMC0_MASK                     (0x30U)                                             /*!< CT16B1_EMR: EMC0 Mask                   */
#define CT16B1_EMR_EMC0_SHIFT                    (4U)                                                /*!< CT16B1_EMR: EMC0 Position               */
#define CT16B1_EMR_EMC0(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_EMR_EMC0_SHIFT))&CT16B1_EMR_EMC0_MASK) /*!< CT16B1_EMR                              */
#define CT16B1_EMR_EMC1_MASK                     (0xC0U)                                             /*!< CT16B1_EMR: EMC1 Mask                   */
#define CT16B1_EMR_EMC1_SHIFT                    (6U)                                                /*!< CT16B1_EMR: EMC1 Position               */
#define CT16B1_EMR_EMC1(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_EMR_EMC1_SHIFT))&CT16B1_EMR_EMC1_MASK) /*!< CT16B1_EMR                              */
#define CT16B1_EMR_EMC2_MASK                     (0x300U)                                            /*!< CT16B1_EMR: EMC2 Mask                   */
#define CT16B1_EMR_EMC2_SHIFT                    (8U)                                                /*!< CT16B1_EMR: EMC2 Position               */
#define CT16B1_EMR_EMC2(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_EMR_EMC2_SHIFT))&CT16B1_EMR_EMC2_MASK) /*!< CT16B1_EMR                              */
#define CT16B1_EMR_EMC3_MASK                     (0xC00U)                                            /*!< CT16B1_EMR: EMC3 Mask                   */
#define CT16B1_EMR_EMC3_SHIFT                    (10U)                                               /*!< CT16B1_EMR: EMC3 Position               */
#define CT16B1_EMR_EMC3(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_EMR_EMC3_SHIFT))&CT16B1_EMR_EMC3_MASK) /*!< CT16B1_EMR                              */
/* ------- CTCR Bit Fields                          ------ */
#define CT16B1_CTCR_CTM_MASK                     (0x3U)                                              /*!< CT16B1_CTCR: CTM Mask                   */
#define CT16B1_CTCR_CTM_SHIFT                    (0U)                                                /*!< CT16B1_CTCR: CTM Position               */
#define CT16B1_CTCR_CTM(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_CTCR_CTM_SHIFT))&CT16B1_CTCR_CTM_MASK) /*!< CT16B1_CTCR                             */
#define CT16B1_CTCR_CIS_MASK                     (0xCU)                                              /*!< CT16B1_CTCR: CIS Mask                   */
#define CT16B1_CTCR_CIS_SHIFT                    (2U)                                                /*!< CT16B1_CTCR: CIS Position               */
#define CT16B1_CTCR_CIS(x)                       (((uint32_t)(((uint32_t)(x))<<CT16B1_CTCR_CIS_SHIFT))&CT16B1_CTCR_CIS_MASK) /*!< CT16B1_CTCR                             */
#define CT16B1_CTCR_ENCC_MASK                    (0x10U)                                             /*!< CT16B1_CTCR: ENCC Mask                  */
#define CT16B1_CTCR_ENCC_SHIFT                   (4U)                                                /*!< CT16B1_CTCR: ENCC Position              */
#define CT16B1_CTCR_ENCC(x)                      (((uint32_t)(((uint32_t)(x))<<CT16B1_CTCR_ENCC_SHIFT))&CT16B1_CTCR_ENCC_MASK) /*!< CT16B1_CTCR                             */
#define CT16B1_CTCR_SELCC_MASK                   (0xE0U)                                             /*!< CT16B1_CTCR: SELCC Mask                 */
#define CT16B1_CTCR_SELCC_SHIFT                  (5U)                                                /*!< CT16B1_CTCR: SELCC Position             */
#define CT16B1_CTCR_SELCC(x)                     (((uint32_t)(((uint32_t)(x))<<CT16B1_CTCR_SELCC_SHIFT))&CT16B1_CTCR_SELCC_MASK) /*!< CT16B1_CTCR                             */
/* ------- PWMC Bit Fields                          ------ */
#define CT16B1_PWMC_PWMEN0_MASK                  (0x1U)                                              /*!< CT16B1_PWMC: PWMEN0 Mask                */
#define CT16B1_PWMC_PWMEN0_SHIFT                 (0U)                                                /*!< CT16B1_PWMC: PWMEN0 Position            */
#define CT16B1_PWMC_PWMEN0(x)                    (((uint32_t)(((uint32_t)(x))<<CT16B1_PWMC_PWMEN0_SHIFT))&CT16B1_PWMC_PWMEN0_MASK) /*!< CT16B1_PWMC                             */
#define CT16B1_PWMC_PWMEN1_MASK                  (0x2U)                                              /*!< CT16B1_PWMC: PWMEN1 Mask                */
#define CT16B1_PWMC_PWMEN1_SHIFT                 (1U)                                                /*!< CT16B1_PWMC: PWMEN1 Position            */
#define CT16B1_PWMC_PWMEN1(x)                    (((uint32_t)(((uint32_t)(x))<<CT16B1_PWMC_PWMEN1_SHIFT))&CT16B1_PWMC_PWMEN1_MASK) /*!< CT16B1_PWMC                             */
#define CT16B1_PWMC_PWMEN2_MASK                  (0x4U)                                              /*!< CT16B1_PWMC: PWMEN2 Mask                */
#define CT16B1_PWMC_PWMEN2_SHIFT                 (2U)                                                /*!< CT16B1_PWMC: PWMEN2 Position            */
#define CT16B1_PWMC_PWMEN2(x)                    (((uint32_t)(((uint32_t)(x))<<CT16B1_PWMC_PWMEN2_SHIFT))&CT16B1_PWMC_PWMEN2_MASK) /*!< CT16B1_PWMC                             */
#define CT16B1_PWMC_PWMEN3_MASK                  (0x8U)                                              /*!< CT16B1_PWMC: PWMEN3 Mask                */
#define CT16B1_PWMC_PWMEN3_SHIFT                 (3U)                                                /*!< CT16B1_PWMC: PWMEN3 Position            */
#define CT16B1_PWMC_PWMEN3(x)                    (((uint32_t)(((uint32_t)(x))<<CT16B1_PWMC_PWMEN3_SHIFT))&CT16B1_PWMC_PWMEN3_MASK) /*!< CT16B1_PWMC                             */
/**
 * @} */ /* End group CT16B_Register_Masks_GROUP 
 */

/* CT16B1 - Peripheral instance base addresses */
#define CT16B1_BasePtr                 0x40010000UL //!< Peripheral base address
#define CT16B1                         ((CT16B1_Type *) CT16B1_BasePtr) //!< Freescale base pointer
#define CT16B1_BASE_PTR                (CT16B1) //!< Freescale style base pointer
/**
 * @} */ /* End group CT16B_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT32B0_Peripheral_access_layer_GROUP CT32B0 Peripheral Access Layer
* @brief C Struct for CT32B0
* @{
*/

/* ================================================================================ */
/* ================           CT32B0 (file:CT32B0_LPC11Uxx)        ================ */
/* ================================================================================ */

/**
 * @brief 32-bit counter/timers CT32B0
 */
/**
* @addtogroup CT32B0_structs_GROUP CT32B0 struct
* @brief Struct for CT32B0
* @{
*/
typedef struct {                                /*       CT32B0 Structure                                             */
   __IO uint32_t  IR;                           /**< 0000: Interrupt Register. The IR can be written to clear interrupts. The IR can be read to identify which of eight possible interrupt sources are pending */
   __IO uint32_t  TCR;                          /**< 0004: Timer Control Register. The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  TC;                           /**< 0008: Timer Counter. The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  PR;                           /**< 000C: Prescale Register. When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  PC;                           /**< 0010: Prescale Counter. The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  MCR;                          /**< 0014: Match Control Register. The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  MR[4];                        /**< 0018: Match Register . MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */
   __IO uint32_t  CCR;                          /**< 0028: Capture Control Register. The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  CR0;                          /**< 002C: Capture Register 0. CR0 is loaded with the value of TC when there is an event on the CT32B0_CAP0 input */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  CR1;                          /**< 0034: Capture Register 1. CR1 is loaded with the value of TC when there is an event on the CT32B0_CAP1 input */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  EMR;                          /**< 003C: External Match Register. The EMR controls the match function and the external match pins CT32Bn_MAT[3:0] */
        uint8_t   RESERVED_2[48];              
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register. The PWMCON enables PWM mode for the external match pins CT32Bn_MAT[3:0] */
} CT32B0_Type;

/**
 * @} */ /* End group CT32B0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CT32B0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CT32B0_Register_Masks_GROUP CT32B0 Register Masks
* @brief Register Masks for CT32B0
* @{
*/
/* ------- IR Bit Fields                            ------ */
#define CT32B0_IR_MR0INT_MASK                    (0x1U)                                              /*!< CT32B0_IR: MR0INT Mask                  */
#define CT32B0_IR_MR0INT_SHIFT                   (0U)                                                /*!< CT32B0_IR: MR0INT Position              */
#define CT32B0_IR_MR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_IR_MR0INT_SHIFT))&CT32B0_IR_MR0INT_MASK) /*!< CT32B0_IR                               */
#define CT32B0_IR_MR1INT_MASK                    (0x2U)                                              /*!< CT32B0_IR: MR1INT Mask                  */
#define CT32B0_IR_MR1INT_SHIFT                   (1U)                                                /*!< CT32B0_IR: MR1INT Position              */
#define CT32B0_IR_MR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_IR_MR1INT_SHIFT))&CT32B0_IR_MR1INT_MASK) /*!< CT32B0_IR                               */
#define CT32B0_IR_MR2INT_MASK                    (0x4U)                                              /*!< CT32B0_IR: MR2INT Mask                  */
#define CT32B0_IR_MR2INT_SHIFT                   (2U)                                                /*!< CT32B0_IR: MR2INT Position              */
#define CT32B0_IR_MR2INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_IR_MR2INT_SHIFT))&CT32B0_IR_MR2INT_MASK) /*!< CT32B0_IR                               */
#define CT32B0_IR_MR3INT_MASK                    (0x8U)                                              /*!< CT32B0_IR: MR3INT Mask                  */
#define CT32B0_IR_MR3INT_SHIFT                   (3U)                                                /*!< CT32B0_IR: MR3INT Position              */
#define CT32B0_IR_MR3INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_IR_MR3INT_SHIFT))&CT32B0_IR_MR3INT_MASK) /*!< CT32B0_IR                               */
#define CT32B0_IR_CR0INT_MASK                    (0x10U)                                             /*!< CT32B0_IR: CR0INT Mask                  */
#define CT32B0_IR_CR0INT_SHIFT                   (4U)                                                /*!< CT32B0_IR: CR0INT Position              */
#define CT32B0_IR_CR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_IR_CR0INT_SHIFT))&CT32B0_IR_CR0INT_MASK) /*!< CT32B0_IR                               */
#define CT32B0_IR_CR1INT_MASK                    (0x40U)                                             /*!< CT32B0_IR: CR1INT Mask                  */
#define CT32B0_IR_CR1INT_SHIFT                   (6U)                                                /*!< CT32B0_IR: CR1INT Position              */
#define CT32B0_IR_CR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_IR_CR1INT_SHIFT))&CT32B0_IR_CR1INT_MASK) /*!< CT32B0_IR                               */
/* ------- TCR Bit Fields                           ------ */
#define CT32B0_TCR_CEN_MASK                      (0x1U)                                              /*!< CT32B0_TCR: CEN Mask                    */
#define CT32B0_TCR_CEN_SHIFT                     (0U)                                                /*!< CT32B0_TCR: CEN Position                */
#define CT32B0_TCR_CEN(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B0_TCR_CEN_SHIFT))&CT32B0_TCR_CEN_MASK) /*!< CT32B0_TCR                              */
#define CT32B0_TCR_CRST_MASK                     (0x2U)                                              /*!< CT32B0_TCR: CRST Mask                   */
#define CT32B0_TCR_CRST_SHIFT                    (1U)                                                /*!< CT32B0_TCR: CRST Position               */
#define CT32B0_TCR_CRST(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_TCR_CRST_SHIFT))&CT32B0_TCR_CRST_MASK) /*!< CT32B0_TCR                              */
/* ------- TC Bit Fields                            ------ */
#define CT32B0_TC_TC_MASK                        (0xFFFFFFFFU)                                       /*!< CT32B0_TC: TC Mask                      */
#define CT32B0_TC_TC_SHIFT                       (0U)                                                /*!< CT32B0_TC: TC Position                  */
#define CT32B0_TC_TC(x)                          (((uint32_t)(((uint32_t)(x))<<CT32B0_TC_TC_SHIFT))&CT32B0_TC_TC_MASK) /*!< CT32B0_TC                               */
/* ------- PR Bit Fields                            ------ */
#define CT32B0_PR_PCVAL_MASK                     (0xFFFFFFFFU)                                       /*!< CT32B0_PR: PCVAL Mask                   */
#define CT32B0_PR_PCVAL_SHIFT                    (0U)                                                /*!< CT32B0_PR: PCVAL Position               */
#define CT32B0_PR_PCVAL(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_PR_PCVAL_SHIFT))&CT32B0_PR_PCVAL_MASK) /*!< CT32B0_PR                               */
/* ------- PC Bit Fields                            ------ */
#define CT32B0_PC_PC_MASK                        (0xFFFFFFFFU)                                       /*!< CT32B0_PC: PC Mask                      */
#define CT32B0_PC_PC_SHIFT                       (0U)                                                /*!< CT32B0_PC: PC Position                  */
#define CT32B0_PC_PC(x)                          (((uint32_t)(((uint32_t)(x))<<CT32B0_PC_PC_SHIFT))&CT32B0_PC_PC_MASK) /*!< CT32B0_PC                               */
/* ------- MCR Bit Fields                           ------ */
#define CT32B0_MCR_MR0I_MASK                     (0x1U)                                              /*!< CT32B0_MCR: MR0I Mask                   */
#define CT32B0_MCR_MR0I_SHIFT                    (0U)                                                /*!< CT32B0_MCR: MR0I Position               */
#define CT32B0_MCR_MR0I(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR0I_SHIFT))&CT32B0_MCR_MR0I_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR0R_MASK                     (0x2U)                                              /*!< CT32B0_MCR: MR0R Mask                   */
#define CT32B0_MCR_MR0R_SHIFT                    (1U)                                                /*!< CT32B0_MCR: MR0R Position               */
#define CT32B0_MCR_MR0R(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR0R_SHIFT))&CT32B0_MCR_MR0R_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR0S_MASK                     (0x4U)                                              /*!< CT32B0_MCR: MR0S Mask                   */
#define CT32B0_MCR_MR0S_SHIFT                    (2U)                                                /*!< CT32B0_MCR: MR0S Position               */
#define CT32B0_MCR_MR0S(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR0S_SHIFT))&CT32B0_MCR_MR0S_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR1I_MASK                     (0x8U)                                              /*!< CT32B0_MCR: MR1I Mask                   */
#define CT32B0_MCR_MR1I_SHIFT                    (3U)                                                /*!< CT32B0_MCR: MR1I Position               */
#define CT32B0_MCR_MR1I(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR1I_SHIFT))&CT32B0_MCR_MR1I_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR1R_MASK                     (0x10U)                                             /*!< CT32B0_MCR: MR1R Mask                   */
#define CT32B0_MCR_MR1R_SHIFT                    (4U)                                                /*!< CT32B0_MCR: MR1R Position               */
#define CT32B0_MCR_MR1R(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR1R_SHIFT))&CT32B0_MCR_MR1R_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR1S_MASK                     (0x20U)                                             /*!< CT32B0_MCR: MR1S Mask                   */
#define CT32B0_MCR_MR1S_SHIFT                    (5U)                                                /*!< CT32B0_MCR: MR1S Position               */
#define CT32B0_MCR_MR1S(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR1S_SHIFT))&CT32B0_MCR_MR1S_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR2I_MASK                     (0x40U)                                             /*!< CT32B0_MCR: MR2I Mask                   */
#define CT32B0_MCR_MR2I_SHIFT                    (6U)                                                /*!< CT32B0_MCR: MR2I Position               */
#define CT32B0_MCR_MR2I(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR2I_SHIFT))&CT32B0_MCR_MR2I_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR2R_MASK                     (0x80U)                                             /*!< CT32B0_MCR: MR2R Mask                   */
#define CT32B0_MCR_MR2R_SHIFT                    (7U)                                                /*!< CT32B0_MCR: MR2R Position               */
#define CT32B0_MCR_MR2R(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR2R_SHIFT))&CT32B0_MCR_MR2R_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR2S_MASK                     (0x100U)                                            /*!< CT32B0_MCR: MR2S Mask                   */
#define CT32B0_MCR_MR2S_SHIFT                    (8U)                                                /*!< CT32B0_MCR: MR2S Position               */
#define CT32B0_MCR_MR2S(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR2S_SHIFT))&CT32B0_MCR_MR2S_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR3I_MASK                     (0x200U)                                            /*!< CT32B0_MCR: MR3I Mask                   */
#define CT32B0_MCR_MR3I_SHIFT                    (9U)                                                /*!< CT32B0_MCR: MR3I Position               */
#define CT32B0_MCR_MR3I(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR3I_SHIFT))&CT32B0_MCR_MR3I_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR3R_MASK                     (0x400U)                                            /*!< CT32B0_MCR: MR3R Mask                   */
#define CT32B0_MCR_MR3R_SHIFT                    (10U)                                               /*!< CT32B0_MCR: MR3R Position               */
#define CT32B0_MCR_MR3R(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR3R_SHIFT))&CT32B0_MCR_MR3R_MASK) /*!< CT32B0_MCR                              */
#define CT32B0_MCR_MR3S_MASK                     (0x800U)                                            /*!< CT32B0_MCR: MR3S Mask                   */
#define CT32B0_MCR_MR3S_SHIFT                    (11U)                                               /*!< CT32B0_MCR: MR3S Position               */
#define CT32B0_MCR_MR3S(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MCR_MR3S_SHIFT))&CT32B0_MCR_MR3S_MASK) /*!< CT32B0_MCR                              */
/* ------- MR Bit Fields                            ------ */
#define CT32B0_MR_MATCH_MASK                     (0xFFFFFFFFU)                                       /*!< CT32B0_MR: MATCH Mask                   */
#define CT32B0_MR_MATCH_SHIFT                    (0U)                                                /*!< CT32B0_MR: MATCH Position               */
#define CT32B0_MR_MATCH(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_MR_MATCH_SHIFT))&CT32B0_MR_MATCH_MASK) /*!< CT32B0_MR                               */
/* ------- CCR Bit Fields                           ------ */
#define CT32B0_CCR_CAP0RE_MASK                   (0x1U)                                              /*!< CT32B0_CCR: CAP0RE Mask                 */
#define CT32B0_CCR_CAP0RE_SHIFT                  (0U)                                                /*!< CT32B0_CCR: CAP0RE Position             */
#define CT32B0_CCR_CAP0RE(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B0_CCR_CAP0RE_SHIFT))&CT32B0_CCR_CAP0RE_MASK) /*!< CT32B0_CCR                              */
#define CT32B0_CCR_CAP0FE_MASK                   (0x2U)                                              /*!< CT32B0_CCR: CAP0FE Mask                 */
#define CT32B0_CCR_CAP0FE_SHIFT                  (1U)                                                /*!< CT32B0_CCR: CAP0FE Position             */
#define CT32B0_CCR_CAP0FE(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B0_CCR_CAP0FE_SHIFT))&CT32B0_CCR_CAP0FE_MASK) /*!< CT32B0_CCR                              */
#define CT32B0_CCR_CAP0I_MASK                    (0x4U)                                              /*!< CT32B0_CCR: CAP0I Mask                  */
#define CT32B0_CCR_CAP0I_SHIFT                   (2U)                                                /*!< CT32B0_CCR: CAP0I Position              */
#define CT32B0_CCR_CAP0I(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_CCR_CAP0I_SHIFT))&CT32B0_CCR_CAP0I_MASK) /*!< CT32B0_CCR                              */
#define CT32B0_CCR_CAP1RE_MASK                   (0x40U)                                             /*!< CT32B0_CCR: CAP1RE Mask                 */
#define CT32B0_CCR_CAP1RE_SHIFT                  (6U)                                                /*!< CT32B0_CCR: CAP1RE Position             */
#define CT32B0_CCR_CAP1RE(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B0_CCR_CAP1RE_SHIFT))&CT32B0_CCR_CAP1RE_MASK) /*!< CT32B0_CCR                              */
#define CT32B0_CCR_CAP1FE_MASK                   (0x80U)                                             /*!< CT32B0_CCR: CAP1FE Mask                 */
#define CT32B0_CCR_CAP1FE_SHIFT                  (7U)                                                /*!< CT32B0_CCR: CAP1FE Position             */
#define CT32B0_CCR_CAP1FE(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B0_CCR_CAP1FE_SHIFT))&CT32B0_CCR_CAP1FE_MASK) /*!< CT32B0_CCR                              */
#define CT32B0_CCR_CAP1I_MASK                    (0x100U)                                            /*!< CT32B0_CCR: CAP1I Mask                  */
#define CT32B0_CCR_CAP1I_SHIFT                   (8U)                                                /*!< CT32B0_CCR: CAP1I Position              */
#define CT32B0_CCR_CAP1I(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_CCR_CAP1I_SHIFT))&CT32B0_CCR_CAP1I_MASK) /*!< CT32B0_CCR                              */
/* ------- CR0 Bit Fields                           ------ */
#define CT32B0_CR0_CAP_MASK                      (0xFFFFFFFFU)                                       /*!< CT32B0_CR0: CAP Mask                    */
#define CT32B0_CR0_CAP_SHIFT                     (0U)                                                /*!< CT32B0_CR0: CAP Position                */
#define CT32B0_CR0_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B0_CR0_CAP_SHIFT))&CT32B0_CR0_CAP_MASK) /*!< CT32B0_CR0                              */
/* ------- CR1 Bit Fields                           ------ */
#define CT32B0_CR1_CAP_MASK                      (0xFFFFFFFFU)                                       /*!< CT32B0_CR1: CAP Mask                    */
#define CT32B0_CR1_CAP_SHIFT                     (0U)                                                /*!< CT32B0_CR1: CAP Position                */
#define CT32B0_CR1_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B0_CR1_CAP_SHIFT))&CT32B0_CR1_CAP_MASK) /*!< CT32B0_CR1                              */
/* ------- EMR Bit Fields                           ------ */
#define CT32B0_EMR_EM0_MASK                      (0x1U)                                              /*!< CT32B0_EMR: EM0 Mask                    */
#define CT32B0_EMR_EM0_SHIFT                     (0U)                                                /*!< CT32B0_EMR: EM0 Position                */
#define CT32B0_EMR_EM0(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B0_EMR_EM0_SHIFT))&CT32B0_EMR_EM0_MASK) /*!< CT32B0_EMR                              */
#define CT32B0_EMR_EM1_MASK                      (0x2U)                                              /*!< CT32B0_EMR: EM1 Mask                    */
#define CT32B0_EMR_EM1_SHIFT                     (1U)                                                /*!< CT32B0_EMR: EM1 Position                */
#define CT32B0_EMR_EM1(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B0_EMR_EM1_SHIFT))&CT32B0_EMR_EM1_MASK) /*!< CT32B0_EMR                              */
#define CT32B0_EMR_EM2_MASK                      (0x4U)                                              /*!< CT32B0_EMR: EM2 Mask                    */
#define CT32B0_EMR_EM2_SHIFT                     (2U)                                                /*!< CT32B0_EMR: EM2 Position                */
#define CT32B0_EMR_EM2(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B0_EMR_EM2_SHIFT))&CT32B0_EMR_EM2_MASK) /*!< CT32B0_EMR                              */
#define CT32B0_EMR_EM3_MASK                      (0x8U)                                              /*!< CT32B0_EMR: EM3 Mask                    */
#define CT32B0_EMR_EM3_SHIFT                     (3U)                                                /*!< CT32B0_EMR: EM3 Position                */
#define CT32B0_EMR_EM3(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B0_EMR_EM3_SHIFT))&CT32B0_EMR_EM3_MASK) /*!< CT32B0_EMR                              */
#define CT32B0_EMR_EMC0_MASK                     (0x30U)                                             /*!< CT32B0_EMR: EMC0 Mask                   */
#define CT32B0_EMR_EMC0_SHIFT                    (4U)                                                /*!< CT32B0_EMR: EMC0 Position               */
#define CT32B0_EMR_EMC0(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_EMR_EMC0_SHIFT))&CT32B0_EMR_EMC0_MASK) /*!< CT32B0_EMR                              */
#define CT32B0_EMR_EMC1_MASK                     (0xC0U)                                             /*!< CT32B0_EMR: EMC1 Mask                   */
#define CT32B0_EMR_EMC1_SHIFT                    (6U)                                                /*!< CT32B0_EMR: EMC1 Position               */
#define CT32B0_EMR_EMC1(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_EMR_EMC1_SHIFT))&CT32B0_EMR_EMC1_MASK) /*!< CT32B0_EMR                              */
#define CT32B0_EMR_EMC2_MASK                     (0x300U)                                            /*!< CT32B0_EMR: EMC2 Mask                   */
#define CT32B0_EMR_EMC2_SHIFT                    (8U)                                                /*!< CT32B0_EMR: EMC2 Position               */
#define CT32B0_EMR_EMC2(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_EMR_EMC2_SHIFT))&CT32B0_EMR_EMC2_MASK) /*!< CT32B0_EMR                              */
#define CT32B0_EMR_EMC3_MASK                     (0xC00U)                                            /*!< CT32B0_EMR: EMC3 Mask                   */
#define CT32B0_EMR_EMC3_SHIFT                    (10U)                                               /*!< CT32B0_EMR: EMC3 Position               */
#define CT32B0_EMR_EMC3(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_EMR_EMC3_SHIFT))&CT32B0_EMR_EMC3_MASK) /*!< CT32B0_EMR                              */
/* ------- CTCR Bit Fields                          ------ */
#define CT32B0_CTCR_CTM_MASK                     (0x3U)                                              /*!< CT32B0_CTCR: CTM Mask                   */
#define CT32B0_CTCR_CTM_SHIFT                    (0U)                                                /*!< CT32B0_CTCR: CTM Position               */
#define CT32B0_CTCR_CTM(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_CTCR_CTM_SHIFT))&CT32B0_CTCR_CTM_MASK) /*!< CT32B0_CTCR                             */
#define CT32B0_CTCR_CIS_MASK                     (0xCU)                                              /*!< CT32B0_CTCR: CIS Mask                   */
#define CT32B0_CTCR_CIS_SHIFT                    (2U)                                                /*!< CT32B0_CTCR: CIS Position               */
#define CT32B0_CTCR_CIS(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B0_CTCR_CIS_SHIFT))&CT32B0_CTCR_CIS_MASK) /*!< CT32B0_CTCR                             */
#define CT32B0_CTCR_ENCC_MASK                    (0x10U)                                             /*!< CT32B0_CTCR: ENCC Mask                  */
#define CT32B0_CTCR_ENCC_SHIFT                   (4U)                                                /*!< CT32B0_CTCR: ENCC Position              */
#define CT32B0_CTCR_ENCC(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B0_CTCR_ENCC_SHIFT))&CT32B0_CTCR_ENCC_MASK) /*!< CT32B0_CTCR                             */
#define CT32B0_CTCR_SElCC_MASK                   (0xE0U)                                             /*!< CT32B0_CTCR: SElCC Mask                 */
#define CT32B0_CTCR_SElCC_SHIFT                  (5U)                                                /*!< CT32B0_CTCR: SElCC Position             */
#define CT32B0_CTCR_SElCC(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B0_CTCR_SElCC_SHIFT))&CT32B0_CTCR_SElCC_MASK) /*!< CT32B0_CTCR                             */
/* ------- PWMC Bit Fields                          ------ */
#define CT32B0_PWMC_PWMEN0_MASK                  (0x1U)                                              /*!< CT32B0_PWMC: PWMEN0 Mask                */
#define CT32B0_PWMC_PWMEN0_SHIFT                 (0U)                                                /*!< CT32B0_PWMC: PWMEN0 Position            */
#define CT32B0_PWMC_PWMEN0(x)                    (((uint32_t)(((uint32_t)(x))<<CT32B0_PWMC_PWMEN0_SHIFT))&CT32B0_PWMC_PWMEN0_MASK) /*!< CT32B0_PWMC                             */
#define CT32B0_PWMC_PWMEN1_MASK                  (0x2U)                                              /*!< CT32B0_PWMC: PWMEN1 Mask                */
#define CT32B0_PWMC_PWMEN1_SHIFT                 (1U)                                                /*!< CT32B0_PWMC: PWMEN1 Position            */
#define CT32B0_PWMC_PWMEN1(x)                    (((uint32_t)(((uint32_t)(x))<<CT32B0_PWMC_PWMEN1_SHIFT))&CT32B0_PWMC_PWMEN1_MASK) /*!< CT32B0_PWMC                             */
#define CT32B0_PWMC_PWMEN2_MASK                  (0x4U)                                              /*!< CT32B0_PWMC: PWMEN2 Mask                */
#define CT32B0_PWMC_PWMEN2_SHIFT                 (2U)                                                /*!< CT32B0_PWMC: PWMEN2 Position            */
#define CT32B0_PWMC_PWMEN2(x)                    (((uint32_t)(((uint32_t)(x))<<CT32B0_PWMC_PWMEN2_SHIFT))&CT32B0_PWMC_PWMEN2_MASK) /*!< CT32B0_PWMC                             */
#define CT32B0_PWMC_PWMEN3_MASK                  (0x8U)                                              /*!< CT32B0_PWMC: PWMEN3 Mask                */
#define CT32B0_PWMC_PWMEN3_SHIFT                 (3U)                                                /*!< CT32B0_PWMC: PWMEN3 Position            */
#define CT32B0_PWMC_PWMEN3(x)                    (((uint32_t)(((uint32_t)(x))<<CT32B0_PWMC_PWMEN3_SHIFT))&CT32B0_PWMC_PWMEN3_MASK) /*!< CT32B0_PWMC                             */
/**
 * @} */ /* End group CT32B0_Register_Masks_GROUP 
 */

/* CT32B0 - Peripheral instance base addresses */
#define CT32B0_BasePtr                 0x40014000UL //!< Peripheral base address
#define CT32B0                         ((CT32B0_Type *) CT32B0_BasePtr) //!< Freescale base pointer
#define CT32B0_BASE_PTR                (CT32B0) //!< Freescale style base pointer
/**
 * @} */ /* End group CT32B0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT32B_Peripheral_access_layer_GROUP CT32B Peripheral Access Layer
* @brief C Struct for CT32B
* @{
*/

/* ================================================================================ */
/* ================           CT32B1 (file:CT32B1_LPC11Uxx)        ================ */
/* ================================================================================ */

/**
 * @brief 32-bit counter/timers CT32B1
 */
/**
* @addtogroup CT32B_structs_GROUP CT32B struct
* @brief Struct for CT32B
* @{
*/
typedef struct {                                /*       CT32B1 Structure                                             */
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
        uint8_t   RESERVED_0[8];               
   __IO uint32_t  EMR;                          /**< 003C: External Match Register. The EMR controls the match function and the external match pins CT32Bn_MAT[3:0] */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register. The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register. The PWMCON enables PWM mode for the external match pins CT32Bn_MAT[3:0] */
} CT32B1_Type;

/**
 * @} */ /* End group CT32B_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CT32B1' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CT32B_Register_Masks_GROUP CT32B Register Masks
* @brief Register Masks for CT32B
* @{
*/
/* ------- IR Bit Fields                            ------ */
#define CT32B1_IR_MR0INT_MASK                    (0x1U)                                              /*!< CT32B1_IR: MR0INT Mask                  */
#define CT32B1_IR_MR0INT_SHIFT                   (0U)                                                /*!< CT32B1_IR: MR0INT Position              */
#define CT32B1_IR_MR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_IR_MR0INT_SHIFT))&CT32B1_IR_MR0INT_MASK) /*!< CT32B1_IR                               */
#define CT32B1_IR_MR1INT_MASK                    (0x2U)                                              /*!< CT32B1_IR: MR1INT Mask                  */
#define CT32B1_IR_MR1INT_SHIFT                   (1U)                                                /*!< CT32B1_IR: MR1INT Position              */
#define CT32B1_IR_MR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_IR_MR1INT_SHIFT))&CT32B1_IR_MR1INT_MASK) /*!< CT32B1_IR                               */
#define CT32B1_IR_MR2INT_MASK                    (0x4U)                                              /*!< CT32B1_IR: MR2INT Mask                  */
#define CT32B1_IR_MR2INT_SHIFT                   (2U)                                                /*!< CT32B1_IR: MR2INT Position              */
#define CT32B1_IR_MR2INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_IR_MR2INT_SHIFT))&CT32B1_IR_MR2INT_MASK) /*!< CT32B1_IR                               */
#define CT32B1_IR_MR3INT_MASK                    (0x8U)                                              /*!< CT32B1_IR: MR3INT Mask                  */
#define CT32B1_IR_MR3INT_SHIFT                   (3U)                                                /*!< CT32B1_IR: MR3INT Position              */
#define CT32B1_IR_MR3INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_IR_MR3INT_SHIFT))&CT32B1_IR_MR3INT_MASK) /*!< CT32B1_IR                               */
#define CT32B1_IR_CR0INT_MASK                    (0x10U)                                             /*!< CT32B1_IR: CR0INT Mask                  */
#define CT32B1_IR_CR0INT_SHIFT                   (4U)                                                /*!< CT32B1_IR: CR0INT Position              */
#define CT32B1_IR_CR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_IR_CR0INT_SHIFT))&CT32B1_IR_CR0INT_MASK) /*!< CT32B1_IR                               */
#define CT32B1_IR_CR1INT_MASK                    (0x20U)                                             /*!< CT32B1_IR: CR1INT Mask                  */
#define CT32B1_IR_CR1INT_SHIFT                   (5U)                                                /*!< CT32B1_IR: CR1INT Position              */
#define CT32B1_IR_CR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_IR_CR1INT_SHIFT))&CT32B1_IR_CR1INT_MASK) /*!< CT32B1_IR                               */
/* ------- TCR Bit Fields                           ------ */
#define CT32B1_TCR_CEN_MASK                      (0x1U)                                              /*!< CT32B1_TCR: CEN Mask                    */
#define CT32B1_TCR_CEN_SHIFT                     (0U)                                                /*!< CT32B1_TCR: CEN Position                */
#define CT32B1_TCR_CEN(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B1_TCR_CEN_SHIFT))&CT32B1_TCR_CEN_MASK) /*!< CT32B1_TCR                              */
#define CT32B1_TCR_CRST_MASK                     (0x2U)                                              /*!< CT32B1_TCR: CRST Mask                   */
#define CT32B1_TCR_CRST_SHIFT                    (1U)                                                /*!< CT32B1_TCR: CRST Position               */
#define CT32B1_TCR_CRST(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_TCR_CRST_SHIFT))&CT32B1_TCR_CRST_MASK) /*!< CT32B1_TCR                              */
/* ------- TC Bit Fields                            ------ */
#define CT32B1_TC_TC_MASK                        (0xFFFFFFFFU)                                       /*!< CT32B1_TC: TC Mask                      */
#define CT32B1_TC_TC_SHIFT                       (0U)                                                /*!< CT32B1_TC: TC Position                  */
#define CT32B1_TC_TC(x)                          (((uint32_t)(((uint32_t)(x))<<CT32B1_TC_TC_SHIFT))&CT32B1_TC_TC_MASK) /*!< CT32B1_TC                               */
/* ------- PR Bit Fields                            ------ */
#define CT32B1_PR_PCVAL_MASK                     (0xFFFFFFFFU)                                       /*!< CT32B1_PR: PCVAL Mask                   */
#define CT32B1_PR_PCVAL_SHIFT                    (0U)                                                /*!< CT32B1_PR: PCVAL Position               */
#define CT32B1_PR_PCVAL(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_PR_PCVAL_SHIFT))&CT32B1_PR_PCVAL_MASK) /*!< CT32B1_PR                               */
/* ------- PC Bit Fields                            ------ */
#define CT32B1_PC_PC_MASK                        (0xFFFFFFFFU)                                       /*!< CT32B1_PC: PC Mask                      */
#define CT32B1_PC_PC_SHIFT                       (0U)                                                /*!< CT32B1_PC: PC Position                  */
#define CT32B1_PC_PC(x)                          (((uint32_t)(((uint32_t)(x))<<CT32B1_PC_PC_SHIFT))&CT32B1_PC_PC_MASK) /*!< CT32B1_PC                               */
/* ------- MCR Bit Fields                           ------ */
#define CT32B1_MCR_MR0I_MASK                     (0x1U)                                              /*!< CT32B1_MCR: MR0I Mask                   */
#define CT32B1_MCR_MR0I_SHIFT                    (0U)                                                /*!< CT32B1_MCR: MR0I Position               */
#define CT32B1_MCR_MR0I(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR0I_SHIFT))&CT32B1_MCR_MR0I_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR0R_MASK                     (0x2U)                                              /*!< CT32B1_MCR: MR0R Mask                   */
#define CT32B1_MCR_MR0R_SHIFT                    (1U)                                                /*!< CT32B1_MCR: MR0R Position               */
#define CT32B1_MCR_MR0R(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR0R_SHIFT))&CT32B1_MCR_MR0R_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR0S_MASK                     (0x4U)                                              /*!< CT32B1_MCR: MR0S Mask                   */
#define CT32B1_MCR_MR0S_SHIFT                    (2U)                                                /*!< CT32B1_MCR: MR0S Position               */
#define CT32B1_MCR_MR0S(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR0S_SHIFT))&CT32B1_MCR_MR0S_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR1I_MASK                     (0x8U)                                              /*!< CT32B1_MCR: MR1I Mask                   */
#define CT32B1_MCR_MR1I_SHIFT                    (3U)                                                /*!< CT32B1_MCR: MR1I Position               */
#define CT32B1_MCR_MR1I(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR1I_SHIFT))&CT32B1_MCR_MR1I_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR1R_MASK                     (0x10U)                                             /*!< CT32B1_MCR: MR1R Mask                   */
#define CT32B1_MCR_MR1R_SHIFT                    (4U)                                                /*!< CT32B1_MCR: MR1R Position               */
#define CT32B1_MCR_MR1R(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR1R_SHIFT))&CT32B1_MCR_MR1R_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR1S_MASK                     (0x20U)                                             /*!< CT32B1_MCR: MR1S Mask                   */
#define CT32B1_MCR_MR1S_SHIFT                    (5U)                                                /*!< CT32B1_MCR: MR1S Position               */
#define CT32B1_MCR_MR1S(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR1S_SHIFT))&CT32B1_MCR_MR1S_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR2I_MASK                     (0x40U)                                             /*!< CT32B1_MCR: MR2I Mask                   */
#define CT32B1_MCR_MR2I_SHIFT                    (6U)                                                /*!< CT32B1_MCR: MR2I Position               */
#define CT32B1_MCR_MR2I(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR2I_SHIFT))&CT32B1_MCR_MR2I_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR2R_MASK                     (0x80U)                                             /*!< CT32B1_MCR: MR2R Mask                   */
#define CT32B1_MCR_MR2R_SHIFT                    (7U)                                                /*!< CT32B1_MCR: MR2R Position               */
#define CT32B1_MCR_MR2R(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR2R_SHIFT))&CT32B1_MCR_MR2R_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR2S_MASK                     (0x100U)                                            /*!< CT32B1_MCR: MR2S Mask                   */
#define CT32B1_MCR_MR2S_SHIFT                    (8U)                                                /*!< CT32B1_MCR: MR2S Position               */
#define CT32B1_MCR_MR2S(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR2S_SHIFT))&CT32B1_MCR_MR2S_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR3I_MASK                     (0x200U)                                            /*!< CT32B1_MCR: MR3I Mask                   */
#define CT32B1_MCR_MR3I_SHIFT                    (9U)                                                /*!< CT32B1_MCR: MR3I Position               */
#define CT32B1_MCR_MR3I(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR3I_SHIFT))&CT32B1_MCR_MR3I_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR3R_MASK                     (0x400U)                                            /*!< CT32B1_MCR: MR3R Mask                   */
#define CT32B1_MCR_MR3R_SHIFT                    (10U)                                               /*!< CT32B1_MCR: MR3R Position               */
#define CT32B1_MCR_MR3R(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR3R_SHIFT))&CT32B1_MCR_MR3R_MASK) /*!< CT32B1_MCR                              */
#define CT32B1_MCR_MR3S_MASK                     (0x800U)                                            /*!< CT32B1_MCR: MR3S Mask                   */
#define CT32B1_MCR_MR3S_SHIFT                    (11U)                                               /*!< CT32B1_MCR: MR3S Position               */
#define CT32B1_MCR_MR3S(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MCR_MR3S_SHIFT))&CT32B1_MCR_MR3S_MASK) /*!< CT32B1_MCR                              */
/* ------- MR Bit Fields                            ------ */
#define CT32B1_MR_MATCH_MASK                     (0xFFFFFFFFU)                                       /*!< CT32B1_MR: MATCH Mask                   */
#define CT32B1_MR_MATCH_SHIFT                    (0U)                                                /*!< CT32B1_MR: MATCH Position               */
#define CT32B1_MR_MATCH(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_MR_MATCH_SHIFT))&CT32B1_MR_MATCH_MASK) /*!< CT32B1_MR                               */
/* ------- CCR Bit Fields                           ------ */
#define CT32B1_CCR_CAP0RE_MASK                   (0x1U)                                              /*!< CT32B1_CCR: CAP0RE Mask                 */
#define CT32B1_CCR_CAP0RE_SHIFT                  (0U)                                                /*!< CT32B1_CCR: CAP0RE Position             */
#define CT32B1_CCR_CAP0RE(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B1_CCR_CAP0RE_SHIFT))&CT32B1_CCR_CAP0RE_MASK) /*!< CT32B1_CCR                              */
#define CT32B1_CCR_CAP0FE_MASK                   (0x2U)                                              /*!< CT32B1_CCR: CAP0FE Mask                 */
#define CT32B1_CCR_CAP0FE_SHIFT                  (1U)                                                /*!< CT32B1_CCR: CAP0FE Position             */
#define CT32B1_CCR_CAP0FE(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B1_CCR_CAP0FE_SHIFT))&CT32B1_CCR_CAP0FE_MASK) /*!< CT32B1_CCR                              */
#define CT32B1_CCR_CAP0I_MASK                    (0x4U)                                              /*!< CT32B1_CCR: CAP0I Mask                  */
#define CT32B1_CCR_CAP0I_SHIFT                   (2U)                                                /*!< CT32B1_CCR: CAP0I Position              */
#define CT32B1_CCR_CAP0I(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_CCR_CAP0I_SHIFT))&CT32B1_CCR_CAP0I_MASK) /*!< CT32B1_CCR                              */
#define CT32B1_CCR_CAP1RE_MASK                   (0x8U)                                              /*!< CT32B1_CCR: CAP1RE Mask                 */
#define CT32B1_CCR_CAP1RE_SHIFT                  (3U)                                                /*!< CT32B1_CCR: CAP1RE Position             */
#define CT32B1_CCR_CAP1RE(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B1_CCR_CAP1RE_SHIFT))&CT32B1_CCR_CAP1RE_MASK) /*!< CT32B1_CCR                              */
#define CT32B1_CCR_CAP1FE_MASK                   (0x10U)                                             /*!< CT32B1_CCR: CAP1FE Mask                 */
#define CT32B1_CCR_CAP1FE_SHIFT                  (4U)                                                /*!< CT32B1_CCR: CAP1FE Position             */
#define CT32B1_CCR_CAP1FE(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B1_CCR_CAP1FE_SHIFT))&CT32B1_CCR_CAP1FE_MASK) /*!< CT32B1_CCR                              */
#define CT32B1_CCR_CAP1I_MASK                    (0x20U)                                             /*!< CT32B1_CCR: CAP1I Mask                  */
#define CT32B1_CCR_CAP1I_SHIFT                   (5U)                                                /*!< CT32B1_CCR: CAP1I Position              */
#define CT32B1_CCR_CAP1I(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_CCR_CAP1I_SHIFT))&CT32B1_CCR_CAP1I_MASK) /*!< CT32B1_CCR                              */
/* ------- CR0 Bit Fields                           ------ */
#define CT32B1_CR0_CAP_MASK                      (0xFFFFFFFFU)                                       /*!< CT32B1_CR0: CAP Mask                    */
#define CT32B1_CR0_CAP_SHIFT                     (0U)                                                /*!< CT32B1_CR0: CAP Position                */
#define CT32B1_CR0_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B1_CR0_CAP_SHIFT))&CT32B1_CR0_CAP_MASK) /*!< CT32B1_CR0                              */
/* ------- CR1 Bit Fields                           ------ */
#define CT32B1_CR1_CAP_MASK                      (0xFFFFFFFFU)                                       /*!< CT32B1_CR1: CAP Mask                    */
#define CT32B1_CR1_CAP_SHIFT                     (0U)                                                /*!< CT32B1_CR1: CAP Position                */
#define CT32B1_CR1_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B1_CR1_CAP_SHIFT))&CT32B1_CR1_CAP_MASK) /*!< CT32B1_CR1                              */
/* ------- EMR Bit Fields                           ------ */
#define CT32B1_EMR_EM0_MASK                      (0x1U)                                              /*!< CT32B1_EMR: EM0 Mask                    */
#define CT32B1_EMR_EM0_SHIFT                     (0U)                                                /*!< CT32B1_EMR: EM0 Position                */
#define CT32B1_EMR_EM0(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B1_EMR_EM0_SHIFT))&CT32B1_EMR_EM0_MASK) /*!< CT32B1_EMR                              */
#define CT32B1_EMR_EM1_MASK                      (0x2U)                                              /*!< CT32B1_EMR: EM1 Mask                    */
#define CT32B1_EMR_EM1_SHIFT                     (1U)                                                /*!< CT32B1_EMR: EM1 Position                */
#define CT32B1_EMR_EM1(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B1_EMR_EM1_SHIFT))&CT32B1_EMR_EM1_MASK) /*!< CT32B1_EMR                              */
#define CT32B1_EMR_EM2_MASK                      (0x4U)                                              /*!< CT32B1_EMR: EM2 Mask                    */
#define CT32B1_EMR_EM2_SHIFT                     (2U)                                                /*!< CT32B1_EMR: EM2 Position                */
#define CT32B1_EMR_EM2(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B1_EMR_EM2_SHIFT))&CT32B1_EMR_EM2_MASK) /*!< CT32B1_EMR                              */
#define CT32B1_EMR_EM3_MASK                      (0x8U)                                              /*!< CT32B1_EMR: EM3 Mask                    */
#define CT32B1_EMR_EM3_SHIFT                     (3U)                                                /*!< CT32B1_EMR: EM3 Position                */
#define CT32B1_EMR_EM3(x)                        (((uint32_t)(((uint32_t)(x))<<CT32B1_EMR_EM3_SHIFT))&CT32B1_EMR_EM3_MASK) /*!< CT32B1_EMR                              */
#define CT32B1_EMR_EMC0_MASK                     (0x30U)                                             /*!< CT32B1_EMR: EMC0 Mask                   */
#define CT32B1_EMR_EMC0_SHIFT                    (4U)                                                /*!< CT32B1_EMR: EMC0 Position               */
#define CT32B1_EMR_EMC0(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_EMR_EMC0_SHIFT))&CT32B1_EMR_EMC0_MASK) /*!< CT32B1_EMR                              */
#define CT32B1_EMR_EMC1_MASK                     (0xC0U)                                             /*!< CT32B1_EMR: EMC1 Mask                   */
#define CT32B1_EMR_EMC1_SHIFT                    (6U)                                                /*!< CT32B1_EMR: EMC1 Position               */
#define CT32B1_EMR_EMC1(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_EMR_EMC1_SHIFT))&CT32B1_EMR_EMC1_MASK) /*!< CT32B1_EMR                              */
#define CT32B1_EMR_EMC2_MASK                     (0x300U)                                            /*!< CT32B1_EMR: EMC2 Mask                   */
#define CT32B1_EMR_EMC2_SHIFT                    (8U)                                                /*!< CT32B1_EMR: EMC2 Position               */
#define CT32B1_EMR_EMC2(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_EMR_EMC2_SHIFT))&CT32B1_EMR_EMC2_MASK) /*!< CT32B1_EMR                              */
#define CT32B1_EMR_EMC3_MASK                     (0xC00U)                                            /*!< CT32B1_EMR: EMC3 Mask                   */
#define CT32B1_EMR_EMC3_SHIFT                    (10U)                                               /*!< CT32B1_EMR: EMC3 Position               */
#define CT32B1_EMR_EMC3(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_EMR_EMC3_SHIFT))&CT32B1_EMR_EMC3_MASK) /*!< CT32B1_EMR                              */
/* ------- CTCR Bit Fields                          ------ */
#define CT32B1_CTCR_CTM_MASK                     (0x3U)                                              /*!< CT32B1_CTCR: CTM Mask                   */
#define CT32B1_CTCR_CTM_SHIFT                    (0U)                                                /*!< CT32B1_CTCR: CTM Position               */
#define CT32B1_CTCR_CTM(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_CTCR_CTM_SHIFT))&CT32B1_CTCR_CTM_MASK) /*!< CT32B1_CTCR                             */
#define CT32B1_CTCR_CIS_MASK                     (0xCU)                                              /*!< CT32B1_CTCR: CIS Mask                   */
#define CT32B1_CTCR_CIS_SHIFT                    (2U)                                                /*!< CT32B1_CTCR: CIS Position               */
#define CT32B1_CTCR_CIS(x)                       (((uint32_t)(((uint32_t)(x))<<CT32B1_CTCR_CIS_SHIFT))&CT32B1_CTCR_CIS_MASK) /*!< CT32B1_CTCR                             */
#define CT32B1_CTCR_ENCC_MASK                    (0x10U)                                             /*!< CT32B1_CTCR: ENCC Mask                  */
#define CT32B1_CTCR_ENCC_SHIFT                   (4U)                                                /*!< CT32B1_CTCR: ENCC Position              */
#define CT32B1_CTCR_ENCC(x)                      (((uint32_t)(((uint32_t)(x))<<CT32B1_CTCR_ENCC_SHIFT))&CT32B1_CTCR_ENCC_MASK) /*!< CT32B1_CTCR                             */
#define CT32B1_CTCR_SElCC_MASK                   (0xE0U)                                             /*!< CT32B1_CTCR: SElCC Mask                 */
#define CT32B1_CTCR_SElCC_SHIFT                  (5U)                                                /*!< CT32B1_CTCR: SElCC Position             */
#define CT32B1_CTCR_SElCC(x)                     (((uint32_t)(((uint32_t)(x))<<CT32B1_CTCR_SElCC_SHIFT))&CT32B1_CTCR_SElCC_MASK) /*!< CT32B1_CTCR                             */
/* ------- PWMC Bit Fields                          ------ */
#define CT32B1_PWMC_PWMEN0_MASK                  (0x1U)                                              /*!< CT32B1_PWMC: PWMEN0 Mask                */
#define CT32B1_PWMC_PWMEN0_SHIFT                 (0U)                                                /*!< CT32B1_PWMC: PWMEN0 Position            */
#define CT32B1_PWMC_PWMEN0(x)                    (((uint32_t)(((uint32_t)(x))<<CT32B1_PWMC_PWMEN0_SHIFT))&CT32B1_PWMC_PWMEN0_MASK) /*!< CT32B1_PWMC                             */
#define CT32B1_PWMC_PWMEN1_MASK                  (0x2U)                                              /*!< CT32B1_PWMC: PWMEN1 Mask                */
#define CT32B1_PWMC_PWMEN1_SHIFT                 (1U)                                                /*!< CT32B1_PWMC: PWMEN1 Position            */
#define CT32B1_PWMC_PWMEN1(x)                    (((uint32_t)(((uint32_t)(x))<<CT32B1_PWMC_PWMEN1_SHIFT))&CT32B1_PWMC_PWMEN1_MASK) /*!< CT32B1_PWMC                             */
#define CT32B1_PWMC_PWMEN2_MASK                  (0x4U)                                              /*!< CT32B1_PWMC: PWMEN2 Mask                */
#define CT32B1_PWMC_PWMEN2_SHIFT                 (2U)                                                /*!< CT32B1_PWMC: PWMEN2 Position            */
#define CT32B1_PWMC_PWMEN2(x)                    (((uint32_t)(((uint32_t)(x))<<CT32B1_PWMC_PWMEN2_SHIFT))&CT32B1_PWMC_PWMEN2_MASK) /*!< CT32B1_PWMC                             */
#define CT32B1_PWMC_PWMEN3_MASK                  (0x8U)                                              /*!< CT32B1_PWMC: PWMEN3 Mask                */
#define CT32B1_PWMC_PWMEN3_SHIFT                 (3U)                                                /*!< CT32B1_PWMC: PWMEN3 Position            */
#define CT32B1_PWMC_PWMEN3(x)                    (((uint32_t)(((uint32_t)(x))<<CT32B1_PWMC_PWMEN3_SHIFT))&CT32B1_PWMC_PWMEN3_MASK) /*!< CT32B1_PWMC                             */
/**
 * @} */ /* End group CT32B_Register_Masks_GROUP 
 */

/* CT32B1 - Peripheral instance base addresses */
#define CT32B1_BasePtr                 0x40018000UL //!< Peripheral base address
#define CT32B1                         ((CT32B1_Type *) CT32B1_BasePtr) //!< Freescale base pointer
#define CT32B1_BASE_PTR                (CT32B1) //!< Freescale style base pointer
/**
 * @} */ /* End group CT32B_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FLASHCTRL_Peripheral_access_layer_GROUP FLASHCTRL Peripheral Access Layer
* @brief C Struct for FLASHCTRL
* @{
*/

/* ================================================================================ */
/* ================           FLASHCTRL (file:FLASHCTRL_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief Flash
controller
 */
/**
* @addtogroup FLASHCTRL_structs_GROUP FLASHCTRL struct
* @brief Struct for FLASHCTRL
* @{
*/
typedef struct {                                /*       FLASHCTRL Structure                                          */
        uint8_t   RESERVED_0[16];              
   __IO uint32_t  FLASHCFG;                     /**< 0010: Flash memory access time configuration register              */
        uint8_t   RESERVED_1[12];              
   __IO uint32_t  FMSSTART;                     /**< 0020: Signature start address register                             */
   __IO uint32_t  FMSSTOP;                      /**< 0024: Signature stop-address register                              */
        uint8_t   RESERVED_2[4];               
   __I  uint32_t  FMSW0;                        /**< 002C: Word 0 [31:0]                                                */
   __I  uint32_t  FMSW1;                        /**< 0030: Word 1 [63:32]                                               */
   __I  uint32_t  FMSW2;                        /**< 0034: Word 2 [95:64]                                               */
   __I  uint32_t  FMSW3;                        /**< 0038: Word 3 [127:96]                                              */
        uint8_t   RESERVED_3[96];              
   __IO uint32_t  EEMSSTART;                    /**< 009C: EEPROM BIST start address register                           */
   __IO uint32_t  EEMSSTOP;                     /**< 00A0: EEPROM BIST stop address register                            */
   __I  uint32_t  EEMSSIG;                      /**< 00A4: EEPROM 24-bit BIST signature register                        */
        uint8_t   RESERVED_4[3896];            
   __I  uint32_t  FMSTAT;                       /**< 0FE0: Signature generation status register                         */
        uint8_t   RESERVED_5[4];               
   __O  uint32_t  FMSTATCLR;                    /**< 0FE8: Signature generation status clear register                   */
} FLASHCTRL_Type;

/**
 * @} */ /* End group FLASHCTRL_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FLASHCTRL' Position & Mask macros                   ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FLASHCTRL_Register_Masks_GROUP FLASHCTRL Register Masks
* @brief Register Masks for FLASHCTRL
* @{
*/
/* ------- FLASHCFG Bit Fields                      ------ */
#define FLASHCTRL_FLASHCFG_FLASHTIM_MASK         (0x3U)                                              /*!< FLASHCTRL_FLASHCFG: FLASHTIM Mask       */
#define FLASHCTRL_FLASHCFG_FLASHTIM_SHIFT        (0U)                                                /*!< FLASHCTRL_FLASHCFG: FLASHTIM Position   */
#define FLASHCTRL_FLASHCFG_FLASHTIM(x)           (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FLASHCFG_FLASHTIM_SHIFT))&FLASHCTRL_FLASHCFG_FLASHTIM_MASK) /*!< FLASHCTRL_FLASHCFG                      */
/* ------- FMSSTART Bit Fields                      ------ */
#define FLASHCTRL_FMSSTART_START_MASK            (0x1FFFFU)                                          /*!< FLASHCTRL_FMSSTART: START Mask          */
#define FLASHCTRL_FMSSTART_START_SHIFT           (0U)                                                /*!< FLASHCTRL_FMSSTART: START Position      */
#define FLASHCTRL_FMSSTART_START(x)              (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSSTART_START_SHIFT))&FLASHCTRL_FMSSTART_START_MASK) /*!< FLASHCTRL_FMSSTART                      */
/* ------- FMSSTOP Bit Fields                       ------ */
#define FLASHCTRL_FMSSTOP_STOP_MASK              (0x1FFFFU)                                          /*!< FLASHCTRL_FMSSTOP: STOP Mask            */
#define FLASHCTRL_FMSSTOP_STOP_SHIFT             (0U)                                                /*!< FLASHCTRL_FMSSTOP: STOP Position        */
#define FLASHCTRL_FMSSTOP_STOP(x)                (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSSTOP_STOP_SHIFT))&FLASHCTRL_FMSSTOP_STOP_MASK) /*!< FLASHCTRL_FMSSTOP                       */
#define FLASHCTRL_FMSSTOP_SIG_START_MASK         (0x20000U)                                          /*!< FLASHCTRL_FMSSTOP: SIG_START Mask       */
#define FLASHCTRL_FMSSTOP_SIG_START_SHIFT        (17U)                                               /*!< FLASHCTRL_FMSSTOP: SIG_START Position   */
#define FLASHCTRL_FMSSTOP_SIG_START(x)           (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSSTOP_SIG_START_SHIFT))&FLASHCTRL_FMSSTOP_SIG_START_MASK) /*!< FLASHCTRL_FMSSTOP                       */
/* ------- FMSW0 Bit Fields                         ------ */
#define FLASHCTRL_FMSW0_SW0_31_0_MASK            (0xFFFFFFFFU)                                       /*!< FLASHCTRL_FMSW0: SW0_31_0 Mask          */
#define FLASHCTRL_FMSW0_SW0_31_0_SHIFT           (0U)                                                /*!< FLASHCTRL_FMSW0: SW0_31_0 Position      */
#define FLASHCTRL_FMSW0_SW0_31_0(x)              (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSW0_SW0_31_0_SHIFT))&FLASHCTRL_FMSW0_SW0_31_0_MASK) /*!< FLASHCTRL_FMSW0                         */
/* ------- FMSW1 Bit Fields                         ------ */
#define FLASHCTRL_FMSW1_SW1_63_32_MASK           (0xFFFFFFFFU)                                       /*!< FLASHCTRL_FMSW1: SW1_63_32 Mask         */
#define FLASHCTRL_FMSW1_SW1_63_32_SHIFT          (0U)                                                /*!< FLASHCTRL_FMSW1: SW1_63_32 Position     */
#define FLASHCTRL_FMSW1_SW1_63_32(x)             (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSW1_SW1_63_32_SHIFT))&FLASHCTRL_FMSW1_SW1_63_32_MASK) /*!< FLASHCTRL_FMSW1                         */
/* ------- FMSW2 Bit Fields                         ------ */
#define FLASHCTRL_FMSW2_SW2_95_64_MASK           (0xFFFFFFFFU)                                       /*!< FLASHCTRL_FMSW2: SW2_95_64 Mask         */
#define FLASHCTRL_FMSW2_SW2_95_64_SHIFT          (0U)                                                /*!< FLASHCTRL_FMSW2: SW2_95_64 Position     */
#define FLASHCTRL_FMSW2_SW2_95_64(x)             (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSW2_SW2_95_64_SHIFT))&FLASHCTRL_FMSW2_SW2_95_64_MASK) /*!< FLASHCTRL_FMSW2                         */
/* ------- FMSW3 Bit Fields                         ------ */
#define FLASHCTRL_FMSW3_SW3_127_96_MASK          (0xFFFFFFFFU)                                       /*!< FLASHCTRL_FMSW3: SW3_127_96 Mask        */
#define FLASHCTRL_FMSW3_SW3_127_96_SHIFT         (0U)                                                /*!< FLASHCTRL_FMSW3: SW3_127_96 Position    */
#define FLASHCTRL_FMSW3_SW3_127_96(x)            (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSW3_SW3_127_96_SHIFT))&FLASHCTRL_FMSW3_SW3_127_96_MASK) /*!< FLASHCTRL_FMSW3                         */
/* ------- EEMSSTART Bit Fields                     ------ */
#define FLASHCTRL_EEMSSTART_STARTA_MASK          (0x3FFFU)                                           /*!< FLASHCTRL_EEMSSTART: STARTA Mask        */
#define FLASHCTRL_EEMSSTART_STARTA_SHIFT         (0U)                                                /*!< FLASHCTRL_EEMSSTART: STARTA Position    */
#define FLASHCTRL_EEMSSTART_STARTA(x)            (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_EEMSSTART_STARTA_SHIFT))&FLASHCTRL_EEMSSTART_STARTA_MASK) /*!< FLASHCTRL_EEMSSTART                     */
/* ------- EEMSSTOP Bit Fields                      ------ */
#define FLASHCTRL_EEMSSTOP_STOPA_MASK            (0x3FFFU)                                           /*!< FLASHCTRL_EEMSSTOP: STOPA Mask          */
#define FLASHCTRL_EEMSSTOP_STOPA_SHIFT           (0U)                                                /*!< FLASHCTRL_EEMSSTOP: STOPA Position      */
#define FLASHCTRL_EEMSSTOP_STOPA(x)              (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_EEMSSTOP_STOPA_SHIFT))&FLASHCTRL_EEMSSTOP_STOPA_MASK) /*!< FLASHCTRL_EEMSSTOP                      */
#define FLASHCTRL_EEMSSTOP_DEVSEL_MASK           (0x40000000U)                                       /*!< FLASHCTRL_EEMSSTOP: DEVSEL Mask         */
#define FLASHCTRL_EEMSSTOP_DEVSEL_SHIFT          (30U)                                               /*!< FLASHCTRL_EEMSSTOP: DEVSEL Position     */
#define FLASHCTRL_EEMSSTOP_DEVSEL(x)             (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_EEMSSTOP_DEVSEL_SHIFT))&FLASHCTRL_EEMSSTOP_DEVSEL_MASK) /*!< FLASHCTRL_EEMSSTOP                      */
#define FLASHCTRL_EEMSSTOP_STRTBIST_MASK         (0x80000000U)                                       /*!< FLASHCTRL_EEMSSTOP: STRTBIST Mask       */
#define FLASHCTRL_EEMSSTOP_STRTBIST_SHIFT        (31U)                                               /*!< FLASHCTRL_EEMSSTOP: STRTBIST Position   */
#define FLASHCTRL_EEMSSTOP_STRTBIST(x)           (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_EEMSSTOP_STRTBIST_SHIFT))&FLASHCTRL_EEMSSTOP_STRTBIST_MASK) /*!< FLASHCTRL_EEMSSTOP                      */
/* ------- EEMSSIG Bit Fields                       ------ */
#define FLASHCTRL_EEMSSIG_DATA_SIG_MASK          (0xFFFFU)                                           /*!< FLASHCTRL_EEMSSIG: DATA_SIG Mask        */
#define FLASHCTRL_EEMSSIG_DATA_SIG_SHIFT         (0U)                                                /*!< FLASHCTRL_EEMSSIG: DATA_SIG Position    */
#define FLASHCTRL_EEMSSIG_DATA_SIG(x)            (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_EEMSSIG_DATA_SIG_SHIFT))&FLASHCTRL_EEMSSIG_DATA_SIG_MASK) /*!< FLASHCTRL_EEMSSIG                       */
#define FLASHCTRL_EEMSSIG_PARITY_SIG_MASK        (0xFFFF0000U)                                       /*!< FLASHCTRL_EEMSSIG: PARITY_SIG Mask      */
#define FLASHCTRL_EEMSSIG_PARITY_SIG_SHIFT       (16U)                                               /*!< FLASHCTRL_EEMSSIG: PARITY_SIG Position  */
#define FLASHCTRL_EEMSSIG_PARITY_SIG(x)          (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_EEMSSIG_PARITY_SIG_SHIFT))&FLASHCTRL_EEMSSIG_PARITY_SIG_MASK) /*!< FLASHCTRL_EEMSSIG                       */
/* ------- FMSTAT Bit Fields                        ------ */
#define FLASHCTRL_FMSTAT_SIG_DONE_MASK           (0x4U)                                              /*!< FLASHCTRL_FMSTAT: SIG_DONE Mask         */
#define FLASHCTRL_FMSTAT_SIG_DONE_SHIFT          (2U)                                                /*!< FLASHCTRL_FMSTAT: SIG_DONE Position     */
#define FLASHCTRL_FMSTAT_SIG_DONE(x)             (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSTAT_SIG_DONE_SHIFT))&FLASHCTRL_FMSTAT_SIG_DONE_MASK) /*!< FLASHCTRL_FMSTAT                        */
/* ------- FMSTATCLR Bit Fields                     ------ */
#define FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_MASK    (0x4U)                                              /*!< FLASHCTRL_FMSTATCLR: SIG_DONE_CLR Mask  */
#define FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_SHIFT   (2U)                                                /*!< FLASHCTRL_FMSTATCLR: SIG_DONE_CLR Position*/
#define FLASHCTRL_FMSTATCLR_SIG_DONE_CLR(x)      (((uint32_t)(((uint32_t)(x))<<FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_SHIFT))&FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_MASK) /*!< FLASHCTRL_FMSTATCLR                     */
/**
 * @} */ /* End group FLASHCTRL_Register_Masks_GROUP 
 */

/* FLASHCTRL - Peripheral instance base addresses */
#define FLASHCTRL_BasePtr              0x4003C000UL //!< Peripheral base address
#define FLASHCTRL                      ((FLASHCTRL_Type *) FLASHCTRL_BasePtr) //!< Freescale base pointer
#define FLASHCTRL_BASE_PTR             (FLASHCTRL) //!< Freescale style base pointer
/**
 * @} */ /* End group FLASHCTRL_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_GROUP_INT0_Peripheral_access_layer_GROUP GPIO_GROUP_INT0 Peripheral Access Layer
* @brief C Struct for GPIO_GROUP_INT0
* @{
*/

/* ================================================================================ */
/* ================           GPIO_GROUP_INT0 (file:GPIO_GROUP_INT0_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief GPIO group interrupt
 */
/**
* @addtogroup GPIO_GROUP_INT0_structs_GROUP GPIO_GROUP_INT0 struct
* @brief Struct for GPIO_GROUP_INT0
* @{
*/
typedef struct {                                /*       GPIO_GROUP_INT0 Structure                                    */
   __IO uint32_t  CTRL;                         /**< 0000: GPIO grouped interrupt control register                      */
        uint8_t   RESERVED_0[28];              
   __IO uint32_t  PORT_POL[2];                  /**< 0020: GPIO grouped interrupt port  polarity register               */
        uint8_t   RESERVED_1[24];              
   __IO uint32_t  PORT_ENA[2];                  /**< 0040: GPIO grouped interrupt port  enable register                 */
} GPIO_GROUP_INT0_Type;

/**
 * @} */ /* End group GPIO_GROUP_INT0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIO_GROUP_INT0' Position & Mask macros             ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_GROUP_INT0_Register_Masks_GROUP GPIO_GROUP_INT0 Register Masks
* @brief Register Masks for GPIO_GROUP_INT0
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define GPIO_GROUP_INT0_CTRL_INT_MASK            (0x1U)                                              /*!< GPIO_GROUP_INT0_CTRL: INT Mask          */
#define GPIO_GROUP_INT0_CTRL_INT_SHIFT           (0U)                                                /*!< GPIO_GROUP_INT0_CTRL: INT Position      */
#define GPIO_GROUP_INT0_CTRL_INT(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_CTRL_INT_SHIFT))&GPIO_GROUP_INT0_CTRL_INT_MASK) /*!< GPIO_GROUP_INT0_CTRL                    */
#define GPIO_GROUP_INT0_CTRL_COMB_MASK           (0x2U)                                              /*!< GPIO_GROUP_INT0_CTRL: COMB Mask         */
#define GPIO_GROUP_INT0_CTRL_COMB_SHIFT          (1U)                                                /*!< GPIO_GROUP_INT0_CTRL: COMB Position     */
#define GPIO_GROUP_INT0_CTRL_COMB(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_CTRL_COMB_SHIFT))&GPIO_GROUP_INT0_CTRL_COMB_MASK) /*!< GPIO_GROUP_INT0_CTRL                    */
#define GPIO_GROUP_INT0_CTRL_TRIG_MASK           (0x4U)                                              /*!< GPIO_GROUP_INT0_CTRL: TRIG Mask         */
#define GPIO_GROUP_INT0_CTRL_TRIG_SHIFT          (2U)                                                /*!< GPIO_GROUP_INT0_CTRL: TRIG Position     */
#define GPIO_GROUP_INT0_CTRL_TRIG(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_CTRL_TRIG_SHIFT))&GPIO_GROUP_INT0_CTRL_TRIG_MASK) /*!< GPIO_GROUP_INT0_CTRL                    */
/* ------- PORT_POL Bit Fields                      ------ */
#define GPIO_GROUP_INT0_PORT_POL_POL_0_MASK      (0x1U)                                              /*!< GPIO_GROUP_INT0_PORT_POL: POL_0 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_0_SHIFT     (0U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_0 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_0(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_0_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_0_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_1_MASK      (0x2U)                                              /*!< GPIO_GROUP_INT0_PORT_POL: POL_1 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_1_SHIFT     (1U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_1 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_1(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_1_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_1_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_2_MASK      (0x4U)                                              /*!< GPIO_GROUP_INT0_PORT_POL: POL_2 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_2_SHIFT     (2U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_2 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_2(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_2_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_2_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_3_MASK      (0x8U)                                              /*!< GPIO_GROUP_INT0_PORT_POL: POL_3 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_3_SHIFT     (3U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_3 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_3(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_3_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_3_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_4_MASK      (0x10U)                                             /*!< GPIO_GROUP_INT0_PORT_POL: POL_4 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_4_SHIFT     (4U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_4 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_4(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_4_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_4_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_5_MASK      (0x20U)                                             /*!< GPIO_GROUP_INT0_PORT_POL: POL_5 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_5_SHIFT     (5U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_5 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_5(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_5_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_5_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_6_MASK      (0x40U)                                             /*!< GPIO_GROUP_INT0_PORT_POL: POL_6 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_6_SHIFT     (6U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_6 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_6(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_6_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_6_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_7_MASK      (0x80U)                                             /*!< GPIO_GROUP_INT0_PORT_POL: POL_7 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_7_SHIFT     (7U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_7 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_7(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_7_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_7_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_8_MASK      (0x100U)                                            /*!< GPIO_GROUP_INT0_PORT_POL: POL_8 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_8_SHIFT     (8U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_8 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_8(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_8_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_8_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_9_MASK      (0x200U)                                            /*!< GPIO_GROUP_INT0_PORT_POL: POL_9 Mask    */
#define GPIO_GROUP_INT0_PORT_POL_POL_9_SHIFT     (9U)                                                /*!< GPIO_GROUP_INT0_PORT_POL: POL_9 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_9(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_9_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_9_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_10_MASK     (0x400U)                                            /*!< GPIO_GROUP_INT0_PORT_POL: POL_10 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_10_SHIFT    (10U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_10 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_10(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_10_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_10_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_11_MASK     (0x800U)                                            /*!< GPIO_GROUP_INT0_PORT_POL: POL_11 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_11_SHIFT    (11U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_11 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_11(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_11_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_11_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_12_MASK     (0x1000U)                                           /*!< GPIO_GROUP_INT0_PORT_POL: POL_12 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_12_SHIFT    (12U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_12 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_12(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_12_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_12_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_13_MASK     (0x2000U)                                           /*!< GPIO_GROUP_INT0_PORT_POL: POL_13 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_13_SHIFT    (13U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_13 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_13(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_13_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_13_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_14_MASK     (0x4000U)                                           /*!< GPIO_GROUP_INT0_PORT_POL: POL_14 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_14_SHIFT    (14U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_14 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_14(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_14_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_14_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_15_MASK     (0x8000U)                                           /*!< GPIO_GROUP_INT0_PORT_POL: POL_15 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_15_SHIFT    (15U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_15 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_15(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_15_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_15_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_16_MASK     (0x10000U)                                          /*!< GPIO_GROUP_INT0_PORT_POL: POL_16 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_16_SHIFT    (16U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_16 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_16(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_16_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_16_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_17_MASK     (0x20000U)                                          /*!< GPIO_GROUP_INT0_PORT_POL: POL_17 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_17_SHIFT    (17U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_17 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_17(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_17_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_17_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_18_MASK     (0x40000U)                                          /*!< GPIO_GROUP_INT0_PORT_POL: POL_18 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_18_SHIFT    (18U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_18 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_18(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_18_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_18_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_19_MASK     (0x80000U)                                          /*!< GPIO_GROUP_INT0_PORT_POL: POL_19 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_19_SHIFT    (19U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_19 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_19(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_19_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_19_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_20_MASK     (0x100000U)                                         /*!< GPIO_GROUP_INT0_PORT_POL: POL_20 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_20_SHIFT    (20U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_20 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_20(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_20_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_20_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_21_MASK     (0x200000U)                                         /*!< GPIO_GROUP_INT0_PORT_POL: POL_21 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_21_SHIFT    (21U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_21 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_21(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_21_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_21_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_22_MASK     (0x400000U)                                         /*!< GPIO_GROUP_INT0_PORT_POL: POL_22 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_22_SHIFT    (22U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_22 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_22(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_22_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_22_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_23_MASK     (0x800000U)                                         /*!< GPIO_GROUP_INT0_PORT_POL: POL_23 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_23_SHIFT    (23U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_23 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_23(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_23_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_23_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_24_MASK     (0x1000000U)                                        /*!< GPIO_GROUP_INT0_PORT_POL: POL_24 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_24_SHIFT    (24U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_24 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_24(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_24_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_24_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_25_MASK     (0x2000000U)                                        /*!< GPIO_GROUP_INT0_PORT_POL: POL_25 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_25_SHIFT    (25U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_25 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_25(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_25_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_25_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_26_MASK     (0x4000000U)                                        /*!< GPIO_GROUP_INT0_PORT_POL: POL_26 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_26_SHIFT    (26U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_26 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_26(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_26_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_26_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_27_MASK     (0x8000000U)                                        /*!< GPIO_GROUP_INT0_PORT_POL: POL_27 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_27_SHIFT    (27U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_27 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_27(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_27_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_27_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_28_MASK     (0x10000000U)                                       /*!< GPIO_GROUP_INT0_PORT_POL: POL_28 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_28_SHIFT    (28U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_28 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_28(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_28_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_28_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_29_MASK     (0x20000000U)                                       /*!< GPIO_GROUP_INT0_PORT_POL: POL_29 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_29_SHIFT    (29U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_29 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_29(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_29_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_29_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_30_MASK     (0x40000000U)                                       /*!< GPIO_GROUP_INT0_PORT_POL: POL_30 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_30_SHIFT    (30U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_30 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_30(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_30_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_30_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
#define GPIO_GROUP_INT0_PORT_POL_POL_31_MASK     (0x80000000U)                                       /*!< GPIO_GROUP_INT0_PORT_POL: POL_31 Mask   */
#define GPIO_GROUP_INT0_PORT_POL_POL_31_SHIFT    (31U)                                               /*!< GPIO_GROUP_INT0_PORT_POL: POL_31 Position*/
#define GPIO_GROUP_INT0_PORT_POL_POL_31(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_POL_POL_31_SHIFT))&GPIO_GROUP_INT0_PORT_POL_POL_31_MASK) /*!< GPIO_GROUP_INT0_PORT_POL                */
/* ------- PORT_ENA Bit Fields                      ------ */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_0_MASK      (0x1U)                                              /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_0 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_0_SHIFT     (0U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_0 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_0(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_0_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_0_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_1_MASK      (0x2U)                                              /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_1 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_1_SHIFT     (1U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_1 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_1(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_1_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_1_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_2_MASK      (0x4U)                                              /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_2 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_2_SHIFT     (2U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_2 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_2(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_2_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_2_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_3_MASK      (0x8U)                                              /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_3 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_3_SHIFT     (3U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_3 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_3(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_3_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_3_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_4_MASK      (0x10U)                                             /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_4 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_4_SHIFT     (4U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_4 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_4(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_4_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_4_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_5_MASK      (0x20U)                                             /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_5 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_5_SHIFT     (5U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_5 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_5(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_5_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_5_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_6_MASK      (0x40U)                                             /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_6 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_6_SHIFT     (6U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_6 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_6(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_6_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_6_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_7_MASK      (0x80U)                                             /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_7 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_7_SHIFT     (7U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_7 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_7(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_7_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_7_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_8_MASK      (0x100U)                                            /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_8 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_8_SHIFT     (8U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_8 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_8(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_8_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_8_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_9_MASK      (0x200U)                                            /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_9 Mask    */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_9_SHIFT     (9U)                                                /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_9 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_9(x)        (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_9_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_9_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_10_MASK     (0x400U)                                            /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_10 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_10_SHIFT    (10U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_10 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_10(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_10_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_10_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_11_MASK     (0x800U)                                            /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_11 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_11_SHIFT    (11U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_11 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_11(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_11_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_11_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_12_MASK     (0x1000U)                                           /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_12 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_12_SHIFT    (12U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_12 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_12(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_12_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_12_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_13_MASK     (0x2000U)                                           /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_13 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_13_SHIFT    (13U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_13 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_13(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_13_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_13_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_14_MASK     (0x4000U)                                           /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_14 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_14_SHIFT    (14U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_14 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_14(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_14_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_14_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_15_MASK     (0x8000U)                                           /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_15 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_15_SHIFT    (15U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_15 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_15(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_15_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_15_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_16_MASK     (0x10000U)                                          /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_16 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_16_SHIFT    (16U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_16 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_16(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_16_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_16_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_17_MASK     (0x20000U)                                          /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_17 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_17_SHIFT    (17U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_17 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_17(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_17_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_17_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_18_MASK     (0x40000U)                                          /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_18 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_18_SHIFT    (18U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_18 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_18(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_18_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_18_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_19_MASK     (0x80000U)                                          /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_19 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_19_SHIFT    (19U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_19 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_19(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_19_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_19_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_20_MASK     (0x100000U)                                         /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_20 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_20_SHIFT    (20U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_20 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_20(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_20_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_20_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_21_MASK     (0x200000U)                                         /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_21 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_21_SHIFT    (21U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_21 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_21(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_21_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_21_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_22_MASK     (0x400000U)                                         /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_22 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_22_SHIFT    (22U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_22 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_22(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_22_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_22_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_23_MASK     (0x800000U)                                         /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_23 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_23_SHIFT    (23U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_23 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_23(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_23_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_23_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_24_MASK     (0x1000000U)                                        /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_24 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_24_SHIFT    (24U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_24 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_24(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_24_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_24_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_25_MASK     (0x2000000U)                                        /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_25 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_25_SHIFT    (25U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_25 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_25(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_25_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_25_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_26_MASK     (0x4000000U)                                        /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_26 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_26_SHIFT    (26U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_26 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_26(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_26_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_26_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_27_MASK     (0x8000000U)                                        /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_27 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_27_SHIFT    (27U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_27 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_27(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_27_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_27_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_28_MASK     (0x10000000U)                                       /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_28 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_28_SHIFT    (28U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_28 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_28(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_28_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_28_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_29_MASK     (0x20000000U)                                       /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_29 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_29_SHIFT    (29U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_29 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_29(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_29_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_29_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_30_MASK     (0x40000000U)                                       /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_30 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_30_SHIFT    (30U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_30 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_30(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_30_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_30_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_31_MASK     (0x80000000U)                                       /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_31 Mask   */
#define GPIO_GROUP_INT0_PORT_ENA_ENA_31_SHIFT    (31U)                                               /*!< GPIO_GROUP_INT0_PORT_ENA: ENA_31 Position*/
#define GPIO_GROUP_INT0_PORT_ENA_ENA_31(x)       (((uint32_t)(((uint32_t)(x))<<GPIO_GROUP_INT0_PORT_ENA_ENA_31_SHIFT))&GPIO_GROUP_INT0_PORT_ENA_ENA_31_MASK) /*!< GPIO_GROUP_INT0_PORT_ENA                */
/**
 * @} */ /* End group GPIO_GROUP_INT0_Register_Masks_GROUP 
 */

/* GPIO_GROUP_INT0 - Peripheral instance base addresses */
#define GPIO_GROUP_INT0_BasePtr        0x4005C000UL //!< Peripheral base address
#define GPIO_GROUP_INT0                ((GPIO_GROUP_INT0_Type *) GPIO_GROUP_INT0_BasePtr) //!< Freescale base pointer
#define GPIO_GROUP_INT0_BASE_PTR       (GPIO_GROUP_INT0) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_GROUP_INT0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_GROUP_INT0_Peripheral_access_layer_GROUP GPIO_GROUP_INT0 Peripheral Access Layer
* @brief C Struct for GPIO_GROUP_INT0
* @{
*/

/* ================================================================================ */
/* ================           GPIO_GROUP_INT1 (derived from GPIO_GROUP_INT0)       ================ */
/* ================================================================================ */

/**
 * @brief GPIO group interrupt
 */

/* GPIO_GROUP_INT1 - Peripheral instance base addresses */
#define GPIO_GROUP_INT1_BasePtr        0x40060000UL //!< Peripheral base address
#define GPIO_GROUP_INT1                ((GPIO_GROUP_INT0_Type *) GPIO_GROUP_INT1_BasePtr) //!< Freescale base pointer
#define GPIO_GROUP_INT1_BASE_PTR       (GPIO_GROUP_INT1) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_GROUP_INT0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_PIN_INT_Peripheral_access_layer_GROUP GPIO_PIN_INT Peripheral Access Layer
* @brief C Struct for GPIO_PIN_INT
* @{
*/

/* ================================================================================ */
/* ================           GPIO_PIN_INT (file:GPIO_PIN_INT_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief GPIO pin interrupt
 */
/**
* @addtogroup GPIO_PIN_INT_structs_GROUP GPIO_PIN_INT struct
* @brief Struct for GPIO_PIN_INT
* @{
*/
typedef struct {                                /*       GPIO_PIN_INT Structure                                       */
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
} GPIO_PIN_INT_Type;

/**
 * @} */ /* End group GPIO_PIN_INT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIO_PIN_INT' Position & Mask macros                ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_PIN_INT_Register_Masks_GROUP GPIO_PIN_INT Register Masks
* @brief Register Masks for GPIO_PIN_INT
* @{
*/
/* ------- ISEL Bit Fields                          ------ */
#define GPIO_PIN_INT_ISEL_PMODE0_MASK            (0x1U)                                              /*!< GPIO_PIN_INT_ISEL: PMODE0 Mask          */
#define GPIO_PIN_INT_ISEL_PMODE0_SHIFT           (0U)                                                /*!< GPIO_PIN_INT_ISEL: PMODE0 Position      */
#define GPIO_PIN_INT_ISEL_PMODE0(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_ISEL_PMODE0_SHIFT))&GPIO_PIN_INT_ISEL_PMODE0_MASK) /*!< GPIO_PIN_INT_ISEL                       */
#define GPIO_PIN_INT_ISEL_PMODE1_MASK            (0x2U)                                              /*!< GPIO_PIN_INT_ISEL: PMODE1 Mask          */
#define GPIO_PIN_INT_ISEL_PMODE1_SHIFT           (1U)                                                /*!< GPIO_PIN_INT_ISEL: PMODE1 Position      */
#define GPIO_PIN_INT_ISEL_PMODE1(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_ISEL_PMODE1_SHIFT))&GPIO_PIN_INT_ISEL_PMODE1_MASK) /*!< GPIO_PIN_INT_ISEL                       */
#define GPIO_PIN_INT_ISEL_PMODE2_MASK            (0x4U)                                              /*!< GPIO_PIN_INT_ISEL: PMODE2 Mask          */
#define GPIO_PIN_INT_ISEL_PMODE2_SHIFT           (2U)                                                /*!< GPIO_PIN_INT_ISEL: PMODE2 Position      */
#define GPIO_PIN_INT_ISEL_PMODE2(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_ISEL_PMODE2_SHIFT))&GPIO_PIN_INT_ISEL_PMODE2_MASK) /*!< GPIO_PIN_INT_ISEL                       */
#define GPIO_PIN_INT_ISEL_PMODE3_MASK            (0x8U)                                              /*!< GPIO_PIN_INT_ISEL: PMODE3 Mask          */
#define GPIO_PIN_INT_ISEL_PMODE3_SHIFT           (3U)                                                /*!< GPIO_PIN_INT_ISEL: PMODE3 Position      */
#define GPIO_PIN_INT_ISEL_PMODE3(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_ISEL_PMODE3_SHIFT))&GPIO_PIN_INT_ISEL_PMODE3_MASK) /*!< GPIO_PIN_INT_ISEL                       */
#define GPIO_PIN_INT_ISEL_PMODE4_MASK            (0x10U)                                             /*!< GPIO_PIN_INT_ISEL: PMODE4 Mask          */
#define GPIO_PIN_INT_ISEL_PMODE4_SHIFT           (4U)                                                /*!< GPIO_PIN_INT_ISEL: PMODE4 Position      */
#define GPIO_PIN_INT_ISEL_PMODE4(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_ISEL_PMODE4_SHIFT))&GPIO_PIN_INT_ISEL_PMODE4_MASK) /*!< GPIO_PIN_INT_ISEL                       */
#define GPIO_PIN_INT_ISEL_PMODE5_MASK            (0x20U)                                             /*!< GPIO_PIN_INT_ISEL: PMODE5 Mask          */
#define GPIO_PIN_INT_ISEL_PMODE5_SHIFT           (5U)                                                /*!< GPIO_PIN_INT_ISEL: PMODE5 Position      */
#define GPIO_PIN_INT_ISEL_PMODE5(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_ISEL_PMODE5_SHIFT))&GPIO_PIN_INT_ISEL_PMODE5_MASK) /*!< GPIO_PIN_INT_ISEL                       */
#define GPIO_PIN_INT_ISEL_PMODE6_MASK            (0x40U)                                             /*!< GPIO_PIN_INT_ISEL: PMODE6 Mask          */
#define GPIO_PIN_INT_ISEL_PMODE6_SHIFT           (6U)                                                /*!< GPIO_PIN_INT_ISEL: PMODE6 Position      */
#define GPIO_PIN_INT_ISEL_PMODE6(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_ISEL_PMODE6_SHIFT))&GPIO_PIN_INT_ISEL_PMODE6_MASK) /*!< GPIO_PIN_INT_ISEL                       */
#define GPIO_PIN_INT_ISEL_PMODE7_MASK            (0x80U)                                             /*!< GPIO_PIN_INT_ISEL: PMODE7 Mask          */
#define GPIO_PIN_INT_ISEL_PMODE7_SHIFT           (7U)                                                /*!< GPIO_PIN_INT_ISEL: PMODE7 Position      */
#define GPIO_PIN_INT_ISEL_PMODE7(x)              (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_ISEL_PMODE7_SHIFT))&GPIO_PIN_INT_ISEL_PMODE7_MASK) /*!< GPIO_PIN_INT_ISEL                       */
/* ------- IENR Bit Fields                          ------ */
#define GPIO_PIN_INT_IENR_ENRL0_MASK             (0x1U)                                              /*!< GPIO_PIN_INT_IENR: ENRL0 Mask           */
#define GPIO_PIN_INT_IENR_ENRL0_SHIFT            (0U)                                                /*!< GPIO_PIN_INT_IENR: ENRL0 Position       */
#define GPIO_PIN_INT_IENR_ENRL0(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENR_ENRL0_SHIFT))&GPIO_PIN_INT_IENR_ENRL0_MASK) /*!< GPIO_PIN_INT_IENR                       */
#define GPIO_PIN_INT_IENR_ENRL1_MASK             (0x2U)                                              /*!< GPIO_PIN_INT_IENR: ENRL1 Mask           */
#define GPIO_PIN_INT_IENR_ENRL1_SHIFT            (1U)                                                /*!< GPIO_PIN_INT_IENR: ENRL1 Position       */
#define GPIO_PIN_INT_IENR_ENRL1(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENR_ENRL1_SHIFT))&GPIO_PIN_INT_IENR_ENRL1_MASK) /*!< GPIO_PIN_INT_IENR                       */
#define GPIO_PIN_INT_IENR_ENRL2_MASK             (0x4U)                                              /*!< GPIO_PIN_INT_IENR: ENRL2 Mask           */
#define GPIO_PIN_INT_IENR_ENRL2_SHIFT            (2U)                                                /*!< GPIO_PIN_INT_IENR: ENRL2 Position       */
#define GPIO_PIN_INT_IENR_ENRL2(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENR_ENRL2_SHIFT))&GPIO_PIN_INT_IENR_ENRL2_MASK) /*!< GPIO_PIN_INT_IENR                       */
#define GPIO_PIN_INT_IENR_ENRL3_MASK             (0x8U)                                              /*!< GPIO_PIN_INT_IENR: ENRL3 Mask           */
#define GPIO_PIN_INT_IENR_ENRL3_SHIFT            (3U)                                                /*!< GPIO_PIN_INT_IENR: ENRL3 Position       */
#define GPIO_PIN_INT_IENR_ENRL3(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENR_ENRL3_SHIFT))&GPIO_PIN_INT_IENR_ENRL3_MASK) /*!< GPIO_PIN_INT_IENR                       */
#define GPIO_PIN_INT_IENR_ENRL4_MASK             (0x10U)                                             /*!< GPIO_PIN_INT_IENR: ENRL4 Mask           */
#define GPIO_PIN_INT_IENR_ENRL4_SHIFT            (4U)                                                /*!< GPIO_PIN_INT_IENR: ENRL4 Position       */
#define GPIO_PIN_INT_IENR_ENRL4(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENR_ENRL4_SHIFT))&GPIO_PIN_INT_IENR_ENRL4_MASK) /*!< GPIO_PIN_INT_IENR                       */
#define GPIO_PIN_INT_IENR_ENRL5_MASK             (0x20U)                                             /*!< GPIO_PIN_INT_IENR: ENRL5 Mask           */
#define GPIO_PIN_INT_IENR_ENRL5_SHIFT            (5U)                                                /*!< GPIO_PIN_INT_IENR: ENRL5 Position       */
#define GPIO_PIN_INT_IENR_ENRL5(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENR_ENRL5_SHIFT))&GPIO_PIN_INT_IENR_ENRL5_MASK) /*!< GPIO_PIN_INT_IENR                       */
#define GPIO_PIN_INT_IENR_ENRL6_MASK             (0x40U)                                             /*!< GPIO_PIN_INT_IENR: ENRL6 Mask           */
#define GPIO_PIN_INT_IENR_ENRL6_SHIFT            (6U)                                                /*!< GPIO_PIN_INT_IENR: ENRL6 Position       */
#define GPIO_PIN_INT_IENR_ENRL6(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENR_ENRL6_SHIFT))&GPIO_PIN_INT_IENR_ENRL6_MASK) /*!< GPIO_PIN_INT_IENR                       */
#define GPIO_PIN_INT_IENR_ENRL7_MASK             (0x80U)                                             /*!< GPIO_PIN_INT_IENR: ENRL7 Mask           */
#define GPIO_PIN_INT_IENR_ENRL7_SHIFT            (7U)                                                /*!< GPIO_PIN_INT_IENR: ENRL7 Position       */
#define GPIO_PIN_INT_IENR_ENRL7(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENR_ENRL7_SHIFT))&GPIO_PIN_INT_IENR_ENRL7_MASK) /*!< GPIO_PIN_INT_IENR                       */
/* ------- SIENR Bit Fields                         ------ */
#define GPIO_PIN_INT_SIENR_SETENRL0_MASK         (0x1U)                                              /*!< GPIO_PIN_INT_SIENR: SETENRL0 Mask       */
#define GPIO_PIN_INT_SIENR_SETENRL0_SHIFT        (0U)                                                /*!< GPIO_PIN_INT_SIENR: SETENRL0 Position   */
#define GPIO_PIN_INT_SIENR_SETENRL0(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENR_SETENRL0_SHIFT))&GPIO_PIN_INT_SIENR_SETENRL0_MASK) /*!< GPIO_PIN_INT_SIENR                      */
#define GPIO_PIN_INT_SIENR_SETENRL1_MASK         (0x2U)                                              /*!< GPIO_PIN_INT_SIENR: SETENRL1 Mask       */
#define GPIO_PIN_INT_SIENR_SETENRL1_SHIFT        (1U)                                                /*!< GPIO_PIN_INT_SIENR: SETENRL1 Position   */
#define GPIO_PIN_INT_SIENR_SETENRL1(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENR_SETENRL1_SHIFT))&GPIO_PIN_INT_SIENR_SETENRL1_MASK) /*!< GPIO_PIN_INT_SIENR                      */
#define GPIO_PIN_INT_SIENR_SETENRL2_MASK         (0x4U)                                              /*!< GPIO_PIN_INT_SIENR: SETENRL2 Mask       */
#define GPIO_PIN_INT_SIENR_SETENRL2_SHIFT        (2U)                                                /*!< GPIO_PIN_INT_SIENR: SETENRL2 Position   */
#define GPIO_PIN_INT_SIENR_SETENRL2(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENR_SETENRL2_SHIFT))&GPIO_PIN_INT_SIENR_SETENRL2_MASK) /*!< GPIO_PIN_INT_SIENR                      */
#define GPIO_PIN_INT_SIENR_SETENRL3_MASK         (0x8U)                                              /*!< GPIO_PIN_INT_SIENR: SETENRL3 Mask       */
#define GPIO_PIN_INT_SIENR_SETENRL3_SHIFT        (3U)                                                /*!< GPIO_PIN_INT_SIENR: SETENRL3 Position   */
#define GPIO_PIN_INT_SIENR_SETENRL3(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENR_SETENRL3_SHIFT))&GPIO_PIN_INT_SIENR_SETENRL3_MASK) /*!< GPIO_PIN_INT_SIENR                      */
#define GPIO_PIN_INT_SIENR_SETENRL4_MASK         (0x10U)                                             /*!< GPIO_PIN_INT_SIENR: SETENRL4 Mask       */
#define GPIO_PIN_INT_SIENR_SETENRL4_SHIFT        (4U)                                                /*!< GPIO_PIN_INT_SIENR: SETENRL4 Position   */
#define GPIO_PIN_INT_SIENR_SETENRL4(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENR_SETENRL4_SHIFT))&GPIO_PIN_INT_SIENR_SETENRL4_MASK) /*!< GPIO_PIN_INT_SIENR                      */
#define GPIO_PIN_INT_SIENR_SETENRL5_MASK         (0x20U)                                             /*!< GPIO_PIN_INT_SIENR: SETENRL5 Mask       */
#define GPIO_PIN_INT_SIENR_SETENRL5_SHIFT        (5U)                                                /*!< GPIO_PIN_INT_SIENR: SETENRL5 Position   */
#define GPIO_PIN_INT_SIENR_SETENRL5(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENR_SETENRL5_SHIFT))&GPIO_PIN_INT_SIENR_SETENRL5_MASK) /*!< GPIO_PIN_INT_SIENR                      */
#define GPIO_PIN_INT_SIENR_SETENRL6_MASK         (0x40U)                                             /*!< GPIO_PIN_INT_SIENR: SETENRL6 Mask       */
#define GPIO_PIN_INT_SIENR_SETENRL6_SHIFT        (6U)                                                /*!< GPIO_PIN_INT_SIENR: SETENRL6 Position   */
#define GPIO_PIN_INT_SIENR_SETENRL6(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENR_SETENRL6_SHIFT))&GPIO_PIN_INT_SIENR_SETENRL6_MASK) /*!< GPIO_PIN_INT_SIENR                      */
#define GPIO_PIN_INT_SIENR_SETENRL7_MASK         (0x80U)                                             /*!< GPIO_PIN_INT_SIENR: SETENRL7 Mask       */
#define GPIO_PIN_INT_SIENR_SETENRL7_SHIFT        (7U)                                                /*!< GPIO_PIN_INT_SIENR: SETENRL7 Position   */
#define GPIO_PIN_INT_SIENR_SETENRL7(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENR_SETENRL7_SHIFT))&GPIO_PIN_INT_SIENR_SETENRL7_MASK) /*!< GPIO_PIN_INT_SIENR                      */
/* ------- CIENR Bit Fields                         ------ */
#define GPIO_PIN_INT_CIENR_CENRL0_MASK           (0x1U)                                              /*!< GPIO_PIN_INT_CIENR: CENRL0 Mask         */
#define GPIO_PIN_INT_CIENR_CENRL0_SHIFT          (0U)                                                /*!< GPIO_PIN_INT_CIENR: CENRL0 Position     */
#define GPIO_PIN_INT_CIENR_CENRL0(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENR_CENRL0_SHIFT))&GPIO_PIN_INT_CIENR_CENRL0_MASK) /*!< GPIO_PIN_INT_CIENR                      */
#define GPIO_PIN_INT_CIENR_CENRL1_MASK           (0x2U)                                              /*!< GPIO_PIN_INT_CIENR: CENRL1 Mask         */
#define GPIO_PIN_INT_CIENR_CENRL1_SHIFT          (1U)                                                /*!< GPIO_PIN_INT_CIENR: CENRL1 Position     */
#define GPIO_PIN_INT_CIENR_CENRL1(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENR_CENRL1_SHIFT))&GPIO_PIN_INT_CIENR_CENRL1_MASK) /*!< GPIO_PIN_INT_CIENR                      */
#define GPIO_PIN_INT_CIENR_CENRL2_MASK           (0x4U)                                              /*!< GPIO_PIN_INT_CIENR: CENRL2 Mask         */
#define GPIO_PIN_INT_CIENR_CENRL2_SHIFT          (2U)                                                /*!< GPIO_PIN_INT_CIENR: CENRL2 Position     */
#define GPIO_PIN_INT_CIENR_CENRL2(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENR_CENRL2_SHIFT))&GPIO_PIN_INT_CIENR_CENRL2_MASK) /*!< GPIO_PIN_INT_CIENR                      */
#define GPIO_PIN_INT_CIENR_CENRL3_MASK           (0x8U)                                              /*!< GPIO_PIN_INT_CIENR: CENRL3 Mask         */
#define GPIO_PIN_INT_CIENR_CENRL3_SHIFT          (3U)                                                /*!< GPIO_PIN_INT_CIENR: CENRL3 Position     */
#define GPIO_PIN_INT_CIENR_CENRL3(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENR_CENRL3_SHIFT))&GPIO_PIN_INT_CIENR_CENRL3_MASK) /*!< GPIO_PIN_INT_CIENR                      */
#define GPIO_PIN_INT_CIENR_CENRL4_MASK           (0x10U)                                             /*!< GPIO_PIN_INT_CIENR: CENRL4 Mask         */
#define GPIO_PIN_INT_CIENR_CENRL4_SHIFT          (4U)                                                /*!< GPIO_PIN_INT_CIENR: CENRL4 Position     */
#define GPIO_PIN_INT_CIENR_CENRL4(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENR_CENRL4_SHIFT))&GPIO_PIN_INT_CIENR_CENRL4_MASK) /*!< GPIO_PIN_INT_CIENR                      */
#define GPIO_PIN_INT_CIENR_CENRL5_MASK           (0x20U)                                             /*!< GPIO_PIN_INT_CIENR: CENRL5 Mask         */
#define GPIO_PIN_INT_CIENR_CENRL5_SHIFT          (5U)                                                /*!< GPIO_PIN_INT_CIENR: CENRL5 Position     */
#define GPIO_PIN_INT_CIENR_CENRL5(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENR_CENRL5_SHIFT))&GPIO_PIN_INT_CIENR_CENRL5_MASK) /*!< GPIO_PIN_INT_CIENR                      */
#define GPIO_PIN_INT_CIENR_CENRL6_MASK           (0x40U)                                             /*!< GPIO_PIN_INT_CIENR: CENRL6 Mask         */
#define GPIO_PIN_INT_CIENR_CENRL6_SHIFT          (6U)                                                /*!< GPIO_PIN_INT_CIENR: CENRL6 Position     */
#define GPIO_PIN_INT_CIENR_CENRL6(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENR_CENRL6_SHIFT))&GPIO_PIN_INT_CIENR_CENRL6_MASK) /*!< GPIO_PIN_INT_CIENR                      */
#define GPIO_PIN_INT_CIENR_CENRL7_MASK           (0x80U)                                             /*!< GPIO_PIN_INT_CIENR: CENRL7 Mask         */
#define GPIO_PIN_INT_CIENR_CENRL7_SHIFT          (7U)                                                /*!< GPIO_PIN_INT_CIENR: CENRL7 Position     */
#define GPIO_PIN_INT_CIENR_CENRL7(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENR_CENRL7_SHIFT))&GPIO_PIN_INT_CIENR_CENRL7_MASK) /*!< GPIO_PIN_INT_CIENR                      */
/* ------- IENF Bit Fields                          ------ */
#define GPIO_PIN_INT_IENF_ENAF0_MASK             (0x1U)                                              /*!< GPIO_PIN_INT_IENF: ENAF0 Mask           */
#define GPIO_PIN_INT_IENF_ENAF0_SHIFT            (0U)                                                /*!< GPIO_PIN_INT_IENF: ENAF0 Position       */
#define GPIO_PIN_INT_IENF_ENAF0(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENF_ENAF0_SHIFT))&GPIO_PIN_INT_IENF_ENAF0_MASK) /*!< GPIO_PIN_INT_IENF                       */
#define GPIO_PIN_INT_IENF_ENAF1_MASK             (0x2U)                                              /*!< GPIO_PIN_INT_IENF: ENAF1 Mask           */
#define GPIO_PIN_INT_IENF_ENAF1_SHIFT            (1U)                                                /*!< GPIO_PIN_INT_IENF: ENAF1 Position       */
#define GPIO_PIN_INT_IENF_ENAF1(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENF_ENAF1_SHIFT))&GPIO_PIN_INT_IENF_ENAF1_MASK) /*!< GPIO_PIN_INT_IENF                       */
#define GPIO_PIN_INT_IENF_ENAF2_MASK             (0x4U)                                              /*!< GPIO_PIN_INT_IENF: ENAF2 Mask           */
#define GPIO_PIN_INT_IENF_ENAF2_SHIFT            (2U)                                                /*!< GPIO_PIN_INT_IENF: ENAF2 Position       */
#define GPIO_PIN_INT_IENF_ENAF2(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENF_ENAF2_SHIFT))&GPIO_PIN_INT_IENF_ENAF2_MASK) /*!< GPIO_PIN_INT_IENF                       */
#define GPIO_PIN_INT_IENF_ENAF3_MASK             (0x8U)                                              /*!< GPIO_PIN_INT_IENF: ENAF3 Mask           */
#define GPIO_PIN_INT_IENF_ENAF3_SHIFT            (3U)                                                /*!< GPIO_PIN_INT_IENF: ENAF3 Position       */
#define GPIO_PIN_INT_IENF_ENAF3(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENF_ENAF3_SHIFT))&GPIO_PIN_INT_IENF_ENAF3_MASK) /*!< GPIO_PIN_INT_IENF                       */
#define GPIO_PIN_INT_IENF_ENAF4_MASK             (0x10U)                                             /*!< GPIO_PIN_INT_IENF: ENAF4 Mask           */
#define GPIO_PIN_INT_IENF_ENAF4_SHIFT            (4U)                                                /*!< GPIO_PIN_INT_IENF: ENAF4 Position       */
#define GPIO_PIN_INT_IENF_ENAF4(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENF_ENAF4_SHIFT))&GPIO_PIN_INT_IENF_ENAF4_MASK) /*!< GPIO_PIN_INT_IENF                       */
#define GPIO_PIN_INT_IENF_ENAF5_MASK             (0x20U)                                             /*!< GPIO_PIN_INT_IENF: ENAF5 Mask           */
#define GPIO_PIN_INT_IENF_ENAF5_SHIFT            (5U)                                                /*!< GPIO_PIN_INT_IENF: ENAF5 Position       */
#define GPIO_PIN_INT_IENF_ENAF5(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENF_ENAF5_SHIFT))&GPIO_PIN_INT_IENF_ENAF5_MASK) /*!< GPIO_PIN_INT_IENF                       */
#define GPIO_PIN_INT_IENF_ENAF6_MASK             (0x40U)                                             /*!< GPIO_PIN_INT_IENF: ENAF6 Mask           */
#define GPIO_PIN_INT_IENF_ENAF6_SHIFT            (6U)                                                /*!< GPIO_PIN_INT_IENF: ENAF6 Position       */
#define GPIO_PIN_INT_IENF_ENAF6(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENF_ENAF6_SHIFT))&GPIO_PIN_INT_IENF_ENAF6_MASK) /*!< GPIO_PIN_INT_IENF                       */
#define GPIO_PIN_INT_IENF_ENAF7_MASK             (0x80U)                                             /*!< GPIO_PIN_INT_IENF: ENAF7 Mask           */
#define GPIO_PIN_INT_IENF_ENAF7_SHIFT            (7U)                                                /*!< GPIO_PIN_INT_IENF: ENAF7 Position       */
#define GPIO_PIN_INT_IENF_ENAF7(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IENF_ENAF7_SHIFT))&GPIO_PIN_INT_IENF_ENAF7_MASK) /*!< GPIO_PIN_INT_IENF                       */
/* ------- SIENF Bit Fields                         ------ */
#define GPIO_PIN_INT_SIENF_SETENAF0_MASK         (0x1U)                                              /*!< GPIO_PIN_INT_SIENF: SETENAF0 Mask       */
#define GPIO_PIN_INT_SIENF_SETENAF0_SHIFT        (0U)                                                /*!< GPIO_PIN_INT_SIENF: SETENAF0 Position   */
#define GPIO_PIN_INT_SIENF_SETENAF0(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENF_SETENAF0_SHIFT))&GPIO_PIN_INT_SIENF_SETENAF0_MASK) /*!< GPIO_PIN_INT_SIENF                      */
#define GPIO_PIN_INT_SIENF_SETENAF1_MASK         (0x2U)                                              /*!< GPIO_PIN_INT_SIENF: SETENAF1 Mask       */
#define GPIO_PIN_INT_SIENF_SETENAF1_SHIFT        (1U)                                                /*!< GPIO_PIN_INT_SIENF: SETENAF1 Position   */
#define GPIO_PIN_INT_SIENF_SETENAF1(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENF_SETENAF1_SHIFT))&GPIO_PIN_INT_SIENF_SETENAF1_MASK) /*!< GPIO_PIN_INT_SIENF                      */
#define GPIO_PIN_INT_SIENF_SETENAF2_MASK         (0x4U)                                              /*!< GPIO_PIN_INT_SIENF: SETENAF2 Mask       */
#define GPIO_PIN_INT_SIENF_SETENAF2_SHIFT        (2U)                                                /*!< GPIO_PIN_INT_SIENF: SETENAF2 Position   */
#define GPIO_PIN_INT_SIENF_SETENAF2(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENF_SETENAF2_SHIFT))&GPIO_PIN_INT_SIENF_SETENAF2_MASK) /*!< GPIO_PIN_INT_SIENF                      */
#define GPIO_PIN_INT_SIENF_SETENAF3_MASK         (0x8U)                                              /*!< GPIO_PIN_INT_SIENF: SETENAF3 Mask       */
#define GPIO_PIN_INT_SIENF_SETENAF3_SHIFT        (3U)                                                /*!< GPIO_PIN_INT_SIENF: SETENAF3 Position   */
#define GPIO_PIN_INT_SIENF_SETENAF3(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENF_SETENAF3_SHIFT))&GPIO_PIN_INT_SIENF_SETENAF3_MASK) /*!< GPIO_PIN_INT_SIENF                      */
#define GPIO_PIN_INT_SIENF_SETENAF4_MASK         (0x10U)                                             /*!< GPIO_PIN_INT_SIENF: SETENAF4 Mask       */
#define GPIO_PIN_INT_SIENF_SETENAF4_SHIFT        (4U)                                                /*!< GPIO_PIN_INT_SIENF: SETENAF4 Position   */
#define GPIO_PIN_INT_SIENF_SETENAF4(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENF_SETENAF4_SHIFT))&GPIO_PIN_INT_SIENF_SETENAF4_MASK) /*!< GPIO_PIN_INT_SIENF                      */
#define GPIO_PIN_INT_SIENF_SETENAF5_MASK         (0x20U)                                             /*!< GPIO_PIN_INT_SIENF: SETENAF5 Mask       */
#define GPIO_PIN_INT_SIENF_SETENAF5_SHIFT        (5U)                                                /*!< GPIO_PIN_INT_SIENF: SETENAF5 Position   */
#define GPIO_PIN_INT_SIENF_SETENAF5(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENF_SETENAF5_SHIFT))&GPIO_PIN_INT_SIENF_SETENAF5_MASK) /*!< GPIO_PIN_INT_SIENF                      */
#define GPIO_PIN_INT_SIENF_SETENAF6_MASK         (0x40U)                                             /*!< GPIO_PIN_INT_SIENF: SETENAF6 Mask       */
#define GPIO_PIN_INT_SIENF_SETENAF6_SHIFT        (6U)                                                /*!< GPIO_PIN_INT_SIENF: SETENAF6 Position   */
#define GPIO_PIN_INT_SIENF_SETENAF6(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENF_SETENAF6_SHIFT))&GPIO_PIN_INT_SIENF_SETENAF6_MASK) /*!< GPIO_PIN_INT_SIENF                      */
#define GPIO_PIN_INT_SIENF_SETENAF7_MASK         (0x80U)                                             /*!< GPIO_PIN_INT_SIENF: SETENAF7 Mask       */
#define GPIO_PIN_INT_SIENF_SETENAF7_SHIFT        (7U)                                                /*!< GPIO_PIN_INT_SIENF: SETENAF7 Position   */
#define GPIO_PIN_INT_SIENF_SETENAF7(x)           (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_SIENF_SETENAF7_SHIFT))&GPIO_PIN_INT_SIENF_SETENAF7_MASK) /*!< GPIO_PIN_INT_SIENF                      */
/* ------- CIENF Bit Fields                         ------ */
#define GPIO_PIN_INT_CIENF_CENAF0_MASK           (0x1U)                                              /*!< GPIO_PIN_INT_CIENF: CENAF0 Mask         */
#define GPIO_PIN_INT_CIENF_CENAF0_SHIFT          (0U)                                                /*!< GPIO_PIN_INT_CIENF: CENAF0 Position     */
#define GPIO_PIN_INT_CIENF_CENAF0(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENF_CENAF0_SHIFT))&GPIO_PIN_INT_CIENF_CENAF0_MASK) /*!< GPIO_PIN_INT_CIENF                      */
#define GPIO_PIN_INT_CIENF_CENAF1_MASK           (0x2U)                                              /*!< GPIO_PIN_INT_CIENF: CENAF1 Mask         */
#define GPIO_PIN_INT_CIENF_CENAF1_SHIFT          (1U)                                                /*!< GPIO_PIN_INT_CIENF: CENAF1 Position     */
#define GPIO_PIN_INT_CIENF_CENAF1(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENF_CENAF1_SHIFT))&GPIO_PIN_INT_CIENF_CENAF1_MASK) /*!< GPIO_PIN_INT_CIENF                      */
#define GPIO_PIN_INT_CIENF_CENAF2_MASK           (0x4U)                                              /*!< GPIO_PIN_INT_CIENF: CENAF2 Mask         */
#define GPIO_PIN_INT_CIENF_CENAF2_SHIFT          (2U)                                                /*!< GPIO_PIN_INT_CIENF: CENAF2 Position     */
#define GPIO_PIN_INT_CIENF_CENAF2(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENF_CENAF2_SHIFT))&GPIO_PIN_INT_CIENF_CENAF2_MASK) /*!< GPIO_PIN_INT_CIENF                      */
#define GPIO_PIN_INT_CIENF_CENAF3_MASK           (0x8U)                                              /*!< GPIO_PIN_INT_CIENF: CENAF3 Mask         */
#define GPIO_PIN_INT_CIENF_CENAF3_SHIFT          (3U)                                                /*!< GPIO_PIN_INT_CIENF: CENAF3 Position     */
#define GPIO_PIN_INT_CIENF_CENAF3(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENF_CENAF3_SHIFT))&GPIO_PIN_INT_CIENF_CENAF3_MASK) /*!< GPIO_PIN_INT_CIENF                      */
#define GPIO_PIN_INT_CIENF_CENAF4_MASK           (0x10U)                                             /*!< GPIO_PIN_INT_CIENF: CENAF4 Mask         */
#define GPIO_PIN_INT_CIENF_CENAF4_SHIFT          (4U)                                                /*!< GPIO_PIN_INT_CIENF: CENAF4 Position     */
#define GPIO_PIN_INT_CIENF_CENAF4(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENF_CENAF4_SHIFT))&GPIO_PIN_INT_CIENF_CENAF4_MASK) /*!< GPIO_PIN_INT_CIENF                      */
#define GPIO_PIN_INT_CIENF_CENAF5_MASK           (0x20U)                                             /*!< GPIO_PIN_INT_CIENF: CENAF5 Mask         */
#define GPIO_PIN_INT_CIENF_CENAF5_SHIFT          (5U)                                                /*!< GPIO_PIN_INT_CIENF: CENAF5 Position     */
#define GPIO_PIN_INT_CIENF_CENAF5(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENF_CENAF5_SHIFT))&GPIO_PIN_INT_CIENF_CENAF5_MASK) /*!< GPIO_PIN_INT_CIENF                      */
#define GPIO_PIN_INT_CIENF_CENAF6_MASK           (0x40U)                                             /*!< GPIO_PIN_INT_CIENF: CENAF6 Mask         */
#define GPIO_PIN_INT_CIENF_CENAF6_SHIFT          (6U)                                                /*!< GPIO_PIN_INT_CIENF: CENAF6 Position     */
#define GPIO_PIN_INT_CIENF_CENAF6(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENF_CENAF6_SHIFT))&GPIO_PIN_INT_CIENF_CENAF6_MASK) /*!< GPIO_PIN_INT_CIENF                      */
#define GPIO_PIN_INT_CIENF_CENAF7_MASK           (0x80U)                                             /*!< GPIO_PIN_INT_CIENF: CENAF7 Mask         */
#define GPIO_PIN_INT_CIENF_CENAF7_SHIFT          (7U)                                                /*!< GPIO_PIN_INT_CIENF: CENAF7 Position     */
#define GPIO_PIN_INT_CIENF_CENAF7(x)             (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_CIENF_CENAF7_SHIFT))&GPIO_PIN_INT_CIENF_CENAF7_MASK) /*!< GPIO_PIN_INT_CIENF                      */
/* ------- RISE Bit Fields                          ------ */
#define GPIO_PIN_INT_RISE_RDET0_MASK             (0x1U)                                              /*!< GPIO_PIN_INT_RISE: RDET0 Mask           */
#define GPIO_PIN_INT_RISE_RDET0_SHIFT            (0U)                                                /*!< GPIO_PIN_INT_RISE: RDET0 Position       */
#define GPIO_PIN_INT_RISE_RDET0(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_RISE_RDET0_SHIFT))&GPIO_PIN_INT_RISE_RDET0_MASK) /*!< GPIO_PIN_INT_RISE                       */
#define GPIO_PIN_INT_RISE_RDET1_MASK             (0x2U)                                              /*!< GPIO_PIN_INT_RISE: RDET1 Mask           */
#define GPIO_PIN_INT_RISE_RDET1_SHIFT            (1U)                                                /*!< GPIO_PIN_INT_RISE: RDET1 Position       */
#define GPIO_PIN_INT_RISE_RDET1(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_RISE_RDET1_SHIFT))&GPIO_PIN_INT_RISE_RDET1_MASK) /*!< GPIO_PIN_INT_RISE                       */
#define GPIO_PIN_INT_RISE_RDET2_MASK             (0x4U)                                              /*!< GPIO_PIN_INT_RISE: RDET2 Mask           */
#define GPIO_PIN_INT_RISE_RDET2_SHIFT            (2U)                                                /*!< GPIO_PIN_INT_RISE: RDET2 Position       */
#define GPIO_PIN_INT_RISE_RDET2(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_RISE_RDET2_SHIFT))&GPIO_PIN_INT_RISE_RDET2_MASK) /*!< GPIO_PIN_INT_RISE                       */
#define GPIO_PIN_INT_RISE_RDET3_MASK             (0x8U)                                              /*!< GPIO_PIN_INT_RISE: RDET3 Mask           */
#define GPIO_PIN_INT_RISE_RDET3_SHIFT            (3U)                                                /*!< GPIO_PIN_INT_RISE: RDET3 Position       */
#define GPIO_PIN_INT_RISE_RDET3(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_RISE_RDET3_SHIFT))&GPIO_PIN_INT_RISE_RDET3_MASK) /*!< GPIO_PIN_INT_RISE                       */
#define GPIO_PIN_INT_RISE_RDET4_MASK             (0x10U)                                             /*!< GPIO_PIN_INT_RISE: RDET4 Mask           */
#define GPIO_PIN_INT_RISE_RDET4_SHIFT            (4U)                                                /*!< GPIO_PIN_INT_RISE: RDET4 Position       */
#define GPIO_PIN_INT_RISE_RDET4(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_RISE_RDET4_SHIFT))&GPIO_PIN_INT_RISE_RDET4_MASK) /*!< GPIO_PIN_INT_RISE                       */
#define GPIO_PIN_INT_RISE_RDET5_MASK             (0x20U)                                             /*!< GPIO_PIN_INT_RISE: RDET5 Mask           */
#define GPIO_PIN_INT_RISE_RDET5_SHIFT            (5U)                                                /*!< GPIO_PIN_INT_RISE: RDET5 Position       */
#define GPIO_PIN_INT_RISE_RDET5(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_RISE_RDET5_SHIFT))&GPIO_PIN_INT_RISE_RDET5_MASK) /*!< GPIO_PIN_INT_RISE                       */
#define GPIO_PIN_INT_RISE_RDET6_MASK             (0x40U)                                             /*!< GPIO_PIN_INT_RISE: RDET6 Mask           */
#define GPIO_PIN_INT_RISE_RDET6_SHIFT            (6U)                                                /*!< GPIO_PIN_INT_RISE: RDET6 Position       */
#define GPIO_PIN_INT_RISE_RDET6(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_RISE_RDET6_SHIFT))&GPIO_PIN_INT_RISE_RDET6_MASK) /*!< GPIO_PIN_INT_RISE                       */
#define GPIO_PIN_INT_RISE_RDET7_MASK             (0x80U)                                             /*!< GPIO_PIN_INT_RISE: RDET7 Mask           */
#define GPIO_PIN_INT_RISE_RDET7_SHIFT            (7U)                                                /*!< GPIO_PIN_INT_RISE: RDET7 Position       */
#define GPIO_PIN_INT_RISE_RDET7(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_RISE_RDET7_SHIFT))&GPIO_PIN_INT_RISE_RDET7_MASK) /*!< GPIO_PIN_INT_RISE                       */
/* ------- FALL Bit Fields                          ------ */
#define GPIO_PIN_INT_FALL_FDET0_MASK             (0x1U)                                              /*!< GPIO_PIN_INT_FALL: FDET0 Mask           */
#define GPIO_PIN_INT_FALL_FDET0_SHIFT            (0U)                                                /*!< GPIO_PIN_INT_FALL: FDET0 Position       */
#define GPIO_PIN_INT_FALL_FDET0(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_FALL_FDET0_SHIFT))&GPIO_PIN_INT_FALL_FDET0_MASK) /*!< GPIO_PIN_INT_FALL                       */
#define GPIO_PIN_INT_FALL_FDET1_MASK             (0x2U)                                              /*!< GPIO_PIN_INT_FALL: FDET1 Mask           */
#define GPIO_PIN_INT_FALL_FDET1_SHIFT            (1U)                                                /*!< GPIO_PIN_INT_FALL: FDET1 Position       */
#define GPIO_PIN_INT_FALL_FDET1(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_FALL_FDET1_SHIFT))&GPIO_PIN_INT_FALL_FDET1_MASK) /*!< GPIO_PIN_INT_FALL                       */
#define GPIO_PIN_INT_FALL_FDET2_MASK             (0x4U)                                              /*!< GPIO_PIN_INT_FALL: FDET2 Mask           */
#define GPIO_PIN_INT_FALL_FDET2_SHIFT            (2U)                                                /*!< GPIO_PIN_INT_FALL: FDET2 Position       */
#define GPIO_PIN_INT_FALL_FDET2(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_FALL_FDET2_SHIFT))&GPIO_PIN_INT_FALL_FDET2_MASK) /*!< GPIO_PIN_INT_FALL                       */
#define GPIO_PIN_INT_FALL_FDET3_MASK             (0x8U)                                              /*!< GPIO_PIN_INT_FALL: FDET3 Mask           */
#define GPIO_PIN_INT_FALL_FDET3_SHIFT            (3U)                                                /*!< GPIO_PIN_INT_FALL: FDET3 Position       */
#define GPIO_PIN_INT_FALL_FDET3(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_FALL_FDET3_SHIFT))&GPIO_PIN_INT_FALL_FDET3_MASK) /*!< GPIO_PIN_INT_FALL                       */
#define GPIO_PIN_INT_FALL_FDET4_MASK             (0x10U)                                             /*!< GPIO_PIN_INT_FALL: FDET4 Mask           */
#define GPIO_PIN_INT_FALL_FDET4_SHIFT            (4U)                                                /*!< GPIO_PIN_INT_FALL: FDET4 Position       */
#define GPIO_PIN_INT_FALL_FDET4(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_FALL_FDET4_SHIFT))&GPIO_PIN_INT_FALL_FDET4_MASK) /*!< GPIO_PIN_INT_FALL                       */
#define GPIO_PIN_INT_FALL_FDET5_MASK             (0x20U)                                             /*!< GPIO_PIN_INT_FALL: FDET5 Mask           */
#define GPIO_PIN_INT_FALL_FDET5_SHIFT            (5U)                                                /*!< GPIO_PIN_INT_FALL: FDET5 Position       */
#define GPIO_PIN_INT_FALL_FDET5(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_FALL_FDET5_SHIFT))&GPIO_PIN_INT_FALL_FDET5_MASK) /*!< GPIO_PIN_INT_FALL                       */
#define GPIO_PIN_INT_FALL_FDET6_MASK             (0x40U)                                             /*!< GPIO_PIN_INT_FALL: FDET6 Mask           */
#define GPIO_PIN_INT_FALL_FDET6_SHIFT            (6U)                                                /*!< GPIO_PIN_INT_FALL: FDET6 Position       */
#define GPIO_PIN_INT_FALL_FDET6(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_FALL_FDET6_SHIFT))&GPIO_PIN_INT_FALL_FDET6_MASK) /*!< GPIO_PIN_INT_FALL                       */
#define GPIO_PIN_INT_FALL_FDET7_MASK             (0x80U)                                             /*!< GPIO_PIN_INT_FALL: FDET7 Mask           */
#define GPIO_PIN_INT_FALL_FDET7_SHIFT            (7U)                                                /*!< GPIO_PIN_INT_FALL: FDET7 Position       */
#define GPIO_PIN_INT_FALL_FDET7(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_FALL_FDET7_SHIFT))&GPIO_PIN_INT_FALL_FDET7_MASK) /*!< GPIO_PIN_INT_FALL                       */
/* ------- IST Bit Fields                           ------ */
#define GPIO_PIN_INT_IST_PSTAT0_MASK             (0x1U)                                              /*!< GPIO_PIN_INT_IST: PSTAT0 Mask           */
#define GPIO_PIN_INT_IST_PSTAT0_SHIFT            (0U)                                                /*!< GPIO_PIN_INT_IST: PSTAT0 Position       */
#define GPIO_PIN_INT_IST_PSTAT0(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IST_PSTAT0_SHIFT))&GPIO_PIN_INT_IST_PSTAT0_MASK) /*!< GPIO_PIN_INT_IST                        */
#define GPIO_PIN_INT_IST_PSTAT1_MASK             (0x2U)                                              /*!< GPIO_PIN_INT_IST: PSTAT1 Mask           */
#define GPIO_PIN_INT_IST_PSTAT1_SHIFT            (1U)                                                /*!< GPIO_PIN_INT_IST: PSTAT1 Position       */
#define GPIO_PIN_INT_IST_PSTAT1(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IST_PSTAT1_SHIFT))&GPIO_PIN_INT_IST_PSTAT1_MASK) /*!< GPIO_PIN_INT_IST                        */
#define GPIO_PIN_INT_IST_PSTAT2_MASK             (0x4U)                                              /*!< GPIO_PIN_INT_IST: PSTAT2 Mask           */
#define GPIO_PIN_INT_IST_PSTAT2_SHIFT            (2U)                                                /*!< GPIO_PIN_INT_IST: PSTAT2 Position       */
#define GPIO_PIN_INT_IST_PSTAT2(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IST_PSTAT2_SHIFT))&GPIO_PIN_INT_IST_PSTAT2_MASK) /*!< GPIO_PIN_INT_IST                        */
#define GPIO_PIN_INT_IST_PSTAT3_MASK             (0x8U)                                              /*!< GPIO_PIN_INT_IST: PSTAT3 Mask           */
#define GPIO_PIN_INT_IST_PSTAT3_SHIFT            (3U)                                                /*!< GPIO_PIN_INT_IST: PSTAT3 Position       */
#define GPIO_PIN_INT_IST_PSTAT3(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IST_PSTAT3_SHIFT))&GPIO_PIN_INT_IST_PSTAT3_MASK) /*!< GPIO_PIN_INT_IST                        */
#define GPIO_PIN_INT_IST_PSTAT4_MASK             (0x10U)                                             /*!< GPIO_PIN_INT_IST: PSTAT4 Mask           */
#define GPIO_PIN_INT_IST_PSTAT4_SHIFT            (4U)                                                /*!< GPIO_PIN_INT_IST: PSTAT4 Position       */
#define GPIO_PIN_INT_IST_PSTAT4(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IST_PSTAT4_SHIFT))&GPIO_PIN_INT_IST_PSTAT4_MASK) /*!< GPIO_PIN_INT_IST                        */
#define GPIO_PIN_INT_IST_PSTAT5_MASK             (0x20U)                                             /*!< GPIO_PIN_INT_IST: PSTAT5 Mask           */
#define GPIO_PIN_INT_IST_PSTAT5_SHIFT            (5U)                                                /*!< GPIO_PIN_INT_IST: PSTAT5 Position       */
#define GPIO_PIN_INT_IST_PSTAT5(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IST_PSTAT5_SHIFT))&GPIO_PIN_INT_IST_PSTAT5_MASK) /*!< GPIO_PIN_INT_IST                        */
#define GPIO_PIN_INT_IST_PSTAT6_MASK             (0x40U)                                             /*!< GPIO_PIN_INT_IST: PSTAT6 Mask           */
#define GPIO_PIN_INT_IST_PSTAT6_SHIFT            (6U)                                                /*!< GPIO_PIN_INT_IST: PSTAT6 Position       */
#define GPIO_PIN_INT_IST_PSTAT6(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IST_PSTAT6_SHIFT))&GPIO_PIN_INT_IST_PSTAT6_MASK) /*!< GPIO_PIN_INT_IST                        */
#define GPIO_PIN_INT_IST_PSTAT7_MASK             (0x80U)                                             /*!< GPIO_PIN_INT_IST: PSTAT7 Mask           */
#define GPIO_PIN_INT_IST_PSTAT7_SHIFT            (7U)                                                /*!< GPIO_PIN_INT_IST: PSTAT7 Position       */
#define GPIO_PIN_INT_IST_PSTAT7(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PIN_INT_IST_PSTAT7_SHIFT))&GPIO_PIN_INT_IST_PSTAT7_MASK) /*!< GPIO_PIN_INT_IST                        */
/**
 * @} */ /* End group GPIO_PIN_INT_Register_Masks_GROUP 
 */

/* GPIO_PIN_INT - Peripheral instance base addresses */
#define GPIO_PIN_INT_BasePtr           0x4004C000UL //!< Peripheral base address
#define GPIO_PIN_INT                   ((GPIO_PIN_INT_Type *) GPIO_PIN_INT_BasePtr) //!< Freescale base pointer
#define GPIO_PIN_INT_BASE_PTR          (GPIO_PIN_INT) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_PIN_INT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_PORT_Peripheral_access_layer_GROUP GPIO_PORT Peripheral Access Layer
* @brief C Struct for GPIO_PORT
* @{
*/

/* ================================================================================ */
/* ================           GPIO_PORT (file:GPIO_PORT_LPC11Uxx)       ================ */
/* ================================================================================ */

/**
 * @brief GPIO port
 */
/**
* @addtogroup GPIO_PORT_structs_GROUP GPIO_PORT struct
* @brief Struct for GPIO_PORT
* @{
*/
typedef struct {                                /*       GPIO_PORT Structure                                          */
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
        uint8_t   RESERVED_0[4032];            
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
        uint8_t   RESERVED_1[3840];            
   __IO uint32_t  DIR[2];                       /**< 2000: Direction registers port                                     */
        uint8_t   RESERVED_2[120];             
   __IO uint32_t  MASK[2];                      /**< 2080: Mask register port %                                         */
        uint8_t   RESERVED_3[120];             
   __IO uint32_t  PIN[2];                       /**< 2100: Portpin register port                                        */
        uint8_t   RESERVED_4[120];             
   __IO uint32_t  MPIN[2];                      /**< 2180: Masked port register port                                    */
        uint8_t   RESERVED_5[120];             
   __IO uint32_t  SET[2];                       /**< 2200: Write: Set register for port,  Read: output bits for port    */
        uint8_t   RESERVED_6[120];             
   __O  uint32_t  CLR[2];                       /**< 2280: Clear port                                                   */
        uint8_t   RESERVED_7[120];             
   __O  uint32_t  NOT[2];                       /**< 2300: Toggle port                                                  */
} GPIO_PORT_Type;

/**
 * @} */ /* End group GPIO_PORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIO_PORT' Position & Mask macros                   ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_PORT_Register_Masks_GROUP GPIO_PORT Register Masks
* @brief Register Masks for GPIO_PORT
* @{
*/
/* ------- B Bit Fields                             ------ */
#define GPIO_PORT_B_PBYTE_MASK                   (0x1U)                                              /*!< GPIO_PORT_B: PBYTE Mask                 */
#define GPIO_PORT_B_PBYTE_SHIFT                  (0U)                                                /*!< GPIO_PORT_B: PBYTE Position             */
#define GPIO_PORT_B_PBYTE(x)                     (((uint8_t)(((uint8_t)(x))<<GPIO_PORT_B_PBYTE_SHIFT))&GPIO_PORT_B_PBYTE_MASK) /*!< GPIO_PORT_B                             */
/* ------- B Bit Fields                             ------ */
/* ------- W Bit Fields                             ------ */
#define GPIO_PORT_W_PWORD_MASK                   (0xFFFFFFFFU)                                       /*!< GPIO_PORT_W: PWORD Mask                 */
#define GPIO_PORT_W_PWORD_SHIFT                  (0U)                                                /*!< GPIO_PORT_W: PWORD Position             */
#define GPIO_PORT_W_PWORD(x)                     (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_W_PWORD_SHIFT))&GPIO_PORT_W_PWORD_MASK) /*!< GPIO_PORT_W                             */
/* ------- W Bit Fields                             ------ */
/* ------- DIR Bit Fields                           ------ */
#define GPIO_PORT_DIR_DIRP0_MASK                 (0x1U)                                              /*!< GPIO_PORT_DIR: DIRP0 Mask               */
#define GPIO_PORT_DIR_DIRP0_SHIFT                (0U)                                                /*!< GPIO_PORT_DIR: DIRP0 Position           */
#define GPIO_PORT_DIR_DIRP0(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP0_SHIFT))&GPIO_PORT_DIR_DIRP0_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP1_MASK                 (0x2U)                                              /*!< GPIO_PORT_DIR: DIRP1 Mask               */
#define GPIO_PORT_DIR_DIRP1_SHIFT                (1U)                                                /*!< GPIO_PORT_DIR: DIRP1 Position           */
#define GPIO_PORT_DIR_DIRP1(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP1_SHIFT))&GPIO_PORT_DIR_DIRP1_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP2_MASK                 (0x4U)                                              /*!< GPIO_PORT_DIR: DIRP2 Mask               */
#define GPIO_PORT_DIR_DIRP2_SHIFT                (2U)                                                /*!< GPIO_PORT_DIR: DIRP2 Position           */
#define GPIO_PORT_DIR_DIRP2(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP2_SHIFT))&GPIO_PORT_DIR_DIRP2_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP3_MASK                 (0x8U)                                              /*!< GPIO_PORT_DIR: DIRP3 Mask               */
#define GPIO_PORT_DIR_DIRP3_SHIFT                (3U)                                                /*!< GPIO_PORT_DIR: DIRP3 Position           */
#define GPIO_PORT_DIR_DIRP3(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP3_SHIFT))&GPIO_PORT_DIR_DIRP3_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP4_MASK                 (0x10U)                                             /*!< GPIO_PORT_DIR: DIRP4 Mask               */
#define GPIO_PORT_DIR_DIRP4_SHIFT                (4U)                                                /*!< GPIO_PORT_DIR: DIRP4 Position           */
#define GPIO_PORT_DIR_DIRP4(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP4_SHIFT))&GPIO_PORT_DIR_DIRP4_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP5_MASK                 (0x20U)                                             /*!< GPIO_PORT_DIR: DIRP5 Mask               */
#define GPIO_PORT_DIR_DIRP5_SHIFT                (5U)                                                /*!< GPIO_PORT_DIR: DIRP5 Position           */
#define GPIO_PORT_DIR_DIRP5(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP5_SHIFT))&GPIO_PORT_DIR_DIRP5_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP6_MASK                 (0x40U)                                             /*!< GPIO_PORT_DIR: DIRP6 Mask               */
#define GPIO_PORT_DIR_DIRP6_SHIFT                (6U)                                                /*!< GPIO_PORT_DIR: DIRP6 Position           */
#define GPIO_PORT_DIR_DIRP6(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP6_SHIFT))&GPIO_PORT_DIR_DIRP6_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP7_MASK                 (0x80U)                                             /*!< GPIO_PORT_DIR: DIRP7 Mask               */
#define GPIO_PORT_DIR_DIRP7_SHIFT                (7U)                                                /*!< GPIO_PORT_DIR: DIRP7 Position           */
#define GPIO_PORT_DIR_DIRP7(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP7_SHIFT))&GPIO_PORT_DIR_DIRP7_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP8_MASK                 (0x100U)                                            /*!< GPIO_PORT_DIR: DIRP8 Mask               */
#define GPIO_PORT_DIR_DIRP8_SHIFT                (8U)                                                /*!< GPIO_PORT_DIR: DIRP8 Position           */
#define GPIO_PORT_DIR_DIRP8(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP8_SHIFT))&GPIO_PORT_DIR_DIRP8_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP9_MASK                 (0x200U)                                            /*!< GPIO_PORT_DIR: DIRP9 Mask               */
#define GPIO_PORT_DIR_DIRP9_SHIFT                (9U)                                                /*!< GPIO_PORT_DIR: DIRP9 Position           */
#define GPIO_PORT_DIR_DIRP9(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP9_SHIFT))&GPIO_PORT_DIR_DIRP9_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP10_MASK                (0x400U)                                            /*!< GPIO_PORT_DIR: DIRP10 Mask              */
#define GPIO_PORT_DIR_DIRP10_SHIFT               (10U)                                               /*!< GPIO_PORT_DIR: DIRP10 Position          */
#define GPIO_PORT_DIR_DIRP10(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP10_SHIFT))&GPIO_PORT_DIR_DIRP10_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP11_MASK                (0x800U)                                            /*!< GPIO_PORT_DIR: DIRP11 Mask              */
#define GPIO_PORT_DIR_DIRP11_SHIFT               (11U)                                               /*!< GPIO_PORT_DIR: DIRP11 Position          */
#define GPIO_PORT_DIR_DIRP11(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP11_SHIFT))&GPIO_PORT_DIR_DIRP11_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP12_MASK                (0x1000U)                                           /*!< GPIO_PORT_DIR: DIRP12 Mask              */
#define GPIO_PORT_DIR_DIRP12_SHIFT               (12U)                                               /*!< GPIO_PORT_DIR: DIRP12 Position          */
#define GPIO_PORT_DIR_DIRP12(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP12_SHIFT))&GPIO_PORT_DIR_DIRP12_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP13_MASK                (0x2000U)                                           /*!< GPIO_PORT_DIR: DIRP13 Mask              */
#define GPIO_PORT_DIR_DIRP13_SHIFT               (13U)                                               /*!< GPIO_PORT_DIR: DIRP13 Position          */
#define GPIO_PORT_DIR_DIRP13(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP13_SHIFT))&GPIO_PORT_DIR_DIRP13_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP14_MASK                (0x4000U)                                           /*!< GPIO_PORT_DIR: DIRP14 Mask              */
#define GPIO_PORT_DIR_DIRP14_SHIFT               (14U)                                               /*!< GPIO_PORT_DIR: DIRP14 Position          */
#define GPIO_PORT_DIR_DIRP14(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP14_SHIFT))&GPIO_PORT_DIR_DIRP14_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP15_MASK                (0x8000U)                                           /*!< GPIO_PORT_DIR: DIRP15 Mask              */
#define GPIO_PORT_DIR_DIRP15_SHIFT               (15U)                                               /*!< GPIO_PORT_DIR: DIRP15 Position          */
#define GPIO_PORT_DIR_DIRP15(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP15_SHIFT))&GPIO_PORT_DIR_DIRP15_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP16_MASK                (0x10000U)                                          /*!< GPIO_PORT_DIR: DIRP16 Mask              */
#define GPIO_PORT_DIR_DIRP16_SHIFT               (16U)                                               /*!< GPIO_PORT_DIR: DIRP16 Position          */
#define GPIO_PORT_DIR_DIRP16(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP16_SHIFT))&GPIO_PORT_DIR_DIRP16_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP17_MASK                (0x20000U)                                          /*!< GPIO_PORT_DIR: DIRP17 Mask              */
#define GPIO_PORT_DIR_DIRP17_SHIFT               (17U)                                               /*!< GPIO_PORT_DIR: DIRP17 Position          */
#define GPIO_PORT_DIR_DIRP17(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP17_SHIFT))&GPIO_PORT_DIR_DIRP17_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP18_MASK                (0x40000U)                                          /*!< GPIO_PORT_DIR: DIRP18 Mask              */
#define GPIO_PORT_DIR_DIRP18_SHIFT               (18U)                                               /*!< GPIO_PORT_DIR: DIRP18 Position          */
#define GPIO_PORT_DIR_DIRP18(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP18_SHIFT))&GPIO_PORT_DIR_DIRP18_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP19_MASK                (0x80000U)                                          /*!< GPIO_PORT_DIR: DIRP19 Mask              */
#define GPIO_PORT_DIR_DIRP19_SHIFT               (19U)                                               /*!< GPIO_PORT_DIR: DIRP19 Position          */
#define GPIO_PORT_DIR_DIRP19(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP19_SHIFT))&GPIO_PORT_DIR_DIRP19_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP20_MASK                (0x100000U)                                         /*!< GPIO_PORT_DIR: DIRP20 Mask              */
#define GPIO_PORT_DIR_DIRP20_SHIFT               (20U)                                               /*!< GPIO_PORT_DIR: DIRP20 Position          */
#define GPIO_PORT_DIR_DIRP20(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP20_SHIFT))&GPIO_PORT_DIR_DIRP20_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP21_MASK                (0x200000U)                                         /*!< GPIO_PORT_DIR: DIRP21 Mask              */
#define GPIO_PORT_DIR_DIRP21_SHIFT               (21U)                                               /*!< GPIO_PORT_DIR: DIRP21 Position          */
#define GPIO_PORT_DIR_DIRP21(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP21_SHIFT))&GPIO_PORT_DIR_DIRP21_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP22_MASK                (0x400000U)                                         /*!< GPIO_PORT_DIR: DIRP22 Mask              */
#define GPIO_PORT_DIR_DIRP22_SHIFT               (22U)                                               /*!< GPIO_PORT_DIR: DIRP22 Position          */
#define GPIO_PORT_DIR_DIRP22(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP22_SHIFT))&GPIO_PORT_DIR_DIRP22_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP23_MASK                (0x800000U)                                         /*!< GPIO_PORT_DIR: DIRP23 Mask              */
#define GPIO_PORT_DIR_DIRP23_SHIFT               (23U)                                               /*!< GPIO_PORT_DIR: DIRP23 Position          */
#define GPIO_PORT_DIR_DIRP23(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP23_SHIFT))&GPIO_PORT_DIR_DIRP23_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP24_MASK                (0x1000000U)                                        /*!< GPIO_PORT_DIR: DIRP24 Mask              */
#define GPIO_PORT_DIR_DIRP24_SHIFT               (24U)                                               /*!< GPIO_PORT_DIR: DIRP24 Position          */
#define GPIO_PORT_DIR_DIRP24(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP24_SHIFT))&GPIO_PORT_DIR_DIRP24_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP25_MASK                (0x2000000U)                                        /*!< GPIO_PORT_DIR: DIRP25 Mask              */
#define GPIO_PORT_DIR_DIRP25_SHIFT               (25U)                                               /*!< GPIO_PORT_DIR: DIRP25 Position          */
#define GPIO_PORT_DIR_DIRP25(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP25_SHIFT))&GPIO_PORT_DIR_DIRP25_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP26_MASK                (0x4000000U)                                        /*!< GPIO_PORT_DIR: DIRP26 Mask              */
#define GPIO_PORT_DIR_DIRP26_SHIFT               (26U)                                               /*!< GPIO_PORT_DIR: DIRP26 Position          */
#define GPIO_PORT_DIR_DIRP26(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP26_SHIFT))&GPIO_PORT_DIR_DIRP26_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP27_MASK                (0x8000000U)                                        /*!< GPIO_PORT_DIR: DIRP27 Mask              */
#define GPIO_PORT_DIR_DIRP27_SHIFT               (27U)                                               /*!< GPIO_PORT_DIR: DIRP27 Position          */
#define GPIO_PORT_DIR_DIRP27(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP27_SHIFT))&GPIO_PORT_DIR_DIRP27_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP28_MASK                (0x10000000U)                                       /*!< GPIO_PORT_DIR: DIRP28 Mask              */
#define GPIO_PORT_DIR_DIRP28_SHIFT               (28U)                                               /*!< GPIO_PORT_DIR: DIRP28 Position          */
#define GPIO_PORT_DIR_DIRP28(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP28_SHIFT))&GPIO_PORT_DIR_DIRP28_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP29_MASK                (0x20000000U)                                       /*!< GPIO_PORT_DIR: DIRP29 Mask              */
#define GPIO_PORT_DIR_DIRP29_SHIFT               (29U)                                               /*!< GPIO_PORT_DIR: DIRP29 Position          */
#define GPIO_PORT_DIR_DIRP29(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP29_SHIFT))&GPIO_PORT_DIR_DIRP29_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP30_MASK                (0x40000000U)                                       /*!< GPIO_PORT_DIR: DIRP30 Mask              */
#define GPIO_PORT_DIR_DIRP30_SHIFT               (30U)                                               /*!< GPIO_PORT_DIR: DIRP30 Position          */
#define GPIO_PORT_DIR_DIRP30(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP30_SHIFT))&GPIO_PORT_DIR_DIRP30_MASK) /*!< GPIO_PORT_DIR                           */
#define GPIO_PORT_DIR_DIRP31_MASK                (0x80000000U)                                       /*!< GPIO_PORT_DIR: DIRP31 Mask              */
#define GPIO_PORT_DIR_DIRP31_SHIFT               (31U)                                               /*!< GPIO_PORT_DIR: DIRP31 Position          */
#define GPIO_PORT_DIR_DIRP31(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_DIR_DIRP31_SHIFT))&GPIO_PORT_DIR_DIRP31_MASK) /*!< GPIO_PORT_DIR                           */
/* ------- MASK Bit Fields                          ------ */
#define GPIO_PORT_MASK_MASKP0_MASK               (0x1U)                                              /*!< GPIO_PORT_MASK: MASKP0 Mask             */
#define GPIO_PORT_MASK_MASKP0_SHIFT              (0U)                                                /*!< GPIO_PORT_MASK: MASKP0 Position         */
#define GPIO_PORT_MASK_MASKP0(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP0_SHIFT))&GPIO_PORT_MASK_MASKP0_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP1_MASK               (0x2U)                                              /*!< GPIO_PORT_MASK: MASKP1 Mask             */
#define GPIO_PORT_MASK_MASKP1_SHIFT              (1U)                                                /*!< GPIO_PORT_MASK: MASKP1 Position         */
#define GPIO_PORT_MASK_MASKP1(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP1_SHIFT))&GPIO_PORT_MASK_MASKP1_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP2_MASK               (0x4U)                                              /*!< GPIO_PORT_MASK: MASKP2 Mask             */
#define GPIO_PORT_MASK_MASKP2_SHIFT              (2U)                                                /*!< GPIO_PORT_MASK: MASKP2 Position         */
#define GPIO_PORT_MASK_MASKP2(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP2_SHIFT))&GPIO_PORT_MASK_MASKP2_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP3_MASK               (0x8U)                                              /*!< GPIO_PORT_MASK: MASKP3 Mask             */
#define GPIO_PORT_MASK_MASKP3_SHIFT              (3U)                                                /*!< GPIO_PORT_MASK: MASKP3 Position         */
#define GPIO_PORT_MASK_MASKP3(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP3_SHIFT))&GPIO_PORT_MASK_MASKP3_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP4_MASK               (0x10U)                                             /*!< GPIO_PORT_MASK: MASKP4 Mask             */
#define GPIO_PORT_MASK_MASKP4_SHIFT              (4U)                                                /*!< GPIO_PORT_MASK: MASKP4 Position         */
#define GPIO_PORT_MASK_MASKP4(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP4_SHIFT))&GPIO_PORT_MASK_MASKP4_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP5_MASK               (0x20U)                                             /*!< GPIO_PORT_MASK: MASKP5 Mask             */
#define GPIO_PORT_MASK_MASKP5_SHIFT              (5U)                                                /*!< GPIO_PORT_MASK: MASKP5 Position         */
#define GPIO_PORT_MASK_MASKP5(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP5_SHIFT))&GPIO_PORT_MASK_MASKP5_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP6_MASK               (0x40U)                                             /*!< GPIO_PORT_MASK: MASKP6 Mask             */
#define GPIO_PORT_MASK_MASKP6_SHIFT              (6U)                                                /*!< GPIO_PORT_MASK: MASKP6 Position         */
#define GPIO_PORT_MASK_MASKP6(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP6_SHIFT))&GPIO_PORT_MASK_MASKP6_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP7_MASK               (0x80U)                                             /*!< GPIO_PORT_MASK: MASKP7 Mask             */
#define GPIO_PORT_MASK_MASKP7_SHIFT              (7U)                                                /*!< GPIO_PORT_MASK: MASKP7 Position         */
#define GPIO_PORT_MASK_MASKP7(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP7_SHIFT))&GPIO_PORT_MASK_MASKP7_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP8_MASK               (0x100U)                                            /*!< GPIO_PORT_MASK: MASKP8 Mask             */
#define GPIO_PORT_MASK_MASKP8_SHIFT              (8U)                                                /*!< GPIO_PORT_MASK: MASKP8 Position         */
#define GPIO_PORT_MASK_MASKP8(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP8_SHIFT))&GPIO_PORT_MASK_MASKP8_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP9_MASK               (0x200U)                                            /*!< GPIO_PORT_MASK: MASKP9 Mask             */
#define GPIO_PORT_MASK_MASKP9_SHIFT              (9U)                                                /*!< GPIO_PORT_MASK: MASKP9 Position         */
#define GPIO_PORT_MASK_MASKP9(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP9_SHIFT))&GPIO_PORT_MASK_MASKP9_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP10_MASK              (0x400U)                                            /*!< GPIO_PORT_MASK: MASKP10 Mask            */
#define GPIO_PORT_MASK_MASKP10_SHIFT             (10U)                                               /*!< GPIO_PORT_MASK: MASKP10 Position        */
#define GPIO_PORT_MASK_MASKP10(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP10_SHIFT))&GPIO_PORT_MASK_MASKP10_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP11_MASK              (0x800U)                                            /*!< GPIO_PORT_MASK: MASKP11 Mask            */
#define GPIO_PORT_MASK_MASKP11_SHIFT             (11U)                                               /*!< GPIO_PORT_MASK: MASKP11 Position        */
#define GPIO_PORT_MASK_MASKP11(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP11_SHIFT))&GPIO_PORT_MASK_MASKP11_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP12_MASK              (0x1000U)                                           /*!< GPIO_PORT_MASK: MASKP12 Mask            */
#define GPIO_PORT_MASK_MASKP12_SHIFT             (12U)                                               /*!< GPIO_PORT_MASK: MASKP12 Position        */
#define GPIO_PORT_MASK_MASKP12(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP12_SHIFT))&GPIO_PORT_MASK_MASKP12_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP13_MASK              (0x2000U)                                           /*!< GPIO_PORT_MASK: MASKP13 Mask            */
#define GPIO_PORT_MASK_MASKP13_SHIFT             (13U)                                               /*!< GPIO_PORT_MASK: MASKP13 Position        */
#define GPIO_PORT_MASK_MASKP13(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP13_SHIFT))&GPIO_PORT_MASK_MASKP13_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP14_MASK              (0x4000U)                                           /*!< GPIO_PORT_MASK: MASKP14 Mask            */
#define GPIO_PORT_MASK_MASKP14_SHIFT             (14U)                                               /*!< GPIO_PORT_MASK: MASKP14 Position        */
#define GPIO_PORT_MASK_MASKP14(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP14_SHIFT))&GPIO_PORT_MASK_MASKP14_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP15_MASK              (0x8000U)                                           /*!< GPIO_PORT_MASK: MASKP15 Mask            */
#define GPIO_PORT_MASK_MASKP15_SHIFT             (15U)                                               /*!< GPIO_PORT_MASK: MASKP15 Position        */
#define GPIO_PORT_MASK_MASKP15(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP15_SHIFT))&GPIO_PORT_MASK_MASKP15_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP16_MASK              (0x10000U)                                          /*!< GPIO_PORT_MASK: MASKP16 Mask            */
#define GPIO_PORT_MASK_MASKP16_SHIFT             (16U)                                               /*!< GPIO_PORT_MASK: MASKP16 Position        */
#define GPIO_PORT_MASK_MASKP16(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP16_SHIFT))&GPIO_PORT_MASK_MASKP16_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP17_MASK              (0x20000U)                                          /*!< GPIO_PORT_MASK: MASKP17 Mask            */
#define GPIO_PORT_MASK_MASKP17_SHIFT             (17U)                                               /*!< GPIO_PORT_MASK: MASKP17 Position        */
#define GPIO_PORT_MASK_MASKP17(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP17_SHIFT))&GPIO_PORT_MASK_MASKP17_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP18_MASK              (0x40000U)                                          /*!< GPIO_PORT_MASK: MASKP18 Mask            */
#define GPIO_PORT_MASK_MASKP18_SHIFT             (18U)                                               /*!< GPIO_PORT_MASK: MASKP18 Position        */
#define GPIO_PORT_MASK_MASKP18(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP18_SHIFT))&GPIO_PORT_MASK_MASKP18_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP19_MASK              (0x80000U)                                          /*!< GPIO_PORT_MASK: MASKP19 Mask            */
#define GPIO_PORT_MASK_MASKP19_SHIFT             (19U)                                               /*!< GPIO_PORT_MASK: MASKP19 Position        */
#define GPIO_PORT_MASK_MASKP19(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP19_SHIFT))&GPIO_PORT_MASK_MASKP19_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP20_MASK              (0x100000U)                                         /*!< GPIO_PORT_MASK: MASKP20 Mask            */
#define GPIO_PORT_MASK_MASKP20_SHIFT             (20U)                                               /*!< GPIO_PORT_MASK: MASKP20 Position        */
#define GPIO_PORT_MASK_MASKP20(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP20_SHIFT))&GPIO_PORT_MASK_MASKP20_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP21_MASK              (0x200000U)                                         /*!< GPIO_PORT_MASK: MASKP21 Mask            */
#define GPIO_PORT_MASK_MASKP21_SHIFT             (21U)                                               /*!< GPIO_PORT_MASK: MASKP21 Position        */
#define GPIO_PORT_MASK_MASKP21(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP21_SHIFT))&GPIO_PORT_MASK_MASKP21_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP22_MASK              (0x400000U)                                         /*!< GPIO_PORT_MASK: MASKP22 Mask            */
#define GPIO_PORT_MASK_MASKP22_SHIFT             (22U)                                               /*!< GPIO_PORT_MASK: MASKP22 Position        */
#define GPIO_PORT_MASK_MASKP22(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP22_SHIFT))&GPIO_PORT_MASK_MASKP22_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP23_MASK              (0x800000U)                                         /*!< GPIO_PORT_MASK: MASKP23 Mask            */
#define GPIO_PORT_MASK_MASKP23_SHIFT             (23U)                                               /*!< GPIO_PORT_MASK: MASKP23 Position        */
#define GPIO_PORT_MASK_MASKP23(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP23_SHIFT))&GPIO_PORT_MASK_MASKP23_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP24_MASK              (0x1000000U)                                        /*!< GPIO_PORT_MASK: MASKP24 Mask            */
#define GPIO_PORT_MASK_MASKP24_SHIFT             (24U)                                               /*!< GPIO_PORT_MASK: MASKP24 Position        */
#define GPIO_PORT_MASK_MASKP24(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP24_SHIFT))&GPIO_PORT_MASK_MASKP24_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP25_MASK              (0x2000000U)                                        /*!< GPIO_PORT_MASK: MASKP25 Mask            */
#define GPIO_PORT_MASK_MASKP25_SHIFT             (25U)                                               /*!< GPIO_PORT_MASK: MASKP25 Position        */
#define GPIO_PORT_MASK_MASKP25(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP25_SHIFT))&GPIO_PORT_MASK_MASKP25_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP26_MASK              (0x4000000U)                                        /*!< GPIO_PORT_MASK: MASKP26 Mask            */
#define GPIO_PORT_MASK_MASKP26_SHIFT             (26U)                                               /*!< GPIO_PORT_MASK: MASKP26 Position        */
#define GPIO_PORT_MASK_MASKP26(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP26_SHIFT))&GPIO_PORT_MASK_MASKP26_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP27_MASK              (0x8000000U)                                        /*!< GPIO_PORT_MASK: MASKP27 Mask            */
#define GPIO_PORT_MASK_MASKP27_SHIFT             (27U)                                               /*!< GPIO_PORT_MASK: MASKP27 Position        */
#define GPIO_PORT_MASK_MASKP27(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP27_SHIFT))&GPIO_PORT_MASK_MASKP27_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP28_MASK              (0x10000000U)                                       /*!< GPIO_PORT_MASK: MASKP28 Mask            */
#define GPIO_PORT_MASK_MASKP28_SHIFT             (28U)                                               /*!< GPIO_PORT_MASK: MASKP28 Position        */
#define GPIO_PORT_MASK_MASKP28(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP28_SHIFT))&GPIO_PORT_MASK_MASKP28_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP29_MASK              (0x20000000U)                                       /*!< GPIO_PORT_MASK: MASKP29 Mask            */
#define GPIO_PORT_MASK_MASKP29_SHIFT             (29U)                                               /*!< GPIO_PORT_MASK: MASKP29 Position        */
#define GPIO_PORT_MASK_MASKP29(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP29_SHIFT))&GPIO_PORT_MASK_MASKP29_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP30_MASK              (0x40000000U)                                       /*!< GPIO_PORT_MASK: MASKP30 Mask            */
#define GPIO_PORT_MASK_MASKP30_SHIFT             (30U)                                               /*!< GPIO_PORT_MASK: MASKP30 Position        */
#define GPIO_PORT_MASK_MASKP30(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP30_SHIFT))&GPIO_PORT_MASK_MASKP30_MASK) /*!< GPIO_PORT_MASK                          */
#define GPIO_PORT_MASK_MASKP31_MASK              (0x80000000U)                                       /*!< GPIO_PORT_MASK: MASKP31 Mask            */
#define GPIO_PORT_MASK_MASKP31_SHIFT             (31U)                                               /*!< GPIO_PORT_MASK: MASKP31 Position        */
#define GPIO_PORT_MASK_MASKP31(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MASK_MASKP31_SHIFT))&GPIO_PORT_MASK_MASKP31_MASK) /*!< GPIO_PORT_MASK                          */
/* ------- PIN Bit Fields                           ------ */
#define GPIO_PORT_PIN_PORT0_MASK                 (0x1U)                                              /*!< GPIO_PORT_PIN: PORT0 Mask               */
#define GPIO_PORT_PIN_PORT0_SHIFT                (0U)                                                /*!< GPIO_PORT_PIN: PORT0 Position           */
#define GPIO_PORT_PIN_PORT0(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT0_SHIFT))&GPIO_PORT_PIN_PORT0_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT1_MASK                 (0x2U)                                              /*!< GPIO_PORT_PIN: PORT1 Mask               */
#define GPIO_PORT_PIN_PORT1_SHIFT                (1U)                                                /*!< GPIO_PORT_PIN: PORT1 Position           */
#define GPIO_PORT_PIN_PORT1(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT1_SHIFT))&GPIO_PORT_PIN_PORT1_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT2_MASK                 (0x4U)                                              /*!< GPIO_PORT_PIN: PORT2 Mask               */
#define GPIO_PORT_PIN_PORT2_SHIFT                (2U)                                                /*!< GPIO_PORT_PIN: PORT2 Position           */
#define GPIO_PORT_PIN_PORT2(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT2_SHIFT))&GPIO_PORT_PIN_PORT2_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT3_MASK                 (0x8U)                                              /*!< GPIO_PORT_PIN: PORT3 Mask               */
#define GPIO_PORT_PIN_PORT3_SHIFT                (3U)                                                /*!< GPIO_PORT_PIN: PORT3 Position           */
#define GPIO_PORT_PIN_PORT3(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT3_SHIFT))&GPIO_PORT_PIN_PORT3_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT4_MASK                 (0x10U)                                             /*!< GPIO_PORT_PIN: PORT4 Mask               */
#define GPIO_PORT_PIN_PORT4_SHIFT                (4U)                                                /*!< GPIO_PORT_PIN: PORT4 Position           */
#define GPIO_PORT_PIN_PORT4(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT4_SHIFT))&GPIO_PORT_PIN_PORT4_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT5_MASK                 (0x20U)                                             /*!< GPIO_PORT_PIN: PORT5 Mask               */
#define GPIO_PORT_PIN_PORT5_SHIFT                (5U)                                                /*!< GPIO_PORT_PIN: PORT5 Position           */
#define GPIO_PORT_PIN_PORT5(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT5_SHIFT))&GPIO_PORT_PIN_PORT5_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT6_MASK                 (0x40U)                                             /*!< GPIO_PORT_PIN: PORT6 Mask               */
#define GPIO_PORT_PIN_PORT6_SHIFT                (6U)                                                /*!< GPIO_PORT_PIN: PORT6 Position           */
#define GPIO_PORT_PIN_PORT6(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT6_SHIFT))&GPIO_PORT_PIN_PORT6_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT7_MASK                 (0x80U)                                             /*!< GPIO_PORT_PIN: PORT7 Mask               */
#define GPIO_PORT_PIN_PORT7_SHIFT                (7U)                                                /*!< GPIO_PORT_PIN: PORT7 Position           */
#define GPIO_PORT_PIN_PORT7(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT7_SHIFT))&GPIO_PORT_PIN_PORT7_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT8_MASK                 (0x100U)                                            /*!< GPIO_PORT_PIN: PORT8 Mask               */
#define GPIO_PORT_PIN_PORT8_SHIFT                (8U)                                                /*!< GPIO_PORT_PIN: PORT8 Position           */
#define GPIO_PORT_PIN_PORT8(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT8_SHIFT))&GPIO_PORT_PIN_PORT8_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT9_MASK                 (0x200U)                                            /*!< GPIO_PORT_PIN: PORT9 Mask               */
#define GPIO_PORT_PIN_PORT9_SHIFT                (9U)                                                /*!< GPIO_PORT_PIN: PORT9 Position           */
#define GPIO_PORT_PIN_PORT9(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT9_SHIFT))&GPIO_PORT_PIN_PORT9_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT10_MASK                (0x400U)                                            /*!< GPIO_PORT_PIN: PORT10 Mask              */
#define GPIO_PORT_PIN_PORT10_SHIFT               (10U)                                               /*!< GPIO_PORT_PIN: PORT10 Position          */
#define GPIO_PORT_PIN_PORT10(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT10_SHIFT))&GPIO_PORT_PIN_PORT10_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT11_MASK                (0x800U)                                            /*!< GPIO_PORT_PIN: PORT11 Mask              */
#define GPIO_PORT_PIN_PORT11_SHIFT               (11U)                                               /*!< GPIO_PORT_PIN: PORT11 Position          */
#define GPIO_PORT_PIN_PORT11(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT11_SHIFT))&GPIO_PORT_PIN_PORT11_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT12_MASK                (0x1000U)                                           /*!< GPIO_PORT_PIN: PORT12 Mask              */
#define GPIO_PORT_PIN_PORT12_SHIFT               (12U)                                               /*!< GPIO_PORT_PIN: PORT12 Position          */
#define GPIO_PORT_PIN_PORT12(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT12_SHIFT))&GPIO_PORT_PIN_PORT12_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT13_MASK                (0x2000U)                                           /*!< GPIO_PORT_PIN: PORT13 Mask              */
#define GPIO_PORT_PIN_PORT13_SHIFT               (13U)                                               /*!< GPIO_PORT_PIN: PORT13 Position          */
#define GPIO_PORT_PIN_PORT13(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT13_SHIFT))&GPIO_PORT_PIN_PORT13_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT14_MASK                (0x4000U)                                           /*!< GPIO_PORT_PIN: PORT14 Mask              */
#define GPIO_PORT_PIN_PORT14_SHIFT               (14U)                                               /*!< GPIO_PORT_PIN: PORT14 Position          */
#define GPIO_PORT_PIN_PORT14(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT14_SHIFT))&GPIO_PORT_PIN_PORT14_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT15_MASK                (0x8000U)                                           /*!< GPIO_PORT_PIN: PORT15 Mask              */
#define GPIO_PORT_PIN_PORT15_SHIFT               (15U)                                               /*!< GPIO_PORT_PIN: PORT15 Position          */
#define GPIO_PORT_PIN_PORT15(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT15_SHIFT))&GPIO_PORT_PIN_PORT15_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT16_MASK                (0x10000U)                                          /*!< GPIO_PORT_PIN: PORT16 Mask              */
#define GPIO_PORT_PIN_PORT16_SHIFT               (16U)                                               /*!< GPIO_PORT_PIN: PORT16 Position          */
#define GPIO_PORT_PIN_PORT16(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT16_SHIFT))&GPIO_PORT_PIN_PORT16_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT17_MASK                (0x20000U)                                          /*!< GPIO_PORT_PIN: PORT17 Mask              */
#define GPIO_PORT_PIN_PORT17_SHIFT               (17U)                                               /*!< GPIO_PORT_PIN: PORT17 Position          */
#define GPIO_PORT_PIN_PORT17(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT17_SHIFT))&GPIO_PORT_PIN_PORT17_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT18_MASK                (0x40000U)                                          /*!< GPIO_PORT_PIN: PORT18 Mask              */
#define GPIO_PORT_PIN_PORT18_SHIFT               (18U)                                               /*!< GPIO_PORT_PIN: PORT18 Position          */
#define GPIO_PORT_PIN_PORT18(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT18_SHIFT))&GPIO_PORT_PIN_PORT18_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT19_MASK                (0x80000U)                                          /*!< GPIO_PORT_PIN: PORT19 Mask              */
#define GPIO_PORT_PIN_PORT19_SHIFT               (19U)                                               /*!< GPIO_PORT_PIN: PORT19 Position          */
#define GPIO_PORT_PIN_PORT19(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT19_SHIFT))&GPIO_PORT_PIN_PORT19_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT20_MASK                (0x100000U)                                         /*!< GPIO_PORT_PIN: PORT20 Mask              */
#define GPIO_PORT_PIN_PORT20_SHIFT               (20U)                                               /*!< GPIO_PORT_PIN: PORT20 Position          */
#define GPIO_PORT_PIN_PORT20(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT20_SHIFT))&GPIO_PORT_PIN_PORT20_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT21_MASK                (0x200000U)                                         /*!< GPIO_PORT_PIN: PORT21 Mask              */
#define GPIO_PORT_PIN_PORT21_SHIFT               (21U)                                               /*!< GPIO_PORT_PIN: PORT21 Position          */
#define GPIO_PORT_PIN_PORT21(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT21_SHIFT))&GPIO_PORT_PIN_PORT21_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT22_MASK                (0x400000U)                                         /*!< GPIO_PORT_PIN: PORT22 Mask              */
#define GPIO_PORT_PIN_PORT22_SHIFT               (22U)                                               /*!< GPIO_PORT_PIN: PORT22 Position          */
#define GPIO_PORT_PIN_PORT22(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT22_SHIFT))&GPIO_PORT_PIN_PORT22_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT23_MASK                (0x800000U)                                         /*!< GPIO_PORT_PIN: PORT23 Mask              */
#define GPIO_PORT_PIN_PORT23_SHIFT               (23U)                                               /*!< GPIO_PORT_PIN: PORT23 Position          */
#define GPIO_PORT_PIN_PORT23(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT23_SHIFT))&GPIO_PORT_PIN_PORT23_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT24_MASK                (0x1000000U)                                        /*!< GPIO_PORT_PIN: PORT24 Mask              */
#define GPIO_PORT_PIN_PORT24_SHIFT               (24U)                                               /*!< GPIO_PORT_PIN: PORT24 Position          */
#define GPIO_PORT_PIN_PORT24(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT24_SHIFT))&GPIO_PORT_PIN_PORT24_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT25_MASK                (0x2000000U)                                        /*!< GPIO_PORT_PIN: PORT25 Mask              */
#define GPIO_PORT_PIN_PORT25_SHIFT               (25U)                                               /*!< GPIO_PORT_PIN: PORT25 Position          */
#define GPIO_PORT_PIN_PORT25(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT25_SHIFT))&GPIO_PORT_PIN_PORT25_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT26_MASK                (0x4000000U)                                        /*!< GPIO_PORT_PIN: PORT26 Mask              */
#define GPIO_PORT_PIN_PORT26_SHIFT               (26U)                                               /*!< GPIO_PORT_PIN: PORT26 Position          */
#define GPIO_PORT_PIN_PORT26(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT26_SHIFT))&GPIO_PORT_PIN_PORT26_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT27_MASK                (0x8000000U)                                        /*!< GPIO_PORT_PIN: PORT27 Mask              */
#define GPIO_PORT_PIN_PORT27_SHIFT               (27U)                                               /*!< GPIO_PORT_PIN: PORT27 Position          */
#define GPIO_PORT_PIN_PORT27(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT27_SHIFT))&GPIO_PORT_PIN_PORT27_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT28_MASK                (0x10000000U)                                       /*!< GPIO_PORT_PIN: PORT28 Mask              */
#define GPIO_PORT_PIN_PORT28_SHIFT               (28U)                                               /*!< GPIO_PORT_PIN: PORT28 Position          */
#define GPIO_PORT_PIN_PORT28(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT28_SHIFT))&GPIO_PORT_PIN_PORT28_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT29_MASK                (0x20000000U)                                       /*!< GPIO_PORT_PIN: PORT29 Mask              */
#define GPIO_PORT_PIN_PORT29_SHIFT               (29U)                                               /*!< GPIO_PORT_PIN: PORT29 Position          */
#define GPIO_PORT_PIN_PORT29(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT29_SHIFT))&GPIO_PORT_PIN_PORT29_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT30_MASK                (0x40000000U)                                       /*!< GPIO_PORT_PIN: PORT30 Mask              */
#define GPIO_PORT_PIN_PORT30_SHIFT               (30U)                                               /*!< GPIO_PORT_PIN: PORT30 Position          */
#define GPIO_PORT_PIN_PORT30(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT30_SHIFT))&GPIO_PORT_PIN_PORT30_MASK) /*!< GPIO_PORT_PIN                           */
#define GPIO_PORT_PIN_PORT31_MASK                (0x80000000U)                                       /*!< GPIO_PORT_PIN: PORT31 Mask              */
#define GPIO_PORT_PIN_PORT31_SHIFT               (31U)                                               /*!< GPIO_PORT_PIN: PORT31 Position          */
#define GPIO_PORT_PIN_PORT31(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_PIN_PORT31_SHIFT))&GPIO_PORT_PIN_PORT31_MASK) /*!< GPIO_PORT_PIN                           */
/* ------- MPIN Bit Fields                          ------ */
#define GPIO_PORT_MPIN_MPORTP0_MASK              (0x1U)                                              /*!< GPIO_PORT_MPIN: MPORTP0 Mask            */
#define GPIO_PORT_MPIN_MPORTP0_SHIFT             (0U)                                                /*!< GPIO_PORT_MPIN: MPORTP0 Position        */
#define GPIO_PORT_MPIN_MPORTP0(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP0_SHIFT))&GPIO_PORT_MPIN_MPORTP0_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP1_MASK              (0x2U)                                              /*!< GPIO_PORT_MPIN: MPORTP1 Mask            */
#define GPIO_PORT_MPIN_MPORTP1_SHIFT             (1U)                                                /*!< GPIO_PORT_MPIN: MPORTP1 Position        */
#define GPIO_PORT_MPIN_MPORTP1(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP1_SHIFT))&GPIO_PORT_MPIN_MPORTP1_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP2_MASK              (0x4U)                                              /*!< GPIO_PORT_MPIN: MPORTP2 Mask            */
#define GPIO_PORT_MPIN_MPORTP2_SHIFT             (2U)                                                /*!< GPIO_PORT_MPIN: MPORTP2 Position        */
#define GPIO_PORT_MPIN_MPORTP2(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP2_SHIFT))&GPIO_PORT_MPIN_MPORTP2_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP3_MASK              (0x8U)                                              /*!< GPIO_PORT_MPIN: MPORTP3 Mask            */
#define GPIO_PORT_MPIN_MPORTP3_SHIFT             (3U)                                                /*!< GPIO_PORT_MPIN: MPORTP3 Position        */
#define GPIO_PORT_MPIN_MPORTP3(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP3_SHIFT))&GPIO_PORT_MPIN_MPORTP3_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP4_MASK              (0x10U)                                             /*!< GPIO_PORT_MPIN: MPORTP4 Mask            */
#define GPIO_PORT_MPIN_MPORTP4_SHIFT             (4U)                                                /*!< GPIO_PORT_MPIN: MPORTP4 Position        */
#define GPIO_PORT_MPIN_MPORTP4(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP4_SHIFT))&GPIO_PORT_MPIN_MPORTP4_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP5_MASK              (0x20U)                                             /*!< GPIO_PORT_MPIN: MPORTP5 Mask            */
#define GPIO_PORT_MPIN_MPORTP5_SHIFT             (5U)                                                /*!< GPIO_PORT_MPIN: MPORTP5 Position        */
#define GPIO_PORT_MPIN_MPORTP5(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP5_SHIFT))&GPIO_PORT_MPIN_MPORTP5_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP6_MASK              (0x40U)                                             /*!< GPIO_PORT_MPIN: MPORTP6 Mask            */
#define GPIO_PORT_MPIN_MPORTP6_SHIFT             (6U)                                                /*!< GPIO_PORT_MPIN: MPORTP6 Position        */
#define GPIO_PORT_MPIN_MPORTP6(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP6_SHIFT))&GPIO_PORT_MPIN_MPORTP6_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP7_MASK              (0x80U)                                             /*!< GPIO_PORT_MPIN: MPORTP7 Mask            */
#define GPIO_PORT_MPIN_MPORTP7_SHIFT             (7U)                                                /*!< GPIO_PORT_MPIN: MPORTP7 Position        */
#define GPIO_PORT_MPIN_MPORTP7(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP7_SHIFT))&GPIO_PORT_MPIN_MPORTP7_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP8_MASK              (0x100U)                                            /*!< GPIO_PORT_MPIN: MPORTP8 Mask            */
#define GPIO_PORT_MPIN_MPORTP8_SHIFT             (8U)                                                /*!< GPIO_PORT_MPIN: MPORTP8 Position        */
#define GPIO_PORT_MPIN_MPORTP8(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP8_SHIFT))&GPIO_PORT_MPIN_MPORTP8_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP9_MASK              (0x200U)                                            /*!< GPIO_PORT_MPIN: MPORTP9 Mask            */
#define GPIO_PORT_MPIN_MPORTP9_SHIFT             (9U)                                                /*!< GPIO_PORT_MPIN: MPORTP9 Position        */
#define GPIO_PORT_MPIN_MPORTP9(x)                (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP9_SHIFT))&GPIO_PORT_MPIN_MPORTP9_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP10_MASK             (0x400U)                                            /*!< GPIO_PORT_MPIN: MPORTP10 Mask           */
#define GPIO_PORT_MPIN_MPORTP10_SHIFT            (10U)                                               /*!< GPIO_PORT_MPIN: MPORTP10 Position       */
#define GPIO_PORT_MPIN_MPORTP10(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP10_SHIFT))&GPIO_PORT_MPIN_MPORTP10_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP11_MASK             (0x800U)                                            /*!< GPIO_PORT_MPIN: MPORTP11 Mask           */
#define GPIO_PORT_MPIN_MPORTP11_SHIFT            (11U)                                               /*!< GPIO_PORT_MPIN: MPORTP11 Position       */
#define GPIO_PORT_MPIN_MPORTP11(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP11_SHIFT))&GPIO_PORT_MPIN_MPORTP11_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP12_MASK             (0x1000U)                                           /*!< GPIO_PORT_MPIN: MPORTP12 Mask           */
#define GPIO_PORT_MPIN_MPORTP12_SHIFT            (12U)                                               /*!< GPIO_PORT_MPIN: MPORTP12 Position       */
#define GPIO_PORT_MPIN_MPORTP12(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP12_SHIFT))&GPIO_PORT_MPIN_MPORTP12_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP13_MASK             (0x2000U)                                           /*!< GPIO_PORT_MPIN: MPORTP13 Mask           */
#define GPIO_PORT_MPIN_MPORTP13_SHIFT            (13U)                                               /*!< GPIO_PORT_MPIN: MPORTP13 Position       */
#define GPIO_PORT_MPIN_MPORTP13(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP13_SHIFT))&GPIO_PORT_MPIN_MPORTP13_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP14_MASK             (0x4000U)                                           /*!< GPIO_PORT_MPIN: MPORTP14 Mask           */
#define GPIO_PORT_MPIN_MPORTP14_SHIFT            (14U)                                               /*!< GPIO_PORT_MPIN: MPORTP14 Position       */
#define GPIO_PORT_MPIN_MPORTP14(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP14_SHIFT))&GPIO_PORT_MPIN_MPORTP14_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP15_MASK             (0x8000U)                                           /*!< GPIO_PORT_MPIN: MPORTP15 Mask           */
#define GPIO_PORT_MPIN_MPORTP15_SHIFT            (15U)                                               /*!< GPIO_PORT_MPIN: MPORTP15 Position       */
#define GPIO_PORT_MPIN_MPORTP15(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP15_SHIFT))&GPIO_PORT_MPIN_MPORTP15_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP16_MASK             (0x10000U)                                          /*!< GPIO_PORT_MPIN: MPORTP16 Mask           */
#define GPIO_PORT_MPIN_MPORTP16_SHIFT            (16U)                                               /*!< GPIO_PORT_MPIN: MPORTP16 Position       */
#define GPIO_PORT_MPIN_MPORTP16(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP16_SHIFT))&GPIO_PORT_MPIN_MPORTP16_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP17_MASK             (0x20000U)                                          /*!< GPIO_PORT_MPIN: MPORTP17 Mask           */
#define GPIO_PORT_MPIN_MPORTP17_SHIFT            (17U)                                               /*!< GPIO_PORT_MPIN: MPORTP17 Position       */
#define GPIO_PORT_MPIN_MPORTP17(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP17_SHIFT))&GPIO_PORT_MPIN_MPORTP17_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP18_MASK             (0x40000U)                                          /*!< GPIO_PORT_MPIN: MPORTP18 Mask           */
#define GPIO_PORT_MPIN_MPORTP18_SHIFT            (18U)                                               /*!< GPIO_PORT_MPIN: MPORTP18 Position       */
#define GPIO_PORT_MPIN_MPORTP18(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP18_SHIFT))&GPIO_PORT_MPIN_MPORTP18_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP19_MASK             (0x80000U)                                          /*!< GPIO_PORT_MPIN: MPORTP19 Mask           */
#define GPIO_PORT_MPIN_MPORTP19_SHIFT            (19U)                                               /*!< GPIO_PORT_MPIN: MPORTP19 Position       */
#define GPIO_PORT_MPIN_MPORTP19(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP19_SHIFT))&GPIO_PORT_MPIN_MPORTP19_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP20_MASK             (0x100000U)                                         /*!< GPIO_PORT_MPIN: MPORTP20 Mask           */
#define GPIO_PORT_MPIN_MPORTP20_SHIFT            (20U)                                               /*!< GPIO_PORT_MPIN: MPORTP20 Position       */
#define GPIO_PORT_MPIN_MPORTP20(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP20_SHIFT))&GPIO_PORT_MPIN_MPORTP20_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP21_MASK             (0x200000U)                                         /*!< GPIO_PORT_MPIN: MPORTP21 Mask           */
#define GPIO_PORT_MPIN_MPORTP21_SHIFT            (21U)                                               /*!< GPIO_PORT_MPIN: MPORTP21 Position       */
#define GPIO_PORT_MPIN_MPORTP21(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP21_SHIFT))&GPIO_PORT_MPIN_MPORTP21_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP22_MASK             (0x400000U)                                         /*!< GPIO_PORT_MPIN: MPORTP22 Mask           */
#define GPIO_PORT_MPIN_MPORTP22_SHIFT            (22U)                                               /*!< GPIO_PORT_MPIN: MPORTP22 Position       */
#define GPIO_PORT_MPIN_MPORTP22(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP22_SHIFT))&GPIO_PORT_MPIN_MPORTP22_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP23_MASK             (0x800000U)                                         /*!< GPIO_PORT_MPIN: MPORTP23 Mask           */
#define GPIO_PORT_MPIN_MPORTP23_SHIFT            (23U)                                               /*!< GPIO_PORT_MPIN: MPORTP23 Position       */
#define GPIO_PORT_MPIN_MPORTP23(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP23_SHIFT))&GPIO_PORT_MPIN_MPORTP23_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP24_MASK             (0x1000000U)                                        /*!< GPIO_PORT_MPIN: MPORTP24 Mask           */
#define GPIO_PORT_MPIN_MPORTP24_SHIFT            (24U)                                               /*!< GPIO_PORT_MPIN: MPORTP24 Position       */
#define GPIO_PORT_MPIN_MPORTP24(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP24_SHIFT))&GPIO_PORT_MPIN_MPORTP24_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP25_MASK             (0x2000000U)                                        /*!< GPIO_PORT_MPIN: MPORTP25 Mask           */
#define GPIO_PORT_MPIN_MPORTP25_SHIFT            (25U)                                               /*!< GPIO_PORT_MPIN: MPORTP25 Position       */
#define GPIO_PORT_MPIN_MPORTP25(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP25_SHIFT))&GPIO_PORT_MPIN_MPORTP25_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP26_MASK             (0x4000000U)                                        /*!< GPIO_PORT_MPIN: MPORTP26 Mask           */
#define GPIO_PORT_MPIN_MPORTP26_SHIFT            (26U)                                               /*!< GPIO_PORT_MPIN: MPORTP26 Position       */
#define GPIO_PORT_MPIN_MPORTP26(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP26_SHIFT))&GPIO_PORT_MPIN_MPORTP26_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP27_MASK             (0x8000000U)                                        /*!< GPIO_PORT_MPIN: MPORTP27 Mask           */
#define GPIO_PORT_MPIN_MPORTP27_SHIFT            (27U)                                               /*!< GPIO_PORT_MPIN: MPORTP27 Position       */
#define GPIO_PORT_MPIN_MPORTP27(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP27_SHIFT))&GPIO_PORT_MPIN_MPORTP27_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP28_MASK             (0x10000000U)                                       /*!< GPIO_PORT_MPIN: MPORTP28 Mask           */
#define GPIO_PORT_MPIN_MPORTP28_SHIFT            (28U)                                               /*!< GPIO_PORT_MPIN: MPORTP28 Position       */
#define GPIO_PORT_MPIN_MPORTP28(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP28_SHIFT))&GPIO_PORT_MPIN_MPORTP28_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP29_MASK             (0x20000000U)                                       /*!< GPIO_PORT_MPIN: MPORTP29 Mask           */
#define GPIO_PORT_MPIN_MPORTP29_SHIFT            (29U)                                               /*!< GPIO_PORT_MPIN: MPORTP29 Position       */
#define GPIO_PORT_MPIN_MPORTP29(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP29_SHIFT))&GPIO_PORT_MPIN_MPORTP29_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP30_MASK             (0x40000000U)                                       /*!< GPIO_PORT_MPIN: MPORTP30 Mask           */
#define GPIO_PORT_MPIN_MPORTP30_SHIFT            (30U)                                               /*!< GPIO_PORT_MPIN: MPORTP30 Position       */
#define GPIO_PORT_MPIN_MPORTP30(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP30_SHIFT))&GPIO_PORT_MPIN_MPORTP30_MASK) /*!< GPIO_PORT_MPIN                          */
#define GPIO_PORT_MPIN_MPORTP31_MASK             (0x80000000U)                                       /*!< GPIO_PORT_MPIN: MPORTP31 Mask           */
#define GPIO_PORT_MPIN_MPORTP31_SHIFT            (31U)                                               /*!< GPIO_PORT_MPIN: MPORTP31 Position       */
#define GPIO_PORT_MPIN_MPORTP31(x)               (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_MPIN_MPORTP31_SHIFT))&GPIO_PORT_MPIN_MPORTP31_MASK) /*!< GPIO_PORT_MPIN                          */
/* ------- SET Bit Fields                           ------ */
#define GPIO_PORT_SET_SETP0_MASK                 (0x1U)                                              /*!< GPIO_PORT_SET: SETP0 Mask               */
#define GPIO_PORT_SET_SETP0_SHIFT                (0U)                                                /*!< GPIO_PORT_SET: SETP0 Position           */
#define GPIO_PORT_SET_SETP0(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP0_SHIFT))&GPIO_PORT_SET_SETP0_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP1_MASK                 (0x2U)                                              /*!< GPIO_PORT_SET: SETP1 Mask               */
#define GPIO_PORT_SET_SETP1_SHIFT                (1U)                                                /*!< GPIO_PORT_SET: SETP1 Position           */
#define GPIO_PORT_SET_SETP1(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP1_SHIFT))&GPIO_PORT_SET_SETP1_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP2_MASK                 (0x4U)                                              /*!< GPIO_PORT_SET: SETP2 Mask               */
#define GPIO_PORT_SET_SETP2_SHIFT                (2U)                                                /*!< GPIO_PORT_SET: SETP2 Position           */
#define GPIO_PORT_SET_SETP2(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP2_SHIFT))&GPIO_PORT_SET_SETP2_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP3_MASK                 (0x8U)                                              /*!< GPIO_PORT_SET: SETP3 Mask               */
#define GPIO_PORT_SET_SETP3_SHIFT                (3U)                                                /*!< GPIO_PORT_SET: SETP3 Position           */
#define GPIO_PORT_SET_SETP3(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP3_SHIFT))&GPIO_PORT_SET_SETP3_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP4_MASK                 (0x10U)                                             /*!< GPIO_PORT_SET: SETP4 Mask               */
#define GPIO_PORT_SET_SETP4_SHIFT                (4U)                                                /*!< GPIO_PORT_SET: SETP4 Position           */
#define GPIO_PORT_SET_SETP4(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP4_SHIFT))&GPIO_PORT_SET_SETP4_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP5_MASK                 (0x20U)                                             /*!< GPIO_PORT_SET: SETP5 Mask               */
#define GPIO_PORT_SET_SETP5_SHIFT                (5U)                                                /*!< GPIO_PORT_SET: SETP5 Position           */
#define GPIO_PORT_SET_SETP5(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP5_SHIFT))&GPIO_PORT_SET_SETP5_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP6_MASK                 (0x40U)                                             /*!< GPIO_PORT_SET: SETP6 Mask               */
#define GPIO_PORT_SET_SETP6_SHIFT                (6U)                                                /*!< GPIO_PORT_SET: SETP6 Position           */
#define GPIO_PORT_SET_SETP6(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP6_SHIFT))&GPIO_PORT_SET_SETP6_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP7_MASK                 (0x80U)                                             /*!< GPIO_PORT_SET: SETP7 Mask               */
#define GPIO_PORT_SET_SETP7_SHIFT                (7U)                                                /*!< GPIO_PORT_SET: SETP7 Position           */
#define GPIO_PORT_SET_SETP7(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP7_SHIFT))&GPIO_PORT_SET_SETP7_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP8_MASK                 (0x100U)                                            /*!< GPIO_PORT_SET: SETP8 Mask               */
#define GPIO_PORT_SET_SETP8_SHIFT                (8U)                                                /*!< GPIO_PORT_SET: SETP8 Position           */
#define GPIO_PORT_SET_SETP8(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP8_SHIFT))&GPIO_PORT_SET_SETP8_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP9_MASK                 (0x200U)                                            /*!< GPIO_PORT_SET: SETP9 Mask               */
#define GPIO_PORT_SET_SETP9_SHIFT                (9U)                                                /*!< GPIO_PORT_SET: SETP9 Position           */
#define GPIO_PORT_SET_SETP9(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP9_SHIFT))&GPIO_PORT_SET_SETP9_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP10_MASK                (0x400U)                                            /*!< GPIO_PORT_SET: SETP10 Mask              */
#define GPIO_PORT_SET_SETP10_SHIFT               (10U)                                               /*!< GPIO_PORT_SET: SETP10 Position          */
#define GPIO_PORT_SET_SETP10(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP10_SHIFT))&GPIO_PORT_SET_SETP10_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP11_MASK                (0x800U)                                            /*!< GPIO_PORT_SET: SETP11 Mask              */
#define GPIO_PORT_SET_SETP11_SHIFT               (11U)                                               /*!< GPIO_PORT_SET: SETP11 Position          */
#define GPIO_PORT_SET_SETP11(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP11_SHIFT))&GPIO_PORT_SET_SETP11_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP12_MASK                (0x1000U)                                           /*!< GPIO_PORT_SET: SETP12 Mask              */
#define GPIO_PORT_SET_SETP12_SHIFT               (12U)                                               /*!< GPIO_PORT_SET: SETP12 Position          */
#define GPIO_PORT_SET_SETP12(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP12_SHIFT))&GPIO_PORT_SET_SETP12_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP13_MASK                (0x2000U)                                           /*!< GPIO_PORT_SET: SETP13 Mask              */
#define GPIO_PORT_SET_SETP13_SHIFT               (13U)                                               /*!< GPIO_PORT_SET: SETP13 Position          */
#define GPIO_PORT_SET_SETP13(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP13_SHIFT))&GPIO_PORT_SET_SETP13_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP14_MASK                (0x4000U)                                           /*!< GPIO_PORT_SET: SETP14 Mask              */
#define GPIO_PORT_SET_SETP14_SHIFT               (14U)                                               /*!< GPIO_PORT_SET: SETP14 Position          */
#define GPIO_PORT_SET_SETP14(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP14_SHIFT))&GPIO_PORT_SET_SETP14_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP15_MASK                (0x8000U)                                           /*!< GPIO_PORT_SET: SETP15 Mask              */
#define GPIO_PORT_SET_SETP15_SHIFT               (15U)                                               /*!< GPIO_PORT_SET: SETP15 Position          */
#define GPIO_PORT_SET_SETP15(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP15_SHIFT))&GPIO_PORT_SET_SETP15_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP16_MASK                (0x10000U)                                          /*!< GPIO_PORT_SET: SETP16 Mask              */
#define GPIO_PORT_SET_SETP16_SHIFT               (16U)                                               /*!< GPIO_PORT_SET: SETP16 Position          */
#define GPIO_PORT_SET_SETP16(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP16_SHIFT))&GPIO_PORT_SET_SETP16_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP17_MASK                (0x20000U)                                          /*!< GPIO_PORT_SET: SETP17 Mask              */
#define GPIO_PORT_SET_SETP17_SHIFT               (17U)                                               /*!< GPIO_PORT_SET: SETP17 Position          */
#define GPIO_PORT_SET_SETP17(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP17_SHIFT))&GPIO_PORT_SET_SETP17_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP18_MASK                (0x40000U)                                          /*!< GPIO_PORT_SET: SETP18 Mask              */
#define GPIO_PORT_SET_SETP18_SHIFT               (18U)                                               /*!< GPIO_PORT_SET: SETP18 Position          */
#define GPIO_PORT_SET_SETP18(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP18_SHIFT))&GPIO_PORT_SET_SETP18_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP19_MASK                (0x80000U)                                          /*!< GPIO_PORT_SET: SETP19 Mask              */
#define GPIO_PORT_SET_SETP19_SHIFT               (19U)                                               /*!< GPIO_PORT_SET: SETP19 Position          */
#define GPIO_PORT_SET_SETP19(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP19_SHIFT))&GPIO_PORT_SET_SETP19_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP20_MASK                (0x100000U)                                         /*!< GPIO_PORT_SET: SETP20 Mask              */
#define GPIO_PORT_SET_SETP20_SHIFT               (20U)                                               /*!< GPIO_PORT_SET: SETP20 Position          */
#define GPIO_PORT_SET_SETP20(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP20_SHIFT))&GPIO_PORT_SET_SETP20_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP21_MASK                (0x200000U)                                         /*!< GPIO_PORT_SET: SETP21 Mask              */
#define GPIO_PORT_SET_SETP21_SHIFT               (21U)                                               /*!< GPIO_PORT_SET: SETP21 Position          */
#define GPIO_PORT_SET_SETP21(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP21_SHIFT))&GPIO_PORT_SET_SETP21_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP22_MASK                (0x400000U)                                         /*!< GPIO_PORT_SET: SETP22 Mask              */
#define GPIO_PORT_SET_SETP22_SHIFT               (22U)                                               /*!< GPIO_PORT_SET: SETP22 Position          */
#define GPIO_PORT_SET_SETP22(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP22_SHIFT))&GPIO_PORT_SET_SETP22_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP23_MASK                (0x800000U)                                         /*!< GPIO_PORT_SET: SETP23 Mask              */
#define GPIO_PORT_SET_SETP23_SHIFT               (23U)                                               /*!< GPIO_PORT_SET: SETP23 Position          */
#define GPIO_PORT_SET_SETP23(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP23_SHIFT))&GPIO_PORT_SET_SETP23_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP24_MASK                (0x1000000U)                                        /*!< GPIO_PORT_SET: SETP24 Mask              */
#define GPIO_PORT_SET_SETP24_SHIFT               (24U)                                               /*!< GPIO_PORT_SET: SETP24 Position          */
#define GPIO_PORT_SET_SETP24(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP24_SHIFT))&GPIO_PORT_SET_SETP24_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP25_MASK                (0x2000000U)                                        /*!< GPIO_PORT_SET: SETP25 Mask              */
#define GPIO_PORT_SET_SETP25_SHIFT               (25U)                                               /*!< GPIO_PORT_SET: SETP25 Position          */
#define GPIO_PORT_SET_SETP25(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP25_SHIFT))&GPIO_PORT_SET_SETP25_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP26_MASK                (0x4000000U)                                        /*!< GPIO_PORT_SET: SETP26 Mask              */
#define GPIO_PORT_SET_SETP26_SHIFT               (26U)                                               /*!< GPIO_PORT_SET: SETP26 Position          */
#define GPIO_PORT_SET_SETP26(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP26_SHIFT))&GPIO_PORT_SET_SETP26_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP27_MASK                (0x8000000U)                                        /*!< GPIO_PORT_SET: SETP27 Mask              */
#define GPIO_PORT_SET_SETP27_SHIFT               (27U)                                               /*!< GPIO_PORT_SET: SETP27 Position          */
#define GPIO_PORT_SET_SETP27(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP27_SHIFT))&GPIO_PORT_SET_SETP27_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP28_MASK                (0x10000000U)                                       /*!< GPIO_PORT_SET: SETP28 Mask              */
#define GPIO_PORT_SET_SETP28_SHIFT               (28U)                                               /*!< GPIO_PORT_SET: SETP28 Position          */
#define GPIO_PORT_SET_SETP28(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP28_SHIFT))&GPIO_PORT_SET_SETP28_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP29_MASK                (0x20000000U)                                       /*!< GPIO_PORT_SET: SETP29 Mask              */
#define GPIO_PORT_SET_SETP29_SHIFT               (29U)                                               /*!< GPIO_PORT_SET: SETP29 Position          */
#define GPIO_PORT_SET_SETP29(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP29_SHIFT))&GPIO_PORT_SET_SETP29_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP30_MASK                (0x40000000U)                                       /*!< GPIO_PORT_SET: SETP30 Mask              */
#define GPIO_PORT_SET_SETP30_SHIFT               (30U)                                               /*!< GPIO_PORT_SET: SETP30 Position          */
#define GPIO_PORT_SET_SETP30(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP30_SHIFT))&GPIO_PORT_SET_SETP30_MASK) /*!< GPIO_PORT_SET                           */
#define GPIO_PORT_SET_SETP31_MASK                (0x80000000U)                                       /*!< GPIO_PORT_SET: SETP31 Mask              */
#define GPIO_PORT_SET_SETP31_SHIFT               (31U)                                               /*!< GPIO_PORT_SET: SETP31 Position          */
#define GPIO_PORT_SET_SETP31(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_SET_SETP31_SHIFT))&GPIO_PORT_SET_SETP31_MASK) /*!< GPIO_PORT_SET                           */
/* ------- CLR Bit Fields                           ------ */
#define GPIO_PORT_CLR_CLRP00_MASK                (0x1U)                                              /*!< GPIO_PORT_CLR: CLRP00 Mask              */
#define GPIO_PORT_CLR_CLRP00_SHIFT               (0U)                                                /*!< GPIO_PORT_CLR: CLRP00 Position          */
#define GPIO_PORT_CLR_CLRP00(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP00_SHIFT))&GPIO_PORT_CLR_CLRP00_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP01_MASK                (0x2U)                                              /*!< GPIO_PORT_CLR: CLRP01 Mask              */
#define GPIO_PORT_CLR_CLRP01_SHIFT               (1U)                                                /*!< GPIO_PORT_CLR: CLRP01 Position          */
#define GPIO_PORT_CLR_CLRP01(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP01_SHIFT))&GPIO_PORT_CLR_CLRP01_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP02_MASK                (0x4U)                                              /*!< GPIO_PORT_CLR: CLRP02 Mask              */
#define GPIO_PORT_CLR_CLRP02_SHIFT               (2U)                                                /*!< GPIO_PORT_CLR: CLRP02 Position          */
#define GPIO_PORT_CLR_CLRP02(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP02_SHIFT))&GPIO_PORT_CLR_CLRP02_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP03_MASK                (0x8U)                                              /*!< GPIO_PORT_CLR: CLRP03 Mask              */
#define GPIO_PORT_CLR_CLRP03_SHIFT               (3U)                                                /*!< GPIO_PORT_CLR: CLRP03 Position          */
#define GPIO_PORT_CLR_CLRP03(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP03_SHIFT))&GPIO_PORT_CLR_CLRP03_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP04_MASK                (0x10U)                                             /*!< GPIO_PORT_CLR: CLRP04 Mask              */
#define GPIO_PORT_CLR_CLRP04_SHIFT               (4U)                                                /*!< GPIO_PORT_CLR: CLRP04 Position          */
#define GPIO_PORT_CLR_CLRP04(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP04_SHIFT))&GPIO_PORT_CLR_CLRP04_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP05_MASK                (0x20U)                                             /*!< GPIO_PORT_CLR: CLRP05 Mask              */
#define GPIO_PORT_CLR_CLRP05_SHIFT               (5U)                                                /*!< GPIO_PORT_CLR: CLRP05 Position          */
#define GPIO_PORT_CLR_CLRP05(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP05_SHIFT))&GPIO_PORT_CLR_CLRP05_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP06_MASK                (0x40U)                                             /*!< GPIO_PORT_CLR: CLRP06 Mask              */
#define GPIO_PORT_CLR_CLRP06_SHIFT               (6U)                                                /*!< GPIO_PORT_CLR: CLRP06 Position          */
#define GPIO_PORT_CLR_CLRP06(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP06_SHIFT))&GPIO_PORT_CLR_CLRP06_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP07_MASK                (0x80U)                                             /*!< GPIO_PORT_CLR: CLRP07 Mask              */
#define GPIO_PORT_CLR_CLRP07_SHIFT               (7U)                                                /*!< GPIO_PORT_CLR: CLRP07 Position          */
#define GPIO_PORT_CLR_CLRP07(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP07_SHIFT))&GPIO_PORT_CLR_CLRP07_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP08_MASK                (0x100U)                                            /*!< GPIO_PORT_CLR: CLRP08 Mask              */
#define GPIO_PORT_CLR_CLRP08_SHIFT               (8U)                                                /*!< GPIO_PORT_CLR: CLRP08 Position          */
#define GPIO_PORT_CLR_CLRP08(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP08_SHIFT))&GPIO_PORT_CLR_CLRP08_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP09_MASK                (0x200U)                                            /*!< GPIO_PORT_CLR: CLRP09 Mask              */
#define GPIO_PORT_CLR_CLRP09_SHIFT               (9U)                                                /*!< GPIO_PORT_CLR: CLRP09 Position          */
#define GPIO_PORT_CLR_CLRP09(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP09_SHIFT))&GPIO_PORT_CLR_CLRP09_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP010_MASK               (0x400U)                                            /*!< GPIO_PORT_CLR: CLRP010 Mask             */
#define GPIO_PORT_CLR_CLRP010_SHIFT              (10U)                                               /*!< GPIO_PORT_CLR: CLRP010 Position         */
#define GPIO_PORT_CLR_CLRP010(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP010_SHIFT))&GPIO_PORT_CLR_CLRP010_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP011_MASK               (0x800U)                                            /*!< GPIO_PORT_CLR: CLRP011 Mask             */
#define GPIO_PORT_CLR_CLRP011_SHIFT              (11U)                                               /*!< GPIO_PORT_CLR: CLRP011 Position         */
#define GPIO_PORT_CLR_CLRP011(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP011_SHIFT))&GPIO_PORT_CLR_CLRP011_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP012_MASK               (0x1000U)                                           /*!< GPIO_PORT_CLR: CLRP012 Mask             */
#define GPIO_PORT_CLR_CLRP012_SHIFT              (12U)                                               /*!< GPIO_PORT_CLR: CLRP012 Position         */
#define GPIO_PORT_CLR_CLRP012(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP012_SHIFT))&GPIO_PORT_CLR_CLRP012_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP013_MASK               (0x2000U)                                           /*!< GPIO_PORT_CLR: CLRP013 Mask             */
#define GPIO_PORT_CLR_CLRP013_SHIFT              (13U)                                               /*!< GPIO_PORT_CLR: CLRP013 Position         */
#define GPIO_PORT_CLR_CLRP013(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP013_SHIFT))&GPIO_PORT_CLR_CLRP013_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP014_MASK               (0x4000U)                                           /*!< GPIO_PORT_CLR: CLRP014 Mask             */
#define GPIO_PORT_CLR_CLRP014_SHIFT              (14U)                                               /*!< GPIO_PORT_CLR: CLRP014 Position         */
#define GPIO_PORT_CLR_CLRP014(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP014_SHIFT))&GPIO_PORT_CLR_CLRP014_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP015_MASK               (0x8000U)                                           /*!< GPIO_PORT_CLR: CLRP015 Mask             */
#define GPIO_PORT_CLR_CLRP015_SHIFT              (15U)                                               /*!< GPIO_PORT_CLR: CLRP015 Position         */
#define GPIO_PORT_CLR_CLRP015(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP015_SHIFT))&GPIO_PORT_CLR_CLRP015_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP016_MASK               (0x10000U)                                          /*!< GPIO_PORT_CLR: CLRP016 Mask             */
#define GPIO_PORT_CLR_CLRP016_SHIFT              (16U)                                               /*!< GPIO_PORT_CLR: CLRP016 Position         */
#define GPIO_PORT_CLR_CLRP016(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP016_SHIFT))&GPIO_PORT_CLR_CLRP016_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP017_MASK               (0x20000U)                                          /*!< GPIO_PORT_CLR: CLRP017 Mask             */
#define GPIO_PORT_CLR_CLRP017_SHIFT              (17U)                                               /*!< GPIO_PORT_CLR: CLRP017 Position         */
#define GPIO_PORT_CLR_CLRP017(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP017_SHIFT))&GPIO_PORT_CLR_CLRP017_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP018_MASK               (0x40000U)                                          /*!< GPIO_PORT_CLR: CLRP018 Mask             */
#define GPIO_PORT_CLR_CLRP018_SHIFT              (18U)                                               /*!< GPIO_PORT_CLR: CLRP018 Position         */
#define GPIO_PORT_CLR_CLRP018(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP018_SHIFT))&GPIO_PORT_CLR_CLRP018_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP019_MASK               (0x80000U)                                          /*!< GPIO_PORT_CLR: CLRP019 Mask             */
#define GPIO_PORT_CLR_CLRP019_SHIFT              (19U)                                               /*!< GPIO_PORT_CLR: CLRP019 Position         */
#define GPIO_PORT_CLR_CLRP019(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP019_SHIFT))&GPIO_PORT_CLR_CLRP019_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP020_MASK               (0x100000U)                                         /*!< GPIO_PORT_CLR: CLRP020 Mask             */
#define GPIO_PORT_CLR_CLRP020_SHIFT              (20U)                                               /*!< GPIO_PORT_CLR: CLRP020 Position         */
#define GPIO_PORT_CLR_CLRP020(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP020_SHIFT))&GPIO_PORT_CLR_CLRP020_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP021_MASK               (0x200000U)                                         /*!< GPIO_PORT_CLR: CLRP021 Mask             */
#define GPIO_PORT_CLR_CLRP021_SHIFT              (21U)                                               /*!< GPIO_PORT_CLR: CLRP021 Position         */
#define GPIO_PORT_CLR_CLRP021(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP021_SHIFT))&GPIO_PORT_CLR_CLRP021_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP022_MASK               (0x400000U)                                         /*!< GPIO_PORT_CLR: CLRP022 Mask             */
#define GPIO_PORT_CLR_CLRP022_SHIFT              (22U)                                               /*!< GPIO_PORT_CLR: CLRP022 Position         */
#define GPIO_PORT_CLR_CLRP022(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP022_SHIFT))&GPIO_PORT_CLR_CLRP022_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP023_MASK               (0x800000U)                                         /*!< GPIO_PORT_CLR: CLRP023 Mask             */
#define GPIO_PORT_CLR_CLRP023_SHIFT              (23U)                                               /*!< GPIO_PORT_CLR: CLRP023 Position         */
#define GPIO_PORT_CLR_CLRP023(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP023_SHIFT))&GPIO_PORT_CLR_CLRP023_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP024_MASK               (0x1000000U)                                        /*!< GPIO_PORT_CLR: CLRP024 Mask             */
#define GPIO_PORT_CLR_CLRP024_SHIFT              (24U)                                               /*!< GPIO_PORT_CLR: CLRP024 Position         */
#define GPIO_PORT_CLR_CLRP024(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP024_SHIFT))&GPIO_PORT_CLR_CLRP024_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP025_MASK               (0x2000000U)                                        /*!< GPIO_PORT_CLR: CLRP025 Mask             */
#define GPIO_PORT_CLR_CLRP025_SHIFT              (25U)                                               /*!< GPIO_PORT_CLR: CLRP025 Position         */
#define GPIO_PORT_CLR_CLRP025(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP025_SHIFT))&GPIO_PORT_CLR_CLRP025_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP026_MASK               (0x4000000U)                                        /*!< GPIO_PORT_CLR: CLRP026 Mask             */
#define GPIO_PORT_CLR_CLRP026_SHIFT              (26U)                                               /*!< GPIO_PORT_CLR: CLRP026 Position         */
#define GPIO_PORT_CLR_CLRP026(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP026_SHIFT))&GPIO_PORT_CLR_CLRP026_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP027_MASK               (0x8000000U)                                        /*!< GPIO_PORT_CLR: CLRP027 Mask             */
#define GPIO_PORT_CLR_CLRP027_SHIFT              (27U)                                               /*!< GPIO_PORT_CLR: CLRP027 Position         */
#define GPIO_PORT_CLR_CLRP027(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP027_SHIFT))&GPIO_PORT_CLR_CLRP027_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP028_MASK               (0x10000000U)                                       /*!< GPIO_PORT_CLR: CLRP028 Mask             */
#define GPIO_PORT_CLR_CLRP028_SHIFT              (28U)                                               /*!< GPIO_PORT_CLR: CLRP028 Position         */
#define GPIO_PORT_CLR_CLRP028(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP028_SHIFT))&GPIO_PORT_CLR_CLRP028_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP029_MASK               (0x20000000U)                                       /*!< GPIO_PORT_CLR: CLRP029 Mask             */
#define GPIO_PORT_CLR_CLRP029_SHIFT              (29U)                                               /*!< GPIO_PORT_CLR: CLRP029 Position         */
#define GPIO_PORT_CLR_CLRP029(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP029_SHIFT))&GPIO_PORT_CLR_CLRP029_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP030_MASK               (0x40000000U)                                       /*!< GPIO_PORT_CLR: CLRP030 Mask             */
#define GPIO_PORT_CLR_CLRP030_SHIFT              (30U)                                               /*!< GPIO_PORT_CLR: CLRP030 Position         */
#define GPIO_PORT_CLR_CLRP030(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP030_SHIFT))&GPIO_PORT_CLR_CLRP030_MASK) /*!< GPIO_PORT_CLR                           */
#define GPIO_PORT_CLR_CLRP031_MASK               (0x80000000U)                                       /*!< GPIO_PORT_CLR: CLRP031 Mask             */
#define GPIO_PORT_CLR_CLRP031_SHIFT              (31U)                                               /*!< GPIO_PORT_CLR: CLRP031 Position         */
#define GPIO_PORT_CLR_CLRP031(x)                 (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_CLR_CLRP031_SHIFT))&GPIO_PORT_CLR_CLRP031_MASK) /*!< GPIO_PORT_CLR                           */
/* ------- NOT Bit Fields                           ------ */
#define GPIO_PORT_NOT_NOTP0_MASK                 (0x1U)                                              /*!< GPIO_PORT_NOT: NOTP0 Mask               */
#define GPIO_PORT_NOT_NOTP0_SHIFT                (0U)                                                /*!< GPIO_PORT_NOT: NOTP0 Position           */
#define GPIO_PORT_NOT_NOTP0(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP0_SHIFT))&GPIO_PORT_NOT_NOTP0_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP1_MASK                 (0x2U)                                              /*!< GPIO_PORT_NOT: NOTP1 Mask               */
#define GPIO_PORT_NOT_NOTP1_SHIFT                (1U)                                                /*!< GPIO_PORT_NOT: NOTP1 Position           */
#define GPIO_PORT_NOT_NOTP1(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP1_SHIFT))&GPIO_PORT_NOT_NOTP1_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP2_MASK                 (0x4U)                                              /*!< GPIO_PORT_NOT: NOTP2 Mask               */
#define GPIO_PORT_NOT_NOTP2_SHIFT                (2U)                                                /*!< GPIO_PORT_NOT: NOTP2 Position           */
#define GPIO_PORT_NOT_NOTP2(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP2_SHIFT))&GPIO_PORT_NOT_NOTP2_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP3_MASK                 (0x8U)                                              /*!< GPIO_PORT_NOT: NOTP3 Mask               */
#define GPIO_PORT_NOT_NOTP3_SHIFT                (3U)                                                /*!< GPIO_PORT_NOT: NOTP3 Position           */
#define GPIO_PORT_NOT_NOTP3(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP3_SHIFT))&GPIO_PORT_NOT_NOTP3_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP4_MASK                 (0x10U)                                             /*!< GPIO_PORT_NOT: NOTP4 Mask               */
#define GPIO_PORT_NOT_NOTP4_SHIFT                (4U)                                                /*!< GPIO_PORT_NOT: NOTP4 Position           */
#define GPIO_PORT_NOT_NOTP4(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP4_SHIFT))&GPIO_PORT_NOT_NOTP4_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP5_MASK                 (0x20U)                                             /*!< GPIO_PORT_NOT: NOTP5 Mask               */
#define GPIO_PORT_NOT_NOTP5_SHIFT                (5U)                                                /*!< GPIO_PORT_NOT: NOTP5 Position           */
#define GPIO_PORT_NOT_NOTP5(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP5_SHIFT))&GPIO_PORT_NOT_NOTP5_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP6_MASK                 (0x40U)                                             /*!< GPIO_PORT_NOT: NOTP6 Mask               */
#define GPIO_PORT_NOT_NOTP6_SHIFT                (6U)                                                /*!< GPIO_PORT_NOT: NOTP6 Position           */
#define GPIO_PORT_NOT_NOTP6(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP6_SHIFT))&GPIO_PORT_NOT_NOTP6_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP7_MASK                 (0x80U)                                             /*!< GPIO_PORT_NOT: NOTP7 Mask               */
#define GPIO_PORT_NOT_NOTP7_SHIFT                (7U)                                                /*!< GPIO_PORT_NOT: NOTP7 Position           */
#define GPIO_PORT_NOT_NOTP7(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP7_SHIFT))&GPIO_PORT_NOT_NOTP7_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP8_MASK                 (0x100U)                                            /*!< GPIO_PORT_NOT: NOTP8 Mask               */
#define GPIO_PORT_NOT_NOTP8_SHIFT                (8U)                                                /*!< GPIO_PORT_NOT: NOTP8 Position           */
#define GPIO_PORT_NOT_NOTP8(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP8_SHIFT))&GPIO_PORT_NOT_NOTP8_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP9_MASK                 (0x200U)                                            /*!< GPIO_PORT_NOT: NOTP9 Mask               */
#define GPIO_PORT_NOT_NOTP9_SHIFT                (9U)                                                /*!< GPIO_PORT_NOT: NOTP9 Position           */
#define GPIO_PORT_NOT_NOTP9(x)                   (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP9_SHIFT))&GPIO_PORT_NOT_NOTP9_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP10_MASK                (0x400U)                                            /*!< GPIO_PORT_NOT: NOTP10 Mask              */
#define GPIO_PORT_NOT_NOTP10_SHIFT               (10U)                                               /*!< GPIO_PORT_NOT: NOTP10 Position          */
#define GPIO_PORT_NOT_NOTP10(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP10_SHIFT))&GPIO_PORT_NOT_NOTP10_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP11_MASK                (0x800U)                                            /*!< GPIO_PORT_NOT: NOTP11 Mask              */
#define GPIO_PORT_NOT_NOTP11_SHIFT               (11U)                                               /*!< GPIO_PORT_NOT: NOTP11 Position          */
#define GPIO_PORT_NOT_NOTP11(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP11_SHIFT))&GPIO_PORT_NOT_NOTP11_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP12_MASK                (0x1000U)                                           /*!< GPIO_PORT_NOT: NOTP12 Mask              */
#define GPIO_PORT_NOT_NOTP12_SHIFT               (12U)                                               /*!< GPIO_PORT_NOT: NOTP12 Position          */
#define GPIO_PORT_NOT_NOTP12(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP12_SHIFT))&GPIO_PORT_NOT_NOTP12_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP13_MASK                (0x2000U)                                           /*!< GPIO_PORT_NOT: NOTP13 Mask              */
#define GPIO_PORT_NOT_NOTP13_SHIFT               (13U)                                               /*!< GPIO_PORT_NOT: NOTP13 Position          */
#define GPIO_PORT_NOT_NOTP13(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP13_SHIFT))&GPIO_PORT_NOT_NOTP13_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP14_MASK                (0x4000U)                                           /*!< GPIO_PORT_NOT: NOTP14 Mask              */
#define GPIO_PORT_NOT_NOTP14_SHIFT               (14U)                                               /*!< GPIO_PORT_NOT: NOTP14 Position          */
#define GPIO_PORT_NOT_NOTP14(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP14_SHIFT))&GPIO_PORT_NOT_NOTP14_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP15_MASK                (0x8000U)                                           /*!< GPIO_PORT_NOT: NOTP15 Mask              */
#define GPIO_PORT_NOT_NOTP15_SHIFT               (15U)                                               /*!< GPIO_PORT_NOT: NOTP15 Position          */
#define GPIO_PORT_NOT_NOTP15(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP15_SHIFT))&GPIO_PORT_NOT_NOTP15_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP16_MASK                (0x10000U)                                          /*!< GPIO_PORT_NOT: NOTP16 Mask              */
#define GPIO_PORT_NOT_NOTP16_SHIFT               (16U)                                               /*!< GPIO_PORT_NOT: NOTP16 Position          */
#define GPIO_PORT_NOT_NOTP16(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP16_SHIFT))&GPIO_PORT_NOT_NOTP16_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP17_MASK                (0x20000U)                                          /*!< GPIO_PORT_NOT: NOTP17 Mask              */
#define GPIO_PORT_NOT_NOTP17_SHIFT               (17U)                                               /*!< GPIO_PORT_NOT: NOTP17 Position          */
#define GPIO_PORT_NOT_NOTP17(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP17_SHIFT))&GPIO_PORT_NOT_NOTP17_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP18_MASK                (0x40000U)                                          /*!< GPIO_PORT_NOT: NOTP18 Mask              */
#define GPIO_PORT_NOT_NOTP18_SHIFT               (18U)                                               /*!< GPIO_PORT_NOT: NOTP18 Position          */
#define GPIO_PORT_NOT_NOTP18(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP18_SHIFT))&GPIO_PORT_NOT_NOTP18_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP19_MASK                (0x80000U)                                          /*!< GPIO_PORT_NOT: NOTP19 Mask              */
#define GPIO_PORT_NOT_NOTP19_SHIFT               (19U)                                               /*!< GPIO_PORT_NOT: NOTP19 Position          */
#define GPIO_PORT_NOT_NOTP19(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP19_SHIFT))&GPIO_PORT_NOT_NOTP19_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP20_MASK                (0x100000U)                                         /*!< GPIO_PORT_NOT: NOTP20 Mask              */
#define GPIO_PORT_NOT_NOTP20_SHIFT               (20U)                                               /*!< GPIO_PORT_NOT: NOTP20 Position          */
#define GPIO_PORT_NOT_NOTP20(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP20_SHIFT))&GPIO_PORT_NOT_NOTP20_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP21_MASK                (0x200000U)                                         /*!< GPIO_PORT_NOT: NOTP21 Mask              */
#define GPIO_PORT_NOT_NOTP21_SHIFT               (21U)                                               /*!< GPIO_PORT_NOT: NOTP21 Position          */
#define GPIO_PORT_NOT_NOTP21(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP21_SHIFT))&GPIO_PORT_NOT_NOTP21_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP22_MASK                (0x400000U)                                         /*!< GPIO_PORT_NOT: NOTP22 Mask              */
#define GPIO_PORT_NOT_NOTP22_SHIFT               (22U)                                               /*!< GPIO_PORT_NOT: NOTP22 Position          */
#define GPIO_PORT_NOT_NOTP22(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP22_SHIFT))&GPIO_PORT_NOT_NOTP22_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP23_MASK                (0x800000U)                                         /*!< GPIO_PORT_NOT: NOTP23 Mask              */
#define GPIO_PORT_NOT_NOTP23_SHIFT               (23U)                                               /*!< GPIO_PORT_NOT: NOTP23 Position          */
#define GPIO_PORT_NOT_NOTP23(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP23_SHIFT))&GPIO_PORT_NOT_NOTP23_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP24_MASK                (0x1000000U)                                        /*!< GPIO_PORT_NOT: NOTP24 Mask              */
#define GPIO_PORT_NOT_NOTP24_SHIFT               (24U)                                               /*!< GPIO_PORT_NOT: NOTP24 Position          */
#define GPIO_PORT_NOT_NOTP24(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP24_SHIFT))&GPIO_PORT_NOT_NOTP24_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP25_MASK                (0x2000000U)                                        /*!< GPIO_PORT_NOT: NOTP25 Mask              */
#define GPIO_PORT_NOT_NOTP25_SHIFT               (25U)                                               /*!< GPIO_PORT_NOT: NOTP25 Position          */
#define GPIO_PORT_NOT_NOTP25(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP25_SHIFT))&GPIO_PORT_NOT_NOTP25_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP26_MASK                (0x4000000U)                                        /*!< GPIO_PORT_NOT: NOTP26 Mask              */
#define GPIO_PORT_NOT_NOTP26_SHIFT               (26U)                                               /*!< GPIO_PORT_NOT: NOTP26 Position          */
#define GPIO_PORT_NOT_NOTP26(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP26_SHIFT))&GPIO_PORT_NOT_NOTP26_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP27_MASK                (0x8000000U)                                        /*!< GPIO_PORT_NOT: NOTP27 Mask              */
#define GPIO_PORT_NOT_NOTP27_SHIFT               (27U)                                               /*!< GPIO_PORT_NOT: NOTP27 Position          */
#define GPIO_PORT_NOT_NOTP27(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP27_SHIFT))&GPIO_PORT_NOT_NOTP27_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP28_MASK                (0x10000000U)                                       /*!< GPIO_PORT_NOT: NOTP28 Mask              */
#define GPIO_PORT_NOT_NOTP28_SHIFT               (28U)                                               /*!< GPIO_PORT_NOT: NOTP28 Position          */
#define GPIO_PORT_NOT_NOTP28(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP28_SHIFT))&GPIO_PORT_NOT_NOTP28_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP29_MASK                (0x20000000U)                                       /*!< GPIO_PORT_NOT: NOTP29 Mask              */
#define GPIO_PORT_NOT_NOTP29_SHIFT               (29U)                                               /*!< GPIO_PORT_NOT: NOTP29 Position          */
#define GPIO_PORT_NOT_NOTP29(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP29_SHIFT))&GPIO_PORT_NOT_NOTP29_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP30_MASK                (0x40000000U)                                       /*!< GPIO_PORT_NOT: NOTP30 Mask              */
#define GPIO_PORT_NOT_NOTP30_SHIFT               (30U)                                               /*!< GPIO_PORT_NOT: NOTP30 Position          */
#define GPIO_PORT_NOT_NOTP30(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP30_SHIFT))&GPIO_PORT_NOT_NOTP30_MASK) /*!< GPIO_PORT_NOT                           */
#define GPIO_PORT_NOT_NOTP31_MASK                (0x80000000U)                                       /*!< GPIO_PORT_NOT: NOTP31 Mask              */
#define GPIO_PORT_NOT_NOTP31_SHIFT               (31U)                                               /*!< GPIO_PORT_NOT: NOTP31 Position          */
#define GPIO_PORT_NOT_NOTP31(x)                  (((uint32_t)(((uint32_t)(x))<<GPIO_PORT_NOT_NOTP31_SHIFT))&GPIO_PORT_NOT_NOTP31_MASK) /*!< GPIO_PORT_NOT                           */
/**
 * @} */ /* End group GPIO_PORT_Register_Masks_GROUP 
 */

/* GPIO_PORT - Peripheral instance base addresses */
#define GPIO_PORT_BasePtr              0x50000000UL //!< Peripheral base address
#define GPIO_PORT                      ((GPIO_PORT_Type *) GPIO_PORT_BasePtr) //!< Freescale base pointer
#define GPIO_PORT_BASE_PTR             (GPIO_PORT) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C (file:I2C_LPC11Uxx)              ================ */
/* ================================================================================ */

/**
 * @brief I2C-bus controller
 */
/**
* @addtogroup I2C_structs_GROUP I2C struct
* @brief Struct for I2C
* @{
*/
typedef struct {                                /*       I2C Structure                                                */
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
   __IO uint32_t  MASK0;                        /**< 0030: I2C Slave address mask register. This mask register is associated with I2ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (zero) */
   __IO uint32_t  MASK1;                        /**< 0034: I2C Slave address mask register. This mask register is associated with I2ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (zero) */
   __IO uint32_t  MASK2;                        /**< 0038: I2C Slave address mask register. This mask register is associated with I2ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (zero) */
   __IO uint32_t  MASK3;                        /**< 003C: I2C Slave address mask register. This mask register is associated with I2ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (zero) */
} I2C_Type;

/**
 * @} */ /* End group I2C_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2C_Register_Masks_GROUP I2C Register Masks
* @brief Register Masks for I2C
* @{
*/
/* ------- CONSET Bit Fields                        ------ */
#define I2C_CONSET_AA_MASK                       (0x4U)                                              /*!< I2C_CONSET: AA Mask                     */
#define I2C_CONSET_AA_SHIFT                      (2U)                                                /*!< I2C_CONSET: AA Position                 */
#define I2C_CONSET_AA(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CONSET_AA_SHIFT))&I2C_CONSET_AA_MASK) /*!< I2C_CONSET                              */
#define I2C_CONSET_SI_MASK                       (0x8U)                                              /*!< I2C_CONSET: SI Mask                     */
#define I2C_CONSET_SI_SHIFT                      (3U)                                                /*!< I2C_CONSET: SI Position                 */
#define I2C_CONSET_SI(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_CONSET_SI_SHIFT))&I2C_CONSET_SI_MASK) /*!< I2C_CONSET                              */
#define I2C_CONSET_STO_MASK                      (0x10U)                                             /*!< I2C_CONSET: STO Mask                    */
#define I2C_CONSET_STO_SHIFT                     (4U)                                                /*!< I2C_CONSET: STO Position                */
#define I2C_CONSET_STO(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CONSET_STO_SHIFT))&I2C_CONSET_STO_MASK) /*!< I2C_CONSET                              */
#define I2C_CONSET_STA_MASK                      (0x20U)                                             /*!< I2C_CONSET: STA Mask                    */
#define I2C_CONSET_STA_SHIFT                     (5U)                                                /*!< I2C_CONSET: STA Position                */
#define I2C_CONSET_STA(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CONSET_STA_SHIFT))&I2C_CONSET_STA_MASK) /*!< I2C_CONSET                              */
#define I2C_CONSET_I2EN_MASK                     (0x40U)                                             /*!< I2C_CONSET: I2EN Mask                   */
#define I2C_CONSET_I2EN_SHIFT                    (6U)                                                /*!< I2C_CONSET: I2EN Position               */
#define I2C_CONSET_I2EN(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_CONSET_I2EN_SHIFT))&I2C_CONSET_I2EN_MASK) /*!< I2C_CONSET                              */
/* ------- STAT Bit Fields                          ------ */
#define I2C_STAT_Status_MASK                     (0xF8U)                                             /*!< I2C_STAT: Status Mask                   */
#define I2C_STAT_Status_SHIFT                    (3U)                                                /*!< I2C_STAT: Status Position               */
#define I2C_STAT_Status(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_STAT_Status_SHIFT))&I2C_STAT_Status_MASK) /*!< I2C_STAT                                */
/* ------- DAT Bit Fields                           ------ */
#define I2C_DAT_Data_MASK                        (0xFFU)                                             /*!< I2C_DAT: Data Mask                      */
#define I2C_DAT_Data_SHIFT                       (0U)                                                /*!< I2C_DAT: Data Position                  */
#define I2C_DAT_Data(x)                          (((uint32_t)(((uint32_t)(x))<<I2C_DAT_Data_SHIFT))&I2C_DAT_Data_MASK) /*!< I2C_DAT                                 */
/* ------- ADR0 Bit Fields                          ------ */
#define I2C_ADR0_GC_MASK                         (0x1U)                                              /*!< I2C_ADR0: GC Mask                       */
#define I2C_ADR0_GC_SHIFT                        (0U)                                                /*!< I2C_ADR0: GC Position                   */
#define I2C_ADR0_GC(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_ADR0_GC_SHIFT))&I2C_ADR0_GC_MASK) /*!< I2C_ADR0                                */
#define I2C_ADR0_Address_MASK                    (0xFEU)                                             /*!< I2C_ADR0: Address Mask                  */
#define I2C_ADR0_Address_SHIFT                   (1U)                                                /*!< I2C_ADR0: Address Position              */
#define I2C_ADR0_Address(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_ADR0_Address_SHIFT))&I2C_ADR0_Address_MASK) /*!< I2C_ADR0                                */
/* ------- SCLH Bit Fields                          ------ */
#define I2C_SCLH_SCLH_MASK                       (0xFFFFU)                                           /*!< I2C_SCLH: SCLH Mask                     */
#define I2C_SCLH_SCLH_SHIFT                      (0U)                                                /*!< I2C_SCLH: SCLH Position                 */
#define I2C_SCLH_SCLH(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_SCLH_SCLH_SHIFT))&I2C_SCLH_SCLH_MASK) /*!< I2C_SCLH                                */
/* ------- SCLL Bit Fields                          ------ */
#define I2C_SCLL_SCLL_MASK                       (0xFFFFU)                                           /*!< I2C_SCLL: SCLL Mask                     */
#define I2C_SCLL_SCLL_SHIFT                      (0U)                                                /*!< I2C_SCLL: SCLL Position                 */
#define I2C_SCLL_SCLL(x)                         (((uint32_t)(((uint32_t)(x))<<I2C_SCLL_SCLL_SHIFT))&I2C_SCLL_SCLL_MASK) /*!< I2C_SCLL                                */
/* ------- CONCLR Bit Fields                        ------ */
#define I2C_CONCLR_AAC_MASK                      (0x4U)                                              /*!< I2C_CONCLR: AAC Mask                    */
#define I2C_CONCLR_AAC_SHIFT                     (2U)                                                /*!< I2C_CONCLR: AAC Position                */
#define I2C_CONCLR_AAC(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CONCLR_AAC_SHIFT))&I2C_CONCLR_AAC_MASK) /*!< I2C_CONCLR                              */
#define I2C_CONCLR_SIC_MASK                      (0x8U)                                              /*!< I2C_CONCLR: SIC Mask                    */
#define I2C_CONCLR_SIC_SHIFT                     (3U)                                                /*!< I2C_CONCLR: SIC Position                */
#define I2C_CONCLR_SIC(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_CONCLR_SIC_SHIFT))&I2C_CONCLR_SIC_MASK) /*!< I2C_CONCLR                              */
#define I2C_CONCLR_STAC_MASK                     (0x20U)                                             /*!< I2C_CONCLR: STAC Mask                   */
#define I2C_CONCLR_STAC_SHIFT                    (5U)                                                /*!< I2C_CONCLR: STAC Position               */
#define I2C_CONCLR_STAC(x)                       (((uint32_t)(((uint32_t)(x))<<I2C_CONCLR_STAC_SHIFT))&I2C_CONCLR_STAC_MASK) /*!< I2C_CONCLR                              */
#define I2C_CONCLR_I2ENC_MASK                    (0x40U)                                             /*!< I2C_CONCLR: I2ENC Mask                  */
#define I2C_CONCLR_I2ENC_SHIFT                   (6U)                                                /*!< I2C_CONCLR: I2ENC Position              */
#define I2C_CONCLR_I2ENC(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_CONCLR_I2ENC_SHIFT))&I2C_CONCLR_I2ENC_MASK) /*!< I2C_CONCLR                              */
/* ------- MMCTRL Bit Fields                        ------ */
#define I2C_MMCTRL_MM_ENA_MASK                   (0x1U)                                              /*!< I2C_MMCTRL: MM_ENA Mask                 */
#define I2C_MMCTRL_MM_ENA_SHIFT                  (0U)                                                /*!< I2C_MMCTRL: MM_ENA Position             */
#define I2C_MMCTRL_MM_ENA(x)                     (((uint32_t)(((uint32_t)(x))<<I2C_MMCTRL_MM_ENA_SHIFT))&I2C_MMCTRL_MM_ENA_MASK) /*!< I2C_MMCTRL                              */
#define I2C_MMCTRL_ENA_SCL_MASK                  (0x2U)                                              /*!< I2C_MMCTRL: ENA_SCL Mask                */
#define I2C_MMCTRL_ENA_SCL_SHIFT                 (1U)                                                /*!< I2C_MMCTRL: ENA_SCL Position            */
#define I2C_MMCTRL_ENA_SCL(x)                    (((uint32_t)(((uint32_t)(x))<<I2C_MMCTRL_ENA_SCL_SHIFT))&I2C_MMCTRL_ENA_SCL_MASK) /*!< I2C_MMCTRL                              */
#define I2C_MMCTRL_MATCH_ALL_MASK                (0x4U)                                              /*!< I2C_MMCTRL: MATCH_ALL Mask              */
#define I2C_MMCTRL_MATCH_ALL_SHIFT               (2U)                                                /*!< I2C_MMCTRL: MATCH_ALL Position          */
#define I2C_MMCTRL_MATCH_ALL(x)                  (((uint32_t)(((uint32_t)(x))<<I2C_MMCTRL_MATCH_ALL_SHIFT))&I2C_MMCTRL_MATCH_ALL_MASK) /*!< I2C_MMCTRL                              */
/* ------- ADR1 Bit Fields                          ------ */
#define I2C_ADR1_GC_MASK                         (0x1U)                                              /*!< I2C_ADR1: GC Mask                       */
#define I2C_ADR1_GC_SHIFT                        (0U)                                                /*!< I2C_ADR1: GC Position                   */
#define I2C_ADR1_GC(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_ADR1_GC_SHIFT))&I2C_ADR1_GC_MASK) /*!< I2C_ADR1                                */
#define I2C_ADR1_Address_MASK                    (0xFEU)                                             /*!< I2C_ADR1: Address Mask                  */
#define I2C_ADR1_Address_SHIFT                   (1U)                                                /*!< I2C_ADR1: Address Position              */
#define I2C_ADR1_Address(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_ADR1_Address_SHIFT))&I2C_ADR1_Address_MASK) /*!< I2C_ADR1                                */
/* ------- ADR2 Bit Fields                          ------ */
#define I2C_ADR2_GC_MASK                         (0x1U)                                              /*!< I2C_ADR2: GC Mask                       */
#define I2C_ADR2_GC_SHIFT                        (0U)                                                /*!< I2C_ADR2: GC Position                   */
#define I2C_ADR2_GC(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_ADR2_GC_SHIFT))&I2C_ADR2_GC_MASK) /*!< I2C_ADR2                                */
#define I2C_ADR2_Address_MASK                    (0xFEU)                                             /*!< I2C_ADR2: Address Mask                  */
#define I2C_ADR2_Address_SHIFT                   (1U)                                                /*!< I2C_ADR2: Address Position              */
#define I2C_ADR2_Address(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_ADR2_Address_SHIFT))&I2C_ADR2_Address_MASK) /*!< I2C_ADR2                                */
/* ------- ADR3 Bit Fields                          ------ */
#define I2C_ADR3_GC_MASK                         (0x1U)                                              /*!< I2C_ADR3: GC Mask                       */
#define I2C_ADR3_GC_SHIFT                        (0U)                                                /*!< I2C_ADR3: GC Position                   */
#define I2C_ADR3_GC(x)                           (((uint32_t)(((uint32_t)(x))<<I2C_ADR3_GC_SHIFT))&I2C_ADR3_GC_MASK) /*!< I2C_ADR3                                */
#define I2C_ADR3_Address_MASK                    (0xFEU)                                             /*!< I2C_ADR3: Address Mask                  */
#define I2C_ADR3_Address_SHIFT                   (1U)                                                /*!< I2C_ADR3: Address Position              */
#define I2C_ADR3_Address(x)                      (((uint32_t)(((uint32_t)(x))<<I2C_ADR3_Address_SHIFT))&I2C_ADR3_Address_MASK) /*!< I2C_ADR3                                */
/* ------- DATA_BUFFER Bit Fields                   ------ */
#define I2C_DATA_BUFFER_Data_MASK                (0xFFU)                                             /*!< I2C_DATA_BUFFER: Data Mask              */
#define I2C_DATA_BUFFER_Data_SHIFT               (0U)                                                /*!< I2C_DATA_BUFFER: Data Position          */
#define I2C_DATA_BUFFER_Data(x)                  (((uint32_t)(((uint32_t)(x))<<I2C_DATA_BUFFER_Data_SHIFT))&I2C_DATA_BUFFER_Data_MASK) /*!< I2C_DATA_BUFFER                         */
/* ------- MASK0 Bit Fields                         ------ */
#define I2C_MASK0_MASK_MASK                      (0xFEU)                                             /*!< I2C_MASK0: MASK Mask                    */
#define I2C_MASK0_MASK_SHIFT                     (1U)                                                /*!< I2C_MASK0: MASK Position                */
#define I2C_MASK0_MASK(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_MASK0_MASK_SHIFT))&I2C_MASK0_MASK_MASK) /*!< I2C_MASK0                               */
/* ------- MASK1 Bit Fields                         ------ */
#define I2C_MASK1_MASK_MASK                      (0xFEU)                                             /*!< I2C_MASK1: MASK Mask                    */
#define I2C_MASK1_MASK_SHIFT                     (1U)                                                /*!< I2C_MASK1: MASK Position                */
#define I2C_MASK1_MASK(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_MASK1_MASK_SHIFT))&I2C_MASK1_MASK_MASK) /*!< I2C_MASK1                               */
/* ------- MASK2 Bit Fields                         ------ */
#define I2C_MASK2_MASK_MASK                      (0xFEU)                                             /*!< I2C_MASK2: MASK Mask                    */
#define I2C_MASK2_MASK_SHIFT                     (1U)                                                /*!< I2C_MASK2: MASK Position                */
#define I2C_MASK2_MASK(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_MASK2_MASK_SHIFT))&I2C_MASK2_MASK_MASK) /*!< I2C_MASK2                               */
/* ------- MASK3 Bit Fields                         ------ */
#define I2C_MASK3_MASK_MASK                      (0xFEU)                                             /*!< I2C_MASK3: MASK Mask                    */
#define I2C_MASK3_MASK_SHIFT                     (1U)                                                /*!< I2C_MASK3: MASK Position                */
#define I2C_MASK3_MASK(x)                        (((uint32_t)(((uint32_t)(x))<<I2C_MASK3_MASK_SHIFT))&I2C_MASK3_MASK_MASK) /*!< I2C_MASK3                               */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C - Peripheral instance base addresses */
#define I2C_BasePtr                    0x40000000UL //!< Peripheral base address
#define I2C                            ((I2C_Type *) I2C_BasePtr) //!< Freescale base pointer
#define I2C_BASE_PTR                   (I2C) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup IOCON_Peripheral_access_layer_GROUP IOCON Peripheral Access Layer
* @brief C Struct for IOCON
* @{
*/

/* ================================================================================ */
/* ================           IOCON (file:IOCON_LPC11Uxx)          ================ */
/* ================================================================================ */

/**
 * @brief I/O configuration Modification
 */
/**
* @addtogroup IOCON_structs_GROUP IOCON struct
* @brief Struct for IOCON
* @{
*/
typedef struct {                                /*       IOCON Structure                                              */
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
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  PIO1_31;                      /**< 00DC: I/O configuration for pin PIO1_31                            */
} IOCON_Type;

/**
 * @} */ /* End group IOCON_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'IOCON' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup IOCON_Register_Masks_GROUP IOCON Register Masks
* @brief Register Masks for IOCON
* @{
*/
/* ------- RESET_PIO0_0 Bit Fields                  ------ */
#define IOCON_RESET_PIO0_0_FUNC_MASK             (0x7U)                                              /*!< IOCON_RESET_PIO0_0: FUNC Mask           */
#define IOCON_RESET_PIO0_0_FUNC_SHIFT            (0U)                                                /*!< IOCON_RESET_PIO0_0: FUNC Position       */
#define IOCON_RESET_PIO0_0_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_RESET_PIO0_0_FUNC_SHIFT))&IOCON_RESET_PIO0_0_FUNC_MASK) /*!< IOCON_RESET_PIO0_0                      */
#define IOCON_RESET_PIO0_0_MODE_MASK             (0x18U)                                             /*!< IOCON_RESET_PIO0_0: MODE Mask           */
#define IOCON_RESET_PIO0_0_MODE_SHIFT            (3U)                                                /*!< IOCON_RESET_PIO0_0: MODE Position       */
#define IOCON_RESET_PIO0_0_MODE(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_RESET_PIO0_0_MODE_SHIFT))&IOCON_RESET_PIO0_0_MODE_MASK) /*!< IOCON_RESET_PIO0_0                      */
#define IOCON_RESET_PIO0_0_HYS_MASK              (0x20U)                                             /*!< IOCON_RESET_PIO0_0: HYS Mask            */
#define IOCON_RESET_PIO0_0_HYS_SHIFT             (5U)                                                /*!< IOCON_RESET_PIO0_0: HYS Position        */
#define IOCON_RESET_PIO0_0_HYS(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_RESET_PIO0_0_HYS_SHIFT))&IOCON_RESET_PIO0_0_HYS_MASK) /*!< IOCON_RESET_PIO0_0                      */
#define IOCON_RESET_PIO0_0_INV_MASK              (0x40U)                                             /*!< IOCON_RESET_PIO0_0: INV Mask            */
#define IOCON_RESET_PIO0_0_INV_SHIFT             (6U)                                                /*!< IOCON_RESET_PIO0_0: INV Position        */
#define IOCON_RESET_PIO0_0_INV(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_RESET_PIO0_0_INV_SHIFT))&IOCON_RESET_PIO0_0_INV_MASK) /*!< IOCON_RESET_PIO0_0                      */
#define IOCON_RESET_PIO0_0_OD_MASK               (0x400U)                                            /*!< IOCON_RESET_PIO0_0: OD Mask             */
#define IOCON_RESET_PIO0_0_OD_SHIFT              (10U)                                               /*!< IOCON_RESET_PIO0_0: OD Position         */
#define IOCON_RESET_PIO0_0_OD(x)                 (((uint32_t)(((uint32_t)(x))<<IOCON_RESET_PIO0_0_OD_SHIFT))&IOCON_RESET_PIO0_0_OD_MASK) /*!< IOCON_RESET_PIO0_0                      */
/* ------- PIO0_1 Bit Fields                        ------ */
#define IOCON_PIO0_1_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_1: FUNC Mask                 */
#define IOCON_PIO0_1_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_1: FUNC Position             */
#define IOCON_PIO0_1_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_1_FUNC_SHIFT))&IOCON_PIO0_1_FUNC_MASK) /*!< IOCON_PIO0_1                            */
#define IOCON_PIO0_1_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO0_1: MODE Mask                 */
#define IOCON_PIO0_1_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO0_1: MODE Position             */
#define IOCON_PIO0_1_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_1_MODE_SHIFT))&IOCON_PIO0_1_MODE_MASK) /*!< IOCON_PIO0_1                            */
#define IOCON_PIO0_1_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO0_1: HYS Mask                  */
#define IOCON_PIO0_1_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO0_1: HYS Position              */
#define IOCON_PIO0_1_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_1_HYS_SHIFT))&IOCON_PIO0_1_HYS_MASK) /*!< IOCON_PIO0_1                            */
#define IOCON_PIO0_1_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO0_1: INV Mask                  */
#define IOCON_PIO0_1_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO0_1: INV Position              */
#define IOCON_PIO0_1_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_1_INV_SHIFT))&IOCON_PIO0_1_INV_MASK) /*!< IOCON_PIO0_1                            */
#define IOCON_PIO0_1_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO0_1: OD Mask                   */
#define IOCON_PIO0_1_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO0_1: OD Position               */
#define IOCON_PIO0_1_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_1_OD_SHIFT))&IOCON_PIO0_1_OD_MASK) /*!< IOCON_PIO0_1                            */
/* ------- PIO0_2 Bit Fields                        ------ */
#define IOCON_PIO0_2_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_2: FUNC Mask                 */
#define IOCON_PIO0_2_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_2: FUNC Position             */
#define IOCON_PIO0_2_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_2_FUNC_SHIFT))&IOCON_PIO0_2_FUNC_MASK) /*!< IOCON_PIO0_2                            */
#define IOCON_PIO0_2_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO0_2: MODE Mask                 */
#define IOCON_PIO0_2_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO0_2: MODE Position             */
#define IOCON_PIO0_2_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_2_MODE_SHIFT))&IOCON_PIO0_2_MODE_MASK) /*!< IOCON_PIO0_2                            */
#define IOCON_PIO0_2_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO0_2: HYS Mask                  */
#define IOCON_PIO0_2_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO0_2: HYS Position              */
#define IOCON_PIO0_2_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_2_HYS_SHIFT))&IOCON_PIO0_2_HYS_MASK) /*!< IOCON_PIO0_2                            */
#define IOCON_PIO0_2_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO0_2: INV Mask                  */
#define IOCON_PIO0_2_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO0_2: INV Position              */
#define IOCON_PIO0_2_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_2_INV_SHIFT))&IOCON_PIO0_2_INV_MASK) /*!< IOCON_PIO0_2                            */
#define IOCON_PIO0_2_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO0_2: OD Mask                   */
#define IOCON_PIO0_2_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO0_2: OD Position               */
#define IOCON_PIO0_2_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_2_OD_SHIFT))&IOCON_PIO0_2_OD_MASK) /*!< IOCON_PIO0_2                            */
/* ------- PIO0_3 Bit Fields                        ------ */
#define IOCON_PIO0_3_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_3: FUNC Mask                 */
#define IOCON_PIO0_3_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_3: FUNC Position             */
#define IOCON_PIO0_3_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_3_FUNC_SHIFT))&IOCON_PIO0_3_FUNC_MASK) /*!< IOCON_PIO0_3                            */
#define IOCON_PIO0_3_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO0_3: MODE Mask                 */
#define IOCON_PIO0_3_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO0_3: MODE Position             */
#define IOCON_PIO0_3_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_3_MODE_SHIFT))&IOCON_PIO0_3_MODE_MASK) /*!< IOCON_PIO0_3                            */
#define IOCON_PIO0_3_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO0_3: HYS Mask                  */
#define IOCON_PIO0_3_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO0_3: HYS Position              */
#define IOCON_PIO0_3_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_3_HYS_SHIFT))&IOCON_PIO0_3_HYS_MASK) /*!< IOCON_PIO0_3                            */
#define IOCON_PIO0_3_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO0_3: INV Mask                  */
#define IOCON_PIO0_3_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO0_3: INV Position              */
#define IOCON_PIO0_3_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_3_INV_SHIFT))&IOCON_PIO0_3_INV_MASK) /*!< IOCON_PIO0_3                            */
#define IOCON_PIO0_3_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO0_3: OD Mask                   */
#define IOCON_PIO0_3_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO0_3: OD Position               */
#define IOCON_PIO0_3_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_3_OD_SHIFT))&IOCON_PIO0_3_OD_MASK) /*!< IOCON_PIO0_3                            */
/* ------- PIO0_4 Bit Fields                        ------ */
#define IOCON_PIO0_4_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_4: FUNC Mask                 */
#define IOCON_PIO0_4_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_4: FUNC Position             */
#define IOCON_PIO0_4_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_4_FUNC_SHIFT))&IOCON_PIO0_4_FUNC_MASK) /*!< IOCON_PIO0_4                            */
#define IOCON_PIO0_4_I2CMODE_MASK                (0x300U)                                            /*!< IOCON_PIO0_4: I2CMODE Mask              */
#define IOCON_PIO0_4_I2CMODE_SHIFT               (8U)                                                /*!< IOCON_PIO0_4: I2CMODE Position          */
#define IOCON_PIO0_4_I2CMODE(x)                  (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_4_I2CMODE_SHIFT))&IOCON_PIO0_4_I2CMODE_MASK) /*!< IOCON_PIO0_4                            */
/* ------- PIO0_5 Bit Fields                        ------ */
#define IOCON_PIO0_5_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_5: FUNC Mask                 */
#define IOCON_PIO0_5_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_5: FUNC Position             */
#define IOCON_PIO0_5_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_5_FUNC_SHIFT))&IOCON_PIO0_5_FUNC_MASK) /*!< IOCON_PIO0_5                            */
#define IOCON_PIO0_5_I2CMODE_MASK                (0x300U)                                            /*!< IOCON_PIO0_5: I2CMODE Mask              */
#define IOCON_PIO0_5_I2CMODE_SHIFT               (8U)                                                /*!< IOCON_PIO0_5: I2CMODE Position          */
#define IOCON_PIO0_5_I2CMODE(x)                  (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_5_I2CMODE_SHIFT))&IOCON_PIO0_5_I2CMODE_MASK) /*!< IOCON_PIO0_5                            */
/* ------- PIO0_6 Bit Fields                        ------ */
#define IOCON_PIO0_6_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_6: FUNC Mask                 */
#define IOCON_PIO0_6_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_6: FUNC Position             */
#define IOCON_PIO0_6_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_6_FUNC_SHIFT))&IOCON_PIO0_6_FUNC_MASK) /*!< IOCON_PIO0_6                            */
#define IOCON_PIO0_6_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO0_6: MODE Mask                 */
#define IOCON_PIO0_6_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO0_6: MODE Position             */
#define IOCON_PIO0_6_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_6_MODE_SHIFT))&IOCON_PIO0_6_MODE_MASK) /*!< IOCON_PIO0_6                            */
#define IOCON_PIO0_6_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO0_6: HYS Mask                  */
#define IOCON_PIO0_6_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO0_6: HYS Position              */
#define IOCON_PIO0_6_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_6_HYS_SHIFT))&IOCON_PIO0_6_HYS_MASK) /*!< IOCON_PIO0_6                            */
#define IOCON_PIO0_6_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO0_6: INV Mask                  */
#define IOCON_PIO0_6_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO0_6: INV Position              */
#define IOCON_PIO0_6_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_6_INV_SHIFT))&IOCON_PIO0_6_INV_MASK) /*!< IOCON_PIO0_6                            */
#define IOCON_PIO0_6_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO0_6: OD Mask                   */
#define IOCON_PIO0_6_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO0_6: OD Position               */
#define IOCON_PIO0_6_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_6_OD_SHIFT))&IOCON_PIO0_6_OD_MASK) /*!< IOCON_PIO0_6                            */
/* ------- PIO0_7 Bit Fields                        ------ */
#define IOCON_PIO0_7_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_7: FUNC Mask                 */
#define IOCON_PIO0_7_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_7: FUNC Position             */
#define IOCON_PIO0_7_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_7_FUNC_SHIFT))&IOCON_PIO0_7_FUNC_MASK) /*!< IOCON_PIO0_7                            */
#define IOCON_PIO0_7_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO0_7: MODE Mask                 */
#define IOCON_PIO0_7_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO0_7: MODE Position             */
#define IOCON_PIO0_7_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_7_MODE_SHIFT))&IOCON_PIO0_7_MODE_MASK) /*!< IOCON_PIO0_7                            */
#define IOCON_PIO0_7_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO0_7: HYS Mask                  */
#define IOCON_PIO0_7_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO0_7: HYS Position              */
#define IOCON_PIO0_7_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_7_HYS_SHIFT))&IOCON_PIO0_7_HYS_MASK) /*!< IOCON_PIO0_7                            */
#define IOCON_PIO0_7_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO0_7: INV Mask                  */
#define IOCON_PIO0_7_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO0_7: INV Position              */
#define IOCON_PIO0_7_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_7_INV_SHIFT))&IOCON_PIO0_7_INV_MASK) /*!< IOCON_PIO0_7                            */
#define IOCON_PIO0_7_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO0_7: OD Mask                   */
#define IOCON_PIO0_7_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO0_7: OD Position               */
#define IOCON_PIO0_7_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_7_OD_SHIFT))&IOCON_PIO0_7_OD_MASK) /*!< IOCON_PIO0_7                            */
/* ------- PIO0_8 Bit Fields                        ------ */
#define IOCON_PIO0_8_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_8: FUNC Mask                 */
#define IOCON_PIO0_8_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_8: FUNC Position             */
#define IOCON_PIO0_8_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_8_FUNC_SHIFT))&IOCON_PIO0_8_FUNC_MASK) /*!< IOCON_PIO0_8                            */
#define IOCON_PIO0_8_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO0_8: MODE Mask                 */
#define IOCON_PIO0_8_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO0_8: MODE Position             */
#define IOCON_PIO0_8_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_8_MODE_SHIFT))&IOCON_PIO0_8_MODE_MASK) /*!< IOCON_PIO0_8                            */
#define IOCON_PIO0_8_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO0_8: HYS Mask                  */
#define IOCON_PIO0_8_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO0_8: HYS Position              */
#define IOCON_PIO0_8_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_8_HYS_SHIFT))&IOCON_PIO0_8_HYS_MASK) /*!< IOCON_PIO0_8                            */
#define IOCON_PIO0_8_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO0_8: INV Mask                  */
#define IOCON_PIO0_8_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO0_8: INV Position              */
#define IOCON_PIO0_8_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_8_INV_SHIFT))&IOCON_PIO0_8_INV_MASK) /*!< IOCON_PIO0_8                            */
#define IOCON_PIO0_8_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO0_8: OD Mask                   */
#define IOCON_PIO0_8_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO0_8: OD Position               */
#define IOCON_PIO0_8_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_8_OD_SHIFT))&IOCON_PIO0_8_OD_MASK) /*!< IOCON_PIO0_8                            */
/* ------- PIO0_9 Bit Fields                        ------ */
#define IOCON_PIO0_9_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO0_9: FUNC Mask                 */
#define IOCON_PIO0_9_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO0_9: FUNC Position             */
#define IOCON_PIO0_9_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_9_FUNC_SHIFT))&IOCON_PIO0_9_FUNC_MASK) /*!< IOCON_PIO0_9                            */
#define IOCON_PIO0_9_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO0_9: MODE Mask                 */
#define IOCON_PIO0_9_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO0_9: MODE Position             */
#define IOCON_PIO0_9_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_9_MODE_SHIFT))&IOCON_PIO0_9_MODE_MASK) /*!< IOCON_PIO0_9                            */
#define IOCON_PIO0_9_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO0_9: HYS Mask                  */
#define IOCON_PIO0_9_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO0_9: HYS Position              */
#define IOCON_PIO0_9_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_9_HYS_SHIFT))&IOCON_PIO0_9_HYS_MASK) /*!< IOCON_PIO0_9                            */
#define IOCON_PIO0_9_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO0_9: INV Mask                  */
#define IOCON_PIO0_9_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO0_9: INV Position              */
#define IOCON_PIO0_9_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_9_INV_SHIFT))&IOCON_PIO0_9_INV_MASK) /*!< IOCON_PIO0_9                            */
#define IOCON_PIO0_9_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO0_9: OD Mask                   */
#define IOCON_PIO0_9_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO0_9: OD Position               */
#define IOCON_PIO0_9_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_9_OD_SHIFT))&IOCON_PIO0_9_OD_MASK) /*!< IOCON_PIO0_9                            */
/* ------- SWCLK_PIO0_10 Bit Fields                 ------ */
#define IOCON_SWCLK_PIO0_10_FUNC_MASK            (0x7U)                                              /*!< IOCON_SWCLK_PIO0_10: FUNC Mask          */
#define IOCON_SWCLK_PIO0_10_FUNC_SHIFT           (0U)                                                /*!< IOCON_SWCLK_PIO0_10: FUNC Position      */
#define IOCON_SWCLK_PIO0_10_FUNC(x)              (((uint32_t)(((uint32_t)(x))<<IOCON_SWCLK_PIO0_10_FUNC_SHIFT))&IOCON_SWCLK_PIO0_10_FUNC_MASK) /*!< IOCON_SWCLK_PIO0_10                     */
#define IOCON_SWCLK_PIO0_10_MODE_MASK            (0x18U)                                             /*!< IOCON_SWCLK_PIO0_10: MODE Mask          */
#define IOCON_SWCLK_PIO0_10_MODE_SHIFT           (3U)                                                /*!< IOCON_SWCLK_PIO0_10: MODE Position      */
#define IOCON_SWCLK_PIO0_10_MODE(x)              (((uint32_t)(((uint32_t)(x))<<IOCON_SWCLK_PIO0_10_MODE_SHIFT))&IOCON_SWCLK_PIO0_10_MODE_MASK) /*!< IOCON_SWCLK_PIO0_10                     */
#define IOCON_SWCLK_PIO0_10_HYS_MASK             (0x20U)                                             /*!< IOCON_SWCLK_PIO0_10: HYS Mask           */
#define IOCON_SWCLK_PIO0_10_HYS_SHIFT            (5U)                                                /*!< IOCON_SWCLK_PIO0_10: HYS Position       */
#define IOCON_SWCLK_PIO0_10_HYS(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_SWCLK_PIO0_10_HYS_SHIFT))&IOCON_SWCLK_PIO0_10_HYS_MASK) /*!< IOCON_SWCLK_PIO0_10                     */
#define IOCON_SWCLK_PIO0_10_INV_MASK             (0x40U)                                             /*!< IOCON_SWCLK_PIO0_10: INV Mask           */
#define IOCON_SWCLK_PIO0_10_INV_SHIFT            (6U)                                                /*!< IOCON_SWCLK_PIO0_10: INV Position       */
#define IOCON_SWCLK_PIO0_10_INV(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_SWCLK_PIO0_10_INV_SHIFT))&IOCON_SWCLK_PIO0_10_INV_MASK) /*!< IOCON_SWCLK_PIO0_10                     */
#define IOCON_SWCLK_PIO0_10_OD_MASK              (0x400U)                                            /*!< IOCON_SWCLK_PIO0_10: OD Mask            */
#define IOCON_SWCLK_PIO0_10_OD_SHIFT             (10U)                                               /*!< IOCON_SWCLK_PIO0_10: OD Position        */
#define IOCON_SWCLK_PIO0_10_OD(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_SWCLK_PIO0_10_OD_SHIFT))&IOCON_SWCLK_PIO0_10_OD_MASK) /*!< IOCON_SWCLK_PIO0_10                     */
/* ------- TDI_PIO0_11 Bit Fields                   ------ */
#define IOCON_TDI_PIO0_11_FUNC_MASK              (0x7U)                                              /*!< IOCON_TDI_PIO0_11: FUNC Mask            */
#define IOCON_TDI_PIO0_11_FUNC_SHIFT             (0U)                                                /*!< IOCON_TDI_PIO0_11: FUNC Position        */
#define IOCON_TDI_PIO0_11_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_TDI_PIO0_11_FUNC_SHIFT))&IOCON_TDI_PIO0_11_FUNC_MASK) /*!< IOCON_TDI_PIO0_11                       */
#define IOCON_TDI_PIO0_11_MODE_MASK              (0x18U)                                             /*!< IOCON_TDI_PIO0_11: MODE Mask            */
#define IOCON_TDI_PIO0_11_MODE_SHIFT             (3U)                                                /*!< IOCON_TDI_PIO0_11: MODE Position        */
#define IOCON_TDI_PIO0_11_MODE(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_TDI_PIO0_11_MODE_SHIFT))&IOCON_TDI_PIO0_11_MODE_MASK) /*!< IOCON_TDI_PIO0_11                       */
#define IOCON_TDI_PIO0_11_HYS_MASK               (0x20U)                                             /*!< IOCON_TDI_PIO0_11: HYS Mask             */
#define IOCON_TDI_PIO0_11_HYS_SHIFT              (5U)                                                /*!< IOCON_TDI_PIO0_11: HYS Position         */
#define IOCON_TDI_PIO0_11_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<IOCON_TDI_PIO0_11_HYS_SHIFT))&IOCON_TDI_PIO0_11_HYS_MASK) /*!< IOCON_TDI_PIO0_11                       */
#define IOCON_TDI_PIO0_11_INV_MASK               (0x40U)                                             /*!< IOCON_TDI_PIO0_11: INV Mask             */
#define IOCON_TDI_PIO0_11_INV_SHIFT              (6U)                                                /*!< IOCON_TDI_PIO0_11: INV Position         */
#define IOCON_TDI_PIO0_11_INV(x)                 (((uint32_t)(((uint32_t)(x))<<IOCON_TDI_PIO0_11_INV_SHIFT))&IOCON_TDI_PIO0_11_INV_MASK) /*!< IOCON_TDI_PIO0_11                       */
#define IOCON_TDI_PIO0_11_ADMODE_MASK            (0x80U)                                             /*!< IOCON_TDI_PIO0_11: ADMODE Mask          */
#define IOCON_TDI_PIO0_11_ADMODE_SHIFT           (7U)                                                /*!< IOCON_TDI_PIO0_11: ADMODE Position      */
#define IOCON_TDI_PIO0_11_ADMODE(x)              (((uint32_t)(((uint32_t)(x))<<IOCON_TDI_PIO0_11_ADMODE_SHIFT))&IOCON_TDI_PIO0_11_ADMODE_MASK) /*!< IOCON_TDI_PIO0_11                       */
#define IOCON_TDI_PIO0_11_FILTR_MASK             (0x100U)                                            /*!< IOCON_TDI_PIO0_11: FILTR Mask           */
#define IOCON_TDI_PIO0_11_FILTR_SHIFT            (8U)                                                /*!< IOCON_TDI_PIO0_11: FILTR Position       */
#define IOCON_TDI_PIO0_11_FILTR(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_TDI_PIO0_11_FILTR_SHIFT))&IOCON_TDI_PIO0_11_FILTR_MASK) /*!< IOCON_TDI_PIO0_11                       */
#define IOCON_TDI_PIO0_11_OD_MASK                (0x400U)                                            /*!< IOCON_TDI_PIO0_11: OD Mask              */
#define IOCON_TDI_PIO0_11_OD_SHIFT               (10U)                                               /*!< IOCON_TDI_PIO0_11: OD Position          */
#define IOCON_TDI_PIO0_11_OD(x)                  (((uint32_t)(((uint32_t)(x))<<IOCON_TDI_PIO0_11_OD_SHIFT))&IOCON_TDI_PIO0_11_OD_MASK) /*!< IOCON_TDI_PIO0_11                       */
/* ------- TMS_PIO0_12 Bit Fields                   ------ */
#define IOCON_TMS_PIO0_12_FUNC_MASK              (0x7U)                                              /*!< IOCON_TMS_PIO0_12: FUNC Mask            */
#define IOCON_TMS_PIO0_12_FUNC_SHIFT             (0U)                                                /*!< IOCON_TMS_PIO0_12: FUNC Position        */
#define IOCON_TMS_PIO0_12_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_TMS_PIO0_12_FUNC_SHIFT))&IOCON_TMS_PIO0_12_FUNC_MASK) /*!< IOCON_TMS_PIO0_12                       */
#define IOCON_TMS_PIO0_12_MODE_MASK              (0x18U)                                             /*!< IOCON_TMS_PIO0_12: MODE Mask            */
#define IOCON_TMS_PIO0_12_MODE_SHIFT             (3U)                                                /*!< IOCON_TMS_PIO0_12: MODE Position        */
#define IOCON_TMS_PIO0_12_MODE(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_TMS_PIO0_12_MODE_SHIFT))&IOCON_TMS_PIO0_12_MODE_MASK) /*!< IOCON_TMS_PIO0_12                       */
#define IOCON_TMS_PIO0_12_HYS_MASK               (0x20U)                                             /*!< IOCON_TMS_PIO0_12: HYS Mask             */
#define IOCON_TMS_PIO0_12_HYS_SHIFT              (5U)                                                /*!< IOCON_TMS_PIO0_12: HYS Position         */
#define IOCON_TMS_PIO0_12_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<IOCON_TMS_PIO0_12_HYS_SHIFT))&IOCON_TMS_PIO0_12_HYS_MASK) /*!< IOCON_TMS_PIO0_12                       */
#define IOCON_TMS_PIO0_12_INV_MASK               (0x40U)                                             /*!< IOCON_TMS_PIO0_12: INV Mask             */
#define IOCON_TMS_PIO0_12_INV_SHIFT              (6U)                                                /*!< IOCON_TMS_PIO0_12: INV Position         */
#define IOCON_TMS_PIO0_12_INV(x)                 (((uint32_t)(((uint32_t)(x))<<IOCON_TMS_PIO0_12_INV_SHIFT))&IOCON_TMS_PIO0_12_INV_MASK) /*!< IOCON_TMS_PIO0_12                       */
#define IOCON_TMS_PIO0_12_ADMODE_MASK            (0x80U)                                             /*!< IOCON_TMS_PIO0_12: ADMODE Mask          */
#define IOCON_TMS_PIO0_12_ADMODE_SHIFT           (7U)                                                /*!< IOCON_TMS_PIO0_12: ADMODE Position      */
#define IOCON_TMS_PIO0_12_ADMODE(x)              (((uint32_t)(((uint32_t)(x))<<IOCON_TMS_PIO0_12_ADMODE_SHIFT))&IOCON_TMS_PIO0_12_ADMODE_MASK) /*!< IOCON_TMS_PIO0_12                       */
#define IOCON_TMS_PIO0_12_FILTR_MASK             (0x100U)                                            /*!< IOCON_TMS_PIO0_12: FILTR Mask           */
#define IOCON_TMS_PIO0_12_FILTR_SHIFT            (8U)                                                /*!< IOCON_TMS_PIO0_12: FILTR Position       */
#define IOCON_TMS_PIO0_12_FILTR(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_TMS_PIO0_12_FILTR_SHIFT))&IOCON_TMS_PIO0_12_FILTR_MASK) /*!< IOCON_TMS_PIO0_12                       */
#define IOCON_TMS_PIO0_12_OD_MASK                (0x400U)                                            /*!< IOCON_TMS_PIO0_12: OD Mask              */
#define IOCON_TMS_PIO0_12_OD_SHIFT               (10U)                                               /*!< IOCON_TMS_PIO0_12: OD Position          */
#define IOCON_TMS_PIO0_12_OD(x)                  (((uint32_t)(((uint32_t)(x))<<IOCON_TMS_PIO0_12_OD_SHIFT))&IOCON_TMS_PIO0_12_OD_MASK) /*!< IOCON_TMS_PIO0_12                       */
/* ------- TDO_PIO0_13 Bit Fields                   ------ */
#define IOCON_TDO_PIO0_13_FUNC_MASK              (0x7U)                                              /*!< IOCON_TDO_PIO0_13: FUNC Mask            */
#define IOCON_TDO_PIO0_13_FUNC_SHIFT             (0U)                                                /*!< IOCON_TDO_PIO0_13: FUNC Position        */
#define IOCON_TDO_PIO0_13_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_TDO_PIO0_13_FUNC_SHIFT))&IOCON_TDO_PIO0_13_FUNC_MASK) /*!< IOCON_TDO_PIO0_13                       */
#define IOCON_TDO_PIO0_13_MODE_MASK              (0x18U)                                             /*!< IOCON_TDO_PIO0_13: MODE Mask            */
#define IOCON_TDO_PIO0_13_MODE_SHIFT             (3U)                                                /*!< IOCON_TDO_PIO0_13: MODE Position        */
#define IOCON_TDO_PIO0_13_MODE(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_TDO_PIO0_13_MODE_SHIFT))&IOCON_TDO_PIO0_13_MODE_MASK) /*!< IOCON_TDO_PIO0_13                       */
#define IOCON_TDO_PIO0_13_HYS_MASK               (0x20U)                                             /*!< IOCON_TDO_PIO0_13: HYS Mask             */
#define IOCON_TDO_PIO0_13_HYS_SHIFT              (5U)                                                /*!< IOCON_TDO_PIO0_13: HYS Position         */
#define IOCON_TDO_PIO0_13_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<IOCON_TDO_PIO0_13_HYS_SHIFT))&IOCON_TDO_PIO0_13_HYS_MASK) /*!< IOCON_TDO_PIO0_13                       */
#define IOCON_TDO_PIO0_13_INV_MASK               (0x40U)                                             /*!< IOCON_TDO_PIO0_13: INV Mask             */
#define IOCON_TDO_PIO0_13_INV_SHIFT              (6U)                                                /*!< IOCON_TDO_PIO0_13: INV Position         */
#define IOCON_TDO_PIO0_13_INV(x)                 (((uint32_t)(((uint32_t)(x))<<IOCON_TDO_PIO0_13_INV_SHIFT))&IOCON_TDO_PIO0_13_INV_MASK) /*!< IOCON_TDO_PIO0_13                       */
#define IOCON_TDO_PIO0_13_ADMODE_MASK            (0x80U)                                             /*!< IOCON_TDO_PIO0_13: ADMODE Mask          */
#define IOCON_TDO_PIO0_13_ADMODE_SHIFT           (7U)                                                /*!< IOCON_TDO_PIO0_13: ADMODE Position      */
#define IOCON_TDO_PIO0_13_ADMODE(x)              (((uint32_t)(((uint32_t)(x))<<IOCON_TDO_PIO0_13_ADMODE_SHIFT))&IOCON_TDO_PIO0_13_ADMODE_MASK) /*!< IOCON_TDO_PIO0_13                       */
#define IOCON_TDO_PIO0_13_FILTR_MASK             (0x100U)                                            /*!< IOCON_TDO_PIO0_13: FILTR Mask           */
#define IOCON_TDO_PIO0_13_FILTR_SHIFT            (8U)                                                /*!< IOCON_TDO_PIO0_13: FILTR Position       */
#define IOCON_TDO_PIO0_13_FILTR(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_TDO_PIO0_13_FILTR_SHIFT))&IOCON_TDO_PIO0_13_FILTR_MASK) /*!< IOCON_TDO_PIO0_13                       */
#define IOCON_TDO_PIO0_13_OD_MASK                (0x400U)                                            /*!< IOCON_TDO_PIO0_13: OD Mask              */
#define IOCON_TDO_PIO0_13_OD_SHIFT               (10U)                                               /*!< IOCON_TDO_PIO0_13: OD Position          */
#define IOCON_TDO_PIO0_13_OD(x)                  (((uint32_t)(((uint32_t)(x))<<IOCON_TDO_PIO0_13_OD_SHIFT))&IOCON_TDO_PIO0_13_OD_MASK) /*!< IOCON_TDO_PIO0_13                       */
/* ------- TRST_PIO0_14 Bit Fields                  ------ */
#define IOCON_TRST_PIO0_14_FUNC_MASK             (0x7U)                                              /*!< IOCON_TRST_PIO0_14: FUNC Mask           */
#define IOCON_TRST_PIO0_14_FUNC_SHIFT            (0U)                                                /*!< IOCON_TRST_PIO0_14: FUNC Position       */
#define IOCON_TRST_PIO0_14_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_TRST_PIO0_14_FUNC_SHIFT))&IOCON_TRST_PIO0_14_FUNC_MASK) /*!< IOCON_TRST_PIO0_14                      */
#define IOCON_TRST_PIO0_14_MODE_MASK             (0x18U)                                             /*!< IOCON_TRST_PIO0_14: MODE Mask           */
#define IOCON_TRST_PIO0_14_MODE_SHIFT            (3U)                                                /*!< IOCON_TRST_PIO0_14: MODE Position       */
#define IOCON_TRST_PIO0_14_MODE(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_TRST_PIO0_14_MODE_SHIFT))&IOCON_TRST_PIO0_14_MODE_MASK) /*!< IOCON_TRST_PIO0_14                      */
#define IOCON_TRST_PIO0_14_HYS_MASK              (0x20U)                                             /*!< IOCON_TRST_PIO0_14: HYS Mask            */
#define IOCON_TRST_PIO0_14_HYS_SHIFT             (5U)                                                /*!< IOCON_TRST_PIO0_14: HYS Position        */
#define IOCON_TRST_PIO0_14_HYS(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_TRST_PIO0_14_HYS_SHIFT))&IOCON_TRST_PIO0_14_HYS_MASK) /*!< IOCON_TRST_PIO0_14                      */
#define IOCON_TRST_PIO0_14_INV_MASK              (0x40U)                                             /*!< IOCON_TRST_PIO0_14: INV Mask            */
#define IOCON_TRST_PIO0_14_INV_SHIFT             (6U)                                                /*!< IOCON_TRST_PIO0_14: INV Position        */
#define IOCON_TRST_PIO0_14_INV(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_TRST_PIO0_14_INV_SHIFT))&IOCON_TRST_PIO0_14_INV_MASK) /*!< IOCON_TRST_PIO0_14                      */
#define IOCON_TRST_PIO0_14_ADMODE_MASK           (0x80U)                                             /*!< IOCON_TRST_PIO0_14: ADMODE Mask         */
#define IOCON_TRST_PIO0_14_ADMODE_SHIFT          (7U)                                                /*!< IOCON_TRST_PIO0_14: ADMODE Position     */
#define IOCON_TRST_PIO0_14_ADMODE(x)             (((uint32_t)(((uint32_t)(x))<<IOCON_TRST_PIO0_14_ADMODE_SHIFT))&IOCON_TRST_PIO0_14_ADMODE_MASK) /*!< IOCON_TRST_PIO0_14                      */
#define IOCON_TRST_PIO0_14_FILTR_MASK            (0x100U)                                            /*!< IOCON_TRST_PIO0_14: FILTR Mask          */
#define IOCON_TRST_PIO0_14_FILTR_SHIFT           (8U)                                                /*!< IOCON_TRST_PIO0_14: FILTR Position      */
#define IOCON_TRST_PIO0_14_FILTR(x)              (((uint32_t)(((uint32_t)(x))<<IOCON_TRST_PIO0_14_FILTR_SHIFT))&IOCON_TRST_PIO0_14_FILTR_MASK) /*!< IOCON_TRST_PIO0_14                      */
#define IOCON_TRST_PIO0_14_OD_MASK               (0x400U)                                            /*!< IOCON_TRST_PIO0_14: OD Mask             */
#define IOCON_TRST_PIO0_14_OD_SHIFT              (10U)                                               /*!< IOCON_TRST_PIO0_14: OD Position         */
#define IOCON_TRST_PIO0_14_OD(x)                 (((uint32_t)(((uint32_t)(x))<<IOCON_TRST_PIO0_14_OD_SHIFT))&IOCON_TRST_PIO0_14_OD_MASK) /*!< IOCON_TRST_PIO0_14                      */
/* ------- SWDIO_PIO0_15 Bit Fields                 ------ */
#define IOCON_SWDIO_PIO0_15_FUNC_MASK            (0x7U)                                              /*!< IOCON_SWDIO_PIO0_15: FUNC Mask          */
#define IOCON_SWDIO_PIO0_15_FUNC_SHIFT           (0U)                                                /*!< IOCON_SWDIO_PIO0_15: FUNC Position      */
#define IOCON_SWDIO_PIO0_15_FUNC(x)              (((uint32_t)(((uint32_t)(x))<<IOCON_SWDIO_PIO0_15_FUNC_SHIFT))&IOCON_SWDIO_PIO0_15_FUNC_MASK) /*!< IOCON_SWDIO_PIO0_15                     */
#define IOCON_SWDIO_PIO0_15_MODE_MASK            (0x18U)                                             /*!< IOCON_SWDIO_PIO0_15: MODE Mask          */
#define IOCON_SWDIO_PIO0_15_MODE_SHIFT           (3U)                                                /*!< IOCON_SWDIO_PIO0_15: MODE Position      */
#define IOCON_SWDIO_PIO0_15_MODE(x)              (((uint32_t)(((uint32_t)(x))<<IOCON_SWDIO_PIO0_15_MODE_SHIFT))&IOCON_SWDIO_PIO0_15_MODE_MASK) /*!< IOCON_SWDIO_PIO0_15                     */
#define IOCON_SWDIO_PIO0_15_HYS_MASK             (0x20U)                                             /*!< IOCON_SWDIO_PIO0_15: HYS Mask           */
#define IOCON_SWDIO_PIO0_15_HYS_SHIFT            (5U)                                                /*!< IOCON_SWDIO_PIO0_15: HYS Position       */
#define IOCON_SWDIO_PIO0_15_HYS(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_SWDIO_PIO0_15_HYS_SHIFT))&IOCON_SWDIO_PIO0_15_HYS_MASK) /*!< IOCON_SWDIO_PIO0_15                     */
#define IOCON_SWDIO_PIO0_15_INV_MASK             (0x40U)                                             /*!< IOCON_SWDIO_PIO0_15: INV Mask           */
#define IOCON_SWDIO_PIO0_15_INV_SHIFT            (6U)                                                /*!< IOCON_SWDIO_PIO0_15: INV Position       */
#define IOCON_SWDIO_PIO0_15_INV(x)               (((uint32_t)(((uint32_t)(x))<<IOCON_SWDIO_PIO0_15_INV_SHIFT))&IOCON_SWDIO_PIO0_15_INV_MASK) /*!< IOCON_SWDIO_PIO0_15                     */
#define IOCON_SWDIO_PIO0_15_ADMODE_MASK          (0x80U)                                             /*!< IOCON_SWDIO_PIO0_15: ADMODE Mask        */
#define IOCON_SWDIO_PIO0_15_ADMODE_SHIFT         (7U)                                                /*!< IOCON_SWDIO_PIO0_15: ADMODE Position    */
#define IOCON_SWDIO_PIO0_15_ADMODE(x)            (((uint32_t)(((uint32_t)(x))<<IOCON_SWDIO_PIO0_15_ADMODE_SHIFT))&IOCON_SWDIO_PIO0_15_ADMODE_MASK) /*!< IOCON_SWDIO_PIO0_15                     */
#define IOCON_SWDIO_PIO0_15_FILTR_MASK           (0x100U)                                            /*!< IOCON_SWDIO_PIO0_15: FILTR Mask         */
#define IOCON_SWDIO_PIO0_15_FILTR_SHIFT          (8U)                                                /*!< IOCON_SWDIO_PIO0_15: FILTR Position     */
#define IOCON_SWDIO_PIO0_15_FILTR(x)             (((uint32_t)(((uint32_t)(x))<<IOCON_SWDIO_PIO0_15_FILTR_SHIFT))&IOCON_SWDIO_PIO0_15_FILTR_MASK) /*!< IOCON_SWDIO_PIO0_15                     */
#define IOCON_SWDIO_PIO0_15_OD_MASK              (0x400U)                                            /*!< IOCON_SWDIO_PIO0_15: OD Mask            */
#define IOCON_SWDIO_PIO0_15_OD_SHIFT             (10U)                                               /*!< IOCON_SWDIO_PIO0_15: OD Position        */
#define IOCON_SWDIO_PIO0_15_OD(x)                (((uint32_t)(((uint32_t)(x))<<IOCON_SWDIO_PIO0_15_OD_SHIFT))&IOCON_SWDIO_PIO0_15_OD_MASK) /*!< IOCON_SWDIO_PIO0_15                     */
/* ------- PIO0_16 Bit Fields                       ------ */
#define IOCON_PIO0_16_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO0_16: FUNC Mask                */
#define IOCON_PIO0_16_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO0_16: FUNC Position            */
#define IOCON_PIO0_16_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_16_FUNC_SHIFT))&IOCON_PIO0_16_FUNC_MASK) /*!< IOCON_PIO0_16                           */
#define IOCON_PIO0_16_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO0_16: MODE Mask                */
#define IOCON_PIO0_16_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO0_16: MODE Position            */
#define IOCON_PIO0_16_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_16_MODE_SHIFT))&IOCON_PIO0_16_MODE_MASK) /*!< IOCON_PIO0_16                           */
#define IOCON_PIO0_16_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO0_16: HYS Mask                 */
#define IOCON_PIO0_16_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO0_16: HYS Position             */
#define IOCON_PIO0_16_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_16_HYS_SHIFT))&IOCON_PIO0_16_HYS_MASK) /*!< IOCON_PIO0_16                           */
#define IOCON_PIO0_16_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO0_16: INV Mask                 */
#define IOCON_PIO0_16_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO0_16: INV Position             */
#define IOCON_PIO0_16_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_16_INV_SHIFT))&IOCON_PIO0_16_INV_MASK) /*!< IOCON_PIO0_16                           */
#define IOCON_PIO0_16_ADMODE_MASK                (0x80U)                                             /*!< IOCON_PIO0_16: ADMODE Mask              */
#define IOCON_PIO0_16_ADMODE_SHIFT               (7U)                                                /*!< IOCON_PIO0_16: ADMODE Position          */
#define IOCON_PIO0_16_ADMODE(x)                  (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_16_ADMODE_SHIFT))&IOCON_PIO0_16_ADMODE_MASK) /*!< IOCON_PIO0_16                           */
#define IOCON_PIO0_16_FILTR_MASK                 (0x100U)                                            /*!< IOCON_PIO0_16: FILTR Mask               */
#define IOCON_PIO0_16_FILTR_SHIFT                (8U)                                                /*!< IOCON_PIO0_16: FILTR Position           */
#define IOCON_PIO0_16_FILTR(x)                   (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_16_FILTR_SHIFT))&IOCON_PIO0_16_FILTR_MASK) /*!< IOCON_PIO0_16                           */
#define IOCON_PIO0_16_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO0_16: OD Mask                  */
#define IOCON_PIO0_16_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO0_16: OD Position              */
#define IOCON_PIO0_16_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_16_OD_SHIFT))&IOCON_PIO0_16_OD_MASK) /*!< IOCON_PIO0_16                           */
/* ------- PIO0_17 Bit Fields                       ------ */
#define IOCON_PIO0_17_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO0_17: FUNC Mask                */
#define IOCON_PIO0_17_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO0_17: FUNC Position            */
#define IOCON_PIO0_17_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_17_FUNC_SHIFT))&IOCON_PIO0_17_FUNC_MASK) /*!< IOCON_PIO0_17                           */
#define IOCON_PIO0_17_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO0_17: MODE Mask                */
#define IOCON_PIO0_17_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO0_17: MODE Position            */
#define IOCON_PIO0_17_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_17_MODE_SHIFT))&IOCON_PIO0_17_MODE_MASK) /*!< IOCON_PIO0_17                           */
#define IOCON_PIO0_17_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO0_17: HYS Mask                 */
#define IOCON_PIO0_17_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO0_17: HYS Position             */
#define IOCON_PIO0_17_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_17_HYS_SHIFT))&IOCON_PIO0_17_HYS_MASK) /*!< IOCON_PIO0_17                           */
#define IOCON_PIO0_17_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO0_17: INV Mask                 */
#define IOCON_PIO0_17_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO0_17: INV Position             */
#define IOCON_PIO0_17_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_17_INV_SHIFT))&IOCON_PIO0_17_INV_MASK) /*!< IOCON_PIO0_17                           */
#define IOCON_PIO0_17_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO0_17: OD Mask                  */
#define IOCON_PIO0_17_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO0_17: OD Position              */
#define IOCON_PIO0_17_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_17_OD_SHIFT))&IOCON_PIO0_17_OD_MASK) /*!< IOCON_PIO0_17                           */
/* ------- PIO0_18 Bit Fields                       ------ */
#define IOCON_PIO0_18_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO0_18: FUNC Mask                */
#define IOCON_PIO0_18_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO0_18: FUNC Position            */
#define IOCON_PIO0_18_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_18_FUNC_SHIFT))&IOCON_PIO0_18_FUNC_MASK) /*!< IOCON_PIO0_18                           */
#define IOCON_PIO0_18_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO0_18: MODE Mask                */
#define IOCON_PIO0_18_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO0_18: MODE Position            */
#define IOCON_PIO0_18_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_18_MODE_SHIFT))&IOCON_PIO0_18_MODE_MASK) /*!< IOCON_PIO0_18                           */
#define IOCON_PIO0_18_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO0_18: HYS Mask                 */
#define IOCON_PIO0_18_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO0_18: HYS Position             */
#define IOCON_PIO0_18_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_18_HYS_SHIFT))&IOCON_PIO0_18_HYS_MASK) /*!< IOCON_PIO0_18                           */
#define IOCON_PIO0_18_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO0_18: INV Mask                 */
#define IOCON_PIO0_18_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO0_18: INV Position             */
#define IOCON_PIO0_18_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_18_INV_SHIFT))&IOCON_PIO0_18_INV_MASK) /*!< IOCON_PIO0_18                           */
#define IOCON_PIO0_18_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO0_18: OD Mask                  */
#define IOCON_PIO0_18_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO0_18: OD Position              */
#define IOCON_PIO0_18_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_18_OD_SHIFT))&IOCON_PIO0_18_OD_MASK) /*!< IOCON_PIO0_18                           */
/* ------- PIO0_19 Bit Fields                       ------ */
#define IOCON_PIO0_19_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO0_19: FUNC Mask                */
#define IOCON_PIO0_19_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO0_19: FUNC Position            */
#define IOCON_PIO0_19_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_19_FUNC_SHIFT))&IOCON_PIO0_19_FUNC_MASK) /*!< IOCON_PIO0_19                           */
#define IOCON_PIO0_19_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO0_19: MODE Mask                */
#define IOCON_PIO0_19_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO0_19: MODE Position            */
#define IOCON_PIO0_19_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_19_MODE_SHIFT))&IOCON_PIO0_19_MODE_MASK) /*!< IOCON_PIO0_19                           */
#define IOCON_PIO0_19_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO0_19: HYS Mask                 */
#define IOCON_PIO0_19_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO0_19: HYS Position             */
#define IOCON_PIO0_19_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_19_HYS_SHIFT))&IOCON_PIO0_19_HYS_MASK) /*!< IOCON_PIO0_19                           */
#define IOCON_PIO0_19_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO0_19: INV Mask                 */
#define IOCON_PIO0_19_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO0_19: INV Position             */
#define IOCON_PIO0_19_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_19_INV_SHIFT))&IOCON_PIO0_19_INV_MASK) /*!< IOCON_PIO0_19                           */
#define IOCON_PIO0_19_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO0_19: OD Mask                  */
#define IOCON_PIO0_19_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO0_19: OD Position              */
#define IOCON_PIO0_19_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_19_OD_SHIFT))&IOCON_PIO0_19_OD_MASK) /*!< IOCON_PIO0_19                           */
/* ------- PIO0_20 Bit Fields                       ------ */
#define IOCON_PIO0_20_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO0_20: FUNC Mask                */
#define IOCON_PIO0_20_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO0_20: FUNC Position            */
#define IOCON_PIO0_20_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_20_FUNC_SHIFT))&IOCON_PIO0_20_FUNC_MASK) /*!< IOCON_PIO0_20                           */
#define IOCON_PIO0_20_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO0_20: MODE Mask                */
#define IOCON_PIO0_20_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO0_20: MODE Position            */
#define IOCON_PIO0_20_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_20_MODE_SHIFT))&IOCON_PIO0_20_MODE_MASK) /*!< IOCON_PIO0_20                           */
#define IOCON_PIO0_20_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO0_20: HYS Mask                 */
#define IOCON_PIO0_20_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO0_20: HYS Position             */
#define IOCON_PIO0_20_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_20_HYS_SHIFT))&IOCON_PIO0_20_HYS_MASK) /*!< IOCON_PIO0_20                           */
#define IOCON_PIO0_20_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO0_20: INV Mask                 */
#define IOCON_PIO0_20_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO0_20: INV Position             */
#define IOCON_PIO0_20_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_20_INV_SHIFT))&IOCON_PIO0_20_INV_MASK) /*!< IOCON_PIO0_20                           */
#define IOCON_PIO0_20_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO0_20: OD Mask                  */
#define IOCON_PIO0_20_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO0_20: OD Position              */
#define IOCON_PIO0_20_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_20_OD_SHIFT))&IOCON_PIO0_20_OD_MASK) /*!< IOCON_PIO0_20                           */
/* ------- PIO0_21 Bit Fields                       ------ */
#define IOCON_PIO0_21_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO0_21: FUNC Mask                */
#define IOCON_PIO0_21_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO0_21: FUNC Position            */
#define IOCON_PIO0_21_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_21_FUNC_SHIFT))&IOCON_PIO0_21_FUNC_MASK) /*!< IOCON_PIO0_21                           */
#define IOCON_PIO0_21_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO0_21: MODE Mask                */
#define IOCON_PIO0_21_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO0_21: MODE Position            */
#define IOCON_PIO0_21_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_21_MODE_SHIFT))&IOCON_PIO0_21_MODE_MASK) /*!< IOCON_PIO0_21                           */
#define IOCON_PIO0_21_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO0_21: HYS Mask                 */
#define IOCON_PIO0_21_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO0_21: HYS Position             */
#define IOCON_PIO0_21_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_21_HYS_SHIFT))&IOCON_PIO0_21_HYS_MASK) /*!< IOCON_PIO0_21                           */
#define IOCON_PIO0_21_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO0_21: INV Mask                 */
#define IOCON_PIO0_21_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO0_21: INV Position             */
#define IOCON_PIO0_21_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_21_INV_SHIFT))&IOCON_PIO0_21_INV_MASK) /*!< IOCON_PIO0_21                           */
#define IOCON_PIO0_21_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO0_21: OD Mask                  */
#define IOCON_PIO0_21_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO0_21: OD Position              */
#define IOCON_PIO0_21_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_21_OD_SHIFT))&IOCON_PIO0_21_OD_MASK) /*!< IOCON_PIO0_21                           */
/* ------- PIO0_22 Bit Fields                       ------ */
#define IOCON_PIO0_22_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO0_22: FUNC Mask                */
#define IOCON_PIO0_22_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO0_22: FUNC Position            */
#define IOCON_PIO0_22_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_22_FUNC_SHIFT))&IOCON_PIO0_22_FUNC_MASK) /*!< IOCON_PIO0_22                           */
#define IOCON_PIO0_22_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO0_22: MODE Mask                */
#define IOCON_PIO0_22_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO0_22: MODE Position            */
#define IOCON_PIO0_22_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_22_MODE_SHIFT))&IOCON_PIO0_22_MODE_MASK) /*!< IOCON_PIO0_22                           */
#define IOCON_PIO0_22_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO0_22: HYS Mask                 */
#define IOCON_PIO0_22_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO0_22: HYS Position             */
#define IOCON_PIO0_22_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_22_HYS_SHIFT))&IOCON_PIO0_22_HYS_MASK) /*!< IOCON_PIO0_22                           */
#define IOCON_PIO0_22_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO0_22: INV Mask                 */
#define IOCON_PIO0_22_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO0_22: INV Position             */
#define IOCON_PIO0_22_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_22_INV_SHIFT))&IOCON_PIO0_22_INV_MASK) /*!< IOCON_PIO0_22                           */
#define IOCON_PIO0_22_ADMODE_MASK                (0x80U)                                             /*!< IOCON_PIO0_22: ADMODE Mask              */
#define IOCON_PIO0_22_ADMODE_SHIFT               (7U)                                                /*!< IOCON_PIO0_22: ADMODE Position          */
#define IOCON_PIO0_22_ADMODE(x)                  (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_22_ADMODE_SHIFT))&IOCON_PIO0_22_ADMODE_MASK) /*!< IOCON_PIO0_22                           */
#define IOCON_PIO0_22_FILTR_MASK                 (0x100U)                                            /*!< IOCON_PIO0_22: FILTR Mask               */
#define IOCON_PIO0_22_FILTR_SHIFT                (8U)                                                /*!< IOCON_PIO0_22: FILTR Position           */
#define IOCON_PIO0_22_FILTR(x)                   (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_22_FILTR_SHIFT))&IOCON_PIO0_22_FILTR_MASK) /*!< IOCON_PIO0_22                           */
#define IOCON_PIO0_22_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO0_22: OD Mask                  */
#define IOCON_PIO0_22_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO0_22: OD Position              */
#define IOCON_PIO0_22_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_22_OD_SHIFT))&IOCON_PIO0_22_OD_MASK) /*!< IOCON_PIO0_22                           */
/* ------- PIO0_23 Bit Fields                       ------ */
#define IOCON_PIO0_23_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO0_23: FUNC Mask                */
#define IOCON_PIO0_23_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO0_23: FUNC Position            */
#define IOCON_PIO0_23_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_23_FUNC_SHIFT))&IOCON_PIO0_23_FUNC_MASK) /*!< IOCON_PIO0_23                           */
#define IOCON_PIO0_23_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO0_23: MODE Mask                */
#define IOCON_PIO0_23_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO0_23: MODE Position            */
#define IOCON_PIO0_23_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_23_MODE_SHIFT))&IOCON_PIO0_23_MODE_MASK) /*!< IOCON_PIO0_23                           */
#define IOCON_PIO0_23_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO0_23: HYS Mask                 */
#define IOCON_PIO0_23_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO0_23: HYS Position             */
#define IOCON_PIO0_23_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_23_HYS_SHIFT))&IOCON_PIO0_23_HYS_MASK) /*!< IOCON_PIO0_23                           */
#define IOCON_PIO0_23_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO0_23: INV Mask                 */
#define IOCON_PIO0_23_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO0_23: INV Position             */
#define IOCON_PIO0_23_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_23_INV_SHIFT))&IOCON_PIO0_23_INV_MASK) /*!< IOCON_PIO0_23                           */
#define IOCON_PIO0_23_ADMODE_MASK                (0x80U)                                             /*!< IOCON_PIO0_23: ADMODE Mask              */
#define IOCON_PIO0_23_ADMODE_SHIFT               (7U)                                                /*!< IOCON_PIO0_23: ADMODE Position          */
#define IOCON_PIO0_23_ADMODE(x)                  (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_23_ADMODE_SHIFT))&IOCON_PIO0_23_ADMODE_MASK) /*!< IOCON_PIO0_23                           */
#define IOCON_PIO0_23_FILTR_MASK                 (0x100U)                                            /*!< IOCON_PIO0_23: FILTR Mask               */
#define IOCON_PIO0_23_FILTR_SHIFT                (8U)                                                /*!< IOCON_PIO0_23: FILTR Position           */
#define IOCON_PIO0_23_FILTR(x)                   (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_23_FILTR_SHIFT))&IOCON_PIO0_23_FILTR_MASK) /*!< IOCON_PIO0_23                           */
#define IOCON_PIO0_23_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO0_23: OD Mask                  */
#define IOCON_PIO0_23_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO0_23: OD Position              */
#define IOCON_PIO0_23_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO0_23_OD_SHIFT))&IOCON_PIO0_23_OD_MASK) /*!< IOCON_PIO0_23                           */
/* ------- PIO1_0 Bit Fields                        ------ */
#define IOCON_PIO1_0_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO1_0: FUNC Mask                 */
#define IOCON_PIO1_0_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO1_0: FUNC Position             */
#define IOCON_PIO1_0_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_0_FUNC_SHIFT))&IOCON_PIO1_0_FUNC_MASK) /*!< IOCON_PIO1_0                            */
#define IOCON_PIO1_0_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO1_0: MODE Mask                 */
#define IOCON_PIO1_0_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO1_0: MODE Position             */
#define IOCON_PIO1_0_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_0_MODE_SHIFT))&IOCON_PIO1_0_MODE_MASK) /*!< IOCON_PIO1_0                            */
#define IOCON_PIO1_0_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO1_0: HYS Mask                  */
#define IOCON_PIO1_0_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO1_0: HYS Position              */
#define IOCON_PIO1_0_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_0_HYS_SHIFT))&IOCON_PIO1_0_HYS_MASK) /*!< IOCON_PIO1_0                            */
#define IOCON_PIO1_0_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO1_0: INV Mask                  */
#define IOCON_PIO1_0_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO1_0: INV Position              */
#define IOCON_PIO1_0_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_0_INV_SHIFT))&IOCON_PIO1_0_INV_MASK) /*!< IOCON_PIO1_0                            */
#define IOCON_PIO1_0_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO1_0: OD Mask                   */
#define IOCON_PIO1_0_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO1_0: OD Position               */
#define IOCON_PIO1_0_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_0_OD_SHIFT))&IOCON_PIO1_0_OD_MASK) /*!< IOCON_PIO1_0                            */
/* ------- PIO1_1 Bit Fields                        ------ */
#define IOCON_PIO1_1_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO1_1: FUNC Mask                 */
#define IOCON_PIO1_1_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO1_1: FUNC Position             */
#define IOCON_PIO1_1_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_1_FUNC_SHIFT))&IOCON_PIO1_1_FUNC_MASK) /*!< IOCON_PIO1_1                            */
#define IOCON_PIO1_1_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO1_1: MODE Mask                 */
#define IOCON_PIO1_1_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO1_1: MODE Position             */
#define IOCON_PIO1_1_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_1_MODE_SHIFT))&IOCON_PIO1_1_MODE_MASK) /*!< IOCON_PIO1_1                            */
#define IOCON_PIO1_1_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO1_1: HYS Mask                  */
#define IOCON_PIO1_1_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO1_1: HYS Position              */
#define IOCON_PIO1_1_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_1_HYS_SHIFT))&IOCON_PIO1_1_HYS_MASK) /*!< IOCON_PIO1_1                            */
#define IOCON_PIO1_1_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO1_1: INV Mask                  */
#define IOCON_PIO1_1_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO1_1: INV Position              */
#define IOCON_PIO1_1_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_1_INV_SHIFT))&IOCON_PIO1_1_INV_MASK) /*!< IOCON_PIO1_1                            */
#define IOCON_PIO1_1_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO1_1: OD Mask                   */
#define IOCON_PIO1_1_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO1_1: OD Position               */
#define IOCON_PIO1_1_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_1_OD_SHIFT))&IOCON_PIO1_1_OD_MASK) /*!< IOCON_PIO1_1                            */
/* ------- PIO1_2 Bit Fields                        ------ */
#define IOCON_PIO1_2_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO1_2: FUNC Mask                 */
#define IOCON_PIO1_2_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO1_2: FUNC Position             */
#define IOCON_PIO1_2_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_2_FUNC_SHIFT))&IOCON_PIO1_2_FUNC_MASK) /*!< IOCON_PIO1_2                            */
#define IOCON_PIO1_2_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO1_2: MODE Mask                 */
#define IOCON_PIO1_2_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO1_2: MODE Position             */
#define IOCON_PIO1_2_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_2_MODE_SHIFT))&IOCON_PIO1_2_MODE_MASK) /*!< IOCON_PIO1_2                            */
#define IOCON_PIO1_2_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO1_2: HYS Mask                  */
#define IOCON_PIO1_2_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO1_2: HYS Position              */
#define IOCON_PIO1_2_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_2_HYS_SHIFT))&IOCON_PIO1_2_HYS_MASK) /*!< IOCON_PIO1_2                            */
#define IOCON_PIO1_2_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO1_2: INV Mask                  */
#define IOCON_PIO1_2_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO1_2: INV Position              */
#define IOCON_PIO1_2_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_2_INV_SHIFT))&IOCON_PIO1_2_INV_MASK) /*!< IOCON_PIO1_2                            */
#define IOCON_PIO1_2_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO1_2: OD Mask                   */
#define IOCON_PIO1_2_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO1_2: OD Position               */
#define IOCON_PIO1_2_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_2_OD_SHIFT))&IOCON_PIO1_2_OD_MASK) /*!< IOCON_PIO1_2                            */
/* ------- PIO1_3 Bit Fields                        ------ */
#define IOCON_PIO1_3_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO1_3: FUNC Mask                 */
#define IOCON_PIO1_3_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO1_3: FUNC Position             */
#define IOCON_PIO1_3_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_3_FUNC_SHIFT))&IOCON_PIO1_3_FUNC_MASK) /*!< IOCON_PIO1_3                            */
#define IOCON_PIO1_3_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO1_3: MODE Mask                 */
#define IOCON_PIO1_3_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO1_3: MODE Position             */
#define IOCON_PIO1_3_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_3_MODE_SHIFT))&IOCON_PIO1_3_MODE_MASK) /*!< IOCON_PIO1_3                            */
#define IOCON_PIO1_3_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO1_3: HYS Mask                  */
#define IOCON_PIO1_3_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO1_3: HYS Position              */
#define IOCON_PIO1_3_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_3_HYS_SHIFT))&IOCON_PIO1_3_HYS_MASK) /*!< IOCON_PIO1_3                            */
#define IOCON_PIO1_3_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO1_3: INV Mask                  */
#define IOCON_PIO1_3_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO1_3: INV Position              */
#define IOCON_PIO1_3_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_3_INV_SHIFT))&IOCON_PIO1_3_INV_MASK) /*!< IOCON_PIO1_3                            */
#define IOCON_PIO1_3_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO1_3: OD Mask                   */
#define IOCON_PIO1_3_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO1_3: OD Position               */
#define IOCON_PIO1_3_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_3_OD_SHIFT))&IOCON_PIO1_3_OD_MASK) /*!< IOCON_PIO1_3                            */
/* ------- PIO1_4 Bit Fields                        ------ */
#define IOCON_PIO1_4_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO1_4: FUNC Mask                 */
#define IOCON_PIO1_4_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO1_4: FUNC Position             */
#define IOCON_PIO1_4_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_4_FUNC_SHIFT))&IOCON_PIO1_4_FUNC_MASK) /*!< IOCON_PIO1_4                            */
#define IOCON_PIO1_4_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO1_4: MODE Mask                 */
#define IOCON_PIO1_4_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO1_4: MODE Position             */
#define IOCON_PIO1_4_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_4_MODE_SHIFT))&IOCON_PIO1_4_MODE_MASK) /*!< IOCON_PIO1_4                            */
#define IOCON_PIO1_4_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO1_4: HYS Mask                  */
#define IOCON_PIO1_4_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO1_4: HYS Position              */
#define IOCON_PIO1_4_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_4_HYS_SHIFT))&IOCON_PIO1_4_HYS_MASK) /*!< IOCON_PIO1_4                            */
#define IOCON_PIO1_4_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO1_4: INV Mask                  */
#define IOCON_PIO1_4_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO1_4: INV Position              */
#define IOCON_PIO1_4_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_4_INV_SHIFT))&IOCON_PIO1_4_INV_MASK) /*!< IOCON_PIO1_4                            */
#define IOCON_PIO1_4_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO1_4: OD Mask                   */
#define IOCON_PIO1_4_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO1_4: OD Position               */
#define IOCON_PIO1_4_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_4_OD_SHIFT))&IOCON_PIO1_4_OD_MASK) /*!< IOCON_PIO1_4                            */
/* ------- PIO1_5 Bit Fields                        ------ */
#define IOCON_PIO1_5_FUNC_MASK                   (0x7U)                                              /*!< IOCON_PIO1_5: FUNC Mask                 */
#define IOCON_PIO1_5_FUNC_SHIFT                  (0U)                                                /*!< IOCON_PIO1_5: FUNC Position             */
#define IOCON_PIO1_5_FUNC(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_5_FUNC_SHIFT))&IOCON_PIO1_5_FUNC_MASK) /*!< IOCON_PIO1_5                            */
#define IOCON_PIO1_5_MODE_MASK                   (0x18U)                                             /*!< IOCON_PIO1_5: MODE Mask                 */
#define IOCON_PIO1_5_MODE_SHIFT                  (3U)                                                /*!< IOCON_PIO1_5: MODE Position             */
#define IOCON_PIO1_5_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_5_MODE_SHIFT))&IOCON_PIO1_5_MODE_MASK) /*!< IOCON_PIO1_5                            */
#define IOCON_PIO1_5_HYS_MASK                    (0x20U)                                             /*!< IOCON_PIO1_5: HYS Mask                  */
#define IOCON_PIO1_5_HYS_SHIFT                   (5U)                                                /*!< IOCON_PIO1_5: HYS Position              */
#define IOCON_PIO1_5_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_5_HYS_SHIFT))&IOCON_PIO1_5_HYS_MASK) /*!< IOCON_PIO1_5                            */
#define IOCON_PIO1_5_INV_MASK                    (0x40U)                                             /*!< IOCON_PIO1_5: INV Mask                  */
#define IOCON_PIO1_5_INV_SHIFT                   (6U)                                                /*!< IOCON_PIO1_5: INV Position              */
#define IOCON_PIO1_5_INV(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_5_INV_SHIFT))&IOCON_PIO1_5_INV_MASK) /*!< IOCON_PIO1_5                            */
#define IOCON_PIO1_5_OD_MASK                     (0x400U)                                            /*!< IOCON_PIO1_5: OD Mask                   */
#define IOCON_PIO1_5_OD_SHIFT                    (10U)                                               /*!< IOCON_PIO1_5: OD Position               */
#define IOCON_PIO1_5_OD(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_5_OD_SHIFT))&IOCON_PIO1_5_OD_MASK) /*!< IOCON_PIO1_5                            */
/* ------- PIO1_ Bit Fields                         ------ */
#define IOCON_PIO1__FUNC_MASK                    (0x7U)                                              /*!< IOCON_PIO1_: FUNC Mask                  */
#define IOCON_PIO1__FUNC_SHIFT                   (0U)                                                /*!< IOCON_PIO1_: FUNC Position              */
#define IOCON_PIO1__FUNC(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1__FUNC_SHIFT))&IOCON_PIO1__FUNC_MASK) /*!< IOCON_PIO1_                             */
#define IOCON_PIO1__MODE_MASK                    (0x18U)                                             /*!< IOCON_PIO1_: MODE Mask                  */
#define IOCON_PIO1__MODE_SHIFT                   (3U)                                                /*!< IOCON_PIO1_: MODE Position              */
#define IOCON_PIO1__MODE(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1__MODE_SHIFT))&IOCON_PIO1__MODE_MASK) /*!< IOCON_PIO1_                             */
#define IOCON_PIO1__HYS_MASK                     (0x20U)                                             /*!< IOCON_PIO1_: HYS Mask                   */
#define IOCON_PIO1__HYS_SHIFT                    (5U)                                                /*!< IOCON_PIO1_: HYS Position               */
#define IOCON_PIO1__HYS(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1__HYS_SHIFT))&IOCON_PIO1__HYS_MASK) /*!< IOCON_PIO1_                             */
#define IOCON_PIO1__INV_MASK                     (0x40U)                                             /*!< IOCON_PIO1_: INV Mask                   */
#define IOCON_PIO1__INV_SHIFT                    (6U)                                                /*!< IOCON_PIO1_: INV Position               */
#define IOCON_PIO1__INV(x)                       (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1__INV_SHIFT))&IOCON_PIO1__INV_MASK) /*!< IOCON_PIO1_                             */
#define IOCON_PIO1__OD_MASK                      (0x400U)                                            /*!< IOCON_PIO1_: OD Mask                    */
#define IOCON_PIO1__OD_SHIFT                     (10U)                                               /*!< IOCON_PIO1_: OD Position                */
#define IOCON_PIO1__OD(x)                        (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1__OD_SHIFT))&IOCON_PIO1__OD_MASK) /*!< IOCON_PIO1_                             */
/* ------- PIO1_13 Bit Fields                       ------ */
#define IOCON_PIO1_13_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_13: FUNC Mask                */
#define IOCON_PIO1_13_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_13: FUNC Position            */
#define IOCON_PIO1_13_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_13_FUNC_SHIFT))&IOCON_PIO1_13_FUNC_MASK) /*!< IOCON_PIO1_13                           */
#define IOCON_PIO1_13_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_13: MODE Mask                */
#define IOCON_PIO1_13_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_13: MODE Position            */
#define IOCON_PIO1_13_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_13_MODE_SHIFT))&IOCON_PIO1_13_MODE_MASK) /*!< IOCON_PIO1_13                           */
#define IOCON_PIO1_13_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_13: HYS Mask                 */
#define IOCON_PIO1_13_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_13: HYS Position             */
#define IOCON_PIO1_13_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_13_HYS_SHIFT))&IOCON_PIO1_13_HYS_MASK) /*!< IOCON_PIO1_13                           */
#define IOCON_PIO1_13_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_13: INV Mask                 */
#define IOCON_PIO1_13_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_13: INV Position             */
#define IOCON_PIO1_13_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_13_INV_SHIFT))&IOCON_PIO1_13_INV_MASK) /*!< IOCON_PIO1_13                           */
#define IOCON_PIO1_13_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_13: OD Mask                  */
#define IOCON_PIO1_13_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_13: OD Position              */
#define IOCON_PIO1_13_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_13_OD_SHIFT))&IOCON_PIO1_13_OD_MASK) /*!< IOCON_PIO1_13                           */
/* ------- PIO1_14 Bit Fields                       ------ */
#define IOCON_PIO1_14_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_14: FUNC Mask                */
#define IOCON_PIO1_14_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_14: FUNC Position            */
#define IOCON_PIO1_14_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_14_FUNC_SHIFT))&IOCON_PIO1_14_FUNC_MASK) /*!< IOCON_PIO1_14                           */
#define IOCON_PIO1_14_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_14: MODE Mask                */
#define IOCON_PIO1_14_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_14: MODE Position            */
#define IOCON_PIO1_14_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_14_MODE_SHIFT))&IOCON_PIO1_14_MODE_MASK) /*!< IOCON_PIO1_14                           */
#define IOCON_PIO1_14_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_14: HYS Mask                 */
#define IOCON_PIO1_14_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_14: HYS Position             */
#define IOCON_PIO1_14_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_14_HYS_SHIFT))&IOCON_PIO1_14_HYS_MASK) /*!< IOCON_PIO1_14                           */
#define IOCON_PIO1_14_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_14: INV Mask                 */
#define IOCON_PIO1_14_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_14: INV Position             */
#define IOCON_PIO1_14_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_14_INV_SHIFT))&IOCON_PIO1_14_INV_MASK) /*!< IOCON_PIO1_14                           */
#define IOCON_PIO1_14_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_14: OD Mask                  */
#define IOCON_PIO1_14_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_14: OD Position              */
#define IOCON_PIO1_14_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_14_OD_SHIFT))&IOCON_PIO1_14_OD_MASK) /*!< IOCON_PIO1_14                           */
/* ------- PIO1_15 Bit Fields                       ------ */
#define IOCON_PIO1_15_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_15: FUNC Mask                */
#define IOCON_PIO1_15_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_15: FUNC Position            */
#define IOCON_PIO1_15_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_15_FUNC_SHIFT))&IOCON_PIO1_15_FUNC_MASK) /*!< IOCON_PIO1_15                           */
#define IOCON_PIO1_15_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_15: MODE Mask                */
#define IOCON_PIO1_15_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_15: MODE Position            */
#define IOCON_PIO1_15_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_15_MODE_SHIFT))&IOCON_PIO1_15_MODE_MASK) /*!< IOCON_PIO1_15                           */
#define IOCON_PIO1_15_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_15: HYS Mask                 */
#define IOCON_PIO1_15_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_15: HYS Position             */
#define IOCON_PIO1_15_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_15_HYS_SHIFT))&IOCON_PIO1_15_HYS_MASK) /*!< IOCON_PIO1_15                           */
#define IOCON_PIO1_15_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_15: INV Mask                 */
#define IOCON_PIO1_15_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_15: INV Position             */
#define IOCON_PIO1_15_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_15_INV_SHIFT))&IOCON_PIO1_15_INV_MASK) /*!< IOCON_PIO1_15                           */
#define IOCON_PIO1_15_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_15: OD Mask                  */
#define IOCON_PIO1_15_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_15: OD Position              */
#define IOCON_PIO1_15_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_15_OD_SHIFT))&IOCON_PIO1_15_OD_MASK) /*!< IOCON_PIO1_15                           */
/* ------- PIO1_16 Bit Fields                       ------ */
#define IOCON_PIO1_16_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_16: FUNC Mask                */
#define IOCON_PIO1_16_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_16: FUNC Position            */
#define IOCON_PIO1_16_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_16_FUNC_SHIFT))&IOCON_PIO1_16_FUNC_MASK) /*!< IOCON_PIO1_16                           */
#define IOCON_PIO1_16_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_16: MODE Mask                */
#define IOCON_PIO1_16_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_16: MODE Position            */
#define IOCON_PIO1_16_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_16_MODE_SHIFT))&IOCON_PIO1_16_MODE_MASK) /*!< IOCON_PIO1_16                           */
#define IOCON_PIO1_16_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_16: HYS Mask                 */
#define IOCON_PIO1_16_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_16: HYS Position             */
#define IOCON_PIO1_16_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_16_HYS_SHIFT))&IOCON_PIO1_16_HYS_MASK) /*!< IOCON_PIO1_16                           */
#define IOCON_PIO1_16_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_16: INV Mask                 */
#define IOCON_PIO1_16_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_16: INV Position             */
#define IOCON_PIO1_16_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_16_INV_SHIFT))&IOCON_PIO1_16_INV_MASK) /*!< IOCON_PIO1_16                           */
#define IOCON_PIO1_16_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_16: OD Mask                  */
#define IOCON_PIO1_16_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_16: OD Position              */
#define IOCON_PIO1_16_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_16_OD_SHIFT))&IOCON_PIO1_16_OD_MASK) /*!< IOCON_PIO1_16                           */
/* ------- PIO1_17 Bit Fields                       ------ */
#define IOCON_PIO1_17_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_17: FUNC Mask                */
#define IOCON_PIO1_17_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_17: FUNC Position            */
#define IOCON_PIO1_17_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_17_FUNC_SHIFT))&IOCON_PIO1_17_FUNC_MASK) /*!< IOCON_PIO1_17                           */
#define IOCON_PIO1_17_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_17: MODE Mask                */
#define IOCON_PIO1_17_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_17: MODE Position            */
#define IOCON_PIO1_17_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_17_MODE_SHIFT))&IOCON_PIO1_17_MODE_MASK) /*!< IOCON_PIO1_17                           */
#define IOCON_PIO1_17_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_17: HYS Mask                 */
#define IOCON_PIO1_17_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_17: HYS Position             */
#define IOCON_PIO1_17_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_17_HYS_SHIFT))&IOCON_PIO1_17_HYS_MASK) /*!< IOCON_PIO1_17                           */
#define IOCON_PIO1_17_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_17: INV Mask                 */
#define IOCON_PIO1_17_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_17: INV Position             */
#define IOCON_PIO1_17_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_17_INV_SHIFT))&IOCON_PIO1_17_INV_MASK) /*!< IOCON_PIO1_17                           */
#define IOCON_PIO1_17_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_17: OD Mask                  */
#define IOCON_PIO1_17_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_17: OD Position              */
#define IOCON_PIO1_17_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_17_OD_SHIFT))&IOCON_PIO1_17_OD_MASK) /*!< IOCON_PIO1_17                           */
/* ------- PIO1_18 Bit Fields                       ------ */
#define IOCON_PIO1_18_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_18: FUNC Mask                */
#define IOCON_PIO1_18_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_18: FUNC Position            */
#define IOCON_PIO1_18_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_18_FUNC_SHIFT))&IOCON_PIO1_18_FUNC_MASK) /*!< IOCON_PIO1_18                           */
#define IOCON_PIO1_18_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_18: MODE Mask                */
#define IOCON_PIO1_18_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_18: MODE Position            */
#define IOCON_PIO1_18_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_18_MODE_SHIFT))&IOCON_PIO1_18_MODE_MASK) /*!< IOCON_PIO1_18                           */
#define IOCON_PIO1_18_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_18: HYS Mask                 */
#define IOCON_PIO1_18_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_18: HYS Position             */
#define IOCON_PIO1_18_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_18_HYS_SHIFT))&IOCON_PIO1_18_HYS_MASK) /*!< IOCON_PIO1_18                           */
#define IOCON_PIO1_18_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_18: INV Mask                 */
#define IOCON_PIO1_18_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_18: INV Position             */
#define IOCON_PIO1_18_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_18_INV_SHIFT))&IOCON_PIO1_18_INV_MASK) /*!< IOCON_PIO1_18                           */
#define IOCON_PIO1_18_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_18: OD Mask                  */
#define IOCON_PIO1_18_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_18: OD Position              */
#define IOCON_PIO1_18_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_18_OD_SHIFT))&IOCON_PIO1_18_OD_MASK) /*!< IOCON_PIO1_18                           */
/* ------- PIO1_19 Bit Fields                       ------ */
#define IOCON_PIO1_19_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_19: FUNC Mask                */
#define IOCON_PIO1_19_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_19: FUNC Position            */
#define IOCON_PIO1_19_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_19_FUNC_SHIFT))&IOCON_PIO1_19_FUNC_MASK) /*!< IOCON_PIO1_19                           */
#define IOCON_PIO1_19_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_19: MODE Mask                */
#define IOCON_PIO1_19_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_19: MODE Position            */
#define IOCON_PIO1_19_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_19_MODE_SHIFT))&IOCON_PIO1_19_MODE_MASK) /*!< IOCON_PIO1_19                           */
#define IOCON_PIO1_19_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_19: HYS Mask                 */
#define IOCON_PIO1_19_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_19: HYS Position             */
#define IOCON_PIO1_19_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_19_HYS_SHIFT))&IOCON_PIO1_19_HYS_MASK) /*!< IOCON_PIO1_19                           */
#define IOCON_PIO1_19_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_19: INV Mask                 */
#define IOCON_PIO1_19_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_19: INV Position             */
#define IOCON_PIO1_19_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_19_INV_SHIFT))&IOCON_PIO1_19_INV_MASK) /*!< IOCON_PIO1_19                           */
#define IOCON_PIO1_19_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_19: OD Mask                  */
#define IOCON_PIO1_19_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_19: OD Position              */
#define IOCON_PIO1_19_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_19_OD_SHIFT))&IOCON_PIO1_19_OD_MASK) /*!< IOCON_PIO1_19                           */
/* ------- PIO1_20 Bit Fields                       ------ */
#define IOCON_PIO1_20_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_20: FUNC Mask                */
#define IOCON_PIO1_20_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_20: FUNC Position            */
#define IOCON_PIO1_20_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_20_FUNC_SHIFT))&IOCON_PIO1_20_FUNC_MASK) /*!< IOCON_PIO1_20                           */
#define IOCON_PIO1_20_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_20: MODE Mask                */
#define IOCON_PIO1_20_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_20: MODE Position            */
#define IOCON_PIO1_20_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_20_MODE_SHIFT))&IOCON_PIO1_20_MODE_MASK) /*!< IOCON_PIO1_20                           */
#define IOCON_PIO1_20_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_20: HYS Mask                 */
#define IOCON_PIO1_20_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_20: HYS Position             */
#define IOCON_PIO1_20_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_20_HYS_SHIFT))&IOCON_PIO1_20_HYS_MASK) /*!< IOCON_PIO1_20                           */
#define IOCON_PIO1_20_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_20: INV Mask                 */
#define IOCON_PIO1_20_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_20: INV Position             */
#define IOCON_PIO1_20_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_20_INV_SHIFT))&IOCON_PIO1_20_INV_MASK) /*!< IOCON_PIO1_20                           */
#define IOCON_PIO1_20_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_20: OD Mask                  */
#define IOCON_PIO1_20_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_20: OD Position              */
#define IOCON_PIO1_20_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_20_OD_SHIFT))&IOCON_PIO1_20_OD_MASK) /*!< IOCON_PIO1_20                           */
/* ------- PIO1_21 Bit Fields                       ------ */
#define IOCON_PIO1_21_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_21: FUNC Mask                */
#define IOCON_PIO1_21_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_21: FUNC Position            */
#define IOCON_PIO1_21_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_21_FUNC_SHIFT))&IOCON_PIO1_21_FUNC_MASK) /*!< IOCON_PIO1_21                           */
#define IOCON_PIO1_21_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_21: MODE Mask                */
#define IOCON_PIO1_21_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_21: MODE Position            */
#define IOCON_PIO1_21_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_21_MODE_SHIFT))&IOCON_PIO1_21_MODE_MASK) /*!< IOCON_PIO1_21                           */
#define IOCON_PIO1_21_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_21: HYS Mask                 */
#define IOCON_PIO1_21_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_21: HYS Position             */
#define IOCON_PIO1_21_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_21_HYS_SHIFT))&IOCON_PIO1_21_HYS_MASK) /*!< IOCON_PIO1_21                           */
#define IOCON_PIO1_21_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_21: INV Mask                 */
#define IOCON_PIO1_21_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_21: INV Position             */
#define IOCON_PIO1_21_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_21_INV_SHIFT))&IOCON_PIO1_21_INV_MASK) /*!< IOCON_PIO1_21                           */
#define IOCON_PIO1_21_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_21: OD Mask                  */
#define IOCON_PIO1_21_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_21: OD Position              */
#define IOCON_PIO1_21_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_21_OD_SHIFT))&IOCON_PIO1_21_OD_MASK) /*!< IOCON_PIO1_21                           */
/* ------- PIO1_22 Bit Fields                       ------ */
#define IOCON_PIO1_22_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_22: FUNC Mask                */
#define IOCON_PIO1_22_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_22: FUNC Position            */
#define IOCON_PIO1_22_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_22_FUNC_SHIFT))&IOCON_PIO1_22_FUNC_MASK) /*!< IOCON_PIO1_22                           */
#define IOCON_PIO1_22_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_22: MODE Mask                */
#define IOCON_PIO1_22_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_22: MODE Position            */
#define IOCON_PIO1_22_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_22_MODE_SHIFT))&IOCON_PIO1_22_MODE_MASK) /*!< IOCON_PIO1_22                           */
#define IOCON_PIO1_22_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_22: HYS Mask                 */
#define IOCON_PIO1_22_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_22: HYS Position             */
#define IOCON_PIO1_22_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_22_HYS_SHIFT))&IOCON_PIO1_22_HYS_MASK) /*!< IOCON_PIO1_22                           */
#define IOCON_PIO1_22_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_22: INV Mask                 */
#define IOCON_PIO1_22_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_22: INV Position             */
#define IOCON_PIO1_22_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_22_INV_SHIFT))&IOCON_PIO1_22_INV_MASK) /*!< IOCON_PIO1_22                           */
#define IOCON_PIO1_22_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_22: OD Mask                  */
#define IOCON_PIO1_22_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_22: OD Position              */
#define IOCON_PIO1_22_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_22_OD_SHIFT))&IOCON_PIO1_22_OD_MASK) /*!< IOCON_PIO1_22                           */
/* ------- PIO1_23 Bit Fields                       ------ */
#define IOCON_PIO1_23_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_23: FUNC Mask                */
#define IOCON_PIO1_23_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_23: FUNC Position            */
#define IOCON_PIO1_23_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_23_FUNC_SHIFT))&IOCON_PIO1_23_FUNC_MASK) /*!< IOCON_PIO1_23                           */
#define IOCON_PIO1_23_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_23: MODE Mask                */
#define IOCON_PIO1_23_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_23: MODE Position            */
#define IOCON_PIO1_23_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_23_MODE_SHIFT))&IOCON_PIO1_23_MODE_MASK) /*!< IOCON_PIO1_23                           */
#define IOCON_PIO1_23_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_23: HYS Mask                 */
#define IOCON_PIO1_23_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_23: HYS Position             */
#define IOCON_PIO1_23_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_23_HYS_SHIFT))&IOCON_PIO1_23_HYS_MASK) /*!< IOCON_PIO1_23                           */
#define IOCON_PIO1_23_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_23: INV Mask                 */
#define IOCON_PIO1_23_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_23: INV Position             */
#define IOCON_PIO1_23_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_23_INV_SHIFT))&IOCON_PIO1_23_INV_MASK) /*!< IOCON_PIO1_23                           */
#define IOCON_PIO1_23_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_23: OD Mask                  */
#define IOCON_PIO1_23_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_23: OD Position              */
#define IOCON_PIO1_23_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_23_OD_SHIFT))&IOCON_PIO1_23_OD_MASK) /*!< IOCON_PIO1_23                           */
/* ------- PIO1_24 Bit Fields                       ------ */
#define IOCON_PIO1_24_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_24: FUNC Mask                */
#define IOCON_PIO1_24_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_24: FUNC Position            */
#define IOCON_PIO1_24_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_24_FUNC_SHIFT))&IOCON_PIO1_24_FUNC_MASK) /*!< IOCON_PIO1_24                           */
#define IOCON_PIO1_24_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_24: MODE Mask                */
#define IOCON_PIO1_24_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_24: MODE Position            */
#define IOCON_PIO1_24_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_24_MODE_SHIFT))&IOCON_PIO1_24_MODE_MASK) /*!< IOCON_PIO1_24                           */
#define IOCON_PIO1_24_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_24: HYS Mask                 */
#define IOCON_PIO1_24_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_24: HYS Position             */
#define IOCON_PIO1_24_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_24_HYS_SHIFT))&IOCON_PIO1_24_HYS_MASK) /*!< IOCON_PIO1_24                           */
#define IOCON_PIO1_24_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_24: INV Mask                 */
#define IOCON_PIO1_24_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_24: INV Position             */
#define IOCON_PIO1_24_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_24_INV_SHIFT))&IOCON_PIO1_24_INV_MASK) /*!< IOCON_PIO1_24                           */
#define IOCON_PIO1_24_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_24: OD Mask                  */
#define IOCON_PIO1_24_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_24: OD Position              */
#define IOCON_PIO1_24_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_24_OD_SHIFT))&IOCON_PIO1_24_OD_MASK) /*!< IOCON_PIO1_24                           */
/* ------- PIO1_25 Bit Fields                       ------ */
#define IOCON_PIO1_25_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_25: FUNC Mask                */
#define IOCON_PIO1_25_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_25: FUNC Position            */
#define IOCON_PIO1_25_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_25_FUNC_SHIFT))&IOCON_PIO1_25_FUNC_MASK) /*!< IOCON_PIO1_25                           */
#define IOCON_PIO1_25_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_25: MODE Mask                */
#define IOCON_PIO1_25_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_25: MODE Position            */
#define IOCON_PIO1_25_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_25_MODE_SHIFT))&IOCON_PIO1_25_MODE_MASK) /*!< IOCON_PIO1_25                           */
#define IOCON_PIO1_25_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_25: HYS Mask                 */
#define IOCON_PIO1_25_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_25: HYS Position             */
#define IOCON_PIO1_25_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_25_HYS_SHIFT))&IOCON_PIO1_25_HYS_MASK) /*!< IOCON_PIO1_25                           */
#define IOCON_PIO1_25_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_25: INV Mask                 */
#define IOCON_PIO1_25_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_25: INV Position             */
#define IOCON_PIO1_25_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_25_INV_SHIFT))&IOCON_PIO1_25_INV_MASK) /*!< IOCON_PIO1_25                           */
#define IOCON_PIO1_25_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_25: OD Mask                  */
#define IOCON_PIO1_25_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_25: OD Position              */
#define IOCON_PIO1_25_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_25_OD_SHIFT))&IOCON_PIO1_25_OD_MASK) /*!< IOCON_PIO1_25                           */
/* ------- PIO1_26 Bit Fields                       ------ */
#define IOCON_PIO1_26_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_26: FUNC Mask                */
#define IOCON_PIO1_26_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_26: FUNC Position            */
#define IOCON_PIO1_26_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_26_FUNC_SHIFT))&IOCON_PIO1_26_FUNC_MASK) /*!< IOCON_PIO1_26                           */
#define IOCON_PIO1_26_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_26: MODE Mask                */
#define IOCON_PIO1_26_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_26: MODE Position            */
#define IOCON_PIO1_26_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_26_MODE_SHIFT))&IOCON_PIO1_26_MODE_MASK) /*!< IOCON_PIO1_26                           */
#define IOCON_PIO1_26_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_26: HYS Mask                 */
#define IOCON_PIO1_26_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_26: HYS Position             */
#define IOCON_PIO1_26_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_26_HYS_SHIFT))&IOCON_PIO1_26_HYS_MASK) /*!< IOCON_PIO1_26                           */
#define IOCON_PIO1_26_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_26: INV Mask                 */
#define IOCON_PIO1_26_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_26: INV Position             */
#define IOCON_PIO1_26_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_26_INV_SHIFT))&IOCON_PIO1_26_INV_MASK) /*!< IOCON_PIO1_26                           */
#define IOCON_PIO1_26_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_26: OD Mask                  */
#define IOCON_PIO1_26_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_26: OD Position              */
#define IOCON_PIO1_26_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_26_OD_SHIFT))&IOCON_PIO1_26_OD_MASK) /*!< IOCON_PIO1_26                           */
/* ------- PIO1_27 Bit Fields                       ------ */
#define IOCON_PIO1_27_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_27: FUNC Mask                */
#define IOCON_PIO1_27_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_27: FUNC Position            */
#define IOCON_PIO1_27_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_27_FUNC_SHIFT))&IOCON_PIO1_27_FUNC_MASK) /*!< IOCON_PIO1_27                           */
#define IOCON_PIO1_27_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_27: MODE Mask                */
#define IOCON_PIO1_27_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_27: MODE Position            */
#define IOCON_PIO1_27_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_27_MODE_SHIFT))&IOCON_PIO1_27_MODE_MASK) /*!< IOCON_PIO1_27                           */
#define IOCON_PIO1_27_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_27: HYS Mask                 */
#define IOCON_PIO1_27_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_27: HYS Position             */
#define IOCON_PIO1_27_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_27_HYS_SHIFT))&IOCON_PIO1_27_HYS_MASK) /*!< IOCON_PIO1_27                           */
#define IOCON_PIO1_27_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_27: INV Mask                 */
#define IOCON_PIO1_27_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_27: INV Position             */
#define IOCON_PIO1_27_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_27_INV_SHIFT))&IOCON_PIO1_27_INV_MASK) /*!< IOCON_PIO1_27                           */
#define IOCON_PIO1_27_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_27: OD Mask                  */
#define IOCON_PIO1_27_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_27: OD Position              */
#define IOCON_PIO1_27_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_27_OD_SHIFT))&IOCON_PIO1_27_OD_MASK) /*!< IOCON_PIO1_27                           */
/* ------- PIO1_28 Bit Fields                       ------ */
#define IOCON_PIO1_28_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_28: FUNC Mask                */
#define IOCON_PIO1_28_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_28: FUNC Position            */
#define IOCON_PIO1_28_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_28_FUNC_SHIFT))&IOCON_PIO1_28_FUNC_MASK) /*!< IOCON_PIO1_28                           */
#define IOCON_PIO1_28_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_28: MODE Mask                */
#define IOCON_PIO1_28_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_28: MODE Position            */
#define IOCON_PIO1_28_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_28_MODE_SHIFT))&IOCON_PIO1_28_MODE_MASK) /*!< IOCON_PIO1_28                           */
#define IOCON_PIO1_28_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_28: HYS Mask                 */
#define IOCON_PIO1_28_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_28: HYS Position             */
#define IOCON_PIO1_28_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_28_HYS_SHIFT))&IOCON_PIO1_28_HYS_MASK) /*!< IOCON_PIO1_28                           */
#define IOCON_PIO1_28_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_28: INV Mask                 */
#define IOCON_PIO1_28_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_28: INV Position             */
#define IOCON_PIO1_28_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_28_INV_SHIFT))&IOCON_PIO1_28_INV_MASK) /*!< IOCON_PIO1_28                           */
#define IOCON_PIO1_28_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_28: OD Mask                  */
#define IOCON_PIO1_28_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_28: OD Position              */
#define IOCON_PIO1_28_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_28_OD_SHIFT))&IOCON_PIO1_28_OD_MASK) /*!< IOCON_PIO1_28                           */
/* ------- PIO1_29 Bit Fields                       ------ */
#define IOCON_PIO1_29_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_29: FUNC Mask                */
#define IOCON_PIO1_29_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_29: FUNC Position            */
#define IOCON_PIO1_29_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_29_FUNC_SHIFT))&IOCON_PIO1_29_FUNC_MASK) /*!< IOCON_PIO1_29                           */
#define IOCON_PIO1_29_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_29: MODE Mask                */
#define IOCON_PIO1_29_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_29: MODE Position            */
#define IOCON_PIO1_29_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_29_MODE_SHIFT))&IOCON_PIO1_29_MODE_MASK) /*!< IOCON_PIO1_29                           */
#define IOCON_PIO1_29_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_29: HYS Mask                 */
#define IOCON_PIO1_29_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_29: HYS Position             */
#define IOCON_PIO1_29_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_29_HYS_SHIFT))&IOCON_PIO1_29_HYS_MASK) /*!< IOCON_PIO1_29                           */
#define IOCON_PIO1_29_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_29: INV Mask                 */
#define IOCON_PIO1_29_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_29: INV Position             */
#define IOCON_PIO1_29_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_29_INV_SHIFT))&IOCON_PIO1_29_INV_MASK) /*!< IOCON_PIO1_29                           */
#define IOCON_PIO1_29_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_29: OD Mask                  */
#define IOCON_PIO1_29_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_29: OD Position              */
#define IOCON_PIO1_29_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_29_OD_SHIFT))&IOCON_PIO1_29_OD_MASK) /*!< IOCON_PIO1_29                           */
/* ------- PIO1_31 Bit Fields                       ------ */
#define IOCON_PIO1_31_FUNC_MASK                  (0x7U)                                              /*!< IOCON_PIO1_31: FUNC Mask                */
#define IOCON_PIO1_31_FUNC_SHIFT                 (0U)                                                /*!< IOCON_PIO1_31: FUNC Position            */
#define IOCON_PIO1_31_FUNC(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_31_FUNC_SHIFT))&IOCON_PIO1_31_FUNC_MASK) /*!< IOCON_PIO1_31                           */
#define IOCON_PIO1_31_MODE_MASK                  (0x18U)                                             /*!< IOCON_PIO1_31: MODE Mask                */
#define IOCON_PIO1_31_MODE_SHIFT                 (3U)                                                /*!< IOCON_PIO1_31: MODE Position            */
#define IOCON_PIO1_31_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_31_MODE_SHIFT))&IOCON_PIO1_31_MODE_MASK) /*!< IOCON_PIO1_31                           */
#define IOCON_PIO1_31_HYS_MASK                   (0x20U)                                             /*!< IOCON_PIO1_31: HYS Mask                 */
#define IOCON_PIO1_31_HYS_SHIFT                  (5U)                                                /*!< IOCON_PIO1_31: HYS Position             */
#define IOCON_PIO1_31_HYS(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_31_HYS_SHIFT))&IOCON_PIO1_31_HYS_MASK) /*!< IOCON_PIO1_31                           */
#define IOCON_PIO1_31_INV_MASK                   (0x40U)                                             /*!< IOCON_PIO1_31: INV Mask                 */
#define IOCON_PIO1_31_INV_SHIFT                  (6U)                                                /*!< IOCON_PIO1_31: INV Position             */
#define IOCON_PIO1_31_INV(x)                     (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_31_INV_SHIFT))&IOCON_PIO1_31_INV_MASK) /*!< IOCON_PIO1_31                           */
#define IOCON_PIO1_31_OD_MASK                    (0x400U)                                            /*!< IOCON_PIO1_31: OD Mask                  */
#define IOCON_PIO1_31_OD_SHIFT                   (10U)                                               /*!< IOCON_PIO1_31: OD Position              */
#define IOCON_PIO1_31_OD(x)                      (((uint32_t)(((uint32_t)(x))<<IOCON_PIO1_31_OD_SHIFT))&IOCON_PIO1_31_OD_MASK) /*!< IOCON_PIO1_31                           */
/**
 * @} */ /* End group IOCON_Register_Masks_GROUP 
 */

/* IOCON - Peripheral instance base addresses */
#define IOCON_BasePtr                  0x40044000UL //!< Peripheral base address
#define IOCON                          ((IOCON_Type *) IOCON_BasePtr) //!< Freescale base pointer
#define IOCON_BASE_PTR                 (IOCON) //!< Freescale style base pointer
/**
 * @} */ /* End group IOCON_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMU_Peripheral_access_layer_GROUP PMU Peripheral Access Layer
* @brief C Struct for PMU
* @{
*/

/* ================================================================================ */
/* ================           PMU (file:PMU_LPC11Uxx)              ================ */
/* ================================================================================ */

/**
 * @brief Power Management Unit
 */
/**
* @addtogroup PMU_structs_GROUP PMU struct
* @brief Struct for PMU
* @{
*/
typedef struct {                                /*       PMU Structure                                                */
   __IO uint32_t  PCON;                         /**< 0000: Power control register                                       */
   __IO uint32_t  GPREG[4];                     /**< 0004: General purpose register                                     */
   __IO uint32_t  GPREG4;                       /**< 0014: General purpose register 4                                   */
} PMU_Type;

/**
 * @} */ /* End group PMU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMU' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PMU_Register_Masks_GROUP PMU Register Masks
* @brief Register Masks for PMU
* @{
*/
/* ------- PCON Bit Fields                          ------ */
#define PMU_PCON_PM_MASK                         (0x7U)                                              /*!< PMU_PCON: PM Mask                       */
#define PMU_PCON_PM_SHIFT                        (0U)                                                /*!< PMU_PCON: PM Position                   */
#define PMU_PCON_PM(x)                           (((uint32_t)(((uint32_t)(x))<<PMU_PCON_PM_SHIFT))&PMU_PCON_PM_MASK) /*!< PMU_PCON                                */
#define PMU_PCON_NODPD_MASK                      (0x8U)                                              /*!< PMU_PCON: NODPD Mask                    */
#define PMU_PCON_NODPD_SHIFT                     (3U)                                                /*!< PMU_PCON: NODPD Position                */
#define PMU_PCON_NODPD(x)                        (((uint32_t)(((uint32_t)(x))<<PMU_PCON_NODPD_SHIFT))&PMU_PCON_NODPD_MASK) /*!< PMU_PCON                                */
#define PMU_PCON_SLEEPFLAG_MASK                  (0x100U)                                            /*!< PMU_PCON: SLEEPFLAG Mask                */
#define PMU_PCON_SLEEPFLAG_SHIFT                 (8U)                                                /*!< PMU_PCON: SLEEPFLAG Position            */
#define PMU_PCON_SLEEPFLAG(x)                    (((uint32_t)(((uint32_t)(x))<<PMU_PCON_SLEEPFLAG_SHIFT))&PMU_PCON_SLEEPFLAG_MASK) /*!< PMU_PCON                                */
#define PMU_PCON_DPDFLAG_MASK                    (0x800U)                                            /*!< PMU_PCON: DPDFLAG Mask                  */
#define PMU_PCON_DPDFLAG_SHIFT                   (11U)                                               /*!< PMU_PCON: DPDFLAG Position              */
#define PMU_PCON_DPDFLAG(x)                      (((uint32_t)(((uint32_t)(x))<<PMU_PCON_DPDFLAG_SHIFT))&PMU_PCON_DPDFLAG_MASK) /*!< PMU_PCON                                */
/* ------- GPREG Bit Fields                         ------ */
#define PMU_GPREG_GPDATA_MASK                    (0xFFFFFFFFU)                                       /*!< PMU_GPREG: GPDATA Mask                  */
#define PMU_GPREG_GPDATA_SHIFT                   (0U)                                                /*!< PMU_GPREG: GPDATA Position              */
#define PMU_GPREG_GPDATA(x)                      (((uint32_t)(((uint32_t)(x))<<PMU_GPREG_GPDATA_SHIFT))&PMU_GPREG_GPDATA_MASK) /*!< PMU_GPREG                               */
/* ------- GPREG4 Bit Fields                        ------ */
#define PMU_GPREG4_WAKEUPHYS_MASK                (0x400U)                                            /*!< PMU_GPREG4: WAKEUPHYS Mask              */
#define PMU_GPREG4_WAKEUPHYS_SHIFT               (10U)                                               /*!< PMU_GPREG4: WAKEUPHYS Position          */
#define PMU_GPREG4_WAKEUPHYS(x)                  (((uint32_t)(((uint32_t)(x))<<PMU_GPREG4_WAKEUPHYS_SHIFT))&PMU_GPREG4_WAKEUPHYS_MASK) /*!< PMU_GPREG4                              */
#define PMU_GPREG4_GPDATA_MASK                   (0xFFFFF800U)                                       /*!< PMU_GPREG4: GPDATA Mask                 */
#define PMU_GPREG4_GPDATA_SHIFT                  (11U)                                               /*!< PMU_GPREG4: GPDATA Position             */
#define PMU_GPREG4_GPDATA(x)                     (((uint32_t)(((uint32_t)(x))<<PMU_GPREG4_GPDATA_SHIFT))&PMU_GPREG4_GPDATA_MASK) /*!< PMU_GPREG4                              */
/**
 * @} */ /* End group PMU_Register_Masks_GROUP 
 */

/* PMU - Peripheral instance base addresses */
#define PMU_BasePtr                    0x40038000UL //!< Peripheral base address
#define PMU                            ((PMU_Type *) PMU_BasePtr) //!< Freescale base pointer
#define PMU_BASE_PTR                   (PMU) //!< Freescale style base pointer
/**
 * @} */ /* End group PMU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SSP0_Peripheral_access_layer_GROUP SSP0 Peripheral Access Layer
* @brief C Struct for SSP0
* @{
*/

/* ================================================================================ */
/* ================           SSP0 (file:SSP0_LPC11Uxx)            ================ */
/* ================================================================================ */

/**
 * @brief SSP/SPI
 */
/**
* @addtogroup SSP0_structs_GROUP SSP0 struct
* @brief Struct for SSP0
* @{
*/
typedef struct {                                /*       SSP0 Structure                                               */
   __IO uint32_t  CR0;                          /**< 0000: Control Register 0. Selects the serial clock rate, bus type, and data size */
   __IO uint32_t  CR1;                          /**< 0004: Control Register 1. Selects master/slave and other modes     */
   __IO uint32_t  DR;                           /**< 0008: Data Register. Writes fill the transmit FIFO, and reads empty the receive FIFO */
   __I  uint32_t  SR;                           /**< 000C: Status Register                                              */
   __IO uint32_t  CPSR;                         /**< 0010: Clock Prescale Register                                      */
   __IO uint32_t  IMSC;                         /**< 0014: Interrupt Mask Set and Clear Register                        */
   __I  uint32_t  RIS;                          /**< 0018: Raw Interrupt Status Register                                */
   __I  uint32_t  MIS;                          /**< 001C: Masked Interrupt Status Register                             */
   __O  uint32_t  ICR;                          /**< 0020: SSPICR Interrupt Clear Register                              */
} SSP0_Type;

/**
 * @} */ /* End group SSP0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SSP0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SSP0_Register_Masks_GROUP SSP0 Register Masks
* @brief Register Masks for SSP0
* @{
*/
/* ------- CR0 Bit Fields                           ------ */
#define SSP0_CR0_DSS_MASK                        (0xFU)                                              /*!< SSP0_CR0: DSS Mask                      */
#define SSP0_CR0_DSS_SHIFT                       (0U)                                                /*!< SSP0_CR0: DSS Position                  */
#define SSP0_CR0_DSS(x)                          (((uint32_t)(((uint32_t)(x))<<SSP0_CR0_DSS_SHIFT))&SSP0_CR0_DSS_MASK) /*!< SSP0_CR0                                */
#define SSP0_CR0_FRF_MASK                        (0x30U)                                             /*!< SSP0_CR0: FRF Mask                      */
#define SSP0_CR0_FRF_SHIFT                       (4U)                                                /*!< SSP0_CR0: FRF Position                  */
#define SSP0_CR0_FRF(x)                          (((uint32_t)(((uint32_t)(x))<<SSP0_CR0_FRF_SHIFT))&SSP0_CR0_FRF_MASK) /*!< SSP0_CR0                                */
#define SSP0_CR0_CPOL_MASK                       (0x40U)                                             /*!< SSP0_CR0: CPOL Mask                     */
#define SSP0_CR0_CPOL_SHIFT                      (6U)                                                /*!< SSP0_CR0: CPOL Position                 */
#define SSP0_CR0_CPOL(x)                         (((uint32_t)(((uint32_t)(x))<<SSP0_CR0_CPOL_SHIFT))&SSP0_CR0_CPOL_MASK) /*!< SSP0_CR0                                */
#define SSP0_CR0_CPHA_MASK                       (0x80U)                                             /*!< SSP0_CR0: CPHA Mask                     */
#define SSP0_CR0_CPHA_SHIFT                      (7U)                                                /*!< SSP0_CR0: CPHA Position                 */
#define SSP0_CR0_CPHA(x)                         (((uint32_t)(((uint32_t)(x))<<SSP0_CR0_CPHA_SHIFT))&SSP0_CR0_CPHA_MASK) /*!< SSP0_CR0                                */
#define SSP0_CR0_SCR_MASK                        (0xFF00U)                                           /*!< SSP0_CR0: SCR Mask                      */
#define SSP0_CR0_SCR_SHIFT                       (8U)                                                /*!< SSP0_CR0: SCR Position                  */
#define SSP0_CR0_SCR(x)                          (((uint32_t)(((uint32_t)(x))<<SSP0_CR0_SCR_SHIFT))&SSP0_CR0_SCR_MASK) /*!< SSP0_CR0                                */
/* ------- CR1 Bit Fields                           ------ */
#define SSP0_CR1_LBM_MASK                        (0x1U)                                              /*!< SSP0_CR1: LBM Mask                      */
#define SSP0_CR1_LBM_SHIFT                       (0U)                                                /*!< SSP0_CR1: LBM Position                  */
#define SSP0_CR1_LBM(x)                          (((uint32_t)(((uint32_t)(x))<<SSP0_CR1_LBM_SHIFT))&SSP0_CR1_LBM_MASK) /*!< SSP0_CR1                                */
#define SSP0_CR1_SSE_MASK                        (0x2U)                                              /*!< SSP0_CR1: SSE Mask                      */
#define SSP0_CR1_SSE_SHIFT                       (1U)                                                /*!< SSP0_CR1: SSE Position                  */
#define SSP0_CR1_SSE(x)                          (((uint32_t)(((uint32_t)(x))<<SSP0_CR1_SSE_SHIFT))&SSP0_CR1_SSE_MASK) /*!< SSP0_CR1                                */
#define SSP0_CR1_MS_MASK                         (0x4U)                                              /*!< SSP0_CR1: MS Mask                       */
#define SSP0_CR1_MS_SHIFT                        (2U)                                                /*!< SSP0_CR1: MS Position                   */
#define SSP0_CR1_MS(x)                           (((uint32_t)(((uint32_t)(x))<<SSP0_CR1_MS_SHIFT))&SSP0_CR1_MS_MASK) /*!< SSP0_CR1                                */
#define SSP0_CR1_SOD_MASK                        (0x8U)                                              /*!< SSP0_CR1: SOD Mask                      */
#define SSP0_CR1_SOD_SHIFT                       (3U)                                                /*!< SSP0_CR1: SOD Position                  */
#define SSP0_CR1_SOD(x)                          (((uint32_t)(((uint32_t)(x))<<SSP0_CR1_SOD_SHIFT))&SSP0_CR1_SOD_MASK) /*!< SSP0_CR1                                */
/* ------- DR Bit Fields                            ------ */
#define SSP0_DR_DATA_MASK                        (0xFFFFU)                                           /*!< SSP0_DR: DATA Mask                      */
#define SSP0_DR_DATA_SHIFT                       (0U)                                                /*!< SSP0_DR: DATA Position                  */
#define SSP0_DR_DATA(x)                          (((uint32_t)(((uint32_t)(x))<<SSP0_DR_DATA_SHIFT))&SSP0_DR_DATA_MASK) /*!< SSP0_DR                                 */
/* ------- SR Bit Fields                            ------ */
#define SSP0_SR_TFE_MASK                         (0x1U)                                              /*!< SSP0_SR: TFE Mask                       */
#define SSP0_SR_TFE_SHIFT                        (0U)                                                /*!< SSP0_SR: TFE Position                   */
#define SSP0_SR_TFE(x)                           (((uint32_t)(((uint32_t)(x))<<SSP0_SR_TFE_SHIFT))&SSP0_SR_TFE_MASK) /*!< SSP0_SR                                 */
#define SSP0_SR_TNF_MASK                         (0x2U)                                              /*!< SSP0_SR: TNF Mask                       */
#define SSP0_SR_TNF_SHIFT                        (1U)                                                /*!< SSP0_SR: TNF Position                   */
#define SSP0_SR_TNF(x)                           (((uint32_t)(((uint32_t)(x))<<SSP0_SR_TNF_SHIFT))&SSP0_SR_TNF_MASK) /*!< SSP0_SR                                 */
#define SSP0_SR_RNE_MASK                         (0x4U)                                              /*!< SSP0_SR: RNE Mask                       */
#define SSP0_SR_RNE_SHIFT                        (2U)                                                /*!< SSP0_SR: RNE Position                   */
#define SSP0_SR_RNE(x)                           (((uint32_t)(((uint32_t)(x))<<SSP0_SR_RNE_SHIFT))&SSP0_SR_RNE_MASK) /*!< SSP0_SR                                 */
#define SSP0_SR_RFF_MASK                         (0x8U)                                              /*!< SSP0_SR: RFF Mask                       */
#define SSP0_SR_RFF_SHIFT                        (3U)                                                /*!< SSP0_SR: RFF Position                   */
#define SSP0_SR_RFF(x)                           (((uint32_t)(((uint32_t)(x))<<SSP0_SR_RFF_SHIFT))&SSP0_SR_RFF_MASK) /*!< SSP0_SR                                 */
#define SSP0_SR_BSY_MASK                         (0x10U)                                             /*!< SSP0_SR: BSY Mask                       */
#define SSP0_SR_BSY_SHIFT                        (4U)                                                /*!< SSP0_SR: BSY Position                   */
#define SSP0_SR_BSY(x)                           (((uint32_t)(((uint32_t)(x))<<SSP0_SR_BSY_SHIFT))&SSP0_SR_BSY_MASK) /*!< SSP0_SR                                 */
/* ------- CPSR Bit Fields                          ------ */
#define SSP0_CPSR_CPSDVSR_MASK                   (0xFFU)                                             /*!< SSP0_CPSR: CPSDVSR Mask                 */
#define SSP0_CPSR_CPSDVSR_SHIFT                  (0U)                                                /*!< SSP0_CPSR: CPSDVSR Position             */
#define SSP0_CPSR_CPSDVSR(x)                     (((uint32_t)(((uint32_t)(x))<<SSP0_CPSR_CPSDVSR_SHIFT))&SSP0_CPSR_CPSDVSR_MASK) /*!< SSP0_CPSR                               */
/* ------- IMSC Bit Fields                          ------ */
#define SSP0_IMSC_RORIM_MASK                     (0x1U)                                              /*!< SSP0_IMSC: RORIM Mask                   */
#define SSP0_IMSC_RORIM_SHIFT                    (0U)                                                /*!< SSP0_IMSC: RORIM Position               */
#define SSP0_IMSC_RORIM(x)                       (((uint32_t)(((uint32_t)(x))<<SSP0_IMSC_RORIM_SHIFT))&SSP0_IMSC_RORIM_MASK) /*!< SSP0_IMSC                               */
#define SSP0_IMSC_RTIM_MASK                      (0x2U)                                              /*!< SSP0_IMSC: RTIM Mask                    */
#define SSP0_IMSC_RTIM_SHIFT                     (1U)                                                /*!< SSP0_IMSC: RTIM Position                */
#define SSP0_IMSC_RTIM(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_IMSC_RTIM_SHIFT))&SSP0_IMSC_RTIM_MASK) /*!< SSP0_IMSC                               */
#define SSP0_IMSC_RXIM_MASK                      (0x4U)                                              /*!< SSP0_IMSC: RXIM Mask                    */
#define SSP0_IMSC_RXIM_SHIFT                     (2U)                                                /*!< SSP0_IMSC: RXIM Position                */
#define SSP0_IMSC_RXIM(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_IMSC_RXIM_SHIFT))&SSP0_IMSC_RXIM_MASK) /*!< SSP0_IMSC                               */
#define SSP0_IMSC_TXIM_MASK                      (0x8U)                                              /*!< SSP0_IMSC: TXIM Mask                    */
#define SSP0_IMSC_TXIM_SHIFT                     (3U)                                                /*!< SSP0_IMSC: TXIM Position                */
#define SSP0_IMSC_TXIM(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_IMSC_TXIM_SHIFT))&SSP0_IMSC_TXIM_MASK) /*!< SSP0_IMSC                               */
/* ------- RIS Bit Fields                           ------ */
#define SSP0_RIS_RORRIS_MASK                     (0x1U)                                              /*!< SSP0_RIS: RORRIS Mask                   */
#define SSP0_RIS_RORRIS_SHIFT                    (0U)                                                /*!< SSP0_RIS: RORRIS Position               */
#define SSP0_RIS_RORRIS(x)                       (((uint32_t)(((uint32_t)(x))<<SSP0_RIS_RORRIS_SHIFT))&SSP0_RIS_RORRIS_MASK) /*!< SSP0_RIS                                */
#define SSP0_RIS_RTRIS_MASK                      (0x2U)                                              /*!< SSP0_RIS: RTRIS Mask                    */
#define SSP0_RIS_RTRIS_SHIFT                     (1U)                                                /*!< SSP0_RIS: RTRIS Position                */
#define SSP0_RIS_RTRIS(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_RIS_RTRIS_SHIFT))&SSP0_RIS_RTRIS_MASK) /*!< SSP0_RIS                                */
#define SSP0_RIS_RXRIS_MASK                      (0x4U)                                              /*!< SSP0_RIS: RXRIS Mask                    */
#define SSP0_RIS_RXRIS_SHIFT                     (2U)                                                /*!< SSP0_RIS: RXRIS Position                */
#define SSP0_RIS_RXRIS(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_RIS_RXRIS_SHIFT))&SSP0_RIS_RXRIS_MASK) /*!< SSP0_RIS                                */
#define SSP0_RIS_TXRIS_MASK                      (0x8U)                                              /*!< SSP0_RIS: TXRIS Mask                    */
#define SSP0_RIS_TXRIS_SHIFT                     (3U)                                                /*!< SSP0_RIS: TXRIS Position                */
#define SSP0_RIS_TXRIS(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_RIS_TXRIS_SHIFT))&SSP0_RIS_TXRIS_MASK) /*!< SSP0_RIS                                */
/* ------- MIS Bit Fields                           ------ */
#define SSP0_MIS_RORMIS_MASK                     (0x1U)                                              /*!< SSP0_MIS: RORMIS Mask                   */
#define SSP0_MIS_RORMIS_SHIFT                    (0U)                                                /*!< SSP0_MIS: RORMIS Position               */
#define SSP0_MIS_RORMIS(x)                       (((uint32_t)(((uint32_t)(x))<<SSP0_MIS_RORMIS_SHIFT))&SSP0_MIS_RORMIS_MASK) /*!< SSP0_MIS                                */
#define SSP0_MIS_RTMIS_MASK                      (0x2U)                                              /*!< SSP0_MIS: RTMIS Mask                    */
#define SSP0_MIS_RTMIS_SHIFT                     (1U)                                                /*!< SSP0_MIS: RTMIS Position                */
#define SSP0_MIS_RTMIS(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_MIS_RTMIS_SHIFT))&SSP0_MIS_RTMIS_MASK) /*!< SSP0_MIS                                */
#define SSP0_MIS_RXMIS_MASK                      (0x4U)                                              /*!< SSP0_MIS: RXMIS Mask                    */
#define SSP0_MIS_RXMIS_SHIFT                     (2U)                                                /*!< SSP0_MIS: RXMIS Position                */
#define SSP0_MIS_RXMIS(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_MIS_RXMIS_SHIFT))&SSP0_MIS_RXMIS_MASK) /*!< SSP0_MIS                                */
#define SSP0_MIS_TXMIS_MASK                      (0x8U)                                              /*!< SSP0_MIS: TXMIS Mask                    */
#define SSP0_MIS_TXMIS_SHIFT                     (3U)                                                /*!< SSP0_MIS: TXMIS Position                */
#define SSP0_MIS_TXMIS(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_MIS_TXMIS_SHIFT))&SSP0_MIS_TXMIS_MASK) /*!< SSP0_MIS                                */
/* ------- ICR Bit Fields                           ------ */
#define SSP0_ICR_RORIC_MASK                      (0x1U)                                              /*!< SSP0_ICR: RORIC Mask                    */
#define SSP0_ICR_RORIC_SHIFT                     (0U)                                                /*!< SSP0_ICR: RORIC Position                */
#define SSP0_ICR_RORIC(x)                        (((uint32_t)(((uint32_t)(x))<<SSP0_ICR_RORIC_SHIFT))&SSP0_ICR_RORIC_MASK) /*!< SSP0_ICR                                */
#define SSP0_ICR_RTIC_MASK                       (0x2U)                                              /*!< SSP0_ICR: RTIC Mask                     */
#define SSP0_ICR_RTIC_SHIFT                      (1U)                                                /*!< SSP0_ICR: RTIC Position                 */
#define SSP0_ICR_RTIC(x)                         (((uint32_t)(((uint32_t)(x))<<SSP0_ICR_RTIC_SHIFT))&SSP0_ICR_RTIC_MASK) /*!< SSP0_ICR                                */
/**
 * @} */ /* End group SSP0_Register_Masks_GROUP 
 */

/* SSP0 - Peripheral instance base addresses */
#define SSP0_BasePtr                   0x40040000UL //!< Peripheral base address
#define SSP0                           ((SSP0_Type *) SSP0_BasePtr) //!< Freescale base pointer
#define SSP0_BASE_PTR                  (SSP0) //!< Freescale style base pointer
/**
 * @} */ /* End group SSP0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SSP0_Peripheral_access_layer_GROUP SSP0 Peripheral Access Layer
* @brief C Struct for SSP0
* @{
*/

/* ================================================================================ */
/* ================           SSP1 (derived from SSP0)             ================ */
/* ================================================================================ */

/**
 * @brief SSP/SPI
 */

/* SSP1 - Peripheral instance base addresses */
#define SSP1_BasePtr                   0x40058000UL //!< Peripheral base address
#define SSP1                           ((SSP0_Type *) SSP1_BasePtr) //!< Freescale base pointer
#define SSP1_BASE_PTR                  (SSP1) //!< Freescale style base pointer
/**
 * @} */ /* End group SSP0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SYSCON_Peripheral_access_layer_GROUP SYSCON Peripheral Access Layer
* @brief C Struct for SYSCON
* @{
*/

/* ================================================================================ */
/* ================           SYSCON (file:SYSCON_LPC11Uxx)        ================ */
/* ================================================================================ */

/**
 * @brief System control block
 */
/**
* @addtogroup SYSCON_structs_GROUP SYSCON struct
* @brief Struct for SYSCON
* @{
*/
typedef struct {                                /*       SYSCON Structure                                             */
   __IO uint32_t  SYSMEMREMAP;                  /**< 0000: System memory remap                                          */
   __IO uint32_t  PRESETCTRL;                   /**< 0004: Peripheral reset control                                     */
   __IO uint32_t  SYSPLLCTRL;                   /**< 0008: System PLL control                                           */
   __I  uint32_t  SYSPLLSTAT;                   /**< 000C: System PLL status                                            */
   __IO uint32_t  USBPLLCTRL;                   /**< 0010: USB PLL control                                              */
   __I  uint32_t  USBPLLSTAT;                   /**< 0014: USB PLL status                                               */
        uint8_t   RESERVED_0[8];               
   __IO uint32_t  SYSOSCCTRL;                   /**< 0020: System oscillator control                                    */
   __IO uint32_t  WDTOSCCTRL;                   /**< 0024: Watchdog oscillator control                                  */
        uint8_t   RESERVED_1[8];               
   __IO uint32_t  SYSRSTSTAT;                   /**< 0030: System reset status register                                 */
        uint8_t   RESERVED_2[12];              
   __IO uint32_t  SYSPLLCLKSEL;                 /**< 0040: System PLL clock source select                               */
   __IO uint32_t  SYSPLLCLKUEN;                 /**< 0044: System PLL clock source update enable                        */
   __IO uint32_t  USBPLLCLKSEL;                 /**< 0048: USB PLL clock source select                                  */
   __IO uint32_t  USBPLLCLKUEN;                 /**< 004C: USB PLL clock source update enable                           */
        uint8_t   RESERVED_3[32];              
   __IO uint32_t  MAINCLKSEL;                   /**< 0070: Main clock source select                                     */
   __IO uint32_t  MAINCLKUEN;                   /**< 0074: Main clock source update enable                              */
   __IO uint32_t  SYSAHBCLKDIV;                 /**< 0078: System clock divider                                         */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  SYSAHBCLKCTRL;                /**< 0080: System clock control                                         */
        uint8_t   RESERVED_5[16];              
   __IO uint32_t  SSP0CLKDIV;                   /**< 0094: SSP0 clock divider                                           */
   __IO uint32_t  UARTCLKDIV;                   /**< 0098: UART clock divider                                           */
   __IO uint32_t  SSP1CLKDIV;                   /**< 009C: SSP1 clock divider                                           */
        uint8_t   RESERVED_6[32];              
   __IO uint32_t  USBCLKSEL;                    /**< 00C0: USB clock source select                                      */
   __IO uint32_t  USBCLKUEN;                    /**< 00C4: USB clock source update enable                               */
   __IO uint32_t  USBCLKDIV;                    /**< 00C8: USB clock source divider                                     */
        uint8_t   RESERVED_7[20];              
   __IO uint32_t  CLKOUTSEL;                    /**< 00E0: CLKOUT clock source select                                   */
   __IO uint32_t  CLKOUTUEN;                    /**< 00E4: CLKOUT clock source update enable                            */
   __IO uint32_t  CLKOUTDIV;                    /**< 00E8: CLKOUT clock divider                                         */
        uint8_t   RESERVED_8[20];              
   __I  uint32_t  PIOPORCAP0;                   /**< 0100: POR captured PIO status 0                                    */
   __I  uint32_t  PIOPORCAP1;                   /**< 0104: POR captured PIO status 1                                    */
        uint8_t   RESERVED_9[72];              
   __IO uint32_t  BODCTRL;                      /**< 0150: Brown-Out Detect                                             */
   __IO uint32_t  SYSTCKCAL;                    /**< 0154: System tick counter calibration                              */
        uint8_t   RESERVED_10[24];             
   __IO uint32_t  IRQLATENCY;                   /**< 0170: IQR delay. Allows trade-off between interrupt latency and determinism */
   __IO uint32_t  NMISRC;                       /**< 0174: NMI Source Control                                           */
   __IO uint32_t  PINTSEL[8];                   /**< 0178: GPIO Pin Interrupt Select register %                         */
   __IO uint32_t  USBCLKCTRL;                   /**< 0198: USB clock control                                            */
   __I  uint32_t  USBCLKST;                     /**< 019C: USB clock status                                             */
        uint8_t   RESERVED_11[100];            
   __IO uint32_t  STARTERP0;                    /**< 0204: Start logic 0 interrupt wake-up enable register 0            */
        uint8_t   RESERVED_12[12];             
   __IO uint32_t  STARTERP1;                    /**< 0214: Start logic 1 interrupt wake-up enable register 1            */
        uint8_t   RESERVED_13[24];             
   __IO uint32_t  PDSLEEPCFG;                   /**< 0230: Power-down states in deep-sleep mode                         */
   __IO uint32_t  PDAWAKECFG;                   /**< 0234: Power-down states for wake-up from deep-sleep                */
   __IO uint32_t  PDRUNCFG;                     /**< 0238: Power configuration register                                 */
        uint8_t   RESERVED_14[440];            
   __I  uint32_t  DEVICE_ID;                    /**< 03F4: Device ID                                                    */
} SYSCON_Type;

/**
 * @} */ /* End group SYSCON_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SYSCON' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SYSCON_Register_Masks_GROUP SYSCON Register Masks
* @brief Register Masks for SYSCON
* @{
*/
/* ------- SYSMEMREMAP Bit Fields                   ------ */
#define SYSCON_SYSMEMREMAP_MAP_MASK              (0x3U)                                              /*!< SYSCON_SYSMEMREMAP: MAP Mask            */
#define SYSCON_SYSMEMREMAP_MAP_SHIFT             (0U)                                                /*!< SYSCON_SYSMEMREMAP: MAP Position        */
#define SYSCON_SYSMEMREMAP_MAP(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSMEMREMAP_MAP_SHIFT))&SYSCON_SYSMEMREMAP_MAP_MASK) /*!< SYSCON_SYSMEMREMAP                      */
/* ------- PRESETCTRL Bit Fields                    ------ */
#define SYSCON_PRESETCTRL_SSP0_RST_N_MASK        (0x1U)                                              /*!< SYSCON_PRESETCTRL: SSP0_RST_N Mask      */
#define SYSCON_PRESETCTRL_SSP0_RST_N_SHIFT       (0U)                                                /*!< SYSCON_PRESETCTRL: SSP0_RST_N Position  */
#define SYSCON_PRESETCTRL_SSP0_RST_N(x)          (((uint32_t)(((uint32_t)(x))<<SYSCON_PRESETCTRL_SSP0_RST_N_SHIFT))&SYSCON_PRESETCTRL_SSP0_RST_N_MASK) /*!< SYSCON_PRESETCTRL                       */
#define SYSCON_PRESETCTRL_I2C_RST_N_MASK         (0x2U)                                              /*!< SYSCON_PRESETCTRL: I2C_RST_N Mask       */
#define SYSCON_PRESETCTRL_I2C_RST_N_SHIFT        (1U)                                                /*!< SYSCON_PRESETCTRL: I2C_RST_N Position   */
#define SYSCON_PRESETCTRL_I2C_RST_N(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_PRESETCTRL_I2C_RST_N_SHIFT))&SYSCON_PRESETCTRL_I2C_RST_N_MASK) /*!< SYSCON_PRESETCTRL                       */
#define SYSCON_PRESETCTRL_SSP1_RST_N_MASK        (0x4U)                                              /*!< SYSCON_PRESETCTRL: SSP1_RST_N Mask      */
#define SYSCON_PRESETCTRL_SSP1_RST_N_SHIFT       (2U)                                                /*!< SYSCON_PRESETCTRL: SSP1_RST_N Position  */
#define SYSCON_PRESETCTRL_SSP1_RST_N(x)          (((uint32_t)(((uint32_t)(x))<<SYSCON_PRESETCTRL_SSP1_RST_N_SHIFT))&SYSCON_PRESETCTRL_SSP1_RST_N_MASK) /*!< SYSCON_PRESETCTRL                       */
/* ------- SYSPLLCTRL Bit Fields                    ------ */
#define SYSCON_SYSPLLCTRL_MSEL_MASK              (0x1FU)                                             /*!< SYSCON_SYSPLLCTRL: MSEL Mask            */
#define SYSCON_SYSPLLCTRL_MSEL_SHIFT             (0U)                                                /*!< SYSCON_SYSPLLCTRL: MSEL Position        */
#define SYSCON_SYSPLLCTRL_MSEL(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSPLLCTRL_MSEL_SHIFT))&SYSCON_SYSPLLCTRL_MSEL_MASK) /*!< SYSCON_SYSPLLCTRL                       */
#define SYSCON_SYSPLLCTRL_PSEL_MASK              (0x60U)                                             /*!< SYSCON_SYSPLLCTRL: PSEL Mask            */
#define SYSCON_SYSPLLCTRL_PSEL_SHIFT             (5U)                                                /*!< SYSCON_SYSPLLCTRL: PSEL Position        */
#define SYSCON_SYSPLLCTRL_PSEL(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSPLLCTRL_PSEL_SHIFT))&SYSCON_SYSPLLCTRL_PSEL_MASK) /*!< SYSCON_SYSPLLCTRL                       */
/* ------- SYSPLLSTAT Bit Fields                    ------ */
#define SYSCON_SYSPLLSTAT_LOCK_MASK              (0x1U)                                              /*!< SYSCON_SYSPLLSTAT: LOCK Mask            */
#define SYSCON_SYSPLLSTAT_LOCK_SHIFT             (0U)                                                /*!< SYSCON_SYSPLLSTAT: LOCK Position        */
#define SYSCON_SYSPLLSTAT_LOCK(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSPLLSTAT_LOCK_SHIFT))&SYSCON_SYSPLLSTAT_LOCK_MASK) /*!< SYSCON_SYSPLLSTAT                       */
/* ------- USBPLLCTRL Bit Fields                    ------ */
#define SYSCON_USBPLLCTRL_MSEL_MASK              (0x1FU)                                             /*!< SYSCON_USBPLLCTRL: MSEL Mask            */
#define SYSCON_USBPLLCTRL_MSEL_SHIFT             (0U)                                                /*!< SYSCON_USBPLLCTRL: MSEL Position        */
#define SYSCON_USBPLLCTRL_MSEL(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_USBPLLCTRL_MSEL_SHIFT))&SYSCON_USBPLLCTRL_MSEL_MASK) /*!< SYSCON_USBPLLCTRL                       */
#define SYSCON_USBPLLCTRL_PSEL_MASK              (0x60U)                                             /*!< SYSCON_USBPLLCTRL: PSEL Mask            */
#define SYSCON_USBPLLCTRL_PSEL_SHIFT             (5U)                                                /*!< SYSCON_USBPLLCTRL: PSEL Position        */
#define SYSCON_USBPLLCTRL_PSEL(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_USBPLLCTRL_PSEL_SHIFT))&SYSCON_USBPLLCTRL_PSEL_MASK) /*!< SYSCON_USBPLLCTRL                       */
/* ------- USBPLLSTAT Bit Fields                    ------ */
#define SYSCON_USBPLLSTAT_LOCK_MASK              (0x1U)                                              /*!< SYSCON_USBPLLSTAT: LOCK Mask            */
#define SYSCON_USBPLLSTAT_LOCK_SHIFT             (0U)                                                /*!< SYSCON_USBPLLSTAT: LOCK Position        */
#define SYSCON_USBPLLSTAT_LOCK(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_USBPLLSTAT_LOCK_SHIFT))&SYSCON_USBPLLSTAT_LOCK_MASK) /*!< SYSCON_USBPLLSTAT                       */
/* ------- SYSOSCCTRL Bit Fields                    ------ */
#define SYSCON_SYSOSCCTRL_BYPASS_MASK            (0x1U)                                              /*!< SYSCON_SYSOSCCTRL: BYPASS Mask          */
#define SYSCON_SYSOSCCTRL_BYPASS_SHIFT           (0U)                                                /*!< SYSCON_SYSOSCCTRL: BYPASS Position      */
#define SYSCON_SYSOSCCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSOSCCTRL_BYPASS_SHIFT))&SYSCON_SYSOSCCTRL_BYPASS_MASK) /*!< SYSCON_SYSOSCCTRL                       */
#define SYSCON_SYSOSCCTRL_FREQRANGE_MASK         (0x2U)                                              /*!< SYSCON_SYSOSCCTRL: FREQRANGE Mask       */
#define SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT        (1U)                                                /*!< SYSCON_SYSOSCCTRL: FREQRANGE Position   */
#define SYSCON_SYSOSCCTRL_FREQRANGE(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT))&SYSCON_SYSOSCCTRL_FREQRANGE_MASK) /*!< SYSCON_SYSOSCCTRL                       */
/* ------- WDTOSCCTRL Bit Fields                    ------ */
#define SYSCON_WDTOSCCTRL_DIVSEL_MASK            (0x1FU)                                             /*!< SYSCON_WDTOSCCTRL: DIVSEL Mask          */
#define SYSCON_WDTOSCCTRL_DIVSEL_SHIFT           (0U)                                                /*!< SYSCON_WDTOSCCTRL: DIVSEL Position      */
#define SYSCON_WDTOSCCTRL_DIVSEL(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_WDTOSCCTRL_DIVSEL_SHIFT))&SYSCON_WDTOSCCTRL_DIVSEL_MASK) /*!< SYSCON_WDTOSCCTRL                       */
#define SYSCON_WDTOSCCTRL_FREQSEL_MASK           (0x1E0U)                                            /*!< SYSCON_WDTOSCCTRL: FREQSEL Mask         */
#define SYSCON_WDTOSCCTRL_FREQSEL_SHIFT          (5U)                                                /*!< SYSCON_WDTOSCCTRL: FREQSEL Position     */
#define SYSCON_WDTOSCCTRL_FREQSEL(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_WDTOSCCTRL_FREQSEL_SHIFT))&SYSCON_WDTOSCCTRL_FREQSEL_MASK) /*!< SYSCON_WDTOSCCTRL                       */
/* ------- SYSRSTSTAT Bit Fields                    ------ */
#define SYSCON_SYSRSTSTAT_POR_MASK               (0x1U)                                              /*!< SYSCON_SYSRSTSTAT: POR Mask             */
#define SYSCON_SYSRSTSTAT_POR_SHIFT              (0U)                                                /*!< SYSCON_SYSRSTSTAT: POR Position         */
#define SYSCON_SYSRSTSTAT_POR(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSRSTSTAT_POR_SHIFT))&SYSCON_SYSRSTSTAT_POR_MASK) /*!< SYSCON_SYSRSTSTAT                       */
#define SYSCON_SYSRSTSTAT_EXTRST_MASK            (0x2U)                                              /*!< SYSCON_SYSRSTSTAT: EXTRST Mask          */
#define SYSCON_SYSRSTSTAT_EXTRST_SHIFT           (1U)                                                /*!< SYSCON_SYSRSTSTAT: EXTRST Position      */
#define SYSCON_SYSRSTSTAT_EXTRST(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSRSTSTAT_EXTRST_SHIFT))&SYSCON_SYSRSTSTAT_EXTRST_MASK) /*!< SYSCON_SYSRSTSTAT                       */
#define SYSCON_SYSRSTSTAT_WDT_MASK               (0x4U)                                              /*!< SYSCON_SYSRSTSTAT: WDT Mask             */
#define SYSCON_SYSRSTSTAT_WDT_SHIFT              (2U)                                                /*!< SYSCON_SYSRSTSTAT: WDT Position         */
#define SYSCON_SYSRSTSTAT_WDT(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSRSTSTAT_WDT_SHIFT))&SYSCON_SYSRSTSTAT_WDT_MASK) /*!< SYSCON_SYSRSTSTAT                       */
#define SYSCON_SYSRSTSTAT_BOD_MASK               (0x8U)                                              /*!< SYSCON_SYSRSTSTAT: BOD Mask             */
#define SYSCON_SYSRSTSTAT_BOD_SHIFT              (3U)                                                /*!< SYSCON_SYSRSTSTAT: BOD Position         */
#define SYSCON_SYSRSTSTAT_BOD(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSRSTSTAT_BOD_SHIFT))&SYSCON_SYSRSTSTAT_BOD_MASK) /*!< SYSCON_SYSRSTSTAT                       */
#define SYSCON_SYSRSTSTAT_SYSRST_MASK            (0x10U)                                             /*!< SYSCON_SYSRSTSTAT: SYSRST Mask          */
#define SYSCON_SYSRSTSTAT_SYSRST_SHIFT           (4U)                                                /*!< SYSCON_SYSRSTSTAT: SYSRST Position      */
#define SYSCON_SYSRSTSTAT_SYSRST(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSRSTSTAT_SYSRST_SHIFT))&SYSCON_SYSRSTSTAT_SYSRST_MASK) /*!< SYSCON_SYSRSTSTAT                       */
/* ------- SYSPLLCLKSEL Bit Fields                  ------ */
#define SYSCON_SYSPLLCLKSEL_SEL_MASK             (0x3U)                                              /*!< SYSCON_SYSPLLCLKSEL: SEL Mask           */
#define SYSCON_SYSPLLCLKSEL_SEL_SHIFT            (0U)                                                /*!< SYSCON_SYSPLLCLKSEL: SEL Position       */
#define SYSCON_SYSPLLCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSPLLCLKSEL_SEL_SHIFT))&SYSCON_SYSPLLCLKSEL_SEL_MASK) /*!< SYSCON_SYSPLLCLKSEL                     */
/* ------- SYSPLLCLKUEN Bit Fields                  ------ */
#define SYSCON_SYSPLLCLKUEN_ENA_MASK             (0x1U)                                              /*!< SYSCON_SYSPLLCLKUEN: ENA Mask           */
#define SYSCON_SYSPLLCLKUEN_ENA_SHIFT            (0U)                                                /*!< SYSCON_SYSPLLCLKUEN: ENA Position       */
#define SYSCON_SYSPLLCLKUEN_ENA(x)               (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSPLLCLKUEN_ENA_SHIFT))&SYSCON_SYSPLLCLKUEN_ENA_MASK) /*!< SYSCON_SYSPLLCLKUEN                     */
/* ------- USBPLLCLKSEL Bit Fields                  ------ */
#define SYSCON_USBPLLCLKSEL_SEL_MASK             (0x3U)                                              /*!< SYSCON_USBPLLCLKSEL: SEL Mask           */
#define SYSCON_USBPLLCLKSEL_SEL_SHIFT            (0U)                                                /*!< SYSCON_USBPLLCLKSEL: SEL Position       */
#define SYSCON_USBPLLCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x))<<SYSCON_USBPLLCLKSEL_SEL_SHIFT))&SYSCON_USBPLLCLKSEL_SEL_MASK) /*!< SYSCON_USBPLLCLKSEL                     */
/* ------- USBPLLCLKUEN Bit Fields                  ------ */
#define SYSCON_USBPLLCLKUEN_ENA_MASK             (0x1U)                                              /*!< SYSCON_USBPLLCLKUEN: ENA Mask           */
#define SYSCON_USBPLLCLKUEN_ENA_SHIFT            (0U)                                                /*!< SYSCON_USBPLLCLKUEN: ENA Position       */
#define SYSCON_USBPLLCLKUEN_ENA(x)               (((uint32_t)(((uint32_t)(x))<<SYSCON_USBPLLCLKUEN_ENA_SHIFT))&SYSCON_USBPLLCLKUEN_ENA_MASK) /*!< SYSCON_USBPLLCLKUEN                     */
/* ------- MAINCLKSEL Bit Fields                    ------ */
#define SYSCON_MAINCLKSEL_SEL_MASK               (0x3U)                                              /*!< SYSCON_MAINCLKSEL: SEL Mask             */
#define SYSCON_MAINCLKSEL_SEL_SHIFT              (0U)                                                /*!< SYSCON_MAINCLKSEL: SEL Position         */
#define SYSCON_MAINCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_MAINCLKSEL_SEL_SHIFT))&SYSCON_MAINCLKSEL_SEL_MASK) /*!< SYSCON_MAINCLKSEL                       */
/* ------- MAINCLKUEN Bit Fields                    ------ */
#define SYSCON_MAINCLKUEN_ENA_MASK               (0x1U)                                              /*!< SYSCON_MAINCLKUEN: ENA Mask             */
#define SYSCON_MAINCLKUEN_ENA_SHIFT              (0U)                                                /*!< SYSCON_MAINCLKUEN: ENA Position         */
#define SYSCON_MAINCLKUEN_ENA(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_MAINCLKUEN_ENA_SHIFT))&SYSCON_MAINCLKUEN_ENA_MASK) /*!< SYSCON_MAINCLKUEN                       */
/* ------- SYSAHBCLKDIV Bit Fields                  ------ */
#define SYSCON_SYSAHBCLKDIV_DIV_MASK             (0xFFU)                                             /*!< SYSCON_SYSAHBCLKDIV: DIV Mask           */
#define SYSCON_SYSAHBCLKDIV_DIV_SHIFT            (0U)                                                /*!< SYSCON_SYSAHBCLKDIV: DIV Position       */
#define SYSCON_SYSAHBCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKDIV_DIV_SHIFT))&SYSCON_SYSAHBCLKDIV_DIV_MASK) /*!< SYSCON_SYSAHBCLKDIV                     */
/* ------- SYSAHBCLKCTRL Bit Fields                 ------ */
#define SYSCON_SYSAHBCLKCTRL_SYS_MASK            (0x1U)                                              /*!< SYSCON_SYSAHBCLKCTRL: SYS Mask          */
#define SYSCON_SYSAHBCLKCTRL_SYS_SHIFT           (0U)                                                /*!< SYSCON_SYSAHBCLKCTRL: SYS Position      */
#define SYSCON_SYSAHBCLKCTRL_SYS(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_SYS_SHIFT))&SYSCON_SYSAHBCLKCTRL_SYS_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_ROM_MASK            (0x2U)                                              /*!< SYSCON_SYSAHBCLKCTRL: ROM Mask          */
#define SYSCON_SYSAHBCLKCTRL_ROM_SHIFT           (1U)                                                /*!< SYSCON_SYSAHBCLKCTRL: ROM Position      */
#define SYSCON_SYSAHBCLKCTRL_ROM(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_ROM_SHIFT))&SYSCON_SYSAHBCLKCTRL_ROM_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_RAM0_MASK           (0x4U)                                              /*!< SYSCON_SYSAHBCLKCTRL: RAM0 Mask         */
#define SYSCON_SYSAHBCLKCTRL_RAM0_SHIFT          (2U)                                                /*!< SYSCON_SYSAHBCLKCTRL: RAM0 Position     */
#define SYSCON_SYSAHBCLKCTRL_RAM0(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_RAM0_SHIFT))&SYSCON_SYSAHBCLKCTRL_RAM0_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK       (0x8U)                                              /*!< SYSCON_SYSAHBCLKCTRL: FLASHREG Mask     */
#define SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT      (3U)                                                /*!< SYSCON_SYSAHBCLKCTRL: FLASHREG Position */
#define SYSCON_SYSAHBCLKCTRL_FLASHREG(x)         (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT))&SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK     (0x10U)                                             /*!< SYSCON_SYSAHBCLKCTRL: FLASHARRAY Mask   */
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY_SHIFT    (4U)                                                /*!< SYSCON_SYSAHBCLKCTRL: FLASHARRAY Position*/
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY(x)       (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_FLASHARRAY_SHIFT))&SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_I2C_MASK            (0x20U)                                             /*!< SYSCON_SYSAHBCLKCTRL: I2C Mask          */
#define SYSCON_SYSAHBCLKCTRL_I2C_SHIFT           (5U)                                                /*!< SYSCON_SYSAHBCLKCTRL: I2C Position      */
#define SYSCON_SYSAHBCLKCTRL_I2C(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_I2C_SHIFT))&SYSCON_SYSAHBCLKCTRL_I2C_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_GPIO_MASK           (0x40U)                                             /*!< SYSCON_SYSAHBCLKCTRL: GPIO Mask         */
#define SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT          (6U)                                                /*!< SYSCON_SYSAHBCLKCTRL: GPIO Position     */
#define SYSCON_SYSAHBCLKCTRL_GPIO(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT))&SYSCON_SYSAHBCLKCTRL_GPIO_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_CT16B0_MASK         (0x80U)                                             /*!< SYSCON_SYSAHBCLKCTRL: CT16B0 Mask       */
#define SYSCON_SYSAHBCLKCTRL_CT16B0_SHIFT        (7U)                                                /*!< SYSCON_SYSAHBCLKCTRL: CT16B0 Position   */
#define SYSCON_SYSAHBCLKCTRL_CT16B0(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_CT16B0_SHIFT))&SYSCON_SYSAHBCLKCTRL_CT16B0_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_CT16B1_MASK         (0x100U)                                            /*!< SYSCON_SYSAHBCLKCTRL: CT16B1 Mask       */
#define SYSCON_SYSAHBCLKCTRL_CT16B1_SHIFT        (8U)                                                /*!< SYSCON_SYSAHBCLKCTRL: CT16B1 Position   */
#define SYSCON_SYSAHBCLKCTRL_CT16B1(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_CT16B1_SHIFT))&SYSCON_SYSAHBCLKCTRL_CT16B1_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_CT32B0_MASK         (0x200U)                                            /*!< SYSCON_SYSAHBCLKCTRL: CT32B0 Mask       */
#define SYSCON_SYSAHBCLKCTRL_CT32B0_SHIFT        (9U)                                                /*!< SYSCON_SYSAHBCLKCTRL: CT32B0 Position   */
#define SYSCON_SYSAHBCLKCTRL_CT32B0(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_CT32B0_SHIFT))&SYSCON_SYSAHBCLKCTRL_CT32B0_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_CT32B1_MASK         (0x400U)                                            /*!< SYSCON_SYSAHBCLKCTRL: CT32B1 Mask       */
#define SYSCON_SYSAHBCLKCTRL_CT32B1_SHIFT        (10U)                                               /*!< SYSCON_SYSAHBCLKCTRL: CT32B1 Position   */
#define SYSCON_SYSAHBCLKCTRL_CT32B1(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_CT32B1_SHIFT))&SYSCON_SYSAHBCLKCTRL_CT32B1_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_SSP0_MASK           (0x800U)                                            /*!< SYSCON_SYSAHBCLKCTRL: SSP0 Mask         */
#define SYSCON_SYSAHBCLKCTRL_SSP0_SHIFT          (11U)                                               /*!< SYSCON_SYSAHBCLKCTRL: SSP0 Position     */
#define SYSCON_SYSAHBCLKCTRL_SSP0(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_SSP0_SHIFT))&SYSCON_SYSAHBCLKCTRL_SSP0_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_USART_MASK          (0x1000U)                                           /*!< SYSCON_SYSAHBCLKCTRL: USART Mask        */
#define SYSCON_SYSAHBCLKCTRL_USART_SHIFT         (12U)                                               /*!< SYSCON_SYSAHBCLKCTRL: USART Position    */
#define SYSCON_SYSAHBCLKCTRL_USART(x)            (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_USART_SHIFT))&SYSCON_SYSAHBCLKCTRL_USART_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_ADC_MASK            (0x2000U)                                           /*!< SYSCON_SYSAHBCLKCTRL: ADC Mask          */
#define SYSCON_SYSAHBCLKCTRL_ADC_SHIFT           (13U)                                               /*!< SYSCON_SYSAHBCLKCTRL: ADC Position      */
#define SYSCON_SYSAHBCLKCTRL_ADC(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_ADC_SHIFT))&SYSCON_SYSAHBCLKCTRL_ADC_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_USB_MASK            (0x4000U)                                           /*!< SYSCON_SYSAHBCLKCTRL: USB Mask          */
#define SYSCON_SYSAHBCLKCTRL_USB_SHIFT           (14U)                                               /*!< SYSCON_SYSAHBCLKCTRL: USB Position      */
#define SYSCON_SYSAHBCLKCTRL_USB(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_USB_SHIFT))&SYSCON_SYSAHBCLKCTRL_USB_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_WWDT_MASK           (0x8000U)                                           /*!< SYSCON_SYSAHBCLKCTRL: WWDT Mask         */
#define SYSCON_SYSAHBCLKCTRL_WWDT_SHIFT          (15U)                                               /*!< SYSCON_SYSAHBCLKCTRL: WWDT Position     */
#define SYSCON_SYSAHBCLKCTRL_WWDT(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_WWDT_SHIFT))&SYSCON_SYSAHBCLKCTRL_WWDT_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_IOCON_MASK          (0x10000U)                                          /*!< SYSCON_SYSAHBCLKCTRL: IOCON Mask        */
#define SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT         (16U)                                               /*!< SYSCON_SYSAHBCLKCTRL: IOCON Position    */
#define SYSCON_SYSAHBCLKCTRL_IOCON(x)            (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT))&SYSCON_SYSAHBCLKCTRL_IOCON_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_SSP1_MASK           (0x40000U)                                          /*!< SYSCON_SYSAHBCLKCTRL: SSP1 Mask         */
#define SYSCON_SYSAHBCLKCTRL_SSP1_SHIFT          (18U)                                               /*!< SYSCON_SYSAHBCLKCTRL: SSP1 Position     */
#define SYSCON_SYSAHBCLKCTRL_SSP1(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_SSP1_SHIFT))&SYSCON_SYSAHBCLKCTRL_SSP1_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_PINT_MASK           (0x80000U)                                          /*!< SYSCON_SYSAHBCLKCTRL: PINT Mask         */
#define SYSCON_SYSAHBCLKCTRL_PINT_SHIFT          (19U)                                               /*!< SYSCON_SYSAHBCLKCTRL: PINT Position     */
#define SYSCON_SYSAHBCLKCTRL_PINT(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_PINT_SHIFT))&SYSCON_SYSAHBCLKCTRL_PINT_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_GROUP0INT_MASK      (0x800000U)                                         /*!< SYSCON_SYSAHBCLKCTRL: GROUP0INT Mask    */
#define SYSCON_SYSAHBCLKCTRL_GROUP0INT_SHIFT     (23U)                                               /*!< SYSCON_SYSAHBCLKCTRL: GROUP0INT Position*/
#define SYSCON_SYSAHBCLKCTRL_GROUP0INT(x)        (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_GROUP0INT_SHIFT))&SYSCON_SYSAHBCLKCTRL_GROUP0INT_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_GROUP1INT_MASK      (0x1000000U)                                        /*!< SYSCON_SYSAHBCLKCTRL: GROUP1INT Mask    */
#define SYSCON_SYSAHBCLKCTRL_GROUP1INT_SHIFT     (24U)                                               /*!< SYSCON_SYSAHBCLKCTRL: GROUP1INT Position*/
#define SYSCON_SYSAHBCLKCTRL_GROUP1INT(x)        (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_GROUP1INT_SHIFT))&SYSCON_SYSAHBCLKCTRL_GROUP1INT_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_RAM1_MASK           (0x4000000U)                                        /*!< SYSCON_SYSAHBCLKCTRL: RAM1 Mask         */
#define SYSCON_SYSAHBCLKCTRL_RAM1_SHIFT          (26U)                                               /*!< SYSCON_SYSAHBCLKCTRL: RAM1 Position     */
#define SYSCON_SYSAHBCLKCTRL_RAM1(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_RAM1_SHIFT))&SYSCON_SYSAHBCLKCTRL_RAM1_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
#define SYSCON_SYSAHBCLKCTRL_USBRAM_MASK         (0x8000000U)                                        /*!< SYSCON_SYSAHBCLKCTRL: USBRAM Mask       */
#define SYSCON_SYSAHBCLKCTRL_USBRAM_SHIFT        (27U)                                               /*!< SYSCON_SYSAHBCLKCTRL: USBRAM Position   */
#define SYSCON_SYSAHBCLKCTRL_USBRAM(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSAHBCLKCTRL_USBRAM_SHIFT))&SYSCON_SYSAHBCLKCTRL_USBRAM_MASK) /*!< SYSCON_SYSAHBCLKCTRL                    */
/* ------- SSP0CLKDIV Bit Fields                    ------ */
#define SYSCON_SSP0CLKDIV_DIV_MASK               (0xFFU)                                             /*!< SYSCON_SSP0CLKDIV: DIV Mask             */
#define SYSCON_SSP0CLKDIV_DIV_SHIFT              (0U)                                                /*!< SYSCON_SSP0CLKDIV: DIV Position         */
#define SYSCON_SSP0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_SSP0CLKDIV_DIV_SHIFT))&SYSCON_SSP0CLKDIV_DIV_MASK) /*!< SYSCON_SSP0CLKDIV                       */
/* ------- UARTCLKDIV Bit Fields                    ------ */
#define SYSCON_UARTCLKDIV_DIV_MASK               (0xFFU)                                             /*!< SYSCON_UARTCLKDIV: DIV Mask             */
#define SYSCON_UARTCLKDIV_DIV_SHIFT              (0U)                                                /*!< SYSCON_UARTCLKDIV: DIV Position         */
#define SYSCON_UARTCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_UARTCLKDIV_DIV_SHIFT))&SYSCON_UARTCLKDIV_DIV_MASK) /*!< SYSCON_UARTCLKDIV                       */
/* ------- SSP1CLKDIV Bit Fields                    ------ */
#define SYSCON_SSP1CLKDIV_DIV_MASK               (0xFFU)                                             /*!< SYSCON_SSP1CLKDIV: DIV Mask             */
#define SYSCON_SSP1CLKDIV_DIV_SHIFT              (0U)                                                /*!< SYSCON_SSP1CLKDIV: DIV Position         */
#define SYSCON_SSP1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_SSP1CLKDIV_DIV_SHIFT))&SYSCON_SSP1CLKDIV_DIV_MASK) /*!< SYSCON_SSP1CLKDIV                       */
/* ------- USBCLKSEL Bit Fields                     ------ */
#define SYSCON_USBCLKSEL_SEL_MASK                (0x3U)                                              /*!< SYSCON_USBCLKSEL: SEL Mask              */
#define SYSCON_USBCLKSEL_SEL_SHIFT               (0U)                                                /*!< SYSCON_USBCLKSEL: SEL Position          */
#define SYSCON_USBCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCON_USBCLKSEL_SEL_SHIFT))&SYSCON_USBCLKSEL_SEL_MASK) /*!< SYSCON_USBCLKSEL                        */
/* ------- USBCLKUEN Bit Fields                     ------ */
#define SYSCON_USBCLKUEN_ENA_MASK                (0x1U)                                              /*!< SYSCON_USBCLKUEN: ENA Mask              */
#define SYSCON_USBCLKUEN_ENA_SHIFT               (0U)                                                /*!< SYSCON_USBCLKUEN: ENA Position          */
#define SYSCON_USBCLKUEN_ENA(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCON_USBCLKUEN_ENA_SHIFT))&SYSCON_USBCLKUEN_ENA_MASK) /*!< SYSCON_USBCLKUEN                        */
/* ------- USBCLKDIV Bit Fields                     ------ */
#define SYSCON_USBCLKDIV_DIV_MASK                (0xFFU)                                             /*!< SYSCON_USBCLKDIV: DIV Mask              */
#define SYSCON_USBCLKDIV_DIV_SHIFT               (0U)                                                /*!< SYSCON_USBCLKDIV: DIV Position          */
#define SYSCON_USBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCON_USBCLKDIV_DIV_SHIFT))&SYSCON_USBCLKDIV_DIV_MASK) /*!< SYSCON_USBCLKDIV                        */
/* ------- CLKOUTSEL Bit Fields                     ------ */
#define SYSCON_CLKOUTSEL_SEL_MASK                (0x3U)                                              /*!< SYSCON_CLKOUTSEL: SEL Mask              */
#define SYSCON_CLKOUTSEL_SEL_SHIFT               (0U)                                                /*!< SYSCON_CLKOUTSEL: SEL Position          */
#define SYSCON_CLKOUTSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCON_CLKOUTSEL_SEL_SHIFT))&SYSCON_CLKOUTSEL_SEL_MASK) /*!< SYSCON_CLKOUTSEL                        */
/* ------- CLKOUTUEN Bit Fields                     ------ */
#define SYSCON_CLKOUTUEN_ENA_MASK                (0x1U)                                              /*!< SYSCON_CLKOUTUEN: ENA Mask              */
#define SYSCON_CLKOUTUEN_ENA_SHIFT               (0U)                                                /*!< SYSCON_CLKOUTUEN: ENA Position          */
#define SYSCON_CLKOUTUEN_ENA(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCON_CLKOUTUEN_ENA_SHIFT))&SYSCON_CLKOUTUEN_ENA_MASK) /*!< SYSCON_CLKOUTUEN                        */
/* ------- CLKOUTDIV Bit Fields                     ------ */
#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)                                             /*!< SYSCON_CLKOUTDIV: DIV Mask              */
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)                                                /*!< SYSCON_CLKOUTDIV: DIV Position          */
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCON_CLKOUTDIV_DIV_SHIFT))&SYSCON_CLKOUTDIV_DIV_MASK) /*!< SYSCON_CLKOUTDIV                        */
/* ------- PIOPORCAP0 Bit Fields                    ------ */
#define SYSCON_PIOPORCAP0_PIOSTAT_MASK           (0xFFFFFFU)                                         /*!< SYSCON_PIOPORCAP0: PIOSTAT Mask         */
#define SYSCON_PIOPORCAP0_PIOSTAT_SHIFT          (0U)                                                /*!< SYSCON_PIOPORCAP0: PIOSTAT Position     */
#define SYSCON_PIOPORCAP0_PIOSTAT(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_PIOPORCAP0_PIOSTAT_SHIFT))&SYSCON_PIOPORCAP0_PIOSTAT_MASK) /*!< SYSCON_PIOPORCAP0                       */
/* ------- PIOPORCAP1 Bit Fields                    ------ */
#define SYSCON_PIOPORCAP1_PIOSTAT_MASK           (0xFFFFFFFFU)                                       /*!< SYSCON_PIOPORCAP1: PIOSTAT Mask         */
#define SYSCON_PIOPORCAP1_PIOSTAT_SHIFT          (0U)                                                /*!< SYSCON_PIOPORCAP1: PIOSTAT Position     */
#define SYSCON_PIOPORCAP1_PIOSTAT(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_PIOPORCAP1_PIOSTAT_SHIFT))&SYSCON_PIOPORCAP1_PIOSTAT_MASK) /*!< SYSCON_PIOPORCAP1                       */
/* ------- BODCTRL Bit Fields                       ------ */
#define SYSCON_BODCTRL_BODRSTLEV_MASK            (0x3U)                                              /*!< SYSCON_BODCTRL: BODRSTLEV Mask          */
#define SYSCON_BODCTRL_BODRSTLEV_SHIFT           (0U)                                                /*!< SYSCON_BODCTRL: BODRSTLEV Position      */
#define SYSCON_BODCTRL_BODRSTLEV(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_BODCTRL_BODRSTLEV_SHIFT))&SYSCON_BODCTRL_BODRSTLEV_MASK) /*!< SYSCON_BODCTRL                          */
#define SYSCON_BODCTRL_BODINTVAL_MASK            (0xCU)                                              /*!< SYSCON_BODCTRL: BODINTVAL Mask          */
#define SYSCON_BODCTRL_BODINTVAL_SHIFT           (2U)                                                /*!< SYSCON_BODCTRL: BODINTVAL Position      */
#define SYSCON_BODCTRL_BODINTVAL(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_BODCTRL_BODINTVAL_SHIFT))&SYSCON_BODCTRL_BODINTVAL_MASK) /*!< SYSCON_BODCTRL                          */
#define SYSCON_BODCTRL_BODRSTENA_MASK            (0x10U)                                             /*!< SYSCON_BODCTRL: BODRSTENA Mask          */
#define SYSCON_BODCTRL_BODRSTENA_SHIFT           (4U)                                                /*!< SYSCON_BODCTRL: BODRSTENA Position      */
#define SYSCON_BODCTRL_BODRSTENA(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_BODCTRL_BODRSTENA_SHIFT))&SYSCON_BODCTRL_BODRSTENA_MASK) /*!< SYSCON_BODCTRL                          */
/* ------- SYSTCKCAL Bit Fields                     ------ */
#define SYSCON_SYSTCKCAL_CAL_MASK                (0x3FFFFFFU)                                        /*!< SYSCON_SYSTCKCAL: CAL Mask              */
#define SYSCON_SYSTCKCAL_CAL_SHIFT               (0U)                                                /*!< SYSCON_SYSTCKCAL: CAL Position          */
#define SYSCON_SYSTCKCAL_CAL(x)                  (((uint32_t)(((uint32_t)(x))<<SYSCON_SYSTCKCAL_CAL_SHIFT))&SYSCON_SYSTCKCAL_CAL_MASK) /*!< SYSCON_SYSTCKCAL                        */
/* ------- IRQLATENCY Bit Fields                    ------ */
#define SYSCON_IRQLATENCY_LATENCY_MASK           (0xFFU)                                             /*!< SYSCON_IRQLATENCY: LATENCY Mask         */
#define SYSCON_IRQLATENCY_LATENCY_SHIFT          (0U)                                                /*!< SYSCON_IRQLATENCY: LATENCY Position     */
#define SYSCON_IRQLATENCY_LATENCY(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_IRQLATENCY_LATENCY_SHIFT))&SYSCON_IRQLATENCY_LATENCY_MASK) /*!< SYSCON_IRQLATENCY                       */
/* ------- NMISRC Bit Fields                        ------ */
#define SYSCON_NMISRC_IRQNO_MASK                 (0x1FU)                                             /*!< SYSCON_NMISRC: IRQNO Mask               */
#define SYSCON_NMISRC_IRQNO_SHIFT                (0U)                                                /*!< SYSCON_NMISRC: IRQNO Position           */
#define SYSCON_NMISRC_IRQNO(x)                   (((uint32_t)(((uint32_t)(x))<<SYSCON_NMISRC_IRQNO_SHIFT))&SYSCON_NMISRC_IRQNO_MASK) /*!< SYSCON_NMISRC                           */
#define SYSCON_NMISRC_NMIEN_MASK                 (0x80000000U)                                       /*!< SYSCON_NMISRC: NMIEN Mask               */
#define SYSCON_NMISRC_NMIEN_SHIFT                (31U)                                               /*!< SYSCON_NMISRC: NMIEN Position           */
#define SYSCON_NMISRC_NMIEN(x)                   (((uint32_t)(((uint32_t)(x))<<SYSCON_NMISRC_NMIEN_SHIFT))&SYSCON_NMISRC_NMIEN_MASK) /*!< SYSCON_NMISRC                           */
/* ------- PINTSEL Bit Fields                       ------ */
#define SYSCON_PINTSEL_INTPIN_MASK               (0x3FU)                                             /*!< SYSCON_PINTSEL: INTPIN Mask             */
#define SYSCON_PINTSEL_INTPIN_SHIFT              (0U)                                                /*!< SYSCON_PINTSEL: INTPIN Position         */
#define SYSCON_PINTSEL_INTPIN(x)                 (((uint32_t)(((uint32_t)(x))<<SYSCON_PINTSEL_INTPIN_SHIFT))&SYSCON_PINTSEL_INTPIN_MASK) /*!< SYSCON_PINTSEL                          */
/* ------- USBCLKCTRL Bit Fields                    ------ */
#define SYSCON_USBCLKCTRL_AP_CLK_MASK            (0x1U)                                              /*!< SYSCON_USBCLKCTRL: AP_CLK Mask          */
#define SYSCON_USBCLKCTRL_AP_CLK_SHIFT           (0U)                                                /*!< SYSCON_USBCLKCTRL: AP_CLK Position      */
#define SYSCON_USBCLKCTRL_AP_CLK(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_USBCLKCTRL_AP_CLK_SHIFT))&SYSCON_USBCLKCTRL_AP_CLK_MASK) /*!< SYSCON_USBCLKCTRL                       */
#define SYSCON_USBCLKCTRL_POL_CLK_MASK           (0x2U)                                              /*!< SYSCON_USBCLKCTRL: POL_CLK Mask         */
#define SYSCON_USBCLKCTRL_POL_CLK_SHIFT          (1U)                                                /*!< SYSCON_USBCLKCTRL: POL_CLK Position     */
#define SYSCON_USBCLKCTRL_POL_CLK(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_USBCLKCTRL_POL_CLK_SHIFT))&SYSCON_USBCLKCTRL_POL_CLK_MASK) /*!< SYSCON_USBCLKCTRL                       */
/* ------- USBCLKST Bit Fields                      ------ */
#define SYSCON_USBCLKST_NEED_CLKST_MASK          (0x1U)                                              /*!< SYSCON_USBCLKST: NEED_CLKST Mask        */
#define SYSCON_USBCLKST_NEED_CLKST_SHIFT         (0U)                                                /*!< SYSCON_USBCLKST: NEED_CLKST Position    */
#define SYSCON_USBCLKST_NEED_CLKST(x)            (((uint32_t)(((uint32_t)(x))<<SYSCON_USBCLKST_NEED_CLKST_SHIFT))&SYSCON_USBCLKST_NEED_CLKST_MASK) /*!< SYSCON_USBCLKST                         */
/* ------- STARTERP0 Bit Fields                     ------ */
#define SYSCON_STARTERP0_PINT0_MASK              (0x1U)                                              /*!< SYSCON_STARTERP0: PINT0 Mask            */
#define SYSCON_STARTERP0_PINT0_SHIFT             (0U)                                                /*!< SYSCON_STARTERP0: PINT0 Position        */
#define SYSCON_STARTERP0_PINT0(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP0_PINT0_SHIFT))&SYSCON_STARTERP0_PINT0_MASK) /*!< SYSCON_STARTERP0                        */
#define SYSCON_STARTERP0_PINT1_MASK              (0x2U)                                              /*!< SYSCON_STARTERP0: PINT1 Mask            */
#define SYSCON_STARTERP0_PINT1_SHIFT             (1U)                                                /*!< SYSCON_STARTERP0: PINT1 Position        */
#define SYSCON_STARTERP0_PINT1(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP0_PINT1_SHIFT))&SYSCON_STARTERP0_PINT1_MASK) /*!< SYSCON_STARTERP0                        */
#define SYSCON_STARTERP0_PINT2_MASK              (0x4U)                                              /*!< SYSCON_STARTERP0: PINT2 Mask            */
#define SYSCON_STARTERP0_PINT2_SHIFT             (2U)                                                /*!< SYSCON_STARTERP0: PINT2 Position        */
#define SYSCON_STARTERP0_PINT2(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP0_PINT2_SHIFT))&SYSCON_STARTERP0_PINT2_MASK) /*!< SYSCON_STARTERP0                        */
#define SYSCON_STARTERP0_PINT3_MASK              (0x8U)                                              /*!< SYSCON_STARTERP0: PINT3 Mask            */
#define SYSCON_STARTERP0_PINT3_SHIFT             (3U)                                                /*!< SYSCON_STARTERP0: PINT3 Position        */
#define SYSCON_STARTERP0_PINT3(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP0_PINT3_SHIFT))&SYSCON_STARTERP0_PINT3_MASK) /*!< SYSCON_STARTERP0                        */
#define SYSCON_STARTERP0_PINT4_MASK              (0x10U)                                             /*!< SYSCON_STARTERP0: PINT4 Mask            */
#define SYSCON_STARTERP0_PINT4_SHIFT             (4U)                                                /*!< SYSCON_STARTERP0: PINT4 Position        */
#define SYSCON_STARTERP0_PINT4(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP0_PINT4_SHIFT))&SYSCON_STARTERP0_PINT4_MASK) /*!< SYSCON_STARTERP0                        */
#define SYSCON_STARTERP0_PINT5_MASK              (0x20U)                                             /*!< SYSCON_STARTERP0: PINT5 Mask            */
#define SYSCON_STARTERP0_PINT5_SHIFT             (5U)                                                /*!< SYSCON_STARTERP0: PINT5 Position        */
#define SYSCON_STARTERP0_PINT5(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP0_PINT5_SHIFT))&SYSCON_STARTERP0_PINT5_MASK) /*!< SYSCON_STARTERP0                        */
#define SYSCON_STARTERP0_PINT6_MASK              (0x40U)                                             /*!< SYSCON_STARTERP0: PINT6 Mask            */
#define SYSCON_STARTERP0_PINT6_SHIFT             (6U)                                                /*!< SYSCON_STARTERP0: PINT6 Position        */
#define SYSCON_STARTERP0_PINT6(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP0_PINT6_SHIFT))&SYSCON_STARTERP0_PINT6_MASK) /*!< SYSCON_STARTERP0                        */
#define SYSCON_STARTERP0_PINT7_MASK              (0x80U)                                             /*!< SYSCON_STARTERP0: PINT7 Mask            */
#define SYSCON_STARTERP0_PINT7_SHIFT             (7U)                                                /*!< SYSCON_STARTERP0: PINT7 Position        */
#define SYSCON_STARTERP0_PINT7(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP0_PINT7_SHIFT))&SYSCON_STARTERP0_PINT7_MASK) /*!< SYSCON_STARTERP0                        */
/* ------- STARTERP1 Bit Fields                     ------ */
#define SYSCON_STARTERP1_WWDTINT_MASK            (0x1000U)                                           /*!< SYSCON_STARTERP1: WWDTINT Mask          */
#define SYSCON_STARTERP1_WWDTINT_SHIFT           (12U)                                               /*!< SYSCON_STARTERP1: WWDTINT Position      */
#define SYSCON_STARTERP1_WWDTINT(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP1_WWDTINT_SHIFT))&SYSCON_STARTERP1_WWDTINT_MASK) /*!< SYSCON_STARTERP1                        */
#define SYSCON_STARTERP1_BODINT_MASK             (0x2000U)                                           /*!< SYSCON_STARTERP1: BODINT Mask           */
#define SYSCON_STARTERP1_BODINT_SHIFT            (13U)                                               /*!< SYSCON_STARTERP1: BODINT Position       */
#define SYSCON_STARTERP1_BODINT(x)               (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP1_BODINT_SHIFT))&SYSCON_STARTERP1_BODINT_MASK) /*!< SYSCON_STARTERP1                        */
#define SYSCON_STARTERP1_USB_WAKEUP_MASK         (0x80000U)                                          /*!< SYSCON_STARTERP1: USB_WAKEUP Mask       */
#define SYSCON_STARTERP1_USB_WAKEUP_SHIFT        (19U)                                               /*!< SYSCON_STARTERP1: USB_WAKEUP Position   */
#define SYSCON_STARTERP1_USB_WAKEUP(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP1_USB_WAKEUP_SHIFT))&SYSCON_STARTERP1_USB_WAKEUP_MASK) /*!< SYSCON_STARTERP1                        */
#define SYSCON_STARTERP1_GPIOINT0_MASK           (0x100000U)                                         /*!< SYSCON_STARTERP1: GPIOINT0 Mask         */
#define SYSCON_STARTERP1_GPIOINT0_SHIFT          (20U)                                               /*!< SYSCON_STARTERP1: GPIOINT0 Position     */
#define SYSCON_STARTERP1_GPIOINT0(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP1_GPIOINT0_SHIFT))&SYSCON_STARTERP1_GPIOINT0_MASK) /*!< SYSCON_STARTERP1                        */
#define SYSCON_STARTERP1_GPIOINT1_MASK           (0x200000U)                                         /*!< SYSCON_STARTERP1: GPIOINT1 Mask         */
#define SYSCON_STARTERP1_GPIOINT1_SHIFT          (21U)                                               /*!< SYSCON_STARTERP1: GPIOINT1 Position     */
#define SYSCON_STARTERP1_GPIOINT1(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_STARTERP1_GPIOINT1_SHIFT))&SYSCON_STARTERP1_GPIOINT1_MASK) /*!< SYSCON_STARTERP1                        */
/* ------- PDSLEEPCFG Bit Fields                    ------ */
#define SYSCON_PDSLEEPCFG_BOD_PD_MASK            (0x8U)                                              /*!< SYSCON_PDSLEEPCFG: BOD_PD Mask          */
#define SYSCON_PDSLEEPCFG_BOD_PD_SHIFT           (3U)                                                /*!< SYSCON_PDSLEEPCFG: BOD_PD Position      */
#define SYSCON_PDSLEEPCFG_BOD_PD(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_PDSLEEPCFG_BOD_PD_SHIFT))&SYSCON_PDSLEEPCFG_BOD_PD_MASK) /*!< SYSCON_PDSLEEPCFG                       */
#define SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK         (0x40U)                                             /*!< SYSCON_PDSLEEPCFG: WDTOSC_PD Mask       */
#define SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT        (6U)                                                /*!< SYSCON_PDSLEEPCFG: WDTOSC_PD Position   */
#define SYSCON_PDSLEEPCFG_WDTOSC_PD(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT))&SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK) /*!< SYSCON_PDSLEEPCFG                       */
/* ------- PDAWAKECFG Bit Fields                    ------ */
#define SYSCON_PDAWAKECFG_IRCOUT_PD_MASK         (0x1U)                                              /*!< SYSCON_PDAWAKECFG: IRCOUT_PD Mask       */
#define SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT        (0U)                                                /*!< SYSCON_PDAWAKECFG: IRCOUT_PD Position   */
#define SYSCON_PDAWAKECFG_IRCOUT_PD(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT))&SYSCON_PDAWAKECFG_IRCOUT_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_IRC_PD_MASK            (0x2U)                                              /*!< SYSCON_PDAWAKECFG: IRC_PD Mask          */
#define SYSCON_PDAWAKECFG_IRC_PD_SHIFT           (1U)                                                /*!< SYSCON_PDAWAKECFG: IRC_PD Position      */
#define SYSCON_PDAWAKECFG_IRC_PD(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_IRC_PD_SHIFT))&SYSCON_PDAWAKECFG_IRC_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_FLASH_PD_MASK          (0x4U)                                              /*!< SYSCON_PDAWAKECFG: FLASH_PD Mask        */
#define SYSCON_PDAWAKECFG_FLASH_PD_SHIFT         (2U)                                                /*!< SYSCON_PDAWAKECFG: FLASH_PD Position    */
#define SYSCON_PDAWAKECFG_FLASH_PD(x)            (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_FLASH_PD_SHIFT))&SYSCON_PDAWAKECFG_FLASH_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_BOD_PD_MASK            (0x8U)                                              /*!< SYSCON_PDAWAKECFG: BOD_PD Mask          */
#define SYSCON_PDAWAKECFG_BOD_PD_SHIFT           (3U)                                                /*!< SYSCON_PDAWAKECFG: BOD_PD Position      */
#define SYSCON_PDAWAKECFG_BOD_PD(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_BOD_PD_SHIFT))&SYSCON_PDAWAKECFG_BOD_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_ADC_PD_MASK            (0x10U)                                             /*!< SYSCON_PDAWAKECFG: ADC_PD Mask          */
#define SYSCON_PDAWAKECFG_ADC_PD_SHIFT           (4U)                                                /*!< SYSCON_PDAWAKECFG: ADC_PD Position      */
#define SYSCON_PDAWAKECFG_ADC_PD(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_ADC_PD_SHIFT))&SYSCON_PDAWAKECFG_ADC_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_SYSOSC_PD_MASK         (0x20U)                                             /*!< SYSCON_PDAWAKECFG: SYSOSC_PD Mask       */
#define SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT        (5U)                                                /*!< SYSCON_PDAWAKECFG: SYSOSC_PD Position   */
#define SYSCON_PDAWAKECFG_SYSOSC_PD(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT))&SYSCON_PDAWAKECFG_SYSOSC_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_WDTOSC_PD_MASK         (0x40U)                                             /*!< SYSCON_PDAWAKECFG: WDTOSC_PD Mask       */
#define SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT        (6U)                                                /*!< SYSCON_PDAWAKECFG: WDTOSC_PD Position   */
#define SYSCON_PDAWAKECFG_WDTOSC_PD(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT))&SYSCON_PDAWAKECFG_WDTOSC_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_SYSPLL_PD_MASK         (0x80U)                                             /*!< SYSCON_PDAWAKECFG: SYSPLL_PD Mask       */
#define SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT        (7U)                                                /*!< SYSCON_PDAWAKECFG: SYSPLL_PD Position   */
#define SYSCON_PDAWAKECFG_SYSPLL_PD(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT))&SYSCON_PDAWAKECFG_SYSPLL_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_USBPLL_PD_MASK         (0x100U)                                            /*!< SYSCON_PDAWAKECFG: USBPLL_PD Mask       */
#define SYSCON_PDAWAKECFG_USBPLL_PD_SHIFT        (8U)                                                /*!< SYSCON_PDAWAKECFG: USBPLL_PD Position   */
#define SYSCON_PDAWAKECFG_USBPLL_PD(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_USBPLL_PD_SHIFT))&SYSCON_PDAWAKECFG_USBPLL_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
#define SYSCON_PDAWAKECFG_USBPAD_PD_MASK         (0x400U)                                            /*!< SYSCON_PDAWAKECFG: USBPAD_PD Mask       */
#define SYSCON_PDAWAKECFG_USBPAD_PD_SHIFT        (10U)                                               /*!< SYSCON_PDAWAKECFG: USBPAD_PD Position   */
#define SYSCON_PDAWAKECFG_USBPAD_PD(x)           (((uint32_t)(((uint32_t)(x))<<SYSCON_PDAWAKECFG_USBPAD_PD_SHIFT))&SYSCON_PDAWAKECFG_USBPAD_PD_MASK) /*!< SYSCON_PDAWAKECFG                       */
/* ------- PDRUNCFG Bit Fields                      ------ */
#define SYSCON_PDRUNCFG_IRCOUT_PD_MASK           (0x1U)                                              /*!< SYSCON_PDRUNCFG: IRCOUT_PD Mask         */
#define SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT          (0U)                                                /*!< SYSCON_PDRUNCFG: IRCOUT_PD Position     */
#define SYSCON_PDRUNCFG_IRCOUT_PD(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT))&SYSCON_PDRUNCFG_IRCOUT_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_IRC_PD_MASK              (0x2U)                                              /*!< SYSCON_PDRUNCFG: IRC_PD Mask            */
#define SYSCON_PDRUNCFG_IRC_PD_SHIFT             (1U)                                                /*!< SYSCON_PDRUNCFG: IRC_PD Position        */
#define SYSCON_PDRUNCFG_IRC_PD(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_IRC_PD_SHIFT))&SYSCON_PDRUNCFG_IRC_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_FLASH_PD_MASK            (0x4U)                                              /*!< SYSCON_PDRUNCFG: FLASH_PD Mask          */
#define SYSCON_PDRUNCFG_FLASH_PD_SHIFT           (2U)                                                /*!< SYSCON_PDRUNCFG: FLASH_PD Position      */
#define SYSCON_PDRUNCFG_FLASH_PD(x)              (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_FLASH_PD_SHIFT))&SYSCON_PDRUNCFG_FLASH_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_BOD_PD_MASK              (0x8U)                                              /*!< SYSCON_PDRUNCFG: BOD_PD Mask            */
#define SYSCON_PDRUNCFG_BOD_PD_SHIFT             (3U)                                                /*!< SYSCON_PDRUNCFG: BOD_PD Position        */
#define SYSCON_PDRUNCFG_BOD_PD(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_BOD_PD_SHIFT))&SYSCON_PDRUNCFG_BOD_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_ADC_PD_MASK              (0x10U)                                             /*!< SYSCON_PDRUNCFG: ADC_PD Mask            */
#define SYSCON_PDRUNCFG_ADC_PD_SHIFT             (4U)                                                /*!< SYSCON_PDRUNCFG: ADC_PD Position        */
#define SYSCON_PDRUNCFG_ADC_PD(x)                (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_ADC_PD_SHIFT))&SYSCON_PDRUNCFG_ADC_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_SYSOSC_PD_MASK           (0x20U)                                             /*!< SYSCON_PDRUNCFG: SYSOSC_PD Mask         */
#define SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT          (5U)                                                /*!< SYSCON_PDRUNCFG: SYSOSC_PD Position     */
#define SYSCON_PDRUNCFG_SYSOSC_PD(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT))&SYSCON_PDRUNCFG_SYSOSC_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_WDTOSC_PD_MASK           (0x40U)                                             /*!< SYSCON_PDRUNCFG: WDTOSC_PD Mask         */
#define SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT          (6U)                                                /*!< SYSCON_PDRUNCFG: WDTOSC_PD Position     */
#define SYSCON_PDRUNCFG_WDTOSC_PD(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT))&SYSCON_PDRUNCFG_WDTOSC_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_SYSPLL_PD_MASK           (0x80U)                                             /*!< SYSCON_PDRUNCFG: SYSPLL_PD Mask         */
#define SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT          (7U)                                                /*!< SYSCON_PDRUNCFG: SYSPLL_PD Position     */
#define SYSCON_PDRUNCFG_SYSPLL_PD(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT))&SYSCON_PDRUNCFG_SYSPLL_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_USBPLL_PD_MASK           (0x100U)                                            /*!< SYSCON_PDRUNCFG: USBPLL_PD Mask         */
#define SYSCON_PDRUNCFG_USBPLL_PD_SHIFT          (8U)                                                /*!< SYSCON_PDRUNCFG: USBPLL_PD Position     */
#define SYSCON_PDRUNCFG_USBPLL_PD(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_USBPLL_PD_SHIFT))&SYSCON_PDRUNCFG_USBPLL_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
#define SYSCON_PDRUNCFG_USBPAD_PD_MASK           (0x400U)                                            /*!< SYSCON_PDRUNCFG: USBPAD_PD Mask         */
#define SYSCON_PDRUNCFG_USBPAD_PD_SHIFT          (10U)                                               /*!< SYSCON_PDRUNCFG: USBPAD_PD Position     */
#define SYSCON_PDRUNCFG_USBPAD_PD(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_PDRUNCFG_USBPAD_PD_SHIFT))&SYSCON_PDRUNCFG_USBPAD_PD_MASK) /*!< SYSCON_PDRUNCFG                         */
/* ------- DEVICE_ID Bit Fields                     ------ */
#define SYSCON_DEVICE_ID_DEVICEID_MASK           (0xFFFFFFFFU)                                       /*!< SYSCON_DEVICE_ID: DEVICEID Mask         */
#define SYSCON_DEVICE_ID_DEVICEID_SHIFT          (0U)                                                /*!< SYSCON_DEVICE_ID: DEVICEID Position     */
#define SYSCON_DEVICE_ID_DEVICEID(x)             (((uint32_t)(((uint32_t)(x))<<SYSCON_DEVICE_ID_DEVICEID_SHIFT))&SYSCON_DEVICE_ID_DEVICEID_MASK) /*!< SYSCON_DEVICE_ID                        */
/**
 * @} */ /* End group SYSCON_Register_Masks_GROUP 
 */

/* SYSCON - Peripheral instance base addresses */
#define SYSCON_BasePtr                 0x40048000UL //!< Peripheral base address
#define SYSCON                         ((SYSCON_Type *) SYSCON_BasePtr) //!< Freescale base pointer
#define SYSCON_BASE_PTR                (SYSCON) //!< Freescale style base pointer
/**
 * @} */ /* End group SYSCON_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USART_Peripheral_access_layer_GROUP USART Peripheral Access Layer
* @brief C Struct for USART
* @{
*/

/* ================================================================================ */
/* ================           USART (file:USART_LPC11Uxx)          ================ */
/* ================================================================================ */

/**
 * @brief USART
 */
/**
* @addtogroup USART_structs_GROUP USART struct
* @brief Struct for USART
* @{
*/
typedef struct {                                /*       USART Structure                                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DLL;                       /**< 0000: Divisor Latch LSB. Least significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. (DLAB=1) */
      __I  uint32_t  RBR;                       /**< 0000: Receiver Buffer Register. Contains the next received character to be read. (DLAB=0) */
      __O  uint32_t  THR;                       /**< 0000: Transmit Holding Register. The next character to be transmitted is written here. (DLAB=0) */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DLM;                       /**< 0004: Divisor Latch MSB. Most significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. (DLAB=1) */
      __IO uint32_t  IER;                       /**< 0004: Interrupt Enable Register. Contains individual interrupt enable bits for the 7 potential USART interrupts. (DLAB=0) */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
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
        uint8_t   RESERVED_0[12];              
   __IO uint32_t  HDEN;                         /**< 0040: Half duplex enable register                                  */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  SCICTRL;                      /**< 0048: Smart Card Interface Control register. Enables and configures the Smart Card Interface feature */
   __IO uint32_t  RS485CTRL;                    /**< 004C: RS-485/EIA-485 Control. Contains controls to configure various aspects of RS-485/EIA-485 modes */
   __IO uint32_t  RS485ADRMATCH;                /**< 0050: RS-485/EIA-485 address match. Contains the address match value for RS-485/EIA-485 mode */
   __IO uint32_t  RS485DLY;                     /**< 0054: RS-485/EIA-485 direction control delay                       */
   __IO uint32_t  SYNCCTRL;                     /**< 0058: Synchronous mode control register                            */
} USART_Type;

/**
 * @} */ /* End group USART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'USART' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup USART_Register_Masks_GROUP USART Register Masks
* @brief Register Masks for USART
* @{
*/
/* ------- DLL Bit Fields                           ------ */
#define USART_DLL_DLLSB_MASK                     (0xFFU)                                             /*!< USART_DLL: DLLSB Mask                   */
#define USART_DLL_DLLSB_SHIFT                    (0U)                                                /*!< USART_DLL: DLLSB Position               */
#define USART_DLL_DLLSB(x)                       (((uint32_t)(((uint32_t)(x))<<USART_DLL_DLLSB_SHIFT))&USART_DLL_DLLSB_MASK) /*!< USART_DLL                               */
/* ------- RBR Bit Fields                           ------ */
#define USART_RBR_RBR_MASK                       (0xFFU)                                             /*!< USART_RBR: RBR Mask                     */
#define USART_RBR_RBR_SHIFT                      (0U)                                                /*!< USART_RBR: RBR Position                 */
#define USART_RBR_RBR(x)                         (((uint32_t)(((uint32_t)(x))<<USART_RBR_RBR_SHIFT))&USART_RBR_RBR_MASK) /*!< USART_RBR                               */
/* ------- THR Bit Fields                           ------ */
#define USART_THR_THR_MASK                       (0xFFU)                                             /*!< USART_THR: THR Mask                     */
#define USART_THR_THR_SHIFT                      (0U)                                                /*!< USART_THR: THR Position                 */
#define USART_THR_THR(x)                         (((uint32_t)(((uint32_t)(x))<<USART_THR_THR_SHIFT))&USART_THR_THR_MASK) /*!< USART_THR                               */
/* ------- DLM Bit Fields                           ------ */
#define USART_DLM_DLMSB_MASK                     (0xFFU)                                             /*!< USART_DLM: DLMSB Mask                   */
#define USART_DLM_DLMSB_SHIFT                    (0U)                                                /*!< USART_DLM: DLMSB Position               */
#define USART_DLM_DLMSB(x)                       (((uint32_t)(((uint32_t)(x))<<USART_DLM_DLMSB_SHIFT))&USART_DLM_DLMSB_MASK) /*!< USART_DLM                               */
/* ------- IER Bit Fields                           ------ */
#define USART_IER_RBRINTEN_MASK                  (0x1U)                                              /*!< USART_IER: RBRINTEN Mask                */
#define USART_IER_RBRINTEN_SHIFT                 (0U)                                                /*!< USART_IER: RBRINTEN Position            */
#define USART_IER_RBRINTEN(x)                    (((uint32_t)(((uint32_t)(x))<<USART_IER_RBRINTEN_SHIFT))&USART_IER_RBRINTEN_MASK) /*!< USART_IER                               */
#define USART_IER_THREINTEN_MASK                 (0x2U)                                              /*!< USART_IER: THREINTEN Mask               */
#define USART_IER_THREINTEN_SHIFT                (1U)                                                /*!< USART_IER: THREINTEN Position           */
#define USART_IER_THREINTEN(x)                   (((uint32_t)(((uint32_t)(x))<<USART_IER_THREINTEN_SHIFT))&USART_IER_THREINTEN_MASK) /*!< USART_IER                               */
#define USART_IER_RLSINTEN_MASK                  (0x4U)                                              /*!< USART_IER: RLSINTEN Mask                */
#define USART_IER_RLSINTEN_SHIFT                 (2U)                                                /*!< USART_IER: RLSINTEN Position            */
#define USART_IER_RLSINTEN(x)                    (((uint32_t)(((uint32_t)(x))<<USART_IER_RLSINTEN_SHIFT))&USART_IER_RLSINTEN_MASK) /*!< USART_IER                               */
#define USART_IER_MSINTEN_MASK                   (0x8U)                                              /*!< USART_IER: MSINTEN Mask                 */
#define USART_IER_MSINTEN_SHIFT                  (3U)                                                /*!< USART_IER: MSINTEN Position             */
#define USART_IER_MSINTEN(x)                     (((uint32_t)(((uint32_t)(x))<<USART_IER_MSINTEN_SHIFT))&USART_IER_MSINTEN_MASK) /*!< USART_IER                               */
#define USART_IER_ABEOINTEN_MASK                 (0x100U)                                            /*!< USART_IER: ABEOINTEN Mask               */
#define USART_IER_ABEOINTEN_SHIFT                (8U)                                                /*!< USART_IER: ABEOINTEN Position           */
#define USART_IER_ABEOINTEN(x)                   (((uint32_t)(((uint32_t)(x))<<USART_IER_ABEOINTEN_SHIFT))&USART_IER_ABEOINTEN_MASK) /*!< USART_IER                               */
#define USART_IER_ABTOINTEN_MASK                 (0x200U)                                            /*!< USART_IER: ABTOINTEN Mask               */
#define USART_IER_ABTOINTEN_SHIFT                (9U)                                                /*!< USART_IER: ABTOINTEN Position           */
#define USART_IER_ABTOINTEN(x)                   (((uint32_t)(((uint32_t)(x))<<USART_IER_ABTOINTEN_SHIFT))&USART_IER_ABTOINTEN_MASK) /*!< USART_IER                               */
/* ------- FCR Bit Fields                           ------ */
#define USART_FCR_FIFOEN_MASK                    (0x1U)                                              /*!< USART_FCR: FIFOEN Mask                  */
#define USART_FCR_FIFOEN_SHIFT                   (0U)                                                /*!< USART_FCR: FIFOEN Position              */
#define USART_FCR_FIFOEN(x)                      (((uint32_t)(((uint32_t)(x))<<USART_FCR_FIFOEN_SHIFT))&USART_FCR_FIFOEN_MASK) /*!< USART_FCR                               */
#define USART_FCR_RXFIFORES_MASK                 (0x2U)                                              /*!< USART_FCR: RXFIFORES Mask               */
#define USART_FCR_RXFIFORES_SHIFT                (1U)                                                /*!< USART_FCR: RXFIFORES Position           */
#define USART_FCR_RXFIFORES(x)                   (((uint32_t)(((uint32_t)(x))<<USART_FCR_RXFIFORES_SHIFT))&USART_FCR_RXFIFORES_MASK) /*!< USART_FCR                               */
#define USART_FCR_TXFIFORES_MASK                 (0x4U)                                              /*!< USART_FCR: TXFIFORES Mask               */
#define USART_FCR_TXFIFORES_SHIFT                (2U)                                                /*!< USART_FCR: TXFIFORES Position           */
#define USART_FCR_TXFIFORES(x)                   (((uint32_t)(((uint32_t)(x))<<USART_FCR_TXFIFORES_SHIFT))&USART_FCR_TXFIFORES_MASK) /*!< USART_FCR                               */
#define USART_FCR_RXTL_MASK                      (0xC0U)                                             /*!< USART_FCR: RXTL Mask                    */
#define USART_FCR_RXTL_SHIFT                     (6U)                                                /*!< USART_FCR: RXTL Position                */
#define USART_FCR_RXTL(x)                        (((uint32_t)(((uint32_t)(x))<<USART_FCR_RXTL_SHIFT))&USART_FCR_RXTL_MASK) /*!< USART_FCR                               */
/* ------- IIR Bit Fields                           ------ */
#define USART_IIR_INTSTATUS_MASK                 (0x1U)                                              /*!< USART_IIR: INTSTATUS Mask               */
#define USART_IIR_INTSTATUS_SHIFT                (0U)                                                /*!< USART_IIR: INTSTATUS Position           */
#define USART_IIR_INTSTATUS(x)                   (((uint32_t)(((uint32_t)(x))<<USART_IIR_INTSTATUS_SHIFT))&USART_IIR_INTSTATUS_MASK) /*!< USART_IIR                               */
#define USART_IIR_INTID_MASK                     (0xEU)                                              /*!< USART_IIR: INTID Mask                   */
#define USART_IIR_INTID_SHIFT                    (1U)                                                /*!< USART_IIR: INTID Position               */
#define USART_IIR_INTID(x)                       (((uint32_t)(((uint32_t)(x))<<USART_IIR_INTID_SHIFT))&USART_IIR_INTID_MASK) /*!< USART_IIR                               */
#define USART_IIR_FIFOEN_MASK                    (0xC0U)                                             /*!< USART_IIR: FIFOEN Mask                  */
#define USART_IIR_FIFOEN_SHIFT                   (6U)                                                /*!< USART_IIR: FIFOEN Position              */
#define USART_IIR_FIFOEN(x)                      (((uint32_t)(((uint32_t)(x))<<USART_IIR_FIFOEN_SHIFT))&USART_IIR_FIFOEN_MASK) /*!< USART_IIR                               */
#define USART_IIR_ABEOINT_MASK                   (0x100U)                                            /*!< USART_IIR: ABEOINT Mask                 */
#define USART_IIR_ABEOINT_SHIFT                  (8U)                                                /*!< USART_IIR: ABEOINT Position             */
#define USART_IIR_ABEOINT(x)                     (((uint32_t)(((uint32_t)(x))<<USART_IIR_ABEOINT_SHIFT))&USART_IIR_ABEOINT_MASK) /*!< USART_IIR                               */
#define USART_IIR_ABTOINT_MASK                   (0x200U)                                            /*!< USART_IIR: ABTOINT Mask                 */
#define USART_IIR_ABTOINT_SHIFT                  (9U)                                                /*!< USART_IIR: ABTOINT Position             */
#define USART_IIR_ABTOINT(x)                     (((uint32_t)(((uint32_t)(x))<<USART_IIR_ABTOINT_SHIFT))&USART_IIR_ABTOINT_MASK) /*!< USART_IIR                               */
/* ------- LCR Bit Fields                           ------ */
#define USART_LCR_WLS_MASK                       (0x3U)                                              /*!< USART_LCR: WLS Mask                     */
#define USART_LCR_WLS_SHIFT                      (0U)                                                /*!< USART_LCR: WLS Position                 */
#define USART_LCR_WLS(x)                         (((uint32_t)(((uint32_t)(x))<<USART_LCR_WLS_SHIFT))&USART_LCR_WLS_MASK) /*!< USART_LCR                               */
#define USART_LCR_SBS_MASK                       (0x4U)                                              /*!< USART_LCR: SBS Mask                     */
#define USART_LCR_SBS_SHIFT                      (2U)                                                /*!< USART_LCR: SBS Position                 */
#define USART_LCR_SBS(x)                         (((uint32_t)(((uint32_t)(x))<<USART_LCR_SBS_SHIFT))&USART_LCR_SBS_MASK) /*!< USART_LCR                               */
#define USART_LCR_PE_MASK                        (0x8U)                                              /*!< USART_LCR: PE Mask                      */
#define USART_LCR_PE_SHIFT                       (3U)                                                /*!< USART_LCR: PE Position                  */
#define USART_LCR_PE(x)                          (((uint32_t)(((uint32_t)(x))<<USART_LCR_PE_SHIFT))&USART_LCR_PE_MASK) /*!< USART_LCR                               */
#define USART_LCR_PS_MASK                        (0x30U)                                             /*!< USART_LCR: PS Mask                      */
#define USART_LCR_PS_SHIFT                       (4U)                                                /*!< USART_LCR: PS Position                  */
#define USART_LCR_PS(x)                          (((uint32_t)(((uint32_t)(x))<<USART_LCR_PS_SHIFT))&USART_LCR_PS_MASK) /*!< USART_LCR                               */
#define USART_LCR_BC_MASK                        (0x40U)                                             /*!< USART_LCR: BC Mask                      */
#define USART_LCR_BC_SHIFT                       (6U)                                                /*!< USART_LCR: BC Position                  */
#define USART_LCR_BC(x)                          (((uint32_t)(((uint32_t)(x))<<USART_LCR_BC_SHIFT))&USART_LCR_BC_MASK) /*!< USART_LCR                               */
#define USART_LCR_DLAB_MASK                      (0x80U)                                             /*!< USART_LCR: DLAB Mask                    */
#define USART_LCR_DLAB_SHIFT                     (7U)                                                /*!< USART_LCR: DLAB Position                */
#define USART_LCR_DLAB(x)                        (((uint32_t)(((uint32_t)(x))<<USART_LCR_DLAB_SHIFT))&USART_LCR_DLAB_MASK) /*!< USART_LCR                               */
/* ------- MCR Bit Fields                           ------ */
#define USART_MCR_DTRCTRL_MASK                   (0x1U)                                              /*!< USART_MCR: DTRCTRL Mask                 */
#define USART_MCR_DTRCTRL_SHIFT                  (0U)                                                /*!< USART_MCR: DTRCTRL Position             */
#define USART_MCR_DTRCTRL(x)                     (((uint32_t)(((uint32_t)(x))<<USART_MCR_DTRCTRL_SHIFT))&USART_MCR_DTRCTRL_MASK) /*!< USART_MCR                               */
#define USART_MCR_RTSCTRL_MASK                   (0x2U)                                              /*!< USART_MCR: RTSCTRL Mask                 */
#define USART_MCR_RTSCTRL_SHIFT                  (1U)                                                /*!< USART_MCR: RTSCTRL Position             */
#define USART_MCR_RTSCTRL(x)                     (((uint32_t)(((uint32_t)(x))<<USART_MCR_RTSCTRL_SHIFT))&USART_MCR_RTSCTRL_MASK) /*!< USART_MCR                               */
#define USART_MCR_LMS_MASK                       (0x10U)                                             /*!< USART_MCR: LMS Mask                     */
#define USART_MCR_LMS_SHIFT                      (4U)                                                /*!< USART_MCR: LMS Position                 */
#define USART_MCR_LMS(x)                         (((uint32_t)(((uint32_t)(x))<<USART_MCR_LMS_SHIFT))&USART_MCR_LMS_MASK) /*!< USART_MCR                               */
#define USART_MCR_RTSEN_MASK                     (0x40U)                                             /*!< USART_MCR: RTSEN Mask                   */
#define USART_MCR_RTSEN_SHIFT                    (6U)                                                /*!< USART_MCR: RTSEN Position               */
#define USART_MCR_RTSEN(x)                       (((uint32_t)(((uint32_t)(x))<<USART_MCR_RTSEN_SHIFT))&USART_MCR_RTSEN_MASK) /*!< USART_MCR                               */
#define USART_MCR_CTSEN_MASK                     (0x80U)                                             /*!< USART_MCR: CTSEN Mask                   */
#define USART_MCR_CTSEN_SHIFT                    (7U)                                                /*!< USART_MCR: CTSEN Position               */
#define USART_MCR_CTSEN(x)                       (((uint32_t)(((uint32_t)(x))<<USART_MCR_CTSEN_SHIFT))&USART_MCR_CTSEN_MASK) /*!< USART_MCR                               */
/* ------- LSR Bit Fields                           ------ */
#define USART_LSR_RDR_MASK                       (0x1U)                                              /*!< USART_LSR: RDR Mask                     */
#define USART_LSR_RDR_SHIFT                      (0U)                                                /*!< USART_LSR: RDR Position                 */
#define USART_LSR_RDR(x)                         (((uint32_t)(((uint32_t)(x))<<USART_LSR_RDR_SHIFT))&USART_LSR_RDR_MASK) /*!< USART_LSR                               */
#define USART_LSR_OE_MASK                        (0x2U)                                              /*!< USART_LSR: OE Mask                      */
#define USART_LSR_OE_SHIFT                       (1U)                                                /*!< USART_LSR: OE Position                  */
#define USART_LSR_OE(x)                          (((uint32_t)(((uint32_t)(x))<<USART_LSR_OE_SHIFT))&USART_LSR_OE_MASK) /*!< USART_LSR                               */
#define USART_LSR_PE_MASK                        (0x4U)                                              /*!< USART_LSR: PE Mask                      */
#define USART_LSR_PE_SHIFT                       (2U)                                                /*!< USART_LSR: PE Position                  */
#define USART_LSR_PE(x)                          (((uint32_t)(((uint32_t)(x))<<USART_LSR_PE_SHIFT))&USART_LSR_PE_MASK) /*!< USART_LSR                               */
#define USART_LSR_FE_MASK                        (0x8U)                                              /*!< USART_LSR: FE Mask                      */
#define USART_LSR_FE_SHIFT                       (3U)                                                /*!< USART_LSR: FE Position                  */
#define USART_LSR_FE(x)                          (((uint32_t)(((uint32_t)(x))<<USART_LSR_FE_SHIFT))&USART_LSR_FE_MASK) /*!< USART_LSR                               */
#define USART_LSR_BI_MASK                        (0x10U)                                             /*!< USART_LSR: BI Mask                      */
#define USART_LSR_BI_SHIFT                       (4U)                                                /*!< USART_LSR: BI Position                  */
#define USART_LSR_BI(x)                          (((uint32_t)(((uint32_t)(x))<<USART_LSR_BI_SHIFT))&USART_LSR_BI_MASK) /*!< USART_LSR                               */
#define USART_LSR_THRE_MASK                      (0x20U)                                             /*!< USART_LSR: THRE Mask                    */
#define USART_LSR_THRE_SHIFT                     (5U)                                                /*!< USART_LSR: THRE Position                */
#define USART_LSR_THRE(x)                        (((uint32_t)(((uint32_t)(x))<<USART_LSR_THRE_SHIFT))&USART_LSR_THRE_MASK) /*!< USART_LSR                               */
#define USART_LSR_TEMT_MASK                      (0x40U)                                             /*!< USART_LSR: TEMT Mask                    */
#define USART_LSR_TEMT_SHIFT                     (6U)                                                /*!< USART_LSR: TEMT Position                */
#define USART_LSR_TEMT(x)                        (((uint32_t)(((uint32_t)(x))<<USART_LSR_TEMT_SHIFT))&USART_LSR_TEMT_MASK) /*!< USART_LSR                               */
#define USART_LSR_RXFE_MASK                      (0x80U)                                             /*!< USART_LSR: RXFE Mask                    */
#define USART_LSR_RXFE_SHIFT                     (7U)                                                /*!< USART_LSR: RXFE Position                */
#define USART_LSR_RXFE(x)                        (((uint32_t)(((uint32_t)(x))<<USART_LSR_RXFE_SHIFT))&USART_LSR_RXFE_MASK) /*!< USART_LSR                               */
#define USART_LSR_TXERR_MASK                     (0x100U)                                            /*!< USART_LSR: TXERR Mask                   */
#define USART_LSR_TXERR_SHIFT                    (8U)                                                /*!< USART_LSR: TXERR Position               */
#define USART_LSR_TXERR(x)                       (((uint32_t)(((uint32_t)(x))<<USART_LSR_TXERR_SHIFT))&USART_LSR_TXERR_MASK) /*!< USART_LSR                               */
/* ------- MSR Bit Fields                           ------ */
#define USART_MSR_DCTS_MASK                      (0x1U)                                              /*!< USART_MSR: DCTS Mask                    */
#define USART_MSR_DCTS_SHIFT                     (0U)                                                /*!< USART_MSR: DCTS Position                */
#define USART_MSR_DCTS(x)                        (((uint32_t)(((uint32_t)(x))<<USART_MSR_DCTS_SHIFT))&USART_MSR_DCTS_MASK) /*!< USART_MSR                               */
#define USART_MSR_DDSR_MASK                      (0x2U)                                              /*!< USART_MSR: DDSR Mask                    */
#define USART_MSR_DDSR_SHIFT                     (1U)                                                /*!< USART_MSR: DDSR Position                */
#define USART_MSR_DDSR(x)                        (((uint32_t)(((uint32_t)(x))<<USART_MSR_DDSR_SHIFT))&USART_MSR_DDSR_MASK) /*!< USART_MSR                               */
#define USART_MSR_TERI_MASK                      (0x4U)                                              /*!< USART_MSR: TERI Mask                    */
#define USART_MSR_TERI_SHIFT                     (2U)                                                /*!< USART_MSR: TERI Position                */
#define USART_MSR_TERI(x)                        (((uint32_t)(((uint32_t)(x))<<USART_MSR_TERI_SHIFT))&USART_MSR_TERI_MASK) /*!< USART_MSR                               */
#define USART_MSR_DDCD_MASK                      (0x8U)                                              /*!< USART_MSR: DDCD Mask                    */
#define USART_MSR_DDCD_SHIFT                     (3U)                                                /*!< USART_MSR: DDCD Position                */
#define USART_MSR_DDCD(x)                        (((uint32_t)(((uint32_t)(x))<<USART_MSR_DDCD_SHIFT))&USART_MSR_DDCD_MASK) /*!< USART_MSR                               */
#define USART_MSR_CTS_MASK                       (0x10U)                                             /*!< USART_MSR: CTS Mask                     */
#define USART_MSR_CTS_SHIFT                      (4U)                                                /*!< USART_MSR: CTS Position                 */
#define USART_MSR_CTS(x)                         (((uint32_t)(((uint32_t)(x))<<USART_MSR_CTS_SHIFT))&USART_MSR_CTS_MASK) /*!< USART_MSR                               */
#define USART_MSR_DSR_MASK                       (0x20U)                                             /*!< USART_MSR: DSR Mask                     */
#define USART_MSR_DSR_SHIFT                      (5U)                                                /*!< USART_MSR: DSR Position                 */
#define USART_MSR_DSR(x)                         (((uint32_t)(((uint32_t)(x))<<USART_MSR_DSR_SHIFT))&USART_MSR_DSR_MASK) /*!< USART_MSR                               */
#define USART_MSR_RI_MASK                        (0x40U)                                             /*!< USART_MSR: RI Mask                      */
#define USART_MSR_RI_SHIFT                       (6U)                                                /*!< USART_MSR: RI Position                  */
#define USART_MSR_RI(x)                          (((uint32_t)(((uint32_t)(x))<<USART_MSR_RI_SHIFT))&USART_MSR_RI_MASK) /*!< USART_MSR                               */
#define USART_MSR_DCD_MASK                       (0x80U)                                             /*!< USART_MSR: DCD Mask                     */
#define USART_MSR_DCD_SHIFT                      (7U)                                                /*!< USART_MSR: DCD Position                 */
#define USART_MSR_DCD(x)                         (((uint32_t)(((uint32_t)(x))<<USART_MSR_DCD_SHIFT))&USART_MSR_DCD_MASK) /*!< USART_MSR                               */
/* ------- SCR Bit Fields                           ------ */
#define USART_SCR_PAD_MASK                       (0xFFU)                                             /*!< USART_SCR: PAD Mask                     */
#define USART_SCR_PAD_SHIFT                      (0U)                                                /*!< USART_SCR: PAD Position                 */
#define USART_SCR_PAD(x)                         (((uint32_t)(((uint32_t)(x))<<USART_SCR_PAD_SHIFT))&USART_SCR_PAD_MASK) /*!< USART_SCR                               */
/* ------- ACR Bit Fields                           ------ */
#define USART_ACR_START_MASK                     (0x1U)                                              /*!< USART_ACR: START Mask                   */
#define USART_ACR_START_SHIFT                    (0U)                                                /*!< USART_ACR: START Position               */
#define USART_ACR_START(x)                       (((uint32_t)(((uint32_t)(x))<<USART_ACR_START_SHIFT))&USART_ACR_START_MASK) /*!< USART_ACR                               */
#define USART_ACR_MODE_MASK                      (0x2U)                                              /*!< USART_ACR: MODE Mask                    */
#define USART_ACR_MODE_SHIFT                     (1U)                                                /*!< USART_ACR: MODE Position                */
#define USART_ACR_MODE(x)                        (((uint32_t)(((uint32_t)(x))<<USART_ACR_MODE_SHIFT))&USART_ACR_MODE_MASK) /*!< USART_ACR                               */
#define USART_ACR_AUTORESTART_MASK               (0x4U)                                              /*!< USART_ACR: AUTORESTART Mask             */
#define USART_ACR_AUTORESTART_SHIFT              (2U)                                                /*!< USART_ACR: AUTORESTART Position         */
#define USART_ACR_AUTORESTART(x)                 (((uint32_t)(((uint32_t)(x))<<USART_ACR_AUTORESTART_SHIFT))&USART_ACR_AUTORESTART_MASK) /*!< USART_ACR                               */
#define USART_ACR_ABEOINTCLR_MASK                (0x100U)                                            /*!< USART_ACR: ABEOINTCLR Mask              */
#define USART_ACR_ABEOINTCLR_SHIFT               (8U)                                                /*!< USART_ACR: ABEOINTCLR Position          */
#define USART_ACR_ABEOINTCLR(x)                  (((uint32_t)(((uint32_t)(x))<<USART_ACR_ABEOINTCLR_SHIFT))&USART_ACR_ABEOINTCLR_MASK) /*!< USART_ACR                               */
#define USART_ACR_ABTOINTCLR_MASK                (0x200U)                                            /*!< USART_ACR: ABTOINTCLR Mask              */
#define USART_ACR_ABTOINTCLR_SHIFT               (9U)                                                /*!< USART_ACR: ABTOINTCLR Position          */
#define USART_ACR_ABTOINTCLR(x)                  (((uint32_t)(((uint32_t)(x))<<USART_ACR_ABTOINTCLR_SHIFT))&USART_ACR_ABTOINTCLR_MASK) /*!< USART_ACR                               */
/* ------- ICR Bit Fields                           ------ */
#define USART_ICR_IRDAEN_MASK                    (0x1U)                                              /*!< USART_ICR: IRDAEN Mask                  */
#define USART_ICR_IRDAEN_SHIFT                   (0U)                                                /*!< USART_ICR: IRDAEN Position              */
#define USART_ICR_IRDAEN(x)                      (((uint32_t)(((uint32_t)(x))<<USART_ICR_IRDAEN_SHIFT))&USART_ICR_IRDAEN_MASK) /*!< USART_ICR                               */
#define USART_ICR_IRDAINV_MASK                   (0x2U)                                              /*!< USART_ICR: IRDAINV Mask                 */
#define USART_ICR_IRDAINV_SHIFT                  (1U)                                                /*!< USART_ICR: IRDAINV Position             */
#define USART_ICR_IRDAINV(x)                     (((uint32_t)(((uint32_t)(x))<<USART_ICR_IRDAINV_SHIFT))&USART_ICR_IRDAINV_MASK) /*!< USART_ICR                               */
#define USART_ICR_FIXPULSEEN_MASK                (0x4U)                                              /*!< USART_ICR: FIXPULSEEN Mask              */
#define USART_ICR_FIXPULSEEN_SHIFT               (2U)                                                /*!< USART_ICR: FIXPULSEEN Position          */
#define USART_ICR_FIXPULSEEN(x)                  (((uint32_t)(((uint32_t)(x))<<USART_ICR_FIXPULSEEN_SHIFT))&USART_ICR_FIXPULSEEN_MASK) /*!< USART_ICR                               */
#define USART_ICR_PULSEDIV_MASK                  (0x38U)                                             /*!< USART_ICR: PULSEDIV Mask                */
#define USART_ICR_PULSEDIV_SHIFT                 (3U)                                                /*!< USART_ICR: PULSEDIV Position            */
#define USART_ICR_PULSEDIV(x)                    (((uint32_t)(((uint32_t)(x))<<USART_ICR_PULSEDIV_SHIFT))&USART_ICR_PULSEDIV_MASK) /*!< USART_ICR                               */
/* ------- FDR Bit Fields                           ------ */
#define USART_FDR_DIVADDVAL_MASK                 (0xFU)                                              /*!< USART_FDR: DIVADDVAL Mask               */
#define USART_FDR_DIVADDVAL_SHIFT                (0U)                                                /*!< USART_FDR: DIVADDVAL Position           */
#define USART_FDR_DIVADDVAL(x)                   (((uint32_t)(((uint32_t)(x))<<USART_FDR_DIVADDVAL_SHIFT))&USART_FDR_DIVADDVAL_MASK) /*!< USART_FDR                               */
#define USART_FDR_MULVAL_MASK                    (0xF0U)                                             /*!< USART_FDR: MULVAL Mask                  */
#define USART_FDR_MULVAL_SHIFT                   (4U)                                                /*!< USART_FDR: MULVAL Position              */
#define USART_FDR_MULVAL(x)                      (((uint32_t)(((uint32_t)(x))<<USART_FDR_MULVAL_SHIFT))&USART_FDR_MULVAL_MASK) /*!< USART_FDR                               */
/* ------- OSR Bit Fields                           ------ */
#define USART_OSR_OSFRAC_MASK                    (0xEU)                                              /*!< USART_OSR: OSFRAC Mask                  */
#define USART_OSR_OSFRAC_SHIFT                   (1U)                                                /*!< USART_OSR: OSFRAC Position              */
#define USART_OSR_OSFRAC(x)                      (((uint32_t)(((uint32_t)(x))<<USART_OSR_OSFRAC_SHIFT))&USART_OSR_OSFRAC_MASK) /*!< USART_OSR                               */
#define USART_OSR_OSINT_MASK                     (0xF0U)                                             /*!< USART_OSR: OSINT Mask                   */
#define USART_OSR_OSINT_SHIFT                    (4U)                                                /*!< USART_OSR: OSINT Position               */
#define USART_OSR_OSINT(x)                       (((uint32_t)(((uint32_t)(x))<<USART_OSR_OSINT_SHIFT))&USART_OSR_OSINT_MASK) /*!< USART_OSR                               */
#define USART_OSR_FDINT_MASK                     (0x7F00U)                                           /*!< USART_OSR: FDINT Mask                   */
#define USART_OSR_FDINT_SHIFT                    (8U)                                                /*!< USART_OSR: FDINT Position               */
#define USART_OSR_FDINT(x)                       (((uint32_t)(((uint32_t)(x))<<USART_OSR_FDINT_SHIFT))&USART_OSR_FDINT_MASK) /*!< USART_OSR                               */
/* ------- TER Bit Fields                           ------ */
#define USART_TER_TXEN_MASK                      (0x80U)                                             /*!< USART_TER: TXEN Mask                    */
#define USART_TER_TXEN_SHIFT                     (7U)                                                /*!< USART_TER: TXEN Position                */
#define USART_TER_TXEN(x)                        (((uint32_t)(((uint32_t)(x))<<USART_TER_TXEN_SHIFT))&USART_TER_TXEN_MASK) /*!< USART_TER                               */
/* ------- HDEN Bit Fields                          ------ */
#define USART_HDEN_HDEN_MASK                     (0x1U)                                              /*!< USART_HDEN: HDEN Mask                   */
#define USART_HDEN_HDEN_SHIFT                    (0U)                                                /*!< USART_HDEN: HDEN Position               */
#define USART_HDEN_HDEN(x)                       (((uint32_t)(((uint32_t)(x))<<USART_HDEN_HDEN_SHIFT))&USART_HDEN_HDEN_MASK) /*!< USART_HDEN                              */
/* ------- SCICTRL Bit Fields                       ------ */
#define USART_SCICTRL_SCIEN_MASK                 (0x1U)                                              /*!< USART_SCICTRL: SCIEN Mask               */
#define USART_SCICTRL_SCIEN_SHIFT                (0U)                                                /*!< USART_SCICTRL: SCIEN Position           */
#define USART_SCICTRL_SCIEN(x)                   (((uint32_t)(((uint32_t)(x))<<USART_SCICTRL_SCIEN_SHIFT))&USART_SCICTRL_SCIEN_MASK) /*!< USART_SCICTRL                           */
#define USART_SCICTRL_NACKDIS_MASK               (0x2U)                                              /*!< USART_SCICTRL: NACKDIS Mask             */
#define USART_SCICTRL_NACKDIS_SHIFT              (1U)                                                /*!< USART_SCICTRL: NACKDIS Position         */
#define USART_SCICTRL_NACKDIS(x)                 (((uint32_t)(((uint32_t)(x))<<USART_SCICTRL_NACKDIS_SHIFT))&USART_SCICTRL_NACKDIS_MASK) /*!< USART_SCICTRL                           */
#define USART_SCICTRL_PROTSEL_MASK               (0x4U)                                              /*!< USART_SCICTRL: PROTSEL Mask             */
#define USART_SCICTRL_PROTSEL_SHIFT              (2U)                                                /*!< USART_SCICTRL: PROTSEL Position         */
#define USART_SCICTRL_PROTSEL(x)                 (((uint32_t)(((uint32_t)(x))<<USART_SCICTRL_PROTSEL_SHIFT))&USART_SCICTRL_PROTSEL_MASK) /*!< USART_SCICTRL                           */
#define USART_SCICTRL_TXRETRY_MASK               (0xE0U)                                             /*!< USART_SCICTRL: TXRETRY Mask             */
#define USART_SCICTRL_TXRETRY_SHIFT              (5U)                                                /*!< USART_SCICTRL: TXRETRY Position         */
#define USART_SCICTRL_TXRETRY(x)                 (((uint32_t)(((uint32_t)(x))<<USART_SCICTRL_TXRETRY_SHIFT))&USART_SCICTRL_TXRETRY_MASK) /*!< USART_SCICTRL                           */
#define USART_SCICTRL_XTRAGUARD_MASK             (0xFF00U)                                           /*!< USART_SCICTRL: XTRAGUARD Mask           */
#define USART_SCICTRL_XTRAGUARD_SHIFT            (8U)                                                /*!< USART_SCICTRL: XTRAGUARD Position       */
#define USART_SCICTRL_XTRAGUARD(x)               (((uint32_t)(((uint32_t)(x))<<USART_SCICTRL_XTRAGUARD_SHIFT))&USART_SCICTRL_XTRAGUARD_MASK) /*!< USART_SCICTRL                           */
/* ------- RS485CTRL Bit Fields                     ------ */
#define USART_RS485CTRL_NMMEN_MASK               (0x1U)                                              /*!< USART_RS485CTRL: NMMEN Mask             */
#define USART_RS485CTRL_NMMEN_SHIFT              (0U)                                                /*!< USART_RS485CTRL: NMMEN Position         */
#define USART_RS485CTRL_NMMEN(x)                 (((uint32_t)(((uint32_t)(x))<<USART_RS485CTRL_NMMEN_SHIFT))&USART_RS485CTRL_NMMEN_MASK) /*!< USART_RS485CTRL                         */
#define USART_RS485CTRL_RXDIS_MASK               (0x2U)                                              /*!< USART_RS485CTRL: RXDIS Mask             */
#define USART_RS485CTRL_RXDIS_SHIFT              (1U)                                                /*!< USART_RS485CTRL: RXDIS Position         */
#define USART_RS485CTRL_RXDIS(x)                 (((uint32_t)(((uint32_t)(x))<<USART_RS485CTRL_RXDIS_SHIFT))&USART_RS485CTRL_RXDIS_MASK) /*!< USART_RS485CTRL                         */
#define USART_RS485CTRL_AADEN_MASK               (0x4U)                                              /*!< USART_RS485CTRL: AADEN Mask             */
#define USART_RS485CTRL_AADEN_SHIFT              (2U)                                                /*!< USART_RS485CTRL: AADEN Position         */
#define USART_RS485CTRL_AADEN(x)                 (((uint32_t)(((uint32_t)(x))<<USART_RS485CTRL_AADEN_SHIFT))&USART_RS485CTRL_AADEN_MASK) /*!< USART_RS485CTRL                         */
#define USART_RS485CTRL_SEL_MASK                 (0x8U)                                              /*!< USART_RS485CTRL: SEL Mask               */
#define USART_RS485CTRL_SEL_SHIFT                (3U)                                                /*!< USART_RS485CTRL: SEL Position           */
#define USART_RS485CTRL_SEL(x)                   (((uint32_t)(((uint32_t)(x))<<USART_RS485CTRL_SEL_SHIFT))&USART_RS485CTRL_SEL_MASK) /*!< USART_RS485CTRL                         */
#define USART_RS485CTRL_DCTRL_MASK               (0x10U)                                             /*!< USART_RS485CTRL: DCTRL Mask             */
#define USART_RS485CTRL_DCTRL_SHIFT              (4U)                                                /*!< USART_RS485CTRL: DCTRL Position         */
#define USART_RS485CTRL_DCTRL(x)                 (((uint32_t)(((uint32_t)(x))<<USART_RS485CTRL_DCTRL_SHIFT))&USART_RS485CTRL_DCTRL_MASK) /*!< USART_RS485CTRL                         */
#define USART_RS485CTRL_OINV_MASK                (0x20U)                                             /*!< USART_RS485CTRL: OINV Mask              */
#define USART_RS485CTRL_OINV_SHIFT               (5U)                                                /*!< USART_RS485CTRL: OINV Position          */
#define USART_RS485CTRL_OINV(x)                  (((uint32_t)(((uint32_t)(x))<<USART_RS485CTRL_OINV_SHIFT))&USART_RS485CTRL_OINV_MASK) /*!< USART_RS485CTRL                         */
/* ------- RS485ADRMATCH Bit Fields                 ------ */
#define USART_RS485ADRMATCH_ADRMATCH_MASK        (0xFFU)                                             /*!< USART_RS485ADRMATCH: ADRMATCH Mask      */
#define USART_RS485ADRMATCH_ADRMATCH_SHIFT       (0U)                                                /*!< USART_RS485ADRMATCH: ADRMATCH Position  */
#define USART_RS485ADRMATCH_ADRMATCH(x)          (((uint32_t)(((uint32_t)(x))<<USART_RS485ADRMATCH_ADRMATCH_SHIFT))&USART_RS485ADRMATCH_ADRMATCH_MASK) /*!< USART_RS485ADRMATCH                     */
/* ------- RS485DLY Bit Fields                      ------ */
#define USART_RS485DLY_DLY_MASK                  (0xFFU)                                             /*!< USART_RS485DLY: DLY Mask                */
#define USART_RS485DLY_DLY_SHIFT                 (0U)                                                /*!< USART_RS485DLY: DLY Position            */
#define USART_RS485DLY_DLY(x)                    (((uint32_t)(((uint32_t)(x))<<USART_RS485DLY_DLY_SHIFT))&USART_RS485DLY_DLY_MASK) /*!< USART_RS485DLY                          */
/* ------- SYNCCTRL Bit Fields                      ------ */
#define USART_SYNCCTRL_SYNC_MASK                 (0x1U)                                              /*!< USART_SYNCCTRL: SYNC Mask               */
#define USART_SYNCCTRL_SYNC_SHIFT                (0U)                                                /*!< USART_SYNCCTRL: SYNC Position           */
#define USART_SYNCCTRL_SYNC(x)                   (((uint32_t)(((uint32_t)(x))<<USART_SYNCCTRL_SYNC_SHIFT))&USART_SYNCCTRL_SYNC_MASK) /*!< USART_SYNCCTRL                          */
#define USART_SYNCCTRL_CSRC_MASK                 (0x2U)                                              /*!< USART_SYNCCTRL: CSRC Mask               */
#define USART_SYNCCTRL_CSRC_SHIFT                (1U)                                                /*!< USART_SYNCCTRL: CSRC Position           */
#define USART_SYNCCTRL_CSRC(x)                   (((uint32_t)(((uint32_t)(x))<<USART_SYNCCTRL_CSRC_SHIFT))&USART_SYNCCTRL_CSRC_MASK) /*!< USART_SYNCCTRL                          */
#define USART_SYNCCTRL_FES_MASK                  (0x4U)                                              /*!< USART_SYNCCTRL: FES Mask                */
#define USART_SYNCCTRL_FES_SHIFT                 (2U)                                                /*!< USART_SYNCCTRL: FES Position            */
#define USART_SYNCCTRL_FES(x)                    (((uint32_t)(((uint32_t)(x))<<USART_SYNCCTRL_FES_SHIFT))&USART_SYNCCTRL_FES_MASK) /*!< USART_SYNCCTRL                          */
#define USART_SYNCCTRL_TSBYPASS_MASK             (0x8U)                                              /*!< USART_SYNCCTRL: TSBYPASS Mask           */
#define USART_SYNCCTRL_TSBYPASS_SHIFT            (3U)                                                /*!< USART_SYNCCTRL: TSBYPASS Position       */
#define USART_SYNCCTRL_TSBYPASS(x)               (((uint32_t)(((uint32_t)(x))<<USART_SYNCCTRL_TSBYPASS_SHIFT))&USART_SYNCCTRL_TSBYPASS_MASK) /*!< USART_SYNCCTRL                          */
#define USART_SYNCCTRL_CSCEN_MASK                (0x10U)                                             /*!< USART_SYNCCTRL: CSCEN Mask              */
#define USART_SYNCCTRL_CSCEN_SHIFT               (4U)                                                /*!< USART_SYNCCTRL: CSCEN Position          */
#define USART_SYNCCTRL_CSCEN(x)                  (((uint32_t)(((uint32_t)(x))<<USART_SYNCCTRL_CSCEN_SHIFT))&USART_SYNCCTRL_CSCEN_MASK) /*!< USART_SYNCCTRL                          */
#define USART_SYNCCTRL_SSDIS_MASK                (0x20U)                                             /*!< USART_SYNCCTRL: SSDIS Mask              */
#define USART_SYNCCTRL_SSDIS_SHIFT               (5U)                                                /*!< USART_SYNCCTRL: SSDIS Position          */
#define USART_SYNCCTRL_SSDIS(x)                  (((uint32_t)(((uint32_t)(x))<<USART_SYNCCTRL_SSDIS_SHIFT))&USART_SYNCCTRL_SSDIS_MASK) /*!< USART_SYNCCTRL                          */
#define USART_SYNCCTRL_CCCLR_MASK                (0x40U)                                             /*!< USART_SYNCCTRL: CCCLR Mask              */
#define USART_SYNCCTRL_CCCLR_SHIFT               (6U)                                                /*!< USART_SYNCCTRL: CCCLR Position          */
#define USART_SYNCCTRL_CCCLR(x)                  (((uint32_t)(((uint32_t)(x))<<USART_SYNCCTRL_CCCLR_SHIFT))&USART_SYNCCTRL_CCCLR_MASK) /*!< USART_SYNCCTRL                          */
/**
 * @} */ /* End group USART_Register_Masks_GROUP 
 */

/* USART - Peripheral instance base addresses */
#define USART_BasePtr                  0x40008000UL //!< Peripheral base address
#define USART                          ((USART_Type *) USART_BasePtr) //!< Freescale base pointer
#define USART_BASE_PTR                 (USART) //!< Freescale style base pointer
/**
 * @} */ /* End group USART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USB_Peripheral_access_layer_GROUP USB Peripheral Access Layer
* @brief C Struct for USB
* @{
*/

/* ================================================================================ */
/* ================           USB (file:USB_LPC11Uxx)              ================ */
/* ================================================================================ */

/**
 * @brief USB2.0 device controller
 */
/**
* @addtogroup USB_structs_GROUP USB struct
* @brief Struct for USB
* @{
*/
typedef struct {                                /*       USB Structure                                                */
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
        uint8_t   RESERVED_0[4];               
   __I  uint32_t  EPTOGGLE;                     /**< 0034: USB Endpoint toggle register                                 */
} USB_Type;

/**
 * @} */ /* End group USB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'USB' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup USB_Register_Masks_GROUP USB Register Masks
* @brief Register Masks for USB
* @{
*/
/* ------- DEVCMDSTAT Bit Fields                    ------ */
#define USB_DEVCMDSTAT_DEV_ADDR_MASK             (0x7FU)                                             /*!< USB_DEVCMDSTAT: DEV_ADDR Mask           */
#define USB_DEVCMDSTAT_DEV_ADDR_SHIFT            (0U)                                                /*!< USB_DEVCMDSTAT: DEV_ADDR Position       */
#define USB_DEVCMDSTAT_DEV_ADDR(x)               (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_DEV_ADDR_SHIFT))&USB_DEVCMDSTAT_DEV_ADDR_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_DEV_EN_MASK               (0x80U)                                             /*!< USB_DEVCMDSTAT: DEV_EN Mask             */
#define USB_DEVCMDSTAT_DEV_EN_SHIFT              (7U)                                                /*!< USB_DEVCMDSTAT: DEV_EN Position         */
#define USB_DEVCMDSTAT_DEV_EN(x)                 (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_DEV_EN_SHIFT))&USB_DEVCMDSTAT_DEV_EN_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_SETUP_MASK                (0x100U)                                            /*!< USB_DEVCMDSTAT: SETUP Mask              */
#define USB_DEVCMDSTAT_SETUP_SHIFT               (8U)                                                /*!< USB_DEVCMDSTAT: SETUP Position          */
#define USB_DEVCMDSTAT_SETUP(x)                  (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_SETUP_SHIFT))&USB_DEVCMDSTAT_SETUP_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_PLL_ON_MASK               (0x200U)                                            /*!< USB_DEVCMDSTAT: PLL_ON Mask             */
#define USB_DEVCMDSTAT_PLL_ON_SHIFT              (9U)                                                /*!< USB_DEVCMDSTAT: PLL_ON Position         */
#define USB_DEVCMDSTAT_PLL_ON(x)                 (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_PLL_ON_SHIFT))&USB_DEVCMDSTAT_PLL_ON_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_LPM_SUP_MASK              (0x800U)                                            /*!< USB_DEVCMDSTAT: LPM_SUP Mask            */
#define USB_DEVCMDSTAT_LPM_SUP_SHIFT             (11U)                                               /*!< USB_DEVCMDSTAT: LPM_SUP Position        */
#define USB_DEVCMDSTAT_LPM_SUP(x)                (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_LPM_SUP_SHIFT))&USB_DEVCMDSTAT_LPM_SUP_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_INTONNAK_AO_MASK          (0x1000U)                                           /*!< USB_DEVCMDSTAT: INTONNAK_AO Mask        */
#define USB_DEVCMDSTAT_INTONNAK_AO_SHIFT         (12U)                                               /*!< USB_DEVCMDSTAT: INTONNAK_AO Position    */
#define USB_DEVCMDSTAT_INTONNAK_AO(x)            (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_INTONNAK_AO_SHIFT))&USB_DEVCMDSTAT_INTONNAK_AO_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_INTONNAK_AI_MASK          (0x2000U)                                           /*!< USB_DEVCMDSTAT: INTONNAK_AI Mask        */
#define USB_DEVCMDSTAT_INTONNAK_AI_SHIFT         (13U)                                               /*!< USB_DEVCMDSTAT: INTONNAK_AI Position    */
#define USB_DEVCMDSTAT_INTONNAK_AI(x)            (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_INTONNAK_AI_SHIFT))&USB_DEVCMDSTAT_INTONNAK_AI_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_INTONNAK_CO_MASK          (0x4000U)                                           /*!< USB_DEVCMDSTAT: INTONNAK_CO Mask        */
#define USB_DEVCMDSTAT_INTONNAK_CO_SHIFT         (14U)                                               /*!< USB_DEVCMDSTAT: INTONNAK_CO Position    */
#define USB_DEVCMDSTAT_INTONNAK_CO(x)            (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_INTONNAK_CO_SHIFT))&USB_DEVCMDSTAT_INTONNAK_CO_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_INTONNAK_CI_MASK          (0x8000U)                                           /*!< USB_DEVCMDSTAT: INTONNAK_CI Mask        */
#define USB_DEVCMDSTAT_INTONNAK_CI_SHIFT         (15U)                                               /*!< USB_DEVCMDSTAT: INTONNAK_CI Position    */
#define USB_DEVCMDSTAT_INTONNAK_CI(x)            (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_INTONNAK_CI_SHIFT))&USB_DEVCMDSTAT_INTONNAK_CI_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_DCON_MASK                 (0x10000U)                                          /*!< USB_DEVCMDSTAT: DCON Mask               */
#define USB_DEVCMDSTAT_DCON_SHIFT                (16U)                                               /*!< USB_DEVCMDSTAT: DCON Position           */
#define USB_DEVCMDSTAT_DCON(x)                   (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_DCON_SHIFT))&USB_DEVCMDSTAT_DCON_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_DSUS_MASK                 (0x20000U)                                          /*!< USB_DEVCMDSTAT: DSUS Mask               */
#define USB_DEVCMDSTAT_DSUS_SHIFT                (17U)                                               /*!< USB_DEVCMDSTAT: DSUS Position           */
#define USB_DEVCMDSTAT_DSUS(x)                   (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_DSUS_SHIFT))&USB_DEVCMDSTAT_DSUS_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_LPM_SUS_MASK              (0x80000U)                                          /*!< USB_DEVCMDSTAT: LPM_SUS Mask            */
#define USB_DEVCMDSTAT_LPM_SUS_SHIFT             (19U)                                               /*!< USB_DEVCMDSTAT: LPM_SUS Position        */
#define USB_DEVCMDSTAT_LPM_SUS(x)                (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_LPM_SUS_SHIFT))&USB_DEVCMDSTAT_LPM_SUS_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_LPM_REWP_MASK             (0x100000U)                                         /*!< USB_DEVCMDSTAT: LPM_REWP Mask           */
#define USB_DEVCMDSTAT_LPM_REWP_SHIFT            (20U)                                               /*!< USB_DEVCMDSTAT: LPM_REWP Position       */
#define USB_DEVCMDSTAT_LPM_REWP(x)               (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_LPM_REWP_SHIFT))&USB_DEVCMDSTAT_LPM_REWP_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_DCON_C_MASK               (0x1000000U)                                        /*!< USB_DEVCMDSTAT: DCON_C Mask             */
#define USB_DEVCMDSTAT_DCON_C_SHIFT              (24U)                                               /*!< USB_DEVCMDSTAT: DCON_C Position         */
#define USB_DEVCMDSTAT_DCON_C(x)                 (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_DCON_C_SHIFT))&USB_DEVCMDSTAT_DCON_C_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_DSUS_C_MASK               (0x2000000U)                                        /*!< USB_DEVCMDSTAT: DSUS_C Mask             */
#define USB_DEVCMDSTAT_DSUS_C_SHIFT              (25U)                                               /*!< USB_DEVCMDSTAT: DSUS_C Position         */
#define USB_DEVCMDSTAT_DSUS_C(x)                 (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_DSUS_C_SHIFT))&USB_DEVCMDSTAT_DSUS_C_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_DRES_C_MASK               (0x4000000U)                                        /*!< USB_DEVCMDSTAT: DRES_C Mask             */
#define USB_DEVCMDSTAT_DRES_C_SHIFT              (26U)                                               /*!< USB_DEVCMDSTAT: DRES_C Position         */
#define USB_DEVCMDSTAT_DRES_C(x)                 (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_DRES_C_SHIFT))&USB_DEVCMDSTAT_DRES_C_MASK) /*!< USB_DEVCMDSTAT                          */
#define USB_DEVCMDSTAT_VBUSDEBOUNCED_MASK        (0x10000000U)                                       /*!< USB_DEVCMDSTAT: VBUSDEBOUNCED Mask      */
#define USB_DEVCMDSTAT_VBUSDEBOUNCED_SHIFT       (28U)                                               /*!< USB_DEVCMDSTAT: VBUSDEBOUNCED Position  */
#define USB_DEVCMDSTAT_VBUSDEBOUNCED(x)          (((uint32_t)(((uint32_t)(x))<<USB_DEVCMDSTAT_VBUSDEBOUNCED_SHIFT))&USB_DEVCMDSTAT_VBUSDEBOUNCED_MASK) /*!< USB_DEVCMDSTAT                          */
/* ------- INFO Bit Fields                          ------ */
#define USB_INFO_FRAME_NR_MASK                   (0x7FFU)                                            /*!< USB_INFO: FRAME_NR Mask                 */
#define USB_INFO_FRAME_NR_SHIFT                  (0U)                                                /*!< USB_INFO: FRAME_NR Position             */
#define USB_INFO_FRAME_NR(x)                     (((uint32_t)(((uint32_t)(x))<<USB_INFO_FRAME_NR_SHIFT))&USB_INFO_FRAME_NR_MASK) /*!< USB_INFO                                */
#define USB_INFO_ERR_CODE_MASK                   (0x7800U)                                           /*!< USB_INFO: ERR_CODE Mask                 */
#define USB_INFO_ERR_CODE_SHIFT                  (11U)                                               /*!< USB_INFO: ERR_CODE Position             */
#define USB_INFO_ERR_CODE(x)                     (((uint32_t)(((uint32_t)(x))<<USB_INFO_ERR_CODE_SHIFT))&USB_INFO_ERR_CODE_MASK) /*!< USB_INFO                                */
/* ------- EPLISTSTART Bit Fields                   ------ */
#define USB_EPLISTSTART_EP_LIST_MASK             (0xFFFFFF00U)                                       /*!< USB_EPLISTSTART: EP_LIST Mask           */
#define USB_EPLISTSTART_EP_LIST_SHIFT            (8U)                                                /*!< USB_EPLISTSTART: EP_LIST Position       */
#define USB_EPLISTSTART_EP_LIST(x)               (((uint32_t)(((uint32_t)(x))<<USB_EPLISTSTART_EP_LIST_SHIFT))&USB_EPLISTSTART_EP_LIST_MASK) /*!< USB_EPLISTSTART                         */
/* ------- DATABUFSTART Bit Fields                  ------ */
#define USB_DATABUFSTART_DA_BUF_MASK             (0xFFC00000U)                                       /*!< USB_DATABUFSTART: DA_BUF Mask           */
#define USB_DATABUFSTART_DA_BUF_SHIFT            (22U)                                               /*!< USB_DATABUFSTART: DA_BUF Position       */
#define USB_DATABUFSTART_DA_BUF(x)               (((uint32_t)(((uint32_t)(x))<<USB_DATABUFSTART_DA_BUF_SHIFT))&USB_DATABUFSTART_DA_BUF_MASK) /*!< USB_DATABUFSTART                        */
/* ------- LPM Bit Fields                           ------ */
#define USB_LPM_HIRD_HW_MASK                     (0xFU)                                              /*!< USB_LPM: HIRD_HW Mask                   */
#define USB_LPM_HIRD_HW_SHIFT                    (0U)                                                /*!< USB_LPM: HIRD_HW Position               */
#define USB_LPM_HIRD_HW(x)                       (((uint32_t)(((uint32_t)(x))<<USB_LPM_HIRD_HW_SHIFT))&USB_LPM_HIRD_HW_MASK) /*!< USB_LPM                                 */
#define USB_LPM_HIRD_SW_MASK                     (0xF0U)                                             /*!< USB_LPM: HIRD_SW Mask                   */
#define USB_LPM_HIRD_SW_SHIFT                    (4U)                                                /*!< USB_LPM: HIRD_SW Position               */
#define USB_LPM_HIRD_SW(x)                       (((uint32_t)(((uint32_t)(x))<<USB_LPM_HIRD_SW_SHIFT))&USB_LPM_HIRD_SW_MASK) /*!< USB_LPM                                 */
#define USB_LPM_DATA_PENDING_MASK                (0x100U)                                            /*!< USB_LPM: DATA_PENDING Mask              */
#define USB_LPM_DATA_PENDING_SHIFT               (8U)                                                /*!< USB_LPM: DATA_PENDING Position          */
#define USB_LPM_DATA_PENDING(x)                  (((uint32_t)(((uint32_t)(x))<<USB_LPM_DATA_PENDING_SHIFT))&USB_LPM_DATA_PENDING_MASK) /*!< USB_LPM                                 */
/* ------- EPSKIP Bit Fields                        ------ */
#define USB_EPSKIP_SKIP_MASK                     (0x3FFFFFFFU)                                       /*!< USB_EPSKIP: SKIP Mask                   */
#define USB_EPSKIP_SKIP_SHIFT                    (0U)                                                /*!< USB_EPSKIP: SKIP Position               */
#define USB_EPSKIP_SKIP(x)                       (((uint32_t)(((uint32_t)(x))<<USB_EPSKIP_SKIP_SHIFT))&USB_EPSKIP_SKIP_MASK) /*!< USB_EPSKIP                              */
/* ------- EPINUSE Bit Fields                       ------ */
#define USB_EPINUSE_BUF_MASK                     (0x3FCU)                                            /*!< USB_EPINUSE: BUF Mask                   */
#define USB_EPINUSE_BUF_SHIFT                    (2U)                                                /*!< USB_EPINUSE: BUF Position               */
#define USB_EPINUSE_BUF(x)                       (((uint32_t)(((uint32_t)(x))<<USB_EPINUSE_BUF_SHIFT))&USB_EPINUSE_BUF_MASK) /*!< USB_EPINUSE                             */
/* ------- EPBUFCFG Bit Fields                      ------ */
#define USB_EPBUFCFG_BUF_SB_MASK                 (0x3FCU)                                            /*!< USB_EPBUFCFG: BUF_SB Mask               */
#define USB_EPBUFCFG_BUF_SB_SHIFT                (2U)                                                /*!< USB_EPBUFCFG: BUF_SB Position           */
#define USB_EPBUFCFG_BUF_SB(x)                   (((uint32_t)(((uint32_t)(x))<<USB_EPBUFCFG_BUF_SB_SHIFT))&USB_EPBUFCFG_BUF_SB_MASK) /*!< USB_EPBUFCFG                            */
/* ------- INTSTAT Bit Fields                       ------ */
#define USB_INTSTAT_EP0OUT_MASK                  (0x1U)                                              /*!< USB_INTSTAT: EP0OUT Mask                */
#define USB_INTSTAT_EP0OUT_SHIFT                 (0U)                                                /*!< USB_INTSTAT: EP0OUT Position            */
#define USB_INTSTAT_EP0OUT(x)                    (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP0OUT_SHIFT))&USB_INTSTAT_EP0OUT_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP0IN_MASK                   (0x2U)                                              /*!< USB_INTSTAT: EP0IN Mask                 */
#define USB_INTSTAT_EP0IN_SHIFT                  (1U)                                                /*!< USB_INTSTAT: EP0IN Position             */
#define USB_INTSTAT_EP0IN(x)                     (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP0IN_SHIFT))&USB_INTSTAT_EP0IN_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP1OUT_MASK                  (0x4U)                                              /*!< USB_INTSTAT: EP1OUT Mask                */
#define USB_INTSTAT_EP1OUT_SHIFT                 (2U)                                                /*!< USB_INTSTAT: EP1OUT Position            */
#define USB_INTSTAT_EP1OUT(x)                    (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP1OUT_SHIFT))&USB_INTSTAT_EP1OUT_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP1IN_MASK                   (0x8U)                                              /*!< USB_INTSTAT: EP1IN Mask                 */
#define USB_INTSTAT_EP1IN_SHIFT                  (3U)                                                /*!< USB_INTSTAT: EP1IN Position             */
#define USB_INTSTAT_EP1IN(x)                     (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP1IN_SHIFT))&USB_INTSTAT_EP1IN_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP2OUT_MASK                  (0x10U)                                             /*!< USB_INTSTAT: EP2OUT Mask                */
#define USB_INTSTAT_EP2OUT_SHIFT                 (4U)                                                /*!< USB_INTSTAT: EP2OUT Position            */
#define USB_INTSTAT_EP2OUT(x)                    (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP2OUT_SHIFT))&USB_INTSTAT_EP2OUT_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP2IN_MASK                   (0x20U)                                             /*!< USB_INTSTAT: EP2IN Mask                 */
#define USB_INTSTAT_EP2IN_SHIFT                  (5U)                                                /*!< USB_INTSTAT: EP2IN Position             */
#define USB_INTSTAT_EP2IN(x)                     (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP2IN_SHIFT))&USB_INTSTAT_EP2IN_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP3OUT_MASK                  (0x40U)                                             /*!< USB_INTSTAT: EP3OUT Mask                */
#define USB_INTSTAT_EP3OUT_SHIFT                 (6U)                                                /*!< USB_INTSTAT: EP3OUT Position            */
#define USB_INTSTAT_EP3OUT(x)                    (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP3OUT_SHIFT))&USB_INTSTAT_EP3OUT_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP3IN_MASK                   (0x80U)                                             /*!< USB_INTSTAT: EP3IN Mask                 */
#define USB_INTSTAT_EP3IN_SHIFT                  (7U)                                                /*!< USB_INTSTAT: EP3IN Position             */
#define USB_INTSTAT_EP3IN(x)                     (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP3IN_SHIFT))&USB_INTSTAT_EP3IN_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP4OUT_MASK                  (0x100U)                                            /*!< USB_INTSTAT: EP4OUT Mask                */
#define USB_INTSTAT_EP4OUT_SHIFT                 (8U)                                                /*!< USB_INTSTAT: EP4OUT Position            */
#define USB_INTSTAT_EP4OUT(x)                    (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP4OUT_SHIFT))&USB_INTSTAT_EP4OUT_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_EP4IN_MASK                   (0x200U)                                            /*!< USB_INTSTAT: EP4IN Mask                 */
#define USB_INTSTAT_EP4IN_SHIFT                  (9U)                                                /*!< USB_INTSTAT: EP4IN Position             */
#define USB_INTSTAT_EP4IN(x)                     (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_EP4IN_SHIFT))&USB_INTSTAT_EP4IN_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_FRAME_INT_MASK               (0x40000000U)                                       /*!< USB_INTSTAT: FRAME_INT Mask             */
#define USB_INTSTAT_FRAME_INT_SHIFT              (30U)                                               /*!< USB_INTSTAT: FRAME_INT Position         */
#define USB_INTSTAT_FRAME_INT(x)                 (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_FRAME_INT_SHIFT))&USB_INTSTAT_FRAME_INT_MASK) /*!< USB_INTSTAT                             */
#define USB_INTSTAT_DEV_INT_MASK                 (0x80000000U)                                       /*!< USB_INTSTAT: DEV_INT Mask               */
#define USB_INTSTAT_DEV_INT_SHIFT                (31U)                                               /*!< USB_INTSTAT: DEV_INT Position           */
#define USB_INTSTAT_DEV_INT(x)                   (((uint32_t)(((uint32_t)(x))<<USB_INTSTAT_DEV_INT_SHIFT))&USB_INTSTAT_DEV_INT_MASK) /*!< USB_INTSTAT                             */
/* ------- INTEN Bit Fields                         ------ */
#define USB_INTEN_EP_INT_EN_MASK                 (0x3FFU)                                            /*!< USB_INTEN: EP_INT_EN Mask               */
#define USB_INTEN_EP_INT_EN_SHIFT                (0U)                                                /*!< USB_INTEN: EP_INT_EN Position           */
#define USB_INTEN_EP_INT_EN(x)                   (((uint32_t)(((uint32_t)(x))<<USB_INTEN_EP_INT_EN_SHIFT))&USB_INTEN_EP_INT_EN_MASK) /*!< USB_INTEN                               */
#define USB_INTEN_FRAME_INT_EN_MASK              (0x40000000U)                                       /*!< USB_INTEN: FRAME_INT_EN Mask            */
#define USB_INTEN_FRAME_INT_EN_SHIFT             (30U)                                               /*!< USB_INTEN: FRAME_INT_EN Position        */
#define USB_INTEN_FRAME_INT_EN(x)                (((uint32_t)(((uint32_t)(x))<<USB_INTEN_FRAME_INT_EN_SHIFT))&USB_INTEN_FRAME_INT_EN_MASK) /*!< USB_INTEN                               */
#define USB_INTEN_DEV_INT_EN_MASK                (0x80000000U)                                       /*!< USB_INTEN: DEV_INT_EN Mask              */
#define USB_INTEN_DEV_INT_EN_SHIFT               (31U)                                               /*!< USB_INTEN: DEV_INT_EN Position          */
#define USB_INTEN_DEV_INT_EN(x)                  (((uint32_t)(((uint32_t)(x))<<USB_INTEN_DEV_INT_EN_SHIFT))&USB_INTEN_DEV_INT_EN_MASK) /*!< USB_INTEN                               */
/* ------- INTSETSTAT Bit Fields                    ------ */
#define USB_INTSETSTAT_EP_SET_INT_MASK           (0x3FFU)                                            /*!< USB_INTSETSTAT: EP_SET_INT Mask         */
#define USB_INTSETSTAT_EP_SET_INT_SHIFT          (0U)                                                /*!< USB_INTSETSTAT: EP_SET_INT Position     */
#define USB_INTSETSTAT_EP_SET_INT(x)             (((uint32_t)(((uint32_t)(x))<<USB_INTSETSTAT_EP_SET_INT_SHIFT))&USB_INTSETSTAT_EP_SET_INT_MASK) /*!< USB_INTSETSTAT                          */
#define USB_INTSETSTAT_FRAME_SET_INT_MASK        (0x40000000U)                                       /*!< USB_INTSETSTAT: FRAME_SET_INT Mask      */
#define USB_INTSETSTAT_FRAME_SET_INT_SHIFT       (30U)                                               /*!< USB_INTSETSTAT: FRAME_SET_INT Position  */
#define USB_INTSETSTAT_FRAME_SET_INT(x)          (((uint32_t)(((uint32_t)(x))<<USB_INTSETSTAT_FRAME_SET_INT_SHIFT))&USB_INTSETSTAT_FRAME_SET_INT_MASK) /*!< USB_INTSETSTAT                          */
#define USB_INTSETSTAT_DEV_SET_INT_MASK          (0x80000000U)                                       /*!< USB_INTSETSTAT: DEV_SET_INT Mask        */
#define USB_INTSETSTAT_DEV_SET_INT_SHIFT         (31U)                                               /*!< USB_INTSETSTAT: DEV_SET_INT Position    */
#define USB_INTSETSTAT_DEV_SET_INT(x)            (((uint32_t)(((uint32_t)(x))<<USB_INTSETSTAT_DEV_SET_INT_SHIFT))&USB_INTSETSTAT_DEV_SET_INT_MASK) /*!< USB_INTSETSTAT                          */
/* ------- INTROUTING Bit Fields                    ------ */
#define USB_INTROUTING_ROUTE_INT9_0_MASK         (0x3FFU)                                            /*!< USB_INTROUTING: ROUTE_INT9_0 Mask       */
#define USB_INTROUTING_ROUTE_INT9_0_SHIFT        (0U)                                                /*!< USB_INTROUTING: ROUTE_INT9_0 Position   */
#define USB_INTROUTING_ROUTE_INT9_0(x)           (((uint32_t)(((uint32_t)(x))<<USB_INTROUTING_ROUTE_INT9_0_SHIFT))&USB_INTROUTING_ROUTE_INT9_0_MASK) /*!< USB_INTROUTING                          */
#define USB_INTROUTING_ROUTE_INT30_MASK          (0x40000000U)                                       /*!< USB_INTROUTING: ROUTE_INT30 Mask        */
#define USB_INTROUTING_ROUTE_INT30_SHIFT         (30U)                                               /*!< USB_INTROUTING: ROUTE_INT30 Position    */
#define USB_INTROUTING_ROUTE_INT30(x)            (((uint32_t)(((uint32_t)(x))<<USB_INTROUTING_ROUTE_INT30_SHIFT))&USB_INTROUTING_ROUTE_INT30_MASK) /*!< USB_INTROUTING                          */
#define USB_INTROUTING_ROUTE_INT31_MASK          (0x80000000U)                                       /*!< USB_INTROUTING: ROUTE_INT31 Mask        */
#define USB_INTROUTING_ROUTE_INT31_SHIFT         (31U)                                               /*!< USB_INTROUTING: ROUTE_INT31 Position    */
#define USB_INTROUTING_ROUTE_INT31(x)            (((uint32_t)(((uint32_t)(x))<<USB_INTROUTING_ROUTE_INT31_SHIFT))&USB_INTROUTING_ROUTE_INT31_MASK) /*!< USB_INTROUTING                          */
/* ------- EPTOGGLE Bit Fields                      ------ */
#define USB_EPTOGGLE_TOGGLE_MASK                 (0x3FFU)                                            /*!< USB_EPTOGGLE: TOGGLE Mask               */
#define USB_EPTOGGLE_TOGGLE_SHIFT                (0U)                                                /*!< USB_EPTOGGLE: TOGGLE Position           */
#define USB_EPTOGGLE_TOGGLE(x)                   (((uint32_t)(((uint32_t)(x))<<USB_EPTOGGLE_TOGGLE_SHIFT))&USB_EPTOGGLE_TOGGLE_MASK) /*!< USB_EPTOGGLE                            */
/**
 * @} */ /* End group USB_Register_Masks_GROUP 
 */

/* USB - Peripheral instance base addresses */
#define USB_BasePtr                    0x40080000UL //!< Peripheral base address
#define USB                            ((USB_Type *) USB_BasePtr) //!< Freescale base pointer
#define USB_BASE_PTR                   (USB) //!< Freescale style base pointer
/**
 * @} */ /* End group USB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WWDT_Peripheral_access_layer_GROUP WWDT Peripheral Access Layer
* @brief C Struct for WWDT
* @{
*/

/* ================================================================================ */
/* ================           WWDT (file:WWDT_LPC11Uxx)            ================ */
/* ================================================================================ */

/**
 * @brief Windowed Watchdog Timer
 */
/**
* @addtogroup WWDT_structs_GROUP WWDT struct
* @brief Struct for WWDT
* @{
*/
typedef struct {                                /*       WWDT Structure                                               */
   __IO uint32_t  MOD;                          /**< 0000: Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer */
   __IO uint32_t  TC;                           /**< 0004: Watchdog timer constant register. This 24-bit register determines the time-out value */
   __O  uint32_t  FEED;                         /**< 0008: Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC */
   __I  uint32_t  TV;                           /**< 000C: Watchdog timer value register. This 24-bit register reads out the current value of the Watchdog timer */
   __IO uint32_t  CLKSEL;                       /**< 0010: Watchdog clock select register                               */
   __IO uint32_t  WARNINT;                      /**< 0014: Watchdog Warning Interrupt compare value                     */
   __IO uint32_t  WINDOW;                       /**< 0018: Watchdog Window compare value                                */
} WWDT_Type;

/**
 * @} */ /* End group WWDT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'WWDT' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup WWDT_Register_Masks_GROUP WWDT Register Masks
* @brief Register Masks for WWDT
* @{
*/
/* ------- MOD Bit Fields                           ------ */
#define WWDT_MOD_WDEN_MASK                       (0x1U)                                              /*!< WWDT_MOD: WDEN Mask                     */
#define WWDT_MOD_WDEN_SHIFT                      (0U)                                                /*!< WWDT_MOD: WDEN Position                 */
#define WWDT_MOD_WDEN(x)                         (((uint32_t)(((uint32_t)(x))<<WWDT_MOD_WDEN_SHIFT))&WWDT_MOD_WDEN_MASK) /*!< WWDT_MOD                                */
#define WWDT_MOD_WDRESET_MASK                    (0x2U)                                              /*!< WWDT_MOD: WDRESET Mask                  */
#define WWDT_MOD_WDRESET_SHIFT                   (1U)                                                /*!< WWDT_MOD: WDRESET Position              */
#define WWDT_MOD_WDRESET(x)                      (((uint32_t)(((uint32_t)(x))<<WWDT_MOD_WDRESET_SHIFT))&WWDT_MOD_WDRESET_MASK) /*!< WWDT_MOD                                */
#define WWDT_MOD_WDTOF_MASK                      (0x4U)                                              /*!< WWDT_MOD: WDTOF Mask                    */
#define WWDT_MOD_WDTOF_SHIFT                     (2U)                                                /*!< WWDT_MOD: WDTOF Position                */
#define WWDT_MOD_WDTOF(x)                        (((uint32_t)(((uint32_t)(x))<<WWDT_MOD_WDTOF_SHIFT))&WWDT_MOD_WDTOF_MASK) /*!< WWDT_MOD                                */
#define WWDT_MOD_WDINT_MASK                      (0x8U)                                              /*!< WWDT_MOD: WDINT Mask                    */
#define WWDT_MOD_WDINT_SHIFT                     (3U)                                                /*!< WWDT_MOD: WDINT Position                */
#define WWDT_MOD_WDINT(x)                        (((uint32_t)(((uint32_t)(x))<<WWDT_MOD_WDINT_SHIFT))&WWDT_MOD_WDINT_MASK) /*!< WWDT_MOD                                */
#define WWDT_MOD_WDPROTECT_MASK                  (0x10U)                                             /*!< WWDT_MOD: WDPROTECT Mask                */
#define WWDT_MOD_WDPROTECT_SHIFT                 (4U)                                                /*!< WWDT_MOD: WDPROTECT Position            */
#define WWDT_MOD_WDPROTECT(x)                    (((uint32_t)(((uint32_t)(x))<<WWDT_MOD_WDPROTECT_SHIFT))&WWDT_MOD_WDPROTECT_MASK) /*!< WWDT_MOD                                */
#define WWDT_MOD_LOCK_MASK                       (0x20U)                                             /*!< WWDT_MOD: LOCK Mask                     */
#define WWDT_MOD_LOCK_SHIFT                      (5U)                                                /*!< WWDT_MOD: LOCK Position                 */
#define WWDT_MOD_LOCK(x)                         (((uint32_t)(((uint32_t)(x))<<WWDT_MOD_LOCK_SHIFT))&WWDT_MOD_LOCK_MASK) /*!< WWDT_MOD                                */
/* ------- TC Bit Fields                            ------ */
#define WWDT_TC_COUNT_MASK                       (0xFFFFFFU)                                         /*!< WWDT_TC: COUNT Mask                     */
#define WWDT_TC_COUNT_SHIFT                      (0U)                                                /*!< WWDT_TC: COUNT Position                 */
#define WWDT_TC_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<WWDT_TC_COUNT_SHIFT))&WWDT_TC_COUNT_MASK) /*!< WWDT_TC                                 */
/* ------- FEED Bit Fields                          ------ */
#define WWDT_FEED_FEED_MASK                      (0xFFU)                                             /*!< WWDT_FEED: FEED Mask                    */
#define WWDT_FEED_FEED_SHIFT                     (0U)                                                /*!< WWDT_FEED: FEED Position                */
#define WWDT_FEED_FEED(x)                        (((uint32_t)(((uint32_t)(x))<<WWDT_FEED_FEED_SHIFT))&WWDT_FEED_FEED_MASK) /*!< WWDT_FEED                               */
/* ------- TV Bit Fields                            ------ */
#define WWDT_TV_COUNT_MASK                       (0xFFFFFFU)                                         /*!< WWDT_TV: COUNT Mask                     */
#define WWDT_TV_COUNT_SHIFT                      (0U)                                                /*!< WWDT_TV: COUNT Position                 */
#define WWDT_TV_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<WWDT_TV_COUNT_SHIFT))&WWDT_TV_COUNT_MASK) /*!< WWDT_TV                                 */
/* ------- CLKSEL Bit Fields                        ------ */
#define WWDT_CLKSEL_CLKSEL_MASK                  (0x1U)                                              /*!< WWDT_CLKSEL: CLKSEL Mask                */
#define WWDT_CLKSEL_CLKSEL_SHIFT                 (0U)                                                /*!< WWDT_CLKSEL: CLKSEL Position            */
#define WWDT_CLKSEL_CLKSEL(x)                    (((uint32_t)(((uint32_t)(x))<<WWDT_CLKSEL_CLKSEL_SHIFT))&WWDT_CLKSEL_CLKSEL_MASK) /*!< WWDT_CLKSEL                             */
#define WWDT_CLKSEL_LOCK_MASK                    (0x80000000U)                                       /*!< WWDT_CLKSEL: LOCK Mask                  */
#define WWDT_CLKSEL_LOCK_SHIFT                   (31U)                                               /*!< WWDT_CLKSEL: LOCK Position              */
#define WWDT_CLKSEL_LOCK(x)                      (((uint32_t)(((uint32_t)(x))<<WWDT_CLKSEL_LOCK_SHIFT))&WWDT_CLKSEL_LOCK_MASK) /*!< WWDT_CLKSEL                             */
/* ------- WARNINT Bit Fields                       ------ */
#define WWDT_WARNINT_WARNINT_MASK                (0x3FFU)                                            /*!< WWDT_WARNINT: WARNINT Mask              */
#define WWDT_WARNINT_WARNINT_SHIFT               (0U)                                                /*!< WWDT_WARNINT: WARNINT Position          */
#define WWDT_WARNINT_WARNINT(x)                  (((uint32_t)(((uint32_t)(x))<<WWDT_WARNINT_WARNINT_SHIFT))&WWDT_WARNINT_WARNINT_MASK) /*!< WWDT_WARNINT                            */
/* ------- WINDOW Bit Fields                        ------ */
#define WWDT_WINDOW_WINDOW_MASK                  (0xFFFFFFU)                                         /*!< WWDT_WINDOW: WINDOW Mask                */
#define WWDT_WINDOW_WINDOW_SHIFT                 (0U)                                                /*!< WWDT_WINDOW: WINDOW Position            */
#define WWDT_WINDOW_WINDOW(x)                    (((uint32_t)(((uint32_t)(x))<<WWDT_WINDOW_WINDOW_SHIFT))&WWDT_WINDOW_WINDOW_MASK) /*!< WWDT_WINDOW                             */
/**
 * @} */ /* End group WWDT_Register_Masks_GROUP 
 */

/* WWDT - Peripheral instance base addresses */
#define WWDT_BasePtr                   0x40004000UL //!< Peripheral base address
#define WWDT                           ((WWDT_Type *) WWDT_BasePtr) //!< Freescale base pointer
#define WWDT_BASE_PTR                  (WWDT) //!< Freescale style base pointer
/**
 * @} */ /* End group WWDT_Peripheral_access_layer_GROUP 
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


#endif  /* MCU_LPC11UXX */

