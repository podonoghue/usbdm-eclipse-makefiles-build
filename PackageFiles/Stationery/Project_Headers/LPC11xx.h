/****************************************************************************************************//**
 * @file     LPC11xx.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for LPC11xx.
 *           Equivalent: 
 *
 * @version  V6
 * @date     2017/07
 *
 *******************************************************************************************************/

#ifndef MCU_LPC11XX
#define MCU_LPC11XX

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
/* ----------------------   LPC11xx VectorTable                      ---------------------- */
  PIO0_0_IRQn                   =   0,   /**<  16 /LPC11Cxx System configuration                                                   */
  PIO0_1_IRQn                   =   1,   /**<  17 /LPC11Cxx System configuration                                                   */
  PIO0_2_IRQn                   =   2,   /**<  18 /LPC11Cxx System configuration                                                   */
  PIO0_3_IRQn                   =   3,   /**<  19 /LPC11Cxx System configuration                                                   */
  PIO0_4_IRQn                   =   4,   /**<  20 /LPC11Cxx System configuration                                                   */
  PIO0_5_IRQn                   =   5,   /**<  21 /LPC11Cxx System configuration                                                   */
  PIO0_6_IRQn                   =   6,   /**<  22 /LPC11Cxx System configuration                                                   */
  PIO0_7_IRQn                   =   7,   /**<  23 /LPC11Cxx System configuration                                                   */
  PIO0_8_IRQn                   =   8,   /**<  24 /LPC11Cxx System configuration                                                   */
  PIO0_9_IRQn                   =   9,   /**<  25 /LPC11Cxx System configuration                                                   */
  PIO0_10_IRQn                  =  10,   /**<  26 /LPC11Cxx System configuration                                                   */
  PIO0_11_IRQn                  =  11,   /**<  27 /LPC11Cxx System configuration                                                   */
  PIO1_0_IRQn                   =  12,   /**<  28 /LPC11Cxx System configuration                                                   */
  C_CAN_IRQn                    =  13,   /**<  29 /LPC11Cxx C_CAN controller                                                       */
  SPI1_IRQn                     =  14,   /**<  30 SPI0                                                                             */
  I2C_IRQn                      =  15,   /**<  31 I2C-bus interface                                                                */
  CT16B0_IRQn                   =  16,   /**<  32 16-bit counter/timer                                                             */
  CT16B1_IRQn                   =  17,   /**<  33 16-bit counter/timer                                                             */
  CT32B0_IRQn                   =  18,   /**<  34 LPC1100XL series: 32-bit counter/timer CT32B0/1                                  */
  CT32B1_IRQn                   =  19,   /**<  35 LPC1100XL series: 32-bit counter/timer CT32B0/1                                  */
  SPI0_IRQn                     =  20,   /**<  36 SPI0                                                                             */
  UART_IRQn                     =  21,   /**<  37 UART                                                                             */
  ADC_IRQn                      =  24,   /**<  40 10-bit ADC                                                                       */
  WDT_IRQn                      =  25,   /**<  41 Windowed WatchDog Timer                                                          */
  BOD_IRQn                      =  26,   /**<  42 /LPC11Cxx System configuration                                                   */
  FMC_IRQn                      =  27,   /**<  43 LPC11U1x Flash programming firmware                                              */
  GPIO3_IRQn                    =  28,   /**<  44 GPIO0                                                                            */
  GPIO2_IRQn                    =  29,   /**<  45 GPIO0                                                                            */
  GPIO1_IRQn                    =  30,   /**<  46 GPIO0                                                                            */
  GPIO0_IRQn                    =  31,   /**<  47 GPIO0                                                                            */
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
extern void PIO0_0_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_1_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_2_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_3_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_4_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_5_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_6_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_7_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_8_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_9_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_10_IRQHandler(void);          /**< /LPC11Cxx System configuration                                                   */
extern void PIO0_11_IRQHandler(void);          /**< /LPC11Cxx System configuration                                                   */
extern void PIO1_0_IRQHandler(void);           /**< /LPC11Cxx System configuration                                                   */
extern void C_CAN_IRQHandler(void);            /**< /LPC11Cxx C_CAN controller                                                       */
extern void SPI1_IRQHandler(void);             /**< SPI0                                                                             */
extern void I2C_IRQHandler(void);              /**< I2C-bus interface                                                                */
extern void CT16B0_IRQHandler(void);           /**< 16-bit counter/timer                                                             */
extern void CT16B1_IRQHandler(void);           /**< 16-bit counter/timer                                                             */
extern void CT32B0_IRQHandler(void);           /**< LPC1100XL series: 32-bit counter/timer CT32B0/1                                  */
extern void CT32B1_IRQHandler(void);           /**< LPC1100XL series: 32-bit counter/timer CT32B0/1                                  */
extern void SPI0_IRQHandler(void);             /**< SPI0                                                                             */
extern void UART_IRQHandler(void);             /**< UART                                                                             */
extern void ADC_IRQHandler(void);              /**< 10-bit ADC                                                                       */
extern void WDT_IRQHandler(void);              /**< Windowed WatchDog Timer                                                          */
extern void BOD_IRQHandler(void);              /**< /LPC11Cxx System configuration                                                   */
extern void FMC_IRQHandler(void);              /**< LPC11U1x Flash programming firmware                                              */
extern void GPIO3_IRQHandler(void);            /**< GPIO0                                                                            */
extern void GPIO2_IRQHandler(void);            /**< GPIO0                                                                            */
extern void GPIO1_IRQHandler(void);            /**< GPIO0                                                                            */
extern void GPIO0_IRQHandler(void);            /**< GPIO0                                                                            */

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
#define __VTOR_PRESENT            0          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
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
/* ================           ADC (file:ADC_LPC11Cxx)              ================ */
/* ================================================================================ */

/**
 * @brief 10-bit ADC
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC Structure                                                */
   __IO uint32_t  CR;                           /**< 0000: A/D Control Register. The ADCR register must be written to select the operating mode before A/D conversion can occur */
   __IO uint32_t  GDR;                          /**< 0004: A/D Global Data Register. Contains the result of the most recent A/D conversion */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  INTEN;                        /**< 000C: A/D Interrupt Enable Register. This register contains enable bits that allow the DONE flag of each A/D channel to be included or excluded from contributing to the generation of an A/D interrupt */
   __IO uint32_t  DR[8];                        /**< 0010: A/D Channel n Data Register. This register contains the result of the most recent conversion completed on channel n */
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
#define ADC_CR_SEL_MASK                          (0xFFU)                                             /*!< ADC_CR.SEL Mask                         */
#define ADC_CR_SEL_SHIFT                         (0U)                                                /*!< ADC_CR.SEL Position                     */
#define ADC_CR_SEL(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< ADC_CR.SEL Field                        */
#define ADC_CR_CLKDIV_MASK                       (0xFF00U)                                           /*!< ADC_CR.CLKDIV Mask                      */
#define ADC_CR_CLKDIV_SHIFT                      (8U)                                                /*!< ADC_CR.CLKDIV Position                  */
#define ADC_CR_CLKDIV(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< ADC_CR.CLKDIV Field                     */
#define ADC_CR_BURST_MASK                        (0x10000U)                                          /*!< ADC_CR.BURST Mask                       */
#define ADC_CR_BURST_SHIFT                       (16U)                                               /*!< ADC_CR.BURST Position                   */
#define ADC_CR_BURST(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< ADC_CR.BURST Field                      */
#define ADC_CR_CLKS_MASK                         (0xE0000U)                                          /*!< ADC_CR.CLKS Mask                        */
#define ADC_CR_CLKS_SHIFT                        (17U)                                               /*!< ADC_CR.CLKS Position                    */
#define ADC_CR_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<17U))&0xE0000UL)      /*!< ADC_CR.CLKS Field                       */
#define ADC_CR_START_MASK                        (0x7000000U)                                        /*!< ADC_CR.START Mask                       */
#define ADC_CR_START_SHIFT                       (24U)                                               /*!< ADC_CR.START Position                   */
#define ADC_CR_START(x)                          (((uint32_t)(((uint32_t)(x))<<24U))&0x7000000UL)    /*!< ADC_CR.START Field                      */
#define ADC_CR_EDGE_MASK                         (0x8000000U)                                        /*!< ADC_CR.EDGE Mask                        */
#define ADC_CR_EDGE_SHIFT                        (27U)                                               /*!< ADC_CR.EDGE Position                    */
#define ADC_CR_EDGE(x)                           (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< ADC_CR.EDGE Field                       */
/* ------- GDR Bit Fields                           ------ */
#define ADC_GDR_V_VREF_MASK                      (0xFFC0U)                                           /*!< ADC_GDR.V_VREF Mask                     */
#define ADC_GDR_V_VREF_SHIFT                     (6U)                                                /*!< ADC_GDR.V_VREF Position                 */
#define ADC_GDR_V_VREF(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0xFFC0UL)        /*!< ADC_GDR.V_VREF Field                    */
#define ADC_GDR_CHN_MASK                         (0x7000000U)                                        /*!< ADC_GDR.CHN Mask                        */
#define ADC_GDR_CHN_SHIFT                        (24U)                                               /*!< ADC_GDR.CHN Position                    */
#define ADC_GDR_CHN(x)                           (((uint32_t)(((uint32_t)(x))<<24U))&0x7000000UL)    /*!< ADC_GDR.CHN Field                       */
#define ADC_GDR_OVERRUN_MASK                     (0x40000000U)                                       /*!< ADC_GDR.OVERRUN Mask                    */
#define ADC_GDR_OVERRUN_SHIFT                    (30U)                                               /*!< ADC_GDR.OVERRUN Position                */
#define ADC_GDR_OVERRUN(x)                       (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< ADC_GDR.OVERRUN Field                   */
#define ADC_GDR_DONE_MASK                        (0x80000000U)                                       /*!< ADC_GDR.DONE Mask                       */
#define ADC_GDR_DONE_SHIFT                       (31U)                                               /*!< ADC_GDR.DONE Position                   */
#define ADC_GDR_DONE(x)                          (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< ADC_GDR.DONE Field                      */
/* ------- INTEN Bit Fields                         ------ */
#define ADC_INTEN_ADINTENn_MASK                  (0xFFU)                                             /*!< ADC_INTEN.ADINTENn Mask                 */
#define ADC_INTEN_ADINTENn_SHIFT                 (0U)                                                /*!< ADC_INTEN.ADINTENn Position             */
#define ADC_INTEN_ADINTENn(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< ADC_INTEN.ADINTENn Field                */
#define ADC_INTEN_ADGINTEN_MASK                  (0x100U)                                            /*!< ADC_INTEN.ADGINTEN Mask                 */
#define ADC_INTEN_ADGINTEN_SHIFT                 (8U)                                                /*!< ADC_INTEN.ADGINTEN Position             */
#define ADC_INTEN_ADGINTEN(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< ADC_INTEN.ADGINTEN Field                */
/* ------- DR Bit Fields                            ------ */
#define ADC_DR_V_VREF_MASK                       (0xFFC0U)                                           /*!< ADC_DR.V_VREF Mask                      */
#define ADC_DR_V_VREF_SHIFT                      (6U)                                                /*!< ADC_DR.V_VREF Position                  */
#define ADC_DR_V_VREF(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0xFFC0UL)        /*!< ADC_DR.V_VREF Field                     */
#define ADC_DR_OVERRUN_MASK                      (0x40000000U)                                       /*!< ADC_DR.OVERRUN Mask                     */
#define ADC_DR_OVERRUN_SHIFT                     (30U)                                               /*!< ADC_DR.OVERRUN Position                 */
#define ADC_DR_OVERRUN(x)                        (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< ADC_DR.OVERRUN Field                    */
#define ADC_DR_DONE_MASK                         (0x80000000U)                                       /*!< ADC_DR.DONE Mask                        */
#define ADC_DR_DONE_SHIFT                        (31U)                                               /*!< ADC_DR.DONE Position                    */
#define ADC_DR_DONE(x)                           (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< ADC_DR.DONE Field                       */
/* ------- STAT Bit Fields                          ------ */
#define ADC_STAT_DONE_MASK                       (0xFFU)                                             /*!< ADC_STAT.DONE Mask                      */
#define ADC_STAT_DONE_SHIFT                      (0U)                                                /*!< ADC_STAT.DONE Position                  */
#define ADC_STAT_DONE(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< ADC_STAT.DONE Field                     */
#define ADC_STAT_OVERRUN_MASK                    (0xFF00U)                                           /*!< ADC_STAT.OVERRUN Mask                   */
#define ADC_STAT_OVERRUN_SHIFT                   (8U)                                                /*!< ADC_STAT.OVERRUN Position               */
#define ADC_STAT_OVERRUN(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< ADC_STAT.OVERRUN Field                  */
#define ADC_STAT_ADINT_MASK                      (0x10000U)                                          /*!< ADC_STAT.ADINT Mask                     */
#define ADC_STAT_ADINT_SHIFT                     (16U)                                               /*!< ADC_STAT.ADINT Position                 */
#define ADC_STAT_ADINT(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< ADC_STAT.ADINT Field                    */
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
* @addtogroup CT16B_Peripheral_access_layer_GROUP CT16B Peripheral Access Layer
* @brief C Struct for CT16B
* @{
*/

/* ================================================================================ */
/* ================           CT16B0 (file:CT16B0_LPC11xx)         ================ */
/* ================================================================================ */

/**
 * @brief 16-bit counter/timer
 */
/**
* @addtogroup CT16B_structs_GROUP CT16B struct
* @brief Struct for CT16B
* @{
*/
typedef struct {                                /*       CT16B0 Structure                                             */
   __IO uint32_t  IR;                           /**< 0000: Interrupt Register (IR). The IR can be written to clear interrupts. The IR can be read to identify which of five possible interrupt sources are pending */
   __IO uint32_t  TCR;                          /**< 0004: Timer Control Register (TCR). The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  TC;                           /**< 0008: Timer Counter (TC). The 16-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  PR;                           /**< 000C: Prescale Register (PR). When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  PC;                           /**< 0010: Prescale Counter (PC). The 16-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  MCR;                          /**< 0014: Match Control Register (MCR). The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  MR[4];                        /**< 0018: Match Register. MR can be enabled through the MCR to reset the TC, stop both the TC and PC, and/or generate an interrupt every time MR matches the TC */
   __IO uint32_t  CCR;                          /**< 0028: Capture Control Register (CCR). The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  CR0;                          /**< 002C: Capture Register (CR). CR is loaded with the value of TC when there is an event on the CT16Bn_CAPm input */
   __I  uint32_t  CR1;                          /**< 0030: Capture Register (CR). CR is loaded with the value of TC when there is an event on the CT16Bn_CAPm input */
        uint8_t   RESERVED_0[8];               
   __IO uint32_t  EMR;                          /**< 003C: External Match Register (EMR). The EMR controls the match function and the external match pins CT16B0_MAT[2:0] */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register (CTCR). The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register (PWMCON). The PWMCON enables PWM mode for the external match pins CT16B0_MAT[2:0] */
} CT16B0_Type;

/**
 * @} */ /* End group CT16B_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CT16B0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CT16B_Register_Masks_GROUP CT16B Register Masks
* @brief Register Masks for CT16B
* @{
*/
/* ------- IR Bit Fields                            ------ */
#define CT16B0_IR_MR0INT_MASK                    (0x1U)                                              /*!< CT16B0_IR.MR0INT Mask                   */
#define CT16B0_IR_MR0INT_SHIFT                   (0U)                                                /*!< CT16B0_IR.MR0INT Position               */
#define CT16B0_IR_MR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT16B0_IR.MR0INT Field                  */
#define CT16B0_IR_MR1INT_MASK                    (0x2U)                                              /*!< CT16B0_IR.MR1INT Mask                   */
#define CT16B0_IR_MR1INT_SHIFT                   (1U)                                                /*!< CT16B0_IR.MR1INT Position               */
#define CT16B0_IR_MR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT16B0_IR.MR1INT Field                  */
#define CT16B0_IR_MR2INT_MASK                    (0x4U)                                              /*!< CT16B0_IR.MR2INT Mask                   */
#define CT16B0_IR_MR2INT_SHIFT                   (2U)                                                /*!< CT16B0_IR.MR2INT Position               */
#define CT16B0_IR_MR2INT(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT16B0_IR.MR2INT Field                  */
#define CT16B0_IR_MR3INT_MASK                    (0x8U)                                              /*!< CT16B0_IR.MR3INT Mask                   */
#define CT16B0_IR_MR3INT_SHIFT                   (3U)                                                /*!< CT16B0_IR.MR3INT Position               */
#define CT16B0_IR_MR3INT(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT16B0_IR.MR3INT Field                  */
#define CT16B0_IR_CR0INT_MASK                    (0x10U)                                             /*!< CT16B0_IR.CR0INT Mask                   */
#define CT16B0_IR_CR0INT_SHIFT                   (4U)                                                /*!< CT16B0_IR.CR0INT Position               */
#define CT16B0_IR_CR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CT16B0_IR.CR0INT Field                  */
#define CT16B0_IR_CR1INT_MASK                    (0x20U)                                             /*!< CT16B0_IR.CR1INT Mask                   */
#define CT16B0_IR_CR1INT_SHIFT                   (5U)                                                /*!< CT16B0_IR.CR1INT Position               */
#define CT16B0_IR_CR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< CT16B0_IR.CR1INT Field                  */
/* ------- TCR Bit Fields                           ------ */
#define CT16B0_TCR_CEN_MASK                      (0x1U)                                              /*!< CT16B0_TCR.CEN Mask                     */
#define CT16B0_TCR_CEN_SHIFT                     (0U)                                                /*!< CT16B0_TCR.CEN Position                 */
#define CT16B0_TCR_CEN(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT16B0_TCR.CEN Field                    */
#define CT16B0_TCR_CRST_MASK                     (0x2U)                                              /*!< CT16B0_TCR.CRST Mask                    */
#define CT16B0_TCR_CRST_SHIFT                    (1U)                                                /*!< CT16B0_TCR.CRST Position                */
#define CT16B0_TCR_CRST(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT16B0_TCR.CRST Field                   */
/* ------- TC Bit Fields                            ------ */
#define CT16B0_TC_TC_MASK                        (0xFFFFU)                                           /*!< CT16B0_TC.TC Mask                       */
#define CT16B0_TC_TC_SHIFT                       (0U)                                                /*!< CT16B0_TC.TC Position                   */
#define CT16B0_TC_TC(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CT16B0_TC.TC Field                      */
/* ------- PR Bit Fields                            ------ */
#define CT16B0_PR_PR_MASK                        (0xFFFFU)                                           /*!< CT16B0_PR.PR Mask                       */
#define CT16B0_PR_PR_SHIFT                       (0U)                                                /*!< CT16B0_PR.PR Position                   */
#define CT16B0_PR_PR(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CT16B0_PR.PR Field                      */
/* ------- PC Bit Fields                            ------ */
#define CT16B0_PC_PC_MASK                        (0xFFFFU)                                           /*!< CT16B0_PC.PC Mask                       */
#define CT16B0_PC_PC_SHIFT                       (0U)                                                /*!< CT16B0_PC.PC Position                   */
#define CT16B0_PC_PC(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CT16B0_PC.PC Field                      */
/* ------- MCR Bit Fields                           ------ */
#define CT16B0_MCR_MR0I_MASK                     (0x1U)                                              /*!< CT16B0_MCR.MR0I Mask                    */
#define CT16B0_MCR_MR0I_SHIFT                    (0U)                                                /*!< CT16B0_MCR.MR0I Position                */
#define CT16B0_MCR_MR0I(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT16B0_MCR.MR0I Field                   */
#define CT16B0_MCR_MR0R_MASK                     (0x2U)                                              /*!< CT16B0_MCR.MR0R Mask                    */
#define CT16B0_MCR_MR0R_SHIFT                    (1U)                                                /*!< CT16B0_MCR.MR0R Position                */
#define CT16B0_MCR_MR0R(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT16B0_MCR.MR0R Field                   */
#define CT16B0_MCR_MR0S_MASK                     (0x4U)                                              /*!< CT16B0_MCR.MR0S Mask                    */
#define CT16B0_MCR_MR0S_SHIFT                    (2U)                                                /*!< CT16B0_MCR.MR0S Position                */
#define CT16B0_MCR_MR0S(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT16B0_MCR.MR0S Field                   */
#define CT16B0_MCR_MR1I_MASK                     (0x8U)                                              /*!< CT16B0_MCR.MR1I Mask                    */
#define CT16B0_MCR_MR1I_SHIFT                    (3U)                                                /*!< CT16B0_MCR.MR1I Position                */
#define CT16B0_MCR_MR1I(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT16B0_MCR.MR1I Field                   */
#define CT16B0_MCR_MR1R_MASK                     (0x10U)                                             /*!< CT16B0_MCR.MR1R Mask                    */
#define CT16B0_MCR_MR1R_SHIFT                    (4U)                                                /*!< CT16B0_MCR.MR1R Position                */
#define CT16B0_MCR_MR1R(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CT16B0_MCR.MR1R Field                   */
#define CT16B0_MCR_MR1S_MASK                     (0x20U)                                             /*!< CT16B0_MCR.MR1S Mask                    */
#define CT16B0_MCR_MR1S_SHIFT                    (5U)                                                /*!< CT16B0_MCR.MR1S Position                */
#define CT16B0_MCR_MR1S(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< CT16B0_MCR.MR1S Field                   */
#define CT16B0_MCR_MR2I_MASK                     (0x40U)                                             /*!< CT16B0_MCR.MR2I Mask                    */
#define CT16B0_MCR_MR2I_SHIFT                    (6U)                                                /*!< CT16B0_MCR.MR2I Position                */
#define CT16B0_MCR_MR2I(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< CT16B0_MCR.MR2I Field                   */
#define CT16B0_MCR_MR2R_MASK                     (0x80U)                                             /*!< CT16B0_MCR.MR2R Mask                    */
#define CT16B0_MCR_MR2R_SHIFT                    (7U)                                                /*!< CT16B0_MCR.MR2R Position                */
#define CT16B0_MCR_MR2R(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< CT16B0_MCR.MR2R Field                   */
#define CT16B0_MCR_MR2S_MASK                     (0x100U)                                            /*!< CT16B0_MCR.MR2S Mask                    */
#define CT16B0_MCR_MR2S_SHIFT                    (8U)                                                /*!< CT16B0_MCR.MR2S Position                */
#define CT16B0_MCR_MR2S(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< CT16B0_MCR.MR2S Field                   */
#define CT16B0_MCR_MR3I_MASK                     (0x200U)                                            /*!< CT16B0_MCR.MR3I Mask                    */
#define CT16B0_MCR_MR3I_SHIFT                    (9U)                                                /*!< CT16B0_MCR.MR3I Position                */
#define CT16B0_MCR_MR3I(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< CT16B0_MCR.MR3I Field                   */
#define CT16B0_MCR_MR3R_MASK                     (0x400U)                                            /*!< CT16B0_MCR.MR3R Mask                    */
#define CT16B0_MCR_MR3R_SHIFT                    (10U)                                               /*!< CT16B0_MCR.MR3R Position                */
#define CT16B0_MCR_MR3R(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< CT16B0_MCR.MR3R Field                   */
#define CT16B0_MCR_MR3S_MASK                     (0x800U)                                            /*!< CT16B0_MCR.MR3S Mask                    */
#define CT16B0_MCR_MR3S_SHIFT                    (11U)                                               /*!< CT16B0_MCR.MR3S Position                */
#define CT16B0_MCR_MR3S(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< CT16B0_MCR.MR3S Field                   */
/* ------- MR Bit Fields                            ------ */
#define CT16B0_MR_MATCH_MASK                     (0xFFFFU)                                           /*!< CT16B0_MR.MATCH Mask                    */
#define CT16B0_MR_MATCH_SHIFT                    (0U)                                                /*!< CT16B0_MR.MATCH Position                */
#define CT16B0_MR_MATCH(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CT16B0_MR.MATCH Field                   */
/* ------- CCR Bit Fields                           ------ */
#define CT16B0_CCR_CAP0RE_MASK                   (0x1U)                                              /*!< CT16B0_CCR.CAP0RE Mask                  */
#define CT16B0_CCR_CAP0RE_SHIFT                  (0U)                                                /*!< CT16B0_CCR.CAP0RE Position              */
#define CT16B0_CCR_CAP0RE(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT16B0_CCR.CAP0RE Field                 */
#define CT16B0_CCR_CAP0FE_MASK                   (0x2U)                                              /*!< CT16B0_CCR.CAP0FE Mask                  */
#define CT16B0_CCR_CAP0FE_SHIFT                  (1U)                                                /*!< CT16B0_CCR.CAP0FE Position              */
#define CT16B0_CCR_CAP0FE(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT16B0_CCR.CAP0FE Field                 */
#define CT16B0_CCR_CAP0I_MASK                    (0x4U)                                              /*!< CT16B0_CCR.CAP0I Mask                   */
#define CT16B0_CCR_CAP0I_SHIFT                   (2U)                                                /*!< CT16B0_CCR.CAP0I Position               */
#define CT16B0_CCR_CAP0I(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT16B0_CCR.CAP0I Field                  */
#define CT16B0_CCR_CAP1RE_MASK                   (0x8U)                                              /*!< CT16B0_CCR.CAP1RE Mask                  */
#define CT16B0_CCR_CAP1RE_SHIFT                  (3U)                                                /*!< CT16B0_CCR.CAP1RE Position              */
#define CT16B0_CCR_CAP1RE(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT16B0_CCR.CAP1RE Field                 */
#define CT16B0_CCR_CAP1FE_MASK                   (0x10U)                                             /*!< CT16B0_CCR.CAP1FE Mask                  */
#define CT16B0_CCR_CAP1FE_SHIFT                  (4U)                                                /*!< CT16B0_CCR.CAP1FE Position              */
#define CT16B0_CCR_CAP1FE(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CT16B0_CCR.CAP1FE Field                 */
#define CT16B0_CCR_CAP1I_MASK                    (0x20U)                                             /*!< CT16B0_CCR.CAP1I Mask                   */
#define CT16B0_CCR_CAP1I_SHIFT                   (5U)                                                /*!< CT16B0_CCR.CAP1I Position               */
#define CT16B0_CCR_CAP1I(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< CT16B0_CCR.CAP1I Field                  */
/* ------- CR0 Bit Fields                           ------ */
#define CT16B0_CR0_CAP_MASK                      (0xFFFFU)                                           /*!< CT16B0_CR0.CAP Mask                     */
#define CT16B0_CR0_CAP_SHIFT                     (0U)                                                /*!< CT16B0_CR0.CAP Position                 */
#define CT16B0_CR0_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CT16B0_CR0.CAP Field                    */
/* ------- CR1 Bit Fields                           ------ */
#define CT16B0_CR1_CAP_MASK                      (0xFFFFU)                                           /*!< CT16B0_CR1.CAP Mask                     */
#define CT16B0_CR1_CAP_SHIFT                     (0U)                                                /*!< CT16B0_CR1.CAP Position                 */
#define CT16B0_CR1_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CT16B0_CR1.CAP Field                    */
/* ------- EMR Bit Fields                           ------ */
#define CT16B0_EMR_EM0_MASK                      (0x1U)                                              /*!< CT16B0_EMR.EM0 Mask                     */
#define CT16B0_EMR_EM0_SHIFT                     (0U)                                                /*!< CT16B0_EMR.EM0 Position                 */
#define CT16B0_EMR_EM0(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT16B0_EMR.EM0 Field                    */
#define CT16B0_EMR_EM1_MASK                      (0x2U)                                              /*!< CT16B0_EMR.EM1 Mask                     */
#define CT16B0_EMR_EM1_SHIFT                     (1U)                                                /*!< CT16B0_EMR.EM1 Position                 */
#define CT16B0_EMR_EM1(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT16B0_EMR.EM1 Field                    */
#define CT16B0_EMR_EM2_MASK                      (0x4U)                                              /*!< CT16B0_EMR.EM2 Mask                     */
#define CT16B0_EMR_EM2_SHIFT                     (2U)                                                /*!< CT16B0_EMR.EM2 Position                 */
#define CT16B0_EMR_EM2(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT16B0_EMR.EM2 Field                    */
#define CT16B0_EMR_EM3_MASK                      (0x8U)                                              /*!< CT16B0_EMR.EM3 Mask                     */
#define CT16B0_EMR_EM3_SHIFT                     (3U)                                                /*!< CT16B0_EMR.EM3 Position                 */
#define CT16B0_EMR_EM3(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT16B0_EMR.EM3 Field                    */
#define CT16B0_EMR_EMC0_MASK                     (0x30U)                                             /*!< CT16B0_EMR.EMC0 Mask                    */
#define CT16B0_EMR_EMC0_SHIFT                    (4U)                                                /*!< CT16B0_EMR.EMC0 Position                */
#define CT16B0_EMR_EMC0(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< CT16B0_EMR.EMC0 Field                   */
#define CT16B0_EMR_EMC1_MASK                     (0xC0U)                                             /*!< CT16B0_EMR.EMC1 Mask                    */
#define CT16B0_EMR_EMC1_SHIFT                    (6U)                                                /*!< CT16B0_EMR.EMC1 Position                */
#define CT16B0_EMR_EMC1(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< CT16B0_EMR.EMC1 Field                   */
#define CT16B0_EMR_EMC2_MASK                     (0x300U)                                            /*!< CT16B0_EMR.EMC2 Mask                    */
#define CT16B0_EMR_EMC2_SHIFT                    (8U)                                                /*!< CT16B0_EMR.EMC2 Position                */
#define CT16B0_EMR_EMC2(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< CT16B0_EMR.EMC2 Field                   */
#define CT16B0_EMR_EMC3_MASK                     (0xC00U)                                            /*!< CT16B0_EMR.EMC3 Mask                    */
#define CT16B0_EMR_EMC3_SHIFT                    (10U)                                               /*!< CT16B0_EMR.EMC3 Position                */
#define CT16B0_EMR_EMC3(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0xC00UL)        /*!< CT16B0_EMR.EMC3 Field                   */
/* ------- CTCR Bit Fields                          ------ */
#define CT16B0_CTCR_CTM_MASK                     (0x3U)                                              /*!< CT16B0_CTCR.CTM Mask                    */
#define CT16B0_CTCR_CTM_SHIFT                    (0U)                                                /*!< CT16B0_CTCR.CTM Position                */
#define CT16B0_CTCR_CTM(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< CT16B0_CTCR.CTM Field                   */
#define CT16B0_CTCR_CIS_MASK                     (0xCU)                                              /*!< CT16B0_CTCR.CIS Mask                    */
#define CT16B0_CTCR_CIS_SHIFT                    (2U)                                                /*!< CT16B0_CTCR.CIS Position                */
#define CT16B0_CTCR_CIS(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< CT16B0_CTCR.CIS Field                   */
#define CT16B0_CTCR_ENCC_MASK                    (0x10U)                                             /*!< CT16B0_CTCR.ENCC Mask                   */
#define CT16B0_CTCR_ENCC_SHIFT                   (4U)                                                /*!< CT16B0_CTCR.ENCC Position               */
#define CT16B0_CTCR_ENCC(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CT16B0_CTCR.ENCC Field                  */
#define CT16B0_CTCR_SELCC_MASK                   (0xE0U)                                             /*!< CT16B0_CTCR.SELCC Mask                  */
#define CT16B0_CTCR_SELCC_SHIFT                  (5U)                                                /*!< CT16B0_CTCR.SELCC Position              */
#define CT16B0_CTCR_SELCC(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0xE0UL)          /*!< CT16B0_CTCR.SELCC Field                 */
/* ------- PWMC Bit Fields                          ------ */
#define CT16B0_PWMC_PWMEN0_MASK                  (0x1U)                                              /*!< CT16B0_PWMC.PWMEN0 Mask                 */
#define CT16B0_PWMC_PWMEN0_SHIFT                 (0U)                                                /*!< CT16B0_PWMC.PWMEN0 Position             */
#define CT16B0_PWMC_PWMEN0(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT16B0_PWMC.PWMEN0 Field                */
#define CT16B0_PWMC_PWMEN1_MASK                  (0x2U)                                              /*!< CT16B0_PWMC.PWMEN1 Mask                 */
#define CT16B0_PWMC_PWMEN1_SHIFT                 (1U)                                                /*!< CT16B0_PWMC.PWMEN1 Position             */
#define CT16B0_PWMC_PWMEN1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT16B0_PWMC.PWMEN1 Field                */
#define CT16B0_PWMC_PWMEN2_MASK                  (0x4U)                                              /*!< CT16B0_PWMC.PWMEN2 Mask                 */
#define CT16B0_PWMC_PWMEN2_SHIFT                 (2U)                                                /*!< CT16B0_PWMC.PWMEN2 Position             */
#define CT16B0_PWMC_PWMEN2(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT16B0_PWMC.PWMEN2 Field                */
#define CT16B0_PWMC_PWMEN3_MASK                  (0x8U)                                              /*!< CT16B0_PWMC.PWMEN3 Mask                 */
#define CT16B0_PWMC_PWMEN3_SHIFT                 (3U)                                                /*!< CT16B0_PWMC.PWMEN3 Position             */
#define CT16B0_PWMC_PWMEN3(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT16B0_PWMC.PWMEN3 Field                */
/**
 * @} */ /* End group CT16B_Register_Masks_GROUP 
 */

/* CT16B0 - Peripheral instance base addresses */
#define CT16B0_BasePtr                 0x4000C000UL //!< Peripheral base address
#define CT16B0                         ((CT16B0_Type *) CT16B0_BasePtr) //!< Freescale base pointer
#define CT16B0_BASE_PTR                (CT16B0) //!< Freescale style base pointer
/**
 * @} */ /* End group CT16B_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT16B_Peripheral_access_layer_GROUP CT16B Peripheral Access Layer
* @brief C Struct for CT16B
* @{
*/

/* ================================================================================ */
/* ================           CT16B1 (derived from CT16B0)         ================ */
/* ================================================================================ */

/**
 * @brief 16-bit counter/timer
 */

/* CT16B1 - Peripheral instance base addresses */
#define CT16B1_BasePtr                 0x40010000UL //!< Peripheral base address
#define CT16B1                         ((CT16B0_Type *) CT16B1_BasePtr) //!< Freescale base pointer
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
/* ================           CT32B0 (file:CT32B0_LPC11xx)         ================ */
/* ================================================================================ */

/**
 * @brief LPC1100XL series: 32-bit counter/timer CT32B0/1
 */
/**
* @addtogroup CT32B0_structs_GROUP CT32B0 struct
* @brief Struct for CT32B0
* @{
*/
typedef struct {                                /*       CT32B0 Structure                                             */
   __IO uint32_t  IR;                           /**< 0000: Interrupt Register (IR). The IR can be written to clear interrupts. The IR can be read to identify which of five possible interrupt sources are pending */
   __IO uint32_t  TCR;                          /**< 0004: Timer Control Register (TCR). The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  TC;                           /**< 0008: Timer Counter (TC). The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  PR;                           /**< 000C: Prescale Register (PR). When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  PC;                           /**< 0010: Prescale Counter (PC). The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  MCR;                          /**< 0014: Match Control Register (MCR). The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  MR[4];                        /**< 0018: Match Register. MR can be enabled through the                */
   __IO uint32_t  CCR;                          /**< 0028: Capture Control Register (CCR). The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  CR0;                          /**< 002C: Capture Register (CR). CR is loaded with the value of TC when there is an event on the CT16Bn_CAPm input */
   __I  uint32_t  CR1;                          /**< 0030: Capture Register (CR). CR is loaded with the value of TC when there is an event on the CT16Bn_CAPm input */
        uint8_t   RESERVED_0[8];               
   __IO uint32_t  EMR;                          /**< 003C: External Match Register (EMR). The EMR controls the match function and the external match pins CT32B0_MAT[3:0] */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  CTCR;                         /**< 0070: Count Control Register (CTCR). The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  PWMC;                         /**< 0074: PWM Control Register (PWMCON). The PWMCON enables PWM mode for the external match pins CT32B0_MAT[3:0] */
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
#define CT32B0_IR_MR0INT_MASK                    (0x1U)                                              /*!< CT32B0_IR.MR0INT Mask                   */
#define CT32B0_IR_MR0INT_SHIFT                   (0U)                                                /*!< CT32B0_IR.MR0INT Position               */
#define CT32B0_IR_MR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT32B0_IR.MR0INT Field                  */
#define CT32B0_IR_MR1INT_MASK                    (0x2U)                                              /*!< CT32B0_IR.MR1INT Mask                   */
#define CT32B0_IR_MR1INT_SHIFT                   (1U)                                                /*!< CT32B0_IR.MR1INT Position               */
#define CT32B0_IR_MR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT32B0_IR.MR1INT Field                  */
#define CT32B0_IR_MR2INT_MASK                    (0x4U)                                              /*!< CT32B0_IR.MR2INT Mask                   */
#define CT32B0_IR_MR2INT_SHIFT                   (2U)                                                /*!< CT32B0_IR.MR2INT Position               */
#define CT32B0_IR_MR2INT(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT32B0_IR.MR2INT Field                  */
#define CT32B0_IR_MR3INT_MASK                    (0x8U)                                              /*!< CT32B0_IR.MR3INT Mask                   */
#define CT32B0_IR_MR3INT_SHIFT                   (3U)                                                /*!< CT32B0_IR.MR3INT Position               */
#define CT32B0_IR_MR3INT(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT32B0_IR.MR3INT Field                  */
#define CT32B0_IR_CR0INT_MASK                    (0x10U)                                             /*!< CT32B0_IR.CR0INT Mask                   */
#define CT32B0_IR_CR0INT_SHIFT                   (4U)                                                /*!< CT32B0_IR.CR0INT Position               */
#define CT32B0_IR_CR0INT(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CT32B0_IR.CR0INT Field                  */
#define CT32B0_IR_CR1INT_MASK                    (0x20U)                                             /*!< CT32B0_IR.CR1INT Mask                   */
#define CT32B0_IR_CR1INT_SHIFT                   (5U)                                                /*!< CT32B0_IR.CR1INT Position               */
#define CT32B0_IR_CR1INT(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< CT32B0_IR.CR1INT Field                  */
/* ------- TCR Bit Fields                           ------ */
#define CT32B0_TCR_CEN_MASK                      (0x1U)                                              /*!< CT32B0_TCR.CEN Mask                     */
#define CT32B0_TCR_CEN_SHIFT                     (0U)                                                /*!< CT32B0_TCR.CEN Position                 */
#define CT32B0_TCR_CEN(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT32B0_TCR.CEN Field                    */
#define CT32B0_TCR_CRST_MASK                     (0x2U)                                              /*!< CT32B0_TCR.CRST Mask                    */
#define CT32B0_TCR_CRST_SHIFT                    (1U)                                                /*!< CT32B0_TCR.CRST Position                */
#define CT32B0_TCR_CRST(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT32B0_TCR.CRST Field                   */
/* ------- TC Bit Fields                            ------ */
#define CT32B0_TC_TC_MASK                        (0xFFFFFFFFU)                                       /*!< CT32B0_TC.TC Mask                       */
#define CT32B0_TC_TC_SHIFT                       (0U)                                                /*!< CT32B0_TC.TC Position                   */
#define CT32B0_TC_TC(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CT32B0_TC.TC Field                      */
/* ------- PR Bit Fields                            ------ */
#define CT32B0_PR_PR_MASK                        (0xFFFFFFFFU)                                       /*!< CT32B0_PR.PR Mask                       */
#define CT32B0_PR_PR_SHIFT                       (0U)                                                /*!< CT32B0_PR.PR Position                   */
#define CT32B0_PR_PR(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CT32B0_PR.PR Field                      */
/* ------- PC Bit Fields                            ------ */
#define CT32B0_PC_PC_MASK                        (0xFFFFFFFFU)                                       /*!< CT32B0_PC.PC Mask                       */
#define CT32B0_PC_PC_SHIFT                       (0U)                                                /*!< CT32B0_PC.PC Position                   */
#define CT32B0_PC_PC(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CT32B0_PC.PC Field                      */
/* ------- MCR Bit Fields                           ------ */
#define CT32B0_MCR_MR0I_MASK                     (0x1U)                                              /*!< CT32B0_MCR.MR0I Mask                    */
#define CT32B0_MCR_MR0I_SHIFT                    (0U)                                                /*!< CT32B0_MCR.MR0I Position                */
#define CT32B0_MCR_MR0I(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT32B0_MCR.MR0I Field                   */
#define CT32B0_MCR_MR0R_MASK                     (0x2U)                                              /*!< CT32B0_MCR.MR0R Mask                    */
#define CT32B0_MCR_MR0R_SHIFT                    (1U)                                                /*!< CT32B0_MCR.MR0R Position                */
#define CT32B0_MCR_MR0R(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT32B0_MCR.MR0R Field                   */
#define CT32B0_MCR_MR0S_MASK                     (0x4U)                                              /*!< CT32B0_MCR.MR0S Mask                    */
#define CT32B0_MCR_MR0S_SHIFT                    (2U)                                                /*!< CT32B0_MCR.MR0S Position                */
#define CT32B0_MCR_MR0S(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT32B0_MCR.MR0S Field                   */
#define CT32B0_MCR_MR1I_MASK                     (0x8U)                                              /*!< CT32B0_MCR.MR1I Mask                    */
#define CT32B0_MCR_MR1I_SHIFT                    (3U)                                                /*!< CT32B0_MCR.MR1I Position                */
#define CT32B0_MCR_MR1I(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT32B0_MCR.MR1I Field                   */
#define CT32B0_MCR_MR1R_MASK                     (0x10U)                                             /*!< CT32B0_MCR.MR1R Mask                    */
#define CT32B0_MCR_MR1R_SHIFT                    (4U)                                                /*!< CT32B0_MCR.MR1R Position                */
#define CT32B0_MCR_MR1R(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CT32B0_MCR.MR1R Field                   */
#define CT32B0_MCR_MR1S_MASK                     (0x20U)                                             /*!< CT32B0_MCR.MR1S Mask                    */
#define CT32B0_MCR_MR1S_SHIFT                    (5U)                                                /*!< CT32B0_MCR.MR1S Position                */
#define CT32B0_MCR_MR1S(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< CT32B0_MCR.MR1S Field                   */
#define CT32B0_MCR_MR2I_MASK                     (0x40U)                                             /*!< CT32B0_MCR.MR2I Mask                    */
#define CT32B0_MCR_MR2I_SHIFT                    (6U)                                                /*!< CT32B0_MCR.MR2I Position                */
#define CT32B0_MCR_MR2I(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< CT32B0_MCR.MR2I Field                   */
#define CT32B0_MCR_MR2R_MASK                     (0x80U)                                             /*!< CT32B0_MCR.MR2R Mask                    */
#define CT32B0_MCR_MR2R_SHIFT                    (7U)                                                /*!< CT32B0_MCR.MR2R Position                */
#define CT32B0_MCR_MR2R(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< CT32B0_MCR.MR2R Field                   */
#define CT32B0_MCR_MR2S_MASK                     (0x100U)                                            /*!< CT32B0_MCR.MR2S Mask                    */
#define CT32B0_MCR_MR2S_SHIFT                    (8U)                                                /*!< CT32B0_MCR.MR2S Position                */
#define CT32B0_MCR_MR2S(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< CT32B0_MCR.MR2S Field                   */
#define CT32B0_MCR_MR3I_MASK                     (0x200U)                                            /*!< CT32B0_MCR.MR3I Mask                    */
#define CT32B0_MCR_MR3I_SHIFT                    (9U)                                                /*!< CT32B0_MCR.MR3I Position                */
#define CT32B0_MCR_MR3I(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< CT32B0_MCR.MR3I Field                   */
#define CT32B0_MCR_MR3R_MASK                     (0x400U)                                            /*!< CT32B0_MCR.MR3R Mask                    */
#define CT32B0_MCR_MR3R_SHIFT                    (10U)                                               /*!< CT32B0_MCR.MR3R Position                */
#define CT32B0_MCR_MR3R(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< CT32B0_MCR.MR3R Field                   */
#define CT32B0_MCR_MR3S_MASK                     (0x800U)                                            /*!< CT32B0_MCR.MR3S Mask                    */
#define CT32B0_MCR_MR3S_SHIFT                    (11U)                                               /*!< CT32B0_MCR.MR3S Position                */
#define CT32B0_MCR_MR3S(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< CT32B0_MCR.MR3S Field                   */
/* ------- MR Bit Fields                            ------ */
#define CT32B0_MR_MATCH_MASK                     (0xFFFFFFFFU)                                       /*!< CT32B0_MR.MATCH Mask                    */
#define CT32B0_MR_MATCH_SHIFT                    (0U)                                                /*!< CT32B0_MR.MATCH Position                */
#define CT32B0_MR_MATCH(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CT32B0_MR.MATCH Field                   */
/* ------- CCR Bit Fields                           ------ */
#define CT32B0_CCR_CAP0RE_MASK                   (0x1U)                                              /*!< CT32B0_CCR.CAP0RE Mask                  */
#define CT32B0_CCR_CAP0RE_SHIFT                  (0U)                                                /*!< CT32B0_CCR.CAP0RE Position              */
#define CT32B0_CCR_CAP0RE(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT32B0_CCR.CAP0RE Field                 */
#define CT32B0_CCR_CAP0FE_MASK                   (0x2U)                                              /*!< CT32B0_CCR.CAP0FE Mask                  */
#define CT32B0_CCR_CAP0FE_SHIFT                  (1U)                                                /*!< CT32B0_CCR.CAP0FE Position              */
#define CT32B0_CCR_CAP0FE(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT32B0_CCR.CAP0FE Field                 */
#define CT32B0_CCR_CAP0I_MASK                    (0x4U)                                              /*!< CT32B0_CCR.CAP0I Mask                   */
#define CT32B0_CCR_CAP0I_SHIFT                   (2U)                                                /*!< CT32B0_CCR.CAP0I Position               */
#define CT32B0_CCR_CAP0I(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT32B0_CCR.CAP0I Field                  */
#define CT32B0_CCR_CAP1RE_MASK                   (0x8U)                                              /*!< CT32B0_CCR.CAP1RE Mask                  */
#define CT32B0_CCR_CAP1RE_SHIFT                  (3U)                                                /*!< CT32B0_CCR.CAP1RE Position              */
#define CT32B0_CCR_CAP1RE(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT32B0_CCR.CAP1RE Field                 */
#define CT32B0_CCR_CAP1FE_MASK                   (0x10U)                                             /*!< CT32B0_CCR.CAP1FE Mask                  */
#define CT32B0_CCR_CAP1FE_SHIFT                  (4U)                                                /*!< CT32B0_CCR.CAP1FE Position              */
#define CT32B0_CCR_CAP1FE(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CT32B0_CCR.CAP1FE Field                 */
#define CT32B0_CCR_CAP1I_MASK                    (0x20U)                                             /*!< CT32B0_CCR.CAP1I Mask                   */
#define CT32B0_CCR_CAP1I_SHIFT                   (5U)                                                /*!< CT32B0_CCR.CAP1I Position               */
#define CT32B0_CCR_CAP1I(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< CT32B0_CCR.CAP1I Field                  */
/* ------- CR0 Bit Fields                           ------ */
#define CT32B0_CR0_CAP_MASK                      (0xFFFFFFFFU)                                       /*!< CT32B0_CR0.CAP Mask                     */
#define CT32B0_CR0_CAP_SHIFT                     (0U)                                                /*!< CT32B0_CR0.CAP Position                 */
#define CT32B0_CR0_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CT32B0_CR0.CAP Field                    */
/* ------- CR1 Bit Fields                           ------ */
#define CT32B0_CR1_CAP_MASK                      (0xFFFFFFFFU)                                       /*!< CT32B0_CR1.CAP Mask                     */
#define CT32B0_CR1_CAP_SHIFT                     (0U)                                                /*!< CT32B0_CR1.CAP Position                 */
#define CT32B0_CR1_CAP(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CT32B0_CR1.CAP Field                    */
/* ------- EMR Bit Fields                           ------ */
#define CT32B0_EMR_EM0_MASK                      (0x1U)                                              /*!< CT32B0_EMR.EM0 Mask                     */
#define CT32B0_EMR_EM0_SHIFT                     (0U)                                                /*!< CT32B0_EMR.EM0 Position                 */
#define CT32B0_EMR_EM0(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT32B0_EMR.EM0 Field                    */
#define CT32B0_EMR_EM1_MASK                      (0x2U)                                              /*!< CT32B0_EMR.EM1 Mask                     */
#define CT32B0_EMR_EM1_SHIFT                     (1U)                                                /*!< CT32B0_EMR.EM1 Position                 */
#define CT32B0_EMR_EM1(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT32B0_EMR.EM1 Field                    */
#define CT32B0_EMR_EM2_MASK                      (0x4U)                                              /*!< CT32B0_EMR.EM2 Mask                     */
#define CT32B0_EMR_EM2_SHIFT                     (2U)                                                /*!< CT32B0_EMR.EM2 Position                 */
#define CT32B0_EMR_EM2(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT32B0_EMR.EM2 Field                    */
#define CT32B0_EMR_EM3_MASK                      (0x8U)                                              /*!< CT32B0_EMR.EM3 Mask                     */
#define CT32B0_EMR_EM3_SHIFT                     (3U)                                                /*!< CT32B0_EMR.EM3 Position                 */
#define CT32B0_EMR_EM3(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT32B0_EMR.EM3 Field                    */
#define CT32B0_EMR_EMC0_MASK                     (0x30U)                                             /*!< CT32B0_EMR.EMC0 Mask                    */
#define CT32B0_EMR_EMC0_SHIFT                    (4U)                                                /*!< CT32B0_EMR.EMC0 Position                */
#define CT32B0_EMR_EMC0(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< CT32B0_EMR.EMC0 Field                   */
#define CT32B0_EMR_EMC1_MASK                     (0xC0U)                                             /*!< CT32B0_EMR.EMC1 Mask                    */
#define CT32B0_EMR_EMC1_SHIFT                    (6U)                                                /*!< CT32B0_EMR.EMC1 Position                */
#define CT32B0_EMR_EMC1(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< CT32B0_EMR.EMC1 Field                   */
#define CT32B0_EMR_EMC2_MASK                     (0x300U)                                            /*!< CT32B0_EMR.EMC2 Mask                    */
#define CT32B0_EMR_EMC2_SHIFT                    (8U)                                                /*!< CT32B0_EMR.EMC2 Position                */
#define CT32B0_EMR_EMC2(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< CT32B0_EMR.EMC2 Field                   */
#define CT32B0_EMR_EMC3_MASK                     (0xC00U)                                            /*!< CT32B0_EMR.EMC3 Mask                    */
#define CT32B0_EMR_EMC3_SHIFT                    (10U)                                               /*!< CT32B0_EMR.EMC3 Position                */
#define CT32B0_EMR_EMC3(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0xC00UL)        /*!< CT32B0_EMR.EMC3 Field                   */
/* ------- CTCR Bit Fields                          ------ */
#define CT32B0_CTCR_CTM_MASK                     (0x3U)                                              /*!< CT32B0_CTCR.CTM Mask                    */
#define CT32B0_CTCR_CTM_SHIFT                    (0U)                                                /*!< CT32B0_CTCR.CTM Position                */
#define CT32B0_CTCR_CTM(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< CT32B0_CTCR.CTM Field                   */
#define CT32B0_CTCR_CIS_MASK                     (0xCU)                                              /*!< CT32B0_CTCR.CIS Mask                    */
#define CT32B0_CTCR_CIS_SHIFT                    (2U)                                                /*!< CT32B0_CTCR.CIS Position                */
#define CT32B0_CTCR_CIS(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< CT32B0_CTCR.CIS Field                   */
#define CT32B0_CTCR_ENCC_MASK                    (0x10U)                                             /*!< CT32B0_CTCR.ENCC Mask                   */
#define CT32B0_CTCR_ENCC_SHIFT                   (4U)                                                /*!< CT32B0_CTCR.ENCC Position               */
#define CT32B0_CTCR_ENCC(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CT32B0_CTCR.ENCC Field                  */
#define CT32B0_CTCR_SELCC_MASK                   (0xE0U)                                             /*!< CT32B0_CTCR.SELCC Mask                  */
#define CT32B0_CTCR_SELCC_SHIFT                  (5U)                                                /*!< CT32B0_CTCR.SELCC Position              */
#define CT32B0_CTCR_SELCC(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0xE0UL)          /*!< CT32B0_CTCR.SELCC Field                 */
/* ------- PWMC Bit Fields                          ------ */
#define CT32B0_PWMC_PWMEN0_MASK                  (0x1U)                                              /*!< CT32B0_PWMC.PWMEN0 Mask                 */
#define CT32B0_PWMC_PWMEN0_SHIFT                 (0U)                                                /*!< CT32B0_PWMC.PWMEN0 Position             */
#define CT32B0_PWMC_PWMEN0(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CT32B0_PWMC.PWMEN0 Field                */
#define CT32B0_PWMC_PWMEN1_MASK                  (0x2U)                                              /*!< CT32B0_PWMC.PWMEN1 Mask                 */
#define CT32B0_PWMC_PWMEN1_SHIFT                 (1U)                                                /*!< CT32B0_PWMC.PWMEN1 Position             */
#define CT32B0_PWMC_PWMEN1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CT32B0_PWMC.PWMEN1 Field                */
#define CT32B0_PWMC_PWMEN2_MASK                  (0x4U)                                              /*!< CT32B0_PWMC.PWMEN2 Mask                 */
#define CT32B0_PWMC_PWMEN2_SHIFT                 (2U)                                                /*!< CT32B0_PWMC.PWMEN2 Position             */
#define CT32B0_PWMC_PWMEN2(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CT32B0_PWMC.PWMEN2 Field                */
#define CT32B0_PWMC_PWMEN3_MASK                  (0x8U)                                              /*!< CT32B0_PWMC.PWMEN3 Mask                 */
#define CT32B0_PWMC_PWMEN3_SHIFT                 (3U)                                                /*!< CT32B0_PWMC.PWMEN3 Position             */
#define CT32B0_PWMC_PWMEN3(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CT32B0_PWMC.PWMEN3 Field                */
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
* @addtogroup CT32B0_Peripheral_access_layer_GROUP CT32B0 Peripheral Access Layer
* @brief C Struct for CT32B0
* @{
*/

/* ================================================================================ */
/* ================           CT32B1 (derived from CT32B0)         ================ */
/* ================================================================================ */

/**
 * @brief LPC1100XL series: 32-bit counter/timer CT32B0/1
 */

/* CT32B1 - Peripheral instance base addresses */
#define CT32B1_BasePtr                 0x40018000UL //!< Peripheral base address
#define CT32B1                         ((CT32B0_Type *) CT32B1_BasePtr) //!< Freescale base pointer
#define CT32B1_BASE_PTR                (CT32B1) //!< Freescale style base pointer
/**
 * @} */ /* End group CT32B0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup C_CAN_Peripheral_access_layer_GROUP C_CAN Peripheral Access Layer
* @brief C Struct for C_CAN
* @{
*/

/* ================================================================================ */
/* ================           C_CAN (file:C_CAN_LPC11xx)           ================ */
/* ================================================================================ */

/**
 * @brief /LPC11Cxx C_CAN controller
 */
/**
* @addtogroup C_CAN_structs_GROUP C_CAN struct
* @brief Struct for C_CAN
* @{
*/
typedef struct {                                /*       C_CAN Structure                                              */
   __IO uint32_t  CANCNTL;                      /**< 0000: CAN control                                                  */
   __IO uint32_t  CANSTAT;                      /**< 0004: Status register                                              */
   __I  uint32_t  CANEC;                        /**< 0008: Error counter                                                */
   __IO uint32_t  CANBT;                        /**< 000C: Bit timing register                                          */
   __I  uint32_t  CANINT;                       /**< 0010: Interrupt register                                           */
   __IO uint32_t  CANTEST;                      /**< 0014: Test register                                                */
   __IO uint32_t  CANBRPE;                      /**< 0018: Baud rate prescaler extension register                       */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  CANIF1_CMDREQ;                /**< 0020: Message interface  command request                           */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CANIF1_CMDMSK_R;           /**< 0024: Message interface  command mask - read direction             */
      __IO uint32_t  CANIF1_CMDMSK_W;           /**< 0024: Message interface                                            */
   };
   __IO uint32_t  CANIF1_MSK1;                  /**< 0028: Message interface 1 mask 1                                   */
   __IO uint32_t  CANIF1_MSK2;                  /**< 002C: Message interface 1 mask 2                                   */
   __IO uint32_t  CANIF1_ARB1;                  /**< 0030: Message interface 1 arbitration 1                            */
   __IO uint32_t  CANIF1_ARB2;                  /**< 0034: Message interface 1 arbitration 2                            */
   __IO uint32_t  CANIF1_MCTRL;                 /**< 0038: Message interface 1 message control                          */
   __IO uint32_t  CANIF1_DA1;                   /**< 003C: Message interface 1 data A1                                  */
   __IO uint32_t  CANIF1_DA2;                   /**< 0040: Message interface 1 data A2                                  */
   __IO uint32_t  CANIF1_DB1;                   /**< 0044: Message interface 1 data B1                                  */
   __IO uint32_t  CANIF1_DB2;                   /**< 0048: Message interface 1 data B2                                  */
        uint8_t   RESERVED_1[52];              
   __IO uint32_t  CANIF2_CMDREQ;                /**< 0080: Message interface  command request                           */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CANIF2_CMDMSK_R;           /**< 0084: Message interface  command mask - read direction             */
      __IO uint32_t  CANIF2_CMDMSK_W;           /**< 0084: Message interface                                            */
   };
   __IO uint32_t  CANIF2_MSK1;                  /**< 0088: Message interface 1 mask 1                                   */
   __IO uint32_t  CANIF2_MSK2;                  /**< 008C: Message interface 1 mask 2                                   */
   __IO uint32_t  CANIF2_ARB1;                  /**< 0090: Message interface 1 arbitration 1                            */
   __IO uint32_t  CANIF2_ARB2;                  /**< 0094: Message interface 1 arbitration 2                            */
   __IO uint32_t  CANIF2_MCTRL;                 /**< 0098: Message interface 1 message control                          */
   __IO uint32_t  CANIF2_DA1;                   /**< 009C: Message interface 1 data A1                                  */
   __IO uint32_t  CANIF2_DA2;                   /**< 00A0: Message interface 1 data A2                                  */
   __IO uint32_t  CANIF2_DB1;                   /**< 00A4: Message interface 1 data B1                                  */
   __IO uint32_t  CANIF2_DB2;                   /**< 00A8: Message interface 1 data B2                                  */
        uint8_t   RESERVED_2[84];              
   __I  uint32_t  CANTXREQ1;                    /**< 0100: Transmission request 1                                       */
   __I  uint32_t  CANTXREQ2;                    /**< 0104: Transmission request 2                                       */
        uint8_t   RESERVED_3[24];              
   __I  uint32_t  CANND1;                       /**< 0120: New data 1                                                   */
   __I  uint32_t  CANND2;                       /**< 0124: New data 2                                                   */
        uint8_t   RESERVED_4[24];              
   __I  uint32_t  CANIR1;                       /**< 0140: Interrupt pending 1                                          */
   __I  uint32_t  CANIR2;                       /**< 0144: Interrupt pending 2                                          */
        uint8_t   RESERVED_5[24];              
   __I  uint32_t  CANMSGV1;                     /**< 0160: Message valid 1                                              */
   __I  uint32_t  CANMSGV2;                     /**< 0164: Message valid 2                                              */
        uint8_t   RESERVED_6[24];              
   __IO uint32_t  CANCLKDIV;                    /**< 0180: Can clock divider register                                   */
} C_CAN_Type;

/**
 * @} */ /* End group C_CAN_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'C_CAN' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup C_CAN_Register_Masks_GROUP C_CAN Register Masks
* @brief Register Masks for C_CAN
* @{
*/
/* ------- CANCNTL Bit Fields                       ------ */
#define C_CAN_CANCNTL_INIT_MASK                  (0x1U)                                              /*!< C_CAN_CANCNTL.INIT Mask                 */
#define C_CAN_CANCNTL_INIT_SHIFT                 (0U)                                                /*!< C_CAN_CANCNTL.INIT Position             */
#define C_CAN_CANCNTL_INIT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< C_CAN_CANCNTL.INIT Field                */
#define C_CAN_CANCNTL_IE_MASK                    (0x2U)                                              /*!< C_CAN_CANCNTL.IE Mask                   */
#define C_CAN_CANCNTL_IE_SHIFT                   (1U)                                                /*!< C_CAN_CANCNTL.IE Position               */
#define C_CAN_CANCNTL_IE(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< C_CAN_CANCNTL.IE Field                  */
#define C_CAN_CANCNTL_SIE_MASK                   (0x4U)                                              /*!< C_CAN_CANCNTL.SIE Mask                  */
#define C_CAN_CANCNTL_SIE_SHIFT                  (2U)                                                /*!< C_CAN_CANCNTL.SIE Position              */
#define C_CAN_CANCNTL_SIE(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< C_CAN_CANCNTL.SIE Field                 */
#define C_CAN_CANCNTL_EIE_MASK                   (0x8U)                                              /*!< C_CAN_CANCNTL.EIE Mask                  */
#define C_CAN_CANCNTL_EIE_SHIFT                  (3U)                                                /*!< C_CAN_CANCNTL.EIE Position              */
#define C_CAN_CANCNTL_EIE(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< C_CAN_CANCNTL.EIE Field                 */
#define C_CAN_CANCNTL_DAR_MASK                   (0x20U)                                             /*!< C_CAN_CANCNTL.DAR Mask                  */
#define C_CAN_CANCNTL_DAR_SHIFT                  (5U)                                                /*!< C_CAN_CANCNTL.DAR Position              */
#define C_CAN_CANCNTL_DAR(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< C_CAN_CANCNTL.DAR Field                 */
#define C_CAN_CANCNTL_CCE_MASK                   (0x40U)                                             /*!< C_CAN_CANCNTL.CCE Mask                  */
#define C_CAN_CANCNTL_CCE_SHIFT                  (6U)                                                /*!< C_CAN_CANCNTL.CCE Position              */
#define C_CAN_CANCNTL_CCE(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< C_CAN_CANCNTL.CCE Field                 */
#define C_CAN_CANCNTL_TEST_MASK                  (0x80U)                                             /*!< C_CAN_CANCNTL.TEST Mask                 */
#define C_CAN_CANCNTL_TEST_SHIFT                 (7U)                                                /*!< C_CAN_CANCNTL.TEST Position             */
#define C_CAN_CANCNTL_TEST(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANCNTL.TEST Field                */
/* ------- CANSTAT Bit Fields                       ------ */
#define C_CAN_CANSTAT_LEC_MASK                   (0x7U)                                              /*!< C_CAN_CANSTAT.LEC Mask                  */
#define C_CAN_CANSTAT_LEC_SHIFT                  (0U)                                                /*!< C_CAN_CANSTAT.LEC Position              */
#define C_CAN_CANSTAT_LEC(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< C_CAN_CANSTAT.LEC Field                 */
#define C_CAN_CANSTAT_TXOK_MASK                  (0x8U)                                              /*!< C_CAN_CANSTAT.TXOK Mask                 */
#define C_CAN_CANSTAT_TXOK_SHIFT                 (3U)                                                /*!< C_CAN_CANSTAT.TXOK Position             */
#define C_CAN_CANSTAT_TXOK(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< C_CAN_CANSTAT.TXOK Field                */
#define C_CAN_CANSTAT_RXOK_MASK                  (0x10U)                                             /*!< C_CAN_CANSTAT.RXOK Mask                 */
#define C_CAN_CANSTAT_RXOK_SHIFT                 (4U)                                                /*!< C_CAN_CANSTAT.RXOK Position             */
#define C_CAN_CANSTAT_RXOK(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< C_CAN_CANSTAT.RXOK Field                */
#define C_CAN_CANSTAT_EPASS_MASK                 (0x20U)                                             /*!< C_CAN_CANSTAT.EPASS Mask                */
#define C_CAN_CANSTAT_EPASS_SHIFT                (5U)                                                /*!< C_CAN_CANSTAT.EPASS Position            */
#define C_CAN_CANSTAT_EPASS(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< C_CAN_CANSTAT.EPASS Field               */
#define C_CAN_CANSTAT_EWARN_MASK                 (0x40U)                                             /*!< C_CAN_CANSTAT.EWARN Mask                */
#define C_CAN_CANSTAT_EWARN_SHIFT                (6U)                                                /*!< C_CAN_CANSTAT.EWARN Position            */
#define C_CAN_CANSTAT_EWARN(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< C_CAN_CANSTAT.EWARN Field               */
#define C_CAN_CANSTAT_BOFF_MASK                  (0x80U)                                             /*!< C_CAN_CANSTAT.BOFF Mask                 */
#define C_CAN_CANSTAT_BOFF_SHIFT                 (7U)                                                /*!< C_CAN_CANSTAT.BOFF Position             */
#define C_CAN_CANSTAT_BOFF(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANSTAT.BOFF Field                */
/* ------- CANEC Bit Fields                         ------ */
#define C_CAN_CANEC_TEC_7_0_MASK                 (0xFFU)                                             /*!< C_CAN_CANEC.TEC_7_0 Mask                */
#define C_CAN_CANEC_TEC_7_0_SHIFT                (0U)                                                /*!< C_CAN_CANEC.TEC_7_0 Position            */
#define C_CAN_CANEC_TEC_7_0(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANEC.TEC_7_0 Field               */
#define C_CAN_CANEC_REC_6_0_MASK                 (0x7F00U)                                           /*!< C_CAN_CANEC.REC_6_0 Mask                */
#define C_CAN_CANEC_REC_6_0_SHIFT                (8U)                                                /*!< C_CAN_CANEC.REC_6_0 Position            */
#define C_CAN_CANEC_REC_6_0(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x7F00UL)        /*!< C_CAN_CANEC.REC_6_0 Field               */
#define C_CAN_CANEC_RP_MASK                      (0x8000U)                                           /*!< C_CAN_CANEC.RP Mask                     */
#define C_CAN_CANEC_RP_SHIFT                     (15U)                                               /*!< C_CAN_CANEC.RP Position                 */
#define C_CAN_CANEC_RP(x)                        (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANEC.RP Field                    */
/* ------- CANBT Bit Fields                         ------ */
#define C_CAN_CANBT_BRP_MASK                     (0x3FU)                                             /*!< C_CAN_CANBT.BRP Mask                    */
#define C_CAN_CANBT_BRP_SHIFT                    (0U)                                                /*!< C_CAN_CANBT.BRP Position                */
#define C_CAN_CANBT_BRP(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< C_CAN_CANBT.BRP Field                   */
#define C_CAN_CANBT_SJW_MASK                     (0xC0U)                                             /*!< C_CAN_CANBT.SJW Mask                    */
#define C_CAN_CANBT_SJW_SHIFT                    (6U)                                                /*!< C_CAN_CANBT.SJW Position                */
#define C_CAN_CANBT_SJW(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< C_CAN_CANBT.SJW Field                   */
#define C_CAN_CANBT_TSEG1_MASK                   (0xF00U)                                            /*!< C_CAN_CANBT.TSEG1 Mask                  */
#define C_CAN_CANBT_TSEG1_SHIFT                  (8U)                                                /*!< C_CAN_CANBT.TSEG1 Position              */
#define C_CAN_CANBT_TSEG1(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< C_CAN_CANBT.TSEG1 Field                 */
#define C_CAN_CANBT_TSEG2_MASK                   (0x7000U)                                           /*!< C_CAN_CANBT.TSEG2 Mask                  */
#define C_CAN_CANBT_TSEG2_SHIFT                  (12U)                                               /*!< C_CAN_CANBT.TSEG2 Position              */
#define C_CAN_CANBT_TSEG2(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0x7000UL)       /*!< C_CAN_CANBT.TSEG2 Field                 */
/* ------- CANINT Bit Fields                        ------ */
#define C_CAN_CANINT_INTID_MASK                  (0xFFFFU)                                           /*!< C_CAN_CANINT.INTID Mask                 */
#define C_CAN_CANINT_INTID_SHIFT                 (0U)                                                /*!< C_CAN_CANINT.INTID Position             */
#define C_CAN_CANINT_INTID(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANINT.INTID Field                */
/* ------- CANTEST Bit Fields                       ------ */
#define C_CAN_CANTEST_BASIC_MASK                 (0x4U)                                              /*!< C_CAN_CANTEST.BASIC Mask                */
#define C_CAN_CANTEST_BASIC_SHIFT                (2U)                                                /*!< C_CAN_CANTEST.BASIC Position            */
#define C_CAN_CANTEST_BASIC(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< C_CAN_CANTEST.BASIC Field               */
#define C_CAN_CANTEST_SILENT_MASK                (0x8U)                                              /*!< C_CAN_CANTEST.SILENT Mask               */
#define C_CAN_CANTEST_SILENT_SHIFT               (3U)                                                /*!< C_CAN_CANTEST.SILENT Position           */
#define C_CAN_CANTEST_SILENT(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< C_CAN_CANTEST.SILENT Field              */
#define C_CAN_CANTEST_LBACK_MASK                 (0x10U)                                             /*!< C_CAN_CANTEST.LBACK Mask                */
#define C_CAN_CANTEST_LBACK_SHIFT                (4U)                                                /*!< C_CAN_CANTEST.LBACK Position            */
#define C_CAN_CANTEST_LBACK(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< C_CAN_CANTEST.LBACK Field               */
#define C_CAN_CANTEST_TX_MASK                    (0x60U)                                             /*!< C_CAN_CANTEST.TX Mask                   */
#define C_CAN_CANTEST_TX_SHIFT                   (5U)                                                /*!< C_CAN_CANTEST.TX Position               */
#define C_CAN_CANTEST_TX(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x60UL)          /*!< C_CAN_CANTEST.TX Field                  */
#define C_CAN_CANTEST_RX_MASK                    (0x80U)                                             /*!< C_CAN_CANTEST.RX Mask                   */
#define C_CAN_CANTEST_RX_SHIFT                   (7U)                                                /*!< C_CAN_CANTEST.RX Position               */
#define C_CAN_CANTEST_RX(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANTEST.RX Field                  */
/* ------- CANBRPE Bit Fields                       ------ */
#define C_CAN_CANBRPE_BRPE_MASK                  (0xFU)                                              /*!< C_CAN_CANBRPE.BRPE Mask                 */
#define C_CAN_CANBRPE_BRPE_SHIFT                 (0U)                                                /*!< C_CAN_CANBRPE.BRPE Position             */
#define C_CAN_CANBRPE_BRPE(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< C_CAN_CANBRPE.BRPE Field                */
/* ------- CANIF1_CMDREQ Bit Fields                 ------ */
#define C_CAN_CANIF1_CMDREQ_MN_MASK              (0x3FU)                                             /*!< C_CAN_CANIF1_CMDREQ.MN Mask             */
#define C_CAN_CANIF1_CMDREQ_MN_SHIFT             (0U)                                                /*!< C_CAN_CANIF1_CMDREQ.MN Position         */
#define C_CAN_CANIF1_CMDREQ_MN(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< C_CAN_CANIF1_CMDREQ.MN Field            */
#define C_CAN_CANIF1_CMDREQ_BUSY_MASK            (0x8000U)                                           /*!< C_CAN_CANIF1_CMDREQ.BUSY Mask           */
#define C_CAN_CANIF1_CMDREQ_BUSY_SHIFT           (15U)                                               /*!< C_CAN_CANIF1_CMDREQ.BUSY Position       */
#define C_CAN_CANIF1_CMDREQ_BUSY(x)              (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANIF1_CMDREQ.BUSY Field          */
/* ------- CANIF1_CMDMSK_R Bit Fields               ------ */
#define C_CAN_CANIF1_CMDMSK_R_DATA_B_MASK        (0x1U)                                              /*!< C_CAN_CANIF1_CMDMSK_R.DATA_B Mask       */
#define C_CAN_CANIF1_CMDMSK_R_DATA_B_SHIFT       (0U)                                                /*!< C_CAN_CANIF1_CMDMSK_R.DATA_B Position   */
#define C_CAN_CANIF1_CMDMSK_R_DATA_B(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< C_CAN_CANIF1_CMDMSK_R.DATA_B Field      */
#define C_CAN_CANIF1_CMDMSK_R_DATA_A_MASK        (0x2U)                                              /*!< C_CAN_CANIF1_CMDMSK_R.DATA_A Mask       */
#define C_CAN_CANIF1_CMDMSK_R_DATA_A_SHIFT       (1U)                                                /*!< C_CAN_CANIF1_CMDMSK_R.DATA_A Position   */
#define C_CAN_CANIF1_CMDMSK_R_DATA_A(x)          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< C_CAN_CANIF1_CMDMSK_R.DATA_A Field      */
#define C_CAN_CANIF1_CMDMSK_R_NEWDAT_MASK        (0x4U)                                              /*!< C_CAN_CANIF1_CMDMSK_R.NEWDAT Mask       */
#define C_CAN_CANIF1_CMDMSK_R_NEWDAT_SHIFT       (2U)                                                /*!< C_CAN_CANIF1_CMDMSK_R.NEWDAT Position   */
#define C_CAN_CANIF1_CMDMSK_R_NEWDAT(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< C_CAN_CANIF1_CMDMSK_R.NEWDAT Field      */
#define C_CAN_CANIF1_CMDMSK_R_CLRINTPND_MASK     (0x8U)                                              /*!< C_CAN_CANIF1_CMDMSK_R.CLRINTPND Mask    */
#define C_CAN_CANIF1_CMDMSK_R_CLRINTPND_SHIFT    (3U)                                                /*!< C_CAN_CANIF1_CMDMSK_R.CLRINTPND Position*/
#define C_CAN_CANIF1_CMDMSK_R_CLRINTPND(x)       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< C_CAN_CANIF1_CMDMSK_R.CLRINTPND Field   */
#define C_CAN_CANIF1_CMDMSK_R_CTRL_MASK          (0x10U)                                             /*!< C_CAN_CANIF1_CMDMSK_R.CTRL Mask         */
#define C_CAN_CANIF1_CMDMSK_R_CTRL_SHIFT         (4U)                                                /*!< C_CAN_CANIF1_CMDMSK_R.CTRL Position     */
#define C_CAN_CANIF1_CMDMSK_R_CTRL(x)            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< C_CAN_CANIF1_CMDMSK_R.CTRL Field        */
#define C_CAN_CANIF1_CMDMSK_R_ARB_MASK           (0x20U)                                             /*!< C_CAN_CANIF1_CMDMSK_R.ARB Mask          */
#define C_CAN_CANIF1_CMDMSK_R_ARB_SHIFT          (5U)                                                /*!< C_CAN_CANIF1_CMDMSK_R.ARB Position      */
#define C_CAN_CANIF1_CMDMSK_R_ARB(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< C_CAN_CANIF1_CMDMSK_R.ARB Field         */
#define C_CAN_CANIF1_CMDMSK_R_MASK_MASK          (0x40U)                                             /*!< C_CAN_CANIF1_CMDMSK_R.MASK Mask         */
#define C_CAN_CANIF1_CMDMSK_R_MASK_SHIFT         (6U)                                                /*!< C_CAN_CANIF1_CMDMSK_R.MASK Position     */
#define C_CAN_CANIF1_CMDMSK_R_MASK(x)            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< C_CAN_CANIF1_CMDMSK_R.MASK Field        */
#define C_CAN_CANIF1_CMDMSK_R_WR_RD_MASK         (0x80U)                                             /*!< C_CAN_CANIF1_CMDMSK_R.WR_RD Mask        */
#define C_CAN_CANIF1_CMDMSK_R_WR_RD_SHIFT        (7U)                                                /*!< C_CAN_CANIF1_CMDMSK_R.WR_RD Position    */
#define C_CAN_CANIF1_CMDMSK_R_WR_RD(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANIF1_CMDMSK_R.WR_RD Field       */
/* ------- CANIF1_CMDMSK_W Bit Fields               ------ */
#define C_CAN_CANIF1_CMDMSK_W_DATA_B_MASK        (0x1U)                                              /*!< C_CAN_CANIF1_CMDMSK_W.DATA_B Mask       */
#define C_CAN_CANIF1_CMDMSK_W_DATA_B_SHIFT       (0U)                                                /*!< C_CAN_CANIF1_CMDMSK_W.DATA_B Position   */
#define C_CAN_CANIF1_CMDMSK_W_DATA_B(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< C_CAN_CANIF1_CMDMSK_W.DATA_B Field      */
#define C_CAN_CANIF1_CMDMSK_W_DATA_A_MASK        (0x2U)                                              /*!< C_CAN_CANIF1_CMDMSK_W.DATA_A Mask       */
#define C_CAN_CANIF1_CMDMSK_W_DATA_A_SHIFT       (1U)                                                /*!< C_CAN_CANIF1_CMDMSK_W.DATA_A Position   */
#define C_CAN_CANIF1_CMDMSK_W_DATA_A(x)          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< C_CAN_CANIF1_CMDMSK_W.DATA_A Field      */
#define C_CAN_CANIF1_CMDMSK_W_TXRQST_MASK        (0x4U)                                              /*!< C_CAN_CANIF1_CMDMSK_W.TXRQST Mask       */
#define C_CAN_CANIF1_CMDMSK_W_TXRQST_SHIFT       (2U)                                                /*!< C_CAN_CANIF1_CMDMSK_W.TXRQST Position   */
#define C_CAN_CANIF1_CMDMSK_W_TXRQST(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< C_CAN_CANIF1_CMDMSK_W.TXRQST Field      */
#define C_CAN_CANIF1_CMDMSK_W_CLRINTPND_MASK     (0x8U)                                              /*!< C_CAN_CANIF1_CMDMSK_W.CLRINTPND Mask    */
#define C_CAN_CANIF1_CMDMSK_W_CLRINTPND_SHIFT    (3U)                                                /*!< C_CAN_CANIF1_CMDMSK_W.CLRINTPND Position*/
#define C_CAN_CANIF1_CMDMSK_W_CLRINTPND(x)       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< C_CAN_CANIF1_CMDMSK_W.CLRINTPND Field   */
#define C_CAN_CANIF1_CMDMSK_W_CTRL_MASK          (0x10U)                                             /*!< C_CAN_CANIF1_CMDMSK_W.CTRL Mask         */
#define C_CAN_CANIF1_CMDMSK_W_CTRL_SHIFT         (4U)                                                /*!< C_CAN_CANIF1_CMDMSK_W.CTRL Position     */
#define C_CAN_CANIF1_CMDMSK_W_CTRL(x)            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< C_CAN_CANIF1_CMDMSK_W.CTRL Field        */
#define C_CAN_CANIF1_CMDMSK_W_ARB_MASK           (0x20U)                                             /*!< C_CAN_CANIF1_CMDMSK_W.ARB Mask          */
#define C_CAN_CANIF1_CMDMSK_W_ARB_SHIFT          (5U)                                                /*!< C_CAN_CANIF1_CMDMSK_W.ARB Position      */
#define C_CAN_CANIF1_CMDMSK_W_ARB(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< C_CAN_CANIF1_CMDMSK_W.ARB Field         */
#define C_CAN_CANIF1_CMDMSK_W_MASK_MASK          (0x40U)                                             /*!< C_CAN_CANIF1_CMDMSK_W.MASK Mask         */
#define C_CAN_CANIF1_CMDMSK_W_MASK_SHIFT         (6U)                                                /*!< C_CAN_CANIF1_CMDMSK_W.MASK Position     */
#define C_CAN_CANIF1_CMDMSK_W_MASK(x)            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< C_CAN_CANIF1_CMDMSK_W.MASK Field        */
#define C_CAN_CANIF1_CMDMSK_W_WR_RD_MASK         (0x80U)                                             /*!< C_CAN_CANIF1_CMDMSK_W.WR_RD Mask        */
#define C_CAN_CANIF1_CMDMSK_W_WR_RD_SHIFT        (7U)                                                /*!< C_CAN_CANIF1_CMDMSK_W.WR_RD Position    */
#define C_CAN_CANIF1_CMDMSK_W_WR_RD(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANIF1_CMDMSK_W.WR_RD Field       */
/* ------- CANIF1_MSK1 Bit Fields                   ------ */
#define C_CAN_CANIF1_MSK1_MSK_15_0_MASK          (0xFFFFU)                                           /*!< C_CAN_CANIF1_MSK1.MSK_15_0 Mask         */
#define C_CAN_CANIF1_MSK1_MSK_15_0_SHIFT         (0U)                                                /*!< C_CAN_CANIF1_MSK1.MSK_15_0 Position     */
#define C_CAN_CANIF1_MSK1_MSK_15_0(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANIF1_MSK1.MSK_15_0 Field        */
/* ------- CANIF1_MSK2 Bit Fields                   ------ */
#define C_CAN_CANIF1_MSK2_MSK_28_16_MASK         (0x1FFFU)                                           /*!< C_CAN_CANIF1_MSK2.MSK_28_16 Mask        */
#define C_CAN_CANIF1_MSK2_MSK_28_16_SHIFT        (0U)                                                /*!< C_CAN_CANIF1_MSK2.MSK_28_16 Position    */
#define C_CAN_CANIF1_MSK2_MSK_28_16(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFUL)        /*!< C_CAN_CANIF1_MSK2.MSK_28_16 Field       */
#define C_CAN_CANIF1_MSK2_MDIR_MASK              (0x4000U)                                           /*!< C_CAN_CANIF1_MSK2.MDIR Mask             */
#define C_CAN_CANIF1_MSK2_MDIR_SHIFT             (14U)                                               /*!< C_CAN_CANIF1_MSK2.MDIR Position         */
#define C_CAN_CANIF1_MSK2_MDIR(x)                (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< C_CAN_CANIF1_MSK2.MDIR Field            */
#define C_CAN_CANIF1_MSK2_MXTD_MASK              (0x8000U)                                           /*!< C_CAN_CANIF1_MSK2.MXTD Mask             */
#define C_CAN_CANIF1_MSK2_MXTD_SHIFT             (15U)                                               /*!< C_CAN_CANIF1_MSK2.MXTD Position         */
#define C_CAN_CANIF1_MSK2_MXTD(x)                (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANIF1_MSK2.MXTD Field            */
/* ------- CANIF1_ARB1 Bit Fields                   ------ */
#define C_CAN_CANIF1_ARB1_ID_15_0_MASK           (0xFFFFU)                                           /*!< C_CAN_CANIF1_ARB1.ID_15_0 Mask          */
#define C_CAN_CANIF1_ARB1_ID_15_0_SHIFT          (0U)                                                /*!< C_CAN_CANIF1_ARB1.ID_15_0 Position      */
#define C_CAN_CANIF1_ARB1_ID_15_0(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANIF1_ARB1.ID_15_0 Field         */
/* ------- CANIF1_ARB2 Bit Fields                   ------ */
#define C_CAN_CANIF1_ARB2_ID_28_16_MASK          (0x1FFFU)                                           /*!< C_CAN_CANIF1_ARB2.ID_28_16 Mask         */
#define C_CAN_CANIF1_ARB2_ID_28_16_SHIFT         (0U)                                                /*!< C_CAN_CANIF1_ARB2.ID_28_16 Position     */
#define C_CAN_CANIF1_ARB2_ID_28_16(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFUL)        /*!< C_CAN_CANIF1_ARB2.ID_28_16 Field        */
#define C_CAN_CANIF1_ARB2_DIR_MASK               (0x2000U)                                           /*!< C_CAN_CANIF1_ARB2.DIR Mask              */
#define C_CAN_CANIF1_ARB2_DIR_SHIFT              (13U)                                               /*!< C_CAN_CANIF1_ARB2.DIR Position          */
#define C_CAN_CANIF1_ARB2_DIR(x)                 (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< C_CAN_CANIF1_ARB2.DIR Field             */
#define C_CAN_CANIF1_ARB2_XTD_MASK               (0x4000U)                                           /*!< C_CAN_CANIF1_ARB2.XTD Mask              */
#define C_CAN_CANIF1_ARB2_XTD_SHIFT              (14U)                                               /*!< C_CAN_CANIF1_ARB2.XTD Position          */
#define C_CAN_CANIF1_ARB2_XTD(x)                 (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< C_CAN_CANIF1_ARB2.XTD Field             */
#define C_CAN_CANIF1_ARB2_MSGVAL_MASK            (0x8000U)                                           /*!< C_CAN_CANIF1_ARB2.MSGVAL Mask           */
#define C_CAN_CANIF1_ARB2_MSGVAL_SHIFT           (15U)                                               /*!< C_CAN_CANIF1_ARB2.MSGVAL Position       */
#define C_CAN_CANIF1_ARB2_MSGVAL(x)              (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANIF1_ARB2.MSGVAL Field          */
/* ------- CANIF1_MCTRL Bit Fields                  ------ */
#define C_CAN_CANIF1_MCTRL_DLC_3_0_MASK          (0xFU)                                              /*!< C_CAN_CANIF1_MCTRL.DLC_3_0 Mask         */
#define C_CAN_CANIF1_MCTRL_DLC_3_0_SHIFT         (0U)                                                /*!< C_CAN_CANIF1_MCTRL.DLC_3_0 Position     */
#define C_CAN_CANIF1_MCTRL_DLC_3_0(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< C_CAN_CANIF1_MCTRL.DLC_3_0 Field        */
#define C_CAN_CANIF1_MCTRL_EOB_MASK              (0x80U)                                             /*!< C_CAN_CANIF1_MCTRL.EOB Mask             */
#define C_CAN_CANIF1_MCTRL_EOB_SHIFT             (7U)                                                /*!< C_CAN_CANIF1_MCTRL.EOB Position         */
#define C_CAN_CANIF1_MCTRL_EOB(x)                (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANIF1_MCTRL.EOB Field            */
#define C_CAN_CANIF1_MCTRL_TXRQST_MASK           (0x100U)                                            /*!< C_CAN_CANIF1_MCTRL.TXRQST Mask          */
#define C_CAN_CANIF1_MCTRL_TXRQST_SHIFT          (8U)                                                /*!< C_CAN_CANIF1_MCTRL.TXRQST Position      */
#define C_CAN_CANIF1_MCTRL_TXRQST(x)             (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< C_CAN_CANIF1_MCTRL.TXRQST Field         */
#define C_CAN_CANIF1_MCTRL_RMTEN_MASK            (0x200U)                                            /*!< C_CAN_CANIF1_MCTRL.RMTEN Mask           */
#define C_CAN_CANIF1_MCTRL_RMTEN_SHIFT           (9U)                                                /*!< C_CAN_CANIF1_MCTRL.RMTEN Position       */
#define C_CAN_CANIF1_MCTRL_RMTEN(x)              (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< C_CAN_CANIF1_MCTRL.RMTEN Field          */
#define C_CAN_CANIF1_MCTRL_RXIE_MASK             (0x400U)                                            /*!< C_CAN_CANIF1_MCTRL.RXIE Mask            */
#define C_CAN_CANIF1_MCTRL_RXIE_SHIFT            (10U)                                               /*!< C_CAN_CANIF1_MCTRL.RXIE Position        */
#define C_CAN_CANIF1_MCTRL_RXIE(x)               (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< C_CAN_CANIF1_MCTRL.RXIE Field           */
#define C_CAN_CANIF1_MCTRL_TXIE_MASK             (0x800U)                                            /*!< C_CAN_CANIF1_MCTRL.TXIE Mask            */
#define C_CAN_CANIF1_MCTRL_TXIE_SHIFT            (11U)                                               /*!< C_CAN_CANIF1_MCTRL.TXIE Position        */
#define C_CAN_CANIF1_MCTRL_TXIE(x)               (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< C_CAN_CANIF1_MCTRL.TXIE Field           */
#define C_CAN_CANIF1_MCTRL_UMASK_MASK            (0x1000U)                                           /*!< C_CAN_CANIF1_MCTRL.UMASK Mask           */
#define C_CAN_CANIF1_MCTRL_UMASK_SHIFT           (12U)                                               /*!< C_CAN_CANIF1_MCTRL.UMASK Position       */
#define C_CAN_CANIF1_MCTRL_UMASK(x)              (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< C_CAN_CANIF1_MCTRL.UMASK Field          */
#define C_CAN_CANIF1_MCTRL_INTPND_MASK           (0x2000U)                                           /*!< C_CAN_CANIF1_MCTRL.INTPND Mask          */
#define C_CAN_CANIF1_MCTRL_INTPND_SHIFT          (13U)                                               /*!< C_CAN_CANIF1_MCTRL.INTPND Position      */
#define C_CAN_CANIF1_MCTRL_INTPND(x)             (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< C_CAN_CANIF1_MCTRL.INTPND Field         */
#define C_CAN_CANIF1_MCTRL_MSGLST_MASK           (0x4000U)                                           /*!< C_CAN_CANIF1_MCTRL.MSGLST Mask          */
#define C_CAN_CANIF1_MCTRL_MSGLST_SHIFT          (14U)                                               /*!< C_CAN_CANIF1_MCTRL.MSGLST Position      */
#define C_CAN_CANIF1_MCTRL_MSGLST(x)             (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< C_CAN_CANIF1_MCTRL.MSGLST Field         */
#define C_CAN_CANIF1_MCTRL_NEWDAT_MASK           (0x8000U)                                           /*!< C_CAN_CANIF1_MCTRL.NEWDAT Mask          */
#define C_CAN_CANIF1_MCTRL_NEWDAT_SHIFT          (15U)                                               /*!< C_CAN_CANIF1_MCTRL.NEWDAT Position      */
#define C_CAN_CANIF1_MCTRL_NEWDAT(x)             (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANIF1_MCTRL.NEWDAT Field         */
/* ------- CANIF1_DA1 Bit Fields                    ------ */
#define C_CAN_CANIF1_DA1_DATA0_MASK              (0xFFU)                                             /*!< C_CAN_CANIF1_DA1.DATA0 Mask             */
#define C_CAN_CANIF1_DA1_DATA0_SHIFT             (0U)                                                /*!< C_CAN_CANIF1_DA1.DATA0 Position         */
#define C_CAN_CANIF1_DA1_DATA0(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANIF1_DA1.DATA0 Field            */
#define C_CAN_CANIF1_DA1_DATA1_MASK              (0xFF00U)                                           /*!< C_CAN_CANIF1_DA1.DATA1 Mask             */
#define C_CAN_CANIF1_DA1_DATA1_SHIFT             (8U)                                                /*!< C_CAN_CANIF1_DA1.DATA1 Position         */
#define C_CAN_CANIF1_DA1_DATA1(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< C_CAN_CANIF1_DA1.DATA1 Field            */
/* ------- CANIF1_DA2 Bit Fields                    ------ */
#define C_CAN_CANIF1_DA2_DATA2_MASK              (0xFFU)                                             /*!< C_CAN_CANIF1_DA2.DATA2 Mask             */
#define C_CAN_CANIF1_DA2_DATA2_SHIFT             (0U)                                                /*!< C_CAN_CANIF1_DA2.DATA2 Position         */
#define C_CAN_CANIF1_DA2_DATA2(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANIF1_DA2.DATA2 Field            */
#define C_CAN_CANIF1_DA2_DATA3_MASK              (0xFF00U)                                           /*!< C_CAN_CANIF1_DA2.DATA3 Mask             */
#define C_CAN_CANIF1_DA2_DATA3_SHIFT             (8U)                                                /*!< C_CAN_CANIF1_DA2.DATA3 Position         */
#define C_CAN_CANIF1_DA2_DATA3(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< C_CAN_CANIF1_DA2.DATA3 Field            */
/* ------- CANIF1_DB1 Bit Fields                    ------ */
#define C_CAN_CANIF1_DB1_DATA4_MASK              (0xFFU)                                             /*!< C_CAN_CANIF1_DB1.DATA4 Mask             */
#define C_CAN_CANIF1_DB1_DATA4_SHIFT             (0U)                                                /*!< C_CAN_CANIF1_DB1.DATA4 Position         */
#define C_CAN_CANIF1_DB1_DATA4(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANIF1_DB1.DATA4 Field            */
#define C_CAN_CANIF1_DB1_DATA5_MASK              (0xFF00U)                                           /*!< C_CAN_CANIF1_DB1.DATA5 Mask             */
#define C_CAN_CANIF1_DB1_DATA5_SHIFT             (8U)                                                /*!< C_CAN_CANIF1_DB1.DATA5 Position         */
#define C_CAN_CANIF1_DB1_DATA5(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< C_CAN_CANIF1_DB1.DATA5 Field            */
/* ------- CANIF1_DB2 Bit Fields                    ------ */
#define C_CAN_CANIF1_DB2_DATA6_MASK              (0xFFU)                                             /*!< C_CAN_CANIF1_DB2.DATA6 Mask             */
#define C_CAN_CANIF1_DB2_DATA6_SHIFT             (0U)                                                /*!< C_CAN_CANIF1_DB2.DATA6 Position         */
#define C_CAN_CANIF1_DB2_DATA6(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANIF1_DB2.DATA6 Field            */
#define C_CAN_CANIF1_DB2_DATA7_MASK              (0xFF00U)                                           /*!< C_CAN_CANIF1_DB2.DATA7 Mask             */
#define C_CAN_CANIF1_DB2_DATA7_SHIFT             (8U)                                                /*!< C_CAN_CANIF1_DB2.DATA7 Position         */
#define C_CAN_CANIF1_DB2_DATA7(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< C_CAN_CANIF1_DB2.DATA7 Field            */
/* ------- CANIF2_CMDREQ Bit Fields                 ------ */
#define C_CAN_CANIF2_CMDREQ_MN_MASK              (0x3FU)                                             /*!< C_CAN_CANIF2_CMDREQ.MN Mask             */
#define C_CAN_CANIF2_CMDREQ_MN_SHIFT             (0U)                                                /*!< C_CAN_CANIF2_CMDREQ.MN Position         */
#define C_CAN_CANIF2_CMDREQ_MN(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< C_CAN_CANIF2_CMDREQ.MN Field            */
#define C_CAN_CANIF2_CMDREQ_BUSY_MASK            (0x8000U)                                           /*!< C_CAN_CANIF2_CMDREQ.BUSY Mask           */
#define C_CAN_CANIF2_CMDREQ_BUSY_SHIFT           (15U)                                               /*!< C_CAN_CANIF2_CMDREQ.BUSY Position       */
#define C_CAN_CANIF2_CMDREQ_BUSY(x)              (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANIF2_CMDREQ.BUSY Field          */
/* ------- CANIF2_CMDMSK_R Bit Fields               ------ */
#define C_CAN_CANIF2_CMDMSK_R_DATA_B_MASK        (0x1U)                                              /*!< C_CAN_CANIF2_CMDMSK_R.DATA_B Mask       */
#define C_CAN_CANIF2_CMDMSK_R_DATA_B_SHIFT       (0U)                                                /*!< C_CAN_CANIF2_CMDMSK_R.DATA_B Position   */
#define C_CAN_CANIF2_CMDMSK_R_DATA_B(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< C_CAN_CANIF2_CMDMSK_R.DATA_B Field      */
#define C_CAN_CANIF2_CMDMSK_R_DATA_A_MASK        (0x2U)                                              /*!< C_CAN_CANIF2_CMDMSK_R.DATA_A Mask       */
#define C_CAN_CANIF2_CMDMSK_R_DATA_A_SHIFT       (1U)                                                /*!< C_CAN_CANIF2_CMDMSK_R.DATA_A Position   */
#define C_CAN_CANIF2_CMDMSK_R_DATA_A(x)          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< C_CAN_CANIF2_CMDMSK_R.DATA_A Field      */
#define C_CAN_CANIF2_CMDMSK_R_NEWDAT_MASK        (0x4U)                                              /*!< C_CAN_CANIF2_CMDMSK_R.NEWDAT Mask       */
#define C_CAN_CANIF2_CMDMSK_R_NEWDAT_SHIFT       (2U)                                                /*!< C_CAN_CANIF2_CMDMSK_R.NEWDAT Position   */
#define C_CAN_CANIF2_CMDMSK_R_NEWDAT(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< C_CAN_CANIF2_CMDMSK_R.NEWDAT Field      */
#define C_CAN_CANIF2_CMDMSK_R_CLRINTPND_MASK     (0x8U)                                              /*!< C_CAN_CANIF2_CMDMSK_R.CLRINTPND Mask    */
#define C_CAN_CANIF2_CMDMSK_R_CLRINTPND_SHIFT    (3U)                                                /*!< C_CAN_CANIF2_CMDMSK_R.CLRINTPND Position*/
#define C_CAN_CANIF2_CMDMSK_R_CLRINTPND(x)       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< C_CAN_CANIF2_CMDMSK_R.CLRINTPND Field   */
#define C_CAN_CANIF2_CMDMSK_R_CTRL_MASK          (0x10U)                                             /*!< C_CAN_CANIF2_CMDMSK_R.CTRL Mask         */
#define C_CAN_CANIF2_CMDMSK_R_CTRL_SHIFT         (4U)                                                /*!< C_CAN_CANIF2_CMDMSK_R.CTRL Position     */
#define C_CAN_CANIF2_CMDMSK_R_CTRL(x)            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< C_CAN_CANIF2_CMDMSK_R.CTRL Field        */
#define C_CAN_CANIF2_CMDMSK_R_ARB_MASK           (0x20U)                                             /*!< C_CAN_CANIF2_CMDMSK_R.ARB Mask          */
#define C_CAN_CANIF2_CMDMSK_R_ARB_SHIFT          (5U)                                                /*!< C_CAN_CANIF2_CMDMSK_R.ARB Position      */
#define C_CAN_CANIF2_CMDMSK_R_ARB(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< C_CAN_CANIF2_CMDMSK_R.ARB Field         */
#define C_CAN_CANIF2_CMDMSK_R_MASK_MASK          (0x40U)                                             /*!< C_CAN_CANIF2_CMDMSK_R.MASK Mask         */
#define C_CAN_CANIF2_CMDMSK_R_MASK_SHIFT         (6U)                                                /*!< C_CAN_CANIF2_CMDMSK_R.MASK Position     */
#define C_CAN_CANIF2_CMDMSK_R_MASK(x)            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< C_CAN_CANIF2_CMDMSK_R.MASK Field        */
#define C_CAN_CANIF2_CMDMSK_R_WR_RD_MASK         (0x80U)                                             /*!< C_CAN_CANIF2_CMDMSK_R.WR_RD Mask        */
#define C_CAN_CANIF2_CMDMSK_R_WR_RD_SHIFT        (7U)                                                /*!< C_CAN_CANIF2_CMDMSK_R.WR_RD Position    */
#define C_CAN_CANIF2_CMDMSK_R_WR_RD(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANIF2_CMDMSK_R.WR_RD Field       */
/* ------- CANIF2_CMDMSK_W Bit Fields               ------ */
#define C_CAN_CANIF2_CMDMSK_W_DATA_B_MASK        (0x1U)                                              /*!< C_CAN_CANIF2_CMDMSK_W.DATA_B Mask       */
#define C_CAN_CANIF2_CMDMSK_W_DATA_B_SHIFT       (0U)                                                /*!< C_CAN_CANIF2_CMDMSK_W.DATA_B Position   */
#define C_CAN_CANIF2_CMDMSK_W_DATA_B(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< C_CAN_CANIF2_CMDMSK_W.DATA_B Field      */
#define C_CAN_CANIF2_CMDMSK_W_DATA_A_MASK        (0x2U)                                              /*!< C_CAN_CANIF2_CMDMSK_W.DATA_A Mask       */
#define C_CAN_CANIF2_CMDMSK_W_DATA_A_SHIFT       (1U)                                                /*!< C_CAN_CANIF2_CMDMSK_W.DATA_A Position   */
#define C_CAN_CANIF2_CMDMSK_W_DATA_A(x)          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< C_CAN_CANIF2_CMDMSK_W.DATA_A Field      */
#define C_CAN_CANIF2_CMDMSK_W_TXRQST_MASK        (0x4U)                                              /*!< C_CAN_CANIF2_CMDMSK_W.TXRQST Mask       */
#define C_CAN_CANIF2_CMDMSK_W_TXRQST_SHIFT       (2U)                                                /*!< C_CAN_CANIF2_CMDMSK_W.TXRQST Position   */
#define C_CAN_CANIF2_CMDMSK_W_TXRQST(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< C_CAN_CANIF2_CMDMSK_W.TXRQST Field      */
#define C_CAN_CANIF2_CMDMSK_W_CLRINTPND_MASK     (0x8U)                                              /*!< C_CAN_CANIF2_CMDMSK_W.CLRINTPND Mask    */
#define C_CAN_CANIF2_CMDMSK_W_CLRINTPND_SHIFT    (3U)                                                /*!< C_CAN_CANIF2_CMDMSK_W.CLRINTPND Position*/
#define C_CAN_CANIF2_CMDMSK_W_CLRINTPND(x)       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< C_CAN_CANIF2_CMDMSK_W.CLRINTPND Field   */
#define C_CAN_CANIF2_CMDMSK_W_CTRL_MASK          (0x10U)                                             /*!< C_CAN_CANIF2_CMDMSK_W.CTRL Mask         */
#define C_CAN_CANIF2_CMDMSK_W_CTRL_SHIFT         (4U)                                                /*!< C_CAN_CANIF2_CMDMSK_W.CTRL Position     */
#define C_CAN_CANIF2_CMDMSK_W_CTRL(x)            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< C_CAN_CANIF2_CMDMSK_W.CTRL Field        */
#define C_CAN_CANIF2_CMDMSK_W_ARB_MASK           (0x20U)                                             /*!< C_CAN_CANIF2_CMDMSK_W.ARB Mask          */
#define C_CAN_CANIF2_CMDMSK_W_ARB_SHIFT          (5U)                                                /*!< C_CAN_CANIF2_CMDMSK_W.ARB Position      */
#define C_CAN_CANIF2_CMDMSK_W_ARB(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< C_CAN_CANIF2_CMDMSK_W.ARB Field         */
#define C_CAN_CANIF2_CMDMSK_W_MASK_MASK          (0x40U)                                             /*!< C_CAN_CANIF2_CMDMSK_W.MASK Mask         */
#define C_CAN_CANIF2_CMDMSK_W_MASK_SHIFT         (6U)                                                /*!< C_CAN_CANIF2_CMDMSK_W.MASK Position     */
#define C_CAN_CANIF2_CMDMSK_W_MASK(x)            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< C_CAN_CANIF2_CMDMSK_W.MASK Field        */
#define C_CAN_CANIF2_CMDMSK_W_WR_RD_MASK         (0x80U)                                             /*!< C_CAN_CANIF2_CMDMSK_W.WR_RD Mask        */
#define C_CAN_CANIF2_CMDMSK_W_WR_RD_SHIFT        (7U)                                                /*!< C_CAN_CANIF2_CMDMSK_W.WR_RD Position    */
#define C_CAN_CANIF2_CMDMSK_W_WR_RD(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANIF2_CMDMSK_W.WR_RD Field       */
/* ------- CANIF2_MSK1 Bit Fields                   ------ */
#define C_CAN_CANIF2_MSK1_MSK_15_0_MASK          (0xFFFFU)                                           /*!< C_CAN_CANIF2_MSK1.MSK_15_0 Mask         */
#define C_CAN_CANIF2_MSK1_MSK_15_0_SHIFT         (0U)                                                /*!< C_CAN_CANIF2_MSK1.MSK_15_0 Position     */
#define C_CAN_CANIF2_MSK1_MSK_15_0(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANIF2_MSK1.MSK_15_0 Field        */
/* ------- CANIF2_MSK2 Bit Fields                   ------ */
#define C_CAN_CANIF2_MSK2_MSK_28_16_MASK         (0x1FFFU)                                           /*!< C_CAN_CANIF2_MSK2.MSK_28_16 Mask        */
#define C_CAN_CANIF2_MSK2_MSK_28_16_SHIFT        (0U)                                                /*!< C_CAN_CANIF2_MSK2.MSK_28_16 Position    */
#define C_CAN_CANIF2_MSK2_MSK_28_16(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFUL)        /*!< C_CAN_CANIF2_MSK2.MSK_28_16 Field       */
#define C_CAN_CANIF2_MSK2_MDIR_MASK              (0x4000U)                                           /*!< C_CAN_CANIF2_MSK2.MDIR Mask             */
#define C_CAN_CANIF2_MSK2_MDIR_SHIFT             (14U)                                               /*!< C_CAN_CANIF2_MSK2.MDIR Position         */
#define C_CAN_CANIF2_MSK2_MDIR(x)                (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< C_CAN_CANIF2_MSK2.MDIR Field            */
#define C_CAN_CANIF2_MSK2_MXTD_MASK              (0x8000U)                                           /*!< C_CAN_CANIF2_MSK2.MXTD Mask             */
#define C_CAN_CANIF2_MSK2_MXTD_SHIFT             (15U)                                               /*!< C_CAN_CANIF2_MSK2.MXTD Position         */
#define C_CAN_CANIF2_MSK2_MXTD(x)                (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANIF2_MSK2.MXTD Field            */
/* ------- CANIF2_ARB1 Bit Fields                   ------ */
#define C_CAN_CANIF2_ARB1_ID_15_0_MASK           (0xFFFFU)                                           /*!< C_CAN_CANIF2_ARB1.ID_15_0 Mask          */
#define C_CAN_CANIF2_ARB1_ID_15_0_SHIFT          (0U)                                                /*!< C_CAN_CANIF2_ARB1.ID_15_0 Position      */
#define C_CAN_CANIF2_ARB1_ID_15_0(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANIF2_ARB1.ID_15_0 Field         */
/* ------- CANIF2_ARB2 Bit Fields                   ------ */
#define C_CAN_CANIF2_ARB2_ID_28_16_MASK          (0x1FFFU)                                           /*!< C_CAN_CANIF2_ARB2.ID_28_16 Mask         */
#define C_CAN_CANIF2_ARB2_ID_28_16_SHIFT         (0U)                                                /*!< C_CAN_CANIF2_ARB2.ID_28_16 Position     */
#define C_CAN_CANIF2_ARB2_ID_28_16(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFUL)        /*!< C_CAN_CANIF2_ARB2.ID_28_16 Field        */
#define C_CAN_CANIF2_ARB2_DIR_MASK               (0x2000U)                                           /*!< C_CAN_CANIF2_ARB2.DIR Mask              */
#define C_CAN_CANIF2_ARB2_DIR_SHIFT              (13U)                                               /*!< C_CAN_CANIF2_ARB2.DIR Position          */
#define C_CAN_CANIF2_ARB2_DIR(x)                 (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< C_CAN_CANIF2_ARB2.DIR Field             */
#define C_CAN_CANIF2_ARB2_XTD_MASK               (0x4000U)                                           /*!< C_CAN_CANIF2_ARB2.XTD Mask              */
#define C_CAN_CANIF2_ARB2_XTD_SHIFT              (14U)                                               /*!< C_CAN_CANIF2_ARB2.XTD Position          */
#define C_CAN_CANIF2_ARB2_XTD(x)                 (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< C_CAN_CANIF2_ARB2.XTD Field             */
#define C_CAN_CANIF2_ARB2_MSGVAL_MASK            (0x8000U)                                           /*!< C_CAN_CANIF2_ARB2.MSGVAL Mask           */
#define C_CAN_CANIF2_ARB2_MSGVAL_SHIFT           (15U)                                               /*!< C_CAN_CANIF2_ARB2.MSGVAL Position       */
#define C_CAN_CANIF2_ARB2_MSGVAL(x)              (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANIF2_ARB2.MSGVAL Field          */
/* ------- CANIF2_MCTRL Bit Fields                  ------ */
#define C_CAN_CANIF2_MCTRL_DLC_3_0_MASK          (0xFU)                                              /*!< C_CAN_CANIF2_MCTRL.DLC_3_0 Mask         */
#define C_CAN_CANIF2_MCTRL_DLC_3_0_SHIFT         (0U)                                                /*!< C_CAN_CANIF2_MCTRL.DLC_3_0 Position     */
#define C_CAN_CANIF2_MCTRL_DLC_3_0(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< C_CAN_CANIF2_MCTRL.DLC_3_0 Field        */
#define C_CAN_CANIF2_MCTRL_EOB_MASK              (0x80U)                                             /*!< C_CAN_CANIF2_MCTRL.EOB Mask             */
#define C_CAN_CANIF2_MCTRL_EOB_SHIFT             (7U)                                                /*!< C_CAN_CANIF2_MCTRL.EOB Position         */
#define C_CAN_CANIF2_MCTRL_EOB(x)                (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< C_CAN_CANIF2_MCTRL.EOB Field            */
#define C_CAN_CANIF2_MCTRL_TXRQST_MASK           (0x100U)                                            /*!< C_CAN_CANIF2_MCTRL.TXRQST Mask          */
#define C_CAN_CANIF2_MCTRL_TXRQST_SHIFT          (8U)                                                /*!< C_CAN_CANIF2_MCTRL.TXRQST Position      */
#define C_CAN_CANIF2_MCTRL_TXRQST(x)             (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< C_CAN_CANIF2_MCTRL.TXRQST Field         */
#define C_CAN_CANIF2_MCTRL_RMTEN_MASK            (0x200U)                                            /*!< C_CAN_CANIF2_MCTRL.RMTEN Mask           */
#define C_CAN_CANIF2_MCTRL_RMTEN_SHIFT           (9U)                                                /*!< C_CAN_CANIF2_MCTRL.RMTEN Position       */
#define C_CAN_CANIF2_MCTRL_RMTEN(x)              (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< C_CAN_CANIF2_MCTRL.RMTEN Field          */
#define C_CAN_CANIF2_MCTRL_RXIE_MASK             (0x400U)                                            /*!< C_CAN_CANIF2_MCTRL.RXIE Mask            */
#define C_CAN_CANIF2_MCTRL_RXIE_SHIFT            (10U)                                               /*!< C_CAN_CANIF2_MCTRL.RXIE Position        */
#define C_CAN_CANIF2_MCTRL_RXIE(x)               (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< C_CAN_CANIF2_MCTRL.RXIE Field           */
#define C_CAN_CANIF2_MCTRL_TXIE_MASK             (0x800U)                                            /*!< C_CAN_CANIF2_MCTRL.TXIE Mask            */
#define C_CAN_CANIF2_MCTRL_TXIE_SHIFT            (11U)                                               /*!< C_CAN_CANIF2_MCTRL.TXIE Position        */
#define C_CAN_CANIF2_MCTRL_TXIE(x)               (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< C_CAN_CANIF2_MCTRL.TXIE Field           */
#define C_CAN_CANIF2_MCTRL_UMASK_MASK            (0x1000U)                                           /*!< C_CAN_CANIF2_MCTRL.UMASK Mask           */
#define C_CAN_CANIF2_MCTRL_UMASK_SHIFT           (12U)                                               /*!< C_CAN_CANIF2_MCTRL.UMASK Position       */
#define C_CAN_CANIF2_MCTRL_UMASK(x)              (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< C_CAN_CANIF2_MCTRL.UMASK Field          */
#define C_CAN_CANIF2_MCTRL_INTPND_MASK           (0x2000U)                                           /*!< C_CAN_CANIF2_MCTRL.INTPND Mask          */
#define C_CAN_CANIF2_MCTRL_INTPND_SHIFT          (13U)                                               /*!< C_CAN_CANIF2_MCTRL.INTPND Position      */
#define C_CAN_CANIF2_MCTRL_INTPND(x)             (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< C_CAN_CANIF2_MCTRL.INTPND Field         */
#define C_CAN_CANIF2_MCTRL_MSGLST_MASK           (0x4000U)                                           /*!< C_CAN_CANIF2_MCTRL.MSGLST Mask          */
#define C_CAN_CANIF2_MCTRL_MSGLST_SHIFT          (14U)                                               /*!< C_CAN_CANIF2_MCTRL.MSGLST Position      */
#define C_CAN_CANIF2_MCTRL_MSGLST(x)             (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< C_CAN_CANIF2_MCTRL.MSGLST Field         */
#define C_CAN_CANIF2_MCTRL_NEWDAT_MASK           (0x8000U)                                           /*!< C_CAN_CANIF2_MCTRL.NEWDAT Mask          */
#define C_CAN_CANIF2_MCTRL_NEWDAT_SHIFT          (15U)                                               /*!< C_CAN_CANIF2_MCTRL.NEWDAT Position      */
#define C_CAN_CANIF2_MCTRL_NEWDAT(x)             (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< C_CAN_CANIF2_MCTRL.NEWDAT Field         */
/* ------- CANIF2_DA1 Bit Fields                    ------ */
#define C_CAN_CANIF2_DA1_DATA0_MASK              (0xFFU)                                             /*!< C_CAN_CANIF2_DA1.DATA0 Mask             */
#define C_CAN_CANIF2_DA1_DATA0_SHIFT             (0U)                                                /*!< C_CAN_CANIF2_DA1.DATA0 Position         */
#define C_CAN_CANIF2_DA1_DATA0(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANIF2_DA1.DATA0 Field            */
#define C_CAN_CANIF2_DA1_DATA1_MASK              (0xFF00U)                                           /*!< C_CAN_CANIF2_DA1.DATA1 Mask             */
#define C_CAN_CANIF2_DA1_DATA1_SHIFT             (8U)                                                /*!< C_CAN_CANIF2_DA1.DATA1 Position         */
#define C_CAN_CANIF2_DA1_DATA1(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< C_CAN_CANIF2_DA1.DATA1 Field            */
/* ------- CANIF2_DA2 Bit Fields                    ------ */
#define C_CAN_CANIF2_DA2_DATA2_MASK              (0xFFU)                                             /*!< C_CAN_CANIF2_DA2.DATA2 Mask             */
#define C_CAN_CANIF2_DA2_DATA2_SHIFT             (0U)                                                /*!< C_CAN_CANIF2_DA2.DATA2 Position         */
#define C_CAN_CANIF2_DA2_DATA2(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANIF2_DA2.DATA2 Field            */
#define C_CAN_CANIF2_DA2_DATA3_MASK              (0xFF00U)                                           /*!< C_CAN_CANIF2_DA2.DATA3 Mask             */
#define C_CAN_CANIF2_DA2_DATA3_SHIFT             (8U)                                                /*!< C_CAN_CANIF2_DA2.DATA3 Position         */
#define C_CAN_CANIF2_DA2_DATA3(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< C_CAN_CANIF2_DA2.DATA3 Field            */
/* ------- CANIF2_DB1 Bit Fields                    ------ */
#define C_CAN_CANIF2_DB1_DATA4_MASK              (0xFFU)                                             /*!< C_CAN_CANIF2_DB1.DATA4 Mask             */
#define C_CAN_CANIF2_DB1_DATA4_SHIFT             (0U)                                                /*!< C_CAN_CANIF2_DB1.DATA4 Position         */
#define C_CAN_CANIF2_DB1_DATA4(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANIF2_DB1.DATA4 Field            */
#define C_CAN_CANIF2_DB1_DATA5_MASK              (0xFF00U)                                           /*!< C_CAN_CANIF2_DB1.DATA5 Mask             */
#define C_CAN_CANIF2_DB1_DATA5_SHIFT             (8U)                                                /*!< C_CAN_CANIF2_DB1.DATA5 Position         */
#define C_CAN_CANIF2_DB1_DATA5(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< C_CAN_CANIF2_DB1.DATA5 Field            */
/* ------- CANIF2_DB2 Bit Fields                    ------ */
#define C_CAN_CANIF2_DB2_DATA6_MASK              (0xFFU)                                             /*!< C_CAN_CANIF2_DB2.DATA6 Mask             */
#define C_CAN_CANIF2_DB2_DATA6_SHIFT             (0U)                                                /*!< C_CAN_CANIF2_DB2.DATA6 Position         */
#define C_CAN_CANIF2_DB2_DATA6(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< C_CAN_CANIF2_DB2.DATA6 Field            */
#define C_CAN_CANIF2_DB2_DATA7_MASK              (0xFF00U)                                           /*!< C_CAN_CANIF2_DB2.DATA7 Mask             */
#define C_CAN_CANIF2_DB2_DATA7_SHIFT             (8U)                                                /*!< C_CAN_CANIF2_DB2.DATA7 Position         */
#define C_CAN_CANIF2_DB2_DATA7(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< C_CAN_CANIF2_DB2.DATA7 Field            */
/* ------- CANTXREQ1 Bit Fields                     ------ */
#define C_CAN_CANTXREQ1_TXRQST_16_1_MASK         (0xFFFFU)                                           /*!< C_CAN_CANTXREQ1.TXRQST_16_1 Mask        */
#define C_CAN_CANTXREQ1_TXRQST_16_1_SHIFT        (0U)                                                /*!< C_CAN_CANTXREQ1.TXRQST_16_1 Position    */
#define C_CAN_CANTXREQ1_TXRQST_16_1(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANTXREQ1.TXRQST_16_1 Field       */
/* ------- CANTXREQ2 Bit Fields                     ------ */
#define C_CAN_CANTXREQ2_TXRQST_32_17_MASK        (0xFFFFU)                                           /*!< C_CAN_CANTXREQ2.TXRQST_32_17 Mask       */
#define C_CAN_CANTXREQ2_TXRQST_32_17_SHIFT       (0U)                                                /*!< C_CAN_CANTXREQ2.TXRQST_32_17 Position   */
#define C_CAN_CANTXREQ2_TXRQST_32_17(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANTXREQ2.TXRQST_32_17 Field      */
/* ------- CANND1 Bit Fields                        ------ */
#define C_CAN_CANND1_NEWDAT_16_1_MASK            (0xFFFFU)                                           /*!< C_CAN_CANND1.NEWDAT_16_1 Mask           */
#define C_CAN_CANND1_NEWDAT_16_1_SHIFT           (0U)                                                /*!< C_CAN_CANND1.NEWDAT_16_1 Position       */
#define C_CAN_CANND1_NEWDAT_16_1(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANND1.NEWDAT_16_1 Field          */
/* ------- CANND2 Bit Fields                        ------ */
#define C_CAN_CANND2_NEWDAT_32_17_MASK           (0xFFFFU)                                           /*!< C_CAN_CANND2.NEWDAT_32_17 Mask          */
#define C_CAN_CANND2_NEWDAT_32_17_SHIFT          (0U)                                                /*!< C_CAN_CANND2.NEWDAT_32_17 Position      */
#define C_CAN_CANND2_NEWDAT_32_17(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANND2.NEWDAT_32_17 Field         */
/* ------- CANIR1 Bit Fields                        ------ */
#define C_CAN_CANIR1_INTPND_16_1_MASK            (0xFFFFU)                                           /*!< C_CAN_CANIR1.INTPND_16_1 Mask           */
#define C_CAN_CANIR1_INTPND_16_1_SHIFT           (0U)                                                /*!< C_CAN_CANIR1.INTPND_16_1 Position       */
#define C_CAN_CANIR1_INTPND_16_1(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANIR1.INTPND_16_1 Field          */
/* ------- CANIR2 Bit Fields                        ------ */
#define C_CAN_CANIR2_INTPND_32_17_MASK           (0xFFFFU)                                           /*!< C_CAN_CANIR2.INTPND_32_17 Mask          */
#define C_CAN_CANIR2_INTPND_32_17_SHIFT          (0U)                                                /*!< C_CAN_CANIR2.INTPND_32_17 Position      */
#define C_CAN_CANIR2_INTPND_32_17(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANIR2.INTPND_32_17 Field         */
/* ------- CANMSGV1 Bit Fields                      ------ */
#define C_CAN_CANMSGV1_MSGVAL_16_1_MASK          (0xFFFFU)                                           /*!< C_CAN_CANMSGV1.MSGVAL_16_1 Mask         */
#define C_CAN_CANMSGV1_MSGVAL_16_1_SHIFT         (0U)                                                /*!< C_CAN_CANMSGV1.MSGVAL_16_1 Position     */
#define C_CAN_CANMSGV1_MSGVAL_16_1(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANMSGV1.MSGVAL_16_1 Field        */
/* ------- CANMSGV2 Bit Fields                      ------ */
#define C_CAN_CANMSGV2_MSGVAL_32_17_MASK         (0xFFFFU)                                           /*!< C_CAN_CANMSGV2.MSGVAL_32_17 Mask        */
#define C_CAN_CANMSGV2_MSGVAL_32_17_SHIFT        (0U)                                                /*!< C_CAN_CANMSGV2.MSGVAL_32_17 Position    */
#define C_CAN_CANMSGV2_MSGVAL_32_17(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< C_CAN_CANMSGV2.MSGVAL_32_17 Field       */
/* ------- CANCLKDIV Bit Fields                     ------ */
#define C_CAN_CANCLKDIV_CLKDIVVAL_MASK           (0xFU)                                              /*!< C_CAN_CANCLKDIV.CLKDIVVAL Mask          */
#define C_CAN_CANCLKDIV_CLKDIVVAL_SHIFT          (0U)                                                /*!< C_CAN_CANCLKDIV.CLKDIVVAL Position      */
#define C_CAN_CANCLKDIV_CLKDIVVAL(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< C_CAN_CANCLKDIV.CLKDIVVAL Field         */
/**
 * @} */ /* End group C_CAN_Register_Masks_GROUP 
 */

/* C_CAN - Peripheral instance base addresses */
#define C_CAN_BasePtr                  0x40050000UL //!< Peripheral base address
#define C_CAN                          ((C_CAN_Type *) C_CAN_BasePtr) //!< Freescale base pointer
#define C_CAN_BASE_PTR                 (C_CAN) //!< Freescale style base pointer
/**
 * @} */ /* End group C_CAN_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FLASHCTRL_Peripheral_access_layer_GROUP FLASHCTRL Peripheral Access Layer
* @brief C Struct for FLASHCTRL
* @{
*/

/* ================================================================================ */
/* ================           FLASHCTRL (file:FLASHCTRL_LPC11xx)       ================ */
/* ================================================================================ */

/**
 * @brief LPC11U1x Flash programming firmware
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
        uint8_t   RESERVED_3[4004];            
   __I  uint32_t  FMSTAT;                       /**< 0FE0: Signature generation status register                         */
        uint8_t   RESERVED_4[4];               
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
#define FLASHCTRL_FLASHCFG_FLASHTIM_MASK         (0x3U)                                              /*!< FLASHCTRL_FLASHCFG.FLASHTIM Mask        */
#define FLASHCTRL_FLASHCFG_FLASHTIM_SHIFT        (0U)                                                /*!< FLASHCTRL_FLASHCFG.FLASHTIM Position    */
#define FLASHCTRL_FLASHCFG_FLASHTIM(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< FLASHCTRL_FLASHCFG.FLASHTIM Field       */
/* ------- FMSSTART Bit Fields                      ------ */
#define FLASHCTRL_FMSSTART_START_MASK            (0x1FFFFU)                                          /*!< FLASHCTRL_FMSSTART.START Mask           */
#define FLASHCTRL_FMSSTART_START_SHIFT           (0U)                                                /*!< FLASHCTRL_FMSSTART.START Position       */
#define FLASHCTRL_FMSSTART_START(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFFUL)       /*!< FLASHCTRL_FMSSTART.START Field          */
/* ------- FMSSTOP Bit Fields                       ------ */
#define FLASHCTRL_FMSSTOP_STOP_MASK              (0x1FFFFU)                                          /*!< FLASHCTRL_FMSSTOP.STOP Mask             */
#define FLASHCTRL_FMSSTOP_STOP_SHIFT             (0U)                                                /*!< FLASHCTRL_FMSSTOP.STOP Position         */
#define FLASHCTRL_FMSSTOP_STOP(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFFUL)       /*!< FLASHCTRL_FMSSTOP.STOP Field            */
#define FLASHCTRL_FMSSTOP_SIG_START_MASK         (0x20000U)                                          /*!< FLASHCTRL_FMSSTOP.SIG_START Mask        */
#define FLASHCTRL_FMSSTOP_SIG_START_SHIFT        (17U)                                               /*!< FLASHCTRL_FMSSTOP.SIG_START Position    */
#define FLASHCTRL_FMSSTOP_SIG_START(x)           (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< FLASHCTRL_FMSSTOP.SIG_START Field       */
/* ------- FMSW0 Bit Fields                         ------ */
#define FLASHCTRL_FMSW0_SW0_31_0_MASK            (0xFFFFFFFFU)                                       /*!< FLASHCTRL_FMSW0.SW0_31_0 Mask           */
#define FLASHCTRL_FMSW0_SW0_31_0_SHIFT           (0U)                                                /*!< FLASHCTRL_FMSW0.SW0_31_0 Position       */
#define FLASHCTRL_FMSW0_SW0_31_0(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLASHCTRL_FMSW0.SW0_31_0 Field          */
/* ------- FMSW1 Bit Fields                         ------ */
#define FLASHCTRL_FMSW1_SW1_63_32_MASK           (0xFFFFFFFFU)                                       /*!< FLASHCTRL_FMSW1.SW1_63_32 Mask          */
#define FLASHCTRL_FMSW1_SW1_63_32_SHIFT          (0U)                                                /*!< FLASHCTRL_FMSW1.SW1_63_32 Position      */
#define FLASHCTRL_FMSW1_SW1_63_32(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLASHCTRL_FMSW1.SW1_63_32 Field         */
/* ------- FMSW2 Bit Fields                         ------ */
#define FLASHCTRL_FMSW2_SW2_95_64_MASK           (0xFFFFFFFFU)                                       /*!< FLASHCTRL_FMSW2.SW2_95_64 Mask          */
#define FLASHCTRL_FMSW2_SW2_95_64_SHIFT          (0U)                                                /*!< FLASHCTRL_FMSW2.SW2_95_64 Position      */
#define FLASHCTRL_FMSW2_SW2_95_64(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLASHCTRL_FMSW2.SW2_95_64 Field         */
/* ------- FMSW3 Bit Fields                         ------ */
#define FLASHCTRL_FMSW3_SW3_127_96_MASK          (0xFFFFFFFFU)                                       /*!< FLASHCTRL_FMSW3.SW3_127_96 Mask         */
#define FLASHCTRL_FMSW3_SW3_127_96_SHIFT         (0U)                                                /*!< FLASHCTRL_FMSW3.SW3_127_96 Position     */
#define FLASHCTRL_FMSW3_SW3_127_96(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLASHCTRL_FMSW3.SW3_127_96 Field        */
/* ------- FMSTAT Bit Fields                        ------ */
#define FLASHCTRL_FMSTAT_SIG_DONE_MASK           (0x4U)                                              /*!< FLASHCTRL_FMSTAT.SIG_DONE Mask          */
#define FLASHCTRL_FMSTAT_SIG_DONE_SHIFT          (2U)                                                /*!< FLASHCTRL_FMSTAT.SIG_DONE Position      */
#define FLASHCTRL_FMSTAT_SIG_DONE(x)             (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FLASHCTRL_FMSTAT.SIG_DONE Field         */
/* ------- FMSTATCLR Bit Fields                     ------ */
#define FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_MASK    (0x4U)                                              /*!< FLASHCTRL_FMSTATCLR.SIG_DONE_CLR Mask   */
#define FLASHCTRL_FMSTATCLR_SIG_DONE_CLR_SHIFT   (2U)                                                /*!< FLASHCTRL_FMSTATCLR.SIG_DONE_CLR Position*/
#define FLASHCTRL_FMSTATCLR_SIG_DONE_CLR(x)      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FLASHCTRL_FMSTATCLR.SIG_DONE_CLR Field  */
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
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIO0 (file:GPIO0_LPC11Cxx)          ================ */
/* ================================================================================ */

/**
 * @brief GPIO0
 */
/**
* @addtogroup GPIO_structs_GROUP GPIO struct
* @brief Struct for GPIO
* @{
*/
typedef struct {                                /*       GPIO0 Structure                                              */
        uint8_t   RESERVED_0[16380];           
   __IO uint32_t  DATA;                         /**< 3FFC: Port n data register for pins PIOn_0 to PIOn_11              */
        uint8_t   RESERVED_1[16384];           
   __IO uint32_t  DIR;                          /**< 8000: Data direction register for port n                           */
   __IO uint32_t  IS;                           /**< 8004: Interrupt sense register for port n                          */
   __IO uint32_t  IBE;                          /**< 8008: Interrupt both edges register for port n                     */
   __IO uint32_t  IEV;                          /**< 800C: Interrupt event register for port n                          */
   __IO uint32_t  IE;                           /**< 8010: Interrupt mask register for port n                           */
   __I  uint32_t  RIS;                          /**< 8014: Raw interrupt status register for port n                     */
   __I  uint32_t  MIS;                          /**< 8018: Masked interrupt status register for port n                  */
   __O  uint32_t  IC;                           /**< 801C: Interrupt clear register for port n                          */
} GPIO0_Type;

/**
 * @} */ /* End group GPIO_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIO0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_Register_Masks_GROUP GPIO Register Masks
* @brief Register Masks for GPIO
* @{
*/
/* ------- DATA Bit Fields                          ------ */
#define GPIO0_DATA_DATA0_MASK                    (0x1U)                                              /*!< GPIO0_DATA.DATA0 Mask                   */
#define GPIO0_DATA_DATA0_SHIFT                   (0U)                                                /*!< GPIO0_DATA.DATA0 Position               */
#define GPIO0_DATA_DATA0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_DATA.DATA0 Field                  */
#define GPIO0_DATA_DATA1_MASK                    (0x2U)                                              /*!< GPIO0_DATA.DATA1 Mask                   */
#define GPIO0_DATA_DATA1_SHIFT                   (1U)                                                /*!< GPIO0_DATA.DATA1 Position               */
#define GPIO0_DATA_DATA1(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_DATA.DATA1 Field                  */
#define GPIO0_DATA_DATA2_MASK                    (0x4U)                                              /*!< GPIO0_DATA.DATA2 Mask                   */
#define GPIO0_DATA_DATA2_SHIFT                   (2U)                                                /*!< GPIO0_DATA.DATA2 Position               */
#define GPIO0_DATA_DATA2(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_DATA.DATA2 Field                  */
#define GPIO0_DATA_DATA3_MASK                    (0x8U)                                              /*!< GPIO0_DATA.DATA3 Mask                   */
#define GPIO0_DATA_DATA3_SHIFT                   (3U)                                                /*!< GPIO0_DATA.DATA3 Position               */
#define GPIO0_DATA_DATA3(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_DATA.DATA3 Field                  */
#define GPIO0_DATA_DATA4_MASK                    (0x10U)                                             /*!< GPIO0_DATA.DATA4 Mask                   */
#define GPIO0_DATA_DATA4_SHIFT                   (4U)                                                /*!< GPIO0_DATA.DATA4 Position               */
#define GPIO0_DATA_DATA4(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_DATA.DATA4 Field                  */
#define GPIO0_DATA_DATA5_MASK                    (0x20U)                                             /*!< GPIO0_DATA.DATA5 Mask                   */
#define GPIO0_DATA_DATA5_SHIFT                   (5U)                                                /*!< GPIO0_DATA.DATA5 Position               */
#define GPIO0_DATA_DATA5(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_DATA.DATA5 Field                  */
#define GPIO0_DATA_DATA6_MASK                    (0x40U)                                             /*!< GPIO0_DATA.DATA6 Mask                   */
#define GPIO0_DATA_DATA6_SHIFT                   (6U)                                                /*!< GPIO0_DATA.DATA6 Position               */
#define GPIO0_DATA_DATA6(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_DATA.DATA6 Field                  */
#define GPIO0_DATA_DATA7_MASK                    (0x80U)                                             /*!< GPIO0_DATA.DATA7 Mask                   */
#define GPIO0_DATA_DATA7_SHIFT                   (7U)                                                /*!< GPIO0_DATA.DATA7 Position               */
#define GPIO0_DATA_DATA7(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_DATA.DATA7 Field                  */
#define GPIO0_DATA_DATA8_MASK                    (0x100U)                                            /*!< GPIO0_DATA.DATA8 Mask                   */
#define GPIO0_DATA_DATA8_SHIFT                   (8U)                                                /*!< GPIO0_DATA.DATA8 Position               */
#define GPIO0_DATA_DATA8(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_DATA.DATA8 Field                  */
#define GPIO0_DATA_DATA9_MASK                    (0x200U)                                            /*!< GPIO0_DATA.DATA9 Mask                   */
#define GPIO0_DATA_DATA9_SHIFT                   (9U)                                                /*!< GPIO0_DATA.DATA9 Position               */
#define GPIO0_DATA_DATA9(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_DATA.DATA9 Field                  */
#define GPIO0_DATA_DATA10_MASK                   (0x400U)                                            /*!< GPIO0_DATA.DATA10 Mask                  */
#define GPIO0_DATA_DATA10_SHIFT                  (10U)                                               /*!< GPIO0_DATA.DATA10 Position              */
#define GPIO0_DATA_DATA10(x)                     (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_DATA.DATA10 Field                 */
#define GPIO0_DATA_DATA11_MASK                   (0x800U)                                            /*!< GPIO0_DATA.DATA11 Mask                  */
#define GPIO0_DATA_DATA11_SHIFT                  (11U)                                               /*!< GPIO0_DATA.DATA11 Position              */
#define GPIO0_DATA_DATA11(x)                     (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_DATA.DATA11 Field                 */
/* ------- DIR Bit Fields                           ------ */
#define GPIO0_DIR_IO0_MASK                       (0x1U)                                              /*!< GPIO0_DIR.IO0 Mask                      */
#define GPIO0_DIR_IO0_SHIFT                      (0U)                                                /*!< GPIO0_DIR.IO0 Position                  */
#define GPIO0_DIR_IO0(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_DIR.IO0 Field                     */
#define GPIO0_DIR_IO1_MASK                       (0x2U)                                              /*!< GPIO0_DIR.IO1 Mask                      */
#define GPIO0_DIR_IO1_SHIFT                      (1U)                                                /*!< GPIO0_DIR.IO1 Position                  */
#define GPIO0_DIR_IO1(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_DIR.IO1 Field                     */
#define GPIO0_DIR_IO2_MASK                       (0x4U)                                              /*!< GPIO0_DIR.IO2 Mask                      */
#define GPIO0_DIR_IO2_SHIFT                      (2U)                                                /*!< GPIO0_DIR.IO2 Position                  */
#define GPIO0_DIR_IO2(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_DIR.IO2 Field                     */
#define GPIO0_DIR_IO3_MASK                       (0x8U)                                              /*!< GPIO0_DIR.IO3 Mask                      */
#define GPIO0_DIR_IO3_SHIFT                      (3U)                                                /*!< GPIO0_DIR.IO3 Position                  */
#define GPIO0_DIR_IO3(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_DIR.IO3 Field                     */
#define GPIO0_DIR_IO4_MASK                       (0x10U)                                             /*!< GPIO0_DIR.IO4 Mask                      */
#define GPIO0_DIR_IO4_SHIFT                      (4U)                                                /*!< GPIO0_DIR.IO4 Position                  */
#define GPIO0_DIR_IO4(x)                         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_DIR.IO4 Field                     */
#define GPIO0_DIR_IO5_MASK                       (0x20U)                                             /*!< GPIO0_DIR.IO5 Mask                      */
#define GPIO0_DIR_IO5_SHIFT                      (5U)                                                /*!< GPIO0_DIR.IO5 Position                  */
#define GPIO0_DIR_IO5(x)                         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_DIR.IO5 Field                     */
#define GPIO0_DIR_IO6_MASK                       (0x40U)                                             /*!< GPIO0_DIR.IO6 Mask                      */
#define GPIO0_DIR_IO6_SHIFT                      (6U)                                                /*!< GPIO0_DIR.IO6 Position                  */
#define GPIO0_DIR_IO6(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_DIR.IO6 Field                     */
#define GPIO0_DIR_IO7_MASK                       (0x80U)                                             /*!< GPIO0_DIR.IO7 Mask                      */
#define GPIO0_DIR_IO7_SHIFT                      (7U)                                                /*!< GPIO0_DIR.IO7 Position                  */
#define GPIO0_DIR_IO7(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_DIR.IO7 Field                     */
#define GPIO0_DIR_IO8_MASK                       (0x100U)                                            /*!< GPIO0_DIR.IO8 Mask                      */
#define GPIO0_DIR_IO8_SHIFT                      (8U)                                                /*!< GPIO0_DIR.IO8 Position                  */
#define GPIO0_DIR_IO8(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_DIR.IO8 Field                     */
#define GPIO0_DIR_IO9_MASK                       (0x200U)                                            /*!< GPIO0_DIR.IO9 Mask                      */
#define GPIO0_DIR_IO9_SHIFT                      (9U)                                                /*!< GPIO0_DIR.IO9 Position                  */
#define GPIO0_DIR_IO9(x)                         (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_DIR.IO9 Field                     */
#define GPIO0_DIR_IO10_MASK                      (0x400U)                                            /*!< GPIO0_DIR.IO10 Mask                     */
#define GPIO0_DIR_IO10_SHIFT                     (10U)                                               /*!< GPIO0_DIR.IO10 Position                 */
#define GPIO0_DIR_IO10(x)                        (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_DIR.IO10 Field                    */
#define GPIO0_DIR_IO11_MASK                      (0x800U)                                            /*!< GPIO0_DIR.IO11 Mask                     */
#define GPIO0_DIR_IO11_SHIFT                     (11U)                                               /*!< GPIO0_DIR.IO11 Position                 */
#define GPIO0_DIR_IO11(x)                        (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_DIR.IO11 Field                    */
/* ------- IS Bit Fields                            ------ */
#define GPIO0_IS_ISENSE0_MASK                    (0x1U)                                              /*!< GPIO0_IS.ISENSE0 Mask                   */
#define GPIO0_IS_ISENSE0_SHIFT                   (0U)                                                /*!< GPIO0_IS.ISENSE0 Position               */
#define GPIO0_IS_ISENSE0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_IS.ISENSE0 Field                  */
#define GPIO0_IS_ISENSE1_MASK                    (0x2U)                                              /*!< GPIO0_IS.ISENSE1 Mask                   */
#define GPIO0_IS_ISENSE1_SHIFT                   (1U)                                                /*!< GPIO0_IS.ISENSE1 Position               */
#define GPIO0_IS_ISENSE1(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_IS.ISENSE1 Field                  */
#define GPIO0_IS_ISENSE2_MASK                    (0x4U)                                              /*!< GPIO0_IS.ISENSE2 Mask                   */
#define GPIO0_IS_ISENSE2_SHIFT                   (2U)                                                /*!< GPIO0_IS.ISENSE2 Position               */
#define GPIO0_IS_ISENSE2(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_IS.ISENSE2 Field                  */
#define GPIO0_IS_ISENSE3_MASK                    (0x8U)                                              /*!< GPIO0_IS.ISENSE3 Mask                   */
#define GPIO0_IS_ISENSE3_SHIFT                   (3U)                                                /*!< GPIO0_IS.ISENSE3 Position               */
#define GPIO0_IS_ISENSE3(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_IS.ISENSE3 Field                  */
#define GPIO0_IS_ISENSE4_MASK                    (0x10U)                                             /*!< GPIO0_IS.ISENSE4 Mask                   */
#define GPIO0_IS_ISENSE4_SHIFT                   (4U)                                                /*!< GPIO0_IS.ISENSE4 Position               */
#define GPIO0_IS_ISENSE4(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_IS.ISENSE4 Field                  */
#define GPIO0_IS_ISENSE5_MASK                    (0x20U)                                             /*!< GPIO0_IS.ISENSE5 Mask                   */
#define GPIO0_IS_ISENSE5_SHIFT                   (5U)                                                /*!< GPIO0_IS.ISENSE5 Position               */
#define GPIO0_IS_ISENSE5(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_IS.ISENSE5 Field                  */
#define GPIO0_IS_ISENSE6_MASK                    (0x40U)                                             /*!< GPIO0_IS.ISENSE6 Mask                   */
#define GPIO0_IS_ISENSE6_SHIFT                   (6U)                                                /*!< GPIO0_IS.ISENSE6 Position               */
#define GPIO0_IS_ISENSE6(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_IS.ISENSE6 Field                  */
#define GPIO0_IS_ISENSE7_MASK                    (0x80U)                                             /*!< GPIO0_IS.ISENSE7 Mask                   */
#define GPIO0_IS_ISENSE7_SHIFT                   (7U)                                                /*!< GPIO0_IS.ISENSE7 Position               */
#define GPIO0_IS_ISENSE7(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_IS.ISENSE7 Field                  */
#define GPIO0_IS_ISENSE8_MASK                    (0x100U)                                            /*!< GPIO0_IS.ISENSE8 Mask                   */
#define GPIO0_IS_ISENSE8_SHIFT                   (8U)                                                /*!< GPIO0_IS.ISENSE8 Position               */
#define GPIO0_IS_ISENSE8(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_IS.ISENSE8 Field                  */
#define GPIO0_IS_ISENSE9_MASK                    (0x200U)                                            /*!< GPIO0_IS.ISENSE9 Mask                   */
#define GPIO0_IS_ISENSE9_SHIFT                   (9U)                                                /*!< GPIO0_IS.ISENSE9 Position               */
#define GPIO0_IS_ISENSE9(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_IS.ISENSE9 Field                  */
#define GPIO0_IS_ISENSE10_MASK                   (0x400U)                                            /*!< GPIO0_IS.ISENSE10 Mask                  */
#define GPIO0_IS_ISENSE10_SHIFT                  (10U)                                               /*!< GPIO0_IS.ISENSE10 Position              */
#define GPIO0_IS_ISENSE10(x)                     (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_IS.ISENSE10 Field                 */
#define GPIO0_IS_ISENSE11_MASK                   (0x800U)                                            /*!< GPIO0_IS.ISENSE11 Mask                  */
#define GPIO0_IS_ISENSE11_SHIFT                  (11U)                                               /*!< GPIO0_IS.ISENSE11 Position              */
#define GPIO0_IS_ISENSE11(x)                     (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_IS.ISENSE11 Field                 */
/* ------- IBE Bit Fields                           ------ */
#define GPIO0_IBE_IBE0_MASK                      (0x1U)                                              /*!< GPIO0_IBE.IBE0 Mask                     */
#define GPIO0_IBE_IBE0_SHIFT                     (0U)                                                /*!< GPIO0_IBE.IBE0 Position                 */
#define GPIO0_IBE_IBE0(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_IBE.IBE0 Field                    */
#define GPIO0_IBE_IBE1_MASK                      (0x2U)                                              /*!< GPIO0_IBE.IBE1 Mask                     */
#define GPIO0_IBE_IBE1_SHIFT                     (1U)                                                /*!< GPIO0_IBE.IBE1 Position                 */
#define GPIO0_IBE_IBE1(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_IBE.IBE1 Field                    */
#define GPIO0_IBE_IBE2_MASK                      (0x4U)                                              /*!< GPIO0_IBE.IBE2 Mask                     */
#define GPIO0_IBE_IBE2_SHIFT                     (2U)                                                /*!< GPIO0_IBE.IBE2 Position                 */
#define GPIO0_IBE_IBE2(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_IBE.IBE2 Field                    */
#define GPIO0_IBE_IBE3_MASK                      (0x8U)                                              /*!< GPIO0_IBE.IBE3 Mask                     */
#define GPIO0_IBE_IBE3_SHIFT                     (3U)                                                /*!< GPIO0_IBE.IBE3 Position                 */
#define GPIO0_IBE_IBE3(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_IBE.IBE3 Field                    */
#define GPIO0_IBE_IBE4_MASK                      (0x10U)                                             /*!< GPIO0_IBE.IBE4 Mask                     */
#define GPIO0_IBE_IBE4_SHIFT                     (4U)                                                /*!< GPIO0_IBE.IBE4 Position                 */
#define GPIO0_IBE_IBE4(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_IBE.IBE4 Field                    */
#define GPIO0_IBE_IBE5_MASK                      (0x20U)                                             /*!< GPIO0_IBE.IBE5 Mask                     */
#define GPIO0_IBE_IBE5_SHIFT                     (5U)                                                /*!< GPIO0_IBE.IBE5 Position                 */
#define GPIO0_IBE_IBE5(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_IBE.IBE5 Field                    */
#define GPIO0_IBE_IBE6_MASK                      (0x40U)                                             /*!< GPIO0_IBE.IBE6 Mask                     */
#define GPIO0_IBE_IBE6_SHIFT                     (6U)                                                /*!< GPIO0_IBE.IBE6 Position                 */
#define GPIO0_IBE_IBE6(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_IBE.IBE6 Field                    */
#define GPIO0_IBE_IBE7_MASK                      (0x80U)                                             /*!< GPIO0_IBE.IBE7 Mask                     */
#define GPIO0_IBE_IBE7_SHIFT                     (7U)                                                /*!< GPIO0_IBE.IBE7 Position                 */
#define GPIO0_IBE_IBE7(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_IBE.IBE7 Field                    */
#define GPIO0_IBE_IBE8_MASK                      (0x100U)                                            /*!< GPIO0_IBE.IBE8 Mask                     */
#define GPIO0_IBE_IBE8_SHIFT                     (8U)                                                /*!< GPIO0_IBE.IBE8 Position                 */
#define GPIO0_IBE_IBE8(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_IBE.IBE8 Field                    */
#define GPIO0_IBE_IBE9_MASK                      (0x200U)                                            /*!< GPIO0_IBE.IBE9 Mask                     */
#define GPIO0_IBE_IBE9_SHIFT                     (9U)                                                /*!< GPIO0_IBE.IBE9 Position                 */
#define GPIO0_IBE_IBE9(x)                        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_IBE.IBE9 Field                    */
#define GPIO0_IBE_IBE10_MASK                     (0x400U)                                            /*!< GPIO0_IBE.IBE10 Mask                    */
#define GPIO0_IBE_IBE10_SHIFT                    (10U)                                               /*!< GPIO0_IBE.IBE10 Position                */
#define GPIO0_IBE_IBE10(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_IBE.IBE10 Field                   */
#define GPIO0_IBE_IBE11_MASK                     (0x800U)                                            /*!< GPIO0_IBE.IBE11 Mask                    */
#define GPIO0_IBE_IBE11_SHIFT                    (11U)                                               /*!< GPIO0_IBE.IBE11 Position                */
#define GPIO0_IBE_IBE11(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_IBE.IBE11 Field                   */
/* ------- IEV Bit Fields                           ------ */
#define GPIO0_IEV_IEV0_MASK                      (0x1U)                                              /*!< GPIO0_IEV.IEV0 Mask                     */
#define GPIO0_IEV_IEV0_SHIFT                     (0U)                                                /*!< GPIO0_IEV.IEV0 Position                 */
#define GPIO0_IEV_IEV0(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_IEV.IEV0 Field                    */
#define GPIO0_IEV_IEV1_MASK                      (0x2U)                                              /*!< GPIO0_IEV.IEV1 Mask                     */
#define GPIO0_IEV_IEV1_SHIFT                     (1U)                                                /*!< GPIO0_IEV.IEV1 Position                 */
#define GPIO0_IEV_IEV1(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_IEV.IEV1 Field                    */
#define GPIO0_IEV_IEV2_MASK                      (0x4U)                                              /*!< GPIO0_IEV.IEV2 Mask                     */
#define GPIO0_IEV_IEV2_SHIFT                     (2U)                                                /*!< GPIO0_IEV.IEV2 Position                 */
#define GPIO0_IEV_IEV2(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_IEV.IEV2 Field                    */
#define GPIO0_IEV_IEV3_MASK                      (0x8U)                                              /*!< GPIO0_IEV.IEV3 Mask                     */
#define GPIO0_IEV_IEV3_SHIFT                     (3U)                                                /*!< GPIO0_IEV.IEV3 Position                 */
#define GPIO0_IEV_IEV3(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_IEV.IEV3 Field                    */
#define GPIO0_IEV_IEV4_MASK                      (0x10U)                                             /*!< GPIO0_IEV.IEV4 Mask                     */
#define GPIO0_IEV_IEV4_SHIFT                     (4U)                                                /*!< GPIO0_IEV.IEV4 Position                 */
#define GPIO0_IEV_IEV4(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_IEV.IEV4 Field                    */
#define GPIO0_IEV_IEV5_MASK                      (0x20U)                                             /*!< GPIO0_IEV.IEV5 Mask                     */
#define GPIO0_IEV_IEV5_SHIFT                     (5U)                                                /*!< GPIO0_IEV.IEV5 Position                 */
#define GPIO0_IEV_IEV5(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_IEV.IEV5 Field                    */
#define GPIO0_IEV_IEV6_MASK                      (0x40U)                                             /*!< GPIO0_IEV.IEV6 Mask                     */
#define GPIO0_IEV_IEV6_SHIFT                     (6U)                                                /*!< GPIO0_IEV.IEV6 Position                 */
#define GPIO0_IEV_IEV6(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_IEV.IEV6 Field                    */
#define GPIO0_IEV_IEV7_MASK                      (0x80U)                                             /*!< GPIO0_IEV.IEV7 Mask                     */
#define GPIO0_IEV_IEV7_SHIFT                     (7U)                                                /*!< GPIO0_IEV.IEV7 Position                 */
#define GPIO0_IEV_IEV7(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_IEV.IEV7 Field                    */
#define GPIO0_IEV_IEV8_MASK                      (0x100U)                                            /*!< GPIO0_IEV.IEV8 Mask                     */
#define GPIO0_IEV_IEV8_SHIFT                     (8U)                                                /*!< GPIO0_IEV.IEV8 Position                 */
#define GPIO0_IEV_IEV8(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_IEV.IEV8 Field                    */
#define GPIO0_IEV_IEV9_MASK                      (0x200U)                                            /*!< GPIO0_IEV.IEV9 Mask                     */
#define GPIO0_IEV_IEV9_SHIFT                     (9U)                                                /*!< GPIO0_IEV.IEV9 Position                 */
#define GPIO0_IEV_IEV9(x)                        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_IEV.IEV9 Field                    */
#define GPIO0_IEV_IEV10_MASK                     (0x400U)                                            /*!< GPIO0_IEV.IEV10 Mask                    */
#define GPIO0_IEV_IEV10_SHIFT                    (10U)                                               /*!< GPIO0_IEV.IEV10 Position                */
#define GPIO0_IEV_IEV10(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_IEV.IEV10 Field                   */
#define GPIO0_IEV_IEV11_MASK                     (0x800U)                                            /*!< GPIO0_IEV.IEV11 Mask                    */
#define GPIO0_IEV_IEV11_SHIFT                    (11U)                                               /*!< GPIO0_IEV.IEV11 Position                */
#define GPIO0_IEV_IEV11(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_IEV.IEV11 Field                   */
/* ------- IE Bit Fields                            ------ */
#define GPIO0_IE_MASK0_MASK                      (0x1U)                                              /*!< GPIO0_IE.MASK0 Mask                     */
#define GPIO0_IE_MASK0_SHIFT                     (0U)                                                /*!< GPIO0_IE.MASK0 Position                 */
#define GPIO0_IE_MASK0(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_IE.MASK0 Field                    */
#define GPIO0_IE_MASK1_MASK                      (0x2U)                                              /*!< GPIO0_IE.MASK1 Mask                     */
#define GPIO0_IE_MASK1_SHIFT                     (1U)                                                /*!< GPIO0_IE.MASK1 Position                 */
#define GPIO0_IE_MASK1(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_IE.MASK1 Field                    */
#define GPIO0_IE_MASK2_MASK                      (0x4U)                                              /*!< GPIO0_IE.MASK2 Mask                     */
#define GPIO0_IE_MASK2_SHIFT                     (2U)                                                /*!< GPIO0_IE.MASK2 Position                 */
#define GPIO0_IE_MASK2(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_IE.MASK2 Field                    */
#define GPIO0_IE_MASK3_MASK                      (0x8U)                                              /*!< GPIO0_IE.MASK3 Mask                     */
#define GPIO0_IE_MASK3_SHIFT                     (3U)                                                /*!< GPIO0_IE.MASK3 Position                 */
#define GPIO0_IE_MASK3(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_IE.MASK3 Field                    */
#define GPIO0_IE_MASK4_MASK                      (0x10U)                                             /*!< GPIO0_IE.MASK4 Mask                     */
#define GPIO0_IE_MASK4_SHIFT                     (4U)                                                /*!< GPIO0_IE.MASK4 Position                 */
#define GPIO0_IE_MASK4(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_IE.MASK4 Field                    */
#define GPIO0_IE_MASK5_MASK                      (0x20U)                                             /*!< GPIO0_IE.MASK5 Mask                     */
#define GPIO0_IE_MASK5_SHIFT                     (5U)                                                /*!< GPIO0_IE.MASK5 Position                 */
#define GPIO0_IE_MASK5(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_IE.MASK5 Field                    */
#define GPIO0_IE_MASK6_MASK                      (0x40U)                                             /*!< GPIO0_IE.MASK6 Mask                     */
#define GPIO0_IE_MASK6_SHIFT                     (6U)                                                /*!< GPIO0_IE.MASK6 Position                 */
#define GPIO0_IE_MASK6(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_IE.MASK6 Field                    */
#define GPIO0_IE_MASK7_MASK                      (0x80U)                                             /*!< GPIO0_IE.MASK7 Mask                     */
#define GPIO0_IE_MASK7_SHIFT                     (7U)                                                /*!< GPIO0_IE.MASK7 Position                 */
#define GPIO0_IE_MASK7(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_IE.MASK7 Field                    */
#define GPIO0_IE_MASK8_MASK                      (0x100U)                                            /*!< GPIO0_IE.MASK8 Mask                     */
#define GPIO0_IE_MASK8_SHIFT                     (8U)                                                /*!< GPIO0_IE.MASK8 Position                 */
#define GPIO0_IE_MASK8(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_IE.MASK8 Field                    */
#define GPIO0_IE_MASK9_MASK                      (0x200U)                                            /*!< GPIO0_IE.MASK9 Mask                     */
#define GPIO0_IE_MASK9_SHIFT                     (9U)                                                /*!< GPIO0_IE.MASK9 Position                 */
#define GPIO0_IE_MASK9(x)                        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_IE.MASK9 Field                    */
#define GPIO0_IE_MASK10_MASK                     (0x400U)                                            /*!< GPIO0_IE.MASK10 Mask                    */
#define GPIO0_IE_MASK10_SHIFT                    (10U)                                               /*!< GPIO0_IE.MASK10 Position                */
#define GPIO0_IE_MASK10(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_IE.MASK10 Field                   */
#define GPIO0_IE_MASK11_MASK                     (0x800U)                                            /*!< GPIO0_IE.MASK11 Mask                    */
#define GPIO0_IE_MASK11_SHIFT                    (11U)                                               /*!< GPIO0_IE.MASK11 Position                */
#define GPIO0_IE_MASK11(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_IE.MASK11 Field                   */
/* ------- RIS Bit Fields                           ------ */
#define GPIO0_RIS_RAWST0_MASK                    (0x1U)                                              /*!< GPIO0_RIS.RAWST0 Mask                   */
#define GPIO0_RIS_RAWST0_SHIFT                   (0U)                                                /*!< GPIO0_RIS.RAWST0 Position               */
#define GPIO0_RIS_RAWST0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_RIS.RAWST0 Field                  */
#define GPIO0_RIS_RAWST1_MASK                    (0x2U)                                              /*!< GPIO0_RIS.RAWST1 Mask                   */
#define GPIO0_RIS_RAWST1_SHIFT                   (1U)                                                /*!< GPIO0_RIS.RAWST1 Position               */
#define GPIO0_RIS_RAWST1(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_RIS.RAWST1 Field                  */
#define GPIO0_RIS_RAWST2_MASK                    (0x4U)                                              /*!< GPIO0_RIS.RAWST2 Mask                   */
#define GPIO0_RIS_RAWST2_SHIFT                   (2U)                                                /*!< GPIO0_RIS.RAWST2 Position               */
#define GPIO0_RIS_RAWST2(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_RIS.RAWST2 Field                  */
#define GPIO0_RIS_RAWST3_MASK                    (0x8U)                                              /*!< GPIO0_RIS.RAWST3 Mask                   */
#define GPIO0_RIS_RAWST3_SHIFT                   (3U)                                                /*!< GPIO0_RIS.RAWST3 Position               */
#define GPIO0_RIS_RAWST3(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_RIS.RAWST3 Field                  */
#define GPIO0_RIS_RAWST4_MASK                    (0x10U)                                             /*!< GPIO0_RIS.RAWST4 Mask                   */
#define GPIO0_RIS_RAWST4_SHIFT                   (4U)                                                /*!< GPIO0_RIS.RAWST4 Position               */
#define GPIO0_RIS_RAWST4(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_RIS.RAWST4 Field                  */
#define GPIO0_RIS_RAWST5_MASK                    (0x20U)                                             /*!< GPIO0_RIS.RAWST5 Mask                   */
#define GPIO0_RIS_RAWST5_SHIFT                   (5U)                                                /*!< GPIO0_RIS.RAWST5 Position               */
#define GPIO0_RIS_RAWST5(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_RIS.RAWST5 Field                  */
#define GPIO0_RIS_RAWST6_MASK                    (0x40U)                                             /*!< GPIO0_RIS.RAWST6 Mask                   */
#define GPIO0_RIS_RAWST6_SHIFT                   (6U)                                                /*!< GPIO0_RIS.RAWST6 Position               */
#define GPIO0_RIS_RAWST6(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_RIS.RAWST6 Field                  */
#define GPIO0_RIS_RAWST7_MASK                    (0x80U)                                             /*!< GPIO0_RIS.RAWST7 Mask                   */
#define GPIO0_RIS_RAWST7_SHIFT                   (7U)                                                /*!< GPIO0_RIS.RAWST7 Position               */
#define GPIO0_RIS_RAWST7(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_RIS.RAWST7 Field                  */
#define GPIO0_RIS_RAWST8_MASK                    (0x100U)                                            /*!< GPIO0_RIS.RAWST8 Mask                   */
#define GPIO0_RIS_RAWST8_SHIFT                   (8U)                                                /*!< GPIO0_RIS.RAWST8 Position               */
#define GPIO0_RIS_RAWST8(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_RIS.RAWST8 Field                  */
#define GPIO0_RIS_RAWST9_MASK                    (0x200U)                                            /*!< GPIO0_RIS.RAWST9 Mask                   */
#define GPIO0_RIS_RAWST9_SHIFT                   (9U)                                                /*!< GPIO0_RIS.RAWST9 Position               */
#define GPIO0_RIS_RAWST9(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_RIS.RAWST9 Field                  */
#define GPIO0_RIS_RAWST10_MASK                   (0x400U)                                            /*!< GPIO0_RIS.RAWST10 Mask                  */
#define GPIO0_RIS_RAWST10_SHIFT                  (10U)                                               /*!< GPIO0_RIS.RAWST10 Position              */
#define GPIO0_RIS_RAWST10(x)                     (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_RIS.RAWST10 Field                 */
#define GPIO0_RIS_RAWST11_MASK                   (0x800U)                                            /*!< GPIO0_RIS.RAWST11 Mask                  */
#define GPIO0_RIS_RAWST11_SHIFT                  (11U)                                               /*!< GPIO0_RIS.RAWST11 Position              */
#define GPIO0_RIS_RAWST11(x)                     (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_RIS.RAWST11 Field                 */
/* ------- MIS Bit Fields                           ------ */
#define GPIO0_MIS_MASK0_MASK                     (0x1U)                                              /*!< GPIO0_MIS.MASK0 Mask                    */
#define GPIO0_MIS_MASK0_SHIFT                    (0U)                                                /*!< GPIO0_MIS.MASK0 Position                */
#define GPIO0_MIS_MASK0(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_MIS.MASK0 Field                   */
#define GPIO0_MIS_MASK1_MASK                     (0x2U)                                              /*!< GPIO0_MIS.MASK1 Mask                    */
#define GPIO0_MIS_MASK1_SHIFT                    (1U)                                                /*!< GPIO0_MIS.MASK1 Position                */
#define GPIO0_MIS_MASK1(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_MIS.MASK1 Field                   */
#define GPIO0_MIS_MASK2_MASK                     (0x4U)                                              /*!< GPIO0_MIS.MASK2 Mask                    */
#define GPIO0_MIS_MASK2_SHIFT                    (2U)                                                /*!< GPIO0_MIS.MASK2 Position                */
#define GPIO0_MIS_MASK2(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_MIS.MASK2 Field                   */
#define GPIO0_MIS_MASK3_MASK                     (0x8U)                                              /*!< GPIO0_MIS.MASK3 Mask                    */
#define GPIO0_MIS_MASK3_SHIFT                    (3U)                                                /*!< GPIO0_MIS.MASK3 Position                */
#define GPIO0_MIS_MASK3(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_MIS.MASK3 Field                   */
#define GPIO0_MIS_MASK4_MASK                     (0x10U)                                             /*!< GPIO0_MIS.MASK4 Mask                    */
#define GPIO0_MIS_MASK4_SHIFT                    (4U)                                                /*!< GPIO0_MIS.MASK4 Position                */
#define GPIO0_MIS_MASK4(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_MIS.MASK4 Field                   */
#define GPIO0_MIS_MASK5_MASK                     (0x20U)                                             /*!< GPIO0_MIS.MASK5 Mask                    */
#define GPIO0_MIS_MASK5_SHIFT                    (5U)                                                /*!< GPIO0_MIS.MASK5 Position                */
#define GPIO0_MIS_MASK5(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_MIS.MASK5 Field                   */
#define GPIO0_MIS_MASK6_MASK                     (0x40U)                                             /*!< GPIO0_MIS.MASK6 Mask                    */
#define GPIO0_MIS_MASK6_SHIFT                    (6U)                                                /*!< GPIO0_MIS.MASK6 Position                */
#define GPIO0_MIS_MASK6(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_MIS.MASK6 Field                   */
#define GPIO0_MIS_MASK7_MASK                     (0x80U)                                             /*!< GPIO0_MIS.MASK7 Mask                    */
#define GPIO0_MIS_MASK7_SHIFT                    (7U)                                                /*!< GPIO0_MIS.MASK7 Position                */
#define GPIO0_MIS_MASK7(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_MIS.MASK7 Field                   */
#define GPIO0_MIS_MASK8_MASK                     (0x100U)                                            /*!< GPIO0_MIS.MASK8 Mask                    */
#define GPIO0_MIS_MASK8_SHIFT                    (8U)                                                /*!< GPIO0_MIS.MASK8 Position                */
#define GPIO0_MIS_MASK8(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_MIS.MASK8 Field                   */
#define GPIO0_MIS_MASK9_MASK                     (0x200U)                                            /*!< GPIO0_MIS.MASK9 Mask                    */
#define GPIO0_MIS_MASK9_SHIFT                    (9U)                                                /*!< GPIO0_MIS.MASK9 Position                */
#define GPIO0_MIS_MASK9(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_MIS.MASK9 Field                   */
#define GPIO0_MIS_MASK10_MASK                    (0x400U)                                            /*!< GPIO0_MIS.MASK10 Mask                   */
#define GPIO0_MIS_MASK10_SHIFT                   (10U)                                               /*!< GPIO0_MIS.MASK10 Position               */
#define GPIO0_MIS_MASK10(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_MIS.MASK10 Field                  */
#define GPIO0_MIS_MASK11_MASK                    (0x800U)                                            /*!< GPIO0_MIS.MASK11 Mask                   */
#define GPIO0_MIS_MASK11_SHIFT                   (11U)                                               /*!< GPIO0_MIS.MASK11 Position               */
#define GPIO0_MIS_MASK11(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_MIS.MASK11 Field                  */
/* ------- IC Bit Fields                            ------ */
#define GPIO0_IC_CLR0_MASK                       (0x1U)                                              /*!< GPIO0_IC.CLR0 Mask                      */
#define GPIO0_IC_CLR0_SHIFT                      (0U)                                                /*!< GPIO0_IC.CLR0 Position                  */
#define GPIO0_IC_CLR0(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< GPIO0_IC.CLR0 Field                     */
#define GPIO0_IC_CLR1_MASK                       (0x2U)                                              /*!< GPIO0_IC.CLR1 Mask                      */
#define GPIO0_IC_CLR1_SHIFT                      (1U)                                                /*!< GPIO0_IC.CLR1 Position                  */
#define GPIO0_IC_CLR1(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< GPIO0_IC.CLR1 Field                     */
#define GPIO0_IC_CLR2_MASK                       (0x4U)                                              /*!< GPIO0_IC.CLR2 Mask                      */
#define GPIO0_IC_CLR2_SHIFT                      (2U)                                                /*!< GPIO0_IC.CLR2 Position                  */
#define GPIO0_IC_CLR2(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< GPIO0_IC.CLR2 Field                     */
#define GPIO0_IC_CLR3_MASK                       (0x8U)                                              /*!< GPIO0_IC.CLR3 Mask                      */
#define GPIO0_IC_CLR3_SHIFT                      (3U)                                                /*!< GPIO0_IC.CLR3 Position                  */
#define GPIO0_IC_CLR3(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< GPIO0_IC.CLR3 Field                     */
#define GPIO0_IC_CLR4_MASK                       (0x10U)                                             /*!< GPIO0_IC.CLR4 Mask                      */
#define GPIO0_IC_CLR4_SHIFT                      (4U)                                                /*!< GPIO0_IC.CLR4 Position                  */
#define GPIO0_IC_CLR4(x)                         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< GPIO0_IC.CLR4 Field                     */
#define GPIO0_IC_CLR5_MASK                       (0x20U)                                             /*!< GPIO0_IC.CLR5 Mask                      */
#define GPIO0_IC_CLR5_SHIFT                      (5U)                                                /*!< GPIO0_IC.CLR5 Position                  */
#define GPIO0_IC_CLR5(x)                         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< GPIO0_IC.CLR5 Field                     */
#define GPIO0_IC_CLR6_MASK                       (0x40U)                                             /*!< GPIO0_IC.CLR6 Mask                      */
#define GPIO0_IC_CLR6_SHIFT                      (6U)                                                /*!< GPIO0_IC.CLR6 Position                  */
#define GPIO0_IC_CLR6(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< GPIO0_IC.CLR6 Field                     */
#define GPIO0_IC_CLR7_MASK                       (0x80U)                                             /*!< GPIO0_IC.CLR7 Mask                      */
#define GPIO0_IC_CLR7_SHIFT                      (7U)                                                /*!< GPIO0_IC.CLR7 Position                  */
#define GPIO0_IC_CLR7(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< GPIO0_IC.CLR7 Field                     */
#define GPIO0_IC_CLR8_MASK                       (0x100U)                                            /*!< GPIO0_IC.CLR8 Mask                      */
#define GPIO0_IC_CLR8_SHIFT                      (8U)                                                /*!< GPIO0_IC.CLR8 Position                  */
#define GPIO0_IC_CLR8(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< GPIO0_IC.CLR8 Field                     */
#define GPIO0_IC_CLR9_MASK                       (0x200U)                                            /*!< GPIO0_IC.CLR9 Mask                      */
#define GPIO0_IC_CLR9_SHIFT                      (9U)                                                /*!< GPIO0_IC.CLR9 Position                  */
#define GPIO0_IC_CLR9(x)                         (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< GPIO0_IC.CLR9 Field                     */
#define GPIO0_IC_CLR10_MASK                      (0x400U)                                            /*!< GPIO0_IC.CLR10 Mask                     */
#define GPIO0_IC_CLR10_SHIFT                     (10U)                                               /*!< GPIO0_IC.CLR10 Position                 */
#define GPIO0_IC_CLR10(x)                        (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< GPIO0_IC.CLR10 Field                    */
#define GPIO0_IC_CLR11_MASK                      (0x800U)                                            /*!< GPIO0_IC.CLR11 Mask                     */
#define GPIO0_IC_CLR11_SHIFT                     (11U)                                               /*!< GPIO0_IC.CLR11 Position                 */
#define GPIO0_IC_CLR11(x)                        (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< GPIO0_IC.CLR11 Field                    */
/**
 * @} */ /* End group GPIO_Register_Masks_GROUP 
 */

/* GPIO0 - Peripheral instance base addresses */
#define GPIO0_BasePtr                  0x50000000UL //!< Peripheral base address
#define GPIO0                          ((GPIO0_Type *) GPIO0_BasePtr) //!< Freescale base pointer
#define GPIO0_BASE_PTR                 (GPIO0) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIO1 (derived from GPIO0)           ================ */
/* ================================================================================ */

/**
 * @brief GPIO0
 */

/* GPIO1 - Peripheral instance base addresses */
#define GPIO1_BasePtr                  0x50010000UL //!< Peripheral base address
#define GPIO1                          ((GPIO0_Type *) GPIO1_BasePtr) //!< Freescale base pointer
#define GPIO1_BASE_PTR                 (GPIO1) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIO2 (derived from GPIO0)           ================ */
/* ================================================================================ */

/**
 * @brief GPIO0
 */

/* GPIO2 - Peripheral instance base addresses */
#define GPIO2_BasePtr                  0x50020000UL //!< Peripheral base address
#define GPIO2                          ((GPIO0_Type *) GPIO2_BasePtr) //!< Freescale base pointer
#define GPIO2_BASE_PTR                 (GPIO2) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIO3 (derived from GPIO0)           ================ */
/* ================================================================================ */

/**
 * @brief GPIO0
 */

/* GPIO3 - Peripheral instance base addresses */
#define GPIO3_BasePtr                  0x50030000UL //!< Peripheral base address
#define GPIO3                          ((GPIO0_Type *) GPIO3_BasePtr) //!< Freescale base pointer
#define GPIO3_BASE_PTR                 (GPIO3) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C (file:I2C_LPC11Cxx)              ================ */
/* ================================================================================ */

/**
 * @brief I2C-bus interface
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
   __IO uint32_t  ADR1;                         /**< 0020: I2C Slave Address Register 1. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
   __IO uint32_t  ADR2;                         /**< 0024: I2C Slave Address Register 1. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
   __IO uint32_t  ADR3;                         /**< 0028: I2C Slave Address Register 1. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address */
   __I  uint32_t  DATA_BUFFER;                  /**< 002C: Data buffer register. The contents of the 8 MSBs of the I2DAT shift register will be transferred to the DATA_BUFFER automatically after every nine bits (8 bits of data plus ACK or NACK) has been received on the bus */
   __IO uint32_t  MASK0;                        /**< 0030: I2C Slave address mask register 0. This mask register is associated with I2ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (0000000) */
   __IO uint32_t  MASK1;                        /**< 0034: I2C Slave address mask register 0. This mask register is associated with I2ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (0000000) */
   __IO uint32_t  MASK2;                        /**< 0038: I2C Slave address mask register 0. This mask register is associated with I2ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (0000000) */
   __IO uint32_t  MASK3;                        /**< 003C: I2C Slave address mask register 0. This mask register is associated with I2ADR0 to determine an address match. The mask register has no effect when comparing to the General Call address (0000000) */
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
#define I2C_CONSET_AA_MASK                       (0x4U)                                              /*!< I2C_CONSET.AA Mask                      */
#define I2C_CONSET_AA_SHIFT                      (2U)                                                /*!< I2C_CONSET.AA Position                  */
#define I2C_CONSET_AA(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< I2C_CONSET.AA Field                     */
#define I2C_CONSET_SI_MASK                       (0x8U)                                              /*!< I2C_CONSET.SI Mask                      */
#define I2C_CONSET_SI_SHIFT                      (3U)                                                /*!< I2C_CONSET.SI Position                  */
#define I2C_CONSET_SI(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< I2C_CONSET.SI Field                     */
#define I2C_CONSET_STO_MASK                      (0x10U)                                             /*!< I2C_CONSET.STO Mask                     */
#define I2C_CONSET_STO_SHIFT                     (4U)                                                /*!< I2C_CONSET.STO Position                 */
#define I2C_CONSET_STO(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< I2C_CONSET.STO Field                    */
#define I2C_CONSET_STA_MASK                      (0x20U)                                             /*!< I2C_CONSET.STA Mask                     */
#define I2C_CONSET_STA_SHIFT                     (5U)                                                /*!< I2C_CONSET.STA Position                 */
#define I2C_CONSET_STA(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< I2C_CONSET.STA Field                    */
#define I2C_CONSET_I2EN_MASK                     (0x40U)                                             /*!< I2C_CONSET.I2EN Mask                    */
#define I2C_CONSET_I2EN_SHIFT                    (6U)                                                /*!< I2C_CONSET.I2EN Position                */
#define I2C_CONSET_I2EN(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< I2C_CONSET.I2EN Field                   */
/* ------- STAT Bit Fields                          ------ */
#define I2C_STAT_Status_MASK                     (0xF8U)                                             /*!< I2C_STAT.Status Mask                    */
#define I2C_STAT_Status_SHIFT                    (3U)                                                /*!< I2C_STAT.Status Position                */
#define I2C_STAT_Status(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0xF8UL)          /*!< I2C_STAT.Status Field                   */
/* ------- DAT Bit Fields                           ------ */
#define I2C_DAT_Data_MASK                        (0xFFU)                                             /*!< I2C_DAT.Data Mask                       */
#define I2C_DAT_Data_SHIFT                       (0U)                                                /*!< I2C_DAT.Data Position                   */
#define I2C_DAT_Data(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< I2C_DAT.Data Field                      */
/* ------- ADR0 Bit Fields                          ------ */
#define I2C_ADR0_GC_MASK                         (0x1U)                                              /*!< I2C_ADR0.GC Mask                        */
#define I2C_ADR0_GC_SHIFT                        (0U)                                                /*!< I2C_ADR0.GC Position                    */
#define I2C_ADR0_GC(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< I2C_ADR0.GC Field                       */
#define I2C_ADR0_Address_MASK                    (0xFEU)                                             /*!< I2C_ADR0.Address Mask                   */
#define I2C_ADR0_Address_SHIFT                   (1U)                                                /*!< I2C_ADR0.Address Position               */
#define I2C_ADR0_Address(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< I2C_ADR0.Address Field                  */
/* ------- SCLH Bit Fields                          ------ */
#define I2C_SCLH_SCLH_MASK                       (0xFFFFU)                                           /*!< I2C_SCLH.SCLH Mask                      */
#define I2C_SCLH_SCLH_SHIFT                      (0U)                                                /*!< I2C_SCLH.SCLH Position                  */
#define I2C_SCLH_SCLH(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< I2C_SCLH.SCLH Field                     */
/* ------- SCLL Bit Fields                          ------ */
#define I2C_SCLL_SCLL_MASK                       (0xFFFFU)                                           /*!< I2C_SCLL.SCLL Mask                      */
#define I2C_SCLL_SCLL_SHIFT                      (0U)                                                /*!< I2C_SCLL.SCLL Position                  */
#define I2C_SCLL_SCLL(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< I2C_SCLL.SCLL Field                     */
/* ------- CONCLR Bit Fields                        ------ */
#define I2C_CONCLR_AAC_MASK                      (0x4U)                                              /*!< I2C_CONCLR.AAC Mask                     */
#define I2C_CONCLR_AAC_SHIFT                     (2U)                                                /*!< I2C_CONCLR.AAC Position                 */
#define I2C_CONCLR_AAC(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< I2C_CONCLR.AAC Field                    */
#define I2C_CONCLR_SIC_MASK                      (0x8U)                                              /*!< I2C_CONCLR.SIC Mask                     */
#define I2C_CONCLR_SIC_SHIFT                     (3U)                                                /*!< I2C_CONCLR.SIC Position                 */
#define I2C_CONCLR_SIC(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< I2C_CONCLR.SIC Field                    */
#define I2C_CONCLR_STAC_MASK                     (0x20U)                                             /*!< I2C_CONCLR.STAC Mask                    */
#define I2C_CONCLR_STAC_SHIFT                    (5U)                                                /*!< I2C_CONCLR.STAC Position                */
#define I2C_CONCLR_STAC(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< I2C_CONCLR.STAC Field                   */
#define I2C_CONCLR_I2ENC_MASK                    (0x40U)                                             /*!< I2C_CONCLR.I2ENC Mask                   */
#define I2C_CONCLR_I2ENC_SHIFT                   (6U)                                                /*!< I2C_CONCLR.I2ENC Position               */
#define I2C_CONCLR_I2ENC(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< I2C_CONCLR.I2ENC Field                  */
/* ------- MMCTRL Bit Fields                        ------ */
#define I2C_MMCTRL_MM_ENA_MASK                   (0x1U)                                              /*!< I2C_MMCTRL.MM_ENA Mask                  */
#define I2C_MMCTRL_MM_ENA_SHIFT                  (0U)                                                /*!< I2C_MMCTRL.MM_ENA Position              */
#define I2C_MMCTRL_MM_ENA(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< I2C_MMCTRL.MM_ENA Field                 */
#define I2C_MMCTRL_ENA_SCL_MASK                  (0x2U)                                              /*!< I2C_MMCTRL.ENA_SCL Mask                 */
#define I2C_MMCTRL_ENA_SCL_SHIFT                 (1U)                                                /*!< I2C_MMCTRL.ENA_SCL Position             */
#define I2C_MMCTRL_ENA_SCL(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< I2C_MMCTRL.ENA_SCL Field                */
#define I2C_MMCTRL_MATCH_ALL_MASK                (0x4U)                                              /*!< I2C_MMCTRL.MATCH_ALL Mask               */
#define I2C_MMCTRL_MATCH_ALL_SHIFT               (2U)                                                /*!< I2C_MMCTRL.MATCH_ALL Position           */
#define I2C_MMCTRL_MATCH_ALL(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< I2C_MMCTRL.MATCH_ALL Field              */
/* ------- ADR1 Bit Fields                          ------ */
#define I2C_ADR1_GC_MASK                         (0x1U)                                              /*!< I2C_ADR1.GC Mask                        */
#define I2C_ADR1_GC_SHIFT                        (0U)                                                /*!< I2C_ADR1.GC Position                    */
#define I2C_ADR1_GC(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< I2C_ADR1.GC Field                       */
#define I2C_ADR1_Address_MASK                    (0xFEU)                                             /*!< I2C_ADR1.Address Mask                   */
#define I2C_ADR1_Address_SHIFT                   (1U)                                                /*!< I2C_ADR1.Address Position               */
#define I2C_ADR1_Address(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< I2C_ADR1.Address Field                  */
/* ------- ADR2 Bit Fields                          ------ */
#define I2C_ADR2_GC_MASK                         (0x1U)                                              /*!< I2C_ADR2.GC Mask                        */
#define I2C_ADR2_GC_SHIFT                        (0U)                                                /*!< I2C_ADR2.GC Position                    */
#define I2C_ADR2_GC(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< I2C_ADR2.GC Field                       */
#define I2C_ADR2_Address_MASK                    (0xFEU)                                             /*!< I2C_ADR2.Address Mask                   */
#define I2C_ADR2_Address_SHIFT                   (1U)                                                /*!< I2C_ADR2.Address Position               */
#define I2C_ADR2_Address(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< I2C_ADR2.Address Field                  */
/* ------- ADR3 Bit Fields                          ------ */
#define I2C_ADR3_GC_MASK                         (0x1U)                                              /*!< I2C_ADR3.GC Mask                        */
#define I2C_ADR3_GC_SHIFT                        (0U)                                                /*!< I2C_ADR3.GC Position                    */
#define I2C_ADR3_GC(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< I2C_ADR3.GC Field                       */
#define I2C_ADR3_Address_MASK                    (0xFEU)                                             /*!< I2C_ADR3.Address Mask                   */
#define I2C_ADR3_Address_SHIFT                   (1U)                                                /*!< I2C_ADR3.Address Position               */
#define I2C_ADR3_Address(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< I2C_ADR3.Address Field                  */
/* ------- DATA_BUFFER Bit Fields                   ------ */
#define I2C_DATA_BUFFER_Data_MASK                (0xFFU)                                             /*!< I2C_DATA_BUFFER.Data Mask               */
#define I2C_DATA_BUFFER_Data_SHIFT               (0U)                                                /*!< I2C_DATA_BUFFER.Data Position           */
#define I2C_DATA_BUFFER_Data(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< I2C_DATA_BUFFER.Data Field              */
/* ------- MASK0 Bit Fields                         ------ */
#define I2C_MASK0_MASK_MASK                      (0xFEU)                                             /*!< I2C_MASK0.MASK Mask                     */
#define I2C_MASK0_MASK_SHIFT                     (1U)                                                /*!< I2C_MASK0.MASK Position                 */
#define I2C_MASK0_MASK(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< I2C_MASK0.MASK Field                    */
/* ------- MASK1 Bit Fields                         ------ */
#define I2C_MASK1_MASK_MASK                      (0xFEU)                                             /*!< I2C_MASK1.MASK Mask                     */
#define I2C_MASK1_MASK_SHIFT                     (1U)                                                /*!< I2C_MASK1.MASK Position                 */
#define I2C_MASK1_MASK(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< I2C_MASK1.MASK Field                    */
/* ------- MASK2 Bit Fields                         ------ */
#define I2C_MASK2_MASK_MASK                      (0xFEU)                                             /*!< I2C_MASK2.MASK Mask                     */
#define I2C_MASK2_MASK_SHIFT                     (1U)                                                /*!< I2C_MASK2.MASK Position                 */
#define I2C_MASK2_MASK(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< I2C_MASK2.MASK Field                    */
/* ------- MASK3 Bit Fields                         ------ */
#define I2C_MASK3_MASK_MASK                      (0xFEU)                                             /*!< I2C_MASK3.MASK Mask                     */
#define I2C_MASK3_MASK_SHIFT                     (1U)                                                /*!< I2C_MASK3.MASK Position                 */
#define I2C_MASK3_MASK(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< I2C_MASK3.MASK Field                    */
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
/* ================           IOCON (file:IOCON_LPC11xx)           ================ */
/* ================================================================================ */

/**
 * @brief LPC1100XL series: I/O configuration
 */
/**
* @addtogroup IOCON_structs_GROUP IOCON struct
* @brief Struct for IOCON
* @{
*/
typedef struct {                                /*       IOCON Structure                                              */
   __IO uint32_t  IOCON_PIO2_6;                 /**< 0000: I/O configuration for pin PIO2_6/ CT32B0_MAT1                */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  IOCON_PIO2_0;                 /**< 0008: I/O configuration for pin PIO2_0/DTR/SSEL1                   */
   __IO uint32_t  IOCON_RESET_PIO0_0;           /**< 000C: I/O configuration for pin RESET/PIO0_0                       */
   __IO uint32_t  IOCON_PIO0_1;                 /**< 0010: I/O configuration for pin PIO0_1/CLKOUT/CT32B0_MAT2          */
   __IO uint32_t  IOCON_PIO1_8;                 /**< 0014: I/O configuration for pin PIO1_8/CT16B1_CAP0                 */
   __IO uint32_t  IOCON_SSEL1_LOC;              /**< 0018: SSEL1 pin location select register                           */
   __IO uint32_t  IOCON_PIO0_2;                 /**< 001C: I/O configuration for pin PIO0_2/SSEL0/CT16B0_CAP0           */
   __IO uint32_t  IOCON_PIO2_7;                 /**< 0020: I/O configuration for pin PIO2_7/ CT32B0_MAT2/RXD            */
   __IO uint32_t  IOCON_PIO2_8;                 /**< 0024: I/O configuration for pin PIO2_8/ CT32B0_MAT3/TXD            */
   __IO uint32_t  IOCON_PIO2_1;                 /**< 0028: I/O configuration for pin PIO2_1/DSR/SCK1                    */
   __IO uint32_t  IOCON_PIO0_3;                 /**< 002C: I/O configuration for pin PIO0_3                             */
   __IO uint32_t  IOCON_PIO0_4;                 /**< 0030: I/O configuration for pin PIO0_4/SCL                         */
   __IO uint32_t  IOCON_PIO0_5;                 /**< 0034: I/O configuration for pin PIO0_5/SDA                         */
   __IO uint32_t  IOCON_PIO1_9;                 /**< 0038: I/O configuration for pin PIO1_9/CT16B1_MAT0/ MOSI1          */
   __IO uint32_t  IOCON_PIO3_4;                 /**< 003C: I/O configuration for pin PIO3_4/ CT16B0_CAP1/RXD            */
   __IO uint32_t  IOCON_PIO2_4;                 /**< 0040: I/O configuration for pin PIO2_4/ CT16B1_MAT1/ SSEL1         */
   __IO uint32_t  IOCON_PIO2_5;                 /**< 0044: I/O configuration for pin PIO2_5/ CT32B0_MAT0                */
   __IO uint32_t  IOCON_PIO3_5;                 /**< 0048: I/O configuration for pin PIO3_5/ CT16B1_CAP1/TXD            */
   __IO uint32_t  IOCON_PIO0_6;                 /**< 004C: I/O configuration for pin PIO0_6/SCK0                        */
   __IO uint32_t  IOCON_PIO0_7;                 /**< 0050: I/O configuration for pin PIO0_7/CTS                         */
   __IO uint32_t  IOCON_PIO2_9;                 /**< 0054: I/O configuration for pin PIO2_9/ CT32B0_CAP0                */
   __IO uint32_t  IOCON_PIO2_10;                /**< 0058: I/O configuration for pin PIO2_10                            */
   __IO uint32_t  IOCON_PIO2_2;                 /**< 005C: I/O configuration for pin PIO2_2/DCD/MISO1                   */
   __IO uint32_t  IOCON_PIO0_8;                 /**< 0060: I/O configuration for pin PIO0_8/MISO0/CT16B0_MAT0           */
   __IO uint32_t  IOCON_PIO0_9;                 /**< 0064: I/O configuration for pin PIO0_9/MOSI0/CT16B0_MAT1           */
   __IO uint32_t  IOCON_SWCLK_PIO0_10;          /**< 0068: I/O configuration for pin SWCLK/PIO0_10/ SCK0/CT16B0_MAT2    */
   __IO uint32_t  IOCON_PIO1_10;                /**< 006C: I/O configuration for pin PIO1_10/AD6/CT16B1_MAT1/ MISO1     */
   __IO uint32_t  IOCON_PIO2_11;                /**< 0070: I/O configuration for pin PIO2_11/SCK0/ CT32B0_CAP1          */
   __IO uint32_t  IOCON_R_PIO0_11;              /**< 0074: I/O configuration for pin R/PIO0_11/AD0/CT32B0_MAT3          */
   __IO uint32_t  IOCON_R_PIO1_0;               /**< 0078: I/O configuration for pin R/PIO1_0/AD1/CT32B1_CAP0           */
   __IO uint32_t  IOCON_R_PIO1_1;               /**< 007C: I/O configuration for pin R/PIO1_1/AD2/CT32B1_MAT0           */
   __IO uint32_t  IOCON_R_PIO1_2;               /**< 0080: I/O configuration for pin R/PIO1_2/AD3/CT32B1_MAT1           */
   __IO uint32_t  IOCON_PIO3_0;                 /**< 0084: I/O configuration for pin PIO3_0/DTR/CT16B0_MAT0/TXD         */
   __IO uint32_t  IOCON_PIO3_1;                 /**< 0088: I/O configuration for pin PIO3_1/DSR/CT16B0_MAT1/RXD         */
   __IO uint32_t  IOCON_PIO2_3;                 /**< 008C: I/O configuration for pin PIO2_3/RI/MOSI1                    */
   __IO uint32_t  IOCON_SWDIO_PIO1_3;           /**< 0090: I/O configuration for pin SWDIO/PIO1_3/AD4/CT32B1_MAT2       */
   __IO uint32_t  IOCON_PIO1_4;                 /**< 0094: I/O configuration for pin PIO1_4/AD5/CT32B1_MAT3             */
   __IO uint32_t  IOCON_PIO1_11;                /**< 0098: I/O configuration for pin PIO1_11/AD7/CT32B1_CAP1            */
   __IO uint32_t  IOCON_PIO3_2;                 /**< 009C: I/O configuration for pin PIO3_2/DCD/ CT16B0_MAT2/SCK1       */
   __IO uint32_t  IOCON_PIO1_5;                 /**< 00A0: I/O configuration for pin PIO1_5/RTS/CT32B0_CAP0             */
   __IO uint32_t  IOCON_PIO1_6;                 /**< 00A4: I/O configuration for pin PIO1_6/RXD/CT32B0_MAT0             */
   __IO uint32_t  IOCON_PIO1_7;                 /**< 00A8: I/O configuration for pin PIO1_7/TXD/CT32B0_MAT1             */
   __IO uint32_t  IOCON_PIO3_3;                 /**< 00AC: I/O configuration for pin PIO3_3/RI/ CT16B0_CAP0             */
   __IO uint32_t  IOCON_SCK0_LOC;               /**< 00B0: SCK0 pin location select register                            */
   __IO uint32_t  IOCON_DSR_LOC;                /**< 00B4: DSR pin location select register                             */
   __IO uint32_t  IOCON_DCD_LOC;                /**< 00B8: DCD pin location select register                             */
   __IO uint32_t  IOCON_RI_LOC;                 /**< 00BC: RI pin location select register                              */
   __IO uint32_t  IOCON_CT16B0_CAP0_LOC;        /**< 00C0: CT16B0_CAP0 pin location select register                     */
   __IO uint32_t  IOCON_SCK1_LOC;               /**< 00C4: SCK1 pin location select register                            */
   __IO uint32_t  IOCON_MISO1_LOC;              /**< 00C8: MISO1 pin location select register                           */
   __IO uint32_t  IOCON_MOSI1_LOC;              /**< 00CC: MOSI1 pin location select register                           */
   __IO uint32_t  IOCON_CT32B0_CAP0_LOC;        /**< 00D0: CT32B0_CAP0 pin location select register                     */
   __IO uint32_t  IOCON_RXD_LOC;                /**< 00D4: RXD pin location select register                             */
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
/* ------- IOCON_PIO2_6 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_6_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_6.FUNC Mask            */
#define IOCON_IOCON_PIO2_6_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_6.FUNC Position        */
#define IOCON_IOCON_PIO2_6_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_6.FUNC Field           */
#define IOCON_IOCON_PIO2_6_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_6.MODE Mask            */
#define IOCON_IOCON_PIO2_6_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_6.MODE Position        */
#define IOCON_IOCON_PIO2_6_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_6.MODE Field           */
#define IOCON_IOCON_PIO2_6_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_6.HYS Mask             */
#define IOCON_IOCON_PIO2_6_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_6.HYS Position         */
#define IOCON_IOCON_PIO2_6_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_6.HYS Field            */
#define IOCON_IOCON_PIO2_6_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_6.OD Mask              */
#define IOCON_IOCON_PIO2_6_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_6.OD Position          */
#define IOCON_IOCON_PIO2_6_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_6.OD Field             */
/* ------- IOCON_PIO2_0 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_0_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_0.FUNC Mask            */
#define IOCON_IOCON_PIO2_0_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_0.FUNC Position        */
#define IOCON_IOCON_PIO2_0_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_0.FUNC Field           */
#define IOCON_IOCON_PIO2_0_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_0.MODE Mask            */
#define IOCON_IOCON_PIO2_0_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_0.MODE Position        */
#define IOCON_IOCON_PIO2_0_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_0.MODE Field           */
#define IOCON_IOCON_PIO2_0_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_0.HYS Mask             */
#define IOCON_IOCON_PIO2_0_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_0.HYS Position         */
#define IOCON_IOCON_PIO2_0_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_0.HYS Field            */
#define IOCON_IOCON_PIO2_0_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_0.OD Mask              */
#define IOCON_IOCON_PIO2_0_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_0.OD Position          */
#define IOCON_IOCON_PIO2_0_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_0.OD Field             */
/* ------- IOCON_RESET_PIO0_0 Bit Fields            ------ */
#define IOCON_IOCON_RESET_PIO0_0_FUNC_MASK       (0x7U)                                              /*!< IOCON_IOCON_RESET_PIO0_0.FUNC Mask      */
#define IOCON_IOCON_RESET_PIO0_0_FUNC_SHIFT      (0U)                                                /*!< IOCON_IOCON_RESET_PIO0_0.FUNC Position  */
#define IOCON_IOCON_RESET_PIO0_0_FUNC(x)         (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_RESET_PIO0_0.FUNC Field     */
#define IOCON_IOCON_RESET_PIO0_0_MODE_MASK       (0x18U)                                             /*!< IOCON_IOCON_RESET_PIO0_0.MODE Mask      */
#define IOCON_IOCON_RESET_PIO0_0_MODE_SHIFT      (3U)                                                /*!< IOCON_IOCON_RESET_PIO0_0.MODE Position  */
#define IOCON_IOCON_RESET_PIO0_0_MODE(x)         (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_RESET_PIO0_0.MODE Field     */
#define IOCON_IOCON_RESET_PIO0_0_HYS_MASK        (0x20U)                                             /*!< IOCON_IOCON_RESET_PIO0_0.HYS Mask       */
#define IOCON_IOCON_RESET_PIO0_0_HYS_SHIFT       (5U)                                                /*!< IOCON_IOCON_RESET_PIO0_0.HYS Position   */
#define IOCON_IOCON_RESET_PIO0_0_HYS(x)          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_RESET_PIO0_0.HYS Field      */
#define IOCON_IOCON_RESET_PIO0_0_OD_MASK         (0x400U)                                            /*!< IOCON_IOCON_RESET_PIO0_0.OD Mask        */
#define IOCON_IOCON_RESET_PIO0_0_OD_SHIFT        (10U)                                               /*!< IOCON_IOCON_RESET_PIO0_0.OD Position    */
#define IOCON_IOCON_RESET_PIO0_0_OD(x)           (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_RESET_PIO0_0.OD Field       */
/* ------- IOCON_PIO0_1 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_1_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_1.FUNC Mask            */
#define IOCON_IOCON_PIO0_1_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_1.FUNC Position        */
#define IOCON_IOCON_PIO0_1_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_1.FUNC Field           */
#define IOCON_IOCON_PIO0_1_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO0_1.MODE Mask            */
#define IOCON_IOCON_PIO0_1_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO0_1.MODE Position        */
#define IOCON_IOCON_PIO0_1_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO0_1.MODE Field           */
#define IOCON_IOCON_PIO0_1_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO0_1.HYS Mask             */
#define IOCON_IOCON_PIO0_1_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO0_1.HYS Position         */
#define IOCON_IOCON_PIO0_1_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO0_1.HYS Field            */
#define IOCON_IOCON_PIO0_1_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO0_1.OD Mask              */
#define IOCON_IOCON_PIO0_1_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO0_1.OD Position          */
#define IOCON_IOCON_PIO0_1_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO0_1.OD Field             */
/* ------- IOCON_PIO1_8 Bit Fields                  ------ */
#define IOCON_IOCON_PIO1_8_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO1_8.FUNC Mask            */
#define IOCON_IOCON_PIO1_8_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO1_8.FUNC Position        */
#define IOCON_IOCON_PIO1_8_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO1_8.FUNC Field           */
#define IOCON_IOCON_PIO1_8_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO1_8.MODE Mask            */
#define IOCON_IOCON_PIO1_8_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO1_8.MODE Position        */
#define IOCON_IOCON_PIO1_8_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO1_8.MODE Field           */
#define IOCON_IOCON_PIO1_8_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO1_8.HYS Mask             */
#define IOCON_IOCON_PIO1_8_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO1_8.HYS Position         */
#define IOCON_IOCON_PIO1_8_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO1_8.HYS Field            */
#define IOCON_IOCON_PIO1_8_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO1_8.OD Mask              */
#define IOCON_IOCON_PIO1_8_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO1_8.OD Position          */
#define IOCON_IOCON_PIO1_8_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO1_8.OD Field             */
/* ------- IOCON_SSEL1_LOC Bit Fields               ------ */
#define IOCON_IOCON_SSEL1_LOC_SSEL1LOC_MASK      (0x3U)                                              /*!< IOCON_IOCON_SSEL1_LOC.SSEL1LOC Mask     */
#define IOCON_IOCON_SSEL1_LOC_SSEL1LOC_SHIFT     (0U)                                                /*!< IOCON_IOCON_SSEL1_LOC.SSEL1LOC Position */
#define IOCON_IOCON_SSEL1_LOC_SSEL1LOC(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_SSEL1_LOC.SSEL1LOC Field    */
/* ------- IOCON_PIO0_2 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_2_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_2.FUNC Mask            */
#define IOCON_IOCON_PIO0_2_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_2.FUNC Position        */
#define IOCON_IOCON_PIO0_2_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_2.FUNC Field           */
#define IOCON_IOCON_PIO0_2_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO0_2.MODE Mask            */
#define IOCON_IOCON_PIO0_2_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO0_2.MODE Position        */
#define IOCON_IOCON_PIO0_2_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO0_2.MODE Field           */
#define IOCON_IOCON_PIO0_2_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO0_2.HYS Mask             */
#define IOCON_IOCON_PIO0_2_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO0_2.HYS Position         */
#define IOCON_IOCON_PIO0_2_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO0_2.HYS Field            */
#define IOCON_IOCON_PIO0_2_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO0_2.OD Mask              */
#define IOCON_IOCON_PIO0_2_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO0_2.OD Position          */
#define IOCON_IOCON_PIO0_2_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO0_2.OD Field             */
/* ------- IOCON_PIO2_7 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_7_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_7.FUNC Mask            */
#define IOCON_IOCON_PIO2_7_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_7.FUNC Position        */
#define IOCON_IOCON_PIO2_7_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_7.FUNC Field           */
#define IOCON_IOCON_PIO2_7_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_7.MODE Mask            */
#define IOCON_IOCON_PIO2_7_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_7.MODE Position        */
#define IOCON_IOCON_PIO2_7_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_7.MODE Field           */
#define IOCON_IOCON_PIO2_7_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_7.HYS Mask             */
#define IOCON_IOCON_PIO2_7_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_7.HYS Position         */
#define IOCON_IOCON_PIO2_7_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_7.HYS Field            */
#define IOCON_IOCON_PIO2_7_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_7.OD Mask              */
#define IOCON_IOCON_PIO2_7_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_7.OD Position          */
#define IOCON_IOCON_PIO2_7_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_7.OD Field             */
/* ------- IOCON_PIO2_8 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_8_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_8.FUNC Mask            */
#define IOCON_IOCON_PIO2_8_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_8.FUNC Position        */
#define IOCON_IOCON_PIO2_8_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_8.FUNC Field           */
#define IOCON_IOCON_PIO2_8_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_8.MODE Mask            */
#define IOCON_IOCON_PIO2_8_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_8.MODE Position        */
#define IOCON_IOCON_PIO2_8_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_8.MODE Field           */
#define IOCON_IOCON_PIO2_8_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_8.HYS Mask             */
#define IOCON_IOCON_PIO2_8_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_8.HYS Position         */
#define IOCON_IOCON_PIO2_8_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_8.HYS Field            */
#define IOCON_IOCON_PIO2_8_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_8.OD Mask              */
#define IOCON_IOCON_PIO2_8_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_8.OD Position          */
#define IOCON_IOCON_PIO2_8_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_8.OD Field             */
/* ------- IOCON_PIO2_1 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_1_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_1.FUNC Mask            */
#define IOCON_IOCON_PIO2_1_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_1.FUNC Position        */
#define IOCON_IOCON_PIO2_1_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_1.FUNC Field           */
#define IOCON_IOCON_PIO2_1_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_1.MODE Mask            */
#define IOCON_IOCON_PIO2_1_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_1.MODE Position        */
#define IOCON_IOCON_PIO2_1_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_1.MODE Field           */
#define IOCON_IOCON_PIO2_1_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_1.HYS Mask             */
#define IOCON_IOCON_PIO2_1_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_1.HYS Position         */
#define IOCON_IOCON_PIO2_1_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_1.HYS Field            */
#define IOCON_IOCON_PIO2_1_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_1.OD Mask              */
#define IOCON_IOCON_PIO2_1_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_1.OD Position          */
#define IOCON_IOCON_PIO2_1_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_1.OD Field             */
/* ------- IOCON_PIO0_3 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_3_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_3.FUNC Mask            */
#define IOCON_IOCON_PIO0_3_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_3.FUNC Position        */
#define IOCON_IOCON_PIO0_3_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_3.FUNC Field           */
#define IOCON_IOCON_PIO0_3_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO0_3.MODE Mask            */
#define IOCON_IOCON_PIO0_3_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO0_3.MODE Position        */
#define IOCON_IOCON_PIO0_3_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO0_3.MODE Field           */
#define IOCON_IOCON_PIO0_3_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO0_3.HYS Mask             */
#define IOCON_IOCON_PIO0_3_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO0_3.HYS Position         */
#define IOCON_IOCON_PIO0_3_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO0_3.HYS Field            */
#define IOCON_IOCON_PIO0_3_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO0_3.OD Mask              */
#define IOCON_IOCON_PIO0_3_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO0_3.OD Position          */
#define IOCON_IOCON_PIO0_3_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO0_3.OD Field             */
/* ------- IOCON_PIO0_4 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_4_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_4.FUNC Mask            */
#define IOCON_IOCON_PIO0_4_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_4.FUNC Position        */
#define IOCON_IOCON_PIO0_4_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_4.FUNC Field           */
#define IOCON_IOCON_PIO0_4_I2CMODE_MASK          (0x300U)                                            /*!< IOCON_IOCON_PIO0_4.I2CMODE Mask         */
#define IOCON_IOCON_PIO0_4_I2CMODE_SHIFT         (8U)                                                /*!< IOCON_IOCON_PIO0_4.I2CMODE Position     */
#define IOCON_IOCON_PIO0_4_I2CMODE(x)            (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< IOCON_IOCON_PIO0_4.I2CMODE Field        */
/* ------- IOCON_PIO0_5 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_5_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_5.FUNC Mask            */
#define IOCON_IOCON_PIO0_5_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_5.FUNC Position        */
#define IOCON_IOCON_PIO0_5_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_5.FUNC Field           */
#define IOCON_IOCON_PIO0_5_I2CMODE_MASK          (0x300U)                                            /*!< IOCON_IOCON_PIO0_5.I2CMODE Mask         */
#define IOCON_IOCON_PIO0_5_I2CMODE_SHIFT         (8U)                                                /*!< IOCON_IOCON_PIO0_5.I2CMODE Position     */
#define IOCON_IOCON_PIO0_5_I2CMODE(x)            (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< IOCON_IOCON_PIO0_5.I2CMODE Field        */
/* ------- IOCON_PIO1_9 Bit Fields                  ------ */
#define IOCON_IOCON_PIO1_9_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO1_9.FUNC Mask            */
#define IOCON_IOCON_PIO1_9_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO1_9.FUNC Position        */
#define IOCON_IOCON_PIO1_9_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO1_9.FUNC Field           */
#define IOCON_IOCON_PIO1_9_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO1_9.MODE Mask            */
#define IOCON_IOCON_PIO1_9_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO1_9.MODE Position        */
#define IOCON_IOCON_PIO1_9_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO1_9.MODE Field           */
#define IOCON_IOCON_PIO1_9_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO1_9.HYS Mask             */
#define IOCON_IOCON_PIO1_9_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO1_9.HYS Position         */
#define IOCON_IOCON_PIO1_9_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO1_9.HYS Field            */
#define IOCON_IOCON_PIO1_9_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO1_9.OD Mask              */
#define IOCON_IOCON_PIO1_9_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO1_9.OD Position          */
#define IOCON_IOCON_PIO1_9_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO1_9.OD Field             */
/* ------- IOCON_PIO3_4 Bit Fields                  ------ */
#define IOCON_IOCON_PIO3_4_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO3_4.FUNC Mask            */
#define IOCON_IOCON_PIO3_4_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO3_4.FUNC Position        */
#define IOCON_IOCON_PIO3_4_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO3_4.FUNC Field           */
#define IOCON_IOCON_PIO3_4_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO3_4.MODE Mask            */
#define IOCON_IOCON_PIO3_4_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO3_4.MODE Position        */
#define IOCON_IOCON_PIO3_4_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO3_4.MODE Field           */
#define IOCON_IOCON_PIO3_4_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO3_4.HYS Mask             */
#define IOCON_IOCON_PIO3_4_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO3_4.HYS Position         */
#define IOCON_IOCON_PIO3_4_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO3_4.HYS Field            */
#define IOCON_IOCON_PIO3_4_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO3_4.OD Mask              */
#define IOCON_IOCON_PIO3_4_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO3_4.OD Position          */
#define IOCON_IOCON_PIO3_4_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO3_4.OD Field             */
/* ------- IOCON_PIO2_4 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_4_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_4.FUNC Mask            */
#define IOCON_IOCON_PIO2_4_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_4.FUNC Position        */
#define IOCON_IOCON_PIO2_4_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_4.FUNC Field           */
#define IOCON_IOCON_PIO2_4_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_4.MODE Mask            */
#define IOCON_IOCON_PIO2_4_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_4.MODE Position        */
#define IOCON_IOCON_PIO2_4_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_4.MODE Field           */
#define IOCON_IOCON_PIO2_4_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_4.HYS Mask             */
#define IOCON_IOCON_PIO2_4_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_4.HYS Position         */
#define IOCON_IOCON_PIO2_4_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_4.HYS Field            */
#define IOCON_IOCON_PIO2_4_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_4.OD Mask              */
#define IOCON_IOCON_PIO2_4_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_4.OD Position          */
#define IOCON_IOCON_PIO2_4_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_4.OD Field             */
/* ------- IOCON_PIO2_5 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_5_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_5.FUNC Mask            */
#define IOCON_IOCON_PIO2_5_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_5.FUNC Position        */
#define IOCON_IOCON_PIO2_5_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_5.FUNC Field           */
#define IOCON_IOCON_PIO2_5_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_5.MODE Mask            */
#define IOCON_IOCON_PIO2_5_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_5.MODE Position        */
#define IOCON_IOCON_PIO2_5_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_5.MODE Field           */
#define IOCON_IOCON_PIO2_5_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_5.HYS Mask             */
#define IOCON_IOCON_PIO2_5_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_5.HYS Position         */
#define IOCON_IOCON_PIO2_5_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_5.HYS Field            */
#define IOCON_IOCON_PIO2_5_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_5.OD Mask              */
#define IOCON_IOCON_PIO2_5_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_5.OD Position          */
#define IOCON_IOCON_PIO2_5_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_5.OD Field             */
/* ------- IOCON_PIO3_5 Bit Fields                  ------ */
#define IOCON_IOCON_PIO3_5_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO3_5.FUNC Mask            */
#define IOCON_IOCON_PIO3_5_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO3_5.FUNC Position        */
#define IOCON_IOCON_PIO3_5_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO3_5.FUNC Field           */
#define IOCON_IOCON_PIO3_5_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO3_5.MODE Mask            */
#define IOCON_IOCON_PIO3_5_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO3_5.MODE Position        */
#define IOCON_IOCON_PIO3_5_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO3_5.MODE Field           */
#define IOCON_IOCON_PIO3_5_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO3_5.HYS Mask             */
#define IOCON_IOCON_PIO3_5_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO3_5.HYS Position         */
#define IOCON_IOCON_PIO3_5_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO3_5.HYS Field            */
#define IOCON_IOCON_PIO3_5_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO3_5.OD Mask              */
#define IOCON_IOCON_PIO3_5_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO3_5.OD Position          */
#define IOCON_IOCON_PIO3_5_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO3_5.OD Field             */
/* ------- IOCON_PIO0_6 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_6_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_6.FUNC Mask            */
#define IOCON_IOCON_PIO0_6_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_6.FUNC Position        */
#define IOCON_IOCON_PIO0_6_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_6.FUNC Field           */
#define IOCON_IOCON_PIO0_6_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO0_6.MODE Mask            */
#define IOCON_IOCON_PIO0_6_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO0_6.MODE Position        */
#define IOCON_IOCON_PIO0_6_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO0_6.MODE Field           */
#define IOCON_IOCON_PIO0_6_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO0_6.HYS Mask             */
#define IOCON_IOCON_PIO0_6_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO0_6.HYS Position         */
#define IOCON_IOCON_PIO0_6_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO0_6.HYS Field            */
#define IOCON_IOCON_PIO0_6_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO0_6.OD Mask              */
#define IOCON_IOCON_PIO0_6_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO0_6.OD Position          */
#define IOCON_IOCON_PIO0_6_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO0_6.OD Field             */
/* ------- IOCON_PIO0_7 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_7_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_7.FUNC Mask            */
#define IOCON_IOCON_PIO0_7_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_7.FUNC Position        */
#define IOCON_IOCON_PIO0_7_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_7.FUNC Field           */
#define IOCON_IOCON_PIO0_7_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO0_7.MODE Mask            */
#define IOCON_IOCON_PIO0_7_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO0_7.MODE Position        */
#define IOCON_IOCON_PIO0_7_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO0_7.MODE Field           */
#define IOCON_IOCON_PIO0_7_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO0_7.HYS Mask             */
#define IOCON_IOCON_PIO0_7_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO0_7.HYS Position         */
#define IOCON_IOCON_PIO0_7_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO0_7.HYS Field            */
#define IOCON_IOCON_PIO0_7_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO0_7.OD Mask              */
#define IOCON_IOCON_PIO0_7_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO0_7.OD Position          */
#define IOCON_IOCON_PIO0_7_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO0_7.OD Field             */
/* ------- IOCON_PIO2_9 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_9_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_9.FUNC Mask            */
#define IOCON_IOCON_PIO2_9_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_9.FUNC Position        */
#define IOCON_IOCON_PIO2_9_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_9.FUNC Field           */
#define IOCON_IOCON_PIO2_9_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_9.MODE Mask            */
#define IOCON_IOCON_PIO2_9_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_9.MODE Position        */
#define IOCON_IOCON_PIO2_9_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_9.MODE Field           */
#define IOCON_IOCON_PIO2_9_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_9.HYS Mask             */
#define IOCON_IOCON_PIO2_9_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_9.HYS Position         */
#define IOCON_IOCON_PIO2_9_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_9.HYS Field            */
#define IOCON_IOCON_PIO2_9_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_9.OD Mask              */
#define IOCON_IOCON_PIO2_9_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_9.OD Position          */
#define IOCON_IOCON_PIO2_9_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_9.OD Field             */
/* ------- IOCON_PIO2_10 Bit Fields                 ------ */
#define IOCON_IOCON_PIO2_10_FUNC_MASK            (0x7U)                                              /*!< IOCON_IOCON_PIO2_10.FUNC Mask           */
#define IOCON_IOCON_PIO2_10_FUNC_SHIFT           (0U)                                                /*!< IOCON_IOCON_PIO2_10.FUNC Position       */
#define IOCON_IOCON_PIO2_10_FUNC(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_10.FUNC Field          */
#define IOCON_IOCON_PIO2_10_MODE_MASK            (0x18U)                                             /*!< IOCON_IOCON_PIO2_10.MODE Mask           */
#define IOCON_IOCON_PIO2_10_MODE_SHIFT           (3U)                                                /*!< IOCON_IOCON_PIO2_10.MODE Position       */
#define IOCON_IOCON_PIO2_10_MODE(x)              (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_10.MODE Field          */
#define IOCON_IOCON_PIO2_10_HYS_MASK             (0x20U)                                             /*!< IOCON_IOCON_PIO2_10.HYS Mask            */
#define IOCON_IOCON_PIO2_10_HYS_SHIFT            (5U)                                                /*!< IOCON_IOCON_PIO2_10.HYS Position        */
#define IOCON_IOCON_PIO2_10_HYS(x)               (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_10.HYS Field           */
#define IOCON_IOCON_PIO2_10_OD_MASK              (0x400U)                                            /*!< IOCON_IOCON_PIO2_10.OD Mask             */
#define IOCON_IOCON_PIO2_10_OD_SHIFT             (10U)                                               /*!< IOCON_IOCON_PIO2_10.OD Position         */
#define IOCON_IOCON_PIO2_10_OD(x)                (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_10.OD Field            */
/* ------- IOCON_PIO2_2 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_2_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_2.FUNC Mask            */
#define IOCON_IOCON_PIO2_2_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_2.FUNC Position        */
#define IOCON_IOCON_PIO2_2_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_2.FUNC Field           */
#define IOCON_IOCON_PIO2_2_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_2.MODE Mask            */
#define IOCON_IOCON_PIO2_2_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_2.MODE Position        */
#define IOCON_IOCON_PIO2_2_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_2.MODE Field           */
#define IOCON_IOCON_PIO2_2_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_2.HYS Mask             */
#define IOCON_IOCON_PIO2_2_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_2.HYS Position         */
#define IOCON_IOCON_PIO2_2_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_2.HYS Field            */
#define IOCON_IOCON_PIO2_2_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_2.OD Mask              */
#define IOCON_IOCON_PIO2_2_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_2.OD Position          */
#define IOCON_IOCON_PIO2_2_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_2.OD Field             */
/* ------- IOCON_PIO0_8 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_8_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_8.FUNC Mask            */
#define IOCON_IOCON_PIO0_8_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_8.FUNC Position        */
#define IOCON_IOCON_PIO0_8_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_8.FUNC Field           */
#define IOCON_IOCON_PIO0_8_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO0_8.MODE Mask            */
#define IOCON_IOCON_PIO0_8_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO0_8.MODE Position        */
#define IOCON_IOCON_PIO0_8_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO0_8.MODE Field           */
#define IOCON_IOCON_PIO0_8_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO0_8.HYS Mask             */
#define IOCON_IOCON_PIO0_8_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO0_8.HYS Position         */
#define IOCON_IOCON_PIO0_8_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO0_8.HYS Field            */
#define IOCON_IOCON_PIO0_8_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO0_8.OD Mask              */
#define IOCON_IOCON_PIO0_8_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO0_8.OD Position          */
#define IOCON_IOCON_PIO0_8_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO0_8.OD Field             */
/* ------- IOCON_PIO0_9 Bit Fields                  ------ */
#define IOCON_IOCON_PIO0_9_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO0_9.FUNC Mask            */
#define IOCON_IOCON_PIO0_9_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO0_9.FUNC Position        */
#define IOCON_IOCON_PIO0_9_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO0_9.FUNC Field           */
#define IOCON_IOCON_PIO0_9_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO0_9.MODE Mask            */
#define IOCON_IOCON_PIO0_9_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO0_9.MODE Position        */
#define IOCON_IOCON_PIO0_9_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO0_9.MODE Field           */
#define IOCON_IOCON_PIO0_9_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO0_9.HYS Mask             */
#define IOCON_IOCON_PIO0_9_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO0_9.HYS Position         */
#define IOCON_IOCON_PIO0_9_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO0_9.HYS Field            */
#define IOCON_IOCON_PIO0_9_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO0_9.OD Mask              */
#define IOCON_IOCON_PIO0_9_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO0_9.OD Position          */
#define IOCON_IOCON_PIO0_9_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO0_9.OD Field             */
/* ------- IOCON_SWCLK_PIO0_10 Bit Fields           ------ */
#define IOCON_IOCON_SWCLK_PIO0_10_FUNC_MASK      (0x7U)                                              /*!< IOCON_IOCON_SWCLK_PIO0_10.FUNC Mask     */
#define IOCON_IOCON_SWCLK_PIO0_10_FUNC_SHIFT     (0U)                                                /*!< IOCON_IOCON_SWCLK_PIO0_10.FUNC Position */
#define IOCON_IOCON_SWCLK_PIO0_10_FUNC(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_SWCLK_PIO0_10.FUNC Field    */
#define IOCON_IOCON_SWCLK_PIO0_10_MODE_MASK      (0x18U)                                             /*!< IOCON_IOCON_SWCLK_PIO0_10.MODE Mask     */
#define IOCON_IOCON_SWCLK_PIO0_10_MODE_SHIFT     (3U)                                                /*!< IOCON_IOCON_SWCLK_PIO0_10.MODE Position */
#define IOCON_IOCON_SWCLK_PIO0_10_MODE(x)        (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_SWCLK_PIO0_10.MODE Field    */
#define IOCON_IOCON_SWCLK_PIO0_10_HYS_MASK       (0x20U)                                             /*!< IOCON_IOCON_SWCLK_PIO0_10.HYS Mask      */
#define IOCON_IOCON_SWCLK_PIO0_10_HYS_SHIFT      (5U)                                                /*!< IOCON_IOCON_SWCLK_PIO0_10.HYS Position  */
#define IOCON_IOCON_SWCLK_PIO0_10_HYS(x)         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_SWCLK_PIO0_10.HYS Field     */
#define IOCON_IOCON_SWCLK_PIO0_10_OD_MASK        (0x400U)                                            /*!< IOCON_IOCON_SWCLK_PIO0_10.OD Mask       */
#define IOCON_IOCON_SWCLK_PIO0_10_OD_SHIFT       (10U)                                               /*!< IOCON_IOCON_SWCLK_PIO0_10.OD Position   */
#define IOCON_IOCON_SWCLK_PIO0_10_OD(x)          (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_SWCLK_PIO0_10.OD Field      */
/* ------- IOCON_PIO1_10 Bit Fields                 ------ */
#define IOCON_IOCON_PIO1_10_FUNC_MASK            (0x7U)                                              /*!< IOCON_IOCON_PIO1_10.FUNC Mask           */
#define IOCON_IOCON_PIO1_10_FUNC_SHIFT           (0U)                                                /*!< IOCON_IOCON_PIO1_10.FUNC Position       */
#define IOCON_IOCON_PIO1_10_FUNC(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO1_10.FUNC Field          */
#define IOCON_IOCON_PIO1_10_MODE_MASK            (0x18U)                                             /*!< IOCON_IOCON_PIO1_10.MODE Mask           */
#define IOCON_IOCON_PIO1_10_MODE_SHIFT           (3U)                                                /*!< IOCON_IOCON_PIO1_10.MODE Position       */
#define IOCON_IOCON_PIO1_10_MODE(x)              (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO1_10.MODE Field          */
#define IOCON_IOCON_PIO1_10_HYS_MASK             (0x20U)                                             /*!< IOCON_IOCON_PIO1_10.HYS Mask            */
#define IOCON_IOCON_PIO1_10_HYS_SHIFT            (5U)                                                /*!< IOCON_IOCON_PIO1_10.HYS Position        */
#define IOCON_IOCON_PIO1_10_HYS(x)               (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO1_10.HYS Field           */
#define IOCON_IOCON_PIO1_10_ADMODE_MASK          (0x80U)                                             /*!< IOCON_IOCON_PIO1_10.ADMODE Mask         */
#define IOCON_IOCON_PIO1_10_ADMODE_SHIFT         (7U)                                                /*!< IOCON_IOCON_PIO1_10.ADMODE Position     */
#define IOCON_IOCON_PIO1_10_ADMODE(x)            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< IOCON_IOCON_PIO1_10.ADMODE Field        */
#define IOCON_IOCON_PIO1_10_OD_MASK              (0x400U)                                            /*!< IOCON_IOCON_PIO1_10.OD Mask             */
#define IOCON_IOCON_PIO1_10_OD_SHIFT             (10U)                                               /*!< IOCON_IOCON_PIO1_10.OD Position         */
#define IOCON_IOCON_PIO1_10_OD(x)                (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO1_10.OD Field            */
/* ------- IOCON_PIO2_11 Bit Fields                 ------ */
#define IOCON_IOCON_PIO2_11_FUNC_MASK            (0x7U)                                              /*!< IOCON_IOCON_PIO2_11.FUNC Mask           */
#define IOCON_IOCON_PIO2_11_FUNC_SHIFT           (0U)                                                /*!< IOCON_IOCON_PIO2_11.FUNC Position       */
#define IOCON_IOCON_PIO2_11_FUNC(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_11.FUNC Field          */
#define IOCON_IOCON_PIO2_11_MODE_MASK            (0x18U)                                             /*!< IOCON_IOCON_PIO2_11.MODE Mask           */
#define IOCON_IOCON_PIO2_11_MODE_SHIFT           (3U)                                                /*!< IOCON_IOCON_PIO2_11.MODE Position       */
#define IOCON_IOCON_PIO2_11_MODE(x)              (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_11.MODE Field          */
#define IOCON_IOCON_PIO2_11_HYS_MASK             (0x20U)                                             /*!< IOCON_IOCON_PIO2_11.HYS Mask            */
#define IOCON_IOCON_PIO2_11_HYS_SHIFT            (5U)                                                /*!< IOCON_IOCON_PIO2_11.HYS Position        */
#define IOCON_IOCON_PIO2_11_HYS(x)               (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_11.HYS Field           */
#define IOCON_IOCON_PIO2_11_OD_MASK              (0x400U)                                            /*!< IOCON_IOCON_PIO2_11.OD Mask             */
#define IOCON_IOCON_PIO2_11_OD_SHIFT             (10U)                                               /*!< IOCON_IOCON_PIO2_11.OD Position         */
#define IOCON_IOCON_PIO2_11_OD(x)                (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_11.OD Field            */
/* ------- IOCON_R_PIO0_11 Bit Fields               ------ */
#define IOCON_IOCON_R_PIO0_11_FUNC_MASK          (0x7U)                                              /*!< IOCON_IOCON_R_PIO0_11.FUNC Mask         */
#define IOCON_IOCON_R_PIO0_11_FUNC_SHIFT         (0U)                                                /*!< IOCON_IOCON_R_PIO0_11.FUNC Position     */
#define IOCON_IOCON_R_PIO0_11_FUNC(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_R_PIO0_11.FUNC Field        */
#define IOCON_IOCON_R_PIO0_11_MODE_MASK          (0x18U)                                             /*!< IOCON_IOCON_R_PIO0_11.MODE Mask         */
#define IOCON_IOCON_R_PIO0_11_MODE_SHIFT         (3U)                                                /*!< IOCON_IOCON_R_PIO0_11.MODE Position     */
#define IOCON_IOCON_R_PIO0_11_MODE(x)            (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_R_PIO0_11.MODE Field        */
#define IOCON_IOCON_R_PIO0_11_HYS_MASK           (0x20U)                                             /*!< IOCON_IOCON_R_PIO0_11.HYS Mask          */
#define IOCON_IOCON_R_PIO0_11_HYS_SHIFT          (5U)                                                /*!< IOCON_IOCON_R_PIO0_11.HYS Position      */
#define IOCON_IOCON_R_PIO0_11_HYS(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_R_PIO0_11.HYS Field         */
#define IOCON_IOCON_R_PIO0_11_ADMODE_MASK        (0x80U)                                             /*!< IOCON_IOCON_R_PIO0_11.ADMODE Mask       */
#define IOCON_IOCON_R_PIO0_11_ADMODE_SHIFT       (7U)                                                /*!< IOCON_IOCON_R_PIO0_11.ADMODE Position   */
#define IOCON_IOCON_R_PIO0_11_ADMODE(x)          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< IOCON_IOCON_R_PIO0_11.ADMODE Field      */
#define IOCON_IOCON_R_PIO0_11_OD_MASK            (0x400U)                                            /*!< IOCON_IOCON_R_PIO0_11.OD Mask           */
#define IOCON_IOCON_R_PIO0_11_OD_SHIFT           (10U)                                               /*!< IOCON_IOCON_R_PIO0_11.OD Position       */
#define IOCON_IOCON_R_PIO0_11_OD(x)              (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_R_PIO0_11.OD Field          */
/* ------- IOCON_R_PIO1_0 Bit Fields                ------ */
#define IOCON_IOCON_R_PIO1_0_FUNC_MASK           (0x7U)                                              /*!< IOCON_IOCON_R_PIO1_0.FUNC Mask          */
#define IOCON_IOCON_R_PIO1_0_FUNC_SHIFT          (0U)                                                /*!< IOCON_IOCON_R_PIO1_0.FUNC Position      */
#define IOCON_IOCON_R_PIO1_0_FUNC(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_R_PIO1_0.FUNC Field         */
#define IOCON_IOCON_R_PIO1_0_MODE_MASK           (0x18U)                                             /*!< IOCON_IOCON_R_PIO1_0.MODE Mask          */
#define IOCON_IOCON_R_PIO1_0_MODE_SHIFT          (3U)                                                /*!< IOCON_IOCON_R_PIO1_0.MODE Position      */
#define IOCON_IOCON_R_PIO1_0_MODE(x)             (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_R_PIO1_0.MODE Field         */
#define IOCON_IOCON_R_PIO1_0_HYS_MASK            (0x20U)                                             /*!< IOCON_IOCON_R_PIO1_0.HYS Mask           */
#define IOCON_IOCON_R_PIO1_0_HYS_SHIFT           (5U)                                                /*!< IOCON_IOCON_R_PIO1_0.HYS Position       */
#define IOCON_IOCON_R_PIO1_0_HYS(x)              (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_R_PIO1_0.HYS Field          */
#define IOCON_IOCON_R_PIO1_0_ADMODE_MASK         (0x80U)                                             /*!< IOCON_IOCON_R_PIO1_0.ADMODE Mask        */
#define IOCON_IOCON_R_PIO1_0_ADMODE_SHIFT        (7U)                                                /*!< IOCON_IOCON_R_PIO1_0.ADMODE Position    */
#define IOCON_IOCON_R_PIO1_0_ADMODE(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< IOCON_IOCON_R_PIO1_0.ADMODE Field       */
#define IOCON_IOCON_R_PIO1_0_OD_MASK             (0x400U)                                            /*!< IOCON_IOCON_R_PIO1_0.OD Mask            */
#define IOCON_IOCON_R_PIO1_0_OD_SHIFT            (10U)                                               /*!< IOCON_IOCON_R_PIO1_0.OD Position        */
#define IOCON_IOCON_R_PIO1_0_OD(x)               (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_R_PIO1_0.OD Field           */
/* ------- IOCON_R_PIO1_1 Bit Fields                ------ */
#define IOCON_IOCON_R_PIO1_1_FUNC_MASK           (0x7U)                                              /*!< IOCON_IOCON_R_PIO1_1.FUNC Mask          */
#define IOCON_IOCON_R_PIO1_1_FUNC_SHIFT          (0U)                                                /*!< IOCON_IOCON_R_PIO1_1.FUNC Position      */
#define IOCON_IOCON_R_PIO1_1_FUNC(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_R_PIO1_1.FUNC Field         */
#define IOCON_IOCON_R_PIO1_1_MODE_MASK           (0x18U)                                             /*!< IOCON_IOCON_R_PIO1_1.MODE Mask          */
#define IOCON_IOCON_R_PIO1_1_MODE_SHIFT          (3U)                                                /*!< IOCON_IOCON_R_PIO1_1.MODE Position      */
#define IOCON_IOCON_R_PIO1_1_MODE(x)             (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_R_PIO1_1.MODE Field         */
#define IOCON_IOCON_R_PIO1_1_HYS_MASK            (0x20U)                                             /*!< IOCON_IOCON_R_PIO1_1.HYS Mask           */
#define IOCON_IOCON_R_PIO1_1_HYS_SHIFT           (5U)                                                /*!< IOCON_IOCON_R_PIO1_1.HYS Position       */
#define IOCON_IOCON_R_PIO1_1_HYS(x)              (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_R_PIO1_1.HYS Field          */
#define IOCON_IOCON_R_PIO1_1_ADMODE_MASK         (0x80U)                                             /*!< IOCON_IOCON_R_PIO1_1.ADMODE Mask        */
#define IOCON_IOCON_R_PIO1_1_ADMODE_SHIFT        (7U)                                                /*!< IOCON_IOCON_R_PIO1_1.ADMODE Position    */
#define IOCON_IOCON_R_PIO1_1_ADMODE(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< IOCON_IOCON_R_PIO1_1.ADMODE Field       */
#define IOCON_IOCON_R_PIO1_1_OD_MASK             (0x400U)                                            /*!< IOCON_IOCON_R_PIO1_1.OD Mask            */
#define IOCON_IOCON_R_PIO1_1_OD_SHIFT            (10U)                                               /*!< IOCON_IOCON_R_PIO1_1.OD Position        */
#define IOCON_IOCON_R_PIO1_1_OD(x)               (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_R_PIO1_1.OD Field           */
/* ------- IOCON_R_PIO1_2 Bit Fields                ------ */
#define IOCON_IOCON_R_PIO1_2_FUNC_MASK           (0x7U)                                              /*!< IOCON_IOCON_R_PIO1_2.FUNC Mask          */
#define IOCON_IOCON_R_PIO1_2_FUNC_SHIFT          (0U)                                                /*!< IOCON_IOCON_R_PIO1_2.FUNC Position      */
#define IOCON_IOCON_R_PIO1_2_FUNC(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_R_PIO1_2.FUNC Field         */
#define IOCON_IOCON_R_PIO1_2_MODE_MASK           (0x18U)                                             /*!< IOCON_IOCON_R_PIO1_2.MODE Mask          */
#define IOCON_IOCON_R_PIO1_2_MODE_SHIFT          (3U)                                                /*!< IOCON_IOCON_R_PIO1_2.MODE Position      */
#define IOCON_IOCON_R_PIO1_2_MODE(x)             (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_R_PIO1_2.MODE Field         */
#define IOCON_IOCON_R_PIO1_2_HYS_MASK            (0x20U)                                             /*!< IOCON_IOCON_R_PIO1_2.HYS Mask           */
#define IOCON_IOCON_R_PIO1_2_HYS_SHIFT           (5U)                                                /*!< IOCON_IOCON_R_PIO1_2.HYS Position       */
#define IOCON_IOCON_R_PIO1_2_HYS(x)              (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_R_PIO1_2.HYS Field          */
#define IOCON_IOCON_R_PIO1_2_ADMODE_MASK         (0x80U)                                             /*!< IOCON_IOCON_R_PIO1_2.ADMODE Mask        */
#define IOCON_IOCON_R_PIO1_2_ADMODE_SHIFT        (7U)                                                /*!< IOCON_IOCON_R_PIO1_2.ADMODE Position    */
#define IOCON_IOCON_R_PIO1_2_ADMODE(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< IOCON_IOCON_R_PIO1_2.ADMODE Field       */
#define IOCON_IOCON_R_PIO1_2_OD_MASK             (0x400U)                                            /*!< IOCON_IOCON_R_PIO1_2.OD Mask            */
#define IOCON_IOCON_R_PIO1_2_OD_SHIFT            (10U)                                               /*!< IOCON_IOCON_R_PIO1_2.OD Position        */
#define IOCON_IOCON_R_PIO1_2_OD(x)               (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_R_PIO1_2.OD Field           */
/* ------- IOCON_PIO3_0 Bit Fields                  ------ */
#define IOCON_IOCON_PIO3_0_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO3_0.FUNC Mask            */
#define IOCON_IOCON_PIO3_0_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO3_0.FUNC Position        */
#define IOCON_IOCON_PIO3_0_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO3_0.FUNC Field           */
#define IOCON_IOCON_PIO3_0_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO3_0.MODE Mask            */
#define IOCON_IOCON_PIO3_0_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO3_0.MODE Position        */
#define IOCON_IOCON_PIO3_0_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO3_0.MODE Field           */
#define IOCON_IOCON_PIO3_0_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO3_0.HYS Mask             */
#define IOCON_IOCON_PIO3_0_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO3_0.HYS Position         */
#define IOCON_IOCON_PIO3_0_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO3_0.HYS Field            */
#define IOCON_IOCON_PIO3_0_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO3_0.OD Mask              */
#define IOCON_IOCON_PIO3_0_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO3_0.OD Position          */
#define IOCON_IOCON_PIO3_0_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO3_0.OD Field             */
/* ------- IOCON_PIO3_1 Bit Fields                  ------ */
#define IOCON_IOCON_PIO3_1_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO3_1.FUNC Mask            */
#define IOCON_IOCON_PIO3_1_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO3_1.FUNC Position        */
#define IOCON_IOCON_PIO3_1_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO3_1.FUNC Field           */
#define IOCON_IOCON_PIO3_1_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO3_1.MODE Mask            */
#define IOCON_IOCON_PIO3_1_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO3_1.MODE Position        */
#define IOCON_IOCON_PIO3_1_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO3_1.MODE Field           */
#define IOCON_IOCON_PIO3_1_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO3_1.HYS Mask             */
#define IOCON_IOCON_PIO3_1_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO3_1.HYS Position         */
#define IOCON_IOCON_PIO3_1_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO3_1.HYS Field            */
#define IOCON_IOCON_PIO3_1_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO3_1.OD Mask              */
#define IOCON_IOCON_PIO3_1_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO3_1.OD Position          */
#define IOCON_IOCON_PIO3_1_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO3_1.OD Field             */
/* ------- IOCON_PIO2_3 Bit Fields                  ------ */
#define IOCON_IOCON_PIO2_3_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO2_3.FUNC Mask            */
#define IOCON_IOCON_PIO2_3_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO2_3.FUNC Position        */
#define IOCON_IOCON_PIO2_3_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO2_3.FUNC Field           */
#define IOCON_IOCON_PIO2_3_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO2_3.MODE Mask            */
#define IOCON_IOCON_PIO2_3_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO2_3.MODE Position        */
#define IOCON_IOCON_PIO2_3_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO2_3.MODE Field           */
#define IOCON_IOCON_PIO2_3_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO2_3.HYS Mask             */
#define IOCON_IOCON_PIO2_3_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO2_3.HYS Position         */
#define IOCON_IOCON_PIO2_3_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO2_3.HYS Field            */
#define IOCON_IOCON_PIO2_3_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO2_3.OD Mask              */
#define IOCON_IOCON_PIO2_3_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO2_3.OD Position          */
#define IOCON_IOCON_PIO2_3_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO2_3.OD Field             */
/* ------- IOCON_SWDIO_PIO1_3 Bit Fields            ------ */
#define IOCON_IOCON_SWDIO_PIO1_3_FUNC_MASK       (0x7U)                                              /*!< IOCON_IOCON_SWDIO_PIO1_3.FUNC Mask      */
#define IOCON_IOCON_SWDIO_PIO1_3_FUNC_SHIFT      (0U)                                                /*!< IOCON_IOCON_SWDIO_PIO1_3.FUNC Position  */
#define IOCON_IOCON_SWDIO_PIO1_3_FUNC(x)         (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_SWDIO_PIO1_3.FUNC Field     */
#define IOCON_IOCON_SWDIO_PIO1_3_MODE_MASK       (0x18U)                                             /*!< IOCON_IOCON_SWDIO_PIO1_3.MODE Mask      */
#define IOCON_IOCON_SWDIO_PIO1_3_MODE_SHIFT      (3U)                                                /*!< IOCON_IOCON_SWDIO_PIO1_3.MODE Position  */
#define IOCON_IOCON_SWDIO_PIO1_3_MODE(x)         (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_SWDIO_PIO1_3.MODE Field     */
#define IOCON_IOCON_SWDIO_PIO1_3_HYS_MASK        (0x20U)                                             /*!< IOCON_IOCON_SWDIO_PIO1_3.HYS Mask       */
#define IOCON_IOCON_SWDIO_PIO1_3_HYS_SHIFT       (5U)                                                /*!< IOCON_IOCON_SWDIO_PIO1_3.HYS Position   */
#define IOCON_IOCON_SWDIO_PIO1_3_HYS(x)          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_SWDIO_PIO1_3.HYS Field      */
#define IOCON_IOCON_SWDIO_PIO1_3_ADMODE_MASK     (0x80U)                                             /*!< IOCON_IOCON_SWDIO_PIO1_3.ADMODE Mask    */
#define IOCON_IOCON_SWDIO_PIO1_3_ADMODE_SHIFT    (7U)                                                /*!< IOCON_IOCON_SWDIO_PIO1_3.ADMODE Position*/
#define IOCON_IOCON_SWDIO_PIO1_3_ADMODE(x)       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< IOCON_IOCON_SWDIO_PIO1_3.ADMODE Field   */
#define IOCON_IOCON_SWDIO_PIO1_3_OD_MASK         (0x400U)                                            /*!< IOCON_IOCON_SWDIO_PIO1_3.OD Mask        */
#define IOCON_IOCON_SWDIO_PIO1_3_OD_SHIFT        (10U)                                               /*!< IOCON_IOCON_SWDIO_PIO1_3.OD Position    */
#define IOCON_IOCON_SWDIO_PIO1_3_OD(x)           (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_SWDIO_PIO1_3.OD Field       */
/* ------- IOCON_PIO1_4 Bit Fields                  ------ */
#define IOCON_IOCON_PIO1_4_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO1_4.FUNC Mask            */
#define IOCON_IOCON_PIO1_4_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO1_4.FUNC Position        */
#define IOCON_IOCON_PIO1_4_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO1_4.FUNC Field           */
#define IOCON_IOCON_PIO1_4_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO1_4.MODE Mask            */
#define IOCON_IOCON_PIO1_4_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO1_4.MODE Position        */
#define IOCON_IOCON_PIO1_4_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO1_4.MODE Field           */
#define IOCON_IOCON_PIO1_4_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO1_4.HYS Mask             */
#define IOCON_IOCON_PIO1_4_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO1_4.HYS Position         */
#define IOCON_IOCON_PIO1_4_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO1_4.HYS Field            */
#define IOCON_IOCON_PIO1_4_ADMODE_MASK           (0x80U)                                             /*!< IOCON_IOCON_PIO1_4.ADMODE Mask          */
#define IOCON_IOCON_PIO1_4_ADMODE_SHIFT          (7U)                                                /*!< IOCON_IOCON_PIO1_4.ADMODE Position      */
#define IOCON_IOCON_PIO1_4_ADMODE(x)             (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< IOCON_IOCON_PIO1_4.ADMODE Field         */
#define IOCON_IOCON_PIO1_4_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO1_4.OD Mask              */
#define IOCON_IOCON_PIO1_4_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO1_4.OD Position          */
#define IOCON_IOCON_PIO1_4_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO1_4.OD Field             */
/* ------- IOCON_PIO1_11 Bit Fields                 ------ */
#define IOCON_IOCON_PIO1_11_FUNC_MASK            (0x7U)                                              /*!< IOCON_IOCON_PIO1_11.FUNC Mask           */
#define IOCON_IOCON_PIO1_11_FUNC_SHIFT           (0U)                                                /*!< IOCON_IOCON_PIO1_11.FUNC Position       */
#define IOCON_IOCON_PIO1_11_FUNC(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO1_11.FUNC Field          */
#define IOCON_IOCON_PIO1_11_MODE_MASK            (0x18U)                                             /*!< IOCON_IOCON_PIO1_11.MODE Mask           */
#define IOCON_IOCON_PIO1_11_MODE_SHIFT           (3U)                                                /*!< IOCON_IOCON_PIO1_11.MODE Position       */
#define IOCON_IOCON_PIO1_11_MODE(x)              (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO1_11.MODE Field          */
#define IOCON_IOCON_PIO1_11_HYS_MASK             (0x20U)                                             /*!< IOCON_IOCON_PIO1_11.HYS Mask            */
#define IOCON_IOCON_PIO1_11_HYS_SHIFT            (5U)                                                /*!< IOCON_IOCON_PIO1_11.HYS Position        */
#define IOCON_IOCON_PIO1_11_HYS(x)               (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO1_11.HYS Field           */
#define IOCON_IOCON_PIO1_11_ADMODE_MASK          (0x80U)                                             /*!< IOCON_IOCON_PIO1_11.ADMODE Mask         */
#define IOCON_IOCON_PIO1_11_ADMODE_SHIFT         (7U)                                                /*!< IOCON_IOCON_PIO1_11.ADMODE Position     */
#define IOCON_IOCON_PIO1_11_ADMODE(x)            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< IOCON_IOCON_PIO1_11.ADMODE Field        */
#define IOCON_IOCON_PIO1_11_OD_MASK              (0x400U)                                            /*!< IOCON_IOCON_PIO1_11.OD Mask             */
#define IOCON_IOCON_PIO1_11_OD_SHIFT             (10U)                                               /*!< IOCON_IOCON_PIO1_11.OD Position         */
#define IOCON_IOCON_PIO1_11_OD(x)                (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO1_11.OD Field            */
/* ------- IOCON_PIO3_2 Bit Fields                  ------ */
#define IOCON_IOCON_PIO3_2_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO3_2.FUNC Mask            */
#define IOCON_IOCON_PIO3_2_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO3_2.FUNC Position        */
#define IOCON_IOCON_PIO3_2_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO3_2.FUNC Field           */
#define IOCON_IOCON_PIO3_2_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO3_2.MODE Mask            */
#define IOCON_IOCON_PIO3_2_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO3_2.MODE Position        */
#define IOCON_IOCON_PIO3_2_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO3_2.MODE Field           */
#define IOCON_IOCON_PIO3_2_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO3_2.HYS Mask             */
#define IOCON_IOCON_PIO3_2_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO3_2.HYS Position         */
#define IOCON_IOCON_PIO3_2_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO3_2.HYS Field            */
#define IOCON_IOCON_PIO3_2_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO3_2.OD Mask              */
#define IOCON_IOCON_PIO3_2_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO3_2.OD Position          */
#define IOCON_IOCON_PIO3_2_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO3_2.OD Field             */
/* ------- IOCON_PIO1_5 Bit Fields                  ------ */
#define IOCON_IOCON_PIO1_5_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO1_5.FUNC Mask            */
#define IOCON_IOCON_PIO1_5_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO1_5.FUNC Position        */
#define IOCON_IOCON_PIO1_5_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO1_5.FUNC Field           */
#define IOCON_IOCON_PIO1_5_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO1_5.MODE Mask            */
#define IOCON_IOCON_PIO1_5_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO1_5.MODE Position        */
#define IOCON_IOCON_PIO1_5_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO1_5.MODE Field           */
#define IOCON_IOCON_PIO1_5_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO1_5.HYS Mask             */
#define IOCON_IOCON_PIO1_5_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO1_5.HYS Position         */
#define IOCON_IOCON_PIO1_5_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO1_5.HYS Field            */
#define IOCON_IOCON_PIO1_5_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO1_5.OD Mask              */
#define IOCON_IOCON_PIO1_5_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO1_5.OD Position          */
#define IOCON_IOCON_PIO1_5_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO1_5.OD Field             */
/* ------- IOCON_PIO1_6 Bit Fields                  ------ */
#define IOCON_IOCON_PIO1_6_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO1_6.FUNC Mask            */
#define IOCON_IOCON_PIO1_6_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO1_6.FUNC Position        */
#define IOCON_IOCON_PIO1_6_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO1_6.FUNC Field           */
#define IOCON_IOCON_PIO1_6_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO1_6.MODE Mask            */
#define IOCON_IOCON_PIO1_6_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO1_6.MODE Position        */
#define IOCON_IOCON_PIO1_6_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO1_6.MODE Field           */
#define IOCON_IOCON_PIO1_6_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO1_6.HYS Mask             */
#define IOCON_IOCON_PIO1_6_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO1_6.HYS Position         */
#define IOCON_IOCON_PIO1_6_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO1_6.HYS Field            */
#define IOCON_IOCON_PIO1_6_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO1_6.OD Mask              */
#define IOCON_IOCON_PIO1_6_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO1_6.OD Position          */
#define IOCON_IOCON_PIO1_6_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO1_6.OD Field             */
/* ------- IOCON_PIO1_7 Bit Fields                  ------ */
#define IOCON_IOCON_PIO1_7_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO1_7.FUNC Mask            */
#define IOCON_IOCON_PIO1_7_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO1_7.FUNC Position        */
#define IOCON_IOCON_PIO1_7_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO1_7.FUNC Field           */
#define IOCON_IOCON_PIO1_7_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO1_7.MODE Mask            */
#define IOCON_IOCON_PIO1_7_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO1_7.MODE Position        */
#define IOCON_IOCON_PIO1_7_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO1_7.MODE Field           */
#define IOCON_IOCON_PIO1_7_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO1_7.HYS Mask             */
#define IOCON_IOCON_PIO1_7_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO1_7.HYS Position         */
#define IOCON_IOCON_PIO1_7_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO1_7.HYS Field            */
#define IOCON_IOCON_PIO1_7_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO1_7.OD Mask              */
#define IOCON_IOCON_PIO1_7_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO1_7.OD Position          */
#define IOCON_IOCON_PIO1_7_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO1_7.OD Field             */
/* ------- IOCON_PIO3_3 Bit Fields                  ------ */
#define IOCON_IOCON_PIO3_3_FUNC_MASK             (0x7U)                                              /*!< IOCON_IOCON_PIO3_3.FUNC Mask            */
#define IOCON_IOCON_PIO3_3_FUNC_SHIFT            (0U)                                                /*!< IOCON_IOCON_PIO3_3.FUNC Position        */
#define IOCON_IOCON_PIO3_3_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< IOCON_IOCON_PIO3_3.FUNC Field           */
#define IOCON_IOCON_PIO3_3_MODE_MASK             (0x18U)                                             /*!< IOCON_IOCON_PIO3_3.MODE Mask            */
#define IOCON_IOCON_PIO3_3_MODE_SHIFT            (3U)                                                /*!< IOCON_IOCON_PIO3_3.MODE Position        */
#define IOCON_IOCON_PIO3_3_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< IOCON_IOCON_PIO3_3.MODE Field           */
#define IOCON_IOCON_PIO3_3_HYS_MASK              (0x20U)                                             /*!< IOCON_IOCON_PIO3_3.HYS Mask             */
#define IOCON_IOCON_PIO3_3_HYS_SHIFT             (5U)                                                /*!< IOCON_IOCON_PIO3_3.HYS Position         */
#define IOCON_IOCON_PIO3_3_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< IOCON_IOCON_PIO3_3.HYS Field            */
#define IOCON_IOCON_PIO3_3_OD_MASK               (0x400U)                                            /*!< IOCON_IOCON_PIO3_3.OD Mask              */
#define IOCON_IOCON_PIO3_3_OD_SHIFT              (10U)                                               /*!< IOCON_IOCON_PIO3_3.OD Position          */
#define IOCON_IOCON_PIO3_3_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< IOCON_IOCON_PIO3_3.OD Field             */
/* ------- IOCON_SCK0_LOC Bit Fields                ------ */
#define IOCON_IOCON_SCK0_LOC_SCKLOC_MASK         (0x3U)                                              /*!< IOCON_IOCON_SCK0_LOC.SCKLOC Mask        */
#define IOCON_IOCON_SCK0_LOC_SCKLOC_SHIFT        (0U)                                                /*!< IOCON_IOCON_SCK0_LOC.SCKLOC Position    */
#define IOCON_IOCON_SCK0_LOC_SCKLOC(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_SCK0_LOC.SCKLOC Field       */
/* ------- IOCON_DSR_LOC Bit Fields                 ------ */
#define IOCON_IOCON_DSR_LOC_DSRLOC_MASK          (0x3U)                                              /*!< IOCON_IOCON_DSR_LOC.DSRLOC Mask         */
#define IOCON_IOCON_DSR_LOC_DSRLOC_SHIFT         (0U)                                                /*!< IOCON_IOCON_DSR_LOC.DSRLOC Position     */
#define IOCON_IOCON_DSR_LOC_DSRLOC(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_DSR_LOC.DSRLOC Field        */
/* ------- IOCON_DCD_LOC Bit Fields                 ------ */
#define IOCON_IOCON_DCD_LOC_DCDLOC_MASK          (0x3U)                                              /*!< IOCON_IOCON_DCD_LOC.DCDLOC Mask         */
#define IOCON_IOCON_DCD_LOC_DCDLOC_SHIFT         (0U)                                                /*!< IOCON_IOCON_DCD_LOC.DCDLOC Position     */
#define IOCON_IOCON_DCD_LOC_DCDLOC(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_DCD_LOC.DCDLOC Field        */
/* ------- IOCON_RI_LOC Bit Fields                  ------ */
#define IOCON_IOCON_RI_LOC_RILOC_MASK            (0x3U)                                              /*!< IOCON_IOCON_RI_LOC.RILOC Mask           */
#define IOCON_IOCON_RI_LOC_RILOC_SHIFT           (0U)                                                /*!< IOCON_IOCON_RI_LOC.RILOC Position       */
#define IOCON_IOCON_RI_LOC_RILOC(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_RI_LOC.RILOC Field          */
/* ------- IOCON_CT16B0_CAP0_LOC Bit Fields         ------ */
#define IOCON_IOCON_CT16B0_CAP0_LOC_CT16B0_CAP0LOC_MASK (0x3U)                                       /*!< IOCON_IOCON_CT16B0_CAP0_LOC.CT16B0_CAP0LOC Mask*/
#define IOCON_IOCON_CT16B0_CAP0_LOC_CT16B0_CAP0LOC_SHIFT (0U)                                        /*!< IOCON_IOCON_CT16B0_CAP0_LOC.CT16B0_CAP0LOC Position*/
#define IOCON_IOCON_CT16B0_CAP0_LOC_CT16B0_CAP0LOC(x) (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)      /*!< IOCON_IOCON_CT16B0_CAP0_LOC.CT16B0_CAP0LOC Field*/
/* ------- IOCON_SCK1_LOC Bit Fields                ------ */
#define IOCON_IOCON_SCK1_LOC_SCK1LOC_MASK        (0x3U)                                              /*!< IOCON_IOCON_SCK1_LOC.SCK1LOC Mask       */
#define IOCON_IOCON_SCK1_LOC_SCK1LOC_SHIFT       (0U)                                                /*!< IOCON_IOCON_SCK1_LOC.SCK1LOC Position   */
#define IOCON_IOCON_SCK1_LOC_SCK1LOC(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_SCK1_LOC.SCK1LOC Field      */
/* ------- IOCON_MISO1_LOC Bit Fields               ------ */
#define IOCON_IOCON_MISO1_LOC_MISO1LOC_MASK      (0x3U)                                              /*!< IOCON_IOCON_MISO1_LOC.MISO1LOC Mask     */
#define IOCON_IOCON_MISO1_LOC_MISO1LOC_SHIFT     (0U)                                                /*!< IOCON_IOCON_MISO1_LOC.MISO1LOC Position */
#define IOCON_IOCON_MISO1_LOC_MISO1LOC(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_MISO1_LOC.MISO1LOC Field    */
/* ------- IOCON_MOSI1_LOC Bit Fields               ------ */
#define IOCON_IOCON_MOSI1_LOC_MOSI1LOC_MASK      (0x3U)                                              /*!< IOCON_IOCON_MOSI1_LOC.MOSI1LOC Mask     */
#define IOCON_IOCON_MOSI1_LOC_MOSI1LOC_SHIFT     (0U)                                                /*!< IOCON_IOCON_MOSI1_LOC.MOSI1LOC Position */
#define IOCON_IOCON_MOSI1_LOC_MOSI1LOC(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_MOSI1_LOC.MOSI1LOC Field    */
/* ------- IOCON_CT32B0_CAP0_LOC Bit Fields         ------ */
#define IOCON_IOCON_CT32B0_CAP0_LOC_CT32B0_CAP0LOC_MASK (0x3U)                                       /*!< IOCON_IOCON_CT32B0_CAP0_LOC.CT32B0_CAP0LOC Mask*/
#define IOCON_IOCON_CT32B0_CAP0_LOC_CT32B0_CAP0LOC_SHIFT (0U)                                        /*!< IOCON_IOCON_CT32B0_CAP0_LOC.CT32B0_CAP0LOC Position*/
#define IOCON_IOCON_CT32B0_CAP0_LOC_CT32B0_CAP0LOC(x) (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)      /*!< IOCON_IOCON_CT32B0_CAP0_LOC.CT32B0_CAP0LOC Field*/
/* ------- IOCON_RXD_LOC Bit Fields                 ------ */
#define IOCON_IOCON_RXD_LOC_RXDLOC_MASK          (0x3U)                                              /*!< IOCON_IOCON_RXD_LOC.RXDLOC Mask         */
#define IOCON_IOCON_RXD_LOC_RXDLOC_SHIFT         (0U)                                                /*!< IOCON_IOCON_RXD_LOC.RXDLOC Position     */
#define IOCON_IOCON_RXD_LOC_RXDLOC(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< IOCON_IOCON_RXD_LOC.RXDLOC Field        */
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
/* ================           PMU (file:PMU_LPC11xx)               ================ */
/* ================================================================================ */

/**
 * @brief power management unit
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
#define PMU_PCON_DPDEN_MASK                      (0x2U)                                              /*!< PMU_PCON.DPDEN Mask                     */
#define PMU_PCON_DPDEN_SHIFT                     (1U)                                                /*!< PMU_PCON.DPDEN Position                 */
#define PMU_PCON_DPDEN(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PMU_PCON.DPDEN Field                    */
#define PMU_PCON_SLEEPFLAG_MASK                  (0x100U)                                            /*!< PMU_PCON.SLEEPFLAG Mask                 */
#define PMU_PCON_SLEEPFLAG_SHIFT                 (8U)                                                /*!< PMU_PCON.SLEEPFLAG Position             */
#define PMU_PCON_SLEEPFLAG(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< PMU_PCON.SLEEPFLAG Field                */
#define PMU_PCON_DPDFLAG_MASK                    (0x800U)                                            /*!< PMU_PCON.DPDFLAG Mask                   */
#define PMU_PCON_DPDFLAG_SHIFT                   (11U)                                               /*!< PMU_PCON.DPDFLAG Position               */
#define PMU_PCON_DPDFLAG(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< PMU_PCON.DPDFLAG Field                  */
/* ------- GPREG Bit Fields                         ------ */
#define PMU_GPREG_GPDATA_MASK                    (0xFFFFFFFFU)                                       /*!< PMU_GPREG.GPDATA Mask                   */
#define PMU_GPREG_GPDATA_SHIFT                   (0U)                                                /*!< PMU_GPREG.GPDATA Position               */
#define PMU_GPREG_GPDATA(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< PMU_GPREG.GPDATA Field                  */
/* ------- GPREG4 Bit Fields                        ------ */
#define PMU_GPREG4_WAKEUPHYS_MASK                (0x400U)                                            /*!< PMU_GPREG4.WAKEUPHYS Mask               */
#define PMU_GPREG4_WAKEUPHYS_SHIFT               (10U)                                               /*!< PMU_GPREG4.WAKEUPHYS Position           */
#define PMU_GPREG4_WAKEUPHYS(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< PMU_GPREG4.WAKEUPHYS Field              */
#define PMU_GPREG4_GPDATA_MASK                   (0xFFFFF800U)                                       /*!< PMU_GPREG4.GPDATA Mask                  */
#define PMU_GPREG4_GPDATA_SHIFT                  (11U)                                               /*!< PMU_GPREG4.GPDATA Position              */
#define PMU_GPREG4_GPDATA(x)                     (((uint32_t)(((uint32_t)(x))<<11U))&0xFFFFF800UL)   /*!< PMU_GPREG4.GPDATA Field                 */
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
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI0 (file:SPI0_LPC11Cxx)            ================ */
/* ================================================================================ */

/**
 * @brief SPI0
 */
/**
* @addtogroup SPI_structs_GROUP SPI struct
* @brief Struct for SPI
* @{
*/
typedef struct {                                /*       SPI0 Structure                                               */
   __IO uint32_t  CR0;                          /**< 0000: Control Register 0. Selects the serial clock rate, bus type, and data size */
   __IO uint32_t  CR1;                          /**< 0004: Control Register 1. Selects master/slave and other modes     */
   __IO uint32_t  DR;                           /**< 0008: Data Register. Writes fill the transmit FIFO, and reads empty the receive FIFO */
   __I  uint32_t  SR;                           /**< 000C: Status Register                                              */
   __IO uint32_t  CPSR;                         /**< 0010: Clock Prescale Register                                      */
   __IO uint32_t  IMSC;                         /**< 0014: Interrupt Mask Set and Clear Register                        */
   __I  uint32_t  RIS;                          /**< 0018: Raw Interrupt Status Register                                */
   __I  uint32_t  MIS;                          /**< 001C: Masked Interrupt Status Register                             */
   __O  uint32_t  ICR;                          /**< 0020: SSPICR Interrupt Clear Register                              */
} SPI0_Type;

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
/* ------- CR0 Bit Fields                           ------ */
#define SPI_CR0_DSS_MASK                         (0xFU)                                              /*!< SPI0_CR0.DSS Mask                       */
#define SPI_CR0_DSS_SHIFT                        (0U)                                                /*!< SPI0_CR0.DSS Position                   */
#define SPI_CR0_DSS(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SPI0_CR0.DSS Field                      */
#define SPI_CR0_FRF_MASK                         (0x30U)                                             /*!< SPI0_CR0.FRF Mask                       */
#define SPI_CR0_FRF_SHIFT                        (4U)                                                /*!< SPI0_CR0.FRF Position                   */
#define SPI_CR0_FRF(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< SPI0_CR0.FRF Field                      */
#define SPI_CR0_CPOL_MASK                        (0x40U)                                             /*!< SPI0_CR0.CPOL Mask                      */
#define SPI_CR0_CPOL_SHIFT                       (6U)                                                /*!< SPI0_CR0.CPOL Position                  */
#define SPI_CR0_CPOL(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SPI0_CR0.CPOL Field                     */
#define SPI_CR0_CPHA_MASK                        (0x80U)                                             /*!< SPI0_CR0.CPHA Mask                      */
#define SPI_CR0_CPHA_SHIFT                       (7U)                                                /*!< SPI0_CR0.CPHA Position                  */
#define SPI_CR0_CPHA(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SPI0_CR0.CPHA Field                     */
#define SPI_CR0_SCR_MASK                         (0xFF00U)                                           /*!< SPI0_CR0.SCR Mask                       */
#define SPI_CR0_SCR_SHIFT                        (8U)                                                /*!< SPI0_CR0.SCR Position                   */
#define SPI_CR0_SCR(x)                           (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< SPI0_CR0.SCR Field                      */
/* ------- CR1 Bit Fields                           ------ */
#define SPI_CR1_LBM_MASK                         (0x1U)                                              /*!< SPI0_CR1.LBM Mask                       */
#define SPI_CR1_LBM_SHIFT                        (0U)                                                /*!< SPI0_CR1.LBM Position                   */
#define SPI_CR1_LBM(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SPI0_CR1.LBM Field                      */
#define SPI_CR1_SSE_MASK                         (0x2U)                                              /*!< SPI0_CR1.SSE Mask                       */
#define SPI_CR1_SSE_SHIFT                        (1U)                                                /*!< SPI0_CR1.SSE Position                   */
#define SPI_CR1_SSE(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SPI0_CR1.SSE Field                      */
#define SPI_CR1_MS_MASK                          (0x4U)                                              /*!< SPI0_CR1.MS Mask                        */
#define SPI_CR1_MS_SHIFT                         (2U)                                                /*!< SPI0_CR1.MS Position                    */
#define SPI_CR1_MS(x)                            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SPI0_CR1.MS Field                       */
#define SPI_CR1_SOD_MASK                         (0x8U)                                              /*!< SPI0_CR1.SOD Mask                       */
#define SPI_CR1_SOD_SHIFT                        (3U)                                                /*!< SPI0_CR1.SOD Position                   */
#define SPI_CR1_SOD(x)                           (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SPI0_CR1.SOD Field                      */
/* ------- DR Bit Fields                            ------ */
#define SPI_DR_DATA_MASK                         (0xFFFFU)                                           /*!< SPI0_DR.DATA Mask                       */
#define SPI_DR_DATA_SHIFT                        (0U)                                                /*!< SPI0_DR.DATA Position                   */
#define SPI_DR_DATA(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< SPI0_DR.DATA Field                      */
/* ------- SR Bit Fields                            ------ */
#define SPI_SR_TFE_MASK                          (0x1U)                                              /*!< SPI0_SR.TFE Mask                        */
#define SPI_SR_TFE_SHIFT                         (0U)                                                /*!< SPI0_SR.TFE Position                    */
#define SPI_SR_TFE(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SPI0_SR.TFE Field                       */
#define SPI_SR_TNF_MASK                          (0x2U)                                              /*!< SPI0_SR.TNF Mask                        */
#define SPI_SR_TNF_SHIFT                         (1U)                                                /*!< SPI0_SR.TNF Position                    */
#define SPI_SR_TNF(x)                            (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SPI0_SR.TNF Field                       */
#define SPI_SR_RNE_MASK                          (0x4U)                                              /*!< SPI0_SR.RNE Mask                        */
#define SPI_SR_RNE_SHIFT                         (2U)                                                /*!< SPI0_SR.RNE Position                    */
#define SPI_SR_RNE(x)                            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SPI0_SR.RNE Field                       */
#define SPI_SR_RFF_MASK                          (0x8U)                                              /*!< SPI0_SR.RFF Mask                        */
#define SPI_SR_RFF_SHIFT                         (3U)                                                /*!< SPI0_SR.RFF Position                    */
#define SPI_SR_RFF(x)                            (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SPI0_SR.RFF Field                       */
#define SPI_SR_BSY_MASK                          (0x10U)                                             /*!< SPI0_SR.BSY Mask                        */
#define SPI_SR_BSY_SHIFT                         (4U)                                                /*!< SPI0_SR.BSY Position                    */
#define SPI_SR_BSY(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SPI0_SR.BSY Field                       */
/* ------- CPSR Bit Fields                          ------ */
#define SPI_CPSR_CPSDVSR_MASK                    (0xFFU)                                             /*!< SPI0_CPSR.CPSDVSR Mask                  */
#define SPI_CPSR_CPSDVSR_SHIFT                   (0U)                                                /*!< SPI0_CPSR.CPSDVSR Position              */
#define SPI_CPSR_CPSDVSR(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< SPI0_CPSR.CPSDVSR Field                 */
/* ------- IMSC Bit Fields                          ------ */
#define SPI_IMSC_RORIM_MASK                      (0x1U)                                              /*!< SPI0_IMSC.RORIM Mask                    */
#define SPI_IMSC_RORIM_SHIFT                     (0U)                                                /*!< SPI0_IMSC.RORIM Position                */
#define SPI_IMSC_RORIM(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SPI0_IMSC.RORIM Field                   */
#define SPI_IMSC_RTIM_MASK                       (0x2U)                                              /*!< SPI0_IMSC.RTIM Mask                     */
#define SPI_IMSC_RTIM_SHIFT                      (1U)                                                /*!< SPI0_IMSC.RTIM Position                 */
#define SPI_IMSC_RTIM(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SPI0_IMSC.RTIM Field                    */
#define SPI_IMSC_RXIM_MASK                       (0x4U)                                              /*!< SPI0_IMSC.RXIM Mask                     */
#define SPI_IMSC_RXIM_SHIFT                      (2U)                                                /*!< SPI0_IMSC.RXIM Position                 */
#define SPI_IMSC_RXIM(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SPI0_IMSC.RXIM Field                    */
#define SPI_IMSC_TXIM_MASK                       (0x8U)                                              /*!< SPI0_IMSC.TXIM Mask                     */
#define SPI_IMSC_TXIM_SHIFT                      (3U)                                                /*!< SPI0_IMSC.TXIM Position                 */
#define SPI_IMSC_TXIM(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SPI0_IMSC.TXIM Field                    */
/* ------- RIS Bit Fields                           ------ */
#define SPI_RIS_RORRIS_MASK                      (0x1U)                                              /*!< SPI0_RIS.RORRIS Mask                    */
#define SPI_RIS_RORRIS_SHIFT                     (0U)                                                /*!< SPI0_RIS.RORRIS Position                */
#define SPI_RIS_RORRIS(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SPI0_RIS.RORRIS Field                   */
#define SPI_RIS_RTRIS_MASK                       (0x2U)                                              /*!< SPI0_RIS.RTRIS Mask                     */
#define SPI_RIS_RTRIS_SHIFT                      (1U)                                                /*!< SPI0_RIS.RTRIS Position                 */
#define SPI_RIS_RTRIS(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SPI0_RIS.RTRIS Field                    */
#define SPI_RIS_RXRIS_MASK                       (0x4U)                                              /*!< SPI0_RIS.RXRIS Mask                     */
#define SPI_RIS_RXRIS_SHIFT                      (2U)                                                /*!< SPI0_RIS.RXRIS Position                 */
#define SPI_RIS_RXRIS(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SPI0_RIS.RXRIS Field                    */
#define SPI_RIS_TXRIS_MASK                       (0x8U)                                              /*!< SPI0_RIS.TXRIS Mask                     */
#define SPI_RIS_TXRIS_SHIFT                      (3U)                                                /*!< SPI0_RIS.TXRIS Position                 */
#define SPI_RIS_TXRIS(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SPI0_RIS.TXRIS Field                    */
/* ------- MIS Bit Fields                           ------ */
#define SPI_MIS_RORMIS_MASK                      (0x1U)                                              /*!< SPI0_MIS.RORMIS Mask                    */
#define SPI_MIS_RORMIS_SHIFT                     (0U)                                                /*!< SPI0_MIS.RORMIS Position                */
#define SPI_MIS_RORMIS(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SPI0_MIS.RORMIS Field                   */
#define SPI_MIS_RTMIS_MASK                       (0x2U)                                              /*!< SPI0_MIS.RTMIS Mask                     */
#define SPI_MIS_RTMIS_SHIFT                      (1U)                                                /*!< SPI0_MIS.RTMIS Position                 */
#define SPI_MIS_RTMIS(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SPI0_MIS.RTMIS Field                    */
#define SPI_MIS_RXMIS_MASK                       (0x4U)                                              /*!< SPI0_MIS.RXMIS Mask                     */
#define SPI_MIS_RXMIS_SHIFT                      (2U)                                                /*!< SPI0_MIS.RXMIS Position                 */
#define SPI_MIS_RXMIS(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SPI0_MIS.RXMIS Field                    */
#define SPI_MIS_TXMIS_MASK                       (0x8U)                                              /*!< SPI0_MIS.TXMIS Mask                     */
#define SPI_MIS_TXMIS_SHIFT                      (3U)                                                /*!< SPI0_MIS.TXMIS Position                 */
#define SPI_MIS_TXMIS(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SPI0_MIS.TXMIS Field                    */
/* ------- ICR Bit Fields                           ------ */
#define SPI_ICR_RORIC_MASK                       (0x1U)                                              /*!< SPI0_ICR.RORIC Mask                     */
#define SPI_ICR_RORIC_SHIFT                      (0U)                                                /*!< SPI0_ICR.RORIC Position                 */
#define SPI_ICR_RORIC(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SPI0_ICR.RORIC Field                    */
#define SPI_ICR_RTIC_MASK                        (0x2U)                                              /*!< SPI0_ICR.RTIC Mask                      */
#define SPI_ICR_RTIC_SHIFT                       (1U)                                                /*!< SPI0_ICR.RTIC Position                  */
#define SPI_ICR_RTIC(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SPI0_ICR.RTIC Field                     */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0x40040000UL //!< Peripheral base address
#define SPI0                           ((SPI0_Type *) SPI0_BasePtr) //!< Freescale base pointer
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
 * @brief SPI0
 */

/* SPI1 - Peripheral instance base addresses */
#define SPI1_BasePtr                   0x40058000UL //!< Peripheral base address
#define SPI1                           ((SPI0_Type *) SPI1_BasePtr) //!< Freescale base pointer
#define SPI1_BASE_PTR                  (SPI1) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SYSCON_Peripheral_access_layer_GROUP SYSCON Peripheral Access Layer
* @brief C Struct for SYSCON
* @{
*/

/* ================================================================================ */
/* ================           SYSCON (file:SYSCON_LPC11xx)         ================ */
/* ================================================================================ */

/**
 * @brief /LPC11Cxx System configuration
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
        uint8_t   RESERVED_0[16];              
   __IO uint32_t  SYSOSCCTRL;                   /**< 0020: System oscillator control                                    */
   __IO uint32_t  WDTOSCCTRL;                   /**< 0024: Watchdog oscillator control                                  */
   __IO uint32_t  IRCCTRL;                      /**< 0028: IRC control                                                  */
        uint8_t   RESERVED_1[4];               
   __I  uint32_t  SYSRSTSTAT;                   /**< 0030: System reset status register                                 */
        uint8_t   RESERVED_2[12];              
   __IO uint32_t  SYSPLLCLKSEL;                 /**< 0040: System PLL clock source select                               */
   __IO uint32_t  SYSPLLCLKUEN;                 /**< 0044: System PLL clock source update enable                        */
        uint8_t   RESERVED_3[40];              
   __IO uint32_t  MAINCLKSEL;                   /**< 0070: Main clock source select                                     */
   __IO uint32_t  MAINCLKUEN;                   /**< 0074: Main clock source update enable                              */
   __IO uint32_t  SYSAHBCLKDIV;                 /**< 0078: System AHB clock divider                                     */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  SYSAHBCLKCTRL;                /**< 0080: System AHB clock control                                     */
        uint8_t   RESERVED_5[16];              
   __IO uint32_t  SSP0CLKDIV;                   /**< 0094: SPI0 clock divider                                           */
   __IO uint32_t  UARTCLKDIV;                   /**< 0098: UART clock divder                                            */
   __IO uint32_t  SSP1CLKDIV;                   /**< 009C: SPI1 clock divder                                            */
        uint8_t   RESERVED_6[48];              
   __IO uint32_t  WDTCLKSEL;                    /**< 00D0: WDT clock source select                                      */
   __IO uint32_t  WDTCLKUEN;                    /**< 00D4: WDT clock source update enable                               */
   __IO uint32_t  WDTCLKDIV;                    /**< 00D8: WDT clock divider                                            */
        uint8_t   RESERVED_7[4];               
   __IO uint32_t  CLKOUTCLKSEL;                 /**< 00E0: CLKOUT clock source select                                   */
   __IO uint32_t  CLKOUTUEN;                    /**< 00E4: CLKOUT clock source update enable                            */
   __IO uint32_t  CLKOUTCLKDIV;                 /**< 00E8: CLKOUT clock divider                                         */
        uint8_t   RESERVED_8[20];              
   __I  uint32_t  PIOPORCAP0;                   /**< 0100: POR captured PIO status 0                                    */
   __I  uint32_t  PIOPORCAP1;                   /**< 0104: POR captured PIO status 1                                    */
        uint8_t   RESERVED_9[72];              
   __IO uint32_t  BODCTRL;                      /**< 0150: BOD control                                                  */
   __IO uint32_t  SYSTCKCAL;                    /**< 0154: System tick counter calibration                              */
        uint8_t   RESERVED_10[28];             
   __IO uint32_t  NMISRC;                       /**< 0174: NMI source selection                                         */
        uint8_t   RESERVED_11[136];            
   __IO uint32_t  STARTAPRP0;                   /**< 0200: Start logic edge control register 0                          */
   __IO uint32_t  STARTERP0;                    /**< 0204: Start logic signal enable register 0                         */
   __O  uint32_t  STARTRSRP0CLR;                /**< 0208: Start logic reset register 0                                 */
   __I  uint32_t  STARTSRP0;                    /**< 020C: Start logic status register 0                                */
        uint8_t   RESERVED_12[32];             
   __IO uint32_t  PDSLEEPCFG;                   /**< 0230: Power-down states in Deep-sleep mode                         */
   __IO uint32_t  PDAWAKECFG;                   /**< 0234: Power-down states after wake-up from Deep-sleep mode         */
   __IO uint32_t  PDRUNCFG;                     /**< 0238: Power-down configuration register                            */
        uint8_t   RESERVED_13[440];            
   __I  uint32_t  DEVICE_ID;                    /**< 03F4: Device ID register 0 for parts LPC1100, LPC1100C, LPC1100L   */
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
#define SYSCON_SYSMEMREMAP_MAP_MASK              (0x3U)                                              /*!< SYSCON_SYSMEMREMAP.MAP Mask             */
#define SYSCON_SYSMEMREMAP_MAP_SHIFT             (0U)                                                /*!< SYSCON_SYSMEMREMAP.MAP Position         */
#define SYSCON_SYSMEMREMAP_MAP(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< SYSCON_SYSMEMREMAP.MAP Field            */
/* ------- PRESETCTRL Bit Fields                    ------ */
#define SYSCON_PRESETCTRL_SSP0_RST_N_MASK        (0x1U)                                              /*!< SYSCON_PRESETCTRL.SSP0_RST_N Mask       */
#define SYSCON_PRESETCTRL_SSP0_RST_N_SHIFT       (0U)                                                /*!< SYSCON_PRESETCTRL.SSP0_RST_N Position   */
#define SYSCON_PRESETCTRL_SSP0_RST_N(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_PRESETCTRL.SSP0_RST_N Field      */
#define SYSCON_PRESETCTRL_I2C_RST_N_MASK         (0x2U)                                              /*!< SYSCON_PRESETCTRL.I2C_RST_N Mask        */
#define SYSCON_PRESETCTRL_I2C_RST_N_SHIFT        (1U)                                                /*!< SYSCON_PRESETCTRL.I2C_RST_N Position    */
#define SYSCON_PRESETCTRL_I2C_RST_N(x)           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_PRESETCTRL.I2C_RST_N Field       */
#define SYSCON_PRESETCTRL_SSP1_RST_N_MASK        (0x4U)                                              /*!< SYSCON_PRESETCTRL.SSP1_RST_N Mask       */
#define SYSCON_PRESETCTRL_SSP1_RST_N_SHIFT       (2U)                                                /*!< SYSCON_PRESETCTRL.SSP1_RST_N Position   */
#define SYSCON_PRESETCTRL_SSP1_RST_N(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_PRESETCTRL.SSP1_RST_N Field      */
#define SYSCON_PRESETCTRL_CAN_RST_N_MASK         (0x8U)                                              /*!< SYSCON_PRESETCTRL.CAN_RST_N Mask        */
#define SYSCON_PRESETCTRL_CAN_RST_N_SHIFT        (3U)                                                /*!< SYSCON_PRESETCTRL.CAN_RST_N Position    */
#define SYSCON_PRESETCTRL_CAN_RST_N(x)           (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_PRESETCTRL.CAN_RST_N Field       */
/* ------- SYSPLLCTRL Bit Fields                    ------ */
#define SYSCON_SYSPLLCTRL_MSEL_MASK              (0x1FU)                                             /*!< SYSCON_SYSPLLCTRL.MSEL Mask             */
#define SYSCON_SYSPLLCTRL_MSEL_SHIFT             (0U)                                                /*!< SYSCON_SYSPLLCTRL.MSEL Position         */
#define SYSCON_SYSPLLCTRL_MSEL(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< SYSCON_SYSPLLCTRL.MSEL Field            */
#define SYSCON_SYSPLLCTRL_PSEL_MASK              (0x60U)                                             /*!< SYSCON_SYSPLLCTRL.PSEL Mask             */
#define SYSCON_SYSPLLCTRL_PSEL_SHIFT             (5U)                                                /*!< SYSCON_SYSPLLCTRL.PSEL Position         */
#define SYSCON_SYSPLLCTRL_PSEL(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x60UL)          /*!< SYSCON_SYSPLLCTRL.PSEL Field            */
/* ------- SYSPLLSTAT Bit Fields                    ------ */
#define SYSCON_SYSPLLSTAT_LOCK_MASK              (0x1U)                                              /*!< SYSCON_SYSPLLSTAT.LOCK Mask             */
#define SYSCON_SYSPLLSTAT_LOCK_SHIFT             (0U)                                                /*!< SYSCON_SYSPLLSTAT.LOCK Position         */
#define SYSCON_SYSPLLSTAT_LOCK(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_SYSPLLSTAT.LOCK Field            */
/* ------- SYSOSCCTRL Bit Fields                    ------ */
#define SYSCON_SYSOSCCTRL_BYPASS_MASK            (0x1U)                                              /*!< SYSCON_SYSOSCCTRL.BYPASS Mask           */
#define SYSCON_SYSOSCCTRL_BYPASS_SHIFT           (0U)                                                /*!< SYSCON_SYSOSCCTRL.BYPASS Position       */
#define SYSCON_SYSOSCCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_SYSOSCCTRL.BYPASS Field          */
#define SYSCON_SYSOSCCTRL_FREQRANGE_MASK         (0x2U)                                              /*!< SYSCON_SYSOSCCTRL.FREQRANGE Mask        */
#define SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT        (1U)                                                /*!< SYSCON_SYSOSCCTRL.FREQRANGE Position    */
#define SYSCON_SYSOSCCTRL_FREQRANGE(x)           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_SYSOSCCTRL.FREQRANGE Field       */
/* ------- WDTOSCCTRL Bit Fields                    ------ */
#define SYSCON_WDTOSCCTRL_DIVSEL_MASK            (0x1FU)                                             /*!< SYSCON_WDTOSCCTRL.DIVSEL Mask           */
#define SYSCON_WDTOSCCTRL_DIVSEL_SHIFT           (0U)                                                /*!< SYSCON_WDTOSCCTRL.DIVSEL Position       */
#define SYSCON_WDTOSCCTRL_DIVSEL(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< SYSCON_WDTOSCCTRL.DIVSEL Field          */
#define SYSCON_WDTOSCCTRL_FREQSEL_MASK           (0x1E0U)                                            /*!< SYSCON_WDTOSCCTRL.FREQSEL Mask          */
#define SYSCON_WDTOSCCTRL_FREQSEL_SHIFT          (5U)                                                /*!< SYSCON_WDTOSCCTRL.FREQSEL Position      */
#define SYSCON_WDTOSCCTRL_FREQSEL(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x1E0UL)         /*!< SYSCON_WDTOSCCTRL.FREQSEL Field         */
/* ------- IRCCTRL Bit Fields                       ------ */
#define SYSCON_IRCCTRL_TRIM_MASK                 (0xFFU)                                             /*!< SYSCON_IRCCTRL.TRIM Mask                */
#define SYSCON_IRCCTRL_TRIM_SHIFT                (0U)                                                /*!< SYSCON_IRCCTRL.TRIM Position            */
#define SYSCON_IRCCTRL_TRIM(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< SYSCON_IRCCTRL.TRIM Field               */
/* ------- SYSRSTSTAT Bit Fields                    ------ */
#define SYSCON_SYSRSTSTAT_POR_MASK               (0x1U)                                              /*!< SYSCON_SYSRSTSTAT.POR Mask              */
#define SYSCON_SYSRSTSTAT_POR_SHIFT              (0U)                                                /*!< SYSCON_SYSRSTSTAT.POR Position          */
#define SYSCON_SYSRSTSTAT_POR(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_SYSRSTSTAT.POR Field             */
#define SYSCON_SYSRSTSTAT_EXTRST_MASK            (0x2U)                                              /*!< SYSCON_SYSRSTSTAT.EXTRST Mask           */
#define SYSCON_SYSRSTSTAT_EXTRST_SHIFT           (1U)                                                /*!< SYSCON_SYSRSTSTAT.EXTRST Position       */
#define SYSCON_SYSRSTSTAT_EXTRST(x)              (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_SYSRSTSTAT.EXTRST Field          */
#define SYSCON_SYSRSTSTAT_WDT_MASK               (0x4U)                                              /*!< SYSCON_SYSRSTSTAT.WDT Mask              */
#define SYSCON_SYSRSTSTAT_WDT_SHIFT              (2U)                                                /*!< SYSCON_SYSRSTSTAT.WDT Position          */
#define SYSCON_SYSRSTSTAT_WDT(x)                 (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_SYSRSTSTAT.WDT Field             */
#define SYSCON_SYSRSTSTAT_BOD_MASK               (0x8U)                                              /*!< SYSCON_SYSRSTSTAT.BOD Mask              */
#define SYSCON_SYSRSTSTAT_BOD_SHIFT              (3U)                                                /*!< SYSCON_SYSRSTSTAT.BOD Position          */
#define SYSCON_SYSRSTSTAT_BOD(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_SYSRSTSTAT.BOD Field             */
#define SYSCON_SYSRSTSTAT_SYSRST_MASK            (0x10U)                                             /*!< SYSCON_SYSRSTSTAT.SYSRST Mask           */
#define SYSCON_SYSRSTSTAT_SYSRST_SHIFT           (4U)                                                /*!< SYSCON_SYSRSTSTAT.SYSRST Position       */
#define SYSCON_SYSRSTSTAT_SYSRST(x)              (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_SYSRSTSTAT.SYSRST Field          */
/* ------- SYSPLLCLKSEL Bit Fields                  ------ */
#define SYSCON_SYSPLLCLKSEL_SEL_MASK             (0x3U)                                              /*!< SYSCON_SYSPLLCLKSEL.SEL Mask            */
#define SYSCON_SYSPLLCLKSEL_SEL_SHIFT            (0U)                                                /*!< SYSCON_SYSPLLCLKSEL.SEL Position        */
#define SYSCON_SYSPLLCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< SYSCON_SYSPLLCLKSEL.SEL Field           */
/* ------- SYSPLLCLKUEN Bit Fields                  ------ */
#define SYSCON_SYSPLLCLKUEN_ENA_MASK             (0x1U)                                              /*!< SYSCON_SYSPLLCLKUEN.ENA Mask            */
#define SYSCON_SYSPLLCLKUEN_ENA_SHIFT            (0U)                                                /*!< SYSCON_SYSPLLCLKUEN.ENA Position        */
#define SYSCON_SYSPLLCLKUEN_ENA(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_SYSPLLCLKUEN.ENA Field           */
/* ------- MAINCLKSEL Bit Fields                    ------ */
#define SYSCON_MAINCLKSEL_SEL_MASK               (0x3U)                                              /*!< SYSCON_MAINCLKSEL.SEL Mask              */
#define SYSCON_MAINCLKSEL_SEL_SHIFT              (0U)                                                /*!< SYSCON_MAINCLKSEL.SEL Position          */
#define SYSCON_MAINCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< SYSCON_MAINCLKSEL.SEL Field             */
/* ------- MAINCLKUEN Bit Fields                    ------ */
#define SYSCON_MAINCLKUEN_ENA_MASK               (0x1U)                                              /*!< SYSCON_MAINCLKUEN.ENA Mask              */
#define SYSCON_MAINCLKUEN_ENA_SHIFT              (0U)                                                /*!< SYSCON_MAINCLKUEN.ENA Position          */
#define SYSCON_MAINCLKUEN_ENA(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_MAINCLKUEN.ENA Field             */
/* ------- SYSAHBCLKDIV Bit Fields                  ------ */
#define SYSCON_SYSAHBCLKDIV_DIV_MASK             (0xFFU)                                             /*!< SYSCON_SYSAHBCLKDIV.DIV Mask            */
#define SYSCON_SYSAHBCLKDIV_DIV_SHIFT            (0U)                                                /*!< SYSCON_SYSAHBCLKDIV.DIV Position        */
#define SYSCON_SYSAHBCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< SYSCON_SYSAHBCLKDIV.DIV Field           */
/* ------- SYSAHBCLKCTRL Bit Fields                 ------ */
#define SYSCON_SYSAHBCLKCTRL_SYS_MASK            (0x1U)                                              /*!< SYSCON_SYSAHBCLKCTRL.SYS Mask           */
#define SYSCON_SYSAHBCLKCTRL_SYS_SHIFT           (0U)                                                /*!< SYSCON_SYSAHBCLKCTRL.SYS Position       */
#define SYSCON_SYSAHBCLKCTRL_SYS(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_SYSAHBCLKCTRL.SYS Field          */
#define SYSCON_SYSAHBCLKCTRL_ROM_MASK            (0x2U)                                              /*!< SYSCON_SYSAHBCLKCTRL.ROM Mask           */
#define SYSCON_SYSAHBCLKCTRL_ROM_SHIFT           (1U)                                                /*!< SYSCON_SYSAHBCLKCTRL.ROM Position       */
#define SYSCON_SYSAHBCLKCTRL_ROM(x)              (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_SYSAHBCLKCTRL.ROM Field          */
#define SYSCON_SYSAHBCLKCTRL_RAM_MASK            (0x4U)                                              /*!< SYSCON_SYSAHBCLKCTRL.RAM Mask           */
#define SYSCON_SYSAHBCLKCTRL_RAM_SHIFT           (2U)                                                /*!< SYSCON_SYSAHBCLKCTRL.RAM Position       */
#define SYSCON_SYSAHBCLKCTRL_RAM(x)              (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_SYSAHBCLKCTRL.RAM Field          */
#define SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK       (0x8U)                                              /*!< SYSCON_SYSAHBCLKCTRL.FLASHREG Mask      */
#define SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT      (3U)                                                /*!< SYSCON_SYSAHBCLKCTRL.FLASHREG Position  */
#define SYSCON_SYSAHBCLKCTRL_FLASHREG(x)         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_SYSAHBCLKCTRL.FLASHREG Field     */
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK     (0x10U)                                             /*!< SYSCON_SYSAHBCLKCTRL.FLASHARRAY Mask    */
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY_SHIFT    (4U)                                                /*!< SYSCON_SYSAHBCLKCTRL.FLASHARRAY Position*/
#define SYSCON_SYSAHBCLKCTRL_FLASHARRAY(x)       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_SYSAHBCLKCTRL.FLASHARRAY Field   */
#define SYSCON_SYSAHBCLKCTRL_I2C_MASK            (0x20U)                                             /*!< SYSCON_SYSAHBCLKCTRL.I2C Mask           */
#define SYSCON_SYSAHBCLKCTRL_I2C_SHIFT           (5U)                                                /*!< SYSCON_SYSAHBCLKCTRL.I2C Position       */
#define SYSCON_SYSAHBCLKCTRL_I2C(x)              (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SYSCON_SYSAHBCLKCTRL.I2C Field          */
#define SYSCON_SYSAHBCLKCTRL_GPIO_MASK           (0x40U)                                             /*!< SYSCON_SYSAHBCLKCTRL.GPIO Mask          */
#define SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT          (6U)                                                /*!< SYSCON_SYSAHBCLKCTRL.GPIO Position      */
#define SYSCON_SYSAHBCLKCTRL_GPIO(x)             (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_SYSAHBCLKCTRL.GPIO Field         */
#define SYSCON_SYSAHBCLKCTRL_CT16B0_MASK         (0x80U)                                             /*!< SYSCON_SYSAHBCLKCTRL.CT16B0 Mask        */
#define SYSCON_SYSAHBCLKCTRL_CT16B0_SHIFT        (7U)                                                /*!< SYSCON_SYSAHBCLKCTRL.CT16B0 Position    */
#define SYSCON_SYSAHBCLKCTRL_CT16B0(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_SYSAHBCLKCTRL.CT16B0 Field       */
#define SYSCON_SYSAHBCLKCTRL_CT16B1_MASK         (0x100U)                                            /*!< SYSCON_SYSAHBCLKCTRL.CT16B1 Mask        */
#define SYSCON_SYSAHBCLKCTRL_CT16B1_SHIFT        (8U)                                                /*!< SYSCON_SYSAHBCLKCTRL.CT16B1 Position    */
#define SYSCON_SYSAHBCLKCTRL_CT16B1(x)           (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SYSCON_SYSAHBCLKCTRL.CT16B1 Field       */
#define SYSCON_SYSAHBCLKCTRL_CT32B0_MASK         (0x200U)                                            /*!< SYSCON_SYSAHBCLKCTRL.CT32B0 Mask        */
#define SYSCON_SYSAHBCLKCTRL_CT32B0_SHIFT        (9U)                                                /*!< SYSCON_SYSAHBCLKCTRL.CT32B0 Position    */
#define SYSCON_SYSAHBCLKCTRL_CT32B0(x)           (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SYSCON_SYSAHBCLKCTRL.CT32B0 Field       */
#define SYSCON_SYSAHBCLKCTRL_CT32B1_MASK         (0x400U)                                            /*!< SYSCON_SYSAHBCLKCTRL.CT32B1 Mask        */
#define SYSCON_SYSAHBCLKCTRL_CT32B1_SHIFT        (10U)                                               /*!< SYSCON_SYSAHBCLKCTRL.CT32B1 Position    */
#define SYSCON_SYSAHBCLKCTRL_CT32B1(x)           (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SYSCON_SYSAHBCLKCTRL.CT32B1 Field       */
#define SYSCON_SYSAHBCLKCTRL_SSP0_MASK           (0x800U)                                            /*!< SYSCON_SYSAHBCLKCTRL.SSP0 Mask          */
#define SYSCON_SYSAHBCLKCTRL_SSP0_SHIFT          (11U)                                               /*!< SYSCON_SYSAHBCLKCTRL.SSP0 Position      */
#define SYSCON_SYSAHBCLKCTRL_SSP0(x)             (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SYSCON_SYSAHBCLKCTRL.SSP0 Field         */
#define SYSCON_SYSAHBCLKCTRL_UART_MASK           (0x1000U)                                           /*!< SYSCON_SYSAHBCLKCTRL.UART Mask          */
#define SYSCON_SYSAHBCLKCTRL_UART_SHIFT          (12U)                                               /*!< SYSCON_SYSAHBCLKCTRL.UART Position      */
#define SYSCON_SYSAHBCLKCTRL_UART(x)             (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SYSCON_SYSAHBCLKCTRL.UART Field         */
#define SYSCON_SYSAHBCLKCTRL_ADC_MASK            (0x2000U)                                           /*!< SYSCON_SYSAHBCLKCTRL.ADC Mask           */
#define SYSCON_SYSAHBCLKCTRL_ADC_SHIFT           (13U)                                               /*!< SYSCON_SYSAHBCLKCTRL.ADC Position       */
#define SYSCON_SYSAHBCLKCTRL_ADC(x)              (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SYSCON_SYSAHBCLKCTRL.ADC Field          */
#define SYSCON_SYSAHBCLKCTRL_WDT_MASK            (0x8000U)                                           /*!< SYSCON_SYSAHBCLKCTRL.WDT Mask           */
#define SYSCON_SYSAHBCLKCTRL_WDT_SHIFT           (15U)                                               /*!< SYSCON_SYSAHBCLKCTRL.WDT Position       */
#define SYSCON_SYSAHBCLKCTRL_WDT(x)              (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< SYSCON_SYSAHBCLKCTRL.WDT Field          */
#define SYSCON_SYSAHBCLKCTRL_IOCON_MASK          (0x10000U)                                          /*!< SYSCON_SYSAHBCLKCTRL.IOCON Mask         */
#define SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT         (16U)                                               /*!< SYSCON_SYSAHBCLKCTRL.IOCON Position     */
#define SYSCON_SYSAHBCLKCTRL_IOCON(x)            (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SYSCON_SYSAHBCLKCTRL.IOCON Field        */
#define SYSCON_SYSAHBCLKCTRL_CAN_MASK            (0x20000U)                                          /*!< SYSCON_SYSAHBCLKCTRL.CAN Mask           */
#define SYSCON_SYSAHBCLKCTRL_CAN_SHIFT           (17U)                                               /*!< SYSCON_SYSAHBCLKCTRL.CAN Position       */
#define SYSCON_SYSAHBCLKCTRL_CAN(x)              (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SYSCON_SYSAHBCLKCTRL.CAN Field          */
#define SYSCON_SYSAHBCLKCTRL_SSP1_MASK           (0x40000U)                                          /*!< SYSCON_SYSAHBCLKCTRL.SSP1 Mask          */
#define SYSCON_SYSAHBCLKCTRL_SSP1_SHIFT          (18U)                                               /*!< SYSCON_SYSAHBCLKCTRL.SSP1 Position      */
#define SYSCON_SYSAHBCLKCTRL_SSP1(x)             (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< SYSCON_SYSAHBCLKCTRL.SSP1 Field         */
/* ------- SSP0CLKDIV Bit Fields                    ------ */
#define SYSCON_SSP0CLKDIV_DIV_MASK               (0xFFU)                                             /*!< SYSCON_SSP0CLKDIV.DIV Mask              */
#define SYSCON_SSP0CLKDIV_DIV_SHIFT              (0U)                                                /*!< SYSCON_SSP0CLKDIV.DIV Position          */
#define SYSCON_SSP0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< SYSCON_SSP0CLKDIV.DIV Field             */
/* ------- UARTCLKDIV Bit Fields                    ------ */
#define SYSCON_UARTCLKDIV_DIV_MASK               (0xFFU)                                             /*!< SYSCON_UARTCLKDIV.DIV Mask              */
#define SYSCON_UARTCLKDIV_DIV_SHIFT              (0U)                                                /*!< SYSCON_UARTCLKDIV.DIV Position          */
#define SYSCON_UARTCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< SYSCON_UARTCLKDIV.DIV Field             */
/* ------- SSP1CLKDIV Bit Fields                    ------ */
#define SYSCON_SSP1CLKDIV_DIV_MASK               (0xFFU)                                             /*!< SYSCON_SSP1CLKDIV.DIV Mask              */
#define SYSCON_SSP1CLKDIV_DIV_SHIFT              (0U)                                                /*!< SYSCON_SSP1CLKDIV.DIV Position          */
#define SYSCON_SSP1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< SYSCON_SSP1CLKDIV.DIV Field             */
/* ------- WDTCLKSEL Bit Fields                     ------ */
#define SYSCON_WDTCLKSEL_SEL_MASK                (0x3U)                                              /*!< SYSCON_WDTCLKSEL.SEL Mask               */
#define SYSCON_WDTCLKSEL_SEL_SHIFT               (0U)                                                /*!< SYSCON_WDTCLKSEL.SEL Position           */
#define SYSCON_WDTCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< SYSCON_WDTCLKSEL.SEL Field              */
/* ------- WDTCLKUEN Bit Fields                     ------ */
#define SYSCON_WDTCLKUEN_ENA_MASK                (0x1U)                                              /*!< SYSCON_WDTCLKUEN.ENA Mask               */
#define SYSCON_WDTCLKUEN_ENA_SHIFT               (0U)                                                /*!< SYSCON_WDTCLKUEN.ENA Position           */
#define SYSCON_WDTCLKUEN_ENA(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_WDTCLKUEN.ENA Field              */
/* ------- WDTCLKDIV Bit Fields                     ------ */
#define SYSCON_WDTCLKDIV_DIV_MASK                (0xFFU)                                             /*!< SYSCON_WDTCLKDIV.DIV Mask               */
#define SYSCON_WDTCLKDIV_DIV_SHIFT               (0U)                                                /*!< SYSCON_WDTCLKDIV.DIV Position           */
#define SYSCON_WDTCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< SYSCON_WDTCLKDIV.DIV Field              */
/* ------- CLKOUTCLKSEL Bit Fields                  ------ */
#define SYSCON_CLKOUTCLKSEL_SEL_MASK             (0x3U)                                              /*!< SYSCON_CLKOUTCLKSEL.SEL Mask            */
#define SYSCON_CLKOUTCLKSEL_SEL_SHIFT            (0U)                                                /*!< SYSCON_CLKOUTCLKSEL.SEL Position        */
#define SYSCON_CLKOUTCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< SYSCON_CLKOUTCLKSEL.SEL Field           */
/* ------- CLKOUTUEN Bit Fields                     ------ */
#define SYSCON_CLKOUTUEN_ENA_MASK                (0x1U)                                              /*!< SYSCON_CLKOUTUEN.ENA Mask               */
#define SYSCON_CLKOUTUEN_ENA_SHIFT               (0U)                                                /*!< SYSCON_CLKOUTUEN.ENA Position           */
#define SYSCON_CLKOUTUEN_ENA(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_CLKOUTUEN.ENA Field              */
/* ------- CLKOUTCLKDIV Bit Fields                  ------ */
#define SYSCON_CLKOUTCLKDIV_DIV_MASK             (0xFFU)                                             /*!< SYSCON_CLKOUTCLKDIV.DIV Mask            */
#define SYSCON_CLKOUTCLKDIV_DIV_SHIFT            (0U)                                                /*!< SYSCON_CLKOUTCLKDIV.DIV Position        */
#define SYSCON_CLKOUTCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< SYSCON_CLKOUTCLKDIV.DIV Field           */
/* ------- PIOPORCAP0 Bit Fields                    ------ */
#define SYSCON_PIOPORCAP0_CAPPIO0_n_MASK         (0xFFFU)                                            /*!< SYSCON_PIOPORCAP0.CAPPIO0_n Mask        */
#define SYSCON_PIOPORCAP0_CAPPIO0_n_SHIFT        (0U)                                                /*!< SYSCON_PIOPORCAP0.CAPPIO0_n Position    */
#define SYSCON_PIOPORCAP0_CAPPIO0_n(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFUL)         /*!< SYSCON_PIOPORCAP0.CAPPIO0_n Field       */
#define SYSCON_PIOPORCAP0_CAPPIO1_n_MASK         (0xFFF000U)                                         /*!< SYSCON_PIOPORCAP0.CAPPIO1_n Mask        */
#define SYSCON_PIOPORCAP0_CAPPIO1_n_SHIFT        (12U)                                               /*!< SYSCON_PIOPORCAP0.CAPPIO1_n Position    */
#define SYSCON_PIOPORCAP0_CAPPIO1_n(x)           (((uint32_t)(((uint32_t)(x))<<12U))&0xFFF000UL)     /*!< SYSCON_PIOPORCAP0.CAPPIO1_n Field       */
#define SYSCON_PIOPORCAP0_CAPPIO2_n_MASK         (0xFF000000U)                                       /*!< SYSCON_PIOPORCAP0.CAPPIO2_n Mask        */
#define SYSCON_PIOPORCAP0_CAPPIO2_n_SHIFT        (24U)                                               /*!< SYSCON_PIOPORCAP0.CAPPIO2_n Position    */
#define SYSCON_PIOPORCAP0_CAPPIO2_n(x)           (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< SYSCON_PIOPORCAP0.CAPPIO2_n Field       */
/* ------- PIOPORCAP1 Bit Fields                    ------ */
#define SYSCON_PIOPORCAP1_CAPPIO2_8_MASK         (0x1U)                                              /*!< SYSCON_PIOPORCAP1.CAPPIO2_8 Mask        */
#define SYSCON_PIOPORCAP1_CAPPIO2_8_SHIFT        (0U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO2_8 Position    */
#define SYSCON_PIOPORCAP1_CAPPIO2_8(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_PIOPORCAP1.CAPPIO2_8 Field       */
#define SYSCON_PIOPORCAP1_CAPPIO2_9_MASK         (0x2U)                                              /*!< SYSCON_PIOPORCAP1.CAPPIO2_9 Mask        */
#define SYSCON_PIOPORCAP1_CAPPIO2_9_SHIFT        (1U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO2_9 Position    */
#define SYSCON_PIOPORCAP1_CAPPIO2_9(x)           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_PIOPORCAP1.CAPPIO2_9 Field       */
#define SYSCON_PIOPORCAP1_CAPPIO2_10_MASK        (0x4U)                                              /*!< SYSCON_PIOPORCAP1.CAPPIO2_10 Mask       */
#define SYSCON_PIOPORCAP1_CAPPIO2_10_SHIFT       (2U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO2_10 Position   */
#define SYSCON_PIOPORCAP1_CAPPIO2_10(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_PIOPORCAP1.CAPPIO2_10 Field      */
#define SYSCON_PIOPORCAP1_CAPPIO2_11_MASK        (0x8U)                                              /*!< SYSCON_PIOPORCAP1.CAPPIO2_11 Mask       */
#define SYSCON_PIOPORCAP1_CAPPIO2_11_SHIFT       (3U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO2_11 Position   */
#define SYSCON_PIOPORCAP1_CAPPIO2_11(x)          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_PIOPORCAP1.CAPPIO2_11 Field      */
#define SYSCON_PIOPORCAP1_CAPPIO3_0_MASK         (0x10U)                                             /*!< SYSCON_PIOPORCAP1.CAPPIO3_0 Mask        */
#define SYSCON_PIOPORCAP1_CAPPIO3_0_SHIFT        (4U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO3_0 Position    */
#define SYSCON_PIOPORCAP1_CAPPIO3_0(x)           (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_PIOPORCAP1.CAPPIO3_0 Field       */
#define SYSCON_PIOPORCAP1_CAPPIO3_1_MASK         (0x20U)                                             /*!< SYSCON_PIOPORCAP1.CAPPIO3_1 Mask        */
#define SYSCON_PIOPORCAP1_CAPPIO3_1_SHIFT        (5U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO3_1 Position    */
#define SYSCON_PIOPORCAP1_CAPPIO3_1(x)           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SYSCON_PIOPORCAP1.CAPPIO3_1 Field       */
#define SYSCON_PIOPORCAP1_CAPPIO3_2_MASK         (0x40U)                                             /*!< SYSCON_PIOPORCAP1.CAPPIO3_2 Mask        */
#define SYSCON_PIOPORCAP1_CAPPIO3_2_SHIFT        (6U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO3_2 Position    */
#define SYSCON_PIOPORCAP1_CAPPIO3_2(x)           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_PIOPORCAP1.CAPPIO3_2 Field       */
#define SYSCON_PIOPORCAP1_CAPPIO3_3_MASK         (0x80U)                                             /*!< SYSCON_PIOPORCAP1.CAPPIO3_3 Mask        */
#define SYSCON_PIOPORCAP1_CAPPIO3_3_SHIFT        (7U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO3_3 Position    */
#define SYSCON_PIOPORCAP1_CAPPIO3_3(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_PIOPORCAP1.CAPPIO3_3 Field       */
#define SYSCON_PIOPORCAP1_CAPPIO3_4_MASK         (0x100U)                                            /*!< SYSCON_PIOPORCAP1.CAPPIO3_4 Mask        */
#define SYSCON_PIOPORCAP1_CAPPIO3_4_SHIFT        (8U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO3_4 Position    */
#define SYSCON_PIOPORCAP1_CAPPIO3_4(x)           (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SYSCON_PIOPORCAP1.CAPPIO3_4 Field       */
#define SYSCON_PIOPORCAP1_CAPPIO3_5_MASK         (0x200U)                                            /*!< SYSCON_PIOPORCAP1.CAPPIO3_5 Mask        */
#define SYSCON_PIOPORCAP1_CAPPIO3_5_SHIFT        (9U)                                                /*!< SYSCON_PIOPORCAP1.CAPPIO3_5 Position    */
#define SYSCON_PIOPORCAP1_CAPPIO3_5(x)           (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SYSCON_PIOPORCAP1.CAPPIO3_5 Field       */
/* ------- BODCTRL Bit Fields                       ------ */
#define SYSCON_BODCTRL_BODRSTLEV_MASK            (0x3U)                                              /*!< SYSCON_BODCTRL.BODRSTLEV Mask           */
#define SYSCON_BODCTRL_BODRSTLEV_SHIFT           (0U)                                                /*!< SYSCON_BODCTRL.BODRSTLEV Position       */
#define SYSCON_BODCTRL_BODRSTLEV(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< SYSCON_BODCTRL.BODRSTLEV Field          */
#define SYSCON_BODCTRL_BODINTVAL_MASK            (0xCU)                                              /*!< SYSCON_BODCTRL.BODINTVAL Mask           */
#define SYSCON_BODCTRL_BODINTVAL_SHIFT           (2U)                                                /*!< SYSCON_BODCTRL.BODINTVAL Position       */
#define SYSCON_BODCTRL_BODINTVAL(x)              (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< SYSCON_BODCTRL.BODINTVAL Field          */
#define SYSCON_BODCTRL_BODRSTENA_MASK            (0x10U)                                             /*!< SYSCON_BODCTRL.BODRSTENA Mask           */
#define SYSCON_BODCTRL_BODRSTENA_SHIFT           (4U)                                                /*!< SYSCON_BODCTRL.BODRSTENA Position       */
#define SYSCON_BODCTRL_BODRSTENA(x)              (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_BODCTRL.BODRSTENA Field          */
/* ------- SYSTCKCAL Bit Fields                     ------ */
#define SYSCON_SYSTCKCAL_CAL_MASK                (0x3FFFFFFU)                                        /*!< SYSCON_SYSTCKCAL.CAL Mask               */
#define SYSCON_SYSTCKCAL_CAL_SHIFT               (0U)                                                /*!< SYSCON_SYSTCKCAL.CAL Position           */
#define SYSCON_SYSTCKCAL_CAL(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFFFUL)     /*!< SYSCON_SYSTCKCAL.CAL Field              */
/* ------- NMISRC Bit Fields                        ------ */
#define SYSCON_NMISRC_IRQNO_MASK                 (0x1FU)                                             /*!< SYSCON_NMISRC.IRQNO Mask                */
#define SYSCON_NMISRC_IRQNO_SHIFT                (0U)                                                /*!< SYSCON_NMISRC.IRQNO Position            */
#define SYSCON_NMISRC_IRQNO(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< SYSCON_NMISRC.IRQNO Field               */
#define SYSCON_NMISRC_NMIEN_MASK                 (0x80000000U)                                       /*!< SYSCON_NMISRC.NMIEN Mask                */
#define SYSCON_NMISRC_NMIEN_SHIFT                (31U)                                               /*!< SYSCON_NMISRC.NMIEN Position            */
#define SYSCON_NMISRC_NMIEN(x)                   (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SYSCON_NMISRC.NMIEN Field               */
/* ------- STARTAPRP0 Bit Fields                    ------ */
#define SYSCON_STARTAPRP0_APRPIO0_0_MASK         (0x1U)                                              /*!< SYSCON_STARTAPRP0.APRPIO0_0 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_0_SHIFT        (0U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_0 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_0(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_STARTAPRP0.APRPIO0_0 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_1_MASK         (0x2U)                                              /*!< SYSCON_STARTAPRP0.APRPIO0_1 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_1_SHIFT        (1U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_1 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_1(x)           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_STARTAPRP0.APRPIO0_1 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_2_MASK         (0x4U)                                              /*!< SYSCON_STARTAPRP0.APRPIO0_2 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_2_SHIFT        (2U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_2 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_2(x)           (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_STARTAPRP0.APRPIO0_2 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_3_MASK         (0x8U)                                              /*!< SYSCON_STARTAPRP0.APRPIO0_3 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_3_SHIFT        (3U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_3 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_3(x)           (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_STARTAPRP0.APRPIO0_3 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_4_MASK         (0x10U)                                             /*!< SYSCON_STARTAPRP0.APRPIO0_4 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_4_SHIFT        (4U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_4 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_4(x)           (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_STARTAPRP0.APRPIO0_4 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_5_MASK         (0x20U)                                             /*!< SYSCON_STARTAPRP0.APRPIO0_5 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_5_SHIFT        (5U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_5 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_5(x)           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SYSCON_STARTAPRP0.APRPIO0_5 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_6_MASK         (0x40U)                                             /*!< SYSCON_STARTAPRP0.APRPIO0_6 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_6_SHIFT        (6U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_6 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_6(x)           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_STARTAPRP0.APRPIO0_6 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_7_MASK         (0x80U)                                             /*!< SYSCON_STARTAPRP0.APRPIO0_7 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_7_SHIFT        (7U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_7 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_7(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_STARTAPRP0.APRPIO0_7 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_8_MASK         (0x100U)                                            /*!< SYSCON_STARTAPRP0.APRPIO0_8 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_8_SHIFT        (8U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_8 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_8(x)           (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SYSCON_STARTAPRP0.APRPIO0_8 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_9_MASK         (0x200U)                                            /*!< SYSCON_STARTAPRP0.APRPIO0_9 Mask        */
#define SYSCON_STARTAPRP0_APRPIO0_9_SHIFT        (9U)                                                /*!< SYSCON_STARTAPRP0.APRPIO0_9 Position    */
#define SYSCON_STARTAPRP0_APRPIO0_9(x)           (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SYSCON_STARTAPRP0.APRPIO0_9 Field       */
#define SYSCON_STARTAPRP0_APRPIO0_10_MASK        (0x400U)                                            /*!< SYSCON_STARTAPRP0.APRPIO0_10 Mask       */
#define SYSCON_STARTAPRP0_APRPIO0_10_SHIFT       (10U)                                               /*!< SYSCON_STARTAPRP0.APRPIO0_10 Position   */
#define SYSCON_STARTAPRP0_APRPIO0_10(x)          (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SYSCON_STARTAPRP0.APRPIO0_10 Field      */
#define SYSCON_STARTAPRP0_APRPIO0_11_MASK        (0x800U)                                            /*!< SYSCON_STARTAPRP0.APRPIO0_11 Mask       */
#define SYSCON_STARTAPRP0_APRPIO0_11_SHIFT       (11U)                                               /*!< SYSCON_STARTAPRP0.APRPIO0_11 Position   */
#define SYSCON_STARTAPRP0_APRPIO0_11(x)          (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SYSCON_STARTAPRP0.APRPIO0_11 Field      */
#define SYSCON_STARTAPRP0_APRPIO1_0_MASK         (0x1000U)                                           /*!< SYSCON_STARTAPRP0.APRPIO1_0 Mask        */
#define SYSCON_STARTAPRP0_APRPIO1_0_SHIFT        (12U)                                               /*!< SYSCON_STARTAPRP0.APRPIO1_0 Position    */
#define SYSCON_STARTAPRP0_APRPIO1_0(x)           (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SYSCON_STARTAPRP0.APRPIO1_0 Field       */
/* ------- STARTERP0 Bit Fields                     ------ */
#define SYSCON_STARTERP0_ERPIO0_0_MASK           (0x1U)                                              /*!< SYSCON_STARTERP0.ERPIO0_0 Mask          */
#define SYSCON_STARTERP0_ERPIO0_0_SHIFT          (0U)                                                /*!< SYSCON_STARTERP0.ERPIO0_0 Position      */
#define SYSCON_STARTERP0_ERPIO0_0(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_STARTERP0.ERPIO0_0 Field         */
#define SYSCON_STARTERP0_ERPIO0_1_MASK           (0x2U)                                              /*!< SYSCON_STARTERP0.ERPIO0_1 Mask          */
#define SYSCON_STARTERP0_ERPIO0_1_SHIFT          (1U)                                                /*!< SYSCON_STARTERP0.ERPIO0_1 Position      */
#define SYSCON_STARTERP0_ERPIO0_1(x)             (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_STARTERP0.ERPIO0_1 Field         */
#define SYSCON_STARTERP0_ERPIO0_2_MASK           (0x4U)                                              /*!< SYSCON_STARTERP0.ERPIO0_2 Mask          */
#define SYSCON_STARTERP0_ERPIO0_2_SHIFT          (2U)                                                /*!< SYSCON_STARTERP0.ERPIO0_2 Position      */
#define SYSCON_STARTERP0_ERPIO0_2(x)             (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_STARTERP0.ERPIO0_2 Field         */
#define SYSCON_STARTERP0_ERPIO0_3_MASK           (0x8U)                                              /*!< SYSCON_STARTERP0.ERPIO0_3 Mask          */
#define SYSCON_STARTERP0_ERPIO0_3_SHIFT          (3U)                                                /*!< SYSCON_STARTERP0.ERPIO0_3 Position      */
#define SYSCON_STARTERP0_ERPIO0_3(x)             (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_STARTERP0.ERPIO0_3 Field         */
#define SYSCON_STARTERP0_ERPIO0_4_MASK           (0x10U)                                             /*!< SYSCON_STARTERP0.ERPIO0_4 Mask          */
#define SYSCON_STARTERP0_ERPIO0_4_SHIFT          (4U)                                                /*!< SYSCON_STARTERP0.ERPIO0_4 Position      */
#define SYSCON_STARTERP0_ERPIO0_4(x)             (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_STARTERP0.ERPIO0_4 Field         */
#define SYSCON_STARTERP0_ERPIO0_5_MASK           (0x20U)                                             /*!< SYSCON_STARTERP0.ERPIO0_5 Mask          */
#define SYSCON_STARTERP0_ERPIO0_5_SHIFT          (5U)                                                /*!< SYSCON_STARTERP0.ERPIO0_5 Position      */
#define SYSCON_STARTERP0_ERPIO0_5(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SYSCON_STARTERP0.ERPIO0_5 Field         */
#define SYSCON_STARTERP0_ERPIO0_6_MASK           (0x40U)                                             /*!< SYSCON_STARTERP0.ERPIO0_6 Mask          */
#define SYSCON_STARTERP0_ERPIO0_6_SHIFT          (6U)                                                /*!< SYSCON_STARTERP0.ERPIO0_6 Position      */
#define SYSCON_STARTERP0_ERPIO0_6(x)             (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_STARTERP0.ERPIO0_6 Field         */
#define SYSCON_STARTERP0_ERPIO0_7_MASK           (0x80U)                                             /*!< SYSCON_STARTERP0.ERPIO0_7 Mask          */
#define SYSCON_STARTERP0_ERPIO0_7_SHIFT          (7U)                                                /*!< SYSCON_STARTERP0.ERPIO0_7 Position      */
#define SYSCON_STARTERP0_ERPIO0_7(x)             (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_STARTERP0.ERPIO0_7 Field         */
#define SYSCON_STARTERP0_ERPIO0_8_MASK           (0x100U)                                            /*!< SYSCON_STARTERP0.ERPIO0_8 Mask          */
#define SYSCON_STARTERP0_ERPIO0_8_SHIFT          (8U)                                                /*!< SYSCON_STARTERP0.ERPIO0_8 Position      */
#define SYSCON_STARTERP0_ERPIO0_8(x)             (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SYSCON_STARTERP0.ERPIO0_8 Field         */
#define SYSCON_STARTERP0_ERPIO0_9_MASK           (0x200U)                                            /*!< SYSCON_STARTERP0.ERPIO0_9 Mask          */
#define SYSCON_STARTERP0_ERPIO0_9_SHIFT          (9U)                                                /*!< SYSCON_STARTERP0.ERPIO0_9 Position      */
#define SYSCON_STARTERP0_ERPIO0_9(x)             (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SYSCON_STARTERP0.ERPIO0_9 Field         */
#define SYSCON_STARTERP0_ERPIO0_10_MASK          (0x400U)                                            /*!< SYSCON_STARTERP0.ERPIO0_10 Mask         */
#define SYSCON_STARTERP0_ERPIO0_10_SHIFT         (10U)                                               /*!< SYSCON_STARTERP0.ERPIO0_10 Position     */
#define SYSCON_STARTERP0_ERPIO0_10(x)            (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SYSCON_STARTERP0.ERPIO0_10 Field        */
#define SYSCON_STARTERP0_ERPIO0_11_MASK          (0x800U)                                            /*!< SYSCON_STARTERP0.ERPIO0_11 Mask         */
#define SYSCON_STARTERP0_ERPIO0_11_SHIFT         (11U)                                               /*!< SYSCON_STARTERP0.ERPIO0_11 Position     */
#define SYSCON_STARTERP0_ERPIO0_11(x)            (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SYSCON_STARTERP0.ERPIO0_11 Field        */
#define SYSCON_STARTERP0_ERPIO1_0_MASK           (0x1000U)                                           /*!< SYSCON_STARTERP0.ERPIO1_0 Mask          */
#define SYSCON_STARTERP0_ERPIO1_0_SHIFT          (12U)                                               /*!< SYSCON_STARTERP0.ERPIO1_0 Position      */
#define SYSCON_STARTERP0_ERPIO1_0(x)             (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SYSCON_STARTERP0.ERPIO1_0 Field         */
/* ------- STARTRSRP0CLR Bit Fields                 ------ */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_0_MASK      (0x1U)                                              /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_0 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_0_SHIFT     (0U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_0 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_0(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_0 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_1_MASK      (0x2U)                                              /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_1 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_1_SHIFT     (1U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_1 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_1(x)        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_1 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_2_MASK      (0x4U)                                              /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_2 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_2_SHIFT     (2U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_2 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_2(x)        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_2 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_3_MASK      (0x8U)                                              /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_3 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_3_SHIFT     (3U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_3 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_3(x)        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_3 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_4_MASK      (0x10U)                                             /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_4 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_4_SHIFT     (4U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_4 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_4(x)        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_4 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_5_MASK      (0x20U)                                             /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_5 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_5_SHIFT     (5U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_5 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_5(x)        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_5 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_6_MASK      (0x40U)                                             /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_6 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_6_SHIFT     (6U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_6 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_6(x)        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_6 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_7_MASK      (0x80U)                                             /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_7 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_7_SHIFT     (7U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_7 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_7(x)        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_7 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_8_MASK      (0x100U)                                            /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_8 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_8_SHIFT     (8U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_8 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_8(x)        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_8 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_9_MASK      (0x200U)                                            /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_9 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_9_SHIFT     (9U)                                                /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_9 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_9(x)        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_9 Field    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_10_MASK     (0x400U)                                            /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_10 Mask    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_10_SHIFT    (10U)                                               /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_10 Position*/
#define SYSCON_STARTRSRP0CLR_RSRPIO0_10(x)       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_10 Field   */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_11_MASK     (0x800U)                                            /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_11 Mask    */
#define SYSCON_STARTRSRP0CLR_RSRPIO0_11_SHIFT    (11U)                                               /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_11 Position*/
#define SYSCON_STARTRSRP0CLR_RSRPIO0_11(x)       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SYSCON_STARTRSRP0CLR.RSRPIO0_11 Field   */
#define SYSCON_STARTRSRP0CLR_RSRPIO1_0_MASK      (0x1000U)                                           /*!< SYSCON_STARTRSRP0CLR.RSRPIO1_0 Mask     */
#define SYSCON_STARTRSRP0CLR_RSRPIO1_0_SHIFT     (12U)                                               /*!< SYSCON_STARTRSRP0CLR.RSRPIO1_0 Position */
#define SYSCON_STARTRSRP0CLR_RSRPIO1_0(x)        (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SYSCON_STARTRSRP0CLR.RSRPIO1_0 Field    */
/* ------- STARTSRP0 Bit Fields                     ------ */
#define SYSCON_STARTSRP0_SRPIO0_0_MASK           (0x1U)                                              /*!< SYSCON_STARTSRP0.SRPIO0_0 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_0_SHIFT          (0U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_0 Position      */
#define SYSCON_STARTSRP0_SRPIO0_0(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_STARTSRP0.SRPIO0_0 Field         */
#define SYSCON_STARTSRP0_SRPIO0_1_MASK           (0x2U)                                              /*!< SYSCON_STARTSRP0.SRPIO0_1 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_1_SHIFT          (1U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_1 Position      */
#define SYSCON_STARTSRP0_SRPIO0_1(x)             (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_STARTSRP0.SRPIO0_1 Field         */
#define SYSCON_STARTSRP0_SRPIO0_2_MASK           (0x4U)                                              /*!< SYSCON_STARTSRP0.SRPIO0_2 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_2_SHIFT          (2U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_2 Position      */
#define SYSCON_STARTSRP0_SRPIO0_2(x)             (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_STARTSRP0.SRPIO0_2 Field         */
#define SYSCON_STARTSRP0_SRPIO0_3_MASK           (0x8U)                                              /*!< SYSCON_STARTSRP0.SRPIO0_3 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_3_SHIFT          (3U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_3 Position      */
#define SYSCON_STARTSRP0_SRPIO0_3(x)             (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_STARTSRP0.SRPIO0_3 Field         */
#define SYSCON_STARTSRP0_SRPIO0_4_MASK           (0x10U)                                             /*!< SYSCON_STARTSRP0.SRPIO0_4 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_4_SHIFT          (4U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_4 Position      */
#define SYSCON_STARTSRP0_SRPIO0_4(x)             (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_STARTSRP0.SRPIO0_4 Field         */
#define SYSCON_STARTSRP0_SRPIO0_5_MASK           (0x20U)                                             /*!< SYSCON_STARTSRP0.SRPIO0_5 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_5_SHIFT          (5U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_5 Position      */
#define SYSCON_STARTSRP0_SRPIO0_5(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SYSCON_STARTSRP0.SRPIO0_5 Field         */
#define SYSCON_STARTSRP0_SRPIO0_6_MASK           (0x40U)                                             /*!< SYSCON_STARTSRP0.SRPIO0_6 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_6_SHIFT          (6U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_6 Position      */
#define SYSCON_STARTSRP0_SRPIO0_6(x)             (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_STARTSRP0.SRPIO0_6 Field         */
#define SYSCON_STARTSRP0_SRPIO0_7_MASK           (0x80U)                                             /*!< SYSCON_STARTSRP0.SRPIO0_7 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_7_SHIFT          (7U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_7 Position      */
#define SYSCON_STARTSRP0_SRPIO0_7(x)             (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_STARTSRP0.SRPIO0_7 Field         */
#define SYSCON_STARTSRP0_SRPIO0_8_MASK           (0x100U)                                            /*!< SYSCON_STARTSRP0.SRPIO0_8 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_8_SHIFT          (8U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_8 Position      */
#define SYSCON_STARTSRP0_SRPIO0_8(x)             (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SYSCON_STARTSRP0.SRPIO0_8 Field         */
#define SYSCON_STARTSRP0_SRPIO0_9_MASK           (0x200U)                                            /*!< SYSCON_STARTSRP0.SRPIO0_9 Mask          */
#define SYSCON_STARTSRP0_SRPIO0_9_SHIFT          (9U)                                                /*!< SYSCON_STARTSRP0.SRPIO0_9 Position      */
#define SYSCON_STARTSRP0_SRPIO0_9(x)             (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SYSCON_STARTSRP0.SRPIO0_9 Field         */
#define SYSCON_STARTSRP0_SRPIO0_10_MASK          (0x400U)                                            /*!< SYSCON_STARTSRP0.SRPIO0_10 Mask         */
#define SYSCON_STARTSRP0_SRPIO0_10_SHIFT         (10U)                                               /*!< SYSCON_STARTSRP0.SRPIO0_10 Position     */
#define SYSCON_STARTSRP0_SRPIO0_10(x)            (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SYSCON_STARTSRP0.SRPIO0_10 Field        */
#define SYSCON_STARTSRP0_SRPIO0_11_MASK          (0x800U)                                            /*!< SYSCON_STARTSRP0.SRPIO0_11 Mask         */
#define SYSCON_STARTSRP0_SRPIO0_11_SHIFT         (11U)                                               /*!< SYSCON_STARTSRP0.SRPIO0_11 Position     */
#define SYSCON_STARTSRP0_SRPIO0_11(x)            (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SYSCON_STARTSRP0.SRPIO0_11 Field        */
#define SYSCON_STARTSRP0_SRPIO1_0_MASK           (0x1000U)                                           /*!< SYSCON_STARTSRP0.SRPIO1_0 Mask          */
#define SYSCON_STARTSRP0_SRPIO1_0_SHIFT          (12U)                                               /*!< SYSCON_STARTSRP0.SRPIO1_0 Position      */
#define SYSCON_STARTSRP0_SRPIO1_0(x)             (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SYSCON_STARTSRP0.SRPIO1_0 Field         */
/* ------- PDSLEEPCFG Bit Fields                    ------ */
#define SYSCON_PDSLEEPCFG_NOTUSED0_MASK          (0x7U)                                              /*!< SYSCON_PDSLEEPCFG.NOTUSED0 Mask         */
#define SYSCON_PDSLEEPCFG_NOTUSED0_SHIFT         (0U)                                                /*!< SYSCON_PDSLEEPCFG.NOTUSED0 Position     */
#define SYSCON_PDSLEEPCFG_NOTUSED0(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< SYSCON_PDSLEEPCFG.NOTUSED0 Field        */
#define SYSCON_PDSLEEPCFG_BOD_PD_MASK            (0x8U)                                              /*!< SYSCON_PDSLEEPCFG.BOD_PD Mask           */
#define SYSCON_PDSLEEPCFG_BOD_PD_SHIFT           (3U)                                                /*!< SYSCON_PDSLEEPCFG.BOD_PD Position       */
#define SYSCON_PDSLEEPCFG_BOD_PD(x)              (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_PDSLEEPCFG.BOD_PD Field          */
#define SYSCON_PDSLEEPCFG_NOTUSED1_MASK          (0x30U)                                             /*!< SYSCON_PDSLEEPCFG.NOTUSED1 Mask         */
#define SYSCON_PDSLEEPCFG_NOTUSED1_SHIFT         (4U)                                                /*!< SYSCON_PDSLEEPCFG.NOTUSED1 Position     */
#define SYSCON_PDSLEEPCFG_NOTUSED1(x)            (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< SYSCON_PDSLEEPCFG.NOTUSED1 Field        */
#define SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK         (0x40U)                                             /*!< SYSCON_PDSLEEPCFG.WDTOSC_PD Mask        */
#define SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT        (6U)                                                /*!< SYSCON_PDSLEEPCFG.WDTOSC_PD Position    */
#define SYSCON_PDSLEEPCFG_WDTOSC_PD(x)           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_PDSLEEPCFG.WDTOSC_PD Field       */
#define SYSCON_PDSLEEPCFG_NOTUSED2_MASK          (0x80U)                                             /*!< SYSCON_PDSLEEPCFG.NOTUSED2 Mask         */
#define SYSCON_PDSLEEPCFG_NOTUSED2_SHIFT         (7U)                                                /*!< SYSCON_PDSLEEPCFG.NOTUSED2 Position     */
#define SYSCON_PDSLEEPCFG_NOTUSED2(x)            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_PDSLEEPCFG.NOTUSED2 Field        */
#define SYSCON_PDSLEEPCFG_NOTUSED3_MASK          (0x700U)                                            /*!< SYSCON_PDSLEEPCFG.NOTUSED3 Mask         */
#define SYSCON_PDSLEEPCFG_NOTUSED3_SHIFT         (8U)                                                /*!< SYSCON_PDSLEEPCFG.NOTUSED3 Position     */
#define SYSCON_PDSLEEPCFG_NOTUSED3(x)            (((uint32_t)(((uint32_t)(x))<<8U))&0x700UL)         /*!< SYSCON_PDSLEEPCFG.NOTUSED3 Field        */
#define SYSCON_PDSLEEPCFG_NOTUSED4_MASK          (0x1800U)                                           /*!< SYSCON_PDSLEEPCFG.NOTUSED4 Mask         */
#define SYSCON_PDSLEEPCFG_NOTUSED4_SHIFT         (11U)                                               /*!< SYSCON_PDSLEEPCFG.NOTUSED4 Position     */
#define SYSCON_PDSLEEPCFG_NOTUSED4(x)            (((uint32_t)(((uint32_t)(x))<<11U))&0x1800UL)       /*!< SYSCON_PDSLEEPCFG.NOTUSED4 Field        */
/* ------- PDAWAKECFG Bit Fields                    ------ */
#define SYSCON_PDAWAKECFG_IRCOUT_PD_MASK         (0x1U)                                              /*!< SYSCON_PDAWAKECFG.IRCOUT_PD Mask        */
#define SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT        (0U)                                                /*!< SYSCON_PDAWAKECFG.IRCOUT_PD Position    */
#define SYSCON_PDAWAKECFG_IRCOUT_PD(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_PDAWAKECFG.IRCOUT_PD Field       */
#define SYSCON_PDAWAKECFG_IRC_PD_MASK            (0x2U)                                              /*!< SYSCON_PDAWAKECFG.IRC_PD Mask           */
#define SYSCON_PDAWAKECFG_IRC_PD_SHIFT           (1U)                                                /*!< SYSCON_PDAWAKECFG.IRC_PD Position       */
#define SYSCON_PDAWAKECFG_IRC_PD(x)              (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_PDAWAKECFG.IRC_PD Field          */
#define SYSCON_PDAWAKECFG_FLASH_PD_MASK          (0x4U)                                              /*!< SYSCON_PDAWAKECFG.FLASH_PD Mask         */
#define SYSCON_PDAWAKECFG_FLASH_PD_SHIFT         (2U)                                                /*!< SYSCON_PDAWAKECFG.FLASH_PD Position     */
#define SYSCON_PDAWAKECFG_FLASH_PD(x)            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_PDAWAKECFG.FLASH_PD Field        */
#define SYSCON_PDAWAKECFG_BOD_PD_MASK            (0x8U)                                              /*!< SYSCON_PDAWAKECFG.BOD_PD Mask           */
#define SYSCON_PDAWAKECFG_BOD_PD_SHIFT           (3U)                                                /*!< SYSCON_PDAWAKECFG.BOD_PD Position       */
#define SYSCON_PDAWAKECFG_BOD_PD(x)              (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_PDAWAKECFG.BOD_PD Field          */
#define SYSCON_PDAWAKECFG_ADC_PD_MASK            (0x10U)                                             /*!< SYSCON_PDAWAKECFG.ADC_PD Mask           */
#define SYSCON_PDAWAKECFG_ADC_PD_SHIFT           (4U)                                                /*!< SYSCON_PDAWAKECFG.ADC_PD Position       */
#define SYSCON_PDAWAKECFG_ADC_PD(x)              (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_PDAWAKECFG.ADC_PD Field          */
#define SYSCON_PDAWAKECFG_SYSOSC_PD_MASK         (0x20U)                                             /*!< SYSCON_PDAWAKECFG.SYSOSC_PD Mask        */
#define SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT        (5U)                                                /*!< SYSCON_PDAWAKECFG.SYSOSC_PD Position    */
#define SYSCON_PDAWAKECFG_SYSOSC_PD(x)           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SYSCON_PDAWAKECFG.SYSOSC_PD Field       */
#define SYSCON_PDAWAKECFG_WDTOSC_PD_MASK         (0x40U)                                             /*!< SYSCON_PDAWAKECFG.WDTOSC_PD Mask        */
#define SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT        (6U)                                                /*!< SYSCON_PDAWAKECFG.WDTOSC_PD Position    */
#define SYSCON_PDAWAKECFG_WDTOSC_PD(x)           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_PDAWAKECFG.WDTOSC_PD Field       */
#define SYSCON_PDAWAKECFG_SYSPLL_PD_MASK         (0x80U)                                             /*!< SYSCON_PDAWAKECFG.SYSPLL_PD Mask        */
#define SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT        (7U)                                                /*!< SYSCON_PDAWAKECFG.SYSPLL_PD Position    */
#define SYSCON_PDAWAKECFG_SYSPLL_PD(x)           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_PDAWAKECFG.SYSPLL_PD Field       */
#define SYSCON_PDAWAKECFG_NOTUSED0_MASK          (0x100U)                                            /*!< SYSCON_PDAWAKECFG.NOTUSED0 Mask         */
#define SYSCON_PDAWAKECFG_NOTUSED0_SHIFT         (8U)                                                /*!< SYSCON_PDAWAKECFG.NOTUSED0 Position     */
#define SYSCON_PDAWAKECFG_NOTUSED0(x)            (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SYSCON_PDAWAKECFG.NOTUSED0 Field        */
#define SYSCON_PDAWAKECFG_NOTUSED1_MASK          (0x200U)                                            /*!< SYSCON_PDAWAKECFG.NOTUSED1 Mask         */
#define SYSCON_PDAWAKECFG_NOTUSED1_SHIFT         (9U)                                                /*!< SYSCON_PDAWAKECFG.NOTUSED1 Position     */
#define SYSCON_PDAWAKECFG_NOTUSED1(x)            (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SYSCON_PDAWAKECFG.NOTUSED1 Field        */
#define SYSCON_PDAWAKECFG_NOTUSED2_MASK          (0x400U)                                            /*!< SYSCON_PDAWAKECFG.NOTUSED2 Mask         */
#define SYSCON_PDAWAKECFG_NOTUSED2_SHIFT         (10U)                                               /*!< SYSCON_PDAWAKECFG.NOTUSED2 Position     */
#define SYSCON_PDAWAKECFG_NOTUSED2(x)            (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SYSCON_PDAWAKECFG.NOTUSED2 Field        */
#define SYSCON_PDAWAKECFG_NOTUSED3_MASK          (0x800U)                                            /*!< SYSCON_PDAWAKECFG.NOTUSED3 Mask         */
#define SYSCON_PDAWAKECFG_NOTUSED3_SHIFT         (11U)                                               /*!< SYSCON_PDAWAKECFG.NOTUSED3 Position     */
#define SYSCON_PDAWAKECFG_NOTUSED3(x)            (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SYSCON_PDAWAKECFG.NOTUSED3 Field        */
#define SYSCON_PDAWAKECFG_NOTUSED4_MASK          (0x1000U)                                           /*!< SYSCON_PDAWAKECFG.NOTUSED4 Mask         */
#define SYSCON_PDAWAKECFG_NOTUSED4_SHIFT         (12U)                                               /*!< SYSCON_PDAWAKECFG.NOTUSED4 Position     */
#define SYSCON_PDAWAKECFG_NOTUSED4(x)            (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SYSCON_PDAWAKECFG.NOTUSED4 Field        */
#define SYSCON_PDAWAKECFG_NOTUSED5_MASK          (0xE000U)                                           /*!< SYSCON_PDAWAKECFG.NOTUSED5 Mask         */
#define SYSCON_PDAWAKECFG_NOTUSED5_SHIFT         (13U)                                               /*!< SYSCON_PDAWAKECFG.NOTUSED5 Position     */
#define SYSCON_PDAWAKECFG_NOTUSED5(x)            (((uint32_t)(((uint32_t)(x))<<13U))&0xE000UL)       /*!< SYSCON_PDAWAKECFG.NOTUSED5 Field        */
/* ------- PDRUNCFG Bit Fields                      ------ */
#define SYSCON_PDRUNCFG_IRCOUT_PD_MASK           (0x1U)                                              /*!< SYSCON_PDRUNCFG.IRCOUT_PD Mask          */
#define SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT          (0U)                                                /*!< SYSCON_PDRUNCFG.IRCOUT_PD Position      */
#define SYSCON_PDRUNCFG_IRCOUT_PD(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYSCON_PDRUNCFG.IRCOUT_PD Field         */
#define SYSCON_PDRUNCFG_IRC_PD_MASK              (0x2U)                                              /*!< SYSCON_PDRUNCFG.IRC_PD Mask             */
#define SYSCON_PDRUNCFG_IRC_PD_SHIFT             (1U)                                                /*!< SYSCON_PDRUNCFG.IRC_PD Position         */
#define SYSCON_PDRUNCFG_IRC_PD(x)                (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYSCON_PDRUNCFG.IRC_PD Field            */
#define SYSCON_PDRUNCFG_FLASH_PD_MASK            (0x4U)                                              /*!< SYSCON_PDRUNCFG.FLASH_PD Mask           */
#define SYSCON_PDRUNCFG_FLASH_PD_SHIFT           (2U)                                                /*!< SYSCON_PDRUNCFG.FLASH_PD Position       */
#define SYSCON_PDRUNCFG_FLASH_PD(x)              (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYSCON_PDRUNCFG.FLASH_PD Field          */
#define SYSCON_PDRUNCFG_BOD_PD_MASK              (0x8U)                                              /*!< SYSCON_PDRUNCFG.BOD_PD Mask             */
#define SYSCON_PDRUNCFG_BOD_PD_SHIFT             (3U)                                                /*!< SYSCON_PDRUNCFG.BOD_PD Position         */
#define SYSCON_PDRUNCFG_BOD_PD(x)                (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SYSCON_PDRUNCFG.BOD_PD Field            */
#define SYSCON_PDRUNCFG_ADC_PD_MASK              (0x10U)                                             /*!< SYSCON_PDRUNCFG.ADC_PD Mask             */
#define SYSCON_PDRUNCFG_ADC_PD_SHIFT             (4U)                                                /*!< SYSCON_PDRUNCFG.ADC_PD Position         */
#define SYSCON_PDRUNCFG_ADC_PD(x)                (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SYSCON_PDRUNCFG.ADC_PD Field            */
#define SYSCON_PDRUNCFG_SYSOSC_PD_MASK           (0x20U)                                             /*!< SYSCON_PDRUNCFG.SYSOSC_PD Mask          */
#define SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT          (5U)                                                /*!< SYSCON_PDRUNCFG.SYSOSC_PD Position      */
#define SYSCON_PDRUNCFG_SYSOSC_PD(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SYSCON_PDRUNCFG.SYSOSC_PD Field         */
#define SYSCON_PDRUNCFG_WDTOSC_PD_MASK           (0x40U)                                             /*!< SYSCON_PDRUNCFG.WDTOSC_PD Mask          */
#define SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT          (6U)                                                /*!< SYSCON_PDRUNCFG.WDTOSC_PD Position      */
#define SYSCON_PDRUNCFG_WDTOSC_PD(x)             (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SYSCON_PDRUNCFG.WDTOSC_PD Field         */
#define SYSCON_PDRUNCFG_SYSPLL_PD_MASK           (0x80U)                                             /*!< SYSCON_PDRUNCFG.SYSPLL_PD Mask          */
#define SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT          (7U)                                                /*!< SYSCON_PDRUNCFG.SYSPLL_PD Position      */
#define SYSCON_PDRUNCFG_SYSPLL_PD(x)             (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SYSCON_PDRUNCFG.SYSPLL_PD Field         */
#define SYSCON_PDRUNCFG_NOTUSED0_MASK            (0x100U)                                            /*!< SYSCON_PDRUNCFG.NOTUSED0 Mask           */
#define SYSCON_PDRUNCFG_NOTUSED0_SHIFT           (8U)                                                /*!< SYSCON_PDRUNCFG.NOTUSED0 Position       */
#define SYSCON_PDRUNCFG_NOTUSED0(x)              (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SYSCON_PDRUNCFG.NOTUSED0 Field          */
#define SYSCON_PDRUNCFG_NOTUSED1_MASK            (0x200U)                                            /*!< SYSCON_PDRUNCFG.NOTUSED1 Mask           */
#define SYSCON_PDRUNCFG_NOTUSED1_SHIFT           (9U)                                                /*!< SYSCON_PDRUNCFG.NOTUSED1 Position       */
#define SYSCON_PDRUNCFG_NOTUSED1(x)              (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SYSCON_PDRUNCFG.NOTUSED1 Field          */
#define SYSCON_PDRUNCFG_NOTUSED2_MASK            (0x400U)                                            /*!< SYSCON_PDRUNCFG.NOTUSED2 Mask           */
#define SYSCON_PDRUNCFG_NOTUSED2_SHIFT           (10U)                                               /*!< SYSCON_PDRUNCFG.NOTUSED2 Position       */
#define SYSCON_PDRUNCFG_NOTUSED2(x)              (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SYSCON_PDRUNCFG.NOTUSED2 Field          */
#define SYSCON_PDRUNCFG_NOTUSED3_MASK            (0x800U)                                            /*!< SYSCON_PDRUNCFG.NOTUSED3 Mask           */
#define SYSCON_PDRUNCFG_NOTUSED3_SHIFT           (11U)                                               /*!< SYSCON_PDRUNCFG.NOTUSED3 Position       */
#define SYSCON_PDRUNCFG_NOTUSED3(x)              (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SYSCON_PDRUNCFG.NOTUSED3 Field          */
#define SYSCON_PDRUNCFG_NOTUSED4_MASK            (0x1000U)                                           /*!< SYSCON_PDRUNCFG.NOTUSED4 Mask           */
#define SYSCON_PDRUNCFG_NOTUSED4_SHIFT           (12U)                                               /*!< SYSCON_PDRUNCFG.NOTUSED4 Position       */
#define SYSCON_PDRUNCFG_NOTUSED4(x)              (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SYSCON_PDRUNCFG.NOTUSED4 Field          */
#define SYSCON_PDRUNCFG_NOTUSED5_MASK            (0xE000U)                                           /*!< SYSCON_PDRUNCFG.NOTUSED5 Mask           */
#define SYSCON_PDRUNCFG_NOTUSED5_SHIFT           (13U)                                               /*!< SYSCON_PDRUNCFG.NOTUSED5 Position       */
#define SYSCON_PDRUNCFG_NOTUSED5(x)              (((uint32_t)(((uint32_t)(x))<<13U))&0xE000UL)       /*!< SYSCON_PDRUNCFG.NOTUSED5 Field          */
/* ------- DEVICE_ID Bit Fields                     ------ */
#define SYSCON_DEVICE_ID_DEVICEID_MASK           (0xFFFFFFFFU)                                       /*!< SYSCON_DEVICE_ID.DEVICEID Mask          */
#define SYSCON_DEVICE_ID_DEVICEID_SHIFT          (0U)                                                /*!< SYSCON_DEVICE_ID.DEVICEID Position      */
#define SYSCON_DEVICE_ID_DEVICEID(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SYSCON_DEVICE_ID.DEVICEID Field         */
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
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART (file:UART_LPC11Cxx)            ================ */
/* ================================================================================ */

/**
 * @brief UART
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART Structure                                               */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DLL;                       /**< 0000: Divisor Latch LSB. Least significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. (DLAB=1) */
      __I  uint32_t  RBR;                       /**< 0000: Receiver Buffer Register. Contains the next received character to be read. (DLAB=0) */
      __O  uint32_t  THR;                       /**< 0000: Transmit Holding Register. The next character to be transmitted is written here. (DLAB=0) */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DLM;                       /**< 0004: Divisor Latch MSB. Most significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. (DLAB=1) */
      __IO uint32_t  IER;                       /**< 0004: Interrupt Enable Register. Contains individual interrupt enable bits for the 7 potential UART interrupts. (DLAB=0) */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __O  uint32_t  FCR;                       /**< 0008: FIFO Control Register. Controls UART FIFO usage and modes    */
      __I  uint32_t  IIR;                       /**< 0008: Interrupt ID Register. Identifies which interrupt(s) are pending */
   };
   __IO uint32_t  LCR;                          /**< 000C: Line Control Register. Contains controls for frame formatting and break generation */
   __IO uint32_t  MCR;                          /**< 0010: Modem control register                                       */
   __I  uint32_t  LSR;                          /**< 0014: Line Status Register. Contains flags for transmit and receive status, including line errors */
   __I  uint32_t  MSR;                          /**< 0018: Modem status register                                        */
   __IO uint32_t  SCR;                          /**< 001C: Scratch Pad Register. Eight-bit temporary storage for software */
   __IO uint32_t  ACR;                          /**< 0020: Auto-baud Control Register. Contains controls for the auto-baud feature */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  FDR;                          /**< 0028: Fractional Divider Register. Generates a clock input for the baud rate divider */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  TER;                          /**< 0030: Transmit Enable Register. Turns off UART transmitter for use with software flow control */
        uint8_t   RESERVED_2[24];              
   __IO uint32_t  RS485CTRL;                    /**< 004C: RS-485/EIA-485 Control. Contains controls to configure various aspects of RS-485/EIA-485 modes */
   __IO uint32_t  RS485ADRMATCH;                /**< 0050: RS-485/EIA-485 address match. Contains the address match value for RS-485/EIA-485 mode */
   __IO uint32_t  RS485DLY;                     /**< 0054: RS-485/EIA-485 direction control delay                       */
} UART_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- DLL Bit Fields                           ------ */
#define UART_DLL_DLLSB_MASK                      (0xFFU)                                             /*!< UART_DLL.DLLSB Mask                     */
#define UART_DLL_DLLSB_SHIFT                     (0U)                                                /*!< UART_DLL.DLLSB Position                 */
#define UART_DLL_DLLSB(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< UART_DLL.DLLSB Field                    */
/* ------- RBR Bit Fields                           ------ */
#define UART_RBR_RBR_MASK                        (0xFFU)                                             /*!< UART_RBR.RBR Mask                       */
#define UART_RBR_RBR_SHIFT                       (0U)                                                /*!< UART_RBR.RBR Position                   */
#define UART_RBR_RBR(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< UART_RBR.RBR Field                      */
/* ------- THR Bit Fields                           ------ */
#define UART_THR_THR_MASK                        (0xFFU)                                             /*!< UART_THR.THR Mask                       */
#define UART_THR_THR_SHIFT                       (0U)                                                /*!< UART_THR.THR Position                   */
#define UART_THR_THR(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< UART_THR.THR Field                      */
/* ------- DLM Bit Fields                           ------ */
#define UART_DLM_DLMSB_MASK                      (0xFFU)                                             /*!< UART_DLM.DLMSB Mask                     */
#define UART_DLM_DLMSB_SHIFT                     (0U)                                                /*!< UART_DLM.DLMSB Position                 */
#define UART_DLM_DLMSB(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< UART_DLM.DLMSB Field                    */
/* ------- IER Bit Fields                           ------ */
#define UART_IER_RBRIE_MASK                      (0x1U)                                              /*!< UART_IER.RBRIE Mask                     */
#define UART_IER_RBRIE_SHIFT                     (0U)                                                /*!< UART_IER.RBRIE Position                 */
#define UART_IER_RBRIE(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< UART_IER.RBRIE Field                    */
#define UART_IER_THREIE_MASK                     (0x2U)                                              /*!< UART_IER.THREIE Mask                    */
#define UART_IER_THREIE_SHIFT                    (1U)                                                /*!< UART_IER.THREIE Position                */
#define UART_IER_THREIE(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< UART_IER.THREIE Field                   */
#define UART_IER_RXLIE_MASK                      (0x4U)                                              /*!< UART_IER.RXLIE Mask                     */
#define UART_IER_RXLIE_SHIFT                     (2U)                                                /*!< UART_IER.RXLIE Position                 */
#define UART_IER_RXLIE(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< UART_IER.RXLIE Field                    */
#define UART_IER_ABEOINTEN_MASK                  (0x100U)                                            /*!< UART_IER.ABEOINTEN Mask                 */
#define UART_IER_ABEOINTEN_SHIFT                 (8U)                                                /*!< UART_IER.ABEOINTEN Position             */
#define UART_IER_ABEOINTEN(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< UART_IER.ABEOINTEN Field                */
#define UART_IER_ABTOINTEN_MASK                  (0x200U)                                            /*!< UART_IER.ABTOINTEN Mask                 */
#define UART_IER_ABTOINTEN_SHIFT                 (9U)                                                /*!< UART_IER.ABTOINTEN Position             */
#define UART_IER_ABTOINTEN(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< UART_IER.ABTOINTEN Field                */
/* ------- FCR Bit Fields                           ------ */
#define UART_FCR_FIFOEN_MASK                     (0x1U)                                              /*!< UART_FCR.FIFOEN Mask                    */
#define UART_FCR_FIFOEN_SHIFT                    (0U)                                                /*!< UART_FCR.FIFOEN Position                */
#define UART_FCR_FIFOEN(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< UART_FCR.FIFOEN Field                   */
#define UART_FCR_RXFIFORES_MASK                  (0x2U)                                              /*!< UART_FCR.RXFIFORES Mask                 */
#define UART_FCR_RXFIFORES_SHIFT                 (1U)                                                /*!< UART_FCR.RXFIFORES Position             */
#define UART_FCR_RXFIFORES(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< UART_FCR.RXFIFORES Field                */
#define UART_FCR_TXFIFORES_MASK                  (0x4U)                                              /*!< UART_FCR.TXFIFORES Mask                 */
#define UART_FCR_TXFIFORES_SHIFT                 (2U)                                                /*!< UART_FCR.TXFIFORES Position             */
#define UART_FCR_TXFIFORES(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< UART_FCR.TXFIFORES Field                */
#define UART_FCR_RXTL_MASK                       (0xC0U)                                             /*!< UART_FCR.RXTL Mask                      */
#define UART_FCR_RXTL_SHIFT                      (6U)                                                /*!< UART_FCR.RXTL Position                  */
#define UART_FCR_RXTL(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< UART_FCR.RXTL Field                     */
/* ------- IIR Bit Fields                           ------ */
#define UART_IIR_INTSTATUS_MASK                  (0x1U)                                              /*!< UART_IIR.INTSTATUS Mask                 */
#define UART_IIR_INTSTATUS_SHIFT                 (0U)                                                /*!< UART_IIR.INTSTATUS Position             */
#define UART_IIR_INTSTATUS(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< UART_IIR.INTSTATUS Field                */
#define UART_IIR_INTID_MASK                      (0xEU)                                              /*!< UART_IIR.INTID Mask                     */
#define UART_IIR_INTID_SHIFT                     (1U)                                                /*!< UART_IIR.INTID Position                 */
#define UART_IIR_INTID(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0xEUL)           /*!< UART_IIR.INTID Field                    */
#define UART_IIR_FIFOENABLE_MASK                 (0xC0U)                                             /*!< UART_IIR.FIFOENABLE Mask                */
#define UART_IIR_FIFOENABLE_SHIFT                (6U)                                                /*!< UART_IIR.FIFOENABLE Position            */
#define UART_IIR_FIFOENABLE(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< UART_IIR.FIFOENABLE Field               */
#define UART_IIR_ABEOINT_MASK                    (0x100U)                                            /*!< UART_IIR.ABEOINT Mask                   */
#define UART_IIR_ABEOINT_SHIFT                   (8U)                                                /*!< UART_IIR.ABEOINT Position               */
#define UART_IIR_ABEOINT(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< UART_IIR.ABEOINT Field                  */
#define UART_IIR_ABTOINT_MASK                    (0x200U)                                            /*!< UART_IIR.ABTOINT Mask                   */
#define UART_IIR_ABTOINT_SHIFT                   (9U)                                                /*!< UART_IIR.ABTOINT Position               */
#define UART_IIR_ABTOINT(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< UART_IIR.ABTOINT Field                  */
/* ------- LCR Bit Fields                           ------ */
#define UART_LCR_WLS_MASK                        (0x3U)                                              /*!< UART_LCR.WLS Mask                       */
#define UART_LCR_WLS_SHIFT                       (0U)                                                /*!< UART_LCR.WLS Position                   */
#define UART_LCR_WLS(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< UART_LCR.WLS Field                      */
#define UART_LCR_SBS_MASK                        (0x4U)                                              /*!< UART_LCR.SBS Mask                       */
#define UART_LCR_SBS_SHIFT                       (2U)                                                /*!< UART_LCR.SBS Position                   */
#define UART_LCR_SBS(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< UART_LCR.SBS Field                      */
#define UART_LCR_PE_MASK                         (0x8U)                                              /*!< UART_LCR.PE Mask                        */
#define UART_LCR_PE_SHIFT                        (3U)                                                /*!< UART_LCR.PE Position                    */
#define UART_LCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< UART_LCR.PE Field                       */
#define UART_LCR_PS_MASK                         (0x30U)                                             /*!< UART_LCR.PS Mask                        */
#define UART_LCR_PS_SHIFT                        (4U)                                                /*!< UART_LCR.PS Position                    */
#define UART_LCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< UART_LCR.PS Field                       */
#define UART_LCR_BC_MASK                         (0x40U)                                             /*!< UART_LCR.BC Mask                        */
#define UART_LCR_BC_SHIFT                        (6U)                                                /*!< UART_LCR.BC Position                    */
#define UART_LCR_BC(x)                           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< UART_LCR.BC Field                       */
#define UART_LCR_DLAB_MASK                       (0x80U)                                             /*!< UART_LCR.DLAB Mask                      */
#define UART_LCR_DLAB_SHIFT                      (7U)                                                /*!< UART_LCR.DLAB Position                  */
#define UART_LCR_DLAB(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< UART_LCR.DLAB Field                     */
/* ------- MCR Bit Fields                           ------ */
#define UART_MCR_DTRC_MASK                       (0x1U)                                              /*!< UART_MCR.DTRC Mask                      */
#define UART_MCR_DTRC_SHIFT                      (0U)                                                /*!< UART_MCR.DTRC Position                  */
#define UART_MCR_DTRC(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< UART_MCR.DTRC Field                     */
#define UART_MCR_RTSC_MASK                       (0x2U)                                              /*!< UART_MCR.RTSC Mask                      */
#define UART_MCR_RTSC_SHIFT                      (1U)                                                /*!< UART_MCR.RTSC Position                  */
#define UART_MCR_RTSC(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< UART_MCR.RTSC Field                     */
#define UART_MCR_LMS_MASK                        (0x10U)                                             /*!< UART_MCR.LMS Mask                       */
#define UART_MCR_LMS_SHIFT                       (4U)                                                /*!< UART_MCR.LMS Position                   */
#define UART_MCR_LMS(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< UART_MCR.LMS Field                      */
#define UART_MCR_RTSEN_MASK                      (0x40U)                                             /*!< UART_MCR.RTSEN Mask                     */
#define UART_MCR_RTSEN_SHIFT                     (6U)                                                /*!< UART_MCR.RTSEN Position                 */
#define UART_MCR_RTSEN(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< UART_MCR.RTSEN Field                    */
#define UART_MCR_CTSEN_MASK                      (0x80U)                                             /*!< UART_MCR.CTSEN Mask                     */
#define UART_MCR_CTSEN_SHIFT                     (7U)                                                /*!< UART_MCR.CTSEN Position                 */
#define UART_MCR_CTSEN(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< UART_MCR.CTSEN Field                    */
/* ------- LSR Bit Fields                           ------ */
#define UART_LSR_RDR_MASK                        (0x1U)                                              /*!< UART_LSR.RDR Mask                       */
#define UART_LSR_RDR_SHIFT                       (0U)                                                /*!< UART_LSR.RDR Position                   */
#define UART_LSR_RDR(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< UART_LSR.RDR Field                      */
#define UART_LSR_OE_MASK                         (0x2U)                                              /*!< UART_LSR.OE Mask                        */
#define UART_LSR_OE_SHIFT                        (1U)                                                /*!< UART_LSR.OE Position                    */
#define UART_LSR_OE(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< UART_LSR.OE Field                       */
#define UART_LSR_PE_MASK                         (0x4U)                                              /*!< UART_LSR.PE Mask                        */
#define UART_LSR_PE_SHIFT                        (2U)                                                /*!< UART_LSR.PE Position                    */
#define UART_LSR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< UART_LSR.PE Field                       */
#define UART_LSR_FE_MASK                         (0x8U)                                              /*!< UART_LSR.FE Mask                        */
#define UART_LSR_FE_SHIFT                        (3U)                                                /*!< UART_LSR.FE Position                    */
#define UART_LSR_FE(x)                           (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< UART_LSR.FE Field                       */
#define UART_LSR_BI_MASK                         (0x10U)                                             /*!< UART_LSR.BI Mask                        */
#define UART_LSR_BI_SHIFT                        (4U)                                                /*!< UART_LSR.BI Position                    */
#define UART_LSR_BI(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< UART_LSR.BI Field                       */
#define UART_LSR_THRE_MASK                       (0x20U)                                             /*!< UART_LSR.THRE Mask                      */
#define UART_LSR_THRE_SHIFT                      (5U)                                                /*!< UART_LSR.THRE Position                  */
#define UART_LSR_THRE(x)                         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< UART_LSR.THRE Field                     */
#define UART_LSR_TEMT_MASK                       (0x40U)                                             /*!< UART_LSR.TEMT Mask                      */
#define UART_LSR_TEMT_SHIFT                      (6U)                                                /*!< UART_LSR.TEMT Position                  */
#define UART_LSR_TEMT(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< UART_LSR.TEMT Field                     */
#define UART_LSR_RXFE_MASK                       (0x80U)                                             /*!< UART_LSR.RXFE Mask                      */
#define UART_LSR_RXFE_SHIFT                      (7U)                                                /*!< UART_LSR.RXFE Position                  */
#define UART_LSR_RXFE(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< UART_LSR.RXFE Field                     */
/* ------- MSR Bit Fields                           ------ */
#define UART_MSR_DCTS_MASK                       (0x1U)                                              /*!< UART_MSR.DCTS Mask                      */
#define UART_MSR_DCTS_SHIFT                      (0U)                                                /*!< UART_MSR.DCTS Position                  */
#define UART_MSR_DCTS(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< UART_MSR.DCTS Field                     */
#define UART_MSR_DDSR_MASK                       (0x2U)                                              /*!< UART_MSR.DDSR Mask                      */
#define UART_MSR_DDSR_SHIFT                      (1U)                                                /*!< UART_MSR.DDSR Position                  */
#define UART_MSR_DDSR(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< UART_MSR.DDSR Field                     */
#define UART_MSR_TERI_MASK                       (0x4U)                                              /*!< UART_MSR.TERI Mask                      */
#define UART_MSR_TERI_SHIFT                      (2U)                                                /*!< UART_MSR.TERI Position                  */
#define UART_MSR_TERI(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< UART_MSR.TERI Field                     */
#define UART_MSR_DDCD_MASK                       (0x8U)                                              /*!< UART_MSR.DDCD Mask                      */
#define UART_MSR_DDCD_SHIFT                      (3U)                                                /*!< UART_MSR.DDCD Position                  */
#define UART_MSR_DDCD(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< UART_MSR.DDCD Field                     */
#define UART_MSR_CTS_MASK                        (0x10U)                                             /*!< UART_MSR.CTS Mask                       */
#define UART_MSR_CTS_SHIFT                       (4U)                                                /*!< UART_MSR.CTS Position                   */
#define UART_MSR_CTS(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< UART_MSR.CTS Field                      */
#define UART_MSR_DSR_MASK                        (0x20U)                                             /*!< UART_MSR.DSR Mask                       */
#define UART_MSR_DSR_SHIFT                       (5U)                                                /*!< UART_MSR.DSR Position                   */
#define UART_MSR_DSR(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< UART_MSR.DSR Field                      */
#define UART_MSR_RI_MASK                         (0x40U)                                             /*!< UART_MSR.RI Mask                        */
#define UART_MSR_RI_SHIFT                        (6U)                                                /*!< UART_MSR.RI Position                    */
#define UART_MSR_RI(x)                           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< UART_MSR.RI Field                       */
#define UART_MSR_DCD_MASK                        (0x80U)                                             /*!< UART_MSR.DCD Mask                       */
#define UART_MSR_DCD_SHIFT                       (7U)                                                /*!< UART_MSR.DCD Position                   */
#define UART_MSR_DCD(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< UART_MSR.DCD Field                      */
/* ------- SCR Bit Fields                           ------ */
#define UART_SCR_pad_MASK                        (0xFFU)                                             /*!< UART_SCR.pad Mask                       */
#define UART_SCR_pad_SHIFT                       (0U)                                                /*!< UART_SCR.pad Position                   */
#define UART_SCR_pad(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< UART_SCR.pad Field                      */
/* ------- ACR Bit Fields                           ------ */
#define UART_ACR_START_MASK                      (0x1U)                                              /*!< UART_ACR.START Mask                     */
#define UART_ACR_START_SHIFT                     (0U)                                                /*!< UART_ACR.START Position                 */
#define UART_ACR_START(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< UART_ACR.START Field                    */
#define UART_ACR_MODE_MASK                       (0x2U)                                              /*!< UART_ACR.MODE Mask                      */
#define UART_ACR_MODE_SHIFT                      (1U)                                                /*!< UART_ACR.MODE Position                  */
#define UART_ACR_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< UART_ACR.MODE Field                     */
#define UART_ACR_AUTORESTART_MASK                (0x4U)                                              /*!< UART_ACR.AUTORESTART Mask               */
#define UART_ACR_AUTORESTART_SHIFT               (2U)                                                /*!< UART_ACR.AUTORESTART Position           */
#define UART_ACR_AUTORESTART(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< UART_ACR.AUTORESTART Field              */
#define UART_ACR_ABEOINTCLR_MASK                 (0x100U)                                            /*!< UART_ACR.ABEOINTCLR Mask                */
#define UART_ACR_ABEOINTCLR_SHIFT                (8U)                                                /*!< UART_ACR.ABEOINTCLR Position            */
#define UART_ACR_ABEOINTCLR(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< UART_ACR.ABEOINTCLR Field               */
#define UART_ACR_ABTOINTCLR_MASK                 (0x200U)                                            /*!< UART_ACR.ABTOINTCLR Mask                */
#define UART_ACR_ABTOINTCLR_SHIFT                (9U)                                                /*!< UART_ACR.ABTOINTCLR Position            */
#define UART_ACR_ABTOINTCLR(x)                   (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< UART_ACR.ABTOINTCLR Field               */
/* ------- FDR Bit Fields                           ------ */
#define UART_FDR_DIVADDVAL_MASK                  (0xFU)                                              /*!< UART_FDR.DIVADDVAL Mask                 */
#define UART_FDR_DIVADDVAL_SHIFT                 (0U)                                                /*!< UART_FDR.DIVADDVAL Position             */
#define UART_FDR_DIVADDVAL(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< UART_FDR.DIVADDVAL Field                */
#define UART_FDR_MULVAL_MASK                     (0xF0U)                                             /*!< UART_FDR.MULVAL Mask                    */
#define UART_FDR_MULVAL_SHIFT                    (4U)                                                /*!< UART_FDR.MULVAL Position                */
#define UART_FDR_MULVAL(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< UART_FDR.MULVAL Field                   */
/* ------- TER Bit Fields                           ------ */
#define UART_TER_TXEN_MASK                       (0x80U)                                             /*!< UART_TER.TXEN Mask                      */
#define UART_TER_TXEN_SHIFT                      (7U)                                                /*!< UART_TER.TXEN Position                  */
#define UART_TER_TXEN(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< UART_TER.TXEN Field                     */
/* ------- RS485CTRL Bit Fields                     ------ */
#define UART_RS485CTRL_NMMEN_MASK                (0x1U)                                              /*!< UART_RS485CTRL.NMMEN Mask               */
#define UART_RS485CTRL_NMMEN_SHIFT               (0U)                                                /*!< UART_RS485CTRL.NMMEN Position           */
#define UART_RS485CTRL_NMMEN(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< UART_RS485CTRL.NMMEN Field              */
#define UART_RS485CTRL_RXDIS_MASK                (0x2U)                                              /*!< UART_RS485CTRL.RXDIS Mask               */
#define UART_RS485CTRL_RXDIS_SHIFT               (1U)                                                /*!< UART_RS485CTRL.RXDIS Position           */
#define UART_RS485CTRL_RXDIS(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< UART_RS485CTRL.RXDIS Field              */
#define UART_RS485CTRL_AADEN_MASK                (0x4U)                                              /*!< UART_RS485CTRL.AADEN Mask               */
#define UART_RS485CTRL_AADEN_SHIFT               (2U)                                                /*!< UART_RS485CTRL.AADEN Position           */
#define UART_RS485CTRL_AADEN(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< UART_RS485CTRL.AADEN Field              */
#define UART_RS485CTRL_SEL_MASK                  (0x8U)                                              /*!< UART_RS485CTRL.SEL Mask                 */
#define UART_RS485CTRL_SEL_SHIFT                 (3U)                                                /*!< UART_RS485CTRL.SEL Position             */
#define UART_RS485CTRL_SEL(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< UART_RS485CTRL.SEL Field                */
#define UART_RS485CTRL_DCTRL_MASK                (0x10U)                                             /*!< UART_RS485CTRL.DCTRL Mask               */
#define UART_RS485CTRL_DCTRL_SHIFT               (4U)                                                /*!< UART_RS485CTRL.DCTRL Position           */
#define UART_RS485CTRL_DCTRL(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< UART_RS485CTRL.DCTRL Field              */
#define UART_RS485CTRL_OINV_MASK                 (0x20U)                                             /*!< UART_RS485CTRL.OINV Mask                */
#define UART_RS485CTRL_OINV_SHIFT                (5U)                                                /*!< UART_RS485CTRL.OINV Position            */
#define UART_RS485CTRL_OINV(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< UART_RS485CTRL.OINV Field               */
/* ------- RS485ADRMATCH Bit Fields                 ------ */
#define UART_RS485ADRMATCH_ADRMATCH_MASK         (0xFFU)                                             /*!< UART_RS485ADRMATCH.ADRMATCH Mask        */
#define UART_RS485ADRMATCH_ADRMATCH_SHIFT        (0U)                                                /*!< UART_RS485ADRMATCH.ADRMATCH Position    */
#define UART_RS485ADRMATCH_ADRMATCH(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< UART_RS485ADRMATCH.ADRMATCH Field       */
/* ------- RS485DLY Bit Fields                      ------ */
#define UART_RS485DLY_DLY_MASK                   (0xFFU)                                             /*!< UART_RS485DLY.DLY Mask                  */
#define UART_RS485DLY_DLY_SHIFT                  (0U)                                                /*!< UART_RS485DLY.DLY Position              */
#define UART_RS485DLY_DLY(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< UART_RS485DLY.DLY Field                 */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART - Peripheral instance base addresses */
#define UART_BasePtr                   0x40008000UL //!< Peripheral base address
#define UART                           ((UART_Type *) UART_BasePtr) //!< Freescale base pointer
#define UART_BASE_PTR                  (UART) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WWDT_Peripheral_access_layer_GROUP WWDT Peripheral Access Layer
* @brief C Struct for WWDT
* @{
*/

/* ================================================================================ */
/* ================           WWDT (file:WWDT_LPC11Cxx)            ================ */
/* ================================================================================ */

/**
 * @brief Windowed WatchDog Timer
 */
/**
* @addtogroup WWDT_structs_GROUP WWDT struct
* @brief Struct for WWDT
* @{
*/
typedef struct {                                /*       WWDT Structure                                               */
   __IO uint32_t  WDMOD;                        /**< 0000: Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer */
   __IO uint32_t  WDTC;                         /**< 0004: Watchdog timer constant register. This register determines the time-out value */
   __O  uint32_t  WDFEED;                       /**< 0008: Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC */
   __I  uint32_t  WDTV;                         /**< 000C: Watchdog timer value register. This register reads out the current value of the Watchdog timer */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  WDWARNINT;                    /**< 0014: Watchdog Warning Interrupt compare value                     */
   __IO uint32_t  WDWINDOW;                     /**< 0018: Watchdog Window compare value                                */
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
/* ------- WDMOD Bit Fields                         ------ */
#define WWDT_WDMOD_WDEN_MASK                     (0x1U)                                              /*!< WWDT_WDMOD.WDEN Mask                    */
#define WWDT_WDMOD_WDEN_SHIFT                    (0U)                                                /*!< WWDT_WDMOD.WDEN Position                */
#define WWDT_WDMOD_WDEN(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< WWDT_WDMOD.WDEN Field                   */
#define WWDT_WDMOD_WDRESET_MASK                  (0x2U)                                              /*!< WWDT_WDMOD.WDRESET Mask                 */
#define WWDT_WDMOD_WDRESET_SHIFT                 (1U)                                                /*!< WWDT_WDMOD.WDRESET Position             */
#define WWDT_WDMOD_WDRESET(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< WWDT_WDMOD.WDRESET Field                */
#define WWDT_WDMOD_WDTOF_MASK                    (0x4U)                                              /*!< WWDT_WDMOD.WDTOF Mask                   */
#define WWDT_WDMOD_WDTOF_SHIFT                   (2U)                                                /*!< WWDT_WDMOD.WDTOF Position               */
#define WWDT_WDMOD_WDTOF(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< WWDT_WDMOD.WDTOF Field                  */
#define WWDT_WDMOD_WDINT_MASK                    (0x8U)                                              /*!< WWDT_WDMOD.WDINT Mask                   */
#define WWDT_WDMOD_WDINT_SHIFT                   (3U)                                                /*!< WWDT_WDMOD.WDINT Position               */
#define WWDT_WDMOD_WDINT(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< WWDT_WDMOD.WDINT Field                  */
#define WWDT_WDMOD_WDPROTECT_MASK                (0x10U)                                             /*!< WWDT_WDMOD.WDPROTECT Mask               */
#define WWDT_WDMOD_WDPROTECT_SHIFT               (4U)                                                /*!< WWDT_WDMOD.WDPROTECT Position           */
#define WWDT_WDMOD_WDPROTECT(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< WWDT_WDMOD.WDPROTECT Field              */
/* ------- WDTC Bit Fields                          ------ */
#define WWDT_WDTC_Count_MASK                     (0xFFFFFFU)                                         /*!< WWDT_WDTC.Count Mask                    */
#define WWDT_WDTC_Count_SHIFT                    (0U)                                                /*!< WWDT_WDTC.Count Position                */
#define WWDT_WDTC_Count(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< WWDT_WDTC.Count Field                   */
/* ------- WDFEED Bit Fields                        ------ */
#define WWDT_WDFEED_Feed_MASK                    (0xFFU)                                             /*!< WWDT_WDFEED.Feed Mask                   */
#define WWDT_WDFEED_Feed_SHIFT                   (0U)                                                /*!< WWDT_WDFEED.Feed Position               */
#define WWDT_WDFEED_Feed(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< WWDT_WDFEED.Feed Field                  */
/* ------- WDTV Bit Fields                          ------ */
#define WWDT_WDTV_Count_MASK                     (0xFFFFFFU)                                         /*!< WWDT_WDTV.Count Mask                    */
#define WWDT_WDTV_Count_SHIFT                    (0U)                                                /*!< WWDT_WDTV.Count Position                */
#define WWDT_WDTV_Count(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< WWDT_WDTV.Count Field                   */
/* ------- WDWARNINT Bit Fields                     ------ */
#define WWDT_WDWARNINT_WARNINT_MASK              (0x3FFU)                                            /*!< WWDT_WDWARNINT.WARNINT Mask             */
#define WWDT_WDWARNINT_WARNINT_SHIFT             (0U)                                                /*!< WWDT_WDWARNINT.WARNINT Position         */
#define WWDT_WDWARNINT_WARNINT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< WWDT_WDWARNINT.WARNINT Field            */
/* ------- WDWINDOW Bit Fields                      ------ */
#define WWDT_WDWINDOW_WINDOW_MASK                (0xFFFFFFU)                                         /*!< WWDT_WDWINDOW.WINDOW Mask               */
#define WWDT_WDWINDOW_WINDOW_SHIFT               (0U)                                                /*!< WWDT_WDWINDOW.WINDOW Position           */
#define WWDT_WDWINDOW_WINDOW(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< WWDT_WDWINDOW.WINDOW Field              */
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


#endif  /* MCU_LPC11XX */

