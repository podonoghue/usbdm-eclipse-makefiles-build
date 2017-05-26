/****************************************************************************************************//**
 * @file     LPC82x.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for LPC82x.
 *           Equivalent: 
 *
 * @version  V0.4
 * @date     2017/05
 *
 *******************************************************************************************************/

#ifndef MCU_LPC82X
#define MCU_LPC82X

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
/* ----------------------   LPC82x VectorTable                       ---------------------- */
  SPI0_IRQn                     =   0,   /**<  16 SPI0                                                                             */
  SPI1_IRQn                     =   1,   /**<  17 SPI1                                                                             */
  UART0_IRQn                    =   3,   /**<  19 USART0                                                                           */
  UART1_IRQn                    =   4,   /**<  20 USART1                                                                           */
  UART2_IRQn                    =   5,   /**<  21 USART2                                                                           */
  I2C1_IRQn                     =   7,   /**<  23 I2C1                                                                             */
  I2C0_IRQn                     =   8,   /**<  24 I2C0-bus interface                                                               */
  SCT_IRQn                      =   9,   /**<  25 State Configurable Timer                                                         */
  MRT_IRQn                      =  10,   /**<  26 Multi-Rate Timer                                                                 */
  CMP_IRQn                      =  11,   /**<  27 Analog comparator                                                                */
  WDT_IRQn                      =  12,   /**<  28 Windowed Watchdog Timer                                                          */
  BOD_IRQn                      =  13,   /**<  29 System configuration                                                             */
  FLASH_IRQn                    =  14,   /**<  30 Flash controller                                                                 */
  WKT_IRQn                      =  15,   /**<  31 Self wake-up timer                                                               */
  ADC_SEQA_IRQn                 =  16,   /**<  32 12-bit Analog-to-Digital Converter                                               */
  ADC_SEQB_IRQn                 =  17,   /**<  33 12-bit Analog-to-Digital Converter                                               */
  ADC_THCMP_IRQn                =  18,   /**<  34 12-bit Analog-to-Digital Converter                                               */
  ADC_OVR_IRQn                  =  19,   /**<  35 12-bit Analog-to-Digital Converter                                               */
  DMA_IRQn                      =  20,   /**<  36 DMA controller                                                                   */
  I2C2_IRQn                     =  21,   /**<  37 I2C2                                                                             */
  I2C3_IRQn                     =  22,   /**<  38 I2C3                                                                             */
  PIN_INT0_IRQn                 =  24,   /**<  40 Pin interrupt and  pattern match engine                                          */
  PIN_INT1_IRQn                 =  25,   /**<  41 Pin interrupt and  pattern match engine                                          */
  PIN_INT2_IRQn                 =  26,   /**<  42 Pin interrupt and  pattern match engine                                          */
  PIN_INT3_IRQn                 =  27,   /**<  43 Pin interrupt and  pattern match engine                                          */
  PIN_INT4_IRQn                 =  28,   /**<  44 Pin interrupt and  pattern match engine                                          */
  PIN_INT5_IRQn                 =  29,   /**<  45 Pin interrupt and  pattern match engine                                          */
  PIN_INT6_IRQn                 =  30,   /**<  46 Pin interrupt and  pattern match engine                                          */
  PIN_INT7_IRQn                 =  31,   /**<  47 Pin interrupt and  pattern match engine                                          */
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
extern void SPI0_IRQHandler(void);             /**< SPI0                                                                             */
extern void SPI1_IRQHandler(void);             /**< SPI1                                                                             */
extern void UART0_IRQHandler(void);            /**< USART0                                                                           */
extern void UART1_IRQHandler(void);            /**< USART1                                                                           */
extern void UART2_IRQHandler(void);            /**< USART2                                                                           */
extern void I2C1_IRQHandler(void);             /**< I2C1                                                                             */
extern void I2C0_IRQHandler(void);             /**< I2C0-bus interface                                                               */
extern void SCT_IRQHandler(void);              /**< State Configurable Timer                                                         */
extern void MRT_IRQHandler(void);              /**< Multi-Rate Timer                                                                 */
extern void CMP_IRQHandler(void);              /**< Analog comparator                                                                */
extern void WDT_IRQHandler(void);              /**< Windowed Watchdog Timer                                                          */
extern void BOD_IRQHandler(void);              /**< System configuration                                                             */
extern void FLASH_IRQHandler(void);            /**< Flash controller                                                                 */
extern void WKT_IRQHandler(void);              /**< Self wake-up timer                                                               */
extern void ADC_SEQA_IRQHandler(void);         /**< 12-bit Analog-to-Digital Converter                                               */
extern void ADC_SEQB_IRQHandler(void);         /**< 12-bit Analog-to-Digital Converter                                               */
extern void ADC_THCMP_IRQHandler(void);        /**< 12-bit Analog-to-Digital Converter                                               */
extern void ADC_OVR_IRQHandler(void);          /**< 12-bit Analog-to-Digital Converter                                               */
extern void DMA_IRQHandler(void);              /**< DMA controller                                                                   */
extern void I2C2_IRQHandler(void);             /**< I2C2                                                                             */
extern void I2C3_IRQHandler(void);             /**< I2C3                                                                             */
extern void PIN_INT0_IRQHandler(void);         /**< Pin interrupt and  pattern match engine                                          */
extern void PIN_INT1_IRQHandler(void);         /**< Pin interrupt and  pattern match engine                                          */
extern void PIN_INT2_IRQHandler(void);         /**< Pin interrupt and  pattern match engine                                          */
extern void PIN_INT3_IRQHandler(void);         /**< Pin interrupt and  pattern match engine                                          */
extern void PIN_INT4_IRQHandler(void);         /**< Pin interrupt and  pattern match engine                                          */
extern void PIN_INT5_IRQHandler(void);         /**< Pin interrupt and  pattern match engine                                          */
extern void PIN_INT6_IRQHandler(void);         /**< Pin interrupt and  pattern match engine                                          */
extern void PIN_INT7_IRQHandler(void);         /**< Pin interrupt and  pattern match engine                                          */

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
#define __CM0PLUS_REV             0x0001     /**< CPU Revision                                        */
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
/* ================           LPC_ADC (file:ADC_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief 12-bit Analog-to-Digital Converter
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       LPC_ADC Structure                                            */
   __IO uint32_t  CTRL;                         /**< 0000: A/D Control Register. Contains the clock divide value, enable bits for each sequence and the A/D power-down bit */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  SEQA_CTRL;                    /**< 0008: A/D Conversion Sequence-A control Register: Controls triggering and channel selection for conversion sequence-A. Also specifies interrupt mode for sequence-A */
   __IO uint32_t  SEQB_CTRL;                    /**< 000C: A/D Conversion Sequence-B Control Register: Controls triggering and channel selection for conversion sequence-B. Also specifies interrupt mode for sequence-B */
   __IO uint32_t  SEQA_GDAT;                    /**< 0010: A/D Sequence-A Global Data Register. This register contains the result of the most recent A/D conversion performed under sequence-A */
   __IO uint32_t  SEQB_GDAT;                    /**< 0014: A/D Sequence-B Global Data Register. This register contains the result of the most recent A/D conversion performed under sequence-B */
        uint8_t   RESERVED_1[8];               
   __I  uint32_t  DAT0;                         /**< 0020: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT1;                         /**< 0024: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT2;                         /**< 0028: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT3;                         /**< 002C: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT4;                         /**< 0030: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT5;                         /**< 0034: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT6;                         /**< 0038: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT7;                         /**< 003C: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT8;                         /**< 0040: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT9;                         /**< 0044: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT10;                        /**< 0048: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __I  uint32_t  DAT11;                        /**< 004C: A/D Channel 0 Data Register. This register contains the result of the most recent conversion completed on channel 0 */
   __IO uint32_t  THR0_LOW;                     /**< 0050: A/D Low Compare Threshold Register 0 : Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 0 */
   __IO uint32_t  THR1_LOW;                     /**< 0054: A/D Low Compare Threshold Register 1: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 1 */
   __IO uint32_t  THR0_HIGH;                    /**< 0058: A/D High Compare Threshold Register 0: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 0 */
   __IO uint32_t  THR1_HIGH;                    /**< 005C: A/D High Compare Threshold Register 1: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 1 */
   __IO uint32_t  CHAN_THRSEL;                  /**< 0060: A/D Channel-Threshold Select Register. Specifies which set of threshold compare registers are to be used for each channel */
   __IO uint32_t  INTEN;                        /**< 0064: A/D Interrupt Enable Register. This register contains enable bits that enable the sequence-A, sequence-B, threshold compare and data overrun interrupts to be generated */
   __IO uint32_t  FLAGS;                        /**< 0068: A/D Flags Register. Contains the four interrupt request flags and the individual component overrun and threshold-compare flags. (The overrun bits replicate information stored in the result registers) */
   __IO uint32_t  TRM;                          /**< 006C: ADC trim register                                            */
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
/* ------- CTRL Bit Fields                          ------ */
#define LPC_ADC_CTRL_CLKDIV_MASK                 (0xFFU)                                             /*!< LPC_ADC_CTRL: CLKDIV Mask               */
#define LPC_ADC_CTRL_CLKDIV_SHIFT                (0U)                                                /*!< LPC_ADC_CTRL: CLKDIV Position           */
#define LPC_ADC_CTRL_CLKDIV(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CTRL_CLKDIV_SHIFT))&LPC_ADC_CTRL_CLKDIV_MASK) /*!< LPC_ADC_CTRL                            */
#define LPC_ADC_CTRL_LPWRMODE_MASK               (0x400U)                                            /*!< LPC_ADC_CTRL: LPWRMODE Mask             */
#define LPC_ADC_CTRL_LPWRMODE_SHIFT              (10U)                                               /*!< LPC_ADC_CTRL: LPWRMODE Position         */
#define LPC_ADC_CTRL_LPWRMODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CTRL_LPWRMODE_SHIFT))&LPC_ADC_CTRL_LPWRMODE_MASK) /*!< LPC_ADC_CTRL                            */
#define LPC_ADC_CTRL_CAL_MODE_MASK               (0x40000000U)                                       /*!< LPC_ADC_CTRL: CAL_MODE Mask             */
#define LPC_ADC_CTRL_CAL_MODE_SHIFT              (30U)                                               /*!< LPC_ADC_CTRL: CAL_MODE Position         */
#define LPC_ADC_CTRL_CAL_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CTRL_CAL_MODE_SHIFT))&LPC_ADC_CTRL_CAL_MODE_MASK) /*!< LPC_ADC_CTRL                            */
/* ------- SEQA_CTRL Bit Fields                     ------ */
#define LPC_ADC_SEQA_CTRL_CHANNELS_MASK          (0xFFFU)                                            /*!< LPC_ADC_SEQA_CTRL: CHANNELS Mask        */
#define LPC_ADC_SEQA_CTRL_CHANNELS_SHIFT         (0U)                                                /*!< LPC_ADC_SEQA_CTRL: CHANNELS Position    */
#define LPC_ADC_SEQA_CTRL_CHANNELS(x)            (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_CHANNELS_SHIFT))&LPC_ADC_SEQA_CTRL_CHANNELS_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_TRIGGER_MASK           (0x7000U)                                           /*!< LPC_ADC_SEQA_CTRL: TRIGGER Mask         */
#define LPC_ADC_SEQA_CTRL_TRIGGER_SHIFT          (12U)                                               /*!< LPC_ADC_SEQA_CTRL: TRIGGER Position     */
#define LPC_ADC_SEQA_CTRL_TRIGGER(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_TRIGGER_SHIFT))&LPC_ADC_SEQA_CTRL_TRIGGER_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_TRIGPOL_MASK           (0x40000U)                                          /*!< LPC_ADC_SEQA_CTRL: TRIGPOL Mask         */
#define LPC_ADC_SEQA_CTRL_TRIGPOL_SHIFT          (18U)                                               /*!< LPC_ADC_SEQA_CTRL: TRIGPOL Position     */
#define LPC_ADC_SEQA_CTRL_TRIGPOL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_TRIGPOL_SHIFT))&LPC_ADC_SEQA_CTRL_TRIGPOL_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_SYNCBYPASS_MASK        (0x80000U)                                          /*!< LPC_ADC_SEQA_CTRL: SYNCBYPASS Mask      */
#define LPC_ADC_SEQA_CTRL_SYNCBYPASS_SHIFT       (19U)                                               /*!< LPC_ADC_SEQA_CTRL: SYNCBYPASS Position  */
#define LPC_ADC_SEQA_CTRL_SYNCBYPASS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_SYNCBYPASS_SHIFT))&LPC_ADC_SEQA_CTRL_SYNCBYPASS_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_START_MASK             (0x4000000U)                                        /*!< LPC_ADC_SEQA_CTRL: START Mask           */
#define LPC_ADC_SEQA_CTRL_START_SHIFT            (26U)                                               /*!< LPC_ADC_SEQA_CTRL: START Position       */
#define LPC_ADC_SEQA_CTRL_START(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_START_SHIFT))&LPC_ADC_SEQA_CTRL_START_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_BURST_MASK             (0x8000000U)                                        /*!< LPC_ADC_SEQA_CTRL: BURST Mask           */
#define LPC_ADC_SEQA_CTRL_BURST_SHIFT            (27U)                                               /*!< LPC_ADC_SEQA_CTRL: BURST Position       */
#define LPC_ADC_SEQA_CTRL_BURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_BURST_SHIFT))&LPC_ADC_SEQA_CTRL_BURST_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_SINGLESTEP_MASK        (0x10000000U)                                       /*!< LPC_ADC_SEQA_CTRL: SINGLESTEP Mask      */
#define LPC_ADC_SEQA_CTRL_SINGLESTEP_SHIFT       (28U)                                               /*!< LPC_ADC_SEQA_CTRL: SINGLESTEP Position  */
#define LPC_ADC_SEQA_CTRL_SINGLESTEP(x)          (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_SINGLESTEP_SHIFT))&LPC_ADC_SEQA_CTRL_SINGLESTEP_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_LOWPRIO_MASK           (0x20000000U)                                       /*!< LPC_ADC_SEQA_CTRL: LOWPRIO Mask         */
#define LPC_ADC_SEQA_CTRL_LOWPRIO_SHIFT          (29U)                                               /*!< LPC_ADC_SEQA_CTRL: LOWPRIO Position     */
#define LPC_ADC_SEQA_CTRL_LOWPRIO(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_LOWPRIO_SHIFT))&LPC_ADC_SEQA_CTRL_LOWPRIO_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_MODE_MASK              (0x40000000U)                                       /*!< LPC_ADC_SEQA_CTRL: MODE Mask            */
#define LPC_ADC_SEQA_CTRL_MODE_SHIFT             (30U)                                               /*!< LPC_ADC_SEQA_CTRL: MODE Position        */
#define LPC_ADC_SEQA_CTRL_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_MODE_SHIFT))&LPC_ADC_SEQA_CTRL_MODE_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
#define LPC_ADC_SEQA_CTRL_SEQA_ENA_MASK          (0x80000000U)                                       /*!< LPC_ADC_SEQA_CTRL: SEQA_ENA Mask        */
#define LPC_ADC_SEQA_CTRL_SEQA_ENA_SHIFT         (31U)                                               /*!< LPC_ADC_SEQA_CTRL: SEQA_ENA Position    */
#define LPC_ADC_SEQA_CTRL_SEQA_ENA(x)            (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_CTRL_SEQA_ENA_SHIFT))&LPC_ADC_SEQA_CTRL_SEQA_ENA_MASK) /*!< LPC_ADC_SEQA_CTRL                       */
/* ------- SEQB_CTRL Bit Fields                     ------ */
#define LPC_ADC_SEQB_CTRL_CHANNELS_MASK          (0xFFFU)                                            /*!< LPC_ADC_SEQB_CTRL: CHANNELS Mask        */
#define LPC_ADC_SEQB_CTRL_CHANNELS_SHIFT         (0U)                                                /*!< LPC_ADC_SEQB_CTRL: CHANNELS Position    */
#define LPC_ADC_SEQB_CTRL_CHANNELS(x)            (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_CHANNELS_SHIFT))&LPC_ADC_SEQB_CTRL_CHANNELS_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
#define LPC_ADC_SEQB_CTRL_TRIGGER_MASK           (0x7000U)                                           /*!< LPC_ADC_SEQB_CTRL: TRIGGER Mask         */
#define LPC_ADC_SEQB_CTRL_TRIGGER_SHIFT          (12U)                                               /*!< LPC_ADC_SEQB_CTRL: TRIGGER Position     */
#define LPC_ADC_SEQB_CTRL_TRIGGER(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_TRIGGER_SHIFT))&LPC_ADC_SEQB_CTRL_TRIGGER_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
#define LPC_ADC_SEQB_CTRL_TRIGPOL_MASK           (0x40000U)                                          /*!< LPC_ADC_SEQB_CTRL: TRIGPOL Mask         */
#define LPC_ADC_SEQB_CTRL_TRIGPOL_SHIFT          (18U)                                               /*!< LPC_ADC_SEQB_CTRL: TRIGPOL Position     */
#define LPC_ADC_SEQB_CTRL_TRIGPOL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_TRIGPOL_SHIFT))&LPC_ADC_SEQB_CTRL_TRIGPOL_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
#define LPC_ADC_SEQB_CTRL_SYNCBYPASS_MASK        (0x80000U)                                          /*!< LPC_ADC_SEQB_CTRL: SYNCBYPASS Mask      */
#define LPC_ADC_SEQB_CTRL_SYNCBYPASS_SHIFT       (19U)                                               /*!< LPC_ADC_SEQB_CTRL: SYNCBYPASS Position  */
#define LPC_ADC_SEQB_CTRL_SYNCBYPASS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_SYNCBYPASS_SHIFT))&LPC_ADC_SEQB_CTRL_SYNCBYPASS_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
#define LPC_ADC_SEQB_CTRL_START_MASK             (0x4000000U)                                        /*!< LPC_ADC_SEQB_CTRL: START Mask           */
#define LPC_ADC_SEQB_CTRL_START_SHIFT            (26U)                                               /*!< LPC_ADC_SEQB_CTRL: START Position       */
#define LPC_ADC_SEQB_CTRL_START(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_START_SHIFT))&LPC_ADC_SEQB_CTRL_START_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
#define LPC_ADC_SEQB_CTRL_BURST_MASK             (0x8000000U)                                        /*!< LPC_ADC_SEQB_CTRL: BURST Mask           */
#define LPC_ADC_SEQB_CTRL_BURST_SHIFT            (27U)                                               /*!< LPC_ADC_SEQB_CTRL: BURST Position       */
#define LPC_ADC_SEQB_CTRL_BURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_BURST_SHIFT))&LPC_ADC_SEQB_CTRL_BURST_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
#define LPC_ADC_SEQB_CTRL_SINGLESTEP_MASK        (0x10000000U)                                       /*!< LPC_ADC_SEQB_CTRL: SINGLESTEP Mask      */
#define LPC_ADC_SEQB_CTRL_SINGLESTEP_SHIFT       (28U)                                               /*!< LPC_ADC_SEQB_CTRL: SINGLESTEP Position  */
#define LPC_ADC_SEQB_CTRL_SINGLESTEP(x)          (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_SINGLESTEP_SHIFT))&LPC_ADC_SEQB_CTRL_SINGLESTEP_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
#define LPC_ADC_SEQB_CTRL_MODE_MASK              (0x40000000U)                                       /*!< LPC_ADC_SEQB_CTRL: MODE Mask            */
#define LPC_ADC_SEQB_CTRL_MODE_SHIFT             (30U)                                               /*!< LPC_ADC_SEQB_CTRL: MODE Position        */
#define LPC_ADC_SEQB_CTRL_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_MODE_SHIFT))&LPC_ADC_SEQB_CTRL_MODE_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
#define LPC_ADC_SEQB_CTRL_SEQB_ENA_MASK          (0x80000000U)                                       /*!< LPC_ADC_SEQB_CTRL: SEQB_ENA Mask        */
#define LPC_ADC_SEQB_CTRL_SEQB_ENA_SHIFT         (31U)                                               /*!< LPC_ADC_SEQB_CTRL: SEQB_ENA Position    */
#define LPC_ADC_SEQB_CTRL_SEQB_ENA(x)            (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_CTRL_SEQB_ENA_SHIFT))&LPC_ADC_SEQB_CTRL_SEQB_ENA_MASK) /*!< LPC_ADC_SEQB_CTRL                       */
/* ------- SEQA_GDAT Bit Fields                     ------ */
#define LPC_ADC_SEQA_GDAT_RESULT_MASK            (0xFFF0U)                                           /*!< LPC_ADC_SEQA_GDAT: RESULT Mask          */
#define LPC_ADC_SEQA_GDAT_RESULT_SHIFT           (4U)                                                /*!< LPC_ADC_SEQA_GDAT: RESULT Position      */
#define LPC_ADC_SEQA_GDAT_RESULT(x)              (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_GDAT_RESULT_SHIFT))&LPC_ADC_SEQA_GDAT_RESULT_MASK) /*!< LPC_ADC_SEQA_GDAT                       */
#define LPC_ADC_SEQA_GDAT_THCMPRANGE_MASK        (0x30000U)                                          /*!< LPC_ADC_SEQA_GDAT: THCMPRANGE Mask      */
#define LPC_ADC_SEQA_GDAT_THCMPRANGE_SHIFT       (16U)                                               /*!< LPC_ADC_SEQA_GDAT: THCMPRANGE Position  */
#define LPC_ADC_SEQA_GDAT_THCMPRANGE(x)          (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_GDAT_THCMPRANGE_SHIFT))&LPC_ADC_SEQA_GDAT_THCMPRANGE_MASK) /*!< LPC_ADC_SEQA_GDAT                       */
#define LPC_ADC_SEQA_GDAT_THCMPCROSS_MASK        (0xC0000U)                                          /*!< LPC_ADC_SEQA_GDAT: THCMPCROSS Mask      */
#define LPC_ADC_SEQA_GDAT_THCMPCROSS_SHIFT       (18U)                                               /*!< LPC_ADC_SEQA_GDAT: THCMPCROSS Position  */
#define LPC_ADC_SEQA_GDAT_THCMPCROSS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_GDAT_THCMPCROSS_SHIFT))&LPC_ADC_SEQA_GDAT_THCMPCROSS_MASK) /*!< LPC_ADC_SEQA_GDAT                       */
#define LPC_ADC_SEQA_GDAT_CHN_MASK               (0x3C000000U)                                       /*!< LPC_ADC_SEQA_GDAT: CHN Mask             */
#define LPC_ADC_SEQA_GDAT_CHN_SHIFT              (26U)                                               /*!< LPC_ADC_SEQA_GDAT: CHN Position         */
#define LPC_ADC_SEQA_GDAT_CHN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_GDAT_CHN_SHIFT))&LPC_ADC_SEQA_GDAT_CHN_MASK) /*!< LPC_ADC_SEQA_GDAT                       */
#define LPC_ADC_SEQA_GDAT_OVERRUN_MASK           (0x40000000U)                                       /*!< LPC_ADC_SEQA_GDAT: OVERRUN Mask         */
#define LPC_ADC_SEQA_GDAT_OVERRUN_SHIFT          (30U)                                               /*!< LPC_ADC_SEQA_GDAT: OVERRUN Position     */
#define LPC_ADC_SEQA_GDAT_OVERRUN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_GDAT_OVERRUN_SHIFT))&LPC_ADC_SEQA_GDAT_OVERRUN_MASK) /*!< LPC_ADC_SEQA_GDAT                       */
#define LPC_ADC_SEQA_GDAT_DATAVALID_MASK         (0x80000000U)                                       /*!< LPC_ADC_SEQA_GDAT: DATAVALID Mask       */
#define LPC_ADC_SEQA_GDAT_DATAVALID_SHIFT        (31U)                                               /*!< LPC_ADC_SEQA_GDAT: DATAVALID Position   */
#define LPC_ADC_SEQA_GDAT_DATAVALID(x)           (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQA_GDAT_DATAVALID_SHIFT))&LPC_ADC_SEQA_GDAT_DATAVALID_MASK) /*!< LPC_ADC_SEQA_GDAT                       */
/* ------- SEQB_GDAT Bit Fields                     ------ */
#define LPC_ADC_SEQB_GDAT_RESULT_MASK            (0xFFF0U)                                           /*!< LPC_ADC_SEQB_GDAT: RESULT Mask          */
#define LPC_ADC_SEQB_GDAT_RESULT_SHIFT           (4U)                                                /*!< LPC_ADC_SEQB_GDAT: RESULT Position      */
#define LPC_ADC_SEQB_GDAT_RESULT(x)              (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_GDAT_RESULT_SHIFT))&LPC_ADC_SEQB_GDAT_RESULT_MASK) /*!< LPC_ADC_SEQB_GDAT                       */
#define LPC_ADC_SEQB_GDAT_THCMPRANGE_MASK        (0x30000U)                                          /*!< LPC_ADC_SEQB_GDAT: THCMPRANGE Mask      */
#define LPC_ADC_SEQB_GDAT_THCMPRANGE_SHIFT       (16U)                                               /*!< LPC_ADC_SEQB_GDAT: THCMPRANGE Position  */
#define LPC_ADC_SEQB_GDAT_THCMPRANGE(x)          (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_GDAT_THCMPRANGE_SHIFT))&LPC_ADC_SEQB_GDAT_THCMPRANGE_MASK) /*!< LPC_ADC_SEQB_GDAT                       */
#define LPC_ADC_SEQB_GDAT_THCMPCROSS_MASK        (0xC0000U)                                          /*!< LPC_ADC_SEQB_GDAT: THCMPCROSS Mask      */
#define LPC_ADC_SEQB_GDAT_THCMPCROSS_SHIFT       (18U)                                               /*!< LPC_ADC_SEQB_GDAT: THCMPCROSS Position  */
#define LPC_ADC_SEQB_GDAT_THCMPCROSS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_GDAT_THCMPCROSS_SHIFT))&LPC_ADC_SEQB_GDAT_THCMPCROSS_MASK) /*!< LPC_ADC_SEQB_GDAT                       */
#define LPC_ADC_SEQB_GDAT_CHN_MASK               (0x3C000000U)                                       /*!< LPC_ADC_SEQB_GDAT: CHN Mask             */
#define LPC_ADC_SEQB_GDAT_CHN_SHIFT              (26U)                                               /*!< LPC_ADC_SEQB_GDAT: CHN Position         */
#define LPC_ADC_SEQB_GDAT_CHN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_GDAT_CHN_SHIFT))&LPC_ADC_SEQB_GDAT_CHN_MASK) /*!< LPC_ADC_SEQB_GDAT                       */
#define LPC_ADC_SEQB_GDAT_OVERRUN_MASK           (0x40000000U)                                       /*!< LPC_ADC_SEQB_GDAT: OVERRUN Mask         */
#define LPC_ADC_SEQB_GDAT_OVERRUN_SHIFT          (30U)                                               /*!< LPC_ADC_SEQB_GDAT: OVERRUN Position     */
#define LPC_ADC_SEQB_GDAT_OVERRUN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_GDAT_OVERRUN_SHIFT))&LPC_ADC_SEQB_GDAT_OVERRUN_MASK) /*!< LPC_ADC_SEQB_GDAT                       */
#define LPC_ADC_SEQB_GDAT_DATAVALID_MASK         (0x80000000U)                                       /*!< LPC_ADC_SEQB_GDAT: DATAVALID Mask       */
#define LPC_ADC_SEQB_GDAT_DATAVALID_SHIFT        (31U)                                               /*!< LPC_ADC_SEQB_GDAT: DATAVALID Position   */
#define LPC_ADC_SEQB_GDAT_DATAVALID(x)           (((uint32_t)(((uint32_t)(x))<<LPC_ADC_SEQB_GDAT_DATAVALID_SHIFT))&LPC_ADC_SEQB_GDAT_DATAVALID_MASK) /*!< LPC_ADC_SEQB_GDAT                       */
/* ------- DAT0 Bit Fields                          ------ */
#define LPC_ADC_DAT0_RESULT_MASK                 (0xFFF0U)                                           /*!< LPC_ADC_DAT0: RESULT Mask               */
#define LPC_ADC_DAT0_RESULT_SHIFT                (4U)                                                /*!< LPC_ADC_DAT0: RESULT Position           */
#define LPC_ADC_DAT0_RESULT(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT0_RESULT_SHIFT))&LPC_ADC_DAT0_RESULT_MASK) /*!< LPC_ADC_DAT0                            */
#define LPC_ADC_DAT0_THCMPRANGE_MASK             (0x30000U)                                          /*!< LPC_ADC_DAT0: THCMPRANGE Mask           */
#define LPC_ADC_DAT0_THCMPRANGE_SHIFT            (16U)                                               /*!< LPC_ADC_DAT0: THCMPRANGE Position       */
#define LPC_ADC_DAT0_THCMPRANGE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT0_THCMPRANGE_SHIFT))&LPC_ADC_DAT0_THCMPRANGE_MASK) /*!< LPC_ADC_DAT0                            */
#define LPC_ADC_DAT0_THCMPCROSS_MASK             (0xC0000U)                                          /*!< LPC_ADC_DAT0: THCMPCROSS Mask           */
#define LPC_ADC_DAT0_THCMPCROSS_SHIFT            (18U)                                               /*!< LPC_ADC_DAT0: THCMPCROSS Position       */
#define LPC_ADC_DAT0_THCMPCROSS(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT0_THCMPCROSS_SHIFT))&LPC_ADC_DAT0_THCMPCROSS_MASK) /*!< LPC_ADC_DAT0                            */
#define LPC_ADC_DAT0_CHANNEL_MASK                (0x3C000000U)                                       /*!< LPC_ADC_DAT0: CHANNEL Mask              */
#define LPC_ADC_DAT0_CHANNEL_SHIFT               (26U)                                               /*!< LPC_ADC_DAT0: CHANNEL Position          */
#define LPC_ADC_DAT0_CHANNEL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT0_CHANNEL_SHIFT))&LPC_ADC_DAT0_CHANNEL_MASK) /*!< LPC_ADC_DAT0                            */
#define LPC_ADC_DAT0_OVERRUN_MASK                (0x40000000U)                                       /*!< LPC_ADC_DAT0: OVERRUN Mask              */
#define LPC_ADC_DAT0_OVERRUN_SHIFT               (30U)                                               /*!< LPC_ADC_DAT0: OVERRUN Position          */
#define LPC_ADC_DAT0_OVERRUN(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT0_OVERRUN_SHIFT))&LPC_ADC_DAT0_OVERRUN_MASK) /*!< LPC_ADC_DAT0                            */
#define LPC_ADC_DAT0_DATAVALID_MASK              (0x80000000U)                                       /*!< LPC_ADC_DAT0: DATAVALID Mask            */
#define LPC_ADC_DAT0_DATAVALID_SHIFT             (31U)                                               /*!< LPC_ADC_DAT0: DATAVALID Position        */
#define LPC_ADC_DAT0_DATAVALID(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT0_DATAVALID_SHIFT))&LPC_ADC_DAT0_DATAVALID_MASK) /*!< LPC_ADC_DAT0                            */
/* ------- DAT Bit Fields                           ------ */
#define LPC_ADC_DAT_RESULT_MASK                  (0xFFF0U)                                           /*!< LPC_ADC_DAT: RESULT Mask                */
#define LPC_ADC_DAT_RESULT_SHIFT                 (4U)                                                /*!< LPC_ADC_DAT: RESULT Position            */
#define LPC_ADC_DAT_RESULT(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT_RESULT_SHIFT))&LPC_ADC_DAT_RESULT_MASK) /*!< LPC_ADC_DAT                             */
#define LPC_ADC_DAT_THCMPRANGE_MASK              (0x30000U)                                          /*!< LPC_ADC_DAT: THCMPRANGE Mask            */
#define LPC_ADC_DAT_THCMPRANGE_SHIFT             (16U)                                               /*!< LPC_ADC_DAT: THCMPRANGE Position        */
#define LPC_ADC_DAT_THCMPRANGE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT_THCMPRANGE_SHIFT))&LPC_ADC_DAT_THCMPRANGE_MASK) /*!< LPC_ADC_DAT                             */
#define LPC_ADC_DAT_THCMPCROSS_MASK              (0xC0000U)                                          /*!< LPC_ADC_DAT: THCMPCROSS Mask            */
#define LPC_ADC_DAT_THCMPCROSS_SHIFT             (18U)                                               /*!< LPC_ADC_DAT: THCMPCROSS Position        */
#define LPC_ADC_DAT_THCMPCROSS(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT_THCMPCROSS_SHIFT))&LPC_ADC_DAT_THCMPCROSS_MASK) /*!< LPC_ADC_DAT                             */
#define LPC_ADC_DAT_CHANNEL_MASK                 (0x3C000000U)                                       /*!< LPC_ADC_DAT: CHANNEL Mask               */
#define LPC_ADC_DAT_CHANNEL_SHIFT                (26U)                                               /*!< LPC_ADC_DAT: CHANNEL Position           */
#define LPC_ADC_DAT_CHANNEL(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT_CHANNEL_SHIFT))&LPC_ADC_DAT_CHANNEL_MASK) /*!< LPC_ADC_DAT                             */
#define LPC_ADC_DAT_OVERRUN_MASK                 (0x40000000U)                                       /*!< LPC_ADC_DAT: OVERRUN Mask               */
#define LPC_ADC_DAT_OVERRUN_SHIFT                (30U)                                               /*!< LPC_ADC_DAT: OVERRUN Position           */
#define LPC_ADC_DAT_OVERRUN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT_OVERRUN_SHIFT))&LPC_ADC_DAT_OVERRUN_MASK) /*!< LPC_ADC_DAT                             */
#define LPC_ADC_DAT_DATAVALID_MASK               (0x80000000U)                                       /*!< LPC_ADC_DAT: DATAVALID Mask             */
#define LPC_ADC_DAT_DATAVALID_SHIFT              (31U)                                               /*!< LPC_ADC_DAT: DATAVALID Position         */
#define LPC_ADC_DAT_DATAVALID(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_DAT_DATAVALID_SHIFT))&LPC_ADC_DAT_DATAVALID_MASK) /*!< LPC_ADC_DAT                             */
/* ------- THR0_LOW Bit Fields                      ------ */
#define LPC_ADC_THR0_LOW_THRLOW_MASK             (0xFFF0U)                                           /*!< LPC_ADC_THR0_LOW: THRLOW Mask           */
#define LPC_ADC_THR0_LOW_THRLOW_SHIFT            (4U)                                                /*!< LPC_ADC_THR0_LOW: THRLOW Position       */
#define LPC_ADC_THR0_LOW_THRLOW(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_THR0_LOW_THRLOW_SHIFT))&LPC_ADC_THR0_LOW_THRLOW_MASK) /*!< LPC_ADC_THR0_LOW                        */
/* ------- THR1_LOW Bit Fields                      ------ */
#define LPC_ADC_THR1_LOW_THRLOW_MASK             (0xFFF0U)                                           /*!< LPC_ADC_THR1_LOW: THRLOW Mask           */
#define LPC_ADC_THR1_LOW_THRLOW_SHIFT            (4U)                                                /*!< LPC_ADC_THR1_LOW: THRLOW Position       */
#define LPC_ADC_THR1_LOW_THRLOW(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_THR1_LOW_THRLOW_SHIFT))&LPC_ADC_THR1_LOW_THRLOW_MASK) /*!< LPC_ADC_THR1_LOW                        */
/* ------- THR0_HIGH Bit Fields                     ------ */
#define LPC_ADC_THR0_HIGH_THRHIGH_MASK           (0xFFF0U)                                           /*!< LPC_ADC_THR0_HIGH: THRHIGH Mask         */
#define LPC_ADC_THR0_HIGH_THRHIGH_SHIFT          (4U)                                                /*!< LPC_ADC_THR0_HIGH: THRHIGH Position     */
#define LPC_ADC_THR0_HIGH_THRHIGH(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_THR0_HIGH_THRHIGH_SHIFT))&LPC_ADC_THR0_HIGH_THRHIGH_MASK) /*!< LPC_ADC_THR0_HIGH                       */
/* ------- THR1_HIGH Bit Fields                     ------ */
#define LPC_ADC_THR1_HIGH_THRHIGH_MASK           (0xFFF0U)                                           /*!< LPC_ADC_THR1_HIGH: THRHIGH Mask         */
#define LPC_ADC_THR1_HIGH_THRHIGH_SHIFT          (4U)                                                /*!< LPC_ADC_THR1_HIGH: THRHIGH Position     */
#define LPC_ADC_THR1_HIGH_THRHIGH(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_THR1_HIGH_THRHIGH_SHIFT))&LPC_ADC_THR1_HIGH_THRHIGH_MASK) /*!< LPC_ADC_THR1_HIGH                       */
/* ------- CHAN_THRSEL Bit Fields                   ------ */
#define LPC_ADC_CHAN_THRSEL_CH0_THRSEL_MASK      (0x1U)                                              /*!< LPC_ADC_CHAN_THRSEL: CH0_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH0_THRSEL_SHIFT     (0U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH0_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH0_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH0_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH0_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH1_THRSEL_MASK      (0x2U)                                              /*!< LPC_ADC_CHAN_THRSEL: CH1_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH1_THRSEL_SHIFT     (1U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH1_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH1_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH1_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH1_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH2_THRSEL_MASK      (0x4U)                                              /*!< LPC_ADC_CHAN_THRSEL: CH2_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH2_THRSEL_SHIFT     (2U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH2_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH2_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH2_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH2_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH3_THRSEL_MASK      (0x8U)                                              /*!< LPC_ADC_CHAN_THRSEL: CH3_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH3_THRSEL_SHIFT     (3U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH3_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH3_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH3_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH3_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH4_THRSEL_MASK      (0x10U)                                             /*!< LPC_ADC_CHAN_THRSEL: CH4_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH4_THRSEL_SHIFT     (4U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH4_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH4_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH4_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH4_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH5_THRSEL_MASK      (0x20U)                                             /*!< LPC_ADC_CHAN_THRSEL: CH5_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH5_THRSEL_SHIFT     (5U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH5_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH5_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH5_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH5_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH6_THRSEL_MASK      (0x40U)                                             /*!< LPC_ADC_CHAN_THRSEL: CH6_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH6_THRSEL_SHIFT     (6U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH6_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH6_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH6_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH6_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH7_THRSEL_MASK      (0x80U)                                             /*!< LPC_ADC_CHAN_THRSEL: CH7_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH7_THRSEL_SHIFT     (7U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH7_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH7_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH7_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH7_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH8_THRSEL_MASK      (0x100U)                                            /*!< LPC_ADC_CHAN_THRSEL: CH8_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH8_THRSEL_SHIFT     (8U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH8_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH8_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH8_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH8_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH9_THRSEL_MASK      (0x200U)                                            /*!< LPC_ADC_CHAN_THRSEL: CH9_THRSEL Mask    */
#define LPC_ADC_CHAN_THRSEL_CH9_THRSEL_SHIFT     (9U)                                                /*!< LPC_ADC_CHAN_THRSEL: CH9_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH9_THRSEL(x)        (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH9_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH9_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH10_THRSEL_MASK     (0x400U)                                            /*!< LPC_ADC_CHAN_THRSEL: CH10_THRSEL Mask   */
#define LPC_ADC_CHAN_THRSEL_CH10_THRSEL_SHIFT    (10U)                                               /*!< LPC_ADC_CHAN_THRSEL: CH10_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH10_THRSEL(x)       (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH10_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH10_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
#define LPC_ADC_CHAN_THRSEL_CH11_THRSEL_MASK     (0x800U)                                            /*!< LPC_ADC_CHAN_THRSEL: CH11_THRSEL Mask   */
#define LPC_ADC_CHAN_THRSEL_CH11_THRSEL_SHIFT    (11U)                                               /*!< LPC_ADC_CHAN_THRSEL: CH11_THRSEL Position*/
#define LPC_ADC_CHAN_THRSEL_CH11_THRSEL(x)       (((uint32_t)(((uint32_t)(x))<<LPC_ADC_CHAN_THRSEL_CH11_THRSEL_SHIFT))&LPC_ADC_CHAN_THRSEL_CH11_THRSEL_MASK) /*!< LPC_ADC_CHAN_THRSEL                     */
/* ------- INTEN Bit Fields                         ------ */
#define LPC_ADC_INTEN_SEQA_INTEN_MASK            (0x1U)                                              /*!< LPC_ADC_INTEN: SEQA_INTEN Mask          */
#define LPC_ADC_INTEN_SEQA_INTEN_SHIFT           (0U)                                                /*!< LPC_ADC_INTEN: SEQA_INTEN Position      */
#define LPC_ADC_INTEN_SEQA_INTEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_SEQA_INTEN_SHIFT))&LPC_ADC_INTEN_SEQA_INTEN_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_SEQB_INTEN_MASK            (0x2U)                                              /*!< LPC_ADC_INTEN: SEQB_INTEN Mask          */
#define LPC_ADC_INTEN_SEQB_INTEN_SHIFT           (1U)                                                /*!< LPC_ADC_INTEN: SEQB_INTEN Position      */
#define LPC_ADC_INTEN_SEQB_INTEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_SEQB_INTEN_SHIFT))&LPC_ADC_INTEN_SEQB_INTEN_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_OVR_INTEN_MASK             (0x4U)                                              /*!< LPC_ADC_INTEN: OVR_INTEN Mask           */
#define LPC_ADC_INTEN_OVR_INTEN_SHIFT            (2U)                                                /*!< LPC_ADC_INTEN: OVR_INTEN Position       */
#define LPC_ADC_INTEN_OVR_INTEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_OVR_INTEN_SHIFT))&LPC_ADC_INTEN_OVR_INTEN_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN0_MASK           (0x18U)                                             /*!< LPC_ADC_INTEN: ADCMPINTEN0 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN0_SHIFT          (3U)                                                /*!< LPC_ADC_INTEN: ADCMPINTEN0 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN0(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN0_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN0_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN1_MASK           (0x60U)                                             /*!< LPC_ADC_INTEN: ADCMPINTEN1 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN1_SHIFT          (5U)                                                /*!< LPC_ADC_INTEN: ADCMPINTEN1 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN1(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN1_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN1_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN2_MASK           (0x180U)                                            /*!< LPC_ADC_INTEN: ADCMPINTEN2 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN2_SHIFT          (7U)                                                /*!< LPC_ADC_INTEN: ADCMPINTEN2 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN2(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN2_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN2_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN3_MASK           (0x600U)                                            /*!< LPC_ADC_INTEN: ADCMPINTEN3 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN3_SHIFT          (9U)                                                /*!< LPC_ADC_INTEN: ADCMPINTEN3 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN3(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN3_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN3_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN4_MASK           (0x1800U)                                           /*!< LPC_ADC_INTEN: ADCMPINTEN4 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN4_SHIFT          (11U)                                               /*!< LPC_ADC_INTEN: ADCMPINTEN4 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN4(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN4_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN4_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN5_MASK           (0x6000U)                                           /*!< LPC_ADC_INTEN: ADCMPINTEN5 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN5_SHIFT          (13U)                                               /*!< LPC_ADC_INTEN: ADCMPINTEN5 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN5(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN5_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN5_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN6_MASK           (0x18000U)                                          /*!< LPC_ADC_INTEN: ADCMPINTEN6 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN6_SHIFT          (15U)                                               /*!< LPC_ADC_INTEN: ADCMPINTEN6 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN6(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN6_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN6_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN7_MASK           (0x60000U)                                          /*!< LPC_ADC_INTEN: ADCMPINTEN7 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN7_SHIFT          (17U)                                               /*!< LPC_ADC_INTEN: ADCMPINTEN7 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN7(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN7_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN7_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN8_MASK           (0x180000U)                                         /*!< LPC_ADC_INTEN: ADCMPINTEN8 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN8_SHIFT          (19U)                                               /*!< LPC_ADC_INTEN: ADCMPINTEN8 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN8(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN8_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN8_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN9_MASK           (0x600000U)                                         /*!< LPC_ADC_INTEN: ADCMPINTEN9 Mask         */
#define LPC_ADC_INTEN_ADCMPINTEN9_SHIFT          (21U)                                               /*!< LPC_ADC_INTEN: ADCMPINTEN9 Position     */
#define LPC_ADC_INTEN_ADCMPINTEN9(x)             (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN9_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN9_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN10_MASK          (0x1800000U)                                        /*!< LPC_ADC_INTEN: ADCMPINTEN10 Mask        */
#define LPC_ADC_INTEN_ADCMPINTEN10_SHIFT         (23U)                                               /*!< LPC_ADC_INTEN: ADCMPINTEN10 Position    */
#define LPC_ADC_INTEN_ADCMPINTEN10(x)            (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN10_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN10_MASK) /*!< LPC_ADC_INTEN                           */
#define LPC_ADC_INTEN_ADCMPINTEN11_MASK          (0x6000000U)                                        /*!< LPC_ADC_INTEN: ADCMPINTEN11 Mask        */
#define LPC_ADC_INTEN_ADCMPINTEN11_SHIFT         (25U)                                               /*!< LPC_ADC_INTEN: ADCMPINTEN11 Position    */
#define LPC_ADC_INTEN_ADCMPINTEN11(x)            (((uint32_t)(((uint32_t)(x))<<LPC_ADC_INTEN_ADCMPINTEN11_SHIFT))&LPC_ADC_INTEN_ADCMPINTEN11_MASK) /*!< LPC_ADC_INTEN                           */
/* ------- FLAGS Bit Fields                         ------ */
#define LPC_ADC_FLAGS_THCMP0_MASK                (0x1U)                                              /*!< LPC_ADC_FLAGS: THCMP0 Mask              */
#define LPC_ADC_FLAGS_THCMP0_SHIFT               (0U)                                                /*!< LPC_ADC_FLAGS: THCMP0 Position          */
#define LPC_ADC_FLAGS_THCMP0(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP0_SHIFT))&LPC_ADC_FLAGS_THCMP0_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP1_MASK                (0x2U)                                              /*!< LPC_ADC_FLAGS: THCMP1 Mask              */
#define LPC_ADC_FLAGS_THCMP1_SHIFT               (1U)                                                /*!< LPC_ADC_FLAGS: THCMP1 Position          */
#define LPC_ADC_FLAGS_THCMP1(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP1_SHIFT))&LPC_ADC_FLAGS_THCMP1_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP2_MASK                (0x4U)                                              /*!< LPC_ADC_FLAGS: THCMP2 Mask              */
#define LPC_ADC_FLAGS_THCMP2_SHIFT               (2U)                                                /*!< LPC_ADC_FLAGS: THCMP2 Position          */
#define LPC_ADC_FLAGS_THCMP2(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP2_SHIFT))&LPC_ADC_FLAGS_THCMP2_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP3_MASK                (0x8U)                                              /*!< LPC_ADC_FLAGS: THCMP3 Mask              */
#define LPC_ADC_FLAGS_THCMP3_SHIFT               (3U)                                                /*!< LPC_ADC_FLAGS: THCMP3 Position          */
#define LPC_ADC_FLAGS_THCMP3(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP3_SHIFT))&LPC_ADC_FLAGS_THCMP3_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP4_MASK                (0x10U)                                             /*!< LPC_ADC_FLAGS: THCMP4 Mask              */
#define LPC_ADC_FLAGS_THCMP4_SHIFT               (4U)                                                /*!< LPC_ADC_FLAGS: THCMP4 Position          */
#define LPC_ADC_FLAGS_THCMP4(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP4_SHIFT))&LPC_ADC_FLAGS_THCMP4_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP5_MASK                (0x20U)                                             /*!< LPC_ADC_FLAGS: THCMP5 Mask              */
#define LPC_ADC_FLAGS_THCMP5_SHIFT               (5U)                                                /*!< LPC_ADC_FLAGS: THCMP5 Position          */
#define LPC_ADC_FLAGS_THCMP5(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP5_SHIFT))&LPC_ADC_FLAGS_THCMP5_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP6_MASK                (0x40U)                                             /*!< LPC_ADC_FLAGS: THCMP6 Mask              */
#define LPC_ADC_FLAGS_THCMP6_SHIFT               (6U)                                                /*!< LPC_ADC_FLAGS: THCMP6 Position          */
#define LPC_ADC_FLAGS_THCMP6(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP6_SHIFT))&LPC_ADC_FLAGS_THCMP6_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP7_MASK                (0x80U)                                             /*!< LPC_ADC_FLAGS: THCMP7 Mask              */
#define LPC_ADC_FLAGS_THCMP7_SHIFT               (7U)                                                /*!< LPC_ADC_FLAGS: THCMP7 Position          */
#define LPC_ADC_FLAGS_THCMP7(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP7_SHIFT))&LPC_ADC_FLAGS_THCMP7_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP8_MASK                (0x100U)                                            /*!< LPC_ADC_FLAGS: THCMP8 Mask              */
#define LPC_ADC_FLAGS_THCMP8_SHIFT               (8U)                                                /*!< LPC_ADC_FLAGS: THCMP8 Position          */
#define LPC_ADC_FLAGS_THCMP8(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP8_SHIFT))&LPC_ADC_FLAGS_THCMP8_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP9_MASK                (0x200U)                                            /*!< LPC_ADC_FLAGS: THCMP9 Mask              */
#define LPC_ADC_FLAGS_THCMP9_SHIFT               (9U)                                                /*!< LPC_ADC_FLAGS: THCMP9 Position          */
#define LPC_ADC_FLAGS_THCMP9(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP9_SHIFT))&LPC_ADC_FLAGS_THCMP9_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP10_MASK               (0x400U)                                            /*!< LPC_ADC_FLAGS: THCMP10 Mask             */
#define LPC_ADC_FLAGS_THCMP10_SHIFT              (10U)                                               /*!< LPC_ADC_FLAGS: THCMP10 Position         */
#define LPC_ADC_FLAGS_THCMP10(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP10_SHIFT))&LPC_ADC_FLAGS_THCMP10_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP11_MASK               (0x800U)                                            /*!< LPC_ADC_FLAGS: THCMP11 Mask             */
#define LPC_ADC_FLAGS_THCMP11_SHIFT              (11U)                                               /*!< LPC_ADC_FLAGS: THCMP11 Position         */
#define LPC_ADC_FLAGS_THCMP11(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP11_SHIFT))&LPC_ADC_FLAGS_THCMP11_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN0_MASK              (0x1000U)                                           /*!< LPC_ADC_FLAGS: OVERRUN0 Mask            */
#define LPC_ADC_FLAGS_OVERRUN0_SHIFT             (12U)                                               /*!< LPC_ADC_FLAGS: OVERRUN0 Position        */
#define LPC_ADC_FLAGS_OVERRUN0(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN0_SHIFT))&LPC_ADC_FLAGS_OVERRUN0_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN1_MASK              (0x2000U)                                           /*!< LPC_ADC_FLAGS: OVERRUN1 Mask            */
#define LPC_ADC_FLAGS_OVERRUN1_SHIFT             (13U)                                               /*!< LPC_ADC_FLAGS: OVERRUN1 Position        */
#define LPC_ADC_FLAGS_OVERRUN1(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN1_SHIFT))&LPC_ADC_FLAGS_OVERRUN1_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN2_MASK              (0x4000U)                                           /*!< LPC_ADC_FLAGS: OVERRUN2 Mask            */
#define LPC_ADC_FLAGS_OVERRUN2_SHIFT             (14U)                                               /*!< LPC_ADC_FLAGS: OVERRUN2 Position        */
#define LPC_ADC_FLAGS_OVERRUN2(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN2_SHIFT))&LPC_ADC_FLAGS_OVERRUN2_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN3_MASK              (0x8000U)                                           /*!< LPC_ADC_FLAGS: OVERRUN3 Mask            */
#define LPC_ADC_FLAGS_OVERRUN3_SHIFT             (15U)                                               /*!< LPC_ADC_FLAGS: OVERRUN3 Position        */
#define LPC_ADC_FLAGS_OVERRUN3(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN3_SHIFT))&LPC_ADC_FLAGS_OVERRUN3_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN4_MASK              (0x10000U)                                          /*!< LPC_ADC_FLAGS: OVERRUN4 Mask            */
#define LPC_ADC_FLAGS_OVERRUN4_SHIFT             (16U)                                               /*!< LPC_ADC_FLAGS: OVERRUN4 Position        */
#define LPC_ADC_FLAGS_OVERRUN4(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN4_SHIFT))&LPC_ADC_FLAGS_OVERRUN4_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN5_MASK              (0x20000U)                                          /*!< LPC_ADC_FLAGS: OVERRUN5 Mask            */
#define LPC_ADC_FLAGS_OVERRUN5_SHIFT             (17U)                                               /*!< LPC_ADC_FLAGS: OVERRUN5 Position        */
#define LPC_ADC_FLAGS_OVERRUN5(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN5_SHIFT))&LPC_ADC_FLAGS_OVERRUN5_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN6_MASK              (0x40000U)                                          /*!< LPC_ADC_FLAGS: OVERRUN6 Mask            */
#define LPC_ADC_FLAGS_OVERRUN6_SHIFT             (18U)                                               /*!< LPC_ADC_FLAGS: OVERRUN6 Position        */
#define LPC_ADC_FLAGS_OVERRUN6(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN6_SHIFT))&LPC_ADC_FLAGS_OVERRUN6_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN7_MASK              (0x80000U)                                          /*!< LPC_ADC_FLAGS: OVERRUN7 Mask            */
#define LPC_ADC_FLAGS_OVERRUN7_SHIFT             (19U)                                               /*!< LPC_ADC_FLAGS: OVERRUN7 Position        */
#define LPC_ADC_FLAGS_OVERRUN7(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN7_SHIFT))&LPC_ADC_FLAGS_OVERRUN7_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN8_MASK              (0x100000U)                                         /*!< LPC_ADC_FLAGS: OVERRUN8 Mask            */
#define LPC_ADC_FLAGS_OVERRUN8_SHIFT             (20U)                                               /*!< LPC_ADC_FLAGS: OVERRUN8 Position        */
#define LPC_ADC_FLAGS_OVERRUN8(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN8_SHIFT))&LPC_ADC_FLAGS_OVERRUN8_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN9_MASK              (0x200000U)                                         /*!< LPC_ADC_FLAGS: OVERRUN9 Mask            */
#define LPC_ADC_FLAGS_OVERRUN9_SHIFT             (21U)                                               /*!< LPC_ADC_FLAGS: OVERRUN9 Position        */
#define LPC_ADC_FLAGS_OVERRUN9(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN9_SHIFT))&LPC_ADC_FLAGS_OVERRUN9_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN10_MASK             (0x400000U)                                         /*!< LPC_ADC_FLAGS: OVERRUN10 Mask           */
#define LPC_ADC_FLAGS_OVERRUN10_SHIFT            (22U)                                               /*!< LPC_ADC_FLAGS: OVERRUN10 Position       */
#define LPC_ADC_FLAGS_OVERRUN10(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN10_SHIFT))&LPC_ADC_FLAGS_OVERRUN10_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVERRUN11_MASK             (0x800000U)                                         /*!< LPC_ADC_FLAGS: OVERRUN11 Mask           */
#define LPC_ADC_FLAGS_OVERRUN11_SHIFT            (23U)                                               /*!< LPC_ADC_FLAGS: OVERRUN11 Position       */
#define LPC_ADC_FLAGS_OVERRUN11(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVERRUN11_SHIFT))&LPC_ADC_FLAGS_OVERRUN11_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_SEQA_OVR_MASK              (0x1000000U)                                        /*!< LPC_ADC_FLAGS: SEQA_OVR Mask            */
#define LPC_ADC_FLAGS_SEQA_OVR_SHIFT             (24U)                                               /*!< LPC_ADC_FLAGS: SEQA_OVR Position        */
#define LPC_ADC_FLAGS_SEQA_OVR(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_SEQA_OVR_SHIFT))&LPC_ADC_FLAGS_SEQA_OVR_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_SEQB_OVR_MASK              (0x2000000U)                                        /*!< LPC_ADC_FLAGS: SEQB_OVR Mask            */
#define LPC_ADC_FLAGS_SEQB_OVR_SHIFT             (25U)                                               /*!< LPC_ADC_FLAGS: SEQB_OVR Position        */
#define LPC_ADC_FLAGS_SEQB_OVR(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_SEQB_OVR_SHIFT))&LPC_ADC_FLAGS_SEQB_OVR_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_SEQA_INT_MASK              (0x10000000U)                                       /*!< LPC_ADC_FLAGS: SEQA_INT Mask            */
#define LPC_ADC_FLAGS_SEQA_INT_SHIFT             (28U)                                               /*!< LPC_ADC_FLAGS: SEQA_INT Position        */
#define LPC_ADC_FLAGS_SEQA_INT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_SEQA_INT_SHIFT))&LPC_ADC_FLAGS_SEQA_INT_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_SEQB_INT_MASK              (0x20000000U)                                       /*!< LPC_ADC_FLAGS: SEQB_INT Mask            */
#define LPC_ADC_FLAGS_SEQB_INT_SHIFT             (29U)                                               /*!< LPC_ADC_FLAGS: SEQB_INT Position        */
#define LPC_ADC_FLAGS_SEQB_INT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_SEQB_INT_SHIFT))&LPC_ADC_FLAGS_SEQB_INT_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_THCMP_INT_MASK             (0x40000000U)                                       /*!< LPC_ADC_FLAGS: THCMP_INT Mask           */
#define LPC_ADC_FLAGS_THCMP_INT_SHIFT            (30U)                                               /*!< LPC_ADC_FLAGS: THCMP_INT Position       */
#define LPC_ADC_FLAGS_THCMP_INT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_THCMP_INT_SHIFT))&LPC_ADC_FLAGS_THCMP_INT_MASK) /*!< LPC_ADC_FLAGS                           */
#define LPC_ADC_FLAGS_OVR_INT_MASK               (0x80000000U)                                       /*!< LPC_ADC_FLAGS: OVR_INT Mask             */
#define LPC_ADC_FLAGS_OVR_INT_SHIFT              (31U)                                               /*!< LPC_ADC_FLAGS: OVR_INT Position         */
#define LPC_ADC_FLAGS_OVR_INT(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_ADC_FLAGS_OVR_INT_SHIFT))&LPC_ADC_FLAGS_OVR_INT_MASK) /*!< LPC_ADC_FLAGS                           */
/* ------- TRM Bit Fields                           ------ */
#define LPC_ADC_TRM_VRANGE_MASK                  (0x20U)                                             /*!< LPC_ADC_TRM: VRANGE Mask                */
#define LPC_ADC_TRM_VRANGE_SHIFT                 (5U)                                                /*!< LPC_ADC_TRM: VRANGE Position            */
#define LPC_ADC_TRM_VRANGE(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_ADC_TRM_VRANGE_SHIFT))&LPC_ADC_TRM_VRANGE_MASK) /*!< LPC_ADC_TRM                             */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* LPC_ADC - Peripheral instance base addresses */
#define LPC_ADC_BasePtr                0x4001C000UL //!< Peripheral base address
#define LPC_ADC                        ((LPC_ADC_Type *) LPC_ADC_BasePtr) //!< Freescale base pointer
#define LPC_ADC_BASE_PTR               (LPC_ADC) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           LPC_CMP (file:CMP_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief Analog comparator
 */
/**
* @addtogroup CMP_structs_GROUP CMP struct
* @brief Struct for CMP
* @{
*/
typedef struct {                                /*       LPC_CMP Structure                                            */
   __IO uint32_t  CTRL;                         /**< 0000: Comparator control register                                  */
   __IO uint32_t  LAD;                          /**< 0004: Voltage ladder register                                      */
} LPC_CMP_Type;

/**
 * @} */ /* End group CMP_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_CMP' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMP_Register_Masks_GROUP CMP Register Masks
* @brief Register Masks for CMP
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define LPC_CMP_CTRL_EDGESEL_MASK                (0x18U)                                             /*!< LPC_CMP_CTRL: EDGESEL Mask              */
#define LPC_CMP_CTRL_EDGESEL_SHIFT               (3U)                                                /*!< LPC_CMP_CTRL: EDGESEL Position          */
#define LPC_CMP_CTRL_EDGESEL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CMP_CTRL_EDGESEL_SHIFT))&LPC_CMP_CTRL_EDGESEL_MASK) /*!< LPC_CMP_CTRL                            */
#define LPC_CMP_CTRL_COMPSA_MASK                 (0x40U)                                             /*!< LPC_CMP_CTRL: COMPSA Mask               */
#define LPC_CMP_CTRL_COMPSA_SHIFT                (6U)                                                /*!< LPC_CMP_CTRL: COMPSA Position           */
#define LPC_CMP_CTRL_COMPSA(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CMP_CTRL_COMPSA_SHIFT))&LPC_CMP_CTRL_COMPSA_MASK) /*!< LPC_CMP_CTRL                            */
#define LPC_CMP_CTRL_COMP_VP_SEL_MASK            (0x700U)                                            /*!< LPC_CMP_CTRL: COMP_VP_SEL Mask          */
#define LPC_CMP_CTRL_COMP_VP_SEL_SHIFT           (8U)                                                /*!< LPC_CMP_CTRL: COMP_VP_SEL Position      */
#define LPC_CMP_CTRL_COMP_VP_SEL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_CMP_CTRL_COMP_VP_SEL_SHIFT))&LPC_CMP_CTRL_COMP_VP_SEL_MASK) /*!< LPC_CMP_CTRL                            */
#define LPC_CMP_CTRL_COMP_VM_SEL_MASK            (0x3800U)                                           /*!< LPC_CMP_CTRL: COMP_VM_SEL Mask          */
#define LPC_CMP_CTRL_COMP_VM_SEL_SHIFT           (11U)                                               /*!< LPC_CMP_CTRL: COMP_VM_SEL Position      */
#define LPC_CMP_CTRL_COMP_VM_SEL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_CMP_CTRL_COMP_VM_SEL_SHIFT))&LPC_CMP_CTRL_COMP_VM_SEL_MASK) /*!< LPC_CMP_CTRL                            */
#define LPC_CMP_CTRL_EDGECLR_MASK                (0x100000U)                                         /*!< LPC_CMP_CTRL: EDGECLR Mask              */
#define LPC_CMP_CTRL_EDGECLR_SHIFT               (20U)                                               /*!< LPC_CMP_CTRL: EDGECLR Position          */
#define LPC_CMP_CTRL_EDGECLR(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CMP_CTRL_EDGECLR_SHIFT))&LPC_CMP_CTRL_EDGECLR_MASK) /*!< LPC_CMP_CTRL                            */
#define LPC_CMP_CTRL_COMPSTAT_MASK               (0x200000U)                                         /*!< LPC_CMP_CTRL: COMPSTAT Mask             */
#define LPC_CMP_CTRL_COMPSTAT_SHIFT              (21U)                                               /*!< LPC_CMP_CTRL: COMPSTAT Position         */
#define LPC_CMP_CTRL_COMPSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CMP_CTRL_COMPSTAT_SHIFT))&LPC_CMP_CTRL_COMPSTAT_MASK) /*!< LPC_CMP_CTRL                            */
#define LPC_CMP_CTRL_COMPEDGE_MASK               (0x800000U)                                         /*!< LPC_CMP_CTRL: COMPEDGE Mask             */
#define LPC_CMP_CTRL_COMPEDGE_SHIFT              (23U)                                               /*!< LPC_CMP_CTRL: COMPEDGE Position         */
#define LPC_CMP_CTRL_COMPEDGE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CMP_CTRL_COMPEDGE_SHIFT))&LPC_CMP_CTRL_COMPEDGE_MASK) /*!< LPC_CMP_CTRL                            */
#define LPC_CMP_CTRL_HYS_MASK                    (0x6000000U)                                        /*!< LPC_CMP_CTRL: HYS Mask                  */
#define LPC_CMP_CTRL_HYS_SHIFT                   (25U)                                               /*!< LPC_CMP_CTRL: HYS Position              */
#define LPC_CMP_CTRL_HYS(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_CMP_CTRL_HYS_SHIFT))&LPC_CMP_CTRL_HYS_MASK) /*!< LPC_CMP_CTRL                            */
/* ------- LAD Bit Fields                           ------ */
#define LPC_CMP_LAD_LADEN_MASK                   (0x1U)                                              /*!< LPC_CMP_LAD: LADEN Mask                 */
#define LPC_CMP_LAD_LADEN_SHIFT                  (0U)                                                /*!< LPC_CMP_LAD: LADEN Position             */
#define LPC_CMP_LAD_LADEN(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_CMP_LAD_LADEN_SHIFT))&LPC_CMP_LAD_LADEN_MASK) /*!< LPC_CMP_LAD                             */
#define LPC_CMP_LAD_LADSEL_MASK                  (0x3EU)                                             /*!< LPC_CMP_LAD: LADSEL Mask                */
#define LPC_CMP_LAD_LADSEL_SHIFT                 (1U)                                                /*!< LPC_CMP_LAD: LADSEL Position            */
#define LPC_CMP_LAD_LADSEL(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CMP_LAD_LADSEL_SHIFT))&LPC_CMP_LAD_LADSEL_MASK) /*!< LPC_CMP_LAD                             */
#define LPC_CMP_LAD_LADREF_MASK                  (0x40U)                                             /*!< LPC_CMP_LAD: LADREF Mask                */
#define LPC_CMP_LAD_LADREF_SHIFT                 (6U)                                                /*!< LPC_CMP_LAD: LADREF Position            */
#define LPC_CMP_LAD_LADREF(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_CMP_LAD_LADREF_SHIFT))&LPC_CMP_LAD_LADREF_MASK) /*!< LPC_CMP_LAD                             */
/**
 * @} */ /* End group CMP_Register_Masks_GROUP 
 */

/* LPC_CMP - Peripheral instance base addresses */
#define LPC_CMP_BasePtr                0x40024000UL //!< Peripheral base address
#define LPC_CMP                        ((LPC_CMP_Type *) LPC_CMP_BasePtr) //!< Freescale base pointer
#define LPC_CMP_BASE_PTR               (LPC_CMP) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer
* @brief C Struct for CRC
* @{
*/

/* ================================================================================ */
/* ================           LPC_CRC (file:CRC_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check (CRC) engine
 */
/**
* @addtogroup CRC_structs_GROUP CRC struct
* @brief Struct for CRC
* @{
*/
typedef struct {                                /*       LPC_CRC Structure                                            */
   __IO uint32_t  MODE;                         /**< 0000: CRC mode register                                            */
   __IO uint32_t  SEED;                         /**< 0004: CRC seed register                                            */
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  SUM;                       /**< 0008: CRC checksum register                                        */
      __O  uint32_t  WR_DATA;                   /**< 0008: CRC data register                                            */
   };
} LPC_CRC_Type;

/**
 * @} */ /* End group CRC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_CRC' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CRC_Register_Masks_GROUP CRC Register Masks
* @brief Register Masks for CRC
* @{
*/
/* ------- MODE Bit Fields                          ------ */
#define LPC_CRC_MODE_CRC_POLY_MASK               (0x3U)                                              /*!< LPC_CRC_MODE: CRC_POLY Mask             */
#define LPC_CRC_MODE_CRC_POLY_SHIFT              (0U)                                                /*!< LPC_CRC_MODE: CRC_POLY Position         */
#define LPC_CRC_MODE_CRC_POLY(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CRC_MODE_CRC_POLY_SHIFT))&LPC_CRC_MODE_CRC_POLY_MASK) /*!< LPC_CRC_MODE                            */
#define LPC_CRC_MODE_BIT_RVS_WR_MASK             (0x4U)                                              /*!< LPC_CRC_MODE: BIT_RVS_WR Mask           */
#define LPC_CRC_MODE_BIT_RVS_WR_SHIFT            (2U)                                                /*!< LPC_CRC_MODE: BIT_RVS_WR Position       */
#define LPC_CRC_MODE_BIT_RVS_WR(x)               (((uint32_t)(((uint32_t)(x))<<LPC_CRC_MODE_BIT_RVS_WR_SHIFT))&LPC_CRC_MODE_BIT_RVS_WR_MASK) /*!< LPC_CRC_MODE                            */
#define LPC_CRC_MODE_CMPL_WR_MASK                (0x8U)                                              /*!< LPC_CRC_MODE: CMPL_WR Mask              */
#define LPC_CRC_MODE_CMPL_WR_SHIFT               (3U)                                                /*!< LPC_CRC_MODE: CMPL_WR Position          */
#define LPC_CRC_MODE_CMPL_WR(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_CRC_MODE_CMPL_WR_SHIFT))&LPC_CRC_MODE_CMPL_WR_MASK) /*!< LPC_CRC_MODE                            */
#define LPC_CRC_MODE_BIT_RVS_SUM_MASK            (0x10U)                                             /*!< LPC_CRC_MODE: BIT_RVS_SUM Mask          */
#define LPC_CRC_MODE_BIT_RVS_SUM_SHIFT           (4U)                                                /*!< LPC_CRC_MODE: BIT_RVS_SUM Position      */
#define LPC_CRC_MODE_BIT_RVS_SUM(x)              (((uint32_t)(((uint32_t)(x))<<LPC_CRC_MODE_BIT_RVS_SUM_SHIFT))&LPC_CRC_MODE_BIT_RVS_SUM_MASK) /*!< LPC_CRC_MODE                            */
#define LPC_CRC_MODE_CMPL_SUM_MASK               (0x20U)                                             /*!< LPC_CRC_MODE: CMPL_SUM Mask             */
#define LPC_CRC_MODE_CMPL_SUM_SHIFT              (5U)                                                /*!< LPC_CRC_MODE: CMPL_SUM Position         */
#define LPC_CRC_MODE_CMPL_SUM(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CRC_MODE_CMPL_SUM_SHIFT))&LPC_CRC_MODE_CMPL_SUM_MASK) /*!< LPC_CRC_MODE                            */
#define LPC_CRC_MODE_Reserved_MASK               (0xFFFFFFC0U)                                       /*!< LPC_CRC_MODE: Reserved Mask             */
#define LPC_CRC_MODE_Reserved_SHIFT              (6U)                                                /*!< LPC_CRC_MODE: Reserved Position         */
#define LPC_CRC_MODE_Reserved(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CRC_MODE_Reserved_SHIFT))&LPC_CRC_MODE_Reserved_MASK) /*!< LPC_CRC_MODE                            */
/* ------- SEED Bit Fields                          ------ */
#define LPC_CRC_SEED_CRC_SEED_MASK               (0xFFFFFFFFU)                                       /*!< LPC_CRC_SEED: CRC_SEED Mask             */
#define LPC_CRC_SEED_CRC_SEED_SHIFT              (0U)                                                /*!< LPC_CRC_SEED: CRC_SEED Position         */
#define LPC_CRC_SEED_CRC_SEED(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_CRC_SEED_CRC_SEED_SHIFT))&LPC_CRC_SEED_CRC_SEED_MASK) /*!< LPC_CRC_SEED                            */
/* ------- SUM Bit Fields                           ------ */
#define LPC_CRC_SUM_CRC_SUM_MASK                 (0xFFFFFFFFU)                                       /*!< LPC_CRC_SUM: CRC_SUM Mask               */
#define LPC_CRC_SUM_CRC_SUM_SHIFT                (0U)                                                /*!< LPC_CRC_SUM: CRC_SUM Position           */
#define LPC_CRC_SUM_CRC_SUM(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_CRC_SUM_CRC_SUM_SHIFT))&LPC_CRC_SUM_CRC_SUM_MASK) /*!< LPC_CRC_SUM                             */
/* ------- WR_DATA Bit Fields                       ------ */
#define LPC_CRC_WR_DATA_CRC_WR_DATA_MASK         (0xFFFFFFFFU)                                       /*!< LPC_CRC_WR_DATA: CRC_WR_DATA Mask       */
#define LPC_CRC_WR_DATA_CRC_WR_DATA_SHIFT        (0U)                                                /*!< LPC_CRC_WR_DATA: CRC_WR_DATA Position   */
#define LPC_CRC_WR_DATA_CRC_WR_DATA(x)           (((uint32_t)(((uint32_t)(x))<<LPC_CRC_WR_DATA_CRC_WR_DATA_SHIFT))&LPC_CRC_WR_DATA_CRC_WR_DATA_MASK) /*!< LPC_CRC_WR_DATA                         */
/**
 * @} */ /* End group CRC_Register_Masks_GROUP 
 */

/* LPC_CRC - Peripheral instance base addresses */
#define LPC_CRC_BasePtr                0x50000000UL //!< Peripheral base address
#define LPC_CRC                        ((LPC_CRC_Type *) LPC_CRC_BasePtr) //!< Freescale base pointer
#define LPC_CRC_BASE_PTR               (LPC_CRC) //!< Freescale style base pointer
/**
 * @} */ /* End group CRC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA_Peripheral_access_layer_GROUP DMA Peripheral Access Layer
* @brief C Struct for DMA
* @{
*/

/* ================================================================================ */
/* ================           LPC_DMA (file:DMA_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief DMA controller
 */
/**
* @addtogroup DMA_structs_GROUP DMA struct
* @brief Struct for DMA
* @{
*/
typedef struct {                                /*       LPC_DMA Structure                                            */
   __IO uint32_t  CTRL;                         /**< 0000: DMA control                                                  */
   __I  uint32_t  INTSTAT;                      /**< 0004: Interrupt status                                             */
   __IO uint32_t  SRAMBASE;                     /**< 0008: SRAM address of the channel configuration table              */
        uint8_t   RESERVED_0[20];              
   __IO uint32_t  ENABLESET0;                   /**< 0020: Channel Enable read and Set for all DMA channels             */
        uint8_t   RESERVED_1[4];               
   __O  uint32_t  ENABLECLR0;                   /**< 0028: Channel Enable Clear for all DMA channels                    */
        uint8_t   RESERVED_2[4];               
   __I  uint32_t  ACTIVE0;                      /**< 0030: Channel Active status for all DMA channels                   */
        uint8_t   RESERVED_3[4];               
   __I  uint32_t  BUSY0;                        /**< 0038: Channel Busy status for all DMA channels                     */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  ERRINT0;                      /**< 0040: Error Interrupt status for all DMA channels                  */
        uint8_t   RESERVED_5[4];               
   __IO uint32_t  INTENSET0;                    /**< 0048: Interrupt Enable read and Set for all DMA channels           */
        uint8_t   RESERVED_6[4];               
   __O  uint32_t  INTENCLR0;                    /**< 0050: Interrupt Enable Clear for all DMA channels                  */
        uint8_t   RESERVED_7[4];               
   __IO uint32_t  INTA0;                        /**< 0058: Interrupt A status for all DMA channels                      */
        uint8_t   RESERVED_8[4];               
   __IO uint32_t  INTB0;                        /**< 0060: Interrupt B status for all DMA channels                      */
        uint8_t   RESERVED_9[4];               
   __O  uint32_t  SETVALID0;                    /**< 0068: Set ValidPending control bits for all DMA channels           */
        uint8_t   RESERVED_10[4];              
   __O  uint32_t  SETTRIG0;                     /**< 0070: Set Trigger control bits for all DMA channels                */
        uint8_t   RESERVED_11[4];              
   __O  uint32_t  ABORT0;                       /**< 0078: Channel Abort control for all DMA channels                   */
        uint8_t   RESERVED_12[900];            
   __IO uint32_t  CFG0;                         /**< 0400: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT0;                     /**< 0404: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG0;                     /**< 0408: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_13[4];              
   __IO uint32_t  CFG1;                         /**< 0410: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT1;                     /**< 0414: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG1;                     /**< 0418: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_14[4];              
   __IO uint32_t  CFG2;                         /**< 0420: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT2;                     /**< 0424: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG2;                     /**< 0428: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_15[4];              
   __IO uint32_t  CFG3;                         /**< 0430: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT3;                     /**< 0434: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG3;                     /**< 0438: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_16[4];              
   __IO uint32_t  CFG4;                         /**< 0440: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT4;                     /**< 0444: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG4;                     /**< 0448: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_17[4];              
   __IO uint32_t  CFG5;                         /**< 0450: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT5;                     /**< 0454: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG5;                     /**< 0458: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_18[4];              
   __IO uint32_t  CFG6;                         /**< 0460: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT6;                     /**< 0464: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG6;                     /**< 0468: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_19[4];              
   __IO uint32_t  CFG7;                         /**< 0470: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT7;                     /**< 0474: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG7;                     /**< 0478: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_20[4];              
   __IO uint32_t  CFG8;                         /**< 0480: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT8;                     /**< 0484: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG8;                     /**< 0488: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_21[4];              
   __IO uint32_t  CFG9;                         /**< 0490: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT9;                     /**< 0494: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG9;                     /**< 0498: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_22[4];              
   __IO uint32_t  CFG10;                        /**< 04A0: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT10;                    /**< 04A4: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG10;                    /**< 04A8: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_23[4];              
   __IO uint32_t  CFG11;                        /**< 04B0: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT11;                    /**< 04B4: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG11;                    /**< 04B8: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_24[4];              
   __IO uint32_t  CFG12;                        /**< 04C0: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT12;                    /**< 04C4: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG12;                    /**< 04C8: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_25[4];              
   __IO uint32_t  CFG13;                        /**< 04D0: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT13;                    /**< 04D4: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG13;                    /**< 04D8: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_26[4];              
   __IO uint32_t  CFG14;                        /**< 04E0: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT14;                    /**< 04E4: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG14;                    /**< 04E8: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_27[4];              
   __IO uint32_t  CFG15;                        /**< 04F0: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT15;                    /**< 04F4: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG15;                    /**< 04F8: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_28[4];              
   __IO uint32_t  CFG16;                        /**< 0500: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT16;                    /**< 0504: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG16;                    /**< 0508: Transfer configuration register for DMA channel 0            */
        uint8_t   RESERVED_29[4];              
   __IO uint32_t  CFG17;                        /**< 0510: Configuration register for DMA channel 0                     */
   __I  uint32_t  CTLSTAT17;                    /**< 0514: Control and status register for DMA channel 0                */
   __IO uint32_t  XFERCFG17;                    /**< 0518: Transfer configuration register for DMA channel 0            */
} LPC_DMA_Type;

/**
 * @} */ /* End group DMA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_DMA' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA_Register_Masks_GROUP DMA Register Masks
* @brief Register Masks for DMA
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define LPC_DMA_CTRL_ENABLE_MASK                 (0x1U)                                              /*!< LPC_DMA_CTRL: ENABLE Mask               */
#define LPC_DMA_CTRL_ENABLE_SHIFT                (0U)                                                /*!< LPC_DMA_CTRL: ENABLE Position           */
#define LPC_DMA_CTRL_ENABLE(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTRL_ENABLE_SHIFT))&LPC_DMA_CTRL_ENABLE_MASK) /*!< LPC_DMA_CTRL                            */
/* ------- INTSTAT Bit Fields                       ------ */
#define LPC_DMA_INTSTAT_ACTIVEINT_MASK           (0x2U)                                              /*!< LPC_DMA_INTSTAT: ACTIVEINT Mask         */
#define LPC_DMA_INTSTAT_ACTIVEINT_SHIFT          (1U)                                                /*!< LPC_DMA_INTSTAT: ACTIVEINT Position     */
#define LPC_DMA_INTSTAT_ACTIVEINT(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_INTSTAT_ACTIVEINT_SHIFT))&LPC_DMA_INTSTAT_ACTIVEINT_MASK) /*!< LPC_DMA_INTSTAT                         */
#define LPC_DMA_INTSTAT_ACTIVEERRINT_MASK        (0x4U)                                              /*!< LPC_DMA_INTSTAT: ACTIVEERRINT Mask      */
#define LPC_DMA_INTSTAT_ACTIVEERRINT_SHIFT       (2U)                                                /*!< LPC_DMA_INTSTAT: ACTIVEERRINT Position  */
#define LPC_DMA_INTSTAT_ACTIVEERRINT(x)          (((uint32_t)(((uint32_t)(x))<<LPC_DMA_INTSTAT_ACTIVEERRINT_SHIFT))&LPC_DMA_INTSTAT_ACTIVEERRINT_MASK) /*!< LPC_DMA_INTSTAT                         */
/* ------- SRAMBASE Bit Fields                      ------ */
#define LPC_DMA_SRAMBASE_OFFSET_MASK             (0xFFFFFE00U)                                       /*!< LPC_DMA_SRAMBASE: OFFSET Mask           */
#define LPC_DMA_SRAMBASE_OFFSET_SHIFT            (9U)                                                /*!< LPC_DMA_SRAMBASE: OFFSET Position       */
#define LPC_DMA_SRAMBASE_OFFSET(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_SRAMBASE_OFFSET_SHIFT))&LPC_DMA_SRAMBASE_OFFSET_MASK) /*!< LPC_DMA_SRAMBASE                        */
/* ------- ENABLESET0 Bit Fields                    ------ */
#define LPC_DMA_ENABLESET0_ENA_MASK              (0x3FFFFU)                                          /*!< LPC_DMA_ENABLESET0: ENA Mask            */
#define LPC_DMA_ENABLESET0_ENA_SHIFT             (0U)                                                /*!< LPC_DMA_ENABLESET0: ENA Position        */
#define LPC_DMA_ENABLESET0_ENA(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_ENABLESET0_ENA_SHIFT))&LPC_DMA_ENABLESET0_ENA_MASK) /*!< LPC_DMA_ENABLESET0                      */
/* ------- ENABLECLR0 Bit Fields                    ------ */
#define LPC_DMA_ENABLECLR0_CLR_MASK              (0x3FFFFU)                                          /*!< LPC_DMA_ENABLECLR0: CLR Mask            */
#define LPC_DMA_ENABLECLR0_CLR_SHIFT             (0U)                                                /*!< LPC_DMA_ENABLECLR0: CLR Position        */
#define LPC_DMA_ENABLECLR0_CLR(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_ENABLECLR0_CLR_SHIFT))&LPC_DMA_ENABLECLR0_CLR_MASK) /*!< LPC_DMA_ENABLECLR0                      */
/* ------- ACTIVE0 Bit Fields                       ------ */
#define LPC_DMA_ACTIVE0_ACT_MASK                 (0x3FFFFU)                                          /*!< LPC_DMA_ACTIVE0: ACT Mask               */
#define LPC_DMA_ACTIVE0_ACT_SHIFT                (0U)                                                /*!< LPC_DMA_ACTIVE0: ACT Position           */
#define LPC_DMA_ACTIVE0_ACT(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_DMA_ACTIVE0_ACT_SHIFT))&LPC_DMA_ACTIVE0_ACT_MASK) /*!< LPC_DMA_ACTIVE0                         */
/* ------- BUSY0 Bit Fields                         ------ */
#define LPC_DMA_BUSY0_BSY_MASK                   (0x3FFFFU)                                          /*!< LPC_DMA_BUSY0: BSY Mask                 */
#define LPC_DMA_BUSY0_BSY_SHIFT                  (0U)                                                /*!< LPC_DMA_BUSY0: BSY Position             */
#define LPC_DMA_BUSY0_BSY(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_DMA_BUSY0_BSY_SHIFT))&LPC_DMA_BUSY0_BSY_MASK) /*!< LPC_DMA_BUSY0                           */
/* ------- ERRINT0 Bit Fields                       ------ */
#define LPC_DMA_ERRINT0_ERR_MASK                 (0x3FFFFU)                                          /*!< LPC_DMA_ERRINT0: ERR Mask               */
#define LPC_DMA_ERRINT0_ERR_SHIFT                (0U)                                                /*!< LPC_DMA_ERRINT0: ERR Position           */
#define LPC_DMA_ERRINT0_ERR(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_DMA_ERRINT0_ERR_SHIFT))&LPC_DMA_ERRINT0_ERR_MASK) /*!< LPC_DMA_ERRINT0                         */
/* ------- INTENSET0 Bit Fields                     ------ */
#define LPC_DMA_INTENSET0_INTEN_MASK             (0x3FFFFU)                                          /*!< LPC_DMA_INTENSET0: INTEN Mask           */
#define LPC_DMA_INTENSET0_INTEN_SHIFT            (0U)                                                /*!< LPC_DMA_INTENSET0: INTEN Position       */
#define LPC_DMA_INTENSET0_INTEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_INTENSET0_INTEN_SHIFT))&LPC_DMA_INTENSET0_INTEN_MASK) /*!< LPC_DMA_INTENSET0                       */
/* ------- INTENCLR0 Bit Fields                     ------ */
#define LPC_DMA_INTENCLR0_CLR_MASK               (0x3FFFFU)                                          /*!< LPC_DMA_INTENCLR0: CLR Mask             */
#define LPC_DMA_INTENCLR0_CLR_SHIFT              (0U)                                                /*!< LPC_DMA_INTENCLR0: CLR Position         */
#define LPC_DMA_INTENCLR0_CLR(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_INTENCLR0_CLR_SHIFT))&LPC_DMA_INTENCLR0_CLR_MASK) /*!< LPC_DMA_INTENCLR0                       */
/* ------- INTA0 Bit Fields                         ------ */
#define LPC_DMA_INTA0_IA_MASK                    (0x3FFFFU)                                          /*!< LPC_DMA_INTA0: IA Mask                  */
#define LPC_DMA_INTA0_IA_SHIFT                   (0U)                                                /*!< LPC_DMA_INTA0: IA Position              */
#define LPC_DMA_INTA0_IA(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_DMA_INTA0_IA_SHIFT))&LPC_DMA_INTA0_IA_MASK) /*!< LPC_DMA_INTA0                           */
/* ------- INTB0 Bit Fields                         ------ */
#define LPC_DMA_INTB0_IB_MASK                    (0x3FFFFU)                                          /*!< LPC_DMA_INTB0: IB Mask                  */
#define LPC_DMA_INTB0_IB_SHIFT                   (0U)                                                /*!< LPC_DMA_INTB0: IB Position              */
#define LPC_DMA_INTB0_IB(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_DMA_INTB0_IB_SHIFT))&LPC_DMA_INTB0_IB_MASK) /*!< LPC_DMA_INTB0                           */
/* ------- SETVALID0 Bit Fields                     ------ */
#define LPC_DMA_SETVALID0_SV_MASK                (0x3FFFFU)                                          /*!< LPC_DMA_SETVALID0: SV Mask              */
#define LPC_DMA_SETVALID0_SV_SHIFT               (0U)                                                /*!< LPC_DMA_SETVALID0: SV Position          */
#define LPC_DMA_SETVALID0_SV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_SETVALID0_SV_SHIFT))&LPC_DMA_SETVALID0_SV_MASK) /*!< LPC_DMA_SETVALID0                       */
/* ------- SETTRIG0 Bit Fields                      ------ */
#define LPC_DMA_SETTRIG0_TRIG_MASK               (0x3FFFFU)                                          /*!< LPC_DMA_SETTRIG0: TRIG Mask             */
#define LPC_DMA_SETTRIG0_TRIG_SHIFT              (0U)                                                /*!< LPC_DMA_SETTRIG0: TRIG Position         */
#define LPC_DMA_SETTRIG0_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_SETTRIG0_TRIG_SHIFT))&LPC_DMA_SETTRIG0_TRIG_MASK) /*!< LPC_DMA_SETTRIG0                        */
/* ------- ABORT0 Bit Fields                        ------ */
#define LPC_DMA_ABORT0_ABORTCTRL_MASK            (0x3FFFFU)                                          /*!< LPC_DMA_ABORT0: ABORTCTRL Mask          */
#define LPC_DMA_ABORT0_ABORTCTRL_SHIFT           (0U)                                                /*!< LPC_DMA_ABORT0: ABORTCTRL Position      */
#define LPC_DMA_ABORT0_ABORTCTRL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_ABORT0_ABORTCTRL_SHIFT))&LPC_DMA_ABORT0_ABORTCTRL_MASK) /*!< LPC_DMA_ABORT0                          */
/* ------- CFG0 Bit Fields                          ------ */
#define LPC_DMA_CFG0_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG0: PERIPHREQEN Mask          */
#define LPC_DMA_CFG0_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG0: PERIPHREQEN Position      */
#define LPC_DMA_CFG0_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_PERIPHREQEN_SHIFT))&LPC_DMA_CFG0_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG0                            */
#define LPC_DMA_CFG0_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG0: HWTRIGEN Mask             */
#define LPC_DMA_CFG0_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG0: HWTRIGEN Position         */
#define LPC_DMA_CFG0_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_HWTRIGEN_SHIFT))&LPC_DMA_CFG0_HWTRIGEN_MASK) /*!< LPC_DMA_CFG0                            */
#define LPC_DMA_CFG0_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG0: TRIGPOL Mask              */
#define LPC_DMA_CFG0_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG0: TRIGPOL Position          */
#define LPC_DMA_CFG0_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_TRIGPOL_SHIFT))&LPC_DMA_CFG0_TRIGPOL_MASK) /*!< LPC_DMA_CFG0                            */
#define LPC_DMA_CFG0_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG0: TRIGTYPE Mask             */
#define LPC_DMA_CFG0_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG0: TRIGTYPE Position         */
#define LPC_DMA_CFG0_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_TRIGTYPE_SHIFT))&LPC_DMA_CFG0_TRIGTYPE_MASK) /*!< LPC_DMA_CFG0                            */
#define LPC_DMA_CFG0_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG0: TRIGBURST Mask            */
#define LPC_DMA_CFG0_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG0: TRIGBURST Position        */
#define LPC_DMA_CFG0_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_TRIGBURST_SHIFT))&LPC_DMA_CFG0_TRIGBURST_MASK) /*!< LPC_DMA_CFG0                            */
#define LPC_DMA_CFG0_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG0: BURSTPOWER Mask           */
#define LPC_DMA_CFG0_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG0: BURSTPOWER Position       */
#define LPC_DMA_CFG0_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_BURSTPOWER_SHIFT))&LPC_DMA_CFG0_BURSTPOWER_MASK) /*!< LPC_DMA_CFG0                            */
#define LPC_DMA_CFG0_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG0: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG0_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG0: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG0_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG0_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG0                            */
#define LPC_DMA_CFG0_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG0: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG0_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG0: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG0_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG0_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG0                            */
#define LPC_DMA_CFG0_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG0: CHPRIORITY Mask           */
#define LPC_DMA_CFG0_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG0: CHPRIORITY Position       */
#define LPC_DMA_CFG0_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG0_CHPRIORITY_SHIFT))&LPC_DMA_CFG0_CHPRIORITY_MASK) /*!< LPC_DMA_CFG0                            */
/* ------- CTLSTAT0 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT0_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT0: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT0_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT0: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT0_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT0_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT0_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT0                        */
#define LPC_DMA_CTLSTAT0_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT0: TRIG Mask             */
#define LPC_DMA_CTLSTAT0_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT0: TRIG Position         */
#define LPC_DMA_CTLSTAT0_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT0_TRIG_SHIFT))&LPC_DMA_CTLSTAT0_TRIG_MASK) /*!< LPC_DMA_CTLSTAT0                        */
/* ------- XFERCFG0 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG0_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG0: CFGVALID Mask         */
#define LPC_DMA_XFERCFG0_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG0: CFGVALID Position     */
#define LPC_DMA_XFERCFG0_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_CFGVALID_SHIFT))&LPC_DMA_XFERCFG0_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG0: RELOAD Mask           */
#define LPC_DMA_XFERCFG0_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG0: RELOAD Position       */
#define LPC_DMA_XFERCFG0_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_RELOAD_SHIFT))&LPC_DMA_XFERCFG0_RELOAD_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG0: SWTRIG Mask           */
#define LPC_DMA_XFERCFG0_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG0: SWTRIG Position       */
#define LPC_DMA_XFERCFG0_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_SWTRIG_SHIFT))&LPC_DMA_XFERCFG0_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG0: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG0_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG0: CLRTRIG Position      */
#define LPC_DMA_XFERCFG0_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG0_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG0: SETINTA Mask          */
#define LPC_DMA_XFERCFG0_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG0: SETINTA Position      */
#define LPC_DMA_XFERCFG0_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_SETINTA_SHIFT))&LPC_DMA_XFERCFG0_SETINTA_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG0: SETINTB Mask          */
#define LPC_DMA_XFERCFG0_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG0: SETINTB Position      */
#define LPC_DMA_XFERCFG0_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_SETINTB_SHIFT))&LPC_DMA_XFERCFG0_SETINTB_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG0: WIDTH Mask            */
#define LPC_DMA_XFERCFG0_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG0: WIDTH Position        */
#define LPC_DMA_XFERCFG0_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_WIDTH_SHIFT))&LPC_DMA_XFERCFG0_WIDTH_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG0: SRCINC Mask           */
#define LPC_DMA_XFERCFG0_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG0: SRCINC Position       */
#define LPC_DMA_XFERCFG0_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_SRCINC_SHIFT))&LPC_DMA_XFERCFG0_SRCINC_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG0: DSTINC Mask           */
#define LPC_DMA_XFERCFG0_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG0: DSTINC Position       */
#define LPC_DMA_XFERCFG0_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_DSTINC_SHIFT))&LPC_DMA_XFERCFG0_DSTINC_MASK) /*!< LPC_DMA_XFERCFG0                        */
#define LPC_DMA_XFERCFG0_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG0: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG0_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG0: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG0_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG0_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG0_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG0                        */
/* ------- CFG1 Bit Fields                          ------ */
#define LPC_DMA_CFG1_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG1: PERIPHREQEN Mask          */
#define LPC_DMA_CFG1_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG1: PERIPHREQEN Position      */
#define LPC_DMA_CFG1_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_PERIPHREQEN_SHIFT))&LPC_DMA_CFG1_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG1                            */
#define LPC_DMA_CFG1_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG1: HWTRIGEN Mask             */
#define LPC_DMA_CFG1_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG1: HWTRIGEN Position         */
#define LPC_DMA_CFG1_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_HWTRIGEN_SHIFT))&LPC_DMA_CFG1_HWTRIGEN_MASK) /*!< LPC_DMA_CFG1                            */
#define LPC_DMA_CFG1_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG1: TRIGPOL Mask              */
#define LPC_DMA_CFG1_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG1: TRIGPOL Position          */
#define LPC_DMA_CFG1_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_TRIGPOL_SHIFT))&LPC_DMA_CFG1_TRIGPOL_MASK) /*!< LPC_DMA_CFG1                            */
#define LPC_DMA_CFG1_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG1: TRIGTYPE Mask             */
#define LPC_DMA_CFG1_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG1: TRIGTYPE Position         */
#define LPC_DMA_CFG1_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_TRIGTYPE_SHIFT))&LPC_DMA_CFG1_TRIGTYPE_MASK) /*!< LPC_DMA_CFG1                            */
#define LPC_DMA_CFG1_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG1: TRIGBURST Mask            */
#define LPC_DMA_CFG1_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG1: TRIGBURST Position        */
#define LPC_DMA_CFG1_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_TRIGBURST_SHIFT))&LPC_DMA_CFG1_TRIGBURST_MASK) /*!< LPC_DMA_CFG1                            */
#define LPC_DMA_CFG1_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG1: BURSTPOWER Mask           */
#define LPC_DMA_CFG1_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG1: BURSTPOWER Position       */
#define LPC_DMA_CFG1_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_BURSTPOWER_SHIFT))&LPC_DMA_CFG1_BURSTPOWER_MASK) /*!< LPC_DMA_CFG1                            */
#define LPC_DMA_CFG1_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG1: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG1_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG1: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG1_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG1_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG1                            */
#define LPC_DMA_CFG1_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG1: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG1_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG1: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG1_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG1_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG1                            */
#define LPC_DMA_CFG1_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG1: CHPRIORITY Mask           */
#define LPC_DMA_CFG1_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG1: CHPRIORITY Position       */
#define LPC_DMA_CFG1_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG1_CHPRIORITY_SHIFT))&LPC_DMA_CFG1_CHPRIORITY_MASK) /*!< LPC_DMA_CFG1                            */
/* ------- CTLSTAT1 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT1_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT1: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT1_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT1: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT1_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT1_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT1_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT1                        */
#define LPC_DMA_CTLSTAT1_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT1: TRIG Mask             */
#define LPC_DMA_CTLSTAT1_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT1: TRIG Position         */
#define LPC_DMA_CTLSTAT1_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT1_TRIG_SHIFT))&LPC_DMA_CTLSTAT1_TRIG_MASK) /*!< LPC_DMA_CTLSTAT1                        */
/* ------- XFERCFG1 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG1_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG1: CFGVALID Mask         */
#define LPC_DMA_XFERCFG1_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG1: CFGVALID Position     */
#define LPC_DMA_XFERCFG1_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_CFGVALID_SHIFT))&LPC_DMA_XFERCFG1_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG1: RELOAD Mask           */
#define LPC_DMA_XFERCFG1_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG1: RELOAD Position       */
#define LPC_DMA_XFERCFG1_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_RELOAD_SHIFT))&LPC_DMA_XFERCFG1_RELOAD_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG1: SWTRIG Mask           */
#define LPC_DMA_XFERCFG1_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG1: SWTRIG Position       */
#define LPC_DMA_XFERCFG1_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_SWTRIG_SHIFT))&LPC_DMA_XFERCFG1_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG1: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG1_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG1: CLRTRIG Position      */
#define LPC_DMA_XFERCFG1_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG1_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG1: SETINTA Mask          */
#define LPC_DMA_XFERCFG1_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG1: SETINTA Position      */
#define LPC_DMA_XFERCFG1_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_SETINTA_SHIFT))&LPC_DMA_XFERCFG1_SETINTA_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG1: SETINTB Mask          */
#define LPC_DMA_XFERCFG1_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG1: SETINTB Position      */
#define LPC_DMA_XFERCFG1_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_SETINTB_SHIFT))&LPC_DMA_XFERCFG1_SETINTB_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG1: WIDTH Mask            */
#define LPC_DMA_XFERCFG1_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG1: WIDTH Position        */
#define LPC_DMA_XFERCFG1_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_WIDTH_SHIFT))&LPC_DMA_XFERCFG1_WIDTH_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG1: SRCINC Mask           */
#define LPC_DMA_XFERCFG1_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG1: SRCINC Position       */
#define LPC_DMA_XFERCFG1_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_SRCINC_SHIFT))&LPC_DMA_XFERCFG1_SRCINC_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG1: DSTINC Mask           */
#define LPC_DMA_XFERCFG1_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG1: DSTINC Position       */
#define LPC_DMA_XFERCFG1_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_DSTINC_SHIFT))&LPC_DMA_XFERCFG1_DSTINC_MASK) /*!< LPC_DMA_XFERCFG1                        */
#define LPC_DMA_XFERCFG1_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG1: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG1_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG1: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG1_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG1_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG1_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG1                        */
/* ------- CFG2 Bit Fields                          ------ */
#define LPC_DMA_CFG2_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG2: PERIPHREQEN Mask          */
#define LPC_DMA_CFG2_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG2: PERIPHREQEN Position      */
#define LPC_DMA_CFG2_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_PERIPHREQEN_SHIFT))&LPC_DMA_CFG2_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG2                            */
#define LPC_DMA_CFG2_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG2: HWTRIGEN Mask             */
#define LPC_DMA_CFG2_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG2: HWTRIGEN Position         */
#define LPC_DMA_CFG2_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_HWTRIGEN_SHIFT))&LPC_DMA_CFG2_HWTRIGEN_MASK) /*!< LPC_DMA_CFG2                            */
#define LPC_DMA_CFG2_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG2: TRIGPOL Mask              */
#define LPC_DMA_CFG2_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG2: TRIGPOL Position          */
#define LPC_DMA_CFG2_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_TRIGPOL_SHIFT))&LPC_DMA_CFG2_TRIGPOL_MASK) /*!< LPC_DMA_CFG2                            */
#define LPC_DMA_CFG2_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG2: TRIGTYPE Mask             */
#define LPC_DMA_CFG2_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG2: TRIGTYPE Position         */
#define LPC_DMA_CFG2_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_TRIGTYPE_SHIFT))&LPC_DMA_CFG2_TRIGTYPE_MASK) /*!< LPC_DMA_CFG2                            */
#define LPC_DMA_CFG2_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG2: TRIGBURST Mask            */
#define LPC_DMA_CFG2_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG2: TRIGBURST Position        */
#define LPC_DMA_CFG2_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_TRIGBURST_SHIFT))&LPC_DMA_CFG2_TRIGBURST_MASK) /*!< LPC_DMA_CFG2                            */
#define LPC_DMA_CFG2_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG2: BURSTPOWER Mask           */
#define LPC_DMA_CFG2_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG2: BURSTPOWER Position       */
#define LPC_DMA_CFG2_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_BURSTPOWER_SHIFT))&LPC_DMA_CFG2_BURSTPOWER_MASK) /*!< LPC_DMA_CFG2                            */
#define LPC_DMA_CFG2_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG2: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG2_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG2: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG2_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG2_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG2                            */
#define LPC_DMA_CFG2_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG2: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG2_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG2: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG2_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG2_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG2                            */
#define LPC_DMA_CFG2_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG2: CHPRIORITY Mask           */
#define LPC_DMA_CFG2_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG2: CHPRIORITY Position       */
#define LPC_DMA_CFG2_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG2_CHPRIORITY_SHIFT))&LPC_DMA_CFG2_CHPRIORITY_MASK) /*!< LPC_DMA_CFG2                            */
/* ------- CTLSTAT2 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT2_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT2: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT2_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT2: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT2_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT2_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT2_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT2                        */
#define LPC_DMA_CTLSTAT2_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT2: TRIG Mask             */
#define LPC_DMA_CTLSTAT2_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT2: TRIG Position         */
#define LPC_DMA_CTLSTAT2_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT2_TRIG_SHIFT))&LPC_DMA_CTLSTAT2_TRIG_MASK) /*!< LPC_DMA_CTLSTAT2                        */
/* ------- XFERCFG2 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG2_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG2: CFGVALID Mask         */
#define LPC_DMA_XFERCFG2_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG2: CFGVALID Position     */
#define LPC_DMA_XFERCFG2_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_CFGVALID_SHIFT))&LPC_DMA_XFERCFG2_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG2: RELOAD Mask           */
#define LPC_DMA_XFERCFG2_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG2: RELOAD Position       */
#define LPC_DMA_XFERCFG2_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_RELOAD_SHIFT))&LPC_DMA_XFERCFG2_RELOAD_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG2: SWTRIG Mask           */
#define LPC_DMA_XFERCFG2_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG2: SWTRIG Position       */
#define LPC_DMA_XFERCFG2_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_SWTRIG_SHIFT))&LPC_DMA_XFERCFG2_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG2: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG2_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG2: CLRTRIG Position      */
#define LPC_DMA_XFERCFG2_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG2_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG2: SETINTA Mask          */
#define LPC_DMA_XFERCFG2_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG2: SETINTA Position      */
#define LPC_DMA_XFERCFG2_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_SETINTA_SHIFT))&LPC_DMA_XFERCFG2_SETINTA_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG2: SETINTB Mask          */
#define LPC_DMA_XFERCFG2_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG2: SETINTB Position      */
#define LPC_DMA_XFERCFG2_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_SETINTB_SHIFT))&LPC_DMA_XFERCFG2_SETINTB_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG2: WIDTH Mask            */
#define LPC_DMA_XFERCFG2_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG2: WIDTH Position        */
#define LPC_DMA_XFERCFG2_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_WIDTH_SHIFT))&LPC_DMA_XFERCFG2_WIDTH_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG2: SRCINC Mask           */
#define LPC_DMA_XFERCFG2_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG2: SRCINC Position       */
#define LPC_DMA_XFERCFG2_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_SRCINC_SHIFT))&LPC_DMA_XFERCFG2_SRCINC_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG2: DSTINC Mask           */
#define LPC_DMA_XFERCFG2_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG2: DSTINC Position       */
#define LPC_DMA_XFERCFG2_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_DSTINC_SHIFT))&LPC_DMA_XFERCFG2_DSTINC_MASK) /*!< LPC_DMA_XFERCFG2                        */
#define LPC_DMA_XFERCFG2_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG2: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG2_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG2: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG2_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG2_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG2_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG2                        */
/* ------- CFG3 Bit Fields                          ------ */
#define LPC_DMA_CFG3_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG3: PERIPHREQEN Mask          */
#define LPC_DMA_CFG3_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG3: PERIPHREQEN Position      */
#define LPC_DMA_CFG3_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_PERIPHREQEN_SHIFT))&LPC_DMA_CFG3_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG3                            */
#define LPC_DMA_CFG3_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG3: HWTRIGEN Mask             */
#define LPC_DMA_CFG3_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG3: HWTRIGEN Position         */
#define LPC_DMA_CFG3_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_HWTRIGEN_SHIFT))&LPC_DMA_CFG3_HWTRIGEN_MASK) /*!< LPC_DMA_CFG3                            */
#define LPC_DMA_CFG3_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG3: TRIGPOL Mask              */
#define LPC_DMA_CFG3_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG3: TRIGPOL Position          */
#define LPC_DMA_CFG3_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_TRIGPOL_SHIFT))&LPC_DMA_CFG3_TRIGPOL_MASK) /*!< LPC_DMA_CFG3                            */
#define LPC_DMA_CFG3_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG3: TRIGTYPE Mask             */
#define LPC_DMA_CFG3_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG3: TRIGTYPE Position         */
#define LPC_DMA_CFG3_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_TRIGTYPE_SHIFT))&LPC_DMA_CFG3_TRIGTYPE_MASK) /*!< LPC_DMA_CFG3                            */
#define LPC_DMA_CFG3_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG3: TRIGBURST Mask            */
#define LPC_DMA_CFG3_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG3: TRIGBURST Position        */
#define LPC_DMA_CFG3_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_TRIGBURST_SHIFT))&LPC_DMA_CFG3_TRIGBURST_MASK) /*!< LPC_DMA_CFG3                            */
#define LPC_DMA_CFG3_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG3: BURSTPOWER Mask           */
#define LPC_DMA_CFG3_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG3: BURSTPOWER Position       */
#define LPC_DMA_CFG3_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_BURSTPOWER_SHIFT))&LPC_DMA_CFG3_BURSTPOWER_MASK) /*!< LPC_DMA_CFG3                            */
#define LPC_DMA_CFG3_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG3: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG3_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG3: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG3_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG3_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG3                            */
#define LPC_DMA_CFG3_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG3: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG3_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG3: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG3_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG3_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG3                            */
#define LPC_DMA_CFG3_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG3: CHPRIORITY Mask           */
#define LPC_DMA_CFG3_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG3: CHPRIORITY Position       */
#define LPC_DMA_CFG3_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG3_CHPRIORITY_SHIFT))&LPC_DMA_CFG3_CHPRIORITY_MASK) /*!< LPC_DMA_CFG3                            */
/* ------- CTLSTAT3 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT3_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT3: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT3_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT3: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT3_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT3_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT3_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT3                        */
#define LPC_DMA_CTLSTAT3_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT3: TRIG Mask             */
#define LPC_DMA_CTLSTAT3_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT3: TRIG Position         */
#define LPC_DMA_CTLSTAT3_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT3_TRIG_SHIFT))&LPC_DMA_CTLSTAT3_TRIG_MASK) /*!< LPC_DMA_CTLSTAT3                        */
/* ------- XFERCFG3 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG3_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG3: CFGVALID Mask         */
#define LPC_DMA_XFERCFG3_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG3: CFGVALID Position     */
#define LPC_DMA_XFERCFG3_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_CFGVALID_SHIFT))&LPC_DMA_XFERCFG3_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG3: RELOAD Mask           */
#define LPC_DMA_XFERCFG3_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG3: RELOAD Position       */
#define LPC_DMA_XFERCFG3_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_RELOAD_SHIFT))&LPC_DMA_XFERCFG3_RELOAD_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG3: SWTRIG Mask           */
#define LPC_DMA_XFERCFG3_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG3: SWTRIG Position       */
#define LPC_DMA_XFERCFG3_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_SWTRIG_SHIFT))&LPC_DMA_XFERCFG3_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG3: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG3_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG3: CLRTRIG Position      */
#define LPC_DMA_XFERCFG3_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG3_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG3: SETINTA Mask          */
#define LPC_DMA_XFERCFG3_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG3: SETINTA Position      */
#define LPC_DMA_XFERCFG3_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_SETINTA_SHIFT))&LPC_DMA_XFERCFG3_SETINTA_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG3: SETINTB Mask          */
#define LPC_DMA_XFERCFG3_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG3: SETINTB Position      */
#define LPC_DMA_XFERCFG3_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_SETINTB_SHIFT))&LPC_DMA_XFERCFG3_SETINTB_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG3: WIDTH Mask            */
#define LPC_DMA_XFERCFG3_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG3: WIDTH Position        */
#define LPC_DMA_XFERCFG3_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_WIDTH_SHIFT))&LPC_DMA_XFERCFG3_WIDTH_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG3: SRCINC Mask           */
#define LPC_DMA_XFERCFG3_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG3: SRCINC Position       */
#define LPC_DMA_XFERCFG3_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_SRCINC_SHIFT))&LPC_DMA_XFERCFG3_SRCINC_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG3: DSTINC Mask           */
#define LPC_DMA_XFERCFG3_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG3: DSTINC Position       */
#define LPC_DMA_XFERCFG3_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_DSTINC_SHIFT))&LPC_DMA_XFERCFG3_DSTINC_MASK) /*!< LPC_DMA_XFERCFG3                        */
#define LPC_DMA_XFERCFG3_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG3: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG3_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG3: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG3_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG3_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG3_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG3                        */
/* ------- CFG4 Bit Fields                          ------ */
#define LPC_DMA_CFG4_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG4: PERIPHREQEN Mask          */
#define LPC_DMA_CFG4_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG4: PERIPHREQEN Position      */
#define LPC_DMA_CFG4_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_PERIPHREQEN_SHIFT))&LPC_DMA_CFG4_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG4                            */
#define LPC_DMA_CFG4_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG4: HWTRIGEN Mask             */
#define LPC_DMA_CFG4_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG4: HWTRIGEN Position         */
#define LPC_DMA_CFG4_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_HWTRIGEN_SHIFT))&LPC_DMA_CFG4_HWTRIGEN_MASK) /*!< LPC_DMA_CFG4                            */
#define LPC_DMA_CFG4_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG4: TRIGPOL Mask              */
#define LPC_DMA_CFG4_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG4: TRIGPOL Position          */
#define LPC_DMA_CFG4_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_TRIGPOL_SHIFT))&LPC_DMA_CFG4_TRIGPOL_MASK) /*!< LPC_DMA_CFG4                            */
#define LPC_DMA_CFG4_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG4: TRIGTYPE Mask             */
#define LPC_DMA_CFG4_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG4: TRIGTYPE Position         */
#define LPC_DMA_CFG4_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_TRIGTYPE_SHIFT))&LPC_DMA_CFG4_TRIGTYPE_MASK) /*!< LPC_DMA_CFG4                            */
#define LPC_DMA_CFG4_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG4: TRIGBURST Mask            */
#define LPC_DMA_CFG4_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG4: TRIGBURST Position        */
#define LPC_DMA_CFG4_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_TRIGBURST_SHIFT))&LPC_DMA_CFG4_TRIGBURST_MASK) /*!< LPC_DMA_CFG4                            */
#define LPC_DMA_CFG4_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG4: BURSTPOWER Mask           */
#define LPC_DMA_CFG4_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG4: BURSTPOWER Position       */
#define LPC_DMA_CFG4_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_BURSTPOWER_SHIFT))&LPC_DMA_CFG4_BURSTPOWER_MASK) /*!< LPC_DMA_CFG4                            */
#define LPC_DMA_CFG4_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG4: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG4_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG4: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG4_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG4_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG4                            */
#define LPC_DMA_CFG4_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG4: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG4_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG4: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG4_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG4_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG4                            */
#define LPC_DMA_CFG4_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG4: CHPRIORITY Mask           */
#define LPC_DMA_CFG4_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG4: CHPRIORITY Position       */
#define LPC_DMA_CFG4_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG4_CHPRIORITY_SHIFT))&LPC_DMA_CFG4_CHPRIORITY_MASK) /*!< LPC_DMA_CFG4                            */
/* ------- CTLSTAT4 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT4_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT4: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT4_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT4: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT4_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT4_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT4_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT4                        */
#define LPC_DMA_CTLSTAT4_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT4: TRIG Mask             */
#define LPC_DMA_CTLSTAT4_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT4: TRIG Position         */
#define LPC_DMA_CTLSTAT4_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT4_TRIG_SHIFT))&LPC_DMA_CTLSTAT4_TRIG_MASK) /*!< LPC_DMA_CTLSTAT4                        */
/* ------- XFERCFG4 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG4_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG4: CFGVALID Mask         */
#define LPC_DMA_XFERCFG4_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG4: CFGVALID Position     */
#define LPC_DMA_XFERCFG4_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_CFGVALID_SHIFT))&LPC_DMA_XFERCFG4_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG4: RELOAD Mask           */
#define LPC_DMA_XFERCFG4_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG4: RELOAD Position       */
#define LPC_DMA_XFERCFG4_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_RELOAD_SHIFT))&LPC_DMA_XFERCFG4_RELOAD_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG4: SWTRIG Mask           */
#define LPC_DMA_XFERCFG4_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG4: SWTRIG Position       */
#define LPC_DMA_XFERCFG4_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_SWTRIG_SHIFT))&LPC_DMA_XFERCFG4_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG4: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG4_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG4: CLRTRIG Position      */
#define LPC_DMA_XFERCFG4_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG4_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG4: SETINTA Mask          */
#define LPC_DMA_XFERCFG4_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG4: SETINTA Position      */
#define LPC_DMA_XFERCFG4_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_SETINTA_SHIFT))&LPC_DMA_XFERCFG4_SETINTA_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG4: SETINTB Mask          */
#define LPC_DMA_XFERCFG4_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG4: SETINTB Position      */
#define LPC_DMA_XFERCFG4_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_SETINTB_SHIFT))&LPC_DMA_XFERCFG4_SETINTB_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG4: WIDTH Mask            */
#define LPC_DMA_XFERCFG4_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG4: WIDTH Position        */
#define LPC_DMA_XFERCFG4_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_WIDTH_SHIFT))&LPC_DMA_XFERCFG4_WIDTH_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG4: SRCINC Mask           */
#define LPC_DMA_XFERCFG4_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG4: SRCINC Position       */
#define LPC_DMA_XFERCFG4_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_SRCINC_SHIFT))&LPC_DMA_XFERCFG4_SRCINC_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG4: DSTINC Mask           */
#define LPC_DMA_XFERCFG4_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG4: DSTINC Position       */
#define LPC_DMA_XFERCFG4_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_DSTINC_SHIFT))&LPC_DMA_XFERCFG4_DSTINC_MASK) /*!< LPC_DMA_XFERCFG4                        */
#define LPC_DMA_XFERCFG4_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG4: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG4_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG4: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG4_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG4_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG4_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG4                        */
/* ------- CFG5 Bit Fields                          ------ */
#define LPC_DMA_CFG5_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG5: PERIPHREQEN Mask          */
#define LPC_DMA_CFG5_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG5: PERIPHREQEN Position      */
#define LPC_DMA_CFG5_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_PERIPHREQEN_SHIFT))&LPC_DMA_CFG5_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG5                            */
#define LPC_DMA_CFG5_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG5: HWTRIGEN Mask             */
#define LPC_DMA_CFG5_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG5: HWTRIGEN Position         */
#define LPC_DMA_CFG5_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_HWTRIGEN_SHIFT))&LPC_DMA_CFG5_HWTRIGEN_MASK) /*!< LPC_DMA_CFG5                            */
#define LPC_DMA_CFG5_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG5: TRIGPOL Mask              */
#define LPC_DMA_CFG5_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG5: TRIGPOL Position          */
#define LPC_DMA_CFG5_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_TRIGPOL_SHIFT))&LPC_DMA_CFG5_TRIGPOL_MASK) /*!< LPC_DMA_CFG5                            */
#define LPC_DMA_CFG5_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG5: TRIGTYPE Mask             */
#define LPC_DMA_CFG5_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG5: TRIGTYPE Position         */
#define LPC_DMA_CFG5_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_TRIGTYPE_SHIFT))&LPC_DMA_CFG5_TRIGTYPE_MASK) /*!< LPC_DMA_CFG5                            */
#define LPC_DMA_CFG5_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG5: TRIGBURST Mask            */
#define LPC_DMA_CFG5_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG5: TRIGBURST Position        */
#define LPC_DMA_CFG5_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_TRIGBURST_SHIFT))&LPC_DMA_CFG5_TRIGBURST_MASK) /*!< LPC_DMA_CFG5                            */
#define LPC_DMA_CFG5_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG5: BURSTPOWER Mask           */
#define LPC_DMA_CFG5_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG5: BURSTPOWER Position       */
#define LPC_DMA_CFG5_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_BURSTPOWER_SHIFT))&LPC_DMA_CFG5_BURSTPOWER_MASK) /*!< LPC_DMA_CFG5                            */
#define LPC_DMA_CFG5_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG5: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG5_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG5: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG5_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG5_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG5                            */
#define LPC_DMA_CFG5_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG5: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG5_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG5: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG5_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG5_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG5                            */
#define LPC_DMA_CFG5_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG5: CHPRIORITY Mask           */
#define LPC_DMA_CFG5_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG5: CHPRIORITY Position       */
#define LPC_DMA_CFG5_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG5_CHPRIORITY_SHIFT))&LPC_DMA_CFG5_CHPRIORITY_MASK) /*!< LPC_DMA_CFG5                            */
/* ------- CTLSTAT5 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT5_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT5: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT5_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT5: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT5_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT5_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT5_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT5                        */
#define LPC_DMA_CTLSTAT5_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT5: TRIG Mask             */
#define LPC_DMA_CTLSTAT5_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT5: TRIG Position         */
#define LPC_DMA_CTLSTAT5_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT5_TRIG_SHIFT))&LPC_DMA_CTLSTAT5_TRIG_MASK) /*!< LPC_DMA_CTLSTAT5                        */
/* ------- XFERCFG5 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG5_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG5: CFGVALID Mask         */
#define LPC_DMA_XFERCFG5_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG5: CFGVALID Position     */
#define LPC_DMA_XFERCFG5_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_CFGVALID_SHIFT))&LPC_DMA_XFERCFG5_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG5: RELOAD Mask           */
#define LPC_DMA_XFERCFG5_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG5: RELOAD Position       */
#define LPC_DMA_XFERCFG5_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_RELOAD_SHIFT))&LPC_DMA_XFERCFG5_RELOAD_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG5: SWTRIG Mask           */
#define LPC_DMA_XFERCFG5_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG5: SWTRIG Position       */
#define LPC_DMA_XFERCFG5_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_SWTRIG_SHIFT))&LPC_DMA_XFERCFG5_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG5: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG5_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG5: CLRTRIG Position      */
#define LPC_DMA_XFERCFG5_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG5_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG5: SETINTA Mask          */
#define LPC_DMA_XFERCFG5_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG5: SETINTA Position      */
#define LPC_DMA_XFERCFG5_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_SETINTA_SHIFT))&LPC_DMA_XFERCFG5_SETINTA_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG5: SETINTB Mask          */
#define LPC_DMA_XFERCFG5_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG5: SETINTB Position      */
#define LPC_DMA_XFERCFG5_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_SETINTB_SHIFT))&LPC_DMA_XFERCFG5_SETINTB_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG5: WIDTH Mask            */
#define LPC_DMA_XFERCFG5_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG5: WIDTH Position        */
#define LPC_DMA_XFERCFG5_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_WIDTH_SHIFT))&LPC_DMA_XFERCFG5_WIDTH_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG5: SRCINC Mask           */
#define LPC_DMA_XFERCFG5_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG5: SRCINC Position       */
#define LPC_DMA_XFERCFG5_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_SRCINC_SHIFT))&LPC_DMA_XFERCFG5_SRCINC_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG5: DSTINC Mask           */
#define LPC_DMA_XFERCFG5_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG5: DSTINC Position       */
#define LPC_DMA_XFERCFG5_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_DSTINC_SHIFT))&LPC_DMA_XFERCFG5_DSTINC_MASK) /*!< LPC_DMA_XFERCFG5                        */
#define LPC_DMA_XFERCFG5_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG5: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG5_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG5: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG5_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG5_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG5_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG5                        */
/* ------- CFG6 Bit Fields                          ------ */
#define LPC_DMA_CFG6_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG6: PERIPHREQEN Mask          */
#define LPC_DMA_CFG6_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG6: PERIPHREQEN Position      */
#define LPC_DMA_CFG6_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_PERIPHREQEN_SHIFT))&LPC_DMA_CFG6_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG6                            */
#define LPC_DMA_CFG6_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG6: HWTRIGEN Mask             */
#define LPC_DMA_CFG6_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG6: HWTRIGEN Position         */
#define LPC_DMA_CFG6_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_HWTRIGEN_SHIFT))&LPC_DMA_CFG6_HWTRIGEN_MASK) /*!< LPC_DMA_CFG6                            */
#define LPC_DMA_CFG6_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG6: TRIGPOL Mask              */
#define LPC_DMA_CFG6_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG6: TRIGPOL Position          */
#define LPC_DMA_CFG6_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_TRIGPOL_SHIFT))&LPC_DMA_CFG6_TRIGPOL_MASK) /*!< LPC_DMA_CFG6                            */
#define LPC_DMA_CFG6_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG6: TRIGTYPE Mask             */
#define LPC_DMA_CFG6_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG6: TRIGTYPE Position         */
#define LPC_DMA_CFG6_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_TRIGTYPE_SHIFT))&LPC_DMA_CFG6_TRIGTYPE_MASK) /*!< LPC_DMA_CFG6                            */
#define LPC_DMA_CFG6_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG6: TRIGBURST Mask            */
#define LPC_DMA_CFG6_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG6: TRIGBURST Position        */
#define LPC_DMA_CFG6_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_TRIGBURST_SHIFT))&LPC_DMA_CFG6_TRIGBURST_MASK) /*!< LPC_DMA_CFG6                            */
#define LPC_DMA_CFG6_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG6: BURSTPOWER Mask           */
#define LPC_DMA_CFG6_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG6: BURSTPOWER Position       */
#define LPC_DMA_CFG6_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_BURSTPOWER_SHIFT))&LPC_DMA_CFG6_BURSTPOWER_MASK) /*!< LPC_DMA_CFG6                            */
#define LPC_DMA_CFG6_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG6: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG6_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG6: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG6_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG6_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG6                            */
#define LPC_DMA_CFG6_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG6: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG6_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG6: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG6_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG6_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG6                            */
#define LPC_DMA_CFG6_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG6: CHPRIORITY Mask           */
#define LPC_DMA_CFG6_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG6: CHPRIORITY Position       */
#define LPC_DMA_CFG6_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG6_CHPRIORITY_SHIFT))&LPC_DMA_CFG6_CHPRIORITY_MASK) /*!< LPC_DMA_CFG6                            */
/* ------- CTLSTAT6 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT6_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT6: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT6_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT6: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT6_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT6_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT6_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT6                        */
#define LPC_DMA_CTLSTAT6_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT6: TRIG Mask             */
#define LPC_DMA_CTLSTAT6_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT6: TRIG Position         */
#define LPC_DMA_CTLSTAT6_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT6_TRIG_SHIFT))&LPC_DMA_CTLSTAT6_TRIG_MASK) /*!< LPC_DMA_CTLSTAT6                        */
/* ------- XFERCFG6 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG6_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG6: CFGVALID Mask         */
#define LPC_DMA_XFERCFG6_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG6: CFGVALID Position     */
#define LPC_DMA_XFERCFG6_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_CFGVALID_SHIFT))&LPC_DMA_XFERCFG6_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG6: RELOAD Mask           */
#define LPC_DMA_XFERCFG6_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG6: RELOAD Position       */
#define LPC_DMA_XFERCFG6_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_RELOAD_SHIFT))&LPC_DMA_XFERCFG6_RELOAD_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG6: SWTRIG Mask           */
#define LPC_DMA_XFERCFG6_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG6: SWTRIG Position       */
#define LPC_DMA_XFERCFG6_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_SWTRIG_SHIFT))&LPC_DMA_XFERCFG6_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG6: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG6_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG6: CLRTRIG Position      */
#define LPC_DMA_XFERCFG6_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG6_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG6: SETINTA Mask          */
#define LPC_DMA_XFERCFG6_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG6: SETINTA Position      */
#define LPC_DMA_XFERCFG6_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_SETINTA_SHIFT))&LPC_DMA_XFERCFG6_SETINTA_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG6: SETINTB Mask          */
#define LPC_DMA_XFERCFG6_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG6: SETINTB Position      */
#define LPC_DMA_XFERCFG6_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_SETINTB_SHIFT))&LPC_DMA_XFERCFG6_SETINTB_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG6: WIDTH Mask            */
#define LPC_DMA_XFERCFG6_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG6: WIDTH Position        */
#define LPC_DMA_XFERCFG6_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_WIDTH_SHIFT))&LPC_DMA_XFERCFG6_WIDTH_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG6: SRCINC Mask           */
#define LPC_DMA_XFERCFG6_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG6: SRCINC Position       */
#define LPC_DMA_XFERCFG6_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_SRCINC_SHIFT))&LPC_DMA_XFERCFG6_SRCINC_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG6: DSTINC Mask           */
#define LPC_DMA_XFERCFG6_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG6: DSTINC Position       */
#define LPC_DMA_XFERCFG6_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_DSTINC_SHIFT))&LPC_DMA_XFERCFG6_DSTINC_MASK) /*!< LPC_DMA_XFERCFG6                        */
#define LPC_DMA_XFERCFG6_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG6: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG6_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG6: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG6_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG6_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG6_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG6                        */
/* ------- CFG7 Bit Fields                          ------ */
#define LPC_DMA_CFG7_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG7: PERIPHREQEN Mask          */
#define LPC_DMA_CFG7_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG7: PERIPHREQEN Position      */
#define LPC_DMA_CFG7_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_PERIPHREQEN_SHIFT))&LPC_DMA_CFG7_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG7                            */
#define LPC_DMA_CFG7_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG7: HWTRIGEN Mask             */
#define LPC_DMA_CFG7_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG7: HWTRIGEN Position         */
#define LPC_DMA_CFG7_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_HWTRIGEN_SHIFT))&LPC_DMA_CFG7_HWTRIGEN_MASK) /*!< LPC_DMA_CFG7                            */
#define LPC_DMA_CFG7_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG7: TRIGPOL Mask              */
#define LPC_DMA_CFG7_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG7: TRIGPOL Position          */
#define LPC_DMA_CFG7_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_TRIGPOL_SHIFT))&LPC_DMA_CFG7_TRIGPOL_MASK) /*!< LPC_DMA_CFG7                            */
#define LPC_DMA_CFG7_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG7: TRIGTYPE Mask             */
#define LPC_DMA_CFG7_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG7: TRIGTYPE Position         */
#define LPC_DMA_CFG7_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_TRIGTYPE_SHIFT))&LPC_DMA_CFG7_TRIGTYPE_MASK) /*!< LPC_DMA_CFG7                            */
#define LPC_DMA_CFG7_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG7: TRIGBURST Mask            */
#define LPC_DMA_CFG7_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG7: TRIGBURST Position        */
#define LPC_DMA_CFG7_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_TRIGBURST_SHIFT))&LPC_DMA_CFG7_TRIGBURST_MASK) /*!< LPC_DMA_CFG7                            */
#define LPC_DMA_CFG7_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG7: BURSTPOWER Mask           */
#define LPC_DMA_CFG7_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG7: BURSTPOWER Position       */
#define LPC_DMA_CFG7_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_BURSTPOWER_SHIFT))&LPC_DMA_CFG7_BURSTPOWER_MASK) /*!< LPC_DMA_CFG7                            */
#define LPC_DMA_CFG7_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG7: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG7_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG7: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG7_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG7_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG7                            */
#define LPC_DMA_CFG7_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG7: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG7_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG7: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG7_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG7_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG7                            */
#define LPC_DMA_CFG7_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG7: CHPRIORITY Mask           */
#define LPC_DMA_CFG7_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG7: CHPRIORITY Position       */
#define LPC_DMA_CFG7_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG7_CHPRIORITY_SHIFT))&LPC_DMA_CFG7_CHPRIORITY_MASK) /*!< LPC_DMA_CFG7                            */
/* ------- CTLSTAT7 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT7_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT7: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT7_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT7: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT7_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT7_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT7_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT7                        */
#define LPC_DMA_CTLSTAT7_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT7: TRIG Mask             */
#define LPC_DMA_CTLSTAT7_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT7: TRIG Position         */
#define LPC_DMA_CTLSTAT7_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT7_TRIG_SHIFT))&LPC_DMA_CTLSTAT7_TRIG_MASK) /*!< LPC_DMA_CTLSTAT7                        */
/* ------- XFERCFG7 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG7_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG7: CFGVALID Mask         */
#define LPC_DMA_XFERCFG7_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG7: CFGVALID Position     */
#define LPC_DMA_XFERCFG7_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_CFGVALID_SHIFT))&LPC_DMA_XFERCFG7_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG7: RELOAD Mask           */
#define LPC_DMA_XFERCFG7_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG7: RELOAD Position       */
#define LPC_DMA_XFERCFG7_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_RELOAD_SHIFT))&LPC_DMA_XFERCFG7_RELOAD_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG7: SWTRIG Mask           */
#define LPC_DMA_XFERCFG7_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG7: SWTRIG Position       */
#define LPC_DMA_XFERCFG7_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_SWTRIG_SHIFT))&LPC_DMA_XFERCFG7_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG7: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG7_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG7: CLRTRIG Position      */
#define LPC_DMA_XFERCFG7_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG7_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG7: SETINTA Mask          */
#define LPC_DMA_XFERCFG7_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG7: SETINTA Position      */
#define LPC_DMA_XFERCFG7_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_SETINTA_SHIFT))&LPC_DMA_XFERCFG7_SETINTA_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG7: SETINTB Mask          */
#define LPC_DMA_XFERCFG7_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG7: SETINTB Position      */
#define LPC_DMA_XFERCFG7_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_SETINTB_SHIFT))&LPC_DMA_XFERCFG7_SETINTB_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG7: WIDTH Mask            */
#define LPC_DMA_XFERCFG7_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG7: WIDTH Position        */
#define LPC_DMA_XFERCFG7_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_WIDTH_SHIFT))&LPC_DMA_XFERCFG7_WIDTH_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG7: SRCINC Mask           */
#define LPC_DMA_XFERCFG7_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG7: SRCINC Position       */
#define LPC_DMA_XFERCFG7_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_SRCINC_SHIFT))&LPC_DMA_XFERCFG7_SRCINC_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG7: DSTINC Mask           */
#define LPC_DMA_XFERCFG7_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG7: DSTINC Position       */
#define LPC_DMA_XFERCFG7_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_DSTINC_SHIFT))&LPC_DMA_XFERCFG7_DSTINC_MASK) /*!< LPC_DMA_XFERCFG7                        */
#define LPC_DMA_XFERCFG7_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG7: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG7_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG7: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG7_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG7_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG7_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG7                        */
/* ------- CFG8 Bit Fields                          ------ */
#define LPC_DMA_CFG8_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG8: PERIPHREQEN Mask          */
#define LPC_DMA_CFG8_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG8: PERIPHREQEN Position      */
#define LPC_DMA_CFG8_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_PERIPHREQEN_SHIFT))&LPC_DMA_CFG8_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG8                            */
#define LPC_DMA_CFG8_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG8: HWTRIGEN Mask             */
#define LPC_DMA_CFG8_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG8: HWTRIGEN Position         */
#define LPC_DMA_CFG8_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_HWTRIGEN_SHIFT))&LPC_DMA_CFG8_HWTRIGEN_MASK) /*!< LPC_DMA_CFG8                            */
#define LPC_DMA_CFG8_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG8: TRIGPOL Mask              */
#define LPC_DMA_CFG8_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG8: TRIGPOL Position          */
#define LPC_DMA_CFG8_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_TRIGPOL_SHIFT))&LPC_DMA_CFG8_TRIGPOL_MASK) /*!< LPC_DMA_CFG8                            */
#define LPC_DMA_CFG8_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG8: TRIGTYPE Mask             */
#define LPC_DMA_CFG8_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG8: TRIGTYPE Position         */
#define LPC_DMA_CFG8_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_TRIGTYPE_SHIFT))&LPC_DMA_CFG8_TRIGTYPE_MASK) /*!< LPC_DMA_CFG8                            */
#define LPC_DMA_CFG8_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG8: TRIGBURST Mask            */
#define LPC_DMA_CFG8_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG8: TRIGBURST Position        */
#define LPC_DMA_CFG8_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_TRIGBURST_SHIFT))&LPC_DMA_CFG8_TRIGBURST_MASK) /*!< LPC_DMA_CFG8                            */
#define LPC_DMA_CFG8_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG8: BURSTPOWER Mask           */
#define LPC_DMA_CFG8_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG8: BURSTPOWER Position       */
#define LPC_DMA_CFG8_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_BURSTPOWER_SHIFT))&LPC_DMA_CFG8_BURSTPOWER_MASK) /*!< LPC_DMA_CFG8                            */
#define LPC_DMA_CFG8_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG8: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG8_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG8: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG8_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG8_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG8                            */
#define LPC_DMA_CFG8_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG8: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG8_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG8: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG8_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG8_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG8                            */
#define LPC_DMA_CFG8_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG8: CHPRIORITY Mask           */
#define LPC_DMA_CFG8_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG8: CHPRIORITY Position       */
#define LPC_DMA_CFG8_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG8_CHPRIORITY_SHIFT))&LPC_DMA_CFG8_CHPRIORITY_MASK) /*!< LPC_DMA_CFG8                            */
/* ------- CTLSTAT8 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT8_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT8: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT8_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT8: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT8_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT8_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT8_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT8                        */
#define LPC_DMA_CTLSTAT8_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT8: TRIG Mask             */
#define LPC_DMA_CTLSTAT8_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT8: TRIG Position         */
#define LPC_DMA_CTLSTAT8_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT8_TRIG_SHIFT))&LPC_DMA_CTLSTAT8_TRIG_MASK) /*!< LPC_DMA_CTLSTAT8                        */
/* ------- XFERCFG8 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG8_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG8: CFGVALID Mask         */
#define LPC_DMA_XFERCFG8_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG8: CFGVALID Position     */
#define LPC_DMA_XFERCFG8_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_CFGVALID_SHIFT))&LPC_DMA_XFERCFG8_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG8: RELOAD Mask           */
#define LPC_DMA_XFERCFG8_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG8: RELOAD Position       */
#define LPC_DMA_XFERCFG8_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_RELOAD_SHIFT))&LPC_DMA_XFERCFG8_RELOAD_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG8: SWTRIG Mask           */
#define LPC_DMA_XFERCFG8_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG8: SWTRIG Position       */
#define LPC_DMA_XFERCFG8_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_SWTRIG_SHIFT))&LPC_DMA_XFERCFG8_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG8: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG8_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG8: CLRTRIG Position      */
#define LPC_DMA_XFERCFG8_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG8_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG8: SETINTA Mask          */
#define LPC_DMA_XFERCFG8_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG8: SETINTA Position      */
#define LPC_DMA_XFERCFG8_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_SETINTA_SHIFT))&LPC_DMA_XFERCFG8_SETINTA_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG8: SETINTB Mask          */
#define LPC_DMA_XFERCFG8_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG8: SETINTB Position      */
#define LPC_DMA_XFERCFG8_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_SETINTB_SHIFT))&LPC_DMA_XFERCFG8_SETINTB_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG8: WIDTH Mask            */
#define LPC_DMA_XFERCFG8_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG8: WIDTH Position        */
#define LPC_DMA_XFERCFG8_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_WIDTH_SHIFT))&LPC_DMA_XFERCFG8_WIDTH_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG8: SRCINC Mask           */
#define LPC_DMA_XFERCFG8_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG8: SRCINC Position       */
#define LPC_DMA_XFERCFG8_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_SRCINC_SHIFT))&LPC_DMA_XFERCFG8_SRCINC_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG8: DSTINC Mask           */
#define LPC_DMA_XFERCFG8_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG8: DSTINC Position       */
#define LPC_DMA_XFERCFG8_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_DSTINC_SHIFT))&LPC_DMA_XFERCFG8_DSTINC_MASK) /*!< LPC_DMA_XFERCFG8                        */
#define LPC_DMA_XFERCFG8_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG8: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG8_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG8: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG8_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG8_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG8_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG8                        */
/* ------- CFG9 Bit Fields                          ------ */
#define LPC_DMA_CFG9_PERIPHREQEN_MASK            (0x1U)                                              /*!< LPC_DMA_CFG9: PERIPHREQEN Mask          */
#define LPC_DMA_CFG9_PERIPHREQEN_SHIFT           (0U)                                                /*!< LPC_DMA_CFG9: PERIPHREQEN Position      */
#define LPC_DMA_CFG9_PERIPHREQEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_PERIPHREQEN_SHIFT))&LPC_DMA_CFG9_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG9                            */
#define LPC_DMA_CFG9_HWTRIGEN_MASK               (0x2U)                                              /*!< LPC_DMA_CFG9: HWTRIGEN Mask             */
#define LPC_DMA_CFG9_HWTRIGEN_SHIFT              (1U)                                                /*!< LPC_DMA_CFG9: HWTRIGEN Position         */
#define LPC_DMA_CFG9_HWTRIGEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_HWTRIGEN_SHIFT))&LPC_DMA_CFG9_HWTRIGEN_MASK) /*!< LPC_DMA_CFG9                            */
#define LPC_DMA_CFG9_TRIGPOL_MASK                (0x10U)                                             /*!< LPC_DMA_CFG9: TRIGPOL Mask              */
#define LPC_DMA_CFG9_TRIGPOL_SHIFT               (4U)                                                /*!< LPC_DMA_CFG9: TRIGPOL Position          */
#define LPC_DMA_CFG9_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_TRIGPOL_SHIFT))&LPC_DMA_CFG9_TRIGPOL_MASK) /*!< LPC_DMA_CFG9                            */
#define LPC_DMA_CFG9_TRIGTYPE_MASK               (0x20U)                                             /*!< LPC_DMA_CFG9: TRIGTYPE Mask             */
#define LPC_DMA_CFG9_TRIGTYPE_SHIFT              (5U)                                                /*!< LPC_DMA_CFG9: TRIGTYPE Position         */
#define LPC_DMA_CFG9_TRIGTYPE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_TRIGTYPE_SHIFT))&LPC_DMA_CFG9_TRIGTYPE_MASK) /*!< LPC_DMA_CFG9                            */
#define LPC_DMA_CFG9_TRIGBURST_MASK              (0x40U)                                             /*!< LPC_DMA_CFG9: TRIGBURST Mask            */
#define LPC_DMA_CFG9_TRIGBURST_SHIFT             (6U)                                                /*!< LPC_DMA_CFG9: TRIGBURST Position        */
#define LPC_DMA_CFG9_TRIGBURST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_TRIGBURST_SHIFT))&LPC_DMA_CFG9_TRIGBURST_MASK) /*!< LPC_DMA_CFG9                            */
#define LPC_DMA_CFG9_BURSTPOWER_MASK             (0xF00U)                                            /*!< LPC_DMA_CFG9: BURSTPOWER Mask           */
#define LPC_DMA_CFG9_BURSTPOWER_SHIFT            (8U)                                                /*!< LPC_DMA_CFG9: BURSTPOWER Position       */
#define LPC_DMA_CFG9_BURSTPOWER(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_BURSTPOWER_SHIFT))&LPC_DMA_CFG9_BURSTPOWER_MASK) /*!< LPC_DMA_CFG9                            */
#define LPC_DMA_CFG9_SRCBURSTWRAP_MASK           (0x4000U)                                           /*!< LPC_DMA_CFG9: SRCBURSTWRAP Mask         */
#define LPC_DMA_CFG9_SRCBURSTWRAP_SHIFT          (14U)                                               /*!< LPC_DMA_CFG9: SRCBURSTWRAP Position     */
#define LPC_DMA_CFG9_SRCBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG9_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG9                            */
#define LPC_DMA_CFG9_DSTBURSTWRAP_MASK           (0x8000U)                                           /*!< LPC_DMA_CFG9: DSTBURSTWRAP Mask         */
#define LPC_DMA_CFG9_DSTBURSTWRAP_SHIFT          (15U)                                               /*!< LPC_DMA_CFG9: DSTBURSTWRAP Position     */
#define LPC_DMA_CFG9_DSTBURSTWRAP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG9_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG9                            */
#define LPC_DMA_CFG9_CHPRIORITY_MASK             (0x70000U)                                          /*!< LPC_DMA_CFG9: CHPRIORITY Mask           */
#define LPC_DMA_CFG9_CHPRIORITY_SHIFT            (16U)                                               /*!< LPC_DMA_CFG9: CHPRIORITY Position       */
#define LPC_DMA_CFG9_CHPRIORITY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG9_CHPRIORITY_SHIFT))&LPC_DMA_CFG9_CHPRIORITY_MASK) /*!< LPC_DMA_CFG9                            */
/* ------- CTLSTAT9 Bit Fields                      ------ */
#define LPC_DMA_CTLSTAT9_VALIDPENDING_MASK       (0x1U)                                              /*!< LPC_DMA_CTLSTAT9: VALIDPENDING Mask     */
#define LPC_DMA_CTLSTAT9_VALIDPENDING_SHIFT      (0U)                                                /*!< LPC_DMA_CTLSTAT9: VALIDPENDING Position */
#define LPC_DMA_CTLSTAT9_VALIDPENDING(x)         (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT9_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT9_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT9                        */
#define LPC_DMA_CTLSTAT9_TRIG_MASK               (0x4U)                                              /*!< LPC_DMA_CTLSTAT9: TRIG Mask             */
#define LPC_DMA_CTLSTAT9_TRIG_SHIFT              (2U)                                                /*!< LPC_DMA_CTLSTAT9: TRIG Position         */
#define LPC_DMA_CTLSTAT9_TRIG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT9_TRIG_SHIFT))&LPC_DMA_CTLSTAT9_TRIG_MASK) /*!< LPC_DMA_CTLSTAT9                        */
/* ------- XFERCFG9 Bit Fields                      ------ */
#define LPC_DMA_XFERCFG9_CFGVALID_MASK           (0x1U)                                              /*!< LPC_DMA_XFERCFG9: CFGVALID Mask         */
#define LPC_DMA_XFERCFG9_CFGVALID_SHIFT          (0U)                                                /*!< LPC_DMA_XFERCFG9: CFGVALID Position     */
#define LPC_DMA_XFERCFG9_CFGVALID(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_CFGVALID_SHIFT))&LPC_DMA_XFERCFG9_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_RELOAD_MASK             (0x2U)                                              /*!< LPC_DMA_XFERCFG9: RELOAD Mask           */
#define LPC_DMA_XFERCFG9_RELOAD_SHIFT            (1U)                                                /*!< LPC_DMA_XFERCFG9: RELOAD Position       */
#define LPC_DMA_XFERCFG9_RELOAD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_RELOAD_SHIFT))&LPC_DMA_XFERCFG9_RELOAD_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_SWTRIG_MASK             (0x4U)                                              /*!< LPC_DMA_XFERCFG9: SWTRIG Mask           */
#define LPC_DMA_XFERCFG9_SWTRIG_SHIFT            (2U)                                                /*!< LPC_DMA_XFERCFG9: SWTRIG Position       */
#define LPC_DMA_XFERCFG9_SWTRIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_SWTRIG_SHIFT))&LPC_DMA_XFERCFG9_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_CLRTRIG_MASK            (0x8U)                                              /*!< LPC_DMA_XFERCFG9: CLRTRIG Mask          */
#define LPC_DMA_XFERCFG9_CLRTRIG_SHIFT           (3U)                                                /*!< LPC_DMA_XFERCFG9: CLRTRIG Position      */
#define LPC_DMA_XFERCFG9_CLRTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG9_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_SETINTA_MASK            (0x10U)                                             /*!< LPC_DMA_XFERCFG9: SETINTA Mask          */
#define LPC_DMA_XFERCFG9_SETINTA_SHIFT           (4U)                                                /*!< LPC_DMA_XFERCFG9: SETINTA Position      */
#define LPC_DMA_XFERCFG9_SETINTA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_SETINTA_SHIFT))&LPC_DMA_XFERCFG9_SETINTA_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_SETINTB_MASK            (0x20U)                                             /*!< LPC_DMA_XFERCFG9: SETINTB Mask          */
#define LPC_DMA_XFERCFG9_SETINTB_SHIFT           (5U)                                                /*!< LPC_DMA_XFERCFG9: SETINTB Position      */
#define LPC_DMA_XFERCFG9_SETINTB(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_SETINTB_SHIFT))&LPC_DMA_XFERCFG9_SETINTB_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_WIDTH_MASK              (0x300U)                                            /*!< LPC_DMA_XFERCFG9: WIDTH Mask            */
#define LPC_DMA_XFERCFG9_WIDTH_SHIFT             (8U)                                                /*!< LPC_DMA_XFERCFG9: WIDTH Position        */
#define LPC_DMA_XFERCFG9_WIDTH(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_WIDTH_SHIFT))&LPC_DMA_XFERCFG9_WIDTH_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_SRCINC_MASK             (0x3000U)                                           /*!< LPC_DMA_XFERCFG9: SRCINC Mask           */
#define LPC_DMA_XFERCFG9_SRCINC_SHIFT            (12U)                                               /*!< LPC_DMA_XFERCFG9: SRCINC Position       */
#define LPC_DMA_XFERCFG9_SRCINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_SRCINC_SHIFT))&LPC_DMA_XFERCFG9_SRCINC_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_DSTINC_MASK             (0xC000U)                                           /*!< LPC_DMA_XFERCFG9: DSTINC Mask           */
#define LPC_DMA_XFERCFG9_DSTINC_SHIFT            (14U)                                               /*!< LPC_DMA_XFERCFG9: DSTINC Position       */
#define LPC_DMA_XFERCFG9_DSTINC(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_DSTINC_SHIFT))&LPC_DMA_XFERCFG9_DSTINC_MASK) /*!< LPC_DMA_XFERCFG9                        */
#define LPC_DMA_XFERCFG9_XFERCOUNT_MASK          (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG9: XFERCOUNT Mask        */
#define LPC_DMA_XFERCFG9_XFERCOUNT_SHIFT         (16U)                                               /*!< LPC_DMA_XFERCFG9: XFERCOUNT Position    */
#define LPC_DMA_XFERCFG9_XFERCOUNT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG9_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG9_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG9                        */
/* ------- CFG10 Bit Fields                         ------ */
#define LPC_DMA_CFG10_PERIPHREQEN_MASK           (0x1U)                                              /*!< LPC_DMA_CFG10: PERIPHREQEN Mask         */
#define LPC_DMA_CFG10_PERIPHREQEN_SHIFT          (0U)                                                /*!< LPC_DMA_CFG10: PERIPHREQEN Position     */
#define LPC_DMA_CFG10_PERIPHREQEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_PERIPHREQEN_SHIFT))&LPC_DMA_CFG10_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG10                           */
#define LPC_DMA_CFG10_HWTRIGEN_MASK              (0x2U)                                              /*!< LPC_DMA_CFG10: HWTRIGEN Mask            */
#define LPC_DMA_CFG10_HWTRIGEN_SHIFT             (1U)                                                /*!< LPC_DMA_CFG10: HWTRIGEN Position        */
#define LPC_DMA_CFG10_HWTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_HWTRIGEN_SHIFT))&LPC_DMA_CFG10_HWTRIGEN_MASK) /*!< LPC_DMA_CFG10                           */
#define LPC_DMA_CFG10_TRIGPOL_MASK               (0x10U)                                             /*!< LPC_DMA_CFG10: TRIGPOL Mask             */
#define LPC_DMA_CFG10_TRIGPOL_SHIFT              (4U)                                                /*!< LPC_DMA_CFG10: TRIGPOL Position         */
#define LPC_DMA_CFG10_TRIGPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_TRIGPOL_SHIFT))&LPC_DMA_CFG10_TRIGPOL_MASK) /*!< LPC_DMA_CFG10                           */
#define LPC_DMA_CFG10_TRIGTYPE_MASK              (0x20U)                                             /*!< LPC_DMA_CFG10: TRIGTYPE Mask            */
#define LPC_DMA_CFG10_TRIGTYPE_SHIFT             (5U)                                                /*!< LPC_DMA_CFG10: TRIGTYPE Position        */
#define LPC_DMA_CFG10_TRIGTYPE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_TRIGTYPE_SHIFT))&LPC_DMA_CFG10_TRIGTYPE_MASK) /*!< LPC_DMA_CFG10                           */
#define LPC_DMA_CFG10_TRIGBURST_MASK             (0x40U)                                             /*!< LPC_DMA_CFG10: TRIGBURST Mask           */
#define LPC_DMA_CFG10_TRIGBURST_SHIFT            (6U)                                                /*!< LPC_DMA_CFG10: TRIGBURST Position       */
#define LPC_DMA_CFG10_TRIGBURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_TRIGBURST_SHIFT))&LPC_DMA_CFG10_TRIGBURST_MASK) /*!< LPC_DMA_CFG10                           */
#define LPC_DMA_CFG10_BURSTPOWER_MASK            (0xF00U)                                            /*!< LPC_DMA_CFG10: BURSTPOWER Mask          */
#define LPC_DMA_CFG10_BURSTPOWER_SHIFT           (8U)                                                /*!< LPC_DMA_CFG10: BURSTPOWER Position      */
#define LPC_DMA_CFG10_BURSTPOWER(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_BURSTPOWER_SHIFT))&LPC_DMA_CFG10_BURSTPOWER_MASK) /*!< LPC_DMA_CFG10                           */
#define LPC_DMA_CFG10_SRCBURSTWRAP_MASK          (0x4000U)                                           /*!< LPC_DMA_CFG10: SRCBURSTWRAP Mask        */
#define LPC_DMA_CFG10_SRCBURSTWRAP_SHIFT         (14U)                                               /*!< LPC_DMA_CFG10: SRCBURSTWRAP Position    */
#define LPC_DMA_CFG10_SRCBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG10_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG10                           */
#define LPC_DMA_CFG10_DSTBURSTWRAP_MASK          (0x8000U)                                           /*!< LPC_DMA_CFG10: DSTBURSTWRAP Mask        */
#define LPC_DMA_CFG10_DSTBURSTWRAP_SHIFT         (15U)                                               /*!< LPC_DMA_CFG10: DSTBURSTWRAP Position    */
#define LPC_DMA_CFG10_DSTBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG10_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG10                           */
#define LPC_DMA_CFG10_CHPRIORITY_MASK            (0x70000U)                                          /*!< LPC_DMA_CFG10: CHPRIORITY Mask          */
#define LPC_DMA_CFG10_CHPRIORITY_SHIFT           (16U)                                               /*!< LPC_DMA_CFG10: CHPRIORITY Position      */
#define LPC_DMA_CFG10_CHPRIORITY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG10_CHPRIORITY_SHIFT))&LPC_DMA_CFG10_CHPRIORITY_MASK) /*!< LPC_DMA_CFG10                           */
/* ------- CTLSTAT10 Bit Fields                     ------ */
#define LPC_DMA_CTLSTAT10_VALIDPENDING_MASK      (0x1U)                                              /*!< LPC_DMA_CTLSTAT10: VALIDPENDING Mask    */
#define LPC_DMA_CTLSTAT10_VALIDPENDING_SHIFT     (0U)                                                /*!< LPC_DMA_CTLSTAT10: VALIDPENDING Position*/
#define LPC_DMA_CTLSTAT10_VALIDPENDING(x)        (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT10_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT10_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT10                       */
#define LPC_DMA_CTLSTAT10_TRIG_MASK              (0x4U)                                              /*!< LPC_DMA_CTLSTAT10: TRIG Mask            */
#define LPC_DMA_CTLSTAT10_TRIG_SHIFT             (2U)                                                /*!< LPC_DMA_CTLSTAT10: TRIG Position        */
#define LPC_DMA_CTLSTAT10_TRIG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT10_TRIG_SHIFT))&LPC_DMA_CTLSTAT10_TRIG_MASK) /*!< LPC_DMA_CTLSTAT10                       */
/* ------- XFERCFG10 Bit Fields                     ------ */
#define LPC_DMA_XFERCFG10_CFGVALID_MASK          (0x1U)                                              /*!< LPC_DMA_XFERCFG10: CFGVALID Mask        */
#define LPC_DMA_XFERCFG10_CFGVALID_SHIFT         (0U)                                                /*!< LPC_DMA_XFERCFG10: CFGVALID Position    */
#define LPC_DMA_XFERCFG10_CFGVALID(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_CFGVALID_SHIFT))&LPC_DMA_XFERCFG10_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_RELOAD_MASK            (0x2U)                                              /*!< LPC_DMA_XFERCFG10: RELOAD Mask          */
#define LPC_DMA_XFERCFG10_RELOAD_SHIFT           (1U)                                                /*!< LPC_DMA_XFERCFG10: RELOAD Position      */
#define LPC_DMA_XFERCFG10_RELOAD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_RELOAD_SHIFT))&LPC_DMA_XFERCFG10_RELOAD_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_SWTRIG_MASK            (0x4U)                                              /*!< LPC_DMA_XFERCFG10: SWTRIG Mask          */
#define LPC_DMA_XFERCFG10_SWTRIG_SHIFT           (2U)                                                /*!< LPC_DMA_XFERCFG10: SWTRIG Position      */
#define LPC_DMA_XFERCFG10_SWTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_SWTRIG_SHIFT))&LPC_DMA_XFERCFG10_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_CLRTRIG_MASK           (0x8U)                                              /*!< LPC_DMA_XFERCFG10: CLRTRIG Mask         */
#define LPC_DMA_XFERCFG10_CLRTRIG_SHIFT          (3U)                                                /*!< LPC_DMA_XFERCFG10: CLRTRIG Position     */
#define LPC_DMA_XFERCFG10_CLRTRIG(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG10_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_SETINTA_MASK           (0x10U)                                             /*!< LPC_DMA_XFERCFG10: SETINTA Mask         */
#define LPC_DMA_XFERCFG10_SETINTA_SHIFT          (4U)                                                /*!< LPC_DMA_XFERCFG10: SETINTA Position     */
#define LPC_DMA_XFERCFG10_SETINTA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_SETINTA_SHIFT))&LPC_DMA_XFERCFG10_SETINTA_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_SETINTB_MASK           (0x20U)                                             /*!< LPC_DMA_XFERCFG10: SETINTB Mask         */
#define LPC_DMA_XFERCFG10_SETINTB_SHIFT          (5U)                                                /*!< LPC_DMA_XFERCFG10: SETINTB Position     */
#define LPC_DMA_XFERCFG10_SETINTB(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_SETINTB_SHIFT))&LPC_DMA_XFERCFG10_SETINTB_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_WIDTH_MASK             (0x300U)                                            /*!< LPC_DMA_XFERCFG10: WIDTH Mask           */
#define LPC_DMA_XFERCFG10_WIDTH_SHIFT            (8U)                                                /*!< LPC_DMA_XFERCFG10: WIDTH Position       */
#define LPC_DMA_XFERCFG10_WIDTH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_WIDTH_SHIFT))&LPC_DMA_XFERCFG10_WIDTH_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_SRCINC_MASK            (0x3000U)                                           /*!< LPC_DMA_XFERCFG10: SRCINC Mask          */
#define LPC_DMA_XFERCFG10_SRCINC_SHIFT           (12U)                                               /*!< LPC_DMA_XFERCFG10: SRCINC Position      */
#define LPC_DMA_XFERCFG10_SRCINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_SRCINC_SHIFT))&LPC_DMA_XFERCFG10_SRCINC_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_DSTINC_MASK            (0xC000U)                                           /*!< LPC_DMA_XFERCFG10: DSTINC Mask          */
#define LPC_DMA_XFERCFG10_DSTINC_SHIFT           (14U)                                               /*!< LPC_DMA_XFERCFG10: DSTINC Position      */
#define LPC_DMA_XFERCFG10_DSTINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_DSTINC_SHIFT))&LPC_DMA_XFERCFG10_DSTINC_MASK) /*!< LPC_DMA_XFERCFG10                       */
#define LPC_DMA_XFERCFG10_XFERCOUNT_MASK         (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG10: XFERCOUNT Mask       */
#define LPC_DMA_XFERCFG10_XFERCOUNT_SHIFT        (16U)                                               /*!< LPC_DMA_XFERCFG10: XFERCOUNT Position   */
#define LPC_DMA_XFERCFG10_XFERCOUNT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG10_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG10_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG10                       */
/* ------- CFG11 Bit Fields                         ------ */
#define LPC_DMA_CFG11_PERIPHREQEN_MASK           (0x1U)                                              /*!< LPC_DMA_CFG11: PERIPHREQEN Mask         */
#define LPC_DMA_CFG11_PERIPHREQEN_SHIFT          (0U)                                                /*!< LPC_DMA_CFG11: PERIPHREQEN Position     */
#define LPC_DMA_CFG11_PERIPHREQEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_PERIPHREQEN_SHIFT))&LPC_DMA_CFG11_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG11                           */
#define LPC_DMA_CFG11_HWTRIGEN_MASK              (0x2U)                                              /*!< LPC_DMA_CFG11: HWTRIGEN Mask            */
#define LPC_DMA_CFG11_HWTRIGEN_SHIFT             (1U)                                                /*!< LPC_DMA_CFG11: HWTRIGEN Position        */
#define LPC_DMA_CFG11_HWTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_HWTRIGEN_SHIFT))&LPC_DMA_CFG11_HWTRIGEN_MASK) /*!< LPC_DMA_CFG11                           */
#define LPC_DMA_CFG11_TRIGPOL_MASK               (0x10U)                                             /*!< LPC_DMA_CFG11: TRIGPOL Mask             */
#define LPC_DMA_CFG11_TRIGPOL_SHIFT              (4U)                                                /*!< LPC_DMA_CFG11: TRIGPOL Position         */
#define LPC_DMA_CFG11_TRIGPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_TRIGPOL_SHIFT))&LPC_DMA_CFG11_TRIGPOL_MASK) /*!< LPC_DMA_CFG11                           */
#define LPC_DMA_CFG11_TRIGTYPE_MASK              (0x20U)                                             /*!< LPC_DMA_CFG11: TRIGTYPE Mask            */
#define LPC_DMA_CFG11_TRIGTYPE_SHIFT             (5U)                                                /*!< LPC_DMA_CFG11: TRIGTYPE Position        */
#define LPC_DMA_CFG11_TRIGTYPE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_TRIGTYPE_SHIFT))&LPC_DMA_CFG11_TRIGTYPE_MASK) /*!< LPC_DMA_CFG11                           */
#define LPC_DMA_CFG11_TRIGBURST_MASK             (0x40U)                                             /*!< LPC_DMA_CFG11: TRIGBURST Mask           */
#define LPC_DMA_CFG11_TRIGBURST_SHIFT            (6U)                                                /*!< LPC_DMA_CFG11: TRIGBURST Position       */
#define LPC_DMA_CFG11_TRIGBURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_TRIGBURST_SHIFT))&LPC_DMA_CFG11_TRIGBURST_MASK) /*!< LPC_DMA_CFG11                           */
#define LPC_DMA_CFG11_BURSTPOWER_MASK            (0xF00U)                                            /*!< LPC_DMA_CFG11: BURSTPOWER Mask          */
#define LPC_DMA_CFG11_BURSTPOWER_SHIFT           (8U)                                                /*!< LPC_DMA_CFG11: BURSTPOWER Position      */
#define LPC_DMA_CFG11_BURSTPOWER(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_BURSTPOWER_SHIFT))&LPC_DMA_CFG11_BURSTPOWER_MASK) /*!< LPC_DMA_CFG11                           */
#define LPC_DMA_CFG11_SRCBURSTWRAP_MASK          (0x4000U)                                           /*!< LPC_DMA_CFG11: SRCBURSTWRAP Mask        */
#define LPC_DMA_CFG11_SRCBURSTWRAP_SHIFT         (14U)                                               /*!< LPC_DMA_CFG11: SRCBURSTWRAP Position    */
#define LPC_DMA_CFG11_SRCBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG11_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG11                           */
#define LPC_DMA_CFG11_DSTBURSTWRAP_MASK          (0x8000U)                                           /*!< LPC_DMA_CFG11: DSTBURSTWRAP Mask        */
#define LPC_DMA_CFG11_DSTBURSTWRAP_SHIFT         (15U)                                               /*!< LPC_DMA_CFG11: DSTBURSTWRAP Position    */
#define LPC_DMA_CFG11_DSTBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG11_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG11                           */
#define LPC_DMA_CFG11_CHPRIORITY_MASK            (0x70000U)                                          /*!< LPC_DMA_CFG11: CHPRIORITY Mask          */
#define LPC_DMA_CFG11_CHPRIORITY_SHIFT           (16U)                                               /*!< LPC_DMA_CFG11: CHPRIORITY Position      */
#define LPC_DMA_CFG11_CHPRIORITY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG11_CHPRIORITY_SHIFT))&LPC_DMA_CFG11_CHPRIORITY_MASK) /*!< LPC_DMA_CFG11                           */
/* ------- CTLSTAT11 Bit Fields                     ------ */
#define LPC_DMA_CTLSTAT11_VALIDPENDING_MASK      (0x1U)                                              /*!< LPC_DMA_CTLSTAT11: VALIDPENDING Mask    */
#define LPC_DMA_CTLSTAT11_VALIDPENDING_SHIFT     (0U)                                                /*!< LPC_DMA_CTLSTAT11: VALIDPENDING Position*/
#define LPC_DMA_CTLSTAT11_VALIDPENDING(x)        (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT11_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT11_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT11                       */
#define LPC_DMA_CTLSTAT11_TRIG_MASK              (0x4U)                                              /*!< LPC_DMA_CTLSTAT11: TRIG Mask            */
#define LPC_DMA_CTLSTAT11_TRIG_SHIFT             (2U)                                                /*!< LPC_DMA_CTLSTAT11: TRIG Position        */
#define LPC_DMA_CTLSTAT11_TRIG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT11_TRIG_SHIFT))&LPC_DMA_CTLSTAT11_TRIG_MASK) /*!< LPC_DMA_CTLSTAT11                       */
/* ------- XFERCFG11 Bit Fields                     ------ */
#define LPC_DMA_XFERCFG11_CFGVALID_MASK          (0x1U)                                              /*!< LPC_DMA_XFERCFG11: CFGVALID Mask        */
#define LPC_DMA_XFERCFG11_CFGVALID_SHIFT         (0U)                                                /*!< LPC_DMA_XFERCFG11: CFGVALID Position    */
#define LPC_DMA_XFERCFG11_CFGVALID(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_CFGVALID_SHIFT))&LPC_DMA_XFERCFG11_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_RELOAD_MASK            (0x2U)                                              /*!< LPC_DMA_XFERCFG11: RELOAD Mask          */
#define LPC_DMA_XFERCFG11_RELOAD_SHIFT           (1U)                                                /*!< LPC_DMA_XFERCFG11: RELOAD Position      */
#define LPC_DMA_XFERCFG11_RELOAD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_RELOAD_SHIFT))&LPC_DMA_XFERCFG11_RELOAD_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_SWTRIG_MASK            (0x4U)                                              /*!< LPC_DMA_XFERCFG11: SWTRIG Mask          */
#define LPC_DMA_XFERCFG11_SWTRIG_SHIFT           (2U)                                                /*!< LPC_DMA_XFERCFG11: SWTRIG Position      */
#define LPC_DMA_XFERCFG11_SWTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_SWTRIG_SHIFT))&LPC_DMA_XFERCFG11_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_CLRTRIG_MASK           (0x8U)                                              /*!< LPC_DMA_XFERCFG11: CLRTRIG Mask         */
#define LPC_DMA_XFERCFG11_CLRTRIG_SHIFT          (3U)                                                /*!< LPC_DMA_XFERCFG11: CLRTRIG Position     */
#define LPC_DMA_XFERCFG11_CLRTRIG(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG11_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_SETINTA_MASK           (0x10U)                                             /*!< LPC_DMA_XFERCFG11: SETINTA Mask         */
#define LPC_DMA_XFERCFG11_SETINTA_SHIFT          (4U)                                                /*!< LPC_DMA_XFERCFG11: SETINTA Position     */
#define LPC_DMA_XFERCFG11_SETINTA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_SETINTA_SHIFT))&LPC_DMA_XFERCFG11_SETINTA_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_SETINTB_MASK           (0x20U)                                             /*!< LPC_DMA_XFERCFG11: SETINTB Mask         */
#define LPC_DMA_XFERCFG11_SETINTB_SHIFT          (5U)                                                /*!< LPC_DMA_XFERCFG11: SETINTB Position     */
#define LPC_DMA_XFERCFG11_SETINTB(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_SETINTB_SHIFT))&LPC_DMA_XFERCFG11_SETINTB_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_WIDTH_MASK             (0x300U)                                            /*!< LPC_DMA_XFERCFG11: WIDTH Mask           */
#define LPC_DMA_XFERCFG11_WIDTH_SHIFT            (8U)                                                /*!< LPC_DMA_XFERCFG11: WIDTH Position       */
#define LPC_DMA_XFERCFG11_WIDTH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_WIDTH_SHIFT))&LPC_DMA_XFERCFG11_WIDTH_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_SRCINC_MASK            (0x3000U)                                           /*!< LPC_DMA_XFERCFG11: SRCINC Mask          */
#define LPC_DMA_XFERCFG11_SRCINC_SHIFT           (12U)                                               /*!< LPC_DMA_XFERCFG11: SRCINC Position      */
#define LPC_DMA_XFERCFG11_SRCINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_SRCINC_SHIFT))&LPC_DMA_XFERCFG11_SRCINC_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_DSTINC_MASK            (0xC000U)                                           /*!< LPC_DMA_XFERCFG11: DSTINC Mask          */
#define LPC_DMA_XFERCFG11_DSTINC_SHIFT           (14U)                                               /*!< LPC_DMA_XFERCFG11: DSTINC Position      */
#define LPC_DMA_XFERCFG11_DSTINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_DSTINC_SHIFT))&LPC_DMA_XFERCFG11_DSTINC_MASK) /*!< LPC_DMA_XFERCFG11                       */
#define LPC_DMA_XFERCFG11_XFERCOUNT_MASK         (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG11: XFERCOUNT Mask       */
#define LPC_DMA_XFERCFG11_XFERCOUNT_SHIFT        (16U)                                               /*!< LPC_DMA_XFERCFG11: XFERCOUNT Position   */
#define LPC_DMA_XFERCFG11_XFERCOUNT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG11_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG11_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG11                       */
/* ------- CFG12 Bit Fields                         ------ */
#define LPC_DMA_CFG12_PERIPHREQEN_MASK           (0x1U)                                              /*!< LPC_DMA_CFG12: PERIPHREQEN Mask         */
#define LPC_DMA_CFG12_PERIPHREQEN_SHIFT          (0U)                                                /*!< LPC_DMA_CFG12: PERIPHREQEN Position     */
#define LPC_DMA_CFG12_PERIPHREQEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_PERIPHREQEN_SHIFT))&LPC_DMA_CFG12_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG12                           */
#define LPC_DMA_CFG12_HWTRIGEN_MASK              (0x2U)                                              /*!< LPC_DMA_CFG12: HWTRIGEN Mask            */
#define LPC_DMA_CFG12_HWTRIGEN_SHIFT             (1U)                                                /*!< LPC_DMA_CFG12: HWTRIGEN Position        */
#define LPC_DMA_CFG12_HWTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_HWTRIGEN_SHIFT))&LPC_DMA_CFG12_HWTRIGEN_MASK) /*!< LPC_DMA_CFG12                           */
#define LPC_DMA_CFG12_TRIGPOL_MASK               (0x10U)                                             /*!< LPC_DMA_CFG12: TRIGPOL Mask             */
#define LPC_DMA_CFG12_TRIGPOL_SHIFT              (4U)                                                /*!< LPC_DMA_CFG12: TRIGPOL Position         */
#define LPC_DMA_CFG12_TRIGPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_TRIGPOL_SHIFT))&LPC_DMA_CFG12_TRIGPOL_MASK) /*!< LPC_DMA_CFG12                           */
#define LPC_DMA_CFG12_TRIGTYPE_MASK              (0x20U)                                             /*!< LPC_DMA_CFG12: TRIGTYPE Mask            */
#define LPC_DMA_CFG12_TRIGTYPE_SHIFT             (5U)                                                /*!< LPC_DMA_CFG12: TRIGTYPE Position        */
#define LPC_DMA_CFG12_TRIGTYPE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_TRIGTYPE_SHIFT))&LPC_DMA_CFG12_TRIGTYPE_MASK) /*!< LPC_DMA_CFG12                           */
#define LPC_DMA_CFG12_TRIGBURST_MASK             (0x40U)                                             /*!< LPC_DMA_CFG12: TRIGBURST Mask           */
#define LPC_DMA_CFG12_TRIGBURST_SHIFT            (6U)                                                /*!< LPC_DMA_CFG12: TRIGBURST Position       */
#define LPC_DMA_CFG12_TRIGBURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_TRIGBURST_SHIFT))&LPC_DMA_CFG12_TRIGBURST_MASK) /*!< LPC_DMA_CFG12                           */
#define LPC_DMA_CFG12_BURSTPOWER_MASK            (0xF00U)                                            /*!< LPC_DMA_CFG12: BURSTPOWER Mask          */
#define LPC_DMA_CFG12_BURSTPOWER_SHIFT           (8U)                                                /*!< LPC_DMA_CFG12: BURSTPOWER Position      */
#define LPC_DMA_CFG12_BURSTPOWER(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_BURSTPOWER_SHIFT))&LPC_DMA_CFG12_BURSTPOWER_MASK) /*!< LPC_DMA_CFG12                           */
#define LPC_DMA_CFG12_SRCBURSTWRAP_MASK          (0x4000U)                                           /*!< LPC_DMA_CFG12: SRCBURSTWRAP Mask        */
#define LPC_DMA_CFG12_SRCBURSTWRAP_SHIFT         (14U)                                               /*!< LPC_DMA_CFG12: SRCBURSTWRAP Position    */
#define LPC_DMA_CFG12_SRCBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG12_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG12                           */
#define LPC_DMA_CFG12_DSTBURSTWRAP_MASK          (0x8000U)                                           /*!< LPC_DMA_CFG12: DSTBURSTWRAP Mask        */
#define LPC_DMA_CFG12_DSTBURSTWRAP_SHIFT         (15U)                                               /*!< LPC_DMA_CFG12: DSTBURSTWRAP Position    */
#define LPC_DMA_CFG12_DSTBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG12_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG12                           */
#define LPC_DMA_CFG12_CHPRIORITY_MASK            (0x70000U)                                          /*!< LPC_DMA_CFG12: CHPRIORITY Mask          */
#define LPC_DMA_CFG12_CHPRIORITY_SHIFT           (16U)                                               /*!< LPC_DMA_CFG12: CHPRIORITY Position      */
#define LPC_DMA_CFG12_CHPRIORITY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG12_CHPRIORITY_SHIFT))&LPC_DMA_CFG12_CHPRIORITY_MASK) /*!< LPC_DMA_CFG12                           */
/* ------- CTLSTAT12 Bit Fields                     ------ */
#define LPC_DMA_CTLSTAT12_VALIDPENDING_MASK      (0x1U)                                              /*!< LPC_DMA_CTLSTAT12: VALIDPENDING Mask    */
#define LPC_DMA_CTLSTAT12_VALIDPENDING_SHIFT     (0U)                                                /*!< LPC_DMA_CTLSTAT12: VALIDPENDING Position*/
#define LPC_DMA_CTLSTAT12_VALIDPENDING(x)        (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT12_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT12_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT12                       */
#define LPC_DMA_CTLSTAT12_TRIG_MASK              (0x4U)                                              /*!< LPC_DMA_CTLSTAT12: TRIG Mask            */
#define LPC_DMA_CTLSTAT12_TRIG_SHIFT             (2U)                                                /*!< LPC_DMA_CTLSTAT12: TRIG Position        */
#define LPC_DMA_CTLSTAT12_TRIG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT12_TRIG_SHIFT))&LPC_DMA_CTLSTAT12_TRIG_MASK) /*!< LPC_DMA_CTLSTAT12                       */
/* ------- XFERCFG12 Bit Fields                     ------ */
#define LPC_DMA_XFERCFG12_CFGVALID_MASK          (0x1U)                                              /*!< LPC_DMA_XFERCFG12: CFGVALID Mask        */
#define LPC_DMA_XFERCFG12_CFGVALID_SHIFT         (0U)                                                /*!< LPC_DMA_XFERCFG12: CFGVALID Position    */
#define LPC_DMA_XFERCFG12_CFGVALID(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_CFGVALID_SHIFT))&LPC_DMA_XFERCFG12_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_RELOAD_MASK            (0x2U)                                              /*!< LPC_DMA_XFERCFG12: RELOAD Mask          */
#define LPC_DMA_XFERCFG12_RELOAD_SHIFT           (1U)                                                /*!< LPC_DMA_XFERCFG12: RELOAD Position      */
#define LPC_DMA_XFERCFG12_RELOAD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_RELOAD_SHIFT))&LPC_DMA_XFERCFG12_RELOAD_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_SWTRIG_MASK            (0x4U)                                              /*!< LPC_DMA_XFERCFG12: SWTRIG Mask          */
#define LPC_DMA_XFERCFG12_SWTRIG_SHIFT           (2U)                                                /*!< LPC_DMA_XFERCFG12: SWTRIG Position      */
#define LPC_DMA_XFERCFG12_SWTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_SWTRIG_SHIFT))&LPC_DMA_XFERCFG12_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_CLRTRIG_MASK           (0x8U)                                              /*!< LPC_DMA_XFERCFG12: CLRTRIG Mask         */
#define LPC_DMA_XFERCFG12_CLRTRIG_SHIFT          (3U)                                                /*!< LPC_DMA_XFERCFG12: CLRTRIG Position     */
#define LPC_DMA_XFERCFG12_CLRTRIG(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG12_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_SETINTA_MASK           (0x10U)                                             /*!< LPC_DMA_XFERCFG12: SETINTA Mask         */
#define LPC_DMA_XFERCFG12_SETINTA_SHIFT          (4U)                                                /*!< LPC_DMA_XFERCFG12: SETINTA Position     */
#define LPC_DMA_XFERCFG12_SETINTA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_SETINTA_SHIFT))&LPC_DMA_XFERCFG12_SETINTA_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_SETINTB_MASK           (0x20U)                                             /*!< LPC_DMA_XFERCFG12: SETINTB Mask         */
#define LPC_DMA_XFERCFG12_SETINTB_SHIFT          (5U)                                                /*!< LPC_DMA_XFERCFG12: SETINTB Position     */
#define LPC_DMA_XFERCFG12_SETINTB(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_SETINTB_SHIFT))&LPC_DMA_XFERCFG12_SETINTB_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_WIDTH_MASK             (0x300U)                                            /*!< LPC_DMA_XFERCFG12: WIDTH Mask           */
#define LPC_DMA_XFERCFG12_WIDTH_SHIFT            (8U)                                                /*!< LPC_DMA_XFERCFG12: WIDTH Position       */
#define LPC_DMA_XFERCFG12_WIDTH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_WIDTH_SHIFT))&LPC_DMA_XFERCFG12_WIDTH_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_SRCINC_MASK            (0x3000U)                                           /*!< LPC_DMA_XFERCFG12: SRCINC Mask          */
#define LPC_DMA_XFERCFG12_SRCINC_SHIFT           (12U)                                               /*!< LPC_DMA_XFERCFG12: SRCINC Position      */
#define LPC_DMA_XFERCFG12_SRCINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_SRCINC_SHIFT))&LPC_DMA_XFERCFG12_SRCINC_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_DSTINC_MASK            (0xC000U)                                           /*!< LPC_DMA_XFERCFG12: DSTINC Mask          */
#define LPC_DMA_XFERCFG12_DSTINC_SHIFT           (14U)                                               /*!< LPC_DMA_XFERCFG12: DSTINC Position      */
#define LPC_DMA_XFERCFG12_DSTINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_DSTINC_SHIFT))&LPC_DMA_XFERCFG12_DSTINC_MASK) /*!< LPC_DMA_XFERCFG12                       */
#define LPC_DMA_XFERCFG12_XFERCOUNT_MASK         (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG12: XFERCOUNT Mask       */
#define LPC_DMA_XFERCFG12_XFERCOUNT_SHIFT        (16U)                                               /*!< LPC_DMA_XFERCFG12: XFERCOUNT Position   */
#define LPC_DMA_XFERCFG12_XFERCOUNT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG12_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG12_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG12                       */
/* ------- CFG13 Bit Fields                         ------ */
#define LPC_DMA_CFG13_PERIPHREQEN_MASK           (0x1U)                                              /*!< LPC_DMA_CFG13: PERIPHREQEN Mask         */
#define LPC_DMA_CFG13_PERIPHREQEN_SHIFT          (0U)                                                /*!< LPC_DMA_CFG13: PERIPHREQEN Position     */
#define LPC_DMA_CFG13_PERIPHREQEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_PERIPHREQEN_SHIFT))&LPC_DMA_CFG13_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG13                           */
#define LPC_DMA_CFG13_HWTRIGEN_MASK              (0x2U)                                              /*!< LPC_DMA_CFG13: HWTRIGEN Mask            */
#define LPC_DMA_CFG13_HWTRIGEN_SHIFT             (1U)                                                /*!< LPC_DMA_CFG13: HWTRIGEN Position        */
#define LPC_DMA_CFG13_HWTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_HWTRIGEN_SHIFT))&LPC_DMA_CFG13_HWTRIGEN_MASK) /*!< LPC_DMA_CFG13                           */
#define LPC_DMA_CFG13_TRIGPOL_MASK               (0x10U)                                             /*!< LPC_DMA_CFG13: TRIGPOL Mask             */
#define LPC_DMA_CFG13_TRIGPOL_SHIFT              (4U)                                                /*!< LPC_DMA_CFG13: TRIGPOL Position         */
#define LPC_DMA_CFG13_TRIGPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_TRIGPOL_SHIFT))&LPC_DMA_CFG13_TRIGPOL_MASK) /*!< LPC_DMA_CFG13                           */
#define LPC_DMA_CFG13_TRIGTYPE_MASK              (0x20U)                                             /*!< LPC_DMA_CFG13: TRIGTYPE Mask            */
#define LPC_DMA_CFG13_TRIGTYPE_SHIFT             (5U)                                                /*!< LPC_DMA_CFG13: TRIGTYPE Position        */
#define LPC_DMA_CFG13_TRIGTYPE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_TRIGTYPE_SHIFT))&LPC_DMA_CFG13_TRIGTYPE_MASK) /*!< LPC_DMA_CFG13                           */
#define LPC_DMA_CFG13_TRIGBURST_MASK             (0x40U)                                             /*!< LPC_DMA_CFG13: TRIGBURST Mask           */
#define LPC_DMA_CFG13_TRIGBURST_SHIFT            (6U)                                                /*!< LPC_DMA_CFG13: TRIGBURST Position       */
#define LPC_DMA_CFG13_TRIGBURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_TRIGBURST_SHIFT))&LPC_DMA_CFG13_TRIGBURST_MASK) /*!< LPC_DMA_CFG13                           */
#define LPC_DMA_CFG13_BURSTPOWER_MASK            (0xF00U)                                            /*!< LPC_DMA_CFG13: BURSTPOWER Mask          */
#define LPC_DMA_CFG13_BURSTPOWER_SHIFT           (8U)                                                /*!< LPC_DMA_CFG13: BURSTPOWER Position      */
#define LPC_DMA_CFG13_BURSTPOWER(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_BURSTPOWER_SHIFT))&LPC_DMA_CFG13_BURSTPOWER_MASK) /*!< LPC_DMA_CFG13                           */
#define LPC_DMA_CFG13_SRCBURSTWRAP_MASK          (0x4000U)                                           /*!< LPC_DMA_CFG13: SRCBURSTWRAP Mask        */
#define LPC_DMA_CFG13_SRCBURSTWRAP_SHIFT         (14U)                                               /*!< LPC_DMA_CFG13: SRCBURSTWRAP Position    */
#define LPC_DMA_CFG13_SRCBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG13_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG13                           */
#define LPC_DMA_CFG13_DSTBURSTWRAP_MASK          (0x8000U)                                           /*!< LPC_DMA_CFG13: DSTBURSTWRAP Mask        */
#define LPC_DMA_CFG13_DSTBURSTWRAP_SHIFT         (15U)                                               /*!< LPC_DMA_CFG13: DSTBURSTWRAP Position    */
#define LPC_DMA_CFG13_DSTBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG13_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG13                           */
#define LPC_DMA_CFG13_CHPRIORITY_MASK            (0x70000U)                                          /*!< LPC_DMA_CFG13: CHPRIORITY Mask          */
#define LPC_DMA_CFG13_CHPRIORITY_SHIFT           (16U)                                               /*!< LPC_DMA_CFG13: CHPRIORITY Position      */
#define LPC_DMA_CFG13_CHPRIORITY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG13_CHPRIORITY_SHIFT))&LPC_DMA_CFG13_CHPRIORITY_MASK) /*!< LPC_DMA_CFG13                           */
/* ------- CTLSTAT13 Bit Fields                     ------ */
#define LPC_DMA_CTLSTAT13_VALIDPENDING_MASK      (0x1U)                                              /*!< LPC_DMA_CTLSTAT13: VALIDPENDING Mask    */
#define LPC_DMA_CTLSTAT13_VALIDPENDING_SHIFT     (0U)                                                /*!< LPC_DMA_CTLSTAT13: VALIDPENDING Position*/
#define LPC_DMA_CTLSTAT13_VALIDPENDING(x)        (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT13_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT13_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT13                       */
#define LPC_DMA_CTLSTAT13_TRIG_MASK              (0x4U)                                              /*!< LPC_DMA_CTLSTAT13: TRIG Mask            */
#define LPC_DMA_CTLSTAT13_TRIG_SHIFT             (2U)                                                /*!< LPC_DMA_CTLSTAT13: TRIG Position        */
#define LPC_DMA_CTLSTAT13_TRIG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT13_TRIG_SHIFT))&LPC_DMA_CTLSTAT13_TRIG_MASK) /*!< LPC_DMA_CTLSTAT13                       */
/* ------- XFERCFG13 Bit Fields                     ------ */
#define LPC_DMA_XFERCFG13_CFGVALID_MASK          (0x1U)                                              /*!< LPC_DMA_XFERCFG13: CFGVALID Mask        */
#define LPC_DMA_XFERCFG13_CFGVALID_SHIFT         (0U)                                                /*!< LPC_DMA_XFERCFG13: CFGVALID Position    */
#define LPC_DMA_XFERCFG13_CFGVALID(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_CFGVALID_SHIFT))&LPC_DMA_XFERCFG13_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_RELOAD_MASK            (0x2U)                                              /*!< LPC_DMA_XFERCFG13: RELOAD Mask          */
#define LPC_DMA_XFERCFG13_RELOAD_SHIFT           (1U)                                                /*!< LPC_DMA_XFERCFG13: RELOAD Position      */
#define LPC_DMA_XFERCFG13_RELOAD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_RELOAD_SHIFT))&LPC_DMA_XFERCFG13_RELOAD_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_SWTRIG_MASK            (0x4U)                                              /*!< LPC_DMA_XFERCFG13: SWTRIG Mask          */
#define LPC_DMA_XFERCFG13_SWTRIG_SHIFT           (2U)                                                /*!< LPC_DMA_XFERCFG13: SWTRIG Position      */
#define LPC_DMA_XFERCFG13_SWTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_SWTRIG_SHIFT))&LPC_DMA_XFERCFG13_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_CLRTRIG_MASK           (0x8U)                                              /*!< LPC_DMA_XFERCFG13: CLRTRIG Mask         */
#define LPC_DMA_XFERCFG13_CLRTRIG_SHIFT          (3U)                                                /*!< LPC_DMA_XFERCFG13: CLRTRIG Position     */
#define LPC_DMA_XFERCFG13_CLRTRIG(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG13_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_SETINTA_MASK           (0x10U)                                             /*!< LPC_DMA_XFERCFG13: SETINTA Mask         */
#define LPC_DMA_XFERCFG13_SETINTA_SHIFT          (4U)                                                /*!< LPC_DMA_XFERCFG13: SETINTA Position     */
#define LPC_DMA_XFERCFG13_SETINTA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_SETINTA_SHIFT))&LPC_DMA_XFERCFG13_SETINTA_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_SETINTB_MASK           (0x20U)                                             /*!< LPC_DMA_XFERCFG13: SETINTB Mask         */
#define LPC_DMA_XFERCFG13_SETINTB_SHIFT          (5U)                                                /*!< LPC_DMA_XFERCFG13: SETINTB Position     */
#define LPC_DMA_XFERCFG13_SETINTB(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_SETINTB_SHIFT))&LPC_DMA_XFERCFG13_SETINTB_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_WIDTH_MASK             (0x300U)                                            /*!< LPC_DMA_XFERCFG13: WIDTH Mask           */
#define LPC_DMA_XFERCFG13_WIDTH_SHIFT            (8U)                                                /*!< LPC_DMA_XFERCFG13: WIDTH Position       */
#define LPC_DMA_XFERCFG13_WIDTH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_WIDTH_SHIFT))&LPC_DMA_XFERCFG13_WIDTH_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_SRCINC_MASK            (0x3000U)                                           /*!< LPC_DMA_XFERCFG13: SRCINC Mask          */
#define LPC_DMA_XFERCFG13_SRCINC_SHIFT           (12U)                                               /*!< LPC_DMA_XFERCFG13: SRCINC Position      */
#define LPC_DMA_XFERCFG13_SRCINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_SRCINC_SHIFT))&LPC_DMA_XFERCFG13_SRCINC_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_DSTINC_MASK            (0xC000U)                                           /*!< LPC_DMA_XFERCFG13: DSTINC Mask          */
#define LPC_DMA_XFERCFG13_DSTINC_SHIFT           (14U)                                               /*!< LPC_DMA_XFERCFG13: DSTINC Position      */
#define LPC_DMA_XFERCFG13_DSTINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_DSTINC_SHIFT))&LPC_DMA_XFERCFG13_DSTINC_MASK) /*!< LPC_DMA_XFERCFG13                       */
#define LPC_DMA_XFERCFG13_XFERCOUNT_MASK         (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG13: XFERCOUNT Mask       */
#define LPC_DMA_XFERCFG13_XFERCOUNT_SHIFT        (16U)                                               /*!< LPC_DMA_XFERCFG13: XFERCOUNT Position   */
#define LPC_DMA_XFERCFG13_XFERCOUNT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG13_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG13_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG13                       */
/* ------- CFG14 Bit Fields                         ------ */
#define LPC_DMA_CFG14_PERIPHREQEN_MASK           (0x1U)                                              /*!< LPC_DMA_CFG14: PERIPHREQEN Mask         */
#define LPC_DMA_CFG14_PERIPHREQEN_SHIFT          (0U)                                                /*!< LPC_DMA_CFG14: PERIPHREQEN Position     */
#define LPC_DMA_CFG14_PERIPHREQEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_PERIPHREQEN_SHIFT))&LPC_DMA_CFG14_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG14                           */
#define LPC_DMA_CFG14_HWTRIGEN_MASK              (0x2U)                                              /*!< LPC_DMA_CFG14: HWTRIGEN Mask            */
#define LPC_DMA_CFG14_HWTRIGEN_SHIFT             (1U)                                                /*!< LPC_DMA_CFG14: HWTRIGEN Position        */
#define LPC_DMA_CFG14_HWTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_HWTRIGEN_SHIFT))&LPC_DMA_CFG14_HWTRIGEN_MASK) /*!< LPC_DMA_CFG14                           */
#define LPC_DMA_CFG14_TRIGPOL_MASK               (0x10U)                                             /*!< LPC_DMA_CFG14: TRIGPOL Mask             */
#define LPC_DMA_CFG14_TRIGPOL_SHIFT              (4U)                                                /*!< LPC_DMA_CFG14: TRIGPOL Position         */
#define LPC_DMA_CFG14_TRIGPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_TRIGPOL_SHIFT))&LPC_DMA_CFG14_TRIGPOL_MASK) /*!< LPC_DMA_CFG14                           */
#define LPC_DMA_CFG14_TRIGTYPE_MASK              (0x20U)                                             /*!< LPC_DMA_CFG14: TRIGTYPE Mask            */
#define LPC_DMA_CFG14_TRIGTYPE_SHIFT             (5U)                                                /*!< LPC_DMA_CFG14: TRIGTYPE Position        */
#define LPC_DMA_CFG14_TRIGTYPE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_TRIGTYPE_SHIFT))&LPC_DMA_CFG14_TRIGTYPE_MASK) /*!< LPC_DMA_CFG14                           */
#define LPC_DMA_CFG14_TRIGBURST_MASK             (0x40U)                                             /*!< LPC_DMA_CFG14: TRIGBURST Mask           */
#define LPC_DMA_CFG14_TRIGBURST_SHIFT            (6U)                                                /*!< LPC_DMA_CFG14: TRIGBURST Position       */
#define LPC_DMA_CFG14_TRIGBURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_TRIGBURST_SHIFT))&LPC_DMA_CFG14_TRIGBURST_MASK) /*!< LPC_DMA_CFG14                           */
#define LPC_DMA_CFG14_BURSTPOWER_MASK            (0xF00U)                                            /*!< LPC_DMA_CFG14: BURSTPOWER Mask          */
#define LPC_DMA_CFG14_BURSTPOWER_SHIFT           (8U)                                                /*!< LPC_DMA_CFG14: BURSTPOWER Position      */
#define LPC_DMA_CFG14_BURSTPOWER(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_BURSTPOWER_SHIFT))&LPC_DMA_CFG14_BURSTPOWER_MASK) /*!< LPC_DMA_CFG14                           */
#define LPC_DMA_CFG14_SRCBURSTWRAP_MASK          (0x4000U)                                           /*!< LPC_DMA_CFG14: SRCBURSTWRAP Mask        */
#define LPC_DMA_CFG14_SRCBURSTWRAP_SHIFT         (14U)                                               /*!< LPC_DMA_CFG14: SRCBURSTWRAP Position    */
#define LPC_DMA_CFG14_SRCBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG14_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG14                           */
#define LPC_DMA_CFG14_DSTBURSTWRAP_MASK          (0x8000U)                                           /*!< LPC_DMA_CFG14: DSTBURSTWRAP Mask        */
#define LPC_DMA_CFG14_DSTBURSTWRAP_SHIFT         (15U)                                               /*!< LPC_DMA_CFG14: DSTBURSTWRAP Position    */
#define LPC_DMA_CFG14_DSTBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG14_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG14                           */
#define LPC_DMA_CFG14_CHPRIORITY_MASK            (0x70000U)                                          /*!< LPC_DMA_CFG14: CHPRIORITY Mask          */
#define LPC_DMA_CFG14_CHPRIORITY_SHIFT           (16U)                                               /*!< LPC_DMA_CFG14: CHPRIORITY Position      */
#define LPC_DMA_CFG14_CHPRIORITY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG14_CHPRIORITY_SHIFT))&LPC_DMA_CFG14_CHPRIORITY_MASK) /*!< LPC_DMA_CFG14                           */
/* ------- CTLSTAT14 Bit Fields                     ------ */
#define LPC_DMA_CTLSTAT14_VALIDPENDING_MASK      (0x1U)                                              /*!< LPC_DMA_CTLSTAT14: VALIDPENDING Mask    */
#define LPC_DMA_CTLSTAT14_VALIDPENDING_SHIFT     (0U)                                                /*!< LPC_DMA_CTLSTAT14: VALIDPENDING Position*/
#define LPC_DMA_CTLSTAT14_VALIDPENDING(x)        (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT14_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT14_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT14                       */
#define LPC_DMA_CTLSTAT14_TRIG_MASK              (0x4U)                                              /*!< LPC_DMA_CTLSTAT14: TRIG Mask            */
#define LPC_DMA_CTLSTAT14_TRIG_SHIFT             (2U)                                                /*!< LPC_DMA_CTLSTAT14: TRIG Position        */
#define LPC_DMA_CTLSTAT14_TRIG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT14_TRIG_SHIFT))&LPC_DMA_CTLSTAT14_TRIG_MASK) /*!< LPC_DMA_CTLSTAT14                       */
/* ------- XFERCFG14 Bit Fields                     ------ */
#define LPC_DMA_XFERCFG14_CFGVALID_MASK          (0x1U)                                              /*!< LPC_DMA_XFERCFG14: CFGVALID Mask        */
#define LPC_DMA_XFERCFG14_CFGVALID_SHIFT         (0U)                                                /*!< LPC_DMA_XFERCFG14: CFGVALID Position    */
#define LPC_DMA_XFERCFG14_CFGVALID(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_CFGVALID_SHIFT))&LPC_DMA_XFERCFG14_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_RELOAD_MASK            (0x2U)                                              /*!< LPC_DMA_XFERCFG14: RELOAD Mask          */
#define LPC_DMA_XFERCFG14_RELOAD_SHIFT           (1U)                                                /*!< LPC_DMA_XFERCFG14: RELOAD Position      */
#define LPC_DMA_XFERCFG14_RELOAD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_RELOAD_SHIFT))&LPC_DMA_XFERCFG14_RELOAD_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_SWTRIG_MASK            (0x4U)                                              /*!< LPC_DMA_XFERCFG14: SWTRIG Mask          */
#define LPC_DMA_XFERCFG14_SWTRIG_SHIFT           (2U)                                                /*!< LPC_DMA_XFERCFG14: SWTRIG Position      */
#define LPC_DMA_XFERCFG14_SWTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_SWTRIG_SHIFT))&LPC_DMA_XFERCFG14_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_CLRTRIG_MASK           (0x8U)                                              /*!< LPC_DMA_XFERCFG14: CLRTRIG Mask         */
#define LPC_DMA_XFERCFG14_CLRTRIG_SHIFT          (3U)                                                /*!< LPC_DMA_XFERCFG14: CLRTRIG Position     */
#define LPC_DMA_XFERCFG14_CLRTRIG(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG14_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_SETINTA_MASK           (0x10U)                                             /*!< LPC_DMA_XFERCFG14: SETINTA Mask         */
#define LPC_DMA_XFERCFG14_SETINTA_SHIFT          (4U)                                                /*!< LPC_DMA_XFERCFG14: SETINTA Position     */
#define LPC_DMA_XFERCFG14_SETINTA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_SETINTA_SHIFT))&LPC_DMA_XFERCFG14_SETINTA_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_SETINTB_MASK           (0x20U)                                             /*!< LPC_DMA_XFERCFG14: SETINTB Mask         */
#define LPC_DMA_XFERCFG14_SETINTB_SHIFT          (5U)                                                /*!< LPC_DMA_XFERCFG14: SETINTB Position     */
#define LPC_DMA_XFERCFG14_SETINTB(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_SETINTB_SHIFT))&LPC_DMA_XFERCFG14_SETINTB_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_WIDTH_MASK             (0x300U)                                            /*!< LPC_DMA_XFERCFG14: WIDTH Mask           */
#define LPC_DMA_XFERCFG14_WIDTH_SHIFT            (8U)                                                /*!< LPC_DMA_XFERCFG14: WIDTH Position       */
#define LPC_DMA_XFERCFG14_WIDTH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_WIDTH_SHIFT))&LPC_DMA_XFERCFG14_WIDTH_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_SRCINC_MASK            (0x3000U)                                           /*!< LPC_DMA_XFERCFG14: SRCINC Mask          */
#define LPC_DMA_XFERCFG14_SRCINC_SHIFT           (12U)                                               /*!< LPC_DMA_XFERCFG14: SRCINC Position      */
#define LPC_DMA_XFERCFG14_SRCINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_SRCINC_SHIFT))&LPC_DMA_XFERCFG14_SRCINC_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_DSTINC_MASK            (0xC000U)                                           /*!< LPC_DMA_XFERCFG14: DSTINC Mask          */
#define LPC_DMA_XFERCFG14_DSTINC_SHIFT           (14U)                                               /*!< LPC_DMA_XFERCFG14: DSTINC Position      */
#define LPC_DMA_XFERCFG14_DSTINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_DSTINC_SHIFT))&LPC_DMA_XFERCFG14_DSTINC_MASK) /*!< LPC_DMA_XFERCFG14                       */
#define LPC_DMA_XFERCFG14_XFERCOUNT_MASK         (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG14: XFERCOUNT Mask       */
#define LPC_DMA_XFERCFG14_XFERCOUNT_SHIFT        (16U)                                               /*!< LPC_DMA_XFERCFG14: XFERCOUNT Position   */
#define LPC_DMA_XFERCFG14_XFERCOUNT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG14_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG14_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG14                       */
/* ------- CFG15 Bit Fields                         ------ */
#define LPC_DMA_CFG15_PERIPHREQEN_MASK           (0x1U)                                              /*!< LPC_DMA_CFG15: PERIPHREQEN Mask         */
#define LPC_DMA_CFG15_PERIPHREQEN_SHIFT          (0U)                                                /*!< LPC_DMA_CFG15: PERIPHREQEN Position     */
#define LPC_DMA_CFG15_PERIPHREQEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_PERIPHREQEN_SHIFT))&LPC_DMA_CFG15_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG15                           */
#define LPC_DMA_CFG15_HWTRIGEN_MASK              (0x2U)                                              /*!< LPC_DMA_CFG15: HWTRIGEN Mask            */
#define LPC_DMA_CFG15_HWTRIGEN_SHIFT             (1U)                                                /*!< LPC_DMA_CFG15: HWTRIGEN Position        */
#define LPC_DMA_CFG15_HWTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_HWTRIGEN_SHIFT))&LPC_DMA_CFG15_HWTRIGEN_MASK) /*!< LPC_DMA_CFG15                           */
#define LPC_DMA_CFG15_TRIGPOL_MASK               (0x10U)                                             /*!< LPC_DMA_CFG15: TRIGPOL Mask             */
#define LPC_DMA_CFG15_TRIGPOL_SHIFT              (4U)                                                /*!< LPC_DMA_CFG15: TRIGPOL Position         */
#define LPC_DMA_CFG15_TRIGPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_TRIGPOL_SHIFT))&LPC_DMA_CFG15_TRIGPOL_MASK) /*!< LPC_DMA_CFG15                           */
#define LPC_DMA_CFG15_TRIGTYPE_MASK              (0x20U)                                             /*!< LPC_DMA_CFG15: TRIGTYPE Mask            */
#define LPC_DMA_CFG15_TRIGTYPE_SHIFT             (5U)                                                /*!< LPC_DMA_CFG15: TRIGTYPE Position        */
#define LPC_DMA_CFG15_TRIGTYPE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_TRIGTYPE_SHIFT))&LPC_DMA_CFG15_TRIGTYPE_MASK) /*!< LPC_DMA_CFG15                           */
#define LPC_DMA_CFG15_TRIGBURST_MASK             (0x40U)                                             /*!< LPC_DMA_CFG15: TRIGBURST Mask           */
#define LPC_DMA_CFG15_TRIGBURST_SHIFT            (6U)                                                /*!< LPC_DMA_CFG15: TRIGBURST Position       */
#define LPC_DMA_CFG15_TRIGBURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_TRIGBURST_SHIFT))&LPC_DMA_CFG15_TRIGBURST_MASK) /*!< LPC_DMA_CFG15                           */
#define LPC_DMA_CFG15_BURSTPOWER_MASK            (0xF00U)                                            /*!< LPC_DMA_CFG15: BURSTPOWER Mask          */
#define LPC_DMA_CFG15_BURSTPOWER_SHIFT           (8U)                                                /*!< LPC_DMA_CFG15: BURSTPOWER Position      */
#define LPC_DMA_CFG15_BURSTPOWER(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_BURSTPOWER_SHIFT))&LPC_DMA_CFG15_BURSTPOWER_MASK) /*!< LPC_DMA_CFG15                           */
#define LPC_DMA_CFG15_SRCBURSTWRAP_MASK          (0x4000U)                                           /*!< LPC_DMA_CFG15: SRCBURSTWRAP Mask        */
#define LPC_DMA_CFG15_SRCBURSTWRAP_SHIFT         (14U)                                               /*!< LPC_DMA_CFG15: SRCBURSTWRAP Position    */
#define LPC_DMA_CFG15_SRCBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG15_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG15                           */
#define LPC_DMA_CFG15_DSTBURSTWRAP_MASK          (0x8000U)                                           /*!< LPC_DMA_CFG15: DSTBURSTWRAP Mask        */
#define LPC_DMA_CFG15_DSTBURSTWRAP_SHIFT         (15U)                                               /*!< LPC_DMA_CFG15: DSTBURSTWRAP Position    */
#define LPC_DMA_CFG15_DSTBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG15_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG15                           */
#define LPC_DMA_CFG15_CHPRIORITY_MASK            (0x70000U)                                          /*!< LPC_DMA_CFG15: CHPRIORITY Mask          */
#define LPC_DMA_CFG15_CHPRIORITY_SHIFT           (16U)                                               /*!< LPC_DMA_CFG15: CHPRIORITY Position      */
#define LPC_DMA_CFG15_CHPRIORITY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG15_CHPRIORITY_SHIFT))&LPC_DMA_CFG15_CHPRIORITY_MASK) /*!< LPC_DMA_CFG15                           */
/* ------- CTLSTAT15 Bit Fields                     ------ */
#define LPC_DMA_CTLSTAT15_VALIDPENDING_MASK      (0x1U)                                              /*!< LPC_DMA_CTLSTAT15: VALIDPENDING Mask    */
#define LPC_DMA_CTLSTAT15_VALIDPENDING_SHIFT     (0U)                                                /*!< LPC_DMA_CTLSTAT15: VALIDPENDING Position*/
#define LPC_DMA_CTLSTAT15_VALIDPENDING(x)        (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT15_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT15_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT15                       */
#define LPC_DMA_CTLSTAT15_TRIG_MASK              (0x4U)                                              /*!< LPC_DMA_CTLSTAT15: TRIG Mask            */
#define LPC_DMA_CTLSTAT15_TRIG_SHIFT             (2U)                                                /*!< LPC_DMA_CTLSTAT15: TRIG Position        */
#define LPC_DMA_CTLSTAT15_TRIG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT15_TRIG_SHIFT))&LPC_DMA_CTLSTAT15_TRIG_MASK) /*!< LPC_DMA_CTLSTAT15                       */
/* ------- XFERCFG15 Bit Fields                     ------ */
#define LPC_DMA_XFERCFG15_CFGVALID_MASK          (0x1U)                                              /*!< LPC_DMA_XFERCFG15: CFGVALID Mask        */
#define LPC_DMA_XFERCFG15_CFGVALID_SHIFT         (0U)                                                /*!< LPC_DMA_XFERCFG15: CFGVALID Position    */
#define LPC_DMA_XFERCFG15_CFGVALID(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_CFGVALID_SHIFT))&LPC_DMA_XFERCFG15_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_RELOAD_MASK            (0x2U)                                              /*!< LPC_DMA_XFERCFG15: RELOAD Mask          */
#define LPC_DMA_XFERCFG15_RELOAD_SHIFT           (1U)                                                /*!< LPC_DMA_XFERCFG15: RELOAD Position      */
#define LPC_DMA_XFERCFG15_RELOAD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_RELOAD_SHIFT))&LPC_DMA_XFERCFG15_RELOAD_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_SWTRIG_MASK            (0x4U)                                              /*!< LPC_DMA_XFERCFG15: SWTRIG Mask          */
#define LPC_DMA_XFERCFG15_SWTRIG_SHIFT           (2U)                                                /*!< LPC_DMA_XFERCFG15: SWTRIG Position      */
#define LPC_DMA_XFERCFG15_SWTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_SWTRIG_SHIFT))&LPC_DMA_XFERCFG15_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_CLRTRIG_MASK           (0x8U)                                              /*!< LPC_DMA_XFERCFG15: CLRTRIG Mask         */
#define LPC_DMA_XFERCFG15_CLRTRIG_SHIFT          (3U)                                                /*!< LPC_DMA_XFERCFG15: CLRTRIG Position     */
#define LPC_DMA_XFERCFG15_CLRTRIG(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG15_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_SETINTA_MASK           (0x10U)                                             /*!< LPC_DMA_XFERCFG15: SETINTA Mask         */
#define LPC_DMA_XFERCFG15_SETINTA_SHIFT          (4U)                                                /*!< LPC_DMA_XFERCFG15: SETINTA Position     */
#define LPC_DMA_XFERCFG15_SETINTA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_SETINTA_SHIFT))&LPC_DMA_XFERCFG15_SETINTA_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_SETINTB_MASK           (0x20U)                                             /*!< LPC_DMA_XFERCFG15: SETINTB Mask         */
#define LPC_DMA_XFERCFG15_SETINTB_SHIFT          (5U)                                                /*!< LPC_DMA_XFERCFG15: SETINTB Position     */
#define LPC_DMA_XFERCFG15_SETINTB(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_SETINTB_SHIFT))&LPC_DMA_XFERCFG15_SETINTB_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_WIDTH_MASK             (0x300U)                                            /*!< LPC_DMA_XFERCFG15: WIDTH Mask           */
#define LPC_DMA_XFERCFG15_WIDTH_SHIFT            (8U)                                                /*!< LPC_DMA_XFERCFG15: WIDTH Position       */
#define LPC_DMA_XFERCFG15_WIDTH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_WIDTH_SHIFT))&LPC_DMA_XFERCFG15_WIDTH_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_SRCINC_MASK            (0x3000U)                                           /*!< LPC_DMA_XFERCFG15: SRCINC Mask          */
#define LPC_DMA_XFERCFG15_SRCINC_SHIFT           (12U)                                               /*!< LPC_DMA_XFERCFG15: SRCINC Position      */
#define LPC_DMA_XFERCFG15_SRCINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_SRCINC_SHIFT))&LPC_DMA_XFERCFG15_SRCINC_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_DSTINC_MASK            (0xC000U)                                           /*!< LPC_DMA_XFERCFG15: DSTINC Mask          */
#define LPC_DMA_XFERCFG15_DSTINC_SHIFT           (14U)                                               /*!< LPC_DMA_XFERCFG15: DSTINC Position      */
#define LPC_DMA_XFERCFG15_DSTINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_DSTINC_SHIFT))&LPC_DMA_XFERCFG15_DSTINC_MASK) /*!< LPC_DMA_XFERCFG15                       */
#define LPC_DMA_XFERCFG15_XFERCOUNT_MASK         (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG15: XFERCOUNT Mask       */
#define LPC_DMA_XFERCFG15_XFERCOUNT_SHIFT        (16U)                                               /*!< LPC_DMA_XFERCFG15: XFERCOUNT Position   */
#define LPC_DMA_XFERCFG15_XFERCOUNT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG15_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG15_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG15                       */
/* ------- CFG16 Bit Fields                         ------ */
#define LPC_DMA_CFG16_PERIPHREQEN_MASK           (0x1U)                                              /*!< LPC_DMA_CFG16: PERIPHREQEN Mask         */
#define LPC_DMA_CFG16_PERIPHREQEN_SHIFT          (0U)                                                /*!< LPC_DMA_CFG16: PERIPHREQEN Position     */
#define LPC_DMA_CFG16_PERIPHREQEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_PERIPHREQEN_SHIFT))&LPC_DMA_CFG16_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG16                           */
#define LPC_DMA_CFG16_HWTRIGEN_MASK              (0x2U)                                              /*!< LPC_DMA_CFG16: HWTRIGEN Mask            */
#define LPC_DMA_CFG16_HWTRIGEN_SHIFT             (1U)                                                /*!< LPC_DMA_CFG16: HWTRIGEN Position        */
#define LPC_DMA_CFG16_HWTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_HWTRIGEN_SHIFT))&LPC_DMA_CFG16_HWTRIGEN_MASK) /*!< LPC_DMA_CFG16                           */
#define LPC_DMA_CFG16_TRIGPOL_MASK               (0x10U)                                             /*!< LPC_DMA_CFG16: TRIGPOL Mask             */
#define LPC_DMA_CFG16_TRIGPOL_SHIFT              (4U)                                                /*!< LPC_DMA_CFG16: TRIGPOL Position         */
#define LPC_DMA_CFG16_TRIGPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_TRIGPOL_SHIFT))&LPC_DMA_CFG16_TRIGPOL_MASK) /*!< LPC_DMA_CFG16                           */
#define LPC_DMA_CFG16_TRIGTYPE_MASK              (0x20U)                                             /*!< LPC_DMA_CFG16: TRIGTYPE Mask            */
#define LPC_DMA_CFG16_TRIGTYPE_SHIFT             (5U)                                                /*!< LPC_DMA_CFG16: TRIGTYPE Position        */
#define LPC_DMA_CFG16_TRIGTYPE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_TRIGTYPE_SHIFT))&LPC_DMA_CFG16_TRIGTYPE_MASK) /*!< LPC_DMA_CFG16                           */
#define LPC_DMA_CFG16_TRIGBURST_MASK             (0x40U)                                             /*!< LPC_DMA_CFG16: TRIGBURST Mask           */
#define LPC_DMA_CFG16_TRIGBURST_SHIFT            (6U)                                                /*!< LPC_DMA_CFG16: TRIGBURST Position       */
#define LPC_DMA_CFG16_TRIGBURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_TRIGBURST_SHIFT))&LPC_DMA_CFG16_TRIGBURST_MASK) /*!< LPC_DMA_CFG16                           */
#define LPC_DMA_CFG16_BURSTPOWER_MASK            (0xF00U)                                            /*!< LPC_DMA_CFG16: BURSTPOWER Mask          */
#define LPC_DMA_CFG16_BURSTPOWER_SHIFT           (8U)                                                /*!< LPC_DMA_CFG16: BURSTPOWER Position      */
#define LPC_DMA_CFG16_BURSTPOWER(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_BURSTPOWER_SHIFT))&LPC_DMA_CFG16_BURSTPOWER_MASK) /*!< LPC_DMA_CFG16                           */
#define LPC_DMA_CFG16_SRCBURSTWRAP_MASK          (0x4000U)                                           /*!< LPC_DMA_CFG16: SRCBURSTWRAP Mask        */
#define LPC_DMA_CFG16_SRCBURSTWRAP_SHIFT         (14U)                                               /*!< LPC_DMA_CFG16: SRCBURSTWRAP Position    */
#define LPC_DMA_CFG16_SRCBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG16_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG16                           */
#define LPC_DMA_CFG16_DSTBURSTWRAP_MASK          (0x8000U)                                           /*!< LPC_DMA_CFG16: DSTBURSTWRAP Mask        */
#define LPC_DMA_CFG16_DSTBURSTWRAP_SHIFT         (15U)                                               /*!< LPC_DMA_CFG16: DSTBURSTWRAP Position    */
#define LPC_DMA_CFG16_DSTBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG16_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG16                           */
#define LPC_DMA_CFG16_CHPRIORITY_MASK            (0x70000U)                                          /*!< LPC_DMA_CFG16: CHPRIORITY Mask          */
#define LPC_DMA_CFG16_CHPRIORITY_SHIFT           (16U)                                               /*!< LPC_DMA_CFG16: CHPRIORITY Position      */
#define LPC_DMA_CFG16_CHPRIORITY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG16_CHPRIORITY_SHIFT))&LPC_DMA_CFG16_CHPRIORITY_MASK) /*!< LPC_DMA_CFG16                           */
/* ------- CTLSTAT16 Bit Fields                     ------ */
#define LPC_DMA_CTLSTAT16_VALIDPENDING_MASK      (0x1U)                                              /*!< LPC_DMA_CTLSTAT16: VALIDPENDING Mask    */
#define LPC_DMA_CTLSTAT16_VALIDPENDING_SHIFT     (0U)                                                /*!< LPC_DMA_CTLSTAT16: VALIDPENDING Position*/
#define LPC_DMA_CTLSTAT16_VALIDPENDING(x)        (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT16_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT16_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT16                       */
#define LPC_DMA_CTLSTAT16_TRIG_MASK              (0x4U)                                              /*!< LPC_DMA_CTLSTAT16: TRIG Mask            */
#define LPC_DMA_CTLSTAT16_TRIG_SHIFT             (2U)                                                /*!< LPC_DMA_CTLSTAT16: TRIG Position        */
#define LPC_DMA_CTLSTAT16_TRIG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT16_TRIG_SHIFT))&LPC_DMA_CTLSTAT16_TRIG_MASK) /*!< LPC_DMA_CTLSTAT16                       */
/* ------- XFERCFG16 Bit Fields                     ------ */
#define LPC_DMA_XFERCFG16_CFGVALID_MASK          (0x1U)                                              /*!< LPC_DMA_XFERCFG16: CFGVALID Mask        */
#define LPC_DMA_XFERCFG16_CFGVALID_SHIFT         (0U)                                                /*!< LPC_DMA_XFERCFG16: CFGVALID Position    */
#define LPC_DMA_XFERCFG16_CFGVALID(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_CFGVALID_SHIFT))&LPC_DMA_XFERCFG16_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_RELOAD_MASK            (0x2U)                                              /*!< LPC_DMA_XFERCFG16: RELOAD Mask          */
#define LPC_DMA_XFERCFG16_RELOAD_SHIFT           (1U)                                                /*!< LPC_DMA_XFERCFG16: RELOAD Position      */
#define LPC_DMA_XFERCFG16_RELOAD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_RELOAD_SHIFT))&LPC_DMA_XFERCFG16_RELOAD_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_SWTRIG_MASK            (0x4U)                                              /*!< LPC_DMA_XFERCFG16: SWTRIG Mask          */
#define LPC_DMA_XFERCFG16_SWTRIG_SHIFT           (2U)                                                /*!< LPC_DMA_XFERCFG16: SWTRIG Position      */
#define LPC_DMA_XFERCFG16_SWTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_SWTRIG_SHIFT))&LPC_DMA_XFERCFG16_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_CLRTRIG_MASK           (0x8U)                                              /*!< LPC_DMA_XFERCFG16: CLRTRIG Mask         */
#define LPC_DMA_XFERCFG16_CLRTRIG_SHIFT          (3U)                                                /*!< LPC_DMA_XFERCFG16: CLRTRIG Position     */
#define LPC_DMA_XFERCFG16_CLRTRIG(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG16_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_SETINTA_MASK           (0x10U)                                             /*!< LPC_DMA_XFERCFG16: SETINTA Mask         */
#define LPC_DMA_XFERCFG16_SETINTA_SHIFT          (4U)                                                /*!< LPC_DMA_XFERCFG16: SETINTA Position     */
#define LPC_DMA_XFERCFG16_SETINTA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_SETINTA_SHIFT))&LPC_DMA_XFERCFG16_SETINTA_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_SETINTB_MASK           (0x20U)                                             /*!< LPC_DMA_XFERCFG16: SETINTB Mask         */
#define LPC_DMA_XFERCFG16_SETINTB_SHIFT          (5U)                                                /*!< LPC_DMA_XFERCFG16: SETINTB Position     */
#define LPC_DMA_XFERCFG16_SETINTB(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_SETINTB_SHIFT))&LPC_DMA_XFERCFG16_SETINTB_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_WIDTH_MASK             (0x300U)                                            /*!< LPC_DMA_XFERCFG16: WIDTH Mask           */
#define LPC_DMA_XFERCFG16_WIDTH_SHIFT            (8U)                                                /*!< LPC_DMA_XFERCFG16: WIDTH Position       */
#define LPC_DMA_XFERCFG16_WIDTH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_WIDTH_SHIFT))&LPC_DMA_XFERCFG16_WIDTH_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_SRCINC_MASK            (0x3000U)                                           /*!< LPC_DMA_XFERCFG16: SRCINC Mask          */
#define LPC_DMA_XFERCFG16_SRCINC_SHIFT           (12U)                                               /*!< LPC_DMA_XFERCFG16: SRCINC Position      */
#define LPC_DMA_XFERCFG16_SRCINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_SRCINC_SHIFT))&LPC_DMA_XFERCFG16_SRCINC_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_DSTINC_MASK            (0xC000U)                                           /*!< LPC_DMA_XFERCFG16: DSTINC Mask          */
#define LPC_DMA_XFERCFG16_DSTINC_SHIFT           (14U)                                               /*!< LPC_DMA_XFERCFG16: DSTINC Position      */
#define LPC_DMA_XFERCFG16_DSTINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_DSTINC_SHIFT))&LPC_DMA_XFERCFG16_DSTINC_MASK) /*!< LPC_DMA_XFERCFG16                       */
#define LPC_DMA_XFERCFG16_XFERCOUNT_MASK         (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG16: XFERCOUNT Mask       */
#define LPC_DMA_XFERCFG16_XFERCOUNT_SHIFT        (16U)                                               /*!< LPC_DMA_XFERCFG16: XFERCOUNT Position   */
#define LPC_DMA_XFERCFG16_XFERCOUNT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG16_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG16_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG16                       */
/* ------- CFG17 Bit Fields                         ------ */
#define LPC_DMA_CFG17_PERIPHREQEN_MASK           (0x1U)                                              /*!< LPC_DMA_CFG17: PERIPHREQEN Mask         */
#define LPC_DMA_CFG17_PERIPHREQEN_SHIFT          (0U)                                                /*!< LPC_DMA_CFG17: PERIPHREQEN Position     */
#define LPC_DMA_CFG17_PERIPHREQEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_PERIPHREQEN_SHIFT))&LPC_DMA_CFG17_PERIPHREQEN_MASK) /*!< LPC_DMA_CFG17                           */
#define LPC_DMA_CFG17_HWTRIGEN_MASK              (0x2U)                                              /*!< LPC_DMA_CFG17: HWTRIGEN Mask            */
#define LPC_DMA_CFG17_HWTRIGEN_SHIFT             (1U)                                                /*!< LPC_DMA_CFG17: HWTRIGEN Position        */
#define LPC_DMA_CFG17_HWTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_HWTRIGEN_SHIFT))&LPC_DMA_CFG17_HWTRIGEN_MASK) /*!< LPC_DMA_CFG17                           */
#define LPC_DMA_CFG17_TRIGPOL_MASK               (0x10U)                                             /*!< LPC_DMA_CFG17: TRIGPOL Mask             */
#define LPC_DMA_CFG17_TRIGPOL_SHIFT              (4U)                                                /*!< LPC_DMA_CFG17: TRIGPOL Position         */
#define LPC_DMA_CFG17_TRIGPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_TRIGPOL_SHIFT))&LPC_DMA_CFG17_TRIGPOL_MASK) /*!< LPC_DMA_CFG17                           */
#define LPC_DMA_CFG17_TRIGTYPE_MASK              (0x20U)                                             /*!< LPC_DMA_CFG17: TRIGTYPE Mask            */
#define LPC_DMA_CFG17_TRIGTYPE_SHIFT             (5U)                                                /*!< LPC_DMA_CFG17: TRIGTYPE Position        */
#define LPC_DMA_CFG17_TRIGTYPE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_TRIGTYPE_SHIFT))&LPC_DMA_CFG17_TRIGTYPE_MASK) /*!< LPC_DMA_CFG17                           */
#define LPC_DMA_CFG17_TRIGBURST_MASK             (0x40U)                                             /*!< LPC_DMA_CFG17: TRIGBURST Mask           */
#define LPC_DMA_CFG17_TRIGBURST_SHIFT            (6U)                                                /*!< LPC_DMA_CFG17: TRIGBURST Position       */
#define LPC_DMA_CFG17_TRIGBURST(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_TRIGBURST_SHIFT))&LPC_DMA_CFG17_TRIGBURST_MASK) /*!< LPC_DMA_CFG17                           */
#define LPC_DMA_CFG17_BURSTPOWER_MASK            (0xF00U)                                            /*!< LPC_DMA_CFG17: BURSTPOWER Mask          */
#define LPC_DMA_CFG17_BURSTPOWER_SHIFT           (8U)                                                /*!< LPC_DMA_CFG17: BURSTPOWER Position      */
#define LPC_DMA_CFG17_BURSTPOWER(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_BURSTPOWER_SHIFT))&LPC_DMA_CFG17_BURSTPOWER_MASK) /*!< LPC_DMA_CFG17                           */
#define LPC_DMA_CFG17_SRCBURSTWRAP_MASK          (0x4000U)                                           /*!< LPC_DMA_CFG17: SRCBURSTWRAP Mask        */
#define LPC_DMA_CFG17_SRCBURSTWRAP_SHIFT         (14U)                                               /*!< LPC_DMA_CFG17: SRCBURSTWRAP Position    */
#define LPC_DMA_CFG17_SRCBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_SRCBURSTWRAP_SHIFT))&LPC_DMA_CFG17_SRCBURSTWRAP_MASK) /*!< LPC_DMA_CFG17                           */
#define LPC_DMA_CFG17_DSTBURSTWRAP_MASK          (0x8000U)                                           /*!< LPC_DMA_CFG17: DSTBURSTWRAP Mask        */
#define LPC_DMA_CFG17_DSTBURSTWRAP_SHIFT         (15U)                                               /*!< LPC_DMA_CFG17: DSTBURSTWRAP Position    */
#define LPC_DMA_CFG17_DSTBURSTWRAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_DSTBURSTWRAP_SHIFT))&LPC_DMA_CFG17_DSTBURSTWRAP_MASK) /*!< LPC_DMA_CFG17                           */
#define LPC_DMA_CFG17_CHPRIORITY_MASK            (0x70000U)                                          /*!< LPC_DMA_CFG17: CHPRIORITY Mask          */
#define LPC_DMA_CFG17_CHPRIORITY_SHIFT           (16U)                                               /*!< LPC_DMA_CFG17: CHPRIORITY Position      */
#define LPC_DMA_CFG17_CHPRIORITY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CFG17_CHPRIORITY_SHIFT))&LPC_DMA_CFG17_CHPRIORITY_MASK) /*!< LPC_DMA_CFG17                           */
/* ------- CTLSTAT17 Bit Fields                     ------ */
#define LPC_DMA_CTLSTAT17_VALIDPENDING_MASK      (0x1U)                                              /*!< LPC_DMA_CTLSTAT17: VALIDPENDING Mask    */
#define LPC_DMA_CTLSTAT17_VALIDPENDING_SHIFT     (0U)                                                /*!< LPC_DMA_CTLSTAT17: VALIDPENDING Position*/
#define LPC_DMA_CTLSTAT17_VALIDPENDING(x)        (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT17_VALIDPENDING_SHIFT))&LPC_DMA_CTLSTAT17_VALIDPENDING_MASK) /*!< LPC_DMA_CTLSTAT17                       */
#define LPC_DMA_CTLSTAT17_TRIG_MASK              (0x4U)                                              /*!< LPC_DMA_CTLSTAT17: TRIG Mask            */
#define LPC_DMA_CTLSTAT17_TRIG_SHIFT             (2U)                                                /*!< LPC_DMA_CTLSTAT17: TRIG Position        */
#define LPC_DMA_CTLSTAT17_TRIG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_DMA_CTLSTAT17_TRIG_SHIFT))&LPC_DMA_CTLSTAT17_TRIG_MASK) /*!< LPC_DMA_CTLSTAT17                       */
/* ------- XFERCFG17 Bit Fields                     ------ */
#define LPC_DMA_XFERCFG17_CFGVALID_MASK          (0x1U)                                              /*!< LPC_DMA_XFERCFG17: CFGVALID Mask        */
#define LPC_DMA_XFERCFG17_CFGVALID_SHIFT         (0U)                                                /*!< LPC_DMA_XFERCFG17: CFGVALID Position    */
#define LPC_DMA_XFERCFG17_CFGVALID(x)            (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_CFGVALID_SHIFT))&LPC_DMA_XFERCFG17_CFGVALID_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_RELOAD_MASK            (0x2U)                                              /*!< LPC_DMA_XFERCFG17: RELOAD Mask          */
#define LPC_DMA_XFERCFG17_RELOAD_SHIFT           (1U)                                                /*!< LPC_DMA_XFERCFG17: RELOAD Position      */
#define LPC_DMA_XFERCFG17_RELOAD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_RELOAD_SHIFT))&LPC_DMA_XFERCFG17_RELOAD_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_SWTRIG_MASK            (0x4U)                                              /*!< LPC_DMA_XFERCFG17: SWTRIG Mask          */
#define LPC_DMA_XFERCFG17_SWTRIG_SHIFT           (2U)                                                /*!< LPC_DMA_XFERCFG17: SWTRIG Position      */
#define LPC_DMA_XFERCFG17_SWTRIG(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_SWTRIG_SHIFT))&LPC_DMA_XFERCFG17_SWTRIG_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_CLRTRIG_MASK           (0x8U)                                              /*!< LPC_DMA_XFERCFG17: CLRTRIG Mask         */
#define LPC_DMA_XFERCFG17_CLRTRIG_SHIFT          (3U)                                                /*!< LPC_DMA_XFERCFG17: CLRTRIG Position     */
#define LPC_DMA_XFERCFG17_CLRTRIG(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_CLRTRIG_SHIFT))&LPC_DMA_XFERCFG17_CLRTRIG_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_SETINTA_MASK           (0x10U)                                             /*!< LPC_DMA_XFERCFG17: SETINTA Mask         */
#define LPC_DMA_XFERCFG17_SETINTA_SHIFT          (4U)                                                /*!< LPC_DMA_XFERCFG17: SETINTA Position     */
#define LPC_DMA_XFERCFG17_SETINTA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_SETINTA_SHIFT))&LPC_DMA_XFERCFG17_SETINTA_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_SETINTB_MASK           (0x20U)                                             /*!< LPC_DMA_XFERCFG17: SETINTB Mask         */
#define LPC_DMA_XFERCFG17_SETINTB_SHIFT          (5U)                                                /*!< LPC_DMA_XFERCFG17: SETINTB Position     */
#define LPC_DMA_XFERCFG17_SETINTB(x)             (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_SETINTB_SHIFT))&LPC_DMA_XFERCFG17_SETINTB_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_WIDTH_MASK             (0x300U)                                            /*!< LPC_DMA_XFERCFG17: WIDTH Mask           */
#define LPC_DMA_XFERCFG17_WIDTH_SHIFT            (8U)                                                /*!< LPC_DMA_XFERCFG17: WIDTH Position       */
#define LPC_DMA_XFERCFG17_WIDTH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_WIDTH_SHIFT))&LPC_DMA_XFERCFG17_WIDTH_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_SRCINC_MASK            (0x3000U)                                           /*!< LPC_DMA_XFERCFG17: SRCINC Mask          */
#define LPC_DMA_XFERCFG17_SRCINC_SHIFT           (12U)                                               /*!< LPC_DMA_XFERCFG17: SRCINC Position      */
#define LPC_DMA_XFERCFG17_SRCINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_SRCINC_SHIFT))&LPC_DMA_XFERCFG17_SRCINC_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_DSTINC_MASK            (0xC000U)                                           /*!< LPC_DMA_XFERCFG17: DSTINC Mask          */
#define LPC_DMA_XFERCFG17_DSTINC_SHIFT           (14U)                                               /*!< LPC_DMA_XFERCFG17: DSTINC Position      */
#define LPC_DMA_XFERCFG17_DSTINC(x)              (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_DSTINC_SHIFT))&LPC_DMA_XFERCFG17_DSTINC_MASK) /*!< LPC_DMA_XFERCFG17                       */
#define LPC_DMA_XFERCFG17_XFERCOUNT_MASK         (0x3FF0000U)                                        /*!< LPC_DMA_XFERCFG17: XFERCOUNT Mask       */
#define LPC_DMA_XFERCFG17_XFERCOUNT_SHIFT        (16U)                                               /*!< LPC_DMA_XFERCFG17: XFERCOUNT Position   */
#define LPC_DMA_XFERCFG17_XFERCOUNT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_DMA_XFERCFG17_XFERCOUNT_SHIFT))&LPC_DMA_XFERCFG17_XFERCOUNT_MASK) /*!< LPC_DMA_XFERCFG17                       */
/**
 * @} */ /* End group DMA_Register_Masks_GROUP 
 */

/* LPC_DMA - Peripheral instance base addresses */
#define LPC_DMA_BasePtr                0x50008000UL //!< Peripheral base address
#define LPC_DMA                        ((LPC_DMA_Type *) LPC_DMA_BasePtr) //!< Freescale base pointer
#define LPC_DMA_BASE_PTR               (LPC_DMA) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMATRIGMUX_Peripheral_access_layer_GROUP DMATRIGMUX Peripheral Access Layer
* @brief C Struct for DMATRIGMUX
* @{
*/

/* ================================================================================ */
/* ================           LPC_DMATRIGMUX (file:DMATRIGMUX_LPC82x)       ================ */
/* ================================================================================ */

/**
 * @brief DMA trigger mux
 */
/**
* @addtogroup DMATRIGMUX_structs_GROUP DMATRIGMUX struct
* @brief Struct for DMATRIGMUX
* @{
*/
typedef struct {                                /*       LPC_DMATRIGMUX Structure                                     */
   __IO uint32_t  DMA_ITRIG_INMUX0;             /**< 0000: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX1;             /**< 0004: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX2;             /**< 0008: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX3;             /**< 000C: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX4;             /**< 0010: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX5;             /**< 0014: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX6;             /**< 0018: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX7;             /**< 001C: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX8;             /**< 0020: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX9;             /**< 0024: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX10;            /**< 0028: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX11;            /**< 002C: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX12;            /**< 0030: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX13;            /**< 0034: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX14;            /**< 0038: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX15;            /**< 003C: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX16;            /**< 0040: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
   __IO uint32_t  DMA_ITRIG_INMUX17;            /**< 0044: Input mux register for trigger inputs 0 to 23 connected to DMA channel 0. Selects from ADC, SCT, ACMP, pin  interrupts, and DMA requests */
} LPC_DMATRIGMUX_Type;

/**
 * @} */ /* End group DMATRIGMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_DMATRIGMUX' Position & Mask macros              ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMATRIGMUX_Register_Masks_GROUP DMATRIGMUX Register Masks
* @brief Register Masks for DMATRIGMUX
* @{
*/
/* ------- DMA_ITRIG_INMUX0 Bit Fields              ------ */
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX0_INP_MASK (0xFU)                                              /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX0: INP Mask*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX0_INP_SHIFT (0U)                                               /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX0: INP Position*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX0_INP(x)   (((uint32_t)(((uint32_t)(x))<<LPC_DMATRIGMUX_DMA_ITRIG_INMUX0_INP_SHIFT))&LPC_DMATRIGMUX_DMA_ITRIG_INMUX0_INP_MASK) /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX0         */
/* ------- DMA_ITRIG_INMUX1 Bit Fields              ------ */
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX1_INP_MASK (0xFU)                                              /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX1: INP Mask*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX1_INP_SHIFT (0U)                                               /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX1: INP Position*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX1_INP(x)   (((uint32_t)(((uint32_t)(x))<<LPC_DMATRIGMUX_DMA_ITRIG_INMUX1_INP_SHIFT))&LPC_DMATRIGMUX_DMA_ITRIG_INMUX1_INP_MASK) /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX1         */
/* ------- DMA_ITRIG_INMUX2 Bit Fields              ------ */
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX2_INP_MASK (0xFU)                                              /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX2: INP Mask*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX2_INP_SHIFT (0U)                                               /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX2: INP Position*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX2_INP(x)   (((uint32_t)(((uint32_t)(x))<<LPC_DMATRIGMUX_DMA_ITRIG_INMUX2_INP_SHIFT))&LPC_DMATRIGMUX_DMA_ITRIG_INMUX2_INP_MASK) /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX2         */
/* ------- DMA_ITRIG_INMUX3 Bit Fields              ------ */
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX3_INP_MASK (0xFU)                                              /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX3: INP Mask*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX3_INP_SHIFT (0U)                                               /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX3: INP Position*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX3_INP(x)   (((uint32_t)(((uint32_t)(x))<<LPC_DMATRIGMUX_DMA_ITRIG_INMUX3_INP_SHIFT))&LPC_DMATRIGMUX_DMA_ITRIG_INMUX3_INP_MASK) /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX3         */
/* ------- DMA_ITRIG_INMUX Bit Fields               ------ */
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX_INP_MASK  (0xFU)                                              /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX: INP Mask*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX_INP_SHIFT (0U)                                                /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX: INP Position*/
#define LPC_DMATRIGMUX_DMA_ITRIG_INMUX_INP(x)    (((uint32_t)(((uint32_t)(x))<<LPC_DMATRIGMUX_DMA_ITRIG_INMUX_INP_SHIFT))&LPC_DMATRIGMUX_DMA_ITRIG_INMUX_INP_MASK) /*!< LPC_DMATRIGMUX_DMA_ITRIG_INMUX          */
/**
 * @} */ /* End group DMATRIGMUX_Register_Masks_GROUP 
 */

/* LPC_DMATRIGMUX - Peripheral instance base addresses */
#define LPC_DMATRIGMUX_BasePtr         0x40028000UL //!< Peripheral base address
#define LPC_DMATRIGMUX                 ((LPC_DMATRIGMUX_Type *) LPC_DMATRIGMUX_BasePtr) //!< Freescale base pointer
#define LPC_DMATRIGMUX_BASE_PTR        (LPC_DMATRIGMUX) //!< Freescale style base pointer
/**
 * @} */ /* End group DMATRIGMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FLASHCTRL_Peripheral_access_layer_GROUP FLASHCTRL Peripheral Access Layer
* @brief C Struct for FLASHCTRL
* @{
*/

/* ================================================================================ */
/* ================           LPC_FLASHCTRL (file:FLASHCTRL_LPC82x)       ================ */
/* ================================================================================ */

/**
 * @brief Flash controller
 */
/**
* @addtogroup FLASHCTRL_structs_GROUP FLASHCTRL struct
* @brief Struct for FLASHCTRL
* @{
*/
typedef struct {                                /*       LPC_FLASHCTRL Structure                                      */
        uint8_t   RESERVED_0[16];              
   __IO uint32_t  FLASHCFG;                     /**< 0010: Flash configuration register                                 */
        uint8_t   RESERVED_1[12];              
   __IO uint32_t  FMSSTART;                     /**< 0020: Signature start address register                             */
   __IO uint32_t  FMSSTOP;                      /**< 0024: Signature stop-address register                              */
        uint8_t   RESERVED_2[4];               
   __I  uint32_t  FMSW0;                        /**< 002C: Signature Word                                               */
} LPC_FLASHCTRL_Type;

/**
 * @} */ /* End group FLASHCTRL_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_FLASHCTRL' Position & Mask macros               ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FLASHCTRL_Register_Masks_GROUP FLASHCTRL Register Masks
* @brief Register Masks for FLASHCTRL
* @{
*/
/* ------- FLASHCFG Bit Fields                      ------ */
#define LPC_FLASHCTRL_FLASHCFG_FLASHTIM_MASK     (0x3U)                                              /*!< LPC_FLASHCTRL_FLASHCFG: FLASHTIM Mask   */
#define LPC_FLASHCTRL_FLASHCFG_FLASHTIM_SHIFT    (0U)                                                /*!< LPC_FLASHCTRL_FLASHCFG: FLASHTIM Position*/
#define LPC_FLASHCTRL_FLASHCFG_FLASHTIM(x)       (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FLASHCFG_FLASHTIM_SHIFT))&LPC_FLASHCTRL_FLASHCFG_FLASHTIM_MASK) /*!< LPC_FLASHCTRL_FLASHCFG                  */
/* ------- FMSSTART Bit Fields                      ------ */
#define LPC_FLASHCTRL_FMSSTART_START_MASK        (0x1FFFFU)                                          /*!< LPC_FLASHCTRL_FMSSTART: START Mask      */
#define LPC_FLASHCTRL_FMSSTART_START_SHIFT       (0U)                                                /*!< LPC_FLASHCTRL_FMSSTART: START Position  */
#define LPC_FLASHCTRL_FMSSTART_START(x)          (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSSTART_START_SHIFT))&LPC_FLASHCTRL_FMSSTART_START_MASK) /*!< LPC_FLASHCTRL_FMSSTART                  */
/* ------- FMSSTOP Bit Fields                       ------ */
#define LPC_FLASHCTRL_FMSSTOP_STOPA_MASK         (0x1FFFFU)                                          /*!< LPC_FLASHCTRL_FMSSTOP: STOPA Mask       */
#define LPC_FLASHCTRL_FMSSTOP_STOPA_SHIFT        (0U)                                                /*!< LPC_FLASHCTRL_FMSSTOP: STOPA Position   */
#define LPC_FLASHCTRL_FMSSTOP_STOPA(x)           (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSSTOP_STOPA_SHIFT))&LPC_FLASHCTRL_FMSSTOP_STOPA_MASK) /*!< LPC_FLASHCTRL_FMSSTOP                   */
#define LPC_FLASHCTRL_FMSSTOP_STRTBIST_MASK      (0x80000000U)                                       /*!< LPC_FLASHCTRL_FMSSTOP: STRTBIST Mask    */
#define LPC_FLASHCTRL_FMSSTOP_STRTBIST_SHIFT     (31U)                                               /*!< LPC_FLASHCTRL_FMSSTOP: STRTBIST Position*/
#define LPC_FLASHCTRL_FMSSTOP_STRTBIST(x)        (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSSTOP_STRTBIST_SHIFT))&LPC_FLASHCTRL_FMSSTOP_STRTBIST_MASK) /*!< LPC_FLASHCTRL_FMSSTOP                   */
/* ------- FMSW0 Bit Fields                         ------ */
#define LPC_FLASHCTRL_FMSW0_SIG_MASK             (0xFFFFFFFFU)                                       /*!< LPC_FLASHCTRL_FMSW0: SIG Mask           */
#define LPC_FLASHCTRL_FMSW0_SIG_SHIFT            (0U)                                                /*!< LPC_FLASHCTRL_FMSW0: SIG Position       */
#define LPC_FLASHCTRL_FMSW0_SIG(x)               (((uint32_t)(((uint32_t)(x))<<LPC_FLASHCTRL_FMSW0_SIG_SHIFT))&LPC_FLASHCTRL_FMSW0_SIG_MASK) /*!< LPC_FLASHCTRL_FMSW0                     */
/**
 * @} */ /* End group FLASHCTRL_Register_Masks_GROUP 
 */

/* LPC_FLASHCTRL - Peripheral instance base addresses */
#define LPC_FLASHCTRL_BasePtr          0x40040000UL //!< Peripheral base address
#define LPC_FLASHCTRL                  ((LPC_FLASHCTRL_Type *) LPC_FLASHCTRL_BasePtr) //!< Freescale base pointer
#define LPC_FLASHCTRL_BASE_PTR         (LPC_FLASHCTRL) //!< Freescale style base pointer
/**
 * @} */ /* End group FLASHCTRL_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_PORT_Peripheral_access_layer_GROUP GPIO_PORT Peripheral Access Layer
* @brief C Struct for GPIO_PORT
* @{
*/

/* ================================================================================ */
/* ================           LPC_GPIO_PORT (file:GPIO_PORT_LPC82x)       ================ */
/* ================================================================================ */

/**
 * @brief General Purpose I/O port
 */
/**
* @addtogroup GPIO_PORT_structs_GROUP GPIO_PORT struct
* @brief Struct for GPIO_PORT
* @{
*/
typedef struct {                                /*       LPC_GPIO_PORT Structure                                      */
   __IO uint8_t   B0;                           /**< 0000: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
   __IO uint8_t   B1;                           /**< 0001: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
   __IO uint8_t   B2;                           /**< 0002: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
   __IO uint8_t   B3;                           /**< 0003: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   B4;                           /**< 0004: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   B5;                           /**< 0005: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_2;                  
   __IO uint8_t   B6;                           /**< 0006: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_3;                  
   __IO uint8_t   B7;                           /**< 0007: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_4;                  
   __IO uint8_t   B8;                           /**< 0008: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
   __IO uint8_t   B9;                           /**< 0009: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_5;                  
   __IO uint8_t   B10;                          /**< 000A: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_6;                  
   __IO uint8_t   B11;                          /**< 000B: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_7;                  
   __IO uint8_t   B12;                          /**< 000C: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_8;                  
   __IO uint8_t   B13;                          /**< 000D: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_9;                  
   __IO uint8_t   B14;                          /**< 000E: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_10;                 
   __IO uint8_t   B15;                          /**< 000F: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_11;                 
   __IO uint8_t   B16;                          /**< 0010: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_12;                 
   __IO uint8_t   B17;                          /**< 0011: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_13;                 
   __IO uint8_t   B18;                          /**< 0012: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_14;                 
   __IO uint8_t   B19;                          /**< 0013: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_15;                 
   __IO uint8_t   B20;                          /**< 0014: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_16;                 
   __IO uint8_t   B21;                          /**< 0015: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_17;                 
   __IO uint8_t   B22;                          /**< 0016: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_18;                 
   __IO uint8_t   B23;                          /**< 0017: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_19;                 
   __IO uint8_t   B24;                          /**< 0018: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_20;                 
   __IO uint8_t   B25;                          /**< 0019: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_21;                 
   __IO uint8_t   B26;                          /**< 001A: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_22;                 
   __IO uint8_t   B27;                          /**< 001B: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_23;                 
   __IO uint8_t   B28;                          /**< 001C: Byte pin registers port 0; pins PIO0_0 to PIO0_28            */
        uint8_t   RESERVED_24[4067];           
   __IO uint32_t  W0;                           /**< 1000: Word pin registers port 0                                    */
   __IO uint32_t  W1;                           /**< 1004: Word pin registers port 0                                    */
   __IO uint32_t  W2;                           /**< 1008: Word pin registers port 0                                    */
   __IO uint32_t  W3;                           /**< 100C: Word pin registers port 0                                    */
   __IO uint32_t  W4;                           /**< 1010: Word pin registers port 0                                    */
   __IO uint32_t  W5;                           /**< 1014: Word pin registers port 0                                    */
   __IO uint32_t  W6;                           /**< 1018: Word pin registers port 0                                    */
   __IO uint32_t  W7;                           /**< 101C: Word pin registers port 0                                    */
   __IO uint32_t  W8;                           /**< 1020: Word pin registers port 0                                    */
   __IO uint32_t  W9;                           /**< 1024: Word pin registers port 0                                    */
   __IO uint32_t  W10;                          /**< 1028: Word pin registers port 0                                    */
   __IO uint32_t  W11;                          /**< 102C: Word pin registers port 0                                    */
   __IO uint32_t  W12;                          /**< 1030: Word pin registers port 0                                    */
   __IO uint32_t  W13;                          /**< 1034: Word pin registers port 0                                    */
   __IO uint32_t  W14;                          /**< 1038: Word pin registers port 0                                    */
   __IO uint32_t  W15;                          /**< 103C: Word pin registers port 0                                    */
   __IO uint32_t  W16;                          /**< 1040: Word pin registers port 0                                    */
   __IO uint32_t  W17;                          /**< 1044: Word pin registers port 0                                    */
   __IO uint32_t  W18;                          /**< 1048: Word pin registers port 0                                    */
   __IO uint32_t  W19;                          /**< 104C: Word pin registers port 0                                    */
   __IO uint32_t  W20;                          /**< 1050: Word pin registers port 0                                    */
   __IO uint32_t  W21;                          /**< 1054: Word pin registers port 0                                    */
   __IO uint32_t  W22;                          /**< 1058: Word pin registers port 0                                    */
   __IO uint32_t  W23;                          /**< 105C: Word pin registers port 0                                    */
   __IO uint32_t  W24;                          /**< 1060: Word pin registers port 0                                    */
   __IO uint32_t  W25;                          /**< 1064: Word pin registers port 0                                    */
   __IO uint32_t  W26;                          /**< 1068: Word pin registers port 0                                    */
   __IO uint32_t  W27;                          /**< 106C: Word pin registers port 0                                    */
   __IO uint32_t  W28;                          /**< 1070: Word pin registers port 0                                    */
        uint8_t   RESERVED_25[3980];           
   __IO uint32_t  DIR0;                         /**< 2000: Direction registers port 0                                   */
        uint8_t   RESERVED_26[124];            
   __IO uint32_t  MASK0;                        /**< 2080: Mask register port 0                                         */
        uint8_t   RESERVED_27[124];            
   __IO uint32_t  PIN0;                         /**< 2100: Port pin register port 0                                     */
        uint8_t   RESERVED_28[124];            
   __IO uint32_t  MPIN0;                        /**< 2180: Masked port register port 0                                  */
        uint8_t   RESERVED_29[124];            
   __IO uint32_t  SET0;                         /**< 2200: Write: Set register for port 0 Read: output bits for port 0  */
        uint8_t   RESERVED_30[124];            
   __O  uint32_t  CLR0;                         /**< 2280: Clear port 0                                                 */
        uint8_t   RESERVED_31[124];            
   __O  uint32_t  NOT0;                         /**< 2300: Toggle port 0                                                */
        uint8_t   RESERVED_32[124];            
   __O  uint32_t  DIRSET0;                      /**< 2380: Set pin direction bits for port 0                            */
        uint8_t   RESERVED_33[124];            
   __O  uint32_t  DIRCLR0;                      /**< 2400: Clear pin direction bits for port 0                          */
        uint8_t   RESERVED_34[124];            
   __O  uint32_t  DIRNOT0;                      /**< 2480: Toggle pin direction bits for port 0                         */
} LPC_GPIO_PORT_Type;

/**
 * @} */ /* End group GPIO_PORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_GPIO_PORT' Position & Mask macros               ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_PORT_Register_Masks_GROUP GPIO_PORT Register Masks
* @brief Register Masks for GPIO_PORT
* @{
*/
/* ------- B0 Bit Fields                            ------ */
#define LPC_GPIO_PORT_B0_PBYTE_MASK              (0x1U)                                              /*!< LPC_GPIO_PORT_B0: PBYTE Mask            */
#define LPC_GPIO_PORT_B0_PBYTE_SHIFT             (0U)                                                /*!< LPC_GPIO_PORT_B0: PBYTE Position        */
#define LPC_GPIO_PORT_B0_PBYTE(x)                (((uint8_t)(((uint8_t)(x))<<LPC_GPIO_PORT_B0_PBYTE_SHIFT))&LPC_GPIO_PORT_B0_PBYTE_MASK) /*!< LPC_GPIO_PORT_B0                        */
/* ------- B1 Bit Fields                            ------ */
#define LPC_GPIO_PORT_B1_PBYTE_MASK              (0x1U)                                              /*!< LPC_GPIO_PORT_B1: PBYTE Mask            */
#define LPC_GPIO_PORT_B1_PBYTE_SHIFT             (0U)                                                /*!< LPC_GPIO_PORT_B1: PBYTE Position        */
#define LPC_GPIO_PORT_B1_PBYTE(x)                (((uint8_t)(((uint8_t)(x))<<LPC_GPIO_PORT_B1_PBYTE_SHIFT))&LPC_GPIO_PORT_B1_PBYTE_MASK) /*!< LPC_GPIO_PORT_B1                        */
/* ------- B2 Bit Fields                            ------ */
#define LPC_GPIO_PORT_B2_PBYTE_MASK              (0x1U)                                              /*!< LPC_GPIO_PORT_B2: PBYTE Mask            */
#define LPC_GPIO_PORT_B2_PBYTE_SHIFT             (0U)                                                /*!< LPC_GPIO_PORT_B2: PBYTE Position        */
#define LPC_GPIO_PORT_B2_PBYTE(x)                (((uint8_t)(((uint8_t)(x))<<LPC_GPIO_PORT_B2_PBYTE_SHIFT))&LPC_GPIO_PORT_B2_PBYTE_MASK) /*!< LPC_GPIO_PORT_B2                        */
/* ------- B Bit Fields                             ------ */
#define LPC_GPIO_PORT_B_PBYTE_MASK               (0x1U)                                              /*!< LPC_GPIO_PORT_B: PBYTE Mask             */
#define LPC_GPIO_PORT_B_PBYTE_SHIFT              (0U)                                                /*!< LPC_GPIO_PORT_B: PBYTE Position         */
#define LPC_GPIO_PORT_B_PBYTE(x)                 (((uint8_t)(((uint8_t)(x))<<LPC_GPIO_PORT_B_PBYTE_SHIFT))&LPC_GPIO_PORT_B_PBYTE_MASK) /*!< LPC_GPIO_PORT_B                         */
/* ------- B8 Bit Fields                            ------ */
#define LPC_GPIO_PORT_B8_PBYTE_MASK              (0x1U)                                              /*!< LPC_GPIO_PORT_B8: PBYTE Mask            */
#define LPC_GPIO_PORT_B8_PBYTE_SHIFT             (0U)                                                /*!< LPC_GPIO_PORT_B8: PBYTE Position        */
#define LPC_GPIO_PORT_B8_PBYTE(x)                (((uint8_t)(((uint8_t)(x))<<LPC_GPIO_PORT_B8_PBYTE_SHIFT))&LPC_GPIO_PORT_B8_PBYTE_MASK) /*!< LPC_GPIO_PORT_B8                        */
/* ------- B Bit Fields                             ------ */
/* ------- B28 Bit Fields                           ------ */
#define LPC_GPIO_PORT_B28_PBYTE_MASK             (0x1U)                                              /*!< LPC_GPIO_PORT_B28: PBYTE Mask           */
#define LPC_GPIO_PORT_B28_PBYTE_SHIFT            (0U)                                                /*!< LPC_GPIO_PORT_B28: PBYTE Position       */
#define LPC_GPIO_PORT_B28_PBYTE(x)               (((uint8_t)(((uint8_t)(x))<<LPC_GPIO_PORT_B28_PBYTE_SHIFT))&LPC_GPIO_PORT_B28_PBYTE_MASK) /*!< LPC_GPIO_PORT_B28                       */
/* ------- W0 Bit Fields                            ------ */
#define LPC_GPIO_PORT_W0_PWORD_MASK              (0xFFFFFFFFU)                                       /*!< LPC_GPIO_PORT_W0: PWORD Mask            */
#define LPC_GPIO_PORT_W0_PWORD_SHIFT             (0U)                                                /*!< LPC_GPIO_PORT_W0: PWORD Position        */
#define LPC_GPIO_PORT_W0_PWORD(x)                (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_W0_PWORD_SHIFT))&LPC_GPIO_PORT_W0_PWORD_MASK) /*!< LPC_GPIO_PORT_W0                        */
/* ------- W Bit Fields                             ------ */
#define LPC_GPIO_PORT_W_PWORD_MASK               (0xFFFFFFFFU)                                       /*!< LPC_GPIO_PORT_W: PWORD Mask             */
#define LPC_GPIO_PORT_W_PWORD_SHIFT              (0U)                                                /*!< LPC_GPIO_PORT_W: PWORD Position         */
#define LPC_GPIO_PORT_W_PWORD(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_W_PWORD_SHIFT))&LPC_GPIO_PORT_W_PWORD_MASK) /*!< LPC_GPIO_PORT_W                         */
/* ------- DIR0 Bit Fields                          ------ */
#define LPC_GPIO_PORT_DIR0_DIRP_MASK             (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_DIR0: DIRP Mask           */
#define LPC_GPIO_PORT_DIR0_DIRP_SHIFT            (0U)                                                /*!< LPC_GPIO_PORT_DIR0: DIRP Position       */
#define LPC_GPIO_PORT_DIR0_DIRP(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIR0_DIRP_SHIFT))&LPC_GPIO_PORT_DIR0_DIRP_MASK) /*!< LPC_GPIO_PORT_DIR0                      */
/* ------- MASK0 Bit Fields                         ------ */
#define LPC_GPIO_PORT_MASK0_MASKP_MASK           (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_MASK0: MASKP Mask         */
#define LPC_GPIO_PORT_MASK0_MASKP_SHIFT          (0U)                                                /*!< LPC_GPIO_PORT_MASK0: MASKP Position     */
#define LPC_GPIO_PORT_MASK0_MASKP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MASK0_MASKP_SHIFT))&LPC_GPIO_PORT_MASK0_MASKP_MASK) /*!< LPC_GPIO_PORT_MASK0                     */
/* ------- PIN0 Bit Fields                          ------ */
#define LPC_GPIO_PORT_PIN0_PORT_MASK             (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_PIN0: PORT Mask           */
#define LPC_GPIO_PORT_PIN0_PORT_SHIFT            (0U)                                                /*!< LPC_GPIO_PORT_PIN0: PORT Position       */
#define LPC_GPIO_PORT_PIN0_PORT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_PIN0_PORT_SHIFT))&LPC_GPIO_PORT_PIN0_PORT_MASK) /*!< LPC_GPIO_PORT_PIN0                      */
/* ------- MPIN0 Bit Fields                         ------ */
#define LPC_GPIO_PORT_MPIN0_MPORTP_MASK          (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_MPIN0: MPORTP Mask        */
#define LPC_GPIO_PORT_MPIN0_MPORTP_SHIFT         (0U)                                                /*!< LPC_GPIO_PORT_MPIN0: MPORTP Position    */
#define LPC_GPIO_PORT_MPIN0_MPORTP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_MPIN0_MPORTP_SHIFT))&LPC_GPIO_PORT_MPIN0_MPORTP_MASK) /*!< LPC_GPIO_PORT_MPIN0                     */
/* ------- SET0 Bit Fields                          ------ */
#define LPC_GPIO_PORT_SET0_SETP_MASK             (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_SET0: SETP Mask           */
#define LPC_GPIO_PORT_SET0_SETP_SHIFT            (0U)                                                /*!< LPC_GPIO_PORT_SET0: SETP Position       */
#define LPC_GPIO_PORT_SET0_SETP(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_SET0_SETP_SHIFT))&LPC_GPIO_PORT_SET0_SETP_MASK) /*!< LPC_GPIO_PORT_SET0                      */
/* ------- CLR0 Bit Fields                          ------ */
#define LPC_GPIO_PORT_CLR0_CLRP_MASK             (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_CLR0: CLRP Mask           */
#define LPC_GPIO_PORT_CLR0_CLRP_SHIFT            (0U)                                                /*!< LPC_GPIO_PORT_CLR0: CLRP Position       */
#define LPC_GPIO_PORT_CLR0_CLRP(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_CLR0_CLRP_SHIFT))&LPC_GPIO_PORT_CLR0_CLRP_MASK) /*!< LPC_GPIO_PORT_CLR0                      */
/* ------- NOT0 Bit Fields                          ------ */
#define LPC_GPIO_PORT_NOT0_NOTP_MASK             (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_NOT0: NOTP Mask           */
#define LPC_GPIO_PORT_NOT0_NOTP_SHIFT            (0U)                                                /*!< LPC_GPIO_PORT_NOT0: NOTP Position       */
#define LPC_GPIO_PORT_NOT0_NOTP(x)               (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_NOT0_NOTP_SHIFT))&LPC_GPIO_PORT_NOT0_NOTP_MASK) /*!< LPC_GPIO_PORT_NOT0                      */
/* ------- DIRSET0 Bit Fields                       ------ */
#define LPC_GPIO_PORT_DIRSET0_DIRSETP_MASK       (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_DIRSET0: DIRSETP Mask     */
#define LPC_GPIO_PORT_DIRSET0_DIRSETP_SHIFT      (0U)                                                /*!< LPC_GPIO_PORT_DIRSET0: DIRSETP Position */
#define LPC_GPIO_PORT_DIRSET0_DIRSETP(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIRSET0_DIRSETP_SHIFT))&LPC_GPIO_PORT_DIRSET0_DIRSETP_MASK) /*!< LPC_GPIO_PORT_DIRSET0                   */
/* ------- DIRCLR0 Bit Fields                       ------ */
#define LPC_GPIO_PORT_DIRCLR0_DIRCLRP_MASK       (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_DIRCLR0: DIRCLRP Mask     */
#define LPC_GPIO_PORT_DIRCLR0_DIRCLRP_SHIFT      (0U)                                                /*!< LPC_GPIO_PORT_DIRCLR0: DIRCLRP Position */
#define LPC_GPIO_PORT_DIRCLR0_DIRCLRP(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIRCLR0_DIRCLRP_SHIFT))&LPC_GPIO_PORT_DIRCLR0_DIRCLRP_MASK) /*!< LPC_GPIO_PORT_DIRCLR0                   */
/* ------- DIRNOT0 Bit Fields                       ------ */
#define LPC_GPIO_PORT_DIRNOT0_DIRNOTP_MASK       (0x1FFFFFFFU)                                       /*!< LPC_GPIO_PORT_DIRNOT0: DIRNOTP Mask     */
#define LPC_GPIO_PORT_DIRNOT0_DIRNOTP_SHIFT      (0U)                                                /*!< LPC_GPIO_PORT_DIRNOT0: DIRNOTP Position */
#define LPC_GPIO_PORT_DIRNOT0_DIRNOTP(x)         (((uint32_t)(((uint32_t)(x))<<LPC_GPIO_PORT_DIRNOT0_DIRNOTP_SHIFT))&LPC_GPIO_PORT_DIRNOT0_DIRNOTP_MASK) /*!< LPC_GPIO_PORT_DIRNOT0                   */
/**
 * @} */ /* End group GPIO_PORT_Register_Masks_GROUP 
 */

/* LPC_GPIO_PORT - Peripheral instance base addresses */
#define LPC_GPIO_PORT_BasePtr          0xA0000000UL //!< Peripheral base address
#define LPC_GPIO_PORT                  ((LPC_GPIO_PORT_Type *) LPC_GPIO_PORT_BasePtr) //!< Freescale base pointer
#define LPC_GPIO_PORT_BASE_PTR         (LPC_GPIO_PORT) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           LPC_I2C0 (file:I2C0_LPC82x)          ================ */
/* ================================================================================ */

/**
 * @brief I2C0-bus interface
 */
/**
* @addtogroup I2C_structs_GROUP I2C struct
* @brief Struct for I2C
* @{
*/
typedef struct {                                /*       LPC_I2C0 Structure                                           */
   __IO uint32_t  CFG;                          /**< 0000: Configuration for shared functions                           */
   __IO uint32_t  STAT;                         /**< 0004: Status register for Master, Slave, and Monitor functions     */
   __IO uint32_t  INTENSET;                     /**< 0008: Interrupt Enable Set and read register                       */
   __O  uint32_t  INTENCLR;                     /**< 000C: Interrupt Enable Clear register                              */
   __IO uint32_t  TIMEOUT;                      /**< 0010: Time-out value register                                      */
   __IO uint32_t  CLKDIV;                       /**< 0014: Clock pre-divider for the entire I2C block. This determines what time increments are used for the MSTTIME and SLVTIME */
   __I  uint32_t  INTSTAT;                      /**< 0018: Interrupt Status register for Master, Slave, and Monitor functions */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  MSTCTL;                       /**< 0020: Master control register                                      */
   __IO uint32_t  MSTTIME;                      /**< 0024: Master timing configuration                                  */
   __IO uint32_t  MSTDAT;                       /**< 0028: Combined Master receiver and transmitter data register       */
        uint8_t   RESERVED_1[20];              
   __IO uint32_t  SLVCTL;                       /**< 0040: Slave control register                                       */
   __IO uint32_t  SLVDAT;                       /**< 0044: Combined Slave receiver and transmitter data register        */
   __IO uint32_t  SLVADR0;                      /**< 0048: Slave address 0                                              */
   __IO uint32_t  SLVADR1;                      /**< 004C: Slave address 0                                              */
   __IO uint32_t  SLVADR2;                      /**< 0050: Slave address 0                                              */
   __IO uint32_t  SLVADR3;                      /**< 0054: Slave address 0                                              */
   __IO uint32_t  SLVQUAL0;                     /**< 0058: Slave Qualification for address 0                            */
        uint8_t   RESERVED_2[36];              
   __I  uint32_t  MONRXDAT;                     /**< 0080: Monitor receiver data register                               */
} LPC_I2C0_Type;

/**
 * @} */ /* End group I2C_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_I2C0' Position & Mask macros                    ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2C_Register_Masks_GROUP I2C Register Masks
* @brief Register Masks for I2C
* @{
*/
/* ------- CFG Bit Fields                           ------ */
#define LPC_I2C0_CFG_MSTEN_MASK                  (0x1U)                                              /*!< LPC_I2C0_CFG: MSTEN Mask                */
#define LPC_I2C0_CFG_MSTEN_SHIFT                 (0U)                                                /*!< LPC_I2C0_CFG: MSTEN Position            */
#define LPC_I2C0_CFG_MSTEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_CFG_MSTEN_SHIFT))&LPC_I2C0_CFG_MSTEN_MASK) /*!< LPC_I2C0_CFG                            */
#define LPC_I2C0_CFG_SLVEN_MASK                  (0x2U)                                              /*!< LPC_I2C0_CFG: SLVEN Mask                */
#define LPC_I2C0_CFG_SLVEN_SHIFT                 (1U)                                                /*!< LPC_I2C0_CFG: SLVEN Position            */
#define LPC_I2C0_CFG_SLVEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_CFG_SLVEN_SHIFT))&LPC_I2C0_CFG_SLVEN_MASK) /*!< LPC_I2C0_CFG                            */
#define LPC_I2C0_CFG_MONEN_MASK                  (0x4U)                                              /*!< LPC_I2C0_CFG: MONEN Mask                */
#define LPC_I2C0_CFG_MONEN_SHIFT                 (2U)                                                /*!< LPC_I2C0_CFG: MONEN Position            */
#define LPC_I2C0_CFG_MONEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_CFG_MONEN_SHIFT))&LPC_I2C0_CFG_MONEN_MASK) /*!< LPC_I2C0_CFG                            */
#define LPC_I2C0_CFG_TIMEOUTEN_MASK              (0x8U)                                              /*!< LPC_I2C0_CFG: TIMEOUTEN Mask            */
#define LPC_I2C0_CFG_TIMEOUTEN_SHIFT             (3U)                                                /*!< LPC_I2C0_CFG: TIMEOUTEN Position        */
#define LPC_I2C0_CFG_TIMEOUTEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_CFG_TIMEOUTEN_SHIFT))&LPC_I2C0_CFG_TIMEOUTEN_MASK) /*!< LPC_I2C0_CFG                            */
#define LPC_I2C0_CFG_MONCLKSTR_MASK              (0x10U)                                             /*!< LPC_I2C0_CFG: MONCLKSTR Mask            */
#define LPC_I2C0_CFG_MONCLKSTR_SHIFT             (4U)                                                /*!< LPC_I2C0_CFG: MONCLKSTR Position        */
#define LPC_I2C0_CFG_MONCLKSTR(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_CFG_MONCLKSTR_SHIFT))&LPC_I2C0_CFG_MONCLKSTR_MASK) /*!< LPC_I2C0_CFG                            */
/* ------- STAT Bit Fields                          ------ */
#define LPC_I2C0_STAT_MSTPENDING_MASK            (0x1U)                                              /*!< LPC_I2C0_STAT: MSTPENDING Mask          */
#define LPC_I2C0_STAT_MSTPENDING_SHIFT           (0U)                                                /*!< LPC_I2C0_STAT: MSTPENDING Position      */
#define LPC_I2C0_STAT_MSTPENDING(x)              (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_MSTPENDING_SHIFT))&LPC_I2C0_STAT_MSTPENDING_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_MSTSTATE_MASK              (0xEU)                                              /*!< LPC_I2C0_STAT: MSTSTATE Mask            */
#define LPC_I2C0_STAT_MSTSTATE_SHIFT             (1U)                                                /*!< LPC_I2C0_STAT: MSTSTATE Position        */
#define LPC_I2C0_STAT_MSTSTATE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_MSTSTATE_SHIFT))&LPC_I2C0_STAT_MSTSTATE_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_MSTARBLOSS_MASK            (0x10U)                                             /*!< LPC_I2C0_STAT: MSTARBLOSS Mask          */
#define LPC_I2C0_STAT_MSTARBLOSS_SHIFT           (4U)                                                /*!< LPC_I2C0_STAT: MSTARBLOSS Position      */
#define LPC_I2C0_STAT_MSTARBLOSS(x)              (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_MSTARBLOSS_SHIFT))&LPC_I2C0_STAT_MSTARBLOSS_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_MSTSTSTPERR_MASK           (0x40U)                                             /*!< LPC_I2C0_STAT: MSTSTSTPERR Mask         */
#define LPC_I2C0_STAT_MSTSTSTPERR_SHIFT          (6U)                                                /*!< LPC_I2C0_STAT: MSTSTSTPERR Position     */
#define LPC_I2C0_STAT_MSTSTSTPERR(x)             (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_MSTSTSTPERR_SHIFT))&LPC_I2C0_STAT_MSTSTSTPERR_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_SLVPENDING_MASK            (0x100U)                                            /*!< LPC_I2C0_STAT: SLVPENDING Mask          */
#define LPC_I2C0_STAT_SLVPENDING_SHIFT           (8U)                                                /*!< LPC_I2C0_STAT: SLVPENDING Position      */
#define LPC_I2C0_STAT_SLVPENDING(x)              (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_SLVPENDING_SHIFT))&LPC_I2C0_STAT_SLVPENDING_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_SLVSTATE_MASK              (0x600U)                                            /*!< LPC_I2C0_STAT: SLVSTATE Mask            */
#define LPC_I2C0_STAT_SLVSTATE_SHIFT             (9U)                                                /*!< LPC_I2C0_STAT: SLVSTATE Position        */
#define LPC_I2C0_STAT_SLVSTATE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_SLVSTATE_SHIFT))&LPC_I2C0_STAT_SLVSTATE_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_SLVNOTSTR_MASK             (0x800U)                                            /*!< LPC_I2C0_STAT: SLVNOTSTR Mask           */
#define LPC_I2C0_STAT_SLVNOTSTR_SHIFT            (11U)                                               /*!< LPC_I2C0_STAT: SLVNOTSTR Position       */
#define LPC_I2C0_STAT_SLVNOTSTR(x)               (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_SLVNOTSTR_SHIFT))&LPC_I2C0_STAT_SLVNOTSTR_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_SLVIDX_MASK                (0x3000U)                                           /*!< LPC_I2C0_STAT: SLVIDX Mask              */
#define LPC_I2C0_STAT_SLVIDX_SHIFT               (12U)                                               /*!< LPC_I2C0_STAT: SLVIDX Position          */
#define LPC_I2C0_STAT_SLVIDX(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_SLVIDX_SHIFT))&LPC_I2C0_STAT_SLVIDX_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_SLVSEL_MASK                (0x4000U)                                           /*!< LPC_I2C0_STAT: SLVSEL Mask              */
#define LPC_I2C0_STAT_SLVSEL_SHIFT               (14U)                                               /*!< LPC_I2C0_STAT: SLVSEL Position          */
#define LPC_I2C0_STAT_SLVSEL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_SLVSEL_SHIFT))&LPC_I2C0_STAT_SLVSEL_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_SLVDESEL_MASK              (0x8000U)                                           /*!< LPC_I2C0_STAT: SLVDESEL Mask            */
#define LPC_I2C0_STAT_SLVDESEL_SHIFT             (15U)                                               /*!< LPC_I2C0_STAT: SLVDESEL Position        */
#define LPC_I2C0_STAT_SLVDESEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_SLVDESEL_SHIFT))&LPC_I2C0_STAT_SLVDESEL_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_MONRDY_MASK                (0x10000U)                                          /*!< LPC_I2C0_STAT: MONRDY Mask              */
#define LPC_I2C0_STAT_MONRDY_SHIFT               (16U)                                               /*!< LPC_I2C0_STAT: MONRDY Position          */
#define LPC_I2C0_STAT_MONRDY(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_MONRDY_SHIFT))&LPC_I2C0_STAT_MONRDY_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_MONOV_MASK                 (0x20000U)                                          /*!< LPC_I2C0_STAT: MONOV Mask               */
#define LPC_I2C0_STAT_MONOV_SHIFT                (17U)                                               /*!< LPC_I2C0_STAT: MONOV Position           */
#define LPC_I2C0_STAT_MONOV(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_MONOV_SHIFT))&LPC_I2C0_STAT_MONOV_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_MONACTIVE_MASK             (0x40000U)                                          /*!< LPC_I2C0_STAT: MONACTIVE Mask           */
#define LPC_I2C0_STAT_MONACTIVE_SHIFT            (18U)                                               /*!< LPC_I2C0_STAT: MONACTIVE Position       */
#define LPC_I2C0_STAT_MONACTIVE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_MONACTIVE_SHIFT))&LPC_I2C0_STAT_MONACTIVE_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_MONIDLE_MASK               (0x80000U)                                          /*!< LPC_I2C0_STAT: MONIDLE Mask             */
#define LPC_I2C0_STAT_MONIDLE_SHIFT              (19U)                                               /*!< LPC_I2C0_STAT: MONIDLE Position         */
#define LPC_I2C0_STAT_MONIDLE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_MONIDLE_SHIFT))&LPC_I2C0_STAT_MONIDLE_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_EVENTTIMEOUT_MASK          (0x1000000U)                                        /*!< LPC_I2C0_STAT: EVENTTIMEOUT Mask        */
#define LPC_I2C0_STAT_EVENTTIMEOUT_SHIFT         (24U)                                               /*!< LPC_I2C0_STAT: EVENTTIMEOUT Position    */
#define LPC_I2C0_STAT_EVENTTIMEOUT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_EVENTTIMEOUT_SHIFT))&LPC_I2C0_STAT_EVENTTIMEOUT_MASK) /*!< LPC_I2C0_STAT                           */
#define LPC_I2C0_STAT_SCLTIMEOUT_MASK            (0x2000000U)                                        /*!< LPC_I2C0_STAT: SCLTIMEOUT Mask          */
#define LPC_I2C0_STAT_SCLTIMEOUT_SHIFT           (25U)                                               /*!< LPC_I2C0_STAT: SCLTIMEOUT Position      */
#define LPC_I2C0_STAT_SCLTIMEOUT(x)              (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_STAT_SCLTIMEOUT_SHIFT))&LPC_I2C0_STAT_SCLTIMEOUT_MASK) /*!< LPC_I2C0_STAT                           */
/* ------- INTENSET Bit Fields                      ------ */
#define LPC_I2C0_INTENSET_MSTPENDINGEN_MASK      (0x1U)                                              /*!< LPC_I2C0_INTENSET: MSTPENDINGEN Mask    */
#define LPC_I2C0_INTENSET_MSTPENDINGEN_SHIFT     (0U)                                                /*!< LPC_I2C0_INTENSET: MSTPENDINGEN Position*/
#define LPC_I2C0_INTENSET_MSTPENDINGEN(x)        (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_MSTPENDINGEN_SHIFT))&LPC_I2C0_INTENSET_MSTPENDINGEN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_MSTARBLOSSEN_MASK      (0x10U)                                             /*!< LPC_I2C0_INTENSET: MSTARBLOSSEN Mask    */
#define LPC_I2C0_INTENSET_MSTARBLOSSEN_SHIFT     (4U)                                                /*!< LPC_I2C0_INTENSET: MSTARBLOSSEN Position*/
#define LPC_I2C0_INTENSET_MSTARBLOSSEN(x)        (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_MSTARBLOSSEN_SHIFT))&LPC_I2C0_INTENSET_MSTARBLOSSEN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_MSTSTSTPERREN_MASK     (0x40U)                                             /*!< LPC_I2C0_INTENSET: MSTSTSTPERREN Mask   */
#define LPC_I2C0_INTENSET_MSTSTSTPERREN_SHIFT    (6U)                                                /*!< LPC_I2C0_INTENSET: MSTSTSTPERREN Position*/
#define LPC_I2C0_INTENSET_MSTSTSTPERREN(x)       (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_MSTSTSTPERREN_SHIFT))&LPC_I2C0_INTENSET_MSTSTSTPERREN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_SLVPENDINGEN_MASK      (0x100U)                                            /*!< LPC_I2C0_INTENSET: SLVPENDINGEN Mask    */
#define LPC_I2C0_INTENSET_SLVPENDINGEN_SHIFT     (8U)                                                /*!< LPC_I2C0_INTENSET: SLVPENDINGEN Position*/
#define LPC_I2C0_INTENSET_SLVPENDINGEN(x)        (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_SLVPENDINGEN_SHIFT))&LPC_I2C0_INTENSET_SLVPENDINGEN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_SLVNOTSTREN_MASK       (0x800U)                                            /*!< LPC_I2C0_INTENSET: SLVNOTSTREN Mask     */
#define LPC_I2C0_INTENSET_SLVNOTSTREN_SHIFT      (11U)                                               /*!< LPC_I2C0_INTENSET: SLVNOTSTREN Position */
#define LPC_I2C0_INTENSET_SLVNOTSTREN(x)         (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_SLVNOTSTREN_SHIFT))&LPC_I2C0_INTENSET_SLVNOTSTREN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_SLVDESELEN_MASK        (0x8000U)                                           /*!< LPC_I2C0_INTENSET: SLVDESELEN Mask      */
#define LPC_I2C0_INTENSET_SLVDESELEN_SHIFT       (15U)                                               /*!< LPC_I2C0_INTENSET: SLVDESELEN Position  */
#define LPC_I2C0_INTENSET_SLVDESELEN(x)          (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_SLVDESELEN_SHIFT))&LPC_I2C0_INTENSET_SLVDESELEN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_MONRDYEN_MASK          (0x10000U)                                          /*!< LPC_I2C0_INTENSET: MONRDYEN Mask        */
#define LPC_I2C0_INTENSET_MONRDYEN_SHIFT         (16U)                                               /*!< LPC_I2C0_INTENSET: MONRDYEN Position    */
#define LPC_I2C0_INTENSET_MONRDYEN(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_MONRDYEN_SHIFT))&LPC_I2C0_INTENSET_MONRDYEN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_MONOVEN_MASK           (0x20000U)                                          /*!< LPC_I2C0_INTENSET: MONOVEN Mask         */
#define LPC_I2C0_INTENSET_MONOVEN_SHIFT          (17U)                                               /*!< LPC_I2C0_INTENSET: MONOVEN Position     */
#define LPC_I2C0_INTENSET_MONOVEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_MONOVEN_SHIFT))&LPC_I2C0_INTENSET_MONOVEN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_MONIDLEEN_MASK         (0x80000U)                                          /*!< LPC_I2C0_INTENSET: MONIDLEEN Mask       */
#define LPC_I2C0_INTENSET_MONIDLEEN_SHIFT        (19U)                                               /*!< LPC_I2C0_INTENSET: MONIDLEEN Position   */
#define LPC_I2C0_INTENSET_MONIDLEEN(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_MONIDLEEN_SHIFT))&LPC_I2C0_INTENSET_MONIDLEEN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_EVENTTIMEOUTEN_MASK    (0x1000000U)                                        /*!< LPC_I2C0_INTENSET: EVENTTIMEOUTEN Mask  */
#define LPC_I2C0_INTENSET_EVENTTIMEOUTEN_SHIFT   (24U)                                               /*!< LPC_I2C0_INTENSET: EVENTTIMEOUTEN Position*/
#define LPC_I2C0_INTENSET_EVENTTIMEOUTEN(x)      (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_EVENTTIMEOUTEN_SHIFT))&LPC_I2C0_INTENSET_EVENTTIMEOUTEN_MASK) /*!< LPC_I2C0_INTENSET                       */
#define LPC_I2C0_INTENSET_SCLTIMEOUTEN_MASK      (0x2000000U)                                        /*!< LPC_I2C0_INTENSET: SCLTIMEOUTEN Mask    */
#define LPC_I2C0_INTENSET_SCLTIMEOUTEN_SHIFT     (25U)                                               /*!< LPC_I2C0_INTENSET: SCLTIMEOUTEN Position*/
#define LPC_I2C0_INTENSET_SCLTIMEOUTEN(x)        (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENSET_SCLTIMEOUTEN_SHIFT))&LPC_I2C0_INTENSET_SCLTIMEOUTEN_MASK) /*!< LPC_I2C0_INTENSET                       */
/* ------- INTENCLR Bit Fields                      ------ */
#define LPC_I2C0_INTENCLR_MSTPENDINGCLR_MASK     (0x1U)                                              /*!< LPC_I2C0_INTENCLR: MSTPENDINGCLR Mask   */
#define LPC_I2C0_INTENCLR_MSTPENDINGCLR_SHIFT    (0U)                                                /*!< LPC_I2C0_INTENCLR: MSTPENDINGCLR Position*/
#define LPC_I2C0_INTENCLR_MSTPENDINGCLR(x)       (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_MSTPENDINGCLR_SHIFT))&LPC_I2C0_INTENCLR_MSTPENDINGCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_MSTARBLOSSCLR_MASK     (0x10U)                                             /*!< LPC_I2C0_INTENCLR: MSTARBLOSSCLR Mask   */
#define LPC_I2C0_INTENCLR_MSTARBLOSSCLR_SHIFT    (4U)                                                /*!< LPC_I2C0_INTENCLR: MSTARBLOSSCLR Position*/
#define LPC_I2C0_INTENCLR_MSTARBLOSSCLR(x)       (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_MSTARBLOSSCLR_SHIFT))&LPC_I2C0_INTENCLR_MSTARBLOSSCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_MSTSTSTPERRCLR_MASK    (0x40U)                                             /*!< LPC_I2C0_INTENCLR: MSTSTSTPERRCLR Mask  */
#define LPC_I2C0_INTENCLR_MSTSTSTPERRCLR_SHIFT   (6U)                                                /*!< LPC_I2C0_INTENCLR: MSTSTSTPERRCLR Position*/
#define LPC_I2C0_INTENCLR_MSTSTSTPERRCLR(x)      (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_MSTSTSTPERRCLR_SHIFT))&LPC_I2C0_INTENCLR_MSTSTSTPERRCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_SLVPENDINGCLR_MASK     (0x100U)                                            /*!< LPC_I2C0_INTENCLR: SLVPENDINGCLR Mask   */
#define LPC_I2C0_INTENCLR_SLVPENDINGCLR_SHIFT    (8U)                                                /*!< LPC_I2C0_INTENCLR: SLVPENDINGCLR Position*/
#define LPC_I2C0_INTENCLR_SLVPENDINGCLR(x)       (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_SLVPENDINGCLR_SHIFT))&LPC_I2C0_INTENCLR_SLVPENDINGCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_SLVNOTSTRCLR_MASK      (0x800U)                                            /*!< LPC_I2C0_INTENCLR: SLVNOTSTRCLR Mask    */
#define LPC_I2C0_INTENCLR_SLVNOTSTRCLR_SHIFT     (11U)                                               /*!< LPC_I2C0_INTENCLR: SLVNOTSTRCLR Position*/
#define LPC_I2C0_INTENCLR_SLVNOTSTRCLR(x)        (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_SLVNOTSTRCLR_SHIFT))&LPC_I2C0_INTENCLR_SLVNOTSTRCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_SLVDESELCLR_MASK       (0x8000U)                                           /*!< LPC_I2C0_INTENCLR: SLVDESELCLR Mask     */
#define LPC_I2C0_INTENCLR_SLVDESELCLR_SHIFT      (15U)                                               /*!< LPC_I2C0_INTENCLR: SLVDESELCLR Position */
#define LPC_I2C0_INTENCLR_SLVDESELCLR(x)         (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_SLVDESELCLR_SHIFT))&LPC_I2C0_INTENCLR_SLVDESELCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_MONRDYCLR_MASK         (0x10000U)                                          /*!< LPC_I2C0_INTENCLR: MONRDYCLR Mask       */
#define LPC_I2C0_INTENCLR_MONRDYCLR_SHIFT        (16U)                                               /*!< LPC_I2C0_INTENCLR: MONRDYCLR Position   */
#define LPC_I2C0_INTENCLR_MONRDYCLR(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_MONRDYCLR_SHIFT))&LPC_I2C0_INTENCLR_MONRDYCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_MONOVCLR_MASK          (0x20000U)                                          /*!< LPC_I2C0_INTENCLR: MONOVCLR Mask        */
#define LPC_I2C0_INTENCLR_MONOVCLR_SHIFT         (17U)                                               /*!< LPC_I2C0_INTENCLR: MONOVCLR Position    */
#define LPC_I2C0_INTENCLR_MONOVCLR(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_MONOVCLR_SHIFT))&LPC_I2C0_INTENCLR_MONOVCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_MONIDLECLR_MASK        (0x80000U)                                          /*!< LPC_I2C0_INTENCLR: MONIDLECLR Mask      */
#define LPC_I2C0_INTENCLR_MONIDLECLR_SHIFT       (19U)                                               /*!< LPC_I2C0_INTENCLR: MONIDLECLR Position  */
#define LPC_I2C0_INTENCLR_MONIDLECLR(x)          (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_MONIDLECLR_SHIFT))&LPC_I2C0_INTENCLR_MONIDLECLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_EVENTTIMEOUTCLR_MASK   (0x1000000U)                                        /*!< LPC_I2C0_INTENCLR: EVENTTIMEOUTCLR Mask */
#define LPC_I2C0_INTENCLR_EVENTTIMEOUTCLR_SHIFT  (24U)                                               /*!< LPC_I2C0_INTENCLR: EVENTTIMEOUTCLR Position*/
#define LPC_I2C0_INTENCLR_EVENTTIMEOUTCLR(x)     (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_EVENTTIMEOUTCLR_SHIFT))&LPC_I2C0_INTENCLR_EVENTTIMEOUTCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
#define LPC_I2C0_INTENCLR_SCLTIMEOUTCLR_MASK     (0x2000000U)                                        /*!< LPC_I2C0_INTENCLR: SCLTIMEOUTCLR Mask   */
#define LPC_I2C0_INTENCLR_SCLTIMEOUTCLR_SHIFT    (25U)                                               /*!< LPC_I2C0_INTENCLR: SCLTIMEOUTCLR Position*/
#define LPC_I2C0_INTENCLR_SCLTIMEOUTCLR(x)       (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTENCLR_SCLTIMEOUTCLR_SHIFT))&LPC_I2C0_INTENCLR_SCLTIMEOUTCLR_MASK) /*!< LPC_I2C0_INTENCLR                       */
/* ------- TIMEOUT Bit Fields                       ------ */
#define LPC_I2C0_TIMEOUT_TOMIN_MASK              (0xFU)                                              /*!< LPC_I2C0_TIMEOUT: TOMIN Mask            */
#define LPC_I2C0_TIMEOUT_TOMIN_SHIFT             (0U)                                                /*!< LPC_I2C0_TIMEOUT: TOMIN Position        */
#define LPC_I2C0_TIMEOUT_TOMIN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_TIMEOUT_TOMIN_SHIFT))&LPC_I2C0_TIMEOUT_TOMIN_MASK) /*!< LPC_I2C0_TIMEOUT                        */
#define LPC_I2C0_TIMEOUT_TO_MASK                 (0xFFF0U)                                           /*!< LPC_I2C0_TIMEOUT: TO Mask               */
#define LPC_I2C0_TIMEOUT_TO_SHIFT                (4U)                                                /*!< LPC_I2C0_TIMEOUT: TO Position           */
#define LPC_I2C0_TIMEOUT_TO(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_TIMEOUT_TO_SHIFT))&LPC_I2C0_TIMEOUT_TO_MASK) /*!< LPC_I2C0_TIMEOUT                        */
/* ------- CLKDIV Bit Fields                        ------ */
#define LPC_I2C0_CLKDIV_DIVVAL_MASK              (0xFFFFU)                                           /*!< LPC_I2C0_CLKDIV: DIVVAL Mask            */
#define LPC_I2C0_CLKDIV_DIVVAL_SHIFT             (0U)                                                /*!< LPC_I2C0_CLKDIV: DIVVAL Position        */
#define LPC_I2C0_CLKDIV_DIVVAL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_CLKDIV_DIVVAL_SHIFT))&LPC_I2C0_CLKDIV_DIVVAL_MASK) /*!< LPC_I2C0_CLKDIV                         */
/* ------- INTSTAT Bit Fields                       ------ */
#define LPC_I2C0_INTSTAT_MSTPENDING_MASK         (0x1U)                                              /*!< LPC_I2C0_INTSTAT: MSTPENDING Mask       */
#define LPC_I2C0_INTSTAT_MSTPENDING_SHIFT        (0U)                                                /*!< LPC_I2C0_INTSTAT: MSTPENDING Position   */
#define LPC_I2C0_INTSTAT_MSTPENDING(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_MSTPENDING_SHIFT))&LPC_I2C0_INTSTAT_MSTPENDING_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_MSTARBLOSS_MASK         (0x10U)                                             /*!< LPC_I2C0_INTSTAT: MSTARBLOSS Mask       */
#define LPC_I2C0_INTSTAT_MSTARBLOSS_SHIFT        (4U)                                                /*!< LPC_I2C0_INTSTAT: MSTARBLOSS Position   */
#define LPC_I2C0_INTSTAT_MSTARBLOSS(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_MSTARBLOSS_SHIFT))&LPC_I2C0_INTSTAT_MSTARBLOSS_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_MSTSTSTPERR_MASK        (0x40U)                                             /*!< LPC_I2C0_INTSTAT: MSTSTSTPERR Mask      */
#define LPC_I2C0_INTSTAT_MSTSTSTPERR_SHIFT       (6U)                                                /*!< LPC_I2C0_INTSTAT: MSTSTSTPERR Position  */
#define LPC_I2C0_INTSTAT_MSTSTSTPERR(x)          (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_MSTSTSTPERR_SHIFT))&LPC_I2C0_INTSTAT_MSTSTSTPERR_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_SLVPENDING_MASK         (0x100U)                                            /*!< LPC_I2C0_INTSTAT: SLVPENDING Mask       */
#define LPC_I2C0_INTSTAT_SLVPENDING_SHIFT        (8U)                                                /*!< LPC_I2C0_INTSTAT: SLVPENDING Position   */
#define LPC_I2C0_INTSTAT_SLVPENDING(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_SLVPENDING_SHIFT))&LPC_I2C0_INTSTAT_SLVPENDING_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_SLVNOTSTR_MASK          (0x800U)                                            /*!< LPC_I2C0_INTSTAT: SLVNOTSTR Mask        */
#define LPC_I2C0_INTSTAT_SLVNOTSTR_SHIFT         (11U)                                               /*!< LPC_I2C0_INTSTAT: SLVNOTSTR Position    */
#define LPC_I2C0_INTSTAT_SLVNOTSTR(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_SLVNOTSTR_SHIFT))&LPC_I2C0_INTSTAT_SLVNOTSTR_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_SLVDESEL_MASK           (0x8000U)                                           /*!< LPC_I2C0_INTSTAT: SLVDESEL Mask         */
#define LPC_I2C0_INTSTAT_SLVDESEL_SHIFT          (15U)                                               /*!< LPC_I2C0_INTSTAT: SLVDESEL Position     */
#define LPC_I2C0_INTSTAT_SLVDESEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_SLVDESEL_SHIFT))&LPC_I2C0_INTSTAT_SLVDESEL_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_MONRDY_MASK             (0x10000U)                                          /*!< LPC_I2C0_INTSTAT: MONRDY Mask           */
#define LPC_I2C0_INTSTAT_MONRDY_SHIFT            (16U)                                               /*!< LPC_I2C0_INTSTAT: MONRDY Position       */
#define LPC_I2C0_INTSTAT_MONRDY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_MONRDY_SHIFT))&LPC_I2C0_INTSTAT_MONRDY_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_MONOV_MASK              (0x20000U)                                          /*!< LPC_I2C0_INTSTAT: MONOV Mask            */
#define LPC_I2C0_INTSTAT_MONOV_SHIFT             (17U)                                               /*!< LPC_I2C0_INTSTAT: MONOV Position        */
#define LPC_I2C0_INTSTAT_MONOV(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_MONOV_SHIFT))&LPC_I2C0_INTSTAT_MONOV_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_MONIDLE_MASK            (0x80000U)                                          /*!< LPC_I2C0_INTSTAT: MONIDLE Mask          */
#define LPC_I2C0_INTSTAT_MONIDLE_SHIFT           (19U)                                               /*!< LPC_I2C0_INTSTAT: MONIDLE Position      */
#define LPC_I2C0_INTSTAT_MONIDLE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_MONIDLE_SHIFT))&LPC_I2C0_INTSTAT_MONIDLE_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_EVENTTIMEOUT_MASK       (0x1000000U)                                        /*!< LPC_I2C0_INTSTAT: EVENTTIMEOUT Mask     */
#define LPC_I2C0_INTSTAT_EVENTTIMEOUT_SHIFT      (24U)                                               /*!< LPC_I2C0_INTSTAT: EVENTTIMEOUT Position */
#define LPC_I2C0_INTSTAT_EVENTTIMEOUT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_EVENTTIMEOUT_SHIFT))&LPC_I2C0_INTSTAT_EVENTTIMEOUT_MASK) /*!< LPC_I2C0_INTSTAT                        */
#define LPC_I2C0_INTSTAT_SCLTIMEOUT_MASK         (0x2000000U)                                        /*!< LPC_I2C0_INTSTAT: SCLTIMEOUT Mask       */
#define LPC_I2C0_INTSTAT_SCLTIMEOUT_SHIFT        (25U)                                               /*!< LPC_I2C0_INTSTAT: SCLTIMEOUT Position   */
#define LPC_I2C0_INTSTAT_SCLTIMEOUT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_INTSTAT_SCLTIMEOUT_SHIFT))&LPC_I2C0_INTSTAT_SCLTIMEOUT_MASK) /*!< LPC_I2C0_INTSTAT                        */
/* ------- MSTCTL Bit Fields                        ------ */
#define LPC_I2C0_MSTCTL_MSTCONTINUE_MASK         (0x1U)                                              /*!< LPC_I2C0_MSTCTL: MSTCONTINUE Mask       */
#define LPC_I2C0_MSTCTL_MSTCONTINUE_SHIFT        (0U)                                                /*!< LPC_I2C0_MSTCTL: MSTCONTINUE Position   */
#define LPC_I2C0_MSTCTL_MSTCONTINUE(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MSTCTL_MSTCONTINUE_SHIFT))&LPC_I2C0_MSTCTL_MSTCONTINUE_MASK) /*!< LPC_I2C0_MSTCTL                         */
#define LPC_I2C0_MSTCTL_MSTSTART_MASK            (0x2U)                                              /*!< LPC_I2C0_MSTCTL: MSTSTART Mask          */
#define LPC_I2C0_MSTCTL_MSTSTART_SHIFT           (1U)                                                /*!< LPC_I2C0_MSTCTL: MSTSTART Position      */
#define LPC_I2C0_MSTCTL_MSTSTART(x)              (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MSTCTL_MSTSTART_SHIFT))&LPC_I2C0_MSTCTL_MSTSTART_MASK) /*!< LPC_I2C0_MSTCTL                         */
#define LPC_I2C0_MSTCTL_MSTSTOP_MASK             (0x4U)                                              /*!< LPC_I2C0_MSTCTL: MSTSTOP Mask           */
#define LPC_I2C0_MSTCTL_MSTSTOP_SHIFT            (2U)                                                /*!< LPC_I2C0_MSTCTL: MSTSTOP Position       */
#define LPC_I2C0_MSTCTL_MSTSTOP(x)               (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MSTCTL_MSTSTOP_SHIFT))&LPC_I2C0_MSTCTL_MSTSTOP_MASK) /*!< LPC_I2C0_MSTCTL                         */
#define LPC_I2C0_MSTCTL_MSTDMA_MASK              (0x8U)                                              /*!< LPC_I2C0_MSTCTL: MSTDMA Mask            */
#define LPC_I2C0_MSTCTL_MSTDMA_SHIFT             (3U)                                                /*!< LPC_I2C0_MSTCTL: MSTDMA Position        */
#define LPC_I2C0_MSTCTL_MSTDMA(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MSTCTL_MSTDMA_SHIFT))&LPC_I2C0_MSTCTL_MSTDMA_MASK) /*!< LPC_I2C0_MSTCTL                         */
/* ------- MSTTIME Bit Fields                       ------ */
#define LPC_I2C0_MSTTIME_MSTSCLLOW_MASK          (0x7U)                                              /*!< LPC_I2C0_MSTTIME: MSTSCLLOW Mask        */
#define LPC_I2C0_MSTTIME_MSTSCLLOW_SHIFT         (0U)                                                /*!< LPC_I2C0_MSTTIME: MSTSCLLOW Position    */
#define LPC_I2C0_MSTTIME_MSTSCLLOW(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MSTTIME_MSTSCLLOW_SHIFT))&LPC_I2C0_MSTTIME_MSTSCLLOW_MASK) /*!< LPC_I2C0_MSTTIME                        */
#define LPC_I2C0_MSTTIME_MSTSCLHIGH_MASK         (0x70U)                                             /*!< LPC_I2C0_MSTTIME: MSTSCLHIGH Mask       */
#define LPC_I2C0_MSTTIME_MSTSCLHIGH_SHIFT        (4U)                                                /*!< LPC_I2C0_MSTTIME: MSTSCLHIGH Position   */
#define LPC_I2C0_MSTTIME_MSTSCLHIGH(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MSTTIME_MSTSCLHIGH_SHIFT))&LPC_I2C0_MSTTIME_MSTSCLHIGH_MASK) /*!< LPC_I2C0_MSTTIME                        */
/* ------- MSTDAT Bit Fields                        ------ */
#define LPC_I2C0_MSTDAT_DATA_MASK                (0xFFU)                                             /*!< LPC_I2C0_MSTDAT: DATA Mask              */
#define LPC_I2C0_MSTDAT_DATA_SHIFT               (0U)                                                /*!< LPC_I2C0_MSTDAT: DATA Position          */
#define LPC_I2C0_MSTDAT_DATA(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MSTDAT_DATA_SHIFT))&LPC_I2C0_MSTDAT_DATA_MASK) /*!< LPC_I2C0_MSTDAT                         */
/* ------- SLVCTL Bit Fields                        ------ */
#define LPC_I2C0_SLVCTL_SLVCONTINUE_MASK         (0x1U)                                              /*!< LPC_I2C0_SLVCTL: SLVCONTINUE Mask       */
#define LPC_I2C0_SLVCTL_SLVCONTINUE_SHIFT        (0U)                                                /*!< LPC_I2C0_SLVCTL: SLVCONTINUE Position   */
#define LPC_I2C0_SLVCTL_SLVCONTINUE(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVCTL_SLVCONTINUE_SHIFT))&LPC_I2C0_SLVCTL_SLVCONTINUE_MASK) /*!< LPC_I2C0_SLVCTL                         */
#define LPC_I2C0_SLVCTL_SLVNACK_MASK             (0x2U)                                              /*!< LPC_I2C0_SLVCTL: SLVNACK Mask           */
#define LPC_I2C0_SLVCTL_SLVNACK_SHIFT            (1U)                                                /*!< LPC_I2C0_SLVCTL: SLVNACK Position       */
#define LPC_I2C0_SLVCTL_SLVNACK(x)               (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVCTL_SLVNACK_SHIFT))&LPC_I2C0_SLVCTL_SLVNACK_MASK) /*!< LPC_I2C0_SLVCTL                         */
#define LPC_I2C0_SLVCTL_SLVDMA_MASK              (0x8U)                                              /*!< LPC_I2C0_SLVCTL: SLVDMA Mask            */
#define LPC_I2C0_SLVCTL_SLVDMA_SHIFT             (3U)                                                /*!< LPC_I2C0_SLVCTL: SLVDMA Position        */
#define LPC_I2C0_SLVCTL_SLVDMA(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVCTL_SLVDMA_SHIFT))&LPC_I2C0_SLVCTL_SLVDMA_MASK) /*!< LPC_I2C0_SLVCTL                         */
/* ------- SLVDAT Bit Fields                        ------ */
#define LPC_I2C0_SLVDAT_DATA_MASK                (0xFFU)                                             /*!< LPC_I2C0_SLVDAT: DATA Mask              */
#define LPC_I2C0_SLVDAT_DATA_SHIFT               (0U)                                                /*!< LPC_I2C0_SLVDAT: DATA Position          */
#define LPC_I2C0_SLVDAT_DATA(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVDAT_DATA_SHIFT))&LPC_I2C0_SLVDAT_DATA_MASK) /*!< LPC_I2C0_SLVDAT                         */
/* ------- SLVADR0 Bit Fields                       ------ */
#define LPC_I2C0_SLVADR0_SADISABLE_MASK          (0x1U)                                              /*!< LPC_I2C0_SLVADR0: SADISABLE Mask        */
#define LPC_I2C0_SLVADR0_SADISABLE_SHIFT         (0U)                                                /*!< LPC_I2C0_SLVADR0: SADISABLE Position    */
#define LPC_I2C0_SLVADR0_SADISABLE(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVADR0_SADISABLE_SHIFT))&LPC_I2C0_SLVADR0_SADISABLE_MASK) /*!< LPC_I2C0_SLVADR0                        */
#define LPC_I2C0_SLVADR0_SLVADR_MASK             (0xFEU)                                             /*!< LPC_I2C0_SLVADR0: SLVADR Mask           */
#define LPC_I2C0_SLVADR0_SLVADR_SHIFT            (1U)                                                /*!< LPC_I2C0_SLVADR0: SLVADR Position       */
#define LPC_I2C0_SLVADR0_SLVADR(x)               (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVADR0_SLVADR_SHIFT))&LPC_I2C0_SLVADR0_SLVADR_MASK) /*!< LPC_I2C0_SLVADR0                        */
/* ------- SLVADR Bit Fields                        ------ */
#define LPC_I2C0_SLVADR_SADISABLE_MASK           (0x1U)                                              /*!< LPC_I2C0_SLVADR: SADISABLE Mask         */
#define LPC_I2C0_SLVADR_SADISABLE_SHIFT          (0U)                                                /*!< LPC_I2C0_SLVADR: SADISABLE Position     */
#define LPC_I2C0_SLVADR_SADISABLE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVADR_SADISABLE_SHIFT))&LPC_I2C0_SLVADR_SADISABLE_MASK) /*!< LPC_I2C0_SLVADR                         */
#define LPC_I2C0_SLVADR_SLVADR_MASK              (0xFEU)                                             /*!< LPC_I2C0_SLVADR: SLVADR Mask            */
#define LPC_I2C0_SLVADR_SLVADR_SHIFT             (1U)                                                /*!< LPC_I2C0_SLVADR: SLVADR Position        */
#define LPC_I2C0_SLVADR_SLVADR(x)                (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVADR_SLVADR_SHIFT))&LPC_I2C0_SLVADR_SLVADR_MASK) /*!< LPC_I2C0_SLVADR                         */
/* ------- SLVQUAL0 Bit Fields                      ------ */
#define LPC_I2C0_SLVQUAL0_QUALMODE0_MASK         (0x1U)                                              /*!< LPC_I2C0_SLVQUAL0: QUALMODE0 Mask       */
#define LPC_I2C0_SLVQUAL0_QUALMODE0_SHIFT        (0U)                                                /*!< LPC_I2C0_SLVQUAL0: QUALMODE0 Position   */
#define LPC_I2C0_SLVQUAL0_QUALMODE0(x)           (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVQUAL0_QUALMODE0_SHIFT))&LPC_I2C0_SLVQUAL0_QUALMODE0_MASK) /*!< LPC_I2C0_SLVQUAL0                       */
#define LPC_I2C0_SLVQUAL0_SLVQUAL0_MASK          (0xFEU)                                             /*!< LPC_I2C0_SLVQUAL0: SLVQUAL0 Mask        */
#define LPC_I2C0_SLVQUAL0_SLVQUAL0_SHIFT         (1U)                                                /*!< LPC_I2C0_SLVQUAL0: SLVQUAL0 Position    */
#define LPC_I2C0_SLVQUAL0_SLVQUAL0(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_SLVQUAL0_SLVQUAL0_SHIFT))&LPC_I2C0_SLVQUAL0_SLVQUAL0_MASK) /*!< LPC_I2C0_SLVQUAL0                       */
/* ------- MONRXDAT Bit Fields                      ------ */
#define LPC_I2C0_MONRXDAT_MONRXDAT_MASK          (0xFFU)                                             /*!< LPC_I2C0_MONRXDAT: MONRXDAT Mask        */
#define LPC_I2C0_MONRXDAT_MONRXDAT_SHIFT         (0U)                                                /*!< LPC_I2C0_MONRXDAT: MONRXDAT Position    */
#define LPC_I2C0_MONRXDAT_MONRXDAT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MONRXDAT_MONRXDAT_SHIFT))&LPC_I2C0_MONRXDAT_MONRXDAT_MASK) /*!< LPC_I2C0_MONRXDAT                       */
#define LPC_I2C0_MONRXDAT_MONSTART_MASK          (0x100U)                                            /*!< LPC_I2C0_MONRXDAT: MONSTART Mask        */
#define LPC_I2C0_MONRXDAT_MONSTART_SHIFT         (8U)                                                /*!< LPC_I2C0_MONRXDAT: MONSTART Position    */
#define LPC_I2C0_MONRXDAT_MONSTART(x)            (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MONRXDAT_MONSTART_SHIFT))&LPC_I2C0_MONRXDAT_MONSTART_MASK) /*!< LPC_I2C0_MONRXDAT                       */
#define LPC_I2C0_MONRXDAT_MONRESTART_MASK        (0x200U)                                            /*!< LPC_I2C0_MONRXDAT: MONRESTART Mask      */
#define LPC_I2C0_MONRXDAT_MONRESTART_SHIFT       (9U)                                                /*!< LPC_I2C0_MONRXDAT: MONRESTART Position  */
#define LPC_I2C0_MONRXDAT_MONRESTART(x)          (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MONRXDAT_MONRESTART_SHIFT))&LPC_I2C0_MONRXDAT_MONRESTART_MASK) /*!< LPC_I2C0_MONRXDAT                       */
#define LPC_I2C0_MONRXDAT_MONNACK_MASK           (0x400U)                                            /*!< LPC_I2C0_MONRXDAT: MONNACK Mask         */
#define LPC_I2C0_MONRXDAT_MONNACK_SHIFT          (10U)                                               /*!< LPC_I2C0_MONRXDAT: MONNACK Position     */
#define LPC_I2C0_MONRXDAT_MONNACK(x)             (((uint32_t)(((uint32_t)(x))<<LPC_I2C0_MONRXDAT_MONNACK_SHIFT))&LPC_I2C0_MONRXDAT_MONNACK_MASK) /*!< LPC_I2C0_MONRXDAT                       */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* LPC_I2C0 - Peripheral instance base addresses */
#define LPC_I2C0_BasePtr               0x40050000UL //!< Peripheral base address
#define LPC_I2C0                       ((LPC_I2C0_Type *) LPC_I2C0_BasePtr) //!< Freescale base pointer
#define LPC_I2C0_BASE_PTR              (LPC_I2C0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           LPC_I2C1 (derived from I2C0)         ================ */
/* ================================================================================ */

/**
 * @brief I2C0-bus interface
 */

/* LPC_I2C1 - Peripheral instance base addresses */
#define LPC_I2C1_BasePtr               0x40054000UL //!< Peripheral base address
#define LPC_I2C1                       ((LPC_I2C0_Type *) LPC_I2C1_BasePtr) //!< Freescale base pointer
#define LPC_I2C1_BASE_PTR              (LPC_I2C1) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           LPC_I2C2 (derived from I2C0)         ================ */
/* ================================================================================ */

/**
 * @brief I2C0-bus interface
 */

/* LPC_I2C2 - Peripheral instance base addresses */
#define LPC_I2C2_BasePtr               0x40070000UL //!< Peripheral base address
#define LPC_I2C2                       ((LPC_I2C0_Type *) LPC_I2C2_BasePtr) //!< Freescale base pointer
#define LPC_I2C2_BASE_PTR              (LPC_I2C2) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           LPC_I2C3 (derived from I2C0)         ================ */
/* ================================================================================ */

/**
 * @brief I2C0-bus interface
 */

/* LPC_I2C3 - Peripheral instance base addresses */
#define LPC_I2C3_BasePtr               0x40074000UL //!< Peripheral base address
#define LPC_I2C3                       ((LPC_I2C0_Type *) LPC_I2C3_BasePtr) //!< Freescale base pointer
#define LPC_I2C3_BASE_PTR              (LPC_I2C3) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup INPUTMUX_Peripheral_access_layer_GROUP INPUTMUX Peripheral Access Layer
* @brief C Struct for INPUTMUX
* @{
*/

/* ================================================================================ */
/* ================           LPC_INPUTMUX (file:INPUTMUX_LPC82x)       ================ */
/* ================================================================================ */

/**
 * @brief Input multiplexing
 */
/**
* @addtogroup INPUTMUX_structs_GROUP INPUTMUX struct
* @brief Struct for INPUTMUX
* @{
*/
typedef struct {                                /*       LPC_INPUTMUX Structure                                       */
   __IO uint32_t  DMA_INMUX_INMUX0;             /**< 0000: Input mux register for DMA trigger input 20. Selects from 18 DMA trigger outputs */
   __IO uint32_t  DMA_INMUX_INMUX1;             /**< 0004: Input mux register for DMA trigger input 20. Selects from 18 DMA trigger outputs */
        uint8_t   RESERVED_0[24];              
   __IO uint32_t  SCT0_INMUX0;                  /**< 0020: Input mux register for SCT input 0                           */
   __IO uint32_t  SCT0_INMUX1;                  /**< 0024: Input mux register for SCT input 0                           */
   __IO uint32_t  SCT0_INMUX2;                  /**< 0028: Input mux register for SCT input 0                           */
   __IO uint32_t  SCT0_INMUX3;                  /**< 002C: Input mux register for SCT input 0                           */
} LPC_INPUTMUX_Type;

/**
 * @} */ /* End group INPUTMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_INPUTMUX' Position & Mask macros                ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup INPUTMUX_Register_Masks_GROUP INPUTMUX Register Masks
* @brief Register Masks for INPUTMUX
* @{
*/
/* ------- DMA_INMUX_INMUX0 Bit Fields              ------ */
#define LPC_INPUTMUX_DMA_INMUX_INMUX0_INP_MASK   (0x1FU)                                             /*!< LPC_INPUTMUX_DMA_INMUX_INMUX0: INP Mask */
#define LPC_INPUTMUX_DMA_INMUX_INMUX0_INP_SHIFT  (0U)                                                /*!< LPC_INPUTMUX_DMA_INMUX_INMUX0: INP Position*/
#define LPC_INPUTMUX_DMA_INMUX_INMUX0_INP(x)     (((uint32_t)(((uint32_t)(x))<<LPC_INPUTMUX_DMA_INMUX_INMUX0_INP_SHIFT))&LPC_INPUTMUX_DMA_INMUX_INMUX0_INP_MASK) /*!< LPC_INPUTMUX_DMA_INMUX_INMUX0           */
/* ------- DMA_INMUX_INMUX1 Bit Fields              ------ */
#define LPC_INPUTMUX_DMA_INMUX_INMUX1_INP_MASK   (0x1FU)                                             /*!< LPC_INPUTMUX_DMA_INMUX_INMUX1: INP Mask */
#define LPC_INPUTMUX_DMA_INMUX_INMUX1_INP_SHIFT  (0U)                                                /*!< LPC_INPUTMUX_DMA_INMUX_INMUX1: INP Position*/
#define LPC_INPUTMUX_DMA_INMUX_INMUX1_INP(x)     (((uint32_t)(((uint32_t)(x))<<LPC_INPUTMUX_DMA_INMUX_INMUX1_INP_SHIFT))&LPC_INPUTMUX_DMA_INMUX_INMUX1_INP_MASK) /*!< LPC_INPUTMUX_DMA_INMUX_INMUX1           */
/* ------- SCT0_INMUX0 Bit Fields                   ------ */
#define LPC_INPUTMUX_SCT0_INMUX0_INP_N_MASK      (0xFU)                                              /*!< LPC_INPUTMUX_SCT0_INMUX0: INP_N Mask    */
#define LPC_INPUTMUX_SCT0_INMUX0_INP_N_SHIFT     (0U)                                                /*!< LPC_INPUTMUX_SCT0_INMUX0: INP_N Position*/
#define LPC_INPUTMUX_SCT0_INMUX0_INP_N(x)        (((uint32_t)(((uint32_t)(x))<<LPC_INPUTMUX_SCT0_INMUX0_INP_N_SHIFT))&LPC_INPUTMUX_SCT0_INMUX0_INP_N_MASK) /*!< LPC_INPUTMUX_SCT0_INMUX0                */
/* ------- SCT0_INMUX Bit Fields                    ------ */
#define LPC_INPUTMUX_SCT0_INMUX_INP_N_MASK       (0xFU)                                              /*!< LPC_INPUTMUX_SCT0_INMUX: INP_N Mask     */
#define LPC_INPUTMUX_SCT0_INMUX_INP_N_SHIFT      (0U)                                                /*!< LPC_INPUTMUX_SCT0_INMUX: INP_N Position */
#define LPC_INPUTMUX_SCT0_INMUX_INP_N(x)         (((uint32_t)(((uint32_t)(x))<<LPC_INPUTMUX_SCT0_INMUX_INP_N_SHIFT))&LPC_INPUTMUX_SCT0_INMUX_INP_N_MASK) /*!< LPC_INPUTMUX_SCT0_INMUX                 */
/**
 * @} */ /* End group INPUTMUX_Register_Masks_GROUP 
 */

/* LPC_INPUTMUX - Peripheral instance base addresses */
#define LPC_INPUTMUX_BasePtr           0x4002C000UL //!< Peripheral base address
#define LPC_INPUTMUX                   ((LPC_INPUTMUX_Type *) LPC_INPUTMUX_BasePtr) //!< Freescale base pointer
#define LPC_INPUTMUX_BASE_PTR          (LPC_INPUTMUX) //!< Freescale style base pointer
/**
 * @} */ /* End group INPUTMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup IOCON_Peripheral_access_layer_GROUP IOCON Peripheral Access Layer
* @brief C Struct for IOCON
* @{
*/

/* ================================================================================ */
/* ================           LPC_IOCON (file:IOCON_LPC82x)        ================ */
/* ================================================================================ */

/**
 * @brief I/O configuration
 */
/**
* @addtogroup IOCON_structs_GROUP IOCON struct
* @brief Struct for IOCON
* @{
*/
typedef struct {                                /*       LPC_IOCON Structure                                          */
   __IO uint32_t  PIO0_17;                      /**< 0000: I/O configuration for pin PIO0_17                            */
   __IO uint32_t  PIO0_13;                      /**< 0004: I/O configuration for pin PIO0_17                            */
   __IO uint32_t  PIO0_12;                      /**< 0008: I/O configuration for pin PIO0_17                            */
   __IO uint32_t  PIO0_5;                       /**< 000C: I/O configuration for pin PIO0_5/RESET                       */
   __IO uint32_t  PIO0_4;                       /**< 0010: I/O configuration for pin PIO0_4                             */
   __IO uint32_t  PIO0_3;                       /**< 0014: I/O configuration for pin PIO0_3/SWCLK                       */
   __IO uint32_t  PIO0_2;                       /**< 0018: I/O configuration for pin PIO0_2/SWDIO                       */
   __IO uint32_t  PIO0_11;                      /**< 001C: I/O configuration for pin PIO0_11. This is the pin configuration for the true open-drain pin */
   __IO uint32_t  PIO0_10;                      /**< 0020: I/O configuration for pin PIO0_11. This is the pin configuration for the true open-drain pin */
   __IO uint32_t  PIO0_16;                      /**< 0024: I/O configuration for pin PIO0_16                            */
   __IO uint32_t  PIO0_15;                      /**< 0028: I/O configuration for pin PIO0_16                            */
   __IO uint32_t  PIO0_1;                       /**< 002C: I/O configuration for pin PIO0_17                            */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  PIO0_9;                       /**< 0034: I/O configuration for pin PIO0_9/XTALOUT                     */
   __IO uint32_t  PIO0_8;                       /**< 0038: I/O configuration for pin PIO0_8/XTALIN                      */
   __IO uint32_t  PIO0_7;                       /**< 003C: I/O configuration for pin PIO0_7                             */
   __IO uint32_t  PIO0_6;                       /**< 0040: I/O configuration for pin PIO0_6/VDDCMP                      */
   __IO uint32_t  PIO0_0;                       /**< 0044: I/O configuration for pin PIO0_0/ACMP_I0                     */
   __IO uint32_t  PIO0_14;                      /**< 0048: I/O configuration for pin PIO0_14                            */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  PIO0_28;                      /**< 0050: I/O configuration for pin PIO0_28                            */
   __IO uint32_t  PIO0_27;                      /**< 0054: I/O configuration for pin PIO0_28                            */
   __IO uint32_t  PIO0_26;                      /**< 0058: I/O configuration for pin PIO0_28                            */
   __IO uint32_t  PIO0_25;                      /**< 005C: I/O configuration for pin PIO0_28                            */
   __IO uint32_t  PIO0_24;                      /**< 0060: I/O configuration for pin PIO0_28                            */
   __IO uint32_t  PIO0_23;                      /**< 0064: I/O configuration for pin PIO0_23/ADC_3                      */
   __IO uint32_t  PIO0_22;                      /**< 0068: I/O configuration for pin PIO0_22/ADC_4                      */
   __IO uint32_t  PIO0_21;                      /**< 006C: I/O configuration for pin PIO0_21/ACMP_I4/ADC_5              */
   __IO uint32_t  PIO0_20;                      /**< 0070: I/O configuration for pin PIO0_20/ADC_6                      */
   __IO uint32_t  PIO0_19;                      /**< 0074: I/O configuration for pin PIO0_19/ADC_7                      */
   __IO uint32_t  PIO0_18;                      /**< 0078: I/O configuration for pin PIO0_18/ADC_8                      */
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
/* ------- PIO0_ Bit Fields                         ------ */
#define LPC_IOCON_PIO0__MODE_MASK                (0x18U)                                             /*!< LPC_IOCON_PIO0_: MODE Mask              */
#define LPC_IOCON_PIO0__MODE_SHIFT               (3U)                                                /*!< LPC_IOCON_PIO0_: MODE Position          */
#define LPC_IOCON_PIO0__MODE(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0__MODE_SHIFT))&LPC_IOCON_PIO0__MODE_MASK) /*!< LPC_IOCON_PIO0_                         */
#define LPC_IOCON_PIO0__HYS_MASK                 (0x20U)                                             /*!< LPC_IOCON_PIO0_: HYS Mask               */
#define LPC_IOCON_PIO0__HYS_SHIFT                (5U)                                                /*!< LPC_IOCON_PIO0_: HYS Position           */
#define LPC_IOCON_PIO0__HYS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0__HYS_SHIFT))&LPC_IOCON_PIO0__HYS_MASK) /*!< LPC_IOCON_PIO0_                         */
#define LPC_IOCON_PIO0__INV_MASK                 (0x40U)                                             /*!< LPC_IOCON_PIO0_: INV Mask               */
#define LPC_IOCON_PIO0__INV_SHIFT                (6U)                                                /*!< LPC_IOCON_PIO0_: INV Position           */
#define LPC_IOCON_PIO0__INV(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0__INV_SHIFT))&LPC_IOCON_PIO0__INV_MASK) /*!< LPC_IOCON_PIO0_                         */
#define LPC_IOCON_PIO0__OD_MASK                  (0x400U)                                            /*!< LPC_IOCON_PIO0_: OD Mask                */
#define LPC_IOCON_PIO0__OD_SHIFT                 (10U)                                               /*!< LPC_IOCON_PIO0_: OD Position            */
#define LPC_IOCON_PIO0__OD(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0__OD_SHIFT))&LPC_IOCON_PIO0__OD_MASK) /*!< LPC_IOCON_PIO0_                         */
#define LPC_IOCON_PIO0__S_MODE_MASK              (0x1800U)                                           /*!< LPC_IOCON_PIO0_: S_MODE Mask            */
#define LPC_IOCON_PIO0__S_MODE_SHIFT             (11U)                                               /*!< LPC_IOCON_PIO0_: S_MODE Position        */
#define LPC_IOCON_PIO0__S_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0__S_MODE_SHIFT))&LPC_IOCON_PIO0__S_MODE_MASK) /*!< LPC_IOCON_PIO0_                         */
#define LPC_IOCON_PIO0__CLK_DIV_MASK             (0xE000U)                                           /*!< LPC_IOCON_PIO0_: CLK_DIV Mask           */
#define LPC_IOCON_PIO0__CLK_DIV_SHIFT            (13U)                                               /*!< LPC_IOCON_PIO0_: CLK_DIV Position       */
#define LPC_IOCON_PIO0__CLK_DIV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0__CLK_DIV_SHIFT))&LPC_IOCON_PIO0__CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_                         */
/* ------- PIO0_5 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_5_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_5: MODE Mask             */
#define LPC_IOCON_PIO0_5_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_5: MODE Position         */
#define LPC_IOCON_PIO0_5_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_5_MODE_SHIFT))&LPC_IOCON_PIO0_5_MODE_MASK) /*!< LPC_IOCON_PIO0_5                        */
#define LPC_IOCON_PIO0_5_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_5: HYS Mask              */
#define LPC_IOCON_PIO0_5_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_5: HYS Position          */
#define LPC_IOCON_PIO0_5_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_5_HYS_SHIFT))&LPC_IOCON_PIO0_5_HYS_MASK) /*!< LPC_IOCON_PIO0_5                        */
#define LPC_IOCON_PIO0_5_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_5: INV Mask              */
#define LPC_IOCON_PIO0_5_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_5: INV Position          */
#define LPC_IOCON_PIO0_5_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_5_INV_SHIFT))&LPC_IOCON_PIO0_5_INV_MASK) /*!< LPC_IOCON_PIO0_5                        */
#define LPC_IOCON_PIO0_5_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_5: OD Mask               */
#define LPC_IOCON_PIO0_5_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_5: OD Position           */
#define LPC_IOCON_PIO0_5_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_5_OD_SHIFT))&LPC_IOCON_PIO0_5_OD_MASK) /*!< LPC_IOCON_PIO0_5                        */
#define LPC_IOCON_PIO0_5_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_5: S_MODE Mask           */
#define LPC_IOCON_PIO0_5_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_5: S_MODE Position       */
#define LPC_IOCON_PIO0_5_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_5_S_MODE_SHIFT))&LPC_IOCON_PIO0_5_S_MODE_MASK) /*!< LPC_IOCON_PIO0_5                        */
#define LPC_IOCON_PIO0_5_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_5: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_5_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_5: CLK_DIV Position      */
#define LPC_IOCON_PIO0_5_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_5_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_5_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_5                        */
/* ------- PIO0_4 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_4_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_4: MODE Mask             */
#define LPC_IOCON_PIO0_4_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_4: MODE Position         */
#define LPC_IOCON_PIO0_4_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_4_MODE_SHIFT))&LPC_IOCON_PIO0_4_MODE_MASK) /*!< LPC_IOCON_PIO0_4                        */
#define LPC_IOCON_PIO0_4_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_4: HYS Mask              */
#define LPC_IOCON_PIO0_4_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_4: HYS Position          */
#define LPC_IOCON_PIO0_4_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_4_HYS_SHIFT))&LPC_IOCON_PIO0_4_HYS_MASK) /*!< LPC_IOCON_PIO0_4                        */
#define LPC_IOCON_PIO0_4_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_4: INV Mask              */
#define LPC_IOCON_PIO0_4_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_4: INV Position          */
#define LPC_IOCON_PIO0_4_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_4_INV_SHIFT))&LPC_IOCON_PIO0_4_INV_MASK) /*!< LPC_IOCON_PIO0_4                        */
#define LPC_IOCON_PIO0_4_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_4: OD Mask               */
#define LPC_IOCON_PIO0_4_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_4: OD Position           */
#define LPC_IOCON_PIO0_4_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_4_OD_SHIFT))&LPC_IOCON_PIO0_4_OD_MASK) /*!< LPC_IOCON_PIO0_4                        */
#define LPC_IOCON_PIO0_4_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_4: S_MODE Mask           */
#define LPC_IOCON_PIO0_4_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_4: S_MODE Position       */
#define LPC_IOCON_PIO0_4_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_4_S_MODE_SHIFT))&LPC_IOCON_PIO0_4_S_MODE_MASK) /*!< LPC_IOCON_PIO0_4                        */
#define LPC_IOCON_PIO0_4_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_4: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_4_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_4: CLK_DIV Position      */
#define LPC_IOCON_PIO0_4_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_4_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_4_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_4                        */
/* ------- PIO0_3 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_3_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_3: MODE Mask             */
#define LPC_IOCON_PIO0_3_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_3: MODE Position         */
#define LPC_IOCON_PIO0_3_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_MODE_SHIFT))&LPC_IOCON_PIO0_3_MODE_MASK) /*!< LPC_IOCON_PIO0_3                        */
#define LPC_IOCON_PIO0_3_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_3: HYS Mask              */
#define LPC_IOCON_PIO0_3_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_3: HYS Position          */
#define LPC_IOCON_PIO0_3_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_HYS_SHIFT))&LPC_IOCON_PIO0_3_HYS_MASK) /*!< LPC_IOCON_PIO0_3                        */
#define LPC_IOCON_PIO0_3_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_3: INV Mask              */
#define LPC_IOCON_PIO0_3_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_3: INV Position          */
#define LPC_IOCON_PIO0_3_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_INV_SHIFT))&LPC_IOCON_PIO0_3_INV_MASK) /*!< LPC_IOCON_PIO0_3                        */
#define LPC_IOCON_PIO0_3_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_3: OD Mask               */
#define LPC_IOCON_PIO0_3_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_3: OD Position           */
#define LPC_IOCON_PIO0_3_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_OD_SHIFT))&LPC_IOCON_PIO0_3_OD_MASK) /*!< LPC_IOCON_PIO0_3                        */
#define LPC_IOCON_PIO0_3_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_3: S_MODE Mask           */
#define LPC_IOCON_PIO0_3_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_3: S_MODE Position       */
#define LPC_IOCON_PIO0_3_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_S_MODE_SHIFT))&LPC_IOCON_PIO0_3_S_MODE_MASK) /*!< LPC_IOCON_PIO0_3                        */
#define LPC_IOCON_PIO0_3_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_3: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_3_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_3: CLK_DIV Position      */
#define LPC_IOCON_PIO0_3_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_3_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_3_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_3                        */
/* ------- PIO0_2 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_2_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_2: MODE Mask             */
#define LPC_IOCON_PIO0_2_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_2: MODE Position         */
#define LPC_IOCON_PIO0_2_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_MODE_SHIFT))&LPC_IOCON_PIO0_2_MODE_MASK) /*!< LPC_IOCON_PIO0_2                        */
#define LPC_IOCON_PIO0_2_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_2: HYS Mask              */
#define LPC_IOCON_PIO0_2_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_2: HYS Position          */
#define LPC_IOCON_PIO0_2_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_HYS_SHIFT))&LPC_IOCON_PIO0_2_HYS_MASK) /*!< LPC_IOCON_PIO0_2                        */
#define LPC_IOCON_PIO0_2_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_2: INV Mask              */
#define LPC_IOCON_PIO0_2_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_2: INV Position          */
#define LPC_IOCON_PIO0_2_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_INV_SHIFT))&LPC_IOCON_PIO0_2_INV_MASK) /*!< LPC_IOCON_PIO0_2                        */
#define LPC_IOCON_PIO0_2_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_2: OD Mask               */
#define LPC_IOCON_PIO0_2_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_2: OD Position           */
#define LPC_IOCON_PIO0_2_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_OD_SHIFT))&LPC_IOCON_PIO0_2_OD_MASK) /*!< LPC_IOCON_PIO0_2                        */
#define LPC_IOCON_PIO0_2_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_2: S_MODE Mask           */
#define LPC_IOCON_PIO0_2_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_2: S_MODE Position       */
#define LPC_IOCON_PIO0_2_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_S_MODE_SHIFT))&LPC_IOCON_PIO0_2_S_MODE_MASK) /*!< LPC_IOCON_PIO0_2                        */
#define LPC_IOCON_PIO0_2_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_2: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_2_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_2: CLK_DIV Position      */
#define LPC_IOCON_PIO0_2_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_2_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_2_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_2                        */
/* ------- PIO0_ Bit Fields                         ------ */
#define LPC_IOCON_PIO0__I2CMODE_MASK             (0x300U)                                            /*!< LPC_IOCON_PIO0_: I2CMODE Mask           */
#define LPC_IOCON_PIO0__I2CMODE_SHIFT            (8U)                                                /*!< LPC_IOCON_PIO0_: I2CMODE Position       */
#define LPC_IOCON_PIO0__I2CMODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0__I2CMODE_SHIFT))&LPC_IOCON_PIO0__I2CMODE_MASK) /*!< LPC_IOCON_PIO0_                         */
/* ------- PIO0_ Bit Fields                         ------ */
/* ------- PIO0_1 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_1_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_1: MODE Mask             */
#define LPC_IOCON_PIO0_1_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_1: MODE Position         */
#define LPC_IOCON_PIO0_1_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_MODE_SHIFT))&LPC_IOCON_PIO0_1_MODE_MASK) /*!< LPC_IOCON_PIO0_1                        */
#define LPC_IOCON_PIO0_1_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_1: HYS Mask              */
#define LPC_IOCON_PIO0_1_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_1: HYS Position          */
#define LPC_IOCON_PIO0_1_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_HYS_SHIFT))&LPC_IOCON_PIO0_1_HYS_MASK) /*!< LPC_IOCON_PIO0_1                        */
#define LPC_IOCON_PIO0_1_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_1: INV Mask              */
#define LPC_IOCON_PIO0_1_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_1: INV Position          */
#define LPC_IOCON_PIO0_1_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_INV_SHIFT))&LPC_IOCON_PIO0_1_INV_MASK) /*!< LPC_IOCON_PIO0_1                        */
#define LPC_IOCON_PIO0_1_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_1: OD Mask               */
#define LPC_IOCON_PIO0_1_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_1: OD Position           */
#define LPC_IOCON_PIO0_1_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_OD_SHIFT))&LPC_IOCON_PIO0_1_OD_MASK) /*!< LPC_IOCON_PIO0_1                        */
#define LPC_IOCON_PIO0_1_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_1: S_MODE Mask           */
#define LPC_IOCON_PIO0_1_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_1: S_MODE Position       */
#define LPC_IOCON_PIO0_1_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_S_MODE_SHIFT))&LPC_IOCON_PIO0_1_S_MODE_MASK) /*!< LPC_IOCON_PIO0_1                        */
#define LPC_IOCON_PIO0_1_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_1: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_1_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_1: CLK_DIV Position      */
#define LPC_IOCON_PIO0_1_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_1_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_1_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_1                        */
/* ------- PIO0_9 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_9_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_9: MODE Mask             */
#define LPC_IOCON_PIO0_9_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_9: MODE Position         */
#define LPC_IOCON_PIO0_9_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_MODE_SHIFT))&LPC_IOCON_PIO0_9_MODE_MASK) /*!< LPC_IOCON_PIO0_9                        */
#define LPC_IOCON_PIO0_9_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_9: HYS Mask              */
#define LPC_IOCON_PIO0_9_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_9: HYS Position          */
#define LPC_IOCON_PIO0_9_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_HYS_SHIFT))&LPC_IOCON_PIO0_9_HYS_MASK) /*!< LPC_IOCON_PIO0_9                        */
#define LPC_IOCON_PIO0_9_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_9: INV Mask              */
#define LPC_IOCON_PIO0_9_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_9: INV Position          */
#define LPC_IOCON_PIO0_9_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_INV_SHIFT))&LPC_IOCON_PIO0_9_INV_MASK) /*!< LPC_IOCON_PIO0_9                        */
#define LPC_IOCON_PIO0_9_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_9: OD Mask               */
#define LPC_IOCON_PIO0_9_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_9: OD Position           */
#define LPC_IOCON_PIO0_9_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_OD_SHIFT))&LPC_IOCON_PIO0_9_OD_MASK) /*!< LPC_IOCON_PIO0_9                        */
#define LPC_IOCON_PIO0_9_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_9: S_MODE Mask           */
#define LPC_IOCON_PIO0_9_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_9: S_MODE Position       */
#define LPC_IOCON_PIO0_9_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_S_MODE_SHIFT))&LPC_IOCON_PIO0_9_S_MODE_MASK) /*!< LPC_IOCON_PIO0_9                        */
#define LPC_IOCON_PIO0_9_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_9: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_9_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_9: CLK_DIV Position      */
#define LPC_IOCON_PIO0_9_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_9_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_9_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_9                        */
/* ------- PIO0_8 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_8_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_8: MODE Mask             */
#define LPC_IOCON_PIO0_8_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_8: MODE Position         */
#define LPC_IOCON_PIO0_8_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_MODE_SHIFT))&LPC_IOCON_PIO0_8_MODE_MASK) /*!< LPC_IOCON_PIO0_8                        */
#define LPC_IOCON_PIO0_8_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_8: HYS Mask              */
#define LPC_IOCON_PIO0_8_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_8: HYS Position          */
#define LPC_IOCON_PIO0_8_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_HYS_SHIFT))&LPC_IOCON_PIO0_8_HYS_MASK) /*!< LPC_IOCON_PIO0_8                        */
#define LPC_IOCON_PIO0_8_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_8: INV Mask              */
#define LPC_IOCON_PIO0_8_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_8: INV Position          */
#define LPC_IOCON_PIO0_8_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_INV_SHIFT))&LPC_IOCON_PIO0_8_INV_MASK) /*!< LPC_IOCON_PIO0_8                        */
#define LPC_IOCON_PIO0_8_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_8: OD Mask               */
#define LPC_IOCON_PIO0_8_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_8: OD Position           */
#define LPC_IOCON_PIO0_8_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_OD_SHIFT))&LPC_IOCON_PIO0_8_OD_MASK) /*!< LPC_IOCON_PIO0_8                        */
#define LPC_IOCON_PIO0_8_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_8: S_MODE Mask           */
#define LPC_IOCON_PIO0_8_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_8: S_MODE Position       */
#define LPC_IOCON_PIO0_8_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_S_MODE_SHIFT))&LPC_IOCON_PIO0_8_S_MODE_MASK) /*!< LPC_IOCON_PIO0_8                        */
#define LPC_IOCON_PIO0_8_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_8: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_8_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_8: CLK_DIV Position      */
#define LPC_IOCON_PIO0_8_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_8_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_8_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_8                        */
/* ------- PIO0_7 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_7_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_7: MODE Mask             */
#define LPC_IOCON_PIO0_7_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_7: MODE Position         */
#define LPC_IOCON_PIO0_7_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_MODE_SHIFT))&LPC_IOCON_PIO0_7_MODE_MASK) /*!< LPC_IOCON_PIO0_7                        */
#define LPC_IOCON_PIO0_7_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_7: HYS Mask              */
#define LPC_IOCON_PIO0_7_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_7: HYS Position          */
#define LPC_IOCON_PIO0_7_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_HYS_SHIFT))&LPC_IOCON_PIO0_7_HYS_MASK) /*!< LPC_IOCON_PIO0_7                        */
#define LPC_IOCON_PIO0_7_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_7: INV Mask              */
#define LPC_IOCON_PIO0_7_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_7: INV Position          */
#define LPC_IOCON_PIO0_7_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_INV_SHIFT))&LPC_IOCON_PIO0_7_INV_MASK) /*!< LPC_IOCON_PIO0_7                        */
#define LPC_IOCON_PIO0_7_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_7: OD Mask               */
#define LPC_IOCON_PIO0_7_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_7: OD Position           */
#define LPC_IOCON_PIO0_7_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_OD_SHIFT))&LPC_IOCON_PIO0_7_OD_MASK) /*!< LPC_IOCON_PIO0_7                        */
#define LPC_IOCON_PIO0_7_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_7: S_MODE Mask           */
#define LPC_IOCON_PIO0_7_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_7: S_MODE Position       */
#define LPC_IOCON_PIO0_7_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_S_MODE_SHIFT))&LPC_IOCON_PIO0_7_S_MODE_MASK) /*!< LPC_IOCON_PIO0_7                        */
#define LPC_IOCON_PIO0_7_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_7: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_7_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_7: CLK_DIV Position      */
#define LPC_IOCON_PIO0_7_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_7_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_7_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_7                        */
/* ------- PIO0_6 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_6_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_6: MODE Mask             */
#define LPC_IOCON_PIO0_6_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_6: MODE Position         */
#define LPC_IOCON_PIO0_6_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_MODE_SHIFT))&LPC_IOCON_PIO0_6_MODE_MASK) /*!< LPC_IOCON_PIO0_6                        */
#define LPC_IOCON_PIO0_6_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_6: HYS Mask              */
#define LPC_IOCON_PIO0_6_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_6: HYS Position          */
#define LPC_IOCON_PIO0_6_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_HYS_SHIFT))&LPC_IOCON_PIO0_6_HYS_MASK) /*!< LPC_IOCON_PIO0_6                        */
#define LPC_IOCON_PIO0_6_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_6: INV Mask              */
#define LPC_IOCON_PIO0_6_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_6: INV Position          */
#define LPC_IOCON_PIO0_6_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_INV_SHIFT))&LPC_IOCON_PIO0_6_INV_MASK) /*!< LPC_IOCON_PIO0_6                        */
#define LPC_IOCON_PIO0_6_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_6: OD Mask               */
#define LPC_IOCON_PIO0_6_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_6: OD Position           */
#define LPC_IOCON_PIO0_6_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_OD_SHIFT))&LPC_IOCON_PIO0_6_OD_MASK) /*!< LPC_IOCON_PIO0_6                        */
#define LPC_IOCON_PIO0_6_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_6: S_MODE Mask           */
#define LPC_IOCON_PIO0_6_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_6: S_MODE Position       */
#define LPC_IOCON_PIO0_6_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_S_MODE_SHIFT))&LPC_IOCON_PIO0_6_S_MODE_MASK) /*!< LPC_IOCON_PIO0_6                        */
#define LPC_IOCON_PIO0_6_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_6: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_6_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_6: CLK_DIV Position      */
#define LPC_IOCON_PIO0_6_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_6_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_6_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_6                        */
/* ------- PIO0_0 Bit Fields                        ------ */
#define LPC_IOCON_PIO0_0_MODE_MASK               (0x18U)                                             /*!< LPC_IOCON_PIO0_0: MODE Mask             */
#define LPC_IOCON_PIO0_0_MODE_SHIFT              (3U)                                                /*!< LPC_IOCON_PIO0_0: MODE Position         */
#define LPC_IOCON_PIO0_0_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_0_MODE_SHIFT))&LPC_IOCON_PIO0_0_MODE_MASK) /*!< LPC_IOCON_PIO0_0                        */
#define LPC_IOCON_PIO0_0_HYS_MASK                (0x20U)                                             /*!< LPC_IOCON_PIO0_0: HYS Mask              */
#define LPC_IOCON_PIO0_0_HYS_SHIFT               (5U)                                                /*!< LPC_IOCON_PIO0_0: HYS Position          */
#define LPC_IOCON_PIO0_0_HYS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_0_HYS_SHIFT))&LPC_IOCON_PIO0_0_HYS_MASK) /*!< LPC_IOCON_PIO0_0                        */
#define LPC_IOCON_PIO0_0_INV_MASK                (0x40U)                                             /*!< LPC_IOCON_PIO0_0: INV Mask              */
#define LPC_IOCON_PIO0_0_INV_SHIFT               (6U)                                                /*!< LPC_IOCON_PIO0_0: INV Position          */
#define LPC_IOCON_PIO0_0_INV(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_0_INV_SHIFT))&LPC_IOCON_PIO0_0_INV_MASK) /*!< LPC_IOCON_PIO0_0                        */
#define LPC_IOCON_PIO0_0_OD_MASK                 (0x400U)                                            /*!< LPC_IOCON_PIO0_0: OD Mask               */
#define LPC_IOCON_PIO0_0_OD_SHIFT                (10U)                                               /*!< LPC_IOCON_PIO0_0: OD Position           */
#define LPC_IOCON_PIO0_0_OD(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_0_OD_SHIFT))&LPC_IOCON_PIO0_0_OD_MASK) /*!< LPC_IOCON_PIO0_0                        */
#define LPC_IOCON_PIO0_0_S_MODE_MASK             (0x1800U)                                           /*!< LPC_IOCON_PIO0_0: S_MODE Mask           */
#define LPC_IOCON_PIO0_0_S_MODE_SHIFT            (11U)                                               /*!< LPC_IOCON_PIO0_0: S_MODE Position       */
#define LPC_IOCON_PIO0_0_S_MODE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_0_S_MODE_SHIFT))&LPC_IOCON_PIO0_0_S_MODE_MASK) /*!< LPC_IOCON_PIO0_0                        */
#define LPC_IOCON_PIO0_0_CLK_DIV_MASK            (0xE000U)                                           /*!< LPC_IOCON_PIO0_0: CLK_DIV Mask          */
#define LPC_IOCON_PIO0_0_CLK_DIV_SHIFT           (13U)                                               /*!< LPC_IOCON_PIO0_0: CLK_DIV Position      */
#define LPC_IOCON_PIO0_0_CLK_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_0_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_0_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_0                        */
/* ------- PIO0_14 Bit Fields                       ------ */
#define LPC_IOCON_PIO0_14_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO0_14: MODE Mask            */
#define LPC_IOCON_PIO0_14_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO0_14: MODE Position        */
#define LPC_IOCON_PIO0_14_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_14_MODE_SHIFT))&LPC_IOCON_PIO0_14_MODE_MASK) /*!< LPC_IOCON_PIO0_14                       */
#define LPC_IOCON_PIO0_14_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO0_14: HYS Mask             */
#define LPC_IOCON_PIO0_14_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO0_14: HYS Position         */
#define LPC_IOCON_PIO0_14_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_14_HYS_SHIFT))&LPC_IOCON_PIO0_14_HYS_MASK) /*!< LPC_IOCON_PIO0_14                       */
#define LPC_IOCON_PIO0_14_INV_MASK               (0x40U)                                             /*!< LPC_IOCON_PIO0_14: INV Mask             */
#define LPC_IOCON_PIO0_14_INV_SHIFT              (6U)                                                /*!< LPC_IOCON_PIO0_14: INV Position         */
#define LPC_IOCON_PIO0_14_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_14_INV_SHIFT))&LPC_IOCON_PIO0_14_INV_MASK) /*!< LPC_IOCON_PIO0_14                       */
#define LPC_IOCON_PIO0_14_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO0_14: OD Mask              */
#define LPC_IOCON_PIO0_14_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO0_14: OD Position          */
#define LPC_IOCON_PIO0_14_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_14_OD_SHIFT))&LPC_IOCON_PIO0_14_OD_MASK) /*!< LPC_IOCON_PIO0_14                       */
#define LPC_IOCON_PIO0_14_S_MODE_MASK            (0x1800U)                                           /*!< LPC_IOCON_PIO0_14: S_MODE Mask          */
#define LPC_IOCON_PIO0_14_S_MODE_SHIFT           (11U)                                               /*!< LPC_IOCON_PIO0_14: S_MODE Position      */
#define LPC_IOCON_PIO0_14_S_MODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_14_S_MODE_SHIFT))&LPC_IOCON_PIO0_14_S_MODE_MASK) /*!< LPC_IOCON_PIO0_14                       */
#define LPC_IOCON_PIO0_14_CLK_DIV_MASK           (0xE000U)                                           /*!< LPC_IOCON_PIO0_14: CLK_DIV Mask         */
#define LPC_IOCON_PIO0_14_CLK_DIV_SHIFT          (13U)                                               /*!< LPC_IOCON_PIO0_14: CLK_DIV Position     */
#define LPC_IOCON_PIO0_14_CLK_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_14_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_14_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_14                       */
/* ------- PIO0_ Bit Fields                         ------ */
/* ------- PIO0_23 Bit Fields                       ------ */
#define LPC_IOCON_PIO0_23_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO0_23: MODE Mask            */
#define LPC_IOCON_PIO0_23_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO0_23: MODE Position        */
#define LPC_IOCON_PIO0_23_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_MODE_SHIFT))&LPC_IOCON_PIO0_23_MODE_MASK) /*!< LPC_IOCON_PIO0_23                       */
#define LPC_IOCON_PIO0_23_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO0_23: HYS Mask             */
#define LPC_IOCON_PIO0_23_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO0_23: HYS Position         */
#define LPC_IOCON_PIO0_23_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_HYS_SHIFT))&LPC_IOCON_PIO0_23_HYS_MASK) /*!< LPC_IOCON_PIO0_23                       */
#define LPC_IOCON_PIO0_23_INV_MASK               (0x40U)                                             /*!< LPC_IOCON_PIO0_23: INV Mask             */
#define LPC_IOCON_PIO0_23_INV_SHIFT              (6U)                                                /*!< LPC_IOCON_PIO0_23: INV Position         */
#define LPC_IOCON_PIO0_23_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_INV_SHIFT))&LPC_IOCON_PIO0_23_INV_MASK) /*!< LPC_IOCON_PIO0_23                       */
#define LPC_IOCON_PIO0_23_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO0_23: OD Mask              */
#define LPC_IOCON_PIO0_23_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO0_23: OD Position          */
#define LPC_IOCON_PIO0_23_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_OD_SHIFT))&LPC_IOCON_PIO0_23_OD_MASK) /*!< LPC_IOCON_PIO0_23                       */
#define LPC_IOCON_PIO0_23_S_MODE_MASK            (0x1800U)                                           /*!< LPC_IOCON_PIO0_23: S_MODE Mask          */
#define LPC_IOCON_PIO0_23_S_MODE_SHIFT           (11U)                                               /*!< LPC_IOCON_PIO0_23: S_MODE Position      */
#define LPC_IOCON_PIO0_23_S_MODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_S_MODE_SHIFT))&LPC_IOCON_PIO0_23_S_MODE_MASK) /*!< LPC_IOCON_PIO0_23                       */
#define LPC_IOCON_PIO0_23_CLK_DIV_MASK           (0xE000U)                                           /*!< LPC_IOCON_PIO0_23: CLK_DIV Mask         */
#define LPC_IOCON_PIO0_23_CLK_DIV_SHIFT          (13U)                                               /*!< LPC_IOCON_PIO0_23: CLK_DIV Position     */
#define LPC_IOCON_PIO0_23_CLK_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_23_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_23_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_23                       */
/* ------- PIO0_22 Bit Fields                       ------ */
#define LPC_IOCON_PIO0_22_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO0_22: MODE Mask            */
#define LPC_IOCON_PIO0_22_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO0_22: MODE Position        */
#define LPC_IOCON_PIO0_22_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_MODE_SHIFT))&LPC_IOCON_PIO0_22_MODE_MASK) /*!< LPC_IOCON_PIO0_22                       */
#define LPC_IOCON_PIO0_22_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO0_22: HYS Mask             */
#define LPC_IOCON_PIO0_22_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO0_22: HYS Position         */
#define LPC_IOCON_PIO0_22_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_HYS_SHIFT))&LPC_IOCON_PIO0_22_HYS_MASK) /*!< LPC_IOCON_PIO0_22                       */
#define LPC_IOCON_PIO0_22_INV_MASK               (0x40U)                                             /*!< LPC_IOCON_PIO0_22: INV Mask             */
#define LPC_IOCON_PIO0_22_INV_SHIFT              (6U)                                                /*!< LPC_IOCON_PIO0_22: INV Position         */
#define LPC_IOCON_PIO0_22_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_INV_SHIFT))&LPC_IOCON_PIO0_22_INV_MASK) /*!< LPC_IOCON_PIO0_22                       */
#define LPC_IOCON_PIO0_22_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO0_22: OD Mask              */
#define LPC_IOCON_PIO0_22_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO0_22: OD Position          */
#define LPC_IOCON_PIO0_22_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_OD_SHIFT))&LPC_IOCON_PIO0_22_OD_MASK) /*!< LPC_IOCON_PIO0_22                       */
#define LPC_IOCON_PIO0_22_S_MODE_MASK            (0x1800U)                                           /*!< LPC_IOCON_PIO0_22: S_MODE Mask          */
#define LPC_IOCON_PIO0_22_S_MODE_SHIFT           (11U)                                               /*!< LPC_IOCON_PIO0_22: S_MODE Position      */
#define LPC_IOCON_PIO0_22_S_MODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_S_MODE_SHIFT))&LPC_IOCON_PIO0_22_S_MODE_MASK) /*!< LPC_IOCON_PIO0_22                       */
#define LPC_IOCON_PIO0_22_CLK_DIV_MASK           (0xE000U)                                           /*!< LPC_IOCON_PIO0_22: CLK_DIV Mask         */
#define LPC_IOCON_PIO0_22_CLK_DIV_SHIFT          (13U)                                               /*!< LPC_IOCON_PIO0_22: CLK_DIV Position     */
#define LPC_IOCON_PIO0_22_CLK_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_22_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_22_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_22                       */
/* ------- PIO0_21 Bit Fields                       ------ */
#define LPC_IOCON_PIO0_21_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO0_21: MODE Mask            */
#define LPC_IOCON_PIO0_21_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO0_21: MODE Position        */
#define LPC_IOCON_PIO0_21_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_MODE_SHIFT))&LPC_IOCON_PIO0_21_MODE_MASK) /*!< LPC_IOCON_PIO0_21                       */
#define LPC_IOCON_PIO0_21_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO0_21: HYS Mask             */
#define LPC_IOCON_PIO0_21_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO0_21: HYS Position         */
#define LPC_IOCON_PIO0_21_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_HYS_SHIFT))&LPC_IOCON_PIO0_21_HYS_MASK) /*!< LPC_IOCON_PIO0_21                       */
#define LPC_IOCON_PIO0_21_INV_MASK               (0x40U)                                             /*!< LPC_IOCON_PIO0_21: INV Mask             */
#define LPC_IOCON_PIO0_21_INV_SHIFT              (6U)                                                /*!< LPC_IOCON_PIO0_21: INV Position         */
#define LPC_IOCON_PIO0_21_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_INV_SHIFT))&LPC_IOCON_PIO0_21_INV_MASK) /*!< LPC_IOCON_PIO0_21                       */
#define LPC_IOCON_PIO0_21_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO0_21: OD Mask              */
#define LPC_IOCON_PIO0_21_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO0_21: OD Position          */
#define LPC_IOCON_PIO0_21_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_OD_SHIFT))&LPC_IOCON_PIO0_21_OD_MASK) /*!< LPC_IOCON_PIO0_21                       */
#define LPC_IOCON_PIO0_21_S_MODE_MASK            (0x1800U)                                           /*!< LPC_IOCON_PIO0_21: S_MODE Mask          */
#define LPC_IOCON_PIO0_21_S_MODE_SHIFT           (11U)                                               /*!< LPC_IOCON_PIO0_21: S_MODE Position      */
#define LPC_IOCON_PIO0_21_S_MODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_S_MODE_SHIFT))&LPC_IOCON_PIO0_21_S_MODE_MASK) /*!< LPC_IOCON_PIO0_21                       */
#define LPC_IOCON_PIO0_21_CLK_DIV_MASK           (0xE000U)                                           /*!< LPC_IOCON_PIO0_21: CLK_DIV Mask         */
#define LPC_IOCON_PIO0_21_CLK_DIV_SHIFT          (13U)                                               /*!< LPC_IOCON_PIO0_21: CLK_DIV Position     */
#define LPC_IOCON_PIO0_21_CLK_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_21_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_21_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_21                       */
/* ------- PIO0_20 Bit Fields                       ------ */
#define LPC_IOCON_PIO0_20_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO0_20: MODE Mask            */
#define LPC_IOCON_PIO0_20_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO0_20: MODE Position        */
#define LPC_IOCON_PIO0_20_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_MODE_SHIFT))&LPC_IOCON_PIO0_20_MODE_MASK) /*!< LPC_IOCON_PIO0_20                       */
#define LPC_IOCON_PIO0_20_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO0_20: HYS Mask             */
#define LPC_IOCON_PIO0_20_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO0_20: HYS Position         */
#define LPC_IOCON_PIO0_20_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_HYS_SHIFT))&LPC_IOCON_PIO0_20_HYS_MASK) /*!< LPC_IOCON_PIO0_20                       */
#define LPC_IOCON_PIO0_20_INV_MASK               (0x40U)                                             /*!< LPC_IOCON_PIO0_20: INV Mask             */
#define LPC_IOCON_PIO0_20_INV_SHIFT              (6U)                                                /*!< LPC_IOCON_PIO0_20: INV Position         */
#define LPC_IOCON_PIO0_20_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_INV_SHIFT))&LPC_IOCON_PIO0_20_INV_MASK) /*!< LPC_IOCON_PIO0_20                       */
#define LPC_IOCON_PIO0_20_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO0_20: OD Mask              */
#define LPC_IOCON_PIO0_20_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO0_20: OD Position          */
#define LPC_IOCON_PIO0_20_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_OD_SHIFT))&LPC_IOCON_PIO0_20_OD_MASK) /*!< LPC_IOCON_PIO0_20                       */
#define LPC_IOCON_PIO0_20_S_MODE_MASK            (0x1800U)                                           /*!< LPC_IOCON_PIO0_20: S_MODE Mask          */
#define LPC_IOCON_PIO0_20_S_MODE_SHIFT           (11U)                                               /*!< LPC_IOCON_PIO0_20: S_MODE Position      */
#define LPC_IOCON_PIO0_20_S_MODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_S_MODE_SHIFT))&LPC_IOCON_PIO0_20_S_MODE_MASK) /*!< LPC_IOCON_PIO0_20                       */
#define LPC_IOCON_PIO0_20_CLK_DIV_MASK           (0xE000U)                                           /*!< LPC_IOCON_PIO0_20: CLK_DIV Mask         */
#define LPC_IOCON_PIO0_20_CLK_DIV_SHIFT          (13U)                                               /*!< LPC_IOCON_PIO0_20: CLK_DIV Position     */
#define LPC_IOCON_PIO0_20_CLK_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_20_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_20_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_20                       */
/* ------- PIO0_19 Bit Fields                       ------ */
#define LPC_IOCON_PIO0_19_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO0_19: MODE Mask            */
#define LPC_IOCON_PIO0_19_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO0_19: MODE Position        */
#define LPC_IOCON_PIO0_19_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_MODE_SHIFT))&LPC_IOCON_PIO0_19_MODE_MASK) /*!< LPC_IOCON_PIO0_19                       */
#define LPC_IOCON_PIO0_19_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO0_19: HYS Mask             */
#define LPC_IOCON_PIO0_19_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO0_19: HYS Position         */
#define LPC_IOCON_PIO0_19_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_HYS_SHIFT))&LPC_IOCON_PIO0_19_HYS_MASK) /*!< LPC_IOCON_PIO0_19                       */
#define LPC_IOCON_PIO0_19_INV_MASK               (0x40U)                                             /*!< LPC_IOCON_PIO0_19: INV Mask             */
#define LPC_IOCON_PIO0_19_INV_SHIFT              (6U)                                                /*!< LPC_IOCON_PIO0_19: INV Position         */
#define LPC_IOCON_PIO0_19_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_INV_SHIFT))&LPC_IOCON_PIO0_19_INV_MASK) /*!< LPC_IOCON_PIO0_19                       */
#define LPC_IOCON_PIO0_19_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO0_19: OD Mask              */
#define LPC_IOCON_PIO0_19_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO0_19: OD Position          */
#define LPC_IOCON_PIO0_19_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_OD_SHIFT))&LPC_IOCON_PIO0_19_OD_MASK) /*!< LPC_IOCON_PIO0_19                       */
#define LPC_IOCON_PIO0_19_S_MODE_MASK            (0x1800U)                                           /*!< LPC_IOCON_PIO0_19: S_MODE Mask          */
#define LPC_IOCON_PIO0_19_S_MODE_SHIFT           (11U)                                               /*!< LPC_IOCON_PIO0_19: S_MODE Position      */
#define LPC_IOCON_PIO0_19_S_MODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_S_MODE_SHIFT))&LPC_IOCON_PIO0_19_S_MODE_MASK) /*!< LPC_IOCON_PIO0_19                       */
#define LPC_IOCON_PIO0_19_CLK_DIV_MASK           (0xE000U)                                           /*!< LPC_IOCON_PIO0_19: CLK_DIV Mask         */
#define LPC_IOCON_PIO0_19_CLK_DIV_SHIFT          (13U)                                               /*!< LPC_IOCON_PIO0_19: CLK_DIV Position     */
#define LPC_IOCON_PIO0_19_CLK_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_19_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_19_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_19                       */
/* ------- PIO0_18 Bit Fields                       ------ */
#define LPC_IOCON_PIO0_18_MODE_MASK              (0x18U)                                             /*!< LPC_IOCON_PIO0_18: MODE Mask            */
#define LPC_IOCON_PIO0_18_MODE_SHIFT             (3U)                                                /*!< LPC_IOCON_PIO0_18: MODE Position        */
#define LPC_IOCON_PIO0_18_MODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_MODE_SHIFT))&LPC_IOCON_PIO0_18_MODE_MASK) /*!< LPC_IOCON_PIO0_18                       */
#define LPC_IOCON_PIO0_18_HYS_MASK               (0x20U)                                             /*!< LPC_IOCON_PIO0_18: HYS Mask             */
#define LPC_IOCON_PIO0_18_HYS_SHIFT              (5U)                                                /*!< LPC_IOCON_PIO0_18: HYS Position         */
#define LPC_IOCON_PIO0_18_HYS(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_HYS_SHIFT))&LPC_IOCON_PIO0_18_HYS_MASK) /*!< LPC_IOCON_PIO0_18                       */
#define LPC_IOCON_PIO0_18_INV_MASK               (0x40U)                                             /*!< LPC_IOCON_PIO0_18: INV Mask             */
#define LPC_IOCON_PIO0_18_INV_SHIFT              (6U)                                                /*!< LPC_IOCON_PIO0_18: INV Position         */
#define LPC_IOCON_PIO0_18_INV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_INV_SHIFT))&LPC_IOCON_PIO0_18_INV_MASK) /*!< LPC_IOCON_PIO0_18                       */
#define LPC_IOCON_PIO0_18_OD_MASK                (0x400U)                                            /*!< LPC_IOCON_PIO0_18: OD Mask              */
#define LPC_IOCON_PIO0_18_OD_SHIFT               (10U)                                               /*!< LPC_IOCON_PIO0_18: OD Position          */
#define LPC_IOCON_PIO0_18_OD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_OD_SHIFT))&LPC_IOCON_PIO0_18_OD_MASK) /*!< LPC_IOCON_PIO0_18                       */
#define LPC_IOCON_PIO0_18_S_MODE_MASK            (0x1800U)                                           /*!< LPC_IOCON_PIO0_18: S_MODE Mask          */
#define LPC_IOCON_PIO0_18_S_MODE_SHIFT           (11U)                                               /*!< LPC_IOCON_PIO0_18: S_MODE Position      */
#define LPC_IOCON_PIO0_18_S_MODE(x)              (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_S_MODE_SHIFT))&LPC_IOCON_PIO0_18_S_MODE_MASK) /*!< LPC_IOCON_PIO0_18                       */
#define LPC_IOCON_PIO0_18_CLK_DIV_MASK           (0xE000U)                                           /*!< LPC_IOCON_PIO0_18: CLK_DIV Mask         */
#define LPC_IOCON_PIO0_18_CLK_DIV_SHIFT          (13U)                                               /*!< LPC_IOCON_PIO0_18: CLK_DIV Position     */
#define LPC_IOCON_PIO0_18_CLK_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_IOCON_PIO0_18_CLK_DIV_SHIFT))&LPC_IOCON_PIO0_18_CLK_DIV_MASK) /*!< LPC_IOCON_PIO0_18                       */
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
* @addtogroup MRT_Peripheral_access_layer_GROUP MRT Peripheral Access Layer
* @brief C Struct for MRT
* @{
*/

/* ================================================================================ */
/* ================           LPC_MRT (file:MRT_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief Multi-Rate Timer
 */
/**
* @addtogroup MRT_structs_GROUP MRT struct
* @brief Struct for MRT
* @{
*/
typedef struct {                                /*       LPC_MRT Structure                                            */
   __IO uint32_t  INTVAL0;                      /**< 0000: MRT0 Time interval value register. This value is loaded into the TIMER0 register */
   __I  uint32_t  TIMER0;                       /**< 0004: MRT0 Timer register. This register reads the value of the down-counter */
   __IO uint32_t  CTRL0;                        /**< 0008: MRT0 Control register. This register controls the MRT0 modes */
   __IO uint32_t  STAT0;                        /**< 000C: MRT0 Status register                                         */
   __IO uint32_t  INTVAL1;                      /**< 0010: MRT0 Time interval value register. This value is loaded into the TIMER0 register */
   __I  uint32_t  TIMER1;                       /**< 0014: MRT0 Timer register. This register reads the value of the down-counter */
   __IO uint32_t  CTRL1;                        /**< 0018: MRT0 Control register. This register controls the MRT0 modes */
   __IO uint32_t  STAT1;                        /**< 001C: MRT0 Status register                                         */
   __IO uint32_t  INTVAL2;                      /**< 0020: MRT0 Time interval value register. This value is loaded into the TIMER0 register */
   __I  uint32_t  TIMER2;                       /**< 0024: MRT0 Timer register. This register reads the value of the down-counter */
   __IO uint32_t  CTRL2;                        /**< 0028: MRT0 Control register. This register controls the MRT0 modes */
   __IO uint32_t  STAT2;                        /**< 002C: MRT0 Status register                                         */
   __IO uint32_t  INTVAL3;                      /**< 0030: MRT0 Time interval value register. This value is loaded into the TIMER0 register */
   __I  uint32_t  TIMER3;                       /**< 0034: MRT0 Timer register. This register reads the value of the down-counter */
   __IO uint32_t  CTRL3;                        /**< 0038: MRT0 Control register. This register controls the MRT0 modes */
   __IO uint32_t  STAT3;                        /**< 003C: MRT0 Status register                                         */
        uint8_t   RESERVED_0[180];             
   __I  uint32_t  IDLE_CH;                      /**< 00F4: Idle channel register. This register returns the number of the first idle channel */
   __IO uint32_t  IRQ_FLAG;                     /**< 00F8: Global interrupt flag register                               */
} LPC_MRT_Type;

/**
 * @} */ /* End group MRT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_MRT' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MRT_Register_Masks_GROUP MRT Register Masks
* @brief Register Masks for MRT
* @{
*/
/* ------- INTVAL0 Bit Fields                       ------ */
#define LPC_MRT_INTVAL0_IVALUE_MASK              (0xFFFFFFU)                                         /*!< LPC_MRT_INTVAL0: IVALUE Mask            */
#define LPC_MRT_INTVAL0_IVALUE_SHIFT             (0U)                                                /*!< LPC_MRT_INTVAL0: IVALUE Position        */
#define LPC_MRT_INTVAL0_IVALUE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_MRT_INTVAL0_IVALUE_SHIFT))&LPC_MRT_INTVAL0_IVALUE_MASK) /*!< LPC_MRT_INTVAL0                         */
#define LPC_MRT_INTVAL0_LOAD_MASK                (0x80000000U)                                       /*!< LPC_MRT_INTVAL0: LOAD Mask              */
#define LPC_MRT_INTVAL0_LOAD_SHIFT               (31U)                                               /*!< LPC_MRT_INTVAL0: LOAD Position          */
#define LPC_MRT_INTVAL0_LOAD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_INTVAL0_LOAD_SHIFT))&LPC_MRT_INTVAL0_LOAD_MASK) /*!< LPC_MRT_INTVAL0                         */
/* ------- TIMER0 Bit Fields                        ------ */
#define LPC_MRT_TIMER0_VALUE_MASK                (0xFFFFFFU)                                         /*!< LPC_MRT_TIMER0: VALUE Mask              */
#define LPC_MRT_TIMER0_VALUE_SHIFT               (0U)                                                /*!< LPC_MRT_TIMER0: VALUE Position          */
#define LPC_MRT_TIMER0_VALUE(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_TIMER0_VALUE_SHIFT))&LPC_MRT_TIMER0_VALUE_MASK) /*!< LPC_MRT_TIMER0                          */
/* ------- CTRL0 Bit Fields                         ------ */
#define LPC_MRT_CTRL0_INTEN_MASK                 (0x1U)                                              /*!< LPC_MRT_CTRL0: INTEN Mask               */
#define LPC_MRT_CTRL0_INTEN_SHIFT                (0U)                                                /*!< LPC_MRT_CTRL0: INTEN Position           */
#define LPC_MRT_CTRL0_INTEN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_MRT_CTRL0_INTEN_SHIFT))&LPC_MRT_CTRL0_INTEN_MASK) /*!< LPC_MRT_CTRL0                           */
#define LPC_MRT_CTRL0_MODE_MASK                  (0x6U)                                              /*!< LPC_MRT_CTRL0: MODE Mask                */
#define LPC_MRT_CTRL0_MODE_SHIFT                 (1U)                                                /*!< LPC_MRT_CTRL0: MODE Position            */
#define LPC_MRT_CTRL0_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_MRT_CTRL0_MODE_SHIFT))&LPC_MRT_CTRL0_MODE_MASK) /*!< LPC_MRT_CTRL0                           */
/* ------- STAT0 Bit Fields                         ------ */
#define LPC_MRT_STAT0_INTFLAG_MASK               (0x1U)                                              /*!< LPC_MRT_STAT0: INTFLAG Mask             */
#define LPC_MRT_STAT0_INTFLAG_SHIFT              (0U)                                                /*!< LPC_MRT_STAT0: INTFLAG Position         */
#define LPC_MRT_STAT0_INTFLAG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_MRT_STAT0_INTFLAG_SHIFT))&LPC_MRT_STAT0_INTFLAG_MASK) /*!< LPC_MRT_STAT0                           */
#define LPC_MRT_STAT0_RUN_MASK                   (0x2U)                                              /*!< LPC_MRT_STAT0: RUN Mask                 */
#define LPC_MRT_STAT0_RUN_SHIFT                  (1U)                                                /*!< LPC_MRT_STAT0: RUN Position             */
#define LPC_MRT_STAT0_RUN(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_MRT_STAT0_RUN_SHIFT))&LPC_MRT_STAT0_RUN_MASK) /*!< LPC_MRT_STAT0                           */
/* ------- INTVAL1 Bit Fields                       ------ */
#define LPC_MRT_INTVAL1_IVALUE_MASK              (0xFFFFFFU)                                         /*!< LPC_MRT_INTVAL1: IVALUE Mask            */
#define LPC_MRT_INTVAL1_IVALUE_SHIFT             (0U)                                                /*!< LPC_MRT_INTVAL1: IVALUE Position        */
#define LPC_MRT_INTVAL1_IVALUE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_MRT_INTVAL1_IVALUE_SHIFT))&LPC_MRT_INTVAL1_IVALUE_MASK) /*!< LPC_MRT_INTVAL1                         */
#define LPC_MRT_INTVAL1_LOAD_MASK                (0x80000000U)                                       /*!< LPC_MRT_INTVAL1: LOAD Mask              */
#define LPC_MRT_INTVAL1_LOAD_SHIFT               (31U)                                               /*!< LPC_MRT_INTVAL1: LOAD Position          */
#define LPC_MRT_INTVAL1_LOAD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_INTVAL1_LOAD_SHIFT))&LPC_MRT_INTVAL1_LOAD_MASK) /*!< LPC_MRT_INTVAL1                         */
/* ------- TIMER1 Bit Fields                        ------ */
#define LPC_MRT_TIMER1_VALUE_MASK                (0xFFFFFFU)                                         /*!< LPC_MRT_TIMER1: VALUE Mask              */
#define LPC_MRT_TIMER1_VALUE_SHIFT               (0U)                                                /*!< LPC_MRT_TIMER1: VALUE Position          */
#define LPC_MRT_TIMER1_VALUE(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_TIMER1_VALUE_SHIFT))&LPC_MRT_TIMER1_VALUE_MASK) /*!< LPC_MRT_TIMER1                          */
/* ------- CTRL1 Bit Fields                         ------ */
#define LPC_MRT_CTRL1_INTEN_MASK                 (0x1U)                                              /*!< LPC_MRT_CTRL1: INTEN Mask               */
#define LPC_MRT_CTRL1_INTEN_SHIFT                (0U)                                                /*!< LPC_MRT_CTRL1: INTEN Position           */
#define LPC_MRT_CTRL1_INTEN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_MRT_CTRL1_INTEN_SHIFT))&LPC_MRT_CTRL1_INTEN_MASK) /*!< LPC_MRT_CTRL1                           */
#define LPC_MRT_CTRL1_MODE_MASK                  (0x6U)                                              /*!< LPC_MRT_CTRL1: MODE Mask                */
#define LPC_MRT_CTRL1_MODE_SHIFT                 (1U)                                                /*!< LPC_MRT_CTRL1: MODE Position            */
#define LPC_MRT_CTRL1_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_MRT_CTRL1_MODE_SHIFT))&LPC_MRT_CTRL1_MODE_MASK) /*!< LPC_MRT_CTRL1                           */
/* ------- STAT1 Bit Fields                         ------ */
#define LPC_MRT_STAT1_INTFLAG_MASK               (0x1U)                                              /*!< LPC_MRT_STAT1: INTFLAG Mask             */
#define LPC_MRT_STAT1_INTFLAG_SHIFT              (0U)                                                /*!< LPC_MRT_STAT1: INTFLAG Position         */
#define LPC_MRT_STAT1_INTFLAG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_MRT_STAT1_INTFLAG_SHIFT))&LPC_MRT_STAT1_INTFLAG_MASK) /*!< LPC_MRT_STAT1                           */
#define LPC_MRT_STAT1_RUN_MASK                   (0x2U)                                              /*!< LPC_MRT_STAT1: RUN Mask                 */
#define LPC_MRT_STAT1_RUN_SHIFT                  (1U)                                                /*!< LPC_MRT_STAT1: RUN Position             */
#define LPC_MRT_STAT1_RUN(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_MRT_STAT1_RUN_SHIFT))&LPC_MRT_STAT1_RUN_MASK) /*!< LPC_MRT_STAT1                           */
/* ------- INTVAL2 Bit Fields                       ------ */
#define LPC_MRT_INTVAL2_IVALUE_MASK              (0xFFFFFFU)                                         /*!< LPC_MRT_INTVAL2: IVALUE Mask            */
#define LPC_MRT_INTVAL2_IVALUE_SHIFT             (0U)                                                /*!< LPC_MRT_INTVAL2: IVALUE Position        */
#define LPC_MRT_INTVAL2_IVALUE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_MRT_INTVAL2_IVALUE_SHIFT))&LPC_MRT_INTVAL2_IVALUE_MASK) /*!< LPC_MRT_INTVAL2                         */
#define LPC_MRT_INTVAL2_LOAD_MASK                (0x80000000U)                                       /*!< LPC_MRT_INTVAL2: LOAD Mask              */
#define LPC_MRT_INTVAL2_LOAD_SHIFT               (31U)                                               /*!< LPC_MRT_INTVAL2: LOAD Position          */
#define LPC_MRT_INTVAL2_LOAD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_INTVAL2_LOAD_SHIFT))&LPC_MRT_INTVAL2_LOAD_MASK) /*!< LPC_MRT_INTVAL2                         */
/* ------- TIMER2 Bit Fields                        ------ */
#define LPC_MRT_TIMER2_VALUE_MASK                (0xFFFFFFU)                                         /*!< LPC_MRT_TIMER2: VALUE Mask              */
#define LPC_MRT_TIMER2_VALUE_SHIFT               (0U)                                                /*!< LPC_MRT_TIMER2: VALUE Position          */
#define LPC_MRT_TIMER2_VALUE(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_TIMER2_VALUE_SHIFT))&LPC_MRT_TIMER2_VALUE_MASK) /*!< LPC_MRT_TIMER2                          */
/* ------- CTRL2 Bit Fields                         ------ */
#define LPC_MRT_CTRL2_INTEN_MASK                 (0x1U)                                              /*!< LPC_MRT_CTRL2: INTEN Mask               */
#define LPC_MRT_CTRL2_INTEN_SHIFT                (0U)                                                /*!< LPC_MRT_CTRL2: INTEN Position           */
#define LPC_MRT_CTRL2_INTEN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_MRT_CTRL2_INTEN_SHIFT))&LPC_MRT_CTRL2_INTEN_MASK) /*!< LPC_MRT_CTRL2                           */
#define LPC_MRT_CTRL2_MODE_MASK                  (0x6U)                                              /*!< LPC_MRT_CTRL2: MODE Mask                */
#define LPC_MRT_CTRL2_MODE_SHIFT                 (1U)                                                /*!< LPC_MRT_CTRL2: MODE Position            */
#define LPC_MRT_CTRL2_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_MRT_CTRL2_MODE_SHIFT))&LPC_MRT_CTRL2_MODE_MASK) /*!< LPC_MRT_CTRL2                           */
/* ------- STAT2 Bit Fields                         ------ */
#define LPC_MRT_STAT2_INTFLAG_MASK               (0x1U)                                              /*!< LPC_MRT_STAT2: INTFLAG Mask             */
#define LPC_MRT_STAT2_INTFLAG_SHIFT              (0U)                                                /*!< LPC_MRT_STAT2: INTFLAG Position         */
#define LPC_MRT_STAT2_INTFLAG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_MRT_STAT2_INTFLAG_SHIFT))&LPC_MRT_STAT2_INTFLAG_MASK) /*!< LPC_MRT_STAT2                           */
#define LPC_MRT_STAT2_RUN_MASK                   (0x2U)                                              /*!< LPC_MRT_STAT2: RUN Mask                 */
#define LPC_MRT_STAT2_RUN_SHIFT                  (1U)                                                /*!< LPC_MRT_STAT2: RUN Position             */
#define LPC_MRT_STAT2_RUN(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_MRT_STAT2_RUN_SHIFT))&LPC_MRT_STAT2_RUN_MASK) /*!< LPC_MRT_STAT2                           */
/* ------- INTVAL3 Bit Fields                       ------ */
#define LPC_MRT_INTVAL3_IVALUE_MASK              (0xFFFFFFU)                                         /*!< LPC_MRT_INTVAL3: IVALUE Mask            */
#define LPC_MRT_INTVAL3_IVALUE_SHIFT             (0U)                                                /*!< LPC_MRT_INTVAL3: IVALUE Position        */
#define LPC_MRT_INTVAL3_IVALUE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_MRT_INTVAL3_IVALUE_SHIFT))&LPC_MRT_INTVAL3_IVALUE_MASK) /*!< LPC_MRT_INTVAL3                         */
#define LPC_MRT_INTVAL3_LOAD_MASK                (0x80000000U)                                       /*!< LPC_MRT_INTVAL3: LOAD Mask              */
#define LPC_MRT_INTVAL3_LOAD_SHIFT               (31U)                                               /*!< LPC_MRT_INTVAL3: LOAD Position          */
#define LPC_MRT_INTVAL3_LOAD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_INTVAL3_LOAD_SHIFT))&LPC_MRT_INTVAL3_LOAD_MASK) /*!< LPC_MRT_INTVAL3                         */
/* ------- TIMER3 Bit Fields                        ------ */
#define LPC_MRT_TIMER3_VALUE_MASK                (0xFFFFFFU)                                         /*!< LPC_MRT_TIMER3: VALUE Mask              */
#define LPC_MRT_TIMER3_VALUE_SHIFT               (0U)                                                /*!< LPC_MRT_TIMER3: VALUE Position          */
#define LPC_MRT_TIMER3_VALUE(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_TIMER3_VALUE_SHIFT))&LPC_MRT_TIMER3_VALUE_MASK) /*!< LPC_MRT_TIMER3                          */
/* ------- CTRL3 Bit Fields                         ------ */
#define LPC_MRT_CTRL3_INTEN_MASK                 (0x1U)                                              /*!< LPC_MRT_CTRL3: INTEN Mask               */
#define LPC_MRT_CTRL3_INTEN_SHIFT                (0U)                                                /*!< LPC_MRT_CTRL3: INTEN Position           */
#define LPC_MRT_CTRL3_INTEN(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_MRT_CTRL3_INTEN_SHIFT))&LPC_MRT_CTRL3_INTEN_MASK) /*!< LPC_MRT_CTRL3                           */
#define LPC_MRT_CTRL3_MODE_MASK                  (0x6U)                                              /*!< LPC_MRT_CTRL3: MODE Mask                */
#define LPC_MRT_CTRL3_MODE_SHIFT                 (1U)                                                /*!< LPC_MRT_CTRL3: MODE Position            */
#define LPC_MRT_CTRL3_MODE(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_MRT_CTRL3_MODE_SHIFT))&LPC_MRT_CTRL3_MODE_MASK) /*!< LPC_MRT_CTRL3                           */
/* ------- STAT3 Bit Fields                         ------ */
#define LPC_MRT_STAT3_INTFLAG_MASK               (0x1U)                                              /*!< LPC_MRT_STAT3: INTFLAG Mask             */
#define LPC_MRT_STAT3_INTFLAG_SHIFT              (0U)                                                /*!< LPC_MRT_STAT3: INTFLAG Position         */
#define LPC_MRT_STAT3_INTFLAG(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_MRT_STAT3_INTFLAG_SHIFT))&LPC_MRT_STAT3_INTFLAG_MASK) /*!< LPC_MRT_STAT3                           */
#define LPC_MRT_STAT3_RUN_MASK                   (0x2U)                                              /*!< LPC_MRT_STAT3: RUN Mask                 */
#define LPC_MRT_STAT3_RUN_SHIFT                  (1U)                                                /*!< LPC_MRT_STAT3: RUN Position             */
#define LPC_MRT_STAT3_RUN(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_MRT_STAT3_RUN_SHIFT))&LPC_MRT_STAT3_RUN_MASK) /*!< LPC_MRT_STAT3                           */
/* ------- IDLE_CH Bit Fields                       ------ */
#define LPC_MRT_IDLE_CH_CHAN_MASK                (0xF0U)                                             /*!< LPC_MRT_IDLE_CH: CHAN Mask              */
#define LPC_MRT_IDLE_CH_CHAN_SHIFT               (4U)                                                /*!< LPC_MRT_IDLE_CH: CHAN Position          */
#define LPC_MRT_IDLE_CH_CHAN(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_MRT_IDLE_CH_CHAN_SHIFT))&LPC_MRT_IDLE_CH_CHAN_MASK) /*!< LPC_MRT_IDLE_CH                         */
/* ------- IRQ_FLAG Bit Fields                      ------ */
#define LPC_MRT_IRQ_FLAG_GFLAG0_MASK             (0x1U)                                              /*!< LPC_MRT_IRQ_FLAG: GFLAG0 Mask           */
#define LPC_MRT_IRQ_FLAG_GFLAG0_SHIFT            (0U)                                                /*!< LPC_MRT_IRQ_FLAG: GFLAG0 Position       */
#define LPC_MRT_IRQ_FLAG_GFLAG0(x)               (((uint32_t)(((uint32_t)(x))<<LPC_MRT_IRQ_FLAG_GFLAG0_SHIFT))&LPC_MRT_IRQ_FLAG_GFLAG0_MASK) /*!< LPC_MRT_IRQ_FLAG                        */
#define LPC_MRT_IRQ_FLAG_GFLAG1_MASK             (0x2U)                                              /*!< LPC_MRT_IRQ_FLAG: GFLAG1 Mask           */
#define LPC_MRT_IRQ_FLAG_GFLAG1_SHIFT            (1U)                                                /*!< LPC_MRT_IRQ_FLAG: GFLAG1 Position       */
#define LPC_MRT_IRQ_FLAG_GFLAG1(x)               (((uint32_t)(((uint32_t)(x))<<LPC_MRT_IRQ_FLAG_GFLAG1_SHIFT))&LPC_MRT_IRQ_FLAG_GFLAG1_MASK) /*!< LPC_MRT_IRQ_FLAG                        */
#define LPC_MRT_IRQ_FLAG_GFLAG2_MASK             (0x4U)                                              /*!< LPC_MRT_IRQ_FLAG: GFLAG2 Mask           */
#define LPC_MRT_IRQ_FLAG_GFLAG2_SHIFT            (2U)                                                /*!< LPC_MRT_IRQ_FLAG: GFLAG2 Position       */
#define LPC_MRT_IRQ_FLAG_GFLAG2(x)               (((uint32_t)(((uint32_t)(x))<<LPC_MRT_IRQ_FLAG_GFLAG2_SHIFT))&LPC_MRT_IRQ_FLAG_GFLAG2_MASK) /*!< LPC_MRT_IRQ_FLAG                        */
#define LPC_MRT_IRQ_FLAG_GFLAG3_MASK             (0x8U)                                              /*!< LPC_MRT_IRQ_FLAG: GFLAG3 Mask           */
#define LPC_MRT_IRQ_FLAG_GFLAG3_SHIFT            (3U)                                                /*!< LPC_MRT_IRQ_FLAG: GFLAG3 Position       */
#define LPC_MRT_IRQ_FLAG_GFLAG3(x)               (((uint32_t)(((uint32_t)(x))<<LPC_MRT_IRQ_FLAG_GFLAG3_SHIFT))&LPC_MRT_IRQ_FLAG_GFLAG3_MASK) /*!< LPC_MRT_IRQ_FLAG                        */
/**
 * @} */ /* End group MRT_Register_Masks_GROUP 
 */

/* LPC_MRT - Peripheral instance base addresses */
#define LPC_MRT_BasePtr                0x40004000UL //!< Peripheral base address
#define LPC_MRT                        ((LPC_MRT_Type *) LPC_MRT_BasePtr) //!< Freescale base pointer
#define LPC_MRT_BASE_PTR               (LPC_MRT) //!< Freescale style base pointer
/**
 * @} */ /* End group MRT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_PIN_INT_Peripheral_access_layer_GROUP GPIO_PIN_INT Peripheral Access Layer
* @brief C Struct for GPIO_PIN_INT
* @{
*/

/* ================================================================================ */
/* ================           LPC_PIN_INT (file:PIN_INT_LPC82x)       ================ */
/* ================================================================================ */

/**
 * @brief Pin interrupt and  pattern match engine
 */
/**
* @addtogroup GPIO_PIN_INT_structs_GROUP GPIO_PIN_INT struct
* @brief Struct for GPIO_PIN_INT
* @{
*/
typedef struct {                                /*       LPC_PIN_INT Structure                                        */
   __IO uint32_t  ISEL;                         /**< 0000: Pin Interrupt Mode register                                  */
   __IO uint32_t  IENR;                         /**< 0004: Pin interrupt level or rising edge interrupt enable register */
   __O  uint32_t  SIENR;                        /**< 0008: Pin interrupt level (rising edge) interrupt set register     */
   __O  uint32_t  CIENR;                        /**< 000C: Pin interrupt level  or rising edge interrupt clear register */
   __IO uint32_t  IENF;                         /**< 0010: Pin interrupt active level or falling edge interrupt enable register */
   __O  uint32_t  SIENF;                        /**< 0014: Pin interrupt active level or falling edge interrupt set register */
   __O  uint32_t  CIENF;                        /**< 0018: Pin interrupt active level (falling edge) interrupt clear register */
   __IO uint32_t  RISE;                         /**< 001C: Pin interrupt rising edge register                           */
   __IO uint32_t  FALL;                         /**< 0020: Pin interrupt falling edge register                          */
   __IO uint32_t  IST;                          /**< 0024: Pin interrupt status register                                */
   __IO uint32_t  PMCTRL;                       /**< 0028: GPIO pattern match interrupt control register                */
   __IO uint32_t  PMSRC;                        /**< 002C: GPIO pattern match interrupt bit-slice source register       */
   __IO uint32_t  PMCFG;                        /**< 0030: GPIO pattern match interrupt bit slice configuration register */
} LPC_PIN_INT_Type;

/**
 * @} */ /* End group GPIO_PIN_INT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_PIN_INT' Position & Mask macros                 ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_PIN_INT_Register_Masks_GROUP GPIO_PIN_INT Register Masks
* @brief Register Masks for GPIO_PIN_INT
* @{
*/
/* ------- ISEL Bit Fields                          ------ */
#define LPC_PIN_INT_ISEL_PMODE_MASK              (0xFFU)                                             /*!< LPC_PIN_INT_ISEL: PMODE Mask            */
#define LPC_PIN_INT_ISEL_PMODE_SHIFT             (0U)                                                /*!< LPC_PIN_INT_ISEL: PMODE Position        */
#define LPC_PIN_INT_ISEL_PMODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_ISEL_PMODE_SHIFT))&LPC_PIN_INT_ISEL_PMODE_MASK) /*!< LPC_PIN_INT_ISEL                        */
/* ------- IENR Bit Fields                          ------ */
#define LPC_PIN_INT_IENR_ENRL_MASK               (0xFFU)                                             /*!< LPC_PIN_INT_IENR: ENRL Mask             */
#define LPC_PIN_INT_IENR_ENRL_SHIFT              (0U)                                                /*!< LPC_PIN_INT_IENR: ENRL Position         */
#define LPC_PIN_INT_IENR_ENRL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_IENR_ENRL_SHIFT))&LPC_PIN_INT_IENR_ENRL_MASK) /*!< LPC_PIN_INT_IENR                        */
/* ------- SIENR Bit Fields                         ------ */
#define LPC_PIN_INT_SIENR_SETENRL_MASK           (0xFFU)                                             /*!< LPC_PIN_INT_SIENR: SETENRL Mask         */
#define LPC_PIN_INT_SIENR_SETENRL_SHIFT          (0U)                                                /*!< LPC_PIN_INT_SIENR: SETENRL Position     */
#define LPC_PIN_INT_SIENR_SETENRL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_SIENR_SETENRL_SHIFT))&LPC_PIN_INT_SIENR_SETENRL_MASK) /*!< LPC_PIN_INT_SIENR                       */
/* ------- CIENR Bit Fields                         ------ */
#define LPC_PIN_INT_CIENR_CENRL_MASK             (0xFFU)                                             /*!< LPC_PIN_INT_CIENR: CENRL Mask           */
#define LPC_PIN_INT_CIENR_CENRL_SHIFT            (0U)                                                /*!< LPC_PIN_INT_CIENR: CENRL Position       */
#define LPC_PIN_INT_CIENR_CENRL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_CIENR_CENRL_SHIFT))&LPC_PIN_INT_CIENR_CENRL_MASK) /*!< LPC_PIN_INT_CIENR                       */
/* ------- IENF Bit Fields                          ------ */
#define LPC_PIN_INT_IENF_ENAF_MASK               (0xFFU)                                             /*!< LPC_PIN_INT_IENF: ENAF Mask             */
#define LPC_PIN_INT_IENF_ENAF_SHIFT              (0U)                                                /*!< LPC_PIN_INT_IENF: ENAF Position         */
#define LPC_PIN_INT_IENF_ENAF(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_IENF_ENAF_SHIFT))&LPC_PIN_INT_IENF_ENAF_MASK) /*!< LPC_PIN_INT_IENF                        */
/* ------- SIENF Bit Fields                         ------ */
#define LPC_PIN_INT_SIENF_SETENAF_MASK           (0xFFU)                                             /*!< LPC_PIN_INT_SIENF: SETENAF Mask         */
#define LPC_PIN_INT_SIENF_SETENAF_SHIFT          (0U)                                                /*!< LPC_PIN_INT_SIENF: SETENAF Position     */
#define LPC_PIN_INT_SIENF_SETENAF(x)             (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_SIENF_SETENAF_SHIFT))&LPC_PIN_INT_SIENF_SETENAF_MASK) /*!< LPC_PIN_INT_SIENF                       */
/* ------- CIENF Bit Fields                         ------ */
#define LPC_PIN_INT_CIENF_CENAF_MASK             (0xFFU)                                             /*!< LPC_PIN_INT_CIENF: CENAF Mask           */
#define LPC_PIN_INT_CIENF_CENAF_SHIFT            (0U)                                                /*!< LPC_PIN_INT_CIENF: CENAF Position       */
#define LPC_PIN_INT_CIENF_CENAF(x)               (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_CIENF_CENAF_SHIFT))&LPC_PIN_INT_CIENF_CENAF_MASK) /*!< LPC_PIN_INT_CIENF                       */
/* ------- RISE Bit Fields                          ------ */
#define LPC_PIN_INT_RISE_RDET_MASK               (0xFFU)                                             /*!< LPC_PIN_INT_RISE: RDET Mask             */
#define LPC_PIN_INT_RISE_RDET_SHIFT              (0U)                                                /*!< LPC_PIN_INT_RISE: RDET Position         */
#define LPC_PIN_INT_RISE_RDET(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_RISE_RDET_SHIFT))&LPC_PIN_INT_RISE_RDET_MASK) /*!< LPC_PIN_INT_RISE                        */
/* ------- FALL Bit Fields                          ------ */
#define LPC_PIN_INT_FALL_FDET_MASK               (0xFFU)                                             /*!< LPC_PIN_INT_FALL: FDET Mask             */
#define LPC_PIN_INT_FALL_FDET_SHIFT              (0U)                                                /*!< LPC_PIN_INT_FALL: FDET Position         */
#define LPC_PIN_INT_FALL_FDET(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_FALL_FDET_SHIFT))&LPC_PIN_INT_FALL_FDET_MASK) /*!< LPC_PIN_INT_FALL                        */
/* ------- IST Bit Fields                           ------ */
#define LPC_PIN_INT_IST_PSTAT_MASK               (0xFFU)                                             /*!< LPC_PIN_INT_IST: PSTAT Mask             */
#define LPC_PIN_INT_IST_PSTAT_SHIFT              (0U)                                                /*!< LPC_PIN_INT_IST: PSTAT Position         */
#define LPC_PIN_INT_IST_PSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_IST_PSTAT_SHIFT))&LPC_PIN_INT_IST_PSTAT_MASK) /*!< LPC_PIN_INT_IST                         */
/* ------- PMCTRL Bit Fields                        ------ */
#define LPC_PIN_INT_PMCTRL_SEL_PMATCH_MASK       (0x1U)                                              /*!< LPC_PIN_INT_PMCTRL: SEL_PMATCH Mask     */
#define LPC_PIN_INT_PMCTRL_SEL_PMATCH_SHIFT      (0U)                                                /*!< LPC_PIN_INT_PMCTRL: SEL_PMATCH Position */
#define LPC_PIN_INT_PMCTRL_SEL_PMATCH(x)         (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCTRL_SEL_PMATCH_SHIFT))&LPC_PIN_INT_PMCTRL_SEL_PMATCH_MASK) /*!< LPC_PIN_INT_PMCTRL                      */
#define LPC_PIN_INT_PMCTRL_ENA_RXEV_MASK         (0x2U)                                              /*!< LPC_PIN_INT_PMCTRL: ENA_RXEV Mask       */
#define LPC_PIN_INT_PMCTRL_ENA_RXEV_SHIFT        (1U)                                                /*!< LPC_PIN_INT_PMCTRL: ENA_RXEV Position   */
#define LPC_PIN_INT_PMCTRL_ENA_RXEV(x)           (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCTRL_ENA_RXEV_SHIFT))&LPC_PIN_INT_PMCTRL_ENA_RXEV_MASK) /*!< LPC_PIN_INT_PMCTRL                      */
#define LPC_PIN_INT_PMCTRL_PMAT_MASK             (0xFF000000U)                                       /*!< LPC_PIN_INT_PMCTRL: PMAT Mask           */
#define LPC_PIN_INT_PMCTRL_PMAT_SHIFT            (24U)                                               /*!< LPC_PIN_INT_PMCTRL: PMAT Position       */
#define LPC_PIN_INT_PMCTRL_PMAT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCTRL_PMAT_SHIFT))&LPC_PIN_INT_PMCTRL_PMAT_MASK) /*!< LPC_PIN_INT_PMCTRL                      */
/* ------- PMSRC Bit Fields                         ------ */
#define LPC_PIN_INT_PMSRC_Reserved_MASK          (0xFFU)                                             /*!< LPC_PIN_INT_PMSRC: Reserved Mask        */
#define LPC_PIN_INT_PMSRC_Reserved_SHIFT         (0U)                                                /*!< LPC_PIN_INT_PMSRC: Reserved Position    */
#define LPC_PIN_INT_PMSRC_Reserved(x)            (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_Reserved_SHIFT))&LPC_PIN_INT_PMSRC_Reserved_MASK) /*!< LPC_PIN_INT_PMSRC                       */
#define LPC_PIN_INT_PMSRC_SRC0_MASK              (0x700U)                                            /*!< LPC_PIN_INT_PMSRC: SRC0 Mask            */
#define LPC_PIN_INT_PMSRC_SRC0_SHIFT             (8U)                                                /*!< LPC_PIN_INT_PMSRC: SRC0 Position        */
#define LPC_PIN_INT_PMSRC_SRC0(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_SRC0_SHIFT))&LPC_PIN_INT_PMSRC_SRC0_MASK) /*!< LPC_PIN_INT_PMSRC                       */
#define LPC_PIN_INT_PMSRC_SRC1_MASK              (0x3800U)                                           /*!< LPC_PIN_INT_PMSRC: SRC1 Mask            */
#define LPC_PIN_INT_PMSRC_SRC1_SHIFT             (11U)                                               /*!< LPC_PIN_INT_PMSRC: SRC1 Position        */
#define LPC_PIN_INT_PMSRC_SRC1(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_SRC1_SHIFT))&LPC_PIN_INT_PMSRC_SRC1_MASK) /*!< LPC_PIN_INT_PMSRC                       */
#define LPC_PIN_INT_PMSRC_SRC2_MASK              (0x1C000U)                                          /*!< LPC_PIN_INT_PMSRC: SRC2 Mask            */
#define LPC_PIN_INT_PMSRC_SRC2_SHIFT             (14U)                                               /*!< LPC_PIN_INT_PMSRC: SRC2 Position        */
#define LPC_PIN_INT_PMSRC_SRC2(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_SRC2_SHIFT))&LPC_PIN_INT_PMSRC_SRC2_MASK) /*!< LPC_PIN_INT_PMSRC                       */
#define LPC_PIN_INT_PMSRC_SRC3_MASK              (0xE0000U)                                          /*!< LPC_PIN_INT_PMSRC: SRC3 Mask            */
#define LPC_PIN_INT_PMSRC_SRC3_SHIFT             (17U)                                               /*!< LPC_PIN_INT_PMSRC: SRC3 Position        */
#define LPC_PIN_INT_PMSRC_SRC3(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_SRC3_SHIFT))&LPC_PIN_INT_PMSRC_SRC3_MASK) /*!< LPC_PIN_INT_PMSRC                       */
#define LPC_PIN_INT_PMSRC_SRC4_MASK              (0x700000U)                                         /*!< LPC_PIN_INT_PMSRC: SRC4 Mask            */
#define LPC_PIN_INT_PMSRC_SRC4_SHIFT             (20U)                                               /*!< LPC_PIN_INT_PMSRC: SRC4 Position        */
#define LPC_PIN_INT_PMSRC_SRC4(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_SRC4_SHIFT))&LPC_PIN_INT_PMSRC_SRC4_MASK) /*!< LPC_PIN_INT_PMSRC                       */
#define LPC_PIN_INT_PMSRC_SRC5_MASK              (0x3800000U)                                        /*!< LPC_PIN_INT_PMSRC: SRC5 Mask            */
#define LPC_PIN_INT_PMSRC_SRC5_SHIFT             (23U)                                               /*!< LPC_PIN_INT_PMSRC: SRC5 Position        */
#define LPC_PIN_INT_PMSRC_SRC5(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_SRC5_SHIFT))&LPC_PIN_INT_PMSRC_SRC5_MASK) /*!< LPC_PIN_INT_PMSRC                       */
#define LPC_PIN_INT_PMSRC_SRC6_MASK              (0x1C000000U)                                       /*!< LPC_PIN_INT_PMSRC: SRC6 Mask            */
#define LPC_PIN_INT_PMSRC_SRC6_SHIFT             (26U)                                               /*!< LPC_PIN_INT_PMSRC: SRC6 Position        */
#define LPC_PIN_INT_PMSRC_SRC6(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_SRC6_SHIFT))&LPC_PIN_INT_PMSRC_SRC6_MASK) /*!< LPC_PIN_INT_PMSRC                       */
#define LPC_PIN_INT_PMSRC_SRC7_MASK              (0xE0000000U)                                       /*!< LPC_PIN_INT_PMSRC: SRC7 Mask            */
#define LPC_PIN_INT_PMSRC_SRC7_SHIFT             (29U)                                               /*!< LPC_PIN_INT_PMSRC: SRC7 Position        */
#define LPC_PIN_INT_PMSRC_SRC7(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMSRC_SRC7_SHIFT))&LPC_PIN_INT_PMSRC_SRC7_MASK) /*!< LPC_PIN_INT_PMSRC                       */
/* ------- PMCFG Bit Fields                         ------ */
#define LPC_PIN_INT_PMCFG_PROD_ENDPTS_MASK       (0x7FU)                                             /*!< LPC_PIN_INT_PMCFG: PROD_ENDPTS Mask     */
#define LPC_PIN_INT_PMCFG_PROD_ENDPTS_SHIFT      (0U)                                                /*!< LPC_PIN_INT_PMCFG: PROD_ENDPTS Position */
#define LPC_PIN_INT_PMCFG_PROD_ENDPTS(x)         (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_PROD_ENDPTS_SHIFT))&LPC_PIN_INT_PMCFG_PROD_ENDPTS_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_Reserved_MASK          (0x80U)                                             /*!< LPC_PIN_INT_PMCFG: Reserved Mask        */
#define LPC_PIN_INT_PMCFG_Reserved_SHIFT         (7U)                                                /*!< LPC_PIN_INT_PMCFG: Reserved Position    */
#define LPC_PIN_INT_PMCFG_Reserved(x)            (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_Reserved_SHIFT))&LPC_PIN_INT_PMCFG_Reserved_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_CFG0_MASK              (0x700U)                                            /*!< LPC_PIN_INT_PMCFG: CFG0 Mask            */
#define LPC_PIN_INT_PMCFG_CFG0_SHIFT             (8U)                                                /*!< LPC_PIN_INT_PMCFG: CFG0 Position        */
#define LPC_PIN_INT_PMCFG_CFG0(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_CFG0_SHIFT))&LPC_PIN_INT_PMCFG_CFG0_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_CFG1_MASK              (0x3800U)                                           /*!< LPC_PIN_INT_PMCFG: CFG1 Mask            */
#define LPC_PIN_INT_PMCFG_CFG1_SHIFT             (11U)                                               /*!< LPC_PIN_INT_PMCFG: CFG1 Position        */
#define LPC_PIN_INT_PMCFG_CFG1(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_CFG1_SHIFT))&LPC_PIN_INT_PMCFG_CFG1_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_CFG2_MASK              (0x1C000U)                                          /*!< LPC_PIN_INT_PMCFG: CFG2 Mask            */
#define LPC_PIN_INT_PMCFG_CFG2_SHIFT             (14U)                                               /*!< LPC_PIN_INT_PMCFG: CFG2 Position        */
#define LPC_PIN_INT_PMCFG_CFG2(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_CFG2_SHIFT))&LPC_PIN_INT_PMCFG_CFG2_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_CFG3_MASK              (0xE0000U)                                          /*!< LPC_PIN_INT_PMCFG: CFG3 Mask            */
#define LPC_PIN_INT_PMCFG_CFG3_SHIFT             (17U)                                               /*!< LPC_PIN_INT_PMCFG: CFG3 Position        */
#define LPC_PIN_INT_PMCFG_CFG3(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_CFG3_SHIFT))&LPC_PIN_INT_PMCFG_CFG3_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_CFG4_MASK              (0x700000U)                                         /*!< LPC_PIN_INT_PMCFG: CFG4 Mask            */
#define LPC_PIN_INT_PMCFG_CFG4_SHIFT             (20U)                                               /*!< LPC_PIN_INT_PMCFG: CFG4 Position        */
#define LPC_PIN_INT_PMCFG_CFG4(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_CFG4_SHIFT))&LPC_PIN_INT_PMCFG_CFG4_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_CFG5_MASK              (0x3800000U)                                        /*!< LPC_PIN_INT_PMCFG: CFG5 Mask            */
#define LPC_PIN_INT_PMCFG_CFG5_SHIFT             (23U)                                               /*!< LPC_PIN_INT_PMCFG: CFG5 Position        */
#define LPC_PIN_INT_PMCFG_CFG5(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_CFG5_SHIFT))&LPC_PIN_INT_PMCFG_CFG5_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_CFG6_MASK              (0x1C000000U)                                       /*!< LPC_PIN_INT_PMCFG: CFG6 Mask            */
#define LPC_PIN_INT_PMCFG_CFG6_SHIFT             (26U)                                               /*!< LPC_PIN_INT_PMCFG: CFG6 Position        */
#define LPC_PIN_INT_PMCFG_CFG6(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_CFG6_SHIFT))&LPC_PIN_INT_PMCFG_CFG6_MASK) /*!< LPC_PIN_INT_PMCFG                       */
#define LPC_PIN_INT_PMCFG_CFG7_MASK              (0xE0000000U)                                       /*!< LPC_PIN_INT_PMCFG: CFG7 Mask            */
#define LPC_PIN_INT_PMCFG_CFG7_SHIFT             (29U)                                               /*!< LPC_PIN_INT_PMCFG: CFG7 Position        */
#define LPC_PIN_INT_PMCFG_CFG7(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PIN_INT_PMCFG_CFG7_SHIFT))&LPC_PIN_INT_PMCFG_CFG7_MASK) /*!< LPC_PIN_INT_PMCFG                       */
/**
 * @} */ /* End group GPIO_PIN_INT_Register_Masks_GROUP 
 */

/* LPC_PIN_INT - Peripheral instance base addresses */
#define LPC_PIN_INT_BasePtr            0xA0004000UL //!< Peripheral base address
#define LPC_PIN_INT                    ((LPC_PIN_INT_Type *) LPC_PIN_INT_BasePtr) //!< Freescale base pointer
#define LPC_PIN_INT_BASE_PTR           (LPC_PIN_INT) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_PIN_INT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMU_Peripheral_access_layer_GROUP PMU Peripheral Access Layer
* @brief C Struct for PMU
* @{
*/

/* ================================================================================ */
/* ================           LPC_PMU (file:PMU_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief Power Management Unit
 */
/**
* @addtogroup PMU_structs_GROUP PMU struct
* @brief Struct for PMU
* @{
*/
typedef struct {                                /*       LPC_PMU Structure                                            */
   __IO uint32_t  PCON;                         /**< 0000: Power control register                                       */
   __IO uint32_t  GPREG0;                       /**< 0004: General purpose register 0                                   */
   __IO uint32_t  GPREG1;                       /**< 0008: General purpose register 0                                   */
   __IO uint32_t  GPREG2;                       /**< 000C: General purpose register 0                                   */
   __IO uint32_t  GPREG3;                       /**< 0010: General purpose register 0                                   */
   __IO uint32_t  DPDCTRL;                      /**< 0014: Deep power-down control register. Also includes bits for general purpose storage */
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
#define LPC_PMU_PCON_PM_MASK                     (0x7U)                                              /*!< LPC_PMU_PCON: PM Mask                   */
#define LPC_PMU_PCON_PM_SHIFT                    (0U)                                                /*!< LPC_PMU_PCON: PM Position               */
#define LPC_PMU_PCON_PM(x)                       (((uint32_t)(((uint32_t)(x))<<LPC_PMU_PCON_PM_SHIFT))&LPC_PMU_PCON_PM_MASK) /*!< LPC_PMU_PCON                            */
#define LPC_PMU_PCON_NODPD_MASK                  (0x8U)                                              /*!< LPC_PMU_PCON: NODPD Mask                */
#define LPC_PMU_PCON_NODPD_SHIFT                 (3U)                                                /*!< LPC_PMU_PCON: NODPD Position            */
#define LPC_PMU_PCON_NODPD(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_PMU_PCON_NODPD_SHIFT))&LPC_PMU_PCON_NODPD_MASK) /*!< LPC_PMU_PCON                            */
#define LPC_PMU_PCON_SLEEPFLAG_MASK              (0x100U)                                            /*!< LPC_PMU_PCON: SLEEPFLAG Mask            */
#define LPC_PMU_PCON_SLEEPFLAG_SHIFT             (8U)                                                /*!< LPC_PMU_PCON: SLEEPFLAG Position        */
#define LPC_PMU_PCON_SLEEPFLAG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_PMU_PCON_SLEEPFLAG_SHIFT))&LPC_PMU_PCON_SLEEPFLAG_MASK) /*!< LPC_PMU_PCON                            */
#define LPC_PMU_PCON_DPDFLAG_MASK                (0x800U)                                            /*!< LPC_PMU_PCON: DPDFLAG Mask              */
#define LPC_PMU_PCON_DPDFLAG_SHIFT               (11U)                                               /*!< LPC_PMU_PCON: DPDFLAG Position          */
#define LPC_PMU_PCON_DPDFLAG(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_PMU_PCON_DPDFLAG_SHIFT))&LPC_PMU_PCON_DPDFLAG_MASK) /*!< LPC_PMU_PCON                            */
/* ------- GPREG0 Bit Fields                        ------ */
#define LPC_PMU_GPREG0_GPDATA_MASK               (0xFFFFFFFFU)                                       /*!< LPC_PMU_GPREG0: GPDATA Mask             */
#define LPC_PMU_GPREG0_GPDATA_SHIFT              (0U)                                                /*!< LPC_PMU_GPREG0: GPDATA Position         */
#define LPC_PMU_GPREG0_GPDATA(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_PMU_GPREG0_GPDATA_SHIFT))&LPC_PMU_GPREG0_GPDATA_MASK) /*!< LPC_PMU_GPREG0                          */
/* ------- GPREG Bit Fields                         ------ */
#define LPC_PMU_GPREG_GPDATA_MASK                (0xFFFFFFFFU)                                       /*!< LPC_PMU_GPREG: GPDATA Mask              */
#define LPC_PMU_GPREG_GPDATA_SHIFT               (0U)                                                /*!< LPC_PMU_GPREG: GPDATA Position          */
#define LPC_PMU_GPREG_GPDATA(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_PMU_GPREG_GPDATA_SHIFT))&LPC_PMU_GPREG_GPDATA_MASK) /*!< LPC_PMU_GPREG                           */
/* ------- DPDCTRL Bit Fields                       ------ */
#define LPC_PMU_DPDCTRL_WAKEUPHYS_MASK           (0x1U)                                              /*!< LPC_PMU_DPDCTRL: WAKEUPHYS Mask         */
#define LPC_PMU_DPDCTRL_WAKEUPHYS_SHIFT          (0U)                                                /*!< LPC_PMU_DPDCTRL: WAKEUPHYS Position     */
#define LPC_PMU_DPDCTRL_WAKEUPHYS(x)             (((uint32_t)(((uint32_t)(x))<<LPC_PMU_DPDCTRL_WAKEUPHYS_SHIFT))&LPC_PMU_DPDCTRL_WAKEUPHYS_MASK) /*!< LPC_PMU_DPDCTRL                         */
#define LPC_PMU_DPDCTRL_WAKEPAD_DISABLE_MASK     (0x2U)                                              /*!< LPC_PMU_DPDCTRL: WAKEPAD_DISABLE Mask   */
#define LPC_PMU_DPDCTRL_WAKEPAD_DISABLE_SHIFT    (1U)                                                /*!< LPC_PMU_DPDCTRL: WAKEPAD_DISABLE Position*/
#define LPC_PMU_DPDCTRL_WAKEPAD_DISABLE(x)       (((uint32_t)(((uint32_t)(x))<<LPC_PMU_DPDCTRL_WAKEPAD_DISABLE_SHIFT))&LPC_PMU_DPDCTRL_WAKEPAD_DISABLE_MASK) /*!< LPC_PMU_DPDCTRL                         */
#define LPC_PMU_DPDCTRL_LPOSCEN_MASK             (0x4U)                                              /*!< LPC_PMU_DPDCTRL: LPOSCEN Mask           */
#define LPC_PMU_DPDCTRL_LPOSCEN_SHIFT            (2U)                                                /*!< LPC_PMU_DPDCTRL: LPOSCEN Position       */
#define LPC_PMU_DPDCTRL_LPOSCEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_PMU_DPDCTRL_LPOSCEN_SHIFT))&LPC_PMU_DPDCTRL_LPOSCEN_MASK) /*!< LPC_PMU_DPDCTRL                         */
#define LPC_PMU_DPDCTRL_LPOSCDPDEN_MASK          (0x8U)                                              /*!< LPC_PMU_DPDCTRL: LPOSCDPDEN Mask        */
#define LPC_PMU_DPDCTRL_LPOSCDPDEN_SHIFT         (3U)                                                /*!< LPC_PMU_DPDCTRL: LPOSCDPDEN Position    */
#define LPC_PMU_DPDCTRL_LPOSCDPDEN(x)            (((uint32_t)(((uint32_t)(x))<<LPC_PMU_DPDCTRL_LPOSCDPDEN_SHIFT))&LPC_PMU_DPDCTRL_LPOSCDPDEN_MASK) /*!< LPC_PMU_DPDCTRL                         */
#define LPC_PMU_DPDCTRL_WAKEUPCLKHYS_MASK        (0x10U)                                             /*!< LPC_PMU_DPDCTRL: WAKEUPCLKHYS Mask      */
#define LPC_PMU_DPDCTRL_WAKEUPCLKHYS_SHIFT       (4U)                                                /*!< LPC_PMU_DPDCTRL: WAKEUPCLKHYS Position  */
#define LPC_PMU_DPDCTRL_WAKEUPCLKHYS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_PMU_DPDCTRL_WAKEUPCLKHYS_SHIFT))&LPC_PMU_DPDCTRL_WAKEUPCLKHYS_MASK) /*!< LPC_PMU_DPDCTRL                         */
#define LPC_PMU_DPDCTRL_WAKECLKPAD_DISABLE_MASK  (0x20U)                                             /*!< LPC_PMU_DPDCTRL: WAKECLKPAD_DISABLE Mask*/
#define LPC_PMU_DPDCTRL_WAKECLKPAD_DISABLE_SHIFT (5U)                                                /*!< LPC_PMU_DPDCTRL: WAKECLKPAD_DISABLE Position*/
#define LPC_PMU_DPDCTRL_WAKECLKPAD_DISABLE(x)    (((uint32_t)(((uint32_t)(x))<<LPC_PMU_DPDCTRL_WAKECLKPAD_DISABLE_SHIFT))&LPC_PMU_DPDCTRL_WAKECLKPAD_DISABLE_MASK) /*!< LPC_PMU_DPDCTRL                         */
/**
 * @} */ /* End group PMU_Register_Masks_GROUP 
 */

/* LPC_PMU - Peripheral instance base addresses */
#define LPC_PMU_BasePtr                0x40020000UL //!< Peripheral base address
#define LPC_PMU                        ((LPC_PMU_Type *) LPC_PMU_BasePtr) //!< Freescale base pointer
#define LPC_PMU_BASE_PTR               (LPC_PMU) //!< Freescale style base pointer
/**
 * @} */ /* End group PMU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SCT_Peripheral_access_layer_GROUP SCT Peripheral Access Layer
* @brief C Struct for SCT
* @{
*/

/* ================================================================================ */
/* ================           LPC_SCT (file:SCT_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief State Configurable Timer
 */
/**
* @addtogroup SCT_structs_GROUP SCT struct
* @brief Struct for SCT
* @{
*/
typedef struct {                                /*       LPC_SCT Structure                                            */
   __IO uint32_t  CONFIG;                       /**< 0000: SCT configuration register                                   */
   __IO uint32_t  CTRL;                         /**< 0004: SCT control register                                         */
   __IO uint32_t  LIMIT;                        /**< 0008: SCT limit register                                           */
   __IO uint32_t  HALT;                         /**< 000C: SCT halt condition register                                  */
   __IO uint32_t  STOP;                         /**< 0010: SCT stop condition register                                  */
   __IO uint32_t  START;                        /**< 0014: SCT start condition register                                 */
        uint8_t   RESERVED_0[40];              
   __IO uint32_t  COUNT;                        /**< 0040: SCT counter register                                         */
   __IO uint32_t  STATE;                        /**< 0044: SCT state register                                           */
   __I  uint32_t  INPUT;                        /**< 0048: SCT input register                                           */
   __IO uint32_t  REGMODE;                      /**< 004C: SCT match/capture registers mode register                    */
   __IO uint32_t  OUTPUT;                       /**< 0050: SCT output register                                          */
   __IO uint32_t  OUTPUTDIRCTRL;                /**< 0054: SCT output counter direction control register                */
   __IO uint32_t  RES;                          /**< 0058: SCT conflict resolution register                             */
   __IO uint32_t  DMAREQ[2];                    /**< 005C: SCT DMA request  register                                    */
        uint8_t   RESERVED_1[140];             
   __IO uint32_t  EVEN;                         /**< 00F0: SCT event enable register                                    */
   __IO uint32_t  EVFLAG;                       /**< 00F4: SCT event flag register                                      */
   __IO uint32_t  CONEN;                        /**< 00F8: SCT conflict enable register                                 */
   __IO uint32_t  CONFLAG;                      /**< 00FC: SCT conflict flag register                                   */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CAP0;                      /**< 0100: SCT capture register of capture channel 0 to 7; REGMOD0 to REGMODE7 = 1 */
      __IO uint32_t  MATCH0;                    /**< 0100: SCT match value register of match channels 0 to 7; REGMOD0 to REGMODE7 = 0 */
   };
   union {                                      /**< 0000: (size=0018)                                                  */
      struct {                                  /**< 0000: (size=0018)                                                  */
      __IO uint32_t  MATCH1;                    /**< 0104: SCT match value register of match channels 0 to 7; REGMOD0 to REGMODE7 = 0 */
      __IO uint32_t  MATCH2;                    /**< 0108: SCT match value register of match channels 0 to 7; REGMOD0 to REGMODE7 = 0 */
      __IO uint32_t  MATCH3;                    /**< 010C: SCT match value register of match channels 0 to 7; REGMOD0 to REGMODE7 = 0 */
      __IO uint32_t  MATCH4;                    /**< 0110: SCT match value register of match channels 0 to 7; REGMOD0 to REGMODE7 = 0 */
      __IO uint32_t  MATCH5;                    /**< 0114: SCT match value register of match channels 0 to 7; REGMOD0 to REGMODE7 = 0 */
      __IO uint32_t  MATCH6;                    /**< 0118: SCT match value register of match channels 0 to 7; REGMOD0 to REGMODE7 = 0 */
      };
      struct {                                  /**< 0000: (size=0018)                                                  */
         __IO uint32_t  CAP1;                   /**< 0104: SCT capture register of capture channel 0 to 7; REGMOD0 to REGMODE7 = 1 */
         __IO uint32_t  CAP2;                   /**< 0108: SCT capture register of capture channel 0 to 7; REGMOD0 to REGMODE7 = 1 */
         __IO uint32_t  CAP3;                   /**< 010C: SCT capture register of capture channel 0 to 7; REGMOD0 to REGMODE7 = 1 */
         __IO uint32_t  CAP4;                   /**< 0110: SCT capture register of capture channel 0 to 7; REGMOD0 to REGMODE7 = 1 */
         __IO uint32_t  CAP5;                   /**< 0114: SCT capture register of capture channel 0 to 7; REGMOD0 to REGMODE7 = 1 */
         __IO uint32_t  CAP6;                   /**< 0118: SCT capture register of capture channel 0 to 7; REGMOD0 to REGMODE7 = 1 */
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CAP7;                      /**< 011C: SCT capture register of capture channel 0 to 7; REGMOD0 to REGMODE7 = 1 */
      __IO uint32_t  MATCH7;                    /**< 011C: SCT match value register of match channels 0 to 7; REGMOD0 to REGMODE7 = 0 */
   };
        uint8_t   RESERVED_3[224];             
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CAPCTRL0;                  /**< 0200: SCT capture control register 0 to 7; REGMOD0 = 1 to REGMODE7 = 1 */
      __IO uint32_t  MATCHREL0;                 /**< 0200: SCT match reload value register 0 to 7; REGMOD0 = 0 to REGMODE7 = 0 */
   };
   union {                                      /**< 0000: (size=0018)                                                  */
      struct {                                  /**< 0000: (size=0018)                                                  */
      __IO uint32_t  MATCHREL1;                 /**< 0204: SCT match reload value register 0 to 7; REGMOD0 = 0 to REGMODE7 = 0 */
      __IO uint32_t  MATCHREL2;                 /**< 0208: SCT match reload value register 0 to 7; REGMOD0 = 0 to REGMODE7 = 0 */
      __IO uint32_t  MATCHREL3;                 /**< 020C: SCT match reload value register 0 to 7; REGMOD0 = 0 to REGMODE7 = 0 */
      __IO uint32_t  MATCHREL4;                 /**< 0210: SCT match reload value register 0 to 7; REGMOD0 = 0 to REGMODE7 = 0 */
      __IO uint32_t  MATCHREL5;                 /**< 0214: SCT match reload value register 0 to 7; REGMOD0 = 0 to REGMODE7 = 0 */
      __IO uint32_t  MATCHREL6;                 /**< 0218: SCT match reload value register 0 to 7; REGMOD0 = 0 to REGMODE7 = 0 */
      };
      struct {                                  /**< 0000: (size=0018)                                                  */
         __IO uint32_t  CAPCTRL1;               /**< 0204: SCT capture control register 0 to 7; REGMOD0 = 1 to REGMODE7 = 1 */
         __IO uint32_t  CAPCTRL2;               /**< 0208: SCT capture control register 0 to 7; REGMOD0 = 1 to REGMODE7 = 1 */
         __IO uint32_t  CAPCTRL3;               /**< 020C: SCT capture control register 0 to 7; REGMOD0 = 1 to REGMODE7 = 1 */
         __IO uint32_t  CAPCTRL4;               /**< 0210: SCT capture control register 0 to 7; REGMOD0 = 1 to REGMODE7 = 1 */
         __IO uint32_t  CAPCTRL5;               /**< 0214: SCT capture control register 0 to 7; REGMOD0 = 1 to REGMODE7 = 1 */
         __IO uint32_t  CAPCTRL6;               /**< 0218: SCT capture control register 0 to 7; REGMOD0 = 1 to REGMODE7 = 1 */
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CAPCTRL7;                  /**< 021C: SCT capture control register 0 to 7; REGMOD0 = 1 to REGMODE7 = 1 */
      __IO uint32_t  MATCHREL7;                 /**< 021C: SCT match reload value register 0 to 7; REGMOD0 = 0 to REGMODE7 = 0 */
   };
        uint8_t   RESERVED_5[224];             
   __IO uint32_t  EV0_STATE;                    /**< 0300: SCT event state register 0                                   */
   __IO uint32_t  EV0_CTRL;                     /**< 0304: SCT event control register 0                                 */
   __IO uint32_t  EV1_STATE;                    /**< 0308: SCT event state register 0                                   */
   __IO uint32_t  EV1_CTRL;                     /**< 030C: SCT event control register 0                                 */
   __IO uint32_t  EV2_STATE;                    /**< 0310: SCT event state register 0                                   */
   __IO uint32_t  EV2_CTRL;                     /**< 0314: SCT event control register 0                                 */
   __IO uint32_t  EV3_STATE;                    /**< 0318: SCT event state register 0                                   */
   __IO uint32_t  EV3_CTRL;                     /**< 031C: SCT event control register 0                                 */
   __IO uint32_t  EV4_STATE;                    /**< 0320: SCT event state register 0                                   */
   __IO uint32_t  EV4_CTRL;                     /**< 0324: SCT event control register 0                                 */
   __IO uint32_t  EV5_STATE;                    /**< 0328: SCT event state register 0                                   */
   __IO uint32_t  EV5_CTRL;                     /**< 032C: SCT event control register 0                                 */
   __IO uint32_t  EV6_STATE;                    /**< 0330: SCT event state register 0                                   */
   __IO uint32_t  EV6_CTRL;                     /**< 0334: SCT event control register 0                                 */
   __IO uint32_t  EV7_STATE;                    /**< 0338: SCT event state register 0                                   */
   __IO uint32_t  EV7_CTRL;                     /**< 033C: SCT event control register 0                                 */
        uint8_t   RESERVED_6[448];             
   __IO uint32_t  OUT0_SET;                     /**< 0500: SCT output 0 set register                                    */
   __IO uint32_t  OUT0_CLR;                     /**< 0504: SCT output 0 clear register                                  */
   __IO uint32_t  OUT1_SET;                     /**< 0508: SCT output 0 set register                                    */
   __IO uint32_t  OUT1_CLR;                     /**< 050C: SCT output 0 clear register                                  */
   __IO uint32_t  OUT2_SET;                     /**< 0510: SCT output 0 set register                                    */
   __IO uint32_t  OUT2_CLR;                     /**< 0514: SCT output 0 clear register                                  */
   __IO uint32_t  OUT3_SET;                     /**< 0518: SCT output 0 set register                                    */
   __IO uint32_t  OUT3_CLR;                     /**< 051C: SCT output 0 clear register                                  */
   __IO uint32_t  OUT4_SET;                     /**< 0520: SCT output 0 set register                                    */
   __IO uint32_t  OUT4_CLR;                     /**< 0524: SCT output 0 clear register                                  */
   __IO uint32_t  OUT5_SET;                     /**< 0528: SCT output 0 set register                                    */
   __IO uint32_t  OUT5_CLR;                     /**< 052C: SCT output 0 clear register                                  */
} LPC_SCT_Type;

/**
 * @} */ /* End group SCT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_SCT' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SCT_Register_Masks_GROUP SCT Register Masks
* @brief Register Masks for SCT
* @{
*/
/* ------- CONFIG Bit Fields                        ------ */
#define LPC_SCT_CONFIG_UNIFY_MASK                (0x1U)                                              /*!< LPC_SCT_CONFIG: UNIFY Mask              */
#define LPC_SCT_CONFIG_UNIFY_SHIFT               (0U)                                                /*!< LPC_SCT_CONFIG: UNIFY Position          */
#define LPC_SCT_CONFIG_UNIFY(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFIG_UNIFY_SHIFT))&LPC_SCT_CONFIG_UNIFY_MASK) /*!< LPC_SCT_CONFIG                          */
#define LPC_SCT_CONFIG_CLKMODE_MASK              (0x6U)                                              /*!< LPC_SCT_CONFIG: CLKMODE Mask            */
#define LPC_SCT_CONFIG_CLKMODE_SHIFT             (1U)                                                /*!< LPC_SCT_CONFIG: CLKMODE Position        */
#define LPC_SCT_CONFIG_CLKMODE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFIG_CLKMODE_SHIFT))&LPC_SCT_CONFIG_CLKMODE_MASK) /*!< LPC_SCT_CONFIG                          */
#define LPC_SCT_CONFIG_CKSEL_MASK                (0x78U)                                             /*!< LPC_SCT_CONFIG: CKSEL Mask              */
#define LPC_SCT_CONFIG_CKSEL_SHIFT               (3U)                                                /*!< LPC_SCT_CONFIG: CKSEL Position          */
#define LPC_SCT_CONFIG_CKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFIG_CKSEL_SHIFT))&LPC_SCT_CONFIG_CKSEL_MASK) /*!< LPC_SCT_CONFIG                          */
#define LPC_SCT_CONFIG_NORELAOD_L_MASK           (0x80U)                                             /*!< LPC_SCT_CONFIG: NORELAOD_L Mask         */
#define LPC_SCT_CONFIG_NORELAOD_L_SHIFT          (7U)                                                /*!< LPC_SCT_CONFIG: NORELAOD_L Position     */
#define LPC_SCT_CONFIG_NORELAOD_L(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFIG_NORELAOD_L_SHIFT))&LPC_SCT_CONFIG_NORELAOD_L_MASK) /*!< LPC_SCT_CONFIG                          */
#define LPC_SCT_CONFIG_NORELOAD_H_MASK           (0x100U)                                            /*!< LPC_SCT_CONFIG: NORELOAD_H Mask         */
#define LPC_SCT_CONFIG_NORELOAD_H_SHIFT          (8U)                                                /*!< LPC_SCT_CONFIG: NORELOAD_H Position     */
#define LPC_SCT_CONFIG_NORELOAD_H(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFIG_NORELOAD_H_SHIFT))&LPC_SCT_CONFIG_NORELOAD_H_MASK) /*!< LPC_SCT_CONFIG                          */
#define LPC_SCT_CONFIG_INSYNC_MASK               (0x1FE00U)                                          /*!< LPC_SCT_CONFIG: INSYNC Mask             */
#define LPC_SCT_CONFIG_INSYNC_SHIFT              (9U)                                                /*!< LPC_SCT_CONFIG: INSYNC Position         */
#define LPC_SCT_CONFIG_INSYNC(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFIG_INSYNC_SHIFT))&LPC_SCT_CONFIG_INSYNC_MASK) /*!< LPC_SCT_CONFIG                          */
#define LPC_SCT_CONFIG_AUTOLIMIT_L_MASK          (0x20000U)                                          /*!< LPC_SCT_CONFIG: AUTOLIMIT_L Mask        */
#define LPC_SCT_CONFIG_AUTOLIMIT_L_SHIFT         (17U)                                               /*!< LPC_SCT_CONFIG: AUTOLIMIT_L Position    */
#define LPC_SCT_CONFIG_AUTOLIMIT_L(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFIG_AUTOLIMIT_L_SHIFT))&LPC_SCT_CONFIG_AUTOLIMIT_L_MASK) /*!< LPC_SCT_CONFIG                          */
#define LPC_SCT_CONFIG_AUTOLIMIT_H_MASK          (0x40000U)                                          /*!< LPC_SCT_CONFIG: AUTOLIMIT_H Mask        */
#define LPC_SCT_CONFIG_AUTOLIMIT_H_SHIFT         (18U)                                               /*!< LPC_SCT_CONFIG: AUTOLIMIT_H Position    */
#define LPC_SCT_CONFIG_AUTOLIMIT_H(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFIG_AUTOLIMIT_H_SHIFT))&LPC_SCT_CONFIG_AUTOLIMIT_H_MASK) /*!< LPC_SCT_CONFIG                          */
/* ------- CTRL Bit Fields                          ------ */
#define LPC_SCT_CTRL_DOWN_L_MASK                 (0x1U)                                              /*!< LPC_SCT_CTRL: DOWN_L Mask               */
#define LPC_SCT_CTRL_DOWN_L_SHIFT                (0U)                                                /*!< LPC_SCT_CTRL: DOWN_L Position           */
#define LPC_SCT_CTRL_DOWN_L(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_DOWN_L_SHIFT))&LPC_SCT_CTRL_DOWN_L_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_STOP_L_MASK                 (0x2U)                                              /*!< LPC_SCT_CTRL: STOP_L Mask               */
#define LPC_SCT_CTRL_STOP_L_SHIFT                (1U)                                                /*!< LPC_SCT_CTRL: STOP_L Position           */
#define LPC_SCT_CTRL_STOP_L(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_STOP_L_SHIFT))&LPC_SCT_CTRL_STOP_L_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_HALT_L_MASK                 (0x4U)                                              /*!< LPC_SCT_CTRL: HALT_L Mask               */
#define LPC_SCT_CTRL_HALT_L_SHIFT                (2U)                                                /*!< LPC_SCT_CTRL: HALT_L Position           */
#define LPC_SCT_CTRL_HALT_L(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_HALT_L_SHIFT))&LPC_SCT_CTRL_HALT_L_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_CLRCTR_L_MASK               (0x8U)                                              /*!< LPC_SCT_CTRL: CLRCTR_L Mask             */
#define LPC_SCT_CTRL_CLRCTR_L_SHIFT              (3U)                                                /*!< LPC_SCT_CTRL: CLRCTR_L Position         */
#define LPC_SCT_CTRL_CLRCTR_L(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_CLRCTR_L_SHIFT))&LPC_SCT_CTRL_CLRCTR_L_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_BIDIR_L_MASK                (0x10U)                                             /*!< LPC_SCT_CTRL: BIDIR_L Mask              */
#define LPC_SCT_CTRL_BIDIR_L_SHIFT               (4U)                                                /*!< LPC_SCT_CTRL: BIDIR_L Position          */
#define LPC_SCT_CTRL_BIDIR_L(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_BIDIR_L_SHIFT))&LPC_SCT_CTRL_BIDIR_L_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_PRE_L_MASK                  (0x1FE0U)                                           /*!< LPC_SCT_CTRL: PRE_L Mask                */
#define LPC_SCT_CTRL_PRE_L_SHIFT                 (5U)                                                /*!< LPC_SCT_CTRL: PRE_L Position            */
#define LPC_SCT_CTRL_PRE_L(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_PRE_L_SHIFT))&LPC_SCT_CTRL_PRE_L_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_DOWN_H_MASK                 (0x10000U)                                          /*!< LPC_SCT_CTRL: DOWN_H Mask               */
#define LPC_SCT_CTRL_DOWN_H_SHIFT                (16U)                                               /*!< LPC_SCT_CTRL: DOWN_H Position           */
#define LPC_SCT_CTRL_DOWN_H(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_DOWN_H_SHIFT))&LPC_SCT_CTRL_DOWN_H_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_STOP_H_MASK                 (0x20000U)                                          /*!< LPC_SCT_CTRL: STOP_H Mask               */
#define LPC_SCT_CTRL_STOP_H_SHIFT                (17U)                                               /*!< LPC_SCT_CTRL: STOP_H Position           */
#define LPC_SCT_CTRL_STOP_H(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_STOP_H_SHIFT))&LPC_SCT_CTRL_STOP_H_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_HALT_H_MASK                 (0x40000U)                                          /*!< LPC_SCT_CTRL: HALT_H Mask               */
#define LPC_SCT_CTRL_HALT_H_SHIFT                (18U)                                               /*!< LPC_SCT_CTRL: HALT_H Position           */
#define LPC_SCT_CTRL_HALT_H(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_HALT_H_SHIFT))&LPC_SCT_CTRL_HALT_H_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_CLRCTR_H_MASK               (0x80000U)                                          /*!< LPC_SCT_CTRL: CLRCTR_H Mask             */
#define LPC_SCT_CTRL_CLRCTR_H_SHIFT              (19U)                                               /*!< LPC_SCT_CTRL: CLRCTR_H Position         */
#define LPC_SCT_CTRL_CLRCTR_H(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_CLRCTR_H_SHIFT))&LPC_SCT_CTRL_CLRCTR_H_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_BIDIR_H_MASK                (0x100000U)                                         /*!< LPC_SCT_CTRL: BIDIR_H Mask              */
#define LPC_SCT_CTRL_BIDIR_H_SHIFT               (20U)                                               /*!< LPC_SCT_CTRL: BIDIR_H Position          */
#define LPC_SCT_CTRL_BIDIR_H(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_BIDIR_H_SHIFT))&LPC_SCT_CTRL_BIDIR_H_MASK) /*!< LPC_SCT_CTRL                            */
#define LPC_SCT_CTRL_PRE_H_MASK                  (0x1FE00000U)                                       /*!< LPC_SCT_CTRL: PRE_H Mask                */
#define LPC_SCT_CTRL_PRE_H_SHIFT                 (21U)                                               /*!< LPC_SCT_CTRL: PRE_H Position            */
#define LPC_SCT_CTRL_PRE_H(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CTRL_PRE_H_SHIFT))&LPC_SCT_CTRL_PRE_H_MASK) /*!< LPC_SCT_CTRL                            */
/* ------- LIMIT Bit Fields                         ------ */
#define LPC_SCT_LIMIT_LIMMSK_L_MASK              (0xFFU)                                             /*!< LPC_SCT_LIMIT: LIMMSK_L Mask            */
#define LPC_SCT_LIMIT_LIMMSK_L_SHIFT             (0U)                                                /*!< LPC_SCT_LIMIT: LIMMSK_L Position        */
#define LPC_SCT_LIMIT_LIMMSK_L(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_LIMIT_LIMMSK_L_SHIFT))&LPC_SCT_LIMIT_LIMMSK_L_MASK) /*!< LPC_SCT_LIMIT                           */
#define LPC_SCT_LIMIT_LIMMSK_H_MASK              (0xFF0000U)                                         /*!< LPC_SCT_LIMIT: LIMMSK_H Mask            */
#define LPC_SCT_LIMIT_LIMMSK_H_SHIFT             (16U)                                               /*!< LPC_SCT_LIMIT: LIMMSK_H Position        */
#define LPC_SCT_LIMIT_LIMMSK_H(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_LIMIT_LIMMSK_H_SHIFT))&LPC_SCT_LIMIT_LIMMSK_H_MASK) /*!< LPC_SCT_LIMIT                           */
/* ------- HALT Bit Fields                          ------ */
#define LPC_SCT_HALT_HALTMSK_L_MASK              (0xFFU)                                             /*!< LPC_SCT_HALT: HALTMSK_L Mask            */
#define LPC_SCT_HALT_HALTMSK_L_SHIFT             (0U)                                                /*!< LPC_SCT_HALT: HALTMSK_L Position        */
#define LPC_SCT_HALT_HALTMSK_L(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_HALT_HALTMSK_L_SHIFT))&LPC_SCT_HALT_HALTMSK_L_MASK) /*!< LPC_SCT_HALT                            */
#define LPC_SCT_HALT_HALTMSK_H_MASK              (0xFF0000U)                                         /*!< LPC_SCT_HALT: HALTMSK_H Mask            */
#define LPC_SCT_HALT_HALTMSK_H_SHIFT             (16U)                                               /*!< LPC_SCT_HALT: HALTMSK_H Position        */
#define LPC_SCT_HALT_HALTMSK_H(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_HALT_HALTMSK_H_SHIFT))&LPC_SCT_HALT_HALTMSK_H_MASK) /*!< LPC_SCT_HALT                            */
/* ------- STOP Bit Fields                          ------ */
#define LPC_SCT_STOP_STOPMSK_L_MASK              (0xFFU)                                             /*!< LPC_SCT_STOP: STOPMSK_L Mask            */
#define LPC_SCT_STOP_STOPMSK_L_SHIFT             (0U)                                                /*!< LPC_SCT_STOP: STOPMSK_L Position        */
#define LPC_SCT_STOP_STOPMSK_L(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_STOP_STOPMSK_L_SHIFT))&LPC_SCT_STOP_STOPMSK_L_MASK) /*!< LPC_SCT_STOP                            */
#define LPC_SCT_STOP_STOPMSK_H_MASK              (0xFF0000U)                                         /*!< LPC_SCT_STOP: STOPMSK_H Mask            */
#define LPC_SCT_STOP_STOPMSK_H_SHIFT             (16U)                                               /*!< LPC_SCT_STOP: STOPMSK_H Position        */
#define LPC_SCT_STOP_STOPMSK_H(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_STOP_STOPMSK_H_SHIFT))&LPC_SCT_STOP_STOPMSK_H_MASK) /*!< LPC_SCT_STOP                            */
/* ------- START Bit Fields                         ------ */
#define LPC_SCT_START_STARTMSK_L_MASK            (0xFFU)                                             /*!< LPC_SCT_START: STARTMSK_L Mask          */
#define LPC_SCT_START_STARTMSK_L_SHIFT           (0U)                                                /*!< LPC_SCT_START: STARTMSK_L Position      */
#define LPC_SCT_START_STARTMSK_L(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_START_STARTMSK_L_SHIFT))&LPC_SCT_START_STARTMSK_L_MASK) /*!< LPC_SCT_START                           */
#define LPC_SCT_START_STARTMSK_H_MASK            (0xFF0000U)                                         /*!< LPC_SCT_START: STARTMSK_H Mask          */
#define LPC_SCT_START_STARTMSK_H_SHIFT           (16U)                                               /*!< LPC_SCT_START: STARTMSK_H Position      */
#define LPC_SCT_START_STARTMSK_H(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_START_STARTMSK_H_SHIFT))&LPC_SCT_START_STARTMSK_H_MASK) /*!< LPC_SCT_START                           */
/* ------- COUNT Bit Fields                         ------ */
#define LPC_SCT_COUNT_CTR_L_MASK                 (0xFFFFU)                                           /*!< LPC_SCT_COUNT: CTR_L Mask               */
#define LPC_SCT_COUNT_CTR_L_SHIFT                (0U)                                                /*!< LPC_SCT_COUNT: CTR_L Position           */
#define LPC_SCT_COUNT_CTR_L(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_COUNT_CTR_L_SHIFT))&LPC_SCT_COUNT_CTR_L_MASK) /*!< LPC_SCT_COUNT                           */
#define LPC_SCT_COUNT_CTR_H_MASK                 (0xFFFF0000U)                                       /*!< LPC_SCT_COUNT: CTR_H Mask               */
#define LPC_SCT_COUNT_CTR_H_SHIFT                (16U)                                               /*!< LPC_SCT_COUNT: CTR_H Position           */
#define LPC_SCT_COUNT_CTR_H(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_COUNT_CTR_H_SHIFT))&LPC_SCT_COUNT_CTR_H_MASK) /*!< LPC_SCT_COUNT                           */
/* ------- STATE Bit Fields                         ------ */
#define LPC_SCT_STATE_STATE_L_MASK               (0x1FU)                                             /*!< LPC_SCT_STATE: STATE_L Mask             */
#define LPC_SCT_STATE_STATE_L_SHIFT              (0U)                                                /*!< LPC_SCT_STATE: STATE_L Position         */
#define LPC_SCT_STATE_STATE_L(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SCT_STATE_STATE_L_SHIFT))&LPC_SCT_STATE_STATE_L_MASK) /*!< LPC_SCT_STATE                           */
#define LPC_SCT_STATE_STATE_H_MASK               (0x1F0000U)                                         /*!< LPC_SCT_STATE: STATE_H Mask             */
#define LPC_SCT_STATE_STATE_H_SHIFT              (16U)                                               /*!< LPC_SCT_STATE: STATE_H Position         */
#define LPC_SCT_STATE_STATE_H(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SCT_STATE_STATE_H_SHIFT))&LPC_SCT_STATE_STATE_H_MASK) /*!< LPC_SCT_STATE                           */
/* ------- INPUT Bit Fields                         ------ */
#define LPC_SCT_INPUT_AIN0_MASK                  (0x1U)                                              /*!< LPC_SCT_INPUT: AIN0 Mask                */
#define LPC_SCT_INPUT_AIN0_SHIFT                 (0U)                                                /*!< LPC_SCT_INPUT: AIN0 Position            */
#define LPC_SCT_INPUT_AIN0(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_INPUT_AIN0_SHIFT))&LPC_SCT_INPUT_AIN0_MASK) /*!< LPC_SCT_INPUT                           */
#define LPC_SCT_INPUT_AIN1_MASK                  (0x2U)                                              /*!< LPC_SCT_INPUT: AIN1 Mask                */
#define LPC_SCT_INPUT_AIN1_SHIFT                 (1U)                                                /*!< LPC_SCT_INPUT: AIN1 Position            */
#define LPC_SCT_INPUT_AIN1(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_INPUT_AIN1_SHIFT))&LPC_SCT_INPUT_AIN1_MASK) /*!< LPC_SCT_INPUT                           */
#define LPC_SCT_INPUT_AIN2_MASK                  (0x4U)                                              /*!< LPC_SCT_INPUT: AIN2 Mask                */
#define LPC_SCT_INPUT_AIN2_SHIFT                 (2U)                                                /*!< LPC_SCT_INPUT: AIN2 Position            */
#define LPC_SCT_INPUT_AIN2(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_INPUT_AIN2_SHIFT))&LPC_SCT_INPUT_AIN2_MASK) /*!< LPC_SCT_INPUT                           */
#define LPC_SCT_INPUT_AIN3_MASK                  (0x8U)                                              /*!< LPC_SCT_INPUT: AIN3 Mask                */
#define LPC_SCT_INPUT_AIN3_SHIFT                 (3U)                                                /*!< LPC_SCT_INPUT: AIN3 Position            */
#define LPC_SCT_INPUT_AIN3(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_INPUT_AIN3_SHIFT))&LPC_SCT_INPUT_AIN3_MASK) /*!< LPC_SCT_INPUT                           */
#define LPC_SCT_INPUT_SIN0_MASK                  (0x10000U)                                          /*!< LPC_SCT_INPUT: SIN0 Mask                */
#define LPC_SCT_INPUT_SIN0_SHIFT                 (16U)                                               /*!< LPC_SCT_INPUT: SIN0 Position            */
#define LPC_SCT_INPUT_SIN0(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_INPUT_SIN0_SHIFT))&LPC_SCT_INPUT_SIN0_MASK) /*!< LPC_SCT_INPUT                           */
#define LPC_SCT_INPUT_SIN1_MASK                  (0x20000U)                                          /*!< LPC_SCT_INPUT: SIN1 Mask                */
#define LPC_SCT_INPUT_SIN1_SHIFT                 (17U)                                               /*!< LPC_SCT_INPUT: SIN1 Position            */
#define LPC_SCT_INPUT_SIN1(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_INPUT_SIN1_SHIFT))&LPC_SCT_INPUT_SIN1_MASK) /*!< LPC_SCT_INPUT                           */
#define LPC_SCT_INPUT_SIN2_MASK                  (0x40000U)                                          /*!< LPC_SCT_INPUT: SIN2 Mask                */
#define LPC_SCT_INPUT_SIN2_SHIFT                 (18U)                                               /*!< LPC_SCT_INPUT: SIN2 Position            */
#define LPC_SCT_INPUT_SIN2(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_INPUT_SIN2_SHIFT))&LPC_SCT_INPUT_SIN2_MASK) /*!< LPC_SCT_INPUT                           */
#define LPC_SCT_INPUT_SIN3_MASK                  (0x80000U)                                          /*!< LPC_SCT_INPUT: SIN3 Mask                */
#define LPC_SCT_INPUT_SIN3_SHIFT                 (19U)                                               /*!< LPC_SCT_INPUT: SIN3 Position            */
#define LPC_SCT_INPUT_SIN3(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_INPUT_SIN3_SHIFT))&LPC_SCT_INPUT_SIN3_MASK) /*!< LPC_SCT_INPUT                           */
/* ------- REGMODE Bit Fields                       ------ */
#define LPC_SCT_REGMODE_REGMOD_L_MASK            (0xFFU)                                             /*!< LPC_SCT_REGMODE: REGMOD_L Mask          */
#define LPC_SCT_REGMODE_REGMOD_L_SHIFT           (0U)                                                /*!< LPC_SCT_REGMODE: REGMOD_L Position      */
#define LPC_SCT_REGMODE_REGMOD_L(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_REGMODE_REGMOD_L_SHIFT))&LPC_SCT_REGMODE_REGMOD_L_MASK) /*!< LPC_SCT_REGMODE                         */
#define LPC_SCT_REGMODE_REGMOD_H_MASK            (0xFF0000U)                                         /*!< LPC_SCT_REGMODE: REGMOD_H Mask          */
#define LPC_SCT_REGMODE_REGMOD_H_SHIFT           (16U)                                               /*!< LPC_SCT_REGMODE: REGMOD_H Position      */
#define LPC_SCT_REGMODE_REGMOD_H(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_REGMODE_REGMOD_H_SHIFT))&LPC_SCT_REGMODE_REGMOD_H_MASK) /*!< LPC_SCT_REGMODE                         */
/* ------- OUTPUT Bit Fields                        ------ */
#define LPC_SCT_OUTPUT_OUT_MASK                  (0x3FU)                                             /*!< LPC_SCT_OUTPUT: OUT Mask                */
#define LPC_SCT_OUTPUT_OUT_SHIFT                 (0U)                                                /*!< LPC_SCT_OUTPUT: OUT Position            */
#define LPC_SCT_OUTPUT_OUT(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUTPUT_OUT_SHIFT))&LPC_SCT_OUTPUT_OUT_MASK) /*!< LPC_SCT_OUTPUT                          */
/* ------- OUTPUTDIRCTRL Bit Fields                 ------ */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR0_MASK       (0x3U)                                              /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR0 Mask     */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR0_SHIFT      (0U)                                                /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR0 Position */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR0(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUTPUTDIRCTRL_SETCLR0_SHIFT))&LPC_SCT_OUTPUTDIRCTRL_SETCLR0_MASK) /*!< LPC_SCT_OUTPUTDIRCTRL                   */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR1_MASK       (0xCU)                                              /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR1 Mask     */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR1_SHIFT      (2U)                                                /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR1 Position */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR1(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUTPUTDIRCTRL_SETCLR1_SHIFT))&LPC_SCT_OUTPUTDIRCTRL_SETCLR1_MASK) /*!< LPC_SCT_OUTPUTDIRCTRL                   */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR2_MASK       (0x30U)                                             /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR2 Mask     */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR2_SHIFT      (4U)                                                /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR2 Position */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR2(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUTPUTDIRCTRL_SETCLR2_SHIFT))&LPC_SCT_OUTPUTDIRCTRL_SETCLR2_MASK) /*!< LPC_SCT_OUTPUTDIRCTRL                   */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR3_MASK       (0xC0U)                                             /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR3 Mask     */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR3_SHIFT      (6U)                                                /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR3 Position */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR3(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUTPUTDIRCTRL_SETCLR3_SHIFT))&LPC_SCT_OUTPUTDIRCTRL_SETCLR3_MASK) /*!< LPC_SCT_OUTPUTDIRCTRL                   */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR4_MASK       (0x300U)                                            /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR4 Mask     */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR4_SHIFT      (8U)                                                /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR4 Position */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR4(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUTPUTDIRCTRL_SETCLR4_SHIFT))&LPC_SCT_OUTPUTDIRCTRL_SETCLR4_MASK) /*!< LPC_SCT_OUTPUTDIRCTRL                   */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR5_MASK       (0xC00U)                                            /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR5 Mask     */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR5_SHIFT      (10U)                                               /*!< LPC_SCT_OUTPUTDIRCTRL: SETCLR5 Position */
#define LPC_SCT_OUTPUTDIRCTRL_SETCLR5(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUTPUTDIRCTRL_SETCLR5_SHIFT))&LPC_SCT_OUTPUTDIRCTRL_SETCLR5_MASK) /*!< LPC_SCT_OUTPUTDIRCTRL                   */
/* ------- RES Bit Fields                           ------ */
#define LPC_SCT_RES_O0RES_MASK                   (0x3U)                                              /*!< LPC_SCT_RES: O0RES Mask                 */
#define LPC_SCT_RES_O0RES_SHIFT                  (0U)                                                /*!< LPC_SCT_RES: O0RES Position             */
#define LPC_SCT_RES_O0RES(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SCT_RES_O0RES_SHIFT))&LPC_SCT_RES_O0RES_MASK) /*!< LPC_SCT_RES                             */
#define LPC_SCT_RES_O1RES_MASK                   (0xCU)                                              /*!< LPC_SCT_RES: O1RES Mask                 */
#define LPC_SCT_RES_O1RES_SHIFT                  (2U)                                                /*!< LPC_SCT_RES: O1RES Position             */
#define LPC_SCT_RES_O1RES(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SCT_RES_O1RES_SHIFT))&LPC_SCT_RES_O1RES_MASK) /*!< LPC_SCT_RES                             */
#define LPC_SCT_RES_O2RES_MASK                   (0x30U)                                             /*!< LPC_SCT_RES: O2RES Mask                 */
#define LPC_SCT_RES_O2RES_SHIFT                  (4U)                                                /*!< LPC_SCT_RES: O2RES Position             */
#define LPC_SCT_RES_O2RES(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SCT_RES_O2RES_SHIFT))&LPC_SCT_RES_O2RES_MASK) /*!< LPC_SCT_RES                             */
#define LPC_SCT_RES_O3RES_MASK                   (0xC0U)                                             /*!< LPC_SCT_RES: O3RES Mask                 */
#define LPC_SCT_RES_O3RES_SHIFT                  (6U)                                                /*!< LPC_SCT_RES: O3RES Position             */
#define LPC_SCT_RES_O3RES(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SCT_RES_O3RES_SHIFT))&LPC_SCT_RES_O3RES_MASK) /*!< LPC_SCT_RES                             */
#define LPC_SCT_RES_O4RES_MASK                   (0x300U)                                            /*!< LPC_SCT_RES: O4RES Mask                 */
#define LPC_SCT_RES_O4RES_SHIFT                  (8U)                                                /*!< LPC_SCT_RES: O4RES Position             */
#define LPC_SCT_RES_O4RES(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SCT_RES_O4RES_SHIFT))&LPC_SCT_RES_O4RES_MASK) /*!< LPC_SCT_RES                             */
#define LPC_SCT_RES_O5RES_MASK                   (0xC00U)                                            /*!< LPC_SCT_RES: O5RES Mask                 */
#define LPC_SCT_RES_O5RES_SHIFT                  (10U)                                               /*!< LPC_SCT_RES: O5RES Position             */
#define LPC_SCT_RES_O5RES(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SCT_RES_O5RES_SHIFT))&LPC_SCT_RES_O5RES_MASK) /*!< LPC_SCT_RES                             */
/* ------- DMAREQ Bit Fields                        ------ */
#define LPC_SCT_DMAREQ_DEV_0_MASK                (0x3FU)                                             /*!< LPC_SCT_DMAREQ: DEV_0 Mask              */
#define LPC_SCT_DMAREQ_DEV_0_SHIFT               (0U)                                                /*!< LPC_SCT_DMAREQ: DEV_0 Position          */
#define LPC_SCT_DMAREQ_DEV_0(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_DMAREQ_DEV_0_SHIFT))&LPC_SCT_DMAREQ_DEV_0_MASK) /*!< LPC_SCT_DMAREQ                          */
#define LPC_SCT_DMAREQ_DRL0_MASK                 (0x40000000U)                                       /*!< LPC_SCT_DMAREQ: DRL0 Mask               */
#define LPC_SCT_DMAREQ_DRL0_SHIFT                (30U)                                               /*!< LPC_SCT_DMAREQ: DRL0 Position           */
#define LPC_SCT_DMAREQ_DRL0(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_DMAREQ_DRL0_SHIFT))&LPC_SCT_DMAREQ_DRL0_MASK) /*!< LPC_SCT_DMAREQ                          */
#define LPC_SCT_DMAREQ_DRQ0_MASK                 (0x80000000U)                                       /*!< LPC_SCT_DMAREQ: DRQ0 Mask               */
#define LPC_SCT_DMAREQ_DRQ0_SHIFT                (31U)                                               /*!< LPC_SCT_DMAREQ: DRQ0 Position           */
#define LPC_SCT_DMAREQ_DRQ0(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_DMAREQ_DRQ0_SHIFT))&LPC_SCT_DMAREQ_DRQ0_MASK) /*!< LPC_SCT_DMAREQ                          */
/* ------- EVEN Bit Fields                          ------ */
#define LPC_SCT_EVEN_IEN_MASK                    (0xFFU)                                             /*!< LPC_SCT_EVEN: IEN Mask                  */
#define LPC_SCT_EVEN_IEN_SHIFT                   (0U)                                                /*!< LPC_SCT_EVEN: IEN Position              */
#define LPC_SCT_EVEN_IEN(x)                      (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EVEN_IEN_SHIFT))&LPC_SCT_EVEN_IEN_MASK) /*!< LPC_SCT_EVEN                            */
/* ------- EVFLAG Bit Fields                        ------ */
#define LPC_SCT_EVFLAG_FLAG_MASK                 (0xFFU)                                             /*!< LPC_SCT_EVFLAG: FLAG Mask               */
#define LPC_SCT_EVFLAG_FLAG_SHIFT                (0U)                                                /*!< LPC_SCT_EVFLAG: FLAG Position           */
#define LPC_SCT_EVFLAG_FLAG(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EVFLAG_FLAG_SHIFT))&LPC_SCT_EVFLAG_FLAG_MASK) /*!< LPC_SCT_EVFLAG                          */
/* ------- CONEN Bit Fields                         ------ */
#define LPC_SCT_CONEN_NCEN_MASK                  (0x3FU)                                             /*!< LPC_SCT_CONEN: NCEN Mask                */
#define LPC_SCT_CONEN_NCEN_SHIFT                 (0U)                                                /*!< LPC_SCT_CONEN: NCEN Position            */
#define LPC_SCT_CONEN_NCEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONEN_NCEN_SHIFT))&LPC_SCT_CONEN_NCEN_MASK) /*!< LPC_SCT_CONEN                           */
/* ------- CONFLAG Bit Fields                       ------ */
#define LPC_SCT_CONFLAG_NCFLAG_MASK              (0x3FU)                                             /*!< LPC_SCT_CONFLAG: NCFLAG Mask            */
#define LPC_SCT_CONFLAG_NCFLAG_SHIFT             (0U)                                                /*!< LPC_SCT_CONFLAG: NCFLAG Position        */
#define LPC_SCT_CONFLAG_NCFLAG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFLAG_NCFLAG_SHIFT))&LPC_SCT_CONFLAG_NCFLAG_MASK) /*!< LPC_SCT_CONFLAG                         */
#define LPC_SCT_CONFLAG_BUSERRL_MASK             (0x40000000U)                                       /*!< LPC_SCT_CONFLAG: BUSERRL Mask           */
#define LPC_SCT_CONFLAG_BUSERRL_SHIFT            (30U)                                               /*!< LPC_SCT_CONFLAG: BUSERRL Position       */
#define LPC_SCT_CONFLAG_BUSERRL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFLAG_BUSERRL_SHIFT))&LPC_SCT_CONFLAG_BUSERRL_MASK) /*!< LPC_SCT_CONFLAG                         */
#define LPC_SCT_CONFLAG_BUSERRH_MASK             (0x80000000U)                                       /*!< LPC_SCT_CONFLAG: BUSERRH Mask           */
#define LPC_SCT_CONFLAG_BUSERRH_SHIFT            (31U)                                               /*!< LPC_SCT_CONFLAG: BUSERRH Position       */
#define LPC_SCT_CONFLAG_BUSERRH(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CONFLAG_BUSERRH_SHIFT))&LPC_SCT_CONFLAG_BUSERRH_MASK) /*!< LPC_SCT_CONFLAG                         */
/* ------- CAP0 Bit Fields                          ------ */
#define LPC_SCT_CAP0_CAPn_L_MASK                 (0xFFFFU)                                           /*!< LPC_SCT_CAP0: CAPn_L Mask               */
#define LPC_SCT_CAP0_CAPn_L_SHIFT                (0U)                                                /*!< LPC_SCT_CAP0: CAPn_L Position           */
#define LPC_SCT_CAP0_CAPn_L(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAP0_CAPn_L_SHIFT))&LPC_SCT_CAP0_CAPn_L_MASK) /*!< LPC_SCT_CAP0                            */
#define LPC_SCT_CAP0_CAPn_H_MASK                 (0xFFFF0000U)                                       /*!< LPC_SCT_CAP0: CAPn_H Mask               */
#define LPC_SCT_CAP0_CAPn_H_SHIFT                (16U)                                               /*!< LPC_SCT_CAP0: CAPn_H Position           */
#define LPC_SCT_CAP0_CAPn_H(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAP0_CAPn_H_SHIFT))&LPC_SCT_CAP0_CAPn_H_MASK) /*!< LPC_SCT_CAP0                            */
/* ------- MATCH0 Bit Fields                        ------ */
#define LPC_SCT_MATCH0_MATCHn_L_MASK             (0xFFFFU)                                           /*!< LPC_SCT_MATCH0: MATCHn_L Mask           */
#define LPC_SCT_MATCH0_MATCHn_L_SHIFT            (0U)                                                /*!< LPC_SCT_MATCH0: MATCHn_L Position       */
#define LPC_SCT_MATCH0_MATCHn_L(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCH0_MATCHn_L_SHIFT))&LPC_SCT_MATCH0_MATCHn_L_MASK) /*!< LPC_SCT_MATCH0                          */
#define LPC_SCT_MATCH0_MATCHn_H_MASK             (0xFFFF0000U)                                       /*!< LPC_SCT_MATCH0: MATCHn_H Mask           */
#define LPC_SCT_MATCH0_MATCHn_H_SHIFT            (16U)                                               /*!< LPC_SCT_MATCH0: MATCHn_H Position       */
#define LPC_SCT_MATCH0_MATCHn_H(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCH0_MATCHn_H_SHIFT))&LPC_SCT_MATCH0_MATCHn_H_MASK) /*!< LPC_SCT_MATCH0                          */
/* ------- MATCH Bit Fields                         ------ */
#define LPC_SCT_MATCH_MATCHn_L_MASK              (0xFFFFU)                                           /*!< LPC_SCT_MATCH: MATCHn_L Mask            */
#define LPC_SCT_MATCH_MATCHn_L_SHIFT             (0U)                                                /*!< LPC_SCT_MATCH: MATCHn_L Position        */
#define LPC_SCT_MATCH_MATCHn_L(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCH_MATCHn_L_SHIFT))&LPC_SCT_MATCH_MATCHn_L_MASK) /*!< LPC_SCT_MATCH                           */
#define LPC_SCT_MATCH_MATCHn_H_MASK              (0xFFFF0000U)                                       /*!< LPC_SCT_MATCH: MATCHn_H Mask            */
#define LPC_SCT_MATCH_MATCHn_H_SHIFT             (16U)                                               /*!< LPC_SCT_MATCH: MATCHn_H Position        */
#define LPC_SCT_MATCH_MATCHn_H(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCH_MATCHn_H_SHIFT))&LPC_SCT_MATCH_MATCHn_H_MASK) /*!< LPC_SCT_MATCH                           */
/* ------- CAP1 Bit Fields                          ------ */
#define LPC_SCT_CAP1_CAPn_L_MASK                 (0xFFFFU)                                           /*!< LPC_SCT_CAP1: CAPn_L Mask               */
#define LPC_SCT_CAP1_CAPn_L_SHIFT                (0U)                                                /*!< LPC_SCT_CAP1: CAPn_L Position           */
#define LPC_SCT_CAP1_CAPn_L(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAP1_CAPn_L_SHIFT))&LPC_SCT_CAP1_CAPn_L_MASK) /*!< LPC_SCT_CAP1                            */
#define LPC_SCT_CAP1_CAPn_H_MASK                 (0xFFFF0000U)                                       /*!< LPC_SCT_CAP1: CAPn_H Mask               */
#define LPC_SCT_CAP1_CAPn_H_SHIFT                (16U)                                               /*!< LPC_SCT_CAP1: CAPn_H Position           */
#define LPC_SCT_CAP1_CAPn_H(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAP1_CAPn_H_SHIFT))&LPC_SCT_CAP1_CAPn_H_MASK) /*!< LPC_SCT_CAP1                            */
/* ------- CAP Bit Fields                           ------ */
#define LPC_SCT_CAP_CAPn_L_MASK                  (0xFFFFU)                                           /*!< LPC_SCT_CAP: CAPn_L Mask                */
#define LPC_SCT_CAP_CAPn_L_SHIFT                 (0U)                                                /*!< LPC_SCT_CAP: CAPn_L Position            */
#define LPC_SCT_CAP_CAPn_L(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAP_CAPn_L_SHIFT))&LPC_SCT_CAP_CAPn_L_MASK) /*!< LPC_SCT_CAP                             */
#define LPC_SCT_CAP_CAPn_H_MASK                  (0xFFFF0000U)                                       /*!< LPC_SCT_CAP: CAPn_H Mask                */
#define LPC_SCT_CAP_CAPn_H_SHIFT                 (16U)                                               /*!< LPC_SCT_CAP: CAPn_H Position            */
#define LPC_SCT_CAP_CAPn_H(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAP_CAPn_H_SHIFT))&LPC_SCT_CAP_CAPn_H_MASK) /*!< LPC_SCT_CAP                             */
/* ------- CAP7 Bit Fields                          ------ */
#define LPC_SCT_CAP7_CAPn_L_MASK                 (0xFFFFU)                                           /*!< LPC_SCT_CAP7: CAPn_L Mask               */
#define LPC_SCT_CAP7_CAPn_L_SHIFT                (0U)                                                /*!< LPC_SCT_CAP7: CAPn_L Position           */
#define LPC_SCT_CAP7_CAPn_L(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAP7_CAPn_L_SHIFT))&LPC_SCT_CAP7_CAPn_L_MASK) /*!< LPC_SCT_CAP7                            */
#define LPC_SCT_CAP7_CAPn_H_MASK                 (0xFFFF0000U)                                       /*!< LPC_SCT_CAP7: CAPn_H Mask               */
#define LPC_SCT_CAP7_CAPn_H_SHIFT                (16U)                                               /*!< LPC_SCT_CAP7: CAPn_H Position           */
#define LPC_SCT_CAP7_CAPn_H(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAP7_CAPn_H_SHIFT))&LPC_SCT_CAP7_CAPn_H_MASK) /*!< LPC_SCT_CAP7                            */
/* ------- MATCH7 Bit Fields                        ------ */
#define LPC_SCT_MATCH7_MATCHn_L_MASK             (0xFFFFU)                                           /*!< LPC_SCT_MATCH7: MATCHn_L Mask           */
#define LPC_SCT_MATCH7_MATCHn_L_SHIFT            (0U)                                                /*!< LPC_SCT_MATCH7: MATCHn_L Position       */
#define LPC_SCT_MATCH7_MATCHn_L(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCH7_MATCHn_L_SHIFT))&LPC_SCT_MATCH7_MATCHn_L_MASK) /*!< LPC_SCT_MATCH7                          */
#define LPC_SCT_MATCH7_MATCHn_H_MASK             (0xFFFF0000U)                                       /*!< LPC_SCT_MATCH7: MATCHn_H Mask           */
#define LPC_SCT_MATCH7_MATCHn_H_SHIFT            (16U)                                               /*!< LPC_SCT_MATCH7: MATCHn_H Position       */
#define LPC_SCT_MATCH7_MATCHn_H(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCH7_MATCHn_H_SHIFT))&LPC_SCT_MATCH7_MATCHn_H_MASK) /*!< LPC_SCT_MATCH7                          */
/* ------- CAPCTRL0 Bit Fields                      ------ */
#define LPC_SCT_CAPCTRL0_CAPCONn_L_MASK          (0xFFU)                                             /*!< LPC_SCT_CAPCTRL0: CAPCONn_L Mask        */
#define LPC_SCT_CAPCTRL0_CAPCONn_L_SHIFT         (0U)                                                /*!< LPC_SCT_CAPCTRL0: CAPCONn_L Position    */
#define LPC_SCT_CAPCTRL0_CAPCONn_L(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAPCTRL0_CAPCONn_L_SHIFT))&LPC_SCT_CAPCTRL0_CAPCONn_L_MASK) /*!< LPC_SCT_CAPCTRL0                        */
#define LPC_SCT_CAPCTRL0_CAPCONn_H_MASK          (0xFF0000U)                                         /*!< LPC_SCT_CAPCTRL0: CAPCONn_H Mask        */
#define LPC_SCT_CAPCTRL0_CAPCONn_H_SHIFT         (16U)                                               /*!< LPC_SCT_CAPCTRL0: CAPCONn_H Position    */
#define LPC_SCT_CAPCTRL0_CAPCONn_H(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAPCTRL0_CAPCONn_H_SHIFT))&LPC_SCT_CAPCTRL0_CAPCONn_H_MASK) /*!< LPC_SCT_CAPCTRL0                        */
/* ------- MATCHREL0 Bit Fields                     ------ */
#define LPC_SCT_MATCHREL0_RELOADn_L_MASK         (0xFFFFU)                                           /*!< LPC_SCT_MATCHREL0: RELOADn_L Mask       */
#define LPC_SCT_MATCHREL0_RELOADn_L_SHIFT        (0U)                                                /*!< LPC_SCT_MATCHREL0: RELOADn_L Position   */
#define LPC_SCT_MATCHREL0_RELOADn_L(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCHREL0_RELOADn_L_SHIFT))&LPC_SCT_MATCHREL0_RELOADn_L_MASK) /*!< LPC_SCT_MATCHREL0                       */
#define LPC_SCT_MATCHREL0_RELOADn_H_MASK         (0xFFFF0000U)                                       /*!< LPC_SCT_MATCHREL0: RELOADn_H Mask       */
#define LPC_SCT_MATCHREL0_RELOADn_H_SHIFT        (16U)                                               /*!< LPC_SCT_MATCHREL0: RELOADn_H Position   */
#define LPC_SCT_MATCHREL0_RELOADn_H(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCHREL0_RELOADn_H_SHIFT))&LPC_SCT_MATCHREL0_RELOADn_H_MASK) /*!< LPC_SCT_MATCHREL0                       */
/* ------- MATCHREL Bit Fields                      ------ */
#define LPC_SCT_MATCHREL_RELOADn_L_MASK          (0xFFFFU)                                           /*!< LPC_SCT_MATCHREL: RELOADn_L Mask        */
#define LPC_SCT_MATCHREL_RELOADn_L_SHIFT         (0U)                                                /*!< LPC_SCT_MATCHREL: RELOADn_L Position    */
#define LPC_SCT_MATCHREL_RELOADn_L(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCHREL_RELOADn_L_SHIFT))&LPC_SCT_MATCHREL_RELOADn_L_MASK) /*!< LPC_SCT_MATCHREL                        */
#define LPC_SCT_MATCHREL_RELOADn_H_MASK          (0xFFFF0000U)                                       /*!< LPC_SCT_MATCHREL: RELOADn_H Mask        */
#define LPC_SCT_MATCHREL_RELOADn_H_SHIFT         (16U)                                               /*!< LPC_SCT_MATCHREL: RELOADn_H Position    */
#define LPC_SCT_MATCHREL_RELOADn_H(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCHREL_RELOADn_H_SHIFT))&LPC_SCT_MATCHREL_RELOADn_H_MASK) /*!< LPC_SCT_MATCHREL                        */
/* ------- CAPCTRL1 Bit Fields                      ------ */
#define LPC_SCT_CAPCTRL1_CAPCONn_L_MASK          (0xFFU)                                             /*!< LPC_SCT_CAPCTRL1: CAPCONn_L Mask        */
#define LPC_SCT_CAPCTRL1_CAPCONn_L_SHIFT         (0U)                                                /*!< LPC_SCT_CAPCTRL1: CAPCONn_L Position    */
#define LPC_SCT_CAPCTRL1_CAPCONn_L(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAPCTRL1_CAPCONn_L_SHIFT))&LPC_SCT_CAPCTRL1_CAPCONn_L_MASK) /*!< LPC_SCT_CAPCTRL1                        */
#define LPC_SCT_CAPCTRL1_CAPCONn_H_MASK          (0xFF0000U)                                         /*!< LPC_SCT_CAPCTRL1: CAPCONn_H Mask        */
#define LPC_SCT_CAPCTRL1_CAPCONn_H_SHIFT         (16U)                                               /*!< LPC_SCT_CAPCTRL1: CAPCONn_H Position    */
#define LPC_SCT_CAPCTRL1_CAPCONn_H(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAPCTRL1_CAPCONn_H_SHIFT))&LPC_SCT_CAPCTRL1_CAPCONn_H_MASK) /*!< LPC_SCT_CAPCTRL1                        */
/* ------- CAPCTRL Bit Fields                       ------ */
#define LPC_SCT_CAPCTRL_CAPCONn_L_MASK           (0xFFU)                                             /*!< LPC_SCT_CAPCTRL: CAPCONn_L Mask         */
#define LPC_SCT_CAPCTRL_CAPCONn_L_SHIFT          (0U)                                                /*!< LPC_SCT_CAPCTRL: CAPCONn_L Position     */
#define LPC_SCT_CAPCTRL_CAPCONn_L(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAPCTRL_CAPCONn_L_SHIFT))&LPC_SCT_CAPCTRL_CAPCONn_L_MASK) /*!< LPC_SCT_CAPCTRL                         */
#define LPC_SCT_CAPCTRL_CAPCONn_H_MASK           (0xFF0000U)                                         /*!< LPC_SCT_CAPCTRL: CAPCONn_H Mask         */
#define LPC_SCT_CAPCTRL_CAPCONn_H_SHIFT          (16U)                                               /*!< LPC_SCT_CAPCTRL: CAPCONn_H Position     */
#define LPC_SCT_CAPCTRL_CAPCONn_H(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAPCTRL_CAPCONn_H_SHIFT))&LPC_SCT_CAPCTRL_CAPCONn_H_MASK) /*!< LPC_SCT_CAPCTRL                         */
/* ------- CAPCTRL7 Bit Fields                      ------ */
#define LPC_SCT_CAPCTRL7_CAPCONn_L_MASK          (0xFFU)                                             /*!< LPC_SCT_CAPCTRL7: CAPCONn_L Mask        */
#define LPC_SCT_CAPCTRL7_CAPCONn_L_SHIFT         (0U)                                                /*!< LPC_SCT_CAPCTRL7: CAPCONn_L Position    */
#define LPC_SCT_CAPCTRL7_CAPCONn_L(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAPCTRL7_CAPCONn_L_SHIFT))&LPC_SCT_CAPCTRL7_CAPCONn_L_MASK) /*!< LPC_SCT_CAPCTRL7                        */
#define LPC_SCT_CAPCTRL7_CAPCONn_H_MASK          (0xFF0000U)                                         /*!< LPC_SCT_CAPCTRL7: CAPCONn_H Mask        */
#define LPC_SCT_CAPCTRL7_CAPCONn_H_SHIFT         (16U)                                               /*!< LPC_SCT_CAPCTRL7: CAPCONn_H Position    */
#define LPC_SCT_CAPCTRL7_CAPCONn_H(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_CAPCTRL7_CAPCONn_H_SHIFT))&LPC_SCT_CAPCTRL7_CAPCONn_H_MASK) /*!< LPC_SCT_CAPCTRL7                        */
/* ------- MATCHREL7 Bit Fields                     ------ */
#define LPC_SCT_MATCHREL7_RELOADn_L_MASK         (0xFFFFU)                                           /*!< LPC_SCT_MATCHREL7: RELOADn_L Mask       */
#define LPC_SCT_MATCHREL7_RELOADn_L_SHIFT        (0U)                                                /*!< LPC_SCT_MATCHREL7: RELOADn_L Position   */
#define LPC_SCT_MATCHREL7_RELOADn_L(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCHREL7_RELOADn_L_SHIFT))&LPC_SCT_MATCHREL7_RELOADn_L_MASK) /*!< LPC_SCT_MATCHREL7                       */
#define LPC_SCT_MATCHREL7_RELOADn_H_MASK         (0xFFFF0000U)                                       /*!< LPC_SCT_MATCHREL7: RELOADn_H Mask       */
#define LPC_SCT_MATCHREL7_RELOADn_H_SHIFT        (16U)                                               /*!< LPC_SCT_MATCHREL7: RELOADn_H Position   */
#define LPC_SCT_MATCHREL7_RELOADn_H(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_MATCHREL7_RELOADn_H_SHIFT))&LPC_SCT_MATCHREL7_RELOADn_H_MASK) /*!< LPC_SCT_MATCHREL7                       */
/* ------- EV0_STATE Bit Fields                     ------ */
#define LPC_SCT_EV0_STATE_STATEMSKn_MASK         (0xFFU)                                             /*!< LPC_SCT_EV0_STATE: STATEMSKn Mask       */
#define LPC_SCT_EV0_STATE_STATEMSKn_SHIFT        (0U)                                                /*!< LPC_SCT_EV0_STATE: STATEMSKn Position   */
#define LPC_SCT_EV0_STATE_STATEMSKn(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_STATE_STATEMSKn_SHIFT))&LPC_SCT_EV0_STATE_STATEMSKn_MASK) /*!< LPC_SCT_EV0_STATE                       */
/* ------- EV0_CTRL Bit Fields                      ------ */
#define LPC_SCT_EV0_CTRL_MATCHSEL_MASK           (0xFU)                                              /*!< LPC_SCT_EV0_CTRL: MATCHSEL Mask         */
#define LPC_SCT_EV0_CTRL_MATCHSEL_SHIFT          (0U)                                                /*!< LPC_SCT_EV0_CTRL: MATCHSEL Position     */
#define LPC_SCT_EV0_CTRL_MATCHSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_MATCHSEL_SHIFT))&LPC_SCT_EV0_CTRL_MATCHSEL_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_HEVENT_MASK             (0x10U)                                             /*!< LPC_SCT_EV0_CTRL: HEVENT Mask           */
#define LPC_SCT_EV0_CTRL_HEVENT_SHIFT            (4U)                                                /*!< LPC_SCT_EV0_CTRL: HEVENT Position       */
#define LPC_SCT_EV0_CTRL_HEVENT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_HEVENT_SHIFT))&LPC_SCT_EV0_CTRL_HEVENT_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_OUTSEL_MASK             (0x20U)                                             /*!< LPC_SCT_EV0_CTRL: OUTSEL Mask           */
#define LPC_SCT_EV0_CTRL_OUTSEL_SHIFT            (5U)                                                /*!< LPC_SCT_EV0_CTRL: OUTSEL Position       */
#define LPC_SCT_EV0_CTRL_OUTSEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_OUTSEL_SHIFT))&LPC_SCT_EV0_CTRL_OUTSEL_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_IOSEL_MASK              (0x3C0U)                                            /*!< LPC_SCT_EV0_CTRL: IOSEL Mask            */
#define LPC_SCT_EV0_CTRL_IOSEL_SHIFT             (6U)                                                /*!< LPC_SCT_EV0_CTRL: IOSEL Position        */
#define LPC_SCT_EV0_CTRL_IOSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_IOSEL_SHIFT))&LPC_SCT_EV0_CTRL_IOSEL_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_IOCOND_MASK             (0xC00U)                                            /*!< LPC_SCT_EV0_CTRL: IOCOND Mask           */
#define LPC_SCT_EV0_CTRL_IOCOND_SHIFT            (10U)                                               /*!< LPC_SCT_EV0_CTRL: IOCOND Position       */
#define LPC_SCT_EV0_CTRL_IOCOND(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_IOCOND_SHIFT))&LPC_SCT_EV0_CTRL_IOCOND_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_COMBMODE_MASK           (0x3000U)                                           /*!< LPC_SCT_EV0_CTRL: COMBMODE Mask         */
#define LPC_SCT_EV0_CTRL_COMBMODE_SHIFT          (12U)                                               /*!< LPC_SCT_EV0_CTRL: COMBMODE Position     */
#define LPC_SCT_EV0_CTRL_COMBMODE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_COMBMODE_SHIFT))&LPC_SCT_EV0_CTRL_COMBMODE_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_STATELD_MASK            (0x4000U)                                           /*!< LPC_SCT_EV0_CTRL: STATELD Mask          */
#define LPC_SCT_EV0_CTRL_STATELD_SHIFT           (14U)                                               /*!< LPC_SCT_EV0_CTRL: STATELD Position      */
#define LPC_SCT_EV0_CTRL_STATELD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_STATELD_SHIFT))&LPC_SCT_EV0_CTRL_STATELD_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_STATEV_MASK             (0xF8000U)                                          /*!< LPC_SCT_EV0_CTRL: STATEV Mask           */
#define LPC_SCT_EV0_CTRL_STATEV_SHIFT            (15U)                                               /*!< LPC_SCT_EV0_CTRL: STATEV Position       */
#define LPC_SCT_EV0_CTRL_STATEV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_STATEV_SHIFT))&LPC_SCT_EV0_CTRL_STATEV_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_MATCHMEM_MASK           (0x100000U)                                         /*!< LPC_SCT_EV0_CTRL: MATCHMEM Mask         */
#define LPC_SCT_EV0_CTRL_MATCHMEM_SHIFT          (20U)                                               /*!< LPC_SCT_EV0_CTRL: MATCHMEM Position     */
#define LPC_SCT_EV0_CTRL_MATCHMEM(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_MATCHMEM_SHIFT))&LPC_SCT_EV0_CTRL_MATCHMEM_MASK) /*!< LPC_SCT_EV0_CTRL                        */
#define LPC_SCT_EV0_CTRL_DIRECTION_MASK          (0x600000U)                                         /*!< LPC_SCT_EV0_CTRL: DIRECTION Mask        */
#define LPC_SCT_EV0_CTRL_DIRECTION_SHIFT         (21U)                                               /*!< LPC_SCT_EV0_CTRL: DIRECTION Position    */
#define LPC_SCT_EV0_CTRL_DIRECTION(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV0_CTRL_DIRECTION_SHIFT))&LPC_SCT_EV0_CTRL_DIRECTION_MASK) /*!< LPC_SCT_EV0_CTRL                        */
/* ------- EV1_STATE Bit Fields                     ------ */
#define LPC_SCT_EV1_STATE_STATEMSKn_MASK         (0xFFU)                                             /*!< LPC_SCT_EV1_STATE: STATEMSKn Mask       */
#define LPC_SCT_EV1_STATE_STATEMSKn_SHIFT        (0U)                                                /*!< LPC_SCT_EV1_STATE: STATEMSKn Position   */
#define LPC_SCT_EV1_STATE_STATEMSKn(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_STATE_STATEMSKn_SHIFT))&LPC_SCT_EV1_STATE_STATEMSKn_MASK) /*!< LPC_SCT_EV1_STATE                       */
/* ------- EV1_CTRL Bit Fields                      ------ */
#define LPC_SCT_EV1_CTRL_MATCHSEL_MASK           (0xFU)                                              /*!< LPC_SCT_EV1_CTRL: MATCHSEL Mask         */
#define LPC_SCT_EV1_CTRL_MATCHSEL_SHIFT          (0U)                                                /*!< LPC_SCT_EV1_CTRL: MATCHSEL Position     */
#define LPC_SCT_EV1_CTRL_MATCHSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_MATCHSEL_SHIFT))&LPC_SCT_EV1_CTRL_MATCHSEL_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_HEVENT_MASK             (0x10U)                                             /*!< LPC_SCT_EV1_CTRL: HEVENT Mask           */
#define LPC_SCT_EV1_CTRL_HEVENT_SHIFT            (4U)                                                /*!< LPC_SCT_EV1_CTRL: HEVENT Position       */
#define LPC_SCT_EV1_CTRL_HEVENT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_HEVENT_SHIFT))&LPC_SCT_EV1_CTRL_HEVENT_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_OUTSEL_MASK             (0x20U)                                             /*!< LPC_SCT_EV1_CTRL: OUTSEL Mask           */
#define LPC_SCT_EV1_CTRL_OUTSEL_SHIFT            (5U)                                                /*!< LPC_SCT_EV1_CTRL: OUTSEL Position       */
#define LPC_SCT_EV1_CTRL_OUTSEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_OUTSEL_SHIFT))&LPC_SCT_EV1_CTRL_OUTSEL_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_IOSEL_MASK              (0x3C0U)                                            /*!< LPC_SCT_EV1_CTRL: IOSEL Mask            */
#define LPC_SCT_EV1_CTRL_IOSEL_SHIFT             (6U)                                                /*!< LPC_SCT_EV1_CTRL: IOSEL Position        */
#define LPC_SCT_EV1_CTRL_IOSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_IOSEL_SHIFT))&LPC_SCT_EV1_CTRL_IOSEL_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_IOCOND_MASK             (0xC00U)                                            /*!< LPC_SCT_EV1_CTRL: IOCOND Mask           */
#define LPC_SCT_EV1_CTRL_IOCOND_SHIFT            (10U)                                               /*!< LPC_SCT_EV1_CTRL: IOCOND Position       */
#define LPC_SCT_EV1_CTRL_IOCOND(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_IOCOND_SHIFT))&LPC_SCT_EV1_CTRL_IOCOND_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_COMBMODE_MASK           (0x3000U)                                           /*!< LPC_SCT_EV1_CTRL: COMBMODE Mask         */
#define LPC_SCT_EV1_CTRL_COMBMODE_SHIFT          (12U)                                               /*!< LPC_SCT_EV1_CTRL: COMBMODE Position     */
#define LPC_SCT_EV1_CTRL_COMBMODE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_COMBMODE_SHIFT))&LPC_SCT_EV1_CTRL_COMBMODE_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_STATELD_MASK            (0x4000U)                                           /*!< LPC_SCT_EV1_CTRL: STATELD Mask          */
#define LPC_SCT_EV1_CTRL_STATELD_SHIFT           (14U)                                               /*!< LPC_SCT_EV1_CTRL: STATELD Position      */
#define LPC_SCT_EV1_CTRL_STATELD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_STATELD_SHIFT))&LPC_SCT_EV1_CTRL_STATELD_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_STATEV_MASK             (0xF8000U)                                          /*!< LPC_SCT_EV1_CTRL: STATEV Mask           */
#define LPC_SCT_EV1_CTRL_STATEV_SHIFT            (15U)                                               /*!< LPC_SCT_EV1_CTRL: STATEV Position       */
#define LPC_SCT_EV1_CTRL_STATEV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_STATEV_SHIFT))&LPC_SCT_EV1_CTRL_STATEV_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_MATCHMEM_MASK           (0x100000U)                                         /*!< LPC_SCT_EV1_CTRL: MATCHMEM Mask         */
#define LPC_SCT_EV1_CTRL_MATCHMEM_SHIFT          (20U)                                               /*!< LPC_SCT_EV1_CTRL: MATCHMEM Position     */
#define LPC_SCT_EV1_CTRL_MATCHMEM(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_MATCHMEM_SHIFT))&LPC_SCT_EV1_CTRL_MATCHMEM_MASK) /*!< LPC_SCT_EV1_CTRL                        */
#define LPC_SCT_EV1_CTRL_DIRECTION_MASK          (0x600000U)                                         /*!< LPC_SCT_EV1_CTRL: DIRECTION Mask        */
#define LPC_SCT_EV1_CTRL_DIRECTION_SHIFT         (21U)                                               /*!< LPC_SCT_EV1_CTRL: DIRECTION Position    */
#define LPC_SCT_EV1_CTRL_DIRECTION(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV1_CTRL_DIRECTION_SHIFT))&LPC_SCT_EV1_CTRL_DIRECTION_MASK) /*!< LPC_SCT_EV1_CTRL                        */
/* ------- EV2_STATE Bit Fields                     ------ */
#define LPC_SCT_EV2_STATE_STATEMSKn_MASK         (0xFFU)                                             /*!< LPC_SCT_EV2_STATE: STATEMSKn Mask       */
#define LPC_SCT_EV2_STATE_STATEMSKn_SHIFT        (0U)                                                /*!< LPC_SCT_EV2_STATE: STATEMSKn Position   */
#define LPC_SCT_EV2_STATE_STATEMSKn(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_STATE_STATEMSKn_SHIFT))&LPC_SCT_EV2_STATE_STATEMSKn_MASK) /*!< LPC_SCT_EV2_STATE                       */
/* ------- EV2_CTRL Bit Fields                      ------ */
#define LPC_SCT_EV2_CTRL_MATCHSEL_MASK           (0xFU)                                              /*!< LPC_SCT_EV2_CTRL: MATCHSEL Mask         */
#define LPC_SCT_EV2_CTRL_MATCHSEL_SHIFT          (0U)                                                /*!< LPC_SCT_EV2_CTRL: MATCHSEL Position     */
#define LPC_SCT_EV2_CTRL_MATCHSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_MATCHSEL_SHIFT))&LPC_SCT_EV2_CTRL_MATCHSEL_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_HEVENT_MASK             (0x10U)                                             /*!< LPC_SCT_EV2_CTRL: HEVENT Mask           */
#define LPC_SCT_EV2_CTRL_HEVENT_SHIFT            (4U)                                                /*!< LPC_SCT_EV2_CTRL: HEVENT Position       */
#define LPC_SCT_EV2_CTRL_HEVENT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_HEVENT_SHIFT))&LPC_SCT_EV2_CTRL_HEVENT_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_OUTSEL_MASK             (0x20U)                                             /*!< LPC_SCT_EV2_CTRL: OUTSEL Mask           */
#define LPC_SCT_EV2_CTRL_OUTSEL_SHIFT            (5U)                                                /*!< LPC_SCT_EV2_CTRL: OUTSEL Position       */
#define LPC_SCT_EV2_CTRL_OUTSEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_OUTSEL_SHIFT))&LPC_SCT_EV2_CTRL_OUTSEL_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_IOSEL_MASK              (0x3C0U)                                            /*!< LPC_SCT_EV2_CTRL: IOSEL Mask            */
#define LPC_SCT_EV2_CTRL_IOSEL_SHIFT             (6U)                                                /*!< LPC_SCT_EV2_CTRL: IOSEL Position        */
#define LPC_SCT_EV2_CTRL_IOSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_IOSEL_SHIFT))&LPC_SCT_EV2_CTRL_IOSEL_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_IOCOND_MASK             (0xC00U)                                            /*!< LPC_SCT_EV2_CTRL: IOCOND Mask           */
#define LPC_SCT_EV2_CTRL_IOCOND_SHIFT            (10U)                                               /*!< LPC_SCT_EV2_CTRL: IOCOND Position       */
#define LPC_SCT_EV2_CTRL_IOCOND(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_IOCOND_SHIFT))&LPC_SCT_EV2_CTRL_IOCOND_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_COMBMODE_MASK           (0x3000U)                                           /*!< LPC_SCT_EV2_CTRL: COMBMODE Mask         */
#define LPC_SCT_EV2_CTRL_COMBMODE_SHIFT          (12U)                                               /*!< LPC_SCT_EV2_CTRL: COMBMODE Position     */
#define LPC_SCT_EV2_CTRL_COMBMODE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_COMBMODE_SHIFT))&LPC_SCT_EV2_CTRL_COMBMODE_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_STATELD_MASK            (0x4000U)                                           /*!< LPC_SCT_EV2_CTRL: STATELD Mask          */
#define LPC_SCT_EV2_CTRL_STATELD_SHIFT           (14U)                                               /*!< LPC_SCT_EV2_CTRL: STATELD Position      */
#define LPC_SCT_EV2_CTRL_STATELD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_STATELD_SHIFT))&LPC_SCT_EV2_CTRL_STATELD_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_STATEV_MASK             (0xF8000U)                                          /*!< LPC_SCT_EV2_CTRL: STATEV Mask           */
#define LPC_SCT_EV2_CTRL_STATEV_SHIFT            (15U)                                               /*!< LPC_SCT_EV2_CTRL: STATEV Position       */
#define LPC_SCT_EV2_CTRL_STATEV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_STATEV_SHIFT))&LPC_SCT_EV2_CTRL_STATEV_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_MATCHMEM_MASK           (0x100000U)                                         /*!< LPC_SCT_EV2_CTRL: MATCHMEM Mask         */
#define LPC_SCT_EV2_CTRL_MATCHMEM_SHIFT          (20U)                                               /*!< LPC_SCT_EV2_CTRL: MATCHMEM Position     */
#define LPC_SCT_EV2_CTRL_MATCHMEM(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_MATCHMEM_SHIFT))&LPC_SCT_EV2_CTRL_MATCHMEM_MASK) /*!< LPC_SCT_EV2_CTRL                        */
#define LPC_SCT_EV2_CTRL_DIRECTION_MASK          (0x600000U)                                         /*!< LPC_SCT_EV2_CTRL: DIRECTION Mask        */
#define LPC_SCT_EV2_CTRL_DIRECTION_SHIFT         (21U)                                               /*!< LPC_SCT_EV2_CTRL: DIRECTION Position    */
#define LPC_SCT_EV2_CTRL_DIRECTION(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV2_CTRL_DIRECTION_SHIFT))&LPC_SCT_EV2_CTRL_DIRECTION_MASK) /*!< LPC_SCT_EV2_CTRL                        */
/* ------- EV3_STATE Bit Fields                     ------ */
#define LPC_SCT_EV3_STATE_STATEMSKn_MASK         (0xFFU)                                             /*!< LPC_SCT_EV3_STATE: STATEMSKn Mask       */
#define LPC_SCT_EV3_STATE_STATEMSKn_SHIFT        (0U)                                                /*!< LPC_SCT_EV3_STATE: STATEMSKn Position   */
#define LPC_SCT_EV3_STATE_STATEMSKn(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_STATE_STATEMSKn_SHIFT))&LPC_SCT_EV3_STATE_STATEMSKn_MASK) /*!< LPC_SCT_EV3_STATE                       */
/* ------- EV3_CTRL Bit Fields                      ------ */
#define LPC_SCT_EV3_CTRL_MATCHSEL_MASK           (0xFU)                                              /*!< LPC_SCT_EV3_CTRL: MATCHSEL Mask         */
#define LPC_SCT_EV3_CTRL_MATCHSEL_SHIFT          (0U)                                                /*!< LPC_SCT_EV3_CTRL: MATCHSEL Position     */
#define LPC_SCT_EV3_CTRL_MATCHSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_MATCHSEL_SHIFT))&LPC_SCT_EV3_CTRL_MATCHSEL_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_HEVENT_MASK             (0x10U)                                             /*!< LPC_SCT_EV3_CTRL: HEVENT Mask           */
#define LPC_SCT_EV3_CTRL_HEVENT_SHIFT            (4U)                                                /*!< LPC_SCT_EV3_CTRL: HEVENT Position       */
#define LPC_SCT_EV3_CTRL_HEVENT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_HEVENT_SHIFT))&LPC_SCT_EV3_CTRL_HEVENT_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_OUTSEL_MASK             (0x20U)                                             /*!< LPC_SCT_EV3_CTRL: OUTSEL Mask           */
#define LPC_SCT_EV3_CTRL_OUTSEL_SHIFT            (5U)                                                /*!< LPC_SCT_EV3_CTRL: OUTSEL Position       */
#define LPC_SCT_EV3_CTRL_OUTSEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_OUTSEL_SHIFT))&LPC_SCT_EV3_CTRL_OUTSEL_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_IOSEL_MASK              (0x3C0U)                                            /*!< LPC_SCT_EV3_CTRL: IOSEL Mask            */
#define LPC_SCT_EV3_CTRL_IOSEL_SHIFT             (6U)                                                /*!< LPC_SCT_EV3_CTRL: IOSEL Position        */
#define LPC_SCT_EV3_CTRL_IOSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_IOSEL_SHIFT))&LPC_SCT_EV3_CTRL_IOSEL_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_IOCOND_MASK             (0xC00U)                                            /*!< LPC_SCT_EV3_CTRL: IOCOND Mask           */
#define LPC_SCT_EV3_CTRL_IOCOND_SHIFT            (10U)                                               /*!< LPC_SCT_EV3_CTRL: IOCOND Position       */
#define LPC_SCT_EV3_CTRL_IOCOND(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_IOCOND_SHIFT))&LPC_SCT_EV3_CTRL_IOCOND_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_COMBMODE_MASK           (0x3000U)                                           /*!< LPC_SCT_EV3_CTRL: COMBMODE Mask         */
#define LPC_SCT_EV3_CTRL_COMBMODE_SHIFT          (12U)                                               /*!< LPC_SCT_EV3_CTRL: COMBMODE Position     */
#define LPC_SCT_EV3_CTRL_COMBMODE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_COMBMODE_SHIFT))&LPC_SCT_EV3_CTRL_COMBMODE_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_STATELD_MASK            (0x4000U)                                           /*!< LPC_SCT_EV3_CTRL: STATELD Mask          */
#define LPC_SCT_EV3_CTRL_STATELD_SHIFT           (14U)                                               /*!< LPC_SCT_EV3_CTRL: STATELD Position      */
#define LPC_SCT_EV3_CTRL_STATELD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_STATELD_SHIFT))&LPC_SCT_EV3_CTRL_STATELD_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_STATEV_MASK             (0xF8000U)                                          /*!< LPC_SCT_EV3_CTRL: STATEV Mask           */
#define LPC_SCT_EV3_CTRL_STATEV_SHIFT            (15U)                                               /*!< LPC_SCT_EV3_CTRL: STATEV Position       */
#define LPC_SCT_EV3_CTRL_STATEV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_STATEV_SHIFT))&LPC_SCT_EV3_CTRL_STATEV_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_MATCHMEM_MASK           (0x100000U)                                         /*!< LPC_SCT_EV3_CTRL: MATCHMEM Mask         */
#define LPC_SCT_EV3_CTRL_MATCHMEM_SHIFT          (20U)                                               /*!< LPC_SCT_EV3_CTRL: MATCHMEM Position     */
#define LPC_SCT_EV3_CTRL_MATCHMEM(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_MATCHMEM_SHIFT))&LPC_SCT_EV3_CTRL_MATCHMEM_MASK) /*!< LPC_SCT_EV3_CTRL                        */
#define LPC_SCT_EV3_CTRL_DIRECTION_MASK          (0x600000U)                                         /*!< LPC_SCT_EV3_CTRL: DIRECTION Mask        */
#define LPC_SCT_EV3_CTRL_DIRECTION_SHIFT         (21U)                                               /*!< LPC_SCT_EV3_CTRL: DIRECTION Position    */
#define LPC_SCT_EV3_CTRL_DIRECTION(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV3_CTRL_DIRECTION_SHIFT))&LPC_SCT_EV3_CTRL_DIRECTION_MASK) /*!< LPC_SCT_EV3_CTRL                        */
/* ------- EV4_STATE Bit Fields                     ------ */
#define LPC_SCT_EV4_STATE_STATEMSKn_MASK         (0xFFU)                                             /*!< LPC_SCT_EV4_STATE: STATEMSKn Mask       */
#define LPC_SCT_EV4_STATE_STATEMSKn_SHIFT        (0U)                                                /*!< LPC_SCT_EV4_STATE: STATEMSKn Position   */
#define LPC_SCT_EV4_STATE_STATEMSKn(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_STATE_STATEMSKn_SHIFT))&LPC_SCT_EV4_STATE_STATEMSKn_MASK) /*!< LPC_SCT_EV4_STATE                       */
/* ------- EV4_CTRL Bit Fields                      ------ */
#define LPC_SCT_EV4_CTRL_MATCHSEL_MASK           (0xFU)                                              /*!< LPC_SCT_EV4_CTRL: MATCHSEL Mask         */
#define LPC_SCT_EV4_CTRL_MATCHSEL_SHIFT          (0U)                                                /*!< LPC_SCT_EV4_CTRL: MATCHSEL Position     */
#define LPC_SCT_EV4_CTRL_MATCHSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_MATCHSEL_SHIFT))&LPC_SCT_EV4_CTRL_MATCHSEL_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_HEVENT_MASK             (0x10U)                                             /*!< LPC_SCT_EV4_CTRL: HEVENT Mask           */
#define LPC_SCT_EV4_CTRL_HEVENT_SHIFT            (4U)                                                /*!< LPC_SCT_EV4_CTRL: HEVENT Position       */
#define LPC_SCT_EV4_CTRL_HEVENT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_HEVENT_SHIFT))&LPC_SCT_EV4_CTRL_HEVENT_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_OUTSEL_MASK             (0x20U)                                             /*!< LPC_SCT_EV4_CTRL: OUTSEL Mask           */
#define LPC_SCT_EV4_CTRL_OUTSEL_SHIFT            (5U)                                                /*!< LPC_SCT_EV4_CTRL: OUTSEL Position       */
#define LPC_SCT_EV4_CTRL_OUTSEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_OUTSEL_SHIFT))&LPC_SCT_EV4_CTRL_OUTSEL_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_IOSEL_MASK              (0x3C0U)                                            /*!< LPC_SCT_EV4_CTRL: IOSEL Mask            */
#define LPC_SCT_EV4_CTRL_IOSEL_SHIFT             (6U)                                                /*!< LPC_SCT_EV4_CTRL: IOSEL Position        */
#define LPC_SCT_EV4_CTRL_IOSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_IOSEL_SHIFT))&LPC_SCT_EV4_CTRL_IOSEL_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_IOCOND_MASK             (0xC00U)                                            /*!< LPC_SCT_EV4_CTRL: IOCOND Mask           */
#define LPC_SCT_EV4_CTRL_IOCOND_SHIFT            (10U)                                               /*!< LPC_SCT_EV4_CTRL: IOCOND Position       */
#define LPC_SCT_EV4_CTRL_IOCOND(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_IOCOND_SHIFT))&LPC_SCT_EV4_CTRL_IOCOND_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_COMBMODE_MASK           (0x3000U)                                           /*!< LPC_SCT_EV4_CTRL: COMBMODE Mask         */
#define LPC_SCT_EV4_CTRL_COMBMODE_SHIFT          (12U)                                               /*!< LPC_SCT_EV4_CTRL: COMBMODE Position     */
#define LPC_SCT_EV4_CTRL_COMBMODE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_COMBMODE_SHIFT))&LPC_SCT_EV4_CTRL_COMBMODE_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_STATELD_MASK            (0x4000U)                                           /*!< LPC_SCT_EV4_CTRL: STATELD Mask          */
#define LPC_SCT_EV4_CTRL_STATELD_SHIFT           (14U)                                               /*!< LPC_SCT_EV4_CTRL: STATELD Position      */
#define LPC_SCT_EV4_CTRL_STATELD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_STATELD_SHIFT))&LPC_SCT_EV4_CTRL_STATELD_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_STATEV_MASK             (0xF8000U)                                          /*!< LPC_SCT_EV4_CTRL: STATEV Mask           */
#define LPC_SCT_EV4_CTRL_STATEV_SHIFT            (15U)                                               /*!< LPC_SCT_EV4_CTRL: STATEV Position       */
#define LPC_SCT_EV4_CTRL_STATEV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_STATEV_SHIFT))&LPC_SCT_EV4_CTRL_STATEV_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_MATCHMEM_MASK           (0x100000U)                                         /*!< LPC_SCT_EV4_CTRL: MATCHMEM Mask         */
#define LPC_SCT_EV4_CTRL_MATCHMEM_SHIFT          (20U)                                               /*!< LPC_SCT_EV4_CTRL: MATCHMEM Position     */
#define LPC_SCT_EV4_CTRL_MATCHMEM(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_MATCHMEM_SHIFT))&LPC_SCT_EV4_CTRL_MATCHMEM_MASK) /*!< LPC_SCT_EV4_CTRL                        */
#define LPC_SCT_EV4_CTRL_DIRECTION_MASK          (0x600000U)                                         /*!< LPC_SCT_EV4_CTRL: DIRECTION Mask        */
#define LPC_SCT_EV4_CTRL_DIRECTION_SHIFT         (21U)                                               /*!< LPC_SCT_EV4_CTRL: DIRECTION Position    */
#define LPC_SCT_EV4_CTRL_DIRECTION(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV4_CTRL_DIRECTION_SHIFT))&LPC_SCT_EV4_CTRL_DIRECTION_MASK) /*!< LPC_SCT_EV4_CTRL                        */
/* ------- EV5_STATE Bit Fields                     ------ */
#define LPC_SCT_EV5_STATE_STATEMSKn_MASK         (0xFFU)                                             /*!< LPC_SCT_EV5_STATE: STATEMSKn Mask       */
#define LPC_SCT_EV5_STATE_STATEMSKn_SHIFT        (0U)                                                /*!< LPC_SCT_EV5_STATE: STATEMSKn Position   */
#define LPC_SCT_EV5_STATE_STATEMSKn(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_STATE_STATEMSKn_SHIFT))&LPC_SCT_EV5_STATE_STATEMSKn_MASK) /*!< LPC_SCT_EV5_STATE                       */
/* ------- EV5_CTRL Bit Fields                      ------ */
#define LPC_SCT_EV5_CTRL_MATCHSEL_MASK           (0xFU)                                              /*!< LPC_SCT_EV5_CTRL: MATCHSEL Mask         */
#define LPC_SCT_EV5_CTRL_MATCHSEL_SHIFT          (0U)                                                /*!< LPC_SCT_EV5_CTRL: MATCHSEL Position     */
#define LPC_SCT_EV5_CTRL_MATCHSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_MATCHSEL_SHIFT))&LPC_SCT_EV5_CTRL_MATCHSEL_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_HEVENT_MASK             (0x10U)                                             /*!< LPC_SCT_EV5_CTRL: HEVENT Mask           */
#define LPC_SCT_EV5_CTRL_HEVENT_SHIFT            (4U)                                                /*!< LPC_SCT_EV5_CTRL: HEVENT Position       */
#define LPC_SCT_EV5_CTRL_HEVENT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_HEVENT_SHIFT))&LPC_SCT_EV5_CTRL_HEVENT_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_OUTSEL_MASK             (0x20U)                                             /*!< LPC_SCT_EV5_CTRL: OUTSEL Mask           */
#define LPC_SCT_EV5_CTRL_OUTSEL_SHIFT            (5U)                                                /*!< LPC_SCT_EV5_CTRL: OUTSEL Position       */
#define LPC_SCT_EV5_CTRL_OUTSEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_OUTSEL_SHIFT))&LPC_SCT_EV5_CTRL_OUTSEL_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_IOSEL_MASK              (0x3C0U)                                            /*!< LPC_SCT_EV5_CTRL: IOSEL Mask            */
#define LPC_SCT_EV5_CTRL_IOSEL_SHIFT             (6U)                                                /*!< LPC_SCT_EV5_CTRL: IOSEL Position        */
#define LPC_SCT_EV5_CTRL_IOSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_IOSEL_SHIFT))&LPC_SCT_EV5_CTRL_IOSEL_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_IOCOND_MASK             (0xC00U)                                            /*!< LPC_SCT_EV5_CTRL: IOCOND Mask           */
#define LPC_SCT_EV5_CTRL_IOCOND_SHIFT            (10U)                                               /*!< LPC_SCT_EV5_CTRL: IOCOND Position       */
#define LPC_SCT_EV5_CTRL_IOCOND(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_IOCOND_SHIFT))&LPC_SCT_EV5_CTRL_IOCOND_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_COMBMODE_MASK           (0x3000U)                                           /*!< LPC_SCT_EV5_CTRL: COMBMODE Mask         */
#define LPC_SCT_EV5_CTRL_COMBMODE_SHIFT          (12U)                                               /*!< LPC_SCT_EV5_CTRL: COMBMODE Position     */
#define LPC_SCT_EV5_CTRL_COMBMODE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_COMBMODE_SHIFT))&LPC_SCT_EV5_CTRL_COMBMODE_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_STATELD_MASK            (0x4000U)                                           /*!< LPC_SCT_EV5_CTRL: STATELD Mask          */
#define LPC_SCT_EV5_CTRL_STATELD_SHIFT           (14U)                                               /*!< LPC_SCT_EV5_CTRL: STATELD Position      */
#define LPC_SCT_EV5_CTRL_STATELD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_STATELD_SHIFT))&LPC_SCT_EV5_CTRL_STATELD_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_STATEV_MASK             (0xF8000U)                                          /*!< LPC_SCT_EV5_CTRL: STATEV Mask           */
#define LPC_SCT_EV5_CTRL_STATEV_SHIFT            (15U)                                               /*!< LPC_SCT_EV5_CTRL: STATEV Position       */
#define LPC_SCT_EV5_CTRL_STATEV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_STATEV_SHIFT))&LPC_SCT_EV5_CTRL_STATEV_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_MATCHMEM_MASK           (0x100000U)                                         /*!< LPC_SCT_EV5_CTRL: MATCHMEM Mask         */
#define LPC_SCT_EV5_CTRL_MATCHMEM_SHIFT          (20U)                                               /*!< LPC_SCT_EV5_CTRL: MATCHMEM Position     */
#define LPC_SCT_EV5_CTRL_MATCHMEM(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_MATCHMEM_SHIFT))&LPC_SCT_EV5_CTRL_MATCHMEM_MASK) /*!< LPC_SCT_EV5_CTRL                        */
#define LPC_SCT_EV5_CTRL_DIRECTION_MASK          (0x600000U)                                         /*!< LPC_SCT_EV5_CTRL: DIRECTION Mask        */
#define LPC_SCT_EV5_CTRL_DIRECTION_SHIFT         (21U)                                               /*!< LPC_SCT_EV5_CTRL: DIRECTION Position    */
#define LPC_SCT_EV5_CTRL_DIRECTION(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV5_CTRL_DIRECTION_SHIFT))&LPC_SCT_EV5_CTRL_DIRECTION_MASK) /*!< LPC_SCT_EV5_CTRL                        */
/* ------- EV6_STATE Bit Fields                     ------ */
#define LPC_SCT_EV6_STATE_STATEMSKn_MASK         (0xFFU)                                             /*!< LPC_SCT_EV6_STATE: STATEMSKn Mask       */
#define LPC_SCT_EV6_STATE_STATEMSKn_SHIFT        (0U)                                                /*!< LPC_SCT_EV6_STATE: STATEMSKn Position   */
#define LPC_SCT_EV6_STATE_STATEMSKn(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_STATE_STATEMSKn_SHIFT))&LPC_SCT_EV6_STATE_STATEMSKn_MASK) /*!< LPC_SCT_EV6_STATE                       */
/* ------- EV6_CTRL Bit Fields                      ------ */
#define LPC_SCT_EV6_CTRL_MATCHSEL_MASK           (0xFU)                                              /*!< LPC_SCT_EV6_CTRL: MATCHSEL Mask         */
#define LPC_SCT_EV6_CTRL_MATCHSEL_SHIFT          (0U)                                                /*!< LPC_SCT_EV6_CTRL: MATCHSEL Position     */
#define LPC_SCT_EV6_CTRL_MATCHSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_MATCHSEL_SHIFT))&LPC_SCT_EV6_CTRL_MATCHSEL_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_HEVENT_MASK             (0x10U)                                             /*!< LPC_SCT_EV6_CTRL: HEVENT Mask           */
#define LPC_SCT_EV6_CTRL_HEVENT_SHIFT            (4U)                                                /*!< LPC_SCT_EV6_CTRL: HEVENT Position       */
#define LPC_SCT_EV6_CTRL_HEVENT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_HEVENT_SHIFT))&LPC_SCT_EV6_CTRL_HEVENT_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_OUTSEL_MASK             (0x20U)                                             /*!< LPC_SCT_EV6_CTRL: OUTSEL Mask           */
#define LPC_SCT_EV6_CTRL_OUTSEL_SHIFT            (5U)                                                /*!< LPC_SCT_EV6_CTRL: OUTSEL Position       */
#define LPC_SCT_EV6_CTRL_OUTSEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_OUTSEL_SHIFT))&LPC_SCT_EV6_CTRL_OUTSEL_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_IOSEL_MASK              (0x3C0U)                                            /*!< LPC_SCT_EV6_CTRL: IOSEL Mask            */
#define LPC_SCT_EV6_CTRL_IOSEL_SHIFT             (6U)                                                /*!< LPC_SCT_EV6_CTRL: IOSEL Position        */
#define LPC_SCT_EV6_CTRL_IOSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_IOSEL_SHIFT))&LPC_SCT_EV6_CTRL_IOSEL_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_IOCOND_MASK             (0xC00U)                                            /*!< LPC_SCT_EV6_CTRL: IOCOND Mask           */
#define LPC_SCT_EV6_CTRL_IOCOND_SHIFT            (10U)                                               /*!< LPC_SCT_EV6_CTRL: IOCOND Position       */
#define LPC_SCT_EV6_CTRL_IOCOND(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_IOCOND_SHIFT))&LPC_SCT_EV6_CTRL_IOCOND_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_COMBMODE_MASK           (0x3000U)                                           /*!< LPC_SCT_EV6_CTRL: COMBMODE Mask         */
#define LPC_SCT_EV6_CTRL_COMBMODE_SHIFT          (12U)                                               /*!< LPC_SCT_EV6_CTRL: COMBMODE Position     */
#define LPC_SCT_EV6_CTRL_COMBMODE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_COMBMODE_SHIFT))&LPC_SCT_EV6_CTRL_COMBMODE_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_STATELD_MASK            (0x4000U)                                           /*!< LPC_SCT_EV6_CTRL: STATELD Mask          */
#define LPC_SCT_EV6_CTRL_STATELD_SHIFT           (14U)                                               /*!< LPC_SCT_EV6_CTRL: STATELD Position      */
#define LPC_SCT_EV6_CTRL_STATELD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_STATELD_SHIFT))&LPC_SCT_EV6_CTRL_STATELD_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_STATEV_MASK             (0xF8000U)                                          /*!< LPC_SCT_EV6_CTRL: STATEV Mask           */
#define LPC_SCT_EV6_CTRL_STATEV_SHIFT            (15U)                                               /*!< LPC_SCT_EV6_CTRL: STATEV Position       */
#define LPC_SCT_EV6_CTRL_STATEV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_STATEV_SHIFT))&LPC_SCT_EV6_CTRL_STATEV_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_MATCHMEM_MASK           (0x100000U)                                         /*!< LPC_SCT_EV6_CTRL: MATCHMEM Mask         */
#define LPC_SCT_EV6_CTRL_MATCHMEM_SHIFT          (20U)                                               /*!< LPC_SCT_EV6_CTRL: MATCHMEM Position     */
#define LPC_SCT_EV6_CTRL_MATCHMEM(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_MATCHMEM_SHIFT))&LPC_SCT_EV6_CTRL_MATCHMEM_MASK) /*!< LPC_SCT_EV6_CTRL                        */
#define LPC_SCT_EV6_CTRL_DIRECTION_MASK          (0x600000U)                                         /*!< LPC_SCT_EV6_CTRL: DIRECTION Mask        */
#define LPC_SCT_EV6_CTRL_DIRECTION_SHIFT         (21U)                                               /*!< LPC_SCT_EV6_CTRL: DIRECTION Position    */
#define LPC_SCT_EV6_CTRL_DIRECTION(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV6_CTRL_DIRECTION_SHIFT))&LPC_SCT_EV6_CTRL_DIRECTION_MASK) /*!< LPC_SCT_EV6_CTRL                        */
/* ------- EV7_STATE Bit Fields                     ------ */
#define LPC_SCT_EV7_STATE_STATEMSKn_MASK         (0xFFU)                                             /*!< LPC_SCT_EV7_STATE: STATEMSKn Mask       */
#define LPC_SCT_EV7_STATE_STATEMSKn_SHIFT        (0U)                                                /*!< LPC_SCT_EV7_STATE: STATEMSKn Position   */
#define LPC_SCT_EV7_STATE_STATEMSKn(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_STATE_STATEMSKn_SHIFT))&LPC_SCT_EV7_STATE_STATEMSKn_MASK) /*!< LPC_SCT_EV7_STATE                       */
/* ------- EV7_CTRL Bit Fields                      ------ */
#define LPC_SCT_EV7_CTRL_MATCHSEL_MASK           (0xFU)                                              /*!< LPC_SCT_EV7_CTRL: MATCHSEL Mask         */
#define LPC_SCT_EV7_CTRL_MATCHSEL_SHIFT          (0U)                                                /*!< LPC_SCT_EV7_CTRL: MATCHSEL Position     */
#define LPC_SCT_EV7_CTRL_MATCHSEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_MATCHSEL_SHIFT))&LPC_SCT_EV7_CTRL_MATCHSEL_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_HEVENT_MASK             (0x10U)                                             /*!< LPC_SCT_EV7_CTRL: HEVENT Mask           */
#define LPC_SCT_EV7_CTRL_HEVENT_SHIFT            (4U)                                                /*!< LPC_SCT_EV7_CTRL: HEVENT Position       */
#define LPC_SCT_EV7_CTRL_HEVENT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_HEVENT_SHIFT))&LPC_SCT_EV7_CTRL_HEVENT_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_OUTSEL_MASK             (0x20U)                                             /*!< LPC_SCT_EV7_CTRL: OUTSEL Mask           */
#define LPC_SCT_EV7_CTRL_OUTSEL_SHIFT            (5U)                                                /*!< LPC_SCT_EV7_CTRL: OUTSEL Position       */
#define LPC_SCT_EV7_CTRL_OUTSEL(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_OUTSEL_SHIFT))&LPC_SCT_EV7_CTRL_OUTSEL_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_IOSEL_MASK              (0x3C0U)                                            /*!< LPC_SCT_EV7_CTRL: IOSEL Mask            */
#define LPC_SCT_EV7_CTRL_IOSEL_SHIFT             (6U)                                                /*!< LPC_SCT_EV7_CTRL: IOSEL Position        */
#define LPC_SCT_EV7_CTRL_IOSEL(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_IOSEL_SHIFT))&LPC_SCT_EV7_CTRL_IOSEL_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_IOCOND_MASK             (0xC00U)                                            /*!< LPC_SCT_EV7_CTRL: IOCOND Mask           */
#define LPC_SCT_EV7_CTRL_IOCOND_SHIFT            (10U)                                               /*!< LPC_SCT_EV7_CTRL: IOCOND Position       */
#define LPC_SCT_EV7_CTRL_IOCOND(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_IOCOND_SHIFT))&LPC_SCT_EV7_CTRL_IOCOND_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_COMBMODE_MASK           (0x3000U)                                           /*!< LPC_SCT_EV7_CTRL: COMBMODE Mask         */
#define LPC_SCT_EV7_CTRL_COMBMODE_SHIFT          (12U)                                               /*!< LPC_SCT_EV7_CTRL: COMBMODE Position     */
#define LPC_SCT_EV7_CTRL_COMBMODE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_COMBMODE_SHIFT))&LPC_SCT_EV7_CTRL_COMBMODE_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_STATELD_MASK            (0x4000U)                                           /*!< LPC_SCT_EV7_CTRL: STATELD Mask          */
#define LPC_SCT_EV7_CTRL_STATELD_SHIFT           (14U)                                               /*!< LPC_SCT_EV7_CTRL: STATELD Position      */
#define LPC_SCT_EV7_CTRL_STATELD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_STATELD_SHIFT))&LPC_SCT_EV7_CTRL_STATELD_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_STATEV_MASK             (0xF8000U)                                          /*!< LPC_SCT_EV7_CTRL: STATEV Mask           */
#define LPC_SCT_EV7_CTRL_STATEV_SHIFT            (15U)                                               /*!< LPC_SCT_EV7_CTRL: STATEV Position       */
#define LPC_SCT_EV7_CTRL_STATEV(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_STATEV_SHIFT))&LPC_SCT_EV7_CTRL_STATEV_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_MATCHMEM_MASK           (0x100000U)                                         /*!< LPC_SCT_EV7_CTRL: MATCHMEM Mask         */
#define LPC_SCT_EV7_CTRL_MATCHMEM_SHIFT          (20U)                                               /*!< LPC_SCT_EV7_CTRL: MATCHMEM Position     */
#define LPC_SCT_EV7_CTRL_MATCHMEM(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_MATCHMEM_SHIFT))&LPC_SCT_EV7_CTRL_MATCHMEM_MASK) /*!< LPC_SCT_EV7_CTRL                        */
#define LPC_SCT_EV7_CTRL_DIRECTION_MASK          (0x600000U)                                         /*!< LPC_SCT_EV7_CTRL: DIRECTION Mask        */
#define LPC_SCT_EV7_CTRL_DIRECTION_SHIFT         (21U)                                               /*!< LPC_SCT_EV7_CTRL: DIRECTION Position    */
#define LPC_SCT_EV7_CTRL_DIRECTION(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SCT_EV7_CTRL_DIRECTION_SHIFT))&LPC_SCT_EV7_CTRL_DIRECTION_MASK) /*!< LPC_SCT_EV7_CTRL                        */
/* ------- OUT0_SET Bit Fields                      ------ */
#define LPC_SCT_OUT0_SET_SET_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT0_SET: SET Mask              */
#define LPC_SCT_OUT0_SET_SET_SHIFT               (0U)                                                /*!< LPC_SCT_OUT0_SET: SET Position          */
#define LPC_SCT_OUT0_SET_SET(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT0_SET_SET_SHIFT))&LPC_SCT_OUT0_SET_SET_MASK) /*!< LPC_SCT_OUT0_SET                        */
/* ------- OUT0_CLR Bit Fields                      ------ */
#define LPC_SCT_OUT0_CLR_CLR_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT0_CLR: CLR Mask              */
#define LPC_SCT_OUT0_CLR_CLR_SHIFT               (0U)                                                /*!< LPC_SCT_OUT0_CLR: CLR Position          */
#define LPC_SCT_OUT0_CLR_CLR(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT0_CLR_CLR_SHIFT))&LPC_SCT_OUT0_CLR_CLR_MASK) /*!< LPC_SCT_OUT0_CLR                        */
/* ------- OUT1_SET Bit Fields                      ------ */
#define LPC_SCT_OUT1_SET_SET_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT1_SET: SET Mask              */
#define LPC_SCT_OUT1_SET_SET_SHIFT               (0U)                                                /*!< LPC_SCT_OUT1_SET: SET Position          */
#define LPC_SCT_OUT1_SET_SET(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT1_SET_SET_SHIFT))&LPC_SCT_OUT1_SET_SET_MASK) /*!< LPC_SCT_OUT1_SET                        */
/* ------- OUT1_CLR Bit Fields                      ------ */
#define LPC_SCT_OUT1_CLR_CLR_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT1_CLR: CLR Mask              */
#define LPC_SCT_OUT1_CLR_CLR_SHIFT               (0U)                                                /*!< LPC_SCT_OUT1_CLR: CLR Position          */
#define LPC_SCT_OUT1_CLR_CLR(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT1_CLR_CLR_SHIFT))&LPC_SCT_OUT1_CLR_CLR_MASK) /*!< LPC_SCT_OUT1_CLR                        */
/* ------- OUT2_SET Bit Fields                      ------ */
#define LPC_SCT_OUT2_SET_SET_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT2_SET: SET Mask              */
#define LPC_SCT_OUT2_SET_SET_SHIFT               (0U)                                                /*!< LPC_SCT_OUT2_SET: SET Position          */
#define LPC_SCT_OUT2_SET_SET(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT2_SET_SET_SHIFT))&LPC_SCT_OUT2_SET_SET_MASK) /*!< LPC_SCT_OUT2_SET                        */
/* ------- OUT2_CLR Bit Fields                      ------ */
#define LPC_SCT_OUT2_CLR_CLR_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT2_CLR: CLR Mask              */
#define LPC_SCT_OUT2_CLR_CLR_SHIFT               (0U)                                                /*!< LPC_SCT_OUT2_CLR: CLR Position          */
#define LPC_SCT_OUT2_CLR_CLR(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT2_CLR_CLR_SHIFT))&LPC_SCT_OUT2_CLR_CLR_MASK) /*!< LPC_SCT_OUT2_CLR                        */
/* ------- OUT3_SET Bit Fields                      ------ */
#define LPC_SCT_OUT3_SET_SET_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT3_SET: SET Mask              */
#define LPC_SCT_OUT3_SET_SET_SHIFT               (0U)                                                /*!< LPC_SCT_OUT3_SET: SET Position          */
#define LPC_SCT_OUT3_SET_SET(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT3_SET_SET_SHIFT))&LPC_SCT_OUT3_SET_SET_MASK) /*!< LPC_SCT_OUT3_SET                        */
/* ------- OUT3_CLR Bit Fields                      ------ */
#define LPC_SCT_OUT3_CLR_CLR_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT3_CLR: CLR Mask              */
#define LPC_SCT_OUT3_CLR_CLR_SHIFT               (0U)                                                /*!< LPC_SCT_OUT3_CLR: CLR Position          */
#define LPC_SCT_OUT3_CLR_CLR(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT3_CLR_CLR_SHIFT))&LPC_SCT_OUT3_CLR_CLR_MASK) /*!< LPC_SCT_OUT3_CLR                        */
/* ------- OUT4_SET Bit Fields                      ------ */
#define LPC_SCT_OUT4_SET_SET_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT4_SET: SET Mask              */
#define LPC_SCT_OUT4_SET_SET_SHIFT               (0U)                                                /*!< LPC_SCT_OUT4_SET: SET Position          */
#define LPC_SCT_OUT4_SET_SET(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT4_SET_SET_SHIFT))&LPC_SCT_OUT4_SET_SET_MASK) /*!< LPC_SCT_OUT4_SET                        */
/* ------- OUT4_CLR Bit Fields                      ------ */
#define LPC_SCT_OUT4_CLR_CLR_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT4_CLR: CLR Mask              */
#define LPC_SCT_OUT4_CLR_CLR_SHIFT               (0U)                                                /*!< LPC_SCT_OUT4_CLR: CLR Position          */
#define LPC_SCT_OUT4_CLR_CLR(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT4_CLR_CLR_SHIFT))&LPC_SCT_OUT4_CLR_CLR_MASK) /*!< LPC_SCT_OUT4_CLR                        */
/* ------- OUT5_SET Bit Fields                      ------ */
#define LPC_SCT_OUT5_SET_SET_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT5_SET: SET Mask              */
#define LPC_SCT_OUT5_SET_SET_SHIFT               (0U)                                                /*!< LPC_SCT_OUT5_SET: SET Position          */
#define LPC_SCT_OUT5_SET_SET(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT5_SET_SET_SHIFT))&LPC_SCT_OUT5_SET_SET_MASK) /*!< LPC_SCT_OUT5_SET                        */
/* ------- OUT5_CLR Bit Fields                      ------ */
#define LPC_SCT_OUT5_CLR_CLR_MASK                (0xFFU)                                             /*!< LPC_SCT_OUT5_CLR: CLR Mask              */
#define LPC_SCT_OUT5_CLR_CLR_SHIFT               (0U)                                                /*!< LPC_SCT_OUT5_CLR: CLR Position          */
#define LPC_SCT_OUT5_CLR_CLR(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SCT_OUT5_CLR_CLR_SHIFT))&LPC_SCT_OUT5_CLR_CLR_MASK) /*!< LPC_SCT_OUT5_CLR                        */
/**
 * @} */ /* End group SCT_Register_Masks_GROUP 
 */

/* LPC_SCT - Peripheral instance base addresses */
#define LPC_SCT_BasePtr                0x50004000UL //!< Peripheral base address
#define LPC_SCT                        ((LPC_SCT_Type *) LPC_SCT_BasePtr) //!< Freescale base pointer
#define LPC_SCT_BASE_PTR               (LPC_SCT) //!< Freescale style base pointer
/**
 * @} */ /* End group SCT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           LPC_SPI0 (file:SPI0_LPC82x)          ================ */
/* ================================================================================ */

/**
 * @brief SPI0
 */
/**
* @addtogroup SPI_structs_GROUP SPI struct
* @brief Struct for SPI
* @{
*/
typedef struct {                                /*       LPC_SPI0 Structure                                           */
   __IO uint32_t  CFG;                          /**< 0000: SPI Configuration register                                   */
   __IO uint32_t  DLY;                          /**< 0004: SPI Delay register                                           */
   __IO uint32_t  STAT;                         /**< 0008: SPI Status. Some status flags can be cleared by writing a 1 to that bit position */
   __IO uint32_t  INTENSET;                     /**< 000C: SPI Interrupt Enable read and Set. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set */
   __O  uint32_t  INTENCLR;                     /**< 0010: SPI Interrupt Enable Clear. Writing a 1 to any implemented bit position causes the corresponding bit in INTENSET to be cleared */
   __I  uint32_t  RXDAT;                        /**< 0014: SPI Receive Data                                             */
   __IO uint32_t  TXDATCTL;                     /**< 0018: SPI Transmit Data with Control                               */
   __IO uint32_t  TXDAT;                        /**< 001C: SPI Transmit Data                                            */
   __IO uint32_t  TXCTL;                        /**< 0020: SPI Transmit Control                                         */
   __IO uint32_t  DIV;                          /**< 0024: SPI clock Divider                                            */
   __I  uint32_t  INTSTAT;                      /**< 0028: SPI Interrupt Status                                         */
} LPC_SPI0_Type;

/**
 * @} */ /* End group SPI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_SPI0' Position & Mask macros                    ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SPI_Register_Masks_GROUP SPI Register Masks
* @brief Register Masks for SPI
* @{
*/
/* ------- CFG Bit Fields                           ------ */
#define LPC_SPI0_CFG_ENABLE_MASK                 (0x1U)                                              /*!< LPC_SPI0_CFG: ENABLE Mask               */
#define LPC_SPI0_CFG_ENABLE_SHIFT                (0U)                                                /*!< LPC_SPI0_CFG: ENABLE Position           */
#define LPC_SPI0_CFG_ENABLE(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_ENABLE_SHIFT))&LPC_SPI0_CFG_ENABLE_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_MASTER_MASK                 (0x4U)                                              /*!< LPC_SPI0_CFG: MASTER Mask               */
#define LPC_SPI0_CFG_MASTER_SHIFT                (2U)                                                /*!< LPC_SPI0_CFG: MASTER Position           */
#define LPC_SPI0_CFG_MASTER(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_MASTER_SHIFT))&LPC_SPI0_CFG_MASTER_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_LSBF_MASK                   (0x8U)                                              /*!< LPC_SPI0_CFG: LSBF Mask                 */
#define LPC_SPI0_CFG_LSBF_SHIFT                  (3U)                                                /*!< LPC_SPI0_CFG: LSBF Position             */
#define LPC_SPI0_CFG_LSBF(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_LSBF_SHIFT))&LPC_SPI0_CFG_LSBF_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_CPHA_MASK                   (0x10U)                                             /*!< LPC_SPI0_CFG: CPHA Mask                 */
#define LPC_SPI0_CFG_CPHA_SHIFT                  (4U)                                                /*!< LPC_SPI0_CFG: CPHA Position             */
#define LPC_SPI0_CFG_CPHA(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_CPHA_SHIFT))&LPC_SPI0_CFG_CPHA_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_CPOL_MASK                   (0x20U)                                             /*!< LPC_SPI0_CFG: CPOL Mask                 */
#define LPC_SPI0_CFG_CPOL_SHIFT                  (5U)                                                /*!< LPC_SPI0_CFG: CPOL Position             */
#define LPC_SPI0_CFG_CPOL(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_CPOL_SHIFT))&LPC_SPI0_CFG_CPOL_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_LOOP_MASK                   (0x80U)                                             /*!< LPC_SPI0_CFG: LOOP Mask                 */
#define LPC_SPI0_CFG_LOOP_SHIFT                  (7U)                                                /*!< LPC_SPI0_CFG: LOOP Position             */
#define LPC_SPI0_CFG_LOOP(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_LOOP_SHIFT))&LPC_SPI0_CFG_LOOP_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_SPOL0_MASK                  (0x100U)                                            /*!< LPC_SPI0_CFG: SPOL0 Mask                */
#define LPC_SPI0_CFG_SPOL0_SHIFT                 (8U)                                                /*!< LPC_SPI0_CFG: SPOL0 Position            */
#define LPC_SPI0_CFG_SPOL0(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_SPOL0_SHIFT))&LPC_SPI0_CFG_SPOL0_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_SPOL1_MASK                  (0x200U)                                            /*!< LPC_SPI0_CFG: SPOL1 Mask                */
#define LPC_SPI0_CFG_SPOL1_SHIFT                 (9U)                                                /*!< LPC_SPI0_CFG: SPOL1 Position            */
#define LPC_SPI0_CFG_SPOL1(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_SPOL1_SHIFT))&LPC_SPI0_CFG_SPOL1_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_SPOL2_MASK                  (0x400U)                                            /*!< LPC_SPI0_CFG: SPOL2 Mask                */
#define LPC_SPI0_CFG_SPOL2_SHIFT                 (10U)                                               /*!< LPC_SPI0_CFG: SPOL2 Position            */
#define LPC_SPI0_CFG_SPOL2(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_SPOL2_SHIFT))&LPC_SPI0_CFG_SPOL2_MASK) /*!< LPC_SPI0_CFG                            */
#define LPC_SPI0_CFG_SPOL3_MASK                  (0x800U)                                            /*!< LPC_SPI0_CFG: SPOL3 Mask                */
#define LPC_SPI0_CFG_SPOL3_SHIFT                 (11U)                                               /*!< LPC_SPI0_CFG: SPOL3 Position            */
#define LPC_SPI0_CFG_SPOL3(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_CFG_SPOL3_SHIFT))&LPC_SPI0_CFG_SPOL3_MASK) /*!< LPC_SPI0_CFG                            */
/* ------- DLY Bit Fields                           ------ */
#define LPC_SPI0_DLY_PRE_DELAY_MASK              (0xFU)                                              /*!< LPC_SPI0_DLY: PRE_DELAY Mask            */
#define LPC_SPI0_DLY_PRE_DELAY_SHIFT             (0U)                                                /*!< LPC_SPI0_DLY: PRE_DELAY Position        */
#define LPC_SPI0_DLY_PRE_DELAY(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_DLY_PRE_DELAY_SHIFT))&LPC_SPI0_DLY_PRE_DELAY_MASK) /*!< LPC_SPI0_DLY                            */
#define LPC_SPI0_DLY_POST_DELAY_MASK             (0xF0U)                                             /*!< LPC_SPI0_DLY: POST_DELAY Mask           */
#define LPC_SPI0_DLY_POST_DELAY_SHIFT            (4U)                                                /*!< LPC_SPI0_DLY: POST_DELAY Position       */
#define LPC_SPI0_DLY_POST_DELAY(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_DLY_POST_DELAY_SHIFT))&LPC_SPI0_DLY_POST_DELAY_MASK) /*!< LPC_SPI0_DLY                            */
#define LPC_SPI0_DLY_FRAME_DELAY_MASK            (0xF00U)                                            /*!< LPC_SPI0_DLY: FRAME_DELAY Mask          */
#define LPC_SPI0_DLY_FRAME_DELAY_SHIFT           (8U)                                                /*!< LPC_SPI0_DLY: FRAME_DELAY Position      */
#define LPC_SPI0_DLY_FRAME_DELAY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_DLY_FRAME_DELAY_SHIFT))&LPC_SPI0_DLY_FRAME_DELAY_MASK) /*!< LPC_SPI0_DLY                            */
#define LPC_SPI0_DLY_TRANSFER_DELAY_MASK         (0xF000U)                                           /*!< LPC_SPI0_DLY: TRANSFER_DELAY Mask       */
#define LPC_SPI0_DLY_TRANSFER_DELAY_SHIFT        (12U)                                               /*!< LPC_SPI0_DLY: TRANSFER_DELAY Position   */
#define LPC_SPI0_DLY_TRANSFER_DELAY(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_DLY_TRANSFER_DELAY_SHIFT))&LPC_SPI0_DLY_TRANSFER_DELAY_MASK) /*!< LPC_SPI0_DLY                            */
/* ------- STAT Bit Fields                          ------ */
#define LPC_SPI0_STAT_RXRDY_MASK                 (0x1U)                                              /*!< LPC_SPI0_STAT: RXRDY Mask               */
#define LPC_SPI0_STAT_RXRDY_SHIFT                (0U)                                                /*!< LPC_SPI0_STAT: RXRDY Position           */
#define LPC_SPI0_STAT_RXRDY(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_RXRDY_SHIFT))&LPC_SPI0_STAT_RXRDY_MASK) /*!< LPC_SPI0_STAT                           */
#define LPC_SPI0_STAT_TXRDY_MASK                 (0x2U)                                              /*!< LPC_SPI0_STAT: TXRDY Mask               */
#define LPC_SPI0_STAT_TXRDY_SHIFT                (1U)                                                /*!< LPC_SPI0_STAT: TXRDY Position           */
#define LPC_SPI0_STAT_TXRDY(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_TXRDY_SHIFT))&LPC_SPI0_STAT_TXRDY_MASK) /*!< LPC_SPI0_STAT                           */
#define LPC_SPI0_STAT_RXOV_MASK                  (0x4U)                                              /*!< LPC_SPI0_STAT: RXOV Mask                */
#define LPC_SPI0_STAT_RXOV_SHIFT                 (2U)                                                /*!< LPC_SPI0_STAT: RXOV Position            */
#define LPC_SPI0_STAT_RXOV(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_RXOV_SHIFT))&LPC_SPI0_STAT_RXOV_MASK) /*!< LPC_SPI0_STAT                           */
#define LPC_SPI0_STAT_TXUR_MASK                  (0x8U)                                              /*!< LPC_SPI0_STAT: TXUR Mask                */
#define LPC_SPI0_STAT_TXUR_SHIFT                 (3U)                                                /*!< LPC_SPI0_STAT: TXUR Position            */
#define LPC_SPI0_STAT_TXUR(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_TXUR_SHIFT))&LPC_SPI0_STAT_TXUR_MASK) /*!< LPC_SPI0_STAT                           */
#define LPC_SPI0_STAT_SSA_MASK                   (0x10U)                                             /*!< LPC_SPI0_STAT: SSA Mask                 */
#define LPC_SPI0_STAT_SSA_SHIFT                  (4U)                                                /*!< LPC_SPI0_STAT: SSA Position             */
#define LPC_SPI0_STAT_SSA(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_SSA_SHIFT))&LPC_SPI0_STAT_SSA_MASK) /*!< LPC_SPI0_STAT                           */
#define LPC_SPI0_STAT_SSD_MASK                   (0x20U)                                             /*!< LPC_SPI0_STAT: SSD Mask                 */
#define LPC_SPI0_STAT_SSD_SHIFT                  (5U)                                                /*!< LPC_SPI0_STAT: SSD Position             */
#define LPC_SPI0_STAT_SSD(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_SSD_SHIFT))&LPC_SPI0_STAT_SSD_MASK) /*!< LPC_SPI0_STAT                           */
#define LPC_SPI0_STAT_STALLED_MASK               (0x40U)                                             /*!< LPC_SPI0_STAT: STALLED Mask             */
#define LPC_SPI0_STAT_STALLED_SHIFT              (6U)                                                /*!< LPC_SPI0_STAT: STALLED Position         */
#define LPC_SPI0_STAT_STALLED(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_STALLED_SHIFT))&LPC_SPI0_STAT_STALLED_MASK) /*!< LPC_SPI0_STAT                           */
#define LPC_SPI0_STAT_ENDTRANSFER_MASK           (0x80U)                                             /*!< LPC_SPI0_STAT: ENDTRANSFER Mask         */
#define LPC_SPI0_STAT_ENDTRANSFER_SHIFT          (7U)                                                /*!< LPC_SPI0_STAT: ENDTRANSFER Position     */
#define LPC_SPI0_STAT_ENDTRANSFER(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_ENDTRANSFER_SHIFT))&LPC_SPI0_STAT_ENDTRANSFER_MASK) /*!< LPC_SPI0_STAT                           */
#define LPC_SPI0_STAT_MSTIDLE_MASK               (0x100U)                                            /*!< LPC_SPI0_STAT: MSTIDLE Mask             */
#define LPC_SPI0_STAT_MSTIDLE_SHIFT              (8U)                                                /*!< LPC_SPI0_STAT: MSTIDLE Position         */
#define LPC_SPI0_STAT_MSTIDLE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_STAT_MSTIDLE_SHIFT))&LPC_SPI0_STAT_MSTIDLE_MASK) /*!< LPC_SPI0_STAT                           */
/* ------- INTENSET Bit Fields                      ------ */
#define LPC_SPI0_INTENSET_RXRDYEN_MASK           (0x1U)                                              /*!< LPC_SPI0_INTENSET: RXRDYEN Mask         */
#define LPC_SPI0_INTENSET_RXRDYEN_SHIFT          (0U)                                                /*!< LPC_SPI0_INTENSET: RXRDYEN Position     */
#define LPC_SPI0_INTENSET_RXRDYEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENSET_RXRDYEN_SHIFT))&LPC_SPI0_INTENSET_RXRDYEN_MASK) /*!< LPC_SPI0_INTENSET                       */
#define LPC_SPI0_INTENSET_TXRDYEN_MASK           (0x2U)                                              /*!< LPC_SPI0_INTENSET: TXRDYEN Mask         */
#define LPC_SPI0_INTENSET_TXRDYEN_SHIFT          (1U)                                                /*!< LPC_SPI0_INTENSET: TXRDYEN Position     */
#define LPC_SPI0_INTENSET_TXRDYEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENSET_TXRDYEN_SHIFT))&LPC_SPI0_INTENSET_TXRDYEN_MASK) /*!< LPC_SPI0_INTENSET                       */
#define LPC_SPI0_INTENSET_RXOVEN_MASK            (0x4U)                                              /*!< LPC_SPI0_INTENSET: RXOVEN Mask          */
#define LPC_SPI0_INTENSET_RXOVEN_SHIFT           (2U)                                                /*!< LPC_SPI0_INTENSET: RXOVEN Position      */
#define LPC_SPI0_INTENSET_RXOVEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENSET_RXOVEN_SHIFT))&LPC_SPI0_INTENSET_RXOVEN_MASK) /*!< LPC_SPI0_INTENSET                       */
#define LPC_SPI0_INTENSET_TXUREN_MASK            (0x8U)                                              /*!< LPC_SPI0_INTENSET: TXUREN Mask          */
#define LPC_SPI0_INTENSET_TXUREN_SHIFT           (3U)                                                /*!< LPC_SPI0_INTENSET: TXUREN Position      */
#define LPC_SPI0_INTENSET_TXUREN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENSET_TXUREN_SHIFT))&LPC_SPI0_INTENSET_TXUREN_MASK) /*!< LPC_SPI0_INTENSET                       */
#define LPC_SPI0_INTENSET_SSAEN_MASK             (0x10U)                                             /*!< LPC_SPI0_INTENSET: SSAEN Mask           */
#define LPC_SPI0_INTENSET_SSAEN_SHIFT            (4U)                                                /*!< LPC_SPI0_INTENSET: SSAEN Position       */
#define LPC_SPI0_INTENSET_SSAEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENSET_SSAEN_SHIFT))&LPC_SPI0_INTENSET_SSAEN_MASK) /*!< LPC_SPI0_INTENSET                       */
#define LPC_SPI0_INTENSET_SSDEN_MASK             (0x20U)                                             /*!< LPC_SPI0_INTENSET: SSDEN Mask           */
#define LPC_SPI0_INTENSET_SSDEN_SHIFT            (5U)                                                /*!< LPC_SPI0_INTENSET: SSDEN Position       */
#define LPC_SPI0_INTENSET_SSDEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENSET_SSDEN_SHIFT))&LPC_SPI0_INTENSET_SSDEN_MASK) /*!< LPC_SPI0_INTENSET                       */
/* ------- INTENCLR Bit Fields                      ------ */
#define LPC_SPI0_INTENCLR_RXRDYEN_MASK           (0x1U)                                              /*!< LPC_SPI0_INTENCLR: RXRDYEN Mask         */
#define LPC_SPI0_INTENCLR_RXRDYEN_SHIFT          (0U)                                                /*!< LPC_SPI0_INTENCLR: RXRDYEN Position     */
#define LPC_SPI0_INTENCLR_RXRDYEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENCLR_RXRDYEN_SHIFT))&LPC_SPI0_INTENCLR_RXRDYEN_MASK) /*!< LPC_SPI0_INTENCLR                       */
#define LPC_SPI0_INTENCLR_TXRDYEN_MASK           (0x2U)                                              /*!< LPC_SPI0_INTENCLR: TXRDYEN Mask         */
#define LPC_SPI0_INTENCLR_TXRDYEN_SHIFT          (1U)                                                /*!< LPC_SPI0_INTENCLR: TXRDYEN Position     */
#define LPC_SPI0_INTENCLR_TXRDYEN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENCLR_TXRDYEN_SHIFT))&LPC_SPI0_INTENCLR_TXRDYEN_MASK) /*!< LPC_SPI0_INTENCLR                       */
#define LPC_SPI0_INTENCLR_RXOVEN_MASK            (0x4U)                                              /*!< LPC_SPI0_INTENCLR: RXOVEN Mask          */
#define LPC_SPI0_INTENCLR_RXOVEN_SHIFT           (2U)                                                /*!< LPC_SPI0_INTENCLR: RXOVEN Position      */
#define LPC_SPI0_INTENCLR_RXOVEN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENCLR_RXOVEN_SHIFT))&LPC_SPI0_INTENCLR_RXOVEN_MASK) /*!< LPC_SPI0_INTENCLR                       */
#define LPC_SPI0_INTENCLR_TXUREN_MASK            (0x8U)                                              /*!< LPC_SPI0_INTENCLR: TXUREN Mask          */
#define LPC_SPI0_INTENCLR_TXUREN_SHIFT           (3U)                                                /*!< LPC_SPI0_INTENCLR: TXUREN Position      */
#define LPC_SPI0_INTENCLR_TXUREN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENCLR_TXUREN_SHIFT))&LPC_SPI0_INTENCLR_TXUREN_MASK) /*!< LPC_SPI0_INTENCLR                       */
#define LPC_SPI0_INTENCLR_SSAEN_MASK             (0x10U)                                             /*!< LPC_SPI0_INTENCLR: SSAEN Mask           */
#define LPC_SPI0_INTENCLR_SSAEN_SHIFT            (4U)                                                /*!< LPC_SPI0_INTENCLR: SSAEN Position       */
#define LPC_SPI0_INTENCLR_SSAEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENCLR_SSAEN_SHIFT))&LPC_SPI0_INTENCLR_SSAEN_MASK) /*!< LPC_SPI0_INTENCLR                       */
#define LPC_SPI0_INTENCLR_SSDEN_MASK             (0x20U)                                             /*!< LPC_SPI0_INTENCLR: SSDEN Mask           */
#define LPC_SPI0_INTENCLR_SSDEN_SHIFT            (5U)                                                /*!< LPC_SPI0_INTENCLR: SSDEN Position       */
#define LPC_SPI0_INTENCLR_SSDEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTENCLR_SSDEN_SHIFT))&LPC_SPI0_INTENCLR_SSDEN_MASK) /*!< LPC_SPI0_INTENCLR                       */
/* ------- RXDAT Bit Fields                         ------ */
#define LPC_SPI0_RXDAT_RXDAT_MASK                (0xFFFFU)                                           /*!< LPC_SPI0_RXDAT: RXDAT Mask              */
#define LPC_SPI0_RXDAT_RXDAT_SHIFT               (0U)                                                /*!< LPC_SPI0_RXDAT: RXDAT Position          */
#define LPC_SPI0_RXDAT_RXDAT(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_RXDAT_RXDAT_SHIFT))&LPC_SPI0_RXDAT_RXDAT_MASK) /*!< LPC_SPI0_RXDAT                          */
#define LPC_SPI0_RXDAT_RXSSEL0_N_MASK            (0x10000U)                                          /*!< LPC_SPI0_RXDAT: RXSSEL0_N Mask          */
#define LPC_SPI0_RXDAT_RXSSEL0_N_SHIFT           (16U)                                               /*!< LPC_SPI0_RXDAT: RXSSEL0_N Position      */
#define LPC_SPI0_RXDAT_RXSSEL0_N(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_RXDAT_RXSSEL0_N_SHIFT))&LPC_SPI0_RXDAT_RXSSEL0_N_MASK) /*!< LPC_SPI0_RXDAT                          */
#define LPC_SPI0_RXDAT_RXSSEL1_N_MASK            (0x20000U)                                          /*!< LPC_SPI0_RXDAT: RXSSEL1_N Mask          */
#define LPC_SPI0_RXDAT_RXSSEL1_N_SHIFT           (17U)                                               /*!< LPC_SPI0_RXDAT: RXSSEL1_N Position      */
#define LPC_SPI0_RXDAT_RXSSEL1_N(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_RXDAT_RXSSEL1_N_SHIFT))&LPC_SPI0_RXDAT_RXSSEL1_N_MASK) /*!< LPC_SPI0_RXDAT                          */
#define LPC_SPI0_RXDAT_RXSSEL2_N_MASK            (0x40000U)                                          /*!< LPC_SPI0_RXDAT: RXSSEL2_N Mask          */
#define LPC_SPI0_RXDAT_RXSSEL2_N_SHIFT           (18U)                                               /*!< LPC_SPI0_RXDAT: RXSSEL2_N Position      */
#define LPC_SPI0_RXDAT_RXSSEL2_N(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_RXDAT_RXSSEL2_N_SHIFT))&LPC_SPI0_RXDAT_RXSSEL2_N_MASK) /*!< LPC_SPI0_RXDAT                          */
#define LPC_SPI0_RXDAT_RXSSEL3_N_MASK            (0x80000U)                                          /*!< LPC_SPI0_RXDAT: RXSSEL3_N Mask          */
#define LPC_SPI0_RXDAT_RXSSEL3_N_SHIFT           (19U)                                               /*!< LPC_SPI0_RXDAT: RXSSEL3_N Position      */
#define LPC_SPI0_RXDAT_RXSSEL3_N(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_RXDAT_RXSSEL3_N_SHIFT))&LPC_SPI0_RXDAT_RXSSEL3_N_MASK) /*!< LPC_SPI0_RXDAT                          */
#define LPC_SPI0_RXDAT_SOT_MASK                  (0x100000U)                                         /*!< LPC_SPI0_RXDAT: SOT Mask                */
#define LPC_SPI0_RXDAT_SOT_SHIFT                 (20U)                                               /*!< LPC_SPI0_RXDAT: SOT Position            */
#define LPC_SPI0_RXDAT_SOT(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_RXDAT_SOT_SHIFT))&LPC_SPI0_RXDAT_SOT_MASK) /*!< LPC_SPI0_RXDAT                          */
/* ------- TXDATCTL Bit Fields                      ------ */
#define LPC_SPI0_TXDATCTL_TXDAT_MASK             (0xFFFFU)                                           /*!< LPC_SPI0_TXDATCTL: TXDAT Mask           */
#define LPC_SPI0_TXDATCTL_TXDAT_SHIFT            (0U)                                                /*!< LPC_SPI0_TXDATCTL: TXDAT Position       */
#define LPC_SPI0_TXDATCTL_TXDAT(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_TXDAT_SHIFT))&LPC_SPI0_TXDATCTL_TXDAT_MASK) /*!< LPC_SPI0_TXDATCTL                       */
#define LPC_SPI0_TXDATCTL_TXSSEL0_N_MASK         (0x10000U)                                          /*!< LPC_SPI0_TXDATCTL: TXSSEL0_N Mask       */
#define LPC_SPI0_TXDATCTL_TXSSEL0_N_SHIFT        (16U)                                               /*!< LPC_SPI0_TXDATCTL: TXSSEL0_N Position   */
#define LPC_SPI0_TXDATCTL_TXSSEL0_N(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_TXSSEL0_N_SHIFT))&LPC_SPI0_TXDATCTL_TXSSEL0_N_MASK) /*!< LPC_SPI0_TXDATCTL                       */
#define LPC_SPI0_TXDATCTL_TXSSEL1_N_MASK         (0x20000U)                                          /*!< LPC_SPI0_TXDATCTL: TXSSEL1_N Mask       */
#define LPC_SPI0_TXDATCTL_TXSSEL1_N_SHIFT        (17U)                                               /*!< LPC_SPI0_TXDATCTL: TXSSEL1_N Position   */
#define LPC_SPI0_TXDATCTL_TXSSEL1_N(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_TXSSEL1_N_SHIFT))&LPC_SPI0_TXDATCTL_TXSSEL1_N_MASK) /*!< LPC_SPI0_TXDATCTL                       */
#define LPC_SPI0_TXDATCTL_TXSSEL2_N_MASK         (0x40000U)                                          /*!< LPC_SPI0_TXDATCTL: TXSSEL2_N Mask       */
#define LPC_SPI0_TXDATCTL_TXSSEL2_N_SHIFT        (18U)                                               /*!< LPC_SPI0_TXDATCTL: TXSSEL2_N Position   */
#define LPC_SPI0_TXDATCTL_TXSSEL2_N(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_TXSSEL2_N_SHIFT))&LPC_SPI0_TXDATCTL_TXSSEL2_N_MASK) /*!< LPC_SPI0_TXDATCTL                       */
#define LPC_SPI0_TXDATCTL_TXSSEL3_N_MASK         (0x80000U)                                          /*!< LPC_SPI0_TXDATCTL: TXSSEL3_N Mask       */
#define LPC_SPI0_TXDATCTL_TXSSEL3_N_SHIFT        (19U)                                               /*!< LPC_SPI0_TXDATCTL: TXSSEL3_N Position   */
#define LPC_SPI0_TXDATCTL_TXSSEL3_N(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_TXSSEL3_N_SHIFT))&LPC_SPI0_TXDATCTL_TXSSEL3_N_MASK) /*!< LPC_SPI0_TXDATCTL                       */
#define LPC_SPI0_TXDATCTL_EOT_MASK               (0x100000U)                                         /*!< LPC_SPI0_TXDATCTL: EOT Mask             */
#define LPC_SPI0_TXDATCTL_EOT_SHIFT              (20U)                                               /*!< LPC_SPI0_TXDATCTL: EOT Position         */
#define LPC_SPI0_TXDATCTL_EOT(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_EOT_SHIFT))&LPC_SPI0_TXDATCTL_EOT_MASK) /*!< LPC_SPI0_TXDATCTL                       */
#define LPC_SPI0_TXDATCTL_EOF_MASK               (0x200000U)                                         /*!< LPC_SPI0_TXDATCTL: EOF Mask             */
#define LPC_SPI0_TXDATCTL_EOF_SHIFT              (21U)                                               /*!< LPC_SPI0_TXDATCTL: EOF Position         */
#define LPC_SPI0_TXDATCTL_EOF(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_EOF_SHIFT))&LPC_SPI0_TXDATCTL_EOF_MASK) /*!< LPC_SPI0_TXDATCTL                       */
#define LPC_SPI0_TXDATCTL_RXIGNORE_MASK          (0x400000U)                                         /*!< LPC_SPI0_TXDATCTL: RXIGNORE Mask        */
#define LPC_SPI0_TXDATCTL_RXIGNORE_SHIFT         (22U)                                               /*!< LPC_SPI0_TXDATCTL: RXIGNORE Position    */
#define LPC_SPI0_TXDATCTL_RXIGNORE(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_RXIGNORE_SHIFT))&LPC_SPI0_TXDATCTL_RXIGNORE_MASK) /*!< LPC_SPI0_TXDATCTL                       */
#define LPC_SPI0_TXDATCTL_LEN_MASK               (0xF000000U)                                        /*!< LPC_SPI0_TXDATCTL: LEN Mask             */
#define LPC_SPI0_TXDATCTL_LEN_SHIFT              (24U)                                               /*!< LPC_SPI0_TXDATCTL: LEN Position         */
#define LPC_SPI0_TXDATCTL_LEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDATCTL_LEN_SHIFT))&LPC_SPI0_TXDATCTL_LEN_MASK) /*!< LPC_SPI0_TXDATCTL                       */
/* ------- TXDAT Bit Fields                         ------ */
#define LPC_SPI0_TXDAT_DATA_MASK                 (0xFFFFU)                                           /*!< LPC_SPI0_TXDAT: DATA Mask               */
#define LPC_SPI0_TXDAT_DATA_SHIFT                (0U)                                                /*!< LPC_SPI0_TXDAT: DATA Position           */
#define LPC_SPI0_TXDAT_DATA(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXDAT_DATA_SHIFT))&LPC_SPI0_TXDAT_DATA_MASK) /*!< LPC_SPI0_TXDAT                          */
/* ------- TXCTL Bit Fields                         ------ */
#define LPC_SPI0_TXCTL_TXSSEL0_N_MASK            (0x10000U)                                          /*!< LPC_SPI0_TXCTL: TXSSEL0_N Mask          */
#define LPC_SPI0_TXCTL_TXSSEL0_N_SHIFT           (16U)                                               /*!< LPC_SPI0_TXCTL: TXSSEL0_N Position      */
#define LPC_SPI0_TXCTL_TXSSEL0_N(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXCTL_TXSSEL0_N_SHIFT))&LPC_SPI0_TXCTL_TXSSEL0_N_MASK) /*!< LPC_SPI0_TXCTL                          */
#define LPC_SPI0_TXCTL_TXSSEL1_N_MASK            (0x20000U)                                          /*!< LPC_SPI0_TXCTL: TXSSEL1_N Mask          */
#define LPC_SPI0_TXCTL_TXSSEL1_N_SHIFT           (17U)                                               /*!< LPC_SPI0_TXCTL: TXSSEL1_N Position      */
#define LPC_SPI0_TXCTL_TXSSEL1_N(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXCTL_TXSSEL1_N_SHIFT))&LPC_SPI0_TXCTL_TXSSEL1_N_MASK) /*!< LPC_SPI0_TXCTL                          */
#define LPC_SPI0_TXCTL_TXSSEL2_N_MASK            (0x40000U)                                          /*!< LPC_SPI0_TXCTL: TXSSEL2_N Mask          */
#define LPC_SPI0_TXCTL_TXSSEL2_N_SHIFT           (18U)                                               /*!< LPC_SPI0_TXCTL: TXSSEL2_N Position      */
#define LPC_SPI0_TXCTL_TXSSEL2_N(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXCTL_TXSSEL2_N_SHIFT))&LPC_SPI0_TXCTL_TXSSEL2_N_MASK) /*!< LPC_SPI0_TXCTL                          */
#define LPC_SPI0_TXCTL_TXSSEL3_n_MASK            (0x80000U)                                          /*!< LPC_SPI0_TXCTL: TXSSEL3_n Mask          */
#define LPC_SPI0_TXCTL_TXSSEL3_n_SHIFT           (19U)                                               /*!< LPC_SPI0_TXCTL: TXSSEL3_n Position      */
#define LPC_SPI0_TXCTL_TXSSEL3_n(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXCTL_TXSSEL3_n_SHIFT))&LPC_SPI0_TXCTL_TXSSEL3_n_MASK) /*!< LPC_SPI0_TXCTL                          */
#define LPC_SPI0_TXCTL_EOT_MASK                  (0x100000U)                                         /*!< LPC_SPI0_TXCTL: EOT Mask                */
#define LPC_SPI0_TXCTL_EOT_SHIFT                 (20U)                                               /*!< LPC_SPI0_TXCTL: EOT Position            */
#define LPC_SPI0_TXCTL_EOT(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXCTL_EOT_SHIFT))&LPC_SPI0_TXCTL_EOT_MASK) /*!< LPC_SPI0_TXCTL                          */
#define LPC_SPI0_TXCTL_EOF_MASK                  (0x200000U)                                         /*!< LPC_SPI0_TXCTL: EOF Mask                */
#define LPC_SPI0_TXCTL_EOF_SHIFT                 (21U)                                               /*!< LPC_SPI0_TXCTL: EOF Position            */
#define LPC_SPI0_TXCTL_EOF(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXCTL_EOF_SHIFT))&LPC_SPI0_TXCTL_EOF_MASK) /*!< LPC_SPI0_TXCTL                          */
#define LPC_SPI0_TXCTL_RXIGNORE_MASK             (0x400000U)                                         /*!< LPC_SPI0_TXCTL: RXIGNORE Mask           */
#define LPC_SPI0_TXCTL_RXIGNORE_SHIFT            (22U)                                               /*!< LPC_SPI0_TXCTL: RXIGNORE Position       */
#define LPC_SPI0_TXCTL_RXIGNORE(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXCTL_RXIGNORE_SHIFT))&LPC_SPI0_TXCTL_RXIGNORE_MASK) /*!< LPC_SPI0_TXCTL                          */
#define LPC_SPI0_TXCTL_LEN_MASK                  (0xF000000U)                                        /*!< LPC_SPI0_TXCTL: LEN Mask                */
#define LPC_SPI0_TXCTL_LEN_SHIFT                 (24U)                                               /*!< LPC_SPI0_TXCTL: LEN Position            */
#define LPC_SPI0_TXCTL_LEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_TXCTL_LEN_SHIFT))&LPC_SPI0_TXCTL_LEN_MASK) /*!< LPC_SPI0_TXCTL                          */
/* ------- DIV Bit Fields                           ------ */
#define LPC_SPI0_DIV_DIVVAL_MASK                 (0xFFFFU)                                           /*!< LPC_SPI0_DIV: DIVVAL Mask               */
#define LPC_SPI0_DIV_DIVVAL_SHIFT                (0U)                                                /*!< LPC_SPI0_DIV: DIVVAL Position           */
#define LPC_SPI0_DIV_DIVVAL(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_DIV_DIVVAL_SHIFT))&LPC_SPI0_DIV_DIVVAL_MASK) /*!< LPC_SPI0_DIV                            */
/* ------- INTSTAT Bit Fields                       ------ */
#define LPC_SPI0_INTSTAT_RXRDY_MASK              (0x1U)                                              /*!< LPC_SPI0_INTSTAT: RXRDY Mask            */
#define LPC_SPI0_INTSTAT_RXRDY_SHIFT             (0U)                                                /*!< LPC_SPI0_INTSTAT: RXRDY Position        */
#define LPC_SPI0_INTSTAT_RXRDY(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTSTAT_RXRDY_SHIFT))&LPC_SPI0_INTSTAT_RXRDY_MASK) /*!< LPC_SPI0_INTSTAT                        */
#define LPC_SPI0_INTSTAT_TXRDY_MASK              (0x2U)                                              /*!< LPC_SPI0_INTSTAT: TXRDY Mask            */
#define LPC_SPI0_INTSTAT_TXRDY_SHIFT             (1U)                                                /*!< LPC_SPI0_INTSTAT: TXRDY Position        */
#define LPC_SPI0_INTSTAT_TXRDY(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTSTAT_TXRDY_SHIFT))&LPC_SPI0_INTSTAT_TXRDY_MASK) /*!< LPC_SPI0_INTSTAT                        */
#define LPC_SPI0_INTSTAT_RXOV_MASK               (0x4U)                                              /*!< LPC_SPI0_INTSTAT: RXOV Mask             */
#define LPC_SPI0_INTSTAT_RXOV_SHIFT              (2U)                                                /*!< LPC_SPI0_INTSTAT: RXOV Position         */
#define LPC_SPI0_INTSTAT_RXOV(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTSTAT_RXOV_SHIFT))&LPC_SPI0_INTSTAT_RXOV_MASK) /*!< LPC_SPI0_INTSTAT                        */
#define LPC_SPI0_INTSTAT_TXUR_MASK               (0x8U)                                              /*!< LPC_SPI0_INTSTAT: TXUR Mask             */
#define LPC_SPI0_INTSTAT_TXUR_SHIFT              (3U)                                                /*!< LPC_SPI0_INTSTAT: TXUR Position         */
#define LPC_SPI0_INTSTAT_TXUR(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTSTAT_TXUR_SHIFT))&LPC_SPI0_INTSTAT_TXUR_MASK) /*!< LPC_SPI0_INTSTAT                        */
#define LPC_SPI0_INTSTAT_SSA_MASK                (0x10U)                                             /*!< LPC_SPI0_INTSTAT: SSA Mask              */
#define LPC_SPI0_INTSTAT_SSA_SHIFT               (4U)                                                /*!< LPC_SPI0_INTSTAT: SSA Position          */
#define LPC_SPI0_INTSTAT_SSA(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTSTAT_SSA_SHIFT))&LPC_SPI0_INTSTAT_SSA_MASK) /*!< LPC_SPI0_INTSTAT                        */
#define LPC_SPI0_INTSTAT_SSD_MASK                (0x20U)                                             /*!< LPC_SPI0_INTSTAT: SSD Mask              */
#define LPC_SPI0_INTSTAT_SSD_SHIFT               (5U)                                                /*!< LPC_SPI0_INTSTAT: SSD Position          */
#define LPC_SPI0_INTSTAT_SSD(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_SPI0_INTSTAT_SSD_SHIFT))&LPC_SPI0_INTSTAT_SSD_MASK) /*!< LPC_SPI0_INTSTAT                        */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* LPC_SPI0 - Peripheral instance base addresses */
#define LPC_SPI0_BasePtr               0x40058000UL //!< Peripheral base address
#define LPC_SPI0                       ((LPC_SPI0_Type *) LPC_SPI0_BasePtr) //!< Freescale base pointer
#define LPC_SPI0_BASE_PTR              (LPC_SPI0) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           LPC_SPI1 (derived from SPI0)         ================ */
/* ================================================================================ */

/**
 * @brief SPI0
 */

/* LPC_SPI1 - Peripheral instance base addresses */
#define LPC_SPI1_BasePtr               0x4005C000UL //!< Peripheral base address
#define LPC_SPI1                       ((LPC_SPI0_Type *) LPC_SPI1_BasePtr) //!< Freescale base pointer
#define LPC_SPI1_BASE_PTR              (LPC_SPI1) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SWM_Peripheral_access_layer_GROUP SWM Peripheral Access Layer
* @brief C Struct for SWM
* @{
*/

/* ================================================================================ */
/* ================           LPC_SWM (file:SWM_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief Switch matrix
 */
/**
* @addtogroup SWM_structs_GROUP SWM struct
* @brief Struct for SWM
* @{
*/
typedef struct {                                /*       LPC_SWM Structure                                            */
   __IO uint32_t  PINASSIGN0;                   /**< 0000: Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS */
   __IO uint32_t  PINASSIGN1;                   /**< 0004: Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_RTS */
   __IO uint32_t  PINASSIGN2;                   /**< 0008: Pin assign register 2. Assign movable functions U1_CTS, U1_SCLK, U2_TXD, U2_RXD */
   __IO uint32_t  PINASSIGN3;                   /**< 000C: Pin assign register 3. Assign movable function U2_RTS, U2_CTS, U2_SCLK, SPI0_SCK */
   __IO uint32_t  PINASSIGN4;                   /**< 0010: Pin assign register 4. Assign movable functions SPI0_MOSI, SPI0_MISO, SPI0_SSEL0, SPI0_SSEL1 */
   __IO uint32_t  PINASSIGN5;                   /**< 0014: Pin assign register 5. Assign movable functions SPI0_SSEL2, SPI0_SSEL3, SPI1_SCK, SPI1_MOSI */
   __IO uint32_t  PINASSIGN6;                   /**< 0018: Pin assign register 6. Assign movable functions SPI1_MISO, SPI1_SSEL0, SPI1_SSEL1, SCT0_IN0 */
   __IO uint32_t  PINASSIGN7;                   /**< 001C: Pin assign register 7. Assign movable functions SCT_IN1, SCT_IN2, SCT_IN3, SCT_OUT0 */
   __IO uint32_t  PINASSIGN8;                   /**< 0020: Pin assign register 8. Assign movable functions SCT_OUT1, SCT_OUT2, SCT_OUT3, SCT_OUT4 */
   __IO uint32_t  PINASSIGN9;                   /**< 0024: Pin assign register 9. Assign movable functions SCT_OUT5, I2C1_SDA, I2C1_SCL, I2C2_SDA */
   __IO uint32_t  PINASSIGN10;                  /**< 0028: Pin assign register 10. Assign movable functions I2C2_SCL, I2C3_SDA, I2C3_SCL, ADC_PINTRIG0 */
   __IO uint32_t  PINASSIGN11;                  /**< 002C: Pin assign register 11. Assign movable functions ADC_PINTRIG1, ACMP_O, CLKOUT, GPIO_INT_BMAT */
        uint8_t   RESERVED_0[400];             
   __IO uint32_t  PINENABLE0;                   /**< 01C0: Pin enable register 0. Enables fixed-pin functions ACMP_I0, ACMP_I1, SWCLK, SWDIO, XTALIN, XTALOUT, RESET, CLKIN, VDDCMP */
} LPC_SWM_Type;

/**
 * @} */ /* End group SWM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_SWM' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SWM_Register_Masks_GROUP SWM Register Masks
* @brief Register Masks for SWM
* @{
*/
/* ------- PINASSIGN0 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN0_U0_TXD_O_MASK         (0xFFU)                                             /*!< LPC_SWM_PINASSIGN0: U0_TXD_O Mask       */
#define LPC_SWM_PINASSIGN0_U0_TXD_O_SHIFT        (0U)                                                /*!< LPC_SWM_PINASSIGN0: U0_TXD_O Position   */
#define LPC_SWM_PINASSIGN0_U0_TXD_O(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN0_U0_TXD_O_SHIFT))&LPC_SWM_PINASSIGN0_U0_TXD_O_MASK) /*!< LPC_SWM_PINASSIGN0                      */
#define LPC_SWM_PINASSIGN0_U0_RXD_I_MASK         (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN0: U0_RXD_I Mask       */
#define LPC_SWM_PINASSIGN0_U0_RXD_I_SHIFT        (8U)                                                /*!< LPC_SWM_PINASSIGN0: U0_RXD_I Position   */
#define LPC_SWM_PINASSIGN0_U0_RXD_I(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN0_U0_RXD_I_SHIFT))&LPC_SWM_PINASSIGN0_U0_RXD_I_MASK) /*!< LPC_SWM_PINASSIGN0                      */
#define LPC_SWM_PINASSIGN0_U0_RTS_O_MASK         (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN0: U0_RTS_O Mask       */
#define LPC_SWM_PINASSIGN0_U0_RTS_O_SHIFT        (16U)                                               /*!< LPC_SWM_PINASSIGN0: U0_RTS_O Position   */
#define LPC_SWM_PINASSIGN0_U0_RTS_O(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN0_U0_RTS_O_SHIFT))&LPC_SWM_PINASSIGN0_U0_RTS_O_MASK) /*!< LPC_SWM_PINASSIGN0                      */
#define LPC_SWM_PINASSIGN0_U0_CTS_I_MASK         (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN0: U0_CTS_I Mask       */
#define LPC_SWM_PINASSIGN0_U0_CTS_I_SHIFT        (24U)                                               /*!< LPC_SWM_PINASSIGN0: U0_CTS_I Position   */
#define LPC_SWM_PINASSIGN0_U0_CTS_I(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN0_U0_CTS_I_SHIFT))&LPC_SWM_PINASSIGN0_U0_CTS_I_MASK) /*!< LPC_SWM_PINASSIGN0                      */
/* ------- PINASSIGN1 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN1_U0_SCLK_IO_MASK       (0xFFU)                                             /*!< LPC_SWM_PINASSIGN1: U0_SCLK_IO Mask     */
#define LPC_SWM_PINASSIGN1_U0_SCLK_IO_SHIFT      (0U)                                                /*!< LPC_SWM_PINASSIGN1: U0_SCLK_IO Position */
#define LPC_SWM_PINASSIGN1_U0_SCLK_IO(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN1_U0_SCLK_IO_SHIFT))&LPC_SWM_PINASSIGN1_U0_SCLK_IO_MASK) /*!< LPC_SWM_PINASSIGN1                      */
#define LPC_SWM_PINASSIGN1_U1_TXD_O_MASK         (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN1: U1_TXD_O Mask       */
#define LPC_SWM_PINASSIGN1_U1_TXD_O_SHIFT        (8U)                                                /*!< LPC_SWM_PINASSIGN1: U1_TXD_O Position   */
#define LPC_SWM_PINASSIGN1_U1_TXD_O(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN1_U1_TXD_O_SHIFT))&LPC_SWM_PINASSIGN1_U1_TXD_O_MASK) /*!< LPC_SWM_PINASSIGN1                      */
#define LPC_SWM_PINASSIGN1_U1_RXD_I_MASK         (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN1: U1_RXD_I Mask       */
#define LPC_SWM_PINASSIGN1_U1_RXD_I_SHIFT        (16U)                                               /*!< LPC_SWM_PINASSIGN1: U1_RXD_I Position   */
#define LPC_SWM_PINASSIGN1_U1_RXD_I(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN1_U1_RXD_I_SHIFT))&LPC_SWM_PINASSIGN1_U1_RXD_I_MASK) /*!< LPC_SWM_PINASSIGN1                      */
#define LPC_SWM_PINASSIGN1_U1_RTS_O_MASK         (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN1: U1_RTS_O Mask       */
#define LPC_SWM_PINASSIGN1_U1_RTS_O_SHIFT        (24U)                                               /*!< LPC_SWM_PINASSIGN1: U1_RTS_O Position   */
#define LPC_SWM_PINASSIGN1_U1_RTS_O(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN1_U1_RTS_O_SHIFT))&LPC_SWM_PINASSIGN1_U1_RTS_O_MASK) /*!< LPC_SWM_PINASSIGN1                      */
/* ------- PINASSIGN2 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN2_U1_CTS_I_MASK         (0xFFU)                                             /*!< LPC_SWM_PINASSIGN2: U1_CTS_I Mask       */
#define LPC_SWM_PINASSIGN2_U1_CTS_I_SHIFT        (0U)                                                /*!< LPC_SWM_PINASSIGN2: U1_CTS_I Position   */
#define LPC_SWM_PINASSIGN2_U1_CTS_I(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN2_U1_CTS_I_SHIFT))&LPC_SWM_PINASSIGN2_U1_CTS_I_MASK) /*!< LPC_SWM_PINASSIGN2                      */
#define LPC_SWM_PINASSIGN2_U1_SCLK_IO_MASK       (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN2: U1_SCLK_IO Mask     */
#define LPC_SWM_PINASSIGN2_U1_SCLK_IO_SHIFT      (8U)                                                /*!< LPC_SWM_PINASSIGN2: U1_SCLK_IO Position */
#define LPC_SWM_PINASSIGN2_U1_SCLK_IO(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN2_U1_SCLK_IO_SHIFT))&LPC_SWM_PINASSIGN2_U1_SCLK_IO_MASK) /*!< LPC_SWM_PINASSIGN2                      */
#define LPC_SWM_PINASSIGN2_U2_TXD_O_MASK         (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN2: U2_TXD_O Mask       */
#define LPC_SWM_PINASSIGN2_U2_TXD_O_SHIFT        (16U)                                               /*!< LPC_SWM_PINASSIGN2: U2_TXD_O Position   */
#define LPC_SWM_PINASSIGN2_U2_TXD_O(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN2_U2_TXD_O_SHIFT))&LPC_SWM_PINASSIGN2_U2_TXD_O_MASK) /*!< LPC_SWM_PINASSIGN2                      */
#define LPC_SWM_PINASSIGN2_U2_RXD_I_MASK         (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN2: U2_RXD_I Mask       */
#define LPC_SWM_PINASSIGN2_U2_RXD_I_SHIFT        (24U)                                               /*!< LPC_SWM_PINASSIGN2: U2_RXD_I Position   */
#define LPC_SWM_PINASSIGN2_U2_RXD_I(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN2_U2_RXD_I_SHIFT))&LPC_SWM_PINASSIGN2_U2_RXD_I_MASK) /*!< LPC_SWM_PINASSIGN2                      */
/* ------- PINASSIGN3 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN3_U2_RTS_O_MASK         (0xFFU)                                             /*!< LPC_SWM_PINASSIGN3: U2_RTS_O Mask       */
#define LPC_SWM_PINASSIGN3_U2_RTS_O_SHIFT        (0U)                                                /*!< LPC_SWM_PINASSIGN3: U2_RTS_O Position   */
#define LPC_SWM_PINASSIGN3_U2_RTS_O(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN3_U2_RTS_O_SHIFT))&LPC_SWM_PINASSIGN3_U2_RTS_O_MASK) /*!< LPC_SWM_PINASSIGN3                      */
#define LPC_SWM_PINASSIGN3_U2_CTS_I_MASK         (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN3: U2_CTS_I Mask       */
#define LPC_SWM_PINASSIGN3_U2_CTS_I_SHIFT        (8U)                                                /*!< LPC_SWM_PINASSIGN3: U2_CTS_I Position   */
#define LPC_SWM_PINASSIGN3_U2_CTS_I(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN3_U2_CTS_I_SHIFT))&LPC_SWM_PINASSIGN3_U2_CTS_I_MASK) /*!< LPC_SWM_PINASSIGN3                      */
#define LPC_SWM_PINASSIGN3_U2_SCLK_IO_MASK       (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN3: U2_SCLK_IO Mask     */
#define LPC_SWM_PINASSIGN3_U2_SCLK_IO_SHIFT      (16U)                                               /*!< LPC_SWM_PINASSIGN3: U2_SCLK_IO Position */
#define LPC_SWM_PINASSIGN3_U2_SCLK_IO(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN3_U2_SCLK_IO_SHIFT))&LPC_SWM_PINASSIGN3_U2_SCLK_IO_MASK) /*!< LPC_SWM_PINASSIGN3                      */
#define LPC_SWM_PINASSIGN3_SPI0_SCK_IO_MASK      (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN3: SPI0_SCK_IO Mask    */
#define LPC_SWM_PINASSIGN3_SPI0_SCK_IO_SHIFT     (24U)                                               /*!< LPC_SWM_PINASSIGN3: SPI0_SCK_IO Position*/
#define LPC_SWM_PINASSIGN3_SPI0_SCK_IO(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN3_SPI0_SCK_IO_SHIFT))&LPC_SWM_PINASSIGN3_SPI0_SCK_IO_MASK) /*!< LPC_SWM_PINASSIGN3                      */
/* ------- PINASSIGN4 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN4_SPI0_MOSI_IO_MASK     (0xFFU)                                             /*!< LPC_SWM_PINASSIGN4: SPI0_MOSI_IO Mask   */
#define LPC_SWM_PINASSIGN4_SPI0_MOSI_IO_SHIFT    (0U)                                                /*!< LPC_SWM_PINASSIGN4: SPI0_MOSI_IO Position*/
#define LPC_SWM_PINASSIGN4_SPI0_MOSI_IO(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN4_SPI0_MOSI_IO_SHIFT))&LPC_SWM_PINASSIGN4_SPI0_MOSI_IO_MASK) /*!< LPC_SWM_PINASSIGN4                      */
#define LPC_SWM_PINASSIGN4_SPI0_MISO_IO_MASK     (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN4: SPI0_MISO_IO Mask   */
#define LPC_SWM_PINASSIGN4_SPI0_MISO_IO_SHIFT    (8U)                                                /*!< LPC_SWM_PINASSIGN4: SPI0_MISO_IO Position*/
#define LPC_SWM_PINASSIGN4_SPI0_MISO_IO(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN4_SPI0_MISO_IO_SHIFT))&LPC_SWM_PINASSIGN4_SPI0_MISO_IO_MASK) /*!< LPC_SWM_PINASSIGN4                      */
#define LPC_SWM_PINASSIGN4_SPI0_SSEL0_IO_MASK    (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN4: SPI0_SSEL0_IO Mask  */
#define LPC_SWM_PINASSIGN4_SPI0_SSEL0_IO_SHIFT   (16U)                                               /*!< LPC_SWM_PINASSIGN4: SPI0_SSEL0_IO Position*/
#define LPC_SWM_PINASSIGN4_SPI0_SSEL0_IO(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN4_SPI0_SSEL0_IO_SHIFT))&LPC_SWM_PINASSIGN4_SPI0_SSEL0_IO_MASK) /*!< LPC_SWM_PINASSIGN4                      */
#define LPC_SWM_PINASSIGN4_SPI0_SSEL1_IO_MASK    (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN4: SPI0_SSEL1_IO Mask  */
#define LPC_SWM_PINASSIGN4_SPI0_SSEL1_IO_SHIFT   (24U)                                               /*!< LPC_SWM_PINASSIGN4: SPI0_SSEL1_IO Position*/
#define LPC_SWM_PINASSIGN4_SPI0_SSEL1_IO(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN4_SPI0_SSEL1_IO_SHIFT))&LPC_SWM_PINASSIGN4_SPI0_SSEL1_IO_MASK) /*!< LPC_SWM_PINASSIGN4                      */
/* ------- PINASSIGN5 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN5_SPI0_SSEL2_IO_MASK    (0xFFU)                                             /*!< LPC_SWM_PINASSIGN5: SPI0_SSEL2_IO Mask  */
#define LPC_SWM_PINASSIGN5_SPI0_SSEL2_IO_SHIFT   (0U)                                                /*!< LPC_SWM_PINASSIGN5: SPI0_SSEL2_IO Position*/
#define LPC_SWM_PINASSIGN5_SPI0_SSEL2_IO(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN5_SPI0_SSEL2_IO_SHIFT))&LPC_SWM_PINASSIGN5_SPI0_SSEL2_IO_MASK) /*!< LPC_SWM_PINASSIGN5                      */
#define LPC_SWM_PINASSIGN5_SPI0_SSEL3_IO_MASK    (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN5: SPI0_SSEL3_IO Mask  */
#define LPC_SWM_PINASSIGN5_SPI0_SSEL3_IO_SHIFT   (8U)                                                /*!< LPC_SWM_PINASSIGN5: SPI0_SSEL3_IO Position*/
#define LPC_SWM_PINASSIGN5_SPI0_SSEL3_IO(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN5_SPI0_SSEL3_IO_SHIFT))&LPC_SWM_PINASSIGN5_SPI0_SSEL3_IO_MASK) /*!< LPC_SWM_PINASSIGN5                      */
#define LPC_SWM_PINASSIGN5_SPI1_SCK_IO_MASK      (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN5: SPI1_SCK_IO Mask    */
#define LPC_SWM_PINASSIGN5_SPI1_SCK_IO_SHIFT     (16U)                                               /*!< LPC_SWM_PINASSIGN5: SPI1_SCK_IO Position*/
#define LPC_SWM_PINASSIGN5_SPI1_SCK_IO(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN5_SPI1_SCK_IO_SHIFT))&LPC_SWM_PINASSIGN5_SPI1_SCK_IO_MASK) /*!< LPC_SWM_PINASSIGN5                      */
#define LPC_SWM_PINASSIGN5_SPI1_MOSI_IO_MASK     (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN5: SPI1_MOSI_IO Mask   */
#define LPC_SWM_PINASSIGN5_SPI1_MOSI_IO_SHIFT    (24U)                                               /*!< LPC_SWM_PINASSIGN5: SPI1_MOSI_IO Position*/
#define LPC_SWM_PINASSIGN5_SPI1_MOSI_IO(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN5_SPI1_MOSI_IO_SHIFT))&LPC_SWM_PINASSIGN5_SPI1_MOSI_IO_MASK) /*!< LPC_SWM_PINASSIGN5                      */
/* ------- PINASSIGN6 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN6_SPI1_MISO_IO_MASK     (0xFFU)                                             /*!< LPC_SWM_PINASSIGN6: SPI1_MISO_IO Mask   */
#define LPC_SWM_PINASSIGN6_SPI1_MISO_IO_SHIFT    (0U)                                                /*!< LPC_SWM_PINASSIGN6: SPI1_MISO_IO Position*/
#define LPC_SWM_PINASSIGN6_SPI1_MISO_IO(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN6_SPI1_MISO_IO_SHIFT))&LPC_SWM_PINASSIGN6_SPI1_MISO_IO_MASK) /*!< LPC_SWM_PINASSIGN6                      */
#define LPC_SWM_PINASSIGN6_SPI1_SSEL0_IO_MASK    (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN6: SPI1_SSEL0_IO Mask  */
#define LPC_SWM_PINASSIGN6_SPI1_SSEL0_IO_SHIFT   (8U)                                                /*!< LPC_SWM_PINASSIGN6: SPI1_SSEL0_IO Position*/
#define LPC_SWM_PINASSIGN6_SPI1_SSEL0_IO(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN6_SPI1_SSEL0_IO_SHIFT))&LPC_SWM_PINASSIGN6_SPI1_SSEL0_IO_MASK) /*!< LPC_SWM_PINASSIGN6                      */
#define LPC_SWM_PINASSIGN6_SPI1_SSEL1_IO_MASK    (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN6: SPI1_SSEL1_IO Mask  */
#define LPC_SWM_PINASSIGN6_SPI1_SSEL1_IO_SHIFT   (16U)                                               /*!< LPC_SWM_PINASSIGN6: SPI1_SSEL1_IO Position*/
#define LPC_SWM_PINASSIGN6_SPI1_SSEL1_IO(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN6_SPI1_SSEL1_IO_SHIFT))&LPC_SWM_PINASSIGN6_SPI1_SSEL1_IO_MASK) /*!< LPC_SWM_PINASSIGN6                      */
#define LPC_SWM_PINASSIGN6_SCT_IN0_I_MASK        (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN6: SCT_IN0_I Mask      */
#define LPC_SWM_PINASSIGN6_SCT_IN0_I_SHIFT       (24U)                                               /*!< LPC_SWM_PINASSIGN6: SCT_IN0_I Position  */
#define LPC_SWM_PINASSIGN6_SCT_IN0_I(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN6_SCT_IN0_I_SHIFT))&LPC_SWM_PINASSIGN6_SCT_IN0_I_MASK) /*!< LPC_SWM_PINASSIGN6                      */
/* ------- PINASSIGN7 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN7_SCT_IN1_I_MASK        (0xFFU)                                             /*!< LPC_SWM_PINASSIGN7: SCT_IN1_I Mask      */
#define LPC_SWM_PINASSIGN7_SCT_IN1_I_SHIFT       (0U)                                                /*!< LPC_SWM_PINASSIGN7: SCT_IN1_I Position  */
#define LPC_SWM_PINASSIGN7_SCT_IN1_I(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN7_SCT_IN1_I_SHIFT))&LPC_SWM_PINASSIGN7_SCT_IN1_I_MASK) /*!< LPC_SWM_PINASSIGN7                      */
#define LPC_SWM_PINASSIGN7_SCT_IN2_I_MASK        (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN7: SCT_IN2_I Mask      */
#define LPC_SWM_PINASSIGN7_SCT_IN2_I_SHIFT       (8U)                                                /*!< LPC_SWM_PINASSIGN7: SCT_IN2_I Position  */
#define LPC_SWM_PINASSIGN7_SCT_IN2_I(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN7_SCT_IN2_I_SHIFT))&LPC_SWM_PINASSIGN7_SCT_IN2_I_MASK) /*!< LPC_SWM_PINASSIGN7                      */
#define LPC_SWM_PINASSIGN7_SCT_IN3_I_MASK        (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN7: SCT_IN3_I Mask      */
#define LPC_SWM_PINASSIGN7_SCT_IN3_I_SHIFT       (16U)                                               /*!< LPC_SWM_PINASSIGN7: SCT_IN3_I Position  */
#define LPC_SWM_PINASSIGN7_SCT_IN3_I(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN7_SCT_IN3_I_SHIFT))&LPC_SWM_PINASSIGN7_SCT_IN3_I_MASK) /*!< LPC_SWM_PINASSIGN7                      */
#define LPC_SWM_PINASSIGN7_SCT_OUT0_O_MASK       (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN7: SCT_OUT0_O Mask     */
#define LPC_SWM_PINASSIGN7_SCT_OUT0_O_SHIFT      (24U)                                               /*!< LPC_SWM_PINASSIGN7: SCT_OUT0_O Position */
#define LPC_SWM_PINASSIGN7_SCT_OUT0_O(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN7_SCT_OUT0_O_SHIFT))&LPC_SWM_PINASSIGN7_SCT_OUT0_O_MASK) /*!< LPC_SWM_PINASSIGN7                      */
/* ------- PINASSIGN8 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN8_SCT_OUT1_O_MASK       (0xFFU)                                             /*!< LPC_SWM_PINASSIGN8: SCT_OUT1_O Mask     */
#define LPC_SWM_PINASSIGN8_SCT_OUT1_O_SHIFT      (0U)                                                /*!< LPC_SWM_PINASSIGN8: SCT_OUT1_O Position */
#define LPC_SWM_PINASSIGN8_SCT_OUT1_O(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN8_SCT_OUT1_O_SHIFT))&LPC_SWM_PINASSIGN8_SCT_OUT1_O_MASK) /*!< LPC_SWM_PINASSIGN8                      */
#define LPC_SWM_PINASSIGN8_SCT_OUT2_O_MASK       (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN8: SCT_OUT2_O Mask     */
#define LPC_SWM_PINASSIGN8_SCT_OUT2_O_SHIFT      (8U)                                                /*!< LPC_SWM_PINASSIGN8: SCT_OUT2_O Position */
#define LPC_SWM_PINASSIGN8_SCT_OUT2_O(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN8_SCT_OUT2_O_SHIFT))&LPC_SWM_PINASSIGN8_SCT_OUT2_O_MASK) /*!< LPC_SWM_PINASSIGN8                      */
#define LPC_SWM_PINASSIGN8_SCT_OUT3_O_MASK       (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN8: SCT_OUT3_O Mask     */
#define LPC_SWM_PINASSIGN8_SCT_OUT3_O_SHIFT      (16U)                                               /*!< LPC_SWM_PINASSIGN8: SCT_OUT3_O Position */
#define LPC_SWM_PINASSIGN8_SCT_OUT3_O(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN8_SCT_OUT3_O_SHIFT))&LPC_SWM_PINASSIGN8_SCT_OUT3_O_MASK) /*!< LPC_SWM_PINASSIGN8                      */
#define LPC_SWM_PINASSIGN8_SCT_OUT4_O_MASK       (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN8: SCT_OUT4_O Mask     */
#define LPC_SWM_PINASSIGN8_SCT_OUT4_O_SHIFT      (24U)                                               /*!< LPC_SWM_PINASSIGN8: SCT_OUT4_O Position */
#define LPC_SWM_PINASSIGN8_SCT_OUT4_O(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN8_SCT_OUT4_O_SHIFT))&LPC_SWM_PINASSIGN8_SCT_OUT4_O_MASK) /*!< LPC_SWM_PINASSIGN8                      */
/* ------- PINASSIGN9 Bit Fields                    ------ */
#define LPC_SWM_PINASSIGN9_SCT_OUT5_O_MASK       (0xFFU)                                             /*!< LPC_SWM_PINASSIGN9: SCT_OUT5_O Mask     */
#define LPC_SWM_PINASSIGN9_SCT_OUT5_O_SHIFT      (0U)                                                /*!< LPC_SWM_PINASSIGN9: SCT_OUT5_O Position */
#define LPC_SWM_PINASSIGN9_SCT_OUT5_O(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN9_SCT_OUT5_O_SHIFT))&LPC_SWM_PINASSIGN9_SCT_OUT5_O_MASK) /*!< LPC_SWM_PINASSIGN9                      */
#define LPC_SWM_PINASSIGN9_I2C1_SDA_IO_MASK      (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN9: I2C1_SDA_IO Mask    */
#define LPC_SWM_PINASSIGN9_I2C1_SDA_IO_SHIFT     (8U)                                                /*!< LPC_SWM_PINASSIGN9: I2C1_SDA_IO Position*/
#define LPC_SWM_PINASSIGN9_I2C1_SDA_IO(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN9_I2C1_SDA_IO_SHIFT))&LPC_SWM_PINASSIGN9_I2C1_SDA_IO_MASK) /*!< LPC_SWM_PINASSIGN9                      */
#define LPC_SWM_PINASSIGN9_I2C1_SCL_IO_MASK      (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN9: I2C1_SCL_IO Mask    */
#define LPC_SWM_PINASSIGN9_I2C1_SCL_IO_SHIFT     (16U)                                               /*!< LPC_SWM_PINASSIGN9: I2C1_SCL_IO Position*/
#define LPC_SWM_PINASSIGN9_I2C1_SCL_IO(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN9_I2C1_SCL_IO_SHIFT))&LPC_SWM_PINASSIGN9_I2C1_SCL_IO_MASK) /*!< LPC_SWM_PINASSIGN9                      */
#define LPC_SWM_PINASSIGN9_I2C2_SDA_IO_MASK      (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN9: I2C2_SDA_IO Mask    */
#define LPC_SWM_PINASSIGN9_I2C2_SDA_IO_SHIFT     (24U)                                               /*!< LPC_SWM_PINASSIGN9: I2C2_SDA_IO Position*/
#define LPC_SWM_PINASSIGN9_I2C2_SDA_IO(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN9_I2C2_SDA_IO_SHIFT))&LPC_SWM_PINASSIGN9_I2C2_SDA_IO_MASK) /*!< LPC_SWM_PINASSIGN9                      */
/* ------- PINASSIGN10 Bit Fields                   ------ */
#define LPC_SWM_PINASSIGN10_I2C2_SCL_IO_MASK     (0xFFU)                                             /*!< LPC_SWM_PINASSIGN10: I2C2_SCL_IO Mask   */
#define LPC_SWM_PINASSIGN10_I2C2_SCL_IO_SHIFT    (0U)                                                /*!< LPC_SWM_PINASSIGN10: I2C2_SCL_IO Position*/
#define LPC_SWM_PINASSIGN10_I2C2_SCL_IO(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN10_I2C2_SCL_IO_SHIFT))&LPC_SWM_PINASSIGN10_I2C2_SCL_IO_MASK) /*!< LPC_SWM_PINASSIGN10                     */
#define LPC_SWM_PINASSIGN10_I2C3_SDA_IO_MASK     (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN10: I2C3_SDA_IO Mask   */
#define LPC_SWM_PINASSIGN10_I2C3_SDA_IO_SHIFT    (8U)                                                /*!< LPC_SWM_PINASSIGN10: I2C3_SDA_IO Position*/
#define LPC_SWM_PINASSIGN10_I2C3_SDA_IO(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN10_I2C3_SDA_IO_SHIFT))&LPC_SWM_PINASSIGN10_I2C3_SDA_IO_MASK) /*!< LPC_SWM_PINASSIGN10                     */
#define LPC_SWM_PINASSIGN10_I2C3_SCL_IO_MASK     (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN10: I2C3_SCL_IO Mask   */
#define LPC_SWM_PINASSIGN10_I2C3_SCL_IO_SHIFT    (16U)                                               /*!< LPC_SWM_PINASSIGN10: I2C3_SCL_IO Position*/
#define LPC_SWM_PINASSIGN10_I2C3_SCL_IO(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN10_I2C3_SCL_IO_SHIFT))&LPC_SWM_PINASSIGN10_I2C3_SCL_IO_MASK) /*!< LPC_SWM_PINASSIGN10                     */
#define LPC_SWM_PINASSIGN10_ADC_PINTRIG0_I_MASK  (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN10: ADC_PINTRIG0_I Mask*/
#define LPC_SWM_PINASSIGN10_ADC_PINTRIG0_I_SHIFT (24U)                                               /*!< LPC_SWM_PINASSIGN10: ADC_PINTRIG0_I Position*/
#define LPC_SWM_PINASSIGN10_ADC_PINTRIG0_I(x)    (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN10_ADC_PINTRIG0_I_SHIFT))&LPC_SWM_PINASSIGN10_ADC_PINTRIG0_I_MASK) /*!< LPC_SWM_PINASSIGN10                     */
/* ------- PINASSIGN11 Bit Fields                   ------ */
#define LPC_SWM_PINASSIGN11_ADC_PINTRIG1_I_MASK  (0xFFU)                                             /*!< LPC_SWM_PINASSIGN11: ADC_PINTRIG1_I Mask*/
#define LPC_SWM_PINASSIGN11_ADC_PINTRIG1_I_SHIFT (0U)                                                /*!< LPC_SWM_PINASSIGN11: ADC_PINTRIG1_I Position*/
#define LPC_SWM_PINASSIGN11_ADC_PINTRIG1_I(x)    (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN11_ADC_PINTRIG1_I_SHIFT))&LPC_SWM_PINASSIGN11_ADC_PINTRIG1_I_MASK) /*!< LPC_SWM_PINASSIGN11                     */
#define LPC_SWM_PINASSIGN11_ACMP_O_O_MASK        (0xFF00U)                                           /*!< LPC_SWM_PINASSIGN11: ACMP_O_O Mask      */
#define LPC_SWM_PINASSIGN11_ACMP_O_O_SHIFT       (8U)                                                /*!< LPC_SWM_PINASSIGN11: ACMP_O_O Position  */
#define LPC_SWM_PINASSIGN11_ACMP_O_O(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN11_ACMP_O_O_SHIFT))&LPC_SWM_PINASSIGN11_ACMP_O_O_MASK) /*!< LPC_SWM_PINASSIGN11                     */
#define LPC_SWM_PINASSIGN11_CLKOUT_O_MASK        (0xFF0000U)                                         /*!< LPC_SWM_PINASSIGN11: CLKOUT_O Mask      */
#define LPC_SWM_PINASSIGN11_CLKOUT_O_SHIFT       (16U)                                               /*!< LPC_SWM_PINASSIGN11: CLKOUT_O Position  */
#define LPC_SWM_PINASSIGN11_CLKOUT_O(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN11_CLKOUT_O_SHIFT))&LPC_SWM_PINASSIGN11_CLKOUT_O_MASK) /*!< LPC_SWM_PINASSIGN11                     */
#define LPC_SWM_PINASSIGN11_GPIO_INT_BMAT_O_MASK (0xFF000000U)                                       /*!< LPC_SWM_PINASSIGN11: GPIO_INT_BMAT_O Mask*/
#define LPC_SWM_PINASSIGN11_GPIO_INT_BMAT_O_SHIFT (24U)                                              /*!< LPC_SWM_PINASSIGN11: GPIO_INT_BMAT_O Position*/
#define LPC_SWM_PINASSIGN11_GPIO_INT_BMAT_O(x)   (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINASSIGN11_GPIO_INT_BMAT_O_SHIFT))&LPC_SWM_PINASSIGN11_GPIO_INT_BMAT_O_MASK) /*!< LPC_SWM_PINASSIGN11                     */
/* ------- PINENABLE0 Bit Fields                    ------ */
#define LPC_SWM_PINENABLE0_ACMP_I1_MASK          (0x1U)                                              /*!< LPC_SWM_PINENABLE0: ACMP_I1 Mask        */
#define LPC_SWM_PINENABLE0_ACMP_I1_SHIFT         (0U)                                                /*!< LPC_SWM_PINENABLE0: ACMP_I1 Position    */
#define LPC_SWM_PINENABLE0_ACMP_I1(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ACMP_I1_SHIFT))&LPC_SWM_PINENABLE0_ACMP_I1_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ACMP_I2_MASK          (0x2U)                                              /*!< LPC_SWM_PINENABLE0: ACMP_I2 Mask        */
#define LPC_SWM_PINENABLE0_ACMP_I2_SHIFT         (1U)                                                /*!< LPC_SWM_PINENABLE0: ACMP_I2 Position    */
#define LPC_SWM_PINENABLE0_ACMP_I2(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ACMP_I2_SHIFT))&LPC_SWM_PINENABLE0_ACMP_I2_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ACMP_I3_MASK          (0x4U)                                              /*!< LPC_SWM_PINENABLE0: ACMP_I3 Mask        */
#define LPC_SWM_PINENABLE0_ACMP_I3_SHIFT         (2U)                                                /*!< LPC_SWM_PINENABLE0: ACMP_I3 Position    */
#define LPC_SWM_PINENABLE0_ACMP_I3(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ACMP_I3_SHIFT))&LPC_SWM_PINENABLE0_ACMP_I3_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ACMP_I4_MASK          (0x8U)                                              /*!< LPC_SWM_PINENABLE0: ACMP_I4 Mask        */
#define LPC_SWM_PINENABLE0_ACMP_I4_SHIFT         (3U)                                                /*!< LPC_SWM_PINENABLE0: ACMP_I4 Position    */
#define LPC_SWM_PINENABLE0_ACMP_I4(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ACMP_I4_SHIFT))&LPC_SWM_PINENABLE0_ACMP_I4_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_SWCLK_MASK            (0x10U)                                             /*!< LPC_SWM_PINENABLE0: SWCLK Mask          */
#define LPC_SWM_PINENABLE0_SWCLK_SHIFT           (4U)                                                /*!< LPC_SWM_PINENABLE0: SWCLK Position      */
#define LPC_SWM_PINENABLE0_SWCLK(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_SWCLK_SHIFT))&LPC_SWM_PINENABLE0_SWCLK_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_SWDIO_MASK            (0x20U)                                             /*!< LPC_SWM_PINENABLE0: SWDIO Mask          */
#define LPC_SWM_PINENABLE0_SWDIO_SHIFT           (5U)                                                /*!< LPC_SWM_PINENABLE0: SWDIO Position      */
#define LPC_SWM_PINENABLE0_SWDIO(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_SWDIO_SHIFT))&LPC_SWM_PINENABLE0_SWDIO_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_XTALIN_MASK           (0x40U)                                             /*!< LPC_SWM_PINENABLE0: XTALIN Mask         */
#define LPC_SWM_PINENABLE0_XTALIN_SHIFT          (6U)                                                /*!< LPC_SWM_PINENABLE0: XTALIN Position     */
#define LPC_SWM_PINENABLE0_XTALIN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_XTALIN_SHIFT))&LPC_SWM_PINENABLE0_XTALIN_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_XTALOUT_MASK          (0x80U)                                             /*!< LPC_SWM_PINENABLE0: XTALOUT Mask        */
#define LPC_SWM_PINENABLE0_XTALOUT_SHIFT         (7U)                                                /*!< LPC_SWM_PINENABLE0: XTALOUT Position    */
#define LPC_SWM_PINENABLE0_XTALOUT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_XTALOUT_SHIFT))&LPC_SWM_PINENABLE0_XTALOUT_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_RESETN_MASK           (0x100U)                                            /*!< LPC_SWM_PINENABLE0: RESETN Mask         */
#define LPC_SWM_PINENABLE0_RESETN_SHIFT          (8U)                                                /*!< LPC_SWM_PINENABLE0: RESETN Position     */
#define LPC_SWM_PINENABLE0_RESETN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_RESETN_SHIFT))&LPC_SWM_PINENABLE0_RESETN_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_CLKIN_MASK            (0x200U)                                            /*!< LPC_SWM_PINENABLE0: CLKIN Mask          */
#define LPC_SWM_PINENABLE0_CLKIN_SHIFT           (9U)                                                /*!< LPC_SWM_PINENABLE0: CLKIN Position      */
#define LPC_SWM_PINENABLE0_CLKIN(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_CLKIN_SHIFT))&LPC_SWM_PINENABLE0_CLKIN_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_VDDCMP_MASK           (0x400U)                                            /*!< LPC_SWM_PINENABLE0: VDDCMP Mask         */
#define LPC_SWM_PINENABLE0_VDDCMP_SHIFT          (10U)                                               /*!< LPC_SWM_PINENABLE0: VDDCMP Position     */
#define LPC_SWM_PINENABLE0_VDDCMP(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_VDDCMP_SHIFT))&LPC_SWM_PINENABLE0_VDDCMP_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_I2C0_SDA_MASK         (0x800U)                                            /*!< LPC_SWM_PINENABLE0: I2C0_SDA Mask       */
#define LPC_SWM_PINENABLE0_I2C0_SDA_SHIFT        (11U)                                               /*!< LPC_SWM_PINENABLE0: I2C0_SDA Position   */
#define LPC_SWM_PINENABLE0_I2C0_SDA(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_I2C0_SDA_SHIFT))&LPC_SWM_PINENABLE0_I2C0_SDA_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_I2C0_SCL_MASK         (0x1000U)                                           /*!< LPC_SWM_PINENABLE0: I2C0_SCL Mask       */
#define LPC_SWM_PINENABLE0_I2C0_SCL_SHIFT        (12U)                                               /*!< LPC_SWM_PINENABLE0: I2C0_SCL Position   */
#define LPC_SWM_PINENABLE0_I2C0_SCL(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_I2C0_SCL_SHIFT))&LPC_SWM_PINENABLE0_I2C0_SCL_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_0_MASK            (0x2000U)                                           /*!< LPC_SWM_PINENABLE0: ADC_0 Mask          */
#define LPC_SWM_PINENABLE0_ADC_0_SHIFT           (13U)                                               /*!< LPC_SWM_PINENABLE0: ADC_0 Position      */
#define LPC_SWM_PINENABLE0_ADC_0(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_0_SHIFT))&LPC_SWM_PINENABLE0_ADC_0_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_1_MASK            (0x4000U)                                           /*!< LPC_SWM_PINENABLE0: ADC_1 Mask          */
#define LPC_SWM_PINENABLE0_ADC_1_SHIFT           (14U)                                               /*!< LPC_SWM_PINENABLE0: ADC_1 Position      */
#define LPC_SWM_PINENABLE0_ADC_1(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_1_SHIFT))&LPC_SWM_PINENABLE0_ADC_1_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_2_MASK            (0x8000U)                                           /*!< LPC_SWM_PINENABLE0: ADC_2 Mask          */
#define LPC_SWM_PINENABLE0_ADC_2_SHIFT           (15U)                                               /*!< LPC_SWM_PINENABLE0: ADC_2 Position      */
#define LPC_SWM_PINENABLE0_ADC_2(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_2_SHIFT))&LPC_SWM_PINENABLE0_ADC_2_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_3_MASK            (0x10000U)                                          /*!< LPC_SWM_PINENABLE0: ADC_3 Mask          */
#define LPC_SWM_PINENABLE0_ADC_3_SHIFT           (16U)                                               /*!< LPC_SWM_PINENABLE0: ADC_3 Position      */
#define LPC_SWM_PINENABLE0_ADC_3(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_3_SHIFT))&LPC_SWM_PINENABLE0_ADC_3_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_4_MASK            (0x20000U)                                          /*!< LPC_SWM_PINENABLE0: ADC_4 Mask          */
#define LPC_SWM_PINENABLE0_ADC_4_SHIFT           (17U)                                               /*!< LPC_SWM_PINENABLE0: ADC_4 Position      */
#define LPC_SWM_PINENABLE0_ADC_4(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_4_SHIFT))&LPC_SWM_PINENABLE0_ADC_4_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_5_MASK            (0x40000U)                                          /*!< LPC_SWM_PINENABLE0: ADC_5 Mask          */
#define LPC_SWM_PINENABLE0_ADC_5_SHIFT           (18U)                                               /*!< LPC_SWM_PINENABLE0: ADC_5 Position      */
#define LPC_SWM_PINENABLE0_ADC_5(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_5_SHIFT))&LPC_SWM_PINENABLE0_ADC_5_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_6_MASK            (0x80000U)                                          /*!< LPC_SWM_PINENABLE0: ADC_6 Mask          */
#define LPC_SWM_PINENABLE0_ADC_6_SHIFT           (19U)                                               /*!< LPC_SWM_PINENABLE0: ADC_6 Position      */
#define LPC_SWM_PINENABLE0_ADC_6(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_6_SHIFT))&LPC_SWM_PINENABLE0_ADC_6_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_7_MASK            (0x100000U)                                         /*!< LPC_SWM_PINENABLE0: ADC_7 Mask          */
#define LPC_SWM_PINENABLE0_ADC_7_SHIFT           (20U)                                               /*!< LPC_SWM_PINENABLE0: ADC_7 Position      */
#define LPC_SWM_PINENABLE0_ADC_7(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_7_SHIFT))&LPC_SWM_PINENABLE0_ADC_7_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_8_MASK            (0x200000U)                                         /*!< LPC_SWM_PINENABLE0: ADC_8 Mask          */
#define LPC_SWM_PINENABLE0_ADC_8_SHIFT           (21U)                                               /*!< LPC_SWM_PINENABLE0: ADC_8 Position      */
#define LPC_SWM_PINENABLE0_ADC_8(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_8_SHIFT))&LPC_SWM_PINENABLE0_ADC_8_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_9_MASK            (0x400000U)                                         /*!< LPC_SWM_PINENABLE0: ADC_9 Mask          */
#define LPC_SWM_PINENABLE0_ADC_9_SHIFT           (22U)                                               /*!< LPC_SWM_PINENABLE0: ADC_9 Position      */
#define LPC_SWM_PINENABLE0_ADC_9(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_9_SHIFT))&LPC_SWM_PINENABLE0_ADC_9_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_10_MASK           (0x800000U)                                         /*!< LPC_SWM_PINENABLE0: ADC_10 Mask         */
#define LPC_SWM_PINENABLE0_ADC_10_SHIFT          (23U)                                               /*!< LPC_SWM_PINENABLE0: ADC_10 Position     */
#define LPC_SWM_PINENABLE0_ADC_10(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_10_SHIFT))&LPC_SWM_PINENABLE0_ADC_10_MASK) /*!< LPC_SWM_PINENABLE0                      */
#define LPC_SWM_PINENABLE0_ADC_11_MASK           (0x1000000U)                                        /*!< LPC_SWM_PINENABLE0: ADC_11 Mask         */
#define LPC_SWM_PINENABLE0_ADC_11_SHIFT          (24U)                                               /*!< LPC_SWM_PINENABLE0: ADC_11 Position     */
#define LPC_SWM_PINENABLE0_ADC_11(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SWM_PINENABLE0_ADC_11_SHIFT))&LPC_SWM_PINENABLE0_ADC_11_MASK) /*!< LPC_SWM_PINENABLE0                      */
/**
 * @} */ /* End group SWM_Register_Masks_GROUP 
 */

/* LPC_SWM - Peripheral instance base addresses */
#define LPC_SWM_BasePtr                0x4000C000UL //!< Peripheral base address
#define LPC_SWM                        ((LPC_SWM_Type *) LPC_SWM_BasePtr) //!< Freescale base pointer
#define LPC_SWM_BASE_PTR               (LPC_SWM) //!< Freescale style base pointer
/**
 * @} */ /* End group SWM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SYSCON_Peripheral_access_layer_GROUP SYSCON Peripheral Access Layer
* @brief C Struct for SYSCON
* @{
*/

/* ================================================================================ */
/* ================           LPC_SYSCON (file:SYSCON_LPC82x)       ================ */
/* ================================================================================ */

/**
 * @brief System configuration
 */
/**
* @addtogroup SYSCON_structs_GROUP SYSCON struct
* @brief Struct for SYSCON
* @{
*/
typedef struct {                                /*       LPC_SYSCON Structure                                         */
   __IO uint32_t  SYSMEMREMAP;                  /**< 0000: System memory remap                                          */
   __IO uint32_t  PRESETCTRL;                   /**< 0004: Peripheral reset control                                     */
   __IO uint32_t  SYSPLLCTRL;                   /**< 0008: System PLL control                                           */
   __I  uint32_t  SYSPLLSTAT;                   /**< 000C: System PLL status                                            */
        uint8_t   RESERVED_0[16];              
   __IO uint32_t  SYSOSCCTRL;                   /**< 0020: System oscillator control                                    */
   __IO uint32_t  WDTOSCCTRL;                   /**< 0024: Watchdog oscillator control                                  */
   __IO uint32_t  IRCCTRL;                      /**< 0028: IRC control                                                  */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  SYSRSTSTAT;                   /**< 0030: System reset status register                                 */
        uint8_t   RESERVED_2[12];              
   __IO uint32_t  SYSPLLCLKSEL;                 /**< 0040: System PLL clock source select                               */
   __IO uint32_t  SYSPLLCLKUEN;                 /**< 0044: System PLL clock source update enable                        */
        uint8_t   RESERVED_3[40];              
   __IO uint32_t  MAINCLKSEL;                   /**< 0070: Main clock source select                                     */
   __IO uint32_t  MAINCLKUEN;                   /**< 0074: Main clock source update enable                              */
   __IO uint32_t  SYSAHBCLKDIV;                 /**< 0078: System clock divider                                         */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  SYSAHBCLKCTRL;                /**< 0080: System clock control                                         */
        uint8_t   RESERVED_5[16];              
   __IO uint32_t  UARTCLKDIV;                   /**< 0094: USART clock divider                                          */
        uint8_t   RESERVED_6[72];              
   __IO uint32_t  CLKOUTSEL;                    /**< 00E0: CLKOUT clock source select                                   */
   __IO uint32_t  CLKOUTUEN;                    /**< 00E4: CLKOUT clock source update enable                            */
   __IO uint32_t  CLKOUTDIV;                    /**< 00E8: CLKOUT clock divider                                         */
        uint8_t   RESERVED_7[4];               
   __IO uint32_t  UARTFRGDIV;                   /**< 00F0: USART1 to USART4 common fractional generator divider value   */
   __IO uint32_t  UARTFRGMULT;                  /**< 00F4: USART1 to USART4 common fractional generator multiplier value */
        uint8_t   RESERVED_8[4];               
   __IO uint32_t  EXTTRACECMD;                  /**< 00FC: External trace buffer command register                       */
   __I  uint32_t  PIOPORCAP0;                   /**< 0100: POR captured PIO status 0                                    */
        uint8_t   RESERVED_9[48];              
   __IO uint32_t  IOCONCLKDIV6;                 /**< 0134: Peripheral clock 6 to the IOCON block for programmable glitch filter */
        uint8_t   RESERVED_10[24];             
   __IO uint32_t  BODCTRL;                      /**< 0150: Brown-Out Detect                                             */
   __IO uint32_t  SYSTCKCAL;                    /**< 0154: System tick counter calibration                              */
        uint8_t   RESERVED_11[24];             
   __IO uint32_t  IRQLATENCY;                   /**< 0170: IQR delay. Allows trade-off between interrupt latency and determinism */
   __IO uint32_t  NMISRC;                       /**< 0174: NMI Source Control                                           */
   __IO uint32_t  PINTSEL0;                     /**< 0178: GPIO Pin Interrupt Select register 0                         */
   __IO uint32_t  PINTSEL1;                     /**< 017C: GPIO Pin Interrupt Select register 0                         */
   __IO uint32_t  PINTSEL2;                     /**< 0180: GPIO Pin Interrupt Select register 0                         */
   __IO uint32_t  PINTSEL3;                     /**< 0184: GPIO Pin Interrupt Select register 0                         */
   __IO uint32_t  PINTSEL4;                     /**< 0188: GPIO Pin Interrupt Select register 0                         */
   __IO uint32_t  PINTSEL5;                     /**< 018C: GPIO Pin Interrupt Select register 0                         */
   __IO uint32_t  PINTSEL6;                     /**< 0190: GPIO Pin Interrupt Select register 0                         */
   __IO uint32_t  PINTSEL7;                     /**< 0194: GPIO Pin Interrupt Select register 0                         */
        uint8_t   RESERVED_12[108];            
   __IO uint32_t  STARTERP0;                    /**< 0204: Start logic 0 pin wake-up enable register                    */
        uint8_t   RESERVED_13[12];             
   __IO uint32_t  STARTERP1;                    /**< 0214: Start logic 1 interrupt wake-up enable register              */
        uint8_t   RESERVED_14[24];             
   __IO uint32_t  PDSLEEPCFG;                   /**< 0230: Power-down states in deep-sleep mode                         */
   __IO uint32_t  PDAWAKECFG;                   /**< 0234: Power-down states for wake-up from deep-sleep                */
   __IO uint32_t  PDRUNCFG;                     /**< 0238: Power configuration register                                 */
        uint8_t   RESERVED_15[444];            
   __I  uint32_t  DEVICE_ID;                    /**< 03F8: Device ID                                                    */
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
#define LPC_SYSCON_SYSMEMREMAP_MAP_MASK          (0x3U)                                              /*!< LPC_SYSCON_SYSMEMREMAP: MAP Mask        */
#define LPC_SYSCON_SYSMEMREMAP_MAP_SHIFT         (0U)                                                /*!< LPC_SYSCON_SYSMEMREMAP: MAP Position    */
#define LPC_SYSCON_SYSMEMREMAP_MAP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSMEMREMAP_MAP_SHIFT))&LPC_SYSCON_SYSMEMREMAP_MAP_MASK) /*!< LPC_SYSCON_SYSMEMREMAP                  */
/* ------- PRESETCTRL Bit Fields                    ------ */
#define LPC_SYSCON_PRESETCTRL_SPI0_RST_N_MASK    (0x1U)                                              /*!< LPC_SYSCON_PRESETCTRL: SPI0_RST_N Mask  */
#define LPC_SYSCON_PRESETCTRL_SPI0_RST_N_SHIFT   (0U)                                                /*!< LPC_SYSCON_PRESETCTRL: SPI0_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_SPI0_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_SPI0_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_SPI0_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_SPI1_RST_N_MASK    (0x2U)                                              /*!< LPC_SYSCON_PRESETCTRL: SPI1_RST_N Mask  */
#define LPC_SYSCON_PRESETCTRL_SPI1_RST_N_SHIFT   (1U)                                                /*!< LPC_SYSCON_PRESETCTRL: SPI1_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_SPI1_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_SPI1_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_SPI1_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_UARTFRG_RST_N_MASK (0x4U)                                              /*!< LPC_SYSCON_PRESETCTRL: UARTFRG_RST_N Mask*/
#define LPC_SYSCON_PRESETCTRL_UARTFRG_RST_N_SHIFT (2U)                                               /*!< LPC_SYSCON_PRESETCTRL: UARTFRG_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_UARTFRG_RST_N(x)   (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_UARTFRG_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_UARTFRG_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_UART0_RST_N_MASK   (0x8U)                                              /*!< LPC_SYSCON_PRESETCTRL: UART0_RST_N Mask */
#define LPC_SYSCON_PRESETCTRL_UART0_RST_N_SHIFT  (3U)                                                /*!< LPC_SYSCON_PRESETCTRL: UART0_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_UART0_RST_N(x)     (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_UART0_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_UART0_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_UART1_RST_N_MASK   (0x10U)                                             /*!< LPC_SYSCON_PRESETCTRL: UART1_RST_N Mask */
#define LPC_SYSCON_PRESETCTRL_UART1_RST_N_SHIFT  (4U)                                                /*!< LPC_SYSCON_PRESETCTRL: UART1_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_UART1_RST_N(x)     (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_UART1_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_UART1_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_UART2_RST_N_MASK   (0x20U)                                             /*!< LPC_SYSCON_PRESETCTRL: UART2_RST_N Mask */
#define LPC_SYSCON_PRESETCTRL_UART2_RST_N_SHIFT  (5U)                                                /*!< LPC_SYSCON_PRESETCTRL: UART2_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_UART2_RST_N(x)     (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_UART2_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_UART2_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_I2C0_RST_N_MASK    (0x40U)                                             /*!< LPC_SYSCON_PRESETCTRL: I2C0_RST_N Mask  */
#define LPC_SYSCON_PRESETCTRL_I2C0_RST_N_SHIFT   (6U)                                                /*!< LPC_SYSCON_PRESETCTRL: I2C0_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_I2C0_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_I2C0_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_I2C0_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_MRT_RST_N_MASK     (0x80U)                                             /*!< LPC_SYSCON_PRESETCTRL: MRT_RST_N Mask   */
#define LPC_SYSCON_PRESETCTRL_MRT_RST_N_SHIFT    (7U)                                                /*!< LPC_SYSCON_PRESETCTRL: MRT_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_MRT_RST_N(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_MRT_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_MRT_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_SCT_RST_N_MASK     (0x100U)                                            /*!< LPC_SYSCON_PRESETCTRL: SCT_RST_N Mask   */
#define LPC_SYSCON_PRESETCTRL_SCT_RST_N_SHIFT    (8U)                                                /*!< LPC_SYSCON_PRESETCTRL: SCT_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_SCT_RST_N(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_SCT_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_SCT_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_WKT_RST_N_MASK     (0x200U)                                            /*!< LPC_SYSCON_PRESETCTRL: WKT_RST_N Mask   */
#define LPC_SYSCON_PRESETCTRL_WKT_RST_N_SHIFT    (9U)                                                /*!< LPC_SYSCON_PRESETCTRL: WKT_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_WKT_RST_N(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_WKT_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_WKT_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_GPIO_RST_N_MASK    (0x400U)                                            /*!< LPC_SYSCON_PRESETCTRL: GPIO_RST_N Mask  */
#define LPC_SYSCON_PRESETCTRL_GPIO_RST_N_SHIFT   (10U)                                               /*!< LPC_SYSCON_PRESETCTRL: GPIO_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_GPIO_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_GPIO_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_GPIO_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_FLASH_RST_N_MASK   (0x800U)                                            /*!< LPC_SYSCON_PRESETCTRL: FLASH_RST_N Mask */
#define LPC_SYSCON_PRESETCTRL_FLASH_RST_N_SHIFT  (11U)                                               /*!< LPC_SYSCON_PRESETCTRL: FLASH_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_FLASH_RST_N(x)     (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_FLASH_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_FLASH_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_ACMP_RST_N_MASK    (0x1000U)                                           /*!< LPC_SYSCON_PRESETCTRL: ACMP_RST_N Mask  */
#define LPC_SYSCON_PRESETCTRL_ACMP_RST_N_SHIFT   (12U)                                               /*!< LPC_SYSCON_PRESETCTRL: ACMP_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_ACMP_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_ACMP_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_ACMP_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_I2C1_RST_N_MASK    (0x4000U)                                           /*!< LPC_SYSCON_PRESETCTRL: I2C1_RST_N Mask  */
#define LPC_SYSCON_PRESETCTRL_I2C1_RST_N_SHIFT   (14U)                                               /*!< LPC_SYSCON_PRESETCTRL: I2C1_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_I2C1_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_I2C1_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_I2C1_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_I2C2_RST_N_MASK    (0x8000U)                                           /*!< LPC_SYSCON_PRESETCTRL: I2C2_RST_N Mask  */
#define LPC_SYSCON_PRESETCTRL_I2C2_RST_N_SHIFT   (15U)                                               /*!< LPC_SYSCON_PRESETCTRL: I2C2_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_I2C2_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_I2C2_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_I2C2_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
#define LPC_SYSCON_PRESETCTRL_I2C3_RST_N_MASK    (0x10000U)                                          /*!< LPC_SYSCON_PRESETCTRL: I2C3_RST_N Mask  */
#define LPC_SYSCON_PRESETCTRL_I2C3_RST_N_SHIFT   (16U)                                               /*!< LPC_SYSCON_PRESETCTRL: I2C3_RST_N Position*/
#define LPC_SYSCON_PRESETCTRL_I2C3_RST_N(x)      (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PRESETCTRL_I2C3_RST_N_SHIFT))&LPC_SYSCON_PRESETCTRL_I2C3_RST_N_MASK) /*!< LPC_SYSCON_PRESETCTRL                   */
/* ------- SYSPLLCTRL Bit Fields                    ------ */
#define LPC_SYSCON_SYSPLLCTRL_MSEL_MASK          (0x1FU)                                             /*!< LPC_SYSCON_SYSPLLCTRL: MSEL Mask        */
#define LPC_SYSCON_SYSPLLCTRL_MSEL_SHIFT         (0U)                                                /*!< LPC_SYSCON_SYSPLLCTRL: MSEL Position    */
#define LPC_SYSCON_SYSPLLCTRL_MSEL(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLCTRL_MSEL_SHIFT))&LPC_SYSCON_SYSPLLCTRL_MSEL_MASK) /*!< LPC_SYSCON_SYSPLLCTRL                   */
#define LPC_SYSCON_SYSPLLCTRL_PSEL_MASK          (0x60U)                                             /*!< LPC_SYSCON_SYSPLLCTRL: PSEL Mask        */
#define LPC_SYSCON_SYSPLLCTRL_PSEL_SHIFT         (5U)                                                /*!< LPC_SYSCON_SYSPLLCTRL: PSEL Position    */
#define LPC_SYSCON_SYSPLLCTRL_PSEL(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLCTRL_PSEL_SHIFT))&LPC_SYSCON_SYSPLLCTRL_PSEL_MASK) /*!< LPC_SYSCON_SYSPLLCTRL                   */
/* ------- SYSPLLSTAT Bit Fields                    ------ */
#define LPC_SYSCON_SYSPLLSTAT_LOCK_MASK          (0x1U)                                              /*!< LPC_SYSCON_SYSPLLSTAT: LOCK Mask        */
#define LPC_SYSCON_SYSPLLSTAT_LOCK_SHIFT         (0U)                                                /*!< LPC_SYSCON_SYSPLLSTAT: LOCK Position    */
#define LPC_SYSCON_SYSPLLSTAT_LOCK(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLSTAT_LOCK_SHIFT))&LPC_SYSCON_SYSPLLSTAT_LOCK_MASK) /*!< LPC_SYSCON_SYSPLLSTAT                   */
/* ------- SYSOSCCTRL Bit Fields                    ------ */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS_MASK        (0x1U)                                              /*!< LPC_SYSCON_SYSOSCCTRL: BYPASS Mask      */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS_SHIFT       (0U)                                                /*!< LPC_SYSCON_SYSOSCCTRL: BYPASS Position  */
#define LPC_SYSCON_SYSOSCCTRL_BYPASS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSOSCCTRL_BYPASS_SHIFT))&LPC_SYSCON_SYSOSCCTRL_BYPASS_MASK) /*!< LPC_SYSCON_SYSOSCCTRL                   */
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE_MASK     (0x2U)                                              /*!< LPC_SYSCON_SYSOSCCTRL: FREQRANGE Mask   */
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT    (1U)                                                /*!< LPC_SYSCON_SYSOSCCTRL: FREQRANGE Position*/
#define LPC_SYSCON_SYSOSCCTRL_FREQRANGE(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT))&LPC_SYSCON_SYSOSCCTRL_FREQRANGE_MASK) /*!< LPC_SYSCON_SYSOSCCTRL                   */
/* ------- WDTOSCCTRL Bit Fields                    ------ */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL_MASK        (0x1FU)                                             /*!< LPC_SYSCON_WDTOSCCTRL: DIVSEL Mask      */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL_SHIFT       (0U)                                                /*!< LPC_SYSCON_WDTOSCCTRL: DIVSEL Position  */
#define LPC_SYSCON_WDTOSCCTRL_DIVSEL(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_WDTOSCCTRL_DIVSEL_SHIFT))&LPC_SYSCON_WDTOSCCTRL_DIVSEL_MASK) /*!< LPC_SYSCON_WDTOSCCTRL                   */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL_MASK       (0x1E0U)                                            /*!< LPC_SYSCON_WDTOSCCTRL: FREQSEL Mask     */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL_SHIFT      (5U)                                                /*!< LPC_SYSCON_WDTOSCCTRL: FREQSEL Position */
#define LPC_SYSCON_WDTOSCCTRL_FREQSEL(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_WDTOSCCTRL_FREQSEL_SHIFT))&LPC_SYSCON_WDTOSCCTRL_FREQSEL_MASK) /*!< LPC_SYSCON_WDTOSCCTRL                   */
/* ------- IRCCTRL Bit Fields                       ------ */
#define LPC_SYSCON_IRCCTRL_TRIM_MASK             (0xFFU)                                             /*!< LPC_SYSCON_IRCCTRL: TRIM Mask           */
#define LPC_SYSCON_IRCCTRL_TRIM_SHIFT            (0U)                                                /*!< LPC_SYSCON_IRCCTRL: TRIM Position       */
#define LPC_SYSCON_IRCCTRL_TRIM(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_IRCCTRL_TRIM_SHIFT))&LPC_SYSCON_IRCCTRL_TRIM_MASK) /*!< LPC_SYSCON_IRCCTRL                      */
/* ------- SYSRSTSTAT Bit Fields                    ------ */
#define LPC_SYSCON_SYSRSTSTAT_POR_MASK           (0x1U)                                              /*!< LPC_SYSCON_SYSRSTSTAT: POR Mask         */
#define LPC_SYSCON_SYSRSTSTAT_POR_SHIFT          (0U)                                                /*!< LPC_SYSCON_SYSRSTSTAT: POR Position     */
#define LPC_SYSCON_SYSRSTSTAT_POR(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_POR_SHIFT))&LPC_SYSCON_SYSRSTSTAT_POR_MASK) /*!< LPC_SYSCON_SYSRSTSTAT                   */
#define LPC_SYSCON_SYSRSTSTAT_EXTRST_MASK        (0x2U)                                              /*!< LPC_SYSCON_SYSRSTSTAT: EXTRST Mask      */
#define LPC_SYSCON_SYSRSTSTAT_EXTRST_SHIFT       (1U)                                                /*!< LPC_SYSCON_SYSRSTSTAT: EXTRST Position  */
#define LPC_SYSCON_SYSRSTSTAT_EXTRST(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_EXTRST_SHIFT))&LPC_SYSCON_SYSRSTSTAT_EXTRST_MASK) /*!< LPC_SYSCON_SYSRSTSTAT                   */
#define LPC_SYSCON_SYSRSTSTAT_WDT_MASK           (0x4U)                                              /*!< LPC_SYSCON_SYSRSTSTAT: WDT Mask         */
#define LPC_SYSCON_SYSRSTSTAT_WDT_SHIFT          (2U)                                                /*!< LPC_SYSCON_SYSRSTSTAT: WDT Position     */
#define LPC_SYSCON_SYSRSTSTAT_WDT(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_WDT_SHIFT))&LPC_SYSCON_SYSRSTSTAT_WDT_MASK) /*!< LPC_SYSCON_SYSRSTSTAT                   */
#define LPC_SYSCON_SYSRSTSTAT_BOD_MASK           (0x8U)                                              /*!< LPC_SYSCON_SYSRSTSTAT: BOD Mask         */
#define LPC_SYSCON_SYSRSTSTAT_BOD_SHIFT          (3U)                                                /*!< LPC_SYSCON_SYSRSTSTAT: BOD Position     */
#define LPC_SYSCON_SYSRSTSTAT_BOD(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_BOD_SHIFT))&LPC_SYSCON_SYSRSTSTAT_BOD_MASK) /*!< LPC_SYSCON_SYSRSTSTAT                   */
#define LPC_SYSCON_SYSRSTSTAT_SYSRST_MASK        (0x10U)                                             /*!< LPC_SYSCON_SYSRSTSTAT: SYSRST Mask      */
#define LPC_SYSCON_SYSRSTSTAT_SYSRST_SHIFT       (4U)                                                /*!< LPC_SYSCON_SYSRSTSTAT: SYSRST Position  */
#define LPC_SYSCON_SYSRSTSTAT_SYSRST(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSRSTSTAT_SYSRST_SHIFT))&LPC_SYSCON_SYSRSTSTAT_SYSRST_MASK) /*!< LPC_SYSCON_SYSRSTSTAT                   */
/* ------- SYSPLLCLKSEL Bit Fields                  ------ */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL_MASK         (0x3U)                                              /*!< LPC_SYSCON_SYSPLLCLKSEL: SEL Mask       */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL_SHIFT        (0U)                                                /*!< LPC_SYSCON_SYSPLLCLKSEL: SEL Position   */
#define LPC_SYSCON_SYSPLLCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLCLKSEL_SEL_SHIFT))&LPC_SYSCON_SYSPLLCLKSEL_SEL_MASK) /*!< LPC_SYSCON_SYSPLLCLKSEL                 */
/* ------- SYSPLLCLKUEN Bit Fields                  ------ */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA_MASK         (0x1U)                                              /*!< LPC_SYSCON_SYSPLLCLKUEN: ENA Mask       */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA_SHIFT        (0U)                                                /*!< LPC_SYSCON_SYSPLLCLKUEN: ENA Position   */
#define LPC_SYSCON_SYSPLLCLKUEN_ENA(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSPLLCLKUEN_ENA_SHIFT))&LPC_SYSCON_SYSPLLCLKUEN_ENA_MASK) /*!< LPC_SYSCON_SYSPLLCLKUEN                 */
/* ------- MAINCLKSEL Bit Fields                    ------ */
#define LPC_SYSCON_MAINCLKSEL_SEL_MASK           (0x3U)                                              /*!< LPC_SYSCON_MAINCLKSEL: SEL Mask         */
#define LPC_SYSCON_MAINCLKSEL_SEL_SHIFT          (0U)                                                /*!< LPC_SYSCON_MAINCLKSEL: SEL Position     */
#define LPC_SYSCON_MAINCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_MAINCLKSEL_SEL_SHIFT))&LPC_SYSCON_MAINCLKSEL_SEL_MASK) /*!< LPC_SYSCON_MAINCLKSEL                   */
/* ------- MAINCLKUEN Bit Fields                    ------ */
#define LPC_SYSCON_MAINCLKUEN_ENA_MASK           (0x1U)                                              /*!< LPC_SYSCON_MAINCLKUEN: ENA Mask         */
#define LPC_SYSCON_MAINCLKUEN_ENA_SHIFT          (0U)                                                /*!< LPC_SYSCON_MAINCLKUEN: ENA Position     */
#define LPC_SYSCON_MAINCLKUEN_ENA(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_MAINCLKUEN_ENA_SHIFT))&LPC_SYSCON_MAINCLKUEN_ENA_MASK) /*!< LPC_SYSCON_MAINCLKUEN                   */
/* ------- SYSAHBCLKDIV Bit Fields                  ------ */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV_MASK         (0xFFU)                                             /*!< LPC_SYSCON_SYSAHBCLKDIV: DIV Mask       */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV_SHIFT        (0U)                                                /*!< LPC_SYSCON_SYSAHBCLKDIV: DIV Position   */
#define LPC_SYSCON_SYSAHBCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKDIV_DIV_SHIFT))&LPC_SYSCON_SYSAHBCLKDIV_DIV_MASK) /*!< LPC_SYSCON_SYSAHBCLKDIV                 */
/* ------- SYSAHBCLKCTRL Bit Fields                 ------ */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS_MASK        (0x1U)                                              /*!< LPC_SYSCON_SYSAHBCLKCTRL: SYS Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS_SHIFT       (0U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: SYS Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_SYS(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_SYS_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_SYS_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM_MASK        (0x2U)                                              /*!< LPC_SYSCON_SYSAHBCLKCTRL: ROM Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM_SHIFT       (1U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: ROM Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_ROM(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_ROM_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_ROM_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM0_1_MASK     (0x4U)                                              /*!< LPC_SYSCON_SYSAHBCLKCTRL: RAM0_1 Mask   */
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM0_1_SHIFT    (2U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: RAM0_1 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_RAM0_1(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_RAM0_1_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_RAM0_1_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK   (0x8U)                                              /*!< LPC_SYSCON_SYSAHBCLKCTRL: FLASHREG Mask */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT  (3U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: FLASHREG Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG(x)     (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASH_MASK      (0x10U)                                             /*!< LPC_SYSCON_SYSAHBCLKCTRL: FLASH Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASH_SHIFT     (4U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: FLASH Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_FLASH(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_FLASH_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_FLASH_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C0_MASK       (0x20U)                                             /*!< LPC_SYSCON_SYSAHBCLKCTRL: I2C0 Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C0_SHIFT      (5U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: I2C0 Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C0(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_I2C0_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_I2C0_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO_MASK       (0x40U)                                             /*!< LPC_SYSCON_SYSAHBCLKCTRL: GPIO Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT      (6U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: GPIO Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_GPIO(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_GPIO_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_SWM_MASK        (0x80U)                                             /*!< LPC_SYSCON_SYSAHBCLKCTRL: SWM Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_SWM_SHIFT       (7U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: SWM Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_SWM(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_SWM_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_SWM_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_SCT_MASK        (0x100U)                                            /*!< LPC_SYSCON_SYSAHBCLKCTRL: SCT Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_SCT_SHIFT       (8U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: SCT Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_SCT(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_SCT_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_SCT_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_WKT_MASK        (0x200U)                                            /*!< LPC_SYSCON_SYSAHBCLKCTRL: WKT Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_WKT_SHIFT       (9U)                                                /*!< LPC_SYSCON_SYSAHBCLKCTRL: WKT Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_WKT(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_WKT_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_WKT_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_MRT_MASK        (0x400U)                                            /*!< LPC_SYSCON_SYSAHBCLKCTRL: MRT Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_MRT_SHIFT       (10U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: MRT Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_MRT(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_MRT_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_MRT_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_SPI0_MASK       (0x800U)                                            /*!< LPC_SYSCON_SYSAHBCLKCTRL: SPI0 Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_SPI0_SHIFT      (11U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: SPI0 Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_SPI0(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_SPI0_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_SPI0_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_SPI1_MASK       (0x1000U)                                           /*!< LPC_SYSCON_SYSAHBCLKCTRL: SPI1 Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_SPI1_SHIFT      (12U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: SPI1 Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_SPI1(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_SPI1_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_SPI1_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_CRC_MASK        (0x2000U)                                           /*!< LPC_SYSCON_SYSAHBCLKCTRL: CRC Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_CRC_SHIFT       (13U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: CRC Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_CRC(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_CRC_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_CRC_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART0_MASK      (0x4000U)                                           /*!< LPC_SYSCON_SYSAHBCLKCTRL: UART0 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART0_SHIFT     (14U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: UART0 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_UART0(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_UART0_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_UART0_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART1_MASK      (0x8000U)                                           /*!< LPC_SYSCON_SYSAHBCLKCTRL: UART1 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART1_SHIFT     (15U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: UART1 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_UART1(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_UART1_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_UART1_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART2_MASK      (0x10000U)                                          /*!< LPC_SYSCON_SYSAHBCLKCTRL: UART2 Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_UART2_SHIFT     (16U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: UART2 Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_UART2(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_UART2_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_UART2_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_WWDT_MASK       (0x20000U)                                          /*!< LPC_SYSCON_SYSAHBCLKCTRL: WWDT Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_WWDT_SHIFT      (17U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: WWDT Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_WWDT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_WWDT_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_WWDT_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON_MASK      (0x40000U)                                          /*!< LPC_SYSCON_SYSAHBCLKCTRL: IOCON Mask    */
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT     (18U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: IOCON Position*/
#define LPC_SYSCON_SYSAHBCLKCTRL_IOCON(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_IOCON_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_ACMP_MASK       (0x80000U)                                          /*!< LPC_SYSCON_SYSAHBCLKCTRL: ACMP Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_ACMP_SHIFT      (19U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: ACMP Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_ACMP(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_ACMP_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_ACMP_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C1_MASK       (0x200000U)                                         /*!< LPC_SYSCON_SYSAHBCLKCTRL: I2C1 Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C1_SHIFT      (21U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: I2C1 Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C1(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_I2C1_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_I2C1_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C2_MASK       (0x400000U)                                         /*!< LPC_SYSCON_SYSAHBCLKCTRL: I2C2 Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C2_SHIFT      (22U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: I2C2 Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C2(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_I2C2_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_I2C2_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C3_MASK       (0x800000U)                                         /*!< LPC_SYSCON_SYSAHBCLKCTRL: I2C3 Mask     */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C3_SHIFT      (23U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: I2C3 Position */
#define LPC_SYSCON_SYSAHBCLKCTRL_I2C3(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_I2C3_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_I2C3_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC_MASK        (0x1000000U)                                        /*!< LPC_SYSCON_SYSAHBCLKCTRL: ADC Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC_SHIFT       (24U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: ADC Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_ADC(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_ADC_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_ADC_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_MTB_MASK        (0x4000000U)                                        /*!< LPC_SYSCON_SYSAHBCLKCTRL: MTB Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_MTB_SHIFT       (26U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: MTB Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_MTB(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_MTB_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_MTB_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
#define LPC_SYSCON_SYSAHBCLKCTRL_DMA_MASK        (0x20000000U)                                       /*!< LPC_SYSCON_SYSAHBCLKCTRL: DMA Mask      */
#define LPC_SYSCON_SYSAHBCLKCTRL_DMA_SHIFT       (29U)                                               /*!< LPC_SYSCON_SYSAHBCLKCTRL: DMA Position  */
#define LPC_SYSCON_SYSAHBCLKCTRL_DMA(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSAHBCLKCTRL_DMA_SHIFT))&LPC_SYSCON_SYSAHBCLKCTRL_DMA_MASK) /*!< LPC_SYSCON_SYSAHBCLKCTRL                */
/* ------- UARTCLKDIV Bit Fields                    ------ */
#define LPC_SYSCON_UARTCLKDIV_DIV_MASK           (0xFFU)                                             /*!< LPC_SYSCON_UARTCLKDIV: DIV Mask         */
#define LPC_SYSCON_UARTCLKDIV_DIV_SHIFT          (0U)                                                /*!< LPC_SYSCON_UARTCLKDIV: DIV Position     */
#define LPC_SYSCON_UARTCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_UARTCLKDIV_DIV_SHIFT))&LPC_SYSCON_UARTCLKDIV_DIV_MASK) /*!< LPC_SYSCON_UARTCLKDIV                   */
/* ------- CLKOUTSEL Bit Fields                     ------ */
#define LPC_SYSCON_CLKOUTSEL_SEL_MASK            (0x3U)                                              /*!< LPC_SYSCON_CLKOUTSEL: SEL Mask          */
#define LPC_SYSCON_CLKOUTSEL_SEL_SHIFT           (0U)                                                /*!< LPC_SYSCON_CLKOUTSEL: SEL Position      */
#define LPC_SYSCON_CLKOUTSEL_SEL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_CLKOUTSEL_SEL_SHIFT))&LPC_SYSCON_CLKOUTSEL_SEL_MASK) /*!< LPC_SYSCON_CLKOUTSEL                    */
/* ------- CLKOUTUEN Bit Fields                     ------ */
#define LPC_SYSCON_CLKOUTUEN_ENA_MASK            (0x1U)                                              /*!< LPC_SYSCON_CLKOUTUEN: ENA Mask          */
#define LPC_SYSCON_CLKOUTUEN_ENA_SHIFT           (0U)                                                /*!< LPC_SYSCON_CLKOUTUEN: ENA Position      */
#define LPC_SYSCON_CLKOUTUEN_ENA(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_CLKOUTUEN_ENA_SHIFT))&LPC_SYSCON_CLKOUTUEN_ENA_MASK) /*!< LPC_SYSCON_CLKOUTUEN                    */
/* ------- CLKOUTDIV Bit Fields                     ------ */
#define LPC_SYSCON_CLKOUTDIV_DIV_MASK            (0xFFU)                                             /*!< LPC_SYSCON_CLKOUTDIV: DIV Mask          */
#define LPC_SYSCON_CLKOUTDIV_DIV_SHIFT           (0U)                                                /*!< LPC_SYSCON_CLKOUTDIV: DIV Position      */
#define LPC_SYSCON_CLKOUTDIV_DIV(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_CLKOUTDIV_DIV_SHIFT))&LPC_SYSCON_CLKOUTDIV_DIV_MASK) /*!< LPC_SYSCON_CLKOUTDIV                    */
/* ------- UARTFRGDIV Bit Fields                    ------ */
#define LPC_SYSCON_UARTFRGDIV_DIV_MASK           (0xFFU)                                             /*!< LPC_SYSCON_UARTFRGDIV: DIV Mask         */
#define LPC_SYSCON_UARTFRGDIV_DIV_SHIFT          (0U)                                                /*!< LPC_SYSCON_UARTFRGDIV: DIV Position     */
#define LPC_SYSCON_UARTFRGDIV_DIV(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_UARTFRGDIV_DIV_SHIFT))&LPC_SYSCON_UARTFRGDIV_DIV_MASK) /*!< LPC_SYSCON_UARTFRGDIV                   */
/* ------- UARTFRGMULT Bit Fields                   ------ */
#define LPC_SYSCON_UARTFRGMULT_MULT_MASK         (0xFFU)                                             /*!< LPC_SYSCON_UARTFRGMULT: MULT Mask       */
#define LPC_SYSCON_UARTFRGMULT_MULT_SHIFT        (0U)                                                /*!< LPC_SYSCON_UARTFRGMULT: MULT Position   */
#define LPC_SYSCON_UARTFRGMULT_MULT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_UARTFRGMULT_MULT_SHIFT))&LPC_SYSCON_UARTFRGMULT_MULT_MASK) /*!< LPC_SYSCON_UARTFRGMULT                  */
/* ------- EXTTRACECMD Bit Fields                   ------ */
#define LPC_SYSCON_EXTTRACECMD_START_MASK        (0x1U)                                              /*!< LPC_SYSCON_EXTTRACECMD: START Mask      */
#define LPC_SYSCON_EXTTRACECMD_START_SHIFT       (0U)                                                /*!< LPC_SYSCON_EXTTRACECMD: START Position  */
#define LPC_SYSCON_EXTTRACECMD_START(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_EXTTRACECMD_START_SHIFT))&LPC_SYSCON_EXTTRACECMD_START_MASK) /*!< LPC_SYSCON_EXTTRACECMD                  */
#define LPC_SYSCON_EXTTRACECMD_STOP_MASK         (0x2U)                                              /*!< LPC_SYSCON_EXTTRACECMD: STOP Mask       */
#define LPC_SYSCON_EXTTRACECMD_STOP_SHIFT        (1U)                                                /*!< LPC_SYSCON_EXTTRACECMD: STOP Position   */
#define LPC_SYSCON_EXTTRACECMD_STOP(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_EXTTRACECMD_STOP_SHIFT))&LPC_SYSCON_EXTTRACECMD_STOP_MASK) /*!< LPC_SYSCON_EXTTRACECMD                  */
/* ------- PIOPORCAP0 Bit Fields                    ------ */
#define LPC_SYSCON_PIOPORCAP0_PIOSTAT_MASK       (0x3FFFFU)                                          /*!< LPC_SYSCON_PIOPORCAP0: PIOSTAT Mask     */
#define LPC_SYSCON_PIOPORCAP0_PIOSTAT_SHIFT      (0U)                                                /*!< LPC_SYSCON_PIOPORCAP0: PIOSTAT Position */
#define LPC_SYSCON_PIOPORCAP0_PIOSTAT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PIOPORCAP0_PIOSTAT_SHIFT))&LPC_SYSCON_PIOPORCAP0_PIOSTAT_MASK) /*!< LPC_SYSCON_PIOPORCAP0                   */
/* ------- IOCONCLKDIV6 Bit Fields                  ------ */
#define LPC_SYSCON_IOCONCLKDIV6_DIV_MASK         (0xFFU)                                             /*!< LPC_SYSCON_IOCONCLKDIV6: DIV Mask       */
#define LPC_SYSCON_IOCONCLKDIV6_DIV_SHIFT        (0U)                                                /*!< LPC_SYSCON_IOCONCLKDIV6: DIV Position   */
#define LPC_SYSCON_IOCONCLKDIV6_DIV(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_IOCONCLKDIV6_DIV_SHIFT))&LPC_SYSCON_IOCONCLKDIV6_DIV_MASK) /*!< LPC_SYSCON_IOCONCLKDIV6                 */
/* ------- BODCTRL Bit Fields                       ------ */
#define LPC_SYSCON_BODCTRL_BODRSTLEV_MASK        (0x3U)                                              /*!< LPC_SYSCON_BODCTRL: BODRSTLEV Mask      */
#define LPC_SYSCON_BODCTRL_BODRSTLEV_SHIFT       (0U)                                                /*!< LPC_SYSCON_BODCTRL: BODRSTLEV Position  */
#define LPC_SYSCON_BODCTRL_BODRSTLEV(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_BODCTRL_BODRSTLEV_SHIFT))&LPC_SYSCON_BODCTRL_BODRSTLEV_MASK) /*!< LPC_SYSCON_BODCTRL                      */
#define LPC_SYSCON_BODCTRL_BODINTVAL_MASK        (0xCU)                                              /*!< LPC_SYSCON_BODCTRL: BODINTVAL Mask      */
#define LPC_SYSCON_BODCTRL_BODINTVAL_SHIFT       (2U)                                                /*!< LPC_SYSCON_BODCTRL: BODINTVAL Position  */
#define LPC_SYSCON_BODCTRL_BODINTVAL(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_BODCTRL_BODINTVAL_SHIFT))&LPC_SYSCON_BODCTRL_BODINTVAL_MASK) /*!< LPC_SYSCON_BODCTRL                      */
#define LPC_SYSCON_BODCTRL_BODRSTENA_MASK        (0x10U)                                             /*!< LPC_SYSCON_BODCTRL: BODRSTENA Mask      */
#define LPC_SYSCON_BODCTRL_BODRSTENA_SHIFT       (4U)                                                /*!< LPC_SYSCON_BODCTRL: BODRSTENA Position  */
#define LPC_SYSCON_BODCTRL_BODRSTENA(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_BODCTRL_BODRSTENA_SHIFT))&LPC_SYSCON_BODCTRL_BODRSTENA_MASK) /*!< LPC_SYSCON_BODCTRL                      */
/* ------- SYSTCKCAL Bit Fields                     ------ */
#define LPC_SYSCON_SYSTCKCAL_CAL_MASK            (0x3FFFFFFU)                                        /*!< LPC_SYSCON_SYSTCKCAL: CAL Mask          */
#define LPC_SYSCON_SYSTCKCAL_CAL_SHIFT           (0U)                                                /*!< LPC_SYSCON_SYSTCKCAL: CAL Position      */
#define LPC_SYSCON_SYSTCKCAL_CAL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_SYSTCKCAL_CAL_SHIFT))&LPC_SYSCON_SYSTCKCAL_CAL_MASK) /*!< LPC_SYSCON_SYSTCKCAL                    */
/* ------- IRQLATENCY Bit Fields                    ------ */
#define LPC_SYSCON_IRQLATENCY_LATENCY_MASK       (0xFFU)                                             /*!< LPC_SYSCON_IRQLATENCY: LATENCY Mask     */
#define LPC_SYSCON_IRQLATENCY_LATENCY_SHIFT      (0U)                                                /*!< LPC_SYSCON_IRQLATENCY: LATENCY Position */
#define LPC_SYSCON_IRQLATENCY_LATENCY(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_IRQLATENCY_LATENCY_SHIFT))&LPC_SYSCON_IRQLATENCY_LATENCY_MASK) /*!< LPC_SYSCON_IRQLATENCY                   */
/* ------- NMISRC Bit Fields                        ------ */
#define LPC_SYSCON_NMISRC_IRQN_MASK              (0x1FU)                                             /*!< LPC_SYSCON_NMISRC: IRQN Mask            */
#define LPC_SYSCON_NMISRC_IRQN_SHIFT             (0U)                                                /*!< LPC_SYSCON_NMISRC: IRQN Position        */
#define LPC_SYSCON_NMISRC_IRQN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_NMISRC_IRQN_SHIFT))&LPC_SYSCON_NMISRC_IRQN_MASK) /*!< LPC_SYSCON_NMISRC                       */
#define LPC_SYSCON_NMISRC_NMIEN_MASK             (0x80000000U)                                       /*!< LPC_SYSCON_NMISRC: NMIEN Mask           */
#define LPC_SYSCON_NMISRC_NMIEN_SHIFT            (31U)                                               /*!< LPC_SYSCON_NMISRC: NMIEN Position       */
#define LPC_SYSCON_NMISRC_NMIEN(x)               (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_NMISRC_NMIEN_SHIFT))&LPC_SYSCON_NMISRC_NMIEN_MASK) /*!< LPC_SYSCON_NMISRC                       */
/* ------- PINTSEL0 Bit Fields                      ------ */
#define LPC_SYSCON_PINTSEL0_INTPIN_MASK          (0x3FU)                                             /*!< LPC_SYSCON_PINTSEL0: INTPIN Mask        */
#define LPC_SYSCON_PINTSEL0_INTPIN_SHIFT         (0U)                                                /*!< LPC_SYSCON_PINTSEL0: INTPIN Position    */
#define LPC_SYSCON_PINTSEL0_INTPIN(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PINTSEL0_INTPIN_SHIFT))&LPC_SYSCON_PINTSEL0_INTPIN_MASK) /*!< LPC_SYSCON_PINTSEL0                     */
/* ------- PINTSEL Bit Fields                       ------ */
#define LPC_SYSCON_PINTSEL_INTPIN_MASK           (0x3FU)                                             /*!< LPC_SYSCON_PINTSEL: INTPIN Mask         */
#define LPC_SYSCON_PINTSEL_INTPIN_SHIFT          (0U)                                                /*!< LPC_SYSCON_PINTSEL: INTPIN Position     */
#define LPC_SYSCON_PINTSEL_INTPIN(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PINTSEL_INTPIN_SHIFT))&LPC_SYSCON_PINTSEL_INTPIN_MASK) /*!< LPC_SYSCON_PINTSEL                      */
/* ------- STARTERP0 Bit Fields                     ------ */
#define LPC_SYSCON_STARTERP0_PINT0_MASK          (0x1U)                                              /*!< LPC_SYSCON_STARTERP0: PINT0 Mask        */
#define LPC_SYSCON_STARTERP0_PINT0_SHIFT         (0U)                                                /*!< LPC_SYSCON_STARTERP0: PINT0 Position    */
#define LPC_SYSCON_STARTERP0_PINT0(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT0_SHIFT))&LPC_SYSCON_STARTERP0_PINT0_MASK) /*!< LPC_SYSCON_STARTERP0                    */
#define LPC_SYSCON_STARTERP0_PINT1_MASK          (0x2U)                                              /*!< LPC_SYSCON_STARTERP0: PINT1 Mask        */
#define LPC_SYSCON_STARTERP0_PINT1_SHIFT         (1U)                                                /*!< LPC_SYSCON_STARTERP0: PINT1 Position    */
#define LPC_SYSCON_STARTERP0_PINT1(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT1_SHIFT))&LPC_SYSCON_STARTERP0_PINT1_MASK) /*!< LPC_SYSCON_STARTERP0                    */
#define LPC_SYSCON_STARTERP0_PINT2_MASK          (0x4U)                                              /*!< LPC_SYSCON_STARTERP0: PINT2 Mask        */
#define LPC_SYSCON_STARTERP0_PINT2_SHIFT         (2U)                                                /*!< LPC_SYSCON_STARTERP0: PINT2 Position    */
#define LPC_SYSCON_STARTERP0_PINT2(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT2_SHIFT))&LPC_SYSCON_STARTERP0_PINT2_MASK) /*!< LPC_SYSCON_STARTERP0                    */
#define LPC_SYSCON_STARTERP0_PINT3_MASK          (0x8U)                                              /*!< LPC_SYSCON_STARTERP0: PINT3 Mask        */
#define LPC_SYSCON_STARTERP0_PINT3_SHIFT         (3U)                                                /*!< LPC_SYSCON_STARTERP0: PINT3 Position    */
#define LPC_SYSCON_STARTERP0_PINT3(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT3_SHIFT))&LPC_SYSCON_STARTERP0_PINT3_MASK) /*!< LPC_SYSCON_STARTERP0                    */
#define LPC_SYSCON_STARTERP0_PINT4_MASK          (0x10U)                                             /*!< LPC_SYSCON_STARTERP0: PINT4 Mask        */
#define LPC_SYSCON_STARTERP0_PINT4_SHIFT         (4U)                                                /*!< LPC_SYSCON_STARTERP0: PINT4 Position    */
#define LPC_SYSCON_STARTERP0_PINT4(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT4_SHIFT))&LPC_SYSCON_STARTERP0_PINT4_MASK) /*!< LPC_SYSCON_STARTERP0                    */
#define LPC_SYSCON_STARTERP0_PINT5_MASK          (0x20U)                                             /*!< LPC_SYSCON_STARTERP0: PINT5 Mask        */
#define LPC_SYSCON_STARTERP0_PINT5_SHIFT         (5U)                                                /*!< LPC_SYSCON_STARTERP0: PINT5 Position    */
#define LPC_SYSCON_STARTERP0_PINT5(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT5_SHIFT))&LPC_SYSCON_STARTERP0_PINT5_MASK) /*!< LPC_SYSCON_STARTERP0                    */
#define LPC_SYSCON_STARTERP0_PINT6_MASK          (0x40U)                                             /*!< LPC_SYSCON_STARTERP0: PINT6 Mask        */
#define LPC_SYSCON_STARTERP0_PINT6_SHIFT         (6U)                                                /*!< LPC_SYSCON_STARTERP0: PINT6 Position    */
#define LPC_SYSCON_STARTERP0_PINT6(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT6_SHIFT))&LPC_SYSCON_STARTERP0_PINT6_MASK) /*!< LPC_SYSCON_STARTERP0                    */
#define LPC_SYSCON_STARTERP0_PINT7_MASK          (0x80U)                                             /*!< LPC_SYSCON_STARTERP0: PINT7 Mask        */
#define LPC_SYSCON_STARTERP0_PINT7_SHIFT         (7U)                                                /*!< LPC_SYSCON_STARTERP0: PINT7 Position    */
#define LPC_SYSCON_STARTERP0_PINT7(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP0_PINT7_SHIFT))&LPC_SYSCON_STARTERP0_PINT7_MASK) /*!< LPC_SYSCON_STARTERP0                    */
/* ------- STARTERP1 Bit Fields                     ------ */
#define LPC_SYSCON_STARTERP1_SPI0_MASK           (0x1U)                                              /*!< LPC_SYSCON_STARTERP1: SPI0 Mask         */
#define LPC_SYSCON_STARTERP1_SPI0_SHIFT          (0U)                                                /*!< LPC_SYSCON_STARTERP1: SPI0 Position     */
#define LPC_SYSCON_STARTERP1_SPI0(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_SPI0_SHIFT))&LPC_SYSCON_STARTERP1_SPI0_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_SPI1_MASK           (0x2U)                                              /*!< LPC_SYSCON_STARTERP1: SPI1 Mask         */
#define LPC_SYSCON_STARTERP1_SPI1_SHIFT          (1U)                                                /*!< LPC_SYSCON_STARTERP1: SPI1 Position     */
#define LPC_SYSCON_STARTERP1_SPI1(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_SPI1_SHIFT))&LPC_SYSCON_STARTERP1_SPI1_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_USART0_MASK         (0x8U)                                              /*!< LPC_SYSCON_STARTERP1: USART0 Mask       */
#define LPC_SYSCON_STARTERP1_USART0_SHIFT        (3U)                                                /*!< LPC_SYSCON_STARTERP1: USART0 Position   */
#define LPC_SYSCON_STARTERP1_USART0(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_USART0_SHIFT))&LPC_SYSCON_STARTERP1_USART0_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_USART1_MASK         (0x10U)                                             /*!< LPC_SYSCON_STARTERP1: USART1 Mask       */
#define LPC_SYSCON_STARTERP1_USART1_SHIFT        (4U)                                                /*!< LPC_SYSCON_STARTERP1: USART1 Position   */
#define LPC_SYSCON_STARTERP1_USART1(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_USART1_SHIFT))&LPC_SYSCON_STARTERP1_USART1_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_USART2_MASK         (0x20U)                                             /*!< LPC_SYSCON_STARTERP1: USART2 Mask       */
#define LPC_SYSCON_STARTERP1_USART2_SHIFT        (5U)                                                /*!< LPC_SYSCON_STARTERP1: USART2 Position   */
#define LPC_SYSCON_STARTERP1_USART2(x)           (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_USART2_SHIFT))&LPC_SYSCON_STARTERP1_USART2_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_I2C1_MASK           (0x80U)                                             /*!< LPC_SYSCON_STARTERP1: I2C1 Mask         */
#define LPC_SYSCON_STARTERP1_I2C1_SHIFT          (7U)                                                /*!< LPC_SYSCON_STARTERP1: I2C1 Position     */
#define LPC_SYSCON_STARTERP1_I2C1(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_I2C1_SHIFT))&LPC_SYSCON_STARTERP1_I2C1_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_I2C0_MASK           (0x100U)                                            /*!< LPC_SYSCON_STARTERP1: I2C0 Mask         */
#define LPC_SYSCON_STARTERP1_I2C0_SHIFT          (8U)                                                /*!< LPC_SYSCON_STARTERP1: I2C0 Position     */
#define LPC_SYSCON_STARTERP1_I2C0(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_I2C0_SHIFT))&LPC_SYSCON_STARTERP1_I2C0_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_WWDT_MASK           (0x1000U)                                           /*!< LPC_SYSCON_STARTERP1: WWDT Mask         */
#define LPC_SYSCON_STARTERP1_WWDT_SHIFT          (12U)                                               /*!< LPC_SYSCON_STARTERP1: WWDT Position     */
#define LPC_SYSCON_STARTERP1_WWDT(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_WWDT_SHIFT))&LPC_SYSCON_STARTERP1_WWDT_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_BOD_MASK            (0x2000U)                                           /*!< LPC_SYSCON_STARTERP1: BOD Mask          */
#define LPC_SYSCON_STARTERP1_BOD_SHIFT           (13U)                                               /*!< LPC_SYSCON_STARTERP1: BOD Position      */
#define LPC_SYSCON_STARTERP1_BOD(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_BOD_SHIFT))&LPC_SYSCON_STARTERP1_BOD_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_WKT_MASK            (0x8000U)                                           /*!< LPC_SYSCON_STARTERP1: WKT Mask          */
#define LPC_SYSCON_STARTERP1_WKT_SHIFT           (15U)                                               /*!< LPC_SYSCON_STARTERP1: WKT Position      */
#define LPC_SYSCON_STARTERP1_WKT(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_WKT_SHIFT))&LPC_SYSCON_STARTERP1_WKT_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_I2C2_MASK           (0x200000U)                                         /*!< LPC_SYSCON_STARTERP1: I2C2 Mask         */
#define LPC_SYSCON_STARTERP1_I2C2_SHIFT          (21U)                                               /*!< LPC_SYSCON_STARTERP1: I2C2 Position     */
#define LPC_SYSCON_STARTERP1_I2C2(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_I2C2_SHIFT))&LPC_SYSCON_STARTERP1_I2C2_MASK) /*!< LPC_SYSCON_STARTERP1                    */
#define LPC_SYSCON_STARTERP1_I2C3_MASK           (0x400000U)                                         /*!< LPC_SYSCON_STARTERP1: I2C3 Mask         */
#define LPC_SYSCON_STARTERP1_I2C3_SHIFT          (22U)                                               /*!< LPC_SYSCON_STARTERP1: I2C3 Position     */
#define LPC_SYSCON_STARTERP1_I2C3(x)             (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_STARTERP1_I2C3_SHIFT))&LPC_SYSCON_STARTERP1_I2C3_MASK) /*!< LPC_SYSCON_STARTERP1                    */
/* ------- PDSLEEPCFG Bit Fields                    ------ */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD_MASK        (0x8U)                                              /*!< LPC_SYSCON_PDSLEEPCFG: BOD_PD Mask      */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD_SHIFT       (3U)                                                /*!< LPC_SYSCON_PDSLEEPCFG: BOD_PD Position  */
#define LPC_SYSCON_PDSLEEPCFG_BOD_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDSLEEPCFG_BOD_PD_SHIFT))&LPC_SYSCON_PDSLEEPCFG_BOD_PD_MASK) /*!< LPC_SYSCON_PDSLEEPCFG                   */
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK     (0x40U)                                             /*!< LPC_SYSCON_PDSLEEPCFG: WDTOSC_PD Mask   */
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT    (6U)                                                /*!< LPC_SYSCON_PDSLEEPCFG: WDTOSC_PD Position*/
#define LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT))&LPC_SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK) /*!< LPC_SYSCON_PDSLEEPCFG                   */
/* ------- PDAWAKECFG Bit Fields                    ------ */
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_MASK     (0x1U)                                              /*!< LPC_SYSCON_PDAWAKECFG: IRCOUT_PD Mask   */
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT    (0U)                                                /*!< LPC_SYSCON_PDAWAKECFG: IRCOUT_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_IRCOUT_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_IRCOUT_PD_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD_MASK        (0x2U)                                              /*!< LPC_SYSCON_PDAWAKECFG: IRC_PD Mask      */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD_SHIFT       (1U)                                                /*!< LPC_SYSCON_PDAWAKECFG: IRC_PD Position  */
#define LPC_SYSCON_PDAWAKECFG_IRC_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_IRC_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_IRC_PD_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD_MASK      (0x4U)                                              /*!< LPC_SYSCON_PDAWAKECFG: FLASH_PD Mask    */
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD_SHIFT     (2U)                                                /*!< LPC_SYSCON_PDAWAKECFG: FLASH_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_FLASH_PD(x)        (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_FLASH_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_FLASH_PD_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD_MASK        (0x8U)                                              /*!< LPC_SYSCON_PDAWAKECFG: BOD_PD Mask      */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD_SHIFT       (3U)                                                /*!< LPC_SYSCON_PDAWAKECFG: BOD_PD Position  */
#define LPC_SYSCON_PDAWAKECFG_BOD_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_BOD_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_BOD_PD_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD_MASK        (0x10U)                                             /*!< LPC_SYSCON_PDAWAKECFG: ADC_PD Mask      */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD_SHIFT       (4U)                                                /*!< LPC_SYSCON_PDAWAKECFG: ADC_PD Position  */
#define LPC_SYSCON_PDAWAKECFG_ADC_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_ADC_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_ADC_PD_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_MASK     (0x20U)                                             /*!< LPC_SYSCON_PDAWAKECFG: SYSOSC_PD Mask   */
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT    (5U)                                                /*!< LPC_SYSCON_PDAWAKECFG: SYSOSC_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_SYSOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_SYSOSC_PD_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_MASK     (0x40U)                                             /*!< LPC_SYSCON_PDAWAKECFG: WDTOSC_PD Mask   */
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT    (6U)                                                /*!< LPC_SYSCON_PDAWAKECFG: WDTOSC_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_WDTOSC_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_WDTOSC_PD_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_MASK     (0x80U)                                             /*!< LPC_SYSCON_PDAWAKECFG: SYSPLL_PD Mask   */
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT    (7U)                                                /*!< LPC_SYSCON_PDAWAKECFG: SYSPLL_PD Position*/
#define LPC_SYSCON_PDAWAKECFG_SYSPLL_PD(x)       (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT))&LPC_SYSCON_PDAWAKECFG_SYSPLL_PD_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
#define LPC_SYSCON_PDAWAKECFG_ACMP_MASK          (0x8000U)                                           /*!< LPC_SYSCON_PDAWAKECFG: ACMP Mask        */
#define LPC_SYSCON_PDAWAKECFG_ACMP_SHIFT         (15U)                                               /*!< LPC_SYSCON_PDAWAKECFG: ACMP Position    */
#define LPC_SYSCON_PDAWAKECFG_ACMP(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDAWAKECFG_ACMP_SHIFT))&LPC_SYSCON_PDAWAKECFG_ACMP_MASK) /*!< LPC_SYSCON_PDAWAKECFG                   */
/* ------- PDRUNCFG Bit Fields                      ------ */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD_MASK       (0x1U)                                              /*!< LPC_SYSCON_PDRUNCFG: IRCOUT_PD Mask     */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT      (0U)                                                /*!< LPC_SYSCON_PDRUNCFG: IRCOUT_PD Position */
#define LPC_SYSCON_PDRUNCFG_IRCOUT_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_IRCOUT_PD_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
#define LPC_SYSCON_PDRUNCFG_IRC_PD_MASK          (0x2U)                                              /*!< LPC_SYSCON_PDRUNCFG: IRC_PD Mask        */
#define LPC_SYSCON_PDRUNCFG_IRC_PD_SHIFT         (1U)                                                /*!< LPC_SYSCON_PDRUNCFG: IRC_PD Position    */
#define LPC_SYSCON_PDRUNCFG_IRC_PD(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_IRC_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_IRC_PD_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD_MASK        (0x4U)                                              /*!< LPC_SYSCON_PDRUNCFG: FLASH_PD Mask      */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD_SHIFT       (2U)                                                /*!< LPC_SYSCON_PDRUNCFG: FLASH_PD Position  */
#define LPC_SYSCON_PDRUNCFG_FLASH_PD(x)          (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_FLASH_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_FLASH_PD_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
#define LPC_SYSCON_PDRUNCFG_BOD_PD_MASK          (0x8U)                                              /*!< LPC_SYSCON_PDRUNCFG: BOD_PD Mask        */
#define LPC_SYSCON_PDRUNCFG_BOD_PD_SHIFT         (3U)                                                /*!< LPC_SYSCON_PDRUNCFG: BOD_PD Position    */
#define LPC_SYSCON_PDRUNCFG_BOD_PD(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_BOD_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_BOD_PD_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
#define LPC_SYSCON_PDRUNCFG_ADC_PD_MASK          (0x10U)                                             /*!< LPC_SYSCON_PDRUNCFG: ADC_PD Mask        */
#define LPC_SYSCON_PDRUNCFG_ADC_PD_SHIFT         (4U)                                                /*!< LPC_SYSCON_PDRUNCFG: ADC_PD Position    */
#define LPC_SYSCON_PDRUNCFG_ADC_PD(x)            (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_ADC_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_ADC_PD_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD_MASK       (0x20U)                                             /*!< LPC_SYSCON_PDRUNCFG: SYSOSC_PD Mask     */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT      (5U)                                                /*!< LPC_SYSCON_PDRUNCFG: SYSOSC_PD Position */
#define LPC_SYSCON_PDRUNCFG_SYSOSC_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_SYSOSC_PD_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD_MASK       (0x40U)                                             /*!< LPC_SYSCON_PDRUNCFG: WDTOSC_PD Mask     */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT      (6U)                                                /*!< LPC_SYSCON_PDRUNCFG: WDTOSC_PD Position */
#define LPC_SYSCON_PDRUNCFG_WDTOSC_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_WDTOSC_PD_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD_MASK       (0x80U)                                             /*!< LPC_SYSCON_PDRUNCFG: SYSPLL_PD Mask     */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT      (7U)                                                /*!< LPC_SYSCON_PDRUNCFG: SYSPLL_PD Position */
#define LPC_SYSCON_PDRUNCFG_SYSPLL_PD(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT))&LPC_SYSCON_PDRUNCFG_SYSPLL_PD_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
#define LPC_SYSCON_PDRUNCFG_ACMP_MASK            (0x8000U)                                           /*!< LPC_SYSCON_PDRUNCFG: ACMP Mask          */
#define LPC_SYSCON_PDRUNCFG_ACMP_SHIFT           (15U)                                               /*!< LPC_SYSCON_PDRUNCFG: ACMP Position      */
#define LPC_SYSCON_PDRUNCFG_ACMP(x)              (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_PDRUNCFG_ACMP_SHIFT))&LPC_SYSCON_PDRUNCFG_ACMP_MASK) /*!< LPC_SYSCON_PDRUNCFG                     */
/* ------- DEVICE_ID Bit Fields                     ------ */
#define LPC_SYSCON_DEVICE_ID_DEVICEID_MASK       (0xFFFFFFFFU)                                       /*!< LPC_SYSCON_DEVICE_ID: DEVICEID Mask     */
#define LPC_SYSCON_DEVICE_ID_DEVICEID_SHIFT      (0U)                                                /*!< LPC_SYSCON_DEVICE_ID: DEVICEID Position */
#define LPC_SYSCON_DEVICE_ID_DEVICEID(x)         (((uint32_t)(((uint32_t)(x))<<LPC_SYSCON_DEVICE_ID_DEVICEID_SHIFT))&LPC_SYSCON_DEVICE_ID_DEVICEID_MASK) /*!< LPC_SYSCON_DEVICE_ID                    */
/**
 * @} */ /* End group SYSCON_Register_Masks_GROUP 
 */

/* LPC_SYSCON - Peripheral instance base addresses */
#define LPC_SYSCON_BasePtr             0x40048000UL //!< Peripheral base address
#define LPC_SYSCON                     ((LPC_SYSCON_Type *) LPC_SYSCON_BasePtr) //!< Freescale base pointer
#define LPC_SYSCON_BASE_PTR            (LPC_SYSCON) //!< Freescale style base pointer
/**
 * @} */ /* End group SYSCON_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USART_Peripheral_access_layer_GROUP USART Peripheral Access Layer
* @brief C Struct for USART
* @{
*/

/* ================================================================================ */
/* ================           LPC_USART0 (file:USART0_LPC82x)       ================ */
/* ================================================================================ */

/**
 * @brief USART0
 */
/**
* @addtogroup USART_structs_GROUP USART struct
* @brief Struct for USART
* @{
*/
typedef struct {                                /*       LPC_USART0 Structure                                         */
   __IO uint32_t  CFG;                          /**< 0000: USART Configuration register. Basic USART configuration settings that typically are not changed during operation */
   __IO uint32_t  CTL;                          /**< 0004: USART Control register. USART control settings that are more likely to change during operation */
   __IO uint32_t  STAT;                         /**< 0008: USART Status register. The complete status value can be read here. Writing ones clears some bits in the register. Some bits can be cleared by writing a 1 to them */
   __IO uint32_t  INTENSET;                     /**< 000C: Interrupt Enable read and Set register. Contains an individual interrupt enable bit for each potential USART interrupt. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set */
   __O  uint32_t  INTENCLR;                     /**< 0010: Interrupt Enable Clear register. Allows clearing any combination of bits in the INTENSET register. Writing a 1 to any implemented bit position causes the corresponding bit to be cleared */
   __I  uint32_t  RXDAT;                        /**< 0014: Receiver Data register. Contains the last character received */
   __I  uint32_t  RXDATSTAT;                    /**< 0018: Receiver Data with Status register. Combines the last character received with the current USART receive status. Allows DMA or software to recover incoming data and status together */
   __IO uint32_t  TXDAT;                        /**< 001C: Transmit Data register. Data to be transmitted is written here */
   __IO uint32_t  BRG;                          /**< 0020: Baud Rate Generator register. 16-bit integer baud rate divisor value */
   __I  uint32_t  INTSTAT;                      /**< 0024: Interrupt status register. Reflects interrupts that are currently enabled */
   __IO uint32_t  OSR;                          /**< 0028: Oversample selection register for asynchronous communication */
   __IO uint32_t  ADDR;                         /**< 002C: Address register for automatic address matching              */
} LPC_USART0_Type;

/**
 * @} */ /* End group USART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_USART0' Position & Mask macros                  ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup USART_Register_Masks_GROUP USART Register Masks
* @brief Register Masks for USART
* @{
*/
/* ------- CFG Bit Fields                           ------ */
#define LPC_USART0_CFG_ENABLE_MASK               (0x1U)                                              /*!< LPC_USART0_CFG: ENABLE Mask             */
#define LPC_USART0_CFG_ENABLE_SHIFT              (0U)                                                /*!< LPC_USART0_CFG: ENABLE Position         */
#define LPC_USART0_CFG_ENABLE(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_ENABLE_SHIFT))&LPC_USART0_CFG_ENABLE_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_DATALEN_MASK              (0xCU)                                              /*!< LPC_USART0_CFG: DATALEN Mask            */
#define LPC_USART0_CFG_DATALEN_SHIFT             (2U)                                                /*!< LPC_USART0_CFG: DATALEN Position        */
#define LPC_USART0_CFG_DATALEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_DATALEN_SHIFT))&LPC_USART0_CFG_DATALEN_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_PARITYSEL_MASK            (0x30U)                                             /*!< LPC_USART0_CFG: PARITYSEL Mask          */
#define LPC_USART0_CFG_PARITYSEL_SHIFT           (4U)                                                /*!< LPC_USART0_CFG: PARITYSEL Position      */
#define LPC_USART0_CFG_PARITYSEL(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_PARITYSEL_SHIFT))&LPC_USART0_CFG_PARITYSEL_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_STOPLEN_MASK              (0x40U)                                             /*!< LPC_USART0_CFG: STOPLEN Mask            */
#define LPC_USART0_CFG_STOPLEN_SHIFT             (6U)                                                /*!< LPC_USART0_CFG: STOPLEN Position        */
#define LPC_USART0_CFG_STOPLEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_STOPLEN_SHIFT))&LPC_USART0_CFG_STOPLEN_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_CTSEN_MASK                (0x200U)                                            /*!< LPC_USART0_CFG: CTSEN Mask              */
#define LPC_USART0_CFG_CTSEN_SHIFT               (9U)                                                /*!< LPC_USART0_CFG: CTSEN Position          */
#define LPC_USART0_CFG_CTSEN(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_CTSEN_SHIFT))&LPC_USART0_CFG_CTSEN_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_SYNCEN_MASK               (0x800U)                                            /*!< LPC_USART0_CFG: SYNCEN Mask             */
#define LPC_USART0_CFG_SYNCEN_SHIFT              (11U)                                               /*!< LPC_USART0_CFG: SYNCEN Position         */
#define LPC_USART0_CFG_SYNCEN(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_SYNCEN_SHIFT))&LPC_USART0_CFG_SYNCEN_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_CLKPOL_MASK               (0x1000U)                                           /*!< LPC_USART0_CFG: CLKPOL Mask             */
#define LPC_USART0_CFG_CLKPOL_SHIFT              (12U)                                               /*!< LPC_USART0_CFG: CLKPOL Position         */
#define LPC_USART0_CFG_CLKPOL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_CLKPOL_SHIFT))&LPC_USART0_CFG_CLKPOL_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_SYNCMST_MASK              (0x4000U)                                           /*!< LPC_USART0_CFG: SYNCMST Mask            */
#define LPC_USART0_CFG_SYNCMST_SHIFT             (14U)                                               /*!< LPC_USART0_CFG: SYNCMST Position        */
#define LPC_USART0_CFG_SYNCMST(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_SYNCMST_SHIFT))&LPC_USART0_CFG_SYNCMST_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_LOOP_MASK                 (0x8000U)                                           /*!< LPC_USART0_CFG: LOOP Mask               */
#define LPC_USART0_CFG_LOOP_SHIFT                (15U)                                               /*!< LPC_USART0_CFG: LOOP Position           */
#define LPC_USART0_CFG_LOOP(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_LOOP_SHIFT))&LPC_USART0_CFG_LOOP_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_OETA_MASK                 (0x40000U)                                          /*!< LPC_USART0_CFG: OETA Mask               */
#define LPC_USART0_CFG_OETA_SHIFT                (18U)                                               /*!< LPC_USART0_CFG: OETA Position           */
#define LPC_USART0_CFG_OETA(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_OETA_SHIFT))&LPC_USART0_CFG_OETA_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_AUTOADDR_MASK             (0x80000U)                                          /*!< LPC_USART0_CFG: AUTOADDR Mask           */
#define LPC_USART0_CFG_AUTOADDR_SHIFT            (19U)                                               /*!< LPC_USART0_CFG: AUTOADDR Position       */
#define LPC_USART0_CFG_AUTOADDR(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_AUTOADDR_SHIFT))&LPC_USART0_CFG_AUTOADDR_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_OESEL_MASK                (0x100000U)                                         /*!< LPC_USART0_CFG: OESEL Mask              */
#define LPC_USART0_CFG_OESEL_SHIFT               (20U)                                               /*!< LPC_USART0_CFG: OESEL Position          */
#define LPC_USART0_CFG_OESEL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_OESEL_SHIFT))&LPC_USART0_CFG_OESEL_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_OEPOL_MASK                (0x200000U)                                         /*!< LPC_USART0_CFG: OEPOL Mask              */
#define LPC_USART0_CFG_OEPOL_SHIFT               (21U)                                               /*!< LPC_USART0_CFG: OEPOL Position          */
#define LPC_USART0_CFG_OEPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_OEPOL_SHIFT))&LPC_USART0_CFG_OEPOL_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_RXPOL_MASK                (0x400000U)                                         /*!< LPC_USART0_CFG: RXPOL Mask              */
#define LPC_USART0_CFG_RXPOL_SHIFT               (22U)                                               /*!< LPC_USART0_CFG: RXPOL Position          */
#define LPC_USART0_CFG_RXPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_RXPOL_SHIFT))&LPC_USART0_CFG_RXPOL_MASK) /*!< LPC_USART0_CFG                          */
#define LPC_USART0_CFG_TXPOL_MASK                (0x800000U)                                         /*!< LPC_USART0_CFG: TXPOL Mask              */
#define LPC_USART0_CFG_TXPOL_SHIFT               (23U)                                               /*!< LPC_USART0_CFG: TXPOL Position          */
#define LPC_USART0_CFG_TXPOL(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CFG_TXPOL_SHIFT))&LPC_USART0_CFG_TXPOL_MASK) /*!< LPC_USART0_CFG                          */
/* ------- CTL Bit Fields                           ------ */
#define LPC_USART0_CTL_TXBRKEN_MASK              (0x2U)                                              /*!< LPC_USART0_CTL: TXBRKEN Mask            */
#define LPC_USART0_CTL_TXBRKEN_SHIFT             (1U)                                                /*!< LPC_USART0_CTL: TXBRKEN Position        */
#define LPC_USART0_CTL_TXBRKEN(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CTL_TXBRKEN_SHIFT))&LPC_USART0_CTL_TXBRKEN_MASK) /*!< LPC_USART0_CTL                          */
#define LPC_USART0_CTL_ADDRDET_MASK              (0x4U)                                              /*!< LPC_USART0_CTL: ADDRDET Mask            */
#define LPC_USART0_CTL_ADDRDET_SHIFT             (2U)                                                /*!< LPC_USART0_CTL: ADDRDET Position        */
#define LPC_USART0_CTL_ADDRDET(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CTL_ADDRDET_SHIFT))&LPC_USART0_CTL_ADDRDET_MASK) /*!< LPC_USART0_CTL                          */
#define LPC_USART0_CTL_TXDIS_MASK                (0x40U)                                             /*!< LPC_USART0_CTL: TXDIS Mask              */
#define LPC_USART0_CTL_TXDIS_SHIFT               (6U)                                                /*!< LPC_USART0_CTL: TXDIS Position          */
#define LPC_USART0_CTL_TXDIS(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CTL_TXDIS_SHIFT))&LPC_USART0_CTL_TXDIS_MASK) /*!< LPC_USART0_CTL                          */
#define LPC_USART0_CTL_CC_MASK                   (0x100U)                                            /*!< LPC_USART0_CTL: CC Mask                 */
#define LPC_USART0_CTL_CC_SHIFT                  (8U)                                                /*!< LPC_USART0_CTL: CC Position             */
#define LPC_USART0_CTL_CC(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CTL_CC_SHIFT))&LPC_USART0_CTL_CC_MASK) /*!< LPC_USART0_CTL                          */
#define LPC_USART0_CTL_CLRCCONRX_MASK            (0x200U)                                            /*!< LPC_USART0_CTL: CLRCCONRX Mask          */
#define LPC_USART0_CTL_CLRCCONRX_SHIFT           (9U)                                                /*!< LPC_USART0_CTL: CLRCCONRX Position      */
#define LPC_USART0_CTL_CLRCCONRX(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CTL_CLRCCONRX_SHIFT))&LPC_USART0_CTL_CLRCCONRX_MASK) /*!< LPC_USART0_CTL                          */
#define LPC_USART0_CTL_AUTOBAUD_MASK             (0x10000U)                                          /*!< LPC_USART0_CTL: AUTOBAUD Mask           */
#define LPC_USART0_CTL_AUTOBAUD_SHIFT            (16U)                                               /*!< LPC_USART0_CTL: AUTOBAUD Position       */
#define LPC_USART0_CTL_AUTOBAUD(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART0_CTL_AUTOBAUD_SHIFT))&LPC_USART0_CTL_AUTOBAUD_MASK) /*!< LPC_USART0_CTL                          */
/* ------- STAT Bit Fields                          ------ */
#define LPC_USART0_STAT_RXRDY_MASK               (0x1U)                                              /*!< LPC_USART0_STAT: RXRDY Mask             */
#define LPC_USART0_STAT_RXRDY_SHIFT              (0U)                                                /*!< LPC_USART0_STAT: RXRDY Position         */
#define LPC_USART0_STAT_RXRDY(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_RXRDY_SHIFT))&LPC_USART0_STAT_RXRDY_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_RXIDLE_MASK              (0x2U)                                              /*!< LPC_USART0_STAT: RXIDLE Mask            */
#define LPC_USART0_STAT_RXIDLE_SHIFT             (1U)                                                /*!< LPC_USART0_STAT: RXIDLE Position        */
#define LPC_USART0_STAT_RXIDLE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_RXIDLE_SHIFT))&LPC_USART0_STAT_RXIDLE_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_TXRDY_MASK               (0x4U)                                              /*!< LPC_USART0_STAT: TXRDY Mask             */
#define LPC_USART0_STAT_TXRDY_SHIFT              (2U)                                                /*!< LPC_USART0_STAT: TXRDY Position         */
#define LPC_USART0_STAT_TXRDY(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_TXRDY_SHIFT))&LPC_USART0_STAT_TXRDY_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_TXIDLE_MASK              (0x8U)                                              /*!< LPC_USART0_STAT: TXIDLE Mask            */
#define LPC_USART0_STAT_TXIDLE_SHIFT             (3U)                                                /*!< LPC_USART0_STAT: TXIDLE Position        */
#define LPC_USART0_STAT_TXIDLE(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_TXIDLE_SHIFT))&LPC_USART0_STAT_TXIDLE_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_CTS_MASK                 (0x10U)                                             /*!< LPC_USART0_STAT: CTS Mask               */
#define LPC_USART0_STAT_CTS_SHIFT                (4U)                                                /*!< LPC_USART0_STAT: CTS Position           */
#define LPC_USART0_STAT_CTS(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_CTS_SHIFT))&LPC_USART0_STAT_CTS_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_DELTACTS_MASK            (0x20U)                                             /*!< LPC_USART0_STAT: DELTACTS Mask          */
#define LPC_USART0_STAT_DELTACTS_SHIFT           (5U)                                                /*!< LPC_USART0_STAT: DELTACTS Position      */
#define LPC_USART0_STAT_DELTACTS(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_DELTACTS_SHIFT))&LPC_USART0_STAT_DELTACTS_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_TXDISSTAT_MASK           (0x40U)                                             /*!< LPC_USART0_STAT: TXDISSTAT Mask         */
#define LPC_USART0_STAT_TXDISSTAT_SHIFT          (6U)                                                /*!< LPC_USART0_STAT: TXDISSTAT Position     */
#define LPC_USART0_STAT_TXDISSTAT(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_TXDISSTAT_SHIFT))&LPC_USART0_STAT_TXDISSTAT_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_OVERRUNINT_MASK          (0x100U)                                            /*!< LPC_USART0_STAT: OVERRUNINT Mask        */
#define LPC_USART0_STAT_OVERRUNINT_SHIFT         (8U)                                                /*!< LPC_USART0_STAT: OVERRUNINT Position    */
#define LPC_USART0_STAT_OVERRUNINT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_OVERRUNINT_SHIFT))&LPC_USART0_STAT_OVERRUNINT_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_RXBRK_MASK               (0x400U)                                            /*!< LPC_USART0_STAT: RXBRK Mask             */
#define LPC_USART0_STAT_RXBRK_SHIFT              (10U)                                               /*!< LPC_USART0_STAT: RXBRK Position         */
#define LPC_USART0_STAT_RXBRK(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_RXBRK_SHIFT))&LPC_USART0_STAT_RXBRK_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_DELTARXBRK_MASK          (0x800U)                                            /*!< LPC_USART0_STAT: DELTARXBRK Mask        */
#define LPC_USART0_STAT_DELTARXBRK_SHIFT         (11U)                                               /*!< LPC_USART0_STAT: DELTARXBRK Position    */
#define LPC_USART0_STAT_DELTARXBRK(x)            (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_DELTARXBRK_SHIFT))&LPC_USART0_STAT_DELTARXBRK_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_START_MASK               (0x1000U)                                           /*!< LPC_USART0_STAT: START Mask             */
#define LPC_USART0_STAT_START_SHIFT              (12U)                                               /*!< LPC_USART0_STAT: START Position         */
#define LPC_USART0_STAT_START(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_START_SHIFT))&LPC_USART0_STAT_START_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_FRAMERRINT_MASK          (0x2000U)                                           /*!< LPC_USART0_STAT: FRAMERRINT Mask        */
#define LPC_USART0_STAT_FRAMERRINT_SHIFT         (13U)                                               /*!< LPC_USART0_STAT: FRAMERRINT Position    */
#define LPC_USART0_STAT_FRAMERRINT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_FRAMERRINT_SHIFT))&LPC_USART0_STAT_FRAMERRINT_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_PARITYERRINT_MASK        (0x4000U)                                           /*!< LPC_USART0_STAT: PARITYERRINT Mask      */
#define LPC_USART0_STAT_PARITYERRINT_SHIFT       (14U)                                               /*!< LPC_USART0_STAT: PARITYERRINT Position  */
#define LPC_USART0_STAT_PARITYERRINT(x)          (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_PARITYERRINT_SHIFT))&LPC_USART0_STAT_PARITYERRINT_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_RXNOISEINT_MASK          (0x8000U)                                           /*!< LPC_USART0_STAT: RXNOISEINT Mask        */
#define LPC_USART0_STAT_RXNOISEINT_SHIFT         (15U)                                               /*!< LPC_USART0_STAT: RXNOISEINT Position    */
#define LPC_USART0_STAT_RXNOISEINT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_RXNOISEINT_SHIFT))&LPC_USART0_STAT_RXNOISEINT_MASK) /*!< LPC_USART0_STAT                         */
#define LPC_USART0_STAT_ABERR_MASK               (0x10000U)                                          /*!< LPC_USART0_STAT: ABERR Mask             */
#define LPC_USART0_STAT_ABERR_SHIFT              (16U)                                               /*!< LPC_USART0_STAT: ABERR Position         */
#define LPC_USART0_STAT_ABERR(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_STAT_ABERR_SHIFT))&LPC_USART0_STAT_ABERR_MASK) /*!< LPC_USART0_STAT                         */
/* ------- INTENSET Bit Fields                      ------ */
#define LPC_USART0_INTENSET_RXRDYEN_MASK         (0x1U)                                              /*!< LPC_USART0_INTENSET: RXRDYEN Mask       */
#define LPC_USART0_INTENSET_RXRDYEN_SHIFT        (0U)                                                /*!< LPC_USART0_INTENSET: RXRDYEN Position   */
#define LPC_USART0_INTENSET_RXRDYEN(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_RXRDYEN_SHIFT))&LPC_USART0_INTENSET_RXRDYEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_TXRDYEN_MASK         (0x4U)                                              /*!< LPC_USART0_INTENSET: TXRDYEN Mask       */
#define LPC_USART0_INTENSET_TXRDYEN_SHIFT        (2U)                                                /*!< LPC_USART0_INTENSET: TXRDYEN Position   */
#define LPC_USART0_INTENSET_TXRDYEN(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_TXRDYEN_SHIFT))&LPC_USART0_INTENSET_TXRDYEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_TXIDLEEN_MASK        (0x8U)                                              /*!< LPC_USART0_INTENSET: TXIDLEEN Mask      */
#define LPC_USART0_INTENSET_TXIDLEEN_SHIFT       (3U)                                                /*!< LPC_USART0_INTENSET: TXIDLEEN Position  */
#define LPC_USART0_INTENSET_TXIDLEEN(x)          (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_TXIDLEEN_SHIFT))&LPC_USART0_INTENSET_TXIDLEEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_DELTACTSEN_MASK      (0x20U)                                             /*!< LPC_USART0_INTENSET: DELTACTSEN Mask    */
#define LPC_USART0_INTENSET_DELTACTSEN_SHIFT     (5U)                                                /*!< LPC_USART0_INTENSET: DELTACTSEN Position*/
#define LPC_USART0_INTENSET_DELTACTSEN(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_DELTACTSEN_SHIFT))&LPC_USART0_INTENSET_DELTACTSEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_TXDISEN_MASK         (0x40U)                                             /*!< LPC_USART0_INTENSET: TXDISEN Mask       */
#define LPC_USART0_INTENSET_TXDISEN_SHIFT        (6U)                                                /*!< LPC_USART0_INTENSET: TXDISEN Position   */
#define LPC_USART0_INTENSET_TXDISEN(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_TXDISEN_SHIFT))&LPC_USART0_INTENSET_TXDISEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_OVERRUNEN_MASK       (0x100U)                                            /*!< LPC_USART0_INTENSET: OVERRUNEN Mask     */
#define LPC_USART0_INTENSET_OVERRUNEN_SHIFT      (8U)                                                /*!< LPC_USART0_INTENSET: OVERRUNEN Position */
#define LPC_USART0_INTENSET_OVERRUNEN(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_OVERRUNEN_SHIFT))&LPC_USART0_INTENSET_OVERRUNEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_DELTARXBRKEN_MASK    (0x800U)                                            /*!< LPC_USART0_INTENSET: DELTARXBRKEN Mask  */
#define LPC_USART0_INTENSET_DELTARXBRKEN_SHIFT   (11U)                                               /*!< LPC_USART0_INTENSET: DELTARXBRKEN Position*/
#define LPC_USART0_INTENSET_DELTARXBRKEN(x)      (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_DELTARXBRKEN_SHIFT))&LPC_USART0_INTENSET_DELTARXBRKEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_STARTEN_MASK         (0x1000U)                                           /*!< LPC_USART0_INTENSET: STARTEN Mask       */
#define LPC_USART0_INTENSET_STARTEN_SHIFT        (12U)                                               /*!< LPC_USART0_INTENSET: STARTEN Position   */
#define LPC_USART0_INTENSET_STARTEN(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_STARTEN_SHIFT))&LPC_USART0_INTENSET_STARTEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_FRAMERREN_MASK       (0x2000U)                                           /*!< LPC_USART0_INTENSET: FRAMERREN Mask     */
#define LPC_USART0_INTENSET_FRAMERREN_SHIFT      (13U)                                               /*!< LPC_USART0_INTENSET: FRAMERREN Position */
#define LPC_USART0_INTENSET_FRAMERREN(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_FRAMERREN_SHIFT))&LPC_USART0_INTENSET_FRAMERREN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_PARITYERREN_MASK     (0x4000U)                                           /*!< LPC_USART0_INTENSET: PARITYERREN Mask   */
#define LPC_USART0_INTENSET_PARITYERREN_SHIFT    (14U)                                               /*!< LPC_USART0_INTENSET: PARITYERREN Position*/
#define LPC_USART0_INTENSET_PARITYERREN(x)       (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_PARITYERREN_SHIFT))&LPC_USART0_INTENSET_PARITYERREN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_RXNOISEEN_MASK       (0x8000U)                                           /*!< LPC_USART0_INTENSET: RXNOISEEN Mask     */
#define LPC_USART0_INTENSET_RXNOISEEN_SHIFT      (15U)                                               /*!< LPC_USART0_INTENSET: RXNOISEEN Position */
#define LPC_USART0_INTENSET_RXNOISEEN(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_RXNOISEEN_SHIFT))&LPC_USART0_INTENSET_RXNOISEEN_MASK) /*!< LPC_USART0_INTENSET                     */
#define LPC_USART0_INTENSET_ABERREN_MASK         (0x10000U)                                          /*!< LPC_USART0_INTENSET: ABERREN Mask       */
#define LPC_USART0_INTENSET_ABERREN_SHIFT        (16U)                                               /*!< LPC_USART0_INTENSET: ABERREN Position   */
#define LPC_USART0_INTENSET_ABERREN(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENSET_ABERREN_SHIFT))&LPC_USART0_INTENSET_ABERREN_MASK) /*!< LPC_USART0_INTENSET                     */
/* ------- INTENCLR Bit Fields                      ------ */
#define LPC_USART0_INTENCLR_RXRDYCLR_MASK        (0x1U)                                              /*!< LPC_USART0_INTENCLR: RXRDYCLR Mask      */
#define LPC_USART0_INTENCLR_RXRDYCLR_SHIFT       (0U)                                                /*!< LPC_USART0_INTENCLR: RXRDYCLR Position  */
#define LPC_USART0_INTENCLR_RXRDYCLR(x)          (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_RXRDYCLR_SHIFT))&LPC_USART0_INTENCLR_RXRDYCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_TXRDYCLR_MASK        (0x4U)                                              /*!< LPC_USART0_INTENCLR: TXRDYCLR Mask      */
#define LPC_USART0_INTENCLR_TXRDYCLR_SHIFT       (2U)                                                /*!< LPC_USART0_INTENCLR: TXRDYCLR Position  */
#define LPC_USART0_INTENCLR_TXRDYCLR(x)          (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_TXRDYCLR_SHIFT))&LPC_USART0_INTENCLR_TXRDYCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_TXIDLECLR_MASK       (0x8U)                                              /*!< LPC_USART0_INTENCLR: TXIDLECLR Mask     */
#define LPC_USART0_INTENCLR_TXIDLECLR_SHIFT      (3U)                                                /*!< LPC_USART0_INTENCLR: TXIDLECLR Position */
#define LPC_USART0_INTENCLR_TXIDLECLR(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_TXIDLECLR_SHIFT))&LPC_USART0_INTENCLR_TXIDLECLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_DELTACTSCLR_MASK     (0x20U)                                             /*!< LPC_USART0_INTENCLR: DELTACTSCLR Mask   */
#define LPC_USART0_INTENCLR_DELTACTSCLR_SHIFT    (5U)                                                /*!< LPC_USART0_INTENCLR: DELTACTSCLR Position*/
#define LPC_USART0_INTENCLR_DELTACTSCLR(x)       (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_DELTACTSCLR_SHIFT))&LPC_USART0_INTENCLR_DELTACTSCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_TXDISINTCLR_MASK     (0x40U)                                             /*!< LPC_USART0_INTENCLR: TXDISINTCLR Mask   */
#define LPC_USART0_INTENCLR_TXDISINTCLR_SHIFT    (6U)                                                /*!< LPC_USART0_INTENCLR: TXDISINTCLR Position*/
#define LPC_USART0_INTENCLR_TXDISINTCLR(x)       (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_TXDISINTCLR_SHIFT))&LPC_USART0_INTENCLR_TXDISINTCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_OVERRUNCLR_MASK      (0x100U)                                            /*!< LPC_USART0_INTENCLR: OVERRUNCLR Mask    */
#define LPC_USART0_INTENCLR_OVERRUNCLR_SHIFT     (8U)                                                /*!< LPC_USART0_INTENCLR: OVERRUNCLR Position*/
#define LPC_USART0_INTENCLR_OVERRUNCLR(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_OVERRUNCLR_SHIFT))&LPC_USART0_INTENCLR_OVERRUNCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_DELTARXBRKCLR_MASK   (0x800U)                                            /*!< LPC_USART0_INTENCLR: DELTARXBRKCLR Mask */
#define LPC_USART0_INTENCLR_DELTARXBRKCLR_SHIFT  (11U)                                               /*!< LPC_USART0_INTENCLR: DELTARXBRKCLR Position*/
#define LPC_USART0_INTENCLR_DELTARXBRKCLR(x)     (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_DELTARXBRKCLR_SHIFT))&LPC_USART0_INTENCLR_DELTARXBRKCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_STARTCLR_MASK        (0x1000U)                                           /*!< LPC_USART0_INTENCLR: STARTCLR Mask      */
#define LPC_USART0_INTENCLR_STARTCLR_SHIFT       (12U)                                               /*!< LPC_USART0_INTENCLR: STARTCLR Position  */
#define LPC_USART0_INTENCLR_STARTCLR(x)          (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_STARTCLR_SHIFT))&LPC_USART0_INTENCLR_STARTCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_FRAMERRCLR_MASK      (0x2000U)                                           /*!< LPC_USART0_INTENCLR: FRAMERRCLR Mask    */
#define LPC_USART0_INTENCLR_FRAMERRCLR_SHIFT     (13U)                                               /*!< LPC_USART0_INTENCLR: FRAMERRCLR Position*/
#define LPC_USART0_INTENCLR_FRAMERRCLR(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_FRAMERRCLR_SHIFT))&LPC_USART0_INTENCLR_FRAMERRCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_PARITYERRCLR_MASK    (0x4000U)                                           /*!< LPC_USART0_INTENCLR: PARITYERRCLR Mask  */
#define LPC_USART0_INTENCLR_PARITYERRCLR_SHIFT   (14U)                                               /*!< LPC_USART0_INTENCLR: PARITYERRCLR Position*/
#define LPC_USART0_INTENCLR_PARITYERRCLR(x)      (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_PARITYERRCLR_SHIFT))&LPC_USART0_INTENCLR_PARITYERRCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_RXNOISECLR_MASK      (0x8000U)                                           /*!< LPC_USART0_INTENCLR: RXNOISECLR Mask    */
#define LPC_USART0_INTENCLR_RXNOISECLR_SHIFT     (15U)                                               /*!< LPC_USART0_INTENCLR: RXNOISECLR Position*/
#define LPC_USART0_INTENCLR_RXNOISECLR(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_RXNOISECLR_SHIFT))&LPC_USART0_INTENCLR_RXNOISECLR_MASK) /*!< LPC_USART0_INTENCLR                     */
#define LPC_USART0_INTENCLR_ABERRCLR_MASK        (0x10000U)                                          /*!< LPC_USART0_INTENCLR: ABERRCLR Mask      */
#define LPC_USART0_INTENCLR_ABERRCLR_SHIFT       (16U)                                               /*!< LPC_USART0_INTENCLR: ABERRCLR Position  */
#define LPC_USART0_INTENCLR_ABERRCLR(x)          (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTENCLR_ABERRCLR_SHIFT))&LPC_USART0_INTENCLR_ABERRCLR_MASK) /*!< LPC_USART0_INTENCLR                     */
/* ------- RXDAT Bit Fields                         ------ */
#define LPC_USART0_RXDAT_RXDAT_MASK              (0x1FFU)                                            /*!< LPC_USART0_RXDAT: RXDAT Mask            */
#define LPC_USART0_RXDAT_RXDAT_SHIFT             (0U)                                                /*!< LPC_USART0_RXDAT: RXDAT Position        */
#define LPC_USART0_RXDAT_RXDAT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_RXDAT_RXDAT_SHIFT))&LPC_USART0_RXDAT_RXDAT_MASK) /*!< LPC_USART0_RXDAT                        */
/* ------- RXDATSTAT Bit Fields                     ------ */
#define LPC_USART0_RXDATSTAT_RXDAT_MASK          (0x1FFU)                                            /*!< LPC_USART0_RXDATSTAT: RXDAT Mask        */
#define LPC_USART0_RXDATSTAT_RXDAT_SHIFT         (0U)                                                /*!< LPC_USART0_RXDATSTAT: RXDAT Position    */
#define LPC_USART0_RXDATSTAT_RXDAT(x)            (((uint32_t)(((uint32_t)(x))<<LPC_USART0_RXDATSTAT_RXDAT_SHIFT))&LPC_USART0_RXDATSTAT_RXDAT_MASK) /*!< LPC_USART0_RXDATSTAT                    */
#define LPC_USART0_RXDATSTAT_FRAMERR_MASK        (0x2000U)                                           /*!< LPC_USART0_RXDATSTAT: FRAMERR Mask      */
#define LPC_USART0_RXDATSTAT_FRAMERR_SHIFT       (13U)                                               /*!< LPC_USART0_RXDATSTAT: FRAMERR Position  */
#define LPC_USART0_RXDATSTAT_FRAMERR(x)          (((uint32_t)(((uint32_t)(x))<<LPC_USART0_RXDATSTAT_FRAMERR_SHIFT))&LPC_USART0_RXDATSTAT_FRAMERR_MASK) /*!< LPC_USART0_RXDATSTAT                    */
#define LPC_USART0_RXDATSTAT_PARITYERR_MASK      (0x4000U)                                           /*!< LPC_USART0_RXDATSTAT: PARITYERR Mask    */
#define LPC_USART0_RXDATSTAT_PARITYERR_SHIFT     (14U)                                               /*!< LPC_USART0_RXDATSTAT: PARITYERR Position*/
#define LPC_USART0_RXDATSTAT_PARITYERR(x)        (((uint32_t)(((uint32_t)(x))<<LPC_USART0_RXDATSTAT_PARITYERR_SHIFT))&LPC_USART0_RXDATSTAT_PARITYERR_MASK) /*!< LPC_USART0_RXDATSTAT                    */
#define LPC_USART0_RXDATSTAT_RXNOISE_MASK        (0x8000U)                                           /*!< LPC_USART0_RXDATSTAT: RXNOISE Mask      */
#define LPC_USART0_RXDATSTAT_RXNOISE_SHIFT       (15U)                                               /*!< LPC_USART0_RXDATSTAT: RXNOISE Position  */
#define LPC_USART0_RXDATSTAT_RXNOISE(x)          (((uint32_t)(((uint32_t)(x))<<LPC_USART0_RXDATSTAT_RXNOISE_SHIFT))&LPC_USART0_RXDATSTAT_RXNOISE_MASK) /*!< LPC_USART0_RXDATSTAT                    */
/* ------- TXDAT Bit Fields                         ------ */
#define LPC_USART0_TXDAT_TXDAT_MASK              (0x1FFU)                                            /*!< LPC_USART0_TXDAT: TXDAT Mask            */
#define LPC_USART0_TXDAT_TXDAT_SHIFT             (0U)                                                /*!< LPC_USART0_TXDAT: TXDAT Position        */
#define LPC_USART0_TXDAT_TXDAT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_USART0_TXDAT_TXDAT_SHIFT))&LPC_USART0_TXDAT_TXDAT_MASK) /*!< LPC_USART0_TXDAT                        */
/* ------- BRG Bit Fields                           ------ */
#define LPC_USART0_BRG_BRGVAL_MASK               (0xFFFFU)                                           /*!< LPC_USART0_BRG: BRGVAL Mask             */
#define LPC_USART0_BRG_BRGVAL_SHIFT              (0U)                                                /*!< LPC_USART0_BRG: BRGVAL Position         */
#define LPC_USART0_BRG_BRGVAL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_BRG_BRGVAL_SHIFT))&LPC_USART0_BRG_BRGVAL_MASK) /*!< LPC_USART0_BRG                          */
/* ------- INTSTAT Bit Fields                       ------ */
#define LPC_USART0_INTSTAT_RXRDY_MASK            (0x1U)                                              /*!< LPC_USART0_INTSTAT: RXRDY Mask          */
#define LPC_USART0_INTSTAT_RXRDY_SHIFT           (0U)                                                /*!< LPC_USART0_INTSTAT: RXRDY Position      */
#define LPC_USART0_INTSTAT_RXRDY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_RXRDY_SHIFT))&LPC_USART0_INTSTAT_RXRDY_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_TXRDY_MASK            (0x4U)                                              /*!< LPC_USART0_INTSTAT: TXRDY Mask          */
#define LPC_USART0_INTSTAT_TXRDY_SHIFT           (2U)                                                /*!< LPC_USART0_INTSTAT: TXRDY Position      */
#define LPC_USART0_INTSTAT_TXRDY(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_TXRDY_SHIFT))&LPC_USART0_INTSTAT_TXRDY_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_TXIDLE_MASK           (0x8U)                                              /*!< LPC_USART0_INTSTAT: TXIDLE Mask         */
#define LPC_USART0_INTSTAT_TXIDLE_SHIFT          (3U)                                                /*!< LPC_USART0_INTSTAT: TXIDLE Position     */
#define LPC_USART0_INTSTAT_TXIDLE(x)             (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_TXIDLE_SHIFT))&LPC_USART0_INTSTAT_TXIDLE_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_DELTACTS_MASK         (0x20U)                                             /*!< LPC_USART0_INTSTAT: DELTACTS Mask       */
#define LPC_USART0_INTSTAT_DELTACTS_SHIFT        (5U)                                                /*!< LPC_USART0_INTSTAT: DELTACTS Position   */
#define LPC_USART0_INTSTAT_DELTACTS(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_DELTACTS_SHIFT))&LPC_USART0_INTSTAT_DELTACTS_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_TXDISINT_MASK         (0x40U)                                             /*!< LPC_USART0_INTSTAT: TXDISINT Mask       */
#define LPC_USART0_INTSTAT_TXDISINT_SHIFT        (6U)                                                /*!< LPC_USART0_INTSTAT: TXDISINT Position   */
#define LPC_USART0_INTSTAT_TXDISINT(x)           (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_TXDISINT_SHIFT))&LPC_USART0_INTSTAT_TXDISINT_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_OVERRUNINT_MASK       (0x100U)                                            /*!< LPC_USART0_INTSTAT: OVERRUNINT Mask     */
#define LPC_USART0_INTSTAT_OVERRUNINT_SHIFT      (8U)                                                /*!< LPC_USART0_INTSTAT: OVERRUNINT Position */
#define LPC_USART0_INTSTAT_OVERRUNINT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_OVERRUNINT_SHIFT))&LPC_USART0_INTSTAT_OVERRUNINT_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_DELTARXBRK_MASK       (0x800U)                                            /*!< LPC_USART0_INTSTAT: DELTARXBRK Mask     */
#define LPC_USART0_INTSTAT_DELTARXBRK_SHIFT      (11U)                                               /*!< LPC_USART0_INTSTAT: DELTARXBRK Position */
#define LPC_USART0_INTSTAT_DELTARXBRK(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_DELTARXBRK_SHIFT))&LPC_USART0_INTSTAT_DELTARXBRK_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_START_MASK            (0x1000U)                                           /*!< LPC_USART0_INTSTAT: START Mask          */
#define LPC_USART0_INTSTAT_START_SHIFT           (12U)                                               /*!< LPC_USART0_INTSTAT: START Position      */
#define LPC_USART0_INTSTAT_START(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_START_SHIFT))&LPC_USART0_INTSTAT_START_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_FRAMERRINT_MASK       (0x2000U)                                           /*!< LPC_USART0_INTSTAT: FRAMERRINT Mask     */
#define LPC_USART0_INTSTAT_FRAMERRINT_SHIFT      (13U)                                               /*!< LPC_USART0_INTSTAT: FRAMERRINT Position */
#define LPC_USART0_INTSTAT_FRAMERRINT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_FRAMERRINT_SHIFT))&LPC_USART0_INTSTAT_FRAMERRINT_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_PARITYERRINT_MASK     (0x4000U)                                           /*!< LPC_USART0_INTSTAT: PARITYERRINT Mask   */
#define LPC_USART0_INTSTAT_PARITYERRINT_SHIFT    (14U)                                               /*!< LPC_USART0_INTSTAT: PARITYERRINT Position*/
#define LPC_USART0_INTSTAT_PARITYERRINT(x)       (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_PARITYERRINT_SHIFT))&LPC_USART0_INTSTAT_PARITYERRINT_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_RXNOISEINT_MASK       (0x8000U)                                           /*!< LPC_USART0_INTSTAT: RXNOISEINT Mask     */
#define LPC_USART0_INTSTAT_RXNOISEINT_SHIFT      (15U)                                               /*!< LPC_USART0_INTSTAT: RXNOISEINT Position */
#define LPC_USART0_INTSTAT_RXNOISEINT(x)         (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_RXNOISEINT_SHIFT))&LPC_USART0_INTSTAT_RXNOISEINT_MASK) /*!< LPC_USART0_INTSTAT                      */
#define LPC_USART0_INTSTAT_ABERR_MASK            (0x10000U)                                          /*!< LPC_USART0_INTSTAT: ABERR Mask          */
#define LPC_USART0_INTSTAT_ABERR_SHIFT           (16U)                                               /*!< LPC_USART0_INTSTAT: ABERR Position      */
#define LPC_USART0_INTSTAT_ABERR(x)              (((uint32_t)(((uint32_t)(x))<<LPC_USART0_INTSTAT_ABERR_SHIFT))&LPC_USART0_INTSTAT_ABERR_MASK) /*!< LPC_USART0_INTSTAT                      */
/* ------- OSR Bit Fields                           ------ */
#define LPC_USART0_OSR_OSRVAL_MASK               (0xFU)                                              /*!< LPC_USART0_OSR: OSRVAL Mask             */
#define LPC_USART0_OSR_OSRVAL_SHIFT              (0U)                                                /*!< LPC_USART0_OSR: OSRVAL Position         */
#define LPC_USART0_OSR_OSRVAL(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_USART0_OSR_OSRVAL_SHIFT))&LPC_USART0_OSR_OSRVAL_MASK) /*!< LPC_USART0_OSR                          */
/* ------- ADDR Bit Fields                          ------ */
#define LPC_USART0_ADDR_ADDRESS_MASK             (0xFFU)                                             /*!< LPC_USART0_ADDR: ADDRESS Mask           */
#define LPC_USART0_ADDR_ADDRESS_SHIFT            (0U)                                                /*!< LPC_USART0_ADDR: ADDRESS Position       */
#define LPC_USART0_ADDR_ADDRESS(x)               (((uint32_t)(((uint32_t)(x))<<LPC_USART0_ADDR_ADDRESS_SHIFT))&LPC_USART0_ADDR_ADDRESS_MASK) /*!< LPC_USART0_ADDR                         */
/**
 * @} */ /* End group USART_Register_Masks_GROUP 
 */

/* LPC_USART0 - Peripheral instance base addresses */
#define LPC_USART0_BasePtr             0x40064000UL //!< Peripheral base address
#define LPC_USART0                     ((LPC_USART0_Type *) LPC_USART0_BasePtr) //!< Freescale base pointer
#define LPC_USART0_BASE_PTR            (LPC_USART0) //!< Freescale style base pointer
/**
 * @} */ /* End group USART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USART_Peripheral_access_layer_GROUP USART Peripheral Access Layer
* @brief C Struct for USART
* @{
*/

/* ================================================================================ */
/* ================           LPC_USART1 (derived from USART0)       ================ */
/* ================================================================================ */

/**
 * @brief USART0
 */

/* LPC_USART1 - Peripheral instance base addresses */
#define LPC_USART1_BasePtr             0x40068000UL //!< Peripheral base address
#define LPC_USART1                     ((LPC_USART0_Type *) LPC_USART1_BasePtr) //!< Freescale base pointer
#define LPC_USART1_BASE_PTR            (LPC_USART1) //!< Freescale style base pointer
/**
 * @} */ /* End group USART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USART_Peripheral_access_layer_GROUP USART Peripheral Access Layer
* @brief C Struct for USART
* @{
*/

/* ================================================================================ */
/* ================           LPC_USART2 (derived from USART0)       ================ */
/* ================================================================================ */

/**
 * @brief USART0
 */

/* LPC_USART2 - Peripheral instance base addresses */
#define LPC_USART2_BasePtr             0x4006C000UL //!< Peripheral base address
#define LPC_USART2                     ((LPC_USART0_Type *) LPC_USART2_BasePtr) //!< Freescale base pointer
#define LPC_USART2_BASE_PTR            (LPC_USART2) //!< Freescale style base pointer
/**
 * @} */ /* End group USART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WKT_Peripheral_access_layer_GROUP WKT Peripheral Access Layer
* @brief C Struct for WKT
* @{
*/

/* ================================================================================ */
/* ================           LPC_WKT (file:WKT_LPC82x)            ================ */
/* ================================================================================ */

/**
 * @brief Self wake-up timer
 */
/**
* @addtogroup WKT_structs_GROUP WKT struct
* @brief Struct for WKT
* @{
*/
typedef struct {                                /*       LPC_WKT Structure                                            */
   __IO uint32_t  CTRL;                         /**< 0000: Self wake-up timer control register                          */
        uint8_t   RESERVED_0[8];               
   __IO uint32_t  COUNT;                        /**< 000C: Counter register                                             */
} LPC_WKT_Type;

/**
 * @} */ /* End group WKT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPC_WKT' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup WKT_Register_Masks_GROUP WKT Register Masks
* @brief Register Masks for WKT
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define LPC_WKT_CTRL_CLKSEL_MASK                 (0x1U)                                              /*!< LPC_WKT_CTRL: CLKSEL Mask               */
#define LPC_WKT_CTRL_CLKSEL_SHIFT                (0U)                                                /*!< LPC_WKT_CTRL: CLKSEL Position           */
#define LPC_WKT_CTRL_CLKSEL(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_WKT_CTRL_CLKSEL_SHIFT))&LPC_WKT_CTRL_CLKSEL_MASK) /*!< LPC_WKT_CTRL                            */
#define LPC_WKT_CTRL_ALARMFLAG_MASK              (0x2U)                                              /*!< LPC_WKT_CTRL: ALARMFLAG Mask            */
#define LPC_WKT_CTRL_ALARMFLAG_SHIFT             (1U)                                                /*!< LPC_WKT_CTRL: ALARMFLAG Position        */
#define LPC_WKT_CTRL_ALARMFLAG(x)                (((uint32_t)(((uint32_t)(x))<<LPC_WKT_CTRL_ALARMFLAG_SHIFT))&LPC_WKT_CTRL_ALARMFLAG_MASK) /*!< LPC_WKT_CTRL                            */
#define LPC_WKT_CTRL_CLEARCTR_MASK               (0x4U)                                              /*!< LPC_WKT_CTRL: CLEARCTR Mask             */
#define LPC_WKT_CTRL_CLEARCTR_SHIFT              (2U)                                                /*!< LPC_WKT_CTRL: CLEARCTR Position         */
#define LPC_WKT_CTRL_CLEARCTR(x)                 (((uint32_t)(((uint32_t)(x))<<LPC_WKT_CTRL_CLEARCTR_SHIFT))&LPC_WKT_CTRL_CLEARCTR_MASK) /*!< LPC_WKT_CTRL                            */
/* ------- COUNT Bit Fields                         ------ */
#define LPC_WKT_COUNT_VALUE_MASK                 (0xFFFFFFFFU)                                       /*!< LPC_WKT_COUNT: VALUE Mask               */
#define LPC_WKT_COUNT_VALUE_SHIFT                (0U)                                                /*!< LPC_WKT_COUNT: VALUE Position           */
#define LPC_WKT_COUNT_VALUE(x)                   (((uint32_t)(((uint32_t)(x))<<LPC_WKT_COUNT_VALUE_SHIFT))&LPC_WKT_COUNT_VALUE_MASK) /*!< LPC_WKT_COUNT                           */
/**
 * @} */ /* End group WKT_Register_Masks_GROUP 
 */

/* LPC_WKT - Peripheral instance base addresses */
#define LPC_WKT_BasePtr                0x40008000UL //!< Peripheral base address
#define LPC_WKT                        ((LPC_WKT_Type *) LPC_WKT_BasePtr) //!< Freescale base pointer
#define LPC_WKT_BASE_PTR               (LPC_WKT) //!< Freescale style base pointer
/**
 * @} */ /* End group WKT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WWDT_Peripheral_access_layer_GROUP WWDT Peripheral Access Layer
* @brief C Struct for WWDT
* @{
*/

/* ================================================================================ */
/* ================           LPC_WWDT (file:WWDT_LPC82x)          ================ */
/* ================================================================================ */

/**
 * @brief Windowed Watchdog Timer
 */
/**
* @addtogroup WWDT_structs_GROUP WWDT struct
* @brief Struct for WWDT
* @{
*/
typedef struct {                                /*       LPC_WWDT Structure                                           */
   __IO uint32_t  MOD;                          /**< 0000: Watchdog mode register. This register contains the basic mode and status of the Watchdog Timer */
   __IO uint32_t  TC;                           /**< 0004: Watchdog timer constant register. This 24-bit register determines the time-out value */
   __O  uint32_t  FEED;                         /**< 0008: Watchdog feed sequence register. Writing 0xAA followed by 0x55 to this register reloads the Watchdog timer with the value contained in WDTC */
   __I  uint32_t  TV;                           /**< 000C: Watchdog timer value register. This 24-bit register reads out the current value of the Watchdog timer */
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
#define LPC_WWDT_MOD_WDEN_MASK                   (0x1U)                                              /*!< LPC_WWDT_MOD: WDEN Mask                 */
#define LPC_WWDT_MOD_WDEN_SHIFT                  (0U)                                                /*!< LPC_WWDT_MOD: WDEN Position             */
#define LPC_WWDT_MOD_WDEN(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDEN_SHIFT))&LPC_WWDT_MOD_WDEN_MASK) /*!< LPC_WWDT_MOD                            */
#define LPC_WWDT_MOD_WDRESET_MASK                (0x2U)                                              /*!< LPC_WWDT_MOD: WDRESET Mask              */
#define LPC_WWDT_MOD_WDRESET_SHIFT               (1U)                                                /*!< LPC_WWDT_MOD: WDRESET Position          */
#define LPC_WWDT_MOD_WDRESET(x)                  (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDRESET_SHIFT))&LPC_WWDT_MOD_WDRESET_MASK) /*!< LPC_WWDT_MOD                            */
#define LPC_WWDT_MOD_WDTOF_MASK                  (0x4U)                                              /*!< LPC_WWDT_MOD: WDTOF Mask                */
#define LPC_WWDT_MOD_WDTOF_SHIFT                 (2U)                                                /*!< LPC_WWDT_MOD: WDTOF Position            */
#define LPC_WWDT_MOD_WDTOF(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDTOF_SHIFT))&LPC_WWDT_MOD_WDTOF_MASK) /*!< LPC_WWDT_MOD                            */
#define LPC_WWDT_MOD_WDINT_MASK                  (0x8U)                                              /*!< LPC_WWDT_MOD: WDINT Mask                */
#define LPC_WWDT_MOD_WDINT_SHIFT                 (3U)                                                /*!< LPC_WWDT_MOD: WDINT Position            */
#define LPC_WWDT_MOD_WDINT(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDINT_SHIFT))&LPC_WWDT_MOD_WDINT_MASK) /*!< LPC_WWDT_MOD                            */
#define LPC_WWDT_MOD_WDPROTECT_MASK              (0x10U)                                             /*!< LPC_WWDT_MOD: WDPROTECT Mask            */
#define LPC_WWDT_MOD_WDPROTECT_SHIFT             (4U)                                                /*!< LPC_WWDT_MOD: WDPROTECT Position        */
#define LPC_WWDT_MOD_WDPROTECT(x)                (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_WDPROTECT_SHIFT))&LPC_WWDT_MOD_WDPROTECT_MASK) /*!< LPC_WWDT_MOD                            */
#define LPC_WWDT_MOD_LOCK_MASK                   (0x20U)                                             /*!< LPC_WWDT_MOD: LOCK Mask                 */
#define LPC_WWDT_MOD_LOCK_SHIFT                  (5U)                                                /*!< LPC_WWDT_MOD: LOCK Position             */
#define LPC_WWDT_MOD_LOCK(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_MOD_LOCK_SHIFT))&LPC_WWDT_MOD_LOCK_MASK) /*!< LPC_WWDT_MOD                            */
/* ------- TC Bit Fields                            ------ */
#define LPC_WWDT_TC_COUNT_MASK                   (0xFFFFFFU)                                         /*!< LPC_WWDT_TC: COUNT Mask                 */
#define LPC_WWDT_TC_COUNT_SHIFT                  (0U)                                                /*!< LPC_WWDT_TC: COUNT Position             */
#define LPC_WWDT_TC_COUNT(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_TC_COUNT_SHIFT))&LPC_WWDT_TC_COUNT_MASK) /*!< LPC_WWDT_TC                             */
/* ------- FEED Bit Fields                          ------ */
#define LPC_WWDT_FEED_FEED_MASK                  (0xFFU)                                             /*!< LPC_WWDT_FEED: FEED Mask                */
#define LPC_WWDT_FEED_FEED_SHIFT                 (0U)                                                /*!< LPC_WWDT_FEED: FEED Position            */
#define LPC_WWDT_FEED_FEED(x)                    (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_FEED_FEED_SHIFT))&LPC_WWDT_FEED_FEED_MASK) /*!< LPC_WWDT_FEED                           */
/* ------- TV Bit Fields                            ------ */
#define LPC_WWDT_TV_COUNT_MASK                   (0xFFFFFFU)                                         /*!< LPC_WWDT_TV: COUNT Mask                 */
#define LPC_WWDT_TV_COUNT_SHIFT                  (0U)                                                /*!< LPC_WWDT_TV: COUNT Position             */
#define LPC_WWDT_TV_COUNT(x)                     (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_TV_COUNT_SHIFT))&LPC_WWDT_TV_COUNT_MASK) /*!< LPC_WWDT_TV                             */
/* ------- WARNINT Bit Fields                       ------ */
#define LPC_WWDT_WARNINT_WARNINT_MASK            (0x3FFU)                                            /*!< LPC_WWDT_WARNINT: WARNINT Mask          */
#define LPC_WWDT_WARNINT_WARNINT_SHIFT           (0U)                                                /*!< LPC_WWDT_WARNINT: WARNINT Position      */
#define LPC_WWDT_WARNINT_WARNINT(x)              (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_WARNINT_WARNINT_SHIFT))&LPC_WWDT_WARNINT_WARNINT_MASK) /*!< LPC_WWDT_WARNINT                        */
/* ------- WINDOW Bit Fields                        ------ */
#define LPC_WWDT_WINDOW_WINDOW_MASK              (0xFFFFFFU)                                         /*!< LPC_WWDT_WINDOW: WINDOW Mask            */
#define LPC_WWDT_WINDOW_WINDOW_SHIFT             (0U)                                                /*!< LPC_WWDT_WINDOW: WINDOW Position        */
#define LPC_WWDT_WINDOW_WINDOW(x)                (((uint32_t)(((uint32_t)(x))<<LPC_WWDT_WINDOW_WINDOW_SHIFT))&LPC_WWDT_WINDOW_WINDOW_MASK) /*!< LPC_WWDT_WINDOW                         */
/**
 * @} */ /* End group WWDT_Register_Masks_GROUP 
 */

/* LPC_WWDT - Peripheral instance base addresses */
#define LPC_WWDT_BasePtr               0x40000000UL //!< Peripheral base address
#define LPC_WWDT                       ((LPC_WWDT_Type *) LPC_WWDT_BasePtr) //!< Freescale base pointer
#define LPC_WWDT_BASE_PTR              (LPC_WWDT) //!< Freescale style base pointer
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


#endif  /* MCU_LPC82X */

