/****************************************************************************************************//**
 * @file     LPC13xx.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for LPC13xx.
 *           Equivalent: 
 *
 * @version  V1
 * @date     2018/03
 *
 *******************************************************************************************************/

#ifndef MCU_LPC13XX
#define MCU_LPC13XX

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
  MemoryManagement_IRQn         = -12,   /**<   4 Memory Management, MPU mismatch, including Access Violation and No Match         */
  BusFault_IRQn                 = -11,   /**<   5 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
  UsageFault_IRQn               = -10,   /**<   6 Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
  SVCall_IRQn                   =  -5,   /**<  11 System Service Call via SVC instruction                                          */
  DebugMonitor_IRQn             =  -4,   /**<  12 Debug Monitor                                                                    */
  PendSV_IRQn                   =  -2,   /**<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /**<  15 System Tick Timer                                                                */
/* ----------------------   LPC13xx VectorTable                      ---------------------- */
  PIO0_0_IRQn                   =   0,   /**<  16 System configuration                                                             */
  PIO0_1_IRQn                   =   1,   /**<  17 System configuration                                                             */
  PIO0_2_IRQn                   =   2,   /**<  18 System configuration                                                             */
  PIO0_3_IRQn                   =   3,   /**<  19 System configuration                                                             */
  PIO0_4_IRQn                   =   4,   /**<  20 System configuration                                                             */
  PIO0_5_IRQn                   =   5,   /**<  21 System configuration                                                             */
  PIO0_6_IRQn                   =   6,   /**<  22 System configuration                                                             */
  PIO0_7_IRQn                   =   7,   /**<  23 System configuration                                                             */
  PIO0_8_IRQn                   =   8,   /**<  24 System configuration                                                             */
  PIO0_9_IRQn                   =   9,   /**<  25 System configuration                                                             */
  PIO0_10_IRQn                  =  10,   /**<  26 System configuration                                                             */
  PIO0_11_IRQn                  =  11,   /**<  27 System configuration                                                             */
  PIO1_0_IRQn                   =  12,   /**<  28 System configuration                                                             */
  PIO1_1_IRQn                   =  13,   /**<  29 System configuration                                                             */
  PIO1_2_IRQn                   =  14,   /**<  30 System configuration                                                             */
  PIO1_3_IRQn                   =  15,   /**<  31 System configuration                                                             */
  PIO1_4_IRQn                   =  16,   /**<  32 System configuration                                                             */
  PIO1_5_IRQn                   =  17,   /**<  33 System configuration                                                             */
  PIO1_6_IRQn                   =  18,   /**<  34 System configuration                                                             */
  PIO1_7_IRQn                   =  19,   /**<  35 System configuration                                                             */
  PIO1_8_IRQn                   =  20,   /**<  36 System configuration                                                             */
  PIO1_9_IRQn                   =  21,   /**<  37 System configuration                                                             */
  PIO1_10_IRQn                  =  22,   /**<  38 System configuration                                                             */
  PIO1_11_IRQn                  =  23,   /**<  39 System configuration                                                             */
  PIO2_0_IRQn                   =  24,   /**<  40 System configuration                                                             */
  PIO2_1_IRQn                   =  25,   /**<  41 System configuration                                                             */
  PIO2_2_IRQn                   =  26,   /**<  42 System configuration                                                             */
  PIO2_3_IRQn                   =  27,   /**<  43 System configuration                                                             */
  PIO2_4_IRQn                   =  28,   /**<  44 System configuration                                                             */
  PIO2_5_IRQn                   =  29,   /**<  45 System configuration                                                             */
  PIO2_6_IRQn                   =  30,   /**<  46 System configuration                                                             */
  PIO2_7_IRQn                   =  31,   /**<  47 System configuration                                                             */
  PIO2_8_IRQn                   =  32,   /**<  48 System configuration                                                             */
  PIO2_9_IRQn                   =  33,   /**<  49 System configuration                                                             */
  PIO2_10_IRQn                  =  34,   /**<  50 System configuration                                                             */
  PIO2_11_IRQn                  =  35,   /**<  51 System configuration                                                             */
  PIO3_0_IRQn                   =  36,   /**<  52 System configuration                                                             */
  PIO3_1_IRQn                   =  37,   /**<  53 System configuration                                                             */
  PIO3_2_IRQn                   =  38,   /**<  54 System configuration                                                             */
  PIO3_3_IRQn                   =  39,   /**<  55 System configuration                                                             */
  I2C0_IRQn                     =  40,   /**<  56 I2C-bus controller                                                               */
  CT16B0_IRQn                   =  41,   /**<  57 16-bit timer/counters (CT16B0/1)                                                 */
  CT16B1_IRQn                   =  42,   /**<  58 16-bit timer/counters (CT16B0/1)                                                 */
  CT32B0_IRQn                   =  43,   /**<  59 32-bit timer/counters (CT32B0/1)                                                 */
  CT32B1_IRQn                   =  44,   /**<  60 32-bit timer/counters (CT32B0/1)                                                 */
  SSP0_IRQn                     =  45,   /**<  61 SSP0/1                                                                           */
  UART_IRQn                     =  46,   /**<  62 UART                                                                             */
  USBIRQ_IRQn                   =  47,   /**<  63 USB device controller                                                            */
  USBFIQ_IRQn                   =  48,   /**<  64 USB device controller                                                            */
  ADC_IRQn                      =  49,   /**<  65 Analog-to-Digital Converter                                                      */
  WDT_IRQn                      =  50,   /**<  66 Windowed WatchDog Timer                                                          */
  BOD_IRQn                      =  51,   /**<  67 System configuration                                                             */
  PIO_3_IRQn                    =  53,   /**<  69 General Purpose I/O                                                              */
  PIO_2_IRQn                    =  54,   /**<  70 General Purpose I/O                                                              */
  PIO_1_IRQn                    =  55,   /**<  71 General Purpose I/O                                                              */
  PIO_0_IRQn                    =  56,   /**<  72 General Purpose I/O                                                              */
  SSP1_IRQn                     =  57,   /**<  73 SSP0/1                                                                           */
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
extern void NMI_Handler(void);                       /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);                 /**< Hard Fault, all classes of Fault                                                 */
extern void MemManage_Handler(void);                 /**< Memory Management, MPU mismatch, including Access Violation and No Match         */
extern void BusFault_Handler(void);                  /**< Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
extern void UsageFault_Handler(void);                /**< Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
extern void SVC_Handler(void);                       /**< System Service Call via SVC instruction                                          */
extern void DebugMon_Handler(void);                  /**< Debug Monitor                                                                    */
extern void PendSV_Handler(void);                    /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);                   /**< System Tick Timer                                                                */
extern void PIO0_0_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_1_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_2_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_3_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_4_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_5_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_6_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_7_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_8_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_9_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO0_10_IRQHandler(void);                /**< System configuration                                                             */
extern void PIO0_11_IRQHandler(void);                /**< System configuration                                                             */
extern void PIO1_0_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_1_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_2_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_3_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_4_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_5_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_6_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_7_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_8_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_9_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO1_10_IRQHandler(void);                /**< System configuration                                                             */
extern void PIO1_11_IRQHandler(void);                /**< System configuration                                                             */
extern void PIO2_0_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_1_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_2_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_3_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_4_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_5_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_6_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_7_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_8_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_9_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO2_10_IRQHandler(void);                /**< System configuration                                                             */
extern void PIO2_11_IRQHandler(void);                /**< System configuration                                                             */
extern void PIO3_0_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO3_1_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO3_2_IRQHandler(void);                 /**< System configuration                                                             */
extern void PIO3_3_IRQHandler(void);                 /**< System configuration                                                             */
extern void I2C0_IRQHandler(void);                   /**< I2C-bus controller                                                               */
extern void CT16B0_IRQHandler(void);                 /**< 16-bit timer/counters (CT16B0/1)                                                 */
extern void CT16B1_IRQHandler(void);                 /**< 16-bit timer/counters (CT16B0/1)                                                 */
extern void CT32B0_IRQHandler(void);                 /**< 32-bit timer/counters (CT32B0/1)                                                 */
extern void CT32B1_IRQHandler(void);                 /**< 32-bit timer/counters (CT32B0/1)                                                 */
extern void SSP0_IRQHandler(void);                   /**< SSP0/1                                                                           */
extern void UART_IRQHandler(void);                   /**< UART                                                                             */
extern void USBIRQ_IRQHandler(void);                 /**< USB device controller                                                            */
extern void USBFIQ_IRQHandler(void);                 /**< USB device controller                                                            */
extern void ADC_IRQHandler(void);                    /**< Analog-to-Digital Converter                                                      */
extern void WDT_IRQHandler(void);                    /**< Windowed WatchDog Timer                                                          */
extern void BOD_IRQHandler(void);                    /**< System configuration                                                             */
extern void PIO_3_IRQHandler(void);                  /**< General Purpose I/O                                                              */
extern void PIO_2_IRQHandler(void);                  /**< General Purpose I/O                                                              */
extern void PIO_1_IRQHandler(void);                  /**< General Purpose I/O                                                              */
extern void PIO_0_IRQHandler(void);                  /**< General Purpose I/O                                                              */
extern void SSP1_IRQHandler(void);                   /**< SSP0/1                                                                           */

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
#define __CM3_REV                 0x0100     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          4          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             0          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
#include "core_cm3.h"           /* Processor and core peripherals     */
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
/* ================           LPC_ADC (file:ADC_LPC13xx)           ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct LPC_ADC_Type {
   __IO uint32_t  CR;                           /**< 0000: A/D Control Register. The AD0CR register must be written to select the operating mode before A/D conversion can occur */
   __IO uint32_t  GDR;                          /**< 0004: A/D Global Data Register. Contains the result of the most recent A/D conversion */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  INTEN;                        /**< 000C: A/D Interrupt Enable Register. This register contains enable bits that allow the DONE flag of each A/D channel to be included or excluded from contributing to the generation of an A/D interrupt */
   __IO uint32_t  DR[8];                        /**< 0010: A/D Channel n Data                                           */
   __I  uint32_t  STAT;                         /**< 0030: A/D Status Register. This register contains DONE and OVERRUN flags for all of the A/D channels, as well as the A/D interrupt flag */
} LPC_ADC_Type;

/**
 * @} */ /* End group ADC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_ADC' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ADC_Register_Masks_GROUP ADC Register Masks
* @brief Register Masks for ADC
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define LPC_ADC_CR_SEL_MASK                      (0xFFU)                                             /*!< LPC_ADC_CR.SEL Mask                     */
#define LPC_ADC_CR_SEL_SHIFT                     (0U)                                                /*!< LPC_ADC_CR.SEL Position                 */
#define LPC_ADC_CR_SEL(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_ADC_CR.SEL Field                    */
#define LPC_ADC_CR_CLKDIV_MASK                   (0xFF00U)                                           /*!< LPC_ADC_CR.CLKDIV Mask                  */
#define LPC_ADC_CR_CLKDIV_SHIFT                  (8U)                                                /*!< LPC_ADC_CR.CLKDIV Position              */
#define LPC_ADC_CR_CLKDIV(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< LPC_ADC_CR.CLKDIV Field                 */
#define LPC_ADC_CR_BURST_MASK                    (0x10000U)                                          /*!< LPC_ADC_CR.BURST Mask                   */
#define LPC_ADC_CR_BURST_SHIFT                   (16U)                                               /*!< LPC_ADC_CR.BURST Position               */
#define LPC_ADC_CR_BURST(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPC_ADC_CR.BURST Field                  */
#define LPC_ADC_CR_CLKS_MASK                     (0xE0000U)                                          /*!< LPC_ADC_CR.CLKS Mask                    */
#define LPC_ADC_CR_CLKS_SHIFT                    (17U)                                               /*!< LPC_ADC_CR.CLKS Position                */
#define LPC_ADC_CR_CLKS(x)                       (((uint32_t)(((uint32_t)(x))<<17U))&0xE0000UL)      /*!< LPC_ADC_CR.CLKS Field                   */
#define LPC_ADC_CR_START_MASK                    (0x7000000U)                                        /*!< LPC_ADC_CR.START Mask                   */
#define LPC_ADC_CR_START_SHIFT                   (24U)                                               /*!< LPC_ADC_CR.START Position               */
#define LPC_ADC_CR_START(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x7000000UL)    /*!< LPC_ADC_CR.START Field                  */
#define LPC_ADC_CR_EDGE_MASK                     (0x8000000U)                                        /*!< LPC_ADC_CR.EDGE Mask                    */
#define LPC_ADC_CR_EDGE_SHIFT                    (27U)                                               /*!< LPC_ADC_CR.EDGE Position                */
#define LPC_ADC_CR_EDGE(x)                       (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< LPC_ADC_CR.EDGE Field                   */
/* ------- GDR Bit Fields                           ------ */
#define LPC_ADC_GDR_V_VREF_MASK                  (0xFFC0U)                                           /*!< LPC_ADC_GDR.V_VREF Mask                 */
#define LPC_ADC_GDR_V_VREF_SHIFT                 (6U)                                                /*!< LPC_ADC_GDR.V_VREF Position             */
#define LPC_ADC_GDR_V_VREF(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0xFFC0UL)        /*!< LPC_ADC_GDR.V_VREF Field                */
#define LPC_ADC_GDR_CHN_MASK                     (0x7000000U)                                        /*!< LPC_ADC_GDR.CHN Mask                    */
#define LPC_ADC_GDR_CHN_SHIFT                    (24U)                                               /*!< LPC_ADC_GDR.CHN Position                */
#define LPC_ADC_GDR_CHN(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0x7000000UL)    /*!< LPC_ADC_GDR.CHN Field                   */
#define LPC_ADC_GDR_OVERRUN_MASK                 (0x40000000U)                                       /*!< LPC_ADC_GDR.OVERRUN Mask                */
#define LPC_ADC_GDR_OVERRUN_SHIFT                (30U)                                               /*!< LPC_ADC_GDR.OVERRUN Position            */
#define LPC_ADC_GDR_OVERRUN(x)                   (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPC_ADC_GDR.OVERRUN Field               */
#define LPC_ADC_GDR_DONE_MASK                    (0x80000000U)                                       /*!< LPC_ADC_GDR.DONE Mask                   */
#define LPC_ADC_GDR_DONE_SHIFT                   (31U)                                               /*!< LPC_ADC_GDR.DONE Position               */
#define LPC_ADC_GDR_DONE(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPC_ADC_GDR.DONE Field                  */
/* ------- INTEN Bit Fields                         ------ */
#define LPC_ADC_INTEN_ADINTEN0_MASK              (0x1U)                                              /*!< LPC_ADC_INTEN.ADINTEN0 Mask             */
#define LPC_ADC_INTEN_ADINTEN0_SHIFT             (0U)                                                /*!< LPC_ADC_INTEN.ADINTEN0 Position         */
#define LPC_ADC_INTEN_ADINTEN0(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_ADC_INTEN.ADINTEN0 Field            */
#define LPC_ADC_INTEN_ADINTEN1_MASK              (0x2U)                                              /*!< LPC_ADC_INTEN.ADINTEN1 Mask             */
#define LPC_ADC_INTEN_ADINTEN1_SHIFT             (1U)                                                /*!< LPC_ADC_INTEN.ADINTEN1 Position         */
#define LPC_ADC_INTEN_ADINTEN1(x)                (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_ADC_INTEN.ADINTEN1 Field            */
#define LPC_ADC_INTEN_ADINTEN2_MASK              (0x4U)                                              /*!< LPC_ADC_INTEN.ADINTEN2 Mask             */
#define LPC_ADC_INTEN_ADINTEN2_SHIFT             (2U)                                                /*!< LPC_ADC_INTEN.ADINTEN2 Position         */
#define LPC_ADC_INTEN_ADINTEN2(x)                (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_ADC_INTEN.ADINTEN2 Field            */
#define LPC_ADC_INTEN_ADINTEN3_MASK              (0x8U)                                              /*!< LPC_ADC_INTEN.ADINTEN3 Mask             */
#define LPC_ADC_INTEN_ADINTEN3_SHIFT             (3U)                                                /*!< LPC_ADC_INTEN.ADINTEN3 Position         */
#define LPC_ADC_INTEN_ADINTEN3(x)                (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_ADC_INTEN.ADINTEN3 Field            */
#define LPC_ADC_INTEN_ADINTEN4_MASK              (0x10U)                                             /*!< LPC_ADC_INTEN.ADINTEN4 Mask             */
#define LPC_ADC_INTEN_ADINTEN4_SHIFT             (4U)                                                /*!< LPC_ADC_INTEN.ADINTEN4 Position         */
#define LPC_ADC_INTEN_ADINTEN4(x)                (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_ADC_INTEN.ADINTEN4 Field            */
#define LPC_ADC_INTEN_ADINTEN5_MASK              (0x20U)                                             /*!< LPC_ADC_INTEN.ADINTEN5 Mask             */
#define LPC_ADC_INTEN_ADINTEN5_SHIFT             (5U)                                                /*!< LPC_ADC_INTEN.ADINTEN5 Position         */
#define LPC_ADC_INTEN_ADINTEN5(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_ADC_INTEN.ADINTEN5 Field            */
#define LPC_ADC_INTEN_ADINTEN6_MASK              (0x40U)                                             /*!< LPC_ADC_INTEN.ADINTEN6 Mask             */
#define LPC_ADC_INTEN_ADINTEN6_SHIFT             (6U)                                                /*!< LPC_ADC_INTEN.ADINTEN6 Position         */
#define LPC_ADC_INTEN_ADINTEN6(x)                (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_ADC_INTEN.ADINTEN6 Field            */
#define LPC_ADC_INTEN_ADINTEN7_MASK              (0x80U)                                             /*!< LPC_ADC_INTEN.ADINTEN7 Mask             */
#define LPC_ADC_INTEN_ADINTEN7_SHIFT             (7U)                                                /*!< LPC_ADC_INTEN.ADINTEN7 Position         */
#define LPC_ADC_INTEN_ADINTEN7(x)                (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_ADC_INTEN.ADINTEN7 Field            */
#define LPC_ADC_INTEN_ADGINTEN_MASK              (0x100U)                                            /*!< LPC_ADC_INTEN.ADGINTEN Mask             */
#define LPC_ADC_INTEN_ADGINTEN_SHIFT             (8U)                                                /*!< LPC_ADC_INTEN.ADGINTEN Position         */
#define LPC_ADC_INTEN_ADGINTEN(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_ADC_INTEN.ADGINTEN Field            */
/* ------- DR Bit Fields                            ------ */
#define LPC_ADC_DR_V_VREF_MASK                   (0xFFC0U)                                           /*!< LPC_ADC_DR.V_VREF Mask                  */
#define LPC_ADC_DR_V_VREF_SHIFT                  (6U)                                                /*!< LPC_ADC_DR.V_VREF Position              */
#define LPC_ADC_DR_V_VREF(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0xFFC0UL)        /*!< LPC_ADC_DR.V_VREF Field                 */
#define LPC_ADC_DR_OVERRUN_MASK                  (0x40000000U)                                       /*!< LPC_ADC_DR.OVERRUN Mask                 */
#define LPC_ADC_DR_OVERRUN_SHIFT                 (30U)                                               /*!< LPC_ADC_DR.OVERRUN Position             */
#define LPC_ADC_DR_OVERRUN(x)                    (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPC_ADC_DR.OVERRUN Field                */
#define LPC_ADC_DR_DONE_MASK                     (0x80000000U)                                       /*!< LPC_ADC_DR.DONE Mask                    */
#define LPC_ADC_DR_DONE_SHIFT                    (31U)                                               /*!< LPC_ADC_DR.DONE Position                */
#define LPC_ADC_DR_DONE(x)                       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPC_ADC_DR.DONE Field                   */
/* ------- STAT Bit Fields                          ------ */
#define LPC_ADC_STAT_DONE0_MASK                  (0x1U)                                              /*!< LPC_ADC_STAT.DONE0 Mask                 */
#define LPC_ADC_STAT_DONE0_SHIFT                 (0U)                                                /*!< LPC_ADC_STAT.DONE0 Position             */
#define LPC_ADC_STAT_DONE0(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_ADC_STAT.DONE0 Field                */
#define LPC_ADC_STAT_DONE1_MASK                  (0x2U)                                              /*!< LPC_ADC_STAT.DONE1 Mask                 */
#define LPC_ADC_STAT_DONE1_SHIFT                 (1U)                                                /*!< LPC_ADC_STAT.DONE1 Position             */
#define LPC_ADC_STAT_DONE1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_ADC_STAT.DONE1 Field                */
#define LPC_ADC_STAT_DONE2_MASK                  (0x4U)                                              /*!< LPC_ADC_STAT.DONE2 Mask                 */
#define LPC_ADC_STAT_DONE2_SHIFT                 (2U)                                                /*!< LPC_ADC_STAT.DONE2 Position             */
#define LPC_ADC_STAT_DONE2(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_ADC_STAT.DONE2 Field                */
#define LPC_ADC_STAT_DONE3_MASK                  (0x8U)                                              /*!< LPC_ADC_STAT.DONE3 Mask                 */
#define LPC_ADC_STAT_DONE3_SHIFT                 (3U)                                                /*!< LPC_ADC_STAT.DONE3 Position             */
#define LPC_ADC_STAT_DONE3(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_ADC_STAT.DONE3 Field                */
#define LPC_ADC_STAT_DONE4_MASK                  (0x10U)                                             /*!< LPC_ADC_STAT.DONE4 Mask                 */
#define LPC_ADC_STAT_DONE4_SHIFT                 (4U)                                                /*!< LPC_ADC_STAT.DONE4 Position             */
#define LPC_ADC_STAT_DONE4(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_ADC_STAT.DONE4 Field                */
#define LPC_ADC_STAT_DONE5_MASK                  (0x20U)                                             /*!< LPC_ADC_STAT.DONE5 Mask                 */
#define LPC_ADC_STAT_DONE5_SHIFT                 (5U)                                                /*!< LPC_ADC_STAT.DONE5 Position             */
#define LPC_ADC_STAT_DONE5(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_ADC_STAT.DONE5 Field                */
#define LPC_ADC_STAT_DONE6_MASK                  (0x40U)                                             /*!< LPC_ADC_STAT.DONE6 Mask                 */
#define LPC_ADC_STAT_DONE6_SHIFT                 (6U)                                                /*!< LPC_ADC_STAT.DONE6 Position             */
#define LPC_ADC_STAT_DONE6(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_ADC_STAT.DONE6 Field                */
#define LPC_ADC_STAT_DONE7_MASK                  (0x80U)                                             /*!< LPC_ADC_STAT.DONE7 Mask                 */
#define LPC_ADC_STAT_DONE7_SHIFT                 (7U)                                                /*!< LPC_ADC_STAT.DONE7 Position             */
#define LPC_ADC_STAT_DONE7(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_ADC_STAT.DONE7 Field                */
#define LPC_ADC_STAT_OVERRUN0_MASK               (0x100U)                                            /*!< LPC_ADC_STAT.OVERRUN0 Mask              */
#define LPC_ADC_STAT_OVERRUN0_SHIFT              (8U)                                                /*!< LPC_ADC_STAT.OVERRUN0 Position          */
#define LPC_ADC_STAT_OVERRUN0(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_ADC_STAT.OVERRUN0 Field             */
#define LPC_ADC_STAT_OVERRUN1_MASK               (0x200U)                                            /*!< LPC_ADC_STAT.OVERRUN1 Mask              */
#define LPC_ADC_STAT_OVERRUN1_SHIFT              (9U)                                                /*!< LPC_ADC_STAT.OVERRUN1 Position          */
#define LPC_ADC_STAT_OVERRUN1(x)                 (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_ADC_STAT.OVERRUN1 Field             */
#define LPC_ADC_STAT_OVERRUN2_MASK               (0x400U)                                            /*!< LPC_ADC_STAT.OVERRUN2 Mask              */
#define LPC_ADC_STAT_OVERRUN2_SHIFT              (10U)                                               /*!< LPC_ADC_STAT.OVERRUN2 Position          */
#define LPC_ADC_STAT_OVERRUN2(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_ADC_STAT.OVERRUN2 Field             */
#define LPC_ADC_STAT_OVERRUN3_MASK               (0x800U)                                            /*!< LPC_ADC_STAT.OVERRUN3 Mask              */
#define LPC_ADC_STAT_OVERRUN3_SHIFT              (11U)                                               /*!< LPC_ADC_STAT.OVERRUN3 Position          */
#define LPC_ADC_STAT_OVERRUN3(x)                 (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_ADC_STAT.OVERRUN3 Field             */
#define LPC_ADC_STAT_OVERRUN4_MASK               (0x1000U)                                           /*!< LPC_ADC_STAT.OVERRUN4 Mask              */
#define LPC_ADC_STAT_OVERRUN4_SHIFT              (12U)                                               /*!< LPC_ADC_STAT.OVERRUN4 Position          */
#define LPC_ADC_STAT_OVERRUN4(x)                 (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_ADC_STAT.OVERRUN4 Field             */
#define LPC_ADC_STAT_OVERRUN5_MASK               (0x2000U)                                           /*!< LPC_ADC_STAT.OVERRUN5 Mask              */
#define LPC_ADC_STAT_OVERRUN5_SHIFT              (13U)                                               /*!< LPC_ADC_STAT.OVERRUN5 Position          */
#define LPC_ADC_STAT_OVERRUN5(x)                 (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_ADC_STAT.OVERRUN5 Field             */
#define LPC_ADC_STAT_OVERRUN6_MASK               (0x4000U)                                           /*!< LPC_ADC_STAT.OVERRUN6 Mask              */
#define LPC_ADC_STAT_OVERRUN6_SHIFT              (14U)                                               /*!< LPC_ADC_STAT.OVERRUN6 Position          */
#define LPC_ADC_STAT_OVERRUN6(x)                 (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPC_ADC_STAT.OVERRUN6 Field             */
#define LPC_ADC_STAT_OVERRUN7_MASK               (0x8000U)                                           /*!< LPC_ADC_STAT.OVERRUN7 Mask              */
#define LPC_ADC_STAT_OVERRUN7_SHIFT              (15U)                                               /*!< LPC_ADC_STAT.OVERRUN7 Position          */
#define LPC_ADC_STAT_OVERRUN7(x)                 (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPC_ADC_STAT.OVERRUN7 Field             */
#define LPC_ADC_STAT_ADINT_MASK                  (0x10000U)                                          /*!< LPC_ADC_STAT.ADINT Mask                 */
#define LPC_ADC_STAT_ADINT_SHIFT                 (16U)                                               /*!< LPC_ADC_STAT.ADINT Position             */
#define LPC_ADC_STAT_ADINT(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPC_ADC_STAT.ADINT Field                */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* LPC_ADC - Peripheral instance base addresses */
#define LPC_ADC_BasePtr                0x4001C000UL //!< Peripheral base address
#define LPC_ADC                        ((LPC_ADC_Type *) LPC_ADC_BasePtr) //!< Freescale base pointer
#define LPC_ADC_BASE_PTR               (LPC_ADC) //!< Freescale style base pointer
#define LPC_ADC_IRQS { ADC_IRQn,  }

/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT16B0_Peripheral_access_layer_GROUP CT16B0 Peripheral Access Layer
* @brief C Struct for CT16B0
* @{
*/

/* ================================================================================ */
/* ================           LPC_CT16B0 (file:CT16B0_LPC13xx)       ================ */
/* ================================================================================ */

/**
 * @brief 16-bit timer/counters (CT16B0/1)
 */
/**
* @addtogroup CT16B0_structs_GROUP CT16B0 struct
* @brief Struct for CT16B0
* @{
*/
typedef struct LPC_CT16B0_Type {
   __IO uint32_t  BIR;                          /**< 0000: Interrupt Register (IR). The IR can be written to clear interrupts. The IR can be read to identify which of five possible interrupt sources are pending */
   __IO uint32_t  BTCR;                         /**< 0004: Timer Control Register (TCR). The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  BTC;                          /**< 0008: Timer Counter (TC). The 16-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  BPR;                          /**< 000C: Prescale Register (PR). When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  BPC;                          /**< 0010: Prescale Counter (PC). The 16-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  BMCR;                         /**< 0014: Match Control Register (MCR). The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  BMR0;                         /**< 0018: Match Register 0 (MR0). MR0 can be enabled through the MCR   */
   __IO uint32_t  BMR1;                         /**< 001C: Match Register 0 (MR0). MR0 can be enabled through the MCR   */
   __IO uint32_t  BMR2;                         /**< 0020: Match Register 0 (MR0). MR0 can be enabled through the MCR   */
   __IO uint32_t  BMR3;                         /**< 0024: Match Register 0 (MR0). MR0 can be enabled through the MCR   */
   __IO uint32_t  BCCR;                         /**< 0028: Capture Control Register (CCR). The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  BCR0;                         /**< 002C: Capture Register 0 (CR0). CR0 is loaded with the value of TC when there is an event on the CT16B0_CAP0 input */
        uint8_t   RESERVED_0[12];              
   __IO uint32_t  BEMR;                         /**< 003C: External Match Register (EMR). The EMR controls the match function and the external match pins CT16B0_MAT[2:0] */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  BCTCR;                        /**< 0070: Count Control Register (CTCR). The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  BPWMC;                        /**< 0074: PWM Control Register (PWMCON). The PWMCON enables PWM mode for the external match pins CT16B0_MAT[2:0] */
} LPC_CT16B0_Type;

/**
 * @} */ /* End group CT16B0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_CT16B0' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CT16B0_Register_Masks_GROUP CT16B0 Register Masks
* @brief Register Masks for CT16B0
* @{
*/
/* ------- BIR Bit Fields                           ------ */
#define LPC_CT16B0_BIR_MR0INT_MASK               (0x1U)                                              /*!< LPC_CT16B0_BIR.MR0INT Mask              */
#define LPC_CT16B0_BIR_MR0INT_SHIFT              (0U)                                                /*!< LPC_CT16B0_BIR.MR0INT Position          */
#define LPC_CT16B0_BIR_MR0INT(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT16B0_BIR.MR0INT Field             */
#define LPC_CT16B0_BIR_MR1INT_MASK               (0x2U)                                              /*!< LPC_CT16B0_BIR.MR1INT Mask              */
#define LPC_CT16B0_BIR_MR1INT_SHIFT              (1U)                                                /*!< LPC_CT16B0_BIR.MR1INT Position          */
#define LPC_CT16B0_BIR_MR1INT(x)                 (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT16B0_BIR.MR1INT Field             */
#define LPC_CT16B0_BIR_MR2INT_MASK               (0x4U)                                              /*!< LPC_CT16B0_BIR.MR2INT Mask              */
#define LPC_CT16B0_BIR_MR2INT_SHIFT              (2U)                                                /*!< LPC_CT16B0_BIR.MR2INT Position          */
#define LPC_CT16B0_BIR_MR2INT(x)                 (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT16B0_BIR.MR2INT Field             */
#define LPC_CT16B0_BIR_MR3INT_MASK               (0x8U)                                              /*!< LPC_CT16B0_BIR.MR3INT Mask              */
#define LPC_CT16B0_BIR_MR3INT_SHIFT              (3U)                                                /*!< LPC_CT16B0_BIR.MR3INT Position          */
#define LPC_CT16B0_BIR_MR3INT(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_CT16B0_BIR.MR3INT Field             */
#define LPC_CT16B0_BIR_CR0INT_MASK               (0x10U)                                             /*!< LPC_CT16B0_BIR.CR0INT Mask              */
#define LPC_CT16B0_BIR_CR0INT_SHIFT              (4U)                                                /*!< LPC_CT16B0_BIR.CR0INT Position          */
#define LPC_CT16B0_BIR_CR0INT(x)                 (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_CT16B0_BIR.CR0INT Field             */
/* ------- BTCR Bit Fields                          ------ */
#define LPC_CT16B0_BTCR_CEN_MASK                 (0x1U)                                              /*!< LPC_CT16B0_BTCR.CEN Mask                */
#define LPC_CT16B0_BTCR_CEN_SHIFT                (0U)                                                /*!< LPC_CT16B0_BTCR.CEN Position            */
#define LPC_CT16B0_BTCR_CEN(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT16B0_BTCR.CEN Field               */
#define LPC_CT16B0_BTCR_CRESET_MASK              (0x2U)                                              /*!< LPC_CT16B0_BTCR.CRESET Mask             */
#define LPC_CT16B0_BTCR_CRESET_SHIFT             (1U)                                                /*!< LPC_CT16B0_BTCR.CRESET Position         */
#define LPC_CT16B0_BTCR_CRESET(x)                (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT16B0_BTCR.CRESET Field            */
/* ------- BTC Bit Fields                           ------ */
#define LPC_CT16B0_BTC_TC_MASK                   (0xFFFFU)                                           /*!< LPC_CT16B0_BTC.TC Mask                  */
#define LPC_CT16B0_BTC_TC_SHIFT                  (0U)                                                /*!< LPC_CT16B0_BTC.TC Position              */
#define LPC_CT16B0_BTC_TC(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_CT16B0_BTC.TC Field                 */
/* ------- BPR Bit Fields                           ------ */
#define LPC_CT16B0_BPR_PR_MASK                   (0xFFFFU)                                           /*!< LPC_CT16B0_BPR.PR Mask                  */
#define LPC_CT16B0_BPR_PR_SHIFT                  (0U)                                                /*!< LPC_CT16B0_BPR.PR Position              */
#define LPC_CT16B0_BPR_PR(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_CT16B0_BPR.PR Field                 */
/* ------- BPC Bit Fields                           ------ */
#define LPC_CT16B0_BPC_PC_MASK                   (0xFFFFU)                                           /*!< LPC_CT16B0_BPC.PC Mask                  */
#define LPC_CT16B0_BPC_PC_SHIFT                  (0U)                                                /*!< LPC_CT16B0_BPC.PC Position              */
#define LPC_CT16B0_BPC_PC(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_CT16B0_BPC.PC Field                 */
/* ------- BMCR Bit Fields                          ------ */
#define LPC_CT16B0_BMCR_MR0I_MASK                (0x1U)                                              /*!< LPC_CT16B0_BMCR.MR0I Mask               */
#define LPC_CT16B0_BMCR_MR0I_SHIFT               (0U)                                                /*!< LPC_CT16B0_BMCR.MR0I Position           */
#define LPC_CT16B0_BMCR_MR0I(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT16B0_BMCR.MR0I Field              */
#define LPC_CT16B0_BMCR_MR0R_MASK                (0x2U)                                              /*!< LPC_CT16B0_BMCR.MR0R Mask               */
#define LPC_CT16B0_BMCR_MR0R_SHIFT               (1U)                                                /*!< LPC_CT16B0_BMCR.MR0R Position           */
#define LPC_CT16B0_BMCR_MR0R(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT16B0_BMCR.MR0R Field              */
#define LPC_CT16B0_BMCR_MR0S_MASK                (0x4U)                                              /*!< LPC_CT16B0_BMCR.MR0S Mask               */
#define LPC_CT16B0_BMCR_MR0S_SHIFT               (2U)                                                /*!< LPC_CT16B0_BMCR.MR0S Position           */
#define LPC_CT16B0_BMCR_MR0S(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT16B0_BMCR.MR0S Field              */
#define LPC_CT16B0_BMCR_MR1I_MASK                (0x8U)                                              /*!< LPC_CT16B0_BMCR.MR1I Mask               */
#define LPC_CT16B0_BMCR_MR1I_SHIFT               (3U)                                                /*!< LPC_CT16B0_BMCR.MR1I Position           */
#define LPC_CT16B0_BMCR_MR1I(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_CT16B0_BMCR.MR1I Field              */
#define LPC_CT16B0_BMCR_MR1R_MASK                (0x10U)                                             /*!< LPC_CT16B0_BMCR.MR1R Mask               */
#define LPC_CT16B0_BMCR_MR1R_SHIFT               (4U)                                                /*!< LPC_CT16B0_BMCR.MR1R Position           */
#define LPC_CT16B0_BMCR_MR1R(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_CT16B0_BMCR.MR1R Field              */
#define LPC_CT16B0_BMCR_MR1S_MASK                (0x20U)                                             /*!< LPC_CT16B0_BMCR.MR1S Mask               */
#define LPC_CT16B0_BMCR_MR1S_SHIFT               (5U)                                                /*!< LPC_CT16B0_BMCR.MR1S Position           */
#define LPC_CT16B0_BMCR_MR1S(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_CT16B0_BMCR.MR1S Field              */
#define LPC_CT16B0_BMCR_MR2I_MASK                (0x40U)                                             /*!< LPC_CT16B0_BMCR.MR2I Mask               */
#define LPC_CT16B0_BMCR_MR2I_SHIFT               (6U)                                                /*!< LPC_CT16B0_BMCR.MR2I Position           */
#define LPC_CT16B0_BMCR_MR2I(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_CT16B0_BMCR.MR2I Field              */
#define LPC_CT16B0_BMCR_MR2R_MASK                (0x80U)                                             /*!< LPC_CT16B0_BMCR.MR2R Mask               */
#define LPC_CT16B0_BMCR_MR2R_SHIFT               (7U)                                                /*!< LPC_CT16B0_BMCR.MR2R Position           */
#define LPC_CT16B0_BMCR_MR2R(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_CT16B0_BMCR.MR2R Field              */
#define LPC_CT16B0_BMCR_MR2S_MASK                (0x100U)                                            /*!< LPC_CT16B0_BMCR.MR2S Mask               */
#define LPC_CT16B0_BMCR_MR2S_SHIFT               (8U)                                                /*!< LPC_CT16B0_BMCR.MR2S Position           */
#define LPC_CT16B0_BMCR_MR2S(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_CT16B0_BMCR.MR2S Field              */
#define LPC_CT16B0_BMCR_MR3I_MASK                (0x200U)                                            /*!< LPC_CT16B0_BMCR.MR3I Mask               */
#define LPC_CT16B0_BMCR_MR3I_SHIFT               (9U)                                                /*!< LPC_CT16B0_BMCR.MR3I Position           */
#define LPC_CT16B0_BMCR_MR3I(x)                  (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_CT16B0_BMCR.MR3I Field              */
#define LPC_CT16B0_BMCR_MR3R_MASK                (0x400U)                                            /*!< LPC_CT16B0_BMCR.MR3R Mask               */
#define LPC_CT16B0_BMCR_MR3R_SHIFT               (10U)                                               /*!< LPC_CT16B0_BMCR.MR3R Position           */
#define LPC_CT16B0_BMCR_MR3R(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_CT16B0_BMCR.MR3R Field              */
#define LPC_CT16B0_BMCR_MR3S_MASK                (0x800U)                                            /*!< LPC_CT16B0_BMCR.MR3S Mask               */
#define LPC_CT16B0_BMCR_MR3S_SHIFT               (11U)                                               /*!< LPC_CT16B0_BMCR.MR3S Position           */
#define LPC_CT16B0_BMCR_MR3S(x)                  (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_CT16B0_BMCR.MR3S Field              */
/* ------- BMR0 Bit Fields                          ------ */
#define LPC_CT16B0_BMR0_MATCH_MASK               (0xFFFFU)                                           /*!< LPC_CT16B0_BMR0.MATCH Mask              */
#define LPC_CT16B0_BMR0_MATCH_SHIFT              (0U)                                                /*!< LPC_CT16B0_BMR0.MATCH Position          */
#define LPC_CT16B0_BMR0_MATCH(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_CT16B0_BMR0.MATCH Field             */
/* ------- BMR Bit Fields                           ------ */
#define LPC_CT16B0_BMR_MATCH_MASK                (0xFFFFU)                                           /*!< LPC_CT16B0_BMR.MATCH Mask               */
#define LPC_CT16B0_BMR_MATCH_SHIFT               (0U)                                                /*!< LPC_CT16B0_BMR.MATCH Position           */
#define LPC_CT16B0_BMR_MATCH(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_CT16B0_BMR.MATCH Field              */
/* ------- BCCR Bit Fields                          ------ */
#define LPC_CT16B0_BCCR_CAP0RE_MASK              (0x1U)                                              /*!< LPC_CT16B0_BCCR.CAP0RE Mask             */
#define LPC_CT16B0_BCCR_CAP0RE_SHIFT             (0U)                                                /*!< LPC_CT16B0_BCCR.CAP0RE Position         */
#define LPC_CT16B0_BCCR_CAP0RE(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT16B0_BCCR.CAP0RE Field            */
#define LPC_CT16B0_BCCR_CAP0FE_MASK              (0x2U)                                              /*!< LPC_CT16B0_BCCR.CAP0FE Mask             */
#define LPC_CT16B0_BCCR_CAP0FE_SHIFT             (1U)                                                /*!< LPC_CT16B0_BCCR.CAP0FE Position         */
#define LPC_CT16B0_BCCR_CAP0FE(x)                (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT16B0_BCCR.CAP0FE Field            */
#define LPC_CT16B0_BCCR_CAP0I_MASK               (0x4U)                                              /*!< LPC_CT16B0_BCCR.CAP0I Mask              */
#define LPC_CT16B0_BCCR_CAP0I_SHIFT              (2U)                                                /*!< LPC_CT16B0_BCCR.CAP0I Position          */
#define LPC_CT16B0_BCCR_CAP0I(x)                 (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT16B0_BCCR.CAP0I Field             */
/* ------- BCR0 Bit Fields                          ------ */
#define LPC_CT16B0_BCR0_CAP_MASK                 (0xFFFFU)                                           /*!< LPC_CT16B0_BCR0.CAP Mask                */
#define LPC_CT16B0_BCR0_CAP_SHIFT                (0U)                                                /*!< LPC_CT16B0_BCR0.CAP Position            */
#define LPC_CT16B0_BCR0_CAP(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_CT16B0_BCR0.CAP Field               */
/* ------- BEMR Bit Fields                          ------ */
#define LPC_CT16B0_BEMR_EM0_MASK                 (0x1U)                                              /*!< LPC_CT16B0_BEMR.EM0 Mask                */
#define LPC_CT16B0_BEMR_EM0_SHIFT                (0U)                                                /*!< LPC_CT16B0_BEMR.EM0 Position            */
#define LPC_CT16B0_BEMR_EM0(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT16B0_BEMR.EM0 Field               */
#define LPC_CT16B0_BEMR_EM1_MASK                 (0x2U)                                              /*!< LPC_CT16B0_BEMR.EM1 Mask                */
#define LPC_CT16B0_BEMR_EM1_SHIFT                (1U)                                                /*!< LPC_CT16B0_BEMR.EM1 Position            */
#define LPC_CT16B0_BEMR_EM1(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT16B0_BEMR.EM1 Field               */
#define LPC_CT16B0_BEMR_EM2_MASK                 (0x4U)                                              /*!< LPC_CT16B0_BEMR.EM2 Mask                */
#define LPC_CT16B0_BEMR_EM2_SHIFT                (2U)                                                /*!< LPC_CT16B0_BEMR.EM2 Position            */
#define LPC_CT16B0_BEMR_EM2(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT16B0_BEMR.EM2 Field               */
#define LPC_CT16B0_BEMR_EM3_MASK                 (0x8U)                                              /*!< LPC_CT16B0_BEMR.EM3 Mask                */
#define LPC_CT16B0_BEMR_EM3_SHIFT                (3U)                                                /*!< LPC_CT16B0_BEMR.EM3 Position            */
#define LPC_CT16B0_BEMR_EM3(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_CT16B0_BEMR.EM3 Field               */
#define LPC_CT16B0_BEMR_EMC0_MASK                (0x30U)                                             /*!< LPC_CT16B0_BEMR.EMC0 Mask               */
#define LPC_CT16B0_BEMR_EMC0_SHIFT               (4U)                                                /*!< LPC_CT16B0_BEMR.EMC0 Position           */
#define LPC_CT16B0_BEMR_EMC0(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< LPC_CT16B0_BEMR.EMC0 Field              */
#define LPC_CT16B0_BEMR_EMC1_MASK                (0xC0U)                                             /*!< LPC_CT16B0_BEMR.EMC1 Mask               */
#define LPC_CT16B0_BEMR_EMC1_SHIFT               (6U)                                                /*!< LPC_CT16B0_BEMR.EMC1 Position           */
#define LPC_CT16B0_BEMR_EMC1(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< LPC_CT16B0_BEMR.EMC1 Field              */
#define LPC_CT16B0_BEMR_EMC2_MASK                (0x300U)                                            /*!< LPC_CT16B0_BEMR.EMC2 Mask               */
#define LPC_CT16B0_BEMR_EMC2_SHIFT               (8U)                                                /*!< LPC_CT16B0_BEMR.EMC2 Position           */
#define LPC_CT16B0_BEMR_EMC2(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< LPC_CT16B0_BEMR.EMC2 Field              */
#define LPC_CT16B0_BEMR_EMC3_MASK                (0xC00U)                                            /*!< LPC_CT16B0_BEMR.EMC3 Mask               */
#define LPC_CT16B0_BEMR_EMC3_SHIFT               (10U)                                               /*!< LPC_CT16B0_BEMR.EMC3 Position           */
#define LPC_CT16B0_BEMR_EMC3(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0xC00UL)        /*!< LPC_CT16B0_BEMR.EMC3 Field              */
/* ------- BCTCR Bit Fields                         ------ */
#define LPC_CT16B0_BCTCR_CTM_MASK                (0x3U)                                              /*!< LPC_CT16B0_BCTCR.CTM Mask               */
#define LPC_CT16B0_BCTCR_CTM_SHIFT               (0U)                                                /*!< LPC_CT16B0_BCTCR.CTM Position           */
#define LPC_CT16B0_BCTCR_CTM(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_CT16B0_BCTCR.CTM Field              */
#define LPC_CT16B0_BCTCR_CIS_MASK                (0xCU)                                              /*!< LPC_CT16B0_BCTCR.CIS Mask               */
#define LPC_CT16B0_BCTCR_CIS_SHIFT               (2U)                                                /*!< LPC_CT16B0_BCTCR.CIS Position           */
#define LPC_CT16B0_BCTCR_CIS(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< LPC_CT16B0_BCTCR.CIS Field              */
/* ------- BPWMC Bit Fields                         ------ */
#define LPC_CT16B0_BPWMC_PWMEN0_MASK             (0x1U)                                              /*!< LPC_CT16B0_BPWMC.PWMEN0 Mask            */
#define LPC_CT16B0_BPWMC_PWMEN0_SHIFT            (0U)                                                /*!< LPC_CT16B0_BPWMC.PWMEN0 Position        */
#define LPC_CT16B0_BPWMC_PWMEN0(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT16B0_BPWMC.PWMEN0 Field           */
#define LPC_CT16B0_BPWMC_PWMEN1_MASK             (0x2U)                                              /*!< LPC_CT16B0_BPWMC.PWMEN1 Mask            */
#define LPC_CT16B0_BPWMC_PWMEN1_SHIFT            (1U)                                                /*!< LPC_CT16B0_BPWMC.PWMEN1 Position        */
#define LPC_CT16B0_BPWMC_PWMEN1(x)               (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT16B0_BPWMC.PWMEN1 Field           */
#define LPC_CT16B0_BPWMC_PWMEN2_MASK             (0x4U)                                              /*!< LPC_CT16B0_BPWMC.PWMEN2 Mask            */
#define LPC_CT16B0_BPWMC_PWMEN2_SHIFT            (2U)                                                /*!< LPC_CT16B0_BPWMC.PWMEN2 Position        */
#define LPC_CT16B0_BPWMC_PWMEN2(x)               (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT16B0_BPWMC.PWMEN2 Field           */
#define LPC_CT16B0_BPWMC_PWMEN3_MASK             (0x8U)                                              /*!< LPC_CT16B0_BPWMC.PWMEN3 Mask            */
#define LPC_CT16B0_BPWMC_PWMEN3_SHIFT            (3U)                                                /*!< LPC_CT16B0_BPWMC.PWMEN3 Position        */
#define LPC_CT16B0_BPWMC_PWMEN3(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_CT16B0_BPWMC.PWMEN3 Field           */
/**
 * @} */ /* End group CT16B0_Register_Masks_GROUP 
 */

/* LPC_CT16B0 - Peripheral instance base addresses */
#define LPC_CT16B0_BasePtr             0x4000C000UL //!< Peripheral base address
#define LPC_CT16B0                     ((LPC_CT16B0_Type *) LPC_CT16B0_BasePtr) //!< Freescale base pointer
#define LPC_CT16B0_BASE_PTR            (LPC_CT16B0) //!< Freescale style base pointer
#define LPC_CT16B0_IRQS { CT16B0_IRQn,  }

/**
 * @} */ /* End group CT16B0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT16B0_Peripheral_access_layer_GROUP CT16B0 Peripheral Access Layer
* @brief C Struct for CT16B0
* @{
*/

/* ================================================================================ */
/* ================           LPC_CT16B1 (derived from CT16B0)       ================ */
/* ================================================================================ */

/**
 * @brief 16-bit timer/counters (CT16B0/1)
 */

/* LPC_CT16B1 - Peripheral instance base addresses */
#define LPC_CT16B1_BasePtr             0x40010000UL //!< Peripheral base address
#define LPC_CT16B1                     ((LPC_CT16B0_Type *) LPC_CT16B1_BasePtr) //!< Freescale base pointer
#define LPC_CT16B1_BASE_PTR            (LPC_CT16B1) //!< Freescale style base pointer
#define LPC_CT16B1_IRQS { CT16B1_IRQn,  }

/**
 * @} */ /* End group CT16B0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT32B0_Peripheral_access_layer_GROUP CT32B0 Peripheral Access Layer
* @brief C Struct for CT32B0
* @{
*/

/* ================================================================================ */
/* ================           LPC_CT32B0 (file:CT32B0_LPC13xx)       ================ */
/* ================================================================================ */

/**
 * @brief 32-bit timer/counters (CT32B0/1)
 */
/**
* @addtogroup CT32B0_structs_GROUP CT32B0 struct
* @brief Struct for CT32B0
* @{
*/
typedef struct LPC_CT32B0_Type {
   __IO uint32_t  BIR;                          /**< 0000: Interrupt Register (IR). The IR can be written to clear interrupts. The IR can be read to identify which of five possible interrupt sources are pending */
   __IO uint32_t  BTCR;                         /**< 0004: Timer Control Register (TCR). The TCR is used to control the Timer Counter functions. The Timer Counter can be disabled or reset through the TCR */
   __IO uint32_t  BTC;                          /**< 0008: Timer Counter (TC). The 32-bit TC is incremented every PR+1 cycles of PCLK. The TC is controlled through the TCR */
   __IO uint32_t  BPR;                          /**< 000C: Prescale Register (PR). When the Prescale Counter (below) is equal to this value, the next clock increments the TC and clears the PC */
   __IO uint32_t  BPC;                          /**< 0010: Prescale Counter (PC). The 32-bit PC is a counter which is incremented to the value stored in PR. When the value in PR is reached, the TC is incremented and the PC is cleared. The PC is observable and controllable through the bus interface */
   __IO uint32_t  BMCR;                         /**< 0014: Match Control Register (MCR). The MCR is used to control if an interrupt is generated and if the TC is reset when a Match occurs */
   __IO uint32_t  BMR0;                         /**< 0018: Match Register. MR can be enabled through the MCR            */
   __IO uint32_t  BMR1;                         /**< 001C: Match Register. MR can be enabled through the MCR            */
   __IO uint32_t  BMR2;                         /**< 0020: Match Register. MR can be enabled through the MCR            */
   __IO uint32_t  BMR3;                         /**< 0024: Match Register. MR can be enabled through the MCR            */
   __IO uint32_t  BCCR;                         /**< 0028: Capture Control Register (CCR). The CCR controls which edges of the capture inputs are used to load the Capture Registers and whether or not an interrupt is generated when a capture takes place */
   __I  uint32_t  BCR0;                         /**< 002C: Capture Register 0 (CR0). CR0 is loaded with the value of TC when there is an event on the CT32B0_CAP0 input */
        uint8_t   RESERVED_0[12];              
   __IO uint32_t  BEMR;                         /**< 003C: External Match Register (EMR). The EMR controls the match function and the external match pins CT32B0_MAT[3:0] */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  BCTCR;                        /**< 0070: Count Control Register (CTCR). The CTCR selects between Timer and Counter mode, and in Counter mode selects the signal and edge(s) for counting */
   __IO uint32_t  BPWMC;                        /**< 0074: PWM Control Register (PWMCON). The PWMCON enables PWM mode for the external match pins CT32B0_MAT[3:0] */
} LPC_CT32B0_Type;

/**
 * @} */ /* End group CT32B0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_CT32B0' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CT32B0_Register_Masks_GROUP CT32B0 Register Masks
* @brief Register Masks for CT32B0
* @{
*/
/* ------- BIR Bit Fields                           ------ */
#define LPC_CT32B0_BIR_MR0INT_MASK               (0x1U)                                              /*!< LPC_CT32B0_BIR.MR0INT Mask              */
#define LPC_CT32B0_BIR_MR0INT_SHIFT              (0U)                                                /*!< LPC_CT32B0_BIR.MR0INT Position          */
#define LPC_CT32B0_BIR_MR0INT(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT32B0_BIR.MR0INT Field             */
#define LPC_CT32B0_BIR_MR1INT_MASK               (0x2U)                                              /*!< LPC_CT32B0_BIR.MR1INT Mask              */
#define LPC_CT32B0_BIR_MR1INT_SHIFT              (1U)                                                /*!< LPC_CT32B0_BIR.MR1INT Position          */
#define LPC_CT32B0_BIR_MR1INT(x)                 (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT32B0_BIR.MR1INT Field             */
#define LPC_CT32B0_BIR_MR2INT_MASK               (0x4U)                                              /*!< LPC_CT32B0_BIR.MR2INT Mask              */
#define LPC_CT32B0_BIR_MR2INT_SHIFT              (2U)                                                /*!< LPC_CT32B0_BIR.MR2INT Position          */
#define LPC_CT32B0_BIR_MR2INT(x)                 (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT32B0_BIR.MR2INT Field             */
#define LPC_CT32B0_BIR_MR3INT_MASK               (0x8U)                                              /*!< LPC_CT32B0_BIR.MR3INT Mask              */
#define LPC_CT32B0_BIR_MR3INT_SHIFT              (3U)                                                /*!< LPC_CT32B0_BIR.MR3INT Position          */
#define LPC_CT32B0_BIR_MR3INT(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_CT32B0_BIR.MR3INT Field             */
#define LPC_CT32B0_BIR_CR0INT_MASK               (0x10U)                                             /*!< LPC_CT32B0_BIR.CR0INT Mask              */
#define LPC_CT32B0_BIR_CR0INT_SHIFT              (4U)                                                /*!< LPC_CT32B0_BIR.CR0INT Position          */
#define LPC_CT32B0_BIR_CR0INT(x)                 (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_CT32B0_BIR.CR0INT Field             */
/* ------- BTCR Bit Fields                          ------ */
#define LPC_CT32B0_BTCR_CEN_MASK                 (0x1U)                                              /*!< LPC_CT32B0_BTCR.CEN Mask                */
#define LPC_CT32B0_BTCR_CEN_SHIFT                (0U)                                                /*!< LPC_CT32B0_BTCR.CEN Position            */
#define LPC_CT32B0_BTCR_CEN(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT32B0_BTCR.CEN Field               */
#define LPC_CT32B0_BTCR_CRES_MASK                (0x2U)                                              /*!< LPC_CT32B0_BTCR.CRES Mask               */
#define LPC_CT32B0_BTCR_CRES_SHIFT               (1U)                                                /*!< LPC_CT32B0_BTCR.CRES Position           */
#define LPC_CT32B0_BTCR_CRES(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT32B0_BTCR.CRES Field              */
/* ------- BTC Bit Fields                           ------ */
#define LPC_CT32B0_BTC_TC_MASK                   (0xFFFFFFFFU)                                       /*!< LPC_CT32B0_BTC.TC Mask                  */
#define LPC_CT32B0_BTC_TC_SHIFT                  (0U)                                                /*!< LPC_CT32B0_BTC.TC Position              */
#define LPC_CT32B0_BTC_TC(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_CT32B0_BTC.TC Field                 */
/* ------- BPR Bit Fields                           ------ */
#define LPC_CT32B0_BPR_PR_MASK                   (0xFFFFFFFFU)                                       /*!< LPC_CT32B0_BPR.PR Mask                  */
#define LPC_CT32B0_BPR_PR_SHIFT                  (0U)                                                /*!< LPC_CT32B0_BPR.PR Position              */
#define LPC_CT32B0_BPR_PR(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_CT32B0_BPR.PR Field                 */
/* ------- BPC Bit Fields                           ------ */
#define LPC_CT32B0_BPC_PC_MASK                   (0xFFFFFFFFU)                                       /*!< LPC_CT32B0_BPC.PC Mask                  */
#define LPC_CT32B0_BPC_PC_SHIFT                  (0U)                                                /*!< LPC_CT32B0_BPC.PC Position              */
#define LPC_CT32B0_BPC_PC(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_CT32B0_BPC.PC Field                 */
/* ------- BMCR Bit Fields                          ------ */
#define LPC_CT32B0_BMCR_MR0I_MASK                (0x1U)                                              /*!< LPC_CT32B0_BMCR.MR0I Mask               */
#define LPC_CT32B0_BMCR_MR0I_SHIFT               (0U)                                                /*!< LPC_CT32B0_BMCR.MR0I Position           */
#define LPC_CT32B0_BMCR_MR0I(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT32B0_BMCR.MR0I Field              */
#define LPC_CT32B0_BMCR_MR0R_MASK                (0x2U)                                              /*!< LPC_CT32B0_BMCR.MR0R Mask               */
#define LPC_CT32B0_BMCR_MR0R_SHIFT               (1U)                                                /*!< LPC_CT32B0_BMCR.MR0R Position           */
#define LPC_CT32B0_BMCR_MR0R(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT32B0_BMCR.MR0R Field              */
#define LPC_CT32B0_BMCR_MR0S_MASK                (0x4U)                                              /*!< LPC_CT32B0_BMCR.MR0S Mask               */
#define LPC_CT32B0_BMCR_MR0S_SHIFT               (2U)                                                /*!< LPC_CT32B0_BMCR.MR0S Position           */
#define LPC_CT32B0_BMCR_MR0S(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT32B0_BMCR.MR0S Field              */
#define LPC_CT32B0_BMCR_MR1I_MASK                (0x8U)                                              /*!< LPC_CT32B0_BMCR.MR1I Mask               */
#define LPC_CT32B0_BMCR_MR1I_SHIFT               (3U)                                                /*!< LPC_CT32B0_BMCR.MR1I Position           */
#define LPC_CT32B0_BMCR_MR1I(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_CT32B0_BMCR.MR1I Field              */
#define LPC_CT32B0_BMCR_MR1R_MASK                (0x10U)                                             /*!< LPC_CT32B0_BMCR.MR1R Mask               */
#define LPC_CT32B0_BMCR_MR1R_SHIFT               (4U)                                                /*!< LPC_CT32B0_BMCR.MR1R Position           */
#define LPC_CT32B0_BMCR_MR1R(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_CT32B0_BMCR.MR1R Field              */
#define LPC_CT32B0_BMCR_MR1S_MASK                (0x20U)                                             /*!< LPC_CT32B0_BMCR.MR1S Mask               */
#define LPC_CT32B0_BMCR_MR1S_SHIFT               (5U)                                                /*!< LPC_CT32B0_BMCR.MR1S Position           */
#define LPC_CT32B0_BMCR_MR1S(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_CT32B0_BMCR.MR1S Field              */
#define LPC_CT32B0_BMCR_MR2I_MASK                (0x40U)                                             /*!< LPC_CT32B0_BMCR.MR2I Mask               */
#define LPC_CT32B0_BMCR_MR2I_SHIFT               (6U)                                                /*!< LPC_CT32B0_BMCR.MR2I Position           */
#define LPC_CT32B0_BMCR_MR2I(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_CT32B0_BMCR.MR2I Field              */
#define LPC_CT32B0_BMCR_MR2R_MASK                (0x80U)                                             /*!< LPC_CT32B0_BMCR.MR2R Mask               */
#define LPC_CT32B0_BMCR_MR2R_SHIFT               (7U)                                                /*!< LPC_CT32B0_BMCR.MR2R Position           */
#define LPC_CT32B0_BMCR_MR2R(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_CT32B0_BMCR.MR2R Field              */
#define LPC_CT32B0_BMCR_MR2S_MASK                (0x100U)                                            /*!< LPC_CT32B0_BMCR.MR2S Mask               */
#define LPC_CT32B0_BMCR_MR2S_SHIFT               (8U)                                                /*!< LPC_CT32B0_BMCR.MR2S Position           */
#define LPC_CT32B0_BMCR_MR2S(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_CT32B0_BMCR.MR2S Field              */
#define LPC_CT32B0_BMCR_MR3I_MASK                (0x200U)                                            /*!< LPC_CT32B0_BMCR.MR3I Mask               */
#define LPC_CT32B0_BMCR_MR3I_SHIFT               (9U)                                                /*!< LPC_CT32B0_BMCR.MR3I Position           */
#define LPC_CT32B0_BMCR_MR3I(x)                  (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_CT32B0_BMCR.MR3I Field              */
#define LPC_CT32B0_BMCR_MR3R_MASK                (0x400U)                                            /*!< LPC_CT32B0_BMCR.MR3R Mask               */
#define LPC_CT32B0_BMCR_MR3R_SHIFT               (10U)                                               /*!< LPC_CT32B0_BMCR.MR3R Position           */
#define LPC_CT32B0_BMCR_MR3R(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_CT32B0_BMCR.MR3R Field              */
#define LPC_CT32B0_BMCR_MR3S_MASK                (0x800U)                                            /*!< LPC_CT32B0_BMCR.MR3S Mask               */
#define LPC_CT32B0_BMCR_MR3S_SHIFT               (11U)                                               /*!< LPC_CT32B0_BMCR.MR3S Position           */
#define LPC_CT32B0_BMCR_MR3S(x)                  (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_CT32B0_BMCR.MR3S Field              */
/* ------- BMR0 Bit Fields                          ------ */
#define LPC_CT32B0_BMR0_MATCH_MASK               (0xFFFFFFFFU)                                       /*!< LPC_CT32B0_BMR0.MATCH Mask              */
#define LPC_CT32B0_BMR0_MATCH_SHIFT              (0U)                                                /*!< LPC_CT32B0_BMR0.MATCH Position          */
#define LPC_CT32B0_BMR0_MATCH(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_CT32B0_BMR0.MATCH Field             */
/* ------- BMR Bit Fields                           ------ */
#define LPC_CT32B0_BMR_MATCH_MASK                (0xFFFFFFFFU)                                       /*!< LPC_CT32B0_BMR.MATCH Mask               */
#define LPC_CT32B0_BMR_MATCH_SHIFT               (0U)                                                /*!< LPC_CT32B0_BMR.MATCH Position           */
#define LPC_CT32B0_BMR_MATCH(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_CT32B0_BMR.MATCH Field              */
/* ------- BCCR Bit Fields                          ------ */
#define LPC_CT32B0_BCCR_CAP0RE_MASK              (0x1U)                                              /*!< LPC_CT32B0_BCCR.CAP0RE Mask             */
#define LPC_CT32B0_BCCR_CAP0RE_SHIFT             (0U)                                                /*!< LPC_CT32B0_BCCR.CAP0RE Position         */
#define LPC_CT32B0_BCCR_CAP0RE(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT32B0_BCCR.CAP0RE Field            */
#define LPC_CT32B0_BCCR_CAP0FE_MASK              (0x2U)                                              /*!< LPC_CT32B0_BCCR.CAP0FE Mask             */
#define LPC_CT32B0_BCCR_CAP0FE_SHIFT             (1U)                                                /*!< LPC_CT32B0_BCCR.CAP0FE Position         */
#define LPC_CT32B0_BCCR_CAP0FE(x)                (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT32B0_BCCR.CAP0FE Field            */
#define LPC_CT32B0_BCCR_CAP0I_MASK               (0x4U)                                              /*!< LPC_CT32B0_BCCR.CAP0I Mask              */
#define LPC_CT32B0_BCCR_CAP0I_SHIFT              (2U)                                                /*!< LPC_CT32B0_BCCR.CAP0I Position          */
#define LPC_CT32B0_BCCR_CAP0I(x)                 (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT32B0_BCCR.CAP0I Field             */
/* ------- BCR0 Bit Fields                          ------ */
#define LPC_CT32B0_BCR0_CAP_MASK                 (0xFFFFFFFFU)                                       /*!< LPC_CT32B0_BCR0.CAP Mask                */
#define LPC_CT32B0_BCR0_CAP_SHIFT                (0U)                                                /*!< LPC_CT32B0_BCR0.CAP Position            */
#define LPC_CT32B0_BCR0_CAP(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_CT32B0_BCR0.CAP Field               */
/* ------- BEMR Bit Fields                          ------ */
#define LPC_CT32B0_BEMR_EM0_MASK                 (0x1U)                                              /*!< LPC_CT32B0_BEMR.EM0 Mask                */
#define LPC_CT32B0_BEMR_EM0_SHIFT                (0U)                                                /*!< LPC_CT32B0_BEMR.EM0 Position            */
#define LPC_CT32B0_BEMR_EM0(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT32B0_BEMR.EM0 Field               */
#define LPC_CT32B0_BEMR_EM1_MASK                 (0x2U)                                              /*!< LPC_CT32B0_BEMR.EM1 Mask                */
#define LPC_CT32B0_BEMR_EM1_SHIFT                (1U)                                                /*!< LPC_CT32B0_BEMR.EM1 Position            */
#define LPC_CT32B0_BEMR_EM1(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT32B0_BEMR.EM1 Field               */
#define LPC_CT32B0_BEMR_EM2_MASK                 (0x4U)                                              /*!< LPC_CT32B0_BEMR.EM2 Mask                */
#define LPC_CT32B0_BEMR_EM2_SHIFT                (2U)                                                /*!< LPC_CT32B0_BEMR.EM2 Position            */
#define LPC_CT32B0_BEMR_EM2(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT32B0_BEMR.EM2 Field               */
#define LPC_CT32B0_BEMR_EM3_MASK                 (0x8U)                                              /*!< LPC_CT32B0_BEMR.EM3 Mask                */
#define LPC_CT32B0_BEMR_EM3_SHIFT                (3U)                                                /*!< LPC_CT32B0_BEMR.EM3 Position            */
#define LPC_CT32B0_BEMR_EM3(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_CT32B0_BEMR.EM3 Field               */
#define LPC_CT32B0_BEMR_EMC0_MASK                (0x30U)                                             /*!< LPC_CT32B0_BEMR.EMC0 Mask               */
#define LPC_CT32B0_BEMR_EMC0_SHIFT               (4U)                                                /*!< LPC_CT32B0_BEMR.EMC0 Position           */
#define LPC_CT32B0_BEMR_EMC0(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< LPC_CT32B0_BEMR.EMC0 Field              */
#define LPC_CT32B0_BEMR_EMC1_MASK                (0xC0U)                                             /*!< LPC_CT32B0_BEMR.EMC1 Mask               */
#define LPC_CT32B0_BEMR_EMC1_SHIFT               (6U)                                                /*!< LPC_CT32B0_BEMR.EMC1 Position           */
#define LPC_CT32B0_BEMR_EMC1(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< LPC_CT32B0_BEMR.EMC1 Field              */
#define LPC_CT32B0_BEMR_EMC2_MASK                (0x300U)                                            /*!< LPC_CT32B0_BEMR.EMC2 Mask               */
#define LPC_CT32B0_BEMR_EMC2_SHIFT               (8U)                                                /*!< LPC_CT32B0_BEMR.EMC2 Position           */
#define LPC_CT32B0_BEMR_EMC2(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< LPC_CT32B0_BEMR.EMC2 Field              */
#define LPC_CT32B0_BEMR_EMC3_MASK                (0xC00U)                                            /*!< LPC_CT32B0_BEMR.EMC3 Mask               */
#define LPC_CT32B0_BEMR_EMC3_SHIFT               (10U)                                               /*!< LPC_CT32B0_BEMR.EMC3 Position           */
#define LPC_CT32B0_BEMR_EMC3(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0xC00UL)        /*!< LPC_CT32B0_BEMR.EMC3 Field              */
/* ------- BCTCR Bit Fields                         ------ */
#define LPC_CT32B0_BCTCR_CTM_MASK                (0x3U)                                              /*!< LPC_CT32B0_BCTCR.CTM Mask               */
#define LPC_CT32B0_BCTCR_CTM_SHIFT               (0U)                                                /*!< LPC_CT32B0_BCTCR.CTM Position           */
#define LPC_CT32B0_BCTCR_CTM(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_CT32B0_BCTCR.CTM Field              */
#define LPC_CT32B0_BCTCR_CIS_MASK                (0xCU)                                              /*!< LPC_CT32B0_BCTCR.CIS Mask               */
#define LPC_CT32B0_BCTCR_CIS_SHIFT               (2U)                                                /*!< LPC_CT32B0_BCTCR.CIS Position           */
#define LPC_CT32B0_BCTCR_CIS(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< LPC_CT32B0_BCTCR.CIS Field              */
/* ------- BPWMC Bit Fields                         ------ */
#define LPC_CT32B0_BPWMC_PWMEN0_MASK             (0x1U)                                              /*!< LPC_CT32B0_BPWMC.PWMEN0 Mask            */
#define LPC_CT32B0_BPWMC_PWMEN0_SHIFT            (0U)                                                /*!< LPC_CT32B0_BPWMC.PWMEN0 Position        */
#define LPC_CT32B0_BPWMC_PWMEN0(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_CT32B0_BPWMC.PWMEN0 Field           */
#define LPC_CT32B0_BPWMC_PWMEN1_MASK             (0x2U)                                              /*!< LPC_CT32B0_BPWMC.PWMEN1 Mask            */
#define LPC_CT32B0_BPWMC_PWMEN1_SHIFT            (1U)                                                /*!< LPC_CT32B0_BPWMC.PWMEN1 Position        */
#define LPC_CT32B0_BPWMC_PWMEN1(x)               (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_CT32B0_BPWMC.PWMEN1 Field           */
#define LPC_CT32B0_BPWMC_PWMEN2_MASK             (0x4U)                                              /*!< LPC_CT32B0_BPWMC.PWMEN2 Mask            */
#define LPC_CT32B0_BPWMC_PWMEN2_SHIFT            (2U)                                                /*!< LPC_CT32B0_BPWMC.PWMEN2 Position        */
#define LPC_CT32B0_BPWMC_PWMEN2(x)               (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_CT32B0_BPWMC.PWMEN2 Field           */
#define LPC_CT32B0_BPWMC_PWMEN3_MASK             (0x8U)                                              /*!< LPC_CT32B0_BPWMC.PWMEN3 Mask            */
#define LPC_CT32B0_BPWMC_PWMEN3_SHIFT            (3U)                                                /*!< LPC_CT32B0_BPWMC.PWMEN3 Position        */
#define LPC_CT32B0_BPWMC_PWMEN3(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_CT32B0_BPWMC.PWMEN3 Field           */
/**
 * @} */ /* End group CT32B0_Register_Masks_GROUP 
 */

/* LPC_CT32B0 - Peripheral instance base addresses */
#define LPC_CT32B0_BasePtr             0x40014000UL //!< Peripheral base address
#define LPC_CT32B0                     ((LPC_CT32B0_Type *) LPC_CT32B0_BasePtr) //!< Freescale base pointer
#define LPC_CT32B0_BASE_PTR            (LPC_CT32B0) //!< Freescale style base pointer
#define LPC_CT32B0_IRQS { CT32B0_IRQn,  }

/**
 * @} */ /* End group CT32B0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CT32B0_Peripheral_access_layer_GROUP CT32B0 Peripheral Access Layer
* @brief C Struct for CT32B0
* @{
*/

/* ================================================================================ */
/* ================           LPC_CT32B1 (derived from CT32B0)       ================ */
/* ================================================================================ */

/**
 * @brief 32-bit timer/counters (CT32B0/1)
 */

/* LPC_CT32B1 - Peripheral instance base addresses */
#define LPC_CT32B1_BasePtr             0x40018000UL //!< Peripheral base address
#define LPC_CT32B1                     ((LPC_CT32B0_Type *) LPC_CT32B1_BasePtr) //!< Freescale base pointer
#define LPC_CT32B1_BASE_PTR            (LPC_CT32B1) //!< Freescale style base pointer
#define LPC_CT32B1_IRQS { CT32B1_IRQn,  }

/**
 * @} */ /* End group CT32B0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FMC_Peripheral_access_layer_GROUP FMC Peripheral Access Layer
* @brief C Struct for FMC
* @{
*/

/* ================================================================================ */
/* ================           LPC_FMC (file:FMC_LPC13xx)           ================ */
/* ================================================================================ */

/**
 * @brief Flash memory 				programming firmware
 */
/**
* @addtogroup FMC_structs_GROUP FMC struct
* @brief Struct for FMC
* @{
*/
typedef struct LPC_FMC_Type {
        uint8_t   RESERVED_0[16];              
   __IO uint32_t  FLASHCFG;                     /**< 0010: Flash configuration register                                 */
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
} LPC_FMC_Type;

/**
 * @} */ /* End group FMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_FMC' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FMC_Register_Masks_GROUP FMC Register Masks
* @brief Register Masks for FMC
* @{
*/
/* ------- FLASHCFG Bit Fields                      ------ */
#define LPC_FMC_FLASHCFG_FLASHTIM_MASK           (0x3U)                                              /*!< LPC_FMC_FLASHCFG.FLASHTIM Mask          */
#define LPC_FMC_FLASHCFG_FLASHTIM_SHIFT          (0U)                                                /*!< LPC_FMC_FLASHCFG.FLASHTIM Position      */
#define LPC_FMC_FLASHCFG_FLASHTIM(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_FMC_FLASHCFG.FLASHTIM Field         */
/* ------- FMSSTART Bit Fields                      ------ */
#define LPC_FMC_FMSSTART_START_MASK              (0x1FFFFU)                                          /*!< LPC_FMC_FMSSTART.START Mask             */
#define LPC_FMC_FMSSTART_START_SHIFT             (0U)                                                /*!< LPC_FMC_FMSSTART.START Position         */
#define LPC_FMC_FMSSTART_START(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFFUL)       /*!< LPC_FMC_FMSSTART.START Field            */
/* ------- FMSSTOP Bit Fields                       ------ */
#define LPC_FMC_FMSSTOP_STOP_MASK                (0x1FFFFU)                                          /*!< LPC_FMC_FMSSTOP.STOP Mask               */
#define LPC_FMC_FMSSTOP_STOP_SHIFT               (0U)                                                /*!< LPC_FMC_FMSSTOP.STOP Position           */
#define LPC_FMC_FMSSTOP_STOP(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFFUL)       /*!< LPC_FMC_FMSSTOP.STOP Field              */
#define LPC_FMC_FMSSTOP_SIG_START_MASK           (0x20000U)                                          /*!< LPC_FMC_FMSSTOP.SIG_START Mask          */
#define LPC_FMC_FMSSTOP_SIG_START_SHIFT          (17U)                                               /*!< LPC_FMC_FMSSTOP.SIG_START Position      */
#define LPC_FMC_FMSSTOP_SIG_START(x)             (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPC_FMC_FMSSTOP.SIG_START Field         */
/* ------- FMSW0 Bit Fields                         ------ */
#define LPC_FMC_FMSW0_SW0_31_0_MASK              (0xFFFFFFFFU)                                       /*!< LPC_FMC_FMSW0.SW0_31_0 Mask             */
#define LPC_FMC_FMSW0_SW0_31_0_SHIFT             (0U)                                                /*!< LPC_FMC_FMSW0.SW0_31_0 Position         */
#define LPC_FMC_FMSW0_SW0_31_0(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_FMC_FMSW0.SW0_31_0 Field            */
/* ------- FMSW1 Bit Fields                         ------ */
#define LPC_FMC_FMSW1_SW1_63_32_MASK             (0xFFFFFFFFU)                                       /*!< LPC_FMC_FMSW1.SW1_63_32 Mask            */
#define LPC_FMC_FMSW1_SW1_63_32_SHIFT            (0U)                                                /*!< LPC_FMC_FMSW1.SW1_63_32 Position        */
#define LPC_FMC_FMSW1_SW1_63_32(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_FMC_FMSW1.SW1_63_32 Field           */
/* ------- FMSW2 Bit Fields                         ------ */
#define LPC_FMC_FMSW2_SW2_95_64_MASK             (0xFFFFFFFFU)                                       /*!< LPC_FMC_FMSW2.SW2_95_64 Mask            */
#define LPC_FMC_FMSW2_SW2_95_64_SHIFT            (0U)                                                /*!< LPC_FMC_FMSW2.SW2_95_64 Position        */
#define LPC_FMC_FMSW2_SW2_95_64(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_FMC_FMSW2.SW2_95_64 Field           */
/* ------- FMSW3 Bit Fields                         ------ */
#define LPC_FMC_FMSW3_SW3_127_96_MASK            (0xFFFFFFFFU)                                       /*!< LPC_FMC_FMSW3.SW3_127_96 Mask           */
#define LPC_FMC_FMSW3_SW3_127_96_SHIFT           (0U)                                                /*!< LPC_FMC_FMSW3.SW3_127_96 Position       */
#define LPC_FMC_FMSW3_SW3_127_96(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_FMC_FMSW3.SW3_127_96 Field          */
/* ------- FMSTAT Bit Fields                        ------ */
#define LPC_FMC_FMSTAT_SIG_DONE_MASK             (0x4U)                                              /*!< LPC_FMC_FMSTAT.SIG_DONE Mask            */
#define LPC_FMC_FMSTAT_SIG_DONE_SHIFT            (2U)                                                /*!< LPC_FMC_FMSTAT.SIG_DONE Position        */
#define LPC_FMC_FMSTAT_SIG_DONE(x)               (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_FMC_FMSTAT.SIG_DONE Field           */
/* ------- FMSTATCLR Bit Fields                     ------ */
#define LPC_FMC_FMSTATCLR_SIG_DONE_CLR_MASK      (0x4U)                                              /*!< LPC_FMC_FMSTATCLR.SIG_DONE_CLR Mask     */
#define LPC_FMC_FMSTATCLR_SIG_DONE_CLR_SHIFT     (2U)                                                /*!< LPC_FMC_FMSTATCLR.SIG_DONE_CLR Position */
#define LPC_FMC_FMSTATCLR_SIG_DONE_CLR(x)        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_FMC_FMSTATCLR.SIG_DONE_CLR Field    */
/**
 * @} */ /* End group FMC_Register_Masks_GROUP 
 */

/* LPC_FMC - Peripheral instance base addresses */
#define LPC_FMC_BasePtr                0x4003C000UL //!< Peripheral base address
#define LPC_FMC                        ((LPC_FMC_Type *) LPC_FMC_BasePtr) //!< Freescale base pointer
#define LPC_FMC_BASE_PTR               (LPC_FMC) //!< Freescale style base pointer
/**
 * @} */ /* End group FMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           LPC_GPIO0 (file:GPIO0_LPC13xx)       ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O
 */
/**
* @addtogroup GPIO_structs_GROUP GPIO struct
* @brief Struct for GPIO
* @{
*/
typedef struct LPC_GPIO0_Type {
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
} LPC_GPIO0_Type;

/**
 * @} */ /* End group GPIO_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_GPIO0' Position & Mask macros                   ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_Register_Masks_GROUP GPIO Register Masks
* @brief Register Masks for GPIO
* @{
*/
/* ------- DATA Bit Fields                          ------ */
#define LPC_GPIO0_DATA_DATA0_MASK                (0x1U)                                              /*!< LPC_GPIO0_DATA.DATA0 Mask               */
#define LPC_GPIO0_DATA_DATA0_SHIFT               (0U)                                                /*!< LPC_GPIO0_DATA.DATA0 Position           */
#define LPC_GPIO0_DATA_DATA0(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_DATA.DATA0 Field              */
#define LPC_GPIO0_DATA_DATA1_MASK                (0x2U)                                              /*!< LPC_GPIO0_DATA.DATA1 Mask               */
#define LPC_GPIO0_DATA_DATA1_SHIFT               (1U)                                                /*!< LPC_GPIO0_DATA.DATA1 Position           */
#define LPC_GPIO0_DATA_DATA1(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_DATA.DATA1 Field              */
#define LPC_GPIO0_DATA_DATA2_MASK                (0x4U)                                              /*!< LPC_GPIO0_DATA.DATA2 Mask               */
#define LPC_GPIO0_DATA_DATA2_SHIFT               (2U)                                                /*!< LPC_GPIO0_DATA.DATA2 Position           */
#define LPC_GPIO0_DATA_DATA2(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_DATA.DATA2 Field              */
#define LPC_GPIO0_DATA_DATA3_MASK                (0x8U)                                              /*!< LPC_GPIO0_DATA.DATA3 Mask               */
#define LPC_GPIO0_DATA_DATA3_SHIFT               (3U)                                                /*!< LPC_GPIO0_DATA.DATA3 Position           */
#define LPC_GPIO0_DATA_DATA3(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_DATA.DATA3 Field              */
#define LPC_GPIO0_DATA_DATA4_MASK                (0x10U)                                             /*!< LPC_GPIO0_DATA.DATA4 Mask               */
#define LPC_GPIO0_DATA_DATA4_SHIFT               (4U)                                                /*!< LPC_GPIO0_DATA.DATA4 Position           */
#define LPC_GPIO0_DATA_DATA4(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_DATA.DATA4 Field              */
#define LPC_GPIO0_DATA_DATA5_MASK                (0x20U)                                             /*!< LPC_GPIO0_DATA.DATA5 Mask               */
#define LPC_GPIO0_DATA_DATA5_SHIFT               (5U)                                                /*!< LPC_GPIO0_DATA.DATA5 Position           */
#define LPC_GPIO0_DATA_DATA5(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_DATA.DATA5 Field              */
#define LPC_GPIO0_DATA_DATA6_MASK                (0x40U)                                             /*!< LPC_GPIO0_DATA.DATA6 Mask               */
#define LPC_GPIO0_DATA_DATA6_SHIFT               (6U)                                                /*!< LPC_GPIO0_DATA.DATA6 Position           */
#define LPC_GPIO0_DATA_DATA6(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_DATA.DATA6 Field              */
#define LPC_GPIO0_DATA_DATA7_MASK                (0x80U)                                             /*!< LPC_GPIO0_DATA.DATA7 Mask               */
#define LPC_GPIO0_DATA_DATA7_SHIFT               (7U)                                                /*!< LPC_GPIO0_DATA.DATA7 Position           */
#define LPC_GPIO0_DATA_DATA7(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_DATA.DATA7 Field              */
#define LPC_GPIO0_DATA_DATA8_MASK                (0x100U)                                            /*!< LPC_GPIO0_DATA.DATA8 Mask               */
#define LPC_GPIO0_DATA_DATA8_SHIFT               (8U)                                                /*!< LPC_GPIO0_DATA.DATA8 Position           */
#define LPC_GPIO0_DATA_DATA8(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_DATA.DATA8 Field              */
#define LPC_GPIO0_DATA_DATA9_MASK                (0x200U)                                            /*!< LPC_GPIO0_DATA.DATA9 Mask               */
#define LPC_GPIO0_DATA_DATA9_SHIFT               (9U)                                                /*!< LPC_GPIO0_DATA.DATA9 Position           */
#define LPC_GPIO0_DATA_DATA9(x)                  (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_DATA.DATA9 Field              */
#define LPC_GPIO0_DATA_DATA10_MASK               (0x400U)                                            /*!< LPC_GPIO0_DATA.DATA10 Mask              */
#define LPC_GPIO0_DATA_DATA10_SHIFT              (10U)                                               /*!< LPC_GPIO0_DATA.DATA10 Position          */
#define LPC_GPIO0_DATA_DATA10(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_DATA.DATA10 Field             */
#define LPC_GPIO0_DATA_DATA11_MASK               (0x800U)                                            /*!< LPC_GPIO0_DATA.DATA11 Mask              */
#define LPC_GPIO0_DATA_DATA11_SHIFT              (11U)                                               /*!< LPC_GPIO0_DATA.DATA11 Position          */
#define LPC_GPIO0_DATA_DATA11(x)                 (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_DATA.DATA11 Field             */
/* ------- DIR Bit Fields                           ------ */
#define LPC_GPIO0_DIR_IO0_MASK                   (0x1U)                                              /*!< LPC_GPIO0_DIR.IO0 Mask                  */
#define LPC_GPIO0_DIR_IO0_SHIFT                  (0U)                                                /*!< LPC_GPIO0_DIR.IO0 Position              */
#define LPC_GPIO0_DIR_IO0(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_DIR.IO0 Field                 */
#define LPC_GPIO0_DIR_IO1_MASK                   (0x2U)                                              /*!< LPC_GPIO0_DIR.IO1 Mask                  */
#define LPC_GPIO0_DIR_IO1_SHIFT                  (1U)                                                /*!< LPC_GPIO0_DIR.IO1 Position              */
#define LPC_GPIO0_DIR_IO1(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_DIR.IO1 Field                 */
#define LPC_GPIO0_DIR_IO2_MASK                   (0x4U)                                              /*!< LPC_GPIO0_DIR.IO2 Mask                  */
#define LPC_GPIO0_DIR_IO2_SHIFT                  (2U)                                                /*!< LPC_GPIO0_DIR.IO2 Position              */
#define LPC_GPIO0_DIR_IO2(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_DIR.IO2 Field                 */
#define LPC_GPIO0_DIR_IO3_MASK                   (0x8U)                                              /*!< LPC_GPIO0_DIR.IO3 Mask                  */
#define LPC_GPIO0_DIR_IO3_SHIFT                  (3U)                                                /*!< LPC_GPIO0_DIR.IO3 Position              */
#define LPC_GPIO0_DIR_IO3(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_DIR.IO3 Field                 */
#define LPC_GPIO0_DIR_IO4_MASK                   (0x10U)                                             /*!< LPC_GPIO0_DIR.IO4 Mask                  */
#define LPC_GPIO0_DIR_IO4_SHIFT                  (4U)                                                /*!< LPC_GPIO0_DIR.IO4 Position              */
#define LPC_GPIO0_DIR_IO4(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_DIR.IO4 Field                 */
#define LPC_GPIO0_DIR_IO5_MASK                   (0x20U)                                             /*!< LPC_GPIO0_DIR.IO5 Mask                  */
#define LPC_GPIO0_DIR_IO5_SHIFT                  (5U)                                                /*!< LPC_GPIO0_DIR.IO5 Position              */
#define LPC_GPIO0_DIR_IO5(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_DIR.IO5 Field                 */
#define LPC_GPIO0_DIR_IO6_MASK                   (0x40U)                                             /*!< LPC_GPIO0_DIR.IO6 Mask                  */
#define LPC_GPIO0_DIR_IO6_SHIFT                  (6U)                                                /*!< LPC_GPIO0_DIR.IO6 Position              */
#define LPC_GPIO0_DIR_IO6(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_DIR.IO6 Field                 */
#define LPC_GPIO0_DIR_IO7_MASK                   (0x80U)                                             /*!< LPC_GPIO0_DIR.IO7 Mask                  */
#define LPC_GPIO0_DIR_IO7_SHIFT                  (7U)                                                /*!< LPC_GPIO0_DIR.IO7 Position              */
#define LPC_GPIO0_DIR_IO7(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_DIR.IO7 Field                 */
#define LPC_GPIO0_DIR_IO8_MASK                   (0x100U)                                            /*!< LPC_GPIO0_DIR.IO8 Mask                  */
#define LPC_GPIO0_DIR_IO8_SHIFT                  (8U)                                                /*!< LPC_GPIO0_DIR.IO8 Position              */
#define LPC_GPIO0_DIR_IO8(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_DIR.IO8 Field                 */
#define LPC_GPIO0_DIR_IO9_MASK                   (0x200U)                                            /*!< LPC_GPIO0_DIR.IO9 Mask                  */
#define LPC_GPIO0_DIR_IO9_SHIFT                  (9U)                                                /*!< LPC_GPIO0_DIR.IO9 Position              */
#define LPC_GPIO0_DIR_IO9(x)                     (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_DIR.IO9 Field                 */
#define LPC_GPIO0_DIR_IO10_MASK                  (0x400U)                                            /*!< LPC_GPIO0_DIR.IO10 Mask                 */
#define LPC_GPIO0_DIR_IO10_SHIFT                 (10U)                                               /*!< LPC_GPIO0_DIR.IO10 Position             */
#define LPC_GPIO0_DIR_IO10(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_DIR.IO10 Field                */
#define LPC_GPIO0_DIR_IO11_MASK                  (0x800U)                                            /*!< LPC_GPIO0_DIR.IO11 Mask                 */
#define LPC_GPIO0_DIR_IO11_SHIFT                 (11U)                                               /*!< LPC_GPIO0_DIR.IO11 Position             */
#define LPC_GPIO0_DIR_IO11(x)                    (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_DIR.IO11 Field                */
/* ------- IS Bit Fields                            ------ */
#define LPC_GPIO0_IS_ISENSE0_MASK                (0x1U)                                              /*!< LPC_GPIO0_IS.ISENSE0 Mask               */
#define LPC_GPIO0_IS_ISENSE0_SHIFT               (0U)                                                /*!< LPC_GPIO0_IS.ISENSE0 Position           */
#define LPC_GPIO0_IS_ISENSE0(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_IS.ISENSE0 Field              */
#define LPC_GPIO0_IS_ISENSE1_MASK                (0x2U)                                              /*!< LPC_GPIO0_IS.ISENSE1 Mask               */
#define LPC_GPIO0_IS_ISENSE1_SHIFT               (1U)                                                /*!< LPC_GPIO0_IS.ISENSE1 Position           */
#define LPC_GPIO0_IS_ISENSE1(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_IS.ISENSE1 Field              */
#define LPC_GPIO0_IS_ISENSE2_MASK                (0x4U)                                              /*!< LPC_GPIO0_IS.ISENSE2 Mask               */
#define LPC_GPIO0_IS_ISENSE2_SHIFT               (2U)                                                /*!< LPC_GPIO0_IS.ISENSE2 Position           */
#define LPC_GPIO0_IS_ISENSE2(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_IS.ISENSE2 Field              */
#define LPC_GPIO0_IS_ISENSE3_MASK                (0x8U)                                              /*!< LPC_GPIO0_IS.ISENSE3 Mask               */
#define LPC_GPIO0_IS_ISENSE3_SHIFT               (3U)                                                /*!< LPC_GPIO0_IS.ISENSE3 Position           */
#define LPC_GPIO0_IS_ISENSE3(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_IS.ISENSE3 Field              */
#define LPC_GPIO0_IS_ISENSE4_MASK                (0x10U)                                             /*!< LPC_GPIO0_IS.ISENSE4 Mask               */
#define LPC_GPIO0_IS_ISENSE4_SHIFT               (4U)                                                /*!< LPC_GPIO0_IS.ISENSE4 Position           */
#define LPC_GPIO0_IS_ISENSE4(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_IS.ISENSE4 Field              */
#define LPC_GPIO0_IS_ISENSE5_MASK                (0x20U)                                             /*!< LPC_GPIO0_IS.ISENSE5 Mask               */
#define LPC_GPIO0_IS_ISENSE5_SHIFT               (5U)                                                /*!< LPC_GPIO0_IS.ISENSE5 Position           */
#define LPC_GPIO0_IS_ISENSE5(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_IS.ISENSE5 Field              */
#define LPC_GPIO0_IS_ISENSE6_MASK                (0x40U)                                             /*!< LPC_GPIO0_IS.ISENSE6 Mask               */
#define LPC_GPIO0_IS_ISENSE6_SHIFT               (6U)                                                /*!< LPC_GPIO0_IS.ISENSE6 Position           */
#define LPC_GPIO0_IS_ISENSE6(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_IS.ISENSE6 Field              */
#define LPC_GPIO0_IS_ISENSE7_MASK                (0x80U)                                             /*!< LPC_GPIO0_IS.ISENSE7 Mask               */
#define LPC_GPIO0_IS_ISENSE7_SHIFT               (7U)                                                /*!< LPC_GPIO0_IS.ISENSE7 Position           */
#define LPC_GPIO0_IS_ISENSE7(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_IS.ISENSE7 Field              */
#define LPC_GPIO0_IS_ISENSE8_MASK                (0x100U)                                            /*!< LPC_GPIO0_IS.ISENSE8 Mask               */
#define LPC_GPIO0_IS_ISENSE8_SHIFT               (8U)                                                /*!< LPC_GPIO0_IS.ISENSE8 Position           */
#define LPC_GPIO0_IS_ISENSE8(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_IS.ISENSE8 Field              */
#define LPC_GPIO0_IS_ISENSE9_MASK                (0x200U)                                            /*!< LPC_GPIO0_IS.ISENSE9 Mask               */
#define LPC_GPIO0_IS_ISENSE9_SHIFT               (9U)                                                /*!< LPC_GPIO0_IS.ISENSE9 Position           */
#define LPC_GPIO0_IS_ISENSE9(x)                  (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_IS.ISENSE9 Field              */
#define LPC_GPIO0_IS_ISENSE10_MASK               (0x400U)                                            /*!< LPC_GPIO0_IS.ISENSE10 Mask              */
#define LPC_GPIO0_IS_ISENSE10_SHIFT              (10U)                                               /*!< LPC_GPIO0_IS.ISENSE10 Position          */
#define LPC_GPIO0_IS_ISENSE10(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_IS.ISENSE10 Field             */
#define LPC_GPIO0_IS_ISENSE11_MASK               (0x800U)                                            /*!< LPC_GPIO0_IS.ISENSE11 Mask              */
#define LPC_GPIO0_IS_ISENSE11_SHIFT              (11U)                                               /*!< LPC_GPIO0_IS.ISENSE11 Position          */
#define LPC_GPIO0_IS_ISENSE11(x)                 (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_IS.ISENSE11 Field             */
/* ------- IBE Bit Fields                           ------ */
#define LPC_GPIO0_IBE_IBE0_MASK                  (0x1U)                                              /*!< LPC_GPIO0_IBE.IBE0 Mask                 */
#define LPC_GPIO0_IBE_IBE0_SHIFT                 (0U)                                                /*!< LPC_GPIO0_IBE.IBE0 Position             */
#define LPC_GPIO0_IBE_IBE0(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_IBE.IBE0 Field                */
#define LPC_GPIO0_IBE_IBE1_MASK                  (0x2U)                                              /*!< LPC_GPIO0_IBE.IBE1 Mask                 */
#define LPC_GPIO0_IBE_IBE1_SHIFT                 (1U)                                                /*!< LPC_GPIO0_IBE.IBE1 Position             */
#define LPC_GPIO0_IBE_IBE1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_IBE.IBE1 Field                */
#define LPC_GPIO0_IBE_IBE2_MASK                  (0x4U)                                              /*!< LPC_GPIO0_IBE.IBE2 Mask                 */
#define LPC_GPIO0_IBE_IBE2_SHIFT                 (2U)                                                /*!< LPC_GPIO0_IBE.IBE2 Position             */
#define LPC_GPIO0_IBE_IBE2(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_IBE.IBE2 Field                */
#define LPC_GPIO0_IBE_IBE3_MASK                  (0x8U)                                              /*!< LPC_GPIO0_IBE.IBE3 Mask                 */
#define LPC_GPIO0_IBE_IBE3_SHIFT                 (3U)                                                /*!< LPC_GPIO0_IBE.IBE3 Position             */
#define LPC_GPIO0_IBE_IBE3(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_IBE.IBE3 Field                */
#define LPC_GPIO0_IBE_IBE4_MASK                  (0x10U)                                             /*!< LPC_GPIO0_IBE.IBE4 Mask                 */
#define LPC_GPIO0_IBE_IBE4_SHIFT                 (4U)                                                /*!< LPC_GPIO0_IBE.IBE4 Position             */
#define LPC_GPIO0_IBE_IBE4(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_IBE.IBE4 Field                */
#define LPC_GPIO0_IBE_IBE5_MASK                  (0x20U)                                             /*!< LPC_GPIO0_IBE.IBE5 Mask                 */
#define LPC_GPIO0_IBE_IBE5_SHIFT                 (5U)                                                /*!< LPC_GPIO0_IBE.IBE5 Position             */
#define LPC_GPIO0_IBE_IBE5(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_IBE.IBE5 Field                */
#define LPC_GPIO0_IBE_IBE6_MASK                  (0x40U)                                             /*!< LPC_GPIO0_IBE.IBE6 Mask                 */
#define LPC_GPIO0_IBE_IBE6_SHIFT                 (6U)                                                /*!< LPC_GPIO0_IBE.IBE6 Position             */
#define LPC_GPIO0_IBE_IBE6(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_IBE.IBE6 Field                */
#define LPC_GPIO0_IBE_IBE7_MASK                  (0x80U)                                             /*!< LPC_GPIO0_IBE.IBE7 Mask                 */
#define LPC_GPIO0_IBE_IBE7_SHIFT                 (7U)                                                /*!< LPC_GPIO0_IBE.IBE7 Position             */
#define LPC_GPIO0_IBE_IBE7(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_IBE.IBE7 Field                */
#define LPC_GPIO0_IBE_IBE8_MASK                  (0x100U)                                            /*!< LPC_GPIO0_IBE.IBE8 Mask                 */
#define LPC_GPIO0_IBE_IBE8_SHIFT                 (8U)                                                /*!< LPC_GPIO0_IBE.IBE8 Position             */
#define LPC_GPIO0_IBE_IBE8(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_IBE.IBE8 Field                */
#define LPC_GPIO0_IBE_IBE9_MASK                  (0x200U)                                            /*!< LPC_GPIO0_IBE.IBE9 Mask                 */
#define LPC_GPIO0_IBE_IBE9_SHIFT                 (9U)                                                /*!< LPC_GPIO0_IBE.IBE9 Position             */
#define LPC_GPIO0_IBE_IBE9(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_IBE.IBE9 Field                */
#define LPC_GPIO0_IBE_IBE10_MASK                 (0x400U)                                            /*!< LPC_GPIO0_IBE.IBE10 Mask                */
#define LPC_GPIO0_IBE_IBE10_SHIFT                (10U)                                               /*!< LPC_GPIO0_IBE.IBE10 Position            */
#define LPC_GPIO0_IBE_IBE10(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_IBE.IBE10 Field               */
#define LPC_GPIO0_IBE_IBE11_MASK                 (0x800U)                                            /*!< LPC_GPIO0_IBE.IBE11 Mask                */
#define LPC_GPIO0_IBE_IBE11_SHIFT                (11U)                                               /*!< LPC_GPIO0_IBE.IBE11 Position            */
#define LPC_GPIO0_IBE_IBE11(x)                   (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_IBE.IBE11 Field               */
/* ------- IEV Bit Fields                           ------ */
#define LPC_GPIO0_IEV_IEV0_MASK                  (0x1U)                                              /*!< LPC_GPIO0_IEV.IEV0 Mask                 */
#define LPC_GPIO0_IEV_IEV0_SHIFT                 (0U)                                                /*!< LPC_GPIO0_IEV.IEV0 Position             */
#define LPC_GPIO0_IEV_IEV0(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_IEV.IEV0 Field                */
#define LPC_GPIO0_IEV_IEV1_MASK                  (0x2U)                                              /*!< LPC_GPIO0_IEV.IEV1 Mask                 */
#define LPC_GPIO0_IEV_IEV1_SHIFT                 (1U)                                                /*!< LPC_GPIO0_IEV.IEV1 Position             */
#define LPC_GPIO0_IEV_IEV1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_IEV.IEV1 Field                */
#define LPC_GPIO0_IEV_IEV2_MASK                  (0x4U)                                              /*!< LPC_GPIO0_IEV.IEV2 Mask                 */
#define LPC_GPIO0_IEV_IEV2_SHIFT                 (2U)                                                /*!< LPC_GPIO0_IEV.IEV2 Position             */
#define LPC_GPIO0_IEV_IEV2(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_IEV.IEV2 Field                */
#define LPC_GPIO0_IEV_IEV3_MASK                  (0x8U)                                              /*!< LPC_GPIO0_IEV.IEV3 Mask                 */
#define LPC_GPIO0_IEV_IEV3_SHIFT                 (3U)                                                /*!< LPC_GPIO0_IEV.IEV3 Position             */
#define LPC_GPIO0_IEV_IEV3(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_IEV.IEV3 Field                */
#define LPC_GPIO0_IEV_IEV4_MASK                  (0x10U)                                             /*!< LPC_GPIO0_IEV.IEV4 Mask                 */
#define LPC_GPIO0_IEV_IEV4_SHIFT                 (4U)                                                /*!< LPC_GPIO0_IEV.IEV4 Position             */
#define LPC_GPIO0_IEV_IEV4(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_IEV.IEV4 Field                */
#define LPC_GPIO0_IEV_IEV5_MASK                  (0x20U)                                             /*!< LPC_GPIO0_IEV.IEV5 Mask                 */
#define LPC_GPIO0_IEV_IEV5_SHIFT                 (5U)                                                /*!< LPC_GPIO0_IEV.IEV5 Position             */
#define LPC_GPIO0_IEV_IEV5(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_IEV.IEV5 Field                */
#define LPC_GPIO0_IEV_IEV6_MASK                  (0x40U)                                             /*!< LPC_GPIO0_IEV.IEV6 Mask                 */
#define LPC_GPIO0_IEV_IEV6_SHIFT                 (6U)                                                /*!< LPC_GPIO0_IEV.IEV6 Position             */
#define LPC_GPIO0_IEV_IEV6(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_IEV.IEV6 Field                */
#define LPC_GPIO0_IEV_IEV7_MASK                  (0x80U)                                             /*!< LPC_GPIO0_IEV.IEV7 Mask                 */
#define LPC_GPIO0_IEV_IEV7_SHIFT                 (7U)                                                /*!< LPC_GPIO0_IEV.IEV7 Position             */
#define LPC_GPIO0_IEV_IEV7(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_IEV.IEV7 Field                */
#define LPC_GPIO0_IEV_IEV8_MASK                  (0x100U)                                            /*!< LPC_GPIO0_IEV.IEV8 Mask                 */
#define LPC_GPIO0_IEV_IEV8_SHIFT                 (8U)                                                /*!< LPC_GPIO0_IEV.IEV8 Position             */
#define LPC_GPIO0_IEV_IEV8(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_IEV.IEV8 Field                */
#define LPC_GPIO0_IEV_IEV9_MASK                  (0x200U)                                            /*!< LPC_GPIO0_IEV.IEV9 Mask                 */
#define LPC_GPIO0_IEV_IEV9_SHIFT                 (9U)                                                /*!< LPC_GPIO0_IEV.IEV9 Position             */
#define LPC_GPIO0_IEV_IEV9(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_IEV.IEV9 Field                */
#define LPC_GPIO0_IEV_IEV10_MASK                 (0x400U)                                            /*!< LPC_GPIO0_IEV.IEV10 Mask                */
#define LPC_GPIO0_IEV_IEV10_SHIFT                (10U)                                               /*!< LPC_GPIO0_IEV.IEV10 Position            */
#define LPC_GPIO0_IEV_IEV10(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_IEV.IEV10 Field               */
#define LPC_GPIO0_IEV_IEV11_MASK                 (0x800U)                                            /*!< LPC_GPIO0_IEV.IEV11 Mask                */
#define LPC_GPIO0_IEV_IEV11_SHIFT                (11U)                                               /*!< LPC_GPIO0_IEV.IEV11 Position            */
#define LPC_GPIO0_IEV_IEV11(x)                   (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_IEV.IEV11 Field               */
/* ------- IE Bit Fields                            ------ */
#define LPC_GPIO0_IE_MASK0_MASK                  (0x1U)                                              /*!< LPC_GPIO0_IE.MASK0 Mask                 */
#define LPC_GPIO0_IE_MASK0_SHIFT                 (0U)                                                /*!< LPC_GPIO0_IE.MASK0 Position             */
#define LPC_GPIO0_IE_MASK0(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_IE.MASK0 Field                */
#define LPC_GPIO0_IE_MASK1_MASK                  (0x2U)                                              /*!< LPC_GPIO0_IE.MASK1 Mask                 */
#define LPC_GPIO0_IE_MASK1_SHIFT                 (1U)                                                /*!< LPC_GPIO0_IE.MASK1 Position             */
#define LPC_GPIO0_IE_MASK1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_IE.MASK1 Field                */
#define LPC_GPIO0_IE_MASK2_MASK                  (0x4U)                                              /*!< LPC_GPIO0_IE.MASK2 Mask                 */
#define LPC_GPIO0_IE_MASK2_SHIFT                 (2U)                                                /*!< LPC_GPIO0_IE.MASK2 Position             */
#define LPC_GPIO0_IE_MASK2(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_IE.MASK2 Field                */
#define LPC_GPIO0_IE_MASK3_MASK                  (0x8U)                                              /*!< LPC_GPIO0_IE.MASK3 Mask                 */
#define LPC_GPIO0_IE_MASK3_SHIFT                 (3U)                                                /*!< LPC_GPIO0_IE.MASK3 Position             */
#define LPC_GPIO0_IE_MASK3(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_IE.MASK3 Field                */
#define LPC_GPIO0_IE_MASK4_MASK                  (0x10U)                                             /*!< LPC_GPIO0_IE.MASK4 Mask                 */
#define LPC_GPIO0_IE_MASK4_SHIFT                 (4U)                                                /*!< LPC_GPIO0_IE.MASK4 Position             */
#define LPC_GPIO0_IE_MASK4(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_IE.MASK4 Field                */
#define LPC_GPIO0_IE_MASK5_MASK                  (0x20U)                                             /*!< LPC_GPIO0_IE.MASK5 Mask                 */
#define LPC_GPIO0_IE_MASK5_SHIFT                 (5U)                                                /*!< LPC_GPIO0_IE.MASK5 Position             */
#define LPC_GPIO0_IE_MASK5(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_IE.MASK5 Field                */
#define LPC_GPIO0_IE_MASK6_MASK                  (0x40U)                                             /*!< LPC_GPIO0_IE.MASK6 Mask                 */
#define LPC_GPIO0_IE_MASK6_SHIFT                 (6U)                                                /*!< LPC_GPIO0_IE.MASK6 Position             */
#define LPC_GPIO0_IE_MASK6(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_IE.MASK6 Field                */
#define LPC_GPIO0_IE_MASK7_MASK                  (0x80U)                                             /*!< LPC_GPIO0_IE.MASK7 Mask                 */
#define LPC_GPIO0_IE_MASK7_SHIFT                 (7U)                                                /*!< LPC_GPIO0_IE.MASK7 Position             */
#define LPC_GPIO0_IE_MASK7(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_IE.MASK7 Field                */
#define LPC_GPIO0_IE_MASK8_MASK                  (0x100U)                                            /*!< LPC_GPIO0_IE.MASK8 Mask                 */
#define LPC_GPIO0_IE_MASK8_SHIFT                 (8U)                                                /*!< LPC_GPIO0_IE.MASK8 Position             */
#define LPC_GPIO0_IE_MASK8(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_IE.MASK8 Field                */
#define LPC_GPIO0_IE_MASK9_MASK                  (0x200U)                                            /*!< LPC_GPIO0_IE.MASK9 Mask                 */
#define LPC_GPIO0_IE_MASK9_SHIFT                 (9U)                                                /*!< LPC_GPIO0_IE.MASK9 Position             */
#define LPC_GPIO0_IE_MASK9(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_IE.MASK9 Field                */
#define LPC_GPIO0_IE_MASK10_MASK                 (0x400U)                                            /*!< LPC_GPIO0_IE.MASK10 Mask                */
#define LPC_GPIO0_IE_MASK10_SHIFT                (10U)                                               /*!< LPC_GPIO0_IE.MASK10 Position            */
#define LPC_GPIO0_IE_MASK10(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_IE.MASK10 Field               */
#define LPC_GPIO0_IE_MASK11_MASK                 (0x800U)                                            /*!< LPC_GPIO0_IE.MASK11 Mask                */
#define LPC_GPIO0_IE_MASK11_SHIFT                (11U)                                               /*!< LPC_GPIO0_IE.MASK11 Position            */
#define LPC_GPIO0_IE_MASK11(x)                   (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_IE.MASK11 Field               */
/* ------- RIS Bit Fields                           ------ */
#define LPC_GPIO0_RIS_RAWST0_MASK                (0x1U)                                              /*!< LPC_GPIO0_RIS.RAWST0 Mask               */
#define LPC_GPIO0_RIS_RAWST0_SHIFT               (0U)                                                /*!< LPC_GPIO0_RIS.RAWST0 Position           */
#define LPC_GPIO0_RIS_RAWST0(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_RIS.RAWST0 Field              */
#define LPC_GPIO0_RIS_RAWST1_MASK                (0x2U)                                              /*!< LPC_GPIO0_RIS.RAWST1 Mask               */
#define LPC_GPIO0_RIS_RAWST1_SHIFT               (1U)                                                /*!< LPC_GPIO0_RIS.RAWST1 Position           */
#define LPC_GPIO0_RIS_RAWST1(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_RIS.RAWST1 Field              */
#define LPC_GPIO0_RIS_RAWST2_MASK                (0x4U)                                              /*!< LPC_GPIO0_RIS.RAWST2 Mask               */
#define LPC_GPIO0_RIS_RAWST2_SHIFT               (2U)                                                /*!< LPC_GPIO0_RIS.RAWST2 Position           */
#define LPC_GPIO0_RIS_RAWST2(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_RIS.RAWST2 Field              */
#define LPC_GPIO0_RIS_RAWST3_MASK                (0x8U)                                              /*!< LPC_GPIO0_RIS.RAWST3 Mask               */
#define LPC_GPIO0_RIS_RAWST3_SHIFT               (3U)                                                /*!< LPC_GPIO0_RIS.RAWST3 Position           */
#define LPC_GPIO0_RIS_RAWST3(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_RIS.RAWST3 Field              */
#define LPC_GPIO0_RIS_RAWST4_MASK                (0x10U)                                             /*!< LPC_GPIO0_RIS.RAWST4 Mask               */
#define LPC_GPIO0_RIS_RAWST4_SHIFT               (4U)                                                /*!< LPC_GPIO0_RIS.RAWST4 Position           */
#define LPC_GPIO0_RIS_RAWST4(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_RIS.RAWST4 Field              */
#define LPC_GPIO0_RIS_RAWST5_MASK                (0x20U)                                             /*!< LPC_GPIO0_RIS.RAWST5 Mask               */
#define LPC_GPIO0_RIS_RAWST5_SHIFT               (5U)                                                /*!< LPC_GPIO0_RIS.RAWST5 Position           */
#define LPC_GPIO0_RIS_RAWST5(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_RIS.RAWST5 Field              */
#define LPC_GPIO0_RIS_RAWST6_MASK                (0x40U)                                             /*!< LPC_GPIO0_RIS.RAWST6 Mask               */
#define LPC_GPIO0_RIS_RAWST6_SHIFT               (6U)                                                /*!< LPC_GPIO0_RIS.RAWST6 Position           */
#define LPC_GPIO0_RIS_RAWST6(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_RIS.RAWST6 Field              */
#define LPC_GPIO0_RIS_RAWST7_MASK                (0x80U)                                             /*!< LPC_GPIO0_RIS.RAWST7 Mask               */
#define LPC_GPIO0_RIS_RAWST7_SHIFT               (7U)                                                /*!< LPC_GPIO0_RIS.RAWST7 Position           */
#define LPC_GPIO0_RIS_RAWST7(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_RIS.RAWST7 Field              */
#define LPC_GPIO0_RIS_RAWST8_MASK                (0x100U)                                            /*!< LPC_GPIO0_RIS.RAWST8 Mask               */
#define LPC_GPIO0_RIS_RAWST8_SHIFT               (8U)                                                /*!< LPC_GPIO0_RIS.RAWST8 Position           */
#define LPC_GPIO0_RIS_RAWST8(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_RIS.RAWST8 Field              */
#define LPC_GPIO0_RIS_RAWST9_MASK                (0x200U)                                            /*!< LPC_GPIO0_RIS.RAWST9 Mask               */
#define LPC_GPIO0_RIS_RAWST9_SHIFT               (9U)                                                /*!< LPC_GPIO0_RIS.RAWST9 Position           */
#define LPC_GPIO0_RIS_RAWST9(x)                  (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_RIS.RAWST9 Field              */
#define LPC_GPIO0_RIS_RAWST10_MASK               (0x400U)                                            /*!< LPC_GPIO0_RIS.RAWST10 Mask              */
#define LPC_GPIO0_RIS_RAWST10_SHIFT              (10U)                                               /*!< LPC_GPIO0_RIS.RAWST10 Position          */
#define LPC_GPIO0_RIS_RAWST10(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_RIS.RAWST10 Field             */
#define LPC_GPIO0_RIS_RAWST11_MASK               (0x800U)                                            /*!< LPC_GPIO0_RIS.RAWST11 Mask              */
#define LPC_GPIO0_RIS_RAWST11_SHIFT              (11U)                                               /*!< LPC_GPIO0_RIS.RAWST11 Position          */
#define LPC_GPIO0_RIS_RAWST11(x)                 (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_RIS.RAWST11 Field             */
/* ------- MIS Bit Fields                           ------ */
#define LPC_GPIO0_MIS_MASK0_MASK                 (0x1U)                                              /*!< LPC_GPIO0_MIS.MASK0 Mask                */
#define LPC_GPIO0_MIS_MASK0_SHIFT                (0U)                                                /*!< LPC_GPIO0_MIS.MASK0 Position            */
#define LPC_GPIO0_MIS_MASK0(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_MIS.MASK0 Field               */
#define LPC_GPIO0_MIS_MASK1_MASK                 (0x2U)                                              /*!< LPC_GPIO0_MIS.MASK1 Mask                */
#define LPC_GPIO0_MIS_MASK1_SHIFT                (1U)                                                /*!< LPC_GPIO0_MIS.MASK1 Position            */
#define LPC_GPIO0_MIS_MASK1(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_MIS.MASK1 Field               */
#define LPC_GPIO0_MIS_MASK2_MASK                 (0x4U)                                              /*!< LPC_GPIO0_MIS.MASK2 Mask                */
#define LPC_GPIO0_MIS_MASK2_SHIFT                (2U)                                                /*!< LPC_GPIO0_MIS.MASK2 Position            */
#define LPC_GPIO0_MIS_MASK2(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_MIS.MASK2 Field               */
#define LPC_GPIO0_MIS_MASK3_MASK                 (0x8U)                                              /*!< LPC_GPIO0_MIS.MASK3 Mask                */
#define LPC_GPIO0_MIS_MASK3_SHIFT                (3U)                                                /*!< LPC_GPIO0_MIS.MASK3 Position            */
#define LPC_GPIO0_MIS_MASK3(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_MIS.MASK3 Field               */
#define LPC_GPIO0_MIS_MASK4_MASK                 (0x10U)                                             /*!< LPC_GPIO0_MIS.MASK4 Mask                */
#define LPC_GPIO0_MIS_MASK4_SHIFT                (4U)                                                /*!< LPC_GPIO0_MIS.MASK4 Position            */
#define LPC_GPIO0_MIS_MASK4(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_MIS.MASK4 Field               */
#define LPC_GPIO0_MIS_MASK5_MASK                 (0x20U)                                             /*!< LPC_GPIO0_MIS.MASK5 Mask                */
#define LPC_GPIO0_MIS_MASK5_SHIFT                (5U)                                                /*!< LPC_GPIO0_MIS.MASK5 Position            */
#define LPC_GPIO0_MIS_MASK5(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_MIS.MASK5 Field               */
#define LPC_GPIO0_MIS_MASK6_MASK                 (0x40U)                                             /*!< LPC_GPIO0_MIS.MASK6 Mask                */
#define LPC_GPIO0_MIS_MASK6_SHIFT                (6U)                                                /*!< LPC_GPIO0_MIS.MASK6 Position            */
#define LPC_GPIO0_MIS_MASK6(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_MIS.MASK6 Field               */
#define LPC_GPIO0_MIS_MASK7_MASK                 (0x80U)                                             /*!< LPC_GPIO0_MIS.MASK7 Mask                */
#define LPC_GPIO0_MIS_MASK7_SHIFT                (7U)                                                /*!< LPC_GPIO0_MIS.MASK7 Position            */
#define LPC_GPIO0_MIS_MASK7(x)                   (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_MIS.MASK7 Field               */
#define LPC_GPIO0_MIS_MASK8_MASK                 (0x100U)                                            /*!< LPC_GPIO0_MIS.MASK8 Mask                */
#define LPC_GPIO0_MIS_MASK8_SHIFT                (8U)                                                /*!< LPC_GPIO0_MIS.MASK8 Position            */
#define LPC_GPIO0_MIS_MASK8(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_MIS.MASK8 Field               */
#define LPC_GPIO0_MIS_MASK9_MASK                 (0x200U)                                            /*!< LPC_GPIO0_MIS.MASK9 Mask                */
#define LPC_GPIO0_MIS_MASK9_SHIFT                (9U)                                                /*!< LPC_GPIO0_MIS.MASK9 Position            */
#define LPC_GPIO0_MIS_MASK9(x)                   (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_MIS.MASK9 Field               */
#define LPC_GPIO0_MIS_MASK10_MASK                (0x400U)                                            /*!< LPC_GPIO0_MIS.MASK10 Mask               */
#define LPC_GPIO0_MIS_MASK10_SHIFT               (10U)                                               /*!< LPC_GPIO0_MIS.MASK10 Position           */
#define LPC_GPIO0_MIS_MASK10(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_MIS.MASK10 Field              */
#define LPC_GPIO0_MIS_MASK11_MASK                (0x800U)                                            /*!< LPC_GPIO0_MIS.MASK11 Mask               */
#define LPC_GPIO0_MIS_MASK11_SHIFT               (11U)                                               /*!< LPC_GPIO0_MIS.MASK11 Position           */
#define LPC_GPIO0_MIS_MASK11(x)                  (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_MIS.MASK11 Field              */
/* ------- IC Bit Fields                            ------ */
#define LPC_GPIO0_IC_CLR0_MASK                   (0x1U)                                              /*!< LPC_GPIO0_IC.CLR0 Mask                  */
#define LPC_GPIO0_IC_CLR0_SHIFT                  (0U)                                                /*!< LPC_GPIO0_IC.CLR0 Position              */
#define LPC_GPIO0_IC_CLR0(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_GPIO0_IC.CLR0 Field                 */
#define LPC_GPIO0_IC_CLR1_MASK                   (0x2U)                                              /*!< LPC_GPIO0_IC.CLR1 Mask                  */
#define LPC_GPIO0_IC_CLR1_SHIFT                  (1U)                                                /*!< LPC_GPIO0_IC.CLR1 Position              */
#define LPC_GPIO0_IC_CLR1(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_GPIO0_IC.CLR1 Field                 */
#define LPC_GPIO0_IC_CLR2_MASK                   (0x4U)                                              /*!< LPC_GPIO0_IC.CLR2 Mask                  */
#define LPC_GPIO0_IC_CLR2_SHIFT                  (2U)                                                /*!< LPC_GPIO0_IC.CLR2 Position              */
#define LPC_GPIO0_IC_CLR2(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_GPIO0_IC.CLR2 Field                 */
#define LPC_GPIO0_IC_CLR3_MASK                   (0x8U)                                              /*!< LPC_GPIO0_IC.CLR3 Mask                  */
#define LPC_GPIO0_IC_CLR3_SHIFT                  (3U)                                                /*!< LPC_GPIO0_IC.CLR3 Position              */
#define LPC_GPIO0_IC_CLR3(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_GPIO0_IC.CLR3 Field                 */
#define LPC_GPIO0_IC_CLR4_MASK                   (0x10U)                                             /*!< LPC_GPIO0_IC.CLR4 Mask                  */
#define LPC_GPIO0_IC_CLR4_SHIFT                  (4U)                                                /*!< LPC_GPIO0_IC.CLR4 Position              */
#define LPC_GPIO0_IC_CLR4(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_GPIO0_IC.CLR4 Field                 */
#define LPC_GPIO0_IC_CLR5_MASK                   (0x20U)                                             /*!< LPC_GPIO0_IC.CLR5 Mask                  */
#define LPC_GPIO0_IC_CLR5_SHIFT                  (5U)                                                /*!< LPC_GPIO0_IC.CLR5 Position              */
#define LPC_GPIO0_IC_CLR5(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_GPIO0_IC.CLR5 Field                 */
#define LPC_GPIO0_IC_CLR6_MASK                   (0x40U)                                             /*!< LPC_GPIO0_IC.CLR6 Mask                  */
#define LPC_GPIO0_IC_CLR6_SHIFT                  (6U)                                                /*!< LPC_GPIO0_IC.CLR6 Position              */
#define LPC_GPIO0_IC_CLR6(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_GPIO0_IC.CLR6 Field                 */
#define LPC_GPIO0_IC_CLR7_MASK                   (0x80U)                                             /*!< LPC_GPIO0_IC.CLR7 Mask                  */
#define LPC_GPIO0_IC_CLR7_SHIFT                  (7U)                                                /*!< LPC_GPIO0_IC.CLR7 Position              */
#define LPC_GPIO0_IC_CLR7(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_GPIO0_IC.CLR7 Field                 */
#define LPC_GPIO0_IC_CLR8_MASK                   (0x100U)                                            /*!< LPC_GPIO0_IC.CLR8 Mask                  */
#define LPC_GPIO0_IC_CLR8_SHIFT                  (8U)                                                /*!< LPC_GPIO0_IC.CLR8 Position              */
#define LPC_GPIO0_IC_CLR8(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_GPIO0_IC.CLR8 Field                 */
#define LPC_GPIO0_IC_CLR9_MASK                   (0x200U)                                            /*!< LPC_GPIO0_IC.CLR9 Mask                  */
#define LPC_GPIO0_IC_CLR9_SHIFT                  (9U)                                                /*!< LPC_GPIO0_IC.CLR9 Position              */
#define LPC_GPIO0_IC_CLR9(x)                     (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_GPIO0_IC.CLR9 Field                 */
#define LPC_GPIO0_IC_CLR10_MASK                  (0x400U)                                            /*!< LPC_GPIO0_IC.CLR10 Mask                 */
#define LPC_GPIO0_IC_CLR10_SHIFT                 (10U)                                               /*!< LPC_GPIO0_IC.CLR10 Position             */
#define LPC_GPIO0_IC_CLR10(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_GPIO0_IC.CLR10 Field                */
#define LPC_GPIO0_IC_CLR11_MASK                  (0x800U)                                            /*!< LPC_GPIO0_IC.CLR11 Mask                 */
#define LPC_GPIO0_IC_CLR11_SHIFT                 (11U)                                               /*!< LPC_GPIO0_IC.CLR11 Position             */
#define LPC_GPIO0_IC_CLR11(x)                    (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_GPIO0_IC.CLR11 Field                */
/**
 * @} */ /* End group GPIO_Register_Masks_GROUP 
 */

/* LPC_GPIO0 - Peripheral instance base addresses */
#define LPC_GPIO0_BasePtr              0x50000000UL //!< Peripheral base address
#define LPC_GPIO0                      ((LPC_GPIO0_Type *) LPC_GPIO0_BasePtr) //!< Freescale base pointer
#define LPC_GPIO0_BASE_PTR             (LPC_GPIO0) //!< Freescale style base pointer
#define LPC_GPIO0_IRQS { PIO_0_IRQn,  }

/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           LPC_GPIO1 (derived from GPIO0)       ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O
 */

/* LPC_GPIO1 - Peripheral instance base addresses */
#define LPC_GPIO1_BasePtr              0x50010000UL //!< Peripheral base address
#define LPC_GPIO1                      ((LPC_GPIO0_Type *) LPC_GPIO1_BasePtr) //!< Freescale base pointer
#define LPC_GPIO1_BASE_PTR             (LPC_GPIO1) //!< Freescale style base pointer
#define LPC_GPIO1_IRQS { PIO_1_IRQn,  }

/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           LPC_GPIO2 (derived from GPIO0)       ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O
 */

/* LPC_GPIO2 - Peripheral instance base addresses */
#define LPC_GPIO2_BasePtr              0x50020000UL //!< Peripheral base address
#define LPC_GPIO2                      ((LPC_GPIO0_Type *) LPC_GPIO2_BasePtr) //!< Freescale base pointer
#define LPC_GPIO2_BASE_PTR             (LPC_GPIO2) //!< Freescale style base pointer
#define LPC_GPIO2_IRQS { PIO_2_IRQn,  }

/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           LPC_GPIO3 (derived from GPIO0)       ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O
 */

/* LPC_GPIO3 - Peripheral instance base addresses */
#define LPC_GPIO3_BasePtr              0x50030000UL //!< Peripheral base address
#define LPC_GPIO3                      ((LPC_GPIO0_Type *) LPC_GPIO3_BasePtr) //!< Freescale base pointer
#define LPC_GPIO3_BASE_PTR             (LPC_GPIO3) //!< Freescale style base pointer
#define LPC_GPIO3_IRQS { PIO_3_IRQn,  }

/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           LPC_I2C (file:I2C_LPC13xx)           ================ */
/* ================================================================================ */

/**
 * @brief I2C-bus controller
 */
/**
* @addtogroup I2C_structs_GROUP I2C struct
* @brief Struct for I2C
* @{
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
   __IO uint32_t  ADR1;                         /**< 0020: I2C                                                          */
   __IO uint32_t  ADR2;                         /**< 0024: I2C                                                          */
   __IO uint32_t  ADR3;                         /**< 0028: I2C                                                          */
   __I  uint32_t  DATA_BUFFER;                  /**< 002C: Data buffer register. The contents of the 8 MSBs of the I2DAT shift register will be transferred to the DATA_BUFFER automatically after every nine bits (8 bits of data plus ACK or NACK) has been received on the bus */
   __IO uint32_t  MASK0;                        /**< 0030: I2C Slave address mask register n. This mask register is associated with I2ADRn to determine an address match. The mask register has no effect when comparing to the General Call address (0000000) */
   __IO uint32_t  MASK1;                        /**< 0034: I2C Slave address mask register n. This mask register is associated with I2ADRn to determine an address match. The mask register has no effect when comparing to the General Call address (0000000) */
   __IO uint32_t  MASK2;                        /**< 0038: I2C Slave address mask register n. This mask register is associated with I2ADRn to determine an address match. The mask register has no effect when comparing to the General Call address (0000000) */
   __IO uint32_t  MASK3;                        /**< 003C: I2C Slave address mask register n. This mask register is associated with I2ADRn to determine an address match. The mask register has no effect when comparing to the General Call address (0000000) */
} LPC_I2C_Type;

/**
 * @} */ /* End group I2C_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_I2C' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2C_Register_Masks_GROUP I2C Register Masks
* @brief Register Masks for I2C
* @{
*/
/* ------- CONSET Bit Fields                        ------ */
#define LPC_I2C_CONSET_AA_MASK                   (0x4U)                                              /*!< LPC_I2C_CONSET.AA Mask                  */
#define LPC_I2C_CONSET_AA_SHIFT                  (2U)                                                /*!< LPC_I2C_CONSET.AA Position              */
#define LPC_I2C_CONSET_AA(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_I2C_CONSET.AA Field                 */
#define LPC_I2C_CONSET_SI_MASK                   (0x8U)                                              /*!< LPC_I2C_CONSET.SI Mask                  */
#define LPC_I2C_CONSET_SI_SHIFT                  (3U)                                                /*!< LPC_I2C_CONSET.SI Position              */
#define LPC_I2C_CONSET_SI(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_I2C_CONSET.SI Field                 */
#define LPC_I2C_CONSET_STO_MASK                  (0x10U)                                             /*!< LPC_I2C_CONSET.STO Mask                 */
#define LPC_I2C_CONSET_STO_SHIFT                 (4U)                                                /*!< LPC_I2C_CONSET.STO Position             */
#define LPC_I2C_CONSET_STO(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_I2C_CONSET.STO Field                */
#define LPC_I2C_CONSET_STA_MASK                  (0x20U)                                             /*!< LPC_I2C_CONSET.STA Mask                 */
#define LPC_I2C_CONSET_STA_SHIFT                 (5U)                                                /*!< LPC_I2C_CONSET.STA Position             */
#define LPC_I2C_CONSET_STA(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_I2C_CONSET.STA Field                */
#define LPC_I2C_CONSET_I2EN_MASK                 (0x40U)                                             /*!< LPC_I2C_CONSET.I2EN Mask                */
#define LPC_I2C_CONSET_I2EN_SHIFT                (6U)                                                /*!< LPC_I2C_CONSET.I2EN Position            */
#define LPC_I2C_CONSET_I2EN(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_I2C_CONSET.I2EN Field               */
/* ------- STAT Bit Fields                          ------ */
#define LPC_I2C_STAT_Status_MASK                 (0xF8U)                                             /*!< LPC_I2C_STAT.Status Mask                */
#define LPC_I2C_STAT_Status_SHIFT                (3U)                                                /*!< LPC_I2C_STAT.Status Position            */
#define LPC_I2C_STAT_Status(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0xF8UL)          /*!< LPC_I2C_STAT.Status Field               */
/* ------- DAT Bit Fields                           ------ */
#define LPC_I2C_DAT_Data_MASK                    (0xFFU)                                             /*!< LPC_I2C_DAT.Data Mask                   */
#define LPC_I2C_DAT_Data_SHIFT                   (0U)                                                /*!< LPC_I2C_DAT.Data Position               */
#define LPC_I2C_DAT_Data(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_I2C_DAT.Data Field                  */
/* ------- ADR0 Bit Fields                          ------ */
#define LPC_I2C_ADR0_GC_MASK                     (0x1U)                                              /*!< LPC_I2C_ADR0.GC Mask                    */
#define LPC_I2C_ADR0_GC_SHIFT                    (0U)                                                /*!< LPC_I2C_ADR0.GC Position                */
#define LPC_I2C_ADR0_GC(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_I2C_ADR0.GC Field                   */
#define LPC_I2C_ADR0_Address_MASK                (0xFEU)                                             /*!< LPC_I2C_ADR0.Address Mask               */
#define LPC_I2C_ADR0_Address_SHIFT               (1U)                                                /*!< LPC_I2C_ADR0.Address Position           */
#define LPC_I2C_ADR0_Address(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< LPC_I2C_ADR0.Address Field              */
/* ------- SCLH Bit Fields                          ------ */
#define LPC_I2C_SCLH_SCLH_MASK                   (0xFFFFU)                                           /*!< LPC_I2C_SCLH.SCLH Mask                  */
#define LPC_I2C_SCLH_SCLH_SHIFT                  (0U)                                                /*!< LPC_I2C_SCLH.SCLH Position              */
#define LPC_I2C_SCLH_SCLH(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_I2C_SCLH.SCLH Field                 */
/* ------- SCLL Bit Fields                          ------ */
#define LPC_I2C_SCLL_SCLL_MASK                   (0xFFFFU)                                           /*!< LPC_I2C_SCLL.SCLL Mask                  */
#define LPC_I2C_SCLL_SCLL_SHIFT                  (0U)                                                /*!< LPC_I2C_SCLL.SCLL Position              */
#define LPC_I2C_SCLL_SCLL(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_I2C_SCLL.SCLL Field                 */
/* ------- CONCLR Bit Fields                        ------ */
#define LPC_I2C_CONCLR_AAC_MASK                  (0x4U)                                              /*!< LPC_I2C_CONCLR.AAC Mask                 */
#define LPC_I2C_CONCLR_AAC_SHIFT                 (2U)                                                /*!< LPC_I2C_CONCLR.AAC Position             */
#define LPC_I2C_CONCLR_AAC(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_I2C_CONCLR.AAC Field                */
#define LPC_I2C_CONCLR_SIC_MASK                  (0x8U)                                              /*!< LPC_I2C_CONCLR.SIC Mask                 */
#define LPC_I2C_CONCLR_SIC_SHIFT                 (3U)                                                /*!< LPC_I2C_CONCLR.SIC Position             */
#define LPC_I2C_CONCLR_SIC(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_I2C_CONCLR.SIC Field                */
#define LPC_I2C_CONCLR_STAC_MASK                 (0x20U)                                             /*!< LPC_I2C_CONCLR.STAC Mask                */
#define LPC_I2C_CONCLR_STAC_SHIFT                (5U)                                                /*!< LPC_I2C_CONCLR.STAC Position            */
#define LPC_I2C_CONCLR_STAC(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_I2C_CONCLR.STAC Field               */
#define LPC_I2C_CONCLR_I2ENC_MASK                (0x40U)                                             /*!< LPC_I2C_CONCLR.I2ENC Mask               */
#define LPC_I2C_CONCLR_I2ENC_SHIFT               (6U)                                                /*!< LPC_I2C_CONCLR.I2ENC Position           */
#define LPC_I2C_CONCLR_I2ENC(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_I2C_CONCLR.I2ENC Field              */
/* ------- MMCTRL Bit Fields                        ------ */
#define LPC_I2C_MMCTRL_MM_ENA_MASK               (0x1U)                                              /*!< LPC_I2C_MMCTRL.MM_ENA Mask              */
#define LPC_I2C_MMCTRL_MM_ENA_SHIFT              (0U)                                                /*!< LPC_I2C_MMCTRL.MM_ENA Position          */
#define LPC_I2C_MMCTRL_MM_ENA(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_I2C_MMCTRL.MM_ENA Field             */
#define LPC_I2C_MMCTRL_ENA_SCL_MASK              (0x2U)                                              /*!< LPC_I2C_MMCTRL.ENA_SCL Mask             */
#define LPC_I2C_MMCTRL_ENA_SCL_SHIFT             (1U)                                                /*!< LPC_I2C_MMCTRL.ENA_SCL Position         */
#define LPC_I2C_MMCTRL_ENA_SCL(x)                (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_I2C_MMCTRL.ENA_SCL Field            */
#define LPC_I2C_MMCTRL_MATCH_ALL_MASK            (0x4U)                                              /*!< LPC_I2C_MMCTRL.MATCH_ALL Mask           */
#define LPC_I2C_MMCTRL_MATCH_ALL_SHIFT           (2U)                                                /*!< LPC_I2C_MMCTRL.MATCH_ALL Position       */
#define LPC_I2C_MMCTRL_MATCH_ALL(x)              (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_I2C_MMCTRL.MATCH_ALL Field          */
/* ------- ADR1 Bit Fields                          ------ */
#define LPC_I2C_ADR1_GC_MASK                     (0x1U)                                              /*!< LPC_I2C_ADR1.GC Mask                    */
#define LPC_I2C_ADR1_GC_SHIFT                    (0U)                                                /*!< LPC_I2C_ADR1.GC Position                */
#define LPC_I2C_ADR1_GC(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_I2C_ADR1.GC Field                   */
#define LPC_I2C_ADR1_Address_MASK                (0xFEU)                                             /*!< LPC_I2C_ADR1.Address Mask               */
#define LPC_I2C_ADR1_Address_SHIFT               (1U)                                                /*!< LPC_I2C_ADR1.Address Position           */
#define LPC_I2C_ADR1_Address(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< LPC_I2C_ADR1.Address Field              */
/* ------- ADR2 Bit Fields                          ------ */
#define LPC_I2C_ADR2_GC_MASK                     (0x1U)                                              /*!< LPC_I2C_ADR2.GC Mask                    */
#define LPC_I2C_ADR2_GC_SHIFT                    (0U)                                                /*!< LPC_I2C_ADR2.GC Position                */
#define LPC_I2C_ADR2_GC(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_I2C_ADR2.GC Field                   */
#define LPC_I2C_ADR2_Address_MASK                (0xFEU)                                             /*!< LPC_I2C_ADR2.Address Mask               */
#define LPC_I2C_ADR2_Address_SHIFT               (1U)                                                /*!< LPC_I2C_ADR2.Address Position           */
#define LPC_I2C_ADR2_Address(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< LPC_I2C_ADR2.Address Field              */
/* ------- ADR3 Bit Fields                          ------ */
#define LPC_I2C_ADR3_GC_MASK                     (0x1U)                                              /*!< LPC_I2C_ADR3.GC Mask                    */
#define LPC_I2C_ADR3_GC_SHIFT                    (0U)                                                /*!< LPC_I2C_ADR3.GC Position                */
#define LPC_I2C_ADR3_GC(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_I2C_ADR3.GC Field                   */
#define LPC_I2C_ADR3_Address_MASK                (0xFEU)                                             /*!< LPC_I2C_ADR3.Address Mask               */
#define LPC_I2C_ADR3_Address_SHIFT               (1U)                                                /*!< LPC_I2C_ADR3.Address Position           */
#define LPC_I2C_ADR3_Address(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< LPC_I2C_ADR3.Address Field              */
/* ------- DATA_BUFFER Bit Fields                   ------ */
#define LPC_I2C_DATA_BUFFER_Data_MASK            (0xFFU)                                             /*!< LPC_I2C_DATA_BUFFER.Data Mask           */
#define LPC_I2C_DATA_BUFFER_Data_SHIFT           (0U)                                                /*!< LPC_I2C_DATA_BUFFER.Data Position       */
#define LPC_I2C_DATA_BUFFER_Data(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_I2C_DATA_BUFFER.Data Field          */
/* ------- MASK0 Bit Fields                         ------ */
#define LPC_I2C_MASK0_MASK_MASK                  (0xFEU)                                             /*!< LPC_I2C_MASK0.MASK Mask                 */
#define LPC_I2C_MASK0_MASK_SHIFT                 (1U)                                                /*!< LPC_I2C_MASK0.MASK Position             */
#define LPC_I2C_MASK0_MASK(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< LPC_I2C_MASK0.MASK Field                */
/* ------- MASK1 Bit Fields                         ------ */
#define LPC_I2C_MASK1_MASK_MASK                  (0xFEU)                                             /*!< LPC_I2C_MASK1.MASK Mask                 */
#define LPC_I2C_MASK1_MASK_SHIFT                 (1U)                                                /*!< LPC_I2C_MASK1.MASK Position             */
#define LPC_I2C_MASK1_MASK(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< LPC_I2C_MASK1.MASK Field                */
/* ------- MASK2 Bit Fields                         ------ */
#define LPC_I2C_MASK2_MASK_MASK                  (0xFEU)                                             /*!< LPC_I2C_MASK2.MASK Mask                 */
#define LPC_I2C_MASK2_MASK_SHIFT                 (1U)                                                /*!< LPC_I2C_MASK2.MASK Position             */
#define LPC_I2C_MASK2_MASK(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< LPC_I2C_MASK2.MASK Field                */
/* ------- MASK3 Bit Fields                         ------ */
#define LPC_I2C_MASK3_MASK_MASK                  (0xFEU)                                             /*!< LPC_I2C_MASK3.MASK Mask                 */
#define LPC_I2C_MASK3_MASK_SHIFT                 (1U)                                                /*!< LPC_I2C_MASK3.MASK Position             */
#define LPC_I2C_MASK3_MASK(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0xFEUL)          /*!< LPC_I2C_MASK3.MASK Field                */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* LPC_I2C - Peripheral instance base addresses */
#define LPC_I2C_BasePtr                0x40000000UL //!< Peripheral base address
#define LPC_I2C                        ((LPC_I2C_Type *) LPC_I2C_BasePtr) //!< Freescale base pointer
#define LPC_I2C_BASE_PTR               (LPC_I2C) //!< Freescale style base pointer
#define LPC_I2C_IRQS { I2C0_IRQn,  }

/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup IOCON_Peripheral_access_layer_GROUP IOCON Peripheral Access Layer
* @brief C Struct for IOCON
* @{
*/

/* ================================================================================ */
/* ================           LPC_IOCON (file:IOCON_LPC13xx)       ================ */
/* ================================================================================ */

/**
 * @brief I/O configuration
 */
/**
* @addtogroup IOCON_structs_GROUP IOCON struct
* @brief Struct for IOCON
* @{
*/
typedef struct LPC_IOCON_Type {
   __IO uint32_t  PIO2_6;                       /**< 0000: I/O configuration for pin PIO2_6                             */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  PIO2_0;                       /**< 0008: I/O configuration for pin PIO2_0/DTR/SSEL1                   */
   __IO uint32_t  RESET_PIO0_0;                 /**< 000C: I/O configuration for pin RESET/PIO0_0                       */
   __IO uint32_t  PIO0_1;                       /**< 0010: I/O configuration for pin PIO0_1/CLKOUT/ CT32B0_MAT2/USB_FTOGGLE */
   __IO uint32_t  PIO1_8;                       /**< 0014: I/O configuration for pin PIO1_8/CT16B1_CAP0                 */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  PIO0_2;                       /**< 001C: I/O configuration for pin PIO0_2/SSEL0/ CT16B0_CAP0          */
   __IO uint32_t  PIO2_7;                       /**< 0020: I/O configuration for pin PIO2_7                             */
   __IO uint32_t  PIO2_8;                       /**< 0024: I/O configuration for pin PIO2_7                             */
   __IO uint32_t  PIO2_1;                       /**< 0028: I/O configuration for pin PIO2_1/DSR/SCK1                    */
   __IO uint32_t  PIO0_3;                       /**< 002C: I/O configuration for pin PIO0_3/USB_VBUS                    */
   __IO uint32_t  PIO0_4;                       /**< 0030: I/O configuration for pin PIO0_4/SCL                         */
   __IO uint32_t  PIO0_5;                       /**< 0034: I/O configuration for pin PIO0_5/SDA                         */
   __IO uint32_t  PIO1_9;                       /**< 0038: I/O configuration for pin PIO1_9/CT16B1_MAT0                 */
   __IO uint32_t  PIO3_4;                       /**< 003C: I/O configuration for pin PIO3_4                             */
   __IO uint32_t  PIO2_4;                       /**< 0040: I/O configuration for pin PIO2_4                             */
   __IO uint32_t  PIO2_5;                       /**< 0044: I/O configuration for pin PIO2_4                             */
   __IO uint32_t  PIO3_5;                       /**< 0048: I/O configuration for pin PIO3_5                             */
   __IO uint32_t  PIO0_6;                       /**< 004C: I/O configuration for pin PIO0_6/USB_CONNECT/SCK             */
   __IO uint32_t  PIO0_7;                       /**< 0050: I/O configuration for pin PIO0_7/CTS                         */
   __IO uint32_t  PIO2_9;                       /**< 0054: I/O configuration for pin PIO2_9                             */
   __IO uint32_t  PIO2_10;                      /**< 0058: I/O configuration for pin PIO2_9                             */
   __IO uint32_t  PIO2_2;                       /**< 005C: I/O configuration for pin PIO2_2/DCD/MISO1                   */
   __IO uint32_t  PIO0_8;                       /**< 0060: I/O configuration for pin PIO0_8/MISO0/CT16B0_MAT0           */
   __IO uint32_t  PIO0_9;                       /**< 0064: I/O configuration for pin PIO0_9/MOSI0/ CT16B0_MAT1/SWO      */
   __IO uint32_t  SWCLK_PIO0_10;                /**< 0068: I/O configuration for pin SWCLK/PIO0_10/ SCK/CT16B0_MAT2     */
   __IO uint32_t  PIO1_10;                      /**< 006C: I/O configuration for pin PIO1_10/AD6/ CT16B1_MAT1           */
   __IO uint32_t  PIO2_11;                      /**< 0070: I/O configuration for pin PIO2_11/SCK                        */
   __IO uint32_t  R_PIO0_11;                    /**< 0074: I/O configuration for pin R/PIO0_11/AD0/CT32B0_MAT3          */
   __IO uint32_t  R_PIO1_0;                     /**< 0078: I/O configuration for pin R/PIO1_0/AD1/ CT32B1_CAP0          */
   __IO uint32_t  R_PIO1_1;                     /**< 007C: I/O configuration for pin R/PIO1_1/AD2/CT32B1_MAT0           */
   __IO uint32_t  R_PIO1_2;                     /**< 0080: I/O configuration for pin R/PIO1_2/AD3/ CT32B1_MAT1          */
   __IO uint32_t  PIO3_0;                       /**< 0084: I/O configuration for pin PIO3_0/DTR                         */
   __IO uint32_t  PIO3_1;                       /**< 0088: I/O configuration for pin PIO3_1/DSR                         */
   __IO uint32_t  PIO2_3;                       /**< 008C: I/O configuration for pin PIO2_3/RI/MOSI1                    */
   __IO uint32_t  SWDIO_PIO1_3;                 /**< 0090: I/O configuration for pin SWDIO/PIO1_3/AD4/ CT32B1_MAT2      */
   __IO uint32_t  PIO1_4;                       /**< 0094: I/O configuration for pin PIO1_4/AD5/CT32B1_MAT3             */
   __IO uint32_t  PIO1_11;                      /**< 0098: I/O configuration for pin PIO1_11/AD7                        */
   __IO uint32_t  PIO3_2;                       /**< 009C: I/O configuration for pin PIO3_2/DCD                         */
   __IO uint32_t  PIO1_5;                       /**< 00A0: I/O configuration for pin PIO1_5/RTS/CT32B0_CAP0             */
   __IO uint32_t  PIO1_6;                       /**< 00A4: I/O configuration for pin PIO1_6/RXD/CT32B0_MAT0             */
   __IO uint32_t  PIO1_7;                       /**< 00A8: I/O configuration for pin PIO1_7/TXD/CT32B0_MAT1             */
   __IO uint32_t  PIO3_3;                       /**< 00AC: I/O configuration for pin PIO3_3/RI                          */
   __IO uint32_t  SCK0_LOC;                     /**< 00B0: SCK0 pin location register                                   */
   __IO uint32_t  DSR_LOC;                      /**< 00B4: DSR pin location select register                             */
   __IO uint32_t  DCD_LOC;                      /**< 00B8: DCD pin location select register                             */
   __IO uint32_t  RI_LOC;                       /**< 00BC: RI pin location register                                     */
} LPC_IOCON_Type;

/**
 * @} */ /* End group IOCON_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_IOCON' Position & Mask macros                   ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup IOCON_Register_Masks_GROUP IOCON Register Masks
* @brief Register Masks for IOCON
* @{
*/
/* ------- PIO2_6 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_6_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_6.FUNC Mask              */
#define LPC_IOCON_PIO2_6_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_6.FUNC Position          */
#define LPC_IOCON_PIO2_6_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_6.FUNC Field             */
#define LPC_IOCON_PIO2_6_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_6.MODE Mask              */
#define LPC_IOCON_PIO2_6_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_6.MODE Position          */
#define LPC_IOCON_PIO2_6_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_6.MODE Field             */
#define LPC_IOCON_PIO2_6_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_6.HYS Mask               */
#define LPC_IOCON_PIO2_6_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_6.HYS Position           */
#define LPC_IOCON_PIO2_6_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_6.HYS Field              */
#define LPC_IOCON_PIO2_6_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_6.OD Mask                */
#define LPC_IOCON_PIO2_6_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_6.OD Position            */
#define LPC_IOCON_PIO2_6_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_6.OD Field               */
/* ------- PIO2_0 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_0_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_0.FUNC Mask              */
#define LPC_IOCON_PIO2_0_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_0.FUNC Position          */
#define LPC_IOCON_PIO2_0_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_0.FUNC Field             */
#define LPC_IOCON_PIO2_0_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_0.MODE Mask              */
#define LPC_IOCON_PIO2_0_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_0.MODE Position          */
#define LPC_IOCON_PIO2_0_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_0.MODE Field             */
#define LPC_IOCON_PIO2_0_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_0.HYS Mask               */
#define LPC_IOCON_PIO2_0_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_0.HYS Position           */
#define LPC_IOCON_PIO2_0_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_0.HYS Field              */
#define LPC_IOCON_PIO2_0_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_0.OD Mask                */
#define LPC_IOCON_PIO2_0_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_0.OD Position            */
#define LPC_IOCON_PIO2_0_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_0.OD Field               */
/* ------- RESET_PIO0_0 Bit Fields                  ------ */
#define LPC_IOCON_RESET_PIO0_0_FUNC_MASK         (0x7U)                                              /*!< LPC_IOCON_RESET_PIO0_0.FUNC Mask        */
#define LPC_IOCON_RESET_PIO0_0_FUNC_SHIFT        (0U)                                                /*!< LPC_IOCON_RESET_PIO0_0.FUNC Position    */
#define LPC_IOCON_RESET_PIO0_0_FUNC(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_RESET_PIO0_0.FUNC Field       */
#define LPC_IOCON_RESET_PIO0_0_MODE_MASK         (0x18U)                                             /*!< LPC_IOCON_RESET_PIO0_0.MODE Mask        */
#define LPC_IOCON_RESET_PIO0_0_MODE_SHIFT        (3U)                                                /*!< LPC_IOCON_RESET_PIO0_0.MODE Position    */
#define LPC_IOCON_RESET_PIO0_0_MODE(x)           (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_RESET_PIO0_0.MODE Field       */
#define LPC_IOCON_RESET_PIO0_0_HYS_MASK          (0x20U)                                             /*!< LPC_IOCON_RESET_PIO0_0.HYS Mask         */
#define LPC_IOCON_RESET_PIO0_0_HYS_SHIFT         (5U)                                                /*!< LPC_IOCON_RESET_PIO0_0.HYS Position     */
#define LPC_IOCON_RESET_PIO0_0_HYS(x)            (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_RESET_PIO0_0.HYS Field        */
#define LPC_IOCON_RESET_PIO0_0_OD_MASK           (0x400U)                                            /*!< LPC_IOCON_RESET_PIO0_0.OD Mask          */
#define LPC_IOCON_RESET_PIO0_0_OD_SHIFT          (10U)                                               /*!< LPC_IOCON_RESET_PIO0_0.OD Position      */
#define LPC_IOCON_RESET_PIO0_0_OD(x)             (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_RESET_PIO0_0.OD Field         */
/* ------- PIO0_1 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_1_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_1.FUNC Mask              */
#define LPC_IOCON_PIO0_1_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_1.FUNC Position          */
#define LPC_IOCON_PIO0_1_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_1.FUNC Field             */
#define LPC_IOCON_PIO0_1_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_1.MODE Mask              */
#define LPC_IOCON_PIO0_1_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_1.MODE Position          */
#define LPC_IOCON_PIO0_1_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO0_1.MODE Field             */
#define LPC_IOCON_PIO0_1_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_1.HYS Mask               */
#define LPC_IOCON_PIO0_1_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_1.HYS Position           */
#define LPC_IOCON_PIO0_1_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO0_1.HYS Field              */
#define LPC_IOCON_PIO0_1_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_1.OD Mask                */
#define LPC_IOCON_PIO0_1_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_1.OD Position            */
#define LPC_IOCON_PIO0_1_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO0_1.OD Field               */
/* ------- PIO1_8 Bit Fields                        ------ */
#define LPC_IOCON_PIO1_8_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO1_8.FUNC Mask              */
#define LPC_IOCON_PIO1_8_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO1_8.FUNC Position          */
#define LPC_IOCON_PIO1_8_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO1_8.FUNC Field             */
#define LPC_IOCON_PIO1_8_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO1_8.MODE Mask              */
#define LPC_IOCON_PIO1_8_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO1_8.MODE Position          */
#define LPC_IOCON_PIO1_8_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO1_8.MODE Field             */
#define LPC_IOCON_PIO1_8_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO1_8.HYS Mask               */
#define LPC_IOCON_PIO1_8_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO1_8.HYS Position           */
#define LPC_IOCON_PIO1_8_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO1_8.HYS Field              */
#define LPC_IOCON_PIO1_8_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO1_8.OD Mask                */
#define LPC_IOCON_PIO1_8_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO1_8.OD Position            */
#define LPC_IOCON_PIO1_8_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO1_8.OD Field               */
/* ------- PIO0_2 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_2_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_2.FUNC Mask              */
#define LPC_IOCON_PIO0_2_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_2.FUNC Position          */
#define LPC_IOCON_PIO0_2_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_2.FUNC Field             */
#define LPC_IOCON_PIO0_2_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_2.MODE Mask              */
#define LPC_IOCON_PIO0_2_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_2.MODE Position          */
#define LPC_IOCON_PIO0_2_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO0_2.MODE Field             */
#define LPC_IOCON_PIO0_2_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_2.HYS Mask               */
#define LPC_IOCON_PIO0_2_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_2.HYS Position           */
#define LPC_IOCON_PIO0_2_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO0_2.HYS Field              */
#define LPC_IOCON_PIO0_2_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_2.OD Mask                */
#define LPC_IOCON_PIO0_2_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_2.OD Position            */
#define LPC_IOCON_PIO0_2_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO0_2.OD Field               */
/* ------- PIO2_7 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_7_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_7.FUNC Mask              */
#define LPC_IOCON_PIO2_7_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_7.FUNC Position          */
#define LPC_IOCON_PIO2_7_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_7.FUNC Field             */
#define LPC_IOCON_PIO2_7_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_7.MODE Mask              */
#define LPC_IOCON_PIO2_7_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_7.MODE Position          */
#define LPC_IOCON_PIO2_7_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_7.MODE Field             */
#define LPC_IOCON_PIO2_7_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_7.HYS Mask               */
#define LPC_IOCON_PIO2_7_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_7.HYS Position           */
#define LPC_IOCON_PIO2_7_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_7.HYS Field              */
#define LPC_IOCON_PIO2_7_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_7.OD Mask                */
#define LPC_IOCON_PIO2_7_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_7.OD Position            */
#define LPC_IOCON_PIO2_7_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_7.OD Field               */
/* ------- PIO2_8 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_8_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_8.FUNC Mask              */
#define LPC_IOCON_PIO2_8_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_8.FUNC Position          */
#define LPC_IOCON_PIO2_8_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_8.FUNC Field             */
#define LPC_IOCON_PIO2_8_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_8.MODE Mask              */
#define LPC_IOCON_PIO2_8_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_8.MODE Position          */
#define LPC_IOCON_PIO2_8_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_8.MODE Field             */
#define LPC_IOCON_PIO2_8_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_8.HYS Mask               */
#define LPC_IOCON_PIO2_8_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_8.HYS Position           */
#define LPC_IOCON_PIO2_8_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_8.HYS Field              */
#define LPC_IOCON_PIO2_8_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_8.OD Mask                */
#define LPC_IOCON_PIO2_8_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_8.OD Position            */
#define LPC_IOCON_PIO2_8_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_8.OD Field               */
/* ------- PIO2_1 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_1_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_1.FUNC Mask              */
#define LPC_IOCON_PIO2_1_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_1.FUNC Position          */
#define LPC_IOCON_PIO2_1_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_1.FUNC Field             */
#define LPC_IOCON_PIO2_1_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_1.MODE Mask              */
#define LPC_IOCON_PIO2_1_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_1.MODE Position          */
#define LPC_IOCON_PIO2_1_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_1.MODE Field             */
#define LPC_IOCON_PIO2_1_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_1.HYS Mask               */
#define LPC_IOCON_PIO2_1_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_1.HYS Position           */
#define LPC_IOCON_PIO2_1_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_1.HYS Field              */
#define LPC_IOCON_PIO2_1_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_1.OD Mask                */
#define LPC_IOCON_PIO2_1_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_1.OD Position            */
#define LPC_IOCON_PIO2_1_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_1.OD Field               */
/* ------- PIO0_3 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_3_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_3.FUNC Mask              */
#define LPC_IOCON_PIO0_3_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_3.FUNC Position          */
#define LPC_IOCON_PIO0_3_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_3.FUNC Field             */
#define LPC_IOCON_PIO0_3_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_3.MODE Mask              */
#define LPC_IOCON_PIO0_3_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_3.MODE Position          */
#define LPC_IOCON_PIO0_3_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO0_3.MODE Field             */
#define LPC_IOCON_PIO0_3_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_3.HYS Mask               */
#define LPC_IOCON_PIO0_3_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_3.HYS Position           */
#define LPC_IOCON_PIO0_3_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO0_3.HYS Field              */
#define LPC_IOCON_PIO0_3_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_3.OD Mask                */
#define LPC_IOCON_PIO0_3_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_3.OD Position            */
#define LPC_IOCON_PIO0_3_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO0_3.OD Field               */
/* ------- PIO0_4 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_4_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_4.FUNC Mask              */
#define LPC_IOCON_PIO0_4_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_4.FUNC Position          */
#define LPC_IOCON_PIO0_4_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_4.FUNC Field             */
#define LPC_IOCON_PIO0_4_I2CMODE_MASK            (0x300U)                                            /*!< LPC_IOCON_PIO0_4.I2CMODE Mask           */
#define LPC_IOCON_PIO0_4_I2CMODE_SHIFT           (8U)                                                /*!< LPC_IOCON_PIO0_4.I2CMODE Position       */
#define LPC_IOCON_PIO0_4_I2CMODE(x)              (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< LPC_IOCON_PIO0_4.I2CMODE Field          */
/* ------- PIO0_5 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_5_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_5.FUNC Mask              */
#define LPC_IOCON_PIO0_5_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_5.FUNC Position          */
#define LPC_IOCON_PIO0_5_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_5.FUNC Field             */
#define LPC_IOCON_PIO0_5_I2CMODE_MASK            (0x300U)                                            /*!< LPC_IOCON_PIO0_5.I2CMODE Mask           */
#define LPC_IOCON_PIO0_5_I2CMODE_SHIFT           (8U)                                                /*!< LPC_IOCON_PIO0_5.I2CMODE Position       */
#define LPC_IOCON_PIO0_5_I2CMODE(x)              (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< LPC_IOCON_PIO0_5.I2CMODE Field          */
/* ------- PIO1_9 Bit Fields                        ------ */
#define LPC_IOCON_PIO1_9_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO1_9.FUNC Mask              */
#define LPC_IOCON_PIO1_9_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO1_9.FUNC Position          */
#define LPC_IOCON_PIO1_9_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO1_9.FUNC Field             */
#define LPC_IOCON_PIO1_9_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO1_9.MODE Mask              */
#define LPC_IOCON_PIO1_9_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO1_9.MODE Position          */
#define LPC_IOCON_PIO1_9_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO1_9.MODE Field             */
#define LPC_IOCON_PIO1_9_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO1_9.HYS Mask               */
#define LPC_IOCON_PIO1_9_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO1_9.HYS Position           */
#define LPC_IOCON_PIO1_9_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO1_9.HYS Field              */
#define LPC_IOCON_PIO1_9_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO1_9.OD Mask                */
#define LPC_IOCON_PIO1_9_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO1_9.OD Position            */
#define LPC_IOCON_PIO1_9_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO1_9.OD Field               */
/* ------- PIO3_4 Bit Fields                        ------ */
#define LPC_IOCON_PIO3_4_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO3_4.FUNC Mask              */
#define LPC_IOCON_PIO3_4_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO3_4.FUNC Position          */
#define LPC_IOCON_PIO3_4_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO3_4.FUNC Field             */
#define LPC_IOCON_PIO3_4_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO3_4.MODE Mask              */
#define LPC_IOCON_PIO3_4_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO3_4.MODE Position          */
#define LPC_IOCON_PIO3_4_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO3_4.MODE Field             */
#define LPC_IOCON_PIO3_4_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO3_4.HYS Mask               */
#define LPC_IOCON_PIO3_4_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO3_4.HYS Position           */
#define LPC_IOCON_PIO3_4_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO3_4.HYS Field              */
#define LPC_IOCON_PIO3_4_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO3_4.OD Mask                */
#define LPC_IOCON_PIO3_4_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO3_4.OD Position            */
#define LPC_IOCON_PIO3_4_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO3_4.OD Field               */
/* ------- PIO2_4 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_4_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_4.FUNC Mask              */
#define LPC_IOCON_PIO2_4_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_4.FUNC Position          */
#define LPC_IOCON_PIO2_4_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_4.FUNC Field             */
#define LPC_IOCON_PIO2_4_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_4.MODE Mask              */
#define LPC_IOCON_PIO2_4_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_4.MODE Position          */
#define LPC_IOCON_PIO2_4_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_4.MODE Field             */
#define LPC_IOCON_PIO2_4_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_4.HYS Mask               */
#define LPC_IOCON_PIO2_4_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_4.HYS Position           */
#define LPC_IOCON_PIO2_4_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_4.HYS Field              */
#define LPC_IOCON_PIO2_4_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_4.OD Mask                */
#define LPC_IOCON_PIO2_4_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_4.OD Position            */
#define LPC_IOCON_PIO2_4_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_4.OD Field               */
/* ------- PIO2_5 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_5_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_5.FUNC Mask              */
#define LPC_IOCON_PIO2_5_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_5.FUNC Position          */
#define LPC_IOCON_PIO2_5_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_5.FUNC Field             */
#define LPC_IOCON_PIO2_5_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_5.MODE Mask              */
#define LPC_IOCON_PIO2_5_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_5.MODE Position          */
#define LPC_IOCON_PIO2_5_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_5.MODE Field             */
#define LPC_IOCON_PIO2_5_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_5.HYS Mask               */
#define LPC_IOCON_PIO2_5_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_5.HYS Position           */
#define LPC_IOCON_PIO2_5_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_5.HYS Field              */
#define LPC_IOCON_PIO2_5_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_5.OD Mask                */
#define LPC_IOCON_PIO2_5_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_5.OD Position            */
#define LPC_IOCON_PIO2_5_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_5.OD Field               */
/* ------- PIO3_5 Bit Fields                        ------ */
#define LPC_IOCON_PIO3_5_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO3_5.FUNC Mask              */
#define LPC_IOCON_PIO3_5_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO3_5.FUNC Position          */
#define LPC_IOCON_PIO3_5_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO3_5.FUNC Field             */
#define LPC_IOCON_PIO3_5_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO3_5.MODE Mask              */
#define LPC_IOCON_PIO3_5_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO3_5.MODE Position          */
#define LPC_IOCON_PIO3_5_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO3_5.MODE Field             */
#define LPC_IOCON_PIO3_5_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO3_5.HYS Mask               */
#define LPC_IOCON_PIO3_5_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO3_5.HYS Position           */
#define LPC_IOCON_PIO3_5_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO3_5.HYS Field              */
#define LPC_IOCON_PIO3_5_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO3_5.OD Mask                */
#define LPC_IOCON_PIO3_5_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO3_5.OD Position            */
#define LPC_IOCON_PIO3_5_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO3_5.OD Field               */
/* ------- PIO0_6 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_6_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_6.FUNC Mask              */
#define LPC_IOCON_PIO0_6_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_6.FUNC Position          */
#define LPC_IOCON_PIO0_6_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_6.FUNC Field             */
#define LPC_IOCON_PIO0_6_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_6.MODE Mask              */
#define LPC_IOCON_PIO0_6_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_6.MODE Position          */
#define LPC_IOCON_PIO0_6_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO0_6.MODE Field             */
#define LPC_IOCON_PIO0_6_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_6.HYS Mask               */
#define LPC_IOCON_PIO0_6_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_6.HYS Position           */
#define LPC_IOCON_PIO0_6_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO0_6.HYS Field              */
#define LPC_IOCON_PIO0_6_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_6.OD Mask                */
#define LPC_IOCON_PIO0_6_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_6.OD Position            */
#define LPC_IOCON_PIO0_6_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO0_6.OD Field               */
/* ------- PIO0_7 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_7_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_7.FUNC Mask              */
#define LPC_IOCON_PIO0_7_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_7.FUNC Position          */
#define LPC_IOCON_PIO0_7_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_7.FUNC Field             */
#define LPC_IOCON_PIO0_7_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_7.MODE Mask              */
#define LPC_IOCON_PIO0_7_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_7.MODE Position          */
#define LPC_IOCON_PIO0_7_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO0_7.MODE Field             */
#define LPC_IOCON_PIO0_7_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_7.HYS Mask               */
#define LPC_IOCON_PIO0_7_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_7.HYS Position           */
#define LPC_IOCON_PIO0_7_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO0_7.HYS Field              */
#define LPC_IOCON_PIO0_7_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_7.OD Mask                */
#define LPC_IOCON_PIO0_7_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_7.OD Position            */
#define LPC_IOCON_PIO0_7_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO0_7.OD Field               */
/* ------- PIO2_9 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_9_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_9.FUNC Mask              */
#define LPC_IOCON_PIO2_9_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_9.FUNC Position          */
#define LPC_IOCON_PIO2_9_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_9.FUNC Field             */
#define LPC_IOCON_PIO2_9_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_9.MODE Mask              */
#define LPC_IOCON_PIO2_9_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_9.MODE Position          */
#define LPC_IOCON_PIO2_9_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_9.MODE Field             */
#define LPC_IOCON_PIO2_9_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_9.HYS Mask               */
#define LPC_IOCON_PIO2_9_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_9.HYS Position           */
#define LPC_IOCON_PIO2_9_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_9.HYS Field              */
#define LPC_IOCON_PIO2_9_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_9.OD Mask                */
#define LPC_IOCON_PIO2_9_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_9.OD Position            */
#define LPC_IOCON_PIO2_9_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_9.OD Field               */
/* ------- PIO2_10 Bit Fields                       ------ */
#define LPC_IOCON_PIO2_10_FUNC_MASK              (0x7U)                                              /*!< LPC_IOCON_PIO2_10.FUNC Mask             */
#define LPC_IOCON_PIO2_10_FUNC_SHIFT             (0U)                                                /*!< LPC_IOCON_PIO2_10.FUNC Position         */
#define LPC_IOCON_PIO2_10_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_10.FUNC Field            */
#define LPC_IOCON_PIO2_10_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO2_10.MODE Mask             */
#define LPC_IOCON_PIO2_10_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO2_10.MODE Position         */
#define LPC_IOCON_PIO2_10_MODE(x)                (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_10.MODE Field            */
#define LPC_IOCON_PIO2_10_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO2_10.HYS Mask              */
#define LPC_IOCON_PIO2_10_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO2_10.HYS Position          */
#define LPC_IOCON_PIO2_10_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_10.HYS Field             */
#define LPC_IOCON_PIO2_10_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO2_10.OD Mask               */
#define LPC_IOCON_PIO2_10_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO2_10.OD Position           */
#define LPC_IOCON_PIO2_10_OD(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_10.OD Field              */
/* ------- PIO2_2 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_2_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_2.FUNC Mask              */
#define LPC_IOCON_PIO2_2_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_2.FUNC Position          */
#define LPC_IOCON_PIO2_2_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_2.FUNC Field             */
#define LPC_IOCON_PIO2_2_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_2.MODE Mask              */
#define LPC_IOCON_PIO2_2_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_2.MODE Position          */
#define LPC_IOCON_PIO2_2_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_2.MODE Field             */
#define LPC_IOCON_PIO2_2_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_2.HYS Mask               */
#define LPC_IOCON_PIO2_2_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_2.HYS Position           */
#define LPC_IOCON_PIO2_2_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_2.HYS Field              */
#define LPC_IOCON_PIO2_2_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_2.OD Mask                */
#define LPC_IOCON_PIO2_2_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_2.OD Position            */
#define LPC_IOCON_PIO2_2_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_2.OD Field               */
/* ------- PIO0_8 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_8_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_8.FUNC Mask              */
#define LPC_IOCON_PIO0_8_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_8.FUNC Position          */
#define LPC_IOCON_PIO0_8_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_8.FUNC Field             */
#define LPC_IOCON_PIO0_8_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_8.MODE Mask              */
#define LPC_IOCON_PIO0_8_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_8.MODE Position          */
#define LPC_IOCON_PIO0_8_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO0_8.MODE Field             */
#define LPC_IOCON_PIO0_8_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_8.HYS Mask               */
#define LPC_IOCON_PIO0_8_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_8.HYS Position           */
#define LPC_IOCON_PIO0_8_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO0_8.HYS Field              */
#define LPC_IOCON_PIO0_8_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_8.OD Mask                */
#define LPC_IOCON_PIO0_8_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_8.OD Position            */
#define LPC_IOCON_PIO0_8_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO0_8.OD Field               */
/* ------- PIO0_9 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_9_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO0_9.FUNC Mask              */
#define LPC_IOCON_PIO0_9_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO0_9.FUNC Position          */
#define LPC_IOCON_PIO0_9_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO0_9.FUNC Field             */
#define LPC_IOCON_PIO0_9_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_9.MODE Mask              */
#define LPC_IOCON_PIO0_9_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_9.MODE Position          */
#define LPC_IOCON_PIO0_9_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO0_9.MODE Field             */
#define LPC_IOCON_PIO0_9_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_9.HYS Mask               */
#define LPC_IOCON_PIO0_9_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_9.HYS Position           */
#define LPC_IOCON_PIO0_9_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO0_9.HYS Field              */
#define LPC_IOCON_PIO0_9_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_9.OD Mask                */
#define LPC_IOCON_PIO0_9_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_9.OD Position            */
#define LPC_IOCON_PIO0_9_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO0_9.OD Field               */
/* ------- SWCLK_PIO0_10 Bit Fields                 ------ */
#define LPC_IOCON_SWCLK_PIO0_10_FUNC_MASK        (0x7U)                                              /*!< LPC_IOCON_SWCLK_PIO0_10.FUNC Mask       */
#define LPC_IOCON_SWCLK_PIO0_10_FUNC_SHIFT       (0U)                                                /*!< LPC_IOCON_SWCLK_PIO0_10.FUNC Position   */
#define LPC_IOCON_SWCLK_PIO0_10_FUNC(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_SWCLK_PIO0_10.FUNC Field      */
#define LPC_IOCON_SWCLK_PIO0_10_MODE_MASK        (0x18U)                                             /*!< LPC_IOCON_SWCLK_PIO0_10.MODE Mask       */
#define LPC_IOCON_SWCLK_PIO0_10_MODE_SHIFT       (3U)                                                /*!< LPC_IOCON_SWCLK_PIO0_10.MODE Position   */
#define LPC_IOCON_SWCLK_PIO0_10_MODE(x)          (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_SWCLK_PIO0_10.MODE Field      */
#define LPC_IOCON_SWCLK_PIO0_10_HYS_MASK         (0x20U)                                             /*!< LPC_IOCON_SWCLK_PIO0_10.HYS Mask        */
#define LPC_IOCON_SWCLK_PIO0_10_HYS_SHIFT        (5U)                                                /*!< LPC_IOCON_SWCLK_PIO0_10.HYS Position    */
#define LPC_IOCON_SWCLK_PIO0_10_HYS(x)           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_SWCLK_PIO0_10.HYS Field       */
#define LPC_IOCON_SWCLK_PIO0_10_OD_MASK          (0x400U)                                            /*!< LPC_IOCON_SWCLK_PIO0_10.OD Mask         */
#define LPC_IOCON_SWCLK_PIO0_10_OD_SHIFT         (10U)                                               /*!< LPC_IOCON_SWCLK_PIO0_10.OD Position     */
#define LPC_IOCON_SWCLK_PIO0_10_OD(x)            (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_SWCLK_PIO0_10.OD Field        */
/* ------- PIO1_10 Bit Fields                       ------ */
#define LPC_IOCON_PIO1_10_FUNC_MASK              (0x7U)                                              /*!< LPC_IOCON_PIO1_10.FUNC Mask             */
#define LPC_IOCON_PIO1_10_FUNC_SHIFT             (0U)                                                /*!< LPC_IOCON_PIO1_10.FUNC Position         */
#define LPC_IOCON_PIO1_10_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO1_10.FUNC Field            */
#define LPC_IOCON_PIO1_10_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO1_10.MODE Mask             */
#define LPC_IOCON_PIO1_10_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO1_10.MODE Position         */
#define LPC_IOCON_PIO1_10_MODE(x)                (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO1_10.MODE Field            */
#define LPC_IOCON_PIO1_10_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO1_10.HYS Mask              */
#define LPC_IOCON_PIO1_10_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO1_10.HYS Position          */
#define LPC_IOCON_PIO1_10_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO1_10.HYS Field             */
#define LPC_IOCON_PIO1_10_ADMODE_MASK            (0x80U)                                             /*!< LPC_IOCON_PIO1_10.ADMODE Mask           */
#define LPC_IOCON_PIO1_10_ADMODE_SHIFT           (7U)                                                /*!< LPC_IOCON_PIO1_10.ADMODE Position       */
#define LPC_IOCON_PIO1_10_ADMODE(x)              (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_IOCON_PIO1_10.ADMODE Field          */
#define LPC_IOCON_PIO1_10_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO1_10.OD Mask               */
#define LPC_IOCON_PIO1_10_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO1_10.OD Position           */
#define LPC_IOCON_PIO1_10_OD(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO1_10.OD Field              */
/* ------- PIO2_11 Bit Fields                       ------ */
#define LPC_IOCON_PIO2_11_FUNC_MASK              (0x7U)                                              /*!< LPC_IOCON_PIO2_11.FUNC Mask             */
#define LPC_IOCON_PIO2_11_FUNC_SHIFT             (0U)                                                /*!< LPC_IOCON_PIO2_11.FUNC Position         */
#define LPC_IOCON_PIO2_11_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_11.FUNC Field            */
#define LPC_IOCON_PIO2_11_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO2_11.MODE Mask             */
#define LPC_IOCON_PIO2_11_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO2_11.MODE Position         */
#define LPC_IOCON_PIO2_11_MODE(x)                (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_11.MODE Field            */
#define LPC_IOCON_PIO2_11_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO2_11.HYS Mask              */
#define LPC_IOCON_PIO2_11_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO2_11.HYS Position          */
#define LPC_IOCON_PIO2_11_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_11.HYS Field             */
#define LPC_IOCON_PIO2_11_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO2_11.OD Mask               */
#define LPC_IOCON_PIO2_11_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO2_11.OD Position           */
#define LPC_IOCON_PIO2_11_OD(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_11.OD Field              */
/* ------- R_PIO0_11 Bit Fields                     ------ */
#define LPC_IOCON_R_PIO0_11_FUNC_MASK            (0x7U)                                              /*!< LPC_IOCON_R_PIO0_11.FUNC Mask           */
#define LPC_IOCON_R_PIO0_11_FUNC_SHIFT           (0U)                                                /*!< LPC_IOCON_R_PIO0_11.FUNC Position       */
#define LPC_IOCON_R_PIO0_11_FUNC(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_R_PIO0_11.FUNC Field          */
#define LPC_IOCON_R_PIO0_11_MODE_MASK            (0x18U)                                             /*!< LPC_IOCON_R_PIO0_11.MODE Mask           */
#define LPC_IOCON_R_PIO0_11_MODE_SHIFT           (3U)                                                /*!< LPC_IOCON_R_PIO0_11.MODE Position       */
#define LPC_IOCON_R_PIO0_11_MODE(x)              (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_R_PIO0_11.MODE Field          */
#define LPC_IOCON_R_PIO0_11_HYS_MASK             (0x20U)                                             /*!< LPC_IOCON_R_PIO0_11.HYS Mask            */
#define LPC_IOCON_R_PIO0_11_HYS_SHIFT            (5U)                                                /*!< LPC_IOCON_R_PIO0_11.HYS Position        */
#define LPC_IOCON_R_PIO0_11_HYS(x)               (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_R_PIO0_11.HYS Field           */
#define LPC_IOCON_R_PIO0_11_ADMODE_MASK          (0x80U)                                             /*!< LPC_IOCON_R_PIO0_11.ADMODE Mask         */
#define LPC_IOCON_R_PIO0_11_ADMODE_SHIFT         (7U)                                                /*!< LPC_IOCON_R_PIO0_11.ADMODE Position     */
#define LPC_IOCON_R_PIO0_11_ADMODE(x)            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_IOCON_R_PIO0_11.ADMODE Field        */
#define LPC_IOCON_R_PIO0_11_OD_MASK              (0x400U)                                            /*!< LPC_IOCON_R_PIO0_11.OD Mask             */
#define LPC_IOCON_R_PIO0_11_OD_SHIFT             (10U)                                               /*!< LPC_IOCON_R_PIO0_11.OD Position         */
#define LPC_IOCON_R_PIO0_11_OD(x)                (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_R_PIO0_11.OD Field            */
/* ------- R_PIO1_0 Bit Fields                      ------ */
#define LPC_IOCON_R_PIO1_0_FUNC_MASK             (0x7U)                                              /*!< LPC_IOCON_R_PIO1_0.FUNC Mask            */
#define LPC_IOCON_R_PIO1_0_FUNC_SHIFT            (0U)                                                /*!< LPC_IOCON_R_PIO1_0.FUNC Position        */
#define LPC_IOCON_R_PIO1_0_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_R_PIO1_0.FUNC Field           */
#define LPC_IOCON_R_PIO1_0_MODE_MASK             (0x18U)                                             /*!< LPC_IOCON_R_PIO1_0.MODE Mask            */
#define LPC_IOCON_R_PIO1_0_MODE_SHIFT            (3U)                                                /*!< LPC_IOCON_R_PIO1_0.MODE Position        */
#define LPC_IOCON_R_PIO1_0_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_R_PIO1_0.MODE Field           */
#define LPC_IOCON_R_PIO1_0_HYS_MASK              (0x20U)                                             /*!< LPC_IOCON_R_PIO1_0.HYS Mask             */
#define LPC_IOCON_R_PIO1_0_HYS_SHIFT             (5U)                                                /*!< LPC_IOCON_R_PIO1_0.HYS Position         */
#define LPC_IOCON_R_PIO1_0_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_R_PIO1_0.HYS Field            */
#define LPC_IOCON_R_PIO1_0_ADMODE_MASK           (0x80U)                                             /*!< LPC_IOCON_R_PIO1_0.ADMODE Mask          */
#define LPC_IOCON_R_PIO1_0_ADMODE_SHIFT          (7U)                                                /*!< LPC_IOCON_R_PIO1_0.ADMODE Position      */
#define LPC_IOCON_R_PIO1_0_ADMODE(x)             (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_IOCON_R_PIO1_0.ADMODE Field         */
#define LPC_IOCON_R_PIO1_0_OD_MASK               (0x400U)                                            /*!< LPC_IOCON_R_PIO1_0.OD Mask              */
#define LPC_IOCON_R_PIO1_0_OD_SHIFT              (10U)                                               /*!< LPC_IOCON_R_PIO1_0.OD Position          */
#define LPC_IOCON_R_PIO1_0_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_R_PIO1_0.OD Field             */
/* ------- R_PIO1_1 Bit Fields                      ------ */
#define LPC_IOCON_R_PIO1_1_FUNC_MASK             (0x7U)                                              /*!< LPC_IOCON_R_PIO1_1.FUNC Mask            */
#define LPC_IOCON_R_PIO1_1_FUNC_SHIFT            (0U)                                                /*!< LPC_IOCON_R_PIO1_1.FUNC Position        */
#define LPC_IOCON_R_PIO1_1_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_R_PIO1_1.FUNC Field           */
#define LPC_IOCON_R_PIO1_1_MODE_MASK             (0x18U)                                             /*!< LPC_IOCON_R_PIO1_1.MODE Mask            */
#define LPC_IOCON_R_PIO1_1_MODE_SHIFT            (3U)                                                /*!< LPC_IOCON_R_PIO1_1.MODE Position        */
#define LPC_IOCON_R_PIO1_1_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_R_PIO1_1.MODE Field           */
#define LPC_IOCON_R_PIO1_1_HYS_MASK              (0x20U)                                             /*!< LPC_IOCON_R_PIO1_1.HYS Mask             */
#define LPC_IOCON_R_PIO1_1_HYS_SHIFT             (5U)                                                /*!< LPC_IOCON_R_PIO1_1.HYS Position         */
#define LPC_IOCON_R_PIO1_1_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_R_PIO1_1.HYS Field            */
#define LPC_IOCON_R_PIO1_1_ADMODE_MASK           (0x80U)                                             /*!< LPC_IOCON_R_PIO1_1.ADMODE Mask          */
#define LPC_IOCON_R_PIO1_1_ADMODE_SHIFT          (7U)                                                /*!< LPC_IOCON_R_PIO1_1.ADMODE Position      */
#define LPC_IOCON_R_PIO1_1_ADMODE(x)             (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_IOCON_R_PIO1_1.ADMODE Field         */
#define LPC_IOCON_R_PIO1_1_OD_MASK               (0x400U)                                            /*!< LPC_IOCON_R_PIO1_1.OD Mask              */
#define LPC_IOCON_R_PIO1_1_OD_SHIFT              (10U)                                               /*!< LPC_IOCON_R_PIO1_1.OD Position          */
#define LPC_IOCON_R_PIO1_1_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_R_PIO1_1.OD Field             */
/* ------- R_PIO1_2 Bit Fields                      ------ */
#define LPC_IOCON_R_PIO1_2_FUNC_MASK             (0x7U)                                              /*!< LPC_IOCON_R_PIO1_2.FUNC Mask            */
#define LPC_IOCON_R_PIO1_2_FUNC_SHIFT            (0U)                                                /*!< LPC_IOCON_R_PIO1_2.FUNC Position        */
#define LPC_IOCON_R_PIO1_2_FUNC(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_R_PIO1_2.FUNC Field           */
#define LPC_IOCON_R_PIO1_2_MODE_MASK             (0x18U)                                             /*!< LPC_IOCON_R_PIO1_2.MODE Mask            */
#define LPC_IOCON_R_PIO1_2_MODE_SHIFT            (3U)                                                /*!< LPC_IOCON_R_PIO1_2.MODE Position        */
#define LPC_IOCON_R_PIO1_2_MODE(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_R_PIO1_2.MODE Field           */
#define LPC_IOCON_R_PIO1_2_HYS_MASK              (0x20U)                                             /*!< LPC_IOCON_R_PIO1_2.HYS Mask             */
#define LPC_IOCON_R_PIO1_2_HYS_SHIFT             (5U)                                                /*!< LPC_IOCON_R_PIO1_2.HYS Position         */
#define LPC_IOCON_R_PIO1_2_HYS(x)                (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_R_PIO1_2.HYS Field            */
#define LPC_IOCON_R_PIO1_2_ADMODE_MASK           (0x80U)                                             /*!< LPC_IOCON_R_PIO1_2.ADMODE Mask          */
#define LPC_IOCON_R_PIO1_2_ADMODE_SHIFT          (7U)                                                /*!< LPC_IOCON_R_PIO1_2.ADMODE Position      */
#define LPC_IOCON_R_PIO1_2_ADMODE(x)             (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_IOCON_R_PIO1_2.ADMODE Field         */
#define LPC_IOCON_R_PIO1_2_OD_MASK               (0x400U)                                            /*!< LPC_IOCON_R_PIO1_2.OD Mask              */
#define LPC_IOCON_R_PIO1_2_OD_SHIFT              (10U)                                               /*!< LPC_IOCON_R_PIO1_2.OD Position          */
#define LPC_IOCON_R_PIO1_2_OD(x)                 (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_R_PIO1_2.OD Field             */
/* ------- PIO3_0 Bit Fields                        ------ */
#define LPC_IOCON_PIO3_0_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO3_0.FUNC Mask              */
#define LPC_IOCON_PIO3_0_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO3_0.FUNC Position          */
#define LPC_IOCON_PIO3_0_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO3_0.FUNC Field             */
#define LPC_IOCON_PIO3_0_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO3_0.MODE Mask              */
#define LPC_IOCON_PIO3_0_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO3_0.MODE Position          */
#define LPC_IOCON_PIO3_0_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO3_0.MODE Field             */
#define LPC_IOCON_PIO3_0_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO3_0.HYS Mask               */
#define LPC_IOCON_PIO3_0_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO3_0.HYS Position           */
#define LPC_IOCON_PIO3_0_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO3_0.HYS Field              */
#define LPC_IOCON_PIO3_0_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO3_0.OD Mask                */
#define LPC_IOCON_PIO3_0_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO3_0.OD Position            */
#define LPC_IOCON_PIO3_0_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO3_0.OD Field               */
/* ------- PIO3_1 Bit Fields                        ------ */
#define LPC_IOCON_PIO3_1_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO3_1.FUNC Mask              */
#define LPC_IOCON_PIO3_1_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO3_1.FUNC Position          */
#define LPC_IOCON_PIO3_1_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO3_1.FUNC Field             */
#define LPC_IOCON_PIO3_1_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO3_1.MODE Mask              */
#define LPC_IOCON_PIO3_1_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO3_1.MODE Position          */
#define LPC_IOCON_PIO3_1_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO3_1.MODE Field             */
#define LPC_IOCON_PIO3_1_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO3_1.HYS Mask               */
#define LPC_IOCON_PIO3_1_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO3_1.HYS Position           */
#define LPC_IOCON_PIO3_1_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO3_1.HYS Field              */
#define LPC_IOCON_PIO3_1_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO3_1.OD Mask                */
#define LPC_IOCON_PIO3_1_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO3_1.OD Position            */
#define LPC_IOCON_PIO3_1_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO3_1.OD Field               */
/* ------- PIO2_3 Bit Fields                        ------ */
#define LPC_IOCON_PIO2_3_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO2_3.FUNC Mask              */
#define LPC_IOCON_PIO2_3_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO2_3.FUNC Position          */
#define LPC_IOCON_PIO2_3_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO2_3.FUNC Field             */
#define LPC_IOCON_PIO2_3_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO2_3.MODE Mask              */
#define LPC_IOCON_PIO2_3_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO2_3.MODE Position          */
#define LPC_IOCON_PIO2_3_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO2_3.MODE Field             */
#define LPC_IOCON_PIO2_3_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO2_3.HYS Mask               */
#define LPC_IOCON_PIO2_3_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO2_3.HYS Position           */
#define LPC_IOCON_PIO2_3_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO2_3.HYS Field              */
#define LPC_IOCON_PIO2_3_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO2_3.OD Mask                */
#define LPC_IOCON_PIO2_3_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO2_3.OD Position            */
#define LPC_IOCON_PIO2_3_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO2_3.OD Field               */
/* ------- SWDIO_PIO1_3 Bit Fields                  ------ */
#define LPC_IOCON_SWDIO_PIO1_3_FUNC_MASK         (0x7U)                                              /*!< LPC_IOCON_SWDIO_PIO1_3.FUNC Mask        */
#define LPC_IOCON_SWDIO_PIO1_3_FUNC_SHIFT        (0U)                                                /*!< LPC_IOCON_SWDIO_PIO1_3.FUNC Position    */
#define LPC_IOCON_SWDIO_PIO1_3_FUNC(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_SWDIO_PIO1_3.FUNC Field       */
#define LPC_IOCON_SWDIO_PIO1_3_MODE_MASK         (0x18U)                                             /*!< LPC_IOCON_SWDIO_PIO1_3.MODE Mask        */
#define LPC_IOCON_SWDIO_PIO1_3_MODE_SHIFT        (3U)                                                /*!< LPC_IOCON_SWDIO_PIO1_3.MODE Position    */
#define LPC_IOCON_SWDIO_PIO1_3_MODE(x)           (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_SWDIO_PIO1_3.MODE Field       */
#define LPC_IOCON_SWDIO_PIO1_3_HYS_MASK          (0x20U)                                             /*!< LPC_IOCON_SWDIO_PIO1_3.HYS Mask         */
#define LPC_IOCON_SWDIO_PIO1_3_HYS_SHIFT         (5U)                                                /*!< LPC_IOCON_SWDIO_PIO1_3.HYS Position     */
#define LPC_IOCON_SWDIO_PIO1_3_HYS(x)            (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_SWDIO_PIO1_3.HYS Field        */
#define LPC_IOCON_SWDIO_PIO1_3_ADMODE_MASK       (0x80U)                                             /*!< LPC_IOCON_SWDIO_PIO1_3.ADMODE Mask      */
#define LPC_IOCON_SWDIO_PIO1_3_ADMODE_SHIFT      (7U)                                                /*!< LPC_IOCON_SWDIO_PIO1_3.ADMODE Position  */
#define LPC_IOCON_SWDIO_PIO1_3_ADMODE(x)         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_IOCON_SWDIO_PIO1_3.ADMODE Field     */
#define LPC_IOCON_SWDIO_PIO1_3_OD_MASK           (0x400U)                                            /*!< LPC_IOCON_SWDIO_PIO1_3.OD Mask          */
#define LPC_IOCON_SWDIO_PIO1_3_OD_SHIFT          (10U)                                               /*!< LPC_IOCON_SWDIO_PIO1_3.OD Position      */
#define LPC_IOCON_SWDIO_PIO1_3_OD(x)             (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_SWDIO_PIO1_3.OD Field         */
/* ------- PIO1_4 Bit Fields                        ------ */
#define LPC_IOCON_PIO1_4_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO1_4.FUNC Mask              */
#define LPC_IOCON_PIO1_4_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO1_4.FUNC Position          */
#define LPC_IOCON_PIO1_4_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO1_4.FUNC Field             */
#define LPC_IOCON_PIO1_4_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO1_4.MODE Mask              */
#define LPC_IOCON_PIO1_4_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO1_4.MODE Position          */
#define LPC_IOCON_PIO1_4_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO1_4.MODE Field             */
#define LPC_IOCON_PIO1_4_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO1_4.HYS Mask               */
#define LPC_IOCON_PIO1_4_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO1_4.HYS Position           */
#define LPC_IOCON_PIO1_4_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO1_4.HYS Field              */
#define LPC_IOCON_PIO1_4_ADMODE_MASK             (0x80U)                                             /*!< LPC_IOCON_PIO1_4.ADMODE Mask            */
#define LPC_IOCON_PIO1_4_ADMODE_SHIFT            (7U)                                                /*!< LPC_IOCON_PIO1_4.ADMODE Position        */
#define LPC_IOCON_PIO1_4_ADMODE(x)               (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_IOCON_PIO1_4.ADMODE Field           */
#define LPC_IOCON_PIO1_4_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO1_4.OD Mask                */
#define LPC_IOCON_PIO1_4_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO1_4.OD Position            */
#define LPC_IOCON_PIO1_4_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO1_4.OD Field               */
/* ------- PIO1_11 Bit Fields                       ------ */
#define LPC_IOCON_PIO1_11_FUNC_MASK              (0x7U)                                              /*!< LPC_IOCON_PIO1_11.FUNC Mask             */
#define LPC_IOCON_PIO1_11_FUNC_SHIFT             (0U)                                                /*!< LPC_IOCON_PIO1_11.FUNC Position         */
#define LPC_IOCON_PIO1_11_FUNC(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO1_11.FUNC Field            */
#define LPC_IOCON_PIO1_11_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO1_11.MODE Mask             */
#define LPC_IOCON_PIO1_11_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO1_11.MODE Position         */
#define LPC_IOCON_PIO1_11_MODE(x)                (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO1_11.MODE Field            */
#define LPC_IOCON_PIO1_11_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO1_11.HYS Mask              */
#define LPC_IOCON_PIO1_11_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO1_11.HYS Position          */
#define LPC_IOCON_PIO1_11_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO1_11.HYS Field             */
#define LPC_IOCON_PIO1_11_ADMODE_MASK            (0x80U)                                             /*!< LPC_IOCON_PIO1_11.ADMODE Mask           */
#define LPC_IOCON_PIO1_11_ADMODE_SHIFT           (7U)                                                /*!< LPC_IOCON_PIO1_11.ADMODE Position       */
#define LPC_IOCON_PIO1_11_ADMODE(x)              (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_IOCON_PIO1_11.ADMODE Field          */
#define LPC_IOCON_PIO1_11_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO1_11.OD Mask               */
#define LPC_IOCON_PIO1_11_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO1_11.OD Position           */
#define LPC_IOCON_PIO1_11_OD(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO1_11.OD Field              */
/* ------- PIO3_2 Bit Fields                        ------ */
#define LPC_IOCON_PIO3_2_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO3_2.FUNC Mask              */
#define LPC_IOCON_PIO3_2_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO3_2.FUNC Position          */
#define LPC_IOCON_PIO3_2_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO3_2.FUNC Field             */
#define LPC_IOCON_PIO3_2_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO3_2.MODE Mask              */
#define LPC_IOCON_PIO3_2_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO3_2.MODE Position          */
#define LPC_IOCON_PIO3_2_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO3_2.MODE Field             */
#define LPC_IOCON_PIO3_2_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO3_2.HYS Mask               */
#define LPC_IOCON_PIO3_2_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO3_2.HYS Position           */
#define LPC_IOCON_PIO3_2_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO3_2.HYS Field              */
#define LPC_IOCON_PIO3_2_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO3_2.OD Mask                */
#define LPC_IOCON_PIO3_2_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO3_2.OD Position            */
#define LPC_IOCON_PIO3_2_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO3_2.OD Field               */
/* ------- PIO1_5 Bit Fields                        ------ */
#define LPC_IOCON_PIO1_5_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO1_5.FUNC Mask              */
#define LPC_IOCON_PIO1_5_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO1_5.FUNC Position          */
#define LPC_IOCON_PIO1_5_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO1_5.FUNC Field             */
#define LPC_IOCON_PIO1_5_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO1_5.MODE Mask              */
#define LPC_IOCON_PIO1_5_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO1_5.MODE Position          */
#define LPC_IOCON_PIO1_5_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO1_5.MODE Field             */
#define LPC_IOCON_PIO1_5_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO1_5.HYS Mask               */
#define LPC_IOCON_PIO1_5_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO1_5.HYS Position           */
#define LPC_IOCON_PIO1_5_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO1_5.HYS Field              */
#define LPC_IOCON_PIO1_5_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO1_5.OD Mask                */
#define LPC_IOCON_PIO1_5_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO1_5.OD Position            */
#define LPC_IOCON_PIO1_5_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO1_5.OD Field               */
/* ------- PIO1_6 Bit Fields                        ------ */
#define LPC_IOCON_PIO1_6_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO1_6.FUNC Mask              */
#define LPC_IOCON_PIO1_6_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO1_6.FUNC Position          */
#define LPC_IOCON_PIO1_6_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO1_6.FUNC Field             */
#define LPC_IOCON_PIO1_6_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO1_6.MODE Mask              */
#define LPC_IOCON_PIO1_6_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO1_6.MODE Position          */
#define LPC_IOCON_PIO1_6_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO1_6.MODE Field             */
#define LPC_IOCON_PIO1_6_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO1_6.HYS Mask               */
#define LPC_IOCON_PIO1_6_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO1_6.HYS Position           */
#define LPC_IOCON_PIO1_6_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO1_6.HYS Field              */
#define LPC_IOCON_PIO1_6_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO1_6.OD Mask                */
#define LPC_IOCON_PIO1_6_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO1_6.OD Position            */
#define LPC_IOCON_PIO1_6_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO1_6.OD Field               */
/* ------- PIO1_7 Bit Fields                        ------ */
#define LPC_IOCON_PIO1_7_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO1_7.FUNC Mask              */
#define LPC_IOCON_PIO1_7_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO1_7.FUNC Position          */
#define LPC_IOCON_PIO1_7_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO1_7.FUNC Field             */
#define LPC_IOCON_PIO1_7_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO1_7.MODE Mask              */
#define LPC_IOCON_PIO1_7_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO1_7.MODE Position          */
#define LPC_IOCON_PIO1_7_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO1_7.MODE Field             */
#define LPC_IOCON_PIO1_7_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO1_7.HYS Mask               */
#define LPC_IOCON_PIO1_7_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO1_7.HYS Position           */
#define LPC_IOCON_PIO1_7_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO1_7.HYS Field              */
#define LPC_IOCON_PIO1_7_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO1_7.OD Mask                */
#define LPC_IOCON_PIO1_7_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO1_7.OD Position            */
#define LPC_IOCON_PIO1_7_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO1_7.OD Field               */
/* ------- PIO3_3 Bit Fields                        ------ */
#define LPC_IOCON_PIO3_3_FUNC_MASK               (0x7U)                                              /*!< LPC_IOCON_PIO3_3.FUNC Mask              */
#define LPC_IOCON_PIO3_3_FUNC_SHIFT              (0U)                                                /*!< LPC_IOCON_PIO3_3.FUNC Position          */
#define LPC_IOCON_PIO3_3_FUNC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_IOCON_PIO3_3.FUNC Field             */
#define LPC_IOCON_PIO3_3_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO3_3.MODE Mask              */
#define LPC_IOCON_PIO3_3_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO3_3.MODE Position          */
#define LPC_IOCON_PIO3_3_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< LPC_IOCON_PIO3_3.MODE Field             */
#define LPC_IOCON_PIO3_3_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO3_3.HYS Mask               */
#define LPC_IOCON_PIO3_3_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO3_3.HYS Position           */
#define LPC_IOCON_PIO3_3_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_IOCON_PIO3_3.HYS Field              */
#define LPC_IOCON_PIO3_3_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO3_3.OD Mask                */
#define LPC_IOCON_PIO3_3_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO3_3.OD Position            */
#define LPC_IOCON_PIO3_3_OD(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_IOCON_PIO3_3.OD Field               */
/* ------- SCK0_LOC Bit Fields                      ------ */
#define LPC_IOCON_SCK0_LOC_SCKLOC_MASK           (0x3U)                                              /*!< LPC_IOCON_SCK0_LOC.SCKLOC Mask          */
#define LPC_IOCON_SCK0_LOC_SCKLOC_SHIFT          (0U)                                                /*!< LPC_IOCON_SCK0_LOC.SCKLOC Position      */
#define LPC_IOCON_SCK0_LOC_SCKLOC(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_IOCON_SCK0_LOC.SCKLOC Field         */
/* ------- DSR_LOC Bit Fields                       ------ */
#define LPC_IOCON_DSR_LOC_DSRLOC_MASK            (0x3U)                                              /*!< LPC_IOCON_DSR_LOC.DSRLOC Mask           */
#define LPC_IOCON_DSR_LOC_DSRLOC_SHIFT           (0U)                                                /*!< LPC_IOCON_DSR_LOC.DSRLOC Position       */
#define LPC_IOCON_DSR_LOC_DSRLOC(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_IOCON_DSR_LOC.DSRLOC Field          */
/* ------- DCD_LOC Bit Fields                       ------ */
#define LPC_IOCON_DCD_LOC_DCDLOC_MASK            (0x3U)                                              /*!< LPC_IOCON_DCD_LOC.DCDLOC Mask           */
#define LPC_IOCON_DCD_LOC_DCDLOC_SHIFT           (0U)                                                /*!< LPC_IOCON_DCD_LOC.DCDLOC Position       */
#define LPC_IOCON_DCD_LOC_DCDLOC(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_IOCON_DCD_LOC.DCDLOC Field          */
/* ------- RI_LOC Bit Fields                        ------ */
#define LPC_IOCON_RI_LOC_RILOC_MASK              (0x3U)                                              /*!< LPC_IOCON_RI_LOC.RILOC Mask             */
#define LPC_IOCON_RI_LOC_RILOC_SHIFT             (0U)                                                /*!< LPC_IOCON_RI_LOC.RILOC Position         */
#define LPC_IOCON_RI_LOC_RILOC(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_IOCON_RI_LOC.RILOC Field            */
/**
 * @} */ /* End group IOCON_Register_Masks_GROUP 
 */

/* LPC_IOCON - Peripheral instance base addresses */
#define LPC_IOCON_BasePtr              0x40044000UL //!< Peripheral base address
#define LPC_IOCON                      ((LPC_IOCON_Type *) LPC_IOCON_BasePtr) //!< Freescale base pointer
#define LPC_IOCON_BASE_PTR             (LPC_IOCON) //!< Freescale style base pointer
/**
 * @} */ /* End group IOCON_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMU_Peripheral_access_layer_GROUP PMU Peripheral Access Layer
* @brief C Struct for PMU
* @{
*/

/* ================================================================================ */
/* ================           LPC_PMU (file:PMU_LPC13xx)           ================ */
/* ================================================================================ */

/**
 * @brief Power Management Unit
 */
/**
* @addtogroup PMU_structs_GROUP PMU struct
* @brief Struct for PMU
* @{
*/
typedef struct LPC_PMU_Type {
   __IO uint32_t  PCON;                         /**< 0000: Power control register                                       */
   __IO uint32_t  GPREG[4];                     /**< 0004: General purpose register                                     */
   __IO uint32_t  GPREG4;                       /**< 0014: General purpose register 4                                   */
} LPC_PMU_Type;

/**
 * @} */ /* End group PMU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_PMU' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PMU_Register_Masks_GROUP PMU Register Masks
* @brief Register Masks for PMU
* @{
*/
/* ------- PCON Bit Fields                          ------ */
#define LPC_PMU_PCON_DPDEN_MASK                  (0x2U)                                              /*!< LPC_PMU_PCON.DPDEN Mask                 */
#define LPC_PMU_PCON_DPDEN_SHIFT                 (1U)                                                /*!< LPC_PMU_PCON.DPDEN Position             */
#define LPC_PMU_PCON_DPDEN(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_PMU_PCON.DPDEN Field                */
#define LPC_PMU_PCON_SLEEPFLAG_MASK              (0x100U)                                            /*!< LPC_PMU_PCON.SLEEPFLAG Mask             */
#define LPC_PMU_PCON_SLEEPFLAG_SHIFT             (8U)                                                /*!< LPC_PMU_PCON.SLEEPFLAG Position         */
#define LPC_PMU_PCON_SLEEPFLAG(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_PMU_PCON.SLEEPFLAG Field            */
#define LPC_PMU_PCON_DPDFLAG_MASK                (0x800U)                                            /*!< LPC_PMU_PCON.DPDFLAG Mask               */
#define LPC_PMU_PCON_DPDFLAG_SHIFT               (11U)                                               /*!< LPC_PMU_PCON.DPDFLAG Position           */
#define LPC_PMU_PCON_DPDFLAG(x)                  (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_PMU_PCON.DPDFLAG Field              */
/* ------- GPREG Bit Fields                         ------ */
#define LPC_PMU_GPREG_GPDATA_MASK                (0xFFFFFFFFU)                                       /*!< LPC_PMU_GPREG.GPDATA Mask               */
#define LPC_PMU_GPREG_GPDATA_SHIFT               (0U)                                                /*!< LPC_PMU_GPREG.GPDATA Position           */
#define LPC_PMU_GPREG_GPDATA(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_PMU_GPREG.GPDATA Field              */
/* ------- GPREG4 Bit Fields                        ------ */
#define LPC_PMU_GPREG4_WAKEUPHYS_MASK            (0x400U)                                            /*!< LPC_PMU_GPREG4.WAKEUPHYS Mask           */
#define LPC_PMU_GPREG4_WAKEUPHYS_SHIFT           (10U)                                               /*!< LPC_PMU_GPREG4.WAKEUPHYS Position       */
#define LPC_PMU_GPREG4_WAKEUPHYS(x)              (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_PMU_GPREG4.WAKEUPHYS Field          */
#define LPC_PMU_GPREG4_GPDATA_MASK               (0xFFFFF800U)                                       /*!< LPC_PMU_GPREG4.GPDATA Mask              */
#define LPC_PMU_GPREG4_GPDATA_SHIFT              (11U)                                               /*!< LPC_PMU_GPREG4.GPDATA Position          */
#define LPC_PMU_GPREG4_GPDATA(x)                 (((uint32_t)(((uint32_t)(x))<<11U))&0xFFFFF800UL)   /*!< LPC_PMU_GPREG4.GPDATA Field             */
/**
 * @} */ /* End group PMU_Register_Masks_GROUP 
 */

/* LPC_PMU - Peripheral instance base addresses */
#define LPC_PMU_BasePtr                0x40038000UL //!< Peripheral base address
#define LPC_PMU                        ((LPC_PMU_Type *) LPC_PMU_BasePtr) //!< Freescale base pointer
#define LPC_PMU_BASE_PTR               (LPC_PMU) //!< Freescale style base pointer
/**
 * @} */ /* End group PMU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SSP0_Peripheral_access_layer_GROUP SSP0 Peripheral Access Layer
* @brief C Struct for SSP0
* @{
*/

/* ================================================================================ */
/* ================           LPC_SSP0 (file:SSP0_LPC13xx)         ================ */
/* ================================================================================ */

/**
 * @brief SSP0/1
 */
/**
* @addtogroup SSP0_structs_GROUP SSP0 struct
* @brief Struct for SSP0
* @{
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

/**
 * @} */ /* End group SSP0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_SSP0' Position & Mask macros                    ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SSP0_Register_Masks_GROUP SSP0 Register Masks
* @brief Register Masks for SSP0
* @{
*/
/* ------- CR0 Bit Fields                           ------ */
#define LPC_SSP0_CR0_DSS_MASK                    (0xFU)                                              /*!< LPC_SSP0_CR0.DSS Mask                   */
#define LPC_SSP0_CR0_DSS_SHIFT                   (0U)                                                /*!< LPC_SSP0_CR0.DSS Position               */
#define LPC_SSP0_CR0_DSS(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< LPC_SSP0_CR0.DSS Field                  */
#define LPC_SSP0_CR0_FRF_MASK                    (0x30U)                                             /*!< LPC_SSP0_CR0.FRF Mask                   */
#define LPC_SSP0_CR0_FRF_SHIFT                   (4U)                                                /*!< LPC_SSP0_CR0.FRF Position               */
#define LPC_SSP0_CR0_FRF(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< LPC_SSP0_CR0.FRF Field                  */
#define LPC_SSP0_CR0_CPOL_MASK                   (0x40U)                                             /*!< LPC_SSP0_CR0.CPOL Mask                  */
#define LPC_SSP0_CR0_CPOL_SHIFT                  (6U)                                                /*!< LPC_SSP0_CR0.CPOL Position              */
#define LPC_SSP0_CR0_CPOL(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SSP0_CR0.CPOL Field                 */
#define LPC_SSP0_CR0_CPHA_MASK                   (0x80U)                                             /*!< LPC_SSP0_CR0.CPHA Mask                  */
#define LPC_SSP0_CR0_CPHA_SHIFT                  (7U)                                                /*!< LPC_SSP0_CR0.CPHA Position              */
#define LPC_SSP0_CR0_CPHA(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SSP0_CR0.CPHA Field                 */
#define LPC_SSP0_CR0_SCR_MASK                    (0xFF00U)                                           /*!< LPC_SSP0_CR0.SCR Mask                   */
#define LPC_SSP0_CR0_SCR_SHIFT                   (8U)                                                /*!< LPC_SSP0_CR0.SCR Position               */
#define LPC_SSP0_CR0_SCR(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< LPC_SSP0_CR0.SCR Field                  */
/* ------- CR1 Bit Fields                           ------ */
#define LPC_SSP0_CR1_LBM_MASK                    (0x1U)                                              /*!< LPC_SSP0_CR1.LBM Mask                   */
#define LPC_SSP0_CR1_LBM_SHIFT                   (0U)                                                /*!< LPC_SSP0_CR1.LBM Position               */
#define LPC_SSP0_CR1_LBM(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SSP0_CR1.LBM Field                  */
#define LPC_SSP0_CR1_SSE_MASK                    (0x2U)                                              /*!< LPC_SSP0_CR1.SSE Mask                   */
#define LPC_SSP0_CR1_SSE_SHIFT                   (1U)                                                /*!< LPC_SSP0_CR1.SSE Position               */
#define LPC_SSP0_CR1_SSE(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SSP0_CR1.SSE Field                  */
#define LPC_SSP0_CR1_MS_MASK                     (0x4U)                                              /*!< LPC_SSP0_CR1.MS Mask                    */
#define LPC_SSP0_CR1_MS_SHIFT                    (2U)                                                /*!< LPC_SSP0_CR1.MS Position                */
#define LPC_SSP0_CR1_MS(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SSP0_CR1.MS Field                   */
#define LPC_SSP0_CR1_SOD_MASK                    (0x8U)                                              /*!< LPC_SSP0_CR1.SOD Mask                   */
#define LPC_SSP0_CR1_SOD_SHIFT                   (3U)                                                /*!< LPC_SSP0_CR1.SOD Position               */
#define LPC_SSP0_CR1_SOD(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SSP0_CR1.SOD Field                  */
/* ------- DR Bit Fields                            ------ */
#define LPC_SSP0_DR_DATA_MASK                    (0xFFFFU)                                           /*!< LPC_SSP0_DR.DATA Mask                   */
#define LPC_SSP0_DR_DATA_SHIFT                   (0U)                                                /*!< LPC_SSP0_DR.DATA Position               */
#define LPC_SSP0_DR_DATA(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPC_SSP0_DR.DATA Field                  */
/* ------- SR Bit Fields                            ------ */
#define LPC_SSP0_SR_TFE_MASK                     (0x1U)                                              /*!< LPC_SSP0_SR.TFE Mask                    */
#define LPC_SSP0_SR_TFE_SHIFT                    (0U)                                                /*!< LPC_SSP0_SR.TFE Position                */
#define LPC_SSP0_SR_TFE(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SSP0_SR.TFE Field                   */
#define LPC_SSP0_SR_TNF_MASK                     (0x2U)                                              /*!< LPC_SSP0_SR.TNF Mask                    */
#define LPC_SSP0_SR_TNF_SHIFT                    (1U)                                                /*!< LPC_SSP0_SR.TNF Position                */
#define LPC_SSP0_SR_TNF(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SSP0_SR.TNF Field                   */
#define LPC_SSP0_SR_RNE_MASK                     (0x4U)                                              /*!< LPC_SSP0_SR.RNE Mask                    */
#define LPC_SSP0_SR_RNE_SHIFT                    (2U)                                                /*!< LPC_SSP0_SR.RNE Position                */
#define LPC_SSP0_SR_RNE(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SSP0_SR.RNE Field                   */
#define LPC_SSP0_SR_RFF_MASK                     (0x8U)                                              /*!< LPC_SSP0_SR.RFF Mask                    */
#define LPC_SSP0_SR_RFF_SHIFT                    (3U)                                                /*!< LPC_SSP0_SR.RFF Position                */
#define LPC_SSP0_SR_RFF(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SSP0_SR.RFF Field                   */
#define LPC_SSP0_SR_BSY_MASK                     (0x10U)                                             /*!< LPC_SSP0_SR.BSY Mask                    */
#define LPC_SSP0_SR_BSY_SHIFT                    (4U)                                                /*!< LPC_SSP0_SR.BSY Position                */
#define LPC_SSP0_SR_BSY(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SSP0_SR.BSY Field                   */
/* ------- CPSR Bit Fields                          ------ */
#define LPC_SSP0_CPSR_CPSDVSR_MASK               (0xFFU)                                             /*!< LPC_SSP0_CPSR.CPSDVSR Mask              */
#define LPC_SSP0_CPSR_CPSDVSR_SHIFT              (0U)                                                /*!< LPC_SSP0_CPSR.CPSDVSR Position          */
#define LPC_SSP0_CPSR_CPSDVSR(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SSP0_CPSR.CPSDVSR Field             */
/* ------- IMSC Bit Fields                          ------ */
#define LPC_SSP0_IMSC_RORIM_MASK                 (0x1U)                                              /*!< LPC_SSP0_IMSC.RORIM Mask                */
#define LPC_SSP0_IMSC_RORIM_SHIFT                (0U)                                                /*!< LPC_SSP0_IMSC.RORIM Position            */
#define LPC_SSP0_IMSC_RORIM(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SSP0_IMSC.RORIM Field               */
#define LPC_SSP0_IMSC_RTIM_MASK                  (0x2U)                                              /*!< LPC_SSP0_IMSC.RTIM Mask                 */
#define LPC_SSP0_IMSC_RTIM_SHIFT                 (1U)                                                /*!< LPC_SSP0_IMSC.RTIM Position             */
#define LPC_SSP0_IMSC_RTIM(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SSP0_IMSC.RTIM Field                */
#define LPC_SSP0_IMSC_RXIM_MASK                  (0x4U)                                              /*!< LPC_SSP0_IMSC.RXIM Mask                 */
#define LPC_SSP0_IMSC_RXIM_SHIFT                 (2U)                                                /*!< LPC_SSP0_IMSC.RXIM Position             */
#define LPC_SSP0_IMSC_RXIM(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SSP0_IMSC.RXIM Field                */
#define LPC_SSP0_IMSC_TXIM_MASK                  (0x8U)                                              /*!< LPC_SSP0_IMSC.TXIM Mask                 */
#define LPC_SSP0_IMSC_TXIM_SHIFT                 (3U)                                                /*!< LPC_SSP0_IMSC.TXIM Position             */
#define LPC_SSP0_IMSC_TXIM(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SSP0_IMSC.TXIM Field                */
/* ------- RIS Bit Fields                           ------ */
#define LPC_SSP0_RIS_RORRIS_MASK                 (0x1U)                                              /*!< LPC_SSP0_RIS.RORRIS Mask                */
#define LPC_SSP0_RIS_RORRIS_SHIFT                (0U)                                                /*!< LPC_SSP0_RIS.RORRIS Position            */
#define LPC_SSP0_RIS_RORRIS(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SSP0_RIS.RORRIS Field               */
#define LPC_SSP0_RIS_RTRIS_MASK                  (0x2U)                                              /*!< LPC_SSP0_RIS.RTRIS Mask                 */
#define LPC_SSP0_RIS_RTRIS_SHIFT                 (1U)                                                /*!< LPC_SSP0_RIS.RTRIS Position             */
#define LPC_SSP0_RIS_RTRIS(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SSP0_RIS.RTRIS Field                */
#define LPC_SSP0_RIS_RXRIS_MASK                  (0x4U)                                              /*!< LPC_SSP0_RIS.RXRIS Mask                 */
#define LPC_SSP0_RIS_RXRIS_SHIFT                 (2U)                                                /*!< LPC_SSP0_RIS.RXRIS Position             */
#define LPC_SSP0_RIS_RXRIS(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SSP0_RIS.RXRIS Field                */
#define LPC_SSP0_RIS_TXRIS_MASK                  (0x8U)                                              /*!< LPC_SSP0_RIS.TXRIS Mask                 */
#define LPC_SSP0_RIS_TXRIS_SHIFT                 (3U)                                                /*!< LPC_SSP0_RIS.TXRIS Position             */
#define LPC_SSP0_RIS_TXRIS(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SSP0_RIS.TXRIS Field                */
/* ------- MIS Bit Fields                           ------ */
#define LPC_SSP0_MIS_RORMIS_MASK                 (0x1U)                                              /*!< LPC_SSP0_MIS.RORMIS Mask                */
#define LPC_SSP0_MIS_RORMIS_SHIFT                (0U)                                                /*!< LPC_SSP0_MIS.RORMIS Position            */
#define LPC_SSP0_MIS_RORMIS(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SSP0_MIS.RORMIS Field               */
#define LPC_SSP0_MIS_RTMIS_MASK                  (0x2U)                                              /*!< LPC_SSP0_MIS.RTMIS Mask                 */
#define LPC_SSP0_MIS_RTMIS_SHIFT                 (1U)                                                /*!< LPC_SSP0_MIS.RTMIS Position             */
#define LPC_SSP0_MIS_RTMIS(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SSP0_MIS.RTMIS Field                */
#define LPC_SSP0_MIS_RXMIS_MASK                  (0x4U)                                              /*!< LPC_SSP0_MIS.RXMIS Mask                 */
#define LPC_SSP0_MIS_RXMIS_SHIFT                 (2U)                                                /*!< LPC_SSP0_MIS.RXMIS Position             */
#define LPC_SSP0_MIS_RXMIS(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SSP0_MIS.RXMIS Field                */
#define LPC_SSP0_MIS_TXMIS_MASK                  (0x8U)                                              /*!< LPC_SSP0_MIS.TXMIS Mask                 */
#define LPC_SSP0_MIS_TXMIS_SHIFT                 (3U)                                                /*!< LPC_SSP0_MIS.TXMIS Position             */
#define LPC_SSP0_MIS_TXMIS(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SSP0_MIS.TXMIS Field                */
/* ------- ICR Bit Fields                           ------ */
#define LPC_SSP0_ICR_RORIC_MASK                  (0x1U)                                              /*!< LPC_SSP0_ICR.RORIC Mask                 */
#define LPC_SSP0_ICR_RORIC_SHIFT                 (0U)                                                /*!< LPC_SSP0_ICR.RORIC Position             */
#define LPC_SSP0_ICR_RORIC(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SSP0_ICR.RORIC Field                */
#define LPC_SSP0_ICR_RTIC_MASK                   (0x2U)                                              /*!< LPC_SSP0_ICR.RTIC Mask                  */
#define LPC_SSP0_ICR_RTIC_SHIFT                  (1U)                                                /*!< LPC_SSP0_ICR.RTIC Position              */
#define LPC_SSP0_ICR_RTIC(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SSP0_ICR.RTIC Field                 */
/**
 * @} */ /* End group SSP0_Register_Masks_GROUP 
 */

/* LPC_SSP0 - Peripheral instance base addresses */
#define LPC_SSP0_BasePtr               0x40040000UL //!< Peripheral base address
#define LPC_SSP0                       ((LPC_SSP0_Type *) LPC_SSP0_BasePtr) //!< Freescale base pointer
#define LPC_SSP0_BASE_PTR              (LPC_SSP0) //!< Freescale style base pointer
#define LPC_SSP0_IRQS { SSP0_IRQn,  }

/**
 * @} */ /* End group SSP0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SSP0_Peripheral_access_layer_GROUP SSP0 Peripheral Access Layer
* @brief C Struct for SSP0
* @{
*/

/* ================================================================================ */
/* ================           LPC_SSP1 (derived from SSP0)         ================ */
/* ================================================================================ */

/**
 * @brief SSP0/1
 */

/* LPC_SSP1 - Peripheral instance base addresses */
#define LPC_SSP1_BasePtr               0x40058000UL //!< Peripheral base address
#define LPC_SSP1                       ((LPC_SSP0_Type *) LPC_SSP1_BasePtr) //!< Freescale base pointer
#define LPC_SSP1_BASE_PTR              (LPC_SSP1) //!< Freescale style base pointer
#define LPC_SSP1_IRQS { SSP1_IRQn,  }

/**
 * @} */ /* End group SSP0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SYSCON_Peripheral_access_layer_GROUP SYSCON Peripheral Access Layer
* @brief C Struct for SYSCON
* @{
*/

/* ================================================================================ */
/* ================           LPC_SYSCON (file:SYSCON_LPC13xx)       ================ */
/* ================================================================================ */

/**
 * @brief System configuration
 */
/**
* @addtogroup SYSCON_structs_GROUP SYSCON struct
* @brief Struct for SYSCON
* @{
*/
typedef struct LPC_SYSCON_Type {
   __IO uint32_t  SYSMEMREMAP;                  /**< 0000: System memory remap                                          */
   __IO uint32_t  PRESETCTRL;                   /**< 0004: Peripheral reset control                                     */
   __IO uint32_t  SYSPLLCTRL;                   /**< 0008: System PLL control                                           */
   __I  uint32_t  SYSPLLSTAT;                   /**< 000C: System PLL status                                            */
   __IO uint32_t  USBPLLCTRL;                   /**< 0010: USB PLL control                                              */
   __I  uint32_t  USBPLLSTAT;                   /**< 0014: USB PLL status                                               */
        uint8_t   RESERVED_0[8];               
   __IO uint32_t  SYSOSCCTRL;                   /**< 0020: System oscillator control                                    */
   __IO uint32_t  WDTOSCCTRL;                   /**< 0024: Watchdog oscillator control                                  */
   __IO uint32_t  IRCCTRL;                      /**< 0028: IRC control                                                  */
        uint8_t   RESERVED_1[4];               
   __I  uint32_t  SYSRESSTAT;                   /**< 0030: System reset status register                                 */
        uint8_t   RESERVED_2[12];              
   __IO uint32_t  SYSPLLCLKSEL;                 /**< 0040: System PLL clock source select                               */
   __IO uint32_t  SYSPLLCLKUEN;                 /**< 0044: System PLL clock source update enable                        */
   __IO uint32_t  USBPLLCLKSEL;                 /**< 0048: USB PLL clock source select                                  */
   __IO uint32_t  USBPLLCLKUEN;                 /**< 004C: USB PLL clock source update enable                           */
        uint8_t   RESERVED_3[32];              
   __IO uint32_t  MAINCLKSEL;                   /**< 0070: Main clock source select                                     */
   __IO uint32_t  MAINCLKUEN;                   /**< 0074: Main clock source update enable                              */
   __IO uint32_t  SYSAHBCLKDIV;                 /**< 0078: System AHB clock divider                                     */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  SYSAHBCLKCTRL;                /**< 0080: System AHB clock control                                     */
        uint8_t   RESERVED_5[16];              
   __IO uint32_t  SSP0CLKDIV;                   /**< 0094: SSP clock divder                                             */
   __IO uint32_t  UARTCLKDIV;                   /**< 0098: UART clock divder                                            */
   __IO uint32_t  SSP1CLKDIV;                   /**< 009C: SPISP1 clock divder                                          */
        uint8_t   RESERVED_6[12];              
   __IO uint32_t  TRACECLKDIV;                  /**< 00AC: ARM trace clock divider                                      */
   __IO uint32_t  SYSTICKCLKDIV;                /**< 00B0: SYSTICK clock divder                                         */
        uint8_t   RESERVED_7[12];              
   __IO uint32_t  USBCLKSEL;                    /**< 00C0: USB clock source select                                      */
   __IO uint32_t  USBCLKUEN;                    /**< 00C4: USB clock source update enable                               */
   __IO uint32_t  USBCLKDIV;                    /**< 00C8: USB clock source divider                                     */
        uint8_t   RESERVED_8[4];               
   __IO uint32_t  WDTCLKSEL;                    /**< 00D0: WDT clock source select                                      */
   __IO uint32_t  WDTCLKUEN;                    /**< 00D4: WDT clock source update enable                               */
   __IO uint32_t  WDTCLKDIV;                    /**< 00D8: WDT clock divider                                            */
        uint8_t   RESERVED_9[4];               
   __IO uint32_t  CLKOUTCLKSEL;                 /**< 00E0: CLKOUT clock source select                                   */
   __IO uint32_t  CLKOUTUEN;                    /**< 00E4: CLKOUT clock source update enable                            */
   __IO uint32_t  CLKOUTDIV;                    /**< 00E8: CLKOUT clock divider                                         */
        uint8_t   RESERVED_10[20];             
   __I  uint32_t  PIOPORCAP0;                   /**< 0100: POR captured PIO status 0                                    */
   __I  uint32_t  PIOPORCAP1;                   /**< 0104: POR captured PIO status 1                                    */
        uint8_t   RESERVED_11[72];             
   __IO uint32_t  BODCTRL;                      /**< 0150: BOD control                                                  */
   __IO uint32_t  SYSTCKCAL;                    /**< 0154: System tick counter calibration                              */
        uint8_t   RESERVED_12[168];            
   __IO uint32_t  STARTAPRP0;                   /**< 0200: Start logic edge control register 0; bottom 32 interrupts    */
   __IO uint32_t  STARTERP0;                    /**< 0204: Start logic signal enable register 0; bottom 32 interrupts   */
   __O  uint32_t  STARTRSRP0CLR;                /**< 0208: Start logic reset register 0; bottom 32 interrupts           */
   __I  uint32_t  STARTSRP0;                    /**< 020C: Start logic status register 0; bottom 32 interrupts          */
   __IO uint32_t  STARTAPRP1;                   /**< 0210: Start logic edge control register 1; top 8 interrupts        */
   __IO uint32_t  STARTERP1;                    /**< 0214: Start logic signal enable register 1; top 8 interrupts       */
   __O  uint32_t  STARTRSRP1CLR;                /**< 0218: Start logic reset register 1; top 8 interrupts               */
   __I  uint32_t  STARTSRP1;                    /**< 021C: Start logic status register 1; top 8 interrupts              */
        uint8_t   RESERVED_13[16];             
   __IO uint32_t  PDSLEEPCFG;                   /**< 0230: Power-down states in Deep-sleep mode                         */
   __IO uint32_t  PDAWAKECFG;                   /**< 0234: Power-down states after wake-up from Deep-sleep mode         */
   __IO uint32_t  PDRUNCFG;                     /**< 0238: Power-down configuration register                            */
        uint8_t   RESERVED_14[440];            
   __I  uint32_t  DEVICE_ID;                    /**< 03F4: Device ID                                                    */
} LPC_SYSCON_Type;

/**
 * @} */ /* End group SYSCON_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_SYSCON' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SYSCON_Register_Masks_GROUP SYSCON Register Masks
* @brief Register Masks for SYSCON
* @{
*/
/* ------- SYSMEMREMAP Bit Fields                   ------ */
#define LPC_SYSCON_SYSMEMREMAP_MAP_MASK          (0x3U)                                              /*!< LPC_SYSCON_SYSMEMREMAP.MAP Mask         */
#define LPC_SYSCON_SYSMEMREMAP_MAP_SHIFT         (0U)                                                /*!< LPC_SYSCON_SYSMEMREMAP.MAP Position     */
#define LPC_SYSCON_SYSMEMREMAP_MAP(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_SYSCON_SYSMEMREMAP.MAP Field        */
/* ------- PRESETCTRL Bit Fields                    ------ */
#define LPC_SYSCON_PRESETCTRL_SSP0_RST_N_MASK    (0x1U)                                              /*!< LPC_SYSCON_PRESETCTRL.SSP0_RST_N Mask   */
#define LPC_SYSCON_PRESETCTRL_SSP0_RST_N_SHIFT   (0U)                                                /*!< LPC_SYSCON_PRESETCTRL.SSP0_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_SSP0_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_PRESETCTRL.SSP0_RST_N Field  */
#define LPC_SYSCON_PRESETCTRL_I2C_RST_N_MASK     (0x2U)                                              /*!< LPC_SYSCON_PRESETCTRL.I2C_RST_N Mask    */
#define LPC_SYSCON_PRESETCTRL_I2C_RST_N_SHIFT    (1U)                                                /*!< LPC_SYSCON_PRESETCTRL.I2C_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_I2C_RST_N(x)       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_PRESETCTRL.I2C_RST_N Field   */
#define LPC_SYSCON_PRESETCTRL_SSP1_RST_N_MASK    (0x4U)                                              /*!< LPC_SYSCON_PRESETCTRL.SSP1_RST_N Mask   */
#define LPC_SYSCON_PRESETCTRL_SSP1_RST_N_SHIFT   (2U)                                                /*!< LPC_SYSCON_PRESETCTRL.SSP1_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_SSP1_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_PRESETCTRL.SSP1_RST_N Field  */
/* ------- SYSPLLCTRL Bit Fields                    ------ */
#define LPC_SYSCON_SYSPLLCTRL_MSEL_MASK          (0x1FU)                                             /*!< LPC_SYSCON_SYSPLLCTRL.MSEL Mask         */
#define LPC_SYSCON_SYSPLLCTRL_MSEL_SHIFT         (0U)                                                /*!< LPC_SYSCON_SYSPLLCTRL.MSEL Position     */
#define LPC_SYSCON_SYSPLLCTRL_MSEL(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< LPC_SYSCON_SYSPLLCTRL.MSEL Field        */
#define LPC_SYSCON_SYSPLLCTRL_PSEL_MASK          (0x60U)                                             /*!< LPC_SYSCON_SYSPLLCTRL.PSEL Mask         */
#define LPC_SYSCON_SYSPLLCTRL_PSEL_SHIFT         (5U)                                                /*!< LPC_SYSCON_SYSPLLCTRL.PSEL Position     */
#define LPC_SYSCON_SYSPLLCTRL_PSEL(x)            (((uint32_t)(((uint32_t)(x))<<5U))&0x60UL)          /*!< LPC_SYSCON_SYSPLLCTRL.PSEL Field        */
/* ------- SYSPLLSTAT Bit Fields                    ------ */
#define LPC_SYSCON_SYSPLLSTAT_LOCK_MASK          (0x1U)                                              /*!< LPC_SYSCON_SYSPLLSTAT.LOCK Mask         */
#define LPC_SYSCON_SYSPLLSTAT_LOCK_SHIFT         (0U)                                                /*!< LPC_SYSCON_SYSPLLSTAT.LOCK Position     */
#define LPC_SYSCON_SYSPLLSTAT_LOCK(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_SYSPLLSTAT.LOCK Field        */
/* ------- USBPLLCTRL Bit Fields                    ------ */
#define LPC_SYSCON_USBPLLCTRL_MSEL_MASK          (0x1FU)                                             /*!< LPC_SYSCON_USBPLLCTRL.MSEL Mask         */
#define LPC_SYSCON_USBPLLCTRL_MSEL_SHIFT         (0U)                                                /*!< LPC_SYSCON_USBPLLCTRL.MSEL Position     */
#define LPC_SYSCON_USBPLLCTRL_MSEL(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< LPC_SYSCON_USBPLLCTRL.MSEL Field        */
#define LPC_SYSCON_USBPLLCTRL_PSEL_MASK          (0x60U)                                             /*!< LPC_SYSCON_USBPLLCTRL.PSEL Mask         */
#define LPC_SYSCON_USBPLLCTRL_PSEL_SHIFT         (5U)                                                /*!< LPC_SYSCON_USBPLLCTRL.PSEL Position     */
#define LPC_SYSCON_USBPLLCTRL_PSEL(x)            (((uint32_t)(((uint32_t)(x))<<5U))&0x60UL)          /*!< LPC_SYSCON_USBPLLCTRL.PSEL Field        */
/* ------- USBPLLSTAT Bit Fields                    ------ */
#define LPC_SYSCON_USBPLLSTAT_LOCK_MASK          (0x1U)                                              /*!< LPC_SYSCON_USBPLLSTAT.LOCK Mask         */
#define LPC_SYSCON_USBPLLSTAT_LOCK_SHIFT         (0U)                                                /*!< LPC_SYSCON_USBPLLSTAT.LOCK Position     */
#define LPC_SYSCON_USBPLLSTAT_LOCK(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_USBPLLSTAT.LOCK Field        */
/* ------- SYSOSCCTRL Bit Fields                    ------ */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS_MASK        (0x1U)                                              /*!< LPC_SYSCON_SYSOSCCTRL.BYPASS Mask       */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS_SHIFT       (0U)                                                /*!< LPC_SYSCON_SYSOSCCTRL.BYPASS Position   */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_SYSOSCCTRL.BYPASS Field      */
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE_MASK     (0x2U)                                              /*!< LPC_SYSCON_SYSOSCCTRL.FREQRANGE Mask    */
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT    (1U)                                                /*!< LPC_SYSCON_SYSOSCCTRL.FREQRANGE Position*/
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE(x)       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_SYSOSCCTRL.FREQRANGE Field   */
/* ------- WDTOSCCTRL Bit Fields                    ------ */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL_MASK        (0x1FU)                                             /*!< LPC_SYSCON_WDTOSCCTRL.DIVSEL Mask       */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL_SHIFT       (0U)                                                /*!< LPC_SYSCON_WDTOSCCTRL.DIVSEL Position   */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< LPC_SYSCON_WDTOSCCTRL.DIVSEL Field      */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL_MASK       (0x1E0U)                                            /*!< LPC_SYSCON_WDTOSCCTRL.FREQSEL Mask      */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL_SHIFT      (5U)                                                /*!< LPC_SYSCON_WDTOSCCTRL.FREQSEL Position  */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL(x)         (((uint32_t)(((uint32_t)(x))<<5U))&0x1E0UL)         /*!< LPC_SYSCON_WDTOSCCTRL.FREQSEL Field     */
/* ------- IRCCTRL Bit Fields                       ------ */
#define LPC_SYSCON_IRCCTRL_TRIM_MASK             (0xFFU)                                             /*!< LPC_SYSCON_IRCCTRL.TRIM Mask            */
#define LPC_SYSCON_IRCCTRL_TRIM_SHIFT            (0U)                                                /*!< LPC_SYSCON_IRCCTRL.TRIM Position        */
#define LPC_SYSCON_IRCCTRL_TRIM(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_IRCCTRL.TRIM Field           */
/* ------- SYSRESSTAT Bit Fields                    ------ */
#define LPC_SYSCON_SYSRESSTAT_POR_MASK           (0x1U)                                              /*!< LPC_SYSCON_SYSRESSTAT.POR Mask          */
#define LPC_SYSCON_SYSRESSTAT_POR_SHIFT          (0U)                                                /*!< LPC_SYSCON_SYSRESSTAT.POR Position      */
#define LPC_SYSCON_SYSRESSTAT_POR(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_SYSRESSTAT.POR Field         */
#define LPC_SYSCON_SYSRESSTAT_EXTRST_MASK        (0x2U)                                              /*!< LPC_SYSCON_SYSRESSTAT.EXTRST Mask       */
#define LPC_SYSCON_SYSRESSTAT_EXTRST_SHIFT       (1U)                                                /*!< LPC_SYSCON_SYSRESSTAT.EXTRST Position   */
#define LPC_SYSCON_SYSRESSTAT_EXTRST(x)          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_SYSRESSTAT.EXTRST Field      */
#define LPC_SYSCON_SYSRESSTAT_WDT_MASK           (0x4U)                                              /*!< LPC_SYSCON_SYSRESSTAT.WDT Mask          */
#define LPC_SYSCON_SYSRESSTAT_WDT_SHIFT          (2U)                                                /*!< LPC_SYSCON_SYSRESSTAT.WDT Position      */
#define LPC_SYSCON_SYSRESSTAT_WDT(x)             (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_SYSRESSTAT.WDT Field         */
#define LPC_SYSCON_SYSRESSTAT_BOD_MASK           (0x8U)                                              /*!< LPC_SYSCON_SYSRESSTAT.BOD Mask          */
#define LPC_SYSCON_SYSRESSTAT_BOD_SHIFT          (3U)                                                /*!< LPC_SYSCON_SYSRESSTAT.BOD Position      */
#define LPC_SYSCON_SYSRESSTAT_BOD(x)             (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_SYSRESSTAT.BOD Field         */
#define LPC_SYSCON_SYSRESSTAT_SYSRST_MASK        (0x10U)                                             /*!< LPC_SYSCON_SYSRESSTAT.SYSRST Mask       */
#define LPC_SYSCON_SYSRESSTAT_SYSRST_SHIFT       (4U)                                                /*!< LPC_SYSCON_SYSRESSTAT.SYSRST Position   */
#define LPC_SYSCON_SYSRESSTAT_SYSRST(x)          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_SYSRESSTAT.SYSRST Field      */
/* ------- SYSPLLCLKSEL Bit Fields                  ------ */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL_MASK         (0x3U)                                              /*!< LPC_SYSCON_SYSPLLCLKSEL.SEL Mask        */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL_SHIFT        (0U)                                                /*!< LPC_SYSCON_SYSPLLCLKSEL.SEL Position    */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_SYSCON_SYSPLLCLKSEL.SEL Field       */
/* ------- SYSPLLCLKUEN Bit Fields                  ------ */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA_MASK         (0x1U)                                              /*!< LPC_SYSCON_SYSPLLCLKUEN.ENA Mask        */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA_SHIFT        (0U)                                                /*!< LPC_SYSCON_SYSPLLCLKUEN.ENA Position    */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_SYSPLLCLKUEN.ENA Field       */
/* ------- USBPLLCLKSEL Bit Fields                  ------ */
#define LPC_SYSCON_USBPLLCLKSEL_SEL_MASK         (0x3U)                                              /*!< LPC_SYSCON_USBPLLCLKSEL.SEL Mask        */
#define LPC_SYSCON_USBPLLCLKSEL_SEL_SHIFT        (0U)                                                /*!< LPC_SYSCON_USBPLLCLKSEL.SEL Position    */
#define LPC_SYSCON_USBPLLCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_SYSCON_USBPLLCLKSEL.SEL Field       */
/* ------- USBPLLCLKUEN Bit Fields                  ------ */
#define LPC_SYSCON_USBPLLCLKUEN_ENA_MASK         (0x1U)                                              /*!< LPC_SYSCON_USBPLLCLKUEN.ENA Mask        */
#define LPC_SYSCON_USBPLLCLKUEN_ENA_SHIFT        (0U)                                                /*!< LPC_SYSCON_USBPLLCLKUEN.ENA Position    */
#define LPC_SYSCON_USBPLLCLKUEN_ENA(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_USBPLLCLKUEN.ENA Field       */
/* ------- MAINCLKSEL Bit Fields                    ------ */
#define LPC_SYSCON_MAINCLKSEL_SEL_MASK           (0x3U)                                              /*!< LPC_SYSCON_MAINCLKSEL.SEL Mask          */
#define LPC_SYSCON_MAINCLKSEL_SEL_SHIFT          (0U)                                                /*!< LPC_SYSCON_MAINCLKSEL.SEL Position      */
#define LPC_SYSCON_MAINCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_SYSCON_MAINCLKSEL.SEL Field         */
/* ------- MAINCLKUEN Bit Fields                    ------ */
#define LPC_SYSCON_MAINCLKUEN_ENA_MASK           (0x1U)                                              /*!< LPC_SYSCON_MAINCLKUEN.ENA Mask          */
#define LPC_SYSCON_MAINCLKUEN_ENA_SHIFT          (0U)                                                /*!< LPC_SYSCON_MAINCLKUEN.ENA Position      */
#define LPC_SYSCON_MAINCLKUEN_ENA(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_MAINCLKUEN.ENA Field         */
/* ------- SYSAHBCLKDIV Bit Fields                  ------ */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV_MASK         (0xFFU)                                             /*!< LPC_SYSCON_SYSAHBCLKDIV.DIV Mask        */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV_SHIFT        (0U)                                                /*!< LPC_SYSCON_SYSAHBCLKDIV.DIV Position    */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_SYSAHBCLKDIV.DIV Field       */
/* ------- SYSAHBCLKCTRL Bit Fields                 ------ */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS_MASK        (0x1U)                                              /*!< LPC_SYSCON_SYSAHBCLKCTRL.SYS Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS_SHIFT       (0U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.SYS Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_SYSAHBCLKCTRL.SYS Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM_MASK        (0x2U)                                              /*!< LPC_SYSCON_SYSAHBCLKCTRL.ROM Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM_SHIFT       (1U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.ROM Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM(x)          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_SYSAHBCLKCTRL.ROM Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM_MASK        (0x4U)                                              /*!< LPC_SYSCON_SYSAHBCLKCTRL.RAM Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM_SHIFT       (2U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.RAM Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_SYSAHBCLKCTRL.RAM Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK   (0x8U)                                              /*!< LPC_SYSCON_SYSAHBCLKCTRL.FLASHREG Mask  */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT  (3U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.FLASHREG Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG(x)     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_SYSAHBCLKCTRL.FLASHREG Field */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHARRAY_MASK (0x10U)                                             /*!< LPC_SYSCON_SYSAHBCLKCTRL.FLASHARRAY Mask*/
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHARRAY_SHIFT (4U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.FLASHARRAY Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHARRAY(x)   (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_SYSAHBCLKCTRL.FLASHARRAY Field*/
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C_MASK        (0x20U)                                             /*!< LPC_SYSCON_SYSAHBCLKCTRL.I2C Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C_SHIFT       (5U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.I2C Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C(x)          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_SYSAHBCLKCTRL.I2C Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO_MASK       (0x40U)                                             /*!< LPC_SYSCON_SYSAHBCLKCTRL.GPIO Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT      (6U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.GPIO Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO(x)         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_SYSAHBCLKCTRL.GPIO Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B0_MASK     (0x80U)                                             /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT16B0 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B0_SHIFT    (7U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT16B0 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B0(x)       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT16B0 Field   */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B1_MASK     (0x100U)                                            /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT16B1 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B1_SHIFT    (8U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT16B1 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_CT16B1(x)       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT16B1 Field   */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B0_MASK     (0x200U)                                            /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT32B0 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B0_SHIFT    (9U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT32B0 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B0(x)       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT32B0 Field   */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B1_MASK     (0x400U)                                            /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT32B1 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B1_SHIFT    (10U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT32B1 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_CT32B1(x)       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_SYSCON_SYSAHBCLKCTRL.CT32B1 Field   */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP_MASK        (0x800U)                                            /*!< LPC_SYSCON_SYSAHBCLKCTRL.SSP Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP_SHIFT       (11U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.SSP Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP(x)          (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_SYSCON_SYSAHBCLKCTRL.SSP Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART_MASK       (0x1000U)                                           /*!< LPC_SYSCON_SYSAHBCLKCTRL.UART Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART_SHIFT      (12U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.UART Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART(x)         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_SYSCON_SYSAHBCLKCTRL.UART Field     */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC_MASK        (0x2000U)                                           /*!< LPC_SYSCON_SYSAHBCLKCTRL.ADC Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC_SHIFT       (13U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.ADC Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC(x)          (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_SYSCON_SYSAHBCLKCTRL.ADC Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_USB_REG_MASK    (0x4000U)                                           /*!< LPC_SYSCON_SYSAHBCLKCTRL.USB_REG Mask   */
#define LPC_SYSCON_SYSAHBCLKCTRL_USB_REG_SHIFT   (14U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.USB_REG Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_USB_REG(x)      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPC_SYSCON_SYSAHBCLKCTRL.USB_REG Field  */
#define LPC_SYSCON_SYSAHBCLKCTRL_WDT_MASK        (0x8000U)                                           /*!< LPC_SYSCON_SYSAHBCLKCTRL.WDT Mask       */
#define LPC_SYSCON_SYSAHBCLKCTRL_WDT_SHIFT       (15U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.WDT Position   */
#define LPC_SYSCON_SYSAHBCLKCTRL_WDT(x)          (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPC_SYSCON_SYSAHBCLKCTRL.WDT Field      */
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON_MASK      (0x10000U)                                          /*!< LPC_SYSCON_SYSAHBCLKCTRL.IOCON Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT     (16U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.IOCON Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON(x)        (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPC_SYSCON_SYSAHBCLKCTRL.IOCON Field    */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP1_MASK       (0x40000U)                                          /*!< LPC_SYSCON_SYSAHBCLKCTRL.SSP1 Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP1_SHIFT      (18U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL.SSP1 Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_SSP1(x)         (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPC_SYSCON_SYSAHBCLKCTRL.SSP1 Field     */
/* ------- SSP0CLKDIV Bit Fields                    ------ */
#define LPC_SYSCON_SSP0CLKDIV_DIV_MASK           (0xFFU)                                             /*!< LPC_SYSCON_SSP0CLKDIV.DIV Mask          */
#define LPC_SYSCON_SSP0CLKDIV_DIV_SHIFT          (0U)                                                /*!< LPC_SYSCON_SSP0CLKDIV.DIV Position      */
#define LPC_SYSCON_SSP0CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_SSP0CLKDIV.DIV Field         */
/* ------- UARTCLKDIV Bit Fields                    ------ */
#define LPC_SYSCON_UARTCLKDIV_DIV_MASK           (0xFFU)                                             /*!< LPC_SYSCON_UARTCLKDIV.DIV Mask          */
#define LPC_SYSCON_UARTCLKDIV_DIV_SHIFT          (0U)                                                /*!< LPC_SYSCON_UARTCLKDIV.DIV Position      */
#define LPC_SYSCON_UARTCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_UARTCLKDIV.DIV Field         */
/* ------- SSP1CLKDIV Bit Fields                    ------ */
#define LPC_SYSCON_SSP1CLKDIV_DIV_MASK           (0xFFU)                                             /*!< LPC_SYSCON_SSP1CLKDIV.DIV Mask          */
#define LPC_SYSCON_SSP1CLKDIV_DIV_SHIFT          (0U)                                                /*!< LPC_SYSCON_SSP1CLKDIV.DIV Position      */
#define LPC_SYSCON_SSP1CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_SSP1CLKDIV.DIV Field         */
/* ------- TRACECLKDIV Bit Fields                   ------ */
#define LPC_SYSCON_TRACECLKDIV_DIV_MASK          (0xFFU)                                             /*!< LPC_SYSCON_TRACECLKDIV.DIV Mask         */
#define LPC_SYSCON_TRACECLKDIV_DIV_SHIFT         (0U)                                                /*!< LPC_SYSCON_TRACECLKDIV.DIV Position     */
#define LPC_SYSCON_TRACECLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_TRACECLKDIV.DIV Field        */
/* ------- SYSTICKCLKDIV Bit Fields                 ------ */
#define LPC_SYSCON_SYSTICKCLKDIV_DIV_MASK        (0xFFU)                                             /*!< LPC_SYSCON_SYSTICKCLKDIV.DIV Mask       */
#define LPC_SYSCON_SYSTICKCLKDIV_DIV_SHIFT       (0U)                                                /*!< LPC_SYSCON_SYSTICKCLKDIV.DIV Position   */
#define LPC_SYSCON_SYSTICKCLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_SYSTICKCLKDIV.DIV Field      */
/* ------- USBCLKSEL Bit Fields                     ------ */
#define LPC_SYSCON_USBCLKSEL_SEL_MASK            (0x3U)                                              /*!< LPC_SYSCON_USBCLKSEL.SEL Mask           */
#define LPC_SYSCON_USBCLKSEL_SEL_SHIFT           (0U)                                                /*!< LPC_SYSCON_USBCLKSEL.SEL Position       */
#define LPC_SYSCON_USBCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_SYSCON_USBCLKSEL.SEL Field          */
/* ------- USBCLKUEN Bit Fields                     ------ */
#define LPC_SYSCON_USBCLKUEN_ENA_MASK            (0x1U)                                              /*!< LPC_SYSCON_USBCLKUEN.ENA Mask           */
#define LPC_SYSCON_USBCLKUEN_ENA_SHIFT           (0U)                                                /*!< LPC_SYSCON_USBCLKUEN.ENA Position       */
#define LPC_SYSCON_USBCLKUEN_ENA(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_USBCLKUEN.ENA Field          */
/* ------- USBCLKDIV Bit Fields                     ------ */
#define LPC_SYSCON_USBCLKDIV_DIV_MASK            (0xFFU)                                             /*!< LPC_SYSCON_USBCLKDIV.DIV Mask           */
#define LPC_SYSCON_USBCLKDIV_DIV_SHIFT           (0U)                                                /*!< LPC_SYSCON_USBCLKDIV.DIV Position       */
#define LPC_SYSCON_USBCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_USBCLKDIV.DIV Field          */
/* ------- WDTCLKSEL Bit Fields                     ------ */
#define LPC_SYSCON_WDTCLKSEL_SEL_MASK            (0x3U)                                              /*!< LPC_SYSCON_WDTCLKSEL.SEL Mask           */
#define LPC_SYSCON_WDTCLKSEL_SEL_SHIFT           (0U)                                                /*!< LPC_SYSCON_WDTCLKSEL.SEL Position       */
#define LPC_SYSCON_WDTCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_SYSCON_WDTCLKSEL.SEL Field          */
/* ------- WDTCLKUEN Bit Fields                     ------ */
#define LPC_SYSCON_WDTCLKUEN_ENA_MASK            (0x1U)                                              /*!< LPC_SYSCON_WDTCLKUEN.ENA Mask           */
#define LPC_SYSCON_WDTCLKUEN_ENA_SHIFT           (0U)                                                /*!< LPC_SYSCON_WDTCLKUEN.ENA Position       */
#define LPC_SYSCON_WDTCLKUEN_ENA(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_WDTCLKUEN.ENA Field          */
/* ------- WDTCLKDIV Bit Fields                     ------ */
#define LPC_SYSCON_WDTCLKDIV_DIV_MASK            (0xFFU)                                             /*!< LPC_SYSCON_WDTCLKDIV.DIV Mask           */
#define LPC_SYSCON_WDTCLKDIV_DIV_SHIFT           (0U)                                                /*!< LPC_SYSCON_WDTCLKDIV.DIV Position       */
#define LPC_SYSCON_WDTCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_WDTCLKDIV.DIV Field          */
/* ------- CLKOUTCLKSEL Bit Fields                  ------ */
#define LPC_SYSCON_CLKOUTCLKSEL_SEL_MASK         (0x3U)                                              /*!< LPC_SYSCON_CLKOUTCLKSEL.SEL Mask        */
#define LPC_SYSCON_CLKOUTCLKSEL_SEL_SHIFT        (0U)                                                /*!< LPC_SYSCON_CLKOUTCLKSEL.SEL Position    */
#define LPC_SYSCON_CLKOUTCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_SYSCON_CLKOUTCLKSEL.SEL Field       */
/* ------- CLKOUTUEN Bit Fields                     ------ */
#define LPC_SYSCON_CLKOUTUEN_ENA_MASK            (0x1U)                                              /*!< LPC_SYSCON_CLKOUTUEN.ENA Mask           */
#define LPC_SYSCON_CLKOUTUEN_ENA_SHIFT           (0U)                                                /*!< LPC_SYSCON_CLKOUTUEN.ENA Position       */
#define LPC_SYSCON_CLKOUTUEN_ENA(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_CLKOUTUEN.ENA Field          */
/* ------- CLKOUTDIV Bit Fields                     ------ */
#define LPC_SYSCON_CLKOUTDIV_DIV_MASK            (0xFFU)                                             /*!< LPC_SYSCON_CLKOUTDIV.DIV Mask           */
#define LPC_SYSCON_CLKOUTDIV_DIV_SHIFT           (0U)                                                /*!< LPC_SYSCON_CLKOUTDIV.DIV Position       */
#define LPC_SYSCON_CLKOUTDIV_DIV(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_SYSCON_CLKOUTDIV.DIV Field          */
/* ------- PIOPORCAP0 Bit Fields                    ------ */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_0_MASK     (0x1U)                                              /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_0 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_0_SHIFT    (0U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_0 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_0(x)       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_0 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_1_MASK     (0x2U)                                              /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_1 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_1_SHIFT    (1U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_1 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_1(x)       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_1 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_2_MASK     (0x4U)                                              /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_2 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_2_SHIFT    (2U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_2 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_2(x)       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_2 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_3_MASK     (0x8U)                                              /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_3 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_3_SHIFT    (3U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_3 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_3(x)       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_3 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_4_MASK     (0x10U)                                             /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_4 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_4_SHIFT    (4U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_4 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_4(x)       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_4 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_5_MASK     (0x20U)                                             /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_5 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_5_SHIFT    (5U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_5 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_5(x)       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_5 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_6_MASK     (0x40U)                                             /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_6 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_6_SHIFT    (6U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_6 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_6(x)       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_6 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_7_MASK     (0x80U)                                             /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_7 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_7_SHIFT    (7U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_7 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_7(x)       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_7 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_8_MASK     (0x100U)                                            /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_8 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_8_SHIFT    (8U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_8 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_8(x)       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_8 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_9_MASK     (0x200U)                                            /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_9 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_9_SHIFT    (9U)                                                /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_9 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_9(x)       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_9 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_10_MASK    (0x400U)                                            /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_10 Mask   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_10_SHIFT   (10U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_10 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_10(x)      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_10 Field  */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_11_MASK    (0x800U)                                            /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_11 Mask   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_11_SHIFT   (11U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_11 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO0_11(x)      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO0_11 Field  */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_0_MASK     (0x1000U)                                           /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_0 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_0_SHIFT    (12U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_0 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_0(x)       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_0 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_1_MASK     (0x2000U)                                           /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_1 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_1_SHIFT    (13U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_1 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_1(x)       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_1 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_2_MASK     (0x4000U)                                           /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_2 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_2_SHIFT    (14U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_2 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_2(x)       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_2 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_3_MASK     (0x8000U)                                           /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_3 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_3_SHIFT    (15U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_3 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_3(x)       (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_3 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_4_MASK     (0x10000U)                                          /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_4 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_4_SHIFT    (16U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_4 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_4(x)       (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_4 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_5_MASK     (0x20000U)                                          /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_5 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_5_SHIFT    (17U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_5 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_5(x)       (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_5 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_6_MASK     (0x40000U)                                          /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_6 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_6_SHIFT    (18U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_6 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_6(x)       (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_6 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_7_MASK     (0x80000U)                                          /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_7 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_7_SHIFT    (19U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_7 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_7(x)       (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_7 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_8_MASK     (0x100000U)                                         /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_8 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_8_SHIFT    (20U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_8 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_8(x)       (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_8 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_9_MASK     (0x200000U)                                         /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_9 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_9_SHIFT    (21U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_9 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_9(x)       (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_9 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_10_MASK    (0x400000U)                                         /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_10 Mask   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_10_SHIFT   (22U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_10 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_10(x)      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_10 Field  */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_11_MASK    (0x800000U)                                         /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_11 Mask   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_11_SHIFT   (23U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_11 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO1_11(x)      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO1_11 Field  */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_0_MASK     (0x1000000U)                                        /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_0 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_0_SHIFT    (24U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_0 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_0(x)       (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_0 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_1_MASK     (0x2000000U)                                        /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_1 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_1_SHIFT    (25U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_1 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_1(x)       (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_1 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_2_MASK     (0x4000000U)                                        /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_2 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_2_SHIFT    (26U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_2 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_2(x)       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_2 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_3_MASK     (0x8000000U)                                        /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_3 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_3_SHIFT    (27U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_3 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_3(x)       (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_3 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_4_MASK     (0x10000000U)                                       /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_4 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_4_SHIFT    (28U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_4 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_4(x)       (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_4 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_5_MASK     (0x20000000U)                                       /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_5 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_5_SHIFT    (29U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_5 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_5(x)       (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_5 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_6_MASK     (0x40000000U)                                       /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_6 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_6_SHIFT    (30U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_6 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_6(x)       (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_6 Field   */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_7_MASK     (0x80000000U)                                       /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_7 Mask    */
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_7_SHIFT    (31U)                                               /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_7 Position*/
#define LPC_SYSCON_PIOPORCAP0_CAPPIO2_7(x)       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPC_SYSCON_PIOPORCAP0.CAPPIO2_7 Field   */
/* ------- PIOPORCAP1 Bit Fields                    ------ */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_8_MASK     (0x1U)                                              /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_8 Mask    */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_8_SHIFT    (0U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_8 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_8(x)       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_8 Field   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_9_MASK     (0x2U)                                              /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_9 Mask    */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_9_SHIFT    (1U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_9 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_9(x)       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_9 Field   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_10_MASK    (0x4U)                                              /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_10 Mask   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_10_SHIFT   (2U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_10 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_10(x)      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_10 Field  */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_11_MASK    (0x8U)                                              /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_11 Mask   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_11_SHIFT   (3U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_11 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO2_11(x)      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO2_11 Field  */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_0_MASK     (0x10U)                                             /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_0 Mask    */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_0_SHIFT    (4U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_0 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_0(x)       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_0 Field   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_1_MASK     (0x20U)                                             /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_1 Mask    */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_1_SHIFT    (5U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_1 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_1(x)       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_1 Field   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_2_MASK     (0x40U)                                             /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_2 Mask    */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_2_SHIFT    (6U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_2 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_2(x)       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_2 Field   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_3_MASK     (0x80U)                                             /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_3 Mask    */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_3_SHIFT    (7U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_3 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_3(x)       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_3 Field   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_4_MASK     (0x100U)                                            /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_4 Mask    */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_4_SHIFT    (8U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_4 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_4(x)       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_4 Field   */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_5_MASK     (0x200U)                                            /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_5 Mask    */
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_5_SHIFT    (9U)                                                /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_5 Position*/
#define LPC_SYSCON_PIOPORCAP1_CAPPIO3_5(x)       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_PIOPORCAP1.CAPPIO3_5 Field   */
/* ------- BODCTRL Bit Fields                       ------ */
#define LPC_SYSCON_BODCTRL_BODRSTLEV_MASK        (0x3U)                                              /*!< LPC_SYSCON_BODCTRL.BODRSTLEV Mask       */
#define LPC_SYSCON_BODCTRL_BODRSTLEV_SHIFT       (0U)                                                /*!< LPC_SYSCON_BODCTRL.BODRSTLEV Position   */
#define LPC_SYSCON_BODCTRL_BODRSTLEV(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_SYSCON_BODCTRL.BODRSTLEV Field      */
#define LPC_SYSCON_BODCTRL_BODINTVAL_MASK        (0xCU)                                              /*!< LPC_SYSCON_BODCTRL.BODINTVAL Mask       */
#define LPC_SYSCON_BODCTRL_BODINTVAL_SHIFT       (2U)                                                /*!< LPC_SYSCON_BODCTRL.BODINTVAL Position   */
#define LPC_SYSCON_BODCTRL_BODINTVAL(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< LPC_SYSCON_BODCTRL.BODINTVAL Field      */
#define LPC_SYSCON_BODCTRL_BODRSTENA_MASK        (0x10U)                                             /*!< LPC_SYSCON_BODCTRL.BODRSTENA Mask       */
#define LPC_SYSCON_BODCTRL_BODRSTENA_SHIFT       (4U)                                                /*!< LPC_SYSCON_BODCTRL.BODRSTENA Position   */
#define LPC_SYSCON_BODCTRL_BODRSTENA(x)          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_BODCTRL.BODRSTENA Field      */
/* ------- SYSTCKCAL Bit Fields                     ------ */
#define LPC_SYSCON_SYSTCKCAL_CAL_MASK            (0x3FFFFFFU)                                        /*!< LPC_SYSCON_SYSTCKCAL.CAL Mask           */
#define LPC_SYSCON_SYSTCKCAL_CAL_SHIFT           (0U)                                                /*!< LPC_SYSCON_SYSTCKCAL.CAL Position       */
#define LPC_SYSCON_SYSTCKCAL_CAL(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFFFUL)     /*!< LPC_SYSCON_SYSTCKCAL.CAL Field          */
/* ------- STARTAPRP0 Bit Fields                    ------ */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_0_MASK     (0x1U)                                              /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_0 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_0_SHIFT    (0U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_0 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_0(x)       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_0 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_1_MASK     (0x2U)                                              /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_1 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_1_SHIFT    (1U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_1 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_1(x)       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_1 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_2_MASK     (0x4U)                                              /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_2 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_2_SHIFT    (2U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_2 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_2(x)       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_2 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_3_MASK     (0x8U)                                              /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_3 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_3_SHIFT    (3U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_3 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_3(x)       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_3 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_4_MASK     (0x10U)                                             /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_4 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_4_SHIFT    (4U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_4 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_4(x)       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_4 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_5_MASK     (0x20U)                                             /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_5 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_5_SHIFT    (5U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_5 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_5(x)       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_5 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_6_MASK     (0x40U)                                             /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_6 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_6_SHIFT    (6U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_6 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_6(x)       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_6 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_7_MASK     (0x80U)                                             /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_7 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_7_SHIFT    (7U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_7 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_7(x)       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_7 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_8_MASK     (0x100U)                                            /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_8 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_8_SHIFT    (8U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_8 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_8(x)       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_8 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_9_MASK     (0x200U)                                            /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_9 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_9_SHIFT    (9U)                                                /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_9 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_9(x)       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_9 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_10_MASK    (0x400U)                                            /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_10 Mask   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_10_SHIFT   (10U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_10 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_10(x)      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_10 Field  */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_11_MASK    (0x800U)                                            /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_11 Mask   */
#define LPC_SYSCON_STARTAPRP0_APRPIO0_11_SHIFT   (11U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_11 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO0_11(x)      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_SYSCON_STARTAPRP0.APRPIO0_11 Field  */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_0_MASK     (0x1000U)                                           /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_0 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_0_SHIFT    (12U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_0 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_0(x)       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_0 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_1_MASK     (0x2000U)                                           /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_1 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_1_SHIFT    (13U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_1 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_1(x)       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_1 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_2_MASK     (0x4000U)                                           /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_2 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_2_SHIFT    (14U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_2 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_2(x)       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_2 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_3_MASK     (0x8000U)                                           /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_3 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_3_SHIFT    (15U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_3 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_3(x)       (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_3 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_4_MASK     (0x10000U)                                          /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_4 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_4_SHIFT    (16U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_4 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_4(x)       (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_4 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_5_MASK     (0x20000U)                                          /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_5 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_5_SHIFT    (17U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_5 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_5(x)       (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_5 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_6_MASK     (0x40000U)                                          /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_6 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_6_SHIFT    (18U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_6 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_6(x)       (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_6 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_7_MASK     (0x80000U)                                          /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_7 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_7_SHIFT    (19U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_7 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_7(x)       (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_7 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_8_MASK     (0x100000U)                                         /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_8 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_8_SHIFT    (20U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_8 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_8(x)       (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_8 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_9_MASK     (0x200000U)                                         /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_9 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_9_SHIFT    (21U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_9 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_9(x)       (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_9 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_10_MASK    (0x400000U)                                         /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_10 Mask   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_10_SHIFT   (22U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_10 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_10(x)      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_10 Field  */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_11_MASK    (0x800000U)                                         /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_11 Mask   */
#define LPC_SYSCON_STARTAPRP0_APRPIO1_11_SHIFT   (23U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_11 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO1_11(x)      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPC_SYSCON_STARTAPRP0.APRPIO1_11 Field  */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_0_MASK     (0x1000000U)                                        /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_0 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_0_SHIFT    (24U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_0 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO2_0(x)       (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_0 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_1_MASK     (0x2000000U)                                        /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_1 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_1_SHIFT    (25U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_1 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO2_1(x)       (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_1 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_2_MASK     (0x4000000U)                                        /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_2 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_2_SHIFT    (26U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_2 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO2_2(x)       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_2 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_3_MASK     (0x8000000U)                                        /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_3 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_3_SHIFT    (27U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_3 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO2_3(x)       (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_3 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_4_MASK     (0x10000000U)                                       /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_4 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_4_SHIFT    (28U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_4 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO2_4(x)       (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_4 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_5_MASK     (0x20000000U)                                       /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_5 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_5_SHIFT    (29U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_5 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO2_5(x)       (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_5 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_6_MASK     (0x40000000U)                                       /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_6 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_6_SHIFT    (30U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_6 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO2_6(x)       (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_6 Field   */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_7_MASK     (0x80000000U)                                       /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_7 Mask    */
#define LPC_SYSCON_STARTAPRP0_APRPIO2_7_SHIFT    (31U)                                               /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_7 Position*/
#define LPC_SYSCON_STARTAPRP0_APRPIO2_7(x)       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPC_SYSCON_STARTAPRP0.APRPIO2_7 Field   */
/* ------- STARTERP0 Bit Fields                     ------ */
#define LPC_SYSCON_STARTERP0_ERPIO0_0_MASK       (0x1U)                                              /*!< LPC_SYSCON_STARTERP0.ERPIO0_0 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_0_SHIFT      (0U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_0 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_0(x)         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_STARTERP0.ERPIO0_0 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_1_MASK       (0x2U)                                              /*!< LPC_SYSCON_STARTERP0.ERPIO0_1 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_1_SHIFT      (1U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_1 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_1(x)         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_STARTERP0.ERPIO0_1 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_2_MASK       (0x4U)                                              /*!< LPC_SYSCON_STARTERP0.ERPIO0_2 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_2_SHIFT      (2U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_2 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_2(x)         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_STARTERP0.ERPIO0_2 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_3_MASK       (0x8U)                                              /*!< LPC_SYSCON_STARTERP0.ERPIO0_3 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_3_SHIFT      (3U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_3 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_3(x)         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_STARTERP0.ERPIO0_3 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_4_MASK       (0x10U)                                             /*!< LPC_SYSCON_STARTERP0.ERPIO0_4 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_4_SHIFT      (4U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_4 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_4(x)         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_STARTERP0.ERPIO0_4 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_5_MASK       (0x20U)                                             /*!< LPC_SYSCON_STARTERP0.ERPIO0_5 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_5_SHIFT      (5U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_5 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_5(x)         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_STARTERP0.ERPIO0_5 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_6_MASK       (0x40U)                                             /*!< LPC_SYSCON_STARTERP0.ERPIO0_6 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_6_SHIFT      (6U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_6 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_6(x)         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_STARTERP0.ERPIO0_6 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_7_MASK       (0x80U)                                             /*!< LPC_SYSCON_STARTERP0.ERPIO0_7 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_7_SHIFT      (7U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_7 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_7(x)         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_STARTERP0.ERPIO0_7 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_8_MASK       (0x100U)                                            /*!< LPC_SYSCON_STARTERP0.ERPIO0_8 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_8_SHIFT      (8U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_8 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_8(x)         (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_STARTERP0.ERPIO0_8 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_9_MASK       (0x200U)                                            /*!< LPC_SYSCON_STARTERP0.ERPIO0_9 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO0_9_SHIFT      (9U)                                                /*!< LPC_SYSCON_STARTERP0.ERPIO0_9 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO0_9(x)         (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_STARTERP0.ERPIO0_9 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO0_10_MASK      (0x400U)                                            /*!< LPC_SYSCON_STARTERP0.ERPIO0_10 Mask     */
#define LPC_SYSCON_STARTERP0_ERPIO0_10_SHIFT     (10U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO0_10 Position */
#define LPC_SYSCON_STARTERP0_ERPIO0_10(x)        (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_SYSCON_STARTERP0.ERPIO0_10 Field    */
#define LPC_SYSCON_STARTERP0_ERPIO0_11_MASK      (0x800U)                                            /*!< LPC_SYSCON_STARTERP0.ERPIO0_11 Mask     */
#define LPC_SYSCON_STARTERP0_ERPIO0_11_SHIFT     (11U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO0_11 Position */
#define LPC_SYSCON_STARTERP0_ERPIO0_11(x)        (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_SYSCON_STARTERP0.ERPIO0_11 Field    */
#define LPC_SYSCON_STARTERP0_ERPIO1_0_MASK       (0x1000U)                                           /*!< LPC_SYSCON_STARTERP0.ERPIO1_0 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_0_SHIFT      (12U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_0 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_0(x)         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_SYSCON_STARTERP0.ERPIO1_0 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_1_MASK       (0x2000U)                                           /*!< LPC_SYSCON_STARTERP0.ERPIO1_1 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_1_SHIFT      (13U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_1 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_1(x)         (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_SYSCON_STARTERP0.ERPIO1_1 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_2_MASK       (0x4000U)                                           /*!< LPC_SYSCON_STARTERP0.ERPIO1_2 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_2_SHIFT      (14U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_2 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_2(x)         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPC_SYSCON_STARTERP0.ERPIO1_2 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_3_MASK       (0x8000U)                                           /*!< LPC_SYSCON_STARTERP0.ERPIO1_3 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_3_SHIFT      (15U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_3 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_3(x)         (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPC_SYSCON_STARTERP0.ERPIO1_3 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_4_MASK       (0x10000U)                                          /*!< LPC_SYSCON_STARTERP0.ERPIO1_4 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_4_SHIFT      (16U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_4 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_4(x)         (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPC_SYSCON_STARTERP0.ERPIO1_4 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_5_MASK       (0x20000U)                                          /*!< LPC_SYSCON_STARTERP0.ERPIO1_5 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_5_SHIFT      (17U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_5 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_5(x)         (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPC_SYSCON_STARTERP0.ERPIO1_5 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_6_MASK       (0x40000U)                                          /*!< LPC_SYSCON_STARTERP0.ERPIO1_6 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_6_SHIFT      (18U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_6 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_6(x)         (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPC_SYSCON_STARTERP0.ERPIO1_6 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_7_MASK       (0x80000U)                                          /*!< LPC_SYSCON_STARTERP0.ERPIO1_7 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_7_SHIFT      (19U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_7 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_7(x)         (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< LPC_SYSCON_STARTERP0.ERPIO1_7 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_8_MASK       (0x100000U)                                         /*!< LPC_SYSCON_STARTERP0.ERPIO1_8 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_8_SHIFT      (20U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_8 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_8(x)         (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LPC_SYSCON_STARTERP0.ERPIO1_8 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_9_MASK       (0x200000U)                                         /*!< LPC_SYSCON_STARTERP0.ERPIO1_9 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO1_9_SHIFT      (21U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_9 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO1_9(x)         (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LPC_SYSCON_STARTERP0.ERPIO1_9 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO1_10_MASK      (0x400000U)                                         /*!< LPC_SYSCON_STARTERP0.ERPIO1_10 Mask     */
#define LPC_SYSCON_STARTERP0_ERPIO1_10_SHIFT     (22U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_10 Position */
#define LPC_SYSCON_STARTERP0_ERPIO1_10(x)        (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LPC_SYSCON_STARTERP0.ERPIO1_10 Field    */
#define LPC_SYSCON_STARTERP0_ERPIO1_11_MASK      (0x800000U)                                         /*!< LPC_SYSCON_STARTERP0.ERPIO1_11 Mask     */
#define LPC_SYSCON_STARTERP0_ERPIO1_11_SHIFT     (23U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO1_11 Position */
#define LPC_SYSCON_STARTERP0_ERPIO1_11(x)        (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPC_SYSCON_STARTERP0.ERPIO1_11 Field    */
#define LPC_SYSCON_STARTERP0_ERPIO2_0_MASK       (0x1000000U)                                        /*!< LPC_SYSCON_STARTERP0.ERPIO2_0 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO2_0_SHIFT      (24U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO2_0 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO2_0(x)         (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< LPC_SYSCON_STARTERP0.ERPIO2_0 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO2_1_MASK       (0x2000000U)                                        /*!< LPC_SYSCON_STARTERP0.ERPIO2_1 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO2_1_SHIFT      (25U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO2_1 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO2_1(x)         (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< LPC_SYSCON_STARTERP0.ERPIO2_1 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO2_2_MASK       (0x4000000U)                                        /*!< LPC_SYSCON_STARTERP0.ERPIO2_2 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO2_2_SHIFT      (26U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO2_2 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO2_2(x)         (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< LPC_SYSCON_STARTERP0.ERPIO2_2 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO2_3_MASK       (0x8000000U)                                        /*!< LPC_SYSCON_STARTERP0.ERPIO2_3 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO2_3_SHIFT      (27U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO2_3 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO2_3(x)         (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< LPC_SYSCON_STARTERP0.ERPIO2_3 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO2_4_MASK       (0x10000000U)                                       /*!< LPC_SYSCON_STARTERP0.ERPIO2_4 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO2_4_SHIFT      (28U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO2_4 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO2_4(x)         (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< LPC_SYSCON_STARTERP0.ERPIO2_4 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO2_5_MASK       (0x20000000U)                                       /*!< LPC_SYSCON_STARTERP0.ERPIO2_5 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO2_5_SHIFT      (29U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO2_5 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO2_5(x)         (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LPC_SYSCON_STARTERP0.ERPIO2_5 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO2_6_MASK       (0x40000000U)                                       /*!< LPC_SYSCON_STARTERP0.ERPIO2_6 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO2_6_SHIFT      (30U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO2_6 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO2_6(x)         (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPC_SYSCON_STARTERP0.ERPIO2_6 Field     */
#define LPC_SYSCON_STARTERP0_ERPIO2_7_MASK       (0x80000000U)                                       /*!< LPC_SYSCON_STARTERP0.ERPIO2_7 Mask      */
#define LPC_SYSCON_STARTERP0_ERPIO2_7_SHIFT      (31U)                                               /*!< LPC_SYSCON_STARTERP0.ERPIO2_7 Position  */
#define LPC_SYSCON_STARTERP0_ERPIO2_7(x)         (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPC_SYSCON_STARTERP0.ERPIO2_7 Field     */
/* ------- STARTRSRP0CLR Bit Fields                 ------ */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_0_MASK  (0x1U)                                              /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_0 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_0_SHIFT (0U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_0 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_0(x)    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_0 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_1_MASK  (0x2U)                                              /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_1 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_1_SHIFT (1U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_1 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_1(x)    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_1 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_2_MASK  (0x4U)                                              /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_2 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_2_SHIFT (2U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_2 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_2(x)    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_2 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_3_MASK  (0x8U)                                              /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_3 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_3_SHIFT (3U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_3 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_3(x)    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_3 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_4_MASK  (0x10U)                                             /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_4 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_4_SHIFT (4U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_4 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_4(x)    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_4 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_5_MASK  (0x20U)                                             /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_5 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_5_SHIFT (5U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_5 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_5(x)    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_5 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_6_MASK  (0x40U)                                             /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_6 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_6_SHIFT (6U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_6 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_6(x)    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_6 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_7_MASK  (0x80U)                                             /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_7 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_7_SHIFT (7U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_7 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_7(x)    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_7 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_8_MASK  (0x100U)                                            /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_8 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_8_SHIFT (8U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_8 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_8(x)    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_8 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_9_MASK  (0x200U)                                            /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_9 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_9_SHIFT (9U)                                                /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_9 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_9(x)    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_9 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_10_MASK (0x400U)                                            /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_10 Mask*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_10_SHIFT (10U)                                              /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_10 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_10(x)   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_10 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_11_MASK (0x800U)                                            /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_11 Mask*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_11_SHIFT (11U)                                              /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_11 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO0_11(x)   (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO0_11 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_0_MASK  (0x1000U)                                           /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_0 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_0_SHIFT (12U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_0 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_0(x)    (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_0 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_1_MASK  (0x2000U)                                           /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_1 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_1_SHIFT (13U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_1 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_1(x)    (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_1 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_2_MASK  (0x4000U)                                           /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_2 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_2_SHIFT (14U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_2 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_2(x)    (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_2 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_3_MASK  (0x8000U)                                           /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_3 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_3_SHIFT (15U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_3 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_3(x)    (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_3 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_4_MASK  (0x10000U)                                          /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_4 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_4_SHIFT (16U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_4 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_4(x)    (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_4 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_5_MASK  (0x20000U)                                          /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_5 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_5_SHIFT (17U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_5 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_5(x)    (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_5 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_6_MASK  (0x40000U)                                          /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_6 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_6_SHIFT (18U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_6 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_6(x)    (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_6 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_7_MASK  (0x80000U)                                          /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_7 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_7_SHIFT (19U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_7 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_7(x)    (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_7 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_8_MASK  (0x100000U)                                         /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_8 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_8_SHIFT (20U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_8 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_8(x)    (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_8 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_9_MASK  (0x200000U)                                         /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_9 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_9_SHIFT (21U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_9 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_9(x)    (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_9 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_10_MASK (0x400000U)                                         /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_10 Mask*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_10_SHIFT (22U)                                              /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_10 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_10(x)   (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_10 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_11_MASK (0x800000U)                                         /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_11 Mask*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_11_SHIFT (23U)                                              /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_11 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO1_11(x)   (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO1_11 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_0_MASK  (0x1000000U)                                        /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_0 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_0_SHIFT (24U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_0 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_0(x)    (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_0 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_1_MASK  (0x2000000U)                                        /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_1 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_1_SHIFT (25U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_1 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_1(x)    (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_1 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_2_MASK  (0x4000000U)                                        /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_2 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_2_SHIFT (26U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_2 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_2(x)    (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_2 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_3_MASK  (0x8000000U)                                        /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_3 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_3_SHIFT (27U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_3 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_3(x)    (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_3 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_4_MASK  (0x10000000U)                                       /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_4 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_4_SHIFT (28U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_4 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_4(x)    (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_4 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_5_MASK  (0x20000000U)                                       /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_5 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_5_SHIFT (29U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_5 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_5(x)    (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_5 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_6_MASK  (0x40000000U)                                       /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_6 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_6_SHIFT (30U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_6 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_6(x)    (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_6 Field*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_7_MASK  (0x80000000U)                                       /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_7 Mask */
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_7_SHIFT (31U)                                               /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_7 Position*/
#define LPC_SYSCON_STARTRSRP0CLR_RSRPIO2_7(x)    (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPC_SYSCON_STARTRSRP0CLR.RSRPIO2_7 Field*/
/* ------- STARTSRP0 Bit Fields                     ------ */
#define LPC_SYSCON_STARTSRP0_SRPIO0_0_MASK       (0x1U)                                              /*!< LPC_SYSCON_STARTSRP0.SRPIO0_0 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_0_SHIFT      (0U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_0 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_0(x)         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_STARTSRP0.SRPIO0_0 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_1_MASK       (0x2U)                                              /*!< LPC_SYSCON_STARTSRP0.SRPIO0_1 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_1_SHIFT      (1U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_1 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_1(x)         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_STARTSRP0.SRPIO0_1 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_2_MASK       (0x4U)                                              /*!< LPC_SYSCON_STARTSRP0.SRPIO0_2 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_2_SHIFT      (2U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_2 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_2(x)         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_STARTSRP0.SRPIO0_2 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_3_MASK       (0x8U)                                              /*!< LPC_SYSCON_STARTSRP0.SRPIO0_3 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_3_SHIFT      (3U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_3 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_3(x)         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_STARTSRP0.SRPIO0_3 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_4_MASK       (0x10U)                                             /*!< LPC_SYSCON_STARTSRP0.SRPIO0_4 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_4_SHIFT      (4U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_4 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_4(x)         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_STARTSRP0.SRPIO0_4 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_5_MASK       (0x20U)                                             /*!< LPC_SYSCON_STARTSRP0.SRPIO0_5 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_5_SHIFT      (5U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_5 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_5(x)         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_STARTSRP0.SRPIO0_5 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_6_MASK       (0x40U)                                             /*!< LPC_SYSCON_STARTSRP0.SRPIO0_6 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_6_SHIFT      (6U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_6 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_6(x)         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_STARTSRP0.SRPIO0_6 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_7_MASK       (0x80U)                                             /*!< LPC_SYSCON_STARTSRP0.SRPIO0_7 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_7_SHIFT      (7U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_7 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_7(x)         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_STARTSRP0.SRPIO0_7 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_8_MASK       (0x100U)                                            /*!< LPC_SYSCON_STARTSRP0.SRPIO0_8 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_8_SHIFT      (8U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_8 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_8(x)         (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_STARTSRP0.SRPIO0_8 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_9_MASK       (0x200U)                                            /*!< LPC_SYSCON_STARTSRP0.SRPIO0_9 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO0_9_SHIFT      (9U)                                                /*!< LPC_SYSCON_STARTSRP0.SRPIO0_9 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO0_9(x)         (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_STARTSRP0.SRPIO0_9 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_10_MASK      (0x400U)                                            /*!< LPC_SYSCON_STARTSRP0.SRPIO0_10 Mask     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_10_SHIFT     (10U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO0_10 Position */
#define LPC_SYSCON_STARTSRP0_SRPIO0_10(x)        (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_SYSCON_STARTSRP0.SRPIO0_10 Field    */
#define LPC_SYSCON_STARTSRP0_SRPIO0_11_MASK      (0x800U)                                            /*!< LPC_SYSCON_STARTSRP0.SRPIO0_11 Mask     */
#define LPC_SYSCON_STARTSRP0_SRPIO0_11_SHIFT     (11U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO0_11 Position */
#define LPC_SYSCON_STARTSRP0_SRPIO0_11(x)        (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_SYSCON_STARTSRP0.SRPIO0_11 Field    */
#define LPC_SYSCON_STARTSRP0_SRPIO1_0_MASK       (0x1000U)                                           /*!< LPC_SYSCON_STARTSRP0.SRPIO1_0 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_0_SHIFT      (12U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_0 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_0(x)         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_SYSCON_STARTSRP0.SRPIO1_0 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_1_MASK       (0x2000U)                                           /*!< LPC_SYSCON_STARTSRP0.SRPIO1_1 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_1_SHIFT      (13U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_1 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_1(x)         (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_SYSCON_STARTSRP0.SRPIO1_1 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_2_MASK       (0x4000U)                                           /*!< LPC_SYSCON_STARTSRP0.SRPIO1_2 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_2_SHIFT      (14U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_2 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_2(x)         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPC_SYSCON_STARTSRP0.SRPIO1_2 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_3_MASK       (0x8000U)                                           /*!< LPC_SYSCON_STARTSRP0.SRPIO1_3 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_3_SHIFT      (15U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_3 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_3(x)         (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPC_SYSCON_STARTSRP0.SRPIO1_3 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_4_MASK       (0x10000U)                                          /*!< LPC_SYSCON_STARTSRP0.SRPIO1_4 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_4_SHIFT      (16U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_4 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_4(x)         (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPC_SYSCON_STARTSRP0.SRPIO1_4 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_5_MASK       (0x20000U)                                          /*!< LPC_SYSCON_STARTSRP0.SRPIO1_5 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_5_SHIFT      (17U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_5 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_5(x)         (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPC_SYSCON_STARTSRP0.SRPIO1_5 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_6_MASK       (0x40000U)                                          /*!< LPC_SYSCON_STARTSRP0.SRPIO1_6 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_6_SHIFT      (18U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_6 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_6(x)         (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPC_SYSCON_STARTSRP0.SRPIO1_6 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_7_MASK       (0x80000U)                                          /*!< LPC_SYSCON_STARTSRP0.SRPIO1_7 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_7_SHIFT      (19U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_7 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_7(x)         (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< LPC_SYSCON_STARTSRP0.SRPIO1_7 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_8_MASK       (0x100000U)                                         /*!< LPC_SYSCON_STARTSRP0.SRPIO1_8 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_8_SHIFT      (20U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_8 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_8(x)         (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LPC_SYSCON_STARTSRP0.SRPIO1_8 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_9_MASK       (0x200000U)                                         /*!< LPC_SYSCON_STARTSRP0.SRPIO1_9 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO1_9_SHIFT      (21U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_9 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO1_9(x)         (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LPC_SYSCON_STARTSRP0.SRPIO1_9 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_10_MASK      (0x400000U)                                         /*!< LPC_SYSCON_STARTSRP0.SRPIO1_10 Mask     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_10_SHIFT     (22U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_10 Position */
#define LPC_SYSCON_STARTSRP0_SRPIO1_10(x)        (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LPC_SYSCON_STARTSRP0.SRPIO1_10 Field    */
#define LPC_SYSCON_STARTSRP0_SRPIO1_11_MASK      (0x800000U)                                         /*!< LPC_SYSCON_STARTSRP0.SRPIO1_11 Mask     */
#define LPC_SYSCON_STARTSRP0_SRPIO1_11_SHIFT     (23U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO1_11 Position */
#define LPC_SYSCON_STARTSRP0_SRPIO1_11(x)        (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPC_SYSCON_STARTSRP0.SRPIO1_11 Field    */
#define LPC_SYSCON_STARTSRP0_SRPIO2_0_MASK       (0x1000000U)                                        /*!< LPC_SYSCON_STARTSRP0.SRPIO2_0 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO2_0_SHIFT      (24U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO2_0 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO2_0(x)         (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< LPC_SYSCON_STARTSRP0.SRPIO2_0 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO2_1_MASK       (0x2000000U)                                        /*!< LPC_SYSCON_STARTSRP0.SRPIO2_1 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO2_1_SHIFT      (25U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO2_1 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO2_1(x)         (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< LPC_SYSCON_STARTSRP0.SRPIO2_1 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO2_2_MASK       (0x4000000U)                                        /*!< LPC_SYSCON_STARTSRP0.SRPIO2_2 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO2_2_SHIFT      (26U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO2_2 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO2_2(x)         (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< LPC_SYSCON_STARTSRP0.SRPIO2_2 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO2_3_MASK       (0x8000000U)                                        /*!< LPC_SYSCON_STARTSRP0.SRPIO2_3 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO2_3_SHIFT      (27U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO2_3 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO2_3(x)         (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< LPC_SYSCON_STARTSRP0.SRPIO2_3 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO2_4_MASK       (0x10000000U)                                       /*!< LPC_SYSCON_STARTSRP0.SRPIO2_4 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO2_4_SHIFT      (28U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO2_4 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO2_4(x)         (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< LPC_SYSCON_STARTSRP0.SRPIO2_4 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO2_5_MASK       (0x20000000U)                                       /*!< LPC_SYSCON_STARTSRP0.SRPIO2_5 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO2_5_SHIFT      (29U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO2_5 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO2_5(x)         (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LPC_SYSCON_STARTSRP0.SRPIO2_5 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO2_6_MASK       (0x40000000U)                                       /*!< LPC_SYSCON_STARTSRP0.SRPIO2_6 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO2_6_SHIFT      (30U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO2_6 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO2_6(x)         (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPC_SYSCON_STARTSRP0.SRPIO2_6 Field     */
#define LPC_SYSCON_STARTSRP0_SRPIO2_7_MASK       (0x80000000U)                                       /*!< LPC_SYSCON_STARTSRP0.SRPIO2_7 Mask      */
#define LPC_SYSCON_STARTSRP0_SRPIO2_7_SHIFT      (31U)                                               /*!< LPC_SYSCON_STARTSRP0.SRPIO2_7 Position  */
#define LPC_SYSCON_STARTSRP0_SRPIO2_7(x)         (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPC_SYSCON_STARTSRP0.SRPIO2_7 Field     */
/* ------- STARTAPRP1 Bit Fields                    ------ */
#define LPC_SYSCON_STARTAPRP1_APRPIO2_8_MASK     (0x1U)                                              /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_8 Mask    */
#define LPC_SYSCON_STARTAPRP1_APRPIO2_8_SHIFT    (0U)                                                /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_8 Position*/
#define LPC_SYSCON_STARTAPRP1_APRPIO2_8(x)       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_8 Field   */
#define LPC_SYSCON_STARTAPRP1_APRPIO2_9_MASK     (0x2U)                                              /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_9 Mask    */
#define LPC_SYSCON_STARTAPRP1_APRPIO2_9_SHIFT    (1U)                                                /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_9 Position*/
#define LPC_SYSCON_STARTAPRP1_APRPIO2_9(x)       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_9 Field   */
#define LPC_SYSCON_STARTAPRP1_APRPIO2_10_MASK    (0x4U)                                              /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_10 Mask   */
#define LPC_SYSCON_STARTAPRP1_APRPIO2_10_SHIFT   (2U)                                                /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_10 Position*/
#define LPC_SYSCON_STARTAPRP1_APRPIO2_10(x)      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_10 Field  */
#define LPC_SYSCON_STARTAPRP1_APRPIO2_11_MASK    (0x8U)                                              /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_11 Mask   */
#define LPC_SYSCON_STARTAPRP1_APRPIO2_11_SHIFT   (3U)                                                /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_11 Position*/
#define LPC_SYSCON_STARTAPRP1_APRPIO2_11(x)      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_STARTAPRP1.APRPIO2_11 Field  */
#define LPC_SYSCON_STARTAPRP1_APRPIO3_0_MASK     (0x10U)                                             /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_0 Mask    */
#define LPC_SYSCON_STARTAPRP1_APRPIO3_0_SHIFT    (4U)                                                /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_0 Position*/
#define LPC_SYSCON_STARTAPRP1_APRPIO3_0(x)       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_0 Field   */
#define LPC_SYSCON_STARTAPRP1_APRPIO3_1_MASK     (0x20U)                                             /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_1 Mask    */
#define LPC_SYSCON_STARTAPRP1_APRPIO3_1_SHIFT    (5U)                                                /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_1 Position*/
#define LPC_SYSCON_STARTAPRP1_APRPIO3_1(x)       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_1 Field   */
#define LPC_SYSCON_STARTAPRP1_APRPIO3_2_MASK     (0x40U)                                             /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_2 Mask    */
#define LPC_SYSCON_STARTAPRP1_APRPIO3_2_SHIFT    (6U)                                                /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_2 Position*/
#define LPC_SYSCON_STARTAPRP1_APRPIO3_2(x)       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_2 Field   */
#define LPC_SYSCON_STARTAPRP1_APRPIO3_3_MASK     (0x80U)                                             /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_3 Mask    */
#define LPC_SYSCON_STARTAPRP1_APRPIO3_3_SHIFT    (7U)                                                /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_3 Position*/
#define LPC_SYSCON_STARTAPRP1_APRPIO3_3(x)       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_STARTAPRP1.APRPIO3_3 Field   */
/* ------- STARTERP1 Bit Fields                     ------ */
#define LPC_SYSCON_STARTERP1_ERPIO2_8_MASK       (0x1U)                                              /*!< LPC_SYSCON_STARTERP1.ERPIO2_8 Mask      */
#define LPC_SYSCON_STARTERP1_ERPIO2_8_SHIFT      (0U)                                                /*!< LPC_SYSCON_STARTERP1.ERPIO2_8 Position  */
#define LPC_SYSCON_STARTERP1_ERPIO2_8(x)         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_STARTERP1.ERPIO2_8 Field     */
#define LPC_SYSCON_STARTERP1_ERPIO2_9_MASK       (0x2U)                                              /*!< LPC_SYSCON_STARTERP1.ERPIO2_9 Mask      */
#define LPC_SYSCON_STARTERP1_ERPIO2_9_SHIFT      (1U)                                                /*!< LPC_SYSCON_STARTERP1.ERPIO2_9 Position  */
#define LPC_SYSCON_STARTERP1_ERPIO2_9(x)         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_STARTERP1.ERPIO2_9 Field     */
#define LPC_SYSCON_STARTERP1_ERPIO2_10_MASK      (0x4U)                                              /*!< LPC_SYSCON_STARTERP1.ERPIO2_10 Mask     */
#define LPC_SYSCON_STARTERP1_ERPIO2_10_SHIFT     (2U)                                                /*!< LPC_SYSCON_STARTERP1.ERPIO2_10 Position */
#define LPC_SYSCON_STARTERP1_ERPIO2_10(x)        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_STARTERP1.ERPIO2_10 Field    */
#define LPC_SYSCON_STARTERP1_ERPIO2_11_MASK      (0x8U)                                              /*!< LPC_SYSCON_STARTERP1.ERPIO2_11 Mask     */
#define LPC_SYSCON_STARTERP1_ERPIO2_11_SHIFT     (3U)                                                /*!< LPC_SYSCON_STARTERP1.ERPIO2_11 Position */
#define LPC_SYSCON_STARTERP1_ERPIO2_11(x)        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_STARTERP1.ERPIO2_11 Field    */
#define LPC_SYSCON_STARTERP1_ERPIO3_0_MASK       (0x10U)                                             /*!< LPC_SYSCON_STARTERP1.ERPIO3_0 Mask      */
#define LPC_SYSCON_STARTERP1_ERPIO3_0_SHIFT      (4U)                                                /*!< LPC_SYSCON_STARTERP1.ERPIO3_0 Position  */
#define LPC_SYSCON_STARTERP1_ERPIO3_0(x)         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_STARTERP1.ERPIO3_0 Field     */
#define LPC_SYSCON_STARTERP1_ERPIO3_1_MASK       (0x20U)                                             /*!< LPC_SYSCON_STARTERP1.ERPIO3_1 Mask      */
#define LPC_SYSCON_STARTERP1_ERPIO3_1_SHIFT      (5U)                                                /*!< LPC_SYSCON_STARTERP1.ERPIO3_1 Position  */
#define LPC_SYSCON_STARTERP1_ERPIO3_1(x)         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_STARTERP1.ERPIO3_1 Field     */
#define LPC_SYSCON_STARTERP1_ERPIO3_2_MASK       (0x40U)                                             /*!< LPC_SYSCON_STARTERP1.ERPIO3_2 Mask      */
#define LPC_SYSCON_STARTERP1_ERPIO3_2_SHIFT      (6U)                                                /*!< LPC_SYSCON_STARTERP1.ERPIO3_2 Position  */
#define LPC_SYSCON_STARTERP1_ERPIO3_2(x)         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_STARTERP1.ERPIO3_2 Field     */
#define LPC_SYSCON_STARTERP1_ERPIO3_3_MASK       (0x80U)                                             /*!< LPC_SYSCON_STARTERP1.ERPIO3_3 Mask      */
#define LPC_SYSCON_STARTERP1_ERPIO3_3_SHIFT      (7U)                                                /*!< LPC_SYSCON_STARTERP1.ERPIO3_3 Position  */
#define LPC_SYSCON_STARTERP1_ERPIO3_3(x)         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_STARTERP1.ERPIO3_3 Field     */
/* ------- STARTRSRP1CLR Bit Fields                 ------ */
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_8_MASK  (0x1U)                                              /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_8 Mask */
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_8_SHIFT (0U)                                                /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_8 Position*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_8(x)    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_8 Field*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_9_MASK  (0x2U)                                              /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_9 Mask */
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_9_SHIFT (1U)                                                /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_9 Position*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_9(x)    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_9 Field*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_10_MASK (0x4U)                                              /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_10 Mask*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_10_SHIFT (2U)                                               /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_10 Position*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_10(x)   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_10 Field*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_11_MASK (0x8U)                                              /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_11 Mask*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_11_SHIFT (3U)                                               /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_11 Position*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO2_11(x)   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO2_11 Field*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_0_MASK  (0x10U)                                             /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_0 Mask */
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_0_SHIFT (4U)                                                /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_0 Position*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_0(x)    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_0 Field*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_1_MASK  (0x20U)                                             /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_1 Mask */
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_1_SHIFT (5U)                                                /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_1 Position*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_1(x)    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_1 Field*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_2_MASK  (0x40U)                                             /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_2 Mask */
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_2_SHIFT (6U)                                                /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_2 Position*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_2(x)    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_2 Field*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_3_MASK  (0x80U)                                             /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_3 Mask */
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_3_SHIFT (7U)                                                /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_3 Position*/
#define LPC_SYSCON_STARTRSRP1CLR_RSRPIO3_3(x)    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_STARTRSRP1CLR.RSRPIO3_3 Field*/
/* ------- STARTSRP1 Bit Fields                     ------ */
#define LPC_SYSCON_STARTSRP1_SRPIO2_8_MASK       (0x1U)                                              /*!< LPC_SYSCON_STARTSRP1.SRPIO2_8 Mask      */
#define LPC_SYSCON_STARTSRP1_SRPIO2_8_SHIFT      (0U)                                                /*!< LPC_SYSCON_STARTSRP1.SRPIO2_8 Position  */
#define LPC_SYSCON_STARTSRP1_SRPIO2_8(x)         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_STARTSRP1.SRPIO2_8 Field     */
#define LPC_SYSCON_STARTSRP1_SRPIO2_9_MASK       (0x2U)                                              /*!< LPC_SYSCON_STARTSRP1.SRPIO2_9 Mask      */
#define LPC_SYSCON_STARTSRP1_SRPIO2_9_SHIFT      (1U)                                                /*!< LPC_SYSCON_STARTSRP1.SRPIO2_9 Position  */
#define LPC_SYSCON_STARTSRP1_SRPIO2_9(x)         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_STARTSRP1.SRPIO2_9 Field     */
#define LPC_SYSCON_STARTSRP1_SRPIO2_10_MASK      (0x4U)                                              /*!< LPC_SYSCON_STARTSRP1.SRPIO2_10 Mask     */
#define LPC_SYSCON_STARTSRP1_SRPIO2_10_SHIFT     (2U)                                                /*!< LPC_SYSCON_STARTSRP1.SRPIO2_10 Position */
#define LPC_SYSCON_STARTSRP1_SRPIO2_10(x)        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_STARTSRP1.SRPIO2_10 Field    */
#define LPC_SYSCON_STARTSRP1_SRPIO2_11_MASK      (0x8U)                                              /*!< LPC_SYSCON_STARTSRP1.SRPIO2_11 Mask     */
#define LPC_SYSCON_STARTSRP1_SRPIO2_11_SHIFT     (3U)                                                /*!< LPC_SYSCON_STARTSRP1.SRPIO2_11 Position */
#define LPC_SYSCON_STARTSRP1_SRPIO2_11(x)        (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_STARTSRP1.SRPIO2_11 Field    */
#define LPC_SYSCON_STARTSRP1_SRPIO3_0_MASK       (0x10U)                                             /*!< LPC_SYSCON_STARTSRP1.SRPIO3_0 Mask      */
#define LPC_SYSCON_STARTSRP1_SRPIO3_0_SHIFT      (4U)                                                /*!< LPC_SYSCON_STARTSRP1.SRPIO3_0 Position  */
#define LPC_SYSCON_STARTSRP1_SRPIO3_0(x)         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_STARTSRP1.SRPIO3_0 Field     */
#define LPC_SYSCON_STARTSRP1_SRPIO3_1_MASK       (0x20U)                                             /*!< LPC_SYSCON_STARTSRP1.SRPIO3_1 Mask      */
#define LPC_SYSCON_STARTSRP1_SRPIO3_1_SHIFT      (5U)                                                /*!< LPC_SYSCON_STARTSRP1.SRPIO3_1 Position  */
#define LPC_SYSCON_STARTSRP1_SRPIO3_1(x)         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_STARTSRP1.SRPIO3_1 Field     */
#define LPC_SYSCON_STARTSRP1_SRPIO3_2_MASK       (0x40U)                                             /*!< LPC_SYSCON_STARTSRP1.SRPIO3_2 Mask      */
#define LPC_SYSCON_STARTSRP1_SRPIO3_2_SHIFT      (6U)                                                /*!< LPC_SYSCON_STARTSRP1.SRPIO3_2 Position  */
#define LPC_SYSCON_STARTSRP1_SRPIO3_2(x)         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_STARTSRP1.SRPIO3_2 Field     */
#define LPC_SYSCON_STARTSRP1_SRPIO3_3_MASK       (0x80U)                                             /*!< LPC_SYSCON_STARTSRP1.SRPIO3_3 Mask      */
#define LPC_SYSCON_STARTSRP1_SRPIO3_3_SHIFT      (7U)                                                /*!< LPC_SYSCON_STARTSRP1.SRPIO3_3 Position  */
#define LPC_SYSCON_STARTSRP1_SRPIO3_3(x)         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_STARTSRP1.SRPIO3_3 Field     */
/* ------- PDSLEEPCFG Bit Fields                    ------ */
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL0_MASK     (0x7U)                                              /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL0 Mask    */
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL0_SHIFT    (0U)                                                /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL0 Position*/
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL0(x)       (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL0 Field   */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD_MASK        (0x8U)                                              /*!< LPC_SYSCON_PDSLEEPCFG.BOD_PD Mask       */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD_SHIFT       (3U)                                                /*!< LPC_SYSCON_PDSLEEPCFG.BOD_PD Position   */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD(x)          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_PDSLEEPCFG.BOD_PD Field      */
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL1_MASK     (0x30U)                                             /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL1 Mask    */
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL1_SHIFT    (4U)                                                /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL1 Position*/
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL1(x)       (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL1 Field   */
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK     (0x40U)                                             /*!< LPC_SYSCON_PDSLEEPCFG.WDTOSC_PD Mask    */
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT    (6U)                                                /*!< LPC_SYSCON_PDSLEEPCFG.WDTOSC_PD Position*/
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_PDSLEEPCFG.WDTOSC_PD Field   */
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL2_MASK     (0xF80U)                                            /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL2 Mask    */
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL2_SHIFT    (7U)                                                /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL2 Position*/
#define LPC_SYSCON_PDSLEEPCFG_FIXEDVAL2(x)       (((uint32_t)(((uint32_t)(x))<<7U))&0xF80UL)         /*!< LPC_SYSCON_PDSLEEPCFG.FIXEDVAL2 Field   */
/* ------- PDAWAKECFG Bit Fields                    ------ */
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_MASK     (0x1U)                                              /*!< LPC_SYSCON_PDAWAKECFG.IRCOUT_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT    (0U)                                                /*!< LPC_SYSCON_PDAWAKECFG.IRCOUT_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD(x)       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_PDAWAKECFG.IRCOUT_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD_MASK        (0x2U)                                              /*!< LPC_SYSCON_PDAWAKECFG.IRC_PD Mask       */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD_SHIFT       (1U)                                                /*!< LPC_SYSCON_PDAWAKECFG.IRC_PD Position   */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD(x)          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_PDAWAKECFG.IRC_PD Field      */
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD_MASK      (0x4U)                                              /*!< LPC_SYSCON_PDAWAKECFG.FLASH_PD Mask     */
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD_SHIFT     (2U)                                                /*!< LPC_SYSCON_PDAWAKECFG.FLASH_PD Position */
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD(x)        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_PDAWAKECFG.FLASH_PD Field    */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD_MASK        (0x8U)                                              /*!< LPC_SYSCON_PDAWAKECFG.BOD_PD Mask       */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD_SHIFT       (3U)                                                /*!< LPC_SYSCON_PDAWAKECFG.BOD_PD Position   */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD(x)          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_PDAWAKECFG.BOD_PD Field      */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD_MASK        (0x10U)                                             /*!< LPC_SYSCON_PDAWAKECFG.ADC_PD Mask       */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD_SHIFT       (4U)                                                /*!< LPC_SYSCON_PDAWAKECFG.ADC_PD Position   */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD(x)          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_PDAWAKECFG.ADC_PD Field      */
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_MASK     (0x20U)                                             /*!< LPC_SYSCON_PDAWAKECFG.SYSOSC_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT    (5U)                                                /*!< LPC_SYSCON_PDAWAKECFG.SYSOSC_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_PDAWAKECFG.SYSOSC_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_MASK     (0x40U)                                             /*!< LPC_SYSCON_PDAWAKECFG.WDTOSC_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT    (6U)                                                /*!< LPC_SYSCON_PDAWAKECFG.WDTOSC_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_PDAWAKECFG.WDTOSC_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_MASK     (0x80U)                                             /*!< LPC_SYSCON_PDAWAKECFG.SYSPLL_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT    (7U)                                                /*!< LPC_SYSCON_PDAWAKECFG.SYSPLL_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD(x)       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_PDAWAKECFG.SYSPLL_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_USBPLL_PD_MASK     (0x100U)                                            /*!< LPC_SYSCON_PDAWAKECFG.USBPLL_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_USBPLL_PD_SHIFT    (8U)                                                /*!< LPC_SYSCON_PDAWAKECFG.USBPLL_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_USBPLL_PD(x)       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_PDAWAKECFG.USBPLL_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL0_MASK     (0x200U)                                            /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL0 Mask    */
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL0_SHIFT    (9U)                                                /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL0 Position*/
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL0(x)       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL0 Field   */
#define LPC_SYSCON_PDAWAKECFG_USBPAD_PD_MASK     (0x400U)                                            /*!< LPC_SYSCON_PDAWAKECFG.USBPAD_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_USBPAD_PD_SHIFT    (10U)                                               /*!< LPC_SYSCON_PDAWAKECFG.USBPAD_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_USBPAD_PD(x)       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_SYSCON_PDAWAKECFG.USBPAD_PD Field   */
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL1_MASK     (0x800U)                                            /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL1 Mask    */
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL1_SHIFT    (11U)                                               /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL1 Position*/
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL1(x)       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL1 Field   */
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL2_MASK     (0x1000U)                                           /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL2 Mask    */
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL2_SHIFT    (12U)                                               /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL2 Position*/
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL2(x)       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL2 Field   */
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL3_MASK     (0xE000U)                                           /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL3 Mask    */
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL3_SHIFT    (13U)                                               /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL3 Position*/
#define LPC_SYSCON_PDAWAKECFG_FIXEDVAL3(x)       (((uint32_t)(((uint32_t)(x))<<13U))&0xE000UL)       /*!< LPC_SYSCON_PDAWAKECFG.FIXEDVAL3 Field   */
/* ------- PDRUNCFG Bit Fields                      ------ */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD_MASK       (0x1U)                                              /*!< LPC_SYSCON_PDRUNCFG.IRCOUT_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT      (0U)                                                /*!< LPC_SYSCON_PDRUNCFG.IRCOUT_PD Position  */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD(x)         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_SYSCON_PDRUNCFG.IRCOUT_PD Field     */
#define LPC_SYSCON_PDRUNCFG_IRC_PD_MASK          (0x2U)                                              /*!< LPC_SYSCON_PDRUNCFG.IRC_PD Mask         */
#define LPC_SYSCON_PDRUNCFG_IRC_PD_SHIFT         (1U)                                                /*!< LPC_SYSCON_PDRUNCFG.IRC_PD Position     */
#define LPC_SYSCON_PDRUNCFG_IRC_PD(x)            (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_SYSCON_PDRUNCFG.IRC_PD Field        */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD_MASK        (0x4U)                                              /*!< LPC_SYSCON_PDRUNCFG.FLASH_PD Mask       */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD_SHIFT       (2U)                                                /*!< LPC_SYSCON_PDRUNCFG.FLASH_PD Position   */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD(x)          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_SYSCON_PDRUNCFG.FLASH_PD Field      */
#define LPC_SYSCON_PDRUNCFG_BOD_PD_MASK          (0x8U)                                              /*!< LPC_SYSCON_PDRUNCFG.BOD_PD Mask         */
#define LPC_SYSCON_PDRUNCFG_BOD_PD_SHIFT         (3U)                                                /*!< LPC_SYSCON_PDRUNCFG.BOD_PD Position     */
#define LPC_SYSCON_PDRUNCFG_BOD_PD(x)            (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_SYSCON_PDRUNCFG.BOD_PD Field        */
#define LPC_SYSCON_PDRUNCFG_ADC_PD_MASK          (0x10U)                                             /*!< LPC_SYSCON_PDRUNCFG.ADC_PD Mask         */
#define LPC_SYSCON_PDRUNCFG_ADC_PD_SHIFT         (4U)                                                /*!< LPC_SYSCON_PDRUNCFG.ADC_PD Position     */
#define LPC_SYSCON_PDRUNCFG_ADC_PD(x)            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_SYSCON_PDRUNCFG.ADC_PD Field        */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD_MASK       (0x20U)                                             /*!< LPC_SYSCON_PDRUNCFG.SYSOSC_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT      (5U)                                                /*!< LPC_SYSCON_PDRUNCFG.SYSOSC_PD Position  */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD(x)         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_SYSCON_PDRUNCFG.SYSOSC_PD Field     */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD_MASK       (0x40U)                                             /*!< LPC_SYSCON_PDRUNCFG.WDTOSC_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT      (6U)                                                /*!< LPC_SYSCON_PDRUNCFG.WDTOSC_PD Position  */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD(x)         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_SYSCON_PDRUNCFG.WDTOSC_PD Field     */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD_MASK       (0x80U)                                             /*!< LPC_SYSCON_PDRUNCFG.SYSPLL_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT      (7U)                                                /*!< LPC_SYSCON_PDRUNCFG.SYSPLL_PD Position  */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD(x)         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_SYSCON_PDRUNCFG.SYSPLL_PD Field     */
#define LPC_SYSCON_PDRUNCFG_USBPLL_PD_MASK       (0x100U)                                            /*!< LPC_SYSCON_PDRUNCFG.USBPLL_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_USBPLL_PD_SHIFT      (8U)                                                /*!< LPC_SYSCON_PDRUNCFG.USBPLL_PD Position  */
#define LPC_SYSCON_PDRUNCFG_USBPLL_PD(x)         (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_SYSCON_PDRUNCFG.USBPLL_PD Field     */
#define LPC_SYSCON_PDRUNCFG_FIXEDVAL0_MASK       (0x200U)                                            /*!< LPC_SYSCON_PDRUNCFG.FIXEDVAL0 Mask      */
#define LPC_SYSCON_PDRUNCFG_FIXEDVAL0_SHIFT      (9U)                                                /*!< LPC_SYSCON_PDRUNCFG.FIXEDVAL0 Position  */
#define LPC_SYSCON_PDRUNCFG_FIXEDVAL0(x)         (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_SYSCON_PDRUNCFG.FIXEDVAL0 Field     */
#define LPC_SYSCON_PDRUNCFG_USBPAD_PD_MASK       (0x400U)                                            /*!< LPC_SYSCON_PDRUNCFG.USBPAD_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_USBPAD_PD_SHIFT      (10U)                                               /*!< LPC_SYSCON_PDRUNCFG.USBPAD_PD Position  */
#define LPC_SYSCON_PDRUNCFG_USBPAD_PD(x)         (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_SYSCON_PDRUNCFG.USBPAD_PD Field     */
#define LPC_SYSCON_PDRUNCFG_FIXEDVAL1_MASK       (0x800U)                                            /*!< LPC_SYSCON_PDRUNCFG.FIXEDVAL1 Mask      */
#define LPC_SYSCON_PDRUNCFG_FIXEDVAL1_SHIFT      (11U)                                               /*!< LPC_SYSCON_PDRUNCFG.FIXEDVAL1 Position  */
#define LPC_SYSCON_PDRUNCFG_FIXEDVAL1(x)         (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_SYSCON_PDRUNCFG.FIXEDVAL1 Field     */
/* ------- DEVICE_ID Bit Fields                     ------ */
#define LPC_SYSCON_DEVICE_ID_DEVICEID_MASK       (0xFFFFFFFFU)                                       /*!< LPC_SYSCON_DEVICE_ID.DEVICEID Mask      */
#define LPC_SYSCON_DEVICE_ID_DEVICEID_SHIFT      (0U)                                                /*!< LPC_SYSCON_DEVICE_ID.DEVICEID Position  */
#define LPC_SYSCON_DEVICE_ID_DEVICEID(x)         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_SYSCON_DEVICE_ID.DEVICEID Field     */
/**
 * @} */ /* End group SYSCON_Register_Masks_GROUP 
 */

/* LPC_SYSCON - Peripheral instance base addresses */
#define LPC_SYSCON_BasePtr             0x40048000UL //!< Peripheral base address
#define LPC_SYSCON                     ((LPC_SYSCON_Type *) LPC_SYSCON_BasePtr) //!< Freescale base pointer
#define LPC_SYSCON_BASE_PTR            (LPC_SYSCON) //!< Freescale style base pointer
#define LPC_SYSCON_IRQS { PIO0_0_IRQn, PIO0_1_IRQn, PIO0_2_IRQn, PIO0_3_IRQn, PIO0_4_IRQn, PIO0_5_IRQn, PIO0_6_IRQn, PIO0_7_IRQn, PIO0_8_IRQn, PIO0_9_IRQn, PIO0_10_IRQn, PIO0_11_IRQn, PIO1_0_IRQn, PIO1_1_IRQn, PIO1_2_IRQn, PIO1_3_IRQn, PIO1_4_IRQn, PIO1_5_IRQn, PIO1_6_IRQn, PIO1_7_IRQn, PIO1_8_IRQn, PIO1_9_IRQn, PIO1_10_IRQn, PIO1_11_IRQn, PIO2_0_IRQn, PIO2_1_IRQn, PIO2_2_IRQn, PIO2_3_IRQn, PIO2_4_IRQn, PIO2_5_IRQn, PIO2_6_IRQn, PIO2_7_IRQn, PIO2_8_IRQn, PIO2_9_IRQn, PIO2_10_IRQn, PIO2_11_IRQn, PIO3_0_IRQn, PIO3_1_IRQn, PIO3_2_IRQn, PIO3_3_IRQn, BOD_IRQn,  }

/**
 * @} */ /* End group SYSCON_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           LPC_UART (file:UART_LPC13xx)         ================ */
/* ================================================================================ */

/**
 * @brief UART
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct LPC_UART_Type {
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DLL;                       /**< 0000: Divisor Latch LSB. Least significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. When DLAB=1 */
      __I  uint32_t  RBR;                       /**< 0000: Receiver Buffer Register. Contains the next received character to be read. When DLAB=0 */
      __O  uint32_t  THR;                       /**< 0000: Transmit Holding Register. The next character to be transmitted is written here. When DLAB=0 */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DLM;                       /**< 0004: Divisor Latch MSB. Most significant byte of the baud rate divisor value. The full divisor is used to generate a baud rate from the fractional rate divider. When DLAB=1 */
      __IO uint32_t  IER;                       /**< 0004: Interrupt Enable Register. Contains individual interrupt enable bits for the 7 potential UART interrupts. When DLAB=0 */
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
} LPC_UART_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_UART' Position & Mask macros                    ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- DLL Bit Fields                           ------ */
#define LPC_UART_DLL_DLLSB_MASK                  (0xFFU)                                             /*!< LPC_UART_DLL.DLLSB Mask                 */
#define LPC_UART_DLL_DLLSB_SHIFT                 (0U)                                                /*!< LPC_UART_DLL.DLLSB Position             */
#define LPC_UART_DLL_DLLSB(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_UART_DLL.DLLSB Field                */
/* ------- RBR Bit Fields                           ------ */
#define LPC_UART_RBR_RBR_MASK                    (0xFFU)                                             /*!< LPC_UART_RBR.RBR Mask                   */
#define LPC_UART_RBR_RBR_SHIFT                   (0U)                                                /*!< LPC_UART_RBR.RBR Position               */
#define LPC_UART_RBR_RBR(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_UART_RBR.RBR Field                  */
/* ------- THR Bit Fields                           ------ */
#define LPC_UART_THR_THR_MASK                    (0xFFU)                                             /*!< LPC_UART_THR.THR Mask                   */
#define LPC_UART_THR_THR_SHIFT                   (0U)                                                /*!< LPC_UART_THR.THR Position               */
#define LPC_UART_THR_THR(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_UART_THR.THR Field                  */
/* ------- DLM Bit Fields                           ------ */
#define LPC_UART_DLM_DLMSB_MASK                  (0xFFU)                                             /*!< LPC_UART_DLM.DLMSB Mask                 */
#define LPC_UART_DLM_DLMSB_SHIFT                 (0U)                                                /*!< LPC_UART_DLM.DLMSB Position             */
#define LPC_UART_DLM_DLMSB(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_UART_DLM.DLMSB Field                */
/* ------- IER Bit Fields                           ------ */
#define LPC_UART_IER_RBRIE_MASK                  (0x1U)                                              /*!< LPC_UART_IER.RBRIE Mask                 */
#define LPC_UART_IER_RBRIE_SHIFT                 (0U)                                                /*!< LPC_UART_IER.RBRIE Position             */
#define LPC_UART_IER_RBRIE(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_UART_IER.RBRIE Field                */
#define LPC_UART_IER_THREIE_MASK                 (0x2U)                                              /*!< LPC_UART_IER.THREIE Mask                */
#define LPC_UART_IER_THREIE_SHIFT                (1U)                                                /*!< LPC_UART_IER.THREIE Position            */
#define LPC_UART_IER_THREIE(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_UART_IER.THREIE Field               */
#define LPC_UART_IER_RXLIE_MASK                  (0x4U)                                              /*!< LPC_UART_IER.RXLIE Mask                 */
#define LPC_UART_IER_RXLIE_SHIFT                 (2U)                                                /*!< LPC_UART_IER.RXLIE Position             */
#define LPC_UART_IER_RXLIE(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_UART_IER.RXLIE Field                */
#define LPC_UART_IER_ABEOINTEN_MASK              (0x100U)                                            /*!< LPC_UART_IER.ABEOINTEN Mask             */
#define LPC_UART_IER_ABEOINTEN_SHIFT             (8U)                                                /*!< LPC_UART_IER.ABEOINTEN Position         */
#define LPC_UART_IER_ABEOINTEN(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_UART_IER.ABEOINTEN Field            */
#define LPC_UART_IER_ABTOINTEN_MASK              (0x200U)                                            /*!< LPC_UART_IER.ABTOINTEN Mask             */
#define LPC_UART_IER_ABTOINTEN_SHIFT             (9U)                                                /*!< LPC_UART_IER.ABTOINTEN Position         */
#define LPC_UART_IER_ABTOINTEN(x)                (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_UART_IER.ABTOINTEN Field            */
/* ------- FCR Bit Fields                           ------ */
#define LPC_UART_FCR_FIFOEN_MASK                 (0x1U)                                              /*!< LPC_UART_FCR.FIFOEN Mask                */
#define LPC_UART_FCR_FIFOEN_SHIFT                (0U)                                                /*!< LPC_UART_FCR.FIFOEN Position            */
#define LPC_UART_FCR_FIFOEN(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_UART_FCR.FIFOEN Field               */
#define LPC_UART_FCR_RXFIFOR_MASK                (0x2U)                                              /*!< LPC_UART_FCR.RXFIFOR Mask               */
#define LPC_UART_FCR_RXFIFOR_SHIFT               (1U)                                                /*!< LPC_UART_FCR.RXFIFOR Position           */
#define LPC_UART_FCR_RXFIFOR(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_UART_FCR.RXFIFOR Field              */
#define LPC_UART_FCR_TXFIFOR_MASK                (0x4U)                                              /*!< LPC_UART_FCR.TXFIFOR Mask               */
#define LPC_UART_FCR_TXFIFOR_SHIFT               (2U)                                                /*!< LPC_UART_FCR.TXFIFOR Position           */
#define LPC_UART_FCR_TXFIFOR(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_UART_FCR.TXFIFOR Field              */
#define LPC_UART_FCR_RXTLVL_MASK                 (0xC0U)                                             /*!< LPC_UART_FCR.RXTLVL Mask                */
#define LPC_UART_FCR_RXTLVL_SHIFT                (6U)                                                /*!< LPC_UART_FCR.RXTLVL Position            */
#define LPC_UART_FCR_RXTLVL(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< LPC_UART_FCR.RXTLVL Field               */
/* ------- IIR Bit Fields                           ------ */
#define LPC_UART_IIR_INTSTATUS_MASK              (0x1U)                                              /*!< LPC_UART_IIR.INTSTATUS Mask             */
#define LPC_UART_IIR_INTSTATUS_SHIFT             (0U)                                                /*!< LPC_UART_IIR.INTSTATUS Position         */
#define LPC_UART_IIR_INTSTATUS(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_UART_IIR.INTSTATUS Field            */
#define LPC_UART_IIR_INTID_MASK                  (0xEU)                                              /*!< LPC_UART_IIR.INTID Mask                 */
#define LPC_UART_IIR_INTID_SHIFT                 (1U)                                                /*!< LPC_UART_IIR.INTID Position             */
#define LPC_UART_IIR_INTID(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0xEUL)           /*!< LPC_UART_IIR.INTID Field                */
#define LPC_UART_IIR_FIFOEN_MASK                 (0xC0U)                                             /*!< LPC_UART_IIR.FIFOEN Mask                */
#define LPC_UART_IIR_FIFOEN_SHIFT                (6U)                                                /*!< LPC_UART_IIR.FIFOEN Position            */
#define LPC_UART_IIR_FIFOEN(x)                   (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< LPC_UART_IIR.FIFOEN Field               */
#define LPC_UART_IIR_ABEOINT_MASK                (0x100U)                                            /*!< LPC_UART_IIR.ABEOINT Mask               */
#define LPC_UART_IIR_ABEOINT_SHIFT               (8U)                                                /*!< LPC_UART_IIR.ABEOINT Position           */
#define LPC_UART_IIR_ABEOINT(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_UART_IIR.ABEOINT Field              */
#define LPC_UART_IIR_ABTOINT_MASK                (0x200U)                                            /*!< LPC_UART_IIR.ABTOINT Mask               */
#define LPC_UART_IIR_ABTOINT_SHIFT               (9U)                                                /*!< LPC_UART_IIR.ABTOINT Position           */
#define LPC_UART_IIR_ABTOINT(x)                  (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_UART_IIR.ABTOINT Field              */
/* ------- LCR Bit Fields                           ------ */
#define LPC_UART_LCR_WLS_MASK                    (0x3U)                                              /*!< LPC_UART_LCR.WLS Mask                   */
#define LPC_UART_LCR_WLS_SHIFT                   (0U)                                                /*!< LPC_UART_LCR.WLS Position               */
#define LPC_UART_LCR_WLS(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPC_UART_LCR.WLS Field                  */
#define LPC_UART_LCR_SBS_MASK                    (0x4U)                                              /*!< LPC_UART_LCR.SBS Mask                   */
#define LPC_UART_LCR_SBS_SHIFT                   (2U)                                                /*!< LPC_UART_LCR.SBS Position               */
#define LPC_UART_LCR_SBS(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_UART_LCR.SBS Field                  */
#define LPC_UART_LCR_PE_MASK                     (0x8U)                                              /*!< LPC_UART_LCR.PE Mask                    */
#define LPC_UART_LCR_PE_SHIFT                    (3U)                                                /*!< LPC_UART_LCR.PE Position                */
#define LPC_UART_LCR_PE(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_UART_LCR.PE Field                   */
#define LPC_UART_LCR_PS_MASK                     (0x30U)                                             /*!< LPC_UART_LCR.PS Mask                    */
#define LPC_UART_LCR_PS_SHIFT                    (4U)                                                /*!< LPC_UART_LCR.PS Position                */
#define LPC_UART_LCR_PS(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< LPC_UART_LCR.PS Field                   */
#define LPC_UART_LCR_BC_MASK                     (0x40U)                                             /*!< LPC_UART_LCR.BC Mask                    */
#define LPC_UART_LCR_BC_SHIFT                    (6U)                                                /*!< LPC_UART_LCR.BC Position                */
#define LPC_UART_LCR_BC(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_UART_LCR.BC Field                   */
#define LPC_UART_LCR_DLAB_MASK                   (0x80U)                                             /*!< LPC_UART_LCR.DLAB Mask                  */
#define LPC_UART_LCR_DLAB_SHIFT                  (7U)                                                /*!< LPC_UART_LCR.DLAB Position              */
#define LPC_UART_LCR_DLAB(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_UART_LCR.DLAB Field                 */
/* ------- MCR Bit Fields                           ------ */
#define LPC_UART_MCR_DTRCTRL_MASK                (0x1U)                                              /*!< LPC_UART_MCR.DTRCTRL Mask               */
#define LPC_UART_MCR_DTRCTRL_SHIFT               (0U)                                                /*!< LPC_UART_MCR.DTRCTRL Position           */
#define LPC_UART_MCR_DTRCTRL(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_UART_MCR.DTRCTRL Field              */
#define LPC_UART_MCR_RTSCTRL_MASK                (0x2U)                                              /*!< LPC_UART_MCR.RTSCTRL Mask               */
#define LPC_UART_MCR_RTSCTRL_SHIFT               (1U)                                                /*!< LPC_UART_MCR.RTSCTRL Position           */
#define LPC_UART_MCR_RTSCTRL(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_UART_MCR.RTSCTRL Field              */
#define LPC_UART_MCR_LMS_MASK                    (0x10U)                                             /*!< LPC_UART_MCR.LMS Mask                   */
#define LPC_UART_MCR_LMS_SHIFT                   (4U)                                                /*!< LPC_UART_MCR.LMS Position               */
#define LPC_UART_MCR_LMS(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_UART_MCR.LMS Field                  */
#define LPC_UART_MCR_RTSEN_MASK                  (0x40U)                                             /*!< LPC_UART_MCR.RTSEN Mask                 */
#define LPC_UART_MCR_RTSEN_SHIFT                 (6U)                                                /*!< LPC_UART_MCR.RTSEN Position             */
#define LPC_UART_MCR_RTSEN(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_UART_MCR.RTSEN Field                */
#define LPC_UART_MCR_CTSEN_MASK                  (0x80U)                                             /*!< LPC_UART_MCR.CTSEN Mask                 */
#define LPC_UART_MCR_CTSEN_SHIFT                 (7U)                                                /*!< LPC_UART_MCR.CTSEN Position             */
#define LPC_UART_MCR_CTSEN(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_UART_MCR.CTSEN Field                */
/* ------- LSR Bit Fields                           ------ */
#define LPC_UART_LSR_RDR_MASK                    (0x1U)                                              /*!< LPC_UART_LSR.RDR Mask                   */
#define LPC_UART_LSR_RDR_SHIFT                   (0U)                                                /*!< LPC_UART_LSR.RDR Position               */
#define LPC_UART_LSR_RDR(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_UART_LSR.RDR Field                  */
#define LPC_UART_LSR_OE_MASK                     (0x2U)                                              /*!< LPC_UART_LSR.OE Mask                    */
#define LPC_UART_LSR_OE_SHIFT                    (1U)                                                /*!< LPC_UART_LSR.OE Position                */
#define LPC_UART_LSR_OE(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_UART_LSR.OE Field                   */
#define LPC_UART_LSR_PE_MASK                     (0x4U)                                              /*!< LPC_UART_LSR.PE Mask                    */
#define LPC_UART_LSR_PE_SHIFT                    (2U)                                                /*!< LPC_UART_LSR.PE Position                */
#define LPC_UART_LSR_PE(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_UART_LSR.PE Field                   */
#define LPC_UART_LSR_FE_MASK                     (0x8U)                                              /*!< LPC_UART_LSR.FE Mask                    */
#define LPC_UART_LSR_FE_SHIFT                    (3U)                                                /*!< LPC_UART_LSR.FE Position                */
#define LPC_UART_LSR_FE(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_UART_LSR.FE Field                   */
#define LPC_UART_LSR_BI_MASK                     (0x10U)                                             /*!< LPC_UART_LSR.BI Mask                    */
#define LPC_UART_LSR_BI_SHIFT                    (4U)                                                /*!< LPC_UART_LSR.BI Position                */
#define LPC_UART_LSR_BI(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_UART_LSR.BI Field                   */
#define LPC_UART_LSR_THRE_MASK                   (0x20U)                                             /*!< LPC_UART_LSR.THRE Mask                  */
#define LPC_UART_LSR_THRE_SHIFT                  (5U)                                                /*!< LPC_UART_LSR.THRE Position              */
#define LPC_UART_LSR_THRE(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_UART_LSR.THRE Field                 */
#define LPC_UART_LSR_TEMT_MASK                   (0x40U)                                             /*!< LPC_UART_LSR.TEMT Mask                  */
#define LPC_UART_LSR_TEMT_SHIFT                  (6U)                                                /*!< LPC_UART_LSR.TEMT Position              */
#define LPC_UART_LSR_TEMT(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_UART_LSR.TEMT Field                 */
#define LPC_UART_LSR_RXFE_MASK                   (0x80U)                                             /*!< LPC_UART_LSR.RXFE Mask                  */
#define LPC_UART_LSR_RXFE_SHIFT                  (7U)                                                /*!< LPC_UART_LSR.RXFE Position              */
#define LPC_UART_LSR_RXFE(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_UART_LSR.RXFE Field                 */
/* ------- MSR Bit Fields                           ------ */
#define LPC_UART_MSR_DELTACTS_MASK               (0x1U)                                              /*!< LPC_UART_MSR.DELTACTS Mask              */
#define LPC_UART_MSR_DELTACTS_SHIFT              (0U)                                                /*!< LPC_UART_MSR.DELTACTS Position          */
#define LPC_UART_MSR_DELTACTS(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_UART_MSR.DELTACTS Field             */
#define LPC_UART_MSR_DELTADSR_MASK               (0x2U)                                              /*!< LPC_UART_MSR.DELTADSR Mask              */
#define LPC_UART_MSR_DELTADSR_SHIFT              (1U)                                                /*!< LPC_UART_MSR.DELTADSR Position          */
#define LPC_UART_MSR_DELTADSR(x)                 (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_UART_MSR.DELTADSR Field             */
#define LPC_UART_MSR_TERI_MASK                   (0x4U)                                              /*!< LPC_UART_MSR.TERI Mask                  */
#define LPC_UART_MSR_TERI_SHIFT                  (2U)                                                /*!< LPC_UART_MSR.TERI Position              */
#define LPC_UART_MSR_TERI(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_UART_MSR.TERI Field                 */
#define LPC_UART_MSR_DELTADCD_MASK               (0x8U)                                              /*!< LPC_UART_MSR.DELTADCD Mask              */
#define LPC_UART_MSR_DELTADCD_SHIFT              (3U)                                                /*!< LPC_UART_MSR.DELTADCD Position          */
#define LPC_UART_MSR_DELTADCD(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_UART_MSR.DELTADCD Field             */
#define LPC_UART_MSR_CTS_MASK                    (0x10U)                                             /*!< LPC_UART_MSR.CTS Mask                   */
#define LPC_UART_MSR_CTS_SHIFT                   (4U)                                                /*!< LPC_UART_MSR.CTS Position               */
#define LPC_UART_MSR_CTS(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_UART_MSR.CTS Field                  */
#define LPC_UART_MSR_DSR_MASK                    (0x20U)                                             /*!< LPC_UART_MSR.DSR Mask                   */
#define LPC_UART_MSR_DSR_SHIFT                   (5U)                                                /*!< LPC_UART_MSR.DSR Position               */
#define LPC_UART_MSR_DSR(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_UART_MSR.DSR Field                  */
#define LPC_UART_MSR_RI_MASK                     (0x40U)                                             /*!< LPC_UART_MSR.RI Mask                    */
#define LPC_UART_MSR_RI_SHIFT                    (6U)                                                /*!< LPC_UART_MSR.RI Position                */
#define LPC_UART_MSR_RI(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_UART_MSR.RI Field                   */
#define LPC_UART_MSR_DCD_MASK                    (0x80U)                                             /*!< LPC_UART_MSR.DCD Mask                   */
#define LPC_UART_MSR_DCD_SHIFT                   (7U)                                                /*!< LPC_UART_MSR.DCD Position               */
#define LPC_UART_MSR_DCD(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_UART_MSR.DCD Field                  */
/* ------- SCR Bit Fields                           ------ */
#define LPC_UART_SCR_Pad_MASK                    (0xFFU)                                             /*!< LPC_UART_SCR.Pad Mask                   */
#define LPC_UART_SCR_Pad_SHIFT                   (0U)                                                /*!< LPC_UART_SCR.Pad Position               */
#define LPC_UART_SCR_Pad(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_UART_SCR.Pad Field                  */
/* ------- ACR Bit Fields                           ------ */
#define LPC_UART_ACR_START_MASK                  (0x1U)                                              /*!< LPC_UART_ACR.START Mask                 */
#define LPC_UART_ACR_START_SHIFT                 (0U)                                                /*!< LPC_UART_ACR.START Position             */
#define LPC_UART_ACR_START(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_UART_ACR.START Field                */
#define LPC_UART_ACR_MODE_MASK                   (0x2U)                                              /*!< LPC_UART_ACR.MODE Mask                  */
#define LPC_UART_ACR_MODE_SHIFT                  (1U)                                                /*!< LPC_UART_ACR.MODE Position              */
#define LPC_UART_ACR_MODE(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_UART_ACR.MODE Field                 */
#define LPC_UART_ACR_AUTORESTART_MASK            (0x4U)                                              /*!< LPC_UART_ACR.AUTORESTART Mask           */
#define LPC_UART_ACR_AUTORESTART_SHIFT           (2U)                                                /*!< LPC_UART_ACR.AUTORESTART Position       */
#define LPC_UART_ACR_AUTORESTART(x)              (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_UART_ACR.AUTORESTART Field          */
#define LPC_UART_ACR_ABEOINTCLR_MASK             (0x100U)                                            /*!< LPC_UART_ACR.ABEOINTCLR Mask            */
#define LPC_UART_ACR_ABEOINTCLR_SHIFT            (8U)                                                /*!< LPC_UART_ACR.ABEOINTCLR Position        */
#define LPC_UART_ACR_ABEOINTCLR(x)               (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_UART_ACR.ABEOINTCLR Field           */
#define LPC_UART_ACR_ABTOINTCLR_MASK             (0x200U)                                            /*!< LPC_UART_ACR.ABTOINTCLR Mask            */
#define LPC_UART_ACR_ABTOINTCLR_SHIFT            (9U)                                                /*!< LPC_UART_ACR.ABTOINTCLR Position        */
#define LPC_UART_ACR_ABTOINTCLR(x)               (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_UART_ACR.ABTOINTCLR Field           */
/* ------- FDR Bit Fields                           ------ */
#define LPC_UART_FDR_DIVADDVAL_MASK              (0xFU)                                              /*!< LPC_UART_FDR.DIVADDVAL Mask             */
#define LPC_UART_FDR_DIVADDVAL_SHIFT             (0U)                                                /*!< LPC_UART_FDR.DIVADDVAL Position         */
#define LPC_UART_FDR_DIVADDVAL(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< LPC_UART_FDR.DIVADDVAL Field            */
#define LPC_UART_FDR_MULVAL_MASK                 (0xF0U)                                             /*!< LPC_UART_FDR.MULVAL Mask                */
#define LPC_UART_FDR_MULVAL_SHIFT                (4U)                                                /*!< LPC_UART_FDR.MULVAL Position            */
#define LPC_UART_FDR_MULVAL(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< LPC_UART_FDR.MULVAL Field               */
/* ------- TER Bit Fields                           ------ */
#define LPC_UART_TER_TXEN_MASK                   (0x80U)                                             /*!< LPC_UART_TER.TXEN Mask                  */
#define LPC_UART_TER_TXEN_SHIFT                  (7U)                                                /*!< LPC_UART_TER.TXEN Position              */
#define LPC_UART_TER_TXEN(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_UART_TER.TXEN Field                 */
/* ------- RS485CTRL Bit Fields                     ------ */
#define LPC_UART_RS485CTRL_NMMEN_MASK            (0x1U)                                              /*!< LPC_UART_RS485CTRL.NMMEN Mask           */
#define LPC_UART_RS485CTRL_NMMEN_SHIFT           (0U)                                                /*!< LPC_UART_RS485CTRL.NMMEN Position       */
#define LPC_UART_RS485CTRL_NMMEN(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_UART_RS485CTRL.NMMEN Field          */
#define LPC_UART_RS485CTRL_RXDIS_MASK            (0x2U)                                              /*!< LPC_UART_RS485CTRL.RXDIS Mask           */
#define LPC_UART_RS485CTRL_RXDIS_SHIFT           (1U)                                                /*!< LPC_UART_RS485CTRL.RXDIS Position       */
#define LPC_UART_RS485CTRL_RXDIS(x)              (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_UART_RS485CTRL.RXDIS Field          */
#define LPC_UART_RS485CTRL_AADEN_MASK            (0x4U)                                              /*!< LPC_UART_RS485CTRL.AADEN Mask           */
#define LPC_UART_RS485CTRL_AADEN_SHIFT           (2U)                                                /*!< LPC_UART_RS485CTRL.AADEN Position       */
#define LPC_UART_RS485CTRL_AADEN(x)              (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_UART_RS485CTRL.AADEN Field          */
#define LPC_UART_RS485CTRL_SEL_MASK              (0x8U)                                              /*!< LPC_UART_RS485CTRL.SEL Mask             */
#define LPC_UART_RS485CTRL_SEL_SHIFT             (3U)                                                /*!< LPC_UART_RS485CTRL.SEL Position         */
#define LPC_UART_RS485CTRL_SEL(x)                (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_UART_RS485CTRL.SEL Field            */
#define LPC_UART_RS485CTRL_DCTRL_MASK            (0x10U)                                             /*!< LPC_UART_RS485CTRL.DCTRL Mask           */
#define LPC_UART_RS485CTRL_DCTRL_SHIFT           (4U)                                                /*!< LPC_UART_RS485CTRL.DCTRL Position       */
#define LPC_UART_RS485CTRL_DCTRL(x)              (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_UART_RS485CTRL.DCTRL Field          */
#define LPC_UART_RS485CTRL_OINV_MASK             (0x20U)                                             /*!< LPC_UART_RS485CTRL.OINV Mask            */
#define LPC_UART_RS485CTRL_OINV_SHIFT            (5U)                                                /*!< LPC_UART_RS485CTRL.OINV Position        */
#define LPC_UART_RS485CTRL_OINV(x)               (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_UART_RS485CTRL.OINV Field           */
/* ------- RS485ADRMATCH Bit Fields                 ------ */
#define LPC_UART_RS485ADRMATCH_ADRMATCH_MASK     (0xFFU)                                             /*!< LPC_UART_RS485ADRMATCH.ADRMATCH Mask    */
#define LPC_UART_RS485ADRMATCH_ADRMATCH_SHIFT    (0U)                                                /*!< LPC_UART_RS485ADRMATCH.ADRMATCH Position*/
#define LPC_UART_RS485ADRMATCH_ADRMATCH(x)       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_UART_RS485ADRMATCH.ADRMATCH Field   */
/* ------- RS485DLY Bit Fields                      ------ */
#define LPC_UART_RS485DLY_DLY_MASK               (0xFFU)                                             /*!< LPC_UART_RS485DLY.DLY Mask              */
#define LPC_UART_RS485DLY_DLY_SHIFT              (0U)                                                /*!< LPC_UART_RS485DLY.DLY Position          */
#define LPC_UART_RS485DLY_DLY(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_UART_RS485DLY.DLY Field             */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* LPC_UART - Peripheral instance base addresses */
#define LPC_UART_BasePtr               0x40008000UL //!< Peripheral base address
#define LPC_UART                       ((LPC_UART_Type *) LPC_UART_BasePtr) //!< Freescale base pointer
#define LPC_UART_BASE_PTR              (LPC_UART) //!< Freescale style base pointer
#define LPC_UART_IRQS { UART_IRQn,  }

/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USB_Peripheral_access_layer_GROUP USB Peripheral Access Layer
* @brief C Struct for USB
* @{
*/

/* ================================================================================ */
/* ================           LPC_USB (file:USB_LPC13xx)           ================ */
/* ================================================================================ */

/**
 * @brief USB device controller
 */
/**
* @addtogroup USB_structs_GROUP USB struct
* @brief Struct for USB
* @{
*/
typedef struct LPC_USB_Type {
   __I  uint32_t  DEVINTST;                     /**< 0000: USB Device Interrupt Status                                  */
   __IO uint32_t  DEVINTEN;                     /**< 0004: USB Device Interrupt Enable                                  */
   __O  uint32_t  DEVINTCTRL;                   /**< 0008: USB Device Interrupt Clear                                   */
   __O  uint32_t  DEVINTSET;                    /**< 000C: USB Device Interrupt Set                                     */
   __O  uint32_t  CMDCODE;                      /**< 0010: USB Command Code                                             */
   __I  uint32_t  CMDDATA;                      /**< 0014: USB Command Data                                             */
   __I  uint32_t  RXDATA;                       /**< 0018: USB Receive Data                                             */
   __O  uint32_t  TXDATA;                       /**< 001C: USB Transmit Data                                            */
   __I  uint32_t  RXPLEN;                       /**< 0020: USB Receive Packet Length                                    */
   __O  uint32_t  TXPLENn;                      /**< 0024: USB Transmit Packet Length                                   */
   __IO uint32_t  CTRL;                         /**< 0028: USB Control                                                  */
   __O  uint32_t  DEVFIQSEL;                    /**< 002C: USB Device FIQ select                                        */
} LPC_USB_Type;

/**
 * @} */ /* End group USB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_USB' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup USB_Register_Masks_GROUP USB Register Masks
* @brief Register Masks for USB
* @{
*/
/* ------- DEVINTST Bit Fields                      ------ */
#define LPC_USB_DEVINTST_FRAME_MASK              (0x1U)                                              /*!< LPC_USB_DEVINTST.FRAME Mask             */
#define LPC_USB_DEVINTST_FRAME_SHIFT             (0U)                                                /*!< LPC_USB_DEVINTST.FRAME Position         */
#define LPC_USB_DEVINTST_FRAME(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_USB_DEVINTST.FRAME Field            */
#define LPC_USB_DEVINTST_EP0_MASK                (0x2U)                                              /*!< LPC_USB_DEVINTST.EP0 Mask               */
#define LPC_USB_DEVINTST_EP0_SHIFT               (1U)                                                /*!< LPC_USB_DEVINTST.EP0 Position           */
#define LPC_USB_DEVINTST_EP0(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_USB_DEVINTST.EP0 Field              */
#define LPC_USB_DEVINTST_EP1_MASK                (0x4U)                                              /*!< LPC_USB_DEVINTST.EP1 Mask               */
#define LPC_USB_DEVINTST_EP1_SHIFT               (2U)                                                /*!< LPC_USB_DEVINTST.EP1 Position           */
#define LPC_USB_DEVINTST_EP1(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_USB_DEVINTST.EP1 Field              */
#define LPC_USB_DEVINTST_EP2_MASK                (0x8U)                                              /*!< LPC_USB_DEVINTST.EP2 Mask               */
#define LPC_USB_DEVINTST_EP2_SHIFT               (3U)                                                /*!< LPC_USB_DEVINTST.EP2 Position           */
#define LPC_USB_DEVINTST_EP2(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_USB_DEVINTST.EP2 Field              */
#define LPC_USB_DEVINTST_EP3_MASK                (0x10U)                                             /*!< LPC_USB_DEVINTST.EP3 Mask               */
#define LPC_USB_DEVINTST_EP3_SHIFT               (4U)                                                /*!< LPC_USB_DEVINTST.EP3 Position           */
#define LPC_USB_DEVINTST_EP3(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_USB_DEVINTST.EP3 Field              */
#define LPC_USB_DEVINTST_EP4_MASK                (0x20U)                                             /*!< LPC_USB_DEVINTST.EP4 Mask               */
#define LPC_USB_DEVINTST_EP4_SHIFT               (5U)                                                /*!< LPC_USB_DEVINTST.EP4 Position           */
#define LPC_USB_DEVINTST_EP4(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_USB_DEVINTST.EP4 Field              */
#define LPC_USB_DEVINTST_EP5_MASK                (0x40U)                                             /*!< LPC_USB_DEVINTST.EP5 Mask               */
#define LPC_USB_DEVINTST_EP5_SHIFT               (6U)                                                /*!< LPC_USB_DEVINTST.EP5 Position           */
#define LPC_USB_DEVINTST_EP5(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_USB_DEVINTST.EP5 Field              */
#define LPC_USB_DEVINTST_EP6_MASK                (0x80U)                                             /*!< LPC_USB_DEVINTST.EP6 Mask               */
#define LPC_USB_DEVINTST_EP6_SHIFT               (7U)                                                /*!< LPC_USB_DEVINTST.EP6 Position           */
#define LPC_USB_DEVINTST_EP6(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_USB_DEVINTST.EP6 Field              */
#define LPC_USB_DEVINTST_EP7_MASK                (0x100U)                                            /*!< LPC_USB_DEVINTST.EP7 Mask               */
#define LPC_USB_DEVINTST_EP7_SHIFT               (8U)                                                /*!< LPC_USB_DEVINTST.EP7 Position           */
#define LPC_USB_DEVINTST_EP7(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_USB_DEVINTST.EP7 Field              */
#define LPC_USB_DEVINTST_DEV_STAT_MASK           (0x200U)                                            /*!< LPC_USB_DEVINTST.DEV_STAT Mask          */
#define LPC_USB_DEVINTST_DEV_STAT_SHIFT          (9U)                                                /*!< LPC_USB_DEVINTST.DEV_STAT Position      */
#define LPC_USB_DEVINTST_DEV_STAT(x)             (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_USB_DEVINTST.DEV_STAT Field         */
#define LPC_USB_DEVINTST_CC_EMPTY_MASK           (0x400U)                                            /*!< LPC_USB_DEVINTST.CC_EMPTY Mask          */
#define LPC_USB_DEVINTST_CC_EMPTY_SHIFT          (10U)                                               /*!< LPC_USB_DEVINTST.CC_EMPTY Position      */
#define LPC_USB_DEVINTST_CC_EMPTY(x)             (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_USB_DEVINTST.CC_EMPTY Field         */
#define LPC_USB_DEVINTST_CD_FULL_MASK            (0x800U)                                            /*!< LPC_USB_DEVINTST.CD_FULL Mask           */
#define LPC_USB_DEVINTST_CD_FULL_SHIFT           (11U)                                               /*!< LPC_USB_DEVINTST.CD_FULL Position       */
#define LPC_USB_DEVINTST_CD_FULL(x)              (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_USB_DEVINTST.CD_FULL Field          */
#define LPC_USB_DEVINTST_RxENDPKT_MASK           (0x1000U)                                           /*!< LPC_USB_DEVINTST.RxENDPKT Mask          */
#define LPC_USB_DEVINTST_RxENDPKT_SHIFT          (12U)                                               /*!< LPC_USB_DEVINTST.RxENDPKT Position      */
#define LPC_USB_DEVINTST_RxENDPKT(x)             (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_USB_DEVINTST.RxENDPKT Field         */
#define LPC_USB_DEVINTST_TxENDPKT_MASK           (0x2000U)                                           /*!< LPC_USB_DEVINTST.TxENDPKT Mask          */
#define LPC_USB_DEVINTST_TxENDPKT_SHIFT          (13U)                                               /*!< LPC_USB_DEVINTST.TxENDPKT Position      */
#define LPC_USB_DEVINTST_TxENDPKT(x)             (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_USB_DEVINTST.TxENDPKT Field         */
/* ------- DEVINTEN Bit Fields                      ------ */
#define LPC_USB_DEVINTEN_FRAME_EN_MASK           (0x1U)                                              /*!< LPC_USB_DEVINTEN.FRAME_EN Mask          */
#define LPC_USB_DEVINTEN_FRAME_EN_SHIFT          (0U)                                                /*!< LPC_USB_DEVINTEN.FRAME_EN Position      */
#define LPC_USB_DEVINTEN_FRAME_EN(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_USB_DEVINTEN.FRAME_EN Field         */
#define LPC_USB_DEVINTEN_EP0_EN_MASK             (0x2U)                                              /*!< LPC_USB_DEVINTEN.EP0_EN Mask            */
#define LPC_USB_DEVINTEN_EP0_EN_SHIFT            (1U)                                                /*!< LPC_USB_DEVINTEN.EP0_EN Position        */
#define LPC_USB_DEVINTEN_EP0_EN(x)               (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_USB_DEVINTEN.EP0_EN Field           */
#define LPC_USB_DEVINTEN_EP1_EN_MASK             (0x4U)                                              /*!< LPC_USB_DEVINTEN.EP1_EN Mask            */
#define LPC_USB_DEVINTEN_EP1_EN_SHIFT            (2U)                                                /*!< LPC_USB_DEVINTEN.EP1_EN Position        */
#define LPC_USB_DEVINTEN_EP1_EN(x)               (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_USB_DEVINTEN.EP1_EN Field           */
#define LPC_USB_DEVINTEN_EP2_EN_MASK             (0x8U)                                              /*!< LPC_USB_DEVINTEN.EP2_EN Mask            */
#define LPC_USB_DEVINTEN_EP2_EN_SHIFT            (3U)                                                /*!< LPC_USB_DEVINTEN.EP2_EN Position        */
#define LPC_USB_DEVINTEN_EP2_EN(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_USB_DEVINTEN.EP2_EN Field           */
#define LPC_USB_DEVINTEN_EP3_EN_MASK             (0x10U)                                             /*!< LPC_USB_DEVINTEN.EP3_EN Mask            */
#define LPC_USB_DEVINTEN_EP3_EN_SHIFT            (4U)                                                /*!< LPC_USB_DEVINTEN.EP3_EN Position        */
#define LPC_USB_DEVINTEN_EP3_EN(x)               (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_USB_DEVINTEN.EP3_EN Field           */
#define LPC_USB_DEVINTEN_EP4_EN_MASK             (0x20U)                                             /*!< LPC_USB_DEVINTEN.EP4_EN Mask            */
#define LPC_USB_DEVINTEN_EP4_EN_SHIFT            (5U)                                                /*!< LPC_USB_DEVINTEN.EP4_EN Position        */
#define LPC_USB_DEVINTEN_EP4_EN(x)               (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_USB_DEVINTEN.EP4_EN Field           */
#define LPC_USB_DEVINTEN_EP5_EN_MASK             (0x40U)                                             /*!< LPC_USB_DEVINTEN.EP5_EN Mask            */
#define LPC_USB_DEVINTEN_EP5_EN_SHIFT            (6U)                                                /*!< LPC_USB_DEVINTEN.EP5_EN Position        */
#define LPC_USB_DEVINTEN_EP5_EN(x)               (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_USB_DEVINTEN.EP5_EN Field           */
#define LPC_USB_DEVINTEN_EP6_EN_MASK             (0x80U)                                             /*!< LPC_USB_DEVINTEN.EP6_EN Mask            */
#define LPC_USB_DEVINTEN_EP6_EN_SHIFT            (7U)                                                /*!< LPC_USB_DEVINTEN.EP6_EN Position        */
#define LPC_USB_DEVINTEN_EP6_EN(x)               (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_USB_DEVINTEN.EP6_EN Field           */
#define LPC_USB_DEVINTEN_EP7_EN_MASK             (0x100U)                                            /*!< LPC_USB_DEVINTEN.EP7_EN Mask            */
#define LPC_USB_DEVINTEN_EP7_EN_SHIFT            (8U)                                                /*!< LPC_USB_DEVINTEN.EP7_EN Position        */
#define LPC_USB_DEVINTEN_EP7_EN(x)               (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_USB_DEVINTEN.EP7_EN Field           */
#define LPC_USB_DEVINTEN_DEV_STAT_EN_MASK        (0x200U)                                            /*!< LPC_USB_DEVINTEN.DEV_STAT_EN Mask       */
#define LPC_USB_DEVINTEN_DEV_STAT_EN_SHIFT       (9U)                                                /*!< LPC_USB_DEVINTEN.DEV_STAT_EN Position   */
#define LPC_USB_DEVINTEN_DEV_STAT_EN(x)          (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_USB_DEVINTEN.DEV_STAT_EN Field      */
#define LPC_USB_DEVINTEN_CC_EMPTY_EN_MASK        (0x400U)                                            /*!< LPC_USB_DEVINTEN.CC_EMPTY_EN Mask       */
#define LPC_USB_DEVINTEN_CC_EMPTY_EN_SHIFT       (10U)                                               /*!< LPC_USB_DEVINTEN.CC_EMPTY_EN Position   */
#define LPC_USB_DEVINTEN_CC_EMPTY_EN(x)          (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_USB_DEVINTEN.CC_EMPTY_EN Field      */
#define LPC_USB_DEVINTEN_CD_FULL_EN_MASK         (0x800U)                                            /*!< LPC_USB_DEVINTEN.CD_FULL_EN Mask        */
#define LPC_USB_DEVINTEN_CD_FULL_EN_SHIFT        (11U)                                               /*!< LPC_USB_DEVINTEN.CD_FULL_EN Position    */
#define LPC_USB_DEVINTEN_CD_FULL_EN(x)           (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_USB_DEVINTEN.CD_FULL_EN Field       */
#define LPC_USB_DEVINTEN_RXENDPKT_EN_MASK        (0x1000U)                                           /*!< LPC_USB_DEVINTEN.RXENDPKT_EN Mask       */
#define LPC_USB_DEVINTEN_RXENDPKT_EN_SHIFT       (12U)                                               /*!< LPC_USB_DEVINTEN.RXENDPKT_EN Position   */
#define LPC_USB_DEVINTEN_RXENDPKT_EN(x)          (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_USB_DEVINTEN.RXENDPKT_EN Field      */
#define LPC_USB_DEVINTEN_TXENDPKT_EN_MASK        (0x2000U)                                           /*!< LPC_USB_DEVINTEN.TXENDPKT_EN Mask       */
#define LPC_USB_DEVINTEN_TXENDPKT_EN_SHIFT       (13U)                                               /*!< LPC_USB_DEVINTEN.TXENDPKT_EN Position   */
#define LPC_USB_DEVINTEN_TXENDPKT_EN(x)          (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_USB_DEVINTEN.TXENDPKT_EN Field      */
/* ------- DEVINTCTRL Bit Fields                    ------ */
#define LPC_USB_DEVINTCTRL_FRAME_CLR_MASK        (0x1U)                                              /*!< LPC_USB_DEVINTCTRL.FRAME_CLR Mask       */
#define LPC_USB_DEVINTCTRL_FRAME_CLR_SHIFT       (0U)                                                /*!< LPC_USB_DEVINTCTRL.FRAME_CLR Position   */
#define LPC_USB_DEVINTCTRL_FRAME_CLR(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_USB_DEVINTCTRL.FRAME_CLR Field      */
#define LPC_USB_DEVINTCTRL_EP0_CLR_MASK          (0x2U)                                              /*!< LPC_USB_DEVINTCTRL.EP0_CLR Mask         */
#define LPC_USB_DEVINTCTRL_EP0_CLR_SHIFT         (1U)                                                /*!< LPC_USB_DEVINTCTRL.EP0_CLR Position     */
#define LPC_USB_DEVINTCTRL_EP0_CLR(x)            (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_USB_DEVINTCTRL.EP0_CLR Field        */
#define LPC_USB_DEVINTCTRL_EP1_CLR_MASK          (0x4U)                                              /*!< LPC_USB_DEVINTCTRL.EP1_CLR Mask         */
#define LPC_USB_DEVINTCTRL_EP1_CLR_SHIFT         (2U)                                                /*!< LPC_USB_DEVINTCTRL.EP1_CLR Position     */
#define LPC_USB_DEVINTCTRL_EP1_CLR(x)            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_USB_DEVINTCTRL.EP1_CLR Field        */
#define LPC_USB_DEVINTCTRL_EP2_CLR_MASK          (0x8U)                                              /*!< LPC_USB_DEVINTCTRL.EP2_CLR Mask         */
#define LPC_USB_DEVINTCTRL_EP2_CLR_SHIFT         (3U)                                                /*!< LPC_USB_DEVINTCTRL.EP2_CLR Position     */
#define LPC_USB_DEVINTCTRL_EP2_CLR(x)            (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_USB_DEVINTCTRL.EP2_CLR Field        */
#define LPC_USB_DEVINTCTRL_EP3_CLR_MASK          (0x10U)                                             /*!< LPC_USB_DEVINTCTRL.EP3_CLR Mask         */
#define LPC_USB_DEVINTCTRL_EP3_CLR_SHIFT         (4U)                                                /*!< LPC_USB_DEVINTCTRL.EP3_CLR Position     */
#define LPC_USB_DEVINTCTRL_EP3_CLR(x)            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_USB_DEVINTCTRL.EP3_CLR Field        */
#define LPC_USB_DEVINTCTRL_EP4_CLR_MASK          (0x20U)                                             /*!< LPC_USB_DEVINTCTRL.EP4_CLR Mask         */
#define LPC_USB_DEVINTCTRL_EP4_CLR_SHIFT         (5U)                                                /*!< LPC_USB_DEVINTCTRL.EP4_CLR Position     */
#define LPC_USB_DEVINTCTRL_EP4_CLR(x)            (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_USB_DEVINTCTRL.EP4_CLR Field        */
#define LPC_USB_DEVINTCTRL_EP5_CLR_MASK          (0x40U)                                             /*!< LPC_USB_DEVINTCTRL.EP5_CLR Mask         */
#define LPC_USB_DEVINTCTRL_EP5_CLR_SHIFT         (6U)                                                /*!< LPC_USB_DEVINTCTRL.EP5_CLR Position     */
#define LPC_USB_DEVINTCTRL_EP5_CLR(x)            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_USB_DEVINTCTRL.EP5_CLR Field        */
#define LPC_USB_DEVINTCTRL_EP6_CLR_MASK          (0x80U)                                             /*!< LPC_USB_DEVINTCTRL.EP6_CLR Mask         */
#define LPC_USB_DEVINTCTRL_EP6_CLR_SHIFT         (7U)                                                /*!< LPC_USB_DEVINTCTRL.EP6_CLR Position     */
#define LPC_USB_DEVINTCTRL_EP6_CLR(x)            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_USB_DEVINTCTRL.EP6_CLR Field        */
#define LPC_USB_DEVINTCTRL_EP7_CLR_MASK          (0x100U)                                            /*!< LPC_USB_DEVINTCTRL.EP7_CLR Mask         */
#define LPC_USB_DEVINTCTRL_EP7_CLR_SHIFT         (8U)                                                /*!< LPC_USB_DEVINTCTRL.EP7_CLR Position     */
#define LPC_USB_DEVINTCTRL_EP7_CLR(x)            (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_USB_DEVINTCTRL.EP7_CLR Field        */
#define LPC_USB_DEVINTCTRL_DEV_STAT_CLR_MASK     (0x200U)                                            /*!< LPC_USB_DEVINTCTRL.DEV_STAT_CLR Mask    */
#define LPC_USB_DEVINTCTRL_DEV_STAT_CLR_SHIFT    (9U)                                                /*!< LPC_USB_DEVINTCTRL.DEV_STAT_CLR Position*/
#define LPC_USB_DEVINTCTRL_DEV_STAT_CLR(x)       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_USB_DEVINTCTRL.DEV_STAT_CLR Field   */
#define LPC_USB_DEVINTCTRL_CC_EMPTY_CLR_MASK     (0x400U)                                            /*!< LPC_USB_DEVINTCTRL.CC_EMPTY_CLR Mask    */
#define LPC_USB_DEVINTCTRL_CC_EMPTY_CLR_SHIFT    (10U)                                               /*!< LPC_USB_DEVINTCTRL.CC_EMPTY_CLR Position*/
#define LPC_USB_DEVINTCTRL_CC_EMPTY_CLR(x)       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_USB_DEVINTCTRL.CC_EMPTY_CLR Field   */
#define LPC_USB_DEVINTCTRL_CD_FULL_CLR_MASK      (0x800U)                                            /*!< LPC_USB_DEVINTCTRL.CD_FULL_CLR Mask     */
#define LPC_USB_DEVINTCTRL_CD_FULL_CLR_SHIFT     (11U)                                               /*!< LPC_USB_DEVINTCTRL.CD_FULL_CLR Position */
#define LPC_USB_DEVINTCTRL_CD_FULL_CLR(x)        (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_USB_DEVINTCTRL.CD_FULL_CLR Field    */
#define LPC_USB_DEVINTCTRL_RXENDPKT_CLR_MASK     (0x1000U)                                           /*!< LPC_USB_DEVINTCTRL.RXENDPKT_CLR Mask    */
#define LPC_USB_DEVINTCTRL_RXENDPKT_CLR_SHIFT    (12U)                                               /*!< LPC_USB_DEVINTCTRL.RXENDPKT_CLR Position*/
#define LPC_USB_DEVINTCTRL_RXENDPKT_CLR(x)       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_USB_DEVINTCTRL.RXENDPKT_CLR Field   */
#define LPC_USB_DEVINTCTRL_TXENDPKT_CLR_MASK     (0x2000U)                                           /*!< LPC_USB_DEVINTCTRL.TXENDPKT_CLR Mask    */
#define LPC_USB_DEVINTCTRL_TXENDPKT_CLR_SHIFT    (13U)                                               /*!< LPC_USB_DEVINTCTRL.TXENDPKT_CLR Position*/
#define LPC_USB_DEVINTCTRL_TXENDPKT_CLR(x)       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_USB_DEVINTCTRL.TXENDPKT_CLR Field   */
/* ------- DEVINTSET Bit Fields                     ------ */
#define LPC_USB_DEVINTSET_FRAME_SET_MASK         (0x1U)                                              /*!< LPC_USB_DEVINTSET.FRAME_SET Mask        */
#define LPC_USB_DEVINTSET_FRAME_SET_SHIFT        (0U)                                                /*!< LPC_USB_DEVINTSET.FRAME_SET Position    */
#define LPC_USB_DEVINTSET_FRAME_SET(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_USB_DEVINTSET.FRAME_SET Field       */
#define LPC_USB_DEVINTSET_EP0_SET_MASK           (0x2U)                                              /*!< LPC_USB_DEVINTSET.EP0_SET Mask          */
#define LPC_USB_DEVINTSET_EP0_SET_SHIFT          (1U)                                                /*!< LPC_USB_DEVINTSET.EP0_SET Position      */
#define LPC_USB_DEVINTSET_EP0_SET(x)             (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_USB_DEVINTSET.EP0_SET Field         */
#define LPC_USB_DEVINTSET_EP1_SET_MASK           (0x4U)                                              /*!< LPC_USB_DEVINTSET.EP1_SET Mask          */
#define LPC_USB_DEVINTSET_EP1_SET_SHIFT          (2U)                                                /*!< LPC_USB_DEVINTSET.EP1_SET Position      */
#define LPC_USB_DEVINTSET_EP1_SET(x)             (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_USB_DEVINTSET.EP1_SET Field         */
#define LPC_USB_DEVINTSET_EP2_SET_MASK           (0x8U)                                              /*!< LPC_USB_DEVINTSET.EP2_SET Mask          */
#define LPC_USB_DEVINTSET_EP2_SET_SHIFT          (3U)                                                /*!< LPC_USB_DEVINTSET.EP2_SET Position      */
#define LPC_USB_DEVINTSET_EP2_SET(x)             (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_USB_DEVINTSET.EP2_SET Field         */
#define LPC_USB_DEVINTSET_EP3_SET_MASK           (0x10U)                                             /*!< LPC_USB_DEVINTSET.EP3_SET Mask          */
#define LPC_USB_DEVINTSET_EP3_SET_SHIFT          (4U)                                                /*!< LPC_USB_DEVINTSET.EP3_SET Position      */
#define LPC_USB_DEVINTSET_EP3_SET(x)             (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_USB_DEVINTSET.EP3_SET Field         */
#define LPC_USB_DEVINTSET_EP4_SET_MASK           (0x20U)                                             /*!< LPC_USB_DEVINTSET.EP4_SET Mask          */
#define LPC_USB_DEVINTSET_EP4_SET_SHIFT          (5U)                                                /*!< LPC_USB_DEVINTSET.EP4_SET Position      */
#define LPC_USB_DEVINTSET_EP4_SET(x)             (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPC_USB_DEVINTSET.EP4_SET Field         */
#define LPC_USB_DEVINTSET_EP5_SET_MASK           (0x40U)                                             /*!< LPC_USB_DEVINTSET.EP5_SET Mask          */
#define LPC_USB_DEVINTSET_EP5_SET_SHIFT          (6U)                                                /*!< LPC_USB_DEVINTSET.EP5_SET Position      */
#define LPC_USB_DEVINTSET_EP5_SET(x)             (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPC_USB_DEVINTSET.EP5_SET Field         */
#define LPC_USB_DEVINTSET_EP6_SET_MASK           (0x80U)                                             /*!< LPC_USB_DEVINTSET.EP6_SET Mask          */
#define LPC_USB_DEVINTSET_EP6_SET_SHIFT          (7U)                                                /*!< LPC_USB_DEVINTSET.EP6_SET Position      */
#define LPC_USB_DEVINTSET_EP6_SET(x)             (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPC_USB_DEVINTSET.EP6_SET Field         */
#define LPC_USB_DEVINTSET_EP7_SET_MASK           (0x100U)                                            /*!< LPC_USB_DEVINTSET.EP7_SET Mask          */
#define LPC_USB_DEVINTSET_EP7_SET_SHIFT          (8U)                                                /*!< LPC_USB_DEVINTSET.EP7_SET Position      */
#define LPC_USB_DEVINTSET_EP7_SET(x)             (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPC_USB_DEVINTSET.EP7_SET Field         */
#define LPC_USB_DEVINTSET_DEV_STAT_SET_MASK      (0x200U)                                            /*!< LPC_USB_DEVINTSET.DEV_STAT_SET Mask     */
#define LPC_USB_DEVINTSET_DEV_STAT_SET_SHIFT     (9U)                                                /*!< LPC_USB_DEVINTSET.DEV_STAT_SET Position */
#define LPC_USB_DEVINTSET_DEV_STAT_SET(x)        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPC_USB_DEVINTSET.DEV_STAT_SET Field    */
#define LPC_USB_DEVINTSET_CC_EMPTY_SET_MASK      (0x400U)                                            /*!< LPC_USB_DEVINTSET.CC_EMPTY_SET Mask     */
#define LPC_USB_DEVINTSET_CC_EMPTY_SET_SHIFT     (10U)                                               /*!< LPC_USB_DEVINTSET.CC_EMPTY_SET Position */
#define LPC_USB_DEVINTSET_CC_EMPTY_SET(x)        (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_USB_DEVINTSET.CC_EMPTY_SET Field    */
#define LPC_USB_DEVINTSET_CD_FULL_SET_MASK       (0x800U)                                            /*!< LPC_USB_DEVINTSET.CD_FULL_SET Mask      */
#define LPC_USB_DEVINTSET_CD_FULL_SET_SHIFT      (11U)                                               /*!< LPC_USB_DEVINTSET.CD_FULL_SET Position  */
#define LPC_USB_DEVINTSET_CD_FULL_SET(x)         (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPC_USB_DEVINTSET.CD_FULL_SET Field     */
#define LPC_USB_DEVINTSET_RXENDPKT_SET_MASK      (0x1000U)                                           /*!< LPC_USB_DEVINTSET.RXENDPKT_SET Mask     */
#define LPC_USB_DEVINTSET_RXENDPKT_SET_SHIFT     (12U)                                               /*!< LPC_USB_DEVINTSET.RXENDPKT_SET Position */
#define LPC_USB_DEVINTSET_RXENDPKT_SET(x)        (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPC_USB_DEVINTSET.RXENDPKT_SET Field    */
#define LPC_USB_DEVINTSET_TXENDPKT_SET_MASK      (0x2000U)                                           /*!< LPC_USB_DEVINTSET.TXENDPKT_SET Mask     */
#define LPC_USB_DEVINTSET_TXENDPKT_SET_SHIFT     (13U)                                               /*!< LPC_USB_DEVINTSET.TXENDPKT_SET Position */
#define LPC_USB_DEVINTSET_TXENDPKT_SET(x)        (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPC_USB_DEVINTSET.TXENDPKT_SET Field    */
/* ------- CMDCODE Bit Fields                       ------ */
#define LPC_USB_CMDCODE_CMD_PHASE_MASK           (0xFF00U)                                           /*!< LPC_USB_CMDCODE.CMD_PHASE Mask          */
#define LPC_USB_CMDCODE_CMD_PHASE_SHIFT          (8U)                                                /*!< LPC_USB_CMDCODE.CMD_PHASE Position      */
#define LPC_USB_CMDCODE_CMD_PHASE(x)             (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< LPC_USB_CMDCODE.CMD_PHASE Field         */
#define LPC_USB_CMDCODE_CODE_WDATA_MASK          (0xFF0000U)                                         /*!< LPC_USB_CMDCODE.CODE_WDATA Mask         */
#define LPC_USB_CMDCODE_CODE_WDATA_SHIFT         (16U)                                               /*!< LPC_USB_CMDCODE.CODE_WDATA Position     */
#define LPC_USB_CMDCODE_CODE_WDATA(x)            (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< LPC_USB_CMDCODE.CODE_WDATA Field        */
/* ------- CMDDATA Bit Fields                       ------ */
#define LPC_USB_CMDDATA_CMD_RDATA_MASK           (0xFFU)                                             /*!< LPC_USB_CMDDATA.CMD_RDATA Mask          */
#define LPC_USB_CMDDATA_CMD_RDATA_SHIFT          (0U)                                                /*!< LPC_USB_CMDDATA.CMD_RDATA Position      */
#define LPC_USB_CMDDATA_CMD_RDATA(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_USB_CMDDATA.CMD_RDATA Field         */
/* ------- RXDATA Bit Fields                        ------ */
#define LPC_USB_RXDATA_RX_DATA_MASK              (0xFFFFFFFFU)                                       /*!< LPC_USB_RXDATA.RX_DATA Mask             */
#define LPC_USB_RXDATA_RX_DATA_SHIFT             (0U)                                                /*!< LPC_USB_RXDATA.RX_DATA Position         */
#define LPC_USB_RXDATA_RX_DATA(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_USB_RXDATA.RX_DATA Field            */
/* ------- TXDATA Bit Fields                        ------ */
#define LPC_USB_TXDATA_TX_DATA_MASK              (0xFFFFFFFFU)                                       /*!< LPC_USB_TXDATA.TX_DATA Mask             */
#define LPC_USB_TXDATA_TX_DATA_SHIFT             (0U)                                                /*!< LPC_USB_TXDATA.TX_DATA Position         */
#define LPC_USB_TXDATA_TX_DATA(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LPC_USB_TXDATA.TX_DATA Field            */
/* ------- RXPLEN Bit Fields                        ------ */
#define LPC_USB_RXPLEN_PKT_LNGTH_MASK            (0x3FFU)                                            /*!< LPC_USB_RXPLEN.PKT_LNGTH Mask           */
#define LPC_USB_RXPLEN_PKT_LNGTH_SHIFT           (0U)                                                /*!< LPC_USB_RXPLEN.PKT_LNGTH Position       */
#define LPC_USB_RXPLEN_PKT_LNGTH(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< LPC_USB_RXPLEN.PKT_LNGTH Field          */
#define LPC_USB_RXPLEN_DV_MASK                   (0x400U)                                            /*!< LPC_USB_RXPLEN.DV Mask                  */
#define LPC_USB_RXPLEN_DV_SHIFT                  (10U)                                               /*!< LPC_USB_RXPLEN.DV Position              */
#define LPC_USB_RXPLEN_DV(x)                     (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< LPC_USB_RXPLEN.DV Field                 */
/* ------- TXPLENn Bit Fields                       ------ */
#define LPC_USB_TXPLENn_PKT_LNGTH_MASK           (0x3FFU)                                            /*!< LPC_USB_TXPLENn.PKT_LNGTH Mask          */
#define LPC_USB_TXPLENn_PKT_LNGTH_SHIFT          (0U)                                                /*!< LPC_USB_TXPLENn.PKT_LNGTH Position      */
#define LPC_USB_TXPLENn_PKT_LNGTH(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< LPC_USB_TXPLENn.PKT_LNGTH Field         */
/* ------- CTRL Bit Fields                          ------ */
#define LPC_USB_CTRL_RD_EN_MASK                  (0x1U)                                              /*!< LPC_USB_CTRL.RD_EN Mask                 */
#define LPC_USB_CTRL_RD_EN_SHIFT                 (0U)                                                /*!< LPC_USB_CTRL.RD_EN Position             */
#define LPC_USB_CTRL_RD_EN(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_USB_CTRL.RD_EN Field                */
#define LPC_USB_CTRL_WR_EN_MASK                  (0x2U)                                              /*!< LPC_USB_CTRL.WR_EN Mask                 */
#define LPC_USB_CTRL_WR_EN_SHIFT                 (1U)                                                /*!< LPC_USB_CTRL.WR_EN Position             */
#define LPC_USB_CTRL_WR_EN(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_USB_CTRL.WR_EN Field                */
#define LPC_USB_CTRL_LOG_ENDPOINT_MASK           (0x3CU)                                             /*!< LPC_USB_CTRL.LOG_ENDPOINT Mask          */
#define LPC_USB_CTRL_LOG_ENDPOINT_SHIFT          (2U)                                                /*!< LPC_USB_CTRL.LOG_ENDPOINT Position      */
#define LPC_USB_CTRL_LOG_ENDPOINT(x)             (((uint32_t)(((uint32_t)(x))<<2U))&0x3CUL)          /*!< LPC_USB_CTRL.LOG_ENDPOINT Field         */
/* ------- DEVFIQSEL Bit Fields                     ------ */
#define LPC_USB_DEVFIQSEL_FRAME_MASK             (0x1U)                                              /*!< LPC_USB_DEVFIQSEL.FRAME Mask            */
#define LPC_USB_DEVFIQSEL_FRAME_SHIFT            (0U)                                                /*!< LPC_USB_DEVFIQSEL.FRAME Position        */
#define LPC_USB_DEVFIQSEL_FRAME(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_USB_DEVFIQSEL.FRAME Field           */
#define LPC_USB_DEVFIQSEL_BULKOUT_MASK           (0x2U)                                              /*!< LPC_USB_DEVFIQSEL.BULKOUT Mask          */
#define LPC_USB_DEVFIQSEL_BULKOUT_SHIFT          (1U)                                                /*!< LPC_USB_DEVFIQSEL.BULKOUT Position      */
#define LPC_USB_DEVFIQSEL_BULKOUT(x)             (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_USB_DEVFIQSEL.BULKOUT Field         */
#define LPC_USB_DEVFIQSEL_BULKIN_MASK            (0x4U)                                              /*!< LPC_USB_DEVFIQSEL.BULKIN Mask           */
#define LPC_USB_DEVFIQSEL_BULKIN_SHIFT           (2U)                                                /*!< LPC_USB_DEVFIQSEL.BULKIN Position       */
#define LPC_USB_DEVFIQSEL_BULKIN(x)              (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_USB_DEVFIQSEL.BULKIN Field          */
/**
 * @} */ /* End group USB_Register_Masks_GROUP 
 */

/* LPC_USB - Peripheral instance base addresses */
#define LPC_USB_BasePtr                0x40020000UL //!< Peripheral base address
#define LPC_USB                        ((LPC_USB_Type *) LPC_USB_BasePtr) //!< Freescale base pointer
#define LPC_USB_BASE_PTR               (LPC_USB) //!< Freescale style base pointer
#define LPC_USB_IRQS { USBIRQ_IRQn, USBFIQ_IRQn,  }

/**
 * @} */ /* End group USB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WWDT_Peripheral_access_layer_GROUP WWDT Peripheral Access Layer
* @brief C Struct for WWDT
* @{
*/

/* ================================================================================ */
/* ================           LPC_WWDT (file:WWDT_LPC13xx)         ================ */
/* ================================================================================ */

/**
 * @brief Windowed WatchDog Timer
 */
/**
* @addtogroup WWDT_structs_GROUP WWDT struct
* @brief Struct for WWDT
* @{
*/
typedef struct LPC_WWDT_Type {
   __IO uint32_t  MOD;                          /**< 0000: Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer */
   __IO uint32_t  TC;                           /**< 0004: Watchdog timer constant register. This register determines the time-out value */
   __O  uint32_t  FEED;                         /**< 0008: Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC */
   __I  uint32_t  TV;                           /**< 000C: Watchdog timer value register. This register reads out the current value of the Watchdog timer */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  WARNINT;                      /**< 0014: Watchdog Warning Interrupt compare value                     */
   __IO uint32_t  WINDOW;                       /**< 0018: Watchdog Window compare value                                */
} LPC_WWDT_Type;

/**
 * @} */ /* End group WWDT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_WWDT' Position & Mask macros                    ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup WWDT_Register_Masks_GROUP WWDT Register Masks
* @brief Register Masks for WWDT
* @{
*/
/* ------- MOD Bit Fields                           ------ */
#define LPC_WWDT_MOD_WDEN_MASK                   (0x1U)                                              /*!< LPC_WWDT_MOD.WDEN Mask                  */
#define LPC_WWDT_MOD_WDEN_SHIFT                  (0U)                                                /*!< LPC_WWDT_MOD.WDEN Position              */
#define LPC_WWDT_MOD_WDEN(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPC_WWDT_MOD.WDEN Field                 */
#define LPC_WWDT_MOD_WDRESET_MASK                (0x2U)                                              /*!< LPC_WWDT_MOD.WDRESET Mask               */
#define LPC_WWDT_MOD_WDRESET_SHIFT               (1U)                                                /*!< LPC_WWDT_MOD.WDRESET Position           */
#define LPC_WWDT_MOD_WDRESET(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPC_WWDT_MOD.WDRESET Field              */
#define LPC_WWDT_MOD_WDTOF_MASK                  (0x4U)                                              /*!< LPC_WWDT_MOD.WDTOF Mask                 */
#define LPC_WWDT_MOD_WDTOF_SHIFT                 (2U)                                                /*!< LPC_WWDT_MOD.WDTOF Position             */
#define LPC_WWDT_MOD_WDTOF(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPC_WWDT_MOD.WDTOF Field                */
#define LPC_WWDT_MOD_WDINT_MASK                  (0x8U)                                              /*!< LPC_WWDT_MOD.WDINT Mask                 */
#define LPC_WWDT_MOD_WDINT_SHIFT                 (3U)                                                /*!< LPC_WWDT_MOD.WDINT Position             */
#define LPC_WWDT_MOD_WDINT(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPC_WWDT_MOD.WDINT Field                */
#define LPC_WWDT_MOD_WDPROTECT_MASK              (0x10U)                                             /*!< LPC_WWDT_MOD.WDPROTECT Mask             */
#define LPC_WWDT_MOD_WDPROTECT_SHIFT             (4U)                                                /*!< LPC_WWDT_MOD.WDPROTECT Position         */
#define LPC_WWDT_MOD_WDPROTECT(x)                (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPC_WWDT_MOD.WDPROTECT Field            */
/* ------- TC Bit Fields                            ------ */
#define LPC_WWDT_TC_Count_MASK                   (0xFFFFFFU)                                         /*!< LPC_WWDT_TC.Count Mask                  */
#define LPC_WWDT_TC_Count_SHIFT                  (0U)                                                /*!< LPC_WWDT_TC.Count Position              */
#define LPC_WWDT_TC_Count(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< LPC_WWDT_TC.Count Field                 */
/* ------- FEED Bit Fields                          ------ */
#define LPC_WWDT_FEED_Feed_MASK                  (0xFFU)                                             /*!< LPC_WWDT_FEED.Feed Mask                 */
#define LPC_WWDT_FEED_Feed_SHIFT                 (0U)                                                /*!< LPC_WWDT_FEED.Feed Position             */
#define LPC_WWDT_FEED_Feed(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPC_WWDT_FEED.Feed Field                */
/* ------- TV Bit Fields                            ------ */
#define LPC_WWDT_TV_Count_MASK                   (0xFFFFFFU)                                         /*!< LPC_WWDT_TV.Count Mask                  */
#define LPC_WWDT_TV_Count_SHIFT                  (0U)                                                /*!< LPC_WWDT_TV.Count Position              */
#define LPC_WWDT_TV_Count(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< LPC_WWDT_TV.Count Field                 */
/* ------- WARNINT Bit Fields                       ------ */
#define LPC_WWDT_WARNINT_WARNINT_MASK            (0x3FFU)                                            /*!< LPC_WWDT_WARNINT.WARNINT Mask           */
#define LPC_WWDT_WARNINT_WARNINT_SHIFT           (0U)                                                /*!< LPC_WWDT_WARNINT.WARNINT Position       */
#define LPC_WWDT_WARNINT_WARNINT(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< LPC_WWDT_WARNINT.WARNINT Field          */
/* ------- WINDOW Bit Fields                        ------ */
#define LPC_WWDT_WINDOW_WINDOW_MASK              (0xFFFFFFU)                                         /*!< LPC_WWDT_WINDOW.WINDOW Mask             */
#define LPC_WWDT_WINDOW_WINDOW_SHIFT             (0U)                                                /*!< LPC_WWDT_WINDOW.WINDOW Position         */
#define LPC_WWDT_WINDOW_WINDOW(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< LPC_WWDT_WINDOW.WINDOW Field            */
/**
 * @} */ /* End group WWDT_Register_Masks_GROUP 
 */

/* LPC_WWDT - Peripheral instance base addresses */
#define LPC_WWDT_BasePtr               0x40004000UL //!< Peripheral base address
#define LPC_WWDT                       ((LPC_WWDT_Type *) LPC_WWDT_BasePtr) //!< Freescale base pointer
#define LPC_WWDT_BASE_PTR              (LPC_WWDT) //!< Freescale style base pointer
#define LPC_WWDT_IRQS { WDT_IRQn,  }

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


#endif  /* MCU_LPC13XX */

