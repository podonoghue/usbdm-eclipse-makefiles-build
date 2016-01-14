/****************************************************************************************************//**
 * @file     $(targetDevice).h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKV43F15.
 *           Equivalent: MKV43F15
 *
 * @version  V1.6
 * @date     2016/01
 *
 *******************************************************************************************************/

#ifndef MCU_MKV43F15
#define MCU_MKV43F15

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
/* ----------------------                                            ---------------------- */
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
extern void MemManage_Handler(void);           /**< Memory Management, MPU mismatch, including Access Violation and No Match         */
extern void BusFault_Handler(void);            /**< Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
extern void UsageFault_Handler(void);          /**< Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
extern void SVC_Handler(void);                 /**< System Service Call via SVC instruction                                          */
extern void DebugMon_Handler(void);            /**< Debug Monitor                                                                    */
extern void PendSV_Handler(void);              /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);             /**< System Tick Timer                                                                */

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
#define __CM4_REV                 0x0001     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          4          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             1          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
#include "core_cm4.h"           /* Processor and core peripherals     */
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
/* ================           ADC                                  ================ */
/* ================================================================================ */

/**
 * @brief Analog to digital converter
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC Structure                                                */
   __IO uint16_t  CTRL1;                        /**< 0000: ADC Control Register 1                                       */
   __IO uint16_t  CTRL2;                        /**< 0002: ADC Control Register 2                                       */
   __IO uint16_t  ZXCTRL1;                      /**< 0004: ADC Zero Crossing Control 1 Register                         */
   __IO uint16_t  ZXCTRL2;                      /**< 0006: ADC Zero Crossing Control 2 Register                         */
   __IO uint16_t  CLIST1;                       /**< 0008: ADC Channel List Register 1                                  */
   __IO uint16_t  CLIST2;                       /**< 000A: ADC Channel List Register 2                                  */
   __IO uint16_t  CLIST3;                       /**< 000C: ADC Channel List Register 3                                  */
   __IO uint16_t  CLIST4;                       /**< 000E: ADC Channel List Register 4                                  */
   __IO uint16_t  SDIS;                         /**< 0010: ADC Sample Disable Register                                  */
   __IO uint16_t  STAT;                         /**< 0012: ADC Status Register                                          */
   __I  uint16_t  RDY;                          /**< 0014: ADC Ready Register                                           */
   __IO uint16_t  LOLIMSTAT;                    /**< 0016: ADC Low Limit Status Register                                */
   __IO uint16_t  HILIMSTAT;                    /**< 0018: ADC High Limit Status Register                               */
   __IO uint16_t  ZXSTAT;                       /**< 001A: ADC Zero Crossing Status Register                            */
   __IO uint16_t  RSLT[16];                     /**< 001C: ADC Result Registers with sign extension                     */
   __IO uint16_t  LOLIM[16];                    /**< 003C: ADC Low Limit                                                */
   __IO uint16_t  HILIM[16];                    /**< 005C: ADC High Limit                                               */
   __IO uint16_t  OFFST[16];                    /**< 007C: ADC Offset                                                   */
   __IO uint16_t  PWR;                          /**< 009C: ADC Power Control Register                                   */
   __IO uint16_t  CAL;                          /**< 009E: ADC Calibration Register                                     */
   __IO uint16_t  GC1;                          /**< 00A0: Gain Control 1 Register                                      */
   __IO uint16_t  GC2;                          /**< 00A2: Gain Control 2 Register                                      */
   __IO uint16_t  SCTRL;                        /**< 00A4: ADC Scan Control Register                                    */
   __IO uint16_t  PWR2;                         /**< 00A6: ADC Power Control Register                                   */
   __IO uint16_t  CTRL3;                        /**< 00A8: ADC Control Register 3                                       */
   __IO uint16_t  SCHLTEN;                      /**< 00AA: ADC Scan Interrupt Enable Register                           */
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
/* ------- CTRL1 Bit Fields                         ------ */
#define ADC_CTRL1_SMODE_MASK                     (0x07UL << ADC_CTRL1_SMODE_SHIFT)                   /*!< ADC_CTRL1: SMODE Mask                   */
#define ADC_CTRL1_SMODE_SHIFT                    0                                                   /*!< ADC_CTRL1: SMODE Position               */
#define ADC_CTRL1_SMODE(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_SMODE_SHIFT))&ADC_CTRL1_SMODE_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_CHNCFG_L_MASK                  (0x0FUL << ADC_CTRL1_CHNCFG_L_SHIFT)                /*!< ADC_CTRL1: CHNCFG_L Mask                */
#define ADC_CTRL1_CHNCFG_L_SHIFT                 4                                                   /*!< ADC_CTRL1: CHNCFG_L Position            */
#define ADC_CTRL1_CHNCFG_L(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CTRL1_CHNCFG_L_SHIFT))&ADC_CTRL1_CHNCFG_L_MASK) /*!< ADC_CTRL1                               */
#define ADC_CTRL1_HLMTIE_MASK                    (0x01UL << ADC_CTRL1_HLMTIE_SHIFT)                  /*!< ADC_CTRL1: HLMTIE Mask                  */
#define ADC_CTRL1_HLMTIE_SHIFT                   8                                                   /*!< ADC_CTRL1: HLMTIE Position              */
#define ADC_CTRL1_LLMTIE_MASK                    (0x01UL << ADC_CTRL1_LLMTIE_SHIFT)                  /*!< ADC_CTRL1: LLMTIE Mask                  */
#define ADC_CTRL1_LLMTIE_SHIFT                   9                                                   /*!< ADC_CTRL1: LLMTIE Position              */
#define ADC_CTRL1_ZCIE_MASK                      (0x01UL << ADC_CTRL1_ZCIE_SHIFT)                    /*!< ADC_CTRL1: ZCIE Mask                    */
#define ADC_CTRL1_ZCIE_SHIFT                     10                                                  /*!< ADC_CTRL1: ZCIE Position                */
#define ADC_CTRL1_EOSIE0_MASK                    (0x01UL << ADC_CTRL1_EOSIE0_SHIFT)                  /*!< ADC_CTRL1: EOSIE0 Mask                  */
#define ADC_CTRL1_EOSIE0_SHIFT                   11                                                  /*!< ADC_CTRL1: EOSIE0 Position              */
#define ADC_CTRL1_SYNC0_MASK                     (0x01UL << ADC_CTRL1_SYNC0_SHIFT)                   /*!< ADC_CTRL1: SYNC0 Mask                   */
#define ADC_CTRL1_SYNC0_SHIFT                    12                                                  /*!< ADC_CTRL1: SYNC0 Position               */
#define ADC_CTRL1_START0_MASK                    (0x01UL << ADC_CTRL1_START0_SHIFT)                  /*!< ADC_CTRL1: START0 Mask                  */
#define ADC_CTRL1_START0_SHIFT                   13                                                  /*!< ADC_CTRL1: START0 Position              */
#define ADC_CTRL1_STOP0_MASK                     (0x01UL << ADC_CTRL1_STOP0_SHIFT)                   /*!< ADC_CTRL1: STOP0 Mask                   */
#define ADC_CTRL1_STOP0_SHIFT                    14                                                  /*!< ADC_CTRL1: STOP0 Position               */
#define ADC_CTRL1_DMAEN0_MASK                    (0x01UL << ADC_CTRL1_DMAEN0_SHIFT)                  /*!< ADC_CTRL1: DMAEN0 Mask                  */
#define ADC_CTRL1_DMAEN0_SHIFT                   15                                                  /*!< ADC_CTRL1: DMAEN0 Position              */
/* ------- CTRL2 Bit Fields                         ------ */
#define ADC_CTRL2_DIV0_MASK                      (0x3FUL << ADC_CTRL2_DIV0_SHIFT)                    /*!< ADC_CTRL2: DIV0 Mask                    */
#define ADC_CTRL2_DIV0_SHIFT                     0                                                   /*!< ADC_CTRL2: DIV0 Position                */
#define ADC_CTRL2_DIV0(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_DIV0_SHIFT))&ADC_CTRL2_DIV0_MASK) /*!< ADC_CTRL2                               */
#define ADC_CTRL2_SIMULT_MASK                    (0x01UL << ADC_CTRL2_SIMULT_SHIFT)                  /*!< ADC_CTRL2: SIMULT Mask                  */
#define ADC_CTRL2_SIMULT_SHIFT                   6                                                   /*!< ADC_CTRL2: SIMULT Position              */
#define ADC_CTRL2_CHNCFG_H_MASK                  (0x0FUL << ADC_CTRL2_CHNCFG_H_SHIFT)                /*!< ADC_CTRL2: CHNCFG_H Mask                */
#define ADC_CTRL2_CHNCFG_H_SHIFT                 7                                                   /*!< ADC_CTRL2: CHNCFG_H Position            */
#define ADC_CTRL2_CHNCFG_H(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CTRL2_CHNCFG_H_SHIFT))&ADC_CTRL2_CHNCFG_H_MASK) /*!< ADC_CTRL2                               */
#define ADC_CTRL2_EOSIE1_MASK                    (0x01UL << ADC_CTRL2_EOSIE1_SHIFT)                  /*!< ADC_CTRL2: EOSIE1 Mask                  */
#define ADC_CTRL2_EOSIE1_SHIFT                   11                                                  /*!< ADC_CTRL2: EOSIE1 Position              */
#define ADC_CTRL2_SYNC1_MASK                     (0x01UL << ADC_CTRL2_SYNC1_SHIFT)                   /*!< ADC_CTRL2: SYNC1 Mask                   */
#define ADC_CTRL2_SYNC1_SHIFT                    12                                                  /*!< ADC_CTRL2: SYNC1 Position               */
#define ADC_CTRL2_START1_MASK                    (0x01UL << ADC_CTRL2_START1_SHIFT)                  /*!< ADC_CTRL2: START1 Mask                  */
#define ADC_CTRL2_START1_SHIFT                   13                                                  /*!< ADC_CTRL2: START1 Position              */
#define ADC_CTRL2_STOP1_MASK                     (0x01UL << ADC_CTRL2_STOP1_SHIFT)                   /*!< ADC_CTRL2: STOP1 Mask                   */
#define ADC_CTRL2_STOP1_SHIFT                    14                                                  /*!< ADC_CTRL2: STOP1 Position               */
#define ADC_CTRL2_DMAEN1_MASK                    (0x01UL << ADC_CTRL2_DMAEN1_SHIFT)                  /*!< ADC_CTRL2: DMAEN1 Mask                  */
#define ADC_CTRL2_DMAEN1_SHIFT                   15                                                  /*!< ADC_CTRL2: DMAEN1 Position              */
/* ------- ZXCTRL1 Bit Fields                       ------ */
#define ADC_ZXCTRL1_ZCE0_MASK                    (0x03UL << ADC_ZXCTRL1_ZCE0_SHIFT)                  /*!< ADC_ZXCTRL1: ZCE0 Mask                  */
#define ADC_ZXCTRL1_ZCE0_SHIFT                   0                                                   /*!< ADC_ZXCTRL1: ZCE0 Position              */
#define ADC_ZXCTRL1_ZCE0(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE0_SHIFT))&ADC_ZXCTRL1_ZCE0_MASK) /*!< ADC_ZXCTRL1                             */
#define ADC_ZXCTRL1_ZCE1_MASK                    (0x03UL << ADC_ZXCTRL1_ZCE1_SHIFT)                  /*!< ADC_ZXCTRL1: ZCE1 Mask                  */
#define ADC_ZXCTRL1_ZCE1_SHIFT                   2                                                   /*!< ADC_ZXCTRL1: ZCE1 Position              */
#define ADC_ZXCTRL1_ZCE1(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE1_SHIFT))&ADC_ZXCTRL1_ZCE1_MASK) /*!< ADC_ZXCTRL1                             */
#define ADC_ZXCTRL1_ZCE2_MASK                    (0x03UL << ADC_ZXCTRL1_ZCE2_SHIFT)                  /*!< ADC_ZXCTRL1: ZCE2 Mask                  */
#define ADC_ZXCTRL1_ZCE2_SHIFT                   4                                                   /*!< ADC_ZXCTRL1: ZCE2 Position              */
#define ADC_ZXCTRL1_ZCE2(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE2_SHIFT))&ADC_ZXCTRL1_ZCE2_MASK) /*!< ADC_ZXCTRL1                             */
#define ADC_ZXCTRL1_ZCE3_MASK                    (0x03UL << ADC_ZXCTRL1_ZCE3_SHIFT)                  /*!< ADC_ZXCTRL1: ZCE3 Mask                  */
#define ADC_ZXCTRL1_ZCE3_SHIFT                   6                                                   /*!< ADC_ZXCTRL1: ZCE3 Position              */
#define ADC_ZXCTRL1_ZCE3(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE3_SHIFT))&ADC_ZXCTRL1_ZCE3_MASK) /*!< ADC_ZXCTRL1                             */
#define ADC_ZXCTRL1_ZCE4_MASK                    (0x03UL << ADC_ZXCTRL1_ZCE4_SHIFT)                  /*!< ADC_ZXCTRL1: ZCE4 Mask                  */
#define ADC_ZXCTRL1_ZCE4_SHIFT                   8                                                   /*!< ADC_ZXCTRL1: ZCE4 Position              */
#define ADC_ZXCTRL1_ZCE4(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE4_SHIFT))&ADC_ZXCTRL1_ZCE4_MASK) /*!< ADC_ZXCTRL1                             */
#define ADC_ZXCTRL1_ZCE5_MASK                    (0x03UL << ADC_ZXCTRL1_ZCE5_SHIFT)                  /*!< ADC_ZXCTRL1: ZCE5 Mask                  */
#define ADC_ZXCTRL1_ZCE5_SHIFT                   10                                                  /*!< ADC_ZXCTRL1: ZCE5 Position              */
#define ADC_ZXCTRL1_ZCE5(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE5_SHIFT))&ADC_ZXCTRL1_ZCE5_MASK) /*!< ADC_ZXCTRL1                             */
#define ADC_ZXCTRL1_ZCE6_MASK                    (0x03UL << ADC_ZXCTRL1_ZCE6_SHIFT)                  /*!< ADC_ZXCTRL1: ZCE6 Mask                  */
#define ADC_ZXCTRL1_ZCE6_SHIFT                   12                                                  /*!< ADC_ZXCTRL1: ZCE6 Position              */
#define ADC_ZXCTRL1_ZCE6(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE6_SHIFT))&ADC_ZXCTRL1_ZCE6_MASK) /*!< ADC_ZXCTRL1                             */
#define ADC_ZXCTRL1_ZCE7_MASK                    (0x03UL << ADC_ZXCTRL1_ZCE7_SHIFT)                  /*!< ADC_ZXCTRL1: ZCE7 Mask                  */
#define ADC_ZXCTRL1_ZCE7_SHIFT                   14                                                  /*!< ADC_ZXCTRL1: ZCE7 Position              */
#define ADC_ZXCTRL1_ZCE7(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL1_ZCE7_SHIFT))&ADC_ZXCTRL1_ZCE7_MASK) /*!< ADC_ZXCTRL1                             */
/* ------- ZXCTRL2 Bit Fields                       ------ */
#define ADC_ZXCTRL2_ZCE8_MASK                    (0x03UL << ADC_ZXCTRL2_ZCE8_SHIFT)                  /*!< ADC_ZXCTRL2: ZCE8 Mask                  */
#define ADC_ZXCTRL2_ZCE8_SHIFT                   0                                                   /*!< ADC_ZXCTRL2: ZCE8 Position              */
#define ADC_ZXCTRL2_ZCE8(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE8_SHIFT))&ADC_ZXCTRL2_ZCE8_MASK) /*!< ADC_ZXCTRL2                             */
#define ADC_ZXCTRL2_ZCE9_MASK                    (0x03UL << ADC_ZXCTRL2_ZCE9_SHIFT)                  /*!< ADC_ZXCTRL2: ZCE9 Mask                  */
#define ADC_ZXCTRL2_ZCE9_SHIFT                   2                                                   /*!< ADC_ZXCTRL2: ZCE9 Position              */
#define ADC_ZXCTRL2_ZCE9(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE9_SHIFT))&ADC_ZXCTRL2_ZCE9_MASK) /*!< ADC_ZXCTRL2                             */
#define ADC_ZXCTRL2_ZCE10_MASK                   (0x03UL << ADC_ZXCTRL2_ZCE10_SHIFT)                 /*!< ADC_ZXCTRL2: ZCE10 Mask                 */
#define ADC_ZXCTRL2_ZCE10_SHIFT                  4                                                   /*!< ADC_ZXCTRL2: ZCE10 Position             */
#define ADC_ZXCTRL2_ZCE10(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE10_SHIFT))&ADC_ZXCTRL2_ZCE10_MASK) /*!< ADC_ZXCTRL2                             */
#define ADC_ZXCTRL2_ZCE11_MASK                   (0x03UL << ADC_ZXCTRL2_ZCE11_SHIFT)                 /*!< ADC_ZXCTRL2: ZCE11 Mask                 */
#define ADC_ZXCTRL2_ZCE11_SHIFT                  6                                                   /*!< ADC_ZXCTRL2: ZCE11 Position             */
#define ADC_ZXCTRL2_ZCE11(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE11_SHIFT))&ADC_ZXCTRL2_ZCE11_MASK) /*!< ADC_ZXCTRL2                             */
#define ADC_ZXCTRL2_ZCE12_MASK                   (0x03UL << ADC_ZXCTRL2_ZCE12_SHIFT)                 /*!< ADC_ZXCTRL2: ZCE12 Mask                 */
#define ADC_ZXCTRL2_ZCE12_SHIFT                  8                                                   /*!< ADC_ZXCTRL2: ZCE12 Position             */
#define ADC_ZXCTRL2_ZCE12(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE12_SHIFT))&ADC_ZXCTRL2_ZCE12_MASK) /*!< ADC_ZXCTRL2                             */
#define ADC_ZXCTRL2_ZCE13_MASK                   (0x03UL << ADC_ZXCTRL2_ZCE13_SHIFT)                 /*!< ADC_ZXCTRL2: ZCE13 Mask                 */
#define ADC_ZXCTRL2_ZCE13_SHIFT                  10                                                  /*!< ADC_ZXCTRL2: ZCE13 Position             */
#define ADC_ZXCTRL2_ZCE13(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE13_SHIFT))&ADC_ZXCTRL2_ZCE13_MASK) /*!< ADC_ZXCTRL2                             */
#define ADC_ZXCTRL2_ZCE14_MASK                   (0x03UL << ADC_ZXCTRL2_ZCE14_SHIFT)                 /*!< ADC_ZXCTRL2: ZCE14 Mask                 */
#define ADC_ZXCTRL2_ZCE14_SHIFT                  12                                                  /*!< ADC_ZXCTRL2: ZCE14 Position             */
#define ADC_ZXCTRL2_ZCE14(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE14_SHIFT))&ADC_ZXCTRL2_ZCE14_MASK) /*!< ADC_ZXCTRL2                             */
#define ADC_ZXCTRL2_ZCE15_MASK                   (0x03UL << ADC_ZXCTRL2_ZCE15_SHIFT)                 /*!< ADC_ZXCTRL2: ZCE15 Mask                 */
#define ADC_ZXCTRL2_ZCE15_SHIFT                  14                                                  /*!< ADC_ZXCTRL2: ZCE15 Position             */
#define ADC_ZXCTRL2_ZCE15(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_ZXCTRL2_ZCE15_SHIFT))&ADC_ZXCTRL2_ZCE15_MASK) /*!< ADC_ZXCTRL2                             */
/* ------- CLIST1 Bit Fields                        ------ */
#define ADC_CLIST1_SAMPLE0_MASK                  (0x0FUL << ADC_CLIST1_SAMPLE0_SHIFT)                /*!< ADC_CLIST1: SAMPLE0 Mask                */
#define ADC_CLIST1_SAMPLE0_SHIFT                 0                                                   /*!< ADC_CLIST1: SAMPLE0 Position            */
#define ADC_CLIST1_SAMPLE0(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST1_SAMPLE0_SHIFT))&ADC_CLIST1_SAMPLE0_MASK) /*!< ADC_CLIST1                              */
#define ADC_CLIST1_SAMPLE1_MASK                  (0x0FUL << ADC_CLIST1_SAMPLE1_SHIFT)                /*!< ADC_CLIST1: SAMPLE1 Mask                */
#define ADC_CLIST1_SAMPLE1_SHIFT                 4                                                   /*!< ADC_CLIST1: SAMPLE1 Position            */
#define ADC_CLIST1_SAMPLE1(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST1_SAMPLE1_SHIFT))&ADC_CLIST1_SAMPLE1_MASK) /*!< ADC_CLIST1                              */
#define ADC_CLIST1_SAMPLE2_MASK                  (0x0FUL << ADC_CLIST1_SAMPLE2_SHIFT)                /*!< ADC_CLIST1: SAMPLE2 Mask                */
#define ADC_CLIST1_SAMPLE2_SHIFT                 8                                                   /*!< ADC_CLIST1: SAMPLE2 Position            */
#define ADC_CLIST1_SAMPLE2(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST1_SAMPLE2_SHIFT))&ADC_CLIST1_SAMPLE2_MASK) /*!< ADC_CLIST1                              */
#define ADC_CLIST1_SAMPLE3_MASK                  (0x0FUL << ADC_CLIST1_SAMPLE3_SHIFT)                /*!< ADC_CLIST1: SAMPLE3 Mask                */
#define ADC_CLIST1_SAMPLE3_SHIFT                 12                                                  /*!< ADC_CLIST1: SAMPLE3 Position            */
#define ADC_CLIST1_SAMPLE3(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST1_SAMPLE3_SHIFT))&ADC_CLIST1_SAMPLE3_MASK) /*!< ADC_CLIST1                              */
/* ------- CLIST2 Bit Fields                        ------ */
#define ADC_CLIST2_SAMPLE4_MASK                  (0x0FUL << ADC_CLIST2_SAMPLE4_SHIFT)                /*!< ADC_CLIST2: SAMPLE4 Mask                */
#define ADC_CLIST2_SAMPLE4_SHIFT                 0                                                   /*!< ADC_CLIST2: SAMPLE4 Position            */
#define ADC_CLIST2_SAMPLE4(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST2_SAMPLE4_SHIFT))&ADC_CLIST2_SAMPLE4_MASK) /*!< ADC_CLIST2                              */
#define ADC_CLIST2_SAMPLE5_MASK                  (0x0FUL << ADC_CLIST2_SAMPLE5_SHIFT)                /*!< ADC_CLIST2: SAMPLE5 Mask                */
#define ADC_CLIST2_SAMPLE5_SHIFT                 4                                                   /*!< ADC_CLIST2: SAMPLE5 Position            */
#define ADC_CLIST2_SAMPLE5(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST2_SAMPLE5_SHIFT))&ADC_CLIST2_SAMPLE5_MASK) /*!< ADC_CLIST2                              */
#define ADC_CLIST2_SAMPLE6_MASK                  (0x0FUL << ADC_CLIST2_SAMPLE6_SHIFT)                /*!< ADC_CLIST2: SAMPLE6 Mask                */
#define ADC_CLIST2_SAMPLE6_SHIFT                 8                                                   /*!< ADC_CLIST2: SAMPLE6 Position            */
#define ADC_CLIST2_SAMPLE6(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST2_SAMPLE6_SHIFT))&ADC_CLIST2_SAMPLE6_MASK) /*!< ADC_CLIST2                              */
#define ADC_CLIST2_SAMPLE7_MASK                  (0x0FUL << ADC_CLIST2_SAMPLE7_SHIFT)                /*!< ADC_CLIST2: SAMPLE7 Mask                */
#define ADC_CLIST2_SAMPLE7_SHIFT                 12                                                  /*!< ADC_CLIST2: SAMPLE7 Position            */
#define ADC_CLIST2_SAMPLE7(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST2_SAMPLE7_SHIFT))&ADC_CLIST2_SAMPLE7_MASK) /*!< ADC_CLIST2                              */
/* ------- CLIST3 Bit Fields                        ------ */
#define ADC_CLIST3_SAMPLE8_MASK                  (0x0FUL << ADC_CLIST3_SAMPLE8_SHIFT)                /*!< ADC_CLIST3: SAMPLE8 Mask                */
#define ADC_CLIST3_SAMPLE8_SHIFT                 0                                                   /*!< ADC_CLIST3: SAMPLE8 Position            */
#define ADC_CLIST3_SAMPLE8(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST3_SAMPLE8_SHIFT))&ADC_CLIST3_SAMPLE8_MASK) /*!< ADC_CLIST3                              */
#define ADC_CLIST3_SAMPLE9_MASK                  (0x0FUL << ADC_CLIST3_SAMPLE9_SHIFT)                /*!< ADC_CLIST3: SAMPLE9 Mask                */
#define ADC_CLIST3_SAMPLE9_SHIFT                 4                                                   /*!< ADC_CLIST3: SAMPLE9 Position            */
#define ADC_CLIST3_SAMPLE9(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_CLIST3_SAMPLE9_SHIFT))&ADC_CLIST3_SAMPLE9_MASK) /*!< ADC_CLIST3                              */
#define ADC_CLIST3_SAMPLE10_MASK                 (0x0FUL << ADC_CLIST3_SAMPLE10_SHIFT)               /*!< ADC_CLIST3: SAMPLE10 Mask               */
#define ADC_CLIST3_SAMPLE10_SHIFT                8                                                   /*!< ADC_CLIST3: SAMPLE10 Position           */
#define ADC_CLIST3_SAMPLE10(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST3_SAMPLE10_SHIFT))&ADC_CLIST3_SAMPLE10_MASK) /*!< ADC_CLIST3                              */
#define ADC_CLIST3_SAMPLE11_MASK                 (0x0FUL << ADC_CLIST3_SAMPLE11_SHIFT)               /*!< ADC_CLIST3: SAMPLE11 Mask               */
#define ADC_CLIST3_SAMPLE11_SHIFT                12                                                  /*!< ADC_CLIST3: SAMPLE11 Position           */
#define ADC_CLIST3_SAMPLE11(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST3_SAMPLE11_SHIFT))&ADC_CLIST3_SAMPLE11_MASK) /*!< ADC_CLIST3                              */
/* ------- CLIST4 Bit Fields                        ------ */
#define ADC_CLIST4_SAMPLE12_MASK                 (0x0FUL << ADC_CLIST4_SAMPLE12_SHIFT)               /*!< ADC_CLIST4: SAMPLE12 Mask               */
#define ADC_CLIST4_SAMPLE12_SHIFT                0                                                   /*!< ADC_CLIST4: SAMPLE12 Position           */
#define ADC_CLIST4_SAMPLE12(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST4_SAMPLE12_SHIFT))&ADC_CLIST4_SAMPLE12_MASK) /*!< ADC_CLIST4                              */
#define ADC_CLIST4_SAMPLE13_MASK                 (0x0FUL << ADC_CLIST4_SAMPLE13_SHIFT)               /*!< ADC_CLIST4: SAMPLE13 Mask               */
#define ADC_CLIST4_SAMPLE13_SHIFT                4                                                   /*!< ADC_CLIST4: SAMPLE13 Position           */
#define ADC_CLIST4_SAMPLE13(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST4_SAMPLE13_SHIFT))&ADC_CLIST4_SAMPLE13_MASK) /*!< ADC_CLIST4                              */
#define ADC_CLIST4_SAMPLE14_MASK                 (0x0FUL << ADC_CLIST4_SAMPLE14_SHIFT)               /*!< ADC_CLIST4: SAMPLE14 Mask               */
#define ADC_CLIST4_SAMPLE14_SHIFT                8                                                   /*!< ADC_CLIST4: SAMPLE14 Position           */
#define ADC_CLIST4_SAMPLE14(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST4_SAMPLE14_SHIFT))&ADC_CLIST4_SAMPLE14_MASK) /*!< ADC_CLIST4                              */
#define ADC_CLIST4_SAMPLE15_MASK                 (0x0FUL << ADC_CLIST4_SAMPLE15_SHIFT)               /*!< ADC_CLIST4: SAMPLE15 Mask               */
#define ADC_CLIST4_SAMPLE15_SHIFT                12                                                  /*!< ADC_CLIST4: SAMPLE15 Position           */
#define ADC_CLIST4_SAMPLE15(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_CLIST4_SAMPLE15_SHIFT))&ADC_CLIST4_SAMPLE15_MASK) /*!< ADC_CLIST4                              */
/* ------- SDIS Bit Fields                          ------ */
#define ADC_SDIS_DS_MASK                         (0xFFFFUL << ADC_SDIS_DS_SHIFT)                     /*!< ADC_SDIS: DS Mask                       */
#define ADC_SDIS_DS_SHIFT                        0                                                   /*!< ADC_SDIS: DS Position                   */
#define ADC_SDIS_DS(x)                           (((uint16_t)(((uint16_t)(x))<<ADC_SDIS_DS_SHIFT))&ADC_SDIS_DS_MASK) /*!< ADC_SDIS                                */
/* ------- STAT Bit Fields                          ------ */
#define ADC_STAT_UNDEFINED_MASK                  (0xFFUL << ADC_STAT_UNDEFINED_SHIFT)                /*!< ADC_STAT: UNDEFINED Mask                */
#define ADC_STAT_UNDEFINED_SHIFT                 0                                                   /*!< ADC_STAT: UNDEFINED Position            */
#define ADC_STAT_UNDEFINED(x)                    (((uint16_t)(((uint16_t)(x))<<ADC_STAT_UNDEFINED_SHIFT))&ADC_STAT_UNDEFINED_MASK) /*!< ADC_STAT                                */
#define ADC_STAT_HLMTI_MASK                      (0x01UL << ADC_STAT_HLMTI_SHIFT)                    /*!< ADC_STAT: HLMTI Mask                    */
#define ADC_STAT_HLMTI_SHIFT                     8                                                   /*!< ADC_STAT: HLMTI Position                */
#define ADC_STAT_LLMTI_MASK                      (0x01UL << ADC_STAT_LLMTI_SHIFT)                    /*!< ADC_STAT: LLMTI Mask                    */
#define ADC_STAT_LLMTI_SHIFT                     9                                                   /*!< ADC_STAT: LLMTI Position                */
#define ADC_STAT_ZCI_MASK                        (0x01UL << ADC_STAT_ZCI_SHIFT)                      /*!< ADC_STAT: ZCI Mask                      */
#define ADC_STAT_ZCI_SHIFT                       10                                                  /*!< ADC_STAT: ZCI Position                  */
#define ADC_STAT_EOSI0_MASK                      (0x01UL << ADC_STAT_EOSI0_SHIFT)                    /*!< ADC_STAT: EOSI0 Mask                    */
#define ADC_STAT_EOSI0_SHIFT                     11                                                  /*!< ADC_STAT: EOSI0 Position                */
#define ADC_STAT_EOSI1_MASK                      (0x01UL << ADC_STAT_EOSI1_SHIFT)                    /*!< ADC_STAT: EOSI1 Mask                    */
#define ADC_STAT_EOSI1_SHIFT                     12                                                  /*!< ADC_STAT: EOSI1 Position                */
#define ADC_STAT_CIP1_MASK                       (0x01UL << ADC_STAT_CIP1_SHIFT)                     /*!< ADC_STAT: CIP1 Mask                     */
#define ADC_STAT_CIP1_SHIFT                      14                                                  /*!< ADC_STAT: CIP1 Position                 */
#define ADC_STAT_CIP0_MASK                       (0x01UL << ADC_STAT_CIP0_SHIFT)                     /*!< ADC_STAT: CIP0 Mask                     */
#define ADC_STAT_CIP0_SHIFT                      15                                                  /*!< ADC_STAT: CIP0 Position                 */
/* ------- RDY Bit Fields                           ------ */
#define ADC_RDY_RDY_MASK                         (0xFFFFUL << ADC_RDY_RDY_SHIFT)                     /*!< ADC_RDY: RDY Mask                       */
#define ADC_RDY_RDY_SHIFT                        0                                                   /*!< ADC_RDY: RDY Position                   */
#define ADC_RDY_RDY(x)                           (((uint16_t)(((uint16_t)(x))<<ADC_RDY_RDY_SHIFT))&ADC_RDY_RDY_MASK) /*!< ADC_RDY                                 */
/* ------- LOLIMSTAT Bit Fields                     ------ */
#define ADC_LOLIMSTAT_LLS_MASK                   (0xFFFFUL << ADC_LOLIMSTAT_LLS_SHIFT)               /*!< ADC_LOLIMSTAT: LLS Mask                 */
#define ADC_LOLIMSTAT_LLS_SHIFT                  0                                                   /*!< ADC_LOLIMSTAT: LLS Position             */
#define ADC_LOLIMSTAT_LLS(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_LOLIMSTAT_LLS_SHIFT))&ADC_LOLIMSTAT_LLS_MASK) /*!< ADC_LOLIMSTAT                           */
/* ------- HILIMSTAT Bit Fields                     ------ */
#define ADC_HILIMSTAT_HLS_MASK                   (0xFFFFUL << ADC_HILIMSTAT_HLS_SHIFT)               /*!< ADC_HILIMSTAT: HLS Mask                 */
#define ADC_HILIMSTAT_HLS_SHIFT                  0                                                   /*!< ADC_HILIMSTAT: HLS Position             */
#define ADC_HILIMSTAT_HLS(x)                     (((uint16_t)(((uint16_t)(x))<<ADC_HILIMSTAT_HLS_SHIFT))&ADC_HILIMSTAT_HLS_MASK) /*!< ADC_HILIMSTAT                           */
/* ------- ZXSTAT Bit Fields                        ------ */
#define ADC_ZXSTAT_ZCS_MASK                      (0xFFFFUL << ADC_ZXSTAT_ZCS_SHIFT)                  /*!< ADC_ZXSTAT: ZCS Mask                    */
#define ADC_ZXSTAT_ZCS_SHIFT                     0                                                   /*!< ADC_ZXSTAT: ZCS Position                */
#define ADC_ZXSTAT_ZCS(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_ZXSTAT_ZCS_SHIFT))&ADC_ZXSTAT_ZCS_MASK) /*!< ADC_ZXSTAT                              */
/* ------- RSLT Bit Fields                          ------ */
#define ADC_RSLT_RSLT_MASK                       (0xFFFUL << ADC_RSLT_RSLT_SHIFT)                    /*!< ADC_RSLT: RSLT Mask                     */
#define ADC_RSLT_RSLT_SHIFT                      3                                                   /*!< ADC_RSLT: RSLT Position                 */
#define ADC_RSLT_RSLT(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_RSLT_RSLT_SHIFT))&ADC_RSLT_RSLT_MASK) /*!< ADC_RSLT                                */
#define ADC_RSLT_SEXT_MASK                       (0x01UL << ADC_RSLT_SEXT_SHIFT)                     /*!< ADC_RSLT: SEXT Mask                     */
#define ADC_RSLT_SEXT_SHIFT                      15                                                  /*!< ADC_RSLT: SEXT Position                 */
/* ------- LOLIM Bit Fields                         ------ */
#define ADC_LOLIM_LLMT_MASK                      (0xFFFUL << ADC_LOLIM_LLMT_SHIFT)                   /*!< ADC_LOLIM: LLMT Mask                    */
#define ADC_LOLIM_LLMT_SHIFT                     3                                                   /*!< ADC_LOLIM: LLMT Position                */
#define ADC_LOLIM_LLMT(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_LOLIM_LLMT_SHIFT))&ADC_LOLIM_LLMT_MASK) /*!< ADC_LOLIM                               */
/* ------- HILIM Bit Fields                         ------ */
#define ADC_HILIM_HLMT_MASK                      (0xFFFUL << ADC_HILIM_HLMT_SHIFT)                   /*!< ADC_HILIM: HLMT Mask                    */
#define ADC_HILIM_HLMT_SHIFT                     3                                                   /*!< ADC_HILIM: HLMT Position                */
#define ADC_HILIM_HLMT(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_HILIM_HLMT_SHIFT))&ADC_HILIM_HLMT_MASK) /*!< ADC_HILIM                               */
/* ------- OFFST Bit Fields                         ------ */
#define ADC_OFFST_OFFSET_MASK                    (0xFFFUL << ADC_OFFST_OFFSET_SHIFT)                 /*!< ADC_OFFST: OFFSET Mask                  */
#define ADC_OFFST_OFFSET_SHIFT                   3                                                   /*!< ADC_OFFST: OFFSET Position              */
#define ADC_OFFST_OFFSET(x)                      (((uint16_t)(((uint16_t)(x))<<ADC_OFFST_OFFSET_SHIFT))&ADC_OFFST_OFFSET_MASK) /*!< ADC_OFFST                               */
/* ------- PWR Bit Fields                           ------ */
#define ADC_PWR_PD0_MASK                         (0x01UL << ADC_PWR_PD0_SHIFT)                       /*!< ADC_PWR: PD0 Mask                       */
#define ADC_PWR_PD0_SHIFT                        0                                                   /*!< ADC_PWR: PD0 Position                   */
#define ADC_PWR_PD1_MASK                         (0x01UL << ADC_PWR_PD1_SHIFT)                       /*!< ADC_PWR: PD1 Mask                       */
#define ADC_PWR_PD1_SHIFT                        1                                                   /*!< ADC_PWR: PD1 Position                   */
#define ADC_PWR_APD_MASK                         (0x01UL << ADC_PWR_APD_SHIFT)                       /*!< ADC_PWR: APD Mask                       */
#define ADC_PWR_APD_SHIFT                        3                                                   /*!< ADC_PWR: APD Position                   */
#define ADC_PWR_PUDELAY_MASK                     (0x3FUL << ADC_PWR_PUDELAY_SHIFT)                   /*!< ADC_PWR: PUDELAY Mask                   */
#define ADC_PWR_PUDELAY_SHIFT                    4                                                   /*!< ADC_PWR: PUDELAY Position               */
#define ADC_PWR_PUDELAY(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_PWR_PUDELAY_SHIFT))&ADC_PWR_PUDELAY_MASK) /*!< ADC_PWR                                 */
#define ADC_PWR_PSTS0_MASK                       (0x01UL << ADC_PWR_PSTS0_SHIFT)                     /*!< ADC_PWR: PSTS0 Mask                     */
#define ADC_PWR_PSTS0_SHIFT                      10                                                  /*!< ADC_PWR: PSTS0 Position                 */
#define ADC_PWR_PSTS1_MASK                       (0x01UL << ADC_PWR_PSTS1_SHIFT)                     /*!< ADC_PWR: PSTS1 Mask                     */
#define ADC_PWR_PSTS1_SHIFT                      11                                                  /*!< ADC_PWR: PSTS1 Position                 */
#define ADC_PWR_ASB_MASK                         (0x01UL << ADC_PWR_ASB_SHIFT)                       /*!< ADC_PWR: ASB Mask                       */
#define ADC_PWR_ASB_SHIFT                        15                                                  /*!< ADC_PWR: ASB Position                   */
/* ------- CAL Bit Fields                           ------ */
#define ADC_CAL_SEL_VREFLO_A_MASK                (0x01UL << ADC_CAL_SEL_VREFLO_A_SHIFT)              /*!< ADC_CAL: SEL_VREFLO_A Mask              */
#define ADC_CAL_SEL_VREFLO_A_SHIFT               12                                                  /*!< ADC_CAL: SEL_VREFLO_A Position          */
#define ADC_CAL_SEL_VREFH_A_MASK                 (0x01UL << ADC_CAL_SEL_VREFH_A_SHIFT)               /*!< ADC_CAL: SEL_VREFH_A Mask               */
#define ADC_CAL_SEL_VREFH_A_SHIFT                13                                                  /*!< ADC_CAL: SEL_VREFH_A Position           */
#define ADC_CAL_SEL_VREFLO_B_MASK                (0x01UL << ADC_CAL_SEL_VREFLO_B_SHIFT)              /*!< ADC_CAL: SEL_VREFLO_B Mask              */
#define ADC_CAL_SEL_VREFLO_B_SHIFT               14                                                  /*!< ADC_CAL: SEL_VREFLO_B Position          */
#define ADC_CAL_SEL_VREFH_B_MASK                 (0x01UL << ADC_CAL_SEL_VREFH_B_SHIFT)               /*!< ADC_CAL: SEL_VREFH_B Mask               */
#define ADC_CAL_SEL_VREFH_B_SHIFT                15                                                  /*!< ADC_CAL: SEL_VREFH_B Position           */
/* ------- GC1 Bit Fields                           ------ */
#define ADC_GC1_GAIN0_MASK                       (0x03UL << ADC_GC1_GAIN0_SHIFT)                     /*!< ADC_GC1: GAIN0 Mask                     */
#define ADC_GC1_GAIN0_SHIFT                      0                                                   /*!< ADC_GC1: GAIN0 Position                 */
#define ADC_GC1_GAIN0(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN0_SHIFT))&ADC_GC1_GAIN0_MASK) /*!< ADC_GC1                                 */
#define ADC_GC1_GAIN1_MASK                       (0x03UL << ADC_GC1_GAIN1_SHIFT)                     /*!< ADC_GC1: GAIN1 Mask                     */
#define ADC_GC1_GAIN1_SHIFT                      2                                                   /*!< ADC_GC1: GAIN1 Position                 */
#define ADC_GC1_GAIN1(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN1_SHIFT))&ADC_GC1_GAIN1_MASK) /*!< ADC_GC1                                 */
#define ADC_GC1_GAIN2_MASK                       (0x03UL << ADC_GC1_GAIN2_SHIFT)                     /*!< ADC_GC1: GAIN2 Mask                     */
#define ADC_GC1_GAIN2_SHIFT                      4                                                   /*!< ADC_GC1: GAIN2 Position                 */
#define ADC_GC1_GAIN2(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN2_SHIFT))&ADC_GC1_GAIN2_MASK) /*!< ADC_GC1                                 */
#define ADC_GC1_GAIN3_MASK                       (0x03UL << ADC_GC1_GAIN3_SHIFT)                     /*!< ADC_GC1: GAIN3 Mask                     */
#define ADC_GC1_GAIN3_SHIFT                      6                                                   /*!< ADC_GC1: GAIN3 Position                 */
#define ADC_GC1_GAIN3(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN3_SHIFT))&ADC_GC1_GAIN3_MASK) /*!< ADC_GC1                                 */
#define ADC_GC1_GAIN4_MASK                       (0x03UL << ADC_GC1_GAIN4_SHIFT)                     /*!< ADC_GC1: GAIN4 Mask                     */
#define ADC_GC1_GAIN4_SHIFT                      8                                                   /*!< ADC_GC1: GAIN4 Position                 */
#define ADC_GC1_GAIN4(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN4_SHIFT))&ADC_GC1_GAIN4_MASK) /*!< ADC_GC1                                 */
#define ADC_GC1_GAIN5_MASK                       (0x03UL << ADC_GC1_GAIN5_SHIFT)                     /*!< ADC_GC1: GAIN5 Mask                     */
#define ADC_GC1_GAIN5_SHIFT                      10                                                  /*!< ADC_GC1: GAIN5 Position                 */
#define ADC_GC1_GAIN5(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN5_SHIFT))&ADC_GC1_GAIN5_MASK) /*!< ADC_GC1                                 */
#define ADC_GC1_GAIN6_MASK                       (0x03UL << ADC_GC1_GAIN6_SHIFT)                     /*!< ADC_GC1: GAIN6 Mask                     */
#define ADC_GC1_GAIN6_SHIFT                      12                                                  /*!< ADC_GC1: GAIN6 Position                 */
#define ADC_GC1_GAIN6(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN6_SHIFT))&ADC_GC1_GAIN6_MASK) /*!< ADC_GC1                                 */
#define ADC_GC1_GAIN7_MASK                       (0x03UL << ADC_GC1_GAIN7_SHIFT)                     /*!< ADC_GC1: GAIN7 Mask                     */
#define ADC_GC1_GAIN7_SHIFT                      14                                                  /*!< ADC_GC1: GAIN7 Position                 */
#define ADC_GC1_GAIN7(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC1_GAIN7_SHIFT))&ADC_GC1_GAIN7_MASK) /*!< ADC_GC1                                 */
/* ------- GC2 Bit Fields                           ------ */
#define ADC_GC2_GAIN8_MASK                       (0x03UL << ADC_GC2_GAIN8_SHIFT)                     /*!< ADC_GC2: GAIN8 Mask                     */
#define ADC_GC2_GAIN8_SHIFT                      0                                                   /*!< ADC_GC2: GAIN8 Position                 */
#define ADC_GC2_GAIN8(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN8_SHIFT))&ADC_GC2_GAIN8_MASK) /*!< ADC_GC2                                 */
#define ADC_GC2_GAIN9_MASK                       (0x03UL << ADC_GC2_GAIN9_SHIFT)                     /*!< ADC_GC2: GAIN9 Mask                     */
#define ADC_GC2_GAIN9_SHIFT                      2                                                   /*!< ADC_GC2: GAIN9 Position                 */
#define ADC_GC2_GAIN9(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN9_SHIFT))&ADC_GC2_GAIN9_MASK) /*!< ADC_GC2                                 */
#define ADC_GC2_GAIN10_MASK                      (0x03UL << ADC_GC2_GAIN10_SHIFT)                    /*!< ADC_GC2: GAIN10 Mask                    */
#define ADC_GC2_GAIN10_SHIFT                     4                                                   /*!< ADC_GC2: GAIN10 Position                */
#define ADC_GC2_GAIN10(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN10_SHIFT))&ADC_GC2_GAIN10_MASK) /*!< ADC_GC2                                 */
#define ADC_GC2_GAIN11_MASK                      (0x03UL << ADC_GC2_GAIN11_SHIFT)                    /*!< ADC_GC2: GAIN11 Mask                    */
#define ADC_GC2_GAIN11_SHIFT                     6                                                   /*!< ADC_GC2: GAIN11 Position                */
#define ADC_GC2_GAIN11(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN11_SHIFT))&ADC_GC2_GAIN11_MASK) /*!< ADC_GC2                                 */
#define ADC_GC2_GAIN12_MASK                      (0x03UL << ADC_GC2_GAIN12_SHIFT)                    /*!< ADC_GC2: GAIN12 Mask                    */
#define ADC_GC2_GAIN12_SHIFT                     8                                                   /*!< ADC_GC2: GAIN12 Position                */
#define ADC_GC2_GAIN12(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN12_SHIFT))&ADC_GC2_GAIN12_MASK) /*!< ADC_GC2                                 */
#define ADC_GC2_GAIN13_MASK                      (0x03UL << ADC_GC2_GAIN13_SHIFT)                    /*!< ADC_GC2: GAIN13 Mask                    */
#define ADC_GC2_GAIN13_SHIFT                     10                                                  /*!< ADC_GC2: GAIN13 Position                */
#define ADC_GC2_GAIN13(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN13_SHIFT))&ADC_GC2_GAIN13_MASK) /*!< ADC_GC2                                 */
#define ADC_GC2_GAIN14_MASK                      (0x03UL << ADC_GC2_GAIN14_SHIFT)                    /*!< ADC_GC2: GAIN14 Mask                    */
#define ADC_GC2_GAIN14_SHIFT                     12                                                  /*!< ADC_GC2: GAIN14 Position                */
#define ADC_GC2_GAIN14(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN14_SHIFT))&ADC_GC2_GAIN14_MASK) /*!< ADC_GC2                                 */
#define ADC_GC2_GAIN15_MASK                      (0x03UL << ADC_GC2_GAIN15_SHIFT)                    /*!< ADC_GC2: GAIN15 Mask                    */
#define ADC_GC2_GAIN15_SHIFT                     14                                                  /*!< ADC_GC2: GAIN15 Position                */
#define ADC_GC2_GAIN15(x)                        (((uint16_t)(((uint16_t)(x))<<ADC_GC2_GAIN15_SHIFT))&ADC_GC2_GAIN15_MASK) /*!< ADC_GC2                                 */
/* ------- SCTRL Bit Fields                         ------ */
#define ADC_SCTRL_SC_MASK                        (0xFFFFUL << ADC_SCTRL_SC_SHIFT)                    /*!< ADC_SCTRL: SC Mask                      */
#define ADC_SCTRL_SC_SHIFT                       0                                                   /*!< ADC_SCTRL: SC Position                  */
#define ADC_SCTRL_SC(x)                          (((uint16_t)(((uint16_t)(x))<<ADC_SCTRL_SC_SHIFT))&ADC_SCTRL_SC_MASK) /*!< ADC_SCTRL                               */
/* ------- PWR2 Bit Fields                          ------ */
#define ADC_PWR2_SPEEDA_MASK                     (0x03UL << ADC_PWR2_SPEEDA_SHIFT)                   /*!< ADC_PWR2: SPEEDA Mask                   */
#define ADC_PWR2_SPEEDA_SHIFT                    0                                                   /*!< ADC_PWR2: SPEEDA Position               */
#define ADC_PWR2_SPEEDA(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_PWR2_SPEEDA_SHIFT))&ADC_PWR2_SPEEDA_MASK) /*!< ADC_PWR2                                */
#define ADC_PWR2_SPEEDB_MASK                     (0x03UL << ADC_PWR2_SPEEDB_SHIFT)                   /*!< ADC_PWR2: SPEEDB Mask                   */
#define ADC_PWR2_SPEEDB_SHIFT                    2                                                   /*!< ADC_PWR2: SPEEDB Position               */
#define ADC_PWR2_SPEEDB(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_PWR2_SPEEDB_SHIFT))&ADC_PWR2_SPEEDB_MASK) /*!< ADC_PWR2                                */
#define ADC_PWR2_DIV1_MASK                       (0x3FUL << ADC_PWR2_DIV1_SHIFT)                     /*!< ADC_PWR2: DIV1 Mask                     */
#define ADC_PWR2_DIV1_SHIFT                      8                                                   /*!< ADC_PWR2: DIV1 Position                 */
#define ADC_PWR2_DIV1(x)                         (((uint16_t)(((uint16_t)(x))<<ADC_PWR2_DIV1_SHIFT))&ADC_PWR2_DIV1_MASK) /*!< ADC_PWR2                                */
/* ------- CTRL3 Bit Fields                         ------ */
#define ADC_CTRL3_SCNT0_MASK                     (0x07UL << ADC_CTRL3_SCNT0_SHIFT)                   /*!< ADC_CTRL3: SCNT0 Mask                   */
#define ADC_CTRL3_SCNT0_SHIFT                    0                                                   /*!< ADC_CTRL3: SCNT0 Position               */
#define ADC_CTRL3_SCNT0(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL3_SCNT0_SHIFT))&ADC_CTRL3_SCNT0_MASK) /*!< ADC_CTRL3                               */
#define ADC_CTRL3_SCNT1_MASK                     (0x07UL << ADC_CTRL3_SCNT1_SHIFT)                   /*!< ADC_CTRL3: SCNT1 Mask                   */
#define ADC_CTRL3_SCNT1_SHIFT                    3                                                   /*!< ADC_CTRL3: SCNT1 Position               */
#define ADC_CTRL3_SCNT1(x)                       (((uint16_t)(((uint16_t)(x))<<ADC_CTRL3_SCNT1_SHIFT))&ADC_CTRL3_SCNT1_MASK) /*!< ADC_CTRL3                               */
#define ADC_CTRL3_DMASRC_MASK                    (0x01UL << ADC_CTRL3_DMASRC_SHIFT)                  /*!< ADC_CTRL3: DMASRC Mask                  */
#define ADC_CTRL3_DMASRC_SHIFT                   6                                                   /*!< ADC_CTRL3: DMASRC Position              */
/* ------- SCHLTEN Bit Fields                       ------ */
#define ADC_SCHLTEN_SCHLTEN_MASK                 (0xFFFFUL << ADC_SCHLTEN_SCHLTEN_SHIFT)             /*!< ADC_SCHLTEN: SCHLTEN Mask               */
#define ADC_SCHLTEN_SCHLTEN_SHIFT                0                                                   /*!< ADC_SCHLTEN: SCHLTEN Position           */
#define ADC_SCHLTEN_SCHLTEN(x)                   (((uint16_t)(((uint16_t)(x))<<ADC_SCHLTEN_SCHLTEN_SHIFT))&ADC_SCHLTEN_SCHLTEN_MASK) /*!< ADC_SCHLTEN                             */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC - Peripheral instance base addresses */
#define ADC_BasePtr                    0x4005C000UL //!< Peripheral base address
#define ADC                            ((ADC_Type *) ADC_BasePtr) //!< Freescale base pointer
#define ADC_BASE_PTR                   (ADC) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup AOI_Peripheral_access_layer_GROUP AOI Peripheral Access Layer
* @brief C Struct for AOI
* @{
*/

/* ================================================================================ */
/* ================           AOI                                  ================ */
/* ================================================================================ */

/**
 * @brief AND/OR/INVERT module
 */
/**
* @addtogroup AOI_structs_GROUP AOI struct
* @brief Struct for AOI
* @{
*/
typedef struct {                                /*       AOI Structure                                                */
   union {                                      /**< 0000: (size=0012)                                                  */
      struct {                                  /**< 0000: (size=0012)                                                  */
         union {                                /**< 0000: (size=0012)                                                  */
            struct {                            /**< 0000: (size=0012)                                                  */
               union {                          /**< 0000: (size=0012)                                                  */
                  struct {                      /**< 0000: (size=0012)                                                  */
                     union {                    /**< 0000: (size=0012)                                                  */
                        struct {                /**< 0000: (size=0012)                                                  */
                           union {              /**< 0000: (size=0012)                                                  */
                              struct {          /**< 0000: (size=0012)                                                  */
                                 union {        /**< 0000: (size=0012)                                                  */
                                    struct {    /**< 0000: (size=0012)                                                  */
                                       union {  /**< 0000: (size=0012)                                                  */
                                          struct { /**< 0000: (size=0012)                                                  */
                                             union { /**< 0000: (size=0012)                                                  */
                                                struct { /**< 0000: (size=0012)                                                  */
                                                   union { /**< 0000: (size=0012)                                                  */
                                                      struct { /**< 0000: (size=0012)                                                  */
                                                         union { /**< 0000: (size=0012)                                                  */
                                                            struct { /**< 0000: (size=0012)                                                  */
                                                               union { /**< 0000: (size=0012)                                                  */
                                                                  struct { /**< 0000: (size=0012)                                                  */
                                                                     union { /**< 0000: (size=0012)                                                  */
                                                                        struct { /**< 0000: (size=0012)                                                  */
                                                                           union { /**< 0000: (size=0012)                                                  */
                                                                              struct { /**< 0000: (size=0012)                                                  */
                                                                                 union { /**< 0000: (size=0012)                                                  */
                                                                                    struct { /**< 0000: (size=0012)                                                  */
                                                                                       union { /**< 0000: (size=0012)                                                  */
                                                                                          struct { /**< 0000: (size=0012)                                                  */
                                                                                             union { /**< 0000: (size=0012)                                                  */
                                                                                                struct { /**< 0000: (size=0012)                                                  */
                                                                                                   union { /**< 0000: (size=0012)                                                  */
                                                                                                      struct { /**< 0000: (size=0012)                                                  */
                                                                                                         union { /**< 0000: (size=0012)                                                  */
                                                                                                            struct { /**< 0000: (size=0012)                                                  */
                                                                                                               union { /**< 0000: (size=0012)                                                  */
                                                                                                                  struct { /**< 0000: (size=0012)                                                  */
                                                                                                                     union { /**< 0000: (size=0012)                                                  */
                                                                                                                        struct { /**< 0000: (size=0012)                                                  */
                                                                                                                           union { /**< 0000: (size=0012)                                                  */
                                                                                                                              struct { /**< 0000: (size=0012)                                                  */
                                                                                                                                 union { /**< 0000: (size=0012)                                                  */
                                                                                                                                    struct { /**< 0000: (size=0012)                                                  */
                                                                                                                                       union { /**< 0000: (size=0012)                                                  */
                                                                                                                                          struct { /**< 0000: (size=0012)                                                  */
                                                                                                                                             union { /**< 0000: (size=0012)                                                  */
                                                                                                                                                struct { /**< 0000: (size=0012)                                                  */
